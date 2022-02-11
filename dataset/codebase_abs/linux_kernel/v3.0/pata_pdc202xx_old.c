static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
T_1 V_7 ;
F_3 ( V_4 , 0x50 , & V_7 ) ;
if ( V_7 & ( 1 << ( 10 + V_2 -> V_8 ) ) )
return V_9 ;
return V_10 ;
}
static void F_4 ( struct V_1 * V_2 ,
const struct V_11 * V_12 )
{
F_5 ( L_1 , V_2 -> V_13 , V_12 -> V_14 ) ;
F_6 ( V_12 -> V_14 , V_2 -> V_15 . V_16 ) ;
F_7 ( 400 ) ;
}
static bool F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
unsigned long V_17 = F_9 ( V_4 , 4 ) ;
T_2 V_18 = F_10 ( V_17 + 0x1d ) ;
if ( V_2 -> V_8 ) {
return V_18 & 0x40 ;
} else {
return V_18 & 0x04 ;
}
}
static void F_11 ( struct V_1 * V_2 , struct V_19 * V_20 , int V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
int V_22 = 0x60 + 8 * V_2 -> V_8 + 4 * V_20 -> V_23 ;
static T_1 V_24 [ 5 ] = {
0x0913 , 0x050C , 0x0308 , 0x0206 , 0x0104
} ;
T_2 V_25 , V_26 ;
F_12 ( V_4 , V_22 , & V_25 ) ;
F_12 ( V_4 , V_22 + 1 , & V_26 ) ;
V_25 &= ~ 0x3F ;
V_26 &= ~ 0x1F ;
V_25 |= ( V_24 [ V_21 ] >> 8 ) ;
V_26 |= ( V_24 [ V_21 ] & 0xFF ) ;
if ( F_13 ( V_20 ) )
V_25 |= 0x20 ;
if ( V_20 -> V_27 == V_28 )
V_25 |= 0x10 ;
F_14 ( V_4 , V_22 , V_25 ) ;
F_14 ( V_4 , V_22 + 1 , V_26 ) ;
}
static void F_15 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
F_11 ( V_2 , V_20 , V_20 -> V_29 - V_30 ) ;
}
static void F_16 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
int V_22 = 0x60 + 8 * V_2 -> V_8 + 4 * V_20 -> V_23 ;
static T_2 V_31 [ 6 ] [ 2 ] = {
{ 0x60 , 0x03 } ,
{ 0x40 , 0x02 } ,
{ 0x20 , 0x01 } ,
{ 0x40 , 0x02 } ,
{ 0x20 , 0x01 } ,
{ 0x20 , 0x01 }
} ;
static T_2 V_32 [ 3 ] [ 2 ] = {
{ 0xe0 , 0x0f } ,
{ 0x60 , 0x04 } ,
{ 0x60 , 0x03 } ,
} ;
T_2 V_26 , V_33 ;
F_12 ( V_4 , V_22 + 1 , & V_26 ) ;
F_12 ( V_4 , V_22 + 2 , & V_33 ) ;
V_26 &= ~ 0xE0 ;
V_33 &= ~ 0x0F ;
if ( V_20 -> V_34 >= V_35 ) {
int V_36 = V_20 -> V_34 - V_35 ;
V_26 |= V_31 [ V_36 ] [ 0 ] ;
V_33 |= V_31 [ V_36 ] [ 1 ] ;
} else {
int V_36 = V_20 -> V_34 - V_37 ;
V_26 |= V_32 [ V_36 ] [ 0 ] ;
V_33 |= V_32 [ V_36 ] [ 1 ] ;
}
F_14 ( V_4 , V_22 + 1 , V_26 ) ;
F_14 ( V_4 , V_22 + 2 , V_33 ) ;
}
static void F_17 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_2 ;
struct V_19 * V_20 = V_39 -> V_6 ;
struct V_11 * V_12 = & V_39 -> V_12 ;
int V_40 = V_2 -> V_8 ? 0x08 : 0x02 ;
void T_3 * V_17 = V_2 -> V_5 -> V_41 [ 0 ] -> V_15 . V_42 ;
void T_3 * clock = V_17 + 0x11 ;
void T_3 * V_43 = V_17 + 0x20 + ( 4 * V_2 -> V_8 ) ;
T_4 V_44 ;
if ( V_20 -> V_34 > V_45 )
F_6 ( F_18 ( clock ) | V_40 , clock ) ;
else
F_6 ( F_18 ( clock ) & ~ V_40 , clock ) ;
F_16 ( V_2 , V_39 -> V_6 ) ;
if ( ( V_12 -> V_46 & V_47 ) || V_12 -> V_48 == V_49 ) {
V_44 = V_39 -> V_50 / 2 ;
if ( V_12 -> V_46 & V_51 )
V_44 |= 0x06000000 ;
else
V_44 |= 0x05000000 ;
F_19 ( V_44 , V_43 ) ;
}
F_20 ( V_39 ) ;
}
static void F_21 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_2 ;
struct V_19 * V_20 = V_39 -> V_6 ;
struct V_11 * V_12 = & V_39 -> V_12 ;
int V_40 = V_2 -> V_8 ? 0x08 : 0x02 ;
void T_3 * V_17 = V_2 -> V_5 -> V_41 [ 0 ] -> V_15 . V_42 ;
void T_3 * clock = V_17 + 0x11 ;
void T_3 * V_43 = V_17 + 0x20 + ( 4 * V_2 -> V_8 ) ;
if ( V_12 -> V_48 == V_49 || ( V_12 -> V_46 & V_47 ) ) {
F_19 ( 0 , V_43 ) ;
F_6 ( F_18 ( clock ) & ~ V_40 , clock ) ;
}
if ( V_20 -> V_34 > V_45 )
F_6 ( F_18 ( clock ) & ~ V_40 , clock ) ;
F_22 ( V_39 ) ;
F_15 ( V_2 , V_20 ) ;
}
static void F_23 ( struct V_19 * V_20 )
{
V_20 -> V_52 = 256 ;
}
static int F_24 ( struct V_1 * V_2 )
{
void T_3 * V_53 = V_2 -> V_15 . V_42 ;
if ( V_53 ) {
T_2 V_54 = F_18 ( V_53 + 0x1f ) ;
F_6 ( V_54 | 0x01 , V_53 + 0x1f ) ;
}
return F_25 ( V_2 ) ;
}
static int F_26 ( struct V_38 * V_39 )
{
return 1 ;
}
static int F_27 ( struct V_3 * V_6 , const struct V_55 * V_56 )
{
static const struct V_57 V_58 [ 3 ] = {
{
. V_46 = V_59 ,
. V_60 = V_61 ,
. V_62 = V_63 ,
. V_64 = V_65 ,
. V_66 = & V_67
} ,
{
. V_46 = V_59 ,
. V_60 = V_61 ,
. V_62 = V_63 ,
. V_64 = V_68 ,
. V_66 = & V_69
} ,
{
. V_46 = V_59 ,
. V_60 = V_61 ,
. V_62 = V_63 ,
. V_64 = V_70 ,
. V_66 = & V_69
}
} ;
const struct V_57 * V_71 [] = { & V_58 [ V_56 -> V_72 ] , NULL } ;
if ( V_6 -> V_73 == V_74 ) {
struct V_3 * V_75 = V_6 -> V_76 -> V_77 ;
if ( V_75 && V_75 -> V_78 == V_79 ) {
if ( V_75 -> V_73 == V_80 )
return - V_81 ;
if ( V_75 -> V_73 == V_82 )
return - V_81 ;
}
}
return F_28 ( V_6 , V_71 , & V_83 , NULL , 0 ) ;
}
static int T_5 F_29 ( void )
{
return F_30 ( & V_84 ) ;
}
static void T_6 F_31 ( void )
{
F_32 ( & V_84 ) ;
}
