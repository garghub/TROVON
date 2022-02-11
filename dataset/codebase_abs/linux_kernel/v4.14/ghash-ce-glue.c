static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_4 = (struct V_3 ) {} ;
return 0 ;
}
static void F_3 ( int V_5 , T_1 V_6 [] , const char * V_7 ,
struct V_8 * V_9 , const char * V_10 )
{
if ( F_4 ( F_5 () ) ) {
F_6 () ;
F_7 ( V_5 , V_6 , V_7 , V_9 , V_10 ) ;
F_8 () ;
} else {
T_2 V_11 = { F_9 ( V_6 [ 1 ] ) , F_9 (dg[0]) } ;
do {
const T_3 * V_12 = V_7 ;
if ( V_10 ) {
V_12 = V_10 ;
V_5 ++ ;
V_10 = NULL ;
} else {
V_7 += V_13 ;
}
F_10 ( ( T_3 * ) & V_11 , V_12 , V_13 ) ;
F_11 ( & V_11 , & V_9 -> V_14 ) ;
} while ( -- V_5 );
V_6 [ 0 ] = F_12 ( V_11 . V_15 ) ;
V_6 [ 1 ] = F_12 ( V_11 . V_16 ) ;
}
}
static int F_13 ( struct V_1 * V_2 , const T_3 * V_7 ,
unsigned int V_17 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_18 = V_4 -> V_19 % V_13 ;
V_4 -> V_19 += V_17 ;
if ( ( V_18 + V_17 ) >= V_13 ) {
struct V_8 * V_9 = F_14 ( V_2 -> V_20 ) ;
int V_5 ;
if ( V_18 ) {
int V_21 = V_13 - V_18 ;
memcpy ( V_4 -> V_22 + V_18 , V_7 , V_21 ) ;
V_7 += V_21 ;
V_17 -= V_21 ;
}
V_5 = V_17 / V_13 ;
V_17 %= V_13 ;
F_3 ( V_5 , V_4 -> V_23 , V_7 , V_9 ,
V_18 ? V_4 -> V_22 : NULL ) ;
V_7 += V_5 * V_13 ;
V_18 = 0 ;
}
if ( V_17 )
memcpy ( V_4 -> V_22 + V_18 , V_7 , V_17 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_3 * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_18 = V_4 -> V_19 % V_13 ;
if ( V_18 ) {
struct V_8 * V_9 = F_14 ( V_2 -> V_20 ) ;
memset ( V_4 -> V_22 + V_18 , 0 , V_13 - V_18 ) ;
F_3 ( 1 , V_4 -> V_23 , V_4 -> V_22 , V_9 , NULL ) ;
}
F_16 ( V_4 -> V_23 [ 1 ] , V_11 ) ;
F_16 ( V_4 -> V_23 [ 0 ] , V_11 + 8 ) ;
* V_4 = (struct V_3 ) {} ;
return 0 ;
}
static int F_17 ( struct V_8 * V_9 ,
const T_3 * V_24 , unsigned int V_25 )
{
T_1 V_16 , V_15 ;
memcpy ( & V_9 -> V_14 , V_24 , V_13 ) ;
V_15 = F_18 ( V_24 ) ;
V_16 = F_18 ( V_24 + 8 ) ;
V_9 -> V_16 = ( V_16 << 1 ) | ( V_15 >> 63 ) ;
V_9 -> V_15 = ( V_15 << 1 ) | ( V_16 >> 63 ) ;
if ( V_15 >> 63 )
V_9 -> V_15 ^= 0xc200000000000000UL ;
return 0 ;
}
static int F_19 ( struct V_26 * V_20 ,
const T_3 * V_24 , unsigned int V_25 )
{
struct V_8 * V_9 = F_14 ( V_20 ) ;
if ( V_25 != V_13 ) {
F_20 ( V_20 , V_27 ) ;
return - V_28 ;
}
return F_17 ( V_9 , V_24 , V_25 ) ;
}
static int F_21 ( struct V_29 * V_4 )
{
return 6 + V_4 -> V_30 / 4 ;
}
static int F_22 ( struct V_31 * V_20 , const T_3 * V_24 ,
unsigned int V_25 )
{
struct V_32 * V_4 = F_23 ( V_20 ) ;
T_3 V_9 [ V_13 ] ;
int V_33 ;
V_33 = F_24 ( & V_4 -> V_34 , V_24 , V_25 ) ;
if ( V_33 ) {
V_20 -> V_35 . V_36 |= V_27 ;
return - V_28 ;
}
F_25 (ctx->aes_key.key_enc, key, (u8[AES_BLOCK_SIZE]){},
num_rounds(&ctx->aes_key)) ;
return F_17 ( & V_4 -> V_8 , V_9 , sizeof( V_9 ) ) ;
}
static int F_26 ( struct V_31 * V_20 , unsigned int V_37 )
{
switch ( V_37 ) {
case 4 :
case 8 :
case 12 ... 16 :
break;
default:
return - V_28 ;
}
return 0 ;
}
static void F_27 ( T_1 V_6 [] , const T_3 * V_7 , int V_19 , T_3 V_22 [] ,
int * V_38 , struct V_32 * V_4 )
{
if ( * V_38 > 0 ) {
int V_39 = F_28 ( V_19 , V_13 - * V_38 ) ;
memcpy ( & V_22 [ * V_38 ] , V_7 , V_39 ) ;
* V_38 += V_39 ;
V_7 += V_39 ;
V_19 -= V_39 ;
}
if ( V_19 >= V_13 || * V_38 == V_13 ) {
int V_5 = V_19 / V_13 ;
F_3 ( V_5 , V_6 , V_7 , & V_4 -> V_8 ,
* V_38 ? V_22 : NULL ) ;
V_7 += V_5 * V_13 ;
V_19 %= V_13 ;
* V_38 = 0 ;
}
if ( V_19 > 0 ) {
memcpy ( V_22 , V_7 , V_19 ) ;
* V_38 = V_19 ;
}
}
static void F_29 ( struct V_40 * V_41 , T_1 V_6 [] )
{
struct V_31 * V_42 = F_30 ( V_41 ) ;
struct V_32 * V_4 = F_23 ( V_42 ) ;
T_3 V_22 [ V_13 ] ;
struct V_43 V_44 ;
T_4 V_17 = V_41 -> V_45 ;
int V_38 = 0 ;
F_31 ( & V_44 , V_41 -> V_7 ) ;
do {
T_4 V_46 = F_32 ( & V_44 , V_17 ) ;
T_3 * V_21 ;
if ( ! V_46 ) {
F_31 ( & V_44 , F_33 ( V_44 . V_47 ) ) ;
V_46 = F_32 ( & V_44 , V_17 ) ;
}
V_21 = F_34 ( & V_44 ) ;
F_27 ( V_6 , V_21 , V_46 , V_22 , & V_38 , V_4 ) ;
V_17 -= V_46 ;
F_35 ( V_21 ) ;
F_36 ( & V_44 , V_46 ) ;
F_37 ( & V_44 , 0 , V_17 ) ;
} while ( V_17 );
if ( V_38 ) {
memset ( & V_22 [ V_38 ] , 0 , V_13 - V_38 ) ;
F_3 ( 1 , V_6 , V_22 , & V_4 -> V_8 , NULL ) ;
}
}
static void F_38 ( struct V_40 * V_41 , struct V_32 * V_4 ,
T_1 V_6 [] , T_3 V_48 [] , int V_49 )
{
T_3 V_50 [ V_51 ] ;
T_5 V_52 ;
V_52 . V_16 = F_9 ( V_41 -> V_45 * 8 ) ;
V_52 . V_15 = F_9 ( V_49 * 8 ) ;
F_3 ( 1 , V_6 , ( void * ) & V_52 , & V_4 -> V_8 , NULL ) ;
F_16 ( V_6 [ 1 ] , V_50 ) ;
F_16 ( V_6 [ 0 ] , V_50 + 8 ) ;
F_10 ( V_48 , V_50 , V_51 ) ;
}
static int F_39 ( struct V_40 * V_41 )
{
struct V_31 * V_42 = F_30 ( V_41 ) ;
struct V_32 * V_4 = F_23 ( V_42 ) ;
struct V_53 V_44 ;
T_3 V_54 [ V_51 ] ;
T_3 V_55 [ V_51 ] ;
T_3 V_48 [ V_51 ] ;
T_1 V_6 [ 2 ] = {} ;
int V_56 ;
if ( V_41 -> V_45 )
F_29 ( V_41 , V_6 ) ;
memcpy ( V_54 , V_41 -> V_54 , V_57 ) ;
F_40 ( 1 , V_54 + V_57 ) ;
if ( F_4 ( F_5 () ) ) {
F_6 () ;
F_41 ( V_48 , V_54 , V_4 -> V_34 . V_58 ,
F_21 ( & V_4 -> V_34 ) ) ;
F_40 ( 2 , V_54 + V_57 ) ;
F_41 ( V_55 , V_54 , NULL ,
F_21 ( & V_4 -> V_34 ) ) ;
F_40 ( 3 , V_54 + V_57 ) ;
V_56 = F_42 ( & V_44 , V_41 , true ) ;
while ( V_44 . V_59 >= V_51 ) {
int V_5 = V_44 . V_59 / V_51 ;
F_43 ( V_5 , V_6 , V_44 . V_11 . V_60 . V_61 ,
V_44 . V_7 . V_60 . V_61 , & V_4 -> V_8 ,
V_54 , F_21 ( & V_4 -> V_34 ) , V_55 ) ;
V_56 = F_44 ( & V_44 ,
V_44 . V_59 % V_51 ) ;
}
F_8 () ;
} else {
F_25 ( V_4 -> V_34 . V_58 , V_48 , V_54 ,
F_21 ( & V_4 -> V_34 ) ) ;
F_40 ( 2 , V_54 + V_57 ) ;
V_56 = F_42 ( & V_44 , V_41 , true ) ;
while ( V_44 . V_59 >= V_51 ) {
int V_5 = V_44 . V_59 / V_51 ;
T_3 * V_11 = V_44 . V_11 . V_60 . V_61 ;
T_3 * V_7 = V_44 . V_7 . V_60 . V_61 ;
do {
F_25 ( V_4 -> V_34 . V_58 ,
V_55 , V_54 ,
F_21 ( & V_4 -> V_34 ) ) ;
F_45 ( V_11 , V_7 , V_55 , V_51 ) ;
F_46 ( V_54 , V_51 ) ;
V_11 += V_51 ;
V_7 += V_51 ;
} while ( -- V_5 > 0 );
F_3 ( V_44 . V_59 / V_51 , V_6 ,
V_44 . V_11 . V_60 . V_61 , & V_4 -> V_8 ,
NULL ) ;
V_56 = F_44 ( & V_44 ,
V_44 . V_59 % V_51 ) ;
}
if ( V_44 . V_59 )
F_25 ( V_4 -> V_34 . V_58 , V_55 , V_54 ,
F_21 ( & V_4 -> V_34 ) ) ;
}
if ( V_44 . V_59 ) {
T_3 V_22 [ V_13 ] ;
F_45 ( V_44 . V_11 . V_60 . V_61 , V_44 . V_7 . V_60 . V_61 , V_55 ,
V_44 . V_59 ) ;
memcpy ( V_22 , V_44 . V_11 . V_60 . V_61 , V_44 . V_59 ) ;
memset ( V_22 + V_44 . V_59 , 0 , V_13 - V_44 . V_59 ) ;
F_3 ( 1 , V_6 , V_22 , & V_4 -> V_8 , NULL ) ;
V_56 = F_44 ( & V_44 , 0 ) ;
}
if ( V_56 )
return V_56 ;
F_38 ( V_41 , V_4 , V_6 , V_48 , V_41 -> V_49 ) ;
F_47 ( V_48 , V_41 -> V_11 , V_41 -> V_45 + V_41 -> V_49 ,
F_48 ( V_42 ) , 1 ) ;
return 0 ;
}
static int F_49 ( struct V_40 * V_41 )
{
struct V_31 * V_42 = F_30 ( V_41 ) ;
struct V_32 * V_4 = F_23 ( V_42 ) ;
unsigned int V_37 = F_48 ( V_42 ) ;
struct V_53 V_44 ;
T_3 V_54 [ V_51 ] ;
T_3 V_48 [ V_51 ] ;
T_3 V_22 [ V_13 ] ;
T_1 V_6 [ 2 ] = {} ;
int V_56 ;
if ( V_41 -> V_45 )
F_29 ( V_41 , V_6 ) ;
memcpy ( V_54 , V_41 -> V_54 , V_57 ) ;
F_40 ( 1 , V_54 + V_57 ) ;
if ( F_4 ( F_5 () ) ) {
F_6 () ;
F_41 ( V_48 , V_54 , V_4 -> V_34 . V_58 ,
F_21 ( & V_4 -> V_34 ) ) ;
F_40 ( 2 , V_54 + V_57 ) ;
V_56 = F_50 ( & V_44 , V_41 , true ) ;
while ( V_44 . V_59 >= V_51 ) {
int V_5 = V_44 . V_59 / V_51 ;
F_51 ( V_5 , V_6 , V_44 . V_11 . V_60 . V_61 ,
V_44 . V_7 . V_60 . V_61 , & V_4 -> V_8 ,
V_54 , F_21 ( & V_4 -> V_34 ) ) ;
V_56 = F_44 ( & V_44 ,
V_44 . V_59 % V_51 ) ;
}
if ( V_44 . V_59 )
F_41 ( V_54 , V_54 , NULL ,
F_21 ( & V_4 -> V_34 ) ) ;
F_8 () ;
} else {
F_25 ( V_4 -> V_34 . V_58 , V_48 , V_54 ,
F_21 ( & V_4 -> V_34 ) ) ;
F_40 ( 2 , V_54 + V_57 ) ;
V_56 = F_50 ( & V_44 , V_41 , true ) ;
while ( V_44 . V_59 >= V_51 ) {
int V_5 = V_44 . V_59 / V_51 ;
T_3 * V_11 = V_44 . V_11 . V_60 . V_61 ;
T_3 * V_7 = V_44 . V_7 . V_60 . V_61 ;
F_3 ( V_5 , V_6 , V_44 . V_7 . V_60 . V_61 ,
& V_4 -> V_8 , NULL ) ;
do {
F_25 ( V_4 -> V_34 . V_58 ,
V_22 , V_54 ,
F_21 ( & V_4 -> V_34 ) ) ;
F_45 ( V_11 , V_7 , V_22 , V_51 ) ;
F_46 ( V_54 , V_51 ) ;
V_11 += V_51 ;
V_7 += V_51 ;
} while ( -- V_5 > 0 );
V_56 = F_44 ( & V_44 ,
V_44 . V_59 % V_51 ) ;
}
if ( V_44 . V_59 )
F_25 ( V_4 -> V_34 . V_58 , V_54 , V_54 ,
F_21 ( & V_4 -> V_34 ) ) ;
}
if ( V_44 . V_59 ) {
memcpy ( V_22 , V_44 . V_7 . V_60 . V_61 , V_44 . V_59 ) ;
memset ( V_22 + V_44 . V_59 , 0 , V_13 - V_44 . V_59 ) ;
F_3 ( 1 , V_6 , V_22 , & V_4 -> V_8 , NULL ) ;
F_45 ( V_44 . V_11 . V_60 . V_61 , V_44 . V_7 . V_60 . V_61 , V_54 ,
V_44 . V_59 ) ;
V_56 = F_44 ( & V_44 , 0 ) ;
}
if ( V_56 )
return V_56 ;
F_38 ( V_41 , V_4 , V_6 , V_48 , V_41 -> V_49 - V_37 ) ;
F_47 ( V_22 , V_41 -> V_7 ,
V_41 -> V_45 + V_41 -> V_49 - V_37 ,
V_37 , 0 ) ;
if ( F_52 ( V_48 , V_22 , V_37 ) )
return - V_62 ;
return 0 ;
}
static int T_6 F_53 ( void )
{
int V_33 ;
if ( ! ( V_63 & V_64 ) )
return - V_65 ;
if ( V_63 & V_66 )
F_7 = V_67 ;
else
F_7 = V_68 ;
V_33 = F_54 ( & V_69 ) ;
if ( V_33 )
return V_33 ;
if ( V_63 & V_66 ) {
V_33 = F_55 ( & V_70 ) ;
if ( V_33 )
F_56 ( & V_69 ) ;
}
return V_33 ;
}
static void T_7 F_57 ( void )
{
F_56 ( & V_69 ) ;
F_58 ( & V_70 ) ;
}
