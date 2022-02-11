static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 -> V_7 . V_8 )
return - V_9 ;
V_4 -> V_10 = V_6 -> V_10 ;
V_4 -> V_11 = V_6 -> V_11 ;
V_4 -> V_12 = V_6 -> V_12 ;
return F_3 ( V_2 -> V_13 , V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_10 = V_4 -> V_10 ;
if ( ! V_6 -> V_10 ) {
F_5 ( V_6 ) ;
} else {
V_6 -> V_10 = F_6 ( V_6 ) ;
if ( ! V_6 -> V_10 )
return - V_9 ;
V_6 -> V_12 = V_4 -> V_12 ;
}
return F_7 ( V_2 -> V_13 , V_4 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
F_9 ( V_15 -> V_16 , V_17 , sizeof( V_15 -> V_16 ) ) ;
F_9 ( V_15 -> V_18 , V_19 , sizeof( V_15 -> V_18 ) ) ;
}
static T_1 F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_20 ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_21 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_20 = V_21 ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_22 , T_2 * V_23 )
{
int V_24 ;
T_2 * V_25 = V_23 ;
switch ( V_22 ) {
case V_26 :
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ ) {
memcpy ( V_25 , V_28 [ V_24 ] . V_29 ,
V_30 ) ;
V_25 += V_30 ;
}
break;
default:
F_13 ( 1 ) ;
break;
}
}
static int F_14 ( struct V_1 * V_31 , int V_32 )
{
int V_33 ;
switch ( V_32 ) {
case V_26 :
V_33 = V_27 ;
return V_33 ;
default:
return - V_34 ;
}
}
static void F_15 ( struct V_1 * V_2 ,
struct V_35 * V_36 , T_3 * V_23 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_24 ;
char * V_25 ;
if ( V_6 -> V_10 ) {
int V_37 = F_16 ( V_2 -> V_13 ) ;
if ( V_37 )
V_6 -> V_38 . V_39 = V_37 ;
}
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ ) {
V_25 = ( char * ) V_6 + V_28 [ V_24 ] . V_40 ;
V_23 [ V_24 ] = ( V_28 [ V_24 ] . V_41 == sizeof( T_3 ) )
? ( * ( T_3 * ) V_25 ) : ( * ( T_1 * ) V_25 ) ;
}
}
static void F_17 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
V_43 -> V_44 = V_45 ;
V_43 -> V_46 = V_47 ;
V_43 -> V_48 = V_49 ;
V_43 -> V_50 = V_51 ;
}
static T_1 F_18 ( T_1 V_52 , struct V_5 * V_6 )
{
unsigned long V_53 = F_19 ( V_6 -> V_54 ) ;
if ( ! V_53 )
return 0 ;
return ( V_52 * 256 ) / ( V_53 / 1000000 ) ;
}
static T_1 F_20 ( T_1 V_55 , struct V_5 * V_6 )
{
unsigned long V_53 = F_19 ( V_6 -> V_54 ) ;
if ( ! V_53 )
return 0 ;
return ( V_55 * ( V_53 / 1000000 ) ) / 256 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_58 )
V_57 -> V_59 = F_18 ( V_6 -> V_60 , V_6 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_60 ;
if ( ! V_57 -> V_59 )
return - V_34 ;
V_60 = F_20 ( V_57 -> V_59 , V_6 ) ;
if ( ( V_60 > V_61 ) || ( V_60 < V_62 ) )
return - V_34 ;
else if ( ! V_6 -> V_58 )
return - V_9 ;
V_6 -> V_60 = V_60 ;
V_6 -> V_63 -> V_64 -> V_65 ( V_6 -> V_66 , V_6 -> V_60 ) ;
return 0 ;
}
static int F_23 ( struct V_5 * V_6 ,
struct V_67 * V_68 )
{
V_68 -> V_23 = 0 ;
switch ( V_68 -> V_69 ) {
case V_70 :
case V_71 :
V_68 -> V_23 |= V_72 | V_73 ;
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
V_68 -> V_23 |= V_79 | V_80 ;
break;
case V_81 :
case V_82 :
V_68 -> V_23 |= V_72 | V_73 ;
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
V_68 -> V_23 |= V_79 | V_80 ;
break;
default:
return - V_34 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_67 * V_68 ,
T_1 * V_88 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_89 = - V_9 ;
switch ( V_68 -> V_68 ) {
case V_90 :
V_89 = F_23 ( V_6 , V_68 ) ;
break;
default:
break;
}
return V_89 ;
}
static int F_25 ( struct V_5 * V_6 ,
struct V_67 * V_68 )
{
T_1 V_91 = 0 ;
if ( V_68 -> V_23 & ~ ( V_79 | V_80 |
V_72 | V_73 ) )
return - V_34 ;
switch ( V_68 -> V_69 ) {
case V_70 :
case V_81 :
if ( ! ( V_68 -> V_23 & V_79 ) ||
! ( V_68 -> V_23 & V_80 ) ||
! ( V_68 -> V_23 & V_72 ) ||
! ( V_68 -> V_23 & V_73 ) )
return - V_34 ;
V_91 = V_92 ;
break;
case V_71 :
case V_82 :
if ( ! ( V_68 -> V_23 & V_79 ) ||
! ( V_68 -> V_23 & V_80 ) ||
! ( V_68 -> V_23 & V_72 ) ||
! ( V_68 -> V_23 & V_73 ) )
return - V_34 ;
V_91 = V_93 ;
break;
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_84 :
case V_85 :
case V_86 :
case V_83 :
case V_78 :
case V_87 :
if ( ! ( V_68 -> V_23 & V_79 ) ||
! ( V_68 -> V_23 & V_80 ) ||
( V_68 -> V_23 & V_72 ) ||
( V_68 -> V_23 & V_73 ) )
return - V_34 ;
V_91 = V_94 ;
break;
default:
return - V_34 ;
}
V_91 |= F_26 ( V_6 -> V_66 + V_95 ) ;
F_27 ( V_91 , V_6 -> V_66 + V_95 ) ;
F_26 ( V_6 -> V_66 + V_95 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_67 * V_68 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_89 = - V_9 ;
switch ( V_68 -> V_68 ) {
case V_96 :
V_89 = F_25 ( V_6 , V_68 ) ;
break;
default:
break;
}
return V_89 ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_97 * V_98 , void * V_99 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 * V_100 = ( T_1 * ) V_99 ;
int V_101 ;
int V_102 = 0 ;
void T_4 * V_66 = V_6 -> V_66 ;
memset ( V_100 , 0x0 , V_103 ) ;
for ( V_101 = V_104 ;
V_101 <= V_105 ; V_101 += 4 ) {
V_100 [ V_102 ] = F_26 ( V_66 + V_101 ) ;
V_102 ++ ;
}
for ( V_101 = V_106 ;
V_101 <= V_107 ; V_101 += 4 ) {
V_100 [ V_102 ] = F_26 ( V_66 + V_101 ) ;
V_102 ++ ;
}
for ( V_101 = V_108 ;
V_101 <= V_109 ; V_101 += 4 ) {
V_100 [ V_102 ] = F_26 ( V_66 + V_101 ) ;
V_102 ++ ;
}
F_30 ( V_102 * 4 > V_103 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
return V_103 ;
}
void F_32 ( struct V_1 * V_31 )
{
V_31 -> V_110 = & V_111 ;
}
