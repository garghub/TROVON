static void T_1 F_1 ( const char * V_1 , ... )
{
const char * V_2 , * V_3 , * V_4 ;
T_2 args ;
unsigned long V_5 ;
va_start ( args , V_1 ) ;
for ( V_2 = V_1 ; * V_2 != 0 ; V_2 = V_3 ) {
for ( V_3 = V_2 ; * V_3 != 0 && * V_3 != '\n' && * V_3 != '%' ; ++ V_3 )
;
if ( V_3 > V_2 )
F_2 ( V_2 , V_3 - V_2 ) ;
if ( * V_3 == 0 )
break;
if ( * V_3 == '\n' ) {
++ V_3 ;
F_3 () ;
F_4 ( L_1 ) ;
F_3 () ;
continue;
}
++ V_3 ;
if ( * V_3 == 0 )
break;
switch ( * V_3 ) {
case 's' :
++ V_3 ;
V_4 = va_arg ( args , const char * ) ;
if ( V_4 == NULL )
V_4 = L_2 ;
F_4 ( V_4 ) ;
break;
case 'x' :
++ V_3 ;
V_5 = va_arg (args, unsigned long) ;
F_5 ( V_5 ) ;
break;
}
}
}
static void T_1 F_1 ( const char * V_1 , ... ) {}
static void * T_1 F_6 ( unsigned long V_6 ,
unsigned long V_7 ,
char * V_8 )
{
struct V_9 * V_10 = (struct V_9 * ) ( V_6 + V_7 ) ;
T_3 * V_11 = & V_10 -> V_12 ;
while( * V_11 ) {
struct V_13 * V_14 =
(struct V_13 * ) ( V_6 + * V_11 ) ;
if ( strcmp ( ( char * ) ( ( unsigned long ) V_14 -> V_15 + V_6 ) ,
V_8 ) == 0 ) {
return ( void * ) ( ( unsigned long ) V_14 -> V_16 + V_6 ) ;
}
V_11 = & V_14 -> V_17 ;
}
return NULL ;
}
static unsigned long T_1 F_7 ( char * V_18 )
{
char * V_4 , * V_19 ;
V_4 = V_19 = ( char * ) V_20 ;
V_4 += 4 ;
while ( V_4 < ( char * ) V_21 ) {
if ( strcmp ( V_4 , V_18 ) == 0 )
return V_4 - V_19 ;
V_4 += strlen ( V_4 ) + 1 ;
}
return 0 ;
}
static void T_1 F_8 ( char * V_15 , void * V_22 , int V_23 ,
unsigned long * V_24 )
{
unsigned long V_25 = F_7 ( V_15 ) ;
if ( V_22 == NULL )
V_23 = 0 ;
if ( V_25 == 0 ) {
F_1 ( L_3 ,
V_15 ) ;
return;
}
if ( V_23 > 0x20000 ) {
F_1 ( L_4 ) ;
F_1 ( L_5 , V_15 , V_23 ) ;
return;
}
F_9 ( V_26 , V_24 ) ;
F_9 ( V_23 , V_24 ) ;
F_9 ( V_25 , V_24 ) ;
if ( V_23 && V_22 ) {
memcpy ( ( void * ) * V_24 , V_22 , V_23 ) ;
* V_24 = F_10 ( * V_24 + V_23 , 4 ) ;
}
}
static void T_1 F_11 ( unsigned long V_6 ,
unsigned long * V_24 )
{
T_3 V_27 ;
F_8 ( L_6 , NULL , 0 , V_24 ) ;
if ( V_28 -> V_29 ) {
char * args = ( char * ) ( ( unsigned long ) V_28 ) +
V_28 -> V_29 ;
F_8 ( L_7 , args , strlen ( args ) + 1 , V_24 ) ;
}
if ( V_28 -> V_30 ) {
V_27 = ( ( unsigned long ) V_28 ) + V_28 -> V_30 ;
F_8 ( L_8 , & V_27 , 4 , V_24 ) ;
V_27 += V_28 -> V_31 ;
F_8 ( L_9 , & V_27 , 4 , V_24 ) ;
}
if ( strlen ( V_32 ) )
F_8 ( L_10 , V_32 ,
strlen ( V_32 ) + 1 , V_24 ) ;
}
static void T_1 F_12 ( unsigned long V_6 ,
unsigned long * V_24 ,
int V_33 )
{
T_4 * V_34 = V_28 ;
T_3 V_35 ;
if ( V_33 ) {
F_8 ( L_11 , NULL , 0 , V_24 ) ;
F_8 ( L_12 , NULL , 0 , V_24 ) ;
} else
F_8 ( L_13 , NULL , 0 , V_24 ) ;
V_35 = V_34 -> V_36 ;
F_8 ( L_14 , & V_35 , 4 , V_24 ) ;
V_35 = V_34 -> V_37 [ 2 ] - V_34 -> V_37 [ 0 ] ;
F_8 ( L_15 , & V_35 , 4 , V_24 ) ;
V_35 = V_34 -> V_37 [ 3 ] - V_34 -> V_37 [ 1 ] ;
F_8 ( L_16 , & V_35 , 4 , V_24 ) ;
V_35 = V_34 -> V_38 ;
F_8 ( L_17 , & V_35 , 4 , V_24 ) ;
V_35 = ( T_3 ) V_34 -> V_39 ;
if ( V_35 == 0 )
V_35 = ( T_3 ) V_34 -> V_40 ;
V_35 += V_34 -> V_37 [ 1 ] * V_34 -> V_38 ;
V_35 += V_34 -> V_37 [ 0 ] * ( ( V_34 -> V_36 + 7 ) / 8 ) ;
F_8 ( L_18 , & V_35 , 4 , V_24 ) ;
}
static void T_1 F_13 ( char * V_4 , unsigned long * V_24 )
{
unsigned int V_41 = strlen ( V_4 ) + 1 ;
memcpy ( ( void * ) * V_24 , V_4 , V_41 ) ;
V_21 = * V_24 = * V_24 + V_41 ;
}
static void T_1 F_14 ( unsigned long V_6 ,
unsigned long V_7 ,
unsigned long * V_24 )
{
struct V_9 * V_10 = (struct V_9 * ) ( V_6 + V_7 ) ;
T_3 * V_42 , * V_11 = & V_10 -> V_12 ;
unsigned long V_25 ;
char * V_43 ;
V_43 = V_10 -> V_44 ? ( char * ) ( V_6 + V_10 -> V_44 ) : NULL ;
if ( V_43 == NULL ) {
F_1 ( L_19 ) ;
V_43 = L_20 ;
}
F_15 ( L_21 , V_43 ) ;
if ( ! strcmp ( V_43 , L_22 ) ) {
F_15 ( L_23 ) ;
F_13 ( L_6 , V_24 ) ;
F_13 ( L_10 , V_24 ) ;
F_13 ( L_8 , V_24 ) ;
F_13 ( L_9 , V_24 ) ;
F_13 ( L_7 , V_24 ) ;
V_45 = V_7 ;
}
if ( V_7 == V_28 -> V_46 ) {
F_15 ( L_24 ) ;
F_13 ( L_11 , V_24 ) ;
F_13 ( L_12 , V_24 ) ;
F_16 ( V_32 , V_43 , sizeof( V_32 ) ) ;
}
while ( * V_11 ) {
struct V_13 * V_14 =
(struct V_13 * ) ( V_6 + * V_11 ) ;
V_43 = V_14 -> V_15 ? ( char * ) ( V_6 + V_14 -> V_15 ) : NULL ;
if ( V_43 == NULL || strcmp ( V_43 , L_25 ) == 0 )
goto V_17;
V_25 = F_7 ( V_43 ) ;
if ( V_25 == 0 )
F_13 ( V_43 , V_24 ) ;
V_17:
V_11 = & V_14 -> V_17 ;
}
V_42 = & V_10 -> V_47 ;
while( * V_42 ) {
V_10 = (struct V_9 * ) ( V_6 + * V_42 ) ;
F_14 ( V_6 , * V_42 , V_24 ) ;
V_42 = & V_10 -> V_48 ;
}
}
static void T_1 F_17 ( unsigned long V_6 ,
unsigned long V_7 ,
unsigned long * V_24 )
{
struct V_9 * V_10 = (struct V_9 * ) ( V_6 + V_7 ) ;
T_3 * V_42 , * V_11 = & V_10 -> V_12 ;
char * V_43 , * V_2 , * V_49 , * V_50 ;
int V_41 ;
F_9 ( V_51 , V_24 ) ;
V_43 = V_10 -> V_44 ? ( char * ) ( V_6 + V_10 -> V_44 ) : NULL ;
if ( V_43 == NULL )
V_43 = L_20 ;
V_41 = strlen ( V_43 ) ;
F_15 ( L_26 , V_43 ) ;
memcpy ( ( void * ) * V_24 , V_43 , V_41 + 1 ) ;
V_43 = ( char * ) * V_24 ;
for ( V_50 = V_2 = V_43 , V_49 = V_43 + V_41 ; V_2 < V_49 ; V_2 ++ ) {
if ( * V_2 == '/' )
V_50 = V_43 ;
else if ( * V_2 != 0 )
* V_50 ++ = * V_2 ;
}
* V_50 = 0 ;
* V_24 = F_10 ( ( unsigned long ) V_50 + 1 , 4 ) ;
while ( * V_11 ) {
struct V_13 * V_14 =
(struct V_13 * ) ( V_6 + * V_11 ) ;
V_43 = V_14 -> V_15 ? ( char * ) ( V_6 + V_14 -> V_15 ) : NULL ;
if ( V_43 == NULL || ! strcmp ( V_43 , L_25 ) )
goto V_17;
if ( V_7 == V_45 && ! strcmp ( V_43 , L_7 ) )
goto V_17;
F_8 ( V_43 ,
V_14 -> V_16 ? ( void * ) ( V_6 + V_14 -> V_16 ) : NULL ,
V_14 -> V_52 , V_24 ) ;
V_17:
V_11 = & V_14 -> V_17 ;
}
if ( V_7 == V_45 ) {
F_11 ( V_6 , V_24 ) ;
if ( V_28 -> V_46 == 0 )
F_12 ( V_6 , V_24 , 0 ) ;
}
else if ( V_7 == V_28 -> V_46 )
F_12 ( V_6 , V_24 , 1 ) ;
V_42 = & V_10 -> V_47 ;
while( * V_42 ) {
V_10 = (struct V_9 * ) ( V_6 + * V_42 ) ;
F_17 ( V_6 , * V_42 , V_24 ) ;
V_42 = & V_10 -> V_48 ;
}
F_9 ( V_53 , V_24 ) ;
}
static unsigned long T_1 F_18 ( unsigned long V_54 )
{
T_4 * V_34 = V_28 ;
unsigned long V_55 , V_24 ;
struct V_56 * V_57 ;
unsigned long V_6 ;
T_5 * V_58 ;
V_55 = V_24 = F_10 ( ( ( unsigned long ) V_34 ) + V_54 , 4 ) ;
F_15 ( L_27 , V_55 ) ;
V_57 = (struct V_56 * ) V_55 ;
V_24 += sizeof( struct V_56 ) ;
V_58 = ( T_5 * ) ( F_10 ( V_24 , 8 ) ) ;
V_57 -> V_59 = ( ( unsigned long ) V_58 ) - V_55 ;
V_24 = ( ( unsigned long ) V_58 ) + 8 * sizeof( T_5 ) ;
V_6 = ( ( unsigned long ) V_34 ) + V_34 -> V_60 ;
F_15 ( L_28 , V_24 ) ;
F_15 ( L_29 , V_6 ) ;
V_20 = V_24 ;
V_24 += 4 ;
V_21 = V_24 ;
F_14 ( V_6 , 4 , & V_24 ) ;
F_13 ( L_13 , & V_24 ) ;
F_13 ( L_14 , & V_24 ) ;
F_13 ( L_15 , & V_24 ) ;
F_13 ( L_16 , & V_24 ) ;
F_13 ( L_17 , & V_24 ) ;
F_13 ( L_18 , & V_24 ) ;
V_57 -> V_61 = V_20 - V_55 ;
V_57 -> V_62 = V_21 - V_20 ;
V_24 = F_19 ( V_24 , 16 ) ;
F_15 ( L_30 , V_24 ) ;
V_57 -> V_63 = V_24 - V_55 ;
F_17 ( V_6 , 4 , & V_24 ) ;
F_9 ( V_64 , & V_24 ) ;
V_57 -> V_65 = 0 ;
V_57 -> V_66 = V_67 ;
V_57 -> V_68 = V_24 - V_55 ;
V_57 -> V_69 = V_70 ;
V_57 -> V_71 = 0x10 ;
V_24 = F_19 ( V_24 , V_72 ) ;
F_15 ( L_31 , V_24 ) ;
V_58 [ 0 ] = V_55 ;
V_58 [ 1 ] = V_24 ;
if ( V_28 -> V_30 ) {
V_58 [ 2 ] = ( ( unsigned long ) V_28 ) + V_28 -> V_30 ;
V_58 [ 3 ] = V_58 [ 2 ] + V_28 -> V_31 ;
V_58 [ 4 ] = 0 ;
V_58 [ 5 ] = 0 ;
} else {
V_58 [ 2 ] = 0 ;
V_58 [ 3 ] = 0 ;
}
return ( unsigned long ) V_57 ;
}
static void T_1 F_20 ( T_4 * V_34 )
{
unsigned long V_73 ;
unsigned long V_74 ;
F_1 ( L_32 V_75 L_33 ) ;
F_1 ( L_34 , V_76 ) ;
F_1 ( L_35 , V_34 -> V_39 ) ;
F_1 ( L_36 , V_34 -> V_40 ) ;
F_1 ( L_37 ) ;
F_1 ( L_38 , ( unsigned long ) V_77 ) ;
F_1 ( L_39 , V_34 ) ;
__asm__ __volatile__ ("mfmsr %0" : "=r" (flags));
F_1 ( L_40 , V_73 ) ;
__asm__ __volatile__ ("mfspr %0, 287" : "=r" (pvr));
F_1 ( L_41 , V_74 ) ;
V_74 >>= 16 ;
if ( V_74 > 1 ) {
__asm__ __volatile__ ("mfspr %0, 1008" : "=r" (flags));
F_1 ( L_42 , V_73 ) ;
}
if ( V_74 == 8 || V_74 == 12 || V_74 == 0x800c ) {
__asm__ __volatile__ ("mfspr %0, 1019" : "=r" (flags));
F_1 ( L_43 , V_73 ) ;
}
#ifdef F_21
F_1 ( L_44 ) ;
F_1 ( L_45 ,
V_34 -> V_60 ) ;
F_1 ( L_46 ,
V_34 -> V_78 ) ;
#endif
F_1 ( L_44 ) ;
}
void T_1 F_22 ( unsigned long V_79 , unsigned long V_80 )
{
T_4 * V_34 = ( T_4 * ) V_80 ;
unsigned long V_57 ;
unsigned long V_81 ;
unsigned long V_82 , V_83 ;
char * V_84 ;
unsigned long V_85 = F_23 () ;
F_24 ( V_85 ) ;
V_28 = V_34 ;
V_20 = V_21 = 0 ;
V_45 = 0 ;
V_32 [ 0 ] = 0 ;
if ( ! F_25 ( V_34 ) )
V_34 -> V_40 = V_34 -> V_39 ;
if ( V_34 -> V_36 == 16 )
V_34 -> V_36 = 15 ;
#ifdef F_26
V_82 = ( unsigned long ) V_34 -> V_40 ;
V_82 += V_34 -> V_37 [ 1 ] * V_34 -> V_38 ;
V_82 += V_34 -> V_37 [ 0 ] * ( ( V_34 -> V_36 + 7 ) / 8 ) ;
F_27 ( V_34 -> V_37 [ 2 ] - V_34 -> V_37 [ 0 ] ,
V_34 -> V_37 [ 3 ] - V_34 -> V_37 [ 1 ] ,
V_34 -> V_36 , V_34 -> V_38 ,
( unsigned long ) V_34 -> V_40 ) ;
F_28 () ;
F_29 () ;
#endif
if ( ! F_30 ( V_34 ) ) {
F_1 ( L_47
L_48 ) ;
for (; ; )
;
}
if ( V_34 -> V_86 != V_87 ) {
F_1 ( L_49
L_50 ) ;
for (; ; )
;
}
#ifdef F_26
F_20 ( V_34 ) ;
#endif
if ( V_34 -> V_69 < 4 ) {
V_84 = ( char * ) F_6 ( V_80 + V_34 -> V_60 ,
4 , L_51 ) ;
if ( V_84
&& ( strcmp ( V_84 , L_52 ) == 0
|| strcmp ( V_84 , L_53 ) == 0 ) ) {
F_1 ( L_54 ) ;
F_31 ( ( unsigned V_88 * ) 0x80880008 , 1 ) ;
}
}
if ( V_34 -> V_69 < 5 ) {
V_81 = V_34 -> V_60 + V_34 -> V_78 ;
if ( V_34 -> V_30 >= V_81 )
V_81 = V_34 -> V_30 + V_34 -> V_31 ;
} else
V_81 = V_34 -> V_89 ;
F_1 ( L_55 , V_81 ) ;
if ( V_34 -> V_69 < 4 ) {
F_1 ( L_56 ) ;
for ( V_82 = ( ( unsigned long ) & V_90 ) & V_91 ;
V_82 < ( unsigned long ) V_34 + V_81 ; V_82 += V_72 )
V_83 = * ( volatile unsigned long * ) V_82 ;
}
F_1 ( L_57 ) ;
V_57 = F_18 ( V_81 ) ;
#ifdef F_26
#ifdef F_32
F_1 ( L_58 ) ;
F_33 () ;
#else
F_34 () ;
#endif
#endif
F_24 ( - V_85 ) ;
F_35 ( V_57 , V_76 + V_85 , 0 ) ;
}
