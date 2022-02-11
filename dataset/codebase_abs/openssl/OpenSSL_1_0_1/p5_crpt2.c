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
if ( ! F_4 ( & V_19 , V_1 , V_2 , V_6 , NULL )
|| ! F_5 ( & V_19 , V_3 , V_4 )
|| ! F_5 ( & V_19 , V_12 , 4 )
|| ! F_6 ( & V_19 , V_9 , NULL ) )
{
F_7 ( & V_19 ) ;
return 0 ;
}
memcpy ( V_11 , V_9 , V_13 ) ;
for( V_14 = 1 ; V_14 < V_5 ; V_14 ++ )
{
F_8 ( V_6 , V_1 , V_2 ,
V_9 , V_17 , V_9 , NULL ) ;
for( V_15 = 0 ; V_15 < V_13 ; V_15 ++ )
V_11 [ V_15 ] ^= V_9 [ V_15 ] ;
}
V_16 -= V_13 ;
V_18 ++ ;
V_11 += V_13 ;
}
F_7 ( & V_19 ) ;
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
const unsigned char * V_26 ;
int V_27 ;
T_6 * V_28 = NULL ;
const T_5 * V_29 ;
int V_30 = 0 ;
if ( V_22 == NULL || V_22 -> type != V_31 ||
V_22 -> V_32 . V_33 == NULL ) {
F_14 ( V_34 , V_35 ) ;
goto V_36;
}
V_26 = V_22 -> V_32 . V_33 -> V_37 ;
V_27 = V_22 -> V_32 . V_33 -> V_38 ;
if( ! ( V_28 = F_15 ( NULL , & V_26 , V_27 ) ) ) {
F_14 ( V_34 , V_35 ) ;
goto V_36;
}
if( F_16 ( V_28 -> V_39 -> V_40 ) != V_41 ) {
F_14 ( V_34 ,
V_42 ) ;
goto V_36;
}
V_29 = F_17 ( V_28 -> V_43 -> V_40 ) ;
if( ! V_29 ) {
F_14 ( V_34 ,
V_44 ) ;
goto V_36;
}
if ( ! F_18 ( V_21 , V_29 , NULL , NULL , NULL , V_25 ) )
goto V_36;
if( F_19 ( V_21 , V_28 -> V_43 -> V_45 ) < 0 ) {
F_14 ( V_34 ,
V_46 ) ;
goto V_36;
}
V_30 = F_20 ( V_21 , V_1 , V_2 ,
V_28 -> V_39 -> V_45 , V_23 , V_24 , V_25 ) ;
V_36:
F_21 ( V_28 ) ;
return V_30 ;
}
int F_20 ( T_3 * V_21 , const char * V_1 , int V_2 ,
T_4 * V_22 ,
const T_5 * V_23 , const T_1 * V_24 , int V_25 )
{
unsigned char * V_3 , V_47 [ V_48 ] ;
const unsigned char * V_26 ;
int V_4 , V_5 , V_27 ;
int V_30 = 0 ;
unsigned int V_7 = 0 ;
int V_49 , V_50 ;
T_7 * V_51 = NULL ;
const T_1 * V_52 ;
if ( F_22 ( V_21 ) == NULL )
{
F_14 ( V_53 , V_54 ) ;
goto V_36;
}
V_7 = F_23 ( V_21 ) ;
F_24 ( V_7 <= sizeof V_47 ) ;
if( ! V_22 || ( V_22 -> type != V_31 ) )
{
F_14 ( V_53 , V_35 ) ;
goto V_36;
}
V_26 = V_22 -> V_32 . V_33 -> V_37 ;
V_27 = V_22 -> V_32 . V_33 -> V_38 ;
if( ! ( V_51 = F_25 ( NULL , & V_26 , V_27 ) ) ) {
F_14 ( V_53 , V_35 ) ;
goto V_36;
}
V_7 = F_23 ( V_21 ) ;
if( V_51 -> V_55 && ( F_26 ( V_51 -> V_55 ) != ( int ) V_7 ) ) {
F_14 ( V_53 ,
V_56 ) ;
goto V_36;
}
if ( V_51 -> V_57 )
V_49 = F_16 ( V_51 -> V_57 -> V_40 ) ;
else
V_49 = V_58 ;
if ( ! F_27 ( V_59 , V_49 , NULL , & V_50 , 0 ) )
{
F_14 ( V_53 , V_60 ) ;
goto V_36;
}
V_52 = F_28 ( V_50 ) ;
if ( V_52 == NULL )
{
F_14 ( V_53 , V_60 ) ;
goto V_36;
}
if( V_51 -> V_3 -> type != V_61 ) {
F_14 ( V_53 ,
V_62 ) ;
goto V_36;
}
V_3 = V_51 -> V_3 -> V_32 . V_63 -> V_37 ;
V_4 = V_51 -> V_3 -> V_32 . V_63 -> V_38 ;
V_5 = F_26 ( V_51 -> V_5 ) ;
if( ! F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_52 ,
V_7 , V_47 ) )
goto V_36;
V_30 = F_18 ( V_21 , NULL , NULL , V_47 , NULL , V_25 ) ;
V_36:
F_29 ( V_47 , V_7 ) ;
F_30 ( V_51 ) ;
return V_30 ;
}
static void F_10 ( const unsigned char * V_11 , int V_64 )
{
for (; V_64 -- ; V_11 ++ ) fprintf ( V_20 , L_7 , * V_11 ) ;
fprintf ( V_20 , L_8 ) ;
}
