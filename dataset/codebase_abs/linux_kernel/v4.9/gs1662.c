static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
int V_5 ;
T_1 V_6 = ( 0x8000 | ( 0x0FFF & V_3 ) ) ;
T_1 V_7 = 0 ;
struct V_8 V_9 ;
struct V_10 V_11 [] = {
{
. V_12 = & V_6 ,
. V_13 = 2 ,
. V_14 = 1 ,
} , {
. V_15 = & V_7 ,
. V_13 = 2 ,
. V_14 = 1 ,
} ,
} ;
F_2 ( & V_9 ) ;
F_3 ( & V_11 [ 0 ] , & V_9 ) ;
F_3 ( & V_11 [ 1 ] , & V_9 ) ;
V_5 = F_4 ( V_2 , & V_9 ) ;
* V_4 = V_7 ;
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
T_1 V_6 = V_3 ;
T_1 V_7 = V_4 ;
struct V_8 V_9 ;
struct V_10 V_11 [] = {
{
. V_12 = & V_6 ,
. V_13 = 2 ,
. V_14 = 1 ,
} , {
. V_12 = & V_7 ,
. V_13 = 2 ,
. V_14 = 1 ,
} ,
} ;
F_2 ( & V_9 ) ;
F_3 ( & V_11 [ 0 ] , & V_9 ) ;
F_3 ( & V_11 [ 1 ] , & V_9 ) ;
V_5 = F_4 ( V_2 , & V_9 ) ;
return V_5 ;
}
static int F_6 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = F_7 ( V_17 ) ;
T_1 V_20 ;
int V_5 ;
V_5 = F_1 ( V_2 , V_19 -> V_19 & 0xFFFF , & V_20 ) ;
V_19 -> V_20 = V_20 ;
V_19 -> V_21 = 2 ;
return V_5 ;
}
static int F_8 ( struct V_16 * V_17 ,
const struct V_18 * V_19 )
{
struct V_1 * V_2 = F_7 ( V_17 ) ;
return F_5 ( V_2 , V_19 -> V_19 & 0xFFFF , V_19 -> V_20 & 0xFFFF ) ;
}
static int F_9 ( T_1 V_22 , struct V_23 * V_24 )
{
int V_25 = ( V_22 & V_26 ) >> 5 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < F_10 ( V_28 ) ; V_27 ++ ) {
if ( V_28 [ V_27 ] . V_29 == V_25 ) {
* V_24 = V_28 [ V_27 ] . V_30 ;
return 0 ;
}
}
return - V_31 ;
}
static T_1 F_11 ( struct V_23 * V_24 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < F_10 ( V_28 ) ; V_27 ++ ) {
if ( F_12 ( V_24 , & V_28 [ V_27 ] . V_30 , 0 ,
false ) )
return V_28 [ V_27 ] . V_29 | V_32 ;
}
return 0x0 ;
}
static inline struct V_33 * F_13 ( struct V_16 * V_17 )
{
return F_14 ( V_17 , struct V_33 , V_17 ) ;
}
static int F_15 ( struct V_16 * V_17 ,
struct V_23 * V_24 )
{
struct V_33 * V_33 = F_13 ( V_17 ) ;
int V_29 ;
V_29 = F_11 ( V_24 ) ;
if ( V_29 == 0x0 )
return - V_34 ;
V_33 -> V_35 = * V_24 ;
return 0 ;
}
static int F_16 ( struct V_16 * V_17 ,
struct V_23 * V_24 )
{
struct V_33 * V_33 = F_13 ( V_17 ) ;
* V_24 = V_33 -> V_35 ;
return 0 ;
}
static int F_17 ( struct V_16 * V_17 ,
struct V_23 * V_24 )
{
struct V_33 * V_33 = F_13 ( V_17 ) ;
struct V_23 V_36 ;
T_1 V_29 , V_27 ;
int V_5 ;
if ( V_33 -> V_37 )
return - V_38 ;
for ( V_27 = 0 ; V_27 < 4 ; V_27 ++ ) {
F_1 ( V_33 -> V_39 , V_40 + V_27 , & V_29 ) ;
if ( V_29 )
break;
}
if ( V_27 >= 4 )
return - V_41 ;
F_1 ( V_33 -> V_39 , V_42 , & V_29 ) ;
if ( ! ( V_29 & V_43 ) || ! ( V_29 & V_44 ) )
return - V_45 ;
if ( ! ( V_29 & V_46 ) )
return - V_31 ;
V_5 = F_9 ( V_29 , & V_36 ) ;
if ( V_5 < 0 )
return V_5 ;
* V_24 = V_36 ;
return 0 ;
}
static int F_18 ( struct V_16 * V_17 ,
struct V_47 * V_24 )
{
if ( V_24 -> V_48 >= F_10 ( V_49 ) )
return - V_34 ;
if ( V_24 -> V_50 != 0 )
return - V_34 ;
V_24 -> V_24 = V_49 [ V_24 -> V_48 ] ;
return 0 ;
}
static int F_19 ( struct V_16 * V_17 , int V_51 )
{
struct V_33 * V_33 = F_13 ( V_17 ) ;
int V_29 ;
if ( V_33 -> V_37 == V_51 )
return 0 ;
V_33 -> V_37 = V_51 ;
if ( V_51 ) {
V_29 = F_11 ( & V_33 -> V_35 ) ;
return F_5 ( V_33 -> V_39 , V_52 , V_29 ) ;
}
return F_5 ( V_33 -> V_39 , V_52 , 0x0 ) ;
}
static int F_20 ( struct V_16 * V_17 , T_2 * V_22 )
{
struct V_33 * V_33 = F_13 ( V_17 ) ;
T_1 V_29 , V_27 ;
int V_5 ;
for ( V_27 = 0 ; V_27 < 4 ; V_27 ++ ) {
V_5 = F_1 ( V_33 -> V_39 ,
V_40 + V_27 , & V_29 ) ;
if ( V_29 )
break;
if ( V_5 ) {
* V_22 = V_53 ;
return V_5 ;
}
}
if ( V_27 >= 4 )
* V_22 |= V_54 ;
V_5 = F_1 ( V_33 -> V_39 , V_42 , & V_29 ) ;
if ( ! ( V_29 & V_43 ) )
* V_22 |= V_55 ;
if ( ! ( V_29 & V_44 ) )
* V_22 |= V_56 ;
if ( ! ( V_29 & V_46 ) )
* V_22 |= V_57 ;
return V_5 ;
}
static int F_21 ( struct V_16 * V_17 ,
struct V_58 * V_59 )
{
if ( V_59 -> V_50 != 0 )
return - V_34 ;
* V_59 = V_60 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_33 * V_33 ;
struct V_16 * V_17 ;
V_33 = F_23 ( & V_2 -> V_61 , sizeof( struct V_33 ) , V_62 ) ;
if ( ! V_33 )
return - V_63 ;
V_33 -> V_39 = V_2 ;
V_17 = & V_33 -> V_17 ;
V_2 -> V_64 = V_65 ;
V_2 -> V_66 = - 1 ;
V_2 -> V_67 = 10000000 ;
V_2 -> V_68 = 16 ;
V_5 = F_24 ( V_2 ) ;
F_25 ( V_17 , V_2 , & V_69 ) ;
V_33 -> V_35 = V_28 [ 0 ] . V_30 ;
V_33 -> V_37 = 0 ;
F_5 ( V_2 , 0x0 , 0x300 ) ;
return V_5 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_27 ( V_2 ) ;
struct V_33 * V_33 = F_13 ( V_17 ) ;
F_28 ( V_17 ) ;
F_29 ( V_33 ) ;
return 0 ;
}
