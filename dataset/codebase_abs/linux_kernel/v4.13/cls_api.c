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
F_7 ( & V_5 ) ;
F_3 (t, &tcf_proto_base, head) {
if ( V_3 == V_7 ) {
F_12 ( & V_3 -> V_11 ) ;
V_8 = 0 ;
break;
}
}
F_9 ( & V_5 ) ;
return V_8 ;
}
static void F_13 ( struct V_14 * V_14 , struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_19 * V_20 , int V_21 )
{
struct V_22 * V_23 ;
for ( V_23 = F_14 ( V_20 -> V_24 ) ;
V_23 ; V_23 = F_14 ( V_23 -> V_25 ) )
F_15 ( V_14 , V_16 , V_18 , V_23 , 0 , V_21 , false ) ;
}
static inline T_1 F_16 ( struct V_22 * V_23 )
{
T_1 V_26 = F_17 ( 0xC0000000U , 0U ) ;
if ( V_23 )
V_26 = V_23 -> V_27 - 1 ;
return F_18 ( V_26 ) ;
}
static struct V_22 * F_19 ( const char * V_2 , T_1 V_28 ,
T_1 V_27 , T_1 V_29 , struct V_30 * V_31 ,
struct V_19 * V_20 )
{
struct V_22 * V_23 ;
int V_32 ;
V_23 = F_20 ( sizeof( * V_23 ) , V_33 ) ;
if ( ! V_23 )
return F_21 ( - V_34 ) ;
V_32 = - V_13 ;
V_23 -> V_7 = F_1 ( V_2 ) ;
if ( ! V_23 -> V_7 ) {
#ifdef F_22
F_23 () ;
F_24 ( L_1 , V_2 ) ;
F_25 () ;
V_23 -> V_7 = F_1 ( V_2 ) ;
if ( V_23 -> V_7 ) {
F_26 ( V_23 -> V_7 -> V_6 ) ;
V_32 = - V_35 ;
} else {
V_32 = - V_13 ;
}
goto V_36;
#endif
}
V_23 -> V_37 = V_23 -> V_7 -> V_37 ;
V_23 -> V_28 = V_28 ;
V_23 -> V_27 = V_27 ;
V_23 -> V_38 = V_29 ;
V_23 -> V_31 = V_31 ;
V_23 -> V_20 = V_20 ;
V_32 = V_23 -> V_7 -> V_39 ( V_23 ) ;
if ( V_32 ) {
F_26 ( V_23 -> V_7 -> V_6 ) ;
goto V_36;
}
return V_23 ;
V_36:
F_27 ( V_23 ) ;
return F_21 ( V_32 ) ;
}
static void F_28 ( struct V_22 * V_23 )
{
V_23 -> V_7 -> V_40 ( V_23 ) ;
F_26 ( V_23 -> V_7 -> V_6 ) ;
F_29 ( V_23 , V_41 ) ;
}
static struct V_19 * F_30 ( struct V_42 * V_43 ,
T_1 V_44 )
{
struct V_19 * V_20 ;
V_20 = F_20 ( sizeof( * V_20 ) , V_33 ) ;
if ( ! V_20 )
return NULL ;
F_8 ( & V_20 -> V_45 , & V_43 -> V_46 ) ;
V_20 -> V_43 = V_43 ;
V_20 -> V_47 = V_44 ;
V_20 -> V_48 = 1 ;
return V_20 ;
}
static void F_31 ( struct V_19 * V_20 )
{
struct V_22 * V_23 ;
if ( V_20 -> V_49 )
F_32 ( * V_20 -> V_49 , NULL ) ;
while ( ( V_23 = F_14 ( V_20 -> V_24 ) ) != NULL ) {
F_32 ( V_20 -> V_24 , V_23 -> V_25 ) ;
F_28 ( V_23 ) ;
}
}
static void F_33 ( struct V_19 * V_20 )
{
if ( ! F_34 ( & V_20 -> V_45 ) )
F_35 ( & V_20 -> V_45 ) ;
if ( ! V_20 -> V_48 )
F_27 ( V_20 ) ;
}
struct V_19 * F_36 ( struct V_42 * V_43 , T_1 V_44 ,
bool V_50 )
{
struct V_19 * V_20 ;
F_3 (chain, &block->chain_list, list) {
if ( V_20 -> V_47 == V_44 ) {
V_20 -> V_48 ++ ;
return V_20 ;
}
}
if ( V_50 )
return F_30 ( V_43 , V_44 ) ;
else
return NULL ;
}
void F_37 ( struct V_19 * V_20 )
{
if ( -- V_20 -> V_48 == 0 && ! V_20 -> V_24 && V_20 -> V_47 != 0 )
F_33 ( V_20 ) ;
}
static void
F_38 ( struct V_19 * V_20 ,
struct V_22 T_2 * * V_49 )
{
V_20 -> V_49 = V_49 ;
}
int F_39 ( struct V_42 * * V_51 ,
struct V_22 T_2 * * V_49 )
{
struct V_42 * V_43 = F_20 ( sizeof( * V_43 ) , V_33 ) ;
struct V_19 * V_20 ;
int V_32 ;
if ( ! V_43 )
return - V_52 ;
F_40 ( & V_43 -> V_46 ) ;
V_20 = F_30 ( V_43 , 0 ) ;
if ( ! V_20 ) {
V_32 = - V_52 ;
goto V_53;
}
F_38 ( V_20 , V_49 ) ;
* V_51 = V_43 ;
return 0 ;
V_53:
F_27 ( V_43 ) ;
return V_32 ;
}
void F_41 ( struct V_42 * V_43 )
{
struct V_19 * V_20 , * V_54 ;
if ( ! V_43 )
return;
F_42 (chain, tmp, &block->chain_list, list) {
F_31 ( V_20 ) ;
F_33 ( V_20 ) ;
}
F_27 ( V_43 ) ;
}
int F_43 ( struct V_15 * V_55 , const struct V_22 * V_23 ,
struct V_56 * V_4 , bool V_57 )
{
T_3 V_28 = F_44 ( V_55 ) ;
#ifdef F_45
const int V_58 = 4 ;
const struct V_22 * V_59 = V_23 ;
const struct V_22 * V_60 ;
int V_61 = 0 ;
V_62:
#endif
for (; V_23 ; V_23 = F_46 ( V_23 -> V_25 ) ) {
int V_32 ;
if ( V_23 -> V_28 != V_28 &&
V_23 -> V_28 != F_47 ( V_63 ) )
continue;
V_32 = V_23 -> V_37 ( V_55 , V_23 , V_4 ) ;
#ifdef F_45
if ( F_48 ( V_32 == V_64 && ! V_57 ) ) {
V_60 = V_59 ;
goto V_65;
} else if ( F_48 ( F_49 ( V_32 , V_66 ) ) ) {
V_60 = V_4 -> V_67 ;
goto V_65;
}
#endif
if ( V_32 >= 0 )
return V_32 ;
}
return V_68 ;
#ifdef F_45
V_65:
if ( F_48 ( V_61 ++ >= V_58 ) ) {
F_50 ( L_2 ,
V_23 -> V_31 -> V_7 -> V_69 , V_23 -> V_27 & 0xffff ,
F_51 ( V_23 -> V_28 ) ) ;
return V_70 ;
}
V_23 = V_60 ;
V_28 = F_44 ( V_55 ) ;
goto V_62;
#endif
}
static struct V_22 * F_52 ( struct V_71 * V_72 )
{
return F_14 ( * V_72 -> V_73 ) ;
}
static void F_53 ( struct V_19 * V_20 ,
struct V_71 * V_72 ,
struct V_22 * V_23 )
{
if ( V_20 -> V_49 &&
* V_72 -> V_73 == V_20 -> V_24 )
F_54 ( * V_20 -> V_49 , V_23 ) ;
F_32 ( V_23 -> V_25 , F_52 ( V_72 ) ) ;
F_54 ( * V_72 -> V_73 , V_23 ) ;
}
static void F_55 ( struct V_19 * V_20 ,
struct V_71 * V_72 ,
struct V_22 * V_23 )
{
struct V_22 * V_25 = F_14 ( V_72 -> V_25 ) ;
if ( V_20 -> V_49 && V_23 == V_20 -> V_24 )
F_32 ( * V_20 -> V_49 , V_25 ) ;
F_32 ( * V_72 -> V_73 , V_25 ) ;
}
static struct V_22 * F_56 ( struct V_19 * V_20 ,
struct V_71 * V_72 ,
T_1 V_28 , T_1 V_27 ,
bool V_74 )
{
struct V_22 * * V_73 ;
struct V_22 * V_23 ;
for ( V_73 = & V_20 -> V_24 ;
( V_23 = F_14 ( * V_73 ) ) ; V_73 = & V_23 -> V_25 ) {
if ( V_23 -> V_27 >= V_27 ) {
if ( V_23 -> V_27 == V_27 ) {
if ( V_74 ||
( V_23 -> V_28 != V_28 && V_28 ) )
return F_21 ( - V_75 ) ;
} else {
V_23 = NULL ;
}
break;
}
}
V_72 -> V_73 = V_73 ;
V_72 -> V_25 = V_23 ? V_23 -> V_25 : NULL ;
return V_23 ;
}
static int F_57 ( struct V_15 * V_55 , struct V_17 * V_18 ,
struct V_76 * V_77 )
{
struct V_14 * V_14 = F_58 ( V_55 -> V_78 ) ;
struct V_79 * V_80 [ V_81 + 1 ] ;
struct V_82 * V_3 ;
T_1 V_28 ;
T_1 V_27 ;
bool V_74 ;
T_1 V_29 ;
T_1 V_44 ;
struct V_83 * V_84 ;
struct V_30 * V_31 ;
struct V_71 V_72 ;
struct V_19 * V_20 = NULL ;
struct V_42 * V_43 ;
struct V_22 * V_23 ;
const struct V_85 * V_86 ;
unsigned long V_87 ;
unsigned long V_88 ;
int V_32 ;
int V_89 ;
if ( ( V_18 -> V_90 != V_91 ) &&
! F_59 ( V_55 , V_14 -> V_92 , V_93 ) )
return - V_94 ;
V_95:
V_89 = 0 ;
V_32 = F_60 ( V_18 , sizeof( * V_3 ) , V_80 , V_81 , NULL , V_77 ) ;
if ( V_32 < 0 )
return V_32 ;
V_3 = F_61 ( V_18 ) ;
V_28 = F_62 ( V_3 -> V_96 ) ;
V_27 = F_18 ( V_3 -> V_96 ) ;
V_74 = false ;
V_29 = V_3 -> V_97 ;
V_87 = 0 ;
if ( V_27 == 0 ) {
switch ( V_18 -> V_90 ) {
case V_98 :
if ( V_28 || V_3 -> V_99 || V_80 [ V_100 ] )
return - V_13 ;
break;
case V_101 :
if ( V_18 -> V_102 & V_103 ) {
V_27 = F_17 ( 0x80000000U , 0U ) ;
V_74 = true ;
break;
}
default:
return - V_13 ;
}
}
V_84 = F_63 ( V_14 , V_3 -> V_104 ) ;
if ( V_84 == NULL )
return - V_105 ;
if ( ! V_29 ) {
V_31 = V_84 -> V_106 ;
V_29 = V_31 -> V_107 ;
} else {
V_31 = F_64 ( V_84 , F_18 ( V_3 -> V_97 ) ) ;
if ( V_31 == NULL )
return - V_75 ;
}
V_86 = V_31 -> V_7 -> V_108 ;
if ( ! V_86 )
return - V_75 ;
if ( ! V_86 -> V_42 )
return - V_109 ;
if ( F_62 ( V_29 ) ) {
V_87 = V_86 -> V_110 ( V_31 , V_29 ) ;
if ( V_87 == 0 )
return - V_13 ;
}
V_43 = V_86 -> V_42 ( V_31 , V_87 ) ;
if ( ! V_43 ) {
V_32 = - V_75 ;
goto V_36;
}
V_44 = V_80 [ V_111 ] ? F_65 ( V_80 [ V_111 ] ) : 0 ;
if ( V_44 > V_112 ) {
V_32 = - V_75 ;
goto V_36;
}
V_20 = F_36 ( V_43 , V_44 ,
V_18 -> V_90 == V_101 ) ;
if ( ! V_20 ) {
V_32 = V_18 -> V_90 == V_101 ? - V_52 : - V_75 ;
goto V_36;
}
if ( V_18 -> V_90 == V_98 && V_27 == 0 ) {
F_13 ( V_14 , V_55 , V_18 , V_20 , V_98 ) ;
F_31 ( V_20 ) ;
V_32 = 0 ;
goto V_36;
}
V_23 = F_56 ( V_20 , & V_72 , V_28 ,
V_27 , V_74 ) ;
if ( F_66 ( V_23 ) ) {
V_32 = F_67 ( V_23 ) ;
goto V_36;
}
if ( V_23 == NULL ) {
if ( V_80 [ V_100 ] == NULL || ! V_28 ) {
V_32 = - V_75 ;
goto V_36;
}
if ( V_18 -> V_90 != V_101 ||
! ( V_18 -> V_102 & V_103 ) ) {
V_32 = - V_13 ;
goto V_36;
}
if ( V_74 )
V_27 = F_16 ( F_52 ( & V_72 ) ) ;
V_23 = F_19 ( F_68 ( V_80 [ V_100 ] ) ,
V_28 , V_27 , V_29 , V_31 , V_20 ) ;
if ( F_66 ( V_23 ) ) {
V_32 = F_67 ( V_23 ) ;
goto V_36;
}
V_89 = 1 ;
} else if ( V_80 [ V_100 ] && F_69 ( V_80 [ V_100 ] , V_23 -> V_7 -> V_2 ) ) {
V_32 = - V_75 ;
goto V_36;
}
V_88 = V_23 -> V_7 -> V_110 ( V_23 , V_3 -> V_99 ) ;
if ( V_88 == 0 ) {
if ( V_18 -> V_90 == V_98 && V_3 -> V_99 == 0 ) {
F_55 ( V_20 , & V_72 , V_23 ) ;
F_15 ( V_14 , V_55 , V_18 , V_23 , V_88 ,
V_98 , false ) ;
F_28 ( V_23 ) ;
V_32 = 0 ;
goto V_36;
}
if ( V_18 -> V_90 != V_101 ||
! ( V_18 -> V_102 & V_103 ) ) {
V_32 = - V_13 ;
goto V_36;
}
} else {
bool V_113 ;
switch ( V_18 -> V_90 ) {
case V_101 :
if ( V_18 -> V_102 & V_114 ) {
if ( V_89 )
F_28 ( V_23 ) ;
V_32 = - V_9 ;
goto V_36;
}
break;
case V_98 :
V_32 = V_23 -> V_7 -> V_115 ( V_23 , V_88 , & V_113 ) ;
if ( V_32 )
goto V_36;
F_15 ( V_14 , V_55 , V_18 , V_23 , V_3 -> V_99 ,
V_98 , false ) ;
if ( V_113 ) {
F_55 ( V_20 , & V_72 , V_23 ) ;
F_28 ( V_23 ) ;
}
goto V_36;
case V_91 :
V_32 = F_15 ( V_14 , V_55 , V_18 , V_23 , V_88 ,
V_101 , true ) ;
goto V_36;
default:
V_32 = - V_75 ;
goto V_36;
}
}
V_32 = V_23 -> V_7 -> V_116 ( V_14 , V_55 , V_23 , V_87 , V_3 -> V_99 , V_80 , & V_88 ,
V_18 -> V_102 & V_103 ? V_117 : V_118 ) ;
if ( V_32 == 0 ) {
if ( V_89 )
F_53 ( V_20 , & V_72 , V_23 ) ;
F_15 ( V_14 , V_55 , V_18 , V_23 , V_88 , V_101 , false ) ;
} else {
if ( V_89 )
F_28 ( V_23 ) ;
}
V_36:
if ( V_20 )
F_37 ( V_20 ) ;
if ( V_87 )
V_86 -> V_119 ( V_31 , V_87 ) ;
if ( V_32 == - V_35 )
goto V_95;
return V_32 ;
}
static int F_70 ( struct V_14 * V_14 , struct V_15 * V_55 ,
struct V_22 * V_23 , unsigned long V_88 , T_1 V_120 ,
T_1 V_121 , T_4 V_122 , int V_21 )
{
struct V_82 * V_123 ;
struct V_17 * V_124 ;
unsigned char * V_125 = F_71 ( V_55 ) ;
V_124 = F_72 ( V_55 , V_120 , V_121 , V_21 , sizeof( * V_123 ) , V_122 ) ;
if ( ! V_124 )
goto V_126;
V_123 = F_61 ( V_124 ) ;
V_123 -> V_127 = V_128 ;
V_123 -> V_129 = 0 ;
V_123 -> V_130 = 0 ;
V_123 -> V_104 = F_73 ( V_23 -> V_31 ) -> V_131 ;
V_123 -> V_97 = V_23 -> V_38 ;
V_123 -> V_96 = F_17 ( V_23 -> V_27 , V_23 -> V_28 ) ;
if ( F_74 ( V_55 , V_100 , V_23 -> V_7 -> V_2 ) )
goto V_132;
if ( F_75 ( V_55 , V_111 , V_23 -> V_20 -> V_47 ) )
goto V_132;
V_123 -> V_99 = V_88 ;
if ( V_98 != V_21 ) {
V_123 -> V_99 = 0 ;
if ( V_23 -> V_7 -> V_133 && V_23 -> V_7 -> V_133 ( V_14 , V_23 , V_88 , V_55 , V_123 ) < 0 )
goto V_132;
}
V_124 -> V_134 = F_71 ( V_55 ) - V_125 ;
return V_55 -> V_135 ;
V_126:
V_132:
F_76 ( V_55 , V_125 ) ;
return - 1 ;
}
static int F_15 ( struct V_14 * V_14 , struct V_15 * V_16 ,
struct V_17 * V_18 , struct V_22 * V_23 ,
unsigned long V_88 , int V_21 , bool V_136 )
{
struct V_15 * V_55 ;
T_1 V_120 = V_16 ? F_77 ( V_16 ) . V_120 : 0 ;
V_55 = F_78 ( V_137 , V_33 ) ;
if ( ! V_55 )
return - V_34 ;
if ( F_70 ( V_14 , V_55 , V_23 , V_88 , V_120 , V_18 -> V_138 ,
V_18 -> V_102 , V_21 ) <= 0 ) {
F_79 ( V_55 ) ;
return - V_75 ;
}
if ( V_136 )
return F_80 ( V_14 -> V_139 , V_55 , V_120 , V_140 ) ;
return F_81 ( V_55 , V_14 , V_120 , V_141 ,
V_18 -> V_102 & V_142 ) ;
}
static int F_82 ( struct V_22 * V_23 , unsigned long V_18 ,
struct V_143 * V_144 )
{
struct V_145 * V_146 = ( void * ) V_144 ;
struct V_14 * V_14 = F_58 ( V_146 -> V_55 -> V_78 ) ;
return F_70 ( V_14 , V_146 -> V_55 , V_23 , V_18 , F_77 ( V_146 -> V_147 -> V_55 ) . V_120 ,
V_146 -> V_147 -> V_124 -> V_138 , V_148 ,
V_101 ) ;
}
static bool F_83 ( struct V_19 * V_20 , struct V_15 * V_55 ,
struct V_149 * V_147 ,
long V_150 , long * V_151 )
{
struct V_14 * V_14 = F_58 ( V_55 -> V_78 ) ;
struct V_82 * V_123 = F_61 ( V_147 -> V_124 ) ;
struct V_145 V_144 ;
struct V_22 * V_23 ;
for ( V_23 = F_14 ( V_20 -> V_24 ) ;
V_23 ; V_23 = F_14 ( V_23 -> V_25 ) , ( * V_151 ) ++ ) {
if ( * V_151 < V_150 )
continue;
if ( F_18 ( V_123 -> V_96 ) &&
F_18 ( V_123 -> V_96 ) != V_23 -> V_27 )
continue;
if ( F_62 ( V_123 -> V_96 ) &&
F_62 ( V_123 -> V_96 ) != V_23 -> V_28 )
continue;
if ( * V_151 > V_150 )
memset ( & V_147 -> args [ 1 ] , 0 ,
sizeof( V_147 -> args ) - sizeof( V_147 -> args [ 0 ] ) ) ;
if ( V_147 -> args [ 1 ] == 0 ) {
if ( F_70 ( V_14 , V_55 , V_23 , 0 ,
F_77 ( V_147 -> V_55 ) . V_120 ,
V_147 -> V_124 -> V_138 , V_148 ,
V_101 ) <= 0 )
return false ;
V_147 -> args [ 1 ] = 1 ;
}
if ( ! V_23 -> V_7 -> V_152 )
continue;
V_144 . V_153 . V_154 = F_82 ;
V_144 . V_55 = V_55 ;
V_144 . V_147 = V_147 ;
V_144 . V_153 . V_155 = 0 ;
V_144 . V_153 . V_156 = V_147 -> args [ 1 ] - 1 ;
V_144 . V_153 . V_157 = 0 ;
V_23 -> V_7 -> V_152 ( V_23 , & V_144 . V_153 ) ;
V_147 -> args [ 1 ] = V_144 . V_153 . V_157 + 1 ;
if ( V_144 . V_153 . V_155 )
return false ;
}
return true ;
}
static int F_84 ( struct V_15 * V_55 , struct V_149 * V_147 )
{
struct V_14 * V_14 = F_58 ( V_55 -> V_78 ) ;
struct V_79 * V_80 [ V_81 + 1 ] ;
struct V_83 * V_84 ;
struct V_30 * V_31 ;
struct V_42 * V_43 ;
struct V_19 * V_20 ;
struct V_82 * V_123 = F_61 ( V_147 -> V_124 ) ;
unsigned long V_87 = 0 ;
const struct V_85 * V_86 ;
long V_150 ;
long V_47 ;
int V_32 ;
if ( V_134 ( V_147 -> V_124 ) < sizeof( * V_123 ) )
return V_55 -> V_135 ;
V_32 = F_60 ( V_147 -> V_124 , sizeof( * V_123 ) , V_80 , V_81 , NULL , NULL ) ;
if ( V_32 )
return V_32 ;
V_84 = F_63 ( V_14 , V_123 -> V_104 ) ;
if ( ! V_84 )
return V_55 -> V_135 ;
if ( ! V_123 -> V_97 )
V_31 = V_84 -> V_106 ;
else
V_31 = F_64 ( V_84 , F_18 ( V_123 -> V_97 ) ) ;
if ( ! V_31 )
goto V_10;
V_86 = V_31 -> V_7 -> V_108 ;
if ( ! V_86 )
goto V_36;
if ( ! V_86 -> V_42 )
goto V_36;
if ( F_62 ( V_123 -> V_97 ) ) {
V_87 = V_86 -> V_110 ( V_31 , V_123 -> V_97 ) ;
if ( V_87 == 0 )
goto V_36;
}
V_43 = V_86 -> V_42 ( V_31 , V_87 ) ;
if ( ! V_43 )
goto V_36;
V_150 = V_147 -> args [ 0 ] ;
V_47 = 0 ;
F_3 (chain, &block->chain_list, list) {
if ( V_80 [ V_111 ] &&
F_65 ( V_80 [ V_111 ] ) != V_20 -> V_47 )
continue;
if ( ! F_83 ( V_20 , V_55 , V_147 , V_150 , & V_47 ) )
break;
}
V_147 -> args [ 0 ] = V_47 ;
V_36:
if ( V_87 )
V_86 -> V_119 ( V_31 , V_87 ) ;
V_10:
return V_55 -> V_135 ;
}
void F_85 ( struct V_158 * V_159 )
{
#ifdef F_45
F_86 ( V_160 ) ;
F_87 ( V_159 , & V_160 ) ;
F_88 ( & V_160 , V_161 ) ;
F_27 ( V_159 -> V_160 ) ;
V_159 -> V_162 = 0 ;
#endif
}
int F_89 ( struct V_14 * V_14 , struct V_22 * V_23 , struct V_79 * * V_163 ,
struct V_79 * V_164 , struct V_158 * V_159 , bool V_165 )
{
#ifdef F_45
{
struct V_166 * V_167 ;
if ( V_159 -> V_168 && V_163 [ V_159 -> V_168 ] ) {
V_167 = F_90 ( V_14 , V_23 , V_163 [ V_159 -> V_168 ] ,
V_164 , L_3 , V_165 ,
V_169 ) ;
if ( F_66 ( V_167 ) )
return F_67 ( V_167 ) ;
V_167 -> type = V_159 -> type = V_170 ;
V_159 -> V_160 [ 0 ] = V_167 ;
V_159 -> V_162 = 1 ;
} else if ( V_159 -> V_171 && V_163 [ V_159 -> V_171 ] ) {
F_86 ( V_160 ) ;
int V_32 , V_172 = 0 ;
V_32 = F_91 ( V_14 , V_23 , V_163 [ V_159 -> V_171 ] ,
V_164 , NULL , V_165 , V_169 ,
& V_160 ) ;
if ( V_32 )
return V_32 ;
F_3 (act, &actions, list)
V_159 -> V_160 [ V_172 ++ ] = V_167 ;
V_159 -> V_162 = V_172 ;
}
}
#else
if ( ( V_159 -> V_171 && V_163 [ V_159 -> V_171 ] ) ||
( V_159 -> V_168 && V_163 [ V_159 -> V_168 ] ) )
return - V_109 ;
#endif
return 0 ;
}
void F_92 ( struct V_22 * V_23 , struct V_158 * V_173 ,
struct V_158 * V_174 )
{
#ifdef F_45
struct V_158 V_175 = * V_173 ;
F_93 ( V_23 ) ;
V_173 -> V_162 = V_174 -> V_162 ;
V_173 -> V_160 = V_174 -> V_160 ;
V_173 -> type = V_174 -> type ;
F_94 ( V_23 ) ;
F_85 ( & V_175 ) ;
#endif
}
static struct V_166 * F_95 ( struct V_158 * V_159 )
{
if ( V_159 -> V_162 == 0 )
return NULL ;
else
return V_159 -> V_160 [ 0 ] ;
}
int F_96 ( struct V_15 * V_55 , struct V_158 * V_159 )
{
#ifdef F_45
struct V_79 * V_176 ;
if ( V_159 -> V_171 && V_159 -> V_162 ) {
if ( V_159 -> type != V_170 ) {
F_86 ( V_160 ) ;
V_176 = F_97 ( V_55 , V_159 -> V_171 ) ;
if ( V_176 == NULL )
goto V_132;
F_87 ( V_159 , & V_160 ) ;
if ( F_98 ( V_55 , & V_160 , 0 , 0 ) < 0 )
goto V_132;
F_99 ( V_55 , V_176 ) ;
} else if ( V_159 -> V_168 ) {
struct V_166 * V_167 = F_95 ( V_159 ) ;
V_176 = F_97 ( V_55 , V_159 -> V_168 ) ;
if ( V_176 == NULL || ! V_167 )
goto V_132;
if ( F_100 ( V_55 , V_167 , 0 , 0 ) < 0 )
goto V_132;
F_99 ( V_55 , V_176 ) ;
}
}
return 0 ;
V_132:
F_101 ( V_55 , V_176 ) ;
return - 1 ;
#else
return 0 ;
#endif
}
int F_102 ( struct V_15 * V_55 , struct V_158 * V_159 )
{
#ifdef F_45
struct V_166 * V_146 = F_95 ( V_159 ) ;
if ( V_146 != NULL && F_103 ( V_55 , V_146 , 1 ) < 0 )
return - 1 ;
#endif
return 0 ;
}
int F_104 ( struct V_83 * V_84 , struct V_158 * V_159 ,
struct V_83 * * V_177 )
{
#ifdef F_45
const struct V_166 * V_146 ;
F_86 ( V_160 ) ;
if ( F_105 ( V_159 ) )
return - V_75 ;
F_87 ( V_159 , & V_160 ) ;
F_3 (a, &actions, list) {
if ( V_146 -> V_7 -> V_178 ) {
V_146 -> V_7 -> V_178 ( V_146 , F_106 ( V_84 ) , V_177 ) ;
break;
}
}
if ( * V_177 )
return 0 ;
#endif
return - V_109 ;
}
static int T_5 F_107 ( void )
{
F_108 ( V_179 , V_101 , F_57 , NULL , NULL ) ;
F_108 ( V_179 , V_98 , F_57 , NULL , NULL ) ;
F_108 ( V_179 , V_91 , F_57 ,
F_84 , NULL ) ;
return 0 ;
}
