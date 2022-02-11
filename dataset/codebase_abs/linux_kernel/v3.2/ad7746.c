static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 , V_8 ;
T_1 V_9 , V_10 ;
switch ( V_4 -> type ) {
case V_11 :
V_10 = ( V_4 -> V_12 & 0xFF ) | V_13 ;
V_9 = V_6 -> V_9 & ~ V_14 ;
V_8 = V_15 [ ( V_6 -> V_16 >> 3 ) &
0x7 ] [ 1 ] ;
if ( V_6 -> V_17 != V_4 -> V_18 ) {
V_7 = F_3 ( V_6 -> V_19 ,
V_20 ,
V_6 -> V_21 [ V_4 -> V_18 ] [ 0 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_3 ( V_6 -> V_19 ,
V_22 ,
V_6 -> V_21 [ V_4 -> V_18 ] [ 1 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 -> V_17 = V_4 -> V_18 ;
}
break;
case V_23 :
case V_24 :
V_9 = ( V_4 -> V_12 & 0xFF ) | V_14 ;
V_10 = V_6 -> V_10 & ~ V_13 ;
V_8 = V_15 [ ( V_6 -> V_16 >> 6 ) &
0x3 ] [ 1 ] ;
break;
default:
return - V_25 ;
}
if ( V_6 -> V_10 != V_10 ) {
V_7 = F_3 ( V_6 -> V_19 ,
V_26 ,
V_10 ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 -> V_10 = V_10 ;
}
if ( V_6 -> V_9 != V_9 ) {
V_7 = F_3 ( V_6 -> V_19 ,
V_27 ,
V_9 ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 -> V_9 = V_9 ;
}
return V_8 ;
}
static inline T_2 F_4 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
const char * V_32 ,
T_3 V_33 ,
T_1 V_34 )
{
struct V_1 * V_2 = F_5 ( V_29 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
bool V_35 ;
int V_7 , V_36 = 10 ;
V_7 = F_6 ( V_32 , & V_35 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ! V_35 )
return 0 ;
F_7 ( & V_2 -> V_37 ) ;
V_34 |= V_6 -> V_16 ;
V_7 = F_3 ( V_6 -> V_19 , V_38 , V_34 ) ;
if ( V_7 < 0 ) {
F_8 ( & V_2 -> V_37 ) ;
return V_7 ;
}
do {
F_9 ( 20 ) ;
V_7 = F_10 ( V_6 -> V_19 , V_38 ) ;
if ( V_7 < 0 ) {
F_8 ( & V_2 -> V_37 ) ;
return V_7 ;
}
} while ( ( V_7 == V_34 ) && V_36 -- );
F_8 ( & V_2 -> V_37 ) ;
return V_33 ;
}
static T_2 F_11 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
const char * V_32 ,
T_3 V_33 )
{
struct V_1 * V_2 = F_5 ( V_29 ) ;
int V_7 = F_1 ( V_2 ,
& V_39 [ F_12 ( V_31 ) -> V_12 ] ) ;
if ( V_7 < 0 )
return V_7 ;
return F_4 ( V_29 , V_31 , V_32 , V_33 ,
V_40 ) ;
}
static T_2 F_13 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
const char * V_32 ,
T_3 V_33 )
{
struct V_1 * V_2 = F_5 ( V_29 ) ;
int V_7 = F_1 ( V_2 ,
& V_39 [ F_12 ( V_31 ) -> V_12 ] ) ;
if ( V_7 < 0 )
return V_7 ;
return F_4 ( V_29 , V_31 , V_32 , V_33 ,
V_41 ) ;
}
static T_2 F_14 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
char * V_32 )
{
struct V_1 * V_2 = F_5 ( V_29 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
return sprintf ( V_32 , L_1 , V_15 [
( V_6 -> V_16 >> 3 ) & 0x7 ] [ 0 ] ) ;
}
static T_2 F_15 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
const char * V_32 ,
T_3 V_33 )
{
struct V_1 * V_2 = F_5 ( V_29 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_42 ;
int V_7 , V_43 ;
V_7 = F_16 ( V_32 , 10 , & V_42 ) ;
if ( V_7 < 0 )
return V_7 ;
for ( V_43 = 0 ; V_43 < F_17 ( V_15 ) ; V_43 ++ )
if ( V_42 >= V_15 [ V_43 ] [ 0 ] )
break;
if ( V_43 >= F_17 ( V_15 ) )
V_43 = F_17 ( V_15 ) - 1 ;
F_7 ( & V_2 -> V_37 ) ;
V_6 -> V_16 &= ~ F_18 ( 0x7 ) ;
V_6 -> V_16 |= F_18 ( V_43 ) ;
F_8 ( & V_2 -> V_37 ) ;
return V_33 ;
}
static T_2 F_19 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
char * V_32 )
{
struct V_1 * V_2 = F_5 ( V_29 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
return sprintf ( V_32 , L_1 , V_44 [
( V_6 -> V_16 >> 6 ) & 0x3 ] [ 0 ] ) ;
}
static T_2 F_20 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
const char * V_32 ,
T_3 V_33 )
{
struct V_1 * V_2 = F_5 ( V_29 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_42 ;
int V_7 , V_43 ;
V_7 = F_16 ( V_32 , 10 , & V_42 ) ;
if ( V_7 < 0 )
return V_7 ;
for ( V_43 = 0 ; V_43 < F_17 ( V_44 ) ; V_43 ++ )
if ( V_42 >= V_44 [ V_43 ] [ 0 ] )
break;
if ( V_43 >= F_17 ( V_44 ) )
V_43 = F_17 ( V_44 ) - 1 ;
F_7 ( & V_2 -> V_37 ) ;
V_6 -> V_16 &= ~ F_21 ( 0x3 ) ;
V_6 -> V_16 |= F_21 ( V_43 ) ;
F_8 ( & V_2 -> V_37 ) ;
return V_33 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int V_45 ,
int V_46 ,
long V_47 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 , V_48 ;
F_7 ( & V_2 -> V_37 ) ;
switch ( V_47 ) {
case ( 1 << V_49 ) :
if ( V_45 != 1 ) {
V_7 = - V_25 ;
goto V_50;
}
V_45 = ( V_46 * 1024 ) / 15625 ;
switch ( V_4 -> type ) {
case V_11 :
V_48 = V_51 ;
break;
case V_23 :
V_48 = V_52 ;
break;
default:
V_7 = - V_25 ;
goto V_50;
}
V_7 = F_23 ( V_6 -> V_19 , V_48 , F_24 ( V_45 ) ) ;
if ( V_7 < 0 )
goto V_50;
V_7 = 0 ;
break;
case ( 1 << V_53 ) :
if ( ( V_45 < 0 ) | ( V_45 > 0xFFFF ) ) {
V_7 = - V_25 ;
goto V_50;
}
V_7 = F_23 ( V_6 -> V_19 ,
V_54 , F_24 ( V_45 ) ) ;
if ( V_7 < 0 )
goto V_50;
V_7 = 0 ;
break;
case ( 1 << V_55 ) :
if ( ( V_45 < 0 ) | ( V_45 > 43008000 ) ) {
V_7 = - V_25 ;
goto V_50;
}
V_45 /= 338646 ;
V_6 -> V_21 [ V_4 -> V_18 ] [ V_4 -> V_56 ] = ( V_45 > 0 ?
F_25 ( V_45 ) | V_57 : 0 ) ;
V_7 = F_3 ( V_6 -> V_19 ,
V_20 ,
V_6 -> V_21 [ V_4 -> V_18 ] [ 0 ] ) ;
if ( V_7 < 0 )
goto V_50;
V_7 = F_3 ( V_6 -> V_19 ,
V_22 ,
V_6 -> V_21 [ V_4 -> V_18 ] [ 1 ] ) ;
if ( V_7 < 0 )
goto V_50;
V_6 -> V_17 = V_4 -> V_18 ;
V_7 = 0 ;
break;
default:
V_7 = - V_25 ;
}
V_50:
F_8 ( & V_2 -> V_37 ) ;
return V_7 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_45 , int * V_46 ,
long V_47 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 , V_8 ;
T_1 V_34 , V_48 ;
union {
T_4 V_58 ;
T_1 V_59 [ 4 ] ;
} V_42 ;
F_7 ( & V_2 -> V_37 ) ;
switch ( V_47 ) {
case 0 :
V_7 = F_1 ( V_2 , V_4 ) ;
if ( V_7 < 0 )
goto V_50;
V_8 = V_7 ;
V_34 = V_6 -> V_16 | V_60 ;
V_7 = F_3 ( V_6 -> V_19 , V_38 ,
V_34 ) ;
if ( V_7 < 0 )
goto V_50;
F_9 ( V_8 ) ;
V_7 = F_27 ( V_6 -> V_19 ,
V_4 -> V_12 >> 8 , 3 , & V_42 . V_59 [ 1 ] ) ;
if ( V_7 < 0 )
goto V_50;
* V_45 = ( F_28 ( V_42 . V_58 ) & 0xFFFFFF ) - 0x800000 ;
switch ( V_4 -> type ) {
case V_24 :
* V_45 = ( * V_45 * 125 ) / 256 ;
break;
case V_23 :
if ( V_4 -> V_18 == 1 )
* V_45 = * V_45 * 6 ;
break;
default:
break;
}
V_7 = V_61 ;
break;
case ( 1 << V_49 ) :
switch ( V_4 -> type ) {
case V_11 :
V_48 = V_51 ;
break;
case V_23 :
V_48 = V_52 ;
break;
default:
V_7 = - V_25 ;
goto V_50;
}
V_7 = F_29 ( V_6 -> V_19 , V_48 ) ;
if ( V_7 < 0 )
goto V_50;
* V_45 = 1 ;
* V_46 = ( 15625 * F_24 ( V_7 ) ) / 1024 ;
V_7 = V_62 ;
break;
case ( 1 << V_53 ) :
V_7 = F_29 ( V_6 -> V_19 ,
V_54 ) ;
if ( V_7 < 0 )
goto V_50;
* V_45 = F_24 ( V_7 ) ;
V_7 = V_61 ;
break;
case ( 1 << V_55 ) :
* V_45 = F_25 ( V_6 -> V_21 [ V_4 -> V_18 ]
[ V_4 -> V_56 ] ) * 338646 ;
V_7 = V_61 ;
break;
case ( 1 << V_63 ) :
switch ( V_4 -> type ) {
case V_11 :
* V_46 = 488 ;
* V_45 = 0 ;
break;
case V_23 :
* V_46 = 139475 ;
* V_45 = 0 ;
break;
default:
V_7 = - V_25 ;
goto V_50;
}
V_7 = V_64 ;
break;
default:
V_7 = - V_25 ;
} ;
V_50:
F_8 ( & V_2 -> V_37 ) ;
return V_7 ;
}
static int T_5 F_30 ( struct V_65 * V_19 ,
const struct V_66 * V_67 )
{
struct V_68 * V_69 = V_19 -> V_29 . V_70 ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
int V_7 = 0 ;
unsigned char V_34 = 0 ;
V_2 = F_31 ( sizeof( * V_6 ) ) ;
if ( V_2 == NULL ) {
V_7 = - V_71 ;
goto V_72;
}
V_6 = F_2 ( V_2 ) ;
F_32 ( V_19 , V_2 ) ;
V_6 -> V_19 = V_19 ;
V_6 -> V_17 = - 1 ;
V_2 -> V_73 = V_67 -> V_73 ;
V_2 -> V_29 . V_74 = & V_19 -> V_29 ;
V_2 -> V_75 = & V_76 ;
V_2 -> V_77 = V_39 ;
if ( V_67 -> V_78 == 7746 )
V_2 -> V_79 = F_17 ( V_39 ) ;
else
V_2 -> V_79 = F_17 ( V_39 ) - 2 ;
V_2 -> V_79 = F_17 ( V_39 ) ;
V_2 -> V_80 = V_81 ;
if ( V_69 ) {
if ( V_69 -> V_82 ) {
if ( V_69 -> V_83 )
V_34 |= V_84 ;
else
V_34 |= V_85 ;
}
if ( V_69 -> V_86 ) {
if ( V_69 -> V_87 )
V_34 |= V_88 ;
else
V_34 |= V_89 ;
}
V_34 |= F_33 ( V_69 -> V_90 ) ;
} else {
F_34 ( & V_19 -> V_29 , L_2 ) ;
V_34 = V_85 | V_89 |
F_33 ( 3 ) ;
}
V_7 = F_3 ( V_6 -> V_19 ,
V_91 , V_34 ) ;
if ( V_7 < 0 )
goto V_92;
V_7 = F_35 ( V_2 ) ;
if ( V_7 )
goto V_92;
F_36 ( & V_19 -> V_29 , L_3 , V_67 -> V_73 ) ;
return 0 ;
V_92:
F_37 ( V_2 ) ;
V_72:
return V_7 ;
}
static int T_6 F_38 ( struct V_65 * V_19 )
{
struct V_1 * V_2 = F_39 ( V_19 ) ;
F_40 ( V_2 ) ;
F_37 ( V_2 ) ;
return 0 ;
}
static T_7 int F_41 ( void )
{
return F_42 ( & V_93 ) ;
}
static T_8 void F_43 ( void )
{
F_44 ( & V_93 ) ;
}
