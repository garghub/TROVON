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
int V_7 ;
V_7 = F_8 ( V_2 , V_2 -> V_20 ) ;
if ( V_7 < 0 )
return V_7 ;
V_2 -> V_45 = true ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
T_4 V_6 = 0 ;
int V_7 ;
V_7 = V_2 -> V_9 -> V_13 ( V_2 -> V_11 , V_27 , sizeof( V_6 ) ,
( T_1 * ) & V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
V_2 -> V_45 = false ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_7 , * V_46 , * V_47 ;
T_5 V_48 , V_49 , V_50 , V_51 ;
T_1 V_52 , V_53 ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_54 ,
sizeof( V_52 ) , & V_52 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_55 ,
sizeof( V_53 ) , & V_53 ) ;
if ( V_7 < 0 )
return V_7 ;
V_50 = ( F_18 ( V_53 & 0x3 ) << 8 ) | V_52 ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_56 ,
sizeof( V_52 ) , & V_52 ) ;
if ( V_7 < 0 )
return V_7 ;
V_51 = ( ( ( V_53 & 0xc ) >> 2 ) << 8 ) | V_52 ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_57 , sizeof( V_48 ) ,
( T_1 * ) & V_48 ) ;
if ( V_7 < 0 )
return V_7 ;
V_48 = F_18 ( V_48 ) ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_58 , sizeof( V_49 ) ,
( T_1 * ) & V_49 ) ;
if ( V_7 < 0 )
return V_7 ;
V_49 = F_18 ( V_49 ) ;
V_46 = & V_2 -> V_35 [ V_44 ] . V_46 ;
V_47 = & V_2 -> V_35 [ V_44 ] . V_47 ;
* V_46 = ( ( V_51 - V_50 ) * 8000 ) / ( V_49 - V_48 ) ;
* V_47 = ( ( ( V_59 ) V_49 * V_50 - ( V_59 ) V_48 * V_51 ) * 1000 ) /
( V_49 - V_48 ) ;
* V_47 *= 8 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_7 , * V_46 , * V_47 ;
T_5 V_48 , V_49 , V_50 , V_51 ;
T_1 V_6 ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_60 , sizeof( V_6 ) ,
& V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
V_50 = V_6 ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_61 , sizeof( V_6 ) ,
& V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
V_51 = V_6 ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_62 , sizeof( V_48 ) ,
( T_1 * ) & V_48 ) ;
if ( V_7 < 0 )
return V_7 ;
V_48 = F_18 ( V_48 ) ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_63 , sizeof( V_49 ) ,
( T_1 * ) & V_49 ) ;
if ( V_7 < 0 )
return V_7 ;
V_49 = F_18 ( V_49 ) ;
V_46 = & V_2 -> V_35 [ V_43 ] . V_46 ;
V_47 = & V_2 -> V_35 [ V_43 ] . V_47 ;
* V_46 = ( ( V_51 - V_50 ) * 8000 ) / ( V_49 - V_48 ) ;
* V_47 = ( ( ( V_59 ) V_49 * V_50 - ( V_59 ) V_48 * V_51 ) * 1000 ) /
( V_49 - V_48 ) ;
* V_47 *= 8 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
enum V_64 V_65 ,
int * V_5 , int * V_66 )
{
T_6 V_67 ;
V_59 V_68 , div , V_6 ;
switch ( V_65 ) {
case V_69 :
V_6 = V_2 -> V_35 [ V_43 ] . V_46 ;
div = ( 1 << 4 ) * 1000 ;
break;
case V_70 :
V_6 = V_2 -> V_35 [ V_44 ] . V_46 ;
div = ( 1 << 6 ) * 1000 ;
break;
default:
return - V_24 ;
}
V_67 = F_21 ( V_6 * 1000000000LL , div ) ;
V_67 = F_22 ( V_67 , 1000000000LL , & V_68 ) ;
* V_5 = V_67 ;
* V_66 = V_68 ;
return V_71 ;
}
static int F_23 ( struct V_1 * V_2 ,
enum V_64 V_65 ,
int * V_5 , int * V_66 )
{
T_6 V_67 ;
V_59 V_68 , div , V_6 ;
switch ( V_65 ) {
case V_69 :
V_6 = V_2 -> V_35 [ V_43 ] . V_47 ;
div = V_2 -> V_35 [ V_43 ] . V_46 ;
break;
case V_70 :
V_6 = V_2 -> V_35 [ V_44 ] . V_47 ;
div = V_2 -> V_35 [ V_44 ] . V_46 ;
break;
default:
return - V_24 ;
}
V_67 = F_21 ( V_6 * 1000000000LL , div ) ;
V_67 = F_22 ( V_67 , 1000000000LL , & V_68 ) ;
* V_5 = V_67 ;
* V_66 = V_68 ;
return V_71 ;
}
static int F_24 ( struct V_1 * V_2 , T_1 V_3 , int * V_5 )
{
T_1 V_6 [ V_72 ] ;
int V_7 ;
V_7 = F_15 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
F_25 ( 50 ) ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_3 , sizeof( V_6 ) , V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
F_16 ( V_2 ) ;
* V_5 = ( T_5 ) F_26 ( V_6 ) ;
return V_73 ;
}
static int F_27 ( struct V_74 * V_74 ,
struct V_75 const * V_76 ,
int * V_5 , int * V_66 , long V_4 )
{
struct V_1 * V_2 = F_28 ( V_74 ) ;
int V_77 ;
V_77 = F_29 ( V_74 ) ;
if ( V_77 )
return V_77 ;
switch ( V_4 ) {
case V_78 :
V_77 = F_24 ( V_2 , V_76 -> V_79 , V_5 ) ;
break;
case V_80 :
V_77 = F_20 ( V_2 , V_76 -> type , V_5 , V_66 ) ;
break;
case V_81 :
V_77 = F_23 ( V_2 , V_76 -> type , V_5 , V_66 ) ;
break;
case V_82 :
* V_5 = V_2 -> V_20 ;
V_77 = V_73 ;
break;
case V_83 : {
T_1 V_84 ;
const struct V_30 * V_31 ;
switch ( V_76 -> type ) {
case V_69 :
V_31 = & V_32 [ V_43 ] ;
V_84 = V_2 -> V_35 [ V_43 ] . V_36 ;
* V_5 = V_31 -> V_34 [ V_84 ] . V_31 ;
V_77 = V_73 ;
break;
case V_70 :
V_31 = & V_32 [ V_44 ] ;
V_84 = V_2 -> V_35 [ V_44 ] . V_36 ;
* V_5 = V_31 -> V_34 [ V_84 ] . V_31 ;
V_77 = V_73 ;
break;
default:
V_77 = - V_24 ;
break;
}
break;
}
default:
V_77 = - V_24 ;
break;
}
F_30 ( V_74 ) ;
return V_77 ;
}
static int F_31 ( struct V_74 * V_74 ,
struct V_75 const * V_85 ,
int V_5 , int V_66 , long V_4 )
{
struct V_1 * V_2 = F_28 ( V_74 ) ;
int V_77 ;
V_77 = F_29 ( V_74 ) ;
if ( V_77 )
return V_77 ;
switch ( V_4 ) {
case V_82 :
V_77 = F_8 ( V_2 , V_5 ) ;
break;
case V_83 :
switch ( V_85 -> type ) {
case V_69 :
V_77 = F_10 ( V_2 , V_43 , V_5 ) ;
break;
case V_70 :
V_77 = F_10 ( V_2 , V_44 , V_5 ) ;
break;
default:
V_77 = - V_24 ;
break;
}
break;
default:
V_77 = - V_24 ;
break;
}
F_30 ( V_74 ) ;
return V_77 ;
}
static int F_32 ( struct V_74 * V_74 ,
struct V_86 * V_87 )
{
struct V_1 * V_2 = F_28 ( V_74 ) ;
return V_2 -> V_87 == V_87 ? 0 : - V_24 ;
}
int F_33 ( struct V_74 * V_74 )
{
struct V_1 * V_2 = F_28 ( V_74 ) ;
int V_7 ;
T_1 V_6 ;
F_34 ( & V_2 -> V_8 ) ;
V_7 = F_5 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_2 -> V_20 = V_22 [ 0 ] . V_23 ;
V_74 -> V_88 = V_89 ;
V_74 -> V_11 . V_90 = V_2 -> V_11 ;
V_74 -> V_91 = V_92 ;
V_74 -> V_93 = V_94 ;
V_74 -> V_95 = F_9 ( V_94 ) ;
V_74 -> V_96 = V_97 ;
V_74 -> V_98 = & V_99 ;
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
if ( V_2 -> V_100 > 0 ) {
V_7 = F_35 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_36 ( V_2 ) ;
if ( V_7 )
return V_7 ;
}
return F_37 ( V_2 -> V_11 , V_74 ) ;
}
static int T_7 F_38 ( struct V_37 * V_11 )
{
struct V_74 * V_74 = F_39 ( V_11 ) ;
struct V_1 * V_2 = F_28 ( V_74 ) ;
T_4 V_6 = 0 ;
int V_7 ;
V_7 = V_2 -> V_9 -> V_13 ( V_2 -> V_11 , V_27 , sizeof( V_6 ) ,
( T_1 * ) & V_6 ) ;
return V_7 < 0 ? V_7 : 0 ;
}
static int T_7 F_40 ( struct V_37 * V_11 )
{
struct V_74 * V_74 = F_39 ( V_11 ) ;
struct V_1 * V_2 = F_28 ( V_74 ) ;
int V_7 = 0 ;
if ( V_2 -> V_45 )
V_7 = F_8 ( V_2 , V_2 -> V_20 ) ;
return V_7 ;
}
