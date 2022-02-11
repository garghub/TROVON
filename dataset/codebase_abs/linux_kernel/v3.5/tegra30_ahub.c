static inline void F_1 ( T_1 V_1 , T_1 V_2 )
{
F_2 ( V_3 -> V_4 , V_1 , V_2 ) ;
}
static inline T_1 F_3 ( T_1 V_1 )
{
T_1 V_2 ;
F_4 ( V_3 -> V_4 , V_1 , & V_2 ) ;
return V_2 ;
}
static inline void F_5 ( T_1 V_1 , T_1 V_2 )
{
F_2 ( V_3 -> V_5 , V_1 , V_2 ) ;
}
static int F_6 ( struct V_6 * V_7 )
{
F_7 ( V_3 -> V_4 , true ) ;
F_7 ( V_3 -> V_5 , true ) ;
F_8 ( V_3 -> V_8 ) ;
F_8 ( V_3 -> V_9 ) ;
return 0 ;
}
static int F_9 ( struct V_6 * V_7 )
{
int V_10 ;
V_10 = F_10 ( V_3 -> V_9 ) ;
if ( V_10 ) {
F_11 ( V_7 , L_1 , V_10 ) ;
return V_10 ;
}
V_10 = F_10 ( V_3 -> V_8 ) ;
if ( V_10 ) {
F_11 ( V_7 , L_2 , V_10 ) ;
F_8 ( V_3 -> V_9 ) ;
return V_10 ;
}
F_7 ( V_3 -> V_4 , false ) ;
F_7 ( V_3 -> V_5 , false ) ;
return 0 ;
}
int F_12 ( enum V_11 * V_12 ,
unsigned long * V_13 ,
unsigned long * V_14 )
{
int V_15 ;
T_1 V_1 , V_2 ;
V_15 = F_13 ( V_3 -> V_16 ,
V_17 ) ;
if ( V_15 >= V_17 )
return - V_18 ;
F_14 ( V_15 , V_3 -> V_16 ) ;
* V_12 = V_19 + V_15 ;
* V_13 = V_3 -> V_20 + V_21 +
( V_15 * V_22 ) ;
* V_14 = V_3 -> V_23 + V_15 ;
V_1 = V_24 +
( V_15 * V_25 ) ;
V_2 = F_3 ( V_1 ) ;
V_2 &= ~ ( V_26 |
V_27 ) ;
V_2 |= ( 7 << V_28 ) |
V_29 |
V_30 ;
F_1 ( V_1 , V_2 ) ;
V_1 = V_31 +
( V_15 * V_32 ) ;
V_2 = ( 0 << V_33 ) |
( 1 << V_34 ) |
( 1 << V_35 ) |
V_36 |
V_37 |
V_38 ;
F_1 ( V_1 , V_2 ) ;
return 0 ;
}
int F_15 ( enum V_11 V_12 )
{
int V_15 = V_12 - V_19 ;
int V_1 , V_2 ;
V_1 = V_24 +
( V_15 * V_25 ) ;
V_2 = F_3 ( V_1 ) ;
V_2 |= V_39 ;
F_1 ( V_1 , V_2 ) ;
return 0 ;
}
int F_16 ( enum V_11 V_12 )
{
int V_15 = V_12 - V_19 ;
int V_1 , V_2 ;
V_1 = V_24 +
( V_15 * V_25 ) ;
V_2 = F_3 ( V_1 ) ;
V_2 &= ~ V_39 ;
F_1 ( V_1 , V_2 ) ;
return 0 ;
}
int F_17 ( enum V_11 V_12 )
{
int V_15 = V_12 - V_19 ;
F_18 ( V_15 , V_3 -> V_16 ) ;
return 0 ;
}
int F_19 ( enum V_40 * V_41 ,
unsigned long * V_13 ,
unsigned long * V_14 )
{
int V_15 ;
T_1 V_1 , V_2 ;
V_15 = F_13 ( V_3 -> V_42 ,
V_17 ) ;
if ( V_15 >= V_17 )
return - V_18 ;
F_14 ( V_15 , V_3 -> V_42 ) ;
* V_41 = V_43 + V_15 ;
* V_13 = V_3 -> V_20 + V_44 +
( V_15 * V_45 ) ;
* V_14 = V_3 -> V_23 + V_15 ;
V_1 = V_24 +
( V_15 * V_25 ) ;
V_2 = F_3 ( V_1 ) ;
V_2 &= ~ ( V_46 |
V_47 ) ;
V_2 |= ( 7 << V_48 ) |
V_49 |
V_50 ;
F_1 ( V_1 , V_2 ) ;
V_1 = V_51 +
( V_15 * V_52 ) ;
V_2 = ( 0 << V_33 ) |
( 1 << V_34 ) |
( 1 << V_35 ) |
V_36 |
V_37 |
V_53 ;
F_1 ( V_1 , V_2 ) ;
return 0 ;
}
int F_20 ( enum V_40 V_41 )
{
int V_15 = V_41 - V_43 ;
int V_1 , V_2 ;
V_1 = V_24 +
( V_15 * V_25 ) ;
V_2 = F_3 ( V_1 ) ;
V_2 |= V_54 ;
F_1 ( V_1 , V_2 ) ;
return 0 ;
}
int F_21 ( enum V_40 V_41 )
{
int V_15 = V_41 - V_43 ;
int V_1 , V_2 ;
V_1 = V_24 +
( V_15 * V_25 ) ;
V_2 = F_3 ( V_1 ) ;
V_2 &= ~ V_54 ;
F_1 ( V_1 , V_2 ) ;
return 0 ;
}
int F_22 ( enum V_40 V_41 )
{
int V_15 = V_41 - V_43 ;
F_18 ( V_15 , V_3 -> V_42 ) ;
return 0 ;
}
int F_23 ( enum V_11 V_12 ,
enum V_40 V_41 )
{
int V_15 = V_12 - V_19 ;
int V_1 ;
V_1 = V_55 +
( V_15 * V_56 ) ;
F_5 ( V_1 , 1 << V_41 ) ;
return 0 ;
}
int F_24 ( enum V_11 V_12 )
{
int V_15 = V_12 - V_19 ;
int V_1 ;
V_1 = V_55 +
( V_15 * V_56 ) ;
F_5 ( V_1 , 0 ) ;
return 0 ;
}
static bool F_25 ( struct V_6 * V_7 , unsigned int V_1 )
{
switch ( V_1 ) {
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
return true ;
default:
break;
} ;
if ( F_26 ( V_1 , V_78 ) ||
F_26 ( V_1 , V_79 ) ||
F_26 ( V_1 , V_80 ) ||
F_26 ( V_1 , V_81 ) ||
F_26 ( V_1 , V_82 ) ||
F_26 ( V_1 , V_83 ) ||
F_26 ( V_1 , V_84 ) ||
F_26 ( V_1 , V_85 ) )
return true ;
return false ;
}
static bool F_27 ( struct V_6 * V_7 ,
unsigned int V_1 )
{
switch ( V_1 ) {
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
return true ;
default:
break;
} ;
if ( F_26 ( V_1 , V_79 ) ||
F_26 ( V_1 , V_80 ) ||
F_26 ( V_1 , V_81 ) ||
F_26 ( V_1 , V_82 ) ||
F_26 ( V_1 , V_85 ) )
return true ;
return false ;
}
static bool F_28 ( struct V_6 * V_7 ,
unsigned int V_1 )
{
if ( F_26 ( V_1 , V_81 ) ||
F_26 ( V_1 , V_82 ) )
return true ;
return false ;
}
static bool F_29 ( struct V_6 * V_7 , unsigned int V_1 )
{
if ( F_26 ( V_1 , V_86 ) )
return true ;
return false ;
}
static int T_2 F_30 ( struct V_87 * V_88 )
{
struct V_89 * V_89 ;
int V_90 ;
struct V_91 * V_92 , * V_93 , * V_94 ;
T_1 V_95 [ 2 ] ;
void T_3 * V_96 , * V_97 ;
int V_10 = 0 ;
if ( V_3 )
return - V_98 ;
for ( V_90 = 0 ; V_90 < F_31 ( V_99 ) ; V_90 ++ ) {
V_89 = F_32 ( NULL , V_99 [ V_90 ] ) ;
if ( F_33 ( V_89 ) ) {
F_11 ( & V_88 -> V_7 , L_3 ,
V_99 [ V_90 ] ) ;
V_10 = F_34 ( V_89 ) ;
goto V_100;
}
F_35 ( V_89 ) ;
F_36 ( V_89 ) ;
}
V_3 = F_37 ( & V_88 -> V_7 , sizeof( struct V_101 ) ,
V_102 ) ;
if ( ! V_3 ) {
F_11 ( & V_88 -> V_7 , L_4 ) ;
V_10 = - V_103 ;
goto V_100;
}
F_38 ( & V_88 -> V_7 , V_3 ) ;
V_3 -> V_7 = & V_88 -> V_7 ;
V_3 -> V_9 = F_39 ( & V_88 -> V_7 , L_5 ) ;
if ( F_33 ( V_3 -> V_9 ) ) {
F_11 ( & V_88 -> V_7 , L_6 ) ;
V_10 = F_34 ( V_3 -> V_9 ) ;
goto V_100;
}
V_3 -> V_8 = F_39 ( & V_88 -> V_7 , L_7 ) ;
if ( F_33 ( V_3 -> V_8 ) ) {
F_11 ( & V_88 -> V_7 , L_8 ) ;
V_10 = F_34 ( V_3 -> V_8 ) ;
goto V_104;
}
if ( F_40 ( V_88 -> V_7 . V_105 ,
L_9 ,
V_95 , 2 ) < 0 ) {
F_11 ( & V_88 -> V_7 ,
L_10 ) ;
V_10 = - V_98 ;
goto V_104;
}
V_3 -> V_23 = V_95 [ 1 ] ;
V_92 = F_41 ( V_88 , V_106 , 0 ) ;
if ( ! V_92 ) {
F_11 ( & V_88 -> V_7 , L_11 ) ;
V_10 = - V_98 ;
goto V_107;
}
V_94 = F_42 ( & V_88 -> V_7 , V_92 -> V_108 ,
F_43 ( V_92 ) , V_109 ) ;
if ( ! V_94 ) {
F_11 ( & V_88 -> V_7 , L_12 ) ;
V_10 = - V_18 ;
goto V_107;
}
V_3 -> V_20 = V_92 -> V_108 ;
V_96 = F_44 ( & V_88 -> V_7 , V_92 -> V_108 ,
F_43 ( V_92 ) ) ;
if ( ! V_96 ) {
F_11 ( & V_88 -> V_7 , L_13 ) ;
V_10 = - V_103 ;
goto V_107;
}
V_3 -> V_4 = F_45 ( & V_88 -> V_7 , V_96 ,
& V_110 ) ;
if ( F_33 ( V_3 -> V_4 ) ) {
F_11 ( & V_88 -> V_7 , L_14 ) ;
V_10 = F_34 ( V_3 -> V_4 ) ;
goto V_107;
}
F_7 ( V_3 -> V_4 , true ) ;
V_93 = F_41 ( V_88 , V_106 , 1 ) ;
if ( ! V_93 ) {
F_11 ( & V_88 -> V_7 , L_15 ) ;
V_10 = - V_98 ;
goto V_107;
}
V_94 = F_42 ( & V_88 -> V_7 , V_93 -> V_108 ,
F_43 ( V_93 ) , V_109 ) ;
if ( ! V_94 ) {
F_11 ( & V_88 -> V_7 , L_16 ) ;
V_10 = - V_18 ;
goto V_107;
}
V_97 = F_44 ( & V_88 -> V_7 , V_93 -> V_108 ,
F_43 ( V_93 ) ) ;
if ( ! V_97 ) {
F_11 ( & V_88 -> V_7 , L_17 ) ;
V_10 = - V_103 ;
goto V_107;
}
V_3 -> V_5 = F_45 ( & V_88 -> V_7 , V_97 ,
& V_111 ) ;
if ( F_33 ( V_3 -> V_5 ) ) {
F_11 ( & V_88 -> V_7 , L_18 ) ;
V_10 = F_34 ( V_3 -> V_5 ) ;
goto V_107;
}
F_7 ( V_3 -> V_5 , true ) ;
F_46 ( & V_88 -> V_7 ) ;
if ( ! F_47 ( & V_88 -> V_7 ) ) {
V_10 = F_9 ( & V_88 -> V_7 ) ;
if ( V_10 )
goto V_112;
}
F_48 ( V_88 -> V_7 . V_105 , NULL , V_113 ,
& V_88 -> V_7 ) ;
return 0 ;
V_112:
F_49 ( & V_88 -> V_7 ) ;
V_107:
F_36 ( V_3 -> V_8 ) ;
V_104:
F_36 ( V_3 -> V_9 ) ;
V_3 = 0 ;
V_100:
return V_10 ;
}
static int T_4 F_50 ( struct V_87 * V_88 )
{
if ( ! V_3 )
return - V_98 ;
F_49 ( & V_88 -> V_7 ) ;
if ( ! F_51 ( & V_88 -> V_7 ) )
F_6 ( & V_88 -> V_7 ) ;
F_36 ( V_3 -> V_8 ) ;
F_36 ( V_3 -> V_9 ) ;
V_3 = 0 ;
return 0 ;
}
