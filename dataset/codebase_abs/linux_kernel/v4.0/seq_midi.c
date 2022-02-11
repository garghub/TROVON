static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 V_8 ;
char V_9 [ 16 ] , * V_10 ;
long V_11 , V_12 ;
if ( V_2 == NULL )
return;
V_4 = V_2 -> V_4 ;
V_6 = V_4 -> V_13 ;
if ( V_6 == NULL )
return;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
while ( V_4 -> V_14 > 0 ) {
V_11 = F_2 ( V_2 , V_9 , sizeof( V_9 ) ) ;
if ( V_11 <= 0 )
continue;
if ( V_6 -> V_15 == NULL )
continue;
V_10 = V_9 ;
while ( V_11 > 0 ) {
V_12 = F_3 ( V_6 -> V_15 , V_10 , V_11 , & V_8 ) ;
if ( V_12 < 0 )
break;
V_10 += V_12 ;
V_11 -= V_12 ;
if ( V_8 . type != V_16 ) {
V_8 . V_17 . V_18 = V_6 -> V_19 ;
V_8 . V_20 . V_21 = V_22 ;
F_4 ( V_6 -> V_23 , & V_8 , 1 , 0 ) ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
}
}
}
}
static int F_5 ( struct V_1 * V_2 , const char * V_9 , int V_12 )
{
struct V_3 * V_4 ;
int V_24 ;
if ( F_6 ( ! V_2 || ! V_9 ) )
return - V_25 ;
V_4 = V_2 -> V_4 ;
if ( ( V_24 = V_4 -> V_14 ) < V_12 ) {
if ( F_7 () )
F_8 ( L_1 ) ;
return - V_26 ;
}
if ( F_9 ( V_2 , V_9 , V_12 ) < V_12 )
return - V_25 ;
return 0 ;
}
static int F_10 ( struct V_7 * V_8 , int V_27 ,
void * V_13 , int V_28 , int V_29 )
{
struct V_5 * V_6 = V_13 ;
unsigned char V_30 [ 10 ] ;
struct V_1 * V_2 ;
int V_31 ;
if ( F_6 ( ! V_6 ) )
return - V_25 ;
V_2 = V_6 -> V_32 . V_33 ;
if ( V_2 == NULL )
return - V_34 ;
if ( V_8 -> type == V_35 ) {
if ( ( V_8 -> V_36 & V_37 ) != V_38 ) {
F_11 ( L_2 , V_8 -> V_36 ) ;
return 0 ;
}
F_12 ( V_8 , ( V_39 ) F_5 , V_2 ) ;
F_13 ( V_6 -> V_15 ) ;
} else {
if ( V_6 -> V_15 == NULL )
return - V_40 ;
V_31 = F_14 ( V_6 -> V_15 , V_30 , sizeof( V_30 ) , V_8 ) ;
if ( V_31 < 0 )
return 0 ;
if ( F_5 ( V_2 , V_30 , V_31 ) < 0 )
F_13 ( V_6 -> V_15 ) ;
}
return 0 ;
}
static int F_15 ( struct V_5 * V_6 ,
struct V_41 * V_42 ,
int V_43 ,
int V_44 )
{
if ( F_16 ( V_45 , & V_6 -> V_15 ) < 0 )
return - V_26 ;
V_6 -> V_42 = V_42 ;
V_6 -> V_43 = V_43 ;
V_6 -> V_44 = V_44 ;
return 0 ;
}
static int F_17 ( void * V_13 , struct V_46 * V_47 )
{
int V_48 ;
struct V_5 * V_6 = V_13 ;
struct V_3 * V_4 ;
struct V_49 V_50 ;
if ( ( V_48 = F_18 ( V_6 -> V_42 , V_6 -> V_43 ,
V_6 -> V_44 ,
V_51 ,
& V_6 -> V_52 ) ) < 0 ) {
F_11 ( L_3 ) ;
return V_48 ;
}
V_4 = V_6 -> V_52 . V_53 -> V_4 ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
V_50 . V_54 = 1 ;
V_50 . V_55 = V_56 ;
if ( ( V_48 = F_19 ( V_6 -> V_52 . V_53 , & V_50 ) ) < 0 ) {
F_20 ( & V_6 -> V_52 ) ;
return V_48 ;
}
F_21 ( V_6 -> V_15 ) ;
V_4 -> V_57 = F_1 ;
V_4 -> V_13 = V_6 ;
F_2 ( V_6 -> V_52 . V_53 , NULL , 0 ) ;
return 0 ;
}
static int F_22 ( void * V_13 , struct V_46 * V_47 )
{
int V_48 ;
struct V_5 * V_6 = V_13 ;
if ( F_6 ( ! V_6 -> V_52 . V_53 ) )
return - V_25 ;
V_48 = F_20 ( & V_6 -> V_52 ) ;
return V_48 ;
}
static int F_23 ( void * V_13 , struct V_46 * V_47 )
{
int V_48 ;
struct V_5 * V_6 = V_13 ;
struct V_49 V_50 ;
if ( ( V_48 = F_18 ( V_6 -> V_42 , V_6 -> V_43 ,
V_6 -> V_44 ,
V_58 ,
& V_6 -> V_32 ) ) < 0 ) {
F_11 ( L_4 ) ;
return V_48 ;
}
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
V_50 . V_54 = 1 ;
V_50 . V_55 = V_59 ;
V_50 . V_60 = 1 ;
if ( ( V_48 = F_24 ( V_6 -> V_32 . V_33 , & V_50 ) ) < 0 ) {
F_20 ( & V_6 -> V_32 ) ;
return V_48 ;
}
F_13 ( V_6 -> V_15 ) ;
return 0 ;
}
static int F_25 ( void * V_13 , struct V_46 * V_47 )
{
struct V_5 * V_6 = V_13 ;
if ( F_6 ( ! V_6 -> V_32 . V_33 ) )
return - V_25 ;
F_26 ( V_6 -> V_32 . V_33 ) ;
return F_20 ( & V_6 -> V_32 ) ;
}
static void F_27 ( struct V_5 * V_6 )
{
if ( V_6 == NULL )
return;
if ( V_6 -> V_23 > 0 ) {
F_28 ( V_6 -> V_23 , V_6 -> V_19 ) ;
}
F_29 ( V_6 -> V_15 ) ;
}
static int
F_30 ( struct V_61 * V_62 )
{
struct V_63 * V_21 ;
struct V_5 * V_6 , * V_64 ;
struct V_65 * V_18 ;
struct V_66 * V_47 ;
struct V_67 * V_68 = V_62 -> V_13 ;
int V_69 = 0 ;
unsigned int V_70 , V_71 ;
struct V_72 V_73 ;
struct V_41 * V_42 = V_62 -> V_42 ;
int V_43 = V_62 -> V_43 ;
unsigned int V_74 = 0 , V_75 = 0 ;
if ( F_6 ( ! V_42 || V_43 < 0 || V_43 >= V_76 ) )
return - V_25 ;
V_47 = F_31 ( sizeof( * V_47 ) , V_77 ) ;
if ( ! V_47 )
return - V_26 ;
V_47 -> V_43 = V_43 ;
V_47 -> V_78 = V_79 ;
V_47 -> V_44 = 0 ;
if ( F_32 ( V_42 , V_47 ) >= 0 )
V_75 = V_47 -> V_80 ;
V_47 -> V_78 = V_81 ;
if ( F_32 ( V_42 , V_47 ) >= 0 ) {
V_74 = V_47 -> V_80 ;
}
V_71 = V_75 ;
if ( V_71 < V_74 )
V_71 = V_74 ;
if ( V_71 == 0 ) {
F_33 ( V_47 ) ;
return - V_34 ;
}
if ( V_71 > ( 256 / V_76 ) )
V_71 = 256 / V_76 ;
F_34 ( & V_82 ) ;
V_21 = V_83 [ V_42 -> V_84 ] ;
if ( V_21 == NULL ) {
V_69 = 1 ;
V_21 = F_35 ( sizeof( * V_21 ) , V_77 ) ;
if ( V_21 == NULL ) {
F_36 ( & V_82 ) ;
F_33 ( V_47 ) ;
return - V_26 ;
}
V_21 -> V_23 =
F_37 (
V_42 , 0 , L_5 , V_42 -> V_85 [ 0 ] ?
( const char * ) V_42 -> V_85 : L_6 ) ;
if ( V_21 -> V_23 < 0 ) {
F_33 ( V_21 ) ;
F_36 ( & V_82 ) ;
F_33 ( V_47 ) ;
return - V_26 ;
}
}
V_6 = F_38 ( V_71 , sizeof( struct V_5 ) , V_77 ) ;
V_18 = F_31 ( sizeof( * V_18 ) , V_77 ) ;
if ( V_6 == NULL || V_18 == NULL )
goto V_86;
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ ) {
V_64 = & V_6 [ V_70 ] ;
if ( F_15 ( V_64 , V_42 , V_43 , V_70 ) < 0 )
goto V_86;
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
V_18 -> V_87 . V_21 = V_21 -> V_23 ;
V_18 -> V_87 . V_18 = V_43 * ( 256 / V_76 ) + V_70 ;
V_18 -> V_36 = V_88 ;
memset ( V_47 , 0 , sizeof( * V_47 ) ) ;
V_47 -> V_43 = V_43 ;
if ( V_70 < V_75 )
V_47 -> V_78 = V_79 ;
else
V_47 -> V_78 = V_81 ;
V_47 -> V_44 = V_70 ;
if ( F_32 ( V_42 , V_47 ) >= 0 )
strcpy ( V_18 -> V_89 , V_47 -> V_90 ) ;
if ( ! V_18 -> V_89 [ 0 ] ) {
if ( V_47 -> V_89 [ 0 ] ) {
if ( V_71 > 1 )
snprintf ( V_18 -> V_89 , sizeof( V_18 -> V_89 ) , L_7 , V_47 -> V_89 , V_70 ) ;
else
snprintf ( V_18 -> V_89 , sizeof( V_18 -> V_89 ) , L_5 , V_47 -> V_89 ) ;
} else {
if ( V_71 > 1 )
sprintf ( V_18 -> V_89 , L_8 , V_42 -> V_84 , V_43 , V_70 ) ;
else
sprintf ( V_18 -> V_89 , L_9 , V_42 -> V_84 , V_43 ) ;
}
}
if ( ( V_47 -> V_36 & V_91 ) && V_70 < V_75 )
V_18 -> V_92 |= V_93 | V_94 | V_95 ;
if ( ( V_47 -> V_36 & V_96 ) && V_70 < V_74 )
V_18 -> V_92 |= V_97 | V_98 | V_99 ;
if ( ( V_18 -> V_92 & ( V_93 | V_97 ) ) == ( V_93 | V_97 ) &&
V_47 -> V_36 & V_100 )
V_18 -> V_92 |= V_101 ;
V_18 -> type = V_102
| V_103
| V_104 ;
V_18 -> V_105 = 16 ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
V_73 . V_106 = V_107 ;
V_73 . V_13 = V_64 ;
V_73 . V_108 = F_17 ;
V_73 . V_109 = F_22 ;
V_73 . V_110 = F_23 ;
V_73 . V_111 = F_25 ;
V_73 . V_112 = F_10 ;
V_18 -> V_113 = & V_73 ;
if ( V_68 -> V_114 && V_68 -> V_114 -> V_115 )
V_68 -> V_114 -> V_115 ( V_68 , V_70 , V_18 ) ;
if ( F_39 ( V_21 -> V_23 , V_116 , V_18 ) < 0 )
goto V_86;
V_64 -> V_23 = V_21 -> V_23 ;
V_64 -> V_19 = V_18 -> V_87 . V_18 ;
}
V_21 -> V_117 [ V_43 ] = V_71 ;
V_21 -> V_71 [ V_43 ] = V_6 ;
V_21 -> V_118 ++ ;
if ( V_69 )
V_83 [ V_42 -> V_84 ] = V_21 ;
F_36 ( & V_82 ) ;
F_33 ( V_47 ) ;
F_33 ( V_18 ) ;
return 0 ;
V_86:
if ( V_6 != NULL ) {
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ )
F_27 ( & V_6 [ V_70 ] ) ;
F_33 ( V_6 ) ;
}
if ( V_69 ) {
F_40 ( V_21 -> V_23 ) ;
F_33 ( V_21 ) ;
}
F_33 ( V_47 ) ;
F_33 ( V_18 ) ;
F_36 ( & V_82 ) ;
return - V_26 ;
}
static int
F_41 ( struct V_61 * V_62 )
{
struct V_63 * V_21 ;
struct V_5 * V_6 ;
struct V_41 * V_42 = V_62 -> V_42 ;
int V_43 = V_62 -> V_43 , V_70 , V_71 ;
F_34 ( & V_82 ) ;
V_21 = V_83 [ V_42 -> V_84 ] ;
if ( V_21 == NULL || V_21 -> V_71 [ V_43 ] == NULL ) {
F_36 ( & V_82 ) ;
return - V_34 ;
}
V_71 = V_21 -> V_117 [ V_43 ] ;
V_21 -> V_117 [ V_43 ] = 0 ;
V_6 = V_21 -> V_71 [ V_43 ] ;
V_21 -> V_71 [ V_43 ] = NULL ;
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ )
F_27 ( & V_6 [ V_70 ] ) ;
F_33 ( V_6 ) ;
V_21 -> V_118 -- ;
if ( V_21 -> V_118 <= 0 ) {
F_40 ( V_21 -> V_23 ) ;
V_83 [ V_42 -> V_84 ] = NULL ;
F_33 ( V_21 ) ;
}
F_36 ( & V_82 ) ;
return 0 ;
}
static int T_1 F_42 ( void )
{
static struct V_119 V_114 = {
F_30 ,
F_41 ,
} ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
F_43 () ;
F_44 ( V_120 , & V_114 , 0 ) ;
F_45 () ;
return 0 ;
}
static void T_2 F_46 ( void )
{
F_47 ( V_120 ) ;
}
