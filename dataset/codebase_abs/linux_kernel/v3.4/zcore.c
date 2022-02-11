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
static int T_2 F_9 ( enum V_17 V_18 )
{
struct V_19 * V_20 ;
V_20 = F_10 ( sizeof( * V_20 ) , V_21 ) ;
if ( ! V_20 )
return - V_22 ;
if ( F_8 ( V_20 , V_23 . V_24 , V_23 . V_25 ) < 0 ) {
F_4 ( L_2 ) ;
F_11 ( V_20 ) ;
return - V_10 ;
}
V_26 [ 0 ] = V_20 ;
return 0 ;
}
static int F_12 ( void V_13 * V_7 , void * V_20 , int V_27 , int V_28 )
{
int V_29 ;
char * V_30 = ( char * ) & V_23 . V_30 ;
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ ) {
if ( ! V_30 [ V_29 + V_27 ] )
continue;
if ( F_6 ( V_7 + V_29 , V_20 + V_27 + V_29 , 1 ) )
return - V_14 ;
}
return 0 ;
}
static int F_13 ( char V_13 * V_7 , unsigned long V_31 , T_1 V_3 )
{
unsigned long V_32 ;
int V_29 = 0 ;
if ( V_3 == 0 )
return 0 ;
V_32 = V_31 + V_3 ;
while ( V_26 [ V_29 ] ) {
unsigned long V_33 , V_34 ;
unsigned long V_35 , V_36 ;
unsigned long V_37 ;
unsigned long V_27 , V_28 , V_38 ;
V_37 = V_26 [ V_29 ] -> V_39 ;
V_35 = V_37 + V_23 . V_24 ;
V_36 = V_37 + V_23 . V_24 + V_23 . V_25 ;
if ( ( V_32 < V_35 ) || ( V_31 > V_36 ) )
goto V_40;
V_33 = F_14 ( V_31 , V_35 ) ;
V_34 = F_5 ( V_32 , V_36 ) ;
V_38 = V_33 - V_31 ;
V_27 = V_33 - V_35 ;
V_28 = V_34 - V_33 ;
F_4 ( L_3 , V_31 ) ;
if ( F_12 ( V_7 + V_38 , V_26 [ V_29 ] , V_27 , V_28 ) )
return - V_14 ;
V_40:
V_29 ++ ;
}
return 0 ;
}
static T_3 F_15 ( struct V_41 * V_41 , char V_13 * V_7 , T_1 V_3 ,
T_4 * V_42 )
{
unsigned long V_43 ;
T_1 V_44 ;
T_1 V_45 ;
T_1 V_46 ;
int V_47 ;
F_16 ( & V_48 ) ;
if ( * V_42 > ( V_23 . V_49 + V_50 ) ) {
V_47 = - V_51 ;
goto V_52;
}
V_3 = F_5 ( V_3 , ( T_1 ) ( V_23 . V_49 + V_50 - * V_42 ) ) ;
if ( * V_42 < V_50 ) {
V_46 = F_5 ( V_3 , ( T_1 ) ( V_50 - * V_42 ) ) ;
if ( F_6 ( V_7 , & V_53 + * V_42 , V_46 ) ) {
V_47 = - V_14 ;
goto V_52;
}
V_45 = V_46 ;
V_43 = 0 ;
} else {
V_45 = 0 ;
V_43 = * V_42 - V_50 ;
}
V_44 = 0 ;
if ( * V_42 < ( V_54 + V_50 ) ) {
V_46 = F_5 ( ( V_3 - V_45 ) , ( T_1 ) ( V_54
- V_43 ) ) ;
V_47 = F_7 ( V_7 + V_45 , V_43 , V_46 ) ;
if ( V_47 )
goto V_52;
V_44 += V_46 ;
}
V_46 = V_3 - V_44 - V_45 ;
V_47 = F_17 ( V_7 + V_45 + V_44 ,
( void * ) V_43 + V_44 , V_46 ) ;
if ( V_47 )
goto V_52;
if ( F_13 ( V_7 + V_45 , V_43 , V_3 - V_45 ) ) {
V_47 = - V_14 ;
goto V_52;
}
* V_42 += V_3 ;
V_52:
F_18 ( & V_48 ) ;
return ( V_47 < 0 ) ? V_47 : V_3 ;
}
static int F_19 ( struct V_55 * V_55 , struct V_41 * V_56 )
{
if ( ! V_57 )
return - V_58 ;
else
return F_20 ( V_59 ) ? 0 : - V_60 ;
}
static int F_21 ( struct V_55 * V_55 , struct V_41 * V_61 )
{
F_22 ( V_62 , NULL ) ;
V_57 = 0 ;
return 0 ;
}
static T_4 F_23 ( struct V_41 * V_41 , T_4 V_63 , int V_64 )
{
T_4 V_47 ;
F_16 ( & V_48 ) ;
switch ( V_64 ) {
case 0 :
V_41 -> V_65 = V_63 ;
V_47 = V_41 -> V_65 ;
break;
case 1 :
V_41 -> V_65 += V_63 ;
V_47 = V_41 -> V_65 ;
break;
default:
V_47 = - V_51 ;
}
F_18 ( & V_48 ) ;
return V_47 ;
}
static T_3 F_24 ( struct V_41 * V_56 , char V_13 * V_7 ,
T_1 V_3 , T_4 * V_42 )
{
return F_25 ( V_7 , V_3 , V_42 , V_56 -> V_66 ,
V_67 * V_68 ) ;
}
static int F_26 ( struct V_55 * V_55 , struct V_41 * V_56 )
{
int V_29 ;
char * V_7 ;
struct V_69 * V_70 ;
V_70 = F_27 ( V_67 * sizeof( struct V_69 ) ,
V_21 ) ;
if ( ! V_70 )
return - V_22 ;
F_28 ( V_70 ) ;
V_7 = F_27 ( V_67 * V_68 , V_21 ) ;
if ( ! V_7 ) {
F_11 ( V_70 ) ;
return - V_22 ;
}
for ( V_29 = 0 ; V_29 < V_67 ; V_29 ++ ) {
sprintf ( V_7 + ( V_29 * V_68 ) , L_4 ,
( unsigned long long ) V_70 [ V_29 ] . V_71 ,
( unsigned long long ) V_70 [ V_29 ] . V_46 ) ;
if ( V_70 [ V_29 ] . V_46 == 0 )
break;
}
F_11 ( V_70 ) ;
V_56 -> V_66 = V_7 ;
return F_29 ( V_55 , V_56 ) ;
}
static int F_30 ( struct V_55 * V_55 , struct V_41 * V_56 )
{
F_11 ( V_56 -> V_66 ) ;
return 0 ;
}
static T_3 F_31 ( struct V_41 * V_56 , const char V_13 * V_7 ,
T_1 V_3 , T_4 * V_42 )
{
if ( V_72 ) {
F_22 ( V_73 , V_72 ) ;
F_22 ( V_74 , NULL ) ;
}
return V_3 ;
}
static int F_32 ( struct V_55 * V_55 , struct V_41 * V_56 )
{
return F_29 ( V_55 , V_56 ) ;
}
static int F_33 ( struct V_55 * V_55 , struct V_41 * V_56 )
{
return 0 ;
}
static void T_2 F_34 ( struct V_19 * V_75 )
{
memset ( & V_75 -> V_76 , 0xff , sizeof( V_75 -> V_76 ) ) ;
memset ( & V_75 -> V_77 , 0xff , sizeof( V_75 -> V_77 ) ) ;
memset ( & V_75 -> V_78 , 0xff , sizeof( V_75 -> V_78 ) ) ;
memset ( & V_75 -> V_79 , 0xff , sizeof( V_75 -> V_79 ) ) ;
memset ( & V_75 -> V_39 , 0xff , sizeof( V_75 -> V_39 ) ) ;
memset ( & V_75 -> V_80 , 0xff , sizeof( V_75 -> V_80 ) ) ;
memset ( & V_75 -> V_81 , 0xff , sizeof( V_75 -> V_81 ) ) ;
memset ( & V_75 -> V_82 , 0xff , sizeof( V_75 -> V_82 ) ) ;
memset ( & V_75 -> V_83 , 0xff , sizeof( V_75 -> V_83 ) ) ;
}
static void T_2 F_34 ( struct V_19 * V_75 )
{
memset ( & V_75 -> V_81 , 0xff , sizeof( V_75 -> V_81 ) ) ;
memset ( & V_75 -> V_82 , 0xff , sizeof( V_75 -> V_82 ) ) ;
memset ( & V_75 -> V_79 , 0xff , sizeof( V_75 -> V_79 ) ) ;
memset ( & V_75 -> V_39 , 0xff , sizeof( V_75 -> V_39 ) ) ;
memset ( & V_75 -> V_84 , 0xff , sizeof( V_75 -> V_84 ) ) ;
memset ( & V_75 -> V_85 , 0xff , sizeof( V_75 -> V_85 ) ) ;
memset ( & V_75 -> V_77 , 0xff , sizeof( V_75 -> V_77 ) ) ;
memset ( & V_75 -> V_78 , 0xff , sizeof( V_75 -> V_78 ) ) ;
memset ( & V_75 -> V_80 , 0xff , sizeof( V_75 -> V_80 ) ) ;
memset ( & V_75 -> V_83 , 0xff , sizeof( V_75 -> V_83 ) ) ;
}
static int T_2 F_35 ( enum V_17 V_18 )
{
int V_47 ;
switch ( V_18 ) {
case V_86 :
F_36 ( L_5 ) ;
break;
case V_87 :
F_36 ( L_6 ) ;
break;
default:
F_36 ( L_7 , V_18 ) ;
return - V_51 ;
}
V_23 . V_24 = V_88 ;
V_23 . V_25 = sizeof( struct V_19 ) ;
V_23 . V_18 = V_18 ;
F_34 ( & V_23 . V_30 ) ;
V_47 = F_9 ( V_18 ) ;
if ( V_47 )
return V_47 ;
V_23 . V_49 = V_89 ;
return 0 ;
}
static int T_2 F_37 ( void )
{
int V_47 , V_90 ;
V_47 = F_38 () ;
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
static int T_2 F_39 ( unsigned long * V_91 )
{
int V_29 ;
struct V_69 * V_70 ;
V_70 = F_27 ( V_67 * sizeof( struct V_69 ) ,
V_21 ) ;
if ( ! V_70 )
return - V_22 ;
F_28 ( V_70 ) ;
for ( V_29 = 0 ; V_29 < V_67 ; V_29 ++ ) {
if ( V_70 [ V_29 ] . V_46 == 0 )
break;
* V_91 += V_70 [ V_29 ] . V_46 ;
}
F_11 ( V_70 ) ;
return 0 ;
}
static int T_2 F_40 ( int V_18 , struct V_53 * V_92 )
{
int V_47 , V_29 ;
unsigned long V_93 = 0 ;
T_5 V_37 ;
if ( V_18 == V_86 )
V_92 -> V_17 = V_94 ;
else
V_92 -> V_17 = V_95 ;
V_47 = F_39 ( & V_93 ) ;
if ( V_47 )
return V_47 ;
V_92 -> V_49 = V_93 ;
V_92 -> V_96 = V_93 ;
V_92 -> V_97 = V_23 . V_49 ;
V_92 -> V_98 = V_93 / V_8 ;
V_92 -> V_99 = F_41 () ;
F_42 ( & V_92 -> V_100 ) ;
for ( V_29 = 0 ; V_26 [ V_29 ] ; V_29 ++ ) {
V_37 = V_26 [ V_29 ] -> V_39 ;
V_92 -> V_101 ++ ;
if ( ! V_37 )
continue;
V_92 -> V_102 [ V_92 -> V_103 ] = V_37 ;
V_92 -> V_103 ++ ;
}
return 0 ;
}
static int T_2 F_43 ( void )
{
struct V_104 V_104 ;
int V_47 ;
V_47 = F_8 ( & V_104 , V_105 , sizeof( V_104 ) ) ;
if ( V_47 )
return V_47 ;
if ( V_104 . V_106 == 0 )
return 0 ;
V_72 = ( void * ) F_44 ( V_21 ) ;
if ( ! V_72 )
return - V_22 ;
if ( V_104 . V_106 < V_54 )
V_47 = F_8 ( V_72 , V_104 . V_106 , V_8 ) ;
else
V_47 = F_45 ( V_72 , ( void * ) V_104 . V_106 , V_8 ) ;
if ( V_47 || F_46 ( V_72 , V_72 -> V_92 . V_28 , 0 ) !=
V_104 . V_107 ) {
F_4 ( L_10 ) ;
F_47 ( ( unsigned long ) V_72 ) ;
V_72 = NULL ;
}
return 0 ;
}
static int T_2 F_48 ( void )
{
unsigned char V_18 ;
int V_47 ;
if ( V_108 . type != V_109 )
return - V_58 ;
if ( V_110 )
return - V_58 ;
V_111 = F_49 ( L_11 , 4 , 1 , 4 * sizeof( long ) ) ;
F_50 ( V_111 , & V_112 ) ;
F_51 ( V_111 , 6 ) ;
F_4 ( L_12 , V_108 . V_113 . V_114 . V_115 . V_116 ) ;
F_4 ( L_13 , ( unsigned long long ) V_108 . V_113 . V_114 . V_117 ) ;
F_4 ( L_14 , ( unsigned long long ) V_108 . V_113 . V_114 . V_118 ) ;
V_47 = F_52 () ;
if ( V_47 )
goto V_52;
V_47 = F_37 () ;
if ( V_47 )
goto V_52;
V_47 = F_8 ( & V_18 , V_119 , 1 ) ;
if ( V_47 )
goto V_52;
#ifdef F_53
if ( V_18 == V_87 ) {
F_36 ( L_15
L_16 ) ;
V_47 = - V_51 ;
goto V_52;
}
#else
if ( V_18 == V_86 ) {
F_36 ( L_17
L_18 ) ;
V_47 = - V_51 ;
goto V_52;
}
#endif
V_47 = F_35 ( V_18 ) ;
if ( V_47 )
goto V_52;
V_47 = F_40 ( V_18 , & V_53 ) ;
if ( V_47 )
goto V_52;
V_47 = F_43 () ;
if ( V_47 )
goto V_52;
V_120 = F_54 ( L_11 , NULL ) ;
if ( ! V_120 ) {
V_47 = - V_22 ;
goto V_52;
}
V_121 = F_55 ( L_19 , V_122 , V_120 , NULL ,
& V_123 ) ;
if ( ! V_121 ) {
V_47 = - V_22 ;
goto V_124;
}
V_125 = F_55 ( L_20 , V_122 , V_120 ,
NULL , & V_126 ) ;
if ( ! V_125 ) {
V_47 = - V_22 ;
goto V_127;
}
V_128 = F_55 ( L_21 , V_122 , V_120 ,
NULL , & V_129 ) ;
if ( ! V_128 ) {
V_47 = - V_22 ;
goto V_130;
}
V_57 = 1 ;
return 0 ;
V_130:
F_56 ( V_125 ) ;
V_127:
F_56 ( V_121 ) ;
V_124:
F_56 ( V_120 ) ;
V_52:
F_22 ( V_62 , NULL ) ;
return V_47 ;
}
static void T_6 F_57 ( void )
{
F_58 ( V_111 ) ;
F_59 () ;
F_47 ( ( unsigned long ) V_72 ) ;
F_56 ( V_128 ) ;
F_56 ( V_125 ) ;
F_56 ( V_121 ) ;
F_56 ( V_120 ) ;
F_22 ( V_62 , NULL ) ;
}
