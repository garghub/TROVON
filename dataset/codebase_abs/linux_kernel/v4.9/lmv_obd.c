static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
if ( V_4 -> V_6 == V_5 )
return;
V_4 -> V_6 = V_5 ;
V_2 -> V_7 . V_8 += ( V_5 ? 1 : - 1 ) ;
}
static int F_2 ( struct V_1 * V_2 , const struct V_9 * V_10 ,
int V_5 )
{
struct V_3 * V_11 ( V_4 ) ;
struct V_12 * V_13 ;
T_1 V_14 ;
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
struct V_3 * V_4 = V_2 -> V_19 [ 0 ] ;
return V_4 ? F_10 ( V_4 -> V_20 ) : NULL ;
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
static int F_21 ( struct V_32 * exp , T_1 V_63 , T_1 V_64 ,
T_1 V_65 , T_1 V_66 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
T_1 V_14 ;
int V_15 = 0 ;
int V_67 = 0 ;
if ( V_2 -> V_68 < V_63 ) {
V_2 -> V_68 = V_63 ;
V_67 = 1 ;
}
if ( V_2 -> V_69 < V_64 ) {
V_2 -> V_69 = V_64 ;
V_67 = 1 ;
}
if ( V_2 -> V_70 < V_65 ) {
V_2 -> V_70 = V_65 ;
V_67 = 1 ;
}
if ( V_2 -> V_71 < V_66 ) {
V_2 -> V_71 = V_66 ;
V_67 = 1 ;
}
if ( V_67 == 0 )
return 0 ;
if ( V_2 -> V_58 == 0 )
return 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
struct V_3 * V_4 = V_2 -> V_19 [ V_14 ] ;
if ( ! V_4 || ! V_4 -> V_20 || ! V_4 -> V_6 ) {
F_22 ( L_13 , V_13 -> V_27 , V_14 ) ;
continue;
}
V_15 = F_23 ( V_4 -> V_20 , V_63 , V_64 ,
V_65 , V_66 ) ;
if ( V_15 ) {
F_12 ( L_14 ,
V_13 -> V_27 , V_14 , V_15 ) ;
break;
}
}
return V_15 ;
}
static int F_24 ( struct V_12 * V_13 , struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_9 * V_53 = & V_2 -> V_53 ;
struct V_9 V_72 = { L_15 } ;
struct V_12 * V_73 ;
struct V_32 * V_74 ;
struct V_75 V_76 ;
int V_15 ;
V_73 = F_25 ( & V_4 -> V_21 , V_31 ,
& V_13 -> V_9 ) ;
if ( ! V_73 ) {
F_12 ( L_16 , V_4 -> V_21 . V_10 ) ;
return - V_24 ;
}
F_3 ( V_77 , L_17 ,
V_73 -> V_27 , V_73 -> V_9 . V_10 ,
V_4 -> V_21 . V_10 , V_13 -> V_9 . V_10 , V_53 -> V_10 ) ;
if ( ! V_73 -> V_78 ) {
F_12 ( L_18 , V_4 -> V_21 . V_10 ) ;
return - V_24 ;
}
V_15 = F_26 ( NULL , & V_74 , V_73 , & V_72 ,
& V_2 -> V_40 , NULL ) ;
if ( V_15 ) {
F_12 ( L_19 , V_4 -> V_21 . V_10 , V_15 ) ;
return V_15 ;
}
V_15 = F_27 ( V_73 , V_74 , V_79 ) ;
if ( V_15 )
return V_15 ;
V_76 . V_80 = NULL ;
V_76 . V_81 = V_74 ;
V_76 . V_82 = V_4 -> V_83 ;
F_28 ( & V_2 -> V_84 , & V_76 ) ;
V_15 = F_29 ( V_73 , V_13 ) ;
if ( V_15 ) {
F_30 ( V_74 ) ;
F_12 ( L_20 ,
V_4 -> V_21 . V_10 , V_15 ) ;
return V_15 ;
}
if ( V_13 -> V_50 ) {
V_15 = F_13 ( V_13 -> V_50 , V_74 -> V_33 ,
V_43 ,
( void * ) ( V_4 - V_2 -> V_19 [ 0 ] ) ) ;
if ( V_15 ) {
F_30 ( V_74 ) ;
return V_15 ;
}
}
V_4 -> V_6 = 1 ;
V_4 -> V_20 = V_74 ;
V_2 -> V_7 . V_8 ++ ;
F_23 ( V_4 -> V_20 , V_2 -> V_68 , V_2 -> V_69 ,
V_2 -> V_70 , V_2 -> V_71 ) ;
F_3 ( V_77 , L_21 ,
V_73 -> V_27 , V_73 -> V_9 . V_10 ,
F_31 ( & V_13 -> V_85 ) ) ;
if ( V_2 -> V_59 )
V_15 = F_32 ( V_2 -> V_59 , & V_73 -> V_60 ,
V_73 -> V_27 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 , int V_86 )
{
if ( ! V_2 -> V_19 [ V_86 ] )
return;
F_34 ( V_2 -> V_19 [ V_86 ] ) ;
V_2 -> V_19 [ V_86 ] = NULL ;
return;
}
static int F_35 ( struct V_12 * V_13 , struct V_9 * V_87 ,
T_2 V_86 , int V_88 )
{
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_89 = 0 ;
int V_15 = 0 ;
F_3 ( V_77 , L_22 , V_87 -> V_10 , V_86 ) ;
F_36 ( & V_2 -> V_90 ) ;
if ( V_2 -> V_7 . V_18 == 0 ) {
struct V_12 * V_73 ;
V_73 = F_25 ( V_87 , V_31 ,
& V_13 -> V_9 ) ;
if ( ! V_73 ) {
F_37 ( & V_2 -> V_90 ) ;
F_12 ( L_23 ,
V_13 -> V_27 , V_87 -> V_10 , - V_24 ) ;
return - V_24 ;
}
}
if ( ( V_86 < V_2 -> V_91 ) && V_2 -> V_19 [ V_86 ] ) {
V_4 = V_2 -> V_19 [ V_86 ] ;
F_12 ( L_24 ,
V_13 -> V_27 ,
F_38 ( & V_4 -> V_21 ) , V_86 , - V_92 ) ;
F_37 ( & V_2 -> V_90 ) ;
return - V_92 ;
}
if ( V_86 >= V_2 -> V_91 ) {
struct V_3 * * V_93 , * * V_94 = NULL ;
T_2 V_95 = 1 ;
T_2 V_96 = 0 ;
while ( V_95 < V_86 + 1 )
V_95 <<= 1 ;
V_93 = F_39 ( V_95 , sizeof( * V_93 ) , V_97 ) ;
if ( ! V_93 ) {
F_37 ( & V_2 -> V_90 ) ;
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
F_40 () ;
F_34 ( V_94 ) ;
F_3 ( V_77 , L_25 , V_2 -> V_19 ,
V_2 -> V_91 ) ;
}
V_4 = F_41 ( sizeof( * V_4 ) , V_97 ) ;
if ( ! V_4 ) {
F_37 ( & V_2 -> V_90 ) ;
return - V_98 ;
}
F_42 ( & V_4 -> V_99 ) ;
V_4 -> V_83 = V_86 ;
V_4 -> V_21 = * V_87 ;
V_4 -> V_6 = 0 ;
V_2 -> V_19 [ V_86 ] = V_4 ;
if ( V_86 >= V_2 -> V_7 . V_18 ) {
V_89 = V_2 -> V_7 . V_18 ;
V_2 -> V_7 . V_18 = V_86 + 1 ;
}
if ( V_2 -> V_58 ) {
V_15 = F_24 ( V_13 , V_4 ) ;
if ( V_15 ) {
F_4 ( & V_2 -> V_17 ) ;
if ( V_2 -> V_7 . V_18 == V_86 + 1 )
V_2 -> V_7 . V_18 = V_89 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_8 ( & V_2 -> V_17 ) ;
} else {
int V_63 = sizeof( struct V_100 ) +
V_2 -> V_7 . V_18 * sizeof( struct V_101 ) ;
F_21 ( V_13 -> V_48 , V_63 , 0 , 0 , 0 ) ;
}
}
F_37 ( & V_2 -> V_90 ) ;
return V_15 ;
}
int F_19 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
T_1 V_14 ;
int V_15 ;
int V_63 ;
if ( V_2 -> V_58 )
return 0 ;
F_36 ( & V_2 -> V_90 ) ;
if ( V_2 -> V_58 ) {
F_37 ( & V_2 -> V_90 ) ;
return 0 ;
}
if ( V_2 -> V_7 . V_18 == 0 ) {
F_37 ( & V_2 -> V_90 ) ;
F_12 ( L_26 , V_13 -> V_27 ) ;
return - V_24 ;
}
F_7 ( V_2 -> V_19 ) ;
if ( ! V_2 -> V_19 [ 0 ] ) {
F_37 ( & V_2 -> V_90 ) ;
F_12 ( L_27 ,
V_13 -> V_27 ) ;
return - V_24 ;
}
F_3 ( V_77 , L_28 ,
V_2 -> V_53 . V_10 , V_13 -> V_27 ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( ! V_4 )
continue;
V_15 = F_24 ( V_13 , V_4 ) ;
if ( V_15 )
goto V_102;
}
F_43 ( V_2 -> exp ) ;
V_2 -> V_58 = 1 ;
V_63 = F_44 ( V_2 -> V_7 . V_18 , V_103 ) ;
F_21 ( V_13 -> V_48 , V_63 , 0 , 0 , 0 ) ;
F_37 ( & V_2 -> V_90 ) ;
return 0 ;
V_102:
while ( V_14 -- > 0 ) {
int V_104 ;
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( ! V_4 )
continue;
V_4 -> V_6 = 0 ;
if ( V_4 -> V_20 ) {
-- V_2 -> V_7 . V_8 ;
V_104 = F_30 ( V_4 -> V_20 ) ;
if ( V_104 ) {
F_12 ( L_29 ,
V_4 -> V_21 . V_10 , V_14 , V_104 ) ;
}
}
}
F_45 ( V_2 -> exp ) ;
F_37 ( & V_2 -> V_90 ) ;
return V_15 ;
}
static int F_46 ( struct V_12 * V_13 , struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_12 * V_73 ;
int V_15 ;
V_73 = F_6 ( V_4 -> V_20 ) ;
if ( V_73 ) {
V_73 -> V_105 = V_13 -> V_105 ;
V_73 -> V_106 = V_13 -> V_106 ;
V_73 -> V_107 = V_13 -> V_107 ;
if ( V_2 -> V_59 )
F_47 ( V_2 -> V_59 ,
V_73 -> V_27 ) ;
}
V_15 = F_48 ( V_4 -> V_20 -> V_33 ) ;
if ( V_15 )
F_12 ( L_30 ) ;
F_3 ( V_16 , L_31 ,
V_4 -> V_20 -> V_33 -> V_27 ,
V_4 -> V_20 -> V_33 -> V_9 . V_10 ) ;
F_29 ( V_4 -> V_20 -> V_33 , NULL ) ;
V_15 = F_30 ( V_4 -> V_20 ) ;
if ( V_15 ) {
if ( V_4 -> V_6 ) {
F_12 ( L_32 ,
V_4 -> V_21 . V_10 , V_15 ) ;
}
}
F_1 ( V_2 , V_4 , 0 ) ;
V_4 -> V_20 = NULL ;
return 0 ;
}
static int F_49 ( struct V_32 * exp )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
int V_15 ;
T_1 V_14 ;
if ( ! V_2 -> V_19 )
goto V_108;
V_2 -> V_57 -- ;
if ( V_2 -> V_57 != 0 )
goto V_108;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( ! V_2 -> V_19 [ V_14 ] || ! V_2 -> V_19 [ V_14 ] -> V_20 )
continue;
F_46 ( V_13 , V_2 -> V_19 [ V_14 ] ) ;
}
if ( V_2 -> V_59 )
F_20 ( V_2 -> V_59 ) ;
V_108:
if ( ! V_2 -> V_58 )
F_43 ( exp ) ;
V_15 = F_45 ( exp ) ;
if ( V_2 -> V_57 == 0 )
V_2 -> V_58 = 0 ;
return V_15 ;
}
static int F_50 ( struct V_32 * exp , int V_109 , void * V_110 ,
void T_3 * V_111 )
{
struct V_12 * V_112 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_112 -> V_34 . V_2 ;
struct V_113 * V_114 ;
struct V_3 * V_4 ;
struct V_113 * V_115 = NULL ;
int V_116 = 0 ;
int V_15 ;
V_114 = (struct V_113 * ) V_110 ;
V_4 = F_51 ( V_2 , & V_114 -> V_117 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_118:
V_15 = F_54 ( V_119 , V_4 -> V_20 , V_109 , V_114 , V_111 ) ;
if ( V_15 != 0 && V_15 != - V_120 )
goto V_121;
if ( V_115 ) {
struct V_113 * V_122 ;
char * V_123 ;
V_122 = (struct V_113 * ) V_110 ;
if ( strlen ( V_122 -> V_124 ) +
strlen ( V_114 -> V_124 ) > V_122 -> V_125 ) {
V_15 = - V_126 ;
goto V_121;
}
V_123 = V_122 -> V_124 ;
memmove ( V_123 + strlen ( V_114 -> V_124 ) + 1 , V_123 ,
strlen ( V_122 -> V_124 ) ) ;
strncpy ( V_123 , V_114 -> V_124 , strlen ( V_114 -> V_124 ) ) ;
V_123 += strlen ( V_114 -> V_124 ) ;
* V_123 = '/' ;
}
F_3 ( V_16 , L_33 V_127 L_34 ,
V_4 -> V_20 -> V_33 -> V_27 ,
V_114 -> V_124 , F_55 ( & V_114 -> V_117 ) , V_114 -> V_128 ,
V_114 -> V_129 ) ;
if ( V_15 == 0 )
goto V_121;
if ( ! V_115 ) {
V_116 = sizeof( * V_115 ) + V_130 ;
V_115 = F_41 ( V_116 , V_97 ) ;
if ( ! V_115 ) {
V_15 = - V_98 ;
goto V_121;
}
V_115 -> V_125 = V_130 ;
}
if ( ! F_56 ( & V_114 -> V_117 ) ) {
F_12 ( L_35 V_127 L_36 ,
V_4 -> V_20 -> V_33 -> V_27 ,
F_55 ( & V_114 -> V_117 ) , - V_24 ) ;
V_15 = - V_24 ;
goto V_121;
}
V_4 = F_51 ( V_2 , & V_114 -> V_117 ) ;
if ( F_52 ( V_4 ) ) {
V_15 = - V_24 ;
goto V_121;
}
V_115 -> V_117 = V_114 -> V_117 ;
V_115 -> V_128 = - 1 ;
V_115 -> V_129 = - 1 ;
memset ( V_115 -> V_124 , 0 , V_115 -> V_125 ) ;
V_114 = V_115 ;
goto V_118;
V_121:
F_34 ( V_115 ) ;
return V_15 ;
}
static int F_57 ( struct V_1 * V_2 ,
const struct V_131 * V_132 ,
const struct V_3 * V_133 )
{
T_1 V_14 , V_134 = 0 ;
struct V_3 * V_135 ;
for ( V_14 = 0 ; V_14 < V_132 -> V_136 . V_137 ; V_14 ++ ) {
V_135 = F_51 ( V_2 , & V_132 -> V_138 [ V_14 ] . V_139 ) ;
if ( F_5 ( & V_135 -> V_21 , & V_133 -> V_21 ) )
V_134 ++ ;
}
return V_134 ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_131 * V_140 ,
const struct V_3 * V_133 ,
struct V_131 * V_141 )
{
int V_14 , V_142 ;
struct V_3 * V_135 ;
V_141 -> V_136 = V_140 -> V_136 ;
V_142 = 0 ;
for ( V_14 = 0 ; V_14 < V_140 -> V_136 . V_137 ; V_14 ++ ) {
V_135 = F_51 ( V_2 ,
& V_140 -> V_138 [ V_14 ] . V_139 ) ;
if ( F_5 ( & V_135 -> V_21 , & V_133 -> V_21 ) ) {
V_141 -> V_138 [ V_142 ] =
V_140 -> V_138 [ V_14 ] ;
V_142 ++ ;
}
}
V_141 -> V_136 . V_137 = V_142 ;
memcpy ( F_59 ( V_141 ) , F_59 ( V_140 ) ,
V_140 -> V_136 . V_143 ) ;
}
static int F_60 ( struct V_1 * V_2 , unsigned int V_144 , int V_109 ,
struct V_145 * V_146 ,
void T_3 * V_111 )
{
int V_15 = 0 ;
T_2 V_14 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
struct V_3 * V_4 = V_2 -> V_19 [ V_14 ] ;
if ( ! V_4 || ! V_4 -> V_20 )
continue;
F_54 ( V_144 , V_2 -> V_19 [ V_14 ] -> V_20 , V_109 , V_146 , V_111 ) ;
}
V_15 = F_61 ( V_146 -> V_147 , V_146 -> V_148 ) ;
return V_15 ;
}
static int F_62 ( struct V_1 * V_2 , unsigned int V_144 , int V_109 ,
struct V_145 * V_146 , void T_3 * V_111 )
{
struct V_149 * V_150 ;
T_2 V_14 , V_151 ;
int V_152 , V_15 = 0 ;
bool V_153 = false ;
struct V_154 V_155 = { 0 } ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
struct V_3 * V_4 = V_2 -> V_19 [ V_14 ] ;
if ( ! V_4 || ! V_4 -> V_20 )
continue;
V_152 = F_54 ( V_144 , V_4 -> V_20 , V_109 , V_146 , V_111 ) ;
if ( V_152 ) {
if ( V_4 -> V_6 ) {
F_12 ( L_37 ,
V_4 -> V_21 . V_10 , V_14 , V_144 , V_152 ) ;
V_15 = V_152 ;
V_146 -> V_156 |= V_157 ;
for ( V_151 = 0 ; V_151 < V_14 ; V_151 ++ ) {
V_4 = V_2 -> V_19 [ V_151 ] ;
if ( ! V_4 || ! V_4 -> V_20 )
continue;
F_54 ( V_144 , V_4 -> V_20 , V_109 ,
V_146 , V_111 ) ;
}
return V_15 ;
}
} else {
V_153 = true ;
}
}
if ( ! V_153 )
return - V_26 ;
V_150 = F_63 ( V_146 -> V_158 ) ;
if ( ! V_150 )
return - V_159 ;
V_155 . V_160 = V_161 ;
V_155 . V_162 = V_2 -> V_53 ;
V_155 . V_163 = V_146 -> V_164 ;
V_15 = F_64 ( V_150 , V_146 -> V_147 , V_146 -> V_148 ,
& V_155 , sizeof( V_155 ) ) ;
if ( V_15 )
F_65 ( V_150 ) ;
return V_15 ;
}
static int F_66 ( unsigned int V_144 , struct V_32 * exp ,
int V_109 , void * V_110 , void T_3 * V_111 )
{
struct V_12 * V_112 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_112 -> V_34 . V_2 ;
struct V_3 * V_4 = NULL ;
T_1 V_14 = 0 ;
int V_15 = 0 ;
int V_165 = 0 ;
T_1 V_166 = V_2 -> V_7 . V_18 ;
if ( V_166 == 0 )
return - V_167 ;
switch ( V_144 ) {
case V_168 : {
struct V_169 * V_38 = V_110 ;
struct V_12 * V_73 ;
struct V_170 V_171 = { 0 } ;
T_2 V_86 ;
memcpy ( & V_86 , V_38 -> V_172 , sizeof( T_2 ) ) ;
if ( V_86 >= V_166 )
return - V_173 ;
V_4 = V_2 -> V_19 [ V_86 ] ;
if ( ! V_4 || ! V_4 -> V_6 )
return - V_174 ;
V_73 = F_6 ( V_4 -> V_20 ) ;
if ( ! V_73 )
return - V_24 ;
if ( F_67 ( V_38 -> V_175 , F_68 ( V_73 ) ,
F_69 ( ( int ) V_38 -> V_176 ,
( int ) sizeof( struct V_9 ) ) ) )
return - V_177 ;
V_15 = V_170 ( NULL , V_4 -> V_20 , & V_171 ,
F_70 ( - V_178 ) ,
0 ) ;
if ( V_15 )
return V_15 ;
if ( F_67 ( V_38 -> V_179 , & V_171 ,
F_69 ( ( int ) V_38 -> V_180 ,
( int ) sizeof( V_171 ) ) ) )
return - V_177 ;
break;
}
case V_181 : {
struct V_182 * V_183 = V_110 ;
struct V_184 * V_185 ;
if ( V_183 -> V_186 == V_187 ) {
if ( V_166 <= V_183 -> V_188 )
return - V_24 ;
V_4 = V_2 -> V_19 [ V_183 -> V_188 ] ;
if ( ! V_4 || ! V_4 -> V_20 )
return - V_24 ;
} else if ( V_183 -> V_186 == V_189 ) {
for ( V_14 = 0 ; V_14 < V_166 ; V_14 ++ ) {
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( ! V_4 )
continue;
if ( ! F_5 ( & V_4 -> V_21 ,
& V_183 -> V_9 ) )
continue;
if ( ! V_4 -> V_20 )
return - V_24 ;
break;
}
} else {
return - V_24 ;
}
if ( V_14 >= V_166 )
return - V_190 ;
F_7 ( V_4 && V_4 -> V_20 ) ;
V_185 = F_41 ( sizeof( * V_185 ) , V_97 ) ;
if ( ! V_185 )
return - V_98 ;
F_71 ( V_185 , V_183 ) ;
V_15 = V_184 ( V_4 -> V_20 , V_185 ) ;
if ( V_15 == 0 ) {
F_71 ( V_183 , V_185 ) ;
V_183 -> V_186 = V_187 ;
V_183 -> V_9 = V_4 -> V_21 ;
}
F_34 ( V_185 ) ;
break;
}
case V_191 :
case V_192 : {
struct V_193 * V_194 = V_110 ;
if ( V_194 -> V_195 >= V_166 )
return - V_173 ;
V_4 = V_2 -> V_19 [ V_194 -> V_195 ] ;
if ( ! V_4 || ! V_4 -> V_20 || ! V_4 -> V_6 )
return - V_173 ;
V_15 = F_54 ( V_144 , V_4 -> V_20 , sizeof( * V_194 ) , V_194 , NULL ) ;
break;
}
case V_196 : {
V_4 = V_2 -> V_19 [ 0 ] ;
if ( ! V_4 || ! V_4 -> V_20 )
return - V_174 ;
V_15 = F_54 ( V_144 , V_4 -> V_20 , V_109 , V_110 , V_111 ) ;
break;
}
case V_197 : {
struct V_101 * V_198 = V_110 ;
int V_199 ;
V_15 = F_72 ( V_2 , V_198 , & V_199 ) ;
if ( V_15 )
return V_15 ;
* ( T_2 * ) V_111 = V_199 ;
break;
}
case V_119 : {
V_15 = F_50 ( exp , V_109 , V_110 , V_111 ) ;
break;
}
case V_200 :
case V_201 :
case V_202 : {
struct V_203 * V_204 = V_110 ;
V_4 = F_51 ( V_2 , & V_204 -> V_205 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
if ( ! V_4 -> V_20 )
return - V_24 ;
V_15 = F_54 ( V_144 , V_4 -> V_20 , V_109 , V_110 , V_111 ) ;
break;
}
case V_206 : {
const struct V_207 * V_208 = V_110 ;
V_4 = F_51 ( V_2 , & V_208 -> V_209 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_15 = F_54 ( V_144 , V_4 -> V_20 , V_109 , V_110 , V_111 ) ;
break;
}
case V_210 : {
struct V_131 * V_132 = V_110 ;
unsigned int V_211 = V_132 -> V_136 . V_137 ;
if ( V_211 == 0 )
return 0 ;
if ( V_211 == 1 || V_166 == 1 ) {
V_4 = F_51 ( V_2 ,
& V_132 -> V_138 [ 0 ] . V_139 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_15 = F_54 ( V_144 , V_4 -> V_20 , V_109 , V_110 , V_111 ) ;
} else {
for ( V_14 = 0 ; V_14 < V_166 ; V_14 ++ ) {
unsigned int V_134 , V_212 ;
int V_213 ;
struct V_131 * V_214 ;
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( ! V_4 || ! V_4 -> V_20 )
continue;
V_134 = F_57 ( V_2 , V_132 , V_4 ) ;
if ( V_134 == 0 )
continue;
V_212 = F_73 ( F_74 ( * V_132 ) ,
V_138 [ V_134 ] )
+ V_132 -> V_136 . V_143 ;
V_214 = F_75 ( V_212 , V_97 ) ;
if ( ! V_214 )
return - V_98 ;
F_58 ( V_2 , V_132 , V_4 , V_214 ) ;
V_213 = F_54 ( V_144 , V_4 -> V_20 , V_212 ,
V_214 , V_111 ) ;
if ( V_213 != 0 && V_15 == 0 )
V_15 = V_213 ;
F_76 ( V_214 ) ;
}
}
break;
}
case V_215 : {
struct V_203 * V_204 = V_110 ;
struct V_3 * V_216 , * V_217 ;
V_216 = F_51 ( V_2 , & V_204 -> V_205 ) ;
if ( F_52 ( V_216 ) )
return F_53 ( V_216 ) ;
V_217 = F_51 ( V_2 , & V_204 -> V_218 ) ;
if ( F_52 ( V_217 ) )
return F_53 ( V_217 ) ;
if ( ! V_216 -> V_20 || ! V_217 -> V_20 )
return - V_24 ;
if ( V_216 -> V_83 != V_217 -> V_83 )
return - V_219 ;
V_15 = F_54 ( V_144 , V_216 -> V_20 , V_109 , V_110 , V_111 ) ;
break;
}
case V_220 : {
struct V_145 * V_146 = V_110 ;
if ( V_146 -> V_156 & V_157 )
V_15 = F_60 ( V_2 , V_144 , V_109 , V_146 , V_111 ) ;
else
V_15 = F_62 ( V_2 , V_144 , V_109 , V_146 , V_111 ) ;
break;
}
default:
for ( V_14 = 0 ; V_14 < V_166 ; V_14 ++ ) {
struct V_12 * V_73 ;
int V_152 ;
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( ! V_4 || ! V_4 -> V_20 )
continue;
V_73 = F_6 ( V_4 -> V_20 ) ;
V_73 -> V_105 = V_112 -> V_105 ;
V_152 = F_54 ( V_144 , V_4 -> V_20 , V_109 , V_110 , V_111 ) ;
if ( V_152 == - V_174 && V_144 == V_221 ) {
return V_152 ;
} else if ( V_152 ) {
if ( V_4 -> V_6 ) {
F_12 ( L_37 ,
V_4 -> V_21 . V_10 , V_14 , V_144 , V_152 ) ;
if ( ! V_15 )
V_15 = V_152 ;
}
} else {
V_165 = 1 ;
}
}
if ( ! V_165 && ! V_15 )
V_15 = - V_222 ;
}
return V_15 ;
}
static int F_77 ( struct V_12 * V_13 ,
struct V_203 * V_204 , T_1 * V_223 )
{
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
F_7 ( V_223 ) ;
if ( V_2 -> V_7 . V_18 == 1 ) {
* V_223 = 0 ;
return 0 ;
}
if ( V_204 -> V_224 != - 1 ) {
* V_223 = V_204 -> V_224 ;
return 0 ;
}
if ( V_204 -> V_225 & V_226 && V_204 -> V_204 ) {
struct V_227 * V_228 ;
V_228 = V_204 -> V_204 ;
if ( F_78 ( V_228 -> V_229 ) != ( T_2 ) - 1 ) {
* V_223 = F_78 ( V_228 -> V_229 ) ;
} else {
* V_223 = V_204 -> V_230 ;
V_228 -> V_229 = F_79 ( V_204 -> V_230 ) ;
}
} else {
* V_223 = V_204 -> V_230 ;
}
return 0 ;
}
int F_80 ( struct V_1 * V_2 , struct V_101 * V_198 , T_1 V_223 )
{
struct V_3 * V_4 ;
int V_15 ;
V_4 = F_81 ( V_2 , V_223 , NULL ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
F_36 ( & V_4 -> V_99 ) ;
if ( V_4 -> V_6 == 0 || ! V_4 -> V_20 ) {
V_15 = - V_173 ;
goto V_231;
}
V_15 = F_82 ( NULL , V_4 -> V_20 , V_198 , NULL ) ;
if ( V_15 > 0 ) {
F_7 ( F_56 ( V_198 ) ) ;
V_15 = 0 ;
}
V_231:
F_37 ( & V_4 -> V_99 ) ;
return V_15 ;
}
int F_83 ( const struct V_51 * V_52 , struct V_32 * exp ,
struct V_101 * V_198 , struct V_203 * V_204 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
T_1 V_223 = 0 ;
int V_15 ;
F_7 ( V_204 ) ;
F_7 ( V_198 ) ;
V_15 = F_77 ( V_13 , V_204 , & V_223 ) ;
if ( V_15 ) {
F_12 ( L_38 ,
V_15 ) ;
return V_15 ;
}
V_15 = F_80 ( V_2 , V_198 , V_223 ) ;
if ( V_15 ) {
F_12 ( L_39 , V_15 ) ;
return V_15 ;
}
return V_15 ;
}
static int F_84 ( struct V_12 * V_13 , struct V_232 * V_233 )
{
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_234 V_235 = { NULL } ;
struct V_236 * V_7 ;
int V_15 ;
if ( F_85 ( V_233 , 1 ) < 1 ) {
F_12 ( L_40 ) ;
return - V_24 ;
}
V_7 = (struct V_236 * ) F_86 ( V_233 , 1 ) ;
if ( sizeof( * V_7 ) > F_85 ( V_233 , 1 ) ) {
F_12 ( L_41 ,
( int ) sizeof( * V_7 ) , F_85 ( V_233 , 1 ) ) ;
return - V_24 ;
}
V_2 -> V_91 = 32U ;
V_2 -> V_19 = F_39 ( V_2 -> V_91 , sizeof( * V_2 -> V_19 ) , V_97 ) ;
if ( ! V_2 -> V_19 )
return - V_98 ;
F_87 ( & V_2 -> V_7 . V_237 , V_7 -> V_237 . V_10 ) ;
V_2 -> V_7 . V_18 = 0 ;
V_2 -> V_7 . V_8 = 0 ;
V_2 -> V_70 = 0 ;
V_2 -> V_69 = 0 ;
V_2 -> V_68 = 0 ;
V_2 -> V_238 = V_239 ;
F_88 ( & V_2 -> V_17 ) ;
F_42 ( & V_2 -> V_90 ) ;
F_89 ( & V_235 ) ;
F_90 ( V_13 , V_235 . V_240 , V_235 . V_241 ) ;
V_15 = F_91 ( V_13 -> V_242 , L_42 ,
0444 , & V_243 , V_13 ) ;
if ( V_15 )
F_22 ( L_43 ,
V_13 -> V_27 , V_15 ) ;
V_15 = F_92 ( & V_2 -> V_84 , V_13 -> V_27 ,
V_244 ) ;
if ( V_15 ) {
F_12 ( L_44 , V_15 ) ;
goto V_231;
}
return 0 ;
V_231:
return V_15 ;
}
static int F_93 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
F_94 ( & V_2 -> V_84 ) ;
if ( V_2 -> V_19 ) {
int V_14 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( ! V_2 -> V_19 [ V_14 ] )
continue;
F_33 ( V_2 , V_14 ) ;
}
F_34 ( V_2 -> V_19 ) ;
V_2 -> V_91 = 0 ;
}
return 0 ;
}
static int F_95 ( struct V_12 * V_13 , T_1 V_109 , void * V_245 )
{
struct V_232 * V_233 = V_245 ;
struct V_9 V_9 ;
int V_88 ;
T_2 V_86 ;
int V_15 ;
switch ( V_233 -> V_246 ) {
case V_247 :
if ( F_85 ( V_233 , 1 ) > sizeof( V_9 . V_10 ) ) {
V_15 = - V_24 ;
goto V_231;
}
F_87 ( & V_9 , F_86 ( V_233 , 1 ) ) ;
if ( sscanf ( F_86 ( V_233 , 2 ) , L_45 , & V_86 ) != 1 ) {
V_15 = - V_24 ;
goto V_231;
}
if ( sscanf ( F_86 ( V_233 , 3 ) , L_46 , & V_88 ) != 1 ) {
V_15 = - V_24 ;
goto V_231;
}
V_15 = F_35 ( V_13 , & V_9 , V_86 , V_88 ) ;
goto V_231;
default:
F_12 ( L_47 , V_233 -> V_246 ) ;
V_15 = - V_24 ;
goto V_231;
}
V_231:
return V_15 ;
}
static int F_96 ( const struct V_51 * V_52 , struct V_32 * exp ,
struct V_170 * V_248 , T_4 V_249 , T_2 V_250 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_170 * V_251 ;
int V_15 = 0 ;
T_1 V_14 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_251 = F_41 ( sizeof( * V_251 ) , V_97 ) ;
if ( ! V_251 )
return - V_98 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( ! V_2 -> V_19 [ V_14 ] || ! V_2 -> V_19 [ V_14 ] -> V_20 )
continue;
V_15 = V_170 ( V_52 , V_2 -> V_19 [ V_14 ] -> V_20 , V_251 ,
V_249 , V_250 ) ;
if ( V_15 ) {
F_12 ( L_48 , V_14 ,
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
F_34 ( V_251 ) ;
return V_15 ;
}
static int F_97 ( struct V_32 * exp ,
struct V_101 * V_198 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_98 ( V_2 -> V_19 [ 0 ] -> V_20 , V_198 ) ;
return V_15 ;
}
static int F_99 ( struct V_32 * exp , const struct V_101 * V_198 ,
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
V_4 = F_51 ( V_2 , V_198 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_15 = F_100 ( V_4 -> V_20 , V_198 , V_258 , V_259 , V_260 ,
V_261 , V_262 , V_250 , V_264 ) ;
return V_15 ;
}
static int F_101 ( struct V_32 * exp , const struct V_101 * V_198 ,
T_5 V_258 , const char * V_259 ,
const char * V_260 , int V_261 , int V_262 ,
int V_250 , T_2 V_265 ,
struct V_263 * * V_264 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_51 ( V_2 , V_198 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_15 = F_102 ( V_4 -> V_20 , V_198 , V_258 , V_259 , V_260 ,
V_261 , V_262 , V_250 , V_265 ,
V_264 ) ;
return V_15 ;
}
static int F_103 ( struct V_32 * exp , struct V_203 * V_204 ,
struct V_263 * * V_264 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_51 ( V_2 , & V_204 -> V_205 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
if ( V_204 -> V_266 & V_267 ) {
V_204 -> V_230 = V_4 -> V_83 ;
return 0 ;
}
V_15 = F_104 ( V_4 -> V_20 , V_204 , V_264 ) ;
return V_15 ;
}
static int F_105 ( struct V_32 * exp , const struct V_101 * V_198 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
T_1 V_14 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_268 , L_49 V_127 L_50 , F_55 ( V_198 ) ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
if ( ! V_2 -> V_19 [ V_14 ] || ! V_2 -> V_19 [ V_14 ] -> V_20 )
continue;
F_106 ( V_2 -> V_19 [ V_14 ] -> V_20 , V_198 ) ;
}
return 0 ;
}
static int F_107 ( struct V_32 * exp , struct V_203 * V_204 ,
struct V_269 * V_270 , struct V_263 * * V_264 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_51 ( V_2 , & V_204 -> V_205 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
F_3 ( V_268 , L_51 V_127 L_50 , F_55 ( & V_204 -> V_205 ) ) ;
V_15 = F_108 ( V_4 -> V_20 , V_204 , V_270 , V_264 ) ;
return V_15 ;
}
static struct V_3 *
F_109 ( struct V_1 * V_2 , struct V_100 * V_271 ,
const char * V_259 , int V_272 , struct V_101 * V_198 ,
T_1 * V_223 )
{
const struct V_273 * V_274 ;
struct V_3 * V_4 ;
if ( F_110 ( V_275 ) ) {
if ( V_276 >= V_271 -> V_277 )
return F_111 ( - V_159 ) ;
V_274 = & V_271 -> V_278 [ V_276 ] ;
} else {
V_274 = F_112 ( V_271 , V_259 , V_272 ) ;
if ( F_52 ( V_274 ) )
return F_113 ( V_274 ) ;
}
if ( V_198 )
* V_198 = V_274 -> V_279 ;
if ( V_223 )
* V_223 = V_274 -> V_280 ;
V_4 = F_81 ( V_2 , V_274 -> V_280 , NULL ) ;
F_3 ( V_16 , L_52 V_127 L_50 , V_274 -> V_280 ,
F_55 ( & V_274 -> V_279 ) ) ;
return V_4 ;
}
struct V_3 *
F_114 ( struct V_1 * V_2 , struct V_203 * V_204 ,
struct V_101 * V_198 )
{
struct V_100 * V_271 = V_204 -> V_281 ;
struct V_3 * V_4 ;
if ( V_204 -> V_282 & V_283 &&
( int ) V_204 -> V_230 != - 1 && V_271 ) {
int V_14 ;
V_4 = F_81 ( V_2 , V_204 -> V_230 , NULL ) ;
if ( F_52 ( V_4 ) )
return V_4 ;
for ( V_14 = 0 ; V_14 < V_271 -> V_277 ; V_14 ++ ) {
struct V_273 * V_274 ;
V_274 = & V_271 -> V_278 [ V_14 ] ;
if ( V_274 -> V_280 == V_204 -> V_230 ) {
* V_198 = V_274 -> V_279 ;
break;
}
}
if ( V_14 == V_271 -> V_277 )
V_4 = F_111 ( - V_24 ) ;
return V_4 ;
}
if ( ! V_271 || ! V_204 -> V_284 ) {
V_4 = F_51 ( V_2 , V_198 ) ;
if ( F_52 ( V_4 ) )
return V_4 ;
V_204 -> V_230 = V_4 -> V_83 ;
return V_4 ;
}
return F_109 ( V_2 , V_271 , V_204 -> V_285 ,
V_204 -> V_284 , V_198 ,
& V_204 -> V_230 ) ;
}
static int F_115 ( struct V_32 * exp , struct V_203 * V_204 ,
const void * V_38 , T_6 V_286 , T_7 V_287 ,
T_8 V_288 , T_9 V_289 , T_10 V_290 ,
T_4 V_291 , struct V_263 * * V_264 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
if ( ! V_2 -> V_7 . V_8 )
return - V_222 ;
V_4 = F_114 ( V_2 , V_204 , & V_204 -> V_205 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
F_3 ( V_268 , L_53 V_127 L_54 ,
( int ) V_204 -> V_284 , V_204 -> V_285 ,
F_55 ( & V_204 -> V_205 ) , V_204 -> V_230 ) ;
V_15 = F_83 ( NULL , exp , & V_204 -> V_218 , V_204 ) ;
if ( V_15 )
return V_15 ;
if ( F_116 ( exp ) & V_292 ) {
V_4 = F_51 ( V_2 , & V_204 -> V_218 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_204 -> V_230 = V_4 -> V_83 ;
} else {
F_3 ( V_77 , L_55 ) ;
}
F_3 ( V_268 , L_56 V_127 L_54 ,
F_55 ( & V_204 -> V_205 ) , V_204 -> V_230 ) ;
V_204 -> V_266 |= V_293 ;
V_15 = F_117 ( V_4 -> V_20 , V_204 , V_38 , V_286 , V_287 , V_288 , V_289 ,
V_290 , V_291 , V_264 ) ;
if ( V_15 == 0 ) {
if ( ! * V_264 )
return V_15 ;
F_3 ( V_268 , L_57 V_127 L_50 , F_55 ( & V_204 -> V_218 ) ) ;
}
return V_15 ;
}
static int F_118 ( struct V_32 * exp ,
struct V_203 * V_204 ,
struct V_269 * V_270 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_51 ( V_2 , & V_204 -> V_205 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_15 = F_119 ( V_4 -> V_20 , V_204 , V_270 ) ;
return V_15 ;
}
static int
F_120 ( struct V_32 * exp , struct V_294 * V_295 ,
const T_11 * V_296 ,
struct V_297 * V_298 , struct V_203 * V_204 ,
struct V_55 * V_299 , T_4 V_300 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_268 , L_58 V_127 L_50 ,
F_121 ( V_298 ) , F_55 ( & V_204 -> V_205 ) ) ;
V_4 = F_114 ( V_2 , V_204 , & V_204 -> V_205 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
F_3 ( V_268 , L_58 V_127 L_59 ,
F_121 ( V_298 ) , F_55 ( & V_204 -> V_205 ) , V_4 -> V_83 ) ;
V_15 = F_122 ( V_4 -> V_20 , V_295 , V_296 , V_298 , V_204 , V_299 ,
V_300 ) ;
return V_15 ;
}
static int
F_123 ( struct V_32 * exp , struct V_203 * V_204 ,
struct V_263 * * V_301 )
{
struct V_263 * V_214 = NULL ;
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
struct V_302 * V_303 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_114 ( V_2 , V_204 , & V_204 -> V_205 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
F_3 ( V_268 , L_60 V_127 L_59 ,
( int ) V_204 -> V_284 , V_204 -> V_285 ,
F_55 ( & V_204 -> V_205 ) , V_4 -> V_83 ) ;
V_15 = F_124 ( V_4 -> V_20 , V_204 , V_301 ) ;
if ( V_15 != 0 )
return V_15 ;
V_303 = F_125 ( & ( * V_301 ) -> V_304 , & V_305 ) ;
if ( V_303 -> V_306 & V_307 ) {
struct V_101 V_308 = V_303 -> V_309 ;
F_3 ( V_268 , L_61 V_127 L_50 ,
F_55 ( & V_308 ) ) ;
V_4 = F_51 ( V_2 , & V_308 ) ;
if ( F_52 ( V_4 ) ) {
F_126 ( * V_301 ) ;
* V_301 = NULL ;
return F_53 ( V_4 ) ;
}
V_204 -> V_205 = V_308 ;
V_204 -> V_310 |= V_311 ;
V_204 -> V_284 = 0 ;
V_204 -> V_285 = NULL ;
V_15 = F_124 ( V_4 -> V_20 , V_204 , & V_214 ) ;
F_126 ( * V_301 ) ;
* V_301 = V_214 ;
}
return V_15 ;
}
static int F_127 ( struct V_32 * exp , struct V_3 * V_4 ,
struct V_203 * V_204 , int V_312 ,
enum V_313 V_287 , int V_314 , int V_315 )
{
struct V_101 * V_198 = F_128 ( V_204 , V_315 ) ;
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
T_11 V_296 = { { 0 } } ;
int V_15 = 0 ;
if ( ! F_56 ( V_198 ) )
return 0 ;
if ( ! V_4 ) {
V_4 = F_51 ( V_2 , V_198 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
}
if ( V_4 -> V_83 != V_312 ) {
F_3 ( V_268 , L_62 V_127 L_50 , F_55 ( V_198 ) ) ;
V_296 . V_316 . V_314 = V_314 ;
V_15 = F_129 ( V_4 -> V_20 , V_198 , & V_296 ,
V_287 , V_317 , NULL ) ;
} else {
F_3 ( V_268 ,
L_63 V_127 L_50 ,
V_312 , F_55 ( V_198 ) ) ;
V_204 -> V_266 |= V_315 ;
V_15 = 0 ;
}
return V_15 ;
}
static int F_130 ( struct V_32 * exp , struct V_203 * V_204 ,
struct V_263 * * V_264 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_7 ( V_204 -> V_284 != 0 ) ;
F_3 ( V_268 , L_64 V_127 L_65 V_127 L_50 ,
F_55 ( & V_204 -> V_218 ) , ( int ) V_204 -> V_284 ,
V_204 -> V_285 , F_55 ( & V_204 -> V_205 ) ) ;
V_204 -> V_318 = F_131 ( & V_319 , F_132 () ) ;
V_204 -> V_320 = F_133 ( & V_319 , F_134 () ) ;
V_204 -> V_321 = F_135 () ;
if ( V_204 -> V_322 ) {
struct V_100 * V_271 = V_204 -> V_322 ;
const struct V_273 * V_274 ;
V_274 = F_112 ( V_271 , V_204 -> V_285 ,
V_204 -> V_284 ) ;
if ( F_52 ( V_274 ) )
return F_53 ( V_274 ) ;
V_204 -> V_218 = V_274 -> V_279 ;
}
V_4 = F_114 ( V_2 , V_204 , & V_204 -> V_218 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_204 -> V_266 |= V_323 ;
V_15 = F_127 ( exp , NULL , V_204 , V_4 -> V_83 , V_324 ,
V_325 , V_293 ) ;
if ( V_15 != 0 )
return V_15 ;
V_15 = F_136 ( V_4 -> V_20 , V_204 , V_264 ) ;
return V_15 ;
}
static int F_137 ( struct V_32 * exp , struct V_203 * V_204 ,
const char * V_94 , T_6 V_326 ,
const char * V_327 , T_6 V_328 ,
struct V_263 * * V_264 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_329 ;
int V_15 ;
F_7 ( V_326 != 0 ) ;
F_3 ( V_268 , L_66 V_127 L_67 V_127 L_68 ,
( int ) V_326 , V_94 , F_55 ( & V_204 -> V_205 ) ,
V_204 -> V_281 ? V_204 -> V_281 -> V_277 : 0 ,
( int ) V_328 , V_327 , F_55 ( & V_204 -> V_218 ) ,
V_204 -> V_322 ? V_204 -> V_322 -> V_277 : 0 ) ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_204 -> V_318 = F_131 ( & V_319 , F_132 () ) ;
V_204 -> V_320 = F_133 ( & V_319 , F_134 () ) ;
V_204 -> V_321 = F_135 () ;
if ( V_204 -> V_225 & V_330 ) {
F_138 ( F_56 ( & V_204 -> V_331 ) , L_69 V_127 L_50 ,
F_55 ( & V_204 -> V_331 ) ) ;
if ( V_204 -> V_281 ) {
struct V_100 * V_271 = V_204 -> V_281 ;
struct V_3 * V_332 ;
V_332 = F_109 ( V_2 , V_271 , V_94 ,
V_326 ,
& V_204 -> V_205 ,
NULL ) ;
if ( F_52 ( V_332 ) )
return F_53 ( V_332 ) ;
}
V_15 = F_83 ( NULL , exp , & V_204 -> V_218 , V_204 ) ;
if ( V_15 )
return V_15 ;
V_329 = F_51 ( V_2 , & V_204 -> V_331 ) ;
} else {
if ( V_204 -> V_281 ) {
struct V_100 * V_271 = V_204 -> V_281 ;
V_329 = F_109 ( V_2 , V_271 , V_94 ,
V_326 ,
& V_204 -> V_205 ,
& V_204 -> V_230 ) ;
if ( F_52 ( V_329 ) )
return F_53 ( V_329 ) ;
} else {
V_329 = F_51 ( V_2 , & V_204 -> V_205 ) ;
if ( F_52 ( V_329 ) )
return F_53 ( V_329 ) ;
V_204 -> V_230 = V_329 -> V_83 ;
}
if ( V_204 -> V_322 ) {
struct V_100 * V_271 = V_204 -> V_322 ;
const struct V_273 * V_274 ;
V_274 = F_112 ( V_271 , V_327 , V_328 ) ;
if ( F_52 ( V_274 ) )
return F_53 ( V_274 ) ;
V_204 -> V_218 = V_274 -> V_279 ;
}
}
if ( F_52 ( V_329 ) )
return F_53 ( V_329 ) ;
V_204 -> V_266 |= V_293 | V_333 ;
V_15 = F_127 ( exp , NULL , V_204 , V_329 -> V_83 ,
V_324 , V_325 ,
V_323 ) ;
if ( V_15 )
return V_15 ;
if ( F_56 ( & V_204 -> V_331 ) ) {
struct V_3 * V_4 ;
V_4 = F_51 ( V_2 , & V_204 -> V_205 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_15 = F_127 ( exp , V_4 , V_204 , V_329 -> V_83 ,
V_324 , V_334 ,
V_333 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_127 ( exp , NULL , V_204 , V_329 -> V_83 ,
V_324 , V_335 ,
V_333 ) ;
if ( V_15 )
return V_15 ;
}
if ( F_56 ( & V_204 -> V_336 ) )
V_15 = F_127 ( exp , NULL , V_204 , V_329 -> V_83 ,
V_324 , V_335 ,
V_337 ) ;
F_3 ( V_268 , V_127 L_70 V_127 L_50 , F_55 ( & V_204 -> V_205 ) ,
V_204 -> V_230 , F_55 ( & V_204 -> V_218 ) ) ;
V_15 = F_139 ( V_329 -> V_20 , V_204 , V_94 , V_326 ,
V_327 , V_328 , V_264 ) ;
return V_15 ;
}
static int F_140 ( struct V_32 * exp , struct V_203 * V_204 ,
void * V_338 , T_6 V_339 , void * V_340 , T_6 V_341 ,
struct V_263 * * V_264 ,
struct V_269 * * V_270 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_268 , L_71 V_127 L_72 ,
F_55 ( & V_204 -> V_205 ) , V_204 -> V_342 . V_343 ) ;
V_204 -> V_266 |= V_293 ;
V_4 = F_51 ( V_2 , & V_204 -> V_205 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_15 = F_141 ( V_4 -> V_20 , V_204 , V_338 , V_339 , V_340 ,
V_341 , V_264 , V_270 ) ;
return V_15 ;
}
static int F_142 ( struct V_32 * exp , const struct V_101 * V_198 ,
struct V_263 * * V_264 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_51 ( V_2 , V_198 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_15 = F_143 ( V_4 -> V_20 , V_198 , V_264 ) ;
return V_15 ;
}
static int F_144 ( struct V_32 * exp ,
struct V_203 * V_204 ,
struct V_344 * V_345 ,
T_4 V_346 , int * V_347 ,
struct V_348 * * V_349 ,
struct V_350 * * V_351 )
{
struct V_100 * V_271 = V_204 -> V_281 ;
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_348 * V_352 = NULL ;
struct V_350 * V_353 = NULL ;
struct V_3 * V_4 ;
int V_354 ;
int V_355 = 0 ;
int V_15 = 0 ;
int V_14 ;
V_354 = V_271 -> V_277 ;
for ( V_14 = 0 ; V_14 < V_354 ; V_14 ++ ) {
T_4 V_356 = V_346 ;
struct V_348 * V_357 = NULL ;
struct V_350 * V_350 = NULL ;
struct V_358 * V_359 ;
V_4 = F_81 ( V_2 , V_271 -> V_278 [ V_14 ] . V_280 , NULL ) ;
if ( F_52 ( V_4 ) ) {
V_15 = F_53 ( V_4 ) ;
goto V_231;
}
V_204 -> V_205 = V_271 -> V_278 [ V_14 ] . V_279 ;
V_204 -> V_218 = V_271 -> V_278 [ V_14 ] . V_279 ;
V_204 -> V_204 = V_271 -> V_278 [ V_14 ] . V_360 ;
V_361:
V_15 = F_145 ( V_4 -> V_20 , V_204 , V_345 , V_356 ,
& V_350 ) ;
if ( V_15 )
goto V_231;
V_359 = F_146 ( V_350 ) ;
for ( V_357 = F_147 ( V_359 ) ; V_357 ;
V_357 = F_148 ( V_357 ) ) {
if ( ! F_149 ( V_357 -> V_362 ) )
continue;
if ( F_150 ( V_357 -> V_363 ) < V_346 )
continue;
if ( F_150 ( V_357 -> V_363 ) == V_346 &&
( * V_349 == V_357 || V_14 < * V_347 ) )
continue;
if ( V_14 && ( ! strncmp ( V_357 -> V_364 , L_73 ,
F_149 ( V_357 -> V_362 ) ) ||
! strncmp ( V_357 -> V_364 , L_74 ,
F_149 ( V_357 -> V_362 ) ) ) )
continue;
break;
}
if ( ! V_357 ) {
V_356 = F_150 ( V_359 -> V_365 ) ;
F_151 ( V_350 ) ;
F_152 ( V_350 ) ;
V_350 = NULL ;
if ( V_356 == V_366 )
continue;
else
goto V_361;
}
if ( V_352 ) {
if ( F_150 ( V_352 -> V_363 ) >
F_150 ( V_357 -> V_363 ) ) {
V_352 = V_357 ;
F_151 ( V_353 ) ;
F_152 ( V_353 ) ;
V_355 = V_14 ;
V_353 = V_350 ;
} else {
F_151 ( V_350 ) ;
F_152 ( V_350 ) ;
V_350 = NULL ;
}
} else {
V_352 = V_357 ;
V_353 = V_350 ;
V_355 = V_14 ;
}
}
V_231:
if ( * V_351 ) {
F_151 ( * V_351 ) ;
F_152 ( * V_351 ) ;
}
* V_347 = V_355 ;
* V_349 = V_352 ;
* V_351 = V_353 ;
return V_15 ;
}
static int F_153 ( struct V_32 * exp ,
struct V_203 * V_204 ,
struct V_344 * V_345 ,
T_4 V_367 , struct V_350 * * V_351 )
{
struct V_368 * V_369 = V_204 -> V_204 ;
struct V_101 V_370 = V_204 -> V_205 ;
struct V_12 * V_13 = exp -> V_33 ;
T_4 V_346 = V_367 ;
struct V_350 * V_371 = NULL ;
struct V_350 * V_372 = NULL ;
struct V_348 * V_352 = NULL ;
struct V_348 * V_373 ;
struct V_348 * V_357 ;
struct V_358 * V_359 ;
T_6 V_374 ;
int V_375 = 0 ;
void * V_376 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_372 = F_154 ( V_377 ) ;
if ( ! V_372 )
return - V_98 ;
V_359 = F_155 ( V_372 ) ;
memset ( V_359 , 0 , sizeof( * V_359 ) ) ;
V_359 -> V_378 = F_156 ( V_367 ) ;
V_359 -> V_379 |= V_380 ;
V_376 = V_359 + 1 ;
V_374 = V_381 - sizeof( * V_359 ) ;
V_357 = V_376 ;
V_373 = V_357 ;
do {
T_12 V_382 ;
V_15 = F_144 ( exp , V_204 , V_345 , V_346 ,
& V_375 , & V_352 ,
& V_371 ) ;
if ( V_15 )
goto V_231;
if ( ! V_352 ) {
V_373 -> V_383 = 0 ;
V_346 = V_366 ;
goto V_231;
}
V_382 = F_149 ( V_352 -> V_383 ) ;
if ( ! V_382 )
V_382 = F_157 (
F_149 ( V_352 -> V_362 ) ,
F_78 ( V_352 -> V_384 ) ) ;
if ( V_382 > V_374 ) {
V_373 -> V_383 = F_158 ( 0 ) ;
V_346 = F_150 ( V_352 -> V_363 ) ;
goto V_231;
}
memcpy ( V_357 , V_352 , V_382 ) ;
if ( ! strncmp ( V_357 -> V_364 , L_73 ,
F_149 ( V_357 -> V_362 ) ) &&
F_149 ( V_357 -> V_362 ) == 1 )
F_159 ( & V_357 -> V_385 , & V_370 ) ;
else if ( ! strncmp ( V_357 -> V_364 , L_74 ,
F_149 ( V_357 -> V_362 ) ) &&
F_149 ( V_357 -> V_362 ) == 2 )
F_159 ( & V_357 -> V_385 , & V_204 -> V_331 ) ;
V_374 -= V_382 ;
V_357 -> V_383 = F_158 ( V_382 ) ;
V_373 = V_357 ;
V_357 = ( void * ) V_357 + V_382 ;
V_346 = F_150 ( V_352 -> V_363 ) ;
if ( V_346 == V_366 ) {
V_373 -> V_383 = 0 ;
break;
}
} while ( 1 );
V_231:
if ( V_371 ) {
F_151 ( V_371 ) ;
F_152 ( V_371 ) ;
}
if ( F_160 ( V_15 ) ) {
F_161 ( V_372 ) ;
V_372 = NULL ;
} else {
if ( V_357 == V_376 )
V_359 -> V_379 |= V_386 ;
V_359 -> V_379 = F_79 ( V_359 -> V_379 ) ;
V_359 -> V_365 = F_156 ( V_346 ) ;
}
V_204 -> V_205 = V_370 ;
V_204 -> V_218 = V_370 ;
V_204 -> V_204 = V_369 ;
* V_351 = V_372 ;
return V_15 ;
}
static int F_162 ( struct V_32 * exp , struct V_203 * V_204 ,
struct V_344 * V_345 , T_4 V_367 ,
struct V_350 * * V_351 )
{
struct V_100 * V_271 = V_204 -> V_281 ;
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
if ( F_160 ( V_271 ) ) {
V_15 = F_153 ( exp , V_204 , V_345 , V_367 , V_351 ) ;
return V_15 ;
}
V_4 = F_51 ( V_2 , & V_204 -> V_205 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_15 = F_145 ( V_4 -> V_20 , V_204 , V_345 , V_367 , V_351 ) ;
return V_15 ;
}
static int F_163 ( struct V_32 * exp , struct V_203 * V_204 ,
struct V_263 * * V_264 )
{
struct V_100 * V_271 = V_204 -> V_281 ;
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_387 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_302 * V_303 ;
int V_388 = 0 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_389:
if ( V_271 ) {
struct V_3 * V_332 ;
F_7 ( V_204 -> V_285 && V_204 -> V_284 ) ;
V_332 = F_109 ( V_2 , V_271 ,
V_204 -> V_285 ,
V_204 -> V_284 ,
& V_204 -> V_205 ,
& V_204 -> V_230 ) ;
if ( F_52 ( V_332 ) && F_53 ( V_332 ) != - V_390 )
return F_53 ( V_332 ) ;
if ( ! F_164 ( V_271 -> V_391 ) ) {
struct V_273 * V_274 ;
V_274 = & V_271 -> V_278 [ V_388 ] ;
V_204 -> V_205 = V_274 -> V_279 ;
V_204 -> V_230 = V_274 -> V_280 ;
}
}
V_392:
if ( F_165 ( ! F_166 ( & V_204 -> V_218 ) ) )
V_4 = F_51 ( V_2 , & V_204 -> V_218 ) ;
else if ( V_271 )
V_4 = F_81 ( V_2 , V_204 -> V_230 , NULL ) ;
else
V_4 = F_114 ( V_2 , V_204 , & V_204 -> V_205 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_204 -> V_318 = F_131 ( & V_319 , F_132 () ) ;
V_204 -> V_320 = F_133 ( & V_319 , F_134 () ) ;
V_204 -> V_321 = F_135 () ;
V_204 -> V_266 |= V_293 | V_333 ;
V_387 = F_51 ( V_2 , & V_204 -> V_205 ) ;
if ( F_52 ( V_387 ) )
return F_53 ( V_387 ) ;
if ( V_387 != V_4 ) {
V_15 = F_127 ( exp , V_387 , V_204 , V_4 -> V_83 ,
V_324 , V_334 ,
V_333 ) ;
}
V_15 = F_127 ( exp , NULL , V_204 , V_4 -> V_83 , V_324 ,
V_335 , V_333 ) ;
if ( V_15 != 0 )
return V_15 ;
F_3 ( V_268 , L_75 V_127 L_76 V_127 L_59 ,
F_55 ( & V_204 -> V_205 ) , F_55 ( & V_204 -> V_218 ) , V_4 -> V_83 ) ;
V_15 = F_167 ( V_4 -> V_20 , V_204 , V_264 ) ;
if ( V_15 != 0 && V_15 != - V_120 && V_15 != - V_393 )
return V_15 ;
if ( V_15 == - V_393 && V_271 && F_168 ( V_271 ) ) {
struct V_273 * V_274 ;
V_388 ++ ;
if ( V_388 >= V_271 -> V_277 )
return V_15 ;
V_274 = & V_271 -> V_278 [ V_388 ] ;
V_204 -> V_205 = V_274 -> V_279 ;
V_204 -> V_230 = V_274 -> V_280 ;
F_126 ( * V_264 ) ;
* V_264 = NULL ;
goto V_392;
}
V_303 = F_125 ( & ( * V_264 ) -> V_304 , & V_305 ) ;
if ( ! V_303 )
return - V_394 ;
if ( F_165 ( ! ( V_303 -> V_306 & V_307 ) ) )
return V_15 ;
F_3 ( V_268 , L_77 V_127 L_50 ,
exp -> V_33 -> V_27 , F_55 ( & V_303 -> V_309 ) ) ;
V_204 -> V_218 = V_303 -> V_309 ;
F_126 ( * V_264 ) ;
* V_264 = NULL ;
goto V_389;
}
static int F_169 ( struct V_12 * V_13 , enum V_395 V_396 )
{
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
switch ( V_396 ) {
case V_397 :
break;
case V_398 :
F_170 ( & V_2 -> V_84 ) ;
F_171 ( V_13 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_172 ( const struct V_51 * V_52 , struct V_32 * exp ,
T_2 V_399 , void * V_400 , T_2 * V_401 , void * V_402 ,
struct V_403 * V_271 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
int V_15 = 0 ;
V_13 = F_6 ( exp ) ;
if ( ! V_13 ) {
F_3 ( V_404 , L_78 ,
exp -> V_22 . V_23 ) ;
return - V_24 ;
}
V_2 = & V_13 -> V_34 . V_2 ;
if ( V_399 >= strlen ( L_79 ) && ! strcmp ( V_400 , L_79 ) ) {
int V_14 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
F_7 ( * V_401 == sizeof( T_2 ) ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
struct V_3 * V_4 = V_2 -> V_19 [ V_14 ] ;
if ( ! V_4 || ! V_4 -> V_20 )
continue;
if ( ! F_173 ( V_52 , V_4 -> V_20 , V_399 , V_400 ,
V_401 , V_402 , NULL ) )
return 0 ;
}
return - V_24 ;
} else if ( F_174 ( V_405 ) ||
F_174 ( V_406 ) ||
F_174 ( V_407 ) ) {
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_173 ( V_52 , V_2 -> V_19 [ 0 ] -> V_20 , V_399 , V_400 ,
V_401 , V_402 , NULL ) ;
if ( ! V_15 && F_174 ( V_407 ) )
exp -> V_49 = * (struct V_39 * ) V_402 ;
return V_15 ;
} else if ( F_174 ( V_408 ) ) {
* ( ( int * ) V_402 ) = V_2 -> V_7 . V_18 ;
return 0 ;
}
F_3 ( V_404 , L_80 ) ;
return - V_24 ;
}
static int F_175 ( const struct V_51 * V_52 , struct V_32 * exp ,
T_1 V_399 , void * V_400 , T_1 V_401 ,
void * V_402 , struct V_409 * V_165 )
{
struct V_3 * V_4 ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
int V_15 = 0 ;
V_13 = F_6 ( exp ) ;
if ( ! V_13 ) {
F_3 ( V_404 , L_78 ,
exp -> V_22 . V_23 ) ;
return - V_24 ;
}
V_2 = & V_13 -> V_34 . V_2 ;
if ( F_174 ( V_410 ) || F_174 ( V_411 ) ||
F_174 ( V_406 ) ) {
int V_14 , V_152 = 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( ! V_4 || ! V_4 -> V_20 )
continue;
V_152 = F_176 ( V_52 , V_4 -> V_20 ,
V_399 , V_400 , V_401 , V_402 , V_165 ) ;
if ( V_152 && V_15 == 0 )
V_15 = V_152 ;
}
return V_15 ;
}
return - V_24 ;
}
static int F_177 ( const struct V_100 * V_271 ,
struct V_412 * V_413 )
{
int V_414 ;
int V_14 ;
V_413 -> V_415 = F_79 ( V_271 -> V_416 ) ;
V_413 -> V_417 = F_79 ( V_271 -> V_277 ) ;
V_413 -> V_418 = F_79 ( V_271 -> V_419 ) ;
V_413 -> V_420 = F_79 ( V_271 -> V_391 ) ;
V_414 = F_178 ( V_413 -> V_421 , V_271 -> V_422 ,
sizeof( V_413 -> V_421 ) ) ;
if ( V_414 >= sizeof( V_413 -> V_421 ) )
return - V_423 ;
for ( V_14 = 0 ; V_14 < V_271 -> V_277 ; V_14 ++ )
F_159 ( & V_413 -> V_424 [ V_14 ] ,
& V_271 -> V_278 [ V_14 ] . V_279 ) ;
return 0 ;
}
static int
F_179 ( union V_425 * * V_426 , const struct V_100 * V_271 ,
int V_354 )
{
int V_427 = 0 , V_15 = 0 ;
bool V_428 = false ;
F_7 ( V_426 ) ;
if ( * V_426 && ! V_271 ) {
int V_429 ;
V_429 = F_180 ( * V_426 ) ;
V_427 = F_44 ( V_429 ,
F_78 ( ( * V_426 ) -> V_415 ) ) ;
if ( ! V_427 )
return - V_24 ;
F_76 ( * V_426 ) ;
* V_426 = NULL ;
return 0 ;
}
if ( ! * V_426 && ! V_271 ) {
V_427 = F_44 ( V_354 , V_103 ) ;
F_7 ( V_427 > 0 ) ;
* V_426 = F_75 ( V_427 , V_97 ) ;
if ( ! * V_426 )
return - V_98 ;
F_181 ( * V_426 , V_354 ) ;
( * V_426 ) -> V_415 = F_79 ( V_103 ) ;
return V_427 ;
}
F_7 ( V_271 ) ;
V_427 = F_44 ( V_271 -> V_277 ,
V_271 -> V_416 ) ;
if ( ! * V_426 ) {
* V_426 = F_75 ( V_427 , V_97 ) ;
if ( ! * V_426 )
return - V_98 ;
V_428 = true ;
}
switch ( V_271 -> V_416 ) {
case V_430 :
V_15 = F_177 ( V_271 , & ( * V_426 ) -> V_431 ) ;
break;
default:
V_15 = - V_24 ;
break;
}
if ( V_15 && V_428 ) {
F_76 ( * V_426 ) ;
* V_426 = NULL ;
}
return V_427 ;
}
static int F_182 ( struct V_32 * exp , struct V_100 * V_271 ,
const struct V_412 * V_413 )
{
struct V_1 * V_2 = & exp -> V_33 -> V_34 . V_2 ;
int V_354 ;
int V_15 = 0 ;
int V_414 ;
int V_14 ;
V_271 -> V_416 = F_78 ( V_413 -> V_415 ) ;
V_271 -> V_277 = F_78 ( V_413 -> V_417 ) ;
V_271 -> V_419 = F_78 ( V_413 -> V_418 ) ;
if ( F_110 ( V_432 ) )
V_271 -> V_391 = V_433 ;
else
V_271 -> V_391 = F_78 ( V_413 -> V_420 ) ;
V_271 -> V_434 = F_78 ( V_413 -> V_435 ) ;
V_414 = F_178 ( V_271 -> V_422 , V_413 -> V_421 ,
sizeof( V_271 -> V_422 ) ) ;
if ( V_414 >= sizeof( V_271 -> V_422 ) )
return - V_423 ;
F_3 ( V_16 , L_81 ,
V_271 -> V_277 , V_271 -> V_419 ,
V_271 -> V_391 , V_271 -> V_434 ) ;
V_354 = F_78 ( V_413 -> V_417 ) ;
for ( V_14 = 0 ; V_14 < V_354 ; V_14 ++ ) {
F_183 ( & V_271 -> V_278 [ V_14 ] . V_279 ,
& V_413 -> V_424 [ V_14 ] ) ;
V_15 = F_72 ( V_2 , & V_271 -> V_278 [ V_14 ] . V_279 ,
& V_271 -> V_278 [ V_14 ] . V_280 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_16 , L_82 V_127 L_50 , V_14 ,
F_55 ( & V_271 -> V_278 [ V_14 ] . V_279 ) ) ;
}
return V_15 ;
}
int F_184 ( struct V_32 * exp , struct V_100 * * V_436 ,
const union V_425 * V_437 , int V_354 )
{
struct V_100 * V_271 ;
bool V_428 = false ;
int V_438 , V_15 ;
F_7 ( V_436 ) ;
V_271 = * V_436 ;
if ( V_271 && ! V_437 ) {
int V_14 ;
for ( V_14 = 1 ; V_14 < V_271 -> V_277 ; V_14 ++ ) {
if ( ! ( V_271 -> V_391 & V_439 &&
! V_14 ) && V_271 -> V_278 [ V_14 ] . V_360 )
F_185 ( V_271 -> V_278 [ V_14 ] . V_360 ) ;
}
F_76 ( V_271 ) ;
* V_436 = NULL ;
return 0 ;
}
if ( ! V_271 && ! V_437 ) {
V_438 = F_186 ( V_354 ) ;
V_271 = F_75 ( V_438 , V_97 ) ;
if ( ! V_271 )
return - V_98 ;
V_271 -> V_277 = V_354 ;
* V_436 = V_271 ;
return 0 ;
}
if ( F_78 ( V_437 -> V_415 ) == V_440 )
return - V_219 ;
if ( F_78 ( V_437 -> V_415 ) != V_430 &&
F_78 ( V_437 -> V_415 ) != V_441 ) {
F_12 ( L_83 ,
exp -> V_33 -> V_27 , F_78 ( V_437 -> V_415 ) ,
- V_222 ) ;
return - V_222 ;
}
if ( F_78 ( V_437 -> V_415 ) == V_430 )
V_438 = F_186 ( F_180 ( V_437 ) ) ;
else
V_438 = F_186 ( 0 ) ;
if ( ! V_271 ) {
V_271 = F_75 ( V_438 , V_97 ) ;
if ( ! V_271 )
return - V_98 ;
V_428 = true ;
* V_436 = V_271 ;
}
switch ( F_78 ( V_437 -> V_415 ) ) {
case V_430 :
V_15 = F_182 ( exp , V_271 , & V_437 -> V_431 ) ;
break;
default:
F_12 ( L_84 , exp -> V_33 -> V_27 ,
F_78 ( V_437 -> V_415 ) ) ;
V_15 = - V_24 ;
break;
}
if ( V_15 && V_428 ) {
F_76 ( V_271 ) ;
* V_436 = NULL ;
V_438 = V_15 ;
}
return V_438 ;
}
static int F_187 ( struct V_32 * exp , struct V_403 * * V_436 ,
struct V_442 * V_437 , int V_443 )
{
return F_184 ( exp , (struct V_100 * * ) V_436 ,
(union V_425 * ) V_437 , V_443 ) ;
}
static int F_188 ( struct V_32 * exp , struct V_442 * * V_426 ,
struct V_403 * V_271 )
{
const struct V_100 * V_2 = (struct V_100 * ) V_271 ;
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_1 = & V_13 -> V_34 . V_2 ;
int V_354 ;
if ( ! V_426 ) {
if ( V_271 )
V_354 = V_2 -> V_277 ;
else
V_354 = V_1 -> V_7 . V_18 ;
return F_44 ( V_354 , V_430 ) ;
}
return F_179 ( (union V_425 * * ) V_426 , V_2 , 0 ) ;
}
static int F_189 ( struct V_32 * exp , const struct V_101 * V_198 ,
T_11 * V_296 , enum V_313 V_287 ,
enum V_444 V_250 , void * V_445 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
int V_15 = 0 ;
int V_152 ;
T_1 V_14 ;
F_7 ( V_198 ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
struct V_3 * V_4 = V_2 -> V_19 [ V_14 ] ;
if ( ! V_4 || ! V_4 -> V_20 || ! V_4 -> V_6 )
continue;
V_152 = F_129 ( V_4 -> V_20 , V_198 , V_296 , V_287 , V_250 ,
V_445 ) ;
if ( ! V_15 )
V_15 = V_152 ;
}
return V_15 ;
}
static int F_190 ( struct V_32 * exp ,
const struct V_55 * V_299 ,
void * V_38 , T_4 * V_314 )
{
struct V_1 * V_2 = & exp -> V_33 -> V_34 . V_2 ;
struct V_3 * V_4 = V_2 -> V_19 [ 0 ] ;
int V_15 ;
if ( ! V_4 || ! V_4 -> V_20 )
return - V_24 ;
V_15 = F_191 ( V_4 -> V_20 , V_299 , V_38 , V_314 ) ;
return V_15 ;
}
static enum V_313 F_192 ( struct V_32 * exp , T_4 V_250 ,
const struct V_101 * V_198 ,
enum V_446 type ,
T_11 * V_296 ,
enum V_313 V_287 ,
struct V_55 * V_299 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
enum V_313 V_15 ;
int V_4 ;
T_1 V_14 ;
F_3 ( V_268 , L_85 V_127 L_50 , F_55 ( V_198 ) ) ;
for ( V_14 = 0 , V_4 = F_193 ( V_2 , V_198 ) ;
V_14 < V_2 -> V_7 . V_18 ;
V_14 ++ , V_4 = ( V_4 + 1 ) % V_2 -> V_7 . V_18 ) {
if ( V_4 < 0 ) {
F_3 ( V_447 , L_86 V_127 L_87 ,
V_13 -> V_27 , F_55 ( V_198 ) , V_4 ) ;
V_4 = 0 ;
}
if ( ! V_2 -> V_19 [ V_4 ] || ! V_2 -> V_19 [ V_4 ] -> V_20 ||
! V_2 -> V_19 [ V_4 ] -> V_6 )
continue;
V_15 = F_194 ( V_2 -> V_19 [ V_4 ] -> V_20 , V_250 , V_198 ,
type , V_296 , V_287 , V_299 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static int F_195 ( struct V_32 * exp ,
struct V_263 * V_214 ,
struct V_32 * V_448 ,
struct V_32 * V_449 ,
struct V_450 * V_451 )
{
struct V_1 * V_2 = & exp -> V_33 -> V_34 . V_2 ;
struct V_3 * V_4 = V_2 -> V_19 [ 0 ] ;
if ( ! V_4 || ! V_4 -> V_20 )
return - V_24 ;
return F_196 ( V_4 -> V_20 , V_214 , V_448 , V_449 , V_451 ) ;
}
static int F_197 ( struct V_32 * exp , struct V_450 * V_451 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 = V_2 -> V_19 [ 0 ] ;
if ( V_451 -> V_2 ) {
F_198 ( V_451 -> V_2 ) ;
V_451 -> V_2 = NULL ;
}
if ( ! V_4 || ! V_4 -> V_20 )
return - V_24 ;
return F_199 ( V_4 -> V_20 , V_451 ) ;
}
static int F_200 ( struct V_32 * exp ,
struct V_452 * V_453 ,
struct V_297 * V_298 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
V_4 = F_51 ( V_2 , & V_453 -> V_454 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
return F_201 ( V_4 -> V_20 , V_453 , V_298 ) ;
}
static int F_202 ( struct V_32 * exp ,
struct V_452 * V_453 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
V_4 = F_51 ( V_2 , & V_453 -> V_454 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
return F_203 ( V_4 -> V_20 , V_453 ) ;
}
static int F_204 ( struct V_32 * exp ,
struct V_455 * V_456 ,
struct V_294 * V_295 )
{
struct V_203 * V_204 = & V_456 -> V_457 ;
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 = NULL ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_114 ( V_2 , V_204 , & V_204 -> V_205 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_15 = F_205 ( V_4 -> V_20 , V_456 , V_295 ) ;
return V_15 ;
}
static int F_206 ( struct V_32 * exp , struct V_297 * V_298 ,
struct V_101 * V_198 , T_4 * V_314 )
{
struct V_12 * V_13 = exp -> V_33 ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_15 = F_19 ( V_13 ) ;
if ( V_15 )
return V_15 ;
V_4 = F_51 ( V_2 , V_198 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_15 = F_207 ( V_4 -> V_20 , V_298 , V_198 , V_314 ) ;
return V_15 ;
}
static int
F_208 ( struct V_32 * exp ,
const struct V_100 * V_271 ,
const char * V_259 , int V_272 , struct V_101 * V_198 )
{
const struct V_273 * V_274 ;
F_7 ( V_271 ) ;
V_274 = F_112 ( V_271 , V_259 , V_272 ) ;
if ( F_52 ( V_274 ) )
return F_53 ( V_274 ) ;
* V_198 = V_274 -> V_279 ;
return 0 ;
}
static int F_209 ( struct V_12 * V_458 , struct V_32 * exp ,
struct V_184 * V_185 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 = V_2 -> V_19 [ 0 ] ;
int V_15 = 0 ;
T_4 V_459 = 0 , V_460 = 0 ;
T_1 V_14 ;
if ( ! V_4 || ! V_4 -> V_20 || ! V_4 -> V_6 ||
! V_2 -> V_7 . V_18 ) {
F_12 ( L_88 ) ;
return - V_222 ;
}
if ( V_185 -> V_461 != V_462 ) {
V_15 = V_184 ( V_4 -> V_20 , V_185 ) ;
return V_15 ;
}
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
int V_152 ;
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( ! V_4 || ! V_4 -> V_20 || ! V_4 -> V_6 )
continue;
V_152 = V_184 ( V_4 -> V_20 , V_185 ) ;
if ( V_152 ) {
F_12 ( L_89 , V_14 , V_152 ) ;
if ( ! V_15 )
V_15 = V_152 ;
} else {
V_459 += V_185 -> V_463 . V_464 ;
V_460 += V_185 -> V_463 . V_465 ;
}
}
V_185 -> V_463 . V_464 = V_459 ;
V_185 -> V_463 . V_465 = V_460 ;
return V_15 ;
}
static int F_210 ( struct V_12 * V_458 , struct V_32 * exp ,
struct V_184 * V_185 )
{
struct V_12 * V_13 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_13 -> V_34 . V_2 ;
struct V_3 * V_4 ;
int V_15 = 0 ;
T_1 V_14 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_7 . V_18 ; V_14 ++ ) {
int V_152 ;
V_4 = V_2 -> V_19 [ V_14 ] ;
if ( ! V_4 || ! V_4 -> V_20 || ! V_4 -> V_6 ) {
F_12 ( L_90 , V_14 ) ;
return - V_222 ;
}
V_152 = F_211 ( V_4 -> V_20 , V_185 ) ;
if ( V_152 && ! V_15 )
V_15 = V_152 ;
}
return V_15 ;
}
static int F_212 ( struct V_32 * exp ,
const struct V_100 * V_271 ,
struct V_466 * V_467 ,
T_13 V_468 )
{
int V_15 , V_14 ;
V_15 = F_213 ( exp , V_271 , V_468 , 0 ) ;
if ( V_15 < 0 )
return V_15 ;
for ( V_14 = 0 ; V_14 < V_271 -> V_277 ; V_14 ++ ) {
struct V_368 * V_368 = V_271 -> V_278 [ V_14 ] . V_360 ;
F_3 ( V_16 , L_5 V_127 L_91 ,
F_55 ( & V_271 -> V_278 [ V_14 ] . V_279 ) ,
F_214 ( V_368 ) , ( unsigned long long ) V_368 -> V_469 ,
V_368 -> V_470 , F_215 ( V_368 -> V_471 ) ,
F_215 ( V_368 -> V_472 ) , F_215 ( V_368 -> V_473 ) ) ;
if ( V_14 )
V_467 -> V_474 += V_368 -> V_470 - 2 ;
else
V_467 -> V_474 = V_368 -> V_470 ;
V_467 -> V_475 += F_214 ( V_368 ) ;
V_467 -> V_476 += V_368 -> V_469 ;
if ( V_467 -> V_477 < F_215 ( V_368 -> V_471 ) )
V_467 -> V_477 = F_215 ( V_368 -> V_471 ) ;
if ( V_467 -> V_478 < F_215 ( V_368 -> V_472 ) )
V_467 -> V_478 = F_215 ( V_368 -> V_472 ) ;
if ( V_467 -> V_479 < F_215 ( V_368 -> V_473 ) )
V_467 -> V_479 = F_215 ( V_368 -> V_473 ) ;
}
return 0 ;
}
static int T_14 F_216 ( void )
{
struct V_234 V_235 ;
int V_15 ;
F_89 ( & V_235 ) ;
V_15 = F_217 ( & V_480 , & V_481 ,
V_482 , NULL ) ;
return V_15 ;
}
static void F_218 ( void )
{
F_219 ( V_482 ) ;
}
