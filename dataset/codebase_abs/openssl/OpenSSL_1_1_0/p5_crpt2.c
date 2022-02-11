int F_1 ( const char * V_1 , int V_2 ,
const unsigned char * V_3 , int V_4 , int V_5 ,
const T_1 * V_6 , int V_7 , unsigned char * V_8 )
{
unsigned char V_9 [ V_10 ] , * V_11 , V_12 [ 4 ] ;
int V_13 , V_14 , V_15 , V_16 , V_17 ;
unsigned long V_18 = 1 ;
T_2 * V_19 = NULL , * V_20 = NULL ;
V_17 = F_2 ( V_6 ) ;
if ( V_17 < 0 )
return 0 ;
V_19 = F_3 () ;
if ( V_19 == NULL )
return 0 ;
V_11 = V_8 ;
V_16 = V_7 ;
if ( ! V_1 )
V_2 = 0 ;
else if ( V_2 == - 1 )
V_2 = strlen ( V_1 ) ;
if ( ! F_4 ( V_19 , V_1 , V_2 , V_6 , NULL ) ) {
F_5 ( V_19 ) ;
return 0 ;
}
V_20 = F_3 () ;
if ( V_20 == NULL ) {
F_5 ( V_19 ) ;
return 0 ;
}
while ( V_16 ) {
if ( V_16 > V_17 )
V_13 = V_17 ;
else
V_13 = V_16 ;
V_12 [ 0 ] = ( unsigned char ) ( ( V_18 >> 24 ) & 0xff ) ;
V_12 [ 1 ] = ( unsigned char ) ( ( V_18 >> 16 ) & 0xff ) ;
V_12 [ 2 ] = ( unsigned char ) ( ( V_18 >> 8 ) & 0xff ) ;
V_12 [ 3 ] = ( unsigned char ) ( V_18 & 0xff ) ;
if ( ! F_6 ( V_20 , V_19 ) ) {
F_5 ( V_20 ) ;
F_5 ( V_19 ) ;
return 0 ;
}
if ( ! F_7 ( V_20 , V_3 , V_4 )
|| ! F_7 ( V_20 , V_12 , 4 )
|| ! F_8 ( V_20 , V_9 , NULL ) ) {
F_5 ( V_20 ) ;
F_5 ( V_19 ) ;
return 0 ;
}
F_9 ( V_20 ) ;
memcpy ( V_11 , V_9 , V_13 ) ;
for ( V_14 = 1 ; V_14 < V_5 ; V_14 ++ ) {
if ( ! F_6 ( V_20 , V_19 ) ) {
F_5 ( V_20 ) ;
F_5 ( V_19 ) ;
return 0 ;
}
if ( ! F_7 ( V_20 , V_9 , V_17 )
|| ! F_8 ( V_20 , V_9 , NULL ) ) {
F_5 ( V_20 ) ;
F_5 ( V_19 ) ;
return 0 ;
}
F_9 ( V_20 ) ;
for ( V_15 = 0 ; V_15 < V_13 ; V_15 ++ )
V_11 [ V_15 ] ^= V_9 [ V_15 ] ;
}
V_16 -= V_13 ;
V_18 ++ ;
V_11 += V_13 ;
}
F_5 ( V_20 ) ;
F_5 ( V_19 ) ;
# ifdef F_10
fprintf ( V_21 , L_1 ) ;
F_11 ( V_1 , V_2 ) ;
fprintf ( V_21 , L_2 ) ;
F_11 ( V_3 , V_4 ) ;
fprintf ( V_21 , L_3 , V_5 ) ;
fprintf ( V_21 , L_4 ) ;
F_11 ( V_8 , V_7 ) ;
# endif
return 1 ;
}
int F_12 ( const char * V_1 , int V_2 ,
const unsigned char * V_3 , int V_4 , int V_5 ,
int V_7 , unsigned char * V_8 )
{
return F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 , F_13 () ,
V_7 , V_8 ) ;
}
main ()
{
unsigned char V_8 [ 4 ] ;
unsigned char V_3 [] = { 0x12 , 0x34 , 0x56 , 0x78 } ;
F_12 ( L_5 , - 1 , V_3 , 4 , 5 , 4 , V_8 ) ;
fprintf ( V_21 , L_6 ,
V_8 [ 0 ] , V_8 [ 1 ] , V_8 [ 2 ] , V_8 [ 3 ] ) ;
}
int F_14 ( T_3 * V_22 , const char * V_1 , int V_2 ,
T_4 * V_23 , const T_5 * V_24 ,
const T_1 * V_25 , int V_26 )
{
T_6 * V_27 = NULL ;
const T_5 * V_28 ;
T_7 * V_29 ;
int V_30 = 0 ;
V_27 = F_15 ( F_16 ( T_6 ) , V_23 ) ;
if ( V_27 == NULL ) {
F_17 ( V_31 , V_32 ) ;
goto V_33;
}
if ( ! F_18 ( V_34 , F_19 ( V_27 -> V_35 -> V_36 ) ,
NULL , NULL , & V_29 ) ) {
F_17 ( V_31 ,
V_37 ) ;
goto V_33;
}
V_28 = F_20 ( V_27 -> V_38 -> V_36 ) ;
if ( ! V_28 ) {
F_17 ( V_31 , V_39 ) ;
goto V_33;
}
if ( ! F_21 ( V_22 , V_28 , NULL , NULL , NULL , V_26 ) )
goto V_33;
if ( F_22 ( V_22 , V_27 -> V_38 -> V_40 ) < 0 ) {
F_17 ( V_31 , V_41 ) ;
goto V_33;
}
V_30 = V_29 ( V_22 , V_1 , V_2 , V_27 -> V_35 -> V_40 , NULL , NULL , V_26 ) ;
V_33:
F_23 ( V_27 ) ;
return V_30 ;
}
int F_24 ( T_3 * V_22 , const char * V_1 ,
int V_2 , T_4 * V_23 ,
const T_5 * V_24 , const T_1 * V_25 , int V_26 )
{
unsigned char * V_3 , V_42 [ V_43 ] ;
int V_4 , V_5 ;
int V_30 = 0 ;
unsigned int V_7 = 0 ;
int V_44 , V_45 ;
T_8 * V_29 = NULL ;
const T_1 * V_46 ;
if ( F_25 ( V_22 ) == NULL ) {
F_17 ( V_47 , V_48 ) ;
goto V_33;
}
V_7 = F_26 ( V_22 ) ;
F_27 ( V_7 <= sizeof V_42 ) ;
V_29 = F_15 ( F_16 ( T_8 ) , V_23 ) ;
if ( V_29 == NULL ) {
F_17 ( V_47 , V_32 ) ;
goto V_33;
}
V_7 = F_26 ( V_22 ) ;
if ( V_29 -> V_49 && ( F_28 ( V_29 -> V_49 ) != ( int ) V_7 ) ) {
F_17 ( V_47 , V_50 ) ;
goto V_33;
}
if ( V_29 -> V_51 )
V_44 = F_19 ( V_29 -> V_51 -> V_36 ) ;
else
V_44 = V_52 ;
if ( ! F_18 ( V_53 , V_44 , NULL , & V_45 , 0 ) ) {
F_17 ( V_47 , V_54 ) ;
goto V_33;
}
V_46 = F_29 ( V_45 ) ;
if ( V_46 == NULL ) {
F_17 ( V_47 , V_54 ) ;
goto V_33;
}
if ( V_29 -> V_3 -> type != V_55 ) {
F_17 ( V_47 , V_56 ) ;
goto V_33;
}
V_3 = V_29 -> V_3 -> V_57 . V_58 -> V_59 ;
V_4 = V_29 -> V_3 -> V_57 . V_58 -> V_60 ;
V_5 = F_28 ( V_29 -> V_5 ) ;
if ( ! F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_46 ,
V_7 , V_42 ) )
goto V_33;
V_30 = F_21 ( V_22 , NULL , NULL , V_42 , NULL , V_26 ) ;
V_33:
F_30 ( V_42 , V_7 ) ;
F_31 ( V_29 ) ;
return V_30 ;
}
static void F_11 ( const unsigned char * V_11 , int V_61 )
{
for (; V_61 -- ; V_11 ++ )
fprintf ( V_21 , L_7 , * V_11 ) ;
fprintf ( V_21 , L_8 ) ;
}
