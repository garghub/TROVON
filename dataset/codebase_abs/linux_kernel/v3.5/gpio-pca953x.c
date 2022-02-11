static int F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
int V_5 = 0 ;
if ( V_2 -> V_6 . V_7 <= 8 )
V_5 = F_2 ( V_2 -> V_8 , V_3 , V_4 ) ;
else if ( V_2 -> V_6 . V_7 == 24 ) {
V_5 = F_3 ( V_2 -> V_8 ,
( V_3 << 2 ) | V_9 ,
V_4 & 0xffff ) ;
V_5 = F_2 ( V_2 -> V_8 ,
( V_3 << 2 ) + 2 ,
( V_4 & 0xff0000 ) >> 16 ) ;
}
else {
switch ( V_2 -> V_10 ) {
case V_11 :
V_5 = F_3 ( V_2 -> V_8 ,
V_3 << 1 , V_4 ) ;
break;
case V_12 :
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
F_4 ( & V_2 -> V_8 -> V_13 , L_1 ) ;
return V_5 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
int V_5 ;
if ( V_2 -> V_6 . V_7 <= 8 )
V_5 = F_6 ( V_2 -> V_8 , V_3 ) ;
else if ( V_2 -> V_6 . V_7 == 24 ) {
V_5 = F_7 ( V_2 -> V_8 , V_3 << 2 ) ;
V_5 |= ( F_6 ( V_2 -> V_8 ,
( V_3 << 2 ) + 2 ) << 16 ) ;
}
else
V_5 = F_7 ( V_2 -> V_8 , V_3 << 1 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_8 -> V_13 , L_2 ) ;
return V_5 ;
}
* V_4 = ( T_1 ) V_5 ;
return 0 ;
}
static int F_8 ( struct V_6 * V_14 , unsigned V_15 )
{
struct V_1 * V_2 ;
T_2 V_16 ;
int V_5 , V_17 = 0 ;
V_2 = F_9 ( V_14 , struct V_1 , V_6 ) ;
F_10 ( & V_2 -> V_18 ) ;
V_16 = V_2 -> V_19 | ( 1u << V_15 ) ;
switch ( V_2 -> V_10 ) {
case V_11 :
V_17 = V_20 ;
break;
case V_12 :
V_17 = V_21 ;
break;
}
V_5 = F_1 ( V_2 , V_17 , V_16 ) ;
if ( V_5 )
goto exit;
V_2 -> V_19 = V_16 ;
V_5 = 0 ;
exit:
F_11 ( & V_2 -> V_18 ) ;
return V_5 ;
}
static int F_12 ( struct V_6 * V_14 ,
unsigned V_15 , int V_4 )
{
struct V_1 * V_2 ;
T_2 V_16 ;
int V_5 , V_17 = 0 ;
V_2 = F_9 ( V_14 , struct V_1 , V_6 ) ;
F_10 ( & V_2 -> V_18 ) ;
if ( V_4 )
V_16 = V_2 -> V_22 | ( 1u << V_15 ) ;
else
V_16 = V_2 -> V_22 & ~ ( 1u << V_15 ) ;
switch ( V_2 -> V_10 ) {
case V_11 :
V_17 = V_23 ;
break;
case V_12 :
V_17 = V_24 ;
break;
}
V_5 = F_1 ( V_2 , V_17 , V_16 ) ;
if ( V_5 )
goto exit;
V_2 -> V_22 = V_16 ;
V_16 = V_2 -> V_19 & ~ ( 1u << V_15 ) ;
switch ( V_2 -> V_10 ) {
case V_11 :
V_17 = V_20 ;
break;
case V_12 :
V_17 = V_21 ;
break;
}
V_5 = F_1 ( V_2 , V_17 , V_16 ) ;
if ( V_5 )
goto exit;
V_2 -> V_19 = V_16 ;
V_5 = 0 ;
exit:
F_11 ( & V_2 -> V_18 ) ;
return V_5 ;
}
static int F_13 ( struct V_6 * V_14 , unsigned V_15 )
{
struct V_1 * V_2 ;
T_1 V_16 ;
int V_5 , V_17 = 0 ;
V_2 = F_9 ( V_14 , struct V_1 , V_6 ) ;
F_10 ( & V_2 -> V_18 ) ;
switch ( V_2 -> V_10 ) {
case V_11 :
V_17 = V_25 ;
break;
case V_12 :
V_17 = V_26 ;
break;
}
V_5 = F_5 ( V_2 , V_17 , & V_16 ) ;
F_11 ( & V_2 -> V_18 ) ;
if ( V_5 < 0 ) {
return 0 ;
}
return ( V_16 & ( 1u << V_15 ) ) ? 1 : 0 ;
}
static void F_14 ( struct V_6 * V_14 , unsigned V_15 , int V_4 )
{
struct V_1 * V_2 ;
T_1 V_16 ;
int V_5 , V_17 = 0 ;
V_2 = F_9 ( V_14 , struct V_1 , V_6 ) ;
F_10 ( & V_2 -> V_18 ) ;
if ( V_4 )
V_16 = V_2 -> V_22 | ( 1u << V_15 ) ;
else
V_16 = V_2 -> V_22 & ~ ( 1u << V_15 ) ;
switch ( V_2 -> V_10 ) {
case V_11 :
V_17 = V_23 ;
break;
case V_12 :
V_17 = V_24 ;
break;
}
V_5 = F_1 ( V_2 , V_17 , V_16 ) ;
if ( V_5 )
goto exit;
V_2 -> V_22 = V_16 ;
exit:
F_11 ( & V_2 -> V_18 ) ;
}
static void F_15 ( struct V_1 * V_2 , int V_27 )
{
struct V_6 * V_14 ;
V_14 = & V_2 -> V_6 ;
V_14 -> V_28 = F_8 ;
V_14 -> V_29 = F_12 ;
V_14 -> V_30 = F_13 ;
V_14 -> V_31 = F_14 ;
V_14 -> V_32 = 1 ;
V_14 -> V_33 = V_2 -> V_34 ;
V_14 -> V_7 = V_27 ;
V_14 -> V_35 = V_2 -> V_8 -> V_36 ;
V_14 -> V_13 = & V_2 -> V_8 -> V_13 ;
V_14 -> V_37 = V_38 ;
V_14 -> V_39 = V_2 -> V_39 ;
}
static int F_16 ( struct V_6 * V_14 , unsigned V_15 )
{
struct V_1 * V_2 ;
V_2 = F_9 ( V_14 , struct V_1 , V_6 ) ;
return V_2 -> V_40 + V_15 ;
}
static void F_17 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_18 ( V_42 ) ;
V_2 -> V_43 &= ~ ( 1 << ( V_42 -> V_44 - V_2 -> V_40 ) ) ;
}
static void F_19 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_18 ( V_42 ) ;
V_2 -> V_43 |= 1 << ( V_42 -> V_44 - V_2 -> V_40 ) ;
}
static void F_20 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_18 ( V_42 ) ;
F_10 ( & V_2 -> V_45 ) ;
}
static void F_21 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_18 ( V_42 ) ;
T_3 V_46 ;
T_3 V_47 ;
V_46 = V_2 -> V_48 | V_2 -> V_49 ;
V_46 &= ~ V_2 -> V_19 ;
while ( V_46 ) {
V_47 = F_22 ( V_46 ) ;
F_8 ( & V_2 -> V_6 , V_47 ) ;
V_46 &= ~ ( 1 << V_47 ) ;
}
F_11 ( & V_2 -> V_45 ) ;
}
static int F_23 ( struct V_41 * V_42 , unsigned int type )
{
struct V_1 * V_2 = F_18 ( V_42 ) ;
T_3 V_47 = V_42 -> V_44 - V_2 -> V_40 ;
T_3 V_50 = 1 << V_47 ;
if ( ! ( type & V_51 ) ) {
F_4 ( & V_2 -> V_8 -> V_13 , L_3 ,
V_42 -> V_44 , type ) ;
return - V_52 ;
}
if ( type & V_53 )
V_2 -> V_48 |= V_50 ;
else
V_2 -> V_48 &= ~ V_50 ;
if ( type & V_54 )
V_2 -> V_49 |= V_50 ;
else
V_2 -> V_49 &= ~ V_50 ;
return 0 ;
}
static T_3 F_24 ( struct V_1 * V_2 )
{
T_1 V_55 ;
T_3 V_56 ;
T_3 V_57 ;
T_3 V_58 ;
int V_5 , V_17 = 0 ;
switch ( V_2 -> V_10 ) {
case V_11 :
V_17 = V_25 ;
break;
case V_12 :
V_17 = V_26 ;
break;
}
V_5 = F_5 ( V_2 , V_17 , & V_55 ) ;
if ( V_5 )
return 0 ;
V_55 &= V_2 -> V_19 ;
V_56 = V_2 -> V_59 ;
V_58 = ( V_55 ^ V_56 ) & V_2 -> V_43 ;
if ( ! V_58 )
return 0 ;
V_2 -> V_59 = V_55 ;
V_57 = ( V_56 & V_2 -> V_48 ) |
( V_55 & V_2 -> V_49 ) ;
V_57 &= V_58 ;
return V_57 ;
}
static T_4 F_25 ( int V_44 , void * V_60 )
{
struct V_1 * V_2 = V_60 ;
T_3 V_57 ;
T_3 V_47 ;
V_57 = F_24 ( V_2 ) ;
if ( ! V_57 )
return V_61 ;
do {
V_47 = F_22 ( V_57 ) ;
F_26 ( V_47 + V_2 -> V_40 ) ;
V_57 &= ~ ( 1 << V_47 ) ;
} while ( V_57 );
return V_61 ;
}
static int F_27 ( struct V_1 * V_2 ,
const struct V_62 * V_63 ,
int V_40 )
{
struct V_64 * V_8 = V_2 -> V_8 ;
int V_5 , V_17 = 0 ;
T_1 V_65 ;
if ( V_40 != - 1
&& ( V_63 -> V_66 & V_67 ) ) {
int V_68 ;
switch ( V_2 -> V_10 ) {
case V_11 :
V_17 = V_25 ;
break;
case V_12 :
V_17 = V_26 ;
break;
}
V_5 = F_5 ( V_2 , V_17 , & V_65 ) ;
V_2 -> V_59 = V_65 ;
if ( V_5 )
goto V_69;
V_2 -> V_59 &= V_2 -> V_19 ;
F_28 ( & V_2 -> V_45 ) ;
V_2 -> V_40 = F_29 ( - 1 , V_40 , V_2 -> V_6 . V_7 , - 1 ) ;
if ( V_2 -> V_40 < 0 )
goto V_69;
for ( V_68 = 0 ; V_68 < V_2 -> V_6 . V_7 ; V_68 ++ ) {
int V_44 = V_68 + V_2 -> V_40 ;
F_30 ( V_44 , V_70 ) ;
F_31 ( V_44 , V_2 ) ;
F_32 ( V_44 , & V_71 ) ;
F_33 ( V_44 , true ) ;
#ifdef F_34
F_35 ( V_44 , V_72 ) ;
#else
F_36 ( V_44 ) ;
#endif
}
V_5 = F_37 ( V_8 -> V_44 ,
NULL ,
F_25 ,
V_73 | V_74 ,
F_38 ( & V_8 -> V_13 ) , V_2 ) ;
if ( V_5 ) {
F_4 ( & V_8 -> V_13 , L_4 ,
V_8 -> V_44 ) ;
goto V_69;
}
V_2 -> V_6 . V_75 = F_16 ;
}
return 0 ;
V_69:
V_2 -> V_40 = - 1 ;
return V_5 ;
}
static void F_39 ( struct V_1 * V_2 )
{
if ( V_2 -> V_40 != - 1 ) {
F_40 ( V_2 -> V_40 , V_2 -> V_6 . V_7 ) ;
F_41 ( V_2 -> V_8 -> V_44 , V_2 ) ;
}
}
static int F_27 ( struct V_1 * V_2 ,
const struct V_62 * V_63 ,
int V_40 )
{
struct V_64 * V_8 = V_2 -> V_8 ;
if ( V_40 != - 1 && ( V_63 -> V_66 & V_67 ) )
F_42 ( & V_8 -> V_13 , L_5 ) ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 )
{
}
static void
F_43 ( struct V_64 * V_8 , int * V_76 , int * V_77 )
{
struct V_78 * V_79 ;
const T_5 * V_4 ;
int V_80 ;
V_79 = V_8 -> V_13 . V_81 ;
if ( V_79 == NULL )
return;
* V_76 = - 1 ;
V_4 = F_44 ( V_79 , L_6 , & V_80 ) ;
F_45 ( V_4 , L_7 , V_82 ) ;
if ( V_4 ) {
if ( V_80 != sizeof( * V_4 ) )
F_42 ( & V_8 -> V_13 , L_8 ,
V_79 -> V_83 ) ;
else
* V_76 = F_46 ( V_4 ) ;
}
V_4 = F_44 ( V_79 , L_9 , NULL ) ;
F_45 ( V_4 , L_10 , V_82 ) ;
if ( V_4 )
* V_77 = * V_4 ;
}
static void
F_43 ( struct V_64 * V_8 , int * V_76 , int * V_77 )
{
* V_76 = - 1 ;
}
static int T_6 F_47 ( struct V_1 * V_2 , int V_77 )
{
int V_5 ;
V_5 = F_5 ( V_2 , V_23 , & V_2 -> V_22 ) ;
if ( V_5 )
goto V_84;
V_5 = F_5 ( V_2 , V_20 ,
& V_2 -> V_19 ) ;
if ( V_5 )
goto V_84;
V_5 = F_1 ( V_2 , V_85 , V_77 ) ;
V_84:
return V_5 ;
}
static int T_6 F_48 ( struct V_1 * V_2 , int V_77 )
{
int V_5 ;
T_1 V_4 = 0 ;
F_1 ( V_2 , V_86 , 0x0 ) ;
F_1 ( V_2 , V_21 , 0xffff ) ;
F_1 ( V_2 , V_24 , 0x0 ) ;
V_5 = F_5 ( V_2 , V_26 , & V_4 ) ;
if ( V_5 )
goto V_84;
V_5 = F_5 ( V_2 , V_24 , & V_2 -> V_22 ) ;
if ( V_5 )
goto V_84;
V_5 = F_5 ( V_2 , V_21 , & V_2 -> V_19 ) ;
if ( V_5 )
goto V_84;
F_1 ( V_2 , V_87 , V_77 ) ;
F_1 ( V_2 , V_88 , 0x202 ) ;
return 0 ;
V_84:
return V_5 ;
}
static int T_6 F_49 ( struct V_64 * V_8 ,
const struct V_62 * V_63 )
{
struct V_89 * V_90 ;
struct V_1 * V_2 ;
int V_40 = 0 , V_77 = 0 ;
int V_5 ;
V_2 = F_50 ( sizeof( struct V_1 ) , V_91 ) ;
if ( V_2 == NULL )
return - V_92 ;
V_90 = V_8 -> V_13 . V_93 ;
if ( V_90 ) {
V_40 = V_90 -> V_40 ;
V_2 -> V_34 = V_90 -> V_76 ;
V_77 = V_90 -> V_77 ;
V_2 -> V_39 = V_90 -> V_39 ;
} else {
F_43 ( V_8 , & V_2 -> V_34 , & V_77 ) ;
#ifdef F_51
if ( F_52 ( V_8 -> V_13 . V_81 , L_11 , NULL ) == NULL )
V_40 = - 1 ;
#endif
}
V_2 -> V_8 = V_8 ;
V_2 -> V_10 = V_63 -> V_66 & ( V_11 | V_12 ) ;
F_28 ( & V_2 -> V_18 ) ;
F_15 ( V_2 , V_63 -> V_66 & V_94 ) ;
if ( V_2 -> V_10 == V_11 )
V_5 = F_47 ( V_2 , V_77 ) ;
else
V_5 = F_48 ( V_2 , V_77 ) ;
if ( V_5 )
goto V_69;
V_5 = F_27 ( V_2 , V_63 , V_40 ) ;
if ( V_5 )
goto V_69;
V_5 = F_53 ( & V_2 -> V_6 ) ;
if ( V_5 )
goto V_95;
if ( V_90 && V_90 -> V_96 ) {
V_5 = V_90 -> V_96 ( V_8 , V_2 -> V_6 . V_33 ,
V_2 -> V_6 . V_7 , V_90 -> V_97 ) ;
if ( V_5 < 0 )
F_42 ( & V_8 -> V_13 , L_12 , V_5 ) ;
}
F_54 ( V_8 , V_2 ) ;
return 0 ;
V_95:
F_39 ( V_2 ) ;
V_69:
F_55 ( V_2 ) ;
return V_5 ;
}
static int F_56 ( struct V_64 * V_8 )
{
struct V_89 * V_90 = V_8 -> V_13 . V_93 ;
struct V_1 * V_2 = F_57 ( V_8 ) ;
int V_5 = 0 ;
if ( V_90 && V_90 -> V_98 ) {
V_5 = V_90 -> V_98 ( V_8 , V_2 -> V_6 . V_33 ,
V_2 -> V_6 . V_7 , V_90 -> V_97 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_8 -> V_13 , L_13 ,
L_14 , V_5 ) ;
return V_5 ;
}
}
V_5 = F_58 ( & V_2 -> V_6 ) ;
if ( V_5 ) {
F_4 ( & V_8 -> V_13 , L_13 ,
L_15 , V_5 ) ;
return V_5 ;
}
F_39 ( V_2 ) ;
F_55 ( V_2 ) ;
return 0 ;
}
static int T_7 F_59 ( void )
{
return F_60 ( & V_99 ) ;
}
static void T_8 F_61 ( void )
{
F_62 ( & V_99 ) ;
}
