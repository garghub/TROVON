static void F_1 ( T_1 * V_1 , struct V_2 * V_3 ,
int V_4 )
{
V_3 -> V_5 = V_1 [ V_6 ] & 0x7f ;
V_3 -> V_7 = V_1 [ V_8 ] & 0x7f ;
if ( V_4 ) {
V_3 -> V_9 = V_1 [ V_10 ] & 0x1f ;
} else {
V_3 -> V_9 = V_1 [ V_10 ] & 0x0f ;
if ( V_1 [ V_10 ] & V_11 )
V_3 -> V_9 += 12 ;
}
V_3 -> V_12 = F_2 ( V_1 [ V_13 ] & 0x7f ) ;
V_3 -> V_14 = V_1 [ V_15 ] & 0x1f ;
V_3 -> V_16 = ( V_1 [ V_17 ] & 0x0f ) - 1 ;
V_3 -> V_18 = ( V_1 [ V_19 ] & 0x7f ) + 100 ;
V_3 -> V_20 = 0 ;
V_3 -> V_21 = 0 ;
}
static int F_3 ( struct V_2 * V_3 , T_1 * V_1 )
{
V_1 [ V_6 ] = V_3 -> V_5 ;
V_1 [ V_8 ] = V_3 -> V_7 ;
if ( V_3 -> V_9 >= 12 )
V_1 [ V_10 ] = V_3 -> V_9 | V_11 ;
else
V_1 [ V_10 ] = V_3 -> V_9 & ~ V_11 ;
V_1 [ V_13 ] = 1 << V_3 -> V_12 ;
V_1 [ V_15 ] = V_3 -> V_14 ;
V_1 [ V_17 ] = V_3 -> V_16 + 1 ;
V_1 [ V_19 ] = V_3 -> V_18 > 100 ? ( V_3 -> V_18 - 100 ) : 0 ;
if ( V_3 -> V_18 < 100 ) {
F_4 ( L_1 ,
1900 + V_3 -> V_18 ) ;
return - V_22 ;
} else {
return 0 ;
}
}
static inline int F_5 ( struct V_23 * V_24 )
{
int V_25 , V_26 = V_27 ;
unsigned int V_1 ;
do {
V_25 = F_6 ( V_24 -> V_28 , V_29 , & V_1 ) ;
} while ( -- V_26 && ( V_1 & V_30 ) && ! V_25 );
if ( ! V_26 )
F_7 ( V_24 -> V_31 , L_2 ) ;
return V_25 ;
}
static inline int F_8 ( struct V_23 * V_24 )
{
int V_25 ;
unsigned int V_1 ;
V_25 = F_6 ( V_24 -> V_28 , V_29 , & V_1 ) ;
if ( V_25 < 0 ) {
F_7 ( V_24 -> V_31 , L_3 , V_25 ) ;
return V_25 ;
}
V_1 |= V_32 ;
V_1 |= V_30 ;
V_25 = F_9 ( V_24 -> V_28 , V_29 , V_1 ) ;
if ( V_25 < 0 ) {
F_7 ( V_24 -> V_31 , L_4 , V_25 ) ;
return V_25 ;
}
V_25 = F_5 ( V_24 ) ;
return V_25 ;
}
static inline int F_10 ( struct V_23 * V_24 )
{
int V_25 ;
unsigned int V_1 ;
V_25 = F_6 ( V_24 -> V_28 , V_29 , & V_1 ) ;
if ( V_25 < 0 ) {
F_7 ( V_24 -> V_31 , L_5 ,
V_33 , V_25 ) ;
return V_25 ;
}
V_1 &= ~ V_32 ;
V_1 |= V_30 ;
V_25 = F_9 ( V_24 -> V_28 , V_29 , V_1 ) ;
if ( V_25 < 0 ) {
F_7 ( V_24 -> V_31 , L_6 ,
V_33 , V_25 ) ;
return V_25 ;
}
V_25 = F_5 ( V_24 ) ;
return V_25 ;
}
static void F_11 ( T_1 * V_1 , struct V_2 * V_3 )
{
V_3 -> V_5 = F_12 ( V_1 [ V_6 ] ) ;
V_3 -> V_7 = F_12 ( V_1 [ V_8 ] ) ;
if ( V_1 [ V_10 ] & V_34 ) {
V_3 -> V_9 = F_12 ( V_1 [ V_10 ] & 0x1f ) ;
if ( V_1 [ V_10 ] & V_35 )
V_3 -> V_9 += 12 ;
} else {
V_3 -> V_9 = F_12 ( V_1 [ V_10 ] & 0x3f ) ;
}
V_3 -> V_12 = V_1 [ V_13 ] & 0x07 ;
V_3 -> V_14 = F_12 ( V_1 [ V_15 ] ) ;
V_3 -> V_16 = F_12 ( V_1 [ V_17 ] ) ;
V_3 -> V_18 = F_12 ( V_1 [ V_19 ] ) + F_12 ( V_1 [ V_36 ] ) * 100 ;
V_3 -> V_18 -= 1900 ;
}
static void F_13 ( struct V_2 * V_3 , T_1 * V_1 )
{
V_1 [ V_6 ] = F_14 ( V_3 -> V_5 ) ;
V_1 [ V_8 ] = F_14 ( V_3 -> V_7 ) ;
V_1 [ V_10 ] = F_14 ( V_3 -> V_9 ) ;
V_1 [ V_13 ] = V_3 -> V_12 ;
V_1 [ V_15 ] = F_14 ( V_3 -> V_14 ) ;
V_1 [ V_17 ] = F_14 ( V_3 -> V_16 ) ;
V_1 [ V_19 ] = F_14 ( V_3 -> V_18 % 100 ) ;
V_1 [ V_36 ] = F_14 ( ( V_3 -> V_18 + 1900 ) / 100 ) ;
}
static int F_15 ( struct V_37 * V_31 , struct V_2 * V_3 )
{
struct V_23 * V_24 = F_16 ( V_31 ) ;
T_1 V_1 [ 8 ] ;
int V_25 ;
V_25 = F_17 ( V_24 -> V_28 , V_38 , V_1 , 8 ) ;
if ( V_25 < 0 )
return V_25 ;
switch ( V_24 -> V_39 ) {
case V_40 :
F_11 ( V_1 , V_3 ) ;
break;
case V_41 :
F_1 ( V_1 , V_3 , V_24 -> V_4 ) ;
break;
default:
return - V_22 ;
}
F_18 ( V_31 , L_7 , V_33 ,
1900 + V_3 -> V_18 , 1 + V_3 -> V_16 , V_3 -> V_14 ,
V_3 -> V_9 , V_3 -> V_7 , V_3 -> V_5 , V_3 -> V_12 ) ;
return F_19 ( V_3 ) ;
}
static int F_20 ( struct V_37 * V_31 , struct V_2 * V_3 )
{
struct V_23 * V_24 = F_16 ( V_31 ) ;
T_1 V_1 [ 8 ] ;
int V_25 = 0 ;
switch ( V_24 -> V_39 ) {
case V_40 :
F_13 ( V_3 , V_1 ) ;
break;
case V_41 :
V_25 = F_3 ( V_3 , V_1 ) ;
break;
default:
return - V_22 ;
}
if ( V_25 < 0 )
return V_25 ;
F_18 ( V_31 , L_7 , V_33 ,
1900 + V_3 -> V_18 , 1 + V_3 -> V_16 , V_3 -> V_14 ,
V_3 -> V_9 , V_3 -> V_7 , V_3 -> V_5 , V_3 -> V_12 ) ;
V_25 = F_21 ( V_24 -> V_28 , V_38 , V_1 , 8 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_8 ( V_24 ) ;
return V_25 ;
}
static int F_22 ( struct V_37 * V_31 , struct V_42 * V_43 )
{
struct V_23 * V_24 = F_16 ( V_31 ) ;
T_1 V_1 [ 8 ] ;
unsigned int V_44 ;
int V_25 , V_45 ;
V_25 = F_17 ( V_24 -> V_28 , V_46 , V_1 , 8 ) ;
if ( V_25 < 0 )
return V_25 ;
switch ( V_24 -> V_39 ) {
case V_40 :
F_11 ( V_1 , & V_43 -> time ) ;
V_25 = F_6 ( V_24 -> V_28 , V_47 , & V_44 ) ;
if ( V_25 < 0 )
return V_25 ;
V_43 -> V_48 = ! ! V_44 ;
V_25 = F_6 ( V_24 -> V_28 , V_49 , & V_44 ) ;
if ( V_25 < 0 )
return V_25 ;
break;
case V_41 :
F_1 ( V_1 , & V_43 -> time , V_24 -> V_4 ) ;
F_18 ( V_31 , L_7 , V_33 ,
1900 + V_43 -> time . V_18 , 1 + V_43 -> time . V_16 ,
V_43 -> time . V_14 , V_43 -> time . V_9 ,
V_43 -> time . V_7 , V_43 -> time . V_5 ,
V_43 -> time . V_12 ) ;
V_43 -> V_48 = 0 ;
for ( V_45 = 0 ; V_45 < 7 ; V_45 ++ ) {
if ( V_1 [ V_45 ] & V_50 ) {
V_43 -> V_48 = 1 ;
break;
}
}
V_43 -> V_51 = 0 ;
V_25 = F_6 ( V_24 -> V_28 , V_49 , & V_44 ) ;
if ( V_25 < 0 )
return V_25 ;
break;
default:
return - V_22 ;
}
if ( V_44 & V_52 )
V_43 -> V_51 = 1 ;
else
V_43 -> V_51 = 0 ;
return 0 ;
}
static int F_23 ( struct V_23 * V_24 )
{
T_1 V_1 [ 8 ] ;
int V_25 , V_45 ;
struct V_2 V_3 ;
V_25 = F_17 ( V_24 -> V_28 , V_46 , V_1 , 8 ) ;
if ( V_25 < 0 )
return V_25 ;
F_1 ( V_1 , & V_3 , V_24 -> V_4 ) ;
F_18 ( V_24 -> V_31 , L_7 , V_33 ,
1900 + V_3 . V_18 , 1 + V_3 . V_16 , V_3 . V_14 ,
V_3 . V_9 , V_3 . V_7 , V_3 . V_5 , V_3 . V_12 ) ;
switch ( V_24 -> V_39 ) {
case V_40 :
V_25 = F_9 ( V_24 -> V_28 , V_47 , 0 ) ;
break;
case V_41 :
for ( V_45 = 0 ; V_45 < 7 ; V_45 ++ )
V_1 [ V_45 ] &= ~ V_50 ;
V_25 = F_21 ( V_24 -> V_28 , V_46 , V_1 , 8 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_10 ( V_24 ) ;
break;
default:
return - V_22 ;
}
return V_25 ;
}
static int F_24 ( struct V_23 * V_24 )
{
int V_25 ;
T_1 V_1 [ 8 ] ;
T_1 V_53 ;
struct V_2 V_3 ;
V_25 = F_17 ( V_24 -> V_28 , V_46 , V_1 , 8 ) ;
if ( V_25 < 0 )
return V_25 ;
F_1 ( V_1 , & V_3 , V_24 -> V_4 ) ;
F_18 ( V_24 -> V_31 , L_7 , V_33 ,
1900 + V_3 . V_18 , 1 + V_3 . V_16 , V_3 . V_14 ,
V_3 . V_9 , V_3 . V_7 , V_3 . V_5 , V_3 . V_12 ) ;
switch ( V_24 -> V_39 ) {
case V_40 :
V_53 = 0x77 ;
V_25 = F_9 ( V_24 -> V_28 , V_47 , V_53 ) ;
break;
case V_41 :
V_1 [ V_6 ] |= V_50 ;
V_1 [ V_8 ] |= V_50 ;
V_1 [ V_10 ] |= V_50 ;
V_1 [ V_13 ] &= ~ V_50 ;
if ( V_1 [ V_15 ] & 0x1f )
V_1 [ V_15 ] |= V_50 ;
if ( V_1 [ V_17 ] & 0xf )
V_1 [ V_17 ] |= V_50 ;
if ( V_1 [ V_19 ] & 0x7f )
V_1 [ V_19 ] |= V_50 ;
V_25 = F_21 ( V_24 -> V_28 , V_46 , V_1 , 8 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_10 ( V_24 ) ;
break;
default:
return - V_22 ;
}
return V_25 ;
}
static int F_25 ( struct V_37 * V_31 , struct V_42 * V_43 )
{
struct V_23 * V_24 = F_16 ( V_31 ) ;
T_1 V_1 [ 8 ] ;
int V_25 ;
switch ( V_24 -> V_39 ) {
case V_40 :
F_13 ( & V_43 -> time , V_1 ) ;
break;
case V_41 :
F_3 ( & V_43 -> time , V_1 ) ;
break;
default:
return - V_22 ;
}
F_18 ( V_31 , L_7 , V_33 ,
1900 + V_43 -> time . V_18 , 1 + V_43 -> time . V_16 ,
V_43 -> time . V_14 , V_43 -> time . V_9 , V_43 -> time . V_7 ,
V_43 -> time . V_5 , V_43 -> time . V_12 ) ;
V_25 = F_23 ( V_24 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_21 ( V_24 -> V_28 , V_46 , V_1 , 8 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_10 ( V_24 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_43 -> V_48 )
V_25 = F_24 ( V_24 ) ;
return V_25 ;
}
static int F_26 ( struct V_37 * V_31 ,
unsigned int V_48 )
{
struct V_23 * V_24 = F_16 ( V_31 ) ;
if ( V_48 )
return F_24 ( V_24 ) ;
else
return F_23 ( V_24 ) ;
}
static T_2 F_27 ( int V_54 , void * V_1 )
{
struct V_23 * V_24 = V_1 ;
F_28 ( V_24 -> V_55 , 1 , V_56 | V_57 ) ;
return V_58 ;
}
static void F_29 ( struct V_23 * V_24 , bool V_59 )
{
int V_25 ;
V_25 = F_30 ( V_24 -> V_28 , V_60 ,
V_61 ,
V_59 ? V_61 : 0 ) ;
if ( V_25 < 0 )
F_7 ( V_24 -> V_31 , L_8 ,
V_33 , V_25 ) ;
}
static void F_31 ( struct V_23 * V_24 , bool V_59 )
{
int V_25 ;
V_25 = F_30 ( V_24 -> V_28 , V_60 ,
V_62 ,
V_59 ? V_62 : 0 ) ;
if ( V_25 < 0 )
F_7 ( V_24 -> V_31 , L_9 ,
V_33 , V_25 ) ;
}
static int F_32 ( struct V_23 * V_24 )
{
T_1 V_1 [ 2 ] ;
unsigned int V_63 ;
int V_25 ;
struct V_2 V_3 ;
V_25 = F_6 ( V_24 -> V_28 , V_29 , & V_63 ) ;
if ( V_25 < 0 ) {
F_7 ( V_24 -> V_31 , L_10 ,
V_33 , V_25 ) ;
return V_25 ;
}
V_1 [ 0 ] = ( 1 << V_64 ) | ( 1 << V_65 ) ;
V_1 [ 1 ] = ( 0 << V_64 ) | ( 1 << V_65 ) ;
V_24 -> V_4 = 1 ;
V_25 = F_21 ( V_24 -> V_28 , V_47 , V_1 , 2 ) ;
if ( V_25 < 0 ) {
F_7 ( V_24 -> V_31 , L_11 ,
V_33 , V_25 ) ;
return V_25 ;
}
if ( ( V_63 & V_66 ) == 0 ) {
F_18 ( V_24 -> V_31 , L_12 ) ;
V_3 . V_5 = 0 ;
V_3 . V_7 = 0 ;
V_3 . V_9 = 0 ;
V_3 . V_12 = 0 ;
V_3 . V_14 = 1 ;
V_3 . V_16 = 0 ;
V_3 . V_18 = 112 ;
V_3 . V_20 = 0 ;
V_3 . V_21 = 0 ;
V_25 = F_20 ( V_24 -> V_31 , & V_3 ) ;
}
V_25 = F_30 ( V_24 -> V_28 , V_29 ,
V_66 , V_63 | V_66 ) ;
if ( V_25 < 0 )
F_7 ( V_24 -> V_31 , L_13 ,
V_33 , V_25 ) ;
return V_25 ;
}
static int F_33 ( struct V_67 * V_68 )
{
struct V_69 * V_70 = F_16 ( V_68 -> V_31 . V_71 ) ;
struct V_72 * V_73 = V_70 -> V_73 ;
struct V_23 * V_24 ;
int V_25 ;
if ( ! V_73 ) {
F_7 ( V_68 -> V_31 . V_71 , L_14 ) ;
return - V_74 ;
}
V_24 = F_34 ( & V_68 -> V_31 , sizeof( * V_24 ) , V_75 ) ;
if ( ! V_24 )
return - V_76 ;
V_24 -> V_31 = & V_68 -> V_31 ;
V_24 -> V_70 = V_70 ;
V_24 -> V_28 = V_70 -> V_77 ;
V_24 -> V_39 = V_70 -> V_39 ;
V_24 -> V_78 = V_70 -> V_78 ;
switch ( V_73 -> V_39 ) {
case V_40 :
V_24 -> V_54 = F_35 ( V_70 -> V_79 ,
V_80 ) ;
break;
case V_41 :
V_24 -> V_54 = F_35 ( V_70 -> V_79 ,
V_81 ) ;
break;
default:
V_25 = - V_22 ;
F_7 ( & V_68 -> V_31 , L_15 , V_25 ) ;
return V_25 ;
}
F_36 ( V_68 , V_24 ) ;
V_25 = F_32 ( V_24 ) ;
if ( V_24 -> V_78 ) {
F_29 ( V_24 , true ) ;
F_31 ( V_24 , true ) ;
}
F_37 ( & V_68 -> V_31 , 1 ) ;
V_24 -> V_55 = F_38 ( & V_68 -> V_31 , L_16 ,
& V_82 , V_83 ) ;
if ( F_39 ( V_24 -> V_55 ) )
return F_40 ( V_24 -> V_55 ) ;
V_25 = F_41 ( & V_68 -> V_31 , V_24 -> V_54 , NULL ,
F_27 , 0 , L_17 ,
V_24 ) ;
if ( V_25 < 0 )
F_7 ( & V_68 -> V_31 , L_18 ,
V_24 -> V_54 , V_25 ) ;
return V_25 ;
}
static void F_42 ( struct V_67 * V_68 )
{
struct V_23 * V_24 = F_43 ( V_68 ) ;
int V_45 ;
unsigned int V_44 = 0 ;
if ( V_24 -> V_78 ) {
for ( V_45 = 0 ; V_45 < 3 ; V_45 ++ ) {
F_29 ( V_24 , false ) ;
F_6 ( V_24 -> V_28 , V_60 , & V_44 ) ;
F_44 ( L_19 , V_33 , V_44 ) ;
if ( V_44 & V_61 )
F_45 ( L_20 ,
V_33 ) ;
else {
F_46 ( L_21 ,
V_33 ) ;
break;
}
}
}
F_31 ( V_24 , false ) ;
}
static int F_47 ( struct V_37 * V_31 )
{
struct V_23 * V_24 = F_16 ( V_31 ) ;
int V_25 = 0 ;
if ( F_48 ( V_31 ) )
V_25 = F_49 ( V_24 -> V_54 ) ;
return V_25 ;
}
static int F_50 ( struct V_37 * V_31 )
{
struct V_23 * V_24 = F_16 ( V_31 ) ;
int V_25 = 0 ;
if ( F_48 ( V_31 ) )
V_25 = F_51 ( V_24 -> V_54 ) ;
return V_25 ;
}
