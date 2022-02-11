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
if ( V_5 > V_8 )
return - V_9 ;
V_7 = F_9 ( V_1 -> V_10 , V_5 , V_6 ) ;
F_10 ( V_1 -> V_3 , L_3 , V_5 , * V_6 ) ;
return V_7 ;
}
int F_11 ( struct V_1 * V_1 , unsigned int V_5 , T_1 V_6 )
{
F_10 ( V_1 -> V_3 , L_4 , V_5 , V_6 ) ;
if ( V_5 > V_8 || V_6 > 0xffffff )
return - V_9 ;
return F_12 ( V_1 -> V_10 , V_5 , V_6 ) ;
}
int F_13 ( struct V_1 * V_1 , unsigned int V_5 ,
T_1 V_11 , T_1 V_6 )
{
F_14 ( V_6 & ~ V_11 ) ;
F_10 ( V_1 -> V_3 , L_5 ,
V_5 , V_6 , V_11 ) ;
return F_15 ( V_1 -> V_10 , V_5 , V_11 , V_6 ) ;
}
int F_16 ( struct V_1 * V_1 , int V_12 )
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
return F_11 ( V_1 , V_13 , V_11 | V_16 ) ;
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
if ( ! ( V_11 & V_16 ) )
return 0 ;
return F_11 ( V_1 , V_13 , V_11 & ~ V_16 ) ;
}
int F_18 ( struct V_1 * V_1 , int V_12 ,
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
int F_19 ( struct V_1 * V_1 , int V_12 )
{
unsigned int V_20 = V_12 < 24 ? V_21 : V_22 ;
unsigned int V_6 = 1 << ( V_12 < 24 ? V_12 : V_12 - 24 ) ;
F_14 ( V_12 < 0 || V_12 >= V_17 ) ;
return F_11 ( V_1 , V_20 , V_6 ) ;
}
int F_20 ( struct V_1 * V_1 , int V_12 ,
T_2 V_24 , const char * V_25 , void * V_3 )
{
F_14 ( ! F_21 ( & V_1 -> V_2 ) ) ;
F_14 ( ! V_24 ) ;
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
V_7 = F_20 ( V_1 , V_12 , V_24 , V_25 , V_3 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_17 ( V_1 , V_12 ) ;
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
F_14 ( ! F_21 ( & V_1 -> V_2 ) ) ;
if ( V_12 < 0 || V_12 >= V_17 || ! V_1 -> V_26 [ V_12 ] ||
V_1 -> V_28 [ V_12 ] != V_3 )
return - V_9 ;
V_7 = F_16 ( V_1 , V_12 ) ;
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
V_7 = F_11 ( V_1 , V_13 , V_11 ) ;
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
static void F_31 ( struct V_1 * V_1 , T_1 V_34 )
{
F_32 ( V_1 -> V_3 , L_7
L_8 ,
V_1 -> V_35 -> V_25 ,
F_33 ( V_34 , V_36 ) ,
F_33 ( V_34 , V_37 ) ,
F_33 ( V_34 , V_38 ) ,
F_33 ( V_34 , V_39 ) ,
F_33 ( V_34 , V_40 ) ,
F_33 ( V_34 , V_41 ) ) ;
}
static void F_34 ( struct V_1 * V_1 , T_1 V_34 )
{
F_32 ( V_1 -> V_3 , L_9 ,
V_1 -> V_35 -> V_25 ,
F_33 ( V_34 , V_42 ) ,
F_33 ( V_34 , V_43 ) ,
F_33 ( V_34 , V_44 ) ,
F_33 ( V_34 , V_45 ) ) ;
}
static const char * F_35 ( struct V_1 * V_1 )
{
return V_1 -> V_35 -> V_25 ;
}
int F_36 ( struct V_1 * V_1 )
{
return V_1 -> V_46 ;
}
static T_3 F_37 ( int V_12 , void * V_33 )
{
struct V_47 * V_48 = V_33 ;
F_19 ( V_48 -> V_1 , V_12 ) ;
F_38 ( & V_48 -> V_49 ) ;
return V_32 ;
}
int F_39 ( struct V_1 * V_1 , unsigned int V_50 ,
unsigned int V_51 , T_4 V_52 , bool V_53 ,
unsigned int * V_54 )
{
T_1 V_55 , V_56 , V_57 ;
int V_58 , V_7 ;
struct V_47 V_48 = {
. V_1 = V_1 ,
} ;
F_40 ( & V_48 . V_49 ) ;
F_3 ( V_1 -> V_3 , L_10 , V_4 ) ;
F_1 ( V_1 ) ;
if ( V_1 -> V_59 & V_60 ) {
V_7 = - V_27 ;
goto V_61;
}
V_1 -> V_59 |= V_60 ;
F_8 ( V_1 , V_62 , & V_57 ) ;
V_55 = V_63 | V_64 ;
V_56 = V_65 | V_66 | V_67 ;
if ( V_51 > 7 )
V_56 |= V_68 ;
switch ( V_50 ) {
case V_69 :
V_55 |= V_70 | V_71 |
V_72 ;
V_56 |= 4 << V_73 ;
break;
case V_74 :
V_55 |= V_57 & V_75 ;
V_56 |= ( V_51 & 0x7 ) << V_76 ;
V_56 |= V_77 ;
break;
case V_78 :
V_55 |= V_57 & V_75 ;
V_56 |= 4 << V_73 ;
break;
default:
F_6 ( V_1 ) ;
return - V_9 ;
}
V_56 |= V_52 << V_79 ;
if ( V_53 )
V_56 |= V_80 ;
F_3 ( V_1 -> V_3 , L_11 , V_4 ) ;
F_22 ( V_1 , V_81 ,
F_37 , V_4 , & V_48 ) ;
F_19 ( V_1 , V_81 ) ;
F_11 ( V_1 , V_62 , V_55 ) ;
F_11 ( V_1 , V_82 , V_56 ) ;
F_6 ( V_1 ) ;
V_7 = F_41 ( & V_48 . V_49 , V_83 ) ;
if ( ! V_7 )
V_7 = - V_84 ;
F_1 ( V_1 ) ;
F_23 ( V_1 , V_81 , & V_48 ) ;
if ( V_7 > 0 )
for ( V_58 = 0 ; V_58 < 4 ; ++ V_58 ) {
V_7 = F_8 ( V_1 ,
V_85 , & V_54 [ V_58 ] ) ;
if ( V_7 )
break;
}
if ( V_50 == V_69 )
F_11 ( V_1 , V_62 , V_57 ) ;
V_1 -> V_59 &= ~ V_60 ;
V_61:
F_6 ( V_1 ) ;
return V_7 ;
}
static int F_42 ( struct V_1 * V_1 ,
const char * V_86 , void * V_87 , T_5 V_88 )
{
char V_89 [ 30 ] ;
const char * V_25 = F_35 ( V_1 ) ;
struct V_90 V_91 = {
. V_92 = V_87 ,
. V_88 = V_88 ,
} ;
if ( snprintf ( V_89 , sizeof( V_89 ) , V_86 , V_25 ) > sizeof( V_89 ) )
return - V_93 ;
V_91 . V_25 = F_43 ( V_89 , strlen ( V_89 ) + 1 , V_94 ) ;
if ( ! V_91 . V_25 )
return - V_95 ;
return F_44 ( V_1 -> V_3 , - 1 , & V_91 , 1 , NULL , 0 , NULL ) ;
}
static int F_45 ( struct V_1 * V_1 , const char * V_86 )
{
return F_42 ( V_1 , V_86 , NULL , 0 ) ;
}
static int F_46 ( struct V_1 * V_1 )
{
struct V_96 * V_97 = V_1 -> V_3 -> V_98 ;
if ( ! V_97 )
return - V_99 ;
if ( F_47 ( V_97 , L_12 , NULL ) )
V_1 -> V_46 |= V_100 ;
if ( F_47 ( V_97 , L_13 , NULL ) )
V_1 -> V_46 |= V_101 ;
if ( F_47 ( V_97 , L_14 , NULL ) )
V_1 -> V_46 |= V_102 ;
if ( F_47 ( V_97 , L_15 , NULL ) )
V_1 -> V_46 |= V_103 ;
return 0 ;
}
static inline int F_46 ( struct V_1 * V_1 )
{
return - V_99 ;
}
int F_48 ( struct V_1 * V_1 ,
struct V_104 * V_87 , int V_12 )
{
int V_7 ;
T_1 V_34 ;
F_1 ( V_1 ) ;
V_7 = F_8 ( V_1 , V_105 , & V_34 ) ;
if ( V_7 )
goto V_106;
V_1 -> V_35 -> V_107 ( V_1 , V_34 ) ;
V_7 = F_11 ( V_1 , V_14 , 0x00ffffff ) ;
if ( V_7 )
goto V_108;
V_7 = F_11 ( V_1 , V_15 , 0x00ffffff ) ;
if ( V_7 )
goto V_108;
V_7 = F_49 ( V_12 , NULL , F_29 ,
V_109 | V_110 , L_16 , V_1 ) ;
if ( V_7 ) {
V_108:
V_106:
F_6 ( V_1 ) ;
return V_7 ;
}
V_1 -> V_12 = V_12 ;
F_6 ( V_1 ) ;
if ( F_46 ( V_1 ) < 0 && V_87 )
V_1 -> V_46 = V_87 -> V_46 ;
if ( V_1 -> V_46 & V_100 )
F_45 ( V_1 , L_17 ) ;
if ( V_1 -> V_46 & V_101 )
F_42 ( V_1 , L_18 ,
V_87 -> V_111 , sizeof( * V_87 -> V_111 ) ) ;
if ( V_1 -> V_46 & V_102 )
F_45 ( V_1 , L_19 ) ;
if ( V_1 -> V_46 & V_103 )
F_42 ( V_1 , L_20 ,
& V_87 -> V_112 , sizeof( V_87 -> V_112 ) ) ;
if ( V_87 ) {
F_42 ( V_1 , L_21 ,
& V_87 -> V_113 , sizeof( V_87 -> V_113 ) ) ;
F_42 ( V_1 , L_22 ,
V_87 -> V_114 , sizeof( * V_87 -> V_114 ) ) ;
F_42 ( V_1 , L_23 ,
V_87 -> V_115 , sizeof( * V_87 -> V_115 ) ) ;
} else {
F_45 ( V_1 , L_21 ) ;
F_45 ( V_1 , L_22 ) ;
F_45 ( V_1 , L_23 ) ;
}
return 0 ;
}
void F_50 ( struct V_1 * V_1 )
{
F_51 ( V_1 -> V_12 , V_1 ) ;
F_52 ( V_1 -> V_3 ) ;
}
