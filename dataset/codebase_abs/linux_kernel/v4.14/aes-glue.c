static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
return F_2 ( F_3 ( V_2 ) , V_3 , V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
int V_7 ;
V_7 = F_6 ( V_2 , V_3 , V_4 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_7 ( & V_6 -> V_8 , V_3 , V_4 / 2 ) ;
if ( ! V_7 )
V_7 = F_7 ( & V_6 -> V_9 , & V_3 [ V_4 / 2 ] ,
V_4 / 2 ) ;
if ( ! V_7 )
return 0 ;
F_8 ( V_2 , V_10 ) ;
return - V_11 ;
}
static int F_9 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_10 ( V_13 ) ;
struct V_14 * V_6 = F_5 ( V_2 ) ;
int V_15 , V_16 , V_17 = 6 + V_6 -> V_18 / 4 ;
struct V_19 V_20 ;
unsigned int V_21 ;
V_15 = F_11 ( & V_20 , V_13 , true ) ;
F_12 () ;
for ( V_16 = 1 ; ( V_21 = ( V_20 . V_22 / V_23 ) ) ; V_16 = 0 ) {
F_13 ( V_20 . V_24 . V_25 . V_26 , V_20 . V_27 . V_25 . V_26 ,
( T_1 * ) V_6 -> V_28 , V_17 , V_21 , V_16 ) ;
V_15 = F_14 ( & V_20 , V_20 . V_22 % V_23 ) ;
}
F_15 () ;
return V_15 ;
}
static int F_16 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_10 ( V_13 ) ;
struct V_14 * V_6 = F_5 ( V_2 ) ;
int V_15 , V_16 , V_17 = 6 + V_6 -> V_18 / 4 ;
struct V_19 V_20 ;
unsigned int V_21 ;
V_15 = F_11 ( & V_20 , V_13 , true ) ;
F_12 () ;
for ( V_16 = 1 ; ( V_21 = ( V_20 . V_22 / V_23 ) ) ; V_16 = 0 ) {
F_17 ( V_20 . V_24 . V_25 . V_26 , V_20 . V_27 . V_25 . V_26 ,
( T_1 * ) V_6 -> V_29 , V_17 , V_21 , V_16 ) ;
V_15 = F_14 ( & V_20 , V_20 . V_22 % V_23 ) ;
}
F_15 () ;
return V_15 ;
}
static int F_18 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_10 ( V_13 ) ;
struct V_14 * V_6 = F_5 ( V_2 ) ;
int V_15 , V_16 , V_17 = 6 + V_6 -> V_18 / 4 ;
struct V_19 V_20 ;
unsigned int V_21 ;
V_15 = F_11 ( & V_20 , V_13 , true ) ;
F_12 () ;
for ( V_16 = 1 ; ( V_21 = ( V_20 . V_22 / V_23 ) ) ; V_16 = 0 ) {
F_19 ( V_20 . V_24 . V_25 . V_26 , V_20 . V_27 . V_25 . V_26 ,
( T_1 * ) V_6 -> V_28 , V_17 , V_21 , V_20 . V_30 ,
V_16 ) ;
V_15 = F_14 ( & V_20 , V_20 . V_22 % V_23 ) ;
}
F_15 () ;
return V_15 ;
}
static int F_20 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_10 ( V_13 ) ;
struct V_14 * V_6 = F_5 ( V_2 ) ;
int V_15 , V_16 , V_17 = 6 + V_6 -> V_18 / 4 ;
struct V_19 V_20 ;
unsigned int V_21 ;
V_15 = F_11 ( & V_20 , V_13 , true ) ;
F_12 () ;
for ( V_16 = 1 ; ( V_21 = ( V_20 . V_22 / V_23 ) ) ; V_16 = 0 ) {
F_21 ( V_20 . V_24 . V_25 . V_26 , V_20 . V_27 . V_25 . V_26 ,
( T_1 * ) V_6 -> V_29 , V_17 , V_21 , V_20 . V_30 ,
V_16 ) ;
V_15 = F_14 ( & V_20 , V_20 . V_22 % V_23 ) ;
}
F_15 () ;
return V_15 ;
}
static int F_22 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_10 ( V_13 ) ;
struct V_14 * V_6 = F_5 ( V_2 ) ;
int V_15 , V_16 , V_17 = 6 + V_6 -> V_18 / 4 ;
struct V_19 V_20 ;
int V_21 ;
V_15 = F_11 ( & V_20 , V_13 , true ) ;
V_16 = 1 ;
F_12 () ;
while ( ( V_21 = ( V_20 . V_22 / V_23 ) ) ) {
F_23 ( V_20 . V_24 . V_25 . V_26 , V_20 . V_27 . V_25 . V_26 ,
( T_1 * ) V_6 -> V_28 , V_17 , V_21 , V_20 . V_30 ,
V_16 ) ;
V_15 = F_14 ( & V_20 , V_20 . V_22 % V_23 ) ;
V_16 = 0 ;
}
if ( V_20 . V_22 ) {
T_1 V_31 ( 8 ) V_32 [ V_23 ] ;
unsigned int V_22 = V_20 . V_22 ;
T_1 * V_33 = V_20 . V_24 . V_25 . V_26 ;
T_1 * V_34 = V_20 . V_27 . V_25 . V_26 ;
V_21 = - 1 ;
F_23 ( V_32 , NULL , ( T_1 * ) V_6 -> V_28 , V_17 ,
V_21 , V_20 . V_30 , V_16 ) ;
F_24 ( V_33 , V_34 , V_32 , V_22 ) ;
V_15 = F_14 ( & V_20 , 0 ) ;
}
F_15 () ;
return V_15 ;
}
static int F_25 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_10 ( V_13 ) ;
struct V_14 * V_6 = F_5 ( V_2 ) ;
if ( ! F_26 () )
return F_27 ( V_6 , V_13 ) ;
return F_22 ( V_13 ) ;
}
static int F_28 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_10 ( V_13 ) ;
struct V_5 * V_6 = F_5 ( V_2 ) ;
int V_15 , V_16 , V_17 = 6 + V_6 -> V_8 . V_18 / 4 ;
struct V_19 V_20 ;
unsigned int V_21 ;
V_15 = F_11 ( & V_20 , V_13 , true ) ;
F_12 () ;
for ( V_16 = 1 ; ( V_21 = ( V_20 . V_22 / V_23 ) ) ; V_16 = 0 ) {
F_29 ( V_20 . V_24 . V_25 . V_26 , V_20 . V_27 . V_25 . V_26 ,
( T_1 * ) V_6 -> V_8 . V_28 , V_17 , V_21 ,
( T_1 * ) V_6 -> V_9 . V_28 , V_20 . V_30 , V_16 ) ;
V_15 = F_14 ( & V_20 , V_20 . V_22 % V_23 ) ;
}
F_15 () ;
return V_15 ;
}
static int F_30 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_10 ( V_13 ) ;
struct V_5 * V_6 = F_5 ( V_2 ) ;
int V_15 , V_16 , V_17 = 6 + V_6 -> V_8 . V_18 / 4 ;
struct V_19 V_20 ;
unsigned int V_21 ;
V_15 = F_11 ( & V_20 , V_13 , true ) ;
F_12 () ;
for ( V_16 = 1 ; ( V_21 = ( V_20 . V_22 / V_23 ) ) ; V_16 = 0 ) {
F_31 ( V_20 . V_24 . V_25 . V_26 , V_20 . V_27 . V_25 . V_26 ,
( T_1 * ) V_6 -> V_8 . V_29 , V_17 , V_21 ,
( T_1 * ) V_6 -> V_9 . V_28 , V_20 . V_30 , V_16 ) ;
V_15 = F_14 ( & V_20 , V_20 . V_22 % V_23 ) ;
}
F_15 () ;
return V_15 ;
}
static int F_32 ( struct V_35 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_36 * V_6 = F_33 ( V_2 ) ;
int V_15 ;
V_15 = F_7 ( & V_6 -> V_37 , V_3 , V_4 ) ;
if ( V_15 )
F_34 ( V_2 , V_10 ) ;
return V_15 ;
}
static void F_35 ( T_2 * V_38 , const T_2 * V_39 )
{
T_3 V_40 = F_36 ( V_39 -> V_40 ) ;
T_3 V_41 = F_36 ( V_39 -> V_41 ) ;
V_38 -> V_40 = F_37 ( ( V_40 << 1 ) | ( V_41 >> 63 ) ) ;
V_38 -> V_41 = F_37 ( ( V_41 << 1 ) ^ ( ( V_40 >> 63 ) ? 0x87 : 0 ) ) ;
}
static int F_38 ( struct V_35 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_36 * V_6 = F_33 ( V_2 ) ;
T_2 * V_42 = ( T_2 * ) V_6 -> V_42 ;
T_1 * V_43 = ( T_1 * ) V_6 -> V_37 . V_28 ;
int V_17 = 6 + V_4 / 4 ;
int V_15 ;
V_15 = F_32 ( V_2 , V_3 , V_4 ) ;
if ( V_15 )
return V_15 ;
F_12 () ;
F_13 (ctx->consts, (u8[AES_BLOCK_SIZE]){}, rk, rounds, 1 , 1 ) ;
F_15 () ;
F_35 ( V_42 , V_42 ) ;
F_35 ( V_42 + 1 , V_42 ) ;
return 0 ;
}
static int F_39 ( struct V_35 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
static T_1 const V_44 [ 3 ] [ V_23 ] = {
{ [ 0 ... V_23 - 1 ] = 0x1 } ,
{ [ 0 ... V_23 - 1 ] = 0x2 } ,
{ [ 0 ... V_23 - 1 ] = 0x3 } ,
} ;
struct V_36 * V_6 = F_33 ( V_2 ) ;
T_1 * V_43 = ( T_1 * ) V_6 -> V_37 . V_28 ;
int V_17 = 6 + V_4 / 4 ;
T_1 V_37 [ V_23 ] ;
int V_15 ;
V_15 = F_32 ( V_2 , V_3 , V_4 ) ;
if ( V_15 )
return V_15 ;
F_12 () ;
F_13 ( V_37 , V_44 [ 0 ] , V_43 , V_17 , 1 , 1 ) ;
F_13 ( V_6 -> V_42 , V_44 [ 1 ] , V_43 , V_17 , 2 , 0 ) ;
F_15 () ;
return F_32 ( V_2 , V_37 , sizeof( V_37 ) ) ;
}
static int F_40 ( struct V_45 * V_46 )
{
struct V_47 * V_6 = F_41 ( V_46 ) ;
memset ( V_6 -> V_48 , 0 , V_23 ) ;
V_6 -> V_49 = 0 ;
return 0 ;
}
static void F_42 ( struct V_14 * V_6 , T_1 const V_50 [] , int V_21 ,
T_1 V_48 [] , int V_51 , int V_52 )
{
int V_17 = 6 + V_6 -> V_18 / 4 ;
if ( F_26 () ) {
F_12 () ;
F_43 ( V_50 , V_6 -> V_28 , V_17 , V_21 , V_48 , V_51 ,
V_52 ) ;
F_15 () ;
} else {
if ( V_51 )
F_44 ( V_6 -> V_28 , V_48 , V_48 , V_17 ) ;
while ( V_21 -- ) {
F_45 ( V_48 , V_50 , V_23 ) ;
V_50 += V_23 ;
if ( V_21 || V_52 )
F_44 ( V_6 -> V_28 , V_48 , V_48 ,
V_17 ) ;
}
}
}
static int F_46 ( struct V_45 * V_46 , const T_1 * V_53 , unsigned int V_49 )
{
struct V_36 * V_54 = F_33 ( V_46 -> V_2 ) ;
struct V_47 * V_6 = F_41 ( V_46 ) ;
while ( V_49 > 0 ) {
unsigned int V_55 ;
if ( ( V_6 -> V_49 % V_23 ) == 0 &&
( V_6 -> V_49 + V_49 ) > V_23 ) {
int V_21 = V_49 / V_23 ;
V_49 %= V_23 ;
F_42 ( & V_54 -> V_37 , V_53 , V_21 , V_6 -> V_48 ,
( V_6 -> V_49 != 0 ) , ( V_49 != 0 ) ) ;
V_53 += V_21 * V_23 ;
if ( ! V_49 ) {
V_6 -> V_49 = V_23 ;
break;
}
V_6 -> V_49 = 0 ;
}
V_55 = F_47 ( V_49 , V_23 - V_6 -> V_49 ) ;
if ( V_55 <= V_23 ) {
F_45 ( V_6 -> V_48 + V_6 -> V_49 , V_53 , V_55 ) ;
V_6 -> V_49 += V_55 ;
V_49 -= V_55 ;
V_53 += V_55 ;
}
}
return 0 ;
}
static int F_48 ( struct V_45 * V_46 , T_1 * V_56 )
{
struct V_36 * V_54 = F_33 ( V_46 -> V_2 ) ;
struct V_47 * V_6 = F_41 ( V_46 ) ;
F_42 ( & V_54 -> V_37 , NULL , 0 , V_6 -> V_48 , 1 , 0 ) ;
memcpy ( V_56 , V_6 -> V_48 , V_23 ) ;
return 0 ;
}
static int F_49 ( struct V_45 * V_46 , T_1 * V_56 )
{
struct V_36 * V_54 = F_33 ( V_46 -> V_2 ) ;
struct V_47 * V_6 = F_41 ( V_46 ) ;
T_1 * V_42 = V_54 -> V_42 ;
if ( V_6 -> V_49 != V_23 ) {
V_6 -> V_48 [ V_6 -> V_49 ] ^= 0x80 ;
V_42 += V_23 ;
}
F_42 ( & V_54 -> V_37 , V_42 , 1 , V_6 -> V_48 , 0 , 1 ) ;
memcpy ( V_56 , V_6 -> V_48 , V_23 ) ;
return 0 ;
}
static void F_50 ( void )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < F_51 ( V_58 ) ; V_57 ++ )
if ( V_58 [ V_57 ] )
F_52 ( V_58 [ V_57 ] ) ;
F_53 ( V_59 , F_51 ( V_59 ) ) ;
F_54 ( V_60 , F_51 ( V_60 ) ) ;
}
static int T_4 F_55 ( void )
{
struct V_61 * V_62 ;
const char * V_63 ;
const char * V_64 ;
const char * V_65 ;
int V_15 ;
int V_57 ;
V_15 = F_56 ( V_60 , F_51 ( V_60 ) ) ;
if ( V_15 )
return V_15 ;
V_15 = F_57 ( V_59 , F_51 ( V_59 ) ) ;
if ( V_15 )
goto V_66;
for ( V_57 = 0 ; V_57 < F_51 ( V_60 ) ; V_57 ++ ) {
if ( ! ( V_60 [ V_57 ] . V_67 . V_68 & V_69 ) )
continue;
V_64 = V_60 [ V_57 ] . V_67 . V_70 + 2 ;
V_65 = V_60 [ V_57 ] . V_67 . V_71 + 2 ;
V_63 = V_60 [ V_57 ] . V_67 . V_71 ;
V_62 = F_58 ( V_64 , V_65 , V_63 ) ;
V_15 = F_59 ( V_62 ) ;
if ( F_60 ( V_62 ) )
goto V_72;
V_58 [ V_57 ] = V_62 ;
}
return 0 ;
V_72:
F_50 () ;
V_66:
F_54 ( V_60 , F_51 ( V_60 ) ) ;
return V_15 ;
}
