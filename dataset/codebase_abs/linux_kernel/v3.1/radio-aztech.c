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
V_17 -> V_21 = V_22 | V_23 ;
return 0 ;
}
static int F_16 ( struct V_14 * V_14 , void * V_15 ,
struct V_24 * V_17 )
{
struct V_2 * V_3 = F_17 ( V_14 ) ;
if ( V_17 -> V_25 > 0 )
return - V_26 ;
F_15 ( V_17 -> V_27 , L_4 , sizeof( V_17 -> V_27 ) ) ;
V_17 -> type = V_28 ;
V_17 -> V_29 = 87 * 16000 ;
V_17 -> V_30 = 108 * 16000 ;
V_17 -> V_31 = V_32 | V_33 ;
V_17 -> V_34 = V_35 ;
if ( F_12 ( V_3 ) )
V_17 -> V_36 = V_37 ;
else
V_17 -> V_36 = V_38 ;
V_17 -> signal = 0xFFFF * F_10 ( V_3 ) ;
return 0 ;
}
static int F_18 ( struct V_14 * V_14 , void * V_15 ,
struct V_24 * V_17 )
{
return V_17 -> V_25 ? - V_26 : 0 ;
}
static int F_19 ( struct V_14 * V_39 , void * V_15 , unsigned int * V_12 )
{
* V_12 = 0 ;
return 0 ;
}
static int F_20 ( struct V_14 * V_39 , void * V_15 , unsigned int V_12 )
{
return V_12 ? - V_26 : 0 ;
}
static int F_21 ( struct V_14 * V_14 , void * V_15 ,
struct V_40 * V_41 )
{
V_41 -> V_25 = 0 ;
F_15 ( V_41 -> V_27 , L_5 , sizeof( V_41 -> V_27 ) ) ;
V_41 -> V_34 = V_42 ;
return 0 ;
}
static int F_22 ( struct V_14 * V_14 , void * V_15 ,
struct V_40 * V_41 )
{
return V_41 -> V_25 ? - V_26 : 0 ;
}
static int F_23 ( struct V_14 * V_14 , void * V_15 ,
struct V_43 * V_44 )
{
struct V_2 * V_3 = F_17 ( V_14 ) ;
if ( V_44 -> V_45 != 0 || V_44 -> type != V_28 )
return - V_26 ;
F_13 ( V_3 , V_44 -> V_11 ) ;
return 0 ;
}
static int F_24 ( struct V_14 * V_14 , void * V_15 ,
struct V_43 * V_44 )
{
struct V_2 * V_3 = F_17 ( V_14 ) ;
if ( V_44 -> V_45 != 0 )
return - V_26 ;
V_44 -> type = V_28 ;
V_44 -> V_11 = V_3 -> V_13 ;
return 0 ;
}
static int F_25 ( struct V_14 * V_14 , void * V_15 ,
struct V_46 * V_47 )
{
switch ( V_47 -> V_48 ) {
case V_49 :
return F_26 ( V_47 , 0 , 1 , 1 , 1 ) ;
case V_50 :
return F_26 ( V_47 , 0 , 0xff , 1 , 0xff ) ;
}
return - V_26 ;
}
static int F_27 ( struct V_14 * V_14 , void * V_15 ,
struct V_51 * V_52 )
{
struct V_2 * V_3 = F_17 ( V_14 ) ;
switch ( V_52 -> V_48 ) {
case V_49 :
if ( V_3 -> V_5 == 0 )
V_52 -> V_53 = 1 ;
else
V_52 -> V_53 = 0 ;
return 0 ;
case V_50 :
V_52 -> V_53 = V_3 -> V_5 * 6554 ;
return 0 ;
}
return - V_26 ;
}
static int F_28 ( struct V_14 * V_14 , void * V_15 ,
struct V_51 * V_52 )
{
struct V_2 * V_3 = F_17 ( V_14 ) ;
switch ( V_52 -> V_48 ) {
case V_49 :
if ( V_52 -> V_53 )
F_6 ( V_3 , 0 ) ;
else
F_6 ( V_3 , V_3 -> V_5 ) ;
return 0 ;
case V_50 :
F_6 ( V_3 , V_52 -> V_53 ) ;
return 0 ;
}
return - V_26 ;
}
static int T_1 F_29 ( void )
{
struct V_2 * V_3 = & V_54 ;
struct V_55 * V_56 = & V_3 -> V_56 ;
int V_57 ;
F_15 ( V_56 -> V_27 , L_6 , sizeof( V_56 -> V_27 ) ) ;
V_3 -> V_6 = V_6 ;
if ( V_3 -> V_6 == - 1 ) {
F_30 ( V_56 , L_7 ) ;
return - V_26 ;
}
if ( ! F_31 ( V_3 -> V_6 , 2 , L_6 ) ) {
F_30 ( V_56 , L_8 , V_3 -> V_6 ) ;
return - V_58 ;
}
V_57 = F_32 ( NULL , V_56 ) ;
if ( V_57 < 0 ) {
F_33 ( V_3 -> V_6 , 2 ) ;
F_30 ( V_56 , L_9 ) ;
return V_57 ;
}
F_34 ( & V_3 -> V_8 ) ;
F_15 ( V_3 -> V_59 . V_27 , V_56 -> V_27 , sizeof( V_3 -> V_59 . V_27 ) ) ;
V_3 -> V_59 . V_56 = V_56 ;
V_3 -> V_59 . V_60 = & V_61 ;
V_3 -> V_59 . V_62 = & V_63 ;
V_3 -> V_59 . V_64 = V_65 ;
F_35 ( & V_3 -> V_59 , V_3 ) ;
F_8 ( 0 , V_3 -> V_6 ) ;
if ( F_36 ( & V_3 -> V_59 , V_66 , V_67 ) < 0 ) {
F_37 ( V_56 ) ;
F_33 ( V_3 -> V_6 , 2 ) ;
return - V_26 ;
}
F_38 ( V_56 , L_10 ) ;
return 0 ;
}
static void T_2 F_39 ( void )
{
struct V_2 * V_3 = & V_54 ;
F_40 ( & V_3 -> V_59 ) ;
F_37 ( & V_3 -> V_56 ) ;
F_33 ( V_3 -> V_6 , 2 ) ;
}
