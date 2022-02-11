static const struct V_1 * F_1 ( const char * V_2 )
{
const struct V_1 * V_3 , * V_4 = NULL ;
if ( V_2 ) {
F_2 ( & V_5 ) ;
F_3 (t, &tcf_proto_base, head) {
if ( strcmp ( V_2 , V_3 -> V_2 ) == 0 ) {
if ( F_4 ( V_3 -> V_6 ) )
V_4 = V_3 ;
break;
}
}
F_5 ( & V_5 ) ;
}
return V_4 ;
}
int F_6 ( struct V_1 * V_7 )
{
struct V_1 * V_3 ;
int V_8 = - V_9 ;
F_7 ( & V_5 ) ;
F_3 (t, &tcf_proto_base, head)
if ( ! strcmp ( V_7 -> V_2 , V_3 -> V_2 ) )
goto V_10;
F_8 ( & V_7 -> V_11 , & V_12 ) ;
V_8 = 0 ;
V_10:
F_9 ( & V_5 ) ;
return V_8 ;
}
int F_10 ( struct V_1 * V_7 )
{
struct V_1 * V_3 ;
int V_8 = - V_13 ;
F_11 () ;
F_12 ( V_14 ) ;
F_7 ( & V_5 ) ;
F_3 (t, &tcf_proto_base, head) {
if ( V_3 == V_7 ) {
F_13 ( & V_3 -> V_11 ) ;
V_8 = 0 ;
break;
}
}
F_9 ( & V_5 ) ;
return V_8 ;
}
bool F_14 ( struct V_15 * V_16 )
{
return F_15 ( V_14 , V_16 ) ;
}
static inline T_1 F_16 ( struct V_17 * V_18 )
{
T_1 V_19 = F_17 ( 0xC0000000U , 0U ) ;
if ( V_18 )
V_19 = V_18 -> V_20 - 1 ;
return F_18 ( V_19 ) ;
}
static struct V_17 * F_19 ( const char * V_2 , T_1 V_21 ,
T_1 V_20 , T_1 V_22 , struct V_23 * V_24 ,
struct V_25 * V_26 )
{
struct V_17 * V_18 ;
int V_27 ;
V_18 = F_20 ( sizeof( * V_18 ) , V_28 ) ;
if ( ! V_18 )
return F_21 ( - V_29 ) ;
V_27 = - V_13 ;
V_18 -> V_7 = F_1 ( V_2 ) ;
if ( ! V_18 -> V_7 ) {
#ifdef F_22
F_23 () ;
F_24 ( L_1 , V_2 ) ;
F_25 () ;
V_18 -> V_7 = F_1 ( V_2 ) ;
if ( V_18 -> V_7 ) {
F_26 ( V_18 -> V_7 -> V_6 ) ;
V_27 = - V_30 ;
} else {
V_27 = - V_13 ;
}
goto V_31;
#endif
}
V_18 -> V_32 = V_18 -> V_7 -> V_32 ;
V_18 -> V_21 = V_21 ;
V_18 -> V_20 = V_20 ;
V_18 -> V_33 = V_22 ;
V_18 -> V_24 = V_24 ;
V_18 -> V_26 = V_26 ;
V_27 = V_18 -> V_7 -> V_34 ( V_18 ) ;
if ( V_27 ) {
F_26 ( V_18 -> V_7 -> V_6 ) ;
goto V_31;
}
return V_18 ;
V_31:
F_27 ( V_18 ) ;
return F_21 ( V_27 ) ;
}
static void F_28 ( struct V_17 * V_18 )
{
V_18 -> V_7 -> V_35 ( V_18 ) ;
F_26 ( V_18 -> V_7 -> V_6 ) ;
F_29 ( V_18 , V_36 ) ;
}
static struct V_25 * F_30 ( struct V_37 * V_38 ,
T_1 V_39 )
{
struct V_25 * V_26 ;
V_26 = F_20 ( sizeof( * V_26 ) , V_28 ) ;
if ( ! V_26 )
return NULL ;
F_8 ( & V_26 -> V_40 , & V_38 -> V_41 ) ;
V_26 -> V_38 = V_38 ;
V_26 -> V_42 = V_39 ;
V_26 -> V_43 = 1 ;
return V_26 ;
}
static void F_31 ( struct V_25 * V_26 )
{
struct V_17 * V_18 ;
if ( V_26 -> V_44 )
F_32 ( * V_26 -> V_44 , NULL ) ;
while ( ( V_18 = F_33 ( V_26 -> V_45 ) ) != NULL ) {
F_32 ( V_26 -> V_45 , V_18 -> V_46 ) ;
F_34 ( V_26 ) ;
F_28 ( V_18 ) ;
}
}
static void F_35 ( struct V_25 * V_26 )
{
F_13 ( & V_26 -> V_40 ) ;
F_27 ( V_26 ) ;
}
static void F_36 ( struct V_25 * V_26 )
{
++ V_26 -> V_43 ;
}
struct V_25 * F_37 ( struct V_37 * V_38 , T_1 V_39 ,
bool V_47 )
{
struct V_25 * V_26 ;
F_3 (chain, &block->chain_list, list) {
if ( V_26 -> V_42 == V_39 ) {
F_36 ( V_26 ) ;
return V_26 ;
}
}
return V_47 ? F_30 ( V_38 , V_39 ) : NULL ;
}
void F_34 ( struct V_25 * V_26 )
{
if ( -- V_26 -> V_43 == 0 )
F_35 ( V_26 ) ;
}
static void
F_38 ( struct V_25 * V_26 ,
struct V_17 T_2 * * V_44 )
{
V_26 -> V_44 = V_44 ;
}
int F_39 ( struct V_37 * * V_48 ,
struct V_17 T_2 * * V_44 )
{
struct V_37 * V_38 = F_20 ( sizeof( * V_38 ) , V_28 ) ;
struct V_25 * V_26 ;
int V_27 ;
if ( ! V_38 )
return - V_49 ;
F_40 ( & V_38 -> V_41 ) ;
V_26 = F_30 ( V_38 , 0 ) ;
if ( ! V_26 ) {
V_27 = - V_49 ;
goto V_50;
}
F_38 ( V_26 , V_44 ) ;
* V_48 = V_38 ;
return 0 ;
V_50:
F_27 ( V_38 ) ;
return V_27 ;
}
static void F_41 ( struct V_15 * V_16 )
{
struct V_37 * V_38 = F_42 ( V_16 , struct V_37 , V_16 ) ;
struct V_25 * V_26 , * V_51 ;
F_25 () ;
F_43 (chain, tmp, &block->chain_list, list)
F_34 ( V_26 ) ;
F_23 () ;
F_27 ( V_38 ) ;
}
void F_44 ( struct V_37 * V_38 )
{
struct V_25 * V_26 , * V_51 ;
if ( ! V_38 )
return;
F_43 (chain, tmp, &block->chain_list, list)
F_31 ( V_26 ) ;
F_45 ( & V_38 -> V_16 , F_41 ) ;
F_11 () ;
F_14 ( & V_38 -> V_16 ) ;
}
int F_46 ( struct V_52 * V_53 , const struct V_17 * V_18 ,
struct V_54 * V_4 , bool V_55 )
{
T_3 V_21 = F_47 ( V_53 ) ;
#ifdef F_48
const int V_56 = 4 ;
const struct V_17 * V_57 = V_18 ;
const struct V_17 * V_58 ;
int V_59 = 0 ;
V_60:
#endif
for (; V_18 ; V_18 = F_49 ( V_18 -> V_46 ) ) {
int V_27 ;
if ( V_18 -> V_21 != V_21 &&
V_18 -> V_21 != F_50 ( V_61 ) )
continue;
V_27 = V_18 -> V_32 ( V_53 , V_18 , V_4 ) ;
#ifdef F_48
if ( F_51 ( V_27 == V_62 && ! V_55 ) ) {
V_58 = V_57 ;
goto V_63;
} else if ( F_51 ( F_52 ( V_27 , V_64 ) ) ) {
V_58 = V_4 -> V_65 ;
goto V_63;
}
#endif
if ( V_27 >= 0 )
return V_27 ;
}
return V_66 ;
#ifdef F_48
V_63:
if ( F_51 ( V_59 ++ >= V_56 ) ) {
F_53 ( L_2 ,
V_18 -> V_24 -> V_7 -> V_67 , V_18 -> V_20 & 0xffff ,
F_54 ( V_18 -> V_21 ) ) ;
return V_68 ;
}
V_18 = V_58 ;
V_21 = F_47 ( V_53 ) ;
goto V_60;
#endif
}
static struct V_17 * F_55 ( struct V_69 * V_70 )
{
return F_33 ( * V_70 -> V_71 ) ;
}
static void F_56 ( struct V_25 * V_26 ,
struct V_69 * V_70 ,
struct V_17 * V_18 )
{
if ( V_26 -> V_44 &&
* V_70 -> V_71 == V_26 -> V_45 )
F_57 ( * V_26 -> V_44 , V_18 ) ;
F_32 ( V_18 -> V_46 , F_55 ( V_70 ) ) ;
F_57 ( * V_70 -> V_71 , V_18 ) ;
F_36 ( V_26 ) ;
}
static void F_58 ( struct V_25 * V_26 ,
struct V_69 * V_70 ,
struct V_17 * V_18 )
{
struct V_17 * V_46 = F_33 ( V_70 -> V_46 ) ;
if ( V_26 -> V_44 && V_18 == V_26 -> V_45 )
F_32 ( * V_26 -> V_44 , V_46 ) ;
F_32 ( * V_70 -> V_71 , V_46 ) ;
F_34 ( V_26 ) ;
}
static struct V_17 * F_59 ( struct V_25 * V_26 ,
struct V_69 * V_70 ,
T_1 V_21 , T_1 V_20 ,
bool V_72 )
{
struct V_17 * * V_71 ;
struct V_17 * V_18 ;
for ( V_71 = & V_26 -> V_45 ;
( V_18 = F_33 ( * V_71 ) ) ; V_71 = & V_18 -> V_46 ) {
if ( V_18 -> V_20 >= V_20 ) {
if ( V_18 -> V_20 == V_20 ) {
if ( V_72 ||
( V_18 -> V_21 != V_21 && V_21 ) )
return F_21 ( - V_73 ) ;
} else {
V_18 = NULL ;
}
break;
}
}
V_70 -> V_71 = V_71 ;
V_70 -> V_46 = V_18 ? V_18 -> V_46 : NULL ;
return V_18 ;
}
static int F_60 ( struct V_74 * V_74 , struct V_52 * V_53 ,
struct V_17 * V_18 , void * V_75 , T_1 V_76 ,
T_1 V_77 , T_4 V_78 , int V_79 )
{
struct V_80 * V_81 ;
struct V_82 * V_83 ;
unsigned char * V_84 = F_61 ( V_53 ) ;
V_83 = F_62 ( V_53 , V_76 , V_77 , V_79 , sizeof( * V_81 ) , V_78 ) ;
if ( ! V_83 )
goto V_85;
V_81 = F_63 ( V_83 ) ;
V_81 -> V_86 = V_87 ;
V_81 -> V_88 = 0 ;
V_81 -> V_89 = 0 ;
V_81 -> V_90 = F_64 ( V_18 -> V_24 ) -> V_91 ;
V_81 -> V_92 = V_18 -> V_33 ;
V_81 -> V_93 = F_17 ( V_18 -> V_20 , V_18 -> V_21 ) ;
if ( F_65 ( V_53 , V_94 , V_18 -> V_7 -> V_2 ) )
goto V_95;
if ( F_66 ( V_53 , V_96 , V_18 -> V_26 -> V_42 ) )
goto V_95;
if ( ! V_75 ) {
V_81 -> V_97 = 0 ;
} else {
if ( V_18 -> V_7 -> V_98 && V_18 -> V_7 -> V_98 ( V_74 , V_18 , V_75 , V_53 , V_81 ) < 0 )
goto V_95;
}
V_83 -> V_99 = F_61 ( V_53 ) - V_84 ;
return V_53 -> V_100 ;
V_85:
V_95:
F_67 ( V_53 , V_84 ) ;
return - 1 ;
}
static int F_68 ( struct V_74 * V_74 , struct V_52 * V_101 ,
struct V_82 * V_102 , struct V_17 * V_18 ,
void * V_75 , int V_79 , bool V_103 )
{
struct V_52 * V_53 ;
T_1 V_76 = V_101 ? F_69 ( V_101 ) . V_76 : 0 ;
V_53 = F_70 ( V_104 , V_28 ) ;
if ( ! V_53 )
return - V_29 ;
if ( F_60 ( V_74 , V_53 , V_18 , V_75 , V_76 , V_102 -> V_105 ,
V_102 -> V_106 , V_79 ) <= 0 ) {
F_71 ( V_53 ) ;
return - V_73 ;
}
if ( V_103 )
return F_72 ( V_74 -> V_107 , V_53 , V_76 , V_108 ) ;
return F_73 ( V_53 , V_74 , V_76 , V_109 ,
V_102 -> V_106 & V_110 ) ;
}
static int F_74 ( struct V_74 * V_74 , struct V_52 * V_101 ,
struct V_82 * V_102 , struct V_17 * V_18 ,
void * V_75 , bool V_103 , bool * V_111 )
{
struct V_52 * V_53 ;
T_1 V_76 = V_101 ? F_69 ( V_101 ) . V_76 : 0 ;
int V_27 ;
V_53 = F_70 ( V_104 , V_28 ) ;
if ( ! V_53 )
return - V_29 ;
if ( F_60 ( V_74 , V_53 , V_18 , V_75 , V_76 , V_102 -> V_105 ,
V_102 -> V_106 , V_112 ) <= 0 ) {
F_71 ( V_53 ) ;
return - V_73 ;
}
V_27 = V_18 -> V_7 -> V_113 ( V_18 , V_75 , V_111 ) ;
if ( V_27 ) {
F_71 ( V_53 ) ;
return V_27 ;
}
if ( V_103 )
return F_72 ( V_74 -> V_107 , V_53 , V_76 , V_108 ) ;
return F_73 ( V_53 , V_74 , V_76 , V_109 ,
V_102 -> V_106 & V_110 ) ;
}
static void F_75 ( struct V_74 * V_74 , struct V_52 * V_101 ,
struct V_82 * V_102 ,
struct V_25 * V_26 , int V_79 )
{
struct V_17 * V_18 ;
for ( V_18 = F_33 ( V_26 -> V_45 ) ;
V_18 ; V_18 = F_33 ( V_18 -> V_46 ) )
F_68 ( V_74 , V_101 , V_102 , V_18 , 0 , V_79 , false ) ;
}
static int F_76 ( struct V_52 * V_53 , struct V_82 * V_102 ,
struct V_114 * V_115 )
{
struct V_74 * V_74 = F_77 ( V_53 -> V_116 ) ;
struct V_117 * V_118 [ V_119 + 1 ] ;
struct V_80 * V_3 ;
T_1 V_21 ;
T_1 V_20 ;
bool V_72 ;
T_1 V_22 ;
T_1 V_39 ;
struct V_120 * V_121 ;
struct V_23 * V_24 ;
struct V_69 V_70 ;
struct V_25 * V_26 = NULL ;
struct V_37 * V_38 ;
struct V_17 * V_18 ;
const struct V_122 * V_123 ;
unsigned long V_124 ;
void * V_75 ;
int V_27 ;
int V_125 ;
if ( ( V_102 -> V_126 != V_127 ) &&
! F_78 ( V_53 , V_74 -> V_128 , V_129 ) )
return - V_130 ;
V_131:
V_125 = 0 ;
V_27 = F_79 ( V_102 , sizeof( * V_3 ) , V_118 , V_119 , NULL , V_115 ) ;
if ( V_27 < 0 )
return V_27 ;
V_3 = F_63 ( V_102 ) ;
V_21 = F_80 ( V_3 -> V_93 ) ;
V_20 = F_18 ( V_3 -> V_93 ) ;
V_72 = false ;
V_22 = V_3 -> V_92 ;
V_124 = 0 ;
if ( V_20 == 0 ) {
switch ( V_102 -> V_126 ) {
case V_112 :
if ( V_21 || V_3 -> V_97 || V_118 [ V_94 ] )
return - V_13 ;
break;
case V_132 :
if ( V_102 -> V_106 & V_133 ) {
V_20 = F_17 ( 0x80000000U , 0U ) ;
V_72 = true ;
break;
}
default:
return - V_13 ;
}
}
V_121 = F_81 ( V_74 , V_3 -> V_90 ) ;
if ( V_121 == NULL )
return - V_134 ;
if ( ! V_22 ) {
V_24 = V_121 -> V_135 ;
V_22 = V_24 -> V_136 ;
} else {
V_24 = F_82 ( V_121 , F_18 ( V_3 -> V_92 ) ) ;
if ( V_24 == NULL )
return - V_73 ;
}
V_123 = V_24 -> V_7 -> V_137 ;
if ( ! V_123 )
return - V_73 ;
if ( ! V_123 -> V_37 )
return - V_138 ;
if ( F_80 ( V_22 ) ) {
V_124 = V_123 -> V_139 ( V_24 , V_22 ) ;
if ( V_124 == 0 )
return - V_13 ;
}
V_38 = V_123 -> V_37 ( V_24 , V_124 ) ;
if ( ! V_38 ) {
V_27 = - V_73 ;
goto V_31;
}
V_39 = V_118 [ V_96 ] ? F_83 ( V_118 [ V_96 ] ) : 0 ;
if ( V_39 > V_140 ) {
V_27 = - V_73 ;
goto V_31;
}
V_26 = F_37 ( V_38 , V_39 ,
V_102 -> V_126 == V_132 ) ;
if ( ! V_26 ) {
V_27 = V_102 -> V_126 == V_132 ? - V_49 : - V_73 ;
goto V_31;
}
if ( V_102 -> V_126 == V_112 && V_20 == 0 ) {
F_75 ( V_74 , V_53 , V_102 , V_26 , V_112 ) ;
F_31 ( V_26 ) ;
V_27 = 0 ;
goto V_31;
}
V_18 = F_59 ( V_26 , & V_70 , V_21 ,
V_20 , V_72 ) ;
if ( F_84 ( V_18 ) ) {
V_27 = F_85 ( V_18 ) ;
goto V_31;
}
if ( V_18 == NULL ) {
if ( V_118 [ V_94 ] == NULL || ! V_21 ) {
V_27 = - V_73 ;
goto V_31;
}
if ( V_102 -> V_126 != V_132 ||
! ( V_102 -> V_106 & V_133 ) ) {
V_27 = - V_13 ;
goto V_31;
}
if ( V_72 )
V_20 = F_16 ( F_55 ( & V_70 ) ) ;
V_18 = F_19 ( F_86 ( V_118 [ V_94 ] ) ,
V_21 , V_20 , V_22 , V_24 , V_26 ) ;
if ( F_84 ( V_18 ) ) {
V_27 = F_85 ( V_18 ) ;
goto V_31;
}
V_125 = 1 ;
} else if ( V_118 [ V_94 ] && F_87 ( V_118 [ V_94 ] , V_18 -> V_7 -> V_2 ) ) {
V_27 = - V_73 ;
goto V_31;
}
V_75 = V_18 -> V_7 -> V_141 ( V_18 , V_3 -> V_97 ) ;
if ( ! V_75 ) {
if ( V_102 -> V_126 == V_112 && V_3 -> V_97 == 0 ) {
F_58 ( V_26 , & V_70 , V_18 ) ;
F_68 ( V_74 , V_53 , V_102 , V_18 , V_75 ,
V_112 , false ) ;
F_28 ( V_18 ) ;
V_27 = 0 ;
goto V_31;
}
if ( V_102 -> V_126 != V_132 ||
! ( V_102 -> V_106 & V_133 ) ) {
V_27 = - V_13 ;
goto V_31;
}
} else {
bool V_111 ;
switch ( V_102 -> V_126 ) {
case V_132 :
if ( V_102 -> V_106 & V_142 ) {
if ( V_125 )
F_28 ( V_18 ) ;
V_27 = - V_9 ;
goto V_31;
}
break;
case V_112 :
V_27 = F_74 ( V_74 , V_53 , V_102 , V_18 , V_75 , false ,
& V_111 ) ;
if ( V_27 )
goto V_31;
if ( V_111 ) {
F_58 ( V_26 , & V_70 , V_18 ) ;
F_28 ( V_18 ) ;
}
goto V_31;
case V_127 :
V_27 = F_68 ( V_74 , V_53 , V_102 , V_18 , V_75 ,
V_132 , true ) ;
goto V_31;
default:
V_27 = - V_73 ;
goto V_31;
}
}
V_27 = V_18 -> V_7 -> V_143 ( V_74 , V_53 , V_18 , V_124 , V_3 -> V_97 , V_118 , & V_75 ,
V_102 -> V_106 & V_133 ? V_144 : V_145 ) ;
if ( V_27 == 0 ) {
if ( V_125 )
F_56 ( V_26 , & V_70 , V_18 ) ;
F_68 ( V_74 , V_53 , V_102 , V_18 , V_75 , V_132 , false ) ;
} else {
if ( V_125 )
F_28 ( V_18 ) ;
}
V_31:
if ( V_26 )
F_34 ( V_26 ) ;
if ( V_27 == - V_30 )
goto V_131;
return V_27 ;
}
static int F_88 ( struct V_17 * V_18 , void * V_102 , struct V_146 * V_147 )
{
struct V_148 * V_149 = ( void * ) V_147 ;
struct V_74 * V_74 = F_77 ( V_149 -> V_53 -> V_116 ) ;
return F_60 ( V_74 , V_149 -> V_53 , V_18 , V_102 , F_69 ( V_149 -> V_150 -> V_53 ) . V_76 ,
V_149 -> V_150 -> V_83 -> V_105 , V_151 ,
V_132 ) ;
}
static bool F_89 ( struct V_25 * V_26 , struct V_52 * V_53 ,
struct V_152 * V_150 ,
long V_153 , long * V_154 )
{
struct V_74 * V_74 = F_77 ( V_53 -> V_116 ) ;
struct V_80 * V_81 = F_63 ( V_150 -> V_83 ) ;
struct V_148 V_147 ;
struct V_17 * V_18 ;
for ( V_18 = F_33 ( V_26 -> V_45 ) ;
V_18 ; V_18 = F_33 ( V_18 -> V_46 ) , ( * V_154 ) ++ ) {
if ( * V_154 < V_153 )
continue;
if ( F_18 ( V_81 -> V_93 ) &&
F_18 ( V_81 -> V_93 ) != V_18 -> V_20 )
continue;
if ( F_80 ( V_81 -> V_93 ) &&
F_80 ( V_81 -> V_93 ) != V_18 -> V_21 )
continue;
if ( * V_154 > V_153 )
memset ( & V_150 -> args [ 1 ] , 0 ,
sizeof( V_150 -> args ) - sizeof( V_150 -> args [ 0 ] ) ) ;
if ( V_150 -> args [ 1 ] == 0 ) {
if ( F_60 ( V_74 , V_53 , V_18 , 0 ,
F_69 ( V_150 -> V_53 ) . V_76 ,
V_150 -> V_83 -> V_105 , V_151 ,
V_132 ) <= 0 )
return false ;
V_150 -> args [ 1 ] = 1 ;
}
if ( ! V_18 -> V_7 -> V_155 )
continue;
V_147 . V_156 . V_157 = F_88 ;
V_147 . V_53 = V_53 ;
V_147 . V_150 = V_150 ;
V_147 . V_156 . V_158 = 0 ;
V_147 . V_156 . V_159 = V_150 -> args [ 1 ] - 1 ;
V_147 . V_156 . V_160 = 0 ;
V_18 -> V_7 -> V_155 ( V_18 , & V_147 . V_156 ) ;
V_150 -> args [ 1 ] = V_147 . V_156 . V_160 + 1 ;
if ( V_147 . V_156 . V_158 )
return false ;
}
return true ;
}
static int F_90 ( struct V_52 * V_53 , struct V_152 * V_150 )
{
struct V_74 * V_74 = F_77 ( V_53 -> V_116 ) ;
struct V_117 * V_118 [ V_119 + 1 ] ;
struct V_120 * V_121 ;
struct V_23 * V_24 ;
struct V_37 * V_38 ;
struct V_25 * V_26 ;
struct V_80 * V_81 = F_63 ( V_150 -> V_83 ) ;
unsigned long V_124 = 0 ;
const struct V_122 * V_123 ;
long V_153 ;
long V_42 ;
int V_27 ;
if ( V_99 ( V_150 -> V_83 ) < sizeof( * V_81 ) )
return V_53 -> V_100 ;
V_27 = F_79 ( V_150 -> V_83 , sizeof( * V_81 ) , V_118 , V_119 , NULL , NULL ) ;
if ( V_27 )
return V_27 ;
V_121 = F_81 ( V_74 , V_81 -> V_90 ) ;
if ( ! V_121 )
return V_53 -> V_100 ;
if ( ! V_81 -> V_92 )
V_24 = V_121 -> V_135 ;
else
V_24 = F_82 ( V_121 , F_18 ( V_81 -> V_92 ) ) ;
if ( ! V_24 )
goto V_10;
V_123 = V_24 -> V_7 -> V_137 ;
if ( ! V_123 )
goto V_10;
if ( ! V_123 -> V_37 )
goto V_10;
if ( F_80 ( V_81 -> V_92 ) ) {
V_124 = V_123 -> V_139 ( V_24 , V_81 -> V_92 ) ;
if ( V_124 == 0 )
goto V_10;
}
V_38 = V_123 -> V_37 ( V_24 , V_124 ) ;
if ( ! V_38 )
goto V_10;
V_153 = V_150 -> args [ 0 ] ;
V_42 = 0 ;
F_3 (chain, &block->chain_list, list) {
if ( V_118 [ V_96 ] &&
F_83 ( V_118 [ V_96 ] ) != V_26 -> V_42 )
continue;
if ( ! F_89 ( V_26 , V_53 , V_150 , V_153 , & V_42 ) )
break;
}
V_150 -> args [ 0 ] = V_42 ;
V_10:
return V_53 -> V_100 ;
}
void F_91 ( struct V_161 * V_162 )
{
#ifdef F_48
F_92 ( V_163 ) ;
F_93 () ;
F_94 ( V_162 , & V_163 ) ;
F_95 ( & V_163 , V_164 ) ;
F_27 ( V_162 -> V_163 ) ;
V_162 -> V_165 = 0 ;
#endif
}
int F_96 ( struct V_74 * V_74 , struct V_17 * V_18 , struct V_117 * * V_166 ,
struct V_117 * V_167 , struct V_161 * V_162 , bool V_168 )
{
#ifdef F_48
{
struct V_169 * V_170 ;
if ( V_162 -> V_171 && V_166 [ V_162 -> V_171 ] ) {
V_170 = F_97 ( V_74 , V_18 , V_166 [ V_162 -> V_171 ] ,
V_167 , L_3 , V_168 ,
V_172 ) ;
if ( F_84 ( V_170 ) )
return F_85 ( V_170 ) ;
V_170 -> type = V_162 -> type = V_173 ;
V_162 -> V_163 [ 0 ] = V_170 ;
V_162 -> V_165 = 1 ;
} else if ( V_162 -> V_174 && V_166 [ V_162 -> V_174 ] ) {
F_92 ( V_163 ) ;
int V_27 , V_175 = 0 ;
V_27 = F_98 ( V_74 , V_18 , V_166 [ V_162 -> V_174 ] ,
V_167 , NULL , V_168 , V_172 ,
& V_163 ) ;
if ( V_27 )
return V_27 ;
F_3 (act, &actions, list)
V_162 -> V_163 [ V_175 ++ ] = V_170 ;
V_162 -> V_165 = V_175 ;
}
V_162 -> V_74 = V_74 ;
}
#else
if ( ( V_162 -> V_174 && V_166 [ V_162 -> V_174 ] ) ||
( V_162 -> V_171 && V_166 [ V_162 -> V_171 ] ) )
return - V_138 ;
#endif
return 0 ;
}
void F_99 ( struct V_161 * V_176 , struct V_161 * V_177 )
{
#ifdef F_48
struct V_161 V_178 = * V_176 ;
* V_176 = * V_177 ;
F_91 ( & V_178 ) ;
#endif
}
static struct V_169 * F_100 ( struct V_161 * V_162 )
{
if ( V_162 -> V_165 == 0 )
return NULL ;
else
return V_162 -> V_163 [ 0 ] ;
}
int F_101 ( struct V_52 * V_53 , struct V_161 * V_162 )
{
#ifdef F_48
struct V_117 * V_179 ;
if ( V_162 -> V_174 && F_102 ( V_162 ) ) {
if ( V_162 -> type != V_173 ) {
F_92 ( V_163 ) ;
V_179 = F_103 ( V_53 , V_162 -> V_174 ) ;
if ( V_179 == NULL )
goto V_95;
F_94 ( V_162 , & V_163 ) ;
if ( F_104 ( V_53 , & V_163 , 0 , 0 ) < 0 )
goto V_95;
F_105 ( V_53 , V_179 ) ;
} else if ( V_162 -> V_171 ) {
struct V_169 * V_170 = F_100 ( V_162 ) ;
V_179 = F_103 ( V_53 , V_162 -> V_171 ) ;
if ( V_179 == NULL || ! V_170 )
goto V_95;
if ( F_106 ( V_53 , V_170 , 0 , 0 ) < 0 )
goto V_95;
F_105 ( V_53 , V_179 ) ;
}
}
return 0 ;
V_95:
F_107 ( V_53 , V_179 ) ;
return - 1 ;
#else
return 0 ;
#endif
}
int F_108 ( struct V_52 * V_53 , struct V_161 * V_162 )
{
#ifdef F_48
struct V_169 * V_149 = F_100 ( V_162 ) ;
if ( V_149 != NULL && F_109 ( V_53 , V_149 , 1 ) < 0 )
return - 1 ;
#endif
return 0 ;
}
int F_110 ( struct V_120 * V_121 , struct V_161 * V_162 ,
struct V_120 * * V_180 )
{
#ifdef F_48
const struct V_169 * V_149 ;
F_92 ( V_163 ) ;
if ( ! F_102 ( V_162 ) )
return - V_73 ;
F_94 ( V_162 , & V_163 ) ;
F_3 (a, &actions, list) {
if ( V_149 -> V_7 -> V_181 ) {
V_149 -> V_7 -> V_181 ( V_149 , F_111 ( V_121 ) , V_180 ) ;
break;
}
}
if ( * V_180 )
return 0 ;
#endif
return - V_138 ;
}
static int T_5 F_112 ( void )
{
V_14 = F_113 ( L_4 , 0 ) ;
if ( ! V_14 )
return - V_49 ;
F_114 ( V_182 , V_132 , F_76 , NULL , 0 ) ;
F_114 ( V_182 , V_112 , F_76 , NULL , 0 ) ;
F_114 ( V_182 , V_127 , F_76 ,
F_90 , 0 ) ;
return 0 ;
}
