void F_1 ( struct V_1 * V_1 )
{
if ( ! F_2 ( & V_1 -> V_2 ) ) {
F_3 ( V_1 -> V_3 , L_1 ,
V_4 , F_4 ( 0 ) ) ;
F_5 ( & V_1 -> V_2 ) ;
}
F_3 ( V_1 -> V_3 , L_2 ,
V_4 , F_4 ( 0 ) ) ;
}
void F_6 ( struct V_1 * V_1 )
{
F_3 ( V_1 -> V_3 , L_2 ,
V_4 , F_4 ( 0 ) ) ;
F_7 ( & V_1 -> V_2 ) ;
}
int F_8 ( struct V_1 * V_1 , unsigned int V_5 , T_1 * V_6 )
{
int V_7 ;
V_7 = F_9 ( V_1 -> V_8 , V_5 , V_6 ) ;
F_10 ( V_1 -> V_3 , L_3 , V_5 , * V_6 ) ;
return V_7 ;
}
int F_11 ( struct V_1 * V_1 , unsigned int V_5 , T_1 V_6 )
{
F_10 ( V_1 -> V_3 , L_4 , V_5 , V_6 ) ;
if ( V_6 >= F_12 ( 24 ) )
return - V_9 ;
return F_13 ( V_1 -> V_8 , V_5 , V_6 ) ;
}
int F_14 ( struct V_1 * V_1 , unsigned int V_5 ,
T_1 V_10 , T_1 V_6 )
{
F_15 ( V_6 & ~ V_10 ) ;
F_10 ( V_1 -> V_3 , L_5 ,
V_5 , V_6 , V_10 ) ;
return F_16 ( V_1 -> V_8 , V_5 , V_10 , V_6 ) ;
}
int F_17 ( struct V_1 * V_1 , int V_11 )
{
int V_7 ;
unsigned int V_12 = V_11 < 24 ? V_13 : V_14 ;
T_1 V_15 = 1 << ( V_11 < 24 ? V_11 : V_11 - 24 ) ;
T_1 V_10 ;
if ( V_11 < 0 || V_11 >= V_16 )
return - V_9 ;
V_7 = F_8 ( V_1 , V_12 , & V_10 ) ;
if ( V_7 )
return V_7 ;
if ( V_10 & V_15 )
return 0 ;
return F_11 ( V_1 , V_12 , V_10 | V_15 ) ;
}
int F_18 ( struct V_1 * V_1 , int V_11 )
{
int V_7 ;
unsigned int V_12 = V_11 < 24 ? V_13 : V_14 ;
T_1 V_15 = 1 << ( V_11 < 24 ? V_11 : V_11 - 24 ) ;
T_1 V_10 ;
if ( V_11 < 0 || V_11 >= V_16 )
return - V_9 ;
V_7 = F_8 ( V_1 , V_12 , & V_10 ) ;
if ( V_7 )
return V_7 ;
if ( ! ( V_10 & V_15 ) )
return 0 ;
return F_11 ( V_1 , V_12 , V_10 & ~ V_15 ) ;
}
int F_19 ( struct V_1 * V_1 , int V_11 ,
int * V_17 , int * V_18 )
{
int V_7 ;
unsigned int V_12 = V_11 < 24 ? V_13 : V_14 ;
unsigned int V_19 = V_11 < 24 ? V_20 : V_21 ;
T_1 V_15 = 1 << ( V_11 < 24 ? V_11 : V_11 - 24 ) ;
if ( V_11 < 0 || V_11 >= V_16 )
return - V_9 ;
if ( V_17 ) {
T_1 V_10 ;
V_7 = F_8 ( V_1 , V_12 , & V_10 ) ;
if ( V_7 )
return V_7 ;
* V_17 = V_10 & V_15 ;
}
if ( V_18 ) {
T_1 V_22 ;
V_7 = F_8 ( V_1 , V_19 , & V_22 ) ;
if ( V_7 )
return V_7 ;
* V_18 = V_22 & V_15 ;
}
return 0 ;
}
int F_20 ( struct V_1 * V_1 , int V_11 )
{
unsigned int V_19 = V_11 < 24 ? V_20 : V_21 ;
unsigned int V_6 = 1 << ( V_11 < 24 ? V_11 : V_11 - 24 ) ;
F_15 ( V_11 < 0 || V_11 >= V_16 ) ;
return F_11 ( V_1 , V_19 , V_6 ) ;
}
int F_21 ( struct V_1 * V_1 , int V_11 ,
T_2 V_23 , const char * V_24 , void * V_3 )
{
F_15 ( ! F_22 ( & V_1 -> V_2 ) ) ;
F_15 ( ! V_23 ) ;
if ( V_11 < 0 || V_11 >= V_16 )
return - V_9 ;
if ( V_1 -> V_25 [ V_11 ] )
return - V_26 ;
V_1 -> V_25 [ V_11 ] = V_23 ;
V_1 -> V_27 [ V_11 ] = V_3 ;
return 0 ;
}
int F_23 ( struct V_1 * V_1 , int V_11 ,
T_2 V_23 , const char * V_24 , void * V_3 )
{
int V_7 ;
V_7 = F_21 ( V_1 , V_11 , V_23 , V_24 , V_3 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_18 ( V_1 , V_11 ) ;
if ( V_7 ) {
V_1 -> V_25 [ V_11 ] = NULL ;
V_1 -> V_27 [ V_11 ] = NULL ;
return V_7 ;
}
return 0 ;
}
int F_24 ( struct V_1 * V_1 , int V_11 , void * V_3 )
{
int V_7 ;
F_15 ( ! F_22 ( & V_1 -> V_2 ) ) ;
if ( V_11 < 0 || V_11 >= V_16 || ! V_1 -> V_25 [ V_11 ] ||
V_1 -> V_27 [ V_11 ] != V_3 )
return - V_9 ;
V_7 = F_17 ( V_1 , V_11 ) ;
if ( V_7 )
return V_7 ;
V_1 -> V_25 [ V_11 ] = NULL ;
V_1 -> V_27 [ V_11 ] = NULL ;
return 0 ;
}
static inline T_3 F_25 ( struct V_1 * V_1 , int V_11 )
{
return V_1 -> V_25 [ V_11 ] ( V_11 , V_1 -> V_27 [ V_11 ] ) ;
}
static int F_26 ( struct V_1 * V_1 ,
unsigned int V_19 , unsigned int V_12 , int V_28 )
{
T_1 V_22 , V_10 ;
int V_7 = F_8 ( V_1 , V_19 , & V_22 ) ;
int V_29 = 0 ;
if ( V_7 )
return V_7 ;
V_7 = F_8 ( V_1 , V_12 , & V_10 ) ;
if ( V_7 )
return V_7 ;
while ( V_22 & ~ V_10 ) {
int V_11 = F_27 ( V_22 & ~ V_10 ) ;
V_22 &= ~ ( 1 << V_11 ) ;
if ( F_28 ( V_1 -> V_25 [ V_28 + V_11 ] ) ) {
T_3 V_30 ;
V_30 = F_25 ( V_1 , V_28 + V_11 ) ;
if ( V_30 == V_31 )
V_29 ++ ;
} else {
F_29 ( V_1 -> V_3 ,
L_6 ,
V_28 + V_11 ) ;
V_10 |= 1 << V_11 ;
V_7 = F_11 ( V_1 , V_12 , V_10 ) ;
}
}
return V_29 ;
}
static T_3 F_30 ( int V_11 , void * V_32 )
{
struct V_1 * V_1 = V_32 ;
T_3 V_7 ;
int V_30 = 0 ;
F_1 ( V_1 ) ;
V_7 = F_26 ( V_1 , V_20 ,
V_13 , 0 ) ;
if ( V_7 > 0 )
V_30 = 1 ;
V_7 = F_26 ( V_1 , V_21 ,
V_14 , 24 ) ;
if ( V_7 > 0 )
V_30 = 1 ;
F_6 ( V_1 ) ;
return F_31 ( V_30 ) ;
}
static void F_32 ( struct V_1 * V_1 , T_1 V_33 )
{
F_33 ( V_1 -> V_3 , L_7
L_8 ,
V_1 -> V_34 -> V_24 ,
F_34 ( V_33 , V_35 ) ,
F_34 ( V_33 , V_36 ) ,
F_34 ( V_33 , V_37 ) ,
F_34 ( V_33 , V_38 ) ,
F_34 ( V_33 , V_39 ) ,
F_34 ( V_33 , V_40 ) ) ;
}
static void F_35 ( struct V_1 * V_1 , T_1 V_33 )
{
F_33 ( V_1 -> V_3 , L_9 ,
V_1 -> V_34 -> V_24 ,
F_34 ( V_33 , V_41 ) ,
F_34 ( V_33 , V_42 ) ,
F_34 ( V_33 , V_43 ) ,
F_34 ( V_33 , V_44 ) ) ;
}
static const char * F_36 ( struct V_1 * V_1 )
{
return V_1 -> V_34 -> V_24 ;
}
int F_37 ( struct V_1 * V_1 )
{
return V_1 -> V_45 ;
}
static T_3 F_38 ( int V_11 , void * V_32 )
{
struct V_46 * V_47 = V_32 ;
F_20 ( V_47 -> V_1 , V_11 ) ;
F_39 ( & V_47 -> V_48 ) ;
return V_31 ;
}
int F_40 ( struct V_1 * V_1 , unsigned int V_49 ,
unsigned int V_50 , T_4 V_51 , bool V_52 ,
unsigned int * V_53 )
{
T_1 V_54 , V_55 , V_56 ;
int V_57 , V_7 ;
struct V_46 V_47 = {
. V_1 = V_1 ,
} ;
F_41 ( & V_47 . V_48 ) ;
F_3 ( V_1 -> V_3 , L_10 , V_4 ) ;
F_1 ( V_1 ) ;
if ( V_1 -> V_58 & V_59 ) {
V_7 = - V_26 ;
goto V_60;
}
V_1 -> V_58 |= V_59 ;
F_8 ( V_1 , V_61 , & V_56 ) ;
V_54 = V_62 | V_63 ;
V_55 = V_64 | V_65 | V_66 ;
if ( V_50 > 7 )
V_55 |= V_67 ;
switch ( V_49 ) {
case V_68 :
V_54 |= V_69 | V_70 |
V_71 ;
V_55 |= 4 << V_72 ;
break;
case V_73 :
V_54 |= V_56 & V_74 ;
V_55 |= ( V_50 & 0x7 ) << V_75 ;
V_55 |= V_76 ;
break;
case V_77 :
V_54 |= V_56 & V_74 ;
V_55 |= 4 << V_72 ;
break;
default:
F_6 ( V_1 ) ;
return - V_9 ;
}
V_55 |= V_51 << V_78 ;
if ( V_52 )
V_55 |= V_79 ;
F_3 ( V_1 -> V_3 , L_11 , V_4 ) ;
F_23 ( V_1 , V_80 ,
F_38 , V_4 , & V_47 ) ;
F_20 ( V_1 , V_80 ) ;
F_11 ( V_1 , V_61 , V_54 ) ;
F_11 ( V_1 , V_81 , V_55 ) ;
F_6 ( V_1 ) ;
V_7 = F_42 ( & V_47 . V_48 , V_82 ) ;
if ( ! V_7 )
V_7 = - V_83 ;
F_1 ( V_1 ) ;
F_24 ( V_1 , V_80 , & V_47 ) ;
if ( V_7 > 0 )
for ( V_57 = 0 ; V_57 < 4 ; ++ V_57 ) {
V_7 = F_8 ( V_1 ,
V_84 , & V_53 [ V_57 ] ) ;
if ( V_7 )
break;
}
if ( V_49 == V_68 )
F_11 ( V_1 , V_61 , V_56 ) ;
V_1 -> V_58 &= ~ V_59 ;
V_60:
F_6 ( V_1 ) ;
return V_7 ;
}
static int F_43 ( struct V_1 * V_1 ,
const char * V_85 , void * V_86 , T_5 V_87 )
{
char V_88 [ 30 ] ;
const char * V_24 = F_36 ( V_1 ) ;
struct V_89 V_90 = {
. V_91 = V_86 ,
. V_87 = V_87 ,
} ;
if ( snprintf ( V_88 , sizeof( V_88 ) , V_85 , V_24 ) > sizeof( V_88 ) )
return - V_92 ;
V_90 . V_24 = F_44 ( V_88 , strlen ( V_88 ) + 1 , V_93 ) ;
if ( ! V_90 . V_24 )
return - V_94 ;
return F_45 ( V_1 -> V_3 , - 1 , & V_90 , 1 , NULL , 0 , NULL ) ;
}
static int F_46 ( struct V_1 * V_1 , const char * V_85 )
{
return F_43 ( V_1 , V_85 , NULL , 0 ) ;
}
static int F_47 ( struct V_1 * V_1 )
{
struct V_95 * V_96 = V_1 -> V_3 -> V_97 ;
if ( ! V_96 )
return - V_98 ;
if ( F_48 ( V_96 , L_12 , NULL ) )
V_1 -> V_45 |= V_99 ;
if ( F_48 ( V_96 , L_13 , NULL ) )
V_1 -> V_45 |= V_100 ;
if ( F_48 ( V_96 , L_14 , NULL ) )
V_1 -> V_45 |= V_101 ;
if ( F_48 ( V_96 , L_15 , NULL ) )
V_1 -> V_45 |= V_102 ;
return 0 ;
}
static inline int F_47 ( struct V_1 * V_1 )
{
return - V_98 ;
}
int F_49 ( struct V_103 * V_3 )
{
struct V_104 * V_86 = F_50 ( V_3 ) ;
struct V_1 * V_1 = F_51 ( V_3 ) ;
int V_7 ;
T_1 V_33 ;
V_1 -> V_3 = V_3 ;
V_7 = F_8 ( V_1 , V_105 , & V_33 ) ;
if ( V_7 )
return V_7 ;
V_1 -> V_34 -> V_106 ( V_1 , V_33 ) ;
V_7 = F_11 ( V_1 , V_13 , 0x00ffffff ) ;
if ( V_7 )
return V_7 ;
V_7 = F_11 ( V_1 , V_14 , 0x00ffffff ) ;
if ( V_7 )
return V_7 ;
F_52 ( & V_1 -> V_2 ) ;
V_7 = F_53 ( V_1 -> V_11 , NULL , F_30 ,
V_107 | V_108 , L_16 , V_1 ) ;
if ( V_7 )
return V_7 ;
if ( F_47 ( V_1 ) < 0 && V_86 )
V_1 -> V_45 = V_86 -> V_45 ;
if ( V_1 -> V_45 & V_99 )
F_46 ( V_1 , L_17 ) ;
if ( V_1 -> V_45 & V_101 )
F_46 ( V_1 , L_18 ) ;
if ( V_86 ) {
F_43 ( V_1 , L_19 ,
& V_86 -> V_109 , sizeof( V_86 -> V_109 ) ) ;
F_43 ( V_1 , L_20 ,
V_86 -> V_110 , sizeof( * V_86 -> V_110 ) ) ;
F_43 ( V_1 , L_21 ,
V_86 -> V_111 , sizeof( * V_86 -> V_111 ) ) ;
if ( V_1 -> V_45 & V_100 )
F_43 ( V_1 , L_22 ,
V_86 -> V_112 , sizeof( * V_86 -> V_112 ) ) ;
if ( V_1 -> V_45 & V_102 )
F_43 ( V_1 , L_23 ,
& V_86 -> V_113 , sizeof( V_86 -> V_113 ) ) ;
} else {
F_46 ( V_1 , L_19 ) ;
F_46 ( V_1 , L_20 ) ;
F_46 ( V_1 , L_21 ) ;
if ( V_1 -> V_45 & V_100 )
F_46 ( V_1 , L_22 ) ;
if ( V_1 -> V_45 & V_102 )
F_46 ( V_1 , L_23 ) ;
}
return 0 ;
}
int F_54 ( struct V_103 * V_3 )
{
struct V_1 * V_1 = F_51 ( V_3 ) ;
F_55 ( V_1 -> V_11 , V_1 ) ;
F_56 ( V_3 ) ;
F_57 ( & V_1 -> V_2 ) ;
return 0 ;
}
