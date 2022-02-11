static unsigned int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_2 -> V_5 = V_6 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_11 = 0 ;
V_2 -> V_12 = 0 ;
V_2 -> V_13 = V_14 ;
V_2 -> V_15 = V_16 ;
return 2 ;
}
static inline unsigned char F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_4 -> V_17 ( V_2 -> V_4 , 1 ) ;
}
static inline unsigned char F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_4 -> V_17 ( V_2 -> V_4 , 0 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , unsigned char V_18 )
{
V_2 -> V_4 -> V_19 ( V_2 -> V_4 , 1 , V_18 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , unsigned char V_18 )
{
V_2 -> V_4 -> V_19 ( V_2 -> V_4 , 0 , V_18 ) ;
}
static inline void F_6 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_2 -> F_5 [ V_2 -> V_7 ] ) ;
( V_2 -> V_7 ) ++ ;
( V_2 -> V_8 ) -- ;
}
static inline void F_7 ( struct V_1 * V_2 , char * V_20 )
{
( V_2 -> V_11 ) ++ ;
if ( V_2 -> V_11 > V_21 ) {
if ( V_22 & V_23 )
F_8 ( V_24 L_1 ,
V_20 ) ;
V_2 -> V_5 = V_25 ;
} else {
V_2 -> V_26 = V_27 + V_28 ;
V_2 -> V_5 = V_29 ;
}
}
static inline void F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 >= V_30 ) {
F_3 ( V_2 ) ;
V_2 -> V_12 = 1 ;
} else {
V_2 -> F_3 [ V_2 -> V_10 ] = F_3 ( V_2 ) ;
( V_2 -> V_10 ) ++ ;
}
F_5 ( V_2 , V_31 ) ;
}
static inline int F_10 ( struct V_1 * V_2 , unsigned char V_32 ,
long time )
{
if ( F_11 ( V_32 ) ) {
V_2 -> V_13 -= time ;
if ( V_2 -> V_13 < 0 ) {
F_7 ( V_2 , L_2 ) ;
V_2 -> V_13 = V_14 ;
return 1 ;
}
return 0 ;
}
V_2 -> V_13 = V_14 ;
return 1 ;
}
static inline int F_12 ( struct V_1 * V_2 , unsigned char V_32 ,
long time )
{
if ( ! F_13 ( V_32 ) ) {
V_2 -> V_15 -= time ;
if ( V_2 -> V_15 < 0 ) {
F_7 ( V_2 , L_3 ) ;
return 1 ;
}
return 0 ;
}
V_2 -> V_15 = V_16 ;
return 1 ;
}
static void F_14 ( struct V_1 * V_2 , unsigned char V_32 )
{
if ( F_13 ( V_32 ) )
F_3 ( V_2 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
V_2 -> V_8 = V_2 -> V_9 ;
V_2 -> V_7 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_5 = V_33 ;
V_2 -> V_13 = V_14 ;
V_2 -> V_15 = V_16 ;
F_4 ( V_2 , V_34 ) ;
}
static int F_16 ( struct V_1 * V_2 , unsigned char * V_18 ,
unsigned int V_35 )
{
unsigned int V_36 ;
if ( V_35 < 2 )
return V_37 ;
if ( V_35 > V_38 )
return V_39 ;
if ( ( V_2 -> V_5 != V_6 ) && ( V_2 -> V_5 != V_25 ) )
return V_40 ;
if ( V_22 & V_41 ) {
F_8 ( V_24 L_4 ) ;
for ( V_36 = 0 ; V_36 < V_35 ; V_36 ++ )
F_8 ( L_5 , ( unsigned char ) ( V_18 [ V_36 ] ) ) ;
F_8 ( L_6 ) ;
}
V_2 -> V_11 = 0 ;
memcpy ( V_2 -> F_5 , V_18 , V_35 ) ;
V_2 -> V_8 = V_35 ;
V_2 -> V_9 = V_35 ;
V_2 -> V_7 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_5 = V_42 ;
V_2 -> V_13 = V_14 ;
V_2 -> V_15 = V_16 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , unsigned char * V_18 ,
unsigned int V_43 )
{
if ( V_43 < V_2 -> V_10 ) {
V_2 -> V_10 = V_43 ;
V_2 -> V_12 = 1 ;
}
memcpy ( V_18 , V_2 -> F_3 , V_2 -> V_10 ) ;
if ( ( V_43 >= 3 ) && ( V_2 -> V_10 < 3 ) ) {
V_18 [ 2 ] = V_44 ;
V_2 -> V_10 = 3 ;
}
if ( V_2 -> V_12 ) {
V_18 [ 2 ] = V_45 ;
V_2 -> V_12 = 0 ;
}
return V_2 -> V_10 ;
}
static enum V_46 F_18 ( struct V_1 * V_2 , long time )
{
unsigned char V_32 ;
unsigned char V_5 ;
V_32 = F_2 ( V_2 ) ;
if ( V_22 & V_47 )
F_8 ( V_24 L_7 , V_2 -> V_5 , V_32 ) ;
if ( ! F_10 ( V_2 , V_32 , time ) )
return V_48 ;
V_5 = F_19 ( V_32 ) ;
switch ( V_2 -> V_5 ) {
case V_6 :
F_14 ( V_2 , V_32 ) ;
if ( F_20 ( V_32 ) )
return V_49 ;
else
return V_50 ;
case V_42 :
if ( V_5 != V_51 ) {
F_7 ( V_2 ,
L_8 ) ;
break;
}
F_14 ( V_2 , V_32 ) ;
F_4 ( V_2 , V_34 ) ;
V_2 -> V_5 = V_33 ;
break;
case V_33 :
if ( V_5 != V_52 ) {
F_7 (
V_2 ,
L_9 ) ;
break;
}
F_3 ( V_2 ) ;
if ( V_2 -> V_8 == 1 ) {
F_4 ( V_2 , V_53 ) ;
V_2 -> V_5 = V_54 ;
} else {
F_6 ( V_2 ) ;
V_2 -> V_5 = V_55 ;
}
break;
case V_55 :
if ( V_5 != V_52 ) {
F_7 ( V_2 ,
L_10 ) ;
break;
}
F_14 ( V_2 , V_32 ) ;
if ( V_2 -> V_8 == 1 ) {
F_4 ( V_2 , V_53 ) ;
V_2 -> V_5 = V_54 ;
} else {
F_6 ( V_2 ) ;
}
break;
case V_54 :
if ( V_5 != V_52 ) {
F_7 ( V_2 ,
L_11
L_12 ) ;
break;
}
F_14 ( V_2 , V_32 ) ;
F_6 ( V_2 ) ;
V_2 -> V_5 = V_56 ;
break;
case V_56 :
if ( ( V_5 != V_57 ) && ( V_5 != V_51 ) ) {
F_7 (
V_2 ,
L_13 ) ;
break;
}
if ( V_5 == V_57 ) {
if ( ! F_12 ( V_2 , V_32 , time ) )
return V_48 ;
F_9 ( V_2 ) ;
} else {
F_14 ( V_2 , V_32 ) ;
V_2 -> V_9 = 0 ;
V_2 -> V_5 = V_6 ;
return V_58 ;
}
break;
case V_29 :
F_14 ( V_2 , V_32 ) ;
V_32 = F_2 ( V_2 ) ;
if ( F_13 ( V_32 ) )
if ( F_21 ( V_27 , V_2 -> V_26 ) )
return V_59 ;
F_4 ( V_2 , V_60 ) ;
V_2 -> V_5 = V_61 ;
break;
case V_61 :
F_14 ( V_2 , V_32 ) ;
F_5 ( V_2 , 0 ) ;
V_2 -> V_5 = V_62 ;
break;
case V_62 :
if ( V_5 != V_57 ) {
F_7 ( V_2 ,
L_14 ) ;
break;
}
if ( ! F_12 ( V_2 , V_32 , time ) )
return V_48 ;
F_14 ( V_2 , V_32 ) ;
F_5 ( V_2 , V_31 ) ;
V_2 -> V_5 = V_63 ;
break;
case V_63 :
if ( V_5 != V_51 ) {
F_7 ( V_2 ,
L_15 ) ;
break;
}
if ( ! F_12 ( V_2 , V_32 , time ) )
return V_48 ;
F_14 ( V_2 , V_32 ) ;
if ( V_2 -> V_9 ) {
F_15 ( V_2 ) ;
} else {
V_2 -> V_5 = V_6 ;
return V_58 ;
}
break;
case V_25 :
break;
}
if ( V_2 -> V_5 == V_25 ) {
F_1 ( V_2 , V_2 -> V_4 ) ;
return V_64 ;
}
return V_65 ;
}
static int F_22 ( void )
{
return sizeof( struct V_1 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) == 0xff )
return 1 ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
}
