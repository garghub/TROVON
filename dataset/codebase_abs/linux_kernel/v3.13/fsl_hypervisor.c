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
V_23 = F_17 ( V_34 , V_34 -> V_35 ,
V_3 . V_29 - V_21 , V_20 ,
( V_3 . V_26 == - 1 ) ? V_37 : V_38 ,
0 , V_16 , NULL ) ;
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
V_19 [ 0 ] . V_39 = F_20 ( V_40 , V_3 . V_25 , V_30 - V_21 ) ;
V_24 = V_3 . V_24 + V_19 [ 0 ] . V_39 ;
V_25 = V_3 . V_25 - V_19 [ 0 ] . V_39 ;
for ( V_22 = 1 ; V_22 < V_20 ; V_22 ++ ) {
if ( V_3 . V_26 == - 1 ) {
V_19 [ V_22 ] . V_26 = F_19 ( V_16 [ V_22 ] ) ;
V_19 [ V_22 ] . V_27 = V_24 ;
} else {
V_19 [ V_22 ] . V_26 = V_24 ;
V_19 [ V_22 ] . V_27 = F_19 ( V_16 [ V_22 ] ) ;
}
V_19 [ V_22 ] . V_39 = F_20 ( V_40 , V_25 , V_30 ) ;
V_24 += V_19 [ V_22 ] . V_39 ;
V_25 -= V_19 [ V_22 ] . V_39 ;
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
static long F_25 ( struct V_41 T_1 * V_2 )
{
struct V_41 V_3 ;
if ( F_2 ( & V_3 , V_2 , sizeof( struct V_41 ) ) )
return - V_4 ;
V_3 . V_5 = F_26 ( V_3 . V_42 ) ;
if ( F_4 ( & V_2 -> V_5 , & V_3 . V_5 , sizeof( V_7 ) ) )
return - V_4 ;
return 0 ;
}
static long F_27 ( struct V_43 T_1 * V_2 , int V_44 )
{
struct V_43 V_3 ;
char T_1 * V_45 , * V_46 ;
void T_1 * V_47 ;
char * V_48 = NULL , * V_49 = NULL ;
void * V_50 = NULL ;
int V_5 = 0 ;
if ( F_2 ( & V_3 , V_2 , sizeof( struct V_43 ) ) )
return - V_4 ;
V_45 = ( char T_1 * ) ( V_51 ) V_3 . V_48 ;
V_46 = ( char T_1 * ) ( V_51 ) V_3 . V_49 ;
V_47 = ( void T_1 * ) ( V_51 ) V_3 . V_50 ;
V_48 = F_28 ( V_45 , V_52 ) ;
if ( F_29 ( V_48 ) ) {
V_5 = F_30 ( V_48 ) ;
goto V_53;
}
V_49 = F_28 ( V_46 , V_52 ) ;
if ( F_29 ( V_49 ) ) {
V_5 = F_30 ( V_49 ) ;
goto V_53;
}
if ( V_3 . V_54 > V_55 ) {
V_5 = - V_28 ;
goto V_53;
}
V_50 = F_14 ( V_3 . V_54 , V_32 ) ;
if ( ! V_50 ) {
V_5 = - V_33 ;
goto V_53;
}
if ( V_44 ) {
if ( F_2 ( V_50 , V_47 , V_3 . V_54 ) ) {
V_5 = - V_4 ;
goto V_53;
}
V_3 . V_5 = F_31 ( V_3 . V_56 ,
F_22 ( V_48 ) ,
F_22 ( V_49 ) ,
F_22 ( V_50 ) ,
V_3 . V_54 ) ;
} else {
V_3 . V_5 = F_32 ( V_3 . V_56 ,
F_22 ( V_48 ) ,
F_22 ( V_49 ) ,
F_22 ( V_50 ) ,
& V_3 . V_54 ) ;
if ( V_3 . V_5 == 0 ) {
if ( F_4 ( V_47 , V_50 , V_3 . V_54 ) ||
F_33 ( V_3 . V_54 , & V_2 -> V_54 ) ) {
V_5 = - V_4 ;
goto V_53;
}
}
}
if ( F_33 ( V_3 . V_5 , & V_2 -> V_5 ) )
V_5 = - V_4 ;
V_53:
F_24 ( V_48 ) ;
F_24 ( V_50 ) ;
F_24 ( V_49 ) ;
return V_5 ;
}
static long F_34 ( struct V_57 * V_57 , unsigned int V_58 ,
unsigned long V_59 )
{
void T_1 * V_60 = ( void T_1 * ) V_59 ;
long V_5 ;
switch ( V_58 ) {
case V_61 :
V_5 = F_1 ( V_60 ) ;
break;
case V_62 :
V_5 = F_5 ( V_60 ) ;
break;
case V_63 :
V_5 = F_7 ( V_60 ) ;
break;
case V_64 :
V_5 = F_9 ( V_60 ) ;
break;
case V_65 :
V_5 = F_11 ( V_60 ) ;
break;
case V_66 :
V_5 = F_25 ( V_60 ) ;
break;
case V_67 :
V_5 = F_27 ( V_60 , 0 ) ;
break;
case V_68 :
V_5 = F_27 ( V_60 , 1 ) ;
break;
default:
F_13 ( L_4 ,
F_35 ( V_58 ) , F_36 ( V_58 ) , F_37 ( V_58 ) ,
F_38 ( V_58 ) ) ;
return - V_69 ;
}
return V_5 ;
}
static void F_39 ( T_4 V_42 )
{
struct V_70 * V_71 ;
unsigned long V_72 ;
F_40 ( & V_73 , V_72 ) ;
F_41 (dbq, &db_list, list) {
if ( V_71 -> V_74 != F_42 ( V_71 -> V_75 ) ) {
V_71 -> V_76 [ V_71 -> V_75 ] = V_42 ;
F_43 () ;
V_71 -> V_75 = F_42 ( V_71 -> V_75 ) ;
F_44 ( & V_71 -> V_77 ) ;
}
}
F_45 ( & V_73 , V_72 ) ;
}
static T_5 F_46 ( int V_78 , void * V_79 )
{
F_39 ( ( V_51 ) V_79 ) ;
return V_80 ;
}
static T_5 F_47 ( int V_78 , void * V_79 )
{
struct V_81 * V_82 = V_79 ;
F_48 ( & V_83 , V_82 -> V_6 ,
NULL ) ;
return V_80 ;
}
static T_5 F_49 ( int V_78 , void * V_79 )
{
unsigned int V_9 ;
struct V_81 * V_82 = V_79 ;
int V_5 ;
F_39 ( V_82 -> V_42 ) ;
V_5 = F_6 ( V_82 -> V_6 , & V_9 ) ;
if ( ! V_5 && ( V_9 == V_84 ) )
return V_85 ;
return V_80 ;
}
static unsigned int F_50 ( struct V_57 * V_86 , struct V_87 * V_2 )
{
struct V_70 * V_71 = V_86 -> V_88 ;
unsigned long V_72 ;
unsigned int V_89 ;
F_40 ( & V_71 -> V_90 , V_72 ) ;
F_51 ( V_86 , & V_71 -> V_77 , V_2 ) ;
V_89 = ( V_71 -> V_74 == V_71 -> V_75 ) ? 0 : ( V_91 | V_92 ) ;
F_45 ( & V_71 -> V_90 , V_72 ) ;
return V_89 ;
}
static T_6 F_52 ( struct V_57 * V_86 , char T_1 * V_93 , T_7 V_94 ,
T_8 * V_95 )
{
struct V_70 * V_71 = V_86 -> V_88 ;
T_4 T_1 * V_2 = ( T_4 T_1 * ) V_93 ;
unsigned long V_72 ;
T_6 V_25 = 0 ;
while ( V_94 >= sizeof( T_4 ) ) {
T_4 V_96 ;
F_40 ( & V_71 -> V_90 , V_72 ) ;
if ( V_71 -> V_74 == V_71 -> V_75 ) {
F_45 ( & V_71 -> V_90 , V_72 ) ;
if ( V_25 )
break;
if ( V_86 -> V_97 & V_98 )
return - V_99 ;
if ( F_53 ( V_71 -> V_77 ,
V_71 -> V_74 != V_71 -> V_75 ) )
return - V_100 ;
continue;
}
F_54 () ;
V_96 = V_71 -> V_76 [ V_71 -> V_74 ] ;
V_71 -> V_74 = F_42 ( V_71 -> V_74 ) ;
F_45 ( & V_71 -> V_90 , V_72 ) ;
if ( F_33 ( V_96 , V_2 ) )
return - V_4 ;
V_2 ++ ;
V_25 += sizeof( T_4 ) ;
V_94 -= sizeof( T_4 ) ;
}
return V_25 ;
}
static int F_55 ( struct V_101 * V_101 , struct V_57 * V_86 )
{
struct V_70 * V_71 ;
unsigned long V_72 ;
int V_5 = 0 ;
V_71 = F_12 ( sizeof( struct V_70 ) , V_32 ) ;
if ( ! V_71 ) {
F_56 ( L_5 ) ;
return - V_33 ;
}
F_57 ( & V_71 -> V_90 ) ;
F_58 ( & V_71 -> V_77 ) ;
F_40 ( & V_73 , V_72 ) ;
F_59 ( & V_71 -> V_102 , & V_103 ) ;
F_45 ( & V_73 , V_72 ) ;
V_86 -> V_88 = V_71 ;
return V_5 ;
}
static int F_60 ( struct V_101 * V_101 , struct V_57 * V_86 )
{
struct V_70 * V_71 = V_86 -> V_88 ;
unsigned long V_72 ;
int V_5 = 0 ;
F_40 ( & V_73 , V_72 ) ;
F_61 ( & V_71 -> V_102 ) ;
F_45 ( & V_73 , V_72 ) ;
F_24 ( V_71 ) ;
return V_5 ;
}
static T_5 F_62 ( int V_78 , void * V_79 )
{
F_63 ( false ) ;
return V_80 ;
}
static int F_64 ( struct V_104 * V_105 )
{
struct V_104 * V_106 ;
const T_4 * V_107 ;
T_4 V_56 ;
int V_94 ;
V_106 = F_65 ( V_105 ) ;
if ( ! V_106 )
return - V_108 ;
V_107 = F_66 ( V_106 , L_6 , & V_94 ) ;
if ( ! V_107 )
V_107 = F_66 ( V_106 , L_7 , & V_94 ) ;
if ( ! V_107 || ( V_94 != sizeof( T_4 ) ) ) {
F_67 ( V_106 ) ;
return - V_108 ;
}
V_56 = F_68 ( V_107 ) ;
F_67 ( V_106 ) ;
return V_56 ;
}
int F_69 ( struct V_109 * V_110 )
{
return F_70 ( & V_83 , V_110 ) ;
}
int F_71 ( struct V_109 * V_110 )
{
return F_72 ( & V_83 , V_110 ) ;
}
static int F_73 ( void )
{
struct V_104 * V_111 ;
int V_5 ;
V_111 = F_74 ( L_8 ) ;
if ( ! V_111 )
return 0 ;
V_5 = F_75 ( V_111 , L_9 , NULL ) != NULL ;
F_67 ( V_111 ) ;
return V_5 ;
}
static int T_9 F_76 ( void )
{
struct V_104 * V_105 ;
struct V_81 * V_82 , * V_112 ;
int V_5 ;
F_77 ( L_10 ) ;
if ( ! F_73 () ) {
F_77 ( L_11 ) ;
return - V_108 ;
}
V_5 = F_78 ( & V_113 ) ;
if ( V_5 ) {
F_56 ( L_12 ) ;
return V_5 ;
}
F_79 ( & V_103 ) ;
F_79 ( & V_114 ) ;
F_80 (np, NULL, L_13 ) {
unsigned int V_78 ;
const T_4 * V_56 ;
V_56 = F_66 ( V_105 , L_14 , NULL ) ;
V_78 = F_81 ( V_105 , 0 ) ;
if ( ! V_56 || ( V_78 == V_115 ) ) {
F_56 ( L_15 ,
V_105 -> V_116 ) ;
continue;
}
V_82 = F_12 ( sizeof( * V_82 ) , V_32 ) ;
if ( ! V_82 )
goto V_117;
V_82 -> V_78 = V_78 ;
V_82 -> V_42 = F_68 ( V_56 ) ;
if ( F_82 ( V_105 , L_16 ) ) {
V_5 = F_83 ( V_78 , F_62 , 0 ,
V_105 -> V_118 , NULL ) ;
} else if ( F_82 ( V_105 ,
L_17 ) ) {
V_82 -> V_6 = V_5 = F_64 ( V_105 ) ;
if ( V_5 < 0 ) {
F_56 ( L_18
L_19 , V_105 -> V_116 ) ;
F_24 ( V_82 ) ;
continue;
}
V_5 = F_84 ( V_78 , F_49 ,
F_47 ,
0 , V_105 -> V_118 , V_82 ) ;
} else
V_5 = F_83 ( V_78 , F_46 , 0 , V_105 -> V_118 , V_82 ) ;
if ( V_5 < 0 ) {
F_56 ( L_20 ,
V_78 , V_105 -> V_116 ) ;
F_24 ( V_82 ) ;
continue;
}
F_59 ( & V_82 -> V_102 , & V_114 ) ;
F_77 ( L_21 ,
V_82 -> V_42 ) ;
}
return 0 ;
V_117:
F_85 (dbisr, n, &isr_list, list) {
F_86 ( V_82 -> V_78 , V_82 ) ;
F_61 ( & V_82 -> V_102 ) ;
F_24 ( V_82 ) ;
}
F_87 ( & V_113 ) ;
return - V_33 ;
}
static void T_10 F_88 ( void )
{
struct V_81 * V_82 , * V_112 ;
F_85 (dbisr, n, &isr_list, list) {
F_86 ( V_82 -> V_78 , V_82 ) ;
F_61 ( & V_82 -> V_102 ) ;
F_24 ( V_82 ) ;
}
F_87 ( & V_113 ) ;
}
