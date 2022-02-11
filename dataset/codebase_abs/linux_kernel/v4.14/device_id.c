static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
static struct {
int V_4 , type , V_5 ;
} V_6 [] = {
{ 0x08 , 0x01 , 0x3480 } ,
{ 0x08 , 0x02 , 0x3430 } ,
{ 0x08 , 0x10 , 0x3420 } ,
{ 0x08 , 0x42 , 0x3424 } ,
{ 0x08 , 0x44 , 0x9348 } ,
{ 0x08 , 0x81 , 0x3490 } ,
{ 0x08 , 0x82 , 0x3422 } ,
{ 0x10 , 0x41 , 0x1403 } ,
{ 0x10 , 0x42 , 0x3211 } ,
{ 0x10 , 0x43 , 0x3203 } ,
{ 0x10 , 0x45 , 0x3800 } ,
{ 0x10 , 0x47 , 0x3262 } ,
{ 0x10 , 0x48 , 0x3820 } ,
{ 0x10 , 0x49 , 0x3800 } ,
{ 0x10 , 0x4a , 0x4245 } ,
{ 0x10 , 0x4b , 0x4248 } ,
{ 0x10 , 0x4d , 0x3800 } ,
{ 0x10 , 0x4e , 0x3820 } ,
{ 0x10 , 0x4f , 0x3820 } ,
{ 0x10 , 0x82 , 0x2540 } ,
{ 0x10 , 0x84 , 0x3525 } ,
{ 0x20 , 0x81 , 0x2501 } ,
{ 0x20 , 0x82 , 0x2540 } ,
{ 0x20 , 0x84 , 0x3505 } ,
{ 0x40 , 0x01 , 0x3278 } ,
{ 0x40 , 0x04 , 0x3277 } ,
{ 0x40 , 0x80 , 0x2250 } ,
{ 0x40 , 0xc0 , 0x5080 } ,
{ 0x80 , 0x00 , 0x3215 } ,
} ;
int V_7 ;
if ( V_3 -> V_8 == 0x02 && V_3 -> V_9 == 0x20 ) {
V_1 -> V_5 = 0x3088 ;
V_1 -> V_10 = 0x60 ;
V_1 -> V_11 = 0xff ;
return 0 ;
}
for ( V_7 = 0 ; V_7 < F_2 ( V_6 ) ; V_7 ++ ) {
if ( V_3 -> V_8 == V_6 [ V_7 ] . V_4 &&
V_3 -> V_9 == V_6 [ V_7 ] . type ) {
V_1 -> V_5 = V_6 [ V_7 ] . V_5 ;
V_1 -> V_11 = 0xff ;
return 0 ;
}
}
return - V_12 ;
}
static int F_3 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_17 -> V_16 ;
struct V_1 * V_1 = & V_14 -> V_17 -> V_1 ;
struct V_2 V_18 ;
int V_19 ;
if ( V_16 -> V_20 != 0 )
return - V_12 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_21 = V_16 -> V_22 ;
V_18 . V_23 = sizeof( V_18 ) ;
V_19 = V_2 ( & V_18 ) ;
F_4 ( 4 , L_1 ) ;
F_5 ( 4 , & V_19 , sizeof( V_19 ) ) ;
F_5 ( 4 , & V_18 , sizeof( V_18 ) ) ;
if ( V_19 != 0 && V_19 != 2 )
goto V_24;
if ( F_1 ( V_1 , & V_18 ) )
goto V_25;
return 0 ;
V_25:
F_6 ( 0 , L_2 ,
V_16 -> V_20 , V_16 -> V_22 ) ;
return - V_12 ;
V_24:
F_6 ( 0 , L_3 ,
V_16 -> V_20 , V_16 -> V_22 , V_19 ) ;
return - V_12 ;
}
static void F_7 ( struct V_13 * V_14 )
{
V_14 -> V_17 -> V_26 . V_27 = 0 ;
memset ( & V_14 -> V_17 -> V_1 , 0 , sizeof( V_14 -> V_17 -> V_1 ) ) ;
V_14 -> V_17 -> V_1 . V_5 = 0xffff ;
}
static int F_8 ( struct V_13 * V_14 , void * V_28 )
{
struct V_29 * V_30 = & V_14 -> V_17 -> V_31 . V_30 . V_32 ;
int V_33 = sizeof( struct V_1 ) - V_30 -> V_34 ;
if ( V_33 < V_35 )
goto V_36;
if ( V_14 -> V_17 -> V_1 . V_5 == 0xffff )
goto V_36;
if ( V_14 -> V_17 -> V_1 . V_11 != 0xff )
return - V_37 ;
if ( V_33 > V_38 )
V_14 -> V_17 -> V_26 . V_27 = 1 ;
return 0 ;
V_36:
F_7 ( V_14 ) ;
return - V_39 ;
}
static void F_9 ( struct V_13 * V_14 , void * V_28 , int V_19 )
{
struct V_15 * V_40 = & V_14 -> V_17 -> V_16 ;
struct V_1 * V_1 = & V_14 -> V_17 -> V_1 ;
int V_41 = 0 ;
if ( V_19 && V_42 ) {
F_7 ( V_14 ) ;
if ( F_3 ( V_14 ) == 0 ) {
V_19 = 0 ;
V_41 = 1 ;
}
}
F_6 ( 2 , L_4
L_5 , V_40 -> V_20 , V_40 -> V_22 , V_19 ,
V_1 -> V_5 , V_1 -> V_10 , V_1 -> V_43 ,
V_1 -> V_44 , V_41 ? L_6 : L_7 ) ;
F_10 ( V_14 , V_19 ) ;
}
void F_11 ( struct V_13 * V_14 )
{
struct V_45 * V_46 = F_12 ( V_14 -> V_47 . V_48 ) ;
struct V_49 * V_50 = & V_14 -> V_17 -> V_50 ;
struct V_51 * V_52 = V_14 -> V_17 -> V_53 ;
F_4 ( 4 , L_8 ) ;
F_5 ( 4 , & V_14 -> V_17 -> V_16 , sizeof( V_14 -> V_17 -> V_16 ) ) ;
F_7 ( V_14 ) ;
V_52 -> V_54 = V_55 ;
V_52 -> V_56 = ( V_57 ) ( V_58 ) & V_14 -> V_17 -> V_1 ;
V_52 -> V_34 = sizeof( struct V_1 ) ;
V_52 -> V_26 = V_59 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_50 -> V_52 = V_52 ;
V_50 -> V_60 = V_61 ;
V_50 -> V_62 = V_63 ;
V_50 -> V_64 = V_46 -> V_65 . V_66 . V_67 & V_46 -> V_68 ;
V_50 -> V_69 = F_8 ;
V_50 -> V_70 = F_9 ;
F_13 ( V_14 ) ;
}
