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
F_9 ( ! F_10 ( & V_1 -> V_2 ) ) ;
if ( V_5 > V_8 )
return - V_9 ;
V_7 = F_11 ( V_1 -> V_10 , V_5 , V_6 ) ;
F_12 ( V_1 -> V_3 , L_3 , V_5 , * V_6 ) ;
return V_7 ;
}
int F_13 ( struct V_1 * V_1 , unsigned int V_5 , T_1 V_6 )
{
F_9 ( ! F_10 ( & V_1 -> V_2 ) ) ;
F_12 ( V_1 -> V_3 , L_4 , V_5 , V_6 ) ;
if ( V_5 > V_8 || V_6 > 0xffffff )
return - V_9 ;
return F_14 ( V_1 -> V_10 , V_5 , V_6 ) ;
}
int F_15 ( struct V_1 * V_1 , unsigned int V_5 ,
T_1 V_11 , T_1 V_6 )
{
F_9 ( ! F_10 ( & V_1 -> V_2 ) ) ;
F_9 ( V_6 & ~ V_11 ) ;
F_12 ( V_1 -> V_3 , L_5 ,
V_5 , V_6 , V_11 ) ;
return F_16 ( V_1 -> V_10 , V_5 , V_11 , V_6 ) ;
}
int F_17 ( struct V_1 * V_1 , int V_12 )
{
int V_7 ;
unsigned int V_13 = V_12 < 24 ? V_14 : V_15 ;
T_1 V_16 = 1 << ( V_12 < 24 ? V_12 : V_12 - 24 ) ;
T_1 V_11 ;
if ( V_12 < 0 || V_12 >= V_17 )
return - V_9 ;
V_7 = F_8 ( V_1 , V_13 , & V_11 ) ;
if ( V_7 )
return V_7 ;
if ( V_11 & V_16 )
return 0 ;
return F_13 ( V_1 , V_13 , V_11 | V_16 ) ;
}
int F_18 ( struct V_1 * V_1 , int V_12 )
{
int V_7 ;
unsigned int V_13 = V_12 < 24 ? V_14 : V_15 ;
T_1 V_16 = 1 << ( V_12 < 24 ? V_12 : V_12 - 24 ) ;
T_1 V_11 ;
if ( V_12 < 0 || V_12 >= V_17 )
return - V_9 ;
V_7 = F_8 ( V_1 , V_13 , & V_11 ) ;
if ( V_7 )
return V_7 ;
if ( ! ( V_11 & V_16 ) )
return 0 ;
return F_13 ( V_1 , V_13 , V_11 & ~ V_16 ) ;
}
int F_19 ( struct V_1 * V_1 , int V_12 ,
int * V_18 , int * V_19 )
{
int V_7 ;
unsigned int V_13 = V_12 < 24 ? V_14 : V_15 ;
unsigned int V_20 = V_12 < 24 ? V_21 : V_22 ;
T_1 V_16 = 1 << ( V_12 < 24 ? V_12 : V_12 - 24 ) ;
if ( V_12 < 0 || V_12 >= V_17 )
return - V_9 ;
if ( V_18 ) {
T_1 V_11 ;
V_7 = F_8 ( V_1 , V_13 , & V_11 ) ;
if ( V_7 )
return V_7 ;
* V_18 = V_11 & V_16 ;
}
if ( V_19 ) {
T_1 V_23 ;
V_7 = F_8 ( V_1 , V_20 , & V_23 ) ;
if ( V_7 )
return V_7 ;
* V_19 = V_23 & V_16 ;
}
return 0 ;
}
int F_20 ( struct V_1 * V_1 , int V_12 )
{
unsigned int V_20 = V_12 < 24 ? V_21 : V_22 ;
unsigned int V_6 = 1 << ( V_12 < 24 ? V_12 : V_12 - 24 ) ;
F_9 ( V_12 < 0 || V_12 >= V_17 ) ;
return F_13 ( V_1 , V_20 , V_6 ) ;
}
int F_21 ( struct V_1 * V_1 , int V_12 ,
T_2 V_24 , const char * V_25 , void * V_3 )
{
F_9 ( ! F_10 ( & V_1 -> V_2 ) ) ;
F_9 ( ! V_24 ) ;
if ( V_12 < 0 || V_12 >= V_17 )
return - V_9 ;
if ( V_1 -> V_26 [ V_12 ] )
return - V_27 ;
V_1 -> V_26 [ V_12 ] = V_24 ;
V_1 -> V_28 [ V_12 ] = V_3 ;
return 0 ;
}
int F_22 ( struct V_1 * V_1 , int V_12 ,
T_2 V_24 , const char * V_25 , void * V_3 )
{
int V_7 ;
V_7 = F_21 ( V_1 , V_12 , V_24 , V_25 , V_3 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_18 ( V_1 , V_12 ) ;
if ( V_7 ) {
V_1 -> V_26 [ V_12 ] = NULL ;
V_1 -> V_28 [ V_12 ] = NULL ;
return V_7 ;
}
return 0 ;
}
int F_23 ( struct V_1 * V_1 , int V_12 , void * V_3 )
{
int V_7 ;
F_9 ( ! F_10 ( & V_1 -> V_2 ) ) ;
if ( V_12 < 0 || V_12 >= V_17 || ! V_1 -> V_26 [ V_12 ] ||
V_1 -> V_28 [ V_12 ] != V_3 )
return - V_9 ;
V_7 = F_17 ( V_1 , V_12 ) ;
if ( V_7 )
return V_7 ;
V_1 -> V_26 [ V_12 ] = NULL ;
V_1 -> V_28 [ V_12 ] = NULL ;
return 0 ;
}
static inline T_3 F_24 ( struct V_1 * V_1 , int V_12 )
{
return V_1 -> V_26 [ V_12 ] ( V_12 , V_1 -> V_28 [ V_12 ] ) ;
}
static int F_25 ( struct V_1 * V_1 ,
unsigned int V_20 , unsigned int V_13 , int V_29 )
{
T_1 V_23 , V_11 ;
int V_7 = F_8 ( V_1 , V_20 , & V_23 ) ;
int V_30 = 0 ;
if ( V_7 )
return V_7 ;
V_7 = F_8 ( V_1 , V_13 , & V_11 ) ;
if ( V_7 )
return V_7 ;
while ( V_23 & ~ V_11 ) {
int V_12 = F_26 ( V_23 & ~ V_11 ) ;
V_23 &= ~ ( 1 << V_12 ) ;
if ( F_27 ( V_1 -> V_26 [ V_29 + V_12 ] ) ) {
T_3 V_31 ;
V_31 = F_24 ( V_1 , V_29 + V_12 ) ;
if ( V_31 == V_32 )
V_30 ++ ;
} else {
F_28 ( V_1 -> V_3 ,
L_6 ,
V_29 + V_12 ) ;
V_11 |= 1 << V_12 ;
V_7 = F_13 ( V_1 , V_13 , V_11 ) ;
}
}
return V_30 ;
}
static T_3 F_29 ( int V_12 , void * V_33 )
{
struct V_1 * V_1 = V_33 ;
T_3 V_7 ;
int V_31 = 0 ;
F_1 ( V_1 ) ;
V_7 = F_25 ( V_1 , V_21 ,
V_14 , 0 ) ;
if ( V_7 > 0 )
V_31 = 1 ;
V_7 = F_25 ( V_1 , V_22 ,
V_15 , 24 ) ;
if ( V_7 > 0 )
V_31 = 1 ;
F_6 ( V_1 ) ;
return F_30 ( V_31 ) ;
}
static int F_31 ( struct V_1 * V_1 )
{
T_1 V_34 ;
T_1 V_35 ;
int V_7 ;
V_7 = F_8 ( V_1 , 46 , & V_34 ) ;
if ( V_7 )
return V_7 ;
V_34 = ( V_34 >> 6 ) & 0x7 ;
switch ( V_34 ) {
case 2 :
V_1 -> V_36 = V_37 ;
break;
case 7 :
V_1 -> V_36 = V_38 ;
break;
default:
V_1 -> V_36 = V_39 ;
break;
}
if ( V_1 -> V_36 == V_37 ||
V_1 -> V_36 == V_38 ) {
V_7 = F_8 ( V_1 , V_40 , & V_35 ) ;
F_32 ( V_1 -> V_3 , L_7
L_8 ,
V_41 [ V_1 -> V_36 ] ,
F_33 ( V_35 , V_42 ) ,
F_33 ( V_35 , V_43 ) ,
F_33 ( V_35 , V_44 ) ,
F_33 ( V_35 , V_45 ) ,
F_33 ( V_35 , V_46 ) ,
F_33 ( V_35 , V_47 ) ) ;
}
return ( V_1 -> V_36 == V_39 ) ? - V_48 : 0 ;
}
static const char * F_34 ( struct V_1 * V_1 )
{
return V_41 [ V_1 -> V_36 ] ;
}
int F_35 ( struct V_1 * V_1 )
{
return V_1 -> V_49 ;
}
static T_3 F_36 ( int V_12 , void * V_33 )
{
struct V_50 * V_51 = V_33 ;
F_20 ( V_51 -> V_1 , V_12 ) ;
F_37 ( & V_51 -> V_52 ) ;
return V_32 ;
}
int F_38 ( struct V_1 * V_1 , unsigned int V_53 ,
unsigned int V_54 , T_4 V_55 , bool V_56 ,
unsigned int * V_57 )
{
T_1 V_58 , V_59 , V_60 ;
int V_61 , V_7 ;
struct V_50 V_51 = {
. V_1 = V_1 ,
} ;
F_39 ( & V_51 . V_52 ) ;
F_3 ( V_1 -> V_3 , L_9 , V_4 ) ;
F_1 ( V_1 ) ;
if ( V_1 -> V_62 & V_63 ) {
V_7 = - V_27 ;
goto V_64;
}
V_1 -> V_62 |= V_63 ;
F_8 ( V_1 , V_65 , & V_60 ) ;
V_58 = V_66 | V_67 ;
V_59 = V_68 | V_69 | V_70 ;
if ( V_54 > 7 )
V_59 |= V_71 ;
switch ( V_53 ) {
case V_72 :
V_58 |= V_73 | V_74 |
V_75 ;
V_59 |= 4 << V_76 ;
break;
case V_77 :
V_58 |= V_60 & V_78 ;
V_59 |= ( V_54 & 0x7 ) << V_79 ;
V_59 |= V_80 ;
break;
case V_81 :
V_58 |= V_60 & V_78 ;
V_59 |= 4 << V_76 ;
break;
default:
F_6 ( V_1 ) ;
return - V_9 ;
}
V_59 |= V_55 << V_82 ;
if ( V_56 )
V_59 |= V_83 ;
F_3 ( V_1 -> V_3 , L_10 , V_4 ) ;
F_22 ( V_1 , V_84 ,
F_36 , V_4 , & V_51 ) ;
F_20 ( V_1 , V_84 ) ;
F_13 ( V_1 , V_65 , V_58 ) ;
F_13 ( V_1 , V_85 , V_59 ) ;
F_6 ( V_1 ) ;
V_7 = F_40 ( & V_51 . V_52 , V_86 ) ;
if ( ! V_7 )
V_7 = - V_87 ;
F_1 ( V_1 ) ;
F_23 ( V_1 , V_84 , & V_51 ) ;
if ( V_7 > 0 )
for ( V_61 = 0 ; V_61 < 4 ; ++ V_61 ) {
V_7 = F_8 ( V_1 ,
V_88 , & V_57 [ V_61 ] ) ;
if ( V_7 )
break;
}
if ( V_53 == V_72 )
F_13 ( V_1 , V_65 , V_60 ) ;
V_1 -> V_62 &= ~ V_63 ;
V_64:
F_6 ( V_1 ) ;
return V_7 ;
}
static int F_41 ( struct V_1 * V_1 ,
const char * V_89 , void * V_90 , T_5 V_91 )
{
char V_92 [ 30 ] ;
const char * V_25 = F_34 ( V_1 ) ;
struct V_93 V_94 = {
. V_95 = V_90 ,
. V_91 = V_91 ,
} ;
if ( snprintf ( V_92 , sizeof( V_92 ) , V_89 , V_25 ) > sizeof( V_92 ) )
return - V_96 ;
V_94 . V_25 = F_42 ( V_92 , strlen ( V_92 ) + 1 , V_97 ) ;
if ( ! V_94 . V_25 )
return - V_98 ;
return F_43 ( V_1 -> V_3 , - 1 , & V_94 , 1 , NULL , 0 , NULL ) ;
}
static int F_44 ( struct V_1 * V_1 , const char * V_89 )
{
return F_41 ( V_1 , V_89 , NULL , 0 ) ;
}
static int F_45 ( struct V_1 * V_1 )
{
struct V_99 * V_100 = V_1 -> V_3 -> V_101 ;
if ( ! V_100 )
return - V_48 ;
if ( F_46 ( V_100 , L_11 , NULL ) )
V_1 -> V_49 |= V_102 ;
if ( F_46 ( V_100 , L_12 , NULL ) )
V_1 -> V_49 |= V_103 ;
if ( F_46 ( V_100 , L_13 , NULL ) )
V_1 -> V_49 |= V_104 ;
if ( F_46 ( V_100 , L_14 , NULL ) )
V_1 -> V_49 |= V_105 ;
return 0 ;
}
static inline int F_45 ( struct V_1 * V_1 )
{
return - V_48 ;
}
int F_47 ( struct V_1 * V_1 ,
struct V_106 * V_90 , int V_12 )
{
int V_7 ;
F_1 ( V_1 ) ;
V_7 = F_31 ( V_1 ) ;
if ( V_7 )
goto V_107;
V_7 = F_13 ( V_1 , V_14 , 0x00ffffff ) ;
if ( V_7 )
goto V_108;
V_7 = F_13 ( V_1 , V_15 , 0x00ffffff ) ;
if ( V_7 )
goto V_108;
V_7 = F_48 ( V_12 , NULL , F_29 ,
V_109 | V_110 , L_15 , V_1 ) ;
if ( V_7 ) {
V_108:
V_107:
F_6 ( V_1 ) ;
return V_7 ;
}
V_1 -> V_12 = V_12 ;
F_6 ( V_1 ) ;
if ( F_45 ( V_1 ) < 0 && V_90 )
V_1 -> V_49 = V_90 -> V_49 ;
if ( V_1 -> V_49 & V_102 )
F_44 ( V_1 , L_16 ) ;
if ( V_1 -> V_49 & V_103 )
F_41 ( V_1 , L_17 ,
V_90 -> V_111 , sizeof( * V_90 -> V_111 ) ) ;
if ( V_1 -> V_49 & V_104 )
F_44 ( V_1 , L_18 ) ;
if ( V_1 -> V_49 & V_105 )
F_41 ( V_1 , L_19 ,
& V_90 -> V_112 , sizeof( V_90 -> V_112 ) ) ;
if ( V_90 ) {
F_41 ( V_1 , L_20 ,
& V_90 -> V_113 , sizeof( V_90 -> V_113 ) ) ;
F_41 ( V_1 , L_21 ,
V_90 -> V_114 , sizeof( * V_90 -> V_114 ) ) ;
F_41 ( V_1 , L_22 ,
V_90 -> V_115 , sizeof( * V_90 -> V_115 ) ) ;
} else {
F_44 ( V_1 , L_20 ) ;
F_44 ( V_1 , L_21 ) ;
F_44 ( V_1 , L_22 ) ;
}
return 0 ;
}
void F_49 ( struct V_1 * V_1 )
{
F_50 ( V_1 -> V_12 , V_1 ) ;
F_51 ( V_1 -> V_3 ) ;
}
