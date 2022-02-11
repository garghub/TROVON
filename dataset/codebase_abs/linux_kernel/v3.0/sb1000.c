static int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned short V_7 [ 2 ] , V_8 ;
unsigned int V_9 ;
int error = - V_10 ;
if ( F_2 ( V_2 ) < 0 )
return - V_10 ;
if ( F_3 ( V_2 ) < 0 )
goto V_11;
if ( ! F_4 ( V_2 , 0 ) || ! F_4 ( V_2 , 1 ) )
goto V_12;
if ( ! F_5 ( V_2 , 0 ) )
goto V_12;
V_9 = V_2 -> V_13 -> V_14 ;
V_7 [ 0 ] = F_6 ( V_2 , 0 ) ;
V_7 [ 1 ] = F_6 ( V_2 , 0 ) ;
V_8 = F_7 ( V_2 , 0 ) ;
if ( ! F_8 ( V_7 [ 0 ] , 16 , L_1 ) )
goto V_12;
if ( ! F_8 ( V_7 [ 1 ] , 16 , L_1 ) )
goto V_15;
V_6 = F_9 ( sizeof( struct V_16 ) ) ;
if ( ! V_6 ) {
error = - V_17 ;
goto V_18;
}
V_6 -> V_19 = V_7 [ 0 ] ;
V_6 -> V_20 = V_7 [ 1 ] ;
V_6 -> V_8 = V_8 ;
if ( V_21 > 0 )
F_10 ( V_22 L_2
L_3 , V_6 -> V_23 , V_6 -> V_19 ,
V_6 -> V_20 , V_9 , V_6 -> V_8 ) ;
V_6 -> V_24 = V_25 | V_26 ;
F_11 ( V_6 , & V_2 -> V_6 ) ;
if ( V_21 > 0 )
F_10 ( V_22 L_4 , V_27 ) ;
V_6 -> V_28 = & V_29 ;
V_6 -> V_30 [ 2 ] = V_9 >> 24 & 0xff ;
V_6 -> V_30 [ 3 ] = V_9 >> 16 & 0xff ;
V_6 -> V_30 [ 4 ] = V_9 >> 8 & 0xff ;
V_6 -> V_30 [ 5 ] = V_9 >> 0 & 0xff ;
F_12 ( V_2 , V_6 ) ;
error = F_13 ( V_6 ) ;
if ( error )
goto V_31;
return 0 ;
V_31:
F_14 ( V_6 ) ;
V_18:
F_15 ( V_7 [ 1 ] , 16 ) ;
V_15:
F_15 ( V_7 [ 0 ] , 16 ) ;
V_12:
F_16 ( V_2 ) ;
V_11:
F_17 ( V_2 ) ;
return error ;
}
static void
F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_19 ( V_2 ) ;
F_20 ( V_6 ) ;
F_15 ( V_6 -> V_19 , 16 ) ;
F_15 ( V_6 -> V_20 , 16 ) ;
F_14 ( V_6 ) ;
}
static int
F_21 ( const int V_7 [] , const char * V_23 )
{
unsigned char V_32 ;
unsigned long V_33 ;
V_32 = F_22 ( V_7 [ 0 ] + 7 ) ;
V_33 = V_34 + V_35 ;
while ( V_32 & 0x80 || V_32 & 0x40 ) {
F_23 () ;
V_32 = F_22 ( V_7 [ 0 ] + 7 ) ;
if ( F_24 ( V_34 , V_33 ) ) {
F_10 ( V_36 L_5 ,
V_23 ) ;
return - V_37 ;
}
}
return 0 ;
}
static int
F_25 ( const int V_7 [] , const char * V_23 , unsigned char V_38 [] )
{
unsigned char V_32 ;
unsigned long V_33 ;
V_32 = F_22 ( V_7 [ 1 ] + 6 ) ;
V_33 = V_34 + V_35 ;
while ( V_32 & 0x80 || ! ( V_32 & 0x40 ) ) {
F_23 () ;
V_32 = F_22 ( V_7 [ 1 ] + 6 ) ;
if ( F_24 ( V_34 , V_33 ) ) {
F_10 ( V_36 L_6 ,
V_23 ) ;
return - V_37 ;
}
}
V_38 [ 1 ] = F_22 ( V_7 [ 0 ] + 1 ) ;
V_38 [ 2 ] = F_22 ( V_7 [ 0 ] + 2 ) ;
V_38 [ 3 ] = F_22 ( V_7 [ 0 ] + 3 ) ;
V_38 [ 4 ] = F_22 ( V_7 [ 0 ] + 4 ) ;
V_38 [ 0 ] = F_22 ( V_7 [ 0 ] + 5 ) ;
V_38 [ 6 ] = F_22 ( V_7 [ 0 ] + 6 ) ;
V_38 [ 5 ] = F_22 ( V_7 [ 1 ] + 6 ) ;
return 0 ;
}
static int
F_26 ( const int V_7 [] , const char * V_23 ,
const unsigned char V_39 [] , unsigned char V_38 [] )
{
int V_40 , V_41 ;
if ( ( V_40 = F_21 ( V_7 , V_23 ) ) )
return V_40 ;
F_27 ( 0xa0 , V_7 [ 0 ] + 6 ) ;
F_27 ( V_39 [ 2 ] , V_7 [ 0 ] + 1 ) ;
F_27 ( V_39 [ 3 ] , V_7 [ 0 ] + 2 ) ;
F_27 ( V_39 [ 4 ] , V_7 [ 0 ] + 3 ) ;
F_27 ( V_39 [ 5 ] , V_7 [ 0 ] + 4 ) ;
F_27 ( V_39 [ 1 ] , V_7 [ 0 ] + 5 ) ;
F_27 ( 0xa0 , V_7 [ 0 ] + 6 ) ;
F_27 ( V_39 [ 0 ] , V_7 [ 0 ] + 7 ) ;
if ( V_39 [ 0 ] != 0x20 && V_39 [ 0 ] != 0x30 ) {
if ( ( V_40 = F_25 ( V_7 , V_23 , V_38 ) ) )
return V_40 ;
F_22 ( V_7 [ 0 ] + 7 ) ;
if ( V_21 > 3 )
F_10 ( V_42 L_7
L_8
L_9 , V_23 ,
V_39 [ 0 ] , V_39 [ 1 ] , V_39 [ 2 ] , V_39 [ 3 ] , V_39 [ 4 ] , V_39 [ 5 ] ,
V_38 [ 0 ] , V_38 [ 1 ] , V_38 [ 2 ] , V_38 [ 3 ] , V_38 [ 4 ] , V_38 [ 5 ] , V_38 [ 6 ] ) ;
} else {
if ( V_21 > 3 )
F_10 ( V_42 L_7
L_10 , V_23 ,
V_39 [ 0 ] , V_39 [ 1 ] , V_39 [ 2 ] , V_39 [ 3 ] , V_39 [ 4 ] , V_39 [ 5 ] ) ;
}
if ( V_39 [ 1 ] == 0x1b ) {
V_41 = ( V_39 [ 2 ] == 0x02 ) ;
} else {
if ( V_39 [ 0 ] >= 0x80 && V_38 [ 0 ] != ( V_39 [ 1 ] | 0x80 ) )
return - V_43 ;
}
return 0 ;
}
static int
F_28 ( const int V_7 [] , const char * V_23 )
{
unsigned long V_33 ;
V_33 = V_34 + V_44 ;
while ( F_22 ( V_7 [ 1 ] + 6 ) & 0x80 ) {
if ( F_24 ( V_34 , V_33 ) ) {
F_10 ( V_36 L_11 ,
V_23 ) ;
return - V_37 ;
}
}
V_33 = V_34 + V_44 ;
while ( ! ( F_22 ( V_7 [ 1 ] + 6 ) & 0x40 ) ) {
if ( F_24 ( V_34 , V_33 ) ) {
F_10 ( V_36 L_11 ,
V_23 ) ;
return - V_37 ;
}
}
F_22 ( V_7 [ 0 ] + 7 ) ;
return 0 ;
}
static int
F_29 ( const int V_7 [] , const char * V_23 )
{
unsigned long V_33 ;
V_33 = V_34 + V_44 ;
while ( F_22 ( V_7 [ 1 ] + 6 ) & 0x80 ) {
if ( F_24 ( V_34 , V_33 ) ) {
F_10 ( V_36 L_12 ,
V_23 ) ;
return - V_37 ;
}
}
V_33 = V_34 + V_44 ;
while ( F_22 ( V_7 [ 1 ] + 6 ) & 0x40 ) {
if ( F_24 ( V_34 , V_33 ) ) {
F_10 ( V_36 L_12 ,
V_23 ) ;
return - V_37 ;
}
}
return 0 ;
}
static void
F_30 ( const int V_7 [] , const char * V_23 ,
const unsigned char V_39 [] )
{
F_27 ( V_39 [ 2 ] , V_7 [ 0 ] + 1 ) ;
F_27 ( V_39 [ 3 ] , V_7 [ 0 ] + 2 ) ;
F_27 ( V_39 [ 4 ] , V_7 [ 0 ] + 3 ) ;
F_27 ( V_39 [ 5 ] , V_7 [ 0 ] + 4 ) ;
F_27 ( V_39 [ 1 ] , V_7 [ 0 ] + 5 ) ;
F_27 ( V_39 [ 0 ] , V_7 [ 0 ] + 7 ) ;
if ( V_21 > 3 )
F_10 ( V_42 L_13
L_14 , V_23 , V_39 [ 0 ] , V_39 [ 1 ] , V_39 [ 2 ] , V_39 [ 3 ] , V_39 [ 4 ] , V_39 [ 5 ] ) ;
}
static void
F_31 ( const int V_7 [] , unsigned char V_38 [] )
{
V_38 [ 1 ] = F_22 ( V_7 [ 0 ] + 1 ) ;
V_38 [ 2 ] = F_22 ( V_7 [ 0 ] + 2 ) ;
V_38 [ 3 ] = F_22 ( V_7 [ 0 ] + 3 ) ;
V_38 [ 4 ] = F_22 ( V_7 [ 0 ] + 4 ) ;
V_38 [ 0 ] = F_22 ( V_7 [ 0 ] + 5 ) ;
}
static void
F_32 ( const int V_7 [] , const char * V_23 )
{
static const unsigned char V_45 [ 6 ] = { 0x20 , 0x00 , 0x00 , 0x01 , 0x00 , 0x00 } ;
F_29 ( V_7 , V_23 ) ;
F_27 ( 0xa0 , V_7 [ 0 ] + 6 ) ;
F_30 ( V_7 , V_23 , V_45 ) ;
}
static int
F_33 ( const int V_7 [] , const char * V_23 )
{
static const unsigned char V_45 [ 6 ] = { 0x80 , 0x16 , 0x00 , 0x00 , 0x00 , 0x00 } ;
unsigned char V_46 [ 7 ] ;
int V_47 , V_40 ;
V_47 = V_7 [ 1 ] + 6 ;
F_27 ( 0x4 , V_47 ) ;
F_22 ( V_47 ) ;
F_34 ( 1000 ) ;
F_27 ( 0x0 , V_47 ) ;
F_22 ( V_47 ) ;
F_35 ( 1 ) ;
F_27 ( 0x4 , V_47 ) ;
F_22 ( V_47 ) ;
F_34 ( 1000 ) ;
F_27 ( 0x0 , V_47 ) ;
F_22 ( V_47 ) ;
F_34 ( 0 ) ;
if ( ( V_40 = F_26 ( V_7 , V_23 , V_45 , V_46 ) ) )
return V_40 ;
if ( V_46 [ 3 ] != 0xf0 )
return - V_43 ;
return 0 ;
}
static int
F_36 ( const int V_7 [] , const char * V_23 )
{
static const unsigned char V_45 [ 6 ] = { 0x80 , 0x1f , 0x00 , 0x00 , 0x00 , 0x00 } ;
unsigned char V_46 [ 7 ] ;
int V_48 , V_40 ;
if ( ( V_40 = F_26 ( V_7 , V_23 , V_45 , V_46 ) ) )
return V_40 ;
if ( V_46 [ 1 ] != V_46 [ 3 ] || V_46 [ 2 ] != V_46 [ 4 ] )
return - V_43 ;
V_48 = V_46 [ 1 ] << 8 | V_46 [ 2 ] ;
return 0 ;
}
static inline int
F_37 ( const int V_7 [] , const char * V_23 )
{
static const unsigned char V_45 [ 6 ] = { 0x80 , 0x1b , 0x00 , 0x00 , 0x00 , 0x00 } ;
unsigned char V_46 [ 7 ] ;
return F_26 ( V_7 , V_23 , V_45 , V_46 ) ;
}
static int
F_38 ( const int V_7 [] , const char * V_23 )
{
static const unsigned char V_45 [ 6 ] = { 0x80 , 0x1b , 0x02 , 0x00 , 0x00 , 0x00 } ;
static const unsigned char V_49 [ 6 ] = { 0x20 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
unsigned char V_46 [ 7 ] ;
int V_40 ;
if ( ( V_40 = F_26 ( V_7 , V_23 , V_45 , V_46 ) ) )
return V_40 ;
return F_26 ( V_7 , V_23 , V_49 , V_46 ) ;
}
static int
F_39 ( const int V_7 [] , const char * V_23 )
{
static const unsigned char V_45 [ 6 ] = { 0x80 , 0x11 , 0x00 , 0x00 , 0x00 , 0x00 } ;
static const unsigned char V_49 [ 6 ] = { 0x80 , 0x16 , 0x00 , 0x00 , 0x00 , 0x00 } ;
unsigned char V_46 [ 7 ] ;
int V_40 ;
F_35 ( 1 ) ;
if ( ( V_40 = F_26 ( V_7 , V_23 , V_45 , V_46 ) ) )
return V_40 ;
if ( ( V_40 = F_26 ( V_7 , V_23 , V_49 , V_46 ) ) )
return V_40 ;
if ( V_46 [ 3 ] != 0xf1 ) {
if ( ( V_40 = F_37 ( V_7 , V_23 ) ) )
return V_40 ;
return - V_43 ;
}
F_34 ( 1000 ) ;
return F_37 ( V_7 , V_23 ) ;
}
static int
F_40 ( const int V_7 [] , const char * V_23 ,
unsigned char V_27 [] , int V_50 )
{
static const unsigned char V_45 [ 6 ] = { 0x80 , 0x23 , 0x00 , 0x00 , 0x00 , 0x00 } ;
unsigned char V_46 [ 7 ] ;
int V_40 ;
if ( ( V_40 = F_37 ( V_7 , V_23 ) ) )
return V_40 ;
if ( ( V_40 = F_26 ( V_7 , V_23 , V_45 , V_46 ) ) )
return V_40 ;
if ( V_46 [ 0 ] != 0xa3 )
return - V_43 ;
V_27 [ 0 ] = V_46 [ 1 ] ;
V_27 [ 1 ] = V_46 [ 2 ] ;
if ( V_50 )
return F_38 ( V_7 , V_23 ) ;
else
return 0 ;
}
static int
F_41 ( const int V_7 [] , const char * V_23 , int * V_51 )
{
static const unsigned char V_45 [ 6 ] = { 0x80 , 0x44 , 0x00 , 0x00 , 0x00 , 0x00 } ;
unsigned char V_46 [ 7 ] ;
int V_40 ;
F_34 ( 1000 ) ;
if ( ( V_40 = F_37 ( V_7 , V_23 ) ) )
return V_40 ;
if ( ( V_40 = F_26 ( V_7 , V_23 , V_45 , V_46 ) ) )
return V_40 ;
* V_51 = ( ( V_46 [ 1 ] << 8 | V_46 [ 2 ] ) << 8 | V_46 [ 3 ] ) << 8 | V_46 [ 4 ] ;
return F_38 ( V_7 , V_23 ) ;
}
static int
F_42 ( const int V_7 [] , const char * V_23 , int V_51 )
{
unsigned char V_46 [ 7 ] ;
int V_40 ;
unsigned char V_45 [ 6 ] = { 0x80 , 0x29 , 0x00 , 0x00 , 0x00 , 0x00 } ;
const int V_52 = 57000 ;
const int V_53 = 804000 ;
if ( V_51 < V_52 || V_51 > V_53 ) {
F_10 ( V_54 L_15
L_16 , V_23 , V_51 , V_52 ,
V_53 ) ;
return - V_55 ;
}
F_34 ( 1000 ) ;
if ( ( V_40 = F_37 ( V_7 , V_23 ) ) )
return V_40 ;
V_45 [ 5 ] = V_51 & 0xff ;
V_51 >>= 8 ;
V_45 [ 4 ] = V_51 & 0xff ;
V_51 >>= 8 ;
V_45 [ 3 ] = V_51 & 0xff ;
V_51 >>= 8 ;
V_45 [ 2 ] = V_51 & 0xff ;
return F_26 ( V_7 , V_23 , V_45 , V_46 ) ;
}
static int
F_43 ( const int V_7 [] , const char * V_23 , short V_56 [] )
{
static const unsigned char V_45 [ 6 ] = { 0x80 , 0x40 , 0x00 , 0x00 , 0x00 , 0x00 } ;
static const unsigned char V_49 [ 6 ] = { 0x80 , 0x41 , 0x00 , 0x00 , 0x00 , 0x00 } ;
static const unsigned char V_57 [ 6 ] = { 0x80 , 0x42 , 0x00 , 0x00 , 0x00 , 0x00 } ;
static const unsigned char V_58 [ 6 ] = { 0x80 , 0x43 , 0x00 , 0x00 , 0x00 , 0x00 } ;
unsigned char V_46 [ 7 ] ;
int V_40 ;
F_34 ( 1000 ) ;
if ( ( V_40 = F_37 ( V_7 , V_23 ) ) )
return V_40 ;
if ( ( V_40 = F_26 ( V_7 , V_23 , V_45 , V_46 ) ) )
return V_40 ;
V_56 [ 0 ] = V_46 [ 1 ] << 8 | V_46 [ 2 ] ;
if ( ( V_40 = F_26 ( V_7 , V_23 , V_49 , V_46 ) ) )
return V_40 ;
V_56 [ 1 ] = V_46 [ 1 ] << 8 | V_46 [ 2 ] ;
if ( ( V_40 = F_26 ( V_7 , V_23 , V_57 , V_46 ) ) )
return V_40 ;
V_56 [ 2 ] = V_46 [ 1 ] << 8 | V_46 [ 2 ] ;
if ( ( V_40 = F_26 ( V_7 , V_23 , V_58 , V_46 ) ) )
return V_40 ;
V_56 [ 3 ] = V_46 [ 1 ] << 8 | V_46 [ 2 ] ;
return F_38 ( V_7 , V_23 ) ;
}
static int
F_44 ( const int V_7 [] , const char * V_23 , const short V_56 [] )
{
static const unsigned char V_59 [ 6 ] = { 0x80 , 0x2e , 0x00 , 0x00 , 0x00 , 0x00 } ;
unsigned char V_46 [ 7 ] ;
short V_60 ;
int V_40 ;
unsigned char V_45 [ 6 ] = { 0x80 , 0x31 , 0x00 , 0x00 , 0x00 , 0x00 } ;
unsigned char V_49 [ 6 ] = { 0x80 , 0x32 , 0x00 , 0x00 , 0x00 , 0x00 } ;
unsigned char V_57 [ 6 ] = { 0x80 , 0x33 , 0x00 , 0x00 , 0x00 , 0x00 } ;
unsigned char V_58 [ 6 ] = { 0x80 , 0x34 , 0x00 , 0x00 , 0x00 , 0x00 } ;
F_34 ( 1000 ) ;
if ( ( V_40 = F_37 ( V_7 , V_23 ) ) )
return V_40 ;
V_60 = V_56 [ 0 ] ;
V_45 [ 3 ] = V_60 & 0xff ;
V_60 >>= 8 ;
V_45 [ 2 ] = V_60 & 0xff ;
if ( ( V_40 = F_26 ( V_7 , V_23 , V_45 , V_46 ) ) )
return V_40 ;
V_60 = V_56 [ 1 ] ;
V_49 [ 3 ] = V_60 & 0xff ;
V_60 >>= 8 ;
V_49 [ 2 ] = V_60 & 0xff ;
if ( ( V_40 = F_26 ( V_7 , V_23 , V_49 , V_46 ) ) )
return V_40 ;
V_60 = V_56 [ 2 ] ;
V_57 [ 3 ] = V_60 & 0xff ;
V_60 >>= 8 ;
V_57 [ 2 ] = V_60 & 0xff ;
if ( ( V_40 = F_26 ( V_7 , V_23 , V_57 , V_46 ) ) )
return V_40 ;
V_60 = V_56 [ 3 ] ;
V_58 [ 3 ] = V_60 & 0xff ;
V_60 >>= 8 ;
V_58 [ 2 ] = V_60 & 0xff ;
if ( ( V_40 = F_26 ( V_7 , V_23 , V_58 , V_46 ) ) )
return V_40 ;
if ( ( V_40 = F_26 ( V_7 , V_23 , V_59 , V_46 ) ) )
return V_40 ;
return F_38 ( V_7 , V_23 ) ;
}
static void
F_45 ( const char * V_23 , unsigned char V_46 [] ,
unsigned char V_61 [] , int V_62 )
{
int V_63 , V_64 , V_65 ;
F_10 ( V_42 L_17 , V_23 , V_46 [ 0 ] , V_46 [ 1 ] ) ;
if ( V_61 [ 24 ] == 0x08 && V_61 [ 25 ] == 0x00 && V_61 [ 26 ] == 0x45 ) {
F_10 ( V_42 L_18
L_19 , V_23 , V_61 [ 28 ] << 8 | V_61 [ 29 ] ,
V_61 [ 35 ] , V_61 [ 38 ] , V_61 [ 39 ] , V_61 [ 40 ] , V_61 [ 41 ] ,
V_61 [ 46 ] << 8 | V_61 [ 47 ] ,
V_61 [ 42 ] , V_61 [ 43 ] , V_61 [ 44 ] , V_61 [ 45 ] ,
V_61 [ 48 ] << 8 | V_61 [ 49 ] ) ;
} else {
for ( V_63 = 0 , V_65 = 0 ; V_63 < ( V_62 + 7 ) / 8 ; V_63 ++ ) {
F_10 ( V_42 L_20 , V_23 , V_63 ? L_21 : L_22 ) ;
for ( V_64 = 0 ; V_64 < 8 && V_65 < V_62 ; V_64 ++ , V_65 ++ )
F_10 ( L_23 , V_61 [ V_65 ] ) ;
F_10 ( L_24 ) ;
}
}
}
static int
F_46 ( struct V_5 * V_6 )
{
#define F_47 184
unsigned char V_46 [ 2 ] , V_61 [ F_47 ] , V_66 , V_67 ;
short V_68 ;
int V_7 , V_69 ;
unsigned int V_70 ;
struct V_71 * V_72 ;
struct V_16 * V_73 = F_48 ( V_6 ) ;
struct V_74 * V_75 = & V_6 -> V_75 ;
const int V_76 = F_47 ;
const int V_77 = 8 ;
const int V_78 = V_77 + 18 ;
const int V_79 = V_76 - V_78 ;
const int V_80 = 7 ;
const int V_81 = V_80 + 1 ;
const int V_82 = V_76 - V_81 ;
const int V_83 = 4 ;
V_7 = V_6 -> V_19 ;
F_49 ( V_7 , ( unsigned short * ) V_46 , 1 ) ;
#ifdef F_50
F_10 ( L_25 , V_46 [ 0 ] , V_46 [ 1 ] ) ;
#endif
V_73 -> V_84 ++ ;
for ( V_69 = 0 ; V_69 < V_85 ; V_69 ++ ) {
V_66 = V_73 -> V_86 [ V_69 ] ;
V_67 = V_73 -> V_87 [ V_69 ] ;
if ( V_46 [ 0 ] == V_66 ) {
if ( V_46 [ 1 ] == V_67 || ( ! V_67 && ( V_46 [ 1 ] & 0xf0 ) == 0x30 ) ) {
goto V_88;
} else if ( ( V_46 [ 1 ] & 0xf0 ) == 0x30 && ( V_46 [ 0 ] & 0x40 ) ) {
goto V_89;
} else {
goto V_90;
}
} else if ( V_46 [ 0 ] == ( V_66 | 0x40 ) ) {
if ( ( V_46 [ 1 ] & 0xf0 ) == 0x30 ) {
goto V_89;
} else {
goto V_90;
}
}
}
goto V_90;
V_89:
V_75 -> V_91 ++ ;
V_72 = V_73 -> V_92 [ V_69 ] ;
if ( V_21 > 1 )
F_10 ( V_36 L_26
L_27 , V_6 -> V_23 , V_46 [ 0 ] , V_46 [ 1 ] ,
V_72 ? V_66 : V_66 | 0x40 , V_67 ) ;
if ( V_72 ) {
F_51 ( V_72 ) ;
V_72 = NULL ;
}
V_88:
V_73 -> V_87 [ V_69 ] = 0x30 | ( ( V_46 [ 1 ] + 1 ) & 0x0f ) ;
if ( V_46 [ 0 ] & 0x40 ) {
F_49 ( V_7 , V_61 , V_78 / 2 ) ;
#ifdef F_50
F_10 ( L_28 , V_61 [ 30 ] , V_61 [ 31 ] , V_61 [ 32 ] , V_61 [ 33 ] ) ;
#endif
if ( V_61 [ 0 ] != V_77 ) {
if ( V_21 > 1 )
F_10 ( V_36 L_29
L_30 , V_6 -> V_23 , V_61 [ 0 ] ,
V_77 ) ;
V_75 -> V_93 ++ ;
F_49 ( V_7 , V_61 , V_79 / 2 ) ;
goto V_94;
}
V_68 = ( ( V_61 [ V_77 + 3 ] & 0x0f ) << 8 |
V_61 [ V_77 + 4 ] ) - 17 ;
if ( V_68 > V_95 ) {
if ( V_21 > 1 )
F_10 ( V_36 L_31
L_32 , V_6 -> V_23 , V_68 , V_95 ) ;
V_75 -> V_93 ++ ;
F_49 ( V_7 , V_61 , V_79 / 2 ) ;
goto V_94;
}
V_73 -> V_96 [ V_69 ] = V_68 ;
V_70 = V_68 + V_76 ;
if ( ( V_72 = F_52 ( V_70 , V_97 ) ) == NULL ) {
if ( V_21 > 1 )
F_10 ( V_36 L_33
L_34 , V_6 -> V_23 , V_70 ) ;
V_75 -> V_98 ++ ;
F_49 ( V_7 , V_61 , V_79 / 2 ) ;
goto V_99;
}
V_72 -> V_6 = V_6 ;
F_53 ( V_72 ) ;
V_72 -> V_100 = ( unsigned short ) V_61 [ V_77 + 16 ] ;
F_49 ( V_7 , F_54 ( V_72 , V_79 ) ,
V_79 / 2 ) ;
V_73 -> V_92 [ V_69 ] = V_72 ;
} else {
F_49 ( V_7 , V_61 , V_81 / 2 ) ;
if ( V_61 [ 0 ] != V_80 ) {
if ( V_21 > 1 )
F_10 ( V_36 L_35
L_30 , V_6 -> V_23 , V_61 [ 0 ] ,
V_80 ) ;
V_75 -> V_93 ++ ;
F_49 ( V_7 , V_61 , V_82 / 2 ) ;
goto V_94;
}
V_72 = V_73 -> V_92 [ V_69 ] ;
F_49 ( V_7 , F_54 ( V_72 , V_82 ) ,
V_82 / 2 ) ;
V_68 = V_73 -> V_96 [ V_69 ] ;
}
if ( V_72 -> V_101 < V_68 + V_83 ) {
V_73 -> V_86 [ V_69 ] &= ~ 0x40 ;
return 0 ;
}
F_55 ( V_72 , V_68 ) ;
F_56 ( V_72 ) ;
V_75 -> V_102 += V_68 ;
V_75 -> V_103 ++ ;
V_73 -> V_92 [ V_69 ] = NULL ;
V_73 -> V_86 [ V_69 ] |= 0x40 ;
return 0 ;
V_90:
F_49 ( V_7 , V_61 , V_76 / 2 ) ;
if ( V_21 > 1 )
F_10 ( V_36 L_36 ,
V_6 -> V_23 , V_46 [ 0 ] , V_46 [ 1 ] ) ;
V_75 -> V_91 ++ ;
V_94:
if ( V_21 > 2 )
F_45 ( V_6 -> V_23 , V_46 , V_61 , V_76 ) ;
V_99:
V_75 -> V_104 ++ ;
if ( V_69 < V_85 ) {
if ( ( V_72 = V_73 -> V_92 [ V_69 ] ) ) {
F_51 ( V_72 ) ;
V_73 -> V_92 [ V_69 ] = NULL ;
}
V_73 -> V_86 [ V_69 ] |= 0x40 ;
}
return - 1 ;
}
static void
F_57 ( struct V_5 * V_6 )
{
static const unsigned char V_45 [ 6 ] = { 0x80 , 0x26 , 0x00 , 0x00 , 0x00 , 0x00 } ;
char * V_23 ;
unsigned char V_46 [ 5 ] ;
int V_7 [ 2 ] ;
struct V_16 * V_73 = F_48 ( V_6 ) ;
const int V_105 = 200 ;
V_7 [ 0 ] = V_6 -> V_19 ;
V_7 [ 1 ] = V_6 -> V_20 ;
V_23 = V_6 -> V_23 ;
F_29 ( V_7 , V_23 ) ;
F_30 ( V_7 , V_23 , V_45 ) ;
F_28 ( V_7 , V_23 ) ;
F_31 ( V_7 , V_46 ) ;
if ( V_46 [ 1 ] & 0x10 )
V_73 -> V_106 = V_105 ;
}
static int
F_58 ( struct V_5 * V_6 )
{
char * V_23 ;
int V_7 [ 2 ] , V_40 ;
struct V_16 * V_73 = F_48 ( V_6 ) ;
const unsigned short V_107 [] = { 0x01 , 0x01 } ;
V_7 [ 0 ] = V_6 -> V_19 ;
V_7 [ 1 ] = V_6 -> V_20 ;
V_23 = V_6 -> V_23 ;
if ( ( V_40 = F_33 ( V_7 , V_23 ) ) )
return V_40 ;
F_35 ( 1 ) ;
if ( ( V_40 = F_36 ( V_7 , V_23 ) ) )
return V_40 ;
V_73 -> V_92 [ 0 ] = NULL ;
V_73 -> V_92 [ 1 ] = NULL ;
V_73 -> V_92 [ 2 ] = NULL ;
V_73 -> V_92 [ 3 ] = NULL ;
V_73 -> V_96 [ 0 ] = 0 ;
V_73 -> V_96 [ 1 ] = 0 ;
V_73 -> V_96 [ 2 ] = 0 ;
V_73 -> V_96 [ 3 ] = 0 ;
V_73 -> V_84 = 0 ;
V_73 -> V_108 = 0 ;
V_73 -> V_106 = 0 ;
V_73 -> V_86 [ 0 ] = 0x50 ;
V_73 -> V_86 [ 1 ] = 0x48 ;
V_73 -> V_86 [ 2 ] = 0x44 ;
V_73 -> V_86 [ 3 ] = 0x42 ;
V_73 -> V_87 [ 0 ] = 0 ;
V_73 -> V_87 [ 1 ] = 0 ;
V_73 -> V_87 [ 2 ] = 0 ;
V_73 -> V_87 [ 3 ] = 0 ;
if ( F_59 ( V_6 -> V_8 , V_109 , 0 , L_1 , V_6 ) ) {
return - V_110 ;
}
if ( V_21 > 2 )
F_10 ( V_42 L_37 , V_23 , V_6 -> V_8 ) ;
F_34 ( 1000 ) ;
if ( ( V_40 = F_39 ( V_7 , V_23 ) ) )
return V_40 ;
F_34 ( 0 ) ;
if ( ( V_40 = F_40 ( V_7 , V_23 , V_27 , 0 ) ) )
return V_40 ;
if ( V_27 [ 0 ] != V_107 [ 0 ] || V_27 [ 1 ] != V_107 [ 1 ] )
F_10 ( V_36 L_38
L_39 , V_23 , V_27 [ 0 ] , V_27 [ 1 ] ,
V_107 [ 0 ] , V_107 [ 1 ] ) ;
F_60 ( V_6 ) ;
return 0 ;
}
static int F_61 ( struct V_5 * V_6 , struct V_111 * V_112 , int V_113 )
{
char * V_23 ;
unsigned char V_27 [ 2 ] ;
short V_56 [ 4 ] ;
int V_7 [ 2 ] , V_40 , V_51 ;
unsigned int V_75 [ 5 ] ;
struct V_16 * V_73 = F_48 ( V_6 ) ;
if ( ! ( V_6 && V_6 -> V_24 & V_114 ) )
return - V_10 ;
V_7 [ 0 ] = V_6 -> V_19 ;
V_7 [ 1 ] = V_6 -> V_20 ;
V_23 = V_6 -> V_23 ;
switch ( V_113 ) {
case V_115 :
V_75 [ 0 ] = V_6 -> V_75 . V_102 ;
V_75 [ 1 ] = V_73 -> V_84 ;
V_75 [ 2 ] = V_6 -> V_75 . V_103 ;
V_75 [ 3 ] = V_6 -> V_75 . V_104 ;
V_75 [ 4 ] = V_6 -> V_75 . V_98 ;
if( F_62 ( V_112 -> V_116 , V_75 , sizeof( V_75 ) ) )
return - V_117 ;
V_40 = 0 ;
break;
case V_118 :
if ( ( V_40 = F_40 ( V_7 , V_23 , V_27 , 1 ) ) )
return V_40 ;
if( F_62 ( V_112 -> V_116 , V_27 , sizeof( V_27 ) ) )
return - V_117 ;
break;
case V_119 :
if ( ( V_40 = F_41 ( V_7 , V_23 , & V_51 ) ) )
return V_40 ;
if( F_63 ( V_51 , ( int V_120 * ) V_112 -> V_116 ) )
return - V_117 ;
break;
case V_121 :
if ( ! F_64 ( V_122 ) )
return - V_123 ;
if( F_65 ( V_51 , ( int V_120 * ) V_112 -> V_116 ) )
return - V_117 ;
if ( ( V_40 = F_42 ( V_7 , V_23 , V_51 ) ) )
return V_40 ;
break;
case V_124 :
if ( ( V_40 = F_43 ( V_7 , V_23 , V_56 ) ) )
return V_40 ;
if( F_62 ( V_112 -> V_116 , V_56 , sizeof( V_56 ) ) )
return - V_117 ;
break;
case V_125 :
if ( ! F_64 ( V_122 ) )
return - V_123 ;
if( F_66 ( V_56 , V_112 -> V_116 , sizeof( V_56 ) ) )
return - V_117 ;
if ( ( V_40 = F_44 ( V_7 , V_23 , V_56 ) ) )
return V_40 ;
V_73 -> V_86 [ 0 ] = 0x50 | ( V_56 [ 0 ] & 0x0f ) ;
V_73 -> V_86 [ 1 ] = 0x48 ;
V_73 -> V_86 [ 2 ] = 0x44 ;
V_73 -> V_86 [ 3 ] = 0x42 ;
V_73 -> V_87 [ 0 ] = 0 ;
V_73 -> V_87 [ 1 ] = 0 ;
V_73 -> V_87 [ 2 ] = 0 ;
V_73 -> V_87 [ 3 ] = 0 ;
break;
default:
V_40 = - V_55 ;
break;
}
return V_40 ;
}
static T_1
F_67 ( struct V_71 * V_72 , struct V_5 * V_6 )
{
F_10 ( V_36 L_40 , V_6 -> V_23 ) ;
F_51 ( V_72 ) ;
return V_126 ;
}
static T_2 V_109 ( int V_8 , void * V_127 )
{
static const unsigned char V_45 [ 6 ] = { 0x80 , 0x2c , 0x00 , 0x00 , 0x00 , 0x00 } ;
static const unsigned char V_49 [ 6 ] = { 0x80 , 0x2e , 0x00 , 0x00 , 0x00 , 0x00 } ;
char * V_23 ;
unsigned char V_46 ;
int V_7 [ 2 ] ;
struct V_5 * V_6 = V_127 ;
struct V_16 * V_73 = F_48 ( V_6 ) ;
const int V_128 = 6 ;
V_7 [ 0 ] = V_6 -> V_19 ;
V_7 [ 1 ] = V_6 -> V_20 ;
V_23 = V_6 -> V_23 ;
V_46 = F_22 ( V_7 [ 1 ] + 6 ) ;
if ( ! ( V_46 & 0x08 && V_46 & 0x20 ) ) {
return V_129 ;
}
if ( V_21 > 3 )
F_10 ( V_42 L_41 , V_6 -> V_23 ) ;
V_46 = F_22 ( V_7 [ 0 ] + 7 ) ;
if ( F_46 ( V_6 ) )
V_73 -> V_108 ++ ;
#ifdef F_68
F_34 ( F_68 ) ;
#endif
F_32 ( V_7 , V_23 ) ;
if ( V_46 & 0x01 ) {
F_57 ( V_6 ) ;
F_32 ( V_7 , V_23 ) ;
}
if ( V_73 -> V_106 && ! ( -- V_73 -> V_106 ) ) {
F_29 ( V_7 , V_23 ) ;
F_30 ( V_7 , V_23 , V_45 ) ;
F_28 ( V_7 , V_23 ) ;
F_32 ( V_7 , V_23 ) ;
}
if ( V_73 -> V_108 >= V_128 ) {
F_29 ( V_7 , V_23 ) ;
F_30 ( V_7 , V_23 , V_49 ) ;
F_28 ( V_7 , V_23 ) ;
F_32 ( V_7 , V_23 ) ;
V_73 -> V_108 = 0 ;
}
return V_130 ;
}
static int F_69 ( struct V_5 * V_6 )
{
int V_63 ;
int V_7 [ 2 ] ;
struct V_16 * V_73 = F_48 ( V_6 ) ;
if ( V_21 > 2 )
F_10 ( V_42 L_42 , V_6 -> V_23 ) ;
F_70 ( V_6 ) ;
V_7 [ 0 ] = V_6 -> V_19 ;
V_7 [ 1 ] = V_6 -> V_20 ;
F_71 ( V_6 -> V_8 , V_6 ) ;
F_15 ( V_7 [ 1 ] , V_131 ) ;
F_15 ( V_7 [ 0 ] , V_131 ) ;
for ( V_63 = 0 ; V_63 < 4 ; V_63 ++ ) {
if ( V_73 -> V_92 [ V_63 ] ) {
F_51 ( V_73 -> V_92 [ V_63 ] ) ;
}
}
return 0 ;
}
static int T_3
F_72 ( void )
{
return F_73 ( & V_132 ) ;
}
static void T_4
F_74 ( void )
{
F_75 ( & V_132 ) ;
}
