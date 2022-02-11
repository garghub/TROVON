static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
static const struct V_4 V_5 [] = {
{ 0x40 , 1 , 0x01 , 0x01 } ,
{ 0x40 , 1 , 0x10 , 0x10 }
} ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_7 -> V_10 -> V_11 ) ;
if ( V_7 -> V_12 && ! F_3 ( V_9 , & V_5 [ V_7 -> V_12 ] ) )
return - V_13 ;
return F_4 ( V_2 , V_3 ) ;
}
static void F_5 ( struct V_6 * V_7 , struct V_14 * V_15 , int V_16 )
{
struct V_8 * V_9 = F_2 ( V_7 -> V_10 -> V_11 ) ;
static T_1 V_17 [ 5 ] = {
0x50D , 0x407 , 0x304 , 0x242 , 0x240
} ;
T_1 V_18 ;
int V_19 = 0x44 + ( 8 * V_7 -> V_12 ) + ( 4 * V_15 -> V_20 ) ;
F_6 ( V_9 , V_19 , V_17 [ V_16 ] ) ;
F_7 ( V_9 , V_19 , & V_18 ) ;
}
static void F_8 ( struct V_6 * V_7 , struct V_14 * V_15 )
{
F_5 ( V_7 , V_15 , V_15 -> V_21 - V_22 ) ;
}
static void F_9 ( struct V_6 * V_7 , struct V_14 * V_15 )
{
struct V_8 * V_9 = F_2 ( V_7 -> V_10 -> V_11 ) ;
static T_1 V_23 [ 3 ] = {
0x707 , 0x201 , 0x200
} ;
T_1 V_18 ;
int V_19 = 0x44 + ( 8 * V_7 -> V_12 ) + ( 4 * V_15 -> V_20 ) ;
int V_24 = V_15 -> V_25 - V_26 ;
F_6 ( V_9 , V_19 , V_23 [ V_24 ] ) ;
F_7 ( V_9 , V_19 , & V_18 ) ;
}
static void F_10 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_7 -> V_10 -> V_11 ) ;
T_1 V_27 ;
F_7 ( V_9 , 0x7E , & V_27 ) ;
F_6 ( V_9 , 0x7E , V_27 | 4 ) ;
F_6 ( V_9 , 0x7E , V_27 & ~ 4 ) ;
}
static void F_11 ( struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_7 ;
F_12 ( 100 ) ;
F_10 ( V_7 ) ;
F_12 ( 100 ) ;
F_9 ( V_7 , V_29 -> V_11 ) ;
F_13 ( V_29 ) ;
}
static void F_14 ( struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_7 ;
F_15 ( V_29 ) ;
F_10 ( V_7 ) ;
F_12 ( 100 ) ;
F_8 ( V_7 , V_29 -> V_11 ) ;
}
static int F_16 ( struct V_28 * V_29 )
{
struct V_30 * V_10 = V_29 -> V_7 -> V_10 ;
struct V_6 * V_31 = V_10 -> V_32 [ 1 ^ V_29 -> V_7 -> V_12 ] ;
int V_33 ;
V_33 = F_17 ( V_29 ) ;
if ( V_33 != 0 )
return V_33 ;
if ( V_31 && V_31 -> V_34 )
return V_35 ;
return 0 ;
}
static bool F_18 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_7 -> V_10 -> V_11 ) ;
T_2 V_27 , V_36 = V_7 -> V_12 ? V_37 : V_38 ;
F_19 ( V_9 , 0x40 , & V_27 ) ;
return V_27 & V_36 ;
}
static int F_20 ( struct V_8 * V_9 )
{
struct V_8 * V_39 ;
V_39 = F_21 ( V_9 -> V_40 ,
F_22 ( F_23 ( V_9 -> V_41 ) , 0 ) ) ;
if ( ! V_39 )
return - 1 ;
if ( V_39 -> V_42 != V_43 ||
V_39 -> V_44 != V_45 ||
V_39 -> V_46 >> 8 != V_47 ) {
F_24 ( V_39 ) ;
return - 1 ;
}
F_24 ( V_39 ) ;
return V_39 -> V_48 ;
}
static int F_25 ( struct V_8 * V_11 , const struct V_49 * V_50 )
{
static const struct V_51 V_52 = {
. V_53 = V_54 ,
. V_55 = V_56 ,
. V_57 = V_58 ,
. V_59 = & V_60
} ;
static const struct V_51 V_61 = {
. V_53 = V_54 ,
. V_55 = V_56 ,
. V_59 = & V_60
} ;
const struct V_51 * V_62 [] = { & V_61 ,
NULL } ;
T_2 V_27 ;
int V_63 ;
int V_33 ;
V_33 = F_26 ( V_11 ) ;
if ( V_33 )
return V_33 ;
V_63 = F_20 ( V_11 ) ;
if ( V_63 == - 1 )
F_27 ( & V_11 -> V_11 ,
L_1 ) ;
else if ( V_63 <= 5 )
F_27 ( & V_11 -> V_11 ,
L_2 ) ;
else
V_62 [ 0 ] = & V_52 ;
F_19 ( V_11 , 0x40 , & V_27 ) ;
V_27 |= V_64 | V_65 | V_66 ;
F_28 ( V_11 , 0x40 , V_27 ) ;
return F_29 ( V_11 , V_62 , & V_67 , NULL , 0 ) ;
}
static int T_3 F_30 ( void )
{
return F_31 ( & V_68 ) ;
}
static void T_4 F_32 ( void )
{
F_33 ( & V_68 ) ;
}
