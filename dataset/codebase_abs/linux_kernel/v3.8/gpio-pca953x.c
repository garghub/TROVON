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
V_2 -> V_44 &= ~ ( 1 << V_43 -> V_45 ) ;
}
static void F_23 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_22 ( V_43 ) ;
V_2 -> V_44 |= 1 << V_43 -> V_45 ;
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
T_1 V_51 = 1 << V_43 -> V_45 ;
if ( ! ( type & V_52 ) ) {
F_6 ( & V_2 -> V_8 -> V_14 , L_3 ,
V_43 -> V_53 , type ) ;
return - V_54 ;
}
if ( type & V_55 )
V_2 -> V_49 |= V_51 ;
else
V_2 -> V_49 &= ~ V_51 ;
if ( type & V_56 )
V_2 -> V_50 |= V_51 ;
else
V_2 -> V_50 &= ~ V_51 ;
return 0 ;
}
static T_1 F_28 ( struct V_1 * V_2 )
{
T_1 V_57 ;
T_1 V_58 ;
T_1 V_59 ;
T_1 V_60 ;
int V_5 , V_18 = 0 ;
switch ( V_2 -> V_11 ) {
case V_12 :
V_18 = V_26 ;
break;
case V_13 :
V_18 = V_27 ;
break;
}
V_5 = F_7 ( V_2 , V_18 , & V_57 ) ;
if ( V_5 )
return 0 ;
V_57 &= V_2 -> V_20 ;
V_58 = V_2 -> V_61 ;
V_60 = ( V_57 ^ V_58 ) & V_2 -> V_44 ;
if ( ! V_60 )
return 0 ;
V_2 -> V_61 = V_57 ;
V_59 = ( V_58 & V_2 -> V_49 ) |
( V_57 & V_2 -> V_50 ) ;
V_59 &= V_60 ;
return V_59 ;
}
static T_3 F_29 ( int V_53 , void * V_62 )
{
struct V_1 * V_2 = V_62 ;
T_1 V_59 ;
T_1 V_48 ;
V_59 = F_28 ( V_2 ) ;
if ( ! V_59 )
return V_63 ;
do {
V_48 = F_26 ( V_59 ) ;
F_30 ( F_31 ( V_2 -> V_64 , V_48 ) ) ;
V_59 &= ~ ( 1 << V_48 ) ;
} while ( V_59 );
return V_63 ;
}
static int F_32 ( struct V_1 * V_2 ,
const struct V_65 * V_66 ,
int V_41 )
{
struct V_67 * V_8 = V_2 -> V_8 ;
int V_5 , V_18 = 0 ;
T_1 V_68 ;
if ( V_41 != - 1
&& ( V_66 -> V_69 & V_70 ) ) {
int V_71 ;
switch ( V_2 -> V_11 ) {
case V_12 :
V_18 = V_26 ;
break;
case V_13 :
V_18 = V_27 ;
break;
}
V_5 = F_7 ( V_2 , V_18 , & V_68 ) ;
V_2 -> V_61 = V_68 ;
if ( V_5 )
goto V_72;
V_2 -> V_61 &= V_2 -> V_20 ;
F_33 ( & V_2 -> V_46 ) ;
V_2 -> V_41 = F_34 ( - 1 , V_41 , V_2 -> V_6 . V_7 , - 1 ) ;
if ( V_2 -> V_41 < 0 )
goto V_72;
V_2 -> V_64 = F_35 ( V_8 -> V_14 . V_73 ,
V_2 -> V_6 . V_7 ,
V_2 -> V_41 ,
0 ,
& V_74 ,
NULL ) ;
if ( ! V_2 -> V_64 ) {
V_5 = - V_75 ;
goto V_76;
}
for ( V_71 = 0 ; V_71 < V_2 -> V_6 . V_7 ; V_71 ++ ) {
int V_53 = V_71 + V_2 -> V_41 ;
F_36 ( V_53 , V_77 ) ;
F_37 ( V_53 , V_2 ) ;
F_38 ( V_53 , & V_78 ) ;
F_39 ( V_53 , true ) ;
#ifdef F_40
F_41 ( V_53 , V_79 ) ;
#else
F_42 ( V_53 ) ;
#endif
}
V_5 = F_43 ( V_8 -> V_53 ,
NULL ,
F_29 ,
V_80 | V_81 ,
F_44 ( & V_8 -> V_14 ) , V_2 ) ;
if ( V_5 ) {
F_6 ( & V_8 -> V_14 , L_4 ,
V_8 -> V_53 ) ;
goto V_76;
}
V_2 -> V_6 . V_82 = F_20 ;
}
return 0 ;
V_76:
F_45 ( V_2 -> V_41 , V_2 -> V_6 . V_7 ) ;
V_72:
V_2 -> V_41 = - 1 ;
return V_5 ;
}
static void F_46 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 != - 1 ) {
F_45 ( V_2 -> V_41 , V_2 -> V_6 . V_7 ) ;
F_47 ( V_2 -> V_8 -> V_53 , V_2 ) ;
}
}
static int F_32 ( struct V_1 * V_2 ,
const struct V_65 * V_66 ,
int V_41 )
{
struct V_67 * V_8 = V_2 -> V_8 ;
if ( V_41 != - 1 && ( V_66 -> V_69 & V_70 ) )
F_48 ( & V_8 -> V_14 , L_5 ) ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
}
static void
F_49 ( struct V_67 * V_8 , int * V_83 , T_1 * V_84 )
{
struct V_85 * V_86 ;
const T_4 * V_4 ;
int V_87 ;
V_86 = V_8 -> V_14 . V_73 ;
if ( V_86 == NULL )
return;
* V_83 = - 1 ;
V_4 = F_50 ( V_86 , L_6 , & V_87 ) ;
F_51 ( V_4 , L_7 , V_88 ) ;
if ( V_4 ) {
if ( V_87 != sizeof( * V_4 ) )
F_48 ( & V_8 -> V_14 , L_8 ,
V_86 -> V_89 ) ;
else
* V_83 = F_52 ( V_4 ) ;
}
V_4 = F_50 ( V_86 , L_9 , NULL ) ;
F_51 ( V_4 , L_10 , V_88 ) ;
if ( V_4 )
* V_84 = * V_4 ;
}
static void
F_49 ( struct V_67 * V_8 , int * V_83 , T_1 * V_84 )
{
* V_83 = - 1 ;
}
static int F_53 ( struct V_1 * V_2 , T_1 V_84 )
{
int V_5 ;
V_5 = F_7 ( V_2 , V_24 , & V_2 -> V_23 ) ;
if ( V_5 )
goto V_90;
V_5 = F_7 ( V_2 , V_21 ,
& V_2 -> V_20 ) ;
if ( V_5 )
goto V_90;
V_5 = F_1 ( V_2 , V_91 , V_84 ) ;
V_90:
return V_5 ;
}
static int F_54 ( struct V_1 * V_2 , T_1 V_84 )
{
int V_5 ;
T_1 V_4 = 0 ;
F_1 ( V_2 , V_92 , 0x0 ) ;
F_1 ( V_2 , V_22 , 0xffff ) ;
F_1 ( V_2 , V_25 , 0x0 ) ;
V_5 = F_7 ( V_2 , V_27 , & V_4 ) ;
if ( V_5 )
goto V_90;
V_5 = F_7 ( V_2 , V_25 , & V_2 -> V_23 ) ;
if ( V_5 )
goto V_90;
V_5 = F_7 ( V_2 , V_22 , & V_2 -> V_20 ) ;
if ( V_5 )
goto V_90;
F_1 ( V_2 , V_93 , V_84 ) ;
F_1 ( V_2 , V_94 , 0x202 ) ;
return 0 ;
V_90:
return V_5 ;
}
static int F_55 ( struct V_67 * V_8 ,
const struct V_65 * V_66 )
{
struct V_95 * V_96 ;
struct V_1 * V_2 ;
int V_41 = 0 ;
int V_5 ;
T_1 V_84 = 0 ;
V_2 = F_56 ( sizeof( struct V_1 ) , V_97 ) ;
if ( V_2 == NULL )
return - V_98 ;
V_96 = V_8 -> V_14 . V_99 ;
if ( V_96 ) {
V_41 = V_96 -> V_41 ;
V_2 -> V_35 = V_96 -> V_83 ;
V_84 = V_96 -> V_84 ;
V_2 -> V_40 = V_96 -> V_40 ;
} else {
F_49 ( V_8 , & V_2 -> V_35 , & V_84 ) ;
#ifdef F_57
if ( F_58 ( V_8 -> V_14 . V_73 , L_11 , NULL ) == NULL )
V_41 = - 1 ;
#endif
}
V_2 -> V_8 = V_8 ;
V_2 -> V_11 = V_66 -> V_69 & ( V_12 | V_13 ) ;
F_33 ( & V_2 -> V_19 ) ;
F_19 ( V_2 , V_66 -> V_69 & V_100 ) ;
if ( V_2 -> V_11 == V_12 )
V_5 = F_53 ( V_2 , V_84 ) ;
else
V_5 = F_54 ( V_2 , V_84 ) ;
if ( V_5 )
goto V_72;
V_5 = F_32 ( V_2 , V_66 , V_41 ) ;
if ( V_5 )
goto V_72;
V_5 = F_59 ( & V_2 -> V_6 ) ;
if ( V_5 )
goto V_101;
if ( V_96 && V_96 -> V_102 ) {
V_5 = V_96 -> V_102 ( V_8 , V_2 -> V_6 . V_34 ,
V_2 -> V_6 . V_7 , V_96 -> V_103 ) ;
if ( V_5 < 0 )
F_48 ( & V_8 -> V_14 , L_12 , V_5 ) ;
}
F_60 ( V_8 , V_2 ) ;
return 0 ;
V_101:
F_46 ( V_2 ) ;
V_72:
F_61 ( V_2 ) ;
return V_5 ;
}
static int F_62 ( struct V_67 * V_8 )
{
struct V_95 * V_96 = V_8 -> V_14 . V_99 ;
struct V_1 * V_2 = F_63 ( V_8 ) ;
int V_5 = 0 ;
if ( V_96 && V_96 -> V_104 ) {
V_5 = V_96 -> V_104 ( V_8 , V_2 -> V_6 . V_34 ,
V_2 -> V_6 . V_7 , V_96 -> V_103 ) ;
if ( V_5 < 0 ) {
F_6 ( & V_8 -> V_14 , L_13 ,
L_14 , V_5 ) ;
return V_5 ;
}
}
V_5 = F_64 ( & V_2 -> V_6 ) ;
if ( V_5 ) {
F_6 ( & V_8 -> V_14 , L_13 ,
L_15 , V_5 ) ;
return V_5 ;
}
F_46 ( V_2 ) ;
F_61 ( V_2 ) ;
return 0 ;
}
static int T_5 F_65 ( void )
{
return F_66 ( & V_105 ) ;
}
static void T_6 F_67 ( void )
{
F_68 ( & V_105 ) ;
}
