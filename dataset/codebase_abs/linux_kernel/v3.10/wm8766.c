static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
if ( V_3 < V_5 )
V_2 -> V_6 [ V_3 ] = V_4 ;
V_2 -> V_7 . V_8 ( V_2 , V_3 , V_4 ) ;
}
void F_2 ( struct V_1 * V_2 )
{
int V_9 ;
static const T_1 V_10 [] = {
0x000 , 0x100 ,
0x120 , 0x000 ,
0x000 , 0x100 , 0x000 , 0x100 , 0x000 ,
0x000 , 0x080 ,
} ;
memcpy ( V_2 -> V_11 , V_12 , sizeof( V_2 -> V_11 ) ) ;
F_1 ( V_2 , V_13 , 0x00 ) ;
F_3 ( 10 ) ;
for ( V_9 = 0 ; V_9 < F_4 ( V_10 ) ; V_9 ++ )
F_1 ( V_2 , V_9 , V_10 [ V_9 ] ) ;
}
void F_5 ( struct V_1 * V_2 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_5 ; V_9 ++ )
F_1 ( V_2 , V_9 , V_2 -> V_6 [ V_9 ] ) ;
}
void F_6 ( struct V_1 * V_2 , T_1 V_14 )
{
T_1 V_15 = V_2 -> V_6 [ V_16 ] & ~ V_17 ;
V_14 &= V_17 ;
F_1 ( V_2 , V_16 , V_15 | V_14 ) ;
}
void F_7 ( struct V_1 * V_2 , T_1 V_18 )
{
T_1 V_15 = V_2 -> V_6 [ V_19 ] & ~ V_20 ;
V_18 &= V_20 ;
F_1 ( V_2 , V_19 , V_15 | V_18 ) ;
}
void F_8 ( struct V_1 * V_2 , T_1 V_21 )
{
T_1 V_15 = V_2 -> V_6 [ V_19 ] & ~ V_22 ;
V_21 &= V_22 ;
F_1 ( V_2 , V_19 , V_15 | V_21 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
T_1 V_15 = V_2 -> V_6 [ V_23 ] ;
F_1 ( V_2 , V_23 , V_15 | V_24 ) ;
}
static int F_10 ( struct V_25 * V_26 ,
struct V_27 * V_28 )
{
struct V_1 * V_2 = F_11 ( V_26 ) ;
int V_29 = V_26 -> V_30 ;
V_28 -> type = V_31 ;
V_28 -> V_32 = ( V_2 -> V_11 [ V_29 ] . V_33 & V_34 ) ? 2 : 1 ;
V_28 -> V_35 . integer . V_36 = V_2 -> V_11 [ V_29 ] . V_36 ;
V_28 -> V_35 . integer . V_37 = V_2 -> V_11 [ V_29 ] . V_37 ;
return 0 ;
}
static int F_12 ( struct V_25 * V_26 ,
struct V_27 * V_28 )
{
struct V_1 * V_2 = F_11 ( V_26 ) ;
int V_29 = V_26 -> V_30 ;
return F_13 ( V_28 , 1 , V_2 -> V_11 [ V_29 ] . V_37 ,
V_2 -> V_11 [ V_29 ] . V_38 ) ;
}
static int F_14 ( struct V_25 * V_26 ,
struct V_39 * V_40 )
{
struct V_1 * V_2 = F_11 ( V_26 ) ;
int V_29 = V_26 -> V_30 ;
T_1 V_41 , V_42 ;
if ( V_2 -> V_11 [ V_29 ] . V_43 )
V_2 -> V_11 [ V_29 ] . V_43 ( V_2 , & V_41 , & V_42 ) ;
else {
V_41 = V_2 -> V_6 [ V_2 -> V_11 [ V_29 ] . V_44 ] & V_2 -> V_11 [ V_29 ] . V_45 ;
V_41 >>= F_15 ( V_2 -> V_11 [ V_29 ] . V_45 ) ;
if ( V_2 -> V_11 [ V_29 ] . V_33 & V_34 ) {
V_42 = V_2 -> V_6 [ V_2 -> V_11 [ V_29 ] . V_46 ] & V_2 -> V_11 [ V_29 ] . V_47 ;
V_42 >>= F_15 ( V_2 -> V_11 [ V_29 ] . V_47 ) ;
if ( V_2 -> V_11 [ V_29 ] . V_33 & V_48 )
V_42 &= ~ V_24 ;
}
}
if ( V_2 -> V_11 [ V_29 ] . V_33 & V_49 ) {
V_41 = V_2 -> V_11 [ V_29 ] . V_37 - ( V_41 - V_2 -> V_11 [ V_29 ] . V_36 ) ;
V_42 = V_2 -> V_11 [ V_29 ] . V_37 - ( V_42 - V_2 -> V_11 [ V_29 ] . V_36 ) ;
}
V_40 -> V_35 . integer . V_35 [ 0 ] = V_41 ;
if ( V_2 -> V_11 [ V_29 ] . V_33 & V_34 )
V_40 -> V_35 . integer . V_35 [ 1 ] = V_42 ;
return 0 ;
}
static int F_16 ( struct V_25 * V_26 ,
struct V_39 * V_40 )
{
struct V_1 * V_2 = F_11 ( V_26 ) ;
int V_29 = V_26 -> V_30 ;
T_1 V_15 , V_50 , V_51 ;
V_50 = V_40 -> V_35 . integer . V_35 [ 0 ] ;
V_51 = V_40 -> V_35 . integer . V_35 [ 1 ] ;
if ( V_2 -> V_11 [ V_29 ] . V_33 & V_49 ) {
V_50 = V_2 -> V_11 [ V_29 ] . V_37 - ( V_50 - V_2 -> V_11 [ V_29 ] . V_36 ) ;
V_51 = V_2 -> V_11 [ V_29 ] . V_37 - ( V_51 - V_2 -> V_11 [ V_29 ] . V_36 ) ;
}
if ( V_2 -> V_11 [ V_29 ] . V_52 )
V_2 -> V_11 [ V_29 ] . V_52 ( V_2 , V_50 , V_51 ) ;
else {
V_15 = V_2 -> V_6 [ V_2 -> V_11 [ V_29 ] . V_44 ] & ~ V_2 -> V_11 [ V_29 ] . V_45 ;
V_15 |= V_50 << F_15 ( V_2 -> V_11 [ V_29 ] . V_45 ) ;
if ( V_2 -> V_11 [ V_29 ] . V_33 & V_34 &&
V_2 -> V_11 [ V_29 ] . V_44 == V_2 -> V_11 [ V_29 ] . V_46 ) {
V_15 &= ~ V_2 -> V_11 [ V_29 ] . V_47 ;
V_15 |= V_51 << F_15 ( V_2 -> V_11 [ V_29 ] . V_47 ) ;
}
F_1 ( V_2 , V_2 -> V_11 [ V_29 ] . V_44 , V_15 ) ;
if ( V_2 -> V_11 [ V_29 ] . V_33 & V_34 &&
V_2 -> V_11 [ V_29 ] . V_44 != V_2 -> V_11 [ V_29 ] . V_46 ) {
V_15 = V_2 -> V_6 [ V_2 -> V_11 [ V_29 ] . V_46 ] & ~ V_2 -> V_11 [ V_29 ] . V_47 ;
V_15 |= V_51 << F_15 ( V_2 -> V_11 [ V_29 ] . V_47 ) ;
if ( V_2 -> V_11 [ V_29 ] . V_33 & V_48 )
V_15 |= V_24 ;
F_1 ( V_2 , V_2 -> V_11 [ V_29 ] . V_46 , V_15 ) ;
}
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , int V_53 )
{
struct V_54 V_55 ;
struct V_25 * V_11 ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_56 = V_57 ;
V_55 . V_30 = V_53 ;
V_55 . V_58 = V_2 -> V_11 [ V_53 ] . V_58 ;
V_55 . V_59 = V_60 ;
if ( V_2 -> V_11 [ V_53 ] . V_33 & V_61 ||
V_2 -> V_11 [ V_53 ] . V_33 & V_62 )
V_55 . V_59 |= V_63 ;
V_55 . V_64 . V_65 = NULL ;
V_55 . V_43 = F_14 ;
V_55 . V_66 = F_16 ;
switch ( V_2 -> V_11 [ V_53 ] . type ) {
case V_31 :
V_55 . V_67 = F_10 ;
V_55 . V_59 |= V_68 ;
V_55 . V_64 . V_65 = V_2 -> V_11 [ V_53 ] . V_64 ;
break;
case V_69 :
V_2 -> V_11 [ V_53 ] . V_37 = 1 ;
if ( V_2 -> V_11 [ V_53 ] . V_33 & V_34 )
V_55 . V_67 = V_70 ;
else
V_55 . V_67 = V_71 ;
break;
case V_72 :
V_55 . V_67 = F_12 ;
break;
default:
return - V_73 ;
}
V_11 = F_18 ( & V_55 , V_2 ) ;
if ( ! V_11 )
return - V_74 ;
V_2 -> V_11 [ V_53 ] . V_75 = V_11 ;
return F_19 ( V_2 -> V_76 , V_11 ) ;
}
int F_20 ( struct V_1 * V_2 )
{
int V_77 , V_9 ;
for ( V_9 = 0 ; V_9 < V_78 ; V_9 ++ )
if ( V_2 -> V_11 [ V_9 ] . V_58 ) {
V_77 = F_17 ( V_2 , V_9 ) ;
if ( V_77 < 0 )
return V_77 ;
}
return 0 ;
}
