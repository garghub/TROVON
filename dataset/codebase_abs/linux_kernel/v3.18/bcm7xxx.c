static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
const struct V_4 {
int V_5 ;
T_1 V_6 ;
} V_7 [] = {
{ V_8 , 0x0038 } ,
{ V_9 , 0xAB95 } ,
{ V_8 , 0x2038 } ,
{ V_9 , 0xBB22 } ,
{ V_8 , 0x6038 } ,
{ V_9 , 0xFFC5 } ,
{ V_8 , 0x003a } ,
{ V_9 , 0x2002 } ,
} ;
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < F_2 ( V_7 ) ; V_10 ++ ) {
V_3 = F_3 ( V_2 ,
V_7 [ V_10 ] . V_5 ,
V_7 [ V_10 ] . V_6 ) ;
if ( V_3 )
return V_3 ;
}
return 0 ;
}
static void F_4 ( struct V_1 * V_2 ,
T_1 V_5 , T_1 V_6 )
{
F_3 ( V_2 , V_8 , V_11 | V_5 ) ;
F_3 ( V_2 , V_9 , V_6 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
T_1 V_5 , T_1 V_12 , T_1 V_6 )
{
int V_13 ;
F_3 ( V_2 , V_14 , V_15 ) ;
V_13 = F_6 ( V_2 , V_14 ) ;
V_13 |= V_16 ;
F_3 ( V_2 , V_14 , V_13 ) ;
V_13 = ( V_12 * V_17 ) | V_5 ;
F_3 ( V_2 , V_8 , V_13 ) ;
F_3 ( V_2 , V_9 , V_6 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_18 , 0x0048 ) ;
F_5 ( V_2 , V_19 , 0x021b ) ;
F_5 ( V_2 , V_20 , 0x0e20 ) ;
F_5 ( V_2 , V_21 , 0x690b ) ;
F_3 ( V_2 , V_22 , 0xd ) ;
F_4 ( V_2 , V_23 , 0x0010 ) ;
F_4 ( V_2 , V_23 , 0x0000 ) ;
F_5 ( V_2 , V_24 , 0xeb19 ) ;
F_5 ( V_2 , V_25 , 0x9a3f ) ;
F_5 ( V_2 , V_26 , 0x7fc0 ) ;
F_5 ( V_2 , V_27 , 0x000b ) ;
F_5 ( V_2 , V_28 , 0x0800 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_29 ;
V_29 = F_9 ( V_2 , V_30 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 |= V_31 ;
F_10 ( V_2 , V_30 , V_29 ) ;
V_29 = F_9 ( V_2 , V_32 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 |= V_33 ;
return F_10 ( V_2 , V_32 , V_29 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_29 ;
V_29 = F_12 ( V_2 , V_34 ,
V_35 , V_2 -> V_36 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 |= V_37 | V_38 ;
F_13 ( V_2 , V_34 ,
V_35 , V_2 -> V_36 , V_29 ) ;
V_29 = F_12 ( V_2 , V_39 ,
V_35 , V_2 -> V_36 ) ;
V_29 |= ( V_40 | V_41 ) ;
F_13 ( V_2 , V_39 ,
V_35 , V_2 -> V_36 , V_29 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
T_2 V_42 = F_15 ( V_2 -> V_43 ) ;
T_2 V_44 = F_16 ( V_2 -> V_43 ) ;
int V_3 = 0 ;
F_17 ( & V_2 -> V_45 , L_1 , V_42 , V_44 ) ;
switch ( V_42 ) {
case 0xa0 :
case 0xb0 :
V_3 = F_1 ( V_2 ) ;
break;
default:
V_3 = F_7 ( V_2 ) ;
break;
}
if ( V_3 )
return V_3 ;
V_3 = F_11 ( V_2 ) ;
if ( V_3 )
return V_3 ;
return F_8 ( V_2 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_14 ( V_2 ) ;
if ( V_3 )
return V_3 ;
return F_19 ( V_2 ) ;
}
static int F_20 ( struct V_1 * V_45 , int V_46 ,
int V_47 , int V_48 )
{
int V_49 , V_3 ;
V_49 = F_6 ( V_45 , V_46 ) ;
if ( V_49 < 0 )
return V_49 ;
V_49 &= ~ V_48 ;
V_49 |= V_47 ;
V_3 = F_3 ( V_45 , V_46 , V_49 ) ;
if ( V_3 < 0 )
return V_3 ;
return V_49 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_3 ;
F_3 ( V_2 , V_50 , V_51 ) ;
F_6 ( V_2 , V_50 ) ;
if ( V_2 -> V_52 & V_53 )
return 0 ;
V_3 = F_20 ( V_2 , V_54 ,
V_55 , V_55 ) ;
if ( V_3 < 0 )
return V_3 ;
F_3 ( V_2 , V_56 , 0x0F00 ) ;
F_22 ( 10 ) ;
F_3 ( V_2 , V_56 , 0x0C00 ) ;
F_3 ( V_2 , V_57 , 0x7555 ) ;
V_3 = F_20 ( V_2 , V_54 , V_55 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_3 ;
const struct V_58 {
int V_5 ;
T_1 V_6 ;
} V_59 [] = {
{ V_54 , 0x008b } ,
{ V_60 , 0x01c0 } ,
{ V_56 , 0x7000 } ,
{ V_54 , 0x000f } ,
{ V_60 , 0x20d0 } ,
{ V_54 , 0x000b } ,
} ;
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < F_2 ( V_59 ) ; V_10 ++ ) {
V_3 = F_3 ( V_2 ,
V_59 [ V_10 ] . V_5 ,
V_59 [ V_10 ] . V_6 ) ;
if ( V_3 )
return V_3 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
return 0 ;
}
static int T_3 F_25 ( void )
{
return F_26 ( V_61 ,
F_2 ( V_61 ) ) ;
}
static void T_4 F_27 ( void )
{
F_28 ( V_61 ,
F_2 ( V_61 ) ) ;
}
