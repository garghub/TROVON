static void F_1 ( void )
{
fprintf ( V_1 , L_1
L_2 ) ;
fprintf ( V_1 , L_3 ) ;
fprintf ( V_1 , L_4 ) ;
fprintf ( V_1 , L_5 ) ;
fprintf ( V_1 , L_6 ) ;
fprintf ( V_1 , L_7 ) ;
}
static int F_2 ( int V_2 )
{
int V_3 ;
struct V_4 V_5 ;
V_3 = F_3 ( V_6 , V_7 , V_2 ) ;
if ( V_3 < 0 )
return - 1 ;
if ( V_8 )
if ( F_4 ( V_3 , V_9 , V_10 ,
& V_8 , sizeof( V_8 ) ) < 0 ) {
fprintf ( V_1 , L_8 ,
V_8 ) ;
goto error;
}
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_5 . V_11 = V_6 ;
if ( F_5 ( V_3 , (struct V_12 * ) & V_5 , sizeof( V_5 ) ) < 0 )
goto error;
return V_3 ;
error:
F_6 ( V_3 ) ;
return - 1 ;
}
static int F_7 ( int V_13 , T_1 V_14 , T_2 V_15 ,
T_3 V_16 , T_1 V_17 ,
void * V_18 , int V_19 )
{
struct V_20 * V_21 ;
struct V_4 V_22 ;
int V_23 , V_24 ;
char * V_25 ;
struct V_26 V_27 ;
V_27 . V_28 . V_29 = F_8 ( V_30 ) ;
V_27 . V_28 . V_14 = V_14 ;
V_27 . V_28 . V_31 = V_32 ;
V_27 . V_28 . V_33 = 0 ;
V_27 . V_28 . V_15 = V_15 ;
V_27 . V_34 . V_35 = V_16 ;
V_27 . V_34 . V_36 = 0x1 ;
V_21 = (struct V_20 * ) F_9 ( & V_27 ) ;
V_21 -> V_17 = V_17 ;
V_21 -> V_19 = V_19 + 1 + V_37 ;
memcpy ( F_10 ( V_21 ) , V_18 , V_19 ) ;
V_27 . V_28 . V_29 += F_11 ( V_21 -> V_19 ) ;
V_25 = ( char * ) & V_27 ;
V_24 = V_27 . V_28 . V_29 ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
V_22 . V_11 = V_6 ;
while ( ( V_23 = F_12 ( V_13 , V_25 , V_24 , 0 , (struct V_12 * ) & V_22 ,
sizeof( V_22 ) ) ) < V_24 ) {
if ( V_23 > 0 ) {
V_25 += V_23 ;
V_24 -= V_23 ;
} else if ( V_38 != V_39 )
return - 1 ;
}
return 0 ;
}
static int F_13 ( int V_13 )
{
struct {
struct V_40 V_28 ;
struct V_41 V_34 ;
char V_25 [ 256 ] ;
} V_42 ;
int V_43 = 0 , V_44 ;
struct V_20 * V_21 ;
int V_45 ;
strcpy ( V_46 , V_47 ) ;
V_44 = F_7 ( V_13 , V_48 , F_14 () , V_49 ,
V_50 , ( void * ) V_46 ,
strlen ( V_47 ) + 1 ) ;
if ( V_44 < 0 )
return 0 ;
V_45 = F_15 ( V_13 , & V_42 , sizeof( V_42 ) , 0 ) ;
if ( V_42 . V_28 . V_14 == V_51 ||
( V_45 < 0 ) || ! F_16 ( ( & V_42 . V_28 ) , V_45 ) )
return 0 ;
V_21 = (struct V_20 * ) F_9 ( & V_42 ) ;
V_21 = (struct V_20 * ) ( ( char * ) V_21 + F_17 ( V_21 -> V_19 ) ) ;
if ( V_21 -> V_17 == V_52 ) {
V_43 = * ( T_1 * ) F_10 ( V_21 ) ;
}
return V_43 ;
}
static void F_18 ( struct V_53 * V_54 )
{
printf ( L_9
L_10
L_11
L_12
L_13
L_12
L_14
L_12 ,
L_15 , L_16 , L_17 ,
L_18 , L_19 ,
( unsigned long long ) V_54 -> V_55 ,
( unsigned long long ) V_54 -> V_56 ,
( unsigned long long ) V_54 -> V_57 ,
( unsigned long long ) V_54 -> V_58 ,
F_19 ( ( double ) V_54 -> V_58 , V_54 -> V_55 ) ,
L_15 , L_18 , L_19 ,
( unsigned long long ) V_54 -> V_59 ,
( unsigned long long ) V_54 -> V_60 ,
F_19 ( V_54 -> V_60 , V_54 -> V_59 ) ,
L_15 , L_18 , L_19 ,
( unsigned long long ) V_54 -> V_61 ,
( unsigned long long ) V_54 -> V_62 ,
F_19 ( V_54 -> V_62 , V_54 -> V_61 ) ,
L_15 , L_18 , L_19 ,
( unsigned long long ) V_54 -> V_63 ,
( unsigned long long ) V_54 -> V_64 ,
F_19 ( V_54 -> V_64 , V_54 -> V_63 ) ) ;
}
static void F_20 ( struct V_53 * V_54 )
{
printf ( L_20
L_21 ,
L_22 , L_23 ,
( unsigned long long ) V_54 -> V_65 , ( unsigned long long ) V_54 -> V_66 ) ;
}
static void F_21 ( struct V_67 * V_68 )
{
printf ( L_24
L_25 , ( unsigned long long ) V_68 -> V_69 ,
( unsigned long long ) V_68 -> V_70 ,
( unsigned long long ) V_68 -> V_71 ,
( unsigned long long ) V_68 -> V_72 ,
( unsigned long long ) V_68 -> V_73 ) ;
}
static void F_22 ( struct V_53 * V_54 )
{
printf ( L_26 ,
V_54 -> V_74 ,
( unsigned long long ) V_54 -> V_75 ,
( unsigned long long ) V_54 -> V_76 ,
( unsigned long long ) V_54 -> V_77 ) ;
}
int main ( int V_78 , char * V_79 [] )
{
int V_68 , V_44 , V_45 , V_80 , V_81 ;
int V_82 = V_83 ;
T_1 V_43 ;
T_2 V_84 ;
struct V_20 * V_21 ;
int V_85 = - 1 ;
int V_86 = 0 ;
T_4 V_87 = 0 ;
T_4 V_88 = 0 ;
int V_3 = 0 ;
int V_89 = 0 ;
int V_90 = 0 ;
int V_91 = 0 ;
char * V_92 = NULL ;
int V_93 = 0 ;
int V_94 = 0 ;
char V_95 [ 1024 ] ;
int V_96 = 0 ;
int V_97 = 0 ;
T_5 V_98 ;
struct V_26 V_27 ;
while ( ! V_97 ) {
V_68 = F_23 ( V_78 , V_79 , L_27 ) ;
if ( V_68 < 0 )
break;
switch ( V_68 ) {
case 'd' :
printf ( L_28 ) ;
V_99 = 1 ;
break;
case 'i' :
printf ( L_29 ) ;
V_100 = 1 ;
break;
case 'q' :
printf ( L_30 ) ;
V_101 = 1 ;
break;
case 'C' :
V_94 = 1 ;
strncpy ( V_95 , V_102 , strlen ( V_102 ) + 1 ) ;
break;
case 'w' :
V_92 = F_24 ( V_102 ) ;
printf ( L_31 , V_92 ) ;
V_90 = 1 ;
break;
case 'r' :
V_8 = atoi ( V_102 ) ;
printf ( L_32 , V_8 ) ;
if ( V_8 < 0 )
F_25 ( 1 , L_33 ) ;
break;
case 'm' :
strncpy ( V_103 , V_102 , sizeof( V_103 ) ) ;
V_91 = 1 ;
printf ( L_34 , V_103 , V_91 ) ;
break;
case 't' :
V_87 = atoi ( V_102 ) ;
if ( ! V_87 )
F_25 ( 1 , L_35 ) ;
V_82 = V_104 ;
break;
case 'p' :
V_87 = atoi ( V_102 ) ;
if ( ! V_87 )
F_25 ( 1 , L_36 ) ;
V_82 = V_105 ;
break;
case 'c' :
if ( F_26 ( & V_98 ) == - 1 )
F_25 ( 1 , L_37 ) ;
if ( F_27 ( & V_98 , V_106 ) )
F_25 ( 1 , L_38 ) ;
F_28 ( V_107 , & V_98 , NULL ) ;
V_87 = F_29 () ;
if ( V_87 < 0 )
F_25 ( 1 , L_39 ) ;
if ( V_87 == 0 )
if ( F_30 ( V_79 [ V_108 - 1 ] ,
& V_79 [ V_108 - 1 ] ) < 0 )
exit ( - 1 ) ;
V_82 = V_105 ;
V_97 = 1 ;
break;
case 'v' :
printf ( L_40 ) ;
V_109 = 1 ;
break;
case 'l' :
printf ( L_41 ) ;
V_93 = 1 ;
break;
default:
F_1 () ;
exit ( - 1 ) ;
}
}
if ( V_90 ) {
V_3 = F_31 ( V_92 , V_110 | V_111 | V_112 ,
V_113 | V_114 | V_115 | V_116 ) ;
if ( V_3 == - 1 ) {
perror ( L_42 ) ;
exit ( 1 ) ;
}
}
if ( ( V_85 = F_2 ( V_117 ) ) < 0 )
F_25 ( 1 , L_43 ) ;
V_84 = F_14 () ;
V_43 = F_13 ( V_85 ) ;
if ( ! V_43 ) {
fprintf ( V_1 , L_44 , V_38 ) ;
goto F_25;
}
PRINTF ( L_45 , V_43 ) ;
if ( V_91 ) {
V_44 = F_7 ( V_85 , V_43 , V_84 , V_118 ,
V_119 ,
& V_103 , strlen ( V_103 ) + 1 ) ;
PRINTF ( L_46 , V_44 ) ;
if ( V_44 < 0 ) {
fprintf ( V_1 , L_47 ) ;
goto F_25;
}
}
if ( V_87 && V_94 ) {
fprintf ( V_1 , L_48 ) ;
goto F_25;
}
if ( V_87 && V_97 ) {
int V_120 ;
F_32 ( & V_98 , & V_120 ) ;
}
if ( V_87 ) {
V_44 = F_7 ( V_85 , V_43 , V_84 , V_118 ,
V_82 , & V_87 , sizeof( T_2 ) ) ;
PRINTF ( L_49 , V_44 ) ;
if ( V_44 < 0 ) {
fprintf ( V_1 , L_50 ) ;
goto V_121;
}
}
if ( V_94 ) {
V_96 = F_31 ( V_95 , V_122 ) ;
if ( V_96 < 0 ) {
perror ( L_51 ) ;
goto F_25;
}
V_44 = F_7 ( V_85 , V_43 , V_84 , V_123 ,
V_124 , & V_96 , sizeof( T_2 ) ) ;
if ( V_44 < 0 ) {
perror ( L_52 ) ;
goto F_25;
}
}
if ( ! V_91 && ! V_87 && ! V_94 ) {
F_1 () ;
goto F_25;
}
do {
V_45 = F_15 ( V_85 , & V_27 , sizeof( V_27 ) , 0 ) ;
PRINTF ( L_53 , V_45 ) ;
if ( V_45 < 0 ) {
fprintf ( V_1 , L_54 ,
V_38 ) ;
continue;
}
if ( V_27 . V_28 . V_14 == V_51 ||
! F_16 ( ( & V_27 . V_28 ) , V_45 ) ) {
struct V_125 * F_25 = F_33 ( & V_27 ) ;
fprintf ( V_1 , L_55 ,
F_25 -> error ) ;
goto V_121;
}
PRINTF ( L_56 ,
sizeof( struct V_40 ) , V_27 . V_28 . V_29 , V_45 ) ;
V_45 = F_34 ( & V_27 . V_28 ) ;
V_21 = (struct V_20 * ) F_9 ( & V_27 ) ;
V_86 = 0 ;
while ( V_86 < V_45 ) {
V_86 += F_17 ( V_21 -> V_19 ) ;
switch ( V_21 -> V_17 ) {
case V_126 :
case V_127 :
V_80 = F_35 ( V_21 -> V_19 ) ;
V_81 = 0 ;
V_21 = (struct V_20 * ) F_10 ( V_21 ) ;
V_121 = 0 ;
while ( V_81 < V_80 ) {
switch ( V_21 -> V_17 ) {
case V_128 :
V_88 = * ( int * ) F_10 ( V_21 ) ;
if ( V_99 )
printf ( L_57 , V_88 ) ;
break;
case V_129 :
V_88 = * ( int * ) F_10 ( V_21 ) ;
if ( V_99 )
printf ( L_58 , V_88 ) ;
break;
case V_130 :
V_89 ++ ;
if ( V_99 )
F_18 ( (struct V_53 * ) F_10 ( V_21 ) ) ;
if ( V_100 )
F_22 ( (struct V_53 * ) F_10 ( V_21 ) ) ;
if ( V_101 )
F_20 ( (struct V_53 * ) F_10 ( V_21 ) ) ;
if ( V_3 ) {
if ( F_36 ( V_3 , F_10 ( V_21 ) , V_21 -> V_19 ) < 0 ) {
F_25 ( 1 , L_59 ) ;
}
}
if ( ! V_93 )
goto V_121;
break;
default:
fprintf ( V_1 , L_60
L_61 ,
V_21 -> V_17 ) ;
break;
}
V_81 += F_17 ( V_21 -> V_19 ) ;
V_21 = (struct V_20 * ) ( ( char * ) V_21 + V_81 ) ;
}
break;
case V_131 :
F_21 ( F_10 ( V_21 ) ) ;
break;
default:
fprintf ( V_1 , L_62 ,
V_21 -> V_17 ) ;
case V_132 :
break;
}
V_21 = (struct V_20 * ) ( F_9 ( & V_27 ) + V_86 ) ;
}
} while ( V_93 );
V_121:
if ( V_91 ) {
V_44 = F_7 ( V_85 , V_43 , V_84 , V_118 ,
V_133 ,
& V_103 , strlen ( V_103 ) + 1 ) ;
printf ( L_63 , V_44 ) ;
if ( V_44 < 0 )
F_25 ( V_44 , L_64 ) ;
}
F_25:
F_6 ( V_85 ) ;
if ( V_3 )
F_6 ( V_3 ) ;
if ( V_96 )
F_6 ( V_96 ) ;
return 0 ;
}
