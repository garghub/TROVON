static T_1 F_1 ( T_1 V_1 )
{
T_1 V_2 , V_3 ;
for ( V_3 = 0 , V_2 = 0 ; V_2 < 8 ; V_2 ++ )
V_3 |= ( ! ! ( V_1 & ( 1 << V_2 ) ) ) << ( 7 - V_2 ) ;
return V_3 ;
}
static T_1 F_2 ( struct V_4 * V_5 ,
const T_1 * V_6 ,
int V_7 )
{
T_1 V_8 = F_1 ( V_5 -> V_9 & 0x0F ) ;
while ( V_7 -- ) {
V_8 = V_10 [ * V_6 ^ V_8 ] ;
V_6 ++ ;
}
return V_8 ;
}
static void F_3 ( struct V_4 * V_5 )
{
int V_2 ;
F_4 ( V_5 -> V_11 -> V_12 , 1 ) ;
F_5 ( V_13 ) ;
F_6 ( V_5 -> V_11 -> V_14 , 0 ) ;
F_5 ( V_13 ) ;
for ( V_2 = 0 ; V_2 < 9 ; ++ V_2 ) {
F_6 ( V_5 -> V_11 -> V_14 , 1 ) ;
F_5 ( V_15 ) ;
F_6 ( V_5 -> V_11 -> V_14 , 0 ) ;
F_5 ( V_13 ) ;
}
}
static inline void F_7 ( struct V_4 * V_5 , int V_16 )
{
F_6 ( V_5 -> V_11 -> V_12 , V_16 ) ;
F_5 ( V_17 ) ;
F_6 ( V_5 -> V_11 -> V_14 , 1 ) ;
F_5 ( V_15 ) ;
F_6 ( V_5 -> V_11 -> V_14 , 0 ) ;
F_5 ( V_13 ) ;
}
static void F_8 ( struct V_4 * V_5 )
{
F_4 ( V_5 -> V_11 -> V_12 , 1 ) ;
F_5 ( V_17 ) ;
F_6 ( V_5 -> V_11 -> V_14 , 0 ) ;
F_5 ( V_13 ) ;
F_6 ( V_5 -> V_11 -> V_14 , 1 ) ;
F_5 ( V_15 ) ;
F_6 ( V_5 -> V_11 -> V_12 , 0 ) ;
F_5 ( V_17 ) ;
F_6 ( V_5 -> V_11 -> V_14 , 0 ) ;
F_5 ( V_13 ) ;
F_6 ( V_5 -> V_11 -> V_14 , 1 ) ;
F_5 ( V_15 ) ;
F_6 ( V_5 -> V_11 -> V_12 , 1 ) ;
F_5 ( V_17 ) ;
F_6 ( V_5 -> V_11 -> V_14 , 0 ) ;
F_5 ( V_13 ) ;
}
static void F_9 ( struct V_4 * V_5 , T_1 V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < 8 ; V_2 ++ ) {
F_7 ( V_5 , ! ! ( V_1 & 0x80 ) ) ;
V_1 <<= 1 ;
}
}
static int F_10 ( struct V_4 * V_5 )
{
F_11 ( V_5 -> V_11 -> V_12 ) ;
F_6 ( V_5 -> V_11 -> V_14 , 1 ) ;
F_5 ( V_15 ) ;
if ( F_12 ( V_5 -> V_11 -> V_12 ) ) {
F_6 ( V_5 -> V_11 -> V_14 , 0 ) ;
F_13 ( V_5 -> V_18 , L_1 ) ;
F_3 ( V_5 ) ;
return - V_19 ;
}
F_6 ( V_5 -> V_11 -> V_14 , 0 ) ;
F_5 ( V_13 ) ;
return 0 ;
}
static int F_14 ( struct V_4 * V_5 , T_1 V_20 )
{
int V_21 = 0 ;
F_8 ( V_5 ) ;
F_9 ( V_5 , V_20 ) ;
V_21 = F_10 ( V_5 ) ;
return V_21 ;
}
static int F_15 ( struct V_4 * V_5 )
{
int V_21 ;
V_21 = F_14 ( V_5 , V_22 ) ;
if ( V_21 )
return V_21 ;
F_16 ( V_23 ) ;
V_5 -> V_9 = 0 ;
return V_21 ;
}
static void F_17 ( struct V_4 * V_5 )
{
F_4 ( V_5 -> V_11 -> V_12 , 0 ) ;
F_5 ( V_17 ) ;
F_6 ( V_5 -> V_11 -> V_14 , 1 ) ;
F_5 ( V_17 ) ;
F_6 ( V_5 -> V_11 -> V_14 , 0 ) ;
F_5 ( V_17 ) ;
F_6 ( V_5 -> V_11 -> V_12 , 1 ) ;
F_11 ( V_5 -> V_11 -> V_12 ) ;
}
static void F_18 ( struct V_4 * V_5 )
{
F_4 ( V_5 -> V_11 -> V_12 , 1 ) ;
F_5 ( V_17 ) ;
F_6 ( V_5 -> V_11 -> V_14 , 1 ) ;
F_5 ( V_15 ) ;
F_6 ( V_5 -> V_11 -> V_14 , 0 ) ;
F_5 ( V_13 ) ;
}
static T_1 F_19 ( struct V_4 * V_5 )
{
int V_2 ;
T_1 V_1 = 0 ;
for ( V_2 = 0 ; V_2 < 8 ; ++ V_2 ) {
V_1 <<= 1 ;
F_6 ( V_5 -> V_11 -> V_14 , 1 ) ;
F_5 ( V_15 ) ;
V_1 |= ! ! F_12 ( V_5 -> V_11 -> V_12 ) ;
F_6 ( V_5 -> V_11 -> V_14 , 0 ) ;
F_5 ( V_13 ) ;
}
return V_1 ;
}
static int F_20 ( struct V_4 * V_5 , T_1 V_24 )
{
int V_21 ;
V_21 = F_14 ( V_5 , V_25 ) ;
if ( V_21 )
return V_21 ;
F_4 ( V_5 -> V_11 -> V_12 , 1 ) ;
F_5 ( V_17 ) ;
F_9 ( V_5 , V_24 ) ;
V_21 = F_10 ( V_5 ) ;
if ( V_21 )
return V_21 ;
V_5 -> V_9 = V_24 ;
return 0 ;
}
static int F_21 ( struct V_4 * V_5 )
{
int V_21 = 0 ;
T_1 V_24 ;
T_1 V_26 ;
T_1 V_27 = 0 ;
T_1 V_28 [ 2 ] ;
int V_29 = V_30 ;
F_22 ( & V_5 -> V_31 ) ;
if ( F_23 ( V_32 , V_5 -> V_33 + V_29 )
|| ! V_5 -> V_34 ) {
V_21 = F_14 ( V_5 , V_35 ) ;
if ( V_21 )
goto V_36;
V_24 = F_19 ( V_5 ) ;
if ( V_5 -> V_37 ) {
F_17 ( V_5 ) ;
V_27 = F_1 ( F_19 ( V_5 ) ) ;
V_28 [ 0 ] = V_35 ;
V_28 [ 1 ] = V_24 ;
V_5 -> V_38 = ( F_2 ( V_5 , V_28 , 2 )
== V_27 ) ;
}
F_18 ( V_5 ) ;
if ( V_5 -> V_37 && ! V_5 -> V_38 ) {
V_26 = V_5 -> V_9 & 0x07 ;
V_21 = F_15 ( V_5 ) ;
if ( V_21 )
goto V_36;
if ( V_26 ) {
V_21 = F_20 ( V_5 , V_26 ) ;
if ( V_21 ) {
F_13 ( V_5 -> V_18 ,
L_2
L_3 ) ;
goto V_36;
}
}
V_21 = - V_39 ;
goto V_36;
}
V_5 -> V_9 = V_24 ;
V_5 -> V_34 = true ;
V_5 -> V_33 = V_32 ;
}
V_36:
F_24 ( & V_5 -> V_31 ) ;
return V_21 ;
}
static int F_25 ( struct V_4 * V_5 ,
int V_40 ,
int V_41 )
{
int V_21 ;
T_1 V_26 ;
V_21 = F_14 ( V_5 , V_40 ) ;
if ( V_21 )
return V_21 ;
F_11 ( V_5 -> V_11 -> V_12 ) ;
F_26 ( & V_5 -> V_42 , 0 ) ;
F_27 ( F_28 ( V_5 -> V_11 -> V_12 ) ) ;
if ( F_12 ( V_5 -> V_11 -> V_12 ) == 0 ) {
F_29 ( F_28 ( V_5 -> V_11 -> V_12 ) ) ;
if ( ! F_30 ( & V_5 -> V_42 ) )
F_31 ( & V_5 -> V_43 ) ;
}
V_21 = F_32 ( V_5 -> V_44 ,
( V_5 -> V_45 == V_46 ) ,
F_33 ( V_41 ) ) ;
if ( V_21 == 0 ) {
F_29 ( F_28 ( V_5 -> V_11 -> V_12 ) ) ;
F_3 ( V_5 ) ;
return - V_47 ;
}
if ( V_5 -> V_37 && ! V_5 -> V_38 ) {
V_26 = V_5 -> V_9 & 0x07 ;
V_21 = F_15 ( V_5 ) ;
if ( V_21 )
return V_21 ;
if ( V_26 ) {
V_21 = F_20 ( V_5 , V_26 ) ;
if ( V_21 ) {
F_13 ( V_5 -> V_18 ,
L_2
L_3 ) ;
return V_21 ;
}
}
return - V_39 ;
}
return 0 ;
}
static int F_34 ( struct V_4 * V_5 )
{
int V_21 = 0 ;
int V_29 = V_30 ;
F_22 ( & V_5 -> V_31 ) ;
if ( F_23 ( V_32 , V_5 -> V_48 + V_29 )
|| ! V_5 -> V_49 ) {
V_5 -> V_45 = V_50 ;
V_21 = F_25 ( V_5 , V_51 , 160 ) ;
if ( V_21 )
goto V_36;
V_5 -> V_45 = V_52 ;
V_21 = F_25 ( V_5 , V_53 , 400 ) ;
if ( V_21 )
goto V_36;
V_5 -> V_49 = true ;
V_5 -> V_48 = V_32 ;
}
V_36:
F_24 ( & V_5 -> V_31 ) ;
return V_21 ;
}
static inline int F_35 ( struct V_4 * V_5 )
{
int V_54 = V_55 [ 0 ] . V_54 ;
int V_56 = ( V_5 -> V_9 & V_57 ) ? 40 : 10 ;
int V_2 ;
for ( V_2 = F_36 ( V_55 ) - 1 ; V_2 > 0 ; V_2 -- )
if ( V_5 -> V_58 > V_55 [ V_2 - 1 ] . V_59 ) {
V_54 = ( V_5 -> V_58 - V_55 [ V_2 - 1 ] . V_59 )
* ( V_55 [ V_2 ] . V_54 - V_55 [ V_2 - 1 ] . V_54 )
/ ( V_55 [ V_2 ] . V_59 - V_55 [ V_2 - 1 ] . V_59 )
+ V_55 [ V_2 - 1 ] . V_54 ;
break;
}
return V_5 -> V_60 * V_56 + V_54 ;
}
static inline int F_37 ( struct V_4 * V_5 )
{
int V_61 ;
int V_62 = F_35 ( V_5 ) ;
int V_63 , V_64 ;
int V_65 ;
const int V_66 = - 4 ;
if ( V_5 -> V_9 & V_57 ) {
V_63 = 648000 ;
V_64 = - 7200 ;
V_65 = 1280 ;
} else {
V_63 = 40500 ;
V_64 = - 28 ;
V_65 = 80 ;
}
V_61 = V_66 * 1000
+ V_63 * V_5 -> V_67 / 1000
+ ( V_5 -> V_67 * V_5 -> V_67 * V_64 ) / 10000 ;
return ( V_62 - 25000 ) * ( 10000 + V_65 * V_5 -> V_67 )
/ 1000000 + V_61 ;
}
static T_2 F_38 ( struct V_68 * V_18 ,
struct V_69 * V_70 ,
char * V_71 )
{
int V_21 ;
struct V_4 * V_5 = F_39 ( V_18 ) ;
T_1 V_72 = F_40 ( V_70 ) -> V_73 ;
V_21 = F_21 ( V_5 ) ;
return V_21 ? V_21 : sprintf ( V_71 , L_4 , ! ! ( V_5 -> V_9 & V_72 ) ) ;
}
static T_2 F_41 ( struct V_68 * V_18 ,
struct V_69 * V_70 ,
const char * V_71 , T_3 V_74 )
{
int V_21 ;
struct V_4 * V_5 = F_39 ( V_18 ) ;
long V_6 ;
T_1 V_24 ;
if ( F_42 ( V_71 , 10 , & V_6 ) )
return - V_75 ;
F_22 ( & V_5 -> V_31 ) ;
V_24 = V_5 -> V_9 & 0x07 ;
if ( ! ! V_6 )
V_24 |= V_76 ;
else
V_24 &= ~ V_76 ;
V_21 = F_20 ( V_5 , V_24 ) ;
F_24 ( & V_5 -> V_31 ) ;
return V_21 ? V_21 : V_74 ;
}
static T_2 F_43 ( struct V_68 * V_18 ,
struct V_69 * V_70 ,
char * V_71 )
{
int V_21 ;
struct V_4 * V_5 = F_39 ( V_18 ) ;
V_21 = F_34 ( V_5 ) ;
return V_21 ? V_21 : sprintf ( V_71 , L_4 ,
F_35 ( V_5 ) ) ;
}
static T_2 F_44 ( struct V_68 * V_18 ,
struct V_69 * V_70 ,
char * V_71 )
{
int V_21 ;
struct V_4 * V_5 = F_39 ( V_18 ) ;
V_21 = F_34 ( V_5 ) ;
return V_21 ? V_21 : sprintf ( V_71 , L_4 , F_37 ( V_5 ) ) ;
}
static T_2 F_45 ( struct V_68 * V_18 ,
struct V_69 * V_70 ,
char * V_71 )
{
struct V_77 * V_78 = F_46 ( V_18 ) ;
return sprintf ( V_71 , L_5 , V_78 -> V_79 ) ;
}
static T_4 F_47 ( int V_80 , void * V_81 )
{
struct V_4 * V_5 = V_81 ;
F_29 ( V_80 ) ;
F_48 ( & V_5 -> V_42 ) ;
if ( V_5 -> V_45 != V_46 )
F_31 ( & V_5 -> V_43 ) ;
return V_82 ;
}
static void F_49 ( struct V_83 * V_84 )
{
T_5 V_16 = 0 ;
T_1 V_27 = 0 ;
T_1 V_28 [ 3 ] ;
struct V_4 * V_5
= F_50 ( V_84 , struct V_4 ,
V_43 ) ;
if ( F_12 ( V_5 -> V_11 -> V_12 ) ) {
F_26 ( & V_5 -> V_42 , 0 ) ;
F_27 ( F_28 ( V_5 -> V_11 -> V_12 ) ) ;
if ( F_12 ( V_5 -> V_11 -> V_12 )
|| F_30 ( & V_5 -> V_42 ) )
return;
}
V_16 = F_19 ( V_5 ) ;
V_16 <<= 8 ;
F_17 ( V_5 ) ;
V_16 |= F_19 ( V_5 ) ;
if ( V_5 -> V_37 ) {
F_17 ( V_5 ) ;
V_27 = F_1 ( F_19 ( V_5 ) ) ;
V_28 [ 0 ] = ( V_5 -> V_45 == V_52 ) ?
V_53 : V_51 ;
V_28 [ 1 ] = ( T_1 ) ( V_16 >> 8 ) ;
V_28 [ 2 ] = ( T_1 ) V_16 ;
V_5 -> V_38
= ( F_2 ( V_5 , V_28 , 3 ) == V_27 ) ;
}
F_18 ( V_5 ) ;
switch ( V_5 -> V_45 ) {
case V_52 :
V_5 -> V_60 = V_16 ;
break;
case V_50 :
V_5 -> V_67 = V_16 ;
break;
default:
break;
}
V_5 -> V_45 = V_46 ;
F_51 ( & V_5 -> V_44 ) ;
}
static void F_52 ( struct V_83 * V_84 )
{
struct V_4 * V_5
= F_50 ( V_84 , struct V_4 ,
V_85 ) ;
V_5 -> V_58 = F_53 ( V_5 -> V_86 ) ;
}
static int F_54 ( struct V_87 * V_88 ,
unsigned long V_89 ,
void * V_90 )
{
struct V_4 * V_5 = F_50 ( V_88 , struct V_4 , V_88 ) ;
if ( V_89 == V_91 )
V_5 -> V_92 = false ;
F_31 ( & V_5 -> V_85 ) ;
return V_93 ;
}
static int T_6 F_55 ( struct V_77 * V_78 )
{
int V_21 ;
struct V_4 * V_5 = F_56 ( sizeof( * V_5 ) , V_94 ) ;
T_1 V_24 = 0 ;
if ( ! V_5 ) {
V_21 = - V_95 ;
F_13 ( & V_78 -> V_18 , L_6 ) ;
goto V_36;
}
F_57 ( & V_5 -> V_43 , F_49 ) ;
F_57 ( & V_5 -> V_85 , F_52 ) ;
F_58 ( V_78 , V_5 ) ;
F_59 ( & V_5 -> V_31 ) ;
V_5 -> V_18 = & V_78 -> V_18 ;
F_60 ( & V_5 -> V_44 ) ;
if ( V_78 -> V_18 . V_96 == NULL ) {
V_21 = - V_75 ;
F_13 ( & V_78 -> V_18 , L_7 ) ;
goto V_97;
}
V_5 -> V_11 = V_78 -> V_18 . V_96 ;
V_5 -> V_58 = V_5 -> V_11 -> V_98 * 1000 ;
if ( V_5 -> V_11 -> V_99 )
V_5 -> V_37 = true ;
if ( V_5 -> V_11 -> V_100 )
V_24 |= V_101 ;
if ( V_5 -> V_11 -> V_102 )
V_24 |= V_57 ;
V_5 -> V_86 = F_61 ( V_5 -> V_18 , L_8 ) ;
if ( ! F_62 ( V_5 -> V_86 ) ) {
int V_103 ;
V_103 = F_53 ( V_5 -> V_86 ) ;
if ( V_103 )
V_5 -> V_58 = V_103 ;
F_63 ( V_5 -> V_86 ) ;
V_5 -> V_88 . V_104 = & F_54 ;
V_21 = F_64 ( V_5 -> V_86 , & V_5 -> V_88 ) ;
if ( V_21 ) {
F_13 ( & V_78 -> V_18 ,
L_9 ) ;
F_65 ( V_5 -> V_86 ) ;
F_66 ( V_5 -> V_86 ) ;
goto V_97;
}
}
V_21 = F_67 ( V_5 -> V_11 -> V_14 , L_10 ) ;
if ( V_21 ) {
F_13 ( & V_78 -> V_18 , L_11 ) ;
goto V_105;
}
F_4 ( V_5 -> V_11 -> V_14 , 0 ) ;
V_21 = F_67 ( V_5 -> V_11 -> V_12 , L_12 ) ;
if ( V_21 ) {
F_13 ( & V_78 -> V_18 , L_11 ) ;
goto V_106;
}
V_21 = F_68 ( F_28 ( V_5 -> V_11 -> V_12 ) ,
F_47 ,
V_107 ,
L_13 ,
V_5 ) ;
if ( V_21 ) {
F_13 ( & V_78 -> V_18 , L_14 ) ;
goto V_108;
}
F_29 ( F_28 ( V_5 -> V_11 -> V_12 ) ) ;
F_3 ( V_5 ) ;
V_21 = F_15 ( V_5 ) ;
if ( V_21 )
goto V_109;
if ( V_24 ) {
V_21 = F_20 ( V_5 , V_24 ) ;
if ( V_21 )
goto V_109;
}
V_21 = F_69 ( & V_78 -> V_18 . V_110 , & V_111 ) ;
if ( V_21 ) {
F_13 ( & V_78 -> V_18 , L_15 ) ;
goto V_109;
}
V_5 -> V_112 = F_70 ( V_5 -> V_18 ) ;
if ( F_62 ( V_5 -> V_112 ) ) {
V_21 = F_71 ( V_5 -> V_112 ) ;
goto V_113;
}
return 0 ;
V_113:
F_72 ( & V_78 -> V_18 . V_110 , & V_111 ) ;
V_109:
F_73 ( F_28 ( V_5 -> V_11 -> V_12 ) , V_5 ) ;
V_108:
F_74 ( V_5 -> V_11 -> V_12 ) ;
V_106:
F_74 ( V_5 -> V_11 -> V_14 ) ;
V_105:
if ( ! F_62 ( V_5 -> V_86 ) ) {
F_75 ( V_5 -> V_86 , & V_5 -> V_88 ) ;
F_65 ( V_5 -> V_86 ) ;
F_66 ( V_5 -> V_86 ) ;
}
V_97:
F_76 ( V_5 ) ;
V_36:
return V_21 ;
}
static int T_7 F_77 ( struct V_77 * V_78 )
{
struct V_4 * V_5 = F_78 ( V_78 ) ;
F_22 ( & V_5 -> V_31 ) ;
if ( F_15 ( V_5 ) ) {
F_24 ( & V_5 -> V_31 ) ;
return - V_114 ;
}
F_79 ( V_5 -> V_112 ) ;
F_72 ( & V_78 -> V_18 . V_110 , & V_111 ) ;
if ( ! F_62 ( V_5 -> V_86 ) ) {
F_75 ( V_5 -> V_86 , & V_5 -> V_88 ) ;
F_65 ( V_5 -> V_86 ) ;
F_66 ( V_5 -> V_86 ) ;
}
F_73 ( F_28 ( V_5 -> V_11 -> V_12 ) , V_5 ) ;
F_74 ( V_5 -> V_11 -> V_12 ) ;
F_74 ( V_5 -> V_11 -> V_14 ) ;
F_24 ( & V_5 -> V_31 ) ;
F_76 ( V_5 ) ;
return 0 ;
}
static int T_8 F_80 ( void )
{
int V_21 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < F_36 ( V_115 ) ; V_2 ++ ) {
V_21 = F_81 ( & V_115 [ V_2 ] ) ;
if ( V_21 )
goto V_116;
}
return 0 ;
V_116:
while ( -- V_2 >= 0 )
F_82 ( & V_115 [ V_2 ] ) ;
return V_21 ;
}
static void T_9 F_83 ( void )
{
int V_2 ;
for ( V_2 = F_36 ( V_115 ) - 1 ; V_2 >= 0 ; V_2 -- )
F_82 ( & V_115 [ V_2 ] ) ;
}
