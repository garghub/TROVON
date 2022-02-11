static T_1 F_1 ( T_2 V_1 )
{
T_1 V_2 ;
T_3 V_3 = F_2 ( V_1 ) ;
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
unsigned long V_17 = V_9 -> V_12 . V_18 ;
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
unsigned long V_17 = V_9 -> V_12 . V_18 ;
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
static int F_18 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = V_9 -> V_14 ;
T_3 T_4 * V_15 = ( T_3 T_4 * ) V_9 -> V_12 . V_16 ;
unsigned long V_33 = V_9 -> V_12 . V_34 ;
unsigned long V_17 = V_9 -> V_12 . V_18 ;
enum V_19 V_20 = V_21 ;
int V_22 = V_23 ;
if ( ( ( V_33 & V_37 ) == V_38 )
&& F_19 ( V_9 ) ) {
if ( F_20 ( V_33 , V_9 ) < 0 ) {
V_14 -> V_28 = V_29 ;
V_22 = V_30 ;
}
} else if ( F_15 ( V_33 ) < V_35
|| F_15 ( V_33 ) == V_36 ) {
F_6 ( L_6 ,
V_17 , V_15 , V_33 ) ;
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
F_4 ( L_7 ,
V_17 , V_15 , V_33 ) ;
F_5 () ;
F_17 ( V_9 ) ;
V_14 -> V_28 = V_29 ;
V_22 = V_30 ;
}
return V_22 ;
}
static int F_23 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = V_9 -> V_14 ;
T_3 T_4 * V_15 = ( T_3 T_4 * ) V_9 -> V_12 . V_16 ;
unsigned long V_33 = V_9 -> V_12 . V_34 ;
unsigned long V_17 = V_9 -> V_12 . V_18 ;
enum V_19 V_20 = V_21 ;
int V_22 = V_23 ;
if ( ( ( V_33 & V_37 ) == V_38 )
&& F_19 ( V_9 ) ) {
if ( F_20 ( V_33 , V_9 ) < 0 ) {
V_14 -> V_28 = V_29 ;
V_22 = V_30 ;
}
} else if ( F_15 ( V_33 ) < V_35
|| F_15 ( V_33 ) == V_36 ) {
F_6 ( L_8 ,
V_9 -> V_12 . V_16 , V_33 ) ;
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
V_17 , V_15 , V_33 ) ;
F_5 () ;
F_17 ( V_9 ) ;
V_14 -> V_28 = V_29 ;
V_22 = V_30 ;
}
return V_22 ;
}
static int F_24 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = V_9 -> V_14 ;
T_3 T_4 * V_15 = ( T_3 T_4 * ) V_9 -> V_12 . V_16 ;
unsigned long V_33 = V_9 -> V_12 . V_34 ;
unsigned long V_17 = V_9 -> V_12 . V_18 ;
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
V_14 -> V_28 = V_39 ;
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
static int F_25 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = V_9 -> V_14 ;
T_3 T_4 * V_15 = ( T_3 T_4 * ) V_9 -> V_12 . V_16 ;
unsigned long V_33 = V_9 -> V_12 . V_34 ;
unsigned long V_17 = V_9 -> V_12 . V_18 ;
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
V_14 -> V_28 = V_39 ;
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
static int F_26 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = V_9 -> V_14 ;
T_3 T_4 * V_15 = ( T_3 T_4 * ) V_9 -> V_12 . V_16 ;
unsigned long V_17 = V_9 -> V_12 . V_18 ;
enum V_19 V_20 = V_21 ;
int V_22 = V_23 ;
V_20 = F_27 ( V_17 , V_15 , V_14 , V_9 ) ;
if ( V_20 == V_21 )
V_22 = V_23 ;
else {
V_14 -> V_28 = V_29 ;
V_22 = V_30 ;
}
return V_22 ;
}
static int F_28 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = V_9 -> V_14 ;
T_3 T_4 * V_15 = ( T_3 T_4 * ) V_9 -> V_12 . V_16 ;
unsigned long V_17 = V_9 -> V_12 . V_18 ;
enum V_19 V_20 = V_21 ;
int V_22 = V_23 ;
V_20 = F_29 ( V_17 , V_15 , V_14 , V_9 ) ;
if ( V_20 == V_21 )
V_22 = V_23 ;
else {
V_14 -> V_28 = V_29 ;
V_22 = V_30 ;
}
return V_22 ;
}
static int F_30 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = V_9 -> V_14 ;
T_3 T_4 * V_15 = ( T_3 T_4 * ) V_9 -> V_12 . V_16 ;
unsigned long V_17 = V_9 -> V_12 . V_18 ;
enum V_19 V_20 = V_21 ;
int V_22 = V_23 ;
V_20 = F_31 ( V_17 , V_15 , V_14 , V_9 ) ;
if ( V_20 == V_21 )
V_22 = V_23 ;
else {
V_14 -> V_28 = V_29 ;
V_22 = V_30 ;
}
return V_22 ;
}
static int F_32 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = V_9 -> V_14 ;
T_3 T_4 * V_15 = ( T_3 T_4 * ) V_9 -> V_12 . V_16 ;
unsigned long V_17 = V_9 -> V_12 . V_18 ;
enum V_19 V_20 = V_21 ;
int V_22 = V_23 ;
V_20 = F_33 ( V_17 , V_15 , V_14 , V_9 ) ;
if ( V_20 == V_21 ) {
V_22 = V_23 ;
} else {
V_14 -> V_28 = V_29 ;
V_22 = V_30 ;
}
return V_22 ;
}
static int F_34 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = V_9 -> V_14 ;
T_3 T_4 * V_15 = ( T_3 T_4 * ) V_9 -> V_12 . V_16 ;
unsigned long V_17 = V_9 -> V_12 . V_18 ;
enum V_19 V_20 = V_21 ;
int V_22 = V_23 ;
V_20 = F_35 ( V_17 , V_15 , V_14 , V_9 ) ;
if ( V_20 == V_21 ) {
V_22 = V_23 ;
} else {
V_14 -> V_28 = V_29 ;
V_22 = V_30 ;
}
return V_22 ;
}
static int F_36 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = V_9 -> V_14 ;
T_3 T_4 * V_15 = ( T_3 T_4 * ) V_9 -> V_12 . V_16 ;
unsigned long V_17 = V_9 -> V_12 . V_18 ;
enum V_19 V_20 = V_21 ;
int V_22 = V_23 ;
V_20 = F_37 ( V_17 , V_15 , V_14 , V_9 ) ;
if ( V_20 == V_21 ) {
V_22 = V_23 ;
} else {
V_14 -> V_28 = V_29 ;
V_22 = V_30 ;
}
return V_22 ;
}
static int F_38 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 . V_11 ;
struct V_13 * V_14 = V_9 -> V_14 ;
T_3 T_4 * V_15 = ( T_3 T_4 * ) V_9 -> V_12 . V_16 ;
unsigned long V_17 = V_9 -> V_12 . V_18 ;
enum V_19 V_20 = V_21 ;
int V_22 = V_23 ;
if ( ! F_39 ( & V_9 -> V_12 ) ||
( F_9 ( V_11 ) & ( V_26 | V_40 ) ) == V_26 ) {
V_20 = F_40 ( V_17 , V_15 , V_14 , V_9 ) ;
} else if ( ! ( F_41 ( V_11 ) & V_41 ) ) {
V_20 = F_42 ( V_17 , V_15 , V_14 , V_9 ) ;
} else {
F_43 ( V_9 ) ;
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
static int F_44 ( struct V_42 * V_42 )
{
return 0 ;
}
static int F_45 ( struct V_8 * V_9 )
{
return 0 ;
}
static int F_46 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 . V_11 ;
T_3 V_43 ;
int V_44 = V_9 -> V_44 ;
F_47 ( V_11 , 0x00019300 ) ;
F_48 ( V_11 , V_45 | ( 0x3 << V_46 ) |
( 0x1 << V_47 ) |
( V_48 << V_49 ) ) ;
V_43 = ( F_49 () & ~ 0x7f ) ;
V_43 &= ~ ( 0x3f << 25 ) ;
V_43 |= ( ( V_50 - 1 ) << 25 ) ;
V_43 &=
~ ( ( 1 << V_51 ) | ( 1 << V_52 ) | ( 1 << V_53 ) |
( 1 << V_54 ) | ( 1 << V_55 ) ) ;
F_50 ( V_11 , V_43 ) ;
F_51 ( V_11 , V_45 ) ;
F_52 ( V_11 , V_45 | V_56 ) ;
F_53 ( V_11 , V_45 ) ;
F_54 ( V_11 , 0 ) ;
F_55 ( V_11 , ( V_57 ) | ( 1 << 10 ) ) ;
F_56 ( V_11 , 0xFC000000 ) ;
F_57 ( V_11 , V_35 | ( V_44 & 0xFF ) ) ;
return 0 ;
}
static int F_58 ( struct V_8 * V_9 ,
const struct V_58 * V_59 ,
T_5 * V_60 )
{
switch ( V_59 -> V_61 ) {
case V_62 :
* V_60 = F_59 ( V_9 ) ;
break;
case V_63 :
* V_60 = V_9 -> V_12 . V_64 ;
break;
case V_65 :
* V_60 = F_60 ( V_9 -> V_12 . V_66 ) ;
break;
case V_67 :
* V_60 = V_9 -> V_12 . V_68 ;
break;
default:
return - V_69 ;
}
return 0 ;
}
static int F_61 ( struct V_8 * V_9 ,
const struct V_58 * V_59 ,
T_5 V_60 )
{
struct V_10 * V_11 = V_9 -> V_12 . V_11 ;
int V_22 = 0 ;
unsigned int V_70 , V_71 ;
switch ( V_59 -> V_61 ) {
case V_62 :
F_62 ( V_9 , V_60 ) ;
break;
case V_72 :
F_63 ( V_9 , V_60 ) ;
break;
case V_73 :
if ( ( F_64 ( V_11 ) ^ V_60 ) & V_74 ) {
if ( V_60 & V_74 ) {
F_65 ( V_9 ) ;
F_66 ( V_11 , ~ V_74 , V_60 ) ;
} else {
F_66 ( V_11 , ~ V_74 , V_60 ) ;
F_67 ( V_9 ) ;
}
} else {
F_68 ( V_11 , V_60 ) ;
}
break;
case V_75 :
break;
case V_76 :
V_70 = F_69 ( V_11 ) ;
V_71 = ( V_70 ^ V_60 ) & F_70 ( V_9 ) ;
if ( V_71 ) {
V_60 = V_70 ^ V_71 ;
F_50 ( V_11 , V_60 ) ;
}
break;
case V_77 :
break;
case V_78 :
V_70 = F_71 ( V_11 ) ;
V_71 = ( V_70 ^ V_60 ) & F_72 ( V_9 ) ;
if ( V_71 ) {
V_60 = V_70 ^ V_71 ;
F_52 ( V_11 , V_60 ) ;
}
break;
case V_79 :
V_70 = F_73 ( V_11 ) ;
V_71 = ( V_70 ^ V_60 ) & F_74 ( V_9 ) ;
if ( V_71 ) {
V_60 = V_70 ^ V_71 ;
F_53 ( V_11 , V_60 ) ;
}
break;
case V_80 :
V_70 = F_41 ( V_11 ) ;
V_71 = ( V_70 ^ V_60 ) & F_75 ( V_9 ) ;
if ( V_71 ) {
V_60 = V_70 ^ V_71 ;
F_54 ( V_11 , V_60 ) ;
}
break;
case V_63 :
V_22 = F_76 ( V_9 , V_60 ) ;
break;
case V_65 :
V_22 = F_77 ( V_9 , V_60 ) ;
break;
case V_67 :
V_22 = F_78 ( V_9 , V_60 ) ;
break;
default:
return - V_69 ;
}
return V_22 ;
}
static int F_79 ( struct V_8 * V_9 )
{
F_80 ( V_9 ) ;
return 0 ;
}
static int F_81 ( struct V_8 * V_9 )
{
return 0 ;
}
int F_82 ( struct V_81 * * V_82 )
{
* V_82 = & V_83 ;
return 0 ;
}
