static T_1 char F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + ( V_3 << 4 ) ) ;
}
static T_1 void F_3 ( struct V_1 * V_2 , int V_3 , int V_5 )
{
F_4 ( V_2 -> V_4 + ( V_3 << 4 ) , V_5 ) ;
}
static int T_2 F_5 ( char * V_6 ) {
#ifdef F_6
int V_7 [ 7 ] ;
( void ) F_7 ( V_6 , F_8 ( V_7 ) , V_7 ) ;
if ( V_8 ++ || V_7 [ 0 ] < 1 || V_7 [ 0 ] > 6 ) {
F_9 ( V_9 L_1
L_2 ) ;
F_9 ( V_10 L_3 ) ;
return 0 ;
}
if ( V_7 [ 0 ] >= 1 ) {
if ( V_7 [ 1 ] > 0 )
V_11 = V_7 [ 1 ] ;
}
if ( V_7 [ 0 ] >= 2 ) {
if ( V_7 [ 2 ] > 0 )
V_12 = V_7 [ 2 ] ;
}
if ( V_7 [ 0 ] >= 3 ) {
if ( V_7 [ 3 ] >= 0 ) {
V_13 = V_7 [ 3 ] ;
if ( V_13 > V_14 )
V_13 = V_14 ;
}
}
if ( V_7 [ 0 ] >= 4 ) {
if ( V_7 [ 4 ] >= 0 && V_7 [ 4 ] <= 7 )
V_15 = V_7 [ 4 ] ;
else if ( V_7 [ 4 ] > 7 )
F_9 ( V_9 L_4 , V_7 [ 4 ] ) ;
}
#ifdef F_10
if ( V_7 [ 0 ] >= 5 ) {
if ( V_7 [ 5 ] >= 0 )
V_16 = ! ! V_7 [ 5 ] ;
}
if ( V_7 [ 0 ] == 6 ) {
if ( V_7 [ 6 ] >= 0 )
V_17 = V_7 [ 6 ] ;
}
#else
if ( V_7 [ 0 ] == 5 ) {
if ( V_7 [ 5 ] >= 0 )
V_17 = V_7 [ 5 ] ;
}
#endif
#endif
return 1 ;
}
int T_2 F_11 ( struct V_18 * V_19 )
{
static int V_20 = 0 ;
int V_21 = 0 ;
struct V_1 * V_2 ;
if ( ! V_22 || V_20 )
return ( 0 ) ;
if ( V_23 -> V_24 != V_25 )
return ( 0 ) ;
V_19 -> V_26 =
( V_11 > 0 ) ? V_11 : V_27 ;
V_19 -> V_28 =
( V_12 > 0 ) ? V_12 : V_29 ;
V_19 -> V_30 =
( V_13 >= 0 ) ? V_13 : V_31 ;
if ( V_15 >= 0 )
V_19 -> V_32 = V_15 ;
else {
V_19 -> V_32 = 7 ;
}
#ifdef F_10
if ( V_16 < 0 )
V_16 = V_33 ;
#endif
V_2 = F_12 ( V_19 , sizeof( struct V_34 ) ) ;
if ( V_23 -> V_35 == V_36 ) {
V_37 = V_38 + 0x8000 ;
V_39 = V_38 + 0xE000 ;
V_40 = V_38 + 0xC000 ;
V_21 = V_41 ;
} else {
V_37 = V_38 + 0x10000 ;
V_39 = V_38 + 0x6000 ;
V_40 = V_38 + 0x12000 ;
}
if ( ! V_17 )
V_21 = V_41 ;
V_2 -> V_4 = ( unsigned long ) V_37 ;
V_2 -> V_42 = V_43 ;
#ifdef F_13
F_14 ( V_2 ) ;
#endif
F_15 ( V_2 , V_21 ) ;
V_2 -> V_44 = 255 ;
( (struct V_34 * ) V_2 -> V_45 ) -> V_46 = 0 ;
if ( V_2 -> V_42 != V_47 )
if ( F_16 ( V_2 -> V_42 , V_48 , V_49 ,
L_5 , V_2 ) ) {
F_9 ( V_9 L_6 ,
V_2 -> V_50 , V_2 -> V_42 ) ;
V_2 -> V_42 = V_47 ;
}
F_9 ( V_51 L_7 , V_2 -> V_50 , V_2 -> V_4 ) ;
if ( V_2 -> V_42 == V_47 )
F_9 ( V_51 L_8 ) ;
else
F_9 ( V_51 L_9 , V_2 -> V_42 ) ;
F_9 ( V_51 L_10 ,
V_2 -> V_26 , V_2 -> V_28 , V_52 ) ;
F_9 ( V_51 L_11 , V_2 -> V_50 ) ;
F_17 ( V_2 ) ;
F_9 ( L_12 ) ;
V_20 = 1 ;
return 1 ;
}
int F_18 ( struct V_1 * V_53 )
{
if ( V_53 -> V_42 != V_47 )
F_19 ( V_53 -> V_42 , V_53 ) ;
F_20 ( V_53 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
unsigned long V_54 ;
F_21 () ;
F_22 ( V_2 ) ;
F_9 ( V_51 L_13 ) ;
F_23 ( V_43 ) ;
F_24 ( V_55 ,
F_25 ( F_26 ( V_56 ) ) ) ;
F_24 ( V_57 , V_58 | V_59 ) ;
F_27 ( 50 ) ;
F_24 ( V_57 , V_58 ) ;
F_26 ( V_60 ) ;
for( V_54 = V_61 + V_62 ; F_28 ( V_61 , V_54 ) ; )
F_29 () ;
F_30 ( V_43 ) ;
F_9 ( V_51 L_14 ) ;
}
const char * F_31 ( struct V_1 * V_63 ) {
return L_15 ;
}
static int F_32 ( struct V_1 * V_2 ,
unsigned char * V_64 , int V_65 )
{
unsigned char * V_66 ;
volatile unsigned char * V_67 ;
F_21 () ;
F_22 ( V_2 ) ;
V_67 = V_39 + 0x60 ;
V_66 = V_64 ;
while ( ! ( F_26 ( V_68 ) & V_69 )
&& ! ( F_26 ( V_56 ) & V_70 ) )
;
if ( ! ( F_26 ( V_68 ) & V_69 )
&& ( F_26 ( V_68 ) & V_71 ) ) {
F_9 ( V_72 L_16 ) ;
return - 1 ;
}
F_33 ( V_67 , V_66 , V_65 ) ;
if ( V_65 != 0 ) {
F_9 ( V_73 L_17 ) ;
return - 1 ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
unsigned char * V_74 , int V_65 )
{
unsigned char * V_67 ;
volatile unsigned char * V_66 ;
F_21 () ;
F_22 ( V_2 ) ;
V_67 = V_74 ;
V_66 = V_39 ;
while ( ! ( F_26 ( V_68 ) & V_69 )
&& ( ! ( F_26 ( V_56 ) & V_70 )
|| ( F_26 ( V_68 ) & V_71 ) ) )
;
if ( ! ( F_26 ( V_68 ) & V_69 ) ) {
F_9 ( V_72 L_18 ) ;
return - 1 ;
}
F_35 ( V_67 , V_66 , V_65 ) ;
if ( V_65 != 0 ) {
F_9 ( V_73 L_19 ) ;
return - 1 ;
}
return 0 ;
}
