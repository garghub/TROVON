static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_2 ) ;
}
static int F_3 ( struct V_1 * V_4 , int V_5 , T_1 * V_6 ,
int V_7 )
{
int V_8 ;
int V_9 = F_4 ( ( V_4 -> V_2 . V_10 - 1 ) / V_11 ) ;
int V_12 = V_7 / V_11 ;
V_8 = F_5 ( V_4 -> V_13 ,
( V_5 << V_9 ) + V_12 ) ;
* V_6 = V_8 ;
if ( V_8 < 0 ) {
F_6 ( & V_4 -> V_13 -> V_14 , L_1 ) ;
return V_8 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_4 , int V_5 , T_1 V_6 ,
int V_7 )
{
int V_8 = 0 ;
int V_9 = F_4 ( ( V_4 -> V_2 . V_10 - 1 ) / V_11 ) ;
int V_12 = V_7 / V_11 ;
V_8 = F_8 ( V_4 -> V_13 ,
( V_5 << V_9 ) + V_12 , V_6 ) ;
if ( V_8 < 0 ) {
F_6 ( & V_4 -> V_13 -> V_14 , L_2 ) ;
return V_8 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_4 , int V_5 , T_2 * V_6 )
{
int V_8 = 0 ;
if ( V_4 -> V_2 . V_10 <= 8 )
V_8 = F_8 ( V_4 -> V_13 , V_5 , * V_6 ) ;
else if ( V_4 -> V_2 . V_10 >= 24 ) {
int V_9 = F_4 ( ( V_4 -> V_2 . V_10 - 1 ) / V_11 ) ;
V_8 = F_10 ( V_4 -> V_13 ,
( V_5 << V_9 ) | V_15 ,
F_11 ( V_4 ) , V_6 ) ;
} else {
switch ( V_4 -> V_16 ) {
case V_17 :
V_8 = F_12 ( V_4 -> V_13 ,
V_5 << 1 , ( V_18 ) * V_6 ) ;
break;
case V_19 :
V_8 = F_8 ( V_4 -> V_13 , V_5 << 1 ,
V_6 [ 0 ] ) ;
if ( V_8 < 0 )
break;
V_8 = F_8 ( V_4 -> V_13 ,
( V_5 << 1 ) + 1 ,
V_6 [ 1 ] ) ;
break;
}
}
if ( V_8 < 0 ) {
F_6 ( & V_4 -> V_13 -> V_14 , L_2 ) ;
return V_8 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_4 , int V_5 , T_2 * V_6 )
{
int V_8 ;
if ( V_4 -> V_2 . V_10 <= 8 ) {
V_8 = F_5 ( V_4 -> V_13 , V_5 ) ;
* V_6 = V_8 ;
} else if ( V_4 -> V_2 . V_10 >= 24 ) {
int V_9 = F_4 ( ( V_4 -> V_2 . V_10 - 1 ) / V_11 ) ;
V_8 = F_14 ( V_4 -> V_13 ,
( V_5 << V_9 ) | V_15 ,
F_11 ( V_4 ) , V_6 ) ;
} else {
V_8 = F_15 ( V_4 -> V_13 , V_5 << 1 ) ;
V_6 [ 0 ] = ( V_18 ) V_8 & 0xFF ;
V_6 [ 1 ] = ( V_18 ) V_8 >> 8 ;
}
if ( V_8 < 0 ) {
F_6 ( & V_4 -> V_13 -> V_14 , L_1 ) ;
return V_8 ;
}
return 0 ;
}
static int F_16 ( struct V_2 * V_3 , unsigned V_7 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_20 ;
int V_8 , V_12 = 0 ;
F_17 ( & V_4 -> V_21 ) ;
V_20 = V_4 -> V_22 [ V_7 / V_11 ] | ( 1u << ( V_7 % V_11 ) ) ;
switch ( V_4 -> V_16 ) {
case V_17 :
V_12 = V_23 ;
break;
case V_19 :
V_12 = V_24 ;
break;
}
V_8 = F_7 ( V_4 , V_12 , V_20 , V_7 ) ;
if ( V_8 )
goto exit;
V_4 -> V_22 [ V_7 / V_11 ] = V_20 ;
V_8 = 0 ;
exit:
F_18 ( & V_4 -> V_21 ) ;
return V_8 ;
}
static int F_19 ( struct V_2 * V_3 ,
unsigned V_7 , int V_6 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_20 ;
int V_8 , V_12 = 0 ;
F_17 ( & V_4 -> V_21 ) ;
if ( V_6 )
V_20 = V_4 -> V_25 [ V_7 / V_11 ]
| ( 1u << ( V_7 % V_11 ) ) ;
else
V_20 = V_4 -> V_25 [ V_7 / V_11 ]
& ~ ( 1u << ( V_7 % V_11 ) ) ;
switch ( V_4 -> V_16 ) {
case V_17 :
V_12 = V_26 ;
break;
case V_19 :
V_12 = V_27 ;
break;
}
V_8 = F_7 ( V_4 , V_12 , V_20 , V_7 ) ;
if ( V_8 )
goto exit;
V_4 -> V_25 [ V_7 / V_11 ] = V_20 ;
V_20 = V_4 -> V_22 [ V_7 / V_11 ] & ~ ( 1u << ( V_7 % V_11 ) ) ;
switch ( V_4 -> V_16 ) {
case V_17 :
V_12 = V_23 ;
break;
case V_19 :
V_12 = V_24 ;
break;
}
V_8 = F_7 ( V_4 , V_12 , V_20 , V_7 ) ;
if ( V_8 )
goto exit;
V_4 -> V_22 [ V_7 / V_11 ] = V_20 ;
V_8 = 0 ;
exit:
F_18 ( & V_4 -> V_21 ) ;
return V_8 ;
}
static int F_20 ( struct V_2 * V_3 , unsigned V_7 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_20 ;
int V_8 , V_12 = 0 ;
F_17 ( & V_4 -> V_21 ) ;
switch ( V_4 -> V_16 ) {
case V_17 :
V_12 = V_28 ;
break;
case V_19 :
V_12 = V_29 ;
break;
}
V_8 = F_3 ( V_4 , V_12 , & V_20 , V_7 ) ;
F_18 ( & V_4 -> V_21 ) ;
if ( V_8 < 0 ) {
return 0 ;
}
return ( V_20 & ( 1u << ( V_7 % V_11 ) ) ) ? 1 : 0 ;
}
static void F_21 ( struct V_2 * V_3 , unsigned V_7 , int V_6 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_20 ;
int V_8 , V_12 = 0 ;
F_17 ( & V_4 -> V_21 ) ;
if ( V_6 )
V_20 = V_4 -> V_25 [ V_7 / V_11 ]
| ( 1u << ( V_7 % V_11 ) ) ;
else
V_20 = V_4 -> V_25 [ V_7 / V_11 ]
& ~ ( 1u << ( V_7 % V_11 ) ) ;
switch ( V_4 -> V_16 ) {
case V_17 :
V_12 = V_26 ;
break;
case V_19 :
V_12 = V_27 ;
break;
}
V_8 = F_7 ( V_4 , V_12 , V_20 , V_7 ) ;
if ( V_8 )
goto exit;
V_4 -> V_25 [ V_7 / V_11 ] = V_20 ;
exit:
F_18 ( & V_4 -> V_21 ) ;
}
static void F_22 ( struct V_1 * V_4 , int V_30 )
{
struct V_2 * V_3 ;
V_3 = & V_4 -> V_2 ;
V_3 -> V_31 = F_16 ;
V_3 -> V_32 = F_19 ;
V_3 -> V_33 = F_20 ;
V_3 -> V_34 = F_21 ;
V_3 -> V_35 = true ;
V_3 -> V_36 = V_4 -> V_37 ;
V_3 -> V_10 = V_30 ;
V_3 -> V_38 = V_4 -> V_13 -> V_39 ;
V_3 -> V_14 = & V_4 -> V_13 -> V_14 ;
V_3 -> V_40 = V_41 ;
V_3 -> V_42 = V_4 -> V_42 ;
}
static void F_23 ( struct V_43 * V_44 )
{
struct V_2 * V_3 = F_24 ( V_44 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_45 [ V_44 -> V_46 / V_11 ] &= ~ ( 1 << ( V_44 -> V_46 % V_11 ) ) ;
}
static void F_25 ( struct V_43 * V_44 )
{
struct V_2 * V_3 = F_24 ( V_44 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_45 [ V_44 -> V_46 / V_11 ] |= 1 << ( V_44 -> V_46 % V_11 ) ;
}
static void F_26 ( struct V_43 * V_44 )
{
struct V_2 * V_3 = F_24 ( V_44 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_17 ( & V_4 -> V_47 ) ;
}
static void F_27 ( struct V_43 * V_44 )
{
struct V_2 * V_3 = F_24 ( V_44 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_48 ;
int V_49 , V_50 ;
for ( V_50 = 0 ; V_50 < F_11 ( V_4 ) ; V_50 ++ ) {
V_48 = V_4 -> V_51 [ V_50 ] | V_4 -> V_52 [ V_50 ] ;
V_48 &= ~ V_4 -> V_22 [ V_50 ] ;
while ( V_48 ) {
V_49 = F_28 ( V_48 ) ;
F_16 ( & V_4 -> V_2 ,
V_49 + ( V_11 * V_50 ) ) ;
V_48 &= ~ ( 1 << V_49 ) ;
}
}
F_18 ( & V_4 -> V_47 ) ;
}
static int F_29 ( struct V_43 * V_44 , unsigned int type )
{
struct V_2 * V_3 = F_24 ( V_44 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_53 = V_44 -> V_46 / V_11 ;
T_2 V_54 = 1 << ( V_44 -> V_46 % V_11 ) ;
if ( ! ( type & V_55 ) ) {
F_6 ( & V_4 -> V_13 -> V_14 , L_3 ,
V_44 -> V_56 , type ) ;
return - V_57 ;
}
if ( type & V_58 )
V_4 -> V_51 [ V_53 ] |= V_54 ;
else
V_4 -> V_51 [ V_53 ] &= ~ V_54 ;
if ( type & V_59 )
V_4 -> V_52 [ V_53 ] |= V_54 ;
else
V_4 -> V_52 [ V_53 ] &= ~ V_54 ;
return 0 ;
}
static bool F_30 ( struct V_1 * V_4 , T_2 * V_60 )
{
T_2 V_61 [ V_62 ] ;
T_2 V_63 [ V_62 ] ;
bool V_64 = false ;
bool V_65 = false ;
T_2 V_66 [ V_62 ] ;
int V_8 , V_50 , V_12 = 0 ;
switch ( V_4 -> V_16 ) {
case V_17 :
V_12 = V_28 ;
break;
case V_19 :
V_12 = V_29 ;
break;
}
V_8 = F_13 ( V_4 , V_12 , V_61 ) ;
if ( V_8 )
return false ;
for ( V_50 = 0 ; V_50 < F_11 ( V_4 ) ; V_50 ++ )
V_61 [ V_50 ] &= V_4 -> V_22 [ V_50 ] ;
memcpy ( V_63 , V_4 -> V_67 , F_11 ( V_4 ) ) ;
for ( V_50 = 0 ; V_50 < F_11 ( V_4 ) ; V_50 ++ ) {
V_66 [ V_50 ] = ( V_61 [ V_50 ] ^ V_63 [ V_50 ] ) & V_4 -> V_45 [ V_50 ] ;
if ( V_66 [ V_50 ] )
V_65 = true ;
}
if ( ! V_65 )
return false ;
memcpy ( V_4 -> V_67 , V_61 , F_11 ( V_4 ) ) ;
for ( V_50 = 0 ; V_50 < F_11 ( V_4 ) ; V_50 ++ ) {
V_60 [ V_50 ] = ( V_63 [ V_50 ] & V_4 -> V_51 [ V_50 ] ) |
( V_61 [ V_50 ] & V_4 -> V_52 [ V_50 ] ) ;
V_60 [ V_50 ] &= V_66 [ V_50 ] ;
if ( V_60 [ V_50 ] )
V_64 = true ;
}
return V_64 ;
}
static T_3 F_31 ( int V_56 , void * V_68 )
{
struct V_1 * V_4 = V_68 ;
T_2 V_60 [ V_62 ] ;
T_2 V_49 ;
unsigned V_69 = 0 ;
int V_50 ;
if ( ! F_30 ( V_4 , V_60 ) )
return V_70 ;
for ( V_50 = 0 ; V_50 < F_11 ( V_4 ) ; V_50 ++ ) {
while ( V_60 [ V_50 ] ) {
V_49 = F_28 ( V_60 [ V_50 ] ) ;
F_32 ( F_33 ( V_4 -> V_2 . V_71 ,
V_49 + ( V_11 * V_50 ) ) ) ;
V_60 [ V_50 ] &= ~ ( 1 << V_49 ) ;
V_69 ++ ;
}
}
return ( V_69 > 0 ) ? V_72 : V_70 ;
}
static int F_34 ( struct V_1 * V_4 ,
int V_73 )
{
struct V_74 * V_13 = V_4 -> V_13 ;
int V_8 , V_50 , V_12 = 0 ;
if ( V_13 -> V_56 && V_73 != - 1
&& ( V_4 -> V_75 & V_76 ) ) {
switch ( V_4 -> V_16 ) {
case V_17 :
V_12 = V_28 ;
break;
case V_19 :
V_12 = V_29 ;
break;
}
V_8 = F_13 ( V_4 , V_12 , V_4 -> V_67 ) ;
if ( V_8 )
return V_8 ;
for ( V_50 = 0 ; V_50 < F_11 ( V_4 ) ; V_50 ++ )
V_4 -> V_67 [ V_50 ] &= V_4 -> V_22 [ V_50 ] ;
F_35 ( & V_4 -> V_47 ) ;
V_8 = F_36 ( & V_13 -> V_14 ,
V_13 -> V_56 ,
NULL ,
F_31 ,
V_77 | V_78 |
V_79 ,
F_37 ( & V_13 -> V_14 ) , V_4 ) ;
if ( V_8 ) {
F_6 ( & V_13 -> V_14 , L_4 ,
V_13 -> V_56 ) ;
return V_8 ;
}
V_8 = F_38 ( & V_4 -> V_2 ,
& V_80 ,
V_73 ,
V_81 ,
V_82 ) ;
if ( V_8 ) {
F_6 ( & V_13 -> V_14 ,
L_5 ) ;
return V_8 ;
}
F_39 ( & V_4 -> V_2 ,
& V_80 ,
V_13 -> V_56 , NULL ) ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_4 ,
int V_73 )
{
struct V_74 * V_13 = V_4 -> V_13 ;
if ( V_73 != - 1 && ( V_4 -> V_75 & V_76 ) )
F_40 ( & V_13 -> V_14 , L_6 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_4 , T_1 V_83 )
{
int V_8 ;
T_2 V_6 [ V_62 ] ;
V_8 = F_13 ( V_4 , V_26 , V_4 -> V_25 ) ;
if ( V_8 )
goto V_84;
V_8 = F_13 ( V_4 , V_23 ,
V_4 -> V_22 ) ;
if ( V_8 )
goto V_84;
if ( V_83 )
memset ( V_6 , 0xFF , F_11 ( V_4 ) ) ;
else
memset ( V_6 , 0 , F_11 ( V_4 ) ) ;
V_8 = F_9 ( V_4 , V_85 , V_6 ) ;
V_84:
return V_8 ;
}
static int F_42 ( struct V_1 * V_4 , T_1 V_83 )
{
int V_8 ;
T_2 V_6 [ V_62 ] ;
V_8 = F_13 ( V_4 , V_27 , V_4 -> V_25 ) ;
if ( V_8 )
goto V_84;
V_8 = F_13 ( V_4 , V_24 , V_4 -> V_22 ) ;
if ( V_8 )
goto V_84;
if ( V_83 )
memset ( V_6 , 0xFF , F_11 ( V_4 ) ) ;
else
memset ( V_6 , 0 , F_11 ( V_4 ) ) ;
V_8 = F_9 ( V_4 , V_86 , V_6 ) ;
if ( V_8 )
goto V_84;
memset ( V_6 , 0x02 , F_11 ( V_4 ) ) ;
V_8 = F_9 ( V_4 , V_87 , V_6 ) ;
if ( V_8 )
goto V_84;
return 0 ;
V_84:
return V_8 ;
}
static int F_43 ( struct V_74 * V_13 ,
const struct V_88 * V_89 )
{
struct V_90 * V_91 ;
struct V_1 * V_4 ;
int V_73 = 0 ;
int V_8 ;
T_1 V_83 = 0 ;
V_4 = F_44 ( & V_13 -> V_14 ,
sizeof( struct V_1 ) , V_92 ) ;
if ( V_4 == NULL )
return - V_93 ;
V_91 = F_45 ( & V_13 -> V_14 ) ;
if ( V_91 ) {
V_73 = V_91 -> V_73 ;
V_4 -> V_37 = V_91 -> V_94 ;
V_83 = V_91 -> V_83 ;
V_4 -> V_42 = V_91 -> V_42 ;
} else {
V_4 -> V_37 = - 1 ;
V_73 = 0 ;
}
V_4 -> V_13 = V_13 ;
if ( V_89 ) {
V_4 -> V_75 = V_89 -> V_75 ;
} else {
const struct V_95 * V_89 ;
V_89 = F_46 ( V_96 , & V_13 -> V_14 ) ;
if ( ! V_89 )
return - V_97 ;
V_4 -> V_75 = V_89 -> V_75 ;
}
V_4 -> V_16 = F_47 ( V_4 -> V_75 ) ;
F_35 ( & V_4 -> V_21 ) ;
F_22 ( V_4 , V_4 -> V_75 & V_98 ) ;
if ( V_4 -> V_16 == V_17 )
V_8 = F_41 ( V_4 , V_83 ) ;
else
V_8 = F_42 ( V_4 , V_83 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_48 ( & V_4 -> V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_34 ( V_4 , V_73 ) ;
if ( V_8 )
return V_8 ;
if ( V_91 && V_91 -> V_99 ) {
V_8 = V_91 -> V_99 ( V_13 , V_4 -> V_2 . V_36 ,
V_4 -> V_2 . V_10 , V_91 -> V_100 ) ;
if ( V_8 < 0 )
F_40 ( & V_13 -> V_14 , L_7 , V_8 ) ;
}
F_49 ( V_13 , V_4 ) ;
return 0 ;
}
static int F_50 ( struct V_74 * V_13 )
{
struct V_90 * V_91 = F_45 ( & V_13 -> V_14 ) ;
struct V_1 * V_4 = F_51 ( V_13 ) ;
int V_8 = 0 ;
if ( V_91 && V_91 -> V_101 ) {
V_8 = V_91 -> V_101 ( V_13 , V_4 -> V_2 . V_36 ,
V_4 -> V_2 . V_10 , V_91 -> V_100 ) ;
if ( V_8 < 0 ) {
F_6 ( & V_13 -> V_14 , L_8 ,
L_9 , V_8 ) ;
return V_8 ;
}
}
F_52 ( & V_4 -> V_2 ) ;
return 0 ;
}
static int T_4 F_53 ( void )
{
return F_54 ( & V_102 ) ;
}
static void T_5 F_55 ( void )
{
F_56 ( & V_102 ) ;
}
