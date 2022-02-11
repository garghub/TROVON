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
unsigned long V_1 = F_15 ( V_14 , NULL , 10 ) ;
F_16 ( & V_18 -> V_24 ) ;
V_18 -> V_20 [ V_15 ] = F_1 ( V_1 ) ;
F_17 ( V_23 , F_18 ( V_15 ) , V_18 -> V_20 [ V_15 ] ) ;
F_19 ( & V_18 -> V_24 ) ;
return V_21 ;
}
static T_3 F_20 ( struct V_10 * V_11 , struct V_12 * V_13 ,
char * V_14 )
{
struct V_17 * V_18 = F_9 ( V_11 ) ;
int V_25 ;
if ( V_18 -> V_26 ) {
V_25 = F_21 ( V_18 -> V_25 & 0x3f , V_18 -> V_27 ) ;
} else {
V_25 = F_21 ( V_18 -> V_25 & 0x1f , V_18 -> V_27 ) ;
}
return sprintf ( V_14 , L_1 , V_25 ) ;
}
static T_3 F_22 ( struct V_10 * V_11 , struct V_12 * V_13 ,
char * V_14 )
{
struct V_17 * V_18 = F_23 ( V_11 ) ;
return sprintf ( V_14 , L_2 , ( long ) V_18 -> V_27 ) ;
}
static T_3 F_24 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_4 V_21 )
{
struct V_17 * V_18 = F_23 ( V_11 ) ;
V_18 -> V_27 = F_15 ( V_14 , NULL , 10 ) ;
return V_21 ;
}
static T_3 F_25 ( struct V_10 * V_11 , struct V_12
* V_13 , char * V_14 )
{
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_3 , V_18 -> V_28 ) ;
}
static T_3 F_26 ( struct V_10 * V_11 , struct V_12 * V_13 ,
char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_3 , ( V_18 -> V_28 >> V_15 ) & 1 ) ;
}
static T_3 F_27 ( struct V_10 * V_11 , struct V_12 * V_13 ,
char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , F_28 ( V_18 -> V_29 [ V_15 ] ) ) ;
}
static T_3 F_29 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_4 V_21 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
long V_1 = F_30 ( V_14 , NULL , 10 ) ;
F_16 ( & V_18 -> V_24 ) ;
V_18 -> V_29 [ V_15 ] = F_31 ( V_1 ) ;
F_17 ( V_23 , F_32 ( V_15 ) , V_18 -> V_29 [ V_15 ] ) ;
F_19 ( & V_18 -> V_24 ) ;
return V_21 ;
}
static T_3 F_33 ( struct V_10 * V_11 , struct V_12
* V_13 , char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
int V_30 , V_31 ;
V_30 = F_34 ( V_18 -> V_32 [ V_15 ] . V_33 ) ;
switch ( V_30 ) {
case - 1 :
V_31 = 0 ;
break;
case 0 :
case - 2 :
V_31 = 1 ;
break;
default:
V_31 = 2 ;
}
return sprintf ( V_14 , L_1 , V_31 ) ;
}
static T_3 F_35 ( struct V_10 * V_11 , struct V_12
* V_13 , const char * V_14 , T_4 V_21 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
long V_1 = F_30 ( V_14 , NULL , 10 ) ;
T_2 V_33 ;
switch ( V_1 ) {
case 0 :
V_33 = 3 ;
break;
case 1 :
V_33 = 7 ;
break;
case 2 :
V_33 = 6 ;
break;
default:
return - V_34 ;
}
F_16 ( & V_18 -> V_24 ) ;
V_18 -> V_32 [ V_15 ] . V_33 = F_36 ( V_23 ,
F_37 ( V_15 ) ) ;
V_18 -> V_32 [ V_15 ] . V_33 = ( V_18 -> V_32 [ V_15 ] . V_33 & ~ 0xe0 )
| ( V_33 << 5 ) ;
F_17 ( V_23 , F_37 ( V_15 ) ,
V_18 -> V_32 [ V_15 ] . V_33 ) ;
F_19 ( & V_18 -> V_24 ) ;
return V_21 ;
}
static T_3 F_38 ( struct V_10 * V_11 ,
struct V_12 * V_13 , char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
int V_6 ;
if ( F_39 ( V_18 ) )
V_6 = 22500 ;
else
V_6 = F_5 ( V_18 -> V_35 , V_18 -> V_36 [ V_15 ] ) ;
return sprintf ( V_14 , L_1 , V_6 ) ;
}
static T_3 F_40 ( struct V_10 * V_11 ,
struct V_12 * V_13 , const char * V_14 , T_4 V_21 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
long V_1 = F_30 ( V_14 , NULL , 10 ) ;
F_16 ( & V_18 -> V_24 ) ;
if ( V_18 -> type == V_37 && V_1 >= 11300 ) {
V_18 -> V_38 &= ~ V_39 ;
F_17 ( V_23 , V_40 , V_18 -> V_38 ) ;
} else {
V_18 -> V_36 [ V_15 ] = F_4 ( V_18 -> V_35 , V_1 ) ;
F_17 ( V_23 , F_41 ( V_15 ) ,
( V_18 -> V_8 [ V_15 ] . V_2 << 4 )
| V_18 -> V_36 [ V_15 ] ) ;
if ( V_18 -> type == V_37 ) {
V_18 -> V_38 |= V_39 ;
F_17 ( V_23 , V_40 , V_18 -> V_38 ) ;
}
}
F_19 ( & V_18 -> V_24 ) ;
return V_21 ;
}
static T_3 F_42 ( struct V_10 * V_11 , struct V_12 * V_13 ,
char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , F_43 ( V_15 , V_18 -> V_41 [ V_15 ] ,
V_18 -> V_42 [ V_15 ] ) ) ;
}
static T_3 F_44 ( struct V_10 * V_11 , struct V_12 * V_13 ,
char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , F_45 ( V_15 , V_18 -> V_43 [ V_15 ] ) ) ;
}
static T_3 F_46 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_4 V_21 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
long V_1 = F_30 ( V_14 , NULL , 10 ) ;
F_16 ( & V_18 -> V_24 ) ;
V_18 -> V_43 [ V_15 ] = F_47 ( V_15 , V_1 ) ;
F_17 ( V_23 , F_48 ( V_15 ) , V_18 -> V_43 [ V_15 ] ) ;
F_19 ( & V_18 -> V_24 ) ;
return V_21 ;
}
static T_3 F_49 ( struct V_10 * V_11 , struct V_12 * V_13 ,
char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , F_45 ( V_15 , V_18 -> V_44 [ V_15 ] ) ) ;
}
static T_3 F_50 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_4 V_21 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
long V_1 = F_30 ( V_14 , NULL , 10 ) ;
F_16 ( & V_18 -> V_24 ) ;
V_18 -> V_44 [ V_15 ] = F_47 ( V_15 , V_1 ) ;
F_17 ( V_23 , F_51 ( V_15 ) , V_18 -> V_44 [ V_15 ] ) ;
F_19 ( & V_18 -> V_24 ) ;
return V_21 ;
}
static T_3 F_52 ( struct V_10 * V_11 , struct V_12 * V_13 ,
char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , F_53 ( V_18 -> V_45 [ V_15 ] ,
V_18 -> V_46 [ V_15 ] ) ) ;
}
static T_3 F_54 ( struct V_10 * V_11 , struct V_12 * V_13 ,
char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , F_55 ( V_18 -> V_47 [ V_15 ] ) ) ;
}
static T_3 F_56 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_4 V_21 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
long V_1 = F_30 ( V_14 , NULL , 10 ) ;
if ( F_57 ( V_18 ) )
V_1 += 64 ;
F_16 ( & V_18 -> V_24 ) ;
V_18 -> V_47 [ V_15 ] = F_58 ( V_1 ) ;
F_17 ( V_23 , F_59 ( V_15 ) , V_18 -> V_47 [ V_15 ] ) ;
F_19 ( & V_18 -> V_24 ) ;
return V_21 ;
}
static T_3 F_60 ( struct V_10 * V_11 , struct V_12 * V_13 ,
char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , F_55 ( V_18 -> V_48 [ V_15 ] ) ) ;
}
static T_3 F_61 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_4 V_21 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
long V_1 = F_30 ( V_14 , NULL , 10 ) ;
if ( F_57 ( V_18 ) )
V_1 += 64 ;
F_16 ( & V_18 -> V_24 ) ;
V_18 -> V_48 [ V_15 ] = F_58 ( V_1 ) ;
F_17 ( V_23 , F_62 ( V_15 ) , V_18 -> V_48 [ V_15 ] ) ;
F_19 ( & V_18 -> V_24 ) ;
return V_21 ;
}
static T_3 F_63 ( struct V_10 * V_11 ,
struct V_12 * V_13 , char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , F_34 ( V_18 -> V_32 [ V_15 ] . V_33 ) ) ;
}
static T_3 F_64 ( struct V_10 * V_11 ,
struct V_12 * V_13 , const char * V_14 , T_4 V_21 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
long V_1 = F_30 ( V_14 , NULL , 10 ) ;
F_16 ( & V_18 -> V_24 ) ;
V_18 -> V_32 [ V_15 ] . V_33 = ( V_18 -> V_32 [ V_15 ] . V_33 & ( ~ 0xe0 ) )
| F_6 ( V_1 ) ;
F_17 ( V_23 , F_37 ( V_15 ) ,
V_18 -> V_32 [ V_15 ] . V_33 ) ;
F_19 ( & V_18 -> V_24 ) ;
return V_21 ;
}
static T_3 F_65 ( struct V_10 * V_11 ,
struct V_12 * V_13 , char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , F_28 ( V_18 -> V_32 [ V_15 ] . V_49 ) ) ;
}
static T_3 F_66 ( struct V_10 * V_11 ,
struct V_12 * V_13 , const char * V_14 , T_4 V_21 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
long V_1 = F_30 ( V_14 , NULL , 10 ) ;
F_16 ( & V_18 -> V_24 ) ;
V_18 -> V_32 [ V_15 ] . V_49 = F_31 ( V_1 ) ;
F_17 ( V_23 , F_67 ( V_15 ) ,
V_18 -> V_32 [ V_15 ] . V_49 ) ;
F_19 ( & V_18 -> V_24 ) ;
return V_21 ;
}
static T_3 F_68 ( struct V_10 * V_11 ,
struct V_12 * V_13 , char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , V_18 -> V_32 [ V_15 ] . V_50 ) ;
}
static T_3 F_69 ( struct V_10 * V_11 ,
struct V_12 * V_13 , const char * V_14 , T_4 V_21 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
long V_1 = F_30 ( V_14 , NULL , 10 ) ;
T_2 V_51 ;
F_16 ( & V_18 -> V_24 ) ;
V_18 -> V_32 [ V_15 ] . V_50 = V_1 ;
V_51 = F_36 ( V_23 , V_52 ) ;
V_51 &= ~ ( 0x20 << V_15 ) ;
if ( V_18 -> V_32 [ V_15 ] . V_50 )
V_51 |= 0x20 << V_15 ;
F_17 ( V_23 , V_52 , V_51 ) ;
F_19 ( & V_18 -> V_24 ) ;
return V_21 ;
}
static T_3 F_70 ( struct V_10 * V_11 ,
struct V_12 * V_13 , char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , F_55 ( V_18 -> V_8 [ V_15 ] . V_53 ) -
F_71 ( V_18 -> V_8 [ V_15 ] . V_54 ) ) ;
}
static T_3 F_72 ( struct V_10 * V_11 ,
struct V_12 * V_13 , const char * V_14 , T_4 V_21 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
int V_55 ;
long V_1 = F_30 ( V_14 , NULL , 10 ) ;
F_16 ( & V_18 -> V_24 ) ;
V_55 = F_55 ( V_18 -> V_8 [ V_15 ] . V_53 ) ;
V_18 -> V_8 [ V_15 ] . V_54 = F_73 ( V_55 - V_1 ) ;
if ( V_15 == 0 || V_15 == 1 ) {
F_17 ( V_23 , V_56 ,
( V_18 -> V_8 [ 0 ] . V_54 << 4 )
| V_18 -> V_8 [ 1 ] . V_54 ) ;
} else {
F_17 ( V_23 , V_57 ,
( V_18 -> V_8 [ 2 ] . V_54 << 4 ) ) ;
}
F_19 ( & V_18 -> V_24 ) ;
return V_21 ;
}
static T_3 F_74 ( struct V_10 * V_11 ,
struct V_12 * V_13 , char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , F_55 ( V_18 -> V_8 [ V_15 ] . V_53 ) ) ;
}
static T_3 F_75 ( struct V_10 * V_11 ,
struct V_12 * V_13 , const char * V_14 , T_4 V_21 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
long V_1 = F_30 ( V_14 , NULL , 10 ) ;
F_16 ( & V_18 -> V_24 ) ;
V_18 -> V_8 [ V_15 ] . V_53 = F_58 ( V_1 ) ;
F_17 ( V_23 , F_76 ( V_15 ) ,
V_18 -> V_8 [ V_15 ] . V_53 ) ;
V_18 -> V_8 [ V_15 ] . V_2 = F_3 (
F_55 ( V_18 -> V_8 [ V_15 ] . V_58 ) -
F_55 ( V_18 -> V_8 [ V_15 ] . V_53 ) ) ;
F_17 ( V_23 , F_41 ( V_15 ) ,
( ( V_18 -> V_8 [ V_15 ] . V_2 & 0x0f ) << 4 )
| ( V_18 -> V_36 [ V_15 ] & 0x07 ) ) ;
F_19 ( & V_18 -> V_24 ) ;
return V_21 ;
}
static T_3 F_77 ( struct V_10 * V_11 ,
struct V_12 * V_13 , char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , F_55 ( V_18 -> V_8 [ V_15 ] . V_53 ) +
F_78 ( V_18 -> V_8 [ V_15 ] . V_2 ) ) ;
}
static T_3 F_79 ( struct V_10 * V_11 ,
struct V_12 * V_13 , const char * V_14 , T_4 V_21 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
int V_55 ;
long V_1 = F_30 ( V_14 , NULL , 10 ) ;
F_16 ( & V_18 -> V_24 ) ;
V_55 = F_55 ( V_18 -> V_8 [ V_15 ] . V_53 ) ;
V_18 -> V_8 [ V_15 ] . V_58 = F_58 ( V_1 ) ;
V_18 -> V_8 [ V_15 ] . V_2 = F_3 (
V_1 - V_55 ) ;
F_17 ( V_23 , F_41 ( V_15 ) ,
( ( V_18 -> V_8 [ V_15 ] . V_2 & 0x0f ) << 4 )
| ( V_18 -> V_36 [ V_15 ] & 0x07 ) ) ;
F_19 ( & V_18 -> V_24 ) ;
return V_21 ;
}
static T_3 F_80 ( struct V_10 * V_11 ,
struct V_12 * V_13 , char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_17 * V_18 = F_9 ( V_11 ) ;
return sprintf ( V_14 , L_1 , F_55 ( V_18 -> V_8 [ V_15 ] . V_59 ) ) ;
}
static T_3 F_81 ( struct V_10 * V_11 ,
struct V_12 * V_13 , const char * V_14 , T_4 V_21 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
long V_1 = F_30 ( V_14 , NULL , 10 ) ;
F_16 ( & V_18 -> V_24 ) ;
V_18 -> V_8 [ V_15 ] . V_59 = F_58 ( V_1 ) ;
F_17 ( V_23 , F_82 ( V_15 ) ,
V_18 -> V_8 [ V_15 ] . V_59 ) ;
F_19 ( & V_18 -> V_24 ) ;
return V_21 ;
}
static void F_83 ( struct V_22 * V_23 )
{
int V_60 ;
V_60 = F_36 ( V_23 , V_61 ) ;
if ( ! ( V_60 & 0x01 ) ) {
F_84 ( & V_23 -> V_11 , L_4 ) ;
F_17 ( V_23 , V_61 , V_60 | 0x01 ) ;
}
if ( V_60 & 0x02 )
F_85 ( & V_23 -> V_11 , L_5 ) ;
if ( ! ( V_60 & 0x04 ) )
F_85 ( & V_23 -> V_11 , L_6 ) ;
}
static int F_86 ( struct V_22 * V_23 )
{
int V_3 ;
T_2 V_62 , V_19 ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
V_62 = F_87 ( V_23 , 0x20 + V_3 ) ;
V_19 = F_87 ( V_23 , 0x28 + V_3 ) ;
if ( V_62 != 0x00 || V_19 != 0xff )
return 0 ;
}
return 1 ;
}
static int F_88 ( struct V_22 * V_23 , struct V_63 * V_64 )
{
struct V_65 * V_66 = V_23 -> V_66 ;
int V_67 = V_23 -> V_68 ;
const char * V_69 ;
int V_70 , V_71 ;
if ( ! F_89 ( V_66 , V_72 ) ) {
return - V_73 ;
}
V_70 = F_36 ( V_23 , V_74 ) ;
V_71 = F_36 ( V_23 , V_75 ) ;
F_90 ( & V_66 -> V_11 , L_7
L_8 ,
V_67 , V_70 , V_71 ) ;
if ( ( V_71 & V_76 ) != V_77 &&
( V_71 & V_76 ) != V_78 ) {
F_90 ( & V_66 -> V_11 ,
L_9 ) ;
return - V_73 ;
}
V_69 = L_10 ;
if ( V_70 == V_79 ) {
switch ( V_71 ) {
case V_80 :
V_69 = L_11 ;
break;
case V_81 :
V_69 = L_12 ;
break;
case V_82 :
case V_83 :
if ( F_86 ( V_23 ) ) {
F_90 ( & V_66 -> V_11 ,
L_13 ) ;
return - V_73 ;
}
break;
}
} else if ( V_70 == V_84 ) {
switch ( V_71 ) {
case V_85 :
V_69 = L_14 ;
break;
case V_86 :
case V_87 :
V_69 = L_15 ;
break;
case V_88 :
case V_89 :
V_69 = L_16 ;
break;
}
} else if ( V_70 == V_90 ) {
switch ( V_71 ) {
case V_91 :
case V_92 :
V_69 = L_17 ;
break;
case V_93 :
V_69 = L_18 ;
break;
case V_94 :
case V_95 :
V_69 = L_19 ;
break;
case V_96 :
V_69 = L_20 ;
break;
}
} else {
F_90 ( & V_66 -> V_11 ,
L_21 ) ;
return - V_73 ;
}
F_91 ( V_64 -> type , V_69 , V_97 ) ;
return 0 ;
}
static void F_92 ( struct V_22 * V_23 , struct V_17 * V_18 )
{
F_93 ( & V_23 -> V_11 . V_98 , & V_99 ) ;
if ( V_18 -> type != V_100 ) {
F_93 ( & V_23 -> V_11 . V_98 , & V_101 ) ;
F_93 ( & V_23 -> V_11 . V_98 , & V_102 ) ;
}
if ( ! V_18 -> V_26 )
F_93 ( & V_23 -> V_11 . V_98 , & V_103 ) ;
if ( V_18 -> type == V_104 )
F_93 ( & V_23 -> V_11 . V_98 , & V_105 ) ;
}
static int F_94 ( struct V_22 * V_23 ,
const struct V_106 * V_107 )
{
struct V_17 * V_18 ;
int V_108 ;
V_18 = F_95 ( sizeof( struct V_17 ) , V_109 ) ;
if ( ! V_18 )
return - V_110 ;
F_96 ( V_23 , V_18 ) ;
V_18 -> type = V_107 -> V_111 ;
F_97 ( & V_18 -> V_24 ) ;
switch ( V_18 -> type ) {
case V_112 :
case V_113 :
case V_37 :
case V_104 :
case V_114 :
case V_115 :
case V_100 :
V_18 -> V_35 = V_116 ;
break;
default:
V_18 -> V_35 = V_117 ;
}
V_18 -> V_27 = F_98 () ;
F_83 ( V_23 ) ;
V_108 = F_99 ( & V_23 -> V_11 . V_98 , & V_99 ) ;
if ( V_108 )
goto V_118;
if ( V_18 -> type != V_100 ) {
V_108 = F_99 ( & V_23 -> V_11 . V_98 , & V_101 ) ;
if ( V_108 )
goto V_119;
V_108 = F_99 ( & V_23 -> V_11 . V_98 ,
& V_102 ) ;
if ( V_108 )
goto V_119;
}
if ( V_18 -> type == V_113 || V_18 -> type == V_37 ) {
T_2 V_25 = F_36 ( V_23 , V_120 ) ;
if ( V_25 & 0x80 )
V_18 -> V_26 = true ;
}
if ( ! V_18 -> V_26 )
if ( ( V_108 = F_99 ( & V_23 -> V_11 . V_98 ,
& V_103 ) ) )
goto V_119;
if ( V_18 -> type == V_104 )
if ( ( V_108 = F_99 ( & V_23 -> V_11 . V_98 ,
& V_105 ) ) )
goto V_119;
V_18 -> V_121 = F_100 ( & V_23 -> V_11 ) ;
if ( F_101 ( V_18 -> V_121 ) ) {
V_108 = F_102 ( V_18 -> V_121 ) ;
goto V_119;
}
return 0 ;
V_119:
F_92 ( V_23 , V_18 ) ;
V_118:
F_103 ( V_18 ) ;
return V_108 ;
}
static int F_104 ( struct V_22 * V_23 )
{
struct V_17 * V_18 = F_14 ( V_23 ) ;
F_105 ( V_18 -> V_121 ) ;
F_92 ( V_23 , V_18 ) ;
F_103 ( V_18 ) ;
return 0 ;
}
static int F_36 ( struct V_22 * V_23 , T_2 V_7 )
{
int V_122 ;
switch ( V_7 ) {
case F_106 ( 0 ) :
case F_106 ( 1 ) :
case F_106 ( 2 ) :
case F_106 ( 3 ) :
case F_18 ( 0 ) :
case F_18 ( 1 ) :
case F_18 ( 2 ) :
case F_18 ( 3 ) :
case V_123 :
V_122 = F_87 ( V_23 , V_7 ) & 0xff ;
V_122 |= F_87 ( V_23 , V_7 + 1 ) << 8 ;
break;
default:
V_122 = F_87 ( V_23 , V_7 ) ;
break;
}
return V_122 ;
}
static void F_17 ( struct V_22 * V_23 , T_2 V_7 , int V_60 )
{
switch ( V_7 ) {
case F_106 ( 0 ) :
case F_106 ( 1 ) :
case F_106 ( 2 ) :
case F_106 ( 3 ) :
case F_18 ( 0 ) :
case F_18 ( 1 ) :
case F_18 ( 2 ) :
case F_18 ( 3 ) :
F_107 ( V_23 , V_7 , V_60 & 0xff ) ;
F_107 ( V_23 , V_7 + 1 , V_60 >> 8 ) ;
break;
default:
F_107 ( V_23 , V_7 , V_60 ) ;
break;
}
}
static struct V_17 * F_9 ( struct V_10 * V_11 )
{
struct V_22 * V_23 = F_13 ( V_11 ) ;
struct V_17 * V_18 = F_14 ( V_23 ) ;
int V_3 ;
F_16 ( & V_18 -> V_24 ) ;
if ( ! V_18 -> V_124 ||
F_108 ( V_125 , V_18 -> V_126 + V_127 ) ) {
F_90 ( & V_23 -> V_11 , L_22 ) ;
if ( V_18 -> type == V_112 || V_18 -> type == V_113 ||
V_18 -> type == V_37 ) {
int V_128 = F_36 ( V_23 ,
V_129 ) ;
int V_130 = F_36 ( V_23 ,
V_131 ) ;
int V_1 = ( V_128 << 8 ) + V_130 ;
for ( V_3 = 0 ; V_3 <= 4 ; V_3 ++ )
V_18 -> V_42 [ V_3 ] =
( ( V_1 >> ( V_3 * 2 ) ) & 0x03 ) << 2 ;
for ( V_3 = 0 ; V_3 <= 2 ; V_3 ++ )
V_18 -> V_46 [ V_3 ] =
( V_1 >> ( ( V_3 + 4 ) * 2 ) ) & 0x0c ;
}
V_18 -> V_25 = F_36 ( V_23 , V_120 ) ;
for ( V_3 = 0 ; V_3 <= 3 ; ++ V_3 ) {
V_18 -> V_41 [ V_3 ] =
F_36 ( V_23 , F_109 ( V_3 ) ) ;
V_18 -> V_19 [ V_3 ] =
F_36 ( V_23 , F_106 ( V_3 ) ) ;
}
if ( ! V_18 -> V_26 )
V_18 -> V_41 [ 4 ] = F_36 ( V_23 , F_109 ( 4 ) ) ;
if ( V_18 -> type == V_37 )
V_18 -> V_38 = F_36 ( V_23 , V_40 ) ;
for ( V_3 = 0 ; V_3 <= 2 ; ++ V_3 ) {
V_18 -> V_45 [ V_3 ] =
F_36 ( V_23 , F_110 ( V_3 ) ) ;
V_18 -> V_29 [ V_3 ] =
F_36 ( V_23 , F_32 ( V_3 ) ) ;
if ( F_57 ( V_18 ) )
V_18 -> V_45 [ V_3 ] -= 64 ;
}
V_18 -> V_28 = F_36 ( V_23 , V_123 ) ;
if ( V_18 -> type == V_104 ) {
for ( V_3 = 5 ; V_3 <= 7 ; ++ V_3 ) {
V_18 -> V_41 [ V_3 ] = F_36 ( V_23 ,
F_111 ( V_3 ) ) ;
}
V_18 -> V_28 |= F_36 ( V_23 ,
V_132 ) << 16 ;
} else if ( V_18 -> type == V_114 || V_18 -> type == V_115 ||
V_18 -> type == V_100 ) {
int V_128 = F_36 ( V_23 ,
V_133 ) ;
int V_130 = F_36 ( V_23 ,
V_134 ) ;
int V_135 = F_36 ( V_23 ,
V_136 ) ;
int V_137 = F_36 ( V_23 ,
V_138 ) ;
V_18 -> V_42 [ 0 ] = V_135 & 0x0f ;
V_18 -> V_42 [ 1 ] = V_137 & 0x0f ;
V_18 -> V_42 [ 2 ] = V_137 >> 4 ;
V_18 -> V_42 [ 3 ] = V_135 >> 4 ;
V_18 -> V_42 [ 4 ] = V_130 >> 4 ;
V_18 -> V_46 [ 0 ] = V_128 & 0x0f ;
V_18 -> V_46 [ 1 ] = V_130 & 0x0f ;
V_18 -> V_46 [ 2 ] = V_128 >> 4 ;
}
V_18 -> V_126 = V_125 ;
}
if ( ! V_18 -> V_124 ||
F_108 ( V_125 , V_18 -> V_139 + V_140 ) ) {
F_90 ( & V_23 -> V_11 , L_23 ) ;
for ( V_3 = 0 ; V_3 <= 3 ; ++ V_3 ) {
V_18 -> V_43 [ V_3 ] =
F_36 ( V_23 , F_48 ( V_3 ) ) ;
V_18 -> V_44 [ V_3 ] =
F_36 ( V_23 , F_51 ( V_3 ) ) ;
V_18 -> V_20 [ V_3 ] =
F_36 ( V_23 , F_18 ( V_3 ) ) ;
}
if ( ! V_18 -> V_26 ) {
V_18 -> V_43 [ 4 ] = F_36 ( V_23 ,
F_48 ( 4 ) ) ;
V_18 -> V_44 [ 4 ] = F_36 ( V_23 ,
F_51 ( 4 ) ) ;
}
if ( V_18 -> type == V_104 ) {
for ( V_3 = 5 ; V_3 <= 7 ; ++ V_3 ) {
V_18 -> V_43 [ V_3 ] = F_36 ( V_23 ,
F_112 ( V_3 ) ) ;
V_18 -> V_44 [ V_3 ] = F_36 ( V_23 ,
F_113 ( V_3 ) ) ;
}
}
for ( V_3 = 0 ; V_3 <= 2 ; ++ V_3 ) {
int V_1 ;
V_18 -> V_47 [ V_3 ] =
F_36 ( V_23 , F_59 ( V_3 ) ) ;
V_18 -> V_48 [ V_3 ] =
F_36 ( V_23 , F_62 ( V_3 ) ) ;
V_18 -> V_32 [ V_3 ] . V_33 =
F_36 ( V_23 , F_37 ( V_3 ) ) ;
V_1 = F_36 ( V_23 , F_41 ( V_3 ) ) ;
V_18 -> V_36 [ V_3 ] = V_1 & 0x07 ;
V_18 -> V_8 [ V_3 ] . V_2 = V_1 >> 4 ;
V_18 -> V_32 [ V_3 ] . V_49 =
F_36 ( V_23 , F_67 ( V_3 ) ) ;
V_18 -> V_8 [ V_3 ] . V_53 =
F_36 ( V_23 , F_76 ( V_3 ) ) ;
V_18 -> V_8 [ V_3 ] . V_59 =
F_36 ( V_23 , F_82 ( V_3 ) ) ;
if ( F_57 ( V_18 ) ) {
V_18 -> V_47 [ V_3 ] -= 64 ;
V_18 -> V_48 [ V_3 ] -= 64 ;
V_18 -> V_8 [ V_3 ] . V_53 -= 64 ;
V_18 -> V_8 [ V_3 ] . V_59 -= 64 ;
}
}
if ( V_18 -> type != V_100 ) {
V_3 = F_36 ( V_23 , V_52 ) ;
V_18 -> V_32 [ 0 ] . V_50 = ( V_3 & 0x20 ) != 0 ;
V_18 -> V_32 [ 1 ] . V_50 = ( V_3 & 0x40 ) != 0 ;
V_18 -> V_32 [ 2 ] . V_50 = ( V_3 & 0x80 ) != 0 ;
V_3 = F_36 ( V_23 , V_56 ) ;
V_18 -> V_8 [ 0 ] . V_54 = V_3 >> 4 ;
V_18 -> V_8 [ 1 ] . V_54 = V_3 & 0x0f ;
V_3 = F_36 ( V_23 , V_57 ) ;
V_18 -> V_8 [ 2 ] . V_54 = V_3 >> 4 ;
}
V_18 -> V_139 = V_125 ;
}
V_18 -> V_124 = 1 ;
F_19 ( & V_18 -> V_24 ) ;
return V_18 ;
}
static int T_5 F_114 ( void )
{
return F_115 ( & V_141 ) ;
}
static void T_6 F_116 ( void )
{
F_117 ( & V_141 ) ;
}
