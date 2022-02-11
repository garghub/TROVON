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
static int F_3 ( struct V_4 * V_5 )
{
int V_2 , V_11 ;
V_11 = F_4 ( V_5 -> V_12 -> V_13 , 1 ) ;
if ( V_11 )
return V_11 ;
F_5 ( V_14 ) ;
F_6 ( V_5 -> V_12 -> V_15 , 0 ) ;
F_5 ( V_14 ) ;
for ( V_2 = 0 ; V_2 < 9 ; ++ V_2 ) {
F_6 ( V_5 -> V_12 -> V_15 , 1 ) ;
F_5 ( V_16 ) ;
F_6 ( V_5 -> V_12 -> V_15 , 0 ) ;
F_5 ( V_14 ) ;
}
return 0 ;
}
static inline void F_7 ( struct V_4 * V_5 , int V_17 )
{
F_6 ( V_5 -> V_12 -> V_13 , V_17 ) ;
F_5 ( V_18 ) ;
F_6 ( V_5 -> V_12 -> V_15 , 1 ) ;
F_5 ( V_16 ) ;
F_6 ( V_5 -> V_12 -> V_15 , 0 ) ;
F_5 ( V_14 ) ;
}
static int F_8 ( struct V_4 * V_5 )
{
int V_11 ;
V_11 = F_4 ( V_5 -> V_12 -> V_13 , 1 ) ;
if ( V_11 )
return V_11 ;
F_5 ( V_18 ) ;
F_6 ( V_5 -> V_12 -> V_15 , 0 ) ;
F_5 ( V_14 ) ;
F_6 ( V_5 -> V_12 -> V_15 , 1 ) ;
F_5 ( V_16 ) ;
F_6 ( V_5 -> V_12 -> V_13 , 0 ) ;
F_5 ( V_18 ) ;
F_6 ( V_5 -> V_12 -> V_15 , 0 ) ;
F_5 ( V_14 ) ;
F_6 ( V_5 -> V_12 -> V_15 , 1 ) ;
F_5 ( V_16 ) ;
F_6 ( V_5 -> V_12 -> V_13 , 1 ) ;
F_5 ( V_18 ) ;
F_6 ( V_5 -> V_12 -> V_15 , 0 ) ;
F_5 ( V_14 ) ;
return 0 ;
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
int V_11 ;
V_11 = F_11 ( V_5 -> V_12 -> V_13 ) ;
if ( V_11 )
return V_11 ;
F_6 ( V_5 -> V_12 -> V_15 , 1 ) ;
F_5 ( V_16 ) ;
if ( F_12 ( V_5 -> V_12 -> V_13 ) ) {
F_6 ( V_5 -> V_12 -> V_15 , 0 ) ;
F_13 ( V_5 -> V_19 , L_1 ) ;
V_11 = F_3 ( V_5 ) ;
if ( V_11 )
return V_11 ;
return - V_20 ;
}
F_6 ( V_5 -> V_12 -> V_15 , 0 ) ;
F_5 ( V_14 ) ;
return 0 ;
}
static int F_14 ( struct V_4 * V_5 , T_1 V_21 )
{
int V_11 ;
V_11 = F_8 ( V_5 ) ;
if ( V_11 )
return V_11 ;
F_9 ( V_5 , V_21 ) ;
return F_10 ( V_5 ) ;
}
static int F_15 ( struct V_4 * V_5 )
{
int V_22 ;
V_22 = F_14 ( V_5 , V_23 ) ;
if ( V_22 )
return V_22 ;
F_16 ( V_24 ) ;
V_5 -> V_9 = 0 ;
return V_22 ;
}
static int F_17 ( struct V_4 * V_5 )
{
int V_11 ;
V_11 = F_4 ( V_5 -> V_12 -> V_13 , 0 ) ;
if ( V_11 )
return V_11 ;
F_5 ( V_18 ) ;
F_6 ( V_5 -> V_12 -> V_15 , 1 ) ;
F_5 ( V_18 ) ;
F_6 ( V_5 -> V_12 -> V_15 , 0 ) ;
F_5 ( V_18 ) ;
F_6 ( V_5 -> V_12 -> V_13 , 1 ) ;
return F_11 ( V_5 -> V_12 -> V_13 ) ;
}
static int F_18 ( struct V_4 * V_5 )
{
int V_11 ;
V_11 = F_4 ( V_5 -> V_12 -> V_13 , 1 ) ;
if ( V_11 )
return V_11 ;
F_5 ( V_18 ) ;
F_6 ( V_5 -> V_12 -> V_15 , 1 ) ;
F_5 ( V_16 ) ;
F_6 ( V_5 -> V_12 -> V_15 , 0 ) ;
F_5 ( V_14 ) ;
return 0 ;
}
static T_1 F_19 ( struct V_4 * V_5 )
{
int V_2 ;
T_1 V_1 = 0 ;
for ( V_2 = 0 ; V_2 < 8 ; ++ V_2 ) {
V_1 <<= 1 ;
F_6 ( V_5 -> V_12 -> V_15 , 1 ) ;
F_5 ( V_16 ) ;
V_1 |= ! ! F_12 ( V_5 -> V_12 -> V_13 ) ;
F_6 ( V_5 -> V_12 -> V_15 , 0 ) ;
F_5 ( V_14 ) ;
}
return V_1 ;
}
static int F_20 ( struct V_4 * V_5 , T_1 V_25 )
{
int V_11 ;
V_11 = F_14 ( V_5 , V_26 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_4 ( V_5 -> V_12 -> V_13 , 1 ) ;
if ( V_11 )
return V_11 ;
F_5 ( V_18 ) ;
F_9 ( V_5 , V_25 ) ;
V_11 = F_10 ( V_5 ) ;
if ( V_11 )
return V_11 ;
V_5 -> V_9 = V_25 ;
return 0 ;
}
static int F_21 ( struct V_4 * V_5 )
{
int V_22 = 0 ;
T_1 V_25 ;
T_1 V_27 ;
T_1 V_28 = 0 ;
T_1 V_29 [ 2 ] ;
int V_30 = V_31 ;
F_22 ( & V_5 -> V_32 ) ;
if ( F_23 ( V_33 , V_5 -> V_34 + V_30 )
|| ! V_5 -> V_35 ) {
V_22 = F_14 ( V_5 , V_36 ) ;
if ( V_22 )
goto V_37;
V_25 = F_19 ( V_5 ) ;
if ( V_5 -> V_38 ) {
F_17 ( V_5 ) ;
V_28 = F_1 ( F_19 ( V_5 ) ) ;
V_29 [ 0 ] = V_36 ;
V_29 [ 1 ] = V_25 ;
V_5 -> V_39 = ( F_2 ( V_5 , V_29 , 2 )
== V_28 ) ;
}
V_22 = F_18 ( V_5 ) ;
if ( V_22 )
goto V_37;
if ( V_5 -> V_38 && ! V_5 -> V_39 ) {
V_27 = V_5 -> V_9 & 0x07 ;
V_22 = F_15 ( V_5 ) ;
if ( V_22 )
goto V_37;
if ( V_27 ) {
V_22 = F_20 ( V_5 , V_27 ) ;
if ( V_22 ) {
F_13 ( V_5 -> V_19 ,
L_2
L_3 ) ;
goto V_37;
}
}
V_22 = - V_40 ;
goto V_37;
}
V_5 -> V_9 = V_25 ;
V_5 -> V_35 = true ;
V_5 -> V_34 = V_33 ;
}
V_37:
F_24 ( & V_5 -> V_32 ) ;
return V_22 ;
}
static int F_25 ( struct V_4 * V_5 ,
int V_41 ,
int V_42 )
{
int V_22 ;
T_1 V_27 ;
V_22 = F_14 ( V_5 , V_41 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_11 ( V_5 -> V_12 -> V_13 ) ;
if ( V_22 )
return V_22 ;
F_26 ( & V_5 -> V_43 , 0 ) ;
F_27 ( F_28 ( V_5 -> V_12 -> V_13 ) ) ;
if ( F_12 ( V_5 -> V_12 -> V_13 ) == 0 ) {
F_29 ( F_28 ( V_5 -> V_12 -> V_13 ) ) ;
if ( ! F_30 ( & V_5 -> V_43 ) )
F_31 ( & V_5 -> V_44 ) ;
}
V_22 = F_32 ( V_5 -> V_45 ,
( V_5 -> V_46 == V_47 ) ,
F_33 ( V_42 ) ) ;
if ( V_5 -> V_46 != V_47 ) {
V_5 -> V_46 = V_47 ;
return - V_20 ;
} else if ( V_22 == 0 ) {
F_29 ( F_28 ( V_5 -> V_12 -> V_13 ) ) ;
V_22 = F_3 ( V_5 ) ;
if ( V_22 )
return V_22 ;
return - V_48 ;
}
if ( V_5 -> V_38 && ! V_5 -> V_39 ) {
V_27 = V_5 -> V_9 & 0x07 ;
V_22 = F_15 ( V_5 ) ;
if ( V_22 )
return V_22 ;
if ( V_27 ) {
V_22 = F_20 ( V_5 , V_27 ) ;
if ( V_22 ) {
F_13 ( V_5 -> V_19 ,
L_2
L_3 ) ;
return V_22 ;
}
}
return - V_40 ;
}
return 0 ;
}
static int F_34 ( struct V_4 * V_5 )
{
int V_22 = 0 ;
int V_30 = V_31 ;
F_22 ( & V_5 -> V_32 ) ;
if ( F_23 ( V_33 , V_5 -> V_49 + V_30 )
|| ! V_5 -> V_50 ) {
V_5 -> V_46 = V_51 ;
V_22 = F_25 ( V_5 , V_52 , 160 ) ;
if ( V_22 )
goto V_37;
V_5 -> V_46 = V_53 ;
V_22 = F_25 ( V_5 , V_54 , 400 ) ;
if ( V_22 )
goto V_37;
V_5 -> V_50 = true ;
V_5 -> V_49 = V_33 ;
}
V_37:
F_24 ( & V_5 -> V_32 ) ;
return V_22 ;
}
static inline int F_35 ( struct V_4 * V_5 )
{
int V_55 = V_56 [ 0 ] . V_55 ;
int V_57 = ( V_5 -> V_9 & V_58 ) ? 40 : 10 ;
int V_2 ;
for ( V_2 = F_36 ( V_56 ) - 1 ; V_2 > 0 ; V_2 -- )
if ( V_5 -> V_59 > V_56 [ V_2 - 1 ] . V_60 ) {
V_55 = ( V_5 -> V_59 - V_56 [ V_2 - 1 ] . V_60 )
* ( V_56 [ V_2 ] . V_55 - V_56 [ V_2 - 1 ] . V_55 )
/ ( V_56 [ V_2 ] . V_60 - V_56 [ V_2 - 1 ] . V_60 )
+ V_56 [ V_2 - 1 ] . V_55 ;
break;
}
return V_5 -> V_61 * V_57 + V_55 ;
}
static inline int F_37 ( struct V_4 * V_5 )
{
int V_62 ;
int V_63 = F_35 ( V_5 ) ;
int V_64 , V_65 ;
int V_66 ;
const int V_67 = - 4 ;
if ( V_5 -> V_9 & V_58 ) {
V_64 = 648000 ;
V_65 = - 7200 ;
V_66 = 1280 ;
} else {
V_64 = 40500 ;
V_65 = - 28 ;
V_66 = 80 ;
}
V_62 = V_67 * 1000
+ V_64 * V_5 -> V_68 / 1000
+ ( V_5 -> V_68 * V_5 -> V_68 * V_65 ) / 10000 ;
return ( V_63 - 25000 ) * ( 10000 + V_66 * V_5 -> V_68 )
/ 1000000 + V_62 ;
}
static T_2 F_38 ( struct V_69 * V_19 ,
struct V_70 * V_71 ,
char * V_72 )
{
int V_22 ;
struct V_4 * V_5 = F_39 ( V_19 ) ;
T_1 V_73 = F_40 ( V_71 ) -> V_74 ;
V_22 = F_21 ( V_5 ) ;
return V_22 ? V_22 : sprintf ( V_72 , L_4 , ! ! ( V_5 -> V_9 & V_73 ) ) ;
}
static T_2 F_41 ( struct V_69 * V_19 ,
struct V_70 * V_71 ,
const char * V_72 , T_3 V_75 )
{
int V_22 ;
struct V_4 * V_5 = F_39 ( V_19 ) ;
long V_6 ;
T_1 V_25 ;
if ( F_42 ( V_72 , 10 , & V_6 ) )
return - V_76 ;
F_22 ( & V_5 -> V_32 ) ;
V_25 = V_5 -> V_9 & 0x07 ;
if ( ! ! V_6 )
V_25 |= V_77 ;
else
V_25 &= ~ V_77 ;
V_22 = F_20 ( V_5 , V_25 ) ;
F_24 ( & V_5 -> V_32 ) ;
return V_22 ? V_22 : V_75 ;
}
static T_2 F_43 ( struct V_69 * V_19 ,
struct V_70 * V_71 ,
char * V_72 )
{
int V_22 ;
struct V_4 * V_5 = F_39 ( V_19 ) ;
V_22 = F_34 ( V_5 ) ;
return V_22 ? V_22 : sprintf ( V_72 , L_4 ,
F_35 ( V_5 ) ) ;
}
static T_2 F_44 ( struct V_69 * V_19 ,
struct V_70 * V_71 ,
char * V_72 )
{
int V_22 ;
struct V_4 * V_5 = F_39 ( V_19 ) ;
V_22 = F_34 ( V_5 ) ;
return V_22 ? V_22 : sprintf ( V_72 , L_4 , F_37 ( V_5 ) ) ;
}
static T_2 F_45 ( struct V_69 * V_19 ,
struct V_70 * V_71 ,
char * V_72 )
{
struct V_78 * V_79 = F_46 ( V_19 ) ;
return sprintf ( V_72 , L_5 , V_79 -> V_80 ) ;
}
static T_4 F_47 ( int V_81 , void * V_82 )
{
struct V_4 * V_5 = V_82 ;
F_29 ( V_81 ) ;
F_48 ( & V_5 -> V_43 ) ;
if ( V_5 -> V_46 != V_47 )
F_31 ( & V_5 -> V_44 ) ;
return V_83 ;
}
static void F_49 ( struct V_84 * V_85 )
{
T_5 V_17 = 0 ;
T_1 V_28 = 0 ;
T_1 V_29 [ 3 ] ;
struct V_4 * V_5
= F_50 ( V_85 , struct V_4 ,
V_44 ) ;
if ( F_12 ( V_5 -> V_12 -> V_13 ) ) {
F_26 ( & V_5 -> V_43 , 0 ) ;
F_27 ( F_28 ( V_5 -> V_12 -> V_13 ) ) ;
if ( F_12 ( V_5 -> V_12 -> V_13 )
|| F_30 ( & V_5 -> V_43 ) )
return;
}
V_17 = F_19 ( V_5 ) ;
V_17 <<= 8 ;
if ( F_17 ( V_5 ) )
goto V_86;
V_17 |= F_19 ( V_5 ) ;
if ( V_5 -> V_38 ) {
if ( F_17 ( V_5 ) )
goto V_86;
V_28 = F_1 ( F_19 ( V_5 ) ) ;
V_29 [ 0 ] = ( V_5 -> V_46 == V_53 ) ?
V_54 : V_52 ;
V_29 [ 1 ] = ( T_1 ) ( V_17 >> 8 ) ;
V_29 [ 2 ] = ( T_1 ) V_17 ;
V_5 -> V_39
= ( F_2 ( V_5 , V_29 , 3 ) == V_28 ) ;
}
if ( F_18 ( V_5 ) )
goto V_86;
switch ( V_5 -> V_46 ) {
case V_53 :
V_5 -> V_61 = V_17 ;
break;
case V_51 :
V_5 -> V_68 = V_17 ;
break;
default:
break;
}
V_5 -> V_46 = V_47 ;
V_86:
F_51 ( & V_5 -> V_45 ) ;
}
static void F_52 ( struct V_84 * V_85 )
{
struct V_4 * V_5
= F_50 ( V_85 , struct V_4 ,
V_87 ) ;
V_5 -> V_59 = F_53 ( V_5 -> V_88 ) ;
}
static int F_54 ( struct V_89 * V_90 ,
unsigned long V_91 ,
void * V_92 )
{
struct V_4 * V_5 = F_50 ( V_90 , struct V_4 , V_90 ) ;
if ( V_91 == V_93 )
V_5 -> V_94 = false ;
F_31 ( & V_5 -> V_87 ) ;
return V_95 ;
}
static int F_55 ( struct V_78 * V_79 )
{
int V_22 ;
struct V_4 * V_5 ;
T_1 V_25 = 0 ;
V_5 = F_56 ( & V_79 -> V_19 , sizeof( * V_5 ) , V_96 ) ;
if ( ! V_5 )
return - V_97 ;
F_57 ( & V_5 -> V_44 , F_49 ) ;
F_57 ( & V_5 -> V_87 , F_52 ) ;
F_58 ( V_79 , V_5 ) ;
F_59 ( & V_5 -> V_32 ) ;
V_5 -> V_19 = & V_79 -> V_19 ;
F_60 ( & V_5 -> V_45 ) ;
if ( F_61 ( & V_79 -> V_19 ) == NULL ) {
F_13 ( & V_79 -> V_19 , L_6 ) ;
return - V_76 ;
}
V_5 -> V_12 = F_61 ( & V_79 -> V_19 ) ;
V_5 -> V_59 = V_5 -> V_12 -> V_98 * 1000 ;
if ( V_5 -> V_12 -> V_99 )
V_5 -> V_38 = true ;
if ( V_5 -> V_12 -> V_100 )
V_25 |= V_101 ;
if ( V_5 -> V_12 -> V_102 )
V_25 |= V_58 ;
V_5 -> V_88 = F_62 ( V_5 -> V_19 , L_7 ) ;
if ( ! F_63 ( V_5 -> V_88 ) ) {
int V_103 ;
V_103 = F_53 ( V_5 -> V_88 ) ;
if ( V_103 )
V_5 -> V_59 = V_103 ;
V_22 = F_64 ( V_5 -> V_88 ) ;
if ( V_22 != 0 ) {
F_13 ( & V_79 -> V_19 ,
L_8 , V_22 ) ;
return V_22 ;
}
V_5 -> V_90 . V_104 = & F_54 ;
V_22 = F_65 ( V_5 -> V_88 , & V_5 -> V_90 ) ;
if ( V_22 ) {
F_13 ( & V_79 -> V_19 ,
L_9 ) ;
F_66 ( V_5 -> V_88 ) ;
return V_22 ;
}
}
V_22 = F_67 ( & V_79 -> V_19 , V_5 -> V_12 -> V_15 ,
V_105 , L_10 ) ;
if ( V_22 ) {
F_13 ( & V_79 -> V_19 , L_11 ) ;
goto V_106;
}
V_22 = F_68 ( & V_79 -> V_19 , V_5 -> V_12 -> V_13 ,
L_12 ) ;
if ( V_22 ) {
F_13 ( & V_79 -> V_19 , L_13 ) ;
goto V_106;
}
V_22 = F_69 ( & V_79 -> V_19 , F_28 ( V_5 -> V_12 -> V_13 ) ,
F_47 ,
V_107 ,
L_14 ,
V_5 ) ;
if ( V_22 ) {
F_13 ( & V_79 -> V_19 , L_15 ) ;
goto V_106;
}
F_29 ( F_28 ( V_5 -> V_12 -> V_13 ) ) ;
V_22 = F_3 ( V_5 ) ;
if ( V_22 )
goto V_106;
V_22 = F_15 ( V_5 ) ;
if ( V_22 )
goto V_106;
if ( V_25 ) {
V_22 = F_20 ( V_5 , V_25 ) ;
if ( V_22 )
goto V_106;
}
V_22 = F_70 ( & V_79 -> V_19 . V_108 , & V_109 ) ;
if ( V_22 ) {
F_13 ( & V_79 -> V_19 , L_16 ) ;
goto V_106;
}
V_5 -> V_110 = F_71 ( V_5 -> V_19 ) ;
if ( F_63 ( V_5 -> V_110 ) ) {
V_22 = F_72 ( V_5 -> V_110 ) ;
goto V_111;
}
return 0 ;
V_111:
F_73 ( & V_79 -> V_19 . V_108 , & V_109 ) ;
V_106:
if ( ! F_63 ( V_5 -> V_88 ) ) {
F_74 ( V_5 -> V_88 , & V_5 -> V_90 ) ;
F_66 ( V_5 -> V_88 ) ;
}
return V_22 ;
}
static int F_75 ( struct V_78 * V_79 )
{
struct V_4 * V_5 = F_76 ( V_79 ) ;
F_22 ( & V_5 -> V_32 ) ;
if ( F_15 ( V_5 ) ) {
F_24 ( & V_5 -> V_32 ) ;
return - V_112 ;
}
F_77 ( V_5 -> V_110 ) ;
F_73 ( & V_79 -> V_19 . V_108 , & V_109 ) ;
if ( ! F_63 ( V_5 -> V_88 ) ) {
F_74 ( V_5 -> V_88 , & V_5 -> V_90 ) ;
F_66 ( V_5 -> V_88 ) ;
}
F_24 ( & V_5 -> V_32 ) ;
return 0 ;
}
