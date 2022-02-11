static int F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
int V_5 = 0 ;
if ( V_2 -> V_6 . V_7 <= 8 )
V_5 = F_2 ( V_2 -> V_8 , V_3 , V_4 ) ;
else if ( V_2 -> V_6 . V_7 == 24 ) {
F_3 ( & V_4 ) ;
V_5 = F_4 ( V_2 -> V_8 ,
( V_3 << 2 ) | V_9 ,
3 ,
( V_10 * ) & V_4 ) ;
}
else {
switch ( V_2 -> V_11 ) {
case V_12 :
V_5 = F_5 ( V_2 -> V_8 ,
V_3 << 1 , V_4 ) ;
break;
case V_13 :
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
F_6 ( & V_2 -> V_8 -> V_14 , L_1 ) ;
return V_5 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
int V_5 ;
if ( V_2 -> V_6 . V_7 <= 8 ) {
V_5 = F_8 ( V_2 -> V_8 , V_3 ) ;
* V_4 = V_5 ;
}
else if ( V_2 -> V_6 . V_7 == 24 ) {
* V_4 = 0 ;
V_5 = F_9 ( V_2 -> V_8 ,
( V_3 << 2 ) | V_9 ,
3 ,
( V_10 * ) V_4 ) ;
F_10 ( V_4 ) ;
} else {
V_5 = F_11 ( V_2 -> V_8 , V_3 << 1 ) ;
* V_4 = V_5 ;
}
if ( V_5 < 0 ) {
F_6 ( & V_2 -> V_8 -> V_14 , L_2 ) ;
return V_5 ;
}
return 0 ;
}
static int F_12 ( struct V_6 * V_15 , unsigned V_16 )
{
struct V_1 * V_2 ;
T_2 V_17 ;
int V_5 , V_18 = 0 ;
V_2 = F_13 ( V_15 , struct V_1 , V_6 ) ;
F_14 ( & V_2 -> V_19 ) ;
V_17 = V_2 -> V_20 | ( 1u << V_16 ) ;
switch ( V_2 -> V_11 ) {
case V_12 :
V_18 = V_21 ;
break;
case V_13 :
V_18 = V_22 ;
break;
}
V_5 = F_1 ( V_2 , V_18 , V_17 ) ;
if ( V_5 )
goto exit;
V_2 -> V_20 = V_17 ;
V_5 = 0 ;
exit:
F_15 ( & V_2 -> V_19 ) ;
return V_5 ;
}
static int F_16 ( struct V_6 * V_15 ,
unsigned V_16 , int V_4 )
{
struct V_1 * V_2 ;
T_2 V_17 ;
int V_5 , V_18 = 0 ;
V_2 = F_13 ( V_15 , struct V_1 , V_6 ) ;
F_14 ( & V_2 -> V_19 ) ;
if ( V_4 )
V_17 = V_2 -> V_23 | ( 1u << V_16 ) ;
else
V_17 = V_2 -> V_23 & ~ ( 1u << V_16 ) ;
switch ( V_2 -> V_11 ) {
case V_12 :
V_18 = V_24 ;
break;
case V_13 :
V_18 = V_25 ;
break;
}
V_5 = F_1 ( V_2 , V_18 , V_17 ) ;
if ( V_5 )
goto exit;
V_2 -> V_23 = V_17 ;
V_17 = V_2 -> V_20 & ~ ( 1u << V_16 ) ;
switch ( V_2 -> V_11 ) {
case V_12 :
V_18 = V_21 ;
break;
case V_13 :
V_18 = V_22 ;
break;
}
V_5 = F_1 ( V_2 , V_18 , V_17 ) ;
if ( V_5 )
goto exit;
V_2 -> V_20 = V_17 ;
V_5 = 0 ;
exit:
F_15 ( & V_2 -> V_19 ) ;
return V_5 ;
}
static int F_17 ( struct V_6 * V_15 , unsigned V_16 )
{
struct V_1 * V_2 ;
T_1 V_17 ;
int V_5 , V_18 = 0 ;
V_2 = F_13 ( V_15 , struct V_1 , V_6 ) ;
F_14 ( & V_2 -> V_19 ) ;
switch ( V_2 -> V_11 ) {
case V_12 :
V_18 = V_26 ;
break;
case V_13 :
V_18 = V_27 ;
break;
}
V_5 = F_7 ( V_2 , V_18 , & V_17 ) ;
F_15 ( & V_2 -> V_19 ) ;
if ( V_5 < 0 ) {
return 0 ;
}
return ( V_17 & ( 1u << V_16 ) ) ? 1 : 0 ;
}
static void F_18 ( struct V_6 * V_15 , unsigned V_16 , int V_4 )
{
struct V_1 * V_2 ;
T_1 V_17 ;
int V_5 , V_18 = 0 ;
V_2 = F_13 ( V_15 , struct V_1 , V_6 ) ;
F_14 ( & V_2 -> V_19 ) ;
if ( V_4 )
V_17 = V_2 -> V_23 | ( 1u << V_16 ) ;
else
V_17 = V_2 -> V_23 & ~ ( 1u << V_16 ) ;
switch ( V_2 -> V_11 ) {
case V_12 :
V_18 = V_24 ;
break;
case V_13 :
V_18 = V_25 ;
break;
}
V_5 = F_1 ( V_2 , V_18 , V_17 ) ;
if ( V_5 )
goto exit;
V_2 -> V_23 = V_17 ;
exit:
F_15 ( & V_2 -> V_19 ) ;
}
static void F_19 ( struct V_1 * V_2 , int V_28 )
{
struct V_6 * V_15 ;
V_15 = & V_2 -> V_6 ;
V_15 -> V_29 = F_12 ;
V_15 -> V_30 = F_16 ;
V_15 -> V_31 = F_17 ;
V_15 -> V_32 = F_18 ;
V_15 -> V_33 = 1 ;
V_15 -> V_34 = V_2 -> V_35 ;
V_15 -> V_7 = V_28 ;
V_15 -> V_36 = V_2 -> V_8 -> V_37 ;
V_15 -> V_14 = & V_2 -> V_8 -> V_14 ;
V_15 -> V_38 = V_39 ;
V_15 -> V_40 = V_2 -> V_40 ;
}
static int F_20 ( struct V_6 * V_15 , unsigned V_16 )
{
struct V_1 * V_2 ;
V_2 = F_13 ( V_15 , struct V_1 , V_6 ) ;
return V_2 -> V_41 + V_16 ;
}
static void F_21 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_22 ( V_43 ) ;
V_2 -> V_44 &= ~ ( 1 << ( V_43 -> V_45 - V_2 -> V_41 ) ) ;
}
static void F_23 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_22 ( V_43 ) ;
V_2 -> V_44 |= 1 << ( V_43 -> V_45 - V_2 -> V_41 ) ;
}
static void F_24 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_22 ( V_43 ) ;
F_14 ( & V_2 -> V_46 ) ;
}
static void F_25 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_22 ( V_43 ) ;
T_1 V_47 ;
T_1 V_48 ;
V_47 = V_2 -> V_49 | V_2 -> V_50 ;
V_47 &= ~ V_2 -> V_20 ;
while ( V_47 ) {
V_48 = F_26 ( V_47 ) ;
F_12 ( & V_2 -> V_6 , V_48 ) ;
V_47 &= ~ ( 1 << V_48 ) ;
}
F_15 ( & V_2 -> V_46 ) ;
}
static int F_27 ( struct V_42 * V_43 , unsigned int type )
{
struct V_1 * V_2 = F_22 ( V_43 ) ;
T_1 V_48 = V_43 -> V_45 - V_2 -> V_41 ;
T_1 V_51 = 1 << V_48 ;
if ( ! ( type & V_52 ) ) {
F_6 ( & V_2 -> V_8 -> V_14 , L_3 ,
V_43 -> V_45 , type ) ;
return - V_53 ;
}
if ( type & V_54 )
V_2 -> V_49 |= V_51 ;
else
V_2 -> V_49 &= ~ V_51 ;
if ( type & V_55 )
V_2 -> V_50 |= V_51 ;
else
V_2 -> V_50 &= ~ V_51 ;
return 0 ;
}
static T_1 F_28 ( struct V_1 * V_2 )
{
T_1 V_56 ;
T_1 V_57 ;
T_1 V_58 ;
T_1 V_59 ;
int V_5 , V_18 = 0 ;
switch ( V_2 -> V_11 ) {
case V_12 :
V_18 = V_26 ;
break;
case V_13 :
V_18 = V_27 ;
break;
}
V_5 = F_7 ( V_2 , V_18 , & V_56 ) ;
if ( V_5 )
return 0 ;
V_56 &= V_2 -> V_20 ;
V_57 = V_2 -> V_60 ;
V_59 = ( V_56 ^ V_57 ) & V_2 -> V_44 ;
if ( ! V_59 )
return 0 ;
V_2 -> V_60 = V_56 ;
V_58 = ( V_57 & V_2 -> V_49 ) |
( V_56 & V_2 -> V_50 ) ;
V_58 &= V_59 ;
return V_58 ;
}
static T_3 F_29 ( int V_45 , void * V_61 )
{
struct V_1 * V_2 = V_61 ;
T_1 V_58 ;
T_1 V_48 ;
V_58 = F_28 ( V_2 ) ;
if ( ! V_58 )
return V_62 ;
do {
V_48 = F_26 ( V_58 ) ;
F_30 ( V_48 + V_2 -> V_41 ) ;
V_58 &= ~ ( 1 << V_48 ) ;
} while ( V_58 );
return V_62 ;
}
static int F_31 ( struct V_1 * V_2 ,
const struct V_63 * V_64 ,
int V_41 )
{
struct V_65 * V_8 = V_2 -> V_8 ;
int V_5 , V_18 = 0 ;
T_1 V_66 ;
if ( V_41 != - 1
&& ( V_64 -> V_67 & V_68 ) ) {
int V_69 ;
switch ( V_2 -> V_11 ) {
case V_12 :
V_18 = V_26 ;
break;
case V_13 :
V_18 = V_27 ;
break;
}
V_5 = F_7 ( V_2 , V_18 , & V_66 ) ;
V_2 -> V_60 = V_66 ;
if ( V_5 )
goto V_70;
V_2 -> V_60 &= V_2 -> V_20 ;
F_32 ( & V_2 -> V_46 ) ;
V_2 -> V_41 = F_33 ( - 1 , V_41 , V_2 -> V_6 . V_7 , - 1 ) ;
if ( V_2 -> V_41 < 0 )
goto V_70;
for ( V_69 = 0 ; V_69 < V_2 -> V_6 . V_7 ; V_69 ++ ) {
int V_45 = V_69 + V_2 -> V_41 ;
F_34 ( V_45 , V_71 ) ;
F_35 ( V_45 , V_2 ) ;
F_36 ( V_45 , & V_72 ) ;
F_37 ( V_45 , true ) ;
#ifdef F_38
F_39 ( V_45 , V_73 ) ;
#else
F_40 ( V_45 ) ;
#endif
}
V_5 = F_41 ( V_8 -> V_45 ,
NULL ,
F_29 ,
V_74 | V_75 ,
F_42 ( & V_8 -> V_14 ) , V_2 ) ;
if ( V_5 ) {
F_6 ( & V_8 -> V_14 , L_4 ,
V_8 -> V_45 ) ;
goto V_70;
}
V_2 -> V_6 . V_76 = F_20 ;
}
return 0 ;
V_70:
V_2 -> V_41 = - 1 ;
return V_5 ;
}
static void F_43 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 != - 1 ) {
F_44 ( V_2 -> V_41 , V_2 -> V_6 . V_7 ) ;
F_45 ( V_2 -> V_8 -> V_45 , V_2 ) ;
}
}
static int F_31 ( struct V_1 * V_2 ,
const struct V_63 * V_64 ,
int V_41 )
{
struct V_65 * V_8 = V_2 -> V_8 ;
if ( V_41 != - 1 && ( V_64 -> V_67 & V_68 ) )
F_46 ( & V_8 -> V_14 , L_5 ) ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 )
{
}
static void
F_47 ( struct V_65 * V_8 , int * V_77 , T_1 * V_78 )
{
struct V_79 * V_80 ;
const T_4 * V_4 ;
int V_81 ;
V_80 = V_8 -> V_14 . V_82 ;
if ( V_80 == NULL )
return;
* V_77 = - 1 ;
V_4 = F_48 ( V_80 , L_6 , & V_81 ) ;
F_49 ( V_4 , L_7 , V_83 ) ;
if ( V_4 ) {
if ( V_81 != sizeof( * V_4 ) )
F_46 ( & V_8 -> V_14 , L_8 ,
V_80 -> V_84 ) ;
else
* V_77 = F_50 ( V_4 ) ;
}
V_4 = F_48 ( V_80 , L_9 , NULL ) ;
F_49 ( V_4 , L_10 , V_83 ) ;
if ( V_4 )
* V_78 = * V_4 ;
}
static void
F_47 ( struct V_65 * V_8 , int * V_77 , T_1 * V_78 )
{
* V_77 = - 1 ;
}
static int T_5 F_51 ( struct V_1 * V_2 , T_1 V_78 )
{
int V_5 ;
V_5 = F_7 ( V_2 , V_24 , & V_2 -> V_23 ) ;
if ( V_5 )
goto V_85;
V_5 = F_7 ( V_2 , V_21 ,
& V_2 -> V_20 ) ;
if ( V_5 )
goto V_85;
V_5 = F_1 ( V_2 , V_86 , V_78 ) ;
V_85:
return V_5 ;
}
static int T_5 F_52 ( struct V_1 * V_2 , T_1 V_78 )
{
int V_5 ;
T_1 V_4 = 0 ;
F_1 ( V_2 , V_87 , 0x0 ) ;
F_1 ( V_2 , V_22 , 0xffff ) ;
F_1 ( V_2 , V_25 , 0x0 ) ;
V_5 = F_7 ( V_2 , V_27 , & V_4 ) ;
if ( V_5 )
goto V_85;
V_5 = F_7 ( V_2 , V_25 , & V_2 -> V_23 ) ;
if ( V_5 )
goto V_85;
V_5 = F_7 ( V_2 , V_22 , & V_2 -> V_20 ) ;
if ( V_5 )
goto V_85;
F_1 ( V_2 , V_88 , V_78 ) ;
F_1 ( V_2 , V_89 , 0x202 ) ;
return 0 ;
V_85:
return V_5 ;
}
static int T_5 F_53 ( struct V_65 * V_8 ,
const struct V_63 * V_64 )
{
struct V_90 * V_91 ;
struct V_1 * V_2 ;
int V_41 = 0 ;
int V_5 ;
T_1 V_78 = 0 ;
V_2 = F_54 ( sizeof( struct V_1 ) , V_92 ) ;
if ( V_2 == NULL )
return - V_93 ;
V_91 = V_8 -> V_14 . V_94 ;
if ( V_91 ) {
V_41 = V_91 -> V_41 ;
V_2 -> V_35 = V_91 -> V_77 ;
V_78 = V_91 -> V_78 ;
V_2 -> V_40 = V_91 -> V_40 ;
} else {
F_47 ( V_8 , & V_2 -> V_35 , & V_78 ) ;
#ifdef F_55
if ( F_56 ( V_8 -> V_14 . V_82 , L_11 , NULL ) == NULL )
V_41 = - 1 ;
#endif
}
V_2 -> V_8 = V_8 ;
V_2 -> V_11 = V_64 -> V_67 & ( V_12 | V_13 ) ;
F_32 ( & V_2 -> V_19 ) ;
F_19 ( V_2 , V_64 -> V_67 & V_95 ) ;
if ( V_2 -> V_11 == V_12 )
V_5 = F_51 ( V_2 , V_78 ) ;
else
V_5 = F_52 ( V_2 , V_78 ) ;
if ( V_5 )
goto V_70;
V_5 = F_31 ( V_2 , V_64 , V_41 ) ;
if ( V_5 )
goto V_70;
V_5 = F_57 ( & V_2 -> V_6 ) ;
if ( V_5 )
goto V_96;
if ( V_91 && V_91 -> V_97 ) {
V_5 = V_91 -> V_97 ( V_8 , V_2 -> V_6 . V_34 ,
V_2 -> V_6 . V_7 , V_91 -> V_98 ) ;
if ( V_5 < 0 )
F_46 ( & V_8 -> V_14 , L_12 , V_5 ) ;
}
F_58 ( V_8 , V_2 ) ;
return 0 ;
V_96:
F_43 ( V_2 ) ;
V_70:
F_59 ( V_2 ) ;
return V_5 ;
}
static int F_60 ( struct V_65 * V_8 )
{
struct V_90 * V_91 = V_8 -> V_14 . V_94 ;
struct V_1 * V_2 = F_61 ( V_8 ) ;
int V_5 = 0 ;
if ( V_91 && V_91 -> V_99 ) {
V_5 = V_91 -> V_99 ( V_8 , V_2 -> V_6 . V_34 ,
V_2 -> V_6 . V_7 , V_91 -> V_98 ) ;
if ( V_5 < 0 ) {
F_6 ( & V_8 -> V_14 , L_13 ,
L_14 , V_5 ) ;
return V_5 ;
}
}
V_5 = F_62 ( & V_2 -> V_6 ) ;
if ( V_5 ) {
F_6 ( & V_8 -> V_14 , L_13 ,
L_15 , V_5 ) ;
return V_5 ;
}
F_43 ( V_2 ) ;
F_59 ( V_2 ) ;
return 0 ;
}
static int T_6 F_63 ( void )
{
return F_64 ( & V_100 ) ;
}
static void T_7 F_65 ( void )
{
F_66 ( & V_100 ) ;
}
