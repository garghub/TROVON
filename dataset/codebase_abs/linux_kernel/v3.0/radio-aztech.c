static int F_1 ( int V_1 )
{
V_1 >>= 14 ;
V_1 &= 3 ;
switch ( V_1 ) {
case 0 :
return 0 ;
case 1 :
return 1 ;
case 2 :
return 4 ;
case 3 :
return 5 ;
}
return 0 ;
}
static void F_2 ( struct V_2 * V_3 )
{
F_3 ( V_4 ) ;
F_4 ( 2 + F_1 ( V_3 -> V_5 ) , V_3 -> V_6 ) ;
F_4 ( 64 + 2 + F_1 ( V_3 -> V_5 ) , V_3 -> V_6 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
F_3 ( V_4 ) ;
F_4 ( 128 + 2 + F_1 ( V_3 -> V_5 ) , V_3 -> V_6 ) ;
F_4 ( 128 + 64 + 2 + F_1 ( V_3 -> V_5 ) , V_3 -> V_6 ) ;
}
static int F_6 ( struct V_2 * V_3 , int V_7 )
{
F_7 ( & V_3 -> V_8 ) ;
F_8 ( F_1 ( V_7 ) , V_3 -> V_6 ) ;
F_9 ( & V_3 -> V_8 ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 )
{
int V_9 = 1 ;
F_7 ( & V_3 -> V_8 ) ;
if ( F_11 ( V_3 -> V_6 ) & 2 )
V_9 = 0 ;
F_9 ( & V_3 -> V_8 ) ;
return V_9 ;
}
static int F_12 ( struct V_2 * V_3 )
{
int V_10 = 1 ;
F_7 ( & V_3 -> V_8 ) ;
if ( F_11 ( V_3 -> V_6 ) & 1 )
V_10 = 0 ;
F_9 ( & V_3 -> V_8 ) ;
return V_10 ;
}
static int F_13 ( struct V_2 * V_3 , unsigned long V_11 )
{
int V_12 ;
F_7 ( & V_3 -> V_8 ) ;
V_3 -> V_13 = V_11 ;
V_11 += 171200 ;
V_11 /= 800 ;
F_2 ( V_3 ) ;
for ( V_12 = 0 ; V_12 < 13 ; V_12 ++ )
if ( V_11 & ( 1 << V_12 ) )
F_5 ( V_3 ) ;
else
F_2 ( V_3 ) ;
F_2 ( V_3 ) ;
F_2 ( V_3 ) ;
F_2 ( V_3 ) ;
if ( V_3 -> V_10 )
F_5 ( V_3 ) ;
else
F_2 ( V_3 ) ;
F_5 ( V_3 ) ;
F_2 ( V_3 ) ;
F_2 ( V_3 ) ;
F_5 ( V_3 ) ;
F_2 ( V_3 ) ;
F_5 ( V_3 ) ;
F_3 ( V_4 ) ;
F_4 ( 128 + 64 + F_1 ( V_3 -> V_5 ) , V_3 -> V_6 ) ;
F_9 ( & V_3 -> V_8 ) ;
return 0 ;
}
static int F_14 ( struct V_14 * V_14 , void * V_15 ,
struct V_16 * V_17 )
{
F_15 ( V_17 -> V_18 , L_1 , sizeof( V_17 -> V_18 ) ) ;
F_15 ( V_17 -> V_19 , L_2 , sizeof( V_17 -> V_19 ) ) ;
F_15 ( V_17 -> V_20 , L_3 , sizeof( V_17 -> V_20 ) ) ;
V_17 -> V_21 = V_22 ;
V_17 -> V_23 = V_24 | V_25 ;
return 0 ;
}
static int F_16 ( struct V_14 * V_14 , void * V_15 ,
struct V_26 * V_17 )
{
struct V_2 * V_3 = F_17 ( V_14 ) ;
if ( V_17 -> V_27 > 0 )
return - V_28 ;
F_15 ( V_17 -> V_29 , L_4 , sizeof( V_17 -> V_29 ) ) ;
V_17 -> type = V_30 ;
V_17 -> V_31 = 87 * 16000 ;
V_17 -> V_32 = 108 * 16000 ;
V_17 -> V_33 = V_34 | V_35 ;
V_17 -> V_36 = V_37 ;
if ( F_12 ( V_3 ) )
V_17 -> V_38 = V_39 ;
else
V_17 -> V_38 = V_40 ;
V_17 -> signal = 0xFFFF * F_10 ( V_3 ) ;
return 0 ;
}
static int F_18 ( struct V_14 * V_14 , void * V_15 ,
struct V_26 * V_17 )
{
return V_17 -> V_27 ? - V_28 : 0 ;
}
static int F_19 ( struct V_14 * V_41 , void * V_15 , unsigned int * V_12 )
{
* V_12 = 0 ;
return 0 ;
}
static int F_20 ( struct V_14 * V_41 , void * V_15 , unsigned int V_12 )
{
return V_12 ? - V_28 : 0 ;
}
static int F_21 ( struct V_14 * V_14 , void * V_15 ,
struct V_42 * V_43 )
{
V_43 -> V_27 = 0 ;
F_15 ( V_43 -> V_29 , L_5 , sizeof( V_43 -> V_29 ) ) ;
V_43 -> V_36 = V_44 ;
return 0 ;
}
static int F_22 ( struct V_14 * V_14 , void * V_15 ,
struct V_42 * V_43 )
{
return V_43 -> V_27 ? - V_28 : 0 ;
}
static int F_23 ( struct V_14 * V_14 , void * V_15 ,
struct V_45 * V_46 )
{
struct V_2 * V_3 = F_17 ( V_14 ) ;
if ( V_46 -> V_47 != 0 || V_46 -> type != V_30 )
return - V_28 ;
F_13 ( V_3 , V_46 -> V_11 ) ;
return 0 ;
}
static int F_24 ( struct V_14 * V_14 , void * V_15 ,
struct V_45 * V_46 )
{
struct V_2 * V_3 = F_17 ( V_14 ) ;
if ( V_46 -> V_47 != 0 )
return - V_28 ;
V_46 -> type = V_30 ;
V_46 -> V_11 = V_3 -> V_13 ;
return 0 ;
}
static int F_25 ( struct V_14 * V_14 , void * V_15 ,
struct V_48 * V_49 )
{
switch ( V_49 -> V_50 ) {
case V_51 :
return F_26 ( V_49 , 0 , 1 , 1 , 1 ) ;
case V_52 :
return F_26 ( V_49 , 0 , 0xff , 1 , 0xff ) ;
}
return - V_28 ;
}
static int F_27 ( struct V_14 * V_14 , void * V_15 ,
struct V_53 * V_54 )
{
struct V_2 * V_3 = F_17 ( V_14 ) ;
switch ( V_54 -> V_50 ) {
case V_51 :
if ( V_3 -> V_5 == 0 )
V_54 -> V_55 = 1 ;
else
V_54 -> V_55 = 0 ;
return 0 ;
case V_52 :
V_54 -> V_55 = V_3 -> V_5 * 6554 ;
return 0 ;
}
return - V_28 ;
}
static int F_28 ( struct V_14 * V_14 , void * V_15 ,
struct V_53 * V_54 )
{
struct V_2 * V_3 = F_17 ( V_14 ) ;
switch ( V_54 -> V_50 ) {
case V_51 :
if ( V_54 -> V_55 )
F_6 ( V_3 , 0 ) ;
else
F_6 ( V_3 , V_3 -> V_5 ) ;
return 0 ;
case V_52 :
F_6 ( V_3 , V_54 -> V_55 ) ;
return 0 ;
}
return - V_28 ;
}
static int T_1 F_29 ( void )
{
struct V_2 * V_3 = & V_56 ;
struct V_57 * V_58 = & V_3 -> V_58 ;
int V_59 ;
F_15 ( V_58 -> V_29 , L_6 , sizeof( V_58 -> V_29 ) ) ;
V_3 -> V_6 = V_6 ;
if ( V_3 -> V_6 == - 1 ) {
F_30 ( V_58 , L_7 ) ;
return - V_28 ;
}
if ( ! F_31 ( V_3 -> V_6 , 2 , L_6 ) ) {
F_30 ( V_58 , L_8 , V_3 -> V_6 ) ;
return - V_60 ;
}
V_59 = F_32 ( NULL , V_58 ) ;
if ( V_59 < 0 ) {
F_33 ( V_3 -> V_6 , 2 ) ;
F_30 ( V_58 , L_9 ) ;
return V_59 ;
}
F_34 ( & V_3 -> V_8 ) ;
F_15 ( V_3 -> V_61 . V_29 , V_58 -> V_29 , sizeof( V_3 -> V_61 . V_29 ) ) ;
V_3 -> V_61 . V_58 = V_58 ;
V_3 -> V_61 . V_62 = & V_63 ;
V_3 -> V_61 . V_64 = & V_65 ;
V_3 -> V_61 . V_66 = V_67 ;
F_35 ( & V_3 -> V_61 , V_3 ) ;
F_8 ( 0 , V_3 -> V_6 ) ;
if ( F_36 ( & V_3 -> V_61 , V_68 , V_69 ) < 0 ) {
F_37 ( V_58 ) ;
F_33 ( V_3 -> V_6 , 2 ) ;
return - V_28 ;
}
F_38 ( V_58 , L_10 ) ;
return 0 ;
}
static void T_2 F_39 ( void )
{
struct V_2 * V_3 = & V_56 ;
F_40 ( & V_3 -> V_61 ) ;
F_37 ( & V_3 -> V_58 ) ;
F_33 ( V_3 -> V_6 , 2 ) ;
}
