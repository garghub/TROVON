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
F_4 ( V_2 , V_13 , 0xd003 ) ;
F_4 ( V_2 , V_6 , 0x791b ) ;
F_4 ( V_2 , V_11 , 0x10e3 ) ;
F_4 ( V_2 , 0x21 , 0x2 , 0x87f6 ) ;
F_4 ( V_2 , 0x22 , 0x2 , 0x017d ) ;
F_4 ( V_2 , 0x26 , 0x2 , 0x0015 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_1 V_16 = F_10 ( V_2 -> V_17 ) ;
T_1 V_18 = F_11 ( V_2 -> V_17 ) ;
T_1 V_19 ;
int V_20 = 0 ;
if ( V_16 == 0 )
V_16 = V_2 -> V_21 & ~ V_2 -> V_22 -> V_23 ;
F_12 ( L_1 ,
F_13 ( V_2 ) , V_2 -> V_22 -> V_24 , V_16 , V_18 ) ;
F_14 ( V_2 , V_25 ) ;
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
case 0x01 :
V_20 = F_8 ( V_2 ) ;
break;
default:
break;
}
if ( V_20 )
return V_20 ;
V_20 = F_15 ( V_2 , & V_19 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_16 ( V_2 , V_19 == V_26 ) ;
if ( V_20 )
return V_20 ;
return F_17 ( V_2 , true ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_20 ;
V_20 = F_9 ( V_2 ) ;
if ( V_20 )
return V_20 ;
return F_19 ( V_2 ) ;
}
static int F_20 ( struct V_1 * V_27 , int V_28 ,
int V_29 , int V_30 )
{
int V_31 , V_20 ;
V_31 = F_14 ( V_27 , V_28 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 &= ~ V_30 ;
V_31 |= V_29 ;
V_20 = F_5 ( V_27 , V_28 , V_31 ) ;
if ( V_20 < 0 )
return V_20 ;
return V_31 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_20 ;
V_20 = F_20 ( V_2 , V_32 ,
V_33 , 0 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_5 ( V_2 , V_34 , 0x3BE0 ) ;
if ( V_20 < 0 )
goto V_35;
V_20 = F_5 ( V_2 , V_36 ,
V_37 ) ;
if ( V_20 < 0 )
goto V_35;
V_20 = F_20 ( V_2 , V_38 ,
V_39 , 0 ) ;
if ( V_20 < 0 )
goto V_35;
V_20 = F_5 ( V_2 , V_36 ,
V_37 ) ;
if ( V_20 < 0 )
goto V_35;
V_20 = F_20 ( V_2 , V_38 ,
0 , V_39 ) ;
if ( V_20 < 0 )
goto V_35;
V_35:
V_20 = F_20 ( V_2 , V_32 , 0 ,
V_33 ) ;
if ( V_20 < 0 )
return V_20 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_20 ;
V_20 = F_20 ( V_2 , V_40 ,
V_41 , 0 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_20 ( V_2 , V_42 ,
V_43 , 0 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_20 ( V_2 , V_40 , 0 ,
V_41 ) ;
if ( V_20 < 0 )
return V_20 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_20 ;
V_20 = F_20 ( V_2 , V_32 ,
V_33 , 0 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_5 ( V_2 , V_36 ,
V_44 ) ;
if ( V_20 < 0 )
goto V_35;
V_20 = F_5 ( V_2 , V_38 ,
V_45 ) ;
if ( V_20 < 0 )
goto V_35;
V_20 = F_5 ( V_2 , V_36 ,
V_46 ) ;
if ( V_20 < 0 )
goto V_35;
V_20 = F_5 ( V_2 , V_38 ,
V_47 ) ;
if ( V_20 < 0 )
goto V_35;
V_20 = F_5 ( V_2 , V_36 ,
V_48 ) ;
if ( V_20 < 0 )
goto V_35;
V_20 = F_5 ( V_2 , V_38 ,
V_49 ) ;
if ( V_20 < 0 )
goto V_35;
V_20 = F_5 ( V_2 , V_36 ,
V_50 ) ;
if ( V_20 < 0 )
goto V_35;
V_20 = F_5 ( V_2 , V_38 ,
( V_51 | V_52 ) ) ;
if ( V_20 < 0 )
goto V_35;
V_35:
V_20 = F_20 ( V_2 , V_32 , 0 ,
V_33 ) ;
if ( V_20 < 0 )
return V_20 ;
F_5 ( V_2 , V_53 ,
( V_54 | V_55 | V_56 ) ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
T_1 V_16 = V_2 -> V_21 & ~ V_2 -> V_22 -> V_23 ;
int V_20 = 0 ;
F_12 ( L_2 ,
F_13 ( V_2 ) , V_2 -> V_22 -> V_24 , V_16 ) ;
F_14 ( V_2 , V_25 ) ;
if ( V_16 == 0x01 ) {
V_20 = F_21 ( V_2 ) ;
if ( V_20 )
return V_20 ;
}
V_20 = F_23 ( V_2 ) ;
if ( V_20 )
return V_20 ;
return F_22 ( V_2 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_20 ;
V_20 = F_24 ( V_2 ) ;
if ( V_20 )
return V_20 ;
return F_19 ( V_2 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_20 ;
F_5 ( V_2 , V_57 , V_58 ) ;
F_14 ( V_2 , V_57 ) ;
V_20 = F_20 ( V_2 , V_32 ,
V_33 , V_33 ) ;
if ( V_20 < 0 )
return V_20 ;
F_5 ( V_2 , V_59 , 0x0F00 ) ;
F_27 ( 10 ) ;
F_5 ( V_2 , V_59 , 0x0C00 ) ;
F_5 ( V_2 , V_60 , 0x7555 ) ;
V_20 = F_20 ( V_2 , V_32 , 0 , V_33 ) ;
if ( V_20 < 0 )
return V_20 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_20 ;
static const struct V_61 {
int V_62 ;
T_2 V_63 ;
} V_64 [] = {
{ V_32 , 0x008b } ,
{ V_65 , 0x01c0 } ,
{ V_59 , 0x7000 } ,
{ V_32 , 0x000f } ,
{ V_65 , 0x20d0 } ,
{ V_32 , 0x000b } ,
} ;
unsigned int V_66 ;
for ( V_66 = 0 ; V_66 < F_29 ( V_64 ) ; V_66 ++ ) {
V_20 = F_5 ( V_2 ,
V_64 [ V_66 ] . V_62 ,
V_64 [ V_66 ] . V_63 ) ;
if ( V_20 )
return V_20 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
void * V_69 )
{
switch ( V_68 -> V_70 ) {
case V_71 :
return F_15 ( V_2 , ( T_1 * ) V_69 ) ;
default:
return - V_72 ;
}
}
static int F_31 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
const void * V_69 )
{
T_1 V_19 = * ( T_1 * ) V_69 ;
int V_20 ;
switch ( V_68 -> V_70 ) {
case V_71 :
V_20 = F_32 ( V_2 , V_19 ) ;
break;
default:
return - V_72 ;
}
if ( V_20 )
return V_20 ;
V_20 = F_16 ( V_2 , V_19 == V_26 ) ;
if ( V_20 )
return V_20 ;
return F_33 ( V_2 ) ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_73 * V_74 , T_3 * V_69 )
{
struct V_75 * V_76 = V_2 -> V_76 ;
F_35 ( V_2 , V_76 -> V_74 , V_74 , V_69 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_75 * V_76 ;
V_76 = F_37 ( & V_2 -> V_77 . V_27 , sizeof( * V_76 ) , V_78 ) ;
if ( ! V_76 )
return - V_79 ;
V_2 -> V_76 = V_76 ;
V_76 -> V_74 = F_38 ( & V_2 -> V_77 . V_27 ,
F_39 ( V_2 ) , sizeof( T_3 ) ,
V_78 ) ;
if ( ! V_76 -> V_74 )
return - V_79 ;
return 0 ;
}
