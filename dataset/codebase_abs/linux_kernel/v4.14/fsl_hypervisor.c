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
V_23 = F_16 ( V_3 . V_29 - V_21 ,
V_20 , V_16 , ( V_3 . V_26 == - 1 ) ? 0 : V_34 ) ;
if ( V_23 != V_20 ) {
F_13 ( L_3 ) ;
V_5 = ( V_23 < 0 ) ? V_23 : - V_4 ;
goto exit;
}
if ( V_3 . V_26 == - 1 ) {
V_19 [ 0 ] . V_26 = F_17 ( V_16 [ 0 ] ) + V_21 ;
V_19 [ 0 ] . V_27 = V_3 . V_24 ;
} else {
V_19 [ 0 ] . V_26 = V_3 . V_24 ;
V_19 [ 0 ] . V_27 = F_17 ( V_16 [ 0 ] ) + V_21 ;
}
V_19 [ 0 ] . V_35 = F_18 ( V_36 , V_3 . V_25 , V_30 - V_21 ) ;
V_24 = V_3 . V_24 + V_19 [ 0 ] . V_35 ;
V_25 = V_3 . V_25 - V_19 [ 0 ] . V_35 ;
for ( V_22 = 1 ; V_22 < V_20 ; V_22 ++ ) {
if ( V_3 . V_26 == - 1 ) {
V_19 [ V_22 ] . V_26 = F_17 ( V_16 [ V_22 ] ) ;
V_19 [ V_22 ] . V_27 = V_24 ;
} else {
V_19 [ V_22 ] . V_26 = V_24 ;
V_19 [ V_22 ] . V_27 = F_17 ( V_16 [ V_22 ] ) ;
}
V_19 [ V_22 ] . V_35 = F_18 ( V_36 , V_25 , V_30 ) ;
V_24 += V_19 [ V_22 ] . V_35 ;
V_25 -= V_19 [ V_22 ] . V_35 ;
}
V_3 . V_5 = F_19 ( V_3 . V_26 , V_3 . V_27 ,
F_20 ( V_19 ) , V_20 ) ;
exit:
if ( V_16 ) {
for ( V_22 = 0 ; V_22 < V_20 ; V_22 ++ )
if ( V_16 [ V_22 ] )
F_21 ( V_16 [ V_22 ] ) ;
}
F_22 ( V_17 ) ;
F_22 ( V_16 ) ;
if ( ! V_5 )
if ( F_4 ( & V_2 -> V_5 , & V_3 . V_5 , sizeof( V_7 ) ) )
return - V_4 ;
return V_5 ;
}
static long F_23 ( struct V_37 T_1 * V_2 )
{
struct V_37 V_3 ;
if ( F_2 ( & V_3 , V_2 , sizeof( struct V_37 ) ) )
return - V_4 ;
V_3 . V_5 = F_24 ( V_3 . V_38 ) ;
if ( F_4 ( & V_2 -> V_5 , & V_3 . V_5 , sizeof( V_7 ) ) )
return - V_4 ;
return 0 ;
}
static long F_25 ( struct V_39 T_1 * V_2 , int V_40 )
{
struct V_39 V_3 ;
char T_1 * V_41 , * V_42 ;
void T_1 * V_43 ;
char * V_44 = NULL , * V_45 = NULL ;
void * V_46 = NULL ;
int V_5 = 0 ;
if ( F_2 ( & V_3 , V_2 , sizeof( struct V_39 ) ) )
return - V_4 ;
V_41 = ( char T_1 * ) ( V_47 ) V_3 . V_44 ;
V_42 = ( char T_1 * ) ( V_47 ) V_3 . V_45 ;
V_43 = ( void T_1 * ) ( V_47 ) V_3 . V_46 ;
V_44 = F_26 ( V_41 , V_48 ) ;
if ( F_27 ( V_44 ) ) {
V_5 = F_28 ( V_44 ) ;
goto V_49;
}
V_45 = F_26 ( V_42 , V_48 ) ;
if ( F_27 ( V_45 ) ) {
V_5 = F_28 ( V_45 ) ;
goto V_49;
}
if ( V_3 . V_50 > V_51 ) {
V_5 = - V_28 ;
goto V_49;
}
V_46 = F_14 ( V_3 . V_50 , V_32 ) ;
if ( ! V_46 ) {
V_5 = - V_33 ;
goto V_49;
}
if ( V_40 ) {
if ( F_2 ( V_46 , V_43 , V_3 . V_50 ) ) {
V_5 = - V_4 ;
goto V_49;
}
V_3 . V_5 = F_29 ( V_3 . V_52 ,
F_20 ( V_44 ) ,
F_20 ( V_45 ) ,
F_20 ( V_46 ) ,
V_3 . V_50 ) ;
} else {
V_3 . V_5 = F_30 ( V_3 . V_52 ,
F_20 ( V_44 ) ,
F_20 ( V_45 ) ,
F_20 ( V_46 ) ,
& V_3 . V_50 ) ;
if ( V_3 . V_5 == 0 ) {
if ( F_4 ( V_43 , V_46 , V_3 . V_50 ) ||
F_31 ( V_3 . V_50 , & V_2 -> V_50 ) ) {
V_5 = - V_4 ;
goto V_49;
}
}
}
if ( F_31 ( V_3 . V_5 , & V_2 -> V_5 ) )
V_5 = - V_4 ;
V_49:
F_22 ( V_44 ) ;
F_22 ( V_46 ) ;
F_22 ( V_45 ) ;
return V_5 ;
}
static long F_32 ( struct V_53 * V_53 , unsigned int V_54 ,
unsigned long V_55 )
{
void T_1 * V_56 = ( void T_1 * ) V_55 ;
long V_5 ;
switch ( V_54 ) {
case V_57 :
V_5 = F_1 ( V_56 ) ;
break;
case V_58 :
V_5 = F_5 ( V_56 ) ;
break;
case V_59 :
V_5 = F_7 ( V_56 ) ;
break;
case V_60 :
V_5 = F_9 ( V_56 ) ;
break;
case V_61 :
V_5 = F_11 ( V_56 ) ;
break;
case V_62 :
V_5 = F_23 ( V_56 ) ;
break;
case V_63 :
V_5 = F_25 ( V_56 , 0 ) ;
break;
case V_64 :
V_5 = F_25 ( V_56 , 1 ) ;
break;
default:
F_13 ( L_4 ,
F_33 ( V_54 ) , F_34 ( V_54 ) , F_35 ( V_54 ) ,
F_36 ( V_54 ) ) ;
return - V_65 ;
}
return V_5 ;
}
static void F_37 ( T_4 V_38 )
{
struct V_66 * V_67 ;
unsigned long V_68 ;
F_38 ( & V_69 , V_68 ) ;
F_39 (dbq, &db_list, list) {
if ( V_67 -> V_70 != F_40 ( V_67 -> V_71 ) ) {
V_67 -> V_72 [ V_67 -> V_71 ] = V_38 ;
F_41 () ;
V_67 -> V_71 = F_40 ( V_67 -> V_71 ) ;
F_42 ( & V_67 -> V_73 ) ;
}
}
F_43 ( & V_69 , V_68 ) ;
}
static T_5 F_44 ( int V_74 , void * V_75 )
{
F_37 ( ( V_47 ) V_75 ) ;
return V_76 ;
}
static T_5 F_45 ( int V_74 , void * V_75 )
{
struct V_77 * V_78 = V_75 ;
F_46 ( & V_79 , V_78 -> V_6 ,
NULL ) ;
return V_76 ;
}
static T_5 F_47 ( int V_74 , void * V_75 )
{
unsigned int V_9 ;
struct V_77 * V_78 = V_75 ;
int V_5 ;
F_37 ( V_78 -> V_38 ) ;
V_5 = F_6 ( V_78 -> V_6 , & V_9 ) ;
if ( ! V_5 && ( V_9 == V_80 ) )
return V_81 ;
return V_76 ;
}
static unsigned int F_48 ( struct V_53 * V_82 , struct V_83 * V_2 )
{
struct V_66 * V_67 = V_82 -> V_84 ;
unsigned long V_68 ;
unsigned int V_85 ;
F_38 ( & V_67 -> V_86 , V_68 ) ;
F_49 ( V_82 , & V_67 -> V_73 , V_2 ) ;
V_85 = ( V_67 -> V_70 == V_67 -> V_71 ) ? 0 : ( V_87 | V_88 ) ;
F_43 ( & V_67 -> V_86 , V_68 ) ;
return V_85 ;
}
static T_6 F_50 ( struct V_53 * V_82 , char T_1 * V_89 , T_7 V_90 ,
T_8 * V_91 )
{
struct V_66 * V_67 = V_82 -> V_84 ;
T_4 T_1 * V_2 = ( T_4 T_1 * ) V_89 ;
unsigned long V_68 ;
T_6 V_25 = 0 ;
while ( V_90 >= sizeof( T_4 ) ) {
T_4 V_92 ;
F_38 ( & V_67 -> V_86 , V_68 ) ;
if ( V_67 -> V_70 == V_67 -> V_71 ) {
F_43 ( & V_67 -> V_86 , V_68 ) ;
if ( V_25 )
break;
if ( V_82 -> V_93 & V_94 )
return - V_95 ;
if ( F_51 ( V_67 -> V_73 ,
V_67 -> V_70 != V_67 -> V_71 ) )
return - V_96 ;
continue;
}
F_52 () ;
V_92 = V_67 -> V_72 [ V_67 -> V_70 ] ;
V_67 -> V_70 = F_40 ( V_67 -> V_70 ) ;
F_43 ( & V_67 -> V_86 , V_68 ) ;
if ( F_31 ( V_92 , V_2 ) )
return - V_4 ;
V_2 ++ ;
V_25 += sizeof( T_4 ) ;
V_90 -= sizeof( T_4 ) ;
}
return V_25 ;
}
static int F_53 ( struct V_97 * V_97 , struct V_53 * V_82 )
{
struct V_66 * V_67 ;
unsigned long V_68 ;
int V_5 = 0 ;
V_67 = F_12 ( sizeof( struct V_66 ) , V_32 ) ;
if ( ! V_67 ) {
F_54 ( L_5 ) ;
return - V_33 ;
}
F_55 ( & V_67 -> V_86 ) ;
F_56 ( & V_67 -> V_73 ) ;
F_38 ( & V_69 , V_68 ) ;
F_57 ( & V_67 -> V_98 , & V_99 ) ;
F_43 ( & V_69 , V_68 ) ;
V_82 -> V_84 = V_67 ;
return V_5 ;
}
static int F_58 ( struct V_97 * V_97 , struct V_53 * V_82 )
{
struct V_66 * V_67 = V_82 -> V_84 ;
unsigned long V_68 ;
int V_5 = 0 ;
F_38 ( & V_69 , V_68 ) ;
F_59 ( & V_67 -> V_98 ) ;
F_43 ( & V_69 , V_68 ) ;
F_22 ( V_67 ) ;
return V_5 ;
}
static T_5 F_60 ( int V_74 , void * V_75 )
{
F_61 ( false ) ;
return V_76 ;
}
static int F_62 ( struct V_100 * V_101 )
{
struct V_100 * V_102 ;
const T_4 * V_103 ;
T_4 V_52 ;
int V_90 ;
V_102 = F_63 ( V_101 ) ;
if ( ! V_102 )
return - V_104 ;
V_103 = F_64 ( V_102 , L_6 , & V_90 ) ;
if ( ! V_103 )
V_103 = F_64 ( V_102 , L_7 , & V_90 ) ;
if ( ! V_103 || ( V_90 != sizeof( T_4 ) ) ) {
F_65 ( V_102 ) ;
return - V_104 ;
}
V_52 = F_66 ( V_103 ) ;
F_65 ( V_102 ) ;
return V_52 ;
}
int F_67 ( struct V_105 * V_106 )
{
return F_68 ( & V_79 , V_106 ) ;
}
int F_69 ( struct V_105 * V_106 )
{
return F_70 ( & V_79 , V_106 ) ;
}
static int F_71 ( void )
{
struct V_100 * V_107 ;
int V_5 ;
V_107 = F_72 ( L_8 ) ;
if ( ! V_107 )
return 0 ;
V_5 = F_73 ( V_107 , L_9 , NULL ) != NULL ;
F_65 ( V_107 ) ;
return V_5 ;
}
static int T_9 F_74 ( void )
{
struct V_100 * V_101 ;
struct V_77 * V_78 , * V_108 ;
int V_5 ;
F_75 ( L_10 ) ;
if ( ! F_71 () ) {
F_75 ( L_11 ) ;
return - V_104 ;
}
V_5 = F_76 ( & V_109 ) ;
if ( V_5 ) {
F_54 ( L_12 ) ;
return V_5 ;
}
F_77 ( & V_99 ) ;
F_77 ( & V_110 ) ;
F_78 (np, NULL, L_13 ) {
unsigned int V_74 ;
const T_4 * V_52 ;
V_52 = F_64 ( V_101 , L_14 , NULL ) ;
V_74 = F_79 ( V_101 , 0 ) ;
if ( ! V_52 || ( V_74 == V_111 ) ) {
F_54 ( L_15 ,
V_101 ) ;
continue;
}
V_78 = F_12 ( sizeof( * V_78 ) , V_32 ) ;
if ( ! V_78 )
goto V_112;
V_78 -> V_74 = V_74 ;
V_78 -> V_38 = F_66 ( V_52 ) ;
if ( F_80 ( V_101 , L_16 ) ) {
V_5 = F_81 ( V_74 , F_60 , 0 ,
V_101 -> V_113 , NULL ) ;
} else if ( F_80 ( V_101 ,
L_17 ) ) {
V_78 -> V_6 = V_5 = F_62 ( V_101 ) ;
if ( V_5 < 0 ) {
F_54 ( L_18
L_19 , V_101 ) ;
F_22 ( V_78 ) ;
continue;
}
V_5 = F_82 ( V_74 , F_47 ,
F_45 ,
0 , V_101 -> V_113 , V_78 ) ;
} else
V_5 = F_81 ( V_74 , F_44 , 0 , V_101 -> V_113 , V_78 ) ;
if ( V_5 < 0 ) {
F_54 ( L_20 ,
V_74 , V_101 ) ;
F_22 ( V_78 ) ;
continue;
}
F_57 ( & V_78 -> V_98 , & V_110 ) ;
F_75 ( L_21 ,
V_78 -> V_38 ) ;
}
return 0 ;
V_112:
F_83 (dbisr, n, &isr_list, list) {
F_84 ( V_78 -> V_74 , V_78 ) ;
F_59 ( & V_78 -> V_98 ) ;
F_22 ( V_78 ) ;
}
F_85 ( & V_109 ) ;
return - V_33 ;
}
static void T_10 F_86 ( void )
{
struct V_77 * V_78 , * V_108 ;
F_83 (dbisr, n, &isr_list, list) {
F_84 ( V_78 -> V_74 , V_78 ) ;
F_59 ( & V_78 -> V_98 ) ;
F_22 ( V_78 ) ;
}
F_85 ( & V_109 ) ;
}
