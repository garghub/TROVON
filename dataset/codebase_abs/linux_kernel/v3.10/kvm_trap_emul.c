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
#ifdef F_6
F_7 ( L_2 , V_6 , V_1 , V_2 ) ;
#endif
return V_2 ;
}
static int F_8 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_9 -> V_13 . V_14 ;
unsigned long V_15 = V_9 -> V_13 . V_16 ;
enum V_17 V_18 = V_19 ;
int V_20 = V_21 ;
if ( ( ( V_15 & V_22 ) >> V_23 ) == 1 ) {
V_18 = F_9 ( V_15 , V_12 , V_11 , V_9 ) ;
} else
V_18 = F_10 ( V_15 , V_12 , V_11 , V_9 ) ;
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
F_11 () ;
}
return V_20 ;
}
static int F_12 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_9 -> V_13 . V_14 ;
unsigned long V_30 = V_9 -> V_13 . V_31 ;
unsigned long V_15 = V_9 -> V_13 . V_16 ;
enum V_17 V_18 = V_19 ;
int V_20 = V_21 ;
if ( F_13 ( V_30 ) < V_32
|| F_13 ( V_30 ) == V_33 ) {
#ifdef F_6
F_7
( L_3 ,
V_15 , V_12 , V_30 ) ;
#endif
V_18 = F_14 ( V_15 , V_12 , V_11 , V_9 ) ;
if ( V_18 == V_19 )
V_20 = V_21 ;
else {
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
}
} else if ( F_13 ( V_30 ) == V_32 ) {
F_4
( L_4 ,
V_15 , V_12 , V_30 ) ;
F_5 () ;
F_15 ( V_9 ) ;
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
} else {
F_4
( L_5 ,
V_15 , V_12 , V_30 ) ;
F_5 () ;
F_15 ( V_9 ) ;
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
}
return V_20 ;
}
static int F_16 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_9 -> V_13 . V_14 ;
unsigned long V_30 = V_9 -> V_13 . V_31 ;
unsigned long V_15 = V_9 -> V_13 . V_16 ;
enum V_17 V_18 = V_19 ;
int V_20 = V_21 ;
if ( ( ( V_30 & V_34 ) == V_35 )
&& F_17 ( V_9 ) ) {
if ( F_18 ( V_30 , V_9 ) < 0 ) {
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
}
} else if ( F_13 ( V_30 ) < V_32
|| F_13 ( V_30 ) == V_33 ) {
#ifdef F_6
F_7
( L_6 ,
V_15 , V_12 , V_30 ) ;
#endif
V_18 = F_19 ( V_15 , V_12 , V_11 , V_9 ) ;
if ( V_18 == V_19 )
V_20 = V_21 ;
else {
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
}
} else if ( F_13 ( V_30 ) == V_32 ) {
if ( F_20
( V_9 -> V_13 . V_31 , V_9 ) < 0 ) {
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
}
} else {
F_21
( L_7 ,
V_15 , V_12 , V_30 ) ;
F_5 () ;
F_15 ( V_9 ) ;
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
if ( ( ( V_30 & V_34 ) == V_35 )
&& F_17 ( V_9 ) ) {
if ( F_18 ( V_30 , V_9 ) < 0 ) {
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
}
} else if ( F_13 ( V_30 ) < V_32
|| F_13 ( V_30 ) == V_33 ) {
#ifdef F_6
F_7 ( L_8 ,
V_9 -> V_13 . V_14 , V_30 ) ;
#endif
V_18 = F_19 ( V_15 , V_12 , V_11 , V_9 ) ;
if ( V_18 == V_19 )
V_20 = V_21 ;
else {
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
}
} else if ( F_13 ( V_30 ) == V_32 ) {
if ( F_20
( V_9 -> V_13 . V_31 , V_9 ) < 0 ) {
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
}
} else {
F_4
( L_9 ,
V_15 , V_12 , V_30 ) ;
F_5 () ;
F_15 ( V_9 ) ;
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
}
return V_20 ;
}
static int F_23 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_9 -> V_13 . V_14 ;
unsigned long V_30 = V_9 -> V_13 . V_31 ;
unsigned long V_15 = V_9 -> V_13 . V_16 ;
enum V_17 V_18 = V_19 ;
int V_20 = V_21 ;
if ( F_17 ( V_9 )
&& ( F_2 ( V_30 ) == V_4 || F_2 ( V_30 ) == V_5 ) ) {
#ifdef F_6
F_7 ( L_10 ) ;
#endif
V_18 = F_10 ( V_15 , V_12 , V_11 , V_9 ) ;
if ( V_18 == V_24 ) {
F_4 ( L_11 ) ;
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
} else {
V_11 -> V_25 = V_36 ;
V_20 = V_27 ;
}
} else {
F_4
( L_12 ,
V_15 , V_12 , V_30 ) ;
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
}
return V_20 ;
}
static int F_24 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_9 -> V_13 . V_14 ;
unsigned long V_30 = V_9 -> V_13 . V_31 ;
unsigned long V_15 = V_9 -> V_13 . V_16 ;
enum V_17 V_18 = V_19 ;
int V_20 = V_21 ;
if ( F_2 ( V_30 ) == V_4 || F_2 ( V_30 ) == V_5 ) {
#ifdef F_6
F_7 ( L_13 , V_30 ) ;
#endif
V_18 = F_10 ( V_15 , V_12 , V_11 , V_9 ) ;
if ( V_18 == V_24 ) {
F_4 ( L_14 ) ;
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
} else {
V_11 -> V_25 = V_36 ;
V_20 = V_27 ;
}
} else {
F_4
( L_15 ,
V_15 , V_12 , V_30 ) ;
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
V_18 = V_24 ;
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
static int F_29 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_9 -> V_13 . V_14 ;
unsigned long V_15 = V_9 -> V_13 . V_16 ;
enum V_17 V_18 = V_19 ;
int V_20 = V_21 ;
V_18 = F_30 ( V_15 , V_12 , V_11 , V_9 ) ;
if ( V_18 == V_19 )
V_20 = V_21 ;
else {
V_11 -> V_25 = V_26 ;
V_20 = V_27 ;
}
return V_20 ;
}
static int F_31 ( struct V_37 * V_37 )
{
return 0 ;
}
static int F_32 ( struct V_8 * V_9 )
{
return 0 ;
}
static int F_33 ( struct V_8 * V_9 )
{
struct V_38 * V_39 = V_9 -> V_13 . V_39 ;
T_3 V_40 ;
int V_41 = V_9 -> V_41 ;
F_34 ( V_39 , 0x00019300 ) ;
F_35 ( V_39 ,
V_42 | ( 0x1 << V_43 ) |
( V_44 << V_45 ) ) ;
V_40 = ( F_36 () & ~ 0x7f ) ;
V_40 &= ~ ( 0x3f << 25 ) ;
V_40 |= ( ( V_46 - 1 ) << 25 ) ;
V_40 &=
~ ( ( 1 << V_47 ) | ( 1 << V_48 ) | ( 1 << V_49 ) |
( 1 << V_50 ) | ( 1 << V_51 ) ) ;
F_37 ( V_39 , V_40 ) ;
F_38 ( V_39 , V_52 ) ;
F_39 ( V_39 ,
V_53 | ( 0 << V_54 ) | ( 1 <<
V_55 ) ) ;
F_40 ( V_39 , ( V_56 ) | ( 1 << 10 ) ) ;
F_41 ( V_39 , 0xFC000000 ) ;
F_42 ( V_39 , V_32 | ( V_41 & 0xFF ) ) ;
return 0 ;
}
int F_43 ( struct V_57 * * V_58 )
{
* V_58 = & V_59 ;
return 0 ;
}
