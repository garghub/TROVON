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
return V_21 ;
}
static T_5 F_16 ( struct V_58 * V_24 ,
struct V_59 * V_60 ,
char * V_17 )
{
struct V_10 * V_11 = F_17 ( V_24 ) ;
struct V_1 * V_2 = F_3 ( V_11 ) ;
int V_21 ;
F_18 ( & V_2 -> V_61 ) ;
V_21 = sprintf ( V_17 , L_15 , V_2 -> V_3 . V_7 ) ;
F_19 ( & V_2 -> V_61 ) ;
return V_21 ;
}
static T_5 F_20 ( struct V_58 * V_24 ,
struct V_59 * V_60 ,
const char * V_17 , T_6 V_62 )
{
struct V_10 * V_11 = F_17 ( V_24 ) ;
struct V_1 * V_2 = F_3 ( V_11 ) ;
int V_63 ;
if ( F_21 ( V_17 , 0 , & V_63 ) || ! V_63 )
return - V_48 ;
F_18 ( & V_2 -> V_61 ) ;
V_2 -> V_3 . V_7 = V_63 ;
F_19 ( & V_2 -> V_61 ) ;
return V_62 ;
}
static T_5 F_22 ( struct V_58 * V_24 ,
struct V_59 * V_60 ,
const char * V_17 , T_6 V_62 )
{
struct V_10 * V_11 = F_17 ( V_24 ) ;
struct V_1 * V_2 = F_3 ( V_11 ) ;
int V_63 , V_21 ;
if ( F_21 ( V_17 , 0 , & V_63 ) || V_63 != 1 )
return - V_48 ;
F_18 ( & V_2 -> V_61 ) ;
V_21 = F_9 ( V_11 ) ;
if ( V_21 < 0 )
goto V_26;
V_21 = V_62 ;
V_26:
F_19 ( & V_2 -> V_61 ) ;
return V_21 ;
}
static T_5 F_23 ( struct V_58 * V_24 ,
struct V_59 * V_60 ,
char * V_17 )
{
struct V_10 * V_11 = F_17 ( V_24 ) ;
struct V_1 * V_2 = F_3 ( V_11 ) ;
unsigned int V_20 ;
int V_64 = 0 ;
for ( V_20 = 0 ; V_20 < F_24 ( V_2 -> V_3 . V_8 ) ; V_20 ++ ) {
V_64 += sprintf ( V_17 + V_64 , L_16 ,
V_2 -> V_3 . V_8 [ V_20 ] . V_16 ,
V_2 -> V_3 . V_8 [ V_20 ] . V_12 ,
V_2 -> V_3 . V_8 [ V_20 ] . V_13 ) ;
if ( V_2 -> V_3 . V_8 [ V_20 ] . V_16 == 0 ) {
V_64 -- ;
break;
}
}
V_64 += sprintf ( V_17 + V_64 , L_17 ) ;
return V_64 ;
}
static T_5 F_25 ( struct V_58 * V_24 ,
struct V_59 * V_60 ,
const char * V_17 , T_6 V_62 )
{
struct V_10 * V_11 = F_17 ( V_24 ) ;
struct V_1 * V_2 = F_3 ( V_11 ) ;
const unsigned int V_65 = V_66 * 3 ;
int V_63 [ V_66 * 3 + 1 ] ;
int V_21 = - V_48 ;
unsigned int V_67 ;
F_18 ( & V_2 -> V_61 ) ;
F_26 ( V_17 , F_24 ( V_63 ) , V_63 ) ;
V_67 = V_63 [ 0 ] ;
if ( ( V_67 % 3 ) || V_67 < 6 || V_67 > V_65 ) {
F_5 ( V_24 ,
L_18 ,
V_25 , V_65 ) ;
goto V_26;
}
if ( ( V_63 [ V_67 - 2 ] | V_63 [ V_67 - 1 ] | V_63 [ V_67 ] ) != 0 ) {
F_5 ( V_24 , L_19 ,
V_25 ) ;
goto V_26;
}
memcpy ( V_2 -> V_3 . V_8 , & V_63 [ 1 ] ,
V_63 [ 0 ] * sizeof( V_63 [ 1 ] ) ) ;
V_21 = V_62 ;
V_26:
F_19 ( & V_2 -> V_61 ) ;
return V_21 ;
}
static int F_27 ( struct V_1 * V_2 , bool V_68 )
{
int V_21 ;
if ( V_68 ) {
V_21 = F_28 ( & V_2 -> V_22 -> V_24 ) ;
if ( V_21 < 0 )
F_29 ( & V_2 -> V_22 -> V_24 ) ;
} else {
F_30 ( & V_2 -> V_22 -> V_24 ) ;
V_21 = F_31 ( & V_2 -> V_22 -> V_24 ) ;
}
return V_21 ;
}
static int F_32 ( struct V_10 * V_11 ,
struct V_69 const * V_70 ,
int * V_52 , int * V_71 , long V_72 )
{
struct V_1 * V_2 = F_3 ( V_11 ) ;
int V_21 , V_73 ;
V_21 = F_27 ( V_2 , true ) ;
if ( V_21 < 0 )
return V_21 ;
F_18 ( & V_2 -> V_61 ) ;
V_21 = - V_48 ;
switch ( V_72 ) {
case V_74 :
if ( V_70 -> type == V_75 ) {
V_21 = F_2 ( V_11 ) ;
if ( V_21 < 0 )
goto V_76;
if ( V_70 -> V_77 == V_78 )
* V_52 = V_2 -> V_28 . V_34 ;
else
* V_52 = V_2 -> V_28 . V_35 ;
V_21 = V_79 ;
}
break;
case V_80 :
if ( V_70 -> type == V_75 ) {
V_21 = F_2 ( V_11 ) ;
if ( V_21 < 0 )
goto V_76;
* V_52 = V_21 ;
V_21 = V_79 ;
}
break;
case V_81 :
if ( V_70 -> type == V_75 ) {
* V_52 = V_2 -> V_3 . V_6 ;
V_21 = V_79 ;
}
break;
case V_82 :
if ( V_70 -> type == V_75 ) {
* V_52 = V_40 [ V_2 -> V_3 . V_5 ] . V_83 ;
V_21 = V_79 ;
}
break;
case V_84 :
if ( V_70 -> type == V_75 ) {
* V_52 = 0 ;
* V_71 = V_2 -> V_3 . V_4 ;
V_21 = V_85 ;
}
break;
default:
break;
}
V_76:
F_19 ( & V_2 -> V_61 ) ;
if ( V_21 < 0 )
return V_21 ;
V_73 = F_27 ( V_2 , false ) ;
if ( V_73 < 0 )
return V_73 ;
return V_21 ;
}
static int F_33 ( struct V_10 * V_11 ,
struct V_69 const * V_70 ,
int V_52 , int V_71 , long V_72 )
{
struct V_1 * V_2 = F_3 ( V_11 ) ;
int V_21 ;
V_21 = F_27 ( V_2 , true ) ;
if ( V_21 < 0 )
return V_21 ;
F_18 ( & V_2 -> V_61 ) ;
V_21 = - V_48 ;
switch ( V_72 ) {
case V_81 :
if ( V_70 -> type == V_75 ) {
V_2 -> V_3 . V_6 = V_52 ;
V_21 = 0 ;
}
break;
case V_82 :
if ( V_70 -> type == V_75 ) {
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
if ( V_70 -> type == V_75 && ! V_52 && V_71 >= 50 &&
V_71 <= 650 && ! ( V_71 % 50 ) ) {
V_2 -> V_3 . V_4 = V_71 ;
V_21 = F_10 ( V_2 ) ;
}
break;
default:
break;
}
F_19 ( & V_2 -> V_61 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_27 ( V_2 , false ) ;
if ( V_21 < 0 )
return V_21 ;
return V_21 ;
}
static int F_34 ( struct V_86 * V_87 ,
const struct V_88 * V_89 )
{
int V_21 ;
struct V_1 * V_2 ;
struct V_10 * V_11 ;
if ( ! F_35 ( V_87 -> V_90 ,
V_91 ) ) {
F_5 ( & V_87 -> V_24 , L_20 ,
V_25 ) ;
return - V_92 ;
}
V_11 = F_36 ( & V_87 -> V_24 , sizeof( * V_2 ) ) ;
if ( ! V_11 )
return - V_93 ;
V_2 = F_3 ( V_11 ) ;
V_2 -> V_22 = V_87 ;
F_37 ( V_87 , V_11 ) ;
F_38 ( & V_2 -> V_61 ) ;
V_21 = F_4 ( V_87 ,
V_23 | V_94 ) ;
if ( V_21 < 0 ) {
F_5 ( & V_87 -> V_24 ,
L_21 , V_25 ) ;
return V_21 ;
}
if ( ( V_21 & V_95 ) != V_96 ) {
F_5 ( & V_87 -> V_24 , L_22 ,
V_25 , V_21 ) ;
return - V_48 ;
}
V_11 -> V_97 = & V_98 ;
V_11 -> V_99 = V_100 ;
V_11 -> V_101 = F_24 ( V_100 ) ;
V_11 -> V_24 . V_102 = & V_87 -> V_24 ;
V_11 -> V_103 = V_104 ;
V_11 -> V_105 = V_2 -> V_22 -> V_105 ;
F_39 ( & V_87 -> V_24 ) ;
F_40 ( & V_87 -> V_24 ,
V_106 ) ;
F_41 ( & V_87 -> V_24 ) ;
V_21 = F_42 ( V_11 -> V_24 . V_102 , V_11 ) ;
if ( V_21 ) {
F_5 ( & V_87 -> V_24 , L_23 ,
V_25 ) ;
return V_21 ;
}
F_1 ( V_2 ) ;
F_43 ( & V_87 -> V_24 , L_24 ) ;
return 0 ;
}
static int F_44 ( struct V_86 * V_22 )
{
struct V_10 * V_11 = F_45 ( V_22 ) ;
struct V_1 * V_2 = F_3 ( V_11 ) ;
F_46 ( V_11 ) ;
F_47 ( & V_22 -> V_24 ) ;
F_48 ( & V_22 -> V_24 ) ;
F_29 ( & V_22 -> V_24 ) ;
return F_13 ( V_2 , V_107 ) ;
}
static int T_7 F_49 ( struct V_58 * V_24 )
{
struct V_10 * V_11 = F_45 ( F_50 ( V_24 ) ) ;
struct V_1 * V_2 = F_3 ( V_11 ) ;
int V_21 ;
F_18 ( & V_2 -> V_61 ) ;
V_21 = F_13 ( V_2 , V_107 ) ;
F_19 ( & V_2 -> V_61 ) ;
return V_21 ;
}
static int T_7 F_51 ( struct V_58 * V_24 )
{
struct V_10 * V_11 = F_45 ( F_50 ( V_24 ) ) ;
struct V_1 * V_2 = F_3 ( V_11 ) ;
int V_21 ;
F_18 ( & V_2 -> V_61 ) ;
V_21 = F_14 ( V_11 ) ;
F_19 ( & V_2 -> V_61 ) ;
return V_21 ;
}
