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
if ( ! V_4 || ! V_4 -> V_20 )
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
if ( ! V_13 ) {
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
if ( V_38 && V_38 -> V_61 & V_62 )
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
if ( ! V_4 || ! V_4 -> V_20 || V_4 -> V_6 == 0 )
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
if ( ! V_2 -> V_19 [ V_14 ] || ! V_2 -> V_19 [ V_14 ] -> V_20 ||
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
V_4 -> V_21 . V_10 , V_13 -> V_9 . V_10 , V_53 -> V_10 ) ;
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
if ( ! V_2 -> V_19 [ V_88 ] )
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
if ( ( V_88 < V_2 -> V_91 ) && V_2 -> V_19 [ V_88 ] ) {
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
if ( ! V_93 ) {
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
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( ! V_4 )
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
if ( ! V_4 )
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
V_75 = F_6 ( V_4 -> V_20 ) ;
if ( V_75 ) {
V_75 -> V_104 = V_13 -> V_104 ;
V_75 -> V_105 = V_13 -> V_105 ;
V_75 -> V_106 = V_13 -> V_106 ;
if ( V_2 -> V_59 )
F_49 ( V_2 -> V_59 ,
V_75 -> V_27 ) ;
}
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
if ( ! V_2 -> V_19 [ V_14 ] || ! V_2 -> V_19 [ V_14 ] -> V_20 )
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
static int F_52 ( struct V_32 * exp , int V_108 , void * V_109 ,
void T_2 * V_110 )
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
if ( V_114 ) {
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
if ( ! V_114 ) {
V_115 = sizeof( * V_114 ) + V_129 ;
V_114 = F_43 ( V_115 , V_97 ) ;
if ( ! V_114 ) {
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
struct V_144 * V_145 ,
void T_2 * V_110 )
{
int V_15 = 0 ;
T_1 V_14 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
F_56 ( V_143 , V_2 -> V_19 [ V_14 ] -> V_20 , V_108 , V_145 , V_110 ) ;
}
V_15 = F_63 ( V_145 -> V_146 , V_145 -> V_147 ) ;
return V_15 ;
}
static int F_64 ( struct V_1 * V_2 , unsigned int V_143 , int V_108 ,
struct V_144 * V_145 , void T_2 * V_110 )
{
struct V_148 * V_149 ;
T_1 V_14 , V_150 ;
int V_151 , V_15 = 0 ;
bool V_152 = false ;
struct V_153 V_154 = { 0 } ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_151 = F_56 ( V_143 , V_2 -> V_19 [ V_14 ] -> V_20 , V_108 , V_145 , V_110 ) ;
if ( V_151 ) {
if ( V_2 -> V_19 [ V_14 ] -> V_6 ) {
F_12 ( L_36 ,
V_2 -> V_19 [ V_14 ] -> V_21 . V_10 ,
V_14 , V_143 , V_151 ) ;
V_15 = V_151 ;
V_145 -> V_155 |= V_156 ;
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
V_149 = F_65 ( V_145 -> V_157 ) ;
if ( ! V_149 )
return - V_158 ;
V_154 . V_159 = V_160 ;
V_154 . V_161 = V_2 -> V_53 ;
V_154 . V_162 = V_145 -> V_163 ;
V_15 = F_66 ( V_149 , V_145 -> V_146 , V_145 -> V_147 ,
& V_154 , sizeof( V_154 ) ) ;
if ( V_15 ) {
if ( V_149 )
F_67 ( V_149 ) ;
}
return V_15 ;
}
static int F_68 ( unsigned int V_143 , struct V_32 * exp ,
int V_108 , void * V_109 , void T_2 * V_110 )
{
struct V_12 * V_111 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_111 -> V_34 . V_2 ;
int V_14 = 0 ;
int V_15 = 0 ;
int V_164 = 0 ;
int V_165 = V_2 -> V_7 . V_18 ;
if ( V_165 == 0 )
return - V_166 ;
switch ( V_143 ) {
case V_167 : {
struct V_168 * V_38 = V_109 ;
struct V_12 * V_75 ;
struct V_169 V_170 = { 0 } ;
T_1 V_88 ;
memcpy ( & V_88 , V_38 -> V_171 , sizeof( T_1 ) ) ;
if ( V_88 >= V_165 )
return - V_172 ;
if ( ! V_2 -> V_19 [ V_88 ] || V_2 -> V_19 [ V_88 ] -> V_6 == 0 )
return - V_173 ;
V_75 = F_6 ( V_2 -> V_19 [ V_88 ] -> V_20 ) ;
if ( ! V_75 )
return - V_24 ;
if ( F_69 ( V_38 -> V_174 , F_70 ( V_75 ) ,
F_71 ( ( int ) V_38 -> V_175 ,
( int ) sizeof( struct V_9 ) ) ) )
return - V_176 ;
V_15 = V_169 ( NULL , V_2 -> V_19 [ V_88 ] -> V_20 , & V_170 ,
F_72 ( - V_177 ) ,
0 ) ;
if ( V_15 )
return V_15 ;
if ( F_69 ( V_38 -> V_178 , & V_170 ,
F_71 ( ( int ) V_38 -> V_179 ,
( int ) sizeof( V_170 ) ) ) )
return - V_176 ;
break;
}
case V_180 : {
struct V_181 * V_182 = V_109 ;
struct V_3 * V_4 = NULL ;
struct V_183 * V_184 ;
if ( V_182 -> V_185 == V_186 ) {
if ( V_182 -> V_187 < 0 || V_165 <= V_182 -> V_187 )
return - V_24 ;
V_4 = V_2 -> V_19 [ V_182 -> V_187 ] ;
if ( ! V_4 || ! V_4 -> V_20 )
return - V_24 ;
} else if ( V_182 -> V_185 == V_188 ) {
for ( V_14 = 0 ; V_14 < V_165 ; V_14 ++ ) {
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( ! V_4 )
continue;
if ( ! F_5 ( & V_4 -> V_21 ,
& V_182 -> V_9 ) )
continue;
if ( ! V_4 -> V_20 )
return - V_24 ;
break;
}
} else {
return - V_24 ;
}
if ( V_14 >= V_165 )
return - V_189 ;
F_7 ( V_4 && V_4 -> V_20 ) ;
V_184 = F_43 ( sizeof( * V_184 ) , V_97 ) ;
if ( ! V_184 )
return - V_98 ;
F_73 ( V_184 , V_182 ) ;
V_15 = V_183 ( V_4 -> V_20 , V_184 ) ;
if ( V_15 == 0 ) {
F_73 ( V_182 , V_184 ) ;
V_182 -> V_185 = V_186 ;
V_182 -> V_9 = V_4 -> V_21 ;
}
F_36 ( V_184 ) ;
break;
}
case V_190 :
case V_191 : {
struct V_192 * V_193 = V_109 ;
if ( V_193 -> V_194 >= V_165 )
return - V_172 ;
if ( ! V_2 -> V_19 [ V_193 -> V_194 ] ||
! V_2 -> V_19 [ V_193 -> V_194 ] -> V_20 ||
V_2 -> V_19 [ V_193 -> V_194 ] -> V_6 == 0 )
return - V_172 ;
V_15 = F_56 ( V_143 , V_2 -> V_19 [ V_193 -> V_194 ] -> V_20 ,
sizeof( * V_193 ) , V_193 , NULL ) ;
break;
}
case V_195 : {
if ( ! V_2 -> V_19 [ 0 ] )
return - V_173 ;
V_15 = F_56 ( V_143 , V_2 -> V_19 [ 0 ] -> V_20 , V_108 , V_109 , V_110 ) ;
break;
}
case V_118 : {
V_15 = F_52 ( exp , V_108 , V_109 , V_110 ) ;
break;
}
case V_196 :
case V_197 :
case V_198 : {
struct V_199 * V_200 = V_109 ;
struct V_3 * V_4 ;
V_4 = F_53 ( V_2 , & V_200 -> V_201 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
if ( ! V_4 -> V_20 )
return - V_24 ;
V_15 = F_56 ( V_143 , V_4 -> V_20 , V_108 , V_109 , V_110 ) ;
break;
}
case V_202 : {
const struct V_203 * V_204 = V_109 ;
struct V_3 * V_4 ;
V_4 = F_53 ( V_2 , & V_204 -> V_205 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_15 = F_56 ( V_143 , V_4 -> V_20 , V_108 , V_109 , V_110 ) ;
break;
}
case V_206 : {
struct V_130 * V_131 = V_109 ;
struct V_3 * V_4 ;
unsigned int V_207 = V_131 -> V_135 . V_136 ;
if ( V_207 == 0 )
return 0 ;
if ( V_207 == 1 || V_165 == 1 ) {
V_4 = F_53 ( V_2 ,
& V_131 -> V_137 [ 0 ] . V_138 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_15 = F_56 ( V_143 , V_4 -> V_20 , V_108 , V_109 , V_110 ) ;
} else {
for ( V_14 = 0 ; V_14 < V_165 ; V_14 ++ ) {
unsigned int V_133 , V_208 ;
int V_209 ;
struct V_130 * V_210 ;
V_133 = F_59 ( V_2 , V_131 , V_2 -> V_19 [ V_14 ] ) ;
if ( V_133 == 0 )
continue;
V_208 = F_74 ( F_75 ( * V_131 ) ,
V_137 [ V_133 ] )
+ V_131 -> V_135 . V_142 ;
V_210 = F_76 ( V_208 , V_97 ) ;
if ( ! V_210 )
return - V_98 ;
F_60 ( V_2 , V_131 , V_2 -> V_19 [ V_14 ] , V_210 ) ;
V_209 = F_56 ( V_143 , V_2 -> V_19 [ V_14 ] -> V_20 ,
V_208 , V_210 , V_110 ) ;
if ( V_209 != 0 && V_15 == 0 )
V_15 = V_209 ;
F_77 ( V_210 ) ;
}
}
break;
}
case V_211 : {
struct V_199 * V_200 = V_109 ;
struct V_3 * V_212 , * V_213 ;
V_212 = F_53 ( V_2 , & V_200 -> V_201 ) ;
if ( F_54 ( V_212 ) )
return F_55 ( V_212 ) ;
V_213 = F_53 ( V_2 , & V_200 -> V_214 ) ;
if ( F_54 ( V_213 ) )
return F_55 ( V_213 ) ;
if ( ! V_212 -> V_20 || ! V_213 -> V_20 )
return - V_24 ;
if ( V_212 -> V_85 != V_213 -> V_85 )
return - V_215 ;
V_15 = F_56 ( V_143 , V_212 -> V_20 , V_108 , V_109 , V_110 ) ;
break;
}
case V_216 : {
struct V_144 * V_145 = V_109 ;
if ( V_145 -> V_155 & V_156 )
V_15 = F_62 ( V_2 , V_143 , V_108 , V_145 , V_110 ) ;
else
V_15 = F_64 ( V_2 , V_143 , V_108 , V_145 , V_110 ) ;
break;
}
default:
for ( V_14 = 0 ; V_14 < V_165 ; V_14 ++ ) {
struct V_12 * V_75 ;
int V_151 ;
if ( ! V_2 -> V_19 [ V_14 ] || ! V_2 -> V_19 [ V_14 ] -> V_20 )
continue;
V_75 = F_6 ( V_2 -> V_19 [ V_14 ] -> V_20 ) ;
V_75 -> V_104 = V_111 -> V_104 ;
V_151 = F_56 ( V_143 , V_2 -> V_19 [ V_14 ] -> V_20 , V_108 ,
V_109 , V_110 ) ;
if ( V_151 == - V_173 && V_143 == V_217 ) {
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
V_164 = 1 ;
}
if ( ! V_164 && ! V_15 )
V_15 = - V_218 ;
}
return V_15 ;
}
static int F_78 ( struct V_12 * V_13 ,
struct V_199 * V_200 , T_3 * V_219 )
{
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
F_7 ( V_219 ) ;
if ( V_2 -> V_7 . V_18 == 1 ) {
* V_219 = 0 ;
return 0 ;
}
if ( V_200 -> V_220 & V_221 ) {
struct V_222 * V_223 ;
V_223 = (struct V_222 * ) V_200 -> V_200 ;
if ( V_223 -> V_224 == V_225 &&
V_223 -> V_226 != - 1 ) {
if ( V_223 -> V_226 >= V_2 -> V_7 . V_18 ) {
F_12 ( L_37 ,
V_13 -> V_27 ,
V_223 -> V_226 ,
V_2 -> V_7 . V_18 , - V_227 ) ;
return - V_227 ;
}
* V_219 = V_223 -> V_226 ;
return 0 ;
}
}
* V_219 = V_200 -> V_228 ;
return 0 ;
}
int F_79 ( struct V_1 * V_2 , struct V_101 * V_229 , T_3 V_219 )
{
struct V_3 * V_4 ;
int V_15 ;
V_4 = F_80 ( V_2 , V_219 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
F_81 ( & V_4 -> V_99 ) ;
if ( V_4 -> V_6 == 0 || ! V_4 -> V_20 ) {
V_15 = - V_172 ;
goto V_230;
}
V_15 = F_82 ( V_4 -> V_20 , V_229 , NULL ) ;
if ( V_15 > 0 ) {
F_7 ( F_58 ( V_229 ) ) ;
V_15 = 0 ;
}
V_230:
F_83 ( & V_4 -> V_99 ) ;
return V_15 ;
}
int F_84 ( struct V_32 * exp , struct V_101 * V_229 ,
struct V_199 * V_200 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
T_3 V_219 = 0 ;
int V_15 ;
F_7 ( V_200 ) ;
F_7 ( V_229 ) ;
V_15 = F_78 ( V_13 , V_200 , & V_219 ) ;
if ( V_15 ) {
F_12 ( L_38 ,
V_15 ) ;
return V_15 ;
}
V_15 = F_79 ( V_2 , V_229 , V_219 ) ;
if ( V_15 ) {
F_12 ( L_39 , V_15 ) ;
return V_15 ;
}
return V_15 ;
}
static int F_85 ( struct V_12 * V_13 , struct V_231 * V_232 )
{
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_233 V_234 = { NULL } ;
struct V_235 * V_7 ;
int V_15 ;
if ( F_86 ( V_232 , 1 ) < 1 ) {
F_12 ( L_40 ) ;
return - V_24 ;
}
V_7 = (struct V_235 * ) F_87 ( V_232 , 1 ) ;
if ( sizeof( * V_7 ) > F_86 ( V_232 , 1 ) ) {
F_12 ( L_41 ,
( int ) sizeof( * V_7 ) , F_86 ( V_232 , 1 ) ) ;
return - V_24 ;
}
V_2 -> V_19 = F_41 ( 32 , sizeof( * V_2 -> V_19 ) , V_97 ) ;
if ( ! V_2 -> V_19 )
return - V_98 ;
V_2 -> V_91 = 32 ;
F_88 ( & V_2 -> V_7 . V_236 , V_7 -> V_236 . V_10 ) ;
V_2 -> V_7 . V_18 = 0 ;
V_2 -> V_7 . V_8 = 0 ;
V_2 -> V_72 = 0 ;
V_2 -> V_71 = 0 ;
V_2 -> V_70 = 0 ;
V_2 -> V_237 = V_238 ;
F_89 ( & V_2 -> V_17 ) ;
F_44 ( & V_2 -> V_239 ) ;
F_90 ( & V_234 ) ;
F_91 ( V_13 , V_234 . V_240 , V_234 . V_241 ) ;
V_15 = F_92 ( V_13 -> V_242 , L_42 ,
0444 , & V_243 , V_13 ) ;
if ( V_15 )
F_24 ( L_43 ,
V_13 -> V_27 , V_15 ) ;
V_15 = F_93 ( & V_2 -> V_86 , V_13 -> V_27 ,
V_244 ) ;
if ( V_15 ) {
F_12 ( L_44 , V_15 ) ;
goto V_230;
}
return 0 ;
V_230:
return V_15 ;
}
static int F_94 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
F_95 ( & V_2 -> V_86 ) ;
if ( V_2 -> V_19 ) {
int V_14 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( ! V_2 -> V_19 [ V_14 ] )
continue;
F_35 ( V_2 , V_14 ) ;
}
F_36 ( V_2 -> V_19 ) ;
V_2 -> V_91 = 0 ;
}
return 0 ;
}
static int F_96 ( struct V_12 * V_13 , T_3 V_108 , void * V_245 )
{
struct V_231 * V_232 = V_245 ;
struct V_9 V_9 ;
int V_90 ;
T_1 V_88 ;
int V_15 ;
switch ( V_232 -> V_246 ) {
case V_247 :
if ( F_86 ( V_232 , 1 ) > sizeof( V_9 . V_10 ) ) {
V_15 = - V_24 ;
goto V_230;
}
F_88 ( & V_9 , F_87 ( V_232 , 1 ) ) ;
if ( sscanf ( F_87 ( V_232 , 2 ) , L_45 , & V_88 ) != 1 ) {
V_15 = - V_24 ;
goto V_230;
}
if ( sscanf ( F_87 ( V_232 , 3 ) , L_45 , & V_90 ) != 1 ) {
V_15 = - V_24 ;
goto V_230;
}
V_15 = F_37 ( V_13 , & V_9 , V_88 , V_90 ) ;
goto V_230;
default:
F_12 ( L_46 , V_232 -> V_246 ) ;
V_15 = - V_24 ;
goto V_230;
}
V_230:
return V_15 ;
}
static int F_97 ( const struct V_51 * V_52 , struct V_32 * exp ,
struct V_169 * V_248 , T_4 V_249 , T_1 V_250 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_169 * V_251 ;
int V_15 = 0 ;
int V_14 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_251 = F_43 ( sizeof( * V_251 ) , V_97 ) ;
if ( ! V_251 )
return - V_98 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( ! V_2 -> V_19 [ V_14 ] || ! V_2 -> V_19 [ V_14 ] -> V_20 )
continue;
V_15 = V_169 ( V_52 , V_2 -> V_19 [ V_14 ] -> V_20 , V_251 ,
V_249 , V_250 ) ;
if ( V_15 ) {
F_12 ( L_47 , V_14 ,
V_2 -> V_19 [ V_14 ] -> V_20 -> V_33 -> V_27 ,
V_15 ) ;
goto V_252;
}
if ( V_14 == 0 ) {
* V_248 = * V_251 ;
if ( V_250 & V_253 )
goto V_252;
} else {
V_248 -> V_254 += V_251 -> V_254 ;
V_248 -> V_255 += V_251 -> V_255 ;
V_248 -> V_256 += V_251 -> V_256 ;
V_248 -> V_257 += V_251 -> V_257 ;
}
}
V_252:
F_36 ( V_251 ) ;
return V_15 ;
}
static int F_98 ( struct V_32 * exp ,
struct V_101 * V_229 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_99 ( V_2 -> V_19 [ 0 ] -> V_20 , V_229 ) ;
return V_15 ;
}
static int F_100 ( struct V_32 * exp , const struct V_101 * V_229 ,
T_5 V_258 , const char * V_259 ,
const char * V_260 , int V_261 , int V_262 ,
int V_250 , struct V_263 * * V_264 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_53 ( V_2 , V_229 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_15 = F_101 ( V_4 -> V_20 , V_229 , V_258 , V_259 , V_260 ,
V_261 , V_262 , V_250 , V_264 ) ;
return V_15 ;
}
static int F_102 ( struct V_32 * exp , const struct V_101 * V_229 ,
T_5 V_258 , const char * V_259 ,
const char * V_260 , int V_261 , int V_262 ,
int V_250 , T_1 V_265 ,
struct V_263 * * V_264 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_53 ( V_2 , V_229 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_15 = F_103 ( V_4 -> V_20 , V_229 , V_258 , V_259 , V_260 ,
V_261 , V_262 , V_250 , V_265 ,
V_264 ) ;
return V_15 ;
}
static int F_104 ( struct V_32 * exp , struct V_199 * V_200 ,
struct V_263 * * V_264 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_53 ( V_2 , & V_200 -> V_201 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
if ( V_200 -> V_266 & V_267 ) {
V_200 -> V_228 = V_4 -> V_85 ;
return 0 ;
}
V_15 = F_105 ( V_4 -> V_20 , V_200 , V_264 ) ;
return V_15 ;
}
static int F_106 ( struct V_32 * exp , const struct V_101 * V_229 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
int V_14 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_268 , L_48 V_126 L_49 , F_57 ( V_229 ) ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( ! V_2 -> V_19 [ V_14 ] || ! V_2 -> V_19 [ V_14 ] -> V_20 )
continue;
F_107 ( V_2 -> V_19 [ V_14 ] -> V_20 , V_229 ) ;
}
return 0 ;
}
static int F_108 ( struct V_32 * exp , const struct V_101 * V_229 ,
T_6 V_269 , void * V_38 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
int V_14 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_268 , L_48 V_126 L_49 , F_57 ( V_229 ) ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( ! V_2 -> V_19 [ V_14 ] || ! V_2 -> V_19 [ V_14 ] -> V_20 )
continue;
V_15 = F_109 ( V_2 -> V_19 [ V_14 ] -> V_20 , V_229 , V_269 , V_38 ) ;
if ( V_15 )
return V_15 ;
}
return V_15 ;
}
static int F_110 ( struct V_32 * exp , struct V_199 * V_200 ,
struct V_270 * V_271 , struct V_263 * * V_264 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_53 ( V_2 , & V_200 -> V_201 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
F_3 ( V_268 , L_50 V_126 L_49 , F_57 ( & V_200 -> V_201 ) ) ;
V_15 = F_111 ( V_4 -> V_20 , V_200 , V_271 , V_264 ) ;
return V_15 ;
}
struct V_3
* F_112 ( struct V_1 * V_2 , struct V_199 * V_200 ,
struct V_101 * V_229 )
{
struct V_3 * V_4 ;
V_4 = F_53 ( V_2 , V_229 ) ;
if ( F_54 ( V_4 ) )
return V_4 ;
V_200 -> V_228 = V_4 -> V_85 ;
return V_4 ;
}
static int F_113 ( struct V_32 * exp , struct V_199 * V_200 ,
const void * V_38 , int V_272 , int V_273 , T_1 V_274 ,
T_1 V_275 , T_7 V_276 , T_4 V_277 ,
struct V_263 * * V_264 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
if ( ! V_2 -> V_7 . V_8 )
return - V_218 ;
V_4 = F_112 ( V_2 , V_200 , & V_200 -> V_201 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_15 = F_84 ( exp , & V_200 -> V_214 , V_200 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_268 , L_51 V_126 L_52 ,
V_200 -> V_278 , V_200 -> V_279 , F_57 ( & V_200 -> V_201 ) ,
V_200 -> V_228 ) ;
V_200 -> V_266 |= V_280 ;
V_15 = F_114 ( V_4 -> V_20 , V_200 , V_38 , V_272 , V_273 , V_274 , V_275 ,
V_276 , V_277 , V_264 ) ;
if ( V_15 == 0 ) {
if ( ! * V_264 )
return V_15 ;
F_3 ( V_268 , L_53 V_126 L_49 , F_57 ( & V_200 -> V_214 ) ) ;
}
return V_15 ;
}
static int F_115 ( struct V_32 * exp ,
struct V_199 * V_200 ,
struct V_270 * V_271 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_53 ( V_2 , & V_200 -> V_201 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_15 = F_116 ( V_4 -> V_20 , V_200 , V_271 ) ;
return V_15 ;
}
static int
F_117 ( struct V_32 * exp , struct V_281 * V_282 ,
struct V_283 * V_269 , struct V_199 * V_200 ,
struct V_55 * V_284 , void * V_285 , int V_286 ,
T_4 V_287 )
{
struct V_263 * V_210 = V_269 -> V_288 . V_289 . V_290 ;
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_55 V_291 ;
struct V_3 * V_4 ;
struct V_199 * V_292 ;
struct V_101 V_293 ;
struct V_294 * V_295 ;
int V_15 = 0 ;
int V_296 ;
V_295 = F_118 ( & V_210 -> V_297 , & V_298 ) ;
if ( ! ( V_295 -> V_258 & V_299 ) )
return 0 ;
F_3 ( V_268 , L_54 V_126 L_55 V_126 L_49 ,
F_119 ( V_269 ) , F_57 ( & V_200 -> V_201 ) , F_57 ( & V_295 -> V_293 ) ) ;
V_296 = V_269 -> V_288 . V_289 . V_300 ;
F_7 ( V_296 != 0 ) ;
memcpy ( & V_291 , V_284 , sizeof( V_291 ) ) ;
V_269 -> V_288 . V_289 . V_300 = 0 ;
V_269 -> V_288 . V_289 . V_290 = NULL ;
V_293 = V_295 -> V_293 ;
F_120 ( V_210 ) ;
V_4 = F_53 ( V_2 , & V_293 ) ;
if ( F_54 ( V_4 ) ) {
V_15 = F_55 ( V_4 ) ;
goto V_230;
}
V_292 = F_43 ( sizeof( * V_292 ) , V_97 ) ;
if ( ! V_292 ) {
V_15 = - V_98 ;
goto V_230;
}
V_292 -> V_201 = V_293 ;
V_292 -> V_301 = V_302 ;
V_15 = F_121 ( V_4 -> V_20 , V_282 , V_269 , V_292 , V_284 ,
V_285 , V_286 , NULL , V_287 ) ;
F_36 ( V_292 ) ;
V_230:
F_122 ( & V_291 , V_296 ) ;
return V_15 ;
}
static int
F_123 ( struct V_32 * exp , struct V_281 * V_282 ,
struct V_283 * V_269 , struct V_199 * V_200 ,
struct V_55 * V_284 , void * V_285 , int V_286 ,
struct V_263 * * V_210 , T_4 V_287 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_268 , L_56 V_126 L_49 ,
F_119 ( V_269 ) , F_57 ( & V_200 -> V_201 ) ) ;
V_4 = F_112 ( V_2 , V_200 , & V_200 -> V_201 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
F_3 ( V_268 , L_56 V_126 L_57 ,
F_119 ( V_269 ) , F_57 ( & V_200 -> V_201 ) , V_4 -> V_85 ) ;
V_15 = F_121 ( V_4 -> V_20 , V_282 , V_269 , V_200 , V_284 ,
V_285 , V_286 , V_210 , V_287 ) ;
if ( V_15 == 0 && V_269 && V_269 -> V_303 == V_304 ) {
V_15 = F_117 ( exp , V_282 , V_269 , V_200 , V_284 ,
V_285 , V_286 , V_287 ) ;
}
return V_15 ;
}
static int
F_124 ( struct V_32 * exp , struct V_199 * V_200 ,
struct V_263 * * V_264 )
{
struct V_263 * V_210 = NULL ;
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
struct V_294 * V_295 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_112 ( V_2 , V_200 , & V_200 -> V_201 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
F_3 ( V_268 , L_58 V_126 L_57 ,
V_200 -> V_278 , V_200 -> V_279 , F_57 ( & V_200 -> V_201 ) ,
V_4 -> V_85 ) ;
V_15 = F_125 ( V_4 -> V_20 , V_200 , V_264 ) ;
if ( V_15 != 0 )
return V_15 ;
V_295 = F_118 ( & ( * V_264 ) -> V_297 ,
& V_298 ) ;
if ( V_295 -> V_258 & V_299 ) {
struct V_101 V_305 = V_295 -> V_293 ;
F_3 ( V_268 , L_59 V_126 L_49 ,
F_57 ( & V_305 ) ) ;
V_4 = F_53 ( V_2 , & V_305 ) ;
if ( F_54 ( V_4 ) ) {
F_120 ( * V_264 ) ;
return F_55 ( V_4 ) ;
}
V_200 -> V_201 = V_305 ;
V_200 -> V_306 |= V_307 ;
V_200 -> V_278 = 0 ;
V_200 -> V_279 = NULL ;
V_15 = F_125 ( V_4 -> V_20 , V_200 , & V_210 ) ;
F_120 ( * V_264 ) ;
* V_264 = V_210 ;
}
return V_15 ;
}
static int F_126 ( struct V_32 * exp , struct V_199 * V_200 ,
int V_308 , enum V_309 V_273 , int V_310 ,
int V_311 )
{
struct V_101 * V_229 = F_127 ( V_200 , V_311 ) ;
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
T_8 V_312 = { { 0 } } ;
int V_15 = 0 ;
if ( ! F_58 ( V_229 ) )
return 0 ;
V_4 = F_53 ( V_2 , V_229 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
if ( V_4 -> V_85 != V_308 ) {
F_3 ( V_268 , L_60 V_126 L_49 , F_57 ( V_229 ) ) ;
V_312 . V_313 . V_310 = V_310 ;
V_15 = F_128 ( V_4 -> V_20 , V_229 , & V_312 ,
V_273 , V_314 , NULL ) ;
} else {
F_3 ( V_268 ,
L_61 V_126 L_49 ,
V_308 , F_57 ( V_229 ) ) ;
V_200 -> V_266 |= V_311 ;
V_15 = 0 ;
}
return V_15 ;
}
static int F_129 ( struct V_32 * exp , struct V_199 * V_200 ,
struct V_263 * * V_264 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_7 ( V_200 -> V_278 != 0 ) ;
F_3 ( V_268 , L_62 V_126 L_63 V_126 L_49 ,
F_57 ( & V_200 -> V_214 ) , V_200 -> V_278 ,
V_200 -> V_279 , F_57 ( & V_200 -> V_201 ) ) ;
V_200 -> V_315 = F_130 ( & V_316 , F_131 () ) ;
V_200 -> V_317 = F_132 ( & V_316 , F_133 () ) ;
V_200 -> V_318 = F_134 () ;
V_4 = F_112 ( V_2 , V_200 , & V_200 -> V_214 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_200 -> V_266 |= V_319 ;
V_15 = F_126 ( exp , V_200 , V_4 -> V_85 , V_320 ,
V_321 , V_280 ) ;
if ( V_15 != 0 )
return V_15 ;
V_15 = F_135 ( V_4 -> V_20 , V_200 , V_264 ) ;
return V_15 ;
}
static int F_136 ( struct V_32 * exp , struct V_199 * V_200 ,
const char * V_94 , int V_322 , const char * V_323 , int V_324 ,
struct V_263 * * V_264 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_325 ;
struct V_3 * V_326 ;
int V_15 ;
F_7 ( V_322 != 0 ) ;
F_3 ( V_268 , L_64 V_126 L_65 V_126 L_49 ,
V_322 , V_94 , F_57 ( & V_200 -> V_201 ) ,
V_324 , V_323 , F_57 ( & V_200 -> V_214 ) ) ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_200 -> V_315 = F_130 ( & V_316 , F_131 () ) ;
V_200 -> V_317 = F_132 ( & V_316 , F_133 () ) ;
V_200 -> V_318 = F_134 () ;
V_325 = F_112 ( V_2 , V_200 , & V_200 -> V_201 ) ;
if ( F_54 ( V_325 ) )
return F_55 ( V_325 ) ;
V_326 = F_112 ( V_2 , V_200 , & V_200 -> V_214 ) ;
if ( F_54 ( V_326 ) )
return F_55 ( V_326 ) ;
V_200 -> V_266 |= V_280 | V_327 ;
V_15 = F_126 ( exp , V_200 , V_325 -> V_85 ,
V_320 , V_321 ,
V_319 ) ;
if ( V_15 == 0 ) {
V_15 = F_126 ( exp , V_200 , V_325 -> V_85 ,
V_320 , V_328 ,
V_329 ) ;
}
if ( V_15 == 0 )
V_15 = F_126 ( exp , V_200 , V_325 -> V_85 ,
V_320 , V_330 ,
V_329 ) ;
if ( V_15 == 0 )
V_15 = F_137 ( V_325 -> V_20 , V_200 , V_94 , V_322 ,
V_323 , V_324 , V_264 ) ;
return V_15 ;
}
static int F_138 ( struct V_32 * exp , struct V_199 * V_200 ,
void * V_331 , int V_332 , void * V_333 , int V_334 ,
struct V_263 * * V_264 ,
struct V_270 * * V_271 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_268 , L_66 V_126 L_67 ,
F_57 ( & V_200 -> V_201 ) , V_200 -> V_335 . V_336 ) ;
V_200 -> V_266 |= V_280 ;
V_4 = F_53 ( V_2 , & V_200 -> V_201 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_15 = F_139 ( V_4 -> V_20 , V_200 , V_331 , V_332 , V_333 ,
V_334 , V_264 , V_271 ) ;
return V_15 ;
}
static int F_140 ( struct V_32 * exp , const struct V_101 * V_229 ,
struct V_263 * * V_264 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_53 ( V_2 , V_229 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_15 = F_141 ( V_4 -> V_20 , V_229 , V_264 ) ;
return V_15 ;
}
static void F_142 ( struct V_337 * * V_338 , int V_339 , int V_340 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_339 ; V_14 ++ ) {
struct V_341 * V_342 = F_143 ( V_338 [ V_14 ] ) ;
struct V_341 * V_343 = V_342 ;
struct V_344 * V_345 = NULL ;
struct V_344 * V_346 ;
T_4 V_347 = V_342 -> V_348 ;
T_1 V_250 = V_342 -> V_349 ;
while ( -- V_340 > 0 ) {
V_346 = F_144 ( V_342 ) ;
for ( V_345 = V_346 ; V_346 ;
V_345 = V_346 , V_346 = F_145 ( V_346 ) )
;
V_342 = (struct V_341 * ) ( ( char * ) V_342 + V_350 ) ;
if ( ! ( ( unsigned long ) V_342 & ~ V_351 ) )
break;
V_347 = V_342 -> V_348 ;
V_250 = V_342 -> V_349 ;
if ( ! V_345 )
break;
F_7 ( F_146 ( V_345 -> V_352 ) == 0 ) ;
V_345 -> V_352 =
F_147 ( ( char * ) ( V_342 -> V_353 ) -
( char * ) V_345 ) ;
}
V_343 -> V_348 = V_347 ;
V_343 -> V_349 &= ~ F_148 ( V_354 ) ;
V_343 -> V_349 |= V_250 & F_148 ( V_354 ) ;
F_149 ( V_338 [ V_14 ] ) ;
}
F_150 ( V_340 == 0 , L_68 , V_340 ) ;
}
static int F_151 ( struct V_32 * exp , struct V_199 * V_200 ,
struct V_337 * * V_338 , struct V_263 * * V_264 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
T_4 V_355 = V_200 -> V_356 ;
int V_15 ;
int V_339 ;
int V_340 ;
struct V_3 * V_4 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_268 , L_69 V_126 L_49 ,
V_355 , F_57 ( & V_200 -> V_201 ) ) ;
V_4 = F_53 ( V_2 , & V_200 -> V_201 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_15 = F_152 ( V_4 -> V_20 , V_200 , V_338 , V_264 ) ;
if ( V_15 != 0 )
return V_15 ;
V_339 = ( ( * V_264 ) -> V_357 -> V_358 + V_359 - 1 )
>> V_360 ;
V_340 = ( * V_264 ) -> V_357 -> V_358 >> V_361 ;
F_7 ( ! ( ( * V_264 ) -> V_357 -> V_358 & ~ V_362 ) ) ;
F_7 ( V_339 > 0 && V_339 <= V_200 -> V_363 ) ;
F_3 ( V_268 , L_70 , V_339 , V_340 ,
V_200 -> V_363 ) ;
F_142 ( V_338 , V_339 , V_340 ) ;
return V_15 ;
}
static int F_153 ( struct V_32 * exp , struct V_199 * V_200 ,
struct V_263 * * V_264 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 = NULL ;
struct V_294 * V_295 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_364:
if ( F_154 ( ! F_155 ( & V_200 -> V_214 ) ) )
V_4 = F_112 ( V_2 , V_200 , & V_200 -> V_214 ) ;
else
V_4 = F_112 ( V_2 , V_200 , & V_200 -> V_201 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_200 -> V_315 = F_130 ( & V_316 , F_131 () ) ;
V_200 -> V_317 = F_132 ( & V_316 , F_133 () ) ;
V_200 -> V_318 = F_134 () ;
V_200 -> V_266 |= V_280 | V_327 ;
V_15 = F_126 ( exp , V_200 , V_4 -> V_85 , V_320 ,
V_330 , V_327 ) ;
if ( V_15 != 0 )
return V_15 ;
F_3 ( V_268 , L_71 V_126 L_72 V_126 L_57 ,
F_57 ( & V_200 -> V_201 ) , F_57 ( & V_200 -> V_214 ) , V_4 -> V_85 ) ;
V_15 = F_156 ( V_4 -> V_20 , V_200 , V_264 ) ;
if ( V_15 != 0 && V_15 != - V_119 )
return V_15 ;
V_295 = F_118 ( & ( * V_264 ) -> V_297 , & V_298 ) ;
if ( ! V_295 )
return - V_365 ;
if ( F_154 ( ! ( V_295 -> V_258 & V_299 ) ) )
return 0 ;
F_3 ( V_268 , L_73 V_126 L_49 ,
exp -> V_33 -> V_27 , F_57 ( & V_295 -> V_293 ) ) ;
V_200 -> V_214 = V_295 -> V_293 ;
F_120 ( * V_264 ) ;
* V_264 = NULL ;
goto V_364;
}
static int F_157 ( struct V_12 * V_13 , enum V_366 V_367 )
{
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
switch ( V_367 ) {
case V_368 :
break;
case V_369 :
F_158 ( & V_2 -> V_86 ) ;
F_159 ( V_13 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_160 ( const struct V_51 * V_52 , struct V_32 * exp ,
T_1 V_370 , void * V_371 , T_1 * V_372 , void * V_373 ,
struct V_374 * V_375 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
int V_15 = 0 ;
V_13 = F_6 ( exp ) ;
if ( ! V_13 ) {
F_3 ( V_376 , L_74 ,
exp -> V_22 . V_23 ) ;
return - V_24 ;
}
V_2 = & V_13 -> V_34 . V_2 ;
if ( V_370 >= strlen ( L_75 ) && ! strcmp ( V_371 , L_75 ) ) {
struct V_3 * V_4 ;
int V_14 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_7 ( * V_372 == sizeof( T_1 ) ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( ! V_4 || ! V_4 -> V_20 )
continue;
if ( ! F_161 ( V_52 , V_4 -> V_20 , V_370 , V_371 ,
V_372 , V_373 , NULL ) )
return 0 ;
}
return - V_24 ;
} else if ( F_162 ( V_377 ) ||
F_162 ( V_378 ) ||
F_162 ( V_379 ) ) {
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_161 ( V_52 , V_2 -> V_19 [ 0 ] -> V_20 , V_370 , V_371 ,
V_372 , V_373 , NULL ) ;
if ( ! V_15 && F_162 ( V_379 ) )
exp -> V_49 = * (struct V_39 * ) V_373 ;
return V_15 ;
} else if ( F_162 ( V_380 ) ) {
* ( ( int * ) V_373 ) = V_2 -> V_7 . V_18 ;
return 0 ;
}
F_3 ( V_376 , L_76 ) ;
return - V_24 ;
}
static int F_163 ( const struct V_51 * V_52 , struct V_32 * exp ,
T_3 V_370 , void * V_371 , T_3 V_372 ,
void * V_373 , struct V_381 * V_164 )
{
struct V_3 * V_4 ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
int V_15 = 0 ;
V_13 = F_6 ( exp ) ;
if ( ! V_13 ) {
F_3 ( V_376 , L_74 ,
exp -> V_22 . V_23 ) ;
return - V_24 ;
}
V_2 = & V_13 -> V_34 . V_2 ;
if ( F_162 ( V_382 ) || F_162 ( V_383 ) ) {
int V_14 , V_151 = 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( ! V_4 || ! V_4 -> V_20 )
continue;
V_151 = F_22 ( V_52 , V_4 -> V_20 ,
V_370 , V_371 , V_372 , V_373 , V_164 ) ;
if ( V_151 && V_15 == 0 )
V_15 = V_151 ;
}
return V_15 ;
}
return - V_24 ;
}
static int F_164 ( struct V_32 * exp , struct V_384 * * V_385 ,
struct V_374 * V_375 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_100 * V_386 ;
struct V_100 * V_387 ;
int V_388 ;
int V_14 ;
V_388 = F_46 ( V_2 ) ;
if ( ! V_385 )
return V_388 ;
if ( * V_385 && ! V_375 ) {
F_77 ( * V_385 ) ;
* V_385 = NULL ;
return 0 ;
}
if ( ! * V_385 ) {
* V_385 = F_76 ( V_388 , V_97 ) ;
if ( ! * V_385 )
return - V_98 ;
}
if ( ! V_375 )
return V_388 ;
V_387 = (struct V_100 * ) V_375 ;
V_386 = (struct V_100 * ) * V_385 ;
if ( V_387 -> V_389 != V_390 &&
V_387 -> V_389 != V_391 )
return - V_24 ;
V_386 -> V_389 = F_148 ( V_387 -> V_389 ) ;
V_386 -> V_392 = F_148 ( V_387 -> V_392 ) ;
V_386 -> V_393 = F_148 ( V_387 -> V_393 ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_386 -> V_394 [ V_14 ] = V_387 -> V_394 [ V_14 ] ;
F_165 ( & V_386 -> V_394 [ V_14 ] , & V_387 -> V_394 [ V_14 ] ) ;
}
return V_388 ;
}
static int F_166 ( struct V_32 * exp , struct V_374 * * V_387 ,
struct V_384 * V_285 , int V_395 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_100 * * V_396 = (struct V_100 * * ) V_387 ;
struct V_100 * V_397 = (struct V_100 * ) V_285 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
int V_388 ;
int V_14 ;
T_1 V_398 ;
V_388 = F_46 ( V_2 ) ;
if ( ! V_387 )
return V_388 ;
if ( * V_387 && ! V_285 ) {
F_77 ( * V_396 ) ;
* V_387 = NULL ;
return 0 ;
}
F_7 ( V_388 == V_395 ) ;
* V_396 = F_76 ( V_388 , V_97 ) ;
if ( ! * V_396 )
return - V_98 ;
if ( ! V_285 )
return V_388 ;
if ( V_397 -> V_389 == V_390 ||
V_397 -> V_389 == V_391 ||
V_397 -> V_389 == V_399 ) {
V_398 = F_167 ( V_397 -> V_389 ) ;
} else {
F_12 ( L_77 ) ;
F_168 () ;
}
( * V_396 ) -> V_389 = V_398 ;
( * V_396 ) -> V_392 = F_167 ( V_397 -> V_392 ) ;
( * V_396 ) -> V_393 = F_167 ( V_397 -> V_393 ) ;
for ( V_14 = 0 ; V_14 < ( * V_396 ) -> V_392 ; V_14 ++ ) {
( * V_396 ) -> V_394 [ V_14 ] = V_397 -> V_394 [ V_14 ] ;
F_169 ( & ( * V_396 ) -> V_394 [ V_14 ] , & ( * V_396 ) -> V_394 [ V_14 ] ) ;
}
return V_388 ;
}
static int F_170 ( struct V_32 * exp , const struct V_101 * V_229 ,
T_8 * V_312 , enum V_309 V_273 ,
enum V_400 V_250 , void * V_401 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
int V_15 = 0 ;
int V_151 ;
int V_14 ;
F_7 ( V_229 ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( ! V_2 -> V_19 [ V_14 ] || ! V_2 -> V_19 [ V_14 ] -> V_20 ||
V_2 -> V_19 [ V_14 ] -> V_6 == 0 )
continue;
V_151 = F_128 ( V_2 -> V_19 [ V_14 ] -> V_20 , V_229 ,
V_312 , V_273 , V_250 , V_401 ) ;
if ( ! V_15 )
V_15 = V_151 ;
}
return V_15 ;
}
static int F_171 ( struct V_32 * exp , T_4 * V_284 , void * V_38 ,
T_4 * V_310 )
{
struct V_1 * V_2 = & exp -> V_33 -> V_34 . V_2 ;
int V_15 ;
V_15 = F_172 ( V_2 -> V_19 [ 0 ] -> V_20 , V_284 , V_38 , V_310 ) ;
return V_15 ;
}
static enum V_309 F_173 ( struct V_32 * exp , T_4 V_250 ,
const struct V_101 * V_229 ,
enum V_402 type ,
T_8 * V_312 ,
enum V_309 V_273 ,
struct V_55 * V_284 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
enum V_309 V_15 ;
int V_14 ;
F_3 ( V_268 , L_78 V_126 L_49 , F_57 ( V_229 ) ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( ! V_2 -> V_19 [ V_14 ] || ! V_2 -> V_19 [ V_14 ] -> V_20 ||
V_2 -> V_19 [ V_14 ] -> V_6 == 0 )
continue;
V_15 = F_174 ( V_2 -> V_19 [ V_14 ] -> V_20 , V_250 , V_229 ,
type , V_312 , V_273 , V_284 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static int F_175 ( struct V_32 * exp ,
struct V_263 * V_210 ,
struct V_32 * V_403 ,
struct V_32 * V_404 ,
struct V_405 * V_406 )
{
struct V_1 * V_2 = & exp -> V_33 -> V_34 . V_2 ;
return F_176 ( V_2 -> V_19 [ 0 ] -> V_20 , V_210 , V_403 , V_404 , V_406 ) ;
}
static int F_177 ( struct V_32 * exp , struct V_405 * V_406 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
if ( V_406 -> V_397 )
F_178 ( exp , ( void * ) & V_406 -> V_397 ) ;
return F_179 ( V_2 -> V_19 [ 0 ] -> V_20 , V_406 ) ;
}
static int F_180 ( struct V_32 * exp ,
struct V_407 * V_408 ,
struct V_283 * V_269 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
V_4 = F_53 ( V_2 , & V_408 -> V_409 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
return F_181 ( V_4 -> V_20 , V_408 , V_269 ) ;
}
static int F_182 ( struct V_32 * exp ,
struct V_407 * V_408 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
V_4 = F_53 ( V_2 , & V_408 -> V_409 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
return F_183 ( V_4 -> V_20 , V_408 ) ;
}
static int F_184 ( struct V_32 * exp ,
const struct V_101 * V_229 ,
T_1 V_265 , struct V_263 * * V_264 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_53 ( V_2 , V_229 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_15 = F_185 ( V_4 -> V_20 , V_229 , V_265 , V_264 ) ;
return V_15 ;
}
static int F_186 ( struct V_32 * exp ,
struct V_410 * V_411 ,
struct V_281 * V_282 )
{
struct V_199 * V_200 = & V_411 -> V_412 ;
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 = NULL ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_53 ( V_2 , & V_200 -> V_201 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_15 = F_187 ( V_4 -> V_20 , V_411 , V_282 ) ;
return V_15 ;
}
static int F_188 ( struct V_32 * exp , struct V_283 * V_269 ,
struct V_101 * V_229 , T_4 * V_310 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_53 ( V_2 , V_229 ) ;
if ( F_54 ( V_4 ) )
return F_55 ( V_4 ) ;
V_15 = F_189 ( V_4 -> V_20 , V_269 , V_229 , V_310 ) ;
return V_15 ;
}
static int F_190 ( struct V_12 * V_413 , struct V_32 * exp ,
struct V_183 * V_184 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 = V_2 -> V_19 [ 0 ] ;
int V_15 = 0 , V_14 ;
T_4 V_414 , V_415 ;
if ( ! V_2 -> V_7 . V_18 || ! V_4 -> V_6 ) {
F_12 ( L_79 ) ;
return - V_218 ;
}
if ( V_184 -> V_416 != V_417 ) {
V_15 = V_183 ( V_4 -> V_20 , V_184 ) ;
return V_15 ;
}
V_414 = V_415 = 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
int V_151 ;
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( ! V_4 || ! V_4 -> V_20 || V_4 -> V_6 == 0 )
continue;
if ( ! V_4 -> V_6 ) {
F_3 ( V_418 , L_80 , V_14 ) ;
continue;
}
V_151 = V_183 ( V_4 -> V_20 , V_184 ) ;
if ( V_151 ) {
F_12 ( L_81 , V_14 , V_151 ) ;
if ( ! V_15 )
V_15 = V_151 ;
} else {
V_414 += V_184 -> V_419 . V_420 ;
V_415 += V_184 -> V_419 . V_421 ;
}
}
V_184 -> V_419 . V_420 = V_414 ;
V_184 -> V_419 . V_421 = V_415 ;
return V_15 ;
}
static int F_191 ( struct V_12 * V_413 , struct V_32 * exp ,
struct V_183 * V_184 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_14 , V_15 = 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
int V_151 ;
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( ! V_4 || ! V_4 -> V_20 || ! V_4 -> V_6 ) {
F_12 ( L_82 , V_14 ) ;
return - V_218 ;
}
V_151 = F_192 ( V_4 -> V_20 , V_184 ) ;
if ( V_151 && ! V_15 )
V_15 = V_151 ;
}
return V_15 ;
}
static int T_9 F_193 ( void )
{
struct V_233 V_234 ;
int V_15 ;
F_90 ( & V_234 ) ;
V_15 = F_194 ( & V_422 , & V_423 ,
V_424 , NULL ) ;
return V_15 ;
}
static void F_195 ( void )
{
F_196 ( V_424 ) ;
}
