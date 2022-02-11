int F_1 ( void * V_1 , unsigned long V_2 , T_1 V_3 , int V_4 )
{
int V_5 , V_6 ;
static char V_7 [ V_8 ] V_9 ( ( F_2 ( V_8 ) ) ) ;
if ( ! V_10 )
return - V_11 ;
if ( V_3 == 0 )
return 0 ;
V_5 = 0 ;
if ( ( V_2 % V_8 ) != 0 ) {
V_6 = V_2 / V_8 + 2 ;
if ( F_3 ( V_7 , V_6 , 1 ) ) {
F_4 ( L_1 ) ;
return - V_12 ;
}
V_5 = F_5 ( ( V_8 - ( V_2 % V_8 ) ) , V_3 ) ;
if ( V_4 == V_13 ) {
if ( F_6 ( ( V_14 V_15 void * ) V_1 ,
V_7 + ( V_2 % V_8 ) , V_5 ) )
return - V_16 ;
} else
memcpy ( V_1 , V_7 + ( V_2 % V_8 ) , V_5 ) ;
}
if ( V_5 == V_3 )
goto V_17;
for (; ( V_5 + V_8 ) <= V_3 ; V_5 += V_8 ) {
V_6 = ( V_2 + V_5 ) / V_8 + 2 ;
if ( F_3 ( V_7 , V_6 , 1 ) ) {
F_4 ( L_1 ) ;
return - V_12 ;
}
if ( V_4 == V_13 ) {
if ( F_6 ( ( V_14 V_15 void * ) V_1 + V_5 ,
V_7 , V_8 ) )
return - V_16 ;
} else
memcpy ( V_1 + V_5 , V_7 , V_8 ) ;
}
if ( V_5 == V_3 )
goto V_17;
V_6 = ( V_2 + V_5 ) / V_8 + 2 ;
if ( F_3 ( V_7 , V_6 , 1 ) ) {
F_4 ( L_1 ) ;
return - V_12 ;
}
if ( V_4 == V_13 ) {
if ( F_6 ( ( V_14 V_15 void * ) V_1 + V_5 , V_7 ,
V_3 - V_5 ) )
return - V_16 ;
} else
memcpy ( V_1 + V_5 , V_7 , V_3 - V_5 ) ;
V_17:
return 0 ;
}
static int F_7 ( void V_15 * V_1 , unsigned long V_2 , T_1 V_3 )
{
return F_1 ( ( void V_14 * ) V_1 , V_2 , V_3 , V_13 ) ;
}
static int F_8 ( void * V_1 , unsigned long V_2 , T_1 V_3 )
{
return F_1 ( V_1 , V_2 , V_3 , V_18 ) ;
}
static int T_2 F_9 ( enum V_19 V_20 )
{
struct V_21 * V_22 ;
V_22 = V_23 . V_24 [ 0 ] ;
if ( ! V_22 )
return - V_25 ;
if ( F_8 ( & V_22 -> V_26 , V_27 . V_28 ,
V_27 . V_29 ) < 0 ) {
F_4 ( L_2 ) ;
F_10 ( V_22 ) ;
return - V_12 ;
}
if ( V_30 )
F_11 ( V_22 -> V_31 ) ;
return 0 ;
}
static int F_12 ( void V_15 * V_7 , void * V_26 , int V_32 , int V_33 )
{
int V_34 ;
char * V_35 = ( char * ) & V_27 . V_35 ;
for ( V_34 = 0 ; V_34 < V_33 ; V_34 ++ ) {
if ( ! V_35 [ V_34 + V_32 ] )
continue;
if ( F_6 ( V_7 + V_34 , V_26 + V_32 + V_34 , 1 ) )
return - V_16 ;
}
return 0 ;
}
static int F_13 ( char V_15 * V_7 , unsigned long V_36 , T_1 V_3 )
{
unsigned long V_37 ;
int V_34 ;
if ( V_3 == 0 )
return 0 ;
V_37 = V_36 + V_3 ;
for ( V_34 = 0 ; V_34 < V_23 . V_3 ; V_34 ++ ) {
unsigned long V_38 , V_39 ;
unsigned long V_40 , V_41 ;
unsigned long V_42 ;
unsigned long V_32 , V_33 , V_43 ;
struct V_44 * V_44 = & V_23 . V_24 [ V_34 ] -> V_26 ;
V_42 = V_44 -> V_45 ;
V_40 = V_42 + V_27 . V_28 ;
V_41 = V_42 + V_27 . V_28 + V_27 . V_29 ;
if ( ( V_37 < V_40 ) || ( V_36 > V_41 ) )
continue;
V_38 = F_14 ( V_36 , V_40 ) ;
V_39 = F_5 ( V_37 , V_41 ) ;
V_43 = V_38 - V_36 ;
V_32 = V_38 - V_40 ;
V_33 = V_39 - V_38 ;
F_4 ( L_3 , V_36 ) ;
if ( F_12 ( V_7 + V_43 , V_44 , V_32 , V_33 ) )
return - V_16 ;
}
return 0 ;
}
static void F_15 ( void )
{
F_16 ( V_46 , NULL ) ;
V_10 = 0 ;
}
static T_3 F_17 ( struct V_47 * V_47 , char V_15 * V_7 , T_1 V_3 ,
T_4 * V_48 )
{
unsigned long V_49 ;
T_1 V_50 ;
T_1 V_51 ;
T_1 V_52 ;
int V_53 ;
F_18 ( & V_54 ) ;
if ( * V_48 > ( V_27 . V_55 + V_56 ) ) {
V_53 = - V_57 ;
goto V_58;
}
V_3 = F_5 ( V_3 , ( T_1 ) ( V_27 . V_55 + V_56 - * V_48 ) ) ;
if ( * V_48 < V_56 ) {
V_52 = F_5 ( V_3 , ( T_1 ) ( V_56 - * V_48 ) ) ;
if ( F_6 ( V_7 , & V_59 + * V_48 , V_52 ) ) {
V_53 = - V_16 ;
goto V_58;
}
V_51 = V_52 ;
V_49 = 0 ;
} else {
V_51 = 0 ;
V_49 = * V_48 - V_56 ;
}
V_50 = 0 ;
if ( * V_48 < V_60 . V_61 + V_56 ) {
V_52 = F_5 ( ( V_3 - V_51 ) ,
( T_1 ) ( V_60 . V_61 - V_49 ) ) ;
V_53 = F_7 ( V_7 + V_51 , V_49 , V_52 ) ;
if ( V_53 )
goto V_58;
V_50 += V_52 ;
}
V_52 = V_3 - V_50 - V_51 ;
V_53 = F_19 ( V_7 + V_51 + V_50 ,
( void * ) V_49 + V_50 , V_52 ) ;
if ( V_53 )
goto V_58;
if ( F_13 ( V_7 + V_51 , V_49 , V_3 - V_51 ) ) {
V_53 = - V_16 ;
goto V_58;
}
* V_48 += V_3 ;
V_58:
F_20 ( & V_54 ) ;
return ( V_53 < 0 ) ? V_53 : V_3 ;
}
static int F_21 ( struct V_62 * V_62 , struct V_47 * V_63 )
{
if ( ! V_10 )
return - V_11 ;
else
return F_22 ( V_64 ) ? 0 : - V_65 ;
}
static int F_23 ( struct V_62 * V_62 , struct V_47 * V_66 )
{
if ( V_10 )
F_15 () ;
return 0 ;
}
static T_4 F_24 ( struct V_47 * V_47 , T_4 V_67 , int V_68 )
{
T_4 V_53 ;
F_18 ( & V_54 ) ;
switch ( V_68 ) {
case 0 :
V_47 -> V_69 = V_67 ;
V_53 = V_47 -> V_69 ;
break;
case 1 :
V_47 -> V_69 += V_67 ;
V_53 = V_47 -> V_69 ;
break;
default:
V_53 = - V_57 ;
}
F_20 ( & V_54 ) ;
return V_53 ;
}
static T_3 F_25 ( struct V_47 * V_63 , char V_15 * V_7 ,
T_1 V_3 , T_4 * V_48 )
{
return F_26 ( V_7 , V_3 , V_48 , V_63 -> V_70 ,
V_71 . V_72 . V_73 * V_74 ) ;
}
static int F_27 ( struct V_62 * V_62 , struct V_47 * V_63 )
{
struct V_75 * V_76 ;
char * V_7 ;
int V_34 = 0 ;
V_7 = F_28 ( V_71 . V_72 . V_73 * V_74 , V_77 ) ;
if ( ! V_7 ) {
return - V_25 ;
}
F_29 (memory, reg) {
sprintf ( V_7 + ( V_34 ++ * V_74 ) , L_4 ,
( unsigned long long ) V_76 -> V_78 ,
( unsigned long long ) V_76 -> V_52 ) ;
}
V_63 -> V_70 = V_7 ;
return F_30 ( V_62 , V_63 ) ;
}
static int F_31 ( struct V_62 * V_62 , struct V_47 * V_63 )
{
F_10 ( V_63 -> V_70 ) ;
return 0 ;
}
static T_3 F_32 ( struct V_47 * V_63 , const char V_15 * V_7 ,
T_1 V_3 , T_4 * V_48 )
{
if ( V_79 ) {
F_16 ( V_80 , V_79 ) ;
F_16 ( V_81 , NULL ) ;
}
return V_3 ;
}
static int F_33 ( struct V_62 * V_62 , struct V_47 * V_63 )
{
return F_30 ( V_62 , V_63 ) ;
}
static int F_34 ( struct V_62 * V_62 , struct V_47 * V_63 )
{
return 0 ;
}
static T_3 F_35 ( struct V_47 * V_63 , char V_15 * V_7 ,
T_1 V_3 , T_4 * V_48 )
{
static char V_82 [ 18 ] ;
if ( V_10 )
snprintf ( V_82 , sizeof( V_82 ) , L_5 , V_60 . V_61 ) ;
else
snprintf ( V_82 , sizeof( V_82 ) , L_6 ) ;
return F_26 ( V_7 , V_3 , V_48 , V_82 , strlen ( V_82 ) ) ;
}
static T_3 F_36 ( struct V_47 * V_63 , const char V_15 * V_7 ,
T_1 V_3 , T_4 * V_48 )
{
char V_83 ;
if ( * V_48 != 0 )
return - V_84 ;
if ( F_37 ( & V_83 , V_7 , 1 ) )
return - V_16 ;
if ( V_83 != '0' )
return - V_57 ;
F_15 () ;
return V_3 ;
}
static void T_2 F_38 ( struct V_44 * V_85 )
{
memset ( & V_85 -> V_86 , 0xff , sizeof( V_85 -> V_86 ) ) ;
memset ( & V_85 -> V_87 , 0xff , sizeof( V_85 -> V_87 ) ) ;
memset ( & V_85 -> V_88 , 0xff , sizeof( V_85 -> V_88 ) ) ;
memset ( & V_85 -> V_45 , 0xff , sizeof( V_85 -> V_45 ) ) ;
memset ( & V_85 -> V_89 , 0xff , sizeof( V_85 -> V_89 ) ) ;
memset ( & V_85 -> V_90 , 0xff , sizeof( V_85 -> V_90 ) ) ;
memset ( & V_85 -> V_91 , 0xff , sizeof( V_85 -> V_91 ) ) ;
memset ( & V_85 -> V_92 , 0xff , sizeof( V_85 -> V_92 ) ) ;
memset ( & V_85 -> V_93 , 0xff , sizeof( V_85 -> V_93 ) ) ;
memset ( & V_85 -> V_94 , 0xff , sizeof( V_85 -> V_94 ) ) ;
}
static int T_2 F_39 ( enum V_19 V_20 , unsigned long V_95 )
{
int V_53 ;
switch ( V_20 ) {
case V_96 :
F_40 ( L_7 ) ;
break;
case V_97 :
F_40 ( L_8 ) ;
break;
default:
F_40 ( L_9 , V_20 ) ;
return - V_57 ;
}
V_27 . V_28 = V_98 ;
V_27 . V_29 = sizeof( struct V_44 ) ;
V_27 . V_20 = V_20 ;
F_38 ( & V_27 . V_35 ) ;
V_53 = F_9 ( V_20 ) ;
if ( V_53 )
return V_53 ;
V_27 . V_55 = V_95 ;
return 0 ;
}
static int T_2 F_41 ( void )
{
if ( ! V_60 . V_61 ) {
F_4 ( L_10 ) ;
return - V_99 ;
}
return 0 ;
}
static int T_2 F_42 ( unsigned long * V_100 , unsigned long * V_37 )
{
struct V_75 * V_76 ;
F_29 (memory, reg) {
* V_100 += V_76 -> V_52 ;
* V_37 = F_43 (unsigned long, *end, reg->base + reg->size) ;
}
return 0 ;
}
static void T_2 F_44 ( int V_20 , struct V_59 * V_101 ,
unsigned long V_55 )
{
T_5 V_42 ;
int V_34 ;
if ( V_20 == V_96 )
V_101 -> V_19 = V_102 ;
else
V_101 -> V_19 = V_103 ;
V_101 -> V_55 = V_55 ;
V_101 -> V_104 = V_55 ;
V_101 -> V_95 = V_27 . V_55 ;
V_101 -> V_105 = V_55 / V_8 ;
V_101 -> V_106 = F_45 () ;
F_46 ( & V_101 -> V_107 ) ;
for ( V_34 = 0 ; V_34 < V_23 . V_3 ; V_34 ++ ) {
V_42 = V_23 . V_24 [ V_34 ] -> V_26 . V_45 ;
V_101 -> V_108 ++ ;
if ( ! V_42 )
continue;
V_101 -> V_109 [ V_101 -> V_110 ] = V_42 ;
V_101 -> V_110 ++ ;
}
}
static int T_2 F_47 ( void )
{
struct V_111 V_111 ;
int V_53 ;
V_53 = F_8 ( & V_111 , V_112 , sizeof( V_111 ) ) ;
if ( V_53 )
return V_53 ;
if ( V_111 . V_113 == 0 )
return 0 ;
V_79 = ( void * ) F_48 ( V_77 ) ;
if ( ! V_79 )
return - V_25 ;
if ( V_111 . V_113 < V_60 . V_61 )
V_53 = F_8 ( V_79 , V_111 . V_113 , V_8 ) ;
else
V_53 = F_49 ( V_79 , ( void * ) V_111 . V_113 , V_8 ) ;
if ( V_53 || F_50 ( V_79 , V_79 -> V_101 . V_33 , 0 ) !=
V_111 . V_114 ) {
F_4 ( L_11 ) ;
F_51 ( ( unsigned long ) V_79 ) ;
V_79 = NULL ;
}
return 0 ;
}
static int T_2 F_52 ( void )
{
unsigned long V_55 , V_95 ;
unsigned char V_20 ;
int V_53 ;
V_55 = V_95 = 0 ;
if ( V_115 . type != V_116 )
return - V_11 ;
if ( V_117 )
return - V_11 ;
V_118 = F_53 ( L_12 , 4 , 1 , 4 * sizeof( long ) ) ;
F_54 ( V_118 , & V_119 ) ;
F_55 ( V_118 , 6 ) ;
F_4 ( L_13 , V_115 . V_120 . V_121 . V_122 . V_123 ) ;
F_4 ( L_14 , ( unsigned long long ) V_115 . V_120 . V_121 . V_124 ) ;
F_4 ( L_15 , ( unsigned long long ) V_115 . V_120 . V_121 . V_125 ) ;
V_53 = F_56 () ;
if ( V_53 )
goto V_58;
V_53 = F_41 () ;
if ( V_53 )
goto V_58;
V_10 = 1 ;
V_53 = F_8 ( & V_20 , V_126 , 1 ) ;
if ( V_53 )
goto V_58;
if ( V_20 == V_97 ) {
F_40 ( L_16
L_17 ) ;
V_53 = - V_57 ;
goto V_58;
}
V_53 = F_42 ( & V_55 , & V_95 ) ;
if ( V_53 )
goto V_58;
V_53 = F_39 ( V_20 , V_95 ) ;
if ( V_53 )
goto V_58;
F_44 ( V_20 , & V_59 , V_55 ) ;
V_53 = F_47 () ;
if ( V_53 )
goto V_58;
V_127 = F_57 ( L_12 , NULL ) ;
if ( ! V_127 ) {
V_53 = - V_25 ;
goto V_58;
}
V_128 = F_58 ( L_18 , V_129 , V_127 , NULL ,
& V_130 ) ;
if ( ! V_128 ) {
V_53 = - V_25 ;
goto V_131;
}
V_132 = F_58 ( L_19 , V_129 , V_127 ,
NULL , & V_133 ) ;
if ( ! V_132 ) {
V_53 = - V_25 ;
goto V_134;
}
V_135 = F_58 ( L_20 , V_129 , V_127 ,
NULL , & V_136 ) ;
if ( ! V_135 ) {
V_53 = - V_25 ;
goto V_137;
}
V_138 = F_58 ( L_21 , V_129 | V_139 , V_127 ,
NULL , & V_140 ) ;
if ( ! V_138 ) {
V_53 = - V_25 ;
goto V_141;
}
return 0 ;
V_141:
F_59 ( V_135 ) ;
V_137:
F_59 ( V_132 ) ;
V_134:
F_59 ( V_128 ) ;
V_131:
F_59 ( V_127 ) ;
V_58:
F_16 ( V_46 , NULL ) ;
return V_53 ;
}
static void T_6 F_60 ( void )
{
F_61 ( V_118 ) ;
F_62 () ;
F_51 ( ( unsigned long ) V_79 ) ;
F_59 ( V_138 ) ;
F_59 ( V_135 ) ;
F_59 ( V_132 ) ;
F_59 ( V_128 ) ;
F_59 ( V_127 ) ;
F_16 ( V_46 , NULL ) ;
}
