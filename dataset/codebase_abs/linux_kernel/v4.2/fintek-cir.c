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
F_8 ( V_2 ) ;
V_30 = F_4 ( V_2 , V_34 ) ;
if ( V_30 == 0xff ) {
F_16 ( V_35 , L_11 ) ;
F_9 ( V_2 ) ;
V_2 -> V_6 = V_36 ;
V_2 -> V_7 = V_37 ;
F_8 ( V_2 ) ;
V_30 = F_4 ( V_2 , V_34 ) ;
}
F_2 ( L_12 , V_30 ) ;
V_31 = F_12 ( V_2 , V_38 ) ;
F_2 ( L_13 , V_31 ) ;
switch ( V_31 ) {
case V_39 :
case V_40 :
V_2 -> V_41 = true ;
break;
case V_42 :
default:
V_2 -> V_41 = false ;
break;
}
V_26 = F_4 ( V_2 , V_43 ) ;
V_27 = F_4 ( V_2 , V_44 ) ;
V_33 = V_26 << 8 | V_27 ;
V_28 = F_4 ( V_2 , V_45 ) ;
V_29 = F_4 ( V_2 , V_46 ) ;
V_32 = V_28 << 8 | V_29 ;
if ( V_32 != V_47 )
F_16 ( V_48 , L_14 , V_32 ) ;
else
F_2 ( L_15 ) ;
F_9 ( V_2 ) ;
F_17 ( & V_2 -> V_49 , V_25 ) ;
V_2 -> V_26 = V_26 ;
V_2 -> V_27 = V_27 ;
V_2 -> V_50 = V_32 ;
if ( ( V_33 != 0x0408 ) && ( V_33 != 0x0804 ) )
V_2 -> V_15 = V_51 ;
else
V_2 -> V_15 = V_52 ;
F_18 ( & V_2 -> V_49 , V_25 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_2 -> V_15 ) ;
F_1 ( V_2 , V_53 , V_54 ) ;
F_1 ( V_2 , V_2 -> V_14 >> 8 , V_17 ) ;
F_1 ( V_2 , V_2 -> V_14 & 0xff , V_18 ) ;
F_1 ( V_2 , V_2 -> V_55 , V_19 ) ;
F_2 ( L_16 ,
V_2 -> V_14 , V_2 -> V_55 , V_2 -> V_56 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_11 ( V_2 , V_57 , V_20 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_11 ( V_2 , V_58 , V_20 ) ;
F_20 ( V_2 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
F_10 ( V_2 , V_59 ) ;
F_6 ( V_2 , V_60 , V_61 ) ;
F_6 ( V_2 , V_62 , V_63 ) ;
F_6 ( V_2 , V_62 , V_64 ) ;
F_6 ( V_2 , V_65 , V_66 ) ;
F_9 ( V_2 ) ;
}
static int F_23 ( T_1 V_67 , T_1 V_68 )
{
int V_69 = 0 ;
switch ( V_67 ) {
case V_70 :
if ( V_68 == V_71 )
V_69 = 1 ;
break;
case V_71 :
if ( V_68 == V_72 )
V_69 = 2 ;
break;
case V_73 :
switch ( V_68 ) {
case V_74 :
case V_75 :
case V_76 :
V_69 = 2 ;
break;
case V_77 :
case V_78 :
case V_79 :
V_69 = 1 ;
break;
}
}
return V_69 ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_25 ( V_80 ) ;
T_1 V_81 ;
bool V_82 = false ;
int V_83 ;
for ( V_83 = 0 ; V_83 < V_2 -> V_84 ; V_83 ++ ) {
V_81 = V_2 -> V_85 [ V_83 ] ;
switch ( V_2 -> V_86 ) {
case V_87 :
V_2 -> V_67 = V_81 ;
if ( ( V_2 -> V_67 == V_73 ) ||
( ( V_2 -> V_67 & V_88 ) !=
V_89 ) ) {
V_2 -> V_86 = V_90 ;
continue;
}
V_2 -> V_91 = ( V_2 -> V_67 & V_92 ) ;
F_2 ( L_17 , V_5 , V_2 -> V_91 ) ;
if ( V_2 -> V_91 )
V_2 -> V_86 = V_93 ;
else
F_26 ( V_2 -> V_94 ) ;
break;
case V_90 :
V_2 -> V_91 = F_23 ( V_2 -> V_67 , V_81 ) ;
V_2 -> V_86 = V_95 ;
break;
case V_95 :
V_2 -> V_91 -- ;
break;
case V_93 :
V_2 -> V_91 -- ;
F_27 ( & V_80 ) ;
V_80 . V_96 = ( ( V_81 & V_89 ) != 0 ) ;
V_80 . V_97 = F_28 ( ( V_81 & V_98 )
* V_99 ) ;
F_2 ( L_18 ,
V_80 . V_96 ? L_19 : L_20 ,
V_80 . V_97 ) ;
if ( F_29 ( V_2 -> V_94 ,
& V_80 ) )
V_82 = true ;
break;
}
if ( ( V_2 -> V_86 != V_87 ) && ! V_2 -> V_91 )
V_2 -> V_86 = V_87 ;
}
V_2 -> V_84 = 0 ;
if ( V_82 ) {
F_2 ( L_21 ) ;
F_30 ( V_2 -> V_94 ) ;
}
}
static void F_31 ( struct V_1 * V_2 , T_1 V_100 )
{
unsigned long V_25 ;
T_1 V_81 , V_101 ;
F_17 ( & V_2 -> V_49 , V_25 ) ;
do {
V_81 = F_12 ( V_2 , V_22 ) ;
F_2 ( L_22 , V_5 , V_81 ) ;
V_2 -> V_85 [ V_2 -> V_84 ] = V_81 ;
V_2 -> V_84 ++ ;
V_101 = F_12 ( V_2 , V_20 ) ;
if ( ! ( V_101 & V_57 ) )
break;
} while ( V_101 & V_100 );
F_24 ( V_2 ) ;
F_18 ( & V_2 -> V_49 , V_25 ) ;
}
static void F_32 ( T_1 V_101 )
{
F_16 ( V_35 , L_23 , V_101 ,
V_101 & V_57 ? L_24 : L_25 ,
V_101 & V_102 ? L_26 : L_25 ,
V_101 & V_103 ? L_27 : L_25 ,
V_101 & V_104 ? L_28 : L_25 ,
V_101 & V_105 ? L_29 : L_25 ) ;
}
static T_3 F_33 ( int V_106 , void * V_107 )
{
struct V_1 * V_2 = V_107 ;
T_1 V_101 , V_100 ;
F_34 ( L_30 , V_5 ) ;
F_8 ( V_2 ) ;
F_10 ( V_2 , V_2 -> V_15 ) ;
F_9 ( V_2 ) ;
V_101 = F_12 ( V_2 , V_20 ) ;
if ( ! ( V_101 & V_58 ) || V_101 == 0xff ) {
F_34 ( L_31 , V_5 , V_101 ) ;
F_11 ( V_2 , V_58 , V_20 ) ;
return F_35 ( V_108 ) ;
}
if ( V_109 )
F_32 ( V_101 ) ;
V_100 = V_101 & ( V_105 | V_104 ) ;
if ( V_100 )
F_31 ( V_2 , V_100 ) ;
F_11 ( V_2 , V_101 , V_20 ) ;
F_34 ( L_32 , V_5 ) ;
return F_35 ( V_110 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_11 ( V_2 , V_57 , V_20 ) ;
F_8 ( V_2 ) ;
F_10 ( V_2 , V_2 -> V_15 ) ;
F_1 ( V_2 , V_53 , V_54 ) ;
F_9 ( V_2 ) ;
F_11 ( V_2 , V_58 , V_20 ) ;
F_20 ( V_2 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
F_10 ( V_2 , V_2 -> V_15 ) ;
F_1 ( V_2 , V_111 , V_54 ) ;
F_9 ( V_2 ) ;
}
static int F_38 ( struct V_112 * V_113 )
{
struct V_1 * V_2 = V_113 -> V_114 ;
unsigned long V_25 ;
F_17 ( & V_2 -> V_49 , V_25 ) ;
F_36 ( V_2 ) ;
F_18 ( & V_2 -> V_49 , V_25 ) ;
return 0 ;
}
static void F_39 ( struct V_112 * V_113 )
{
struct V_1 * V_2 = V_113 -> V_114 ;
unsigned long V_25 ;
F_17 ( & V_2 -> V_49 , V_25 ) ;
F_37 ( V_2 ) ;
F_18 ( & V_2 -> V_49 , V_25 ) ;
}
static int F_40 ( struct V_115 * V_116 , const struct V_117 * V_118 )
{
struct V_1 * V_2 ;
struct V_112 * V_94 ;
int V_119 = - V_120 ;
V_2 = F_41 ( sizeof( struct V_1 ) , V_121 ) ;
if ( ! V_2 )
return V_119 ;
V_94 = F_42 () ;
if ( ! V_94 )
goto V_122;
V_119 = - V_123 ;
if ( ! F_43 ( V_116 , 0 ) ) {
F_44 ( & V_116 -> V_113 , L_33 ) ;
goto V_122;
}
if ( ! F_45 ( V_116 , 0 ) ) {
F_44 ( & V_116 -> V_113 , L_34 ) ;
goto V_122;
}
V_2 -> V_14 = F_46 ( V_116 , 0 ) ;
V_2 -> V_55 = F_47 ( V_116 , 0 ) ;
V_2 -> V_56 = F_48 ( V_116 , 0 ) ;
V_2 -> V_6 = V_124 ;
V_2 -> V_7 = V_125 ;
F_49 ( & V_2 -> V_49 ) ;
F_50 ( V_116 , V_2 ) ;
V_2 -> V_116 = V_116 ;
V_119 = F_15 ( V_2 ) ;
if ( V_119 )
goto V_122;
F_8 ( V_2 ) ;
F_19 ( V_2 ) ;
F_9 ( V_2 ) ;
F_21 ( V_2 ) ;
V_94 -> V_114 = V_2 ;
V_94 -> V_126 = V_127 ;
V_94 -> V_128 = V_129 ;
V_94 -> V_130 = F_38 ;
V_94 -> V_131 = F_39 ;
V_94 -> V_132 = V_133 ;
V_94 -> V_134 = L_35 ;
V_94 -> V_135 . V_136 = V_137 ;
V_94 -> V_135 . V_32 = V_47 ;
V_94 -> V_135 . V_138 = V_2 -> V_26 ;
V_94 -> V_135 . V_139 = V_2 -> V_27 ;
V_94 -> V_113 . V_140 = & V_116 -> V_113 ;
V_94 -> V_141 = V_16 ;
V_94 -> V_142 = V_143 ;
V_94 -> V_144 = F_28 ( 1000 ) ;
V_94 -> V_145 = F_28 ( V_99 ) ;
V_2 -> V_94 = V_94 ;
V_119 = - V_146 ;
if ( ! F_51 ( V_2 -> V_14 ,
V_2 -> V_56 , V_16 ) )
goto V_122;
if ( F_52 ( V_2 -> V_55 , F_33 , V_147 ,
V_16 , ( void * ) V_2 ) )
goto V_148;
V_119 = F_53 ( V_94 ) ;
if ( V_119 )
goto V_149;
F_54 ( & V_116 -> V_113 , true ) ;
F_16 ( V_150 , L_36 ) ;
if ( V_109 )
F_13 ( V_2 ) ;
return 0 ;
V_149:
F_55 ( V_2 -> V_55 , V_2 ) ;
V_148:
F_56 ( V_2 -> V_14 , V_2 -> V_56 ) ;
V_122:
F_57 ( V_94 ) ;
F_58 ( V_2 ) ;
return V_119 ;
}
static void F_59 ( struct V_115 * V_116 )
{
struct V_1 * V_2 = F_60 ( V_116 ) ;
unsigned long V_25 ;
F_17 ( & V_2 -> V_49 , V_25 ) ;
F_37 ( V_2 ) ;
F_11 ( V_2 , V_58 , V_20 ) ;
F_22 ( V_2 ) ;
F_18 ( & V_2 -> V_49 , V_25 ) ;
F_55 ( V_2 -> V_55 , V_2 ) ;
F_56 ( V_2 -> V_14 , V_2 -> V_56 ) ;
F_61 ( V_2 -> V_94 ) ;
F_58 ( V_2 ) ;
}
static int F_62 ( struct V_115 * V_116 , T_4 V_151 )
{
struct V_1 * V_2 = F_60 ( V_116 ) ;
unsigned long V_25 ;
F_2 ( L_37 , V_5 ) ;
F_17 ( & V_2 -> V_49 , V_25 ) ;
F_11 ( V_2 , V_58 , V_20 ) ;
F_18 ( & V_2 -> V_49 , V_25 ) ;
F_8 ( V_2 ) ;
F_10 ( V_2 , V_2 -> V_15 ) ;
F_1 ( V_2 , V_111 , V_54 ) ;
F_9 ( V_2 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_63 ( struct V_115 * V_116 )
{
struct V_1 * V_2 = F_60 ( V_116 ) ;
F_2 ( L_37 , V_5 ) ;
F_20 ( V_2 ) ;
F_8 ( V_2 ) ;
F_10 ( V_2 , V_2 -> V_15 ) ;
F_1 ( V_2 , V_53 , V_54 ) ;
F_9 ( V_2 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
static void F_64 ( struct V_115 * V_116 )
{
struct V_1 * V_2 = F_60 ( V_116 ) ;
F_22 ( V_2 ) ;
}
