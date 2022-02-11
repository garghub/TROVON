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
F_8 ( V_26 L_1 ) ;
return - V_27 ;
}
if ( F_9 ( V_2 , V_9 , V_12 ) < V_12 )
return - V_25 ;
return 0 ;
}
static int F_10 ( struct V_7 * V_8 , int V_28 ,
void * V_13 , int V_29 , int V_30 )
{
struct V_5 * V_6 = V_13 ;
unsigned char V_31 [ 10 ] ;
struct V_1 * V_2 ;
int V_32 ;
if ( F_6 ( ! V_6 ) )
return - V_25 ;
V_2 = V_6 -> V_33 . V_34 ;
if ( V_2 == NULL )
return - V_35 ;
if ( V_8 -> type == V_36 ) {
if ( ( V_8 -> V_37 & V_38 ) != V_39 ) {
F_11 ( L_2 , V_8 -> V_37 ) ;
return 0 ;
}
F_12 ( V_8 , ( V_40 ) F_5 , V_2 ) ;
F_13 ( V_6 -> V_15 ) ;
} else {
if ( V_6 -> V_15 == NULL )
return - V_41 ;
V_32 = F_14 ( V_6 -> V_15 , V_31 , sizeof( V_31 ) , V_8 ) ;
if ( V_32 < 0 )
return 0 ;
if ( F_5 ( V_2 , V_31 , V_32 ) < 0 )
F_13 ( V_6 -> V_15 ) ;
}
return 0 ;
}
static int F_15 ( struct V_5 * V_6 ,
struct V_42 * V_43 ,
int V_44 ,
int V_45 )
{
if ( F_16 ( V_46 , & V_6 -> V_15 ) < 0 )
return - V_27 ;
V_6 -> V_43 = V_43 ;
V_6 -> V_44 = V_44 ;
V_6 -> V_45 = V_45 ;
return 0 ;
}
static int F_17 ( void * V_13 , struct V_47 * V_48 )
{
int V_49 ;
struct V_5 * V_6 = V_13 ;
struct V_3 * V_4 ;
struct V_50 V_51 ;
if ( ( V_49 = F_18 ( V_6 -> V_43 , V_6 -> V_44 ,
V_6 -> V_45 ,
V_52 ,
& V_6 -> V_53 ) ) < 0 ) {
F_11 ( L_3 ) ;
return V_49 ;
}
V_4 = V_6 -> V_53 . V_54 -> V_4 ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
V_51 . V_55 = 1 ;
V_51 . V_56 = V_57 ;
if ( ( V_49 = F_19 ( V_6 -> V_53 . V_54 , & V_51 ) ) < 0 ) {
F_20 ( & V_6 -> V_53 ) ;
return V_49 ;
}
F_21 ( V_6 -> V_15 ) ;
V_4 -> V_58 = F_1 ;
V_4 -> V_13 = V_6 ;
F_2 ( V_6 -> V_53 . V_54 , NULL , 0 ) ;
return 0 ;
}
static int F_22 ( void * V_13 , struct V_47 * V_48 )
{
int V_49 ;
struct V_5 * V_6 = V_13 ;
if ( F_6 ( ! V_6 -> V_53 . V_54 ) )
return - V_25 ;
V_49 = F_20 ( & V_6 -> V_53 ) ;
return V_49 ;
}
static int F_23 ( void * V_13 , struct V_47 * V_48 )
{
int V_49 ;
struct V_5 * V_6 = V_13 ;
struct V_50 V_51 ;
if ( ( V_49 = F_18 ( V_6 -> V_43 , V_6 -> V_44 ,
V_6 -> V_45 ,
V_59 ,
& V_6 -> V_33 ) ) < 0 ) {
F_11 ( L_4 ) ;
return V_49 ;
}
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
V_51 . V_55 = 1 ;
V_51 . V_56 = V_60 ;
V_51 . V_61 = 1 ;
if ( ( V_49 = F_24 ( V_6 -> V_33 . V_34 , & V_51 ) ) < 0 ) {
F_20 ( & V_6 -> V_33 ) ;
return V_49 ;
}
F_13 ( V_6 -> V_15 ) ;
return 0 ;
}
static int F_25 ( void * V_13 , struct V_47 * V_48 )
{
struct V_5 * V_6 = V_13 ;
if ( F_6 ( ! V_6 -> V_33 . V_34 ) )
return - V_25 ;
F_26 ( V_6 -> V_33 . V_34 ) ;
return F_20 ( & V_6 -> V_33 ) ;
}
static void F_27 ( struct V_5 * V_6 )
{
if ( V_6 == NULL )
return;
if ( V_6 -> V_23 > 0 ) {
F_28 ( V_6 -> V_23 , V_6 -> V_19 ) ;
}
if ( V_6 -> V_15 )
F_29 ( V_6 -> V_15 ) ;
}
static int
F_30 ( struct V_62 * V_63 )
{
struct V_64 * V_21 ;
struct V_5 * V_6 , * V_65 ;
struct V_66 * V_18 ;
struct V_67 * V_48 ;
struct V_68 * V_69 = V_63 -> V_13 ;
int V_70 = 0 ;
unsigned int V_71 , V_72 ;
struct V_73 V_74 ;
struct V_42 * V_43 = V_63 -> V_43 ;
int V_44 = V_63 -> V_44 ;
unsigned int V_75 = 0 , V_76 = 0 ;
if ( F_6 ( ! V_43 || V_44 < 0 || V_44 >= V_77 ) )
return - V_25 ;
V_48 = F_31 ( sizeof( * V_48 ) , V_78 ) ;
if ( ! V_48 )
return - V_27 ;
V_48 -> V_44 = V_44 ;
V_48 -> V_79 = V_80 ;
V_48 -> V_45 = 0 ;
if ( F_32 ( V_43 , V_48 ) >= 0 )
V_76 = V_48 -> V_81 ;
V_48 -> V_79 = V_82 ;
if ( F_32 ( V_43 , V_48 ) >= 0 ) {
V_75 = V_48 -> V_81 ;
}
V_72 = V_76 ;
if ( V_72 < V_75 )
V_72 = V_75 ;
if ( V_72 == 0 ) {
F_33 ( V_48 ) ;
return - V_35 ;
}
if ( V_72 > ( 256 / V_77 ) )
V_72 = 256 / V_77 ;
F_34 ( & V_83 ) ;
V_21 = V_84 [ V_43 -> V_85 ] ;
if ( V_21 == NULL ) {
V_70 = 1 ;
V_21 = F_35 ( sizeof( * V_21 ) , V_78 ) ;
if ( V_21 == NULL ) {
F_36 ( & V_83 ) ;
F_33 ( V_48 ) ;
return - V_27 ;
}
V_21 -> V_23 =
F_37 (
V_43 , 0 , L_5 , V_43 -> V_86 [ 0 ] ?
( const char * ) V_43 -> V_86 : L_6 ) ;
if ( V_21 -> V_23 < 0 ) {
F_33 ( V_21 ) ;
F_36 ( & V_83 ) ;
F_33 ( V_48 ) ;
return - V_27 ;
}
}
V_6 = F_38 ( V_72 , sizeof( struct V_5 ) , V_78 ) ;
V_18 = F_31 ( sizeof( * V_18 ) , V_78 ) ;
if ( V_6 == NULL || V_18 == NULL )
goto V_87;
for ( V_71 = 0 ; V_71 < V_72 ; V_71 ++ ) {
V_65 = & V_6 [ V_71 ] ;
if ( F_15 ( V_65 , V_43 , V_44 , V_71 ) < 0 )
goto V_87;
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
V_18 -> V_88 . V_21 = V_21 -> V_23 ;
V_18 -> V_88 . V_18 = V_44 * ( 256 / V_77 ) + V_71 ;
V_18 -> V_37 = V_89 ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_48 -> V_44 = V_44 ;
if ( V_71 < V_76 )
V_48 -> V_79 = V_80 ;
else
V_48 -> V_79 = V_82 ;
V_48 -> V_45 = V_71 ;
if ( F_32 ( V_43 , V_48 ) >= 0 )
strcpy ( V_18 -> V_90 , V_48 -> V_91 ) ;
if ( ! V_18 -> V_90 [ 0 ] ) {
if ( V_48 -> V_90 [ 0 ] ) {
if ( V_72 > 1 )
snprintf ( V_18 -> V_90 , sizeof( V_18 -> V_90 ) , L_7 , V_48 -> V_90 , V_71 ) ;
else
snprintf ( V_18 -> V_90 , sizeof( V_18 -> V_90 ) , L_5 , V_48 -> V_90 ) ;
} else {
if ( V_72 > 1 )
sprintf ( V_18 -> V_90 , L_8 , V_43 -> V_85 , V_44 , V_71 ) ;
else
sprintf ( V_18 -> V_90 , L_9 , V_43 -> V_85 , V_44 ) ;
}
}
if ( ( V_48 -> V_37 & V_92 ) && V_71 < V_76 )
V_18 -> V_93 |= V_94 | V_95 | V_96 ;
if ( ( V_48 -> V_37 & V_97 ) && V_71 < V_75 )
V_18 -> V_93 |= V_98 | V_99 | V_100 ;
if ( ( V_18 -> V_93 & ( V_94 | V_98 ) ) == ( V_94 | V_98 ) &&
V_48 -> V_37 & V_101 )
V_18 -> V_93 |= V_102 ;
V_18 -> type = V_103
| V_104
| V_105 ;
V_18 -> V_106 = 16 ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_107 = V_108 ;
V_74 . V_13 = V_65 ;
V_74 . V_109 = F_17 ;
V_74 . V_110 = F_22 ;
V_74 . V_111 = F_23 ;
V_74 . V_112 = F_25 ;
V_74 . V_113 = F_10 ;
V_18 -> V_114 = & V_74 ;
if ( V_69 -> V_115 && V_69 -> V_115 -> V_116 )
V_69 -> V_115 -> V_116 ( V_69 , V_71 , V_18 ) ;
if ( F_39 ( V_21 -> V_23 , V_117 , V_18 ) < 0 )
goto V_87;
V_65 -> V_23 = V_21 -> V_23 ;
V_65 -> V_19 = V_18 -> V_88 . V_18 ;
}
V_21 -> V_118 [ V_44 ] = V_72 ;
V_21 -> V_72 [ V_44 ] = V_6 ;
V_21 -> V_119 ++ ;
if ( V_70 )
V_84 [ V_43 -> V_85 ] = V_21 ;
F_36 ( & V_83 ) ;
F_33 ( V_48 ) ;
F_33 ( V_18 ) ;
return 0 ;
V_87:
if ( V_6 != NULL ) {
for ( V_71 = 0 ; V_71 < V_72 ; V_71 ++ )
F_27 ( & V_6 [ V_71 ] ) ;
F_33 ( V_6 ) ;
}
if ( V_70 ) {
F_40 ( V_21 -> V_23 ) ;
F_33 ( V_21 ) ;
}
F_33 ( V_48 ) ;
F_33 ( V_18 ) ;
F_36 ( & V_83 ) ;
return - V_27 ;
}
static int
F_41 ( struct V_62 * V_63 )
{
struct V_64 * V_21 ;
struct V_5 * V_6 ;
struct V_42 * V_43 = V_63 -> V_43 ;
int V_44 = V_63 -> V_44 , V_71 , V_72 ;
F_34 ( & V_83 ) ;
V_21 = V_84 [ V_43 -> V_85 ] ;
if ( V_21 == NULL || V_21 -> V_72 [ V_44 ] == NULL ) {
F_36 ( & V_83 ) ;
return - V_35 ;
}
V_72 = V_21 -> V_118 [ V_44 ] ;
V_21 -> V_118 [ V_44 ] = 0 ;
V_6 = V_21 -> V_72 [ V_44 ] ;
V_21 -> V_72 [ V_44 ] = NULL ;
for ( V_71 = 0 ; V_71 < V_72 ; V_71 ++ )
F_27 ( & V_6 [ V_71 ] ) ;
F_33 ( V_6 ) ;
V_21 -> V_119 -- ;
if ( V_21 -> V_119 <= 0 ) {
F_40 ( V_21 -> V_23 ) ;
V_84 [ V_43 -> V_85 ] = NULL ;
F_33 ( V_21 ) ;
}
F_36 ( & V_83 ) ;
return 0 ;
}
static int T_1 F_42 ( void )
{
static struct V_120 V_115 = {
F_30 ,
F_41 ,
} ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
F_43 () ;
F_44 ( V_121 , & V_115 , 0 ) ;
F_45 () ;
return 0 ;
}
static void T_2 F_46 ( void )
{
F_47 ( V_121 ) ;
}
