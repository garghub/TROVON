static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 , V_8 , V_9 ;
int V_10 ;
if ( ! V_4 -> V_11 ) {
V_4 -> V_12 [ 0 ] = V_4 -> V_13 [ V_14 - 0x10 ] ;
return;
}
if ( F_3 ( V_15 , V_4 -> V_16 + 5 * V_17 ) ) {
F_4 ( & V_6 -> V_2 , L_1 ) ;
for ( V_10 = 0 ; V_10 < F_5 ( V_4 -> V_12 ) ; V_10 ++ )
V_4 -> V_12 [ V_10 ] = - V_18 ;
}
V_7 = ( V_4 -> V_19 [ V_20 ] & 0xc0 ) >> 6 ;
if ( V_7 > 0 )
V_7 -= 1 ;
V_4 -> V_12 [ V_7 ] = V_4 -> V_13 [ V_14 - 0x10 ] ;
V_8 = ( V_7 + 1 ) % F_5 ( V_4 -> V_12 ) ;
V_9 = ( V_4 -> V_19 [ V_20 ] & 0x3f ) | ( ( V_8 + 1 ) << 6 ) ;
F_6 ( V_6 , V_20 , V_9 ) ;
V_4 -> V_19 [ V_20 ] = V_9 ;
}
static struct V_3 * F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_2 V_21 ;
int V_10 ;
F_8 ( & V_4 -> V_22 ) ;
if ( F_3 ( V_15 , V_4 -> V_16 + V_17 ) || ! V_4 -> V_23 ) {
F_4 ( & V_6 -> V_2 , L_2 ) ;
for ( V_10 = 0 ; V_10 < F_5 ( V_4 -> V_19 ) ; V_10 ++ ) {
V_21 = F_9 ( V_6 , V_10 ) ;
if ( F_10 ( V_21 < 0 ) )
V_4 -> V_19 [ V_10 ] = 0 ;
else
V_4 -> V_19 [ V_10 ] = V_21 ;
}
for ( V_10 = 0 ; V_10 < F_5 ( V_4 -> V_13 ) ; V_10 ++ ) {
V_21 = F_9 ( V_6 , V_10 + 0x10 ) ;
if ( F_10 ( V_21 < 0 ) )
V_4 -> V_13 [ V_10 ] = 0 ;
else
V_4 -> V_13 [ V_10 ] = V_21 ;
}
F_1 ( V_2 ) ;
V_4 -> V_16 = V_15 ;
V_4 -> V_23 = 1 ;
}
F_11 ( & V_4 -> V_22 ) ;
return V_4 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_3 * V_4 = F_7 ( V_2 ) ;
const T_1 V_25 = V_4 -> V_13 [ V_24 - 0x10 ] ;
T_3 V_26 = 0 ;
switch ( V_24 ) {
case V_27 :
case V_28 :
V_26 = V_25 * 55 ;
break;
case V_29 :
case V_30 :
V_26 = V_25 * 22 ;
break;
case V_31 :
case V_32 :
V_26 = V_25 * 15 ;
break;
case V_33 :
case V_34 :
V_26 = V_25 * - 55 ;
break;
case V_14 :
V_26 = V_25 * 10 ;
break;
default:
F_13 ( 1 ) ;
break;
}
return V_26 ;
}
static unsigned int F_14 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_3 * V_4 = F_7 ( V_2 ) ;
const T_1 V_25 = V_4 -> V_13 [ V_24 - 0x10 ] ;
unsigned int V_26 ;
unsigned int V_35 ;
switch ( V_24 ) {
case V_36 :
V_26 = V_25 * 250 ;
V_35 = V_26 / 50 ;
break;
case V_37 :
V_26 = V_25 * 125 ;
V_35 = ( V_26 * 10 ) / 35 ;
break;
case V_38 :
V_26 = V_25 * 125 ;
V_35 = ( V_26 * 10 ) / 25 ;
break;
case V_39 :
V_26 = V_25 * 250 ;
V_35 = V_26 / 100 ;
break;
default:
F_13 ( 1 ) ;
V_35 = 0 ;
break;
}
return V_35 ;
}
static T_4 F_15 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
char * V_42 )
{
struct V_43 * V_44 = F_16 ( V_41 ) ;
const int V_26 = F_12 ( V_2 , V_44 -> V_45 ) ;
return snprintf ( V_42 , V_46 , L_3 , V_26 ) ;
}
static T_4 F_17 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
char * V_42 )
{
struct V_43 * V_44 = F_16 ( V_41 ) ;
const unsigned int V_35 = F_14 ( V_2 , V_44 -> V_45 ) ;
return snprintf ( V_42 , V_46 , L_4 , V_35 ) ;
}
static T_4 F_18 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
char * V_42 )
{
struct V_43 * V_44 = F_16 ( V_41 ) ;
const unsigned int V_35 = F_14 ( V_2 , V_44 -> V_45 ) ;
const int V_47 = F_12 ( V_2 , V_44 -> V_45 + 1 ) ;
const unsigned int V_48 = abs ( V_47 * V_35 ) ;
return snprintf ( V_42 , V_46 , L_4 , V_48 ) ;
}
static T_4 F_19 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
char * V_42 )
{
struct V_49 * V_44 = F_20 ( V_41 ) ;
struct V_3 * V_4 = F_7 ( V_2 ) ;
const T_1 V_24 = V_4 -> V_19 [ V_44 -> V_45 ] ;
const T_3 V_50 = V_44 -> V_51 ;
return snprintf ( V_42 , V_46 , L_4 , ( V_24 & V_50 ) ? 1 : 0 ) ;
}
static T_4 F_21 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
char * V_42 )
{
struct V_43 * V_44 = F_16 ( V_41 ) ;
struct V_3 * V_4 = F_7 ( V_2 ) ;
int V_21 = V_4 -> V_12 [ V_44 -> V_45 ] ;
if ( V_21 < 0 )
return V_21 ;
return snprintf ( V_42 , V_46 , L_4 , V_21 * 10 ) ;
}
static void F_22 ( struct V_3 * V_4 )
{
V_4 -> V_52 [ 0 ] = & V_53 ;
if ( V_4 -> V_11 )
V_4 -> V_52 [ 1 ] = & V_54 ;
}
static bool F_23 ( struct V_5 * V_6 )
{
struct V_55 * V_56 = F_24 ( & V_6 -> V_2 ) ;
#ifdef F_25
struct V_57 * V_58 = V_6 -> V_2 . V_59 ;
#endif
if ( V_56 )
return V_56 -> V_11 ;
#ifdef F_25
if ( F_26 ( V_58 , L_5 , NULL ) )
return true ;
#endif
return false ;
}
static int F_27 ( struct V_5 * V_6 ,
const struct V_60 * V_61 )
{
struct V_62 * V_63 = V_6 -> V_63 ;
struct V_3 * V_4 ;
struct V_1 * V_64 ;
if ( ! F_28 ( V_63 , V_65 ) )
return - V_66 ;
V_4 = F_29 ( & V_6 -> V_2 , sizeof( * V_4 ) , V_67 ) ;
if ( ! V_4 )
return - V_68 ;
V_4 -> V_6 = V_6 ;
F_30 ( & V_4 -> V_22 ) ;
V_4 -> V_11 = F_23 ( V_6 ) ;
F_6 ( V_6 , V_69 , 0x00 ) ;
F_6 ( V_6 , V_70 , 0x00 ) ;
F_22 ( V_4 ) ;
V_64 = F_31 ( & V_6 -> V_2 ,
V_6 -> V_71 , V_4 ,
V_4 -> V_52 ) ;
if ( F_32 ( V_64 ) )
return F_33 ( V_64 ) ;
F_34 ( V_6 , V_64 ) ;
return 0 ;
}
static int F_35 ( struct V_5 * V_6 )
{
struct V_1 * V_64 = F_36 ( V_6 ) ;
F_37 ( V_64 ) ;
return 0 ;
}
