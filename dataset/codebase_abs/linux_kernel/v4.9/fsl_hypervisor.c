static long F_1 ( struct V_1 T_1 * V_2 )
{
struct V_1 V_3 ;
if ( F_2 ( & V_3 , V_2 , sizeof( struct V_1 ) ) )
return - V_4 ;
V_3 . V_5 = F_3 ( V_3 . V_6 ) ;
if ( F_4 ( & V_2 -> V_5 , & V_3 . V_5 , sizeof( V_7 ) ) )
return - V_4 ;
return 0 ;
}
static long F_5 ( struct V_8 T_1 * V_2 )
{
struct V_8 V_3 ;
T_2 V_9 ;
if ( F_2 ( & V_3 , V_2 , sizeof( struct V_8 ) ) )
return - V_4 ;
V_3 . V_5 = F_6 ( V_3 . V_6 , & V_9 ) ;
if ( ! V_3 . V_5 )
V_3 . V_9 = V_9 ;
if ( F_4 ( V_2 , & V_3 , sizeof( struct V_8 ) ) )
return - V_4 ;
return 0 ;
}
static long F_7 ( struct V_10 T_1 * V_2 )
{
struct V_10 V_3 ;
if ( F_2 ( & V_3 , V_2 , sizeof( struct V_10 ) ) )
return - V_4 ;
V_3 . V_5 = F_8 ( V_3 . V_6 , V_3 . V_11 ,
V_3 . V_12 ) ;
if ( F_4 ( & V_2 -> V_5 , & V_3 . V_5 , sizeof( V_7 ) ) )
return - V_4 ;
return 0 ;
}
static long F_9 ( struct V_13 T_1 * V_2 )
{
struct V_13 V_3 ;
if ( F_2 ( & V_3 , V_2 , sizeof( struct V_13 ) ) )
return - V_4 ;
V_3 . V_5 = F_10 ( V_3 . V_6 ) ;
if ( F_4 ( & V_2 -> V_5 , & V_3 . V_5 , sizeof( V_7 ) ) )
return - V_4 ;
return 0 ;
}
static long F_11 ( struct V_14 T_1 * V_2 )
{
struct V_14 V_3 ;
struct V_15 * * V_16 = NULL ;
void * V_17 = NULL ;
struct V_18 * V_19 = NULL ;
unsigned int V_20 ;
unsigned long V_21 ;
unsigned int V_22 ;
long V_5 = 0 ;
int V_23 ;
T_3 V_24 ;
T_4 V_25 ;
if ( F_2 ( & V_3 , V_2 , sizeof( struct V_14 ) ) )
return - V_4 ;
if ( ( V_3 . V_26 == - 1 ) == ( V_3 . V_27 == - 1 ) )
return - V_28 ;
V_21 = V_3 . V_29 & ( V_30 - 1 ) ;
V_20 = ( V_3 . V_25 + V_21 + V_30 - 1 ) >> V_31 ;
V_16 = F_12 ( V_20 * sizeof( struct V_15 * ) , V_32 ) ;
if ( ! V_16 ) {
F_13 ( L_1 ) ;
return - V_33 ;
}
V_17 = F_14 ( V_20 * sizeof( struct V_18 ) +
sizeof( struct V_18 ) - 1 , V_32 ) ;
if ( ! V_17 ) {
F_13 ( L_2 ) ;
V_5 = - V_33 ;
goto exit;
}
V_19 = F_15 ( V_17 , sizeof( struct V_18 ) ) ;
F_16 ( & V_34 -> V_35 -> V_36 ) ;
V_23 = F_17 ( V_3 . V_29 - V_21 ,
V_20 , ( V_3 . V_26 == - 1 ) ? 0 : V_37 ,
V_16 , NULL ) ;
F_18 ( & V_34 -> V_35 -> V_36 ) ;
if ( V_23 != V_20 ) {
F_13 ( L_3 ) ;
V_5 = ( V_23 < 0 ) ? V_23 : - V_4 ;
goto exit;
}
if ( V_3 . V_26 == - 1 ) {
V_19 [ 0 ] . V_26 = F_19 ( V_16 [ 0 ] ) + V_21 ;
V_19 [ 0 ] . V_27 = V_3 . V_24 ;
} else {
V_19 [ 0 ] . V_26 = V_3 . V_24 ;
V_19 [ 0 ] . V_27 = F_19 ( V_16 [ 0 ] ) + V_21 ;
}
V_19 [ 0 ] . V_38 = F_20 ( V_39 , V_3 . V_25 , V_30 - V_21 ) ;
V_24 = V_3 . V_24 + V_19 [ 0 ] . V_38 ;
V_25 = V_3 . V_25 - V_19 [ 0 ] . V_38 ;
for ( V_22 = 1 ; V_22 < V_20 ; V_22 ++ ) {
if ( V_3 . V_26 == - 1 ) {
V_19 [ V_22 ] . V_26 = F_19 ( V_16 [ V_22 ] ) ;
V_19 [ V_22 ] . V_27 = V_24 ;
} else {
V_19 [ V_22 ] . V_26 = V_24 ;
V_19 [ V_22 ] . V_27 = F_19 ( V_16 [ V_22 ] ) ;
}
V_19 [ V_22 ] . V_38 = F_20 ( V_39 , V_25 , V_30 ) ;
V_24 += V_19 [ V_22 ] . V_38 ;
V_25 -= V_19 [ V_22 ] . V_38 ;
}
V_3 . V_5 = F_21 ( V_3 . V_26 , V_3 . V_27 ,
F_22 ( V_19 ) , V_20 ) ;
exit:
if ( V_16 ) {
for ( V_22 = 0 ; V_22 < V_20 ; V_22 ++ )
if ( V_16 [ V_22 ] )
F_23 ( V_16 [ V_22 ] ) ;
}
F_24 ( V_17 ) ;
F_24 ( V_16 ) ;
if ( ! V_5 )
if ( F_4 ( & V_2 -> V_5 , & V_3 . V_5 , sizeof( V_7 ) ) )
return - V_4 ;
return V_5 ;
}
static long F_25 ( struct V_40 T_1 * V_2 )
{
struct V_40 V_3 ;
if ( F_2 ( & V_3 , V_2 , sizeof( struct V_40 ) ) )
return - V_4 ;
V_3 . V_5 = F_26 ( V_3 . V_41 ) ;
if ( F_4 ( & V_2 -> V_5 , & V_3 . V_5 , sizeof( V_7 ) ) )
return - V_4 ;
return 0 ;
}
static long F_27 ( struct V_42 T_1 * V_2 , int V_43 )
{
struct V_42 V_3 ;
char T_1 * V_44 , * V_45 ;
void T_1 * V_46 ;
char * V_47 = NULL , * V_48 = NULL ;
void * V_49 = NULL ;
int V_5 = 0 ;
if ( F_2 ( & V_3 , V_2 , sizeof( struct V_42 ) ) )
return - V_4 ;
V_44 = ( char T_1 * ) ( V_50 ) V_3 . V_47 ;
V_45 = ( char T_1 * ) ( V_50 ) V_3 . V_48 ;
V_46 = ( void T_1 * ) ( V_50 ) V_3 . V_49 ;
V_47 = F_28 ( V_44 , V_51 ) ;
if ( F_29 ( V_47 ) ) {
V_5 = F_30 ( V_47 ) ;
goto V_52;
}
V_48 = F_28 ( V_45 , V_51 ) ;
if ( F_29 ( V_48 ) ) {
V_5 = F_30 ( V_48 ) ;
goto V_52;
}
if ( V_3 . V_53 > V_54 ) {
V_5 = - V_28 ;
goto V_52;
}
V_49 = F_14 ( V_3 . V_53 , V_32 ) ;
if ( ! V_49 ) {
V_5 = - V_33 ;
goto V_52;
}
if ( V_43 ) {
if ( F_2 ( V_49 , V_46 , V_3 . V_53 ) ) {
V_5 = - V_4 ;
goto V_52;
}
V_3 . V_5 = F_31 ( V_3 . V_55 ,
F_22 ( V_47 ) ,
F_22 ( V_48 ) ,
F_22 ( V_49 ) ,
V_3 . V_53 ) ;
} else {
V_3 . V_5 = F_32 ( V_3 . V_55 ,
F_22 ( V_47 ) ,
F_22 ( V_48 ) ,
F_22 ( V_49 ) ,
& V_3 . V_53 ) ;
if ( V_3 . V_5 == 0 ) {
if ( F_4 ( V_46 , V_49 , V_3 . V_53 ) ||
F_33 ( V_3 . V_53 , & V_2 -> V_53 ) ) {
V_5 = - V_4 ;
goto V_52;
}
}
}
if ( F_33 ( V_3 . V_5 , & V_2 -> V_5 ) )
V_5 = - V_4 ;
V_52:
F_24 ( V_47 ) ;
F_24 ( V_49 ) ;
F_24 ( V_48 ) ;
return V_5 ;
}
static long F_34 ( struct V_56 * V_56 , unsigned int V_57 ,
unsigned long V_58 )
{
void T_1 * V_59 = ( void T_1 * ) V_58 ;
long V_5 ;
switch ( V_57 ) {
case V_60 :
V_5 = F_1 ( V_59 ) ;
break;
case V_61 :
V_5 = F_5 ( V_59 ) ;
break;
case V_62 :
V_5 = F_7 ( V_59 ) ;
break;
case V_63 :
V_5 = F_9 ( V_59 ) ;
break;
case V_64 :
V_5 = F_11 ( V_59 ) ;
break;
case V_65 :
V_5 = F_25 ( V_59 ) ;
break;
case V_66 :
V_5 = F_27 ( V_59 , 0 ) ;
break;
case V_67 :
V_5 = F_27 ( V_59 , 1 ) ;
break;
default:
F_13 ( L_4 ,
F_35 ( V_57 ) , F_36 ( V_57 ) , F_37 ( V_57 ) ,
F_38 ( V_57 ) ) ;
return - V_68 ;
}
return V_5 ;
}
static void F_39 ( T_4 V_41 )
{
struct V_69 * V_70 ;
unsigned long V_71 ;
F_40 ( & V_72 , V_71 ) ;
F_41 (dbq, &db_list, list) {
if ( V_70 -> V_73 != F_42 ( V_70 -> V_74 ) ) {
V_70 -> V_75 [ V_70 -> V_74 ] = V_41 ;
F_43 () ;
V_70 -> V_74 = F_42 ( V_70 -> V_74 ) ;
F_44 ( & V_70 -> V_76 ) ;
}
}
F_45 ( & V_72 , V_71 ) ;
}
static T_5 F_46 ( int V_77 , void * V_78 )
{
F_39 ( ( V_50 ) V_78 ) ;
return V_79 ;
}
static T_5 F_47 ( int V_77 , void * V_78 )
{
struct V_80 * V_81 = V_78 ;
F_48 ( & V_82 , V_81 -> V_6 ,
NULL ) ;
return V_79 ;
}
static T_5 F_49 ( int V_77 , void * V_78 )
{
unsigned int V_9 ;
struct V_80 * V_81 = V_78 ;
int V_5 ;
F_39 ( V_81 -> V_41 ) ;
V_5 = F_6 ( V_81 -> V_6 , & V_9 ) ;
if ( ! V_5 && ( V_9 == V_83 ) )
return V_84 ;
return V_79 ;
}
static unsigned int F_50 ( struct V_56 * V_85 , struct V_86 * V_2 )
{
struct V_69 * V_70 = V_85 -> V_87 ;
unsigned long V_71 ;
unsigned int V_88 ;
F_40 ( & V_70 -> V_89 , V_71 ) ;
F_51 ( V_85 , & V_70 -> V_76 , V_2 ) ;
V_88 = ( V_70 -> V_73 == V_70 -> V_74 ) ? 0 : ( V_90 | V_91 ) ;
F_45 ( & V_70 -> V_89 , V_71 ) ;
return V_88 ;
}
static T_6 F_52 ( struct V_56 * V_85 , char T_1 * V_92 , T_7 V_93 ,
T_8 * V_94 )
{
struct V_69 * V_70 = V_85 -> V_87 ;
T_4 T_1 * V_2 = ( T_4 T_1 * ) V_92 ;
unsigned long V_71 ;
T_6 V_25 = 0 ;
while ( V_93 >= sizeof( T_4 ) ) {
T_4 V_95 ;
F_40 ( & V_70 -> V_89 , V_71 ) ;
if ( V_70 -> V_73 == V_70 -> V_74 ) {
F_45 ( & V_70 -> V_89 , V_71 ) ;
if ( V_25 )
break;
if ( V_85 -> V_96 & V_97 )
return - V_98 ;
if ( F_53 ( V_70 -> V_76 ,
V_70 -> V_73 != V_70 -> V_74 ) )
return - V_99 ;
continue;
}
F_54 () ;
V_95 = V_70 -> V_75 [ V_70 -> V_73 ] ;
V_70 -> V_73 = F_42 ( V_70 -> V_73 ) ;
F_45 ( & V_70 -> V_89 , V_71 ) ;
if ( F_33 ( V_95 , V_2 ) )
return - V_4 ;
V_2 ++ ;
V_25 += sizeof( T_4 ) ;
V_93 -= sizeof( T_4 ) ;
}
return V_25 ;
}
static int F_55 ( struct V_100 * V_100 , struct V_56 * V_85 )
{
struct V_69 * V_70 ;
unsigned long V_71 ;
int V_5 = 0 ;
V_70 = F_12 ( sizeof( struct V_69 ) , V_32 ) ;
if ( ! V_70 ) {
F_56 ( L_5 ) ;
return - V_33 ;
}
F_57 ( & V_70 -> V_89 ) ;
F_58 ( & V_70 -> V_76 ) ;
F_40 ( & V_72 , V_71 ) ;
F_59 ( & V_70 -> V_101 , & V_102 ) ;
F_45 ( & V_72 , V_71 ) ;
V_85 -> V_87 = V_70 ;
return V_5 ;
}
static int F_60 ( struct V_100 * V_100 , struct V_56 * V_85 )
{
struct V_69 * V_70 = V_85 -> V_87 ;
unsigned long V_71 ;
int V_5 = 0 ;
F_40 ( & V_72 , V_71 ) ;
F_61 ( & V_70 -> V_101 ) ;
F_45 ( & V_72 , V_71 ) ;
F_24 ( V_70 ) ;
return V_5 ;
}
static T_5 F_62 ( int V_77 , void * V_78 )
{
F_63 ( false ) ;
return V_79 ;
}
static int F_64 ( struct V_103 * V_104 )
{
struct V_103 * V_105 ;
const T_4 * V_106 ;
T_4 V_55 ;
int V_93 ;
V_105 = F_65 ( V_104 ) ;
if ( ! V_105 )
return - V_107 ;
V_106 = F_66 ( V_105 , L_6 , & V_93 ) ;
if ( ! V_106 )
V_106 = F_66 ( V_105 , L_7 , & V_93 ) ;
if ( ! V_106 || ( V_93 != sizeof( T_4 ) ) ) {
F_67 ( V_105 ) ;
return - V_107 ;
}
V_55 = F_68 ( V_106 ) ;
F_67 ( V_105 ) ;
return V_55 ;
}
int F_69 ( struct V_108 * V_109 )
{
return F_70 ( & V_82 , V_109 ) ;
}
int F_71 ( struct V_108 * V_109 )
{
return F_72 ( & V_82 , V_109 ) ;
}
static int F_73 ( void )
{
struct V_103 * V_110 ;
int V_5 ;
V_110 = F_74 ( L_8 ) ;
if ( ! V_110 )
return 0 ;
V_5 = F_75 ( V_110 , L_9 , NULL ) != NULL ;
F_67 ( V_110 ) ;
return V_5 ;
}
static int T_9 F_76 ( void )
{
struct V_103 * V_104 ;
struct V_80 * V_81 , * V_111 ;
int V_5 ;
F_77 ( L_10 ) ;
if ( ! F_73 () ) {
F_77 ( L_11 ) ;
return - V_107 ;
}
V_5 = F_78 ( & V_112 ) ;
if ( V_5 ) {
F_56 ( L_12 ) ;
return V_5 ;
}
F_79 ( & V_102 ) ;
F_79 ( & V_113 ) ;
F_80 (np, NULL, L_13 ) {
unsigned int V_77 ;
const T_4 * V_55 ;
V_55 = F_66 ( V_104 , L_14 , NULL ) ;
V_77 = F_81 ( V_104 , 0 ) ;
if ( ! V_55 || ( V_77 == V_114 ) ) {
F_56 ( L_15 ,
V_104 -> V_115 ) ;
continue;
}
V_81 = F_12 ( sizeof( * V_81 ) , V_32 ) ;
if ( ! V_81 )
goto V_116;
V_81 -> V_77 = V_77 ;
V_81 -> V_41 = F_68 ( V_55 ) ;
if ( F_82 ( V_104 , L_16 ) ) {
V_5 = F_83 ( V_77 , F_62 , 0 ,
V_104 -> V_117 , NULL ) ;
} else if ( F_82 ( V_104 ,
L_17 ) ) {
V_81 -> V_6 = V_5 = F_64 ( V_104 ) ;
if ( V_5 < 0 ) {
F_56 ( L_18
L_19 , V_104 -> V_115 ) ;
F_24 ( V_81 ) ;
continue;
}
V_5 = F_84 ( V_77 , F_49 ,
F_47 ,
0 , V_104 -> V_117 , V_81 ) ;
} else
V_5 = F_83 ( V_77 , F_46 , 0 , V_104 -> V_117 , V_81 ) ;
if ( V_5 < 0 ) {
F_56 ( L_20 ,
V_77 , V_104 -> V_115 ) ;
F_24 ( V_81 ) ;
continue;
}
F_59 ( & V_81 -> V_101 , & V_113 ) ;
F_77 ( L_21 ,
V_81 -> V_41 ) ;
}
return 0 ;
V_116:
F_85 (dbisr, n, &isr_list, list) {
F_86 ( V_81 -> V_77 , V_81 ) ;
F_61 ( & V_81 -> V_101 ) ;
F_24 ( V_81 ) ;
}
F_87 ( & V_112 ) ;
return - V_33 ;
}
static void T_10 F_88 ( void )
{
struct V_80 * V_81 , * V_111 ;
F_85 (dbisr, n, &isr_list, list) {
F_86 ( V_81 -> V_77 , V_81 ) ;
F_61 ( & V_81 -> V_101 ) ;
F_24 ( V_81 ) ;
}
F_87 ( & V_112 ) ;
}
