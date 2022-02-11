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
int V_2 ;
if ( V_5 < 0 )
return V_5 ;
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
V_2 = F_1 ( F_6 ( V_10 ) ) ;
if ( V_2 < 0 )
return V_2 ;
F_7 ( V_14 , V_20 , 0xf , V_2 ) ;
F_7 ( V_14 , V_21 , 0xff , V_6 [ V_5 ] . V_22 ) ;
F_7 ( V_14 , V_23 , 0x1 , V_6 [ V_5 ] . V_24 ) ;
F_7 ( V_14 , V_25 , 0xff , V_6 [ V_5 ] . V_26 ) ;
F_7 ( V_14 , V_27 , 0x3f , V_6 [ V_5 ] . V_28 ) ;
F_7 ( V_14 , V_29 , 0x1f , V_6 [ V_5 ] . V_30 ) ;
return 0 ;
}
static int F_10 ( struct V_11 * V_12 , int V_31 )
{
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_15 * V_16 = F_5 ( V_14 ) ;
switch ( V_16 -> V_8 -> V_32 ) {
case V_33 :
F_7 ( V_14 , V_34 , F_8 ( 0 ) , 1 ) ;
break;
case V_35 :
F_7 ( V_14 , V_34 , F_8 ( 1 ) , 2 ) ;
break;
}
if ( V_31 )
F_7 ( V_14 , V_36 , F_8 ( 4 ) ,
V_37 ) ;
else
F_7 ( V_14 , V_36 , F_8 ( 4 ) ,
V_38 ) ;
return 0 ;
}
static int F_11 ( struct V_11 * V_39 ,
unsigned int V_40 )
{
unsigned char V_41 ;
struct V_13 * V_14 = V_39 -> V_14 ;
switch ( V_40 & V_42 ) {
case V_43 :
V_41 = 1 ;
break;
case V_44 :
V_41 = 0 ;
break;
default:
return - V_3 ;
}
F_7 ( V_14 , V_45 , F_8 ( 0 ) , V_41 ) ;
switch ( V_40 & V_46 ) {
case V_47 :
break;
default:
return - V_3 ;
}
switch ( V_40 & V_48 ) {
case V_49 :
break;
default:
return - V_3 ;
}
return 0 ;
}
static int F_12 ( struct V_11 * V_39 ,
int V_50 , unsigned int V_51 , int V_52 )
{
struct V_13 * V_14 = V_39 -> V_14 ;
struct V_15 * V_16 = F_5 ( V_14 ) ;
switch ( V_50 ) {
case V_53 :
V_16 -> V_17 = V_53 ;
break;
case V_54 :
V_16 -> V_17 = V_54 ;
break;
default:
return - V_3 ;
}
V_16 -> V_4 = V_51 ;
return 0 ;
}
static int F_13 ( struct V_13 * V_14 ,
enum V_55 V_56 )
{
struct V_15 * V_16 = F_5 ( V_14 ) ;
switch ( V_56 ) {
case V_57 :
F_7 ( V_14 , V_58 ,
V_59 , V_60 ) ;
F_14 ( 100 ) ;
F_7 ( V_14 , V_58 ,
V_59 ,
V_61 | V_62 ) ;
break;
case V_63 :
break;
case V_64 :
if ( F_15 ( V_14 ) == V_65 ) {
F_7 ( V_14 , V_66 ,
V_67 , V_67 ) ;
F_14 ( 500 ) ;
F_16 ( V_16 -> V_68 ) ;
}
break;
case V_65 :
F_7 ( V_14 , V_66 ,
V_67 , 0 ) ;
break;
}
return 0 ;
}
static int F_17 ( struct V_13 * V_14 )
{
F_7 ( V_14 , V_69 , 0x01 , 1 ) ;
F_7 ( V_14 , V_69 , 0x01 , 0 ) ;
return 0 ;
}
static int F_18 ( struct V_70 * V_71 ,
const struct V_72 * V_73 )
{
struct V_15 * V_16 ;
int V_74 ;
V_16 = F_19 ( & V_71 -> V_19 , sizeof( * V_16 ) , V_75 ) ;
if ( ! V_16 )
return - V_76 ;
F_20 ( V_71 , V_16 ) ;
V_16 -> V_68 = F_21 ( V_71 , & V_77 ) ;
if ( F_22 ( V_16 -> V_68 ) ) {
V_74 = F_23 ( V_16 -> V_68 ) ;
F_9 ( & V_71 -> V_19 , L_2 , V_74 ) ;
return V_74 ;
}
return F_24 ( & V_71 -> V_19 ,
& V_78 , & V_79 , 1 ) ;
}
static int F_25 ( struct V_70 * V_80 )
{
F_26 ( & V_80 -> V_19 ) ;
return 0 ;
}
