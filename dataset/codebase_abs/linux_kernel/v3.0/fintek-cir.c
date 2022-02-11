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
F_10 ( V_2 , V_15 ) ;
F_14 ( L_2 , V_16 ) ;
F_14 ( L_3 ,
( F_4 ( V_2 , V_17 ) << 8 ) |
F_4 ( V_2 , V_18 ) ) ;
F_14 ( L_4 ,
F_4 ( V_2 , V_19 ) ) ;
F_9 ( V_2 ) ;
F_14 ( L_5 , V_16 ) ;
F_14 ( L_6 , F_12 ( V_2 , V_20 ) ) ;
F_14 ( L_7 , F_12 ( V_2 , V_21 ) ) ;
F_14 ( L_8 , F_12 ( V_2 , V_22 ) ) ;
F_14 ( L_9 , F_12 ( V_2 , V_23 ) ) ;
F_14 ( L_10 , F_12 ( V_2 , V_24 ) ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
unsigned long V_25 ;
T_1 V_26 , V_27 ;
T_1 V_28 , V_29 ;
T_1 V_30 , V_31 ;
T_2 V_32 ;
int V_33 = 0 ;
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
F_18 ( & V_2 -> V_49 , V_25 ) ;
return V_33 ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_15 ) ;
F_1 ( V_2 , V_51 , V_52 ) ;
F_1 ( V_2 , V_2 -> V_14 >> 8 , V_17 ) ;
F_1 ( V_2 , V_2 -> V_14 & 0xff , V_18 ) ;
F_1 ( V_2 , V_2 -> V_53 , V_19 ) ;
F_2 ( L_16 ,
V_2 -> V_14 , V_2 -> V_53 , V_2 -> V_54 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_11 ( V_2 , V_55 , V_20 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_11 ( V_2 , V_56 , V_20 ) ;
F_20 ( V_2 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
F_10 ( V_2 , V_57 ) ;
F_6 ( V_2 , V_58 , V_59 ) ;
F_6 ( V_2 , V_60 , V_61 ) ;
F_6 ( V_2 , V_60 , V_62 ) ;
F_6 ( V_2 , V_63 , V_64 ) ;
F_9 ( V_2 ) ;
}
static int F_23 ( T_1 V_65 , T_1 V_66 )
{
int V_67 = 0 ;
switch ( V_65 ) {
case V_68 :
if ( V_66 == V_69 )
V_67 = 1 ;
break;
case V_69 :
if ( V_66 == V_70 )
V_67 = 2 ;
break;
case V_71 :
switch ( V_66 ) {
case V_72 :
case V_73 :
case V_74 :
V_67 = 2 ;
break;
case V_75 :
case V_76 :
case V_77 :
V_67 = 1 ;
break;
}
}
return V_67 ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_25 ( V_78 ) ;
T_1 V_79 ;
int V_80 ;
for ( V_80 = 0 ; V_80 < V_2 -> V_81 ; V_80 ++ ) {
V_79 = V_2 -> V_82 [ V_80 ] ;
switch ( V_2 -> V_83 ) {
case V_84 :
V_2 -> V_65 = V_79 ;
if ( ( V_2 -> V_65 == V_71 ) ||
( ( V_2 -> V_65 & V_85 ) !=
V_86 ) ) {
V_2 -> V_83 = V_87 ;
continue;
}
V_2 -> V_88 = ( V_2 -> V_65 & V_89 ) ;
F_2 ( L_17 , V_5 , V_2 -> V_88 ) ;
if ( V_2 -> V_88 )
V_2 -> V_83 = V_90 ;
else
F_26 ( V_2 -> V_91 ) ;
break;
case V_87 :
V_2 -> V_88 = F_23 ( V_2 -> V_65 , V_79 ) ;
V_2 -> V_83 = V_92 ;
break;
case V_92 :
V_2 -> V_88 -- ;
break;
case V_90 :
V_2 -> V_88 -- ;
F_27 ( & V_78 ) ;
V_78 . V_93 = ( ( V_79 & V_86 ) != 0 ) ;
V_78 . V_94 = F_28 ( ( V_79 & V_95 )
* V_96 ) ;
F_2 ( L_18 ,
V_78 . V_93 ? L_19 : L_20 ,
V_78 . V_94 ) ;
F_29 ( V_2 -> V_91 , & V_78 ) ;
break;
}
if ( ( V_2 -> V_83 != V_84 ) && ! V_2 -> V_88 )
V_2 -> V_83 = V_84 ;
}
V_2 -> V_81 = 0 ;
F_2 ( L_21 ) ;
F_30 ( V_2 -> V_91 ) ;
}
static void F_31 ( struct V_1 * V_2 , T_1 V_97 )
{
unsigned long V_25 ;
T_1 V_79 , V_98 ;
F_17 ( & V_2 -> V_49 , V_25 ) ;
do {
V_79 = F_12 ( V_2 , V_22 ) ;
F_2 ( L_22 , V_5 , V_79 ) ;
V_2 -> V_82 [ V_2 -> V_81 ] = V_79 ;
V_2 -> V_81 ++ ;
V_98 = F_12 ( V_2 , V_20 ) ;
if ( ! ( V_98 & V_55 ) )
break;
} while ( V_98 & V_97 );
F_24 ( V_2 ) ;
F_18 ( & V_2 -> V_49 , V_25 ) ;
}
static void F_32 ( T_1 V_98 )
{
F_16 ( V_35 , L_23 , V_98 ,
V_98 & V_55 ? L_24 : L_25 ,
V_98 & V_99 ? L_26 : L_25 ,
V_98 & V_100 ? L_27 : L_25 ,
V_98 & V_101 ? L_28 : L_25 ,
V_98 & V_102 ? L_29 : L_25 ) ;
}
static T_3 F_33 ( int V_103 , void * V_104 )
{
struct V_1 * V_2 = V_104 ;
T_1 V_98 , V_97 ;
F_34 ( L_30 , V_5 ) ;
F_8 ( V_2 ) ;
F_10 ( V_2 , V_15 ) ;
F_9 ( V_2 ) ;
V_98 = F_12 ( V_2 , V_20 ) ;
if ( ! ( V_98 & V_56 ) || V_98 == 0xff ) {
F_34 ( L_31 , V_5 , V_98 ) ;
F_11 ( V_2 , V_56 , V_20 ) ;
return F_35 ( V_105 ) ;
}
if ( V_106 )
F_32 ( V_98 ) ;
V_97 = V_98 & ( V_102 | V_101 ) ;
if ( V_97 )
F_31 ( V_2 , V_97 ) ;
F_11 ( V_2 , V_98 , V_20 ) ;
F_34 ( L_32 , V_5 ) ;
return F_35 ( V_107 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_11 ( V_2 , V_55 , V_20 ) ;
F_8 ( V_2 ) ;
F_10 ( V_2 , V_15 ) ;
F_1 ( V_2 , V_51 , V_52 ) ;
F_9 ( V_2 ) ;
F_11 ( V_2 , V_56 , V_20 ) ;
F_20 ( V_2 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
F_10 ( V_2 , V_15 ) ;
F_1 ( V_2 , V_108 , V_52 ) ;
F_9 ( V_2 ) ;
}
static int F_38 ( struct V_109 * V_110 )
{
struct V_1 * V_2 = V_110 -> V_111 ;
unsigned long V_25 ;
F_17 ( & V_2 -> V_49 , V_25 ) ;
F_36 ( V_2 ) ;
F_18 ( & V_2 -> V_49 , V_25 ) ;
return 0 ;
}
static void F_39 ( struct V_109 * V_110 )
{
struct V_1 * V_2 = V_110 -> V_111 ;
unsigned long V_25 ;
F_17 ( & V_2 -> V_49 , V_25 ) ;
F_37 ( V_2 ) ;
F_18 ( & V_2 -> V_49 , V_25 ) ;
}
static int F_40 ( struct V_112 * V_113 , const struct V_114 * V_115 )
{
struct V_1 * V_2 ;
struct V_109 * V_91 ;
int V_33 = - V_116 ;
V_2 = F_41 ( sizeof( struct V_1 ) , V_117 ) ;
if ( ! V_2 )
return V_33 ;
V_91 = F_42 () ;
if ( ! V_91 )
goto V_118;
V_33 = - V_119 ;
if ( ! F_43 ( V_113 , 0 ) ) {
F_44 ( & V_113 -> V_110 , L_33 ) ;
goto V_118;
}
if ( ! F_45 ( V_113 , 0 ) ) {
F_44 ( & V_113 -> V_110 , L_34 ) ;
goto V_118;
}
V_2 -> V_14 = F_46 ( V_113 , 0 ) ;
V_2 -> V_53 = F_47 ( V_113 , 0 ) ;
V_2 -> V_54 = F_48 ( V_113 , 0 ) ;
V_2 -> V_6 = V_120 ;
V_2 -> V_7 = V_121 ;
F_49 ( & V_2 -> V_49 ) ;
V_33 = - V_122 ;
if ( ! F_50 ( V_2 -> V_14 ,
V_2 -> V_54 , V_16 ) )
goto V_118;
if ( F_51 ( V_2 -> V_53 , F_33 , V_123 ,
V_16 , ( void * ) V_2 ) )
goto V_118;
F_52 ( V_113 , V_2 ) ;
V_2 -> V_113 = V_113 ;
V_33 = F_15 ( V_2 ) ;
if ( V_33 )
goto V_118;
F_8 ( V_2 ) ;
F_19 ( V_2 ) ;
F_9 ( V_2 ) ;
F_21 ( V_2 ) ;
V_91 -> V_111 = V_2 ;
V_91 -> V_124 = V_125 ;
V_91 -> V_126 = V_127 ;
V_91 -> V_128 = F_38 ;
V_91 -> V_129 = F_39 ;
V_91 -> V_130 = V_131 ;
V_91 -> V_132 = L_35 ;
V_91 -> V_133 . V_134 = V_135 ;
V_91 -> V_133 . V_32 = V_47 ;
V_91 -> V_133 . V_136 = V_2 -> V_26 ;
V_91 -> V_133 . V_137 = V_2 -> V_27 ;
V_91 -> V_110 . V_138 = & V_113 -> V_110 ;
V_91 -> V_139 = V_16 ;
V_91 -> V_140 = V_141 ;
V_91 -> V_142 = F_28 ( 1000 ) ;
V_91 -> V_143 = F_28 ( V_96 ) ;
V_33 = F_53 ( V_91 ) ;
if ( V_33 )
goto V_118;
F_54 ( & V_113 -> V_110 , true ) ;
V_2 -> V_91 = V_91 ;
F_16 ( V_144 , L_36 ) ;
if ( V_106 )
F_13 ( V_2 ) ;
return 0 ;
V_118:
if ( V_2 -> V_53 )
F_55 ( V_2 -> V_53 , V_2 ) ;
if ( V_2 -> V_14 )
F_56 ( V_2 -> V_14 , V_2 -> V_54 ) ;
F_57 ( V_91 ) ;
F_58 ( V_2 ) ;
return V_33 ;
}
static void T_4 F_59 ( struct V_112 * V_113 )
{
struct V_1 * V_2 = F_60 ( V_113 ) ;
unsigned long V_25 ;
F_17 ( & V_2 -> V_49 , V_25 ) ;
F_37 ( V_2 ) ;
F_11 ( V_2 , V_56 , V_20 ) ;
F_22 ( V_2 ) ;
F_18 ( & V_2 -> V_49 , V_25 ) ;
F_55 ( V_2 -> V_53 , V_2 ) ;
F_56 ( V_2 -> V_14 , V_2 -> V_54 ) ;
F_61 ( V_2 -> V_91 ) ;
F_58 ( V_2 ) ;
}
static int F_62 ( struct V_112 * V_113 , T_5 V_145 )
{
struct V_1 * V_2 = F_60 ( V_113 ) ;
unsigned long V_25 ;
F_2 ( L_37 , V_5 ) ;
F_17 ( & V_2 -> V_49 , V_25 ) ;
F_11 ( V_2 , V_56 , V_20 ) ;
F_18 ( & V_2 -> V_49 , V_25 ) ;
F_8 ( V_2 ) ;
F_10 ( V_2 , V_15 ) ;
F_1 ( V_2 , V_108 , V_52 ) ;
F_9 ( V_2 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_63 ( struct V_112 * V_113 )
{
int V_33 = 0 ;
struct V_1 * V_2 = F_60 ( V_113 ) ;
F_2 ( L_37 , V_5 ) ;
F_20 ( V_2 ) ;
F_8 ( V_2 ) ;
F_10 ( V_2 , V_15 ) ;
F_1 ( V_2 , V_51 , V_52 ) ;
F_9 ( V_2 ) ;
F_21 ( V_2 ) ;
return V_33 ;
}
static void F_64 ( struct V_112 * V_113 )
{
struct V_1 * V_2 = F_60 ( V_113 ) ;
F_22 ( V_2 ) ;
}
int F_65 ( void )
{
return F_66 ( & V_146 ) ;
}
void F_67 ( void )
{
F_68 ( & V_146 ) ;
}
