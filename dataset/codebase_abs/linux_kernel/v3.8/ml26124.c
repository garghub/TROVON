static inline int F_1 ( int V_1 )
{
int V_2 ;
switch ( V_1 ) {
case 16000 :
V_2 = 3 ;
break;
case 32000 :
V_2 = 6 ;
break;
case 48000 :
V_2 = 8 ;
break;
default:
return - V_3 ;
}
return V_2 ;
}
static inline int F_2 ( int V_4 , int V_1 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < F_3 ( V_6 ) ; V_5 ++ ) {
if ( V_6 [ V_5 ] . V_1 == V_1 && V_6 [ V_5 ] . V_4 == V_4 )
return V_5 ;
}
return - V_3 ;
}
static int F_4 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_15 * V_16 = F_5 ( V_14 ) ;
int V_5 = F_2 ( V_16 -> V_4 , F_6 ( V_10 ) ) ;
V_16 -> V_8 = V_8 ;
V_16 -> V_1 = F_6 ( V_10 ) ;
if ( V_16 -> V_17 ) {
switch ( V_16 -> V_4 / F_6 ( V_10 ) ) {
case 256 :
F_7 ( V_14 , V_18 ,
F_8 ( 0 ) | F_8 ( 1 ) , 1 ) ;
break;
case 512 :
F_7 ( V_14 , V_18 ,
F_8 ( 0 ) | F_8 ( 1 ) , 2 ) ;
break;
case 1024 :
F_7 ( V_14 , V_18 ,
F_8 ( 0 ) | F_8 ( 1 ) , 3 ) ;
break;
default:
F_9 ( V_14 -> V_19 , L_1 ) ;
break;
}
} else {
F_7 ( V_14 , V_18 ,
F_8 ( 0 ) | F_8 ( 1 ) , 0 ) ;
}
switch ( F_6 ( V_10 ) ) {
case 16000 :
F_7 ( V_14 , V_20 , 0xf ,
F_1 ( F_6 ( V_10 ) ) ) ;
F_7 ( V_14 , V_21 , 0xff ,
V_6 [ V_5 ] . V_22 ) ;
F_7 ( V_14 , V_23 , 0x1 ,
V_6 [ V_5 ] . V_24 ) ;
F_7 ( V_14 , V_25 , 0xff ,
V_6 [ V_5 ] . V_26 ) ;
F_7 ( V_14 , V_27 , 0x3f ,
V_6 [ V_5 ] . V_28 ) ;
F_7 ( V_14 , V_29 , 0x1f ,
V_6 [ V_5 ] . V_30 ) ;
break;
case 32000 :
F_7 ( V_14 , V_20 , 0xf ,
F_1 ( F_6 ( V_10 ) ) ) ;
F_7 ( V_14 , V_21 , 0xff ,
V_6 [ V_5 ] . V_22 ) ;
F_7 ( V_14 , V_23 , 0x1 ,
V_6 [ V_5 ] . V_24 ) ;
F_7 ( V_14 , V_25 , 0xff ,
V_6 [ V_5 ] . V_26 ) ;
F_7 ( V_14 , V_27 , 0x3f ,
V_6 [ V_5 ] . V_28 ) ;
F_7 ( V_14 , V_29 , 0x1f ,
V_6 [ V_5 ] . V_30 ) ;
break;
case 48000 :
F_7 ( V_14 , V_20 , 0xf ,
F_1 ( F_6 ( V_10 ) ) ) ;
F_7 ( V_14 , V_21 , 0xff ,
V_6 [ V_5 ] . V_22 ) ;
F_7 ( V_14 , V_23 , 0x1 ,
V_6 [ V_5 ] . V_24 ) ;
F_7 ( V_14 , V_25 , 0xff ,
V_6 [ V_5 ] . V_26 ) ;
F_7 ( V_14 , V_27 , 0x3f ,
V_6 [ V_5 ] . V_28 ) ;
F_7 ( V_14 , V_29 , 0x1f ,
V_6 [ V_5 ] . V_30 ) ;
break;
default:
F_10 ( L_2 , V_31 ) ;
return - V_3 ;
}
return 0 ;
}
static int F_11 ( struct V_11 * V_12 , int V_32 )
{
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_15 * V_16 = F_5 ( V_14 ) ;
switch ( V_16 -> V_8 -> V_33 ) {
case V_34 :
F_7 ( V_14 , V_35 , F_8 ( 0 ) , 1 ) ;
break;
case V_36 :
F_7 ( V_14 , V_35 , F_8 ( 1 ) , 2 ) ;
break;
}
if ( V_32 )
F_7 ( V_14 , V_37 , F_8 ( 4 ) ,
V_38 ) ;
else
F_7 ( V_14 , V_37 , F_8 ( 4 ) ,
V_39 ) ;
return 0 ;
}
static int F_12 ( struct V_11 * V_40 ,
unsigned int V_41 )
{
unsigned char V_42 ;
struct V_13 * V_14 = V_40 -> V_14 ;
switch ( V_41 & V_43 ) {
case V_44 :
V_42 = 1 ;
break;
case V_45 :
V_42 = 0 ;
break;
default:
return - V_3 ;
}
F_7 ( V_14 , V_46 , F_8 ( 0 ) , V_42 ) ;
switch ( V_41 & V_47 ) {
case V_48 :
break;
default:
return - V_3 ;
}
switch ( V_41 & V_49 ) {
case V_50 :
break;
default:
return - V_3 ;
}
return 0 ;
}
static int F_13 ( struct V_11 * V_40 ,
int V_51 , unsigned int V_52 , int V_53 )
{
struct V_13 * V_14 = V_40 -> V_14 ;
struct V_15 * V_16 = F_5 ( V_14 ) ;
switch ( V_51 ) {
case V_54 :
V_16 -> V_17 = V_54 ;
break;
case V_55 :
V_16 -> V_17 = V_55 ;
break;
default:
return - V_3 ;
}
V_16 -> V_4 = V_52 ;
return 0 ;
}
static int F_14 ( struct V_13 * V_14 ,
enum V_56 V_57 )
{
struct V_15 * V_16 = F_5 ( V_14 ) ;
switch ( V_57 ) {
case V_58 :
F_7 ( V_14 , V_59 ,
V_60 , V_61 ) ;
F_15 ( 100 ) ;
F_7 ( V_14 , V_59 ,
V_60 ,
V_62 | V_63 ) ;
break;
case V_64 :
break;
case V_65 :
if ( V_14 -> V_66 . V_67 == V_68 ) {
F_7 ( V_14 , V_69 ,
V_70 , V_70 ) ;
F_15 ( 500 ) ;
F_16 ( V_16 -> V_71 ) ;
}
break;
case V_68 :
F_7 ( V_14 , V_69 ,
V_70 , 0 ) ;
break;
}
V_14 -> V_66 . V_67 = V_57 ;
return 0 ;
}
static int F_17 ( struct V_13 * V_14 )
{
F_14 ( V_14 , V_68 ) ;
return 0 ;
}
static int F_18 ( struct V_13 * V_14 )
{
F_14 ( V_14 , V_65 ) ;
return 0 ;
}
static int F_19 ( struct V_13 * V_14 )
{
int V_72 ;
struct V_15 * V_16 = F_5 ( V_14 ) ;
V_14 -> V_73 = V_16 -> V_71 ;
V_72 = F_20 ( V_14 , 7 , 9 , V_74 ) ;
if ( V_72 < 0 ) {
F_9 ( V_14 -> V_19 , L_3 , V_72 ) ;
return V_72 ;
}
F_7 ( V_14 , V_75 , 0x01 , 1 ) ;
F_7 ( V_14 , V_75 , 0x01 , 0 ) ;
F_14 ( V_14 , V_65 ) ;
return 0 ;
}
static int F_21 ( struct V_76 * V_77 ,
const struct V_78 * V_79 )
{
struct V_15 * V_16 ;
int V_72 ;
V_16 = F_22 ( & V_77 -> V_19 , sizeof( * V_16 ) , V_80 ) ;
if ( ! V_16 )
return - V_81 ;
F_23 ( V_77 , V_16 ) ;
V_16 -> V_71 = F_24 ( V_77 , & V_82 ) ;
if ( F_25 ( V_16 -> V_71 ) ) {
V_72 = F_26 ( V_16 -> V_71 ) ;
F_9 ( & V_77 -> V_19 , L_4 , V_72 ) ;
return V_72 ;
}
return F_27 ( & V_77 -> V_19 ,
& V_83 , & V_84 , 1 ) ;
}
static int F_28 ( struct V_76 * V_85 )
{
F_29 ( & V_85 -> V_19 ) ;
return 0 ;
}
