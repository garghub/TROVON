static void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( & V_2 -> V_4 ) ;
V_3 >>= 14 ;
V_3 &= 3 ;
F_3 ( V_3 / 2 , V_2 -> V_5 ) ;
F_3 ( V_3 % 2 , V_2 -> V_5 + 2 ) ;
F_4 ( & V_2 -> V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned long V_6 )
{
unsigned long V_7 ;
unsigned long V_8 ;
F_2 ( & V_2 -> V_4 ) ;
V_8 = V_6 / 160 ;
V_7 = ( V_8 * V_8 + 2500 ) / 5000 ;
V_7 = ( V_7 * V_8 + 5000 ) / 10000 ;
V_7 -= ( 10 * V_8 * V_8 + 10433 ) / 20866 ;
V_7 += 4 * V_8 - 11505 ;
F_3 ( ( V_7 >> 8 ) & 0x01 , V_2 -> V_5 + 4 ) ;
F_3 ( V_7 >> 9 , V_2 -> V_5 + 6 ) ;
F_3 ( V_7 & 0xff , V_2 -> V_5 + 8 ) ;
F_4 ( & V_2 -> V_4 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned long V_6 )
{
F_5 ( V_2 , V_6 ) ;
V_2 -> V_9 = V_6 ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 == 1 )
return;
F_1 ( V_2 , 0 ) ;
F_5 ( V_2 , V_2 -> V_11 ) ;
V_2 -> V_10 = 1 ;
}
static void F_8 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 == 0 )
return;
F_5 ( V_2 , V_2 -> V_9 ) ;
F_1 ( V_2 , V_2 -> V_12 ) ;
V_2 -> V_10 = 0 ;
}
static int F_9 ( struct V_1 * V_2 , int V_3 )
{
if ( V_2 -> V_10 && V_3 != 0 ) {
V_2 -> V_12 = V_3 ;
F_8 ( V_2 ) ;
return 0 ;
}
if ( V_3 == V_2 -> V_12 )
return 0 ;
if ( V_3 == 0 ) {
F_7 ( V_2 ) ;
V_2 -> V_12 = V_3 ;
return 0 ;
}
F_1 ( V_2 , V_3 ) ;
V_2 -> V_12 = V_3 ;
return 0 ;
}
static int F_10 ( struct V_13 * V_13 , void * V_14 ,
struct V_15 * V_16 )
{
F_11 ( V_16 -> V_17 , L_1 , sizeof( V_16 -> V_17 ) ) ;
F_11 ( V_16 -> V_18 , L_2 , sizeof( V_16 -> V_18 ) ) ;
F_11 ( V_16 -> V_19 , L_3 , sizeof( V_16 -> V_19 ) ) ;
V_16 -> V_20 = V_21 ;
V_16 -> V_22 = V_23 | V_24 ;
return 0 ;
}
static int F_12 ( struct V_13 * V_13 , void * V_14 ,
struct V_25 * V_16 )
{
if ( V_16 -> V_26 > 0 )
return - V_27 ;
F_11 ( V_16 -> V_28 , L_4 , sizeof( V_16 -> V_28 ) ) ;
V_16 -> type = V_29 ;
V_16 -> V_30 = 87.5 * 16000 ;
V_16 -> V_31 = 108 * 16000 ;
V_16 -> V_32 = V_33 ;
V_16 -> V_34 = V_35 ;
V_16 -> V_36 = V_37 ;
V_16 -> signal = 0xFFFF ;
return 0 ;
}
static int F_13 ( struct V_13 * V_13 , void * V_14 ,
struct V_25 * V_16 )
{
return V_16 -> V_26 ? - V_27 : 0 ;
}
static int F_14 ( struct V_13 * V_13 , void * V_14 ,
struct V_38 * V_39 )
{
struct V_1 * V_2 = F_15 ( V_13 ) ;
if ( V_39 -> V_40 != 0 )
return - V_27 ;
V_39 -> type = V_29 ;
V_39 -> V_6 = V_2 -> V_9 ;
return 0 ;
}
static int F_16 ( struct V_13 * V_13 , void * V_14 ,
struct V_38 * V_39 )
{
struct V_1 * V_2 = F_15 ( V_13 ) ;
if ( V_39 -> V_40 != 0 || V_39 -> type != V_29 )
return - V_27 ;
V_2 -> V_9 = V_39 -> V_6 ;
F_6 ( V_2 , V_2 -> V_9 ) ;
return 0 ;
}
static int F_17 ( struct V_13 * V_13 , void * V_14 ,
struct V_41 * V_42 )
{
switch ( V_42 -> V_43 ) {
case V_44 :
return F_18 ( V_42 , 0 , 1 , 1 , 1 ) ;
case V_45 :
return F_18 ( V_42 , 0 , 65535 , 16384 , 65535 ) ;
}
return - V_27 ;
}
static int F_19 ( struct V_13 * V_13 , void * V_14 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = F_15 ( V_13 ) ;
switch ( V_47 -> V_43 ) {
case V_44 :
V_47 -> V_48 = V_2 -> V_10 ;
return 0 ;
case V_45 :
V_47 -> V_48 = V_2 -> V_12 ;
return 0 ;
}
return - V_27 ;
}
static int F_20 ( struct V_13 * V_13 , void * V_14 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = F_15 ( V_13 ) ;
switch ( V_47 -> V_43 ) {
case V_44 :
if ( V_47 -> V_48 )
F_7 ( V_2 ) ;
else
F_8 ( V_2 ) ;
return 0 ;
case V_45 :
F_9 ( V_2 , V_47 -> V_48 ) ;
return 0 ;
}
return - V_27 ;
}
static int F_21 ( struct V_13 * V_49 , void * V_14 , unsigned int * V_50 )
{
* V_50 = 0 ;
return 0 ;
}
static int F_22 ( struct V_13 * V_49 , void * V_14 , unsigned int V_50 )
{
return V_50 ? - V_27 : 0 ;
}
static int F_23 ( struct V_13 * V_13 , void * V_14 ,
struct V_51 * V_52 )
{
V_52 -> V_26 = 0 ;
F_11 ( V_52 -> V_28 , L_5 , sizeof( V_52 -> V_28 ) ) ;
V_52 -> V_34 = V_53 ;
return 0 ;
}
static int F_24 ( struct V_13 * V_13 , void * V_14 ,
struct V_51 * V_52 )
{
return V_52 -> V_26 ? - V_27 : 0 ;
}
static int F_25 ( struct V_13 * V_13 , void * V_14 )
{
struct V_1 * V_2 = F_15 ( V_13 ) ;
struct V_54 * V_55 = & V_2 -> V_55 ;
F_26 ( V_55 , V_56 ) ;
#ifdef F_27
F_26 ( V_55 , L_6 ) ;
#else
F_26 ( V_55 , L_7 ) ;
#endif
F_26 ( V_55 , L_8 , V_2 -> V_9 >> 4 ) ;
F_26 ( V_55 , L_9 , V_2 -> V_12 ) ;
F_26 ( V_55 , L_10 , V_2 -> V_10 ? L_11 : L_12 ) ;
F_26 ( V_55 , L_13 , V_2 -> V_5 ) ;
F_26 ( V_55 , L_14 , V_2 -> V_11 >> 4 ) ;
return 0 ;
}
static int T_1 F_28 ( void )
{
struct V_1 * V_2 = & V_57 ;
struct V_54 * V_55 = & V_2 -> V_55 ;
int V_58 ;
F_11 ( V_55 -> V_28 , L_15 , sizeof( V_55 -> V_28 ) ) ;
V_2 -> V_5 = V_5 ;
if ( V_2 -> V_5 == - 1 ) {
F_29 ( V_55 , L_16 ) ;
return - V_27 ;
}
if ( V_11 < 87000 || V_11 > 108500 ) {
F_29 ( V_55 , L_17 ) ;
F_29 ( V_55 , L_18 ) ;
return - V_27 ;
}
V_2 -> V_9 = V_2 -> V_11 = V_11 << 4 ;
F_30 ( & V_2 -> V_4 ) ;
if ( ! F_31 ( V_2 -> V_5 , 8 , L_15 ) ) {
F_29 ( V_55 , L_19 ,
V_2 -> V_5 ) ;
return - V_59 ;
}
V_58 = F_32 ( NULL , V_55 ) ;
if ( V_58 < 0 ) {
F_33 ( V_2 -> V_5 , 8 ) ;
F_29 ( V_55 , L_20 ) ;
return V_58 ;
}
F_26 ( V_55 , V_56 ) ;
F_11 ( V_2 -> V_60 . V_28 , V_55 -> V_28 , sizeof( V_2 -> V_60 . V_28 ) ) ;
V_2 -> V_60 . V_55 = V_55 ;
V_2 -> V_60 . V_61 = & V_62 ;
V_2 -> V_60 . V_63 = & V_64 ;
V_2 -> V_60 . V_65 = V_66 ;
F_34 ( & V_2 -> V_60 , V_2 ) ;
F_7 ( V_2 ) ;
if ( F_35 ( & V_2 -> V_60 , V_67 , V_68 ) < 0 ) {
F_36 ( & V_2 -> V_55 ) ;
F_33 ( V_2 -> V_5 , 8 ) ;
return - V_27 ;
}
F_26 ( V_55 , L_21 , V_2 -> V_5 ) ;
F_26 ( V_55 , L_22 , V_11 ) ;
return 0 ;
}
static void T_2 F_37 ( void )
{
struct V_1 * V_2 = & V_57 ;
F_38 ( & V_2 -> V_60 ) ;
F_36 ( & V_2 -> V_55 ) ;
F_33 ( V_2 -> V_5 , 8 ) ;
}
