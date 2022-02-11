static inline T_1 F_1 ( const unsigned char * V_1 )
{
return ( V_1 [ 1 ] << 8 ) | V_1 [ 0 ] ;
}
static inline T_2 F_2 ( const unsigned char * V_1 )
{
return ( V_1 [ 3 ] << 24 ) | ( V_1 [ 2 ] << 16 ) | ( V_1 [ 1 ] << 8 ) | V_1 [ 0 ] ;
}
static inline T_2 F_3 ( const unsigned char * V_1 )
{
return ( V_1 [ 2 ] << 24 ) | ( V_1 [ 1 ] << 16 ) | ( V_1 [ 0 ] << 8 ) ;
}
static void F_4 ( char * V_2 , T_2 V_3 )
{
char V_4 [ 4 ] ;
int V_5 ;
int V_6 ;
V_5 = V_3 & 0xff ;
V_3 >>= 8 ;
V_6 = V_3 & 0xff ;
V_3 >>= 8 ;
V_4 [ 3 ] = '\0' ;
V_4 [ 2 ] = '@' + ( V_3 & 0x1f ) ;
V_3 >>= 5 ;
V_4 [ 1 ] = '@' + ( V_3 & 0x1f ) ;
V_3 >>= 5 ;
V_4 [ 0 ] = '@' + ( V_3 & 0x1f ) ;
V_3 >>= 5 ;
sprintf ( V_2 , L_1 , V_4 , V_6 , V_5 ) ;
}
static int F_5 ( const unsigned char * V_7 ,
struct V_8 * V_9 ,
char * V_10 )
{
int V_11 ;
T_3 V_12 ;
int V_13 ;
struct V_8 * V_14 ;
V_11 = 0 ;
for ( V_13 = 0 ; V_13 < V_15 ; V_13 ++ ) {
V_12 = F_6 ( V_7 + V_11 ) ;
if ( NULL != ( V_14 = F_7 ( sizeof( struct V_8 ) , V_16 ) ) ) {
int V_17 ;
V_14 -> V_10 = V_10 ;
V_14 -> V_18 = V_9 -> V_18 + F_3 ( V_7 + V_11 + 2 ) ;
V_14 -> V_19 = V_14 -> V_18 + F_1 ( V_7 + V_11 + 5 ) * 1024 ;
V_14 -> V_20 = V_21 ;
F_8 ( L_2 , ( unsigned long ) V_14 -> V_18 , ( unsigned long ) V_14 -> V_19 ) ;
V_17 = F_9 ( V_9 , V_14 ) ;
if ( V_17 < 0 ) {
F_8 ( V_22 L_3 ) ;
return V_17 ;
}
}
V_11 += 7 ;
if ( ! ( V_12 & V_23 ) ) {
break;
}
}
return V_11 ;
}
static int F_10 ( const unsigned char * V_7 )
{
int V_11 ;
T_3 V_12 ;
int V_13 ;
V_11 = 0 ;
for ( V_13 = 0 ; V_13 < V_24 ; V_13 ++ ) {
V_12 = F_6 ( V_7 + V_11 ) ;
F_8 ( L_4 , V_12 & V_25 ) ;
if ( V_12 & V_26 ) {
F_11 ( V_12 & V_25 ) ;
} else {
F_12 ( V_12 & V_25 ) ;
}
V_11 += 2 ;
if ( ! ( V_12 & V_27 ) ) {
break;
}
}
return V_11 ;
}
static int F_13 ( const unsigned char * V_7 )
{
int V_11 ;
T_3 V_12 ;
int V_13 ;
V_11 = 0 ;
for ( V_13 = 0 ; V_13 < V_28 ; V_13 ++ ) {
V_12 = F_6 ( V_7 + V_11 ) ;
F_8 ( L_5 , V_12 & V_29 ) ;
V_11 += 2 ;
if ( ! ( V_12 & V_30 ) ) {
break;
}
}
return V_11 ;
}
static int F_14 ( const unsigned char * V_7 , struct V_8 * V_31 ,
char * V_32 )
{
int V_11 ;
T_3 V_12 ;
int V_13 ;
struct V_8 * V_14 ;
int V_17 ;
V_11 = 0 ;
for ( V_13 = 0 ; V_13 < V_33 ; V_13 ++ ) {
V_12 = F_6 ( V_7 + V_11 ) ;
if ( NULL != ( V_14 = F_7 ( sizeof( struct V_8 ) , V_16 ) ) ) {
V_14 -> V_10 = V_32 ;
V_14 -> V_18 = F_1 ( V_7 + V_11 + 1 ) ;
V_14 -> V_19 = F_1 ( V_7 + V_11 + 1 ) + ( V_12 & V_34 ) + 1 ;
V_14 -> V_20 = V_35 ;
F_8 ( L_6 , ( unsigned long ) V_14 -> V_18 , ( unsigned long ) V_14 -> V_19 ) ;
V_17 = F_9 ( V_31 , V_14 ) ;
if ( V_17 < 0 ) {
F_8 ( V_22 L_3 ) ;
return V_17 ;
}
}
V_11 += 3 ;
if ( ! ( V_12 & V_36 ) ) {
break;
}
}
return V_11 ;
}
static int F_15 ( const unsigned char * V_7 )
{
int V_11 = 0 ;
T_3 V_12 ;
while ( V_11 < V_37 ) {
int V_2 = 0 ;
V_12 = F_6 ( V_7 + V_11 ) ;
switch ( V_12 & V_38 ) {
case V_39 :
V_2 = 1 ;
if ( V_12 & V_40 ) {
F_8 ( V_41 L_7 ) ;
F_16 ( ( F_17 ( F_1 ( V_7 + V_11 + 1 ) &
F_6 ( V_7 + V_11 + 3 ) ) |
F_6 ( V_7 + V_11 + 4 ) ) , F_1 ( V_7 + V_11 + 1 ) ) ;
} else {
F_16 ( F_6 ( V_7 + V_11 + 3 ) , F_1 ( V_7 + V_11 + 1 ) ) ;
}
break;
case V_42 :
V_2 = 2 ;
if ( V_12 & V_40 ) {
F_8 ( V_41 L_7 ) ;
F_18 ( ( F_19 ( F_1 ( V_7 + V_11 + 1 ) ) &
F_1 ( V_7 + V_11 + 3 ) ) |
F_1 ( V_7 + V_11 + 5 ) ,
F_1 ( V_7 + V_11 + 1 ) ) ;
} else {
F_18 ( F_20 ( F_1 ( V_7 + V_11 + 3 ) ) , F_1 ( V_7 + V_11 + 1 ) ) ;
}
break;
case V_43 :
V_2 = 4 ;
if ( V_12 & V_40 ) {
F_8 ( V_41 L_7 ) ;
F_21 ( ( F_22 ( F_1 ( V_7 + V_11 + 1 ) &
F_2 ( V_7 + V_11 + 3 ) ) |
F_2 ( V_7 + V_11 + 7 ) ) , F_1 ( V_7 + V_11 + 1 ) ) ;
} else {
F_21 ( F_23 ( F_2 ( V_7 + V_11 + 3 ) ) , F_1 ( V_7 + V_11 + 1 ) ) ;
}
break;
default:
F_8 ( V_22 L_8 , V_12 ) ;
return 0 ;
}
if ( V_12 & V_40 ) {
V_2 *= 2 ;
}
V_11 += V_2 + 3 ;
if ( ! ( V_12 & V_44 ) ) {
break;
}
}
return V_11 ;
}
static int F_24 ( const unsigned char * V_7 , T_3 * V_45 )
{
int V_11 ;
V_11 = F_6 ( V_7 ) ;
* V_45 = F_6 ( V_7 + V_11 + 1 ) ;
return V_11 + 2 ;
}
static int F_25 ( const unsigned char * V_7 )
{
int V_11 ;
V_11 = F_6 ( V_7 ) ;
if ( V_11 > 80 ) {
F_8 ( V_22 L_9 , V_11 ) ;
}
return 1 + V_11 ;
}
static int F_26 ( const unsigned char * V_7 , int * V_46 )
{
* V_46 = F_1 ( V_7 ) ;
return 2 ;
}
static int F_27 ( int V_47 ,
const unsigned char * V_7 ,
struct V_48 * V_49 ,
struct V_8 * V_31 ,
struct V_8 * V_9 )
{
int V_14 = 0 ;
int V_50 ;
unsigned int V_51 = 0 ;
unsigned int V_52 ;
int V_53 = 0 ;
T_3 V_20 ;
int V_54 ;
char * V_32 ;
int V_55 = 0 ;
if ( NULL == ( V_32 = F_28 ( 8 , V_16 ) ) ) {
return - 1 ;
}
F_4 ( V_32 , V_49 -> V_56 ) ;
F_8 ( V_57 L_10 ,
V_47 , V_32 , V_49 -> V_20 & V_58 ? L_11 : L_12 ) ;
V_52 = V_49 -> V_59 < V_60 ?
V_49 -> V_59 : V_60 ;
while ( ( V_51 < V_52 ) && ( V_53 <= V_49 -> V_61 ) ) {
V_51 += F_26 ( V_7 + V_51 , & V_50 ) ;
if ( ! V_50 ) {
break;
}
V_53 ++ ;
V_54 = V_51 ;
V_51 += F_24 ( V_7 + V_51 , & V_20 ) ;
if ( V_20 & V_62 ) {
V_51 = V_54 + V_50 ;
continue;
}
if ( V_20 & V_63 ) {
F_8 ( L_13 ,
V_53 ) ;
V_51 = V_54 + V_50 ;
continue;
}
if ( V_20 & V_64 ) {
V_51 += F_25 ( V_7 + V_51 ) ;
}
if ( V_20 & V_65 ) {
V_55 = 1 ;
V_51 += F_5 ( V_7 + V_51 , V_9 , V_32 ) ;
}
if ( V_20 & V_66 ) {
V_51 += F_10 ( V_7 + V_51 ) ;
}
if ( V_20 & V_67 ) {
V_51 += F_13 ( V_7 + V_51 ) ;
}
if ( V_20 & V_68 ) {
V_55 = 1 ;
V_51 += F_14 ( V_7 + V_51 , V_31 , V_32 ) ;
}
if ( V_20 & V_69 ) {
V_51 += F_15 ( V_7 + V_51 ) ;
}
if ( V_54 + V_50 < V_51 ) {
F_8 ( V_22 L_14
L_15 ,
V_53 , V_51 - V_54 , V_50 ) ;
V_14 = - 1 ;
break;
}
V_51 = V_54 + V_50 ;
}
F_8 ( L_16 ) ;
if ( ! V_55 ) {
F_29 ( V_32 ) ;
}
if ( V_51 != V_49 -> V_59 ) {
F_8 ( V_22 L_17 ,
V_51 , V_49 -> V_59 ) ;
V_14 = - 1 ;
}
if ( V_53 != V_49 -> V_61 ) {
F_8 ( V_22 L_18 ,
V_53 , V_49 -> V_61 ) ;
V_14 = - 2 ;
}
return V_14 ;
}
static int F_30 ( int V_47 , struct V_48 * V_49 )
{
unsigned int V_3 ;
char V_70 [ 8 ] ;
if ( ! ( V_49 -> V_71 & V_72 ) ) {
V_3 = F_31 ( F_22 ( F_32 ( V_47 ) + V_73 ) ) ;
if ( 0xffffffff == V_3 ) {
if ( V_49 -> V_56 == 0xffffffff )
return - 1 ;
F_8 ( V_22 L_19 ,
V_47 ) ;
F_4 ( V_70 , V_49 -> V_56 ) ;
F_8 ( L_20 , V_70 ) ;
return - 1 ;
}
if ( V_49 -> V_56 != V_3 ) {
F_4 ( V_70 , V_3 ) ;
F_8 ( V_22 L_21 ,
V_47 , V_70 ) ;
F_4 ( V_70 , V_49 -> V_56 ) ;
F_8 ( L_22 , V_70 ) ;
return - 1 ;
}
}
if ( V_49 -> V_74 & V_75 ) {
F_16 ( 0x01 | F_17 ( F_32 ( V_47 ) + V_73 + 4 ) ,
F_32 ( V_47 ) + V_73 + 4 ) ;
}
return 0 ;
}
int F_33 ( unsigned long V_76 ,
struct V_8 * V_31 , struct V_8 * V_9 )
{
int V_13 ;
struct V_77 * V_78 ;
static char V_79 [ V_60 ] ;
for ( V_13 = 0 ; V_13 < V_60 ; V_13 ++ ) {
V_79 [ V_13 ] = F_34 ( V_76 + V_13 ) ;
}
F_8 ( V_57 L_23 ) ;
V_78 = (struct V_77 * ) ( V_79 ) ;
for ( V_13 = 0 ; V_13 < V_78 -> V_80 ; V_13 ++ ) {
struct V_48 * V_49 ;
V_49 = (struct V_48 * )
( & V_79 [ F_35 ( V_13 ) ] ) ;
if ( - 1 == F_30 ( V_13 + 1 , V_49 ) ) {
continue;
}
if ( V_49 -> V_81 < V_60 ) {
if ( F_27 ( V_13 + 1 , & V_79 [ V_49 -> V_81 ] ,
V_49 , V_31 , V_9 ) ) {
return - 1 ;
}
} else {
F_8 ( V_41 L_24 , V_49 -> V_81 ) ;
return - 1 ;
}
}
return V_78 -> V_80 ;
}
