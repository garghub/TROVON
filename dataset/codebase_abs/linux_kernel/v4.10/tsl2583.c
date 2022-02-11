static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = 100 ;
V_2 -> V_3 . V_5 = 0 ;
V_2 -> V_3 . V_6 = 1000 ;
V_2 -> V_3 . V_7 = 130 ;
memcpy ( V_2 -> V_3 . V_8 , V_9 ,
sizeof( V_9 ) ) ;
}
static int F_2 ( struct V_10 * V_11 )
{
T_1 V_12 , V_13 ;
T_2 V_14 ;
T_3 V_15 ;
T_2 V_16 ;
T_4 V_17 [ 5 ] ;
struct V_18 * V_19 ;
struct V_1 * V_2 = F_3 ( V_11 ) ;
int V_20 , V_21 ;
V_21 = F_4 ( V_2 -> V_22 , V_23 ) ;
if ( V_21 < 0 ) {
F_5 ( & V_2 -> V_22 -> V_24 , L_1 ,
V_25 ) ;
goto V_26;
}
if ( ! ( V_21 & V_27 ) ) {
F_5 ( & V_2 -> V_22 -> V_24 , L_2 ,
V_25 ) ;
V_21 = V_2 -> V_28 . V_14 ;
goto V_26;
}
for ( V_20 = 0 ; V_20 < 4 ; V_20 ++ ) {
int V_29 = V_23 | ( V_30 + V_20 ) ;
V_21 = F_4 ( V_2 -> V_22 , V_29 ) ;
if ( V_21 < 0 ) {
F_5 ( & V_2 -> V_22 -> V_24 , L_3 ,
V_25 , V_29 ) ;
goto V_26;
}
V_17 [ V_20 ] = V_21 ;
}
V_21 = F_6 ( V_2 -> V_22 ,
( V_23 | V_31 |
V_32 ) ) ;
if ( V_21 < 0 ) {
F_5 ( & V_2 -> V_22 -> V_24 , L_4 ,
V_25 ) ;
goto V_26;
}
V_12 = F_7 ( ( const V_33 * ) & V_17 [ 0 ] ) ;
V_13 = F_7 ( ( const V_33 * ) & V_17 [ 2 ] ) ;
V_2 -> V_28 . V_34 = V_12 ;
V_2 -> V_28 . V_35 = V_13 ;
if ( ( V_12 >= V_2 -> V_36 ) || ( V_13 >= V_2 -> V_36 ) )
goto V_37;
if ( ! V_12 ) {
V_21 = 0 ;
V_2 -> V_28 . V_14 = 0 ;
goto V_26;
}
V_16 = ( V_13 << 15 ) / V_12 ;
for ( V_19 = (struct V_18 * ) V_2 -> V_3 . V_8 ;
V_19 -> V_16 != 0 && V_19 -> V_16 < V_16 ; V_19 ++ )
;
if ( V_19 -> V_16 == 0 ) {
V_14 = 0 ;
} else {
T_2 V_38 , V_39 ;
V_38 = ( ( V_12 * V_19 -> V_12 ) +
( V_40 [ V_2 -> V_3 . V_5 ] . V_12 >> 1 ) )
/ V_40 [ V_2 -> V_3 . V_5 ] . V_12 ;
V_39 = ( ( V_13 * V_19 -> V_13 ) +
( V_40 [ V_2 -> V_3 . V_5 ] . V_13 >> 1 ) )
/ V_40 [ V_2 -> V_3 . V_5 ] . V_13 ;
if ( V_39 > V_38 ) {
F_8 ( & V_2 -> V_22 -> V_24 , L_5 ,
V_25 ) ;
V_21 = 0 ;
V_2 -> V_28 . V_14 = 0 ;
goto V_26;
}
V_14 = V_38 - V_39 ;
}
if ( V_2 -> V_41 == 0 )
V_14 = 0 ;
else
V_14 = ( V_14 + ( V_2 -> V_41 >> 1 ) ) /
V_2 -> V_41 ;
V_15 = V_14 ;
V_15 = V_15 * V_2 -> V_3 . V_6 ;
V_15 >>= 13 ;
V_14 = V_15 ;
V_14 = ( V_14 + 500 ) / 1000 ;
if ( V_14 > V_42 ) {
V_37:
V_14 = V_42 ;
}
V_2 -> V_28 . V_14 = V_14 ;
V_21 = V_14 ;
V_26:
return V_21 ;
}
static int F_9 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_3 ( V_11 ) ;
unsigned int V_43 ;
int V_21 ;
int V_44 ;
V_21 = F_4 ( V_2 -> V_22 ,
V_23 | V_45 ) ;
if ( V_21 < 0 ) {
F_5 ( & V_2 -> V_22 -> V_24 ,
L_6 ,
V_25 ) ;
return V_21 ;
}
if ( ( V_21 & ( V_46 | V_47 ) )
!= ( V_46 | V_47 ) ) {
F_5 ( & V_2 -> V_22 -> V_24 ,
L_7 ,
V_25 ) ;
return - V_48 ;
} else if ( ( V_21 & V_49 ) != V_49 ) {
F_5 ( & V_2 -> V_22 -> V_24 ,
L_8 ,
V_25 ) ;
return - V_50 ;
}
V_44 = F_2 ( V_11 ) ;
if ( V_44 < 0 ) {
F_5 ( & V_2 -> V_22 -> V_24 , L_9 ,
V_25 ) ;
return V_44 ;
}
V_43 = ( unsigned int ) ( ( ( V_2 -> V_3 . V_7 )
* V_2 -> V_3 . V_6 ) / V_44 ) ;
if ( ( V_43 < 250 ) || ( V_43 > 4000 ) ) {
F_5 ( & V_2 -> V_22 -> V_24 ,
L_10 ,
V_25 , V_43 ) ;
return - V_50 ;
}
V_2 -> V_3 . V_6 = ( int ) V_43 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_51 , V_4 , V_21 ;
T_4 V_52 ;
V_51 = ( V_2 -> V_3 . V_4 * 100 + 135 ) / 270 ;
if ( ! V_51 )
V_51 = 1 ;
V_4 = ( V_51 * 27 + 5 ) / 10 ;
V_52 = 256 - V_51 ;
V_21 = F_11 ( V_2 -> V_22 ,
V_23 | V_53 ,
V_52 ) ;
if ( V_21 < 0 ) {
F_5 ( & V_2 -> V_22 -> V_24 , L_11 ,
V_25 , V_52 ) ;
return V_21 ;
}
V_2 -> V_36 = V_51 * 922 ;
V_2 -> V_41 = ( V_4 + 25 ) / 50 ;
return V_21 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_21 ;
V_21 = F_11 ( V_2 -> V_22 ,
V_23 | V_54 ,
V_2 -> V_3 . V_5 ) ;
if ( V_21 < 0 )
F_5 ( & V_2 -> V_22 -> V_24 ,
L_12 , V_25 ,
V_2 -> V_3 . V_5 ) ;
return V_21 ;
}
static int F_13 ( struct V_1 * V_2 , T_4 V_55 )
{
int V_21 ;
V_21 = F_11 ( V_2 -> V_22 ,
V_23 | V_45 , V_55 ) ;
if ( V_21 < 0 )
F_5 ( & V_2 -> V_22 -> V_24 ,
L_13 , V_25 ,
V_55 ) ;
return V_21 ;
}
static int F_14 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_3 ( V_11 ) ;
int V_21 ;
V_21 = F_13 ( V_2 , V_47 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_11 ( V_2 -> V_22 ,
V_23 | V_56 ,
V_57 ) ;
if ( V_21 < 0 ) {
F_5 ( & V_2 -> V_22 -> V_24 ,
L_14 , V_25 ) ;
return V_21 ;
}
V_21 = F_10 ( V_2 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_12 ( V_2 ) ;
if ( V_21 < 0 )
return V_21 ;
F_15 ( 3000 , 3500 ) ;
V_21 = F_13 ( V_2 , V_47 |
V_46 ) ;
if ( V_21 < 0 )
return V_21 ;
V_2 -> V_58 = false ;
return V_21 ;
}
static T_5 F_16 ( struct V_59 * V_24 ,
struct V_60 * V_61 ,
char * V_17 )
{
struct V_10 * V_11 = F_17 ( V_24 ) ;
struct V_1 * V_2 = F_3 ( V_11 ) ;
int V_21 ;
F_18 ( & V_2 -> V_62 ) ;
V_21 = sprintf ( V_17 , L_15 , V_2 -> V_3 . V_7 ) ;
F_19 ( & V_2 -> V_62 ) ;
return V_21 ;
}
static T_5 F_20 ( struct V_59 * V_24 ,
struct V_60 * V_61 ,
const char * V_17 , T_6 V_63 )
{
struct V_10 * V_11 = F_17 ( V_24 ) ;
struct V_1 * V_2 = F_3 ( V_11 ) ;
int V_64 ;
if ( F_21 ( V_17 , 0 , & V_64 ) || ! V_64 )
return - V_48 ;
F_18 ( & V_2 -> V_62 ) ;
V_2 -> V_3 . V_7 = V_64 ;
F_19 ( & V_2 -> V_62 ) ;
return V_63 ;
}
static T_5 F_22 ( struct V_59 * V_24 ,
struct V_60 * V_61 ,
const char * V_17 , T_6 V_63 )
{
struct V_10 * V_11 = F_17 ( V_24 ) ;
struct V_1 * V_2 = F_3 ( V_11 ) ;
int V_64 , V_21 ;
if ( F_21 ( V_17 , 0 , & V_64 ) || V_64 != 1 )
return - V_48 ;
F_18 ( & V_2 -> V_62 ) ;
if ( V_2 -> V_58 ) {
V_21 = - V_65 ;
goto V_26;
}
V_21 = F_9 ( V_11 ) ;
if ( V_21 < 0 )
goto V_26;
V_21 = V_63 ;
V_26:
F_19 ( & V_2 -> V_62 ) ;
return V_21 ;
}
static T_5 F_23 ( struct V_59 * V_24 ,
struct V_60 * V_61 ,
char * V_17 )
{
struct V_10 * V_11 = F_17 ( V_24 ) ;
struct V_1 * V_2 = F_3 ( V_11 ) ;
unsigned int V_20 ;
int V_66 = 0 ;
for ( V_20 = 0 ; V_20 < F_24 ( V_2 -> V_3 . V_8 ) ; V_20 ++ ) {
V_66 += sprintf ( V_17 + V_66 , L_16 ,
V_2 -> V_3 . V_8 [ V_20 ] . V_16 ,
V_2 -> V_3 . V_8 [ V_20 ] . V_12 ,
V_2 -> V_3 . V_8 [ V_20 ] . V_13 ) ;
if ( V_2 -> V_3 . V_8 [ V_20 ] . V_16 == 0 ) {
V_66 -- ;
break;
}
}
V_66 += sprintf ( V_17 + V_66 , L_17 ) ;
return V_66 ;
}
static T_5 F_25 ( struct V_59 * V_24 ,
struct V_60 * V_61 ,
const char * V_17 , T_6 V_63 )
{
struct V_10 * V_11 = F_17 ( V_24 ) ;
struct V_1 * V_2 = F_3 ( V_11 ) ;
const unsigned int V_67 = V_68 * 3 ;
int V_64 [ V_68 * 3 + 1 ] ;
int V_21 = - V_48 ;
unsigned int V_69 ;
F_18 ( & V_2 -> V_62 ) ;
F_26 ( V_17 , F_24 ( V_64 ) , V_64 ) ;
V_69 = V_64 [ 0 ] ;
if ( ( V_69 % 3 ) || V_69 < 6 || V_69 > V_67 ) {
F_5 ( V_24 ,
L_18 ,
V_25 , V_67 ) ;
goto V_26;
}
if ( ( V_64 [ V_69 - 2 ] | V_64 [ V_69 - 1 ] | V_64 [ V_69 ] ) != 0 ) {
F_5 ( V_24 , L_19 ,
V_25 ) ;
goto V_26;
}
memcpy ( V_2 -> V_3 . V_8 , & V_64 [ 1 ] ,
V_64 [ 0 ] * sizeof( V_64 [ 1 ] ) ) ;
V_21 = V_63 ;
V_26:
F_19 ( & V_2 -> V_62 ) ;
return V_21 ;
}
static int F_27 ( struct V_10 * V_11 ,
struct V_70 const * V_71 ,
int * V_52 , int * V_72 , long V_73 )
{
struct V_1 * V_2 = F_3 ( V_11 ) ;
int V_21 = - V_48 ;
F_18 ( & V_2 -> V_62 ) ;
if ( V_2 -> V_58 ) {
V_21 = - V_65 ;
goto V_74;
}
switch ( V_73 ) {
case V_75 :
if ( V_71 -> type == V_76 ) {
V_21 = F_2 ( V_11 ) ;
if ( V_21 < 0 )
goto V_74;
if ( V_71 -> V_77 == V_78 )
* V_52 = V_2 -> V_28 . V_34 ;
else
* V_52 = V_2 -> V_28 . V_35 ;
V_21 = V_79 ;
}
break;
case V_80 :
if ( V_71 -> type == V_76 ) {
V_21 = F_2 ( V_11 ) ;
if ( V_21 < 0 )
goto V_74;
* V_52 = V_21 ;
V_21 = V_79 ;
}
break;
case V_81 :
if ( V_71 -> type == V_76 ) {
* V_52 = V_2 -> V_3 . V_6 ;
V_21 = V_79 ;
}
break;
case V_82 :
if ( V_71 -> type == V_76 ) {
* V_52 = V_40 [ V_2 -> V_3 . V_5 ] . V_83 ;
V_21 = V_79 ;
}
break;
case V_84 :
if ( V_71 -> type == V_76 ) {
* V_52 = 0 ;
* V_72 = V_2 -> V_3 . V_4 ;
V_21 = V_85 ;
}
break;
default:
break;
}
V_74:
F_19 ( & V_2 -> V_62 ) ;
return V_21 ;
}
static int F_28 ( struct V_10 * V_11 ,
struct V_70 const * V_71 ,
int V_52 , int V_72 , long V_73 )
{
struct V_1 * V_2 = F_3 ( V_11 ) ;
int V_21 = - V_48 ;
F_18 ( & V_2 -> V_62 ) ;
if ( V_2 -> V_58 ) {
V_21 = - V_65 ;
goto V_86;
}
switch ( V_73 ) {
case V_81 :
if ( V_71 -> type == V_76 ) {
V_2 -> V_3 . V_6 = V_52 ;
V_21 = 0 ;
}
break;
case V_82 :
if ( V_71 -> type == V_76 ) {
unsigned int V_20 ;
for ( V_20 = 0 ; V_20 < F_24 ( V_40 ) ; V_20 ++ ) {
if ( V_40 [ V_20 ] . V_83 == V_52 ) {
V_2 -> V_3 . V_5 = V_20 ;
V_21 = F_12 ( V_2 ) ;
break;
}
}
}
break;
case V_84 :
if ( V_71 -> type == V_76 && ! V_52 && V_72 >= 50 &&
V_72 <= 650 && ! ( V_72 % 50 ) ) {
V_2 -> V_3 . V_4 = V_72 ;
V_21 = F_10 ( V_2 ) ;
}
break;
default:
break;
}
V_86:
F_19 ( & V_2 -> V_62 ) ;
return V_21 ;
}
static int F_29 ( struct V_87 * V_88 ,
const struct V_89 * V_90 )
{
int V_21 ;
struct V_1 * V_2 ;
struct V_10 * V_11 ;
if ( ! F_30 ( V_88 -> V_91 ,
V_92 ) ) {
F_5 ( & V_88 -> V_24 , L_20 ,
V_25 ) ;
return - V_93 ;
}
V_11 = F_31 ( & V_88 -> V_24 , sizeof( * V_2 ) ) ;
if ( ! V_11 )
return - V_94 ;
V_2 = F_3 ( V_11 ) ;
V_2 -> V_22 = V_88 ;
F_32 ( V_88 , V_11 ) ;
F_33 ( & V_2 -> V_62 ) ;
V_2 -> V_58 = true ;
V_21 = F_4 ( V_88 ,
V_23 | V_95 ) ;
if ( V_21 < 0 ) {
F_5 ( & V_88 -> V_24 ,
L_21 , V_25 ) ;
return V_21 ;
}
if ( ( V_21 & V_96 ) != V_97 ) {
F_5 ( & V_88 -> V_24 , L_22 ,
V_25 , V_21 ) ;
return - V_48 ;
}
V_11 -> V_98 = & V_99 ;
V_11 -> V_100 = V_101 ;
V_11 -> V_102 = F_24 ( V_101 ) ;
V_11 -> V_24 . V_103 = & V_88 -> V_24 ;
V_11 -> V_104 = V_105 ;
V_11 -> V_106 = V_2 -> V_22 -> V_106 ;
V_21 = F_34 ( V_11 -> V_24 . V_103 , V_11 ) ;
if ( V_21 ) {
F_5 ( & V_88 -> V_24 , L_23 ,
V_25 ) ;
return V_21 ;
}
F_1 ( V_2 ) ;
V_21 = F_14 ( V_11 ) ;
if ( V_21 < 0 )
return V_21 ;
F_35 ( & V_88 -> V_24 , L_24 ) ;
return 0 ;
}
static int T_7 F_36 ( struct V_59 * V_24 )
{
struct V_10 * V_11 = F_37 ( F_38 ( V_24 ) ) ;
struct V_1 * V_2 = F_3 ( V_11 ) ;
int V_21 ;
F_18 ( & V_2 -> V_62 ) ;
V_21 = F_13 ( V_2 , V_107 ) ;
V_2 -> V_58 = true ;
F_19 ( & V_2 -> V_62 ) ;
return V_21 ;
}
static int T_7 F_39 ( struct V_59 * V_24 )
{
struct V_10 * V_11 = F_37 ( F_38 ( V_24 ) ) ;
struct V_1 * V_2 = F_3 ( V_11 ) ;
int V_21 ;
F_18 ( & V_2 -> V_62 ) ;
V_21 = F_14 ( V_11 ) ;
F_19 ( & V_2 -> V_62 ) ;
return V_21 ;
}
