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
if ( ! F_22 ( V_46 , V_20 , 0 ) )
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
if ( ! F_22 ( V_46 , V_20 , V_63 ) )
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
static void F_24 ( struct V_19 * V_20 , struct V_26 * V_27 )
{
struct V_45 * V_46 = V_20 -> V_47 -> V_48 -> V_46 ;
struct V_49 V_50 = { 0 } ;
struct V_51 V_52 ;
if ( ! F_22 ( V_46 , V_20 , 0 ) )
return;
V_50 . V_53 = V_65 ;
V_50 . V_44 = ( unsigned long ) V_27 ;
V_50 . V_38 = & V_27 -> V_38 ;
V_52 . type = V_55 ;
V_52 . V_56 = & V_50 ;
V_46 -> V_57 -> V_58 ( V_46 , V_20 -> V_47 -> V_59 , V_20 -> V_34 , & V_52 ) ;
}
static bool F_25 ( struct V_19 * V_20 , bool V_66 )
{
struct V_23 * V_24 = F_26 ( V_20 -> V_25 ) ;
struct V_26 * V_27 , * V_67 ;
if ( ! V_66 && ! F_27 ( & V_24 -> V_41 ) )
return false ;
F_28 (f, next, &head->filters, list) {
F_21 ( V_20 , ( unsigned long ) V_27 ) ;
F_29 ( & V_27 -> V_68 ) ;
F_30 ( & V_27 -> V_43 , F_17 ) ;
}
F_31 ( V_20 -> V_25 , NULL ) ;
if ( V_24 -> V_69 )
F_32 ( & V_24 -> V_36 ) ;
F_33 ( V_24 , V_43 ) ;
return true ;
}
static unsigned long F_34 ( struct V_19 * V_20 , T_3 V_59 )
{
struct V_23 * V_24 = F_26 ( V_20 -> V_25 ) ;
struct V_26 * V_27 ;
F_35 (f, &head->filters, list)
if ( V_27 -> V_59 == V_59 )
return ( unsigned long ) V_27 ;
return 0 ;
}
static void F_36 ( struct V_70 * * V_71 ,
void * V_72 , int V_73 ,
void * V_2 , int V_74 , int V_75 )
{
if ( ! V_71 [ V_73 ] )
return;
memcpy ( V_72 , F_37 ( V_71 [ V_73 ] ) , V_75 ) ;
if ( V_74 == V_76 || ! V_71 [ V_74 ] )
memset ( V_2 , 0xff , V_75 ) ;
else
memcpy ( V_2 , F_37 ( V_71 [ V_74 ] ) , V_75 ) ;
}
static int F_38 ( struct V_77 * V_77 , struct V_70 * * V_71 ,
struct V_12 * V_7 , struct V_12 * V_2 )
{
#ifdef F_39
if ( V_71 [ V_78 ] ) {
int V_79 = F_40 ( V_77 , V_71 [ V_78 ] ) ;
if ( V_79 < 0 )
return V_79 ;
V_7 -> V_30 = V_79 ;
V_2 -> V_30 = 0xffffffff ;
}
#endif
F_36 ( V_71 , V_7 -> V_80 . V_81 , V_82 ,
V_2 -> V_80 . V_81 , V_83 ,
sizeof( V_7 -> V_80 . V_81 ) ) ;
F_36 ( V_71 , V_7 -> V_80 . V_84 , V_85 ,
V_2 -> V_80 . V_84 , V_86 ,
sizeof( V_7 -> V_80 . V_84 ) ) ;
F_36 ( V_71 , & V_7 -> V_32 . V_33 , V_87 ,
& V_2 -> V_32 . V_33 , V_76 ,
sizeof( V_7 -> V_32 . V_33 ) ) ;
if ( V_7 -> V_32 . V_33 == F_41 ( V_88 ) ||
V_7 -> V_32 . V_33 == F_41 ( V_89 ) ) {
F_36 ( V_71 , & V_7 -> V_32 . V_90 , V_91 ,
& V_2 -> V_32 . V_90 , V_76 ,
sizeof( V_7 -> V_32 . V_90 ) ) ;
}
if ( V_71 [ V_92 ] || V_71 [ V_93 ] ) {
V_7 -> V_94 . V_95 = V_96 ;
F_36 ( V_71 , & V_7 -> V_97 . V_84 , V_92 ,
& V_2 -> V_97 . V_84 , V_98 ,
sizeof( V_7 -> V_97 . V_84 ) ) ;
F_36 ( V_71 , & V_7 -> V_97 . V_81 , V_93 ,
& V_2 -> V_97 . V_81 , V_99 ,
sizeof( V_7 -> V_97 . V_81 ) ) ;
} else if ( V_71 [ V_100 ] || V_71 [ V_101 ] ) {
V_7 -> V_94 . V_95 = V_102 ;
F_36 ( V_71 , & V_7 -> V_103 . V_84 , V_100 ,
& V_2 -> V_103 . V_84 , V_104 ,
sizeof( V_7 -> V_103 . V_84 ) ) ;
F_36 ( V_71 , & V_7 -> V_103 . V_81 , V_101 ,
& V_2 -> V_103 . V_81 , V_105 ,
sizeof( V_7 -> V_103 . V_81 ) ) ;
}
if ( V_7 -> V_32 . V_90 == V_106 ) {
F_36 ( V_71 , & V_7 -> V_20 . V_84 , V_107 ,
& V_2 -> V_20 . V_84 , V_76 ,
sizeof( V_7 -> V_20 . V_84 ) ) ;
F_36 ( V_71 , & V_7 -> V_20 . V_81 , V_108 ,
& V_2 -> V_20 . V_81 , V_76 ,
sizeof( V_7 -> V_20 . V_81 ) ) ;
} else if ( V_7 -> V_32 . V_90 == V_109 ) {
F_36 ( V_71 , & V_7 -> V_20 . V_84 , V_110 ,
& V_2 -> V_20 . V_84 , V_76 ,
sizeof( V_7 -> V_20 . V_84 ) ) ;
F_36 ( V_71 , & V_7 -> V_20 . V_81 , V_111 ,
& V_2 -> V_20 . V_81 , V_76 ,
sizeof( V_7 -> V_20 . V_81 ) ) ;
}
return 0 ;
}
static bool F_42 ( struct V_1 * V_112 ,
struct V_1 * V_113 )
{
const long * V_114 = F_5 ( & V_112 -> V_7 , V_112 ) ;
const long * V_115 = F_5 ( & V_113 -> V_7 , V_113 ) ;
return ! memcmp ( & V_112 -> V_3 , & V_113 -> V_3 , sizeof( V_112 -> V_3 ) ) &&
! memcmp ( V_114 , V_115 , F_1 ( V_112 ) ) ;
}
static int F_43 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
V_24 -> V_37 = V_116 ;
V_24 -> V_37 . V_117 = F_1 ( V_2 ) ;
V_24 -> V_37 . V_118 += V_2 -> V_3 . V_5 ;
return F_44 ( & V_24 -> V_36 , & V_24 -> V_37 ) ;
}
static void F_45 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_119 V_120 [ V_121 ] ;
T_2 V_122 = 0 ;
F_46 ( V_120 , V_122 , V_123 , V_94 ) ;
F_46 ( V_120 , V_122 , V_124 , V_32 ) ;
F_47 ( V_2 , V_120 , V_122 ,
V_125 , V_80 ) ;
F_47 ( V_2 , V_120 , V_122 ,
V_96 , V_97 ) ;
F_47 ( V_2 , V_120 , V_122 ,
V_102 , V_103 ) ;
F_47 ( V_2 , V_120 , V_122 ,
V_126 , V_20 ) ;
F_48 ( & V_24 -> V_35 , V_120 , V_122 ) ;
}
static int F_49 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
int V_79 ;
if ( V_24 -> V_69 ) {
if ( ! F_42 ( & V_24 -> V_2 , V_2 ) )
return - V_127 ;
else
return 0 ;
}
V_79 = F_43 ( V_24 , V_2 ) ;
if ( V_79 )
return V_79 ;
memcpy ( & V_24 -> V_2 , V_2 , sizeof( V_24 -> V_2 ) ) ;
V_24 -> V_69 = true ;
F_45 ( V_24 , V_2 ) ;
return 0 ;
}
static int F_50 ( struct V_77 * V_77 , struct V_19 * V_20 ,
struct V_26 * V_27 , struct V_1 * V_2 ,
unsigned long V_128 , struct V_70 * * V_71 ,
struct V_70 * V_129 , bool V_130 )
{
struct V_61 V_131 ;
int V_79 ;
F_51 ( & V_131 , V_132 , 0 ) ;
V_79 = F_52 ( V_77 , V_20 , V_71 , V_129 , & V_131 , V_130 ) ;
if ( V_79 < 0 )
return V_79 ;
if ( V_71 [ V_133 ] ) {
V_27 -> V_22 . V_134 = F_53 ( V_71 [ V_133 ] ) ;
F_54 ( V_20 , & V_27 -> V_22 , V_128 ) ;
}
V_79 = F_38 ( V_77 , V_71 , & V_27 -> V_7 , & V_2 -> V_7 ) ;
if ( V_79 )
goto V_135;
F_2 ( V_2 ) ;
F_6 ( & V_27 -> V_13 , & V_27 -> V_7 , V_2 ) ;
F_55 ( V_20 , & V_27 -> V_38 , & V_131 ) ;
return 0 ;
V_135:
F_19 ( & V_131 ) ;
return V_79 ;
}
static T_3 F_56 ( struct V_19 * V_20 ,
struct V_23 * V_24 )
{
unsigned int V_9 = 0x80000000 ;
T_3 V_59 ;
do {
if ( ++ V_24 -> V_136 == 0x7FFFFFFF )
V_24 -> V_136 = 1 ;
} while ( -- V_9 > 0 && F_34 ( V_20 , V_24 -> V_136 ) );
if ( F_57 ( V_9 == 0 ) ) {
F_58 ( L_1 ) ;
V_59 = 0 ;
} else {
V_59 = V_24 -> V_136 ;
}
return V_59 ;
}
static int F_59 ( struct V_77 * V_77 , struct V_17 * V_137 ,
struct V_19 * V_20 , unsigned long V_128 ,
T_3 V_59 , struct V_70 * * V_138 ,
unsigned long * V_139 , bool V_130 )
{
struct V_23 * V_24 = F_26 ( V_20 -> V_25 ) ;
struct V_26 * V_140 = (struct V_26 * ) * V_139 ;
struct V_26 * V_141 ;
struct V_70 * V_71 [ V_142 + 1 ] ;
struct V_1 V_2 = {} ;
T_3 V_63 = 0 ;
int V_79 ;
if ( ! V_138 [ V_143 ] )
return - V_127 ;
V_79 = F_60 ( V_71 , V_142 , V_138 [ V_143 ] , V_144 ) ;
if ( V_79 < 0 )
return V_79 ;
if ( V_140 && V_59 && V_140 -> V_59 != V_59 )
return - V_127 ;
V_141 = F_14 ( sizeof( * V_141 ) , V_39 ) ;
if ( ! V_141 )
return - V_40 ;
F_51 ( & V_141 -> V_38 , V_132 , 0 ) ;
if ( ! V_59 ) {
V_59 = F_56 ( V_20 , V_24 ) ;
if ( ! V_59 ) {
V_79 = - V_127 ;
goto V_135;
}
}
V_141 -> V_59 = V_59 ;
if ( V_71 [ V_145 ] )
V_63 = F_53 ( V_71 [ V_145 ] ) ;
V_79 = F_50 ( V_77 , V_20 , V_141 , & V_2 , V_128 , V_71 , V_138 [ V_146 ] , V_130 ) ;
if ( V_79 )
goto V_135;
V_79 = F_49 ( V_24 , & V_2 ) ;
if ( V_79 )
goto V_135;
V_79 = F_61 ( & V_24 -> V_36 , & V_141 -> V_147 ,
V_24 -> V_37 ) ;
if ( V_79 )
goto V_135;
F_23 ( V_20 ,
& V_24 -> V_35 ,
& V_2 . V_7 ,
& V_141 -> V_7 ,
& V_141 -> V_38 ,
( unsigned long ) V_141 ,
V_63 ) ;
if ( V_140 ) {
F_62 ( & V_24 -> V_36 , & V_140 -> V_147 ,
V_24 -> V_37 ) ;
F_21 ( V_20 , ( unsigned long ) V_140 ) ;
}
* V_139 = ( unsigned long ) V_141 ;
if ( V_140 ) {
F_63 ( & V_140 -> V_68 , & V_141 -> V_68 ) ;
F_64 ( V_20 , & V_140 -> V_22 ) ;
F_30 ( & V_140 -> V_43 , F_17 ) ;
} else {
F_65 ( & V_141 -> V_68 , & V_24 -> V_41 ) ;
}
return 0 ;
V_135:
F_20 ( V_141 ) ;
return V_79 ;
}
static int F_66 ( struct V_19 * V_20 , unsigned long V_139 )
{
struct V_23 * V_24 = F_26 ( V_20 -> V_25 ) ;
struct V_26 * V_27 = (struct V_26 * ) V_139 ;
F_62 ( & V_24 -> V_36 , & V_27 -> V_147 ,
V_24 -> V_37 ) ;
F_29 ( & V_27 -> V_68 ) ;
F_21 ( V_20 , ( unsigned long ) V_27 ) ;
F_64 ( V_20 , & V_27 -> V_22 ) ;
F_30 ( & V_27 -> V_43 , F_17 ) ;
return 0 ;
}
static void F_67 ( struct V_19 * V_20 , struct V_148 * V_139 )
{
struct V_23 * V_24 = F_26 ( V_20 -> V_25 ) ;
struct V_26 * V_27 ;
F_68 (f, &head->filters, list) {
if ( V_139 -> V_149 < V_139 -> V_150 )
goto V_150;
if ( V_139 -> V_151 ( V_20 , ( unsigned long ) V_27 , V_139 ) < 0 ) {
V_139 -> V_152 = 1 ;
break;
}
V_150:
V_139 -> V_149 ++ ;
}
}
static int F_69 ( struct V_17 * V_18 ,
void * V_72 , int V_73 ,
void * V_2 , int V_74 , int V_75 )
{
int V_79 ;
if ( ! F_70 ( V_2 , 0 , V_75 ) )
return 0 ;
V_79 = F_71 ( V_18 , V_73 , V_75 , V_72 ) ;
if ( V_79 )
return V_79 ;
if ( V_74 != V_76 ) {
V_79 = F_71 ( V_18 , V_74 , V_75 , V_2 ) ;
if ( V_79 )
return V_79 ;
}
return 0 ;
}
static int F_72 ( struct V_77 * V_77 , struct V_19 * V_20 , unsigned long V_153 ,
struct V_17 * V_18 , struct V_154 * V_155 )
{
struct V_23 * V_24 = F_26 ( V_20 -> V_25 ) ;
struct V_26 * V_27 = (struct V_26 * ) V_153 ;
struct V_70 * V_156 ;
struct V_12 * V_7 , * V_2 ;
if ( ! V_27 )
return V_18 -> V_75 ;
V_155 -> V_157 = V_27 -> V_59 ;
V_156 = F_73 ( V_18 , V_143 ) ;
if ( ! V_156 )
goto V_158;
if ( V_27 -> V_22 . V_134 &&
F_74 ( V_18 , V_133 , V_27 -> V_22 . V_134 ) )
goto V_158;
V_7 = & V_27 -> V_7 ;
V_2 = & V_24 -> V_2 . V_7 ;
if ( V_2 -> V_30 ) {
struct V_45 * V_46 ;
V_46 = F_75 ( V_77 , V_7 -> V_30 ) ;
if ( V_46 && F_76 ( V_18 , V_78 , V_46 -> V_159 ) )
goto V_158;
}
F_24 ( V_20 , V_27 ) ;
if ( F_69 ( V_18 , V_7 -> V_80 . V_81 , V_82 ,
V_2 -> V_80 . V_81 , V_83 ,
sizeof( V_7 -> V_80 . V_81 ) ) ||
F_69 ( V_18 , V_7 -> V_80 . V_84 , V_85 ,
V_2 -> V_80 . V_84 , V_86 ,
sizeof( V_7 -> V_80 . V_84 ) ) ||
F_69 ( V_18 , & V_7 -> V_32 . V_33 , V_87 ,
& V_2 -> V_32 . V_33 , V_76 ,
sizeof( V_7 -> V_32 . V_33 ) ) )
goto V_158;
if ( ( V_7 -> V_32 . V_33 == F_41 ( V_88 ) ||
V_7 -> V_32 . V_33 == F_41 ( V_89 ) ) &&
F_69 ( V_18 , & V_7 -> V_32 . V_90 , V_91 ,
& V_2 -> V_32 . V_90 , V_76 ,
sizeof( V_7 -> V_32 . V_90 ) ) )
goto V_158;
if ( V_7 -> V_94 . V_95 == V_96 &&
( F_69 ( V_18 , & V_7 -> V_97 . V_84 , V_92 ,
& V_2 -> V_97 . V_84 , V_98 ,
sizeof( V_7 -> V_97 . V_84 ) ) ||
F_69 ( V_18 , & V_7 -> V_97 . V_81 , V_93 ,
& V_2 -> V_97 . V_81 , V_99 ,
sizeof( V_7 -> V_97 . V_81 ) ) ) )
goto V_158;
else if ( V_7 -> V_94 . V_95 == V_102 &&
( F_69 ( V_18 , & V_7 -> V_103 . V_84 , V_100 ,
& V_2 -> V_103 . V_84 , V_104 ,
sizeof( V_7 -> V_103 . V_84 ) ) ||
F_69 ( V_18 , & V_7 -> V_103 . V_81 , V_101 ,
& V_2 -> V_103 . V_81 , V_105 ,
sizeof( V_7 -> V_103 . V_81 ) ) ) )
goto V_158;
if ( V_7 -> V_32 . V_90 == V_106 &&
( F_69 ( V_18 , & V_7 -> V_20 . V_84 , V_107 ,
& V_2 -> V_20 . V_84 , V_76 ,
sizeof( V_7 -> V_20 . V_84 ) ) ||
F_69 ( V_18 , & V_7 -> V_20 . V_81 , V_108 ,
& V_2 -> V_20 . V_81 , V_76 ,
sizeof( V_7 -> V_20 . V_81 ) ) ) )
goto V_158;
else if ( V_7 -> V_32 . V_90 == V_109 &&
( F_69 ( V_18 , & V_7 -> V_20 . V_84 , V_110 ,
& V_2 -> V_20 . V_84 , V_76 ,
sizeof( V_7 -> V_20 . V_84 ) ) ||
F_69 ( V_18 , & V_7 -> V_20 . V_81 , V_111 ,
& V_2 -> V_20 . V_81 , V_76 ,
sizeof( V_7 -> V_20 . V_81 ) ) ) )
goto V_158;
if ( F_77 ( V_18 , & V_27 -> V_38 ) )
goto V_158;
F_78 ( V_18 , V_156 ) ;
if ( F_79 ( V_18 , & V_27 -> V_38 ) < 0 )
goto V_158;
return V_18 -> V_75 ;
V_158:
F_80 ( V_18 , V_156 ) ;
return - 1 ;
}
static int T_4 F_81 ( void )
{
return F_82 ( & V_160 ) ;
}
static void T_5 F_83 ( void )
{
F_84 ( & V_160 ) ;
}
