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
T_2 V_7 , V_12 ;
F_1 ( V_5 -> V_9 , V_13 , 1 ) ;
if ( V_11 -> V_6 == V_8 ) {
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ ) {
V_12 = F_3 ( V_5 -> V_9 , F_12 ( V_7 ) ) ;
F_1 ( V_5 -> V_9 , F_12 ( V_7 ) , V_12 & ~ 0x30 ) ;
}
F_1 ( V_5 -> V_9 , V_14 , 1 ) ;
} else {
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ ) {
V_12 = F_3 ( V_5 -> V_9 , F_12 ( V_7 ) ) ;
F_1 ( V_5 -> V_9 , F_12 ( V_7 ) , V_12 & ~ 0x03 ) ;
}
F_1 ( V_5 -> V_9 , V_15 , 1 ) ;
}
F_1 ( V_5 -> V_9 , V_16 , 1 ) ;
}
static void F_13 ( struct V_4 * V_5 ,
struct V_10 * V_11 )
{
T_2 V_7 = 0 , V_12 ;
F_8 ( V_5 , V_11 -> V_6 ) ;
if ( V_11 -> V_6 == V_8 ) {
F_1 ( V_5 -> V_9 , V_14 , 0 ) ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ ) {
V_12 = F_3 ( V_5 -> V_9 , F_12 ( V_7 ) ) ;
F_1 ( V_5 -> V_9 , F_12 ( V_7 ) , V_12 | 0x30 ) ;
}
} else {
F_1 ( V_5 -> V_9 , V_15 , 0 ) ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ ) {
V_12 = F_3 ( V_5 -> V_9 , F_12 ( V_7 ) ) ;
F_1 ( V_5 -> V_9 , F_12 ( V_7 ) , V_12 | 0x03 ) ;
}
}
if ( ! V_5 -> V_17 ) {
F_1 ( V_5 -> V_9 , V_16 , 0 ) ;
F_1 ( V_5 -> V_9 , V_13 , 0 ) ;
}
}
static int F_14 ( struct V_10 * V_11 ,
struct V_18 * V_19 )
{
struct V_4 * V_5 = F_15 ( V_19 ) ;
union V_20 * V_21 = NULL ;
if ( ! ( V_5 -> V_22 & V_23 ) &&
( V_11 -> V_6 == V_24 ) )
return - V_25 ;
if ( ! ( V_5 -> V_22 & V_26 ) &&
( V_11 -> V_6 == V_8 ) )
return - V_25 ;
if ( V_11 -> V_6 == V_8 )
V_21 = & V_5 -> V_27 ;
else if ( V_11 -> V_6 == V_24 )
V_21 = & V_5 -> V_28 ;
F_16 ( V_19 , V_11 , ( void * ) V_21 ) ;
return 0 ;
}
static void F_17 ( struct V_4 * V_5 , int V_6 )
{
T_2 V_29 , V_12 ;
struct V_30 * V_31 = & V_5 -> V_31 ;
F_5 ( V_5 , V_6 ) ;
for ( V_29 = 0 ; V_29 < ( V_31 -> V_32 / 2 ) ; V_29 ++ ) {
if ( V_6 == V_8 ) {
F_1 ( V_5 -> V_9 , F_18 ( V_29 ) ,
V_5 -> V_33 ) ;
F_1 ( V_5 -> V_9 , F_19 ( V_29 ) , 0x02 ) ;
V_12 = F_3 ( V_5 -> V_9 , F_12 ( V_29 ) ) ;
F_1 ( V_5 -> V_9 , F_12 ( V_29 ) , V_12 & ~ 0x30 ) ;
F_1 ( V_5 -> V_9 , F_6 ( V_29 ) , 1 ) ;
} else {
F_1 ( V_5 -> V_9 , F_20 ( V_29 ) ,
V_5 -> V_33 ) ;
F_1 ( V_5 -> V_9 , F_21 ( V_29 ) , 0x07 ) ;
V_12 = F_3 ( V_5 -> V_9 , F_12 ( V_29 ) ) ;
F_1 ( V_5 -> V_9 , F_12 ( V_29 ) , V_12 & ~ 0x03 ) ;
F_1 ( V_5 -> V_9 , F_7 ( V_29 ) , 1 ) ;
}
}
}
static int F_22 ( struct V_10 * V_11 ,
struct V_34 * V_35 , struct V_18 * V_36 )
{
struct V_4 * V_5 = F_15 ( V_36 ) ;
struct V_30 * V_31 = & V_5 -> V_31 ;
int V_37 ;
switch ( F_23 ( V_35 ) ) {
case V_38 :
V_31 -> V_39 = 16 ;
V_5 -> V_40 = 0x00 ;
V_5 -> V_33 = 0x02 ;
break;
case V_41 :
V_31 -> V_39 = 24 ;
V_5 -> V_40 = 0x08 ;
V_5 -> V_33 = 0x04 ;
break;
case V_42 :
V_31 -> V_39 = 32 ;
V_5 -> V_40 = 0x10 ;
V_5 -> V_33 = 0x05 ;
break;
default:
F_24 ( V_5 -> V_5 , L_1 ) ;
return - V_25 ;
}
V_31 -> V_32 = F_25 ( V_35 ) ;
switch ( V_31 -> V_32 ) {
case V_43 :
case V_44 :
case V_45 :
case V_46 :
break;
default:
F_24 ( V_5 -> V_5 , L_2 ) ;
return - V_25 ;
}
F_17 ( V_5 , V_11 -> V_6 ) ;
F_1 ( V_5 -> V_9 , V_47 , V_5 -> V_40 ) ;
V_31 -> V_48 = F_26 ( V_35 ) ;
if ( V_5 -> V_22 & V_49 ) {
if ( V_5 -> V_50 ) {
V_37 = V_5 -> V_50 ( V_31 ) ;
if ( V_37 < 0 ) {
F_24 ( V_5 -> V_5 , L_3 ) ;
return V_37 ;
}
} else {
T_2 V_51 = V_31 -> V_48 *
V_31 -> V_39 * 2 ;
V_37 = F_27 ( V_5 -> V_52 , V_51 ) ;
if ( V_37 ) {
F_24 ( V_5 -> V_5 , L_4 ,
V_37 ) ;
return V_37 ;
}
}
}
return 0 ;
}
static void F_28 ( struct V_10 * V_11 ,
struct V_18 * V_36 )
{
F_16 ( V_36 , V_11 , NULL ) ;
}
static int F_29 ( struct V_10 * V_11 ,
struct V_18 * V_36 )
{
struct V_4 * V_5 = F_15 ( V_36 ) ;
if ( V_11 -> V_6 == V_8 )
F_1 ( V_5 -> V_9 , V_53 , 1 ) ;
else
F_1 ( V_5 -> V_9 , V_54 , 1 ) ;
return 0 ;
}
static int F_30 ( struct V_10 * V_11 ,
int V_55 , struct V_18 * V_36 )
{
struct V_4 * V_5 = F_15 ( V_36 ) ;
int V_37 = 0 ;
switch ( V_55 ) {
case V_56 :
case V_57 :
case V_58 :
V_5 -> V_17 ++ ;
F_11 ( V_5 , V_11 ) ;
break;
case V_59 :
case V_60 :
case V_61 :
V_5 -> V_17 -- ;
F_13 ( V_5 , V_11 ) ;
break;
default:
V_37 = - V_25 ;
break;
}
return V_37 ;
}
static int F_31 ( struct V_18 * V_19 , unsigned int V_62 )
{
struct V_4 * V_5 = F_15 ( V_19 ) ;
int V_37 = 0 ;
switch ( V_62 & V_63 ) {
case V_64 :
if ( V_5 -> V_22 & V_65 )
V_37 = 0 ;
else
V_37 = - V_25 ;
break;
case V_66 :
if ( V_5 -> V_22 & V_49 )
V_37 = 0 ;
else
V_37 = - V_25 ;
break;
case V_67 :
case V_68 :
V_37 = - V_25 ;
break;
default:
F_32 ( V_5 -> V_5 , L_5 ) ;
V_37 = - V_25 ;
break;
}
return V_37 ;
}
static int F_33 ( struct V_69 * V_5 )
{
struct V_4 * V_70 = F_34 ( V_5 ) ;
if ( V_70 -> V_22 & V_49 )
F_35 ( V_70 -> V_52 ) ;
return 0 ;
}
static int F_36 ( struct V_69 * V_5 )
{
struct V_4 * V_70 = F_34 ( V_5 ) ;
if ( V_70 -> V_22 & V_49 )
F_37 ( V_70 -> V_52 ) ;
return 0 ;
}
static int F_38 ( struct V_18 * V_36 )
{
struct V_4 * V_5 = F_15 ( V_36 ) ;
if ( V_5 -> V_22 & V_49 )
F_35 ( V_5 -> V_52 ) ;
return 0 ;
}
static int F_39 ( struct V_18 * V_36 )
{
struct V_4 * V_5 = F_15 ( V_36 ) ;
if ( V_5 -> V_22 & V_49 )
F_37 ( V_5 -> V_52 ) ;
if ( V_36 -> V_71 )
F_17 ( V_5 , V_8 ) ;
if ( V_36 -> V_72 )
F_17 ( V_5 , V_24 ) ;
return 0 ;
}
static int F_40 ( struct V_4 * V_5 ,
struct V_73 * V_74 ,
unsigned int V_75 )
{
T_2 V_76 = F_3 ( V_5 -> V_9 , V_5 -> V_77 ) ;
T_2 V_78 = F_3 ( V_5 -> V_9 , V_5 -> V_79 ) ;
T_2 V_80 ;
if ( V_5 -> V_22 & V_23 &&
V_5 -> V_81 & V_82 )
V_76 = V_76 & ~ F_41 ( 5 ) ;
if ( F_42 ( V_76 ) ) {
F_32 ( V_5 -> V_5 , L_6 ) ;
V_80 = F_43 ( V_76 ) ;
if ( F_44 ( V_80 >= F_45 ( V_83 ) ) )
return - V_25 ;
V_74 -> V_84 . V_85 = V_86 ;
V_74 -> V_84 . V_87 =
1 << ( F_46 ( V_76 ) + 1 ) ;
V_74 -> V_84 . V_83 = V_83 [ V_80 ] ;
V_74 -> V_84 . V_75 = V_75 ;
}
if ( F_47 ( V_76 ) ) {
F_32 ( V_5 -> V_5 , L_7 ) ;
V_80 = F_48 ( V_78 ) ;
if ( F_44 ( V_80 >= F_45 ( V_83 ) ) )
return - V_25 ;
V_74 -> V_88 . V_85 = V_86 ;
V_74 -> V_88 . V_87 =
1 << ( F_49 ( V_76 ) + 1 ) ;
V_74 -> V_88 . V_83 = V_83 [ V_80 ] ;
V_74 -> V_88 . V_75 = V_75 ;
}
if ( F_50 ( V_76 ) ) {
F_32 ( V_5 -> V_5 , L_8 ) ;
V_5 -> V_22 |= V_49 ;
} else {
F_32 ( V_5 -> V_5 , L_9 ) ;
V_5 -> V_22 |= V_65 ;
}
return 0 ;
}
static int F_51 ( struct V_4 * V_5 ,
struct V_73 * V_74 ,
struct V_89 * V_90 ,
const struct V_91 * V_92 )
{
T_2 V_76 = F_3 ( V_5 -> V_9 , V_5 -> V_77 ) ;
T_2 V_80 = F_52 ( V_76 ) ;
int V_37 ;
if ( F_44 ( V_80 >= F_45 ( V_93 ) ) )
return - V_25 ;
V_37 = F_40 ( V_5 , V_74 , V_92 -> V_94 ) ;
if ( V_37 < 0 )
return V_37 ;
V_5 -> V_27 . V_95 . V_96 = V_92 -> V_27 ;
V_5 -> V_28 . V_95 . V_96 = V_92 -> V_28 ;
V_5 -> V_27 . V_95 . V_97 = V_90 -> V_98 + V_99 ;
V_5 -> V_28 . V_95 . V_97 = V_90 -> V_98 + V_100 ;
V_5 -> V_27 . V_95 . V_101 = 16 ;
V_5 -> V_28 . V_95 . V_101 = 16 ;
V_5 -> V_27 . V_95 . V_102 = V_93 [ V_80 ] ;
V_5 -> V_28 . V_95 . V_102 = V_93 [ V_80 ] ;
V_5 -> V_27 . V_95 . V_103 = V_92 -> V_103 ;
V_5 -> V_28 . V_95 . V_103 = V_92 -> V_103 ;
return 0 ;
}
static int F_53 ( struct V_4 * V_5 ,
struct V_73 * V_74 ,
struct V_89 * V_90 )
{
T_2 V_76 = F_3 ( V_5 -> V_9 , V_104 ) ;
T_2 V_78 = F_3 ( V_5 -> V_9 , V_105 ) ;
T_2 V_106 = 1 << ( 1 + F_54 ( V_76 ) ) ;
T_2 V_80 = F_52 ( V_76 ) ;
T_2 V_107 ;
int V_37 ;
if ( F_44 ( V_80 >= F_45 ( V_93 ) ) )
return - V_25 ;
V_37 = F_40 ( V_5 , V_74 , V_108 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( F_42 ( V_76 ) ) {
V_107 = F_43 ( V_76 ) ;
V_5 -> V_22 |= V_26 ;
V_5 -> V_27 . V_109 . V_97 = V_90 -> V_98 + V_99 ;
V_5 -> V_27 . V_109 . V_102 = V_93 [ V_80 ] ;
V_5 -> V_27 . V_109 . V_110 = L_10 ;
V_5 -> V_27 . V_109 . V_111 = V_106 *
( V_112 [ V_107 ] ) >> 8 ;
V_5 -> V_27 . V_109 . V_113 = 16 ;
}
if ( F_47 ( V_76 ) ) {
V_107 = F_48 ( V_78 ) ;
V_5 -> V_22 |= V_23 ;
V_5 -> V_28 . V_109 . V_97 = V_90 -> V_98 + V_100 ;
V_5 -> V_28 . V_109 . V_102 = V_93 [ V_80 ] ;
V_5 -> V_28 . V_109 . V_110 = L_11 ;
V_5 -> V_28 . V_109 . V_111 = V_106 *
( V_112 [ V_107 ] >> 8 ) ;
V_5 -> V_28 . V_109 . V_113 = 16 ;
}
return 0 ;
}
static int F_55 ( struct V_114 * V_115 )
{
const struct V_91 * V_92 = V_115 -> V_5 . V_116 ;
struct V_4 * V_5 ;
struct V_89 * V_90 ;
int V_37 ;
struct V_73 * V_74 ;
const char * V_117 ;
V_5 = F_56 ( & V_115 -> V_5 , sizeof( * V_5 ) , V_118 ) ;
if ( ! V_5 ) {
F_57 ( & V_115 -> V_5 , L_12 ) ;
return - V_119 ;
}
V_74 = F_56 ( & V_115 -> V_5 , sizeof( * V_74 ) , V_118 ) ;
if ( ! V_74 )
return - V_119 ;
V_74 -> V_120 = & V_121 ;
V_74 -> V_122 = F_38 ;
V_74 -> V_123 = F_39 ;
V_90 = F_58 ( V_115 , V_124 , 0 ) ;
V_5 -> V_9 = F_59 ( & V_115 -> V_5 , V_90 ) ;
if ( F_60 ( V_5 -> V_9 ) )
return F_61 ( V_5 -> V_9 ) ;
V_5 -> V_5 = & V_115 -> V_5 ;
V_5 -> V_77 = V_104 ;
V_5 -> V_79 = V_105 ;
if ( V_92 ) {
V_5 -> V_22 = V_92 -> V_125 ;
V_117 = NULL ;
V_5 -> V_81 = V_92 -> V_81 ;
if ( V_5 -> V_81 & V_126 ) {
V_5 -> V_77 = V_92 -> V_77 ;
V_5 -> V_79 = V_92 -> V_79 ;
}
V_37 = F_51 ( V_5 , V_74 , V_90 , V_92 ) ;
} else {
V_117 = L_13 ;
V_37 = F_53 ( V_5 , V_74 , V_90 ) ;
}
if ( V_37 < 0 )
return V_37 ;
if ( V_5 -> V_22 & V_49 ) {
if ( V_92 ) {
V_5 -> V_50 = V_92 -> V_50 ;
if ( ! V_5 -> V_50 ) {
F_24 ( & V_115 -> V_5 , L_14 ) ;
return - V_127 ;
}
}
V_5 -> V_52 = F_62 ( & V_115 -> V_5 , V_117 ) ;
if ( F_60 ( V_5 -> V_52 ) )
return F_61 ( V_5 -> V_52 ) ;
V_37 = F_63 ( V_5 -> V_52 ) ;
if ( V_37 < 0 )
return V_37 ;
}
F_64 ( & V_115 -> V_5 , V_5 ) ;
V_37 = F_65 ( & V_115 -> V_5 , & V_128 ,
V_74 , 1 ) ;
if ( V_37 != 0 ) {
F_24 ( & V_115 -> V_5 , L_15 ) ;
goto V_129;
}
if ( ! V_92 ) {
V_37 = F_66 ( & V_115 -> V_5 , NULL , 0 ) ;
if ( V_37 ) {
F_24 ( & V_115 -> V_5 ,
L_16 , V_37 ) ;
goto V_129;
}
}
F_67 ( & V_115 -> V_5 ) ;
return 0 ;
V_129:
if ( V_5 -> V_22 & V_49 )
F_68 ( V_5 -> V_52 ) ;
return V_37 ;
}
static int F_69 ( struct V_114 * V_115 )
{
struct V_4 * V_5 = F_34 ( & V_115 -> V_5 ) ;
if ( V_5 -> V_22 & V_49 )
F_68 ( V_5 -> V_52 ) ;
F_70 ( & V_115 -> V_5 ) ;
return 0 ;
}
