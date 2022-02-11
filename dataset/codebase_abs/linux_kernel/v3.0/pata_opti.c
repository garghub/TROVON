static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_5 -> V_8 -> V_9 ) ;
static const struct V_10 V_11 [] = {
{ 0x45 , 1 , 0x80 , 0x00 } ,
{ 0x40 , 1 , 0x08 , 0x00 }
} ;
if ( ! F_3 ( V_7 , & V_11 [ V_5 -> V_12 ] ) )
return - V_13 ;
return F_4 ( V_2 , V_3 ) ;
}
static void F_5 ( struct V_4 * V_5 , T_1 V_14 , int V_15 )
{
void T_2 * V_16 = V_5 -> V_17 . V_18 ;
F_6 ( V_16 + 1 ) ;
F_6 ( V_16 + 1 ) ;
F_7 ( 3 , V_16 + 2 ) ;
F_7 ( V_14 , V_16 + V_15 ) ;
F_7 ( 0x83 , V_16 + 2 ) ;
}
static void F_8 ( struct V_4 * V_5 , struct V_19 * V_20 )
{
struct V_19 * V_21 = F_9 ( V_20 ) ;
int clock ;
int V_22 = V_20 -> V_23 - V_24 ;
void T_2 * V_16 = V_5 -> V_17 . V_18 ;
T_1 V_25 ;
static const T_1 V_26 [ 2 ] [ 5 ] = {
{ 0x30 , 0x20 , 0x20 , 0x10 , 0x10 } ,
{ 0x20 , 0x20 , 0x10 , 0x10 , 0x10 }
} ;
static const T_1 V_27 [ 2 ] [ 5 ] = {
{ 0x6B , 0x56 , 0x42 , 0x32 , 0x31 } ,
{ 0x58 , 0x44 , 0x32 , 0x22 , 0x21 }
} ;
F_7 ( 0xff , V_16 + 5 ) ;
clock = F_6 ( V_16 + 5 ) & 1 ;
V_25 = V_26 [ clock ] [ V_22 ] ;
if ( V_21 ) {
T_1 V_28 = V_26 [ clock ] [ V_21 -> V_23 - V_24 ] ;
if ( V_28 > V_25 )
V_25 = V_28 ;
}
F_5 ( V_5 , V_20 -> V_29 , V_30 ) ;
F_5 ( V_5 , V_27 [ clock ] [ V_22 ] , V_31 ) ;
F_5 ( V_5 , V_27 [ clock ] [ V_22 ] , V_32 ) ;
F_5 ( V_5 , V_25 , V_30 ) ;
F_5 ( V_5 , 0x85 , V_33 ) ;
}
static int F_10 ( struct V_6 * V_9 , const struct V_34 * V_35 )
{
static const struct V_36 V_37 = {
. V_38 = V_39 ,
. V_40 = V_41 ,
. V_42 = & V_43
} ;
const struct V_36 * V_44 [] = { & V_37 , NULL } ;
static int V_45 ;
if ( ! V_45 ++ )
F_11 ( V_46 , & V_9 -> V_9 , L_1 V_47 L_2 ) ;
return F_12 ( V_9 , V_44 , & V_48 , NULL , 0 ) ;
}
static int T_3 F_13 ( void )
{
return F_14 ( & V_49 ) ;
}
static void T_4 F_15 ( void )
{
F_16 ( & V_49 ) ;
}
