static unsigned long * F_1 ( T_1 * V_1 )
{
#if F_2 ( V_2 ) && V_3 == 32
* V_1 = ( * V_1 >> 32 ) | ( * V_1 << 32 ) ;
#endif
return ( unsigned long * ) V_1 ;
}
static inline void F_3 ( int V_4 , T_2 V_1 )
{
void T_3 * V_5 = V_6 . V_7 ;
F_4 ( V_1 , V_5 + V_8 + ( V_4 * 4 ) ) ;
}
void F_5 ( void )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_6 . V_10 ; V_9 ++ )
F_3 ( V_9 , 0 ) ;
}
void F_6 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = & V_12 -> V_15 . V_16 . V_17 ;
if ( V_14 -> V_18 & V_19 ) {
T_1 V_20 = V_14 -> V_21 ;
unsigned long * V_22 = F_1 ( & V_20 ) ;
int V_4 ;
F_7 (lr, eisr_bmap, kvm_vgic_global_state.nr_lr) {
T_2 V_23 = V_14 -> V_24 [ V_4 ] & V_25 ;
F_8 ( V_14 -> V_24 [ V_4 ] & V_26 ) ;
if ( F_9 ( V_12 -> V_27 , V_23 ) )
F_10 ( V_12 -> V_27 , 0 ,
V_23 - V_28 ) ;
}
}
V_14 -> V_29 &= ~ V_30 ;
V_14 -> V_21 = 0 ;
}
void F_11 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = & V_12 -> V_15 . V_16 . V_17 ;
V_14 -> V_29 |= V_30 ;
}
void F_12 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = & V_12 -> V_15 . V_16 . V_17 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_12 -> V_15 . V_16 . V_31 ; V_4 ++ ) {
T_2 V_1 = V_14 -> V_24 [ V_4 ] ;
T_2 V_23 = V_1 & V_25 ;
struct V_32 * V_33 ;
V_33 = F_13 ( V_12 -> V_27 , V_12 , V_23 ) ;
F_14 ( & V_33 -> V_34 ) ;
V_33 -> V_35 = ! ! ( V_1 & V_36 ) ;
if ( V_33 -> V_37 == V_38 &&
( V_1 & V_39 ) ) {
V_33 -> V_40 = true ;
if ( F_15 ( V_23 ) ) {
T_2 V_41 = V_1 & V_42 ;
V_41 >>= V_43 ;
V_33 -> V_44 |= ( 1 << V_41 ) ;
}
}
if ( V_33 -> V_37 == V_45 ) {
if ( ! ( V_1 & V_39 ) )
V_33 -> V_40 = false ;
}
F_16 ( & V_33 -> V_34 ) ;
F_17 ( V_12 -> V_27 , V_33 ) ;
}
}
void F_18 ( struct V_11 * V_12 , struct V_32 * V_33 , int V_4 )
{
T_2 V_1 = V_33 -> V_23 ;
if ( F_19 ( V_33 ) ) {
V_1 |= V_39 ;
if ( V_33 -> V_37 == V_38 )
V_33 -> V_40 = false ;
if ( F_15 ( V_33 -> V_23 ) ) {
T_2 V_46 = F_20 ( V_33 -> V_44 ) ;
F_21 ( ! V_46 ) ;
V_1 |= ( V_46 - 1 ) << V_43 ;
V_33 -> V_44 &= ~ ( 1 << ( V_46 - 1 ) ) ;
if ( V_33 -> V_44 )
V_33 -> V_40 = true ;
}
}
if ( V_33 -> V_35 )
V_1 |= V_36 ;
if ( V_33 -> V_47 ) {
V_1 |= V_48 ;
V_1 |= V_33 -> V_49 << V_43 ;
} else {
if ( V_33 -> V_37 == V_45 )
V_1 |= V_50 ;
}
V_1 |= ( V_33 -> V_51 >> 3 ) << V_52 ;
V_12 -> V_15 . V_16 . V_17 . V_24 [ V_4 ] = V_1 ;
}
void F_22 ( struct V_11 * V_12 , int V_4 )
{
V_12 -> V_15 . V_16 . V_17 . V_24 [ V_4 ] = 0 ;
}
void F_23 ( struct V_11 * V_12 , struct V_53 * V_54 )
{
T_2 V_55 ;
V_55 = ( V_54 -> V_56 << V_57 ) & V_58 ;
V_55 |= ( V_54 -> V_59 << V_60 ) &
V_61 ;
V_55 |= ( V_54 -> V_62 << V_63 ) &
V_64 ;
V_55 |= ( ( V_54 -> V_65 >> V_66 ) <<
V_67 ) & V_68 ;
V_12 -> V_15 . V_16 . V_17 . V_53 = V_55 ;
}
void F_24 ( struct V_11 * V_12 , struct V_53 * V_54 )
{
T_2 V_55 = V_12 -> V_15 . V_16 . V_17 . V_53 ;
V_54 -> V_56 = ( V_55 & V_58 ) >>
V_57 ;
V_54 -> V_59 = ( V_55 & V_61 ) >>
V_60 ;
V_54 -> V_62 = ( V_55 & V_64 ) >>
V_63 ;
V_54 -> V_65 = ( ( V_55 & V_68 ) >>
V_67 ) << V_66 ;
}
void F_25 ( struct V_11 * V_12 )
{
V_12 -> V_15 . V_16 . V_17 . V_53 = 0 ;
V_12 -> V_15 . V_16 . V_17 . V_69 = ~ 0 ;
V_12 -> V_15 . V_16 . V_17 . V_29 = V_70 ;
}
static bool F_26 ( T_4 V_71 , T_4 V_72 )
{
if ( V_71 + V_73 < V_71 )
return false ;
if ( V_72 + V_74 < V_72 )
return false ;
if ( V_71 + V_73 <= V_72 )
return true ;
if ( V_72 + V_74 <= V_71 )
return true ;
return false ;
}
int F_27 ( struct V_27 * V_27 )
{
struct V_75 * V_76 = & V_27 -> V_15 . V_77 ;
int V_78 = 0 ;
if ( F_28 ( V_27 ) )
goto V_79;
if ( F_29 ( V_76 -> V_80 ) ||
F_29 ( V_76 -> V_81 ) ) {
F_30 ( L_1 ) ;
V_78 = - V_82 ;
goto V_79;
}
if ( ! F_26 ( V_76 -> V_80 , V_76 -> V_81 ) ) {
F_30 ( L_2 ) ;
V_78 = - V_83 ;
goto V_79;
}
V_78 = F_31 ( V_27 ) ;
if ( V_78 ) {
F_30 ( L_3 ) ;
goto V_79;
}
V_78 = F_32 ( V_27 , V_76 -> V_80 , V_84 ) ;
if ( V_78 ) {
F_30 ( L_4 ) ;
goto V_79;
}
if ( ! F_33 ( & V_85 ) ) {
V_78 = F_34 ( V_27 , V_76 -> V_81 ,
V_6 . V_86 ,
V_74 , true ) ;
if ( V_78 ) {
F_30 ( L_5 ) ;
goto V_79;
}
}
V_76 -> V_87 = true ;
V_79:
return V_78 ;
}
int F_35 ( const struct V_88 * V_89 )
{
int V_78 ;
T_2 V_90 ;
if ( ! V_89 -> V_91 . V_92 ) {
F_30 ( L_6 ) ;
return - V_82 ;
}
if ( ! F_36 ( V_89 -> V_12 . V_92 ) ||
! F_36 ( F_37 ( & V_89 -> V_12 ) ) ) {
F_38 ( L_7 ) ;
V_6 . V_93 = F_39 ( V_89 -> V_12 . V_92 ,
F_37 ( & V_89 -> V_12 ) ) ;
if ( ! V_6 . V_93 ) {
F_30 ( L_8 ) ;
return - V_94 ;
}
V_78 = F_40 ( V_6 . V_93 ,
V_6 . V_93 + F_37 ( & V_89 -> V_12 ) ,
V_89 -> V_12 . V_92 ) ;
if ( V_78 ) {
F_30 ( L_9 ) ;
goto V_79;
}
F_41 ( & V_85 ) ;
}
V_6 . V_7 = F_39 ( V_89 -> V_91 . V_92 ,
F_37 ( & V_89 -> V_91 ) ) ;
if ( ! V_6 . V_7 ) {
F_30 ( L_10 ) ;
V_78 = - V_94 ;
goto V_79;
}
V_90 = F_42 ( V_6 . V_7 + V_95 ) ;
V_6 . V_10 = ( V_90 & 0x3f ) + 1 ;
V_78 = F_40 ( V_6 . V_7 ,
V_6 . V_7 +
F_37 ( & V_89 -> V_91 ) ,
V_89 -> V_91 . V_92 ) ;
if ( V_78 ) {
F_30 ( L_11 ) ;
goto V_79;
}
V_78 = F_43 ( V_96 ) ;
if ( V_78 ) {
F_30 ( L_12 ) ;
goto V_79;
}
V_6 . V_97 = true ;
V_6 . V_86 = V_89 -> V_12 . V_92 ;
V_6 . type = V_84 ;
V_6 . V_98 = V_99 ;
F_38 ( L_13 , V_89 -> V_91 . V_92 ) ;
return 0 ;
V_79:
if ( V_6 . V_7 )
F_44 ( V_6 . V_7 ) ;
if ( V_6 . V_93 )
F_44 ( V_6 . V_93 ) ;
return V_78 ;
}
