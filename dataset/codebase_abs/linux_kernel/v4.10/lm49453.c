static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_9 = 0 ;
switch ( F_2 ( V_4 ) ) {
case 8000 :
case 16000 :
case 32000 :
case 24000 :
case 48000 :
V_9 = 256 ;
break;
case 11025 :
case 22050 :
case 44100 :
V_9 = 216 ;
break;
case 96000 :
V_9 = 127 ;
break;
default:
return - V_10 ;
}
F_3 ( V_8 , V_11 , V_9 ) ;
F_3 ( V_8 , V_12 , V_9 ) ;
return 0 ;
}
static int F_4 ( struct V_5 * V_13 , unsigned int V_14 )
{
struct V_7 * V_8 = V_13 -> V_8 ;
T_1 V_15 ;
int V_16 = 0 ;
int V_17 = 0 ;
int V_18 = 0 ;
switch ( V_14 & V_19 ) {
case V_20 :
V_15 = 0 ;
break;
case V_21 :
V_15 = V_22 ;
break;
case V_23 :
V_15 = V_24 ;
break;
case V_25 :
V_15 = V_24 |
V_22 ;
break;
default:
return - V_10 ;
}
switch ( V_14 & V_26 ) {
case V_27 :
break;
case V_28 :
V_16 = 1 ;
V_17 = ( 1 << 5 ) ;
V_18 = 1 ;
break;
case V_29 :
V_16 = 1 ;
V_17 = ( 1 << 5 ) ;
V_18 = 0 ;
break;
default:
return - V_10 ;
}
F_5 ( V_8 , V_30 ,
V_31 | F_6 ( 0 ) | F_6 ( 5 ) ,
( V_15 | V_16 | V_17 ) ) ;
F_3 ( V_8 , V_32 , V_18 ) ;
return 0 ;
}
static int F_7 ( struct V_5 * V_6 , int V_33 ,
unsigned int V_34 , int V_35 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_36 = 0 ;
switch ( V_34 ) {
case 12288000 :
case 26000000 :
case 19200000 :
V_36 = 0 ;
break;
case 48000 :
case 32576 :
V_36 = F_6 ( 4 ) ;
return 0 ;
default:
return - V_10 ;
}
F_5 ( V_8 , V_37 , F_6 ( 4 ) , V_36 ) ;
return 0 ;
}
static int F_8 ( struct V_5 * V_6 , int V_38 )
{
F_5 ( V_6 -> V_8 , V_39 , F_6 ( 1 ) | F_6 ( 0 ) ,
( V_38 ? ( F_6 ( 1 ) | F_6 ( 0 ) ) : 0 ) ) ;
return 0 ;
}
static int F_9 ( struct V_5 * V_6 , int V_38 )
{
F_5 ( V_6 -> V_8 , V_39 , F_6 ( 3 ) | F_6 ( 2 ) ,
( V_38 ? ( F_6 ( 3 ) | F_6 ( 2 ) ) : 0 ) ) ;
return 0 ;
}
static int F_10 ( struct V_5 * V_6 , int V_38 )
{
F_5 ( V_6 -> V_8 , V_39 , F_6 ( 5 ) | F_6 ( 4 ) ,
( V_38 ? ( F_6 ( 5 ) | F_6 ( 4 ) ) : 0 ) ) ;
return 0 ;
}
static int F_11 ( struct V_5 * V_6 , int V_38 )
{
F_5 ( V_6 -> V_8 , V_39 , F_6 ( 4 ) ,
( V_38 ? F_6 ( 4 ) : 0 ) ) ;
return 0 ;
}
static int F_12 ( struct V_5 * V_6 , int V_38 )
{
F_5 ( V_6 -> V_8 , V_39 , F_6 ( 7 ) | F_6 ( 6 ) ,
( V_38 ? ( F_6 ( 7 ) | F_6 ( 6 ) ) : 0 ) ) ;
return 0 ;
}
static int F_13 ( struct V_7 * V_8 ,
enum V_40 V_41 )
{
struct V_42 * V_43 = F_14 ( V_8 ) ;
switch ( V_41 ) {
case V_44 :
case V_45 :
break;
case V_46 :
if ( F_15 ( V_8 ) == V_47 )
F_16 ( V_43 -> V_48 ) ;
F_5 ( V_8 , V_37 ,
V_49 , V_50 ) ;
break;
case V_47 :
F_5 ( V_8 , V_37 ,
V_49 , 0 ) ;
break;
}
return 0 ;
}
static int F_17 ( struct V_51 * V_52 ,
const struct V_53 * V_54 )
{
struct V_42 * V_43 ;
int V_55 = 0 ;
V_43 = F_18 ( & V_52 -> V_56 , sizeof( struct V_42 ) ,
V_57 ) ;
if ( V_43 == NULL )
return - V_58 ;
F_19 ( V_52 , V_43 ) ;
V_43 -> V_48 = F_20 ( V_52 , & V_59 ) ;
if ( F_21 ( V_43 -> V_48 ) ) {
V_55 = F_22 ( V_43 -> V_48 ) ;
F_23 ( & V_52 -> V_56 , L_1 ,
V_55 ) ;
return V_55 ;
}
V_55 = F_24 ( & V_52 -> V_56 ,
& V_60 ,
V_61 , F_25 ( V_61 ) ) ;
if ( V_55 < 0 )
F_23 ( & V_52 -> V_56 , L_2 , V_55 ) ;
return V_55 ;
}
static int F_26 ( struct V_51 * V_62 )
{
F_27 ( & V_62 -> V_56 ) ;
return 0 ;
}
