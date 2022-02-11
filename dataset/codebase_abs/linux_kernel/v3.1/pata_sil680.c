static unsigned long F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned long V_4 = 0xA0 + V_3 ;
V_4 += ( V_2 -> V_5 << 4 ) ;
return V_4 ;
}
static unsigned long F_2 ( struct V_1 * V_2 , struct V_6 * V_7 , int V_3 )
{
unsigned long V_4 = 0xA0 + V_3 ;
V_4 += ( V_2 -> V_5 << 4 ) ;
V_4 |= V_7 -> V_8 ? 2 : 0 ;
return V_4 ;
}
static int F_3 ( struct V_1 * V_2 ) {
struct V_9 * V_10 = F_4 ( V_2 -> V_11 -> V_12 ) ;
unsigned long V_13 = F_1 ( V_2 , 0 ) ;
T_1 V_14 ;
F_5 ( V_10 , V_13 , & V_14 ) ;
if ( V_14 & 1 )
return V_15 ;
else
return V_16 ;
}
static void F_6 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
static T_2 V_17 [ 5 ] = { 0x328A , 0x2283 , 0x1104 , 0x10C3 , 0x10C1 } ;
static T_2 V_18 [ 5 ] = { 0x328A , 0x2283 , 0x1281 , 0x10C3 , 0x10C1 } ;
unsigned long V_19 = F_1 ( V_2 , 0x02 ) ;
unsigned long V_13 = F_2 ( V_2 , V_7 , 0x04 ) ;
unsigned long V_20 = 0x80 + 4 * V_2 -> V_5 ;
struct V_9 * V_10 = F_4 ( V_2 -> V_11 -> V_12 ) ;
int V_21 = V_7 -> V_22 - V_23 ;
int V_24 = V_21 ;
int V_25 = 4 * V_7 -> V_8 ;
T_2 V_26 ;
T_1 V_27 ;
struct V_6 * V_28 = F_7 ( V_7 ) ;
if ( V_28 != NULL && V_7 -> V_22 > V_28 -> V_22 )
V_24 = V_28 -> V_22 - V_23 ;
F_8 ( V_10 , V_13 , V_17 [ V_21 ] ) ;
F_8 ( V_10 , V_19 , V_18 [ V_24 ] ) ;
F_9 ( V_10 , V_19 - 2 , & V_26 ) ;
F_5 ( V_10 , V_20 , & V_27 ) ;
V_26 &= ~ 0x0200 ;
V_27 &= ~ ( 3 << V_25 ) ;
if ( F_10 ( V_7 ) ) {
V_26 |= 0x0200 ;
V_27 |= 1 << V_25 ;
}
F_8 ( V_10 , V_19 - 2 , V_26 ) ;
F_11 ( V_10 , V_20 , V_27 ) ;
}
static void F_12 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
static T_1 V_29 [ 2 ] [ 7 ] = {
{ 0x0C , 0x07 , 0x05 , 0x04 , 0x02 , 0x01 , 0xFF } ,
{ 0x0F , 0x0B , 0x07 , 0x05 , 0x03 , 0x02 , 0x01 } ,
} ;
static T_2 V_30 [ 3 ] = { 0x2208 , 0x10C2 , 0x10C1 } ;
struct V_9 * V_10 = F_4 ( V_2 -> V_11 -> V_12 ) ;
unsigned long V_31 = F_2 ( V_2 , V_7 , 0x08 ) ;
unsigned long V_32 = F_2 ( V_2 , V_7 , 0x0C ) ;
unsigned long V_20 = 0x80 + 4 * V_2 -> V_5 ;
int V_25 = V_7 -> V_8 * 4 ;
T_1 V_33 , V_27 ;
T_2 V_34 , V_35 ;
F_5 ( V_10 , 0x8A , & V_33 ) ;
F_5 ( V_10 , V_20 , & V_27 ) ;
F_9 ( V_10 , V_31 , & V_34 ) ;
F_9 ( V_10 , V_32 , & V_35 ) ;
V_35 &= ~ 0x3F ;
V_27 &= ~ ( 0x03 << V_25 ) ;
V_33 = ( V_33 & 0x30 ) ? 1 : 0 ;
if ( V_7 -> V_36 >= V_37 ) {
V_34 = 0x10C1 ;
V_35 |= V_29 [ V_33 ] [ V_7 -> V_36 - V_37 ] ;
V_27 |= ( 0x03 << V_25 ) ;
} else {
V_34 = V_30 [ V_7 -> V_36 - V_38 ] ;
V_27 |= ( 0x02 << V_25 ) ;
}
F_11 ( V_10 , V_20 , V_27 ) ;
F_8 ( V_10 , V_31 , V_34 ) ;
F_8 ( V_10 , V_32 , V_35 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
const struct V_39 * V_40 )
{
F_14 ( L_1 , V_2 -> V_41 , V_40 -> V_42 ) ;
F_15 ( V_40 -> V_42 , V_2 -> V_43 . V_44 ) ;
F_16 ( V_2 -> V_43 . V_45 + V_46 ) ;
}
static bool F_17 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 -> V_11 -> V_12 ) ;
unsigned long V_13 = F_1 ( V_2 , 1 ) ;
T_1 V_47 ;
F_5 ( V_10 , V_13 , & V_47 ) ;
return V_47 & 0x08 ;
}
static T_1 F_18 ( struct V_9 * V_10 , int * V_48 )
{
T_1 V_49 = 0 ;
F_11 ( V_10 , V_50 ,
V_10 -> V_51 ? 1 : 255 ) ;
F_11 ( V_10 , 0x80 , 0x00 ) ;
F_11 ( V_10 , 0x84 , 0x00 ) ;
F_5 ( V_10 , 0x8A , & V_49 ) ;
F_19 ( & V_10 -> V_12 , L_2 ,
V_49 & 1 , V_49 & 0x30 ) ;
* V_48 = 0 ;
#ifdef F_20
if ( F_21 ( V_52 ) )
* V_48 = ( V_49 & 1 ) || F_22 ( V_10 , 5 ) ;
#endif
switch( V_49 & 0x30 ) {
case 0x00 :
F_11 ( V_10 , 0x8A , V_49 | 0x10 ) ;
break;
case 0x30 :
F_11 ( V_10 , 0x8A , V_49 & ~ 0x20 ) ;
break;
case 0x10 :
break;
case 0x20 :
break;
}
F_5 ( V_10 , 0x8A , & V_49 ) ;
F_19 ( & V_10 -> V_12 , L_2 ,
V_49 & 1 , V_49 & 0x30 ) ;
F_11 ( V_10 , 0xA1 , 0x72 ) ;
F_8 ( V_10 , 0xA2 , 0x328A ) ;
F_23 ( V_10 , 0xA4 , 0x62DD62DD ) ;
F_23 ( V_10 , 0xA8 , 0x43924392 ) ;
F_23 ( V_10 , 0xAC , 0x40094009 ) ;
F_11 ( V_10 , 0xB1 , 0x72 ) ;
F_8 ( V_10 , 0xB2 , 0x328A ) ;
F_23 ( V_10 , 0xB4 , 0x62DD62DD ) ;
F_23 ( V_10 , 0xB8 , 0x43924392 ) ;
F_23 ( V_10 , 0xBC , 0x40094009 ) ;
switch( V_49 & 0x30 ) {
case 0x00 : F_24 ( V_53 L_3 ) ; break;
case 0x10 : F_24 ( V_53 L_4 ) ; break;
case 0x20 : F_24 ( V_53 L_5 ) ; break;
case 0x30 : F_24 ( V_54 L_6 ) ;
}
return V_49 & 0x30 ;
}
static int T_3 F_25 ( struct V_9 * V_10 ,
const struct V_55 * V_56 )
{
static const struct V_57 V_58 = {
. V_59 = V_60 ,
. V_61 = V_62 ,
. V_63 = V_64 ,
. V_65 = V_66 ,
. V_67 = & V_68
} ;
static const struct V_57 V_69 = {
. V_59 = V_60 ,
. V_61 = V_62 ,
. V_63 = V_64 ,
. V_65 = V_70 ,
. V_67 = & V_68
} ;
const struct V_57 * V_71 [] = { & V_58 , NULL } ;
struct V_72 * V_11 ;
void T_4 * V_73 ;
int V_74 , V_48 ;
F_26 ( & V_10 -> V_12 , V_75 ) ;
V_74 = F_27 ( V_10 ) ;
if ( V_74 )
return V_74 ;
switch ( F_18 ( V_10 , & V_48 ) ) {
case 0 :
V_71 [ 0 ] = & V_69 ;
break;
case 0x30 :
return - V_76 ;
}
if ( ! V_48 )
goto V_77;
V_74 = F_28 ( V_10 , 1 << V_78 , V_79 ) ;
if ( V_74 )
goto V_77;
V_11 = F_29 ( & V_10 -> V_12 , V_71 , 2 ) ;
if ( ! V_11 )
return - V_80 ;
V_11 -> V_81 = F_30 ( V_10 ) ;
V_74 = F_31 ( V_10 , V_82 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_32 ( V_10 , V_82 ) ;
if ( V_74 )
return V_74 ;
F_33 ( V_10 ) ;
V_73 = V_11 -> V_81 [ V_78 ] ;
V_11 -> V_83 [ 0 ] -> V_43 . V_45 = V_73 + 0x00 ;
V_11 -> V_83 [ 0 ] -> V_43 . V_84 = V_73 + 0x80 ;
V_11 -> V_83 [ 0 ] -> V_43 . V_85 = V_73 + 0x8a ;
V_11 -> V_83 [ 0 ] -> V_43 . V_86 = V_73 + 0x8a ;
F_34 ( & V_11 -> V_83 [ 0 ] -> V_43 ) ;
V_11 -> V_83 [ 1 ] -> V_43 . V_45 = V_73 + 0x08 ;
V_11 -> V_83 [ 1 ] -> V_43 . V_84 = V_73 + 0xc0 ;
V_11 -> V_83 [ 1 ] -> V_43 . V_85 = V_73 + 0xca ;
V_11 -> V_83 [ 1 ] -> V_43 . V_86 = V_73 + 0xca ;
F_34 ( & V_11 -> V_83 [ 1 ] -> V_43 ) ;
return F_35 ( V_11 , V_10 -> V_87 , V_88 ,
V_89 , & V_90 ) ;
V_77:
return F_36 ( V_10 , V_71 , & V_90 , NULL , 0 ) ;
}
static int F_37 ( struct V_9 * V_10 )
{
struct V_72 * V_11 = F_38 ( & V_10 -> V_12 ) ;
int V_48 , V_74 ;
V_74 = F_39 ( V_10 ) ;
if ( V_74 )
return V_74 ;
F_18 ( V_10 , & V_48 ) ;
F_40 ( V_11 ) ;
return 0 ;
}
static int T_5 F_41 ( void )
{
return F_42 ( & V_91 ) ;
}
static void T_6 F_43 ( void )
{
F_44 ( & V_91 ) ;
}
