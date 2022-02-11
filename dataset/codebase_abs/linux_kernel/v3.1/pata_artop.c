static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_5 -> V_8 -> V_9 ) ;
const struct V_10 V_11 [] = {
{ 0x4AU , 1U , 0x02UL , 0x02UL } ,
{ 0x4AU , 1U , 0x04UL , 0x04UL } ,
} ;
if ( ! F_3 ( V_7 , & V_11 [ V_5 -> V_12 ] ) )
return - V_13 ;
return F_4 ( V_2 , V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 , unsigned long V_3 )
{
static const struct V_10 V_11 [] = {
{ 0x4AU , 1U , 0x02UL , 0x02UL } ,
{ 0x4AU , 1U , 0x04UL , 0x04UL } ,
} ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_5 -> V_8 -> V_9 ) ;
if ( ( V_7 -> V_14 & 1 ) &&
! F_3 ( V_7 , & V_11 [ V_5 -> V_12 ] ) )
return - V_13 ;
return F_4 ( V_2 , V_3 ) ;
}
static int F_6 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 -> V_8 -> V_9 ) ;
T_1 V_15 ;
F_7 ( V_7 , 0x49 , & V_15 ) ;
if ( V_15 & ( 1 << V_5 -> V_12 ) )
return V_16 ;
return V_17 ;
}
static void F_8 ( struct V_4 * V_5 , struct V_18 * V_19 , unsigned int V_20 )
{
struct V_6 * V_7 = F_2 ( V_5 -> V_8 -> V_9 ) ;
int V_21 = V_19 -> V_22 + 2 * V_5 -> V_12 ;
const T_2 V_23 [ 2 ] [ 5 ] = {
{ 0x0000 , 0x000A , 0x0008 , 0x0303 , 0x0301 } ,
{ 0x0700 , 0x070A , 0x0708 , 0x0403 , 0x0401 }
} ;
F_9 ( V_7 , 0x40 + 2 * V_21 , V_23 [ clock ] [ V_20 ] ) ;
}
static void F_10 ( struct V_4 * V_5 , struct V_18 * V_19 )
{
struct V_6 * V_7 = F_2 ( V_5 -> V_8 -> V_9 ) ;
int V_21 = V_19 -> V_22 + 2 * V_5 -> V_12 ;
T_1 V_24 ;
F_8 ( V_5 , V_19 , V_19 -> V_25 - V_26 ) ;
F_7 ( V_7 , 0x54 , & V_24 ) ;
V_24 &= ~ ( 3 << ( 2 * V_21 ) ) ;
F_11 ( V_7 , 0x54 , V_24 ) ;
}
static void F_12 ( struct V_4 * V_5 , struct V_18 * V_19 , unsigned int V_20 )
{
struct V_6 * V_7 = F_2 ( V_5 -> V_8 -> V_9 ) ;
int V_21 = V_19 -> V_22 + 2 * V_5 -> V_12 ;
const T_1 V_23 [ 2 ] [ 5 ] = {
{ 0x00 , 0x0A , 0x08 , 0x33 , 0x31 } ,
{ 0x70 , 0x7A , 0x78 , 0x43 , 0x41 }
} ;
F_11 ( V_7 , 0x40 + V_21 , V_23 [ clock ] [ V_20 ] ) ;
}
static void F_13 ( struct V_4 * V_5 , struct V_18 * V_19 )
{
struct V_6 * V_7 = F_2 ( V_5 -> V_8 -> V_9 ) ;
T_1 V_24 ;
F_12 ( V_5 , V_19 , V_19 -> V_25 - V_26 ) ;
F_7 ( V_7 , 0x44 + V_5 -> V_12 , & V_24 ) ;
V_24 &= ~ ( 7 << ( 4 * V_19 -> V_22 ) ) ;
F_11 ( V_7 , 0x44 + V_5 -> V_12 , V_24 ) ;
}
static void F_14 ( struct V_4 * V_5 , struct V_18 * V_19 )
{
unsigned int V_20 ;
struct V_6 * V_7 = F_2 ( V_5 -> V_8 -> V_9 ) ;
int V_21 = V_19 -> V_22 + 2 * V_5 -> V_12 ;
T_1 V_24 ;
if ( V_19 -> V_27 == V_28 )
V_20 = 1 ;
else
V_20 = 4 ;
F_8 ( V_5 , V_19 , V_20 ) ;
F_7 ( V_7 , 0x54 , & V_24 ) ;
V_24 &= ~ ( 3 << ( 2 * V_21 ) ) ;
if ( V_19 -> V_27 >= V_29 ) {
T_1 V_30 = ( V_19 -> V_27 - V_29 ) + 1 - clock ;
if ( V_30 == 0 )
V_30 = 1 ;
V_24 |= ( V_30 << ( 2 * V_21 ) ) ;
}
F_11 ( V_7 , 0x54 , V_24 ) ;
}
static void F_15 ( struct V_4 * V_5 , struct V_18 * V_19 )
{
unsigned int V_20 = V_19 -> V_25 - V_26 ;
struct V_6 * V_7 = F_2 ( V_5 -> V_8 -> V_9 ) ;
T_1 V_24 ;
if ( V_19 -> V_27 == V_28 )
V_20 = 1 ;
else
V_20 = 4 ;
F_12 ( V_5 , V_19 , V_20 ) ;
F_7 ( V_7 , 0x44 + V_5 -> V_12 , & V_24 ) ;
V_24 &= ~ ( 7 << ( 4 * V_19 -> V_22 ) ) ;
if ( V_19 -> V_27 >= V_29 ) {
T_1 V_30 = V_19 -> V_27 - V_29 + 1 - clock ;
if ( V_30 == 0 )
V_30 = 1 ;
V_24 |= ( V_30 << ( 4 * V_19 -> V_22 ) ) ;
}
F_11 ( V_7 , 0x44 + V_5 -> V_12 , V_24 ) ;
}
static int F_16 ( struct V_31 * V_32 )
{
struct V_33 * V_8 = V_32 -> V_5 -> V_8 ;
struct V_4 * V_34 = V_8 -> V_35 [ 1 ^ V_32 -> V_5 -> V_12 ] ;
int V_36 ;
V_36 = F_17 ( V_32 ) ;
if ( V_36 != 0 )
return V_36 ;
if ( V_34 && V_34 -> V_37 )
return V_38 ;
return 0 ;
}
static int F_18 ( struct V_6 * V_7 , const struct V_39 * V_40 )
{
static const struct V_41 V_42 = {
. V_43 = V_44 ,
. V_45 = V_46 ,
. V_47 = V_48 ,
. V_49 = V_50 ,
. V_51 = & V_52 ,
} ;
static const struct V_41 V_53 = {
. V_43 = V_44 ,
. V_45 = V_46 ,
. V_47 = V_48 ,
. V_49 = V_54 ,
. V_51 = & V_55 ,
} ;
static const struct V_41 V_56 = {
. V_43 = V_44 ,
. V_45 = V_46 ,
. V_47 = V_48 ,
. V_49 = V_57 ,
. V_51 = & V_55 ,
} ;
static const struct V_41 V_58 = {
. V_43 = V_44 ,
. V_45 = V_46 ,
. V_47 = V_48 ,
. V_49 = V_59 ,
. V_51 = & V_55 ,
} ;
const struct V_41 * V_60 [] = { NULL , NULL } ;
int V_36 ;
F_19 ( & V_7 -> V_9 , V_61 ) ;
V_36 = F_20 ( V_7 ) ;
if ( V_36 )
return V_36 ;
if ( V_40 -> V_62 == 0 ) {
V_60 [ 0 ] = & V_42 ;
F_11 ( V_7 , 0x54 , 0 ) ;
}
else if ( V_40 -> V_62 == 1 )
V_60 [ 0 ] = & V_53 ;
else if ( V_40 -> V_62 == 2 ) {
unsigned long V_63 = F_21 ( V_7 , 4 ) ;
T_1 V_64 ;
V_60 [ 0 ] = & V_56 ;
if ( F_22 ( V_63 ) & 0x10 )
V_60 [ 0 ] = & V_58 ;
F_7 ( V_7 , 0x49 , & V_64 ) ;
F_11 ( V_7 , 0x49 , V_64 & ~ 0x30 ) ;
F_7 ( V_7 , V_65 , & V_64 ) ;
if ( V_64 <= 0x80 )
F_11 ( V_7 , V_65 , 0x90 ) ;
F_7 ( V_7 , 0x4a , & V_64 ) ;
F_11 ( V_7 , 0x4a , ( V_64 & ~ 0x01 ) | 0x80 ) ;
}
F_23 ( V_60 [ 0 ] == NULL ) ;
return F_24 ( V_7 , V_60 , & V_66 , NULL , 0 ) ;
}
static int T_3 F_25 ( void )
{
return F_26 ( & V_67 ) ;
}
static void T_4 F_27 ( void )
{
F_28 ( & V_67 ) ;
}
