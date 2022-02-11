static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * V_5 )
{
unsigned long V_6 ;
unsigned int V_7 , V_8 ;
struct V_9 * V_10 =
F_2 ( V_2 , struct V_9 , V_2 ) ;
F_3 ( V_2 , V_4 , V_5 ) ;
V_7 = F_4 ( V_2 , V_4 , V_5 ,
V_2 -> V_11 / 16 / 0xffff ,
V_2 -> V_11 / 16 ) ;
if ( V_7 <= 115200 ) {
F_5 ( V_2 , V_12 , 0x0 ) ;
V_8 = F_6 ( V_2 , V_7 ) ;
} else if ( V_7 <= 576000 ) {
F_5 ( V_2 , V_12 , 0x2 ) ;
if ( ( V_7 == 500000 ) || ( V_7 == 576000 ) )
V_7 = 460800 ;
V_8 = F_7 ( V_2 -> V_11 , 4 * V_7 ) ;
} else {
F_5 ( V_2 , V_12 , 0x3 ) ;
if ( V_7 >= 1152000 )
V_7 = 921600 ;
V_8 = F_7 ( V_2 -> V_11 , 256 * V_7 ) ;
}
F_8 ( & V_2 -> V_13 , V_6 ) ;
F_5 ( V_2 , V_14 , V_10 -> V_15 | V_16 ) ;
F_9 ( V_10 , V_8 ) ;
F_5 ( V_2 , V_14 , V_10 -> V_15 ) ;
if ( V_7 > 460800 ) {
unsigned int V_17 ;
V_17 = F_10 ( V_2 -> V_11 , V_8 * V_7 ) ;
F_5 ( V_2 , V_18 , V_17 - 1 ) ;
F_5 ( V_2 , V_19 ,
( V_17 - 2 ) >> 1 ) ;
} else {
F_5 ( V_2 , V_18 , 0x00 ) ;
F_5 ( V_2 , V_19 , 0xff ) ;
}
F_11 ( & V_2 -> V_13 , V_6 ) ;
if ( F_12 ( V_4 ) )
F_13 ( V_4 , V_7 , V_7 ) ;
}
static void
F_14 ( struct V_1 * V_2 , unsigned int V_20 , unsigned int V_5 )
{
if ( ! V_20 )
F_15 ( V_2 -> V_21 ) ;
F_16 ( V_2 , V_20 , V_5 ) ;
if ( V_20 )
F_17 ( V_2 -> V_21 ) ;
}
static int F_18 ( struct V_22 * V_23 , struct V_1 * V_24 ,
struct V_25 * V_26 )
{
int V_27 ;
struct V_28 * V_29 = V_23 -> V_21 . V_30 ;
V_26 -> V_31 = F_19 ( V_29 , 0 ) ;
if ( F_20 ( V_26 -> V_31 ) ) {
F_21 ( & V_23 -> V_21 , L_1 ) ;
return F_22 ( V_26 -> V_31 ) ;
}
V_27 = F_23 ( V_26 -> V_31 ) ;
if ( V_27 ) {
F_21 ( & V_23 -> V_21 , L_2 ) ;
F_24 ( V_26 -> V_31 ) ;
return V_27 ;
}
V_24 -> V_11 = F_25 ( V_26 -> V_31 ) ;
return 0 ;
}
static int F_26 ( struct V_22 * V_23 )
{
struct V_9 V_32 = {} ;
struct V_33 * V_34 = F_27 ( V_23 , V_35 , 0 ) ;
struct V_33 * V_36 = F_27 ( V_23 , V_37 , 0 ) ;
struct V_25 * V_26 ;
int V_27 ;
if ( ! V_34 || ! V_36 ) {
F_28 ( & V_23 -> V_21 , L_3 ) ;
return - V_38 ;
}
V_32 . V_2 . V_39 = F_29 ( & V_23 -> V_21 , V_34 -> V_40 ,
F_30 ( V_34 ) ) ;
if ( ! V_32 . V_2 . V_39 )
return - V_41 ;
V_26 = F_31 ( & V_23 -> V_21 , sizeof( * V_26 ) , V_42 ) ;
if ( ! V_26 )
return - V_41 ;
if ( V_23 -> V_21 . V_30 ) {
V_27 = F_18 ( V_23 , & V_32 . V_2 , V_26 ) ;
if ( V_27 )
return V_27 ;
} else
return - V_43 ;
F_32 ( & V_32 . V_2 . V_13 ) ;
V_32 . V_2 . V_44 = V_34 -> V_40 ;
V_32 . V_2 . V_36 = V_36 -> V_40 ;
V_32 . V_2 . V_45 = F_14 ;
V_32 . V_2 . type = V_46 ;
V_32 . V_2 . V_6 = V_47 | V_48 ;
V_32 . V_2 . V_21 = & V_23 -> V_21 ;
V_32 . V_2 . V_49 = V_50 ;
V_32 . V_2 . V_51 = 2 ;
V_32 . V_2 . V_52 = V_26 ;
V_32 . V_2 . V_53 = F_1 ;
F_33 ( 0x0 , V_32 . V_2 . V_39 +
( V_54 << V_32 . V_2 . V_51 ) ) ;
V_26 -> line = F_34 ( & V_32 ) ;
if ( V_26 -> line < 0 )
return V_26 -> line ;
F_35 ( V_23 , V_26 ) ;
F_36 ( & V_23 -> V_21 ) ;
F_37 ( & V_23 -> V_21 ) ;
return 0 ;
}
static int F_38 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = F_39 ( V_23 ) ;
F_15 ( & V_23 -> V_21 ) ;
F_40 ( V_26 -> line ) ;
if ( ! F_20 ( V_26 -> V_31 ) ) {
F_41 ( V_26 -> V_31 ) ;
F_24 ( V_26 -> V_31 ) ;
}
F_42 ( & V_23 -> V_21 ) ;
F_43 ( & V_23 -> V_21 ) ;
return 0 ;
}
static int F_44 ( struct V_55 * V_21 )
{
struct V_25 * V_26 = F_45 ( V_21 ) ;
F_46 ( V_26 -> line ) ;
return 0 ;
}
static int F_47 ( struct V_55 * V_21 )
{
struct V_25 * V_26 = F_45 ( V_21 ) ;
F_48 ( V_26 -> line ) ;
return 0 ;
}
static int F_49 ( struct V_55 * V_21 )
{
struct V_25 * V_26 = F_45 ( V_21 ) ;
if ( ! F_20 ( V_26 -> V_31 ) )
F_41 ( V_26 -> V_31 ) ;
return 0 ;
}
static int F_50 ( struct V_55 * V_21 )
{
struct V_25 * V_26 = F_45 ( V_21 ) ;
if ( ! F_20 ( V_26 -> V_31 ) )
F_23 ( V_26 -> V_31 ) ;
return 0 ;
}
