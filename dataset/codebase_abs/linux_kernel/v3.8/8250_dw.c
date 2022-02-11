static void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_3 == V_8 )
V_6 -> V_9 = V_4 ;
V_3 <<= V_2 -> V_10 ;
F_2 ( V_4 , V_2 -> V_11 + V_3 ) ;
}
static unsigned int F_3 ( struct V_1 * V_2 , int V_3 )
{
V_3 <<= V_2 -> V_10 ;
return F_4 ( V_2 -> V_11 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_3 == V_8 )
V_6 -> V_9 = V_4 ;
V_3 <<= V_2 -> V_10 ;
F_6 ( V_4 , V_2 -> V_11 + V_3 ) ;
}
static unsigned int F_7 ( struct V_1 * V_2 , int V_3 )
{
V_3 <<= V_2 -> V_10 ;
return F_8 ( V_2 -> V_11 + V_3 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_12 = V_2 -> V_13 ( V_2 , V_14 ) ;
if ( F_10 ( V_2 , V_12 ) ) {
return 1 ;
} else if ( ( V_12 & V_15 ) == V_15 ) {
( void ) V_2 -> V_13 ( V_2 , V_16 ) ;
V_2 -> V_17 ( V_2 , V_8 , V_6 -> V_9 ) ;
return 1 ;
}
return 0 ;
}
static int F_11 ( struct V_18 * V_19 )
{
struct V_20 V_21 = {} ;
struct V_22 * V_23 = F_12 ( V_19 , V_24 , 0 ) ;
struct V_22 * V_25 = F_12 ( V_19 , V_26 , 0 ) ;
struct V_27 * V_28 = V_19 -> V_29 . V_30 ;
T_1 V_31 ;
struct V_5 * V_32 ;
if ( ! V_23 || ! V_25 ) {
F_13 ( & V_19 -> V_29 , L_1 ) ;
return - V_33 ;
}
V_32 = F_14 ( & V_19 -> V_29 , sizeof( * V_32 ) , V_34 ) ;
if ( ! V_32 )
return - V_35 ;
V_21 . V_36 . V_7 = V_32 ;
F_15 ( & V_21 . V_36 . V_37 ) ;
V_21 . V_36 . V_38 = V_23 -> V_39 ;
V_21 . V_36 . V_25 = V_25 -> V_39 ;
V_21 . V_36 . V_40 = F_9 ;
V_21 . V_36 . type = V_41 ;
V_21 . V_36 . V_42 = V_43 | V_44 | V_45 |
V_46 | V_47 ;
V_21 . V_36 . V_29 = & V_19 -> V_29 ;
V_21 . V_36 . V_48 = V_49 ;
V_21 . V_36 . V_13 = F_3 ;
V_21 . V_36 . V_17 = F_1 ;
if ( ! F_16 ( V_28 , L_2 , & V_31 ) ) {
switch ( V_31 ) {
case 1 :
break;
case 4 :
V_21 . V_36 . V_48 = V_50 ;
V_21 . V_36 . V_13 = F_7 ;
V_21 . V_36 . V_17 = F_5 ;
break;
default:
F_13 ( & V_19 -> V_29 , L_3 ,
V_31 ) ;
return - V_33 ;
}
}
if ( ! F_16 ( V_28 , L_4 , & V_31 ) )
V_21 . V_36 . V_10 = V_31 ;
if ( F_16 ( V_28 , L_5 , & V_31 ) ) {
F_13 ( & V_19 -> V_29 , L_6 ) ;
return - V_33 ;
}
V_21 . V_36 . V_51 = V_31 ;
V_32 -> line = F_17 ( & V_21 ) ;
if ( V_32 -> line < 0 )
return V_32 -> line ;
F_18 ( V_19 , V_32 ) ;
return 0 ;
}
static int F_19 ( struct V_18 * V_19 )
{
struct V_5 * V_32 = F_20 ( V_19 ) ;
F_21 ( V_32 -> line ) ;
return 0 ;
}
static int F_22 ( struct V_18 * V_19 , T_2 V_52 )
{
struct V_5 * V_32 = F_20 ( V_19 ) ;
F_23 ( V_32 -> line ) ;
return 0 ;
}
static int F_24 ( struct V_18 * V_19 )
{
struct V_5 * V_32 = F_20 ( V_19 ) ;
F_25 ( V_32 -> line ) ;
return 0 ;
}
