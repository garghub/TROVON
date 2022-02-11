static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
if ( V_4 -> V_6 == V_5 )
return;
V_4 -> V_6 = V_5 ;
V_2 -> V_7 . V_8 += ( V_5 ? 1 : - 1 ) ;
V_4 -> V_9 -> V_10 -> V_11 = ! V_5 ;
}
static int F_2 ( struct V_1 * V_2 , const struct V_12 * V_13 ,
int V_5 )
{
struct V_3 * V_4 = NULL ;
struct V_14 * V_15 ;
T_1 V_16 ;
int V_17 = 0 ;
F_3 ( V_18 , L_1 ,
V_2 , V_13 -> V_13 , V_5 ) ;
F_4 ( & V_2 -> V_19 ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_7 . V_20 ; V_16 ++ ) {
V_4 = V_2 -> V_21 [ V_16 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
continue;
F_3 ( V_18 , L_2 , V_16 ,
V_4 -> V_22 . V_13 , V_4 -> V_9 -> V_23 . V_24 ) ;
if ( F_5 ( V_13 , & V_4 -> V_22 ) )
break;
}
if ( V_16 == V_2 -> V_7 . V_20 ) {
V_17 = - V_25 ;
goto V_26;
}
V_15 = F_6 ( V_4 -> V_9 ) ;
if ( ! V_15 ) {
V_17 = - V_27 ;
goto V_26;
}
F_3 ( V_18 , L_3 ,
V_15 -> V_28 , V_15 -> V_12 . V_13 , V_15 -> V_29 , V_15 ,
V_15 -> V_30 -> V_31 , V_16 ) ;
F_7 ( strcmp ( V_15 -> V_30 -> V_31 , V_32 ) == 0 ) ;
if ( V_4 -> V_6 == V_5 ) {
F_3 ( V_18 , L_4 , V_15 ,
V_5 ? L_5 : L_6 ) ;
goto V_26;
}
F_3 ( V_18 , L_7 , V_15 ,
V_5 ? L_5 : L_6 ) ;
F_1 ( V_2 , V_4 , V_5 ) ;
V_26:
F_8 ( & V_2 -> V_19 ) ;
return V_17 ;
}
static struct V_12 * F_9 ( struct V_33 * exp )
{
struct V_1 * V_2 = & exp -> V_10 -> V_34 . V_2 ;
struct V_3 * V_4 = V_2 -> V_21 [ 0 ] ;
return V_4 ? F_10 ( V_4 -> V_9 ) : NULL ;
}
static int F_11 ( struct V_14 * V_15 , struct V_14 * V_35 ,
enum V_36 V_37 , void * V_38 )
{
struct V_39 * V_40 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_12 * V_13 ;
int V_17 = 0 ;
if ( strcmp ( V_35 -> V_30 -> V_31 , V_32 ) ) {
F_12 ( L_8 ,
V_35 -> V_30 -> V_31 ,
V_35 -> V_28 ) ;
return - V_25 ;
}
V_13 = & V_35 -> V_34 . V_41 . V_42 ;
if ( V_37 == V_43 || V_37 == V_44 ) {
V_17 = F_2 ( V_2 , V_13 ,
V_37 == V_43 ) ;
if ( V_17 ) {
F_12 ( L_9 ,
V_37 == V_43 ? L_5 : L_10 ,
V_13 -> V_13 , V_17 ) ;
return V_17 ;
}
} else if ( V_37 == V_45 ) {
V_40 = & V_35 -> V_34 . V_41 . V_46 -> V_47 ;
V_15 -> V_48 -> V_49 = * V_40 ;
}
if ( V_15 -> V_50 )
V_17 = F_13 ( V_15 -> V_50 , V_35 , V_37 , V_38 ) ;
return V_17 ;
}
static int F_14 ( const struct V_51 * V_52 ,
struct V_33 * * V_53 , struct V_14 * V_15 ,
struct V_12 * V_54 , struct V_39 * V_38 ,
void * V_55 )
{
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_56 V_57 = { 0 } ;
struct V_33 * exp ;
int V_17 = 0 ;
V_17 = F_15 ( & V_57 , V_15 , V_54 ) ;
if ( V_17 ) {
F_12 ( L_11 , V_17 ) ;
return V_17 ;
}
exp = F_16 ( & V_57 ) ;
V_2 -> V_58 = 0 ;
V_2 -> V_54 = * V_54 ;
V_2 -> V_40 = * V_38 ;
V_2 -> V_59 = F_17 ( L_12 ,
& V_15 -> V_60 ) ;
V_17 = F_18 ( V_15 ) ;
if ( V_17 )
goto V_61;
* V_53 = exp ;
return V_17 ;
V_61:
if ( V_2 -> V_59 )
F_19 ( V_2 -> V_59 ) ;
F_20 ( exp ) ;
return V_17 ;
}
static int F_21 ( struct V_33 * exp , T_1 V_62 , T_1 V_63 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
T_1 V_16 ;
int V_17 = 0 ;
int V_64 = 0 ;
if ( V_2 -> V_65 < V_62 ) {
V_2 -> V_65 = V_62 ;
V_64 = 1 ;
}
if ( V_2 -> V_66 < V_63 ) {
V_2 -> V_66 = V_63 ;
V_64 = 1 ;
}
if ( V_64 == 0 )
return 0 ;
if ( V_2 -> V_58 == 0 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_7 . V_20 ; V_16 ++ ) {
struct V_3 * V_4 = V_2 -> V_21 [ V_16 ] ;
if ( ! V_4 || ! V_4 -> V_9 || ! V_4 -> V_6 ) {
F_22 ( L_13 , V_15 -> V_28 , V_16 ) ;
continue;
}
V_17 = F_23 ( V_4 -> V_9 , V_62 , V_63 ) ;
if ( V_17 ) {
F_12 ( L_14 ,
V_15 -> V_28 , V_16 , V_17 ) ;
break;
}
}
return V_17 ;
}
static int F_24 ( struct V_14 * V_15 , struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_12 * V_54 = & V_2 -> V_54 ;
struct V_12 V_67 = { L_15 } ;
struct V_14 * V_68 ;
struct V_33 * V_69 ;
struct V_70 V_71 ;
int V_17 ;
V_68 = F_25 ( & V_4 -> V_22 , V_32 ,
& V_15 -> V_12 ) ;
if ( ! V_68 ) {
F_12 ( L_16 , V_4 -> V_22 . V_13 ) ;
return - V_25 ;
}
F_3 ( V_72 , L_17 ,
V_68 -> V_28 , V_68 -> V_12 . V_13 ,
V_4 -> V_22 . V_13 , V_15 -> V_12 . V_13 , V_54 -> V_13 ) ;
if ( ! V_68 -> V_73 ) {
F_12 ( L_18 , V_4 -> V_22 . V_13 ) ;
return - V_25 ;
}
V_17 = F_26 ( NULL , & V_69 , V_68 , & V_67 ,
& V_2 -> V_40 , NULL ) ;
if ( V_17 ) {
F_12 ( L_19 , V_4 -> V_22 . V_13 , V_17 ) ;
return V_17 ;
}
V_17 = F_27 ( V_68 , V_69 , V_74 ) ;
if ( V_17 )
return V_17 ;
V_71 . V_75 = NULL ;
V_71 . V_76 = V_69 ;
V_71 . V_77 = V_4 -> V_78 ;
F_28 ( & V_2 -> V_79 , & V_71 ) ;
V_17 = F_29 ( V_68 , V_15 ) ;
if ( V_17 ) {
F_30 ( V_69 ) ;
F_12 ( L_20 ,
V_4 -> V_22 . V_13 , V_17 ) ;
return V_17 ;
}
if ( V_15 -> V_50 ) {
V_17 = F_13 ( V_15 -> V_50 , V_69 -> V_10 ,
V_43 ,
( void * ) ( V_4 - V_2 -> V_21 [ 0 ] ) ) ;
if ( V_17 ) {
F_30 ( V_69 ) ;
return V_17 ;
}
}
V_4 -> V_6 = 1 ;
V_4 -> V_9 = V_69 ;
V_2 -> V_7 . V_8 ++ ;
F_23 ( V_4 -> V_9 , V_2 -> V_65 , V_2 -> V_66 ) ;
F_3 ( V_72 , L_21 ,
V_68 -> V_28 , V_68 -> V_12 . V_13 ,
F_31 ( & V_15 -> V_80 ) ) ;
if ( V_2 -> V_59 )
V_17 = F_32 ( V_2 -> V_59 , & V_68 -> V_60 ,
V_68 -> V_28 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 , int V_81 )
{
if ( ! V_2 -> V_21 [ V_81 ] )
return;
F_34 ( V_2 -> V_21 [ V_81 ] ) ;
V_2 -> V_21 [ V_81 ] = NULL ;
}
static int F_35 ( struct V_14 * V_15 , struct V_12 * V_82 ,
T_2 V_81 , int V_83 )
{
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_14 * V_68 ;
struct V_3 * V_4 ;
int V_84 = 0 ;
int V_17 = 0 ;
F_3 ( V_72 , L_22 , V_82 -> V_13 , V_81 ) ;
V_68 = F_25 ( V_82 , V_32 ,
& V_15 -> V_12 ) ;
if ( ! V_68 ) {
F_12 ( L_23 ,
V_15 -> V_28 , V_82 -> V_13 , - V_25 ) ;
return - V_25 ;
}
F_36 ( & V_2 -> V_85 ) ;
if ( ( V_81 < V_2 -> V_86 ) && V_2 -> V_21 [ V_81 ] ) {
V_4 = V_2 -> V_21 [ V_81 ] ;
F_12 ( L_24 ,
V_15 -> V_28 ,
F_37 ( & V_4 -> V_22 ) , V_81 , - V_87 ) ;
F_38 ( & V_2 -> V_85 ) ;
return - V_87 ;
}
if ( V_81 >= V_2 -> V_86 ) {
struct V_3 * * V_88 , * * V_89 = NULL ;
T_2 V_90 = 1 ;
T_2 V_91 = 0 ;
while ( V_90 < V_81 + 1 )
V_90 <<= 1 ;
V_88 = F_39 ( V_90 , sizeof( * V_88 ) , V_92 ) ;
if ( ! V_88 ) {
F_38 ( & V_2 -> V_85 ) ;
return - V_93 ;
}
if ( V_2 -> V_86 ) {
memcpy ( V_88 , V_2 -> V_21 ,
sizeof( * V_88 ) * V_2 -> V_86 ) ;
V_89 = V_2 -> V_21 ;
V_91 = V_2 -> V_86 ;
}
V_2 -> V_21 = V_88 ;
V_2 -> V_86 = V_90 ;
F_40 () ;
F_34 ( V_89 ) ;
F_3 ( V_72 , L_25 , V_2 -> V_21 ,
V_2 -> V_86 ) ;
}
V_4 = F_41 ( sizeof( * V_4 ) , V_92 ) ;
if ( ! V_4 ) {
F_38 ( & V_2 -> V_85 ) ;
return - V_93 ;
}
F_42 ( & V_4 -> V_94 ) ;
V_4 -> V_78 = V_81 ;
V_4 -> V_22 = * V_82 ;
V_4 -> V_6 = 0 ;
V_2 -> V_21 [ V_81 ] = V_4 ;
if ( V_81 >= V_2 -> V_7 . V_20 ) {
V_84 = V_2 -> V_7 . V_20 ;
V_2 -> V_7 . V_20 = V_81 + 1 ;
}
if ( ! V_2 -> V_58 ) {
F_38 ( & V_2 -> V_85 ) ;
return V_17 ;
}
F_38 ( & V_2 -> V_85 ) ;
V_17 = F_24 ( V_15 , V_4 ) ;
if ( V_17 ) {
F_4 ( & V_2 -> V_19 ) ;
if ( V_2 -> V_7 . V_20 == V_81 + 1 )
V_2 -> V_7 . V_20 = V_84 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_8 ( & V_2 -> V_19 ) ;
} else {
int V_62 = sizeof( struct V_95 ) +
V_2 -> V_7 . V_20 * sizeof( struct V_96 ) ;
F_21 ( V_15 -> V_48 , V_62 , 0 ) ;
}
return V_17 ;
}
static int F_18 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
T_1 V_16 ;
int V_17 ;
int V_62 ;
if ( V_2 -> V_58 )
return 0 ;
F_36 ( & V_2 -> V_85 ) ;
if ( V_2 -> V_58 ) {
F_38 ( & V_2 -> V_85 ) ;
return 0 ;
}
if ( V_2 -> V_7 . V_20 == 0 ) {
F_38 ( & V_2 -> V_85 ) ;
F_12 ( L_26 , V_15 -> V_28 ) ;
return - V_25 ;
}
F_7 ( V_2 -> V_21 ) ;
if ( ! V_2 -> V_21 [ 0 ] ) {
F_38 ( & V_2 -> V_85 ) ;
F_12 ( L_27 ,
V_15 -> V_28 ) ;
return - V_25 ;
}
F_3 ( V_72 , L_28 ,
V_2 -> V_54 . V_13 , V_15 -> V_28 ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_7 . V_20 ; V_16 ++ ) {
V_4 = V_2 -> V_21 [ V_16 ] ;
if ( ! V_4 )
continue;
V_17 = F_24 ( V_15 , V_4 ) ;
if ( V_17 )
goto V_97;
}
V_2 -> V_58 = 1 ;
V_62 = F_43 ( V_2 -> V_7 . V_20 , V_98 ) ;
F_21 ( V_15 -> V_48 , V_62 , 0 ) ;
F_38 ( & V_2 -> V_85 ) ;
return 0 ;
V_97:
while ( V_16 -- > 0 ) {
int V_99 ;
V_4 = V_2 -> V_21 [ V_16 ] ;
if ( ! V_4 )
continue;
V_4 -> V_6 = 0 ;
if ( V_4 -> V_9 ) {
-- V_2 -> V_7 . V_8 ;
V_99 = F_30 ( V_4 -> V_9 ) ;
if ( V_99 ) {
F_12 ( L_29 ,
V_4 -> V_22 . V_13 , V_16 , V_99 ) ;
}
}
}
F_38 ( & V_2 -> V_85 ) ;
return V_17 ;
}
static int F_44 ( struct V_14 * V_15 , struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_14 * V_68 ;
int V_17 ;
V_68 = F_6 ( V_4 -> V_9 ) ;
if ( V_68 ) {
V_68 -> V_100 = V_15 -> V_100 ;
V_68 -> V_101 = V_15 -> V_101 ;
V_68 -> V_102 = V_15 -> V_102 ;
if ( V_2 -> V_59 )
F_45 ( V_2 -> V_59 ,
V_68 -> V_28 ) ;
}
V_17 = F_46 ( V_4 -> V_9 -> V_10 ) ;
if ( V_17 )
F_12 ( L_30 ) ;
F_3 ( V_18 , L_31 ,
V_4 -> V_9 -> V_10 -> V_28 ,
V_4 -> V_9 -> V_10 -> V_12 . V_13 ) ;
F_29 ( V_4 -> V_9 -> V_10 , NULL ) ;
V_17 = F_30 ( V_4 -> V_9 ) ;
if ( V_17 ) {
if ( V_4 -> V_6 ) {
F_12 ( L_32 ,
V_4 -> V_22 . V_13 , V_17 ) ;
}
}
F_1 ( V_2 , V_4 , 0 ) ;
V_4 -> V_9 = NULL ;
return 0 ;
}
static int F_47 ( struct V_33 * exp )
{
struct V_14 * V_15 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
int V_17 ;
T_1 V_16 ;
if ( ! V_2 -> V_21 )
goto V_103;
for ( V_16 = 0 ; V_16 < V_2 -> V_7 . V_20 ; V_16 ++ ) {
if ( ! V_2 -> V_21 [ V_16 ] || ! V_2 -> V_21 [ V_16 ] -> V_9 )
continue;
F_44 ( V_15 , V_2 -> V_21 [ V_16 ] ) ;
}
if ( V_2 -> V_59 )
F_19 ( V_2 -> V_59 ) ;
V_103:
if ( ! V_2 -> V_58 )
F_48 ( exp ) ;
V_17 = F_20 ( exp ) ;
V_2 -> V_58 = 0 ;
return V_17 ;
}
static int F_49 ( struct V_33 * exp , int V_104 , void * V_105 ,
void T_3 * V_106 )
{
struct V_14 * V_107 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_107 -> V_34 . V_2 ;
struct V_108 * V_109 ;
struct V_3 * V_4 ;
struct V_108 * V_110 = NULL ;
int V_111 = 0 ;
int V_17 ;
V_109 = V_105 ;
V_4 = F_50 ( V_2 , & V_109 -> V_112 ) ;
if ( F_51 ( V_4 ) )
return F_52 ( V_4 ) ;
V_113:
V_17 = F_53 ( V_114 , V_4 -> V_9 , V_104 , V_109 , V_106 ) ;
if ( V_17 != 0 && V_17 != - V_115 )
goto V_116;
if ( V_110 ) {
struct V_108 * V_117 ;
char * V_118 ;
V_117 = V_105 ;
if ( strlen ( V_117 -> V_119 ) + 1 +
strlen ( V_109 -> V_119 ) + 1 > V_117 -> V_120 ) {
V_17 = - V_121 ;
goto V_116;
}
V_118 = V_117 -> V_119 ;
memmove ( V_118 + strlen ( V_109 -> V_119 ) + 1 , V_118 ,
strlen ( V_117 -> V_119 ) ) ;
strncpy ( V_118 , V_109 -> V_119 , strlen ( V_109 -> V_119 ) ) ;
V_118 += strlen ( V_109 -> V_119 ) ;
* V_118 = '/' ;
}
F_3 ( V_18 , L_33 V_122 L_34 ,
V_4 -> V_9 -> V_10 -> V_28 ,
V_109 -> V_119 , F_54 ( & V_109 -> V_112 ) , V_109 -> V_123 ,
V_109 -> V_124 ) ;
if ( V_17 == 0 )
goto V_116;
if ( ! V_110 ) {
V_111 = sizeof( * V_110 ) + V_125 ;
V_110 = F_41 ( V_111 , V_92 ) ;
if ( ! V_110 ) {
V_17 = - V_93 ;
goto V_116;
}
V_110 -> V_120 = V_125 ;
}
if ( ! F_55 ( & V_109 -> V_112 ) ) {
F_12 ( L_35 V_122 L_36 ,
V_4 -> V_9 -> V_10 -> V_28 ,
F_54 ( & V_109 -> V_112 ) , - V_25 ) ;
V_17 = - V_25 ;
goto V_116;
}
V_4 = F_50 ( V_2 , & V_109 -> V_112 ) ;
if ( F_51 ( V_4 ) ) {
V_17 = - V_25 ;
goto V_116;
}
V_110 -> V_112 = V_109 -> V_112 ;
V_110 -> V_123 = - 1 ;
V_110 -> V_124 = - 1 ;
memset ( V_110 -> V_119 , 0 , V_110 -> V_120 ) ;
V_109 = V_110 ;
goto V_113;
V_116:
F_34 ( V_110 ) ;
return V_17 ;
}
static int F_56 ( struct V_1 * V_2 ,
const struct V_126 * V_127 ,
const struct V_3 * V_128 )
{
T_1 V_16 , V_129 = 0 ;
struct V_3 * V_130 ;
for ( V_16 = 0 ; V_16 < V_127 -> V_131 . V_132 ; V_16 ++ ) {
V_130 = F_50 ( V_2 , & V_127 -> V_133 [ V_16 ] . V_134 ) ;
if ( F_51 ( V_130 ) )
return F_52 ( V_130 ) ;
if ( F_5 ( & V_130 -> V_22 , & V_128 -> V_22 ) )
V_129 ++ ;
}
return V_129 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_126 * V_135 ,
const struct V_3 * V_128 ,
struct V_126 * V_136 )
{
int V_16 , V_137 ;
struct V_3 * V_130 ;
V_136 -> V_131 = V_135 -> V_131 ;
V_137 = 0 ;
for ( V_16 = 0 ; V_16 < V_135 -> V_131 . V_132 ; V_16 ++ ) {
V_130 = F_50 ( V_2 ,
& V_135 -> V_133 [ V_16 ] . V_134 ) ;
if ( F_51 ( V_130 ) )
return F_52 ( V_130 ) ;
if ( F_5 ( & V_130 -> V_22 , & V_128 -> V_22 ) ) {
V_136 -> V_133 [ V_137 ] =
V_135 -> V_133 [ V_16 ] ;
V_137 ++ ;
}
}
V_136 -> V_131 . V_132 = V_137 ;
memcpy ( F_58 ( V_136 ) , F_58 ( V_135 ) ,
V_135 -> V_131 . V_138 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , unsigned int V_139 , int V_104 ,
struct V_140 * V_141 ,
void T_3 * V_106 )
{
T_2 V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_7 . V_20 ; V_16 ++ ) {
struct V_3 * V_4 = V_2 -> V_21 [ V_16 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
continue;
F_53 ( V_139 , V_2 -> V_21 [ V_16 ] -> V_9 , V_104 , V_141 , V_106 ) ;
}
return F_60 ( V_141 -> V_142 , V_141 -> V_143 ) ;
}
static int F_61 ( struct V_1 * V_2 , unsigned int V_139 , int V_104 ,
struct V_140 * V_141 , void T_3 * V_106 )
{
struct V_144 * V_145 ;
T_2 V_16 , V_146 ;
int V_147 , V_17 = 0 ;
bool V_148 = false ;
struct V_149 V_150 = { 0 } ;
for ( V_16 = 0 ; V_16 < V_2 -> V_7 . V_20 ; V_16 ++ ) {
struct V_3 * V_4 = V_2 -> V_21 [ V_16 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
continue;
V_147 = F_53 ( V_139 , V_4 -> V_9 , V_104 , V_141 , V_106 ) ;
if ( V_147 ) {
if ( V_4 -> V_6 ) {
F_12 ( L_37 ,
V_4 -> V_22 . V_13 , V_16 , V_139 , V_147 ) ;
V_17 = V_147 ;
V_141 -> V_151 |= V_152 ;
for ( V_146 = 0 ; V_146 < V_16 ; V_146 ++ ) {
V_4 = V_2 -> V_21 [ V_146 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
continue;
F_53 ( V_139 , V_4 -> V_9 , V_104 ,
V_141 , V_106 ) ;
}
return V_17 ;
}
} else {
V_148 = true ;
}
}
if ( ! V_148 )
return - V_27 ;
V_145 = F_62 ( V_141 -> V_153 ) ;
if ( ! V_145 )
return - V_154 ;
V_150 . V_155 = V_156 ;
V_150 . V_157 = V_2 -> V_54 ;
V_150 . V_158 = V_141 -> V_159 ;
V_17 = F_63 ( V_145 , V_141 -> V_142 , V_141 -> V_143 ,
& V_150 , sizeof( V_150 ) ) ;
if ( V_17 )
F_64 ( V_145 ) ;
return V_17 ;
}
static int F_65 ( unsigned int V_139 , struct V_33 * exp ,
int V_104 , void * V_105 , void T_3 * V_106 )
{
struct V_14 * V_107 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_107 -> V_34 . V_2 ;
struct V_3 * V_4 = NULL ;
T_1 V_16 = 0 ;
int V_17 = 0 ;
int V_160 = 0 ;
T_1 V_161 = V_2 -> V_7 . V_20 ;
if ( V_161 == 0 )
return - V_162 ;
switch ( V_139 ) {
case V_163 : {
struct V_164 * V_38 = V_105 ;
struct V_14 * V_68 ;
struct V_165 V_166 = { 0 } ;
T_2 V_81 ;
memcpy ( & V_81 , V_38 -> V_167 , sizeof( T_2 ) ) ;
if ( V_81 >= V_161 )
return - V_168 ;
V_4 = V_2 -> V_21 [ V_81 ] ;
if ( ! V_4 || ! V_4 -> V_6 )
return - V_169 ;
V_68 = F_6 ( V_4 -> V_9 ) ;
if ( ! V_68 )
return - V_25 ;
if ( F_66 ( V_38 -> V_170 , F_67 ( V_68 ) ,
F_68 ( ( int ) V_38 -> V_171 ,
( int ) sizeof( struct V_12 ) ) ) )
return - V_172 ;
V_17 = V_165 ( NULL , V_4 -> V_9 , & V_166 ,
F_69 ( - V_173 ) ,
0 ) ;
if ( V_17 )
return V_17 ;
if ( F_66 ( V_38 -> V_174 , & V_166 ,
F_68 ( ( int ) V_38 -> V_175 ,
( int ) sizeof( V_166 ) ) ) )
return - V_172 ;
break;
}
case V_176 : {
struct V_177 * V_178 = V_105 ;
struct V_179 * V_180 ;
if ( V_178 -> V_181 == V_182 ) {
if ( V_161 <= V_178 -> V_183 )
return - V_25 ;
V_4 = V_2 -> V_21 [ V_178 -> V_183 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
return - V_25 ;
} else if ( V_178 -> V_181 == V_184 ) {
for ( V_16 = 0 ; V_16 < V_161 ; V_16 ++ ) {
V_4 = V_2 -> V_21 [ V_16 ] ;
if ( ! V_4 )
continue;
if ( ! F_5 ( & V_4 -> V_22 ,
& V_178 -> V_12 ) )
continue;
if ( ! V_4 -> V_9 )
return - V_25 ;
break;
}
} else {
return - V_25 ;
}
if ( V_16 >= V_161 )
return - V_185 ;
F_7 ( V_4 && V_4 -> V_9 ) ;
V_180 = F_41 ( sizeof( * V_180 ) , V_92 ) ;
if ( ! V_180 )
return - V_93 ;
F_70 ( V_180 , V_178 ) ;
V_17 = V_179 ( V_4 -> V_9 , V_180 ) ;
if ( V_17 == 0 ) {
F_70 ( V_178 , V_180 ) ;
V_178 -> V_181 = V_182 ;
V_178 -> V_12 = V_4 -> V_22 ;
}
F_34 ( V_180 ) ;
break;
}
case V_186 :
case V_187 : {
struct V_188 * V_189 = V_105 ;
if ( V_189 -> V_190 >= V_161 )
return - V_168 ;
V_4 = V_2 -> V_21 [ V_189 -> V_190 ] ;
if ( ! V_4 || ! V_4 -> V_9 || ! V_4 -> V_6 )
return - V_168 ;
V_17 = F_53 ( V_139 , V_4 -> V_9 , sizeof( * V_189 ) , V_189 , NULL ) ;
break;
}
case V_191 : {
V_4 = V_2 -> V_21 [ 0 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
return - V_169 ;
V_17 = F_53 ( V_139 , V_4 -> V_9 , V_104 , V_105 , V_106 ) ;
break;
}
case V_192 : {
struct V_96 * V_193 = V_105 ;
int V_194 ;
V_17 = F_71 ( V_2 , V_193 , & V_194 ) ;
if ( V_17 )
return V_17 ;
* ( T_2 * ) V_106 = V_194 ;
break;
}
case V_114 : {
V_17 = F_49 ( exp , V_104 , V_105 , V_106 ) ;
break;
}
case V_195 :
case V_196 :
case V_197 : {
struct V_198 * V_199 = V_105 ;
V_4 = F_50 ( V_2 , & V_199 -> V_200 ) ;
if ( F_51 ( V_4 ) )
return F_52 ( V_4 ) ;
if ( ! V_4 -> V_9 )
return - V_25 ;
V_17 = F_53 ( V_139 , V_4 -> V_9 , V_104 , V_105 , V_106 ) ;
break;
}
case V_201 : {
const struct V_202 * V_203 = V_105 ;
V_4 = F_50 ( V_2 , & V_203 -> V_204 ) ;
if ( F_51 ( V_4 ) )
return F_52 ( V_4 ) ;
V_17 = F_53 ( V_139 , V_4 -> V_9 , V_104 , V_105 , V_106 ) ;
break;
}
case V_205 : {
struct V_126 * V_127 = V_105 ;
unsigned int V_206 = V_127 -> V_131 . V_132 ;
if ( V_206 == 0 )
return 0 ;
if ( V_206 == 1 || V_161 == 1 ) {
V_4 = F_50 ( V_2 ,
& V_127 -> V_133 [ 0 ] . V_134 ) ;
if ( F_51 ( V_4 ) )
return F_52 ( V_4 ) ;
V_17 = F_53 ( V_139 , V_4 -> V_9 , V_104 , V_105 , V_106 ) ;
} else {
for ( V_16 = 0 ; V_16 < V_161 ; V_16 ++ ) {
struct V_126 * V_207 ;
T_4 V_208 ;
int V_129 , V_209 ;
V_4 = V_2 -> V_21 [ V_16 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
continue;
V_129 = F_56 ( V_2 , V_127 , V_4 ) ;
if ( V_129 < 0 )
return V_129 ;
if ( V_129 == 0 )
continue;
V_208 = F_72 ( F_73 ( * V_127 ) ,
V_133 [ V_129 ] )
+ V_127 -> V_131 . V_138 ;
V_207 = F_74 ( V_208 , V_92 ) ;
if ( ! V_207 )
return - V_93 ;
V_209 = F_57 ( V_2 , V_127 , V_4 , V_207 ) ;
if ( V_209 < 0 )
goto V_210;
V_209 = F_53 ( V_139 , V_4 -> V_9 , V_208 ,
V_207 , V_106 ) ;
V_210:
if ( V_209 != 0 && V_17 == 0 )
V_17 = V_209 ;
F_75 ( V_207 ) ;
}
}
break;
}
case V_211 : {
struct V_198 * V_199 = V_105 ;
struct V_3 * V_212 , * V_213 ;
V_212 = F_50 ( V_2 , & V_199 -> V_200 ) ;
if ( F_51 ( V_212 ) )
return F_52 ( V_212 ) ;
V_213 = F_50 ( V_2 , & V_199 -> V_214 ) ;
if ( F_51 ( V_213 ) )
return F_52 ( V_213 ) ;
if ( ! V_212 -> V_9 || ! V_213 -> V_9 )
return - V_25 ;
if ( V_212 -> V_78 != V_213 -> V_78 )
return - V_215 ;
V_17 = F_53 ( V_139 , V_212 -> V_9 , V_104 , V_105 , V_106 ) ;
break;
}
case V_216 : {
struct V_140 * V_141 = V_105 ;
if ( V_141 -> V_151 & V_152 )
V_17 = F_59 ( V_2 , V_139 , V_104 , V_141 , V_106 ) ;
else
V_17 = F_61 ( V_2 , V_139 , V_104 , V_141 , V_106 ) ;
break;
}
default:
for ( V_16 = 0 ; V_16 < V_161 ; V_16 ++ ) {
struct V_14 * V_68 ;
int V_147 ;
V_4 = V_2 -> V_21 [ V_16 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
continue;
V_68 = F_6 ( V_4 -> V_9 ) ;
V_68 -> V_100 = V_107 -> V_100 ;
V_147 = F_53 ( V_139 , V_4 -> V_9 , V_104 , V_105 , V_106 ) ;
if ( V_147 ) {
if ( V_4 -> V_6 ) {
F_12 ( L_38 ,
F_76 ( V_2 ) -> V_28 ,
V_4 -> V_22 . V_13 , V_16 , V_139 , V_147 ) ;
if ( ! V_17 )
V_17 = V_147 ;
}
} else {
V_160 = 1 ;
}
}
if ( ! V_160 && ! V_17 )
V_17 = - V_217 ;
}
return V_17 ;
}
static int F_77 ( struct V_14 * V_15 ,
struct V_198 * V_199 , T_1 * V_218 )
{
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
F_7 ( V_218 ) ;
if ( V_2 -> V_7 . V_20 == 1 ) {
* V_218 = 0 ;
return 0 ;
}
if ( V_199 -> V_219 != - 1 ) {
* V_218 = V_199 -> V_219 ;
return 0 ;
}
if ( V_199 -> V_220 & V_221 && V_199 -> V_199 ) {
struct V_222 * V_223 ;
V_223 = V_199 -> V_199 ;
if ( F_78 ( V_223 -> V_224 ) != ( T_2 ) - 1 ) {
* V_218 = F_78 ( V_223 -> V_224 ) ;
} else {
* V_218 = V_199 -> V_225 ;
V_223 -> V_224 = F_79 ( V_199 -> V_225 ) ;
}
} else {
* V_218 = V_199 -> V_225 ;
}
return 0 ;
}
int F_80 ( struct V_1 * V_2 , struct V_96 * V_193 , T_1 V_218 )
{
struct V_3 * V_4 ;
int V_17 ;
V_4 = F_81 ( V_2 , V_218 , NULL ) ;
if ( F_51 ( V_4 ) )
return F_52 ( V_4 ) ;
F_36 ( & V_4 -> V_94 ) ;
if ( V_4 -> V_6 == 0 || ! V_4 -> V_9 ) {
V_17 = - V_168 ;
goto V_226;
}
V_17 = F_82 ( NULL , V_4 -> V_9 , V_193 , NULL ) ;
if ( V_17 > 0 ) {
F_7 ( F_55 ( V_193 ) ) ;
V_17 = 0 ;
}
V_226:
F_38 ( & V_4 -> V_94 ) ;
return V_17 ;
}
int F_83 ( const struct V_51 * V_52 , struct V_33 * exp ,
struct V_96 * V_193 , struct V_198 * V_199 )
{
struct V_14 * V_15 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
T_1 V_218 = 0 ;
int V_17 ;
F_7 ( V_199 ) ;
F_7 ( V_193 ) ;
V_17 = F_77 ( V_15 , V_199 , & V_218 ) ;
if ( V_17 ) {
F_12 ( L_39 ,
V_17 ) ;
return V_17 ;
}
V_17 = F_80 ( V_2 , V_193 , V_218 ) ;
if ( V_17 ) {
F_12 ( L_40 , V_17 ) ;
return V_17 ;
}
return V_17 ;
}
static int F_84 ( struct V_14 * V_15 , struct V_227 * V_228 )
{
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_229 V_230 = { NULL } ;
struct V_231 * V_7 ;
int V_17 ;
if ( F_85 ( V_228 , 1 ) < 1 ) {
F_12 ( L_41 ) ;
return - V_25 ;
}
V_7 = (struct V_231 * ) F_86 ( V_228 , 1 ) ;
if ( sizeof( * V_7 ) > F_85 ( V_228 , 1 ) ) {
F_12 ( L_42 ,
( int ) sizeof( * V_7 ) , F_85 ( V_228 , 1 ) ) ;
return - V_25 ;
}
V_2 -> V_86 = 32U ;
V_2 -> V_21 = F_39 ( V_2 -> V_86 , sizeof( * V_2 -> V_21 ) , V_92 ) ;
if ( ! V_2 -> V_21 )
return - V_93 ;
F_87 ( & V_2 -> V_7 . V_232 , V_7 -> V_232 . V_13 ) ;
V_2 -> V_7 . V_20 = 0 ;
V_2 -> V_7 . V_8 = 0 ;
V_2 -> V_66 = 0 ;
V_2 -> V_65 = 0 ;
F_88 ( & V_2 -> V_19 ) ;
F_42 ( & V_2 -> V_85 ) ;
F_89 ( & V_230 ) ;
F_90 ( V_15 , V_230 . V_233 , V_230 . V_234 ) ;
V_17 = F_91 ( V_15 -> V_235 , L_43 ,
0444 , & V_236 , V_15 ) ;
if ( V_17 )
F_22 ( L_44 ,
V_15 -> V_28 , V_17 ) ;
V_17 = F_92 ( & V_2 -> V_79 , V_15 -> V_28 ,
V_237 ) ;
if ( V_17 ) {
F_12 ( L_45 , V_17 ) ;
goto V_226;
}
return 0 ;
V_226:
return V_17 ;
}
static int F_93 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
F_94 ( & V_2 -> V_79 ) ;
if ( V_2 -> V_21 ) {
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_7 . V_20 ; V_16 ++ ) {
if ( ! V_2 -> V_21 [ V_16 ] )
continue;
F_33 ( V_2 , V_16 ) ;
}
F_34 ( V_2 -> V_21 ) ;
V_2 -> V_86 = 0 ;
}
return 0 ;
}
static int F_95 ( struct V_14 * V_15 , T_1 V_104 , void * V_238 )
{
struct V_227 * V_228 = V_238 ;
struct V_12 V_12 ;
int V_83 ;
T_2 V_81 ;
int V_17 ;
switch ( V_228 -> V_239 ) {
case V_240 :
if ( F_85 ( V_228 , 1 ) > sizeof( V_12 . V_13 ) ) {
V_17 = - V_25 ;
goto V_226;
}
F_87 ( & V_12 , F_86 ( V_228 , 1 ) ) ;
if ( sscanf ( F_86 ( V_228 , 2 ) , L_46 , & V_81 ) != 1 ) {
V_17 = - V_25 ;
goto V_226;
}
if ( sscanf ( F_86 ( V_228 , 3 ) , L_47 , & V_83 ) != 1 ) {
V_17 = - V_25 ;
goto V_226;
}
V_17 = F_35 ( V_15 , & V_12 , V_81 , V_83 ) ;
goto V_226;
default:
F_12 ( L_48 , V_228 -> V_239 ) ;
V_17 = - V_25 ;
goto V_226;
}
V_226:
return V_17 ;
}
static int F_96 ( const struct V_51 * V_52 , struct V_33 * exp ,
struct V_165 * V_241 , T_5 V_242 , T_2 V_243 )
{
struct V_14 * V_15 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_165 * V_244 ;
int V_17 = 0 ;
T_1 V_16 ;
V_244 = F_41 ( sizeof( * V_244 ) , V_92 ) ;
if ( ! V_244 )
return - V_93 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_7 . V_20 ; V_16 ++ ) {
if ( ! V_2 -> V_21 [ V_16 ] || ! V_2 -> V_21 [ V_16 ] -> V_9 )
continue;
V_17 = V_165 ( V_52 , V_2 -> V_21 [ V_16 ] -> V_9 , V_244 ,
V_242 , V_243 ) ;
if ( V_17 ) {
F_12 ( L_49 , V_16 ,
V_2 -> V_21 [ V_16 ] -> V_9 -> V_10 -> V_28 ,
V_17 ) ;
goto V_245;
}
if ( V_16 == 0 ) {
* V_241 = * V_244 ;
if ( V_243 & V_246 )
goto V_245;
} else {
V_241 -> V_247 += V_244 -> V_247 ;
V_241 -> V_248 += V_244 -> V_248 ;
V_241 -> V_249 += V_244 -> V_249 ;
V_241 -> V_250 += V_244 -> V_250 ;
}
}
V_245:
F_34 ( V_244 ) ;
return V_17 ;
}
static int F_97 ( struct V_33 * exp ,
struct V_96 * V_193 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
return F_98 ( V_2 -> V_21 [ 0 ] -> V_9 , V_193 ) ;
}
static int F_99 ( struct V_33 * exp , const struct V_96 * V_193 ,
T_6 V_251 , const char * V_252 ,
const char * V_253 , int V_254 , int V_255 ,
int V_243 , struct V_256 * * V_257 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
V_4 = F_50 ( V_2 , V_193 ) ;
if ( F_51 ( V_4 ) )
return F_52 ( V_4 ) ;
return F_100 ( V_4 -> V_9 , V_193 , V_251 , V_252 , V_253 ,
V_254 , V_255 , V_243 , V_257 ) ;
}
static int F_101 ( struct V_33 * exp , const struct V_96 * V_193 ,
T_6 V_251 , const char * V_252 ,
const char * V_253 , int V_254 , int V_255 ,
int V_243 , T_2 V_258 ,
struct V_256 * * V_257 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
V_4 = F_50 ( V_2 , V_193 ) ;
if ( F_51 ( V_4 ) )
return F_52 ( V_4 ) ;
return F_102 ( V_4 -> V_9 , V_193 , V_251 , V_252 , V_253 ,
V_254 , V_255 , V_243 , V_258 ,
V_257 ) ;
}
static int F_103 ( struct V_33 * exp , struct V_198 * V_199 ,
struct V_256 * * V_257 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
V_4 = F_50 ( V_2 , & V_199 -> V_200 ) ;
if ( F_51 ( V_4 ) )
return F_52 ( V_4 ) ;
if ( V_199 -> V_259 & V_260 ) {
V_199 -> V_225 = V_4 -> V_78 ;
return 0 ;
}
return F_104 ( V_4 -> V_9 , V_199 , V_257 ) ;
}
static int F_105 ( struct V_33 * exp , const struct V_96 * V_193 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
T_1 V_16 ;
F_3 ( V_261 , L_50 V_122 L_51 , F_54 ( V_193 ) ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_7 . V_20 ; V_16 ++ ) {
if ( ! V_2 -> V_21 [ V_16 ] || ! V_2 -> V_21 [ V_16 ] -> V_9 )
continue;
F_106 ( V_2 -> V_21 [ V_16 ] -> V_9 , V_193 ) ;
}
return 0 ;
}
static int F_107 ( struct V_33 * exp , struct V_198 * V_199 ,
struct V_262 * V_263 , struct V_256 * * V_257 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
V_4 = F_50 ( V_2 , & V_199 -> V_200 ) ;
if ( F_51 ( V_4 ) )
return F_52 ( V_4 ) ;
F_3 ( V_261 , L_52 V_122 L_51 , F_54 ( & V_199 -> V_200 ) ) ;
return F_108 ( V_4 -> V_9 , V_199 , V_263 , V_257 ) ;
}
static struct V_3 *
F_109 ( struct V_1 * V_2 , struct V_95 * V_264 ,
const char * V_252 , int V_265 , struct V_96 * V_193 ,
T_1 * V_218 )
{
const struct V_266 * V_267 ;
struct V_3 * V_4 ;
if ( F_110 ( V_268 ) ) {
if ( V_269 >= V_264 -> V_270 )
return F_111 ( - V_154 ) ;
V_267 = & V_264 -> V_271 [ V_269 ] ;
} else {
V_267 = F_112 ( V_264 , V_252 , V_265 ) ;
if ( F_51 ( V_267 ) )
return F_113 ( V_267 ) ;
}
if ( V_193 )
* V_193 = V_267 -> V_272 ;
if ( V_218 )
* V_218 = V_267 -> V_273 ;
V_4 = F_81 ( V_2 , V_267 -> V_273 , NULL ) ;
F_3 ( V_18 , L_53 V_122 L_51 , V_267 -> V_273 ,
F_54 ( & V_267 -> V_272 ) ) ;
return V_4 ;
}
struct V_3 *
F_114 ( struct V_1 * V_2 , struct V_198 * V_199 ,
struct V_96 * V_193 )
{
struct V_95 * V_264 = V_199 -> V_274 ;
struct V_3 * V_4 ;
if ( V_199 -> V_275 & V_276 &&
( int ) V_199 -> V_225 != - 1 ) {
int V_16 ;
V_4 = F_81 ( V_2 , V_199 -> V_225 , NULL ) ;
if ( F_51 ( V_4 ) )
return V_4 ;
if ( V_264 ) {
for ( V_16 = 0 ; V_16 < V_264 -> V_270 ; V_16 ++ ) {
struct V_266 * V_267 ;
V_267 = & V_264 -> V_271 [ V_16 ] ;
if ( V_267 -> V_273 == V_199 -> V_225 ) {
* V_193 = V_267 -> V_272 ;
break;
}
}
if ( V_16 == V_264 -> V_270 )
* V_193 = V_264 -> V_271 [ 0 ] . V_272 ;
}
return V_4 ;
}
if ( ! V_264 || ! V_199 -> V_277 ) {
V_4 = F_50 ( V_2 , V_193 ) ;
if ( F_51 ( V_4 ) )
return V_4 ;
V_199 -> V_225 = V_4 -> V_78 ;
return V_4 ;
}
return F_109 ( V_2 , V_264 , V_199 -> V_278 ,
V_199 -> V_277 , V_193 ,
& V_199 -> V_225 ) ;
}
static int F_115 ( struct V_33 * exp , struct V_198 * V_199 ,
const void * V_38 , T_4 V_279 , T_7 V_280 ,
T_8 V_281 , T_9 V_282 , T_10 V_283 ,
T_5 V_284 , struct V_256 * * V_257 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_17 ;
if ( ! V_2 -> V_7 . V_8 )
return - V_217 ;
V_4 = F_114 ( V_2 , V_199 , & V_199 -> V_200 ) ;
if ( F_51 ( V_4 ) )
return F_52 ( V_4 ) ;
F_3 ( V_261 , L_54 V_122 L_55 ,
( int ) V_199 -> V_277 , V_199 -> V_278 ,
F_54 ( & V_199 -> V_200 ) , V_199 -> V_225 ) ;
V_17 = F_83 ( NULL , exp , & V_199 -> V_214 , V_199 ) ;
if ( V_17 )
return V_17 ;
if ( F_116 ( exp ) & V_285 ) {
V_4 = F_50 ( V_2 , & V_199 -> V_214 ) ;
if ( F_51 ( V_4 ) )
return F_52 ( V_4 ) ;
V_199 -> V_225 = V_4 -> V_78 ;
} else {
F_3 ( V_72 , L_56 ) ;
}
F_3 ( V_261 , L_57 V_122 L_55 ,
F_54 ( & V_199 -> V_200 ) , V_199 -> V_225 ) ;
V_199 -> V_259 |= V_286 ;
V_17 = F_117 ( V_4 -> V_9 , V_199 , V_38 , V_279 , V_280 , V_281 , V_282 ,
V_283 , V_284 , V_257 ) ;
if ( V_17 == 0 ) {
if ( ! * V_257 )
return V_17 ;
F_3 ( V_261 , L_58 V_122 L_51 , F_54 ( & V_199 -> V_214 ) ) ;
}
return V_17 ;
}
static int
F_118 ( struct V_33 * exp , struct V_287 * V_288 ,
const union V_289 * V_290 ,
struct V_291 * V_292 , struct V_198 * V_199 ,
struct V_56 * V_293 , T_5 V_294 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
F_3 ( V_261 , L_59 V_122 L_51 ,
F_119 ( V_292 ) , F_54 ( & V_199 -> V_200 ) ) ;
V_4 = F_114 ( V_2 , V_199 , & V_199 -> V_200 ) ;
if ( F_51 ( V_4 ) )
return F_52 ( V_4 ) ;
F_3 ( V_261 , L_59 V_122 L_60 ,
F_119 ( V_292 ) , F_54 ( & V_199 -> V_200 ) , V_4 -> V_78 ) ;
return F_120 ( V_4 -> V_9 , V_288 , V_290 , V_292 , V_199 , V_293 ,
V_294 ) ;
}
static int
F_121 ( struct V_33 * exp , struct V_198 * V_199 ,
struct V_256 * * V_295 )
{
struct V_256 * V_207 = NULL ;
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
struct V_296 * V_297 ;
int V_17 ;
V_4 = F_114 ( V_2 , V_199 , & V_199 -> V_200 ) ;
if ( F_51 ( V_4 ) )
return F_52 ( V_4 ) ;
F_3 ( V_261 , L_61 V_122 L_60 ,
( int ) V_199 -> V_277 , V_199 -> V_278 ,
F_54 ( & V_199 -> V_200 ) , V_4 -> V_78 ) ;
V_17 = F_122 ( V_4 -> V_9 , V_199 , V_295 ) ;
if ( V_17 != 0 )
return V_17 ;
V_297 = F_123 ( & ( * V_295 ) -> V_298 , & V_299 ) ;
if ( V_297 -> V_300 & V_301 ) {
struct V_96 V_302 = V_297 -> V_303 ;
F_3 ( V_261 , L_62 V_122 L_51 ,
F_54 ( & V_302 ) ) ;
V_4 = F_50 ( V_2 , & V_302 ) ;
if ( F_51 ( V_4 ) ) {
F_124 ( * V_295 ) ;
* V_295 = NULL ;
return F_52 ( V_4 ) ;
}
V_199 -> V_200 = V_302 ;
V_199 -> V_304 |= V_305 ;
V_199 -> V_277 = 0 ;
V_199 -> V_278 = NULL ;
V_17 = F_122 ( V_4 -> V_9 , V_199 , & V_207 ) ;
F_124 ( * V_295 ) ;
* V_295 = V_207 ;
}
return V_17 ;
}
static int F_125 ( struct V_33 * exp , struct V_3 * V_4 ,
struct V_198 * V_199 , int V_306 ,
enum V_307 V_280 , int V_308 , int V_309 )
{
struct V_96 * V_193 = F_126 ( V_199 , V_309 ) ;
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
union V_289 V_290 = { { 0 } } ;
int V_17 = 0 ;
if ( ! F_55 ( V_193 ) )
return 0 ;
if ( ! V_4 ) {
V_4 = F_50 ( V_2 , V_193 ) ;
if ( F_51 ( V_4 ) )
return F_52 ( V_4 ) ;
}
if ( V_4 -> V_78 != V_306 ) {
F_3 ( V_261 , L_63 V_122 L_51 , F_54 ( V_193 ) ) ;
V_290 . V_310 . V_308 = V_308 ;
V_17 = F_127 ( V_4 -> V_9 , V_193 , & V_290 ,
V_280 , V_311 , NULL ) ;
} else {
F_3 ( V_261 ,
L_64 V_122 L_51 ,
V_306 , F_54 ( V_193 ) ) ;
V_199 -> V_259 |= V_309 ;
V_17 = 0 ;
}
return V_17 ;
}
static int F_128 ( struct V_33 * exp , struct V_198 * V_199 ,
struct V_256 * * V_257 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_17 ;
F_7 ( V_199 -> V_277 != 0 ) ;
F_3 ( V_261 , L_65 V_122 L_66 V_122 L_51 ,
F_54 ( & V_199 -> V_214 ) , ( int ) V_199 -> V_277 ,
V_199 -> V_278 , F_54 ( & V_199 -> V_200 ) ) ;
V_199 -> V_312 = F_129 ( & V_313 , F_130 () ) ;
V_199 -> V_314 = F_131 ( & V_313 , F_132 () ) ;
V_199 -> V_315 = F_133 () ;
if ( V_199 -> V_316 ) {
struct V_95 * V_264 = V_199 -> V_316 ;
const struct V_266 * V_267 ;
V_267 = F_112 ( V_264 , V_199 -> V_278 ,
V_199 -> V_277 ) ;
if ( F_51 ( V_267 ) )
return F_52 ( V_267 ) ;
V_199 -> V_214 = V_267 -> V_272 ;
}
V_4 = F_114 ( V_2 , V_199 , & V_199 -> V_214 ) ;
if ( F_51 ( V_4 ) )
return F_52 ( V_4 ) ;
V_199 -> V_259 |= V_317 ;
V_17 = F_125 ( exp , NULL , V_199 , V_4 -> V_78 , V_318 ,
V_319 , V_286 ) ;
if ( V_17 != 0 )
return V_17 ;
return F_134 ( V_4 -> V_9 , V_199 , V_257 ) ;
}
static int F_135 ( struct V_33 * exp , struct V_198 * V_199 ,
const char * V_89 , T_4 V_320 ,
const char * V_321 , T_4 V_322 ,
struct V_256 * * V_257 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_33 * V_323 ;
struct V_3 * V_324 ;
struct V_3 * V_325 ;
struct V_296 * V_297 ;
int V_17 ;
F_7 ( V_320 != 0 ) ;
F_3 ( V_261 , L_67 V_122 L_68 V_122 L_69 ,
( int ) V_320 , V_89 , F_54 ( & V_199 -> V_200 ) ,
V_199 -> V_274 ? V_199 -> V_274 -> V_270 : 0 ,
( int ) V_322 , V_321 , F_54 ( & V_199 -> V_214 ) ,
V_199 -> V_316 ? V_199 -> V_316 -> V_270 : 0 ) ;
V_199 -> V_312 = F_129 ( & V_313 , F_130 () ) ;
V_199 -> V_314 = F_131 ( & V_313 , F_132 () ) ;
V_199 -> V_315 = F_133 () ;
if ( V_199 -> V_220 & V_326 ) {
F_136 ( F_55 ( & V_199 -> V_327 ) , L_70 V_122 L_51 ,
F_54 ( & V_199 -> V_327 ) ) ;
if ( V_199 -> V_274 ) {
struct V_95 * V_264 = V_199 -> V_274 ;
struct V_3 * V_328 ;
V_328 = F_109 ( V_2 , V_264 , V_89 ,
V_320 ,
& V_199 -> V_200 ,
NULL ) ;
if ( F_51 ( V_328 ) )
return F_52 ( V_328 ) ;
}
V_17 = F_83 ( NULL , exp , & V_199 -> V_214 , V_199 ) ;
if ( V_17 )
return V_17 ;
V_324 = F_50 ( V_2 , & V_199 -> V_327 ) ;
if ( F_51 ( V_324 ) )
return F_52 ( V_324 ) ;
V_323 = V_324 -> V_9 ;
} else {
if ( V_199 -> V_274 ) {
struct V_95 * V_264 = V_199 -> V_274 ;
V_324 = F_109 ( V_2 , V_264 , V_89 ,
V_320 ,
& V_199 -> V_200 ,
& V_199 -> V_225 ) ;
} else {
V_324 = F_50 ( V_2 , & V_199 -> V_200 ) ;
}
if ( F_51 ( V_324 ) )
return F_52 ( V_324 ) ;
if ( V_199 -> V_316 ) {
struct V_95 * V_264 = V_199 -> V_316 ;
V_325 = F_109 ( V_2 , V_264 , V_321 ,
V_322 ,
& V_199 -> V_214 ,
& V_199 -> V_225 ) ;
} else {
V_325 = F_50 ( V_2 , & V_199 -> V_214 ) ;
}
if ( F_51 ( V_325 ) )
return F_52 ( V_325 ) ;
V_323 = V_325 -> V_9 ;
}
V_199 -> V_259 |= V_286 | V_329 ;
V_17 = F_125 ( exp , NULL , V_199 , V_324 -> V_78 ,
V_318 , V_319 ,
V_317 ) ;
if ( V_17 )
return V_17 ;
if ( F_55 ( & V_199 -> V_327 ) ) {
struct V_3 * V_4 ;
V_4 = F_50 ( V_2 , & V_199 -> V_200 ) ;
if ( F_51 ( V_4 ) )
return F_52 ( V_4 ) ;
V_17 = F_125 ( exp , V_4 , V_199 , V_324 -> V_78 ,
V_318 , V_330 ,
V_329 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_125 ( exp , NULL , V_199 , V_324 -> V_78 ,
V_318 , V_331 ,
V_329 ) ;
if ( V_17 )
return V_17 ;
}
V_332:
if ( F_55 ( & V_199 -> V_333 ) ) {
struct V_3 * V_4 ;
V_17 = F_125 ( exp , NULL , V_199 , V_324 -> V_78 ,
V_318 , V_331 ,
V_334 ) ;
if ( V_17 )
return V_17 ;
V_4 = F_50 ( V_2 , & V_199 -> V_333 ) ;
if ( F_51 ( V_4 ) )
return F_52 ( V_4 ) ;
V_323 = V_4 -> V_9 ;
}
V_17 = F_137 ( V_323 , V_199 , V_89 , V_320 , V_321 , V_322 , V_257 ) ;
if ( V_17 && V_17 != - V_115 )
return V_17 ;
V_297 = F_123 ( & ( * V_257 ) -> V_298 , & V_299 ) ;
if ( ! V_297 )
return - V_335 ;
if ( F_138 ( ! ( V_297 -> V_300 & V_301 ) ) )
return V_17 ;
F_3 ( V_261 , L_71 V_122 L_51 ,
exp -> V_10 -> V_28 , F_54 ( & V_297 -> V_303 ) ) ;
V_199 -> V_333 = V_297 -> V_303 ;
F_124 ( * V_257 ) ;
* V_257 = NULL ;
goto V_332;
}
static int F_139 ( struct V_33 * exp , struct V_198 * V_199 ,
void * V_336 , T_4 V_337 , struct V_256 * * V_257 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
F_3 ( V_261 , L_72 V_122 L_73 ,
F_54 ( & V_199 -> V_200 ) , V_199 -> V_338 . V_339 ) ;
V_199 -> V_259 |= V_286 ;
V_4 = F_50 ( V_2 , & V_199 -> V_200 ) ;
if ( F_51 ( V_4 ) )
return F_52 ( V_4 ) ;
return F_140 ( V_4 -> V_9 , V_199 , V_336 , V_337 , V_257 ) ;
}
static int F_141 ( struct V_33 * exp , const struct V_96 * V_193 ,
struct V_256 * * V_257 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
V_4 = F_50 ( V_2 , V_193 ) ;
if ( F_51 ( V_4 ) )
return F_52 ( V_4 ) ;
return F_142 ( V_4 -> V_9 , V_193 , V_257 ) ;
}
static int F_143 ( struct V_33 * exp ,
struct V_198 * V_199 ,
struct V_340 * V_341 ,
T_5 V_342 , int * V_343 ,
struct V_344 * * V_345 ,
struct V_346 * * V_347 )
{
struct V_95 * V_264 = V_199 -> V_274 ;
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_344 * V_348 = NULL ;
struct V_346 * V_349 = NULL ;
struct V_3 * V_4 ;
int V_350 ;
int V_351 = 0 ;
int V_17 = 0 ;
int V_16 ;
V_350 = V_264 -> V_270 ;
for ( V_16 = 0 ; V_16 < V_350 ; V_16 ++ ) {
T_5 V_352 = V_342 ;
struct V_344 * V_353 = NULL ;
struct V_346 * V_346 = NULL ;
struct V_354 * V_355 ;
V_4 = F_81 ( V_2 , V_264 -> V_271 [ V_16 ] . V_273 , NULL ) ;
if ( F_51 ( V_4 ) ) {
V_17 = F_52 ( V_4 ) ;
goto V_226;
}
V_199 -> V_200 = V_264 -> V_271 [ V_16 ] . V_272 ;
V_199 -> V_214 = V_264 -> V_271 [ V_16 ] . V_272 ;
V_199 -> V_199 = V_264 -> V_271 [ V_16 ] . V_356 ;
V_357:
V_17 = F_144 ( V_4 -> V_9 , V_199 , V_341 , V_352 ,
& V_346 ) ;
if ( V_17 )
goto V_226;
V_355 = F_145 ( V_346 ) ;
for ( V_353 = F_146 ( V_355 ) ; V_353 ;
V_353 = F_147 ( V_353 ) ) {
if ( ! F_148 ( V_353 -> V_358 ) )
continue;
if ( F_149 ( V_353 -> V_359 ) < V_342 )
continue;
if ( F_149 ( V_353 -> V_359 ) == V_342 &&
( * V_345 == V_353 || V_16 < * V_343 ) )
continue;
if ( V_16 && ( ! strncmp ( V_353 -> V_360 , L_74 ,
F_148 ( V_353 -> V_358 ) ) ||
! strncmp ( V_353 -> V_360 , L_75 ,
F_148 ( V_353 -> V_358 ) ) ) )
continue;
break;
}
if ( ! V_353 ) {
V_352 = F_149 ( V_355 -> V_361 ) ;
F_150 ( V_346 ) ;
F_151 ( V_346 ) ;
V_346 = NULL ;
if ( V_352 == V_362 )
continue;
else
goto V_357;
}
if ( V_348 ) {
if ( F_149 ( V_348 -> V_359 ) >
F_149 ( V_353 -> V_359 ) ) {
V_348 = V_353 ;
F_150 ( V_349 ) ;
F_151 ( V_349 ) ;
V_351 = V_16 ;
V_349 = V_346 ;
} else {
F_150 ( V_346 ) ;
F_151 ( V_346 ) ;
V_346 = NULL ;
}
} else {
V_348 = V_353 ;
V_349 = V_346 ;
V_351 = V_16 ;
}
}
V_226:
if ( * V_347 ) {
F_150 ( * V_347 ) ;
F_151 ( * V_347 ) ;
}
* V_343 = V_351 ;
* V_345 = V_348 ;
* V_347 = V_349 ;
return V_17 ;
}
static int F_152 ( struct V_33 * exp ,
struct V_198 * V_199 ,
struct V_340 * V_341 ,
T_5 V_363 , struct V_346 * * V_347 )
{
struct V_364 * V_365 = V_199 -> V_199 ;
struct V_96 V_366 = V_199 -> V_200 ;
T_5 V_342 = V_363 ;
T_2 V_367 ;
struct V_346 * V_368 = NULL ;
struct V_346 * V_369 = NULL ;
struct V_344 * V_348 = NULL ;
struct V_344 * V_370 ;
struct V_344 * V_353 ;
struct V_354 * V_355 ;
T_4 V_371 ;
int V_372 = 0 ;
void * V_373 ;
int V_17 ;
V_369 = F_153 ( V_374 ) ;
if ( ! V_369 )
return - V_93 ;
V_355 = F_154 ( V_369 ) ;
memset ( V_355 , 0 , sizeof( * V_355 ) ) ;
V_355 -> V_375 = F_155 ( V_363 ) ;
V_367 = V_376 ;
V_373 = V_355 + 1 ;
V_371 = V_377 - sizeof( * V_355 ) ;
V_353 = V_373 ;
V_370 = V_353 ;
do {
T_11 V_378 ;
V_17 = F_143 ( exp , V_199 , V_341 , V_342 ,
& V_372 , & V_348 ,
& V_368 ) ;
if ( V_17 )
goto V_226;
if ( ! V_348 ) {
V_370 -> V_379 = 0 ;
V_342 = V_362 ;
goto V_226;
}
V_378 = F_148 ( V_348 -> V_379 ) ;
if ( ! V_378 )
V_378 = F_156 (
F_148 ( V_348 -> V_358 ) ,
F_78 ( V_348 -> V_380 ) ) ;
if ( V_378 > V_371 ) {
V_370 -> V_379 = F_157 ( 0 ) ;
V_342 = F_149 ( V_348 -> V_359 ) ;
goto V_226;
}
memcpy ( V_353 , V_348 , V_378 ) ;
if ( ! strncmp ( V_353 -> V_360 , L_74 ,
F_148 ( V_353 -> V_358 ) ) &&
F_148 ( V_353 -> V_358 ) == 1 )
F_158 ( & V_353 -> V_381 , & V_366 ) ;
else if ( ! strncmp ( V_353 -> V_360 , L_75 ,
F_148 ( V_353 -> V_358 ) ) &&
F_148 ( V_353 -> V_358 ) == 2 )
F_158 ( & V_353 -> V_381 , & V_199 -> V_327 ) ;
V_371 -= V_378 ;
V_353 -> V_379 = F_157 ( V_378 ) ;
V_370 = V_353 ;
V_353 = ( void * ) V_353 + V_378 ;
V_342 = F_149 ( V_348 -> V_359 ) ;
if ( V_342 == V_362 ) {
V_370 -> V_379 = 0 ;
break;
}
} while ( 1 );
V_226:
if ( V_368 ) {
F_150 ( V_368 ) ;
F_151 ( V_368 ) ;
}
if ( F_159 ( V_17 ) ) {
F_160 ( V_369 ) ;
V_369 = NULL ;
} else {
if ( V_353 == V_373 )
V_367 |= V_382 ;
V_355 -> V_367 |= F_79 ( V_367 ) ;
V_355 -> V_361 = F_155 ( V_342 ) ;
}
V_199 -> V_200 = V_366 ;
V_199 -> V_214 = V_366 ;
V_199 -> V_199 = V_365 ;
* V_347 = V_369 ;
return V_17 ;
}
static int F_161 ( struct V_33 * exp , struct V_198 * V_199 ,
struct V_340 * V_341 , T_5 V_363 ,
struct V_346 * * V_347 )
{
struct V_95 * V_264 = V_199 -> V_274 ;
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
if ( F_159 ( V_264 ) )
return F_152 ( exp , V_199 , V_341 , V_363 , V_347 ) ;
V_4 = F_50 ( V_2 , & V_199 -> V_200 ) ;
if ( F_51 ( V_4 ) )
return F_52 ( V_4 ) ;
return F_144 ( V_4 -> V_9 , V_199 , V_341 , V_363 , V_347 ) ;
}
static int F_162 ( struct V_33 * exp , struct V_198 * V_199 ,
struct V_256 * * V_257 )
{
struct V_95 * V_264 = V_199 -> V_274 ;
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_383 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_296 * V_297 ;
int V_384 = 0 ;
int V_17 ;
V_385:
if ( V_264 ) {
struct V_3 * V_328 ;
F_7 ( V_199 -> V_278 && V_199 -> V_277 ) ;
V_328 = F_109 ( V_2 , V_264 ,
V_199 -> V_278 ,
V_199 -> V_277 ,
& V_199 -> V_200 ,
& V_199 -> V_225 ) ;
if ( F_51 ( V_328 ) && F_52 ( V_328 ) != - V_386 )
return F_52 ( V_328 ) ;
if ( ! F_163 ( V_264 -> V_387 ) ) {
struct V_266 * V_267 ;
V_267 = & V_264 -> V_271 [ V_384 ] ;
V_199 -> V_200 = V_267 -> V_272 ;
V_199 -> V_225 = V_267 -> V_273 ;
}
}
V_388:
if ( F_138 ( ! F_164 ( & V_199 -> V_214 ) ) )
V_4 = F_50 ( V_2 , & V_199 -> V_214 ) ;
else if ( V_264 )
V_4 = F_81 ( V_2 , V_199 -> V_225 , NULL ) ;
else
V_4 = F_114 ( V_2 , V_199 , & V_199 -> V_200 ) ;
if ( F_51 ( V_4 ) )
return F_52 ( V_4 ) ;
V_199 -> V_312 = F_129 ( & V_313 , F_130 () ) ;
V_199 -> V_314 = F_131 ( & V_313 , F_132 () ) ;
V_199 -> V_315 = F_133 () ;
V_199 -> V_259 |= V_286 | V_329 ;
V_383 = F_50 ( V_2 , & V_199 -> V_200 ) ;
if ( F_51 ( V_383 ) )
return F_52 ( V_383 ) ;
if ( V_383 != V_4 ) {
V_17 = F_125 ( exp , V_383 , V_199 , V_4 -> V_78 ,
V_318 , V_330 ,
V_329 ) ;
}
V_17 = F_125 ( exp , NULL , V_199 , V_4 -> V_78 , V_318 ,
V_331 , V_329 ) ;
if ( V_17 != 0 )
return V_17 ;
F_3 ( V_261 , L_76 V_122 L_77 V_122 L_60 ,
F_54 ( & V_199 -> V_200 ) , F_54 ( & V_199 -> V_214 ) , V_4 -> V_78 ) ;
V_17 = F_165 ( V_4 -> V_9 , V_199 , V_257 ) ;
if ( V_17 != 0 && V_17 != - V_115 && V_17 != - V_389 )
return V_17 ;
if ( V_17 == - V_389 && V_264 && F_166 ( V_264 ) ) {
struct V_266 * V_267 ;
V_384 ++ ;
if ( V_384 >= V_264 -> V_270 )
return V_17 ;
V_267 = & V_264 -> V_271 [ V_384 ] ;
V_199 -> V_200 = V_267 -> V_272 ;
V_199 -> V_225 = V_267 -> V_273 ;
F_124 ( * V_257 ) ;
* V_257 = NULL ;
goto V_388;
}
V_297 = F_123 ( & ( * V_257 ) -> V_298 , & V_299 ) ;
if ( ! V_297 )
return - V_335 ;
if ( F_138 ( ! ( V_297 -> V_300 & V_301 ) ) )
return V_17 ;
F_3 ( V_261 , L_78 V_122 L_51 ,
exp -> V_10 -> V_28 , F_54 ( & V_297 -> V_303 ) ) ;
V_199 -> V_214 = V_297 -> V_303 ;
F_124 ( * V_257 ) ;
* V_257 = NULL ;
goto V_385;
}
static int F_167 ( struct V_14 * V_15 )
{
F_168 ( & V_15 -> V_34 . V_2 . V_79 ) ;
F_169 ( V_15 ) ;
return 0 ;
}
static int F_170 ( const struct V_51 * V_52 , struct V_33 * exp ,
T_2 V_390 , void * V_391 , T_2 * V_392 , void * V_393 )
{
struct V_14 * V_15 ;
struct V_1 * V_2 ;
int V_17 = 0 ;
V_15 = F_6 ( exp ) ;
if ( ! V_15 ) {
F_3 ( V_394 , L_79 ,
exp -> V_23 . V_24 ) ;
return - V_25 ;
}
V_2 = & V_15 -> V_34 . V_2 ;
if ( V_390 >= strlen ( L_80 ) && ! strcmp ( V_391 , L_80 ) ) {
int V_16 ;
F_7 ( * V_392 == sizeof( T_2 ) ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_7 . V_20 ; V_16 ++ ) {
struct V_3 * V_4 = V_2 -> V_21 [ V_16 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
continue;
if ( ! F_171 ( V_52 , V_4 -> V_9 , V_390 , V_391 ,
V_392 , V_393 ) )
return 0 ;
}
return - V_25 ;
} else if ( F_172 ( V_395 ) ||
F_172 ( V_396 ) ||
F_172 ( V_397 ) ) {
V_17 = F_171 ( V_52 , V_2 -> V_21 [ 0 ] -> V_9 , V_390 , V_391 ,
V_392 , V_393 ) ;
if ( ! V_17 && F_172 ( V_397 ) )
exp -> V_49 = * (struct V_39 * ) V_393 ;
return V_17 ;
} else if ( F_172 ( V_398 ) ) {
* ( ( int * ) V_393 ) = V_2 -> V_7 . V_20 ;
return 0 ;
}
F_3 ( V_394 , L_81 ) ;
return - V_25 ;
}
static int F_173 ( const struct V_51 * V_52 , struct V_33 * exp ,
T_1 V_390 , void * V_391 , T_1 V_392 ,
void * V_393 , struct V_399 * V_160 )
{
struct V_3 * V_4 ;
struct V_14 * V_15 ;
struct V_1 * V_2 ;
int V_17 = 0 ;
V_15 = F_6 ( exp ) ;
if ( ! V_15 ) {
F_3 ( V_394 , L_79 ,
exp -> V_23 . V_24 ) ;
return - V_25 ;
}
V_2 = & V_15 -> V_34 . V_2 ;
if ( F_172 ( V_400 ) || F_172 ( V_401 ) ||
F_172 ( V_396 ) ) {
int V_16 , V_147 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_7 . V_20 ; V_16 ++ ) {
V_4 = V_2 -> V_21 [ V_16 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
continue;
V_147 = F_174 ( V_52 , V_4 -> V_9 ,
V_390 , V_391 , V_392 , V_393 , V_160 ) ;
if ( V_147 && V_17 == 0 )
V_17 = V_147 ;
}
return V_17 ;
}
return - V_25 ;
}
static int F_175 ( struct V_33 * exp , struct V_95 * V_264 ,
const struct V_402 * V_403 )
{
struct V_1 * V_2 = & exp -> V_10 -> V_34 . V_2 ;
int V_350 ;
int V_17 = 0 ;
int V_404 ;
int V_16 ;
V_264 -> V_405 = F_78 ( V_403 -> V_406 ) ;
V_264 -> V_270 = F_78 ( V_403 -> V_407 ) ;
V_264 -> V_408 = F_78 ( V_403 -> V_409 ) ;
if ( F_110 ( V_410 ) )
V_264 -> V_387 = V_411 ;
else
V_264 -> V_387 = F_78 ( V_403 -> V_412 ) ;
V_264 -> V_413 = F_78 ( V_403 -> V_414 ) ;
V_404 = F_176 ( V_264 -> V_415 , V_403 -> V_416 ,
sizeof( V_264 -> V_415 ) ) ;
if ( V_404 >= sizeof( V_264 -> V_415 ) )
return - V_417 ;
F_3 ( V_18 , L_82 ,
V_264 -> V_270 , V_264 -> V_408 ,
V_264 -> V_387 , V_264 -> V_413 ) ;
V_350 = F_78 ( V_403 -> V_407 ) ;
for ( V_16 = 0 ; V_16 < V_350 ; V_16 ++ ) {
F_177 ( & V_264 -> V_271 [ V_16 ] . V_272 ,
& V_403 -> V_418 [ V_16 ] ) ;
V_17 = F_71 ( V_2 , & V_264 -> V_271 [ V_16 ] . V_272 ,
& V_264 -> V_271 [ V_16 ] . V_273 ) ;
if ( V_17 )
return V_17 ;
F_3 ( V_18 , L_83 V_122 L_51 , V_16 ,
F_54 ( & V_264 -> V_271 [ V_16 ] . V_272 ) ) ;
}
return V_17 ;
}
static int F_178 ( struct V_33 * exp , struct V_95 * * V_419 ,
const union V_420 * V_421 , T_4 V_422 )
{
struct V_95 * V_264 ;
bool V_423 = false ;
int V_424 , V_17 ;
F_7 ( V_419 ) ;
V_264 = * V_419 ;
if ( V_264 && ! V_421 ) {
int V_16 ;
for ( V_16 = 1 ; V_16 < V_264 -> V_270 ; V_16 ++ ) {
if ( ! ( V_264 -> V_387 & V_425 &&
! V_16 ) && V_264 -> V_271 [ V_16 ] . V_356 )
F_179 ( V_264 -> V_271 [ V_16 ] . V_356 ) ;
}
F_75 ( V_264 ) ;
* V_419 = NULL ;
return 0 ;
}
if ( F_78 ( V_421 -> V_406 ) == V_426 )
return - V_215 ;
if ( F_78 ( V_421 -> V_406 ) != V_427 &&
F_78 ( V_421 -> V_406 ) != V_428 ) {
F_12 ( L_84 ,
exp -> V_10 -> V_28 , F_78 ( V_421 -> V_406 ) ,
- V_217 ) ;
return - V_217 ;
}
if ( F_78 ( V_421 -> V_406 ) == V_427 )
V_424 = F_180 ( F_181 ( V_421 ) ) ;
else
V_424 = F_180 ( 0 ) ;
if ( ! V_264 ) {
V_264 = F_74 ( V_424 , V_92 ) ;
if ( ! V_264 )
return - V_93 ;
V_423 = true ;
* V_419 = V_264 ;
}
switch ( F_78 ( V_421 -> V_406 ) ) {
case V_427 :
V_17 = F_175 ( exp , V_264 , & V_421 -> V_429 ) ;
break;
default:
F_12 ( L_85 , exp -> V_10 -> V_28 ,
F_78 ( V_421 -> V_406 ) ) ;
V_17 = - V_25 ;
break;
}
if ( V_17 && V_423 ) {
F_75 ( V_264 ) ;
* V_419 = NULL ;
V_424 = V_17 ;
}
return V_424 ;
}
void F_182 ( struct V_95 * V_264 )
{
F_178 ( NULL , & V_264 , NULL , 0 ) ;
}
static int F_183 ( struct V_33 * exp , const struct V_96 * V_193 ,
union V_289 * V_290 ,
enum V_307 V_280 , enum V_430 V_243 ,
void * V_431 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
int V_17 = 0 ;
int V_147 ;
T_1 V_16 ;
F_7 ( V_193 ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_7 . V_20 ; V_16 ++ ) {
struct V_3 * V_4 = V_2 -> V_21 [ V_16 ] ;
if ( ! V_4 || ! V_4 -> V_9 || ! V_4 -> V_6 )
continue;
V_147 = F_127 ( V_4 -> V_9 , V_193 , V_290 , V_280 , V_243 ,
V_431 ) ;
if ( ! V_17 )
V_17 = V_147 ;
}
return V_17 ;
}
static int F_184 ( struct V_33 * exp ,
const struct V_56 * V_293 ,
void * V_38 , T_5 * V_308 )
{
struct V_1 * V_2 = & exp -> V_10 -> V_34 . V_2 ;
struct V_3 * V_4 = V_2 -> V_21 [ 0 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
return - V_25 ;
return F_185 ( V_4 -> V_9 , V_293 , V_38 , V_308 ) ;
}
static enum V_307 F_186 ( struct V_33 * exp , T_5 V_243 ,
const struct V_96 * V_193 ,
enum V_432 type ,
union V_289 * V_290 ,
enum V_307 V_280 ,
struct V_56 * V_293 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
enum V_307 V_17 ;
int V_4 ;
T_1 V_16 ;
F_3 ( V_261 , L_86 V_122 L_51 , F_54 ( V_193 ) ) ;
for ( V_16 = 0 , V_4 = F_187 ( V_2 , V_193 ) ;
V_16 < V_2 -> V_7 . V_20 ;
V_16 ++ , V_4 = ( V_4 + 1 ) % V_2 -> V_7 . V_20 ) {
if ( V_4 < 0 ) {
F_3 ( V_433 , L_87 V_122 L_88 ,
V_15 -> V_28 , F_54 ( V_193 ) , V_4 ) ;
V_4 = 0 ;
}
if ( ! V_2 -> V_21 [ V_4 ] || ! V_2 -> V_21 [ V_4 ] -> V_9 ||
! V_2 -> V_21 [ V_4 ] -> V_6 )
continue;
V_17 = F_188 ( V_2 -> V_21 [ V_4 ] -> V_9 , V_243 , V_193 ,
type , V_290 , V_280 , V_293 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static int F_189 ( struct V_33 * exp ,
struct V_256 * V_207 ,
struct V_33 * V_434 ,
struct V_33 * V_435 ,
struct V_436 * V_437 )
{
struct V_1 * V_2 = & exp -> V_10 -> V_34 . V_2 ;
struct V_3 * V_4 = V_2 -> V_21 [ 0 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
return - V_25 ;
return F_190 ( V_4 -> V_9 , V_207 , V_434 , V_435 , V_437 ) ;
}
static int F_191 ( struct V_33 * exp , struct V_436 * V_437 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 = V_2 -> V_21 [ 0 ] ;
if ( V_437 -> V_2 ) {
F_182 ( V_437 -> V_2 ) ;
V_437 -> V_2 = NULL ;
}
if ( ! V_4 || ! V_4 -> V_9 )
return - V_25 ;
return F_192 ( V_4 -> V_9 , V_437 ) ;
}
static int F_193 ( struct V_33 * exp ,
struct V_438 * V_439 ,
struct V_291 * V_292 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
V_4 = F_50 ( V_2 , & V_439 -> V_440 ) ;
if ( F_51 ( V_4 ) )
return F_52 ( V_4 ) ;
return F_194 ( V_4 -> V_9 , V_439 , V_292 ) ;
}
static int F_195 ( struct V_33 * exp ,
struct V_438 * V_439 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
V_4 = F_50 ( V_2 , & V_439 -> V_440 ) ;
if ( F_51 ( V_4 ) )
return F_52 ( V_4 ) ;
return F_196 ( V_4 -> V_9 , V_439 ) ;
}
static int F_197 ( struct V_33 * exp ,
struct V_441 * V_442 )
{
struct V_198 * V_199 = & V_442 -> V_443 ;
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_444 = NULL ;
struct V_3 * V_445 = NULL ;
if ( ! F_55 ( & V_199 -> V_214 ) )
return - V_25 ;
V_444 = F_114 ( V_2 , V_199 , & V_199 -> V_200 ) ;
if ( F_51 ( V_444 ) )
return F_52 ( V_444 ) ;
V_445 = F_114 ( V_2 , V_199 , & V_199 -> V_214 ) ;
if ( F_51 ( V_445 ) )
return F_52 ( V_445 ) ;
if ( V_444 != V_445 )
return - V_446 ;
return F_198 ( V_444 -> V_9 , V_442 ) ;
}
static int F_199 ( struct V_33 * exp , struct V_291 * V_292 ,
struct V_96 * V_193 , T_5 * V_308 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
V_4 = F_50 ( V_2 , V_193 ) ;
if ( F_51 ( V_4 ) )
return F_52 ( V_4 ) ;
return F_200 ( V_4 -> V_9 , V_292 , V_193 , V_308 ) ;
}
static int
F_201 ( struct V_33 * exp ,
const struct V_95 * V_264 ,
const char * V_252 , int V_265 , struct V_96 * V_193 )
{
const struct V_266 * V_267 ;
F_7 ( V_264 ) ;
V_267 = F_112 ( V_264 , V_252 , V_265 ) ;
if ( F_51 ( V_267 ) )
return F_52 ( V_267 ) ;
* V_193 = V_267 -> V_272 ;
return 0 ;
}
static int F_202 ( struct V_14 * V_447 , struct V_33 * exp ,
struct V_179 * V_180 )
{
struct V_14 * V_15 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 = V_2 -> V_21 [ 0 ] ;
int V_17 = 0 ;
T_5 V_448 = 0 , V_449 = 0 ;
T_1 V_16 ;
if ( ! V_4 || ! V_4 -> V_9 || ! V_4 -> V_6 ||
! V_2 -> V_7 . V_20 ) {
F_12 ( L_89 ) ;
return - V_217 ;
}
if ( V_180 -> V_450 != V_451 )
return V_179 ( V_4 -> V_9 , V_180 ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_7 . V_20 ; V_16 ++ ) {
int V_147 ;
V_4 = V_2 -> V_21 [ V_16 ] ;
if ( ! V_4 || ! V_4 -> V_9 || ! V_4 -> V_6 )
continue;
V_147 = V_179 ( V_4 -> V_9 , V_180 ) ;
if ( V_147 ) {
F_12 ( L_90 , V_16 , V_147 ) ;
if ( ! V_17 )
V_17 = V_147 ;
} else {
V_448 += V_180 -> V_452 . V_453 ;
V_449 += V_180 -> V_452 . V_454 ;
}
}
V_180 -> V_452 . V_453 = V_448 ;
V_180 -> V_452 . V_454 = V_449 ;
return V_17 ;
}
static int F_203 ( struct V_33 * exp ,
const struct V_95 * V_264 ,
struct V_455 * V_456 ,
T_12 V_457 )
{
int V_17 , V_16 ;
V_17 = F_204 ( exp , V_264 , V_457 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
for ( V_16 = 0 ; V_16 < V_264 -> V_270 ; V_16 ++ ) {
struct V_364 * V_364 = V_264 -> V_271 [ V_16 ] . V_356 ;
F_3 ( V_18 , L_5 V_122 L_91 ,
F_54 ( & V_264 -> V_271 [ V_16 ] . V_272 ) ,
F_205 ( V_364 ) , ( unsigned long long ) V_364 -> V_458 ,
V_364 -> V_459 , F_206 ( V_364 -> V_460 ) ,
F_206 ( V_364 -> V_461 ) , F_206 ( V_364 -> V_462 ) ) ;
if ( V_16 )
V_456 -> V_463 += V_364 -> V_459 - 2 ;
else
V_456 -> V_463 = V_364 -> V_459 ;
V_456 -> V_464 += F_205 ( V_364 ) ;
V_456 -> V_465 += V_364 -> V_458 ;
if ( V_456 -> V_466 < F_206 ( V_364 -> V_460 ) )
V_456 -> V_466 = F_206 ( V_364 -> V_460 ) ;
if ( V_456 -> V_467 < F_206 ( V_364 -> V_461 ) )
V_456 -> V_467 = F_206 ( V_364 -> V_461 ) ;
if ( V_456 -> V_468 < F_206 ( V_364 -> V_462 ) )
V_456 -> V_468 = F_206 ( V_364 -> V_462 ) ;
}
return 0 ;
}
static int T_13 F_207 ( void )
{
struct V_229 V_230 ;
F_89 ( & V_230 ) ;
return F_208 ( & V_469 , & V_470 ,
V_471 , NULL ) ;
}
static void F_209 ( void )
{
F_210 ( V_471 ) ;
}
