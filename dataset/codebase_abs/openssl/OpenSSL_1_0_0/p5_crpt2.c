int F_1 ( const char * V_1 , int V_2 ,
const unsigned char * V_3 , int V_4 , int V_5 ,
const T_1 * V_6 ,
int V_7 , unsigned char * V_8 )
{
unsigned char V_9 [ V_10 ] , * V_11 , V_12 [ 4 ] ;
int V_13 , V_14 , V_15 , V_16 , V_17 ;
unsigned long V_18 = 1 ;
T_2 V_19 ;
V_17 = F_2 ( V_6 ) ;
if ( V_17 < 0 )
return 0 ;
F_3 ( & V_19 ) ;
V_11 = V_8 ;
V_16 = V_7 ;
if( ! V_1 )
V_2 = 0 ;
else if( V_2 == - 1 )
V_2 = strlen ( V_1 ) ;
while( V_16 )
{
if( V_16 > V_17 )
V_13 = V_17 ;
else
V_13 = V_16 ;
V_12 [ 0 ] = ( unsigned char ) ( ( V_18 >> 24 ) & 0xff ) ;
V_12 [ 1 ] = ( unsigned char ) ( ( V_18 >> 16 ) & 0xff ) ;
V_12 [ 2 ] = ( unsigned char ) ( ( V_18 >> 8 ) & 0xff ) ;
V_12 [ 3 ] = ( unsigned char ) ( V_18 & 0xff ) ;
F_4 ( & V_19 , V_1 , V_2 , V_6 , NULL ) ;
F_5 ( & V_19 , V_3 , V_4 ) ;
F_5 ( & V_19 , V_12 , 4 ) ;
F_6 ( & V_19 , V_9 , NULL ) ;
memcpy ( V_11 , V_9 , V_13 ) ;
for( V_14 = 1 ; V_14 < V_5 ; V_14 ++ )
{
F_7 ( V_6 , V_1 , V_2 ,
V_9 , V_17 , V_9 , NULL ) ;
for( V_15 = 0 ; V_15 < V_13 ; V_15 ++ )
V_11 [ V_15 ] ^= V_9 [ V_15 ] ;
}
V_16 -= V_13 ;
V_18 ++ ;
V_11 += V_13 ;
}
F_8 ( & V_19 ) ;
#ifdef F_9
fprintf ( V_20 , L_1 ) ;
F_10 ( V_1 , V_2 ) ;
fprintf ( V_20 , L_2 ) ;
F_10 ( V_3 , V_4 ) ;
fprintf ( V_20 , L_3 , V_5 ) ;
fprintf ( V_20 , L_4 ) ;
F_10 ( V_8 , V_7 ) ;
#endif
return 1 ;
}
int F_11 ( const char * V_1 , int V_2 ,
const unsigned char * V_3 , int V_4 , int V_5 ,
int V_7 , unsigned char * V_8 )
{
return F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 , F_12 () ,
V_7 , V_8 ) ;
}
main ()
{
unsigned char V_8 [ 4 ] ;
unsigned char V_3 [] = { 0x12 , 0x34 , 0x56 , 0x78 } ;
F_11 ( L_5 , - 1 , V_3 , 4 , 5 , 4 , V_8 ) ;
fprintf ( V_20 , L_6 ,
V_8 [ 0 ] , V_8 [ 1 ] , V_8 [ 2 ] , V_8 [ 3 ] ) ;
}
int F_13 ( T_3 * V_21 , const char * V_1 , int V_2 ,
T_4 * V_22 , const T_5 * V_23 , const T_1 * V_24 ,
int V_25 )
{
unsigned char * V_3 , V_26 [ V_27 ] ;
const unsigned char * V_28 ;
int V_4 , V_5 , V_29 ;
unsigned int V_7 ;
T_6 * V_30 = NULL ;
const T_5 * V_31 ;
T_7 * V_32 = NULL ;
const T_1 * V_33 ;
int V_34 , V_35 ;
if ( V_22 == NULL || V_22 -> type != V_36 ||
V_22 -> V_37 . V_38 == NULL ) {
F_14 ( V_39 , V_40 ) ;
return 0 ;
}
V_28 = V_22 -> V_37 . V_38 -> V_41 ;
V_29 = V_22 -> V_37 . V_38 -> V_42 ;
if( ! ( V_30 = F_15 ( NULL , & V_28 , V_29 ) ) ) {
F_14 ( V_39 , V_40 ) ;
return 0 ;
}
if( F_16 ( V_30 -> V_43 -> V_44 ) != V_45 ) {
F_14 ( V_39 ,
V_46 ) ;
goto V_47;
}
V_31 = F_17 ( V_30 -> V_48 -> V_44 ) ;
if( ! V_31 ) {
F_14 ( V_39 ,
V_49 ) ;
goto V_47;
}
F_18 ( V_21 , V_31 , NULL , NULL , NULL , V_25 ) ;
if( F_19 ( V_21 , V_30 -> V_48 -> V_50 ) < 0 ) {
F_14 ( V_39 ,
V_51 ) ;
goto V_47;
}
V_7 = F_20 ( V_21 ) ;
F_21 ( V_7 <= sizeof V_26 ) ;
if( ! V_30 -> V_43 -> V_50 ||
( V_30 -> V_43 -> V_50 -> type != V_36 ) )
{
F_14 ( V_39 , V_40 ) ;
goto V_47;
}
V_28 = V_30 -> V_43 -> V_50 -> V_37 . V_38 -> V_41 ;
V_29 = V_30 -> V_43 -> V_50 -> V_37 . V_38 -> V_42 ;
if( ! ( V_32 = F_22 ( NULL , & V_28 , V_29 ) ) ) {
F_14 ( V_39 , V_40 ) ;
goto V_47;
}
F_23 ( V_30 ) ;
V_30 = NULL ;
if( V_32 -> V_52 && ( F_24 ( V_32 -> V_52 ) != ( int ) V_7 ) ) {
F_14 ( V_39 ,
V_53 ) ;
goto V_47;
}
if ( V_32 -> V_54 )
V_34 = F_16 ( V_32 -> V_54 -> V_44 ) ;
else
V_34 = V_55 ;
if ( ! F_25 ( V_56 , V_34 , NULL , & V_35 , 0 ) )
{
F_14 ( V_39 , V_57 ) ;
goto V_47;
}
V_33 = F_26 ( V_35 ) ;
if ( V_33 == NULL )
{
F_14 ( V_39 , V_57 ) ;
goto V_47;
}
if( V_32 -> V_3 -> type != V_58 ) {
F_14 ( V_39 ,
V_59 ) ;
goto V_47;
}
V_3 = V_32 -> V_3 -> V_37 . V_60 -> V_41 ;
V_4 = V_32 -> V_3 -> V_37 . V_60 -> V_42 ;
V_5 = F_24 ( V_32 -> V_5 ) ;
if( ! F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_33 ,
V_7 , V_26 ) )
goto V_47;
F_18 ( V_21 , NULL , NULL , V_26 , NULL , V_25 ) ;
F_27 ( V_26 , V_7 ) ;
F_28 ( V_32 ) ;
return 1 ;
V_47:
F_23 ( V_30 ) ;
F_28 ( V_32 ) ;
return 0 ;
}
static void F_10 ( const unsigned char * V_11 , int V_61 )
{
for (; V_61 -- ; V_11 ++ ) fprintf ( V_20 , L_7 , * V_11 ) ;
fprintf ( V_20 , L_8 ) ;
}
