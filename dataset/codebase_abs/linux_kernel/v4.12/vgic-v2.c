static inline void F_1 ( int V_1 , T_1 V_2 )
{
void T_2 * V_3 = V_4 . V_5 ;
F_2 ( V_2 , V_3 + V_6 + ( V_1 * 4 ) ) ;
}
void F_3 ( void )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_4 . V_8 ; V_7 ++ )
F_1 ( V_7 , 0 ) ;
}
void F_4 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = & V_10 -> V_13 . V_14 . V_15 ;
V_12 -> V_16 |= V_17 ;
}
static bool F_5 ( T_1 V_18 )
{
return ! ( V_18 & V_19 ) && ( V_18 & V_20 ) &&
! ( V_18 & V_21 ) ;
}
void F_6 ( struct V_9 * V_10 )
{
struct V_14 * V_14 = & V_10 -> V_13 . V_14 ;
struct V_11 * V_12 = & V_14 -> V_15 ;
int V_1 ;
V_12 -> V_16 &= ~ V_17 ;
for ( V_1 = 0 ; V_1 < V_14 -> V_22 ; V_1 ++ ) {
T_1 V_2 = V_12 -> V_23 [ V_1 ] ;
T_1 V_24 = V_2 & V_25 ;
struct V_26 * V_27 ;
if ( F_5 ( V_2 ) && F_7 ( V_10 -> V_28 , V_24 ) )
F_8 ( V_10 -> V_28 , 0 ,
V_24 - V_29 ) ;
V_27 = F_9 ( V_10 -> V_28 , V_10 , V_24 ) ;
F_10 ( & V_27 -> V_30 ) ;
V_27 -> V_31 = ! ! ( V_2 & V_32 ) ;
if ( V_27 -> V_33 == V_34 &&
( V_2 & V_35 ) ) {
V_27 -> V_36 = true ;
if ( F_11 ( V_24 ) ) {
T_1 V_37 = V_2 & V_38 ;
V_37 >>= V_39 ;
V_27 -> V_40 |= ( 1 << V_37 ) ;
}
}
if ( V_27 -> V_33 == V_41 ) {
if ( ! ( V_2 & V_35 ) )
V_27 -> V_36 = false ;
}
F_12 ( & V_27 -> V_30 ) ;
F_13 ( V_10 -> V_28 , V_27 ) ;
}
V_14 -> V_22 = 0 ;
}
void F_14 ( struct V_9 * V_10 , struct V_26 * V_27 , int V_1 )
{
T_1 V_2 = V_27 -> V_24 ;
if ( F_15 ( V_27 ) ) {
V_2 |= V_35 ;
if ( V_27 -> V_33 == V_34 )
V_27 -> V_36 = false ;
if ( F_11 ( V_27 -> V_24 ) ) {
T_1 V_42 = F_16 ( V_27 -> V_40 ) ;
F_17 ( ! V_42 ) ;
V_2 |= ( V_42 - 1 ) << V_39 ;
V_27 -> V_40 &= ~ ( 1 << ( V_42 - 1 ) ) ;
if ( V_27 -> V_40 )
V_27 -> V_36 = true ;
}
}
if ( V_27 -> V_31 )
V_2 |= V_32 ;
if ( V_27 -> V_43 ) {
V_2 |= V_21 ;
V_2 |= V_27 -> V_44 << V_39 ;
if ( V_27 -> V_31 && F_15 ( V_27 ) )
V_2 &= ~ V_35 ;
} else {
if ( V_27 -> V_33 == V_41 )
V_2 |= V_20 ;
}
V_2 |= ( V_27 -> V_45 >> 3 ) << V_46 ;
V_10 -> V_13 . V_14 . V_15 . V_23 [ V_1 ] = V_2 ;
}
void F_18 ( struct V_9 * V_10 , int V_1 )
{
V_10 -> V_13 . V_14 . V_15 . V_23 [ V_1 ] = 0 ;
}
void F_19 ( struct V_9 * V_10 , struct V_47 * V_48 )
{
struct V_11 * V_49 = & V_10 -> V_13 . V_14 . V_15 ;
T_1 V_50 ;
V_50 = ( V_48 -> V_51 << V_52 ) &
V_53 ;
V_50 |= ( V_48 -> V_54 << V_55 ) &
V_56 ;
V_50 |= ( V_48 -> V_57 << V_58 ) &
V_59 ;
V_50 |= ( V_48 -> V_60 << V_61 ) &
V_62 ;
V_50 |= ( V_48 -> V_63 << V_64 ) &
V_65 ;
V_50 |= ( V_48 -> V_66 << V_67 ) &
V_68 ;
V_50 |= ( V_48 -> V_69 << V_70 ) &
V_71 ;
V_50 |= ( V_48 -> V_72 << V_73 ) &
V_74 ;
V_50 |= ( ( V_48 -> V_75 >> V_76 ) <<
V_77 ) & V_78 ;
V_49 -> V_47 = V_50 ;
}
void F_20 ( struct V_9 * V_10 , struct V_47 * V_48 )
{
struct V_11 * V_49 = & V_10 -> V_13 . V_14 . V_15 ;
T_1 V_50 ;
V_50 = V_49 -> V_47 ;
V_48 -> V_51 = ( V_50 & V_53 ) >>
V_52 ;
V_48 -> V_54 = ( V_50 & V_56 ) >>
V_55 ;
V_48 -> V_57 = ( V_50 & V_59 ) >>
V_58 ;
V_48 -> V_60 = ( V_50 & V_62 ) >>
V_61 ;
V_48 -> V_63 = ( V_50 & V_65 ) >>
V_64 ;
V_48 -> V_66 = ( V_50 & V_68 ) >>
V_67 ;
V_48 -> V_69 = ( V_50 & V_71 ) >>
V_70 ;
V_48 -> V_72 = ( V_50 & V_74 ) >>
V_73 ;
V_48 -> V_75 = ( ( V_50 & V_78 ) >>
V_77 ) << V_76 ;
}
void F_21 ( struct V_9 * V_10 )
{
V_10 -> V_13 . V_14 . V_15 . V_47 = 0 ;
V_10 -> V_13 . V_14 . V_15 . V_79 = ~ 0 ;
V_10 -> V_13 . V_14 . V_15 . V_16 = V_80 ;
}
static bool F_22 ( T_3 V_81 , T_3 V_82 )
{
if ( V_81 + V_83 < V_81 )
return false ;
if ( V_82 + V_84 < V_82 )
return false ;
if ( V_81 + V_83 <= V_82 )
return true ;
if ( V_82 + V_84 <= V_81 )
return true ;
return false ;
}
int F_23 ( struct V_28 * V_28 )
{
struct V_85 * V_86 = & V_28 -> V_13 . V_87 ;
int V_88 = 0 ;
if ( F_24 ( V_28 ) )
goto V_89;
if ( F_25 ( V_86 -> V_90 ) ||
F_25 ( V_86 -> V_91 ) ) {
F_26 ( L_1 ) ;
V_88 = - V_92 ;
goto V_89;
}
if ( ! F_22 ( V_86 -> V_90 , V_86 -> V_91 ) ) {
F_26 ( L_2 ) ;
V_88 = - V_93 ;
goto V_89;
}
V_88 = F_27 ( V_28 ) ;
if ( V_88 ) {
F_26 ( L_3 ) ;
goto V_89;
}
V_88 = F_28 ( V_28 , V_86 -> V_90 , V_94 ) ;
if ( V_88 ) {
F_26 ( L_4 ) ;
goto V_89;
}
if ( ! F_29 ( & V_95 ) ) {
V_88 = F_30 ( V_28 , V_86 -> V_91 ,
V_4 . V_96 ,
V_84 , true ) ;
if ( V_88 ) {
F_26 ( L_5 ) ;
goto V_89;
}
}
V_86 -> V_97 = true ;
V_89:
return V_88 ;
}
int F_31 ( const struct V_98 * V_99 )
{
int V_88 ;
T_1 V_100 ;
if ( ! V_99 -> V_101 . V_102 ) {
F_26 ( L_6 ) ;
return - V_92 ;
}
if ( ! F_32 ( V_99 -> V_10 . V_102 ) ||
! F_32 ( F_33 ( & V_99 -> V_10 ) ) ) {
F_34 ( L_7 ) ;
V_4 . V_103 = F_35 ( V_99 -> V_10 . V_102 ,
F_33 ( & V_99 -> V_10 ) ) ;
if ( ! V_4 . V_103 ) {
F_26 ( L_8 ) ;
return - V_104 ;
}
V_88 = F_36 ( V_4 . V_103 ,
V_4 . V_103 + F_33 ( & V_99 -> V_10 ) ,
V_99 -> V_10 . V_102 ) ;
if ( V_88 ) {
F_26 ( L_9 ) ;
goto V_89;
}
F_37 ( & V_95 ) ;
}
V_4 . V_5 = F_35 ( V_99 -> V_101 . V_102 ,
F_33 ( & V_99 -> V_101 ) ) ;
if ( ! V_4 . V_5 ) {
F_26 ( L_10 ) ;
V_88 = - V_104 ;
goto V_89;
}
V_100 = F_38 ( V_4 . V_5 + V_105 ) ;
V_4 . V_8 = ( V_100 & 0x3f ) + 1 ;
V_88 = F_36 ( V_4 . V_5 ,
V_4 . V_5 +
F_33 ( & V_99 -> V_101 ) ,
V_99 -> V_101 . V_102 ) ;
if ( V_88 ) {
F_26 ( L_11 ) ;
goto V_89;
}
V_88 = F_39 ( V_106 ) ;
if ( V_88 ) {
F_26 ( L_12 ) ;
goto V_89;
}
V_4 . V_107 = true ;
V_4 . V_96 = V_99 -> V_10 . V_102 ;
V_4 . type = V_94 ;
V_4 . V_108 = V_109 ;
F_34 ( L_13 , V_99 -> V_101 . V_102 ) ;
return 0 ;
V_89:
if ( V_4 . V_5 )
F_40 ( V_4 . V_5 ) ;
if ( V_4 . V_103 )
F_40 ( V_4 . V_103 ) ;
return V_88 ;
}
void F_41 ( struct V_9 * V_10 )
{
struct V_11 * V_49 = & V_10 -> V_13 . V_14 . V_15 ;
struct V_85 * V_87 = & V_10 -> V_28 -> V_13 . V_87 ;
F_2 ( V_49 -> V_47 , V_87 -> V_5 + V_110 ) ;
}
void F_42 ( struct V_9 * V_10 )
{
struct V_11 * V_49 = & V_10 -> V_13 . V_14 . V_15 ;
struct V_85 * V_87 = & V_10 -> V_28 -> V_13 . V_87 ;
V_49 -> V_47 = F_38 ( V_87 -> V_5 + V_110 ) ;
}
