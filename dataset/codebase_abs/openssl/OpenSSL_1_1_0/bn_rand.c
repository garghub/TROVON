static int F_1 ( int V_1 , T_1 * V_2 , int V_3 , int V_4 , int V_5 )
{
unsigned char * V_6 = NULL ;
int V_7 = 0 , V_8 , V_9 , V_10 ;
T_2 V_11 ;
if ( V_3 < 0 || ( V_3 == 1 && V_4 > 0 ) ) {
F_2 ( V_12 , V_13 ) ;
return 0 ;
}
if ( V_3 == 0 ) {
F_3 ( V_2 ) ;
return 1 ;
}
V_9 = ( V_3 + 7 ) / 8 ;
V_8 = ( V_3 - 1 ) % 8 ;
V_10 = 0xff << ( V_8 + 1 ) ;
V_6 = F_4 ( V_9 ) ;
if ( V_6 == NULL ) {
F_2 ( V_12 , V_14 ) ;
goto V_15;
}
time ( & V_11 ) ;
F_5 ( & V_11 , sizeof( V_11 ) , 0.0 ) ;
if ( F_6 ( V_6 , V_9 ) <= 0 )
goto V_15;
if ( V_1 == 2 ) {
int V_16 ;
unsigned char V_17 ;
for ( V_16 = 0 ; V_16 < V_9 ; V_16 ++ ) {
if ( F_6 ( & V_17 , 1 ) <= 0 )
goto V_15;
if ( V_17 >= 128 && V_16 > 0 )
V_6 [ V_16 ] = V_6 [ V_16 - 1 ] ;
else if ( V_17 < 42 )
V_6 [ V_16 ] = 0 ;
else if ( V_17 < 84 )
V_6 [ V_16 ] = 255 ;
}
}
if ( V_4 >= 0 ) {
if ( V_4 ) {
if ( V_8 == 0 ) {
V_6 [ 0 ] = 1 ;
V_6 [ 1 ] |= 0x80 ;
} else {
V_6 [ 0 ] |= ( 3 << ( V_8 - 1 ) ) ;
}
} else {
V_6 [ 0 ] |= ( 1 << V_8 ) ;
}
}
V_6 [ 0 ] &= ~ V_10 ;
if ( V_5 )
V_6 [ V_9 - 1 ] |= 1 ;
if ( ! F_7 ( V_6 , V_9 , V_2 ) )
goto V_15;
V_7 = 1 ;
V_15:
F_8 ( V_6 , V_9 ) ;
F_9 ( V_2 ) ;
return ( V_7 ) ;
}
int F_10 ( T_1 * V_2 , int V_3 , int V_4 , int V_5 )
{
return F_1 ( 0 , V_2 , V_3 , V_4 , V_5 ) ;
}
int F_11 ( T_1 * V_2 , int V_3 , int V_4 , int V_5 )
{
return F_1 ( 1 , V_2 , V_3 , V_4 , V_5 ) ;
}
int F_12 ( T_1 * V_2 , int V_3 , int V_4 , int V_5 )
{
return F_1 ( 2 , V_2 , V_3 , V_4 , V_5 ) ;
}
static int F_13 ( int V_18 , T_1 * V_19 , const T_1 * V_20 )
{
int (* F_14) ( T_1 * , int , int , int ) =
V_18 ? F_11 : F_10 ;
int V_21 ;
int V_22 = 100 ;
if ( V_20 -> V_23 || F_15 ( V_20 ) ) {
F_2 ( V_24 , V_25 ) ;
return 0 ;
}
V_21 = F_16 ( V_20 ) ;
if ( V_21 == 1 )
F_3 ( V_19 ) ;
else if ( ! F_17 ( V_20 , V_21 - 2 ) && ! F_17 ( V_20 , V_21 - 3 ) ) {
do {
if ( ! F_14 ( V_19 , V_21 + 1 , V_26 , V_27 ) )
return 0 ;
if ( F_18 ( V_19 , V_20 ) >= 0 ) {
if ( ! F_19 ( V_19 , V_19 , V_20 ) )
return 0 ;
if ( F_18 ( V_19 , V_20 ) >= 0 )
if ( ! F_19 ( V_19 , V_19 , V_20 ) )
return 0 ;
}
if ( ! -- V_22 ) {
F_2 ( V_24 , V_28 ) ;
return 0 ;
}
}
while ( F_18 ( V_19 , V_20 ) >= 0 );
} else {
do {
if ( ! F_14 ( V_19 , V_21 , V_26 , V_27 ) )
return 0 ;
if ( ! -- V_22 ) {
F_2 ( V_24 , V_28 ) ;
return 0 ;
}
}
while ( F_18 ( V_19 , V_20 ) >= 0 );
}
F_9 ( V_19 ) ;
return 1 ;
}
int F_20 ( T_1 * V_19 , const T_1 * V_20 )
{
return F_13 ( 0 , V_19 , V_20 ) ;
}
int F_21 ( T_1 * V_19 , const T_1 * V_20 )
{
return F_13 ( 1 , V_19 , V_20 ) ;
}
int F_22 ( T_1 * V_29 , const T_1 * V_20 ,
const T_1 * V_30 , const unsigned char * V_31 ,
T_3 V_32 , T_4 * V_33 )
{
T_5 V_34 ;
unsigned char V_35 [ 64 ] ;
unsigned char V_36 [ V_37 ] ;
unsigned V_38 , V_39 ;
const unsigned V_40 = F_23 ( V_20 ) + 8 ;
unsigned char V_41 [ 96 ] ;
unsigned char * V_42 ;
int V_7 = 0 ;
V_42 = F_4 ( V_40 ) ;
if ( V_42 == NULL )
goto V_15;
V_39 = sizeof( V_30 -> V_43 [ 0 ] ) * V_30 -> V_4 ;
if ( V_39 > sizeof( V_41 ) ) {
F_2 ( V_44 , V_45 ) ;
goto V_15;
}
memcpy ( V_41 , V_30 -> V_43 , V_39 ) ;
memset ( V_41 + V_39 , 0 , sizeof( V_41 ) - V_39 ) ;
for ( V_38 = 0 ; V_38 < V_40 ; ) {
if ( F_6 ( V_35 , sizeof( V_35 ) ) != 1 )
goto V_15;
F_24 ( & V_34 ) ;
F_25 ( & V_34 , & V_38 , sizeof( V_38 ) ) ;
F_25 ( & V_34 , V_41 , sizeof( V_41 ) ) ;
F_25 ( & V_34 , V_31 , V_32 ) ;
F_25 ( & V_34 , V_35 , sizeof( V_35 ) ) ;
F_26 ( V_36 , & V_34 ) ;
V_39 = V_40 - V_38 ;
if ( V_39 > V_37 )
V_39 = V_37 ;
memcpy ( V_42 + V_38 , V_36 , V_39 ) ;
V_38 += V_39 ;
}
if ( ! F_7 ( V_42 , V_40 , V_29 ) )
goto V_15;
if ( F_27 ( V_29 , V_29 , V_20 , V_33 ) != 1 )
goto V_15;
V_7 = 1 ;
V_15:
F_28 ( V_42 ) ;
return V_7 ;
}
