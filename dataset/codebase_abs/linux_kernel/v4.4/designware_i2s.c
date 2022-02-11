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
static int F_17 ( struct V_10 * V_11 ,
struct V_29 * V_30 , struct V_18 * V_31 )
{
struct V_4 * V_5 = F_15 ( V_31 ) ;
struct V_32 * V_33 = & V_5 -> V_33 ;
T_2 V_34 , V_35 , V_36 , V_12 ;
int V_37 ;
switch ( F_18 ( V_30 ) ) {
case V_38 :
V_33 -> V_39 = 16 ;
V_34 = 0x00 ;
V_35 = 0x02 ;
break;
case V_40 :
V_33 -> V_39 = 24 ;
V_34 = 0x08 ;
V_35 = 0x04 ;
break;
case V_41 :
V_33 -> V_39 = 32 ;
V_34 = 0x10 ;
V_35 = 0x05 ;
break;
default:
F_19 ( V_5 -> V_5 , L_1 ) ;
return - V_25 ;
}
V_33 -> V_42 = F_20 ( V_30 ) ;
switch ( V_33 -> V_42 ) {
case V_43 :
case V_44 :
case V_45 :
case V_46 :
break;
default:
F_19 ( V_5 -> V_5 , L_2 ) ;
return - V_25 ;
}
F_5 ( V_5 , V_11 -> V_6 ) ;
for ( V_36 = 0 ; V_36 < ( V_33 -> V_42 / 2 ) ; V_36 ++ ) {
if ( V_11 -> V_6 == V_8 ) {
F_1 ( V_5 -> V_9 , F_21 ( V_36 ) ,
V_35 ) ;
F_1 ( V_5 -> V_9 , F_22 ( V_36 ) , 0x02 ) ;
V_12 = F_3 ( V_5 -> V_9 , F_12 ( V_36 ) ) ;
F_1 ( V_5 -> V_9 , F_12 ( V_36 ) , V_12 & ~ 0x30 ) ;
F_1 ( V_5 -> V_9 , F_6 ( V_36 ) , 1 ) ;
} else {
F_1 ( V_5 -> V_9 , F_23 ( V_36 ) ,
V_35 ) ;
F_1 ( V_5 -> V_9 , F_24 ( V_36 ) , 0x07 ) ;
V_12 = F_3 ( V_5 -> V_9 , F_12 ( V_36 ) ) ;
F_1 ( V_5 -> V_9 , F_12 ( V_36 ) , V_12 & ~ 0x03 ) ;
F_1 ( V_5 -> V_9 , F_7 ( V_36 ) , 1 ) ;
}
}
F_1 ( V_5 -> V_9 , V_47 , V_34 ) ;
V_33 -> V_48 = F_25 ( V_30 ) ;
if ( V_5 -> V_22 & V_49 ) {
if ( V_5 -> V_50 ) {
V_37 = V_5 -> V_50 ( V_33 ) ;
if ( V_37 < 0 ) {
F_19 ( V_5 -> V_5 , L_3 ) ;
return V_37 ;
}
} else {
T_2 V_51 = V_33 -> V_48 *
V_33 -> V_39 * 2 ;
V_37 = F_26 ( V_5 -> V_52 , V_51 ) ;
if ( V_37 ) {
F_19 ( V_5 -> V_5 , L_4 ,
V_37 ) ;
return V_37 ;
}
}
}
return 0 ;
}
static void F_27 ( struct V_10 * V_11 ,
struct V_18 * V_31 )
{
F_16 ( V_31 , V_11 , NULL ) ;
}
static int F_28 ( struct V_10 * V_11 ,
struct V_18 * V_31 )
{
struct V_4 * V_5 = F_15 ( V_31 ) ;
if ( V_11 -> V_6 == V_8 )
F_1 ( V_5 -> V_9 , V_53 , 1 ) ;
else
F_1 ( V_5 -> V_9 , V_54 , 1 ) ;
return 0 ;
}
static int F_29 ( struct V_10 * V_11 ,
int V_55 , struct V_18 * V_31 )
{
struct V_4 * V_5 = F_15 ( V_31 ) ;
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
static int F_30 ( struct V_18 * V_19 , unsigned int V_62 )
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
F_31 ( V_5 -> V_5 , L_5 ) ;
V_37 = - V_25 ;
break;
}
return V_37 ;
}
static int F_32 ( struct V_18 * V_31 )
{
struct V_4 * V_5 = F_15 ( V_31 ) ;
if ( V_5 -> V_22 & V_49 )
F_33 ( V_5 -> V_52 ) ;
return 0 ;
}
static int F_34 ( struct V_18 * V_31 )
{
struct V_4 * V_5 = F_15 ( V_31 ) ;
if ( V_5 -> V_22 & V_49 )
F_35 ( V_5 -> V_52 ) ;
return 0 ;
}
static int F_36 ( struct V_4 * V_5 ,
struct V_69 * V_70 ,
unsigned int V_71 )
{
T_2 V_72 = F_3 ( V_5 -> V_9 , V_73 ) ;
T_2 V_74 = F_3 ( V_5 -> V_9 , V_75 ) ;
T_2 V_76 ;
if ( F_37 ( V_72 ) ) {
F_31 ( V_5 -> V_5 , L_6 ) ;
V_76 = F_38 ( V_72 ) ;
if ( F_39 ( V_76 >= F_40 ( V_77 ) ) )
return - V_25 ;
V_70 -> V_78 . V_79 = V_80 ;
V_70 -> V_78 . V_81 =
1 << ( F_41 ( V_72 ) + 1 ) ;
V_70 -> V_78 . V_77 = V_77 [ V_76 ] ;
V_70 -> V_78 . V_71 = V_71 ;
}
if ( F_42 ( V_72 ) ) {
F_31 ( V_5 -> V_5 , L_7 ) ;
V_76 = F_43 ( V_74 ) ;
if ( F_39 ( V_76 >= F_40 ( V_77 ) ) )
return - V_25 ;
V_70 -> V_82 . V_79 = V_80 ;
V_70 -> V_82 . V_81 =
1 << ( F_44 ( V_72 ) + 1 ) ;
V_70 -> V_82 . V_77 = V_77 [ V_76 ] ;
V_70 -> V_82 . V_71 = V_71 ;
}
if ( F_45 ( V_72 ) ) {
F_31 ( V_5 -> V_5 , L_8 ) ;
V_5 -> V_22 |= V_49 ;
} else {
F_31 ( V_5 -> V_5 , L_9 ) ;
V_5 -> V_22 |= V_65 ;
}
return 0 ;
}
static int F_46 ( struct V_4 * V_5 ,
struct V_69 * V_70 ,
struct V_83 * V_84 ,
const struct V_85 * V_86 )
{
T_2 V_72 = F_3 ( V_5 -> V_9 , V_73 ) ;
T_2 V_76 = F_47 ( V_72 ) ;
int V_37 ;
if ( F_39 ( V_76 >= F_40 ( V_87 ) ) )
return - V_25 ;
V_37 = F_36 ( V_5 , V_70 , V_86 -> V_88 ) ;
if ( V_37 < 0 )
return V_37 ;
V_5 -> V_27 . V_89 . V_90 = V_86 -> V_27 ;
V_5 -> V_28 . V_89 . V_90 = V_86 -> V_28 ;
V_5 -> V_27 . V_89 . V_91 = V_84 -> V_92 + V_93 ;
V_5 -> V_28 . V_89 . V_91 = V_84 -> V_92 + V_94 ;
V_5 -> V_27 . V_89 . V_95 = 16 ;
V_5 -> V_28 . V_89 . V_95 = 16 ;
V_5 -> V_27 . V_89 . V_96 = V_87 [ V_76 ] ;
V_5 -> V_28 . V_89 . V_96 = V_87 [ V_76 ] ;
V_5 -> V_27 . V_89 . V_97 = V_86 -> V_97 ;
V_5 -> V_28 . V_89 . V_97 = V_86 -> V_97 ;
return 0 ;
}
static int F_48 ( struct V_4 * V_5 ,
struct V_69 * V_70 ,
struct V_83 * V_84 )
{
T_2 V_72 = F_3 ( V_5 -> V_9 , V_73 ) ;
T_2 V_74 = F_3 ( V_5 -> V_9 , V_75 ) ;
T_2 V_98 = 1 << ( 1 + F_49 ( V_72 ) ) ;
T_2 V_76 = F_47 ( V_72 ) ;
T_2 V_99 ;
int V_37 ;
if ( F_39 ( V_76 >= F_40 ( V_87 ) ) )
return - V_25 ;
V_37 = F_36 ( V_5 , V_70 , V_100 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( F_37 ( V_72 ) ) {
V_99 = F_38 ( V_72 ) ;
V_5 -> V_22 |= V_26 ;
V_5 -> V_27 . V_101 . V_91 = V_84 -> V_92 + V_93 ;
V_5 -> V_27 . V_101 . V_96 = V_87 [ V_76 ] ;
V_5 -> V_27 . V_101 . V_102 = L_10 ;
V_5 -> V_27 . V_101 . V_103 = V_98 *
( V_104 [ V_99 ] ) >> 8 ;
V_5 -> V_27 . V_101 . V_105 = 16 ;
}
if ( F_42 ( V_72 ) ) {
V_99 = F_43 ( V_74 ) ;
V_5 -> V_22 |= V_23 ;
V_5 -> V_28 . V_101 . V_91 = V_84 -> V_92 + V_94 ;
V_5 -> V_28 . V_101 . V_96 = V_87 [ V_76 ] ;
V_5 -> V_28 . V_101 . V_102 = L_11 ;
V_5 -> V_28 . V_101 . V_103 = V_98 *
( V_104 [ V_99 ] >> 8 ) ;
V_5 -> V_28 . V_101 . V_105 = 16 ;
}
return 0 ;
}
static int F_50 ( struct V_106 * V_107 )
{
const struct V_85 * V_86 = V_107 -> V_5 . V_108 ;
struct V_4 * V_5 ;
struct V_83 * V_84 ;
int V_37 ;
struct V_69 * V_70 ;
const char * V_109 ;
V_5 = F_51 ( & V_107 -> V_5 , sizeof( * V_5 ) , V_110 ) ;
if ( ! V_5 ) {
F_52 ( & V_107 -> V_5 , L_12 ) ;
return - V_111 ;
}
V_70 = F_51 ( & V_107 -> V_5 , sizeof( * V_70 ) , V_110 ) ;
if ( ! V_70 )
return - V_111 ;
V_70 -> V_112 = & V_113 ;
V_70 -> V_114 = F_32 ;
V_70 -> V_115 = F_34 ;
V_84 = F_53 ( V_107 , V_116 , 0 ) ;
V_5 -> V_9 = F_54 ( & V_107 -> V_5 , V_84 ) ;
if ( F_55 ( V_5 -> V_9 ) )
return F_56 ( V_5 -> V_9 ) ;
V_5 -> V_5 = & V_107 -> V_5 ;
if ( V_86 ) {
V_5 -> V_22 = V_86 -> V_117 ;
V_109 = NULL ;
V_37 = F_46 ( V_5 , V_70 , V_84 , V_86 ) ;
} else {
V_109 = L_13 ;
V_37 = F_48 ( V_5 , V_70 , V_84 ) ;
}
if ( V_37 < 0 )
return V_37 ;
if ( V_5 -> V_22 & V_49 ) {
if ( V_86 ) {
V_5 -> V_50 = V_86 -> V_50 ;
if ( ! V_5 -> V_50 ) {
F_19 ( & V_107 -> V_5 , L_14 ) ;
return - V_118 ;
}
}
V_5 -> V_52 = F_57 ( & V_107 -> V_5 , V_109 ) ;
if ( F_55 ( V_5 -> V_52 ) )
return F_56 ( V_5 -> V_52 ) ;
V_37 = F_58 ( V_5 -> V_52 ) ;
if ( V_37 < 0 )
return V_37 ;
}
F_59 ( & V_107 -> V_5 , V_5 ) ;
V_37 = F_60 ( & V_107 -> V_5 , & V_119 ,
V_70 , 1 ) ;
if ( V_37 != 0 ) {
F_19 ( & V_107 -> V_5 , L_15 ) ;
goto V_120;
}
if ( ! V_86 ) {
V_37 = F_61 ( & V_107 -> V_5 , NULL , 0 ) ;
if ( V_37 ) {
F_19 ( & V_107 -> V_5 ,
L_16 , V_37 ) ;
goto V_120;
}
}
return 0 ;
V_120:
if ( V_5 -> V_22 & V_49 )
F_62 ( V_5 -> V_52 ) ;
return V_37 ;
}
static int F_63 ( struct V_106 * V_107 )
{
struct V_4 * V_5 = F_64 ( & V_107 -> V_5 ) ;
if ( V_5 -> V_22 & V_49 )
F_62 ( V_5 -> V_52 ) ;
return 0 ;
}
