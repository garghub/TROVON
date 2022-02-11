static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 = V_5 | F_2 ( V_3 ) ;
int V_6 ;
F_3 ( V_2 -> V_7 , L_1 , V_4 ) ;
V_6 = F_4 ( V_2 -> V_8 , & V_4 , 1 ) ;
if ( V_6 )
F_5 ( V_2 -> V_7 , L_2 , V_9 , V_4 ,
V_6 ) ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_10 , T_1 * V_11 )
{
T_1 V_12 = V_13 | V_10 ;
int V_6 ;
V_6 = F_7 ( V_2 -> V_8 , & V_12 , 1 , V_11 , 1 ) ;
if ( V_6 )
F_5 ( V_2 -> V_7 , L_3 , V_9 , V_12 ,
V_6 ) ;
F_3 ( V_2 -> V_7 , L_4 , V_12 , * V_11 ) ;
return V_6 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_10 ,
T_1 * V_14 , T_2 V_15 )
{
T_1 V_12 = V_10 | V_13 | V_16 ;
int V_6 ;
F_3 ( V_2 -> V_7 , L_5 , V_12 , V_15 ) ;
V_6 = F_7 ( V_2 -> V_8 , & V_12 , 1 , V_14 , V_15 ) ;
if ( V_6 )
F_5 ( V_2 -> V_7 , L_3 , V_9 , V_12 ,
V_6 ) ;
return V_6 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_10 , T_1 V_11 )
{
T_1 V_14 [ 2 ] = { V_10 , V_11 } ;
int V_6 ;
F_3 ( V_2 -> V_7 , L_6 , V_10 , V_11 ) ;
V_6 = F_4 ( V_2 -> V_8 , V_14 , 2 ) ;
if ( V_6 )
F_5 ( V_2 -> V_7 , L_7 , V_9 ,
V_14 [ 0 ] , V_14 [ 1 ] , V_6 ) ;
return V_6 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 * V_17 )
{
int V_6 ;
T_1 V_14 [ 2 ] ;
T_1 V_12 ;
V_12 = V_18 | V_13 ;
if ( V_2 -> V_19 & V_20 ) {
V_12 |= V_16 ;
V_6 = F_7 ( V_2 -> V_8 , & V_12 , 1 , V_14 , 2 ) ;
} else {
V_6 = F_7 ( V_2 -> V_8 , & V_12 , 1 , V_14 , 1 ) ;
}
if ( V_6 )
F_5 ( V_2 -> V_7 , L_8 ,
V_9 , V_6 ) ;
else
* V_17 = V_14 [ 0 ] ;
return V_6 ;
}
static void F_11 ( struct V_1 * V_2 )
{
T_1 V_21 ;
F_12 ( V_2 -> V_22 ) ;
V_2 -> V_22 = NULL ;
if ( V_2 -> V_23 && ! F_13 ( V_2 -> V_23 ) && ! V_2 -> V_24 )
F_14 ( L_9 , V_25 ,
16 , 1 , V_2 -> V_23 -> V_26 , V_2 -> V_23 -> V_15 ,
false ) ;
F_1 ( V_2 , V_27 ) ;
F_6 ( V_2 , V_28 , & V_21 ) ;
V_2 -> V_29 = V_30 ;
if ( V_2 -> V_24 ) {
F_3 ( V_2 -> V_7 , L_10 ) ;
if ( ! F_13 ( V_2 -> V_23 ) ) {
F_15 ( V_2 -> V_23 ) ;
V_2 -> V_23 = F_16 ( - V_31 ) ;
}
V_2 -> V_24 = false ;
}
V_2 -> V_32 ( V_2 -> V_33 , V_2 -> V_34 , V_2 -> V_23 ) ;
V_2 -> V_23 = NULL ;
}
static void F_17 ( struct V_1 * V_2 , int V_35 )
{
F_3 ( V_2 -> V_7 , L_11 , V_2 -> V_29 , V_35 ) ;
F_15 ( V_2 -> V_23 ) ;
V_2 -> V_23 = F_16 ( V_35 ) ;
F_11 ( V_2 ) ;
}
static int F_18 ( struct V_1 * V_2 , struct V_36 * V_37 ,
unsigned int V_15 )
{
unsigned int V_38 ;
int V_6 ;
F_14 ( L_12 , V_25 ,
16 , 1 , V_37 -> V_26 , V_15 , false ) ;
V_6 = F_4 ( V_2 -> V_8 , V_37 -> V_26 , V_15 ) ;
if ( V_6 ) {
F_5 ( V_2 -> V_7 , L_13 , V_9 ,
V_6 ) ;
return V_6 ;
}
F_19 ( V_37 , V_15 ) ;
if ( V_37 -> V_15 > 0 ) {
V_2 -> V_29 = V_39 ;
V_38 = V_40 ;
} else {
if ( V_2 -> V_41 ) {
V_2 -> V_29 = V_42 ;
V_38 = V_43 ;
} else {
V_2 -> V_29 = V_44 ;
V_38 = V_2 -> V_38 ;
}
}
F_3 ( V_2 -> V_7 , L_14 , V_38 ,
V_2 -> V_29 ) ;
F_20 ( & V_2 -> V_45 , F_21 ( V_38 ) ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = V_2 -> V_22 ;
unsigned int V_15 ;
int V_6 ;
T_1 V_46 ;
V_6 = F_6 ( V_2 , V_47 , & V_46 ) ;
if ( V_6 ) {
F_17 ( V_2 , V_6 ) ;
return;
}
F_3 ( V_2 -> V_7 , L_15 , V_46 ) ;
if ( V_46 & V_48 ) {
F_5 ( V_2 -> V_7 , L_16 , V_9 ,
V_46 ) ;
F_17 ( V_2 , - V_49 ) ;
return;
}
V_15 = V_50 - V_46 ;
V_15 = F_23 ( V_37 -> V_15 , V_15 ) ;
V_6 = F_18 ( V_2 , V_37 , V_15 ) ;
if ( V_6 )
F_17 ( V_2 , V_6 ) ;
}
static void F_24 ( struct V_1 * V_2 , T_1 V_17 )
{
struct V_36 * V_37 = V_2 -> V_23 ;
int V_6 ;
T_1 V_46 ;
if ( V_17 & V_51 ) {
F_17 ( V_2 , - V_49 ) ;
return;
}
V_6 = F_6 ( V_2 , V_47 , & V_46 ) ;
if ( V_6 ) {
F_17 ( V_2 , V_6 ) ;
return;
}
F_3 ( V_2 -> V_7 , L_17 , V_46 ) ;
if ( ! V_46 )
goto V_52;
if ( V_46 & V_48 ) {
F_5 ( V_2 -> V_7 , L_16 , V_9 ,
V_46 ) ;
F_17 ( V_2 , - V_49 ) ;
return;
}
if ( V_46 > F_25 ( V_37 ) ) {
V_37 = F_26 ( V_37 , F_27 ( V_37 ) ,
F_28 ( int , V_46 ,
V_53 ) ,
V_54 ) ;
if ( ! V_37 ) {
F_17 ( V_2 , - V_55 ) ;
return;
}
F_15 ( V_2 -> V_23 ) ;
V_2 -> V_23 = V_37 ;
}
V_6 = F_8 ( V_2 , V_56 ,
F_29 ( V_37 , V_46 ) , V_46 ) ;
if ( V_6 ) {
F_17 ( V_2 , V_6 ) ;
return;
}
if ( ( V_2 -> V_57 == V_58 ) && ( V_37 -> V_15 == 1 ) &&
( V_2 -> V_59 ==
V_60 ) ) {
V_37 -> V_26 [ 0 ] >>= 4 ;
V_17 = V_61 ;
} else {
V_2 -> V_29 = V_62 ;
}
V_52:
if ( V_17 == V_61 ) {
F_11 ( V_2 ) ;
return;
}
F_3 ( V_2 -> V_7 , L_18 ,
V_63 ) ;
F_20 ( & V_2 -> V_45 ,
F_21 ( V_63 ) ) ;
}
static T_3 F_30 ( int V_64 , void * V_65 )
{
struct V_1 * V_2 = V_65 ;
int V_6 ;
T_1 V_17 ;
F_31 ( & V_2 -> V_66 ) ;
if ( V_2 -> V_29 == V_67 ) {
F_32 ( & V_2 -> V_66 ) ;
return V_68 ;
}
V_6 = F_10 ( V_2 , & V_17 ) ;
if ( V_6 ) {
F_32 ( & V_2 -> V_66 ) ;
return V_68 ;
}
F_3 ( V_2 -> V_7 , L_19 , V_2 -> V_29 ,
V_17 ) ;
if ( ! V_17 ) {
F_32 ( & V_2 -> V_66 ) ;
return V_68 ;
}
switch ( V_2 -> V_29 ) {
case V_30 :
case V_69 :
if ( V_17 & V_51 ) {
F_1 ( V_2 , V_70 ) ;
V_2 -> V_29 = V_69 ;
}
F_1 ( V_2 , V_27 ) ;
break;
case V_39 :
if ( V_17 & V_71 ) {
V_2 -> V_72 =
! F_33 ( & V_2 -> V_45 ) ;
F_22 ( V_2 ) ;
} else {
F_17 ( V_2 , - V_49 ) ;
}
break;
case V_44 :
case V_62 :
if ( V_17 & V_61 ) {
V_2 -> V_72 =
! F_33 ( & V_2 -> V_45 ) ;
F_24 ( V_2 , V_17 ) ;
} else if ( ! ( V_17 & V_71 ) ) {
F_17 ( V_2 , - V_49 ) ;
}
break;
case V_42 :
if ( V_17 != V_71 )
F_17 ( V_2 , - V_49 ) ;
break;
default:
F_5 ( V_2 -> V_7 , L_20 ,
V_9 , V_2 -> V_29 ) ;
}
F_32 ( & V_2 -> V_66 ) ;
return V_73 ;
}
static void F_34 ( struct V_1 * V_2 )
{
int V_6 ;
F_3 ( V_2 -> V_7 , L_21 ) ;
V_6 = F_1 ( V_2 , V_27 ) ;
if ( V_6 )
F_17 ( V_2 , V_6 ) ;
V_6 = F_1 ( V_2 , V_74 ) ;
if ( V_6 )
F_17 ( V_2 , V_6 ) ;
V_2 -> V_29 = V_44 ;
F_3 ( V_2 -> V_7 , L_14 ,
V_2 -> V_38 , V_2 -> V_29 ) ;
F_20 ( & V_2 -> V_45 ,
F_21 ( V_2 -> V_38 ) ) ;
}
static void F_35 ( struct V_75 * V_76 )
{
struct V_1 * V_2 = F_36 ( V_76 , struct V_1 ,
V_45 . V_76 ) ;
F_3 ( V_2 -> V_7 , L_22 ,
V_2 -> V_29 , V_2 -> V_72 ) ;
F_31 ( & V_2 -> V_66 ) ;
if ( V_2 -> V_72 )
V_2 -> V_72 = false ;
else if ( V_2 -> V_29 == V_62 )
F_11 ( V_2 ) ;
else if ( V_2 -> V_29 == V_42 )
F_34 ( V_2 ) ;
else
F_17 ( V_2 , - V_77 ) ;
F_32 ( & V_2 -> V_66 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_6 ;
F_3 ( V_2 -> V_7 , L_23 , V_2 -> V_29 ) ;
V_6 = F_1 ( V_2 , V_78 ) ;
if ( V_6 )
goto V_79;
V_6 = F_1 ( V_2 , V_80 ) ;
if ( V_6 )
goto V_79;
V_6 = F_9 ( V_2 , V_81 ,
V_82 ) ;
if ( V_6 )
goto V_79;
V_6 = F_9 ( V_2 , V_83 ,
V_84 |
V_85 ) ;
if ( V_6 )
goto V_79;
V_6 = F_9 ( V_2 , V_86 , 0 ) ;
if ( V_6 )
goto V_79;
V_2 -> V_59 = 0 ;
V_6 = F_9 ( V_2 , V_87 ,
V_88 |
V_89 ) ;
if ( V_6 )
goto V_79;
return 0 ;
V_79:
F_3 ( V_2 -> V_7 , L_24 , V_6 ) ;
return V_6 ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_3 ( V_2 -> V_7 , L_25 ) ;
F_39 ( V_2 -> V_90 , 0 ) ;
F_39 ( V_2 -> V_91 , 0 ) ;
V_2 -> V_24 = false ;
V_2 -> V_29 = V_67 ;
}
static int F_40 ( struct V_1 * V_2 )
{
unsigned long V_92 ;
int V_6 ;
F_3 ( V_2 -> V_7 , L_26 ) ;
if ( V_2 -> V_93 )
F_41 ( 5000 , 6000 ) ;
F_39 ( V_2 -> V_91 , 1 ) ;
F_41 ( 1000 , 2000 ) ;
F_39 ( V_2 -> V_90 , 1 ) ;
if ( V_2 -> V_93 ) {
V_92 = 20000 ;
V_2 -> V_93 = false ;
} else {
V_92 = 5000 ;
}
F_41 ( V_92 , V_92 + 1000 ) ;
V_6 = F_37 ( V_2 ) ;
if ( V_6 )
F_38 ( V_2 ) ;
else
V_2 -> V_29 = V_30 ;
return V_6 ;
}
static int F_42 ( struct V_94 * V_33 , bool V_95 )
{
struct V_1 * V_2 = F_43 ( V_33 ) ;
int V_6 = 0 ;
F_3 ( V_2 -> V_7 , L_27 , V_2 -> V_29 , V_95 ) ;
F_31 ( & V_2 -> V_66 ) ;
if ( V_95 ) {
switch ( V_2 -> V_29 ) {
case V_67 :
V_6 = F_40 ( V_2 ) ;
break;
case V_30 :
case V_69 :
break;
default:
F_5 ( V_2 -> V_7 , L_28 ,
V_9 , V_2 -> V_29 , V_95 ) ;
F_38 ( V_2 ) ;
}
} else {
switch ( V_2 -> V_29 ) {
case V_67 :
break;
default:
F_5 ( V_2 -> V_7 , L_28 ,
V_9 , V_2 -> V_29 , V_95 ) ;
case V_30 :
case V_69 :
F_38 ( V_2 ) ;
}
}
F_32 ( & V_2 -> V_66 ) ;
return V_6 ;
}
static int F_44 ( struct V_1 * V_2 , int V_96 )
{
int V_6 = 0 ;
F_3 ( V_2 -> V_7 , L_29 , V_96 ) ;
switch ( V_96 ) {
case V_97 :
V_2 -> V_98 = V_99 ;
break;
case V_100 :
V_2 -> V_98 = V_101 ;
break;
default:
F_3 ( V_2 -> V_7 , L_30 , V_96 ) ;
return - V_102 ;
}
V_2 -> V_103 = V_96 ;
return V_6 ;
}
static int F_45 ( struct V_1 * V_2 , int V_57 )
{
F_3 ( V_2 -> V_7 , L_31 , V_57 ) ;
switch ( V_57 ) {
case V_104 :
case V_105 :
V_2 -> V_106 = V_107 ;
V_2 -> V_98 |= V_108 ;
break;
case V_109 :
case V_110 :
case V_111 :
case V_112 :
V_2 -> V_106 = V_113 ;
V_2 -> V_98 &= ~ V_108 ;
break;
case V_58 :
V_2 -> V_106 = V_113 ;
V_2 -> V_98 |= V_108 ;
break;
default:
F_3 ( V_2 -> V_7 , L_32 , V_57 ) ;
return - V_102 ;
}
V_2 -> V_57 = V_57 ;
return F_9 ( V_2 , V_114 , V_2 -> V_98 ) ;
}
static int F_46 ( struct V_94 * V_33 , int type ,
int V_115 )
{
struct V_1 * V_2 = F_43 ( V_33 ) ;
int V_6 = 0 ;
F_3 ( V_2 -> V_7 , L_33 , type , V_115 ) ;
F_31 ( & V_2 -> V_66 ) ;
if ( V_2 -> V_29 == V_67 ) {
V_6 = F_40 ( V_2 ) ;
if ( V_6 )
goto V_79;
}
switch ( type ) {
case V_116 :
V_6 = F_44 ( V_2 , V_115 ) ;
break;
case V_117 :
V_6 = F_45 ( V_2 , V_115 ) ;
break;
default:
F_3 ( V_2 -> V_7 , L_34 , type ) ;
V_6 = - V_102 ;
}
V_79:
F_32 ( & V_2 -> V_66 ) ;
return V_6 ;
}
static int F_47 ( T_1 V_4 )
{
switch ( V_4 ) {
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
return 1 ;
break;
default:
return 0 ;
}
}
static int F_48 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
T_1 * V_125 = V_37 -> V_26 ;
T_1 V_59 , V_98 ;
int V_6 ;
V_2 -> V_41 = false ;
if ( ( V_2 -> V_103 == V_97 ) &&
( V_2 -> V_57 == V_58 ) ) {
if ( V_125 [ 0 ] == V_126 )
V_59 = 0 ;
else
V_59 = V_60 ;
if ( V_59 != V_2 -> V_59 ) {
V_6 = F_9 ( V_2 , V_86 ,
V_59 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_59 = V_59 ;
}
} else if ( V_2 -> V_103 == V_100 ) {
V_98 = V_2 -> V_98 & ~ V_127 ;
switch ( V_125 [ 0 ] & V_128 ) {
case 0x00 :
V_98 |= V_129 ;
break;
case V_130 :
V_98 |= V_131 ;
break;
case V_132 :
V_98 |= V_101 ;
break;
case ( V_130 |
V_132 ) :
V_98 |= V_133 ;
break;
}
if ( V_98 != V_2 -> V_98 ) {
V_6 = F_9 ( V_2 , V_114 , V_98 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_98 = V_98 ;
}
if ( ( V_2 -> V_57 == V_112 ) &&
F_47 ( V_125 [ 1 ] ) &&
( V_125 [ 0 ] & V_134 ) )
V_2 -> V_41 = true ;
}
return 0 ;
}
static int F_49 ( struct V_94 * V_33 ,
struct V_36 * V_37 , T_4 V_38 ,
T_5 V_32 , void * V_135 )
{
struct V_1 * V_2 = F_43 ( V_33 ) ;
char * V_136 ;
unsigned int V_15 ;
int V_6 ;
F_3 ( V_2 -> V_7 , L_35 ,
V_2 -> V_29 , V_38 , V_37 -> V_15 ) ;
if ( V_37 -> V_15 > V_137 )
return - V_102 ;
F_31 ( & V_2 -> V_66 ) ;
if ( ( V_2 -> V_29 != V_30 ) &&
( V_2 -> V_29 != V_69 ) ) {
F_5 ( V_2 -> V_7 , L_36 , V_9 ,
V_2 -> V_29 ) ;
V_6 = - V_49 ;
goto V_138;
}
if ( V_2 -> V_24 ) {
F_3 ( V_2 -> V_7 , L_10 ) ;
V_2 -> V_24 = false ;
V_6 = - V_31 ;
goto V_138;
}
V_2 -> V_23 = F_50 ( V_53 ,
V_54 ) ;
if ( ! V_2 -> V_23 ) {
F_3 ( V_2 -> V_7 , L_37 ) ;
V_6 = - V_55 ;
goto V_138;
}
if ( V_2 -> V_29 == V_69 ) {
V_6 = F_1 ( V_2 , V_139 ) ;
if ( V_6 )
goto V_138;
V_2 -> V_29 = V_30 ;
}
V_6 = F_48 ( V_2 , V_37 ) ;
if ( V_6 )
goto V_138;
V_2 -> V_33 = V_33 ;
V_2 -> V_22 = V_37 ;
V_2 -> V_32 = V_32 ;
V_2 -> V_34 = V_135 ;
V_2 -> V_38 = V_38 ;
V_2 -> V_72 = false ;
V_15 = V_37 -> V_15 ;
V_136 = F_51 ( V_37 , V_140 ) ;
V_136 [ 0 ] = V_5 |
F_2 ( V_27 ) ;
V_136 [ 1 ] = V_5 |
F_2 ( V_2 -> V_106 ) ;
V_136 [ 2 ] = V_16 | V_141 ;
if ( V_2 -> V_57 == V_104 ) {
V_136 [ 3 ] = 0x00 ;
V_136 [ 4 ] = 0x0f ;
} else {
V_136 [ 3 ] = ( V_15 & 0xf00 ) >> 4 ;
V_136 [ 3 ] |= ( ( V_15 & 0xf0 ) >> 4 ) ;
V_136 [ 4 ] = ( ( V_15 & 0x0f ) << 4 ) ;
}
V_15 = F_52 ( int , V_37 -> V_15 , V_50 ) ;
F_41 ( 1000 , 2000 ) ;
V_6 = F_18 ( V_2 , V_37 , V_15 ) ;
if ( V_6 ) {
F_15 ( V_2 -> V_23 ) ;
V_2 -> V_23 = NULL ;
}
V_138:
F_32 ( & V_2 -> V_66 ) ;
return V_6 ;
}
static int F_53 ( struct V_94 * V_33 ,
int type , int V_115 )
{
struct V_1 * V_2 = F_43 ( V_33 ) ;
F_3 ( V_2 -> V_7 , L_38 ) ;
return - V_102 ;
}
static int F_54 ( struct V_94 * V_33 ,
struct V_36 * V_37 , T_4 V_38 ,
T_5 V_32 , void * V_135 )
{
struct V_1 * V_2 = F_43 ( V_33 ) ;
F_3 ( V_2 -> V_7 , L_38 ) ;
return - V_102 ;
}
static int F_55 ( struct V_94 * V_33 ,
T_4 V_38 , T_5 V_32 , void * V_135 )
{
struct V_1 * V_2 = F_43 ( V_33 ) ;
F_3 ( V_2 -> V_7 , L_38 ) ;
return - V_102 ;
}
static int F_56 ( struct V_94 * V_33 ,
struct V_142 * V_143 ,
T_4 V_38 , T_5 V_32 , void * V_135 )
{
struct V_1 * V_2 = F_43 ( V_33 ) ;
F_3 ( V_2 -> V_7 , L_38 ) ;
return - V_102 ;
}
static void F_57 ( struct V_94 * V_33 )
{
struct V_1 * V_2 = F_43 ( V_33 ) ;
F_3 ( V_2 -> V_7 , L_39 ) ;
F_31 ( & V_2 -> V_66 ) ;
V_2 -> V_24 = true ;
F_32 ( & V_2 -> V_66 ) ;
}
static int F_58 ( struct V_144 * V_8 )
{
struct V_145 * V_146 = V_8 -> V_7 . V_147 ;
const struct V_148 * V_149 = F_59 ( V_8 ) ;
struct V_1 * V_2 ;
int V_6 ;
if ( ! V_146 ) {
F_5 ( & V_8 -> V_7 , L_40 ) ;
return - V_102 ;
}
V_2 = F_60 ( & V_8 -> V_7 , sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_55 ;
V_2 -> V_29 = V_67 ;
V_2 -> V_7 = & V_8 -> V_7 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_19 = V_149 -> V_150 ;
V_8 -> V_151 = V_152 ;
V_8 -> V_153 = 8 ;
V_2 -> V_90 = F_61 ( V_146 , L_41 , 0 ) ;
if ( ! F_62 ( V_2 -> V_90 ) ) {
F_5 ( V_2 -> V_7 , L_42 ) ;
return V_2 -> V_90 ;
}
V_6 = F_63 ( V_2 -> V_7 , V_2 -> V_90 ,
V_154 | V_155 , L_43 ) ;
if ( V_6 ) {
F_5 ( V_2 -> V_7 , L_44 , V_6 ) ;
return V_6 ;
}
V_2 -> V_91 = F_61 ( V_146 , L_41 , 1 ) ;
if ( ! F_62 ( V_2 -> V_91 ) ) {
F_5 ( V_2 -> V_7 , L_45 ) ;
return V_2 -> V_91 ;
}
V_6 = F_63 ( V_2 -> V_7 , V_2 -> V_91 ,
V_154 | V_155 , L_46 ) ;
if ( V_6 ) {
F_5 ( V_2 -> V_7 , L_47 , V_6 ) ;
return V_6 ;
}
V_6 = F_64 ( V_2 -> V_7 , V_8 -> V_64 , NULL ,
F_30 , V_156 | V_157 ,
L_48 , V_2 ) ;
if ( V_6 ) {
F_5 ( V_2 -> V_7 , L_49 , V_8 -> V_64 , V_6 ) ;
return V_6 ;
}
F_65 ( & V_2 -> V_66 ) ;
F_66 ( & V_2 -> V_45 , F_35 ) ;
V_2 -> V_158 = F_67 ( & V_8 -> V_7 , L_50 ) ;
if ( F_13 ( V_2 -> V_158 ) ) {
V_6 = F_68 ( V_2 -> V_158 ) ;
F_5 ( V_2 -> V_7 , L_51 , V_6 ) ;
goto V_159;
}
V_6 = F_69 ( V_2 -> V_158 ) ;
if ( V_6 ) {
F_5 ( V_2 -> V_7 , L_52 , V_6 ) ;
goto V_159;
}
V_2 -> V_93 = true ;
V_2 -> V_33 = F_70 ( & V_160 ,
V_161 ,
V_162 , V_140 ,
0 ) ;
if ( ! V_2 -> V_33 ) {
F_5 ( V_2 -> V_7 , L_53 ) ;
V_6 = - V_55 ;
goto V_163;
}
F_71 ( V_2 -> V_33 , V_2 -> V_7 ) ;
F_72 ( V_2 -> V_33 , V_2 ) ;
F_73 ( V_8 , V_2 ) ;
V_6 = F_74 ( V_2 -> V_33 ) ;
if ( V_6 ) {
F_5 ( V_2 -> V_7 , L_54 ,
V_6 ) ;
goto V_164;
}
return 0 ;
V_164:
F_75 ( V_2 -> V_33 ) ;
V_163:
F_76 ( V_2 -> V_158 ) ;
V_159:
F_77 ( & V_2 -> V_66 ) ;
return V_6 ;
}
static int F_78 ( struct V_144 * V_8 )
{
struct V_1 * V_2 = F_79 ( V_8 ) ;
F_31 ( & V_2 -> V_66 ) ;
F_38 ( V_2 ) ;
F_37 ( V_2 ) ;
switch ( V_2 -> V_29 ) {
case V_39 :
case V_44 :
case V_62 :
case V_42 :
F_17 ( V_2 , - V_31 ) ;
break;
default:
break;
}
F_32 ( & V_2 -> V_66 ) ;
F_80 ( V_2 -> V_33 ) ;
F_75 ( V_2 -> V_33 ) ;
F_76 ( V_2 -> V_158 ) ;
F_77 ( & V_2 -> V_66 ) ;
return 0 ;
}
