int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
T_1 V_6 ;
int V_7 ;
F_2 ( & V_2 -> V_8 ) ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_3 , sizeof( V_6 ) , & V_6 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_11 , L_1 , V_3 ) ;
goto V_12;
}
V_6 = ( V_6 & ~ V_4 ) | ( ( V_5 << F_4 ( V_4 ) ) & V_4 ) ;
V_7 = V_2 -> V_9 -> V_13 ( V_2 -> V_11 , V_3 , sizeof( V_6 ) , & V_6 ) ;
if ( V_7 < 0 )
F_3 ( V_2 -> V_11 , L_2 , V_3 ) ;
V_12:
F_5 ( & V_2 -> V_8 ) ;
return V_7 ;
}
static int F_6 ( struct V_1 * V_2 )
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
static int F_7 ( struct V_1 * V_2 , T_1 V_17 )
{
int V_18 , V_7 ;
for ( V_18 = 0 ; V_18 < F_8 ( V_19 ) ; V_18 ++ )
if ( V_19 [ V_18 ] . V_20 == V_17 )
break;
if ( V_18 == F_8 ( V_19 ) )
return - V_21 ;
V_7 = F_1 ( V_2 , V_22 ,
V_23 , V_19 [ V_18 ] . V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
V_2 -> V_17 = V_17 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
enum V_24 type ,
T_2 V_5 )
{
int V_18 , V_7 ;
const struct V_25 * V_26 = & V_27 [ type ] ;
for ( V_18 = 0 ; V_18 < V_28 ; V_18 ++ )
if ( V_26 -> V_29 [ V_18 ] == V_5 )
break;
if ( V_18 == V_28 )
return - V_21 ;
V_7 = F_1 ( V_2 , V_26 -> V_3 , V_26 -> V_4 , V_18 ) ;
if ( V_7 < 0 )
return V_7 ;
V_2 -> V_30 [ type ] . V_31 = V_18 ;
return 0 ;
}
static T_3 F_10 ( struct V_32 * V_11 ,
struct V_33 * V_34 ,
char * V_35 )
{
int V_18 ;
T_3 V_36 = 0 ;
for ( V_18 = 0 ; V_18 < F_8 ( V_19 ) ; V_18 ++ )
V_36 += F_11 ( V_35 + V_36 , V_37 - V_36 , L_5 ,
V_19 [ V_18 ] . V_20 ) ;
V_35 [ V_36 - 1 ] = '\n' ;
return V_36 ;
}
static T_3
F_12 ( struct V_32 * V_11 ,
struct V_33 * V_34 ,
char * V_35 )
{
const struct V_25 * V_26 = & V_27 [ V_38 ] ;
T_3 V_36 = 0 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < F_8 ( V_26 -> V_29 ) ; V_18 ++ )
V_36 += F_11 ( V_35 + V_36 , V_37 - V_36 , L_5 ,
V_26 -> V_29 [ V_18 ] ) ;
V_35 [ V_36 - 1 ] = '\n' ;
return V_36 ;
}
static T_3
F_13 ( struct V_32 * V_11 ,
struct V_33 * V_34 ,
char * V_35 )
{
const struct V_25 * V_26 = & V_27 [ V_39 ] ;
T_3 V_36 = 0 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < F_8 ( V_26 -> V_29 ) ; V_18 ++ )
V_36 += F_11 ( V_35 + V_36 , V_37 - V_36 , L_5 ,
V_26 -> V_29 [ V_18 ] ) ;
V_35 [ V_36 - 1 ] = '\n' ;
return V_36 ;
}
int F_14 ( struct V_1 * V_2 , bool V_40 )
{
int V_7 ;
V_7 = F_1 ( V_2 , V_22 ,
V_41 , V_40 ) ;
if ( V_7 < 0 )
return V_7 ;
V_2 -> V_42 = V_40 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_7 , * V_43 , * V_44 ;
T_4 V_45 , V_46 , V_47 , V_48 ;
T_1 V_49 , V_50 ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_51 ,
sizeof( V_49 ) , & V_49 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_52 ,
sizeof( V_50 ) , & V_50 ) ;
if ( V_7 < 0 )
return V_7 ;
V_47 = ( F_16 ( V_50 & 0x3 ) << 8 ) | V_49 ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_53 ,
sizeof( V_49 ) , & V_49 ) ;
if ( V_7 < 0 )
return V_7 ;
V_48 = ( ( ( V_50 & 0xc ) >> 2 ) << 8 ) | V_49 ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_54 , sizeof( V_45 ) ,
( T_1 * ) & V_45 ) ;
if ( V_7 < 0 )
return V_7 ;
V_45 = F_16 ( V_45 ) ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_55 , sizeof( V_46 ) ,
( T_1 * ) & V_46 ) ;
if ( V_7 < 0 )
return V_7 ;
V_46 = F_16 ( V_46 ) ;
V_43 = & V_2 -> V_30 [ V_39 ] . V_43 ;
V_44 = & V_2 -> V_30 [ V_39 ] . V_44 ;
* V_43 = ( ( V_48 - V_47 ) * 8000 ) / ( V_46 - V_45 ) ;
* V_44 = ( ( ( V_56 ) V_46 * V_47 - ( V_56 ) V_45 * V_48 ) * 1000 ) /
( V_46 - V_45 ) ;
* V_44 *= 8 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_7 , * V_43 , * V_44 ;
T_4 V_45 , V_46 , V_47 , V_48 ;
T_1 V_6 ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_57 , sizeof( V_6 ) ,
& V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
V_47 = V_6 ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_58 , sizeof( V_6 ) ,
& V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
V_48 = V_6 ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_59 , sizeof( V_45 ) ,
( T_1 * ) & V_45 ) ;
if ( V_7 < 0 )
return V_7 ;
V_45 = F_16 ( V_45 ) ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_60 , sizeof( V_46 ) ,
( T_1 * ) & V_46 ) ;
if ( V_7 < 0 )
return V_7 ;
V_46 = F_16 ( V_46 ) ;
V_43 = & V_2 -> V_30 [ V_38 ] . V_43 ;
V_44 = & V_2 -> V_30 [ V_38 ] . V_44 ;
* V_43 = ( ( V_48 - V_47 ) * 8000 ) / ( V_46 - V_45 ) ;
* V_44 = ( ( ( V_56 ) V_46 * V_47 - ( V_56 ) V_45 * V_48 ) * 1000 ) /
( V_46 - V_45 ) ;
* V_44 *= 8 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
enum V_61 V_62 ,
int * V_5 , int * V_63 )
{
T_5 V_64 ;
V_56 V_65 , div , V_6 ;
switch ( V_62 ) {
case V_66 :
V_6 = V_2 -> V_30 [ V_38 ] . V_43 ;
div = ( 1 << 4 ) * 1000 ;
break;
case V_67 :
V_6 = V_2 -> V_30 [ V_39 ] . V_43 ;
div = ( 1 << 6 ) * 1000 ;
break;
default:
return - V_21 ;
}
V_64 = F_19 ( V_6 * 1000000000LL , div ) ;
V_64 = F_20 ( V_64 , 1000000000LL , & V_65 ) ;
* V_5 = V_64 ;
* V_63 = V_65 ;
return V_68 ;
}
static int F_21 ( struct V_1 * V_2 ,
enum V_61 V_62 ,
int * V_5 , int * V_63 )
{
T_5 V_64 ;
V_56 V_65 , div , V_6 ;
switch ( V_62 ) {
case V_66 :
V_6 = V_2 -> V_30 [ V_38 ] . V_44 ;
div = V_2 -> V_30 [ V_38 ] . V_43 ;
break;
case V_67 :
V_6 = V_2 -> V_30 [ V_39 ] . V_44 ;
div = V_2 -> V_30 [ V_39 ] . V_43 ;
break;
default:
return - V_21 ;
}
V_64 = F_19 ( V_6 * 1000000000LL , div ) ;
V_64 = F_20 ( V_64 , 1000000000LL , & V_65 ) ;
* V_5 = V_64 ;
* V_63 = V_65 ;
return V_68 ;
}
static int F_22 ( struct V_1 * V_2 , T_1 V_3 , int * V_5 )
{
T_1 V_6 [ V_69 ] ;
int V_7 ;
V_7 = F_14 ( V_2 , true ) ;
if ( V_7 < 0 )
return V_7 ;
F_23 ( 50 ) ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_3 , sizeof( V_6 ) , V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
F_14 ( V_2 , false ) ;
* V_5 = ( T_4 ) F_24 ( V_6 ) ;
return V_70 ;
}
static int F_25 ( struct V_71 * V_71 ,
struct V_72 const * V_73 ,
int * V_5 , int * V_63 , long V_4 )
{
struct V_1 * V_2 = F_26 ( V_71 ) ;
int V_74 ;
V_74 = F_27 ( V_71 ) ;
if ( V_74 )
return V_74 ;
switch ( V_4 ) {
case V_75 :
V_74 = F_22 ( V_2 , V_73 -> V_76 , V_5 ) ;
break;
case V_77 :
V_74 = F_18 ( V_2 , V_73 -> type , V_5 , V_63 ) ;
break;
case V_78 :
V_74 = F_21 ( V_2 , V_73 -> type , V_5 , V_63 ) ;
break;
case V_79 :
* V_5 = V_2 -> V_17 ;
V_74 = V_70 ;
break;
case V_80 : {
T_1 V_81 ;
const struct V_25 * V_26 ;
switch ( V_73 -> type ) {
case V_66 :
V_26 = & V_27 [ V_38 ] ;
V_81 = V_2 -> V_30 [ V_38 ] . V_31 ;
* V_5 = V_26 -> V_29 [ V_81 ] ;
V_74 = V_70 ;
break;
case V_67 :
V_26 = & V_27 [ V_39 ] ;
V_81 = V_2 -> V_30 [ V_39 ] . V_31 ;
* V_5 = V_26 -> V_29 [ V_81 ] ;
V_74 = V_70 ;
break;
default:
V_74 = - V_21 ;
break;
}
break;
}
default:
V_74 = - V_21 ;
break;
}
F_28 ( V_71 ) ;
return V_74 ;
}
static int F_29 ( struct V_71 * V_71 ,
struct V_72 const * V_82 ,
int V_5 , int V_63 , long V_4 )
{
struct V_1 * V_2 = F_26 ( V_71 ) ;
int V_74 ;
V_74 = F_27 ( V_71 ) ;
if ( V_74 )
return V_74 ;
switch ( V_4 ) {
case V_79 :
V_74 = F_7 ( V_2 , V_5 ) ;
break;
case V_80 :
switch ( V_82 -> type ) {
case V_66 :
V_74 = F_9 ( V_2 , V_38 , V_5 ) ;
break;
case V_67 :
V_74 = F_9 ( V_2 , V_39 , V_5 ) ;
break;
default:
V_74 = - V_21 ;
break;
}
break;
default:
V_74 = - V_21 ;
break;
}
F_28 ( V_71 ) ;
return V_74 ;
}
static int F_30 ( struct V_71 * V_71 ,
struct V_83 * V_84 )
{
struct V_1 * V_2 = F_26 ( V_71 ) ;
return V_2 -> V_84 == V_84 ? 0 : - V_21 ;
}
int F_31 ( struct V_71 * V_71 )
{
struct V_1 * V_2 = F_26 ( V_71 ) ;
int V_7 ;
T_1 V_6 ;
F_32 ( & V_2 -> V_8 ) ;
V_7 = F_6 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_71 -> V_85 = V_86 ;
V_71 -> V_11 . V_87 = V_2 -> V_11 ;
V_71 -> V_88 = V_89 ;
V_71 -> V_90 = V_91 ;
V_71 -> V_92 = F_8 ( V_91 ) ;
V_71 -> V_93 = V_94 ;
V_71 -> V_95 = & V_96 ;
V_7 = F_1 ( V_2 , V_22 ,
V_97 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 , V_19 [ 0 ] . V_20 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_17 ( V_2 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_11 , L_6 ) ;
return V_7 ;
}
V_6 = V_27 [ V_38 ] . V_29 [ 3 ] ;
V_7 = F_9 ( V_2 , V_38 , V_6 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_11 , L_7 ) ;
return V_7 ;
}
V_7 = F_15 ( V_2 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_11 ,
L_8 ) ;
return V_7 ;
}
V_6 = V_27 [ V_39 ] . V_29 [ 3 ] ;
V_7 = F_9 ( V_2 , V_39 , V_6 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_11 ,
L_9 ) ;
return V_7 ;
}
if ( V_2 -> V_98 > 0 ) {
V_7 = F_33 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_34 ( V_2 ) ;
if ( V_7 )
return V_7 ;
}
return F_35 ( V_2 -> V_11 , V_71 ) ;
}
static int T_6 F_36 ( struct V_32 * V_11 )
{
struct V_71 * V_71 = F_37 ( V_11 ) ;
struct V_1 * V_2 = F_26 ( V_71 ) ;
int V_7 ;
V_7 = F_1 ( V_2 , V_22 ,
V_41 , false ) ;
return V_7 < 0 ? V_7 : 0 ;
}
static int T_6 F_38 ( struct V_32 * V_11 )
{
struct V_71 * V_71 = F_37 ( V_11 ) ;
struct V_1 * V_2 = F_26 ( V_71 ) ;
int V_7 = 0 ;
if ( V_2 -> V_42 )
V_7 = F_1 ( V_2 , V_22 ,
V_41 , true ) ;
return V_7 ;
}
