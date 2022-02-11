T_1 * F_1 ( const T_1 * V_1 )
{
return F_2 ( V_1 ) ;
}
int F_3 ( const T_1 * V_1 , const T_1 * V_2 )
{
int V_3 , V_4 ;
V_3 = V_1 -> type & V_5 ;
if ( V_3 != ( V_2 -> type & V_5 ) ) {
if ( V_3 )
return - 1 ;
else
return 1 ;
}
V_4 = F_4 ( V_1 , V_2 ) ;
if ( V_3 )
return - V_4 ;
else
return V_4 ;
}
static T_2 F_5 ( const unsigned char * V_6 , T_2 V_7 , int V_3 ,
unsigned char * * V_8 )
{
int V_9 = 0 ;
T_2 V_4 , V_10 ;
unsigned char * V_11 , V_12 = 0 ;
const unsigned char * V_13 ;
if ( V_6 == NULL || V_7 == 0 )
V_4 = 1 ;
else {
V_4 = V_7 ;
V_10 = V_6 [ 0 ] ;
if ( V_4 == 1 && V_10 == 0 )
V_3 = 0 ;
if ( ! V_3 && ( V_10 > 127 ) ) {
V_9 = 1 ;
V_12 = 0 ;
} else if ( V_3 ) {
if ( V_10 > 128 ) {
V_9 = 1 ;
V_12 = 0xFF ;
} else if ( V_10 == 128 ) {
for ( V_10 = 1 ; V_10 < V_7 ; V_10 ++ )
if ( V_6 [ V_10 ] ) {
V_9 = 1 ;
V_12 = 0xFF ;
break;
}
}
}
V_4 += V_9 ;
}
if ( V_8 == NULL )
return V_4 ;
V_11 = * V_8 ;
if ( V_9 )
* ( V_11 ++ ) = V_12 ;
if ( V_6 == NULL || V_7 == 0 )
* V_11 = 0 ;
else if ( ! V_3 )
memcpy ( V_11 , V_6 , V_7 ) ;
else {
V_13 = V_6 + V_7 ;
V_11 += V_7 ;
V_10 = V_7 ;
while ( ! V_13 [ - 1 ] && V_10 > 1 ) {
* ( -- V_11 ) = 0 ;
V_13 -- ;
V_10 -- ;
}
* ( -- V_11 ) = ( ( * ( -- V_13 ) ) ^ 0xff ) + 1 ;
V_10 -- ;
for (; V_10 > 0 ; V_10 -- )
* ( -- V_11 ) = * ( -- V_13 ) ^ 0xff ;
}
* V_8 += V_4 ;
return V_4 ;
}
static T_2 F_6 ( unsigned char * V_6 , int * V_14 ,
const unsigned char * V_11 , T_2 V_15 )
{
T_2 V_10 ;
int V_3 , V_9 ;
if ( V_15 == 0 ) {
F_7 ( V_16 , V_17 ) ;
return 0 ;
}
V_3 = V_11 [ 0 ] & 0x80 ;
if ( V_14 )
* V_14 = V_3 ;
if ( V_15 == 1 ) {
if ( V_6 ) {
if ( V_3 )
V_6 [ 0 ] = ( V_11 [ 0 ] ^ 0xFF ) + 1 ;
else
V_6 [ 0 ] = V_11 [ 0 ] ;
}
return 1 ;
}
if ( V_11 [ 0 ] == 0 || V_11 [ 0 ] == 0xFF )
V_9 = 1 ;
else
V_9 = 0 ;
if ( V_9 && ( V_3 == ( V_11 [ 1 ] & 0x80 ) ) ) {
F_7 ( V_16 , V_18 ) ;
return 0 ;
}
if ( V_3 == 0 ) {
if ( V_6 )
memcpy ( V_6 , V_11 + V_9 , V_15 - V_9 ) ;
return V_15 - V_9 ;
}
if ( V_3 && V_9 ) {
for ( V_10 = 1 ; V_10 < V_15 ; V_10 ++ ) {
if ( V_11 [ V_10 ] != 0 )
break;
}
if ( V_10 == V_15 ) {
if ( V_6 ) {
V_6 [ 0 ] = 1 ;
memset ( V_6 + 1 , 0 , V_15 - 1 ) ;
}
return V_15 ;
}
}
V_15 -= V_9 ;
if ( V_6 ) {
const unsigned char * V_19 = V_11 + V_15 - 1 + V_9 ;
unsigned char * V_20 = V_6 + V_15 ;
V_10 = V_15 ;
while ( * V_19 == 0 && V_10 ) {
* -- V_20 = 0 ;
V_10 -- ;
V_19 -- ;
}
* -- V_20 = ( * V_19 -- ^ 0xff ) + 1 ;
F_8 ( V_10 != 0 ) ;
V_10 -- ;
for (; V_10 > 0 ; V_10 -- )
* -- V_20 = * V_19 -- ^ 0xff ;
}
return V_15 ;
}
int F_9 ( T_1 * V_21 , unsigned char * * V_8 )
{
return F_5 ( V_21 -> V_22 , V_21 -> V_23 , V_21 -> type & V_5 , V_8 ) ;
}
static int F_10 ( T_3 * V_24 , const unsigned char * V_6 , T_2 V_7 )
{
T_2 V_10 ;
if ( V_7 > sizeof( * V_24 ) ) {
F_7 ( V_25 , V_26 ) ;
return 0 ;
}
* V_24 = 0 ;
if ( V_6 == NULL )
return 0 ;
for ( V_10 = 0 ; V_10 < V_7 ; V_10 ++ ) {
* V_24 <<= 8 ;
* V_24 |= V_6 [ V_10 ] ;
}
return 1 ;
}
static T_2 F_11 ( unsigned char * V_6 , T_3 V_27 )
{
if ( V_27 >= 0x100 ) {
unsigned char * V_11 ;
T_3 V_28 = V_27 ;
T_2 V_10 = 0 ;
while ( V_28 ) {
V_28 >>= 8 ;
V_10 ++ ;
}
V_11 = V_6 + V_10 - 1 ;
do {
* V_11 -- = V_27 & 0xFF ;
V_27 >>= 8 ;
} while ( V_11 >= V_6 );
return V_10 ;
}
V_6 [ 0 ] = ( unsigned char ) V_27 ;
return 1 ;
}
static int F_12 ( T_4 * V_24 , const unsigned char * V_6 , T_2 V_7 ,
int V_3 )
{
T_3 V_27 ;
if ( F_10 ( & V_27 , V_6 , V_7 ) == 0 )
return 0 ;
if ( V_3 ) {
if ( V_27 > V_29 ) {
F_7 ( V_30 , V_31 ) ;
return 0 ;
}
* V_24 = - ( T_4 ) V_27 ;
} else {
if ( V_27 > V_32 ) {
F_7 ( V_30 , V_26 ) ;
return 0 ;
}
* V_24 = ( T_4 ) V_27 ;
}
return 1 ;
}
T_1 * F_13 ( T_1 * * V_21 , const unsigned char * * V_8 ,
long V_33 )
{
T_1 * V_4 = NULL ;
T_2 V_27 ;
int V_3 ;
V_27 = F_6 ( NULL , NULL , * V_8 , V_33 ) ;
if ( V_27 == 0 )
return NULL ;
if ( ( V_21 == NULL ) || ( ( * V_21 ) == NULL ) ) {
V_4 = F_14 () ;
if ( V_4 == NULL )
return NULL ;
V_4 -> type = V_34 ;
} else
V_4 = * V_21 ;
if ( F_15 ( V_4 , NULL , V_27 ) == 0 )
goto V_35;
F_6 ( V_4 -> V_22 , & V_3 , * V_8 , V_33 ) ;
if ( V_3 )
V_4 -> type |= V_5 ;
* V_8 += V_33 ;
if ( V_21 != NULL )
( * V_21 ) = V_4 ;
return V_4 ;
V_35:
F_7 ( V_36 , V_37 ) ;
if ( ( V_21 == NULL ) || ( * V_21 != V_4 ) )
F_16 ( V_4 ) ;
return NULL ;
}
static int F_17 ( T_4 * V_24 , const T_5 * V_21 , int V_38 )
{
if ( V_21 == NULL ) {
F_7 ( V_39 , V_40 ) ;
return 0 ;
}
if ( ( V_21 -> type & ~ V_5 ) != V_38 ) {
F_7 ( V_39 , V_41 ) ;
return 0 ;
}
return F_12 ( V_24 , V_21 -> V_22 , V_21 -> V_23 , V_21 -> type & V_5 ) ;
}
static int F_18 ( T_5 * V_21 , T_4 V_27 , int V_38 )
{
unsigned char V_42 [ sizeof( V_27 ) ] ;
T_2 V_43 ;
V_21 -> type = V_38 ;
if ( V_27 < 0 ) {
V_43 = F_11 ( V_42 , - V_27 ) ;
V_21 -> type |= V_5 ;
} else {
V_43 = F_11 ( V_42 , V_27 ) ;
V_21 -> type &= ~ V_5 ;
}
if ( V_43 == 0 )
return 0 ;
return F_15 ( V_21 , V_42 , V_43 ) ;
}
static int F_19 ( T_3 * V_24 , const T_5 * V_21 ,
int V_38 )
{
if ( V_21 == NULL ) {
F_7 ( V_44 , V_40 ) ;
return 0 ;
}
if ( ( V_21 -> type & ~ V_5 ) != V_38 ) {
F_7 ( V_44 , V_41 ) ;
return 0 ;
}
if ( V_21 -> type & V_5 ) {
F_7 ( V_44 , V_45 ) ;
return 0 ;
}
return F_10 ( V_24 , V_21 -> V_22 , V_21 -> V_23 ) ;
}
static int F_20 ( T_5 * V_21 , T_3 V_27 , int V_38 )
{
unsigned char V_42 [ sizeof( V_27 ) ] ;
T_2 V_43 ;
V_21 -> type = V_38 ;
V_43 = F_11 ( V_42 , V_27 ) ;
if ( V_43 == 0 )
return 0 ;
return F_15 ( V_21 , V_42 , V_43 ) ;
}
T_1 * F_21 ( T_1 * * V_21 , const unsigned char * * V_8 ,
long V_23 )
{
T_1 * V_4 = NULL ;
const unsigned char * V_11 ;
unsigned char * V_46 ;
long V_33 ;
int V_47 , V_48 , V_49 ;
int V_10 ;
if ( ( V_21 == NULL ) || ( ( * V_21 ) == NULL ) ) {
if ( ( V_4 = F_14 () ) == NULL )
return ( NULL ) ;
V_4 -> type = V_34 ;
} else
V_4 = ( * V_21 ) ;
V_11 = * V_8 ;
V_47 = F_22 ( & V_11 , & V_33 , & V_48 , & V_49 , V_23 ) ;
if ( V_47 & 0x80 ) {
V_10 = V_50 ;
goto V_35;
}
if ( V_48 != V_34 ) {
V_10 = V_51 ;
goto V_35;
}
V_46 = F_23 ( ( int ) V_33 + 1 ) ;
if ( V_46 == NULL ) {
V_10 = V_37 ;
goto V_35;
}
V_4 -> type = V_34 ;
if ( V_33 ) {
if ( ( * V_11 == 0 ) && ( V_33 != 1 ) ) {
V_11 ++ ;
V_33 -- ;
}
memcpy ( V_46 , V_11 , ( int ) V_33 ) ;
V_11 += V_33 ;
}
F_24 ( V_4 -> V_22 ) ;
V_4 -> V_22 = V_46 ;
V_4 -> V_23 = ( int ) V_33 ;
if ( V_21 != NULL )
( * V_21 ) = V_4 ;
* V_8 = V_11 ;
return ( V_4 ) ;
V_35:
F_7 ( V_52 , V_10 ) ;
if ( ( V_21 == NULL ) || ( * V_21 != V_4 ) )
F_16 ( V_4 ) ;
return ( NULL ) ;
}
static T_5 * F_25 ( const T_6 * V_53 , T_5 * V_54 ,
int V_55 )
{
T_1 * V_4 ;
int V_33 ;
if ( V_54 == NULL ) {
V_4 = F_26 ( V_55 ) ;
} else {
V_4 = V_54 ;
V_4 -> type = V_55 ;
}
if ( V_4 == NULL ) {
F_7 ( V_56 , V_57 ) ;
goto V_35;
}
if ( F_27 ( V_53 ) && ! F_28 ( V_53 ) )
V_4 -> type |= V_58 ;
V_33 = F_29 ( V_53 ) ;
if ( V_33 == 0 )
V_33 = 1 ;
if ( F_15 ( V_4 , NULL , V_33 ) == 0 ) {
F_7 ( V_56 , V_37 ) ;
goto V_35;
}
if ( F_28 ( V_53 ) )
V_4 -> V_22 [ 0 ] = 0 ;
else
V_33 = F_30 ( V_53 , V_4 -> V_22 ) ;
V_4 -> V_23 = V_33 ;
return V_4 ;
V_35:
if ( V_4 != V_54 )
F_16 ( V_4 ) ;
return ( NULL ) ;
}
static T_6 * F_31 ( const T_1 * V_54 , T_6 * V_53 ,
int V_38 )
{
T_6 * V_4 ;
if ( ( V_54 -> type & ~ V_5 ) != V_38 ) {
F_7 ( V_59 , V_41 ) ;
return NULL ;
}
V_4 = F_32 ( V_54 -> V_22 , V_54 -> V_23 , V_53 ) ;
if ( V_4 == 0 ) {
F_7 ( V_59 , V_60 ) ;
return NULL ;
}
if ( V_54 -> type & V_5 )
F_33 ( V_4 , 1 ) ;
return V_4 ;
}
int F_34 ( T_4 * V_24 , const T_1 * V_21 )
{
return F_17 ( V_24 , V_21 , V_34 ) ;
}
int F_35 ( T_1 * V_21 , T_4 V_27 )
{
return F_18 ( V_21 , V_27 , V_34 ) ;
}
int F_36 ( T_3 * V_24 , const T_1 * V_21 )
{
return F_19 ( V_24 , V_21 , V_34 ) ;
}
int F_37 ( T_1 * V_21 , T_3 V_27 )
{
return F_20 ( V_21 , V_27 , V_34 ) ;
}
int F_38 ( T_1 * V_21 , long V_61 )
{
return F_35 ( V_21 , V_61 ) ;
}
long F_39 ( const T_1 * V_21 )
{
int V_10 ;
T_4 V_27 ;
if ( V_21 == NULL )
return 0 ;
V_10 = F_34 ( & V_27 , V_21 ) ;
if ( V_10 == 0 )
return - 1 ;
if ( V_27 > V_62 || V_27 < V_63 )
return - 1 ;
return ( long ) V_27 ;
}
T_1 * F_40 ( const T_6 * V_53 , T_1 * V_54 )
{
return F_25 ( V_53 , V_54 , V_34 ) ;
}
T_6 * F_41 ( const T_1 * V_54 , T_6 * V_53 )
{
return F_31 ( V_54 , V_53 , V_34 ) ;
}
int F_42 ( T_4 * V_24 , const T_7 * V_21 )
{
return F_17 ( V_24 , V_21 , V_64 ) ;
}
int F_43 ( T_7 * V_21 , T_4 V_27 )
{
return F_18 ( V_21 , V_27 , V_64 ) ;
}
int F_44 ( T_7 * V_21 , long V_61 )
{
return F_43 ( V_21 , V_61 ) ;
}
long F_45 ( const T_7 * V_21 )
{
int V_10 ;
T_4 V_27 ;
if ( V_21 == NULL )
return 0 ;
if ( ( V_21 -> type & ~ V_5 ) != V_64 )
return - 1 ;
if ( V_21 -> V_23 > ( int ) sizeof( long ) )
return 0xffffffffL ;
V_10 = F_42 ( & V_27 , V_21 ) ;
if ( V_10 == 0 )
return - 1 ;
if ( V_27 > V_62 || V_27 < V_63 )
return - 1 ;
return ( long ) V_27 ;
}
T_7 * F_46 ( const T_6 * V_53 , T_7 * V_54 )
{
return F_25 ( V_53 , V_54 , V_64 ) ;
}
T_6 * F_47 ( const T_7 * V_54 , T_6 * V_53 )
{
return F_31 ( V_54 , V_53 , V_64 ) ;
}
