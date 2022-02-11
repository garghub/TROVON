static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_1 * V_7 = V_4 ;
T_1 V_8 ;
int V_9 ;
F_3 ( & V_4 -> V_10 ) ;
if ( ! V_4 -> V_11 ||
F_4 ( V_12 , V_4 -> V_13 + V_4 -> V_14 ) ) {
for ( V_9 = 0 ; V_9 < F_5 ( V_4 -> V_15 ) ; V_9 ++ ) {
V_8 = F_6 ( V_6 , V_9 ) ;
if ( V_8 < 0 ) {
V_7 = F_7 ( V_8 ) ;
goto abort;
}
V_4 -> V_15 [ V_9 ] = V_8 ;
}
V_4 -> V_13 = V_12 ;
V_4 -> V_11 = true ;
}
abort:
F_8 ( & V_4 -> V_10 ) ;
return V_7 ;
}
static long F_9 ( const T_2 V_16 , const T_3 V_8 )
{
switch ( V_16 ) {
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
return F_10 ( V_8 , 100 ) ;
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
return ( V_8 >> 3 ) * 4 ;
case V_29 :
return V_8 >> 8 ;
case V_30 :
return - 1 * ( V_8 >> 8 ) ;
case V_31 :
case V_32 :
case V_33 :
case V_34 :
return V_8 * 20 * 1000L ;
case V_35 :
return V_8 ;
}
F_11 ( 1 ) ;
return 0 ;
}
static int F_12 ( T_2 V_16 , T_3 V_36 , long V_8 )
{
switch ( V_16 ) {
case V_20 :
case V_21 :
return F_13 ( V_8 , - 320 , 320 ) * 100 ;
case V_25 :
case V_26 :
case V_27 :
case V_28 :
return ( F_10 ( F_13 ( V_8 , 0 , 32000 ) , 4 ) << 3 )
| ( V_36 & 0x7 ) ;
case V_30 :
return ( F_13 ( - V_8 , 0 , 255 ) << 8 ) | ( V_36 & 0xff ) ;
case V_29 :
return ( F_13 ( V_8 , 0 , 255 ) << 8 ) | ( V_36 & 0xff ) ;
case V_33 :
case V_34 :
return F_10 ( V_8 , 20 * 1000 ) ;
}
return - V_37 ;
}
static int F_14 ( T_3 V_16 )
{
return 68 >> ( 15 - ( ( V_16 >> 3 ) & 0x0f ) ) ;
}
static T_3 F_15 ( T_3 V_38 , long V_39 )
{
int V_9 , V_40 ;
if ( V_39 <= 0 ) {
V_40 = 8 ;
} else {
V_40 = 15 ;
for ( V_9 = 34 + 34 / 2 ; V_9 ; V_9 >>= 1 ) {
if ( V_9 < V_39 )
break;
V_40 -- ;
}
}
return ( V_38 & 0xf807 ) | ( V_40 << 3 ) | ( V_40 << 7 ) ;
}
static T_4 F_16 ( struct V_2 * V_3 ,
struct V_41 * V_42 ,
const char * V_43 , T_5 V_44 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
long V_8 ;
T_3 V_45 ;
int V_7 ;
if ( F_17 ( V_4 ) )
return F_18 ( V_4 ) ;
V_7 = F_19 ( V_43 , 10 , & V_8 ) ;
if ( V_7 < 0 )
return V_7 ;
F_3 ( & V_4 -> V_10 ) ;
V_45 = F_15 ( V_4 -> V_15 [ V_46 ] ,
V_8 ) ;
F_20 ( V_4 -> V_6 , V_46 ,
V_45 ) ;
V_4 -> V_15 [ V_46 ] = V_45 ;
V_4 -> V_14 = F_14 ( V_45 ) ;
F_8 ( & V_4 -> V_10 ) ;
return V_44 ;
}
static T_4 F_21 ( struct V_2 * V_3 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
return snprintf ( V_43 , V_47 , L_1 , V_4 -> V_14 ) ;
}
static T_4 F_22 ( struct V_2 * V_3 ,
struct V_41 * V_42 ,
const char * V_43 ,
T_5 V_44 )
{
struct V_48 * V_49 = F_23 ( V_42 ) ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_6 V_50 = V_49 -> V_51 ;
long V_8 ;
int V_9 , V_7 ;
V_7 = F_19 ( V_43 , 10 , & V_8 ) ;
if ( V_7 < 0 )
return V_7 ;
F_3 ( & V_4 -> V_10 ) ;
for ( V_9 = 0 ; V_9 < F_5 ( V_52 ) ; V_9 ++ ) {
if ( V_50 & ( 1 << V_9 ) )
F_20 ( V_6 ,
V_52 [ V_9 ] , 1 ) ;
}
V_4 -> V_11 = false ;
F_8 ( & V_4 -> V_10 ) ;
return V_44 ;
}
static T_4 F_24 ( struct V_2 * V_3 ,
struct V_41 * V_42 ,
const char * V_43 ,
T_5 V_44 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_48 * V_49 = F_23 ( V_42 ) ;
int V_16 = V_49 -> V_51 ;
long V_8 ;
int V_7 ;
if ( F_17 ( V_4 ) )
return F_18 ( V_4 ) ;
V_7 = F_19 ( V_43 , 10 , & V_8 ) ;
if ( V_7 < 0 )
return V_7 ;
F_3 ( & V_4 -> V_10 ) ;
V_7 = F_12 ( V_16 , V_4 -> V_15 [ V_16 ] , V_8 ) ;
if ( V_7 < 0 ) {
V_44 = V_7 ;
goto abort;
}
F_20 ( V_4 -> V_6 , V_16 , V_7 ) ;
V_4 -> V_15 [ V_16 ] = V_7 ;
abort:
F_8 ( & V_4 -> V_10 ) ;
return V_44 ;
}
static T_4 F_25 ( struct V_2 * V_3 ,
struct V_41 * V_42 ,
char * V_43 )
{
struct V_48 * V_49 = F_23 ( V_42 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
long V_8 ;
if ( F_17 ( V_4 ) )
return F_18 ( V_4 ) ;
V_8 = F_9 ( V_49 -> V_51 , V_4 -> V_15 [ V_49 -> V_51 ] ) ;
return snprintf ( V_43 , V_47 , L_2 , V_8 ) ;
}
static T_4 F_26 ( struct V_2 * V_3 ,
struct V_41 * V_42 ,
char * V_43 )
{
struct V_48 * V_49 = F_23 ( V_42 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
const unsigned int V_50 = V_49 -> V_51 ;
T_3 V_53 ;
if ( F_17 ( V_4 ) )
return F_18 ( V_4 ) ;
V_53 = V_4 -> V_15 [ V_54 ] ;
return snprintf ( V_43 , V_47 , L_3 , ! ! ( V_53 & V_50 ) ) ;
}
static void F_27 ( struct V_5 * V_6 ,
struct V_1 * V_4 )
{
F_20 ( V_6 , V_46 ,
V_4 -> V_55 ) ;
F_20 ( V_6 , V_56 ,
V_4 -> V_57 ) ;
}
static int F_28 ( struct V_5 * V_6 ,
struct V_1 * V_4 )
{
struct V_58 * V_59 = F_29 ( & V_6 -> V_3 ) ;
T_6 V_60 ;
int V_16 ;
V_16 = F_6 ( V_6 , V_56 ) ;
if ( V_16 < 0 )
return V_16 ;
V_4 -> V_57 = V_16 ;
V_16 = F_6 ( V_6 , V_46 ) ;
if ( V_16 < 0 )
return V_16 ;
V_4 -> V_55 = V_16 ;
if ( V_59 ) {
if ( V_59 -> V_61 <= 0 )
return - V_62 ;
V_60 = V_59 -> V_61 ;
} else if ( ! F_30 ( V_6 -> V_3 . V_63 , L_4 ,
& V_60 ) ) {
if ( V_60 == 0 )
return - V_62 ;
} else {
V_60 = V_4 -> V_57 ?
40960000 / V_4 -> V_57 : V_64 ;
}
F_20 ( V_6 , V_46 ,
V_65 ) ;
V_4 -> V_14 = F_14 ( V_65 ) ;
F_20 ( V_6 , V_56 ,
F_13 ( 40960000 / V_60 , 1 , 65535 ) ) ;
F_6 ( V_6 , V_54 ) ;
return 0 ;
}
static int F_31 ( struct V_5 * V_6 ,
const struct V_66 * V_67 )
{
struct V_68 * V_69 = V_6 -> V_69 ;
struct V_1 * V_4 ;
struct V_2 * V_70 ;
int V_7 ;
if ( ! F_32 ( V_69 , V_71 ) )
return - V_72 ;
V_4 = F_33 ( & V_6 -> V_3 , sizeof( * V_4 ) , V_73 ) ;
if ( ! V_4 )
return - V_74 ;
F_34 ( V_6 , V_4 ) ;
V_4 -> V_6 = V_6 ;
F_35 ( & V_4 -> V_10 ) ;
V_7 = F_28 ( V_6 , V_4 ) ;
if ( V_7 )
return V_7 ;
V_70 = F_36 ( & V_6 -> V_3 ,
V_6 -> V_75 ,
V_4 , V_76 ) ;
if ( F_17 ( V_70 ) ) {
V_7 = F_18 ( V_70 ) ;
goto V_77;
}
return 0 ;
V_77:
F_27 ( V_6 , V_4 ) ;
return V_7 ;
}
static int F_37 ( struct V_5 * V_6 )
{
struct V_1 * V_4 = F_38 ( V_6 ) ;
F_27 ( V_6 , V_4 ) ;
return 0 ;
}
