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
struct V_3 * V_14 ( V_4 ) ;
struct V_15 * V_16 ;
T_1 V_17 ;
int V_18 = 0 ;
F_3 ( V_19 , L_1 ,
V_2 , V_13 -> V_13 , V_5 ) ;
F_4 ( & V_2 -> V_20 ) ;
for ( V_17 = 0 ; V_17 < V_2 -> V_7 . V_21 ; V_17 ++ ) {
V_4 = V_2 -> V_22 [ V_17 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
continue;
F_3 ( V_19 , L_2 , V_17 ,
V_4 -> V_23 . V_13 , V_4 -> V_9 -> V_24 . V_25 ) ;
if ( F_5 ( V_13 , & V_4 -> V_23 ) )
break;
}
if ( V_17 == V_2 -> V_7 . V_21 ) {
V_18 = - V_26 ;
goto V_27;
}
V_16 = F_6 ( V_4 -> V_9 ) ;
if ( ! V_16 ) {
V_18 = - V_28 ;
goto V_27;
}
F_3 ( V_19 , L_3 ,
V_16 -> V_29 , V_16 -> V_12 . V_13 , V_16 -> V_30 , V_16 ,
V_16 -> V_31 -> V_32 , V_17 ) ;
F_7 ( strcmp ( V_16 -> V_31 -> V_32 , V_33 ) == 0 ) ;
if ( V_4 -> V_6 == V_5 ) {
F_3 ( V_19 , L_4 , V_16 ,
V_5 ? L_5 : L_6 ) ;
goto V_27;
}
F_3 ( V_19 , L_7 , V_16 ,
V_5 ? L_5 : L_6 ) ;
F_1 ( V_2 , V_4 , V_5 ) ;
V_27:
F_8 ( & V_2 -> V_20 ) ;
return V_18 ;
}
static struct V_12 * F_9 ( struct V_34 * exp )
{
struct V_1 * V_2 = & exp -> V_10 -> V_35 . V_2 ;
struct V_3 * V_4 = V_2 -> V_22 [ 0 ] ;
return V_4 ? F_10 ( V_4 -> V_9 ) : NULL ;
}
static int F_11 ( struct V_15 * V_16 , struct V_15 * V_36 ,
enum V_37 V_38 , void * V_39 )
{
struct V_40 * V_41 ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
struct V_12 * V_13 ;
int V_18 = 0 ;
if ( strcmp ( V_36 -> V_31 -> V_32 , V_33 ) ) {
F_12 ( L_8 ,
V_36 -> V_31 -> V_32 ,
V_36 -> V_29 ) ;
return - V_26 ;
}
V_13 = & V_36 -> V_35 . V_42 . V_43 ;
if ( V_38 == V_44 || V_38 == V_45 ) {
V_18 = F_2 ( V_2 , V_13 ,
V_38 == V_44 ) ;
if ( V_18 ) {
F_12 ( L_9 ,
V_38 == V_44 ? L_5 : L_10 ,
V_13 -> V_13 , V_18 ) ;
return V_18 ;
}
} else if ( V_38 == V_46 ) {
V_41 = & V_36 -> V_35 . V_42 . V_47 -> V_48 ;
V_16 -> V_49 -> V_50 = * V_41 ;
}
#if 0
else if (ev == OBD_NOTIFY_DISCON) {
fld_client_flush(&lmv->lmv_fld);
}
#endif
if ( V_16 -> V_51 )
V_18 = F_13 ( V_16 -> V_51 , V_36 , V_38 , V_39 ) ;
return V_18 ;
}
static int F_14 ( const struct V_52 * V_53 ,
struct V_34 * * exp , struct V_15 * V_16 ,
struct V_12 * V_54 , struct V_40 * V_39 ,
void * V_55 )
{
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
struct V_56 V_57 = { 0 } ;
int V_18 = 0 ;
V_2 -> V_58 ++ ;
if ( V_2 -> V_58 > 1 ) {
* exp = NULL ;
return 0 ;
}
V_18 = F_15 ( & V_57 , V_16 , V_54 ) ;
if ( V_18 ) {
F_12 ( L_11 , V_18 ) ;
return V_18 ;
}
* exp = F_16 ( & V_57 ) ;
F_17 ( * exp ) ;
V_2 -> exp = * exp ;
V_2 -> V_59 = 0 ;
V_2 -> V_54 = * V_54 ;
if ( V_39 )
V_2 -> V_41 = * V_39 ;
V_2 -> V_60 = F_18 ( L_12 ,
& V_16 -> V_61 ) ;
if ( V_39 && V_39 -> V_62 & V_63 )
V_18 = F_19 ( V_16 ) ;
if ( V_18 && V_2 -> V_60 )
F_20 ( V_2 -> V_60 ) ;
return V_18 ;
}
static int F_21 ( struct V_34 * exp , T_1 V_64 , T_1 V_65 )
{
struct V_15 * V_16 = exp -> V_10 ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
T_1 V_17 ;
int V_18 = 0 ;
int V_66 = 0 ;
if ( V_2 -> V_67 < V_64 ) {
V_2 -> V_67 = V_64 ;
V_66 = 1 ;
}
if ( V_2 -> V_68 < V_65 ) {
V_2 -> V_68 = V_65 ;
V_66 = 1 ;
}
if ( V_66 == 0 )
return 0 ;
if ( V_2 -> V_59 == 0 )
return 0 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_7 . V_21 ; V_17 ++ ) {
struct V_3 * V_4 = V_2 -> V_22 [ V_17 ] ;
if ( ! V_4 || ! V_4 -> V_9 || ! V_4 -> V_6 ) {
F_22 ( L_13 , V_16 -> V_29 , V_17 ) ;
continue;
}
V_18 = F_23 ( V_4 -> V_9 , V_64 , V_65 ) ;
if ( V_18 ) {
F_12 ( L_14 ,
V_16 -> V_29 , V_17 , V_18 ) ;
break;
}
}
return V_18 ;
}
static int F_24 ( struct V_15 * V_16 , struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
struct V_12 * V_54 = & V_2 -> V_54 ;
struct V_12 V_69 = { L_15 } ;
struct V_15 * V_70 ;
struct V_34 * V_71 ;
struct V_72 V_73 ;
int V_18 ;
V_70 = F_25 ( & V_4 -> V_23 , V_33 ,
& V_16 -> V_12 ) ;
if ( ! V_70 ) {
F_12 ( L_16 , V_4 -> V_23 . V_13 ) ;
return - V_26 ;
}
F_3 ( V_74 , L_17 ,
V_70 -> V_29 , V_70 -> V_12 . V_13 ,
V_4 -> V_23 . V_13 , V_16 -> V_12 . V_13 , V_54 -> V_13 ) ;
if ( ! V_70 -> V_75 ) {
F_12 ( L_18 , V_4 -> V_23 . V_13 ) ;
return - V_26 ;
}
V_18 = F_26 ( NULL , & V_71 , V_70 , & V_69 ,
& V_2 -> V_41 , NULL ) ;
if ( V_18 ) {
F_12 ( L_19 , V_4 -> V_23 . V_13 , V_18 ) ;
return V_18 ;
}
V_18 = F_27 ( V_70 , V_71 , V_76 ) ;
if ( V_18 )
return V_18 ;
V_73 . V_77 = NULL ;
V_73 . V_78 = V_71 ;
V_73 . V_79 = V_4 -> V_80 ;
F_28 ( & V_2 -> V_81 , & V_73 ) ;
V_18 = F_29 ( V_70 , V_16 ) ;
if ( V_18 ) {
F_30 ( V_71 ) ;
F_12 ( L_20 ,
V_4 -> V_23 . V_13 , V_18 ) ;
return V_18 ;
}
if ( V_16 -> V_51 ) {
V_18 = F_13 ( V_16 -> V_51 , V_71 -> V_10 ,
V_44 ,
( void * ) ( V_4 - V_2 -> V_22 [ 0 ] ) ) ;
if ( V_18 ) {
F_30 ( V_71 ) ;
return V_18 ;
}
}
V_4 -> V_6 = 1 ;
V_4 -> V_9 = V_71 ;
V_2 -> V_7 . V_8 ++ ;
F_23 ( V_4 -> V_9 , V_2 -> V_67 , V_2 -> V_68 ) ;
F_3 ( V_74 , L_21 ,
V_70 -> V_29 , V_70 -> V_12 . V_13 ,
F_31 ( & V_16 -> V_82 ) ) ;
if ( V_2 -> V_60 )
V_18 = F_32 ( V_2 -> V_60 , & V_70 -> V_61 ,
V_70 -> V_29 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 , int V_83 )
{
if ( ! V_2 -> V_22 [ V_83 ] )
return;
F_34 ( V_2 -> V_22 [ V_83 ] ) ;
V_2 -> V_22 [ V_83 ] = NULL ;
return;
}
static int F_35 ( struct V_15 * V_16 , struct V_12 * V_84 ,
T_2 V_83 , int V_85 )
{
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
struct V_15 * V_70 ;
struct V_3 * V_4 ;
int V_86 = 0 ;
int V_18 = 0 ;
F_3 ( V_74 , L_22 , V_84 -> V_13 , V_83 ) ;
V_70 = F_25 ( V_84 , V_33 ,
& V_16 -> V_12 ) ;
if ( ! V_70 ) {
F_12 ( L_23 ,
V_16 -> V_29 , V_84 -> V_13 , - V_26 ) ;
return - V_26 ;
}
F_36 ( & V_2 -> V_87 ) ;
if ( ( V_83 < V_2 -> V_88 ) && V_2 -> V_22 [ V_83 ] ) {
V_4 = V_2 -> V_22 [ V_83 ] ;
F_12 ( L_24 ,
V_16 -> V_29 ,
F_37 ( & V_4 -> V_23 ) , V_83 , - V_89 ) ;
F_38 ( & V_2 -> V_87 ) ;
return - V_89 ;
}
if ( V_83 >= V_2 -> V_88 ) {
struct V_3 * * V_90 , * * V_91 = NULL ;
T_2 V_92 = 1 ;
T_2 V_93 = 0 ;
while ( V_92 < V_83 + 1 )
V_92 <<= 1 ;
V_90 = F_39 ( V_92 , sizeof( * V_90 ) , V_94 ) ;
if ( ! V_90 ) {
F_38 ( & V_2 -> V_87 ) ;
return - V_95 ;
}
if ( V_2 -> V_88 ) {
memcpy ( V_90 , V_2 -> V_22 ,
sizeof( * V_90 ) * V_2 -> V_88 ) ;
V_91 = V_2 -> V_22 ;
V_93 = V_2 -> V_88 ;
}
V_2 -> V_22 = V_90 ;
V_2 -> V_88 = V_92 ;
F_40 () ;
F_34 ( V_91 ) ;
F_3 ( V_74 , L_25 , V_2 -> V_22 ,
V_2 -> V_88 ) ;
}
V_4 = F_41 ( sizeof( * V_4 ) , V_94 ) ;
if ( ! V_4 ) {
F_38 ( & V_2 -> V_87 ) ;
return - V_95 ;
}
F_42 ( & V_4 -> V_96 ) ;
V_4 -> V_80 = V_83 ;
V_4 -> V_23 = * V_84 ;
V_4 -> V_6 = 0 ;
V_2 -> V_22 [ V_83 ] = V_4 ;
if ( V_83 >= V_2 -> V_7 . V_21 ) {
V_86 = V_2 -> V_7 . V_21 ;
V_2 -> V_7 . V_21 = V_83 + 1 ;
}
if ( ! V_2 -> V_59 ) {
F_38 ( & V_2 -> V_87 ) ;
return V_18 ;
}
F_38 ( & V_2 -> V_87 ) ;
V_18 = F_24 ( V_16 , V_4 ) ;
if ( V_18 ) {
F_4 ( & V_2 -> V_20 ) ;
if ( V_2 -> V_7 . V_21 == V_83 + 1 )
V_2 -> V_7 . V_21 = V_86 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_8 ( & V_2 -> V_20 ) ;
} else {
int V_64 = sizeof( struct V_97 ) +
V_2 -> V_7 . V_21 * sizeof( struct V_98 ) ;
F_21 ( V_16 -> V_49 , V_64 , 0 ) ;
}
return V_18 ;
}
int F_19 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
struct V_3 * V_4 ;
T_1 V_17 ;
int V_18 ;
int V_64 ;
if ( V_2 -> V_59 )
return 0 ;
F_36 ( & V_2 -> V_87 ) ;
if ( V_2 -> V_59 ) {
F_38 ( & V_2 -> V_87 ) ;
return 0 ;
}
if ( V_2 -> V_7 . V_21 == 0 ) {
F_38 ( & V_2 -> V_87 ) ;
F_12 ( L_26 , V_16 -> V_29 ) ;
return - V_26 ;
}
F_7 ( V_2 -> V_22 ) ;
if ( ! V_2 -> V_22 [ 0 ] ) {
F_38 ( & V_2 -> V_87 ) ;
F_12 ( L_27 ,
V_16 -> V_29 ) ;
return - V_26 ;
}
F_3 ( V_74 , L_28 ,
V_2 -> V_54 . V_13 , V_16 -> V_29 ) ;
for ( V_17 = 0 ; V_17 < V_2 -> V_7 . V_21 ; V_17 ++ ) {
V_4 = V_2 -> V_22 [ V_17 ] ;
if ( ! V_4 )
continue;
V_18 = F_24 ( V_16 , V_4 ) ;
if ( V_18 )
goto V_99;
}
F_43 ( V_2 -> exp ) ;
V_2 -> V_59 = 1 ;
V_64 = F_44 ( V_2 -> V_7 . V_21 , V_100 ) ;
F_21 ( V_16 -> V_49 , V_64 , 0 ) ;
F_38 ( & V_2 -> V_87 ) ;
return 0 ;
V_99:
while ( V_17 -- > 0 ) {
int V_101 ;
V_4 = V_2 -> V_22 [ V_17 ] ;
if ( ! V_4 )
continue;
V_4 -> V_6 = 0 ;
if ( V_4 -> V_9 ) {
-- V_2 -> V_7 . V_8 ;
V_101 = F_30 ( V_4 -> V_9 ) ;
if ( V_101 ) {
F_12 ( L_29 ,
V_4 -> V_23 . V_13 , V_17 , V_101 ) ;
}
}
}
F_45 ( V_2 -> exp ) ;
F_38 ( & V_2 -> V_87 ) ;
return V_18 ;
}
static int F_46 ( struct V_15 * V_16 , struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
struct V_15 * V_70 ;
int V_18 ;
V_70 = F_6 ( V_4 -> V_9 ) ;
if ( V_70 ) {
V_70 -> V_102 = V_16 -> V_102 ;
V_70 -> V_103 = V_16 -> V_103 ;
V_70 -> V_104 = V_16 -> V_104 ;
if ( V_2 -> V_60 )
F_47 ( V_2 -> V_60 ,
V_70 -> V_29 ) ;
}
V_18 = F_48 ( V_4 -> V_9 -> V_10 ) ;
if ( V_18 )
F_12 ( L_30 ) ;
F_3 ( V_19 , L_31 ,
V_4 -> V_9 -> V_10 -> V_29 ,
V_4 -> V_9 -> V_10 -> V_12 . V_13 ) ;
F_29 ( V_4 -> V_9 -> V_10 , NULL ) ;
V_18 = F_30 ( V_4 -> V_9 ) ;
if ( V_18 ) {
if ( V_4 -> V_6 ) {
F_12 ( L_32 ,
V_4 -> V_23 . V_13 , V_18 ) ;
}
}
F_1 ( V_2 , V_4 , 0 ) ;
V_4 -> V_9 = NULL ;
return 0 ;
}
static int F_49 ( struct V_34 * exp )
{
struct V_15 * V_16 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
int V_18 ;
T_1 V_17 ;
if ( ! V_2 -> V_22 )
goto V_105;
V_2 -> V_58 -- ;
if ( V_2 -> V_58 != 0 )
goto V_105;
for ( V_17 = 0 ; V_17 < V_2 -> V_7 . V_21 ; V_17 ++ ) {
if ( ! V_2 -> V_22 [ V_17 ] || ! V_2 -> V_22 [ V_17 ] -> V_9 )
continue;
F_46 ( V_16 , V_2 -> V_22 [ V_17 ] ) ;
}
if ( V_2 -> V_60 )
F_20 ( V_2 -> V_60 ) ;
V_105:
if ( ! V_2 -> V_59 )
F_43 ( exp ) ;
V_18 = F_45 ( exp ) ;
if ( V_2 -> V_58 == 0 )
V_2 -> V_59 = 0 ;
return V_18 ;
}
static int F_50 ( struct V_34 * exp , int V_106 , void * V_107 ,
void T_3 * V_108 )
{
struct V_15 * V_109 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_109 -> V_35 . V_2 ;
struct V_110 * V_111 ;
struct V_3 * V_4 ;
struct V_110 * V_112 = NULL ;
int V_113 = 0 ;
int V_18 ;
V_111 = (struct V_110 * ) V_107 ;
V_4 = F_51 ( V_2 , & V_111 -> V_114 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_115:
V_18 = F_54 ( V_116 , V_4 -> V_9 , V_106 , V_111 , V_108 ) ;
if ( V_18 != 0 && V_18 != - V_117 )
goto V_118;
if ( V_112 ) {
struct V_110 * V_119 ;
char * V_120 ;
V_119 = (struct V_110 * ) V_107 ;
if ( strlen ( V_119 -> V_121 ) +
strlen ( V_111 -> V_121 ) > V_119 -> V_122 ) {
V_18 = - V_123 ;
goto V_118;
}
V_120 = V_119 -> V_121 ;
memmove ( V_120 + strlen ( V_111 -> V_121 ) + 1 , V_120 ,
strlen ( V_119 -> V_121 ) ) ;
strncpy ( V_120 , V_111 -> V_121 , strlen ( V_111 -> V_121 ) ) ;
V_120 += strlen ( V_111 -> V_121 ) ;
* V_120 = '/' ;
}
F_3 ( V_19 , L_33 V_124 L_34 ,
V_4 -> V_9 -> V_10 -> V_29 ,
V_111 -> V_121 , F_55 ( & V_111 -> V_114 ) , V_111 -> V_125 ,
V_111 -> V_126 ) ;
if ( V_18 == 0 )
goto V_118;
if ( ! V_112 ) {
V_113 = sizeof( * V_112 ) + V_127 ;
V_112 = F_41 ( V_113 , V_94 ) ;
if ( ! V_112 ) {
V_18 = - V_95 ;
goto V_118;
}
V_112 -> V_122 = V_127 ;
}
if ( ! F_56 ( & V_111 -> V_114 ) ) {
F_12 ( L_35 V_124 L_36 ,
V_4 -> V_9 -> V_10 -> V_29 ,
F_55 ( & V_111 -> V_114 ) , - V_26 ) ;
V_18 = - V_26 ;
goto V_118;
}
V_4 = F_51 ( V_2 , & V_111 -> V_114 ) ;
if ( F_52 ( V_4 ) ) {
V_18 = - V_26 ;
goto V_118;
}
V_112 -> V_114 = V_111 -> V_114 ;
V_112 -> V_125 = - 1 ;
V_112 -> V_126 = - 1 ;
memset ( V_112 -> V_121 , 0 , V_112 -> V_122 ) ;
V_111 = V_112 ;
goto V_115;
V_118:
F_34 ( V_112 ) ;
return V_18 ;
}
static int F_57 ( struct V_1 * V_2 ,
const struct V_128 * V_129 ,
const struct V_3 * V_130 )
{
T_1 V_17 , V_131 = 0 ;
struct V_3 * V_132 ;
for ( V_17 = 0 ; V_17 < V_129 -> V_133 . V_134 ; V_17 ++ ) {
V_132 = F_51 ( V_2 , & V_129 -> V_135 [ V_17 ] . V_136 ) ;
if ( F_5 ( & V_132 -> V_23 , & V_130 -> V_23 ) )
V_131 ++ ;
}
return V_131 ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_128 * V_137 ,
const struct V_3 * V_130 ,
struct V_128 * V_138 )
{
int V_17 , V_139 ;
struct V_3 * V_132 ;
V_138 -> V_133 = V_137 -> V_133 ;
V_139 = 0 ;
for ( V_17 = 0 ; V_17 < V_137 -> V_133 . V_134 ; V_17 ++ ) {
V_132 = F_51 ( V_2 ,
& V_137 -> V_135 [ V_17 ] . V_136 ) ;
if ( F_5 ( & V_132 -> V_23 , & V_130 -> V_23 ) ) {
V_138 -> V_135 [ V_139 ] =
V_137 -> V_135 [ V_17 ] ;
V_139 ++ ;
}
}
V_138 -> V_133 . V_134 = V_139 ;
memcpy ( F_59 ( V_138 ) , F_59 ( V_137 ) ,
V_137 -> V_133 . V_140 ) ;
}
static int F_60 ( struct V_1 * V_2 , unsigned int V_141 , int V_106 ,
struct V_142 * V_143 ,
void T_3 * V_108 )
{
int V_18 = 0 ;
T_2 V_17 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_7 . V_21 ; V_17 ++ ) {
struct V_3 * V_4 = V_2 -> V_22 [ V_17 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
continue;
F_54 ( V_141 , V_2 -> V_22 [ V_17 ] -> V_9 , V_106 , V_143 , V_108 ) ;
}
V_18 = F_61 ( V_143 -> V_144 , V_143 -> V_145 ) ;
return V_18 ;
}
static int F_62 ( struct V_1 * V_2 , unsigned int V_141 , int V_106 ,
struct V_142 * V_143 , void T_3 * V_108 )
{
struct V_146 * V_147 ;
T_2 V_17 , V_148 ;
int V_149 , V_18 = 0 ;
bool V_150 = false ;
struct V_151 V_152 = { 0 } ;
for ( V_17 = 0 ; V_17 < V_2 -> V_7 . V_21 ; V_17 ++ ) {
struct V_3 * V_4 = V_2 -> V_22 [ V_17 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
continue;
V_149 = F_54 ( V_141 , V_4 -> V_9 , V_106 , V_143 , V_108 ) ;
if ( V_149 ) {
if ( V_4 -> V_6 ) {
F_12 ( L_37 ,
V_4 -> V_23 . V_13 , V_17 , V_141 , V_149 ) ;
V_18 = V_149 ;
V_143 -> V_153 |= V_154 ;
for ( V_148 = 0 ; V_148 < V_17 ; V_148 ++ ) {
V_4 = V_2 -> V_22 [ V_148 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
continue;
F_54 ( V_141 , V_4 -> V_9 , V_106 ,
V_143 , V_108 ) ;
}
return V_18 ;
}
} else {
V_150 = true ;
}
}
if ( ! V_150 )
return - V_28 ;
V_147 = F_63 ( V_143 -> V_155 ) ;
if ( ! V_147 )
return - V_156 ;
V_152 . V_157 = V_158 ;
V_152 . V_159 = V_2 -> V_54 ;
V_152 . V_160 = V_143 -> V_161 ;
V_18 = F_64 ( V_147 , V_143 -> V_144 , V_143 -> V_145 ,
& V_152 , sizeof( V_152 ) ) ;
if ( V_18 )
F_65 ( V_147 ) ;
return V_18 ;
}
static int F_66 ( unsigned int V_141 , struct V_34 * exp ,
int V_106 , void * V_107 , void T_3 * V_108 )
{
struct V_15 * V_109 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_109 -> V_35 . V_2 ;
struct V_3 * V_4 = NULL ;
T_1 V_17 = 0 ;
int V_18 = 0 ;
int V_162 = 0 ;
T_1 V_163 = V_2 -> V_7 . V_21 ;
if ( V_163 == 0 )
return - V_164 ;
switch ( V_141 ) {
case V_165 : {
struct V_166 * V_39 = V_107 ;
struct V_15 * V_70 ;
struct V_167 V_168 = { 0 } ;
T_2 V_83 ;
memcpy ( & V_83 , V_39 -> V_169 , sizeof( T_2 ) ) ;
if ( V_83 >= V_163 )
return - V_170 ;
V_4 = V_2 -> V_22 [ V_83 ] ;
if ( ! V_4 || ! V_4 -> V_6 )
return - V_171 ;
V_70 = F_6 ( V_4 -> V_9 ) ;
if ( ! V_70 )
return - V_26 ;
if ( F_67 ( V_39 -> V_172 , F_68 ( V_70 ) ,
F_69 ( ( int ) V_39 -> V_173 ,
( int ) sizeof( struct V_12 ) ) ) )
return - V_174 ;
V_18 = V_167 ( NULL , V_4 -> V_9 , & V_168 ,
F_70 ( - V_175 ) ,
0 ) ;
if ( V_18 )
return V_18 ;
if ( F_67 ( V_39 -> V_176 , & V_168 ,
F_69 ( ( int ) V_39 -> V_177 ,
( int ) sizeof( V_168 ) ) ) )
return - V_174 ;
break;
}
case V_178 : {
struct V_179 * V_180 = V_107 ;
struct V_181 * V_182 ;
if ( V_180 -> V_183 == V_184 ) {
if ( V_163 <= V_180 -> V_185 )
return - V_26 ;
V_4 = V_2 -> V_22 [ V_180 -> V_185 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
return - V_26 ;
} else if ( V_180 -> V_183 == V_186 ) {
for ( V_17 = 0 ; V_17 < V_163 ; V_17 ++ ) {
V_4 = V_2 -> V_22 [ V_17 ] ;
if ( ! V_4 )
continue;
if ( ! F_5 ( & V_4 -> V_23 ,
& V_180 -> V_12 ) )
continue;
if ( ! V_4 -> V_9 )
return - V_26 ;
break;
}
} else {
return - V_26 ;
}
if ( V_17 >= V_163 )
return - V_187 ;
F_7 ( V_4 && V_4 -> V_9 ) ;
V_182 = F_41 ( sizeof( * V_182 ) , V_94 ) ;
if ( ! V_182 )
return - V_95 ;
F_71 ( V_182 , V_180 ) ;
V_18 = V_181 ( V_4 -> V_9 , V_182 ) ;
if ( V_18 == 0 ) {
F_71 ( V_180 , V_182 ) ;
V_180 -> V_183 = V_184 ;
V_180 -> V_12 = V_4 -> V_23 ;
}
F_34 ( V_182 ) ;
break;
}
case V_188 :
case V_189 : {
struct V_190 * V_191 = V_107 ;
if ( V_191 -> V_192 >= V_163 )
return - V_170 ;
V_4 = V_2 -> V_22 [ V_191 -> V_192 ] ;
if ( ! V_4 || ! V_4 -> V_9 || ! V_4 -> V_6 )
return - V_170 ;
V_18 = F_54 ( V_141 , V_4 -> V_9 , sizeof( * V_191 ) , V_191 , NULL ) ;
break;
}
case V_193 : {
V_4 = V_2 -> V_22 [ 0 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
return - V_171 ;
V_18 = F_54 ( V_141 , V_4 -> V_9 , V_106 , V_107 , V_108 ) ;
break;
}
case V_194 : {
struct V_98 * V_195 = V_107 ;
int V_196 ;
V_18 = F_72 ( V_2 , V_195 , & V_196 ) ;
if ( V_18 )
return V_18 ;
* ( T_2 * ) V_108 = V_196 ;
break;
}
case V_116 : {
V_18 = F_50 ( exp , V_106 , V_107 , V_108 ) ;
break;
}
case V_197 :
case V_198 :
case V_199 : {
struct V_200 * V_201 = V_107 ;
V_4 = F_51 ( V_2 , & V_201 -> V_202 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
if ( ! V_4 -> V_9 )
return - V_26 ;
V_18 = F_54 ( V_141 , V_4 -> V_9 , V_106 , V_107 , V_108 ) ;
break;
}
case V_203 : {
const struct V_204 * V_205 = V_107 ;
V_4 = F_51 ( V_2 , & V_205 -> V_206 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_18 = F_54 ( V_141 , V_4 -> V_9 , V_106 , V_107 , V_108 ) ;
break;
}
case V_207 : {
struct V_128 * V_129 = V_107 ;
unsigned int V_208 = V_129 -> V_133 . V_134 ;
if ( V_208 == 0 )
return 0 ;
if ( V_208 == 1 || V_163 == 1 ) {
V_4 = F_51 ( V_2 ,
& V_129 -> V_135 [ 0 ] . V_136 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_18 = F_54 ( V_141 , V_4 -> V_9 , V_106 , V_107 , V_108 ) ;
} else {
for ( V_17 = 0 ; V_17 < V_163 ; V_17 ++ ) {
unsigned int V_131 , V_209 ;
int V_210 ;
struct V_128 * V_211 ;
V_4 = V_2 -> V_22 [ V_17 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
continue;
V_131 = F_57 ( V_2 , V_129 , V_4 ) ;
if ( V_131 == 0 )
continue;
V_209 = F_73 ( F_74 ( * V_129 ) ,
V_135 [ V_131 ] )
+ V_129 -> V_133 . V_140 ;
V_211 = F_75 ( V_209 , V_94 ) ;
if ( ! V_211 )
return - V_95 ;
F_58 ( V_2 , V_129 , V_4 , V_211 ) ;
V_210 = F_54 ( V_141 , V_4 -> V_9 , V_209 ,
V_211 , V_108 ) ;
if ( V_210 != 0 && V_18 == 0 )
V_18 = V_210 ;
F_76 ( V_211 ) ;
}
}
break;
}
case V_212 : {
struct V_200 * V_201 = V_107 ;
struct V_3 * V_213 , * V_214 ;
V_213 = F_51 ( V_2 , & V_201 -> V_202 ) ;
if ( F_52 ( V_213 ) )
return F_53 ( V_213 ) ;
V_214 = F_51 ( V_2 , & V_201 -> V_215 ) ;
if ( F_52 ( V_214 ) )
return F_53 ( V_214 ) ;
if ( ! V_213 -> V_9 || ! V_214 -> V_9 )
return - V_26 ;
if ( V_213 -> V_80 != V_214 -> V_80 )
return - V_216 ;
V_18 = F_54 ( V_141 , V_213 -> V_9 , V_106 , V_107 , V_108 ) ;
break;
}
case V_217 : {
struct V_142 * V_143 = V_107 ;
if ( V_143 -> V_153 & V_154 )
V_18 = F_60 ( V_2 , V_141 , V_106 , V_143 , V_108 ) ;
else
V_18 = F_62 ( V_2 , V_141 , V_106 , V_143 , V_108 ) ;
break;
}
default:
for ( V_17 = 0 ; V_17 < V_163 ; V_17 ++ ) {
struct V_15 * V_70 ;
int V_149 ;
V_4 = V_2 -> V_22 [ V_17 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
continue;
V_70 = F_6 ( V_4 -> V_9 ) ;
V_70 -> V_102 = V_109 -> V_102 ;
V_149 = F_54 ( V_141 , V_4 -> V_9 , V_106 , V_107 , V_108 ) ;
if ( V_149 ) {
if ( V_4 -> V_6 ) {
F_12 ( L_37 ,
V_4 -> V_23 . V_13 , V_17 , V_141 , V_149 ) ;
if ( ! V_18 )
V_18 = V_149 ;
}
} else {
V_162 = 1 ;
}
}
if ( ! V_162 && ! V_18 )
V_18 = - V_218 ;
}
return V_18 ;
}
static int F_77 ( struct V_15 * V_16 ,
struct V_200 * V_201 , T_1 * V_219 )
{
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
F_7 ( V_219 ) ;
if ( V_2 -> V_7 . V_21 == 1 ) {
* V_219 = 0 ;
return 0 ;
}
if ( V_201 -> V_220 != - 1 ) {
* V_219 = V_201 -> V_220 ;
return 0 ;
}
if ( V_201 -> V_221 & V_222 && V_201 -> V_201 ) {
struct V_223 * V_224 ;
V_224 = V_201 -> V_201 ;
if ( F_78 ( V_224 -> V_225 ) != ( T_2 ) - 1 ) {
* V_219 = F_78 ( V_224 -> V_225 ) ;
} else {
* V_219 = V_201 -> V_226 ;
V_224 -> V_225 = F_79 ( V_201 -> V_226 ) ;
}
} else {
* V_219 = V_201 -> V_226 ;
}
return 0 ;
}
int F_80 ( struct V_1 * V_2 , struct V_98 * V_195 , T_1 V_219 )
{
struct V_3 * V_4 ;
int V_18 ;
V_4 = F_81 ( V_2 , V_219 , NULL ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
F_36 ( & V_4 -> V_96 ) ;
if ( V_4 -> V_6 == 0 || ! V_4 -> V_9 ) {
V_18 = - V_170 ;
goto V_227;
}
V_18 = F_82 ( NULL , V_4 -> V_9 , V_195 , NULL ) ;
if ( V_18 > 0 ) {
F_7 ( F_56 ( V_195 ) ) ;
V_18 = 0 ;
}
V_227:
F_38 ( & V_4 -> V_96 ) ;
return V_18 ;
}
int F_83 ( const struct V_52 * V_53 , struct V_34 * exp ,
struct V_98 * V_195 , struct V_200 * V_201 )
{
struct V_15 * V_16 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
T_1 V_219 = 0 ;
int V_18 ;
F_7 ( V_201 ) ;
F_7 ( V_195 ) ;
V_18 = F_77 ( V_16 , V_201 , & V_219 ) ;
if ( V_18 ) {
F_12 ( L_38 ,
V_18 ) ;
return V_18 ;
}
V_18 = F_80 ( V_2 , V_195 , V_219 ) ;
if ( V_18 ) {
F_12 ( L_39 , V_18 ) ;
return V_18 ;
}
return V_18 ;
}
static int F_84 ( struct V_15 * V_16 , struct V_228 * V_229 )
{
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
struct V_230 V_231 = { NULL } ;
struct V_232 * V_7 ;
int V_18 ;
if ( F_85 ( V_229 , 1 ) < 1 ) {
F_12 ( L_40 ) ;
return - V_26 ;
}
V_7 = (struct V_232 * ) F_86 ( V_229 , 1 ) ;
if ( sizeof( * V_7 ) > F_85 ( V_229 , 1 ) ) {
F_12 ( L_41 ,
( int ) sizeof( * V_7 ) , F_85 ( V_229 , 1 ) ) ;
return - V_26 ;
}
V_2 -> V_88 = 32U ;
V_2 -> V_22 = F_39 ( V_2 -> V_88 , sizeof( * V_2 -> V_22 ) , V_94 ) ;
if ( ! V_2 -> V_22 )
return - V_95 ;
F_87 ( & V_2 -> V_7 . V_233 , V_7 -> V_233 . V_13 ) ;
V_2 -> V_7 . V_21 = 0 ;
V_2 -> V_7 . V_8 = 0 ;
V_2 -> V_68 = 0 ;
V_2 -> V_67 = 0 ;
V_2 -> V_234 = V_235 ;
F_88 ( & V_2 -> V_20 ) ;
F_42 ( & V_2 -> V_87 ) ;
F_89 ( & V_231 ) ;
F_90 ( V_16 , V_231 . V_236 , V_231 . V_237 ) ;
V_18 = F_91 ( V_16 -> V_238 , L_42 ,
0444 , & V_239 , V_16 ) ;
if ( V_18 )
F_22 ( L_43 ,
V_16 -> V_29 , V_18 ) ;
V_18 = F_92 ( & V_2 -> V_81 , V_16 -> V_29 ,
V_240 ) ;
if ( V_18 ) {
F_12 ( L_44 , V_18 ) ;
goto V_227;
}
return 0 ;
V_227:
return V_18 ;
}
static int F_93 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
F_94 ( & V_2 -> V_81 ) ;
if ( V_2 -> V_22 ) {
int V_17 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_7 . V_21 ; V_17 ++ ) {
if ( ! V_2 -> V_22 [ V_17 ] )
continue;
F_33 ( V_2 , V_17 ) ;
}
F_34 ( V_2 -> V_22 ) ;
V_2 -> V_88 = 0 ;
}
return 0 ;
}
static int F_95 ( struct V_15 * V_16 , T_1 V_106 , void * V_241 )
{
struct V_228 * V_229 = V_241 ;
struct V_12 V_12 ;
int V_85 ;
T_2 V_83 ;
int V_18 ;
switch ( V_229 -> V_242 ) {
case V_243 :
if ( F_85 ( V_229 , 1 ) > sizeof( V_12 . V_13 ) ) {
V_18 = - V_26 ;
goto V_227;
}
F_87 ( & V_12 , F_86 ( V_229 , 1 ) ) ;
if ( sscanf ( F_86 ( V_229 , 2 ) , L_45 , & V_83 ) != 1 ) {
V_18 = - V_26 ;
goto V_227;
}
if ( sscanf ( F_86 ( V_229 , 3 ) , L_46 , & V_85 ) != 1 ) {
V_18 = - V_26 ;
goto V_227;
}
V_18 = F_35 ( V_16 , & V_12 , V_83 , V_85 ) ;
goto V_227;
default:
F_12 ( L_47 , V_229 -> V_242 ) ;
V_18 = - V_26 ;
goto V_227;
}
V_227:
return V_18 ;
}
static int F_96 ( const struct V_52 * V_53 , struct V_34 * exp ,
struct V_167 * V_244 , T_4 V_245 , T_2 V_246 )
{
struct V_15 * V_16 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
struct V_167 * V_247 ;
int V_18 = 0 ;
T_1 V_17 ;
V_18 = F_19 ( V_16 ) ;
if ( V_18 )
return V_18 ;
V_247 = F_41 ( sizeof( * V_247 ) , V_94 ) ;
if ( ! V_247 )
return - V_95 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_7 . V_21 ; V_17 ++ ) {
if ( ! V_2 -> V_22 [ V_17 ] || ! V_2 -> V_22 [ V_17 ] -> V_9 )
continue;
V_18 = V_167 ( V_53 , V_2 -> V_22 [ V_17 ] -> V_9 , V_247 ,
V_245 , V_246 ) ;
if ( V_18 ) {
F_12 ( L_48 , V_17 ,
V_2 -> V_22 [ V_17 ] -> V_9 -> V_10 -> V_29 ,
V_18 ) ;
goto V_248;
}
if ( V_17 == 0 ) {
* V_244 = * V_247 ;
if ( V_246 & V_249 )
goto V_248;
} else {
V_244 -> V_250 += V_247 -> V_250 ;
V_244 -> V_251 += V_247 -> V_251 ;
V_244 -> V_252 += V_247 -> V_252 ;
V_244 -> V_253 += V_247 -> V_253 ;
}
}
V_248:
F_34 ( V_247 ) ;
return V_18 ;
}
static int F_97 ( struct V_34 * exp ,
struct V_98 * V_195 )
{
struct V_15 * V_16 = exp -> V_10 ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
int V_18 ;
V_18 = F_19 ( V_16 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_98 ( V_2 -> V_22 [ 0 ] -> V_9 , V_195 ) ;
return V_18 ;
}
static int F_99 ( struct V_34 * exp , const struct V_98 * V_195 ,
T_5 V_254 , const char * V_255 ,
const char * V_256 , int V_257 , int V_258 ,
int V_246 , struct V_259 * * V_260 )
{
struct V_15 * V_16 = exp -> V_10 ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_18 ;
V_18 = F_19 ( V_16 ) ;
if ( V_18 )
return V_18 ;
V_4 = F_51 ( V_2 , V_195 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_18 = F_100 ( V_4 -> V_9 , V_195 , V_254 , V_255 , V_256 ,
V_257 , V_258 , V_246 , V_260 ) ;
return V_18 ;
}
static int F_101 ( struct V_34 * exp , const struct V_98 * V_195 ,
T_5 V_254 , const char * V_255 ,
const char * V_256 , int V_257 , int V_258 ,
int V_246 , T_2 V_261 ,
struct V_259 * * V_260 )
{
struct V_15 * V_16 = exp -> V_10 ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_18 ;
V_18 = F_19 ( V_16 ) ;
if ( V_18 )
return V_18 ;
V_4 = F_51 ( V_2 , V_195 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_18 = F_102 ( V_4 -> V_9 , V_195 , V_254 , V_255 , V_256 ,
V_257 , V_258 , V_246 , V_261 ,
V_260 ) ;
return V_18 ;
}
static int F_103 ( struct V_34 * exp , struct V_200 * V_201 ,
struct V_259 * * V_260 )
{
struct V_15 * V_16 = exp -> V_10 ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_18 ;
V_18 = F_19 ( V_16 ) ;
if ( V_18 )
return V_18 ;
V_4 = F_51 ( V_2 , & V_201 -> V_202 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
if ( V_201 -> V_262 & V_263 ) {
V_201 -> V_226 = V_4 -> V_80 ;
return 0 ;
}
V_18 = F_104 ( V_4 -> V_9 , V_201 , V_260 ) ;
return V_18 ;
}
static int F_105 ( struct V_34 * exp , const struct V_98 * V_195 )
{
struct V_15 * V_16 = exp -> V_10 ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
T_1 V_17 ;
int V_18 ;
V_18 = F_19 ( V_16 ) ;
if ( V_18 )
return V_18 ;
F_3 ( V_264 , L_49 V_124 L_50 , F_55 ( V_195 ) ) ;
for ( V_17 = 0 ; V_17 < V_2 -> V_7 . V_21 ; V_17 ++ ) {
if ( ! V_2 -> V_22 [ V_17 ] || ! V_2 -> V_22 [ V_17 ] -> V_9 )
continue;
F_106 ( V_2 -> V_22 [ V_17 ] -> V_9 , V_195 ) ;
}
return 0 ;
}
static int F_107 ( struct V_34 * exp , struct V_200 * V_201 ,
struct V_265 * V_266 , struct V_259 * * V_260 )
{
struct V_15 * V_16 = exp -> V_10 ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_18 ;
V_18 = F_19 ( V_16 ) ;
if ( V_18 )
return V_18 ;
V_4 = F_51 ( V_2 , & V_201 -> V_202 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
F_3 ( V_264 , L_51 V_124 L_50 , F_55 ( & V_201 -> V_202 ) ) ;
V_18 = F_108 ( V_4 -> V_9 , V_201 , V_266 , V_260 ) ;
return V_18 ;
}
static struct V_3 *
F_109 ( struct V_1 * V_2 , struct V_97 * V_267 ,
const char * V_255 , int V_268 , struct V_98 * V_195 ,
T_1 * V_219 )
{
const struct V_269 * V_270 ;
struct V_3 * V_4 ;
if ( F_110 ( V_271 ) ) {
if ( V_272 >= V_267 -> V_273 )
return F_111 ( - V_156 ) ;
V_270 = & V_267 -> V_274 [ V_272 ] ;
} else {
V_270 = F_112 ( V_267 , V_255 , V_268 ) ;
if ( F_52 ( V_270 ) )
return F_113 ( V_270 ) ;
}
if ( V_195 )
* V_195 = V_270 -> V_275 ;
if ( V_219 )
* V_219 = V_270 -> V_276 ;
V_4 = F_81 ( V_2 , V_270 -> V_276 , NULL ) ;
F_3 ( V_19 , L_52 V_124 L_50 , V_270 -> V_276 ,
F_55 ( & V_270 -> V_275 ) ) ;
return V_4 ;
}
struct V_3 *
F_114 ( struct V_1 * V_2 , struct V_200 * V_201 ,
struct V_98 * V_195 )
{
struct V_97 * V_267 = V_201 -> V_277 ;
struct V_3 * V_4 ;
if ( V_201 -> V_278 & V_279 &&
( int ) V_201 -> V_226 != - 1 ) {
int V_17 ;
V_4 = F_81 ( V_2 , V_201 -> V_226 , NULL ) ;
if ( F_52 ( V_4 ) )
return V_4 ;
if ( V_267 ) {
for ( V_17 = 0 ; V_17 < V_267 -> V_273 ; V_17 ++ ) {
struct V_269 * V_270 ;
V_270 = & V_267 -> V_274 [ V_17 ] ;
if ( V_270 -> V_276 == V_201 -> V_226 ) {
* V_195 = V_270 -> V_275 ;
break;
}
}
if ( V_17 == V_267 -> V_273 )
* V_195 = V_267 -> V_274 [ 0 ] . V_275 ;
}
return V_4 ;
}
if ( ! V_267 || ! V_201 -> V_280 ) {
V_4 = F_51 ( V_2 , V_195 ) ;
if ( F_52 ( V_4 ) )
return V_4 ;
V_201 -> V_226 = V_4 -> V_80 ;
return V_4 ;
}
return F_109 ( V_2 , V_267 , V_201 -> V_281 ,
V_201 -> V_280 , V_195 ,
& V_201 -> V_226 ) ;
}
static int F_115 ( struct V_34 * exp , struct V_200 * V_201 ,
const void * V_39 , T_6 V_282 , T_7 V_283 ,
T_8 V_284 , T_9 V_285 , T_10 V_286 ,
T_4 V_287 , struct V_259 * * V_260 )
{
struct V_15 * V_16 = exp -> V_10 ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_18 ;
V_18 = F_19 ( V_16 ) ;
if ( V_18 )
return V_18 ;
if ( ! V_2 -> V_7 . V_8 )
return - V_218 ;
V_4 = F_114 ( V_2 , V_201 , & V_201 -> V_202 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
F_3 ( V_264 , L_53 V_124 L_54 ,
( int ) V_201 -> V_280 , V_201 -> V_281 ,
F_55 ( & V_201 -> V_202 ) , V_201 -> V_226 ) ;
V_18 = F_83 ( NULL , exp , & V_201 -> V_215 , V_201 ) ;
if ( V_18 )
return V_18 ;
if ( F_116 ( exp ) & V_288 ) {
V_4 = F_51 ( V_2 , & V_201 -> V_215 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_201 -> V_226 = V_4 -> V_80 ;
} else {
F_3 ( V_74 , L_55 ) ;
}
F_3 ( V_264 , L_56 V_124 L_54 ,
F_55 ( & V_201 -> V_202 ) , V_201 -> V_226 ) ;
V_201 -> V_262 |= V_289 ;
V_18 = F_117 ( V_4 -> V_9 , V_201 , V_39 , V_282 , V_283 , V_284 , V_285 ,
V_286 , V_287 , V_260 ) ;
if ( V_18 == 0 ) {
if ( ! * V_260 )
return V_18 ;
F_3 ( V_264 , L_57 V_124 L_50 , F_55 ( & V_201 -> V_215 ) ) ;
}
return V_18 ;
}
static int
F_118 ( struct V_34 * exp , struct V_290 * V_291 ,
const union V_292 * V_293 ,
struct V_294 * V_295 , struct V_200 * V_201 ,
struct V_56 * V_296 , T_4 V_297 )
{
struct V_15 * V_16 = exp -> V_10 ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_18 ;
V_18 = F_19 ( V_16 ) ;
if ( V_18 )
return V_18 ;
F_3 ( V_264 , L_58 V_124 L_50 ,
F_119 ( V_295 ) , F_55 ( & V_201 -> V_202 ) ) ;
V_4 = F_114 ( V_2 , V_201 , & V_201 -> V_202 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
F_3 ( V_264 , L_58 V_124 L_59 ,
F_119 ( V_295 ) , F_55 ( & V_201 -> V_202 ) , V_4 -> V_80 ) ;
V_18 = F_120 ( V_4 -> V_9 , V_291 , V_293 , V_295 , V_201 , V_296 ,
V_297 ) ;
return V_18 ;
}
static int
F_121 ( struct V_34 * exp , struct V_200 * V_201 ,
struct V_259 * * V_298 )
{
struct V_259 * V_211 = NULL ;
struct V_15 * V_16 = exp -> V_10 ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
struct V_3 * V_4 ;
struct V_299 * V_300 ;
int V_18 ;
V_18 = F_19 ( V_16 ) ;
if ( V_18 )
return V_18 ;
V_4 = F_114 ( V_2 , V_201 , & V_201 -> V_202 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
F_3 ( V_264 , L_60 V_124 L_59 ,
( int ) V_201 -> V_280 , V_201 -> V_281 ,
F_55 ( & V_201 -> V_202 ) , V_4 -> V_80 ) ;
V_18 = F_122 ( V_4 -> V_9 , V_201 , V_298 ) ;
if ( V_18 != 0 )
return V_18 ;
V_300 = F_123 ( & ( * V_298 ) -> V_301 , & V_302 ) ;
if ( V_300 -> V_303 & V_304 ) {
struct V_98 V_305 = V_300 -> V_306 ;
F_3 ( V_264 , L_61 V_124 L_50 ,
F_55 ( & V_305 ) ) ;
V_4 = F_51 ( V_2 , & V_305 ) ;
if ( F_52 ( V_4 ) ) {
F_124 ( * V_298 ) ;
* V_298 = NULL ;
return F_53 ( V_4 ) ;
}
V_201 -> V_202 = V_305 ;
V_201 -> V_307 |= V_308 ;
V_201 -> V_280 = 0 ;
V_201 -> V_281 = NULL ;
V_18 = F_122 ( V_4 -> V_9 , V_201 , & V_211 ) ;
F_124 ( * V_298 ) ;
* V_298 = V_211 ;
}
return V_18 ;
}
static int F_125 ( struct V_34 * exp , struct V_3 * V_4 ,
struct V_200 * V_201 , int V_309 ,
enum V_310 V_283 , int V_311 , int V_312 )
{
struct V_98 * V_195 = F_126 ( V_201 , V_312 ) ;
struct V_15 * V_16 = exp -> V_10 ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
union V_292 V_293 = { { 0 } } ;
int V_18 = 0 ;
if ( ! F_56 ( V_195 ) )
return 0 ;
if ( ! V_4 ) {
V_4 = F_51 ( V_2 , V_195 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
}
if ( V_4 -> V_80 != V_309 ) {
F_3 ( V_264 , L_62 V_124 L_50 , F_55 ( V_195 ) ) ;
V_293 . V_313 . V_311 = V_311 ;
V_18 = F_127 ( V_4 -> V_9 , V_195 , & V_293 ,
V_283 , V_314 , NULL ) ;
} else {
F_3 ( V_264 ,
L_63 V_124 L_50 ,
V_309 , F_55 ( V_195 ) ) ;
V_201 -> V_262 |= V_312 ;
V_18 = 0 ;
}
return V_18 ;
}
static int F_128 ( struct V_34 * exp , struct V_200 * V_201 ,
struct V_259 * * V_260 )
{
struct V_15 * V_16 = exp -> V_10 ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_18 ;
V_18 = F_19 ( V_16 ) ;
if ( V_18 )
return V_18 ;
F_7 ( V_201 -> V_280 != 0 ) ;
F_3 ( V_264 , L_64 V_124 L_65 V_124 L_50 ,
F_55 ( & V_201 -> V_215 ) , ( int ) V_201 -> V_280 ,
V_201 -> V_281 , F_55 ( & V_201 -> V_202 ) ) ;
V_201 -> V_315 = F_129 ( & V_316 , F_130 () ) ;
V_201 -> V_317 = F_131 ( & V_316 , F_132 () ) ;
V_201 -> V_318 = F_133 () ;
if ( V_201 -> V_319 ) {
struct V_97 * V_267 = V_201 -> V_319 ;
const struct V_269 * V_270 ;
V_270 = F_112 ( V_267 , V_201 -> V_281 ,
V_201 -> V_280 ) ;
if ( F_52 ( V_270 ) )
return F_53 ( V_270 ) ;
V_201 -> V_215 = V_270 -> V_275 ;
}
V_4 = F_114 ( V_2 , V_201 , & V_201 -> V_215 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_201 -> V_262 |= V_320 ;
V_18 = F_125 ( exp , NULL , V_201 , V_4 -> V_80 , V_321 ,
V_322 , V_289 ) ;
if ( V_18 != 0 )
return V_18 ;
V_18 = F_134 ( V_4 -> V_9 , V_201 , V_260 ) ;
return V_18 ;
}
static int F_135 ( struct V_34 * exp , struct V_200 * V_201 ,
const char * V_91 , T_6 V_323 ,
const char * V_324 , T_6 V_325 ,
struct V_259 * * V_260 )
{
struct V_15 * V_16 = exp -> V_10 ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
struct V_34 * V_326 ;
struct V_3 * V_327 ;
struct V_3 * V_328 ;
struct V_299 * V_300 ;
int V_18 ;
F_7 ( V_323 != 0 ) ;
F_3 ( V_264 , L_66 V_124 L_67 V_124 L_68 ,
( int ) V_323 , V_91 , F_55 ( & V_201 -> V_202 ) ,
V_201 -> V_277 ? V_201 -> V_277 -> V_273 : 0 ,
( int ) V_325 , V_324 , F_55 ( & V_201 -> V_215 ) ,
V_201 -> V_319 ? V_201 -> V_319 -> V_273 : 0 ) ;
V_18 = F_19 ( V_16 ) ;
if ( V_18 )
return V_18 ;
V_201 -> V_315 = F_129 ( & V_316 , F_130 () ) ;
V_201 -> V_317 = F_131 ( & V_316 , F_132 () ) ;
V_201 -> V_318 = F_133 () ;
if ( V_201 -> V_221 & V_329 ) {
F_136 ( F_56 ( & V_201 -> V_330 ) , L_69 V_124 L_50 ,
F_55 ( & V_201 -> V_330 ) ) ;
if ( V_201 -> V_277 ) {
struct V_97 * V_267 = V_201 -> V_277 ;
struct V_3 * V_331 ;
V_331 = F_109 ( V_2 , V_267 , V_91 ,
V_323 ,
& V_201 -> V_202 ,
NULL ) ;
if ( F_52 ( V_331 ) )
return F_53 ( V_331 ) ;
}
V_18 = F_83 ( NULL , exp , & V_201 -> V_215 , V_201 ) ;
if ( V_18 )
return V_18 ;
V_327 = F_51 ( V_2 , & V_201 -> V_330 ) ;
if ( F_52 ( V_327 ) )
return F_53 ( V_327 ) ;
V_326 = V_327 -> V_9 ;
} else {
if ( V_201 -> V_277 ) {
struct V_97 * V_267 = V_201 -> V_277 ;
V_327 = F_109 ( V_2 , V_267 , V_91 ,
V_323 ,
& V_201 -> V_202 ,
& V_201 -> V_226 ) ;
} else {
V_327 = F_51 ( V_2 , & V_201 -> V_202 ) ;
}
if ( F_52 ( V_327 ) )
return F_53 ( V_327 ) ;
if ( V_201 -> V_319 ) {
struct V_97 * V_267 = V_201 -> V_319 ;
V_328 = F_109 ( V_2 , V_267 , V_324 ,
V_325 ,
& V_201 -> V_215 ,
& V_201 -> V_226 ) ;
} else {
V_328 = F_51 ( V_2 , & V_201 -> V_215 ) ;
}
if ( F_52 ( V_328 ) )
return F_53 ( V_328 ) ;
V_326 = V_328 -> V_9 ;
}
V_201 -> V_262 |= V_289 | V_332 ;
V_18 = F_125 ( exp , NULL , V_201 , V_327 -> V_80 ,
V_321 , V_322 ,
V_320 ) ;
if ( V_18 )
return V_18 ;
if ( F_56 ( & V_201 -> V_330 ) ) {
struct V_3 * V_4 ;
V_4 = F_51 ( V_2 , & V_201 -> V_202 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_18 = F_125 ( exp , V_4 , V_201 , V_327 -> V_80 ,
V_321 , V_333 ,
V_332 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_125 ( exp , NULL , V_201 , V_327 -> V_80 ,
V_321 , V_334 ,
V_332 ) ;
if ( V_18 )
return V_18 ;
}
V_335:
if ( F_56 ( & V_201 -> V_336 ) ) {
struct V_3 * V_4 ;
V_18 = F_125 ( exp , NULL , V_201 , V_327 -> V_80 ,
V_321 , V_334 ,
V_337 ) ;
if ( V_18 )
return V_18 ;
V_4 = F_51 ( V_2 , & V_201 -> V_336 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_326 = V_4 -> V_9 ;
}
V_18 = F_137 ( V_326 , V_201 , V_91 , V_323 , V_324 , V_325 , V_260 ) ;
if ( V_18 && V_18 != - V_117 )
return V_18 ;
V_300 = F_123 ( & ( * V_260 ) -> V_301 , & V_302 ) ;
if ( ! V_300 )
return - V_338 ;
if ( F_138 ( ! ( V_300 -> V_303 & V_304 ) ) )
return V_18 ;
F_3 ( V_264 , L_70 V_124 L_50 ,
exp -> V_10 -> V_29 , F_55 ( & V_300 -> V_306 ) ) ;
V_201 -> V_336 = V_300 -> V_306 ;
F_124 ( * V_260 ) ;
* V_260 = NULL ;
goto V_335;
}
static int F_139 ( struct V_34 * exp , struct V_200 * V_201 ,
void * V_339 , T_6 V_340 , struct V_259 * * V_260 )
{
struct V_15 * V_16 = exp -> V_10 ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_18 ;
V_18 = F_19 ( V_16 ) ;
if ( V_18 )
return V_18 ;
F_3 ( V_264 , L_71 V_124 L_72 ,
F_55 ( & V_201 -> V_202 ) , V_201 -> V_341 . V_342 ) ;
V_201 -> V_262 |= V_289 ;
V_4 = F_51 ( V_2 , & V_201 -> V_202 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
return F_140 ( V_4 -> V_9 , V_201 , V_339 , V_340 , V_260 ) ;
}
static int F_141 ( struct V_34 * exp , const struct V_98 * V_195 ,
struct V_259 * * V_260 )
{
struct V_15 * V_16 = exp -> V_10 ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_18 ;
V_18 = F_19 ( V_16 ) ;
if ( V_18 )
return V_18 ;
V_4 = F_51 ( V_2 , V_195 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_18 = F_142 ( V_4 -> V_9 , V_195 , V_260 ) ;
return V_18 ;
}
static int F_143 ( struct V_34 * exp ,
struct V_200 * V_201 ,
struct V_343 * V_344 ,
T_4 V_345 , int * V_346 ,
struct V_347 * * V_348 ,
struct V_349 * * V_350 )
{
struct V_97 * V_267 = V_201 -> V_277 ;
struct V_15 * V_16 = exp -> V_10 ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
struct V_347 * V_351 = NULL ;
struct V_349 * V_352 = NULL ;
struct V_3 * V_4 ;
int V_353 ;
int V_354 = 0 ;
int V_18 = 0 ;
int V_17 ;
V_353 = V_267 -> V_273 ;
for ( V_17 = 0 ; V_17 < V_353 ; V_17 ++ ) {
T_4 V_355 = V_345 ;
struct V_347 * V_356 = NULL ;
struct V_349 * V_349 = NULL ;
struct V_357 * V_358 ;
V_4 = F_81 ( V_2 , V_267 -> V_274 [ V_17 ] . V_276 , NULL ) ;
if ( F_52 ( V_4 ) ) {
V_18 = F_53 ( V_4 ) ;
goto V_227;
}
V_201 -> V_202 = V_267 -> V_274 [ V_17 ] . V_275 ;
V_201 -> V_215 = V_267 -> V_274 [ V_17 ] . V_275 ;
V_201 -> V_201 = V_267 -> V_274 [ V_17 ] . V_359 ;
V_360:
V_18 = F_144 ( V_4 -> V_9 , V_201 , V_344 , V_355 ,
& V_349 ) ;
if ( V_18 )
goto V_227;
V_358 = F_145 ( V_349 ) ;
for ( V_356 = F_146 ( V_358 ) ; V_356 ;
V_356 = F_147 ( V_356 ) ) {
if ( ! F_148 ( V_356 -> V_361 ) )
continue;
if ( F_149 ( V_356 -> V_362 ) < V_345 )
continue;
if ( F_149 ( V_356 -> V_362 ) == V_345 &&
( * V_348 == V_356 || V_17 < * V_346 ) )
continue;
if ( V_17 && ( ! strncmp ( V_356 -> V_363 , L_73 ,
F_148 ( V_356 -> V_361 ) ) ||
! strncmp ( V_356 -> V_363 , L_74 ,
F_148 ( V_356 -> V_361 ) ) ) )
continue;
break;
}
if ( ! V_356 ) {
V_355 = F_149 ( V_358 -> V_364 ) ;
F_150 ( V_349 ) ;
F_151 ( V_349 ) ;
V_349 = NULL ;
if ( V_355 == V_365 )
continue;
else
goto V_360;
}
if ( V_351 ) {
if ( F_149 ( V_351 -> V_362 ) >
F_149 ( V_356 -> V_362 ) ) {
V_351 = V_356 ;
F_150 ( V_352 ) ;
F_151 ( V_352 ) ;
V_354 = V_17 ;
V_352 = V_349 ;
} else {
F_150 ( V_349 ) ;
F_151 ( V_349 ) ;
V_349 = NULL ;
}
} else {
V_351 = V_356 ;
V_352 = V_349 ;
V_354 = V_17 ;
}
}
V_227:
if ( * V_350 ) {
F_150 ( * V_350 ) ;
F_151 ( * V_350 ) ;
}
* V_346 = V_354 ;
* V_348 = V_351 ;
* V_350 = V_352 ;
return V_18 ;
}
static int F_152 ( struct V_34 * exp ,
struct V_200 * V_201 ,
struct V_343 * V_344 ,
T_4 V_366 , struct V_349 * * V_350 )
{
struct V_367 * V_368 = V_201 -> V_201 ;
struct V_98 V_369 = V_201 -> V_202 ;
struct V_15 * V_16 = exp -> V_10 ;
T_4 V_345 = V_366 ;
struct V_349 * V_370 = NULL ;
struct V_349 * V_371 = NULL ;
struct V_347 * V_351 = NULL ;
struct V_347 * V_372 ;
struct V_347 * V_356 ;
struct V_357 * V_358 ;
T_6 V_373 ;
int V_374 = 0 ;
void * V_375 ;
int V_18 ;
V_18 = F_19 ( V_16 ) ;
if ( V_18 )
return V_18 ;
V_371 = F_153 ( V_376 ) ;
if ( ! V_371 )
return - V_95 ;
V_358 = F_154 ( V_371 ) ;
memset ( V_358 , 0 , sizeof( * V_358 ) ) ;
V_358 -> V_377 = F_155 ( V_366 ) ;
V_358 -> V_378 |= V_379 ;
V_375 = V_358 + 1 ;
V_373 = V_380 - sizeof( * V_358 ) ;
V_356 = V_375 ;
V_372 = V_356 ;
do {
T_11 V_381 ;
V_18 = F_143 ( exp , V_201 , V_344 , V_345 ,
& V_374 , & V_351 ,
& V_370 ) ;
if ( V_18 )
goto V_227;
if ( ! V_351 ) {
V_372 -> V_382 = 0 ;
V_345 = V_365 ;
goto V_227;
}
V_381 = F_148 ( V_351 -> V_382 ) ;
if ( ! V_381 )
V_381 = F_156 (
F_148 ( V_351 -> V_361 ) ,
F_78 ( V_351 -> V_383 ) ) ;
if ( V_381 > V_373 ) {
V_372 -> V_382 = F_157 ( 0 ) ;
V_345 = F_149 ( V_351 -> V_362 ) ;
goto V_227;
}
memcpy ( V_356 , V_351 , V_381 ) ;
if ( ! strncmp ( V_356 -> V_363 , L_73 ,
F_148 ( V_356 -> V_361 ) ) &&
F_148 ( V_356 -> V_361 ) == 1 )
F_158 ( & V_356 -> V_384 , & V_369 ) ;
else if ( ! strncmp ( V_356 -> V_363 , L_74 ,
F_148 ( V_356 -> V_361 ) ) &&
F_148 ( V_356 -> V_361 ) == 2 )
F_158 ( & V_356 -> V_384 , & V_201 -> V_330 ) ;
V_373 -= V_381 ;
V_356 -> V_382 = F_157 ( V_381 ) ;
V_372 = V_356 ;
V_356 = ( void * ) V_356 + V_381 ;
V_345 = F_149 ( V_351 -> V_362 ) ;
if ( V_345 == V_365 ) {
V_372 -> V_382 = 0 ;
break;
}
} while ( 1 );
V_227:
if ( V_370 ) {
F_150 ( V_370 ) ;
F_151 ( V_370 ) ;
}
if ( F_159 ( V_18 ) ) {
F_160 ( V_371 ) ;
V_371 = NULL ;
} else {
if ( V_356 == V_375 )
V_358 -> V_378 |= V_385 ;
V_358 -> V_378 = F_79 ( V_358 -> V_378 ) ;
V_358 -> V_364 = F_155 ( V_345 ) ;
}
V_201 -> V_202 = V_369 ;
V_201 -> V_215 = V_369 ;
V_201 -> V_201 = V_368 ;
* V_350 = V_371 ;
return V_18 ;
}
static int F_161 ( struct V_34 * exp , struct V_200 * V_201 ,
struct V_343 * V_344 , T_4 V_366 ,
struct V_349 * * V_350 )
{
struct V_97 * V_267 = V_201 -> V_277 ;
struct V_15 * V_16 = exp -> V_10 ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_18 ;
V_18 = F_19 ( V_16 ) ;
if ( V_18 )
return V_18 ;
if ( F_159 ( V_267 ) ) {
V_18 = F_152 ( exp , V_201 , V_344 , V_366 , V_350 ) ;
return V_18 ;
}
V_4 = F_51 ( V_2 , & V_201 -> V_202 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_18 = F_144 ( V_4 -> V_9 , V_201 , V_344 , V_366 , V_350 ) ;
return V_18 ;
}
static int F_162 ( struct V_34 * exp , struct V_200 * V_201 ,
struct V_259 * * V_260 )
{
struct V_97 * V_267 = V_201 -> V_277 ;
struct V_15 * V_16 = exp -> V_10 ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
struct V_3 * V_386 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_299 * V_300 ;
int V_387 = 0 ;
int V_18 ;
V_18 = F_19 ( V_16 ) ;
if ( V_18 )
return V_18 ;
V_388:
if ( V_267 ) {
struct V_3 * V_331 ;
F_7 ( V_201 -> V_281 && V_201 -> V_280 ) ;
V_331 = F_109 ( V_2 , V_267 ,
V_201 -> V_281 ,
V_201 -> V_280 ,
& V_201 -> V_202 ,
& V_201 -> V_226 ) ;
if ( F_52 ( V_331 ) && F_53 ( V_331 ) != - V_389 )
return F_53 ( V_331 ) ;
if ( ! F_163 ( V_267 -> V_390 ) ) {
struct V_269 * V_270 ;
V_270 = & V_267 -> V_274 [ V_387 ] ;
V_201 -> V_202 = V_270 -> V_275 ;
V_201 -> V_226 = V_270 -> V_276 ;
}
}
V_391:
if ( F_138 ( ! F_164 ( & V_201 -> V_215 ) ) )
V_4 = F_51 ( V_2 , & V_201 -> V_215 ) ;
else if ( V_267 )
V_4 = F_81 ( V_2 , V_201 -> V_226 , NULL ) ;
else
V_4 = F_114 ( V_2 , V_201 , & V_201 -> V_202 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_201 -> V_315 = F_129 ( & V_316 , F_130 () ) ;
V_201 -> V_317 = F_131 ( & V_316 , F_132 () ) ;
V_201 -> V_318 = F_133 () ;
V_201 -> V_262 |= V_289 | V_332 ;
V_386 = F_51 ( V_2 , & V_201 -> V_202 ) ;
if ( F_52 ( V_386 ) )
return F_53 ( V_386 ) ;
if ( V_386 != V_4 ) {
V_18 = F_125 ( exp , V_386 , V_201 , V_4 -> V_80 ,
V_321 , V_333 ,
V_332 ) ;
}
V_18 = F_125 ( exp , NULL , V_201 , V_4 -> V_80 , V_321 ,
V_334 , V_332 ) ;
if ( V_18 != 0 )
return V_18 ;
F_3 ( V_264 , L_75 V_124 L_76 V_124 L_59 ,
F_55 ( & V_201 -> V_202 ) , F_55 ( & V_201 -> V_215 ) , V_4 -> V_80 ) ;
V_18 = F_165 ( V_4 -> V_9 , V_201 , V_260 ) ;
if ( V_18 != 0 && V_18 != - V_117 && V_18 != - V_392 )
return V_18 ;
if ( V_18 == - V_392 && V_267 && F_166 ( V_267 ) ) {
struct V_269 * V_270 ;
V_387 ++ ;
if ( V_387 >= V_267 -> V_273 )
return V_18 ;
V_270 = & V_267 -> V_274 [ V_387 ] ;
V_201 -> V_202 = V_270 -> V_275 ;
V_201 -> V_226 = V_270 -> V_276 ;
F_124 ( * V_260 ) ;
* V_260 = NULL ;
goto V_391;
}
V_300 = F_123 ( & ( * V_260 ) -> V_301 , & V_302 ) ;
if ( ! V_300 )
return - V_338 ;
if ( F_138 ( ! ( V_300 -> V_303 & V_304 ) ) )
return V_18 ;
F_3 ( V_264 , L_77 V_124 L_50 ,
exp -> V_10 -> V_29 , F_55 ( & V_300 -> V_306 ) ) ;
V_201 -> V_215 = V_300 -> V_306 ;
F_124 ( * V_260 ) ;
* V_260 = NULL ;
goto V_388;
}
static int F_167 ( struct V_15 * V_16 )
{
F_168 ( & V_16 -> V_35 . V_2 . V_81 ) ;
F_169 ( V_16 ) ;
return 0 ;
}
static int F_170 ( const struct V_52 * V_53 , struct V_34 * exp ,
T_2 V_393 , void * V_394 , T_2 * V_395 , void * V_396 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 ;
int V_18 = 0 ;
V_16 = F_6 ( exp ) ;
if ( ! V_16 ) {
F_3 ( V_397 , L_78 ,
exp -> V_24 . V_25 ) ;
return - V_26 ;
}
V_2 = & V_16 -> V_35 . V_2 ;
if ( V_393 >= strlen ( L_79 ) && ! strcmp ( V_394 , L_79 ) ) {
int V_17 ;
V_18 = F_19 ( V_16 ) ;
if ( V_18 )
return V_18 ;
F_7 ( * V_395 == sizeof( T_2 ) ) ;
for ( V_17 = 0 ; V_17 < V_2 -> V_7 . V_21 ; V_17 ++ ) {
struct V_3 * V_4 = V_2 -> V_22 [ V_17 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
continue;
if ( ! F_171 ( V_53 , V_4 -> V_9 , V_393 , V_394 ,
V_395 , V_396 ) )
return 0 ;
}
return - V_26 ;
} else if ( F_172 ( V_398 ) ||
F_172 ( V_399 ) ||
F_172 ( V_400 ) ) {
V_18 = F_19 ( V_16 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_171 ( V_53 , V_2 -> V_22 [ 0 ] -> V_9 , V_393 , V_394 ,
V_395 , V_396 ) ;
if ( ! V_18 && F_172 ( V_400 ) )
exp -> V_50 = * (struct V_40 * ) V_396 ;
return V_18 ;
} else if ( F_172 ( V_401 ) ) {
* ( ( int * ) V_396 ) = V_2 -> V_7 . V_21 ;
return 0 ;
}
F_3 ( V_397 , L_80 ) ;
return - V_26 ;
}
static int F_173 ( const struct V_52 * V_53 , struct V_34 * exp ,
T_1 V_393 , void * V_394 , T_1 V_395 ,
void * V_396 , struct V_402 * V_162 )
{
struct V_3 * V_4 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
int V_18 = 0 ;
V_16 = F_6 ( exp ) ;
if ( ! V_16 ) {
F_3 ( V_397 , L_78 ,
exp -> V_24 . V_25 ) ;
return - V_26 ;
}
V_2 = & V_16 -> V_35 . V_2 ;
if ( F_172 ( V_403 ) || F_172 ( V_404 ) ||
F_172 ( V_399 ) ) {
int V_17 , V_149 = 0 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_7 . V_21 ; V_17 ++ ) {
V_4 = V_2 -> V_22 [ V_17 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
continue;
V_149 = F_174 ( V_53 , V_4 -> V_9 ,
V_393 , V_394 , V_395 , V_396 , V_162 ) ;
if ( V_149 && V_18 == 0 )
V_18 = V_149 ;
}
return V_18 ;
}
return - V_26 ;
}
static int F_175 ( struct V_34 * exp , struct V_97 * V_267 ,
const struct V_405 * V_406 )
{
struct V_1 * V_2 = & exp -> V_10 -> V_35 . V_2 ;
int V_353 ;
int V_18 = 0 ;
int V_407 ;
int V_17 ;
V_267 -> V_408 = F_78 ( V_406 -> V_409 ) ;
V_267 -> V_273 = F_78 ( V_406 -> V_410 ) ;
V_267 -> V_411 = F_78 ( V_406 -> V_412 ) ;
if ( F_110 ( V_413 ) )
V_267 -> V_390 = V_414 ;
else
V_267 -> V_390 = F_78 ( V_406 -> V_415 ) ;
V_267 -> V_416 = F_78 ( V_406 -> V_417 ) ;
V_407 = F_176 ( V_267 -> V_418 , V_406 -> V_419 ,
sizeof( V_267 -> V_418 ) ) ;
if ( V_407 >= sizeof( V_267 -> V_418 ) )
return - V_420 ;
F_3 ( V_19 , L_81 ,
V_267 -> V_273 , V_267 -> V_411 ,
V_267 -> V_390 , V_267 -> V_416 ) ;
V_353 = F_78 ( V_406 -> V_410 ) ;
for ( V_17 = 0 ; V_17 < V_353 ; V_17 ++ ) {
F_177 ( & V_267 -> V_274 [ V_17 ] . V_275 ,
& V_406 -> V_421 [ V_17 ] ) ;
V_18 = F_72 ( V_2 , & V_267 -> V_274 [ V_17 ] . V_275 ,
& V_267 -> V_274 [ V_17 ] . V_276 ) ;
if ( V_18 )
return V_18 ;
F_3 ( V_19 , L_82 V_124 L_50 , V_17 ,
F_55 ( & V_267 -> V_274 [ V_17 ] . V_275 ) ) ;
}
return V_18 ;
}
static int F_178 ( struct V_34 * exp , struct V_97 * * V_422 ,
const union V_423 * V_424 , T_6 V_425 )
{
struct V_97 * V_267 ;
bool V_426 = false ;
int V_427 , V_18 ;
F_7 ( V_422 ) ;
V_267 = * V_422 ;
if ( V_267 && ! V_424 ) {
int V_17 ;
for ( V_17 = 1 ; V_17 < V_267 -> V_273 ; V_17 ++ ) {
if ( ! ( V_267 -> V_390 & V_428 &&
! V_17 ) && V_267 -> V_274 [ V_17 ] . V_359 )
F_179 ( V_267 -> V_274 [ V_17 ] . V_359 ) ;
}
F_76 ( V_267 ) ;
* V_422 = NULL ;
return 0 ;
}
if ( F_78 ( V_424 -> V_409 ) == V_429 )
return - V_216 ;
if ( F_78 ( V_424 -> V_409 ) != V_430 &&
F_78 ( V_424 -> V_409 ) != V_431 ) {
F_12 ( L_83 ,
exp -> V_10 -> V_29 , F_78 ( V_424 -> V_409 ) ,
- V_218 ) ;
return - V_218 ;
}
if ( F_78 ( V_424 -> V_409 ) == V_430 )
V_427 = F_180 ( F_181 ( V_424 ) ) ;
else
V_427 = F_180 ( 0 ) ;
if ( ! V_267 ) {
V_267 = F_75 ( V_427 , V_94 ) ;
if ( ! V_267 )
return - V_95 ;
V_426 = true ;
* V_422 = V_267 ;
}
switch ( F_78 ( V_424 -> V_409 ) ) {
case V_430 :
V_18 = F_175 ( exp , V_267 , & V_424 -> V_432 ) ;
break;
default:
F_12 ( L_84 , exp -> V_10 -> V_29 ,
F_78 ( V_424 -> V_409 ) ) ;
V_18 = - V_26 ;
break;
}
if ( V_18 && V_426 ) {
F_76 ( V_267 ) ;
* V_422 = NULL ;
V_427 = V_18 ;
}
return V_427 ;
}
void F_182 ( struct V_97 * V_267 )
{
F_178 ( NULL , & V_267 , NULL , 0 ) ;
}
static int F_183 ( struct V_34 * exp , const struct V_98 * V_195 ,
union V_292 * V_293 ,
enum V_310 V_283 , enum V_433 V_246 ,
void * V_434 )
{
struct V_15 * V_16 = exp -> V_10 ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
int V_18 = 0 ;
int V_149 ;
T_1 V_17 ;
F_7 ( V_195 ) ;
for ( V_17 = 0 ; V_17 < V_2 -> V_7 . V_21 ; V_17 ++ ) {
struct V_3 * V_4 = V_2 -> V_22 [ V_17 ] ;
if ( ! V_4 || ! V_4 -> V_9 || ! V_4 -> V_6 )
continue;
V_149 = F_127 ( V_4 -> V_9 , V_195 , V_293 , V_283 , V_246 ,
V_434 ) ;
if ( ! V_18 )
V_18 = V_149 ;
}
return V_18 ;
}
static int F_184 ( struct V_34 * exp ,
const struct V_56 * V_296 ,
void * V_39 , T_4 * V_311 )
{
struct V_1 * V_2 = & exp -> V_10 -> V_35 . V_2 ;
struct V_3 * V_4 = V_2 -> V_22 [ 0 ] ;
int V_18 ;
if ( ! V_4 || ! V_4 -> V_9 )
return - V_26 ;
V_18 = F_185 ( V_4 -> V_9 , V_296 , V_39 , V_311 ) ;
return V_18 ;
}
static enum V_310 F_186 ( struct V_34 * exp , T_4 V_246 ,
const struct V_98 * V_195 ,
enum V_435 type ,
union V_292 * V_293 ,
enum V_310 V_283 ,
struct V_56 * V_296 )
{
struct V_15 * V_16 = exp -> V_10 ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
enum V_310 V_18 ;
int V_4 ;
T_1 V_17 ;
F_3 ( V_264 , L_85 V_124 L_50 , F_55 ( V_195 ) ) ;
for ( V_17 = 0 , V_4 = F_187 ( V_2 , V_195 ) ;
V_17 < V_2 -> V_7 . V_21 ;
V_17 ++ , V_4 = ( V_4 + 1 ) % V_2 -> V_7 . V_21 ) {
if ( V_4 < 0 ) {
F_3 ( V_436 , L_86 V_124 L_87 ,
V_16 -> V_29 , F_55 ( V_195 ) , V_4 ) ;
V_4 = 0 ;
}
if ( ! V_2 -> V_22 [ V_4 ] || ! V_2 -> V_22 [ V_4 ] -> V_9 ||
! V_2 -> V_22 [ V_4 ] -> V_6 )
continue;
V_18 = F_188 ( V_2 -> V_22 [ V_4 ] -> V_9 , V_246 , V_195 ,
type , V_293 , V_283 , V_296 ) ;
if ( V_18 )
return V_18 ;
}
return 0 ;
}
static int F_189 ( struct V_34 * exp ,
struct V_259 * V_211 ,
struct V_34 * V_437 ,
struct V_34 * V_438 ,
struct V_439 * V_440 )
{
struct V_1 * V_2 = & exp -> V_10 -> V_35 . V_2 ;
struct V_3 * V_4 = V_2 -> V_22 [ 0 ] ;
if ( ! V_4 || ! V_4 -> V_9 )
return - V_26 ;
return F_190 ( V_4 -> V_9 , V_211 , V_437 , V_438 , V_440 ) ;
}
static int F_191 ( struct V_34 * exp , struct V_439 * V_440 )
{
struct V_15 * V_16 = exp -> V_10 ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
struct V_3 * V_4 = V_2 -> V_22 [ 0 ] ;
if ( V_440 -> V_2 ) {
F_182 ( V_440 -> V_2 ) ;
V_440 -> V_2 = NULL ;
}
if ( ! V_4 || ! V_4 -> V_9 )
return - V_26 ;
return F_192 ( V_4 -> V_9 , V_440 ) ;
}
static int F_193 ( struct V_34 * exp ,
struct V_441 * V_442 ,
struct V_294 * V_295 )
{
struct V_15 * V_16 = exp -> V_10 ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
struct V_3 * V_4 ;
V_4 = F_51 ( V_2 , & V_442 -> V_443 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
return F_194 ( V_4 -> V_9 , V_442 , V_295 ) ;
}
static int F_195 ( struct V_34 * exp ,
struct V_441 * V_442 )
{
struct V_15 * V_16 = exp -> V_10 ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
struct V_3 * V_4 ;
V_4 = F_51 ( V_2 , & V_442 -> V_443 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
return F_196 ( V_4 -> V_9 , V_442 ) ;
}
static int F_197 ( struct V_34 * exp ,
struct V_444 * V_445 ,
struct V_290 * V_291 )
{
struct V_200 * V_201 = & V_445 -> V_446 ;
struct V_15 * V_16 = exp -> V_10 ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
struct V_3 * V_4 = NULL ;
int V_18 ;
V_18 = F_19 ( V_16 ) ;
if ( V_18 )
return V_18 ;
V_4 = F_114 ( V_2 , V_201 , & V_201 -> V_202 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_18 = F_198 ( V_4 -> V_9 , V_445 , V_291 ) ;
return V_18 ;
}
static int F_199 ( struct V_34 * exp , struct V_294 * V_295 ,
struct V_98 * V_195 , T_4 * V_311 )
{
struct V_15 * V_16 = exp -> V_10 ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
struct V_3 * V_4 ;
int V_18 ;
V_18 = F_19 ( V_16 ) ;
if ( V_18 )
return V_18 ;
V_4 = F_51 ( V_2 , V_195 ) ;
if ( F_52 ( V_4 ) )
return F_53 ( V_4 ) ;
V_18 = F_200 ( V_4 -> V_9 , V_295 , V_195 , V_311 ) ;
return V_18 ;
}
static int
F_201 ( struct V_34 * exp ,
const struct V_97 * V_267 ,
const char * V_255 , int V_268 , struct V_98 * V_195 )
{
const struct V_269 * V_270 ;
F_7 ( V_267 ) ;
V_270 = F_112 ( V_267 , V_255 , V_268 ) ;
if ( F_52 ( V_270 ) )
return F_53 ( V_270 ) ;
* V_195 = V_270 -> V_275 ;
return 0 ;
}
static int F_202 ( struct V_15 * V_447 , struct V_34 * exp ,
struct V_181 * V_182 )
{
struct V_15 * V_16 = F_6 ( exp ) ;
struct V_1 * V_2 = & V_16 -> V_35 . V_2 ;
struct V_3 * V_4 = V_2 -> V_22 [ 0 ] ;
int V_18 = 0 ;
T_4 V_448 = 0 , V_449 = 0 ;
T_1 V_17 ;
if ( ! V_4 || ! V_4 -> V_9 || ! V_4 -> V_6 ||
! V_2 -> V_7 . V_21 ) {
F_12 ( L_88 ) ;
return - V_218 ;
}
if ( V_182 -> V_450 != V_451 ) {
V_18 = V_181 ( V_4 -> V_9 , V_182 ) ;
return V_18 ;
}
for ( V_17 = 0 ; V_17 < V_2 -> V_7 . V_21 ; V_17 ++ ) {
int V_149 ;
V_4 = V_2 -> V_22 [ V_17 ] ;
if ( ! V_4 || ! V_4 -> V_9 || ! V_4 -> V_6 )
continue;
V_149 = V_181 ( V_4 -> V_9 , V_182 ) ;
if ( V_149 ) {
F_12 ( L_89 , V_17 , V_149 ) ;
if ( ! V_18 )
V_18 = V_149 ;
} else {
V_448 += V_182 -> V_452 . V_453 ;
V_449 += V_182 -> V_452 . V_454 ;
}
}
V_182 -> V_452 . V_453 = V_448 ;
V_182 -> V_452 . V_454 = V_449 ;
return V_18 ;
}
static int F_203 ( struct V_34 * exp ,
const struct V_97 * V_267 ,
struct V_455 * V_456 ,
T_12 V_457 )
{
int V_18 , V_17 ;
V_18 = F_204 ( exp , V_267 , V_457 , 0 ) ;
if ( V_18 < 0 )
return V_18 ;
for ( V_17 = 0 ; V_17 < V_267 -> V_273 ; V_17 ++ ) {
struct V_367 * V_367 = V_267 -> V_274 [ V_17 ] . V_359 ;
F_3 ( V_19 , L_5 V_124 L_90 ,
F_55 ( & V_267 -> V_274 [ V_17 ] . V_275 ) ,
F_205 ( V_367 ) , ( unsigned long long ) V_367 -> V_458 ,
V_367 -> V_459 , F_206 ( V_367 -> V_460 ) ,
F_206 ( V_367 -> V_461 ) , F_206 ( V_367 -> V_462 ) ) ;
if ( V_17 )
V_456 -> V_463 += V_367 -> V_459 - 2 ;
else
V_456 -> V_463 = V_367 -> V_459 ;
V_456 -> V_464 += F_205 ( V_367 ) ;
V_456 -> V_465 += V_367 -> V_458 ;
if ( V_456 -> V_466 < F_206 ( V_367 -> V_460 ) )
V_456 -> V_466 = F_206 ( V_367 -> V_460 ) ;
if ( V_456 -> V_467 < F_206 ( V_367 -> V_461 ) )
V_456 -> V_467 = F_206 ( V_367 -> V_461 ) ;
if ( V_456 -> V_468 < F_206 ( V_367 -> V_462 ) )
V_456 -> V_468 = F_206 ( V_367 -> V_462 ) ;
}
return 0 ;
}
static int T_13 F_207 ( void )
{
struct V_230 V_231 ;
int V_18 ;
F_89 ( & V_231 ) ;
V_18 = F_208 ( & V_469 , & V_470 ,
V_471 , NULL ) ;
return V_18 ;
}
static void F_209 ( void )
{
F_210 ( V_471 ) ;
}
