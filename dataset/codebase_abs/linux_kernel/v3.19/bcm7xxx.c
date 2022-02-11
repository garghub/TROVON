static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
F_2 ( V_2 , V_5 , V_6 | V_3 ) ;
F_2 ( V_2 , V_7 , V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_8 , T_1 V_4 )
{
int V_9 ;
F_2 ( V_2 , V_10 , V_11 ) ;
V_9 = F_4 ( V_2 , V_10 ) ;
V_9 |= V_12 ;
F_2 ( V_2 , V_10 , V_9 ) ;
V_9 = ( V_8 * V_13 ) | V_3 ;
F_2 ( V_2 , V_5 , V_9 ) ;
F_2 ( V_2 , V_7 , V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0x00b0 , 0x0010 ) ;
F_1 ( V_2 , 0x00b0 , 0x0000 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_14 , 0x0048 ) ;
F_3 ( V_2 , V_15 , 0x021b ) ;
F_3 ( V_2 , V_16 , 0x0e20 ) ;
F_3 ( V_2 , V_17 , 0x690b ) ;
F_2 ( V_2 , V_18 , 0xd ) ;
F_5 ( V_2 ) ;
F_3 ( V_2 , V_19 , 0xeb19 ) ;
F_3 ( V_2 , V_20 , 0x9a3f ) ;
F_3 ( V_2 , V_21 , 0x7fc0 ) ;
F_3 ( V_2 , V_22 , 0x000b ) ;
F_3 ( V_2 , V_23 , 0x0800 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_19 , 0xeb15 ) ;
F_3 ( V_2 , V_20 , 0x9b2f ) ;
F_3 ( V_2 , V_24 , 0x2003 ) ;
F_3 ( V_2 , V_21 , 0x7fc0 ) ;
F_3 ( V_2 , V_23 , 0x0061 ) ;
F_3 ( V_2 , V_25 , 0xa7da ) ;
F_3 ( V_2 , V_26 , 0xa020 ) ;
F_3 ( V_2 , V_22 , 0x00e3 ) ;
F_2 ( V_2 , V_18 , 0x0010 ) ;
F_3 ( V_2 , V_17 , 0x011b ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_20 , 0x9b2f ) ;
F_3 ( V_2 , V_25 , 0xa7da ) ;
F_3 ( V_2 , V_22 , 0x00e3 ) ;
F_2 ( V_2 , V_18 , 0x0010 ) ;
F_3 ( V_2 , V_17 , 0x011b ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_27 ;
V_27 = F_10 ( V_2 , V_28 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 |= V_29 ;
F_11 ( V_2 , V_28 , V_27 ) ;
V_27 = F_10 ( V_2 , V_30 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 |= V_31 ;
return F_11 ( V_2 , V_30 , V_27 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_27 ;
V_27 = F_13 ( V_2 , V_32 ,
V_33 , V_2 -> V_34 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 |= V_35 | V_36 ;
F_14 ( V_2 , V_32 ,
V_33 , V_2 -> V_34 , V_27 ) ;
V_27 = F_13 ( V_2 , V_37 ,
V_33 , V_2 -> V_34 ) ;
V_27 |= ( V_38 | V_39 ) ;
F_14 ( V_2 , V_37 ,
V_33 , V_2 -> V_34 , V_27 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
T_2 V_40 = F_16 ( V_2 -> V_41 ) ;
T_2 V_42 = F_17 ( V_2 -> V_41 ) ;
int V_43 = 0 ;
F_18 ( L_1 ,
F_19 ( & V_2 -> V_44 ) , V_2 -> V_45 -> V_46 , V_40 , V_42 ) ;
switch ( V_40 ) {
case 0xb0 :
V_43 = F_6 ( V_2 ) ;
break;
case 0xd0 :
V_43 = F_7 ( V_2 ) ;
break;
case 0xe0 :
case 0xf0 :
case 0x10 :
V_43 = F_8 ( V_2 ) ;
break;
default:
break;
}
if ( V_43 )
return V_43 ;
V_43 = F_12 ( V_2 ) ;
if ( V_43 )
return V_43 ;
return F_9 ( V_2 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_43 ;
V_43 = F_15 ( V_2 ) ;
if ( V_43 )
return V_43 ;
return F_21 ( V_2 ) ;
}
static int F_22 ( struct V_1 * V_44 , int V_47 ,
int V_48 , int V_49 )
{
int V_50 , V_43 ;
V_50 = F_4 ( V_44 , V_47 ) ;
if ( V_50 < 0 )
return V_50 ;
V_50 &= ~ V_49 ;
V_50 |= V_48 ;
V_43 = F_2 ( V_44 , V_47 , V_50 ) ;
if ( V_43 < 0 )
return V_43 ;
return V_50 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_43 ;
F_2 ( V_2 , V_51 , V_52 ) ;
F_4 ( V_2 , V_51 ) ;
if ( V_2 -> V_53 & V_54 )
return 0 ;
V_43 = F_22 ( V_2 , V_55 ,
V_56 , V_56 ) ;
if ( V_43 < 0 )
return V_43 ;
F_2 ( V_2 , V_57 , 0x0F00 ) ;
F_24 ( 10 ) ;
F_2 ( V_2 , V_57 , 0x0C00 ) ;
F_2 ( V_2 , V_58 , 0x7555 ) ;
V_43 = F_22 ( V_2 , V_55 , V_56 , 0 ) ;
if ( V_43 < 0 )
return V_43 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_43 ;
const struct V_59 {
int V_3 ;
T_1 V_4 ;
} V_60 [] = {
{ V_55 , 0x008b } ,
{ V_61 , 0x01c0 } ,
{ V_57 , 0x7000 } ,
{ V_55 , 0x000f } ,
{ V_61 , 0x20d0 } ,
{ V_55 , 0x000b } ,
} ;
unsigned int V_62 ;
for ( V_62 = 0 ; V_62 < F_26 ( V_60 ) ; V_62 ++ ) {
V_43 = F_2 ( V_2 ,
V_60 [ V_62 ] . V_3 ,
V_60 [ V_62 ] . V_4 ) ;
if ( V_43 )
return V_43 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
return 0 ;
}
