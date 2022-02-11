static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_1 V_4 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 ) ;
V_7 -> V_9 [ 0 ] = F_4 ( V_3 ) ;
V_7 -> V_9 [ 1 ] = V_4 ;
V_5 = F_5 ( V_7 -> V_10 , V_7 -> V_9 , 2 ) ;
F_6 ( & V_7 -> V_8 ) ;
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 ,
T_1 V_11 ,
T_2 V_12 )
{
int V_5 ;
struct V_13 V_14 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_15 V_16 [] = {
{
. V_17 = V_7 -> V_9 ,
. V_18 = 8 ,
. V_19 = 2 ,
. V_20 = 1 ,
. V_21 = 35 ,
} , {
. V_17 = V_7 -> V_9 + 2 ,
. V_18 = 8 ,
. V_19 = 2 ,
. V_21 = 35 ,
} ,
} ;
F_3 ( & V_7 -> V_8 ) ;
V_7 -> V_9 [ 0 ] = F_4 ( V_11 ) ;
V_7 -> V_9 [ 1 ] = V_12 & 0xFF ;
V_7 -> V_9 [ 2 ] = F_4 ( V_11 + 1 ) ;
V_7 -> V_9 [ 3 ] = ( V_12 >> 8 ) & 0xFF ;
F_8 ( & V_14 ) ;
F_9 ( & V_16 [ 0 ] , & V_14 ) ;
F_9 ( & V_16 [ 1 ] , & V_14 ) ;
V_5 = F_10 ( V_7 -> V_10 , & V_14 ) ;
F_6 ( & V_7 -> V_8 ) ;
return V_5 ;
}
static int F_11 ( struct V_1 * V_2 ,
T_1 V_11 ,
T_2 * V_4 )
{
struct V_13 V_14 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_5 ;
struct V_15 V_16 [] = {
{
. V_17 = V_7 -> V_9 ,
. V_18 = 8 ,
. V_19 = 2 ,
. V_20 = 1 ,
. V_21 = 35 ,
} , {
. V_22 = V_7 -> V_23 ,
. V_18 = 8 ,
. V_19 = 2 ,
. V_20 = 1 ,
. V_21 = 35 ,
} ,
} ;
F_3 ( & V_7 -> V_8 ) ;
V_7 -> V_9 [ 0 ] = F_12 ( V_11 ) ;
V_7 -> V_9 [ 1 ] = 0 ;
F_8 ( & V_14 ) ;
F_9 ( & V_16 [ 0 ] , & V_14 ) ;
F_9 ( & V_16 [ 1 ] , & V_14 ) ;
V_5 = F_10 ( V_7 -> V_10 , & V_14 ) ;
if ( V_5 ) {
F_13 ( & V_7 -> V_10 -> V_24 ,
L_1 ,
V_11 ) ;
goto V_25;
}
* V_4 = ( V_7 -> V_23 [ 0 ] << 8 ) | V_7 -> V_23 [ 1 ] ;
V_25:
F_6 ( & V_7 -> V_8 ) ;
return V_5 ;
}
static T_3 F_14 ( struct V_26 * V_24 ,
struct V_27 * V_28 ,
char * V_29 )
{
struct V_30 * V_31 = F_15 ( V_28 ) ;
struct V_1 * V_2 = F_16 ( V_24 ) ;
T_3 V_5 ;
T_4 V_4 = 0 ;
F_3 ( & V_2 -> V_32 ) ;
V_5 = F_11 ( V_2 , V_31 -> V_33 ,
( T_2 * ) & V_4 ) ;
F_6 ( & V_2 -> V_32 ) ;
if ( V_5 )
return V_5 ;
return sprintf ( V_29 , L_2 , V_4 ) ;
}
static T_3 F_17 ( struct V_26 * V_24 ,
struct V_27 * V_28 ,
const char * V_29 ,
T_5 V_19 )
{
struct V_1 * V_2 = F_16 ( V_24 ) ;
struct V_30 * V_31 = F_15 ( V_28 ) ;
int V_5 ;
T_2 V_4 ;
V_5 = F_18 ( V_29 , 10 , & V_4 ) ;
if ( V_5 )
goto V_25;
V_5 = F_7 ( V_2 , V_31 -> V_33 , V_4 ) ;
V_25:
return V_5 ? V_5 : V_19 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_7 ( V_2 ,
V_34 ,
0xBF08 ) ;
if ( V_5 )
F_13 ( & V_2 -> V_24 , L_3 ) ;
F_20 ( 10 ) ;
return V_5 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_1 ( V_2 ,
V_34 ,
V_35 ) ;
if ( V_5 )
F_13 ( & V_2 -> V_24 , L_4 ) ;
return V_5 ;
}
static T_3 F_22 ( struct V_26 * V_24 ,
struct V_27 * V_28 ,
const char * V_29 , T_5 V_19 )
{
struct V_1 * V_2 = F_16 ( V_24 ) ;
bool V_4 ;
int V_5 ;
V_5 = F_23 ( V_29 , & V_4 ) ;
if ( V_5 )
return V_5 ;
if ( ! V_4 )
return - V_36 ;
V_5 = F_21 ( V_2 ) ;
if ( V_5 )
return V_5 ;
return V_19 ;
}
static T_3 F_24 ( struct V_26 * V_24 ,
struct V_27 * V_28 ,
const char * V_29 , T_5 V_19 )
{
struct V_1 * V_2 = F_16 ( V_24 ) ;
bool V_4 ;
int V_5 ;
V_5 = F_23 ( V_29 , & V_4 ) ;
if ( V_5 )
return V_5 ;
if ( ! V_4 )
return - V_36 ;
V_5 = F_19 ( V_2 ) ;
if ( V_5 )
return V_5 ;
return V_19 ;
}
static int F_25 ( struct V_1 * V_2 )
{
T_2 V_37 ;
int V_5 ;
V_5 = F_11 ( V_2 , V_38 ,
& V_37 ) ;
if ( V_5 < 0 ) {
F_13 ( & V_2 -> V_24 , L_5 ) ;
goto V_25;
}
V_5 = V_37 & 0x7F ;
if ( V_37 & V_39 )
F_13 ( & V_2 -> V_24 ,
L_6 ) ;
if ( V_37 & V_40 )
F_13 ( & V_2 -> V_24 , L_7 ) ;
if ( V_37 & V_41 )
F_13 ( & V_2 -> V_24 , L_8 ) ;
if ( V_37 & V_42 )
F_13 ( & V_2 -> V_24 , L_9 ) ;
if ( V_37 & V_43 )
F_13 ( & V_2 -> V_24 , L_10 ) ;
V_25:
return V_5 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_7 ( V_2 ,
V_44 ,
V_45 ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_24 , L_11 ) ;
goto V_46;
}
F_25 ( V_2 ) ;
V_46:
return V_5 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_26 ( V_2 ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_24 , L_12 ) ;
goto V_46;
}
V_5 = F_25 ( V_2 ) ;
if ( V_5 ) {
F_21 ( V_2 ) ;
F_13 ( & V_2 -> V_24 , L_13 ) ;
F_20 ( V_47 ) ;
V_5 = F_25 ( V_2 ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_24 , L_14 ) ;
goto V_46;
}
}
V_46:
return V_5 ;
}
static T_3 F_28 ( struct V_1 * V_2 ,
char * V_29 ,
T_6 V_48 ,
T_5 V_49 ,
int V_50 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_13 V_14 ;
struct V_15 V_16 [] = {
{
. V_17 = V_7 -> V_9 ,
. V_18 = 8 ,
. V_19 = 2 ,
. V_20 = 1 ,
. V_21 = 25 ,
} , {
. V_17 = V_7 -> V_9 ,
. V_22 = V_7 -> V_23 ,
. V_18 = 8 ,
. V_20 = 1 ,
. V_21 = 25 ,
} ,
} ;
int V_5 ;
int V_51 ;
if ( F_29 ( ! V_49 ) )
return V_49 ;
if ( ( V_48 >= V_52 ) || ( V_49 & 1 ) || ( V_48 & 1 ) )
return - V_36 ;
if ( V_48 + V_49 > V_52 )
V_49 = V_52 - V_48 ;
V_5 = F_7 ( V_2 ,
V_53 ,
V_48 > 1 ) ;
if ( V_5 )
return - V_54 ;
F_3 ( & V_7 -> V_8 ) ;
for ( V_51 = 0 ; V_51 < V_49 ; V_51 += 2 ) {
V_7 -> V_9 [ V_51 ] = F_12 ( V_50 ) ;
V_7 -> V_9 [ V_51 + 1 ] = 0 ;
}
V_16 [ 1 ] . V_19 = V_49 ;
F_8 ( & V_14 ) ;
F_9 ( & V_16 [ 0 ] , & V_14 ) ;
F_9 ( & V_16 [ 1 ] , & V_14 ) ;
V_5 = F_10 ( V_7 -> V_10 , & V_14 ) ;
if ( V_5 ) {
F_6 ( & V_7 -> V_8 ) ;
return - V_54 ;
}
memcpy ( V_29 , V_7 -> V_23 , V_49 ) ;
F_6 ( & V_7 -> V_8 ) ;
return V_49 ;
}
static T_3 F_30 ( struct V_55 * V_56 , struct V_57 * V_58 ,
struct V_59 * V_28 ,
char * V_29 ,
T_6 V_48 ,
T_5 V_49 )
{
struct V_26 * V_24 = F_31 ( V_58 , struct V_26 , V_58 ) ;
struct V_1 * V_2 = F_16 ( V_24 ) ;
return F_28 ( V_2 , V_29 ,
V_48 , V_49 ,
V_60 ) ;
}
static T_3 F_32 ( struct V_55 * V_56 , struct V_57 * V_58 ,
struct V_59 * V_28 ,
char * V_29 , T_6 V_48 ,
T_5 V_49 )
{
struct V_26 * V_24 = F_31 ( V_58 , struct V_26 , V_58 ) ;
struct V_1 * V_2 = F_16 ( V_24 ) ;
return F_28 ( V_2 , V_29 ,
V_48 , V_49 ,
V_61 ) ;
}
static T_3 F_33 ( struct V_55 * V_56 , struct V_57 * V_58 ,
struct V_59 * V_28 ,
char * V_29 , T_6 V_48 ,
T_5 V_49 )
{
struct V_26 * V_24 = F_31 ( V_58 , struct V_26 , V_58 ) ;
struct V_1 * V_2 = F_16 ( V_24 ) ;
return F_28 ( V_2 , V_29 ,
V_48 , V_49 ,
V_62 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_63 const * V_64 ,
int * V_4 , int * V_65 ,
long V_66 )
{
int V_5 = - V_36 ;
int V_67 = 0 ;
T_2 V_68 ;
T_4 V_69 ;
T_1 V_70 ;
switch ( V_66 ) {
case V_71 :
V_67 = 0 ;
break;
case V_72 :
if ( V_64 -> type == V_73 ) {
* V_4 = 25 ;
return V_74 ;
}
V_67 = 1 ;
break;
case V_75 :
V_67 = 2 ;
break;
case V_76 :
* V_4 = 0 ;
switch ( V_64 -> type ) {
case V_73 :
* V_65 = - 470000 ;
return V_77 ;
case V_78 :
* V_65 = 1887042 ;
return V_77 ;
case V_79 :
if ( V_64 -> V_80 == 0 )
* V_65 = 0012221 ;
else
* V_65 = 305 ;
return V_77 ;
default:
return - V_36 ;
}
default:
return - V_36 ;
}
if ( V_81 [ V_64 -> V_33 ] [ V_67 ] . V_82 ) {
V_5 = F_11 ( V_2 ,
V_81 [ V_64
-> V_33 ]
[ V_67 ] . V_50 ,
& V_69 ) ;
if ( V_5 )
return V_5 ;
V_70 = V_81 [ V_64 -> V_33 ] [ V_67 ] . V_70 ;
V_69 &= ( 1 << V_70 ) - 1 ;
V_69 = ( T_4 ) ( V_69 << ( 16 - V_70 ) ) >> ( 16 - V_70 ) ;
* V_4 = V_69 ;
return V_74 ;
} else {
V_5 = F_11 ( V_2 ,
V_81 [ V_64
-> V_33 ]
[ V_67 ] . V_50 ,
& V_68 ) ;
if ( V_5 )
return V_5 ;
V_70 = V_81 [ V_64 -> V_33 ] [ V_67 ] . V_70 ;
V_68 &= ( 1 << V_70 ) - 1 ;
* V_4 = V_68 ;
return V_74 ;
}
}
static int T_7 F_35 ( struct V_83 * V_84 )
{
int V_5 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
V_2 = F_36 ( sizeof( * V_7 ) ) ;
if ( V_2 == NULL ) {
V_5 = - V_85 ;
goto V_25;
}
V_7 = F_2 ( V_2 ) ;
F_37 ( V_84 , V_2 ) ;
V_7 -> V_10 = V_84 ;
F_38 ( & V_7 -> V_8 ) ;
V_2 -> V_86 = V_84 -> V_24 . V_87 -> V_86 ;
V_2 -> V_24 . V_88 = & V_84 -> V_24 ;
V_2 -> V_89 = & V_90 ;
V_2 -> V_91 = V_92 ;
V_2 -> V_93 = V_94 ;
V_2 -> V_95 = F_39 ( V_94 ) ;
V_5 = F_40 ( V_2 ) ;
if ( V_5 )
goto V_96;
V_5 = F_41 ( & V_2 -> V_24 . V_58 , & V_97 ) ;
if ( V_5 )
goto V_98;
V_5 = F_41 ( & V_2 -> V_24 . V_58 , & V_99 ) ;
if ( V_5 )
goto V_100;
V_5 = F_41 ( & V_2 -> V_24 . V_58 , & V_101 ) ;
if ( V_5 )
goto V_102;
V_5 = F_27 ( V_2 ) ;
if ( V_5 )
goto V_103;
return 0 ;
V_103:
F_42 ( & V_2 -> V_24 . V_58 , & V_101 ) ;
V_102:
F_42 ( & V_2 -> V_24 . V_58 , & V_99 ) ;
V_100:
F_42 ( & V_2 -> V_24 . V_58 , & V_97 ) ;
V_98:
F_43 ( V_2 ) ;
V_96:
F_44 ( V_2 ) ;
V_25:
return V_5 ;
}
static int F_45 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_46 ( V_84 ) ;
F_47 () ;
F_42 ( & V_2 -> V_24 . V_58 , & V_101 ) ;
F_42 ( & V_2 -> V_24 . V_58 , & V_99 ) ;
F_42 ( & V_2 -> V_24 . V_58 , & V_97 ) ;
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
return 0 ;
}
