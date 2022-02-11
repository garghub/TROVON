static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
if ( V_6 -> V_9 -> V_10 ) {
struct V_11 V_12 ;
char V_13 [ 2 ] ;
V_12 . V_14 = V_2 -> V_14 ;
V_12 . V_15 = 0 ;
V_12 . V_16 = 2 ;
V_13 [ 0 ] = V_3 ;
V_13 [ 1 ] = V_4 ;
V_12 . V_13 = V_13 ;
V_8 = F_2 ( V_6 , & V_12 , 1 ) ;
} else {
union V_17 V_18 ;
V_18 . V_19 = V_4 ;
V_8 = V_6 -> V_9 -> V_20 ( V_6 , V_2 -> V_14 ,
V_2 -> V_15 ,
V_21 ,
V_3 ,
V_22 , & V_18 ) ;
}
return V_8 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
T_1 V_4 ;
if ( V_6 -> V_9 -> V_10 ) {
struct V_11 V_12 [ 2 ] = {
{
. V_14 = V_2 -> V_14 ,
. V_15 = 0 ,
. V_16 = 1 ,
. V_13 = & V_3
} ,
{
. V_14 = V_2 -> V_14 ,
. V_15 = V_23 ,
. V_16 = 1 ,
. V_13 = & V_4
}
} ;
V_8 = F_2 ( V_6 , V_12 , 2 ) ;
if ( V_8 == 2 )
V_8 = V_4 ;
else if ( V_8 >= 0 )
V_8 = - V_24 ;
} else {
union V_17 V_18 ;
V_8 = V_6 -> V_9 -> V_20 ( V_6 , V_2 -> V_14 ,
V_2 -> V_15 ,
V_25 ,
V_3 ,
V_22 , & V_18 ) ;
if ( ! V_8 )
V_8 = V_18 . V_19 ;
}
return V_8 ;
}
static void F_4 ( struct V_1 * V_2 )
{
int V_26 ;
V_26 = F_3 ( V_2 , V_27 ) ;
if ( V_26 >= 0 && ! F_5 ( V_26 ) && F_6 ( V_26 ) )
F_1 ( V_2 , V_27 ,
( V_26 & V_28 ) >> 1 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_8 ( V_2 ) ;
struct V_31 * V_18 = F_9 ( V_30 ) ;
int V_26 ;
V_26 = F_3 ( V_2 , V_27 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( F_5 ( V_26 ) ) {
int V_32 ;
V_32 = F_3 ( V_2 , V_33 ) ;
if ( ! ( V_32 & V_34 )
|| F_10 ( V_18 -> V_35 ) ) {
F_1 ( V_2 ,
V_27 ,
V_36 [ V_26 & 0x0f ]
| V_37 ) ;
V_18 -> V_38 = V_39 ;
} else {
V_18 -> V_38 = V_40 * 2 ;
}
} else if ( F_6 ( V_26 ) ) {
if ( V_26 & ( V_37 | V_41 ) )
F_1 ( V_2 ,
V_27 ,
V_26 & ~ ( V_37
| V_41 ) ) ;
return 1 ;
} else {
V_18 -> V_38 = V_40 ;
if ( F_10 ( V_18 -> V_35 ) ) {
F_1 ( V_2 ,
V_27 ,
V_36 [ V_26 & 0x0f ]
| V_41
| V_37 ) ;
} else {
if ( ! ( V_26 & V_37 ) )
F_1 ( V_2 ,
V_27 ,
V_26 | V_37 ) ;
}
}
return 0 ;
}
static int F_11 ( struct V_29 * V_30 , T_2 V_42 )
{
struct V_31 * V_18 = F_9 ( V_30 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
int V_8 ;
unsigned long V_43 = V_44 + V_45 ;
V_18 -> V_35 = V_44 + V_46 ;
do {
V_8 = F_7 ( V_2 ) ;
if ( V_8 )
return V_8 < 0 ? V_8 : 0 ;
if ( V_18 -> V_38 == V_39 )
F_12 ( V_18 -> V_38 ) ;
else
F_13 ( V_18 -> V_38 / 1000 ) ;
} while ( F_14 ( V_43 ) );
return - V_47 ;
}
static int F_15 ( struct V_29 * V_30 , T_2 V_42 )
{
struct V_31 * V_18 = F_9 ( V_30 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
F_4 ( V_2 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
const struct V_48 * V_49 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_50 * V_51 = F_17 ( & V_2 -> V_52 ) ;
struct V_29 * V_30 ;
struct V_31 * V_18 ;
int V_53 ;
int V_8 ;
if ( ! F_18 ( V_6 , V_54 ) )
return - V_55 ;
F_19 ( V_6 ) ;
F_4 ( V_2 ) ;
F_20 ( V_6 ) ;
V_53 = 0 ;
if ( V_51 )
V_53 = V_51 -> V_56 [ 0 ] . V_57 ;
V_30 = F_21 ( V_6 , & V_2 -> V_52 , 1 , sizeof( * V_18 ) ,
V_58 ,
F_11 , F_15 ) ;
if ( ! V_30 )
return - V_59 ;
V_18 = F_9 ( V_30 ) ;
V_18 -> V_2 = V_2 ;
F_22 ( V_2 , V_30 ) ;
V_8 = F_23 ( V_30 , V_53 , 0 , 0 ) ;
if ( V_8 )
return V_8 ;
F_24 ( & V_2 -> V_52 , L_1 ,
V_2 -> V_60 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_8 ( V_2 ) ;
F_26 ( V_30 ) ;
return 0 ;
}
