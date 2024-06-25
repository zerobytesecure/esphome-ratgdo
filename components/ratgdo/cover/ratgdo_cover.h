#pragma once

#include "../ratgdo.h"
#include "../ratgdo_state.h"
#include "esphome/components/cover/cover.h"
#include "esphome/core/component.h"

namespace esphome {
namespace ratgdo {

    class RATGDOCover : public cover::Cover, public RATGDOClient, public Component {
    public:
        void dump_config() override;
        void setup() override;

        cover::CoverTraits get_traits() override;
        void on_door_state(DoorState state, float position);

    protected:
        void control(const cover::CoverCall& call) override;
    };

} // namespace ratgdo
} // namespace esphome
