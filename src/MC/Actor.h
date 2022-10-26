#pragma once
//
// Created by Admin on 2022/10/25.
//

#ifndef GGXX_ACTOR_H
#define GGXX_ACTOR_H

#include "Global.h"

class Actor {
public:
    enum InitializationMethod : unsigned char {
            INVALID = 0x0,
            LOADED = 0x1,
            SPAWNED = 0x2,
            BORN = 0x3,
            TRANSFORMED = 0x4,
            UPDATED = 0x5,
            EVENT = 0x6,
            LEGACY = 0x7,
    };

    /*0*/ virtual bool hasComponent(class HashedString const &) const;
    /*1*/ virtual class Mob * getLastHurtByMob();
    /*2*/ virtual void setLastHurtByMob(class Mob *);
    /*3*/ virtual class Player * getLastHurtByPlayer();
    /*4*/ virtual void setLastHurtByPlayer(class Player *);
    /*5*/ virtual class Mob * getLastHurtMob();
    /*6*/ virtual void setLastHurtMob(class Actor *);
    /*7*/ virtual void outOfWorld();
    /*8*/ virtual void reloadHardcoded(enum Actor::InitializationMethod, class VariantParameterList const &);
    /*9*/ virtual void reloadHardcodedClient(enum Actor::InitializationMethod, class VariantParameterList const &);
    /*10*/ virtual void initializeComponents(enum Actor::InitializationMethod, class VariantParameterList const &);
    /*11*/ virtual void reloadComponents(enum Actor::InitializationMethod, class VariantParameterList const &);
    /*12*/ virtual void _serverInitItemStackIds();
    /*13*/ virtual void _doInitialMove();
    /*14*/ virtual ~Actor();
    /*15*/ virtual void resetUserPos(bool);
    /*16*/ virtual enum ActorType getOwnerEntityType();
    /*17*/ virtual void remove();
    /*18*/ virtual void setPos(class Vec3 const &);
    /*19*/ virtual bool isRuntimePredictedMovementEnabled() const;
    /*20*/ virtual struct PredictedMovementValues const & getPredictedMovementValues() const;
    /*21*/ virtual class Vec3 const & getPosition() const;
    /*22*/ virtual class Vec3 const & getPosPrev() const;
    /*23*/ virtual class Vec3 const getPosExtrapolated(float) const;
    /*24*/ virtual class Vec3 getAttachPos(enum ActorLocation, float) const;
    /*25*/ virtual class Vec3 getFiringPos() const;
    /*26*/ virtual void setRot(class Vec2 const &);
    /*27*/ virtual void move(class Vec3 const &);
    /*28*/ virtual void move(struct IActorMovementProxy &, class Vec3 const &) const;
    /*29*/ virtual class Vec3 getInterpolatedRidingPosition(float) const;
    /*30*/ virtual float getInterpolatedBodyRot(float) const;
    /*31*/ virtual float getInterpolatedHeadRot(float) const;
    /*32*/ virtual float getInterpolatedBodyYaw(float) const;
    /*33*/ virtual float getYawSpeedInDegreesPerSecond() const;
    /*34*/ virtual float getInterpolatedWalkAnimSpeed(float) const;
    /*35*/ virtual class Vec3 getInterpolatedRidingOffset(float) const;
    /*36*/ virtual void resetInterpolated();
    /*37*/ virtual void updateEntityInside(class AABB const &);
    /*38*/ virtual void updateEntityInside();
    /*39*/ virtual bool isFireImmune() const;
    /*40*/ virtual void __unk_vfn_40();
    /*41*/ virtual void blockedByShield(class ActorDamageSource const &, class Actor &);
    /*42*/ virtual bool canDisableShield();
    /*43*/ virtual void teleportTo(class Vec3 const &, bool, int, int, bool);
    /*44*/ virtual bool tryTeleportTo(class Vec3 const &, bool, bool, int, int);
    /*45*/ virtual void chorusFruitTeleport(class Vec3 const &);
    /*46*/ virtual void lerpMotion(class Vec3 const &);
    /*47*/ virtual std::unique_ptr<class AddActorBasePacket> tryCreateAddActorPacket();
    /*48*/ virtual void normalTick();
    /*49*/ virtual void baseTick();
    /*50*/ virtual void passengerTick();
    /*51*/ virtual void positionPassenger(class Actor &, float);
    /*52*/ virtual bool startRiding(class Actor &);
    /*53*/ virtual void addPassenger(class Actor &);
    /*54*/ virtual void flagPassengerToRemove(class Actor &);
    /*55*/ virtual std::string getExitTip(std::string const &, enum InputMode) const;
    /*56*/ virtual bool intersects(class Vec3 const &, class Vec3 const &) const;
    /*57*/ virtual bool isInWall() const;
    /*58*/ virtual bool isInvisible() const;
    /*59*/ virtual bool canShowNameTag() const;
    /*60*/ virtual void __unk_vfn_60();
    /*61*/ virtual void setNameTagVisible(bool);
    /*62*/ virtual std::string const & getNameTag() const;
    /*63*/ virtual unsigned __int64 getNameTagAsHash() const;
    /*64*/ virtual std::string getFormattedNameTag() const;
    /*65*/ virtual void filterFormattedNameTag(class UIProfanityContext const &);
    /*66*/ virtual void setNameTag(std::string const &);
    /*67*/ virtual void __unk_vfn_67();
    /*68*/ virtual void setScoreTag(std::string const &);
    /*69*/ virtual std::string const & getScoreTag() const;
    /*70*/ virtual bool isInWater() const;
    /*71*/ virtual bool hasEnteredWater() const;
    /*72*/ virtual bool isInLava() const;
    /*73*/ virtual bool isUnderLiquid(enum MaterialType) const;
    /*74*/ virtual bool isOverWater() const;
    /*75*/ virtual void setBlockMovementSlowdownMultiplier(class BlockLegacy const &, class Vec3 const &);
    /*76*/ virtual void resetBlockMovementSlowdownMultiplier();
    /*77*/ virtual float getCameraOffset() const;
    /*78*/ virtual float getShadowHeightOffs();
    /*79*/ virtual float getShadowRadius() const;
    /*80*/ virtual class Vec3 getHeadLookVector(float) const;
    /*81*/ virtual void __unk_vfn_81();
    /*82*/ virtual bool canSee(class Actor const &) const;
    /*83*/ virtual bool canSee(class Vec3 const &) const;
    /*84*/ virtual void __unk_vfn_84();
    /*85*/ virtual bool isSkyLit(float);
    /*86*/ virtual float getBrightness(float) const;
    /*87*/ virtual void __unk_vfn_87();
    /*88*/ virtual void playerTouch(class Player &);
    /*89*/ virtual void onAboveBubbleColumn(bool);
    /*90*/ virtual void onInsideBubbleColumn(bool);
    /*91*/ virtual bool isImmobile() const;
    /*92*/ virtual bool isSilent() const;
    /*93*/ virtual bool isSilentObserver() const;
    /*94*/ virtual bool isPickable();
    /*95*/ virtual void __unk_vfn_95();
    /*96*/ virtual bool isSleeping() const;
    /*97*/ virtual void setSleeping(bool);
    /*98*/ virtual void __unk_vfn_98();
    /*99*/ virtual void setSneaking(bool);
    /*100*/ virtual bool isBlocking() const;
    /*101*/ virtual bool isDamageBlocked(class ActorDamageSource const &) const;
    /*102*/ virtual bool isAlive() const;
    /*103*/ virtual bool isOnFire() const;
    /*104*/ virtual bool isOnHotBlock() const;
    /*105*/ virtual void __unk_vfn_105();
    /*106*/ virtual bool isSurfaceMob() const;
    /*107*/ virtual void __unk_vfn_107();
    /*108*/ virtual void __unk_vfn_108();
    /*109*/ virtual bool isRemotePlayer() const;
    /*110*/ virtual void __unk_vfn_110();
    /*111*/ virtual bool isAffectedByWaterBottle() const;
    /*112*/ virtual bool canAttack(class Actor *, bool) const;
    /*113*/ virtual void setTarget(class Actor *);
    /*114*/ virtual bool isValidTarget(class Actor *) const;
    /*115*/ virtual bool attack(class Actor &, enum ActorDamageCause const &);
    /*116*/ virtual void performRangedAttack(class Actor &, float);
    /*117*/ virtual int getEquipmentCount() const;
    /*118*/ virtual void setOwner(struct ActorUniqueID);
    /*119*/ virtual void setSitting(bool);
    /*120*/ virtual void onTame();
    /*121*/ virtual void onFailedTame();
    /*122*/ virtual int getInventorySize() const;
    /*123*/ virtual int getEquipSlots() const;
    /*124*/ virtual int getChestSlots() const;
    /*125*/ virtual void setStanding(bool);
    /*126*/ virtual bool canPowerJump() const;
    /*127*/ virtual void setCanPowerJump(bool);
    /*128*/ virtual bool isJumping() const;
    /*129*/ virtual bool isEnchanted() const;
    /*130*/ virtual void vehicleLanded(class Vec3 const &, class Vec3 const &);
    /*131*/ virtual bool shouldRender() const;
    /*132*/ virtual void playAmbientSound();
    /*133*/ virtual enum LevelSoundEvent getAmbientSound() const;
    /*134*/ virtual bool isInvulnerableTo(class ActorDamageSource const &) const;
    /*135*/ virtual enum ActorDamageCause getBlockDamageCause(class Block const &) const;
    /*136*/ virtual void animateHurt();
    /*137*/ virtual bool doFireHurt(int);
    /*138*/ virtual void onLightningHit();
    /*139*/ virtual void onBounceStarted(class BlockPos const &, class Block const &);
    /*140*/ virtual void feed(int);
    /*141*/ virtual void handleEntityEvent(enum ActorEvent, int);
    /*142*/ virtual float getPickRadius();
    /*143*/ virtual class HashedString const & getActorRendererId() const;
    /*144*/ virtual class ItemActor * spawnAtLocation(int, int);
    /*145*/ virtual class ItemActor * spawnAtLocation(int, int, float);
    /*146*/ virtual class ItemActor * spawnAtLocation(class Block const &, int);
    /*147*/ virtual class ItemActor * spawnAtLocation(class Block const &, int, float);
    /*148*/ virtual class ItemActor * spawnAtLocation(class ItemStack const &, float);
    /*149*/ virtual void despawn();
    /*150*/ virtual void killed(class Actor &);
    /*151*/ virtual void awardKillScore(class Actor &, int);
    /*152*/ virtual void setArmor(enum ArmorSlot, class ItemStack const &);
    /*153*/ virtual class ItemStack const & getArmor(enum ArmorSlot) const;
    /*154*/ virtual std::vector<class ItemStack const *> getAllArmor() const;
    /*155*/ virtual enum ArmorMaterialType getArmorMaterialTypeInSlot(enum ArmorSlot) const;
    /*156*/ virtual enum ArmorTextureType getArmorMaterialTextureTypeInSlot(enum ArmorSlot) const;
    /*157*/ virtual float getArmorColorInSlot(enum ArmorSlot, int) const;
    /*158*/ virtual class ItemStack const & getEquippedSlot(enum EquipmentSlot) const;
    /*159*/ virtual void setEquippedSlot(enum EquipmentSlot, class ItemStack const &);
    /*160*/ virtual void setCarriedItem(class ItemStack const &);
    /*161*/ virtual class ItemStack const & getCarriedItem() const;
    /*162*/ virtual void setOffhandSlot(class ItemStack const &);
    /*163*/ virtual class ItemStack const & getEquippedTotem() const;
    /*164*/ virtual bool consumeTotem();
    /*165*/ virtual bool save(class CompoundTag &) const;
    /*166*/ virtual void saveWithoutId(class CompoundTag &) const;
    /*167*/ virtual bool load(class CompoundTag const &, class DataLoadHelper &);
    /*168*/ virtual void loadLinks(class CompoundTag const &, std::vector<struct ActorLink> &, class DataLoadHelper &);
    /*169*/ virtual enum ActorType getEntityTypeId() const;
    /*170*/ virtual class HashedString const & queryEntityRenderer() const;
    /*171*/ virtual struct ActorUniqueID getSourceUniqueID() const;
    /*172*/ virtual void thawFreezeEffect();
    /*173*/ virtual bool canFreeze() const;
    /*174*/ virtual bool const isWearingLeatherArmor() const;
    /*175*/ virtual class AABB getLiquidAABB(enum MaterialType) const;
    /*176*/ virtual void handleInsidePortal(class BlockPos const &);
    /*177*/ virtual int getPortalCooldown() const;
    /*178*/ virtual int getPortalWaitTime() const;
    /*179*/ virtual class AutomaticID<class Dimension, int> getDimensionId() const;
    /*180*/ virtual bool canChangeDimensionsUsingPortal() const;
    /*181*/ virtual void __unk_vfn_181();
    /*182*/ virtual void changeDimension(class AutomaticID<class Dimension, int>);
    /*183*/ virtual struct ActorUniqueID getControllingPlayer() const;
    /*184*/ virtual void checkFallDamage(float, bool);
    /*185*/ virtual void causeFallDamage(float, float, class ActorDamageSource);
    /*186*/ virtual void handleFallDistanceOnServer(float, float, bool);
    /*187*/ virtual void playSynchronizedSound(enum LevelSoundEvent, class Vec3 const &, class Block const &, bool);
    /*188*/ virtual void playSynchronizedSound(enum LevelSoundEvent, class Vec3 const &, int, bool);
    /*189*/ virtual void onSynchedFlagUpdate(int, __int64, __int64);
    /*190*/ virtual void onSynchedDataUpdate(int);
    /*191*/ virtual bool canAddPassenger(class Actor &) const;
    /*192*/ virtual bool canPickupItem(class ItemStack const &) const;
    /*193*/ virtual bool canBePulledIntoVehicle() const;
    /*194*/ virtual bool inCaravan() const;
    /*195*/ virtual void __unk_vfn_195();
    /*196*/ virtual void tickLeash();
    /*197*/ virtual void sendMotionPacketIfNeeded();
    /*198*/ virtual bool canSynchronizeNewEntity() const;
    /*199*/ virtual void stopRiding(bool, bool, bool);
    /*200*/ virtual void startSwimming();
    /*201*/ virtual void stopSwimming();
    /*202*/ virtual void buildDebugInfo(std::string &) const;
    /*203*/ virtual enum CommandPermissionLevel getCommandPermissionLevel() const;
    /*204*/ virtual bool isClientSide() const;
    /*205*/ virtual class AttributeInstance * getMutableAttribute(class Attribute const &);
    /*206*/ virtual class AttributeInstance const & getAttribute(class Attribute const &) const;
    /*207*/ virtual int getDeathTime() const;
    /*208*/ virtual void heal(int);
    /*209*/ virtual bool isInvertedHealAndHarm() const;
    /*210*/ virtual bool canBeAffected(int) const;
    /*211*/ virtual bool canBeAffected(class MobEffectInstance const &) const;
    /*212*/ virtual bool canBeAffectedByArrow(class MobEffectInstance const &) const;
    /*213*/ virtual void onEffectAdded(class MobEffectInstance &);
    /*214*/ virtual void onEffectUpdated(class MobEffectInstance &);
    /*215*/ virtual void onEffectRemoved(class MobEffectInstance &);
    /*216*/ virtual bool canObstructSpawningAndBlockPlacement() const;
    /*217*/ virtual class AnimationComponent & getAnimationComponent();
    /*218*/ virtual void openContainerComponent(class Player &);
    /*219*/ virtual void swing();
    /*220*/ virtual void useItem(class ItemStackBase &, enum ItemUseMethod, bool);
    /*221*/ virtual void __unk_vfn_221();
    /*222*/ virtual void __unk_vfn_222();
    /*223*/ virtual void getDebugText(std::vector<std::string> &);
    /*224*/ virtual float getMapDecorationRotation() const;
    /*225*/ virtual float getPassengerYRotation(class Actor const &) const;
    /*226*/ virtual float getYHeadRot() const;
    /*227*/ virtual void setYHeadRot(float);
    /*228*/ virtual float getYHeadRotO() const;
    /*229*/ virtual void setYHeadRotO(float);
    /*230*/ virtual bool isWorldBuilder() const;
    /*231*/ virtual bool isCreative() const;
    /*232*/ virtual bool isAdventure() const;
    /*233*/ virtual bool isSurvival() const;
    /*234*/ virtual bool isSpectator() const;
    /*235*/ virtual bool isAttackableGamemode() const;
    /*236*/ virtual bool add(class ItemStack &);
    /*237*/ virtual bool drop(class ItemStack const &, bool);
    /*238*/ virtual bool getInteraction(class Player &, class ActorInteraction &, class Vec3 const &);
    /*239*/ virtual bool canDestroyBlock(class Block const &) const;
    /*240*/ virtual void setAuxValue(int);
    /*241*/ virtual void setSize(float, float);
    /*242*/ virtual void onOrphan();
    /*243*/ virtual void wobble();
    /*244*/ virtual bool wasHurt();
    /*245*/ virtual void startSpinAttack();
    /*246*/ virtual void stopSpinAttack();
    /*247*/ virtual void setDamageNearbyMobs(bool);
    /*248*/ virtual void __unk_vfn_248();
    /*249*/ virtual void reloadLootTable();
    /*250*/ virtual void reloadLootTable(struct EquipmentTableDefinition const &);
    /*251*/ virtual void __unk_vfn_251();
    /*252*/ virtual void kill();
    /*253*/ virtual void die(class ActorDamageSource const &);
    /*254*/ virtual bool shouldDropDeathLoot() const;
    /*255*/ virtual bool shouldTick() const;
    /*256*/ virtual void extractSnapshot(struct PlayerSnapshotComponent &) const;
    /*257*/ virtual void applySnapshot(struct PlayerSnapshotComponent const &, struct PlayerSnapshotComponent const &);
    /*258*/ virtual float getNextStep(float);
    /*259*/ virtual class LootTable * getLootTable();
    /*260*/ virtual void interpolatorTick();
    /*261*/ virtual void onPush(class Actor &);
    /*262*/ virtual class std::optional<class BlockPos> getLastDeathPos() const;
    /*263*/ virtual class std::optional<class AutomaticID<class Dimension, int>> getLastDeathDimension() const;
    /*264*/ virtual bool hasDiedBefore() const;
    /*265*/ virtual void doWaterSplashEffect();
    /*266*/ virtual bool _shouldProvideFeedbackOnHandContainerItemSet(enum HandSlot, class ItemStack const &) const;
    /*267*/ virtual bool _shouldProvideFeedbackOnArmorSet(enum ArmorSlot, class ItemStack const &) const;
    /*268*/ virtual void updateEntitySpecificMolangVariables(class RenderParams &);
    /*269*/ virtual bool shouldTryMakeStepSound();
    /*270*/ virtual void __unk_vfn_270();
    /*271*/ virtual bool _hurt(class ActorDamageSource const &, float, bool, bool);
    /*272*/ virtual void markHurt();
    /*273*/ virtual class AnimationComponent & _getAnimationComponent(class std::shared_ptr<class AnimationComponent> &, enum AnimationComponentGroupType);
    /*274*/ virtual void readAdditionalSaveData(class CompoundTag const &, class DataLoadHelper &);
    /*275*/ virtual void addAdditionalSaveData(class CompoundTag &) const;
    /*276*/ virtual void _playStepSound(class BlockPos const &, class Block const &);
    /*277*/ virtual void _playFlySound(class BlockPos const &, class Block const &);
    /*278*/ virtual void __unk_vfn_278();
    /*279*/ virtual void checkInsideBlocks(float);
    /*280*/ virtual void pushOutOfBlocks(class Vec3 const &);
    /*281*/ virtual void spawnTrailBubbles();
    /*282*/ virtual void updateInsideBlock();
    /*283*/ virtual void _removePassenger(struct ActorUniqueID const &, bool, bool, bool);
    /*284*/ virtual void _onSizeUpdated();
};


#endif //GGXX_ACTOR_H
