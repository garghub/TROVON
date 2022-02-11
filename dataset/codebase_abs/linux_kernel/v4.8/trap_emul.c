static T_1 F_1 ( T_2 V_1 )
{
T_1 V_2 ;
T_2 V_3 = F_2 ( V_1 ) ;
if ( ( V_3 == V_4 ) || ( V_3 == V_5 ) )
V_2 = F_3 ( V_1 ) ;
else {
F_4 ( L_1 , V_6 , V_1 ) ;
F_5 () ;
V_2 = V_7 ;
}
F_6 ( L_2 , V_6 , V_1 , V_2 ) ;
return V_2 ;
}
static int F_7 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 . V_11 ;
struct V_13 * V_14 = V_9 -> V_14 ;
T_3 T_4 * V_15 = ( T_3 T_4 * ) V_9 -> V_12 . V_16 ;
T_3 V_17 = V_9 -> V_12 . V_18 ;
enum V_19 V_20 = V_21 ;
int V_22 = V_23 ;
if ( ( ( V_17 & V_24 ) >> V_25 ) == 1 ) {
if ( ! F_8 ( & V_9 -> V_12 ) ||
( F_9 ( V_11 ) & V_26 ) == 0 ) {
V_20 = F_10 ( V_17 , V_15 , V_14 , V_9 ) ;
} else {
F_11 ( V_9 ) ;
V_20 = V_21 ;
}
} else {
V_20 = F_12 ( V_17 , V_15 , V_14 , V_9 ) ;
}
switch ( V_20 ) {
case V_21 :
V_22 = V_23 ;
break;
case V_27 :
V_14 -> V_28 = V_29 ;
V_22 = V_30 ;
break;
case V_31 :
V_14 -> V_28 = V_32 ;
V_22 = V_30 ;
break;
default:
F_13 () ;
}
return V_22 ;
}
static int F_14 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = V_9 -> V_14 ;
T_3 T_4 * V_15 = ( T_3 T_4 * ) V_9 -> V_12 . V_16 ;
unsigned long V_33 = V_9 -> V_12 . V_34 ;
T_3 V_17 = V_9 -> V_12 . V_18 ;
enum V_19 V_20 = V_21 ;
int V_22 = V_23 ;
if ( F_15 ( V_33 ) < V_35
|| F_15 ( V_33 ) == V_36 ) {
F_6 ( L_3 ,
V_17 , V_15 , V_33 ) ;
V_20 = F_16 ( V_17 , V_15 , V_14 , V_9 ) ;
if ( V_20 == V_21 )
V_22 = V_23 ;
else {
V_14 -> V_28 = V_29 ;
V_22 = V_30 ;
}
} else if ( F_15 ( V_33 ) == V_35 ) {
F_4 ( L_4 ,
V_17 , V_15 , V_33 ) ;
F_5 () ;
F_17 ( V_9 ) ;
V_14 -> V_28 = V_29 ;
V_22 = V_30 ;
} else {
F_4 ( L_5 ,
V_17 , V_15 , V_33 ) ;
F_5 () ;
F_17 ( V_9 ) ;
V_14 -> V_28 = V_29 ;
V_22 = V_30 ;
}
return V_22 ;
}
static int F_18 ( struct V_8 * V_9 , bool V_37 )
{
struct V_13 * V_14 = V_9 -> V_14 ;
T_3 T_4 * V_15 = ( T_3 T_4 * ) V_9 -> V_12 . V_16 ;
unsigned long V_33 = V_9 -> V_12 . V_34 ;
T_3 V_17 = V_9 -> V_12 . V_18 ;
enum V_19 V_20 = V_21 ;
int V_22 = V_23 ;
if ( ( ( V_33 & V_38 ) == V_39 )
&& F_19 ( V_9 ) ) {
if ( F_20 ( V_33 , V_9 ) < 0 ) {
V_14 -> V_28 = V_29 ;
V_22 = V_30 ;
}
} else if ( F_15 ( V_33 ) < V_35
|| F_15 ( V_33 ) == V_36 ) {
F_6 ( L_6 ,
V_37 ? L_7 : L_8 , V_17 , V_15 , V_33 ) ;
V_20 = F_21 ( V_17 , V_15 , V_14 , V_9 ) ;
if ( V_20 == V_21 )
V_22 = V_23 ;
else {
V_14 -> V_28 = V_29 ;
V_22 = V_30 ;
}
} else if ( F_15 ( V_33 ) == V_35 ) {
if ( F_22
( V_9 -> V_12 . V_34 , V_9 ) < 0 ) {
V_14 -> V_28 = V_29 ;
V_22 = V_30 ;
}
} else {
F_4 ( L_9 ,
V_37 ? L_7 : L_8 , V_17 , V_15 , V_33 ) ;
F_5 () ;
F_17 ( V_9 ) ;
V_14 -> V_28 = V_29 ;
V_22 = V_30 ;
}
return V_22 ;
}
static int F_23 ( struct V_8 * V_9 )
{
return F_18 ( V_9 , true ) ;
}
static int F_24 ( struct V_8 * V_9 )
{
return F_18 ( V_9 , false ) ;
}
static int F_25 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = V_9 -> V_14 ;
T_3 T_4 * V_15 = ( T_3 T_4 * ) V_9 -> V_12 . V_16 ;
unsigned long V_33 = V_9 -> V_12 . V_34 ;
T_3 V_17 = V_9 -> V_12 . V_18 ;
enum V_19 V_20 = V_21 ;
int V_22 = V_23 ;
if ( F_19 ( V_9 )
&& ( F_2 ( V_33 ) == V_4 || F_2 ( V_33 ) == V_5 ) ) {
F_6 ( L_10 ) ;
V_20 = F_12 ( V_17 , V_15 , V_14 , V_9 ) ;
if ( V_20 == V_27 ) {
F_4 ( L_11 ) ;
V_14 -> V_28 = V_29 ;
V_22 = V_30 ;
} else {
V_14 -> V_28 = V_40 ;
V_22 = V_30 ;
}
} else {
F_4 ( L_12 ,
V_17 , V_15 , V_33 ) ;
V_14 -> V_28 = V_29 ;
V_22 = V_30 ;
}
return V_22 ;
}
static int F_26 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = V_9 -> V_14 ;
T_3 T_4 * V_15 = ( T_3 T_4 * ) V_9 -> V_12 . V_16 ;
unsigned long V_33 = V_9 -> V_12 . V_34 ;
T_3 V_17 = V_9 -> V_12 . V_18 ;
enum V_19 V_20 = V_21 ;
int V_22 = V_23 ;
if ( F_2 ( V_33 ) == V_4 || F_2 ( V_33 ) == V_5 ) {
F_6 ( L_13 , V_33 ) ;
V_20 = F_12 ( V_17 , V_15 , V_14 , V_9 ) ;
if ( V_20 == V_27 ) {
F_4 ( L_14 ) ;
V_14 -> V_28 = V_29 ;
V_22 = V_30 ;
} else {
V_14 -> V_28 = V_40 ;
V_22 = V_30 ;
}
} else {
F_4 ( L_15 ,
V_17 , V_15 , V_33 ) ;
V_14 -> V_28 = V_29 ;
V_22 = V_30 ;
V_20 = V_27 ;
}
return V_22 ;
}
static int F_27 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = V_9 -> V_14 ;
T_3 T_4 * V_15 = ( T_3 T_4 * ) V_9 -> V_12 . V_16 ;
T_3 V_17 = V_9 -> V_12 . V_18 ;
enum V_19 V_20 = V_21 ;
int V_22 = V_23 ;
V_20 = F_28 ( V_17 , V_15 , V_14 , V_9 ) ;
if ( V_20 == V_21 )
V_22 = V_23 ;
else {
V_14 -> V_28 = V_29 ;
V_22 = V_30 ;
}
return V_22 ;
}
static int F_29 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = V_9 -> V_14 ;
T_3 T_4 * V_15 = ( T_3 T_4 * ) V_9 -> V_12 . V_16 ;
T_3 V_17 = V_9 -> V_12 . V_18 ;
enum V_19 V_20 = V_21 ;
int V_22 = V_23 ;
V_20 = F_30 ( V_17 , V_15 , V_14 , V_9 ) ;
if ( V_20 == V_21 )
V_22 = V_23 ;
else {
V_14 -> V_28 = V_29 ;
V_22 = V_30 ;
}
return V_22 ;
}
static int F_31 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = V_9 -> V_14 ;
T_3 T_4 * V_15 = ( T_3 T_4 * ) V_9 -> V_12 . V_16 ;
T_3 V_17 = V_9 -> V_12 . V_18 ;
enum V_19 V_20 = V_21 ;
int V_22 = V_23 ;
V_20 = F_32 ( V_17 , V_15 , V_14 , V_9 ) ;
if ( V_20 == V_21 )
V_22 = V_23 ;
else {
V_14 -> V_28 = V_29 ;
V_22 = V_30 ;
}
return V_22 ;
}
static int F_33 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = V_9 -> V_14 ;
T_3 T_4 * V_15 = ( T_3 T_4 * ) V_9 -> V_12 . V_16 ;
T_3 V_17 = V_9 -> V_12 . V_18 ;
enum V_19 V_20 = V_21 ;
int V_22 = V_23 ;
V_20 = F_34 ( V_17 , V_15 , V_14 , V_9 ) ;
if ( V_20 == V_21 ) {
V_22 = V_23 ;
} else {
V_14 -> V_28 = V_29 ;
V_22 = V_30 ;
}
return V_22 ;
}
static int F_35 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = V_9 -> V_14 ;
T_3 T_4 * V_15 = ( T_3 T_4 * ) V_9 -> V_12 . V_16 ;
T_3 V_17 = V_9 -> V_12 . V_18 ;
enum V_19 V_20 = V_21 ;
int V_22 = V_23 ;
V_20 = F_36 ( V_17 , V_15 , V_14 , V_9 ) ;
if ( V_20 == V_21 ) {
V_22 = V_23 ;
} else {
V_14 -> V_28 = V_29 ;
V_22 = V_30 ;
}
return V_22 ;
}
static int F_37 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = V_9 -> V_14 ;
T_3 T_4 * V_15 = ( T_3 T_4 * ) V_9 -> V_12 . V_16 ;
T_3 V_17 = V_9 -> V_12 . V_18 ;
enum V_19 V_20 = V_21 ;
int V_22 = V_23 ;
V_20 = F_38 ( V_17 , V_15 , V_14 , V_9 ) ;
if ( V_20 == V_21 ) {
V_22 = V_23 ;
} else {
V_14 -> V_28 = V_29 ;
V_22 = V_30 ;
}
return V_22 ;
}
static int F_39 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 . V_11 ;
struct V_13 * V_14 = V_9 -> V_14 ;
T_3 T_4 * V_15 = ( T_3 T_4 * ) V_9 -> V_12 . V_16 ;
T_3 V_17 = V_9 -> V_12 . V_18 ;
enum V_19 V_20 = V_21 ;
int V_22 = V_23 ;
if ( ! F_40 ( & V_9 -> V_12 ) ||
( F_9 ( V_11 ) & ( V_26 | V_41 ) ) == V_26 ) {
V_20 = F_41 ( V_17 , V_15 , V_14 , V_9 ) ;
} else if ( ! ( F_42 ( V_11 ) & V_42 ) ) {
V_20 = F_43 ( V_17 , V_15 , V_14 , V_9 ) ;
} else {
F_44 ( V_9 ) ;
V_20 = V_21 ;
}
switch ( V_20 ) {
case V_21 :
V_22 = V_23 ;
break;
case V_27 :
V_14 -> V_28 = V_29 ;
V_22 = V_30 ;
break;
default:
F_13 () ;
}
return V_22 ;
}
static int F_45 ( struct V_43 * V_43 )
{
return 0 ;
}
static int F_46 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_44 = 0xfc ;
return 0 ;
}
static int F_47 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 . V_11 ;
T_3 V_45 , V_46 ;
int V_47 = V_9 -> V_47 ;
#ifndef F_48
F_49 ( V_11 , 0x00019300 ) ;
#else
F_49 ( V_11 , 0x00010000 ) ;
#endif
V_45 = F_50 () & V_48 ;
V_45 |= V_49 | V_50 | V_51 ;
#ifdef F_51
V_45 |= V_52 ;
#endif
if ( V_53 )
V_45 |= V_54 ;
F_52 ( V_11 , V_45 ) ;
V_46 = ( F_53 () & ~ 0x7f ) ;
V_46 &= ~ ( 0x3f << 25 ) ;
V_46 |= ( ( V_55 - 1 ) << 25 ) ;
V_46 &= ~ ( V_56 | V_57 | V_58 |
V_59 | V_60 ) ;
F_54 ( V_11 , V_46 ) ;
F_55 ( V_11 , V_49 ) ;
F_56 ( V_11 , V_49 | V_61 ) ;
F_57 ( V_11 , V_49 ) ;
F_58 ( V_11 , 0 ) ;
F_59 ( V_11 , ( V_62 ) | ( 1 << 10 ) ) ;
F_60 ( V_11 , 0xFC000000 ) ;
F_61 ( V_11 , V_35 |
( V_47 & V_63 ) ) ;
return 0 ;
}
static unsigned long F_62 ( struct V_8 * V_9 )
{
return 0 ;
}
static int F_63 ( struct V_8 * V_9 ,
T_5 T_4 * V_64 )
{
return 0 ;
}
static int F_64 ( struct V_8 * V_9 ,
const struct V_65 * V_66 ,
T_6 * V_67 )
{
switch ( V_66 -> V_68 ) {
case V_69 :
* V_67 = F_65 ( V_9 ) ;
break;
case V_70 :
* V_67 = V_9 -> V_12 . V_71 ;
break;
case V_72 :
* V_67 = F_66 ( V_9 -> V_12 . V_73 ) ;
break;
case V_74 :
* V_67 = V_9 -> V_12 . V_75 ;
break;
default:
return - V_76 ;
}
return 0 ;
}
static int F_67 ( struct V_8 * V_9 ,
const struct V_65 * V_66 ,
T_6 V_67 )
{
struct V_10 * V_11 = V_9 -> V_12 . V_11 ;
int V_22 = 0 ;
unsigned int V_77 , V_78 ;
switch ( V_66 -> V_68 ) {
case V_69 :
F_68 ( V_9 , V_67 ) ;
break;
case V_79 :
F_69 ( V_9 , V_67 , false ) ;
break;
case V_80 :
if ( ( F_70 ( V_11 ) ^ V_67 ) & V_81 ) {
if ( V_67 & V_81 ) {
F_71 ( V_9 ) ;
F_72 ( V_11 , ~ V_81 , V_67 ) ;
} else {
F_72 ( V_11 , ~ V_81 , V_67 ) ;
F_73 ( V_9 ) ;
}
} else {
F_74 ( V_11 , V_67 ) ;
}
break;
case V_82 :
break;
case V_83 :
V_77 = F_75 ( V_11 ) ;
V_78 = ( V_77 ^ V_67 ) & F_76 ( V_9 ) ;
if ( V_78 ) {
V_67 = V_77 ^ V_78 ;
F_54 ( V_11 , V_67 ) ;
}
break;
case V_84 :
break;
case V_85 :
V_77 = F_77 ( V_11 ) ;
V_78 = ( V_77 ^ V_67 ) & F_78 ( V_9 ) ;
if ( V_78 ) {
V_67 = V_77 ^ V_78 ;
F_56 ( V_11 , V_67 ) ;
}
break;
case V_86 :
V_77 = F_79 ( V_11 ) ;
V_78 = ( V_77 ^ V_67 ) & F_80 ( V_9 ) ;
if ( V_78 ) {
V_67 = V_77 ^ V_78 ;
F_57 ( V_11 , V_67 ) ;
}
break;
case V_87 :
V_77 = F_42 ( V_11 ) ;
V_78 = ( V_77 ^ V_67 ) & F_81 ( V_9 ) ;
if ( V_78 ) {
V_67 = V_77 ^ V_78 ;
F_58 ( V_11 , V_67 ) ;
}
break;
case V_70 :
V_22 = F_82 ( V_9 , V_67 ) ;
break;
case V_72 :
V_22 = F_83 ( V_9 , V_67 ) ;
break;
case V_74 :
V_22 = F_84 ( V_9 , V_67 ) ;
break;
default:
return - V_76 ;
}
return V_22 ;
}
static int F_85 ( struct V_8 * V_9 )
{
F_86 ( V_9 ) ;
return 0 ;
}
static int F_87 ( struct V_8 * V_9 )
{
return 0 ;
}
int F_88 ( struct V_88 * * V_89 )
{
* V_89 = & V_90 ;
return 0 ;
}
