static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_1 V_5 )
{
T_1 V_6 ;
int V_7 ;
F_2 ( & V_2 -> V_8 ) ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_3 , sizeof( V_6 ) , & V_6 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_11 , L_1 , V_3 ) ;
goto V_12;
}
V_6 = ( V_6 & ~ V_4 ) | ( V_5 & V_4 ) ;
V_7 = V_2 -> V_9 -> V_13 ( V_2 -> V_11 , V_3 , sizeof( V_6 ) , & V_6 ) ;
if ( V_7 < 0 )
F_3 ( V_2 -> V_11 , L_2 , V_3 ) ;
V_12:
F_4 ( & V_2 -> V_8 ) ;
return V_7 ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_1 V_6 ;
int V_7 ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_14 , sizeof( V_6 ) ,
& V_6 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_11 , L_3 ) ;
return V_7 ;
}
if ( V_6 != V_15 ) {
F_3 ( V_2 -> V_11 , L_4 ,
V_6 , V_15 ) ;
return - V_16 ;
}
return 0 ;
}
int F_6 ( struct V_1 * V_2 , bool V_17 )
{
T_1 V_5 = V_17 ? F_7 ( 2 ) : 0 ;
int V_7 ;
V_7 = F_1 ( V_2 , V_18 ,
V_19 , V_5 ) ;
return V_7 < 0 ? V_7 : 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_20 )
{
int V_21 , V_7 ;
T_1 V_5 ;
for ( V_21 = 0 ; V_21 < F_9 ( V_22 ) ; V_21 ++ )
if ( V_22 [ V_21 ] . V_23 == V_20 )
break;
if ( V_21 == F_9 ( V_22 ) )
return - V_24 ;
V_5 = V_25 | V_26 | V_22 [ V_21 ] . V_5 ;
V_7 = F_1 ( V_2 , V_27 ,
V_28 , V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
V_2 -> V_20 = V_20 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
enum V_29 type ,
T_2 V_5 )
{
int V_21 , V_7 ;
const struct V_30 * V_31 = & V_32 [ type ] ;
for ( V_21 = 0 ; V_21 < V_33 ; V_21 ++ )
if ( V_31 -> V_34 [ V_21 ] . V_31 == V_5 )
break;
if ( V_21 == V_33 )
return - V_24 ;
V_7 = F_1 ( V_2 , V_31 -> V_3 , V_31 -> V_4 ,
V_31 -> V_34 [ V_21 ] . V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
V_2 -> V_35 [ type ] . V_36 = V_21 ;
return 0 ;
}
static T_3 F_11 ( struct V_37 * V_11 ,
struct V_38 * V_39 ,
char * V_40 )
{
int V_21 ;
T_3 V_41 = 0 ;
for ( V_21 = 0 ; V_21 < F_9 ( V_22 ) ; V_21 ++ )
V_41 += F_12 ( V_40 + V_41 , V_42 - V_41 , L_5 ,
V_22 [ V_21 ] . V_23 ) ;
V_40 [ V_41 - 1 ] = '\n' ;
return V_41 ;
}
static T_3
F_13 ( struct V_37 * V_11 ,
struct V_38 * V_39 ,
char * V_40 )
{
const struct V_30 * V_31 = & V_32 [ V_43 ] ;
T_3 V_41 = 0 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < F_9 ( V_31 -> V_34 ) ; V_21 ++ )
V_41 += F_12 ( V_40 + V_41 , V_42 - V_41 , L_5 ,
V_31 -> V_34 [ V_21 ] . V_31 ) ;
V_40 [ V_41 - 1 ] = '\n' ;
return V_41 ;
}
static T_3
F_14 ( struct V_37 * V_11 ,
struct V_38 * V_39 ,
char * V_40 )
{
const struct V_30 * V_31 = & V_32 [ V_44 ] ;
T_3 V_41 = 0 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < F_9 ( V_31 -> V_34 ) ; V_21 ++ )
V_41 += F_12 ( V_40 + V_41 , V_42 - V_41 , L_5 ,
V_31 -> V_34 [ V_21 ] . V_31 ) ;
V_40 [ V_41 - 1 ] = '\n' ;
return V_41 ;
}
int F_15 ( struct V_1 * V_2 )
{
return F_8 ( V_2 , V_2 -> V_20 ) ;
}
int F_16 ( struct V_1 * V_2 )
{
T_1 V_6 [] = { 0x00 , 0x00 } ;
return V_2 -> V_9 -> V_13 ( V_2 -> V_11 , V_27 , sizeof( V_6 ) ,
V_6 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_7 , * V_45 , * V_46 ;
T_4 V_47 , V_48 , V_49 , V_50 ;
T_1 V_51 , V_52 ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_53 ,
sizeof( V_51 ) , & V_51 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_54 ,
sizeof( V_52 ) , & V_52 ) ;
if ( V_7 < 0 )
return V_7 ;
V_49 = ( F_18 ( V_52 & 0x3 ) << 8 ) | V_51 ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_55 ,
sizeof( V_51 ) , & V_51 ) ;
if ( V_7 < 0 )
return V_7 ;
V_50 = ( ( ( V_52 & 0xc ) >> 2 ) << 8 ) | V_51 ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_56 , sizeof( V_47 ) ,
( T_1 * ) & V_47 ) ;
if ( V_7 < 0 )
return V_7 ;
V_47 = F_18 ( V_47 ) ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_57 , sizeof( V_48 ) ,
( T_1 * ) & V_48 ) ;
if ( V_7 < 0 )
return V_7 ;
V_48 = F_18 ( V_48 ) ;
V_45 = & V_2 -> V_35 [ V_44 ] . V_45 ;
V_46 = & V_2 -> V_35 [ V_44 ] . V_46 ;
* V_45 = ( ( V_50 - V_49 ) * 8000 ) / ( V_48 - V_47 ) ;
* V_46 = ( ( ( V_58 ) V_48 * V_49 - ( V_58 ) V_47 * V_50 ) * 1000 ) /
( V_48 - V_47 ) ;
* V_46 *= 8 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_7 , * V_45 , * V_46 ;
T_4 V_47 , V_48 , V_49 , V_50 ;
T_1 V_6 ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_59 , sizeof( V_6 ) ,
& V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
V_49 = V_6 ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_60 , sizeof( V_6 ) ,
& V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
V_50 = V_6 ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_61 , sizeof( V_47 ) ,
( T_1 * ) & V_47 ) ;
if ( V_7 < 0 )
return V_7 ;
V_47 = F_18 ( V_47 ) ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_62 , sizeof( V_48 ) ,
( T_1 * ) & V_48 ) ;
if ( V_7 < 0 )
return V_7 ;
V_48 = F_18 ( V_48 ) ;
V_45 = & V_2 -> V_35 [ V_43 ] . V_45 ;
V_46 = & V_2 -> V_35 [ V_43 ] . V_46 ;
* V_45 = ( ( V_50 - V_49 ) * 8000 ) / ( V_48 - V_47 ) ;
* V_46 = ( ( ( V_58 ) V_48 * V_49 - ( V_58 ) V_47 * V_50 ) * 1000 ) /
( V_48 - V_47 ) ;
* V_46 *= 8 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
enum V_63 V_64 ,
int * V_5 , int * V_65 )
{
T_5 V_66 ;
V_58 V_67 , div , V_6 ;
switch ( V_64 ) {
case V_68 :
V_6 = V_2 -> V_35 [ V_43 ] . V_45 ;
div = ( 1 << 4 ) * 1000 ;
break;
case V_69 :
V_6 = V_2 -> V_35 [ V_44 ] . V_45 ;
div = ( 1 << 6 ) * 1000 ;
break;
default:
return - V_24 ;
}
V_66 = F_21 ( V_6 * 1000000000LL , div ) ;
V_66 = F_22 ( V_66 , 1000000000LL , & V_67 ) ;
* V_5 = V_66 ;
* V_65 = V_67 ;
return V_70 ;
}
static int F_23 ( struct V_1 * V_2 ,
enum V_63 V_64 ,
int * V_5 , int * V_65 )
{
T_5 V_66 ;
V_58 V_67 , div , V_6 ;
switch ( V_64 ) {
case V_68 :
V_6 = V_2 -> V_35 [ V_43 ] . V_46 ;
div = V_2 -> V_35 [ V_43 ] . V_45 ;
break;
case V_69 :
V_6 = V_2 -> V_35 [ V_44 ] . V_46 ;
div = V_2 -> V_35 [ V_44 ] . V_45 ;
break;
default:
return - V_24 ;
}
V_66 = F_21 ( V_6 * 1000000000LL , div ) ;
V_66 = F_22 ( V_66 , 1000000000LL , & V_67 ) ;
* V_5 = V_66 ;
* V_65 = V_67 ;
return V_70 ;
}
static int F_24 ( struct V_1 * V_2 , T_1 V_3 , int * V_5 )
{
T_1 V_6 [ V_71 ] ;
int V_7 ;
V_7 = F_15 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
F_25 ( 50 ) ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_3 , sizeof( V_6 ) , V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
F_16 ( V_2 ) ;
* V_5 = ( T_4 ) F_26 ( V_6 ) ;
return V_72 ;
}
static int F_27 ( struct V_73 * V_73 ,
struct V_74 const * V_75 ,
int * V_5 , int * V_65 , long V_4 )
{
struct V_1 * V_2 = F_28 ( V_73 ) ;
int V_76 ;
V_76 = F_29 ( V_73 ) ;
if ( V_76 )
return V_76 ;
switch ( V_4 ) {
case V_77 :
V_76 = F_24 ( V_2 , V_75 -> V_78 , V_5 ) ;
break;
case V_79 :
V_76 = F_20 ( V_2 , V_75 -> type , V_5 , V_65 ) ;
break;
case V_80 :
V_76 = F_23 ( V_2 , V_75 -> type , V_5 , V_65 ) ;
break;
case V_81 :
* V_5 = V_2 -> V_20 ;
V_76 = V_72 ;
break;
case V_82 : {
T_1 V_83 ;
const struct V_30 * V_31 ;
switch ( V_75 -> type ) {
case V_68 :
V_31 = & V_32 [ V_43 ] ;
V_83 = V_2 -> V_35 [ V_43 ] . V_36 ;
* V_5 = V_31 -> V_34 [ V_83 ] . V_31 ;
V_76 = V_72 ;
break;
case V_69 :
V_31 = & V_32 [ V_44 ] ;
V_83 = V_2 -> V_35 [ V_44 ] . V_36 ;
* V_5 = V_31 -> V_34 [ V_83 ] . V_31 ;
V_76 = V_72 ;
break;
default:
V_76 = - V_24 ;
break;
}
break;
}
default:
V_76 = - V_24 ;
break;
}
F_30 ( V_73 ) ;
return V_76 ;
}
static int F_31 ( struct V_73 * V_73 ,
struct V_74 const * V_84 ,
int V_5 , int V_65 , long V_4 )
{
struct V_1 * V_2 = F_28 ( V_73 ) ;
int V_76 ;
V_76 = F_29 ( V_73 ) ;
if ( V_76 )
return V_76 ;
switch ( V_4 ) {
case V_81 :
V_76 = F_8 ( V_2 , V_5 ) ;
break;
case V_82 :
switch ( V_84 -> type ) {
case V_68 :
V_76 = F_10 ( V_2 , V_43 , V_5 ) ;
break;
case V_69 :
V_76 = F_10 ( V_2 , V_44 , V_5 ) ;
break;
default:
V_76 = - V_24 ;
break;
}
break;
default:
V_76 = - V_24 ;
break;
}
F_30 ( V_73 ) ;
return V_76 ;
}
static int F_32 ( struct V_73 * V_73 ,
struct V_85 * V_86 )
{
struct V_1 * V_2 = F_28 ( V_73 ) ;
return V_2 -> V_86 == V_86 ? 0 : - V_24 ;
}
int F_33 ( struct V_73 * V_73 )
{
struct V_1 * V_2 = F_28 ( V_73 ) ;
int V_7 ;
T_1 V_6 ;
F_34 ( & V_2 -> V_8 ) ;
V_7 = F_5 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_2 -> V_20 = V_22 [ 0 ] . V_23 ;
V_73 -> V_87 = V_88 ;
V_73 -> V_11 . V_89 = V_2 -> V_11 ;
V_73 -> V_90 = V_91 ;
V_73 -> V_92 = V_93 ;
V_73 -> V_94 = F_9 ( V_93 ) ;
V_73 -> V_95 = V_96 ;
V_73 -> V_97 = & V_98 ;
V_7 = F_19 ( V_2 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_11 , L_6 ) ;
return V_7 ;
}
V_6 = V_32 [ V_43 ] . V_34 [ 3 ] . V_31 ;
V_7 = F_10 ( V_2 , V_43 , V_6 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_11 , L_7 ) ;
return V_7 ;
}
V_7 = F_17 ( V_2 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_11 ,
L_8 ) ;
return V_7 ;
}
V_6 = V_32 [ V_44 ] . V_34 [ 3 ] . V_31 ;
V_7 = F_10 ( V_2 , V_44 , V_6 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_11 ,
L_9 ) ;
return V_7 ;
}
if ( V_2 -> V_99 > 0 ) {
V_7 = F_35 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_36 ( V_2 ) ;
if ( V_7 )
return V_7 ;
}
return F_37 ( V_2 -> V_11 , V_73 ) ;
}
