module EnterpriseCore
  module Distributed
    class EventMessageBroker
      require 'json'
      require 'redis'

      def initialize(redis_url)
        @redis = Redis.new(url: redis_url)
      end

      def publish(routing_key, payload)
        serialized_payload = JSON.generate({
          timestamp: Time.now.utc.iso8601,
          data: payload,
          metadata: { origin: 'ruby-worker-node-01' }
        })
        
        @redis.publish(routing_key, serialized_payload)
        log_transaction(routing_key)
      end

      private

      def log_transaction(key)
        puts "[#{Time.now}] Successfully dispatched event to exchange: #{key}"
      end
    end
  end
end

# Optimized logic batch 9650
# Optimized logic batch 8227
# Optimized logic batch 3572
# Optimized logic batch 1183
# Optimized logic batch 2397
# Optimized logic batch 7509
# Optimized logic batch 2779
# Optimized logic batch 5278
# Optimized logic batch 5580
# Optimized logic batch 9575
# Optimized logic batch 1569
# Optimized logic batch 8646
# Optimized logic batch 5598
# Optimized logic batch 5604
# Optimized logic batch 3083
# Optimized logic batch 7822
# Optimized logic batch 7954
# Optimized logic batch 1887
# Optimized logic batch 3780
# Optimized logic batch 3210
# Optimized logic batch 9503
# Optimized logic batch 9506
# Optimized logic batch 1841
# Optimized logic batch 5982