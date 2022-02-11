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
int F_11 ( struct V_18 * V_19 )
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
#if V_35
V_36 = V_2 ;
#endif
if ( V_23 -> V_37 == V_38 ) {
V_39 = V_40 + 0x8000 ;
V_41 = V_40 + 0xE000 ;
V_42 = V_40 + 0xC000 ;
V_21 = V_43 ;
} else {
V_39 = V_40 + 0x10000 ;
V_41 = V_40 + 0x6000 ;
V_42 = V_40 + 0x12000 ;
}
if ( ! V_17 )
V_21 = V_43 ;
V_2 -> V_4 = ( unsigned long ) V_39 ;
V_2 -> V_44 = V_45 ;
#ifdef F_13
F_14 ( V_2 ) ;
#endif
F_15 ( V_2 , V_21 ) ;
V_2 -> V_46 = 255 ;
( (struct V_34 * ) V_2 -> V_47 ) -> V_48 = 0 ;
if ( V_2 -> V_44 != V_49 )
if ( F_16 ( V_2 -> V_44 , V_50 , V_51 ,
L_5 , V_2 ) ) {
F_9 ( V_9 L_6 ,
V_2 -> V_52 , V_2 -> V_44 ) ;
V_2 -> V_44 = V_49 ;
}
F_9 ( V_53 L_7 , V_2 -> V_52 , V_2 -> V_4 ) ;
if ( V_2 -> V_44 == V_49 )
F_9 ( V_53 L_8 ) ;
else
F_9 ( V_53 L_9 , V_2 -> V_44 ) ;
F_9 ( V_53 L_10 ,
V_2 -> V_26 , V_2 -> V_28 , V_54 ) ;
F_9 ( V_53 L_11 , V_2 -> V_52 ) ;
F_17 ( V_2 ) ;
F_9 ( L_12 ) ;
V_20 = 1 ;
return 1 ;
}
int F_18 ( struct V_1 * V_55 )
{
if ( V_55 -> V_44 != V_49 )
F_19 ( V_55 -> V_44 , V_55 ) ;
F_20 ( V_55 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
unsigned long V_56 ;
F_21 () ;
F_22 ( V_2 ) ;
F_9 ( V_53 L_13 ) ;
F_23 ( V_45 ) ;
F_24 ( V_57 ,
F_25 ( F_26 ( V_58 ) ) ) ;
F_24 ( V_59 , V_60 | V_61 ) ;
F_27 ( 50 ) ;
F_24 ( V_59 , V_60 ) ;
F_26 ( V_62 ) ;
for( V_56 = V_63 + V_64 ; F_28 ( V_63 , V_56 ) ; )
F_29 () ;
F_30 ( V_45 ) ;
F_9 ( V_53 L_14 ) ;
}
const char * F_31 ( struct V_1 * V_65 ) {
return L_15 ;
}
static int F_32 ( struct V_1 * V_2 ,
unsigned char * V_66 , int V_67 )
{
unsigned char * V_68 ;
volatile unsigned char * V_69 ;
F_21 () ;
F_22 ( V_2 ) ;
V_69 = V_41 + 0x60 ;
V_68 = V_66 ;
while ( ! ( F_26 ( V_70 ) & V_71 )
&& ! ( F_26 ( V_58 ) & V_72 ) )
;
if ( ! ( F_26 ( V_70 ) & V_71 )
&& ( F_26 ( V_70 ) & V_73 ) ) {
F_9 ( V_74 L_16 ) ;
return - 1 ;
}
F_33 ( V_69 , V_68 , V_67 ) ;
if ( V_67 != 0 ) {
F_9 ( V_75 L_17 ) ;
return - 1 ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
unsigned char * V_76 , int V_67 )
{
unsigned char * V_69 ;
volatile unsigned char * V_68 ;
F_21 () ;
F_22 ( V_2 ) ;
V_69 = V_76 ;
V_68 = V_41 ;
while ( ! ( F_26 ( V_70 ) & V_71 )
&& ( ! ( F_26 ( V_58 ) & V_72 )
|| ( F_26 ( V_70 ) & V_73 ) ) )
;
if ( ! ( F_26 ( V_70 ) & V_71 ) ) {
F_9 ( V_74 L_18 ) ;
return - 1 ;
}
F_35 ( V_69 , V_68 , V_67 ) ;
if ( V_67 != 0 ) {
F_9 ( V_75 L_19 ) ;
return - 1 ;
}
return 0 ;
}
