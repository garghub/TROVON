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
struct V_1 * V_2 ;
T_2 V_20 ;
int V_6 , V_11 = 0 ;
V_2 = F_15 ( V_19 , struct V_1 , V_8 ) ;
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
struct V_1 * V_2 ;
T_2 V_20 ;
int V_6 , V_11 = 0 ;
V_2 = F_15 ( V_19 , struct V_1 , V_8 ) ;
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
struct V_1 * V_2 ;
T_1 V_20 ;
int V_6 , V_11 = 0 ;
V_2 = F_15 ( V_19 , struct V_1 , V_8 ) ;
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
struct V_1 * V_2 ;
T_2 V_20 ;
int V_6 , V_11 = 0 ;
V_2 = F_15 ( V_19 , struct V_1 , V_8 ) ;
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
static void F_21 ( struct V_1 * V_2 , int V_30 )
{
struct V_8 * V_19 ;
V_19 = & V_2 -> V_8 ;
V_19 -> V_31 = F_14 ;
V_19 -> V_32 = F_18 ;
V_19 -> V_33 = F_19 ;
V_19 -> V_34 = F_20 ;
V_19 -> V_35 = 1 ;
V_19 -> V_36 = V_2 -> V_37 ;
V_19 -> V_9 = V_30 ;
V_19 -> V_38 = V_2 -> V_12 -> V_39 ;
V_19 -> V_13 = & V_2 -> V_12 -> V_13 ;
V_19 -> V_40 = V_41 ;
V_19 -> V_42 = V_2 -> V_42 ;
}
static int F_22 ( struct V_8 * V_19 , unsigned V_5 )
{
struct V_1 * V_2 ;
V_2 = F_15 ( V_19 , struct V_1 , V_8 ) ;
return F_23 ( V_2 -> V_43 , V_5 ) ;
}
static void F_24 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_25 ( V_45 ) ;
V_2 -> V_46 [ V_45 -> V_47 / V_10 ] &= ~ ( 1 << ( V_45 -> V_47 % V_10 ) ) ;
}
static void F_26 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_25 ( V_45 ) ;
V_2 -> V_46 [ V_45 -> V_47 / V_10 ] |= 1 << ( V_45 -> V_47 % V_10 ) ;
}
static void F_27 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_25 ( V_45 ) ;
F_16 ( & V_2 -> V_48 ) ;
}
static void F_28 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_25 ( V_45 ) ;
T_2 V_49 ;
int V_50 , V_51 ;
for ( V_51 = 0 ; V_51 < F_9 ( V_2 ) ; V_51 ++ ) {
V_49 = V_2 -> V_52 [ V_51 ] | V_2 -> V_53 [ V_51 ] ;
V_49 &= ~ V_2 -> V_22 [ V_51 ] ;
while ( V_49 ) {
V_50 = F_29 ( V_49 ) ;
F_14 ( & V_2 -> V_8 ,
V_50 + ( V_10 * V_51 ) ) ;
V_49 &= ~ ( 1 << V_50 ) ;
}
}
F_17 ( & V_2 -> V_48 ) ;
}
static int F_30 ( struct V_44 * V_45 , unsigned int type )
{
struct V_1 * V_2 = F_25 ( V_45 ) ;
int V_54 = V_45 -> V_47 / V_10 ;
T_2 V_55 = 1 << ( V_45 -> V_47 % V_10 ) ;
if ( ! ( type & V_56 ) ) {
F_4 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_45 -> V_57 , type ) ;
return - V_58 ;
}
if ( type & V_59 )
V_2 -> V_52 [ V_54 ] |= V_55 ;
else
V_2 -> V_52 [ V_54 ] &= ~ V_55 ;
if ( type & V_60 )
V_2 -> V_53 [ V_54 ] |= V_55 ;
else
V_2 -> V_53 [ V_54 ] &= ~ V_55 ;
return 0 ;
}
static T_2 F_31 ( struct V_1 * V_2 , T_2 * V_61 )
{
T_2 V_62 [ V_63 ] ;
T_2 V_64 [ V_63 ] ;
T_2 V_65 = 0 ;
T_2 V_66 [ V_63 ] , V_67 = 0 ;
int V_6 , V_51 , V_11 = 0 ;
switch ( V_2 -> V_15 ) {
case V_16 :
V_11 = V_28 ;
break;
case V_18 :
V_11 = V_29 ;
break;
}
V_6 = F_11 ( V_2 , V_11 , V_62 ) ;
if ( V_6 )
return 0 ;
for ( V_51 = 0 ; V_51 < F_9 ( V_2 ) ; V_51 ++ )
V_62 [ V_51 ] &= V_2 -> V_22 [ V_51 ] ;
memcpy ( V_64 , V_2 -> V_68 , F_9 ( V_2 ) ) ;
for ( V_51 = 0 ; V_51 < F_9 ( V_2 ) ; V_51 ++ ) {
V_66 [ V_51 ] = ( V_62 [ V_51 ] ^ V_64 [ V_51 ] ) & V_2 -> V_46 [ V_51 ] ;
V_67 += V_66 [ V_51 ] ;
}
if ( ! V_67 )
return 0 ;
memcpy ( V_2 -> V_68 , V_62 , F_9 ( V_2 ) ) ;
for ( V_51 = 0 ; V_51 < F_9 ( V_2 ) ; V_51 ++ ) {
V_61 [ V_51 ] = ( V_64 [ V_51 ] & V_2 -> V_52 [ V_51 ] ) |
( V_62 [ V_51 ] & V_2 -> V_53 [ V_51 ] ) ;
V_61 [ V_51 ] &= V_66 [ V_51 ] ;
V_65 += V_61 [ V_51 ] ;
}
return V_65 ;
}
static T_3 F_32 ( int V_57 , void * V_69 )
{
struct V_1 * V_2 = V_69 ;
T_2 V_61 [ V_63 ] ;
T_2 V_50 ;
int V_51 ;
if ( ! F_31 ( V_2 , V_61 ) )
return V_70 ;
for ( V_51 = 0 ; V_51 < F_9 ( V_2 ) ; V_51 ++ ) {
while ( V_61 [ V_51 ] ) {
V_50 = F_29 ( V_61 [ V_51 ] ) ;
F_33 ( F_34 ( V_2 -> V_43 ,
V_50 + ( V_10 * V_51 ) ) ) ;
V_61 [ V_51 ] &= ~ ( 1 << V_50 ) ;
}
}
return V_70 ;
}
static int F_35 ( struct V_71 * V_45 , unsigned int V_57 ,
T_4 V_47 )
{
F_36 ( V_57 , V_72 ) ;
F_37 ( V_57 , V_45 -> V_73 ) ;
F_38 ( V_57 , & V_74 ) ;
F_39 ( V_57 , true ) ;
#ifdef F_40
F_41 ( V_57 , V_75 ) ;
#else
F_42 ( V_57 ) ;
#endif
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
const struct V_76 * V_77 ,
int V_78 )
{
struct V_79 * V_12 = V_2 -> V_12 ;
int V_6 , V_51 , V_11 = 0 ;
if ( V_78 != - 1
&& ( V_77 -> V_80 & V_81 ) ) {
switch ( V_2 -> V_15 ) {
case V_16 :
V_11 = V_28 ;
break;
case V_18 :
V_11 = V_29 ;
break;
}
V_6 = F_11 ( V_2 , V_11 , V_2 -> V_68 ) ;
if ( V_6 )
return V_6 ;
for ( V_51 = 0 ; V_51 < F_9 ( V_2 ) ; V_51 ++ )
V_2 -> V_68 [ V_51 ] &= V_2 -> V_22 [ V_51 ] ;
F_44 ( & V_2 -> V_48 ) ;
V_2 -> V_43 = F_45 ( V_12 -> V_13 . V_82 ,
V_2 -> V_8 . V_9 ,
V_78 ,
& V_83 ,
V_2 ) ;
if ( ! V_2 -> V_43 )
return - V_84 ;
V_6 = F_46 ( & V_12 -> V_13 ,
V_12 -> V_57 ,
NULL ,
F_32 ,
V_85 | V_86 ,
F_47 ( & V_12 -> V_13 ) , V_2 ) ;
if ( V_6 ) {
F_4 ( & V_12 -> V_13 , L_4 ,
V_12 -> V_57 ) ;
return V_6 ;
}
V_2 -> V_8 . V_87 = F_22 ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
const struct V_76 * V_77 ,
int V_78 )
{
struct V_79 * V_12 = V_2 -> V_12 ;
if ( V_78 != - 1 && ( V_77 -> V_80 & V_81 ) )
F_48 ( & V_12 -> V_13 , L_5 ) ;
return 0 ;
}
static void
F_49 ( struct V_79 * V_12 , int * V_88 , T_1 * V_89 )
{
struct V_90 * V_91 ;
const T_5 * V_4 ;
int V_92 ;
V_91 = V_12 -> V_13 . V_82 ;
if ( V_91 == NULL )
return;
* V_88 = - 1 ;
V_4 = F_50 ( V_91 , L_6 , & V_92 ) ;
F_51 ( V_4 , L_7 , V_93 ) ;
if ( V_4 ) {
if ( V_92 != sizeof( * V_4 ) )
F_48 ( & V_12 -> V_13 , L_8 ,
V_91 -> V_94 ) ;
else
* V_88 = F_52 ( V_4 ) ;
}
V_4 = F_50 ( V_91 , L_9 , NULL ) ;
F_51 ( V_4 , L_10 , V_93 ) ;
if ( V_4 )
* V_89 = * V_4 ;
}
static void
F_49 ( struct V_79 * V_12 , int * V_88 , T_1 * V_89 )
{
* V_88 = - 1 ;
}
static int F_53 ( struct V_1 * V_2 , T_1 V_89 )
{
int V_6 ;
T_2 V_4 [ V_63 ] ;
V_6 = F_11 ( V_2 , V_26 , V_2 -> V_25 ) ;
if ( V_6 )
goto V_95;
V_6 = F_11 ( V_2 , V_23 ,
V_2 -> V_22 ) ;
if ( V_6 )
goto V_95;
if ( V_89 )
memset ( V_4 , 0xFF , F_9 ( V_2 ) ) ;
else
memset ( V_4 , 0 , F_9 ( V_2 ) ) ;
V_6 = F_7 ( V_2 , V_96 , V_4 ) ;
V_95:
return V_6 ;
}
static int F_54 ( struct V_1 * V_2 , T_1 V_89 )
{
int V_6 ;
T_2 V_4 [ V_63 ] ;
V_6 = F_11 ( V_2 , V_27 , V_2 -> V_25 ) ;
if ( V_6 )
goto V_95;
V_6 = F_11 ( V_2 , V_24 , V_2 -> V_22 ) ;
if ( V_6 )
goto V_95;
if ( V_89 )
memset ( V_4 , 0xFF , F_9 ( V_2 ) ) ;
else
memset ( V_4 , 0 , F_9 ( V_2 ) ) ;
F_7 ( V_2 , V_97 , V_4 ) ;
memset ( V_4 , 0x02 , F_9 ( V_2 ) ) ;
F_7 ( V_2 , V_98 , V_4 ) ;
return 0 ;
V_95:
return V_6 ;
}
static int F_55 ( struct V_79 * V_12 ,
const struct V_76 * V_77 )
{
struct V_99 * V_100 ;
struct V_1 * V_2 ;
int V_78 = 0 ;
int V_6 ;
T_1 V_89 = 0 ;
V_2 = F_56 ( & V_12 -> V_13 ,
sizeof( struct V_1 ) , V_101 ) ;
if ( V_2 == NULL )
return - V_102 ;
V_100 = F_57 ( & V_12 -> V_13 ) ;
if ( V_100 ) {
V_78 = V_100 -> V_78 ;
V_2 -> V_37 = V_100 -> V_88 ;
V_89 = V_100 -> V_89 ;
V_2 -> V_42 = V_100 -> V_42 ;
} else {
F_49 ( V_12 , & V_2 -> V_37 , & V_89 ) ;
#ifdef F_58
if ( F_59 ( V_12 -> V_13 . V_82 , L_11 , NULL ) == NULL )
V_78 = - 1 ;
#endif
}
V_2 -> V_12 = V_12 ;
V_2 -> V_15 = V_77 -> V_80 & ( V_16 | V_18 ) ;
F_44 ( & V_2 -> V_21 ) ;
F_21 ( V_2 , V_77 -> V_80 & V_103 ) ;
if ( V_2 -> V_15 == V_16 )
V_6 = F_53 ( V_2 , V_89 ) ;
else
V_6 = F_54 ( V_2 , V_89 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_43 ( V_2 , V_77 , V_78 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_60 ( & V_2 -> V_8 ) ;
if ( V_6 )
return V_6 ;
if ( V_100 && V_100 -> V_104 ) {
V_6 = V_100 -> V_104 ( V_12 , V_2 -> V_8 . V_36 ,
V_2 -> V_8 . V_9 , V_100 -> V_105 ) ;
if ( V_6 < 0 )
F_48 ( & V_12 -> V_13 , L_12 , V_6 ) ;
}
F_61 ( V_12 , V_2 ) ;
return 0 ;
}
static int F_62 ( struct V_79 * V_12 )
{
struct V_99 * V_100 = F_57 ( & V_12 -> V_13 ) ;
struct V_1 * V_2 = F_63 ( V_12 ) ;
int V_6 = 0 ;
if ( V_100 && V_100 -> V_106 ) {
V_6 = V_100 -> V_106 ( V_12 , V_2 -> V_8 . V_36 ,
V_2 -> V_8 . V_9 , V_100 -> V_105 ) ;
if ( V_6 < 0 ) {
F_4 ( & V_12 -> V_13 , L_13 ,
L_14 , V_6 ) ;
return V_6 ;
}
}
V_6 = F_64 ( & V_2 -> V_8 ) ;
if ( V_6 ) {
F_4 ( & V_12 -> V_13 , L_13 ,
L_15 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static int T_6 F_65 ( void )
{
return F_66 ( & V_107 ) ;
}
static void T_7 F_67 ( void )
{
F_68 ( & V_107 ) ;
}
