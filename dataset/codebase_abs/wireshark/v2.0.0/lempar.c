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
static int F_8 ( T_2 * V_10 ) {
T_5 V_15 ;
T_3 * V_18 = & V_10 -> V_9 [ V_10 -> V_11 ] ;
if( V_10 -> V_11 < 0 ) return 0 ;
#ifndef F_3
if( V_3 && V_10 -> V_11 >= 0 ) {
fprintf ( V_3 , L_2 ,
V_4 ,
V_19 [ V_18 -> V_20 ] ) ;
}
#endif
V_15 = V_18 -> V_20 ;
F_7 ( V_10 , V_15 , & V_18 -> V_21 ) ;
V_10 -> V_11 -- ;
return V_15 ;
}
void F_9 (
void * V_5 ,
void (* F_10)( void * )
) {
T_2 * V_10 = ( T_2 * ) V_5 ;
if( V_10 == 0 ) return;
while( V_10 -> V_11 >= 0 ) F_8 ( V_10 ) ;
#if V_13 <= 0
free ( V_10 -> V_9 ) ;
#endif
(* F_10)( ( void * ) V_10 ) ;
}
int F_11 ( void * V_5 ) {
T_2 * V_10 = ( T_2 * ) V_5 ;
return V_10 -> V_12 ;
}
static int F_12 (
T_2 * V_10 ,
T_5 V_22
) {
int V_23 ;
int V_24 = V_10 -> V_9 [ V_10 -> V_11 ] . V_24 ;
if( V_24 > V_25
|| ( V_23 = V_26 [ V_24 ] ) == V_27 ) {
return V_28 [ V_24 ] ;
}
assert ( V_22 != V_29 ) ;
V_23 += V_22 ;
if( V_23 < 0 || V_23 >= V_30 || V_31 [ V_23 ] != V_22 ) {
if( V_22 > 0 ) {
#ifdef F_13
T_5 V_32 ;
if( V_22 < sizeof( V_33 ) / sizeof( V_33 [ 0 ] )
&& ( V_32 = V_33 [ V_22 ] ) != 0 ) {
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_3 ,
V_4 , V_19 [ V_22 ] , V_19 [ V_32 ] ) ;
}
#endif
return F_12 ( V_10 , V_32 ) ;
}
#endif
#ifdef F_14
{
int V_34 = V_23 - V_22 + F_14 ;
if(
#if V_35 + F_14 < 0
V_34 >= 0 &&
#endif
#if V_36 + F_14 >= V_30
V_34 < V_30 &&
#endif
V_31 [ V_34 ] == F_14
) {
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_4 ,
V_4 , V_19 [ V_22 ] , V_19 [ F_14 ] ) ;
}
#endif
return V_37 [ V_34 ] ;
}
}
#endif
}
return V_28 [ V_24 ] ;
} else{
return V_37 [ V_23 ] ;
}
}
static int F_15 (
int V_24 ,
T_5 V_22
) {
int V_23 ;
#ifdef F_16
if( V_24 > V_38 ) {
return V_28 [ V_24 ] ;
}
#else
assert ( V_24 <= V_38 ) ;
#endif
V_23 = V_39 [ V_24 ] ;
assert ( V_23 != V_40 ) ;
assert ( V_22 != V_29 ) ;
V_23 += V_22 ;
#ifdef F_16
if( V_23 < 0 || V_23 >= V_30 || V_31 [ V_23 ] != V_22 ) {
return V_28 [ V_24 ] ;
}
#else
assert ( V_23 >= 0 && V_23 < V_30 ) ;
assert ( V_31 [ V_23 ] == V_22 ) ;
#endif
return V_37 [ V_23 ] ;
}
static void F_17 ( T_2 * V_14 , T_6 * T_7 V_41 ) {
V_17 ;
V_14 -> V_11 -- ;
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_5 , V_4 ) ;
}
#endif
while( V_14 -> V_11 >= 0 ) F_8 ( V_14 ) ;
% %
V_42 ;
}
static void F_18 (
T_2 * V_14 ,
int V_43 ,
int V_44 ,
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
F_17 ( V_14 , T_7 ) ;
return;
}
#else
if( V_14 -> V_11 >= V_14 -> V_8 ) {
F_2 ( V_14 ) ;
if( V_14 -> V_11 >= V_14 -> V_8 ) {
F_17 ( V_14 , T_7 ) ;
return;
}
}
#endif
V_18 = & V_14 -> V_9 [ V_14 -> V_11 ] ;
V_18 -> V_24 = ( V_45 ) V_43 ;
V_18 -> V_20 = ( T_5 ) V_44 ;
V_18 -> V_21 = * T_7 ;
#ifndef F_3
if( V_3 && V_14 -> V_11 > 0 ) {
int V_23 ;
fprintf ( V_3 , L_6 , V_4 , V_43 ) ;
fprintf ( V_3 , L_7 , V_4 ) ;
for( V_23 = 1 ; V_23 <= V_14 -> V_11 ; V_23 ++ )
fprintf ( V_3 , L_8 , V_19 [ V_14 -> V_9 [ V_23 ] . V_20 ] ) ;
fprintf ( V_3 , L_9 ) ;
}
#endif
}
static void F_19 (
T_2 * V_14 ,
int V_46
) {
int V_47 ;
int V_48 ;
T_6 V_49 ;
T_3 * V_50 ;
int V_51 ;
V_17 ;
V_50 = & V_14 -> V_9 [ V_14 -> V_11 ] ;
#ifndef F_3
if( V_3 && V_46 >= 0
&& V_46 < ( int ) ( sizeof( V_52 ) / sizeof( V_52 [ 0 ] ) ) ) {
fprintf ( V_3 , L_10 , V_4 ,
V_52 [ V_46 ] ) ;
}
#endif
V_49 = V_53 ;
switch( V_46 ) {
% %
} ;
V_47 = V_54 [ V_46 ] . V_55 ;
V_51 = V_54 [ V_46 ] . V_56 ;
V_14 -> V_11 -= V_51 ;
V_48 = F_15 ( V_50 [ - V_51 ] . V_24 , ( T_5 ) V_47 ) ;
if( V_48 < V_57 ) {
#ifdef F_3
if( V_51 ) {
V_14 -> V_11 ++ ;
V_50 -= V_51 - 1 ;
V_50 -> V_24 = ( V_45 ) V_48 ;
V_50 -> V_20 = ( T_5 ) V_47 ;
V_50 -> V_21 = V_49 ;
} else
#endif
{
F_18 ( V_14 , V_48 , V_47 , & V_49 ) ;
}
} else{
assert ( V_48 == V_57 + V_58 + 1 ) ;
F_20 ( V_14 ) ;
}
}
static void F_21 (
T_2 * V_14
) {
V_17 ;
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_11 , V_4 ) ;
}
#endif
while( V_14 -> V_11 >= 0 ) F_8 ( V_14 ) ;
% %
V_42 ;
}
static void F_22 (
T_2 * V_14 ,
int V_15 V_41 ,
T_6 V_59
) {
V_17 ;
#define F_23 (yyminor.yy0)
% %
V_42 ;
}
static void F_20 (
T_2 * V_14
) {
V_17 ;
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_12 , V_4 ) ;
}
#endif
while( V_14 -> V_11 >= 0 ) F_8 ( V_14 ) ;
% %
V_42 ;
}
void F_24 (
void * V_60 ,
int V_15 ,
T_8 V_59
V_61
) {
T_6 V_62 ;
int V_48 ;
int V_63 ;
#ifdef F_16
int V_64 = 0 ;
#endif
T_2 * V_14 ;
V_14 = ( T_2 * ) V_60 ;
if( V_14 -> V_11 < 0 ) {
#if V_13 <= 0
if( V_14 -> V_8 <= 0 ) {
V_62 = V_53 ;
F_17 ( V_14 , & V_62 ) ;
return;
}
#endif
V_14 -> V_11 = 0 ;
V_14 -> V_65 = - 1 ;
V_14 -> V_9 [ 0 ] . V_24 = 0 ;
V_14 -> V_9 [ 0 ] . V_20 = 0 ;
}
V_62 . V_66 = V_59 ;
V_63 = ( V_15 == 0 ) ;
V_42 ;
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_13 , V_4 , V_19 [ V_15 ] ) ;
}
#endif
do{
V_48 = F_12 ( V_14 , ( T_5 ) V_15 ) ;
if( V_48 < V_57 ) {
assert ( ! V_63 ) ;
F_18 ( V_14 , V_48 , V_15 , & V_62 ) ;
V_14 -> V_65 -- ;
V_15 = V_29 ;
} else if( V_48 < V_57 + V_58 ) {
F_19 ( V_14 , V_48 - V_57 ) ;
} else{
assert ( V_48 == V_67 ) ;
#ifdef F_16
int V_68 ;
#endif
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_14 , V_4 ) ;
}
#endif
#ifdef F_16
if( V_14 -> V_65 < 0 ) {
F_22 ( V_14 , V_15 , V_62 ) ;
}
V_68 = V_14 -> V_9 [ V_14 -> V_11 ] . V_20 ;
if( V_68 == F_16 || V_64 ) {
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_15 ,
V_4 , V_19 [ V_15 ] ) ;
}
#endif
F_7 ( V_14 , ( T_5 ) V_15 , & V_62 ) ;
V_15 = V_29 ;
} else{
while(
V_14 -> V_11 >= 0 &&
V_68 != F_16 &&
( V_48 = F_15 (
V_14 -> V_9 [ V_14 -> V_11 ] . V_24 ,
F_16 ) ) >= V_57
) {
F_8 ( V_14 ) ;
}
if( V_14 -> V_11 < 0 || V_15 == 0 ) {
F_7 ( V_14 , ( T_5 ) V_15 , & V_62 ) ;
F_21 ( V_14 ) ;
V_15 = V_29 ;
} else if( V_68 != F_16 ) {
T_6 V_69 ;
V_69 . V_70 = 0 ;
F_18 ( V_14 , V_48 , F_16 , & V_69 ) ;
}
}
V_14 -> V_65 = 3 ;
V_64 = 1 ;
#elif F_25 ( V_71 )
F_22 ( V_14 , V_15 , V_62 ) ;
F_7 ( V_14 , ( T_5 ) V_15 , & V_62 ) ;
V_15 = V_29 ;
#else
if( V_14 -> V_65 <= 0 ) {
F_22 ( V_14 , V_15 , V_62 ) ;
}
V_14 -> V_65 = 3 ;
F_7 ( V_14 , ( T_5 ) V_15 , & V_62 ) ;
if( V_63 ) {
F_21 ( V_14 ) ;
}
V_15 = V_29 ;
#endif
}
}while( V_15 != V_29 && V_14 -> V_11 >= 0 );
return;
}
