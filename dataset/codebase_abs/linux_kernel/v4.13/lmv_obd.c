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
struct V_33 * * exp , struct V_14 * V_15 ,
struct V_12 * V_53 , struct V_39 * V_38 ,
void * V_54 )
{
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_55 V_56 = { 0 } ;
int V_17 = 0 ;
V_2 -> V_57 ++ ;
if ( V_2 -> V_57 > 1 ) {
* exp = NULL ;
return 0 ;
}
V_17 = F_15 ( & V_56 , V_15 , V_53 ) ;
if ( V_17 ) {
F_12 ( L_11 , V_17 ) ;
return V_17 ;
}
* exp = F_16 ( & V_56 ) ;
F_17 ( * exp ) ;
V_2 -> exp = * exp ;
V_2 -> V_58 = 0 ;
V_2 -> V_53 = * V_53 ;
if ( V_38 )
V_2 -> V_40 = * V_38 ;
V_2 -> V_59 = F_18 ( L_12 ,
& V_15 -> V_60 ) ;
if ( V_38 && V_38 -> V_61 & V_62 )
V_17 = F_19 ( V_15 ) ;
if ( V_17 && V_2 -> V_59 )
F_20 ( V_2 -> V_59 ) ;
return V_17 ;
}
static int F_21 ( struct V_33 * exp , T_1 V_63 , T_1 V_64 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
T_1 V_16 ;
int V_17 = 0 ;
int V_65 = 0 ;
if ( V_2 -> V_66 < V_63 ) {
V_2 -> V_66 = V_63 ;
V_65 = 1 ;
}
if ( V_2 -> V_67 < V_64 ) {
V_2 -> V_67 = V_64 ;
V_65 = 1 ;
}
if ( V_65 == 0 )
return 0 ;
if ( V_2 -> V_58 == 0 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_7 . V_20 ; V_16 ++ ) {
struct V_3 * V_4 = V_2 -> V_21 [ V_16 ] ;
if ( ! V_4 || ! V_4 -> V_9 || ! V_4 -> V_6 ) {
F_22 ( L_13 , V_15 -> V_28 , V_16 ) ;
continue;
}
V_17 = F_23 ( V_4 -> V_9 , V_63 , V_64 ) ;
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
struct V_12 * V_53 = & V_2 -> V_53 ;
struct V_12 V_68 = { L_15 } ;
struct V_14 * V_69 ;
struct V_33 * V_70 ;
struct V_71 V_72 ;
int V_17 ;
V_69 = F_25 ( & V_4 -> V_22 , V_32 ,
& V_15 -> V_12 ) ;
if ( ! V_69 ) {
F_12 ( L_16 , V_4 -> V_22 . V_13 ) ;
return - V_25 ;
}
F_3 ( V_73 , L_17 ,
V_69 -> V_28 , V_69 -> V_12 . V_13 ,
V_4 -> V_22 . V_13 , V_15 -> V_12 . V_13 , V_53 -> V_13 ) ;
if ( ! V_69 -> V_74 ) {
F_12 ( L_18 , V_4 -> V_22 . V_13 ) ;
return - V_25 ;
}
V_17 = F_26 ( NULL , & V_70 , V_69 , & V_68 ,
& V_2 -> V_40 , NULL ) ;
if ( V_17 ) {
F_12 ( L_19 , V_4 -> V_22 . V_13 , V_17 ) ;
return V_17 ;
}
V_17 = F_27 ( V_69 , V_70 , V_75 ) ;
if ( V_17 )
return V_17 ;
V_72 . V_76 = NULL ;
V_72 . V_77 = V_70 ;
V_72 . V_78 = V_4 -> V_79 ;
F_28 ( & V_2 -> V_80 , & V_72 ) ;
V_17 = F_29 ( V_69 , V_15 ) ;
if ( V_17 ) {
F_30 ( V_70 ) ;
F_12 ( L_20 ,
V_4 -> V_22 . V_13 , V_17 ) ;
return V_17 ;
}
if ( V_15 -> V_50 ) {
V_17 = F_13 ( V_15 -> V_50 , V_70 -> V_10 ,
V_43 ,
( void * ) ( V_4 - V_2 -> V_21 [ 0 ] ) ) ;
if ( V_17 ) {
F_30 ( V_70 ) ;
return V_17 ;
}
}
V_4 -> V_6 = 1 ;
V_4 -> V_9 = V_70 ;
V_2 -> V_7 . V_8 ++ ;
F_23 ( V_4 -> V_9 , V_2 -> V_66 , V_2 -> V_67 ) ;
F_3 ( V_73 , L_21 ,
V_69 -> V_28 , V_69 -> V_12 . V_13 ,
F_31 ( & V_15 -> V_81 ) ) ;
if ( V_2 -> V_59 )
V_17 = F_32 ( V_2 -> V_59 , & V_69 -> V_60 ,
V_69 -> V_28 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 , int V_82 )
{
if ( ! V_2 -> V_21 [ V_82 ] )
return;
F_34 ( V_2 -> V_21 [ V_82 ] ) ;
V_2 -> V_21 [ V_82 ] = NULL ;
}
static int F_35 ( struct V_14 * V_15 , struct V_12 * V_83 ,
T_2 V_82 , int V_84 )
{
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_14 * V_69 ;
struct V_3 * V_4 ;
int V_85 = 0 ;
int V_17 = 0 ;
F_3 ( V_73 , L_22 , V_83 -> V_13 , V_82 ) ;
V_69 = F_25 ( V_83 , V_32 ,
& V_15 -> V_12 ) ;
if ( ! V_69 ) {
F_12 ( L_23 ,
V_15 -> V_28 , V_83 -> V_13 , - V_25 ) ;
return - V_25 ;
}
F_36 ( & V_2 -> V_86 ) ;
if ( ( V_82 < V_2 -> V_87 ) && V_2 -> V_21 [ V_82 ] ) {
V_4 = V_2 -> V_21 [ V_82 ] ;
F_12 ( L_24 ,
V_15 -> V_28 ,
F_37 ( & V_4 -> V_22 ) , V_82 , - V_88 ) ;
F_38 ( & V_2 -> V_86 ) ;
return - V_88 ;
}
if ( V_82 >= V_2 -> V_87 ) {
struct V_3 * * V_89 , * * V_90 = NULL ;
T_2 V_91 = 1 ;
T_2 V_92 = 0 ;
while ( V_91 < V_82 + 1 )
V_91 <<= 1 ;
V_89 = F_39 ( V_91 , sizeof( * V_89 ) , V_93 ) ;
if ( ! V_89 ) {
F_38 ( & V_2 -> V_86 ) ;
return - V_94 ;
}
if ( V_2 -> V_87 ) {
memcpy ( V_89 , V_2 -> V_21 ,
sizeof( * V_89 ) * V_2 -> V_87 ) ;
V_90 = V_2 -> V_21 ;
V_92 = V_2 -> V_87 ;
}
V_2 -> V_21 = V_89 ;
V_2 -> V_87 = V_91 ;
F_40 () ;
F_34 ( V_90 ) ;
F_3 ( V_73 , L_25 , V_2 -> V_21 ,
V_2 -> V_87 ) ;
}
V_4 = F_41 ( sizeof( * V_4 ) , V_93 ) ;
if ( ! V_4 ) {
F_38 ( & V_2 -> V_86 ) ;
return - V_94 ;
}
F_42 ( & V_4 -> V_95 ) ;
V_4 -> V_79 = V_82 ;
V_4 -> V_22 = * V_83 ;
V_4 -> V_6 = 0 ;
V_2 -> V_21 [ V_82 ] = V_4 ;
if ( V_82 >= V_2 -> V_7 . V_20 ) {
V_85 = V_2 -> V_7 . V_20 ;
V_2 -> V_7 . V_20 = V_82 + 1 ;
}
if ( ! V_2 -> V_58 ) {
F_38 ( & V_2 -> V_86 ) ;
return V_17 ;
}
F_38 ( & V_2 -> V_86 ) ;
V_17 = F_24 ( V_15 , V_4 ) ;
if ( V_17 ) {
F_4 ( & V_2 -> V_19 ) ;
if ( V_2 -> V_7 . V_20 == V_82 + 1 )
V_2 -> V_7 . V_20 = V_85 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_8 ( & V_2 -> V_19 ) ;
} else {
int V_63 = sizeof( struct V_96 ) +
V_2 -> V_7 . V_20 * sizeof( struct V_97 ) ;
F_21 ( V_15 -> V_48 , V_63 , 0 ) ;
}
return V_17 ;
}
int F_19 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
T_1 V_16 ;
int V_17 ;
int V_63 ;
if ( V_2 -> V_58 )
return 0 ;
F_36 ( & V_2 -> V_86 ) ;
if ( V_2 -> V_58 ) {
F_38 ( & V_2 -> V_86 ) ;
return 0 ;
}
if ( V_2 -> V_7 . V_20 == 0 ) {
F_38 ( & V_2 -> V_86 ) ;
F_12 ( L_26 , V_15 -> V_28 ) ;
return - V_25 ;
}
F_7 ( V_2 -> V_21 ) ;
if ( ! V_2 -> V_21 [ 0 ] ) {
F_38 ( & V_2 -> V_86 ) ;
F_12 ( L_27 ,
V_15 -> V_28 ) ;
return - V_25 ;
}
F_3 ( V_73 , L_28 ,
V_2 -> V_53 . V_13 , V_15 -> V_28 ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_7 . V_20 ; V_16 ++ ) {
V_4 = V_2 -> V_21 [ V_16 ] ;
if ( ! V_4 )
continue;
V_17 = F_24 ( V_15 , V_4 ) ;
if ( V_17 )
goto V_98;
}
F_43 ( V_2 -> exp ) ;
V_2 -> V_58 = 1 ;
V_63 = F_44 ( V_2 -> V_7 . V_20 , V_99 ) ;
F_21 ( V_15 -> V_48 , V_63 , 0 ) ;
F_38 ( & V_2 -> V_86 ) ;
return 0 ;
V_98:
while ( V_16 -- > 0 ) {
int V_100 ;
V_4 = V_2 -> V_21 [ V_16 ] ;
if ( ! V_4 )
continue;
V_4 -> V_6 = 0 ;
if ( V_4 -> V_9 ) {
-- V_2 -> V_7 . V_8 ;
V_100 = F_30 ( V_4 -> V_9 ) ;
if ( V_100 ) {
F_12 ( L_29 ,
V_4 -> V_22 . V_13 , V_16 , V_100 ) ;
}
}
}
F_45 ( V_2 -> exp ) ;
F_38 ( & V_2 -> V_86 ) ;
return V_17 ;
}
static int F_46 ( struct V_14 * V_15 , struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_14 * V_69 ;
int V_17 ;
V_69 = F_6 ( V_4 -> V_9 ) ;
if ( V_69 ) {
V_69 -> V_101 = V_15 -> V_101 ;
V_69 -> V_102 = V_15 -> V_102 ;
V_69 -> V_103 = V_15 -> V_103 ;
if ( V_2 -> V_59 )
F_47 ( V_2 -> V_59 ,
V_69 -> V_28 ) ;
}
V_17 = F_48 ( V_4 -> V_9 -> V_10 ) ;
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
static int F_49 ( struct V_33 * exp )
{
struct V_14 * V_15 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
int V_17 ;
T_1 V_16 ;
if ( ! V_2 -> V_21 )
goto V_104;
V_2 -> V_57 -- ;
if ( V_2 -> V_57 != 0 )
goto V_104;
for ( V_16 = 0 ; V_16 < V_2 -> V_7 . V_20 ; V_16 ++ ) {
if ( ! V_2 -> V_21 [ V_16 ] || ! V_2 -> V_21 [ V_16 ] -> V_9 )
continue;
F_46 ( V_15 , V_2 -> V_21 [ V_16 ] ) ;
}
if ( V_2 -> V_59 )
F_20 ( V_2 -> V_59 ) ;
V_104:
if ( ! V_2 -> V_58 )
F_43 ( exp ) ;
V_17 = F_45 ( exp ) ;
if ( V_2 -> V_57 == 0 )
V_2 -> V_58 = 0 ;
return V_17 ;
}
static int F_50 ( struct V_33 * exp , int V_105 , void * V_106 ,
void T_3 * V_107 )
{
struct V_14 * V_108 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_108 -> V_34 . V_2 ;
struct V_109 * V_110 ;
struct V_3 * V_4 ;
struct V_109 * V_111 = NULL ;
int V_112 = 0 ;
int V_17 ;
V_110 = V_106 ;
V_4 = F_51 ( V_2 , & V_110 -> V_113 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_114:
V_17 = F_54 ( V_115 , V_4 -> V_9 , V_105 , V_110 , V_107 ) ;
if ( V_17 != 0 && V_17 != - V_116 )
goto V_117;
if ( V_111 ) {
struct V_109 * V_118 ;
char * V_119 ;
V_118 = V_106 ;
if ( strlen ( V_118 -> V_120 ) +
strlen ( V_110 -> V_120 ) > V_118 -> V_121 ) {
V_17 = - V_122 ;
goto V_117;
}
V_119 = V_118 -> V_120 ;
memmove ( V_119 + strlen ( V_110 -> V_120 ) + 1 , V_119 ,
strlen ( V_118 -> V_120 ) ) ;
strncpy ( V_119 , V_110 -> V_120 , strlen ( V_110 -> V_120 ) ) ;
V_119 += strlen ( V_110 -> V_120 ) ;
* V_119 = '/' ;
}
F_3 ( V_18 , L_33 V_123 L_34 ,
V_4 -> V_9 -> V_10 -> V_28 ,
V_110 -> V_120 , F_55 ( & V_110 -> V_113 ) , V_110 -> V_124 ,
V_110 -> V_125 ) ;
if ( V_17 == 0 )
goto V_117;
if ( ! V_111 ) {
V_112 = sizeof( * V_111 ) + V_126 ;
V_111 = F_41 ( V_112 , V_93 ) ;
if ( ! V_111 ) {
V_17 = - V_94 ;
goto V_117;
}
V_111 -> V_121 = V_126 ;
}
if ( ! F_56 ( & V_110 -> V_113 ) ) {
F_12 ( L_35 V_123 L_36 ,
V_4 -> V_9 -> V_10 -> V_28 ,
F_55 ( & V_110 -> V_113 ) , - V_25 ) ;
V_17 = - V_25 ;
goto V_117;
}
V_4 = F_51 ( V_2 , & V_110 -> V_113 ) ;
if ( F_52 ( V_4 ) ) {
V_17 = - V_25 ;
goto V_117;
}
V_111 -> V_113 = V_110 -> V_113 ;
V_111 -> V_124 = - 1 ;
V_111 -> V_125 = - 1 ;
memset ( V_111 -> V_120 , 0 , V_111 -> V_121 ) ;
V_110 = V_111 ;
goto V_114;
V_117:
F_34 ( V_111 ) ;
return V_17 ;
}
static int F_57 ( struct V_1 * V_2 ,
const struct V_127 * V_128 ,
const struct V_3 * V_129 )
{
T_1 V_16 , V_130 = 0 ;
struct V_3 * V_131 ;
for ( V_16 = 0 ; V_16 < V_128 -> V_132 . V_133 ; V_16 ++ ) {
V_131 = F_51 ( V_2 , & V_128 -> V_134 [ V_16 ] . V_135 ) ;
if ( F_52 ( V_131 ) )
return F_53 ( V_131 ) ;
if ( F_5 ( & V_131 -> V_22 , & V_129 -> V_22 ) )
V_130 ++ ;
}
return V_130 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_127 * V_136 ,
const struct V_3 * V_129 ,
struct V_127 * V_137 )
{
int V_16 , V_138 ;
struct V_3 * V_131 ;
V_137 -> V_132 = V_136 -> V_132 ;
V_138 = 0 ;
for ( V_16 = 0 ; V_16 < V_136 -> V_132 . V_133 ; V_16 ++ ) {
V_131 = F_51 ( V_2 ,
& V_136 -> V_134 [ V_16 ] . V_135 ) ;
if ( F_52 ( V_131 ) )
return F_53 ( V_131 ) ;
if ( F_5 ( & V_131 -> V_22 , & V_129 -> V_22 ) ) {
V_137 -> V_134 [ V_138 ] =
V_136 -> V_134 [ V_16 ] ;
V_138 ++ ;
}
}
V_137 -> V_132 . V_133 = V_138 ;
memcpy ( F_59 ( V_137 ) , F_59 ( V_136 ) ,
V_136 -> V_132 . V_139 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 , unsigned int V_140 , int V_105 ,
struct V_141 * V_142 ,
void T_3 * V_107 )
{
T_2 V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_7 . V_20 ; V_16 ++ ) {
struct V_3 * V_4 = V_2 -> V_21 [ V_16 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
continue;
F_54 ( V_140 , V_2 -> V_21 [ V_16 ] -> V_9 , V_105 , V_142 , V_107 ) ;
}
return F_61 ( V_142 -> V_143 , V_142 -> V_144 ) ;
}
static int F_62 ( struct V_1 * V_2 , unsigned int V_140 , int V_105 ,
struct V_141 * V_142 , void T_3 * V_107 )
{
struct V_145 * V_146 ;
T_2 V_16 , V_147 ;
int V_148 , V_17 = 0 ;
bool V_149 = false ;
struct V_150 V_151 = { 0 } ;
for ( V_16 = 0 ; V_16 < V_2 -> V_7 . V_20 ; V_16 ++ ) {
struct V_3 * V_4 = V_2 -> V_21 [ V_16 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
continue;
V_148 = F_54 ( V_140 , V_4 -> V_9 , V_105 , V_142 , V_107 ) ;
if ( V_148 ) {
if ( V_4 -> V_6 ) {
F_12 ( L_37 ,
V_4 -> V_22 . V_13 , V_16 , V_140 , V_148 ) ;
V_17 = V_148 ;
V_142 -> V_152 |= V_153 ;
for ( V_147 = 0 ; V_147 < V_16 ; V_147 ++ ) {
V_4 = V_2 -> V_21 [ V_147 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
continue;
F_54 ( V_140 , V_4 -> V_9 , V_105 ,
V_142 , V_107 ) ;
}
return V_17 ;
}
} else {
V_149 = true ;
}
}
if ( ! V_149 )
return - V_27 ;
V_146 = F_63 ( V_142 -> V_154 ) ;
if ( ! V_146 )
return - V_155 ;
V_151 . V_156 = V_157 ;
V_151 . V_158 = V_2 -> V_53 ;
V_151 . V_159 = V_142 -> V_160 ;
V_17 = F_64 ( V_146 , V_142 -> V_143 , V_142 -> V_144 ,
& V_151 , sizeof( V_151 ) ) ;
if ( V_17 )
F_65 ( V_146 ) ;
return V_17 ;
}
static int F_66 ( unsigned int V_140 , struct V_33 * exp ,
int V_105 , void * V_106 , void T_3 * V_107 )
{
struct V_14 * V_108 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_108 -> V_34 . V_2 ;
struct V_3 * V_4 = NULL ;
T_1 V_16 = 0 ;
int V_17 = 0 ;
int V_161 = 0 ;
T_1 V_162 = V_2 -> V_7 . V_20 ;
if ( V_162 == 0 )
return - V_163 ;
switch ( V_140 ) {
case V_164 : {
struct V_165 * V_38 = V_106 ;
struct V_14 * V_69 ;
struct V_166 V_167 = { 0 } ;
T_2 V_82 ;
memcpy ( & V_82 , V_38 -> V_168 , sizeof( T_2 ) ) ;
if ( V_82 >= V_162 )
return - V_169 ;
V_4 = V_2 -> V_21 [ V_82 ] ;
if ( ! V_4 || ! V_4 -> V_6 )
return - V_170 ;
V_69 = F_6 ( V_4 -> V_9 ) ;
if ( ! V_69 )
return - V_25 ;
if ( F_67 ( V_38 -> V_171 , F_68 ( V_69 ) ,
F_69 ( ( int ) V_38 -> V_172 ,
( int ) sizeof( struct V_12 ) ) ) )
return - V_173 ;
V_17 = V_166 ( NULL , V_4 -> V_9 , & V_167 ,
F_70 ( - V_174 ) ,
0 ) ;
if ( V_17 )
return V_17 ;
if ( F_67 ( V_38 -> V_175 , & V_167 ,
F_69 ( ( int ) V_38 -> V_176 ,
( int ) sizeof( V_167 ) ) ) )
return - V_173 ;
break;
}
case V_177 : {
struct V_178 * V_179 = V_106 ;
struct V_180 * V_181 ;
if ( V_179 -> V_182 == V_183 ) {
if ( V_162 <= V_179 -> V_184 )
return - V_25 ;
V_4 = V_2 -> V_21 [ V_179 -> V_184 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
return - V_25 ;
} else if ( V_179 -> V_182 == V_185 ) {
for ( V_16 = 0 ; V_16 < V_162 ; V_16 ++ ) {
V_4 = V_2 -> V_21 [ V_16 ] ;
if ( ! V_4 )
continue;
if ( ! F_5 ( & V_4 -> V_22 ,
& V_179 -> V_12 ) )
continue;
if ( ! V_4 -> V_9 )
return - V_25 ;
break;
}
} else {
return - V_25 ;
}
if ( V_16 >= V_162 )
return - V_186 ;
F_7 ( V_4 && V_4 -> V_9 ) ;
V_181 = F_41 ( sizeof( * V_181 ) , V_93 ) ;
if ( ! V_181 )
return - V_94 ;
F_71 ( V_181 , V_179 ) ;
V_17 = V_180 ( V_4 -> V_9 , V_181 ) ;
if ( V_17 == 0 ) {
F_71 ( V_179 , V_181 ) ;
V_179 -> V_182 = V_183 ;
V_179 -> V_12 = V_4 -> V_22 ;
}
F_34 ( V_181 ) ;
break;
}
case V_187 :
case V_188 : {
struct V_189 * V_190 = V_106 ;
if ( V_190 -> V_191 >= V_162 )
return - V_169 ;
V_4 = V_2 -> V_21 [ V_190 -> V_191 ] ;
if ( ! V_4 || ! V_4 -> V_9 || ! V_4 -> V_6 )
return - V_169 ;
V_17 = F_54 ( V_140 , V_4 -> V_9 , sizeof( * V_190 ) , V_190 , NULL ) ;
break;
}
case V_192 : {
V_4 = V_2 -> V_21 [ 0 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
return - V_170 ;
V_17 = F_54 ( V_140 , V_4 -> V_9 , V_105 , V_106 , V_107 ) ;
break;
}
case V_193 : {
struct V_97 * V_194 = V_106 ;
int V_195 ;
V_17 = F_72 ( V_2 , V_194 , & V_195 ) ;
if ( V_17 )
return V_17 ;
* ( T_2 * ) V_107 = V_195 ;
break;
}
case V_115 : {
V_17 = F_50 ( exp , V_105 , V_106 , V_107 ) ;
break;
}
case V_196 :
case V_197 :
case V_198 : {
struct V_199 * V_200 = V_106 ;
V_4 = F_51 ( V_2 , & V_200 -> V_201 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
if ( ! V_4 -> V_9 )
return - V_25 ;
V_17 = F_54 ( V_140 , V_4 -> V_9 , V_105 , V_106 , V_107 ) ;
break;
}
case V_202 : {
const struct V_203 * V_204 = V_106 ;
V_4 = F_51 ( V_2 , & V_204 -> V_205 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_17 = F_54 ( V_140 , V_4 -> V_9 , V_105 , V_106 , V_107 ) ;
break;
}
case V_206 : {
struct V_127 * V_128 = V_106 ;
unsigned int V_207 = V_128 -> V_132 . V_133 ;
if ( V_207 == 0 )
return 0 ;
if ( V_207 == 1 || V_162 == 1 ) {
V_4 = F_51 ( V_2 ,
& V_128 -> V_134 [ 0 ] . V_135 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_17 = F_54 ( V_140 , V_4 -> V_9 , V_105 , V_106 , V_107 ) ;
} else {
for ( V_16 = 0 ; V_16 < V_162 ; V_16 ++ ) {
struct V_127 * V_208 ;
T_4 V_209 ;
int V_130 , V_210 ;
V_4 = V_2 -> V_21 [ V_16 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
continue;
V_130 = F_57 ( V_2 , V_128 , V_4 ) ;
if ( V_130 < 0 )
return V_130 ;
if ( V_130 == 0 )
continue;
V_209 = F_73 ( F_74 ( * V_128 ) ,
V_134 [ V_130 ] )
+ V_128 -> V_132 . V_139 ;
V_208 = F_75 ( V_209 , V_93 ) ;
if ( ! V_208 )
return - V_94 ;
V_210 = F_58 ( V_2 , V_128 , V_4 , V_208 ) ;
if ( V_210 < 0 )
goto V_211;
V_210 = F_54 ( V_140 , V_4 -> V_9 , V_209 ,
V_208 , V_107 ) ;
V_211:
if ( V_210 != 0 && V_17 == 0 )
V_17 = V_210 ;
F_76 ( V_208 ) ;
}
}
break;
}
case V_212 : {
struct V_199 * V_200 = V_106 ;
struct V_3 * V_213 , * V_214 ;
V_213 = F_51 ( V_2 , & V_200 -> V_201 ) ;
if ( F_52 ( V_213 ) )
return F_53 ( V_213 ) ;
V_214 = F_51 ( V_2 , & V_200 -> V_215 ) ;
if ( F_52 ( V_214 ) )
return F_53 ( V_214 ) ;
if ( ! V_213 -> V_9 || ! V_214 -> V_9 )
return - V_25 ;
if ( V_213 -> V_79 != V_214 -> V_79 )
return - V_216 ;
V_17 = F_54 ( V_140 , V_213 -> V_9 , V_105 , V_106 , V_107 ) ;
break;
}
case V_217 : {
struct V_141 * V_142 = V_106 ;
if ( V_142 -> V_152 & V_153 )
V_17 = F_60 ( V_2 , V_140 , V_105 , V_142 , V_107 ) ;
else
V_17 = F_62 ( V_2 , V_140 , V_105 , V_142 , V_107 ) ;
break;
}
default:
for ( V_16 = 0 ; V_16 < V_162 ; V_16 ++ ) {
struct V_14 * V_69 ;
int V_148 ;
V_4 = V_2 -> V_21 [ V_16 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
continue;
V_69 = F_6 ( V_4 -> V_9 ) ;
V_69 -> V_101 = V_108 -> V_101 ;
V_148 = F_54 ( V_140 , V_4 -> V_9 , V_105 , V_106 , V_107 ) ;
if ( V_148 ) {
if ( V_4 -> V_6 ) {
F_12 ( L_37 ,
V_4 -> V_22 . V_13 , V_16 , V_140 , V_148 ) ;
if ( ! V_17 )
V_17 = V_148 ;
}
} else {
V_161 = 1 ;
}
}
if ( ! V_161 && ! V_17 )
V_17 = - V_218 ;
}
return V_17 ;
}
static int F_77 ( struct V_14 * V_15 ,
struct V_199 * V_200 , T_1 * V_219 )
{
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
F_7 ( V_219 ) ;
if ( V_2 -> V_7 . V_20 == 1 ) {
* V_219 = 0 ;
return 0 ;
}
if ( V_200 -> V_220 != - 1 ) {
* V_219 = V_200 -> V_220 ;
return 0 ;
}
if ( V_200 -> V_221 & V_222 && V_200 -> V_200 ) {
struct V_223 * V_224 ;
V_224 = V_200 -> V_200 ;
if ( F_78 ( V_224 -> V_225 ) != ( T_2 ) - 1 ) {
* V_219 = F_78 ( V_224 -> V_225 ) ;
} else {
* V_219 = V_200 -> V_226 ;
V_224 -> V_225 = F_79 ( V_200 -> V_226 ) ;
}
} else {
* V_219 = V_200 -> V_226 ;
}
return 0 ;
}
int F_80 ( struct V_1 * V_2 , struct V_97 * V_194 , T_1 V_219 )
{
struct V_3 * V_4 ;
int V_17 ;
V_4 = F_81 ( V_2 , V_219 , NULL ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
F_36 ( & V_4 -> V_95 ) ;
if ( V_4 -> V_6 == 0 || ! V_4 -> V_9 ) {
V_17 = - V_169 ;
goto V_227;
}
V_17 = F_82 ( NULL , V_4 -> V_9 , V_194 , NULL ) ;
if ( V_17 > 0 ) {
F_7 ( F_56 ( V_194 ) ) ;
V_17 = 0 ;
}
V_227:
F_38 ( & V_4 -> V_95 ) ;
return V_17 ;
}
int F_83 ( const struct V_51 * V_52 , struct V_33 * exp ,
struct V_97 * V_194 , struct V_199 * V_200 )
{
struct V_14 * V_15 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
T_1 V_219 = 0 ;
int V_17 ;
F_7 ( V_200 ) ;
F_7 ( V_194 ) ;
V_17 = F_77 ( V_15 , V_200 , & V_219 ) ;
if ( V_17 ) {
F_12 ( L_38 ,
V_17 ) ;
return V_17 ;
}
V_17 = F_80 ( V_2 , V_194 , V_219 ) ;
if ( V_17 ) {
F_12 ( L_39 , V_17 ) ;
return V_17 ;
}
return V_17 ;
}
static int F_84 ( struct V_14 * V_15 , struct V_228 * V_229 )
{
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_230 V_231 = { NULL } ;
struct V_232 * V_7 ;
int V_17 ;
if ( F_85 ( V_229 , 1 ) < 1 ) {
F_12 ( L_40 ) ;
return - V_25 ;
}
V_7 = (struct V_232 * ) F_86 ( V_229 , 1 ) ;
if ( sizeof( * V_7 ) > F_85 ( V_229 , 1 ) ) {
F_12 ( L_41 ,
( int ) sizeof( * V_7 ) , F_85 ( V_229 , 1 ) ) ;
return - V_25 ;
}
V_2 -> V_87 = 32U ;
V_2 -> V_21 = F_39 ( V_2 -> V_87 , sizeof( * V_2 -> V_21 ) , V_93 ) ;
if ( ! V_2 -> V_21 )
return - V_94 ;
F_87 ( & V_2 -> V_7 . V_233 , V_7 -> V_233 . V_13 ) ;
V_2 -> V_7 . V_20 = 0 ;
V_2 -> V_7 . V_8 = 0 ;
V_2 -> V_67 = 0 ;
V_2 -> V_66 = 0 ;
F_88 ( & V_2 -> V_19 ) ;
F_42 ( & V_2 -> V_86 ) ;
F_89 ( & V_231 ) ;
F_90 ( V_15 , V_231 . V_234 , V_231 . V_235 ) ;
V_17 = F_91 ( V_15 -> V_236 , L_42 ,
0444 , & V_237 , V_15 ) ;
if ( V_17 )
F_22 ( L_43 ,
V_15 -> V_28 , V_17 ) ;
V_17 = F_92 ( & V_2 -> V_80 , V_15 -> V_28 ,
V_238 ) ;
if ( V_17 ) {
F_12 ( L_44 , V_17 ) ;
goto V_227;
}
return 0 ;
V_227:
return V_17 ;
}
static int F_93 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
F_94 ( & V_2 -> V_80 ) ;
if ( V_2 -> V_21 ) {
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_7 . V_20 ; V_16 ++ ) {
if ( ! V_2 -> V_21 [ V_16 ] )
continue;
F_33 ( V_2 , V_16 ) ;
}
F_34 ( V_2 -> V_21 ) ;
V_2 -> V_87 = 0 ;
}
return 0 ;
}
static int F_95 ( struct V_14 * V_15 , T_1 V_105 , void * V_239 )
{
struct V_228 * V_229 = V_239 ;
struct V_12 V_12 ;
int V_84 ;
T_2 V_82 ;
int V_17 ;
switch ( V_229 -> V_240 ) {
case V_241 :
if ( F_85 ( V_229 , 1 ) > sizeof( V_12 . V_13 ) ) {
V_17 = - V_25 ;
goto V_227;
}
F_87 ( & V_12 , F_86 ( V_229 , 1 ) ) ;
if ( sscanf ( F_86 ( V_229 , 2 ) , L_45 , & V_82 ) != 1 ) {
V_17 = - V_25 ;
goto V_227;
}
if ( sscanf ( F_86 ( V_229 , 3 ) , L_46 , & V_84 ) != 1 ) {
V_17 = - V_25 ;
goto V_227;
}
V_17 = F_35 ( V_15 , & V_12 , V_82 , V_84 ) ;
goto V_227;
default:
F_12 ( L_47 , V_229 -> V_240 ) ;
V_17 = - V_25 ;
goto V_227;
}
V_227:
return V_17 ;
}
static int F_96 ( const struct V_51 * V_52 , struct V_33 * exp ,
struct V_166 * V_242 , T_5 V_243 , T_2 V_244 )
{
struct V_14 * V_15 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_166 * V_245 ;
int V_17 = 0 ;
T_1 V_16 ;
V_17 = F_19 ( V_15 ) ;
if ( V_17 )
return V_17 ;
V_245 = F_41 ( sizeof( * V_245 ) , V_93 ) ;
if ( ! V_245 )
return - V_94 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_7 . V_20 ; V_16 ++ ) {
if ( ! V_2 -> V_21 [ V_16 ] || ! V_2 -> V_21 [ V_16 ] -> V_9 )
continue;
V_17 = V_166 ( V_52 , V_2 -> V_21 [ V_16 ] -> V_9 , V_245 ,
V_243 , V_244 ) ;
if ( V_17 ) {
F_12 ( L_48 , V_16 ,
V_2 -> V_21 [ V_16 ] -> V_9 -> V_10 -> V_28 ,
V_17 ) ;
goto V_246;
}
if ( V_16 == 0 ) {
* V_242 = * V_245 ;
if ( V_244 & V_247 )
goto V_246;
} else {
V_242 -> V_248 += V_245 -> V_248 ;
V_242 -> V_249 += V_245 -> V_249 ;
V_242 -> V_250 += V_245 -> V_250 ;
V_242 -> V_251 += V_245 -> V_251 ;
}
}
V_246:
F_34 ( V_245 ) ;
return V_17 ;
}
static int F_97 ( struct V_33 * exp ,
struct V_97 * V_194 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
int V_17 ;
V_17 = F_19 ( V_15 ) ;
if ( V_17 )
return V_17 ;
return F_98 ( V_2 -> V_21 [ 0 ] -> V_9 , V_194 ) ;
}
static int F_99 ( struct V_33 * exp , const struct V_97 * V_194 ,
T_6 V_252 , const char * V_253 ,
const char * V_254 , int V_255 , int V_256 ,
int V_244 , struct V_257 * * V_258 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_17 ;
V_17 = F_19 ( V_15 ) ;
if ( V_17 )
return V_17 ;
V_4 = F_51 ( V_2 , V_194 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
return F_100 ( V_4 -> V_9 , V_194 , V_252 , V_253 , V_254 ,
V_255 , V_256 , V_244 , V_258 ) ;
}
static int F_101 ( struct V_33 * exp , const struct V_97 * V_194 ,
T_6 V_252 , const char * V_253 ,
const char * V_254 , int V_255 , int V_256 ,
int V_244 , T_2 V_259 ,
struct V_257 * * V_258 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_17 ;
V_17 = F_19 ( V_15 ) ;
if ( V_17 )
return V_17 ;
V_4 = F_51 ( V_2 , V_194 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
return F_102 ( V_4 -> V_9 , V_194 , V_252 , V_253 , V_254 ,
V_255 , V_256 , V_244 , V_259 ,
V_258 ) ;
}
static int F_103 ( struct V_33 * exp , struct V_199 * V_200 ,
struct V_257 * * V_258 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_17 ;
V_17 = F_19 ( V_15 ) ;
if ( V_17 )
return V_17 ;
V_4 = F_51 ( V_2 , & V_200 -> V_201 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
if ( V_200 -> V_260 & V_261 ) {
V_200 -> V_226 = V_4 -> V_79 ;
return 0 ;
}
return F_104 ( V_4 -> V_9 , V_200 , V_258 ) ;
}
static int F_105 ( struct V_33 * exp , const struct V_97 * V_194 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
T_1 V_16 ;
int V_17 ;
V_17 = F_19 ( V_15 ) ;
if ( V_17 )
return V_17 ;
F_3 ( V_262 , L_49 V_123 L_50 , F_55 ( V_194 ) ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_7 . V_20 ; V_16 ++ ) {
if ( ! V_2 -> V_21 [ V_16 ] || ! V_2 -> V_21 [ V_16 ] -> V_9 )
continue;
F_106 ( V_2 -> V_21 [ V_16 ] -> V_9 , V_194 ) ;
}
return 0 ;
}
static int F_107 ( struct V_33 * exp , struct V_199 * V_200 ,
struct V_263 * V_264 , struct V_257 * * V_258 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_17 ;
V_17 = F_19 ( V_15 ) ;
if ( V_17 )
return V_17 ;
V_4 = F_51 ( V_2 , & V_200 -> V_201 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
F_3 ( V_262 , L_51 V_123 L_50 , F_55 ( & V_200 -> V_201 ) ) ;
return F_108 ( V_4 -> V_9 , V_200 , V_264 , V_258 ) ;
}
static struct V_3 *
F_109 ( struct V_1 * V_2 , struct V_96 * V_265 ,
const char * V_253 , int V_266 , struct V_97 * V_194 ,
T_1 * V_219 )
{
const struct V_267 * V_268 ;
struct V_3 * V_4 ;
if ( F_110 ( V_269 ) ) {
if ( V_270 >= V_265 -> V_271 )
return F_111 ( - V_155 ) ;
V_268 = & V_265 -> V_272 [ V_270 ] ;
} else {
V_268 = F_112 ( V_265 , V_253 , V_266 ) ;
if ( F_52 ( V_268 ) )
return F_113 ( V_268 ) ;
}
if ( V_194 )
* V_194 = V_268 -> V_273 ;
if ( V_219 )
* V_219 = V_268 -> V_274 ;
V_4 = F_81 ( V_2 , V_268 -> V_274 , NULL ) ;
F_3 ( V_18 , L_52 V_123 L_50 , V_268 -> V_274 ,
F_55 ( & V_268 -> V_273 ) ) ;
return V_4 ;
}
struct V_3 *
F_114 ( struct V_1 * V_2 , struct V_199 * V_200 ,
struct V_97 * V_194 )
{
struct V_96 * V_265 = V_200 -> V_275 ;
struct V_3 * V_4 ;
if ( V_200 -> V_276 & V_277 &&
( int ) V_200 -> V_226 != - 1 ) {
int V_16 ;
V_4 = F_81 ( V_2 , V_200 -> V_226 , NULL ) ;
if ( F_52 ( V_4 ) )
return V_4 ;
if ( V_265 ) {
for ( V_16 = 0 ; V_16 < V_265 -> V_271 ; V_16 ++ ) {
struct V_267 * V_268 ;
V_268 = & V_265 -> V_272 [ V_16 ] ;
if ( V_268 -> V_274 == V_200 -> V_226 ) {
* V_194 = V_268 -> V_273 ;
break;
}
}
if ( V_16 == V_265 -> V_271 )
* V_194 = V_265 -> V_272 [ 0 ] . V_273 ;
}
return V_4 ;
}
if ( ! V_265 || ! V_200 -> V_278 ) {
V_4 = F_51 ( V_2 , V_194 ) ;
if ( F_52 ( V_4 ) )
return V_4 ;
V_200 -> V_226 = V_4 -> V_79 ;
return V_4 ;
}
return F_109 ( V_2 , V_265 , V_200 -> V_279 ,
V_200 -> V_278 , V_194 ,
& V_200 -> V_226 ) ;
}
static int F_115 ( struct V_33 * exp , struct V_199 * V_200 ,
const void * V_38 , T_4 V_280 , T_7 V_281 ,
T_8 V_282 , T_9 V_283 , T_10 V_284 ,
T_5 V_285 , struct V_257 * * V_258 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_17 ;
V_17 = F_19 ( V_15 ) ;
if ( V_17 )
return V_17 ;
if ( ! V_2 -> V_7 . V_8 )
return - V_218 ;
V_4 = F_114 ( V_2 , V_200 , & V_200 -> V_201 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
F_3 ( V_262 , L_53 V_123 L_54 ,
( int ) V_200 -> V_278 , V_200 -> V_279 ,
F_55 ( & V_200 -> V_201 ) , V_200 -> V_226 ) ;
V_17 = F_83 ( NULL , exp , & V_200 -> V_215 , V_200 ) ;
if ( V_17 )
return V_17 ;
if ( F_116 ( exp ) & V_286 ) {
V_4 = F_51 ( V_2 , & V_200 -> V_215 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_200 -> V_226 = V_4 -> V_79 ;
} else {
F_3 ( V_73 , L_55 ) ;
}
F_3 ( V_262 , L_56 V_123 L_54 ,
F_55 ( & V_200 -> V_201 ) , V_200 -> V_226 ) ;
V_200 -> V_260 |= V_287 ;
V_17 = F_117 ( V_4 -> V_9 , V_200 , V_38 , V_280 , V_281 , V_282 , V_283 ,
V_284 , V_285 , V_258 ) ;
if ( V_17 == 0 ) {
if ( ! * V_258 )
return V_17 ;
F_3 ( V_262 , L_57 V_123 L_50 , F_55 ( & V_200 -> V_215 ) ) ;
}
return V_17 ;
}
static int
F_118 ( struct V_33 * exp , struct V_288 * V_289 ,
const union V_290 * V_291 ,
struct V_292 * V_293 , struct V_199 * V_200 ,
struct V_55 * V_294 , T_5 V_295 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_17 ;
V_17 = F_19 ( V_15 ) ;
if ( V_17 )
return V_17 ;
F_3 ( V_262 , L_58 V_123 L_50 ,
F_119 ( V_293 ) , F_55 ( & V_200 -> V_201 ) ) ;
V_4 = F_114 ( V_2 , V_200 , & V_200 -> V_201 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
F_3 ( V_262 , L_58 V_123 L_59 ,
F_119 ( V_293 ) , F_55 ( & V_200 -> V_201 ) , V_4 -> V_79 ) ;
return F_120 ( V_4 -> V_9 , V_289 , V_291 , V_293 , V_200 , V_294 ,
V_295 ) ;
}
static int
F_121 ( struct V_33 * exp , struct V_199 * V_200 ,
struct V_257 * * V_296 )
{
struct V_257 * V_208 = NULL ;
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
struct V_297 * V_298 ;
int V_17 ;
V_17 = F_19 ( V_15 ) ;
if ( V_17 )
return V_17 ;
V_4 = F_114 ( V_2 , V_200 , & V_200 -> V_201 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
F_3 ( V_262 , L_60 V_123 L_59 ,
( int ) V_200 -> V_278 , V_200 -> V_279 ,
F_55 ( & V_200 -> V_201 ) , V_4 -> V_79 ) ;
V_17 = F_122 ( V_4 -> V_9 , V_200 , V_296 ) ;
if ( V_17 != 0 )
return V_17 ;
V_298 = F_123 ( & ( * V_296 ) -> V_299 , & V_300 ) ;
if ( V_298 -> V_301 & V_302 ) {
struct V_97 V_303 = V_298 -> V_304 ;
F_3 ( V_262 , L_61 V_123 L_50 ,
F_55 ( & V_303 ) ) ;
V_4 = F_51 ( V_2 , & V_303 ) ;
if ( F_52 ( V_4 ) ) {
F_124 ( * V_296 ) ;
* V_296 = NULL ;
return F_53 ( V_4 ) ;
}
V_200 -> V_201 = V_303 ;
V_200 -> V_305 |= V_306 ;
V_200 -> V_278 = 0 ;
V_200 -> V_279 = NULL ;
V_17 = F_122 ( V_4 -> V_9 , V_200 , & V_208 ) ;
F_124 ( * V_296 ) ;
* V_296 = V_208 ;
}
return V_17 ;
}
static int F_125 ( struct V_33 * exp , struct V_3 * V_4 ,
struct V_199 * V_200 , int V_307 ,
enum V_308 V_281 , int V_309 , int V_310 )
{
struct V_97 * V_194 = F_126 ( V_200 , V_310 ) ;
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
union V_290 V_291 = { { 0 } } ;
int V_17 = 0 ;
if ( ! F_56 ( V_194 ) )
return 0 ;
if ( ! V_4 ) {
V_4 = F_51 ( V_2 , V_194 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
}
if ( V_4 -> V_79 != V_307 ) {
F_3 ( V_262 , L_62 V_123 L_50 , F_55 ( V_194 ) ) ;
V_291 . V_311 . V_309 = V_309 ;
V_17 = F_127 ( V_4 -> V_9 , V_194 , & V_291 ,
V_281 , V_312 , NULL ) ;
} else {
F_3 ( V_262 ,
L_63 V_123 L_50 ,
V_307 , F_55 ( V_194 ) ) ;
V_200 -> V_260 |= V_310 ;
V_17 = 0 ;
}
return V_17 ;
}
static int F_128 ( struct V_33 * exp , struct V_199 * V_200 ,
struct V_257 * * V_258 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_17 ;
V_17 = F_19 ( V_15 ) ;
if ( V_17 )
return V_17 ;
F_7 ( V_200 -> V_278 != 0 ) ;
F_3 ( V_262 , L_64 V_123 L_65 V_123 L_50 ,
F_55 ( & V_200 -> V_215 ) , ( int ) V_200 -> V_278 ,
V_200 -> V_279 , F_55 ( & V_200 -> V_201 ) ) ;
V_200 -> V_313 = F_129 ( & V_314 , F_130 () ) ;
V_200 -> V_315 = F_131 ( & V_314 , F_132 () ) ;
V_200 -> V_316 = F_133 () ;
if ( V_200 -> V_317 ) {
struct V_96 * V_265 = V_200 -> V_317 ;
const struct V_267 * V_268 ;
V_268 = F_112 ( V_265 , V_200 -> V_279 ,
V_200 -> V_278 ) ;
if ( F_52 ( V_268 ) )
return F_53 ( V_268 ) ;
V_200 -> V_215 = V_268 -> V_273 ;
}
V_4 = F_114 ( V_2 , V_200 , & V_200 -> V_215 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_200 -> V_260 |= V_318 ;
V_17 = F_125 ( exp , NULL , V_200 , V_4 -> V_79 , V_319 ,
V_320 , V_287 ) ;
if ( V_17 != 0 )
return V_17 ;
return F_134 ( V_4 -> V_9 , V_200 , V_258 ) ;
}
static int F_135 ( struct V_33 * exp , struct V_199 * V_200 ,
const char * V_90 , T_4 V_321 ,
const char * V_322 , T_4 V_323 ,
struct V_257 * * V_258 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_33 * V_324 ;
struct V_3 * V_325 ;
struct V_3 * V_326 ;
struct V_297 * V_298 ;
int V_17 ;
F_7 ( V_321 != 0 ) ;
F_3 ( V_262 , L_66 V_123 L_67 V_123 L_68 ,
( int ) V_321 , V_90 , F_55 ( & V_200 -> V_201 ) ,
V_200 -> V_275 ? V_200 -> V_275 -> V_271 : 0 ,
( int ) V_323 , V_322 , F_55 ( & V_200 -> V_215 ) ,
V_200 -> V_317 ? V_200 -> V_317 -> V_271 : 0 ) ;
V_17 = F_19 ( V_15 ) ;
if ( V_17 )
return V_17 ;
V_200 -> V_313 = F_129 ( & V_314 , F_130 () ) ;
V_200 -> V_315 = F_131 ( & V_314 , F_132 () ) ;
V_200 -> V_316 = F_133 () ;
if ( V_200 -> V_221 & V_327 ) {
F_136 ( F_56 ( & V_200 -> V_328 ) , L_69 V_123 L_50 ,
F_55 ( & V_200 -> V_328 ) ) ;
if ( V_200 -> V_275 ) {
struct V_96 * V_265 = V_200 -> V_275 ;
struct V_3 * V_329 ;
V_329 = F_109 ( V_2 , V_265 , V_90 ,
V_321 ,
& V_200 -> V_201 ,
NULL ) ;
if ( F_52 ( V_329 ) )
return F_53 ( V_329 ) ;
}
V_17 = F_83 ( NULL , exp , & V_200 -> V_215 , V_200 ) ;
if ( V_17 )
return V_17 ;
V_325 = F_51 ( V_2 , & V_200 -> V_328 ) ;
if ( F_52 ( V_325 ) )
return F_53 ( V_325 ) ;
V_324 = V_325 -> V_9 ;
} else {
if ( V_200 -> V_275 ) {
struct V_96 * V_265 = V_200 -> V_275 ;
V_325 = F_109 ( V_2 , V_265 , V_90 ,
V_321 ,
& V_200 -> V_201 ,
& V_200 -> V_226 ) ;
} else {
V_325 = F_51 ( V_2 , & V_200 -> V_201 ) ;
}
if ( F_52 ( V_325 ) )
return F_53 ( V_325 ) ;
if ( V_200 -> V_317 ) {
struct V_96 * V_265 = V_200 -> V_317 ;
V_326 = F_109 ( V_2 , V_265 , V_322 ,
V_323 ,
& V_200 -> V_215 ,
& V_200 -> V_226 ) ;
} else {
V_326 = F_51 ( V_2 , & V_200 -> V_215 ) ;
}
if ( F_52 ( V_326 ) )
return F_53 ( V_326 ) ;
V_324 = V_326 -> V_9 ;
}
V_200 -> V_260 |= V_287 | V_330 ;
V_17 = F_125 ( exp , NULL , V_200 , V_325 -> V_79 ,
V_319 , V_320 ,
V_318 ) ;
if ( V_17 )
return V_17 ;
if ( F_56 ( & V_200 -> V_328 ) ) {
struct V_3 * V_4 ;
V_4 = F_51 ( V_2 , & V_200 -> V_201 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_17 = F_125 ( exp , V_4 , V_200 , V_325 -> V_79 ,
V_319 , V_331 ,
V_330 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_125 ( exp , NULL , V_200 , V_325 -> V_79 ,
V_319 , V_332 ,
V_330 ) ;
if ( V_17 )
return V_17 ;
}
V_333:
if ( F_56 ( & V_200 -> V_334 ) ) {
struct V_3 * V_4 ;
V_17 = F_125 ( exp , NULL , V_200 , V_325 -> V_79 ,
V_319 , V_332 ,
V_335 ) ;
if ( V_17 )
return V_17 ;
V_4 = F_51 ( V_2 , & V_200 -> V_334 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_324 = V_4 -> V_9 ;
}
V_17 = F_137 ( V_324 , V_200 , V_90 , V_321 , V_322 , V_323 , V_258 ) ;
if ( V_17 && V_17 != - V_116 )
return V_17 ;
V_298 = F_123 ( & ( * V_258 ) -> V_299 , & V_300 ) ;
if ( ! V_298 )
return - V_336 ;
if ( F_138 ( ! ( V_298 -> V_301 & V_302 ) ) )
return V_17 ;
F_3 ( V_262 , L_70 V_123 L_50 ,
exp -> V_10 -> V_28 , F_55 ( & V_298 -> V_304 ) ) ;
V_200 -> V_334 = V_298 -> V_304 ;
F_124 ( * V_258 ) ;
* V_258 = NULL ;
goto V_333;
}
static int F_139 ( struct V_33 * exp , struct V_199 * V_200 ,
void * V_337 , T_4 V_338 , struct V_257 * * V_258 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_17 ;
V_17 = F_19 ( V_15 ) ;
if ( V_17 )
return V_17 ;
F_3 ( V_262 , L_71 V_123 L_72 ,
F_55 ( & V_200 -> V_201 ) , V_200 -> V_339 . V_340 ) ;
V_200 -> V_260 |= V_287 ;
V_4 = F_51 ( V_2 , & V_200 -> V_201 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
return F_140 ( V_4 -> V_9 , V_200 , V_337 , V_338 , V_258 ) ;
}
static int F_141 ( struct V_33 * exp , const struct V_97 * V_194 ,
struct V_257 * * V_258 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_17 ;
V_17 = F_19 ( V_15 ) ;
if ( V_17 )
return V_17 ;
V_4 = F_51 ( V_2 , V_194 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
return F_142 ( V_4 -> V_9 , V_194 , V_258 ) ;
}
static int F_143 ( struct V_33 * exp ,
struct V_199 * V_200 ,
struct V_341 * V_342 ,
T_5 V_343 , int * V_344 ,
struct V_345 * * V_346 ,
struct V_347 * * V_348 )
{
struct V_96 * V_265 = V_200 -> V_275 ;
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_345 * V_349 = NULL ;
struct V_347 * V_350 = NULL ;
struct V_3 * V_4 ;
int V_351 ;
int V_352 = 0 ;
int V_17 = 0 ;
int V_16 ;
V_351 = V_265 -> V_271 ;
for ( V_16 = 0 ; V_16 < V_351 ; V_16 ++ ) {
T_5 V_353 = V_343 ;
struct V_345 * V_354 = NULL ;
struct V_347 * V_347 = NULL ;
struct V_355 * V_356 ;
V_4 = F_81 ( V_2 , V_265 -> V_272 [ V_16 ] . V_274 , NULL ) ;
if ( F_52 ( V_4 ) ) {
V_17 = F_53 ( V_4 ) ;
goto V_227;
}
V_200 -> V_201 = V_265 -> V_272 [ V_16 ] . V_273 ;
V_200 -> V_215 = V_265 -> V_272 [ V_16 ] . V_273 ;
V_200 -> V_200 = V_265 -> V_272 [ V_16 ] . V_357 ;
V_358:
V_17 = F_144 ( V_4 -> V_9 , V_200 , V_342 , V_353 ,
& V_347 ) ;
if ( V_17 )
goto V_227;
V_356 = F_145 ( V_347 ) ;
for ( V_354 = F_146 ( V_356 ) ; V_354 ;
V_354 = F_147 ( V_354 ) ) {
if ( ! F_148 ( V_354 -> V_359 ) )
continue;
if ( F_149 ( V_354 -> V_360 ) < V_343 )
continue;
if ( F_149 ( V_354 -> V_360 ) == V_343 &&
( * V_346 == V_354 || V_16 < * V_344 ) )
continue;
if ( V_16 && ( ! strncmp ( V_354 -> V_361 , L_73 ,
F_148 ( V_354 -> V_359 ) ) ||
! strncmp ( V_354 -> V_361 , L_74 ,
F_148 ( V_354 -> V_359 ) ) ) )
continue;
break;
}
if ( ! V_354 ) {
V_353 = F_149 ( V_356 -> V_362 ) ;
F_150 ( V_347 ) ;
F_151 ( V_347 ) ;
V_347 = NULL ;
if ( V_353 == V_363 )
continue;
else
goto V_358;
}
if ( V_349 ) {
if ( F_149 ( V_349 -> V_360 ) >
F_149 ( V_354 -> V_360 ) ) {
V_349 = V_354 ;
F_150 ( V_350 ) ;
F_151 ( V_350 ) ;
V_352 = V_16 ;
V_350 = V_347 ;
} else {
F_150 ( V_347 ) ;
F_151 ( V_347 ) ;
V_347 = NULL ;
}
} else {
V_349 = V_354 ;
V_350 = V_347 ;
V_352 = V_16 ;
}
}
V_227:
if ( * V_348 ) {
F_150 ( * V_348 ) ;
F_151 ( * V_348 ) ;
}
* V_344 = V_352 ;
* V_346 = V_349 ;
* V_348 = V_350 ;
return V_17 ;
}
static int F_152 ( struct V_33 * exp ,
struct V_199 * V_200 ,
struct V_341 * V_342 ,
T_5 V_364 , struct V_347 * * V_348 )
{
struct V_365 * V_366 = V_200 -> V_200 ;
struct V_97 V_367 = V_200 -> V_201 ;
struct V_14 * V_15 = exp -> V_10 ;
T_5 V_343 = V_364 ;
T_2 V_368 ;
struct V_347 * V_369 = NULL ;
struct V_347 * V_370 = NULL ;
struct V_345 * V_349 = NULL ;
struct V_345 * V_371 ;
struct V_345 * V_354 ;
struct V_355 * V_356 ;
T_4 V_372 ;
int V_373 = 0 ;
void * V_374 ;
int V_17 ;
V_17 = F_19 ( V_15 ) ;
if ( V_17 )
return V_17 ;
V_370 = F_153 ( V_375 ) ;
if ( ! V_370 )
return - V_94 ;
V_356 = F_154 ( V_370 ) ;
memset ( V_356 , 0 , sizeof( * V_356 ) ) ;
V_356 -> V_376 = F_155 ( V_364 ) ;
V_368 = V_377 ;
V_374 = V_356 + 1 ;
V_372 = V_378 - sizeof( * V_356 ) ;
V_354 = V_374 ;
V_371 = V_354 ;
do {
T_11 V_379 ;
V_17 = F_143 ( exp , V_200 , V_342 , V_343 ,
& V_373 , & V_349 ,
& V_369 ) ;
if ( V_17 )
goto V_227;
if ( ! V_349 ) {
V_371 -> V_380 = 0 ;
V_343 = V_363 ;
goto V_227;
}
V_379 = F_148 ( V_349 -> V_380 ) ;
if ( ! V_379 )
V_379 = F_156 (
F_148 ( V_349 -> V_359 ) ,
F_78 ( V_349 -> V_381 ) ) ;
if ( V_379 > V_372 ) {
V_371 -> V_380 = F_157 ( 0 ) ;
V_343 = F_149 ( V_349 -> V_360 ) ;
goto V_227;
}
memcpy ( V_354 , V_349 , V_379 ) ;
if ( ! strncmp ( V_354 -> V_361 , L_73 ,
F_148 ( V_354 -> V_359 ) ) &&
F_148 ( V_354 -> V_359 ) == 1 )
F_158 ( & V_354 -> V_382 , & V_367 ) ;
else if ( ! strncmp ( V_354 -> V_361 , L_74 ,
F_148 ( V_354 -> V_359 ) ) &&
F_148 ( V_354 -> V_359 ) == 2 )
F_158 ( & V_354 -> V_382 , & V_200 -> V_328 ) ;
V_372 -= V_379 ;
V_354 -> V_380 = F_157 ( V_379 ) ;
V_371 = V_354 ;
V_354 = ( void * ) V_354 + V_379 ;
V_343 = F_149 ( V_349 -> V_360 ) ;
if ( V_343 == V_363 ) {
V_371 -> V_380 = 0 ;
break;
}
} while ( 1 );
V_227:
if ( V_369 ) {
F_150 ( V_369 ) ;
F_151 ( V_369 ) ;
}
if ( F_159 ( V_17 ) ) {
F_160 ( V_370 ) ;
V_370 = NULL ;
} else {
if ( V_354 == V_374 )
V_368 |= V_383 ;
V_356 -> V_368 |= F_79 ( V_368 ) ;
V_356 -> V_362 = F_155 ( V_343 ) ;
}
V_200 -> V_201 = V_367 ;
V_200 -> V_215 = V_367 ;
V_200 -> V_200 = V_366 ;
* V_348 = V_370 ;
return V_17 ;
}
static int F_161 ( struct V_33 * exp , struct V_199 * V_200 ,
struct V_341 * V_342 , T_5 V_364 ,
struct V_347 * * V_348 )
{
struct V_96 * V_265 = V_200 -> V_275 ;
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_17 ;
V_17 = F_19 ( V_15 ) ;
if ( V_17 )
return V_17 ;
if ( F_159 ( V_265 ) )
return F_152 ( exp , V_200 , V_342 , V_364 , V_348 ) ;
V_4 = F_51 ( V_2 , & V_200 -> V_201 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
return F_144 ( V_4 -> V_9 , V_200 , V_342 , V_364 , V_348 ) ;
}
static int F_162 ( struct V_33 * exp , struct V_199 * V_200 ,
struct V_257 * * V_258 )
{
struct V_96 * V_265 = V_200 -> V_275 ;
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_384 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_297 * V_298 ;
int V_385 = 0 ;
int V_17 ;
V_17 = F_19 ( V_15 ) ;
if ( V_17 )
return V_17 ;
V_386:
if ( V_265 ) {
struct V_3 * V_329 ;
F_7 ( V_200 -> V_279 && V_200 -> V_278 ) ;
V_329 = F_109 ( V_2 , V_265 ,
V_200 -> V_279 ,
V_200 -> V_278 ,
& V_200 -> V_201 ,
& V_200 -> V_226 ) ;
if ( F_52 ( V_329 ) && F_53 ( V_329 ) != - V_387 )
return F_53 ( V_329 ) ;
if ( ! F_163 ( V_265 -> V_388 ) ) {
struct V_267 * V_268 ;
V_268 = & V_265 -> V_272 [ V_385 ] ;
V_200 -> V_201 = V_268 -> V_273 ;
V_200 -> V_226 = V_268 -> V_274 ;
}
}
V_389:
if ( F_138 ( ! F_164 ( & V_200 -> V_215 ) ) )
V_4 = F_51 ( V_2 , & V_200 -> V_215 ) ;
else if ( V_265 )
V_4 = F_81 ( V_2 , V_200 -> V_226 , NULL ) ;
else
V_4 = F_114 ( V_2 , V_200 , & V_200 -> V_201 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_200 -> V_313 = F_129 ( & V_314 , F_130 () ) ;
V_200 -> V_315 = F_131 ( & V_314 , F_132 () ) ;
V_200 -> V_316 = F_133 () ;
V_200 -> V_260 |= V_287 | V_330 ;
V_384 = F_51 ( V_2 , & V_200 -> V_201 ) ;
if ( F_52 ( V_384 ) )
return F_53 ( V_384 ) ;
if ( V_384 != V_4 ) {
V_17 = F_125 ( exp , V_384 , V_200 , V_4 -> V_79 ,
V_319 , V_331 ,
V_330 ) ;
}
V_17 = F_125 ( exp , NULL , V_200 , V_4 -> V_79 , V_319 ,
V_332 , V_330 ) ;
if ( V_17 != 0 )
return V_17 ;
F_3 ( V_262 , L_75 V_123 L_76 V_123 L_59 ,
F_55 ( & V_200 -> V_201 ) , F_55 ( & V_200 -> V_215 ) , V_4 -> V_79 ) ;
V_17 = F_165 ( V_4 -> V_9 , V_200 , V_258 ) ;
if ( V_17 != 0 && V_17 != - V_116 && V_17 != - V_390 )
return V_17 ;
if ( V_17 == - V_390 && V_265 && F_166 ( V_265 ) ) {
struct V_267 * V_268 ;
V_385 ++ ;
if ( V_385 >= V_265 -> V_271 )
return V_17 ;
V_268 = & V_265 -> V_272 [ V_385 ] ;
V_200 -> V_201 = V_268 -> V_273 ;
V_200 -> V_226 = V_268 -> V_274 ;
F_124 ( * V_258 ) ;
* V_258 = NULL ;
goto V_389;
}
V_298 = F_123 ( & ( * V_258 ) -> V_299 , & V_300 ) ;
if ( ! V_298 )
return - V_336 ;
if ( F_138 ( ! ( V_298 -> V_301 & V_302 ) ) )
return V_17 ;
F_3 ( V_262 , L_77 V_123 L_50 ,
exp -> V_10 -> V_28 , F_55 ( & V_298 -> V_304 ) ) ;
V_200 -> V_215 = V_298 -> V_304 ;
F_124 ( * V_258 ) ;
* V_258 = NULL ;
goto V_386;
}
static int F_167 ( struct V_14 * V_15 )
{
F_168 ( & V_15 -> V_34 . V_2 . V_80 ) ;
F_169 ( V_15 ) ;
return 0 ;
}
static int F_170 ( const struct V_51 * V_52 , struct V_33 * exp ,
T_2 V_391 , void * V_392 , T_2 * V_393 , void * V_394 )
{
struct V_14 * V_15 ;
struct V_1 * V_2 ;
int V_17 = 0 ;
V_15 = F_6 ( exp ) ;
if ( ! V_15 ) {
F_3 ( V_395 , L_78 ,
exp -> V_23 . V_24 ) ;
return - V_25 ;
}
V_2 = & V_15 -> V_34 . V_2 ;
if ( V_391 >= strlen ( L_79 ) && ! strcmp ( V_392 , L_79 ) ) {
int V_16 ;
V_17 = F_19 ( V_15 ) ;
if ( V_17 )
return V_17 ;
F_7 ( * V_393 == sizeof( T_2 ) ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_7 . V_20 ; V_16 ++ ) {
struct V_3 * V_4 = V_2 -> V_21 [ V_16 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
continue;
if ( ! F_171 ( V_52 , V_4 -> V_9 , V_391 , V_392 ,
V_393 , V_394 ) )
return 0 ;
}
return - V_25 ;
} else if ( F_172 ( V_396 ) ||
F_172 ( V_397 ) ||
F_172 ( V_398 ) ) {
V_17 = F_19 ( V_15 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_171 ( V_52 , V_2 -> V_21 [ 0 ] -> V_9 , V_391 , V_392 ,
V_393 , V_394 ) ;
if ( ! V_17 && F_172 ( V_398 ) )
exp -> V_49 = * (struct V_39 * ) V_394 ;
return V_17 ;
} else if ( F_172 ( V_399 ) ) {
* ( ( int * ) V_394 ) = V_2 -> V_7 . V_20 ;
return 0 ;
}
F_3 ( V_395 , L_80 ) ;
return - V_25 ;
}
static int F_173 ( const struct V_51 * V_52 , struct V_33 * exp ,
T_1 V_391 , void * V_392 , T_1 V_393 ,
void * V_394 , struct V_400 * V_161 )
{
struct V_3 * V_4 ;
struct V_14 * V_15 ;
struct V_1 * V_2 ;
int V_17 = 0 ;
V_15 = F_6 ( exp ) ;
if ( ! V_15 ) {
F_3 ( V_395 , L_78 ,
exp -> V_23 . V_24 ) ;
return - V_25 ;
}
V_2 = & V_15 -> V_34 . V_2 ;
if ( F_172 ( V_401 ) || F_172 ( V_402 ) ||
F_172 ( V_397 ) ) {
int V_16 , V_148 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_7 . V_20 ; V_16 ++ ) {
V_4 = V_2 -> V_21 [ V_16 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
continue;
V_148 = F_174 ( V_52 , V_4 -> V_9 ,
V_391 , V_392 , V_393 , V_394 , V_161 ) ;
if ( V_148 && V_17 == 0 )
V_17 = V_148 ;
}
return V_17 ;
}
return - V_25 ;
}
static int F_175 ( struct V_33 * exp , struct V_96 * V_265 ,
const struct V_403 * V_404 )
{
struct V_1 * V_2 = & exp -> V_10 -> V_34 . V_2 ;
int V_351 ;
int V_17 = 0 ;
int V_405 ;
int V_16 ;
V_265 -> V_406 = F_78 ( V_404 -> V_407 ) ;
V_265 -> V_271 = F_78 ( V_404 -> V_408 ) ;
V_265 -> V_409 = F_78 ( V_404 -> V_410 ) ;
if ( F_110 ( V_411 ) )
V_265 -> V_388 = V_412 ;
else
V_265 -> V_388 = F_78 ( V_404 -> V_413 ) ;
V_265 -> V_414 = F_78 ( V_404 -> V_415 ) ;
V_405 = F_176 ( V_265 -> V_416 , V_404 -> V_417 ,
sizeof( V_265 -> V_416 ) ) ;
if ( V_405 >= sizeof( V_265 -> V_416 ) )
return - V_418 ;
F_3 ( V_18 , L_81 ,
V_265 -> V_271 , V_265 -> V_409 ,
V_265 -> V_388 , V_265 -> V_414 ) ;
V_351 = F_78 ( V_404 -> V_408 ) ;
for ( V_16 = 0 ; V_16 < V_351 ; V_16 ++ ) {
F_177 ( & V_265 -> V_272 [ V_16 ] . V_273 ,
& V_404 -> V_419 [ V_16 ] ) ;
V_17 = F_72 ( V_2 , & V_265 -> V_272 [ V_16 ] . V_273 ,
& V_265 -> V_272 [ V_16 ] . V_274 ) ;
if ( V_17 )
return V_17 ;
F_3 ( V_18 , L_82 V_123 L_50 , V_16 ,
F_55 ( & V_265 -> V_272 [ V_16 ] . V_273 ) ) ;
}
return V_17 ;
}
static int F_178 ( struct V_33 * exp , struct V_96 * * V_420 ,
const union V_421 * V_422 , T_4 V_423 )
{
struct V_96 * V_265 ;
bool V_424 = false ;
int V_425 , V_17 ;
F_7 ( V_420 ) ;
V_265 = * V_420 ;
if ( V_265 && ! V_422 ) {
int V_16 ;
for ( V_16 = 1 ; V_16 < V_265 -> V_271 ; V_16 ++ ) {
if ( ! ( V_265 -> V_388 & V_426 &&
! V_16 ) && V_265 -> V_272 [ V_16 ] . V_357 )
F_179 ( V_265 -> V_272 [ V_16 ] . V_357 ) ;
}
F_76 ( V_265 ) ;
* V_420 = NULL ;
return 0 ;
}
if ( F_78 ( V_422 -> V_407 ) == V_427 )
return - V_216 ;
if ( F_78 ( V_422 -> V_407 ) != V_428 &&
F_78 ( V_422 -> V_407 ) != V_429 ) {
F_12 ( L_83 ,
exp -> V_10 -> V_28 , F_78 ( V_422 -> V_407 ) ,
- V_218 ) ;
return - V_218 ;
}
if ( F_78 ( V_422 -> V_407 ) == V_428 )
V_425 = F_180 ( F_181 ( V_422 ) ) ;
else
V_425 = F_180 ( 0 ) ;
if ( ! V_265 ) {
V_265 = F_75 ( V_425 , V_93 ) ;
if ( ! V_265 )
return - V_94 ;
V_424 = true ;
* V_420 = V_265 ;
}
switch ( F_78 ( V_422 -> V_407 ) ) {
case V_428 :
V_17 = F_175 ( exp , V_265 , & V_422 -> V_430 ) ;
break;
default:
F_12 ( L_84 , exp -> V_10 -> V_28 ,
F_78 ( V_422 -> V_407 ) ) ;
V_17 = - V_25 ;
break;
}
if ( V_17 && V_424 ) {
F_76 ( V_265 ) ;
* V_420 = NULL ;
V_425 = V_17 ;
}
return V_425 ;
}
void F_182 ( struct V_96 * V_265 )
{
F_178 ( NULL , & V_265 , NULL , 0 ) ;
}
static int F_183 ( struct V_33 * exp , const struct V_97 * V_194 ,
union V_290 * V_291 ,
enum V_308 V_281 , enum V_431 V_244 ,
void * V_432 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
int V_17 = 0 ;
int V_148 ;
T_1 V_16 ;
F_7 ( V_194 ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_7 . V_20 ; V_16 ++ ) {
struct V_3 * V_4 = V_2 -> V_21 [ V_16 ] ;
if ( ! V_4 || ! V_4 -> V_9 || ! V_4 -> V_6 )
continue;
V_148 = F_127 ( V_4 -> V_9 , V_194 , V_291 , V_281 , V_244 ,
V_432 ) ;
if ( ! V_17 )
V_17 = V_148 ;
}
return V_17 ;
}
static int F_184 ( struct V_33 * exp ,
const struct V_55 * V_294 ,
void * V_38 , T_5 * V_309 )
{
struct V_1 * V_2 = & exp -> V_10 -> V_34 . V_2 ;
struct V_3 * V_4 = V_2 -> V_21 [ 0 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
return - V_25 ;
return F_185 ( V_4 -> V_9 , V_294 , V_38 , V_309 ) ;
}
static enum V_308 F_186 ( struct V_33 * exp , T_5 V_244 ,
const struct V_97 * V_194 ,
enum V_433 type ,
union V_290 * V_291 ,
enum V_308 V_281 ,
struct V_55 * V_294 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
enum V_308 V_17 ;
int V_4 ;
T_1 V_16 ;
F_3 ( V_262 , L_85 V_123 L_50 , F_55 ( V_194 ) ) ;
for ( V_16 = 0 , V_4 = F_187 ( V_2 , V_194 ) ;
V_16 < V_2 -> V_7 . V_20 ;
V_16 ++ , V_4 = ( V_4 + 1 ) % V_2 -> V_7 . V_20 ) {
if ( V_4 < 0 ) {
F_3 ( V_434 , L_86 V_123 L_87 ,
V_15 -> V_28 , F_55 ( V_194 ) , V_4 ) ;
V_4 = 0 ;
}
if ( ! V_2 -> V_21 [ V_4 ] || ! V_2 -> V_21 [ V_4 ] -> V_9 ||
! V_2 -> V_21 [ V_4 ] -> V_6 )
continue;
V_17 = F_188 ( V_2 -> V_21 [ V_4 ] -> V_9 , V_244 , V_194 ,
type , V_291 , V_281 , V_294 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static int F_189 ( struct V_33 * exp ,
struct V_257 * V_208 ,
struct V_33 * V_435 ,
struct V_33 * V_436 ,
struct V_437 * V_438 )
{
struct V_1 * V_2 = & exp -> V_10 -> V_34 . V_2 ;
struct V_3 * V_4 = V_2 -> V_21 [ 0 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
return - V_25 ;
return F_190 ( V_4 -> V_9 , V_208 , V_435 , V_436 , V_438 ) ;
}
static int F_191 ( struct V_33 * exp , struct V_437 * V_438 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 = V_2 -> V_21 [ 0 ] ;
if ( V_438 -> V_2 ) {
F_182 ( V_438 -> V_2 ) ;
V_438 -> V_2 = NULL ;
}
if ( ! V_4 || ! V_4 -> V_9 )
return - V_25 ;
return F_192 ( V_4 -> V_9 , V_438 ) ;
}
static int F_193 ( struct V_33 * exp ,
struct V_439 * V_440 ,
struct V_292 * V_293 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
V_4 = F_51 ( V_2 , & V_440 -> V_441 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
return F_194 ( V_4 -> V_9 , V_440 , V_293 ) ;
}
static int F_195 ( struct V_33 * exp ,
struct V_439 * V_440 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
V_4 = F_51 ( V_2 , & V_440 -> V_441 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
return F_196 ( V_4 -> V_9 , V_440 ) ;
}
static int F_197 ( struct V_33 * exp ,
struct V_442 * V_443 )
{
struct V_199 * V_200 = & V_443 -> V_444 ;
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_445 = NULL ;
struct V_3 * V_446 = NULL ;
int V_17 ;
if ( ! F_56 ( & V_200 -> V_215 ) )
return - V_25 ;
V_17 = F_19 ( V_15 ) ;
if ( V_17 )
return V_17 ;
V_445 = F_114 ( V_2 , V_200 , & V_200 -> V_201 ) ;
if ( F_52 ( V_445 ) )
return F_53 ( V_445 ) ;
V_446 = F_114 ( V_2 , V_200 , & V_200 -> V_215 ) ;
if ( F_52 ( V_446 ) )
return F_53 ( V_446 ) ;
if ( V_445 != V_446 )
return - V_447 ;
return F_198 ( V_445 -> V_9 , V_443 ) ;
}
static int F_199 ( struct V_33 * exp , struct V_292 * V_293 ,
struct V_97 * V_194 , T_5 * V_309 )
{
struct V_14 * V_15 = exp -> V_10 ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_17 ;
V_17 = F_19 ( V_15 ) ;
if ( V_17 )
return V_17 ;
V_4 = F_51 ( V_2 , V_194 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
return F_200 ( V_4 -> V_9 , V_293 , V_194 , V_309 ) ;
}
static int
F_201 ( struct V_33 * exp ,
const struct V_96 * V_265 ,
const char * V_253 , int V_266 , struct V_97 * V_194 )
{
const struct V_267 * V_268 ;
F_7 ( V_265 ) ;
V_268 = F_112 ( V_265 , V_253 , V_266 ) ;
if ( F_52 ( V_268 ) )
return F_53 ( V_268 ) ;
* V_194 = V_268 -> V_273 ;
return 0 ;
}
static int F_202 ( struct V_14 * V_448 , struct V_33 * exp ,
struct V_180 * V_181 )
{
struct V_14 * V_15 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_15 -> V_34 . V_2 ;
struct V_3 * V_4 = V_2 -> V_21 [ 0 ] ;
int V_17 = 0 ;
T_5 V_449 = 0 , V_450 = 0 ;
T_1 V_16 ;
if ( ! V_4 || ! V_4 -> V_9 || ! V_4 -> V_6 ||
! V_2 -> V_7 . V_20 ) {
F_12 ( L_88 ) ;
return - V_218 ;
}
if ( V_181 -> V_451 != V_452 )
return V_180 ( V_4 -> V_9 , V_181 ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_7 . V_20 ; V_16 ++ ) {
int V_148 ;
V_4 = V_2 -> V_21 [ V_16 ] ;
if ( ! V_4 || ! V_4 -> V_9 || ! V_4 -> V_6 )
continue;
V_148 = V_180 ( V_4 -> V_9 , V_181 ) ;
if ( V_148 ) {
F_12 ( L_89 , V_16 , V_148 ) ;
if ( ! V_17 )
V_17 = V_148 ;
} else {
V_449 += V_181 -> V_453 . V_454 ;
V_450 += V_181 -> V_453 . V_455 ;
}
}
V_181 -> V_453 . V_454 = V_449 ;
V_181 -> V_453 . V_455 = V_450 ;
return V_17 ;
}
static int F_203 ( struct V_33 * exp ,
const struct V_96 * V_265 ,
struct V_456 * V_457 ,
T_12 V_458 )
{
int V_17 , V_16 ;
V_17 = F_204 ( exp , V_265 , V_458 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
for ( V_16 = 0 ; V_16 < V_265 -> V_271 ; V_16 ++ ) {
struct V_365 * V_365 = V_265 -> V_272 [ V_16 ] . V_357 ;
F_3 ( V_18 , L_5 V_123 L_90 ,
F_55 ( & V_265 -> V_272 [ V_16 ] . V_273 ) ,
F_205 ( V_365 ) , ( unsigned long long ) V_365 -> V_459 ,
V_365 -> V_460 , F_206 ( V_365 -> V_461 ) ,
F_206 ( V_365 -> V_462 ) , F_206 ( V_365 -> V_463 ) ) ;
if ( V_16 )
V_457 -> V_464 += V_365 -> V_460 - 2 ;
else
V_457 -> V_464 = V_365 -> V_460 ;
V_457 -> V_465 += F_205 ( V_365 ) ;
V_457 -> V_466 += V_365 -> V_459 ;
if ( V_457 -> V_467 < F_206 ( V_365 -> V_461 ) )
V_457 -> V_467 = F_206 ( V_365 -> V_461 ) ;
if ( V_457 -> V_468 < F_206 ( V_365 -> V_462 ) )
V_457 -> V_468 = F_206 ( V_365 -> V_462 ) ;
if ( V_457 -> V_469 < F_206 ( V_365 -> V_463 ) )
V_457 -> V_469 = F_206 ( V_365 -> V_463 ) ;
}
return 0 ;
}
static int T_13 F_207 ( void )
{
struct V_230 V_231 ;
F_89 ( & V_231 ) ;
return F_208 ( & V_470 , & V_471 ,
V_472 , NULL ) ;
}
static void F_209 ( void )
{
F_210 ( V_472 ) ;
}
