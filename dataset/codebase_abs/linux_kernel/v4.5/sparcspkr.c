static T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_4 , V_5 = V_2 -> V_5 ;
int V_6 ;
if ( ! V_3 )
return 0 ;
if ( V_3 <= V_5 >> 20 )
return 1 << 18 ;
if ( V_3 >= V_5 >> 12 )
return 1 << 10 ;
V_4 = 1 << 18 ;
for ( V_6 = 19 ; V_6 >= 11 ; V_6 -- ) {
V_4 >>= 1 ;
if ( V_3 <= V_5 >> V_6 )
break;
}
return V_4 ;
}
static int F_2 ( struct V_7 * V_8 , unsigned int type , unsigned int V_9 , int V_10 )
{
struct V_11 * V_12 = F_3 ( V_8 -> V_8 . V_13 ) ;
struct V_1 * V_2 = & V_12 -> V_14 . V_15 ;
unsigned int V_3 = 0 ;
unsigned long V_16 ;
if ( type != V_17 )
return - 1 ;
switch ( V_9 ) {
case V_18 : if ( V_10 ) V_10 = 1000 ;
case V_19 : break;
default: return - 1 ;
}
if ( V_10 > 20 && V_10 < 32767 )
V_3 = 1193182 / V_10 ;
V_3 = F_1 ( V_2 , V_3 ) ;
F_4 ( & V_12 -> V_20 , V_16 ) ;
if ( V_3 ) {
F_5 ( 0x01 , V_2 -> V_21 + 0 ) ;
F_5 ( 0x00 , V_2 -> V_21 + 2 ) ;
F_5 ( ( V_3 >> 16 ) & 0xff , V_2 -> V_21 + 3 ) ;
F_5 ( ( V_3 >> 8 ) & 0xff , V_2 -> V_21 + 4 ) ;
F_5 ( 0x00 , V_2 -> V_21 + 5 ) ;
} else {
F_5 ( 0x00 , V_2 -> V_21 + 0 ) ;
}
F_6 ( & V_12 -> V_20 , V_16 ) ;
return 0 ;
}
static int F_7 ( struct V_7 * V_8 , unsigned int type , unsigned int V_9 , int V_10 )
{
struct V_11 * V_12 = F_3 ( V_8 -> V_8 . V_13 ) ;
struct V_22 * V_2 = & V_12 -> V_14 . V_23 ;
unsigned int V_3 = 0 ;
unsigned long V_16 ;
if ( type != V_17 )
return - 1 ;
switch ( V_9 ) {
case V_18 : if ( V_10 ) V_10 = 1000 ;
case V_19 : break;
default: return - 1 ;
}
if ( V_10 > 20 && V_10 < 32767 )
V_3 = 1193182 / V_10 ;
F_4 ( & V_12 -> V_20 , V_16 ) ;
if ( V_3 ) {
F_5 ( F_8 ( V_2 -> V_24 ) | 3 , V_2 -> V_24 ) ;
F_5 ( 0xB6 , V_2 -> V_25 + 1 ) ;
F_5 ( V_3 & 0xff , V_2 -> V_25 + 0 ) ;
F_5 ( ( V_3 >> 8 ) & 0xff , V_2 -> V_25 + 0 ) ;
} else {
F_5 ( F_8 ( V_2 -> V_24 ) & 0xFC , V_2 -> V_24 ) ;
}
F_6 ( & V_12 -> V_20 , V_16 ) ;
return 0 ;
}
static int F_9 ( struct V_26 * V_8 )
{
struct V_11 * V_12 = F_3 ( V_8 ) ;
struct V_7 * V_7 ;
int error ;
V_7 = F_10 () ;
if ( ! V_7 )
return - V_27 ;
V_7 -> V_28 = V_12 -> V_28 ;
V_7 -> V_29 = L_1 ;
V_7 -> V_30 . V_31 = V_32 ;
V_7 -> V_30 . V_33 = 0x001f ;
V_7 -> V_30 . V_34 = 0x0001 ;
V_7 -> V_30 . V_35 = 0x0100 ;
V_7 -> V_8 . V_13 = V_8 ;
V_7 -> V_36 [ 0 ] = F_11 ( V_17 ) ;
V_7 -> V_37 [ 0 ] = F_11 ( V_18 ) | F_11 ( V_19 ) ;
V_7 -> V_38 = V_12 -> V_38 ;
error = F_12 ( V_7 ) ;
if ( error ) {
F_13 ( V_7 ) ;
return error ;
}
V_12 -> V_7 = V_7 ;
return 0 ;
}
static void F_14 ( struct V_39 * V_8 )
{
struct V_11 * V_12 = F_15 ( V_8 ) ;
struct V_7 * V_7 = V_12 -> V_7 ;
V_12 -> V_38 ( V_7 , V_17 , V_18 , 0 ) ;
}
static int F_16 ( struct V_39 * V_40 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 ;
struct V_41 * V_42 ;
int V_43 = - V_27 ;
V_12 = F_17 ( sizeof( * V_12 ) , V_44 ) ;
if ( ! V_12 )
goto V_45;
V_12 -> V_28 = L_2 ;
V_12 -> V_38 = F_2 ;
F_18 ( & V_12 -> V_20 ) ;
V_42 = F_19 ( L_3 ) ;
V_43 = - V_46 ;
if ( ! V_42 )
goto V_47;
V_2 = & V_12 -> V_14 . V_15 ;
V_2 -> V_5 = F_20 ( V_42 , L_4 , 0 ) ;
if ( ! V_2 -> V_5 )
goto V_47;
V_2 -> V_21 = F_21 ( & V_40 -> V_48 [ 0 ] , 0 , 6 , L_5 ) ;
if ( ! V_2 -> V_21 )
goto V_47;
F_22 ( V_40 , V_12 ) ;
V_43 = F_9 ( & V_40 -> V_8 ) ;
if ( V_43 )
goto V_49;
return 0 ;
V_49:
F_23 ( & V_40 -> V_48 [ 0 ] , V_2 -> V_21 , 6 ) ;
V_47:
F_24 ( V_12 ) ;
V_45:
return V_43 ;
}
static int F_25 ( struct V_39 * V_40 )
{
struct V_11 * V_12 = F_15 ( V_40 ) ;
struct V_7 * V_7 = V_12 -> V_7 ;
struct V_1 * V_2 = & V_12 -> V_14 . V_15 ;
V_12 -> V_38 ( V_7 , V_17 , V_18 , 0 ) ;
F_26 ( V_7 ) ;
F_23 ( & V_40 -> V_48 [ 0 ] , V_2 -> V_21 , 6 ) ;
F_24 ( V_12 ) ;
return 0 ;
}
static int F_27 ( struct V_39 * V_40 )
{
struct V_11 * V_12 ;
struct V_22 * V_2 ;
int V_43 = - V_27 ;
V_12 = F_17 ( sizeof( * V_12 ) , V_44 ) ;
if ( ! V_12 )
goto V_45;
V_12 -> V_28 = L_6 ;
V_12 -> V_38 = F_7 ;
F_18 ( & V_12 -> V_20 ) ;
V_2 = & V_12 -> V_14 . V_23 ;
V_2 -> V_25 = F_21 ( & V_40 -> V_48 [ 2 ] , 0 , 2 , L_7 ) ;
if ( ! V_2 -> V_25 )
goto V_47;
V_2 -> V_24 = F_21 ( & V_40 -> V_48 [ 3 ] , 0 , 1 , L_8 ) ;
if ( ! V_2 -> V_24 )
goto V_50;
F_22 ( V_40 , V_12 ) ;
V_43 = F_9 ( & V_40 -> V_8 ) ;
if ( V_43 )
goto V_49;
return 0 ;
V_49:
F_23 ( & V_40 -> V_48 [ 3 ] , V_2 -> V_24 , 1 ) ;
V_50:
F_23 ( & V_40 -> V_48 [ 2 ] , V_2 -> V_25 , 2 ) ;
V_47:
F_24 ( V_12 ) ;
V_45:
return V_43 ;
}
static int F_28 ( struct V_39 * V_40 )
{
struct V_11 * V_12 = F_15 ( V_40 ) ;
struct V_22 * V_2 = & V_12 -> V_14 . V_23 ;
struct V_7 * V_7 = V_12 -> V_7 ;
V_12 -> V_38 ( V_7 , V_17 , V_18 , 0 ) ;
F_26 ( V_7 ) ;
F_23 ( & V_40 -> V_48 [ 3 ] , V_2 -> V_24 , 1 ) ;
F_23 ( & V_40 -> V_48 [ 2 ] , V_2 -> V_25 , 2 ) ;
F_24 ( V_12 ) ;
return 0 ;
}
static int T_2 F_29 ( void )
{
return F_30 ( V_51 , F_31 ( V_51 ) ) ;
}
static void T_3 F_32 ( void )
{
F_33 ( V_51 , F_31 ( V_51 ) ) ;
}
