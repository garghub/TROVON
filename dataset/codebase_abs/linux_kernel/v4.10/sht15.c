static T_1 F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 ,
int V_4 )
{
T_1 V_5 = F_2 ( V_2 -> V_6 & 0x0F ) ;
while ( V_4 -- ) {
V_5 = V_7 [ * V_3 ^ V_5 ] ;
V_3 ++ ;
}
return V_5 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_8 , V_9 ;
V_9 = F_4 ( V_2 -> V_10 -> V_11 , 1 ) ;
if ( V_9 )
return V_9 ;
F_5 ( V_12 ) ;
F_6 ( V_2 -> V_10 -> V_13 , 0 ) ;
F_5 ( V_12 ) ;
for ( V_8 = 0 ; V_8 < 9 ; ++ V_8 ) {
F_6 ( V_2 -> V_10 -> V_13 , 1 ) ;
F_5 ( V_14 ) ;
F_6 ( V_2 -> V_10 -> V_13 , 0 ) ;
F_5 ( V_12 ) ;
}
return 0 ;
}
static inline void F_7 ( struct V_1 * V_2 , int V_15 )
{
F_6 ( V_2 -> V_10 -> V_11 , V_15 ) ;
F_5 ( V_16 ) ;
F_6 ( V_2 -> V_10 -> V_13 , 1 ) ;
F_5 ( V_14 ) ;
F_6 ( V_2 -> V_10 -> V_13 , 0 ) ;
F_5 ( V_12 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_9 ;
V_9 = F_4 ( V_2 -> V_10 -> V_11 , 1 ) ;
if ( V_9 )
return V_9 ;
F_5 ( V_16 ) ;
F_6 ( V_2 -> V_10 -> V_13 , 0 ) ;
F_5 ( V_12 ) ;
F_6 ( V_2 -> V_10 -> V_13 , 1 ) ;
F_5 ( V_14 ) ;
F_6 ( V_2 -> V_10 -> V_11 , 0 ) ;
F_5 ( V_16 ) ;
F_6 ( V_2 -> V_10 -> V_13 , 0 ) ;
F_5 ( V_12 ) ;
F_6 ( V_2 -> V_10 -> V_13 , 1 ) ;
F_5 ( V_14 ) ;
F_6 ( V_2 -> V_10 -> V_11 , 1 ) ;
F_5 ( V_16 ) ;
F_6 ( V_2 -> V_10 -> V_13 , 0 ) ;
F_5 ( V_12 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_17 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ ) {
F_7 ( V_2 , ! ! ( V_17 & 0x80 ) ) ;
V_17 <<= 1 ;
}
}
static int F_10 ( struct V_1 * V_2 )
{
int V_9 ;
V_9 = F_11 ( V_2 -> V_10 -> V_11 ) ;
if ( V_9 )
return V_9 ;
F_6 ( V_2 -> V_10 -> V_13 , 1 ) ;
F_5 ( V_14 ) ;
if ( F_12 ( V_2 -> V_10 -> V_11 ) ) {
F_6 ( V_2 -> V_10 -> V_13 , 0 ) ;
F_13 ( V_2 -> V_18 , L_1 ) ;
V_9 = F_3 ( V_2 ) ;
if ( V_9 )
return V_9 ;
return - V_19 ;
}
F_6 ( V_2 -> V_10 -> V_13 , 0 ) ;
F_5 ( V_12 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_20 )
{
int V_9 ;
V_9 = F_8 ( V_2 ) ;
if ( V_9 )
return V_9 ;
F_9 ( V_2 , V_20 ) ;
return F_10 ( V_2 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_21 ;
V_21 = F_14 ( V_2 , V_22 ) ;
if ( V_21 )
return V_21 ;
F_16 ( V_23 ) ;
V_2 -> V_6 = 0 ;
return V_21 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_9 ;
V_9 = F_4 ( V_2 -> V_10 -> V_11 , 0 ) ;
if ( V_9 )
return V_9 ;
F_5 ( V_16 ) ;
F_6 ( V_2 -> V_10 -> V_13 , 1 ) ;
F_5 ( V_16 ) ;
F_6 ( V_2 -> V_10 -> V_13 , 0 ) ;
F_5 ( V_16 ) ;
F_6 ( V_2 -> V_10 -> V_11 , 1 ) ;
return F_11 ( V_2 -> V_10 -> V_11 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_9 ;
V_9 = F_4 ( V_2 -> V_10 -> V_11 , 1 ) ;
if ( V_9 )
return V_9 ;
F_5 ( V_16 ) ;
F_6 ( V_2 -> V_10 -> V_13 , 1 ) ;
F_5 ( V_14 ) ;
F_6 ( V_2 -> V_10 -> V_13 , 0 ) ;
F_5 ( V_12 ) ;
return 0 ;
}
static T_1 F_19 ( struct V_1 * V_2 )
{
int V_8 ;
T_1 V_17 = 0 ;
for ( V_8 = 0 ; V_8 < 8 ; ++ V_8 ) {
V_17 <<= 1 ;
F_6 ( V_2 -> V_10 -> V_13 , 1 ) ;
F_5 ( V_14 ) ;
V_17 |= ! ! F_12 ( V_2 -> V_10 -> V_11 ) ;
F_6 ( V_2 -> V_10 -> V_13 , 0 ) ;
F_5 ( V_12 ) ;
}
return V_17 ;
}
static int F_20 ( struct V_1 * V_2 , T_1 V_24 )
{
int V_9 ;
V_9 = F_14 ( V_2 , V_25 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_4 ( V_2 -> V_10 -> V_11 , 1 ) ;
if ( V_9 )
return V_9 ;
F_5 ( V_16 ) ;
F_9 ( V_2 , V_24 ) ;
V_9 = F_10 ( V_2 ) ;
if ( V_9 )
return V_9 ;
V_2 -> V_6 = V_24 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_21 = 0 ;
T_1 V_24 ;
T_1 V_26 ;
T_1 V_27 = 0 ;
T_1 V_28 [ 2 ] ;
int V_29 = V_30 ;
F_22 ( & V_2 -> V_31 ) ;
if ( F_23 ( V_32 , V_2 -> V_33 + V_29 )
|| ! V_2 -> V_34 ) {
V_21 = F_14 ( V_2 , V_35 ) ;
if ( V_21 )
goto V_36;
V_24 = F_19 ( V_2 ) ;
if ( V_2 -> V_37 ) {
F_17 ( V_2 ) ;
V_27 = F_2 ( F_19 ( V_2 ) ) ;
V_28 [ 0 ] = V_35 ;
V_28 [ 1 ] = V_24 ;
V_2 -> V_38 = ( F_1 ( V_2 , V_28 , 2 )
== V_27 ) ;
}
V_21 = F_18 ( V_2 ) ;
if ( V_21 )
goto V_36;
if ( V_2 -> V_37 && ! V_2 -> V_38 ) {
V_26 = V_2 -> V_6 & 0x07 ;
V_21 = F_15 ( V_2 ) ;
if ( V_21 )
goto V_36;
if ( V_26 ) {
V_21 = F_20 ( V_2 , V_26 ) ;
if ( V_21 ) {
F_13 ( V_2 -> V_18 ,
L_2
L_3 ) ;
goto V_36;
}
}
V_21 = - V_39 ;
goto V_36;
}
V_2 -> V_6 = V_24 ;
V_2 -> V_34 = true ;
V_2 -> V_33 = V_32 ;
}
V_36:
F_24 ( & V_2 -> V_31 ) ;
return V_21 ;
}
static int F_25 ( struct V_1 * V_2 ,
int V_40 ,
int V_41 )
{
int V_21 ;
T_1 V_26 ;
V_21 = F_14 ( V_2 , V_40 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_11 ( V_2 -> V_10 -> V_11 ) ;
if ( V_21 )
return V_21 ;
F_26 ( & V_2 -> V_42 , 0 ) ;
F_27 ( F_28 ( V_2 -> V_10 -> V_11 ) ) ;
if ( F_12 ( V_2 -> V_10 -> V_11 ) == 0 ) {
F_29 ( F_28 ( V_2 -> V_10 -> V_11 ) ) ;
if ( ! F_30 ( & V_2 -> V_42 ) )
F_31 ( & V_2 -> V_43 ) ;
}
V_21 = F_32 ( V_2 -> V_44 ,
( V_2 -> V_45 == V_46 ) ,
F_33 ( V_41 ) ) ;
if ( V_2 -> V_45 != V_46 ) {
V_2 -> V_45 = V_46 ;
return - V_19 ;
} else if ( V_21 == 0 ) {
F_29 ( F_28 ( V_2 -> V_10 -> V_11 ) ) ;
V_21 = F_3 ( V_2 ) ;
if ( V_21 )
return V_21 ;
return - V_47 ;
}
if ( V_2 -> V_37 && ! V_2 -> V_38 ) {
V_26 = V_2 -> V_6 & 0x07 ;
V_21 = F_15 ( V_2 ) ;
if ( V_21 )
return V_21 ;
if ( V_26 ) {
V_21 = F_20 ( V_2 , V_26 ) ;
if ( V_21 ) {
F_13 ( V_2 -> V_18 ,
L_2
L_3 ) ;
return V_21 ;
}
}
return - V_39 ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_21 = 0 ;
int V_29 = V_30 ;
F_22 ( & V_2 -> V_31 ) ;
if ( F_23 ( V_32 , V_2 -> V_48 + V_29 )
|| ! V_2 -> V_49 ) {
V_2 -> V_45 = V_50 ;
V_21 = F_25 ( V_2 , V_51 , 160 ) ;
if ( V_21 )
goto V_36;
V_2 -> V_45 = V_52 ;
V_21 = F_25 ( V_2 , V_53 , 400 ) ;
if ( V_21 )
goto V_36;
V_2 -> V_49 = true ;
V_2 -> V_48 = V_32 ;
}
V_36:
F_24 ( & V_2 -> V_31 ) ;
return V_21 ;
}
static inline int F_35 ( struct V_1 * V_2 )
{
int V_54 = V_55 [ 0 ] . V_54 ;
int V_56 = ( V_2 -> V_6 & V_57 ) ? 40 : 10 ;
int V_8 ;
for ( V_8 = F_36 ( V_55 ) - 1 ; V_8 > 0 ; V_8 -- )
if ( V_2 -> V_58 > V_55 [ V_8 - 1 ] . V_59 ) {
V_54 = ( V_2 -> V_58 - V_55 [ V_8 - 1 ] . V_59 )
* ( V_55 [ V_8 ] . V_54 - V_55 [ V_8 - 1 ] . V_54 )
/ ( V_55 [ V_8 ] . V_59 - V_55 [ V_8 - 1 ] . V_59 )
+ V_55 [ V_8 - 1 ] . V_54 ;
break;
}
return V_2 -> V_60 * V_56 + V_54 ;
}
static inline int F_37 ( struct V_1 * V_2 )
{
int V_61 ;
int V_62 = F_35 ( V_2 ) ;
int V_63 , V_64 ;
int V_65 ;
const int V_66 = - 4 ;
if ( V_2 -> V_6 & V_57 ) {
V_63 = 648000 ;
V_64 = - 7200 ;
V_65 = 1280 ;
} else {
V_63 = 40500 ;
V_64 = - 28 ;
V_65 = 80 ;
}
V_61 = V_66 * 1000
+ V_63 * V_2 -> V_67 / 1000
+ ( V_2 -> V_67 * V_2 -> V_67 * V_64 ) / 10000 ;
return ( V_62 - 25000 ) * ( 10000 + V_65 * V_2 -> V_67 )
/ 1000000 + V_61 ;
}
static T_2 F_38 ( struct V_68 * V_18 ,
struct V_69 * V_70 ,
char * V_71 )
{
int V_21 ;
struct V_1 * V_2 = F_39 ( V_18 ) ;
T_1 V_72 = F_40 ( V_70 ) -> V_73 ;
V_21 = F_21 ( V_2 ) ;
return V_21 ? V_21 : sprintf ( V_71 , L_4 , ! ! ( V_2 -> V_6 & V_72 ) ) ;
}
static T_2 F_41 ( struct V_68 * V_18 ,
struct V_69 * V_70 ,
const char * V_71 , T_3 V_74 )
{
int V_21 ;
struct V_1 * V_2 = F_39 ( V_18 ) ;
long V_3 ;
T_1 V_24 ;
if ( F_42 ( V_71 , 10 , & V_3 ) )
return - V_75 ;
F_22 ( & V_2 -> V_31 ) ;
V_24 = V_2 -> V_6 & 0x07 ;
if ( ! ! V_3 )
V_24 |= V_76 ;
else
V_24 &= ~ V_76 ;
V_21 = F_20 ( V_2 , V_24 ) ;
F_24 ( & V_2 -> V_31 ) ;
return V_21 ? V_21 : V_74 ;
}
static T_2 F_43 ( struct V_68 * V_18 ,
struct V_69 * V_70 ,
char * V_71 )
{
int V_21 ;
struct V_1 * V_2 = F_39 ( V_18 ) ;
V_21 = F_34 ( V_2 ) ;
return V_21 ? V_21 : sprintf ( V_71 , L_4 ,
F_35 ( V_2 ) ) ;
}
static T_2 F_44 ( struct V_68 * V_18 ,
struct V_69 * V_70 ,
char * V_71 )
{
int V_21 ;
struct V_1 * V_2 = F_39 ( V_18 ) ;
V_21 = F_34 ( V_2 ) ;
return V_21 ? V_21 : sprintf ( V_71 , L_4 , F_37 ( V_2 ) ) ;
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
struct V_1 * V_2 = V_81 ;
F_29 ( V_80 ) ;
F_48 ( & V_2 -> V_42 ) ;
if ( V_2 -> V_45 != V_46 )
F_31 ( & V_2 -> V_43 ) ;
return V_82 ;
}
static void F_49 ( struct V_83 * V_84 )
{
T_5 V_15 = 0 ;
T_1 V_27 = 0 ;
T_1 V_28 [ 3 ] ;
struct V_1 * V_2
= F_50 ( V_84 , struct V_1 ,
V_43 ) ;
if ( F_12 ( V_2 -> V_10 -> V_11 ) ) {
F_26 ( & V_2 -> V_42 , 0 ) ;
F_27 ( F_28 ( V_2 -> V_10 -> V_11 ) ) ;
if ( F_12 ( V_2 -> V_10 -> V_11 )
|| F_30 ( & V_2 -> V_42 ) )
return;
}
V_15 = F_19 ( V_2 ) ;
V_15 <<= 8 ;
if ( F_17 ( V_2 ) )
goto V_85;
V_15 |= F_19 ( V_2 ) ;
if ( V_2 -> V_37 ) {
if ( F_17 ( V_2 ) )
goto V_85;
V_27 = F_2 ( F_19 ( V_2 ) ) ;
V_28 [ 0 ] = ( V_2 -> V_45 == V_52 ) ?
V_53 : V_51 ;
V_28 [ 1 ] = ( T_1 ) ( V_15 >> 8 ) ;
V_28 [ 2 ] = ( T_1 ) V_15 ;
V_2 -> V_38
= ( F_1 ( V_2 , V_28 , 3 ) == V_27 ) ;
}
if ( F_18 ( V_2 ) )
goto V_85;
switch ( V_2 -> V_45 ) {
case V_52 :
V_2 -> V_60 = V_15 ;
break;
case V_50 :
V_2 -> V_67 = V_15 ;
break;
default:
break;
}
V_2 -> V_45 = V_46 ;
V_85:
F_51 ( & V_2 -> V_44 ) ;
}
static void F_52 ( struct V_83 * V_84 )
{
struct V_1 * V_2
= F_50 ( V_84 , struct V_1 ,
V_86 ) ;
V_2 -> V_58 = F_53 ( V_2 -> V_87 ) ;
}
static int F_54 ( struct V_88 * V_89 ,
unsigned long V_90 ,
void * V_91 )
{
struct V_1 * V_2 = F_50 ( V_89 , struct V_1 , V_89 ) ;
if ( V_90 == V_92 )
V_2 -> V_93 = false ;
F_31 ( & V_2 -> V_86 ) ;
return V_94 ;
}
static int F_55 ( struct V_77 * V_78 )
{
int V_21 ;
struct V_1 * V_2 ;
T_1 V_24 = 0 ;
V_2 = F_56 ( & V_78 -> V_18 , sizeof( * V_2 ) , V_95 ) ;
if ( ! V_2 )
return - V_96 ;
F_57 ( & V_2 -> V_43 , F_49 ) ;
F_57 ( & V_2 -> V_86 , F_52 ) ;
F_58 ( V_78 , V_2 ) ;
F_59 ( & V_2 -> V_31 ) ;
V_2 -> V_18 = & V_78 -> V_18 ;
F_60 ( & V_2 -> V_44 ) ;
if ( F_61 ( & V_78 -> V_18 ) == NULL ) {
F_13 ( & V_78 -> V_18 , L_6 ) ;
return - V_75 ;
}
V_2 -> V_10 = F_61 ( & V_78 -> V_18 ) ;
V_2 -> V_58 = V_2 -> V_10 -> V_97 * 1000 ;
if ( V_2 -> V_10 -> V_98 )
V_2 -> V_37 = true ;
if ( V_2 -> V_10 -> V_99 )
V_24 |= V_100 ;
if ( V_2 -> V_10 -> V_101 )
V_24 |= V_57 ;
V_2 -> V_87 = F_62 ( V_2 -> V_18 , L_7 ) ;
if ( ! F_63 ( V_2 -> V_87 ) ) {
int V_102 ;
V_102 = F_53 ( V_2 -> V_87 ) ;
if ( V_102 )
V_2 -> V_58 = V_102 ;
V_21 = F_64 ( V_2 -> V_87 ) ;
if ( V_21 != 0 ) {
F_13 ( & V_78 -> V_18 ,
L_8 , V_21 ) ;
return V_21 ;
}
V_2 -> V_89 . V_103 = & F_54 ;
V_21 = F_65 ( V_2 -> V_87 , & V_2 -> V_89 ) ;
if ( V_21 ) {
F_13 ( & V_78 -> V_18 ,
L_9 ) ;
F_66 ( V_2 -> V_87 ) ;
return V_21 ;
}
}
V_21 = F_67 ( & V_78 -> V_18 , V_2 -> V_10 -> V_13 ,
V_104 , L_10 ) ;
if ( V_21 ) {
F_13 ( & V_78 -> V_18 , L_11 ) ;
goto V_105;
}
V_21 = F_68 ( & V_78 -> V_18 , V_2 -> V_10 -> V_11 ,
L_12 ) ;
if ( V_21 ) {
F_13 ( & V_78 -> V_18 , L_13 ) ;
goto V_105;
}
V_21 = F_69 ( & V_78 -> V_18 , F_28 ( V_2 -> V_10 -> V_11 ) ,
F_47 ,
V_106 ,
L_14 ,
V_2 ) ;
if ( V_21 ) {
F_13 ( & V_78 -> V_18 , L_15 ) ;
goto V_105;
}
F_29 ( F_28 ( V_2 -> V_10 -> V_11 ) ) ;
V_21 = F_3 ( V_2 ) ;
if ( V_21 )
goto V_105;
V_21 = F_15 ( V_2 ) ;
if ( V_21 )
goto V_105;
if ( V_24 ) {
V_21 = F_20 ( V_2 , V_24 ) ;
if ( V_21 )
goto V_105;
}
V_21 = F_70 ( & V_78 -> V_18 . V_107 , & V_108 ) ;
if ( V_21 ) {
F_13 ( & V_78 -> V_18 , L_16 ) ;
goto V_105;
}
V_2 -> V_109 = F_71 ( V_2 -> V_18 ) ;
if ( F_63 ( V_2 -> V_109 ) ) {
V_21 = F_72 ( V_2 -> V_109 ) ;
goto V_110;
}
return 0 ;
V_110:
F_73 ( & V_78 -> V_18 . V_107 , & V_108 ) ;
V_105:
if ( ! F_63 ( V_2 -> V_87 ) ) {
F_74 ( V_2 -> V_87 , & V_2 -> V_89 ) ;
F_66 ( V_2 -> V_87 ) ;
}
return V_21 ;
}
static int F_75 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = F_76 ( V_78 ) ;
F_22 ( & V_2 -> V_31 ) ;
if ( F_15 ( V_2 ) ) {
F_24 ( & V_2 -> V_31 ) ;
return - V_111 ;
}
F_77 ( V_2 -> V_109 ) ;
F_73 ( & V_78 -> V_18 . V_107 , & V_108 ) ;
if ( ! F_63 ( V_2 -> V_87 ) ) {
F_74 ( V_2 -> V_87 , & V_2 -> V_89 ) ;
F_66 ( V_2 -> V_87 ) ;
}
F_24 ( & V_2 -> V_31 ) ;
return 0 ;
}
