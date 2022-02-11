void F_1 ( T_1 * V_1 , char * V_2 ) {
V_3 = V_1 ;
V_4 = V_2 ;
if( V_3 == 0 ) V_4 = 0 ;
else if( V_4 == 0 ) V_3 = 0 ;
}
static void F_2 ( T_2 * V_5 ) {
int V_6 ;
T_3 * V_7 ;
V_6 = V_5 -> V_8 * 2 + 100 ;
V_7 = realloc ( V_5 -> V_9 , V_6 * sizeof( V_7 [ 0 ] ) ) ;
if( V_7 ) {
V_5 -> V_9 = V_7 ;
V_5 -> V_8 = V_6 ;
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_1 ,
V_4 , V_5 -> V_8 ) ;
}
#endif
}
}
void * F_4 ( void * (* F_5)( T_4 ) ) {
T_2 * V_10 ;
V_10 = ( T_2 * ) (* F_5)( ( T_4 ) sizeof( T_2 ) ) ;
if( V_10 ) {
V_10 -> V_11 = - 1 ;
#ifdef F_6
V_10 -> V_12 = 0 ;
#endif
#if V_13 <= 0
V_10 -> V_9 = NULL ;
V_10 -> V_8 = 0 ;
F_2 ( V_10 ) ;
#endif
}
return V_10 ;
}
static void F_7 (
T_2 * V_14 ,
T_5 V_15 ,
T_6 * V_16
) {
V_17 ;
switch( V_15 ) {
% %
default: break;
}
}
static void F_8 ( T_2 * V_10 ) {
T_3 * V_18 ;
assert ( V_10 -> V_11 >= 0 ) ;
V_18 = & V_10 -> V_9 [ V_10 -> V_11 -- ] ;
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_2 ,
V_4 ,
V_19 [ V_18 -> V_20 ] ) ;
}
#endif
F_7 ( V_10 , V_18 -> V_20 , & V_18 -> V_21 ) ;
}
void F_9 (
void * V_5 ,
void (* F_10)( void * )
) {
T_2 * V_10 = ( T_2 * ) V_5 ;
#ifndef F_11
if( V_10 == 0 ) return;
#endif
while( V_10 -> V_11 >= 0 ) F_8 ( V_10 ) ;
#if V_13 <= 0
free ( V_10 -> V_9 ) ;
#endif
(* F_10)( ( void * ) V_10 ) ;
}
int F_12 ( void * V_5 ) {
T_2 * V_10 = ( T_2 * ) V_5 ;
return V_10 -> V_12 ;
}
static int F_13 (
T_2 * V_10 ,
T_5 V_22
) {
int V_23 ;
int V_24 = V_10 -> V_9 [ V_10 -> V_11 ] . V_24 ;
if( V_24 >= V_25 ) return V_24 ;
assert ( V_24 <= V_26 ) ;
do{
V_23 = V_27 [ V_24 ] ;
if( V_23 == V_28 ) return V_29 [ V_24 ] ;
assert ( V_22 != V_30 ) ;
V_23 += V_22 ;
if( V_23 < 0 || V_23 >= V_31 || V_32 [ V_23 ] != V_22 ) {
if( V_22 > 0 ) {
#ifdef F_14
T_5 V_33 ;
if( V_22 < sizeof( V_34 ) / sizeof( V_34 [ 0 ] )
&& ( V_33 = V_34 [ V_22 ] ) != 0 ) {
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_3 ,
V_4 , V_19 [ V_22 ] , V_19 [ V_33 ] ) ;
}
#endif
assert ( V_34 [ V_33 ] == 0 ) ;
V_22 = V_33 ;
continue;
}
#endif
#ifdef F_15
{
int V_35 = V_23 - V_22 + F_15 ;
if(
#if V_36 + F_15 < 0
V_35 >= 0 &&
#endif
#if V_37 + F_15 >= V_31
V_35 < V_31 &&
#endif
V_32 [ V_35 ] == F_15
) {
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_4 ,
V_4 , V_19 [ V_22 ] ,
V_19 [ F_15 ] ) ;
}
#endif
return V_38 [ V_35 ] ;
}
}
#endif
}
return V_29 [ V_24 ] ;
} else{
return V_38 [ V_23 ] ;
}
}while( 1 );
}
static int F_16 (
int V_24 ,
T_5 V_22
) {
int V_23 ;
#ifdef F_17
if( V_24 > V_39 ) {
return V_29 [ V_24 ] ;
}
#else
assert ( V_24 <= V_39 ) ;
#endif
V_23 = V_40 [ V_24 ] ;
assert ( V_23 != V_41 ) ;
assert ( V_22 != V_30 ) ;
V_23 += V_22 ;
#ifdef F_17
if( V_23 < 0 || V_23 >= V_31 || V_32 [ V_23 ] != V_22 ) {
return V_29 [ V_24 ] ;
}
#else
assert ( V_23 >= 0 && V_23 < V_31 ) ;
assert ( V_32 [ V_23 ] == V_22 ) ;
#endif
return V_38 [ V_23 ] ;
}
static void F_18 ( T_2 * V_14 , T_6 * T_7 V_42 ) {
V_17 ;
V_14 -> V_11 -- ;
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_5 , V_4 ) ;
}
#endif
while( V_14 -> V_11 >= 0 ) F_8 ( V_14 ) ;
% %
V_43 ;
}
static void F_19 ( T_2 * V_14 , int V_44 ) {
if( V_3 ) {
if( V_44 < V_45 ) {
fprintf ( V_3 , L_6 ,
V_4 , V_19 [ V_14 -> V_9 [ V_14 -> V_11 ] . V_20 ] ,
V_44 ) ;
} else{
fprintf ( V_3 , L_7 ,
V_4 , V_19 [ V_14 -> V_9 [ V_14 -> V_11 ] . V_20 ] ) ;
}
}
}
static void F_20 (
T_2 * V_14 ,
int V_44 ,
int V_46 ,
T_6 * T_7
) {
T_3 * V_18 ;
V_14 -> V_11 ++ ;
#ifdef F_6
if( V_14 -> V_11 > V_14 -> V_12 ) {
V_14 -> V_12 = V_14 -> V_11 ;
}
#endif
#if V_13 > 0
if( V_14 -> V_11 >= V_13 ) {
F_18 ( V_14 , T_7 ) ;
return;
}
#else
if( V_14 -> V_11 >= V_14 -> V_8 ) {
F_2 ( V_14 ) ;
if( V_14 -> V_11 >= V_14 -> V_8 ) {
F_18 ( V_14 , T_7 ) ;
return;
}
}
#endif
V_18 = & V_14 -> V_9 [ V_14 -> V_11 ] ;
V_18 -> V_24 = ( V_47 ) V_44 ;
V_18 -> V_20 = ( T_5 ) V_46 ;
V_18 -> V_21 = * T_7 ;
F_19 ( V_14 , V_44 ) ;
}
static void F_21 (
T_2 * V_14 ,
int V_48
) {
int V_49 ;
int V_50 ;
T_6 V_51 ;
T_3 * V_52 ;
int V_53 ;
V_17 ;
V_52 = & V_14 -> V_9 [ V_14 -> V_11 ] ;
#ifndef F_3
if( V_3 && V_48 >= 0
&& V_48 < ( int ) ( sizeof( V_54 ) / sizeof( V_54 [ 0 ] ) ) ) {
V_53 = V_55 [ V_48 ] . V_56 ;
fprintf ( V_3 , L_8 , V_4 ,
V_54 [ V_48 ] , V_52 [ - V_53 ] . V_24 ) ;
}
#endif
V_51 = V_57 ;
switch( V_48 ) {
% %
} ;
assert ( V_48 >= 0 && V_48 < ( int ) ( sizeof( V_55 ) / sizeof( V_55 [ 0 ] ) ) ) ;
V_49 = V_55 [ V_48 ] . V_58 ;
V_53 = V_55 [ V_48 ] . V_56 ;
V_14 -> V_11 -= V_53 ;
V_50 = F_16 ( V_52 [ - V_53 ] . V_24 , ( T_5 ) V_49 ) ;
if( V_50 <= V_59 ) {
if( V_50 > V_60 ) V_50 += V_25 - V_61 ;
if( V_53 ) {
V_14 -> V_11 ++ ;
V_52 -= V_53 - 1 ;
V_52 -> V_24 = ( V_47 ) V_50 ;
V_52 -> V_20 = ( T_5 ) V_49 ;
V_52 -> V_21 = V_51 ;
F_19 ( V_14 , V_50 ) ;
} else{
F_20 ( V_14 , V_50 , V_49 , & V_51 ) ;
}
} else{
assert ( V_50 == V_62 ) ;
F_22 ( V_14 ) ;
}
}
static void F_23 (
T_2 * V_14
) {
V_17 ;
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_9 , V_4 ) ;
}
#endif
while( V_14 -> V_11 >= 0 ) F_8 ( V_14 ) ;
% %
V_43 ;
}
static void F_24 (
T_2 * V_14 ,
int V_15 V_42 ,
T_6 V_63
) {
V_17 ;
#define F_25 (yyminor.yy0)
% %
V_43 ;
}
static void F_22 (
T_2 * V_14
) {
V_17 ;
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_10 , V_4 ) ;
}
#endif
while( V_14 -> V_11 >= 0 ) F_8 ( V_14 ) ;
% %
V_43 ;
}
void F_26 (
void * V_64 ,
int V_15 ,
T_8 V_63
V_65
) {
T_6 V_66 ;
int V_50 ;
#if ! F_27 ( F_17 ) && ! F_27 ( V_67 )
int V_68 ;
#endif
#ifdef F_17
int V_69 = 0 ;
#endif
T_2 * V_14 ;
V_14 = ( T_2 * ) V_64 ;
if( V_14 -> V_11 < 0 ) {
#if V_13 <= 0
if( V_14 -> V_8 <= 0 ) {
V_66 = V_57 ;
F_18 ( V_14 , & V_66 ) ;
return;
}
#endif
V_14 -> V_11 = 0 ;
V_14 -> V_70 = - 1 ;
V_14 -> V_9 [ 0 ] . V_24 = 0 ;
V_14 -> V_9 [ 0 ] . V_20 = 0 ;
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_11 ,
V_4 ) ;
}
#endif
}
V_66 . V_71 = V_63 ;
#if ! F_27 ( F_17 ) && ! F_27 ( V_67 )
V_68 = ( V_15 == 0 ) ;
#endif
V_43 ;
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_12 , V_4 , V_19 [ V_15 ] ) ;
}
#endif
do{
V_50 = F_13 ( V_14 , ( T_5 ) V_15 ) ;
if( V_50 <= V_59 ) {
if( V_50 > V_60 ) V_50 += V_25 - V_61 ;
F_20 ( V_14 , V_50 , V_15 , & V_66 ) ;
V_14 -> V_70 -- ;
V_15 = V_30 ;
} else if( V_50 <= V_72 ) {
F_21 ( V_14 , V_50 - V_25 ) ;
} else{
assert ( V_50 == V_73 ) ;
#ifdef F_17
int V_74 ;
#endif
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_13 , V_4 ) ;
}
#endif
#ifdef F_17
if( V_14 -> V_70 < 0 ) {
F_24 ( V_14 , V_15 , V_66 ) ;
}
V_74 = V_14 -> V_9 [ V_14 -> V_11 ] . V_20 ;
if( V_74 == F_17 || V_69 ) {
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_14 ,
V_4 , V_19 [ V_15 ] ) ;
}
#endif
F_7 ( V_14 , ( T_5 ) V_15 , & V_66 ) ;
V_15 = V_30 ;
} else{
while(
V_14 -> V_11 >= 0 &&
V_74 != F_17 &&
( V_50 = F_16 (
V_14 -> V_9 [ V_14 -> V_11 ] . V_24 ,
F_17 ) ) >= V_25
) {
F_8 ( V_14 ) ;
}
if( V_14 -> V_11 < 0 || V_15 == 0 ) {
F_7 ( V_14 , ( T_5 ) V_15 , & V_66 ) ;
F_23 ( V_14 ) ;
V_15 = V_30 ;
} else if( V_74 != F_17 ) {
T_6 V_75 ;
V_75 . V_76 = 0 ;
F_20 ( V_14 , V_50 , F_17 , & V_75 ) ;
}
}
V_14 -> V_70 = 3 ;
V_69 = 1 ;
#elif F_27 ( V_67 )
F_24 ( V_14 , V_15 , V_66 ) ;
F_7 ( V_14 , ( T_5 ) V_15 , & V_66 ) ;
V_15 = V_30 ;
#else
if( V_14 -> V_70 <= 0 ) {
F_24 ( V_14 , V_15 , V_66 ) ;
}
V_14 -> V_70 = 3 ;
F_7 ( V_14 , ( T_5 ) V_15 , & V_66 ) ;
if( V_68 ) {
F_23 ( V_14 ) ;
}
V_15 = V_30 ;
#endif
}
}while( V_15 != V_30 && V_14 -> V_11 >= 0 );
#ifndef F_3
if( V_3 ) {
int V_23 ;
fprintf ( V_3 , L_15 , V_4 ) ;
for( V_23 = 1 ; V_23 <= V_14 -> V_11 ; V_23 ++ )
fprintf ( V_3 , L_16 , V_23 == 1 ? '[' : ' ' ,
V_19 [ V_14 -> V_9 [ V_23 ] . V_20 ] ) ;
fprintf ( V_3 , L_17 ) ;
}
#endif
return;
}
