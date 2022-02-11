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
#endif
if( V_10 ) {
V_10 -> V_11 = - 1 ;
#ifdef F_6
V_10 -> V_12 = 0 ;
#endif
#if V_13 <= 0
F_2 ( V_10 ) ;
#endif
}
return V_10 ;
}
static void F_7 ( T_5 V_14 , T_6 * V_15 ) {
switch( V_14 ) {
% %
default: break;
}
}
static int F_8 ( T_2 * V_10 ) {
T_5 V_14 ;
T_3 * V_16 ;
if( V_10 -> V_11 < 0 ) return 0 ;
V_16 = & V_10 -> V_9 [ V_10 -> V_11 ] ;
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_2 ,
V_4 ,
V_17 [ V_16 -> V_18 ] ) ;
}
#endif
V_14 = V_16 -> V_18 ;
F_7 ( V_14 , & V_16 -> V_19 ) ;
V_10 -> V_11 -- ;
return V_14 ;
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
(* F_10)( V_10 ) ;
}
int F_11 ( void * V_5 ) {
T_2 * V_10 = ( T_2 * ) V_5 ;
return V_10 -> V_12 ;
}
static int F_12 (
T_2 * V_10 ,
T_5 V_20
) {
int V_21 ;
int V_22 = V_10 -> V_9 [ V_10 -> V_11 ] . V_22 ;
if( V_22 > V_23 || ( V_21 = V_24 [ V_22 ] ) == V_25 ) {
return V_26 [ V_22 ] ;
}
assert ( V_20 != V_27 ) ;
V_21 += V_20 ;
if( V_21 < 0 || V_21 >= V_28 || V_29 [ V_21 ] != V_20 ) {
if( V_20 > 0 ) {
#ifdef F_13
int V_30 ;
if( V_20 < sizeof( V_31 ) / sizeof( V_31 [ 0 ] )
&& ( V_30 = V_31 [ V_20 ] ) != 0 ) {
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_3 ,
V_4 , V_17 [ V_20 ] , V_17 [ V_30 ] ) ;
}
#endif
return F_12 ( V_10 , V_30 ) ;
}
#endif
#ifdef F_14
{
int V_32 = V_21 - V_20 + F_14 ;
if( V_32 >= 0 && V_32 < V_28 && V_29 [ V_32 ] == F_14 ) {
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_4 ,
V_4 , V_17 [ V_20 ] , V_17 [ F_14 ] ) ;
}
#endif
return V_33 [ V_32 ] ;
}
}
#endif
}
return V_26 [ V_22 ] ;
} else{
return V_33 [ V_21 ] ;
}
}
static int F_15 (
int V_22 ,
T_5 V_20
) {
int V_21 ;
#ifdef F_16
if( V_22 > V_34 ) {
return V_26 [ V_22 ] ;
}
#else
assert ( V_22 <= V_34 ) ;
#endif
V_21 = V_35 [ V_22 ] ;
assert ( V_21 != V_36 ) ;
assert ( V_20 != V_27 ) ;
V_21 += V_20 ;
#ifdef F_16
if( V_21 < 0 || V_21 >= V_28 || V_29 [ V_21 ] != V_20 ) {
return V_26 [ V_22 ] ;
}
#else
assert ( V_21 >= 0 && V_21 < V_28 ) ;
assert ( V_29 [ V_21 ] == V_20 ) ;
#endif
return V_33 [ V_21 ] ;
}
static void F_17 ( T_2 * V_37 , T_6 * T_7 V_38 ) {
V_39 ;
V_37 -> V_11 -- ;
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_5 , V_4 ) ;
}
#endif
while( V_37 -> V_11 >= 0 ) F_8 ( V_37 ) ;
% %
V_40 ;
}
static void F_18 (
T_2 * V_37 ,
int V_41 ,
int V_42 ,
T_6 * T_7
) {
T_3 * V_16 ;
V_37 -> V_11 ++ ;
#ifdef F_6
if( V_37 -> V_11 > V_37 -> V_12 ) {
V_37 -> V_12 = V_37 -> V_11 ;
}
#endif
#if V_13 > 0
if( V_37 -> V_11 >= V_13 ) {
F_17 ( V_37 , T_7 ) ;
return;
}
#else
if( V_37 -> V_11 >= V_37 -> V_8 ) {
F_2 ( V_37 ) ;
if( V_37 -> V_11 >= V_37 -> V_8 ) {
F_17 ( V_37 , T_7 ) ;
return;
}
}
#endif
V_16 = & V_37 -> V_9 [ V_37 -> V_11 ] ;
V_16 -> V_22 = V_41 ;
V_16 -> V_18 = V_42 ;
V_16 -> V_19 = * T_7 ;
#ifndef F_3
if( V_3 && V_37 -> V_11 > 0 ) {
int V_21 ;
fprintf ( V_3 , L_6 , V_4 , V_41 ) ;
fprintf ( V_3 , L_7 , V_4 ) ;
for( V_21 = 1 ; V_21 <= V_37 -> V_11 ; V_21 ++ )
fprintf ( V_3 , L_8 , V_17 [ V_37 -> V_9 [ V_21 ] . V_18 ] ) ;
fprintf ( V_3 , L_9 ) ;
}
#endif
}
static void F_19 (
T_2 * V_37 ,
int V_43
) {
int V_44 ;
int V_45 ;
T_6 V_46 ;
T_3 * V_47 ;
int V_48 ;
V_39 ;
V_47 = & V_37 -> V_9 [ V_37 -> V_11 ] ;
#ifndef F_3
if( V_3 && V_43 >= 0
&& V_43 < ( int ) ( sizeof( V_49 ) / sizeof( V_49 [ 0 ] ) ) ) {
fprintf ( V_3 , L_10 , V_4 ,
V_49 [ V_43 ] ) ;
}
#endif
V_46 = V_50 ;
switch( V_43 ) {
% %
} ;
V_44 = V_51 [ V_43 ] . V_52 ;
V_48 = V_51 [ V_43 ] . V_53 ;
V_37 -> V_11 -= V_48 ;
V_45 = F_15 ( V_47 [ - V_48 ] . V_22 , ( T_5 ) V_44 ) ;
if( V_45 < V_54 ) {
#ifdef F_3
if( V_48 ) {
V_37 -> V_11 ++ ;
V_47 -= V_48 - 1 ;
V_47 -> V_22 = V_45 ;
V_47 -> V_18 = V_44 ;
V_47 -> V_19 = V_46 ;
} else
#endif
{
F_18 ( V_37 , V_45 , V_44 , & V_46 ) ;
}
} else{
assert ( V_45 == V_54 + V_55 + 1 ) ;
F_20 ( V_37 ) ;
}
}
static void F_21 (
T_2 * V_37
) {
V_39 ;
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_11 , V_4 ) ;
}
#endif
while( V_37 -> V_11 >= 0 ) F_8 ( V_37 ) ;
% %
V_40 ;
}
static void F_22 (
T_2 * V_37 V_38 ,
int V_14 V_38 ,
T_6 V_56
) {
V_39 ;
#define F_23 (yyminor.yy0)
% %
V_40 ;
}
static void F_20 (
T_2 * V_37
) {
V_39 ;
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_12 , V_4 ) ;
}
#endif
while( V_37 -> V_11 >= 0 ) F_8 ( V_37 ) ;
% %
V_40 ;
}
void F_24 (
void * V_57 ,
int V_14 ,
T_8 V_56
V_58
) {
T_6 V_59 ;
int V_45 ;
int V_60 ;
#ifdef F_16
int V_61 = 0 ;
#endif
T_2 * V_37 ;
V_37 = ( T_2 * ) V_57 ;
if( V_37 -> V_11 < 0 ) {
#if V_13 <= 0
if( V_37 -> V_8 <= 0 ) {
V_59 = V_50 ;
F_17 ( V_37 , & V_59 ) ;
return;
}
#endif
V_37 -> V_11 = 0 ;
V_37 -> V_62 = - 1 ;
V_37 -> V_9 [ 0 ] . V_22 = 0 ;
V_37 -> V_9 [ 0 ] . V_18 = 0 ;
}
V_59 . V_63 = V_56 ;
V_60 = ( V_14 == 0 ) ;
V_40 ;
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_13 , V_4 , V_17 [ V_14 ] ) ;
}
#endif
do{
V_45 = F_12 ( V_37 , ( T_5 ) V_14 ) ;
if( V_45 < V_54 ) {
assert ( ! V_60 ) ;
F_18 ( V_37 , V_45 , V_14 , & V_59 ) ;
V_37 -> V_62 -- ;
V_14 = V_27 ;
} else if( V_45 < V_54 + V_55 ) {
F_19 ( V_37 , V_45 - V_54 ) ;
} else{
#ifdef F_16
int V_64 ;
#endif
assert ( V_45 == V_65 ) ;
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_14 , V_4 ) ;
}
#endif
#ifdef F_16
if( V_37 -> V_62 < 0 ) {
F_22 ( V_37 , V_14 , V_59 ) ;
}
V_64 = V_37 -> V_9 [ V_37 -> V_11 ] . V_18 ;
if( V_64 == F_16 || V_61 ) {
#ifndef F_3
if( V_3 ) {
fprintf ( V_3 , L_15 ,
V_4 , V_17 [ V_14 ] ) ;
}
#endif
F_7 ( ( T_5 ) V_14 , & V_59 ) ;
V_14 = V_27 ;
} else{
while(
V_37 -> V_11 >= 0 &&
V_64 != F_16 &&
( V_45 = F_15 (
V_37 -> V_9 [ V_37 -> V_11 ] . V_22 ,
F_16 ) ) >= V_54
) {
F_8 ( V_37 ) ;
}
if( V_37 -> V_11 < 0 || V_14 == 0 ) {
F_7 ( ( T_5 ) V_14 , & V_59 ) ;
F_21 ( V_37 ) ;
V_14 = V_27 ;
} else if( V_64 != F_16 ) {
T_6 V_66 ;
V_66 . V_67 = 0 ;
F_18 ( V_37 , V_45 , F_16 , & V_66 ) ;
}
}
V_37 -> V_62 = 3 ;
V_61 = 1 ;
#else
if( V_37 -> V_62 <= 0 ) {
F_22 ( V_37 , V_14 , V_59 ) ;
}
V_37 -> V_62 = 3 ;
F_7 ( ( T_5 ) V_14 , & V_59 ) ;
if( V_60 ) {
F_21 ( V_37 ) ;
}
V_14 = V_27 ;
#endif
}
}while( V_14 != V_27 && V_37 -> V_11 >= 0 );
return;
}
