static inline void F_1 ( void T_1 * V_1 , int V_2 , T_2 V_3 )
{
F_2 ( V_3 , V_1 + V_2 ) ;
}
static inline T_2 F_3 ( void T_1 * V_1 , int V_2 )
{
return F_4 ( V_1 + V_2 ) ;
}
static inline void F_5 ( struct V_4 * V_5 , T_2 V_6 )
{
T_2 V_7 = 0 ;
if ( V_6 == V_8 ) {
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
F_1 ( V_5 -> V_9 , F_6 ( V_7 ) , 0 ) ;
} else {
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
F_1 ( V_5 -> V_9 , F_7 ( V_7 ) , 0 ) ;
}
}
static inline void F_8 ( struct V_4 * V_5 , T_2 V_6 )
{
T_2 V_7 = 0 ;
if ( V_6 == V_8 ) {
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
F_3 ( V_5 -> V_9 , F_9 ( V_7 ) ) ;
} else {
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
F_3 ( V_5 -> V_9 , F_10 ( V_7 ) ) ;
}
}
static inline void F_11 ( struct V_4 * V_5 , T_2 V_6 ,
int V_10 )
{
T_2 V_7 , V_11 ;
if ( V_6 == V_8 ) {
for ( V_7 = 0 ; V_7 < ( V_10 / 2 ) ; V_7 ++ ) {
V_11 = F_3 ( V_5 -> V_9 , F_12 ( V_7 ) ) ;
F_1 ( V_5 -> V_9 , F_12 ( V_7 ) , V_11 | 0x30 ) ;
}
} else {
for ( V_7 = 0 ; V_7 < ( V_10 / 2 ) ; V_7 ++ ) {
V_11 = F_3 ( V_5 -> V_9 , F_12 ( V_7 ) ) ;
F_1 ( V_5 -> V_9 , F_12 ( V_7 ) , V_11 | 0x03 ) ;
}
}
}
static inline void F_13 ( struct V_4 * V_5 , T_2 V_6 ,
int V_10 )
{
T_2 V_7 , V_11 ;
if ( V_6 == V_8 ) {
for ( V_7 = 0 ; V_7 < ( V_10 / 2 ) ; V_7 ++ ) {
V_11 = F_3 ( V_5 -> V_9 , F_12 ( V_7 ) ) ;
F_1 ( V_5 -> V_9 , F_12 ( V_7 ) , V_11 & ~ 0x30 ) ;
}
} else {
for ( V_7 = 0 ; V_7 < ( V_10 / 2 ) ; V_7 ++ ) {
V_11 = F_3 ( V_5 -> V_9 , F_12 ( V_7 ) ) ;
F_1 ( V_5 -> V_9 , F_12 ( V_7 ) , V_11 & ~ 0x03 ) ;
}
}
}
static T_3 F_14 ( int V_11 , void * V_12 )
{
struct V_4 * V_5 = V_12 ;
bool V_13 = false ;
T_2 V_14 [ 4 ] ;
int V_7 ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
V_14 [ V_7 ] = F_3 ( V_5 -> V_9 , F_15 ( V_7 ) ) ;
F_8 ( V_5 , V_8 ) ;
F_8 ( V_5 , V_15 ) ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ ) {
if ( ( V_14 [ V_7 ] & V_16 ) && ( V_7 == 0 ) && V_5 -> V_17 ) {
F_16 ( V_5 ) ;
V_13 = true ;
}
if ( V_14 [ V_7 ] & V_18 )
V_13 = true ;
if ( V_14 [ V_7 ] & V_19 ) {
F_17 ( V_5 -> V_5 , L_1 , V_7 ) ;
V_13 = true ;
}
if ( V_14 [ V_7 ] & V_20 ) {
F_17 ( V_5 -> V_5 , L_2 , V_7 ) ;
V_13 = true ;
}
}
if ( V_13 )
return V_21 ;
else
return V_22 ;
}
static void F_18 ( struct V_4 * V_5 ,
struct V_23 * V_24 )
{
struct V_25 * V_26 = & V_5 -> V_26 ;
F_1 ( V_5 -> V_9 , V_27 , 1 ) ;
F_13 ( V_5 , V_24 -> V_6 , V_26 -> V_10 ) ;
if ( V_24 -> V_6 == V_8 )
F_1 ( V_5 -> V_9 , V_28 , 1 ) ;
else
F_1 ( V_5 -> V_9 , V_29 , 1 ) ;
F_1 ( V_5 -> V_9 , V_30 , 1 ) ;
}
static void F_19 ( struct V_4 * V_5 ,
struct V_23 * V_24 )
{
F_8 ( V_5 , V_24 -> V_6 ) ;
if ( V_24 -> V_6 == V_8 )
F_1 ( V_5 -> V_9 , V_28 , 0 ) ;
else
F_1 ( V_5 -> V_9 , V_29 , 0 ) ;
F_11 ( V_5 , V_24 -> V_6 , 8 ) ;
if ( ! V_5 -> V_31 ) {
F_1 ( V_5 -> V_9 , V_30 , 0 ) ;
F_1 ( V_5 -> V_9 , V_27 , 0 ) ;
}
}
static int F_20 ( struct V_23 * V_24 ,
struct V_32 * V_33 )
{
struct V_4 * V_5 = F_21 ( V_33 ) ;
union V_34 * V_35 = NULL ;
if ( ! ( V_5 -> V_36 & V_37 ) &&
( V_24 -> V_6 == V_15 ) )
return - V_38 ;
if ( ! ( V_5 -> V_36 & V_39 ) &&
( V_24 -> V_6 == V_8 ) )
return - V_38 ;
if ( V_24 -> V_6 == V_8 )
V_35 = & V_5 -> V_40 ;
else if ( V_24 -> V_6 == V_15 )
V_35 = & V_5 -> V_41 ;
F_22 ( V_33 , V_24 , ( void * ) V_35 ) ;
return 0 ;
}
static void F_23 ( struct V_4 * V_5 , int V_6 )
{
T_2 V_42 ;
struct V_25 * V_26 = & V_5 -> V_26 ;
F_5 ( V_5 , V_6 ) ;
for ( V_42 = 0 ; V_42 < ( V_26 -> V_10 / 2 ) ; V_42 ++ ) {
if ( V_6 == V_8 ) {
F_1 ( V_5 -> V_9 , F_24 ( V_42 ) ,
V_5 -> V_43 ) ;
F_1 ( V_5 -> V_9 , F_25 ( V_42 ) ,
V_5 -> V_44 - 1 ) ;
F_1 ( V_5 -> V_9 , F_6 ( V_42 ) , 1 ) ;
} else {
F_1 ( V_5 -> V_9 , F_26 ( V_42 ) ,
V_5 -> V_43 ) ;
F_1 ( V_5 -> V_9 , F_27 ( V_42 ) ,
V_5 -> V_44 - 1 ) ;
F_1 ( V_5 -> V_9 , F_7 ( V_42 ) , 1 ) ;
}
}
}
static int F_28 ( struct V_23 * V_24 ,
struct V_45 * V_46 , struct V_32 * V_47 )
{
struct V_4 * V_5 = F_21 ( V_47 ) ;
struct V_25 * V_26 = & V_5 -> V_26 ;
int V_48 ;
switch ( F_29 ( V_46 ) ) {
case V_49 :
V_26 -> V_50 = 16 ;
V_5 -> V_51 = 0x00 ;
V_5 -> V_43 = 0x02 ;
break;
case V_52 :
V_26 -> V_50 = 24 ;
V_5 -> V_51 = 0x08 ;
V_5 -> V_43 = 0x04 ;
break;
case V_53 :
V_26 -> V_50 = 32 ;
V_5 -> V_51 = 0x10 ;
V_5 -> V_43 = 0x05 ;
break;
default:
F_17 ( V_5 -> V_5 , L_3 ) ;
return - V_38 ;
}
V_26 -> V_10 = F_30 ( V_46 ) ;
switch ( V_26 -> V_10 ) {
case V_54 :
case V_55 :
case V_56 :
case V_57 :
break;
default:
F_17 ( V_5 -> V_5 , L_4 ) ;
return - V_38 ;
}
F_23 ( V_5 , V_24 -> V_6 ) ;
F_1 ( V_5 -> V_9 , V_58 , V_5 -> V_51 ) ;
V_26 -> V_59 = F_31 ( V_46 ) ;
if ( V_5 -> V_36 & V_60 ) {
if ( V_5 -> V_61 ) {
V_48 = V_5 -> V_61 ( V_26 ) ;
if ( V_48 < 0 ) {
F_17 ( V_5 -> V_5 , L_5 ) ;
return V_48 ;
}
} else {
T_2 V_62 = V_26 -> V_59 *
V_26 -> V_50 * 2 ;
V_48 = F_32 ( V_5 -> V_63 , V_62 ) ;
if ( V_48 ) {
F_17 ( V_5 -> V_5 , L_6 ,
V_48 ) ;
return V_48 ;
}
}
}
return 0 ;
}
static void F_33 ( struct V_23 * V_24 ,
struct V_32 * V_47 )
{
F_22 ( V_47 , V_24 , NULL ) ;
}
static int F_34 ( struct V_23 * V_24 ,
struct V_32 * V_47 )
{
struct V_4 * V_5 = F_21 ( V_47 ) ;
if ( V_24 -> V_6 == V_8 )
F_1 ( V_5 -> V_9 , V_64 , 1 ) ;
else
F_1 ( V_5 -> V_9 , V_65 , 1 ) ;
return 0 ;
}
static int F_35 ( struct V_23 * V_24 ,
int V_66 , struct V_32 * V_47 )
{
struct V_4 * V_5 = F_21 ( V_47 ) ;
int V_48 = 0 ;
switch ( V_66 ) {
case V_67 :
case V_68 :
case V_69 :
V_5 -> V_31 ++ ;
F_18 ( V_5 , V_24 ) ;
break;
case V_70 :
case V_71 :
case V_72 :
V_5 -> V_31 -- ;
F_19 ( V_5 , V_24 ) ;
break;
default:
V_48 = - V_38 ;
break;
}
return V_48 ;
}
static int F_36 ( struct V_32 * V_33 , unsigned int V_73 )
{
struct V_4 * V_5 = F_21 ( V_33 ) ;
int V_48 = 0 ;
switch ( V_73 & V_74 ) {
case V_75 :
if ( V_5 -> V_36 & V_76 )
V_48 = 0 ;
else
V_48 = - V_38 ;
break;
case V_77 :
if ( V_5 -> V_36 & V_60 )
V_48 = 0 ;
else
V_48 = - V_38 ;
break;
case V_78 :
case V_79 :
V_48 = - V_38 ;
break;
default:
F_37 ( V_5 -> V_5 , L_7 ) ;
V_48 = - V_38 ;
break;
}
return V_48 ;
}
static int F_38 ( struct V_80 * V_5 )
{
struct V_4 * V_81 = F_39 ( V_5 ) ;
if ( V_81 -> V_36 & V_60 )
F_40 ( V_81 -> V_63 ) ;
return 0 ;
}
static int F_41 ( struct V_80 * V_5 )
{
struct V_4 * V_81 = F_39 ( V_5 ) ;
if ( V_81 -> V_36 & V_60 )
F_42 ( V_81 -> V_63 ) ;
return 0 ;
}
static int F_43 ( struct V_32 * V_47 )
{
struct V_4 * V_5 = F_21 ( V_47 ) ;
if ( V_5 -> V_36 & V_60 )
F_40 ( V_5 -> V_63 ) ;
return 0 ;
}
static int F_44 ( struct V_32 * V_47 )
{
struct V_4 * V_5 = F_21 ( V_47 ) ;
if ( V_5 -> V_36 & V_60 )
F_42 ( V_5 -> V_63 ) ;
if ( V_47 -> V_82 )
F_23 ( V_5 , V_8 ) ;
if ( V_47 -> V_83 )
F_23 ( V_5 , V_15 ) ;
return 0 ;
}
static int F_45 ( struct V_4 * V_5 ,
struct V_84 * V_85 ,
unsigned int V_86 )
{
T_2 V_87 = F_3 ( V_5 -> V_9 , V_5 -> V_88 ) ;
T_2 V_89 = F_3 ( V_5 -> V_9 , V_5 -> V_90 ) ;
T_2 V_91 = 1 << ( 1 + F_46 ( V_87 ) ) ;
T_2 V_92 ;
if ( V_5 -> V_36 & V_37 &&
V_5 -> V_93 & V_94 )
V_87 = V_87 & ~ F_47 ( 5 ) ;
if ( F_48 ( V_87 ) ) {
F_37 ( V_5 -> V_5 , L_8 ) ;
V_92 = F_49 ( V_87 ) ;
if ( F_50 ( V_92 >= F_51 ( V_95 ) ) )
return - V_38 ;
V_85 -> V_96 . V_97 = V_98 ;
V_85 -> V_96 . V_99 =
1 << ( F_52 ( V_87 ) + 1 ) ;
V_85 -> V_96 . V_95 = V_95 [ V_92 ] ;
V_85 -> V_96 . V_86 = V_86 ;
}
if ( F_53 ( V_87 ) ) {
F_37 ( V_5 -> V_5 , L_9 ) ;
V_92 = F_54 ( V_89 ) ;
if ( F_50 ( V_92 >= F_51 ( V_95 ) ) )
return - V_38 ;
V_85 -> V_100 . V_97 = V_98 ;
V_85 -> V_100 . V_99 =
1 << ( F_55 ( V_87 ) + 1 ) ;
V_85 -> V_100 . V_95 = V_95 [ V_92 ] ;
V_85 -> V_100 . V_86 = V_86 ;
}
if ( F_56 ( V_87 ) ) {
F_37 ( V_5 -> V_5 , L_10 ) ;
V_5 -> V_36 |= V_60 ;
} else {
F_37 ( V_5 -> V_5 , L_11 ) ;
V_5 -> V_36 |= V_76 ;
}
V_5 -> V_44 = V_91 / 2 ;
return 0 ;
}
static int F_57 ( struct V_4 * V_5 ,
struct V_84 * V_85 ,
struct V_101 * V_102 ,
const struct V_103 * V_104 )
{
T_2 V_87 = F_3 ( V_5 -> V_9 , V_5 -> V_88 ) ;
T_2 V_92 = F_58 ( V_87 ) ;
int V_48 ;
if ( F_50 ( V_92 >= F_51 ( V_105 ) ) )
return - V_38 ;
V_48 = F_45 ( V_5 , V_85 , V_104 -> V_106 ) ;
if ( V_48 < 0 )
return V_48 ;
V_5 -> V_40 . V_107 . V_108 = V_104 -> V_40 ;
V_5 -> V_41 . V_107 . V_108 = V_104 -> V_41 ;
V_5 -> V_40 . V_107 . V_109 = V_102 -> V_110 + V_111 ;
V_5 -> V_41 . V_107 . V_109 = V_102 -> V_110 + V_112 ;
V_5 -> V_40 . V_107 . V_113 = 16 ;
V_5 -> V_41 . V_107 . V_113 = 16 ;
V_5 -> V_40 . V_107 . V_114 = V_105 [ V_92 ] ;
V_5 -> V_41 . V_107 . V_114 = V_105 [ V_92 ] ;
V_5 -> V_40 . V_107 . V_115 = V_104 -> V_115 ;
V_5 -> V_41 . V_107 . V_115 = V_104 -> V_115 ;
return 0 ;
}
static int F_59 ( struct V_4 * V_5 ,
struct V_84 * V_85 ,
struct V_101 * V_102 )
{
T_2 V_87 = F_3 ( V_5 -> V_9 , V_116 ) ;
T_2 V_89 = F_3 ( V_5 -> V_9 , V_117 ) ;
T_2 V_91 = 1 << ( 1 + F_46 ( V_87 ) ) ;
T_2 V_92 = F_58 ( V_87 ) ;
T_2 V_118 ;
int V_48 ;
if ( F_50 ( V_92 >= F_51 ( V_105 ) ) )
return - V_38 ;
V_48 = F_45 ( V_5 , V_85 , V_119 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( F_48 ( V_87 ) ) {
V_118 = F_49 ( V_87 ) ;
V_5 -> V_36 |= V_39 ;
V_5 -> V_40 . V_120 . V_109 = V_102 -> V_110 + V_111 ;
V_5 -> V_40 . V_120 . V_114 = V_105 [ V_92 ] ;
V_5 -> V_40 . V_120 . V_121 = V_91 *
( V_122 [ V_118 ] ) >> 8 ;
V_5 -> V_40 . V_120 . V_123 = 16 ;
}
if ( F_53 ( V_87 ) ) {
V_118 = F_54 ( V_89 ) ;
V_5 -> V_36 |= V_37 ;
V_5 -> V_41 . V_120 . V_109 = V_102 -> V_110 + V_112 ;
V_5 -> V_41 . V_120 . V_114 = V_105 [ V_92 ] ;
V_5 -> V_41 . V_120 . V_121 = V_91 *
( V_122 [ V_118 ] >> 8 ) ;
V_5 -> V_41 . V_120 . V_123 = 16 ;
}
return 0 ;
}
static int F_60 ( struct V_124 * V_125 )
{
const struct V_103 * V_104 = V_125 -> V_5 . V_126 ;
struct V_4 * V_5 ;
struct V_101 * V_102 ;
int V_48 , V_11 ;
struct V_84 * V_85 ;
const char * V_127 ;
V_5 = F_61 ( & V_125 -> V_5 , sizeof( * V_5 ) , V_128 ) ;
if ( ! V_5 ) {
F_62 ( & V_125 -> V_5 , L_12 ) ;
return - V_129 ;
}
V_85 = F_61 ( & V_125 -> V_5 , sizeof( * V_85 ) , V_128 ) ;
if ( ! V_85 )
return - V_129 ;
V_85 -> V_130 = & V_131 ;
V_85 -> V_132 = F_43 ;
V_85 -> V_133 = F_44 ;
V_102 = F_63 ( V_125 , V_134 , 0 ) ;
V_5 -> V_9 = F_64 ( & V_125 -> V_5 , V_102 ) ;
if ( F_65 ( V_5 -> V_9 ) )
return F_66 ( V_5 -> V_9 ) ;
V_5 -> V_5 = & V_125 -> V_5 ;
V_11 = F_67 ( V_125 , 0 ) ;
if ( V_11 >= 0 ) {
V_48 = F_68 ( & V_125 -> V_5 , V_11 , F_14 , 0 ,
V_125 -> V_135 , V_5 ) ;
if ( V_48 < 0 ) {
F_17 ( & V_125 -> V_5 , L_13 ) ;
return V_48 ;
}
}
V_5 -> V_88 = V_116 ;
V_5 -> V_90 = V_117 ;
if ( V_104 ) {
V_5 -> V_36 = V_104 -> V_136 ;
V_127 = NULL ;
V_5 -> V_93 = V_104 -> V_93 ;
if ( V_5 -> V_93 & V_137 ) {
V_5 -> V_88 = V_104 -> V_88 ;
V_5 -> V_90 = V_104 -> V_90 ;
}
V_48 = F_57 ( V_5 , V_85 , V_102 , V_104 ) ;
} else {
V_127 = L_14 ;
V_48 = F_59 ( V_5 , V_85 , V_102 ) ;
}
if ( V_48 < 0 )
return V_48 ;
if ( V_5 -> V_36 & V_60 ) {
if ( V_104 ) {
V_5 -> V_61 = V_104 -> V_61 ;
if ( ! V_5 -> V_61 ) {
F_17 ( & V_125 -> V_5 , L_15 ) ;
return - V_138 ;
}
}
V_5 -> V_63 = F_69 ( & V_125 -> V_5 , V_127 ) ;
if ( F_65 ( V_5 -> V_63 ) )
return F_66 ( V_5 -> V_63 ) ;
V_48 = F_70 ( V_5 -> V_63 ) ;
if ( V_48 < 0 )
return V_48 ;
}
F_71 ( & V_125 -> V_5 , V_5 ) ;
V_48 = F_72 ( & V_125 -> V_5 , & V_139 ,
V_85 , 1 ) ;
if ( V_48 != 0 ) {
F_17 ( & V_125 -> V_5 , L_16 ) ;
goto V_140;
}
if ( ! V_104 ) {
V_48 = F_73 ( & V_125 -> V_5 , NULL , 0 ) ;
if ( V_48 == - V_141 ) {
F_17 ( & V_125 -> V_5 ,
L_17 ) ;
return V_48 ;
} else if ( V_48 ) {
F_17 ( & V_125 -> V_5 ,
L_18
L_19 , V_48 ) ;
V_48 = F_74 ( V_125 ) ;
if ( V_48 ) {
F_17 ( & V_125 -> V_5 ,
L_20 ,
V_48 ) ;
goto V_140;
}
}
}
F_75 ( & V_125 -> V_5 ) ;
return 0 ;
V_140:
if ( V_5 -> V_36 & V_60 )
F_76 ( V_5 -> V_63 ) ;
return V_48 ;
}
static int F_77 ( struct V_124 * V_125 )
{
struct V_4 * V_5 = F_39 ( & V_125 -> V_5 ) ;
if ( V_5 -> V_36 & V_60 )
F_76 ( V_5 -> V_63 ) ;
F_78 ( & V_125 -> V_5 ) ;
return 0 ;
}
