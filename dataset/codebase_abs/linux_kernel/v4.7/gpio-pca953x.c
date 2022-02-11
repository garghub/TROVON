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
V_3 << 1 , F_11 ( F_12 ( ( V_17 * ) V_4 ) ) ) ;
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
static int F_13 ( struct V_1 * V_2 , int V_3 , T_2 * V_4 )
{
int V_6 ;
if ( V_2 -> V_8 . V_9 <= 8 ) {
V_6 = F_3 ( V_2 -> V_12 , V_3 ) ;
* V_4 = V_6 ;
} else if ( V_2 -> V_8 . V_9 >= 24 ) {
int V_7 = F_2 ( ( V_2 -> V_8 . V_9 - 1 ) / V_10 ) ;
V_6 = F_14 ( V_2 -> V_12 ,
( V_3 << V_7 ) | V_14 ,
F_9 ( V_2 ) , V_4 ) ;
} else {
V_6 = F_15 ( V_2 -> V_12 , V_3 << 1 ) ;
V_4 [ 0 ] = ( V_17 ) V_6 & 0xFF ;
V_4 [ 1 ] = ( V_17 ) V_6 >> 8 ;
}
if ( V_6 < 0 ) {
F_4 ( & V_2 -> V_12 -> V_13 , L_1 ) ;
return V_6 ;
}
return 0 ;
}
static int F_16 ( struct V_8 * V_19 , unsigned V_5 )
{
struct V_1 * V_2 = F_17 ( V_19 ) ;
T_2 V_20 ;
int V_6 , V_11 = 0 ;
F_18 ( & V_2 -> V_21 ) ;
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
F_19 ( & V_2 -> V_21 ) ;
return V_6 ;
}
static int F_20 ( struct V_8 * V_19 ,
unsigned V_5 , int V_4 )
{
struct V_1 * V_2 = F_17 ( V_19 ) ;
T_2 V_20 ;
int V_6 , V_11 = 0 ;
F_18 ( & V_2 -> V_21 ) ;
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
F_19 ( & V_2 -> V_21 ) ;
return V_6 ;
}
static int F_21 ( struct V_8 * V_19 , unsigned V_5 )
{
struct V_1 * V_2 = F_17 ( V_19 ) ;
T_1 V_20 ;
int V_6 , V_11 = 0 ;
F_18 ( & V_2 -> V_21 ) ;
switch ( V_2 -> V_15 ) {
case V_16 :
V_11 = V_28 ;
break;
case V_18 :
V_11 = V_29 ;
break;
}
V_6 = F_1 ( V_2 , V_11 , & V_20 , V_5 ) ;
F_19 ( & V_2 -> V_21 ) ;
if ( V_6 < 0 ) {
return 0 ;
}
return ( V_20 & ( 1u << ( V_5 % V_10 ) ) ) ? 1 : 0 ;
}
static void F_22 ( struct V_8 * V_19 , unsigned V_5 , int V_4 )
{
struct V_1 * V_2 = F_17 ( V_19 ) ;
T_2 V_20 ;
int V_6 , V_11 = 0 ;
F_18 ( & V_2 -> V_21 ) ;
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
F_19 ( & V_2 -> V_21 ) ;
}
static void F_23 ( struct V_8 * V_19 ,
unsigned long * V_30 , unsigned long * V_31 )
{
struct V_1 * V_2 = F_17 ( V_19 ) ;
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
F_18 ( & V_2 -> V_21 ) ;
for( V_33 = 0 ; V_33 < F_9 ( V_2 ) ; V_33 ++ ) {
unsigned V_34 = V_30 [ V_33 / sizeof( * V_30 ) ] >>
( ( V_33 % sizeof( * V_30 ) ) * 8 ) ;
if( V_34 ) {
unsigned V_35 = V_31 [ V_33 / sizeof( * V_31 ) ] >>
( ( V_33 % sizeof( * V_31 ) ) * 8 ) ;
V_20 [ V_33 ] = ( V_20 [ V_33 ] & ~ V_34 ) | V_35 ;
}
}
V_6 = F_8 ( V_2 -> V_12 , V_11 << V_7 , F_9 ( V_2 ) , V_20 ) ;
if ( V_6 )
goto exit;
memcpy ( V_2 -> V_25 , V_20 , F_9 ( V_2 ) ) ;
exit:
F_19 ( & V_2 -> V_21 ) ;
}
static void F_24 ( struct V_1 * V_2 , int V_36 )
{
struct V_8 * V_19 ;
V_19 = & V_2 -> V_8 ;
V_19 -> V_37 = F_16 ;
V_19 -> V_38 = F_20 ;
V_19 -> V_39 = F_21 ;
V_19 -> V_40 = F_22 ;
V_19 -> V_41 = F_23 ;
V_19 -> V_42 = true ;
V_19 -> V_43 = V_2 -> V_44 ;
V_19 -> V_9 = V_36 ;
V_19 -> V_45 = V_2 -> V_12 -> V_46 ;
V_19 -> V_47 = & V_2 -> V_12 -> V_13 ;
V_19 -> V_48 = V_49 ;
V_19 -> V_50 = V_2 -> V_50 ;
}
static void F_25 ( struct V_51 * V_52 )
{
struct V_8 * V_19 = F_26 ( V_52 ) ;
struct V_1 * V_2 = F_17 ( V_19 ) ;
V_2 -> V_53 [ V_52 -> V_54 / V_10 ] &= ~ ( 1 << ( V_52 -> V_54 % V_10 ) ) ;
}
static void F_27 ( struct V_51 * V_52 )
{
struct V_8 * V_19 = F_26 ( V_52 ) ;
struct V_1 * V_2 = F_17 ( V_19 ) ;
V_2 -> V_53 [ V_52 -> V_54 / V_10 ] |= 1 << ( V_52 -> V_54 % V_10 ) ;
}
static void F_28 ( struct V_51 * V_52 )
{
struct V_8 * V_19 = F_26 ( V_52 ) ;
struct V_1 * V_2 = F_17 ( V_19 ) ;
F_18 ( & V_2 -> V_55 ) ;
}
static void F_29 ( struct V_51 * V_52 )
{
struct V_8 * V_19 = F_26 ( V_52 ) ;
struct V_1 * V_2 = F_17 ( V_19 ) ;
T_2 V_56 ;
int V_57 , V_58 ;
T_2 V_59 [ V_32 ] ;
if ( V_2 -> V_60 & V_61 ) {
F_7 ( V_2 , V_62 , V_2 -> V_53 ) ;
for ( V_58 = 0 ; V_58 < F_9 ( V_2 ) ; V_58 ++ )
V_59 [ V_58 ] = ~ V_2 -> V_53 [ V_58 ] ;
F_7 ( V_2 , V_63 , V_59 ) ;
}
for ( V_58 = 0 ; V_58 < F_9 ( V_2 ) ; V_58 ++ ) {
V_56 = V_2 -> V_64 [ V_58 ] | V_2 -> V_65 [ V_58 ] ;
V_56 &= ~ V_2 -> V_22 [ V_58 ] ;
while ( V_56 ) {
V_57 = F_30 ( V_56 ) ;
F_16 ( & V_2 -> V_8 ,
V_57 + ( V_10 * V_58 ) ) ;
V_56 &= ~ ( 1 << V_57 ) ;
}
}
F_19 ( & V_2 -> V_55 ) ;
}
static int F_31 ( struct V_51 * V_52 , unsigned int type )
{
struct V_8 * V_19 = F_26 ( V_52 ) ;
struct V_1 * V_2 = F_17 ( V_19 ) ;
int V_66 = V_52 -> V_54 / V_10 ;
T_2 V_30 = 1 << ( V_52 -> V_54 % V_10 ) ;
if ( ! ( type & V_67 ) ) {
F_4 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_52 -> V_68 , type ) ;
return - V_69 ;
}
if ( type & V_70 )
V_2 -> V_64 [ V_66 ] |= V_30 ;
else
V_2 -> V_64 [ V_66 ] &= ~ V_30 ;
if ( type & V_71 )
V_2 -> V_65 [ V_66 ] |= V_30 ;
else
V_2 -> V_65 [ V_66 ] &= ~ V_30 ;
return 0 ;
}
static bool F_32 ( struct V_1 * V_2 , T_2 * V_72 )
{
T_2 V_73 [ V_32 ] ;
T_2 V_74 [ V_32 ] ;
bool V_75 = false ;
bool V_76 = false ;
T_2 V_77 [ V_32 ] ;
int V_6 , V_58 , V_11 = 0 ;
if ( V_2 -> V_60 & V_61 ) {
V_6 = F_13 ( V_2 , V_78 , V_77 ) ;
if ( V_6 )
return false ;
V_6 = F_13 ( V_2 , V_28 , V_73 ) ;
if ( V_6 )
return false ;
for ( V_58 = 0 ; V_58 < F_9 ( V_2 ) ; V_58 ++ ) {
V_72 [ V_58 ] = ( ~ V_73 [ V_58 ] & V_2 -> V_64 [ V_58 ] ) |
( V_73 [ V_58 ] & V_2 -> V_65 [ V_58 ] ) ;
V_72 [ V_58 ] &= V_77 [ V_58 ] ;
if ( V_72 [ V_58 ] )
V_75 = true ;
}
return V_75 ;
}
switch ( V_2 -> V_15 ) {
case V_16 :
V_11 = V_28 ;
break;
case V_18 :
V_11 = V_29 ;
break;
}
V_6 = F_13 ( V_2 , V_11 , V_73 ) ;
if ( V_6 )
return false ;
for ( V_58 = 0 ; V_58 < F_9 ( V_2 ) ; V_58 ++ )
V_73 [ V_58 ] &= V_2 -> V_22 [ V_58 ] ;
memcpy ( V_74 , V_2 -> V_79 , F_9 ( V_2 ) ) ;
for ( V_58 = 0 ; V_58 < F_9 ( V_2 ) ; V_58 ++ ) {
V_77 [ V_58 ] = ( V_73 [ V_58 ] ^ V_74 [ V_58 ] ) & V_2 -> V_53 [ V_58 ] ;
if ( V_77 [ V_58 ] )
V_76 = true ;
}
if ( ! V_76 )
return false ;
memcpy ( V_2 -> V_79 , V_73 , F_9 ( V_2 ) ) ;
for ( V_58 = 0 ; V_58 < F_9 ( V_2 ) ; V_58 ++ ) {
V_72 [ V_58 ] = ( V_74 [ V_58 ] & V_2 -> V_64 [ V_58 ] ) |
( V_73 [ V_58 ] & V_2 -> V_65 [ V_58 ] ) ;
V_72 [ V_58 ] &= V_77 [ V_58 ] ;
if ( V_72 [ V_58 ] )
V_75 = true ;
}
return V_75 ;
}
static T_3 F_33 ( int V_68 , void * V_80 )
{
struct V_1 * V_2 = V_80 ;
T_2 V_72 [ V_32 ] ;
T_2 V_57 ;
unsigned V_81 = 0 ;
int V_58 ;
if ( ! F_32 ( V_2 , V_72 ) )
return V_82 ;
for ( V_58 = 0 ; V_58 < F_9 ( V_2 ) ; V_58 ++ ) {
while ( V_72 [ V_58 ] ) {
V_57 = F_30 ( V_72 [ V_58 ] ) ;
F_34 ( F_35 ( V_2 -> V_8 . V_83 ,
V_57 + ( V_10 * V_58 ) ) ) ;
V_72 [ V_58 ] &= ~ ( 1 << V_57 ) ;
V_81 ++ ;
}
}
return ( V_81 > 0 ) ? V_84 : V_82 ;
}
static int F_36 ( struct V_1 * V_2 ,
int V_85 )
{
struct V_86 * V_12 = V_2 -> V_12 ;
int V_6 , V_58 , V_11 = 0 ;
if ( V_12 -> V_68 && V_85 != - 1
&& ( V_2 -> V_60 & V_87 ) ) {
switch ( V_2 -> V_15 ) {
case V_16 :
V_11 = V_28 ;
break;
case V_18 :
V_11 = V_29 ;
break;
}
V_6 = F_13 ( V_2 , V_11 , V_2 -> V_79 ) ;
if ( V_6 )
return V_6 ;
for ( V_58 = 0 ; V_58 < F_9 ( V_2 ) ; V_58 ++ )
V_2 -> V_79 [ V_58 ] &= V_2 -> V_22 [ V_58 ] ;
F_37 ( & V_2 -> V_55 ) ;
V_6 = F_38 ( & V_12 -> V_13 ,
V_12 -> V_68 ,
NULL ,
F_33 ,
V_88 | V_89 |
V_90 ,
F_39 ( & V_12 -> V_13 ) , V_2 ) ;
if ( V_6 ) {
F_4 ( & V_12 -> V_13 , L_4 ,
V_12 -> V_68 ) ;
return V_6 ;
}
V_6 = F_40 ( & V_2 -> V_8 ,
& V_91 ,
V_85 ,
V_92 ,
V_93 ) ;
if ( V_6 ) {
F_4 ( & V_12 -> V_13 ,
L_5 ) ;
return V_6 ;
}
F_41 ( & V_2 -> V_8 ,
& V_91 ,
V_12 -> V_68 , NULL ) ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
int V_85 )
{
struct V_86 * V_12 = V_2 -> V_12 ;
if ( V_85 != - 1 && ( V_2 -> V_60 & V_87 ) )
F_42 ( & V_12 -> V_13 , L_6 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 , T_1 V_94 )
{
int V_6 ;
T_2 V_4 [ V_32 ] ;
V_6 = F_13 ( V_2 , V_26 , V_2 -> V_25 ) ;
if ( V_6 )
goto V_95;
V_6 = F_13 ( V_2 , V_23 ,
V_2 -> V_22 ) ;
if ( V_6 )
goto V_95;
if ( V_94 )
memset ( V_4 , 0xFF , F_9 ( V_2 ) ) ;
else
memset ( V_4 , 0 , F_9 ( V_2 ) ) ;
V_6 = F_7 ( V_2 , V_96 , V_4 ) ;
V_95:
return V_6 ;
}
static int F_44 ( struct V_1 * V_2 , T_1 V_94 )
{
int V_6 ;
T_2 V_4 [ V_32 ] ;
V_6 = F_13 ( V_2 , V_27 , V_2 -> V_25 ) ;
if ( V_6 )
goto V_95;
V_6 = F_13 ( V_2 , V_24 , V_2 -> V_22 ) ;
if ( V_6 )
goto V_95;
if ( V_94 )
memset ( V_4 , 0xFF , F_9 ( V_2 ) ) ;
else
memset ( V_4 , 0 , F_9 ( V_2 ) ) ;
V_6 = F_7 ( V_2 , V_97 , V_4 ) ;
if ( V_6 )
goto V_95;
memset ( V_4 , 0x02 , F_9 ( V_2 ) ) ;
V_6 = F_7 ( V_2 , V_98 , V_4 ) ;
if ( V_6 )
goto V_95;
return 0 ;
V_95:
return V_6 ;
}
static int F_45 ( struct V_86 * V_12 ,
const struct V_99 * V_100 )
{
struct V_101 * V_102 ;
struct V_1 * V_2 ;
int V_85 = 0 ;
int V_6 ;
T_1 V_94 = 0 ;
V_2 = F_46 ( & V_12 -> V_13 ,
sizeof( struct V_1 ) , V_103 ) ;
if ( V_2 == NULL )
return - V_104 ;
V_102 = F_47 ( & V_12 -> V_13 ) ;
if ( V_102 ) {
V_85 = V_102 -> V_85 ;
V_2 -> V_44 = V_102 -> V_105 ;
V_94 = V_102 -> V_94 ;
V_2 -> V_50 = V_102 -> V_50 ;
} else {
V_2 -> V_44 = - 1 ;
V_85 = 0 ;
}
V_2 -> V_12 = V_12 ;
if ( V_100 ) {
V_2 -> V_60 = V_100 -> V_60 ;
} else {
const struct V_106 * V_100 ;
const struct V_107 * V_108 ;
V_108 = F_48 ( V_109 , & V_12 -> V_13 ) ;
if ( V_108 ) {
V_2 -> V_60 = ( int ) ( V_110 ) V_108 -> V_111 ;
} else {
V_100 = F_49 ( V_112 , & V_12 -> V_13 ) ;
if ( ! V_100 )
return - V_113 ;
V_2 -> V_60 = V_100 -> V_60 ;
}
}
V_2 -> V_15 = F_50 ( V_2 -> V_60 ) ;
F_37 ( & V_2 -> V_21 ) ;
F_24 ( V_2 , V_2 -> V_60 & V_114 ) ;
if ( V_2 -> V_15 == V_16 )
V_6 = F_43 ( V_2 , V_94 ) ;
else
V_6 = F_44 ( V_2 , V_94 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_51 ( & V_12 -> V_13 , & V_2 -> V_8 , V_2 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_36 ( V_2 , V_85 ) ;
if ( V_6 )
return V_6 ;
if ( V_102 && V_102 -> V_115 ) {
V_6 = V_102 -> V_115 ( V_12 , V_2 -> V_8 . V_43 ,
V_2 -> V_8 . V_9 , V_102 -> V_116 ) ;
if ( V_6 < 0 )
F_42 ( & V_12 -> V_13 , L_7 , V_6 ) ;
}
F_52 ( V_12 , V_2 ) ;
return 0 ;
}
static int F_53 ( struct V_86 * V_12 )
{
struct V_101 * V_102 = F_47 ( & V_12 -> V_13 ) ;
struct V_1 * V_2 = F_54 ( V_12 ) ;
int V_6 = 0 ;
if ( V_102 && V_102 -> V_117 ) {
V_6 = V_102 -> V_117 ( V_12 , V_2 -> V_8 . V_43 ,
V_2 -> V_8 . V_9 , V_102 -> V_116 ) ;
if ( V_6 < 0 ) {
F_4 ( & V_12 -> V_13 , L_8 ,
L_9 , V_6 ) ;
return V_6 ;
}
}
return 0 ;
}
static int T_4 F_55 ( void )
{
return F_56 ( & V_118 ) ;
}
static void T_5 F_57 ( void )
{
F_58 ( & V_118 ) ;
}
