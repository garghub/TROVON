static unsigned short int F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 - V_2 -> V_3 . V_5 ;
}
static void F_2 ( struct V_1 * V_2 )
{
const T_1 * V_6 = ( const T_1 * ) & V_2 -> V_7 ;
T_2 V_8 = sizeof( V_2 -> V_7 ) ;
T_2 V_9 , V_10 = 0 , V_11 = V_8 - 1 ;
for ( V_9 = 0 ; V_9 < sizeof( V_2 -> V_7 ) ; V_9 ++ ) {
if ( V_6 [ V_9 ] ) {
if ( ! V_10 && V_9 )
V_10 = V_9 ;
V_11 = V_9 ;
}
}
V_2 -> V_3 . V_5 = F_3 ( V_10 , sizeof( long ) ) ;
V_2 -> V_3 . V_4 = F_4 ( V_11 + 1 , sizeof( long ) ) ;
}
static void * F_5 ( struct V_12 * V_7 ,
const struct V_1 * V_2 )
{
return ( T_1 * ) V_7 + V_2 -> V_3 . V_5 ;
}
static void F_6 ( struct V_12 * V_13 , struct V_12 * V_7 ,
struct V_1 * V_2 )
{
const long * V_14 = F_5 ( V_7 , V_2 ) ;
const long * V_15 = F_5 ( & V_2 -> V_7 , V_2 ) ;
long * V_16 = F_5 ( V_13 , V_2 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < F_1 ( V_2 ) ; V_9 += sizeof( long ) )
* V_16 ++ = * V_14 ++ & * V_15 ++ ;
}
static void F_7 ( struct V_12 * V_7 ,
struct V_1 * V_2 )
{
memset ( F_5 ( V_7 , V_2 ) , 0 , F_1 ( V_2 ) ) ;
}
static int F_8 ( struct V_17 * V_18 , const struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = F_9 ( V_20 -> V_25 ) ;
struct V_26 * V_27 ;
struct V_12 V_28 ;
struct V_12 V_29 ;
F_7 ( & V_28 , & V_24 -> V_2 ) ;
V_28 . V_30 = V_18 -> V_31 ;
V_28 . V_32 . V_33 = V_18 -> V_34 ;
F_10 ( V_18 , & V_24 -> V_35 , & V_28 , 0 ) ;
F_6 ( & V_29 , & V_28 , & V_24 -> V_2 ) ;
V_27 = F_11 ( & V_24 -> V_36 ,
F_5 ( & V_29 , & V_24 -> V_2 ) ,
V_24 -> V_37 ) ;
if ( V_27 ) {
* V_22 = V_27 -> V_22 ;
return F_12 ( V_18 , & V_27 -> V_38 , V_22 ) ;
}
return - 1 ;
}
static int F_13 ( struct V_19 * V_20 )
{
struct V_23 * V_24 ;
V_24 = F_14 ( sizeof( * V_24 ) , V_39 ) ;
if ( ! V_24 )
return - V_40 ;
F_15 ( & V_24 -> V_41 ) ;
F_16 ( V_20 -> V_25 , V_24 ) ;
return 0 ;
}
static void F_17 ( struct V_42 * V_24 )
{
struct V_26 * V_27 = F_18 ( V_24 , struct V_26 , V_43 ) ;
F_19 ( & V_27 -> V_38 ) ;
F_20 ( V_27 ) ;
}
static void F_21 ( struct V_19 * V_20 , unsigned long V_44 )
{
struct V_45 * V_46 = V_20 -> V_47 -> V_48 -> V_46 ;
struct V_49 V_50 = { 0 } ;
struct V_51 V_52 ;
if ( ! F_22 ( V_46 , 0 ) )
return;
V_50 . V_53 = V_54 ;
V_50 . V_44 = V_44 ;
V_52 . type = V_55 ;
V_52 . V_56 = & V_50 ;
V_46 -> V_57 -> V_58 ( V_46 , V_20 -> V_47 -> V_59 , V_20 -> V_34 , & V_52 ) ;
}
static void F_23 ( struct V_19 * V_20 ,
struct V_60 * V_35 ,
struct V_12 * V_2 ,
struct V_12 * V_7 ,
struct V_61 * V_62 ,
unsigned long V_44 , T_3 V_63 )
{
struct V_45 * V_46 = V_20 -> V_47 -> V_48 -> V_46 ;
struct V_49 V_50 = { 0 } ;
struct V_51 V_52 ;
if ( ! F_22 ( V_46 , V_63 ) )
return;
V_50 . V_53 = V_64 ;
V_50 . V_44 = V_44 ;
V_50 . V_35 = V_35 ;
V_50 . V_2 = V_2 ;
V_50 . V_7 = V_7 ;
V_50 . V_38 = V_62 ;
V_52 . type = V_55 ;
V_52 . V_56 = & V_50 ;
V_46 -> V_57 -> V_58 ( V_46 , V_20 -> V_47 -> V_59 , V_20 -> V_34 , & V_52 ) ;
}
static bool F_24 ( struct V_19 * V_20 , bool V_65 )
{
struct V_23 * V_24 = F_25 ( V_20 -> V_25 ) ;
struct V_26 * V_27 , * V_66 ;
if ( ! V_65 && ! F_26 ( & V_24 -> V_41 ) )
return false ;
F_27 (f, next, &head->filters, list) {
F_21 ( V_20 , ( unsigned long ) V_27 ) ;
F_28 ( & V_27 -> V_67 ) ;
F_29 ( & V_27 -> V_43 , F_17 ) ;
}
F_30 ( V_20 -> V_25 , NULL ) ;
if ( V_24 -> V_68 )
F_31 ( & V_24 -> V_36 ) ;
F_32 ( V_24 , V_43 ) ;
return true ;
}
static unsigned long F_33 ( struct V_19 * V_20 , T_3 V_59 )
{
struct V_23 * V_24 = F_25 ( V_20 -> V_25 ) ;
struct V_26 * V_27 ;
F_34 (f, &head->filters, list)
if ( V_27 -> V_59 == V_59 )
return ( unsigned long ) V_27 ;
return 0 ;
}
static void F_35 ( struct V_69 * * V_70 ,
void * V_71 , int V_72 ,
void * V_2 , int V_73 , int V_74 )
{
if ( ! V_70 [ V_72 ] )
return;
memcpy ( V_71 , F_36 ( V_70 [ V_72 ] ) , V_74 ) ;
if ( V_73 == V_75 || ! V_70 [ V_73 ] )
memset ( V_2 , 0xff , V_74 ) ;
else
memcpy ( V_2 , F_36 ( V_70 [ V_73 ] ) , V_74 ) ;
}
static int F_37 ( struct V_76 * V_76 , struct V_69 * * V_70 ,
struct V_12 * V_7 , struct V_12 * V_2 )
{
#ifdef F_38
if ( V_70 [ V_77 ] ) {
int V_78 = F_39 ( V_76 , V_70 [ V_77 ] ) ;
if ( V_78 < 0 )
return V_78 ;
V_7 -> V_30 = V_78 ;
V_2 -> V_30 = 0xffffffff ;
}
#endif
F_35 ( V_70 , V_7 -> V_79 . V_80 , V_81 ,
V_2 -> V_79 . V_80 , V_82 ,
sizeof( V_7 -> V_79 . V_80 ) ) ;
F_35 ( V_70 , V_7 -> V_79 . V_83 , V_84 ,
V_2 -> V_79 . V_83 , V_85 ,
sizeof( V_7 -> V_79 . V_83 ) ) ;
F_35 ( V_70 , & V_7 -> V_32 . V_33 , V_86 ,
& V_2 -> V_32 . V_33 , V_75 ,
sizeof( V_7 -> V_32 . V_33 ) ) ;
if ( V_7 -> V_32 . V_33 == F_40 ( V_87 ) ||
V_7 -> V_32 . V_33 == F_40 ( V_88 ) ) {
F_35 ( V_70 , & V_7 -> V_32 . V_89 , V_90 ,
& V_2 -> V_32 . V_89 , V_75 ,
sizeof( V_7 -> V_32 . V_89 ) ) ;
}
if ( V_70 [ V_91 ] || V_70 [ V_92 ] ) {
V_7 -> V_93 . V_94 = V_95 ;
F_35 ( V_70 , & V_7 -> V_96 . V_83 , V_91 ,
& V_2 -> V_96 . V_83 , V_97 ,
sizeof( V_7 -> V_96 . V_83 ) ) ;
F_35 ( V_70 , & V_7 -> V_96 . V_80 , V_92 ,
& V_2 -> V_96 . V_80 , V_98 ,
sizeof( V_7 -> V_96 . V_80 ) ) ;
} else if ( V_70 [ V_99 ] || V_70 [ V_100 ] ) {
V_7 -> V_93 . V_94 = V_101 ;
F_35 ( V_70 , & V_7 -> V_102 . V_83 , V_99 ,
& V_2 -> V_102 . V_83 , V_103 ,
sizeof( V_7 -> V_102 . V_83 ) ) ;
F_35 ( V_70 , & V_7 -> V_102 . V_80 , V_100 ,
& V_2 -> V_102 . V_80 , V_104 ,
sizeof( V_7 -> V_102 . V_80 ) ) ;
}
if ( V_7 -> V_32 . V_89 == V_105 ) {
F_35 ( V_70 , & V_7 -> V_20 . V_83 , V_106 ,
& V_2 -> V_20 . V_83 , V_75 ,
sizeof( V_7 -> V_20 . V_83 ) ) ;
F_35 ( V_70 , & V_7 -> V_20 . V_80 , V_107 ,
& V_2 -> V_20 . V_80 , V_75 ,
sizeof( V_7 -> V_20 . V_80 ) ) ;
} else if ( V_7 -> V_32 . V_89 == V_108 ) {
F_35 ( V_70 , & V_7 -> V_20 . V_83 , V_109 ,
& V_2 -> V_20 . V_83 , V_75 ,
sizeof( V_7 -> V_20 . V_83 ) ) ;
F_35 ( V_70 , & V_7 -> V_20 . V_80 , V_110 ,
& V_2 -> V_20 . V_80 , V_75 ,
sizeof( V_7 -> V_20 . V_80 ) ) ;
}
return 0 ;
}
static bool F_41 ( struct V_1 * V_111 ,
struct V_1 * V_112 )
{
const long * V_113 = F_5 ( & V_111 -> V_7 , V_111 ) ;
const long * V_114 = F_5 ( & V_112 -> V_7 , V_112 ) ;
return ! memcmp ( & V_111 -> V_3 , & V_112 -> V_3 , sizeof( V_111 -> V_3 ) ) &&
! memcmp ( V_113 , V_114 , F_1 ( V_111 ) ) ;
}
static int F_42 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
V_24 -> V_37 = V_115 ;
V_24 -> V_37 . V_116 = F_1 ( V_2 ) ;
V_24 -> V_37 . V_117 += V_2 -> V_3 . V_5 ;
return F_43 ( & V_24 -> V_36 , & V_24 -> V_37 ) ;
}
static void F_44 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_118 V_119 [ V_120 ] ;
T_2 V_121 = 0 ;
F_45 ( V_119 , V_121 , V_122 , V_93 ) ;
F_45 ( V_119 , V_121 , V_123 , V_32 ) ;
F_46 ( V_2 , V_119 , V_121 ,
V_124 , V_79 ) ;
F_46 ( V_2 , V_119 , V_121 ,
V_95 , V_96 ) ;
F_46 ( V_2 , V_119 , V_121 ,
V_101 , V_102 ) ;
F_46 ( V_2 , V_119 , V_121 ,
V_125 , V_20 ) ;
F_47 ( & V_24 -> V_35 , V_119 , V_121 ) ;
}
static int F_48 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
int V_78 ;
if ( V_24 -> V_68 ) {
if ( ! F_41 ( & V_24 -> V_2 , V_2 ) )
return - V_126 ;
else
return 0 ;
}
V_78 = F_42 ( V_24 , V_2 ) ;
if ( V_78 )
return V_78 ;
memcpy ( & V_24 -> V_2 , V_2 , sizeof( V_24 -> V_2 ) ) ;
V_24 -> V_68 = true ;
F_44 ( V_24 , V_2 ) ;
return 0 ;
}
static int F_49 ( struct V_76 * V_76 , struct V_19 * V_20 ,
struct V_26 * V_27 , struct V_1 * V_2 ,
unsigned long V_127 , struct V_69 * * V_70 ,
struct V_69 * V_128 , bool V_129 )
{
struct V_61 V_130 ;
int V_78 ;
F_50 ( & V_130 , V_131 , 0 ) ;
V_78 = F_51 ( V_76 , V_20 , V_70 , V_128 , & V_130 , V_129 ) ;
if ( V_78 < 0 )
return V_78 ;
if ( V_70 [ V_132 ] ) {
V_27 -> V_22 . V_133 = F_52 ( V_70 [ V_132 ] ) ;
F_53 ( V_20 , & V_27 -> V_22 , V_127 ) ;
}
V_78 = F_37 ( V_76 , V_70 , & V_27 -> V_7 , & V_2 -> V_7 ) ;
if ( V_78 )
goto V_134;
F_2 ( V_2 ) ;
F_6 ( & V_27 -> V_13 , & V_27 -> V_7 , V_2 ) ;
F_54 ( V_20 , & V_27 -> V_38 , & V_130 ) ;
return 0 ;
V_134:
F_19 ( & V_130 ) ;
return V_78 ;
}
static T_3 F_55 ( struct V_19 * V_20 ,
struct V_23 * V_24 )
{
unsigned int V_9 = 0x80000000 ;
T_3 V_59 ;
do {
if ( ++ V_24 -> V_135 == 0x7FFFFFFF )
V_24 -> V_135 = 1 ;
} while ( -- V_9 > 0 && F_33 ( V_20 , V_24 -> V_135 ) );
if ( F_56 ( V_9 == 0 ) ) {
F_57 ( L_1 ) ;
V_59 = 0 ;
} else {
V_59 = V_24 -> V_135 ;
}
return V_59 ;
}
static int F_58 ( struct V_76 * V_76 , struct V_17 * V_136 ,
struct V_19 * V_20 , unsigned long V_127 ,
T_3 V_59 , struct V_69 * * V_137 ,
unsigned long * V_138 , bool V_129 )
{
struct V_23 * V_24 = F_25 ( V_20 -> V_25 ) ;
struct V_26 * V_139 = (struct V_26 * ) * V_138 ;
struct V_26 * V_140 ;
struct V_69 * V_70 [ V_141 + 1 ] ;
struct V_1 V_2 = {} ;
T_3 V_63 = 0 ;
int V_78 ;
if ( ! V_137 [ V_142 ] )
return - V_126 ;
V_78 = F_59 ( V_70 , V_141 , V_137 [ V_142 ] , V_143 ) ;
if ( V_78 < 0 )
return V_78 ;
if ( V_139 && V_59 && V_139 -> V_59 != V_59 )
return - V_126 ;
V_140 = F_14 ( sizeof( * V_140 ) , V_39 ) ;
if ( ! V_140 )
return - V_40 ;
F_50 ( & V_140 -> V_38 , V_131 , 0 ) ;
if ( ! V_59 ) {
V_59 = F_55 ( V_20 , V_24 ) ;
if ( ! V_59 ) {
V_78 = - V_126 ;
goto V_134;
}
}
V_140 -> V_59 = V_59 ;
if ( V_70 [ V_144 ] )
V_63 = F_52 ( V_70 [ V_144 ] ) ;
V_78 = F_49 ( V_76 , V_20 , V_140 , & V_2 , V_127 , V_70 , V_137 [ V_145 ] , V_129 ) ;
if ( V_78 )
goto V_134;
V_78 = F_48 ( V_24 , & V_2 ) ;
if ( V_78 )
goto V_134;
V_78 = F_60 ( & V_24 -> V_36 , & V_140 -> V_146 ,
V_24 -> V_37 ) ;
if ( V_78 )
goto V_134;
F_23 ( V_20 ,
& V_24 -> V_35 ,
& V_2 . V_7 ,
& V_140 -> V_7 ,
& V_140 -> V_38 ,
( unsigned long ) V_140 ,
V_63 ) ;
if ( V_139 ) {
F_61 ( & V_24 -> V_36 , & V_139 -> V_146 ,
V_24 -> V_37 ) ;
F_21 ( V_20 , ( unsigned long ) V_139 ) ;
}
* V_138 = ( unsigned long ) V_140 ;
if ( V_139 ) {
F_62 ( & V_139 -> V_67 , & V_140 -> V_67 ) ;
F_63 ( V_20 , & V_139 -> V_22 ) ;
F_29 ( & V_139 -> V_43 , F_17 ) ;
} else {
F_64 ( & V_140 -> V_67 , & V_24 -> V_41 ) ;
}
return 0 ;
V_134:
F_20 ( V_140 ) ;
return V_78 ;
}
static int F_65 ( struct V_19 * V_20 , unsigned long V_138 )
{
struct V_23 * V_24 = F_25 ( V_20 -> V_25 ) ;
struct V_26 * V_27 = (struct V_26 * ) V_138 ;
F_61 ( & V_24 -> V_36 , & V_27 -> V_146 ,
V_24 -> V_37 ) ;
F_28 ( & V_27 -> V_67 ) ;
F_21 ( V_20 , ( unsigned long ) V_27 ) ;
F_63 ( V_20 , & V_27 -> V_22 ) ;
F_29 ( & V_27 -> V_43 , F_17 ) ;
return 0 ;
}
static void F_66 ( struct V_19 * V_20 , struct V_147 * V_138 )
{
struct V_23 * V_24 = F_25 ( V_20 -> V_25 ) ;
struct V_26 * V_27 ;
F_67 (f, &head->filters, list) {
if ( V_138 -> V_148 < V_138 -> V_149 )
goto V_149;
if ( V_138 -> V_150 ( V_20 , ( unsigned long ) V_27 , V_138 ) < 0 ) {
V_138 -> V_151 = 1 ;
break;
}
V_149:
V_138 -> V_148 ++ ;
}
}
static int F_68 ( struct V_17 * V_18 ,
void * V_71 , int V_72 ,
void * V_2 , int V_73 , int V_74 )
{
int V_78 ;
if ( ! F_69 ( V_2 , 0 , V_74 ) )
return 0 ;
V_78 = F_70 ( V_18 , V_72 , V_74 , V_71 ) ;
if ( V_78 )
return V_78 ;
if ( V_73 != V_75 ) {
V_78 = F_70 ( V_18 , V_73 , V_74 , V_2 ) ;
if ( V_78 )
return V_78 ;
}
return 0 ;
}
static int F_71 ( struct V_76 * V_76 , struct V_19 * V_20 , unsigned long V_152 ,
struct V_17 * V_18 , struct V_153 * V_154 )
{
struct V_23 * V_24 = F_25 ( V_20 -> V_25 ) ;
struct V_26 * V_27 = (struct V_26 * ) V_152 ;
struct V_69 * V_155 ;
struct V_12 * V_7 , * V_2 ;
if ( ! V_27 )
return V_18 -> V_74 ;
V_154 -> V_156 = V_27 -> V_59 ;
V_155 = F_72 ( V_18 , V_142 ) ;
if ( ! V_155 )
goto V_157;
if ( V_27 -> V_22 . V_133 &&
F_73 ( V_18 , V_132 , V_27 -> V_22 . V_133 ) )
goto V_157;
V_7 = & V_27 -> V_7 ;
V_2 = & V_24 -> V_2 . V_7 ;
if ( V_2 -> V_30 ) {
struct V_45 * V_46 ;
V_46 = F_74 ( V_76 , V_7 -> V_30 ) ;
if ( V_46 && F_75 ( V_18 , V_77 , V_46 -> V_158 ) )
goto V_157;
}
if ( F_68 ( V_18 , V_7 -> V_79 . V_80 , V_81 ,
V_2 -> V_79 . V_80 , V_82 ,
sizeof( V_7 -> V_79 . V_80 ) ) ||
F_68 ( V_18 , V_7 -> V_79 . V_83 , V_84 ,
V_2 -> V_79 . V_83 , V_85 ,
sizeof( V_7 -> V_79 . V_83 ) ) ||
F_68 ( V_18 , & V_7 -> V_32 . V_33 , V_86 ,
& V_2 -> V_32 . V_33 , V_75 ,
sizeof( V_7 -> V_32 . V_33 ) ) )
goto V_157;
if ( ( V_7 -> V_32 . V_33 == F_40 ( V_87 ) ||
V_7 -> V_32 . V_33 == F_40 ( V_88 ) ) &&
F_68 ( V_18 , & V_7 -> V_32 . V_89 , V_90 ,
& V_2 -> V_32 . V_89 , V_75 ,
sizeof( V_7 -> V_32 . V_89 ) ) )
goto V_157;
if ( V_7 -> V_93 . V_94 == V_95 &&
( F_68 ( V_18 , & V_7 -> V_96 . V_83 , V_91 ,
& V_2 -> V_96 . V_83 , V_97 ,
sizeof( V_7 -> V_96 . V_83 ) ) ||
F_68 ( V_18 , & V_7 -> V_96 . V_80 , V_92 ,
& V_2 -> V_96 . V_80 , V_98 ,
sizeof( V_7 -> V_96 . V_80 ) ) ) )
goto V_157;
else if ( V_7 -> V_93 . V_94 == V_101 &&
( F_68 ( V_18 , & V_7 -> V_102 . V_83 , V_99 ,
& V_2 -> V_102 . V_83 , V_103 ,
sizeof( V_7 -> V_102 . V_83 ) ) ||
F_68 ( V_18 , & V_7 -> V_102 . V_80 , V_100 ,
& V_2 -> V_102 . V_80 , V_104 ,
sizeof( V_7 -> V_102 . V_80 ) ) ) )
goto V_157;
if ( V_7 -> V_32 . V_89 == V_105 &&
( F_68 ( V_18 , & V_7 -> V_20 . V_83 , V_106 ,
& V_2 -> V_20 . V_83 , V_75 ,
sizeof( V_7 -> V_20 . V_83 ) ) ||
F_68 ( V_18 , & V_7 -> V_20 . V_80 , V_107 ,
& V_2 -> V_20 . V_80 , V_75 ,
sizeof( V_7 -> V_20 . V_80 ) ) ) )
goto V_157;
else if ( V_7 -> V_32 . V_89 == V_108 &&
( F_68 ( V_18 , & V_7 -> V_20 . V_83 , V_109 ,
& V_2 -> V_20 . V_83 , V_75 ,
sizeof( V_7 -> V_20 . V_83 ) ) ||
F_68 ( V_18 , & V_7 -> V_20 . V_80 , V_110 ,
& V_2 -> V_20 . V_80 , V_75 ,
sizeof( V_7 -> V_20 . V_80 ) ) ) )
goto V_157;
if ( F_76 ( V_18 , & V_27 -> V_38 ) )
goto V_157;
F_77 ( V_18 , V_155 ) ;
if ( F_78 ( V_18 , & V_27 -> V_38 ) < 0 )
goto V_157;
return V_18 -> V_74 ;
V_157:
F_79 ( V_18 , V_155 ) ;
return - 1 ;
}
static int T_4 F_80 ( void )
{
return F_81 ( & V_159 ) ;
}
static void T_5 F_82 ( void )
{
F_83 ( & V_159 ) ;
}
