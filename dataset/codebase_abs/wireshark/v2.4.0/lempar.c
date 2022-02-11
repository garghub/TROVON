void F_1 ( T_1 * V_1 , char * V_2 ) {
V_3 = V_1 ;
V_4 = V_2 ;
if( V_3 == 0 ) V_4 = 0 ;
else if( V_4 == 0 ) V_3 = 0 ;
}
static int F_2 ( T_2 * V_5 ) {
int V_6 ;
int V_7 ;
T_3 * V_8 ;
V_6 = V_5 -> V_9 * 2 + 100 ;
V_7 = V_5 -> V_10 ? ( int ) ( V_5 -> V_10 - V_5 -> V_11 ) : 0 ;
if( V_5 -> V_11 == & V_5 -> V_12 ) {
V_8 = malloc ( V_6 * sizeof( V_8 [ 0 ] ) ) ;
if( V_8 ) V_8 [ 0 ] = V_5 -> V_12 ;
} else{
V_8 = realloc ( V_5 -> V_11 , V_6 * sizeof( V_8 [ 0 ] ) ) ;
}
if( V_8 ) {
V_5 -> V_11 = V_8 ;
V_5 -> V_10 = & V_5 -> V_11 [ V_7 ] ;
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_1 ,
V_4 , V_5 -> V_9 , V_6 ) ;
}
#endif
V_5 -> V_9 = V_6 ;
}
return V_8 == 0 ;
}
static void F_4 ( void * V_13 ) {
T_2 * V_14 = ( T_2 * ) V_13 ;
#ifdef F_5
V_14 -> V_15 = 0 ;
#endif
#if V_16 <= 0
V_14 -> V_10 = NULL ;
V_14 -> V_11 = NULL ;
V_14 -> V_9 = 0 ;
if( F_2 ( V_14 ) ) {
V_14 -> V_11 = & V_14 -> V_12 ;
V_14 -> V_9 = 1 ;
}
#endif
#ifndef F_6
V_14 -> V_17 = - 1 ;
#endif
V_14 -> V_10 = V_14 -> V_11 ;
V_14 -> V_11 [ 0 ] . V_18 = 0 ;
V_14 -> V_11 [ 0 ] . V_19 = 0 ;
}
void * F_7 ( void * (* F_8)( T_4 ) ) {
T_2 * V_14 ;
V_14 = ( T_2 * ) (* F_8)( ( T_4 ) sizeof( T_2 ) ) ;
if( V_14 ) F_4 ( V_14 ) ;
return V_14 ;
}
static void F_9 (
T_2 * V_13 ,
T_5 V_20 ,
T_6 * V_21
) {
V_22 ;
switch( V_20 ) {
% %
default: break;
}
}
static void F_10 ( T_2 * V_14 ) {
T_3 * V_10 ;
assert ( V_14 -> V_10 != 0 ) ;
assert ( V_14 -> V_10 > V_14 -> V_11 ) ;
V_10 = V_14 -> V_10 -- ;
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_2 ,
V_4 ,
V_23 [ V_10 -> V_19 ] ) ;
}
#endif
F_9 ( V_14 , V_10 -> V_19 , & V_10 -> V_24 ) ;
}
static void F_11 ( void * V_5 ) {
T_2 * V_14 = ( T_2 * ) V_5 ;
while( V_14 -> V_10 > V_14 -> V_11 ) F_10 ( V_14 ) ;
#if V_16 <= 0
if( V_14 -> V_11 != & V_14 -> V_12 ) free ( V_14 -> V_11 ) ;
#endif
}
void F_12 (
void * V_5 ,
void (* F_13)( void * )
) {
#ifndef F_14
if( V_5 == 0 ) return;
#endif
F_11 ( V_5 ) ;
(* F_13)( V_5 ) ;
}
int F_15 ( void * V_5 ) {
T_2 * V_14 = ( T_2 * ) V_5 ;
return V_14 -> V_15 ;
}
static unsigned int F_16 (
T_2 * V_14 ,
T_5 V_25
) {
int V_26 ;
int V_18 = V_14 -> V_10 -> V_18 ;
if( V_18 >= V_27 ) return V_18 ;
assert ( V_18 <= V_28 ) ;
do{
V_26 = V_29 [ V_18 ] ;
assert ( V_25 != V_30 ) ;
V_26 += V_25 ;
if( V_26 < 0 || V_26 >= V_31 || V_32 [ V_26 ] != V_25 ) {
#ifdef F_17
T_5 V_33 ;
if( V_25 < sizeof( V_34 ) / sizeof( V_34 [ 0 ] )
&& ( V_33 = V_34 [ V_25 ] ) != 0 ) {
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_3 ,
V_4 , V_23 [ V_25 ] , V_23 [ V_33 ] ) ;
}
#endif
assert ( V_34 [ V_33 ] == 0 ) ;
V_25 = V_33 ;
continue;
}
#endif
#ifdef F_18
{
int V_35 = V_26 - V_25 + F_18 ;
if(
#if V_36 + F_18 < 0
V_35 >= 0 &&
#endif
#if V_37 + F_18 >= V_31
V_35 < V_31 &&
#endif
V_32 [ V_35 ] == F_18 && V_25 > 0
) {
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_4 ,
V_4 , V_23 [ V_25 ] ,
V_23 [ F_18 ] ) ;
}
#endif
return V_38 [ V_35 ] ;
}
}
#endif
return V_39 [ V_18 ] ;
} else{
return V_38 [ V_26 ] ;
}
}while( 1 );
}
static int F_19 (
int V_18 ,
T_5 V_25
) {
int V_26 ;
#ifdef F_20
if( V_18 > V_40 ) {
return V_39 [ V_18 ] ;
}
#else
assert ( V_18 <= V_40 ) ;
#endif
V_26 = V_41 [ V_18 ] ;
assert ( V_26 != V_42 ) ;
assert ( V_25 != V_30 ) ;
V_26 += V_25 ;
#ifdef F_20
if( V_26 < 0 || V_26 >= V_31 || V_32 [ V_26 ] != V_25 ) {
return V_39 [ V_18 ] ;
}
#else
assert ( V_26 >= 0 && V_26 < V_31 ) ;
assert ( V_32 [ V_26 ] == V_25 ) ;
#endif
return V_38 [ V_26 ] ;
}
static void F_21 ( T_2 * V_13 ) {
V_22 ;
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_5 , V_4 ) ;
}
#endif
while( V_13 -> V_10 > V_13 -> V_11 ) F_10 ( V_13 ) ;
% %
V_43 ;
}
static void F_22 ( T_2 * V_13 , int V_44 ) {
if( V_3 ) {
if( V_44 < V_45 ) {
fprintf ( V_3 , L_6 ,
V_4 , V_23 [ V_13 -> V_10 -> V_19 ] ,
V_44 ) ;
} else{
fprintf ( V_3 , L_7 ,
V_4 , V_23 [ V_13 -> V_10 -> V_19 ] ) ;
}
}
}
static void F_23 (
T_2 * V_13 ,
int V_44 ,
int V_46 ,
T_7 V_47
) {
T_3 * V_10 ;
V_13 -> V_10 ++ ;
#ifdef F_5
if( ( int ) ( V_13 -> V_10 - V_13 -> V_11 ) > V_13 -> V_15 ) {
V_13 -> V_15 ++ ;
assert ( V_13 -> V_15 == ( int ) ( V_13 -> V_10 - V_13 -> V_11 ) ) ;
}
#endif
#if V_16 > 0
if( V_13 -> V_10 >= & V_13 -> V_11 [ V_16 ] ) {
V_13 -> V_10 -- ;
F_21 ( V_13 ) ;
return;
}
#else
if( V_13 -> V_10 >= & V_13 -> V_11 [ V_13 -> V_9 ] ) {
if( F_2 ( V_13 ) ) {
V_13 -> V_10 -- ;
F_21 ( V_13 ) ;
return;
}
}
#endif
if( V_44 > V_48 ) {
V_44 += V_27 - V_49 ;
}
V_10 = V_13 -> V_10 ;
V_10 -> V_18 = ( V_50 ) V_44 ;
V_10 -> V_19 = ( T_5 ) V_46 ;
V_10 -> V_24 . V_51 = V_47 ;
F_22 ( V_13 , V_44 ) ;
}
static void F_24 (
T_2 * V_13 ,
unsigned int V_52
) {
int V_53 ;
int V_54 ;
T_3 * V_55 ;
int V_56 ;
V_22 ;
V_55 = V_13 -> V_10 ;
#ifndef F_3
if( V_3 && V_52 < ( int ) ( sizeof( V_57 ) / sizeof( V_57 [ 0 ] ) ) ) {
V_56 = V_58 [ V_52 ] . V_59 ;
fprintf ( V_3 , L_8 , V_4 ,
V_57 [ V_52 ] , V_55 [ - V_56 ] . V_18 ) ;
}
#endif
if( V_58 [ V_52 ] . V_59 == 0 ) {
#ifdef F_5
if( ( int ) ( V_13 -> V_10 - V_13 -> V_11 ) > V_13 -> V_15 ) {
V_13 -> V_15 ++ ;
assert ( V_13 -> V_15 == ( int ) ( V_13 -> V_10 - V_13 -> V_11 ) ) ;
}
#endif
#if V_16 > 0
if( V_13 -> V_10 >= & V_13 -> V_11 [ V_16 - 1 ] ) {
F_21 ( V_13 ) ;
return;
}
#else
if( V_13 -> V_10 >= & V_13 -> V_11 [ V_13 -> V_9 - 1 ] ) {
if( F_2 ( V_13 ) ) {
F_21 ( V_13 ) ;
return;
}
V_55 = V_13 -> V_10 ;
}
#endif
}
switch( V_52 ) {
% %
} ;
assert ( V_52 < sizeof( V_58 ) / sizeof( V_58 [ 0 ] ) ) ;
V_53 = V_58 [ V_52 ] . V_60 ;
V_56 = V_58 [ V_52 ] . V_59 ;
V_54 = F_19 ( V_55 [ - V_56 ] . V_18 , ( T_5 ) V_53 ) ;
if( V_54 <= V_61 ) {
if( V_54 > V_48 ) {
V_54 += V_27 - V_49 ;
}
V_55 -= V_56 - 1 ;
V_13 -> V_10 = V_55 ;
V_55 -> V_18 = ( V_50 ) V_54 ;
V_55 -> V_19 = ( T_5 ) V_53 ;
F_22 ( V_13 , V_54 ) ;
} else{
assert ( V_54 == V_62 ) ;
V_13 -> V_10 -= V_56 ;
F_25 ( V_13 ) ;
}
}
static void F_26 (
T_2 * V_13
) {
V_22 ;
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_9 , V_4 ) ;
}
#endif
while( V_13 -> V_10 > V_13 -> V_11 ) F_10 ( V_13 ) ;
% %
V_43 ;
}
static void F_27 (
T_2 * V_13 ,
int V_20 V_63 ,
T_7 V_64
) {
V_22 ;
#define F_28 yyminor
% %
V_43 ;
}
static void F_25 (
T_2 * V_13
) {
V_22 ;
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_10 , V_4 ) ;
}
#endif
#ifndef F_6
V_13 -> V_17 = - 1 ;
#endif
assert ( V_13 -> V_10 == V_13 -> V_11 ) ;
% %
V_43 ;
}
void F_29 (
void * V_65 ,
int V_20 ,
T_7 V_64
V_66
) {
T_6 V_67 ;
unsigned int V_54 ;
#if ! F_30 ( F_20 ) && ! F_30 ( F_6 )
int V_68 ;
#endif
#ifdef F_20
int V_69 = 0 ;
#endif
T_2 * V_13 ;
V_13 = ( T_2 * ) V_65 ;
assert ( V_13 -> V_10 != 0 ) ;
#if ! F_30 ( F_20 ) && ! F_30 ( F_6 )
V_68 = ( V_20 == 0 ) ;
#endif
V_43 ;
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_11 , V_4 , V_23 [ V_20 ] ) ;
}
#endif
do{
V_54 = F_16 ( V_13 , ( T_5 ) V_20 ) ;
if( V_54 <= V_61 ) {
F_23 ( V_13 , V_54 , V_20 , V_64 ) ;
#ifndef F_6
V_13 -> V_17 -- ;
#endif
V_20 = V_30 ;
} else if( V_54 <= V_70 ) {
F_24 ( V_13 , V_54 - V_27 ) ;
} else{
assert ( V_54 == V_71 ) ;
V_67 . V_51 = V_64 ;
#ifdef F_20
int V_72 ;
#endif
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_12 , V_4 ) ;
}
#endif
#ifdef F_20
if( V_13 -> V_17 < 0 ) {
F_27 ( V_13 , V_20 , V_64 ) ;
}
V_72 = V_13 -> V_10 -> V_19 ;
if( V_72 == F_20 || V_69 ) {
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_13 ,
V_4 , V_23 [ V_20 ] ) ;
}
#endif
F_9 ( V_13 , ( T_5 ) V_20 , & V_67 ) ;
V_20 = V_30 ;
} else{
while( V_13 -> V_10 >= V_13 -> V_11
&& V_72 != F_20
&& ( V_54 = F_19 (
V_13 -> V_10 -> V_18 ,
F_20 ) ) >= V_27
) {
F_10 ( V_13 ) ;
}
if( V_13 -> V_10 < V_13 -> V_11 || V_20 == 0 ) {
F_9 ( V_13 , ( T_5 ) V_20 , & V_67 ) ;
F_26 ( V_13 ) ;
#ifndef F_6
V_13 -> V_17 = - 1 ;
#endif
V_20 = V_30 ;
} else if( V_72 != F_20 ) {
F_23 ( V_13 , V_54 , F_20 , V_64 ) ;
}
}
V_13 -> V_17 = 3 ;
V_69 = 1 ;
#elif F_30 ( F_6 )
F_27 ( V_13 , V_20 , V_64 ) ;
F_9 ( V_13 , ( T_5 ) V_20 , & V_67 ) ;
V_20 = V_30 ;
#else
if( V_13 -> V_17 <= 0 ) {
F_27 ( V_13 , V_20 , V_64 ) ;
}
V_13 -> V_17 = 3 ;
F_9 ( V_13 , ( T_5 ) V_20 , & V_67 ) ;
if( V_68 ) {
F_26 ( V_13 ) ;
#ifndef F_6
V_13 -> V_17 = - 1 ;
#endif
}
V_20 = V_30 ;
#endif
}
}while( V_20 != V_30 && V_13 -> V_10 > V_13 -> V_11 );
#ifndef F_3
if( V_3 ) {
T_3 * V_26 ;
char V_73 = '[' ;
fprintf ( V_3 , L_14 , V_4 ) ;
for( V_26 = & V_13 -> V_11 [ 1 ] ; V_26 <= V_13 -> V_10 ; V_26 ++ ) {
fprintf ( V_3 , L_15 , V_73 , V_23 [ V_26 -> V_19 ] ) ;
V_73 = ' ' ;
}
fprintf ( V_3 , L_16 ) ;
}
#endif
return;
}
