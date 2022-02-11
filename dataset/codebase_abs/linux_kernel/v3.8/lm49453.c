static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
T_1 V_11 = 0 ;
V_10 -> V_12 = F_3 ( V_4 ) ;
switch ( V_10 -> V_12 ) {
case 8000 :
case 16000 :
case 32000 :
case 24000 :
case 48000 :
V_11 = 256 ;
break;
case 11025 :
case 22050 :
case 44100 :
V_11 = 216 ;
break;
case 96000 :
V_11 = 127 ;
break;
default:
return - V_13 ;
}
F_4 ( V_8 , V_14 , V_11 ) ;
F_4 ( V_8 , V_15 , V_11 ) ;
return 0 ;
}
static int F_5 ( struct V_5 * V_16 , unsigned int V_17 )
{
struct V_7 * V_8 = V_16 -> V_8 ;
T_1 V_18 ;
int V_19 = 0 ;
int V_20 = 0 ;
int V_21 = 0 ;
switch ( V_17 & V_22 ) {
case V_23 :
V_18 = 0 ;
break;
case V_24 :
V_18 = V_25 ;
break;
case V_26 :
V_18 = V_27 ;
break;
case V_28 :
V_18 = V_27 |
V_25 ;
break;
default:
return - V_13 ;
}
switch ( V_17 & V_29 ) {
case V_30 :
break;
case V_31 :
V_19 = 1 ;
V_20 = ( 1 << 5 ) ;
V_21 = 1 ;
break;
case V_32 :
V_19 = 1 ;
V_20 = ( 1 << 5 ) ;
V_21 = 0 ;
break;
default:
return - V_13 ;
}
F_6 ( V_8 , V_33 ,
V_34 | F_7 ( 0 ) | F_7 ( 5 ) ,
( V_18 | V_19 | V_20 ) ) ;
F_4 ( V_8 , V_35 , V_21 ) ;
return 0 ;
}
static int F_8 ( struct V_5 * V_6 , int V_36 ,
unsigned int V_37 , int V_38 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_39 = 0 ;
switch ( V_37 ) {
case 12288000 :
case 26000000 :
case 19200000 :
V_39 = 0 ;
break;
case 48000 :
case 32576 :
V_39 = F_7 ( 4 ) ;
return 0 ;
default:
return - V_13 ;
}
F_6 ( V_8 , V_40 , F_7 ( 4 ) , V_39 ) ;
return 0 ;
}
static int F_9 ( struct V_5 * V_6 , int V_41 )
{
F_6 ( V_6 -> V_8 , V_42 , F_7 ( 1 ) | F_7 ( 0 ) ,
( V_41 ? ( F_7 ( 1 ) | F_7 ( 0 ) ) : 0 ) ) ;
return 0 ;
}
static int F_10 ( struct V_5 * V_6 , int V_41 )
{
F_6 ( V_6 -> V_8 , V_42 , F_7 ( 3 ) | F_7 ( 2 ) ,
( V_41 ? ( F_7 ( 3 ) | F_7 ( 2 ) ) : 0 ) ) ;
return 0 ;
}
static int F_11 ( struct V_5 * V_6 , int V_41 )
{
F_6 ( V_6 -> V_8 , V_42 , F_7 ( 5 ) | F_7 ( 4 ) ,
( V_41 ? ( F_7 ( 5 ) | F_7 ( 4 ) ) : 0 ) ) ;
return 0 ;
}
static int F_12 ( struct V_5 * V_6 , int V_41 )
{
F_6 ( V_6 -> V_8 , V_42 , F_7 ( 4 ) ,
( V_41 ? F_7 ( 4 ) : 0 ) ) ;
return 0 ;
}
static int F_13 ( struct V_5 * V_6 , int V_41 )
{
F_6 ( V_6 -> V_8 , V_42 , F_7 ( 7 ) | F_7 ( 6 ) ,
( V_41 ? ( F_7 ( 7 ) | F_7 ( 6 ) ) : 0 ) ) ;
return 0 ;
}
static int F_14 ( struct V_7 * V_8 ,
enum V_43 V_44 )
{
struct V_9 * V_10 = F_2 ( V_8 ) ;
switch ( V_44 ) {
case V_45 :
case V_46 :
break;
case V_47 :
if ( V_8 -> V_48 . V_49 == V_50 )
F_15 ( V_10 -> V_51 ) ;
F_6 ( V_8 , V_40 ,
V_52 , V_53 ) ;
break;
case V_50 :
F_6 ( V_8 , V_40 ,
V_52 , 0 ) ;
break;
}
V_8 -> V_48 . V_49 = V_44 ;
return 0 ;
}
static int F_16 ( struct V_7 * V_8 )
{
F_14 ( V_8 , V_50 ) ;
return 0 ;
}
static int F_17 ( struct V_7 * V_8 )
{
F_14 ( V_8 , V_47 ) ;
return 0 ;
}
static int F_18 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_8 ) ;
int V_54 = 0 ;
V_8 -> V_55 = V_10 -> V_51 ;
V_54 = F_19 ( V_8 , 8 , 8 , V_56 ) ;
if ( V_54 < 0 ) {
F_20 ( V_8 -> V_57 , L_1 , V_54 ) ;
return V_54 ;
}
return 0 ;
}
static int F_21 ( struct V_7 * V_8 )
{
F_14 ( V_8 , V_50 ) ;
return 0 ;
}
static int F_22 ( struct V_58 * V_59 ,
const struct V_60 * V_61 )
{
struct V_9 * V_10 ;
int V_54 = 0 ;
V_10 = F_23 ( & V_59 -> V_57 , sizeof( struct V_9 ) ,
V_62 ) ;
if ( V_10 == NULL )
return - V_63 ;
F_24 ( V_59 , V_10 ) ;
V_10 -> V_51 = F_25 ( V_59 , & V_64 ) ;
if ( F_26 ( V_10 -> V_51 ) ) {
V_54 = F_27 ( V_10 -> V_51 ) ;
F_20 ( & V_59 -> V_57 , L_2 ,
V_54 ) ;
return V_54 ;
}
V_54 = F_28 ( & V_59 -> V_57 ,
& V_65 ,
V_66 , F_29 ( V_66 ) ) ;
if ( V_54 < 0 )
F_20 ( & V_59 -> V_57 , L_3 , V_54 ) ;
return V_54 ;
}
static int F_30 ( struct V_58 * V_67 )
{
F_31 ( & V_67 -> V_57 ) ;
return 0 ;
}
