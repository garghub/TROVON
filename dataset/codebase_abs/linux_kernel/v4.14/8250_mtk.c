static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned long V_8 ;
unsigned int V_9 , V_10 ;
F_3 ( V_2 , V_4 , V_5 ) ;
V_9 = F_4 ( V_2 , V_4 , V_5 ,
V_2 -> V_11 / 16 / 0xffff ,
V_2 -> V_11 ) ;
if ( V_9 <= 115200 ) {
F_5 ( V_2 , V_12 , 0x0 ) ;
V_10 = F_6 ( V_2 , V_9 ) ;
} else if ( V_9 <= 576000 ) {
F_5 ( V_2 , V_12 , 0x2 ) ;
if ( ( V_9 == 500000 ) || ( V_9 == 576000 ) )
V_9 = 460800 ;
V_10 = F_7 ( V_2 -> V_11 , 4 * V_9 ) ;
} else {
F_5 ( V_2 , V_12 , 0x3 ) ;
V_10 = F_7 ( V_2 -> V_11 , 256 * V_9 ) ;
}
F_8 ( & V_2 -> V_13 , V_8 ) ;
F_5 ( V_2 , V_14 , V_7 -> V_15 | V_16 ) ;
F_9 ( V_7 , V_10 ) ;
F_5 ( V_2 , V_14 , V_7 -> V_15 ) ;
if ( V_9 > 460800 ) {
unsigned int V_17 ;
V_17 = F_10 ( V_2 -> V_11 , V_10 * V_9 ) ;
F_5 ( V_2 , V_18 , V_17 - 1 ) ;
F_5 ( V_2 , V_19 ,
( V_17 - 2 ) >> 1 ) ;
} else {
F_5 ( V_2 , V_18 , 0x00 ) ;
F_5 ( V_2 , V_19 , 0xff ) ;
}
F_11 ( & V_2 -> V_13 , V_8 ) ;
if ( F_12 ( V_4 ) )
F_13 ( V_4 , V_9 , V_9 ) ;
}
static int T_1 F_14 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_15 ( V_21 ) ;
F_16 ( V_23 -> V_24 ) ;
F_16 ( V_23 -> V_25 ) ;
return 0 ;
}
static int T_1 F_17 ( struct V_20 * V_21 )
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
return F_28 ( V_23 -> V_25 ) ;
}
static int F_29 ( struct V_28 * V_29 )
{
struct V_6 V_31 = {} ;
struct V_32 * V_33 = F_30 ( V_29 , V_34 , 0 ) ;
struct V_32 * V_35 = F_30 ( V_29 , V_36 , 0 ) ;
struct V_22 * V_23 ;
int V_26 ;
if ( ! V_33 || ! V_35 ) {
F_31 ( & V_29 -> V_21 , L_6 ) ;
return - V_37 ;
}
V_31 . V_2 . V_38 = F_32 ( & V_29 -> V_21 , V_33 -> V_39 ,
F_33 ( V_33 ) ) ;
if ( ! V_31 . V_2 . V_38 )
return - V_40 ;
V_23 = F_34 ( & V_29 -> V_21 , sizeof( * V_23 ) , V_41 ) ;
if ( ! V_23 )
return - V_40 ;
if ( V_29 -> V_21 . V_42 ) {
V_26 = F_24 ( V_29 , & V_31 . V_2 , V_23 ) ;
if ( V_26 )
return V_26 ;
} else
return - V_43 ;
F_35 ( & V_31 . V_2 . V_13 ) ;
V_31 . V_2 . V_44 = V_33 -> V_39 ;
V_31 . V_2 . V_35 = V_35 -> V_39 ;
V_31 . V_2 . V_45 = F_20 ;
V_31 . V_2 . type = V_46 ;
V_31 . V_2 . V_8 = V_47 | V_48 ;
V_31 . V_2 . V_21 = & V_29 -> V_21 ;
V_31 . V_2 . V_49 = V_50 ;
V_31 . V_2 . V_51 = 2 ;
V_31 . V_2 . V_52 = V_23 ;
V_31 . V_2 . V_53 = F_1 ;
V_31 . V_2 . V_11 = F_36 ( V_23 -> V_24 ) ;
F_37 ( 0x0 , V_31 . V_2 . V_38 +
( V_54 << V_31 . V_2 . V_51 ) ) ;
F_38 ( V_29 , V_23 ) ;
F_39 ( & V_29 -> V_21 ) ;
if ( ! F_40 ( & V_29 -> V_21 ) ) {
V_26 = F_17 ( & V_29 -> V_21 ) ;
if ( V_26 )
return V_26 ;
}
V_23 -> line = F_41 ( & V_31 ) ;
if ( V_23 -> line < 0 )
return V_23 -> line ;
return 0 ;
}
static int F_42 ( struct V_28 * V_29 )
{
struct V_22 * V_23 = F_43 ( V_29 ) ;
F_21 ( & V_29 -> V_21 ) ;
F_44 ( V_23 -> line ) ;
F_45 ( & V_29 -> V_21 ) ;
F_46 ( & V_29 -> V_21 ) ;
if ( ! F_47 ( & V_29 -> V_21 ) )
F_14 ( & V_29 -> V_21 ) ;
return 0 ;
}
static int T_1 F_48 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_15 ( V_21 ) ;
F_49 ( V_23 -> line ) ;
return 0 ;
}
static int T_1 F_50 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_15 ( V_21 ) ;
F_51 ( V_23 -> line ) ;
return 0 ;
}
static int T_2 F_52 ( struct V_55 * V_20 ,
const char * V_56 )
{
if ( ! V_20 -> V_2 . V_38 )
return - V_43 ;
V_20 -> V_2 . V_49 = V_50 ;
return F_53 ( V_20 , NULL ) ;
}
