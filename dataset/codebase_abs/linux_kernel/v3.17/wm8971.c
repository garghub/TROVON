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
static int F_12 ( struct V_11 * V_12 ,
enum V_46 V_47 )
{
T_1 V_48 = F_8 ( V_12 , V_49 ) & 0xfe3e ;
switch ( V_47 ) {
case V_50 :
F_6 ( V_12 , V_49 , V_48 | 0x00c1 ) ;
break;
case V_51 :
break;
case V_52 :
if ( V_12 -> V_53 . V_54 == V_55 )
F_13 ( V_12 ) ;
F_6 ( V_12 , V_49 , V_48 | 0x0140 ) ;
break;
case V_55 :
F_6 ( V_12 , V_49 , 0x0001 ) ;
break;
}
V_12 -> V_53 . V_54 = V_47 ;
return 0 ;
}
static void F_14 ( struct V_56 * V_57 )
{
struct V_58 * V_53 =
F_15 ( V_57 , struct V_58 ,
V_59 . V_57 ) ;
struct V_11 * V_12 = V_53 -> V_12 ;
F_12 ( V_12 , V_12 -> V_53 . V_54 ) ;
}
static int F_16 ( struct V_11 * V_12 )
{
F_12 ( V_12 , V_55 ) ;
return 0 ;
}
static int F_17 ( struct V_11 * V_12 )
{
T_1 V_60 ;
F_12 ( V_12 , V_52 ) ;
if ( V_12 -> V_53 . V_61 == V_50 ) {
V_60 = F_8 ( V_12 , V_49 ) & 0xfe3e ;
F_6 ( V_12 , V_49 , V_60 | 0x01c0 ) ;
V_12 -> V_53 . V_54 = V_50 ;
F_18 ( V_62 , & V_12 -> V_53 . V_59 ,
F_19 ( 1000 ) ) ;
}
return 0 ;
}
static int F_20 ( struct V_11 * V_12 )
{
int V_63 = 0 ;
T_1 V_60 ;
F_21 ( & V_12 -> V_53 . V_59 , F_14 ) ;
V_62 = F_22 ( L_1 ) ;
if ( V_62 == NULL )
return - V_64 ;
F_23 ( V_12 ) ;
V_60 = F_8 ( V_12 , V_49 ) & 0xfe3e ;
F_6 ( V_12 , V_49 , V_60 | 0x01c0 ) ;
V_12 -> V_53 . V_54 = V_52 ;
F_18 ( V_62 , & V_12 -> V_53 . V_59 ,
F_19 ( 1000 ) ) ;
F_24 ( V_12 , V_65 , 0x0100 , 0x0100 ) ;
F_24 ( V_12 , V_66 , 0x0100 , 0x0100 ) ;
F_24 ( V_12 , V_67 , 0x0100 , 0x0100 ) ;
F_24 ( V_12 , V_68 , 0x0100 , 0x0100 ) ;
F_24 ( V_12 , V_69 , 0x0100 , 0x0100 ) ;
F_24 ( V_12 , V_70 , 0x0100 , 0x0100 ) ;
F_24 ( V_12 , V_71 , 0x0100 , 0x0100 ) ;
F_24 ( V_12 , V_72 , 0x0100 , 0x0100 ) ;
return V_63 ;
}
static int F_25 ( struct V_11 * V_12 )
{
F_12 ( V_12 , V_55 ) ;
if ( V_62 )
F_26 ( V_62 ) ;
return 0 ;
}
static int F_27 ( struct V_73 * V_74 ,
const struct V_75 * V_76 )
{
struct V_13 * V_14 ;
struct V_77 * V_77 ;
int V_63 ;
V_14 = F_28 ( & V_74 -> V_78 , sizeof( struct V_13 ) ,
V_79 ) ;
if ( V_14 == NULL )
return - V_64 ;
V_77 = F_29 ( V_74 , & V_80 ) ;
if ( F_30 ( V_77 ) )
return F_31 ( V_77 ) ;
F_32 ( V_74 , V_14 ) ;
V_63 = F_33 ( & V_74 -> V_78 ,
& V_81 , & V_82 , 1 ) ;
return V_63 ;
}
static int F_34 ( struct V_73 * V_83 )
{
F_35 ( & V_83 -> V_78 ) ;
return 0 ;
}
