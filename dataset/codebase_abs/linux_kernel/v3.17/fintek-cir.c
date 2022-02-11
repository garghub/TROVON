static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( L_1 ,
V_5 , V_4 , V_3 , V_2 -> V_6 , V_2 -> V_7 ) ;
F_3 ( V_4 , V_2 -> V_6 ) ;
F_3 ( V_3 , V_2 -> V_7 ) ;
}
static inline T_1 F_4 ( struct V_1 * V_2 , T_1 V_4 )
{
T_1 V_3 ;
F_3 ( V_4 , V_2 -> V_6 ) ;
V_3 = F_5 ( V_2 -> V_7 ) ;
F_2 ( L_1 ,
V_5 , V_4 , V_3 , V_2 -> V_6 , V_2 -> V_7 ) ;
return V_3 ;
}
static inline void F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 V_8 = F_4 ( V_2 , V_4 ) | V_3 ;
F_1 ( V_2 , V_8 , V_4 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 V_8 = F_4 ( V_2 , V_4 ) & ~ V_3 ;
F_1 ( V_2 , V_8 , V_4 ) ;
}
static inline void F_8 ( struct V_1 * V_2 )
{
F_3 ( V_9 , V_2 -> V_6 ) ;
F_3 ( V_9 , V_2 -> V_6 ) ;
}
static inline void F_9 ( struct V_1 * V_2 )
{
F_3 ( V_10 , V_2 -> V_6 ) ;
}
static inline void F_10 ( struct V_1 * V_2 , T_1 V_11 )
{
F_1 ( V_2 , V_11 , V_12 ) ;
}
static inline void F_11 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_13 )
{
F_3 ( V_3 , V_2 -> V_14 + V_13 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 , T_1 V_13 )
{
T_1 V_3 ;
V_3 = F_5 ( V_2 -> V_14 + V_13 ) ;
return V_3 ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
F_10 ( V_2 , V_2 -> V_15 ) ;
F_14 ( L_2 , V_16 ) ;
F_14 ( L_3 ,
( F_4 ( V_2 , V_17 ) << 8 ) |
F_4 ( V_2 , V_18 ) ) ;
F_14 ( L_4 ,
F_4 ( V_2 , V_19 ) ) ;
F_9 ( V_2 ) ;
F_14 ( L_5 , V_16 ) ;
F_14 ( L_6 ,
F_12 ( V_2 , V_20 ) ) ;
F_14 ( L_7 ,
F_12 ( V_2 , V_21 ) ) ;
F_14 ( L_8 ,
F_12 ( V_2 , V_22 ) ) ;
F_14 ( L_9 ,
F_12 ( V_2 , V_23 ) ) ;
F_14 ( L_10 ,
F_12 ( V_2 , V_24 ) ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
unsigned long V_25 ;
T_1 V_26 , V_27 ;
T_1 V_28 , V_29 ;
T_1 V_30 , V_31 ;
T_2 V_32 , V_33 ;
int V_34 = 0 ;
F_8 ( V_2 ) ;
V_30 = F_4 ( V_2 , V_35 ) ;
if ( V_30 == 0xff ) {
F_16 ( V_36 , L_11 ) ;
F_9 ( V_2 ) ;
V_2 -> V_6 = V_37 ;
V_2 -> V_7 = V_38 ;
F_8 ( V_2 ) ;
V_30 = F_4 ( V_2 , V_35 ) ;
}
F_2 ( L_12 , V_30 ) ;
V_31 = F_12 ( V_2 , V_39 ) ;
F_2 ( L_13 , V_31 ) ;
switch ( V_31 ) {
case V_40 :
case V_41 :
V_2 -> V_42 = true ;
break;
case V_43 :
default:
V_2 -> V_42 = false ;
break;
}
V_26 = F_4 ( V_2 , V_44 ) ;
V_27 = F_4 ( V_2 , V_45 ) ;
V_33 = V_26 << 8 | V_27 ;
V_28 = F_4 ( V_2 , V_46 ) ;
V_29 = F_4 ( V_2 , V_47 ) ;
V_32 = V_28 << 8 | V_29 ;
if ( V_32 != V_48 )
F_16 ( V_49 , L_14 , V_32 ) ;
else
F_2 ( L_15 ) ;
F_9 ( V_2 ) ;
F_17 ( & V_2 -> V_50 , V_25 ) ;
V_2 -> V_26 = V_26 ;
V_2 -> V_27 = V_27 ;
V_2 -> V_51 = V_32 ;
if ( ( V_33 != 0x0408 ) && ( V_33 != 0x0804 ) )
V_2 -> V_15 = V_52 ;
else
V_2 -> V_15 = V_53 ;
F_18 ( & V_2 -> V_50 , V_25 ) ;
return V_34 ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_2 -> V_15 ) ;
F_1 ( V_2 , V_54 , V_55 ) ;
F_1 ( V_2 , V_2 -> V_14 >> 8 , V_17 ) ;
F_1 ( V_2 , V_2 -> V_14 & 0xff , V_18 ) ;
F_1 ( V_2 , V_2 -> V_56 , V_19 ) ;
F_2 ( L_16 ,
V_2 -> V_14 , V_2 -> V_56 , V_2 -> V_57 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_11 ( V_2 , V_58 , V_20 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_11 ( V_2 , V_59 , V_20 ) ;
F_20 ( V_2 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
F_10 ( V_2 , V_60 ) ;
F_6 ( V_2 , V_61 , V_62 ) ;
F_6 ( V_2 , V_63 , V_64 ) ;
F_6 ( V_2 , V_63 , V_65 ) ;
F_6 ( V_2 , V_66 , V_67 ) ;
F_9 ( V_2 ) ;
}
static int F_23 ( T_1 V_68 , T_1 V_69 )
{
int V_70 = 0 ;
switch ( V_68 ) {
case V_71 :
if ( V_69 == V_72 )
V_70 = 1 ;
break;
case V_72 :
if ( V_69 == V_73 )
V_70 = 2 ;
break;
case V_74 :
switch ( V_69 ) {
case V_75 :
case V_76 :
case V_77 :
V_70 = 2 ;
break;
case V_78 :
case V_79 :
case V_80 :
V_70 = 1 ;
break;
}
}
return V_70 ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_25 ( V_81 ) ;
T_1 V_82 ;
bool V_83 = false ;
int V_84 ;
for ( V_84 = 0 ; V_84 < V_2 -> V_85 ; V_84 ++ ) {
V_82 = V_2 -> V_86 [ V_84 ] ;
switch ( V_2 -> V_87 ) {
case V_88 :
V_2 -> V_68 = V_82 ;
if ( ( V_2 -> V_68 == V_74 ) ||
( ( V_2 -> V_68 & V_89 ) !=
V_90 ) ) {
V_2 -> V_87 = V_91 ;
continue;
}
V_2 -> V_92 = ( V_2 -> V_68 & V_93 ) ;
F_2 ( L_17 , V_5 , V_2 -> V_92 ) ;
if ( V_2 -> V_92 )
V_2 -> V_87 = V_94 ;
else
F_26 ( V_2 -> V_95 ) ;
break;
case V_91 :
V_2 -> V_92 = F_23 ( V_2 -> V_68 , V_82 ) ;
V_2 -> V_87 = V_96 ;
break;
case V_96 :
V_2 -> V_92 -- ;
break;
case V_94 :
V_2 -> V_92 -- ;
F_27 ( & V_81 ) ;
V_81 . V_97 = ( ( V_82 & V_90 ) != 0 ) ;
V_81 . V_98 = F_28 ( ( V_82 & V_99 )
* V_100 ) ;
F_2 ( L_18 ,
V_81 . V_97 ? L_19 : L_20 ,
V_81 . V_98 ) ;
if ( F_29 ( V_2 -> V_95 ,
& V_81 ) )
V_83 = true ;
break;
}
if ( ( V_2 -> V_87 != V_88 ) && ! V_2 -> V_92 )
V_2 -> V_87 = V_88 ;
}
V_2 -> V_85 = 0 ;
if ( V_83 ) {
F_2 ( L_21 ) ;
F_30 ( V_2 -> V_95 ) ;
}
}
static void F_31 ( struct V_1 * V_2 , T_1 V_101 )
{
unsigned long V_25 ;
T_1 V_82 , V_102 ;
F_17 ( & V_2 -> V_50 , V_25 ) ;
do {
V_82 = F_12 ( V_2 , V_22 ) ;
F_2 ( L_22 , V_5 , V_82 ) ;
V_2 -> V_86 [ V_2 -> V_85 ] = V_82 ;
V_2 -> V_85 ++ ;
V_102 = F_12 ( V_2 , V_20 ) ;
if ( ! ( V_102 & V_58 ) )
break;
} while ( V_102 & V_101 );
F_24 ( V_2 ) ;
F_18 ( & V_2 -> V_50 , V_25 ) ;
}
static void F_32 ( T_1 V_102 )
{
F_16 ( V_36 , L_23 , V_102 ,
V_102 & V_58 ? L_24 : L_25 ,
V_102 & V_103 ? L_26 : L_25 ,
V_102 & V_104 ? L_27 : L_25 ,
V_102 & V_105 ? L_28 : L_25 ,
V_102 & V_106 ? L_29 : L_25 ) ;
}
static T_3 F_33 ( int V_107 , void * V_108 )
{
struct V_1 * V_2 = V_108 ;
T_1 V_102 , V_101 ;
F_34 ( L_30 , V_5 ) ;
F_8 ( V_2 ) ;
F_10 ( V_2 , V_2 -> V_15 ) ;
F_9 ( V_2 ) ;
V_102 = F_12 ( V_2 , V_20 ) ;
if ( ! ( V_102 & V_59 ) || V_102 == 0xff ) {
F_34 ( L_31 , V_5 , V_102 ) ;
F_11 ( V_2 , V_59 , V_20 ) ;
return F_35 ( V_109 ) ;
}
if ( V_110 )
F_32 ( V_102 ) ;
V_101 = V_102 & ( V_106 | V_105 ) ;
if ( V_101 )
F_31 ( V_2 , V_101 ) ;
F_11 ( V_2 , V_102 , V_20 ) ;
F_34 ( L_32 , V_5 ) ;
return F_35 ( V_111 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_11 ( V_2 , V_58 , V_20 ) ;
F_8 ( V_2 ) ;
F_10 ( V_2 , V_2 -> V_15 ) ;
F_1 ( V_2 , V_54 , V_55 ) ;
F_9 ( V_2 ) ;
F_11 ( V_2 , V_59 , V_20 ) ;
F_20 ( V_2 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
F_10 ( V_2 , V_2 -> V_15 ) ;
F_1 ( V_2 , V_112 , V_55 ) ;
F_9 ( V_2 ) ;
}
static int F_38 ( struct V_113 * V_114 )
{
struct V_1 * V_2 = V_114 -> V_115 ;
unsigned long V_25 ;
F_17 ( & V_2 -> V_50 , V_25 ) ;
F_36 ( V_2 ) ;
F_18 ( & V_2 -> V_50 , V_25 ) ;
return 0 ;
}
static void F_39 ( struct V_113 * V_114 )
{
struct V_1 * V_2 = V_114 -> V_115 ;
unsigned long V_25 ;
F_17 ( & V_2 -> V_50 , V_25 ) ;
F_37 ( V_2 ) ;
F_18 ( & V_2 -> V_50 , V_25 ) ;
}
static int F_40 ( struct V_116 * V_117 , const struct V_118 * V_119 )
{
struct V_1 * V_2 ;
struct V_113 * V_95 ;
int V_34 = - V_120 ;
V_2 = F_41 ( sizeof( struct V_1 ) , V_121 ) ;
if ( ! V_2 )
return V_34 ;
V_95 = F_42 () ;
if ( ! V_95 )
goto V_122;
V_34 = - V_123 ;
if ( ! F_43 ( V_117 , 0 ) ) {
F_44 ( & V_117 -> V_114 , L_33 ) ;
goto V_122;
}
if ( ! F_45 ( V_117 , 0 ) ) {
F_44 ( & V_117 -> V_114 , L_34 ) ;
goto V_122;
}
V_2 -> V_14 = F_46 ( V_117 , 0 ) ;
V_2 -> V_56 = F_47 ( V_117 , 0 ) ;
V_2 -> V_57 = F_48 ( V_117 , 0 ) ;
V_2 -> V_6 = V_124 ;
V_2 -> V_7 = V_125 ;
F_49 ( & V_2 -> V_50 ) ;
F_50 ( V_117 , V_2 ) ;
V_2 -> V_117 = V_117 ;
V_34 = F_15 ( V_2 ) ;
if ( V_34 )
goto V_122;
F_8 ( V_2 ) ;
F_19 ( V_2 ) ;
F_9 ( V_2 ) ;
F_21 ( V_2 ) ;
V_95 -> V_115 = V_2 ;
V_95 -> V_126 = V_127 ;
V_95 -> V_128 = V_129 ;
V_95 -> V_130 = F_38 ;
V_95 -> V_131 = F_39 ;
V_95 -> V_132 = V_133 ;
V_95 -> V_134 = L_35 ;
V_95 -> V_135 . V_136 = V_137 ;
V_95 -> V_135 . V_32 = V_48 ;
V_95 -> V_135 . V_138 = V_2 -> V_26 ;
V_95 -> V_135 . V_139 = V_2 -> V_27 ;
V_95 -> V_114 . V_140 = & V_117 -> V_114 ;
V_95 -> V_141 = V_16 ;
V_95 -> V_142 = V_143 ;
V_95 -> V_144 = F_28 ( 1000 ) ;
V_95 -> V_145 = F_28 ( V_100 ) ;
V_2 -> V_95 = V_95 ;
V_34 = - V_146 ;
if ( ! F_51 ( V_2 -> V_14 ,
V_2 -> V_57 , V_16 ) )
goto V_122;
if ( F_52 ( V_2 -> V_56 , F_33 , V_147 ,
V_16 , ( void * ) V_2 ) )
goto V_148;
V_34 = F_53 ( V_95 ) ;
if ( V_34 )
goto V_149;
F_54 ( & V_117 -> V_114 , true ) ;
F_16 ( V_150 , L_36 ) ;
if ( V_110 )
F_13 ( V_2 ) ;
return 0 ;
V_149:
F_55 ( V_2 -> V_56 , V_2 ) ;
V_148:
F_56 ( V_2 -> V_14 , V_2 -> V_57 ) ;
V_122:
F_57 ( V_95 ) ;
F_58 ( V_2 ) ;
return V_34 ;
}
static void F_59 ( struct V_116 * V_117 )
{
struct V_1 * V_2 = F_60 ( V_117 ) ;
unsigned long V_25 ;
F_17 ( & V_2 -> V_50 , V_25 ) ;
F_37 ( V_2 ) ;
F_11 ( V_2 , V_59 , V_20 ) ;
F_22 ( V_2 ) ;
F_18 ( & V_2 -> V_50 , V_25 ) ;
F_55 ( V_2 -> V_56 , V_2 ) ;
F_56 ( V_2 -> V_14 , V_2 -> V_57 ) ;
F_61 ( V_2 -> V_95 ) ;
F_58 ( V_2 ) ;
}
static int F_62 ( struct V_116 * V_117 , T_4 V_151 )
{
struct V_1 * V_2 = F_60 ( V_117 ) ;
unsigned long V_25 ;
F_2 ( L_37 , V_5 ) ;
F_17 ( & V_2 -> V_50 , V_25 ) ;
F_11 ( V_2 , V_59 , V_20 ) ;
F_18 ( & V_2 -> V_50 , V_25 ) ;
F_8 ( V_2 ) ;
F_10 ( V_2 , V_2 -> V_15 ) ;
F_1 ( V_2 , V_112 , V_55 ) ;
F_9 ( V_2 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_63 ( struct V_116 * V_117 )
{
int V_34 = 0 ;
struct V_1 * V_2 = F_60 ( V_117 ) ;
F_2 ( L_37 , V_5 ) ;
F_20 ( V_2 ) ;
F_8 ( V_2 ) ;
F_10 ( V_2 , V_2 -> V_15 ) ;
F_1 ( V_2 , V_54 , V_55 ) ;
F_9 ( V_2 ) ;
F_21 ( V_2 ) ;
return V_34 ;
}
static void F_64 ( struct V_116 * V_117 )
{
struct V_1 * V_2 = F_60 ( V_117 ) ;
F_22 ( V_2 ) ;
}
static int T_5 F_65 ( void )
{
return F_66 ( & V_152 ) ;
}
static void T_6 F_67 ( void )
{
F_68 ( & V_152 ) ;
}
