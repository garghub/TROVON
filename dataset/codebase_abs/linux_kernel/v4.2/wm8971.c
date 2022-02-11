static int F_1 ( int V_1 , int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( V_4 [ V_3 ] . V_2 == V_2 && V_4 [ V_3 ] . V_1 == V_1 )
return V_3 ;
}
return - V_5 ;
}
static int F_3 ( struct V_6 * V_7 ,
int V_8 , unsigned int V_9 , int V_10 )
{
struct V_11 * V_12 = V_7 -> V_12 ;
struct V_13 * V_14 = F_4 ( V_12 ) ;
switch ( V_9 ) {
case 11289600 :
case 12000000 :
case 12288000 :
case 16934400 :
case 18432000 :
V_14 -> V_15 = V_9 ;
return 0 ;
}
return - V_5 ;
}
static int F_5 ( struct V_6 * V_7 ,
unsigned int V_16 )
{
struct V_11 * V_12 = V_7 -> V_12 ;
T_1 V_17 = 0 ;
switch ( V_16 & V_18 ) {
case V_19 :
V_17 = 0x0040 ;
break;
case V_20 :
break;
default:
return - V_5 ;
}
switch ( V_16 & V_21 ) {
case V_22 :
V_17 |= 0x0002 ;
break;
case V_23 :
break;
case V_24 :
V_17 |= 0x0001 ;
break;
case V_25 :
V_17 |= 0x0003 ;
break;
case V_26 :
V_17 |= 0x0013 ;
break;
default:
return - V_5 ;
}
switch ( V_16 & V_27 ) {
case V_28 :
break;
case V_29 :
V_17 |= 0x0090 ;
break;
case V_30 :
V_17 |= 0x0080 ;
break;
case V_31 :
V_17 |= 0x0010 ;
break;
default:
return - V_5 ;
}
F_6 ( V_12 , V_32 , V_17 ) ;
return 0 ;
}
static int F_7 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
struct V_6 * V_37 )
{
struct V_11 * V_12 = V_37 -> V_12 ;
struct V_13 * V_14 = F_4 ( V_12 ) ;
T_1 V_17 = F_8 ( V_12 , V_32 ) & 0x1f3 ;
T_1 V_38 = F_8 ( V_12 , V_39 ) & 0x1c0 ;
int V_40 = F_1 ( V_14 -> V_15 , F_9 ( V_36 ) ) ;
switch ( F_10 ( V_36 ) ) {
case 16 :
break;
case 20 :
V_17 |= 0x0004 ;
break;
case 24 :
V_17 |= 0x0008 ;
break;
case 32 :
V_17 |= 0x000c ;
break;
}
F_6 ( V_12 , V_32 , V_17 ) ;
if ( V_40 >= 0 )
F_6 ( V_12 , V_39 , V_38 |
( V_4 [ V_40 ] . V_41 << 1 ) | V_4 [ V_40 ] . V_42 ) ;
return 0 ;
}
static int F_11 ( struct V_6 * V_37 , int V_43 )
{
struct V_11 * V_12 = V_37 -> V_12 ;
T_1 V_44 = F_8 ( V_12 , V_45 ) & 0xfff7 ;
if ( V_43 )
F_6 ( V_12 , V_45 , V_44 | 0x8 ) ;
else
F_6 ( V_12 , V_45 , V_44 ) ;
return 0 ;
}
static void F_12 ( struct V_46 * V_47 )
{
struct V_13 * V_14 =
F_13 ( V_47 , struct V_13 , V_48 . V_47 ) ;
F_14 ( V_14 -> V_49 , V_50 , 0x0180 , 0x0100 ) ;
}
static int F_15 ( struct V_11 * V_12 ,
enum V_51 V_52 )
{
struct V_13 * V_14 = F_4 ( V_12 ) ;
T_1 V_53 = F_8 ( V_12 , V_50 ) & 0xfe3e ;
switch ( V_52 ) {
case V_54 :
F_6 ( V_12 , V_50 , V_53 | 0x00c1 ) ;
break;
case V_55 :
F_16 ( & V_14 -> V_48 ) ;
break;
case V_56 :
if ( F_17 ( V_12 ) == V_57 ) {
F_18 ( V_12 ) ;
F_6 ( V_12 , V_50 , V_53 | 0x01c0 ) ;
F_19 ( V_58 ,
& V_14 -> V_48 , F_20 ( 1000 ) ) ;
} else {
F_6 ( V_12 , V_50 , V_53 | 0x0140 ) ;
}
break;
case V_57 :
F_21 ( & V_14 -> V_48 ) ;
F_6 ( V_12 , V_50 , 0x0001 ) ;
break;
}
return 0 ;
}
static int F_22 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_4 ( V_12 ) ;
F_23 ( & V_14 -> V_48 , F_12 ) ;
F_24 ( V_12 ) ;
F_25 ( V_12 , V_59 , 0x0100 , 0x0100 ) ;
F_25 ( V_12 , V_60 , 0x0100 , 0x0100 ) ;
F_25 ( V_12 , V_61 , 0x0100 , 0x0100 ) ;
F_25 ( V_12 , V_62 , 0x0100 , 0x0100 ) ;
F_25 ( V_12 , V_63 , 0x0100 , 0x0100 ) ;
F_25 ( V_12 , V_64 , 0x0100 , 0x0100 ) ;
F_25 ( V_12 , V_65 , 0x0100 , 0x0100 ) ;
F_25 ( V_12 , V_66 , 0x0100 , 0x0100 ) ;
return 0 ;
}
static int F_26 ( struct V_67 * V_68 ,
const struct V_69 * V_70 )
{
struct V_13 * V_14 ;
int V_71 ;
V_14 = F_27 ( & V_68 -> V_72 , sizeof( struct V_13 ) ,
V_73 ) ;
if ( V_14 == NULL )
return - V_74 ;
V_14 -> V_49 = F_28 ( V_68 , & V_75 ) ;
if ( F_29 ( V_14 -> V_49 ) )
return F_30 ( V_14 -> V_49 ) ;
F_31 ( V_68 , V_14 ) ;
V_71 = F_32 ( & V_68 -> V_72 ,
& V_76 , & V_77 , 1 ) ;
return V_71 ;
}
static int F_33 ( struct V_67 * V_78 )
{
F_34 ( & V_78 -> V_72 ) ;
return 0 ;
}
