const struct V_1 * F_1 ( struct V_2 * V_3 ,
const T_1 * V_4 ,
int V_5 )
{
const struct V_1 * V_6 , * V_7 = NULL ;
unsigned int V_8 ;
int V_9 = 0 ;
if ( V_5 >= ( int ) F_2 ( V_10 ) )
return NULL ;
for ( V_8 = 0 ; V_8 < F_2 ( V_10 ) ; ++ V_8 ) {
V_6 = & V_10 [ V_8 ] ;
if ( V_3 && ! ( V_3 -> V_11 & V_6 -> V_12 ) )
continue;
if ( V_4 && V_6 -> V_13 == * V_4 )
return V_6 ;
if ( V_5 == V_9 )
V_7 = V_6 ;
V_9 ++ ;
}
return V_7 ;
}
static int F_3 ( T_1 V_14 , T_1 V_15 , T_1 * V_16 , T_1 * V_17 )
{
unsigned int V_18 = 6 ;
if ( V_14 >= 64 * V_15 )
return - V_19 ;
while ( V_18 -- ) {
unsigned int V_20 = 1 << V_18 ;
if ( V_14 >= V_15 * V_20 ) {
* V_17 = V_18 , * V_16 = V_20 ;
return 0 ;
}
}
* V_17 = 0 , * V_16 = 1 ;
return 0 ;
}
int F_4 ( struct V_2 * V_3 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_3 -> V_25 -> V_24 ;
int V_26 = V_24 -> V_27 ;
int V_28 = V_24 -> V_29 ;
int V_30 = V_3 -> V_31 . V_32 . V_27 ;
int V_33 = V_3 -> V_31 . V_32 . V_29 ;
int V_34 ;
if ( V_3 -> V_35 == 90 || V_3 -> V_35 == 270 )
F_5 ( V_30 , V_33 ) ;
V_34 = F_3 ( V_26 , V_30 , & V_22 -> V_36 ,
& V_22 -> V_37 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_3 ( V_28 , V_33 , & V_22 -> V_38 ,
& V_22 -> V_39 ) ;
if ( V_34 < 0 )
return V_34 ;
V_22 -> V_40 = V_26 / V_22 -> V_36 ;
V_22 -> V_41 = V_28 / V_22 -> V_38 ;
V_22 -> V_42 = ( V_26 << 8 ) / ( V_30 << V_22 -> V_37 ) ;
V_22 -> V_43 = ( V_28 << 8 ) / ( V_33 << V_22 -> V_39 ) ;
V_22 -> V_44 = ( V_30 >= V_26 ) ;
V_22 -> V_45 = ( V_33 >= V_28 ) ;
V_22 -> V_46 = 0 ;
F_6 ( L_1 ,
V_22 -> V_36 , V_22 -> V_37 ,
V_22 -> V_38 , V_22 -> V_39 ) ;
F_6 ( L_2 ,
V_26 , V_28 , V_30 , V_33 ,
V_22 -> V_44 , V_22 -> V_45 ) ;
return 0 ;
}
static int F_7 ( struct V_47 * V_25 )
{
struct V_48 * V_49 = & V_25 -> V_50 . V_49 ;
struct V_51 * V_52 = & V_25 -> V_52 ;
struct V_53 * V_54 ;
struct V_55 V_56 ;
struct V_57 * V_58 ;
int V_34 ;
V_25 -> V_49 . V_58 = NULL ;
if ( V_49 -> V_59 . V_60 == 0 )
return - V_19 ;
V_54 = F_8 ( V_49 -> V_61 ) ;
if ( V_54 == NULL ) {
F_9 ( V_52 , L_3 ,
V_49 -> V_61 ) ;
return - V_62 ;
}
V_58 = F_10 ( V_52 , V_54 ,
& V_49 -> V_59 , NULL ) ;
if ( V_58 == NULL ) {
F_11 ( V_54 ) ;
F_9 ( V_52 , L_4 ,
V_49 -> V_59 . type ) ;
return - V_62 ;
}
V_25 -> V_49 . V_58 = V_58 ;
F_12 ( V_52 , L_5 , V_58 -> V_63 ) ;
V_56 . V_64 = 0 ;
V_56 . V_65 = V_66 ;
V_34 = F_13 ( V_58 , V_64 , V_67 , NULL , & V_56 ) ;
if ( V_34 < 0 )
return 0 ;
V_56 . V_64 = V_68 ;
F_13 ( & V_25 -> V_69 , V_64 , V_70 , NULL , & V_56 ) ;
F_12 ( V_58 , L_6 ,
V_56 . V_56 . V_27 , V_56 . V_56 . V_29 ,
V_56 . V_56 . V_71 ) ;
return 0 ;
}
static void F_14 ( struct V_47 * V_25 )
{
struct V_57 * V_58 = V_25 -> V_49 . V_58 ;
struct V_72 * V_73 = V_58 ? F_15 ( V_58 ) : NULL ;
struct V_53 * V_54 ;
if ( V_73 == NULL )
return;
V_54 = V_73 -> V_54 ;
F_16 ( V_58 ) ;
V_25 -> V_49 . V_58 = NULL ;
F_17 ( V_73 ) ;
F_11 ( V_54 ) ;
}
static int F_18 ( struct V_47 * V_25 )
{
int V_8 , V_34 ;
V_34 = F_19 ( & V_25 -> V_49 . V_58 -> V_74 , 0 ,
& V_25 -> V_69 . V_74 , V_68 ,
V_75 |
V_76 ) ;
if ( V_34 )
return V_34 ;
for ( V_8 = 1 ; V_8 < V_77 && ! V_34 ; V_8 ++ ) {
V_34 = F_19 ( & V_25 -> V_69 . V_74 , V_8 ,
& V_25 -> V_3 [ V_8 - 1 ] . V_78 . V_74 , 0 ,
V_75 |
V_76 ) ;
}
return V_34 ;
}
static int F_20 ( struct V_47 * V_25 )
{
int V_34 = F_21 ( V_25 , V_79 ) ;
if ( V_34 < 0 )
return V_34 ;
return F_21 ( V_25 , V_80 ) ;
}
static void F_22 ( struct V_47 * V_25 )
{
F_23 ( V_25 , V_79 ) ;
F_23 ( V_25 , V_80 ) ;
}
static void F_24 ( struct V_47 * V_25 )
{
F_22 ( V_25 ) ;
F_14 ( V_25 ) ;
F_25 ( V_25 ) ;
}
static int F_26 ( struct V_47 * V_25 )
{
struct V_81 * V_82 = & V_25 -> V_83 ;
struct V_51 * V_52 = & V_25 -> V_52 ;
unsigned int V_84 = V_25 -> V_85 -> V_86 ;
int V_34 ;
memset ( V_82 , 0 , sizeof( * V_82 ) ) ;
snprintf ( V_82 -> V_87 , sizeof( V_82 -> V_87 ) , L_7 ,
V_84 == V_88 ? L_8 : L_9 ) ;
F_27 ( V_82 -> V_89 , L_10 , sizeof( V_82 -> V_89 ) ) ;
V_82 -> V_90 = V_84 ;
V_82 -> V_91 = F_28 ( 1 , 0 , 0 ) ;
V_82 -> V_92 = V_25 -> V_92 ;
F_27 ( V_52 -> V_63 , L_11 , sizeof( V_52 -> V_63 ) ) ;
V_52 -> V_93 = V_82 ;
F_29 ( V_82 ) ;
V_34 = F_30 ( V_25 -> V_92 , V_52 ) ;
if ( V_34 < 0 )
return V_34 ;
return V_34 ;
}
static void F_31 ( struct V_47 * V_25 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_94 ; V_8 ++ ) {
if ( F_32 ( V_25 -> clock [ V_8 ] ) )
continue;
F_33 ( V_25 -> clock [ V_8 ] ) ;
F_34 ( V_25 -> clock [ V_8 ] ) ;
V_25 -> clock [ V_8 ] = F_35 ( - V_19 ) ;
}
}
static int F_36 ( struct V_47 * V_25 )
{
int V_34 , V_8 ;
for ( V_8 = 1 ; V_8 < V_94 ; V_8 ++ )
V_25 -> clock [ V_8 ] = F_35 ( - V_19 ) ;
for ( V_8 = 0 ; V_8 < V_94 ; V_8 ++ ) {
V_25 -> clock [ V_8 ] = F_37 ( V_25 -> V_92 , V_95 [ V_8 ] ) ;
if ( F_32 ( V_25 -> clock [ V_8 ] ) ) {
V_34 = F_38 ( V_25 -> clock [ V_8 ] ) ;
goto V_96;
}
V_34 = F_39 ( V_25 -> clock [ V_8 ] ) ;
if ( V_34 < 0 ) {
F_34 ( V_25 -> clock [ V_8 ] ) ;
V_25 -> clock [ V_8 ] = NULL ;
goto V_96;
}
}
return 0 ;
V_96:
F_31 ( V_25 ) ;
F_40 ( V_25 -> V_92 , L_12 ,
V_95 [ V_8 ] ) ;
return V_34 ;
}
static int F_41 ( struct V_97 * V_98 ,
struct V_47 * V_25 )
{
int V_99 , V_34 , V_8 ;
for ( V_8 = 0 ; V_8 < V_100 ; V_8 ++ ) {
struct V_2 * V_3 = & V_25 -> V_3 [ V_8 ] ;
F_42 ( & V_3 -> V_101 ) ;
V_99 = F_43 ( V_98 , V_8 ) ;
if ( V_99 <= 0 ) {
F_40 ( & V_98 -> V_92 , L_13 , V_8 ) ;
return - V_102 ;
}
V_34 = F_44 ( & V_98 -> V_92 , V_99 , V_103 ,
0 , F_45 ( & V_98 -> V_92 ) , V_3 ) ;
if ( V_34 < 0 ) {
F_40 ( & V_98 -> V_92 , L_14 , V_34 ) ;
break;
}
}
return V_34 ;
}
static int F_46 ( struct V_97 * V_98 )
{
struct V_104 * V_92 = & V_98 -> V_92 ;
struct V_105 * V_50 = V_92 -> V_106 ;
struct V_107 * V_108 ;
struct V_47 * V_25 ;
struct V_109 * V_110 ;
int V_34 = 0 ;
V_25 = F_47 ( V_92 , sizeof( * V_25 ) , V_111 ) ;
if ( ! V_25 )
return - V_112 ;
F_48 ( & V_25 -> V_113 ) ;
F_49 ( & V_25 -> V_114 ) ;
V_25 -> V_92 = V_92 ;
if ( ! V_50 || ! V_50 -> V_115 || ! V_50 -> V_116 ) {
F_40 ( V_92 , L_15 ) ;
return - V_19 ;
}
V_25 -> V_50 = * V_50 ;
V_108 = ( void * ) F_50 ( V_98 ) -> V_117 ;
V_25 -> V_85 = V_108 -> V_85 ;
V_110 = F_51 ( V_98 , V_118 , 0 ) ;
V_25 -> V_119 = F_52 ( V_92 , V_110 ) ;
if ( F_32 ( V_25 -> V_119 ) )
return F_38 ( V_25 -> V_119 ) ;
V_34 = F_41 ( V_98 , V_25 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = V_50 -> V_115 () ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_53 ( V_25 ) ;
if ( V_34 < 0 )
goto V_120;
V_34 = F_36 ( V_25 ) ;
if ( V_34 < 0 )
goto V_121;
F_54 ( V_98 , V_25 ) ;
F_55 ( V_25 -> clock [ V_122 ] ,
V_25 -> V_50 . V_49 . V_123 ) ;
F_56 ( V_92 , L_16 ,
F_57 ( V_25 -> clock [ V_122 ] ) ) ;
F_58 ( V_25 ) ;
F_59 ( V_92 ) ;
V_34 = F_60 ( V_92 ) ;
if ( V_34 < 0 )
goto V_124;
V_34 = F_26 ( V_25 ) ;
if ( V_34 < 0 )
goto V_125;
V_34 = F_7 ( V_25 ) ;
if ( V_34 < 0 )
goto V_126;
V_34 = F_61 ( & V_25 -> V_52 , & V_25 -> V_69 ) ;
if ( V_34 < 0 )
goto V_126;
V_34 = F_62 ( & V_25 -> V_52 ) ;
if ( V_34 < 0 )
goto V_126;
V_34 = F_20 ( V_25 ) ;
if ( V_34 < 0 )
goto V_126;
V_34 = F_18 ( V_25 ) ;
if ( V_34 < 0 )
goto V_126;
V_34 = F_63 ( & V_25 -> V_83 ) ;
if ( V_34 < 0 )
goto V_126;
F_64 ( V_92 ) ;
return 0 ;
V_126:
F_65 ( & V_25 -> V_52 ) ;
F_66 ( & V_25 -> V_83 ) ;
F_67 ( & V_25 -> V_83 ) ;
F_24 ( V_25 ) ;
V_125:
F_64 ( V_92 ) ;
F_68 ( V_92 ) ;
V_124:
F_31 ( V_25 ) ;
V_121:
F_25 ( V_25 ) ;
V_120:
V_50 -> V_116 () ;
return V_34 ;
}
static int F_69 ( struct V_97 * V_98 )
{
struct V_47 * V_25 = F_70 ( V_98 ) ;
struct V_105 * V_50 = & V_25 -> V_50 ;
F_66 ( & V_25 -> V_83 ) ;
F_67 ( & V_25 -> V_83 ) ;
F_24 ( V_25 ) ;
F_65 ( & V_25 -> V_52 ) ;
F_68 ( & V_98 -> V_92 ) ;
F_31 ( V_25 ) ;
V_50 -> V_116 () ;
return 0 ;
}
static int F_71 ( struct V_104 * V_92 )
{
struct V_47 * V_25 = F_72 ( V_92 ) ;
F_73 ( V_25 -> clock [ V_127 ] ) ;
F_73 ( V_25 -> clock [ V_122 ] ) ;
return 0 ;
}
static int F_74 ( struct V_104 * V_92 )
{
struct V_47 * V_25 = F_72 ( V_92 ) ;
F_75 ( V_25 -> clock [ V_122 ] ) ;
F_75 ( V_25 -> clock [ V_127 ] ) ;
return 0 ;
}
