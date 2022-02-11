static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , 0x00b0 , 0x0010 ) ;
F_2 ( V_2 , 0x00b0 , 0x0000 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_3 , 0x0048 ) ;
F_4 ( V_2 , V_4 , 0x021b ) ;
F_4 ( V_2 , V_5 , 0x0e20 ) ;
F_4 ( V_2 , V_6 , 0x690b ) ;
F_5 ( V_2 , V_7 , 0xd ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 , V_8 , 0xeb19 ) ;
F_4 ( V_2 , V_9 , 0x9a3f ) ;
F_4 ( V_2 , V_10 , 0x7fc0 ) ;
F_4 ( V_2 , V_11 , 0x000b ) ;
F_4 ( V_2 , V_12 , 0x0800 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_8 , 0xeb15 ) ;
F_4 ( V_2 , V_9 , 0x9b2f ) ;
F_4 ( V_2 , V_13 , 0x2003 ) ;
F_4 ( V_2 , V_10 , 0x7fc0 ) ;
F_4 ( V_2 , V_12 , 0x431 ) ;
F_4 ( V_2 , V_14 , 0xa7da ) ;
F_4 ( V_2 , V_15 , 0xa020 ) ;
F_4 ( V_2 , V_11 , 0x00e3 ) ;
F_5 ( V_2 , V_7 , 0x0010 ) ;
F_4 ( V_2 , V_6 , 0x011b ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_9 , 0x9b2f ) ;
F_4 ( V_2 , V_12 , 0x431 ) ;
F_4 ( V_2 , V_14 , 0xa7da ) ;
F_4 ( V_2 , V_11 , 0x00e3 ) ;
F_5 ( V_2 , V_7 , 0x0010 ) ;
F_4 ( V_2 , V_6 , 0x011b ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
T_1 V_16 = F_9 ( V_2 -> V_17 ) ;
T_1 V_18 = F_10 ( V_2 -> V_17 ) ;
int V_19 = 0 ;
F_11 ( L_1 ,
F_12 ( & V_2 -> V_20 ) , V_2 -> V_21 -> V_22 , V_16 , V_18 ) ;
F_13 ( V_2 , V_23 ) ;
switch ( V_16 ) {
case 0xb0 :
V_19 = F_3 ( V_2 ) ;
break;
case 0xd0 :
V_19 = F_6 ( V_2 ) ;
break;
case 0xe0 :
case 0xf0 :
case 0x10 :
V_19 = F_7 ( V_2 ) ;
break;
default:
break;
}
if ( V_19 )
return V_19 ;
V_19 = F_14 ( V_2 ) ;
if ( V_19 )
return V_19 ;
return F_15 ( V_2 , true ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_19 ;
V_19 = F_8 ( V_2 ) ;
if ( V_19 )
return V_19 ;
return F_17 ( V_2 ) ;
}
static int F_18 ( struct V_1 * V_20 , int V_24 ,
int V_25 , int V_26 )
{
int V_27 , V_19 ;
V_27 = F_13 ( V_20 , V_24 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 &= ~ V_26 ;
V_27 |= V_25 ;
V_19 = F_5 ( V_20 , V_24 , V_27 ) ;
if ( V_19 < 0 )
return V_19 ;
return V_27 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_19 ;
F_5 ( V_2 , V_28 , V_29 ) ;
F_13 ( V_2 , V_28 ) ;
if ( V_2 -> V_30 & V_31 )
return 0 ;
V_19 = F_18 ( V_2 , V_32 ,
V_33 , V_33 ) ;
if ( V_19 < 0 )
return V_19 ;
F_5 ( V_2 , V_34 , 0x0F00 ) ;
F_20 ( 10 ) ;
F_5 ( V_2 , V_34 , 0x0C00 ) ;
F_5 ( V_2 , V_35 , 0x7555 ) ;
V_19 = F_18 ( V_2 , V_32 , V_33 , 0 ) ;
if ( V_19 < 0 )
return V_19 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_19 ;
const struct V_36 {
int V_37 ;
T_2 V_38 ;
} V_39 [] = {
{ V_32 , 0x008b } ,
{ V_40 , 0x01c0 } ,
{ V_34 , 0x7000 } ,
{ V_32 , 0x000f } ,
{ V_40 , 0x20d0 } ,
{ V_32 , 0x000b } ,
} ;
unsigned int V_41 ;
for ( V_41 = 0 ; V_41 < F_22 ( V_39 ) ; V_41 ++ ) {
V_19 = F_5 ( V_2 ,
V_39 [ V_41 ] . V_37 ,
V_39 [ V_41 ] . V_38 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
return 0 ;
}
