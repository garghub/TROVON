static inline T_1 F_1 ( unsigned long V_1 )
{
if ( ! V_1 )
return 0xffff ;
return F_2 ( 5400000 / V_1 , 1 , 0xfffe ) ;
}
static int F_3 ( int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 15 ; ++ V_3 ) {
if ( V_2 <= ( V_4 [ V_3 ] + V_4 [ V_3 + 1 ] ) / 2 )
break;
}
return V_3 ;
}
static int F_4 ( const int * V_5 , int V_6 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 7 ; ++ V_3 )
if ( V_6 <= ( V_5 [ V_3 ] + V_5 [ V_3 + 1 ] ) / 2 )
break;
return V_3 ;
}
static int F_5 ( const int * V_5 , T_2 V_7 )
{
return V_5 [ V_7 & 0x07 ] ;
}
static int F_6 ( int V_8 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 <= 7 ; ++ V_3 )
if ( V_8 == V_9 [ V_3 ] )
break;
if ( V_3 > 7 )
V_3 = 3 ;
return V_3 << 5 ;
}
static T_3 F_7 ( struct V_10 * V_11 , struct V_12 * V_13 ,
char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , F_10 ( V_18 -> V_19 [ V_15 ] ) ) ;
}
static T_3 F_11 ( struct V_10 * V_11 , struct V_12 * V_13 ,
char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , F_10 ( V_18 -> V_20 [ V_15 ] ) ) ;
}
static T_3 F_12 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_4 V_21 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
unsigned long V_1 ;
int V_24 ;
V_24 = F_15 ( V_14 , 10 , & V_1 ) ;
if ( V_24 )
return V_24 ;
F_16 ( & V_18 -> V_25 ) ;
V_18 -> V_20 [ V_15 ] = F_1 ( V_1 ) ;
F_17 ( V_23 , F_18 ( V_15 ) , V_18 -> V_20 [ V_15 ] ) ;
F_19 ( & V_18 -> V_25 ) ;
return V_21 ;
}
static T_3 F_20 ( struct V_10 * V_11 , struct V_12 * V_13 ,
char * V_14 )
{
struct V_17 * V_18 = F_9 ( V_11 ) ;
int V_26 ;
if ( V_18 -> V_27 ) {
V_26 = F_21 ( V_18 -> V_26 & 0x3f , V_18 -> V_28 ) ;
} else {
V_26 = F_21 ( V_18 -> V_26 & 0x1f , V_18 -> V_28 ) ;
}
return sprintf ( V_14 , L_1 , V_26 ) ;
}
static T_3 F_22 ( struct V_10 * V_11 , struct V_12 * V_13 ,
char * V_14 )
{
struct V_17 * V_18 = F_23 ( V_11 ) ;
return sprintf ( V_14 , L_2 , ( long ) V_18 -> V_28 ) ;
}
static T_3 F_24 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_4 V_21 )
{
struct V_17 * V_18 = F_23 ( V_11 ) ;
unsigned long V_1 ;
int V_24 ;
V_24 = F_15 ( V_14 , 10 , & V_1 ) ;
if ( V_24 )
return V_24 ;
V_18 -> V_28 = V_1 ;
return V_21 ;
}
static T_3 F_25 ( struct V_10 * V_11 , struct V_12
* V_13 , char * V_14 )
{
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_3 , V_18 -> V_29 ) ;
}
static T_3 F_26 ( struct V_10 * V_11 , struct V_12 * V_13 ,
char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_3 , ( V_18 -> V_29 >> V_15 ) & 1 ) ;
}
static T_3 F_27 ( struct V_10 * V_11 , struct V_12 * V_13 ,
char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , F_28 ( V_18 -> V_30 [ V_15 ] ) ) ;
}
static T_3 F_29 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_4 V_21 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
unsigned long V_1 ;
int V_24 ;
V_24 = F_15 ( V_14 , 10 , & V_1 ) ;
if ( V_24 )
return V_24 ;
F_16 ( & V_18 -> V_25 ) ;
V_18 -> V_30 [ V_15 ] = F_30 ( V_1 ) ;
F_17 ( V_23 , F_31 ( V_15 ) , V_18 -> V_30 [ V_15 ] ) ;
F_19 ( & V_18 -> V_25 ) ;
return V_21 ;
}
static T_3 F_32 ( struct V_10 * V_11 , struct V_12
* V_13 , char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
int V_31 , V_32 ;
V_31 = F_33 ( V_18 -> V_33 [ V_15 ] . V_34 ) ;
switch ( V_31 ) {
case - 1 :
V_32 = 0 ;
break;
case 0 :
case - 2 :
V_32 = 1 ;
break;
default:
V_32 = 2 ;
}
return sprintf ( V_14 , L_1 , V_32 ) ;
}
static T_3 F_34 ( struct V_10 * V_11 , struct V_12
* V_13 , const char * V_14 , T_4 V_21 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
T_2 V_34 ;
unsigned long V_1 ;
int V_24 ;
V_24 = F_15 ( V_14 , 10 , & V_1 ) ;
if ( V_24 )
return V_24 ;
switch ( V_1 ) {
case 0 :
V_34 = 3 ;
break;
case 1 :
V_34 = 7 ;
break;
case 2 :
V_34 = 6 ;
break;
default:
return - V_35 ;
}
F_16 ( & V_18 -> V_25 ) ;
V_18 -> V_33 [ V_15 ] . V_34 = F_35 ( V_23 ,
F_36 ( V_15 ) ) ;
V_18 -> V_33 [ V_15 ] . V_34 = ( V_18 -> V_33 [ V_15 ] . V_34 & ~ 0xe0 )
| ( V_34 << 5 ) ;
F_17 ( V_23 , F_36 ( V_15 ) ,
V_18 -> V_33 [ V_15 ] . V_34 ) ;
F_19 ( & V_18 -> V_25 ) ;
return V_21 ;
}
static T_3 F_37 ( struct V_10 * V_11 ,
struct V_12 * V_13 , char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
int V_6 ;
if ( F_38 ( V_18 ) )
V_6 = 22500 ;
else
V_6 = F_5 ( V_18 -> V_36 , V_18 -> V_37 [ V_15 ] ) ;
return sprintf ( V_14 , L_1 , V_6 ) ;
}
static T_3 F_39 ( struct V_10 * V_11 ,
struct V_12 * V_13 , const char * V_14 , T_4 V_21 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
unsigned long V_1 ;
int V_24 ;
V_24 = F_15 ( V_14 , 10 , & V_1 ) ;
if ( V_24 )
return V_24 ;
F_16 ( & V_18 -> V_25 ) ;
if ( V_18 -> type == V_38 && V_1 >= 11300 ) {
V_18 -> V_39 &= ~ V_40 ;
F_17 ( V_23 , V_41 , V_18 -> V_39 ) ;
} else {
V_18 -> V_37 [ V_15 ] = F_4 ( V_18 -> V_36 , V_1 ) ;
F_17 ( V_23 , F_40 ( V_15 ) ,
( V_18 -> V_8 [ V_15 ] . V_2 << 4 )
| V_18 -> V_37 [ V_15 ] ) ;
if ( V_18 -> type == V_38 ) {
V_18 -> V_39 |= V_40 ;
F_17 ( V_23 , V_41 , V_18 -> V_39 ) ;
}
}
F_19 ( & V_18 -> V_25 ) ;
return V_21 ;
}
static T_3 F_41 ( struct V_10 * V_11 , struct V_12 * V_13 ,
char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , F_42 ( V_15 , V_18 -> V_42 [ V_15 ] ,
V_18 -> V_43 [ V_15 ] ) ) ;
}
static T_3 F_43 ( struct V_10 * V_11 , struct V_12 * V_13 ,
char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , F_44 ( V_15 , V_18 -> V_44 [ V_15 ] ) ) ;
}
static T_3 F_45 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_4 V_21 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
long V_1 ;
int V_24 ;
V_24 = F_46 ( V_14 , 10 , & V_1 ) ;
if ( V_24 )
return V_24 ;
F_16 ( & V_18 -> V_25 ) ;
V_18 -> V_44 [ V_15 ] = F_47 ( V_15 , V_1 ) ;
F_17 ( V_23 , F_48 ( V_15 ) , V_18 -> V_44 [ V_15 ] ) ;
F_19 ( & V_18 -> V_25 ) ;
return V_21 ;
}
static T_3 F_49 ( struct V_10 * V_11 , struct V_12 * V_13 ,
char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , F_44 ( V_15 , V_18 -> V_45 [ V_15 ] ) ) ;
}
static T_3 F_50 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_4 V_21 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
long V_1 ;
int V_24 ;
V_24 = F_46 ( V_14 , 10 , & V_1 ) ;
if ( V_24 )
return V_24 ;
F_16 ( & V_18 -> V_25 ) ;
V_18 -> V_45 [ V_15 ] = F_47 ( V_15 , V_1 ) ;
F_17 ( V_23 , F_51 ( V_15 ) , V_18 -> V_45 [ V_15 ] ) ;
F_19 ( & V_18 -> V_25 ) ;
return V_21 ;
}
static T_3 F_52 ( struct V_10 * V_11 , struct V_12 * V_13 ,
char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , F_53 ( V_18 -> V_46 [ V_15 ] ,
V_18 -> V_47 [ V_15 ] ) ) ;
}
static T_3 F_54 ( struct V_10 * V_11 , struct V_12 * V_13 ,
char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , F_55 ( V_18 -> V_48 [ V_15 ] ) ) ;
}
static T_3 F_56 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_4 V_21 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
long V_1 ;
int V_24 ;
V_24 = F_46 ( V_14 , 10 , & V_1 ) ;
if ( V_24 )
return V_24 ;
if ( F_57 ( V_18 ) )
V_1 += 64 ;
F_16 ( & V_18 -> V_25 ) ;
V_18 -> V_48 [ V_15 ] = F_58 ( V_1 ) ;
F_17 ( V_23 , F_59 ( V_15 ) , V_18 -> V_48 [ V_15 ] ) ;
F_19 ( & V_18 -> V_25 ) ;
return V_21 ;
}
static T_3 F_60 ( struct V_10 * V_11 , struct V_12 * V_13 ,
char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , F_55 ( V_18 -> V_49 [ V_15 ] ) ) ;
}
static T_3 F_61 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_4 V_21 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
long V_1 ;
int V_24 ;
V_24 = F_46 ( V_14 , 10 , & V_1 ) ;
if ( V_24 )
return V_24 ;
if ( F_57 ( V_18 ) )
V_1 += 64 ;
F_16 ( & V_18 -> V_25 ) ;
V_18 -> V_49 [ V_15 ] = F_58 ( V_1 ) ;
F_17 ( V_23 , F_62 ( V_15 ) , V_18 -> V_49 [ V_15 ] ) ;
F_19 ( & V_18 -> V_25 ) ;
return V_21 ;
}
static T_3 F_63 ( struct V_10 * V_11 ,
struct V_12 * V_13 , char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , F_33 ( V_18 -> V_33 [ V_15 ] . V_34 ) ) ;
}
static T_3 F_64 ( struct V_10 * V_11 ,
struct V_12 * V_13 , const char * V_14 , T_4 V_21 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
long V_1 ;
int V_24 ;
V_24 = F_46 ( V_14 , 10 , & V_1 ) ;
if ( V_24 )
return V_24 ;
F_16 ( & V_18 -> V_25 ) ;
V_18 -> V_33 [ V_15 ] . V_34 = ( V_18 -> V_33 [ V_15 ] . V_34 & ( ~ 0xe0 ) )
| F_6 ( V_1 ) ;
F_17 ( V_23 , F_36 ( V_15 ) ,
V_18 -> V_33 [ V_15 ] . V_34 ) ;
F_19 ( & V_18 -> V_25 ) ;
return V_21 ;
}
static T_3 F_65 ( struct V_10 * V_11 ,
struct V_12 * V_13 , char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , F_28 ( V_18 -> V_33 [ V_15 ] . V_50 ) ) ;
}
static T_3 F_66 ( struct V_10 * V_11 ,
struct V_12 * V_13 , const char * V_14 , T_4 V_21 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
unsigned long V_1 ;
int V_24 ;
V_24 = F_15 ( V_14 , 10 , & V_1 ) ;
if ( V_24 )
return V_24 ;
F_16 ( & V_18 -> V_25 ) ;
V_18 -> V_33 [ V_15 ] . V_50 = F_30 ( V_1 ) ;
F_17 ( V_23 , F_67 ( V_15 ) ,
V_18 -> V_33 [ V_15 ] . V_50 ) ;
F_19 ( & V_18 -> V_25 ) ;
return V_21 ;
}
static T_3 F_68 ( struct V_10 * V_11 ,
struct V_12 * V_13 , char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , V_18 -> V_33 [ V_15 ] . V_51 ) ;
}
static T_3 F_69 ( struct V_10 * V_11 ,
struct V_12 * V_13 , const char * V_14 , T_4 V_21 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
T_2 V_52 ;
long V_1 ;
int V_24 ;
V_24 = F_46 ( V_14 , 10 , & V_1 ) ;
if ( V_24 )
return V_24 ;
F_16 ( & V_18 -> V_25 ) ;
V_18 -> V_33 [ V_15 ] . V_51 = V_1 ;
V_52 = F_35 ( V_23 , V_53 ) ;
V_52 &= ~ ( 0x20 << V_15 ) ;
if ( V_18 -> V_33 [ V_15 ] . V_51 )
V_52 |= 0x20 << V_15 ;
F_17 ( V_23 , V_53 , V_52 ) ;
F_19 ( & V_18 -> V_25 ) ;
return V_21 ;
}
static T_3 F_70 ( struct V_10 * V_11 ,
struct V_12 * V_13 , char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , F_55 ( V_18 -> V_8 [ V_15 ] . V_54 ) -
F_71 ( V_18 -> V_8 [ V_15 ] . V_55 ) ) ;
}
static T_3 F_72 ( struct V_10 * V_11 ,
struct V_12 * V_13 , const char * V_14 , T_4 V_21 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
int V_56 ;
long V_1 ;
int V_24 ;
V_24 = F_46 ( V_14 , 10 , & V_1 ) ;
if ( V_24 )
return V_24 ;
F_16 ( & V_18 -> V_25 ) ;
V_56 = F_55 ( V_18 -> V_8 [ V_15 ] . V_54 ) ;
V_18 -> V_8 [ V_15 ] . V_55 = F_73 ( V_56 - V_1 ) ;
if ( V_15 == 0 || V_15 == 1 ) {
F_17 ( V_23 , V_57 ,
( V_18 -> V_8 [ 0 ] . V_55 << 4 )
| V_18 -> V_8 [ 1 ] . V_55 ) ;
} else {
F_17 ( V_23 , V_58 ,
( V_18 -> V_8 [ 2 ] . V_55 << 4 ) ) ;
}
F_19 ( & V_18 -> V_25 ) ;
return V_21 ;
}
static T_3 F_74 ( struct V_10 * V_11 ,
struct V_12 * V_13 , char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , F_55 ( V_18 -> V_8 [ V_15 ] . V_54 ) ) ;
}
static T_3 F_75 ( struct V_10 * V_11 ,
struct V_12 * V_13 , const char * V_14 , T_4 V_21 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
long V_1 ;
int V_24 ;
V_24 = F_46 ( V_14 , 10 , & V_1 ) ;
if ( V_24 )
return V_24 ;
F_16 ( & V_18 -> V_25 ) ;
V_18 -> V_8 [ V_15 ] . V_54 = F_58 ( V_1 ) ;
F_17 ( V_23 , F_76 ( V_15 ) ,
V_18 -> V_8 [ V_15 ] . V_54 ) ;
V_18 -> V_8 [ V_15 ] . V_2 = F_3 (
F_55 ( V_18 -> V_8 [ V_15 ] . V_59 ) -
F_55 ( V_18 -> V_8 [ V_15 ] . V_54 ) ) ;
F_17 ( V_23 , F_40 ( V_15 ) ,
( ( V_18 -> V_8 [ V_15 ] . V_2 & 0x0f ) << 4 )
| ( V_18 -> V_37 [ V_15 ] & 0x07 ) ) ;
F_19 ( & V_18 -> V_25 ) ;
return V_21 ;
}
static T_3 F_77 ( struct V_10 * V_11 ,
struct V_12 * V_13 , char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , F_55 ( V_18 -> V_8 [ V_15 ] . V_54 ) +
F_78 ( V_18 -> V_8 [ V_15 ] . V_2 ) ) ;
}
static T_3 F_79 ( struct V_10 * V_11 ,
struct V_12 * V_13 , const char * V_14 , T_4 V_21 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
int V_56 ;
long V_1 ;
int V_24 ;
V_24 = F_46 ( V_14 , 10 , & V_1 ) ;
if ( V_24 )
return V_24 ;
F_16 ( & V_18 -> V_25 ) ;
V_56 = F_55 ( V_18 -> V_8 [ V_15 ] . V_54 ) ;
V_18 -> V_8 [ V_15 ] . V_59 = F_58 ( V_1 ) ;
V_18 -> V_8 [ V_15 ] . V_2 = F_3 (
V_1 - V_56 ) ;
F_17 ( V_23 , F_40 ( V_15 ) ,
( ( V_18 -> V_8 [ V_15 ] . V_2 & 0x0f ) << 4 )
| ( V_18 -> V_37 [ V_15 ] & 0x07 ) ) ;
F_19 ( & V_18 -> V_25 ) ;
return V_21 ;
}
static T_3 F_80 ( struct V_10 * V_11 ,
struct V_12 * V_13 , char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , F_55 ( V_18 -> V_8 [ V_15 ] . V_60 ) ) ;
}
static T_3 F_81 ( struct V_10 * V_11 ,
struct V_12 * V_13 , const char * V_14 , T_4 V_21 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
long V_1 ;
int V_24 ;
V_24 = F_46 ( V_14 , 10 , & V_1 ) ;
if ( V_24 )
return V_24 ;
F_16 ( & V_18 -> V_25 ) ;
V_18 -> V_8 [ V_15 ] . V_60 = F_58 ( V_1 ) ;
F_17 ( V_23 , F_82 ( V_15 ) ,
V_18 -> V_8 [ V_15 ] . V_60 ) ;
F_19 ( & V_18 -> V_25 ) ;
return V_21 ;
}
static void F_83 ( struct V_22 * V_23 )
{
int V_61 ;
V_61 = F_35 ( V_23 , V_62 ) ;
if ( ! ( V_61 & 0x01 ) ) {
F_84 ( & V_23 -> V_11 , L_4 ) ;
F_17 ( V_23 , V_62 , V_61 | 0x01 ) ;
}
if ( V_61 & 0x02 )
F_85 ( & V_23 -> V_11 , L_5 ) ;
if ( ! ( V_61 & 0x04 ) )
F_85 ( & V_23 -> V_11 , L_6 ) ;
}
static int F_86 ( struct V_22 * V_23 )
{
int V_3 ;
T_2 V_63 , V_19 ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
V_63 = F_87 ( V_23 , 0x20 + V_3 ) ;
V_19 = F_87 ( V_23 , 0x28 + V_3 ) ;
if ( V_63 != 0x00 || V_19 != 0xff )
return 0 ;
}
return 1 ;
}
static int F_88 ( struct V_22 * V_23 , struct V_64 * V_65 )
{
struct V_66 * V_67 = V_23 -> V_67 ;
int V_68 = V_23 -> V_69 ;
const char * V_70 = NULL ;
int V_71 , V_72 ;
if ( ! F_89 ( V_67 , V_73 ) ) {
return - V_74 ;
}
V_71 = F_35 ( V_23 , V_75 ) ;
V_72 = F_35 ( V_23 , V_76 ) ;
F_90 ( & V_67 -> V_11 ,
L_7 ,
V_68 , V_71 , V_72 ) ;
if ( V_71 == V_77 ) {
switch ( V_72 ) {
case V_78 :
V_70 = L_8 ;
break;
case V_79 :
V_70 = L_9 ;
break;
case V_80 :
case V_81 :
if ( F_86 ( V_23 ) ) {
F_90 ( & V_67 -> V_11 ,
L_10 ) ;
return - V_74 ;
}
V_70 = L_11 ;
break;
}
} else if ( V_71 == V_82 ) {
switch ( V_72 ) {
case V_83 :
V_70 = L_12 ;
break;
case V_84 :
case V_85 :
V_70 = L_13 ;
break;
case V_86 :
case V_87 :
V_70 = L_14 ;
break;
}
} else if ( V_71 == V_88 ) {
switch ( V_72 ) {
case V_89 :
case V_90 :
V_70 = L_15 ;
break;
case V_91 :
V_70 = L_16 ;
break;
case V_92 :
case V_93 :
V_70 = L_17 ;
break;
case V_94 :
V_70 = L_18 ;
break;
}
}
if ( ! V_70 )
return - V_74 ;
F_91 ( V_65 -> type , V_70 , V_95 ) ;
return 0 ;
}
static void F_92 ( struct V_22 * V_23 , struct V_17 * V_18 )
{
F_93 ( & V_23 -> V_11 . V_96 , & V_97 ) ;
if ( V_18 -> type != V_98 ) {
F_93 ( & V_23 -> V_11 . V_96 , & V_99 ) ;
F_93 ( & V_23 -> V_11 . V_96 , & V_100 ) ;
}
if ( ! V_18 -> V_27 )
F_93 ( & V_23 -> V_11 . V_96 , & V_101 ) ;
if ( V_18 -> type == V_102 )
F_93 ( & V_23 -> V_11 . V_96 , & V_103 ) ;
}
static int F_94 ( struct V_22 * V_23 ,
const struct V_104 * V_105 )
{
struct V_17 * V_18 ;
int V_24 ;
V_18 = F_95 ( & V_23 -> V_11 , sizeof( struct V_17 ) , V_106 ) ;
if ( ! V_18 )
return - V_107 ;
F_96 ( V_23 , V_18 ) ;
V_18 -> type = V_105 -> V_108 ;
F_97 ( & V_18 -> V_25 ) ;
switch ( V_18 -> type ) {
case V_109 :
case V_110 :
case V_38 :
case V_102 :
case V_111 :
case V_112 :
case V_98 :
V_18 -> V_36 = V_113 ;
break;
default:
V_18 -> V_36 = V_114 ;
}
V_18 -> V_28 = F_98 () ;
F_83 ( V_23 ) ;
V_24 = F_99 ( & V_23 -> V_11 . V_96 , & V_97 ) ;
if ( V_24 )
return V_24 ;
if ( V_18 -> type != V_98 ) {
V_24 = F_99 ( & V_23 -> V_11 . V_96 , & V_99 ) ;
if ( V_24 )
goto V_115;
V_24 = F_99 ( & V_23 -> V_11 . V_96 ,
& V_100 ) ;
if ( V_24 )
goto V_115;
}
if ( V_18 -> type == V_110 || V_18 -> type == V_38 ) {
T_2 V_26 = F_35 ( V_23 , V_116 ) ;
if ( V_26 & 0x80 )
V_18 -> V_27 = true ;
}
if ( ! V_18 -> V_27 ) {
V_24 = F_99 ( & V_23 -> V_11 . V_96 , & V_101 ) ;
if ( V_24 )
goto V_115;
}
if ( V_18 -> type == V_102 ) {
V_24 = F_99 ( & V_23 -> V_11 . V_96 , & V_103 ) ;
if ( V_24 )
goto V_115;
}
V_18 -> V_117 = F_100 ( & V_23 -> V_11 ) ;
if ( F_101 ( V_18 -> V_117 ) ) {
V_24 = F_102 ( V_18 -> V_117 ) ;
goto V_115;
}
return 0 ;
V_115:
F_92 ( V_23 , V_18 ) ;
return V_24 ;
}
static int F_103 ( struct V_22 * V_23 )
{
struct V_17 * V_18 = F_14 ( V_23 ) ;
F_104 ( V_18 -> V_117 ) ;
F_92 ( V_23 , V_18 ) ;
return 0 ;
}
static int F_35 ( struct V_22 * V_23 , T_2 V_7 )
{
int V_118 ;
switch ( V_7 ) {
case F_105 ( 0 ) :
case F_105 ( 1 ) :
case F_105 ( 2 ) :
case F_105 ( 3 ) :
case F_18 ( 0 ) :
case F_18 ( 1 ) :
case F_18 ( 2 ) :
case F_18 ( 3 ) :
case V_119 :
V_118 = F_87 ( V_23 , V_7 ) & 0xff ;
V_118 |= F_87 ( V_23 , V_7 + 1 ) << 8 ;
break;
default:
V_118 = F_87 ( V_23 , V_7 ) ;
break;
}
return V_118 ;
}
static void F_17 ( struct V_22 * V_23 , T_2 V_7 , int V_61 )
{
switch ( V_7 ) {
case F_105 ( 0 ) :
case F_105 ( 1 ) :
case F_105 ( 2 ) :
case F_105 ( 3 ) :
case F_18 ( 0 ) :
case F_18 ( 1 ) :
case F_18 ( 2 ) :
case F_18 ( 3 ) :
F_106 ( V_23 , V_7 , V_61 & 0xff ) ;
F_106 ( V_23 , V_7 + 1 , V_61 >> 8 ) ;
break;
default:
F_106 ( V_23 , V_7 , V_61 ) ;
break;
}
}
static struct V_17 * F_9 ( struct V_10 * V_11 )
{
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
int V_3 ;
F_16 ( & V_18 -> V_25 ) ;
if ( ! V_18 -> V_120 ||
F_107 ( V_121 , V_18 -> V_122 + V_123 ) ) {
F_90 ( & V_23 -> V_11 , L_19 ) ;
if ( V_18 -> type == V_109 || V_18 -> type == V_110 ||
V_18 -> type == V_38 ) {
int V_124 = F_35 ( V_23 ,
V_125 ) ;
int V_126 = F_35 ( V_23 ,
V_127 ) ;
int V_1 = ( V_124 << 8 ) + V_126 ;
for ( V_3 = 0 ; V_3 <= 4 ; V_3 ++ )
V_18 -> V_43 [ V_3 ] =
( ( V_1 >> ( V_3 * 2 ) ) & 0x03 ) << 2 ;
for ( V_3 = 0 ; V_3 <= 2 ; V_3 ++ )
V_18 -> V_47 [ V_3 ] =
( V_1 >> ( ( V_3 + 4 ) * 2 ) ) & 0x0c ;
}
V_18 -> V_26 = F_35 ( V_23 , V_116 ) ;
for ( V_3 = 0 ; V_3 <= 3 ; ++ V_3 ) {
V_18 -> V_42 [ V_3 ] =
F_35 ( V_23 , F_108 ( V_3 ) ) ;
V_18 -> V_19 [ V_3 ] =
F_35 ( V_23 , F_105 ( V_3 ) ) ;
}
if ( ! V_18 -> V_27 )
V_18 -> V_42 [ 4 ] = F_35 ( V_23 , F_108 ( 4 ) ) ;
if ( V_18 -> type == V_38 )
V_18 -> V_39 = F_35 ( V_23 , V_41 ) ;
for ( V_3 = 0 ; V_3 <= 2 ; ++ V_3 ) {
V_18 -> V_46 [ V_3 ] =
F_35 ( V_23 , F_109 ( V_3 ) ) ;
V_18 -> V_30 [ V_3 ] =
F_35 ( V_23 , F_31 ( V_3 ) ) ;
if ( F_57 ( V_18 ) )
V_18 -> V_46 [ V_3 ] -= 64 ;
}
V_18 -> V_29 = F_35 ( V_23 , V_119 ) ;
if ( V_18 -> type == V_102 ) {
for ( V_3 = 5 ; V_3 <= 7 ; ++ V_3 ) {
V_18 -> V_42 [ V_3 ] = F_35 ( V_23 ,
F_110 ( V_3 ) ) ;
}
V_18 -> V_29 |= F_35 ( V_23 ,
V_128 ) << 16 ;
} else if ( V_18 -> type == V_111 || V_18 -> type == V_112 ||
V_18 -> type == V_98 ) {
int V_124 = F_35 ( V_23 ,
V_129 ) ;
int V_126 = F_35 ( V_23 ,
V_130 ) ;
int V_131 = F_35 ( V_23 ,
V_132 ) ;
int V_133 = F_35 ( V_23 ,
V_134 ) ;
V_18 -> V_43 [ 0 ] = V_131 & 0x0f ;
V_18 -> V_43 [ 1 ] = V_133 & 0x0f ;
V_18 -> V_43 [ 2 ] = V_133 >> 4 ;
V_18 -> V_43 [ 3 ] = V_131 >> 4 ;
V_18 -> V_43 [ 4 ] = V_126 >> 4 ;
V_18 -> V_47 [ 0 ] = V_124 & 0x0f ;
V_18 -> V_47 [ 1 ] = V_126 & 0x0f ;
V_18 -> V_47 [ 2 ] = V_124 >> 4 ;
}
V_18 -> V_122 = V_121 ;
}
if ( ! V_18 -> V_120 ||
F_107 ( V_121 , V_18 -> V_135 + V_136 ) ) {
F_90 ( & V_23 -> V_11 , L_20 ) ;
for ( V_3 = 0 ; V_3 <= 3 ; ++ V_3 ) {
V_18 -> V_44 [ V_3 ] =
F_35 ( V_23 , F_48 ( V_3 ) ) ;
V_18 -> V_45 [ V_3 ] =
F_35 ( V_23 , F_51 ( V_3 ) ) ;
V_18 -> V_20 [ V_3 ] =
F_35 ( V_23 , F_18 ( V_3 ) ) ;
}
if ( ! V_18 -> V_27 ) {
V_18 -> V_44 [ 4 ] = F_35 ( V_23 ,
F_48 ( 4 ) ) ;
V_18 -> V_45 [ 4 ] = F_35 ( V_23 ,
F_51 ( 4 ) ) ;
}
if ( V_18 -> type == V_102 ) {
for ( V_3 = 5 ; V_3 <= 7 ; ++ V_3 ) {
V_18 -> V_44 [ V_3 ] = F_35 ( V_23 ,
F_111 ( V_3 ) ) ;
V_18 -> V_45 [ V_3 ] = F_35 ( V_23 ,
F_112 ( V_3 ) ) ;
}
}
for ( V_3 = 0 ; V_3 <= 2 ; ++ V_3 ) {
int V_1 ;
V_18 -> V_48 [ V_3 ] =
F_35 ( V_23 , F_59 ( V_3 ) ) ;
V_18 -> V_49 [ V_3 ] =
F_35 ( V_23 , F_62 ( V_3 ) ) ;
V_18 -> V_33 [ V_3 ] . V_34 =
F_35 ( V_23 , F_36 ( V_3 ) ) ;
V_1 = F_35 ( V_23 , F_40 ( V_3 ) ) ;
V_18 -> V_37 [ V_3 ] = V_1 & 0x07 ;
V_18 -> V_8 [ V_3 ] . V_2 = V_1 >> 4 ;
V_18 -> V_33 [ V_3 ] . V_50 =
F_35 ( V_23 , F_67 ( V_3 ) ) ;
V_18 -> V_8 [ V_3 ] . V_54 =
F_35 ( V_23 , F_76 ( V_3 ) ) ;
V_18 -> V_8 [ V_3 ] . V_60 =
F_35 ( V_23 , F_82 ( V_3 ) ) ;
if ( F_57 ( V_18 ) ) {
V_18 -> V_48 [ V_3 ] -= 64 ;
V_18 -> V_49 [ V_3 ] -= 64 ;
V_18 -> V_8 [ V_3 ] . V_54 -= 64 ;
V_18 -> V_8 [ V_3 ] . V_60 -= 64 ;
}
}
if ( V_18 -> type != V_98 ) {
V_3 = F_35 ( V_23 , V_53 ) ;
V_18 -> V_33 [ 0 ] . V_51 = ( V_3 & 0x20 ) != 0 ;
V_18 -> V_33 [ 1 ] . V_51 = ( V_3 & 0x40 ) != 0 ;
V_18 -> V_33 [ 2 ] . V_51 = ( V_3 & 0x80 ) != 0 ;
V_3 = F_35 ( V_23 , V_57 ) ;
V_18 -> V_8 [ 0 ] . V_55 = V_3 >> 4 ;
V_18 -> V_8 [ 1 ] . V_55 = V_3 & 0x0f ;
V_3 = F_35 ( V_23 , V_58 ) ;
V_18 -> V_8 [ 2 ] . V_55 = V_3 >> 4 ;
}
V_18 -> V_135 = V_121 ;
}
V_18 -> V_120 = 1 ;
F_19 ( & V_18 -> V_25 ) ;
return V_18 ;
}
