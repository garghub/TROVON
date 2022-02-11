static struct V_1 * F_1 ( struct V_2 * V_3 , const char * V_4 )
{
struct V_1 * V_5 ;
F_2 (tgt, &gn->targets, list)
if ( ! strcmp ( V_4 , V_5 -> V_6 -> V_7 ) )
return V_5 ;
return NULL ;
}
static int F_3 ( struct V_8 * V_9 , struct V_1 * V_10 ,
int V_11 , int V_12 )
{
int V_13 ;
for ( V_13 = V_11 ; V_13 <= V_12 ; V_13 ++ ) {
if ( F_4 ( V_13 , V_9 -> V_14 ) ) {
F_5 ( L_1 , V_13 ) ;
goto V_15;
}
}
return 0 ;
V_15:
while ( -- V_13 > V_11 )
F_6 ( V_13 , V_9 -> V_14 ) ;
return - V_16 ;
}
static void F_7 ( struct V_8 * V_9 , int V_11 ,
int V_12 )
{
int V_13 ;
for ( V_13 = V_11 ; V_13 <= V_12 ; V_13 ++ )
F_8 ( ! F_9 ( V_13 , V_9 -> V_14 ) ) ;
}
static void F_10 ( struct V_17 * V_18 )
{
struct V_8 * V_9 = V_18 -> V_19 ;
struct V_20 * V_21 = V_18 -> V_22 ;
int V_13 , V_23 ;
for ( V_13 = 0 ; V_13 < V_21 -> V_24 ; V_13 ++ ) {
struct V_25 * V_26 = & V_21 -> V_27 [ V_13 ] ;
int * V_28 = V_26 -> V_28 ;
int V_29 = V_13 + V_26 -> V_30 ;
for ( V_23 = 0 ; V_23 < V_26 -> V_31 ; V_23 ++ ) {
int V_32 = V_23 + V_28 [ V_23 ] ;
int V_33 = ( V_29 * V_9 -> V_34 . V_35 ) + V_32 ;
F_8 ( ! F_9 ( V_33 , V_9 -> V_14 ) ) ;
}
F_11 ( V_26 -> V_28 ) ;
}
F_11 ( V_21 -> V_27 ) ;
F_11 ( V_21 ) ;
F_11 ( V_18 -> V_36 ) ;
F_11 ( V_18 ) ;
}
static struct V_17 * F_12 ( struct V_8 * V_9 ,
int V_11 , int V_12 )
{
struct V_17 * V_18 = NULL ;
struct V_20 * V_37 = V_9 -> V_38 ;
struct V_20 * V_21 ;
struct V_39 * V_36 ;
int V_31 = V_12 - V_11 + 1 ;
int V_40 = V_31 ;
int V_24 = V_31 / V_9 -> V_34 . V_35 ;
int V_41 = V_31 % V_9 -> V_34 . V_35 ;
int V_42 = V_11 / V_9 -> V_34 . V_35 ;
int V_43 = V_11 % V_9 -> V_34 . V_35 ;
int V_33 = 0 ;
int V_44 = 1 ;
int V_45 ;
int V_13 , V_23 ;
V_24 = V_31 / V_9 -> V_34 . V_35 ;
V_24 = ( V_41 == 0 ) ? V_24 : V_24 + 1 ;
V_21 = F_13 ( sizeof( struct V_20 ) , V_46 ) ;
if ( ! V_21 )
goto V_47;
V_21 -> V_27 = F_14 ( V_24 , sizeof( struct V_25 ) ,
V_46 ) ;
if ( ! V_21 -> V_27 )
goto V_48;
V_36 = F_14 ( V_31 , sizeof( struct V_39 ) , V_46 ) ;
if ( ! V_36 )
goto V_49;
V_45 = ( V_40 > V_9 -> V_34 . V_35 ) ?
V_9 -> V_34 . V_35 : V_40 ;
for ( V_13 = 0 ; V_13 < V_24 ; V_13 ++ ) {
struct V_25 * V_50 = & V_37 -> V_27 [ V_13 + V_42 ] ;
int * V_51 = V_50 -> V_28 ;
struct V_25 * V_26 = & V_21 -> V_27 [ V_13 ] ;
int * V_28 ;
int V_52 = ( V_40 > V_9 -> V_34 . V_35 ) ?
V_9 -> V_34 . V_35 : V_40 ;
if ( V_44 && V_45 != V_52 )
V_44 = 0 ;
V_26 -> V_30 = V_50 -> V_30 = V_42 ;
V_26 -> V_31 = V_52 ;
V_28 = F_14 ( V_52 , sizeof( int ) , V_46 ) ;
if ( ! V_28 )
goto V_53;
for ( V_23 = 0 ; V_23 < V_52 ; V_23 ++ ) {
V_36 [ V_33 ] . V_54 = 0 ;
V_36 [ V_33 ] . V_55 . V_29 = V_13 ;
V_36 [ V_33 ++ ] . V_55 . V_32 = V_23 ;
V_28 [ V_23 ] = V_43 ;
V_51 [ V_23 + V_43 ] = V_43 ;
}
V_26 -> V_28 = V_28 ;
V_43 = 0 ;
V_40 -= V_52 ;
}
V_21 -> V_24 = V_24 ;
V_18 = F_13 ( sizeof( struct V_17 ) , V_46 ) ;
if ( ! V_18 )
goto V_53;
memcpy ( & V_18 -> V_34 , & V_9 -> V_34 , sizeof( struct V_56 ) ) ;
V_18 -> V_34 . V_24 = V_24 ;
V_18 -> V_34 . V_31 = V_31 ;
V_18 -> V_34 . V_35 = ( V_44 ) ? V_45 : - 1 ;
V_18 -> V_57 = V_31 * V_18 -> V_34 . V_58 ;
V_18 -> V_59 = V_9 -> V_59 ;
V_18 -> V_22 = V_21 ;
V_18 -> V_36 = V_36 ;
memcpy ( & V_18 -> V_60 , & V_9 -> V_60 , sizeof( struct V_61 ) ) ;
V_18 -> V_19 = V_9 ;
return V_18 ;
V_53:
while ( -- V_13 > 0 )
F_11 ( V_21 -> V_27 [ V_13 ] . V_28 ) ;
F_11 ( V_36 ) ;
V_49:
F_11 ( V_21 -> V_27 ) ;
V_48:
F_11 ( V_21 ) ;
V_47:
return V_18 ;
}
static int F_15 ( struct V_8 * V_9 , struct V_62 * V_63 )
{
struct V_2 * V_3 = V_9 -> V_64 ;
struct V_65 * V_66 = & V_63 -> V_67 . V_66 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
struct V_72 * V_73 ;
struct V_1 * V_10 ;
struct V_17 * V_18 ;
void * V_74 ;
V_73 = F_16 ( V_63 -> V_75 , 1 ) ;
if ( ! V_73 ) {
F_5 ( L_2 , V_63 -> V_75 ) ;
return - V_76 ;
}
F_17 ( & V_3 -> V_77 ) ;
V_10 = F_1 ( V_3 , V_63 -> V_78 ) ;
if ( V_10 ) {
F_5 ( L_3 ) ;
F_18 ( & V_3 -> V_77 ) ;
return - V_76 ;
}
F_18 ( & V_3 -> V_77 ) ;
V_10 = F_13 ( sizeof( struct V_1 ) , V_46 ) ;
if ( ! V_10 )
return - V_79 ;
if ( F_3 ( V_9 , V_10 , V_66 -> V_11 , V_66 -> V_12 ) )
goto V_80;
V_18 = F_12 ( V_9 , V_66 -> V_11 , V_66 -> V_12 ) ;
if ( ! V_18 ) {
F_5 ( L_4 ) ;
goto V_81;
}
V_69 = F_19 ( V_46 , V_9 -> V_59 -> V_82 ) ;
if ( ! V_69 )
goto V_47;
F_20 ( V_69 , V_73 -> V_83 ) ;
V_71 = F_21 ( 0 ) ;
if ( ! V_71 )
goto V_84;
sprintf ( V_71 -> V_7 , L_5 , V_63 -> V_78 ) ;
V_71 -> V_85 = V_86 ;
V_71 -> V_87 = 0 ;
V_71 -> V_88 = 0 ;
V_71 -> V_89 = & V_90 ;
V_71 -> V_91 = V_69 ;
V_74 = V_73 -> V_92 ( V_18 , V_71 ) ;
if ( F_22 ( V_74 ) )
goto V_93;
V_71 -> V_94 = V_74 ;
V_69 -> V_95 = V_74 ;
F_23 ( V_69 , 8 * V_9 -> V_96 -> V_97 ) ;
F_24 ( V_71 , V_73 -> V_98 ( V_74 ) ) ;
F_25 ( V_71 ) ;
V_10 -> type = V_73 ;
V_10 -> V_6 = V_71 ;
V_10 -> V_9 = V_18 ;
F_17 ( & V_3 -> V_77 ) ;
F_26 ( & V_10 -> V_99 , & V_3 -> V_100 ) ;
F_18 ( & V_3 -> V_77 ) ;
return 0 ;
V_93:
F_27 ( V_71 ) ;
V_84:
F_28 ( V_69 ) ;
V_47:
F_11 ( V_18 ) ;
V_81:
F_7 ( V_9 , V_66 -> V_11 , V_66 -> V_12 ) ;
V_80:
F_11 ( V_10 ) ;
return - V_79 ;
}
static void F_29 ( struct V_1 * V_10 )
{
struct V_72 * V_73 = V_10 -> type ;
struct V_70 * V_71 = V_10 -> V_6 ;
struct V_68 * V_59 = V_71 -> V_91 ;
F_30 ( V_71 ) ;
F_28 ( V_59 ) ;
if ( V_73 -> exit )
V_73 -> exit ( V_71 -> V_94 ) ;
F_10 ( V_10 -> V_9 ) ;
F_27 ( V_71 ) ;
F_31 ( & V_10 -> V_99 ) ;
F_11 ( V_10 ) ;
}
static int F_32 ( struct V_8 * V_9 , struct V_101 * remove )
{
struct V_2 * V_3 = V_9 -> V_64 ;
struct V_1 * V_10 ;
if ( ! V_3 )
return 1 ;
F_17 ( & V_3 -> V_77 ) ;
V_10 = F_1 ( V_3 , remove -> V_78 ) ;
if ( ! V_10 ) {
F_18 ( & V_3 -> V_77 ) ;
return 1 ;
}
F_29 ( V_10 ) ;
F_18 ( & V_3 -> V_77 ) ;
return 0 ;
}
static int F_33 ( struct V_8 * V_9 , T_1 * V_102 , T_1 V_103 )
{
struct V_56 * V_34 = & V_9 -> V_34 ;
struct V_2 * V_3 = V_9 -> V_64 ;
struct V_104 * V_105 , * V_106 , * V_107 ;
T_1 V_108 = 0 ;
T_1 V_109 = ( V_34 -> V_110 * V_9 -> V_57 ) >> 9 ;
if ( V_103 > V_109 )
return - V_76 ;
V_105 = F_13 ( sizeof( struct V_104 ) , V_46 ) ;
if ( ! V_105 )
return - V_79 ;
V_106 = NULL ;
F_34 ( & V_9 -> V_77 ) ;
F_2 (next, &gn->area_list, list) {
if ( V_108 + V_103 > V_107 -> V_108 ) {
V_108 = V_107 -> V_111 ;
V_106 = V_107 ;
continue;
}
break;
}
if ( ( V_108 + V_103 ) > V_109 ) {
F_35 ( & V_9 -> V_77 ) ;
F_11 ( V_105 ) ;
return - V_76 ;
}
V_105 -> V_108 = * V_102 = V_108 ;
V_105 -> V_111 = V_108 + V_103 ;
if ( V_106 )
F_36 ( & V_105 -> V_99 , & V_106 -> V_99 ) ;
else
F_36 ( & V_105 -> V_99 , & V_3 -> V_112 ) ;
F_35 ( & V_9 -> V_77 ) ;
return 0 ;
}
static void F_37 ( struct V_8 * V_9 , T_1 V_108 )
{
struct V_2 * V_3 = V_9 -> V_64 ;
struct V_104 * V_105 ;
F_34 ( & V_9 -> V_77 ) ;
F_2 (area, &gn->area_list, list) {
if ( V_105 -> V_108 != V_108 )
continue;
F_31 ( & V_105 -> V_99 ) ;
F_35 ( & V_9 -> V_77 ) ;
F_11 ( V_105 ) ;
return;
}
F_35 ( & V_9 -> V_77 ) ;
}
static void F_38 ( struct V_8 * V_9 )
{
F_11 ( V_9 -> V_64 ) ;
F_11 ( V_9 -> V_38 ) ;
V_9 -> V_64 = NULL ;
}
static int F_39 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
struct V_20 * V_37 ;
int V_13 , V_23 ;
if ( ! F_40 ( V_113 ) )
return - V_114 ;
V_3 = F_41 ( sizeof( struct V_2 ) , V_46 ) ;
if ( ! V_3 )
goto V_115;
V_37 = F_13 ( sizeof( struct V_20 ) , V_46 ) ;
if ( ! V_37 )
goto V_116;
V_37 -> V_27 = F_14 ( V_9 -> V_34 . V_24 , sizeof( struct V_25 ) ,
V_46 ) ;
if ( ! V_37 -> V_27 )
goto V_48;
for ( V_13 = 0 ; V_13 < V_9 -> V_34 . V_24 ; V_13 ++ ) {
struct V_25 * V_50 ;
int * V_51 ;
int V_52 = V_9 -> V_34 . V_35 ;
V_50 = & V_37 -> V_27 [ V_13 ] ;
V_50 -> V_30 = - 1 ;
V_50 -> V_31 = V_52 ;
V_51 = F_14 ( V_52 , sizeof( int ) , V_46 ) ;
if ( ! V_51 )
goto V_53;
for ( V_23 = 0 ; V_23 < V_52 ; V_23 ++ )
V_51 [ V_23 ] = - 1 ;
V_50 -> V_28 = V_51 ;
}
V_3 -> V_9 = V_9 ;
V_3 -> V_31 = V_9 -> V_34 . V_31 ;
F_42 ( & V_3 -> V_112 ) ;
F_43 ( & V_3 -> V_77 ) ;
F_42 ( & V_3 -> V_100 ) ;
V_9 -> V_64 = V_3 ;
V_9 -> V_38 = V_37 ;
return 1 ;
V_53:
while ( -- V_13 >= 0 )
F_11 ( V_37 -> V_27 [ V_13 ] . V_28 ) ;
V_48:
F_11 ( V_37 ) ;
V_116:
F_38 ( V_9 ) ;
V_115:
F_44 ( V_113 ) ;
return - V_79 ;
}
static void F_45 ( struct V_8 * V_9 )
{
struct V_2 * V_3 = V_9 -> V_64 ;
struct V_1 * V_10 , * V_117 ;
F_17 ( & V_3 -> V_77 ) ;
F_46 (t, tmp, &gn->targets, list) {
if ( V_10 -> V_9 -> V_19 != V_9 )
continue;
F_29 ( V_10 ) ;
}
F_18 ( & V_3 -> V_77 ) ;
F_38 ( V_9 ) ;
F_44 ( V_113 ) ;
}
static int F_47 ( struct V_17 * V_18 , struct V_39 * V_118 )
{
struct V_20 * V_21 = V_18 -> V_22 ;
struct V_25 * V_26 = & V_21 -> V_27 [ V_118 -> V_55 . V_29 ] ;
int V_119 = V_26 -> V_28 [ V_118 -> V_55 . V_32 ] ;
struct V_8 * V_9 = V_18 -> V_19 ;
struct V_20 * V_37 = V_9 -> V_38 ;
struct V_25 * V_50 ;
int V_120 ;
V_118 -> V_55 . V_29 += V_26 -> V_30 ;
V_118 -> V_55 . V_32 += V_119 ;
V_50 = & V_37 -> V_27 [ V_118 -> V_55 . V_29 ] ;
V_120 = V_50 -> V_28 [ V_118 -> V_55 . V_32 ] ;
if ( F_48 ( V_50 -> V_30 < 0 || V_120 < 0 ) ) {
F_5 ( L_6 ) ;
return - V_76 ;
}
return 0 ;
}
static int F_49 ( struct V_17 * V_18 , struct V_39 * V_118 )
{
struct V_8 * V_9 = V_18 -> V_19 ;
struct V_20 * V_37 = V_9 -> V_38 ;
struct V_25 * V_50 = & V_37 -> V_27 [ V_118 -> V_55 . V_29 ] ;
int V_120 = V_50 -> V_28 [ V_118 -> V_55 . V_32 ] ;
V_118 -> V_55 . V_29 -= V_50 -> V_30 ;
V_118 -> V_55 . V_32 -= V_120 ;
return 0 ;
}
static int F_50 ( struct V_17 * V_18 , struct V_121 * V_122 ,
int V_123 )
{
T_2 * V_124 ;
int V_13 ;
int V_125 = 0 ;
V_124 = ( V_123 == V_126 ) ? F_47 : F_49 ;
if ( V_122 -> V_127 == 1 )
return V_124 ( V_18 , & V_122 -> V_39 ) ;
for ( V_13 = 0 ; V_13 < V_122 -> V_127 ; V_13 ++ ) {
V_125 = V_124 ( V_18 , & V_122 -> V_128 [ V_13 ] ) ;
if ( V_125 )
goto V_129;
}
V_129:
return V_125 ;
}
static void F_51 ( struct V_121 * V_122 )
{
struct V_17 * V_18 = V_122 -> V_9 ;
struct V_130 * V_131 = V_122 -> V_131 ;
if ( V_18 )
F_50 ( V_18 , V_122 , V_132 ) ;
V_131 -> V_73 -> V_133 ( V_122 ) ;
}
static int F_52 ( struct V_17 * V_18 , struct V_121 * V_122 )
{
struct V_8 * V_9 = V_18 -> V_19 ;
if ( ! V_9 -> V_96 -> V_134 )
return - V_114 ;
F_50 ( V_18 , V_122 , V_126 ) ;
F_53 ( V_9 , V_122 ) ;
V_122 -> V_9 = V_18 ;
V_122 -> V_133 = F_51 ;
return V_9 -> V_96 -> V_134 ( V_9 , V_122 ) ;
}
static int F_54 ( struct V_17 * V_18 , struct V_39 * V_118 ,
int V_85 )
{
F_47 ( V_18 , V_118 ) ;
return F_55 ( V_18 -> V_19 , V_118 , 1 , V_85 ) ;
}
static struct V_39 F_56 ( struct V_17 * V_18 ,
struct V_39 V_118 , int V_135 )
{
T_2 * V_124 ;
struct V_39 V_54 = V_118 ;
V_124 = ( V_135 == V_126 ) ? F_47 : F_49 ;
V_124 ( V_18 , & V_54 ) ;
return V_54 ;
}
static void F_57 ( struct V_8 * V_9 , T_1 * V_136 ,
int V_103 )
{
struct V_56 * V_34 = & V_9 -> V_34 ;
struct V_20 * V_37 = V_9 -> V_38 ;
T_3 V_13 ;
for ( V_13 = 0 ; V_13 < V_103 ; V_13 ++ ) {
struct V_25 * V_50 ;
int * V_51 ;
struct V_39 V_137 ;
T_3 V_138 = F_58 ( V_136 [ V_13 ] ) ;
int V_139 ;
T_3 V_140 ;
if ( ! V_138 )
continue;
V_137 = F_59 ( V_34 , V_138 ) ;
V_50 = & V_37 -> V_27 [ V_137 . V_55 . V_29 ] ;
V_51 = V_50 -> V_28 ;
V_139 = V_137 . V_55 . V_29 * V_34 -> V_35 + V_137 . V_55 . V_32 ;
V_140 = ( ( V_50 -> V_30 * V_34 -> V_35 ) +
( V_51 [ V_137 . V_55 . V_32 ] ) ) * V_34 -> V_58 ;
V_136 [ V_13 ] -= F_60 ( V_140 ) ;
}
}
static int T_4 F_61 ( void )
{
return F_62 ( & V_141 ) ;
}
static void F_63 ( void )
{
F_64 ( & V_141 ) ;
}
