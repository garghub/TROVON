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
static void F_11 ( struct V_4 * V_5 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = & V_5 -> V_13 ;
T_2 V_7 , V_14 ;
F_1 ( V_5 -> V_9 , V_15 , 1 ) ;
if ( V_11 -> V_6 == V_8 ) {
for ( V_7 = 0 ; V_7 < ( V_13 -> V_16 / 2 ) ; V_7 ++ ) {
V_14 = F_3 ( V_5 -> V_9 , F_12 ( V_7 ) ) ;
F_1 ( V_5 -> V_9 , F_12 ( V_7 ) , V_14 & ~ 0x30 ) ;
}
F_1 ( V_5 -> V_9 , V_17 , 1 ) ;
} else {
for ( V_7 = 0 ; V_7 < ( V_13 -> V_16 / 2 ) ; V_7 ++ ) {
V_14 = F_3 ( V_5 -> V_9 , F_12 ( V_7 ) ) ;
F_1 ( V_5 -> V_9 , F_12 ( V_7 ) , V_14 & ~ 0x03 ) ;
}
F_1 ( V_5 -> V_9 , V_18 , 1 ) ;
}
F_1 ( V_5 -> V_9 , V_19 , 1 ) ;
}
static void F_13 ( struct V_4 * V_5 ,
struct V_10 * V_11 )
{
T_2 V_7 = 0 , V_14 ;
F_8 ( V_5 , V_11 -> V_6 ) ;
if ( V_11 -> V_6 == V_8 ) {
F_1 ( V_5 -> V_9 , V_17 , 0 ) ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ ) {
V_14 = F_3 ( V_5 -> V_9 , F_12 ( V_7 ) ) ;
F_1 ( V_5 -> V_9 , F_12 ( V_7 ) , V_14 | 0x30 ) ;
}
} else {
F_1 ( V_5 -> V_9 , V_18 , 0 ) ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ ) {
V_14 = F_3 ( V_5 -> V_9 , F_12 ( V_7 ) ) ;
F_1 ( V_5 -> V_9 , F_12 ( V_7 ) , V_14 | 0x03 ) ;
}
}
if ( ! V_5 -> V_20 ) {
F_1 ( V_5 -> V_9 , V_19 , 0 ) ;
F_1 ( V_5 -> V_9 , V_15 , 0 ) ;
}
}
static int F_14 ( struct V_10 * V_11 ,
struct V_21 * V_22 )
{
struct V_4 * V_5 = F_15 ( V_22 ) ;
union V_23 * V_24 = NULL ;
if ( ! ( V_5 -> V_25 & V_26 ) &&
( V_11 -> V_6 == V_27 ) )
return - V_28 ;
if ( ! ( V_5 -> V_25 & V_29 ) &&
( V_11 -> V_6 == V_8 ) )
return - V_28 ;
if ( V_11 -> V_6 == V_8 )
V_24 = & V_5 -> V_30 ;
else if ( V_11 -> V_6 == V_27 )
V_24 = & V_5 -> V_31 ;
F_16 ( V_22 , V_11 , ( void * ) V_24 ) ;
return 0 ;
}
static void F_17 ( struct V_4 * V_5 , int V_6 )
{
T_2 V_32 , V_14 ;
struct V_12 * V_13 = & V_5 -> V_13 ;
F_5 ( V_5 , V_6 ) ;
for ( V_32 = 0 ; V_32 < ( V_13 -> V_16 / 2 ) ; V_32 ++ ) {
if ( V_6 == V_8 ) {
F_1 ( V_5 -> V_9 , F_18 ( V_32 ) ,
V_5 -> V_33 ) ;
F_1 ( V_5 -> V_9 , F_19 ( V_32 ) ,
V_5 -> V_34 - 1 ) ;
V_14 = F_3 ( V_5 -> V_9 , F_12 ( V_32 ) ) ;
F_1 ( V_5 -> V_9 , F_12 ( V_32 ) , V_14 & ~ 0x30 ) ;
F_1 ( V_5 -> V_9 , F_6 ( V_32 ) , 1 ) ;
} else {
F_1 ( V_5 -> V_9 , F_20 ( V_32 ) ,
V_5 -> V_33 ) ;
F_1 ( V_5 -> V_9 , F_21 ( V_32 ) ,
V_5 -> V_34 - 1 ) ;
V_14 = F_3 ( V_5 -> V_9 , F_12 ( V_32 ) ) ;
F_1 ( V_5 -> V_9 , F_12 ( V_32 ) , V_14 & ~ 0x03 ) ;
F_1 ( V_5 -> V_9 , F_7 ( V_32 ) , 1 ) ;
}
}
}
static int F_22 ( struct V_10 * V_11 ,
struct V_35 * V_36 , struct V_21 * V_37 )
{
struct V_4 * V_5 = F_15 ( V_37 ) ;
struct V_12 * V_13 = & V_5 -> V_13 ;
int V_38 ;
switch ( F_23 ( V_36 ) ) {
case V_39 :
V_13 -> V_40 = 16 ;
V_5 -> V_41 = 0x00 ;
V_5 -> V_33 = 0x02 ;
break;
case V_42 :
V_13 -> V_40 = 24 ;
V_5 -> V_41 = 0x08 ;
V_5 -> V_33 = 0x04 ;
break;
case V_43 :
V_13 -> V_40 = 32 ;
V_5 -> V_41 = 0x10 ;
V_5 -> V_33 = 0x05 ;
break;
default:
F_24 ( V_5 -> V_5 , L_1 ) ;
return - V_28 ;
}
V_13 -> V_16 = F_25 ( V_36 ) ;
switch ( V_13 -> V_16 ) {
case V_44 :
case V_45 :
case V_46 :
case V_47 :
break;
default:
F_24 ( V_5 -> V_5 , L_2 ) ;
return - V_28 ;
}
F_17 ( V_5 , V_11 -> V_6 ) ;
F_1 ( V_5 -> V_9 , V_48 , V_5 -> V_41 ) ;
V_13 -> V_49 = F_26 ( V_36 ) ;
if ( V_5 -> V_25 & V_50 ) {
if ( V_5 -> V_51 ) {
V_38 = V_5 -> V_51 ( V_13 ) ;
if ( V_38 < 0 ) {
F_24 ( V_5 -> V_5 , L_3 ) ;
return V_38 ;
}
} else {
T_2 V_52 = V_13 -> V_49 *
V_13 -> V_40 * 2 ;
V_38 = F_27 ( V_5 -> V_53 , V_52 ) ;
if ( V_38 ) {
F_24 ( V_5 -> V_5 , L_4 ,
V_38 ) ;
return V_38 ;
}
}
}
return 0 ;
}
static void F_28 ( struct V_10 * V_11 ,
struct V_21 * V_37 )
{
F_16 ( V_37 , V_11 , NULL ) ;
}
static int F_29 ( struct V_10 * V_11 ,
struct V_21 * V_37 )
{
struct V_4 * V_5 = F_15 ( V_37 ) ;
if ( V_11 -> V_6 == V_8 )
F_1 ( V_5 -> V_9 , V_54 , 1 ) ;
else
F_1 ( V_5 -> V_9 , V_55 , 1 ) ;
return 0 ;
}
static int F_30 ( struct V_10 * V_11 ,
int V_56 , struct V_21 * V_37 )
{
struct V_4 * V_5 = F_15 ( V_37 ) ;
int V_38 = 0 ;
switch ( V_56 ) {
case V_57 :
case V_58 :
case V_59 :
V_5 -> V_20 ++ ;
F_11 ( V_5 , V_11 ) ;
break;
case V_60 :
case V_61 :
case V_62 :
V_5 -> V_20 -- ;
F_13 ( V_5 , V_11 ) ;
break;
default:
V_38 = - V_28 ;
break;
}
return V_38 ;
}
static int F_31 ( struct V_21 * V_22 , unsigned int V_63 )
{
struct V_4 * V_5 = F_15 ( V_22 ) ;
int V_38 = 0 ;
switch ( V_63 & V_64 ) {
case V_65 :
if ( V_5 -> V_25 & V_66 )
V_38 = 0 ;
else
V_38 = - V_28 ;
break;
case V_67 :
if ( V_5 -> V_25 & V_50 )
V_38 = 0 ;
else
V_38 = - V_28 ;
break;
case V_68 :
case V_69 :
V_38 = - V_28 ;
break;
default:
F_32 ( V_5 -> V_5 , L_5 ) ;
V_38 = - V_28 ;
break;
}
return V_38 ;
}
static int F_33 ( struct V_70 * V_5 )
{
struct V_4 * V_71 = F_34 ( V_5 ) ;
if ( V_71 -> V_25 & V_50 )
F_35 ( V_71 -> V_53 ) ;
return 0 ;
}
static int F_36 ( struct V_70 * V_5 )
{
struct V_4 * V_71 = F_34 ( V_5 ) ;
if ( V_71 -> V_25 & V_50 )
F_37 ( V_71 -> V_53 ) ;
return 0 ;
}
static int F_38 ( struct V_21 * V_37 )
{
struct V_4 * V_5 = F_15 ( V_37 ) ;
if ( V_5 -> V_25 & V_50 )
F_35 ( V_5 -> V_53 ) ;
return 0 ;
}
static int F_39 ( struct V_21 * V_37 )
{
struct V_4 * V_5 = F_15 ( V_37 ) ;
if ( V_5 -> V_25 & V_50 )
F_37 ( V_5 -> V_53 ) ;
if ( V_37 -> V_72 )
F_17 ( V_5 , V_8 ) ;
if ( V_37 -> V_73 )
F_17 ( V_5 , V_27 ) ;
return 0 ;
}
static int F_40 ( struct V_4 * V_5 ,
struct V_74 * V_75 ,
unsigned int V_76 )
{
T_2 V_77 = F_3 ( V_5 -> V_9 , V_5 -> V_78 ) ;
T_2 V_79 = F_3 ( V_5 -> V_9 , V_5 -> V_80 ) ;
T_2 V_81 = 1 << ( 1 + F_41 ( V_77 ) ) ;
T_2 V_82 ;
if ( V_5 -> V_25 & V_26 &&
V_5 -> V_83 & V_84 )
V_77 = V_77 & ~ F_42 ( 5 ) ;
if ( F_43 ( V_77 ) ) {
F_32 ( V_5 -> V_5 , L_6 ) ;
V_82 = F_44 ( V_77 ) ;
if ( F_45 ( V_82 >= F_46 ( V_85 ) ) )
return - V_28 ;
V_75 -> V_86 . V_87 = V_88 ;
V_75 -> V_86 . V_89 =
1 << ( F_47 ( V_77 ) + 1 ) ;
V_75 -> V_86 . V_85 = V_85 [ V_82 ] ;
V_75 -> V_86 . V_76 = V_76 ;
}
if ( F_48 ( V_77 ) ) {
F_32 ( V_5 -> V_5 , L_7 ) ;
V_82 = F_49 ( V_79 ) ;
if ( F_45 ( V_82 >= F_46 ( V_85 ) ) )
return - V_28 ;
V_75 -> V_90 . V_87 = V_88 ;
V_75 -> V_90 . V_89 =
1 << ( F_50 ( V_77 ) + 1 ) ;
V_75 -> V_90 . V_85 = V_85 [ V_82 ] ;
V_75 -> V_90 . V_76 = V_76 ;
}
if ( F_51 ( V_77 ) ) {
F_32 ( V_5 -> V_5 , L_8 ) ;
V_5 -> V_25 |= V_50 ;
} else {
F_32 ( V_5 -> V_5 , L_9 ) ;
V_5 -> V_25 |= V_66 ;
}
V_5 -> V_34 = V_81 / 2 ;
return 0 ;
}
static int F_52 ( struct V_4 * V_5 ,
struct V_74 * V_75 ,
struct V_91 * V_92 ,
const struct V_93 * V_94 )
{
T_2 V_77 = F_3 ( V_5 -> V_9 , V_5 -> V_78 ) ;
T_2 V_82 = F_53 ( V_77 ) ;
int V_38 ;
if ( F_45 ( V_82 >= F_46 ( V_95 ) ) )
return - V_28 ;
V_38 = F_40 ( V_5 , V_75 , V_94 -> V_96 ) ;
if ( V_38 < 0 )
return V_38 ;
V_5 -> V_30 . V_97 . V_98 = V_94 -> V_30 ;
V_5 -> V_31 . V_97 . V_98 = V_94 -> V_31 ;
V_5 -> V_30 . V_97 . V_99 = V_92 -> V_100 + V_101 ;
V_5 -> V_31 . V_97 . V_99 = V_92 -> V_100 + V_102 ;
V_5 -> V_30 . V_97 . V_103 = 16 ;
V_5 -> V_31 . V_97 . V_103 = 16 ;
V_5 -> V_30 . V_97 . V_104 = V_95 [ V_82 ] ;
V_5 -> V_31 . V_97 . V_104 = V_95 [ V_82 ] ;
V_5 -> V_30 . V_97 . V_105 = V_94 -> V_105 ;
V_5 -> V_31 . V_97 . V_105 = V_94 -> V_105 ;
return 0 ;
}
static int F_54 ( struct V_4 * V_5 ,
struct V_74 * V_75 ,
struct V_91 * V_92 )
{
T_2 V_77 = F_3 ( V_5 -> V_9 , V_106 ) ;
T_2 V_79 = F_3 ( V_5 -> V_9 , V_107 ) ;
T_2 V_81 = 1 << ( 1 + F_41 ( V_77 ) ) ;
T_2 V_82 = F_53 ( V_77 ) ;
T_2 V_108 ;
int V_38 ;
if ( F_45 ( V_82 >= F_46 ( V_95 ) ) )
return - V_28 ;
V_38 = F_40 ( V_5 , V_75 , V_109 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( F_43 ( V_77 ) ) {
V_108 = F_44 ( V_77 ) ;
V_5 -> V_25 |= V_29 ;
V_5 -> V_30 . V_110 . V_99 = V_92 -> V_100 + V_101 ;
V_5 -> V_30 . V_110 . V_104 = V_95 [ V_82 ] ;
V_5 -> V_30 . V_110 . V_111 = L_10 ;
V_5 -> V_30 . V_110 . V_112 = V_81 *
( V_113 [ V_108 ] ) >> 8 ;
V_5 -> V_30 . V_110 . V_114 = 16 ;
}
if ( F_48 ( V_77 ) ) {
V_108 = F_49 ( V_79 ) ;
V_5 -> V_25 |= V_26 ;
V_5 -> V_31 . V_110 . V_99 = V_92 -> V_100 + V_102 ;
V_5 -> V_31 . V_110 . V_104 = V_95 [ V_82 ] ;
V_5 -> V_31 . V_110 . V_111 = L_11 ;
V_5 -> V_31 . V_110 . V_112 = V_81 *
( V_113 [ V_108 ] >> 8 ) ;
V_5 -> V_31 . V_110 . V_114 = 16 ;
}
return 0 ;
}
static int F_55 ( struct V_115 * V_116 )
{
const struct V_93 * V_94 = V_116 -> V_5 . V_117 ;
struct V_4 * V_5 ;
struct V_91 * V_92 ;
int V_38 ;
struct V_74 * V_75 ;
const char * V_118 ;
V_5 = F_56 ( & V_116 -> V_5 , sizeof( * V_5 ) , V_119 ) ;
if ( ! V_5 ) {
F_57 ( & V_116 -> V_5 , L_12 ) ;
return - V_120 ;
}
V_75 = F_56 ( & V_116 -> V_5 , sizeof( * V_75 ) , V_119 ) ;
if ( ! V_75 )
return - V_120 ;
V_75 -> V_121 = & V_122 ;
V_75 -> V_123 = F_38 ;
V_75 -> V_124 = F_39 ;
V_92 = F_58 ( V_116 , V_125 , 0 ) ;
V_5 -> V_9 = F_59 ( & V_116 -> V_5 , V_92 ) ;
if ( F_60 ( V_5 -> V_9 ) )
return F_61 ( V_5 -> V_9 ) ;
V_5 -> V_5 = & V_116 -> V_5 ;
V_5 -> V_78 = V_106 ;
V_5 -> V_80 = V_107 ;
if ( V_94 ) {
V_5 -> V_25 = V_94 -> V_126 ;
V_118 = NULL ;
V_5 -> V_83 = V_94 -> V_83 ;
if ( V_5 -> V_83 & V_127 ) {
V_5 -> V_78 = V_94 -> V_78 ;
V_5 -> V_80 = V_94 -> V_80 ;
}
V_38 = F_52 ( V_5 , V_75 , V_92 , V_94 ) ;
} else {
V_118 = L_13 ;
V_38 = F_54 ( V_5 , V_75 , V_92 ) ;
}
if ( V_38 < 0 )
return V_38 ;
if ( V_5 -> V_25 & V_50 ) {
if ( V_94 ) {
V_5 -> V_51 = V_94 -> V_51 ;
if ( ! V_5 -> V_51 ) {
F_24 ( & V_116 -> V_5 , L_14 ) ;
return - V_128 ;
}
}
V_5 -> V_53 = F_62 ( & V_116 -> V_5 , V_118 ) ;
if ( F_60 ( V_5 -> V_53 ) )
return F_61 ( V_5 -> V_53 ) ;
V_38 = F_63 ( V_5 -> V_53 ) ;
if ( V_38 < 0 )
return V_38 ;
}
F_64 ( & V_116 -> V_5 , V_5 ) ;
V_38 = F_65 ( & V_116 -> V_5 , & V_129 ,
V_75 , 1 ) ;
if ( V_38 != 0 ) {
F_24 ( & V_116 -> V_5 , L_15 ) ;
goto V_130;
}
if ( ! V_94 ) {
V_38 = F_66 ( & V_116 -> V_5 , NULL , 0 ) ;
if ( V_38 ) {
F_24 ( & V_116 -> V_5 ,
L_16 , V_38 ) ;
goto V_130;
}
}
F_67 ( & V_116 -> V_5 ) ;
return 0 ;
V_130:
if ( V_5 -> V_25 & V_50 )
F_68 ( V_5 -> V_53 ) ;
return V_38 ;
}
static int F_69 ( struct V_115 * V_116 )
{
struct V_4 * V_5 = F_34 ( & V_116 -> V_5 ) ;
if ( V_5 -> V_25 & V_50 )
F_68 ( V_5 -> V_53 ) ;
F_70 ( & V_116 -> V_5 ) ;
return 0 ;
}
