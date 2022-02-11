static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_5 -> V_8 -> V_9 ) ;
static const struct V_10 V_11 = {
0x40 , 1 , 0x08 , 0x00
} ;
if ( V_5 -> V_12 && ! F_3 ( V_7 , & V_11 ) )
return - V_13 ;
return F_4 ( V_2 , V_3 ) ;
}
static void F_5 ( struct V_4 * V_5 )
{
void T_1 * V_14 = V_5 -> V_15 . V_16 ;
F_6 ( V_14 + 1 ) ;
F_6 ( V_14 + 1 ) ;
F_7 ( 3 , V_14 + 2 ) ;
}
static void F_8 ( struct V_4 * V_5 )
{
void T_1 * V_14 = V_5 -> V_15 . V_16 ;
F_7 ( 0x83 , V_14 + 2 ) ;
}
static void F_9 ( struct V_4 * V_5 , struct V_17 * V_18 , T_2 V_19 )
{
struct V_17 * V_20 = F_10 ( V_18 ) ;
int V_21 = V_18 -> V_22 - V_23 ;
int V_24 = V_18 -> V_25 - V_26 ;
void T_1 * V_14 = V_5 -> V_15 . V_16 ;
T_2 V_27 ;
static const T_2 V_28 [ 2 ] [ 5 ] = {
{ 0x30 , 0x20 , 0x20 , 0x10 , 0x10 } ,
{ 0x20 , 0x20 , 0x10 , 0x10 , 0x10 }
} ;
static const T_2 V_29 [ 2 ] [ 5 ] = {
{ 0x59 , 0x46 , 0x30 , 0x20 , 0x20 } ,
{ 0x46 , 0x32 , 0x20 , 0x20 , 0x10 }
} ;
static const T_2 V_30 [ 2 ] [ 3 ] = {
{ 0x76 , 0x20 , 0x20 } ,
{ 0x54 , 0x20 , 0x10 }
} ;
F_5 ( V_5 ) ;
if ( V_19 >= V_26 )
V_27 = 0 ;
else
V_27 = V_28 [ V_31 ] [ V_21 ] ;
if ( V_20 ) {
T_2 V_32 ;
if ( V_20 -> V_25 )
V_32 = 0 ;
else
V_32 = V_28 [ V_31 ] [ V_20 -> V_22 - V_23 ] ;
if ( V_32 > V_27 )
V_27 = V_32 ;
}
F_7 ( V_18 -> V_33 , V_14 + V_34 ) ;
if ( V_19 < V_26 ) {
F_7 ( V_29 [ V_31 ] [ V_21 ] , V_14 + V_35 ) ;
F_7 ( V_29 [ V_31 ] [ V_21 ] , V_14 + V_36 ) ;
} else if ( V_19 < V_37 ) {
F_7 ( V_30 [ V_31 ] [ V_24 ] , V_14 + V_35 ) ;
F_7 ( V_30 [ V_31 ] [ V_24 ] , V_14 + V_36 ) ;
}
F_7 ( V_27 | V_18 -> V_33 , V_14 + V_34 ) ;
F_7 ( 0x85 , V_14 + V_38 ) ;
F_8 ( V_5 ) ;
}
static void F_11 ( struct V_4 * V_5 , struct V_17 * V_18 , T_2 V_19 )
{
struct V_6 * V_7 = F_2 ( V_5 -> V_8 -> V_9 ) ;
T_2 V_39 ;
T_2 V_40 ;
int V_41 = 2 * V_18 -> V_33 ;
int V_42 = 2 * V_5 -> V_12 + V_18 -> V_33 ;
int V_43 = V_19 - V_37 ;
F_12 ( V_7 , 0x44 , & V_39 ) ;
if ( V_19 <= V_37 ) {
V_39 &= ~ ( 1 << V_42 ) ;
F_9 ( V_5 , V_18 , V_18 -> V_25 ) ;
} else {
V_39 |= ( 1 << V_42 ) ;
if ( V_5 -> V_12 ) {
F_12 ( V_7 , 0x45 , & V_40 ) ;
V_40 &= ~ ( 0x03 << V_41 ) ;
V_40 |= ( V_43 << V_41 ) ;
F_13 ( V_7 , 0x45 , V_40 ) ;
} else {
V_39 &= ~ ( 0x30 << V_41 ) ;
V_39 |= ( V_43 << V_41 ) ;
}
}
F_13 ( V_7 , 0x44 , V_39 ) ;
}
static void F_14 ( struct V_4 * V_5 , struct V_17 * V_18 )
{
F_9 ( V_5 , V_18 , V_18 -> V_22 ) ;
}
static void F_15 ( struct V_4 * V_5 , struct V_17 * V_18 )
{
F_9 ( V_5 , V_18 , V_18 -> V_25 ) ;
}
static void F_16 ( struct V_4 * V_5 , struct V_17 * V_18 )
{
F_11 ( V_5 , V_18 , V_18 -> V_22 ) ;
}
static void F_17 ( struct V_4 * V_5 , struct V_17 * V_18 )
{
F_11 ( V_5 , V_18 , V_18 -> V_25 ) ;
}
static T_2 F_18 ( struct V_17 * V_18 )
{
static const T_2 V_44 [ 5 ] = {
0 , 0 , 0 , 1 , 2
} ;
if ( ! F_19 ( V_18 ) )
return 0 ;
if ( V_18 -> V_25 )
return V_18 -> V_25 - V_26 ;
return V_44 [ V_18 -> V_22 - V_23 ] ;
}
static int F_20 ( struct V_1 * V_2 , struct V_17 * * V_45 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_2 V_46 ;
int V_47 = 4 * V_5 -> V_12 ;
struct V_6 * V_7 = F_2 ( V_5 -> V_8 -> V_9 ) ;
int V_48 = F_21 ( V_2 , V_45 ) ;
if ( V_48 == 0 ) {
F_12 ( V_7 , 0x43 , & V_46 ) ;
V_46 &= ( 0x0F << V_47 ) ;
V_46 |= ( F_18 ( & V_2 -> V_49 [ 0 ] ) +
( F_18 ( & V_2 -> V_49 [ 0 ] ) << 2 ) ) << V_47 ;
F_13 ( V_7 , 0x43 , V_46 ) ;
}
return V_48 ;
}
static int F_22 ( struct V_6 * V_7 )
{
T_2 V_46 ;
int V_50 = 0 ;
int V_51 = 0x22 ;
struct V_6 * V_52 ;
V_52 = F_23 ( 0x1045 , 0xC701 , NULL ) ;
if ( V_52 == NULL )
return 0 ;
F_12 ( V_52 , 0x08 , & V_46 ) ;
if ( V_46 < 0x10 )
goto V_53;
F_12 ( V_52 , 0x5F , & V_46 ) ;
V_51 |= ( V_46 << 8 ) ;
F_24 ( 0x10 , V_51 ) ;
if ( ( F_25 ( V_51 + 2 ) & 1 ) == 0 )
goto V_54;
F_12 ( V_7 , 0x42 , & V_46 ) ;
if ( ( V_46 & 0x36 ) != 0x36 )
goto V_54;
F_12 ( V_52 , 0x52 , & V_46 ) ;
if ( V_46 & 0x80 )
V_50 = 1 ;
V_54:
F_26 ( V_55 L_1 ) ;
V_53:
F_27 ( V_52 ) ;
return V_50 ;
}
static int F_28 ( struct V_6 * V_9 , const struct V_56 * V_57 )
{
static const struct V_58 V_59 = {
. V_60 = V_61 ,
. V_62 = V_63 ,
. V_64 = V_65 ,
. V_66 = & V_67
} ;
static const struct V_58 V_68 = {
. V_60 = V_61 ,
. V_62 = V_63 ,
. V_64 = V_65 ,
. V_69 = V_70 ,
. V_66 = & V_71
} ;
const struct V_58 * V_72 [] = { & V_59 , NULL } ;
int V_48 ;
F_29 ( & V_9 -> V_9 , V_73 ) ;
V_48 = F_30 ( V_9 ) ;
if ( V_48 )
return V_48 ;
F_31 ( 0x1F1 ) ;
F_31 ( 0x1F1 ) ;
V_31 = F_25 ( 0x1F5 ) & 1 ;
if ( F_22 ( V_9 ) )
V_72 [ 0 ] = & V_68 ;
return F_32 ( V_9 , V_72 , & V_74 , NULL , 0 ) ;
}
