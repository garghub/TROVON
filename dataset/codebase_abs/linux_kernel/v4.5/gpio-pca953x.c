static int F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 ,
int V_5 )
{
int V_6 ;
int V_7 = F_2 ( ( V_2 -> V_8 . V_9 - 1 ) / V_10 ) ;
int V_11 = V_5 / V_10 ;
V_6 = F_3 ( V_2 -> V_12 ,
( V_3 << V_7 ) + V_11 ) ;
* V_4 = V_6 ;
if ( V_6 < 0 ) {
F_4 ( & V_2 -> V_12 -> V_13 , L_1 ) ;
return V_6 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 , T_1 V_4 ,
int V_5 )
{
int V_6 = 0 ;
int V_7 = F_2 ( ( V_2 -> V_8 . V_9 - 1 ) / V_10 ) ;
int V_11 = V_5 / V_10 ;
V_6 = F_6 ( V_2 -> V_12 ,
( V_3 << V_7 ) + V_11 , V_4 ) ;
if ( V_6 < 0 ) {
F_4 ( & V_2 -> V_12 -> V_13 , L_2 ) ;
return V_6 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , int V_3 , T_2 * V_4 )
{
int V_6 = 0 ;
if ( V_2 -> V_8 . V_9 <= 8 )
V_6 = F_6 ( V_2 -> V_12 , V_3 , * V_4 ) ;
else if ( V_2 -> V_8 . V_9 >= 24 ) {
int V_7 = F_2 ( ( V_2 -> V_8 . V_9 - 1 ) / V_10 ) ;
V_6 = F_8 ( V_2 -> V_12 ,
( V_3 << V_7 ) | V_14 ,
F_9 ( V_2 ) , V_4 ) ;
} else {
switch ( V_2 -> V_15 ) {
case V_16 :
V_6 = F_10 ( V_2 -> V_12 ,
V_3 << 1 , ( V_17 ) * V_4 ) ;
break;
case V_18 :
V_6 = F_6 ( V_2 -> V_12 , V_3 << 1 ,
V_4 [ 0 ] ) ;
if ( V_6 < 0 )
break;
V_6 = F_6 ( V_2 -> V_12 ,
( V_3 << 1 ) + 1 ,
V_4 [ 1 ] ) ;
break;
}
}
if ( V_6 < 0 ) {
F_4 ( & V_2 -> V_12 -> V_13 , L_2 ) ;
return V_6 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , int V_3 , T_2 * V_4 )
{
int V_6 ;
if ( V_2 -> V_8 . V_9 <= 8 ) {
V_6 = F_3 ( V_2 -> V_12 , V_3 ) ;
* V_4 = V_6 ;
} else if ( V_2 -> V_8 . V_9 >= 24 ) {
int V_7 = F_2 ( ( V_2 -> V_8 . V_9 - 1 ) / V_10 ) ;
V_6 = F_12 ( V_2 -> V_12 ,
( V_3 << V_7 ) | V_14 ,
F_9 ( V_2 ) , V_4 ) ;
} else {
V_6 = F_13 ( V_2 -> V_12 , V_3 << 1 ) ;
V_4 [ 0 ] = ( V_17 ) V_6 & 0xFF ;
V_4 [ 1 ] = ( V_17 ) V_6 >> 8 ;
}
if ( V_6 < 0 ) {
F_4 ( & V_2 -> V_12 -> V_13 , L_1 ) ;
return V_6 ;
}
return 0 ;
}
static int F_14 ( struct V_8 * V_19 , unsigned V_5 )
{
struct V_1 * V_2 = F_15 ( V_19 ) ;
T_2 V_20 ;
int V_6 , V_11 = 0 ;
F_16 ( & V_2 -> V_21 ) ;
V_20 = V_2 -> V_22 [ V_5 / V_10 ] | ( 1u << ( V_5 % V_10 ) ) ;
switch ( V_2 -> V_15 ) {
case V_16 :
V_11 = V_23 ;
break;
case V_18 :
V_11 = V_24 ;
break;
}
V_6 = F_5 ( V_2 , V_11 , V_20 , V_5 ) ;
if ( V_6 )
goto exit;
V_2 -> V_22 [ V_5 / V_10 ] = V_20 ;
V_6 = 0 ;
exit:
F_17 ( & V_2 -> V_21 ) ;
return V_6 ;
}
static int F_18 ( struct V_8 * V_19 ,
unsigned V_5 , int V_4 )
{
struct V_1 * V_2 = F_15 ( V_19 ) ;
T_2 V_20 ;
int V_6 , V_11 = 0 ;
F_16 ( & V_2 -> V_21 ) ;
if ( V_4 )
V_20 = V_2 -> V_25 [ V_5 / V_10 ]
| ( 1u << ( V_5 % V_10 ) ) ;
else
V_20 = V_2 -> V_25 [ V_5 / V_10 ]
& ~ ( 1u << ( V_5 % V_10 ) ) ;
switch ( V_2 -> V_15 ) {
case V_16 :
V_11 = V_26 ;
break;
case V_18 :
V_11 = V_27 ;
break;
}
V_6 = F_5 ( V_2 , V_11 , V_20 , V_5 ) ;
if ( V_6 )
goto exit;
V_2 -> V_25 [ V_5 / V_10 ] = V_20 ;
V_20 = V_2 -> V_22 [ V_5 / V_10 ] & ~ ( 1u << ( V_5 % V_10 ) ) ;
switch ( V_2 -> V_15 ) {
case V_16 :
V_11 = V_23 ;
break;
case V_18 :
V_11 = V_24 ;
break;
}
V_6 = F_5 ( V_2 , V_11 , V_20 , V_5 ) ;
if ( V_6 )
goto exit;
V_2 -> V_22 [ V_5 / V_10 ] = V_20 ;
V_6 = 0 ;
exit:
F_17 ( & V_2 -> V_21 ) ;
return V_6 ;
}
static int F_19 ( struct V_8 * V_19 , unsigned V_5 )
{
struct V_1 * V_2 = F_15 ( V_19 ) ;
T_1 V_20 ;
int V_6 , V_11 = 0 ;
F_16 ( & V_2 -> V_21 ) ;
switch ( V_2 -> V_15 ) {
case V_16 :
V_11 = V_28 ;
break;
case V_18 :
V_11 = V_29 ;
break;
}
V_6 = F_1 ( V_2 , V_11 , & V_20 , V_5 ) ;
F_17 ( & V_2 -> V_21 ) ;
if ( V_6 < 0 ) {
return 0 ;
}
return ( V_20 & ( 1u << ( V_5 % V_10 ) ) ) ? 1 : 0 ;
}
static void F_20 ( struct V_8 * V_19 , unsigned V_5 , int V_4 )
{
struct V_1 * V_2 = F_15 ( V_19 ) ;
T_2 V_20 ;
int V_6 , V_11 = 0 ;
F_16 ( & V_2 -> V_21 ) ;
if ( V_4 )
V_20 = V_2 -> V_25 [ V_5 / V_10 ]
| ( 1u << ( V_5 % V_10 ) ) ;
else
V_20 = V_2 -> V_25 [ V_5 / V_10 ]
& ~ ( 1u << ( V_5 % V_10 ) ) ;
switch ( V_2 -> V_15 ) {
case V_16 :
V_11 = V_26 ;
break;
case V_18 :
V_11 = V_27 ;
break;
}
V_6 = F_5 ( V_2 , V_11 , V_20 , V_5 ) ;
if ( V_6 )
goto exit;
V_2 -> V_25 [ V_5 / V_10 ] = V_20 ;
exit:
F_17 ( & V_2 -> V_21 ) ;
}
static void F_21 ( struct V_8 * V_19 ,
unsigned long * V_30 , unsigned long * V_31 )
{
struct V_1 * V_2 = F_15 ( V_19 ) ;
T_2 V_20 [ V_32 ] ;
int V_6 , V_11 = 0 ;
int V_7 = F_2 ( ( V_2 -> V_8 . V_9 - 1 ) / V_10 ) ;
int V_33 ;
switch ( V_2 -> V_15 ) {
case V_16 :
V_11 = V_26 ;
break;
case V_18 :
V_11 = V_27 ;
break;
}
memcpy ( V_20 , V_2 -> V_25 , F_9 ( V_2 ) ) ;
F_16 ( & V_2 -> V_21 ) ;
for( V_33 = 0 ; V_33 < F_9 ( V_2 ) ; V_33 ++ ) {
unsigned V_34 = V_30 [ V_33 / 4 ] >> ( ( V_33 % 4 ) * 8 ) ;
if( V_34 ) {
unsigned V_35 = V_31 [ V_33 / 4 ] >> ( ( V_33 % 4 ) * 8 ) ;
V_20 [ V_33 ] = ( V_20 [ V_33 ] & ~ V_34 ) | V_35 ;
}
}
V_6 = F_8 ( V_2 -> V_12 , V_11 << V_7 , F_9 ( V_2 ) , V_20 ) ;
if ( V_6 )
goto exit;
memcpy ( V_2 -> V_25 , V_20 , F_9 ( V_2 ) ) ;
exit:
F_17 ( & V_2 -> V_21 ) ;
}
static void F_22 ( struct V_1 * V_2 , int V_36 )
{
struct V_8 * V_19 ;
V_19 = & V_2 -> V_8 ;
V_19 -> V_37 = F_14 ;
V_19 -> V_38 = F_18 ;
V_19 -> V_39 = F_19 ;
V_19 -> V_40 = F_20 ;
V_19 -> V_41 = F_21 ;
V_19 -> V_42 = true ;
V_19 -> V_43 = V_2 -> V_44 ;
V_19 -> V_9 = V_36 ;
V_19 -> V_45 = V_2 -> V_12 -> V_46 ;
V_19 -> V_47 = & V_2 -> V_12 -> V_13 ;
V_19 -> V_48 = V_49 ;
V_19 -> V_50 = V_2 -> V_50 ;
}
static void F_23 ( struct V_51 * V_52 )
{
struct V_8 * V_19 = F_24 ( V_52 ) ;
struct V_1 * V_2 = F_15 ( V_19 ) ;
V_2 -> V_53 [ V_52 -> V_54 / V_10 ] &= ~ ( 1 << ( V_52 -> V_54 % V_10 ) ) ;
}
static void F_25 ( struct V_51 * V_52 )
{
struct V_8 * V_19 = F_24 ( V_52 ) ;
struct V_1 * V_2 = F_15 ( V_19 ) ;
V_2 -> V_53 [ V_52 -> V_54 / V_10 ] |= 1 << ( V_52 -> V_54 % V_10 ) ;
}
static void F_26 ( struct V_51 * V_52 )
{
struct V_8 * V_19 = F_24 ( V_52 ) ;
struct V_1 * V_2 = F_15 ( V_19 ) ;
F_16 ( & V_2 -> V_55 ) ;
}
static void F_27 ( struct V_51 * V_52 )
{
struct V_8 * V_19 = F_24 ( V_52 ) ;
struct V_1 * V_2 = F_15 ( V_19 ) ;
T_2 V_56 ;
int V_57 , V_58 ;
for ( V_58 = 0 ; V_58 < F_9 ( V_2 ) ; V_58 ++ ) {
V_56 = V_2 -> V_59 [ V_58 ] | V_2 -> V_60 [ V_58 ] ;
V_56 &= ~ V_2 -> V_22 [ V_58 ] ;
while ( V_56 ) {
V_57 = F_28 ( V_56 ) ;
F_14 ( & V_2 -> V_8 ,
V_57 + ( V_10 * V_58 ) ) ;
V_56 &= ~ ( 1 << V_57 ) ;
}
}
F_17 ( & V_2 -> V_55 ) ;
}
static int F_29 ( struct V_51 * V_52 , unsigned int type )
{
struct V_8 * V_19 = F_24 ( V_52 ) ;
struct V_1 * V_2 = F_15 ( V_19 ) ;
int V_61 = V_52 -> V_54 / V_10 ;
T_2 V_30 = 1 << ( V_52 -> V_54 % V_10 ) ;
if ( ! ( type & V_62 ) ) {
F_4 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_52 -> V_63 , type ) ;
return - V_64 ;
}
if ( type & V_65 )
V_2 -> V_59 [ V_61 ] |= V_30 ;
else
V_2 -> V_59 [ V_61 ] &= ~ V_30 ;
if ( type & V_66 )
V_2 -> V_60 [ V_61 ] |= V_30 ;
else
V_2 -> V_60 [ V_61 ] &= ~ V_30 ;
return 0 ;
}
static bool F_30 ( struct V_1 * V_2 , T_2 * V_67 )
{
T_2 V_68 [ V_32 ] ;
T_2 V_69 [ V_32 ] ;
bool V_70 = false ;
bool V_71 = false ;
T_2 V_72 [ V_32 ] ;
int V_6 , V_58 , V_11 = 0 ;
switch ( V_2 -> V_15 ) {
case V_16 :
V_11 = V_28 ;
break;
case V_18 :
V_11 = V_29 ;
break;
}
V_6 = F_11 ( V_2 , V_11 , V_68 ) ;
if ( V_6 )
return false ;
for ( V_58 = 0 ; V_58 < F_9 ( V_2 ) ; V_58 ++ )
V_68 [ V_58 ] &= V_2 -> V_22 [ V_58 ] ;
memcpy ( V_69 , V_2 -> V_73 , F_9 ( V_2 ) ) ;
for ( V_58 = 0 ; V_58 < F_9 ( V_2 ) ; V_58 ++ ) {
V_72 [ V_58 ] = ( V_68 [ V_58 ] ^ V_69 [ V_58 ] ) & V_2 -> V_53 [ V_58 ] ;
if ( V_72 [ V_58 ] )
V_71 = true ;
}
if ( ! V_71 )
return false ;
memcpy ( V_2 -> V_73 , V_68 , F_9 ( V_2 ) ) ;
for ( V_58 = 0 ; V_58 < F_9 ( V_2 ) ; V_58 ++ ) {
V_67 [ V_58 ] = ( V_69 [ V_58 ] & V_2 -> V_59 [ V_58 ] ) |
( V_68 [ V_58 ] & V_2 -> V_60 [ V_58 ] ) ;
V_67 [ V_58 ] &= V_72 [ V_58 ] ;
if ( V_67 [ V_58 ] )
V_70 = true ;
}
return V_70 ;
}
static T_3 F_31 ( int V_63 , void * V_74 )
{
struct V_1 * V_2 = V_74 ;
T_2 V_67 [ V_32 ] ;
T_2 V_57 ;
unsigned V_75 = 0 ;
int V_58 ;
if ( ! F_30 ( V_2 , V_67 ) )
return V_76 ;
for ( V_58 = 0 ; V_58 < F_9 ( V_2 ) ; V_58 ++ ) {
while ( V_67 [ V_58 ] ) {
V_57 = F_28 ( V_67 [ V_58 ] ) ;
F_32 ( F_33 ( V_2 -> V_8 . V_77 ,
V_57 + ( V_10 * V_58 ) ) ) ;
V_67 [ V_58 ] &= ~ ( 1 << V_57 ) ;
V_75 ++ ;
}
}
return ( V_75 > 0 ) ? V_78 : V_76 ;
}
static int F_34 ( struct V_1 * V_2 ,
int V_79 )
{
struct V_80 * V_12 = V_2 -> V_12 ;
int V_6 , V_58 , V_11 = 0 ;
if ( V_12 -> V_63 && V_79 != - 1
&& ( V_2 -> V_81 & V_82 ) ) {
switch ( V_2 -> V_15 ) {
case V_16 :
V_11 = V_28 ;
break;
case V_18 :
V_11 = V_29 ;
break;
}
V_6 = F_11 ( V_2 , V_11 , V_2 -> V_73 ) ;
if ( V_6 )
return V_6 ;
for ( V_58 = 0 ; V_58 < F_9 ( V_2 ) ; V_58 ++ )
V_2 -> V_73 [ V_58 ] &= V_2 -> V_22 [ V_58 ] ;
F_35 ( & V_2 -> V_55 ) ;
V_6 = F_36 ( & V_12 -> V_13 ,
V_12 -> V_63 ,
NULL ,
F_31 ,
V_83 | V_84 |
V_85 ,
F_37 ( & V_12 -> V_13 ) , V_2 ) ;
if ( V_6 ) {
F_4 ( & V_12 -> V_13 , L_4 ,
V_12 -> V_63 ) ;
return V_6 ;
}
V_6 = F_38 ( & V_2 -> V_8 ,
& V_86 ,
V_79 ,
V_87 ,
V_88 ) ;
if ( V_6 ) {
F_4 ( & V_12 -> V_13 ,
L_5 ) ;
return V_6 ;
}
F_39 ( & V_2 -> V_8 ,
& V_86 ,
V_12 -> V_63 , NULL ) ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
int V_79 )
{
struct V_80 * V_12 = V_2 -> V_12 ;
if ( V_79 != - 1 && ( V_2 -> V_81 & V_82 ) )
F_40 ( & V_12 -> V_13 , L_6 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , T_1 V_89 )
{
int V_6 ;
T_2 V_4 [ V_32 ] ;
V_6 = F_11 ( V_2 , V_26 , V_2 -> V_25 ) ;
if ( V_6 )
goto V_90;
V_6 = F_11 ( V_2 , V_23 ,
V_2 -> V_22 ) ;
if ( V_6 )
goto V_90;
if ( V_89 )
memset ( V_4 , 0xFF , F_9 ( V_2 ) ) ;
else
memset ( V_4 , 0 , F_9 ( V_2 ) ) ;
V_6 = F_7 ( V_2 , V_91 , V_4 ) ;
V_90:
return V_6 ;
}
static int F_42 ( struct V_1 * V_2 , T_1 V_89 )
{
int V_6 ;
T_2 V_4 [ V_32 ] ;
V_6 = F_11 ( V_2 , V_27 , V_2 -> V_25 ) ;
if ( V_6 )
goto V_90;
V_6 = F_11 ( V_2 , V_24 , V_2 -> V_22 ) ;
if ( V_6 )
goto V_90;
if ( V_89 )
memset ( V_4 , 0xFF , F_9 ( V_2 ) ) ;
else
memset ( V_4 , 0 , F_9 ( V_2 ) ) ;
V_6 = F_7 ( V_2 , V_92 , V_4 ) ;
if ( V_6 )
goto V_90;
memset ( V_4 , 0x02 , F_9 ( V_2 ) ) ;
V_6 = F_7 ( V_2 , V_93 , V_4 ) ;
if ( V_6 )
goto V_90;
return 0 ;
V_90:
return V_6 ;
}
static int F_43 ( struct V_80 * V_12 ,
const struct V_94 * V_95 )
{
struct V_96 * V_97 ;
struct V_1 * V_2 ;
int V_79 = 0 ;
int V_6 ;
T_1 V_89 = 0 ;
V_2 = F_44 ( & V_12 -> V_13 ,
sizeof( struct V_1 ) , V_98 ) ;
if ( V_2 == NULL )
return - V_99 ;
V_97 = F_45 ( & V_12 -> V_13 ) ;
if ( V_97 ) {
V_79 = V_97 -> V_79 ;
V_2 -> V_44 = V_97 -> V_100 ;
V_89 = V_97 -> V_89 ;
V_2 -> V_50 = V_97 -> V_50 ;
} else {
V_2 -> V_44 = - 1 ;
V_79 = 0 ;
}
V_2 -> V_12 = V_12 ;
if ( V_95 ) {
V_2 -> V_81 = V_95 -> V_81 ;
} else {
const struct V_101 * V_95 ;
const struct V_102 * V_103 ;
V_103 = F_46 ( V_104 , & V_12 -> V_13 ) ;
if ( V_103 ) {
V_2 -> V_81 = ( int ) ( V_105 ) V_103 -> V_106 ;
} else {
V_95 = F_47 ( V_107 , & V_12 -> V_13 ) ;
if ( ! V_95 )
return - V_108 ;
V_2 -> V_81 = V_95 -> V_81 ;
}
}
V_2 -> V_15 = F_48 ( V_2 -> V_81 ) ;
F_35 ( & V_2 -> V_21 ) ;
F_22 ( V_2 , V_2 -> V_81 & V_109 ) ;
if ( V_2 -> V_15 == V_16 )
V_6 = F_41 ( V_2 , V_89 ) ;
else
V_6 = F_42 ( V_2 , V_89 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_49 ( & V_2 -> V_8 , V_2 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_34 ( V_2 , V_79 ) ;
if ( V_6 )
return V_6 ;
if ( V_97 && V_97 -> V_110 ) {
V_6 = V_97 -> V_110 ( V_12 , V_2 -> V_8 . V_43 ,
V_2 -> V_8 . V_9 , V_97 -> V_111 ) ;
if ( V_6 < 0 )
F_40 ( & V_12 -> V_13 , L_7 , V_6 ) ;
}
F_50 ( V_12 , V_2 ) ;
return 0 ;
}
static int F_51 ( struct V_80 * V_12 )
{
struct V_96 * V_97 = F_45 ( & V_12 -> V_13 ) ;
struct V_1 * V_2 = F_52 ( V_12 ) ;
int V_6 = 0 ;
if ( V_97 && V_97 -> V_112 ) {
V_6 = V_97 -> V_112 ( V_12 , V_2 -> V_8 . V_43 ,
V_2 -> V_8 . V_9 , V_97 -> V_111 ) ;
if ( V_6 < 0 ) {
F_4 ( & V_12 -> V_13 , L_8 ,
L_9 , V_6 ) ;
return V_6 ;
}
}
F_53 ( & V_2 -> V_8 ) ;
return 0 ;
}
static int T_4 F_54 ( void )
{
return F_55 ( & V_113 ) ;
}
static void T_5 F_56 ( void )
{
F_57 ( & V_113 ) ;
}
