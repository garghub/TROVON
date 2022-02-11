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
0 , V_26 , V_3 ) ;
}
int F_26 ( struct V_1 * V_1 , int V_11 , void * V_3 )
{
int V_12 = F_18 ( V_1 -> V_13 , V_11 ) ;
F_27 ( V_1 -> V_3 , V_12 , V_3 ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_1 , T_1 V_27 )
{
F_29 ( V_1 -> V_3 , L_6
L_7 ,
V_1 -> V_28 -> V_26 ,
F_30 ( V_27 , V_29 ) ,
F_30 ( V_27 , V_30 ) ,
F_30 ( V_27 , V_31 ) ,
F_30 ( V_27 , V_32 ) ,
F_30 ( V_27 , V_33 ) ,
F_30 ( V_27 , V_34 ) ) ;
}
static void F_31 ( struct V_1 * V_1 , T_1 V_27 )
{
F_29 ( V_1 -> V_3 , L_8 ,
V_1 -> V_28 -> V_26 ,
F_30 ( V_27 , V_35 ) ,
F_30 ( V_27 , V_36 ) ,
F_30 ( V_27 , V_37 ) ,
F_30 ( V_27 , V_38 ) ) ;
}
static const char * F_32 ( struct V_1 * V_1 )
{
return V_1 -> V_28 -> V_26 ;
}
int F_33 ( struct V_1 * V_1 )
{
return V_1 -> V_39 ;
}
static T_3 F_34 ( int V_11 , void * V_40 )
{
struct V_41 * V_42 = V_40 ;
F_35 ( & V_42 -> V_43 ) ;
return V_44 ;
}
int F_36 ( struct V_1 * V_1 , unsigned int V_45 ,
unsigned int V_46 , T_4 V_47 , bool V_48 ,
unsigned int * V_49 )
{
T_1 V_50 , V_51 , V_52 ;
int V_53 , V_7 ;
struct V_41 V_42 = {
. V_1 = V_1 ,
} ;
F_37 ( & V_42 . V_43 ) ;
F_3 ( V_1 -> V_3 , L_9 , V_4 ) ;
F_1 ( V_1 ) ;
if ( V_1 -> V_54 & V_55 ) {
V_7 = - V_56 ;
goto V_57;
}
V_1 -> V_54 |= V_55 ;
F_8 ( V_1 , V_58 , & V_52 ) ;
V_50 = V_59 | V_60 ;
V_51 = V_61 | V_62 | V_63 ;
if ( V_46 > 7 )
V_51 |= V_64 ;
switch ( V_45 ) {
case V_65 :
V_50 |= V_66 | V_67 |
V_68 ;
V_51 |= 4 << V_69 ;
break;
case V_70 :
V_50 |= V_52 & V_71 ;
V_51 |= ( V_46 & 0x7 ) << V_72 ;
V_51 |= V_73 ;
break;
case V_74 :
V_50 |= V_52 & V_71 ;
V_51 |= 4 << V_69 ;
break;
default:
F_6 ( V_1 ) ;
return - V_9 ;
}
V_51 |= V_47 << V_75 ;
if ( V_48 )
V_51 |= V_76 ;
F_3 ( V_1 -> V_3 , L_10 , V_4 ) ;
F_24 ( V_1 , V_77 ,
F_34 , V_4 , & V_42 ) ;
F_11 ( V_1 , V_58 , V_50 ) ;
F_11 ( V_1 , V_78 , V_51 ) ;
F_6 ( V_1 ) ;
V_7 = F_38 ( & V_42 . V_43 , V_79 ) ;
if ( ! V_7 )
V_7 = - V_80 ;
F_1 ( V_1 ) ;
F_26 ( V_1 , V_77 , & V_42 ) ;
if ( V_7 > 0 )
for ( V_53 = 0 ; V_53 < 4 ; ++ V_53 ) {
V_7 = F_8 ( V_1 ,
V_81 , & V_49 [ V_53 ] ) ;
if ( V_7 )
break;
}
if ( V_45 == V_65 )
F_11 ( V_1 , V_58 , V_52 ) ;
V_1 -> V_54 &= ~ V_55 ;
V_57:
F_6 ( V_1 ) ;
return V_7 ;
}
static int F_39 ( struct V_1 * V_1 ,
const char * V_82 , void * V_83 , T_5 V_84 )
{
char V_85 [ 30 ] ;
const char * V_26 = F_32 ( V_1 ) ;
struct V_86 V_87 = {
. V_88 = V_83 ,
. V_84 = V_84 ,
} ;
if ( snprintf ( V_85 , sizeof( V_85 ) , V_82 , V_26 ) > sizeof( V_85 ) )
return - V_89 ;
V_87 . V_26 = F_40 ( V_85 , strlen ( V_85 ) + 1 , V_90 ) ;
if ( ! V_87 . V_26 )
return - V_91 ;
return F_41 ( V_1 -> V_3 , - 1 , & V_87 , 1 , NULL , 0 ,
F_42 ( V_1 -> V_13 ) ) ;
}
static int F_43 ( struct V_1 * V_1 , const char * V_82 )
{
return F_39 ( V_1 , V_82 , NULL , 0 ) ;
}
static int F_44 ( struct V_1 * V_1 )
{
struct V_92 * V_93 = V_1 -> V_3 -> V_94 ;
if ( ! V_93 )
return - V_95 ;
if ( F_45 ( V_93 , L_11 , NULL ) )
V_1 -> V_39 |= V_96 ;
if ( F_45 ( V_93 , L_12 , NULL ) )
V_1 -> V_39 |= V_97 ;
if ( F_45 ( V_93 , L_13 , NULL ) )
V_1 -> V_39 |= V_98 ;
if ( F_45 ( V_93 , L_14 , NULL ) )
V_1 -> V_39 |= V_99 ;
return 0 ;
}
static inline int F_44 ( struct V_1 * V_1 )
{
return - V_95 ;
}
int F_46 ( struct V_100 * V_3 )
{
struct V_101 * V_83 = F_47 ( V_3 ) ;
struct V_1 * V_1 = F_48 ( V_3 ) ;
T_1 V_27 ;
int V_53 , V_7 ;
V_1 -> V_3 = V_3 ;
V_7 = F_8 ( V_1 , V_102 , & V_27 ) ;
if ( V_7 )
return V_7 ;
V_1 -> V_28 -> V_103 ( V_1 , V_27 ) ;
V_7 = F_14 ( V_1 , V_104 ,
V_105 , V_105 ) ;
if ( V_7 )
return V_7 ;
for ( V_53 = 0 ; V_53 < F_23 ( V_1 -> V_23 ) ; V_53 ++ ) {
V_1 -> V_23 [ V_53 ] . V_106 = V_53 / V_107 ;
V_1 -> V_23 [ V_53 ] . V_10 = F_12 ( V_53 % V_107 ) ;
}
V_1 -> V_108 . V_26 = F_49 ( V_3 ) ;
V_1 -> V_108 . V_109 = V_20 ;
V_1 -> V_108 . V_110 = V_17 ;
V_1 -> V_108 . V_111 = V_20 ;
V_1 -> V_108 . V_112 = V_21 - V_20 ;
V_1 -> V_108 . V_113 = true ;
V_1 -> V_108 . V_114 = true ;
V_1 -> V_108 . V_115 = V_116 ;
V_1 -> V_108 . V_23 = V_1 -> V_23 ;
V_1 -> V_108 . V_117 = F_23 ( V_1 -> V_23 ) ;
V_7 = F_50 ( V_1 -> V_8 , V_1 -> V_11 , V_118 ,
0 , & V_1 -> V_108 , & V_1 -> V_13 ) ;
if ( V_7 )
return V_7 ;
F_51 ( & V_1 -> V_2 ) ;
if ( F_44 ( V_1 ) < 0 && V_83 )
V_1 -> V_39 = V_83 -> V_39 ;
if ( V_83 ) {
F_39 ( V_1 , L_15 ,
& V_83 -> V_119 , sizeof( V_83 -> V_119 ) ) ;
F_39 ( V_1 , L_16 ,
V_83 -> V_120 , sizeof( * V_83 -> V_120 ) ) ;
F_39 ( V_1 , L_17 ,
V_83 -> V_121 , sizeof( * V_83 -> V_121 ) ) ;
if ( V_1 -> V_39 & V_97 )
F_39 ( V_1 , L_18 ,
V_83 -> V_122 , sizeof( * V_83 -> V_122 ) ) ;
if ( V_1 -> V_39 & V_99 )
F_39 ( V_1 , L_19 ,
& V_83 -> V_123 , sizeof( V_83 -> V_123 ) ) ;
} else {
F_43 ( V_1 , L_15 ) ;
F_43 ( V_1 , L_16 ) ;
F_43 ( V_1 , L_17 ) ;
if ( V_1 -> V_39 & V_97 )
F_43 ( V_1 , L_18 ) ;
if ( V_1 -> V_39 & V_99 )
F_43 ( V_1 , L_19 ) ;
}
if ( V_1 -> V_39 & V_96 )
F_43 ( V_1 , L_20 ) ;
if ( V_1 -> V_39 & V_98 )
F_43 ( V_1 , L_21 ) ;
return 0 ;
}
int F_52 ( struct V_100 * V_3 )
{
struct V_1 * V_1 = F_48 ( V_3 ) ;
F_53 ( V_3 ) ;
F_54 ( V_1 -> V_11 , V_1 -> V_13 ) ;
F_55 ( & V_1 -> V_2 ) ;
return 0 ;
}
