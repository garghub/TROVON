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
case V_42 :
V_25 = F_6 ( V_24 -> V_43 -> V_44 , V_45 ,
& V_35 ) ;
V_35 &= V_46 ;
break;
default:
return - V_22 ;
}
if ( V_25 < 0 )
return V_25 ;
if ( V_35 )
V_34 -> V_47 = 1 ;
else
V_34 -> V_47 = 0 ;
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
V_1 |= V_48 ;
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
V_49 , V_25 ) ;
return V_25 ;
}
V_1 |= V_24 -> V_29 -> V_31 ;
switch ( V_24 -> V_36 ) {
case V_38 :
case V_37 :
V_1 &= ~ V_48 ;
break;
case V_41 :
V_1 |= V_50 ;
break;
case V_42 :
V_1 |= V_51 ;
break;
default:
return - V_22 ;
}
V_25 = F_10 ( V_24 -> V_28 , V_24 -> V_29 -> V_30 , V_1 ) ;
if ( V_25 < 0 ) {
F_7 ( V_24 -> V_32 , L_6 ,
V_49 , V_25 ) ;
return V_25 ;
}
V_25 = F_5 ( V_24 ) ;
if ( V_24 -> V_36 == V_42 )
F_12 ( V_24 -> V_28 , V_24 -> V_29 -> V_30 ,
V_51 , 0 ) ;
return V_25 ;
}
static void F_13 ( T_1 * V_1 , struct V_2 * V_3 )
{
V_3 -> V_5 = F_14 ( V_1 [ V_6 ] ) ;
V_3 -> V_7 = F_14 ( V_1 [ V_8 ] ) ;
if ( V_1 [ V_10 ] & V_52 ) {
V_3 -> V_9 = F_14 ( V_1 [ V_10 ] & 0x1f ) ;
if ( V_1 [ V_10 ] & V_53 )
V_3 -> V_9 += 12 ;
} else {
V_3 -> V_9 = F_14 ( V_1 [ V_10 ] & 0x3f ) ;
}
V_3 -> V_12 = V_1 [ V_13 ] & 0x07 ;
V_3 -> V_14 = F_14 ( V_1 [ V_15 ] ) ;
V_3 -> V_16 = F_14 ( V_1 [ V_17 ] ) ;
V_3 -> V_18 = F_14 ( V_1 [ V_19 ] ) + F_14 ( V_1 [ V_54 ] ) * 100 ;
V_3 -> V_18 -= 1900 ;
}
static void F_15 ( struct V_2 * V_3 , T_1 * V_1 )
{
V_1 [ V_6 ] = F_16 ( V_3 -> V_5 ) ;
V_1 [ V_8 ] = F_16 ( V_3 -> V_7 ) ;
V_1 [ V_10 ] = F_16 ( V_3 -> V_9 ) ;
V_1 [ V_13 ] = V_3 -> V_12 ;
V_1 [ V_15 ] = F_16 ( V_3 -> V_14 ) ;
V_1 [ V_17 ] = F_16 ( V_3 -> V_16 ) ;
V_1 [ V_19 ] = F_16 ( V_3 -> V_18 % 100 ) ;
V_1 [ V_54 ] = F_16 ( ( V_3 -> V_18 + 1900 ) / 100 ) ;
}
static int F_17 ( struct V_55 * V_32 , struct V_2 * V_3 )
{
struct V_23 * V_24 = F_18 ( V_32 ) ;
T_1 V_1 [ V_24 -> V_29 -> V_56 ] ;
int V_25 ;
if ( V_24 -> V_36 == V_41 || V_24 -> V_36 == V_42 ) {
V_25 = F_12 ( V_24 -> V_28 ,
V_24 -> V_29 -> V_30 ,
V_50 , V_50 ) ;
if ( V_25 ) {
F_7 ( V_32 ,
L_7 ,
V_25 ) ;
return V_25 ;
}
}
V_25 = F_19 ( V_24 -> V_28 , V_24 -> V_29 -> time , V_1 ,
V_24 -> V_29 -> V_56 ) ;
if ( V_25 < 0 )
return V_25 ;
switch ( V_24 -> V_36 ) {
case V_38 :
F_13 ( V_1 , V_3 ) ;
break;
case V_37 :
case V_41 :
case V_42 :
F_1 ( V_1 , V_3 , V_24 -> V_4 ) ;
break;
default:
return - V_22 ;
}
F_20 ( V_32 , L_8 , V_49 ,
1900 + V_3 -> V_18 , 1 + V_3 -> V_16 , V_3 -> V_14 ,
V_3 -> V_9 , V_3 -> V_7 , V_3 -> V_5 , V_3 -> V_12 ) ;
return F_21 ( V_3 ) ;
}
static int F_22 ( struct V_55 * V_32 , struct V_2 * V_3 )
{
struct V_23 * V_24 = F_18 ( V_32 ) ;
T_1 V_1 [ V_24 -> V_29 -> V_56 ] ;
int V_25 = 0 ;
switch ( V_24 -> V_36 ) {
case V_38 :
F_15 ( V_3 , V_1 ) ;
break;
case V_37 :
case V_41 :
case V_42 :
V_25 = F_3 ( V_3 , V_1 ) ;
break;
default:
return - V_22 ;
}
if ( V_25 < 0 )
return V_25 ;
F_20 ( V_32 , L_8 , V_49 ,
1900 + V_3 -> V_18 , 1 + V_3 -> V_16 , V_3 -> V_14 ,
V_3 -> V_9 , V_3 -> V_7 , V_3 -> V_5 , V_3 -> V_12 ) ;
V_25 = F_23 ( V_24 -> V_28 , V_24 -> V_29 -> time , V_1 ,
V_24 -> V_29 -> V_56 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_9 ( V_24 ) ;
return V_25 ;
}
static int F_24 ( struct V_55 * V_32 , struct V_33 * V_57 )
{
struct V_23 * V_24 = F_18 ( V_32 ) ;
T_1 V_1 [ V_24 -> V_29 -> V_56 ] ;
unsigned int V_35 ;
int V_25 , V_58 ;
V_25 = F_19 ( V_24 -> V_28 , V_24 -> V_29 -> V_59 , V_1 ,
V_24 -> V_29 -> V_56 ) ;
if ( V_25 < 0 )
return V_25 ;
switch ( V_24 -> V_36 ) {
case V_38 :
F_13 ( V_1 , & V_57 -> time ) ;
V_25 = F_6 ( V_24 -> V_28 , V_60 , & V_35 ) ;
if ( V_25 < 0 )
return V_25 ;
V_57 -> V_61 = ! ! V_35 ;
break;
case V_37 :
case V_41 :
case V_42 :
F_1 ( V_1 , & V_57 -> time , V_24 -> V_4 ) ;
V_57 -> V_61 = 0 ;
for ( V_58 = 0 ; V_58 < V_24 -> V_29 -> V_56 ; V_58 ++ ) {
if ( V_1 [ V_58 ] & V_62 ) {
V_57 -> V_61 = 1 ;
break;
}
}
break;
default:
return - V_22 ;
}
F_20 ( V_32 , L_8 , V_49 ,
1900 + V_57 -> time . V_18 , 1 + V_57 -> time . V_16 ,
V_57 -> time . V_14 , V_57 -> time . V_9 ,
V_57 -> time . V_7 , V_57 -> time . V_5 ,
V_57 -> time . V_12 ) ;
V_25 = F_8 ( V_24 , V_57 ) ;
return 0 ;
}
static int F_25 ( struct V_23 * V_24 )
{
T_1 V_1 [ V_24 -> V_29 -> V_56 ] ;
int V_25 , V_58 ;
struct V_2 V_3 ;
V_25 = F_19 ( V_24 -> V_28 , V_24 -> V_29 -> V_59 , V_1 ,
V_24 -> V_29 -> V_56 ) ;
if ( V_25 < 0 )
return V_25 ;
F_1 ( V_1 , & V_3 , V_24 -> V_4 ) ;
F_20 ( V_24 -> V_32 , L_8 , V_49 ,
1900 + V_3 . V_18 , 1 + V_3 . V_16 , V_3 . V_14 ,
V_3 . V_9 , V_3 . V_7 , V_3 . V_5 , V_3 . V_12 ) ;
switch ( V_24 -> V_36 ) {
case V_38 :
V_25 = F_10 ( V_24 -> V_28 , V_60 , 0 ) ;
break;
case V_37 :
case V_41 :
case V_42 :
for ( V_58 = 0 ; V_58 < V_24 -> V_29 -> V_56 ; V_58 ++ )
V_1 [ V_58 ] &= ~ V_62 ;
V_25 = F_23 ( V_24 -> V_28 , V_24 -> V_29 -> V_59 , V_1 ,
V_24 -> V_29 -> V_56 ) ;
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
T_1 V_1 [ V_24 -> V_29 -> V_56 ] ;
T_1 V_63 ;
struct V_2 V_3 ;
V_25 = F_19 ( V_24 -> V_28 , V_24 -> V_29 -> V_59 , V_1 ,
V_24 -> V_29 -> V_56 ) ;
if ( V_25 < 0 )
return V_25 ;
F_1 ( V_1 , & V_3 , V_24 -> V_4 ) ;
F_20 ( V_24 -> V_32 , L_8 , V_49 ,
1900 + V_3 . V_18 , 1 + V_3 . V_16 , V_3 . V_14 ,
V_3 . V_9 , V_3 . V_7 , V_3 . V_5 , V_3 . V_12 ) ;
switch ( V_24 -> V_36 ) {
case V_38 :
V_63 = 0x77 ;
V_25 = F_10 ( V_24 -> V_28 , V_60 , V_63 ) ;
break;
case V_37 :
case V_41 :
case V_42 :
V_1 [ V_6 ] |= V_62 ;
V_1 [ V_8 ] |= V_62 ;
V_1 [ V_10 ] |= V_62 ;
V_1 [ V_13 ] &= ~ V_62 ;
if ( V_1 [ V_15 ] & 0x1f )
V_1 [ V_15 ] |= V_62 ;
if ( V_1 [ V_17 ] & 0xf )
V_1 [ V_17 ] |= V_62 ;
if ( V_1 [ V_19 ] & 0x7f )
V_1 [ V_19 ] |= V_62 ;
V_25 = F_23 ( V_24 -> V_28 , V_24 -> V_29 -> V_59 , V_1 ,
V_24 -> V_29 -> V_56 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_11 ( V_24 ) ;
break;
default:
return - V_22 ;
}
return V_25 ;
}
static int F_27 ( struct V_55 * V_32 , struct V_33 * V_57 )
{
struct V_23 * V_24 = F_18 ( V_32 ) ;
T_1 V_1 [ V_24 -> V_29 -> V_56 ] ;
int V_25 ;
switch ( V_24 -> V_36 ) {
case V_38 :
F_15 ( & V_57 -> time , V_1 ) ;
break;
case V_37 :
case V_41 :
case V_42 :
F_3 ( & V_57 -> time , V_1 ) ;
break;
default:
return - V_22 ;
}
F_20 ( V_32 , L_8 , V_49 ,
1900 + V_57 -> time . V_18 , 1 + V_57 -> time . V_16 ,
V_57 -> time . V_14 , V_57 -> time . V_9 , V_57 -> time . V_7 ,
V_57 -> time . V_5 , V_57 -> time . V_12 ) ;
V_25 = F_25 ( V_24 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_23 ( V_24 -> V_28 , V_24 -> V_29 -> V_59 , V_1 ,
V_24 -> V_29 -> V_56 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_11 ( V_24 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_57 -> V_61 )
V_25 = F_26 ( V_24 ) ;
return V_25 ;
}
static int F_28 ( struct V_55 * V_32 ,
unsigned int V_61 )
{
struct V_23 * V_24 = F_18 ( V_32 ) ;
if ( V_61 )
return F_26 ( V_24 ) ;
else
return F_25 ( V_24 ) ;
}
static T_2 F_29 ( int V_64 , void * V_1 )
{
struct V_23 * V_24 = V_1 ;
F_30 ( V_24 -> V_65 , 1 , V_66 | V_67 ) ;
return V_68 ;
}
static int F_31 ( struct V_23 * V_24 )
{
T_1 V_1 [ 2 ] ;
int V_25 ;
switch ( V_24 -> V_36 ) {
case V_38 :
case V_37 :
V_25 = F_12 ( V_24 -> V_28 , V_69 ,
V_70 , V_71 ) ;
if ( V_25 < 0 )
F_7 ( V_24 -> V_32 , L_9 ,
V_49 , V_25 ) ;
V_1 [ 0 ] = ( 1 << V_72 ) | ( 1 << V_73 ) ;
V_1 [ 1 ] = ( 0 << V_72 ) | ( 1 << V_73 ) ;
V_25 = F_23 ( V_24 -> V_28 , V_60 , V_1 , 2 ) ;
break;
case V_41 :
case V_42 :
V_1 [ 0 ] = ( 0 << V_72 ) | ( 1 << V_73 ) ;
V_25 = F_10 ( V_24 -> V_28 , V_24 -> V_29 -> V_74 , V_1 [ 0 ] ) ;
if ( V_25 < 0 )
break;
V_25 = F_11 ( V_24 ) ;
break;
default:
return - V_22 ;
}
V_24 -> V_4 = 1 ;
if ( V_25 < 0 ) {
F_7 ( V_24 -> V_32 , L_10 ,
V_49 , V_25 ) ;
return V_25 ;
}
return V_25 ;
}
static int F_32 ( struct V_75 * V_76 )
{
struct V_77 * V_43 = F_18 ( V_76 -> V_32 . V_78 ) ;
struct V_79 * V_80 = V_43 -> V_80 ;
struct V_23 * V_24 ;
const struct V_81 * V_82 ;
int V_25 , V_83 ;
if ( ! V_80 ) {
F_7 ( V_76 -> V_32 . V_78 , L_11 ) ;
return - V_84 ;
}
V_24 = F_33 ( & V_76 -> V_32 , sizeof( * V_24 ) , V_85 ) ;
if ( ! V_24 )
return - V_86 ;
switch ( F_34 ( V_76 ) -> V_87 ) {
case V_41 :
case V_42 :
V_82 = & V_88 ;
V_24 -> V_29 = & V_89 ;
V_83 = V_90 ;
break;
case V_38 :
V_82 = & V_91 ;
V_24 -> V_29 = & V_92 ;
V_83 = V_93 ;
break;
case V_37 :
V_82 = & V_91 ;
V_24 -> V_29 = & V_92 ;
V_83 = V_94 ;
break;
default:
F_7 ( & V_76 -> V_32 ,
L_12 ,
F_34 ( V_76 ) -> V_87 ) ;
return - V_84 ;
}
V_24 -> V_95 = F_35 ( V_43 -> V_95 -> V_96 , V_97 ) ;
if ( ! V_24 -> V_95 ) {
F_7 ( & V_76 -> V_32 , L_13 ) ;
return - V_84 ;
}
V_24 -> V_28 = F_36 ( V_24 -> V_95 , V_82 ) ;
if ( F_37 ( V_24 -> V_28 ) ) {
V_25 = F_38 ( V_24 -> V_28 ) ;
F_7 ( & V_76 -> V_32 , L_14 ,
V_25 ) ;
goto V_98;
}
V_24 -> V_32 = & V_76 -> V_32 ;
V_24 -> V_43 = V_43 ;
V_24 -> V_36 = F_34 ( V_76 ) -> V_87 ;
if ( V_43 -> V_99 ) {
V_24 -> V_64 = F_39 ( V_43 -> V_99 , V_83 ) ;
if ( V_24 -> V_64 <= 0 ) {
V_25 = - V_22 ;
F_7 ( & V_76 -> V_32 , L_15 ,
V_83 ) ;
goto V_98;
}
}
F_40 ( V_76 , V_24 ) ;
V_25 = F_31 ( V_24 ) ;
F_41 ( & V_76 -> V_32 , 1 ) ;
V_24 -> V_65 = F_42 ( & V_76 -> V_32 , L_16 ,
& V_100 , V_101 ) ;
if ( F_37 ( V_24 -> V_65 ) ) {
V_25 = F_38 ( V_24 -> V_65 ) ;
goto V_98;
}
if ( ! V_24 -> V_64 ) {
F_43 ( & V_76 -> V_32 , L_17 ) ;
return 0 ;
}
V_25 = F_44 ( & V_76 -> V_32 , V_24 -> V_64 , NULL ,
F_29 , 0 , L_18 ,
V_24 ) ;
if ( V_25 < 0 ) {
F_7 ( & V_76 -> V_32 , L_19 ,
V_24 -> V_64 , V_25 ) ;
goto V_98;
}
return 0 ;
V_98:
F_45 ( V_24 -> V_95 ) ;
return V_25 ;
}
static int F_46 ( struct V_75 * V_76 )
{
struct V_23 * V_24 = F_47 ( V_76 ) ;
F_45 ( V_24 -> V_95 ) ;
return 0 ;
}
static int F_48 ( struct V_55 * V_32 )
{
struct V_23 * V_24 = F_18 ( V_32 ) ;
int V_25 = 0 ;
if ( V_24 -> V_64 && F_49 ( V_32 ) )
V_25 = F_50 ( V_24 -> V_64 ) ;
return V_25 ;
}
static int F_51 ( struct V_55 * V_32 )
{
struct V_23 * V_24 = F_18 ( V_32 ) ;
int V_25 = 0 ;
if ( V_24 -> V_64 && F_49 ( V_32 ) )
V_25 = F_52 ( V_24 -> V_64 ) ;
return V_25 ;
}
