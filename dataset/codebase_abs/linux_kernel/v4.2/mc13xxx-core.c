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
int V_12 = F_18 ( V_1 -> V_13 , V_11 ) ;
F_19 ( V_12 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_1 , int V_11 )
{
int V_12 = F_18 ( V_1 -> V_13 , V_11 ) ;
F_21 ( V_12 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_1 , int V_11 ,
int * V_14 , int * V_15 )
{
int V_7 ;
unsigned int V_16 = V_11 < 24 ? V_17 : V_18 ;
unsigned int V_19 = V_11 < 24 ? V_20 : V_21 ;
T_1 V_22 = 1 << ( V_11 < 24 ? V_11 : V_11 - 24 ) ;
if ( V_11 < 0 || V_11 >= F_23 ( V_1 -> V_23 ) )
return - V_9 ;
if ( V_14 ) {
T_1 V_10 ;
V_7 = F_8 ( V_1 , V_16 , & V_10 ) ;
if ( V_7 )
return V_7 ;
* V_14 = V_10 & V_22 ;
}
if ( V_15 ) {
T_1 V_24 ;
V_7 = F_8 ( V_1 , V_19 , & V_24 ) ;
if ( V_7 )
return V_7 ;
* V_15 = V_24 & V_22 ;
}
return 0 ;
}
int F_24 ( struct V_1 * V_1 , int V_11 ,
T_2 V_25 , const char * V_26 , void * V_3 )
{
int V_12 = F_18 ( V_1 -> V_13 , V_11 ) ;
return F_25 ( V_1 -> V_3 , V_12 , NULL , V_25 ,
V_27 , V_26 , V_3 ) ;
}
int F_26 ( struct V_1 * V_1 , int V_11 , void * V_3 )
{
int V_12 = F_18 ( V_1 -> V_13 , V_11 ) ;
F_27 ( V_1 -> V_3 , V_12 , V_3 ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_1 , T_1 V_28 )
{
F_29 ( V_1 -> V_3 , L_6
L_7 ,
V_1 -> V_29 -> V_26 ,
F_30 ( V_28 , V_30 ) ,
F_30 ( V_28 , V_31 ) ,
F_30 ( V_28 , V_32 ) ,
F_30 ( V_28 , V_33 ) ,
F_30 ( V_28 , V_34 ) ,
F_30 ( V_28 , V_35 ) ) ;
}
static void F_31 ( struct V_1 * V_1 , T_1 V_28 )
{
F_29 ( V_1 -> V_3 , L_8 ,
V_1 -> V_29 -> V_26 ,
F_30 ( V_28 , V_36 ) ,
F_30 ( V_28 , V_37 ) ,
F_30 ( V_28 , V_38 ) ,
F_30 ( V_28 , V_39 ) ) ;
}
static const char * F_32 ( struct V_1 * V_1 )
{
return V_1 -> V_29 -> V_26 ;
}
int F_33 ( struct V_1 * V_1 )
{
return V_1 -> V_40 ;
}
static T_3 F_34 ( int V_11 , void * V_41 )
{
struct V_42 * V_43 = V_41 ;
F_35 ( & V_43 -> V_44 ) ;
return V_45 ;
}
int F_36 ( struct V_1 * V_1 , unsigned int V_46 ,
unsigned int V_47 , T_4 V_48 , bool V_49 ,
unsigned int * V_50 )
{
T_1 V_51 , V_52 , V_53 ;
int V_54 , V_7 ;
struct V_42 V_43 = {
. V_1 = V_1 ,
} ;
F_37 ( & V_43 . V_44 ) ;
F_3 ( V_1 -> V_3 , L_9 , V_4 ) ;
F_1 ( V_1 ) ;
if ( V_1 -> V_55 & V_56 ) {
V_7 = - V_57 ;
goto V_58;
}
V_1 -> V_55 |= V_56 ;
F_8 ( V_1 , V_59 , & V_53 ) ;
V_51 = V_60 | V_61 ;
V_52 = V_62 | V_63 | V_64 ;
if ( V_47 > 7 )
V_52 |= V_65 ;
switch ( V_46 ) {
case V_66 :
V_51 |= V_67 | V_68 |
V_69 ;
V_52 |= 4 << V_70 ;
break;
case V_71 :
V_51 |= V_53 & V_72 ;
V_52 |= ( V_47 & 0x7 ) << V_73 ;
V_52 |= V_74 ;
break;
case V_75 :
V_51 |= V_53 & V_72 ;
V_52 |= 4 << V_70 ;
break;
default:
F_6 ( V_1 ) ;
return - V_9 ;
}
V_52 |= V_48 << V_76 ;
if ( V_49 )
V_52 |= V_77 ;
F_3 ( V_1 -> V_3 , L_10 , V_4 ) ;
F_24 ( V_1 , V_78 ,
F_34 , V_4 , & V_43 ) ;
F_11 ( V_1 , V_59 , V_51 ) ;
F_11 ( V_1 , V_79 , V_52 ) ;
F_6 ( V_1 ) ;
V_7 = F_38 ( & V_43 . V_44 , V_80 ) ;
if ( ! V_7 )
V_7 = - V_81 ;
F_1 ( V_1 ) ;
F_26 ( V_1 , V_78 , & V_43 ) ;
if ( V_7 > 0 )
for ( V_54 = 0 ; V_54 < 4 ; ++ V_54 ) {
V_7 = F_8 ( V_1 ,
V_82 , & V_50 [ V_54 ] ) ;
if ( V_7 )
break;
}
if ( V_46 == V_66 )
F_11 ( V_1 , V_59 , V_53 ) ;
V_1 -> V_55 &= ~ V_56 ;
V_58:
F_6 ( V_1 ) ;
return V_7 ;
}
static int F_39 ( struct V_1 * V_1 ,
const char * V_83 , void * V_84 , T_5 V_85 )
{
char V_86 [ 30 ] ;
const char * V_26 = F_32 ( V_1 ) ;
struct V_87 V_88 = {
. V_89 = V_84 ,
. V_85 = V_85 ,
} ;
if ( snprintf ( V_86 , sizeof( V_86 ) , V_83 , V_26 ) > sizeof( V_86 ) )
return - V_90 ;
V_88 . V_26 = F_40 ( V_86 , strlen ( V_86 ) + 1 , V_91 ) ;
if ( ! V_88 . V_26 )
return - V_92 ;
return F_41 ( V_1 -> V_3 , - 1 , & V_88 , 1 , NULL , 0 ,
F_42 ( V_1 -> V_13 ) ) ;
}
static int F_43 ( struct V_1 * V_1 , const char * V_83 )
{
return F_39 ( V_1 , V_83 , NULL , 0 ) ;
}
static int F_44 ( struct V_1 * V_1 )
{
struct V_93 * V_94 = V_1 -> V_3 -> V_95 ;
if ( ! V_94 )
return - V_96 ;
if ( F_45 ( V_94 , L_11 , NULL ) )
V_1 -> V_40 |= V_97 ;
if ( F_45 ( V_94 , L_12 , NULL ) )
V_1 -> V_40 |= V_98 ;
if ( F_45 ( V_94 , L_13 , NULL ) )
V_1 -> V_40 |= V_99 ;
if ( F_45 ( V_94 , L_14 , NULL ) )
V_1 -> V_40 |= V_100 ;
return 0 ;
}
static inline int F_44 ( struct V_1 * V_1 )
{
return - V_96 ;
}
int F_46 ( struct V_101 * V_3 )
{
struct V_102 * V_84 = F_47 ( V_3 ) ;
struct V_1 * V_1 = F_48 ( V_3 ) ;
T_1 V_28 ;
int V_54 , V_7 ;
V_1 -> V_3 = V_3 ;
V_7 = F_8 ( V_1 , V_103 , & V_28 ) ;
if ( V_7 )
return V_7 ;
V_1 -> V_29 -> V_104 ( V_1 , V_28 ) ;
V_7 = F_14 ( V_1 , V_105 ,
V_106 , V_106 ) ;
if ( V_7 )
return V_7 ;
for ( V_54 = 0 ; V_54 < F_23 ( V_1 -> V_23 ) ; V_54 ++ ) {
V_1 -> V_23 [ V_54 ] . V_107 = V_54 / V_108 ;
V_1 -> V_23 [ V_54 ] . V_10 = F_12 ( V_54 % V_108 ) ;
}
V_1 -> V_109 . V_26 = F_49 ( V_3 ) ;
V_1 -> V_109 . V_110 = V_20 ;
V_1 -> V_109 . V_111 = V_17 ;
V_1 -> V_109 . V_112 = V_20 ;
V_1 -> V_109 . V_113 = V_21 - V_20 ;
V_1 -> V_109 . V_114 = true ;
V_1 -> V_109 . V_115 = true ;
V_1 -> V_109 . V_116 = V_117 ;
V_1 -> V_109 . V_23 = V_1 -> V_23 ;
V_1 -> V_109 . V_118 = F_23 ( V_1 -> V_23 ) ;
V_7 = F_50 ( V_1 -> V_8 , V_1 -> V_11 , V_27 ,
0 , & V_1 -> V_109 , & V_1 -> V_13 ) ;
if ( V_7 )
return V_7 ;
F_51 ( & V_1 -> V_2 ) ;
if ( F_44 ( V_1 ) < 0 && V_84 )
V_1 -> V_40 = V_84 -> V_40 ;
if ( V_84 ) {
F_39 ( V_1 , L_15 ,
& V_84 -> V_119 , sizeof( V_84 -> V_119 ) ) ;
F_39 ( V_1 , L_16 ,
V_84 -> V_120 , sizeof( * V_84 -> V_120 ) ) ;
F_39 ( V_1 , L_17 ,
V_84 -> V_121 , sizeof( * V_84 -> V_121 ) ) ;
if ( V_1 -> V_40 & V_98 )
F_39 ( V_1 , L_18 ,
V_84 -> V_122 , sizeof( * V_84 -> V_122 ) ) ;
if ( V_1 -> V_40 & V_100 )
F_39 ( V_1 , L_19 ,
& V_84 -> V_123 , sizeof( V_84 -> V_123 ) ) ;
} else {
F_43 ( V_1 , L_15 ) ;
F_43 ( V_1 , L_16 ) ;
F_43 ( V_1 , L_17 ) ;
if ( V_1 -> V_40 & V_98 )
F_43 ( V_1 , L_18 ) ;
if ( V_1 -> V_40 & V_100 )
F_43 ( V_1 , L_19 ) ;
}
if ( V_1 -> V_40 & V_97 )
F_43 ( V_1 , L_20 ) ;
if ( V_1 -> V_40 & V_99 )
F_43 ( V_1 , L_21 ) ;
return 0 ;
}
int F_52 ( struct V_101 * V_3 )
{
struct V_1 * V_1 = F_48 ( V_3 ) ;
F_53 ( V_3 ) ;
F_54 ( V_1 -> V_11 , V_1 -> V_13 ) ;
F_55 ( & V_1 -> V_2 ) ;
return 0 ;
}
