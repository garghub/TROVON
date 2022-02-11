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
return F_10 ( ( V_22 ) V_8 , 100 ) ;
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
return ( V_8 >> 3 ) * 4 ;
case V_30 :
return V_8 >> 8 ;
case V_31 :
return - 1 * ( V_8 >> 8 ) ;
case V_32 :
case V_33 :
case V_34 :
case V_35 :
return V_8 * 20 * 1000L ;
case V_36 :
return ( V_22 ) V_8 ;
}
F_11 ( 1 ) ;
return 0 ;
}
static int F_12 ( T_2 V_16 , T_3 V_37 , long V_8 )
{
switch ( V_16 ) {
case V_20 :
case V_21 :
return F_13 ( V_8 , - 320 , 320 ) * 100 ;
case V_26 :
case V_27 :
case V_28 :
case V_29 :
return ( F_10 ( F_13 ( V_8 , 0 , 32000 ) , 4 ) << 3 )
| ( V_37 & 0x7 ) ;
case V_31 :
return ( F_13 ( - V_8 , 0 , 255 ) << 8 ) | ( V_37 & 0xff ) ;
case V_30 :
return ( F_13 ( V_8 , 0 , 255 ) << 8 ) | ( V_37 & 0xff ) ;
case V_34 :
case V_35 :
return F_10 ( V_8 , 20 * 1000 ) ;
}
return - V_38 ;
}
static int F_14 ( T_3 V_16 )
{
return 68 >> ( 15 - ( ( V_16 >> 3 ) & 0x0f ) ) ;
}
static T_3 F_15 ( T_3 V_39 , long V_40 )
{
int V_9 , V_41 ;
if ( V_40 <= 0 ) {
V_41 = 8 ;
} else {
V_41 = 15 ;
for ( V_9 = 34 + 34 / 2 ; V_9 ; V_9 >>= 1 ) {
if ( V_9 < V_40 )
break;
V_41 -- ;
}
}
return ( V_39 & 0xf807 ) | ( V_41 << 3 ) | ( V_41 << 7 ) ;
}
static T_4 F_16 ( struct V_2 * V_3 ,
struct V_42 * V_43 ,
const char * V_44 , T_5 V_45 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
long V_8 ;
T_3 V_46 ;
int V_7 ;
if ( F_17 ( V_4 ) )
return F_18 ( V_4 ) ;
V_7 = F_19 ( V_44 , 10 , & V_8 ) ;
if ( V_7 < 0 )
return V_7 ;
F_3 ( & V_4 -> V_10 ) ;
V_46 = F_15 ( V_4 -> V_15 [ V_47 ] ,
V_8 ) ;
F_20 ( V_4 -> V_6 , V_47 ,
V_46 ) ;
V_4 -> V_15 [ V_47 ] = V_46 ;
V_4 -> V_14 = F_14 ( V_46 ) ;
F_8 ( & V_4 -> V_10 ) ;
return V_45 ;
}
static T_4 F_21 ( struct V_2 * V_3 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
return snprintf ( V_44 , V_48 , L_1 , V_4 -> V_14 ) ;
}
static T_4 F_22 ( struct V_2 * V_3 ,
struct V_42 * V_43 ,
const char * V_44 ,
T_5 V_45 )
{
struct V_49 * V_50 = F_23 ( V_43 ) ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_6 V_51 = V_50 -> V_52 ;
long V_8 ;
int V_9 , V_7 ;
V_7 = F_19 ( V_44 , 10 , & V_8 ) ;
if ( V_7 < 0 )
return V_7 ;
F_3 ( & V_4 -> V_10 ) ;
for ( V_9 = 0 ; V_9 < F_5 ( V_53 ) ; V_9 ++ ) {
if ( V_51 & ( 1 << V_9 ) )
F_20 ( V_6 ,
V_53 [ V_9 ] , 1 ) ;
}
V_4 -> V_11 = false ;
F_8 ( & V_4 -> V_10 ) ;
return V_45 ;
}
static T_4 F_24 ( struct V_2 * V_3 ,
struct V_42 * V_43 ,
const char * V_44 ,
T_5 V_45 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_49 * V_50 = F_23 ( V_43 ) ;
int V_16 = V_50 -> V_52 ;
long V_8 ;
int V_7 ;
if ( F_17 ( V_4 ) )
return F_18 ( V_4 ) ;
V_7 = F_19 ( V_44 , 10 , & V_8 ) ;
if ( V_7 < 0 )
return V_7 ;
F_3 ( & V_4 -> V_10 ) ;
V_7 = F_12 ( V_16 , V_4 -> V_15 [ V_16 ] , V_8 ) ;
if ( V_7 < 0 ) {
V_45 = V_7 ;
goto abort;
}
F_20 ( V_4 -> V_6 , V_16 , V_7 ) ;
V_4 -> V_15 [ V_16 ] = V_7 ;
abort:
F_8 ( & V_4 -> V_10 ) ;
return V_45 ;
}
static T_4 F_25 ( struct V_2 * V_3 ,
struct V_42 * V_43 ,
char * V_44 )
{
struct V_49 * V_50 = F_23 ( V_43 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
long V_8 ;
if ( F_17 ( V_4 ) )
return F_18 ( V_4 ) ;
V_8 = F_9 ( V_50 -> V_52 , V_4 -> V_15 [ V_50 -> V_52 ] ) ;
return snprintf ( V_44 , V_48 , L_2 , V_8 ) ;
}
static T_4 F_26 ( struct V_2 * V_3 ,
struct V_42 * V_43 ,
char * V_44 )
{
struct V_49 * V_50 = F_23 ( V_43 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
const unsigned int V_51 = V_50 -> V_52 ;
T_3 V_54 ;
if ( F_17 ( V_4 ) )
return F_18 ( V_4 ) ;
V_54 = V_4 -> V_15 [ V_55 ] ;
return snprintf ( V_44 , V_48 , L_3 , ! ! ( V_54 & V_51 ) ) ;
}
static void F_27 ( struct V_5 * V_6 ,
struct V_1 * V_4 )
{
F_20 ( V_6 , V_47 ,
V_4 -> V_56 ) ;
F_20 ( V_6 , V_57 ,
V_4 -> V_58 ) ;
}
static int F_28 ( struct V_5 * V_6 ,
struct V_1 * V_4 )
{
struct V_59 * V_60 = F_29 ( & V_6 -> V_3 ) ;
T_6 V_61 ;
int V_16 ;
V_16 = F_6 ( V_6 , V_57 ) ;
if ( V_16 < 0 )
return V_16 ;
V_4 -> V_58 = V_16 ;
V_16 = F_6 ( V_6 , V_47 ) ;
if ( V_16 < 0 )
return V_16 ;
V_4 -> V_56 = V_16 ;
if ( V_60 ) {
if ( V_60 -> V_62 <= 0 )
return - V_63 ;
V_61 = V_60 -> V_62 ;
} else if ( ! F_30 ( V_6 -> V_3 . V_64 , L_4 ,
& V_61 ) ) {
if ( V_61 == 0 )
return - V_63 ;
} else {
V_61 = V_4 -> V_58 ?
40960000 / V_4 -> V_58 : V_65 ;
}
F_20 ( V_6 , V_47 ,
V_66 ) ;
V_4 -> V_14 = F_14 ( V_66 ) ;
F_20 ( V_6 , V_57 ,
F_13 ( 40960000 / V_61 , 1 , 65535 ) ) ;
F_6 ( V_6 , V_55 ) ;
return 0 ;
}
static int F_31 ( struct V_5 * V_6 ,
const struct V_67 * V_68 )
{
struct V_69 * V_70 = V_6 -> V_70 ;
struct V_1 * V_4 ;
struct V_2 * V_71 ;
int V_7 ;
if ( ! F_32 ( V_70 , V_72 ) )
return - V_73 ;
V_4 = F_33 ( & V_6 -> V_3 , sizeof( * V_4 ) , V_74 ) ;
if ( ! V_4 )
return - V_75 ;
F_34 ( V_6 , V_4 ) ;
V_4 -> V_6 = V_6 ;
F_35 ( & V_4 -> V_10 ) ;
V_7 = F_28 ( V_6 , V_4 ) ;
if ( V_7 )
return V_7 ;
V_71 = F_36 ( & V_6 -> V_3 ,
V_6 -> V_76 ,
V_4 , V_77 ) ;
if ( F_17 ( V_71 ) ) {
V_7 = F_18 ( V_71 ) ;
goto V_78;
}
return 0 ;
V_78:
F_27 ( V_6 , V_4 ) ;
return V_7 ;
}
static int F_37 ( struct V_5 * V_6 )
{
struct V_1 * V_4 = F_38 ( V_6 ) ;
F_27 ( V_6 , V_4 ) ;
return 0 ;
}
