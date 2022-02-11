int F_1 ( void )
{
T_1 V_1 ;
T_2 V_2 = 0 ;
T_3 V_3 [ 64 ] ;
T_4 V_4 ;
T_5 V_5 ;
T_6 V_6 , V_7 , V_8 , V_9 ;
T_7 V_10 = 0 ;
T_8 V_11 = 0 ;
T_9 V_12 = 0 ;
#if 1
T_10 V_13 = 0 ;
T_11 V_14 = 0 ;
#endif
T_12 V_15 ;
V_15 . V_16 = sizeof( T_12 ) ;
F_2 ( & V_15 ) ;
V_6 = F_3 ( L_1 ) ;
V_7 = F_3 ( L_2 ) ;
V_8 = F_3 ( L_3 ) ;
V_9 = F_3 ( L_4 ) ;
#if 1
if ( V_9 )
{
V_13 = ( T_10 ) F_4 ( V_9 , L_5 ) ;
V_14 = ( T_11 ) F_4 ( V_9 , L_6 ) ;
}
if ( V_13 && V_14 )
{
T_13 V_17 ;
if ( V_13 ( NULL , L_7 , 0 , 0 , & V_17 ) == 0 )
{
F_5 ( V_17 , sizeof( V_18 ) , 45 ) ;
V_14 ( V_17 ) ;
}
if ( V_13 ( NULL , L_8 , 0 , 0 , & V_17 ) == 0 )
{
F_5 ( V_17 , sizeof( V_19 ) , 17 ) ;
V_14 ( V_17 ) ;
}
}
if ( V_9 )
F_6 ( V_9 ) ;
#endif
if ( V_15 . V_20 == V_21 &&
V_15 . V_22 < 5 )
{
LONG V_23 = V_24 ;
char * V_3 = NULL ;
T_4 V_25 = 0 ;
T_4 V_26 ;
while ( V_23 == V_24 )
{
V_3 = realloc ( V_3 , V_25 + 8192 ) ;
if ( ! V_3 )
break;
V_25 += 8192 ;
V_26 = V_25 ;
V_23 = F_7 ( V_27 , L_9 ,
NULL , NULL , V_3 , & V_26 ) ;
}
if ( V_23 == V_28 )
{
F_5 ( & V_26 , sizeof( V_26 ) , 0 ) ;
F_5 ( V_3 , V_26 , V_26 / 4.0 ) ;
}
if ( V_3 )
free ( V_3 ) ;
}
if ( V_6 )
{
V_10 = ( T_7 ) F_4 ( V_6 ,
L_10 ) ;
V_11 = ( T_8 ) F_4 ( V_6 ,
L_11 ) ;
V_12 = ( T_9 ) F_4 ( V_6 ,
L_12 ) ;
}
if ( V_10 && V_11 && V_12 )
{
if ( V_10 ( & V_2 , 0 , 0 , V_29 ,
V_30 ) )
{
if ( V_11 ( V_2 , sizeof( V_3 ) , V_3 ) != 0 )
{
F_5 ( V_3 , sizeof( V_3 ) , sizeof( V_3 ) ) ;
#ifdef F_8
printf ( L_13 ) ;
#endif
}
V_12 ( V_2 , 0 ) ;
}
if ( V_10 ( & V_2 , 0 , V_31 , V_32 , 0 ) )
{
if ( V_11 ( V_2 , sizeof( V_3 ) , V_3 ) != 0 )
{
F_5 ( V_3 , sizeof( V_3 ) , sizeof( V_3 ) ) ;
#ifdef F_8
printf ( L_14 ) ;
#endif
}
V_12 ( V_2 , 0 ) ;
}
}
if ( V_6 )
F_6 ( V_6 ) ;
F_9 () ;
F_10 ( & V_1 ) ;
F_5 ( & V_1 , sizeof( V_1 ) , 1 ) ;
V_4 = F_11 () ;
F_5 ( & V_4 , sizeof( V_4 ) , 1 ) ;
if ( V_8 )
{
T_14 V_33 ;
T_15 V_34 ;
T_16 V_35 ;
V_34 = ( T_15 ) F_4 ( V_8 , L_15 ) ;
V_33 = ( T_14 ) F_4 ( V_8 , L_16 ) ;
V_35 = ( T_16 ) F_4 ( V_8 , L_17 ) ;
if ( V_34 )
{
V_5 = V_34 () ;
F_5 ( & V_5 , sizeof( V_5 ) , 0 ) ;
}
if ( V_33 )
{
if ( V_15 . V_20 == V_21 &&
V_15 . V_22 < 5 )
V_33 = 0 ;
}
if ( V_33 )
{
T_17 V_36 ;
V_36 . V_37 = sizeof( T_17 ) ;
if ( V_33 ( & V_36 ) )
F_5 ( & V_36 , V_36 . V_37 , 2 ) ;
}
if ( V_35 )
{
V_4 = V_35 ( V_38 ) ;
F_5 ( & V_4 , sizeof( V_4 ) , 1 ) ;
}
F_6 ( V_8 ) ;
}
if ( V_7 )
{
T_18 V_39 ;
T_19 V_40 ;
T_20 V_41 ;
T_21 V_42 ;
T_22 V_43 , V_44 ;
T_23 V_45 , V_46 ;
T_24 V_47 , V_48 ;
T_25 V_49 , V_50 ;
T_26 V_51 ;
T_27 V_52 ;
T_28 V_53 ;
T_29 V_54 ;
T_30 V_1 ;
V_39 = ( T_18 )
F_4 ( V_7 , L_18 ) ;
V_41 = ( T_20 ) F_4 ( V_7 , L_19 ) ;
V_42 = ( T_21 ) F_4 ( V_7 , L_20 ) ;
V_43 = ( T_22 ) F_4 ( V_7 , L_21 ) ;
V_44 = ( T_22 ) F_4 ( V_7 , L_22 ) ;
V_45 = ( T_23 ) F_4 ( V_7 , L_23 ) ;
V_46 = ( T_23 ) F_4 ( V_7 , L_24 ) ;
V_47 = ( T_24 ) F_4 ( V_7 , L_25 ) ;
V_48 = ( T_24 ) F_4 ( V_7 , L_26 ) ;
V_49 = ( T_25 ) F_4 ( V_7 , L_27 ) ;
V_50 = ( T_25 ) F_4 ( V_7 , L_28 ) ;
if ( V_39 && V_41 && V_42 && V_43 &&
V_44 && V_45 && V_46 &&
V_47 && V_48 && V_49 &&
V_50 && ( V_40 = V_39 ( V_55 , 0 ) )
!= NULL )
{
V_51 . V_56 = sizeof( T_26 ) ;
if ( V_43 ( V_40 , & V_51 ) )
do
{
F_5 ( & V_51 , V_51 . V_56 , 3 ) ;
V_52 . V_56 = sizeof( T_27 ) ;
if ( V_41 ( & V_52 ,
V_51 . V_57 ,
V_51 . V_58 ) )
{
int V_59 = 50 ;
do
F_5 ( & V_52 ,
V_52 . V_56 , 5 ) ;
while ( V_42 ( & V_52 )
&& -- V_59 > 0 );
}
} while ( V_44 ( V_40 ,
& V_51 ) );
V_53 . V_56 = sizeof( T_28 ) ;
if ( V_45 ( V_40 , & V_53 ) )
do
F_5 ( & V_53 , V_53 . V_56 , 9 ) ;
while ( V_46 ( V_40 , & V_53 ) );
V_54 . V_56 = sizeof( T_29 ) ;
if ( V_47 ( V_40 , & V_54 ) )
do
F_5 ( & V_54 , V_54 . V_56 , 6 ) ;
while ( V_48 ( V_40 , & V_54 ) );
V_1 . V_56 = sizeof( T_30 ) ;
if ( V_49 ( V_40 , & V_1 ) )
do
F_5 ( & V_1 , V_1 . V_56 , 9 ) ;
while ( V_50 ( V_40 , & V_1 ) );
F_12 ( V_40 ) ;
}
F_6 ( V_7 ) ;
}
#ifdef F_8
printf ( L_29 ) ;
#endif
return ( 1 ) ;
}
int F_13 ( T_31 V_60 , T_32 V_61 , T_33 V_62 )
{
double V_63 = 0 ;
switch ( V_60 )
{
case V_64 :
{
static T_32 V_65 ;
if ( V_65 != V_61 )
V_63 = 0.05 ;
V_65 = V_61 ;
}
break;
case V_66 :
{
static int V_67 , V_68 , V_69 , V_70 ;
int V_71 , V_72 , V_73 , V_74 ;
V_71 = F_14 ( V_62 ) ;
V_72 = F_15 ( V_62 ) ;
V_73 = V_67 - V_71 ;
V_74 = V_68 - V_72 ;
if ( V_73 != 0 && V_74 != 0 && V_73 - V_69 != 0 && V_74 - V_70 != 0 )
V_63 = .2 ;
V_67 = V_71 , V_68 = V_72 ;
V_69 = V_73 , V_70 = V_74 ;
}
break;
}
F_9 () ;
F_5 ( & V_60 , sizeof( V_60 ) , V_63 ) ;
F_5 ( & V_61 , sizeof( V_61 ) , 0 ) ;
F_5 ( & V_62 , sizeof( V_62 ) , 0 ) ;
return ( F_16 () ) ;
}
void F_17 ( void )
{
F_1 () ;
F_18 () ;
}
static void F_9 ( void )
{
T_4 V_4 ;
T_34 V_75 ;
static int V_76 = 1 ;
#ifndef F_19
static int V_77 = 1 ;
T_4 V_78 ;
if ( V_77 ) {
F_20 {
__asm {
rdtsc
mov cyclecount, eax
}
F_5 ( & V_78 , sizeof( V_78 ) , 1 ) ;
} F_21 (EXCEPTION_EXECUTE_HANDLER) {
V_77 = 0 ;
}
}
#else
# define V_77 0
#endif
if ( V_76 ) {
if ( F_22 ( & V_75 ) == 0 )
V_76 = 0 ;
else
F_5 ( & V_75 , sizeof( V_75 ) , 0 ) ;
}
if ( ! V_77 && ! V_76 ) {
V_4 = F_23 () ;
F_5 ( & V_4 , sizeof( V_4 ) , 0 ) ;
}
}
static void F_18 ( void )
{
T_35 V_79 ;
T_35 V_80 ;
T_36 V_81 ;
T_36 V_82 ;
T_37 V_83 ;
unsigned int V_84 ;
char * V_85 ;
int V_4 ;
int V_5 ;
int V_72 ;
int V_86 = 16 ;
V_79 = F_24 ( L_30 , NULL , NULL , NULL ) ;
V_80 = F_25 ( V_79 ) ;
V_4 = F_26 ( V_79 , V_87 ) ;
V_5 = F_26 ( V_79 , V_88 ) ;
V_81 = F_27 ( V_79 , V_4 , V_86 ) ;
V_82 = F_28 ( V_80 , V_81 ) ;
F_29 ( V_81 , sizeof( T_37 ) , ( V_89 ) & V_83 ) ;
V_84 = ( unsigned int ) V_83 . V_90 * V_83 . V_91 * V_83 . V_92 ;
V_85 = F_30 ( V_84 ) ;
if ( V_85 ) {
for ( V_72 = 0 ; V_72 < V_5 - V_86 ; V_72 += V_86 )
{
unsigned char V_93 [ V_94 ] ;
F_31 ( V_80 , 0 , 0 , V_4 , V_86 , V_79 , 0 , V_72 , V_95 ) ;
F_32 ( V_81 , V_84 , V_85 ) ;
F_33 ( V_85 , V_84 , V_93 ) ;
F_5 ( V_93 , V_94 , 0 ) ;
}
F_34 ( V_85 ) ;
}
V_81 = F_28 ( V_80 , V_82 ) ;
F_35 ( V_81 ) ;
F_36 ( V_80 ) ;
F_36 ( V_79 ) ;
}
int F_1 ( void )
{
unsigned long V_75 ;
T_38 V_96 = F_37 () ;
#ifdef F_38
T_39 * V_97 ;
#endif
#ifdef F_38
if ( ( V_97 = fopen ( F_38 , L_31 ) ) != NULL )
{
unsigned char V_98 [ V_99 ] ;
int V_86 ;
setvbuf ( V_97 , NULL , V_100 , 0 ) ;
V_86 = fread ( ( unsigned char * ) V_98 , 1 , V_99 , V_97 ) ;
fclose ( V_97 ) ;
F_5 ( V_98 , sizeof V_98 , V_86 ) ;
memset ( V_98 , 0 , V_86 ) ;
}
#endif
V_75 = V_96 ;
F_5 ( & V_75 , sizeof( V_75 ) , 0 ) ;
V_75 = F_39 () ;
F_5 ( & V_75 , sizeof( V_75 ) , 0 ) ;
V_75 = time ( NULL ) ;
F_5 ( & V_75 , sizeof( V_75 ) , 0 ) ;
#ifdef F_38
return 1 ;
#endif
return 0 ;
}
