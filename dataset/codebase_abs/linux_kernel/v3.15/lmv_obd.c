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
int V_69 , int V_70 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
int V_14 ;
int V_15 = 0 ;
int V_71 = 0 ;
if ( V_2 -> V_72 < V_68 ) {
V_2 -> V_72 = V_68 ;
V_71 = 1 ;
}
if ( V_2 -> V_73 < V_69 ) {
V_2 -> V_73 = V_69 ;
V_71 = 1 ;
}
if ( V_2 -> V_74 < V_70 ) {
V_2 -> V_74 = V_70 ;
V_71 = 1 ;
}
if ( V_71 == 0 )
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
V_70 ) ;
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
struct V_9 V_75 = { L_18 } ;
struct V_12 * V_76 ;
struct V_33 * V_77 ;
struct V_78 V_79 ;
int V_15 ;
V_76 = F_28 ( & V_4 -> V_22 , V_32 ,
& V_13 -> V_9 ) ;
if ( ! V_76 ) {
F_12 ( L_19 , V_4 -> V_22 . V_10 ) ;
return - V_26 ;
}
F_3 ( V_80 , L_20 ,
V_76 -> V_28 , V_76 -> V_9 . V_10 ,
V_4 -> V_22 . V_10 , V_13 -> V_9 . V_10 ,
V_54 -> V_10 ) ;
if ( ! V_76 -> V_81 ) {
F_12 ( L_21 , V_4 -> V_22 . V_10 ) ;
return - V_26 ;
}
V_15 = F_29 ( NULL , & V_77 , V_76 , & V_75 ,
& V_2 -> V_41 , NULL ) ;
if ( V_15 ) {
F_12 ( L_22 , V_4 -> V_22 . V_10 , V_15 ) ;
return V_15 ;
}
V_15 = F_30 ( V_76 , V_77 , V_82 ) ;
if ( V_15 )
return V_15 ;
V_79 . V_83 = NULL ;
V_79 . V_84 = V_77 ;
V_79 . V_85 = V_4 -> V_86 ;
F_31 ( & V_2 -> V_87 , & V_79 ) ;
V_15 = F_32 ( V_76 , V_13 ) ;
if ( V_15 ) {
F_33 ( V_77 ) ;
F_12 ( L_23 ,
V_4 -> V_22 . V_10 , V_15 ) ;
return V_15 ;
}
if ( V_13 -> V_51 ) {
V_15 = F_13 ( V_13 -> V_51 , V_77 -> V_34 ,
V_44 ,
( void * ) ( V_4 - V_2 -> V_19 [ 0 ] ) ) ;
if ( V_15 ) {
F_33 ( V_77 ) ;
return V_15 ;
}
}
V_4 -> V_6 = 1 ;
V_4 -> V_20 = V_77 ;
V_2 -> V_7 . V_8 ++ ;
F_26 ( V_4 -> V_20 , V_2 -> V_72 ,
V_2 -> V_73 , V_2 -> V_74 ) ;
F_3 ( V_80 , L_24 ,
V_76 -> V_28 , V_76 -> V_9 . V_10 ,
F_34 ( & V_13 -> V_88 ) ) ;
V_57 = V_13 -> V_62 ;
if ( V_57 ) {
struct V_56 * V_89 ;
F_7 ( V_76 -> V_30 != NULL ) ;
F_7 ( V_76 -> V_30 -> V_31 != NULL ) ;
V_89 = F_35 ( V_76 -> V_28 ,
V_57 ,
L_25 ,
V_76 -> V_30 -> V_31 ,
V_76 -> V_28 ) ;
if ( V_89 == NULL ) {
F_12 ( L_26
L_27 ,
V_13 -> V_30 -> V_31 , V_13 -> V_28 ,
V_76 -> V_28 ) ;
F_21 ( & V_57 ) ;
V_13 -> V_62 = NULL ;
}
}
return 0 ;
}
static void F_36 ( struct V_1 * V_2 , int V_90 )
{
if ( V_2 -> V_19 [ V_90 ] == NULL )
return;
F_37 ( V_2 -> V_19 [ V_90 ] ) ;
V_2 -> V_19 [ V_90 ] = NULL ;
return;
}
static int F_38 ( struct V_12 * V_13 , struct V_9 * V_91 ,
T_1 V_90 , int V_92 )
{
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_15 = 0 ;
F_3 ( V_80 , L_28 , V_91 -> V_10 , V_90 ) ;
F_39 ( V_2 ) ;
if ( V_2 -> V_7 . V_18 == 0 ) {
struct V_12 * V_76 ;
V_76 = F_28 ( V_91 , V_32 ,
& V_13 -> V_9 ) ;
if ( ! V_76 ) {
F_40 ( V_2 ) ;
F_12 ( L_29 ,
V_13 -> V_28 , V_91 -> V_10 , - V_26 ) ;
return - V_26 ;
}
}
if ( ( V_90 < V_2 -> V_93 ) && ( V_2 -> V_19 [ V_90 ] != NULL ) ) {
V_4 = V_2 -> V_19 [ V_90 ] ;
F_12 ( L_30
L_31 , V_13 -> V_28 ,
F_41 ( & V_4 -> V_22 ) , V_90 , - V_94 ) ;
F_40 ( V_2 ) ;
return - V_94 ;
}
if ( V_90 >= V_2 -> V_93 ) {
struct V_3 * * V_95 , * * V_96 = NULL ;
T_1 V_97 = 1 ;
T_1 V_98 = 0 ;
while ( V_97 < V_90 + 1 )
V_97 = V_97 << 1 ;
F_42 ( V_95 , sizeof( * V_95 ) * V_97 ) ;
if ( V_95 == NULL ) {
F_40 ( V_2 ) ;
return - V_99 ;
}
if ( V_2 -> V_93 ) {
memcpy ( V_95 , V_2 -> V_19 ,
sizeof( * V_95 ) * V_2 -> V_93 ) ;
V_96 = V_2 -> V_19 ;
V_98 = V_2 -> V_93 ;
}
V_2 -> V_19 = V_95 ;
V_2 -> V_93 = V_97 ;
F_43 () ;
if ( V_96 )
F_44 ( V_96 , sizeof( * V_96 ) * V_98 ) ;
F_3 ( V_80 , L_32 , V_2 -> V_19 ,
V_2 -> V_93 ) ;
}
F_45 ( V_4 ) ;
if ( ! V_4 ) {
F_40 ( V_2 ) ;
return - V_99 ;
}
F_46 ( & V_4 -> V_100 ) ;
V_4 -> V_86 = V_90 ;
V_4 -> V_22 = * V_91 ;
V_4 -> V_6 = 0 ;
V_2 -> V_19 [ V_90 ] = V_4 ;
if ( V_90 >= V_2 -> V_7 . V_18 )
V_2 -> V_7 . V_18 = V_90 + 1 ;
if ( V_2 -> V_61 ) {
V_15 = F_27 ( V_13 , V_4 ) ;
if ( V_15 ) {
F_4 ( & V_2 -> V_17 ) ;
V_2 -> V_7 . V_18 -- ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_8 ( & V_2 -> V_17 ) ;
} else {
int V_68 = sizeof( struct V_101 ) +
V_2 -> V_7 . V_18 *
sizeof( struct V_102 ) ;
F_24 ( V_13 -> V_49 , V_68 , 0 , 0 ) ;
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
F_3 ( V_80 , L_34 ,
V_2 -> V_54 . V_10 , V_13 -> V_28 ) ;
F_7 ( V_2 -> V_19 != NULL ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL )
continue;
V_15 = F_27 ( V_13 , V_4 ) ;
if ( V_15 )
GOTO ( V_103 , V_15 ) ;
}
F_22 ( V_13 ) ;
F_47 ( V_2 -> exp ) ;
V_2 -> V_61 = 1 ;
V_68 = F_48 ( V_2 ) ;
F_24 ( V_13 -> V_49 , V_68 , 0 , 0 ) ;
F_40 ( V_2 ) ;
return 0 ;
V_103:
while ( V_14 -- > 0 ) {
int V_104 ;
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL )
continue;
V_4 -> V_6 = 0 ;
if ( V_4 -> V_20 ) {
-- V_2 -> V_7 . V_8 ;
V_104 = F_33 ( V_4 -> V_20 ) ;
if ( V_104 ) {
F_12 ( L_35
L_36 ,
V_4 -> V_22 . V_10 , V_14 , V_104 ) ;
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
struct V_12 * V_76 ;
int V_15 ;
F_7 ( V_4 != NULL ) ;
F_7 ( V_13 != NULL ) ;
V_76 = F_6 ( V_4 -> V_20 ) ;
if ( V_76 ) {
V_76 -> V_105 = V_13 -> V_105 ;
V_76 -> V_106 = V_13 -> V_106 ;
V_76 -> V_107 = V_13 -> V_107 ;
}
V_57 = V_13 -> V_62 ;
if ( V_57 )
F_51 ( V_76 -> V_28 , V_57 ) ;
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
goto V_108;
V_2 -> V_60 -- ;
if ( V_2 -> V_60 != 0 )
goto V_108;
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
V_108:
if ( ! V_2 -> V_61 )
F_47 ( exp ) ;
V_15 = F_49 ( exp ) ;
if ( V_2 -> V_60 == 0 )
V_2 -> V_61 = 0 ;
return V_15 ;
}
static int F_54 ( struct V_33 * exp , int V_109 , void * V_110 , void * V_111 )
{
struct V_12 * V_112 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_112 -> V_35 . V_2 ;
struct V_113 * V_114 ;
struct V_3 * V_4 ;
struct V_113 * V_115 = NULL ;
int V_116 = 0 ;
int V_15 ;
V_114 = (struct V_113 * ) V_110 ;
V_4 = F_55 ( V_2 , & V_114 -> V_117 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_118:
V_15 = F_57 ( V_119 , V_4 -> V_20 , V_109 , V_114 , V_111 ) ;
if ( V_15 != 0 && V_15 != - V_120 )
GOTO ( V_121 , V_15 ) ;
if ( V_115 != NULL ) {
struct V_113 * V_122 ;
char * V_123 ;
V_122 = (struct V_113 * ) V_110 ;
if ( strlen ( V_122 -> V_124 ) +
strlen ( V_114 -> V_124 ) > V_122 -> V_125 )
GOTO ( V_121 , V_15 = - V_126 ) ;
V_123 = V_122 -> V_124 ;
memmove ( V_123 + strlen ( V_114 -> V_124 ) + 1 , V_123 ,
strlen ( V_122 -> V_124 ) ) ;
strncpy ( V_123 , V_114 -> V_124 , strlen ( V_114 -> V_124 ) ) ;
V_123 += strlen ( V_114 -> V_124 ) ;
* V_123 = '/' ;
}
F_3 ( V_16 , L_41 V_127 L_42 V_128 L_43 ,
V_4 -> V_20 -> V_34 -> V_28 ,
V_114 -> V_124 , F_58 ( & V_114 -> V_117 ) , V_114 -> V_129 ,
V_114 -> V_130 ) ;
if ( V_15 == 0 )
GOTO ( V_121 , V_15 ) ;
if ( V_115 == NULL ) {
V_116 = sizeof( * V_115 ) + V_131 ;
F_42 ( V_115 , V_116 ) ;
if ( V_115 == NULL )
GOTO ( V_121 , V_15 = - V_99 ) ;
V_115 -> V_125 = V_131 ;
}
if ( ! F_59 ( & V_114 -> V_117 ) ) {
F_12 ( L_44 V_127 L_45 ,
V_4 -> V_20 -> V_34 -> V_28 ,
F_58 ( & V_114 -> V_117 ) , - V_26 ) ;
GOTO ( V_121 , V_15 = - V_26 ) ;
}
V_4 = F_55 ( V_2 , & V_114 -> V_117 ) ;
if ( F_19 ( V_4 ) )
GOTO ( V_121 , V_15 = - V_26 ) ;
V_115 -> V_117 = V_114 -> V_117 ;
V_115 -> V_129 = - 1 ;
V_115 -> V_130 = - 1 ;
memset ( V_115 -> V_124 , 0 , V_115 -> V_125 ) ;
V_114 = V_115 ;
goto V_118;
V_121:
if ( V_115 != NULL )
F_44 ( V_115 , V_116 ) ;
return V_15 ;
}
static int F_60 ( struct V_1 * V_2 ,
const struct V_132 * V_133 ,
const struct V_3 * V_134 )
{
int V_14 , V_135 = 0 ;
struct V_3 * V_136 ;
for ( V_14 = 0 ; V_14 < V_133 -> V_137 . V_138 ; V_14 ++ ) {
V_136 = F_55 ( V_2 , & V_133 -> V_139 [ V_14 ] . V_140 ) ;
if ( F_5 ( & V_136 -> V_22 , & V_134 -> V_22 ) )
V_135 ++ ;
}
return V_135 ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_132 * V_141 ,
const struct V_3 * V_134 ,
struct V_132 * V_142 )
{
int V_14 , V_143 ;
struct V_3 * V_136 ;
V_142 -> V_137 = V_141 -> V_137 ;
V_143 = 0 ;
for ( V_14 = 0 ; V_14 < V_141 -> V_137 . V_138 ; V_14 ++ ) {
V_136 = F_55 ( V_2 ,
& V_141 -> V_139 [ V_14 ] . V_140 ) ;
if ( F_5 ( & V_136 -> V_22 , & V_134 -> V_22 ) ) {
V_142 -> V_139 [ V_143 ] =
V_141 -> V_139 [ V_14 ] ;
V_143 ++ ;
}
}
V_142 -> V_137 . V_138 = V_143 ;
memcpy ( F_62 ( V_142 ) , F_62 ( V_141 ) ,
V_141 -> V_137 . V_144 ) ;
}
static int F_63 ( struct V_1 * V_2 , unsigned int V_145 , int V_109 ,
struct V_146 * V_147 , void * V_111 )
{
int V_14 , V_15 = 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
F_57 ( V_145 , V_2 -> V_19 [ V_14 ] -> V_20 , V_109 , V_147 , V_111 ) ;
}
V_15 = F_64 ( V_147 -> V_148 , V_147 -> V_149 ) ;
return V_15 ;
}
static int F_65 ( struct V_1 * V_2 , unsigned int V_145 , int V_109 ,
struct V_146 * V_147 , void * V_111 )
{
struct V_150 * V_151 ;
int V_14 , V_152 , V_153 ;
int V_15 = 0 ;
bool V_154 = false ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_153 = F_57 ( V_145 , V_2 -> V_19 [ V_14 ] -> V_20 ,
V_109 , V_147 , V_111 ) ;
if ( V_153 ) {
if ( V_2 -> V_19 [ V_14 ] -> V_6 ) {
F_12 ( L_46
L_47 ,
V_2 -> V_19 [ V_14 ] -> V_22 . V_10 ,
V_14 , V_145 , V_153 ) ;
V_15 = V_153 ;
V_147 -> V_155 |= V_156 ;
for ( V_152 = 0 ; V_152 < V_14 ; V_152 ++ )
F_57 ( V_145 ,
V_2 -> V_19 [ V_152 ] -> V_20 ,
V_109 , V_147 , V_111 ) ;
return V_15 ;
}
} else {
V_154 = true ;
}
}
if ( ! V_154 )
return - V_27 ;
V_151 = F_66 ( V_147 -> V_157 ) ;
if ( V_151 == NULL ) {
return - V_158 ;
}
V_15 = F_67 ( V_151 , V_147 -> V_148 , V_147 -> V_149 , V_147 -> V_159 ) ;
if ( V_15 != 0 && V_151 != NULL )
F_68 ( V_151 ) ;
return V_15 ;
}
static int F_69 ( unsigned int V_145 , struct V_33 * exp ,
int V_109 , void * V_110 , void * V_111 )
{
struct V_12 * V_112 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_112 -> V_35 . V_2 ;
int V_14 = 0 ;
int V_15 = 0 ;
int V_160 = 0 ;
int V_161 = V_2 -> V_7 . V_18 ;
if ( V_161 == 0 )
return - V_162 ;
switch ( V_145 ) {
case V_163 : {
struct V_164 * V_39 = V_110 ;
struct V_12 * V_76 ;
struct V_165 V_166 = { 0 } ;
T_1 V_90 ;
memcpy ( & V_90 , V_39 -> V_167 , sizeof( T_1 ) ) ;
if ( ( V_90 >= V_161 ) )
return - V_168 ;
if ( V_2 -> V_19 [ V_90 ] == NULL ||
V_2 -> V_19 [ V_90 ] -> V_6 == 0 )
return - V_169 ;
V_76 = F_6 ( V_2 -> V_19 [ V_90 ] -> V_20 ) ;
if ( ! V_76 )
return - V_26 ;
if ( F_70 ( V_39 -> V_170 , F_71 ( V_76 ) ,
F_72 ( ( int ) V_39 -> V_171 ,
( int ) sizeof( struct V_9 ) ) ) )
return - V_172 ;
V_15 = V_165 ( NULL , V_2 -> V_19 [ V_90 ] -> V_20 , & V_166 ,
F_73 ( - V_173 ) ,
0 ) ;
if ( V_15 )
return V_15 ;
if ( F_70 ( V_39 -> V_174 , & V_166 ,
F_72 ( ( int ) V_39 -> V_175 ,
( int ) sizeof( V_166 ) ) ) )
return - V_172 ;
break;
}
case V_176 : {
struct V_177 * V_178 = V_110 ;
struct V_3 * V_4 = NULL ;
struct V_179 * V_180 ;
if ( V_178 -> V_181 == V_182 ) {
if ( V_178 -> V_183 < 0 || V_161 <= V_178 -> V_183 )
return - V_26 ;
V_4 = V_2 -> V_19 [ V_178 -> V_183 ] ;
if ( V_4 == NULL || V_4 -> V_20 == NULL )
return - V_26 ;
} else if ( V_178 -> V_181 == V_184 ) {
for ( V_14 = 0 ; V_14 < V_161 ; V_14 ++ ) {
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL )
continue;
if ( ! F_5 ( & V_4 -> V_22 ,
& V_178 -> V_9 ) )
continue;
if ( V_4 -> V_20 == NULL )
return - V_26 ;
break;
}
} else {
return - V_26 ;
}
if ( V_14 >= V_161 )
return - V_185 ;
F_7 ( V_4 && V_4 -> V_20 ) ;
F_45 ( V_180 ) ;
if ( ! V_180 )
return - V_99 ;
F_74 ( V_180 , V_178 ) ;
V_15 = V_179 ( V_4 -> V_20 , V_180 ) ;
if ( V_15 == 0 ) {
F_74 ( V_178 , V_180 ) ;
V_178 -> V_181 = V_182 ;
V_178 -> V_9 = V_4 -> V_22 ;
}
F_37 ( V_180 ) ;
break;
}
case V_186 :
case V_187 : {
struct V_188 * V_189 = V_110 ;
if ( V_189 -> V_190 >= V_161 )
return - V_168 ;
if ( V_2 -> V_19 [ V_189 -> V_190 ] == NULL ||
V_2 -> V_19 [ V_189 -> V_190 ] -> V_20 == NULL ||
V_2 -> V_19 [ V_189 -> V_190 ] -> V_6 == 0 )
return - V_168 ;
V_15 = F_57 ( V_145 , V_2 -> V_19 [ V_189 -> V_190 ] -> V_20 ,
sizeof( * V_189 ) , V_189 , NULL ) ;
break;
}
case V_191 : {
if ( V_2 -> V_19 [ 0 ] == NULL )
return - V_169 ;
V_15 = F_57 ( V_145 , V_2 -> V_19 [ 0 ] -> V_20 , V_109 , V_110 , V_111 ) ;
break;
}
case V_119 : {
V_15 = F_54 ( exp , V_109 , V_110 , V_111 ) ;
break;
}
case V_192 :
case V_193 :
case V_194 : {
struct V_195 * V_196 = V_110 ;
struct V_3 * V_4 ;
V_4 = F_55 ( V_2 , & V_196 -> V_197 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
if ( V_4 -> V_20 == NULL )
return - V_26 ;
V_15 = F_57 ( V_145 , V_4 -> V_20 , V_109 , V_110 , V_111 ) ;
break;
}
case V_198 : {
const struct V_199 * V_200 = V_110 ;
struct V_3 * V_4 ;
V_4 = F_55 ( V_2 , & V_200 -> V_201 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_57 ( V_145 , V_4 -> V_20 , V_109 , V_110 , V_111 ) ;
break;
}
case V_202 : {
struct V_132 * V_133 = V_110 ;
struct V_3 * V_4 ;
unsigned int V_203 = V_133 -> V_137 . V_138 ;
if ( V_203 == 0 )
return 0 ;
if ( V_203 == 1 || V_161 == 1 ) {
V_4 = F_55 ( V_2 ,
& V_133 -> V_139 [ 0 ] . V_140 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_57 ( V_145 , V_4 -> V_20 , V_109 , V_110 , V_111 ) ;
} else {
for ( V_14 = 0 ; V_14 < V_161 ; V_14 ++ ) {
unsigned int V_135 , V_204 ;
int V_205 ;
struct V_132 * V_206 ;
V_135 = F_60 ( V_2 , V_133 , V_2 -> V_19 [ V_14 ] ) ;
if ( V_135 == 0 )
continue;
V_204 = F_75 ( F_76 ( * V_133 ) ,
V_139 [ V_135 ] )
+ V_133 -> V_137 . V_144 ;
F_77 ( V_206 , V_204 ) ;
if ( V_206 == NULL )
return - V_99 ;
F_61 ( V_2 , V_133 , V_2 -> V_19 [ V_14 ] , V_206 ) ;
V_205 = F_57 ( V_145 , V_2 -> V_19 [ V_14 ] -> V_20 ,
V_204 , V_206 , V_111 ) ;
if ( V_205 != 0 && V_15 == 0 )
V_15 = V_205 ;
F_78 ( V_206 , V_204 ) ;
}
}
break;
}
case V_207 : {
struct V_195 * V_196 = V_110 ;
struct V_3 * V_208 , * V_209 ;
V_208 = F_55 ( V_2 , & V_196 -> V_197 ) ;
if ( F_19 ( V_208 ) )
return F_56 ( V_208 ) ;
V_209 = F_55 ( V_2 , & V_196 -> V_210 ) ;
if ( F_19 ( V_209 ) )
return F_56 ( V_209 ) ;
if ( ( V_208 -> V_20 == NULL ) || ( V_209 -> V_20 == NULL ) )
return - V_26 ;
if ( V_208 -> V_86 != V_209 -> V_86 )
return - V_211 ;
V_15 = F_57 ( V_145 , V_208 -> V_20 , V_109 , V_110 , V_111 ) ;
break;
}
case V_212 : {
struct V_146 * V_147 = V_110 ;
if ( V_147 -> V_155 & V_156 )
V_15 = F_63 ( V_2 , V_145 , V_109 , V_147 , V_111 ) ;
else
V_15 = F_65 ( V_2 , V_145 , V_109 , V_147 , V_111 ) ;
break;
}
default:
for ( V_14 = 0 ; V_14 < V_161 ; V_14 ++ ) {
struct V_12 * V_76 ;
int V_153 ;
if ( V_2 -> V_19 [ V_14 ] == NULL ||
V_2 -> V_19 [ V_14 ] -> V_20 == NULL )
continue;
V_76 = F_6 ( V_2 -> V_19 [ V_14 ] -> V_20 ) ;
V_76 -> V_105 = V_112 -> V_105 ;
V_153 = F_57 ( V_145 , V_2 -> V_19 [ V_14 ] -> V_20 , V_109 ,
V_110 , V_111 ) ;
if ( V_153 == - V_169 && V_145 == V_213 ) {
return V_153 ;
} else if ( V_153 ) {
if ( V_2 -> V_19 [ V_14 ] -> V_6 ) {
F_12 ( L_46
L_47 ,
V_2 -> V_19 [ V_14 ] -> V_22 . V_10 ,
V_14 , V_145 , V_153 ) ;
if ( ! V_15 )
V_15 = V_153 ;
}
} else
V_160 = 1 ;
}
if ( ! V_160 && ! V_15 )
V_15 = - V_214 ;
}
return V_15 ;
}
static int F_79 ( struct V_12 * V_13 ,
struct V_195 * V_196 ,
T_2 * V_215 )
{
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
F_7 ( V_215 != NULL ) ;
if ( V_2 -> V_7 . V_18 == 1 ) {
* V_215 = 0 ;
return 0 ;
}
if ( V_196 -> V_216 & V_217 ) {
struct V_218 * V_219 ;
V_219 = (struct V_218 * ) V_196 -> V_196 ;
if ( V_219 -> V_220 == V_221 &&
V_219 -> V_222 != - 1 ) {
if ( V_219 -> V_222 >= V_2 -> V_7 . V_18 ) {
F_12 ( L_48
L_31 , V_13 -> V_28 ,
V_219 -> V_222 ,
V_2 -> V_7 . V_18 , - V_223 ) ;
return - V_223 ;
}
* V_215 = V_219 -> V_222 ;
return 0 ;
}
}
* V_215 = V_196 -> V_224 ;
return 0 ;
}
int F_80 ( struct V_1 * V_2 , struct V_102 * V_225 ,
T_2 V_215 )
{
struct V_3 * V_4 ;
int V_15 ;
V_4 = F_81 ( V_2 , V_215 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
F_82 ( & V_4 -> V_100 ) ;
if ( V_4 -> V_6 == 0 || V_4 -> V_20 == NULL )
GOTO ( V_226 , V_15 = - V_168 ) ;
V_15 = F_83 ( V_4 -> V_20 , V_225 , NULL ) ;
if ( V_15 > 0 ) {
F_7 ( F_59 ( V_225 ) ) ;
V_15 = 0 ;
}
V_226:
F_84 ( & V_4 -> V_100 ) ;
return V_15 ;
}
int F_85 ( struct V_33 * exp , struct V_102 * V_225 ,
struct V_195 * V_196 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
T_2 V_215 = 0 ;
int V_15 ;
F_7 ( V_196 != NULL ) ;
F_7 ( V_225 != NULL ) ;
V_15 = F_79 ( V_13 , V_196 , & V_215 ) ;
if ( V_15 ) {
F_12 ( L_49
L_50 , V_15 ) ;
return V_15 ;
}
V_15 = F_80 ( V_2 , V_225 , V_215 ) ;
if ( V_15 ) {
F_12 ( L_51 , V_15 ) ;
return V_15 ;
}
return V_15 ;
}
static int F_86 ( struct V_12 * V_13 , struct V_227 * V_228 )
{
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_229 V_230 ;
struct V_231 * V_7 ;
int V_15 ;
if ( F_87 ( V_228 , 1 ) < 1 ) {
F_12 ( L_52 ) ;
return - V_26 ;
}
V_7 = (struct V_231 * ) F_88 ( V_228 , 1 ) ;
if ( sizeof( * V_7 ) > F_87 ( V_228 , 1 ) ) {
F_12 ( L_53 ,
( int ) sizeof( * V_7 ) , F_87 ( V_228 , 1 ) ) ;
return - V_26 ;
}
F_42 ( V_2 -> V_19 , sizeof( * V_2 -> V_19 ) * 32 ) ;
if ( V_2 -> V_19 == NULL )
return - V_99 ;
V_2 -> V_93 = 32 ;
F_89 ( & V_2 -> V_7 . V_232 , V_7 -> V_232 . V_10 ) ;
V_2 -> V_7 . V_18 = 0 ;
V_2 -> V_7 . V_8 = 0 ;
V_2 -> V_74 = 0 ;
V_2 -> V_73 = 0 ;
V_2 -> V_72 = 0 ;
V_2 -> V_233 = V_234 ;
F_90 ( & V_2 -> V_17 ) ;
F_46 ( & V_2 -> V_235 ) ;
F_91 ( & V_230 ) ;
F_92 ( V_13 , V_230 . V_236 ) ;
#ifdef F_93
{
V_15 = F_94 ( V_13 -> V_63 , L_54 ,
0444 , & V_237 , V_13 ) ;
if ( V_15 )
F_25 ( L_55 ,
V_13 -> V_28 , V_15 ) ;
}
#endif
V_15 = F_95 ( & V_2 -> V_87 , V_13 -> V_28 ,
V_238 ) ;
if ( V_15 ) {
F_12 ( L_56 , V_15 ) ;
GOTO ( V_226 , V_15 ) ;
}
return 0 ;
V_226:
return V_15 ;
}
static int F_96 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
F_97 ( & V_2 -> V_87 ) ;
if ( V_2 -> V_19 != NULL ) {
int V_14 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL )
continue;
F_36 ( V_2 , V_14 ) ;
}
F_44 ( V_2 -> V_19 , sizeof( * V_2 -> V_19 ) * V_2 -> V_93 ) ;
V_2 -> V_93 = 0 ;
}
return 0 ;
}
static int F_98 ( struct V_12 * V_13 , T_3 V_109 , void * V_239 )
{
struct V_227 * V_228 = V_239 ;
struct V_9 V_9 ;
int V_92 ;
T_1 V_90 ;
int V_15 ;
switch ( V_228 -> V_240 ) {
case V_241 :
if ( F_87 ( V_228 , 1 ) > sizeof( V_9 . V_10 ) )
GOTO ( V_226 , V_15 = - V_26 ) ;
F_89 ( & V_9 , F_88 ( V_228 , 1 ) ) ;
if ( sscanf ( F_88 ( V_228 , 2 ) , L_57 , & V_90 ) != 1 )
GOTO ( V_226 , V_15 = - V_26 ) ;
if ( sscanf ( F_88 ( V_228 , 3 ) , L_57 , & V_92 ) != 1 )
GOTO ( V_226 , V_15 = - V_26 ) ;
V_15 = F_38 ( V_13 , & V_9 , V_90 , V_92 ) ;
GOTO ( V_226 , V_15 ) ;
default:
F_12 ( L_58 , V_228 -> V_240 ) ;
GOTO ( V_226 , V_15 = - V_26 ) ;
}
V_226:
return V_15 ;
}
static int F_99 ( const struct V_52 * V_53 , struct V_33 * exp ,
struct V_165 * V_242 , T_4 V_243 , T_1 V_244 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_165 * V_245 ;
int V_15 = 0 ;
int V_14 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_42 ( V_245 , sizeof( * V_245 ) ) ;
if ( V_245 == NULL )
return - V_99 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL || V_2 -> V_19 [ V_14 ] -> V_20 == NULL )
continue;
V_15 = V_165 ( V_53 , V_2 -> V_19 [ V_14 ] -> V_20 , V_245 ,
V_243 , V_244 ) ;
if ( V_15 ) {
F_12 ( L_59 , V_14 ,
V_2 -> V_19 [ V_14 ] -> V_20 -> V_34 -> V_28 ,
V_15 ) ;
GOTO ( V_246 , V_15 ) ;
}
if ( V_14 == 0 ) {
* V_242 = * V_245 ;
if ( V_244 & V_247 )
GOTO ( V_246 , V_15 ) ;
} else {
V_242 -> V_248 += V_245 -> V_248 ;
V_242 -> V_249 += V_245 -> V_249 ;
V_242 -> V_250 += V_245 -> V_250 ;
V_242 -> V_251 += V_245 -> V_251 ;
}
}
V_246:
F_44 ( V_245 , sizeof( * V_245 ) ) ;
return V_15 ;
}
static int F_100 ( struct V_33 * exp ,
struct V_102 * V_225 ,
struct V_252 * * V_253 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_101 ( V_2 -> V_19 [ 0 ] -> V_20 , V_225 , V_253 ) ;
return V_15 ;
}
static int F_102 ( struct V_33 * exp , const struct V_102 * V_225 ,
struct V_252 * V_254 , T_5 V_255 , const char * V_256 ,
const char * V_257 , int V_258 , int V_259 ,
int V_244 , struct V_260 * * V_261 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , V_225 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_103 ( V_4 -> V_20 , V_225 , V_254 , V_255 , V_256 , V_257 ,
V_258 , V_259 , V_244 , V_261 ) ;
return V_15 ;
}
static int F_104 ( struct V_33 * exp , const struct V_102 * V_225 ,
struct V_252 * V_254 , T_5 V_255 , const char * V_256 ,
const char * V_257 , int V_258 , int V_259 ,
int V_244 , T_1 V_262 ,
struct V_260 * * V_261 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , V_225 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_105 ( V_4 -> V_20 , V_225 , V_254 , V_255 , V_256 , V_257 ,
V_258 , V_259 , V_244 , V_262 ,
V_261 ) ;
return V_15 ;
}
static int F_106 ( struct V_33 * exp , struct V_195 * V_196 ,
struct V_260 * * V_261 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , & V_196 -> V_197 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
if ( V_196 -> V_263 & V_264 ) {
V_196 -> V_224 = V_4 -> V_86 ;
return 0 ;
}
V_15 = F_107 ( V_4 -> V_20 , V_196 , V_261 ) ;
return V_15 ;
}
static int F_108 ( struct V_33 * exp , const struct V_102 * V_225 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
int V_14 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_265 , L_60 V_127 L_3 , F_58 ( V_225 ) ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL || V_2 -> V_19 [ V_14 ] -> V_20 == NULL )
continue;
F_109 ( V_2 -> V_19 [ V_14 ] -> V_20 , V_225 ) ;
}
return 0 ;
}
static int F_110 ( struct V_33 * exp , const struct V_102 * V_225 ,
T_6 V_266 , void * V_39 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
int V_14 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_265 , L_60 V_127 L_3 , F_58 ( V_225 ) ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL || V_2 -> V_19 [ V_14 ] -> V_20 == NULL )
continue;
V_15 = F_111 ( V_2 -> V_19 [ V_14 ] -> V_20 , V_225 , V_266 , V_39 ) ;
if ( V_15 )
return V_15 ;
}
return V_15 ;
}
static int F_112 ( struct V_33 * exp , struct V_195 * V_196 ,
struct V_267 * V_268 , struct V_260 * * V_261 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , & V_196 -> V_197 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
F_3 ( V_265 , L_61 V_127 L_3 , F_58 ( & V_196 -> V_197 ) ) ;
V_15 = F_113 ( V_4 -> V_20 , V_196 , V_268 , V_261 ) ;
return V_15 ;
}
struct V_3
* F_114 ( struct V_1 * V_2 , struct V_195 * V_196 ,
struct V_102 * V_225 )
{
struct V_3 * V_4 ;
V_4 = F_55 ( V_2 , V_225 ) ;
if ( F_19 ( V_4 ) )
return V_4 ;
V_196 -> V_224 = V_4 -> V_86 ;
return V_4 ;
}
int F_115 ( struct V_33 * exp , struct V_195 * V_196 ,
const void * V_39 , int V_269 , int V_270 , T_1 V_271 ,
T_1 V_272 , T_7 V_273 , T_4 V_274 ,
struct V_260 * * V_261 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
if ( ! V_2 -> V_7 . V_8 )
return - V_214 ;
V_4 = F_114 ( V_2 , V_196 , & V_196 -> V_197 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_85 ( exp , & V_196 -> V_210 , V_196 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_265 , L_62 V_127 L_63 ,
V_196 -> V_275 , V_196 -> V_276 , F_58 ( & V_196 -> V_197 ) ,
V_196 -> V_224 ) ;
V_196 -> V_263 |= V_277 ;
V_15 = F_116 ( V_4 -> V_20 , V_196 , V_39 , V_269 , V_270 , V_271 , V_272 ,
V_273 , V_274 , V_261 ) ;
if ( V_15 == 0 ) {
if ( * V_261 == NULL )
return V_15 ;
F_3 ( V_265 , L_64 V_127 L_3 , F_58 ( & V_196 -> V_210 ) ) ;
}
return V_15 ;
}
static int F_117 ( struct V_33 * exp ,
struct V_195 * V_196 ,
struct V_267 * V_268 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , & V_196 -> V_197 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_118 ( V_4 -> V_20 , V_196 , V_268 ) ;
return V_15 ;
}
static int
F_119 ( struct V_33 * exp , struct V_278 * V_279 ,
struct V_280 * V_266 , struct V_195 * V_196 ,
struct V_58 * V_281 , void * V_282 , int V_283 ,
int V_284 )
{
struct V_260 * V_206 = V_266 -> V_285 . V_286 . V_287 ;
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_58 V_288 ;
struct V_3 * V_4 ;
struct V_195 * V_289 ;
struct V_102 V_290 ;
struct V_291 * V_292 ;
int V_15 = 0 ;
int V_293 ;
V_292 = F_120 ( & V_206 -> V_294 , & V_295 ) ;
F_7 ( V_292 != NULL ) ;
if ( ! ( V_292 -> V_255 & V_296 ) )
return 0 ;
F_3 ( V_265 , L_65 V_127 L_66 V_127 L_3 ,
F_121 ( V_266 ) , F_58 ( & V_196 -> V_197 ) , F_58 ( & V_292 -> V_290 ) ) ;
V_293 = V_266 -> V_285 . V_286 . V_297 ;
F_7 ( V_293 != 0 ) ;
memcpy ( & V_288 , V_281 , sizeof( V_288 ) ) ;
V_266 -> V_285 . V_286 . V_297 = 0 ;
V_266 -> V_285 . V_286 . V_287 = NULL ;
V_290 = V_292 -> V_290 ;
F_122 ( V_206 ) ;
V_4 = F_55 ( V_2 , & V_290 ) ;
if ( F_19 ( V_4 ) )
GOTO ( V_226 , V_15 = F_56 ( V_4 ) ) ;
F_45 ( V_289 ) ;
if ( V_289 == NULL )
GOTO ( V_226 , V_15 = - V_99 ) ;
V_289 -> V_197 = V_290 ;
V_289 -> V_298 = V_299 ;
V_15 = F_123 ( V_4 -> V_20 , V_279 , V_266 , V_289 , V_281 ,
V_282 , V_283 , NULL , V_284 ) ;
F_37 ( V_289 ) ;
V_226:
F_124 ( & V_288 , V_293 ) ;
return V_15 ;
}
static int
F_125 ( struct V_33 * exp , struct V_278 * V_279 ,
struct V_280 * V_266 , struct V_195 * V_196 ,
struct V_58 * V_281 , void * V_282 , int V_283 ,
struct V_260 * * V_206 , T_4 V_284 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_265 , L_67 V_127 L_3 ,
F_121 ( V_266 ) , F_58 ( & V_196 -> V_197 ) ) ;
V_4 = F_114 ( V_2 , V_196 , & V_196 -> V_197 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
F_3 ( V_265 , L_67 V_127 L_68 ,
F_121 ( V_266 ) , F_58 ( & V_196 -> V_197 ) , V_4 -> V_86 ) ;
V_15 = F_123 ( V_4 -> V_20 , V_279 , V_266 , V_196 , V_281 ,
V_282 , V_283 , V_206 , V_284 ) ;
if ( V_15 == 0 && V_266 && V_266 -> V_300 == V_301 ) {
V_15 = F_119 ( exp , V_279 , V_266 , V_196 , V_281 ,
V_282 , V_283 , V_284 ) ;
}
return V_15 ;
}
static int
F_126 ( struct V_33 * exp , struct V_195 * V_196 ,
struct V_260 * * V_261 )
{
struct V_260 * V_206 = NULL ;
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
struct V_291 * V_292 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_114 ( V_2 , V_196 , & V_196 -> V_197 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
F_3 ( V_265 , L_69 V_127 L_68 ,
V_196 -> V_275 , V_196 -> V_276 , F_58 ( & V_196 -> V_197 ) ,
V_4 -> V_86 ) ;
V_15 = F_127 ( V_4 -> V_20 , V_196 , V_261 ) ;
if ( V_15 != 0 )
return V_15 ;
V_292 = F_120 ( & ( * V_261 ) -> V_294 ,
& V_295 ) ;
F_7 ( V_292 != NULL ) ;
if ( V_292 -> V_255 & V_296 ) {
struct V_102 V_302 = V_292 -> V_290 ;
F_3 ( V_265 , L_70 V_127 L_3 ,
F_58 ( & V_302 ) ) ;
V_4 = F_55 ( V_2 , & V_302 ) ;
if ( F_19 ( V_4 ) ) {
F_122 ( * V_261 ) ;
return F_56 ( V_4 ) ;
}
V_196 -> V_197 = V_302 ;
V_196 -> V_303 |= V_304 ;
V_196 -> V_275 = 0 ;
V_196 -> V_276 = NULL ;
V_15 = F_127 ( V_4 -> V_20 , V_196 , & V_206 ) ;
F_122 ( * V_261 ) ;
* V_261 = V_206 ;
}
return V_15 ;
}
static int F_128 ( struct V_33 * exp , struct V_195 * V_196 ,
int V_305 , T_8 V_270 , int V_306 , int V_307 )
{
struct V_102 * V_225 = F_129 ( V_196 , V_307 ) ;
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
T_9 V_308 = { { 0 } } ;
int V_15 = 0 ;
if ( ! F_59 ( V_225 ) )
return 0 ;
V_4 = F_55 ( V_2 , V_225 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
if ( V_4 -> V_86 != V_305 ) {
F_3 ( V_265 , L_71 V_127 L_3 , F_58 ( V_225 ) ) ;
V_308 . V_309 . V_306 = V_306 ;
V_15 = F_130 ( V_4 -> V_20 , V_225 , & V_308 ,
V_270 , V_310 , NULL ) ;
} else {
F_3 ( V_265 ,
L_72 V_127 L_3 ,
V_305 , F_58 ( V_225 ) ) ;
V_196 -> V_263 |= V_307 ;
V_15 = 0 ;
}
return V_15 ;
}
static int F_131 ( struct V_33 * exp , struct V_195 * V_196 ,
struct V_260 * * V_261 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_7 ( V_196 -> V_275 != 0 ) ;
F_3 ( V_265 , L_73 V_127 L_74 V_127 L_3 ,
F_58 ( & V_196 -> V_210 ) , V_196 -> V_275 ,
V_196 -> V_276 , F_58 ( & V_196 -> V_197 ) ) ;
V_196 -> V_311 = F_132 ( & V_312 , F_133 () ) ;
V_196 -> V_313 = F_134 ( & V_312 , F_135 () ) ;
V_196 -> V_314 = F_136 () ;
V_4 = F_114 ( V_2 , V_196 , & V_196 -> V_210 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_196 -> V_263 |= V_315 ;
V_15 = F_128 ( exp , V_196 , V_4 -> V_86 , V_316 ,
V_317 , V_277 ) ;
if ( V_15 != 0 )
return V_15 ;
V_15 = F_137 ( V_4 -> V_20 , V_196 , V_261 ) ;
return V_15 ;
}
static int F_138 ( struct V_33 * exp , struct V_195 * V_196 ,
const char * V_96 , int V_318 , const char * V_319 , int V_320 ,
struct V_260 * * V_261 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_321 ;
struct V_3 * V_322 ;
int V_15 ;
F_7 ( V_318 != 0 ) ;
F_3 ( V_265 , L_75 V_127 L_76 V_127 L_3 ,
V_318 , V_96 , F_58 ( & V_196 -> V_197 ) ,
V_320 , V_319 , F_58 ( & V_196 -> V_210 ) ) ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_196 -> V_311 = F_132 ( & V_312 , F_133 () ) ;
V_196 -> V_313 = F_134 ( & V_312 , F_135 () ) ;
V_196 -> V_314 = F_136 () ;
V_321 = F_114 ( V_2 , V_196 , & V_196 -> V_197 ) ;
if ( F_19 ( V_321 ) )
return F_56 ( V_321 ) ;
V_322 = F_114 ( V_2 , V_196 , & V_196 -> V_210 ) ;
if ( F_19 ( V_322 ) )
return F_56 ( V_322 ) ;
V_196 -> V_263 |= V_277 | V_323 ;
V_15 = F_128 ( exp , V_196 , V_321 -> V_86 ,
V_316 , V_317 ,
V_315 ) ;
if ( V_15 == 0 ) {
V_15 = F_128 ( exp , V_196 , V_321 -> V_86 ,
V_316 , V_324 ,
V_325 ) ;
}
if ( V_15 == 0 )
V_15 = F_128 ( exp , V_196 , V_321 -> V_86 ,
V_316 , V_326 ,
V_325 ) ;
if ( V_15 == 0 )
V_15 = F_139 ( V_321 -> V_20 , V_196 , V_96 , V_318 ,
V_319 , V_320 , V_261 ) ;
return V_15 ;
}
static int F_140 ( struct V_33 * exp , struct V_195 * V_196 ,
void * V_327 , int V_328 , void * V_329 , int V_330 ,
struct V_260 * * V_261 ,
struct V_267 * * V_268 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_15 = 0 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_265 , L_77 V_127 L_78 ,
F_58 ( & V_196 -> V_197 ) , V_196 -> V_331 . V_332 ) ;
V_196 -> V_263 |= V_277 ;
V_4 = F_55 ( V_2 , & V_196 -> V_197 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_141 ( V_4 -> V_20 , V_196 , V_327 , V_328 , V_329 ,
V_330 , V_261 , V_268 ) ;
return V_15 ;
}
static int F_142 ( struct V_33 * exp , const struct V_102 * V_225 ,
struct V_252 * V_254 , struct V_260 * * V_261 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , V_225 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_143 ( V_4 -> V_20 , V_225 , V_254 , V_261 ) ;
return V_15 ;
}
static void F_144 ( struct V_333 * * V_334 , int V_335 , int V_336 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_335 ; V_14 ++ ) {
struct V_337 * V_338 = F_145 ( V_334 [ V_14 ] ) ;
struct V_337 * V_339 = V_338 ;
struct V_340 * V_341 = NULL ;
struct V_340 * V_342 ;
T_4 V_343 = V_338 -> V_344 ;
T_1 V_244 = V_338 -> V_345 ;
while ( -- V_336 > 0 ) {
V_342 = F_146 ( V_338 ) ;
for ( V_341 = V_342 ; V_342 != NULL ;
V_341 = V_342 , V_342 = F_147 ( V_342 ) ) ;
V_338 = (struct V_337 * ) ( ( char * ) V_338 + V_346 ) ;
if ( ! ( ( unsigned long ) V_338 & ~ V_347 ) )
break;
V_343 = V_338 -> V_344 ;
V_244 = V_338 -> V_345 ;
if ( ! V_341 )
break;
F_7 ( F_148 ( V_341 -> V_348 ) == 0 ) ;
V_341 -> V_348 =
F_149 ( ( char * ) ( V_338 -> V_349 ) -
( char * ) V_341 ) ;
}
V_339 -> V_344 = V_343 ;
V_339 -> V_345 &= ~ F_150 ( V_350 ) ;
V_339 -> V_345 |= V_244 & F_150 ( V_350 ) ;
F_151 ( V_334 [ V_14 ] ) ;
}
F_152 ( V_336 == 0 , L_79 , V_336 ) ;
}
static int F_153 ( struct V_33 * exp , struct V_195 * V_196 ,
struct V_333 * * V_334 , struct V_260 * * V_261 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
T_4 V_351 = V_196 -> V_352 ;
int V_15 ;
int V_335 ;
int V_336 ;
struct V_3 * V_4 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_265 , L_80 V_21 L_81 V_127 L_3 ,
V_351 , F_58 ( & V_196 -> V_197 ) ) ;
V_4 = F_55 ( V_2 , & V_196 -> V_197 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_154 ( V_4 -> V_20 , V_196 , V_334 , V_261 ) ;
if ( V_15 != 0 )
return V_15 ;
V_335 = ( ( * V_261 ) -> V_353 -> V_354 + V_355 - 1 )
>> V_356 ;
V_336 = ( * V_261 ) -> V_353 -> V_354 >> V_357 ;
F_7 ( ! ( ( * V_261 ) -> V_353 -> V_354 & ~ V_358 ) ) ;
F_7 ( V_335 > 0 && V_335 <= V_196 -> V_359 ) ;
F_3 ( V_265 , L_82 , V_335 , V_336 ,
V_196 -> V_359 ) ;
F_144 ( V_334 , V_335 , V_336 ) ;
return V_15 ;
}
static int F_155 ( struct V_33 * exp , struct V_195 * V_196 ,
struct V_260 * * V_261 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 = NULL ;
struct V_291 * V_292 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_360:
if ( F_156 ( ! F_157 ( & V_196 -> V_210 ) ) )
V_4 = F_114 ( V_2 , V_196 , & V_196 -> V_210 ) ;
else
V_4 = F_114 ( V_2 , V_196 , & V_196 -> V_197 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_196 -> V_311 = F_132 ( & V_312 , F_133 () ) ;
V_196 -> V_313 = F_134 ( & V_312 , F_135 () ) ;
V_196 -> V_314 = F_136 () ;
V_196 -> V_263 |= V_277 | V_323 ;
V_15 = F_128 ( exp , V_196 , V_4 -> V_86 , V_316 ,
V_326 , V_323 ) ;
if ( V_15 != 0 )
return V_15 ;
F_3 ( V_265 , L_83 V_127 L_84 V_127 L_68 ,
F_58 ( & V_196 -> V_197 ) , F_58 ( & V_196 -> V_210 ) , V_4 -> V_86 ) ;
V_15 = F_158 ( V_4 -> V_20 , V_196 , V_261 ) ;
if ( V_15 != 0 && V_15 != - V_120 )
return V_15 ;
V_292 = F_120 ( & ( * V_261 ) -> V_294 , & V_295 ) ;
if ( V_292 == NULL )
return - V_361 ;
if ( F_156 ( ! ( V_292 -> V_255 & V_296 ) ) )
return 0 ;
F_3 ( V_265 , L_85 V_127 L_3 ,
exp -> V_34 -> V_28 , F_58 ( & V_292 -> V_290 ) ) ;
V_196 -> V_210 = V_292 -> V_290 ;
F_122 ( * V_261 ) ;
* V_261 = NULL ;
goto V_360;
}
static int F_159 ( struct V_12 * V_13 , enum V_362 V_363 )
{
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
int V_15 = 0 ;
switch ( V_363 ) {
case V_364 :
break;
case V_365 :
F_160 ( & V_2 -> V_87 ) ;
F_161 ( V_13 ) ;
break;
default:
break;
}
return V_15 ;
}
static int F_162 ( const struct V_52 * V_53 , struct V_33 * exp ,
T_1 V_366 , void * V_367 , T_1 * V_368 , void * V_369 ,
struct V_370 * V_371 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
int V_15 = 0 ;
V_13 = F_6 ( exp ) ;
if ( V_13 == NULL ) {
F_3 ( V_372 , L_86 V_21 L_3 ,
exp -> V_23 . V_24 ) ;
return - V_26 ;
}
V_2 = & V_13 -> V_35 . V_2 ;
if ( V_366 >= strlen ( L_87 ) && ! strcmp ( V_367 , L_87 ) ) {
struct V_3 * V_4 ;
int V_14 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_7 ( * V_368 == sizeof( T_1 ) ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL || V_4 -> V_20 == NULL )
continue;
if ( ! F_163 ( V_53 , V_4 -> V_20 , V_366 , V_367 ,
V_368 , V_369 , NULL ) )
return 0 ;
}
return - V_26 ;
} else if ( F_164 ( V_373 ) || F_164 ( V_374 ) ) {
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_163 ( V_53 , V_2 -> V_19 [ 0 ] -> V_20 , V_366 , V_367 ,
V_368 , V_369 , NULL ) ;
if ( ! V_15 && F_164 ( V_374 ) )
exp -> V_50 = * (struct V_40 * ) V_369 ;
return V_15 ;
} else if ( F_164 ( V_375 ) ) {
* ( ( int * ) V_369 ) = V_2 -> V_7 . V_18 ;
return 0 ;
}
F_3 ( V_372 , L_88 ) ;
return - V_26 ;
}
int F_165 ( const struct V_52 * V_53 , struct V_33 * exp ,
T_3 V_366 , void * V_367 , T_3 V_368 ,
void * V_369 , struct V_376 * V_160 )
{
struct V_3 * V_4 ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
int V_15 = 0 ;
V_13 = F_6 ( exp ) ;
if ( V_13 == NULL ) {
F_3 ( V_372 , L_86 V_21 L_3 ,
exp -> V_23 . V_24 ) ;
return - V_26 ;
}
V_2 = & V_13 -> V_35 . V_2 ;
if ( F_164 ( V_377 ) || F_164 ( V_378 ) ) {
int V_14 , V_153 = 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL || V_4 -> V_20 == NULL )
continue;
V_153 = F_23 ( V_53 , V_4 -> V_20 ,
V_366 , V_367 , V_368 , V_369 , V_160 ) ;
if ( V_153 && V_15 == 0 )
V_15 = V_153 ;
}
return V_15 ;
}
return - V_26 ;
}
int F_166 ( struct V_33 * exp , struct V_379 * * V_380 ,
struct V_370 * V_371 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_101 * V_381 ;
struct V_101 * V_382 ;
int V_383 ;
int V_14 ;
V_383 = F_48 ( V_2 ) ;
if ( ! V_380 )
return V_383 ;
if ( * V_380 && ! V_371 ) {
F_78 ( * V_380 , V_383 ) ;
* V_380 = NULL ;
return 0 ;
}
if ( * V_380 == NULL ) {
F_77 ( * V_380 , V_383 ) ;
if ( * V_380 == NULL )
return - V_99 ;
}
if ( ! V_371 )
return V_383 ;
V_382 = (struct V_101 * ) V_371 ;
V_381 = (struct V_101 * ) * V_380 ;
if ( V_382 -> V_384 != V_385 &&
V_382 -> V_384 != V_386 )
return - V_26 ;
V_381 -> V_384 = F_150 ( V_382 -> V_384 ) ;
V_381 -> V_387 = F_150 ( V_382 -> V_387 ) ;
V_381 -> V_388 = F_150 ( V_382 -> V_388 ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_381 -> V_389 [ V_14 ] = V_382 -> V_389 [ V_14 ] ;
F_167 ( & V_381 -> V_389 [ V_14 ] , & V_382 -> V_389 [ V_14 ] ) ;
}
return V_383 ;
}
int F_168 ( struct V_33 * exp , struct V_370 * * V_382 ,
struct V_379 * V_282 , int V_390 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_101 * * V_391 = (struct V_101 * * ) V_382 ;
struct V_101 * V_392 = (struct V_101 * ) V_282 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
int V_383 ;
int V_14 ;
T_1 V_393 ;
V_383 = F_48 ( V_2 ) ;
if ( V_382 == NULL )
return V_383 ;
if ( * V_382 != NULL && V_282 == NULL ) {
F_78 ( * V_391 , V_383 ) ;
* V_382 = NULL ;
return 0 ;
}
F_7 ( V_383 == V_390 ) ;
F_77 ( * V_391 , V_383 ) ;
if ( * V_391 == NULL )
return - V_99 ;
if ( ! V_282 )
return V_383 ;
if ( V_392 -> V_384 == V_385 ||
V_392 -> V_384 == V_386 ||
V_392 -> V_384 == V_394 )
{
V_393 = F_169 ( V_392 -> V_384 ) ;
} else {
F_12 ( L_89 ) ;
F_170 () ;
}
( * V_391 ) -> V_384 = V_393 ;
( * V_391 ) -> V_387 = F_169 ( V_392 -> V_387 ) ;
( * V_391 ) -> V_388 = F_169 ( V_392 -> V_388 ) ;
for ( V_14 = 0 ; V_14 < ( * V_391 ) -> V_387 ; V_14 ++ ) {
( * V_391 ) -> V_389 [ V_14 ] = V_392 -> V_389 [ V_14 ] ;
F_171 ( & ( * V_391 ) -> V_389 [ V_14 ] , & ( * V_391 ) -> V_389 [ V_14 ] ) ;
}
return V_383 ;
}
static int F_172 ( struct V_33 * exp , const struct V_102 * V_225 ,
T_9 * V_308 , T_8 V_270 ,
T_10 V_244 , void * V_395 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
int V_15 = 0 ;
int V_153 ;
int V_14 ;
F_7 ( V_225 != NULL ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL || V_2 -> V_19 [ V_14 ] -> V_20 == NULL ||
V_2 -> V_19 [ V_14 ] -> V_6 == 0 )
continue;
V_153 = F_130 ( V_2 -> V_19 [ V_14 ] -> V_20 , V_225 ,
V_308 , V_270 , V_244 , V_395 ) ;
if ( ! V_15 )
V_15 = V_153 ;
}
return V_15 ;
}
int F_173 ( struct V_33 * exp , T_4 * V_281 , void * V_39 ,
T_4 * V_306 )
{
struct V_1 * V_2 = & exp -> V_34 -> V_35 . V_2 ;
int V_15 ;
V_15 = F_174 ( V_2 -> V_19 [ 0 ] -> V_20 , V_281 , V_39 , V_306 ) ;
return V_15 ;
}
T_8 F_175 ( struct V_33 * exp , T_4 V_244 ,
const struct V_102 * V_225 , T_11 type ,
T_9 * V_308 , T_8 V_270 ,
struct V_58 * V_281 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
T_8 V_15 ;
int V_14 ;
F_3 ( V_265 , L_90 V_127 L_3 , F_58 ( V_225 ) ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL ||
V_2 -> V_19 [ V_14 ] -> V_20 == NULL ||
V_2 -> V_19 [ V_14 ] -> V_6 == 0 )
continue;
V_15 = F_176 ( V_2 -> V_19 [ V_14 ] -> V_20 , V_244 , V_225 ,
type , V_308 , V_270 , V_281 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
int F_177 ( struct V_33 * exp , struct V_260 * V_206 ,
struct V_33 * V_396 , struct V_33 * V_397 ,
struct V_398 * V_399 )
{
struct V_1 * V_2 = & exp -> V_34 -> V_35 . V_2 ;
return F_178 ( V_2 -> V_19 [ 0 ] -> V_20 , V_206 , V_396 , V_397 , V_399 ) ;
}
int F_179 ( struct V_33 * exp , struct V_398 * V_399 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
if ( V_399 -> V_392 )
F_180 ( exp , ( void * ) & V_399 -> V_392 ) ;
return F_181 ( V_2 -> V_19 [ 0 ] -> V_20 , V_399 ) ;
}
int F_182 ( struct V_33 * exp ,
struct V_400 * V_401 ,
struct V_280 * V_266 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
V_4 = F_55 ( V_2 , & V_401 -> V_402 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
return F_183 ( V_4 -> V_20 , V_401 , V_266 ) ;
}
int F_184 ( struct V_33 * exp ,
struct V_400 * V_401 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
V_4 = F_55 ( V_2 , & V_401 -> V_402 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
return F_185 ( V_4 -> V_20 , V_401 ) ;
}
static int F_186 ( struct V_33 * exp ,
const struct V_102 * V_225 ,
struct V_252 * V_254 , T_1 V_262 ,
struct V_260 * * V_261 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , V_225 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_187 ( V_4 -> V_20 , V_225 , V_254 , V_262 , V_261 ) ;
return V_15 ;
}
static int F_188 ( struct V_33 * exp , struct V_252 * V_254 ,
T_12 V_403 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , & V_254 -> V_404 . V_405 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_189 ( V_4 -> V_20 , V_254 , V_403 ) ;
return V_15 ;
}
int F_190 ( struct V_33 * exp , struct V_260 * V_206 ,
const struct V_406 * V_407 , struct V_252 * * V_254 )
{
struct V_1 * V_2 = & exp -> V_34 -> V_35 . V_2 ;
return F_191 ( V_2 -> V_19 [ 0 ] -> V_20 , V_206 , V_407 , V_254 ) ;
}
int F_192 ( struct V_33 * exp ,
struct V_408 * V_409 ,
struct V_278 * V_279 )
{
struct V_195 * V_196 = & V_409 -> V_410 ;
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 = NULL ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , & V_196 -> V_197 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_193 ( V_4 -> V_20 , V_409 , V_279 ) ;
return V_15 ;
}
int F_194 ( struct V_33 * exp , struct V_280 * V_266 ,
struct V_102 * V_225 , T_4 * V_306 )
{
struct V_12 * V_13 = exp -> V_34 ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , V_225 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_195 ( V_4 -> V_20 , V_266 , V_225 , V_306 ) ;
return V_15 ;
}
int F_196 ( struct V_12 * V_411 , struct V_33 * exp ,
struct V_179 * V_180 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 = V_2 -> V_19 [ 0 ] ;
int V_15 = 0 , V_14 ;
T_4 V_412 , V_413 ;
if ( ! V_2 -> V_7 . V_18 || ! V_4 -> V_6 ) {
F_12 ( L_91 ) ;
return - V_214 ;
}
if ( V_180 -> V_414 != V_415 ) {
V_15 = V_179 ( V_4 -> V_20 , V_180 ) ;
return V_15 ;
}
V_412 = V_413 = 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
int V_153 ;
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL || V_4 -> V_20 == NULL || V_4 -> V_6 == 0 )
continue;
if ( ! V_4 -> V_6 ) {
F_3 ( V_416 , L_92 , V_14 ) ;
continue;
}
V_153 = V_179 ( V_4 -> V_20 , V_180 ) ;
if ( V_153 ) {
F_12 ( L_93 , V_14 , V_153 ) ;
if ( ! V_15 )
V_15 = V_153 ;
} else {
V_412 += V_180 -> V_417 . V_418 ;
V_413 += V_180 -> V_417 . V_419 ;
}
}
V_180 -> V_417 . V_418 = V_412 ;
V_180 -> V_417 . V_419 = V_413 ;
return V_15 ;
}
int F_197 ( struct V_12 * V_411 , struct V_33 * exp ,
struct V_179 * V_180 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_14 , V_15 = 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
int V_153 ;
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL || V_4 -> V_20 == NULL || ! V_4 -> V_6 ) {
F_12 ( L_94 , V_14 ) ;
return - V_214 ;
}
V_153 = F_198 ( V_4 -> V_20 , V_180 ) ;
if ( V_153 && ! V_15 )
V_15 = V_153 ;
}
return V_15 ;
}
int T_13 F_199 ( void )
{
struct V_229 V_230 ;
int V_15 ;
F_91 ( & V_230 ) ;
V_15 = F_200 ( & V_420 , & V_421 ,
V_230 . V_422 , V_423 , NULL ) ;
return V_15 ;
}
static void F_201 ( void )
{
F_202 ( V_423 ) ;
}
