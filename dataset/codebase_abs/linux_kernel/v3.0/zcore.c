static int F_1 ( void * V_1 , unsigned long V_2 , T_1 V_3 , int V_4 )
{
int V_5 , V_6 ;
static char V_7 [ V_8 ] V_9 ( ( F_2 ( V_8 ) ) ) ;
if ( V_3 == 0 )
return 0 ;
V_5 = 0 ;
if ( ( V_2 % V_8 ) != 0 ) {
V_6 = V_2 / V_8 + 2 ;
if ( F_3 ( V_7 , V_6 , 1 ) ) {
F_4 ( L_1 ) ;
return - V_10 ;
}
V_5 = F_5 ( ( V_8 - ( V_2 % V_8 ) ) , V_3 ) ;
if ( V_4 == V_11 ) {
if ( F_6 ( ( V_12 V_13 void * ) V_1 ,
V_7 + ( V_2 % V_8 ) , V_5 ) )
return - V_14 ;
} else
memcpy ( V_1 , V_7 + ( V_2 % V_8 ) , V_5 ) ;
}
if ( V_5 == V_3 )
goto V_15;
for (; ( V_5 + V_8 ) <= V_3 ; V_5 += V_8 ) {
V_6 = ( V_2 + V_5 ) / V_8 + 2 ;
if ( F_3 ( V_7 , V_6 , 1 ) ) {
F_4 ( L_1 ) ;
return - V_10 ;
}
if ( V_4 == V_11 ) {
if ( F_6 ( ( V_12 V_13 void * ) V_1 + V_5 ,
V_7 , V_8 ) )
return - V_14 ;
} else
memcpy ( V_1 + V_5 , V_7 , V_8 ) ;
}
if ( V_5 == V_3 )
goto V_15;
V_6 = ( V_2 + V_5 ) / V_8 + 2 ;
if ( F_3 ( V_7 , V_6 , 1 ) ) {
F_4 ( L_1 ) ;
return - V_10 ;
}
if ( V_4 == V_11 ) {
if ( F_6 ( ( V_12 V_13 void * ) V_1 + V_5 , V_7 ,
V_8 ) )
return - V_14 ;
} else
memcpy ( V_1 + V_5 , V_7 , V_3 - V_5 ) ;
V_15:
return 0 ;
}
static int F_7 ( void V_13 * V_1 , unsigned long V_2 , T_1 V_3 )
{
return F_1 ( ( void V_12 * ) V_1 , V_2 , V_3 , V_11 ) ;
}
static int F_8 ( void * V_1 , unsigned long V_2 , T_1 V_3 )
{
return F_1 ( V_1 , V_2 , V_3 , V_16 ) ;
}
static int F_9 ( void V_13 * V_1 , unsigned long V_2 , T_1 V_3 )
{
static char V_7 [ 4096 ] ;
int V_5 = 0 , V_17 ;
while ( V_5 < V_3 ) {
V_17 = F_5 ( sizeof( V_7 ) , V_3 - V_5 ) ;
if ( F_10 ( V_7 , ( void * ) V_2 + V_5 , V_17 ) )
return - V_14 ;
if ( F_6 ( V_1 + V_5 , V_7 , V_17 ) )
return - V_14 ;
V_5 += V_17 ;
}
return 0 ;
}
static int T_2 F_11 ( enum V_18 V_19 )
{
struct V_20 * V_21 ;
V_21 = F_12 ( sizeof( * V_21 ) , V_22 ) ;
if ( ! V_21 )
return - V_23 ;
if ( F_8 ( V_21 , V_24 . V_25 , V_24 . V_26 ) < 0 ) {
F_4 ( L_2 ) ;
F_13 ( V_21 ) ;
return - V_10 ;
}
V_27 [ 0 ] = V_21 ;
return 0 ;
}
static int F_14 ( void V_13 * V_7 , void * V_21 , int V_28 , int V_29 )
{
int V_30 ;
char * V_31 = ( char * ) & V_24 . V_31 ;
for ( V_30 = 0 ; V_30 < V_29 ; V_30 ++ ) {
if ( ! V_31 [ V_30 + V_28 ] )
continue;
if ( F_6 ( V_7 + V_30 , V_21 + V_28 + V_30 , 1 ) )
return - V_14 ;
}
return 0 ;
}
static int F_15 ( char V_13 * V_7 , unsigned long V_32 , T_1 V_3 )
{
unsigned long V_33 ;
int V_30 = 0 ;
if ( V_3 == 0 )
return 0 ;
V_33 = V_32 + V_3 ;
while ( V_27 [ V_30 ] ) {
unsigned long V_34 , V_35 ;
unsigned long V_36 , V_37 ;
unsigned long V_38 ;
unsigned long V_28 , V_29 , V_39 ;
V_38 = V_27 [ V_30 ] -> V_40 ;
V_36 = V_38 + V_24 . V_25 ;
V_37 = V_38 + V_24 . V_25 + V_24 . V_26 ;
if ( ( V_33 < V_36 ) || ( V_32 > V_37 ) )
goto V_41;
V_34 = F_16 ( V_32 , V_36 ) ;
V_35 = F_5 ( V_33 , V_37 ) ;
V_39 = V_34 - V_32 ;
V_28 = V_34 - V_36 ;
V_29 = V_35 - V_34 ;
F_4 ( L_3 , V_32 ) ;
if ( F_14 ( V_7 + V_39 , V_27 [ V_30 ] , V_28 , V_29 ) )
return - V_14 ;
V_41:
V_30 ++ ;
}
return 0 ;
}
static T_3 F_17 ( struct V_42 * V_42 , char V_13 * V_7 , T_1 V_3 ,
T_4 * V_43 )
{
unsigned long V_44 ;
T_1 V_45 ;
T_1 V_46 ;
T_1 V_17 ;
int V_47 ;
F_18 ( & V_48 ) ;
if ( * V_43 > ( V_24 . V_49 + V_50 ) ) {
V_47 = - V_51 ;
goto V_52;
}
V_3 = F_5 ( V_3 , ( T_1 ) ( V_24 . V_49 + V_50 - * V_43 ) ) ;
if ( * V_43 < V_50 ) {
V_17 = F_5 ( V_3 , ( T_1 ) ( V_50 - * V_43 ) ) ;
if ( F_6 ( V_7 , & V_53 + * V_43 , V_17 ) ) {
V_47 = - V_14 ;
goto V_52;
}
V_46 = V_17 ;
V_44 = 0 ;
} else {
V_46 = 0 ;
V_44 = * V_43 - V_50 ;
}
V_45 = 0 ;
if ( * V_43 < ( V_54 + V_50 ) ) {
V_17 = F_5 ( ( V_3 - V_46 ) , ( T_1 ) ( V_54
- V_44 ) ) ;
V_47 = F_7 ( V_7 + V_46 , V_44 , V_17 ) ;
if ( V_47 )
goto V_52;
V_45 += V_17 ;
}
V_17 = V_3 - V_45 - V_46 ;
V_47 = F_9 ( V_7 + V_46 + V_45 , V_44 + V_45 ,
V_17 ) ;
if ( V_47 )
goto V_52;
if ( F_15 ( V_7 + V_46 , V_44 , V_3 - V_46 ) ) {
V_47 = - V_14 ;
goto V_52;
}
* V_43 += V_3 ;
V_52:
F_19 ( & V_48 ) ;
return ( V_47 < 0 ) ? V_47 : V_3 ;
}
static int F_20 ( struct V_55 * V_55 , struct V_42 * V_56 )
{
if ( ! V_57 )
return - V_58 ;
else
return F_21 ( V_59 ) ? 0 : - V_60 ;
}
static int F_22 ( struct V_55 * V_55 , struct V_42 * V_61 )
{
F_23 ( V_62 , NULL ) ;
V_57 = 0 ;
return 0 ;
}
static T_4 F_24 ( struct V_42 * V_42 , T_4 V_63 , int V_64 )
{
T_4 V_47 ;
F_18 ( & V_48 ) ;
switch ( V_64 ) {
case 0 :
V_42 -> V_65 = V_63 ;
V_47 = V_42 -> V_65 ;
break;
case 1 :
V_42 -> V_65 += V_63 ;
V_47 = V_42 -> V_65 ;
break;
default:
V_47 = - V_51 ;
}
F_19 ( & V_48 ) ;
return V_47 ;
}
static T_3 F_25 ( struct V_42 * V_56 , char V_13 * V_7 ,
T_1 V_3 , T_4 * V_43 )
{
return F_26 ( V_7 , V_3 , V_43 , V_56 -> V_66 ,
V_67 * V_68 ) ;
}
static int F_27 ( struct V_55 * V_55 , struct V_42 * V_56 )
{
int V_30 ;
char * V_7 ;
struct V_69 * V_70 ;
V_70 = F_28 ( V_67 * sizeof( struct V_69 ) ,
V_22 ) ;
if ( ! V_70 )
return - V_23 ;
F_29 ( V_70 ) ;
V_7 = F_28 ( V_67 * V_68 , V_22 ) ;
if ( ! V_7 ) {
F_13 ( V_70 ) ;
return - V_23 ;
}
for ( V_30 = 0 ; V_30 < V_67 ; V_30 ++ ) {
sprintf ( V_7 + ( V_30 * V_68 ) , L_4 ,
( unsigned long long ) V_70 [ V_30 ] . V_71 ,
( unsigned long long ) V_70 [ V_30 ] . V_17 ) ;
if ( V_70 [ V_30 ] . V_17 == 0 )
break;
}
F_13 ( V_70 ) ;
V_56 -> V_66 = V_7 ;
return F_30 ( V_55 , V_56 ) ;
}
static int F_31 ( struct V_55 * V_55 , struct V_42 * V_56 )
{
F_13 ( V_56 -> V_66 ) ;
return 0 ;
}
static T_3 F_32 ( struct V_42 * V_56 , const char V_13 * V_7 ,
T_1 V_3 , T_4 * V_43 )
{
if ( V_72 ) {
F_23 ( V_73 , V_72 ) ;
F_23 ( V_74 , NULL ) ;
}
return V_3 ;
}
static int F_33 ( struct V_55 * V_55 , struct V_42 * V_56 )
{
return F_30 ( V_55 , V_56 ) ;
}
static int F_34 ( struct V_55 * V_55 , struct V_42 * V_56 )
{
return 0 ;
}
static void T_2 F_35 ( struct V_20 * V_75 )
{
memset ( & V_75 -> V_76 , 0xff , sizeof( V_75 -> V_76 ) ) ;
memset ( & V_75 -> V_77 , 0xff , sizeof( V_75 -> V_77 ) ) ;
memset ( & V_75 -> V_78 , 0xff , sizeof( V_75 -> V_78 ) ) ;
memset ( & V_75 -> V_79 , 0xff , sizeof( V_75 -> V_79 ) ) ;
memset ( & V_75 -> V_40 , 0xff , sizeof( V_75 -> V_40 ) ) ;
memset ( & V_75 -> V_80 , 0xff , sizeof( V_75 -> V_80 ) ) ;
memset ( & V_75 -> V_81 , 0xff , sizeof( V_75 -> V_81 ) ) ;
memset ( & V_75 -> V_82 , 0xff , sizeof( V_75 -> V_82 ) ) ;
memset ( & V_75 -> V_83 , 0xff , sizeof( V_75 -> V_83 ) ) ;
}
static void T_2 F_35 ( struct V_20 * V_75 )
{
memset ( & V_75 -> V_81 , 0xff , sizeof( V_75 -> V_81 ) ) ;
memset ( & V_75 -> V_82 , 0xff , sizeof( V_75 -> V_82 ) ) ;
memset ( & V_75 -> V_79 , 0xff , sizeof( V_75 -> V_79 ) ) ;
memset ( & V_75 -> V_40 , 0xff , sizeof( V_75 -> V_40 ) ) ;
memset ( & V_75 -> V_84 , 0xff , sizeof( V_75 -> V_84 ) ) ;
memset ( & V_75 -> V_85 , 0xff , sizeof( V_75 -> V_85 ) ) ;
memset ( & V_75 -> V_77 , 0xff , sizeof( V_75 -> V_77 ) ) ;
memset ( & V_75 -> V_78 , 0xff , sizeof( V_75 -> V_78 ) ) ;
memset ( & V_75 -> V_80 , 0xff , sizeof( V_75 -> V_80 ) ) ;
memset ( & V_75 -> V_83 , 0xff , sizeof( V_75 -> V_83 ) ) ;
}
static int T_2 F_36 ( enum V_18 V_19 )
{
int V_47 ;
switch ( V_19 ) {
case V_86 :
F_37 ( L_5 ) ;
break;
case V_87 :
F_37 ( L_6 ) ;
break;
default:
F_37 ( L_7 , V_19 ) ;
return - V_51 ;
}
V_24 . V_25 = V_88 ;
V_24 . V_26 = sizeof( struct V_20 ) ;
V_24 . V_19 = V_19 ;
F_35 ( & V_24 . V_31 ) ;
V_47 = F_11 ( V_19 ) ;
if ( V_47 )
return V_47 ;
V_24 . V_49 = V_89 ;
return 0 ;
}
static int T_2 F_38 ( void )
{
int V_47 , V_90 ;
V_47 = F_39 () ;
if ( V_47 < 0 ) {
F_4 ( L_8 ) ;
return V_47 ;
}
V_90 = ( V_47 - 1 ) * V_8 ;
if ( V_90 < V_54 ) {
F_4 ( L_9 , V_90 ) ;
return - V_51 ;
}
return 0 ;
}
static int T_2 F_40 ( unsigned long * V_91 )
{
int V_30 ;
struct V_69 * V_70 ;
V_70 = F_28 ( V_67 * sizeof( struct V_69 ) ,
V_22 ) ;
if ( ! V_70 )
return - V_23 ;
F_29 ( V_70 ) ;
for ( V_30 = 0 ; V_30 < V_67 ; V_30 ++ ) {
if ( V_70 [ V_30 ] . V_17 == 0 )
break;
* V_91 += V_70 [ V_30 ] . V_17 ;
}
F_13 ( V_70 ) ;
return 0 ;
}
static int T_2 F_41 ( int V_19 , struct V_53 * V_92 )
{
int V_47 , V_30 ;
unsigned long V_93 = 0 ;
T_5 V_38 ;
if ( V_19 == V_86 )
V_92 -> V_18 = V_94 ;
else
V_92 -> V_18 = V_95 ;
V_47 = F_40 ( & V_93 ) ;
if ( V_47 )
return V_47 ;
V_92 -> V_49 = V_93 ;
V_92 -> V_96 = V_93 ;
V_92 -> V_97 = V_24 . V_49 ;
V_92 -> V_98 = V_93 / V_8 ;
V_92 -> V_99 = F_42 () ;
F_43 ( & V_92 -> V_100 ) ;
for ( V_30 = 0 ; V_27 [ V_30 ] ; V_30 ++ ) {
V_38 = V_27 [ V_30 ] -> V_40 ;
V_92 -> V_101 ++ ;
if ( ! V_38 )
continue;
V_92 -> V_102 [ V_92 -> V_103 ] = V_38 ;
V_92 -> V_103 ++ ;
}
return 0 ;
}
static int T_2 F_44 ( void )
{
struct V_104 V_104 ;
int V_47 ;
V_47 = F_8 ( & V_104 , V_105 , sizeof( V_104 ) ) ;
if ( V_47 )
return V_47 ;
if ( V_104 . V_106 == 0 )
return 0 ;
V_72 = ( void * ) F_45 ( V_22 ) ;
if ( ! V_72 )
return - V_23 ;
if ( V_104 . V_106 < V_54 )
V_47 = F_8 ( V_72 , V_104 . V_106 , V_8 ) ;
else
V_47 = F_10 ( V_72 , ( void * ) V_104 . V_106 , V_8 ) ;
if ( V_47 || F_46 ( V_72 , V_72 -> V_92 . V_29 , 0 ) !=
V_104 . V_107 ) {
F_4 ( L_10 ) ;
F_47 ( ( unsigned long ) V_72 ) ;
V_72 = NULL ;
}
return 0 ;
}
static int T_2 F_48 ( void )
{
unsigned char V_19 ;
int V_47 ;
if ( V_108 . type != V_109 )
return - V_58 ;
V_110 = F_49 ( L_11 , 4 , 1 , 4 * sizeof( long ) ) ;
F_50 ( V_110 , & V_111 ) ;
F_51 ( V_110 , 6 ) ;
F_4 ( L_12 , V_108 . V_112 . V_113 . V_114 . V_115 ) ;
F_4 ( L_13 , ( unsigned long long ) V_108 . V_112 . V_113 . V_116 ) ;
F_4 ( L_14 , ( unsigned long long ) V_108 . V_112 . V_113 . V_117 ) ;
V_47 = F_52 () ;
if ( V_47 )
goto V_52;
V_47 = F_38 () ;
if ( V_47 )
goto V_52;
V_47 = F_8 ( & V_19 , V_118 , 1 ) ;
if ( V_47 )
goto V_52;
#ifdef F_53
if ( V_19 == V_87 ) {
F_37 ( L_15
L_16 ) ;
V_47 = - V_51 ;
goto V_52;
}
#else
if ( V_19 == V_86 ) {
F_37 ( L_17
L_18 ) ;
V_47 = - V_51 ;
goto V_52;
}
#endif
V_47 = F_36 ( V_19 ) ;
if ( V_47 )
goto V_52;
V_47 = F_41 ( V_19 , & V_53 ) ;
if ( V_47 )
goto V_52;
V_47 = F_44 () ;
if ( V_47 )
goto V_52;
V_119 = F_54 ( L_11 , NULL ) ;
if ( ! V_119 ) {
V_47 = - V_23 ;
goto V_52;
}
V_120 = F_55 ( L_19 , V_121 , V_119 , NULL ,
& V_122 ) ;
if ( ! V_120 ) {
V_47 = - V_23 ;
goto V_123;
}
V_124 = F_55 ( L_20 , V_121 , V_119 ,
NULL , & V_125 ) ;
if ( ! V_124 ) {
V_47 = - V_23 ;
goto V_126;
}
V_127 = F_55 ( L_21 , V_121 , V_119 ,
NULL , & V_128 ) ;
if ( ! V_127 ) {
V_47 = - V_23 ;
goto V_129;
}
V_57 = 1 ;
return 0 ;
V_129:
F_56 ( V_124 ) ;
V_126:
F_56 ( V_120 ) ;
V_123:
F_56 ( V_119 ) ;
V_52:
F_23 ( V_62 , NULL ) ;
return V_47 ;
}
static void T_6 F_57 ( void )
{
F_58 ( V_110 ) ;
F_59 () ;
F_47 ( ( unsigned long ) V_72 ) ;
F_56 ( V_127 ) ;
F_56 ( V_124 ) ;
F_56 ( V_120 ) ;
F_56 ( V_119 ) ;
F_23 ( V_62 , NULL ) ;
}
