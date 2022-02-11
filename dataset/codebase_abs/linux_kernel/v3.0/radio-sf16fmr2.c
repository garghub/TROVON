static inline void F_1 ( int V_1 , int V_2 )
{
for (; V_1 ; -- V_1 )
F_2 ( V_2 ) ;
}
static void F_3 ( int V_3 , unsigned int V_4 , int V_5 , int V_2 )
{
int V_6 ;
for (; -- V_3 >= 0 ; ) {
V_6 = ( V_4 >> V_3 ) & 1 ;
F_4 ( V_6 , V_2 ) ;
F_1 ( V_5 , V_2 ) ;
F_4 ( V_6 | 2 , V_2 ) ;
F_1 ( V_5 , V_2 ) ;
F_4 ( V_6 , V_2 ) ;
F_1 ( V_5 , V_2 ) ;
}
}
static inline void F_5 ( int V_2 )
{
F_4 ( 0x00 , V_2 ) ;
F_1 ( 4 , V_2 ) ;
}
static inline void F_6 ( int V_2 )
{
F_4 ( 0x04 , V_2 ) ;
F_1 ( 4 , V_2 ) ;
}
static inline int F_7 ( int V_2 )
{
int V_1 = F_2 ( V_2 ) ;
F_4 ( 6 , V_2 ) ;
F_2 ( V_2 ) ;
V_1 = ( ( V_1 >> 3 ) & 1 ) ^ 1 ;
F_8 ( ( V_7 L_1 , V_1 ) ) ;
return V_1 ;
}
static int F_9 ( struct V_8 * V_9 )
{
int V_1 = F_2 ( V_9 -> V_2 ) ;
V_1 &= 0xC1 ;
if ( V_1 == 0 ) {
V_9 -> V_10 = 12 ;
return 0 ;
}
V_9 -> V_10 = ( V_1 == 128 ) ? 11 : 0 ;
return V_1 ;
}
static inline int F_10 ( struct V_8 * V_9 )
{
int V_11 = 0xffff ;
F_4 ( 5 , V_9 -> V_2 ) ;
F_1 ( 4 , V_9 -> V_2 ) ;
if ( ! ( F_2 ( V_9 -> V_2 ) & 1 ) )
V_11 = 0 ;
F_8 ( ( V_7 L_2 , V_11 ) ) ;
return V_11 ;
}
static int F_11 ( struct V_8 * V_9 )
{
unsigned long V_12 = V_9 -> V_13 ;
F_5 ( V_9 -> V_2 ) ;
F_3 ( 9 , 0x2 , 3 , V_9 -> V_2 ) ;
F_3 ( 16 , F_12 ( V_12 ) , 2 , V_9 -> V_2 ) ;
F_6 ( V_9 -> V_2 ) ;
F_13 ( 110 ) ;
V_9 -> V_14 = F_7 ( V_9 -> V_2 ) ;
return 0 ;
}
static int F_14 ( struct V_8 * V_9 )
{
int V_15 [ 16 ] = { 0x021 , 0x084 , 0x090 , 0x104 ,
0x110 , 0x204 , 0x210 , 0x402 ,
0x404 , 0x408 , 0x410 , 0x801 ,
0x802 , 0x804 , 0x808 , 0x810 } ;
int V_16 , V_17 ;
int V_1 = V_15 [ V_9 -> V_18 & 0x0f ] ;
if ( V_9 -> V_10 != 11 )
return 1 ;
for ( V_16 = 12 ; -- V_16 >= 0 ; ) {
V_17 = ( ( V_1 >> V_16 ) & 1 ) << 6 ;
F_4 ( V_17 | 4 , V_9 -> V_2 ) ;
F_1 ( 4 , V_9 -> V_2 ) ;
F_4 ( V_17 | 0x24 , V_9 -> V_2 ) ;
F_1 ( 4 , V_9 -> V_2 ) ;
F_4 ( V_17 | 4 , V_9 -> V_2 ) ;
F_1 ( 4 , V_9 -> V_2 ) ;
}
for ( V_16 = 6 ; -- V_16 >= 0 ; ) {
V_17 = ( ( 0x18 >> V_16 ) & 1 ) << 6 ;
F_4 ( V_17 | 4 , V_9 -> V_2 ) ;
F_1 ( 4 , V_9 -> V_2 ) ;
F_4 ( V_17 | 0x24 , V_9 -> V_2 ) ;
F_1 ( 4 , V_9 -> V_2 ) ;
F_4 ( V_17 | 4 , V_9 -> V_2 ) ;
F_1 ( 4 , V_9 -> V_2 ) ;
}
F_1 ( 4 , V_9 -> V_2 ) ;
F_4 ( 0x14 , V_9 -> V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_19 * V_19 , void * V_20 ,
struct V_21 * V_22 )
{
F_16 ( V_22 -> V_23 , L_3 , sizeof( V_22 -> V_23 ) ) ;
F_16 ( V_22 -> V_24 , L_4 , sizeof( V_22 -> V_24 ) ) ;
F_16 ( V_22 -> V_25 , L_5 , sizeof( V_22 -> V_25 ) ) ;
V_22 -> V_26 = V_27 ;
V_22 -> V_28 = V_29 | V_30 ;
return 0 ;
}
static int F_17 ( struct V_19 * V_19 , void * V_20 ,
struct V_31 * V_22 )
{
struct V_8 * V_8 = F_18 ( V_19 ) ;
if ( V_22 -> V_32 > 0 )
return - V_33 ;
F_16 ( V_22 -> V_34 , L_6 , sizeof( V_22 -> V_34 ) ) ;
V_22 -> type = V_35 ;
V_22 -> V_36 = V_37 ;
V_22 -> V_38 = V_39 ;
V_22 -> V_40 = V_8 -> V_14 ? V_41 :
V_42 ;
V_22 -> V_43 = V_44 | V_45 ;
V_22 -> V_46 = V_47 ;
F_19 ( & V_8 -> V_48 ) ;
V_22 -> signal = F_10 ( V_8 ) ;
F_20 ( & V_8 -> V_48 ) ;
return 0 ;
}
static int F_21 ( struct V_19 * V_19 , void * V_20 ,
struct V_31 * V_22 )
{
return V_22 -> V_32 ? - V_33 : 0 ;
}
static int F_22 ( struct V_19 * V_19 , void * V_20 ,
struct V_49 * V_50 )
{
struct V_8 * V_8 = F_18 ( V_19 ) ;
if ( V_50 -> V_51 != 0 || V_50 -> type != V_35 )
return - V_33 ;
if ( V_50 -> V_52 < V_37 ||
V_50 -> V_52 > V_39 )
return - V_33 ;
V_8 -> V_13 = ( V_50 -> V_52 / 200 ) * 200 ;
if ( V_8 -> V_18 && ! V_8 -> V_53 ) {
F_19 ( & V_8 -> V_48 ) ;
F_11 ( V_8 ) ;
F_20 ( & V_8 -> V_48 ) ;
}
return 0 ;
}
static int F_23 ( struct V_19 * V_19 , void * V_20 ,
struct V_49 * V_50 )
{
struct V_8 * V_8 = F_18 ( V_19 ) ;
if ( V_50 -> V_51 != 0 )
return - V_33 ;
V_50 -> type = V_35 ;
V_50 -> V_52 = V_8 -> V_13 ;
return 0 ;
}
static int F_24 ( struct V_19 * V_19 , void * V_20 ,
struct V_54 * V_55 )
{
struct V_8 * V_8 = F_18 ( V_19 ) ;
switch ( V_55 -> V_56 ) {
case V_57 :
return F_25 ( V_55 , 0 , 1 , 1 , 1 ) ;
case V_58 :
if ( V_8 -> V_10 == 11 )
return F_25 ( V_55 , 0 , 15 , 1 , 0 ) ;
return F_25 ( V_55 , 0 , 1 , 1 , 0 ) ;
}
return - V_33 ;
}
static int F_26 ( struct V_19 * V_19 , void * V_20 ,
struct V_59 * V_60 )
{
struct V_8 * V_8 = F_18 ( V_19 ) ;
switch ( V_60 -> V_56 ) {
case V_57 :
V_60 -> V_61 = V_8 -> V_53 ;
return 0 ;
case V_58 :
V_60 -> V_61 = V_8 -> V_18 ;
return 0 ;
}
return - V_33 ;
}
static int F_27 ( struct V_19 * V_19 , void * V_20 ,
struct V_59 * V_60 )
{
struct V_8 * V_8 = F_18 ( V_19 ) ;
switch ( V_60 -> V_56 ) {
case V_57 :
V_8 -> V_53 = V_60 -> V_61 ;
break;
case V_58 :
V_8 -> V_18 = V_60 -> V_61 ;
break;
default:
return - V_33 ;
}
#ifdef F_28
if ( V_8 -> V_18 && ! V_8 -> V_53 )
F_29 ( V_7 L_7 ) ;
else
F_29 ( V_7 L_8 ) ;
#endif
F_19 ( & V_8 -> V_48 ) ;
if ( V_8 -> V_18 && ! V_8 -> V_53 ) {
F_14 ( V_8 ) ;
F_11 ( V_8 ) ;
} else
F_5 ( V_8 -> V_2 ) ;
F_20 ( & V_8 -> V_48 ) ;
return 0 ;
}
static int F_30 ( struct V_19 * V_62 , void * V_20 , unsigned int * V_16 )
{
* V_16 = 0 ;
return 0 ;
}
static int F_31 ( struct V_19 * V_62 , void * V_20 , unsigned int V_16 )
{
return V_16 ? - V_33 : 0 ;
}
static int F_32 ( struct V_19 * V_19 , void * V_20 ,
struct V_63 * V_17 )
{
V_17 -> V_32 = 0 ;
F_16 ( V_17 -> V_34 , L_9 , sizeof( V_17 -> V_34 ) ) ;
V_17 -> V_43 = V_64 ;
return 0 ;
}
static int F_33 ( struct V_19 * V_19 , void * V_20 ,
struct V_63 * V_17 )
{
return V_17 -> V_32 ? - V_33 : 0 ;
}
static int T_1 F_34 ( void )
{
struct V_8 * V_8 = & V_65 ;
struct V_66 * V_67 = & V_8 -> V_67 ;
int V_11 ;
F_16 ( V_67 -> V_34 , L_10 , sizeof( V_67 -> V_34 ) ) ;
V_8 -> V_2 = V_2 ;
V_8 -> V_14 = 1 ;
F_35 ( & V_8 -> V_48 ) ;
if ( ! F_36 ( V_8 -> V_2 , 2 , L_10 ) ) {
F_37 ( V_67 , L_11 ) ;
return - V_68 ;
}
V_11 = F_38 ( NULL , V_67 ) ;
if ( V_11 < 0 ) {
F_39 ( V_8 -> V_2 , 2 ) ;
F_37 ( V_67 , L_12 ) ;
return V_11 ;
}
F_16 ( V_8 -> V_69 . V_34 , V_67 -> V_34 , sizeof( V_8 -> V_69 . V_34 ) ) ;
V_8 -> V_69 . V_67 = V_67 ;
V_8 -> V_69 . V_70 = & V_71 ;
V_8 -> V_69 . V_72 = & V_73 ;
V_8 -> V_69 . V_74 = V_75 ;
F_40 ( & V_8 -> V_69 , V_8 ) ;
F_5 ( V_8 -> V_2 ) ;
F_9 ( V_8 ) ;
if ( F_41 ( & V_8 -> V_69 , V_76 , V_77 ) < 0 ) {
F_42 ( V_67 ) ;
F_39 ( V_8 -> V_2 , 2 ) ;
return - V_33 ;
}
F_43 ( V_67 , L_13 , V_8 -> V_2 ) ;
F_8 ( ( V_7 L_14 , V_8 -> V_10 ) ) ;
return 0 ;
}
static void T_2 F_44 ( void )
{
struct V_8 * V_8 = & V_65 ;
F_45 ( & V_8 -> V_69 ) ;
F_42 ( & V_8 -> V_67 ) ;
F_39 ( V_8 -> V_2 , 2 ) ;
}
static int T_1 F_46 ( char * V_78 )
{
F_47 ( & V_78 , & V_2 ) ;
return 1 ;
}
