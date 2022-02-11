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
V_25 = F_6 ( V_24 -> V_28 , V_24 -> V_29 -> V_30 ,
& V_1 ) ;
} while ( -- V_26 && ( V_1 & V_24 -> V_29 -> V_31 ) && ! V_25 );
if ( ! V_26 )
F_7 ( V_24 -> V_32 , L_2 ) ;
return V_25 ;
}
static inline int F_8 ( struct V_23 * V_24 ,
struct V_33 * V_34 )
{
int V_25 ;
unsigned int V_35 ;
switch ( V_24 -> V_36 ) {
case V_37 :
case V_38 :
V_25 = F_6 ( V_24 -> V_28 , V_39 , & V_35 ) ;
V_35 &= V_40 ;
break;
case V_41 :
V_25 = F_6 ( V_24 -> V_42 -> V_43 , V_44 ,
& V_35 ) ;
V_35 &= V_45 ;
break;
default:
return - V_22 ;
}
if ( V_25 < 0 )
return V_25 ;
if ( V_35 )
V_34 -> V_46 = 1 ;
else
V_34 -> V_46 = 0 ;
return 0 ;
}
static inline int F_9 ( struct V_23 * V_24 )
{
int V_25 ;
unsigned int V_1 ;
V_25 = F_6 ( V_24 -> V_28 , V_24 -> V_29 -> V_30 , & V_1 ) ;
if ( V_25 < 0 ) {
F_7 ( V_24 -> V_32 , L_3 , V_25 ) ;
return V_25 ;
}
V_1 |= V_24 -> V_29 -> V_31 ;
if ( V_24 -> V_36 == V_38 || V_24 -> V_36 == V_37 )
V_1 |= V_47 ;
V_25 = F_10 ( V_24 -> V_28 , V_24 -> V_29 -> V_30 , V_1 ) ;
if ( V_25 < 0 ) {
F_7 ( V_24 -> V_32 , L_4 , V_25 ) ;
return V_25 ;
}
V_25 = F_5 ( V_24 ) ;
return V_25 ;
}
static inline int F_11 ( struct V_23 * V_24 )
{
int V_25 ;
unsigned int V_1 ;
V_25 = F_6 ( V_24 -> V_28 , V_24 -> V_29 -> V_30 , & V_1 ) ;
if ( V_25 < 0 ) {
F_7 ( V_24 -> V_32 , L_5 ,
V_48 , V_25 ) ;
return V_25 ;
}
V_1 |= V_24 -> V_29 -> V_31 ;
switch ( V_24 -> V_36 ) {
case V_38 :
case V_37 :
V_1 &= ~ V_47 ;
break;
case V_41 :
V_1 |= V_49 ;
break;
default:
return - V_22 ;
}
V_25 = F_10 ( V_24 -> V_28 , V_24 -> V_29 -> V_30 , V_1 ) ;
if ( V_25 < 0 ) {
F_7 ( V_24 -> V_32 , L_6 ,
V_48 , V_25 ) ;
return V_25 ;
}
V_25 = F_5 ( V_24 ) ;
return V_25 ;
}
static void F_12 ( T_1 * V_1 , struct V_2 * V_3 )
{
V_3 -> V_5 = F_13 ( V_1 [ V_6 ] ) ;
V_3 -> V_7 = F_13 ( V_1 [ V_8 ] ) ;
if ( V_1 [ V_10 ] & V_50 ) {
V_3 -> V_9 = F_13 ( V_1 [ V_10 ] & 0x1f ) ;
if ( V_1 [ V_10 ] & V_51 )
V_3 -> V_9 += 12 ;
} else {
V_3 -> V_9 = F_13 ( V_1 [ V_10 ] & 0x3f ) ;
}
V_3 -> V_12 = V_1 [ V_13 ] & 0x07 ;
V_3 -> V_14 = F_13 ( V_1 [ V_15 ] ) ;
V_3 -> V_16 = F_13 ( V_1 [ V_17 ] ) ;
V_3 -> V_18 = F_13 ( V_1 [ V_19 ] ) + F_13 ( V_1 [ V_52 ] ) * 100 ;
V_3 -> V_18 -= 1900 ;
}
static void F_14 ( struct V_2 * V_3 , T_1 * V_1 )
{
V_1 [ V_6 ] = F_15 ( V_3 -> V_5 ) ;
V_1 [ V_8 ] = F_15 ( V_3 -> V_7 ) ;
V_1 [ V_10 ] = F_15 ( V_3 -> V_9 ) ;
V_1 [ V_13 ] = V_3 -> V_12 ;
V_1 [ V_15 ] = F_15 ( V_3 -> V_14 ) ;
V_1 [ V_17 ] = F_15 ( V_3 -> V_16 ) ;
V_1 [ V_19 ] = F_15 ( V_3 -> V_18 % 100 ) ;
V_1 [ V_52 ] = F_15 ( ( V_3 -> V_18 + 1900 ) / 100 ) ;
}
static int F_16 ( struct V_53 * V_32 , struct V_2 * V_3 )
{
struct V_23 * V_24 = F_17 ( V_32 ) ;
T_1 V_1 [ V_24 -> V_29 -> V_54 ] ;
int V_25 ;
if ( V_24 -> V_36 == V_41 ) {
V_25 = F_18 ( V_24 -> V_28 ,
V_24 -> V_29 -> V_30 ,
V_49 , V_49 ) ;
if ( V_25 ) {
F_7 ( V_32 ,
L_7 ,
V_25 ) ;
return V_25 ;
}
}
V_25 = F_19 ( V_24 -> V_28 , V_24 -> V_29 -> time , V_1 ,
V_24 -> V_29 -> V_54 ) ;
if ( V_25 < 0 )
return V_25 ;
switch ( V_24 -> V_36 ) {
case V_38 :
F_12 ( V_1 , V_3 ) ;
break;
case V_37 :
case V_41 :
F_1 ( V_1 , V_3 , V_24 -> V_4 ) ;
break;
default:
return - V_22 ;
}
F_20 ( V_32 , L_8 , V_48 ,
1900 + V_3 -> V_18 , 1 + V_3 -> V_16 , V_3 -> V_14 ,
V_3 -> V_9 , V_3 -> V_7 , V_3 -> V_5 , V_3 -> V_12 ) ;
return F_21 ( V_3 ) ;
}
static int F_22 ( struct V_53 * V_32 , struct V_2 * V_3 )
{
struct V_23 * V_24 = F_17 ( V_32 ) ;
T_1 V_1 [ V_24 -> V_29 -> V_54 ] ;
int V_25 = 0 ;
switch ( V_24 -> V_36 ) {
case V_38 :
F_14 ( V_3 , V_1 ) ;
break;
case V_37 :
case V_41 :
V_25 = F_3 ( V_3 , V_1 ) ;
break;
default:
return - V_22 ;
}
if ( V_25 < 0 )
return V_25 ;
F_20 ( V_32 , L_8 , V_48 ,
1900 + V_3 -> V_18 , 1 + V_3 -> V_16 , V_3 -> V_14 ,
V_3 -> V_9 , V_3 -> V_7 , V_3 -> V_5 , V_3 -> V_12 ) ;
V_25 = F_23 ( V_24 -> V_28 , V_24 -> V_29 -> time , V_1 ,
V_24 -> V_29 -> V_54 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_9 ( V_24 ) ;
return V_25 ;
}
static int F_24 ( struct V_53 * V_32 , struct V_33 * V_55 )
{
struct V_23 * V_24 = F_17 ( V_32 ) ;
T_1 V_1 [ V_24 -> V_29 -> V_54 ] ;
unsigned int V_35 ;
int V_25 , V_56 ;
V_25 = F_19 ( V_24 -> V_28 , V_24 -> V_29 -> V_57 , V_1 ,
V_24 -> V_29 -> V_54 ) ;
if ( V_25 < 0 )
return V_25 ;
switch ( V_24 -> V_36 ) {
case V_38 :
F_12 ( V_1 , & V_55 -> time ) ;
V_25 = F_6 ( V_24 -> V_28 , V_58 , & V_35 ) ;
if ( V_25 < 0 )
return V_25 ;
V_55 -> V_59 = ! ! V_35 ;
break;
case V_37 :
case V_41 :
F_1 ( V_1 , & V_55 -> time , V_24 -> V_4 ) ;
V_55 -> V_59 = 0 ;
for ( V_56 = 0 ; V_56 < V_24 -> V_29 -> V_54 ; V_56 ++ ) {
if ( V_1 [ V_56 ] & V_60 ) {
V_55 -> V_59 = 1 ;
break;
}
}
break;
default:
return - V_22 ;
}
F_20 ( V_32 , L_8 , V_48 ,
1900 + V_55 -> time . V_18 , 1 + V_55 -> time . V_16 ,
V_55 -> time . V_14 , V_55 -> time . V_9 ,
V_55 -> time . V_7 , V_55 -> time . V_5 ,
V_55 -> time . V_12 ) ;
V_25 = F_8 ( V_24 , V_55 ) ;
return 0 ;
}
static int F_25 ( struct V_23 * V_24 )
{
T_1 V_1 [ V_24 -> V_29 -> V_54 ] ;
int V_25 , V_56 ;
struct V_2 V_3 ;
V_25 = F_19 ( V_24 -> V_28 , V_24 -> V_29 -> V_57 , V_1 ,
V_24 -> V_29 -> V_54 ) ;
if ( V_25 < 0 )
return V_25 ;
F_1 ( V_1 , & V_3 , V_24 -> V_4 ) ;
F_20 ( V_24 -> V_32 , L_8 , V_48 ,
1900 + V_3 . V_18 , 1 + V_3 . V_16 , V_3 . V_14 ,
V_3 . V_9 , V_3 . V_7 , V_3 . V_5 , V_3 . V_12 ) ;
switch ( V_24 -> V_36 ) {
case V_38 :
V_25 = F_10 ( V_24 -> V_28 , V_58 , 0 ) ;
break;
case V_37 :
case V_41 :
for ( V_56 = 0 ; V_56 < V_24 -> V_29 -> V_54 ; V_56 ++ )
V_1 [ V_56 ] &= ~ V_60 ;
V_25 = F_23 ( V_24 -> V_28 , V_24 -> V_29 -> V_57 , V_1 ,
V_24 -> V_29 -> V_54 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_11 ( V_24 ) ;
break;
default:
return - V_22 ;
}
return V_25 ;
}
static int F_26 ( struct V_23 * V_24 )
{
int V_25 ;
T_1 V_1 [ V_24 -> V_29 -> V_54 ] ;
T_1 V_61 ;
struct V_2 V_3 ;
V_25 = F_19 ( V_24 -> V_28 , V_24 -> V_29 -> V_57 , V_1 ,
V_24 -> V_29 -> V_54 ) ;
if ( V_25 < 0 )
return V_25 ;
F_1 ( V_1 , & V_3 , V_24 -> V_4 ) ;
F_20 ( V_24 -> V_32 , L_8 , V_48 ,
1900 + V_3 . V_18 , 1 + V_3 . V_16 , V_3 . V_14 ,
V_3 . V_9 , V_3 . V_7 , V_3 . V_5 , V_3 . V_12 ) ;
switch ( V_24 -> V_36 ) {
case V_38 :
V_61 = 0x77 ;
V_25 = F_10 ( V_24 -> V_28 , V_58 , V_61 ) ;
break;
case V_37 :
case V_41 :
V_1 [ V_6 ] |= V_60 ;
V_1 [ V_8 ] |= V_60 ;
V_1 [ V_10 ] |= V_60 ;
V_1 [ V_13 ] &= ~ V_60 ;
if ( V_1 [ V_15 ] & 0x1f )
V_1 [ V_15 ] |= V_60 ;
if ( V_1 [ V_17 ] & 0xf )
V_1 [ V_17 ] |= V_60 ;
if ( V_1 [ V_19 ] & 0x7f )
V_1 [ V_19 ] |= V_60 ;
V_25 = F_23 ( V_24 -> V_28 , V_24 -> V_29 -> V_57 , V_1 ,
V_24 -> V_29 -> V_54 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_11 ( V_24 ) ;
break;
default:
return - V_22 ;
}
return V_25 ;
}
static int F_27 ( struct V_53 * V_32 , struct V_33 * V_55 )
{
struct V_23 * V_24 = F_17 ( V_32 ) ;
T_1 V_1 [ V_24 -> V_29 -> V_54 ] ;
int V_25 ;
switch ( V_24 -> V_36 ) {
case V_38 :
F_14 ( & V_55 -> time , V_1 ) ;
break;
case V_37 :
case V_41 :
F_3 ( & V_55 -> time , V_1 ) ;
break;
default:
return - V_22 ;
}
F_20 ( V_32 , L_8 , V_48 ,
1900 + V_55 -> time . V_18 , 1 + V_55 -> time . V_16 ,
V_55 -> time . V_14 , V_55 -> time . V_9 , V_55 -> time . V_7 ,
V_55 -> time . V_5 , V_55 -> time . V_12 ) ;
V_25 = F_25 ( V_24 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_23 ( V_24 -> V_28 , V_24 -> V_29 -> V_57 , V_1 ,
V_24 -> V_29 -> V_54 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_11 ( V_24 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_55 -> V_59 )
V_25 = F_26 ( V_24 ) ;
return V_25 ;
}
static int F_28 ( struct V_53 * V_32 ,
unsigned int V_59 )
{
struct V_23 * V_24 = F_17 ( V_32 ) ;
if ( V_59 )
return F_26 ( V_24 ) ;
else
return F_25 ( V_24 ) ;
}
static T_2 F_29 ( int V_62 , void * V_1 )
{
struct V_23 * V_24 = V_1 ;
F_30 ( V_24 -> V_63 , 1 , V_64 | V_65 ) ;
return V_66 ;
}
static void F_31 ( struct V_23 * V_24 , bool V_67 )
{
int V_25 ;
V_25 = F_18 ( V_24 -> V_28 , V_24 -> V_29 -> V_68 ,
V_69 ,
V_67 ? V_69 : 0 ) ;
if ( V_25 < 0 )
F_7 ( V_24 -> V_32 , L_9 ,
V_48 , V_25 ) ;
}
static void F_32 ( struct V_23 * V_24 , bool V_67 )
{
int V_25 ;
V_25 = F_18 ( V_24 -> V_28 , V_24 -> V_29 -> V_68 ,
V_70 ,
V_67 ? V_70 : 0 ) ;
if ( V_25 < 0 )
F_7 ( V_24 -> V_32 , L_10 ,
V_48 , V_25 ) ;
}
static int F_33 ( struct V_23 * V_24 )
{
T_1 V_1 [ 2 ] ;
int V_25 ;
switch ( V_24 -> V_36 ) {
case V_38 :
case V_37 :
V_25 = F_18 ( V_24 -> V_28 , V_71 ,
V_72 , V_73 ) ;
if ( V_25 < 0 )
F_7 ( V_24 -> V_32 , L_11 ,
V_48 , V_25 ) ;
V_1 [ 0 ] = ( 1 << V_74 ) | ( 1 << V_75 ) ;
V_1 [ 1 ] = ( 0 << V_74 ) | ( 1 << V_75 ) ;
V_25 = F_23 ( V_24 -> V_28 , V_58 , V_1 , 2 ) ;
break;
case V_41 :
V_1 [ 0 ] = ( 0 << V_74 ) | ( 1 << V_75 ) ;
V_25 = F_10 ( V_24 -> V_28 , V_24 -> V_29 -> V_76 , V_1 [ 0 ] ) ;
break;
default:
return - V_22 ;
}
V_24 -> V_4 = 1 ;
if ( V_25 < 0 ) {
F_7 ( V_24 -> V_32 , L_12 ,
V_48 , V_25 ) ;
return V_25 ;
}
return V_25 ;
}
static int F_34 ( struct V_77 * V_78 )
{
struct V_79 * V_42 = F_17 ( V_78 -> V_32 . V_80 ) ;
struct V_81 * V_82 = V_42 -> V_82 ;
struct V_23 * V_24 ;
const struct V_83 * V_84 ;
int V_25 , V_85 ;
if ( ! V_82 ) {
F_7 ( V_78 -> V_32 . V_80 , L_13 ) ;
return - V_86 ;
}
V_24 = F_35 ( & V_78 -> V_32 , sizeof( * V_24 ) , V_87 ) ;
if ( ! V_24 )
return - V_88 ;
switch ( V_82 -> V_36 ) {
case V_41 :
V_84 = & V_89 ;
V_24 -> V_29 = & V_90 ;
V_85 = V_91 ;
break;
case V_38 :
V_84 = & V_92 ;
V_24 -> V_29 = & V_93 ;
V_85 = V_94 ;
break;
case V_37 :
V_84 = & V_92 ;
V_24 -> V_29 = & V_93 ;
V_85 = V_95 ;
break;
default:
F_7 ( & V_78 -> V_32 , L_14 ) ;
return - V_86 ;
}
V_24 -> V_96 = F_36 ( V_42 -> V_96 -> V_97 , V_98 ) ;
if ( ! V_24 -> V_96 ) {
F_7 ( & V_78 -> V_32 , L_15 ) ;
return - V_86 ;
}
V_24 -> V_28 = F_37 ( V_24 -> V_96 , V_84 ) ;
if ( F_38 ( V_24 -> V_28 ) ) {
V_25 = F_39 ( V_24 -> V_28 ) ;
F_7 ( & V_78 -> V_32 , L_16 ,
V_25 ) ;
goto V_99;
}
V_24 -> V_32 = & V_78 -> V_32 ;
V_24 -> V_42 = V_42 ;
V_24 -> V_36 = V_42 -> V_36 ;
V_24 -> V_100 = V_42 -> V_100 ;
V_24 -> V_62 = F_40 ( V_42 -> V_101 , V_85 ) ;
if ( V_24 -> V_62 <= 0 ) {
V_25 = - V_22 ;
F_7 ( & V_78 -> V_32 , L_17 ,
V_85 ) ;
goto V_99;
}
F_41 ( V_78 , V_24 ) ;
V_25 = F_33 ( V_24 ) ;
if ( V_24 -> V_100 ) {
F_31 ( V_24 , true ) ;
F_32 ( V_24 , true ) ;
}
F_42 ( & V_78 -> V_32 , 1 ) ;
V_24 -> V_63 = F_43 ( & V_78 -> V_32 , L_18 ,
& V_102 , V_103 ) ;
if ( F_38 ( V_24 -> V_63 ) ) {
V_25 = F_39 ( V_24 -> V_63 ) ;
goto V_99;
}
V_25 = F_44 ( & V_78 -> V_32 , V_24 -> V_62 , NULL ,
F_29 , 0 , L_19 ,
V_24 ) ;
if ( V_25 < 0 ) {
F_7 ( & V_78 -> V_32 , L_20 ,
V_24 -> V_62 , V_25 ) ;
goto V_99;
}
return 0 ;
V_99:
F_45 ( V_24 -> V_96 ) ;
return V_25 ;
}
static void F_46 ( struct V_77 * V_78 )
{
struct V_23 * V_24 = F_47 ( V_78 ) ;
int V_56 ;
unsigned int V_35 = 0 ;
if ( V_24 -> V_100 ) {
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
F_31 ( V_24 , false ) ;
F_6 ( V_24 -> V_28 , V_24 -> V_29 -> V_68 , & V_35 ) ;
F_48 ( L_21 , V_48 , V_35 ) ;
if ( V_35 & V_69 )
F_49 ( L_22 ,
V_48 ) ;
else {
F_50 ( L_23 ,
V_48 ) ;
break;
}
}
}
F_32 ( V_24 , false ) ;
}
static int F_51 ( struct V_77 * V_78 )
{
struct V_23 * V_24 = F_47 ( V_78 ) ;
F_46 ( V_78 ) ;
F_45 ( V_24 -> V_96 ) ;
return 0 ;
}
static int F_52 ( struct V_53 * V_32 )
{
struct V_23 * V_24 = F_17 ( V_32 ) ;
int V_25 = 0 ;
if ( F_53 ( V_32 ) )
V_25 = F_54 ( V_24 -> V_62 ) ;
return V_25 ;
}
static int F_55 ( struct V_53 * V_32 )
{
struct V_23 * V_24 = F_17 ( V_32 ) ;
int V_25 = 0 ;
if ( F_53 ( V_32 ) )
V_25 = F_56 ( V_24 -> V_62 ) ;
return V_25 ;
}
