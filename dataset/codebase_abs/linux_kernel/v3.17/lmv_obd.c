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
F_3 ( V_16 , L_2 , V_14 ,
V_4 -> V_21 . V_10 , V_4 -> V_20 -> V_22 . V_23 ) ;
if ( F_5 ( V_10 , & V_4 -> V_21 ) )
break;
}
if ( V_14 == V_2 -> V_7 . V_18 )
GOTO ( V_24 , V_15 = - V_25 ) ;
V_13 = F_6 ( V_4 -> V_20 ) ;
if ( V_13 == NULL )
GOTO ( V_24 , V_15 = - V_26 ) ;
F_3 ( V_16 , L_3 ,
V_13 -> V_27 , V_13 -> V_9 . V_10 , V_13 -> V_28 , V_13 ,
V_13 -> V_29 -> V_30 , V_14 ) ;
F_7 ( strcmp ( V_13 -> V_29 -> V_30 , V_31 ) == 0 ) ;
if ( V_4 -> V_6 == V_5 ) {
F_3 ( V_16 , L_4 , V_13 ,
V_5 ? L_5 : L_6 ) ;
GOTO ( V_24 , V_15 ) ;
}
F_3 ( V_16 , L_7 , V_13 ,
V_5 ? L_5 : L_6 ) ;
F_1 ( V_2 , V_4 , V_5 ) ;
V_24:
F_8 ( & V_2 -> V_17 ) ;
return V_15 ;
}
struct V_9 * F_9 ( struct V_32 * exp )
{
struct V_1 * V_2 = & exp -> V_33 -> V_34 . V_2 ;
return F_10 ( V_2 -> V_19 [ 0 ] -> V_20 ) ;
}
static int F_11 ( struct V_12 * V_13 , struct V_12 * V_35 ,
enum V_36 V_37 , void * V_38 )
{
struct V_39 * V_40 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_9 * V_10 ;
int V_15 = 0 ;
if ( strcmp ( V_35 -> V_29 -> V_30 , V_31 ) ) {
F_12 ( L_8 ,
V_35 -> V_29 -> V_30 ,
V_35 -> V_27 ) ;
return - V_25 ;
}
V_10 = & V_35 -> V_34 . V_41 . V_42 ;
if ( V_37 == V_43 || V_37 == V_44 ) {
V_15 = F_2 ( V_2 , V_10 ,
V_37 == V_43 ) ;
if ( V_15 ) {
F_12 ( L_9 ,
V_37 == V_43 ? L_5 : L_10 ,
V_10 -> V_10 , V_15 ) ;
return V_15 ;
}
} else if ( V_37 == V_45 ) {
V_40 = & V_35 -> V_34 . V_41 . V_46 -> V_47 ;
V_13 -> V_48 -> V_49 = * V_40 ;
}
#if 0
else if (ev == OBD_NOTIFY_DISCON) {
fld_client_flush(&lmv->lmv_fld);
}
#endif
if ( V_13 -> V_50 )
V_15 = F_13 ( V_13 -> V_50 , V_35 , V_37 , V_38 ) ;
return V_15 ;
}
static int F_14 ( const struct V_51 * V_52 ,
struct V_32 * * exp , struct V_12 * V_13 ,
struct V_9 * V_53 , struct V_39 * V_38 ,
void * V_54 )
{
struct V_55 * V_56 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_57 V_58 = { 0 } ;
int V_15 = 0 ;
V_2 -> V_59 ++ ;
if ( V_2 -> V_59 > 1 ) {
* exp = NULL ;
return 0 ;
}
V_15 = F_15 ( & V_58 , V_13 , V_53 ) ;
if ( V_15 ) {
F_12 ( L_11 , V_15 ) ;
return V_15 ;
}
* exp = F_16 ( & V_58 ) ;
F_17 ( * exp ) ;
V_2 -> exp = * exp ;
V_2 -> V_60 = 0 ;
V_2 -> V_53 = * V_53 ;
if ( V_38 )
V_2 -> V_40 = * V_38 ;
if ( V_13 -> V_61 != NULL ) {
V_56 = V_13 -> V_61 ;
} else {
V_56 = F_18 ( L_12 , V_13 -> V_62 ,
NULL , NULL ) ;
if ( F_19 ( V_56 ) ) {
F_12 ( L_13 ,
V_13 -> V_29 -> V_30 , V_13 -> V_27 ) ;
V_56 = NULL ;
}
V_13 -> V_61 = V_56 ;
}
if ( V_38 -> V_63 & V_64 )
V_15 = F_20 ( V_13 ) ;
if ( V_15 && V_56 ) {
F_21 ( & V_56 ) ;
V_13 -> V_61 = NULL ;
}
return V_15 ;
}
static void F_22 ( struct V_12 * V_13 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_14 ;
V_2 = & V_13 -> V_34 . V_2 ;
if ( V_2 -> V_65 == 0 )
return;
if ( V_2 -> V_60 == 0 )
return;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL || V_4 -> V_20 == NULL || V_4 -> V_6 == 0 )
continue;
F_23 ( NULL , V_4 -> V_20 , sizeof( V_66 ) ,
V_66 , 0 , NULL , NULL ) ;
}
}
static int F_24 ( struct V_32 * exp , int V_67 ,
int V_68 , int V_69 , int V_70 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
int V_14 ;
int V_15 = 0 ;
int V_71 = 0 ;
if ( V_2 -> V_72 < V_67 ) {
V_2 -> V_72 = V_67 ;
V_71 = 1 ;
}
if ( V_2 -> V_73 < V_68 ) {
V_2 -> V_73 = V_68 ;
V_71 = 1 ;
}
if ( V_2 -> V_74 < V_69 ) {
V_2 -> V_74 = V_69 ;
V_71 = 1 ;
}
if ( V_2 -> V_75 < V_70 ) {
V_2 -> V_75 = V_70 ;
V_71 = 1 ;
}
if ( V_71 == 0 )
return 0 ;
if ( V_2 -> V_60 == 0 )
return 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL ||
V_2 -> V_19 [ V_14 ] -> V_20 == NULL ||
V_2 -> V_19 [ V_14 ] -> V_6 == 0 ) {
F_25 ( L_14 , V_13 -> V_27 , V_14 ) ;
continue;
}
V_15 = F_26 ( V_2 -> V_19 [ V_14 ] -> V_20 , V_67 , V_68 ,
V_69 , V_70 ) ;
if ( V_15 ) {
F_12 ( L_15
L_16 , V_13 -> V_27 , V_14 , V_15 ) ;
break;
}
}
return V_15 ;
}
int F_27 ( struct V_12 * V_13 , struct V_3 * V_4 )
{
struct V_55 * V_56 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_9 * V_53 = & V_2 -> V_53 ;
struct V_9 V_76 = { L_17 } ;
struct V_12 * V_77 ;
struct V_32 * V_78 ;
struct V_79 V_80 ;
int V_15 ;
V_77 = F_28 ( & V_4 -> V_21 , V_31 ,
& V_13 -> V_9 ) ;
if ( ! V_77 ) {
F_12 ( L_18 , V_4 -> V_21 . V_10 ) ;
return - V_25 ;
}
F_3 ( V_81 , L_19 ,
V_77 -> V_27 , V_77 -> V_9 . V_10 ,
V_4 -> V_21 . V_10 , V_13 -> V_9 . V_10 ,
V_53 -> V_10 ) ;
if ( ! V_77 -> V_82 ) {
F_12 ( L_20 , V_4 -> V_21 . V_10 ) ;
return - V_25 ;
}
V_15 = F_29 ( NULL , & V_78 , V_77 , & V_76 ,
& V_2 -> V_40 , NULL ) ;
if ( V_15 ) {
F_12 ( L_21 , V_4 -> V_21 . V_10 , V_15 ) ;
return V_15 ;
}
V_15 = F_30 ( V_77 , V_78 , V_83 ) ;
if ( V_15 )
return V_15 ;
V_80 . V_84 = NULL ;
V_80 . V_85 = V_78 ;
V_80 . V_86 = V_4 -> V_87 ;
F_31 ( & V_2 -> V_88 , & V_80 ) ;
V_15 = F_32 ( V_77 , V_13 ) ;
if ( V_15 ) {
F_33 ( V_78 ) ;
F_12 ( L_22 ,
V_4 -> V_21 . V_10 , V_15 ) ;
return V_15 ;
}
if ( V_13 -> V_50 ) {
V_15 = F_13 ( V_13 -> V_50 , V_78 -> V_33 ,
V_43 ,
( void * ) ( V_4 - V_2 -> V_19 [ 0 ] ) ) ;
if ( V_15 ) {
F_33 ( V_78 ) ;
return V_15 ;
}
}
V_4 -> V_6 = 1 ;
V_4 -> V_20 = V_78 ;
V_2 -> V_7 . V_8 ++ ;
F_26 ( V_4 -> V_20 , V_2 -> V_72 , V_2 -> V_73 ,
V_2 -> V_74 , V_2 -> V_75 ) ;
F_3 ( V_81 , L_23 ,
V_77 -> V_27 , V_77 -> V_9 . V_10 ,
F_34 ( & V_13 -> V_89 ) ) ;
V_56 = V_13 -> V_61 ;
if ( V_56 ) {
struct V_55 * V_90 ;
F_7 ( V_77 -> V_29 != NULL ) ;
F_7 ( V_77 -> V_29 -> V_30 != NULL ) ;
V_90 = F_35 ( V_77 -> V_27 ,
V_56 ,
L_24 ,
V_77 -> V_29 -> V_30 ,
V_77 -> V_27 ) ;
if ( V_90 == NULL ) {
F_12 ( L_25
L_26 ,
V_13 -> V_29 -> V_30 , V_13 -> V_27 ,
V_77 -> V_27 ) ;
F_21 ( & V_56 ) ;
V_13 -> V_61 = NULL ;
}
}
return 0 ;
}
static void F_36 ( struct V_1 * V_2 , int V_91 )
{
if ( V_2 -> V_19 [ V_91 ] == NULL )
return;
F_37 ( V_2 -> V_19 [ V_91 ] ) ;
V_2 -> V_19 [ V_91 ] = NULL ;
return;
}
static int F_38 ( struct V_12 * V_13 , struct V_9 * V_92 ,
T_1 V_91 , int V_93 )
{
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 = 0 ;
F_3 ( V_81 , L_27 , V_92 -> V_10 , V_91 ) ;
F_39 ( V_2 ) ;
if ( V_2 -> V_7 . V_18 == 0 ) {
struct V_12 * V_77 ;
V_77 = F_28 ( V_92 , V_31 ,
& V_13 -> V_9 ) ;
if ( ! V_77 ) {
F_40 ( V_2 ) ;
F_12 ( L_28 ,
V_13 -> V_27 , V_92 -> V_10 , - V_25 ) ;
return - V_25 ;
}
}
if ( ( V_91 < V_2 -> V_94 ) && ( V_2 -> V_19 [ V_91 ] != NULL ) ) {
V_4 = V_2 -> V_19 [ V_91 ] ;
F_12 ( L_29
L_30 , V_13 -> V_27 ,
F_41 ( & V_4 -> V_21 ) , V_91 , - V_95 ) ;
F_40 ( V_2 ) ;
return - V_95 ;
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
return - V_100 ;
}
if ( V_2 -> V_94 ) {
memcpy ( V_96 , V_2 -> V_19 ,
sizeof( * V_96 ) * V_2 -> V_94 ) ;
V_97 = V_2 -> V_19 ;
V_99 = V_2 -> V_94 ;
}
V_2 -> V_19 = V_96 ;
V_2 -> V_94 = V_98 ;
F_43 () ;
if ( V_97 )
F_44 ( V_97 , sizeof( * V_97 ) * V_99 ) ;
F_3 ( V_81 , L_31 , V_2 -> V_19 ,
V_2 -> V_94 ) ;
}
F_45 ( V_4 ) ;
if ( ! V_4 ) {
F_40 ( V_2 ) ;
return - V_100 ;
}
F_46 ( & V_4 -> V_101 ) ;
V_4 -> V_87 = V_91 ;
V_4 -> V_21 = * V_92 ;
V_4 -> V_6 = 0 ;
V_2 -> V_19 [ V_91 ] = V_4 ;
if ( V_91 >= V_2 -> V_7 . V_18 )
V_2 -> V_7 . V_18 = V_91 + 1 ;
if ( V_2 -> V_60 ) {
V_15 = F_27 ( V_13 , V_4 ) ;
if ( V_15 ) {
F_4 ( & V_2 -> V_17 ) ;
V_2 -> V_7 . V_18 -- ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_8 ( & V_2 -> V_17 ) ;
} else {
int V_67 = sizeof( struct V_102 ) +
V_2 -> V_7 . V_18 * sizeof( struct V_103 ) ;
F_24 ( V_13 -> V_48 , V_67 , 0 , 0 , 0 ) ;
}
}
F_40 ( V_2 ) ;
return V_15 ;
}
int F_20 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_14 ;
int V_15 ;
int V_67 ;
if ( V_2 -> V_60 )
return 0 ;
F_39 ( V_2 ) ;
if ( V_2 -> V_60 ) {
F_40 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_7 . V_18 == 0 ) {
F_40 ( V_2 ) ;
F_12 ( L_32 , V_13 -> V_27 ) ;
return - V_25 ;
}
F_3 ( V_81 , L_33 ,
V_2 -> V_53 . V_10 , V_13 -> V_27 ) ;
F_7 ( V_2 -> V_19 != NULL ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL )
continue;
V_15 = F_27 ( V_13 , V_4 ) ;
if ( V_15 )
GOTO ( V_104 , V_15 ) ;
}
F_22 ( V_13 ) ;
F_47 ( V_2 -> exp ) ;
V_2 -> V_60 = 1 ;
V_67 = F_48 ( V_2 ) ;
F_24 ( V_13 -> V_48 , V_67 , 0 , 0 , 0 ) ;
F_40 ( V_2 ) ;
return 0 ;
V_104:
while ( V_14 -- > 0 ) {
int V_105 ;
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL )
continue;
V_4 -> V_6 = 0 ;
if ( V_4 -> V_20 ) {
-- V_2 -> V_7 . V_8 ;
V_105 = F_33 ( V_4 -> V_20 ) ;
if ( V_105 ) {
F_12 ( L_34
L_35 ,
V_4 -> V_21 . V_10 , V_14 , V_105 ) ;
}
}
}
F_49 ( V_2 -> exp ) ;
F_40 ( V_2 ) ;
return V_15 ;
}
static int F_50 ( struct V_12 * V_13 , struct V_3 * V_4 )
{
struct V_55 * V_56 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_12 * V_77 ;
int V_15 ;
F_7 ( V_4 != NULL ) ;
F_7 ( V_13 != NULL ) ;
V_77 = F_6 ( V_4 -> V_20 ) ;
if ( V_77 ) {
V_77 -> V_106 = V_13 -> V_106 ;
V_77 -> V_107 = V_13 -> V_107 ;
V_77 -> V_108 = V_13 -> V_108 ;
}
V_56 = V_13 -> V_61 ;
if ( V_56 )
F_51 ( V_77 -> V_27 , V_56 ) ;
V_15 = F_52 ( V_4 -> V_20 -> V_33 ) ;
if ( V_15 )
F_12 ( L_36 ) ;
F_3 ( V_16 , L_37 ,
V_4 -> V_20 -> V_33 -> V_27 ,
V_4 -> V_20 -> V_33 -> V_9 . V_10 ) ;
F_32 ( V_4 -> V_20 -> V_33 , NULL ) ;
V_15 = F_33 ( V_4 -> V_20 ) ;
if ( V_15 ) {
if ( V_4 -> V_6 ) {
F_12 ( L_38 ,
V_4 -> V_21 . V_10 , V_15 ) ;
}
}
F_1 ( V_2 , V_4 , 0 ) ;
V_4 -> V_20 = NULL ;
return 0 ;
}
static int F_53 ( struct V_32 * exp )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
int V_15 ;
int V_14 ;
if ( ! V_2 -> V_19 )
goto V_109;
V_2 -> V_59 -- ;
if ( V_2 -> V_59 != 0 )
goto V_109;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL || V_2 -> V_19 [ V_14 ] -> V_20 == NULL )
continue;
F_50 ( V_13 , V_2 -> V_19 [ V_14 ] ) ;
}
if ( V_13 -> V_61 )
F_21 ( (struct V_55 * * ) & V_13 -> V_61 ) ;
else
F_12 ( L_39 ,
V_13 -> V_29 -> V_30 , V_13 -> V_27 ) ;
V_109:
if ( ! V_2 -> V_60 )
F_47 ( exp ) ;
V_15 = F_49 ( exp ) ;
if ( V_2 -> V_59 == 0 )
V_2 -> V_60 = 0 ;
return V_15 ;
}
static int F_54 ( struct V_32 * exp , int V_110 , void * V_111 , void * V_112 )
{
struct V_12 * V_113 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_113 -> V_34 . V_2 ;
struct V_114 * V_115 ;
struct V_3 * V_4 ;
struct V_114 * V_116 = NULL ;
int V_117 = 0 ;
int V_15 ;
V_115 = (struct V_114 * ) V_111 ;
V_4 = F_55 ( V_2 , & V_115 -> V_118 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_119:
V_15 = F_57 ( V_120 , V_4 -> V_20 , V_110 , V_115 , V_112 ) ;
if ( V_15 != 0 && V_15 != - V_121 )
GOTO ( V_122 , V_15 ) ;
if ( V_116 != NULL ) {
struct V_114 * V_123 ;
char * V_124 ;
V_123 = (struct V_114 * ) V_111 ;
if ( strlen ( V_123 -> V_125 ) +
strlen ( V_115 -> V_125 ) > V_123 -> V_126 )
GOTO ( V_122 , V_15 = - V_127 ) ;
V_124 = V_123 -> V_125 ;
memmove ( V_124 + strlen ( V_115 -> V_125 ) + 1 , V_124 ,
strlen ( V_123 -> V_125 ) ) ;
strncpy ( V_124 , V_115 -> V_125 , strlen ( V_115 -> V_125 ) ) ;
V_124 += strlen ( V_115 -> V_125 ) ;
* V_124 = '/' ;
}
F_3 ( V_16 , L_40 V_128 L_41 ,
V_4 -> V_20 -> V_33 -> V_27 ,
V_115 -> V_125 , F_58 ( & V_115 -> V_118 ) , V_115 -> V_129 ,
V_115 -> V_130 ) ;
if ( V_15 == 0 )
GOTO ( V_122 , V_15 ) ;
if ( V_116 == NULL ) {
V_117 = sizeof( * V_116 ) + V_131 ;
F_42 ( V_116 , V_117 ) ;
if ( V_116 == NULL )
GOTO ( V_122 , V_15 = - V_100 ) ;
V_116 -> V_126 = V_131 ;
}
if ( ! F_59 ( & V_115 -> V_118 ) ) {
F_12 ( L_42 V_128 L_43 ,
V_4 -> V_20 -> V_33 -> V_27 ,
F_58 ( & V_115 -> V_118 ) , - V_25 ) ;
GOTO ( V_122 , V_15 = - V_25 ) ;
}
V_4 = F_55 ( V_2 , & V_115 -> V_118 ) ;
if ( F_19 ( V_4 ) )
GOTO ( V_122 , V_15 = - V_25 ) ;
V_116 -> V_118 = V_115 -> V_118 ;
V_116 -> V_129 = - 1 ;
V_116 -> V_130 = - 1 ;
memset ( V_116 -> V_125 , 0 , V_116 -> V_126 ) ;
V_115 = V_116 ;
goto V_119;
V_122:
if ( V_116 != NULL )
F_44 ( V_116 , V_117 ) ;
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
if ( F_5 ( & V_136 -> V_21 , & V_134 -> V_21 ) )
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
if ( F_5 ( & V_136 -> V_21 , & V_134 -> V_21 ) ) {
V_142 -> V_139 [ V_143 ] =
V_141 -> V_139 [ V_14 ] ;
V_143 ++ ;
}
}
V_142 -> V_137 . V_138 = V_143 ;
memcpy ( F_62 ( V_142 ) , F_62 ( V_141 ) ,
V_141 -> V_137 . V_144 ) ;
}
static int F_63 ( struct V_1 * V_2 , unsigned int V_145 , int V_110 ,
struct V_146 * V_147 , void * V_112 )
{
int V_14 , V_15 = 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
F_57 ( V_145 , V_2 -> V_19 [ V_14 ] -> V_20 , V_110 , V_147 , V_112 ) ;
}
V_15 = F_64 ( V_147 -> V_148 , V_147 -> V_149 ) ;
return V_15 ;
}
static int F_65 ( struct V_1 * V_2 , unsigned int V_145 , int V_110 ,
struct V_146 * V_147 , void * V_112 )
{
struct V_150 * V_151 ;
int V_14 , V_152 , V_153 ;
int V_15 = 0 ;
bool V_154 = false ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_153 = F_57 ( V_145 , V_2 -> V_19 [ V_14 ] -> V_20 ,
V_110 , V_147 , V_112 ) ;
if ( V_153 ) {
if ( V_2 -> V_19 [ V_14 ] -> V_6 ) {
F_12 ( L_44
L_45 ,
V_2 -> V_19 [ V_14 ] -> V_21 . V_10 ,
V_14 , V_145 , V_153 ) ;
V_15 = V_153 ;
V_147 -> V_155 |= V_156 ;
for ( V_152 = 0 ; V_152 < V_14 ; V_152 ++ )
F_57 ( V_145 ,
V_2 -> V_19 [ V_152 ] -> V_20 ,
V_110 , V_147 , V_112 ) ;
return V_15 ;
}
} else {
V_154 = true ;
}
}
if ( ! V_154 )
return - V_26 ;
V_151 = F_66 ( V_147 -> V_157 ) ;
if ( V_151 == NULL ) {
return - V_158 ;
}
V_15 = F_67 ( V_151 , V_147 -> V_148 , V_147 -> V_149 , V_147 -> V_159 ) ;
if ( V_15 != 0 && V_151 != NULL )
F_68 ( V_151 ) ;
return V_15 ;
}
static int F_69 ( unsigned int V_145 , struct V_32 * exp ,
int V_110 , void * V_111 , void * V_112 )
{
struct V_12 * V_113 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_113 -> V_34 . V_2 ;
int V_14 = 0 ;
int V_15 = 0 ;
int V_160 = 0 ;
int V_161 = V_2 -> V_7 . V_18 ;
if ( V_161 == 0 )
return - V_162 ;
switch ( V_145 ) {
case V_163 : {
struct V_164 * V_38 = V_111 ;
struct V_12 * V_77 ;
struct V_165 V_166 = { 0 } ;
T_1 V_91 ;
memcpy ( & V_91 , V_38 -> V_167 , sizeof( T_1 ) ) ;
if ( ( V_91 >= V_161 ) )
return - V_168 ;
if ( V_2 -> V_19 [ V_91 ] == NULL ||
V_2 -> V_19 [ V_91 ] -> V_6 == 0 )
return - V_169 ;
V_77 = F_6 ( V_2 -> V_19 [ V_91 ] -> V_20 ) ;
if ( ! V_77 )
return - V_25 ;
if ( F_70 ( V_38 -> V_170 , F_71 ( V_77 ) ,
F_72 ( ( int ) V_38 -> V_171 ,
( int ) sizeof( struct V_9 ) ) ) )
return - V_172 ;
V_15 = V_165 ( NULL , V_2 -> V_19 [ V_91 ] -> V_20 , & V_166 ,
F_73 ( - V_173 ) ,
0 ) ;
if ( V_15 )
return V_15 ;
if ( F_70 ( V_38 -> V_174 , & V_166 ,
F_72 ( ( int ) V_38 -> V_175 ,
( int ) sizeof( V_166 ) ) ) )
return - V_172 ;
break;
}
case V_176 : {
struct V_177 * V_178 = V_111 ;
struct V_3 * V_4 = NULL ;
struct V_179 * V_180 ;
if ( V_178 -> V_181 == V_182 ) {
if ( V_178 -> V_183 < 0 || V_161 <= V_178 -> V_183 )
return - V_25 ;
V_4 = V_2 -> V_19 [ V_178 -> V_183 ] ;
if ( V_4 == NULL || V_4 -> V_20 == NULL )
return - V_25 ;
} else if ( V_178 -> V_181 == V_184 ) {
for ( V_14 = 0 ; V_14 < V_161 ; V_14 ++ ) {
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL )
continue;
if ( ! F_5 ( & V_4 -> V_21 ,
& V_178 -> V_9 ) )
continue;
if ( V_4 -> V_20 == NULL )
return - V_25 ;
break;
}
} else {
return - V_25 ;
}
if ( V_14 >= V_161 )
return - V_185 ;
F_7 ( V_4 && V_4 -> V_20 ) ;
F_45 ( V_180 ) ;
if ( ! V_180 )
return - V_100 ;
F_74 ( V_180 , V_178 ) ;
V_15 = V_179 ( V_4 -> V_20 , V_180 ) ;
if ( V_15 == 0 ) {
F_74 ( V_178 , V_180 ) ;
V_178 -> V_181 = V_182 ;
V_178 -> V_9 = V_4 -> V_21 ;
}
F_37 ( V_180 ) ;
break;
}
case V_186 :
case V_187 : {
struct V_188 * V_189 = V_111 ;
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
V_15 = F_57 ( V_145 , V_2 -> V_19 [ 0 ] -> V_20 , V_110 , V_111 , V_112 ) ;
break;
}
case V_120 : {
V_15 = F_54 ( exp , V_110 , V_111 , V_112 ) ;
break;
}
case V_192 :
case V_193 :
case V_194 : {
struct V_195 * V_196 = V_111 ;
struct V_3 * V_4 ;
V_4 = F_55 ( V_2 , & V_196 -> V_197 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
if ( V_4 -> V_20 == NULL )
return - V_25 ;
V_15 = F_57 ( V_145 , V_4 -> V_20 , V_110 , V_111 , V_112 ) ;
break;
}
case V_198 : {
const struct V_199 * V_200 = V_111 ;
struct V_3 * V_4 ;
V_4 = F_55 ( V_2 , & V_200 -> V_201 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_57 ( V_145 , V_4 -> V_20 , V_110 , V_111 , V_112 ) ;
break;
}
case V_202 : {
struct V_132 * V_133 = V_111 ;
struct V_3 * V_4 ;
unsigned int V_203 = V_133 -> V_137 . V_138 ;
if ( V_203 == 0 )
return 0 ;
if ( V_203 == 1 || V_161 == 1 ) {
V_4 = F_55 ( V_2 ,
& V_133 -> V_139 [ 0 ] . V_140 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_57 ( V_145 , V_4 -> V_20 , V_110 , V_111 , V_112 ) ;
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
return - V_100 ;
F_61 ( V_2 , V_133 , V_2 -> V_19 [ V_14 ] , V_206 ) ;
V_205 = F_57 ( V_145 , V_2 -> V_19 [ V_14 ] -> V_20 ,
V_204 , V_206 , V_112 ) ;
if ( V_205 != 0 && V_15 == 0 )
V_15 = V_205 ;
F_78 ( V_206 , V_204 ) ;
}
}
break;
}
case V_207 : {
struct V_195 * V_196 = V_111 ;
struct V_3 * V_208 , * V_209 ;
V_208 = F_55 ( V_2 , & V_196 -> V_197 ) ;
if ( F_19 ( V_208 ) )
return F_56 ( V_208 ) ;
V_209 = F_55 ( V_2 , & V_196 -> V_210 ) ;
if ( F_19 ( V_209 ) )
return F_56 ( V_209 ) ;
if ( ( V_208 -> V_20 == NULL ) || ( V_209 -> V_20 == NULL ) )
return - V_25 ;
if ( V_208 -> V_87 != V_209 -> V_87 )
return - V_211 ;
V_15 = F_57 ( V_145 , V_208 -> V_20 , V_110 , V_111 , V_112 ) ;
break;
}
case V_212 : {
struct V_146 * V_147 = V_111 ;
if ( V_147 -> V_155 & V_156 )
V_15 = F_63 ( V_2 , V_145 , V_110 , V_147 , V_112 ) ;
else
V_15 = F_65 ( V_2 , V_145 , V_110 , V_147 , V_112 ) ;
break;
}
default:
for ( V_14 = 0 ; V_14 < V_161 ; V_14 ++ ) {
struct V_12 * V_77 ;
int V_153 ;
if ( V_2 -> V_19 [ V_14 ] == NULL ||
V_2 -> V_19 [ V_14 ] -> V_20 == NULL )
continue;
V_77 = F_6 ( V_2 -> V_19 [ V_14 ] -> V_20 ) ;
V_77 -> V_106 = V_113 -> V_106 ;
V_153 = F_57 ( V_145 , V_2 -> V_19 [ V_14 ] -> V_20 , V_110 ,
V_111 , V_112 ) ;
if ( V_153 == - V_169 && V_145 == V_213 ) {
return V_153 ;
} else if ( V_153 ) {
if ( V_2 -> V_19 [ V_14 ] -> V_6 ) {
F_12 ( L_44
L_45 ,
V_2 -> V_19 [ V_14 ] -> V_21 . V_10 ,
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
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
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
F_12 ( L_46
L_30 , V_13 -> V_27 ,
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
int F_80 ( struct V_1 * V_2 , struct V_103 * V_225 ,
T_2 V_215 )
{
struct V_3 * V_4 ;
int V_15 ;
V_4 = F_81 ( V_2 , V_215 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
F_82 ( & V_4 -> V_101 ) ;
if ( V_4 -> V_6 == 0 || V_4 -> V_20 == NULL )
GOTO ( V_226 , V_15 = - V_168 ) ;
V_15 = F_83 ( V_4 -> V_20 , V_225 , NULL ) ;
if ( V_15 > 0 ) {
F_7 ( F_59 ( V_225 ) ) ;
V_15 = 0 ;
}
V_226:
F_84 ( & V_4 -> V_101 ) ;
return V_15 ;
}
int F_85 ( struct V_32 * exp , struct V_103 * V_225 ,
struct V_195 * V_196 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
T_2 V_215 = 0 ;
int V_15 ;
F_7 ( V_196 != NULL ) ;
F_7 ( V_225 != NULL ) ;
V_15 = F_79 ( V_13 , V_196 , & V_215 ) ;
if ( V_15 ) {
F_12 ( L_47
L_48 , V_15 ) ;
return V_15 ;
}
V_15 = F_80 ( V_2 , V_225 , V_215 ) ;
if ( V_15 ) {
F_12 ( L_49 , V_15 ) ;
return V_15 ;
}
return V_15 ;
}
static int F_86 ( struct V_12 * V_13 , struct V_227 * V_228 )
{
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_229 V_230 ;
struct V_231 * V_7 ;
int V_15 ;
if ( F_87 ( V_228 , 1 ) < 1 ) {
F_12 ( L_50 ) ;
return - V_25 ;
}
V_7 = (struct V_231 * ) F_88 ( V_228 , 1 ) ;
if ( sizeof( * V_7 ) > F_87 ( V_228 , 1 ) ) {
F_12 ( L_51 ,
( int ) sizeof( * V_7 ) , F_87 ( V_228 , 1 ) ) ;
return - V_25 ;
}
F_42 ( V_2 -> V_19 , sizeof( * V_2 -> V_19 ) * 32 ) ;
if ( V_2 -> V_19 == NULL )
return - V_100 ;
V_2 -> V_94 = 32 ;
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
#if F_93 ( V_237 )
{
V_15 = F_94 ( V_13 -> V_62 , L_52 ,
0444 , & V_238 , V_13 ) ;
if ( V_15 )
F_25 ( L_53 ,
V_13 -> V_27 , V_15 ) ;
}
#endif
V_15 = F_95 ( & V_2 -> V_88 , V_13 -> V_27 ,
V_239 ) ;
if ( V_15 ) {
F_12 ( L_54 , V_15 ) ;
GOTO ( V_226 , V_15 ) ;
}
return 0 ;
V_226:
return V_15 ;
}
static int F_96 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
F_97 ( & V_2 -> V_88 ) ;
if ( V_2 -> V_19 != NULL ) {
int V_14 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL )
continue;
F_36 ( V_2 , V_14 ) ;
}
F_44 ( V_2 -> V_19 , sizeof( * V_2 -> V_19 ) * V_2 -> V_94 ) ;
V_2 -> V_94 = 0 ;
}
return 0 ;
}
static int F_98 ( struct V_12 * V_13 , T_3 V_110 , void * V_240 )
{
struct V_227 * V_228 = V_240 ;
struct V_9 V_9 ;
int V_93 ;
T_1 V_91 ;
int V_15 ;
switch ( V_228 -> V_241 ) {
case V_242 :
if ( F_87 ( V_228 , 1 ) > sizeof( V_9 . V_10 ) )
GOTO ( V_226 , V_15 = - V_25 ) ;
F_89 ( & V_9 , F_88 ( V_228 , 1 ) ) ;
if ( sscanf ( F_88 ( V_228 , 2 ) , L_55 , & V_91 ) != 1 )
GOTO ( V_226 , V_15 = - V_25 ) ;
if ( sscanf ( F_88 ( V_228 , 3 ) , L_55 , & V_93 ) != 1 )
GOTO ( V_226 , V_15 = - V_25 ) ;
V_15 = F_38 ( V_13 , & V_9 , V_91 , V_93 ) ;
GOTO ( V_226 , V_15 ) ;
default:
F_12 ( L_56 , V_228 -> V_241 ) ;
GOTO ( V_226 , V_15 = - V_25 ) ;
}
V_226:
return V_15 ;
}
static int F_99 ( const struct V_51 * V_52 , struct V_32 * exp ,
struct V_165 * V_243 , T_4 V_244 , T_1 V_245 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_165 * V_246 ;
int V_15 = 0 ;
int V_14 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_42 ( V_246 , sizeof( * V_246 ) ) ;
if ( V_246 == NULL )
return - V_100 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL || V_2 -> V_19 [ V_14 ] -> V_20 == NULL )
continue;
V_15 = V_165 ( V_52 , V_2 -> V_19 [ V_14 ] -> V_20 , V_246 ,
V_244 , V_245 ) ;
if ( V_15 ) {
F_12 ( L_57 , V_14 ,
V_2 -> V_19 [ V_14 ] -> V_20 -> V_33 -> V_27 ,
V_15 ) ;
GOTO ( V_247 , V_15 ) ;
}
if ( V_14 == 0 ) {
* V_243 = * V_246 ;
if ( V_245 & V_248 )
GOTO ( V_247 , V_15 ) ;
} else {
V_243 -> V_249 += V_246 -> V_249 ;
V_243 -> V_250 += V_246 -> V_250 ;
V_243 -> V_251 += V_246 -> V_251 ;
V_243 -> V_252 += V_246 -> V_252 ;
}
}
V_247:
F_44 ( V_246 , sizeof( * V_246 ) ) ;
return V_15 ;
}
static int F_100 ( struct V_32 * exp ,
struct V_103 * V_225 ,
struct V_253 * * V_254 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_101 ( V_2 -> V_19 [ 0 ] -> V_20 , V_225 , V_254 ) ;
return V_15 ;
}
static int F_102 ( struct V_32 * exp , const struct V_103 * V_225 ,
struct V_253 * V_255 , T_5 V_256 , const char * V_257 ,
const char * V_258 , int V_259 , int V_260 ,
int V_245 , struct V_261 * * V_262 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , V_225 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_103 ( V_4 -> V_20 , V_225 , V_255 , V_256 , V_257 , V_258 ,
V_259 , V_260 , V_245 , V_262 ) ;
return V_15 ;
}
static int F_104 ( struct V_32 * exp , const struct V_103 * V_225 ,
struct V_253 * V_255 , T_5 V_256 , const char * V_257 ,
const char * V_258 , int V_259 , int V_260 ,
int V_245 , T_1 V_263 ,
struct V_261 * * V_262 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , V_225 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_105 ( V_4 -> V_20 , V_225 , V_255 , V_256 , V_257 , V_258 ,
V_259 , V_260 , V_245 , V_263 ,
V_262 ) ;
return V_15 ;
}
static int F_106 ( struct V_32 * exp , struct V_195 * V_196 ,
struct V_261 * * V_262 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , & V_196 -> V_197 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
if ( V_196 -> V_264 & V_265 ) {
V_196 -> V_224 = V_4 -> V_87 ;
return 0 ;
}
V_15 = F_107 ( V_4 -> V_20 , V_196 , V_262 ) ;
return V_15 ;
}
static int F_108 ( struct V_32 * exp , const struct V_103 * V_225 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
int V_14 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_266 , L_58 V_128 L_59 , F_58 ( V_225 ) ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL || V_2 -> V_19 [ V_14 ] -> V_20 == NULL )
continue;
F_109 ( V_2 -> V_19 [ V_14 ] -> V_20 , V_225 ) ;
}
return 0 ;
}
static int F_110 ( struct V_32 * exp , const struct V_103 * V_225 ,
T_6 V_267 , void * V_38 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
int V_14 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_266 , L_58 V_128 L_59 , F_58 ( V_225 ) ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL || V_2 -> V_19 [ V_14 ] -> V_20 == NULL )
continue;
V_15 = F_111 ( V_2 -> V_19 [ V_14 ] -> V_20 , V_225 , V_267 , V_38 ) ;
if ( V_15 )
return V_15 ;
}
return V_15 ;
}
static int F_112 ( struct V_32 * exp , struct V_195 * V_196 ,
struct V_268 * V_269 , struct V_261 * * V_262 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , & V_196 -> V_197 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
F_3 ( V_266 , L_60 V_128 L_59 , F_58 ( & V_196 -> V_197 ) ) ;
V_15 = F_113 ( V_4 -> V_20 , V_196 , V_269 , V_262 ) ;
return V_15 ;
}
struct V_3
* F_114 ( struct V_1 * V_2 , struct V_195 * V_196 ,
struct V_103 * V_225 )
{
struct V_3 * V_4 ;
V_4 = F_55 ( V_2 , V_225 ) ;
if ( F_19 ( V_4 ) )
return V_4 ;
V_196 -> V_224 = V_4 -> V_87 ;
return V_4 ;
}
int F_115 ( struct V_32 * exp , struct V_195 * V_196 ,
const void * V_38 , int V_270 , int V_271 , T_1 V_272 ,
T_1 V_273 , T_7 V_274 , T_4 V_275 ,
struct V_261 * * V_262 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
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
F_3 ( V_266 , L_61 V_128 L_62 ,
V_196 -> V_276 , V_196 -> V_277 , F_58 ( & V_196 -> V_197 ) ,
V_196 -> V_224 ) ;
V_196 -> V_264 |= V_278 ;
V_15 = F_116 ( V_4 -> V_20 , V_196 , V_38 , V_270 , V_271 , V_272 , V_273 ,
V_274 , V_275 , V_262 ) ;
if ( V_15 == 0 ) {
if ( * V_262 == NULL )
return V_15 ;
F_3 ( V_266 , L_63 V_128 L_59 , F_58 ( & V_196 -> V_210 ) ) ;
}
return V_15 ;
}
static int F_117 ( struct V_32 * exp ,
struct V_195 * V_196 ,
struct V_268 * V_269 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , & V_196 -> V_197 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_118 ( V_4 -> V_20 , V_196 , V_269 ) ;
return V_15 ;
}
static int
F_119 ( struct V_32 * exp , struct V_279 * V_280 ,
struct V_281 * V_267 , struct V_195 * V_196 ,
struct V_57 * V_282 , void * V_283 , int V_284 ,
T_4 V_285 )
{
struct V_261 * V_206 = V_267 -> V_286 . V_287 . V_288 ;
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_57 V_289 ;
struct V_3 * V_4 ;
struct V_195 * V_290 ;
struct V_103 V_291 ;
struct V_292 * V_293 ;
int V_15 = 0 ;
int V_294 ;
V_293 = F_120 ( & V_206 -> V_295 , & V_296 ) ;
F_7 ( V_293 != NULL ) ;
if ( ! ( V_293 -> V_256 & V_297 ) )
return 0 ;
F_3 ( V_266 , L_64 V_128 L_65 V_128 L_59 ,
F_121 ( V_267 ) , F_58 ( & V_196 -> V_197 ) , F_58 ( & V_293 -> V_291 ) ) ;
V_294 = V_267 -> V_286 . V_287 . V_298 ;
F_7 ( V_294 != 0 ) ;
memcpy ( & V_289 , V_282 , sizeof( V_289 ) ) ;
V_267 -> V_286 . V_287 . V_298 = 0 ;
V_267 -> V_286 . V_287 . V_288 = NULL ;
V_291 = V_293 -> V_291 ;
F_122 ( V_206 ) ;
V_4 = F_55 ( V_2 , & V_291 ) ;
if ( F_19 ( V_4 ) )
GOTO ( V_226 , V_15 = F_56 ( V_4 ) ) ;
F_45 ( V_290 ) ;
if ( V_290 == NULL )
GOTO ( V_226 , V_15 = - V_100 ) ;
V_290 -> V_197 = V_291 ;
V_290 -> V_299 = V_300 ;
V_15 = F_123 ( V_4 -> V_20 , V_280 , V_267 , V_290 , V_282 ,
V_283 , V_284 , NULL , V_285 ) ;
F_37 ( V_290 ) ;
V_226:
F_124 ( & V_289 , V_294 ) ;
return V_15 ;
}
static int
F_125 ( struct V_32 * exp , struct V_279 * V_280 ,
struct V_281 * V_267 , struct V_195 * V_196 ,
struct V_57 * V_282 , void * V_283 , int V_284 ,
struct V_261 * * V_206 , T_4 V_285 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_266 , L_66 V_128 L_59 ,
F_121 ( V_267 ) , F_58 ( & V_196 -> V_197 ) ) ;
V_4 = F_114 ( V_2 , V_196 , & V_196 -> V_197 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
F_3 ( V_266 , L_66 V_128 L_67 ,
F_121 ( V_267 ) , F_58 ( & V_196 -> V_197 ) , V_4 -> V_87 ) ;
V_15 = F_123 ( V_4 -> V_20 , V_280 , V_267 , V_196 , V_282 ,
V_283 , V_284 , V_206 , V_285 ) ;
if ( V_15 == 0 && V_267 && V_267 -> V_301 == V_302 ) {
V_15 = F_119 ( exp , V_280 , V_267 , V_196 , V_282 ,
V_283 , V_284 , V_285 ) ;
}
return V_15 ;
}
static int
F_126 ( struct V_32 * exp , struct V_195 * V_196 ,
struct V_261 * * V_262 )
{
struct V_261 * V_206 = NULL ;
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
struct V_292 * V_293 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_114 ( V_2 , V_196 , & V_196 -> V_197 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
F_3 ( V_266 , L_68 V_128 L_67 ,
V_196 -> V_276 , V_196 -> V_277 , F_58 ( & V_196 -> V_197 ) ,
V_4 -> V_87 ) ;
V_15 = F_127 ( V_4 -> V_20 , V_196 , V_262 ) ;
if ( V_15 != 0 )
return V_15 ;
V_293 = F_120 ( & ( * V_262 ) -> V_295 ,
& V_296 ) ;
F_7 ( V_293 != NULL ) ;
if ( V_293 -> V_256 & V_297 ) {
struct V_103 V_303 = V_293 -> V_291 ;
F_3 ( V_266 , L_69 V_128 L_59 ,
F_58 ( & V_303 ) ) ;
V_4 = F_55 ( V_2 , & V_303 ) ;
if ( F_19 ( V_4 ) ) {
F_122 ( * V_262 ) ;
return F_56 ( V_4 ) ;
}
V_196 -> V_197 = V_303 ;
V_196 -> V_304 |= V_305 ;
V_196 -> V_276 = 0 ;
V_196 -> V_277 = NULL ;
V_15 = F_127 ( V_4 -> V_20 , V_196 , & V_206 ) ;
F_122 ( * V_262 ) ;
* V_262 = V_206 ;
}
return V_15 ;
}
static int F_128 ( struct V_32 * exp , struct V_195 * V_196 ,
int V_306 , T_8 V_271 , int V_307 , int V_308 )
{
struct V_103 * V_225 = F_129 ( V_196 , V_308 ) ;
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
T_9 V_309 = { { 0 } } ;
int V_15 = 0 ;
if ( ! F_59 ( V_225 ) )
return 0 ;
V_4 = F_55 ( V_2 , V_225 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
if ( V_4 -> V_87 != V_306 ) {
F_3 ( V_266 , L_70 V_128 L_59 , F_58 ( V_225 ) ) ;
V_309 . V_310 . V_307 = V_307 ;
V_15 = F_130 ( V_4 -> V_20 , V_225 , & V_309 ,
V_271 , V_311 , NULL ) ;
} else {
F_3 ( V_266 ,
L_71 V_128 L_59 ,
V_306 , F_58 ( V_225 ) ) ;
V_196 -> V_264 |= V_308 ;
V_15 = 0 ;
}
return V_15 ;
}
static int F_131 ( struct V_32 * exp , struct V_195 * V_196 ,
struct V_261 * * V_262 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_7 ( V_196 -> V_276 != 0 ) ;
F_3 ( V_266 , L_72 V_128 L_73 V_128 L_59 ,
F_58 ( & V_196 -> V_210 ) , V_196 -> V_276 ,
V_196 -> V_277 , F_58 ( & V_196 -> V_197 ) ) ;
V_196 -> V_312 = F_132 ( & V_313 , F_133 () ) ;
V_196 -> V_314 = F_134 ( & V_313 , F_135 () ) ;
V_196 -> V_315 = F_136 () ;
V_4 = F_114 ( V_2 , V_196 , & V_196 -> V_210 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_196 -> V_264 |= V_316 ;
V_15 = F_128 ( exp , V_196 , V_4 -> V_87 , V_317 ,
V_318 , V_278 ) ;
if ( V_15 != 0 )
return V_15 ;
V_15 = F_137 ( V_4 -> V_20 , V_196 , V_262 ) ;
return V_15 ;
}
static int F_138 ( struct V_32 * exp , struct V_195 * V_196 ,
const char * V_97 , int V_319 , const char * V_320 , int V_321 ,
struct V_261 * * V_262 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_322 ;
struct V_3 * V_323 ;
int V_15 ;
F_7 ( V_319 != 0 ) ;
F_3 ( V_266 , L_74 V_128 L_75 V_128 L_59 ,
V_319 , V_97 , F_58 ( & V_196 -> V_197 ) ,
V_321 , V_320 , F_58 ( & V_196 -> V_210 ) ) ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_196 -> V_312 = F_132 ( & V_313 , F_133 () ) ;
V_196 -> V_314 = F_134 ( & V_313 , F_135 () ) ;
V_196 -> V_315 = F_136 () ;
V_322 = F_114 ( V_2 , V_196 , & V_196 -> V_197 ) ;
if ( F_19 ( V_322 ) )
return F_56 ( V_322 ) ;
V_323 = F_114 ( V_2 , V_196 , & V_196 -> V_210 ) ;
if ( F_19 ( V_323 ) )
return F_56 ( V_323 ) ;
V_196 -> V_264 |= V_278 | V_324 ;
V_15 = F_128 ( exp , V_196 , V_322 -> V_87 ,
V_317 , V_318 ,
V_316 ) ;
if ( V_15 == 0 ) {
V_15 = F_128 ( exp , V_196 , V_322 -> V_87 ,
V_317 , V_325 ,
V_326 ) ;
}
if ( V_15 == 0 )
V_15 = F_128 ( exp , V_196 , V_322 -> V_87 ,
V_317 , V_327 ,
V_326 ) ;
if ( V_15 == 0 )
V_15 = F_139 ( V_322 -> V_20 , V_196 , V_97 , V_319 ,
V_320 , V_321 , V_262 ) ;
return V_15 ;
}
static int F_140 ( struct V_32 * exp , struct V_195 * V_196 ,
void * V_328 , int V_329 , void * V_330 , int V_331 ,
struct V_261 * * V_262 ,
struct V_268 * * V_269 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 = 0 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_266 , L_76 V_128 L_77 ,
F_58 ( & V_196 -> V_197 ) , V_196 -> V_332 . V_333 ) ;
V_196 -> V_264 |= V_278 ;
V_4 = F_55 ( V_2 , & V_196 -> V_197 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_141 ( V_4 -> V_20 , V_196 , V_328 , V_329 , V_330 ,
V_331 , V_262 , V_269 ) ;
return V_15 ;
}
static int F_142 ( struct V_32 * exp , const struct V_103 * V_225 ,
struct V_253 * V_255 , struct V_261 * * V_262 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , V_225 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_143 ( V_4 -> V_20 , V_225 , V_255 , V_262 ) ;
return V_15 ;
}
static void F_144 ( struct V_334 * * V_335 , int V_336 , int V_337 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_336 ; V_14 ++ ) {
struct V_338 * V_339 = F_145 ( V_335 [ V_14 ] ) ;
struct V_338 * V_340 = V_339 ;
struct V_341 * V_342 = NULL ;
struct V_341 * V_343 ;
T_4 V_344 = V_339 -> V_345 ;
T_1 V_245 = V_339 -> V_346 ;
while ( -- V_337 > 0 ) {
V_343 = F_146 ( V_339 ) ;
for ( V_342 = V_343 ; V_343 != NULL ;
V_342 = V_343 , V_343 = F_147 ( V_343 ) ) ;
V_339 = (struct V_338 * ) ( ( char * ) V_339 + V_347 ) ;
if ( ! ( ( unsigned long ) V_339 & ~ V_348 ) )
break;
V_344 = V_339 -> V_345 ;
V_245 = V_339 -> V_346 ;
if ( ! V_342 )
break;
F_7 ( F_148 ( V_342 -> V_349 ) == 0 ) ;
V_342 -> V_349 =
F_149 ( ( char * ) ( V_339 -> V_350 ) -
( char * ) V_342 ) ;
}
V_340 -> V_345 = V_344 ;
V_340 -> V_346 &= ~ F_150 ( V_351 ) ;
V_340 -> V_346 |= V_245 & F_150 ( V_351 ) ;
F_151 ( V_335 [ V_14 ] ) ;
}
F_152 ( V_337 == 0 , L_78 , V_337 ) ;
}
static int F_153 ( struct V_32 * exp , struct V_195 * V_196 ,
struct V_334 * * V_335 , struct V_261 * * V_262 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
T_4 V_352 = V_196 -> V_353 ;
int V_15 ;
int V_336 ;
int V_337 ;
struct V_3 * V_4 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_266 , L_79 V_128 L_59 ,
V_352 , F_58 ( & V_196 -> V_197 ) ) ;
V_4 = F_55 ( V_2 , & V_196 -> V_197 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_154 ( V_4 -> V_20 , V_196 , V_335 , V_262 ) ;
if ( V_15 != 0 )
return V_15 ;
V_336 = ( ( * V_262 ) -> V_354 -> V_355 + V_356 - 1 )
>> V_357 ;
V_337 = ( * V_262 ) -> V_354 -> V_355 >> V_358 ;
F_7 ( ! ( ( * V_262 ) -> V_354 -> V_355 & ~ V_359 ) ) ;
F_7 ( V_336 > 0 && V_336 <= V_196 -> V_360 ) ;
F_3 ( V_266 , L_80 , V_336 , V_337 ,
V_196 -> V_360 ) ;
F_144 ( V_335 , V_336 , V_337 ) ;
return V_15 ;
}
static int F_155 ( struct V_32 * exp , struct V_195 * V_196 ,
struct V_261 * * V_262 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 = NULL ;
struct V_292 * V_293 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_361:
if ( F_156 ( ! F_157 ( & V_196 -> V_210 ) ) )
V_4 = F_114 ( V_2 , V_196 , & V_196 -> V_210 ) ;
else
V_4 = F_114 ( V_2 , V_196 , & V_196 -> V_197 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_196 -> V_312 = F_132 ( & V_313 , F_133 () ) ;
V_196 -> V_314 = F_134 ( & V_313 , F_135 () ) ;
V_196 -> V_315 = F_136 () ;
V_196 -> V_264 |= V_278 | V_324 ;
V_15 = F_128 ( exp , V_196 , V_4 -> V_87 , V_317 ,
V_327 , V_324 ) ;
if ( V_15 != 0 )
return V_15 ;
F_3 ( V_266 , L_81 V_128 L_82 V_128 L_67 ,
F_58 ( & V_196 -> V_197 ) , F_58 ( & V_196 -> V_210 ) , V_4 -> V_87 ) ;
V_15 = F_158 ( V_4 -> V_20 , V_196 , V_262 ) ;
if ( V_15 != 0 && V_15 != - V_121 )
return V_15 ;
V_293 = F_120 ( & ( * V_262 ) -> V_295 , & V_296 ) ;
if ( V_293 == NULL )
return - V_362 ;
if ( F_156 ( ! ( V_293 -> V_256 & V_297 ) ) )
return 0 ;
F_3 ( V_266 , L_83 V_128 L_59 ,
exp -> V_33 -> V_27 , F_58 ( & V_293 -> V_291 ) ) ;
V_196 -> V_210 = V_293 -> V_291 ;
F_122 ( * V_262 ) ;
* V_262 = NULL ;
goto V_361;
}
static int F_159 ( struct V_12 * V_13 , enum V_363 V_364 )
{
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
int V_15 = 0 ;
switch ( V_364 ) {
case V_365 :
break;
case V_366 :
F_160 ( & V_2 -> V_88 ) ;
F_161 ( V_13 ) ;
break;
default:
break;
}
return V_15 ;
}
static int F_162 ( const struct V_51 * V_52 , struct V_32 * exp ,
T_1 V_367 , void * V_368 , T_1 * V_369 , void * V_370 ,
struct V_371 * V_372 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
int V_15 = 0 ;
V_13 = F_6 ( exp ) ;
if ( V_13 == NULL ) {
F_3 ( V_373 , L_84 ,
exp -> V_22 . V_23 ) ;
return - V_25 ;
}
V_2 = & V_13 -> V_34 . V_2 ;
if ( V_367 >= strlen ( L_85 ) && ! strcmp ( V_368 , L_85 ) ) {
struct V_3 * V_4 ;
int V_14 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_7 ( * V_369 == sizeof( T_1 ) ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL || V_4 -> V_20 == NULL )
continue;
if ( ! F_163 ( V_52 , V_4 -> V_20 , V_367 , V_368 ,
V_369 , V_370 , NULL ) )
return 0 ;
}
return - V_25 ;
} else if ( F_164 ( V_374 ) ||
F_164 ( V_375 ) ||
F_164 ( V_376 ) ||
F_164 ( V_377 ) ||
F_164 ( V_378 ) ) {
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_163 ( V_52 , V_2 -> V_19 [ 0 ] -> V_20 , V_367 , V_368 ,
V_369 , V_370 , NULL ) ;
if ( ! V_15 && F_164 ( V_378 ) )
exp -> V_49 = * (struct V_39 * ) V_370 ;
return V_15 ;
} else if ( F_164 ( V_379 ) ) {
* ( ( int * ) V_370 ) = V_2 -> V_7 . V_18 ;
return 0 ;
}
F_3 ( V_373 , L_86 ) ;
return - V_25 ;
}
int F_165 ( const struct V_51 * V_52 , struct V_32 * exp ,
T_3 V_367 , void * V_368 , T_3 V_369 ,
void * V_370 , struct V_380 * V_160 )
{
struct V_3 * V_4 ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
int V_15 = 0 ;
V_13 = F_6 ( exp ) ;
if ( V_13 == NULL ) {
F_3 ( V_373 , L_84 ,
exp -> V_22 . V_23 ) ;
return - V_25 ;
}
V_2 = & V_13 -> V_34 . V_2 ;
if ( F_164 ( V_381 ) || F_164 ( V_382 ) ) {
int V_14 , V_153 = 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL || V_4 -> V_20 == NULL )
continue;
V_153 = F_23 ( V_52 , V_4 -> V_20 ,
V_367 , V_368 , V_369 , V_370 , V_160 ) ;
if ( V_153 && V_15 == 0 )
V_15 = V_153 ;
}
return V_15 ;
}
return - V_25 ;
}
int F_166 ( struct V_32 * exp , struct V_383 * * V_384 ,
struct V_371 * V_372 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_102 * V_385 ;
struct V_102 * V_386 ;
int V_387 ;
int V_14 ;
V_387 = F_48 ( V_2 ) ;
if ( ! V_384 )
return V_387 ;
if ( * V_384 && ! V_372 ) {
F_78 ( * V_384 , V_387 ) ;
* V_384 = NULL ;
return 0 ;
}
if ( * V_384 == NULL ) {
F_77 ( * V_384 , V_387 ) ;
if ( * V_384 == NULL )
return - V_100 ;
}
if ( ! V_372 )
return V_387 ;
V_386 = (struct V_102 * ) V_372 ;
V_385 = (struct V_102 * ) * V_384 ;
if ( V_386 -> V_388 != V_389 &&
V_386 -> V_388 != V_390 )
return - V_25 ;
V_385 -> V_388 = F_150 ( V_386 -> V_388 ) ;
V_385 -> V_391 = F_150 ( V_386 -> V_391 ) ;
V_385 -> V_392 = F_150 ( V_386 -> V_392 ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_385 -> V_393 [ V_14 ] = V_386 -> V_393 [ V_14 ] ;
F_167 ( & V_385 -> V_393 [ V_14 ] , & V_386 -> V_393 [ V_14 ] ) ;
}
return V_387 ;
}
int F_168 ( struct V_32 * exp , struct V_371 * * V_386 ,
struct V_383 * V_283 , int V_394 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_102 * * V_395 = (struct V_102 * * ) V_386 ;
struct V_102 * V_396 = (struct V_102 * ) V_283 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
int V_387 ;
int V_14 ;
T_1 V_397 ;
V_387 = F_48 ( V_2 ) ;
if ( V_386 == NULL )
return V_387 ;
if ( * V_386 != NULL && V_283 == NULL ) {
F_78 ( * V_395 , V_387 ) ;
* V_386 = NULL ;
return 0 ;
}
F_7 ( V_387 == V_394 ) ;
F_77 ( * V_395 , V_387 ) ;
if ( * V_395 == NULL )
return - V_100 ;
if ( ! V_283 )
return V_387 ;
if ( V_396 -> V_388 == V_389 ||
V_396 -> V_388 == V_390 ||
V_396 -> V_388 == V_398 )
{
V_397 = F_169 ( V_396 -> V_388 ) ;
} else {
F_12 ( L_87 ) ;
F_170 () ;
}
( * V_395 ) -> V_388 = V_397 ;
( * V_395 ) -> V_391 = F_169 ( V_396 -> V_391 ) ;
( * V_395 ) -> V_392 = F_169 ( V_396 -> V_392 ) ;
for ( V_14 = 0 ; V_14 < ( * V_395 ) -> V_391 ; V_14 ++ ) {
( * V_395 ) -> V_393 [ V_14 ] = V_396 -> V_393 [ V_14 ] ;
F_171 ( & ( * V_395 ) -> V_393 [ V_14 ] , & ( * V_395 ) -> V_393 [ V_14 ] ) ;
}
return V_387 ;
}
static int F_172 ( struct V_32 * exp , const struct V_103 * V_225 ,
T_9 * V_309 , T_8 V_271 ,
T_10 V_245 , void * V_399 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
int V_15 = 0 ;
int V_153 ;
int V_14 ;
F_7 ( V_225 != NULL ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL || V_2 -> V_19 [ V_14 ] -> V_20 == NULL ||
V_2 -> V_19 [ V_14 ] -> V_6 == 0 )
continue;
V_153 = F_130 ( V_2 -> V_19 [ V_14 ] -> V_20 , V_225 ,
V_309 , V_271 , V_245 , V_399 ) ;
if ( ! V_15 )
V_15 = V_153 ;
}
return V_15 ;
}
int F_173 ( struct V_32 * exp , T_4 * V_282 , void * V_38 ,
T_4 * V_307 )
{
struct V_1 * V_2 = & exp -> V_33 -> V_34 . V_2 ;
int V_15 ;
V_15 = F_174 ( V_2 -> V_19 [ 0 ] -> V_20 , V_282 , V_38 , V_307 ) ;
return V_15 ;
}
T_8 F_175 ( struct V_32 * exp , T_4 V_245 ,
const struct V_103 * V_225 , T_11 type ,
T_9 * V_309 , T_8 V_271 ,
struct V_57 * V_282 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
T_8 V_15 ;
int V_14 ;
F_3 ( V_266 , L_88 V_128 L_59 , F_58 ( V_225 ) ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL ||
V_2 -> V_19 [ V_14 ] -> V_20 == NULL ||
V_2 -> V_19 [ V_14 ] -> V_6 == 0 )
continue;
V_15 = F_176 ( V_2 -> V_19 [ V_14 ] -> V_20 , V_245 , V_225 ,
type , V_309 , V_271 , V_282 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
int F_177 ( struct V_32 * exp , struct V_261 * V_206 ,
struct V_32 * V_400 , struct V_32 * V_401 ,
struct V_402 * V_403 )
{
struct V_1 * V_2 = & exp -> V_33 -> V_34 . V_2 ;
return F_178 ( V_2 -> V_19 [ 0 ] -> V_20 , V_206 , V_400 , V_401 , V_403 ) ;
}
int F_179 ( struct V_32 * exp , struct V_402 * V_403 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
if ( V_403 -> V_396 )
F_180 ( exp , ( void * ) & V_403 -> V_396 ) ;
return F_181 ( V_2 -> V_19 [ 0 ] -> V_20 , V_403 ) ;
}
int F_182 ( struct V_32 * exp ,
struct V_404 * V_405 ,
struct V_281 * V_267 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
V_4 = F_55 ( V_2 , & V_405 -> V_406 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
return F_183 ( V_4 -> V_20 , V_405 , V_267 ) ;
}
int F_184 ( struct V_32 * exp ,
struct V_404 * V_405 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
V_4 = F_55 ( V_2 , & V_405 -> V_406 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
return F_185 ( V_4 -> V_20 , V_405 ) ;
}
static int F_186 ( struct V_32 * exp ,
const struct V_103 * V_225 ,
struct V_253 * V_255 , T_1 V_263 ,
struct V_261 * * V_262 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , V_225 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_187 ( V_4 -> V_20 , V_225 , V_255 , V_263 , V_262 ) ;
return V_15 ;
}
static int F_188 ( struct V_32 * exp , struct V_253 * V_255 ,
T_12 V_407 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , & V_255 -> V_408 . V_409 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_189 ( V_4 -> V_20 , V_255 , V_407 ) ;
return V_15 ;
}
int F_190 ( struct V_32 * exp , struct V_261 * V_206 ,
const struct V_410 * V_411 , struct V_253 * * V_255 )
{
struct V_1 * V_2 = & exp -> V_33 -> V_34 . V_2 ;
return F_191 ( V_2 -> V_19 [ 0 ] -> V_20 , V_206 , V_411 , V_255 ) ;
}
int F_192 ( struct V_32 * exp ,
struct V_412 * V_413 ,
struct V_279 * V_280 )
{
struct V_195 * V_196 = & V_413 -> V_414 ;
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 = NULL ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , & V_196 -> V_197 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_193 ( V_4 -> V_20 , V_413 , V_280 ) ;
return V_15 ;
}
int F_194 ( struct V_32 * exp , struct V_281 * V_267 ,
struct V_103 * V_225 , T_4 * V_307 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_20 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_55 ( V_2 , V_225 ) ;
if ( F_19 ( V_4 ) )
return F_56 ( V_4 ) ;
V_15 = F_195 ( V_4 -> V_20 , V_267 , V_225 , V_307 ) ;
return V_15 ;
}
int F_196 ( struct V_12 * V_415 , struct V_32 * exp ,
struct V_179 * V_180 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 = V_2 -> V_19 [ 0 ] ;
int V_15 = 0 , V_14 ;
T_4 V_416 , V_417 ;
if ( ! V_2 -> V_7 . V_18 || ! V_4 -> V_6 ) {
F_12 ( L_89 ) ;
return - V_214 ;
}
if ( V_180 -> V_418 != V_419 ) {
V_15 = V_179 ( V_4 -> V_20 , V_180 ) ;
return V_15 ;
}
V_416 = V_417 = 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
int V_153 ;
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL || V_4 -> V_20 == NULL || V_4 -> V_6 == 0 )
continue;
if ( ! V_4 -> V_6 ) {
F_3 ( V_420 , L_90 , V_14 ) ;
continue;
}
V_153 = V_179 ( V_4 -> V_20 , V_180 ) ;
if ( V_153 ) {
F_12 ( L_91 , V_14 , V_153 ) ;
if ( ! V_15 )
V_15 = V_153 ;
} else {
V_416 += V_180 -> V_421 . V_422 ;
V_417 += V_180 -> V_421 . V_423 ;
}
}
V_180 -> V_421 . V_422 = V_416 ;
V_180 -> V_421 . V_423 = V_417 ;
return V_15 ;
}
int F_197 ( struct V_12 * V_415 , struct V_32 * exp ,
struct V_179 * V_180 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_14 , V_15 = 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
int V_153 ;
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL || V_4 -> V_20 == NULL || ! V_4 -> V_6 ) {
F_12 ( L_92 , V_14 ) ;
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
V_15 = F_200 ( & V_424 , & V_425 ,
V_230 . V_426 , V_427 , NULL ) ;
return V_15 ;
}
static void F_201 ( void )
{
F_202 ( V_427 ) ;
}
