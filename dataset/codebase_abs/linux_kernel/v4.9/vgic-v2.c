static unsigned long * F_1 ( T_1 * V_1 )
{
#if F_2 ( V_2 ) && V_3 == 32
* V_1 = ( * V_1 >> 32 ) | ( * V_1 << 32 ) ;
#endif
return ( unsigned long * ) V_1 ;
}
void F_3 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_8 . V_9 . V_10 ;
if ( V_7 -> V_11 & V_12 ) {
T_1 V_13 = V_7 -> V_14 ;
unsigned long * V_15 = F_1 ( & V_13 ) ;
int V_16 ;
F_4 (lr, eisr_bmap, kvm_vgic_global_state.nr_lr) {
T_2 V_17 = V_7 -> V_18 [ V_16 ] & V_19 ;
F_5 ( V_7 -> V_18 [ V_16 ] & V_20 ) ;
if ( F_6 ( V_5 -> V_21 , V_17 ) )
F_7 ( V_5 -> V_21 , 0 ,
V_17 - V_22 ) ;
}
}
V_7 -> V_23 &= ~ V_24 ;
V_7 -> V_14 = 0 ;
}
void F_8 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_8 . V_9 . V_10 ;
V_7 -> V_23 |= V_24 ;
}
void F_9 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_8 . V_9 . V_10 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_5 -> V_8 . V_9 . V_25 ; V_16 ++ ) {
T_2 V_1 = V_7 -> V_18 [ V_16 ] ;
T_2 V_17 = V_1 & V_19 ;
struct V_26 * V_27 ;
V_27 = F_10 ( V_5 -> V_21 , V_5 , V_17 ) ;
F_11 ( & V_27 -> V_28 ) ;
V_27 -> V_29 = ! ! ( V_1 & V_30 ) ;
if ( V_27 -> V_31 == V_32 &&
( V_1 & V_33 ) ) {
V_27 -> V_34 = true ;
if ( F_12 ( V_17 ) ) {
T_2 V_35 = V_1 & V_36 ;
V_35 >>= V_37 ;
V_27 -> V_38 |= ( 1 << V_35 ) ;
}
}
if ( V_27 -> V_31 == V_39 ) {
if ( ! ( V_1 & V_33 ) )
V_27 -> V_40 = false ;
V_27 -> V_34 = V_27 -> V_41 || V_27 -> V_40 ;
}
F_13 ( & V_27 -> V_28 ) ;
F_14 ( V_5 -> V_21 , V_27 ) ;
}
}
void F_15 ( struct V_4 * V_5 , struct V_26 * V_27 , int V_16 )
{
T_2 V_1 = V_27 -> V_17 ;
if ( V_27 -> V_34 ) {
V_1 |= V_33 ;
if ( V_27 -> V_31 == V_32 )
V_27 -> V_34 = false ;
if ( F_12 ( V_27 -> V_17 ) ) {
T_2 V_42 = F_16 ( V_27 -> V_38 ) ;
F_17 ( ! V_42 ) ;
V_1 |= ( V_42 - 1 ) << V_37 ;
V_27 -> V_38 &= ~ ( 1 << ( V_42 - 1 ) ) ;
if ( V_27 -> V_38 )
V_27 -> V_34 = true ;
}
}
if ( V_27 -> V_29 )
V_1 |= V_30 ;
if ( V_27 -> V_43 ) {
V_1 |= V_44 ;
V_1 |= V_27 -> V_45 << V_37 ;
} else {
if ( V_27 -> V_31 == V_39 )
V_1 |= V_46 ;
}
V_1 |= ( V_27 -> V_47 >> 3 ) << V_48 ;
V_5 -> V_8 . V_9 . V_10 . V_18 [ V_16 ] = V_1 ;
}
void F_18 ( struct V_4 * V_5 , int V_16 )
{
V_5 -> V_8 . V_9 . V_10 . V_18 [ V_16 ] = 0 ;
}
void F_19 ( struct V_4 * V_5 , struct V_49 * V_50 )
{
T_2 V_51 ;
V_51 = ( V_50 -> V_52 << V_53 ) & V_54 ;
V_51 |= ( V_50 -> V_55 << V_56 ) &
V_57 ;
V_51 |= ( V_50 -> V_58 << V_59 ) &
V_60 ;
V_51 |= ( V_50 -> V_61 << V_62 ) &
V_63 ;
V_5 -> V_8 . V_9 . V_10 . V_49 = V_51 ;
}
void F_20 ( struct V_4 * V_5 , struct V_49 * V_50 )
{
T_2 V_51 = V_5 -> V_8 . V_9 . V_10 . V_49 ;
V_50 -> V_52 = ( V_51 & V_54 ) >>
V_53 ;
V_50 -> V_55 = ( V_51 & V_57 ) >>
V_56 ;
V_50 -> V_58 = ( V_51 & V_60 ) >>
V_59 ;
V_50 -> V_61 = ( V_51 & V_63 ) >>
V_62 ;
}
void F_21 ( struct V_4 * V_5 )
{
V_5 -> V_8 . V_9 . V_10 . V_49 = 0 ;
V_5 -> V_8 . V_9 . V_10 . V_64 = ~ 0 ;
V_5 -> V_8 . V_9 . V_10 . V_23 = V_65 ;
}
static bool F_22 ( T_3 V_66 , T_3 V_67 )
{
if ( V_66 + V_68 < V_66 )
return false ;
if ( V_67 + V_69 < V_67 )
return false ;
if ( V_66 + V_68 <= V_67 )
return true ;
if ( V_67 + V_69 <= V_66 )
return true ;
return false ;
}
int F_23 ( struct V_21 * V_21 )
{
struct V_70 * V_71 = & V_21 -> V_8 . V_72 ;
int V_73 = 0 ;
if ( F_24 ( V_21 ) )
goto V_74;
if ( F_25 ( V_71 -> V_75 ) ||
F_25 ( V_71 -> V_76 ) ) {
F_26 ( L_1 ) ;
V_73 = - V_77 ;
goto V_74;
}
if ( ! F_22 ( V_71 -> V_75 , V_71 -> V_76 ) ) {
F_26 ( L_2 ) ;
V_73 = - V_78 ;
goto V_74;
}
V_73 = F_27 ( V_21 ) ;
if ( V_73 ) {
F_26 ( L_3 ) ;
goto V_74;
}
V_73 = F_28 ( V_21 , V_71 -> V_75 , V_79 ) ;
if ( V_73 ) {
F_26 ( L_4 ) ;
goto V_74;
}
if ( ! F_29 ( & V_80 ) ) {
V_73 = F_30 ( V_21 , V_71 -> V_76 ,
V_81 . V_82 ,
V_69 , true ) ;
if ( V_73 ) {
F_26 ( L_5 ) ;
goto V_74;
}
}
V_71 -> V_83 = true ;
V_74:
if ( V_73 )
F_31 ( V_21 ) ;
return V_73 ;
}
int F_32 ( const struct V_84 * V_85 )
{
int V_73 ;
T_2 V_86 ;
if ( ! V_85 -> V_87 . V_88 ) {
F_26 ( L_6 ) ;
return - V_77 ;
}
if ( ! F_33 ( V_85 -> V_5 . V_88 ) ||
! F_33 ( F_34 ( & V_85 -> V_5 ) ) ) {
F_35 ( L_7 ) ;
V_81 . V_89 = F_36 ( V_85 -> V_5 . V_88 ,
F_34 ( & V_85 -> V_5 ) ) ;
if ( ! V_81 . V_89 ) {
F_26 ( L_8 ) ;
return - V_90 ;
}
V_73 = F_37 ( V_81 . V_89 ,
V_81 . V_89 + F_34 ( & V_85 -> V_5 ) ,
V_85 -> V_5 . V_88 ) ;
if ( V_73 ) {
F_26 ( L_9 ) ;
goto V_74;
}
F_38 ( & V_80 ) ;
}
V_81 . V_91 = F_36 ( V_85 -> V_87 . V_88 ,
F_34 ( & V_85 -> V_87 ) ) ;
if ( ! V_81 . V_91 ) {
F_26 ( L_10 ) ;
V_73 = - V_90 ;
goto V_74;
}
V_86 = F_39 ( V_81 . V_91 + V_92 ) ;
V_81 . V_93 = ( V_86 & 0x3f ) + 1 ;
V_73 = F_37 ( V_81 . V_91 ,
V_81 . V_91 +
F_34 ( & V_85 -> V_87 ) ,
V_85 -> V_87 . V_88 ) ;
if ( V_73 ) {
F_26 ( L_11 ) ;
goto V_74;
}
V_73 = F_40 ( V_94 ) ;
if ( V_73 ) {
F_26 ( L_12 ) ;
goto V_74;
}
V_81 . V_95 = true ;
V_81 . V_82 = V_85 -> V_5 . V_88 ;
V_81 . type = V_79 ;
V_81 . V_96 = V_97 ;
F_35 ( L_13 , V_85 -> V_87 . V_88 ) ;
return 0 ;
V_74:
if ( V_81 . V_91 )
F_41 ( V_81 . V_91 ) ;
if ( V_81 . V_89 )
F_41 ( V_81 . V_89 ) ;
return V_73 ;
}
