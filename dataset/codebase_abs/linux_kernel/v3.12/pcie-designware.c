static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
int F_2 ( void T_1 * V_5 , int V_6 , int V_7 , T_2 * V_8 )
{
* V_8 = F_3 ( V_5 ) ;
if ( V_7 == 1 )
* V_8 = ( * V_8 >> ( 8 * ( V_6 & 3 ) ) ) & 0xff ;
else if ( V_7 == 2 )
* V_8 = ( * V_8 >> ( 8 * ( V_6 & 3 ) ) ) & 0xffff ;
else if ( V_7 != 4 )
return V_9 ;
return V_10 ;
}
int F_4 ( void T_1 * V_5 , int V_6 , int V_7 , T_2 V_8 )
{
if ( V_7 == 4 )
F_5 ( V_8 , V_5 ) ;
else if ( V_7 == 2 )
F_6 ( V_8 , V_5 + ( V_6 & 2 ) ) ;
else if ( V_7 == 1 )
F_7 ( V_8 , V_5 + ( V_6 & 3 ) ) ;
else
return V_9 ;
return V_10 ;
}
static inline void F_8 ( struct V_1 * V_11 , T_2 V_12 , T_2 * V_8 )
{
if ( V_11 -> V_13 -> V_14 )
V_11 -> V_13 -> V_14 ( V_11 , V_11 -> V_15 + V_12 , V_8 ) ;
else
* V_8 = F_3 ( V_11 -> V_15 + V_12 ) ;
}
static inline void F_9 ( struct V_1 * V_11 , T_2 V_8 , T_2 V_12 )
{
if ( V_11 -> V_13 -> V_16 )
V_11 -> V_13 -> V_16 ( V_11 , V_8 , V_11 -> V_15 + V_12 ) ;
else
F_5 ( V_8 , V_11 -> V_15 + V_12 ) ;
}
int F_10 ( struct V_1 * V_11 , int V_6 , int V_7 ,
T_2 * V_8 )
{
int V_17 ;
if ( V_11 -> V_13 -> V_18 )
V_17 = V_11 -> V_13 -> V_18 ( V_11 , V_6 , V_7 , V_8 ) ;
else
V_17 = F_2 ( V_11 -> V_15 + ( V_6 & ~ 0x3 ) , V_6 , V_7 , V_8 ) ;
return V_17 ;
}
int F_11 ( struct V_1 * V_11 , int V_6 , int V_7 ,
T_2 V_8 )
{
int V_17 ;
if ( V_11 -> V_13 -> V_19 )
V_17 = V_11 -> V_13 -> V_19 ( V_11 , V_6 , V_7 , V_8 ) ;
else
V_17 = F_4 ( V_11 -> V_15 + ( V_6 & ~ 0x3 ) , V_6 , V_7 ,
V_8 ) ;
return V_17 ;
}
int F_12 ( struct V_1 * V_11 )
{
if ( V_11 -> V_13 -> V_20 )
return V_11 -> V_13 -> V_20 ( V_11 ) ;
else
return 0 ;
}
int T_3 F_13 ( struct V_1 * V_11 )
{
struct V_21 * V_22 = V_11 -> V_23 -> V_24 ;
struct V_25 V_26 ;
struct V_27 V_28 ;
T_2 V_8 ;
if ( F_14 ( & V_28 , V_22 ) ) {
F_15 ( V_11 -> V_23 , L_1 ) ;
return - V_29 ;
}
F_16 (&parser, &range) {
unsigned long V_30 = V_26 . V_31 & V_32 ;
if ( V_30 == V_33 ) {
F_17 ( & V_26 , V_22 , & V_11 -> V_34 ) ;
V_11 -> V_34 . V_35 = L_2 ;
V_11 -> V_34 . V_36 = F_18 ( V_37 ,
V_38 ,
V_26 . V_39 + V_40 ) ;
V_11 -> V_34 . V_41 = F_19 ( V_37 ,
V_42 ,
V_26 . V_39 + V_26 . V_7
+ V_40 ) ;
V_11 -> V_43 . V_44 = F_20 ( & V_11 -> V_34 ) ;
V_11 -> V_43 . V_45 = V_26 . V_39 ;
}
if ( V_30 == V_46 ) {
F_17 ( & V_26 , V_22 , & V_11 -> V_47 ) ;
V_11 -> V_47 . V_35 = L_3 ;
V_11 -> V_43 . V_48 = F_20 ( & V_11 -> V_47 ) ;
V_11 -> V_43 . V_49 = V_26 . V_39 ;
}
if ( V_30 == 0 ) {
F_17 ( & V_26 , V_22 , & V_11 -> V_50 ) ;
V_11 -> V_43 . V_51 = F_20 ( & V_11 -> V_50 ) / 2 ;
V_11 -> V_43 . V_52 = F_20 ( & V_11 -> V_50 ) / 2 ;
}
}
if ( ! V_11 -> V_15 ) {
V_11 -> V_15 = F_21 ( V_11 -> V_23 , V_11 -> V_50 . V_36 ,
F_20 ( & V_11 -> V_50 ) ) ;
if ( ! V_11 -> V_15 ) {
F_15 ( V_11 -> V_23 , L_4 ) ;
return - V_53 ;
}
}
V_11 -> V_54 = V_11 -> V_50 . V_36 ;
V_11 -> V_55 = V_11 -> V_50 . V_36 + V_11 -> V_43 . V_51 ;
V_11 -> V_56 = V_11 -> V_34 . V_36 ;
V_11 -> V_57 = V_11 -> V_47 . V_36 ;
V_11 -> V_58 = F_21 ( V_11 -> V_23 , V_11 -> V_54 ,
V_11 -> V_43 . V_51 ) ;
if ( ! V_11 -> V_58 ) {
F_15 ( V_11 -> V_23 , L_5 ) ;
return - V_53 ;
}
V_11 -> V_59 = F_21 ( V_11 -> V_23 , V_11 -> V_55 ,
V_11 -> V_43 . V_52 ) ;
if ( ! V_11 -> V_59 ) {
F_15 ( V_11 -> V_23 , L_4 ) ;
return - V_53 ;
}
if ( F_22 ( V_22 , L_6 , & V_11 -> V_60 ) ) {
F_15 ( V_11 -> V_23 , L_7 ) ;
return - V_29 ;
}
if ( V_11 -> V_13 -> V_61 )
V_11 -> V_13 -> V_61 ( V_11 ) ;
F_11 ( V_11 , V_62 , 4 , 0 ) ;
F_11 ( V_11 , V_63 , 2 , V_64 ) ;
F_10 ( V_11 , V_65 , 4 , & V_8 ) ;
V_8 |= V_66 ;
F_11 ( V_11 , V_65 , 4 , V_8 ) ;
V_67 . V_68 = 1 ;
V_67 . V_4 = ( void * * ) & V_11 ;
F_23 ( & V_67 ) ;
F_24 () ;
#ifdef F_25
V_67 . V_69 ++ ;
#endif
return 0 ;
}
static void F_26 ( struct V_1 * V_11 , T_2 V_70 )
{
F_9 ( V_11 , V_71 | V_72 ,
V_73 ) ;
F_9 ( V_11 , V_11 -> V_54 , V_74 ) ;
F_9 ( V_11 , ( V_11 -> V_54 >> 32 ) , V_75 ) ;
F_9 ( V_11 , V_11 -> V_54 + V_11 -> V_43 . V_51 - 1 ,
V_76 ) ;
F_9 ( V_11 , V_70 , V_77 ) ;
F_9 ( V_11 , 0 , V_78 ) ;
F_9 ( V_11 , V_79 , V_80 ) ;
F_9 ( V_11 , V_81 , V_82 ) ;
}
static void F_27 ( struct V_1 * V_11 , T_2 V_70 )
{
F_9 ( V_11 , V_71 | V_83 ,
V_73 ) ;
F_9 ( V_11 , V_84 , V_80 ) ;
F_9 ( V_11 , V_81 , V_82 ) ;
F_9 ( V_11 , V_11 -> V_55 , V_74 ) ;
F_9 ( V_11 , ( V_11 -> V_55 >> 32 ) , V_75 ) ;
F_9 ( V_11 , V_11 -> V_55 + V_11 -> V_43 . V_52 - 1 ,
V_76 ) ;
F_9 ( V_11 , V_70 , V_77 ) ;
F_9 ( V_11 , 0 , V_78 ) ;
}
static void F_28 ( struct V_1 * V_11 )
{
F_9 ( V_11 , V_71 | V_72 ,
V_73 ) ;
F_9 ( V_11 , V_85 , V_80 ) ;
F_9 ( V_11 , V_81 , V_82 ) ;
F_9 ( V_11 , V_11 -> V_57 , V_74 ) ;
F_9 ( V_11 , ( V_11 -> V_57 >> 32 ) , V_75 ) ;
F_9 ( V_11 , V_11 -> V_57 + V_11 -> V_43 . V_48 - 1 ,
V_76 ) ;
F_9 ( V_11 , V_11 -> V_43 . V_49 , V_77 ) ;
F_9 ( V_11 , F_29 ( V_11 -> V_43 . V_49 ) ,
V_78 ) ;
}
static void F_30 ( struct V_1 * V_11 )
{
F_9 ( V_11 , V_71 | V_83 ,
V_73 ) ;
F_9 ( V_11 , V_86 , V_80 ) ;
F_9 ( V_11 , V_81 , V_82 ) ;
F_9 ( V_11 , V_11 -> V_56 , V_74 ) ;
F_9 ( V_11 , ( V_11 -> V_56 >> 32 ) , V_75 ) ;
F_9 ( V_11 , V_11 -> V_56 + V_11 -> V_43 . V_44 - 1 ,
V_76 ) ;
F_9 ( V_11 , V_11 -> V_43 . V_45 , V_77 ) ;
F_9 ( V_11 , F_29 ( V_11 -> V_43 . V_45 ) ,
V_78 ) ;
}
static int F_31 ( struct V_1 * V_11 , struct V_87 * V_88 ,
T_2 V_89 , int V_6 , int V_7 , T_2 * V_8 )
{
int V_17 = V_10 ;
T_2 V_90 , V_70 ;
V_70 = F_32 ( V_88 -> V_91 ) | F_33 ( F_34 ( V_89 ) ) |
F_35 ( F_36 ( V_89 ) ) ;
V_90 = V_6 & ~ 0x3 ;
if ( V_88 -> V_92 -> V_91 == V_11 -> V_93 ) {
F_26 ( V_11 , V_70 ) ;
V_17 = F_2 ( V_11 -> V_58 + V_90 , V_6 , V_7 , V_8 ) ;
F_28 ( V_11 ) ;
} else {
F_27 ( V_11 , V_70 ) ;
V_17 = F_2 ( V_11 -> V_59 + V_90 , V_6 , V_7 , V_8 ) ;
F_30 ( V_11 ) ;
}
return V_17 ;
}
static int F_37 ( struct V_1 * V_11 , struct V_87 * V_88 ,
T_2 V_89 , int V_6 , int V_7 , T_2 V_8 )
{
int V_17 = V_10 ;
T_2 V_90 , V_70 ;
V_70 = F_32 ( V_88 -> V_91 ) | F_33 ( F_34 ( V_89 ) ) |
F_35 ( F_36 ( V_89 ) ) ;
V_90 = V_6 & ~ 0x3 ;
if ( V_88 -> V_92 -> V_91 == V_11 -> V_93 ) {
F_26 ( V_11 , V_70 ) ;
V_17 = F_4 ( V_11 -> V_58 + V_90 , V_6 , V_7 , V_8 ) ;
F_28 ( V_11 ) ;
} else {
F_27 ( V_11 , V_70 ) ;
V_17 = F_4 ( V_11 -> V_59 + V_90 , V_6 , V_7 , V_8 ) ;
F_30 ( V_11 ) ;
}
return V_17 ;
}
static int F_38 ( struct V_1 * V_11 ,
struct V_87 * V_88 , int V_23 )
{
if ( V_88 -> V_91 != V_11 -> V_93 ) {
if ( ! F_12 ( V_11 ) )
return 0 ;
}
if ( V_88 -> V_91 == V_11 -> V_93 && V_23 > 0 )
return 0 ;
if ( V_88 -> V_94 == V_11 -> V_93 && V_23 > 0 )
return 0 ;
return 1 ;
}
static int F_39 ( struct V_87 * V_88 , T_2 V_89 , int V_6 ,
int V_7 , T_2 * V_8 )
{
struct V_1 * V_11 = F_1 ( V_88 -> V_95 ) ;
unsigned long V_31 ;
int V_17 ;
if ( ! V_11 ) {
F_40 () ;
return - V_29 ;
}
if ( F_38 ( V_11 , V_88 , F_34 ( V_89 ) ) == 0 ) {
* V_8 = 0xffffffff ;
return V_96 ;
}
F_41 ( & V_11 -> V_97 , V_31 ) ;
if ( V_88 -> V_91 != V_11 -> V_93 )
V_17 = F_31 ( V_11 , V_88 , V_89 ,
V_6 , V_7 , V_8 ) ;
else
V_17 = F_10 ( V_11 , V_6 , V_7 , V_8 ) ;
F_42 ( & V_11 -> V_97 , V_31 ) ;
return V_17 ;
}
static int F_43 ( struct V_87 * V_88 , T_2 V_89 ,
int V_6 , int V_7 , T_2 V_8 )
{
struct V_1 * V_11 = F_1 ( V_88 -> V_95 ) ;
unsigned long V_31 ;
int V_17 ;
if ( ! V_11 ) {
F_40 () ;
return - V_29 ;
}
if ( F_38 ( V_11 , V_88 , F_34 ( V_89 ) ) == 0 )
return V_96 ;
F_41 ( & V_11 -> V_97 , V_31 ) ;
if ( V_88 -> V_91 != V_11 -> V_93 )
V_17 = F_37 ( V_11 , V_88 , V_89 ,
V_6 , V_7 , V_8 ) ;
else
V_17 = F_11 ( V_11 , V_6 , V_7 , V_8 ) ;
F_42 ( & V_11 -> V_97 , V_31 ) ;
return V_17 ;
}
int F_44 ( int V_98 , struct V_2 * V_3 )
{
struct V_1 * V_11 ;
V_11 = F_1 ( V_3 ) ;
if ( ! V_11 )
return 0 ;
if ( V_40 < V_99 && V_11 -> V_43 . V_44 > 0 ) {
V_3 -> V_100 = V_40 - V_11 -> V_43 . V_45 ;
F_45 ( V_3 -> V_100 , V_11 -> V_34 . V_36 ) ;
V_40 += V_101 ;
F_46 ( & V_3 -> V_102 , & V_11 -> V_34 ,
V_3 -> V_100 ) ;
}
V_3 -> V_103 = V_11 -> V_47 . V_36 - V_11 -> V_43 . V_49 ;
F_46 ( & V_3 -> V_102 , & V_11 -> V_47 , V_3 -> V_103 ) ;
return 1 ;
}
struct V_87 * F_47 ( int V_98 , struct V_2 * V_3 )
{
struct V_87 * V_88 ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
if ( V_11 ) {
V_11 -> V_93 = V_3 -> V_104 ;
V_88 = F_48 ( NULL , V_3 -> V_104 , & V_105 ,
V_3 , & V_3 -> V_102 ) ;
} else {
V_88 = NULL ;
F_40 () ;
}
return V_88 ;
}
int F_49 ( const struct V_106 * V_23 , T_4 V_107 , T_4 V_108 )
{
struct V_1 * V_11 = F_1 ( V_23 -> V_88 -> V_95 ) ;
return V_11 -> V_109 ;
}
void F_50 ( struct V_1 * V_11 )
{
struct V_110 * V_43 = & V_11 -> V_43 ;
T_2 V_8 ;
T_2 V_111 ;
T_2 V_112 ;
F_8 ( V_11 , V_113 , & V_8 ) ;
V_8 &= ~ V_114 ;
switch ( V_11 -> V_60 ) {
case 1 :
V_8 |= V_115 ;
break;
case 2 :
V_8 |= V_116 ;
break;
case 4 :
V_8 |= V_117 ;
break;
}
F_9 ( V_11 , V_8 , V_113 ) ;
F_8 ( V_11 , V_65 , & V_8 ) ;
V_8 &= ~ V_118 ;
switch ( V_11 -> V_60 ) {
case 1 :
V_8 |= V_119 ;
break;
case 2 :
V_8 |= V_120 ;
break;
case 4 :
V_8 |= V_121 ;
break;
}
F_9 ( V_11 , V_8 , V_65 ) ;
F_9 ( V_11 , 0x00000004 , V_62 ) ;
F_9 ( V_11 , 0x00000004 , V_122 ) ;
F_8 ( V_11 , V_123 , & V_8 ) ;
V_8 &= 0xffff00ff ;
V_8 |= 0x00000100 ;
F_9 ( V_11 , V_8 , V_123 ) ;
F_8 ( V_11 , V_124 , & V_8 ) ;
V_8 &= 0xff000000 ;
V_8 |= 0x00010100 ;
F_9 ( V_11 , V_8 , V_124 ) ;
V_111 = ( ( T_2 ) V_11 -> V_57 & 0xfff00000 ) >> 16 ;
V_112 = ( V_43 -> V_48 + ( T_2 ) V_11 -> V_57 ) & 0xfff00000 ;
V_8 = V_112 | V_111 ;
F_9 ( V_11 , V_8 , V_125 ) ;
F_8 ( V_11 , V_126 , & V_8 ) ;
V_8 &= 0xffff0000 ;
V_8 |= V_127 | V_128 |
V_129 | V_130 ;
F_9 ( V_11 , V_8 , V_126 ) ;
}
