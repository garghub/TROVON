void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_5 = F_2 ( V_2 -> V_6 , V_4 -> V_7 ) ;
struct V_1 * * V_8 ;
for ( V_8 = & V_4 -> V_9 [ V_5 ] ; * V_8 ; V_8 = & ( * V_8 ) -> V_10 ) {
if ( * V_8 == V_2 ) {
F_3 ( V_4 -> V_11 ) ;
* V_8 = V_2 -> V_10 ;
F_4 ( V_4 -> V_11 ) ;
F_5 ( & V_2 -> V_12 ,
& V_2 -> V_13 ) ;
F_6 ( V_2 , V_14 ) ;
return;
}
}
F_7 ( 1 ) ;
}
int F_8 ( struct V_1 * V_2 , int V_15 ,
struct V_3 * V_4 )
{
int V_16 = 0 ;
if ( V_2 ) {
if ( V_15 )
V_2 -> V_17 -- ;
V_2 -> V_18 -- ;
if ( V_2 -> V_17 <= 0 && V_2 -> V_18 <= 0 ) {
F_1 ( V_2 , V_4 ) ;
V_16 = 1 ;
}
}
return V_16 ;
}
static int F_9 ( struct V_19 * V_20 , struct V_21 * V_22 ,
struct V_23 * V_24 , struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_25 = 0 , V_26 = - 1 , V_27 = 0 , V_28 = 0 , V_29 = 0 ;
struct V_30 * V_31 ;
F_10 ( V_4 -> V_11 ) ;
V_28 = V_22 -> args [ 0 ] ;
for ( V_27 = 0 ; V_27 < ( V_4 -> V_7 + 1 ) ; V_27 ++ ) {
V_2 = V_4 -> V_9 [ F_2 ( V_27 , V_4 -> V_7 ) ] ;
for (; V_2 ; V_2 = V_2 -> V_10 ) {
V_26 ++ ;
if ( V_26 < V_28 )
continue;
V_24 -> V_32 = V_2 ;
V_24 -> V_33 = V_29 ;
V_31 = F_11 ( V_20 , V_24 -> V_33 ) ;
if ( V_31 == NULL )
goto V_34;
V_25 = F_12 ( V_20 , V_24 , 0 , 0 ) ;
if ( V_25 < 0 ) {
V_26 -- ;
F_13 ( V_20 , V_31 ) ;
goto V_35;
}
F_14 ( V_20 , V_31 ) ;
V_29 ++ ;
if ( V_29 >= V_36 )
goto V_35;
}
}
V_35:
F_15 ( V_4 -> V_11 ) ;
if ( V_29 )
V_22 -> args [ 0 ] += V_29 ;
return V_29 ;
V_34:
F_16 ( V_20 , V_31 ) ;
goto V_35;
}
static int F_17 ( struct V_19 * V_20 , struct V_23 * V_24 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 , * V_37 ;
struct V_30 * V_31 ;
int V_27 = 0 , V_29 = 0 ;
V_31 = F_11 ( V_20 , V_24 -> V_33 ) ;
if ( V_31 == NULL )
goto V_34;
if ( F_18 ( V_20 , V_38 , V_24 -> V_39 -> V_40 ) )
goto V_34;
for ( V_27 = 0 ; V_27 < ( V_4 -> V_7 + 1 ) ; V_27 ++ ) {
V_2 = V_4 -> V_9 [ F_2 ( V_27 , V_4 -> V_7 ) ] ;
while ( V_2 != NULL ) {
V_37 = V_2 -> V_10 ;
if ( V_41 == F_8 ( V_2 , 0 , V_4 ) )
F_19 ( V_24 -> V_39 -> V_42 ) ;
V_29 ++ ;
V_2 = V_37 ;
}
}
if ( F_20 ( V_20 , V_43 , V_29 ) )
goto V_34;
F_14 ( V_20 , V_31 ) ;
return V_29 ;
V_34:
F_16 ( V_20 , V_31 ) ;
return - V_44 ;
}
int F_21 ( struct V_19 * V_20 , struct V_21 * V_22 ,
int type , struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_39 -> V_4 ;
if ( type == V_45 ) {
return F_17 ( V_20 , V_24 , V_4 ) ;
} else if ( type == V_46 ) {
return F_9 ( V_20 , V_22 , V_24 , V_4 ) ;
} else {
F_22 ( 1 , L_1 , type ) ;
return - V_44 ;
}
}
struct V_1 * F_23 ( T_1 V_26 , struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_10 ( V_4 -> V_11 ) ;
for ( V_2 = V_4 -> V_9 [ F_2 ( V_26 , V_4 -> V_7 ) ] ; V_2 ;
V_2 = V_2 -> V_10 ) {
if ( V_2 -> V_6 == V_26 )
break;
}
F_15 ( V_4 -> V_11 ) ;
return V_2 ;
}
T_1 F_24 ( T_1 * V_47 , struct V_3 * V_4 )
{
T_1 V_48 = * V_47 ;
do {
if ( ++ V_48 == 0 )
V_48 = 1 ;
} while ( F_23 ( V_48 , V_4 ) );
return ( * V_47 = V_48 ) ;
}
int F_25 ( struct V_23 * V_24 , T_1 V_26 )
{
struct V_3 * V_4 = V_24 -> V_39 -> V_4 ;
struct V_1 * V_2 = F_23 ( V_26 , V_4 ) ;
if ( V_2 ) {
V_24 -> V_32 = V_2 ;
return 1 ;
}
return 0 ;
}
struct V_1 * F_26 ( T_1 V_26 , struct V_23 * V_24 , int V_15 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = NULL ;
if ( V_26 && ( V_2 = F_23 ( V_26 , V_4 ) ) != NULL ) {
if ( V_15 )
V_2 -> V_17 ++ ;
V_2 -> V_18 ++ ;
V_24 -> V_32 = V_2 ;
}
return V_2 ;
}
struct V_1 * F_27 ( T_1 V_26 , struct V_30 * V_49 ,
struct V_23 * V_24 , int V_50 , int V_15 ,
T_1 * V_47 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_28 ( V_50 , V_51 ) ;
if ( F_29 ( ! V_2 ) )
return F_30 ( - V_52 ) ;
V_2 -> V_18 = 1 ;
if ( V_15 )
V_2 -> V_17 = 1 ;
F_31 ( & V_2 -> V_53 ) ;
V_2 -> V_6 = V_26 ? V_26 : F_24 ( V_47 , V_4 ) ;
V_2 -> V_54 . V_55 = V_56 ;
V_2 -> V_54 . V_57 = V_56 ;
if ( V_49 ) {
int V_25 = F_32 ( & V_2 -> V_12 , & V_2 -> V_13 ,
& V_2 -> V_53 , V_49 ) ;
if ( V_25 ) {
F_33 ( V_2 ) ;
return F_30 ( V_25 ) ;
}
}
V_24 -> V_32 = ( void * ) V_2 ;
return V_2 ;
}
void F_34 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_5 = F_2 ( V_2 -> V_6 , V_4 -> V_7 ) ;
F_3 ( V_4 -> V_11 ) ;
V_2 -> V_10 = V_4 -> V_9 [ V_5 ] ;
V_4 -> V_9 [ V_5 ] = V_2 ;
F_4 ( V_4 -> V_11 ) ;
}
int F_35 ( struct V_58 * V_59 )
{
struct V_58 * V_24 , * * V_60 ;
F_36 ( & V_61 ) ;
for ( V_60 = & V_62 ; ( V_24 = * V_60 ) != NULL ; V_60 = & V_24 -> V_63 ) {
if ( V_59 -> type == V_24 -> type || ( strcmp ( V_59 -> V_40 , V_24 -> V_40 ) == 0 ) ) {
F_37 ( & V_61 ) ;
return - V_64 ;
}
}
V_59 -> V_63 = NULL ;
* V_60 = V_59 ;
F_37 ( & V_61 ) ;
return 0 ;
}
int F_38 ( struct V_58 * V_59 )
{
struct V_58 * V_24 , * * V_60 ;
int V_25 = - V_65 ;
F_36 ( & V_61 ) ;
for ( V_60 = & V_62 ; ( V_24 = * V_60 ) != NULL ; V_60 = & V_24 -> V_63 )
if ( V_24 == V_59 )
break;
if ( V_24 ) {
* V_60 = V_24 -> V_63 ;
V_24 -> V_63 = NULL ;
V_25 = 0 ;
}
F_37 ( & V_61 ) ;
return V_25 ;
}
static struct V_58 * F_39 ( char * V_40 )
{
struct V_58 * V_24 = NULL ;
if ( V_40 ) {
F_40 ( & V_61 ) ;
for ( V_24 = V_62 ; V_24 ; V_24 = V_24 -> V_63 ) {
if ( strcmp ( V_40 , V_24 -> V_40 ) == 0 ) {
if ( ! F_41 ( V_24 -> V_42 ) ) {
F_42 ( & V_61 ) ;
return NULL ;
}
break;
}
}
F_42 ( & V_61 ) ;
}
return V_24 ;
}
static struct V_58 * F_43 ( struct V_30 * V_40 )
{
struct V_58 * V_24 = NULL ;
if ( V_40 ) {
F_40 ( & V_61 ) ;
for ( V_24 = V_62 ; V_24 ; V_24 = V_24 -> V_63 ) {
if ( F_44 ( V_40 , V_24 -> V_40 ) == 0 ) {
if ( ! F_41 ( V_24 -> V_42 ) ) {
F_42 ( & V_61 ) ;
return NULL ;
}
break;
}
}
F_42 ( & V_61 ) ;
}
return V_24 ;
}
int F_45 ( struct V_19 * V_20 , const struct V_23 * V_59 ,
struct V_66 * V_67 )
{
const struct V_23 * V_24 ;
int V_16 = - 1 ;
if ( V_20 -> V_68 & V_69 ) {
V_20 -> V_68 = F_46 ( V_20 -> V_68 ) ;
V_16 = V_70 ;
goto V_71;
}
while ( ( V_24 = V_59 ) != NULL ) {
V_72:
if ( V_24 -> V_39 && V_24 -> V_39 -> V_59 ) {
V_16 = V_24 -> V_39 -> V_59 ( V_20 , V_24 , V_67 ) ;
if ( V_73 & V_20 -> V_68 ) {
V_20 -> V_68 = F_47 ( V_20 -> V_68 ) ;
V_20 -> V_68 = F_48 ( V_20 -> V_68 ) ;
}
if ( V_16 == V_74 )
goto V_72;
if ( V_16 != V_75 )
goto V_71;
}
V_59 = V_24 -> V_63 ;
}
V_71:
return V_16 ;
}
void F_49 ( struct V_23 * V_59 , int V_15 )
{
struct V_23 * V_24 ;
for ( V_24 = V_59 ; V_24 ; V_24 = V_59 ) {
if ( V_24 -> V_39 && V_24 -> V_39 -> V_76 ) {
if ( V_24 -> V_39 -> V_76 ( V_24 , V_15 ) == V_41 )
F_19 ( V_24 -> V_39 -> V_42 ) ;
V_59 = V_59 -> V_63 ;
F_33 ( V_24 ) ;
} else {
F_22 ( 1 , L_2 ) ;
V_59 = V_59 -> V_63 ;
F_33 ( V_24 ) ;
}
}
}
int
F_50 ( struct V_19 * V_20 , struct V_23 * V_24 , int V_15 , int V_77 )
{
int V_25 = - V_44 ;
if ( V_24 -> V_39 == NULL || V_24 -> V_39 -> V_78 == NULL )
return V_25 ;
return V_24 -> V_39 -> V_78 ( V_20 , V_24 , V_15 , V_77 ) ;
}
int
F_12 ( struct V_19 * V_20 , struct V_23 * V_24 , int V_15 , int V_77 )
{
int V_25 = - V_44 ;
unsigned char * V_79 = F_51 ( V_20 ) ;
struct V_30 * V_31 ;
if ( V_24 -> V_39 == NULL || V_24 -> V_39 -> V_78 == NULL )
return V_25 ;
if ( F_18 ( V_20 , V_38 , V_24 -> V_39 -> V_40 ) )
goto V_34;
if ( F_52 ( V_20 , V_24 , 0 ) )
goto V_34;
V_31 = F_11 ( V_20 , V_80 ) ;
if ( V_31 == NULL )
goto V_34;
V_25 = F_50 ( V_20 , V_24 , V_15 , V_77 ) ;
if ( V_25 > 0 ) {
F_14 ( V_20 , V_31 ) ;
return V_25 ;
}
V_34:
F_13 ( V_20 , V_79 ) ;
return - 1 ;
}
int
F_53 ( struct V_19 * V_20 , struct V_23 * V_59 , int V_15 , int V_77 )
{
struct V_23 * V_24 ;
int V_25 = - V_44 ;
struct V_30 * V_31 ;
while ( ( V_24 = V_59 ) != NULL ) {
V_59 = V_24 -> V_63 ;
V_31 = F_11 ( V_20 , V_24 -> V_33 ) ;
if ( V_31 == NULL )
goto V_34;
V_25 = F_12 ( V_20 , V_24 , V_15 , V_77 ) ;
if ( V_25 < 0 )
goto V_81;
F_14 ( V_20 , V_31 ) ;
}
return 0 ;
V_34:
V_25 = - V_44 ;
V_81:
F_16 ( V_20 , V_31 ) ;
return V_25 ;
}
struct V_23 * F_54 ( struct V_82 * V_82 , struct V_30 * V_83 ,
struct V_30 * V_49 , char * V_84 , int V_85 ,
int V_15 )
{
struct V_23 * V_24 ;
struct V_58 * V_86 ;
char V_87 [ V_88 ] ;
struct V_30 * V_89 [ V_90 + 1 ] ;
struct V_30 * V_40 ;
int V_25 ;
if ( V_84 == NULL ) {
V_25 = F_55 ( V_89 , V_90 , V_83 , NULL ) ;
if ( V_25 < 0 )
goto V_91;
V_25 = - V_44 ;
V_40 = V_89 [ V_92 ] ;
if ( V_40 == NULL )
goto V_91;
if ( F_56 ( V_87 , V_40 , V_88 ) >= V_88 )
goto V_91;
} else {
V_25 = - V_44 ;
if ( F_57 ( V_87 , V_84 , V_88 ) >= V_88 )
goto V_91;
}
V_86 = F_39 ( V_87 ) ;
if ( V_86 == NULL ) {
#ifdef F_58
F_59 () ;
F_60 ( L_3 , V_87 ) ;
F_61 () ;
V_86 = F_39 ( V_87 ) ;
if ( V_86 != NULL ) {
V_25 = - V_93 ;
goto V_94;
}
#endif
V_25 = - V_65 ;
goto V_91;
}
V_25 = - V_52 ;
V_24 = F_28 ( sizeof( * V_24 ) , V_51 ) ;
if ( V_24 == NULL )
goto V_94;
if ( V_84 == NULL )
V_25 = V_86 -> V_95 ( V_82 , V_89 [ V_96 ] , V_49 , V_24 , V_85 , V_15 ) ;
else
V_25 = V_86 -> V_95 ( V_82 , V_83 , V_49 , V_24 , V_85 , V_15 ) ;
if ( V_25 < 0 )
goto V_97;
if ( V_25 != V_98 )
F_19 ( V_86 -> V_42 ) ;
V_24 -> V_39 = V_86 ;
return V_24 ;
V_97:
F_33 ( V_24 ) ;
V_94:
F_19 ( V_86 -> V_42 ) ;
V_91:
return F_30 ( V_25 ) ;
}
struct V_23 * F_62 ( struct V_82 * V_82 , struct V_30 * V_83 ,
struct V_30 * V_49 , char * V_84 , int V_85 ,
int V_15 )
{
struct V_30 * V_89 [ V_36 + 1 ] ;
struct V_23 * V_99 = NULL , * V_59 , * V_100 = NULL ;
int V_25 ;
int V_27 ;
V_25 = F_55 ( V_89 , V_36 , V_83 , NULL ) ;
if ( V_25 < 0 )
return F_30 ( V_25 ) ;
for ( V_27 = 1 ; V_27 <= V_36 && V_89 [ V_27 ] ; V_27 ++ ) {
V_59 = F_54 ( V_82 , V_89 [ V_27 ] , V_49 , V_84 , V_85 , V_15 ) ;
if ( F_63 ( V_59 ) )
goto V_25;
V_59 -> V_33 = V_27 ;
if ( V_99 == NULL )
V_99 = V_59 ;
else
V_100 -> V_63 = V_59 ;
V_100 = V_59 ;
}
return V_99 ;
V_25:
if ( V_99 != NULL )
F_49 ( V_99 , V_15 ) ;
return V_59 ;
}
int F_52 ( struct V_19 * V_20 , struct V_23 * V_24 ,
int V_101 )
{
int V_25 = 0 ;
struct V_102 V_103 ;
struct V_104 * V_5 = V_24 -> V_32 ;
if ( V_5 == NULL )
goto V_81;
if ( V_101 ) {
if ( V_24 -> type == V_105 )
V_25 = F_64 ( V_20 , 0 ,
V_106 , V_107 , & V_5 -> V_108 , & V_103 ) ;
else
return 0 ;
} else
V_25 = F_65 ( V_20 , V_109 ,
& V_5 -> V_108 , & V_103 ) ;
if ( V_25 < 0 )
goto V_81;
if ( V_24 -> V_39 != NULL && V_24 -> V_39 -> V_110 != NULL )
if ( V_24 -> V_39 -> V_110 ( V_20 , V_24 ) < 0 )
goto V_81;
if ( F_66 ( & V_103 , & V_5 -> V_111 ) < 0 ||
F_67 ( & V_103 , & V_5 -> V_111 ,
& V_5 -> V_112 ) < 0 ||
F_68 ( & V_103 , & V_5 -> V_113 ) < 0 )
goto V_81;
if ( F_69 ( & V_103 ) < 0 )
goto V_81;
return 0 ;
V_81:
return - 1 ;
}
static int
F_70 ( struct V_19 * V_20 , struct V_23 * V_24 , T_1 V_114 , T_1 V_115 ,
T_2 V_116 , int V_117 , int V_15 , int V_77 )
{
struct V_118 * V_119 ;
struct V_120 * V_121 ;
unsigned char * V_79 = F_51 ( V_20 ) ;
struct V_30 * V_31 ;
V_121 = F_71 ( V_20 , V_114 , V_115 , V_117 , sizeof( * V_119 ) , V_116 ) ;
if ( ! V_121 )
goto V_122;
V_119 = F_72 ( V_121 ) ;
V_119 -> V_123 = V_124 ;
V_119 -> V_125 = 0 ;
V_119 -> V_126 = 0 ;
V_31 = F_11 ( V_20 , V_127 ) ;
if ( V_31 == NULL )
goto V_122;
if ( F_53 ( V_20 , V_24 , V_15 , V_77 ) < 0 )
goto V_122;
F_14 ( V_20 , V_31 ) ;
V_121 -> V_128 = F_51 ( V_20 ) - V_79 ;
return V_20 -> V_129 ;
V_122:
F_13 ( V_20 , V_79 ) ;
return - 1 ;
}
static int
F_73 ( struct V_82 * V_82 , T_1 V_114 , struct V_120 * V_130 ,
struct V_23 * V_24 , int V_117 )
{
struct V_19 * V_20 ;
V_20 = F_74 ( V_131 , V_51 ) ;
if ( ! V_20 )
return - V_132 ;
if ( F_70 ( V_20 , V_24 , V_114 , V_130 -> V_133 , 0 , V_117 , 0 , 0 ) <= 0 ) {
F_75 ( V_20 ) ;
return - V_44 ;
}
return F_76 ( V_20 , V_82 , V_114 ) ;
}
static struct V_23 *
F_77 ( struct V_30 * V_83 , struct V_120 * V_130 , T_1 V_114 )
{
struct V_30 * V_89 [ V_90 + 1 ] ;
struct V_23 * V_24 ;
int V_26 ;
int V_25 ;
V_25 = F_55 ( V_89 , V_90 , V_83 , NULL ) ;
if ( V_25 < 0 )
goto V_91;
V_25 = - V_44 ;
if ( V_89 [ V_134 ] == NULL ||
F_78 ( V_89 [ V_134 ] ) < sizeof( V_26 ) )
goto V_91;
V_26 = F_79 ( V_89 [ V_134 ] ) ;
V_25 = - V_52 ;
V_24 = F_28 ( sizeof( struct V_23 ) , V_51 ) ;
if ( V_24 == NULL )
goto V_91;
V_25 = - V_44 ;
V_24 -> V_39 = F_43 ( V_89 [ V_92 ] ) ;
if ( V_24 -> V_39 == NULL )
goto V_97;
if ( V_24 -> V_39 -> V_135 == NULL )
goto V_94;
V_25 = - V_65 ;
if ( V_24 -> V_39 -> V_135 ( V_24 , V_26 ) == 0 )
goto V_94;
F_19 ( V_24 -> V_39 -> V_42 ) ;
return V_24 ;
V_94:
F_19 ( V_24 -> V_39 -> V_42 ) ;
V_97:
F_33 ( V_24 ) ;
V_91:
return F_30 ( V_25 ) ;
}
static void F_80 ( struct V_23 * V_59 )
{
struct V_23 * V_24 ;
for ( V_24 = V_59 ; V_24 ; V_24 = V_59 ) {
V_59 = V_24 -> V_63 ;
F_33 ( V_24 ) ;
}
}
static struct V_23 * F_81 ( int V_27 )
{
struct V_23 * V_59 ;
V_59 = F_28 ( sizeof( * V_59 ) , V_51 ) ;
if ( V_59 == NULL ) {
F_82 ( L_4 ) ;
return NULL ;
}
V_59 -> V_33 = V_27 ;
return V_59 ;
}
static int F_83 ( struct V_82 * V_82 , struct V_30 * V_83 ,
struct V_120 * V_130 , T_1 V_114 )
{
struct V_19 * V_20 ;
unsigned char * V_79 ;
struct V_120 * V_121 ;
struct V_118 * V_119 ;
struct V_21 V_136 ;
struct V_30 * V_31 ;
struct V_30 * V_89 [ V_90 + 1 ] ;
struct V_30 * V_40 ;
struct V_23 * V_24 = F_81 ( 0 ) ;
int V_25 = - V_52 ;
if ( V_24 == NULL ) {
F_82 ( L_5 ) ;
return V_25 ;
}
V_20 = F_74 ( V_131 , V_51 ) ;
if ( ! V_20 ) {
F_82 ( L_6 ) ;
F_33 ( V_24 ) ;
return V_25 ;
}
V_79 = F_51 ( V_20 ) ;
V_25 = F_55 ( V_89 , V_90 , V_83 , NULL ) ;
if ( V_25 < 0 )
goto V_91;
V_25 = - V_44 ;
V_40 = V_89 [ V_92 ] ;
V_24 -> V_39 = F_43 ( V_40 ) ;
if ( V_24 -> V_39 == NULL )
goto V_91;
V_121 = F_71 ( V_20 , V_114 , V_130 -> V_133 , V_45 , sizeof( * V_119 ) , 0 ) ;
if ( ! V_121 )
goto V_137;
V_119 = F_72 ( V_121 ) ;
V_119 -> V_123 = V_124 ;
V_119 -> V_125 = 0 ;
V_119 -> V_126 = 0 ;
V_31 = F_11 ( V_20 , V_127 ) ;
if ( V_31 == NULL )
goto V_137;
V_25 = V_24 -> V_39 -> V_138 ( V_20 , & V_136 , V_45 , V_24 ) ;
if ( V_25 < 0 )
goto V_137;
if ( V_25 == 0 )
goto V_139;
F_14 ( V_20 , V_31 ) ;
V_121 -> V_128 = F_51 ( V_20 ) - V_79 ;
V_121 -> V_140 |= V_141 ;
F_19 ( V_24 -> V_39 -> V_42 ) ;
F_33 ( V_24 ) ;
V_25 = F_84 ( V_20 , V_82 , V_114 , V_142 ,
V_130 -> V_140 & V_143 ) ;
if ( V_25 > 0 )
return 0 ;
return V_25 ;
V_137:
F_19 ( V_24 -> V_39 -> V_42 ) ;
V_91:
V_139:
F_75 ( V_20 ) ;
F_33 ( V_24 ) ;
return V_25 ;
}
static int
F_85 ( struct V_82 * V_82 , struct V_30 * V_83 , struct V_120 * V_130 ,
T_1 V_114 , int V_117 )
{
int V_27 , V_16 ;
struct V_30 * V_89 [ V_36 + 1 ] ;
struct V_23 * V_99 = NULL , * V_59 , * V_100 = NULL ;
V_16 = F_55 ( V_89 , V_36 , V_83 , NULL ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_117 == V_45 && V_130 -> V_140 & V_141 ) {
if ( V_89 [ 1 ] != NULL )
return F_83 ( V_82 , V_89 [ 1 ] , V_130 , V_114 ) ;
else
return - V_44 ;
}
for ( V_27 = 1 ; V_27 <= V_36 && V_89 [ V_27 ] ; V_27 ++ ) {
V_59 = F_77 ( V_89 [ V_27 ] , V_130 , V_114 ) ;
if ( F_63 ( V_59 ) ) {
V_16 = F_86 ( V_59 ) ;
goto V_25;
}
V_59 -> V_33 = V_27 ;
if ( V_99 == NULL )
V_99 = V_59 ;
else
V_100 -> V_63 = V_59 ;
V_100 = V_59 ;
}
if ( V_117 == V_46 )
V_16 = F_73 ( V_82 , V_114 , V_130 , V_99 , V_117 ) ;
else {
struct V_19 * V_20 ;
V_20 = F_74 ( V_131 , V_51 ) ;
if ( ! V_20 ) {
V_16 = - V_132 ;
goto V_25;
}
if ( F_70 ( V_20 , V_99 , V_114 , V_130 -> V_133 , 0 , V_117 ,
0 , 1 ) <= 0 ) {
F_75 ( V_20 ) ;
V_16 = - V_44 ;
goto V_25;
}
F_49 ( V_99 , 0 ) ;
V_16 = F_84 ( V_20 , V_82 , V_114 , V_142 ,
V_130 -> V_140 & V_143 ) ;
if ( V_16 > 0 )
return 0 ;
return V_16 ;
}
V_25:
F_80 ( V_99 ) ;
return V_16 ;
}
static int F_87 ( struct V_82 * V_82 , struct V_23 * V_24 ,
T_1 V_114 , T_1 V_115 , int V_117 , T_2 V_116 )
{
struct V_118 * V_119 ;
struct V_120 * V_121 ;
struct V_19 * V_20 ;
struct V_30 * V_31 ;
unsigned char * V_79 ;
int V_25 = 0 ;
V_20 = F_74 ( V_131 , V_51 ) ;
if ( ! V_20 )
return - V_132 ;
V_79 = F_51 ( V_20 ) ;
V_121 = F_71 ( V_20 , V_114 , V_115 , V_117 , sizeof( * V_119 ) , V_116 ) ;
if ( ! V_121 )
goto V_144;
V_119 = F_72 ( V_121 ) ;
V_119 -> V_123 = V_124 ;
V_119 -> V_125 = 0 ;
V_119 -> V_126 = 0 ;
V_31 = F_11 ( V_20 , V_127 ) ;
if ( V_31 == NULL )
goto V_144;
if ( F_53 ( V_20 , V_24 , 0 , 0 ) < 0 )
goto V_144;
F_14 ( V_20 , V_31 ) ;
V_121 -> V_128 = F_51 ( V_20 ) - V_79 ;
F_88 ( V_20 ) . V_145 = V_142 ;
V_25 = F_84 ( V_20 , V_82 , V_114 , V_142 , V_116 & V_143 ) ;
if ( V_25 > 0 )
V_25 = 0 ;
return V_25 ;
V_144:
F_75 ( V_20 ) ;
return - 1 ;
}
static int
F_89 ( struct V_82 * V_82 , struct V_30 * V_83 , struct V_120 * V_130 ,
T_1 V_114 , int V_85 )
{
int V_16 = 0 ;
struct V_23 * V_59 ;
struct V_23 * V_24 ;
T_1 V_115 = V_130 -> V_133 ;
V_59 = F_62 ( V_82 , V_83 , NULL , NULL , V_85 , 0 ) ;
if ( V_59 == NULL )
goto V_35;
if ( F_63 ( V_59 ) ) {
V_16 = F_86 ( V_59 ) ;
goto V_35;
}
V_16 = F_87 ( V_82 , V_59 , V_114 , V_115 , V_146 , V_130 -> V_140 ) ;
for ( V_24 = V_59 ; V_24 ; V_24 = V_59 ) {
V_59 = V_24 -> V_63 ;
F_33 ( V_24 ) ;
}
V_35:
return V_16 ;
}
static int F_90 ( struct V_19 * V_20 , struct V_120 * V_130 , void * V_147 )
{
struct V_82 * V_82 = F_91 ( V_20 -> V_148 ) ;
struct V_30 * V_149 [ V_90 + 1 ] ;
T_1 V_114 = V_20 ? F_88 ( V_20 ) . V_114 : 0 ;
int V_16 = 0 , V_85 = 0 ;
if ( ( V_130 -> V_150 != V_46 ) && ! F_92 ( V_151 ) )
return - V_152 ;
V_16 = F_93 ( V_130 , sizeof( struct V_118 ) , V_149 , V_90 , NULL ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_149 [ V_127 ] == NULL ) {
F_94 ( L_7 ) ;
return - V_44 ;
}
switch ( V_130 -> V_150 ) {
case V_146 :
if ( V_130 -> V_140 & V_153 )
V_85 = 1 ;
V_154:
V_16 = F_89 ( V_82 , V_149 [ V_127 ] , V_130 , V_114 , V_85 ) ;
if ( V_16 == - V_93 )
goto V_154;
break;
case V_45 :
V_16 = F_85 ( V_82 , V_149 [ V_127 ] , V_130 ,
V_114 , V_45 ) ;
break;
case V_46 :
V_16 = F_85 ( V_82 , V_149 [ V_127 ] , V_130 ,
V_114 , V_46 ) ;
break;
default:
F_95 () ;
}
return V_16 ;
}
static struct V_30 *
F_96 ( const struct V_120 * V_130 )
{
struct V_30 * V_155 , * V_156 [ V_90 + 1 ] ;
struct V_30 * V_89 [ V_36 + 1 ] ;
struct V_30 * V_83 [ V_157 + 1 ] ;
struct V_30 * V_40 ;
if ( F_93 ( V_130 , sizeof( struct V_118 ) , V_83 , V_157 , NULL ) < 0 )
return NULL ;
V_155 = V_83 [ V_127 ] ;
if ( V_155 == NULL )
return NULL ;
if ( F_97 ( V_89 , V_36 , F_98 ( V_155 ) ,
F_99 ( F_78 ( V_155 ) ) , NULL ) < 0 )
return NULL ;
if ( V_89 [ 1 ] == NULL )
return NULL ;
if ( F_97 ( V_156 , V_90 , F_98 ( V_89 [ 1 ] ) ,
F_78 ( V_89 [ 1 ] ) , NULL ) < 0 )
return NULL ;
V_40 = V_156 [ V_92 ] ;
return V_40 ;
}
static int
F_100 ( struct V_19 * V_20 , struct V_21 * V_22 )
{
struct V_120 * V_121 ;
unsigned char * V_79 = F_51 ( V_20 ) ;
struct V_30 * V_31 ;
struct V_58 * V_86 ;
struct V_23 V_24 ;
int V_16 = 0 ;
struct V_118 * V_119 = (struct V_118 * ) F_72 ( V_22 -> V_121 ) ;
struct V_30 * V_40 = F_96 ( V_22 -> V_121 ) ;
if ( V_40 == NULL ) {
F_101 ( L_8 ) ;
return 0 ;
}
V_86 = F_43 ( V_40 ) ;
if ( V_86 == NULL )
return 0 ;
memset ( & V_24 , 0 , sizeof( struct V_23 ) ) ;
V_24 . V_39 = V_86 ;
if ( V_86 -> V_138 == NULL ) {
F_22 ( 1 , L_9 ,
V_86 -> V_40 ) ;
goto V_137;
}
V_121 = F_71 ( V_20 , F_88 ( V_22 -> V_20 ) . V_114 , V_22 -> V_121 -> V_133 ,
V_22 -> V_121 -> V_150 , sizeof( * V_119 ) , 0 ) ;
if ( ! V_121 )
goto V_137;
V_119 = F_72 ( V_121 ) ;
V_119 -> V_123 = V_124 ;
V_119 -> V_125 = 0 ;
V_119 -> V_126 = 0 ;
V_31 = F_11 ( V_20 , V_127 ) ;
if ( V_31 == NULL )
goto V_137;
V_16 = V_86 -> V_138 ( V_20 , V_22 , V_46 , & V_24 ) ;
if ( V_16 < 0 )
goto V_137;
if ( V_16 > 0 ) {
F_14 ( V_20 , V_31 ) ;
V_16 = V_20 -> V_129 ;
} else
F_16 ( V_20 , V_31 ) ;
V_121 -> V_128 = F_51 ( V_20 ) - V_79 ;
if ( F_88 ( V_22 -> V_20 ) . V_114 && V_16 )
V_121 -> V_140 |= V_158 ;
F_19 ( V_86 -> V_42 ) ;
return V_20 -> V_129 ;
V_137:
F_19 ( V_86 -> V_42 ) ;
F_13 ( V_20 , V_79 ) ;
return V_20 -> V_129 ;
}
static int T_3 F_102 ( void )
{
F_103 ( V_159 , V_146 , F_90 , NULL , NULL ) ;
F_103 ( V_159 , V_45 , F_90 , NULL , NULL ) ;
F_103 ( V_159 , V_46 , F_90 , F_100 ,
NULL ) ;
return 0 ;
}
