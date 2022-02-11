static int F_1 ( void * V_1 , unsigned long V_2 , T_1 V_3 , int V_4 )
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
V_22 = F_10 ( sizeof( * V_22 ) , V_23 ) ;
if ( ! V_22 )
return - V_24 ;
if ( F_8 ( V_22 , V_25 . V_26 , V_25 . V_27 ) < 0 ) {
F_4 ( L_2 ) ;
F_11 ( V_22 ) ;
return - V_12 ;
}
V_28 [ 0 ] = V_22 ;
return 0 ;
}
static int F_12 ( void V_15 * V_7 , void * V_22 , int V_29 , int V_30 )
{
int V_31 ;
char * V_32 = ( char * ) & V_25 . V_32 ;
for ( V_31 = 0 ; V_31 < V_30 ; V_31 ++ ) {
if ( ! V_32 [ V_31 + V_29 ] )
continue;
if ( F_6 ( V_7 + V_31 , V_22 + V_29 + V_31 , 1 ) )
return - V_16 ;
}
return 0 ;
}
static int F_13 ( char V_15 * V_7 , unsigned long V_33 , T_1 V_3 )
{
unsigned long V_34 ;
int V_31 = 0 ;
if ( V_3 == 0 )
return 0 ;
V_34 = V_33 + V_3 ;
while ( V_28 [ V_31 ] ) {
unsigned long V_35 , V_36 ;
unsigned long V_37 , V_38 ;
unsigned long V_39 ;
unsigned long V_29 , V_30 , V_40 ;
V_39 = V_28 [ V_31 ] -> V_41 ;
V_37 = V_39 + V_25 . V_26 ;
V_38 = V_39 + V_25 . V_26 + V_25 . V_27 ;
if ( ( V_34 < V_37 ) || ( V_33 > V_38 ) )
goto V_42;
V_35 = F_14 ( V_33 , V_37 ) ;
V_36 = F_5 ( V_34 , V_38 ) ;
V_40 = V_35 - V_33 ;
V_29 = V_35 - V_37 ;
V_30 = V_36 - V_35 ;
F_4 ( L_3 , V_33 ) ;
if ( F_12 ( V_7 + V_40 , V_28 [ V_31 ] , V_29 , V_30 ) )
return - V_16 ;
V_42:
V_31 ++ ;
}
return 0 ;
}
static void F_15 ( void )
{
F_16 ( V_43 , NULL ) ;
V_10 = 0 ;
}
static T_3 F_17 ( struct V_44 * V_44 , char V_15 * V_7 , T_1 V_3 ,
T_4 * V_45 )
{
unsigned long V_46 ;
T_1 V_47 ;
T_1 V_48 ;
T_1 V_49 ;
int V_50 ;
F_18 ( & V_51 ) ;
if ( * V_45 > ( V_25 . V_52 + V_53 ) ) {
V_50 = - V_54 ;
goto V_55;
}
V_3 = F_5 ( V_3 , ( T_1 ) ( V_25 . V_52 + V_53 - * V_45 ) ) ;
if ( * V_45 < V_53 ) {
V_49 = F_5 ( V_3 , ( T_1 ) ( V_53 - * V_45 ) ) ;
if ( F_6 ( V_7 , & V_56 + * V_45 , V_49 ) ) {
V_50 = - V_16 ;
goto V_55;
}
V_48 = V_49 ;
V_46 = 0 ;
} else {
V_48 = 0 ;
V_46 = * V_45 - V_53 ;
}
V_47 = 0 ;
if ( * V_45 < ( V_57 + V_53 ) ) {
V_49 = F_5 ( ( V_3 - V_48 ) , ( T_1 ) ( V_57
- V_46 ) ) ;
V_50 = F_7 ( V_7 + V_48 , V_46 , V_49 ) ;
if ( V_50 )
goto V_55;
V_47 += V_49 ;
}
V_49 = V_3 - V_47 - V_48 ;
V_50 = F_19 ( V_7 + V_48 + V_47 ,
( void * ) V_46 + V_47 , V_49 ) ;
if ( V_50 )
goto V_55;
if ( F_13 ( V_7 + V_48 , V_46 , V_3 - V_48 ) ) {
V_50 = - V_16 ;
goto V_55;
}
* V_45 += V_3 ;
V_55:
F_20 ( & V_51 ) ;
return ( V_50 < 0 ) ? V_50 : V_3 ;
}
static int F_21 ( struct V_58 * V_58 , struct V_44 * V_59 )
{
if ( ! V_10 )
return - V_11 ;
else
return F_22 ( V_60 ) ? 0 : - V_61 ;
}
static int F_23 ( struct V_58 * V_58 , struct V_44 * V_62 )
{
if ( V_10 )
F_15 () ;
return 0 ;
}
static T_4 F_24 ( struct V_44 * V_44 , T_4 V_63 , int V_64 )
{
T_4 V_50 ;
F_18 ( & V_51 ) ;
switch ( V_64 ) {
case 0 :
V_44 -> V_65 = V_63 ;
V_50 = V_44 -> V_65 ;
break;
case 1 :
V_44 -> V_65 += V_63 ;
V_50 = V_44 -> V_65 ;
break;
default:
V_50 = - V_54 ;
}
F_20 ( & V_51 ) ;
return V_50 ;
}
static T_3 F_25 ( struct V_44 * V_59 , char V_15 * V_7 ,
T_1 V_3 , T_4 * V_45 )
{
return F_26 ( V_7 , V_3 , V_45 , V_59 -> V_66 ,
V_67 * V_68 ) ;
}
static int F_27 ( struct V_58 * V_58 , struct V_44 * V_59 )
{
int V_31 ;
char * V_7 ;
struct V_69 * V_70 ;
V_70 = F_28 ( V_67 * sizeof( struct V_69 ) ,
V_23 ) ;
if ( ! V_70 )
return - V_24 ;
F_29 ( V_70 , 0 ) ;
V_7 = F_28 ( V_67 * V_68 , V_23 ) ;
if ( ! V_7 ) {
F_11 ( V_70 ) ;
return - V_24 ;
}
for ( V_31 = 0 ; V_31 < V_67 ; V_31 ++ ) {
sprintf ( V_7 + ( V_31 * V_68 ) , L_4 ,
( unsigned long long ) V_70 [ V_31 ] . V_71 ,
( unsigned long long ) V_70 [ V_31 ] . V_49 ) ;
if ( V_70 [ V_31 ] . V_49 == 0 )
break;
}
F_11 ( V_70 ) ;
V_59 -> V_66 = V_7 ;
return F_30 ( V_58 , V_59 ) ;
}
static int F_31 ( struct V_58 * V_58 , struct V_44 * V_59 )
{
F_11 ( V_59 -> V_66 ) ;
return 0 ;
}
static T_3 F_32 ( struct V_44 * V_59 , const char V_15 * V_7 ,
T_1 V_3 , T_4 * V_45 )
{
if ( V_72 ) {
F_16 ( V_73 , V_72 ) ;
F_16 ( V_74 , NULL ) ;
}
return V_3 ;
}
static int F_33 ( struct V_58 * V_58 , struct V_44 * V_59 )
{
return F_30 ( V_58 , V_59 ) ;
}
static int F_34 ( struct V_58 * V_58 , struct V_44 * V_59 )
{
return 0 ;
}
static T_3 F_35 ( struct V_44 * V_59 , char V_15 * V_7 ,
T_1 V_3 , T_4 * V_45 )
{
static char V_75 [ 18 ] ;
if ( V_10 )
snprintf ( V_75 , sizeof( V_75 ) , L_5 , V_57 ) ;
else
snprintf ( V_75 , sizeof( V_75 ) , L_6 ) ;
return F_26 ( V_7 , V_3 , V_45 , V_75 , strlen ( V_75 ) ) ;
}
static T_3 F_36 ( struct V_44 * V_59 , const char V_15 * V_7 ,
T_1 V_3 , T_4 * V_45 )
{
char V_76 ;
if ( * V_45 != 0 )
return - V_77 ;
if ( F_37 ( & V_76 , V_7 , 1 ) )
return - V_16 ;
if ( V_76 != '0' )
return - V_54 ;
F_15 () ;
return V_3 ;
}
static void T_2 F_38 ( struct V_21 * V_78 )
{
memset ( & V_78 -> V_79 , 0xff , sizeof( V_78 -> V_79 ) ) ;
memset ( & V_78 -> V_80 , 0xff , sizeof( V_78 -> V_80 ) ) ;
memset ( & V_78 -> V_81 , 0xff , sizeof( V_78 -> V_81 ) ) ;
memset ( & V_78 -> V_82 , 0xff , sizeof( V_78 -> V_82 ) ) ;
memset ( & V_78 -> V_41 , 0xff , sizeof( V_78 -> V_41 ) ) ;
memset ( & V_78 -> V_83 , 0xff , sizeof( V_78 -> V_83 ) ) ;
memset ( & V_78 -> V_84 , 0xff , sizeof( V_78 -> V_84 ) ) ;
memset ( & V_78 -> V_85 , 0xff , sizeof( V_78 -> V_85 ) ) ;
memset ( & V_78 -> V_86 , 0xff , sizeof( V_78 -> V_86 ) ) ;
}
static void T_2 F_38 ( struct V_21 * V_78 )
{
memset ( & V_78 -> V_84 , 0xff , sizeof( V_78 -> V_84 ) ) ;
memset ( & V_78 -> V_85 , 0xff , sizeof( V_78 -> V_85 ) ) ;
memset ( & V_78 -> V_82 , 0xff , sizeof( V_78 -> V_82 ) ) ;
memset ( & V_78 -> V_41 , 0xff , sizeof( V_78 -> V_41 ) ) ;
memset ( & V_78 -> V_87 , 0xff , sizeof( V_78 -> V_87 ) ) ;
memset ( & V_78 -> V_88 , 0xff , sizeof( V_78 -> V_88 ) ) ;
memset ( & V_78 -> V_80 , 0xff , sizeof( V_78 -> V_80 ) ) ;
memset ( & V_78 -> V_81 , 0xff , sizeof( V_78 -> V_81 ) ) ;
memset ( & V_78 -> V_83 , 0xff , sizeof( V_78 -> V_83 ) ) ;
memset ( & V_78 -> V_86 , 0xff , sizeof( V_78 -> V_86 ) ) ;
}
static int T_2 F_39 ( enum V_19 V_20 , unsigned long V_89 )
{
int V_50 ;
switch ( V_20 ) {
case V_90 :
F_40 ( L_7 ) ;
break;
case V_91 :
F_40 ( L_8 ) ;
break;
default:
F_40 ( L_9 , V_20 ) ;
return - V_54 ;
}
V_25 . V_26 = V_92 ;
V_25 . V_27 = sizeof( struct V_21 ) ;
V_25 . V_20 = V_20 ;
F_38 ( & V_25 . V_32 ) ;
V_50 = F_9 ( V_20 ) ;
if ( V_50 )
return V_50 ;
V_25 . V_52 = V_89 ;
return 0 ;
}
static int T_2 F_41 ( void )
{
int V_50 , V_93 ;
V_50 = F_42 () ;
if ( V_50 < 0 ) {
F_4 ( L_10 ) ;
return V_50 ;
}
V_93 = ( V_50 - 1 ) * V_8 ;
if ( V_93 < V_57 ) {
F_4 ( L_11 , V_93 ) ;
return - V_54 ;
}
return 0 ;
}
static int T_2 F_43 ( unsigned long * V_94 , unsigned long * V_34 )
{
int V_31 ;
struct V_69 * V_70 ;
V_70 = F_28 ( V_67 * sizeof( struct V_69 ) ,
V_23 ) ;
if ( ! V_70 )
return - V_24 ;
F_29 ( V_70 , 0 ) ;
for ( V_31 = 0 ; V_31 < V_67 ; V_31 ++ ) {
if ( V_70 [ V_31 ] . V_49 == 0 )
break;
* V_94 += V_70 [ V_31 ] . V_49 ;
* V_34 = F_14 ( * V_34 , V_70 [ V_31 ] . V_71 + V_70 [ V_31 ] . V_49 ) ;
}
F_11 ( V_70 ) ;
return 0 ;
}
static void T_2 F_44 ( int V_20 , struct V_56 * V_95 ,
unsigned long V_52 )
{
T_5 V_39 ;
int V_31 ;
if ( V_20 == V_90 )
V_95 -> V_19 = V_96 ;
else
V_95 -> V_19 = V_97 ;
V_95 -> V_52 = V_52 ;
V_95 -> V_98 = V_52 ;
V_95 -> V_89 = V_25 . V_52 ;
V_95 -> V_99 = V_52 / V_8 ;
V_95 -> V_100 = F_45 () ;
F_46 ( & V_95 -> V_101 ) ;
for ( V_31 = 0 ; V_28 [ V_31 ] ; V_31 ++ ) {
V_39 = V_28 [ V_31 ] -> V_41 ;
V_95 -> V_102 ++ ;
if ( ! V_39 )
continue;
V_95 -> V_103 [ V_95 -> V_104 ] = V_39 ;
V_95 -> V_104 ++ ;
}
}
static int T_2 F_47 ( void )
{
struct V_105 V_105 ;
int V_50 ;
V_50 = F_8 ( & V_105 , V_106 , sizeof( V_105 ) ) ;
if ( V_50 )
return V_50 ;
if ( V_105 . V_107 == 0 )
return 0 ;
V_72 = ( void * ) F_48 ( V_23 ) ;
if ( ! V_72 )
return - V_24 ;
if ( V_105 . V_107 < V_57 )
V_50 = F_8 ( V_72 , V_105 . V_107 , V_8 ) ;
else
V_50 = F_49 ( V_72 , ( void * ) V_105 . V_107 , V_8 ) ;
if ( V_50 || F_50 ( V_72 , V_72 -> V_95 . V_30 , 0 ) !=
V_105 . V_108 ) {
F_4 ( L_12 ) ;
F_51 ( ( unsigned long ) V_72 ) ;
V_72 = NULL ;
}
return 0 ;
}
static int T_2 F_52 ( void )
{
unsigned long V_52 , V_89 ;
unsigned char V_20 ;
int V_50 ;
V_52 = V_89 = 0 ;
if ( V_109 . type != V_110 )
return - V_11 ;
if ( V_111 )
return - V_11 ;
V_112 = F_53 ( L_13 , 4 , 1 , 4 * sizeof( long ) ) ;
F_54 ( V_112 , & V_113 ) ;
F_55 ( V_112 , 6 ) ;
F_4 ( L_14 , V_109 . V_114 . V_115 . V_116 . V_117 ) ;
F_4 ( L_15 , ( unsigned long long ) V_109 . V_114 . V_115 . V_118 ) ;
F_4 ( L_16 , ( unsigned long long ) V_109 . V_114 . V_115 . V_119 ) ;
V_50 = F_56 () ;
if ( V_50 )
goto V_55;
V_50 = F_41 () ;
if ( V_50 )
goto V_55;
V_10 = 1 ;
V_50 = F_8 ( & V_20 , V_120 , 1 ) ;
if ( V_50 )
goto V_55;
#ifdef F_57
if ( V_20 == V_91 ) {
F_40 ( L_17
L_18 ) ;
V_50 = - V_54 ;
goto V_55;
}
#else
if ( V_20 == V_90 ) {
F_40 ( L_19
L_20 ) ;
V_50 = - V_54 ;
goto V_55;
}
#endif
V_50 = F_43 ( & V_52 , & V_89 ) ;
if ( V_50 )
goto V_55;
V_50 = F_39 ( V_20 , V_89 ) ;
if ( V_50 )
goto V_55;
F_44 ( V_20 , & V_56 , V_52 ) ;
V_50 = F_47 () ;
if ( V_50 )
goto V_55;
V_121 = F_58 ( L_13 , NULL ) ;
if ( ! V_121 ) {
V_50 = - V_24 ;
goto V_55;
}
V_122 = F_59 ( L_21 , V_123 , V_121 , NULL ,
& V_124 ) ;
if ( ! V_122 ) {
V_50 = - V_24 ;
goto V_125;
}
V_126 = F_59 ( L_22 , V_123 , V_121 ,
NULL , & V_127 ) ;
if ( ! V_126 ) {
V_50 = - V_24 ;
goto V_128;
}
V_129 = F_59 ( L_23 , V_123 , V_121 ,
NULL , & V_130 ) ;
if ( ! V_129 ) {
V_50 = - V_24 ;
goto V_131;
}
V_132 = F_59 ( L_24 , V_123 | V_133 , V_121 ,
NULL , & V_134 ) ;
if ( ! V_132 ) {
V_50 = - V_24 ;
goto V_135;
}
return 0 ;
V_135:
F_60 ( V_129 ) ;
V_131:
F_60 ( V_126 ) ;
V_128:
F_60 ( V_122 ) ;
V_125:
F_60 ( V_121 ) ;
V_55:
F_16 ( V_43 , NULL ) ;
return V_50 ;
}
static void T_6 F_61 ( void )
{
F_62 ( V_112 ) ;
F_63 () ;
F_51 ( ( unsigned long ) V_72 ) ;
F_60 ( V_132 ) ;
F_60 ( V_129 ) ;
F_60 ( V_126 ) ;
F_60 ( V_122 ) ;
F_60 ( V_121 ) ;
F_16 ( V_43 , NULL ) ;
}
