int F_1 ( const char * V_1 , int V_2 ,
const unsigned char * V_3 , int V_4 , int V_5 ,
int V_6 , unsigned char * V_7 )
{
unsigned char V_8 [ V_9 ] , * V_10 , V_11 [ 4 ] ;
int V_12 , V_13 , V_14 , V_15 ;
unsigned long V_16 = 1 ;
T_1 V_17 ;
F_2 ( & V_17 ) ;
V_10 = V_7 ;
V_15 = V_6 ;
if( ! V_1 ) V_2 = 0 ;
else if( V_2 == - 1 ) V_2 = strlen ( V_1 ) ;
while( V_15 ) {
if( V_15 > V_9 ) V_12 = V_9 ;
else V_12 = V_15 ;
V_11 [ 0 ] = ( unsigned char ) ( ( V_16 >> 24 ) & 0xff ) ;
V_11 [ 1 ] = ( unsigned char ) ( ( V_16 >> 16 ) & 0xff ) ;
V_11 [ 2 ] = ( unsigned char ) ( ( V_16 >> 8 ) & 0xff ) ;
V_11 [ 3 ] = ( unsigned char ) ( V_16 & 0xff ) ;
F_3 ( & V_17 , V_1 , V_2 , F_4 () , NULL ) ;
F_5 ( & V_17 , V_3 , V_4 ) ;
F_5 ( & V_17 , V_11 , 4 ) ;
F_6 ( & V_17 , V_8 , NULL ) ;
memcpy ( V_10 , V_8 , V_12 ) ;
for( V_13 = 1 ; V_13 < V_5 ; V_13 ++ ) {
F_7 ( F_4 () , V_1 , V_2 ,
V_8 , V_9 , V_8 , NULL ) ;
for( V_14 = 0 ; V_14 < V_12 ; V_14 ++ ) V_10 [ V_14 ] ^= V_8 [ V_14 ] ;
}
V_15 -= V_12 ;
V_16 ++ ;
V_10 += V_12 ;
}
F_8 ( & V_17 ) ;
#ifdef F_9
fprintf ( V_18 , L_1 ) ;
F_10 ( V_1 , V_2 ) ;
fprintf ( V_18 , L_2 ) ;
F_10 ( V_3 , V_4 ) ;
fprintf ( V_18 , L_3 , V_5 ) ;
fprintf ( V_18 , L_4 ) ;
F_10 ( V_7 , V_6 ) ;
#endif
return 1 ;
}
main ()
{
unsigned char V_7 [ 4 ] ;
unsigned char V_3 [] = { 0x12 , 0x34 , 0x56 , 0x78 } ;
F_1 ( L_5 , - 1 , V_3 , 4 , 5 , 4 , V_7 ) ;
fprintf ( V_18 , L_6 ,
V_7 [ 0 ] , V_7 [ 1 ] , V_7 [ 2 ] , V_7 [ 3 ] ) ;
}
int F_11 ( T_2 * V_19 , const char * V_1 , int V_2 ,
T_3 * V_20 , const T_4 * V_21 , const T_5 * V_22 ,
int V_23 )
{
unsigned char * V_3 , V_24 [ V_25 ] ;
const unsigned char * V_26 ;
int V_4 , V_5 , V_27 ;
unsigned int V_6 ;
T_6 * V_28 = NULL ;
const T_4 * V_29 ;
T_7 * V_30 = NULL ;
V_26 = V_20 -> V_31 . V_32 -> V_33 ;
V_27 = V_20 -> V_31 . V_32 -> V_34 ;
if( ! V_20 || ( V_20 -> type != V_35 ) ||
! ( V_28 = F_12 ( NULL , & V_26 , V_27 ) ) ) {
F_13 ( V_36 , V_37 ) ;
return 0 ;
}
if( F_14 ( V_28 -> V_38 -> V_39 ) != V_40 ) {
F_13 ( V_36 ,
V_41 ) ;
goto V_42;
}
V_29 = F_15 (
F_16 ( F_14 ( V_28 -> V_43 -> V_39 ) ) ) ;
if( ! V_29 ) {
F_13 ( V_36 ,
V_44 ) ;
goto V_42;
}
F_17 ( V_19 , V_29 , NULL , NULL , NULL , V_23 ) ;
if( F_18 ( V_19 , V_28 -> V_43 -> V_45 ) < 0 ) {
F_13 ( V_36 ,
V_46 ) ;
goto V_42;
}
V_6 = F_19 ( V_19 ) ;
F_20 ( V_6 <= sizeof V_24 ) ;
V_26 = V_28 -> V_38 -> V_45 -> V_31 . V_32 -> V_33 ;
V_27 = V_28 -> V_38 -> V_45 -> V_31 . V_32 -> V_34 ;
if( ! V_28 -> V_38 -> V_45 ||
( V_28 -> V_38 -> V_45 -> type != V_35 ) ||
! ( V_30 = F_21 ( NULL , & V_26 , V_27 ) ) ) {
F_13 ( V_36 , V_37 ) ;
goto V_42;
}
F_22 ( V_28 ) ;
V_28 = NULL ;
if( V_30 -> V_47 && ( F_23 ( V_30 -> V_47 ) != ( int ) V_6 ) ) {
F_13 ( V_36 ,
V_48 ) ;
goto V_42;
}
if( V_30 -> V_49 && ( F_14 ( V_30 -> V_49 -> V_39 ) != V_50 ) ) {
F_13 ( V_36 , V_51 ) ;
goto V_42;
}
if( V_30 -> V_3 -> type != V_52 ) {
F_13 ( V_36 ,
V_53 ) ;
goto V_42;
}
V_3 = V_30 -> V_3 -> V_31 . V_54 -> V_33 ;
V_4 = V_30 -> V_3 -> V_31 . V_54 -> V_34 ;
V_5 = F_23 ( V_30 -> V_5 ) ;
F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 , V_24 ) ;
F_17 ( V_19 , NULL , NULL , V_24 , NULL , V_23 ) ;
F_24 ( V_24 , V_6 ) ;
F_25 ( V_30 ) ;
return 1 ;
V_42:
F_22 ( V_28 ) ;
F_25 ( V_30 ) ;
return 0 ;
}
static void F_10 ( const unsigned char * V_10 , int V_55 )
{
for (; V_55 -- ; V_10 ++ ) fprintf ( V_18 , L_7 , * V_10 ) ;
fprintf ( V_18 , L_8 ) ;
}
