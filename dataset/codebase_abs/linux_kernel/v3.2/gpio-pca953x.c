static int F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
int V_5 = 0 ;
if ( V_2 -> V_6 . V_7 <= 8 )
V_5 = F_2 ( V_2 -> V_8 , V_3 , V_4 ) ;
else {
switch ( V_2 -> V_9 ) {
case V_10 :
V_5 = F_3 ( V_2 -> V_8 ,
V_3 << 1 , V_4 ) ;
break;
case V_11 :
V_5 = F_2 ( V_2 -> V_8 , V_3 << 1 ,
V_4 & 0xff ) ;
if ( V_5 < 0 )
break;
V_5 = F_2 ( V_2 -> V_8 ,
( V_3 << 1 ) + 1 ,
( V_4 & 0xff00 ) >> 8 ) ;
break;
}
}
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_8 -> V_12 , L_1 ) ;
return V_5 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
int V_5 ;
if ( V_2 -> V_6 . V_7 <= 8 )
V_5 = F_6 ( V_2 -> V_8 , V_3 ) ;
else
V_5 = F_7 ( V_2 -> V_8 , V_3 << 1 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_8 -> V_12 , L_2 ) ;
return V_5 ;
}
* V_4 = ( T_1 ) V_5 ;
return 0 ;
}
static int F_8 ( struct V_6 * V_13 , unsigned V_14 )
{
struct V_1 * V_2 ;
T_1 V_15 ;
int V_5 , V_16 = 0 ;
V_2 = F_9 ( V_13 , struct V_1 , V_6 ) ;
F_10 ( & V_2 -> V_17 ) ;
V_15 = V_2 -> V_18 | ( 1u << V_14 ) ;
switch ( V_2 -> V_9 ) {
case V_10 :
V_16 = V_19 ;
break;
case V_11 :
V_16 = V_20 ;
break;
}
V_5 = F_1 ( V_2 , V_16 , V_15 ) ;
if ( V_5 )
goto exit;
V_2 -> V_18 = V_15 ;
V_5 = 0 ;
exit:
F_11 ( & V_2 -> V_17 ) ;
return V_5 ;
}
static int F_12 ( struct V_6 * V_13 ,
unsigned V_14 , int V_4 )
{
struct V_1 * V_2 ;
T_1 V_15 ;
int V_5 , V_16 = 0 ;
V_2 = F_9 ( V_13 , struct V_1 , V_6 ) ;
F_10 ( & V_2 -> V_17 ) ;
if ( V_4 )
V_15 = V_2 -> V_21 | ( 1u << V_14 ) ;
else
V_15 = V_2 -> V_21 & ~ ( 1u << V_14 ) ;
switch ( V_2 -> V_9 ) {
case V_10 :
V_16 = V_22 ;
break;
case V_11 :
V_16 = V_23 ;
break;
}
V_5 = F_1 ( V_2 , V_16 , V_15 ) ;
if ( V_5 )
goto exit;
V_2 -> V_21 = V_15 ;
V_15 = V_2 -> V_18 & ~ ( 1u << V_14 ) ;
switch ( V_2 -> V_9 ) {
case V_10 :
V_16 = V_19 ;
break;
case V_11 :
V_16 = V_20 ;
break;
}
V_5 = F_1 ( V_2 , V_16 , V_15 ) ;
if ( V_5 )
goto exit;
V_2 -> V_18 = V_15 ;
V_5 = 0 ;
exit:
F_11 ( & V_2 -> V_17 ) ;
return V_5 ;
}
static int F_13 ( struct V_6 * V_13 , unsigned V_14 )
{
struct V_1 * V_2 ;
T_1 V_15 ;
int V_5 , V_16 = 0 ;
V_2 = F_9 ( V_13 , struct V_1 , V_6 ) ;
F_10 ( & V_2 -> V_17 ) ;
switch ( V_2 -> V_9 ) {
case V_10 :
V_16 = V_24 ;
break;
case V_11 :
V_16 = V_25 ;
break;
}
V_5 = F_5 ( V_2 , V_16 , & V_15 ) ;
F_11 ( & V_2 -> V_17 ) ;
if ( V_5 < 0 ) {
return 0 ;
}
return ( V_15 & ( 1u << V_14 ) ) ? 1 : 0 ;
}
static void F_14 ( struct V_6 * V_13 , unsigned V_14 , int V_4 )
{
struct V_1 * V_2 ;
T_1 V_15 ;
int V_5 , V_16 = 0 ;
V_2 = F_9 ( V_13 , struct V_1 , V_6 ) ;
F_10 ( & V_2 -> V_17 ) ;
if ( V_4 )
V_15 = V_2 -> V_21 | ( 1u << V_14 ) ;
else
V_15 = V_2 -> V_21 & ~ ( 1u << V_14 ) ;
switch ( V_2 -> V_9 ) {
case V_10 :
V_16 = V_22 ;
break;
case V_11 :
V_16 = V_23 ;
break;
}
V_5 = F_1 ( V_2 , V_16 , V_15 ) ;
if ( V_5 )
goto exit;
V_2 -> V_21 = V_15 ;
exit:
F_11 ( & V_2 -> V_17 ) ;
}
static void F_15 ( struct V_1 * V_2 , int V_26 )
{
struct V_6 * V_13 ;
V_13 = & V_2 -> V_6 ;
V_13 -> V_27 = F_8 ;
V_13 -> V_28 = F_12 ;
V_13 -> V_29 = F_13 ;
V_13 -> V_30 = F_14 ;
V_13 -> V_31 = 1 ;
V_13 -> V_32 = V_2 -> V_33 ;
V_13 -> V_7 = V_26 ;
V_13 -> V_34 = V_2 -> V_8 -> V_35 ;
V_13 -> V_12 = & V_2 -> V_8 -> V_12 ;
V_13 -> V_36 = V_37 ;
V_13 -> V_38 = V_2 -> V_38 ;
}
static int F_16 ( struct V_6 * V_13 , unsigned V_14 )
{
struct V_1 * V_2 ;
V_2 = F_9 ( V_13 , struct V_1 , V_6 ) ;
return V_2 -> V_39 + V_14 ;
}
static void F_17 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_18 ( V_41 ) ;
V_2 -> V_42 &= ~ ( 1 << ( V_41 -> V_43 - V_2 -> V_39 ) ) ;
}
static void F_19 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_18 ( V_41 ) ;
V_2 -> V_42 |= 1 << ( V_41 -> V_43 - V_2 -> V_39 ) ;
}
static void F_20 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_18 ( V_41 ) ;
F_10 ( & V_2 -> V_44 ) ;
}
static void F_21 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_18 ( V_41 ) ;
T_1 V_45 ;
T_1 V_46 ;
V_45 = V_2 -> V_47 | V_2 -> V_48 ;
V_45 &= ~ V_2 -> V_18 ;
while ( V_45 ) {
V_46 = F_22 ( V_45 ) ;
F_8 ( & V_2 -> V_6 , V_46 ) ;
V_45 &= ~ ( 1 << V_46 ) ;
}
F_11 ( & V_2 -> V_44 ) ;
}
static int F_23 ( struct V_40 * V_41 , unsigned int type )
{
struct V_1 * V_2 = F_18 ( V_41 ) ;
T_1 V_46 = V_41 -> V_43 - V_2 -> V_39 ;
T_1 V_49 = 1 << V_46 ;
if ( ! ( type & V_50 ) ) {
F_4 ( & V_2 -> V_8 -> V_12 , L_3 ,
V_41 -> V_43 , type ) ;
return - V_51 ;
}
if ( type & V_52 )
V_2 -> V_47 |= V_49 ;
else
V_2 -> V_47 &= ~ V_49 ;
if ( type & V_53 )
V_2 -> V_48 |= V_49 ;
else
V_2 -> V_48 &= ~ V_49 ;
return 0 ;
}
static T_1 F_24 ( struct V_1 * V_2 )
{
T_1 V_54 ;
T_1 V_55 ;
T_1 V_56 ;
T_1 V_57 ;
int V_5 , V_16 = 0 ;
switch ( V_2 -> V_9 ) {
case V_10 :
V_16 = V_24 ;
break;
case V_11 :
V_16 = V_25 ;
break;
}
V_5 = F_5 ( V_2 , V_16 , & V_54 ) ;
if ( V_5 )
return 0 ;
V_54 &= V_2 -> V_18 ;
V_55 = V_2 -> V_58 ;
V_57 = ( V_54 ^ V_55 ) & V_2 -> V_42 ;
if ( ! V_57 )
return 0 ;
V_2 -> V_58 = V_54 ;
V_56 = ( V_55 & V_2 -> V_47 ) |
( V_54 & V_2 -> V_48 ) ;
V_56 &= V_57 ;
return V_56 ;
}
static T_2 F_25 ( int V_43 , void * V_59 )
{
struct V_1 * V_2 = V_59 ;
T_1 V_56 ;
T_1 V_46 ;
V_56 = F_24 ( V_2 ) ;
if ( ! V_56 )
return V_60 ;
do {
V_46 = F_22 ( V_56 ) ;
F_26 ( V_46 + V_2 -> V_39 ) ;
V_56 &= ~ ( 1 << V_46 ) ;
} while ( V_56 );
return V_60 ;
}
static int F_27 ( struct V_1 * V_2 ,
const struct V_61 * V_62 ,
int V_39 )
{
struct V_63 * V_8 = V_2 -> V_8 ;
int V_5 , V_16 = 0 ;
if ( V_39 != - 1
&& ( V_62 -> V_64 & V_65 ) ) {
int V_66 ;
switch ( V_2 -> V_9 ) {
case V_10 :
V_16 = V_24 ;
break;
case V_11 :
V_16 = V_25 ;
break;
}
V_5 = F_5 ( V_2 , V_16 , & V_2 -> V_58 ) ;
if ( V_5 )
goto V_67;
V_2 -> V_58 &= V_2 -> V_18 ;
F_28 ( & V_2 -> V_44 ) ;
V_2 -> V_39 = F_29 ( - 1 , V_39 , V_2 -> V_6 . V_7 , - 1 ) ;
if ( V_2 -> V_39 < 0 )
goto V_67;
for ( V_66 = 0 ; V_66 < V_2 -> V_6 . V_7 ; V_66 ++ ) {
int V_43 = V_66 + V_2 -> V_39 ;
F_30 ( V_43 , V_68 ) ;
F_31 ( V_43 , V_2 ) ;
F_32 ( V_43 , & V_69 ) ;
F_33 ( V_43 , true ) ;
#ifdef F_34
F_35 ( V_43 , V_70 ) ;
#else
F_36 ( V_43 ) ;
#endif
}
V_5 = F_37 ( V_8 -> V_43 ,
NULL ,
F_25 ,
V_71 | V_72 ,
F_38 ( & V_8 -> V_12 ) , V_2 ) ;
if ( V_5 ) {
F_4 ( & V_8 -> V_12 , L_4 ,
V_8 -> V_43 ) ;
goto V_67;
}
V_2 -> V_6 . V_73 = F_16 ;
}
return 0 ;
V_67:
V_2 -> V_39 = - 1 ;
return V_5 ;
}
static void F_39 ( struct V_1 * V_2 )
{
if ( V_2 -> V_39 != - 1 ) {
F_40 ( V_2 -> V_39 , V_2 -> V_6 . V_7 ) ;
F_41 ( V_2 -> V_8 -> V_43 , V_2 ) ;
}
}
static int F_27 ( struct V_1 * V_2 ,
const struct V_61 * V_62 ,
int V_39 )
{
struct V_63 * V_8 = V_2 -> V_8 ;
if ( V_39 != - 1 && ( V_62 -> V_64 & V_65 ) )
F_42 ( & V_8 -> V_12 , L_5 ) ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 )
{
}
static void
F_43 ( struct V_63 * V_8 , int * V_74 , int * V_75 )
{
struct V_76 * V_77 ;
const T_3 * V_4 ;
int V_78 ;
V_77 = V_8 -> V_12 . V_79 ;
if ( V_77 == NULL )
return;
* V_74 = - 1 ;
V_4 = F_44 ( V_77 , L_6 , & V_78 ) ;
F_45 ( V_4 , L_7 , V_80 ) ;
if ( V_4 ) {
if ( V_78 != sizeof( * V_4 ) )
F_42 ( & V_8 -> V_12 , L_8 ,
V_77 -> V_81 ) ;
else
* V_74 = F_46 ( V_4 ) ;
}
V_4 = F_44 ( V_77 , L_9 , NULL ) ;
F_45 ( V_4 , L_10 , V_80 ) ;
if ( V_4 )
* V_75 = * V_4 ;
}
static void
F_43 ( struct V_63 * V_8 , int * V_74 , int * V_75 )
{
* V_74 = - 1 ;
}
static int T_4 F_47 ( struct V_1 * V_2 , int V_75 )
{
int V_5 ;
V_5 = F_5 ( V_2 , V_22 , & V_2 -> V_21 ) ;
if ( V_5 )
goto V_82;
V_5 = F_5 ( V_2 , V_19 ,
& V_2 -> V_18 ) ;
if ( V_5 )
goto V_82;
V_5 = F_1 ( V_2 , V_83 , V_75 ) ;
V_82:
return V_5 ;
}
static int T_4 F_48 ( struct V_1 * V_2 , int V_75 )
{
int V_5 ;
T_1 V_4 = 0 ;
F_1 ( V_2 , V_84 , 0x0 ) ;
F_1 ( V_2 , V_20 , 0xffff ) ;
F_1 ( V_2 , V_23 , 0x0 ) ;
V_5 = F_5 ( V_2 , V_25 , & V_4 ) ;
if ( V_5 )
goto V_82;
V_5 = F_5 ( V_2 , V_23 , & V_2 -> V_21 ) ;
if ( V_5 )
goto V_82;
V_5 = F_5 ( V_2 , V_20 , & V_2 -> V_18 ) ;
if ( V_5 )
goto V_82;
F_1 ( V_2 , V_85 , V_75 ) ;
F_1 ( V_2 , V_86 , 0x202 ) ;
return 0 ;
V_82:
return V_5 ;
}
static int T_4 F_49 ( struct V_63 * V_8 ,
const struct V_61 * V_62 )
{
struct V_87 * V_88 ;
struct V_1 * V_2 ;
int V_39 = 0 , V_75 = 0 ;
int V_5 ;
V_2 = F_50 ( sizeof( struct V_1 ) , V_89 ) ;
if ( V_2 == NULL )
return - V_90 ;
V_88 = V_8 -> V_12 . V_91 ;
if ( V_88 ) {
V_39 = V_88 -> V_39 ;
V_2 -> V_33 = V_88 -> V_74 ;
V_75 = V_88 -> V_75 ;
V_2 -> V_38 = V_88 -> V_38 ;
} else {
F_43 ( V_8 , & V_2 -> V_33 , & V_75 ) ;
#ifdef F_51
if ( F_52 ( V_8 -> V_12 . V_79 , L_11 , NULL ) == NULL )
V_39 = - 1 ;
#endif
}
V_2 -> V_8 = V_8 ;
V_2 -> V_9 = V_62 -> V_64 & ( V_10 | V_11 ) ;
F_28 ( & V_2 -> V_17 ) ;
F_15 ( V_2 , V_62 -> V_64 & V_92 ) ;
if ( V_2 -> V_9 == V_10 )
V_5 = F_47 ( V_2 , V_75 ) ;
else
V_5 = F_48 ( V_2 , V_75 ) ;
if ( V_5 )
goto V_67;
V_5 = F_27 ( V_2 , V_62 , V_39 ) ;
if ( V_5 )
goto V_67;
V_5 = F_53 ( & V_2 -> V_6 ) ;
if ( V_5 )
goto V_93;
if ( V_88 && V_88 -> V_94 ) {
V_5 = V_88 -> V_94 ( V_8 , V_2 -> V_6 . V_32 ,
V_2 -> V_6 . V_7 , V_88 -> V_95 ) ;
if ( V_5 < 0 )
F_42 ( & V_8 -> V_12 , L_12 , V_5 ) ;
}
F_54 ( V_8 , V_2 ) ;
return 0 ;
V_93:
F_39 ( V_2 ) ;
V_67:
F_55 ( V_2 ) ;
return V_5 ;
}
static int F_56 ( struct V_63 * V_8 )
{
struct V_87 * V_88 = V_8 -> V_12 . V_91 ;
struct V_1 * V_2 = F_57 ( V_8 ) ;
int V_5 = 0 ;
if ( V_88 && V_88 -> V_96 ) {
V_5 = V_88 -> V_96 ( V_8 , V_2 -> V_6 . V_32 ,
V_2 -> V_6 . V_7 , V_88 -> V_95 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_8 -> V_12 , L_13 ,
L_14 , V_5 ) ;
return V_5 ;
}
}
V_5 = F_58 ( & V_2 -> V_6 ) ;
if ( V_5 ) {
F_4 ( & V_8 -> V_12 , L_13 ,
L_15 , V_5 ) ;
return V_5 ;
}
F_39 ( V_2 ) ;
F_55 ( V_2 ) ;
return 0 ;
}
static int T_5 F_59 ( void )
{
return F_60 ( & V_97 ) ;
}
static void T_6 F_61 ( void )
{
F_62 ( & V_97 ) ;
}
