#pragma once

#include "Global.h"
#include "Mob.h"

class Player : public Mob {

public:
    /*8*/ virtual void reloadHardcoded(enum Actor::InitializationMethod, class VariantParameterList const &);
    /*10*/ virtual void initializeComponents(enum Actor::InitializationMethod, class VariantParameterList const &);
    /*12*/ virtual void _serverInitItemStackIds();
    /*14*/ virtual ~Player();
    /*15*/ virtual void resetUserPos(bool);
    /*17*/ virtual void remove();
    /*24*/ virtual class Vec3 getAttachPos(enum ActorLocation, float) const;
    /*27*/ virtual void move(class Vec3 const &);
    /*28*/ virtual void move(struct IActorMovementProxy &, class Vec3 const &) const;
    /*35*/ virtual class Vec3 getInterpolatedRidingOffset(float) const;
    /*39*/ virtual bool isFireImmune() const;
    /*40*/ virtual void __unk_vfn_40();
    /*43*/ virtual void teleportTo(class Vec3 const &, bool, int, int, bool);
    /*47*/ virtual std::unique_ptr<class AddActorBasePacket> tryCreateAddActorPacket();
    /*48*/ virtual void normalTick();
    /*50*/ virtual void passengerTick();
    /*60*/ virtual void __unk_vfn_60();
    /*64*/ virtual std::string getFormattedNameTag() const;
    /*67*/ virtual void __unk_vfn_67();
    /*75*/ virtual void setBlockMovementSlowdownMultiplier(class BlockLegacy const &, class Vec3 const &);
    /*77*/ virtual float getCameraOffset() const;
    /*79*/ virtual float getShadowRadius() const;
    /*81*/ virtual void __unk_vfn_81();
    /*84*/ virtual void __unk_vfn_84();
    /*87*/ virtual void __unk_vfn_87();
    /*91*/ virtual bool isImmobile() const;
    /*93*/ virtual bool isSilentObserver() const;
    /*95*/ virtual void __unk_vfn_95();
    /*96*/ virtual bool isSleeping() const;
    /*97*/ virtual void setSleeping(bool);
    /*98*/ virtual void __unk_vfn_98();
    /*100*/ virtual bool isBlocking() const;
    /*101*/ virtual bool isDamageBlocked(class ActorDamageSource const &) const;
    /*105*/ virtual void __unk_vfn_105();
    /*107*/ virtual void __unk_vfn_107();
    /*108*/ virtual void __unk_vfn_108();
    /*110*/ virtual void __unk_vfn_110();
    /*115*/ virtual bool attack(class Actor &, enum ActorDamageCause const &);
    /*128*/ virtual bool isJumping() const;
    /*134*/ virtual bool isInvulnerableTo(class ActorDamageSource const &) const;
    /*139*/ virtual void onBounceStarted(class BlockPos const &, class Block const &);
    /*140*/ virtual void feed(int);
    /*141*/ virtual void handleEntityEvent(enum ActorEvent, int);
    /*143*/ virtual class HashedString const & getActorRendererId() const;
    /*151*/ virtual void awardKillScore(class Actor &, int);
    /*152*/ virtual void setArmor(enum ArmorSlot, class ItemStack const &);
    /*160*/ virtual void setCarriedItem(class ItemStack const &);
    /*161*/ virtual class ItemStack const & getCarriedItem() const;
    /*162*/ virtual void setOffhandSlot(class ItemStack const &);
    /*163*/ virtual class ItemStack const & getEquippedTotem() const;
    /*164*/ virtual bool consumeTotem();
    /*169*/ virtual enum ActorType getEntityTypeId() const;
    /*173*/ virtual bool canFreeze() const;
    /*177*/ virtual int getPortalCooldown() const;
    /*178*/ virtual int getPortalWaitTime() const;
    /*180*/ virtual bool canChangeDimensionsUsingPortal() const;
    /*181*/ virtual void __unk_vfn_181();
    /*190*/ virtual void onSynchedDataUpdate(int);
    /*191*/ virtual bool canAddPassenger(class Actor &) const;
    /*193*/ virtual bool canBePulledIntoVehicle() const;
    /*195*/ virtual void __unk_vfn_195();
    /*197*/ virtual void sendMotionPacketIfNeeded();
    /*200*/ virtual void startSwimming();
    /*201*/ virtual void stopSwimming();
    /*203*/ virtual enum CommandPermissionLevel getCommandPermissionLevel() const;
    /*216*/ virtual bool canObstructSpawningAndBlockPlacement() const;
    /*217*/ virtual class AnimationComponent & getAnimationComponent();
    /*220*/ virtual void useItem(class ItemStackBase &, enum ItemUseMethod, bool);
    /*221*/ virtual void __unk_vfn_221();
    /*222*/ virtual void __unk_vfn_222();
    /*224*/ virtual float getMapDecorationRotation() const;
    /*230*/ virtual bool isWorldBuilder() const;
    /*231*/ virtual bool isCreative() const;
    /*232*/ virtual bool isAdventure() const;
    /*233*/ virtual bool isSurvival() const;
    /*234*/ virtual bool isSpectator() const;
    /*236*/ virtual bool add(class ItemStack &);
    /*237*/ virtual bool drop(class ItemStack const &, bool);
    /*241*/ virtual void setSize(float, float);
    /*245*/ virtual void startSpinAttack();
    /*246*/ virtual void stopSpinAttack();
    /*248*/ virtual void __unk_vfn_248();
    /*251*/ virtual void __unk_vfn_251();
    /*253*/ virtual void die(class ActorDamageSource const &);
    /*254*/ virtual bool shouldDropDeathLoot() const;
    /*262*/ virtual class std::optional<class BlockPos> getLastDeathPos() const;
    /*263*/ virtual class std::optional<class AutomaticID<class Dimension, int>> getLastDeathDimension() const;
    /*264*/ virtual bool hasDiedBefore() const;
    /*266*/ virtual bool _shouldProvideFeedbackOnHandContainerItemSet(enum HandSlot, class ItemStack const &) const;
    /*267*/ virtual bool _shouldProvideFeedbackOnArmorSet(enum ArmorSlot, class ItemStack const &) const;
    /*270*/ virtual void __unk_vfn_270();
    /*271*/ virtual bool _hurt(class ActorDamageSource const &, float, bool, bool);
    /*274*/ virtual void readAdditionalSaveData(class CompoundTag const &, class DataLoadHelper &);
    /*275*/ virtual void addAdditionalSaveData(class CompoundTag &) const;
    /*278*/ virtual void __unk_vfn_278();
    /*284*/ virtual void _onSizeUpdated();
    /*285*/ virtual void __unk_vfn_285();
    /*292*/ virtual float getSpeed() const;
    /*293*/ virtual void setSpeed(float);
    /*297*/ virtual void travel(float, float, float);
    /*298*/ virtual void travel(struct IMobMovementProxy &, float, float, float) const;
    /*300*/ virtual void aiStep();
    /*301*/ virtual void aiStep(struct IMobMovementProxy &) const;
    /*308*/ virtual int getItemUseDuration() const;
    /*309*/ virtual float getItemUseStartupProgress() const;
    /*310*/ virtual float getItemUseIntervalProgress() const;
    /*313*/ virtual void __unk_vfn_313();
    /*317*/ virtual void __unk_vfn_317();
    /*333*/ virtual std::vector<class ItemStack const *> getAllHand() const;
    /*334*/ virtual std::vector<class ItemStack const *> getAllEquipment() const;
    /*336*/ virtual void dropEquipmentOnDeath(class ActorDamageSource const &, int);
    /*337*/ virtual void dropEquipmentOnDeath();
    /*338*/ virtual void clearVanishEnchantedItemsOnDeath();
    /*339*/ virtual void sendInventory(bool);
    /*350*/ virtual bool canExistWhenDisallowMob() const;
    /*351*/ virtual void __unk_vfn_351();
    /*356*/ virtual std::unique_ptr<class BodyControl> initBodyControl();
    /*357*/ virtual void jumpFromGround();
    /*358*/ virtual void jumpFromGround(struct IMobMovementProxy &) const;
    /*359*/ virtual void updateAi();
    /*364*/ virtual void updateGliding();
    /*365*/ virtual void __unk_vfn_365();
    /*367*/ virtual void prepareRegion(class ChunkSource &);
    /*368*/ virtual void destroyRegion();
    /*369*/ virtual void suspendRegion();
    /*370*/ virtual void resendAllChunks();
    /*371*/ virtual void _fireWillChangeDimension();
    /*372*/ virtual void _fireDimensionChanged();
    /*373*/ virtual void changeDimensionWithCredits(class AutomaticID<class Dimension, int>);
    /*374*/ virtual void tickWorld(struct Tick const &);
    /*375*/ virtual void __unk_vfn_375() = 0;
    /*376*/ virtual std::vector<class ChunkPos> const & getTickingOffsets() const;
    /*377*/ virtual void moveView();
    /*378*/ virtual void moveSpawnView(class Vec3 const &, class AutomaticID<class Dimension, int>);
    /*379*/ virtual void setName(std::string const &);
    /*380*/ virtual enum TravelMethod getTravelledMethod() const;
    /*381*/ virtual void checkMovementStats(class Vec3 const &);
    /*382*/ virtual void __unk_vfn_382();
    /*383*/ virtual void __unk_vfn_383();
    /*384*/ virtual void respawn();
    /*385*/ virtual void __unk_vfn_385();
    /*386*/ virtual void __unk_vfn_386();
    /*387*/ virtual bool hasResource(int);
    /*388*/ virtual void completeUsingItem();
    /*389*/ virtual void startDestroying();
    /*390*/ virtual void stopDestroying();
    /*391*/ virtual void __unk_vfn_391();
    /*392*/ virtual void __unk_vfn_392();
    /*393*/ virtual void openTrading(struct ActorUniqueID const &, bool);
    /*394*/ virtual bool canOpenContainerScreen();
    /*395*/ virtual void __unk_vfn_395();
    /*396*/ virtual void openNpcInteractScreen(class std::shared_ptr<struct INpcDialogueData>);
    /*397*/ virtual void openInventory();
    /*398*/ virtual void displayClientMessage(std::string const &);
    /*399*/ virtual void displayChatMessage(std::string const &, std::string const &);
    /*400*/ virtual void displayTextObjectMessage(class TextObjectRoot const &, std::string const &, std::string const &);
    /*401*/ virtual void displayTextObjectWhisperMessage(class ResolvedTextObject const &, std::string const &, std::string const &);
    /*402*/ virtual void displayTextObjectWhisperMessage(std::string const &, std::string const &, std::string const &);
    /*403*/ virtual void displayWhisperMessage(std::string const &, std::string const &, std::string const &, std::string const &);
    /*404*/ virtual enum BedSleepingResult startSleepInBed(class BlockPos const &);
    /*405*/ virtual void stopSleepInBed(bool, bool);
    /*406*/ virtual bool canStartSleepInBed();
    /*407*/ virtual int getSleepTimer() const;
    /*408*/ virtual int getPreviousTickSleepTimer() const;
    /*409*/ virtual void __unk_vfn_409();
    /*410*/ virtual void __unk_vfn_410();
    /*411*/ virtual bool isHostingPlayer() const;
    /*412*/ virtual bool isLoading() const;
    /*413*/ virtual bool isPlayerInitialized() const;
    /*414*/ virtual void __unk_vfn_414();
    /*415*/ virtual void registerTrackedBoss(struct ActorUniqueID);
    /*416*/ virtual void unRegisterTrackedBoss(struct ActorUniqueID);
    /*417*/ virtual void setPlayerGameType(enum GameType);
    /*418*/ virtual void initHUDContainerManager();
    /*419*/ virtual void _crit(class Actor &);
    /*420*/ virtual class IMinecraftEventing * getEventing() const;
    /*421*/ virtual void __unk_vfn_421();
    /*422*/ virtual void sendEventPacket(class EventPacket &) const;
    /*423*/ virtual void addExperience(int);
    /*424*/ virtual void addLevels(int);
    /*425*/ virtual void setContainerData(class IContainerManager &, int, int) = 0;
    /*426*/ virtual void slotChanged(class IContainerManager &, class Container &, int, class ItemStack const &, class ItemStack const &, bool) = 0;
    /*427*/ virtual void inventoryChanged(class Container &, int, class ItemStack const &, class ItemStack const &, bool);
    /*428*/ virtual void refreshContainer(class IContainerManager &) = 0;
    /*429*/ virtual void deleteContainerManager();
    /*430*/ virtual void setFieldOfViewModifier(float);
    /*431*/ virtual bool isActorRelevant(class Actor const &);
    /*432*/ virtual bool isTeacher() const = 0;
    /*433*/ virtual void onSuspension();
    /*434*/ virtual void onLinkedSlotsChanged();
    /*435*/ virtual void startCooldown(class Item const *, bool);
    /*436*/ virtual int getItemCooldownLeft(class HashedString const &) const;
    /*437*/ virtual int getItemCooldownLeft(unsigned __int64) const;
    /*438*/ virtual int getMaxItemCooldownLeft() const;
    /*439*/ virtual bool isItemOnCooldown(class HashedString const &) const;
    /*440*/ virtual void sendInventoryTransaction(class InventoryTransaction const &) const = 0;
    /*441*/ virtual void sendComplexInventoryTransaction(std::unique_ptr<class ComplexInventoryTransaction>) const = 0;
    /*442*/ virtual void sendNetworkPacket(class Packet &) const;
    /*443*/ virtual class PlayerEventCoordinator & getPlayerEventCoordinator() = 0;
    /*444*/ virtual class MoveInputHandler * tryGetMoveInputHandler() const = 0;
    /*445*/ virtual enum InputMode getInputMode() const = 0;
    /*446*/ virtual enum ClientPlayMode getPlayMode() const = 0;
    /*447*/ virtual void reportMovementTelemetry(enum MovementEventType);
    /*448*/ virtual void __unk_vfn_448();
    /*449*/ virtual std::string getXuid() const;
    /*450*/ virtual struct PlayerMovementSettings const & getMovementSettings() const;
    /*451*/ virtual void addSavedChunk(class ChunkPos const &);
    /*452*/ virtual void onMovePlayerPacketNormal(class Vec3 const &, class Vec2 const &, float);
    /*453*/ virtual class std::shared_ptr<class ChunkViewSource> _createChunkSource(class ChunkSource &);
};