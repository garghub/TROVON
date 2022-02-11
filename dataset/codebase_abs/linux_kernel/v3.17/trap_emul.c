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
struct V_10 * V_11 = V_9 -> V_11 ;
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_9 -> V_13 . V_14 ;
unsigned long V_15 = V_9 -> V_13 . V_16 ;
enum V_17 V_18 = V_19 ;
int V_20 = V_21 ;
if ( ( ( V_15 & V_22 ) >> V_23 ) == 1 )
V_18 = F_8 ( V_15 , V_12 , V_11 , V_9 ) ;
else
V_18 = F_9 ( V_15 , V_12 , V_11 , V_9 ) ;
switch ( V_18 ) {
case V_19 :
V_20 = V_21 ;
break;
case V_24 :
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
break;
case V_28 :
V_11 -> V_25 = V_29 ;
V_20 = V_27 ;
break;
default:
F_10 () ;
}
return V_20 ;
}
static int F_11 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_9 -> V_13 . V_14 ;
unsigned long V_30 = V_9 -> V_13 . V_31 ;
unsigned long V_15 = V_9 -> V_13 . V_16 ;
enum V_17 V_18 = V_19 ;
int V_20 = V_21 ;
if ( F_12 ( V_30 ) < V_32
|| F_12 ( V_30 ) == V_33 ) {
F_6 ( L_3 ,
V_15 , V_12 , V_30 ) ;
V_18 = F_13 ( V_15 , V_12 , V_11 , V_9 ) ;
if ( V_18 == V_19 )
V_20 = V_21 ;
else {
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
}
} else if ( F_12 ( V_30 ) == V_32 ) {
F_4 ( L_4 ,
V_15 , V_12 , V_30 ) ;
F_5 () ;
F_14 ( V_9 ) ;
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
} else {
F_4 ( L_5 ,
V_15 , V_12 , V_30 ) ;
F_5 () ;
F_14 ( V_9 ) ;
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
}
return V_20 ;
}
static int F_15 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_9 -> V_13 . V_14 ;
unsigned long V_30 = V_9 -> V_13 . V_31 ;
unsigned long V_15 = V_9 -> V_13 . V_16 ;
enum V_17 V_18 = V_19 ;
int V_20 = V_21 ;
if ( ( ( V_30 & V_34 ) == V_35 )
&& F_16 ( V_9 ) ) {
if ( F_17 ( V_30 , V_9 ) < 0 ) {
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
}
} else if ( F_12 ( V_30 ) < V_32
|| F_12 ( V_30 ) == V_33 ) {
F_6 ( L_6 ,
V_15 , V_12 , V_30 ) ;
V_18 = F_18 ( V_15 , V_12 , V_11 , V_9 ) ;
if ( V_18 == V_19 )
V_20 = V_21 ;
else {
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
}
} else if ( F_12 ( V_30 ) == V_32 ) {
if ( F_19
( V_9 -> V_13 . V_31 , V_9 ) < 0 ) {
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
}
} else {
F_4 ( L_7 ,
V_15 , V_12 , V_30 ) ;
F_5 () ;
F_14 ( V_9 ) ;
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
}
return V_20 ;
}
static int F_20 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_9 -> V_13 . V_14 ;
unsigned long V_30 = V_9 -> V_13 . V_31 ;
unsigned long V_15 = V_9 -> V_13 . V_16 ;
enum V_17 V_18 = V_19 ;
int V_20 = V_21 ;
if ( ( ( V_30 & V_34 ) == V_35 )
&& F_16 ( V_9 ) ) {
if ( F_17 ( V_30 , V_9 ) < 0 ) {
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
}
} else if ( F_12 ( V_30 ) < V_32
|| F_12 ( V_30 ) == V_33 ) {
F_6 ( L_8 ,
V_9 -> V_13 . V_14 , V_30 ) ;
V_18 = F_18 ( V_15 , V_12 , V_11 , V_9 ) ;
if ( V_18 == V_19 )
V_20 = V_21 ;
else {
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
}
} else if ( F_12 ( V_30 ) == V_32 ) {
if ( F_19
( V_9 -> V_13 . V_31 , V_9 ) < 0 ) {
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
}
} else {
F_4 ( L_9 ,
V_15 , V_12 , V_30 ) ;
F_5 () ;
F_14 ( V_9 ) ;
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
}
return V_20 ;
}
static int F_21 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_9 -> V_13 . V_14 ;
unsigned long V_30 = V_9 -> V_13 . V_31 ;
unsigned long V_15 = V_9 -> V_13 . V_16 ;
enum V_17 V_18 = V_19 ;
int V_20 = V_21 ;
if ( F_16 ( V_9 )
&& ( F_2 ( V_30 ) == V_4 || F_2 ( V_30 ) == V_5 ) ) {
F_6 ( L_10 ) ;
V_18 = F_9 ( V_15 , V_12 , V_11 , V_9 ) ;
if ( V_18 == V_24 ) {
F_4 ( L_11 ) ;
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
} else {
V_11 -> V_25 = V_36 ;
V_20 = V_27 ;
}
} else {
F_4 ( L_12 ,
V_15 , V_12 , V_30 ) ;
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
}
return V_20 ;
}
static int F_22 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_9 -> V_13 . V_14 ;
unsigned long V_30 = V_9 -> V_13 . V_31 ;
unsigned long V_15 = V_9 -> V_13 . V_16 ;
enum V_17 V_18 = V_19 ;
int V_20 = V_21 ;
if ( F_2 ( V_30 ) == V_4 || F_2 ( V_30 ) == V_5 ) {
F_6 ( L_13 , V_30 ) ;
V_18 = F_9 ( V_15 , V_12 , V_11 , V_9 ) ;
if ( V_18 == V_24 ) {
F_4 ( L_14 ) ;
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
} else {
V_11 -> V_25 = V_36 ;
V_20 = V_27 ;
}
} else {
F_4 ( L_15 ,
V_15 , V_12 , V_30 ) ;
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
V_18 = V_24 ;
}
return V_20 ;
}
static int F_23 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_9 -> V_13 . V_14 ;
unsigned long V_15 = V_9 -> V_13 . V_16 ;
enum V_17 V_18 = V_19 ;
int V_20 = V_21 ;
V_18 = F_24 ( V_15 , V_12 , V_11 , V_9 ) ;
if ( V_18 == V_19 )
V_20 = V_21 ;
else {
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
}
return V_20 ;
}
static int F_25 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_9 -> V_13 . V_14 ;
unsigned long V_15 = V_9 -> V_13 . V_16 ;
enum V_17 V_18 = V_19 ;
int V_20 = V_21 ;
V_18 = F_26 ( V_15 , V_12 , V_11 , V_9 ) ;
if ( V_18 == V_19 )
V_20 = V_21 ;
else {
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
}
return V_20 ;
}
static int F_27 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_9 -> V_13 . V_14 ;
unsigned long V_15 = V_9 -> V_13 . V_16 ;
enum V_17 V_18 = V_19 ;
int V_20 = V_21 ;
V_18 = F_28 ( V_15 , V_12 , V_11 , V_9 ) ;
if ( V_18 == V_19 )
V_20 = V_21 ;
else {
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
}
return V_20 ;
}
static int F_29 ( struct V_37 * V_37 )
{
return 0 ;
}
static int F_30 ( struct V_8 * V_9 )
{
return 0 ;
}
static int F_31 ( struct V_8 * V_9 )
{
struct V_38 * V_39 = V_9 -> V_13 . V_39 ;
T_3 V_40 ;
int V_41 = V_9 -> V_41 ;
F_32 ( V_39 , 0x00019300 ) ;
F_33 ( V_39 ,
V_42 | ( 0x1 << V_43 ) |
( V_44 << V_45 ) ) ;
V_40 = ( F_34 () & ~ 0x7f ) ;
V_40 &= ~ ( 0x3f << 25 ) ;
V_40 |= ( ( V_46 - 1 ) << 25 ) ;
V_40 &=
~ ( ( 1 << V_47 ) | ( 1 << V_48 ) | ( 1 << V_49 ) |
( 1 << V_50 ) | ( 1 << V_51 ) ) ;
F_35 ( V_39 , V_40 ) ;
F_36 ( V_39 , V_52 ) ;
F_37 ( V_39 , V_53 | ( 0 << V_54 ) |
( 1 << V_55 ) ) ;
F_38 ( V_39 , ( V_56 ) | ( 1 << 10 ) ) ;
F_39 ( V_39 , 0xFC000000 ) ;
F_40 ( V_39 , V_32 | ( V_41 & 0xFF ) ) ;
return 0 ;
}
static int F_41 ( struct V_8 * V_9 ,
const struct V_57 * V_58 ,
T_5 * V_59 )
{
switch ( V_58 -> V_60 ) {
case V_61 :
* V_59 = F_42 ( V_9 ) ;
break;
case V_62 :
* V_59 = V_9 -> V_13 . V_63 ;
break;
case V_64 :
* V_59 = F_43 ( V_9 -> V_13 . V_65 ) ;
break;
case V_66 :
* V_59 = V_9 -> V_13 . V_67 ;
break;
default:
return - V_68 ;
}
return 0 ;
}
static int F_44 ( struct V_8 * V_9 ,
const struct V_57 * V_58 ,
T_5 V_59 )
{
struct V_38 * V_39 = V_9 -> V_13 . V_39 ;
int V_20 = 0 ;
switch ( V_58 -> V_60 ) {
case V_61 :
F_45 ( V_9 , V_59 ) ;
break;
case V_69 :
F_46 ( V_9 , V_59 ) ;
break;
case V_70 :
if ( ( F_47 ( V_39 ) ^ V_59 ) & V_71 ) {
if ( V_59 & V_71 ) {
F_48 ( V_9 ) ;
F_49 ( V_39 , ~ V_71 , V_59 ) ;
} else {
F_49 ( V_39 , ~ V_71 , V_59 ) ;
F_50 ( V_9 ) ;
}
} else {
F_51 ( V_39 , V_59 ) ;
}
break;
case V_62 :
V_20 = F_52 ( V_9 , V_59 ) ;
break;
case V_64 :
V_20 = F_53 ( V_9 , V_59 ) ;
break;
case V_66 :
V_20 = F_54 ( V_9 , V_59 ) ;
break;
default:
return - V_68 ;
}
return V_20 ;
}
int F_55 ( struct V_72 * * V_73 )
{
* V_73 = & V_74 ;
return 0 ;
}
