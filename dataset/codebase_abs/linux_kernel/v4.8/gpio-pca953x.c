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
int V_6 ;
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
case V_16 : {
T_3 V_17 = F_10 ( F_11 ( ( V_18 * ) V_4 ) ) ;
V_6 = F_12 ( V_2 -> V_12 , V_3 << 1 ,
( V_19 V_18 ) V_17 ) ;
break;
}
case V_20 :
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
V_4 [ 0 ] = ( V_18 ) V_6 & 0xFF ;
V_4 [ 1 ] = ( V_18 ) V_6 >> 8 ;
}
if ( V_6 < 0 ) {
F_4 ( & V_2 -> V_12 -> V_13 , L_1 ) ;
return V_6 ;
}
return 0 ;
}
static int F_16 ( struct V_8 * V_21 , unsigned V_5 )
{
struct V_1 * V_2 = F_17 ( V_21 ) ;
T_2 V_22 ;
int V_6 , V_11 = 0 ;
F_18 ( & V_2 -> V_23 ) ;
V_22 = V_2 -> V_24 [ V_5 / V_10 ] | ( 1u << ( V_5 % V_10 ) ) ;
switch ( V_2 -> V_15 ) {
case V_16 :
V_11 = V_25 ;
break;
case V_20 :
V_11 = V_26 ;
break;
}
V_6 = F_5 ( V_2 , V_11 , V_22 , V_5 ) ;
if ( V_6 )
goto exit;
V_2 -> V_24 [ V_5 / V_10 ] = V_22 ;
exit:
F_19 ( & V_2 -> V_23 ) ;
return V_6 ;
}
static int F_20 ( struct V_8 * V_21 ,
unsigned V_5 , int V_4 )
{
struct V_1 * V_2 = F_17 ( V_21 ) ;
T_2 V_22 ;
int V_6 , V_11 = 0 ;
F_18 ( & V_2 -> V_23 ) ;
if ( V_4 )
V_22 = V_2 -> V_27 [ V_5 / V_10 ]
| ( 1u << ( V_5 % V_10 ) ) ;
else
V_22 = V_2 -> V_27 [ V_5 / V_10 ]
& ~ ( 1u << ( V_5 % V_10 ) ) ;
switch ( V_2 -> V_15 ) {
case V_16 :
V_11 = V_28 ;
break;
case V_20 :
V_11 = V_29 ;
break;
}
V_6 = F_5 ( V_2 , V_11 , V_22 , V_5 ) ;
if ( V_6 )
goto exit;
V_2 -> V_27 [ V_5 / V_10 ] = V_22 ;
V_22 = V_2 -> V_24 [ V_5 / V_10 ] & ~ ( 1u << ( V_5 % V_10 ) ) ;
switch ( V_2 -> V_15 ) {
case V_16 :
V_11 = V_25 ;
break;
case V_20 :
V_11 = V_26 ;
break;
}
V_6 = F_5 ( V_2 , V_11 , V_22 , V_5 ) ;
if ( V_6 )
goto exit;
V_2 -> V_24 [ V_5 / V_10 ] = V_22 ;
exit:
F_19 ( & V_2 -> V_23 ) ;
return V_6 ;
}
static int F_21 ( struct V_8 * V_21 , unsigned V_5 )
{
struct V_1 * V_2 = F_17 ( V_21 ) ;
T_1 V_22 ;
int V_6 , V_11 = 0 ;
F_18 ( & V_2 -> V_23 ) ;
switch ( V_2 -> V_15 ) {
case V_16 :
V_11 = V_30 ;
break;
case V_20 :
V_11 = V_31 ;
break;
}
V_6 = F_1 ( V_2 , V_11 , & V_22 , V_5 ) ;
F_19 ( & V_2 -> V_23 ) ;
if ( V_6 < 0 ) {
return 0 ;
}
return ( V_22 & ( 1u << ( V_5 % V_10 ) ) ) ? 1 : 0 ;
}
static void F_22 ( struct V_8 * V_21 , unsigned V_5 , int V_4 )
{
struct V_1 * V_2 = F_17 ( V_21 ) ;
T_2 V_22 ;
int V_6 , V_11 = 0 ;
F_18 ( & V_2 -> V_23 ) ;
if ( V_4 )
V_22 = V_2 -> V_27 [ V_5 / V_10 ]
| ( 1u << ( V_5 % V_10 ) ) ;
else
V_22 = V_2 -> V_27 [ V_5 / V_10 ]
& ~ ( 1u << ( V_5 % V_10 ) ) ;
switch ( V_2 -> V_15 ) {
case V_16 :
V_11 = V_28 ;
break;
case V_20 :
V_11 = V_29 ;
break;
}
V_6 = F_5 ( V_2 , V_11 , V_22 , V_5 ) ;
if ( V_6 )
goto exit;
V_2 -> V_27 [ V_5 / V_10 ] = V_22 ;
exit:
F_19 ( & V_2 -> V_23 ) ;
}
static void F_23 ( struct V_8 * V_21 ,
unsigned long * V_32 , unsigned long * V_33 )
{
struct V_1 * V_2 = F_17 ( V_21 ) ;
T_2 V_22 [ V_34 ] ;
int V_6 , V_11 = 0 ;
int V_7 = F_2 ( ( V_2 -> V_8 . V_9 - 1 ) / V_10 ) ;
int V_35 ;
switch ( V_2 -> V_15 ) {
case V_16 :
V_11 = V_28 ;
break;
case V_20 :
V_11 = V_29 ;
break;
}
memcpy ( V_22 , V_2 -> V_27 , F_9 ( V_2 ) ) ;
F_18 ( & V_2 -> V_23 ) ;
for( V_35 = 0 ; V_35 < F_9 ( V_2 ) ; V_35 ++ ) {
unsigned V_36 = V_32 [ V_35 / sizeof( * V_32 ) ] >>
( ( V_35 % sizeof( * V_32 ) ) * 8 ) ;
if( V_36 ) {
unsigned V_37 = V_33 [ V_35 / sizeof( * V_33 ) ] >>
( ( V_35 % sizeof( * V_33 ) ) * 8 ) ;
V_22 [ V_35 ] = ( V_22 [ V_35 ] & ~ V_36 ) | V_37 ;
}
}
V_6 = F_8 ( V_2 -> V_12 , V_11 << V_7 , F_9 ( V_2 ) , V_22 ) ;
if ( V_6 )
goto exit;
memcpy ( V_2 -> V_27 , V_22 , F_9 ( V_2 ) ) ;
exit:
F_19 ( & V_2 -> V_23 ) ;
}
static void F_24 ( struct V_1 * V_2 , int V_38 )
{
struct V_8 * V_21 ;
V_21 = & V_2 -> V_8 ;
V_21 -> V_39 = F_16 ;
V_21 -> V_40 = F_20 ;
V_21 -> V_41 = F_21 ;
V_21 -> V_42 = F_22 ;
V_21 -> V_43 = F_23 ;
V_21 -> V_44 = true ;
V_21 -> V_45 = V_2 -> V_46 ;
V_21 -> V_9 = V_38 ;
V_21 -> V_47 = V_2 -> V_12 -> V_48 ;
V_21 -> V_49 = & V_2 -> V_12 -> V_13 ;
V_21 -> V_50 = V_51 ;
V_21 -> V_52 = V_2 -> V_52 ;
}
static void F_25 ( struct V_53 * V_54 )
{
struct V_8 * V_21 = F_26 ( V_54 ) ;
struct V_1 * V_2 = F_17 ( V_21 ) ;
V_2 -> V_55 [ V_54 -> V_56 / V_10 ] &= ~ ( 1 << ( V_54 -> V_56 % V_10 ) ) ;
}
static void F_27 ( struct V_53 * V_54 )
{
struct V_8 * V_21 = F_26 ( V_54 ) ;
struct V_1 * V_2 = F_17 ( V_21 ) ;
V_2 -> V_55 [ V_54 -> V_56 / V_10 ] |= 1 << ( V_54 -> V_56 % V_10 ) ;
}
static void F_28 ( struct V_53 * V_54 )
{
struct V_8 * V_21 = F_26 ( V_54 ) ;
struct V_1 * V_2 = F_17 ( V_21 ) ;
F_18 ( & V_2 -> V_57 ) ;
}
static void F_29 ( struct V_53 * V_54 )
{
struct V_8 * V_21 = F_26 ( V_54 ) ;
struct V_1 * V_2 = F_17 ( V_21 ) ;
T_2 V_58 ;
int V_59 , V_60 ;
T_2 V_61 [ V_34 ] ;
if ( V_2 -> V_62 & V_63 ) {
F_7 ( V_2 , V_64 , V_2 -> V_55 ) ;
for ( V_60 = 0 ; V_60 < F_9 ( V_2 ) ; V_60 ++ )
V_61 [ V_60 ] = ~ V_2 -> V_55 [ V_60 ] ;
F_7 ( V_2 , V_65 , V_61 ) ;
}
for ( V_60 = 0 ; V_60 < F_9 ( V_2 ) ; V_60 ++ ) {
V_58 = V_2 -> V_66 [ V_60 ] | V_2 -> V_67 [ V_60 ] ;
V_58 &= ~ V_2 -> V_24 [ V_60 ] ;
while ( V_58 ) {
V_59 = F_30 ( V_58 ) ;
F_16 ( & V_2 -> V_8 ,
V_59 + ( V_10 * V_60 ) ) ;
V_58 &= ~ ( 1 << V_59 ) ;
}
}
F_19 ( & V_2 -> V_57 ) ;
}
static int F_31 ( struct V_53 * V_54 , unsigned int type )
{
struct V_8 * V_21 = F_26 ( V_54 ) ;
struct V_1 * V_2 = F_17 ( V_21 ) ;
int V_68 = V_54 -> V_56 / V_10 ;
T_2 V_32 = 1 << ( V_54 -> V_56 % V_10 ) ;
if ( ! ( type & V_69 ) ) {
F_4 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_54 -> V_70 , type ) ;
return - V_71 ;
}
if ( type & V_72 )
V_2 -> V_66 [ V_68 ] |= V_32 ;
else
V_2 -> V_66 [ V_68 ] &= ~ V_32 ;
if ( type & V_73 )
V_2 -> V_67 [ V_68 ] |= V_32 ;
else
V_2 -> V_67 [ V_68 ] &= ~ V_32 ;
return 0 ;
}
static bool F_32 ( struct V_1 * V_2 , T_2 * V_74 )
{
T_2 V_75 [ V_34 ] ;
T_2 V_76 [ V_34 ] ;
bool V_77 = false ;
bool V_78 = false ;
T_2 V_79 [ V_34 ] ;
int V_6 , V_60 , V_11 = 0 ;
if ( V_2 -> V_62 & V_63 ) {
V_6 = F_13 ( V_2 , V_80 , V_79 ) ;
if ( V_6 )
return false ;
V_6 = F_13 ( V_2 , V_30 , V_75 ) ;
if ( V_6 )
return false ;
for ( V_60 = 0 ; V_60 < F_9 ( V_2 ) ; V_60 ++ ) {
V_74 [ V_60 ] = ( ~ V_75 [ V_60 ] & V_2 -> V_66 [ V_60 ] ) |
( V_75 [ V_60 ] & V_2 -> V_67 [ V_60 ] ) ;
V_74 [ V_60 ] &= V_79 [ V_60 ] ;
if ( V_74 [ V_60 ] )
V_77 = true ;
}
return V_77 ;
}
switch ( V_2 -> V_15 ) {
case V_16 :
V_11 = V_30 ;
break;
case V_20 :
V_11 = V_31 ;
break;
}
V_6 = F_13 ( V_2 , V_11 , V_75 ) ;
if ( V_6 )
return false ;
for ( V_60 = 0 ; V_60 < F_9 ( V_2 ) ; V_60 ++ )
V_75 [ V_60 ] &= V_2 -> V_24 [ V_60 ] ;
memcpy ( V_76 , V_2 -> V_81 , F_9 ( V_2 ) ) ;
for ( V_60 = 0 ; V_60 < F_9 ( V_2 ) ; V_60 ++ ) {
V_79 [ V_60 ] = ( V_75 [ V_60 ] ^ V_76 [ V_60 ] ) & V_2 -> V_55 [ V_60 ] ;
if ( V_79 [ V_60 ] )
V_78 = true ;
}
if ( ! V_78 )
return false ;
memcpy ( V_2 -> V_81 , V_75 , F_9 ( V_2 ) ) ;
for ( V_60 = 0 ; V_60 < F_9 ( V_2 ) ; V_60 ++ ) {
V_74 [ V_60 ] = ( V_76 [ V_60 ] & V_2 -> V_66 [ V_60 ] ) |
( V_75 [ V_60 ] & V_2 -> V_67 [ V_60 ] ) ;
V_74 [ V_60 ] &= V_79 [ V_60 ] ;
if ( V_74 [ V_60 ] )
V_77 = true ;
}
return V_77 ;
}
static T_4 F_33 ( int V_70 , void * V_82 )
{
struct V_1 * V_2 = V_82 ;
T_2 V_74 [ V_34 ] ;
T_2 V_59 ;
unsigned V_83 = 0 ;
int V_60 ;
if ( ! F_32 ( V_2 , V_74 ) )
return V_84 ;
for ( V_60 = 0 ; V_60 < F_9 ( V_2 ) ; V_60 ++ ) {
while ( V_74 [ V_60 ] ) {
V_59 = F_30 ( V_74 [ V_60 ] ) ;
F_34 ( F_35 ( V_2 -> V_8 . V_85 ,
V_59 + ( V_10 * V_60 ) ) ) ;
V_74 [ V_60 ] &= ~ ( 1 << V_59 ) ;
V_83 ++ ;
}
}
return ( V_83 > 0 ) ? V_86 : V_84 ;
}
static int F_36 ( struct V_1 * V_2 ,
int V_87 )
{
struct V_88 * V_12 = V_2 -> V_12 ;
int V_6 , V_60 , V_11 = 0 ;
if ( V_12 -> V_70 && V_87 != - 1
&& ( V_2 -> V_62 & V_89 ) ) {
switch ( V_2 -> V_15 ) {
case V_16 :
V_11 = V_30 ;
break;
case V_20 :
V_11 = V_31 ;
break;
}
V_6 = F_13 ( V_2 , V_11 , V_2 -> V_81 ) ;
if ( V_6 )
return V_6 ;
for ( V_60 = 0 ; V_60 < F_9 ( V_2 ) ; V_60 ++ )
V_2 -> V_81 [ V_60 ] &= V_2 -> V_24 [ V_60 ] ;
F_37 ( & V_2 -> V_57 ) ;
V_6 = F_38 ( & V_12 -> V_13 ,
V_12 -> V_70 ,
NULL ,
F_33 ,
V_90 | V_91 |
V_92 ,
F_39 ( & V_12 -> V_13 ) , V_2 ) ;
if ( V_6 ) {
F_4 ( & V_12 -> V_13 , L_4 ,
V_12 -> V_70 ) ;
return V_6 ;
}
V_6 = F_40 ( & V_2 -> V_8 ,
& V_93 ,
V_87 ,
V_94 ,
V_95 ) ;
if ( V_6 ) {
F_4 ( & V_12 -> V_13 ,
L_5 ) ;
return V_6 ;
}
F_41 ( & V_2 -> V_8 ,
& V_93 ,
V_12 -> V_70 , NULL ) ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
int V_87 )
{
struct V_88 * V_12 = V_2 -> V_12 ;
if ( V_87 != - 1 && ( V_2 -> V_62 & V_89 ) )
F_42 ( & V_12 -> V_13 , L_6 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 , T_1 V_96 )
{
int V_6 ;
T_2 V_4 [ V_34 ] ;
V_6 = F_13 ( V_2 , V_28 , V_2 -> V_27 ) ;
if ( V_6 )
goto V_97;
V_6 = F_13 ( V_2 , V_25 ,
V_2 -> V_24 ) ;
if ( V_6 )
goto V_97;
if ( V_96 )
memset ( V_4 , 0xFF , F_9 ( V_2 ) ) ;
else
memset ( V_4 , 0 , F_9 ( V_2 ) ) ;
V_6 = F_7 ( V_2 , V_98 , V_4 ) ;
V_97:
return V_6 ;
}
static int F_44 ( struct V_1 * V_2 , T_1 V_96 )
{
int V_6 ;
T_2 V_4 [ V_34 ] ;
V_6 = F_13 ( V_2 , V_29 , V_2 -> V_27 ) ;
if ( V_6 )
goto V_97;
V_6 = F_13 ( V_2 , V_26 , V_2 -> V_24 ) ;
if ( V_6 )
goto V_97;
if ( V_96 )
memset ( V_4 , 0xFF , F_9 ( V_2 ) ) ;
else
memset ( V_4 , 0 , F_9 ( V_2 ) ) ;
V_6 = F_7 ( V_2 , V_99 , V_4 ) ;
if ( V_6 )
goto V_97;
memset ( V_4 , 0x02 , F_9 ( V_2 ) ) ;
V_6 = F_7 ( V_2 , V_100 , V_4 ) ;
if ( V_6 )
goto V_97;
return 0 ;
V_97:
return V_6 ;
}
static int F_45 ( struct V_88 * V_12 ,
const struct V_101 * V_102 )
{
struct V_103 * V_104 ;
struct V_1 * V_2 ;
int V_87 = 0 ;
int V_6 ;
T_1 V_96 = 0 ;
V_2 = F_46 ( & V_12 -> V_13 ,
sizeof( struct V_1 ) , V_105 ) ;
if ( V_2 == NULL )
return - V_106 ;
V_104 = F_47 ( & V_12 -> V_13 ) ;
if ( V_104 ) {
V_87 = V_104 -> V_87 ;
V_2 -> V_46 = V_104 -> V_107 ;
V_96 = V_104 -> V_96 ;
V_2 -> V_52 = V_104 -> V_52 ;
} else {
V_2 -> V_46 = - 1 ;
V_87 = 0 ;
}
V_2 -> V_12 = V_12 ;
if ( V_102 ) {
V_2 -> V_62 = V_102 -> V_62 ;
} else {
const struct V_108 * V_102 ;
const struct V_109 * V_110 ;
V_110 = F_48 ( V_111 , & V_12 -> V_13 ) ;
if ( V_110 ) {
V_2 -> V_62 = ( int ) ( V_112 ) V_110 -> V_113 ;
} else {
V_102 = F_49 ( V_114 , & V_12 -> V_13 ) ;
if ( ! V_102 )
return - V_115 ;
V_2 -> V_62 = V_102 -> V_62 ;
}
}
V_2 -> V_15 = F_50 ( V_2 -> V_62 ) ;
F_37 ( & V_2 -> V_23 ) ;
F_24 ( V_2 , V_2 -> V_62 & V_116 ) ;
if ( V_2 -> V_15 == V_16 )
V_6 = F_43 ( V_2 , V_96 ) ;
else
V_6 = F_44 ( V_2 , V_96 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_51 ( & V_12 -> V_13 , & V_2 -> V_8 , V_2 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_36 ( V_2 , V_87 ) ;
if ( V_6 )
return V_6 ;
if ( V_104 && V_104 -> V_117 ) {
V_6 = V_104 -> V_117 ( V_12 , V_2 -> V_8 . V_45 ,
V_2 -> V_8 . V_9 , V_104 -> V_118 ) ;
if ( V_6 < 0 )
F_42 ( & V_12 -> V_13 , L_7 , V_6 ) ;
}
F_52 ( V_12 , V_2 ) ;
return 0 ;
}
static int F_53 ( struct V_88 * V_12 )
{
struct V_103 * V_104 = F_47 ( & V_12 -> V_13 ) ;
struct V_1 * V_2 = F_54 ( V_12 ) ;
int V_6 ;
if ( V_104 && V_104 -> V_119 ) {
V_6 = V_104 -> V_119 ( V_12 , V_2 -> V_8 . V_45 ,
V_2 -> V_8 . V_9 , V_104 -> V_118 ) ;
if ( V_6 < 0 ) {
F_4 ( & V_12 -> V_13 , L_8 ,
L_9 , V_6 ) ;
return V_6 ;
}
}
return 0 ;
}
static int T_5 F_55 ( void )
{
return F_56 ( & V_120 ) ;
}
static void T_6 F_57 ( void )
{
F_58 ( & V_120 ) ;
}
