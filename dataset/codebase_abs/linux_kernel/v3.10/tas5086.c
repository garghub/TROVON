static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return ! ( ( V_3 == 0x0f ) || ( V_3 >= 0x11 && V_3 <= 0x17 ) ) ;
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
return true ;
}
return false ;
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_1 ( V_2 , V_3 ) && ( V_3 != V_4 ) ;
}
static int F_4 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_5 ( V_7 ) ;
int V_10 , V_11 = 0 ;
if ( V_9 -> V_12 )
for ( V_10 = 0 ; V_10 < F_6 ( V_13 ) ; V_10 ++ )
if ( V_13 [ V_10 ] == V_9 -> V_14 )
V_11 = V_10 ;
return F_7 ( V_9 -> V_15 , V_16 ,
V_17 , V_11 ) ;
}
static int F_8 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_6 * V_7 = F_9 ( V_19 ) ;
struct V_8 * V_9 = F_5 ( V_7 ) ;
V_21 -> V_22 . V_23 . V_24 [ 0 ] = V_9 -> V_12 ;
return 0 ;
}
static int F_10 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_6 * V_7 = F_9 ( V_19 ) ;
struct V_8 * V_9 = F_5 ( V_7 ) ;
V_9 -> V_12 = V_21 -> V_22 . V_23 . V_24 [ 0 ] ;
return F_4 ( V_7 ) ;
}
static int F_11 ( struct V_25 * V_26 ,
int V_27 , unsigned int V_28 , int V_29 )
{
struct V_6 * V_7 = V_26 -> V_7 ;
struct V_8 * V_9 = F_5 ( V_7 ) ;
switch ( V_27 ) {
case V_30 :
V_9 -> V_31 = V_28 ;
break;
case V_32 :
V_9 -> V_33 = V_28 ;
break;
}
return 0 ;
}
static int F_12 ( struct V_25 * V_26 ,
unsigned int V_34 )
{
struct V_6 * V_7 = V_26 -> V_7 ;
struct V_8 * V_9 = F_5 ( V_7 ) ;
if ( ( V_34 & V_35 ) != V_36 ) {
F_13 ( V_7 -> V_2 , L_1 ) ;
return - V_37 ;
}
V_9 -> V_34 = V_34 ;
return 0 ;
}
static int F_14 ( const int * V_38 , int V_39 , int V_40 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_39 ; V_10 ++ )
if ( V_38 [ V_10 ] == V_40 )
return V_10 ;
return - V_41 ;
}
static int F_15 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
struct V_25 * V_46 )
{
struct V_6 * V_7 = V_46 -> V_7 ;
struct V_8 * V_9 = F_5 ( V_7 ) ;
int V_11 ;
int V_47 ;
V_9 -> V_14 = F_16 ( V_45 ) ;
V_11 = F_14 ( V_48 ,
F_6 ( V_48 ) , V_9 -> V_14 ) ;
if ( V_11 < 0 ) {
F_13 ( V_7 -> V_2 , L_2 ) ;
return - V_37 ;
}
V_47 = F_7 ( V_9 -> V_15 , V_49 ,
V_50 ,
F_17 ( V_11 ) ) ;
if ( V_47 < 0 )
return V_47 ;
V_11 = F_14 ( V_51 , F_6 ( V_51 ) ,
V_9 -> V_31 / V_9 -> V_14 ) ;
if ( V_11 < 0 ) {
F_13 ( V_7 -> V_2 , L_3 ) ;
return - V_37 ;
}
V_47 = F_7 ( V_9 -> V_15 , V_49 ,
V_52 ,
F_18 ( V_11 ) ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_7 ( V_9 -> V_15 , V_49 ,
V_53 ,
( V_9 -> V_33 == 48 * V_9 -> V_14 ) ?
V_53 : 0 ) ;
if ( V_47 < 0 )
return V_47 ;
switch ( V_9 -> V_34 & V_54 ) {
case V_55 :
V_11 = 0x00 ;
break;
case V_56 :
V_11 = 0x03 ;
break;
case V_57 :
V_11 = 0x06 ;
break;
default:
F_13 ( V_7 -> V_2 , L_4 ) ;
return - V_37 ;
}
switch ( F_19 ( V_45 ) ) {
case V_58 :
V_11 += 0 ;
break;
case V_59 :
V_11 += 1 ;
break;
case V_60 :
V_11 += 2 ;
break;
default:
F_13 ( V_7 -> V_2 , L_5 ) ;
return - V_37 ;
} ;
V_47 = F_20 ( V_9 -> V_15 , V_61 , V_11 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_7 ( V_9 -> V_15 , V_49 ,
V_62 , V_62 ) ;
if ( V_47 < 0 )
return V_47 ;
return F_4 ( V_7 ) ;
}
static int F_21 ( struct V_25 * V_46 , int V_63 , int V_64 )
{
struct V_6 * V_7 = V_46 -> V_7 ;
struct V_8 * V_9 = F_5 ( V_7 ) ;
unsigned int V_11 = 0 ;
if ( V_63 )
V_11 = V_65 ;
return F_20 ( V_9 -> V_15 , V_66 , V_11 ) ;
}
static int F_22 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_5 ( V_7 ) ;
return F_23 ( V_9 -> V_15 ) ;
}
static int F_24 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_5 ( V_7 ) ;
int V_67 = 1300000 ;
int V_10 , V_47 ;
if ( F_25 ( F_26 ( V_68 ) , V_7 -> V_2 ) ) {
struct V_69 * V_70 = V_7 -> V_2 -> V_70 ;
F_27 ( V_70 , L_6 , & V_67 ) ;
}
if ( V_67 == 0 ) {
F_20 ( V_9 -> V_15 , V_71 , 0 ) ;
} else {
V_10 = F_14 ( V_72 ,
F_6 ( V_72 ) ,
V_67 ) ;
if ( V_10 >= 0 )
F_20 ( V_9 -> V_15 , V_71 ,
V_10 + 0x08 ) ;
else
F_28 ( V_7 -> V_2 ,
L_7 ,
V_67 ) ;
}
V_47 = F_20 ( V_9 -> V_15 , V_73 , 0x00 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_20 ( V_9 -> V_15 , V_74 , 0x20 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_20 ( V_9 -> V_15 , V_75 , 0x30 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_20 ( V_9 -> V_15 , V_66 ,
V_65 ) ;
if ( V_47 < 0 )
return V_47 ;
return 0 ;
}
static int F_29 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_5 ( V_7 ) ;
if ( F_30 ( V_9 -> V_76 ) )
F_31 ( V_9 -> V_76 , 0 ) ;
return 0 ;
}
static int F_32 ( struct V_77 * V_78 ,
const struct V_79 * V_80 )
{
struct V_8 * V_9 ;
struct V_1 * V_2 = & V_78 -> V_2 ;
int V_76 = - V_37 ;
int V_10 , V_47 ;
V_9 = F_33 ( V_2 , sizeof( * V_9 ) , V_81 ) ;
if ( ! V_9 )
return - V_82 ;
V_9 -> V_15 = F_34 ( V_78 , & V_83 ) ;
if ( F_35 ( V_9 -> V_15 ) ) {
V_47 = F_36 ( V_9 -> V_15 ) ;
F_13 ( & V_78 -> V_2 , L_8 , V_47 ) ;
return V_47 ;
}
F_37 ( V_78 , V_9 ) ;
if ( F_25 ( F_26 ( V_68 ) , V_2 ) ) {
struct V_69 * V_70 = V_2 -> V_70 ;
V_76 = F_38 ( V_70 , L_9 , 0 ) ;
}
if ( F_30 ( V_76 ) )
if ( F_39 ( V_2 , V_76 , L_10 ) )
V_76 = - V_37 ;
if ( F_30 ( V_76 ) ) {
F_40 ( V_76 , 0 ) ;
F_41 ( 1 ) ;
F_31 ( V_76 , 1 ) ;
F_42 ( 15 ) ;
}
V_9 -> V_76 = V_76 ;
V_47 = F_43 ( V_9 -> V_15 , V_4 , & V_10 ) ;
if ( V_47 < 0 )
return V_47 ;
if ( V_10 != 0x3 ) {
F_13 ( V_2 ,
L_11 , V_10 ) ;
return - V_84 ;
}
return F_44 ( & V_78 -> V_2 , & V_85 ,
& V_86 , 1 ) ;
}
static int F_45 ( struct V_77 * V_78 )
{
F_46 ( & V_78 -> V_2 ) ;
return 0 ;
}
