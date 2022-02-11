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
T_1 V_19 ;
int V_20 = 0 ;
F_11 ( L_1 ,
F_12 ( V_2 ) , V_2 -> V_21 -> V_22 , V_16 , V_18 ) ;
F_13 ( V_2 , V_23 ) ;
switch ( V_16 ) {
case 0xb0 :
V_20 = F_3 ( V_2 ) ;
break;
case 0xd0 :
V_20 = F_6 ( V_2 ) ;
break;
case 0xe0 :
case 0xf0 :
case 0x10 :
V_20 = F_7 ( V_2 ) ;
break;
default:
break;
}
if ( V_20 )
return V_20 ;
V_20 = F_14 ( V_2 , & V_19 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_15 ( V_2 , V_19 == V_24 ) ;
if ( V_20 )
return V_20 ;
return F_16 ( V_2 , true ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_20 ;
V_20 = F_8 ( V_2 ) ;
if ( V_20 )
return V_20 ;
return F_18 ( V_2 ) ;
}
static int F_19 ( struct V_1 * V_25 , int V_26 ,
int V_27 , int V_28 )
{
int V_29 , V_20 ;
V_29 = F_13 ( V_25 , V_26 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 &= ~ V_28 ;
V_29 |= V_27 ;
V_20 = F_5 ( V_25 , V_26 , V_29 ) ;
if ( V_20 < 0 )
return V_20 ;
return V_29 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_20 ;
F_5 ( V_2 , V_30 , V_31 ) ;
F_13 ( V_2 , V_30 ) ;
V_20 = F_19 ( V_2 , V_32 ,
V_33 , V_33 ) ;
if ( V_20 < 0 )
return V_20 ;
F_5 ( V_2 , V_34 , 0x0F00 ) ;
F_21 ( 10 ) ;
F_5 ( V_2 , V_34 , 0x0C00 ) ;
F_5 ( V_2 , V_35 , 0x7555 ) ;
V_20 = F_19 ( V_2 , V_32 , 0 , V_33 ) ;
if ( V_20 < 0 )
return V_20 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_20 ;
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
for ( V_41 = 0 ; V_41 < F_23 ( V_39 ) ; V_41 ++ ) {
V_20 = F_5 ( V_2 ,
V_39 [ V_41 ] . V_37 ,
V_39 [ V_41 ] . V_38 ) ;
if ( V_20 )
return V_20 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_42 * V_43 ,
void * V_44 )
{
switch ( V_43 -> V_45 ) {
case V_46 :
return F_14 ( V_2 , ( T_1 * ) V_44 ) ;
default:
return - V_47 ;
}
}
static int F_25 ( struct V_1 * V_2 ,
struct V_42 * V_43 ,
const void * V_44 )
{
T_1 V_19 = * ( T_1 * ) V_44 ;
int V_20 ;
switch ( V_43 -> V_45 ) {
case V_46 :
V_20 = F_26 ( V_2 , V_19 ) ;
break;
default:
return - V_47 ;
}
if ( V_20 )
return V_20 ;
V_20 = F_15 ( V_2 , V_19 == V_24 ) ;
if ( V_20 )
return V_20 ;
return F_27 ( V_2 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_48 * V_49 , T_3 * V_44 )
{
struct V_50 * V_51 = V_2 -> V_51 ;
F_29 ( V_2 , V_51 -> V_49 , V_49 , V_44 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_50 * V_51 ;
V_51 = F_31 ( & V_2 -> V_52 . V_25 , sizeof( * V_51 ) , V_53 ) ;
if ( ! V_51 )
return - V_54 ;
V_2 -> V_51 = V_51 ;
V_51 -> V_49 = F_32 ( & V_2 -> V_52 . V_25 ,
F_33 ( V_2 ) , sizeof( T_3 ) ,
V_53 ) ;
if ( ! V_51 -> V_49 )
return - V_54 ;
return 0 ;
}
