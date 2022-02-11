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
if ( V_14 == V_2 -> V_7 . V_18 ) {
V_15 = - V_24 ;
goto V_25;
}
V_13 = F_6 ( V_4 -> V_20 ) ;
if ( V_13 == NULL ) {
V_15 = - V_26 ;
goto V_25;
}
F_3 ( V_16 , L_3 ,
V_13 -> V_27 , V_13 -> V_9 . V_10 , V_13 -> V_28 , V_13 ,
V_13 -> V_29 -> V_30 , V_14 ) ;
F_7 ( strcmp ( V_13 -> V_29 -> V_30 , V_31 ) == 0 ) ;
if ( V_4 -> V_6 == V_5 ) {
F_3 ( V_16 , L_4 , V_13 ,
V_5 ? L_5 : L_6 ) ;
goto V_25;
}
F_3 ( V_16 , L_7 , V_13 ,
V_5 ? L_5 : L_6 ) ;
F_1 ( V_2 , V_4 , V_5 ) ;
V_25:
F_8 ( & V_2 -> V_17 ) ;
return V_15 ;
}
static struct V_9 * F_9 ( struct V_32 * exp )
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
return - V_24 ;
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
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_55 V_56 = { 0 } ;
int V_15 = 0 ;
V_2 -> V_57 ++ ;
if ( V_2 -> V_57 > 1 ) {
* exp = NULL ;
return 0 ;
}
V_15 = F_15 ( & V_56 , V_13 , V_53 ) ;
if ( V_15 ) {
F_12 ( L_11 , V_15 ) ;
return V_15 ;
}
* exp = F_16 ( & V_56 ) ;
F_17 ( * exp ) ;
V_2 -> exp = * exp ;
V_2 -> V_58 = 0 ;
V_2 -> V_53 = * V_53 ;
if ( V_38 )
V_2 -> V_40 = * V_38 ;
V_2 -> V_59 = F_18 ( L_12 ,
& V_13 -> V_60 ) ;
if ( V_38 -> V_61 & V_62 )
V_15 = F_19 ( V_13 ) ;
if ( V_15 && V_2 -> V_59 )
F_20 ( V_2 -> V_59 ) ;
return V_15 ;
}
static void F_21 ( struct V_12 * V_13 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_14 ;
V_2 = & V_13 -> V_34 . V_2 ;
if ( V_2 -> V_63 == 0 )
return;
if ( V_2 -> V_58 == 0 )
return;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL || V_4 -> V_20 == NULL || V_4 -> V_6 == 0 )
continue;
F_22 ( NULL , V_4 -> V_20 , sizeof( V_64 ) ,
V_64 , 0 , NULL , NULL ) ;
}
}
static int F_23 ( struct V_32 * exp , int V_65 ,
int V_66 , int V_67 , int V_68 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
int V_14 ;
int V_15 = 0 ;
int V_69 = 0 ;
if ( V_2 -> V_70 < V_65 ) {
V_2 -> V_70 = V_65 ;
V_69 = 1 ;
}
if ( V_2 -> V_71 < V_66 ) {
V_2 -> V_71 = V_66 ;
V_69 = 1 ;
}
if ( V_2 -> V_72 < V_67 ) {
V_2 -> V_72 = V_67 ;
V_69 = 1 ;
}
if ( V_2 -> V_73 < V_68 ) {
V_2 -> V_73 = V_68 ;
V_69 = 1 ;
}
if ( V_69 == 0 )
return 0 ;
if ( V_2 -> V_58 == 0 )
return 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL ||
V_2 -> V_19 [ V_14 ] -> V_20 == NULL ||
V_2 -> V_19 [ V_14 ] -> V_6 == 0 ) {
F_24 ( L_13 , V_13 -> V_27 , V_14 ) ;
continue;
}
V_15 = F_25 ( V_2 -> V_19 [ V_14 ] -> V_20 , V_65 , V_66 ,
V_67 , V_68 ) ;
if ( V_15 ) {
F_12 ( L_14 ,
V_13 -> V_27 , V_14 , V_15 ) ;
break;
}
}
return V_15 ;
}
static int F_26 ( struct V_12 * V_13 , struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_9 * V_53 = & V_2 -> V_53 ;
struct V_9 V_74 = { L_15 } ;
struct V_12 * V_75 ;
struct V_32 * V_76 ;
struct V_77 V_78 ;
int V_15 ;
V_75 = F_27 ( & V_4 -> V_21 , V_31 ,
& V_13 -> V_9 ) ;
if ( ! V_75 ) {
F_12 ( L_16 , V_4 -> V_21 . V_10 ) ;
return - V_24 ;
}
F_3 ( V_79 , L_17 ,
V_75 -> V_27 , V_75 -> V_9 . V_10 ,
V_4 -> V_21 . V_10 , V_13 -> V_9 . V_10 ,
V_53 -> V_10 ) ;
if ( ! V_75 -> V_80 ) {
F_12 ( L_18 , V_4 -> V_21 . V_10 ) ;
return - V_24 ;
}
V_15 = F_28 ( NULL , & V_76 , V_75 , & V_74 ,
& V_2 -> V_40 , NULL ) ;
if ( V_15 ) {
F_12 ( L_19 , V_4 -> V_21 . V_10 , V_15 ) ;
return V_15 ;
}
V_15 = F_29 ( V_75 , V_76 , V_81 ) ;
if ( V_15 )
return V_15 ;
V_78 . V_82 = NULL ;
V_78 . V_83 = V_76 ;
V_78 . V_84 = V_4 -> V_85 ;
F_30 ( & V_2 -> V_86 , & V_78 ) ;
V_15 = F_31 ( V_75 , V_13 ) ;
if ( V_15 ) {
F_32 ( V_76 ) ;
F_12 ( L_20 ,
V_4 -> V_21 . V_10 , V_15 ) ;
return V_15 ;
}
if ( V_13 -> V_50 ) {
V_15 = F_13 ( V_13 -> V_50 , V_76 -> V_33 ,
V_43 ,
( void * ) ( V_4 - V_2 -> V_19 [ 0 ] ) ) ;
if ( V_15 ) {
F_32 ( V_76 ) ;
return V_15 ;
}
}
V_4 -> V_6 = 1 ;
V_4 -> V_20 = V_76 ;
V_2 -> V_7 . V_8 ++ ;
F_25 ( V_4 -> V_20 , V_2 -> V_70 , V_2 -> V_71 ,
V_2 -> V_72 , V_2 -> V_73 ) ;
F_3 ( V_79 , L_21 ,
V_75 -> V_27 , V_75 -> V_9 . V_10 ,
F_33 ( & V_13 -> V_87 ) ) ;
if ( V_2 -> V_59 )
V_15 = F_34 ( V_2 -> V_59 , & V_75 -> V_60 ,
V_75 -> V_27 ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 , int V_88 )
{
if ( V_2 -> V_19 [ V_88 ] == NULL )
return;
F_36 ( V_2 -> V_19 [ V_88 ] ) ;
V_2 -> V_19 [ V_88 ] = NULL ;
return;
}
static int F_37 ( struct V_12 * V_13 , struct V_9 * V_89 ,
T_1 V_88 , int V_90 )
{
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 = 0 ;
F_3 ( V_79 , L_22 , V_89 -> V_10 , V_88 ) ;
F_38 ( V_2 ) ;
if ( V_2 -> V_7 . V_18 == 0 ) {
struct V_12 * V_75 ;
V_75 = F_27 ( V_89 , V_31 ,
& V_13 -> V_9 ) ;
if ( ! V_75 ) {
F_39 ( V_2 ) ;
F_12 ( L_23 ,
V_13 -> V_27 , V_89 -> V_10 , - V_24 ) ;
return - V_24 ;
}
}
if ( ( V_88 < V_2 -> V_91 ) && ( V_2 -> V_19 [ V_88 ] != NULL ) ) {
V_4 = V_2 -> V_19 [ V_88 ] ;
F_12 ( L_24 ,
V_13 -> V_27 ,
F_40 ( & V_4 -> V_21 ) , V_88 , - V_92 ) ;
F_39 ( V_2 ) ;
return - V_92 ;
}
if ( V_88 >= V_2 -> V_91 ) {
struct V_3 * * V_93 , * * V_94 = NULL ;
T_1 V_95 = 1 ;
T_1 V_96 = 0 ;
while ( V_95 < V_88 + 1 )
V_95 <<= 1 ;
V_93 = F_41 ( V_95 , sizeof( * V_93 ) , V_97 ) ;
if ( V_93 == NULL ) {
F_39 ( V_2 ) ;
return - V_98 ;
}
if ( V_2 -> V_91 ) {
memcpy ( V_93 , V_2 -> V_19 ,
sizeof( * V_93 ) * V_2 -> V_91 ) ;
V_94 = V_2 -> V_19 ;
V_96 = V_2 -> V_91 ;
}
V_2 -> V_19 = V_93 ;
V_2 -> V_91 = V_95 ;
F_42 () ;
F_36 ( V_94 ) ;
F_3 ( V_79 , L_25 , V_2 -> V_19 ,
V_2 -> V_91 ) ;
}
V_4 = F_43 ( sizeof( * V_4 ) , V_97 ) ;
if ( ! V_4 ) {
F_39 ( V_2 ) ;
return - V_98 ;
}
F_44 ( & V_4 -> V_99 ) ;
V_4 -> V_85 = V_88 ;
V_4 -> V_21 = * V_89 ;
V_4 -> V_6 = 0 ;
V_2 -> V_19 [ V_88 ] = V_4 ;
if ( V_88 >= V_2 -> V_7 . V_18 )
V_2 -> V_7 . V_18 = V_88 + 1 ;
if ( V_2 -> V_58 ) {
V_15 = F_26 ( V_13 , V_4 ) ;
if ( V_15 ) {
F_4 ( & V_2 -> V_17 ) ;
V_2 -> V_7 . V_18 -- ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_8 ( & V_2 -> V_17 ) ;
} else {
int V_65 = sizeof( struct V_100 ) +
V_2 -> V_7 . V_18 * sizeof( struct V_101 ) ;
F_23 ( V_13 -> V_48 , V_65 , 0 , 0 , 0 ) ;
}
}
F_39 ( V_2 ) ;
return V_15 ;
}
int F_19 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_14 ;
int V_15 ;
int V_65 ;
if ( V_2 -> V_58 )
return 0 ;
F_38 ( V_2 ) ;
if ( V_2 -> V_58 ) {
F_39 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_7 . V_18 == 0 ) {
F_39 ( V_2 ) ;
F_12 ( L_26 , V_13 -> V_27 ) ;
return - V_24 ;
}
F_3 ( V_79 , L_27 ,
V_2 -> V_53 . V_10 , V_13 -> V_27 ) ;
F_7 ( V_2 -> V_19 != NULL ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL )
continue;
V_15 = F_26 ( V_13 , V_4 ) ;
if ( V_15 )
goto V_102;
}
F_21 ( V_13 ) ;
F_45 ( V_2 -> exp ) ;
V_2 -> V_58 = 1 ;
V_65 = F_46 ( V_2 ) ;
F_23 ( V_13 -> V_48 , V_65 , 0 , 0 , 0 ) ;
F_39 ( V_2 ) ;
return 0 ;
V_102:
while ( V_14 -- > 0 ) {
int V_103 ;
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL )
continue;
V_4 -> V_6 = 0 ;
if ( V_4 -> V_20 ) {
-- V_2 -> V_7 . V_8 ;
V_103 = F_32 ( V_4 -> V_20 ) ;
if ( V_103 ) {
F_12 ( L_28 ,
V_4 -> V_21 . V_10 , V_14 , V_103 ) ;
}
}
}
F_47 ( V_2 -> exp ) ;
F_39 ( V_2 ) ;
return V_15 ;
}
static int F_48 ( struct V_12 * V_13 , struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_12 * V_75 ;
int V_15 ;
F_7 ( V_4 != NULL ) ;
F_7 ( V_13 != NULL ) ;
V_75 = F_6 ( V_4 -> V_20 ) ;
if ( V_75 ) {
V_75 -> V_104 = V_13 -> V_104 ;
V_75 -> V_105 = V_13 -> V_105 ;
V_75 -> V_106 = V_13 -> V_106 ;
}
if ( V_2 -> V_59 )
F_49 ( V_2 -> V_59 ,
V_75 -> V_27 ) ;
V_15 = F_50 ( V_4 -> V_20 -> V_33 ) ;
if ( V_15 )
F_12 ( L_29 ) ;
F_3 ( V_16 , L_30 ,
V_4 -> V_20 -> V_33 -> V_27 ,
V_4 -> V_20 -> V_33 -> V_9 . V_10 ) ;
F_31 ( V_4 -> V_20 -> V_33 , NULL ) ;
V_15 = F_32 ( V_4 -> V_20 ) ;
if ( V_15 ) {
if ( V_4 -> V_6 ) {
F_12 ( L_31 ,
V_4 -> V_21 . V_10 , V_15 ) ;
}
}
F_1 ( V_2 , V_4 , 0 ) ;
V_4 -> V_20 = NULL ;
return 0 ;
}
static int F_51 ( struct V_32 * exp )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
int V_15 ;
int V_14 ;
if ( ! V_2 -> V_19 )
goto V_107;
V_2 -> V_57 -- ;
if ( V_2 -> V_57 != 0 )
goto V_107;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL || V_2 -> V_19 [ V_14 ] -> V_20 == NULL )
continue;
F_48 ( V_13 , V_2 -> V_19 [ V_14 ] ) ;
}
if ( V_2 -> V_59 )
F_20 ( V_2 -> V_59 ) ;
V_107:
if ( ! V_2 -> V_58 )
F_45 ( exp ) ;
V_15 = F_47 ( exp ) ;
if ( V_2 -> V_57 == 0 )
V_2 -> V_58 = 0 ;
return V_15 ;
}
static int F_52 ( struct V_32 * exp , int V_108 , void * V_109 , void * V_110 )
{
struct V_12 * V_111 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_111 -> V_34 . V_2 ;
struct V_112 * V_113 ;
struct V_3 * V_4 ;
struct V_112 * V_114 = NULL ;
int V_115 = 0 ;
int V_15 ;
V_113 = (struct V_112 * ) V_109 ;
V_4 = F_53 ( V_2 , & V_113 -> V_116 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_117:
V_15 = F_56 ( V_118 , V_4 -> V_20 , V_108 , V_113 , V_110 ) ;
if ( V_15 != 0 && V_15 != - V_119 )
goto V_120;
if ( V_114 != NULL ) {
struct V_112 * V_121 ;
char * V_122 ;
V_121 = (struct V_112 * ) V_109 ;
if ( strlen ( V_121 -> V_123 ) +
strlen ( V_113 -> V_123 ) > V_121 -> V_124 ) {
V_15 = - V_125 ;
goto V_120;
}
V_122 = V_121 -> V_123 ;
memmove ( V_122 + strlen ( V_113 -> V_123 ) + 1 , V_122 ,
strlen ( V_121 -> V_123 ) ) ;
strncpy ( V_122 , V_113 -> V_123 , strlen ( V_113 -> V_123 ) ) ;
V_122 += strlen ( V_113 -> V_123 ) ;
* V_122 = '/' ;
}
F_3 ( V_16 , L_32 V_126 L_33 ,
V_4 -> V_20 -> V_33 -> V_27 ,
V_113 -> V_123 , F_57 ( & V_113 -> V_116 ) , V_113 -> V_127 ,
V_113 -> V_128 ) ;
if ( V_15 == 0 )
goto V_120;
if ( V_114 == NULL ) {
V_115 = sizeof( * V_114 ) + V_129 ;
V_114 = F_43 ( V_115 , V_97 ) ;
if ( V_114 == NULL ) {
V_15 = - V_98 ;
goto V_120;
}
V_114 -> V_124 = V_129 ;
}
if ( ! F_58 ( & V_113 -> V_116 ) ) {
F_12 ( L_34 V_126 L_35 ,
V_4 -> V_20 -> V_33 -> V_27 ,
F_57 ( & V_113 -> V_116 ) , - V_24 ) ;
V_15 = - V_24 ;
goto V_120;
}
V_4 = F_53 ( V_2 , & V_113 -> V_116 ) ;
if ( F_54 ( V_4 ) ) {
V_15 = - V_24 ;
goto V_120;
}
V_114 -> V_116 = V_113 -> V_116 ;
V_114 -> V_127 = - 1 ;
V_114 -> V_128 = - 1 ;
memset ( V_114 -> V_123 , 0 , V_114 -> V_124 ) ;
V_113 = V_114 ;
goto V_117;
V_120:
F_36 ( V_114 ) ;
return V_15 ;
}
static int F_59 ( struct V_1 * V_2 ,
const struct V_130 * V_131 ,
const struct V_3 * V_132 )
{
int V_14 , V_133 = 0 ;
struct V_3 * V_134 ;
for ( V_14 = 0 ; V_14 < V_131 -> V_135 . V_136 ; V_14 ++ ) {
V_134 = F_53 ( V_2 , & V_131 -> V_137 [ V_14 ] . V_138 ) ;
if ( F_5 ( & V_134 -> V_21 , & V_132 -> V_21 ) )
V_133 ++ ;
}
return V_133 ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_130 * V_139 ,
const struct V_3 * V_132 ,
struct V_130 * V_140 )
{
int V_14 , V_141 ;
struct V_3 * V_134 ;
V_140 -> V_135 = V_139 -> V_135 ;
V_141 = 0 ;
for ( V_14 = 0 ; V_14 < V_139 -> V_135 . V_136 ; V_14 ++ ) {
V_134 = F_53 ( V_2 ,
& V_139 -> V_137 [ V_14 ] . V_138 ) ;
if ( F_5 ( & V_134 -> V_21 , & V_132 -> V_21 ) ) {
V_140 -> V_137 [ V_141 ] =
V_139 -> V_137 [ V_14 ] ;
V_141 ++ ;
}
}
V_140 -> V_135 . V_136 = V_141 ;
memcpy ( F_61 ( V_140 ) , F_61 ( V_139 ) ,
V_139 -> V_135 . V_142 ) ;
}
static int F_62 ( struct V_1 * V_2 , unsigned int V_143 , int V_108 ,
struct V_144 * V_145 , void * V_110 )
{
int V_14 , V_15 = 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
F_56 ( V_143 , V_2 -> V_19 [ V_14 ] -> V_20 , V_108 , V_145 , V_110 ) ;
}
V_15 = F_63 ( V_145 -> V_146 , V_145 -> V_147 ) ;
return V_15 ;
}
static int F_64 ( struct V_1 * V_2 , unsigned int V_143 , int V_108 ,
struct V_144 * V_145 , void * V_110 )
{
struct V_148 * V_149 ;
int V_14 , V_150 , V_151 ;
int V_15 = 0 ;
bool V_152 = false ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_151 = F_56 ( V_143 , V_2 -> V_19 [ V_14 ] -> V_20 ,
V_108 , V_145 , V_110 ) ;
if ( V_151 ) {
if ( V_2 -> V_19 [ V_14 ] -> V_6 ) {
F_12 ( L_36 ,
V_2 -> V_19 [ V_14 ] -> V_21 . V_10 ,
V_14 , V_143 , V_151 ) ;
V_15 = V_151 ;
V_145 -> V_153 |= V_154 ;
for ( V_150 = 0 ; V_150 < V_14 ; V_150 ++ )
F_56 ( V_143 ,
V_2 -> V_19 [ V_150 ] -> V_20 ,
V_108 , V_145 , V_110 ) ;
return V_15 ;
}
} else {
V_152 = true ;
}
}
if ( ! V_152 )
return - V_26 ;
V_149 = F_65 ( V_145 -> V_155 ) ;
if ( V_149 == NULL ) {
return - V_156 ;
}
V_15 = F_66 ( V_149 , V_145 -> V_146 , V_145 -> V_147 , V_145 -> V_157 ) ;
if ( V_15 != 0 && V_149 != NULL )
F_67 ( V_149 ) ;
return V_15 ;
}
static int F_68 ( unsigned int V_143 , struct V_32 * exp ,
int V_108 , void * V_109 , void * V_110 )
{
struct V_12 * V_111 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_111 -> V_34 . V_2 ;
int V_14 = 0 ;
int V_15 = 0 ;
int V_158 = 0 ;
int V_159 = V_2 -> V_7 . V_18 ;
if ( V_159 == 0 )
return - V_160 ;
switch ( V_143 ) {
case V_161 : {
struct V_162 * V_38 = V_109 ;
struct V_12 * V_75 ;
struct V_163 V_164 = { 0 } ;
T_1 V_88 ;
memcpy ( & V_88 , V_38 -> V_165 , sizeof( T_1 ) ) ;
if ( V_88 >= V_159 )
return - V_166 ;
if ( V_2 -> V_19 [ V_88 ] == NULL ||
V_2 -> V_19 [ V_88 ] -> V_6 == 0 )
return - V_167 ;
V_75 = F_6 ( V_2 -> V_19 [ V_88 ] -> V_20 ) ;
if ( ! V_75 )
return - V_24 ;
if ( F_69 ( V_38 -> V_168 , F_70 ( V_75 ) ,
F_71 ( ( int ) V_38 -> V_169 ,
( int ) sizeof( struct V_9 ) ) ) )
return - V_170 ;
V_15 = V_163 ( NULL , V_2 -> V_19 [ V_88 ] -> V_20 , & V_164 ,
F_72 ( - V_171 ) ,
0 ) ;
if ( V_15 )
return V_15 ;
if ( F_69 ( V_38 -> V_172 , & V_164 ,
F_71 ( ( int ) V_38 -> V_173 ,
( int ) sizeof( V_164 ) ) ) )
return - V_170 ;
break;
}
case V_174 : {
struct V_175 * V_176 = V_109 ;
struct V_3 * V_4 = NULL ;
struct V_177 * V_178 ;
if ( V_176 -> V_179 == V_180 ) {
if ( V_176 -> V_181 < 0 || V_159 <= V_176 -> V_181 )
return - V_24 ;
V_4 = V_2 -> V_19 [ V_176 -> V_181 ] ;
if ( V_4 == NULL || V_4 -> V_20 == NULL )
return - V_24 ;
} else if ( V_176 -> V_179 == V_182 ) {
for ( V_14 = 0 ; V_14 < V_159 ; V_14 ++ ) {
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL )
continue;
if ( ! F_5 ( & V_4 -> V_21 ,
& V_176 -> V_9 ) )
continue;
if ( V_4 -> V_20 == NULL )
return - V_24 ;
break;
}
} else {
return - V_24 ;
}
if ( V_14 >= V_159 )
return - V_183 ;
F_7 ( V_4 && V_4 -> V_20 ) ;
V_178 = F_43 ( sizeof( * V_178 ) , V_97 ) ;
if ( ! V_178 )
return - V_98 ;
F_73 ( V_178 , V_176 ) ;
V_15 = V_177 ( V_4 -> V_20 , V_178 ) ;
if ( V_15 == 0 ) {
F_73 ( V_176 , V_178 ) ;
V_176 -> V_179 = V_180 ;
V_176 -> V_9 = V_4 -> V_21 ;
}
F_36 ( V_178 ) ;
break;
}
case V_184 :
case V_185 : {
struct V_186 * V_187 = V_109 ;
if ( V_187 -> V_188 >= V_159 )
return - V_166 ;
if ( V_2 -> V_19 [ V_187 -> V_188 ] == NULL ||
V_2 -> V_19 [ V_187 -> V_188 ] -> V_20 == NULL ||
V_2 -> V_19 [ V_187 -> V_188 ] -> V_6 == 0 )
return - V_166 ;
V_15 = F_56 ( V_143 , V_2 -> V_19 [ V_187 -> V_188 ] -> V_20 ,
sizeof( * V_187 ) , V_187 , NULL ) ;
break;
}
case V_189 : {
if ( V_2 -> V_19 [ 0 ] == NULL )
return - V_167 ;
V_15 = F_56 ( V_143 , V_2 -> V_19 [ 0 ] -> V_20 , V_108 , V_109 , V_110 ) ;
break;
}
case V_118 : {
V_15 = F_52 ( exp , V_108 , V_109 , V_110 ) ;
break;
}
case V_190 :
case V_191 :
case V_192 : {
struct V_193 * V_194 = V_109 ;
struct V_3 * V_4 ;
V_4 = F_53 ( V_2 , & V_194 -> V_195 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
if ( V_4 -> V_20 == NULL )
return - V_24 ;
V_15 = F_56 ( V_143 , V_4 -> V_20 , V_108 , V_109 , V_110 ) ;
break;
}
case V_196 : {
const struct V_197 * V_198 = V_109 ;
struct V_3 * V_4 ;
V_4 = F_53 ( V_2 , & V_198 -> V_199 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_15 = F_56 ( V_143 , V_4 -> V_20 , V_108 , V_109 , V_110 ) ;
break;
}
case V_200 : {
struct V_130 * V_131 = V_109 ;
struct V_3 * V_4 ;
unsigned int V_201 = V_131 -> V_135 . V_136 ;
if ( V_201 == 0 )
return 0 ;
if ( V_201 == 1 || V_159 == 1 ) {
V_4 = F_53 ( V_2 ,
& V_131 -> V_137 [ 0 ] . V_138 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_15 = F_56 ( V_143 , V_4 -> V_20 , V_108 , V_109 , V_110 ) ;
} else {
for ( V_14 = 0 ; V_14 < V_159 ; V_14 ++ ) {
unsigned int V_133 , V_202 ;
int V_203 ;
struct V_130 * V_204 ;
V_133 = F_59 ( V_2 , V_131 , V_2 -> V_19 [ V_14 ] ) ;
if ( V_133 == 0 )
continue;
V_202 = F_74 ( F_75 ( * V_131 ) ,
V_137 [ V_133 ] )
+ V_131 -> V_135 . V_142 ;
V_204 = F_76 ( V_202 , V_97 ) ;
if ( V_204 == NULL )
return - V_98 ;
F_60 ( V_2 , V_131 , V_2 -> V_19 [ V_14 ] , V_204 ) ;
V_203 = F_56 ( V_143 , V_2 -> V_19 [ V_14 ] -> V_20 ,
V_202 , V_204 , V_110 ) ;
if ( V_203 != 0 && V_15 == 0 )
V_15 = V_203 ;
F_77 ( V_204 ) ;
}
}
break;
}
case V_205 : {
struct V_193 * V_194 = V_109 ;
struct V_3 * V_206 , * V_207 ;
V_206 = F_53 ( V_2 , & V_194 -> V_195 ) ;
if ( F_54 ( V_206 ) )
return F_55 ( V_206 ) ;
V_207 = F_53 ( V_2 , & V_194 -> V_208 ) ;
if ( F_54 ( V_207 ) )
return F_55 ( V_207 ) ;
if ( ( V_206 -> V_20 == NULL ) || ( V_207 -> V_20 == NULL ) )
return - V_24 ;
if ( V_206 -> V_85 != V_207 -> V_85 )
return - V_209 ;
V_15 = F_56 ( V_143 , V_206 -> V_20 , V_108 , V_109 , V_110 ) ;
break;
}
case V_210 : {
struct V_144 * V_145 = V_109 ;
if ( V_145 -> V_153 & V_154 )
V_15 = F_62 ( V_2 , V_143 , V_108 , V_145 , V_110 ) ;
else
V_15 = F_64 ( V_2 , V_143 , V_108 , V_145 , V_110 ) ;
break;
}
default:
for ( V_14 = 0 ; V_14 < V_159 ; V_14 ++ ) {
struct V_12 * V_75 ;
int V_151 ;
if ( V_2 -> V_19 [ V_14 ] == NULL ||
V_2 -> V_19 [ V_14 ] -> V_20 == NULL )
continue;
V_75 = F_6 ( V_2 -> V_19 [ V_14 ] -> V_20 ) ;
V_75 -> V_104 = V_111 -> V_104 ;
V_151 = F_56 ( V_143 , V_2 -> V_19 [ V_14 ] -> V_20 , V_108 ,
V_109 , V_110 ) ;
if ( V_151 == - V_167 && V_143 == V_211 ) {
return V_151 ;
} else if ( V_151 ) {
if ( V_2 -> V_19 [ V_14 ] -> V_6 ) {
F_12 ( L_36 ,
V_2 -> V_19 [ V_14 ] -> V_21 . V_10 ,
V_14 , V_143 , V_151 ) ;
if ( ! V_15 )
V_15 = V_151 ;
}
} else
V_158 = 1 ;
}
if ( ! V_158 && ! V_15 )
V_15 = - V_212 ;
}
return V_15 ;
}
static int F_78 ( struct V_12 * V_13 ,
struct V_193 * V_194 , T_2 * V_213 )
{
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
F_7 ( V_213 != NULL ) ;
if ( V_2 -> V_7 . V_18 == 1 ) {
* V_213 = 0 ;
return 0 ;
}
if ( V_194 -> V_214 & V_215 ) {
struct V_216 * V_217 ;
V_217 = (struct V_216 * ) V_194 -> V_194 ;
if ( V_217 -> V_218 == V_219 &&
V_217 -> V_220 != - 1 ) {
if ( V_217 -> V_220 >= V_2 -> V_7 . V_18 ) {
F_12 ( L_37 ,
V_13 -> V_27 ,
V_217 -> V_220 ,
V_2 -> V_7 . V_18 , - V_221 ) ;
return - V_221 ;
}
* V_213 = V_217 -> V_220 ;
return 0 ;
}
}
* V_213 = V_194 -> V_222 ;
return 0 ;
}
int F_79 ( struct V_1 * V_2 , struct V_101 * V_223 , T_2 V_213 )
{
struct V_3 * V_4 ;
int V_15 ;
V_4 = F_80 ( V_2 , V_213 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
F_81 ( & V_4 -> V_99 ) ;
if ( V_4 -> V_6 == 0 || V_4 -> V_20 == NULL ) {
V_15 = - V_166 ;
goto V_224;
}
V_15 = F_82 ( V_4 -> V_20 , V_223 , NULL ) ;
if ( V_15 > 0 ) {
F_7 ( F_58 ( V_223 ) ) ;
V_15 = 0 ;
}
V_224:
F_83 ( & V_4 -> V_99 ) ;
return V_15 ;
}
int F_84 ( struct V_32 * exp , struct V_101 * V_223 ,
struct V_193 * V_194 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
T_2 V_213 = 0 ;
int V_15 ;
F_7 ( V_194 != NULL ) ;
F_7 ( V_223 != NULL ) ;
V_15 = F_78 ( V_13 , V_194 , & V_213 ) ;
if ( V_15 ) {
F_12 ( L_38 ,
V_15 ) ;
return V_15 ;
}
V_15 = F_79 ( V_2 , V_223 , V_213 ) ;
if ( V_15 ) {
F_12 ( L_39 , V_15 ) ;
return V_15 ;
}
return V_15 ;
}
static int F_85 ( struct V_12 * V_13 , struct V_225 * V_226 )
{
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_227 V_228 = { NULL } ;
struct V_229 * V_7 ;
int V_15 ;
if ( F_86 ( V_226 , 1 ) < 1 ) {
F_12 ( L_40 ) ;
return - V_24 ;
}
V_7 = (struct V_229 * ) F_87 ( V_226 , 1 ) ;
if ( sizeof( * V_7 ) > F_86 ( V_226 , 1 ) ) {
F_12 ( L_41 ,
( int ) sizeof( * V_7 ) , F_86 ( V_226 , 1 ) ) ;
return - V_24 ;
}
V_2 -> V_19 = F_41 ( 32 , sizeof( * V_2 -> V_19 ) , V_97 ) ;
if ( V_2 -> V_19 == NULL )
return - V_98 ;
V_2 -> V_91 = 32 ;
F_88 ( & V_2 -> V_7 . V_230 , V_7 -> V_230 . V_10 ) ;
V_2 -> V_7 . V_18 = 0 ;
V_2 -> V_7 . V_8 = 0 ;
V_2 -> V_72 = 0 ;
V_2 -> V_71 = 0 ;
V_2 -> V_70 = 0 ;
V_2 -> V_231 = V_232 ;
F_89 ( & V_2 -> V_17 ) ;
F_44 ( & V_2 -> V_233 ) ;
F_90 ( & V_228 ) ;
F_91 ( V_13 , V_228 . V_234 , V_228 . V_235 ) ;
V_15 = F_92 ( V_13 -> V_236 , L_42 ,
0444 , & V_237 , V_13 ) ;
if ( V_15 )
F_24 ( L_43 ,
V_13 -> V_27 , V_15 ) ;
V_15 = F_93 ( & V_2 -> V_86 , V_13 -> V_27 ,
V_238 ) ;
if ( V_15 ) {
F_12 ( L_44 , V_15 ) ;
goto V_224;
}
return 0 ;
V_224:
return V_15 ;
}
static int F_94 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
F_95 ( & V_2 -> V_86 ) ;
if ( V_2 -> V_19 != NULL ) {
int V_14 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL )
continue;
F_35 ( V_2 , V_14 ) ;
}
F_36 ( V_2 -> V_19 ) ;
V_2 -> V_91 = 0 ;
}
return 0 ;
}
static int F_96 ( struct V_12 * V_13 , T_2 V_108 , void * V_239 )
{
struct V_225 * V_226 = V_239 ;
struct V_9 V_9 ;
int V_90 ;
T_1 V_88 ;
int V_15 ;
switch ( V_226 -> V_240 ) {
case V_241 :
if ( F_86 ( V_226 , 1 ) > sizeof( V_9 . V_10 ) ) {
V_15 = - V_24 ;
goto V_224;
}
F_88 ( & V_9 , F_87 ( V_226 , 1 ) ) ;
if ( sscanf ( F_87 ( V_226 , 2 ) , L_45 , & V_88 ) != 1 ) {
V_15 = - V_24 ;
goto V_224;
}
if ( sscanf ( F_87 ( V_226 , 3 ) , L_45 , & V_90 ) != 1 ) {
V_15 = - V_24 ;
goto V_224;
}
V_15 = F_37 ( V_13 , & V_9 , V_88 , V_90 ) ;
goto V_224;
default:
F_12 ( L_46 , V_226 -> V_240 ) ;
V_15 = - V_24 ;
goto V_224;
}
V_224:
return V_15 ;
}
static int F_97 ( const struct V_51 * V_52 , struct V_32 * exp ,
struct V_163 * V_242 , T_3 V_243 , T_1 V_244 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_163 * V_245 ;
int V_15 = 0 ;
int V_14 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_245 = F_43 ( sizeof( * V_245 ) , V_97 ) ;
if ( V_245 == NULL )
return - V_98 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL || V_2 -> V_19 [ V_14 ] -> V_20 == NULL )
continue;
V_15 = V_163 ( V_52 , V_2 -> V_19 [ V_14 ] -> V_20 , V_245 ,
V_243 , V_244 ) ;
if ( V_15 ) {
F_12 ( L_47 , V_14 ,
V_2 -> V_19 [ V_14 ] -> V_20 -> V_33 -> V_27 ,
V_15 ) ;
goto V_246;
}
if ( V_14 == 0 ) {
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
F_36 ( V_245 ) ;
return V_15 ;
}
static int F_98 ( struct V_32 * exp ,
struct V_101 * V_223 ,
struct V_252 * * V_253 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_99 ( V_2 -> V_19 [ 0 ] -> V_20 , V_223 , V_253 ) ;
return V_15 ;
}
static int F_100 ( struct V_32 * exp , const struct V_101 * V_223 ,
struct V_252 * V_254 , T_4 V_255 , const char * V_256 ,
const char * V_257 , int V_258 , int V_259 ,
int V_244 , struct V_260 * * V_261 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_53 ( V_2 , V_223 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_15 = F_101 ( V_4 -> V_20 , V_223 , V_254 , V_255 , V_256 , V_257 ,
V_258 , V_259 , V_244 , V_261 ) ;
return V_15 ;
}
static int F_102 ( struct V_32 * exp , const struct V_101 * V_223 ,
struct V_252 * V_254 , T_4 V_255 , const char * V_256 ,
const char * V_257 , int V_258 , int V_259 ,
int V_244 , T_1 V_262 ,
struct V_260 * * V_261 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_53 ( V_2 , V_223 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_15 = F_103 ( V_4 -> V_20 , V_223 , V_254 , V_255 , V_256 , V_257 ,
V_258 , V_259 , V_244 , V_262 ,
V_261 ) ;
return V_15 ;
}
static int F_104 ( struct V_32 * exp , struct V_193 * V_194 ,
struct V_260 * * V_261 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_53 ( V_2 , & V_194 -> V_195 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
if ( V_194 -> V_263 & V_264 ) {
V_194 -> V_222 = V_4 -> V_85 ;
return 0 ;
}
V_15 = F_105 ( V_4 -> V_20 , V_194 , V_261 ) ;
return V_15 ;
}
static int F_106 ( struct V_32 * exp , const struct V_101 * V_223 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
int V_14 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_265 , L_48 V_126 L_49 , F_57 ( V_223 ) ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL || V_2 -> V_19 [ V_14 ] -> V_20 == NULL )
continue;
F_107 ( V_2 -> V_19 [ V_14 ] -> V_20 , V_223 ) ;
}
return 0 ;
}
static int F_108 ( struct V_32 * exp , const struct V_101 * V_223 ,
T_5 V_266 , void * V_38 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
int V_14 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_265 , L_48 V_126 L_49 , F_57 ( V_223 ) ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL || V_2 -> V_19 [ V_14 ] -> V_20 == NULL )
continue;
V_15 = F_109 ( V_2 -> V_19 [ V_14 ] -> V_20 , V_223 , V_266 , V_38 ) ;
if ( V_15 )
return V_15 ;
}
return V_15 ;
}
static int F_110 ( struct V_32 * exp , struct V_193 * V_194 ,
struct V_267 * V_268 , struct V_260 * * V_261 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_53 ( V_2 , & V_194 -> V_195 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
F_3 ( V_265 , L_50 V_126 L_49 , F_57 ( & V_194 -> V_195 ) ) ;
V_15 = F_111 ( V_4 -> V_20 , V_194 , V_268 , V_261 ) ;
return V_15 ;
}
struct V_3
* F_112 ( struct V_1 * V_2 , struct V_193 * V_194 ,
struct V_101 * V_223 )
{
struct V_3 * V_4 ;
V_4 = F_53 ( V_2 , V_223 ) ;
if ( F_54 ( V_4 ) )
return V_4 ;
V_194 -> V_222 = V_4 -> V_85 ;
return V_4 ;
}
static int F_113 ( struct V_32 * exp , struct V_193 * V_194 ,
const void * V_38 , int V_269 , int V_270 , T_1 V_271 ,
T_1 V_272 , T_6 V_273 , T_3 V_274 ,
struct V_260 * * V_261 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
if ( ! V_2 -> V_7 . V_8 )
return - V_212 ;
V_4 = F_112 ( V_2 , V_194 , & V_194 -> V_195 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_15 = F_84 ( exp , & V_194 -> V_208 , V_194 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_265 , L_51 V_126 L_52 ,
V_194 -> V_275 , V_194 -> V_276 , F_57 ( & V_194 -> V_195 ) ,
V_194 -> V_222 ) ;
V_194 -> V_263 |= V_277 ;
V_15 = F_114 ( V_4 -> V_20 , V_194 , V_38 , V_269 , V_270 , V_271 , V_272 ,
V_273 , V_274 , V_261 ) ;
if ( V_15 == 0 ) {
if ( * V_261 == NULL )
return V_15 ;
F_3 ( V_265 , L_53 V_126 L_49 , F_57 ( & V_194 -> V_208 ) ) ;
}
return V_15 ;
}
static int F_115 ( struct V_32 * exp ,
struct V_193 * V_194 ,
struct V_267 * V_268 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_53 ( V_2 , & V_194 -> V_195 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_15 = F_116 ( V_4 -> V_20 , V_194 , V_268 ) ;
return V_15 ;
}
static int
F_117 ( struct V_32 * exp , struct V_278 * V_279 ,
struct V_280 * V_266 , struct V_193 * V_194 ,
struct V_55 * V_281 , void * V_282 , int V_283 ,
T_3 V_284 )
{
struct V_260 * V_204 = V_266 -> V_285 . V_286 . V_287 ;
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_55 V_288 ;
struct V_3 * V_4 ;
struct V_193 * V_289 ;
struct V_101 V_290 ;
struct V_291 * V_292 ;
int V_15 = 0 ;
int V_293 ;
V_292 = F_118 ( & V_204 -> V_294 , & V_295 ) ;
F_7 ( V_292 != NULL ) ;
if ( ! ( V_292 -> V_255 & V_296 ) )
return 0 ;
F_3 ( V_265 , L_54 V_126 L_55 V_126 L_49 ,
F_119 ( V_266 ) , F_57 ( & V_194 -> V_195 ) , F_57 ( & V_292 -> V_290 ) ) ;
V_293 = V_266 -> V_285 . V_286 . V_297 ;
F_7 ( V_293 != 0 ) ;
memcpy ( & V_288 , V_281 , sizeof( V_288 ) ) ;
V_266 -> V_285 . V_286 . V_297 = 0 ;
V_266 -> V_285 . V_286 . V_287 = NULL ;
V_290 = V_292 -> V_290 ;
F_120 ( V_204 ) ;
V_4 = F_53 ( V_2 , & V_290 ) ;
if ( F_54 ( V_4 ) ) {
V_15 = F_55 ( V_4 ) ;
goto V_224;
}
V_289 = F_43 ( sizeof( * V_289 ) , V_97 ) ;
if ( V_289 == NULL ) {
V_15 = - V_98 ;
goto V_224;
}
V_289 -> V_195 = V_290 ;
V_289 -> V_298 = V_299 ;
V_15 = F_121 ( V_4 -> V_20 , V_279 , V_266 , V_289 , V_281 ,
V_282 , V_283 , NULL , V_284 ) ;
F_36 ( V_289 ) ;
V_224:
F_122 ( & V_288 , V_293 ) ;
return V_15 ;
}
static int
F_123 ( struct V_32 * exp , struct V_278 * V_279 ,
struct V_280 * V_266 , struct V_193 * V_194 ,
struct V_55 * V_281 , void * V_282 , int V_283 ,
struct V_260 * * V_204 , T_3 V_284 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_265 , L_56 V_126 L_49 ,
F_119 ( V_266 ) , F_57 ( & V_194 -> V_195 ) ) ;
V_4 = F_112 ( V_2 , V_194 , & V_194 -> V_195 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
F_3 ( V_265 , L_56 V_126 L_57 ,
F_119 ( V_266 ) , F_57 ( & V_194 -> V_195 ) , V_4 -> V_85 ) ;
V_15 = F_121 ( V_4 -> V_20 , V_279 , V_266 , V_194 , V_281 ,
V_282 , V_283 , V_204 , V_284 ) ;
if ( V_15 == 0 && V_266 && V_266 -> V_300 == V_301 ) {
V_15 = F_117 ( exp , V_279 , V_266 , V_194 , V_281 ,
V_282 , V_283 , V_284 ) ;
}
return V_15 ;
}
static int
F_124 ( struct V_32 * exp , struct V_193 * V_194 ,
struct V_260 * * V_261 )
{
struct V_260 * V_204 = NULL ;
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
struct V_291 * V_292 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_112 ( V_2 , V_194 , & V_194 -> V_195 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
F_3 ( V_265 , L_58 V_126 L_57 ,
V_194 -> V_275 , V_194 -> V_276 , F_57 ( & V_194 -> V_195 ) ,
V_4 -> V_85 ) ;
V_15 = F_125 ( V_4 -> V_20 , V_194 , V_261 ) ;
if ( V_15 != 0 )
return V_15 ;
V_292 = F_118 ( & ( * V_261 ) -> V_294 ,
& V_295 ) ;
F_7 ( V_292 != NULL ) ;
if ( V_292 -> V_255 & V_296 ) {
struct V_101 V_302 = V_292 -> V_290 ;
F_3 ( V_265 , L_59 V_126 L_49 ,
F_57 ( & V_302 ) ) ;
V_4 = F_53 ( V_2 , & V_302 ) ;
if ( F_54 ( V_4 ) ) {
F_120 ( * V_261 ) ;
return F_55 ( V_4 ) ;
}
V_194 -> V_195 = V_302 ;
V_194 -> V_303 |= V_304 ;
V_194 -> V_275 = 0 ;
V_194 -> V_276 = NULL ;
V_15 = F_125 ( V_4 -> V_20 , V_194 , & V_204 ) ;
F_120 ( * V_261 ) ;
* V_261 = V_204 ;
}
return V_15 ;
}
static int F_126 ( struct V_32 * exp , struct V_193 * V_194 ,
int V_305 , T_7 V_270 , int V_306 , int V_307 )
{
struct V_101 * V_223 = F_127 ( V_194 , V_307 ) ;
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
T_8 V_308 = { { 0 } } ;
int V_15 = 0 ;
if ( ! F_58 ( V_223 ) )
return 0 ;
V_4 = F_53 ( V_2 , V_223 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
if ( V_4 -> V_85 != V_305 ) {
F_3 ( V_265 , L_60 V_126 L_49 , F_57 ( V_223 ) ) ;
V_308 . V_309 . V_306 = V_306 ;
V_15 = F_128 ( V_4 -> V_20 , V_223 , & V_308 ,
V_270 , V_310 , NULL ) ;
} else {
F_3 ( V_265 ,
L_61 V_126 L_49 ,
V_305 , F_57 ( V_223 ) ) ;
V_194 -> V_263 |= V_307 ;
V_15 = 0 ;
}
return V_15 ;
}
static int F_129 ( struct V_32 * exp , struct V_193 * V_194 ,
struct V_260 * * V_261 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_7 ( V_194 -> V_275 != 0 ) ;
F_3 ( V_265 , L_62 V_126 L_63 V_126 L_49 ,
F_57 ( & V_194 -> V_208 ) , V_194 -> V_275 ,
V_194 -> V_276 , F_57 ( & V_194 -> V_195 ) ) ;
V_194 -> V_311 = F_130 ( & V_312 , F_131 () ) ;
V_194 -> V_313 = F_132 ( & V_312 , F_133 () ) ;
V_194 -> V_314 = F_134 () ;
V_4 = F_112 ( V_2 , V_194 , & V_194 -> V_208 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_194 -> V_263 |= V_315 ;
V_15 = F_126 ( exp , V_194 , V_4 -> V_85 , V_316 ,
V_317 , V_277 ) ;
if ( V_15 != 0 )
return V_15 ;
V_15 = F_135 ( V_4 -> V_20 , V_194 , V_261 ) ;
return V_15 ;
}
static int F_136 ( struct V_32 * exp , struct V_193 * V_194 ,
const char * V_94 , int V_318 , const char * V_319 , int V_320 ,
struct V_260 * * V_261 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_321 ;
struct V_3 * V_322 ;
int V_15 ;
F_7 ( V_318 != 0 ) ;
F_3 ( V_265 , L_64 V_126 L_65 V_126 L_49 ,
V_318 , V_94 , F_57 ( & V_194 -> V_195 ) ,
V_320 , V_319 , F_57 ( & V_194 -> V_208 ) ) ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_194 -> V_311 = F_130 ( & V_312 , F_131 () ) ;
V_194 -> V_313 = F_132 ( & V_312 , F_133 () ) ;
V_194 -> V_314 = F_134 () ;
V_321 = F_112 ( V_2 , V_194 , & V_194 -> V_195 ) ;
if ( F_54 ( V_321 ) )
return F_55 ( V_321 ) ;
V_322 = F_112 ( V_2 , V_194 , & V_194 -> V_208 ) ;
if ( F_54 ( V_322 ) )
return F_55 ( V_322 ) ;
V_194 -> V_263 |= V_277 | V_323 ;
V_15 = F_126 ( exp , V_194 , V_321 -> V_85 ,
V_316 , V_317 ,
V_315 ) ;
if ( V_15 == 0 ) {
V_15 = F_126 ( exp , V_194 , V_321 -> V_85 ,
V_316 , V_324 ,
V_325 ) ;
}
if ( V_15 == 0 )
V_15 = F_126 ( exp , V_194 , V_321 -> V_85 ,
V_316 , V_326 ,
V_325 ) ;
if ( V_15 == 0 )
V_15 = F_137 ( V_321 -> V_20 , V_194 , V_94 , V_318 ,
V_319 , V_320 , V_261 ) ;
return V_15 ;
}
static int F_138 ( struct V_32 * exp , struct V_193 * V_194 ,
void * V_327 , int V_328 , void * V_329 , int V_330 ,
struct V_260 * * V_261 ,
struct V_267 * * V_268 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 = 0 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_265 , L_66 V_126 L_67 ,
F_57 ( & V_194 -> V_195 ) , V_194 -> V_331 . V_332 ) ;
V_194 -> V_263 |= V_277 ;
V_4 = F_53 ( V_2 , & V_194 -> V_195 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_15 = F_139 ( V_4 -> V_20 , V_194 , V_327 , V_328 , V_329 ,
V_330 , V_261 , V_268 ) ;
return V_15 ;
}
static int F_140 ( struct V_32 * exp , const struct V_101 * V_223 ,
struct V_252 * V_254 , struct V_260 * * V_261 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_53 ( V_2 , V_223 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_15 = F_141 ( V_4 -> V_20 , V_223 , V_254 , V_261 ) ;
return V_15 ;
}
static void F_142 ( struct V_333 * * V_334 , int V_335 , int V_336 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_335 ; V_14 ++ ) {
struct V_337 * V_338 = F_143 ( V_334 [ V_14 ] ) ;
struct V_337 * V_339 = V_338 ;
struct V_340 * V_341 = NULL ;
struct V_340 * V_342 ;
T_3 V_343 = V_338 -> V_344 ;
T_1 V_244 = V_338 -> V_345 ;
while ( -- V_336 > 0 ) {
V_342 = F_144 ( V_338 ) ;
for ( V_341 = V_342 ; V_342 != NULL ;
V_341 = V_342 , V_342 = F_145 ( V_342 ) ) ;
V_338 = (struct V_337 * ) ( ( char * ) V_338 + V_346 ) ;
if ( ! ( ( unsigned long ) V_338 & ~ V_347 ) )
break;
V_343 = V_338 -> V_344 ;
V_244 = V_338 -> V_345 ;
if ( ! V_341 )
break;
F_7 ( F_146 ( V_341 -> V_348 ) == 0 ) ;
V_341 -> V_348 =
F_147 ( ( char * ) ( V_338 -> V_349 ) -
( char * ) V_341 ) ;
}
V_339 -> V_344 = V_343 ;
V_339 -> V_345 &= ~ F_148 ( V_350 ) ;
V_339 -> V_345 |= V_244 & F_148 ( V_350 ) ;
F_149 ( V_334 [ V_14 ] ) ;
}
F_150 ( V_336 == 0 , L_68 , V_336 ) ;
}
static int F_151 ( struct V_32 * exp , struct V_193 * V_194 ,
struct V_333 * * V_334 , struct V_260 * * V_261 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
T_3 V_351 = V_194 -> V_352 ;
int V_15 ;
int V_335 ;
int V_336 ;
struct V_3 * V_4 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_265 , L_69 V_126 L_49 ,
V_351 , F_57 ( & V_194 -> V_195 ) ) ;
V_4 = F_53 ( V_2 , & V_194 -> V_195 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_15 = F_152 ( V_4 -> V_20 , V_194 , V_334 , V_261 ) ;
if ( V_15 != 0 )
return V_15 ;
V_335 = ( ( * V_261 ) -> V_353 -> V_354 + V_355 - 1 )
>> V_356 ;
V_336 = ( * V_261 ) -> V_353 -> V_354 >> V_357 ;
F_7 ( ! ( ( * V_261 ) -> V_353 -> V_354 & ~ V_358 ) ) ;
F_7 ( V_335 > 0 && V_335 <= V_194 -> V_359 ) ;
F_3 ( V_265 , L_70 , V_335 , V_336 ,
V_194 -> V_359 ) ;
F_142 ( V_334 , V_335 , V_336 ) ;
return V_15 ;
}
static int F_153 ( struct V_32 * exp , struct V_193 * V_194 ,
struct V_260 * * V_261 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 = NULL ;
struct V_291 * V_292 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_360:
if ( F_154 ( ! F_155 ( & V_194 -> V_208 ) ) )
V_4 = F_112 ( V_2 , V_194 , & V_194 -> V_208 ) ;
else
V_4 = F_112 ( V_2 , V_194 , & V_194 -> V_195 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_194 -> V_311 = F_130 ( & V_312 , F_131 () ) ;
V_194 -> V_313 = F_132 ( & V_312 , F_133 () ) ;
V_194 -> V_314 = F_134 () ;
V_194 -> V_263 |= V_277 | V_323 ;
V_15 = F_126 ( exp , V_194 , V_4 -> V_85 , V_316 ,
V_326 , V_323 ) ;
if ( V_15 != 0 )
return V_15 ;
F_3 ( V_265 , L_71 V_126 L_72 V_126 L_57 ,
F_57 ( & V_194 -> V_195 ) , F_57 ( & V_194 -> V_208 ) , V_4 -> V_85 ) ;
V_15 = F_156 ( V_4 -> V_20 , V_194 , V_261 ) ;
if ( V_15 != 0 && V_15 != - V_119 )
return V_15 ;
V_292 = F_118 ( & ( * V_261 ) -> V_294 , & V_295 ) ;
if ( V_292 == NULL )
return - V_361 ;
if ( F_154 ( ! ( V_292 -> V_255 & V_296 ) ) )
return 0 ;
F_3 ( V_265 , L_73 V_126 L_49 ,
exp -> V_33 -> V_27 , F_57 ( & V_292 -> V_290 ) ) ;
V_194 -> V_208 = V_292 -> V_290 ;
F_120 ( * V_261 ) ;
* V_261 = NULL ;
goto V_360;
}
static int F_157 ( struct V_12 * V_13 , enum V_362 V_363 )
{
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
switch ( V_363 ) {
case V_364 :
break;
case V_365 :
F_158 ( & V_2 -> V_86 ) ;
F_159 ( V_13 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_160 ( const struct V_51 * V_52 , struct V_32 * exp ,
T_1 V_366 , void * V_367 , T_1 * V_368 , void * V_369 ,
struct V_370 * V_371 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
int V_15 = 0 ;
V_13 = F_6 ( exp ) ;
if ( V_13 == NULL ) {
F_3 ( V_372 , L_74 ,
exp -> V_22 . V_23 ) ;
return - V_24 ;
}
V_2 = & V_13 -> V_34 . V_2 ;
if ( V_366 >= strlen ( L_75 ) && ! strcmp ( V_367 , L_75 ) ) {
struct V_3 * V_4 ;
int V_14 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_7 ( * V_368 == sizeof( T_1 ) ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL || V_4 -> V_20 == NULL )
continue;
if ( ! F_161 ( V_52 , V_4 -> V_20 , V_366 , V_367 ,
V_368 , V_369 , NULL ) )
return 0 ;
}
return - V_24 ;
} else if ( F_162 ( V_373 ) ||
F_162 ( V_374 ) ||
F_162 ( V_375 ) ||
F_162 ( V_376 ) ||
F_162 ( V_377 ) ) {
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_161 ( V_52 , V_2 -> V_19 [ 0 ] -> V_20 , V_366 , V_367 ,
V_368 , V_369 , NULL ) ;
if ( ! V_15 && F_162 ( V_377 ) )
exp -> V_49 = * (struct V_39 * ) V_369 ;
return V_15 ;
} else if ( F_162 ( V_378 ) ) {
* ( ( int * ) V_369 ) = V_2 -> V_7 . V_18 ;
return 0 ;
}
F_3 ( V_372 , L_76 ) ;
return - V_24 ;
}
static int F_163 ( const struct V_51 * V_52 , struct V_32 * exp ,
T_2 V_366 , void * V_367 , T_2 V_368 ,
void * V_369 , struct V_379 * V_158 )
{
struct V_3 * V_4 ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
int V_15 = 0 ;
V_13 = F_6 ( exp ) ;
if ( V_13 == NULL ) {
F_3 ( V_372 , L_74 ,
exp -> V_22 . V_23 ) ;
return - V_24 ;
}
V_2 = & V_13 -> V_34 . V_2 ;
if ( F_162 ( V_380 ) || F_162 ( V_381 ) ) {
int V_14 , V_151 = 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL || V_4 -> V_20 == NULL )
continue;
V_151 = F_22 ( V_52 , V_4 -> V_20 ,
V_366 , V_367 , V_368 , V_369 , V_158 ) ;
if ( V_151 && V_15 == 0 )
V_15 = V_151 ;
}
return V_15 ;
}
return - V_24 ;
}
static int F_164 ( struct V_32 * exp , struct V_382 * * V_383 ,
struct V_370 * V_371 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_100 * V_384 ;
struct V_100 * V_385 ;
int V_386 ;
int V_14 ;
V_386 = F_46 ( V_2 ) ;
if ( ! V_383 )
return V_386 ;
if ( * V_383 && ! V_371 ) {
F_77 ( * V_383 ) ;
* V_383 = NULL ;
return 0 ;
}
if ( * V_383 == NULL ) {
* V_383 = F_76 ( V_386 , V_97 ) ;
if ( * V_383 == NULL )
return - V_98 ;
}
if ( ! V_371 )
return V_386 ;
V_385 = (struct V_100 * ) V_371 ;
V_384 = (struct V_100 * ) * V_383 ;
if ( V_385 -> V_387 != V_388 &&
V_385 -> V_387 != V_389 )
return - V_24 ;
V_384 -> V_387 = F_148 ( V_385 -> V_387 ) ;
V_384 -> V_390 = F_148 ( V_385 -> V_390 ) ;
V_384 -> V_391 = F_148 ( V_385 -> V_391 ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_384 -> V_392 [ V_14 ] = V_385 -> V_392 [ V_14 ] ;
F_165 ( & V_384 -> V_392 [ V_14 ] , & V_385 -> V_392 [ V_14 ] ) ;
}
return V_386 ;
}
static int F_166 ( struct V_32 * exp , struct V_370 * * V_385 ,
struct V_382 * V_282 , int V_393 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_100 * * V_394 = (struct V_100 * * ) V_385 ;
struct V_100 * V_395 = (struct V_100 * ) V_282 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
int V_386 ;
int V_14 ;
T_1 V_396 ;
V_386 = F_46 ( V_2 ) ;
if ( V_385 == NULL )
return V_386 ;
if ( * V_385 != NULL && V_282 == NULL ) {
F_77 ( * V_394 ) ;
* V_385 = NULL ;
return 0 ;
}
F_7 ( V_386 == V_393 ) ;
* V_394 = F_76 ( V_386 , V_97 ) ;
if ( * V_394 == NULL )
return - V_98 ;
if ( ! V_282 )
return V_386 ;
if ( V_395 -> V_387 == V_388 ||
V_395 -> V_387 == V_389 ||
V_395 -> V_387 == V_397 ) {
V_396 = F_167 ( V_395 -> V_387 ) ;
} else {
F_12 ( L_77 ) ;
F_168 () ;
}
( * V_394 ) -> V_387 = V_396 ;
( * V_394 ) -> V_390 = F_167 ( V_395 -> V_390 ) ;
( * V_394 ) -> V_391 = F_167 ( V_395 -> V_391 ) ;
for ( V_14 = 0 ; V_14 < ( * V_394 ) -> V_390 ; V_14 ++ ) {
( * V_394 ) -> V_392 [ V_14 ] = V_395 -> V_392 [ V_14 ] ;
F_169 ( & ( * V_394 ) -> V_392 [ V_14 ] , & ( * V_394 ) -> V_392 [ V_14 ] ) ;
}
return V_386 ;
}
static int F_170 ( struct V_32 * exp , const struct V_101 * V_223 ,
T_8 * V_308 , T_7 V_270 ,
T_9 V_244 , void * V_398 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
int V_15 = 0 ;
int V_151 ;
int V_14 ;
F_7 ( V_223 != NULL ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL || V_2 -> V_19 [ V_14 ] -> V_20 == NULL ||
V_2 -> V_19 [ V_14 ] -> V_6 == 0 )
continue;
V_151 = F_128 ( V_2 -> V_19 [ V_14 ] -> V_20 , V_223 ,
V_308 , V_270 , V_244 , V_398 ) ;
if ( ! V_15 )
V_15 = V_151 ;
}
return V_15 ;
}
static int F_171 ( struct V_32 * exp , T_3 * V_281 , void * V_38 ,
T_3 * V_306 )
{
struct V_1 * V_2 = & exp -> V_33 -> V_34 . V_2 ;
int V_15 ;
V_15 = F_172 ( V_2 -> V_19 [ 0 ] -> V_20 , V_281 , V_38 , V_306 ) ;
return V_15 ;
}
static T_7 F_173 ( struct V_32 * exp , T_3 V_244 ,
const struct V_101 * V_223 , T_10 type ,
T_8 * V_308 , T_7 V_270 ,
struct V_55 * V_281 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
T_7 V_15 ;
int V_14 ;
F_3 ( V_265 , L_78 V_126 L_49 , F_57 ( V_223 ) ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( V_2 -> V_19 [ V_14 ] == NULL ||
V_2 -> V_19 [ V_14 ] -> V_20 == NULL ||
V_2 -> V_19 [ V_14 ] -> V_6 == 0 )
continue;
V_15 = F_174 ( V_2 -> V_19 [ V_14 ] -> V_20 , V_244 , V_223 ,
type , V_308 , V_270 , V_281 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static int F_175 ( struct V_32 * exp ,
struct V_260 * V_204 ,
struct V_32 * V_399 ,
struct V_32 * V_400 ,
struct V_401 * V_402 )
{
struct V_1 * V_2 = & exp -> V_33 -> V_34 . V_2 ;
return F_176 ( V_2 -> V_19 [ 0 ] -> V_20 , V_204 , V_399 , V_400 , V_402 ) ;
}
static int F_177 ( struct V_32 * exp , struct V_401 * V_402 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
if ( V_402 -> V_395 )
F_178 ( exp , ( void * ) & V_402 -> V_395 ) ;
return F_179 ( V_2 -> V_19 [ 0 ] -> V_20 , V_402 ) ;
}
static int F_180 ( struct V_32 * exp ,
struct V_403 * V_404 ,
struct V_280 * V_266 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
V_4 = F_53 ( V_2 , & V_404 -> V_405 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
return F_181 ( V_4 -> V_20 , V_404 , V_266 ) ;
}
static int F_182 ( struct V_32 * exp ,
struct V_403 * V_404 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
V_4 = F_53 ( V_2 , & V_404 -> V_405 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
return F_183 ( V_4 -> V_20 , V_404 ) ;
}
static int F_184 ( struct V_32 * exp ,
const struct V_101 * V_223 ,
struct V_252 * V_254 , T_1 V_262 ,
struct V_260 * * V_261 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_53 ( V_2 , V_223 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_15 = F_185 ( V_4 -> V_20 , V_223 , V_254 , V_262 , V_261 ) ;
return V_15 ;
}
static int F_186 ( struct V_32 * exp , struct V_252 * V_254 ,
T_11 V_406 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_53 ( V_2 , & V_254 -> V_407 . V_408 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_15 = F_187 ( V_4 -> V_20 , V_254 , V_406 ) ;
return V_15 ;
}
static int F_188 ( struct V_32 * exp , struct V_260 * V_204 ,
const struct V_409 * V_410 ,
struct V_252 * * V_254 )
{
struct V_1 * V_2 = & exp -> V_33 -> V_34 . V_2 ;
return F_189 ( V_2 -> V_19 [ 0 ] -> V_20 , V_204 , V_410 , V_254 ) ;
}
static int F_190 ( struct V_32 * exp ,
struct V_411 * V_412 ,
struct V_278 * V_279 )
{
struct V_193 * V_194 = & V_412 -> V_413 ;
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 = NULL ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_53 ( V_2 , & V_194 -> V_195 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_15 = F_191 ( V_4 -> V_20 , V_412 , V_279 ) ;
return V_15 ;
}
static int F_192 ( struct V_32 * exp , struct V_280 * V_266 ,
struct V_101 * V_223 , T_3 * V_306 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_53 ( V_2 , V_223 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_15 = F_193 ( V_4 -> V_20 , V_266 , V_223 , V_306 ) ;
return V_15 ;
}
static int F_194 ( struct V_12 * V_414 , struct V_32 * exp ,
struct V_177 * V_178 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 = V_2 -> V_19 [ 0 ] ;
int V_15 = 0 , V_14 ;
T_3 V_415 , V_416 ;
if ( ! V_2 -> V_7 . V_18 || ! V_4 -> V_6 ) {
F_12 ( L_79 ) ;
return - V_212 ;
}
if ( V_178 -> V_417 != V_418 ) {
V_15 = V_177 ( V_4 -> V_20 , V_178 ) ;
return V_15 ;
}
V_415 = V_416 = 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
int V_151 ;
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL || V_4 -> V_20 == NULL || V_4 -> V_6 == 0 )
continue;
if ( ! V_4 -> V_6 ) {
F_3 ( V_419 , L_80 , V_14 ) ;
continue;
}
V_151 = V_177 ( V_4 -> V_20 , V_178 ) ;
if ( V_151 ) {
F_12 ( L_81 , V_14 , V_151 ) ;
if ( ! V_15 )
V_15 = V_151 ;
} else {
V_415 += V_178 -> V_420 . V_421 ;
V_416 += V_178 -> V_420 . V_422 ;
}
}
V_178 -> V_420 . V_421 = V_415 ;
V_178 -> V_420 . V_422 = V_416 ;
return V_15 ;
}
static int F_195 ( struct V_12 * V_414 , struct V_32 * exp ,
struct V_177 * V_178 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_14 , V_15 = 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
int V_151 ;
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( V_4 == NULL || V_4 -> V_20 == NULL || ! V_4 -> V_6 ) {
F_12 ( L_82 , V_14 ) ;
return - V_212 ;
}
V_151 = F_196 ( V_4 -> V_20 , V_178 ) ;
if ( V_151 && ! V_15 )
V_15 = V_151 ;
}
return V_15 ;
}
static int T_12 F_197 ( void )
{
struct V_227 V_228 ;
int V_15 ;
F_90 ( & V_228 ) ;
V_15 = F_198 ( & V_423 , & V_424 ,
V_425 , NULL ) ;
return V_15 ;
}
static void F_199 ( void )
{
F_200 ( V_425 ) ;
}
