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
static int F_14 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_15 ( V_21 ) ;
F_16 ( V_23 -> V_24 ) ;
F_16 ( V_23 -> V_25 ) ;
return 0 ;
}
static int F_17 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_15 ( V_21 ) ;
int V_26 ;
V_26 = F_18 ( V_23 -> V_24 ) ;
if ( V_26 ) {
F_19 ( V_21 , L_1 ) ;
return V_26 ;
}
V_26 = F_18 ( V_23 -> V_25 ) ;
if ( V_26 ) {
F_19 ( V_21 , L_2 ) ;
return V_26 ;
}
return 0 ;
}
static void
F_20 ( struct V_1 * V_2 , unsigned int V_27 , unsigned int V_5 )
{
if ( ! V_27 )
F_21 ( V_2 -> V_21 ) ;
F_22 ( V_2 , V_27 , V_5 ) ;
if ( V_27 )
F_23 ( V_2 -> V_21 ) ;
}
static int F_24 ( struct V_28 * V_29 , struct V_1 * V_30 ,
struct V_22 * V_23 )
{
V_23 -> V_24 = F_25 ( & V_29 -> V_21 , L_3 ) ;
if ( F_26 ( V_23 -> V_24 ) ) {
V_23 -> V_24 = F_25 ( & V_29 -> V_21 , NULL ) ;
if ( F_26 ( V_23 -> V_24 ) ) {
F_19 ( & V_29 -> V_21 , L_4 ) ;
return F_27 ( V_23 -> V_24 ) ;
}
return 0 ;
}
V_23 -> V_25 = F_25 ( & V_29 -> V_21 , L_5 ) ;
if ( F_26 ( V_23 -> V_25 ) )
return F_27 ( V_23 -> V_25 ) ;
return 0 ;
}
static int F_28 ( struct V_28 * V_29 )
{
struct V_9 V_31 = {} ;
struct V_32 * V_33 = F_29 ( V_29 , V_34 , 0 ) ;
struct V_32 * V_35 = F_29 ( V_29 , V_36 , 0 ) ;
struct V_22 * V_23 ;
int V_26 ;
if ( ! V_33 || ! V_35 ) {
F_30 ( & V_29 -> V_21 , L_6 ) ;
return - V_37 ;
}
V_31 . V_2 . V_38 = F_31 ( & V_29 -> V_21 , V_33 -> V_39 ,
F_32 ( V_33 ) ) ;
if ( ! V_31 . V_2 . V_38 )
return - V_40 ;
V_23 = F_33 ( & V_29 -> V_21 , sizeof( * V_23 ) , V_41 ) ;
if ( ! V_23 )
return - V_40 ;
if ( V_29 -> V_21 . V_42 ) {
V_26 = F_24 ( V_29 , & V_31 . V_2 , V_23 ) ;
if ( V_26 )
return V_26 ;
} else
return - V_43 ;
F_34 ( & V_31 . V_2 . V_13 ) ;
V_31 . V_2 . V_44 = V_33 -> V_39 ;
V_31 . V_2 . V_35 = V_35 -> V_39 ;
V_31 . V_2 . V_45 = F_20 ;
V_31 . V_2 . type = V_46 ;
V_31 . V_2 . V_6 = V_47 | V_48 ;
V_31 . V_2 . V_21 = & V_29 -> V_21 ;
V_31 . V_2 . V_49 = V_50 ;
V_31 . V_2 . V_51 = 2 ;
V_31 . V_2 . V_52 = V_23 ;
V_31 . V_2 . V_53 = F_1 ;
V_31 . V_2 . V_11 = F_35 ( V_23 -> V_24 ) ;
F_36 ( 0x0 , V_31 . V_2 . V_38 +
( V_54 << V_31 . V_2 . V_51 ) ) ;
F_37 ( V_29 , V_23 ) ;
F_38 ( & V_29 -> V_21 ) ;
if ( ! F_39 ( & V_29 -> V_21 ) ) {
V_26 = F_17 ( & V_29 -> V_21 ) ;
if ( V_26 )
return V_26 ;
}
V_23 -> line = F_40 ( & V_31 ) ;
if ( V_23 -> line < 0 )
return V_23 -> line ;
return 0 ;
}
static int F_41 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_15 ( V_21 ) ;
F_42 ( V_23 -> line ) ;
return 0 ;
}
static int F_43 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_15 ( V_21 ) ;
F_44 ( V_23 -> line ) ;
return 0 ;
}
static int T_1 F_45 ( struct V_55 * V_20 ,
const char * V_56 )
{
if ( ! V_20 -> V_2 . V_38 )
return - V_43 ;
V_20 -> V_2 . V_49 = V_50 ;
return F_46 ( V_20 , NULL ) ;
}
