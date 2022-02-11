static T_1 F_1 ( T_1 V_1 )
{
return 1 << ( V_1 & V_2 ) ;
}
int F_2 ( struct V_3 * V_3 )
{
return F_3 ( & V_3 -> V_4 . V_5 ) ;
}
static unsigned int F_4 ( T_2 V_6 , T_3 V_7 , T_3 V_8 , T_1 V_9 )
{
F_5 ( & V_10 . V_11 , sizeof( V_10 . V_11 ) ) ;
return F_6 ( ( V_12 V_13 ) V_6 << 16 | V_9 ,
( V_12 V_13 ) V_7 , ( V_12 V_13 ) V_8 ,
V_10 . V_11 ) ;
}
static unsigned int F_7 ( const struct V_14 * V_15 )
{
const struct V_16 * V_16 ;
V_16 = F_8 ( V_15 , struct V_16 , V_15 ) ;
return F_4 ( V_16 -> V_6 , V_16 -> V_7 , V_16 -> V_8 , V_16 -> V_17 ) ;
}
static bool F_9 ( const struct V_14 * V_15 , const void * V_18 )
{
const struct V_16 * V_19 ;
const struct V_20 * V_21 = V_18 ;
V_19 = F_8 ( V_15 , struct V_16 , V_15 ) ;
return V_19 -> V_6 == V_21 -> V_22 -> V_6 &&
V_19 -> V_7 == V_21 -> V_22 -> V_7 &&
V_19 -> V_8 == V_21 -> V_22 -> V_8 &&
V_19 -> V_17 == V_21 -> V_22 -> V_17 &&
V_19 -> V_23 == V_21 -> V_23 &&
V_19 -> V_24 == V_21 -> V_24 ;
}
static void F_10 ( struct V_14 * V_15 , const void * V_18 )
{
struct V_16 * V_19 = F_8 ( V_15 , struct V_16 , V_15 ) ;
struct V_25 * V_4 = F_8 ( V_15 -> V_3 , struct V_25 ,
V_5 ) ;
struct V_3 * V_3 = F_8 ( V_4 , struct V_3 , V_4 ) ;
const struct V_20 * V_21 = V_18 ;
V_19 -> V_17 = V_21 -> V_22 -> V_17 ;
V_19 -> V_6 = V_21 -> V_22 -> V_6 ;
V_19 -> V_26 = F_1 ( V_21 -> V_22 -> V_1 ) ;
V_19 -> V_7 = V_21 -> V_22 -> V_7 ;
V_19 -> V_8 = V_21 -> V_22 -> V_8 ;
V_19 -> V_24 = V_21 -> V_24 ;
V_19 -> V_23 = V_21 -> V_23 ;
V_19 -> V_27 = V_15 -> V_3 -> V_28 ?
F_11 ( V_3 -> V_4 . V_29 , V_21 -> V_22 -> V_7 , V_21 -> V_24 , 1 ) :
NULL ;
}
static void F_12 ( struct V_14 * V_15 )
{
struct V_16 * V_19 ;
V_19 = F_8 ( V_15 , struct V_16 , V_15 ) ;
if ( V_19 -> V_27 )
F_13 ( V_19 -> V_27 ) ;
}
static void F_14 ( struct V_16 * V_16 )
{
F_15 ( & V_16 -> V_15 , & V_10 ) ;
}
static void F_16 ( struct V_16 * V_16 )
{
F_17 ( & V_16 -> V_15 , & V_10 ) ;
}
static bool F_18 ( V_13 V_23 )
{
return V_23 == V_30 ||
F_19 ( V_23 , V_31 ,
V_32 ) ||
F_19 ( V_23 , V_33 ,
V_34 ) ;
}
static void F_20 ( unsigned long V_21 )
{
struct V_16 * V_19 ;
struct V_3 * V_3 ;
V_19 = F_8 ( (struct V_14 * ) V_21 , struct V_16 , V_15 ) ;
V_3 = F_8 ( V_19 -> V_15 . V_3 , struct V_3 , V_4 . V_5 ) ;
F_21 () ;
F_22 ( & V_19 -> V_15 . V_35 ) ;
if ( V_19 -> V_15 . V_36 & V_37 )
goto V_38;
F_16 ( V_19 ) ;
F_23 ( V_3 , V_39 ) ;
if ( ! F_24 ( & V_19 -> V_15 ) ) {
struct V_40 * V_41 , * V_42 = V_19 -> V_15 . V_43 ;
const struct V_44 * V_22 ;
int V_45 ;
F_23 ( V_3 , V_46 ) ;
if ( ! ( V_19 -> V_15 . V_36 & V_47 ) || ! V_19 -> V_15 . V_43 )
goto V_38;
V_42 -> V_48 = F_25 ( V_3 , V_19 -> V_49 ) ;
if ( ! V_42 -> V_48 )
goto V_38;
V_22 = F_26 ( V_42 ) ;
V_45 = F_27 ( V_42 , V_22 -> V_8 , V_22 -> V_7 ,
V_22 -> V_1 , V_42 -> V_48 ) ;
if ( V_45 )
goto V_38;
if ( F_18 ( V_19 -> V_23 ) &&
( F_28 ( V_42 ) -> V_50 != V_51 ) )
goto V_38;
V_41 = F_29 ( V_42 , V_52 ) ;
if ( V_41 ) {
F_30 ( & V_19 -> V_15 . V_35 ) ;
F_31 ( V_41 , V_53 ,
V_54 , 0 ) ;
F_32 ( V_41 ) ;
goto V_55;
}
}
V_38:
F_30 ( & V_19 -> V_15 . V_35 ) ;
V_55:
F_33 () ;
F_14 ( V_19 ) ;
}
static struct V_16 * F_34 ( struct V_3 * V_3 , struct V_44 * V_22 ,
V_13 V_23 , int V_24 )
{
struct V_14 * V_15 ;
struct V_20 V_21 ;
unsigned int V_56 ;
V_21 . V_22 = V_22 ;
V_21 . V_23 = V_23 ;
V_21 . V_24 = V_24 ;
V_56 = F_4 ( V_22 -> V_6 , V_22 -> V_7 , V_22 -> V_8 , V_22 -> V_17 ) ;
V_15 = F_35 ( & V_3 -> V_4 . V_5 , & V_10 , & V_21 , V_56 ) ;
if ( F_36 ( V_15 ) ) {
F_37 ( V_15 , F_38 () ) ;
return NULL ;
}
return F_8 ( V_15 , struct V_16 , V_15 ) ;
}
static int F_39 ( struct V_16 * V_19 )
{
struct V_57 * V_27 = V_19 -> V_27 ;
unsigned int V_58 = V_19 -> V_15 . V_3 -> V_28 ;
unsigned int V_59 , V_60 ;
int V_61 ;
if ( ! V_27 || ! V_58 )
return 0 ;
V_59 = V_19 -> V_62 ;
V_60 = F_40 ( & V_27 -> V_62 ) ;
V_19 -> V_62 = V_60 ;
V_61 = V_19 -> V_15 . V_43 && ( V_60 - V_59 ) > V_58 ;
if ( V_61 ) {
struct V_3 * V_3 ;
V_3 = F_8 ( V_19 -> V_15 . V_3 , struct V_3 , V_4 . V_5 ) ;
F_23 ( V_3 , V_39 ) ;
}
return V_61 ;
}
static int F_41 ( struct V_16 * V_19 )
{
struct V_40 * V_63 ;
unsigned int V_64 = 0 ;
if ( ! F_42 ( & V_19 -> V_15 . V_65 , V_66 + V_19 -> V_15 . V_3 -> V_67 ) ) {
F_43 ( & V_19 -> V_15 . V_68 ) ;
return - V_69 ;
}
V_63 = V_19 -> V_15 . V_43 ;
do {
struct V_40 * V_70 = V_63 -> V_71 ;
V_64 += V_63 -> V_72 ;
F_44 ( V_63 ) ;
V_63 = V_70 ;
} while ( V_63 );
F_45 ( V_19 -> V_15 . V_3 , V_64 ) ;
V_19 -> V_15 . V_36 = 0 ;
V_19 -> V_15 . V_73 = 0 ;
V_19 -> V_15 . V_74 = 0 ;
V_19 -> V_15 . V_43 = NULL ;
V_19 -> V_15 . V_75 = NULL ;
V_19 -> V_49 = 0 ;
V_19 -> V_26 = 0 ;
return 0 ;
}
static int F_46 ( struct V_16 * V_19 , struct V_40 * V_76 )
{
struct V_40 * V_77 , * V_71 ;
struct V_78 * V_48 ;
unsigned int V_79 ;
int V_36 , V_80 ;
int V_81 , V_60 ;
int V_45 = - V_82 ;
T_1 V_26 ;
if ( V_19 -> V_15 . V_36 & V_37 )
goto V_45;
if ( ! ( F_47 ( V_76 ) -> V_36 & V_83 ) &&
F_48 ( F_39 ( V_19 ) ) &&
F_48 ( V_45 = F_41 ( V_19 ) ) ) {
F_16 ( V_19 ) ;
goto V_45;
}
V_26 = F_1 ( F_26 ( V_76 ) -> V_1 ) ;
V_80 = F_49 ( F_26 ( V_76 ) -> V_84 ) ;
V_36 = V_80 & ~ V_85 ;
V_80 &= V_85 ;
V_80 <<= 3 ;
V_81 = F_50 ( V_76 ) ;
V_60 = V_80 + V_76 -> V_73 - F_51 ( V_76 ) - V_81 ;
V_45 = - V_86 ;
if ( ( V_36 & V_87 ) == 0 ) {
if ( V_60 < V_19 -> V_15 . V_73 ||
( ( V_19 -> V_15 . V_36 & V_88 ) && V_60 != V_19 -> V_15 . V_73 ) )
goto V_45;
V_19 -> V_15 . V_36 |= V_88 ;
V_19 -> V_15 . V_73 = V_60 ;
} else {
if ( V_60 & 7 ) {
V_60 &= ~ 7 ;
if ( V_76 -> V_89 != V_90 )
V_76 -> V_89 = V_91 ;
}
if ( V_60 > V_19 -> V_15 . V_73 ) {
if ( V_19 -> V_15 . V_36 & V_88 )
goto V_45;
V_19 -> V_15 . V_73 = V_60 ;
}
}
if ( V_60 == V_80 )
goto V_45;
V_45 = - V_92 ;
if ( ! F_52 ( V_76 , F_51 ( V_76 ) + V_81 ) )
goto V_45;
V_45 = F_53 ( V_76 , V_60 - V_80 ) ;
if ( V_45 )
goto V_45;
V_77 = V_19 -> V_15 . V_75 ;
if ( ! V_77 || F_54 ( V_77 ) -> V_80 < V_80 ) {
V_71 = NULL ;
goto V_93;
}
V_77 = NULL ;
for ( V_71 = V_19 -> V_15 . V_43 ; V_71 != NULL ; V_71 = V_71 -> V_71 ) {
if ( F_54 ( V_71 ) -> V_80 >= V_80 )
break;
V_77 = V_71 ;
}
V_93:
if ( V_77 ) {
int V_94 = ( F_54 ( V_77 ) -> V_80 + V_77 -> V_73 ) - V_80 ;
if ( V_94 > 0 ) {
V_80 += V_94 ;
V_45 = - V_86 ;
if ( V_60 <= V_80 )
goto V_45;
V_45 = - V_92 ;
if ( ! F_52 ( V_76 , V_94 ) )
goto V_45;
if ( V_76 -> V_89 != V_90 )
V_76 -> V_89 = V_91 ;
}
}
V_45 = - V_92 ;
while ( V_71 && F_54 ( V_71 ) -> V_80 < V_60 ) {
int V_94 = V_60 - F_54 ( V_71 ) -> V_80 ;
if ( V_94 < V_71 -> V_73 ) {
if ( ! F_52 ( V_71 , V_94 ) )
goto V_45;
F_54 ( V_71 ) -> V_80 += V_94 ;
V_19 -> V_15 . V_74 -= V_94 ;
if ( V_71 -> V_89 != V_90 )
V_71 -> V_89 = V_91 ;
break;
} else {
struct V_40 * V_95 = V_71 ;
V_71 = V_71 -> V_71 ;
if ( V_77 )
V_77 -> V_71 = V_71 ;
else
V_19 -> V_15 . V_43 = V_71 ;
V_19 -> V_15 . V_74 -= V_95 -> V_73 ;
F_45 ( V_19 -> V_15 . V_3 , V_95 -> V_72 ) ;
F_44 ( V_95 ) ;
}
}
F_54 ( V_76 ) -> V_80 = V_80 ;
V_76 -> V_71 = V_71 ;
if ( ! V_71 )
V_19 -> V_15 . V_75 = V_76 ;
if ( V_77 )
V_77 -> V_71 = V_76 ;
else
V_19 -> V_15 . V_43 = V_76 ;
V_48 = V_76 -> V_48 ;
if ( V_48 ) {
V_19 -> V_49 = V_48 -> V_96 ;
V_76 -> V_48 = NULL ;
}
V_19 -> V_15 . V_97 = V_76 -> V_98 ;
V_19 -> V_15 . V_74 += V_76 -> V_73 ;
V_19 -> V_26 |= V_26 ;
F_55 ( V_19 -> V_15 . V_3 , V_76 -> V_72 ) ;
if ( V_80 == 0 )
V_19 -> V_15 . V_36 |= V_47 ;
V_79 = V_76 -> V_73 + V_81 ;
if ( V_79 > V_19 -> V_15 . V_99 )
V_19 -> V_15 . V_99 = V_79 ;
if ( F_26 ( V_76 ) -> V_84 & F_56 ( V_100 ) &&
V_79 > V_19 -> V_101 )
V_19 -> V_101 = V_79 ;
if ( V_19 -> V_15 . V_36 == ( V_47 | V_88 ) &&
V_19 -> V_15 . V_74 == V_19 -> V_15 . V_73 ) {
unsigned long V_102 = V_76 -> V_103 ;
V_76 -> V_103 = 0UL ;
V_45 = F_57 ( V_19 , V_77 , V_48 ) ;
V_76 -> V_103 = V_102 ;
return V_45 ;
}
F_58 ( V_76 ) ;
return - V_104 ;
V_45:
F_44 ( V_76 ) ;
return V_45 ;
}
static int F_57 ( struct V_16 * V_19 , struct V_40 * V_77 ,
struct V_78 * V_48 )
{
struct V_3 * V_3 = F_8 ( V_19 -> V_15 . V_3 , struct V_3 , V_4 . V_5 ) ;
struct V_44 * V_22 ;
struct V_40 * V_63 , * V_42 = V_19 -> V_15 . V_43 ;
int V_73 ;
int V_105 ;
int V_45 ;
T_1 V_26 ;
F_16 ( V_19 ) ;
V_26 = V_106 [ V_19 -> V_26 ] ;
if ( F_48 ( V_26 == 0xff ) ) {
V_45 = - V_86 ;
goto V_107;
}
if ( V_77 ) {
V_42 = V_77 -> V_71 ;
V_63 = F_29 ( V_42 , V_52 ) ;
if ( ! V_63 )
goto V_108;
V_63 -> V_71 = V_42 -> V_71 ;
if ( ! V_63 -> V_71 )
V_19 -> V_15 . V_75 = V_63 ;
V_77 -> V_71 = V_63 ;
F_59 ( V_42 , V_19 -> V_15 . V_43 ) ;
V_42 -> V_71 = V_19 -> V_15 . V_43 -> V_71 ;
F_32 ( V_19 -> V_15 . V_43 ) ;
V_19 -> V_15 . V_43 = V_42 ;
}
F_60 ( ! V_42 ) ;
F_60 ( F_54 ( V_42 ) -> V_80 != 0 ) ;
V_105 = F_50 ( V_42 ) ;
V_73 = V_105 + V_19 -> V_15 . V_73 ;
V_45 = - V_109 ;
if ( V_73 > 65535 )
goto V_110;
if ( F_61 ( V_42 , V_52 ) )
goto V_108;
if ( F_62 ( V_42 ) ) {
struct V_40 * V_41 ;
int V_94 , V_111 = 0 ;
V_41 = F_63 ( 0 , V_52 ) ;
if ( ! V_41 )
goto V_108;
V_41 -> V_71 = V_42 -> V_71 ;
V_42 -> V_71 = V_41 ;
F_64 ( V_41 ) -> V_112 = F_64 ( V_42 ) -> V_112 ;
F_65 ( V_42 ) ;
for ( V_94 = 0 ; V_94 < F_64 ( V_42 ) -> V_113 ; V_94 ++ )
V_111 += F_66 ( & F_64 ( V_42 ) -> V_5 [ V_94 ] ) ;
V_41 -> V_73 = V_41 -> V_114 = V_42 -> V_114 - V_111 ;
V_42 -> V_114 -= V_41 -> V_73 ;
V_42 -> V_73 -= V_41 -> V_73 ;
V_41 -> V_115 = 0 ;
V_41 -> V_89 = V_42 -> V_89 ;
F_55 ( V_19 -> V_15 . V_3 , V_41 -> V_72 ) ;
}
F_64 ( V_42 ) -> V_112 = V_42 -> V_71 ;
F_67 ( V_42 , V_42 -> V_116 - F_68 ( V_42 ) ) ;
for ( V_63 = V_42 -> V_71 ; V_63 ; V_63 = V_63 -> V_71 ) {
V_42 -> V_114 += V_63 -> V_73 ;
V_42 -> V_73 += V_63 -> V_73 ;
if ( V_42 -> V_89 != V_63 -> V_89 )
V_42 -> V_89 = V_91 ;
else if ( V_42 -> V_89 == V_117 )
V_42 -> V_115 = F_69 ( V_42 -> V_115 , V_63 -> V_115 ) ;
V_42 -> V_72 += V_63 -> V_72 ;
}
F_45 ( V_19 -> V_15 . V_3 , V_42 -> V_72 ) ;
V_42 -> V_71 = NULL ;
V_42 -> V_48 = V_48 ;
V_42 -> V_98 = V_19 -> V_15 . V_97 ;
F_47 ( V_42 ) -> V_118 = V_58 ( V_19 -> V_101 , V_19 -> V_15 . V_99 ) ;
V_22 = F_26 ( V_42 ) ;
V_22 -> V_119 = F_56 ( V_73 ) ;
V_22 -> V_1 |= V_26 ;
if ( V_19 -> V_101 == V_19 -> V_15 . V_99 ) {
F_47 ( V_42 ) -> V_36 |= V_120 ;
V_22 -> V_84 = F_56 ( V_100 ) ;
} else {
V_22 -> V_84 = 0 ;
}
F_70 ( V_22 ) ;
F_23 ( V_3 , V_121 ) ;
V_19 -> V_15 . V_43 = NULL ;
V_19 -> V_15 . V_75 = NULL ;
return 0 ;
V_108:
F_71 ( L_1 , V_19 ) ;
V_45 = - V_92 ;
goto V_107;
V_110:
F_72 ( L_2 , & V_19 -> V_7 ) ;
V_107:
F_23 ( V_3 , V_39 ) ;
return V_45 ;
}
int F_73 ( struct V_3 * V_3 , struct V_40 * V_76 , V_13 V_23 )
{
struct V_78 * V_48 = V_76 -> V_48 ? : F_74 ( V_76 ) -> V_48 ;
int V_24 = F_75 ( V_48 ) ;
struct V_16 * V_19 ;
F_23 ( V_3 , V_122 ) ;
F_76 ( V_76 ) ;
V_19 = F_34 ( V_3 , F_26 ( V_76 ) , V_23 , V_24 ) ;
if ( V_19 ) {
int V_123 ;
F_22 ( & V_19 -> V_15 . V_35 ) ;
V_123 = F_46 ( V_19 , V_76 ) ;
F_30 ( & V_19 -> V_15 . V_35 ) ;
F_14 ( V_19 ) ;
return V_123 ;
}
F_23 ( V_3 , V_39 ) ;
F_44 ( V_76 ) ;
return - V_92 ;
}
struct V_40 * F_77 ( struct V_3 * V_3 , struct V_40 * V_76 , V_13 V_23 )
{
struct V_44 V_22 ;
int V_124 ;
V_13 V_73 ;
if ( V_76 -> V_17 != F_56 ( V_125 ) )
return V_76 ;
V_124 = F_51 ( V_76 ) ;
if ( F_78 ( V_76 , V_124 , & V_22 , sizeof( V_22 ) ) < 0 )
return V_76 ;
if ( V_22 . V_81 < 5 || V_22 . V_126 != 4 )
return V_76 ;
V_73 = F_49 ( V_22 . V_119 ) ;
if ( V_76 -> V_73 < V_124 + V_73 || V_73 < ( V_22 . V_81 * 4 ) )
return V_76 ;
if ( F_79 ( & V_22 ) ) {
V_76 = F_80 ( V_76 , V_52 ) ;
if ( V_76 ) {
if ( ! F_81 ( V_76 , V_124 + V_22 . V_81 * 4 ) )
return V_76 ;
if ( F_53 ( V_76 , V_124 + V_73 ) )
return V_76 ;
memset ( F_47 ( V_76 ) , 0 , sizeof( struct V_127 ) ) ;
if ( F_73 ( V_3 , V_76 , V_23 ) )
return NULL ;
F_82 ( V_76 ) ;
}
}
return V_76 ;
}
static int T_4 F_83 ( struct V_3 * V_3 )
{
struct V_128 * V_129 ;
struct V_130 * V_131 ;
V_129 = V_132 ;
if ( ! F_84 ( V_3 , & V_133 ) ) {
V_129 = F_85 ( V_129 , sizeof( V_132 ) , V_134 ) ;
if ( ! V_129 )
goto V_135;
V_129 [ 0 ] . V_116 = & V_3 -> V_4 . V_5 . V_136 ;
V_129 [ 0 ] . V_137 = & V_3 -> V_4 . V_5 . V_138 ;
V_129 [ 0 ] . V_139 = & V_133 . V_4 . V_5 . V_136 ;
V_129 [ 1 ] . V_116 = & V_3 -> V_4 . V_5 . V_138 ;
V_129 [ 1 ] . V_139 = & V_3 -> V_4 . V_5 . V_136 ;
V_129 [ 2 ] . V_116 = & V_3 -> V_4 . V_5 . V_67 ;
V_129 [ 3 ] . V_116 = & V_3 -> V_4 . V_5 . V_28 ;
}
V_131 = F_86 ( V_3 , L_3 , V_129 ) ;
if ( ! V_131 )
goto V_140;
V_3 -> V_4 . V_141 = V_131 ;
return 0 ;
V_140:
if ( ! F_84 ( V_3 , & V_133 ) )
F_87 ( V_129 ) ;
V_135:
return - V_92 ;
}
static void T_5 F_88 ( struct V_3 * V_3 )
{
struct V_128 * V_129 ;
V_129 = V_3 -> V_4 . V_141 -> V_142 ;
F_89 ( V_3 -> V_4 . V_141 ) ;
F_87 ( V_129 ) ;
}
static void T_6 F_90 ( void )
{
F_86 ( & V_133 , L_3 , V_143 ) ;
}
static int F_83 ( struct V_3 * V_3 )
{
return 0 ;
}
static void F_88 ( struct V_3 * V_3 )
{
}
static void T_6 F_90 ( void )
{
}
static int T_4 F_91 ( struct V_3 * V_3 )
{
int V_144 ;
V_3 -> V_4 . V_5 . V_136 = 4 * 1024 * 1024 ;
V_3 -> V_4 . V_5 . V_138 = 3 * 1024 * 1024 ;
V_3 -> V_4 . V_5 . V_67 = V_145 ;
V_3 -> V_4 . V_5 . V_28 = 64 ;
V_144 = F_92 ( & V_3 -> V_4 . V_5 ) ;
if ( V_144 )
return V_144 ;
V_144 = F_83 ( V_3 ) ;
if ( V_144 )
F_93 ( & V_3 -> V_4 . V_5 ) ;
return V_144 ;
}
static void T_5 F_94 ( struct V_3 * V_3 )
{
F_88 ( V_3 ) ;
F_95 ( & V_3 -> V_4 . V_5 , & V_10 ) ;
}
void T_6 F_96 ( void )
{
F_90 () ;
F_97 ( & V_146 ) ;
V_10 . V_147 = F_7 ;
V_10 . V_148 = F_10 ;
V_10 . V_149 = F_12 ;
V_10 . V_150 = sizeof( struct V_16 ) ;
V_10 . V_151 = F_9 ;
V_10 . V_152 = F_20 ;
V_10 . V_153 = V_154 ;
if ( F_98 ( & V_10 ) )
F_99 ( L_4 ) ;
}
