static struct V_1 * F_1
( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_6 * V_7 ;
V_7 = F_2 ( & V_5 -> V_8 . V_9 [ 0 ] ) ;
if ( V_7 == NULL ) {
F_3 ( L_1 ) ;
return NULL ;
}
return V_7 -> V_10 ;
}
static int F_4 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_6 * V_7 ;
int V_15 ;
V_7 = F_2 ( & V_5 -> V_8 . V_9 [ 0 ] ) ;
if ( V_7 == NULL ) {
F_3 ( L_1 ) ;
return - V_16 ;
}
V_14 = F_5 ( V_7 -> V_10 ) ;
V_12 = V_5 -> V_17 -> V_18 ;
for ( V_15 = 0 ; V_15 < V_12 -> V_19 ; V_15 ++ ) {
if ( ! strcmp ( V_12 -> V_20 [ V_15 ] . V_21 , V_14 -> V_22 ) ) {
V_3 -> V_23 = & V_12 -> V_20 [ V_15 ] ;
break;
}
}
if ( V_15 == V_12 -> V_19 ) {
F_3 ( L_2 ) ;
return - V_16 ;
}
for ( V_15 = 0 ; V_15 < V_5 -> V_24 ; V_15 ++ ) {
if ( ! strcmp ( V_3 -> V_23 -> V_21 ,
V_5 -> V_25 [ V_15 ] -> V_22 ) )
V_3 -> V_23 -> V_14 = V_5 -> V_25 [ V_15 ] ;
}
return 0 ;
}
static struct V_13 *
F_6 ( struct V_2 * V_3 , T_1 * V_26 )
{
struct V_6 * V_7 = F_2 ( & V_3 -> V_26 ) ;
if ( ! V_7 || ! F_7 ( V_7 -> V_10 ) )
return NULL ;
if ( V_26 )
* V_26 = V_7 -> V_27 ;
return F_5 ( V_7 -> V_10 ) ;
}
static int
F_8 ( struct V_2 * V_3 ,
struct V_28 * V_29 )
{
struct V_30 V_31 ;
struct V_13 * V_14 ;
struct V_6 * V_7 ;
T_1 V_26 ;
int V_32 ;
V_14 = F_6 ( V_3 , & V_26 ) ;
if ( V_14 == NULL )
return - V_16 ;
V_31 . V_33 = V_34 ;
V_7 = F_2 ( & V_3 -> V_26 ) ;
V_31 . V_26 = V_7 -> V_27 ;
V_32 = F_9 ( V_14 , V_26 , V_35 , NULL , & V_31 ) ;
if ( V_32 == - V_36 )
return - V_16 ;
V_29 -> type = V_3 -> type ;
F_10 ( & V_29 -> V_31 . V_37 , & V_31 . V_29 ) ;
F_11 ( & V_31 . V_29 , & V_29 -> V_31 . V_37 ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_38 V_39 ;
struct V_1 * V_10 = & V_3 -> V_40 . V_10 ;
struct V_41 * V_42 = V_10 -> V_43 . V_42 ;
struct V_44 * V_45 = & V_3 -> V_45 ;
struct V_2 * V_46 = NULL ;
int V_32 ;
V_45 -> V_47 = 0 ;
V_45 -> V_48 = 0 ;
if ( V_3 -> type == V_49 )
V_45 -> V_50 [ V_45 -> V_47 ++ ] = V_3 ;
else
V_45 -> V_51 [ V_45 -> V_48 ++ ] = V_3 ;
F_13 ( & V_42 -> V_52 ) ;
V_32 = F_14 ( & V_39 , V_10 -> V_43 . V_42 ) ;
if ( V_32 ) {
F_15 ( & V_42 -> V_52 ) ;
return - V_53 ;
}
F_16 ( & V_39 , V_10 ) ;
while ( ( V_10 = F_17 ( & V_39 ) ) ) {
if ( V_10 == & V_3 -> V_40 . V_10 )
continue;
if ( ! F_18 ( V_10 ) )
continue;
V_46 = F_19 ( F_20 ( V_10 ) ) ;
if ( V_46 -> type == V_49 )
V_45 -> V_50 [ V_45 -> V_47 ++ ] = V_46 ;
else
V_45 -> V_51 [ V_45 -> V_48 ++ ] = V_46 ;
}
F_21 ( & V_39 ) ;
F_15 ( & V_42 -> V_52 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_44 * V_45 = & V_3 -> V_45 ;
int V_32 ;
V_32 = F_12 ( V_3 ) ;
if ( V_32 )
return V_32 ;
if ( V_45 -> V_47 == 0 ) {
V_45 -> V_54 = V_55 ;
V_32 = F_4 ( V_3 ) ;
if ( V_32 ) {
F_3 ( L_3 ) ;
return V_32 ;
}
} else {
V_45 -> V_54 = V_56 ;
}
V_3 -> V_57 = 1 ;
V_3 -> V_58 = 1 ;
V_3 -> V_59 = 1 ;
return 0 ;
}
int F_23 ( struct V_44 * V_45 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_45 -> V_47 ; V_15 ++ )
if ( ! V_45 -> V_50 [ V_15 ] -> V_60 ||
V_45 -> V_50 [ V_15 ] -> V_54 != V_61 )
return 0 ;
for ( V_15 = 0 ; V_15 < V_45 -> V_48 ; V_15 ++ )
if ( ! V_45 -> V_51 [ V_15 ] -> V_60 ||
V_45 -> V_51 [ V_15 ] -> V_54 != V_61 )
return 0 ;
return 1 ;
}
static int F_24 ( struct V_44 * V_45 )
{
struct V_30 V_62 ;
struct V_30 V_63 ;
struct V_13 * V_14 ;
struct V_6 * V_26 ;
int V_32 ;
V_14 = F_6 ( V_45 -> V_51 [ 0 ] , NULL ) ;
if ( V_14 == NULL )
return - V_64 ;
while ( 1 ) {
V_26 = & V_14 -> V_10 . V_9 [ 0 ] ;
if ( ! ( V_26 -> V_65 & V_66 ) )
break;
V_63 . V_33 = V_34 ;
V_63 . V_26 = V_26 -> V_27 ;
V_32 = F_9 ( V_14 , V_26 , V_35 , NULL ,
& V_63 ) ;
if ( V_32 < 0 && V_32 != - V_36 )
return - V_64 ;
V_26 = F_2 ( V_26 ) ;
if ( ! V_26 || ! F_7 ( V_26 -> V_10 ) )
break;
V_14 = F_5 ( V_26 -> V_10 ) ;
V_62 . V_33 = V_34 ;
V_62 . V_26 = V_26 -> V_27 ;
V_32 = F_9 ( V_14 , V_26 , V_35 , NULL , & V_62 ) ;
if ( V_32 < 0 && V_32 != - V_36 )
return - V_64 ;
if ( V_62 . V_29 . V_67 != V_63 . V_29 . V_67 ||
V_62 . V_29 . V_68 != V_63 . V_29 . V_68 ||
V_62 . V_29 . V_69 != V_63 . V_29 . V_69 )
return - V_64 ;
}
return 0 ;
}
static int F_25 ( struct V_44 * V_45 )
{
struct V_1 * V_10 ;
struct V_13 * V_14 ;
struct V_41 * V_42 ;
int V_32 ;
if ( V_45 -> V_54 == V_55 )
V_10 = F_1 ( V_45 -> V_51 [ 0 ] ) ;
else
V_10 = & V_45 -> V_50 [ 0 ] -> V_40 . V_10 ;
V_42 = V_10 -> V_43 . V_42 ;
F_13 ( & V_42 -> V_52 ) ;
V_32 = F_14 ( & V_45 -> V_39 ,
V_10 -> V_43 . V_42 ) ;
if ( V_32 )
goto V_70;
F_16 ( & V_45 -> V_39 , V_10 ) ;
while ( ( V_10 = F_17 ( & V_45 -> V_39 ) ) ) {
if ( ! F_7 ( V_10 ) )
continue;
V_14 = F_5 ( V_10 ) ;
V_32 = F_9 ( V_14 , V_3 , V_71 , 1 ) ;
if ( V_32 < 0 && V_32 != - V_36 )
break;
}
V_70:
if ( V_32 )
F_21 ( & V_45 -> V_39 ) ;
F_15 ( & V_42 -> V_52 ) ;
return V_32 ;
}
static int F_26 ( struct V_44 * V_45 )
{
struct V_1 * V_10 ;
struct V_13 * V_14 ;
struct V_41 * V_42 ;
int V_32 = 0 ;
if ( V_45 -> V_54 == V_55 )
V_10 = F_1 ( V_45 -> V_51 [ 0 ] ) ;
else
V_10 = & V_45 -> V_50 [ 0 ] -> V_40 . V_10 ;
V_42 = V_10 -> V_43 . V_42 ;
F_13 ( & V_42 -> V_52 ) ;
F_16 ( & V_45 -> V_39 , V_10 ) ;
while ( ( V_10 = F_17 ( & V_45 -> V_39 ) ) ) {
if ( ! F_7 ( V_10 ) )
continue;
V_14 = F_5 ( V_10 ) ;
V_32 = F_9 ( V_14 , V_3 , V_71 , 0 ) ;
if ( V_32 < 0 && V_32 != - V_36 )
break;
}
F_15 ( & V_42 -> V_52 ) ;
F_21 ( & V_45 -> V_39 ) ;
return V_32 ? - V_72 : 0 ;
}
static int F_27 ( struct V_44 * V_45 ,
enum V_73 V_54 )
{
if ( V_54 == V_74 )
return F_26 ( V_45 ) ;
return F_25 ( V_45 ) ;
}
static int F_28 ( struct V_2 * V_3 )
{
struct V_44 * V_45 = & V_3 -> V_45 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_45 -> V_47 ; V_15 ++ )
if ( V_45 -> V_50 [ V_15 ] -> V_60 )
return 0 ;
for ( V_15 = 0 ; V_15 < V_45 -> V_48 ; V_15 ++ )
if ( V_45 -> V_51 [ V_15 ] -> V_60 )
return 0 ;
return 1 ;
}
static int F_29 ( struct V_75 * V_75 )
{
struct V_2 * V_3 = F_30 ( V_75 ) ;
struct V_76 * V_77 ;
V_77 = F_31 ( sizeof( struct V_76 ) , V_78 ) ;
if ( V_77 == NULL )
return - V_53 ;
F_32 ( & V_77 -> V_79 , & V_3 -> V_40 ) ;
F_33 ( & V_77 -> V_79 ) ;
F_13 ( & V_3 -> V_80 ) ;
if ( ! V_3 -> V_57 && F_22 ( V_3 ) ) {
F_15 ( & V_3 -> V_80 ) ;
return - V_81 ;
}
V_3 -> V_82 ++ ;
V_77 -> V_83 = 0 ;
V_77 -> V_3 = V_3 ;
V_75 -> V_84 = & V_77 -> V_79 ;
F_15 ( & V_3 -> V_80 ) ;
return 0 ;
}
static unsigned long
F_34 ( struct V_2 * V_3 )
{
V_3 -> V_85 = V_3 -> V_86 =
F_35 ( V_3 -> V_87 . V_88 ,
struct V_89 , V_90 ) ;
F_36 ( & V_3 -> V_86 -> V_90 ) ;
V_3 -> V_86 -> V_91 . V_92 . V_54 = V_93 ;
return F_37 ( & V_3 -> V_86 -> V_91 . V_92 , 0 ) ;
}
void F_38 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_94 ;
if ( F_39 ( & V_3 -> V_87 ) )
return;
V_3 -> V_86 = F_35 ( V_3 -> V_87 . V_88 ,
struct V_89 , V_90 ) ;
if ( V_3 -> V_45 . V_54 == V_56 )
V_3 -> V_85 = V_3 -> V_86 ;
F_36 ( & V_3 -> V_86 -> V_90 ) ;
V_3 -> V_86 -> V_91 . V_92 . V_54 = V_93 ;
V_94 = F_37 ( & V_3 -> V_86 -> V_91 . V_92 , 0 ) ;
V_3 -> V_95 -> V_96 ( V_5 , V_94 ) ;
V_3 -> V_54 = V_61 ;
}
void F_40 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_94 ;
V_94 = F_37 ( & V_3 -> V_85 -> V_91 . V_92 , 0 ) ;
V_94 += V_3 -> V_97 ;
V_3 -> V_95 -> V_96 ( V_5 , V_94 ) ;
}
void F_41 ( struct V_2 * V_3 )
{
struct V_44 * V_45 = & V_3 -> V_45 ;
V_3 -> V_85 -> V_91 . V_92 . V_98 = F_42 () ;
F_43 ( & V_3 -> V_85 -> V_91 . V_92 , V_99 ) ;
if ( V_45 -> V_54 == V_55 )
V_3 -> V_85 = V_3 -> V_86 ;
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_44 * V_45 = & V_3 -> V_45 ;
V_3 -> V_60 = 0 ;
if ( V_3 -> type == V_49 )
return;
if ( F_28 ( V_3 ) )
F_27 ( V_45 ,
V_74 ) ;
}
static int F_45 ( struct V_75 * V_75 )
{
struct V_2 * V_3 = F_30 ( V_75 ) ;
struct V_100 * V_79 = V_75 -> V_84 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_76 * V_101 = F_46 ( V_79 , struct V_76 , V_79 ) ;
F_47 ( 1 , V_102 , & V_5 -> V_103 , L_4 ) ;
F_13 ( & V_3 -> V_80 ) ;
if ( V_101 -> V_83 ) {
if ( V_3 -> V_60 ) {
F_44 ( V_3 ) ;
V_3 -> V_45 . V_54 = V_74 ;
F_48 ( & V_3 -> V_104 ,
V_3 -> V_104 . type ) ;
}
V_3 -> V_105 = 0 ;
F_49 ( & V_3 -> V_104 ) ;
F_50 ( V_3 -> V_106 ) ;
}
V_3 -> V_82 -- ;
F_51 ( & V_101 -> V_79 ) ;
F_52 ( & V_101 -> V_79 ) ;
if ( ! V_3 -> V_82 )
V_3 -> V_57 = 0 ;
F_15 ( & V_3 -> V_80 ) ;
V_75 -> V_84 = NULL ;
F_51 ( V_79 ) ;
F_53 ( V_101 ) ;
return 0 ;
}
static int F_54 ( struct V_75 * V_75 , struct V_107 * V_108 )
{
struct V_2 * V_3 = F_30 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_47 ( 1 , V_102 , & V_5 -> V_103 , L_5 ) ;
return F_55 ( & V_3 -> V_104 , V_108 ) ;
}
static unsigned int F_56 ( struct V_75 * V_75 , T_2 * V_109 )
{
struct V_2 * V_3 = F_30 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_47 ( 1 , V_102 , & V_5 -> V_103 , L_6 ) ;
if ( V_3 -> V_60 )
return F_57 ( & V_3 -> V_104 , V_75 , V_109 ) ;
return 0 ;
}
static int F_58 ( struct V_75 * V_75 , void * V_110 ,
struct V_111 * V_112 )
{
struct V_2 * V_3 = F_30 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_47 ( 1 , V_102 , & V_5 -> V_103 , L_7 ) ;
if ( V_3 -> type == V_113 )
V_112 -> V_114 = V_115 | V_116 ;
else
V_112 -> V_114 = V_117 | V_116 ;
V_112 -> V_118 = V_115 | V_117 |
V_116 | V_119 ;
F_59 ( V_112 -> V_120 , V_121 , sizeof( V_112 -> V_120 ) ) ;
F_59 ( V_112 -> V_122 , L_8 , sizeof( V_112 -> V_122 ) ) ;
F_59 ( V_112 -> V_123 , V_5 -> V_124 -> V_125 , sizeof( V_112 -> V_123 ) ) ;
return 0 ;
}
static int F_60 ( struct V_75 * V_75 , void * V_110 ,
struct V_28 * V_31 )
{
struct V_2 * V_3 = F_30 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_47 ( 1 , V_102 , & V_5 -> V_103 , L_9 ) ;
* V_31 = V_3 -> V_31 ;
return 0 ;
}
static int F_61 ( struct V_75 * V_75 , void * V_110 ,
struct V_126 * V_31 )
{
struct V_2 * V_3 = F_30 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_30 V_127 ;
struct V_128 V_129 ;
struct V_13 * V_14 ;
struct V_28 V_29 ;
struct V_6 * V_7 ;
int V_32 ;
F_47 ( 1 , V_102 , & V_5 -> V_103 , L_10 ) ;
if ( V_31 -> V_27 > 0 ) {
F_62 ( & V_5 -> V_103 , L_11 ) ;
return - V_16 ;
}
V_7 = F_2 ( & V_3 -> V_26 ) ;
if ( V_7 == NULL ) {
F_62 ( & V_5 -> V_103 ,
L_12 ) ;
return - V_16 ;
}
V_14 = F_6 ( V_3 , NULL ) ;
if ( V_14 == NULL ) {
F_62 ( & V_5 -> V_103 ,
L_13 ) ;
return - V_16 ;
}
V_127 . V_26 = V_7 -> V_27 ;
V_127 . V_33 = V_34 ;
V_32 = F_9 ( V_14 , V_26 , V_35 , NULL , & V_127 ) ;
if ( V_32 ) {
F_62 ( & V_5 -> V_103 ,
L_13 ) ;
return V_32 ;
}
V_129 . V_67 = V_127 . V_29 . V_67 ;
F_11 ( & V_129 , & V_29 . V_31 . V_37 ) ;
V_31 -> V_130 = V_29 . V_31 . V_37 . V_130 ;
return 0 ;
}
static int F_63 ( struct V_75 * V_75 , void * V_110 ,
struct V_28 * V_31 )
{
struct V_2 * V_3 = F_30 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_28 V_29 ;
int V_32 ;
F_47 ( 1 , V_102 , & V_5 -> V_103 , L_14 ) ;
if ( V_3 -> V_60 ) {
F_62 ( & V_5 -> V_103 , L_15 ) ;
return - V_131 ;
}
V_32 = F_8 ( V_3 , & V_29 ) ;
if ( V_32 )
return V_32 ;
* V_31 = V_29 ;
V_3 -> V_31 = * V_31 ;
return 0 ;
}
static int F_64 ( struct V_75 * V_75 , void * V_110 ,
struct V_28 * V_31 )
{
struct V_2 * V_3 = F_30 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_28 V_29 ;
int V_32 ;
F_47 ( 1 , V_102 , & V_5 -> V_103 , L_16 ) ;
V_32 = F_8 ( V_3 , & V_29 ) ;
if ( V_32 )
return V_32 ;
* V_31 = V_29 ;
return 0 ;
}
static int F_65 ( struct V_75 * V_75 , void * V_110 ,
struct V_132 * V_133 )
{
struct V_2 * V_3 = F_30 ( V_75 ) ;
struct V_134 * V_135 = V_3 -> V_23 ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_47 ( 1 , V_102 , & V_5 -> V_103 , L_17 ) ;
if ( V_133 -> V_27 < V_135 -> V_136 ) {
memcpy ( V_133 , & V_135 -> V_50 [ V_133 -> V_27 ] ,
sizeof( struct V_132 ) ) ;
return 0 ;
}
return - V_16 ;
}
static int F_66 ( struct V_75 * V_75 , void * V_110 , unsigned int * V_27 )
{
struct V_2 * V_3 = F_30 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_47 ( 1 , V_102 , & V_5 -> V_103 , L_18 ) ;
* V_27 = V_3 -> V_137 ;
return 0 ;
}
static int F_67 ( struct V_75 * V_75 , void * V_110 , unsigned int V_27 )
{
struct V_2 * V_3 = F_30 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_134 * V_135 ;
struct V_138 * V_139 ;
struct V_132 * V_140 ;
T_1 V_141 ;
T_1 V_142 ;
int V_32 ;
int V_15 ;
F_47 ( 1 , V_102 , & V_5 -> V_103 , L_19 ) ;
V_32 = F_68 ( & V_3 -> V_80 ) ;
if ( V_32 )
return V_32 ;
if ( V_3 -> V_60 ) {
F_62 ( & V_5 -> V_103 , L_20 ) ;
V_32 = - V_131 ;
goto V_143;
}
V_135 = V_3 -> V_23 ;
if ( ! V_135 -> V_144 ) {
V_32 = - V_16 ;
goto V_143;
}
if ( V_5 -> V_124 -> V_145 &&
V_5 -> V_124 -> V_145 ( V_135 -> V_146 ) < 0 ) {
V_32 = - V_147 ;
F_47 ( 1 , V_102 , & V_5 -> V_103 ,
L_21 ,
V_135 -> V_21 ) ;
goto V_143;
}
V_139 = & V_135 -> V_148 [ V_27 ] ;
if ( V_139 && V_135 -> V_149 ) {
V_142 = V_139 -> V_142 ;
V_141 = V_139 -> V_141 ;
V_32 = F_69 ( & V_5 -> V_103 ,
V_135 -> V_146 , V_3 ,
V_150 , V_142 , V_141 , 0 ) ;
if ( V_32 ) {
F_47 ( 1 , V_102 , & V_5 -> V_103 ,
L_22 ) ;
V_32 = - V_16 ;
goto V_143;
}
}
for ( V_15 = 0 ; V_15 < V_135 -> V_136 ; V_15 ++ ) {
V_140 = & V_135 -> V_50 [ V_15 ] ;
V_3 -> V_40 . V_151 |= V_140 -> V_152 ;
}
V_3 -> V_137 = V_27 ;
V_143:
F_15 ( & V_3 -> V_80 ) ;
return V_32 ;
}
static int F_70 ( struct V_75 * V_75 , void * V_110 , T_3 * V_153 )
{
struct V_2 * V_3 = F_30 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_134 * V_135 ;
int V_32 ;
F_47 ( 1 , V_102 , & V_5 -> V_103 , L_23 ) ;
V_32 = F_68 ( & V_3 -> V_80 ) ;
V_135 = V_3 -> V_23 ;
if ( V_32 )
return V_32 ;
V_32 = F_69 ( & V_5 -> V_103 , V_135 -> V_146 ,
V_3 , V_154 , V_153 ) ;
F_15 ( & V_3 -> V_80 ) ;
return V_32 ;
}
static int F_71 ( struct V_75 * V_75 , void * V_110 , T_3 V_153 )
{
struct V_2 * V_3 = F_30 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_134 * V_135 ;
int V_32 ;
F_47 ( 1 , V_102 , & V_5 -> V_103 , L_24 ) ;
V_32 = F_68 ( & V_3 -> V_80 ) ;
if ( V_32 )
return V_32 ;
V_135 = V_3 -> V_23 ;
if ( V_3 -> V_60 ) {
F_62 ( & V_5 -> V_103 , L_25 ) ;
V_32 = - V_131 ;
goto V_143;
}
V_32 = F_69 ( & V_5 -> V_103 , V_135 -> V_146 ,
V_3 , V_155 , V_153 ) ;
if ( V_32 < 0 ) {
F_62 ( & V_5 -> V_103 , L_26 ) ;
V_3 -> V_156 = V_157 ;
goto V_143;
}
V_3 -> V_156 = V_153 ;
V_143:
F_15 ( & V_3 -> V_80 ) ;
return V_32 ;
}
static int F_72 ( struct V_75 * V_75 , void * V_110 , T_3 * V_158 )
{
struct V_2 * V_3 = F_30 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_47 ( 1 , V_102 , & V_5 -> V_103 , L_27 ) ;
* V_158 = V_3 -> V_156 ;
return 0 ;
}
static int
F_73 ( struct V_75 * V_75 , void * V_101 ,
struct V_159 * V_160 )
{
struct V_2 * V_3 = F_30 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_13 * V_14 = V_3 -> V_23 -> V_14 ;
V_160 -> V_26 = 0 ;
F_47 ( 1 , V_102 , & V_5 -> V_103 , L_28 ) ;
return F_9 ( V_14 , V_26 , V_161 , V_160 ) ;
}
static int
F_74 ( struct V_75 * V_75 , void * V_101 ,
struct V_162 * V_160 )
{
struct V_2 * V_3 = F_30 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_13 * V_14 = V_3 -> V_23 -> V_14 ;
F_47 ( 1 , V_102 , & V_5 -> V_103 , L_29 ) ;
return F_9 ( V_14 , V_3 , V_163 , V_160 ) ;
}
static int
F_75 ( struct V_75 * V_75 , void * V_101 ,
struct V_162 * V_160 )
{
struct V_2 * V_3 = F_30 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_47 ( 1 , V_102 , & V_5 -> V_103 , L_30 ) ;
V_3 -> V_156 = V_157 ;
return F_69 ( & V_5 -> V_103 ,
V_3 -> V_23 -> V_146 ,
V_3 , V_164 , V_160 ) ;
}
static int
F_76 ( struct V_75 * V_75 , void * V_101 ,
struct V_162 * V_160 )
{
struct V_2 * V_3 = F_30 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_13 * V_14 = V_3 -> V_23 -> V_14 ;
F_47 ( 1 , V_102 , & V_5 -> V_103 , L_31 ) ;
return F_9 ( V_14 , V_3 , V_165 , V_160 ) ;
}
static int
F_77 ( struct V_166 * V_167 ,
unsigned int * V_168 , unsigned int * V_169 ,
unsigned int V_170 [] , void * V_171 [] )
{
struct V_76 * V_101 = F_78 ( V_167 ) ;
struct V_2 * V_3 = V_101 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_172 ;
F_47 ( 1 , V_102 , & V_5 -> V_103 , L_32 ) ;
V_172 = V_3 -> V_31 . V_31 . V_37 . V_173 ;
if ( V_167 -> V_174 + * V_168 < 3 )
* V_168 = 3 - V_167 -> V_174 ;
* V_169 = 1 ;
V_170 [ 0 ] = V_172 ;
V_171 [ 0 ] = V_3 -> V_106 ;
F_47 ( 1 , V_102 , & V_5 -> V_103 ,
L_33 , * V_168 , V_172 ) ;
return 0 ;
}
static int F_79 ( struct V_175 * V_91 )
{
struct V_76 * V_101 = F_78 ( V_91 -> V_166 ) ;
struct V_2 * V_3 = V_101 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_94 ;
F_47 ( 1 , V_102 , & V_5 -> V_103 , L_34 ) ;
if ( V_91 -> V_54 != V_93 &&
V_91 -> V_54 != V_176 )
return 0 ;
F_80 ( V_91 , 0 , V_3 -> V_31 . V_31 . V_37 . V_173 ) ;
if ( F_81 ( V_91 , 0 ) &&
F_82 ( V_91 , 0 ) > F_83 ( V_91 , 0 ) )
return - V_16 ;
V_94 = F_37 ( V_91 , 0 ) ;
if ( ! F_84 ( V_94 , 32 ) )
return - V_16 ;
return 0 ;
}
static void F_85 ( struct V_175 * V_91 )
{
struct V_177 * V_178 = F_86 ( V_91 ) ;
struct V_76 * V_101 = F_78 ( V_91 -> V_166 ) ;
struct V_2 * V_3 = V_101 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_44 * V_45 = & V_3 -> V_45 ;
struct V_89 * V_179 = F_46 ( V_178 ,
struct V_89 , V_91 ) ;
unsigned long V_65 ;
unsigned long V_180 ;
unsigned long V_94 ;
F_87 ( & V_3 -> V_181 , V_65 ) ;
V_180 = F_39 ( & V_3 -> V_87 ) ;
F_88 ( & V_179 -> V_90 , & V_3 -> V_87 ) ;
F_89 ( & V_3 -> V_181 , V_65 ) ;
if ( V_180 && V_3 -> V_60 && V_45 -> V_54 ==
V_56 &&
V_3 -> V_54 == V_182 ) {
F_90 ( & V_3 -> V_181 ) ;
V_94 = F_34 ( V_3 ) ;
V_3 -> V_95 -> V_96 ( V_5 , V_94 ) ;
V_3 -> V_54 = V_61 ;
F_91 ( & V_3 -> V_181 ) ;
if ( F_23 ( V_45 ) )
F_27 ( V_45 ,
V_56 ) ;
}
}
static int F_92 ( struct V_2 * V_3 )
{
struct V_44 * V_45 = & V_3 -> V_45 ;
int V_32 = 0 ;
V_3 -> V_60 = 1 ;
if ( F_23 ( V_45 ) )
V_32 = F_27 ( V_45 , V_45 -> V_54 ) ;
return V_32 ;
}
static int F_93 ( struct V_166 * V_167 , unsigned int V_183 )
{
struct V_76 * V_101 = F_78 ( V_167 ) ;
struct V_2 * V_3 = V_101 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_94 ;
int V_32 ;
V_32 = F_68 ( & V_3 -> V_80 ) ;
if ( V_32 )
goto V_184;
V_3 -> V_85 = V_3 -> V_86 =
F_35 ( V_3 -> V_87 . V_88 , struct V_89 , V_90 ) ;
F_36 ( & V_3 -> V_85 -> V_90 ) ;
V_3 -> V_85 -> V_91 . V_92 . V_54 = V_93 ;
V_3 -> V_185 = 0 ;
V_94 = F_37 ( & V_3 -> V_85 -> V_91 . V_92 , 0 ) ;
V_3 -> V_95 -> V_96 ( V_5 , V_94 ) ;
V_3 -> V_54 = V_61 ;
V_32 = F_92 ( V_3 ) ;
if ( V_32 ) {
struct V_89 * V_179 , * V_186 ;
F_43 ( & V_3 -> V_85 -> V_91 . V_92 ,
V_187 ) ;
F_94 (buf, tmp, &video->dma_queue, list) {
F_36 ( & V_179 -> V_90 ) ;
F_43 ( & V_179 -> V_91 . V_92 ,
V_187 ) ;
}
goto V_143;
}
F_15 ( & V_3 -> V_80 ) ;
return V_32 ;
V_143:
F_15 ( & V_3 -> V_80 ) ;
V_184:
V_32 = F_48 ( & V_3 -> V_104 , V_3 -> V_104 . type ) ;
return 0 ;
}
static int F_95 ( struct V_175 * V_91 )
{
struct V_177 * V_178 = F_86 ( V_91 ) ;
struct V_89 * V_179 = F_46 ( V_178 ,
struct V_89 , V_91 ) ;
F_96 ( & V_179 -> V_90 ) ;
return 0 ;
}
static void F_97 ( struct V_166 * V_167 )
{
struct V_76 * V_101 = F_78 ( V_167 ) ;
struct V_2 * V_3 = V_101 -> V_3 ;
if ( V_3 -> V_85 == V_3 -> V_86 ) {
F_43 ( & V_3 -> V_85 -> V_91 . V_92 ,
V_188 ) ;
} else {
if ( V_3 -> V_85 != NULL )
F_43 ( & V_3 -> V_85 -> V_91 . V_92 ,
V_188 ) ;
if ( V_3 -> V_86 != NULL )
F_43 ( & V_3 -> V_86 -> V_91 . V_92 ,
V_188 ) ;
}
while ( ! F_39 ( & V_3 -> V_87 ) ) {
V_3 -> V_86 = F_35 ( V_3 -> V_87 . V_88 ,
struct V_89 , V_90 ) ;
F_36 ( & V_3 -> V_86 -> V_90 ) ;
F_43 ( & V_3 -> V_86 -> V_91 . V_92 ,
V_188 ) ;
}
}
static void F_98 ( struct V_175 * V_91 )
{
struct V_177 * V_178 = F_86 ( V_91 ) ;
struct V_76 * V_101 = F_78 ( V_91 -> V_166 ) ;
struct V_2 * V_3 = V_101 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_89 * V_179 = F_46 ( V_178 ,
struct V_89 , V_91 ) ;
F_47 ( 1 , V_102 , & V_5 -> V_103 , L_35 ) ;
if ( V_91 -> V_54 == V_93 )
F_99 ( & V_179 -> V_90 ) ;
}
static int F_100 ( struct V_75 * V_75 , void * V_110 ,
struct V_189 * V_190 )
{
struct V_2 * V_3 = F_30 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_76 * V_101 = V_75 -> V_84 ;
struct V_166 * V_191 ;
int V_32 ;
F_47 ( 1 , V_102 , & V_5 -> V_103 , L_36 ) ;
if ( V_190 -> type != V_113 &&
V_190 -> type != V_49 ) {
F_62 ( & V_5 -> V_103 , L_37 ) ;
return - V_16 ;
}
V_32 = F_68 ( & V_3 -> V_80 ) ;
if ( V_32 )
return V_32 ;
if ( V_3 -> V_105 != 0 ) {
F_62 ( & V_5 -> V_103 , L_38 ) ;
V_32 = - V_131 ;
goto V_143;
}
V_3 -> V_192 = V_190 -> V_192 ;
V_3 -> V_106 = F_101 ( V_5 -> V_17 ) ;
if ( F_102 ( V_3 -> V_106 ) ) {
F_62 ( & V_5 -> V_103 , L_39 ) ;
return F_103 ( V_3 -> V_106 ) ;
}
V_191 = & V_3 -> V_104 ;
V_191 -> type = V_190 -> type ;
V_191 -> V_193 = V_194 | V_195 ;
V_191 -> V_196 = V_101 ;
V_191 -> V_197 = 1 ;
V_191 -> V_95 = & V_198 ;
V_191 -> V_199 = & V_200 ;
V_191 -> V_201 = sizeof( struct V_89 ) ;
V_191 -> V_202 = V_203 ;
V_32 = F_104 ( V_191 ) ;
if ( V_32 ) {
F_62 ( & V_5 -> V_103 , L_40 ) ;
F_50 ( V_5 -> V_17 ) ;
return V_32 ;
}
V_101 -> V_83 = 1 ;
V_3 -> V_105 = 1 ;
F_96 ( & V_3 -> V_87 ) ;
V_32 = F_105 ( & V_3 -> V_104 , V_190 ) ;
V_143:
F_15 ( & V_3 -> V_80 ) ;
return V_32 ;
}
static int F_106 ( struct V_75 * V_75 , void * V_110 ,
struct V_204 * V_179 )
{
struct V_2 * V_3 = F_30 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_47 ( 1 , V_102 , & V_5 -> V_103 , L_41 ) ;
if ( V_179 -> type != V_113 &&
V_179 -> type != V_49 ) {
F_62 ( & V_5 -> V_103 , L_42 ) ;
return - V_16 ;
}
if ( V_3 -> V_192 != V_205 ) {
F_62 ( & V_5 -> V_103 , L_43 ) ;
return - V_16 ;
}
return F_107 ( & V_3 -> V_104 , V_179 ) ;
}
static int F_108 ( struct V_75 * V_75 , void * V_110 ,
struct V_204 * V_206 )
{
struct V_2 * V_3 = F_30 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_76 * V_101 = V_75 -> V_84 ;
F_47 ( 1 , V_102 , & V_5 -> V_103 , L_44 ) ;
if ( V_206 -> type != V_113 &&
V_206 -> type != V_49 ) {
F_62 ( & V_5 -> V_103 , L_42 ) ;
return - V_16 ;
}
if ( ! V_101 -> V_83 ) {
F_62 ( & V_5 -> V_103 , L_45 ) ;
return - V_207 ;
}
return F_109 ( & V_3 -> V_104 , V_206 ) ;
}
static int F_110 ( struct V_75 * V_75 , void * V_110 ,
struct V_204 * V_179 )
{
struct V_2 * V_3 = F_30 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_47 ( 1 , V_102 , & V_5 -> V_103 , L_46 ) ;
if ( V_179 -> type != V_113 &&
V_179 -> type != V_49 ) {
F_62 ( & V_5 -> V_103 , L_42 ) ;
return - V_16 ;
}
return F_111 ( & V_3 -> V_104 ,
V_179 , ( V_75 -> V_208 & V_209 ) ) ;
}
static int F_112 ( struct V_75 * V_75 , void * V_110 ,
enum V_210 V_211 )
{
struct V_2 * V_3 = F_30 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_44 * V_45 = & V_3 -> V_45 ;
struct V_76 * V_101 = V_75 -> V_84 ;
struct V_134 * V_135 ;
int V_32 = - V_16 ;
F_47 ( 1 , V_102 , & V_5 -> V_103 , L_47 ) ;
if ( V_211 != V_113 &&
V_211 != V_49 ) {
F_62 ( & V_5 -> V_103 , L_42 ) ;
return V_32 ;
}
if ( ! V_101 -> V_83 ) {
F_62 ( & V_5 -> V_103 , L_45 ) ;
return - V_207 ;
}
V_135 = V_3 -> V_23 ;
if ( F_39 ( & V_3 -> V_104 . V_212 ) ) {
F_62 ( & V_5 -> V_103 , L_48 ) ;
return - V_213 ;
}
if ( V_211 == V_113 ) {
V_32 = F_24 ( V_45 ) ;
if ( V_32 < 0 )
return V_32 ;
}
return F_113 ( & V_3 -> V_104 , V_211 ) ;
}
static int F_114 ( struct V_75 * V_75 , void * V_110 ,
enum V_210 V_211 )
{
struct V_2 * V_3 = F_30 ( V_75 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_76 * V_101 = V_75 -> V_84 ;
int V_32 = 0 ;
F_47 ( 1 , V_102 , & V_5 -> V_103 , L_49 ) ;
if ( V_211 != V_113 &&
V_211 != V_49 ) {
F_47 ( 1 , V_102 , & V_5 -> V_103 , L_42 ) ;
return - V_16 ;
}
if ( ! V_101 -> V_83 ) {
F_47 ( 1 , V_102 , & V_5 -> V_103 , L_45 ) ;
return - V_207 ;
}
if ( ! V_3 -> V_60 ) {
F_62 ( & V_5 -> V_103 , L_50 ) ;
return - V_16 ;
}
V_32 = F_68 ( & V_3 -> V_80 ) ;
if ( V_32 )
return V_32 ;
F_44 ( V_3 ) ;
V_32 = F_48 ( & V_3 -> V_104 , V_211 ) ;
F_15 ( & V_3 -> V_80 ) ;
return V_32 ;
}
int F_115 ( struct V_2 * V_3 , const char * V_22 )
{
const char * V_214 ;
int V_32 ;
switch ( V_3 -> type ) {
case V_113 :
V_214 = L_51 ;
V_3 -> V_26 . V_65 = V_66 ;
V_3 -> type = V_113 ;
break;
case V_49 :
V_214 = L_52 ;
V_3 -> V_26 . V_65 = V_215 ;
V_3 -> type = V_49 ;
break;
default:
return - V_16 ;
}
V_3 -> V_40 . V_216 = V_217 ;
V_3 -> V_40 . V_218 = & V_219 ;
V_3 -> V_40 . V_220 = & V_221 ;
V_3 -> V_40 . V_222 = - 1 ;
V_3 -> V_40 . V_151 = 0 ;
snprintf ( V_3 -> V_40 . V_22 , sizeof( V_3 -> V_40 . V_22 ) ,
L_53 , V_22 , V_214 ) ;
F_116 ( & V_3 -> V_223 ) ;
F_116 ( & V_3 -> V_181 ) ;
F_117 ( & V_3 -> V_80 ) ;
V_32 = F_118 ( & V_3 -> V_40 . V_10 ,
1 , & V_3 -> V_26 ) ;
if ( V_32 < 0 )
return V_32 ;
F_119 ( & V_3 -> V_40 , V_3 ) ;
return 0 ;
}
int F_120 ( struct V_2 * V_3 ,
struct V_224 * V_225 )
{
int V_32 ;
V_3 -> V_40 . V_103 = V_225 ;
V_32 = F_121 ( & V_3 -> V_40 , V_226 , - 1 ) ;
if ( V_32 < 0 )
F_3 ( L_54 ,
V_227 , V_32 ) ;
return V_32 ;
}
void F_122 ( struct V_2 * V_3 )
{
if ( F_123 ( & V_3 -> V_40 ) ) {
F_124 ( & V_3 -> V_40 ) ;
F_125 ( & V_3 -> V_40 . V_10 ) ;
}
}
