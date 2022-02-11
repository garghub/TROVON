static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
if ( V_4 -> V_6 == V_5 )
return;
V_4 -> V_6 = V_5 ;
V_2 -> V_7 . V_8 += ( V_5 ? 1 : - 1 ) ;
}
static int F_2 ( struct V_1 * V_2 , struct V_9 * V_10 ,
int V_5 )
{
struct V_3 * V_11 ( V_4 ) ;
struct V_12 * V_13 ;
int V_14 ;
int V_15 = 0 ;
F_3 ( V_16 , L_1 ,
V_2 , V_10 -> V_10 , V_5 ) ;
F_4 ( & V_2 -> V_17 ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL || V_4 -> V_20 == NULL )
continue;
F_3 ( V_16 , L_2 V_21 L_3 , V_14 ,
V_4 -> V_22 . V_10 , V_4 -> V_20 -> V_23 . V_24 ) ;
if ( F_5 ( V_10 , & V_4 -> V_22 ) )
break;
}
if ( V_14 == V_2 -> V_7 . V_18 )
GOTO ( V_25 , V_15 = - V_26 ) ;
V_13 = F_6 ( V_4 -> V_20 ) ;
if ( V_13 == NULL )
GOTO ( V_25 , V_15 = - V_27 ) ;
F_3 ( V_16 , L_4 ,
V_13 -> V_28 , V_13 -> V_9 . V_10 , V_13 -> V_29 , V_13 ,
V_13 -> V_30 -> V_31 , V_14 ) ;
F_7 ( strcmp ( V_13 -> V_30 -> V_31 , V_32 ) == 0 ) ;
if ( V_4 -> V_6 == V_5 ) {
F_3 ( V_16 , L_5 , V_13 ,
V_5 ? L_6 : L_7 ) ;
GOTO ( V_25 , V_15 ) ;
}
F_3 ( V_16 , L_8 , V_13 ,
V_5 ? L_6 : L_7 ) ;
F_1 ( V_2 , V_4 , V_5 ) ;
V_25:
F_8 ( & V_2 -> V_17 ) ;
return V_15 ;
}
struct V_9 * F_9 ( struct V_33 * exp )
{
struct V_1 * V_2 = & exp -> V_34 -> V_35 . V_2 ;
return F_10 ( V_2 -> V_19 [ 0 ] -> V_20 ) ;
}
static int F_11 ( struct V_12 * V_13 , struct V_12 * V_36 ,
enum V_37 V_38 , void * V_39 )
{
struct V_40 * V_41 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_9 * V_10 ;
int V_15 = 0 ;
if ( strcmp ( V_36 -> V_30 -> V_31 , V_32 ) ) {
F_12 ( L_9 ,
V_36 -> V_30 -> V_31 ,
V_36 -> V_28 ) ;
return - V_26 ;
}
V_10 = & V_36 -> V_35 . V_42 . V_43 ;
if ( V_38 == V_44 || V_38 == V_45 ) {
V_15 = F_2 ( V_2 , V_10 ,
V_38 == V_44 ) ;
if ( V_15 ) {
F_12 ( L_10 ,
V_38 == V_44 ? L_6 : L_11 ,
V_10 -> V_10 , V_15 ) ;
return V_15 ;
}
} else if ( V_38 == V_46 ) {
V_41 = & V_36 -> V_35 . V_42 . V_47 -> V_48 ;
V_13 -> V_49 -> V_50 = * V_41 ;
}
#if 0
else if (ev == OBD_NOTIFY_DISCON) {
fld_client_flush(&lmv->lmv_fld);
}
#endif
if ( V_13 -> V_51 )
V_15 = F_13 ( V_13 -> V_51 , V_36 , V_38 , V_39 ) ;
return V_15 ;
}
static int F_14 ( const struct V_52 * V_53 ,
struct V_33 * * exp , struct V_12 * V_13 ,
struct V_9 * V_54 , struct V_40 * V_39 ,
void * V_55 )
{
struct V_56 * V_57 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_58 V_59 = { 0 } ;
int V_15 = 0 ;
V_2 -> V_60 ++ ;
if ( V_2 -> V_60 > 1 ) {
* exp = NULL ;
return 0 ;
}
V_15 = F_15 ( & V_59 , V_13 , V_54 ) ;
if ( V_15 ) {
F_12 ( L_12 , V_15 ) ;
return V_15 ;
}
* exp = F_16 ( & V_59 ) ;
F_17 ( * exp ) ;
V_2 -> exp = * exp ;
V_2 -> V_61 = 0 ;
V_2 -> V_54 = * V_54 ;
if ( V_39 )
V_2 -> V_41 = * V_39 ;
if ( V_13 -> V_62 != NULL ) {
V_57 = V_13 -> V_62 ;
} else {
V_57 = F_18 ( L_13 , V_13 -> V_63 ,
NULL , NULL ) ;
if ( F_19 ( V_57 ) ) {
F_12 ( L_14 ,
V_13 -> V_30 -> V_31 , V_13 -> V_28 ) ;
V_57 = NULL ;
}
V_13 -> V_62 = V_57 ;
}
if ( V_39 -> V_64 & V_65 )
V_15 = F_20 ( V_13 ) ;
if ( V_15 && V_57 ) {
F_21 ( & V_57 ) ;
V_13 -> V_62 = NULL ;
}
return V_15 ;
}
static void F_22 ( struct V_12 * V_13 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_14 ;
V_2 = & V_13 -> V_35 . V_2 ;
if ( V_2 -> V_66 == 0 )
return;
if ( V_2 -> V_61 == 0 )
return;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL || V_4 -> V_20 == NULL || V_4 -> V_6 == 0 )
continue;
F_23 ( NULL , V_4 -> V_20 , sizeof( V_67 ) ,
V_67 , 0 , NULL , NULL ) ;
}
}
static int F_24 ( struct V_33 * exp , int V_68 ,
int V_69 , int V_70 , int V_71 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
int V_14 ;
int V_15 = 0 ;
int V_72 = 0 ;
if ( V_2 -> V_73 < V_68 ) {
V_2 -> V_73 = V_68 ;
V_72 = 1 ;
}
if ( V_2 -> V_74 < V_69 ) {
V_2 -> V_74 = V_69 ;
V_72 = 1 ;
}
if ( V_2 -> V_75 < V_70 ) {
V_2 -> V_75 = V_70 ;
V_72 = 1 ;
}
if ( V_2 -> V_76 < V_71 ) {
V_2 -> V_76 = V_71 ;
V_72 = 1 ;
}
if ( V_72 == 0 )
return 0 ;
if ( V_2 -> V_61 == 0 )
return 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL ||
V_2 -> V_19 [ V_14 ] -> V_20 == NULL ||
V_2 -> V_19 [ V_14 ] -> V_6 == 0 ) {
F_25 ( L_15 , V_13 -> V_28 , V_14 ) ;
continue;
}
V_15 = F_26 ( V_2 -> V_19 [ V_14 ] -> V_20 , V_68 , V_69 ,
V_70 , V_71 ) ;
if ( V_15 ) {
F_12 ( L_16
L_17 , V_13 -> V_28 , V_14 , V_15 ) ;
break;
}
}
return V_15 ;
}
int F_27 ( struct V_12 * V_13 , struct V_3 * V_4 )
{
struct V_56 * V_57 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_9 * V_54 = & V_2 -> V_54 ;
struct V_9 V_77 = { L_18 } ;
struct V_12 * V_78 ;
struct V_33 * V_79 ;
struct V_80 V_81 ;
int V_15 ;
V_78 = F_28 ( & V_4 -> V_22 , V_32 ,
& V_13 -> V_9 ) ;
if ( ! V_78 ) {
F_12 ( L_19 , V_4 -> V_22 . V_10 ) ;
return - V_26 ;
}
F_3 ( V_82 , L_20 ,
V_78 -> V_28 , V_78 -> V_9 . V_10 ,
V_4 -> V_22 . V_10 , V_13 -> V_9 . V_10 ,
V_54 -> V_10 ) ;
if ( ! V_78 -> V_83 ) {
F_12 ( L_21 , V_4 -> V_22 . V_10 ) ;
return - V_26 ;
}
V_15 = F_29 ( NULL , & V_79 , V_78 , & V_77 ,
& V_2 -> V_41 , NULL ) ;
if ( V_15 ) {
F_12 ( L_22 , V_4 -> V_22 . V_10 , V_15 ) ;
return V_15 ;
}
V_15 = F_30 ( V_78 , V_79 , V_84 ) ;
if ( V_15 )
return V_15 ;
V_81 . V_85 = NULL ;
V_81 . V_86 = V_79 ;
V_81 . V_87 = V_4 -> V_88 ;
F_31 ( & V_2 -> V_89 , & V_81 ) ;
V_15 = F_32 ( V_78 , V_13 ) ;
if ( V_15 ) {
F_33 ( V_79 ) ;
F_12 ( L_23 ,
V_4 -> V_22 . V_10 , V_15 ) ;
return V_15 ;
}
if ( V_13 -> V_51 ) {
V_15 = F_13 ( V_13 -> V_51 , V_79 -> V_34 ,
V_44 ,
( void * ) ( V_4 - V_2 -> V_19 [ 0 ] ) ) ;
if ( V_15 ) {
F_33 ( V_79 ) ;
return V_15 ;
}
}
V_4 -> V_6 = 1 ;
V_4 -> V_20 = V_79 ;
V_2 -> V_7 . V_8 ++ ;
F_26 ( V_4 -> V_20 , V_2 -> V_73 , V_2 -> V_74 ,
V_2 -> V_75 , V_2 -> V_76 ) ;
F_3 ( V_82 , L_24 ,
V_78 -> V_28 , V_78 -> V_9 . V_10 ,
F_34 ( & V_13 -> V_90 ) ) ;
V_57 = V_13 -> V_62 ;
if ( V_57 ) {
struct V_56 * V_91 ;
F_7 ( V_78 -> V_30 != NULL ) ;
F_7 ( V_78 -> V_30 -> V_31 != NULL ) ;
V_91 = F_35 ( V_78 -> V_28 ,
V_57 ,
L_25 ,
V_78 -> V_30 -> V_31 ,
V_78 -> V_28 ) ;
if ( V_91 == NULL ) {
F_12 ( L_26
L_27 ,
V_13 -> V_30 -> V_31 , V_13 -> V_28 ,
V_78 -> V_28 ) ;
F_21 ( & V_57 ) ;
V_13 -> V_62 = NULL ;
}
}
return 0 ;
}
static void F_36 ( struct V_1 * V_2 , int V_92 )
{
if ( V_2 -> V_19 [ V_92 ] == NULL )
return;
F_37 ( V_2 -> V_19 [ V_92 ] ) ;
V_2 -> V_19 [ V_92 ] = NULL ;
return;
}
static int F_38 ( struct V_12 * V_13 , struct V_9 * V_93 ,
T_1 V_92 , int V_94 )
{
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_15 = 0 ;
F_3 ( V_82 , L_28 , V_93 -> V_10 , V_92 ) ;
F_39 ( V_2 ) ;
if ( V_2 -> V_7 . V_18 == 0 ) {
struct V_12 * V_78 ;
V_78 = F_28 ( V_93 , V_32 ,
& V_13 -> V_9 ) ;
if ( ! V_78 ) {
F_40 ( V_2 ) ;
F_12 ( L_29 ,
V_13 -> V_28 , V_93 -> V_10 , - V_26 ) ;
return - V_26 ;
}
}
if ( ( V_92 < V_2 -> V_95 ) && ( V_2 -> V_19 [ V_92 ] != NULL ) ) {
V_4 = V_2 -> V_19 [ V_92 ] ;
F_12 ( L_30
L_31 , V_13 -> V_28 ,
F_41 ( & V_4 -> V_22 ) , V_92 , - V_96 ) ;
F_40 ( V_2 ) ;
return - V_96 ;
}
if ( V_92 >= V_2 -> V_95 ) {
struct V_3 * * V_97 , * * V_98 = NULL ;
T_1 V_99 = 1 ;
T_1 V_100 = 0 ;
while ( V_99 < V_92 + 1 )
V_99 = V_99 << 1 ;
F_42 ( V_97 , sizeof( * V_97 ) * V_99 ) ;
if ( V_97 == NULL ) {
F_40 ( V_2 ) ;
return - V_101 ;
}
if ( V_2 -> V_95 ) {
memcpy ( V_97 , V_2 -> V_19 ,
sizeof( * V_97 ) * V_2 -> V_95 ) ;
V_98 = V_2 -> V_19 ;
V_100 = V_2 -> V_95 ;
}
V_2 -> V_19 = V_97 ;
V_2 -> V_95 = V_99 ;
F_43 () ;
if ( V_98 )
F_44 ( V_98 , sizeof( * V_98 ) * V_100 ) ;
F_3 ( V_82 , L_32 , V_2 -> V_19 ,
V_2 -> V_95 ) ;
}
F_45 ( V_4 ) ;
if ( ! V_4 ) {
F_40 ( V_2 ) ;
return - V_101 ;
}
F_46 ( & V_4 -> V_102 ) ;
V_4 -> V_88 = V_92 ;
V_4 -> V_22 = * V_93 ;
V_4 -> V_6 = 0 ;
V_2 -> V_19 [ V_92 ] = V_4 ;
if ( V_92 >= V_2 -> V_7 . V_18 )
V_2 -> V_7 . V_18 = V_92 + 1 ;
if ( V_2 -> V_61 ) {
V_15 = F_27 ( V_13 , V_4 ) ;
if ( V_15 ) {
F_4 ( & V_2 -> V_17 ) ;
V_2 -> V_7 . V_18 -- ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_8 ( & V_2 -> V_17 ) ;
} else {
int V_68 = sizeof( struct V_103 ) +
V_2 -> V_7 . V_18 * sizeof( struct V_104 ) ;
F_24 ( V_13 -> V_49 , V_68 , 0 , 0 , 0 ) ;
}
}
F_40 ( V_2 ) ;
return V_15 ;
}
int F_20 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_14 ;
int V_15 ;
int V_68 ;
if ( V_2 -> V_61 )
return 0 ;
F_39 ( V_2 ) ;
if ( V_2 -> V_61 ) {
F_40 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_7 . V_18 == 0 ) {
F_40 ( V_2 ) ;
F_12 ( L_33 , V_13 -> V_28 ) ;
return - V_26 ;
}
F_3 ( V_82 , L_34 ,
V_2 -> V_54 . V_10 , V_13 -> V_28 ) ;
F_7 ( V_2 -> V_19 != NULL ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL )
continue;
V_15 = F_27 ( V_13 , V_4 ) ;
if ( V_15 )
GOTO ( V_105 , V_15 ) ;
}
F_22 ( V_13 ) ;
F_47 ( V_2 -> exp ) ;
V_2 -> V_61 = 1 ;
V_68 = F_48 ( V_2 ) ;
F_24 ( V_13 -> V_49 , V_68 , 0 , 0 , 0 ) ;
F_40 ( V_2 ) ;
return 0 ;
V_105:
while ( V_14 -- > 0 ) {
int V_106 ;
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL )
continue;
V_4 -> V_6 = 0 ;
if ( V_4 -> V_20 ) {
-- V_2 -> V_7 . V_8 ;
V_106 = F_33 ( V_4 -> V_20 ) ;
if ( V_106 ) {
F_12 ( L_35
L_36 ,
V_4 -> V_22 . V_10 , V_14 , V_106 ) ;
}
}
}
F_49 ( V_2 -> exp ) ;
F_40 ( V_2 ) ;
return V_15 ;
}
static int F_50 ( struct V_12 * V_13 , struct V_3 * V_4 )
{
struct V_56 * V_57 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_12 * V_78 ;
int V_15 ;
F_7 ( V_4 != NULL ) ;
F_7 ( V_13 != NULL ) ;
V_78 = F_6 ( V_4 -> V_20 ) ;
if ( V_78 ) {
V_78 -> V_107 = V_13 -> V_107 ;
V_78 -> V_108 = V_13 -> V_108 ;
V_78 -> V_109 = V_13 -> V_109 ;
}
V_57 = V_13 -> V_62 ;
if ( V_57 )
F_51 ( V_78 -> V_28 , V_57 ) ;
V_15 = F_52 ( V_4 -> V_20 -> V_34 ) ;
if ( V_15 )
F_12 ( L_37 ) ;
F_3 ( V_16 , L_38 ,
V_4 -> V_20 -> V_34 -> V_28 ,
V_4 -> V_20 -> V_34 -> V_9 . V_10 ) ;
F_32 ( V_4 -> V_20 -> V_34 , NULL ) ;
V_15 = F_33 ( V_4 -> V_20 ) ;
if ( V_15 ) {
if ( V_4 -> V_6 ) {
F_12 ( L_39 ,
V_4 -> V_22 . V_10 , V_15 ) ;
}
}
F_1 ( V_2 , V_4 , 0 ) ;
V_4 -> V_20 = NULL ;
return 0 ;
}
static int F_53 ( struct V_33 * exp )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
int V_15 ;
int V_14 ;
if ( ! V_2 -> V_19 )
goto V_110;
V_2 -> V_60 -- ;
if ( V_2 -> V_60 != 0 )
goto V_110;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL || V_2 -> V_19 [ V_14 ] -> V_20 == NULL )
continue;
F_50 ( V_13 , V_2 -> V_19 [ V_14 ] ) ;
}
if ( V_13 -> V_62 )
F_21 ( (struct V_56 * * ) & V_13 -> V_62 ) ;
else
F_12 ( L_40 ,
V_13 -> V_30 -> V_31 , V_13 -> V_28 ) ;
V_110:
if ( ! V_2 -> V_61 )
F_47 ( exp ) ;
V_15 = F_49 ( exp ) ;
if ( V_2 -> V_60 == 0 )
V_2 -> V_61 = 0 ;
return V_15 ;
}
static int F_54 ( struct V_33 * exp , int V_111 , void * V_112 , void * V_113 )
{
struct V_12 * V_114 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_114 -> V_35 . V_2 ;
struct V_115 * V_116 ;
struct V_3 * V_4 ;
struct V_115 * V_117 = NULL ;
int V_118 = 0 ;
int V_15 ;
V_116 = (struct V_115 * ) V_112 ;
V_4 = F_55 ( V_2 , & V_116 -> V_119 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_120:
V_15 = F_57 ( V_121 , V_4 -> V_20 , V_111 , V_116 , V_113 ) ;
if ( V_15 != 0 && V_15 != - V_122 )
GOTO ( V_123 , V_15 ) ;
if ( V_117 != NULL ) {
struct V_115 * V_124 ;
char * V_125 ;
V_124 = (struct V_115 * ) V_112 ;
if ( strlen ( V_124 -> V_126 ) +
strlen ( V_116 -> V_126 ) > V_124 -> V_127 )
GOTO ( V_123 , V_15 = - V_128 ) ;
V_125 = V_124 -> V_126 ;
memmove ( V_125 + strlen ( V_116 -> V_126 ) + 1 , V_125 ,
strlen ( V_124 -> V_126 ) ) ;
strncpy ( V_125 , V_116 -> V_126 , strlen ( V_116 -> V_126 ) ) ;
V_125 += strlen ( V_116 -> V_126 ) ;
* V_125 = '/' ;
}
F_3 ( V_16 , L_41 V_129 L_42 V_130 L_43 ,
V_4 -> V_20 -> V_34 -> V_28 ,
V_116 -> V_126 , F_58 ( & V_116 -> V_119 ) , V_116 -> V_131 ,
V_116 -> V_132 ) ;
if ( V_15 == 0 )
GOTO ( V_123 , V_15 ) ;
if ( V_117 == NULL ) {
V_118 = sizeof( * V_117 ) + V_133 ;
F_42 ( V_117 , V_118 ) ;
if ( V_117 == NULL )
GOTO ( V_123 , V_15 = - V_101 ) ;
V_117 -> V_127 = V_133 ;
}
if ( ! F_59 ( & V_116 -> V_119 ) ) {
F_12 ( L_44 V_129 L_45 ,
V_4 -> V_20 -> V_34 -> V_28 ,
F_58 ( & V_116 -> V_119 ) , - V_26 ) ;
GOTO ( V_123 , V_15 = - V_26 ) ;
}
V_4 = F_55 ( V_2 , & V_116 -> V_119 ) ;
if ( F_19 ( V_4 ) )
GOTO ( V_123 , V_15 = - V_26 ) ;
V_117 -> V_119 = V_116 -> V_119 ;
V_117 -> V_131 = - 1 ;
V_117 -> V_132 = - 1 ;
memset ( V_117 -> V_126 , 0 , V_117 -> V_127 ) ;
V_116 = V_117 ;
goto V_120;
V_123:
if ( V_117 != NULL )
F_44 ( V_117 , V_118 ) ;
return V_15 ;
}
static int F_60 ( struct V_1 * V_2 ,
const struct V_134 * V_135 ,
const struct V_3 * V_136 )
{
int V_14 , V_137 = 0 ;
struct V_3 * V_138 ;
for ( V_14 = 0 ; V_14 < V_135 -> V_139 . V_140 ; V_14 ++ ) {
V_138 = F_55 ( V_2 , & V_135 -> V_141 [ V_14 ] . V_142 ) ;
if ( F_5 ( & V_138 -> V_22 , & V_136 -> V_22 ) )
V_137 ++ ;
}
return V_137 ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_134 * V_143 ,
const struct V_3 * V_136 ,
struct V_134 * V_144 )
{
int V_14 , V_145 ;
struct V_3 * V_138 ;
V_144 -> V_139 = V_143 -> V_139 ;
V_145 = 0 ;
for ( V_14 = 0 ; V_14 < V_143 -> V_139 . V_140 ; V_14 ++ ) {
V_138 = F_55 ( V_2 ,
& V_143 -> V_141 [ V_14 ] . V_142 ) ;
if ( F_5 ( & V_138 -> V_22 , & V_136 -> V_22 ) ) {
V_144 -> V_141 [ V_145 ] =
V_143 -> V_141 [ V_14 ] ;
V_145 ++ ;
}
}
V_144 -> V_139 . V_140 = V_145 ;
memcpy ( F_62 ( V_144 ) , F_62 ( V_143 ) ,
V_143 -> V_139 . V_146 ) ;
}
static int F_63 ( struct V_1 * V_2 , unsigned int V_147 , int V_111 ,
struct V_148 * V_149 , void * V_113 )
{
int V_14 , V_15 = 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
F_57 ( V_147 , V_2 -> V_19 [ V_14 ] -> V_20 , V_111 , V_149 , V_113 ) ;
}
V_15 = F_64 ( V_149 -> V_150 , V_149 -> V_151 ) ;
return V_15 ;
}
static int F_65 ( struct V_1 * V_2 , unsigned int V_147 , int V_111 ,
struct V_148 * V_149 , void * V_113 )
{
struct V_152 * V_153 ;
int V_14 , V_154 , V_155 ;
int V_15 = 0 ;
bool V_156 = false ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_155 = F_57 ( V_147 , V_2 -> V_19 [ V_14 ] -> V_20 ,
V_111 , V_149 , V_113 ) ;
if ( V_155 ) {
if ( V_2 -> V_19 [ V_14 ] -> V_6 ) {
F_12 ( L_46
L_47 ,
V_2 -> V_19 [ V_14 ] -> V_22 . V_10 ,
V_14 , V_147 , V_155 ) ;
V_15 = V_155 ;
V_149 -> V_157 |= V_158 ;
for ( V_154 = 0 ; V_154 < V_14 ; V_154 ++ )
F_57 ( V_147 ,
V_2 -> V_19 [ V_154 ] -> V_20 ,
V_111 , V_149 , V_113 ) ;
return V_15 ;
}
} else {
V_156 = true ;
}
}
if ( ! V_156 )
return - V_27 ;
V_153 = F_66 ( V_149 -> V_159 ) ;
if ( V_153 == NULL ) {
return - V_160 ;
}
V_15 = F_67 ( V_153 , V_149 -> V_150 , V_149 -> V_151 , V_149 -> V_161 ) ;
if ( V_15 != 0 && V_153 != NULL )
F_68 ( V_153 ) ;
return V_15 ;
}
static int F_69 ( unsigned int V_147 , struct V_33 * exp ,
int V_111 , void * V_112 , void * V_113 )
{
struct V_12 * V_114 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_114 -> V_35 . V_2 ;
int V_14 = 0 ;
int V_15 = 0 ;
int V_162 = 0 ;
int V_163 = V_2 -> V_7 . V_18 ;
if ( V_163 == 0 )
return - V_164 ;
switch ( V_147 ) {
case V_165 : {
struct V_166 * V_39 = V_112 ;
struct V_12 * V_78 ;
struct V_167 V_168 = { 0 } ;
T_1 V_92 ;
memcpy ( & V_92 , V_39 -> V_169 , sizeof( T_1 ) ) ;
if ( ( V_92 >= V_163 ) )
return - V_170 ;
if ( V_2 -> V_19 [ V_92 ] == NULL ||
V_2 -> V_19 [ V_92 ] -> V_6 == 0 )
return - V_171 ;
V_78 = F_6 ( V_2 -> V_19 [ V_92 ] -> V_20 ) ;
if ( ! V_78 )
return - V_26 ;
if ( F_70 ( V_39 -> V_172 , F_71 ( V_78 ) ,
F_72 ( ( int ) V_39 -> V_173 ,
( int ) sizeof( struct V_9 ) ) ) )
return - V_174 ;
V_15 = V_167 ( NULL , V_2 -> V_19 [ V_92 ] -> V_20 , & V_168 ,
F_73 ( - V_175 ) ,
0 ) ;
if ( V_15 )
return V_15 ;
if ( F_70 ( V_39 -> V_176 , & V_168 ,
F_72 ( ( int ) V_39 -> V_177 ,
( int ) sizeof( V_168 ) ) ) )
return - V_174 ;
break;
}
case V_178 : {
struct V_179 * V_180 = V_112 ;
struct V_3 * V_4 = NULL ;
struct V_181 * V_182 ;
if ( V_180 -> V_183 == V_184 ) {
if ( V_180 -> V_185 < 0 || V_163 <= V_180 -> V_185 )
return - V_26 ;
V_4 = V_2 -> V_19 [ V_180 -> V_185 ] ;
if ( V_4 == NULL || V_4 -> V_20 == NULL )
return - V_26 ;
} else if ( V_180 -> V_183 == V_186 ) {
for ( V_14 = 0 ; V_14 < V_163 ; V_14 ++ ) {
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL )
continue;
if ( ! F_5 ( & V_4 -> V_22 ,
& V_180 -> V_9 ) )
continue;
if ( V_4 -> V_20 == NULL )
return - V_26 ;
break;
}
} else {
return - V_26 ;
}
if ( V_14 >= V_163 )
return - V_187 ;
F_7 ( V_4 && V_4 -> V_20 ) ;
F_45 ( V_182 ) ;
if ( ! V_182 )
return - V_101 ;
F_74 ( V_182 , V_180 ) ;
V_15 = V_181 ( V_4 -> V_20 , V_182 ) ;
if ( V_15 == 0 ) {
F_74 ( V_180 , V_182 ) ;
V_180 -> V_183 = V_184 ;
V_180 -> V_9 = V_4 -> V_22 ;
}
F_37 ( V_182 ) ;
break;
}
case V_188 :
case V_189 : {
struct V_190 * V_191 = V_112 ;
if ( V_191 -> V_192 >= V_163 )
return - V_170 ;
if ( V_2 -> V_19 [ V_191 -> V_192 ] == NULL ||
V_2 -> V_19 [ V_191 -> V_192 ] -> V_20 == NULL ||
V_2 -> V_19 [ V_191 -> V_192 ] -> V_6 == 0 )
return - V_170 ;
V_15 = F_57 ( V_147 , V_2 -> V_19 [ V_191 -> V_192 ] -> V_20 ,
sizeof( * V_191 ) , V_191 , NULL ) ;
break;
}
case V_193 : {
if ( V_2 -> V_19 [ 0 ] == NULL )
return - V_171 ;
V_15 = F_57 ( V_147 , V_2 -> V_19 [ 0 ] -> V_20 , V_111 , V_112 , V_113 ) ;
break;
}
case V_121 : {
V_15 = F_54 ( exp , V_111 , V_112 , V_113 ) ;
break;
}
case V_194 :
case V_195 :
case V_196 : {
struct V_197 * V_198 = V_112 ;
struct V_3 * V_4 ;
V_4 = F_55 ( V_2 , & V_198 -> V_199 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
if ( V_4 -> V_20 == NULL )
return - V_26 ;
V_15 = F_57 ( V_147 , V_4 -> V_20 , V_111 , V_112 , V_113 ) ;
break;
}
case V_200 : {
const struct V_201 * V_202 = V_112 ;
struct V_3 * V_4 ;
V_4 = F_55 ( V_2 , & V_202 -> V_203 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_57 ( V_147 , V_4 -> V_20 , V_111 , V_112 , V_113 ) ;
break;
}
case V_204 : {
struct V_134 * V_135 = V_112 ;
struct V_3 * V_4 ;
unsigned int V_205 = V_135 -> V_139 . V_140 ;
if ( V_205 == 0 )
return 0 ;
if ( V_205 == 1 || V_163 == 1 ) {
V_4 = F_55 ( V_2 ,
& V_135 -> V_141 [ 0 ] . V_142 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_57 ( V_147 , V_4 -> V_20 , V_111 , V_112 , V_113 ) ;
} else {
for ( V_14 = 0 ; V_14 < V_163 ; V_14 ++ ) {
unsigned int V_137 , V_206 ;
int V_207 ;
struct V_134 * V_208 ;
V_137 = F_60 ( V_2 , V_135 , V_2 -> V_19 [ V_14 ] ) ;
if ( V_137 == 0 )
continue;
V_206 = F_75 ( F_76 ( * V_135 ) ,
V_141 [ V_137 ] )
+ V_135 -> V_139 . V_146 ;
F_77 ( V_208 , V_206 ) ;
if ( V_208 == NULL )
return - V_101 ;
F_61 ( V_2 , V_135 , V_2 -> V_19 [ V_14 ] , V_208 ) ;
V_207 = F_57 ( V_147 , V_2 -> V_19 [ V_14 ] -> V_20 ,
V_206 , V_208 , V_113 ) ;
if ( V_207 != 0 && V_15 == 0 )
V_15 = V_207 ;
F_78 ( V_208 , V_206 ) ;
}
}
break;
}
case V_209 : {
struct V_197 * V_198 = V_112 ;
struct V_3 * V_210 , * V_211 ;
V_210 = F_55 ( V_2 , & V_198 -> V_199 ) ;
if ( F_19 ( V_210 ) )
return F_56 ( V_210 ) ;
V_211 = F_55 ( V_2 , & V_198 -> V_212 ) ;
if ( F_19 ( V_211 ) )
return F_56 ( V_211 ) ;
if ( ( V_210 -> V_20 == NULL ) || ( V_211 -> V_20 == NULL ) )
return - V_26 ;
if ( V_210 -> V_88 != V_211 -> V_88 )
return - V_213 ;
V_15 = F_57 ( V_147 , V_210 -> V_20 , V_111 , V_112 , V_113 ) ;
break;
}
case V_214 : {
struct V_148 * V_149 = V_112 ;
if ( V_149 -> V_157 & V_158 )
V_15 = F_63 ( V_2 , V_147 , V_111 , V_149 , V_113 ) ;
else
V_15 = F_65 ( V_2 , V_147 , V_111 , V_149 , V_113 ) ;
break;
}
default:
for ( V_14 = 0 ; V_14 < V_163 ; V_14 ++ ) {
struct V_12 * V_78 ;
int V_155 ;
if ( V_2 -> V_19 [ V_14 ] == NULL ||
V_2 -> V_19 [ V_14 ] -> V_20 == NULL )
continue;
V_78 = F_6 ( V_2 -> V_19 [ V_14 ] -> V_20 ) ;
V_78 -> V_107 = V_114 -> V_107 ;
V_155 = F_57 ( V_147 , V_2 -> V_19 [ V_14 ] -> V_20 , V_111 ,
V_112 , V_113 ) ;
if ( V_155 == - V_171 && V_147 == V_215 ) {
return V_155 ;
} else if ( V_155 ) {
if ( V_2 -> V_19 [ V_14 ] -> V_6 ) {
F_12 ( L_46
L_47 ,
V_2 -> V_19 [ V_14 ] -> V_22 . V_10 ,
V_14 , V_147 , V_155 ) ;
if ( ! V_15 )
V_15 = V_155 ;
}
} else
V_162 = 1 ;
}
if ( ! V_162 && ! V_15 )
V_15 = - V_216 ;
}
return V_15 ;
}
static int F_79 ( struct V_12 * V_13 ,
struct V_197 * V_198 ,
T_2 * V_217 )
{
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
F_7 ( V_217 != NULL ) ;
if ( V_2 -> V_7 . V_18 == 1 ) {
* V_217 = 0 ;
return 0 ;
}
if ( V_198 -> V_218 & V_219 ) {
struct V_220 * V_221 ;
V_221 = (struct V_220 * ) V_198 -> V_198 ;
if ( V_221 -> V_222 == V_223 &&
V_221 -> V_224 != - 1 ) {
if ( V_221 -> V_224 >= V_2 -> V_7 . V_18 ) {
F_12 ( L_48
L_31 , V_13 -> V_28 ,
V_221 -> V_224 ,
V_2 -> V_7 . V_18 , - V_225 ) ;
return - V_225 ;
}
* V_217 = V_221 -> V_224 ;
return 0 ;
}
}
* V_217 = V_198 -> V_226 ;
return 0 ;
}
int F_80 ( struct V_1 * V_2 , struct V_104 * V_227 ,
T_2 V_217 )
{
struct V_3 * V_4 ;
int V_15 ;
V_4 = F_81 ( V_2 , V_217 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
F_82 ( & V_4 -> V_102 ) ;
if ( V_4 -> V_6 == 0 || V_4 -> V_20 == NULL )
GOTO ( V_228 , V_15 = - V_170 ) ;
V_15 = F_83 ( V_4 -> V_20 , V_227 , NULL ) ;
if ( V_15 > 0 ) {
F_7 ( F_59 ( V_227 ) ) ;
V_15 = 0 ;
}
V_228:
F_84 ( & V_4 -> V_102 ) ;
return V_15 ;
}
int F_85 ( struct V_33 * exp , struct V_104 * V_227 ,
struct V_197 * V_198 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
T_2 V_217 = 0 ;
int V_15 ;
F_7 ( V_198 != NULL ) ;
F_7 ( V_227 != NULL ) ;
V_15 = F_79 ( V_13 , V_198 , & V_217 ) ;
if ( V_15 ) {
F_12 ( L_49
L_50 , V_15 ) ;
return V_15 ;
}
V_15 = F_80 ( V_2 , V_227 , V_217 ) ;
if ( V_15 ) {
F_12 ( L_51 , V_15 ) ;
return V_15 ;
}
return V_15 ;
}
static int F_86 ( struct V_12 * V_13 , struct V_229 * V_230 )
{
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_231 V_232 ;
struct V_233 * V_7 ;
int V_15 ;
if ( F_87 ( V_230 , 1 ) < 1 ) {
F_12 ( L_52 ) ;
return - V_26 ;
}
V_7 = (struct V_233 * ) F_88 ( V_230 , 1 ) ;
if ( sizeof( * V_7 ) > F_87 ( V_230 , 1 ) ) {
F_12 ( L_53 ,
( int ) sizeof( * V_7 ) , F_87 ( V_230 , 1 ) ) ;
return - V_26 ;
}
F_42 ( V_2 -> V_19 , sizeof( * V_2 -> V_19 ) * 32 ) ;
if ( V_2 -> V_19 == NULL )
return - V_101 ;
V_2 -> V_95 = 32 ;
F_89 ( & V_2 -> V_7 . V_234 , V_7 -> V_234 . V_10 ) ;
V_2 -> V_7 . V_18 = 0 ;
V_2 -> V_7 . V_8 = 0 ;
V_2 -> V_75 = 0 ;
V_2 -> V_74 = 0 ;
V_2 -> V_73 = 0 ;
V_2 -> V_235 = V_236 ;
F_90 ( & V_2 -> V_17 ) ;
F_46 ( & V_2 -> V_237 ) ;
F_91 ( & V_232 ) ;
F_92 ( V_13 , V_232 . V_238 ) ;
#ifdef F_93
{
V_15 = F_94 ( V_13 -> V_63 , L_54 ,
0444 , & V_239 , V_13 ) ;
if ( V_15 )
F_25 ( L_55 ,
V_13 -> V_28 , V_15 ) ;
}
#endif
V_15 = F_95 ( & V_2 -> V_89 , V_13 -> V_28 ,
V_240 ) ;
if ( V_15 ) {
F_12 ( L_56 , V_15 ) ;
GOTO ( V_228 , V_15 ) ;
}
return 0 ;
V_228:
return V_15 ;
}
static int F_96 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
F_97 ( & V_2 -> V_89 ) ;
if ( V_2 -> V_19 != NULL ) {
int V_14 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL )
continue;
F_36 ( V_2 , V_14 ) ;
}
F_44 ( V_2 -> V_19 , sizeof( * V_2 -> V_19 ) * V_2 -> V_95 ) ;
V_2 -> V_95 = 0 ;
}
return 0 ;
}
static int F_98 ( struct V_12 * V_13 , T_3 V_111 , void * V_241 )
{
struct V_229 * V_230 = V_241 ;
struct V_9 V_9 ;
int V_94 ;
T_1 V_92 ;
int V_15 ;
switch ( V_230 -> V_242 ) {
case V_243 :
if ( F_87 ( V_230 , 1 ) > sizeof( V_9 . V_10 ) )
GOTO ( V_228 , V_15 = - V_26 ) ;
F_89 ( & V_9 , F_88 ( V_230 , 1 ) ) ;
if ( sscanf ( F_88 ( V_230 , 2 ) , L_57 , & V_92 ) != 1 )
GOTO ( V_228 , V_15 = - V_26 ) ;
if ( sscanf ( F_88 ( V_230 , 3 ) , L_57 , & V_94 ) != 1 )
GOTO ( V_228 , V_15 = - V_26 ) ;
V_15 = F_38 ( V_13 , & V_9 , V_92 , V_94 ) ;
GOTO ( V_228 , V_15 ) ;
default:
F_12 ( L_58 , V_230 -> V_242 ) ;
GOTO ( V_228 , V_15 = - V_26 ) ;
}
V_228:
return V_15 ;
}
static int F_99 ( const struct V_52 * V_53 , struct V_33 * exp ,
struct V_167 * V_244 , T_4 V_245 , T_1 V_246 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_167 * V_247 ;
int V_15 = 0 ;
int V_14 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_42 ( V_247 , sizeof( * V_247 ) ) ;
if ( V_247 == NULL )
return - V_101 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL || V_2 -> V_19 [ V_14 ] -> V_20 == NULL )
continue;
V_15 = V_167 ( V_53 , V_2 -> V_19 [ V_14 ] -> V_20 , V_247 ,
V_245 , V_246 ) ;
if ( V_15 ) {
F_12 ( L_59 , V_14 ,
V_2 -> V_19 [ V_14 ] -> V_20 -> V_34 -> V_28 ,
V_15 ) ;
GOTO ( V_248 , V_15 ) ;
}
if ( V_14 == 0 ) {
* V_244 = * V_247 ;
if ( V_246 & V_249 )
GOTO ( V_248 , V_15 ) ;
} else {
V_244 -> V_250 += V_247 -> V_250 ;
V_244 -> V_251 += V_247 -> V_251 ;
V_244 -> V_252 += V_247 -> V_252 ;
V_244 -> V_253 += V_247 -> V_253 ;
}
}
V_248:
F_44 ( V_247 , sizeof( * V_247 ) ) ;
return V_15 ;
}
static int F_100 ( struct V_33 * exp ,
struct V_104 * V_227 ,
struct V_254 * * V_255 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_101 ( V_2 -> V_19 [ 0 ] -> V_20 , V_227 , V_255 ) ;
return V_15 ;
}
static int F_102 ( struct V_33 * exp , const struct V_104 * V_227 ,
struct V_254 * V_256 , T_5 V_257 , const char * V_258 ,
const char * V_259 , int V_260 , int V_261 ,
int V_246 , struct V_262 * * V_263 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , V_227 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_103 ( V_4 -> V_20 , V_227 , V_256 , V_257 , V_258 , V_259 ,
V_260 , V_261 , V_246 , V_263 ) ;
return V_15 ;
}
static int F_104 ( struct V_33 * exp , const struct V_104 * V_227 ,
struct V_254 * V_256 , T_5 V_257 , const char * V_258 ,
const char * V_259 , int V_260 , int V_261 ,
int V_246 , T_1 V_264 ,
struct V_262 * * V_263 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , V_227 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_105 ( V_4 -> V_20 , V_227 , V_256 , V_257 , V_258 , V_259 ,
V_260 , V_261 , V_246 , V_264 ,
V_263 ) ;
return V_15 ;
}
static int F_106 ( struct V_33 * exp , struct V_197 * V_198 ,
struct V_262 * * V_263 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , & V_198 -> V_199 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
if ( V_198 -> V_265 & V_266 ) {
V_198 -> V_226 = V_4 -> V_88 ;
return 0 ;
}
V_15 = F_107 ( V_4 -> V_20 , V_198 , V_263 ) ;
return V_15 ;
}
static int F_108 ( struct V_33 * exp , const struct V_104 * V_227 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
int V_14 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_267 , L_60 V_129 L_3 , F_58 ( V_227 ) ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL || V_2 -> V_19 [ V_14 ] -> V_20 == NULL )
continue;
F_109 ( V_2 -> V_19 [ V_14 ] -> V_20 , V_227 ) ;
}
return 0 ;
}
static int F_110 ( struct V_33 * exp , const struct V_104 * V_227 ,
T_6 V_268 , void * V_39 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
int V_14 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_267 , L_60 V_129 L_3 , F_58 ( V_227 ) ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL || V_2 -> V_19 [ V_14 ] -> V_20 == NULL )
continue;
V_15 = F_111 ( V_2 -> V_19 [ V_14 ] -> V_20 , V_227 , V_268 , V_39 ) ;
if ( V_15 )
return V_15 ;
}
return V_15 ;
}
static int F_112 ( struct V_33 * exp , struct V_197 * V_198 ,
struct V_269 * V_270 , struct V_262 * * V_263 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , & V_198 -> V_199 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
F_3 ( V_267 , L_61 V_129 L_3 , F_58 ( & V_198 -> V_199 ) ) ;
V_15 = F_113 ( V_4 -> V_20 , V_198 , V_270 , V_263 ) ;
return V_15 ;
}
struct V_3
* F_114 ( struct V_1 * V_2 , struct V_197 * V_198 ,
struct V_104 * V_227 )
{
struct V_3 * V_4 ;
V_4 = F_55 ( V_2 , V_227 ) ;
if ( F_19 ( V_4 ) )
return V_4 ;
V_198 -> V_226 = V_4 -> V_88 ;
return V_4 ;
}
int F_115 ( struct V_33 * exp , struct V_197 * V_198 ,
const void * V_39 , int V_271 , int V_272 , T_1 V_273 ,
T_1 V_274 , T_7 V_275 , T_4 V_276 ,
struct V_262 * * V_263 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
if ( ! V_2 -> V_7 . V_8 )
return - V_216 ;
V_4 = F_114 ( V_2 , V_198 , & V_198 -> V_199 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_85 ( exp , & V_198 -> V_212 , V_198 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_267 , L_62 V_129 L_63 ,
V_198 -> V_277 , V_198 -> V_278 , F_58 ( & V_198 -> V_199 ) ,
V_198 -> V_226 ) ;
V_198 -> V_265 |= V_279 ;
V_15 = F_116 ( V_4 -> V_20 , V_198 , V_39 , V_271 , V_272 , V_273 , V_274 ,
V_275 , V_276 , V_263 ) ;
if ( V_15 == 0 ) {
if ( * V_263 == NULL )
return V_15 ;
F_3 ( V_267 , L_64 V_129 L_3 , F_58 ( & V_198 -> V_212 ) ) ;
}
return V_15 ;
}
static int F_117 ( struct V_33 * exp ,
struct V_197 * V_198 ,
struct V_269 * V_270 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , & V_198 -> V_199 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_118 ( V_4 -> V_20 , V_198 , V_270 ) ;
return V_15 ;
}
static int
F_119 ( struct V_33 * exp , struct V_280 * V_281 ,
struct V_282 * V_268 , struct V_197 * V_198 ,
struct V_58 * V_283 , void * V_284 , int V_285 ,
int V_286 )
{
struct V_262 * V_208 = V_268 -> V_287 . V_288 . V_289 ;
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_58 V_290 ;
struct V_3 * V_4 ;
struct V_197 * V_291 ;
struct V_104 V_292 ;
struct V_293 * V_294 ;
int V_15 = 0 ;
int V_295 ;
V_294 = F_120 ( & V_208 -> V_296 , & V_297 ) ;
F_7 ( V_294 != NULL ) ;
if ( ! ( V_294 -> V_257 & V_298 ) )
return 0 ;
F_3 ( V_267 , L_65 V_129 L_66 V_129 L_3 ,
F_121 ( V_268 ) , F_58 ( & V_198 -> V_199 ) , F_58 ( & V_294 -> V_292 ) ) ;
V_295 = V_268 -> V_287 . V_288 . V_299 ;
F_7 ( V_295 != 0 ) ;
memcpy ( & V_290 , V_283 , sizeof( V_290 ) ) ;
V_268 -> V_287 . V_288 . V_299 = 0 ;
V_268 -> V_287 . V_288 . V_289 = NULL ;
V_292 = V_294 -> V_292 ;
F_122 ( V_208 ) ;
V_4 = F_55 ( V_2 , & V_292 ) ;
if ( F_19 ( V_4 ) )
GOTO ( V_228 , V_15 = F_56 ( V_4 ) ) ;
F_45 ( V_291 ) ;
if ( V_291 == NULL )
GOTO ( V_228 , V_15 = - V_101 ) ;
V_291 -> V_199 = V_292 ;
V_291 -> V_300 = V_301 ;
V_15 = F_123 ( V_4 -> V_20 , V_281 , V_268 , V_291 , V_283 ,
V_284 , V_285 , NULL , V_286 ) ;
F_37 ( V_291 ) ;
V_228:
F_124 ( & V_290 , V_295 ) ;
return V_15 ;
}
static int
F_125 ( struct V_33 * exp , struct V_280 * V_281 ,
struct V_282 * V_268 , struct V_197 * V_198 ,
struct V_58 * V_283 , void * V_284 , int V_285 ,
struct V_262 * * V_208 , T_4 V_286 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_267 , L_67 V_129 L_3 ,
F_121 ( V_268 ) , F_58 ( & V_198 -> V_199 ) ) ;
V_4 = F_114 ( V_2 , V_198 , & V_198 -> V_199 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
F_3 ( V_267 , L_67 V_129 L_68 ,
F_121 ( V_268 ) , F_58 ( & V_198 -> V_199 ) , V_4 -> V_88 ) ;
V_15 = F_123 ( V_4 -> V_20 , V_281 , V_268 , V_198 , V_283 ,
V_284 , V_285 , V_208 , V_286 ) ;
if ( V_15 == 0 && V_268 && V_268 -> V_302 == V_303 ) {
V_15 = F_119 ( exp , V_281 , V_268 , V_198 , V_283 ,
V_284 , V_285 , V_286 ) ;
}
return V_15 ;
}
static int
F_126 ( struct V_33 * exp , struct V_197 * V_198 ,
struct V_262 * * V_263 )
{
struct V_262 * V_208 = NULL ;
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
struct V_293 * V_294 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_114 ( V_2 , V_198 , & V_198 -> V_199 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
F_3 ( V_267 , L_69 V_129 L_68 ,
V_198 -> V_277 , V_198 -> V_278 , F_58 ( & V_198 -> V_199 ) ,
V_4 -> V_88 ) ;
V_15 = F_127 ( V_4 -> V_20 , V_198 , V_263 ) ;
if ( V_15 != 0 )
return V_15 ;
V_294 = F_120 ( & ( * V_263 ) -> V_296 ,
& V_297 ) ;
F_7 ( V_294 != NULL ) ;
if ( V_294 -> V_257 & V_298 ) {
struct V_104 V_304 = V_294 -> V_292 ;
F_3 ( V_267 , L_70 V_129 L_3 ,
F_58 ( & V_304 ) ) ;
V_4 = F_55 ( V_2 , & V_304 ) ;
if ( F_19 ( V_4 ) ) {
F_122 ( * V_263 ) ;
return F_56 ( V_4 ) ;
}
V_198 -> V_199 = V_304 ;
V_198 -> V_305 |= V_306 ;
V_198 -> V_277 = 0 ;
V_198 -> V_278 = NULL ;
V_15 = F_127 ( V_4 -> V_20 , V_198 , & V_208 ) ;
F_122 ( * V_263 ) ;
* V_263 = V_208 ;
}
return V_15 ;
}
static int F_128 ( struct V_33 * exp , struct V_197 * V_198 ,
int V_307 , T_8 V_272 , int V_308 , int V_309 )
{
struct V_104 * V_227 = F_129 ( V_198 , V_309 ) ;
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
T_9 V_310 = { { 0 } } ;
int V_15 = 0 ;
if ( ! F_59 ( V_227 ) )
return 0 ;
V_4 = F_55 ( V_2 , V_227 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
if ( V_4 -> V_88 != V_307 ) {
F_3 ( V_267 , L_71 V_129 L_3 , F_58 ( V_227 ) ) ;
V_310 . V_311 . V_308 = V_308 ;
V_15 = F_130 ( V_4 -> V_20 , V_227 , & V_310 ,
V_272 , V_312 , NULL ) ;
} else {
F_3 ( V_267 ,
L_72 V_129 L_3 ,
V_307 , F_58 ( V_227 ) ) ;
V_198 -> V_265 |= V_309 ;
V_15 = 0 ;
}
return V_15 ;
}
static int F_131 ( struct V_33 * exp , struct V_197 * V_198 ,
struct V_262 * * V_263 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_7 ( V_198 -> V_277 != 0 ) ;
F_3 ( V_267 , L_73 V_129 L_74 V_129 L_3 ,
F_58 ( & V_198 -> V_212 ) , V_198 -> V_277 ,
V_198 -> V_278 , F_58 ( & V_198 -> V_199 ) ) ;
V_198 -> V_313 = F_132 ( & V_314 , F_133 () ) ;
V_198 -> V_315 = F_134 ( & V_314 , F_135 () ) ;
V_198 -> V_316 = F_136 () ;
V_4 = F_114 ( V_2 , V_198 , & V_198 -> V_212 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_198 -> V_265 |= V_317 ;
V_15 = F_128 ( exp , V_198 , V_4 -> V_88 , V_318 ,
V_319 , V_279 ) ;
if ( V_15 != 0 )
return V_15 ;
V_15 = F_137 ( V_4 -> V_20 , V_198 , V_263 ) ;
return V_15 ;
}
static int F_138 ( struct V_33 * exp , struct V_197 * V_198 ,
const char * V_98 , int V_320 , const char * V_321 , int V_322 ,
struct V_262 * * V_263 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_323 ;
struct V_3 * V_324 ;
int V_15 ;
F_7 ( V_320 != 0 ) ;
F_3 ( V_267 , L_75 V_129 L_76 V_129 L_3 ,
V_320 , V_98 , F_58 ( & V_198 -> V_199 ) ,
V_322 , V_321 , F_58 ( & V_198 -> V_212 ) ) ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_198 -> V_313 = F_132 ( & V_314 , F_133 () ) ;
V_198 -> V_315 = F_134 ( & V_314 , F_135 () ) ;
V_198 -> V_316 = F_136 () ;
V_323 = F_114 ( V_2 , V_198 , & V_198 -> V_199 ) ;
if ( F_19 ( V_323 ) )
return F_56 ( V_323 ) ;
V_324 = F_114 ( V_2 , V_198 , & V_198 -> V_212 ) ;
if ( F_19 ( V_324 ) )
return F_56 ( V_324 ) ;
V_198 -> V_265 |= V_279 | V_325 ;
V_15 = F_128 ( exp , V_198 , V_323 -> V_88 ,
V_318 , V_319 ,
V_317 ) ;
if ( V_15 == 0 ) {
V_15 = F_128 ( exp , V_198 , V_323 -> V_88 ,
V_318 , V_326 ,
V_327 ) ;
}
if ( V_15 == 0 )
V_15 = F_128 ( exp , V_198 , V_323 -> V_88 ,
V_318 , V_328 ,
V_327 ) ;
if ( V_15 == 0 )
V_15 = F_139 ( V_323 -> V_20 , V_198 , V_98 , V_320 ,
V_321 , V_322 , V_263 ) ;
return V_15 ;
}
static int F_140 ( struct V_33 * exp , struct V_197 * V_198 ,
void * V_329 , int V_330 , void * V_331 , int V_332 ,
struct V_262 * * V_263 ,
struct V_269 * * V_270 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_15 = 0 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_267 , L_77 V_129 L_78 ,
F_58 ( & V_198 -> V_199 ) , V_198 -> V_333 . V_334 ) ;
V_198 -> V_265 |= V_279 ;
V_4 = F_55 ( V_2 , & V_198 -> V_199 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_141 ( V_4 -> V_20 , V_198 , V_329 , V_330 , V_331 ,
V_332 , V_263 , V_270 ) ;
return V_15 ;
}
static int F_142 ( struct V_33 * exp , const struct V_104 * V_227 ,
struct V_254 * V_256 , struct V_262 * * V_263 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , V_227 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_143 ( V_4 -> V_20 , V_227 , V_256 , V_263 ) ;
return V_15 ;
}
static void F_144 ( struct V_335 * * V_336 , int V_337 , int V_338 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_337 ; V_14 ++ ) {
struct V_339 * V_340 = F_145 ( V_336 [ V_14 ] ) ;
struct V_339 * V_341 = V_340 ;
struct V_342 * V_343 = NULL ;
struct V_342 * V_344 ;
T_4 V_345 = V_340 -> V_346 ;
T_1 V_246 = V_340 -> V_347 ;
while ( -- V_338 > 0 ) {
V_344 = F_146 ( V_340 ) ;
for ( V_343 = V_344 ; V_344 != NULL ;
V_343 = V_344 , V_344 = F_147 ( V_344 ) ) ;
V_340 = (struct V_339 * ) ( ( char * ) V_340 + V_348 ) ;
if ( ! ( ( unsigned long ) V_340 & ~ V_349 ) )
break;
V_345 = V_340 -> V_346 ;
V_246 = V_340 -> V_347 ;
if ( ! V_343 )
break;
F_7 ( F_148 ( V_343 -> V_350 ) == 0 ) ;
V_343 -> V_350 =
F_149 ( ( char * ) ( V_340 -> V_351 ) -
( char * ) V_343 ) ;
}
V_341 -> V_346 = V_345 ;
V_341 -> V_347 &= ~ F_150 ( V_352 ) ;
V_341 -> V_347 |= V_246 & F_150 ( V_352 ) ;
F_151 ( V_336 [ V_14 ] ) ;
}
F_152 ( V_338 == 0 , L_79 , V_338 ) ;
}
static int F_153 ( struct V_33 * exp , struct V_197 * V_198 ,
struct V_335 * * V_336 , struct V_262 * * V_263 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
T_4 V_353 = V_198 -> V_354 ;
int V_15 ;
int V_337 ;
int V_338 ;
struct V_3 * V_4 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_267 , L_80 V_21 L_81 V_129 L_3 ,
V_353 , F_58 ( & V_198 -> V_199 ) ) ;
V_4 = F_55 ( V_2 , & V_198 -> V_199 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_154 ( V_4 -> V_20 , V_198 , V_336 , V_263 ) ;
if ( V_15 != 0 )
return V_15 ;
V_337 = ( ( * V_263 ) -> V_355 -> V_356 + V_357 - 1 )
>> V_358 ;
V_338 = ( * V_263 ) -> V_355 -> V_356 >> V_359 ;
F_7 ( ! ( ( * V_263 ) -> V_355 -> V_356 & ~ V_360 ) ) ;
F_7 ( V_337 > 0 && V_337 <= V_198 -> V_361 ) ;
F_3 ( V_267 , L_82 , V_337 , V_338 ,
V_198 -> V_361 ) ;
F_144 ( V_336 , V_337 , V_338 ) ;
return V_15 ;
}
static int F_155 ( struct V_33 * exp , struct V_197 * V_198 ,
struct V_262 * * V_263 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 = NULL ;
struct V_293 * V_294 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_362:
if ( F_156 ( ! F_157 ( & V_198 -> V_212 ) ) )
V_4 = F_114 ( V_2 , V_198 , & V_198 -> V_212 ) ;
else
V_4 = F_114 ( V_2 , V_198 , & V_198 -> V_199 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_198 -> V_313 = F_132 ( & V_314 , F_133 () ) ;
V_198 -> V_315 = F_134 ( & V_314 , F_135 () ) ;
V_198 -> V_316 = F_136 () ;
V_198 -> V_265 |= V_279 | V_325 ;
V_15 = F_128 ( exp , V_198 , V_4 -> V_88 , V_318 ,
V_328 , V_325 ) ;
if ( V_15 != 0 )
return V_15 ;
F_3 ( V_267 , L_83 V_129 L_84 V_129 L_68 ,
F_58 ( & V_198 -> V_199 ) , F_58 ( & V_198 -> V_212 ) , V_4 -> V_88 ) ;
V_15 = F_158 ( V_4 -> V_20 , V_198 , V_263 ) ;
if ( V_15 != 0 && V_15 != - V_122 )
return V_15 ;
V_294 = F_120 ( & ( * V_263 ) -> V_296 , & V_297 ) ;
if ( V_294 == NULL )
return - V_363 ;
if ( F_156 ( ! ( V_294 -> V_257 & V_298 ) ) )
return 0 ;
F_3 ( V_267 , L_85 V_129 L_3 ,
exp -> V_34 -> V_28 , F_58 ( & V_294 -> V_292 ) ) ;
V_198 -> V_212 = V_294 -> V_292 ;
F_122 ( * V_263 ) ;
* V_263 = NULL ;
goto V_362;
}
static int F_159 ( struct V_12 * V_13 , enum V_364 V_365 )
{
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
int V_15 = 0 ;
switch ( V_365 ) {
case V_366 :
break;
case V_367 :
F_160 ( & V_2 -> V_89 ) ;
F_161 ( V_13 ) ;
break;
default:
break;
}
return V_15 ;
}
static int F_162 ( const struct V_52 * V_53 , struct V_33 * exp ,
T_1 V_368 , void * V_369 , T_1 * V_370 , void * V_371 ,
struct V_372 * V_373 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
int V_15 = 0 ;
V_13 = F_6 ( exp ) ;
if ( V_13 == NULL ) {
F_3 ( V_374 , L_86 V_21 L_3 ,
exp -> V_23 . V_24 ) ;
return - V_26 ;
}
V_2 = & V_13 -> V_35 . V_2 ;
if ( V_368 >= strlen ( L_87 ) && ! strcmp ( V_369 , L_87 ) ) {
struct V_3 * V_4 ;
int V_14 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_7 ( * V_370 == sizeof( T_1 ) ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL || V_4 -> V_20 == NULL )
continue;
if ( ! F_163 ( V_53 , V_4 -> V_20 , V_368 , V_369 ,
V_370 , V_371 , NULL ) )
return 0 ;
}
return - V_26 ;
} else if ( F_164 ( V_375 ) ||
F_164 ( V_376 ) ||
F_164 ( V_377 ) ||
F_164 ( V_378 ) ||
F_164 ( V_379 ) ) {
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_163 ( V_53 , V_2 -> V_19 [ 0 ] -> V_20 , V_368 , V_369 ,
V_370 , V_371 , NULL ) ;
if ( ! V_15 && F_164 ( V_379 ) )
exp -> V_50 = * (struct V_40 * ) V_371 ;
return V_15 ;
} else if ( F_164 ( V_380 ) ) {
* ( ( int * ) V_371 ) = V_2 -> V_7 . V_18 ;
return 0 ;
}
F_3 ( V_374 , L_88 ) ;
return - V_26 ;
}
int F_165 ( const struct V_52 * V_53 , struct V_33 * exp ,
T_3 V_368 , void * V_369 , T_3 V_370 ,
void * V_371 , struct V_381 * V_162 )
{
struct V_3 * V_4 ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
int V_15 = 0 ;
V_13 = F_6 ( exp ) ;
if ( V_13 == NULL ) {
F_3 ( V_374 , L_86 V_21 L_3 ,
exp -> V_23 . V_24 ) ;
return - V_26 ;
}
V_2 = & V_13 -> V_35 . V_2 ;
if ( F_164 ( V_382 ) || F_164 ( V_383 ) ) {
int V_14 , V_155 = 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL || V_4 -> V_20 == NULL )
continue;
V_155 = F_23 ( V_53 , V_4 -> V_20 ,
V_368 , V_369 , V_370 , V_371 , V_162 ) ;
if ( V_155 && V_15 == 0 )
V_15 = V_155 ;
}
return V_15 ;
}
return - V_26 ;
}
int F_166 ( struct V_33 * exp , struct V_384 * * V_385 ,
struct V_372 * V_373 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_103 * V_386 ;
struct V_103 * V_387 ;
int V_388 ;
int V_14 ;
V_388 = F_48 ( V_2 ) ;
if ( ! V_385 )
return V_388 ;
if ( * V_385 && ! V_373 ) {
F_78 ( * V_385 , V_388 ) ;
* V_385 = NULL ;
return 0 ;
}
if ( * V_385 == NULL ) {
F_77 ( * V_385 , V_388 ) ;
if ( * V_385 == NULL )
return - V_101 ;
}
if ( ! V_373 )
return V_388 ;
V_387 = (struct V_103 * ) V_373 ;
V_386 = (struct V_103 * ) * V_385 ;
if ( V_387 -> V_389 != V_390 &&
V_387 -> V_389 != V_391 )
return - V_26 ;
V_386 -> V_389 = F_150 ( V_387 -> V_389 ) ;
V_386 -> V_392 = F_150 ( V_387 -> V_392 ) ;
V_386 -> V_393 = F_150 ( V_387 -> V_393 ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_386 -> V_394 [ V_14 ] = V_387 -> V_394 [ V_14 ] ;
F_167 ( & V_386 -> V_394 [ V_14 ] , & V_387 -> V_394 [ V_14 ] ) ;
}
return V_388 ;
}
int F_168 ( struct V_33 * exp , struct V_372 * * V_387 ,
struct V_384 * V_284 , int V_395 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_103 * * V_396 = (struct V_103 * * ) V_387 ;
struct V_103 * V_397 = (struct V_103 * ) V_284 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
int V_388 ;
int V_14 ;
T_1 V_398 ;
V_388 = F_48 ( V_2 ) ;
if ( V_387 == NULL )
return V_388 ;
if ( * V_387 != NULL && V_284 == NULL ) {
F_78 ( * V_396 , V_388 ) ;
* V_387 = NULL ;
return 0 ;
}
F_7 ( V_388 == V_395 ) ;
F_77 ( * V_396 , V_388 ) ;
if ( * V_396 == NULL )
return - V_101 ;
if ( ! V_284 )
return V_388 ;
if ( V_397 -> V_389 == V_390 ||
V_397 -> V_389 == V_391 ||
V_397 -> V_389 == V_399 )
{
V_398 = F_169 ( V_397 -> V_389 ) ;
} else {
F_12 ( L_89 ) ;
F_170 () ;
}
( * V_396 ) -> V_389 = V_398 ;
( * V_396 ) -> V_392 = F_169 ( V_397 -> V_392 ) ;
( * V_396 ) -> V_393 = F_169 ( V_397 -> V_393 ) ;
for ( V_14 = 0 ; V_14 < ( * V_396 ) -> V_392 ; V_14 ++ ) {
( * V_396 ) -> V_394 [ V_14 ] = V_397 -> V_394 [ V_14 ] ;
F_171 ( & ( * V_396 ) -> V_394 [ V_14 ] , & ( * V_396 ) -> V_394 [ V_14 ] ) ;
}
return V_388 ;
}
static int F_172 ( struct V_33 * exp , const struct V_104 * V_227 ,
T_9 * V_310 , T_8 V_272 ,
T_10 V_246 , void * V_400 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
int V_15 = 0 ;
int V_155 ;
int V_14 ;
F_7 ( V_227 != NULL ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL || V_2 -> V_19 [ V_14 ] -> V_20 == NULL ||
V_2 -> V_19 [ V_14 ] -> V_6 == 0 )
continue;
V_155 = F_130 ( V_2 -> V_19 [ V_14 ] -> V_20 , V_227 ,
V_310 , V_272 , V_246 , V_400 ) ;
if ( ! V_15 )
V_15 = V_155 ;
}
return V_15 ;
}
int F_173 ( struct V_33 * exp , T_4 * V_283 , void * V_39 ,
T_4 * V_308 )
{
struct V_1 * V_2 = & exp -> V_34 -> V_35 . V_2 ;
int V_15 ;
V_15 = F_174 ( V_2 -> V_19 [ 0 ] -> V_20 , V_283 , V_39 , V_308 ) ;
return V_15 ;
}
T_8 F_175 ( struct V_33 * exp , T_4 V_246 ,
const struct V_104 * V_227 , T_11 type ,
T_9 * V_310 , T_8 V_272 ,
struct V_58 * V_283 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
T_8 V_15 ;
int V_14 ;
F_3 ( V_267 , L_90 V_129 L_3 , F_58 ( V_227 ) ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL ||
V_2 -> V_19 [ V_14 ] -> V_20 == NULL ||
V_2 -> V_19 [ V_14 ] -> V_6 == 0 )
continue;
V_15 = F_176 ( V_2 -> V_19 [ V_14 ] -> V_20 , V_246 , V_227 ,
type , V_310 , V_272 , V_283 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
int F_177 ( struct V_33 * exp , struct V_262 * V_208 ,
struct V_33 * V_401 , struct V_33 * V_402 ,
struct V_403 * V_404 )
{
struct V_1 * V_2 = & exp -> V_34 -> V_35 . V_2 ;
return F_178 ( V_2 -> V_19 [ 0 ] -> V_20 , V_208 , V_401 , V_402 , V_404 ) ;
}
int F_179 ( struct V_33 * exp , struct V_403 * V_404 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
if ( V_404 -> V_397 )
F_180 ( exp , ( void * ) & V_404 -> V_397 ) ;
return F_181 ( V_2 -> V_19 [ 0 ] -> V_20 , V_404 ) ;
}
int F_182 ( struct V_33 * exp ,
struct V_405 * V_406 ,
struct V_282 * V_268 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
V_4 = F_55 ( V_2 , & V_406 -> V_407 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
return F_183 ( V_4 -> V_20 , V_406 , V_268 ) ;
}
int F_184 ( struct V_33 * exp ,
struct V_405 * V_406 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
V_4 = F_55 ( V_2 , & V_406 -> V_407 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
return F_185 ( V_4 -> V_20 , V_406 ) ;
}
static int F_186 ( struct V_33 * exp ,
const struct V_104 * V_227 ,
struct V_254 * V_256 , T_1 V_264 ,
struct V_262 * * V_263 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , V_227 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_187 ( V_4 -> V_20 , V_227 , V_256 , V_264 , V_263 ) ;
return V_15 ;
}
static int F_188 ( struct V_33 * exp , struct V_254 * V_256 ,
T_12 V_408 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , & V_256 -> V_409 . V_410 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_189 ( V_4 -> V_20 , V_256 , V_408 ) ;
return V_15 ;
}
int F_190 ( struct V_33 * exp , struct V_262 * V_208 ,
const struct V_411 * V_412 , struct V_254 * * V_256 )
{
struct V_1 * V_2 = & exp -> V_34 -> V_35 . V_2 ;
return F_191 ( V_2 -> V_19 [ 0 ] -> V_20 , V_208 , V_412 , V_256 ) ;
}
int F_192 ( struct V_33 * exp ,
struct V_413 * V_414 ,
struct V_280 * V_281 )
{
struct V_197 * V_198 = & V_414 -> V_415 ;
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 = NULL ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , & V_198 -> V_199 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_193 ( V_4 -> V_20 , V_414 , V_281 ) ;
return V_15 ;
}
int F_194 ( struct V_33 * exp , struct V_282 * V_268 ,
struct V_104 * V_227 , T_4 * V_308 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , V_227 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_195 ( V_4 -> V_20 , V_268 , V_227 , V_308 ) ;
return V_15 ;
}
int F_196 ( struct V_12 * V_416 , struct V_33 * exp ,
struct V_181 * V_182 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 = V_2 -> V_19 [ 0 ] ;
int V_15 = 0 , V_14 ;
T_4 V_417 , V_418 ;
if ( ! V_2 -> V_7 . V_18 || ! V_4 -> V_6 ) {
F_12 ( L_91 ) ;
return - V_216 ;
}
if ( V_182 -> V_419 != V_420 ) {
V_15 = V_181 ( V_4 -> V_20 , V_182 ) ;
return V_15 ;
}
V_417 = V_418 = 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
int V_155 ;
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL || V_4 -> V_20 == NULL || V_4 -> V_6 == 0 )
continue;
if ( ! V_4 -> V_6 ) {
F_3 ( V_421 , L_92 , V_14 ) ;
continue;
}
V_155 = V_181 ( V_4 -> V_20 , V_182 ) ;
if ( V_155 ) {
F_12 ( L_93 , V_14 , V_155 ) ;
if ( ! V_15 )
V_15 = V_155 ;
} else {
V_417 += V_182 -> V_422 . V_423 ;
V_418 += V_182 -> V_422 . V_424 ;
}
}
V_182 -> V_422 . V_423 = V_417 ;
V_182 -> V_422 . V_424 = V_418 ;
return V_15 ;
}
int F_197 ( struct V_12 * V_416 , struct V_33 * exp ,
struct V_181 * V_182 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_14 , V_15 = 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
int V_155 ;
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL || V_4 -> V_20 == NULL || ! V_4 -> V_6 ) {
F_12 ( L_94 , V_14 ) ;
return - V_216 ;
}
V_155 = F_198 ( V_4 -> V_20 , V_182 ) ;
if ( V_155 && ! V_15 )
V_15 = V_155 ;
}
return V_15 ;
}
int T_13 F_199 ( void )
{
struct V_231 V_232 ;
int V_15 ;
F_91 ( & V_232 ) ;
V_15 = F_200 ( & V_425 , & V_426 ,
V_232 . V_427 , V_428 , NULL ) ;
return V_15 ;
}
static void F_201 ( void )
{
F_202 ( V_428 ) ;
}
