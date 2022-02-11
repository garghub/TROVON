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
V_16 ;
F_3 ( V_17 , L_1 ,
V_2 , V_10 -> V_10 , V_5 ) ;
F_4 ( & V_2 -> V_18 ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_19 ; V_14 ++ ) {
V_4 = V_2 -> V_20 [ V_14 ] ;
if ( V_4 == NULL || V_4 -> V_21 == NULL )
continue;
F_3 ( V_17 , L_2 V_22 L_3 , V_14 ,
V_4 -> V_23 . V_10 , V_4 -> V_21 -> V_24 . V_25 ) ;
if ( F_5 ( V_10 , & V_4 -> V_23 ) )
break;
}
if ( V_14 == V_2 -> V_7 . V_19 )
GOTO ( V_26 , V_15 = - V_27 ) ;
V_13 = F_6 ( V_4 -> V_21 ) ;
if ( V_13 == NULL )
GOTO ( V_26 , V_15 = - V_28 ) ;
F_3 ( V_17 , L_4 ,
V_13 -> V_29 , V_13 -> V_9 . V_10 , V_13 -> V_30 , V_13 ,
V_13 -> V_31 -> V_32 , V_14 ) ;
F_7 ( strcmp ( V_13 -> V_31 -> V_32 , V_33 ) == 0 ) ;
if ( V_4 -> V_6 == V_5 ) {
F_3 ( V_17 , L_5 , V_13 ,
V_5 ? L_6 : L_7 ) ;
GOTO ( V_26 , V_15 ) ;
}
F_3 ( V_17 , L_8 , V_13 ,
V_5 ? L_6 : L_7 ) ;
F_1 ( V_2 , V_4 , V_5 ) ;
EXIT ;
V_26:
F_8 ( & V_2 -> V_18 ) ;
return V_15 ;
}
struct V_9 * F_9 ( struct V_34 * exp )
{
struct V_1 * V_2 = & exp -> V_35 -> V_36 . V_2 ;
return F_10 ( V_2 -> V_20 [ 0 ] -> V_21 ) ;
}
static int F_11 ( struct V_12 * V_13 , struct V_12 * V_37 ,
enum V_38 V_39 , void * V_40 )
{
struct V_41 * V_42 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_9 * V_10 ;
int V_15 = 0 ;
V_16 ;
if ( strcmp ( V_37 -> V_31 -> V_32 , V_33 ) ) {
F_12 ( L_9 ,
V_37 -> V_31 -> V_32 ,
V_37 -> V_29 ) ;
RETURN ( - V_27 ) ;
}
V_10 = & V_37 -> V_36 . V_43 . V_44 ;
if ( V_39 == V_45 || V_39 == V_46 ) {
V_15 = F_2 ( V_2 , V_10 ,
V_39 == V_45 ) ;
if ( V_15 ) {
F_12 ( L_10 ,
V_39 == V_45 ? L_6 : L_11 ,
V_10 -> V_10 , V_15 ) ;
RETURN ( V_15 ) ;
}
} else if ( V_39 == V_47 ) {
V_42 = & V_37 -> V_36 . V_43 . V_48 -> V_49 ;
V_13 -> V_50 -> V_51 = * V_42 ;
}
#if 0
else if (ev == OBD_NOTIFY_DISCON) {
fld_client_flush(&lmv->lmv_fld);
}
#endif
if ( V_13 -> V_52 )
V_15 = F_13 ( V_13 -> V_52 , V_37 , V_39 , V_40 ) ;
RETURN ( V_15 ) ;
}
static int F_14 ( const struct V_53 * V_54 ,
struct V_34 * * exp , struct V_12 * V_13 ,
struct V_9 * V_55 , struct V_41 * V_40 ,
void * V_56 )
{
struct V_57 * V_58 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_59 V_60 = { 0 } ;
int V_15 = 0 ;
V_16 ;
V_2 -> V_61 ++ ;
if ( V_2 -> V_61 > 1 ) {
* exp = NULL ;
RETURN ( 0 ) ;
}
V_15 = F_15 ( & V_60 , V_13 , V_55 ) ;
if ( V_15 ) {
F_12 ( L_12 , V_15 ) ;
RETURN ( V_15 ) ;
}
* exp = F_16 ( & V_60 ) ;
F_17 ( * exp ) ;
V_2 -> exp = * exp ;
V_2 -> V_62 = 0 ;
V_2 -> V_55 = * V_55 ;
if ( V_40 )
V_2 -> V_42 = * V_40 ;
if ( V_13 -> V_63 != NULL ) {
V_58 = V_13 -> V_63 ;
} else {
V_58 = F_18 ( L_13 , V_13 -> V_64 ,
NULL , NULL ) ;
if ( F_19 ( V_58 ) ) {
F_12 ( L_14 ,
V_13 -> V_31 -> V_32 , V_13 -> V_29 ) ;
V_58 = NULL ;
}
V_13 -> V_63 = V_58 ;
}
if ( V_40 -> V_65 & V_66 )
V_15 = F_20 ( V_13 ) ;
if ( V_15 && V_58 ) {
F_21 ( & V_58 ) ;
V_13 -> V_63 = NULL ;
}
RETURN ( V_15 ) ;
}
static void F_22 ( struct V_12 * V_13 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_14 ;
V_2 = & V_13 -> V_36 . V_2 ;
if ( V_2 -> V_67 == 0 )
return;
if ( V_2 -> V_62 == 0 )
return;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_19 ; V_14 ++ ) {
V_4 = V_2 -> V_20 [ V_14 ] ;
if ( V_4 == NULL || V_4 -> V_21 == NULL || V_4 -> V_6 == 0 )
continue;
F_23 ( NULL , V_4 -> V_21 , sizeof( V_68 ) ,
V_68 , 0 , NULL , NULL ) ;
}
}
static int F_24 ( struct V_34 * exp , int V_69 ,
int V_70 , int V_71 )
{
struct V_12 * V_13 = exp -> V_35 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
int V_14 ;
int V_15 = 0 ;
int V_72 = 0 ;
V_16 ;
if ( V_2 -> V_73 < V_69 ) {
V_2 -> V_73 = V_69 ;
V_72 = 1 ;
}
if ( V_2 -> V_74 < V_70 ) {
V_2 -> V_74 = V_70 ;
V_72 = 1 ;
}
if ( V_2 -> V_75 < V_71 ) {
V_2 -> V_75 = V_71 ;
V_72 = 1 ;
}
if ( V_72 == 0 )
RETURN ( 0 ) ;
if ( V_2 -> V_62 == 0 )
RETURN ( 0 ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_19 ; V_14 ++ ) {
if ( V_2 -> V_20 [ V_14 ] == NULL ||
V_2 -> V_20 [ V_14 ] -> V_21 == NULL ||
V_2 -> V_20 [ V_14 ] -> V_6 == 0 ) {
F_25 ( L_15 , V_13 -> V_29 , V_14 ) ;
continue;
}
V_15 = F_26 ( V_2 -> V_20 [ V_14 ] -> V_21 , V_69 , V_70 ,
V_71 ) ;
if ( V_15 ) {
F_12 ( L_16
L_17 , V_13 -> V_29 , V_14 , V_15 ) ;
break;
}
}
RETURN ( V_15 ) ;
}
int F_27 ( struct V_12 * V_13 , struct V_3 * V_4 )
{
struct V_57 * V_58 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_9 * V_55 = & V_2 -> V_55 ;
struct V_9 V_76 = { L_18 } ;
struct V_12 * V_77 ;
struct V_34 * V_78 ;
struct V_79 V_80 ;
int V_15 ;
V_16 ;
V_77 = F_28 ( & V_4 -> V_23 , V_33 ,
& V_13 -> V_9 ) ;
if ( ! V_77 ) {
F_12 ( L_19 , V_4 -> V_23 . V_10 ) ;
RETURN ( - V_27 ) ;
}
F_3 ( V_81 , L_20 ,
V_77 -> V_29 , V_77 -> V_9 . V_10 ,
V_4 -> V_23 . V_10 , V_13 -> V_9 . V_10 ,
V_55 -> V_10 ) ;
if ( ! V_77 -> V_82 ) {
F_12 ( L_21 , V_4 -> V_23 . V_10 ) ;
RETURN ( - V_27 ) ;
}
V_15 = F_29 ( NULL , & V_78 , V_77 , & V_76 ,
& V_2 -> V_42 , NULL ) ;
if ( V_15 ) {
F_12 ( L_22 , V_4 -> V_23 . V_10 , V_15 ) ;
RETURN ( V_15 ) ;
}
V_15 = F_30 ( V_77 , V_78 , V_83 ) ;
if ( V_15 )
RETURN ( V_15 ) ;
V_80 . V_84 = NULL ;
V_80 . V_85 = V_78 ;
V_80 . V_86 = V_4 -> V_87 ;
F_31 ( & V_2 -> V_88 , & V_80 ) ;
V_15 = F_32 ( V_77 , V_13 ) ;
if ( V_15 ) {
F_33 ( V_78 ) ;
F_12 ( L_23 ,
V_4 -> V_23 . V_10 , V_15 ) ;
RETURN ( V_15 ) ;
}
if ( V_13 -> V_52 ) {
V_15 = F_13 ( V_13 -> V_52 , V_78 -> V_35 ,
V_45 ,
( void * ) ( V_4 - V_2 -> V_20 [ 0 ] ) ) ;
if ( V_15 ) {
F_33 ( V_78 ) ;
RETURN ( V_15 ) ;
}
}
V_4 -> V_6 = 1 ;
V_4 -> V_21 = V_78 ;
V_2 -> V_7 . V_8 ++ ;
F_26 ( V_4 -> V_21 , V_2 -> V_73 ,
V_2 -> V_74 , V_2 -> V_75 ) ;
F_3 ( V_81 , L_24 ,
V_77 -> V_29 , V_77 -> V_9 . V_10 ,
F_34 ( & V_13 -> V_89 ) ) ;
V_58 = V_13 -> V_63 ;
if ( V_58 ) {
struct V_57 * V_90 ;
F_7 ( V_77 -> V_31 != NULL ) ;
F_7 ( V_77 -> V_31 -> V_32 != NULL ) ;
V_90 = F_35 ( V_77 -> V_29 ,
V_58 ,
L_25 ,
V_77 -> V_31 -> V_32 ,
V_77 -> V_29 ) ;
if ( V_90 == NULL ) {
F_12 ( L_26
L_27 ,
V_13 -> V_31 -> V_32 , V_13 -> V_29 ,
V_77 -> V_29 ) ;
F_21 ( & V_58 ) ;
V_13 -> V_63 = NULL ;
}
}
RETURN ( 0 ) ;
}
static void F_36 ( struct V_1 * V_2 , int V_91 )
{
if ( V_2 -> V_20 [ V_91 ] == NULL )
return;
F_37 ( V_2 -> V_20 [ V_91 ] ) ;
V_2 -> V_20 [ V_91 ] = NULL ;
return;
}
static int F_38 ( struct V_12 * V_13 , struct V_9 * V_92 ,
T_1 V_91 , int V_93 )
{
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_3 * V_4 ;
int V_15 = 0 ;
V_16 ;
F_3 ( V_81 , L_28 , V_92 -> V_10 , V_91 ) ;
F_39 ( V_2 ) ;
if ( V_2 -> V_7 . V_19 == 0 ) {
struct V_12 * V_77 ;
V_77 = F_28 ( V_92 , V_33 ,
& V_13 -> V_9 ) ;
if ( ! V_77 ) {
F_40 ( V_2 ) ;
F_12 ( L_29 ,
V_13 -> V_29 , V_92 -> V_10 , - V_27 ) ;
RETURN ( - V_27 ) ;
}
}
if ( ( V_91 < V_2 -> V_94 ) && ( V_2 -> V_20 [ V_91 ] != NULL ) ) {
V_4 = V_2 -> V_20 [ V_91 ] ;
F_12 ( L_30
L_31 , V_13 -> V_29 ,
F_41 ( & V_4 -> V_23 ) , V_91 , - V_95 ) ;
F_40 ( V_2 ) ;
RETURN ( - V_95 ) ;
}
if ( V_91 >= V_2 -> V_94 ) {
struct V_3 * * V_96 , * * V_97 = NULL ;
T_1 V_98 = 1 ;
T_1 V_99 = 0 ;
while ( V_98 < V_91 + 1 )
V_98 = V_98 << 1 ;
F_42 ( V_96 , sizeof( * V_96 ) * V_98 ) ;
if ( V_96 == NULL ) {
F_40 ( V_2 ) ;
RETURN ( - V_100 ) ;
}
if ( V_2 -> V_94 ) {
memcpy ( V_96 , V_2 -> V_20 ,
sizeof( * V_96 ) * V_2 -> V_94 ) ;
V_97 = V_2 -> V_20 ;
V_99 = V_2 -> V_94 ;
}
V_2 -> V_20 = V_96 ;
V_2 -> V_94 = V_98 ;
F_43 () ;
if ( V_97 )
F_44 ( V_97 , sizeof( * V_97 ) * V_99 ) ;
F_3 ( V_81 , L_32 , V_2 -> V_20 ,
V_2 -> V_94 ) ;
}
F_45 ( V_4 ) ;
if ( ! V_4 ) {
F_40 ( V_2 ) ;
RETURN ( - V_100 ) ;
}
F_46 ( & V_4 -> V_101 ) ;
V_4 -> V_87 = V_91 ;
V_4 -> V_23 = * V_92 ;
V_4 -> V_6 = 0 ;
V_2 -> V_20 [ V_91 ] = V_4 ;
if ( V_91 >= V_2 -> V_7 . V_19 )
V_2 -> V_7 . V_19 = V_91 + 1 ;
if ( V_2 -> V_62 ) {
V_15 = F_27 ( V_13 , V_4 ) ;
if ( V_15 ) {
F_4 ( & V_2 -> V_18 ) ;
V_2 -> V_7 . V_19 -- ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_8 ( & V_2 -> V_18 ) ;
} else {
int V_69 = sizeof( struct V_102 ) +
V_2 -> V_7 . V_19 *
sizeof( struct V_103 ) ;
F_24 ( V_13 -> V_50 , V_69 , 0 , 0 ) ;
}
}
F_40 ( V_2 ) ;
RETURN ( V_15 ) ;
}
int F_20 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_3 * V_4 ;
int V_14 ;
int V_15 ;
int V_69 ;
V_16 ;
if ( V_2 -> V_62 )
RETURN ( 0 ) ;
F_39 ( V_2 ) ;
if ( V_2 -> V_62 ) {
F_40 ( V_2 ) ;
RETURN ( 0 ) ;
}
if ( V_2 -> V_7 . V_19 == 0 ) {
F_40 ( V_2 ) ;
F_12 ( L_33 , V_13 -> V_29 ) ;
RETURN ( - V_27 ) ;
}
F_3 ( V_81 , L_34 ,
V_2 -> V_55 . V_10 , V_13 -> V_29 ) ;
F_7 ( V_2 -> V_20 != NULL ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_19 ; V_14 ++ ) {
V_4 = V_2 -> V_20 [ V_14 ] ;
if ( V_4 == NULL )
continue;
V_15 = F_27 ( V_13 , V_4 ) ;
if ( V_15 )
GOTO ( V_104 , V_15 ) ;
}
F_22 ( V_13 ) ;
F_47 ( V_2 -> exp ) ;
V_2 -> V_62 = 1 ;
V_69 = F_48 ( V_2 ) ;
F_24 ( V_13 -> V_50 , V_69 , 0 , 0 ) ;
F_40 ( V_2 ) ;
RETURN ( 0 ) ;
V_104:
while ( V_14 -- > 0 ) {
int V_105 ;
V_4 = V_2 -> V_20 [ V_14 ] ;
if ( V_4 == NULL )
continue;
V_4 -> V_6 = 0 ;
if ( V_4 -> V_21 ) {
-- V_2 -> V_7 . V_8 ;
V_105 = F_33 ( V_4 -> V_21 ) ;
if ( V_105 ) {
F_12 ( L_35
L_36 ,
V_4 -> V_23 . V_10 , V_14 , V_105 ) ;
}
}
}
F_49 ( V_2 -> exp ) ;
F_40 ( V_2 ) ;
RETURN ( V_15 ) ;
}
static int F_50 ( struct V_12 * V_13 , struct V_3 * V_4 )
{
struct V_57 * V_58 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_12 * V_77 ;
int V_15 ;
V_16 ;
F_7 ( V_4 != NULL ) ;
F_7 ( V_13 != NULL ) ;
V_77 = F_6 ( V_4 -> V_21 ) ;
if ( V_77 ) {
V_77 -> V_106 = V_13 -> V_106 ;
V_77 -> V_107 = V_13 -> V_107 ;
V_77 -> V_108 = V_13 -> V_108 ;
}
V_58 = V_13 -> V_63 ;
if ( V_58 )
F_51 ( V_77 -> V_29 , V_58 ) ;
V_15 = F_52 ( V_4 -> V_21 -> V_35 ) ;
if ( V_15 )
F_12 ( L_37 ) ;
F_3 ( V_17 , L_38 ,
V_4 -> V_21 -> V_35 -> V_29 ,
V_4 -> V_21 -> V_35 -> V_9 . V_10 ) ;
F_32 ( V_4 -> V_21 -> V_35 , NULL ) ;
V_15 = F_33 ( V_4 -> V_21 ) ;
if ( V_15 ) {
if ( V_4 -> V_6 ) {
F_12 ( L_39 ,
V_4 -> V_23 . V_10 , V_15 ) ;
}
}
F_1 ( V_2 , V_4 , 0 ) ;
V_4 -> V_21 = NULL ;
RETURN ( 0 ) ;
}
static int F_53 ( struct V_34 * exp )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
int V_15 ;
int V_14 ;
V_16 ;
if ( ! V_2 -> V_20 )
goto V_109;
V_2 -> V_61 -- ;
if ( V_2 -> V_61 != 0 )
goto V_109;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_19 ; V_14 ++ ) {
if ( V_2 -> V_20 [ V_14 ] == NULL || V_2 -> V_20 [ V_14 ] -> V_21 == NULL )
continue;
F_50 ( V_13 , V_2 -> V_20 [ V_14 ] ) ;
}
if ( V_13 -> V_63 )
F_21 ( ( V_110 * * ) & V_13 -> V_63 ) ;
else
F_12 ( L_40 ,
V_13 -> V_31 -> V_32 , V_13 -> V_29 ) ;
V_109:
if ( ! V_2 -> V_62 )
F_47 ( exp ) ;
V_15 = F_49 ( exp ) ;
if ( V_2 -> V_61 == 0 )
V_2 -> V_62 = 0 ;
RETURN ( V_15 ) ;
}
static int F_54 ( struct V_34 * exp , int V_111 , void * V_112 , void * V_113 )
{
struct V_12 * V_114 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_114 -> V_36 . V_2 ;
struct V_115 * V_116 ;
struct V_3 * V_4 ;
struct V_115 * V_117 = NULL ;
int V_118 = 0 ;
int V_15 ;
V_116 = (struct V_115 * ) V_112 ;
V_4 = F_55 ( V_2 , & V_116 -> V_119 ) ;
if ( F_19 ( V_4 ) )
RETURN ( F_56 ( V_4 ) ) ;
V_120:
V_15 = F_57 ( V_121 , V_4 -> V_21 , V_111 , V_116 , V_113 ) ;
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
F_3 ( V_17 , L_41 V_129 L_42 V_130 L_43 ,
V_4 -> V_21 -> V_35 -> V_29 ,
V_116 -> V_126 , F_58 ( & V_116 -> V_119 ) , V_116 -> V_131 ,
V_116 -> V_132 ) ;
if ( V_15 == 0 )
GOTO ( V_123 , V_15 ) ;
if ( V_117 == NULL ) {
V_118 = sizeof( * V_117 ) + V_133 ;
F_42 ( V_117 , V_118 ) ;
if ( V_117 == NULL )
GOTO ( V_123 , V_15 = - V_100 ) ;
V_117 -> V_127 = V_133 ;
}
if ( ! F_59 ( & V_116 -> V_119 ) ) {
F_12 ( L_44 V_129 L_45 ,
V_4 -> V_21 -> V_35 -> V_29 ,
F_58 ( & V_116 -> V_119 ) , - V_27 ) ;
GOTO ( V_123 , V_15 = - V_27 ) ;
}
V_4 = F_55 ( V_2 , & V_116 -> V_119 ) ;
if ( F_19 ( V_4 ) )
GOTO ( V_123 , V_15 = - V_27 ) ;
V_117 -> V_119 = V_116 -> V_119 ;
V_117 -> V_131 = - 1 ;
V_117 -> V_132 = - 1 ;
memset ( V_117 -> V_126 , 0 , V_117 -> V_127 ) ;
V_116 = V_117 ;
goto V_120;
V_123:
if ( V_117 != NULL )
F_44 ( V_117 , V_118 ) ;
RETURN ( V_15 ) ;
}
static int F_60 ( unsigned int V_134 , struct V_34 * exp ,
int V_111 , void * V_112 , void * V_113 )
{
struct V_12 * V_114 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_114 -> V_36 . V_2 ;
int V_14 = 0 ;
int V_15 = 0 ;
int V_135 = 0 ;
int V_136 = V_2 -> V_7 . V_19 ;
V_16 ;
if ( V_136 == 0 )
RETURN ( - V_137 ) ;
switch ( V_134 ) {
case V_138 : {
struct V_139 * V_40 = V_112 ;
struct V_12 * V_77 ;
struct V_140 V_141 = { 0 } ;
T_1 V_91 ;
memcpy ( & V_91 , V_40 -> V_142 , sizeof( T_1 ) ) ;
if ( ( V_91 >= V_136 ) )
RETURN ( - V_143 ) ;
if ( V_2 -> V_20 [ V_91 ] == NULL ||
V_2 -> V_20 [ V_91 ] -> V_6 == 0 )
RETURN ( - V_144 ) ;
V_77 = F_6 ( V_2 -> V_20 [ V_91 ] -> V_21 ) ;
if ( ! V_77 )
RETURN ( - V_27 ) ;
if ( F_61 ( V_40 -> V_145 , F_62 ( V_77 ) ,
F_63 ( ( int ) V_40 -> V_146 ,
( int ) sizeof( struct V_9 ) ) ) )
RETURN ( - V_147 ) ;
V_15 = V_140 ( NULL , V_2 -> V_20 [ V_91 ] -> V_21 , & V_141 ,
F_64 ( - V_148 ) ,
0 ) ;
if ( V_15 )
RETURN ( V_15 ) ;
if ( F_61 ( V_40 -> V_149 , & V_141 ,
F_63 ( ( int ) V_40 -> V_150 ,
( int ) sizeof( V_141 ) ) ) )
RETURN ( - V_147 ) ;
break;
}
case V_151 : {
struct V_152 * V_153 = V_112 ;
struct V_3 * V_4 = NULL ;
struct V_154 * V_155 ;
if ( V_153 -> V_156 == V_157 ) {
if ( V_153 -> V_158 < 0 || V_136 <= V_153 -> V_158 )
RETURN ( - V_27 ) ;
V_4 = V_2 -> V_20 [ V_153 -> V_158 ] ;
if ( V_4 == NULL || V_4 -> V_21 == NULL )
RETURN ( - V_27 ) ;
} else if ( V_153 -> V_156 == V_159 ) {
for ( V_14 = 0 ; V_14 < V_136 ; V_14 ++ ) {
V_4 = V_2 -> V_20 [ V_14 ] ;
if ( V_4 == NULL )
continue;
if ( ! F_5 ( & V_4 -> V_23 ,
& V_153 -> V_9 ) )
continue;
if ( V_4 -> V_21 == NULL )
RETURN ( - V_27 ) ;
break;
}
} else {
RETURN ( - V_27 ) ;
}
if ( V_14 >= V_136 )
RETURN ( - V_160 ) ;
F_7 ( V_4 && V_4 -> V_21 ) ;
F_45 ( V_155 ) ;
if ( ! V_155 )
RETURN ( - V_100 ) ;
F_65 ( V_155 , V_153 ) ;
V_15 = V_154 ( V_4 -> V_21 , V_155 ) ;
if ( V_15 == 0 ) {
F_65 ( V_153 , V_155 ) ;
V_153 -> V_156 = V_157 ;
V_153 -> V_9 = V_4 -> V_23 ;
}
F_37 ( V_155 ) ;
break;
}
case V_161 :
case V_162 : {
struct V_163 * V_164 = V_112 ;
if ( V_164 -> V_165 >= V_136 )
RETURN ( - V_143 ) ;
if ( V_2 -> V_20 [ V_164 -> V_165 ] == NULL ||
V_2 -> V_20 [ V_164 -> V_165 ] -> V_21 == NULL ||
V_2 -> V_20 [ V_164 -> V_165 ] -> V_6 == 0 )
RETURN ( - V_143 ) ;
V_15 = F_57 ( V_134 , V_2 -> V_20 [ V_164 -> V_165 ] -> V_21 ,
sizeof( * V_164 ) , V_164 , NULL ) ;
break;
}
case V_166 : {
if ( V_2 -> V_20 [ 0 ] == NULL )
RETURN ( - V_144 ) ;
V_15 = F_57 ( V_134 , V_2 -> V_20 [ 0 ] -> V_21 , V_111 , V_112 , V_113 ) ;
break;
}
case V_121 : {
V_15 = F_54 ( exp , V_111 , V_112 , V_113 ) ;
break;
}
case V_167 :
case V_168 :
case V_169 :
case V_170 : {
struct V_171 * V_172 = V_112 ;
struct V_3 * V_173 , * V_174 ;
V_173 = F_55 ( V_2 , & V_172 -> V_175 ) ;
if ( F_19 ( V_173 ) )
RETURN ( F_56 ( V_173 ) ) ;
V_174 = F_55 ( V_2 , & V_172 -> V_176 ) ;
if ( F_19 ( V_174 ) )
RETURN ( F_56 ( V_174 ) ) ;
if ( ( V_173 -> V_21 == NULL ) || ( V_174 -> V_21 == NULL ) )
RETURN ( - V_27 ) ;
if ( V_173 -> V_87 != V_174 -> V_87 )
RETURN ( - V_177 ) ;
V_15 = F_57 ( V_134 , V_173 -> V_21 , V_111 , V_112 , V_113 ) ;
break;
}
default:
for ( V_14 = 0 ; V_14 < V_136 ; V_14 ++ ) {
struct V_12 * V_77 ;
int V_178 ;
if ( V_2 -> V_20 [ V_14 ] == NULL ||
V_2 -> V_20 [ V_14 ] -> V_21 == NULL )
continue;
V_77 = F_6 ( V_2 -> V_20 [ V_14 ] -> V_21 ) ;
V_77 -> V_106 = V_114 -> V_106 ;
V_178 = F_57 ( V_134 , V_2 -> V_20 [ V_14 ] -> V_21 , V_111 ,
V_112 , V_113 ) ;
if ( V_178 == - V_144 && V_134 == V_179 ) {
RETURN ( V_178 ) ;
} else if ( V_178 ) {
if ( V_2 -> V_20 [ V_14 ] -> V_6 ) {
F_12 ( L_46
L_47 ,
V_2 -> V_20 [ V_14 ] -> V_23 . V_10 ,
V_14 , V_134 , V_178 ) ;
if ( ! V_15 )
V_15 = V_178 ;
}
} else
V_135 = 1 ;
}
if ( ! V_135 && ! V_15 )
V_15 = - V_180 ;
}
RETURN ( V_15 ) ;
}
static int F_66 ( struct V_12 * V_13 ,
struct V_171 * V_172 ,
T_2 * V_181 )
{
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
V_16 ;
F_7 ( V_181 != NULL ) ;
if ( V_2 -> V_7 . V_19 == 1 ) {
* V_181 = 0 ;
RETURN ( 0 ) ;
}
if ( V_172 -> V_182 & V_183 ) {
struct V_184 * V_185 ;
V_185 = (struct V_184 * ) V_172 -> V_172 ;
if ( V_185 -> V_186 == V_187 &&
V_185 -> V_188 != - 1 ) {
if ( V_185 -> V_188 >= V_2 -> V_7 . V_19 ) {
F_12 ( L_48
L_31 , V_13 -> V_29 ,
V_185 -> V_188 ,
V_2 -> V_7 . V_19 , - V_189 ) ;
RETURN ( - V_189 ) ;
}
* V_181 = V_185 -> V_188 ;
RETURN ( 0 ) ;
}
}
* V_181 = V_172 -> V_190 ;
RETURN ( 0 ) ;
}
int F_67 ( struct V_1 * V_2 , struct V_103 * V_191 ,
T_2 V_181 )
{
struct V_3 * V_4 ;
int V_15 ;
V_16 ;
V_4 = F_68 ( V_2 , V_181 ) ;
if ( F_19 ( V_4 ) )
RETURN ( F_56 ( V_4 ) ) ;
F_69 ( & V_4 -> V_101 ) ;
if ( V_4 -> V_6 == 0 || V_4 -> V_21 == NULL )
GOTO ( V_192 , V_15 = - V_143 ) ;
V_15 = F_70 ( V_4 -> V_21 , V_191 , NULL ) ;
if ( V_15 > 0 ) {
F_7 ( F_59 ( V_191 ) ) ;
V_15 = 0 ;
}
EXIT ;
V_192:
F_71 ( & V_4 -> V_101 ) ;
return V_15 ;
}
int F_72 ( struct V_34 * exp , struct V_103 * V_191 ,
struct V_171 * V_172 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
T_2 V_181 = 0 ;
int V_15 ;
V_16 ;
F_7 ( V_172 != NULL ) ;
F_7 ( V_191 != NULL ) ;
V_15 = F_66 ( V_13 , V_172 , & V_181 ) ;
if ( V_15 ) {
F_12 ( L_49
L_50 , V_15 ) ;
RETURN ( V_15 ) ;
}
V_15 = F_67 ( V_2 , V_191 , V_181 ) ;
if ( V_15 ) {
F_12 ( L_51 , V_15 ) ;
RETURN ( V_15 ) ;
}
RETURN ( V_15 ) ;
}
static int F_73 ( struct V_12 * V_13 , struct V_193 * V_194 )
{
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_195 V_196 ;
struct V_197 * V_7 ;
int V_15 ;
V_16 ;
if ( F_74 ( V_194 , 1 ) < 1 ) {
F_12 ( L_52 ) ;
RETURN ( - V_27 ) ;
}
V_7 = (struct V_197 * ) F_75 ( V_194 , 1 ) ;
if ( sizeof( * V_7 ) > F_74 ( V_194 , 1 ) ) {
F_12 ( L_53 ,
( int ) sizeof( * V_7 ) , F_74 ( V_194 , 1 ) ) ;
RETURN ( - V_27 ) ;
}
F_42 ( V_2 -> V_20 , sizeof( * V_2 -> V_20 ) * 32 ) ;
if ( V_2 -> V_20 == NULL )
RETURN ( - V_100 ) ;
V_2 -> V_94 = 32 ;
F_76 ( & V_2 -> V_7 . V_198 , V_7 -> V_198 . V_10 ) ;
V_2 -> V_7 . V_19 = 0 ;
V_2 -> V_7 . V_8 = 0 ;
V_2 -> V_75 = 0 ;
V_2 -> V_74 = 0 ;
V_2 -> V_73 = 0 ;
V_2 -> V_199 = V_200 ;
F_77 ( & V_2 -> V_18 ) ;
F_46 ( & V_2 -> V_201 ) ;
F_78 ( & V_196 ) ;
F_79 ( V_13 , V_196 . V_202 ) ;
#ifdef F_80
{
V_15 = F_81 ( V_13 -> V_64 , L_54 ,
0444 , & V_203 , V_13 ) ;
if ( V_15 )
F_25 ( L_55 ,
V_13 -> V_29 , V_15 ) ;
}
#endif
V_15 = F_82 ( & V_2 -> V_88 , V_13 -> V_29 ,
V_204 ) ;
if ( V_15 ) {
F_12 ( L_56 , V_15 ) ;
GOTO ( V_192 , V_15 ) ;
}
RETURN ( 0 ) ;
V_192:
return V_15 ;
}
static int F_83 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
V_16 ;
F_84 ( & V_2 -> V_88 ) ;
if ( V_2 -> V_20 != NULL ) {
int V_14 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_19 ; V_14 ++ ) {
if ( V_2 -> V_20 [ V_14 ] == NULL )
continue;
F_36 ( V_2 , V_14 ) ;
}
F_44 ( V_2 -> V_20 , sizeof( * V_2 -> V_20 ) * V_2 -> V_94 ) ;
V_2 -> V_94 = 0 ;
}
RETURN ( 0 ) ;
}
static int F_85 ( struct V_12 * V_13 , T_3 V_111 , void * V_205 )
{
struct V_193 * V_194 = V_205 ;
struct V_9 V_9 ;
int V_93 ;
T_1 V_91 ;
int V_15 ;
V_16 ;
switch ( V_194 -> V_206 ) {
case V_207 :
if ( F_74 ( V_194 , 1 ) > sizeof( V_9 . V_10 ) )
GOTO ( V_192 , V_15 = - V_27 ) ;
F_76 ( & V_9 , F_75 ( V_194 , 1 ) ) ;
if ( sscanf ( F_75 ( V_194 , 2 ) , L_57 , & V_91 ) != 1 )
GOTO ( V_192 , V_15 = - V_27 ) ;
if ( sscanf ( F_75 ( V_194 , 3 ) , L_57 , & V_93 ) != 1 )
GOTO ( V_192 , V_15 = - V_27 ) ;
V_15 = F_38 ( V_13 , & V_9 , V_91 , V_93 ) ;
GOTO ( V_192 , V_15 ) ;
default:
F_12 ( L_58 , V_194 -> V_206 ) ;
GOTO ( V_192 , V_15 = - V_27 ) ;
}
V_192:
RETURN ( V_15 ) ;
}
static int F_86 ( const struct V_53 * V_54 , struct V_34 * exp ,
struct V_140 * V_208 , T_4 V_209 , T_1 V_210 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_140 * V_211 ;
int V_15 = 0 ;
int V_14 ;
V_16 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
RETURN ( V_15 ) ;
F_42 ( V_211 , sizeof( * V_211 ) ) ;
if ( V_211 == NULL )
RETURN ( - V_100 ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_19 ; V_14 ++ ) {
if ( V_2 -> V_20 [ V_14 ] == NULL || V_2 -> V_20 [ V_14 ] -> V_21 == NULL )
continue;
V_15 = V_140 ( V_54 , V_2 -> V_20 [ V_14 ] -> V_21 , V_211 ,
V_209 , V_210 ) ;
if ( V_15 ) {
F_12 ( L_59 , V_14 ,
V_2 -> V_20 [ V_14 ] -> V_21 -> V_35 -> V_29 ,
V_15 ) ;
GOTO ( V_212 , V_15 ) ;
}
if ( V_14 == 0 ) {
* V_208 = * V_211 ;
if ( V_210 & V_213 )
GOTO ( V_212 , V_15 ) ;
} else {
V_208 -> V_214 += V_211 -> V_214 ;
V_208 -> V_215 += V_211 -> V_215 ;
V_208 -> V_216 += V_211 -> V_216 ;
V_208 -> V_217 += V_211 -> V_217 ;
}
}
EXIT ;
V_212:
F_44 ( V_211 , sizeof( * V_211 ) ) ;
return V_15 ;
}
static int F_87 ( struct V_34 * exp ,
struct V_103 * V_191 ,
struct V_218 * * V_219 )
{
struct V_12 * V_13 = exp -> V_35 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
int V_15 ;
V_16 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
RETURN ( V_15 ) ;
V_15 = F_88 ( V_2 -> V_20 [ 0 ] -> V_21 , V_191 , V_219 ) ;
RETURN ( V_15 ) ;
}
static int F_89 ( struct V_34 * exp , const struct V_103 * V_191 ,
struct V_218 * V_220 , T_5 V_221 , const char * V_222 ,
const char * V_223 , int V_224 , int V_225 ,
int V_210 , struct V_226 * * V_227 )
{
struct V_12 * V_13 = exp -> V_35 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_16 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
RETURN ( V_15 ) ;
V_4 = F_55 ( V_2 , V_191 ) ;
if ( F_19 ( V_4 ) )
RETURN ( F_56 ( V_4 ) ) ;
V_15 = F_90 ( V_4 -> V_21 , V_191 , V_220 , V_221 , V_222 , V_223 ,
V_224 , V_225 , V_210 , V_227 ) ;
RETURN ( V_15 ) ;
}
static int F_91 ( struct V_34 * exp , const struct V_103 * V_191 ,
struct V_218 * V_220 , T_5 V_221 , const char * V_222 ,
const char * V_223 , int V_224 , int V_225 ,
int V_210 , T_1 V_228 ,
struct V_226 * * V_227 )
{
struct V_12 * V_13 = exp -> V_35 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_16 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
RETURN ( V_15 ) ;
V_4 = F_55 ( V_2 , V_191 ) ;
if ( F_19 ( V_4 ) )
RETURN ( F_56 ( V_4 ) ) ;
V_15 = F_92 ( V_4 -> V_21 , V_191 , V_220 , V_221 , V_222 , V_223 ,
V_224 , V_225 , V_210 , V_228 ,
V_227 ) ;
RETURN ( V_15 ) ;
}
static int F_93 ( struct V_34 * exp , struct V_171 * V_172 ,
struct V_226 * * V_227 )
{
struct V_12 * V_13 = exp -> V_35 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_16 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
RETURN ( V_15 ) ;
V_4 = F_55 ( V_2 , & V_172 -> V_175 ) ;
if ( F_19 ( V_4 ) )
RETURN ( F_56 ( V_4 ) ) ;
if ( V_172 -> V_229 & V_230 ) {
V_172 -> V_190 = V_4 -> V_87 ;
RETURN ( 0 ) ;
}
V_15 = F_94 ( V_4 -> V_21 , V_172 , V_227 ) ;
RETURN ( V_15 ) ;
}
static int F_95 ( struct V_34 * exp , const struct V_103 * V_191 )
{
struct V_12 * V_13 = exp -> V_35 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
int V_14 ;
int V_15 ;
V_16 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
RETURN ( V_15 ) ;
F_3 ( V_231 , L_60 V_129 L_3 , F_58 ( V_191 ) ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_19 ; V_14 ++ ) {
if ( V_2 -> V_20 [ V_14 ] == NULL || V_2 -> V_20 [ V_14 ] -> V_21 == NULL )
continue;
F_96 ( V_2 -> V_20 [ V_14 ] -> V_21 , V_191 ) ;
}
RETURN ( 0 ) ;
}
static int F_97 ( struct V_34 * exp , const struct V_103 * V_191 ,
T_6 V_232 , void * V_40 )
{
struct V_12 * V_13 = exp -> V_35 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
int V_14 ;
int V_15 ;
V_16 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
RETURN ( V_15 ) ;
F_3 ( V_231 , L_60 V_129 L_3 , F_58 ( V_191 ) ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_19 ; V_14 ++ ) {
if ( V_2 -> V_20 [ V_14 ] == NULL || V_2 -> V_20 [ V_14 ] -> V_21 == NULL )
continue;
V_15 = F_98 ( V_2 -> V_20 [ V_14 ] -> V_21 , V_191 , V_232 , V_40 ) ;
if ( V_15 )
RETURN ( V_15 ) ;
}
RETURN ( V_15 ) ;
}
static int F_99 ( struct V_34 * exp , struct V_171 * V_172 ,
struct V_233 * V_234 , struct V_226 * * V_227 )
{
struct V_12 * V_13 = exp -> V_35 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_16 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
RETURN ( V_15 ) ;
V_4 = F_55 ( V_2 , & V_172 -> V_175 ) ;
if ( F_19 ( V_4 ) )
RETURN ( F_56 ( V_4 ) ) ;
F_3 ( V_231 , L_61 V_129 L_3 , F_58 ( & V_172 -> V_175 ) ) ;
V_15 = F_100 ( V_4 -> V_21 , V_172 , V_234 , V_227 ) ;
RETURN ( V_15 ) ;
}
struct V_3
* F_101 ( struct V_1 * V_2 , struct V_171 * V_172 ,
struct V_103 * V_191 )
{
struct V_3 * V_4 ;
V_4 = F_55 ( V_2 , V_191 ) ;
if ( F_19 ( V_4 ) )
return V_4 ;
V_172 -> V_190 = V_4 -> V_87 ;
return V_4 ;
}
int F_102 ( struct V_34 * exp , struct V_171 * V_172 ,
const void * V_40 , int V_235 , int V_236 , T_1 V_237 ,
T_1 V_238 , T_7 V_239 , T_4 V_240 ,
struct V_226 * * V_227 )
{
struct V_12 * V_13 = exp -> V_35 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_16 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
RETURN ( V_15 ) ;
if ( ! V_2 -> V_7 . V_8 )
RETURN ( - V_180 ) ;
V_4 = F_101 ( V_2 , V_172 , & V_172 -> V_175 ) ;
if ( F_19 ( V_4 ) )
RETURN ( F_56 ( V_4 ) ) ;
V_15 = F_72 ( exp , & V_172 -> V_176 , V_172 ) ;
if ( V_15 )
RETURN ( V_15 ) ;
F_3 ( V_231 , L_62 V_129 L_63 ,
V_172 -> V_241 , V_172 -> V_242 , F_58 ( & V_172 -> V_175 ) ,
V_172 -> V_190 ) ;
V_172 -> V_229 |= V_243 ;
V_15 = F_103 ( V_4 -> V_21 , V_172 , V_40 , V_235 , V_236 , V_237 , V_238 ,
V_239 , V_240 , V_227 ) ;
if ( V_15 == 0 ) {
if ( * V_227 == NULL )
RETURN ( V_15 ) ;
F_3 ( V_231 , L_64 V_129 L_3 , F_58 ( & V_172 -> V_176 ) ) ;
}
RETURN ( V_15 ) ;
}
static int F_104 ( struct V_34 * exp ,
struct V_171 * V_172 ,
struct V_233 * V_234 )
{
struct V_12 * V_13 = exp -> V_35 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_16 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
RETURN ( V_15 ) ;
V_4 = F_55 ( V_2 , & V_172 -> V_175 ) ;
if ( F_19 ( V_4 ) )
RETURN ( F_56 ( V_4 ) ) ;
V_15 = F_105 ( V_4 -> V_21 , V_172 , V_234 ) ;
RETURN ( V_15 ) ;
}
static int
F_106 ( struct V_34 * exp , struct V_244 * V_245 ,
struct V_246 * V_232 , struct V_171 * V_172 ,
struct V_59 * V_247 , void * V_248 , int V_249 ,
int V_250 )
{
struct V_226 * V_251 = V_232 -> V_252 . V_253 . V_254 ;
struct V_12 * V_13 = exp -> V_35 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_59 V_255 ;
struct V_3 * V_4 ;
struct V_171 * V_256 ;
struct V_103 V_257 ;
struct V_258 * V_259 ;
int V_15 = 0 ;
int V_260 ;
V_16 ;
V_259 = F_107 ( & V_251 -> V_261 , & V_262 ) ;
F_7 ( V_259 != NULL ) ;
if ( ! ( V_259 -> V_221 & V_263 ) )
RETURN ( 0 ) ;
F_3 ( V_231 , L_65 V_129 L_66 V_129 L_3 ,
F_108 ( V_232 ) , F_58 ( & V_172 -> V_175 ) , F_58 ( & V_259 -> V_257 ) ) ;
V_260 = V_232 -> V_252 . V_253 . V_264 ;
F_7 ( V_260 != 0 ) ;
memcpy ( & V_255 , V_247 , sizeof( V_255 ) ) ;
V_232 -> V_252 . V_253 . V_264 = 0 ;
V_232 -> V_252 . V_253 . V_254 = NULL ;
V_257 = V_259 -> V_257 ;
V_232 -> V_252 . V_253 . V_265 &= ~ V_266 ;
F_109 ( V_251 ) ;
V_4 = F_55 ( V_2 , & V_257 ) ;
if ( F_19 ( V_4 ) )
GOTO ( V_192 , V_15 = F_56 ( V_4 ) ) ;
F_45 ( V_256 ) ;
if ( V_256 == NULL )
GOTO ( V_192 , V_15 = - V_100 ) ;
V_256 -> V_175 = V_257 ;
V_256 -> V_267 = V_268 ;
V_15 = F_110 ( V_4 -> V_21 , V_245 , V_232 , V_256 , V_247 ,
V_248 , V_249 , NULL , V_250 ) ;
F_37 ( V_256 ) ;
EXIT ;
V_192:
F_111 ( & V_255 , V_260 ) ;
return V_15 ;
}
static int
F_112 ( struct V_34 * exp , struct V_244 * V_245 ,
struct V_246 * V_232 , struct V_171 * V_172 ,
struct V_59 * V_247 , void * V_248 , int V_249 ,
struct V_226 * * V_251 , T_4 V_250 )
{
struct V_12 * V_13 = exp -> V_35 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_16 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
RETURN ( V_15 ) ;
F_3 ( V_231 , L_67 V_129 L_3 ,
F_108 ( V_232 ) , F_58 ( & V_172 -> V_175 ) ) ;
V_4 = F_101 ( V_2 , V_172 , & V_172 -> V_175 ) ;
if ( F_19 ( V_4 ) )
RETURN ( F_56 ( V_4 ) ) ;
F_3 ( V_231 , L_67 V_129 L_68 ,
F_108 ( V_232 ) , F_58 ( & V_172 -> V_175 ) , V_4 -> V_87 ) ;
V_15 = F_110 ( V_4 -> V_21 , V_245 , V_232 , V_172 , V_247 ,
V_248 , V_249 , V_251 , V_250 ) ;
if ( V_15 == 0 && V_232 && V_232 -> V_269 == V_270 ) {
V_15 = F_106 ( exp , V_245 , V_232 , V_172 , V_247 ,
V_248 , V_249 , V_250 ) ;
}
RETURN ( V_15 ) ;
}
static int
F_113 ( struct V_34 * exp , struct V_171 * V_172 ,
struct V_226 * * V_227 )
{
struct V_226 * V_251 = NULL ;
struct V_12 * V_13 = exp -> V_35 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_3 * V_4 ;
struct V_258 * V_259 ;
int V_15 ;
V_16 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
RETURN ( V_15 ) ;
V_4 = F_101 ( V_2 , V_172 , & V_172 -> V_175 ) ;
if ( F_19 ( V_4 ) )
RETURN ( F_56 ( V_4 ) ) ;
F_3 ( V_231 , L_69 V_129 L_68 ,
V_172 -> V_241 , V_172 -> V_242 , F_58 ( & V_172 -> V_175 ) ,
V_4 -> V_87 ) ;
V_15 = F_114 ( V_4 -> V_21 , V_172 , V_227 ) ;
if ( V_15 != 0 )
RETURN ( V_15 ) ;
V_259 = F_107 ( & ( * V_227 ) -> V_261 ,
& V_262 ) ;
F_7 ( V_259 != NULL ) ;
if ( V_259 -> V_221 & V_263 ) {
struct V_103 V_271 = V_259 -> V_257 ;
F_3 ( V_231 , L_70 V_129 L_3 ,
F_58 ( & V_271 ) ) ;
V_4 = F_55 ( V_2 , & V_271 ) ;
if ( F_19 ( V_4 ) ) {
F_109 ( * V_227 ) ;
RETURN ( F_56 ( V_4 ) ) ;
}
V_172 -> V_175 = V_271 ;
V_172 -> V_272 |= V_273 ;
V_172 -> V_241 = 0 ;
V_172 -> V_242 = NULL ;
V_15 = F_114 ( V_4 -> V_21 , V_172 , & V_251 ) ;
F_109 ( * V_227 ) ;
* V_227 = V_251 ;
}
RETURN ( V_15 ) ;
}
static int F_115 ( struct V_34 * exp , struct V_171 * V_172 ,
int V_274 , T_8 V_236 , int V_275 , int V_276 )
{
struct V_103 * V_191 = F_116 ( V_172 , V_276 ) ;
struct V_12 * V_13 = exp -> V_35 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_3 * V_4 ;
T_9 V_277 = { { 0 } } ;
int V_15 = 0 ;
V_16 ;
if ( ! F_59 ( V_191 ) )
RETURN ( 0 ) ;
V_4 = F_55 ( V_2 , V_191 ) ;
if ( F_19 ( V_4 ) )
RETURN ( F_56 ( V_4 ) ) ;
if ( V_4 -> V_87 != V_274 ) {
F_3 ( V_231 , L_71 V_129 L_3 , F_58 ( V_191 ) ) ;
V_277 . V_278 . V_275 = V_275 ;
V_15 = F_117 ( V_4 -> V_21 , V_191 , & V_277 ,
V_236 , V_279 , NULL ) ;
} else {
F_3 ( V_231 ,
L_72 V_129 L_3 ,
V_274 , F_58 ( V_191 ) ) ;
V_172 -> V_229 |= V_276 ;
V_15 = 0 ;
}
RETURN ( V_15 ) ;
}
static int F_118 ( struct V_34 * exp , struct V_171 * V_172 ,
struct V_226 * * V_227 )
{
struct V_12 * V_13 = exp -> V_35 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_16 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
RETURN ( V_15 ) ;
F_7 ( V_172 -> V_241 != 0 ) ;
F_3 ( V_231 , L_73 V_129 L_74 V_129 L_3 ,
F_58 ( & V_172 -> V_176 ) , V_172 -> V_241 ,
V_172 -> V_242 , F_58 ( & V_172 -> V_175 ) ) ;
V_172 -> V_280 = F_119 () ;
V_172 -> V_281 = F_120 () ;
V_172 -> V_282 = F_121 () ;
V_4 = F_101 ( V_2 , V_172 , & V_172 -> V_176 ) ;
if ( F_19 ( V_4 ) )
RETURN ( F_56 ( V_4 ) ) ;
V_172 -> V_229 |= V_283 ;
V_15 = F_115 ( exp , V_172 , V_4 -> V_87 , V_284 ,
V_285 , V_243 ) ;
if ( V_15 != 0 )
RETURN ( V_15 ) ;
V_15 = F_122 ( V_4 -> V_21 , V_172 , V_227 ) ;
RETURN ( V_15 ) ;
}
static int F_123 ( struct V_34 * exp , struct V_171 * V_172 ,
const char * V_97 , int V_286 , const char * V_287 , int V_288 ,
struct V_226 * * V_227 )
{
struct V_12 * V_13 = exp -> V_35 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_3 * V_289 ;
struct V_3 * V_290 ;
int V_15 ;
V_16 ;
F_7 ( V_286 != 0 ) ;
F_3 ( V_231 , L_75 V_129 L_76 V_129 L_3 ,
V_286 , V_97 , F_58 ( & V_172 -> V_175 ) ,
V_288 , V_287 , F_58 ( & V_172 -> V_176 ) ) ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
RETURN ( V_15 ) ;
V_172 -> V_280 = F_119 () ;
V_172 -> V_281 = F_120 () ;
V_172 -> V_282 = F_121 () ;
V_289 = F_101 ( V_2 , V_172 , & V_172 -> V_175 ) ;
if ( F_19 ( V_289 ) )
RETURN ( F_56 ( V_289 ) ) ;
V_290 = F_101 ( V_2 , V_172 , & V_172 -> V_176 ) ;
if ( F_19 ( V_290 ) )
RETURN ( F_56 ( V_290 ) ) ;
V_172 -> V_229 |= V_243 | V_291 ;
V_15 = F_115 ( exp , V_172 , V_289 -> V_87 ,
V_284 , V_285 ,
V_283 ) ;
if ( V_15 == 0 ) {
V_15 = F_115 ( exp , V_172 , V_289 -> V_87 ,
V_284 , V_292 ,
V_293 ) ;
}
if ( V_15 == 0 )
V_15 = F_115 ( exp , V_172 , V_289 -> V_87 ,
V_284 , V_294 ,
V_293 ) ;
if ( V_15 == 0 )
V_15 = F_124 ( V_289 -> V_21 , V_172 , V_97 , V_286 ,
V_287 , V_288 , V_227 ) ;
RETURN ( V_15 ) ;
}
static int F_125 ( struct V_34 * exp , struct V_171 * V_172 ,
void * V_295 , int V_296 , void * V_297 , int V_298 ,
struct V_226 * * V_227 ,
struct V_233 * * V_234 )
{
struct V_12 * V_13 = exp -> V_35 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_3 * V_4 ;
int V_15 = 0 ;
V_16 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
RETURN ( V_15 ) ;
F_3 ( V_231 , L_77 V_129 L_78 ,
F_58 ( & V_172 -> V_175 ) , V_172 -> V_299 . V_300 ) ;
V_172 -> V_229 |= V_243 ;
V_4 = F_55 ( V_2 , & V_172 -> V_175 ) ;
if ( F_19 ( V_4 ) )
RETURN ( F_56 ( V_4 ) ) ;
V_15 = F_126 ( V_4 -> V_21 , V_172 , V_295 , V_296 , V_297 ,
V_298 , V_227 , V_234 ) ;
RETURN ( V_15 ) ;
}
static int F_127 ( struct V_34 * exp , const struct V_103 * V_191 ,
struct V_218 * V_220 , struct V_226 * * V_227 )
{
struct V_12 * V_13 = exp -> V_35 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_16 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
RETURN ( V_15 ) ;
V_4 = F_55 ( V_2 , V_191 ) ;
if ( F_19 ( V_4 ) )
RETURN ( F_56 ( V_4 ) ) ;
V_15 = F_128 ( V_4 -> V_21 , V_191 , V_220 , V_227 ) ;
RETURN ( V_15 ) ;
}
static void F_129 ( struct V_301 * * V_302 , int V_303 , int V_304 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_303 ; V_14 ++ ) {
struct V_305 * V_306 = F_130 ( V_302 [ V_14 ] ) ;
struct V_305 * V_307 = V_306 ;
struct V_308 * V_309 = NULL ;
struct V_308 * V_310 ;
T_4 V_311 = V_306 -> V_312 ;
T_1 V_210 = V_306 -> V_313 ;
for (; V_304 > 1 ; V_304 -- ) {
V_310 = F_131 ( V_306 ) ;
for ( V_309 = V_310 ; V_310 != NULL ;
V_309 = V_310 , V_310 = F_132 ( V_310 ) ) ;
V_306 = (struct V_305 * ) ( ( char * ) V_306 + V_314 ) ;
if ( ! ( ( unsigned long ) V_306 & ~ V_315 ) )
break;
V_311 = V_306 -> V_312 ;
V_210 = V_306 -> V_313 ;
if ( ! V_309 )
break;
F_7 ( F_133 ( V_309 -> V_316 ) == 0 ) ;
V_309 -> V_316 =
F_134 ( ( char * ) ( V_306 -> V_317 ) -
( char * ) V_309 ) ;
}
V_307 -> V_312 = V_311 ;
V_307 -> V_313 &= ~ F_135 ( V_318 ) ;
V_307 -> V_313 |= V_210 & F_135 ( V_318 ) ;
F_136 ( V_302 [ V_14 ] ) ;
}
}
static int F_137 ( struct V_34 * exp , struct V_171 * V_172 ,
struct V_301 * * V_302 , struct V_226 * * V_227 )
{
struct V_12 * V_13 = exp -> V_35 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
T_4 V_319 = V_172 -> V_320 ;
int V_15 ;
int V_303 ;
int V_304 ;
struct V_3 * V_4 ;
V_16 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
RETURN ( V_15 ) ;
F_3 ( V_231 , L_79 V_22 L_80 V_129 L_3 ,
V_319 , F_58 ( & V_172 -> V_175 ) ) ;
V_4 = F_55 ( V_2 , & V_172 -> V_175 ) ;
if ( F_19 ( V_4 ) )
RETURN ( F_56 ( V_4 ) ) ;
V_15 = F_138 ( V_4 -> V_21 , V_172 , V_302 , V_227 ) ;
if ( V_15 != 0 )
RETURN ( V_15 ) ;
V_303 = ( ( * V_227 ) -> V_321 -> V_322 + V_323 - 1 )
>> V_324 ;
V_304 = ( * V_227 ) -> V_321 -> V_322 >> V_325 ;
F_7 ( ! ( ( * V_227 ) -> V_321 -> V_322 & ~ V_326 ) ) ;
F_7 ( V_303 > 0 && V_303 <= V_172 -> V_327 ) ;
F_3 ( V_231 , L_81 , V_303 , V_304 ,
V_172 -> V_327 ) ;
F_129 ( V_302 , V_303 , V_304 ) ;
RETURN ( V_15 ) ;
}
static int F_139 ( struct V_34 * exp , struct V_171 * V_172 ,
struct V_226 * * V_227 )
{
struct V_12 * V_13 = exp -> V_35 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_3 * V_4 = NULL ;
struct V_258 * V_259 ;
int V_15 ;
V_16 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
RETURN ( V_15 ) ;
V_328:
if ( F_140 ( ! F_141 ( & V_172 -> V_176 ) ) )
V_4 = F_101 ( V_2 , V_172 , & V_172 -> V_176 ) ;
else
V_4 = F_101 ( V_2 , V_172 , & V_172 -> V_175 ) ;
if ( F_19 ( V_4 ) )
RETURN ( F_56 ( V_4 ) ) ;
V_172 -> V_280 = F_119 () ;
V_172 -> V_281 = F_120 () ;
V_172 -> V_282 = F_121 () ;
V_172 -> V_229 |= V_243 | V_291 ;
V_15 = F_115 ( exp , V_172 , V_4 -> V_87 , V_284 ,
V_294 , V_291 ) ;
if ( V_15 != 0 )
RETURN ( V_15 ) ;
F_3 ( V_231 , L_82 V_129 L_83 V_129 L_68 ,
F_58 ( & V_172 -> V_175 ) , F_58 ( & V_172 -> V_176 ) , V_4 -> V_87 ) ;
V_15 = F_142 ( V_4 -> V_21 , V_172 , V_227 ) ;
if ( V_15 != 0 && V_15 != - V_122 )
RETURN ( V_15 ) ;
V_259 = F_107 ( & ( * V_227 ) -> V_261 , & V_262 ) ;
if ( V_259 == NULL )
RETURN ( - V_329 ) ;
if ( F_140 ( ! ( V_259 -> V_221 & V_263 ) ) )
RETURN ( 0 ) ;
F_3 ( V_231 , L_84 V_129 L_3 ,
exp -> V_35 -> V_29 , F_58 ( & V_259 -> V_257 ) ) ;
V_172 -> V_176 = V_259 -> V_257 ;
F_109 ( * V_227 ) ;
* V_227 = NULL ;
goto V_328;
}
static int F_143 ( struct V_12 * V_13 , enum V_330 V_331 )
{
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
int V_15 = 0 ;
switch ( V_331 ) {
case V_332 :
break;
case V_333 :
F_144 ( & V_2 -> V_88 ) ;
F_145 ( V_13 ) ;
break;
default:
break;
}
RETURN ( V_15 ) ;
}
static int F_146 ( const struct V_53 * V_54 , struct V_34 * exp ,
T_1 V_334 , void * V_335 , T_1 * V_336 , void * V_337 ,
struct V_338 * V_339 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
int V_15 = 0 ;
V_16 ;
V_13 = F_6 ( exp ) ;
if ( V_13 == NULL ) {
F_3 ( V_340 , L_85 V_22 L_3 ,
exp -> V_24 . V_25 ) ;
RETURN ( - V_27 ) ;
}
V_2 = & V_13 -> V_36 . V_2 ;
if ( V_334 >= strlen ( L_86 ) && ! strcmp ( V_335 , L_86 ) ) {
struct V_3 * V_4 ;
int V_14 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
RETURN ( V_15 ) ;
F_7 ( * V_336 == sizeof( T_1 ) ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_19 ; V_14 ++ ) {
V_4 = V_2 -> V_20 [ V_14 ] ;
if ( V_4 == NULL || V_4 -> V_21 == NULL )
continue;
if ( ! F_147 ( V_54 , V_4 -> V_21 , V_334 , V_335 ,
V_336 , V_337 , NULL ) )
RETURN ( 0 ) ;
}
RETURN ( - V_27 ) ;
} else if ( F_148 ( V_341 ) || F_148 ( V_342 ) ) {
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
RETURN ( V_15 ) ;
V_15 = F_147 ( V_54 , V_2 -> V_20 [ 0 ] -> V_21 , V_334 , V_335 ,
V_336 , V_337 , NULL ) ;
if ( ! V_15 && F_148 ( V_342 ) )
exp -> V_51 = * (struct V_41 * ) V_337 ;
RETURN ( V_15 ) ;
} else if ( F_148 ( V_343 ) ) {
* ( ( int * ) V_337 ) = V_2 -> V_7 . V_19 ;
RETURN ( 0 ) ;
}
F_3 ( V_340 , L_87 ) ;
RETURN ( - V_27 ) ;
}
int F_149 ( const struct V_53 * V_54 , struct V_34 * exp ,
T_3 V_334 , void * V_335 , T_3 V_336 ,
void * V_337 , struct V_344 * V_135 )
{
struct V_3 * V_4 ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
int V_15 = 0 ;
V_16 ;
V_13 = F_6 ( exp ) ;
if ( V_13 == NULL ) {
F_3 ( V_340 , L_85 V_22 L_3 ,
exp -> V_24 . V_25 ) ;
RETURN ( - V_27 ) ;
}
V_2 = & V_13 -> V_36 . V_2 ;
if ( F_148 ( V_345 ) || F_148 ( V_346 ) ) {
int V_14 , V_178 = 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_19 ; V_14 ++ ) {
V_4 = V_2 -> V_20 [ V_14 ] ;
if ( V_4 == NULL || V_4 -> V_21 == NULL )
continue;
V_178 = F_23 ( V_54 , V_4 -> V_21 ,
V_334 , V_335 , V_336 , V_337 , V_135 ) ;
if ( V_178 && V_15 == 0 )
V_15 = V_178 ;
}
RETURN ( V_15 ) ;
}
RETURN ( - V_27 ) ;
}
int F_150 ( struct V_34 * exp , struct V_347 * * V_348 ,
struct V_338 * V_339 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_102 * V_349 ;
struct V_102 * V_350 ;
int V_351 ;
int V_14 ;
V_16 ;
V_351 = F_48 ( V_2 ) ;
if ( ! V_348 )
RETURN ( V_351 ) ;
if ( * V_348 && ! V_339 ) {
F_151 ( * V_348 , V_351 ) ;
* V_348 = NULL ;
RETURN ( 0 ) ;
}
if ( * V_348 == NULL ) {
F_152 ( * V_348 , V_351 ) ;
if ( * V_348 == NULL )
RETURN ( - V_100 ) ;
}
if ( ! V_339 )
RETURN ( V_351 ) ;
V_350 = (struct V_102 * ) V_339 ;
V_349 = (struct V_102 * ) * V_348 ;
if ( V_350 -> V_352 != V_353 &&
V_350 -> V_352 != V_354 )
RETURN ( - V_27 ) ;
V_349 -> V_352 = F_135 ( V_350 -> V_352 ) ;
V_349 -> V_355 = F_135 ( V_350 -> V_355 ) ;
V_349 -> V_356 = F_135 ( V_350 -> V_356 ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_19 ; V_14 ++ ) {
V_349 -> V_357 [ V_14 ] = V_350 -> V_357 [ V_14 ] ;
F_153 ( & V_349 -> V_357 [ V_14 ] , & V_350 -> V_357 [ V_14 ] ) ;
}
RETURN ( V_351 ) ;
}
int F_154 ( struct V_34 * exp , struct V_338 * * V_350 ,
struct V_347 * V_248 , int V_358 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_102 * * V_359 = (struct V_102 * * ) V_350 ;
struct V_102 * V_360 = (struct V_102 * ) V_248 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
int V_351 ;
int V_14 ;
T_1 V_361 ;
V_16 ;
V_351 = F_48 ( V_2 ) ;
if ( V_350 == NULL )
return V_351 ;
if ( * V_350 != NULL && V_248 == NULL ) {
F_151 ( * V_359 , V_351 ) ;
* V_350 = NULL ;
RETURN ( 0 ) ;
}
F_7 ( V_351 == V_358 ) ;
F_152 ( * V_359 , V_351 ) ;
if ( * V_359 == NULL )
RETURN ( - V_100 ) ;
if ( ! V_248 )
RETURN ( V_351 ) ;
if ( V_360 -> V_352 == V_353 ||
V_360 -> V_352 == V_354 ||
V_360 -> V_352 == V_362 )
{
V_361 = F_155 ( V_360 -> V_352 ) ;
} else {
F_12 ( L_88 ) ;
F_156 () ;
}
( * V_359 ) -> V_352 = V_361 ;
( * V_359 ) -> V_355 = F_155 ( V_360 -> V_355 ) ;
( * V_359 ) -> V_356 = F_155 ( V_360 -> V_356 ) ;
for ( V_14 = 0 ; V_14 < ( * V_359 ) -> V_355 ; V_14 ++ ) {
( * V_359 ) -> V_357 [ V_14 ] = V_360 -> V_357 [ V_14 ] ;
F_157 ( & ( * V_359 ) -> V_357 [ V_14 ] , & ( * V_359 ) -> V_357 [ V_14 ] ) ;
}
RETURN ( V_351 ) ;
}
static int F_158 ( struct V_34 * exp , const struct V_103 * V_191 ,
T_9 * V_277 , T_8 V_236 ,
T_10 V_210 , void * V_363 )
{
struct V_12 * V_13 = exp -> V_35 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
int V_15 = 0 ;
int V_178 ;
int V_14 ;
V_16 ;
F_7 ( V_191 != NULL ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_19 ; V_14 ++ ) {
if ( V_2 -> V_20 [ V_14 ] == NULL || V_2 -> V_20 [ V_14 ] -> V_21 == NULL ||
V_2 -> V_20 [ V_14 ] -> V_6 == 0 )
continue;
V_178 = F_117 ( V_2 -> V_20 [ V_14 ] -> V_21 , V_191 ,
V_277 , V_236 , V_210 , V_363 ) ;
if ( ! V_15 )
V_15 = V_178 ;
}
RETURN ( V_15 ) ;
}
int F_159 ( struct V_34 * exp , T_4 * V_247 , void * V_40 ,
T_4 * V_275 )
{
struct V_1 * V_2 = & exp -> V_35 -> V_36 . V_2 ;
int V_15 ;
V_16 ;
V_15 = F_160 ( V_2 -> V_20 [ 0 ] -> V_21 , V_247 , V_40 , V_275 ) ;
RETURN ( V_15 ) ;
}
T_8 F_161 ( struct V_34 * exp , T_4 V_210 ,
const struct V_103 * V_191 , T_11 type ,
T_9 * V_277 , T_8 V_236 ,
struct V_59 * V_247 )
{
struct V_12 * V_13 = exp -> V_35 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
T_8 V_15 ;
int V_14 ;
V_16 ;
F_3 ( V_231 , L_89 V_129 L_3 , F_58 ( V_191 ) ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_19 ; V_14 ++ ) {
if ( V_2 -> V_20 [ V_14 ] == NULL ||
V_2 -> V_20 [ V_14 ] -> V_21 == NULL ||
V_2 -> V_20 [ V_14 ] -> V_6 == 0 )
continue;
V_15 = F_162 ( V_2 -> V_20 [ V_14 ] -> V_21 , V_210 , V_191 ,
type , V_277 , V_236 , V_247 ) ;
if ( V_15 )
RETURN ( V_15 ) ;
}
RETURN ( 0 ) ;
}
int F_163 ( struct V_34 * exp , struct V_226 * V_251 ,
struct V_34 * V_364 , struct V_34 * V_365 ,
struct V_366 * V_367 )
{
struct V_1 * V_2 = & exp -> V_35 -> V_36 . V_2 ;
return F_164 ( V_2 -> V_20 [ 0 ] -> V_21 , V_251 , V_364 , V_365 , V_367 ) ;
}
int F_165 ( struct V_34 * exp , struct V_366 * V_367 )
{
struct V_12 * V_13 = exp -> V_35 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
V_16 ;
if ( V_367 -> V_360 )
F_166 ( exp , ( void * ) & V_367 -> V_360 ) ;
RETURN ( F_167 ( V_2 -> V_20 [ 0 ] -> V_21 , V_367 ) ) ;
}
int F_168 ( struct V_34 * exp ,
struct V_368 * V_369 ,
struct V_226 * V_370 )
{
struct V_12 * V_13 = exp -> V_35 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_3 * V_4 ;
V_16 ;
V_4 = F_55 ( V_2 , & V_369 -> V_371 ) ;
if ( F_19 ( V_4 ) )
RETURN ( F_56 ( V_4 ) ) ;
RETURN ( F_169 ( V_4 -> V_21 , V_369 , V_370 ) ) ;
}
int F_170 ( struct V_34 * exp ,
struct V_368 * V_369 )
{
struct V_12 * V_13 = exp -> V_35 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_3 * V_4 ;
V_16 ;
V_4 = F_55 ( V_2 , & V_369 -> V_371 ) ;
if ( F_19 ( V_4 ) )
RETURN ( F_56 ( V_4 ) ) ;
RETURN ( F_171 ( V_4 -> V_21 , V_369 ) ) ;
}
static int F_172 ( struct V_34 * exp ,
const struct V_103 * V_191 ,
struct V_218 * V_220 , T_1 V_228 ,
struct V_226 * * V_227 )
{
struct V_12 * V_13 = exp -> V_35 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_16 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
RETURN ( V_15 ) ;
V_4 = F_55 ( V_2 , V_191 ) ;
if ( F_19 ( V_4 ) )
RETURN ( F_56 ( V_4 ) ) ;
V_15 = F_173 ( V_4 -> V_21 , V_191 , V_220 , V_228 , V_227 ) ;
RETURN ( V_15 ) ;
}
static int F_174 ( struct V_34 * exp , struct V_218 * V_220 ,
T_12 V_372 )
{
struct V_12 * V_13 = exp -> V_35 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_16 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
RETURN ( V_15 ) ;
V_4 = F_55 ( V_2 , & V_220 -> V_373 . V_374 ) ;
if ( F_19 ( V_4 ) )
RETURN ( F_56 ( V_4 ) ) ;
V_15 = F_175 ( V_4 -> V_21 , V_220 , V_372 ) ;
RETURN ( V_15 ) ;
}
int F_176 ( struct V_34 * exp , struct V_226 * V_251 ,
const struct V_375 * V_376 , struct V_218 * * V_220 )
{
struct V_1 * V_2 = & exp -> V_35 -> V_36 . V_2 ;
return F_177 ( V_2 -> V_20 [ 0 ] -> V_21 , V_251 , V_376 , V_220 ) ;
}
int F_178 ( struct V_34 * exp ,
struct V_377 * V_378 ,
struct V_244 * V_245 )
{
struct V_171 * V_172 = & V_378 -> V_379 ;
struct V_12 * V_13 = exp -> V_35 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_3 * V_4 = NULL ;
int V_15 ;
V_16 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
RETURN ( V_15 ) ;
V_4 = F_55 ( V_2 , & V_172 -> V_175 ) ;
if ( F_19 ( V_4 ) )
RETURN ( F_56 ( V_4 ) ) ;
V_15 = F_179 ( V_4 -> V_21 , V_378 , V_245 ) ;
RETURN ( V_15 ) ;
}
int F_180 ( struct V_34 * exp , struct V_246 * V_232 ,
struct V_103 * V_191 , T_4 * V_275 )
{
struct V_12 * V_13 = exp -> V_35 ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_16 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
RETURN ( V_15 ) ;
V_4 = F_55 ( V_2 , V_191 ) ;
if ( F_19 ( V_4 ) )
RETURN ( F_56 ( V_4 ) ) ;
V_15 = F_181 ( V_4 -> V_21 , V_232 , V_191 , V_275 ) ;
RETURN ( V_15 ) ;
}
int F_182 ( struct V_12 * V_380 , struct V_34 * exp ,
struct V_154 * V_155 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_3 * V_4 = V_2 -> V_20 [ 0 ] ;
int V_15 = 0 , V_14 ;
T_4 V_381 , V_382 ;
V_16 ;
if ( ! V_2 -> V_7 . V_19 || ! V_4 -> V_6 ) {
F_12 ( L_90 ) ;
RETURN ( - V_180 ) ;
}
if ( V_155 -> V_383 != V_384 ) {
V_15 = V_154 ( V_4 -> V_21 , V_155 ) ;
RETURN ( V_15 ) ;
}
V_381 = V_382 = 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_19 ; V_14 ++ ) {
int V_178 ;
V_4 = V_2 -> V_20 [ V_14 ] ;
if ( V_4 == NULL || V_4 -> V_21 == NULL || V_4 -> V_6 == 0 )
continue;
if ( ! V_4 -> V_6 ) {
F_3 ( V_385 , L_91 , V_14 ) ;
continue;
}
V_178 = V_154 ( V_4 -> V_21 , V_155 ) ;
if ( V_178 ) {
F_12 ( L_92 , V_14 , V_178 ) ;
if ( ! V_15 )
V_15 = V_178 ;
} else {
V_381 += V_155 -> V_386 . V_387 ;
V_382 += V_155 -> V_386 . V_388 ;
}
}
V_155 -> V_386 . V_387 = V_381 ;
V_155 -> V_386 . V_388 = V_382 ;
RETURN ( V_15 ) ;
}
int F_183 ( struct V_12 * V_380 , struct V_34 * exp ,
struct V_154 * V_155 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_36 . V_2 ;
struct V_3 * V_4 ;
int V_14 , V_15 = 0 ;
V_16 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_19 ; V_14 ++ ) {
int V_178 ;
V_4 = V_2 -> V_20 [ V_14 ] ;
if ( V_4 == NULL || V_4 -> V_21 == NULL || ! V_4 -> V_6 ) {
F_12 ( L_93 , V_14 ) ;
RETURN ( - V_180 ) ;
}
V_178 = F_184 ( V_4 -> V_21 , V_155 ) ;
if ( V_178 && ! V_15 )
V_15 = V_178 ;
}
RETURN ( V_15 ) ;
}
int T_13 F_185 ( void )
{
struct V_195 V_196 ;
int V_15 ;
F_78 ( & V_196 ) ;
V_15 = F_186 ( & V_389 , & V_390 ,
V_196 . V_391 , V_392 , NULL ) ;
return V_15 ;
}
static void F_187 ( void )
{
F_188 ( V_392 ) ;
}
