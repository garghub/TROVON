void F_1 ( T_1 * V_1 , char * V_2 ) {
V_3 = V_1 ;
V_4 = V_2 ;
if( V_3 == 0 ) {
V_4 = 0 ;
} else if( V_4 == 0 ) {
V_3 = 0 ;
}
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
static void F_7 ( T_2 * V_14 , T_5 V_15 , T_6 * V_16 ) {
V_17 ;
switch( V_15 ) {
% %
default: break;
}
}
static int F_8 ( T_2 * V_10 ) {
T_5 V_15 ;
T_3 * V_18 ;
if( V_10 -> V_11 < 0 ) {
return 0 ;
}
V_18 = & V_10 -> V_9 [ V_10 -> V_11 ] ;
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
if( V_10 == 0 ) {
return;
}
while( V_10 -> V_11 >= 0 ) {
F_8 ( V_10 ) ;
}
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
if( V_34 >= 0 && V_34 < V_30 && V_31 [ V_34 ] == F_14 ) {
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_4 ,
V_4 , V_19 [ V_22 ] , V_19 [ F_14 ] ) ;
}
#endif
return V_35 [ V_34 ] ;
}
}
#endif
}
return V_28 [ V_24 ] ;
} else{
return V_35 [ V_23 ] ;
}
}
static int F_15 (
int V_24 ,
T_5 V_22
) {
int V_23 ;
#ifdef F_16
if( V_24 > V_36 ) {
return V_28 [ V_24 ] ;
}
#else
assert ( V_24 <= V_36 ) ;
#endif
V_23 = V_37 [ V_24 ] ;
assert ( V_23 != V_38 ) ;
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
return V_35 [ V_23 ] ;
}
static void F_17 ( T_2 * V_14 , T_6 * T_7 V_39 ) {
V_17 ;
V_14 -> V_11 -- ;
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_5 , V_4 ) ;
}
#endif
while( V_14 -> V_11 >= 0 ) {
F_8 ( V_14 ) ;
}
% %
V_40 ;
}
static void F_18 (
T_2 * V_14 ,
int V_41 ,
int V_42 ,
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
V_18 -> V_24 = ( V_43 ) V_41 ;
V_18 -> V_20 = ( T_5 ) V_42 ;
V_18 -> V_21 = * T_7 ;
#ifndef F_3
if( V_3 && V_14 -> V_11 > 0 ) {
int V_23 ;
fprintf ( V_3 , L_6 , V_4 , V_41 ) ;
fprintf ( V_3 , L_7 , V_4 ) ;
for( V_23 = 1 ; V_23 <= V_14 -> V_11 ; V_23 ++ )
fprintf ( V_3 , L_8 , V_19 [ V_14 -> V_9 [ V_23 ] . V_20 ] ) ;
fprintf ( V_3 , L_9 ) ;
}
#endif
}
static void F_19 (
T_2 * V_14 ,
int V_44
) {
int V_45 ;
int V_46 ;
T_6 V_47 ;
T_3 * V_48 ;
int V_49 ;
V_17 ;
V_48 = & V_14 -> V_9 [ V_14 -> V_11 ] ;
#ifndef F_3
if( V_3 && V_44 >= 0
&& V_44 < ( int ) ( sizeof( V_50 ) / sizeof( V_50 [ 0 ] ) ) ) {
fprintf ( V_3 , L_10 , V_4 ,
V_50 [ V_44 ] ) ;
}
#endif
V_47 = V_51 ;
switch( V_44 ) {
% %
} ;
V_45 = V_52 [ V_44 ] . V_53 ;
V_49 = V_52 [ V_44 ] . V_54 ;
V_14 -> V_11 -= V_49 ;
V_46 = F_15 ( V_48 [ - V_49 ] . V_24 , ( T_5 ) V_45 ) ;
if( V_46 < V_55 ) {
#ifdef F_3
if( V_49 ) {
V_14 -> V_11 ++ ;
V_48 -= V_49 - 1 ;
V_48 -> V_24 = ( V_43 ) V_46 ;
V_48 -> V_20 = ( T_5 ) V_45 ;
V_48 -> V_21 = V_47 ;
} else
#endif
{
F_18 ( V_14 , V_46 , V_45 , & V_47 ) ;
}
} else{
assert ( V_46 == V_55 + V_56 + 1 ) ;
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
while( V_14 -> V_11 >= 0 ) {
F_8 ( V_14 ) ;
}
% %
V_40 ;
}
static void F_22 (
T_2 * V_14 V_39 ,
int V_15 V_39 ,
T_6 V_57
) {
V_17 ;
#define F_23 (yyminor.yy0)
% %
V_40 ;
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
while( V_14 -> V_11 >= 0 ) {
F_8 ( V_14 ) ;
}
% %
V_40 ;
}
void F_24 (
void * V_58 ,
int V_15 ,
T_8 V_57
V_59
) {
T_6 V_60 ;
int V_46 ;
int V_61 ;
#ifdef F_16
int V_62 = 0 ;
#endif
T_2 * V_14 ;
V_14 = ( T_2 * ) V_58 ;
if( V_14 -> V_11 < 0 ) {
#if V_13 <= 0
if( V_14 -> V_8 <= 0 ) {
V_60 = V_51 ;
F_17 ( V_14 , & V_60 ) ;
return;
}
#endif
V_14 -> V_11 = 0 ;
V_14 -> V_63 = - 1 ;
V_14 -> V_9 [ 0 ] . V_24 = 0 ;
V_14 -> V_9 [ 0 ] . V_20 = 0 ;
}
V_60 . V_64 = V_57 ;
V_61 = ( V_15 == 0 ) ;
V_40 ;
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_13 , V_4 , V_19 [ V_15 ] ) ;
}
#endif
do{
V_46 = F_12 ( V_14 , ( T_5 ) V_15 ) ;
if( V_46 < V_55 ) {
assert ( ! V_61 ) ;
F_18 ( V_14 , V_46 , V_15 , & V_60 ) ;
V_14 -> V_63 -- ;
V_15 = V_29 ;
} else if( V_46 < V_55 + V_56 ) {
F_19 ( V_14 , V_46 - V_55 ) ;
} else{
#ifdef F_16
int V_65 ;
#endif
assert ( V_46 == V_66 ) ;
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_14 , V_4 ) ;
}
#endif
#ifdef F_16
if( V_14 -> V_63 < 0 ) {
F_22 ( V_14 , V_15 , V_60 ) ;
}
V_65 = V_14 -> V_9 [ V_14 -> V_11 ] . V_20 ;
if( V_65 == F_16 || V_62 ) {
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_15 ,
V_4 , V_19 [ V_15 ] ) ;
}
#endif
F_7 ( V_14 , ( T_5 ) V_15 , & V_60 ) ;
V_15 = V_29 ;
} else{
while(
V_14 -> V_11 >= 0 &&
V_65 != F_16 &&
( V_46 = F_15 (
V_14 -> V_9 [ V_14 -> V_11 ] . V_24 ,
F_16 ) ) >= V_55
) {
F_8 ( V_14 ) ;
}
if( V_14 -> V_11 < 0 || V_15 == 0 ) {
F_7 ( V_14 , ( T_5 ) V_15 , & V_60 ) ;
F_21 ( V_14 ) ;
V_15 = V_29 ;
} else if( V_65 != F_16 ) {
T_6 V_67 ;
V_67 . V_68 = 0 ;
F_18 ( V_14 , V_46 , F_16 , & V_67 ) ;
}
}
V_14 -> V_63 = 3 ;
V_62 = 1 ;
#else
if( V_14 -> V_63 <= 0 ) {
F_22 ( V_14 , V_15 , V_60 ) ;
}
V_14 -> V_63 = 3 ;
F_7 ( V_14 , ( T_5 ) V_15 , & V_60 ) ;
if( V_61 ) {
F_21 ( V_14 ) ;
}
V_15 = V_29 ;
#endif
}
}while( V_15 != V_29 && V_14 -> V_11 >= 0 );
return;
}
