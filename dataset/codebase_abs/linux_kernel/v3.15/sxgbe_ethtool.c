static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 -> V_7 . V_8 )
return - V_9 ;
V_4 -> V_10 = V_6 -> V_10 ;
V_4 -> V_11 = V_6 -> V_11 ;
V_4 -> V_12 = V_6 -> V_12 ;
return F_3 ( V_6 -> V_13 , V_4 ) ;
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
return F_7 ( V_6 -> V_13 , V_4 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
F_9 ( V_15 -> V_16 , V_17 , sizeof( V_15 -> V_16 ) ) ;
F_9 ( V_15 -> V_18 , V_19 , sizeof( V_15 -> V_18 ) ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_13 )
return F_11 ( V_6 -> V_13 , V_21 ) ;
return - V_9 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_13 )
return F_13 ( V_6 -> V_13 , V_21 ) ;
return - V_9 ;
}
static T_1 F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_22 ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_23 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_22 = V_23 ;
}
static void F_16 ( struct V_1 * V_2 , T_1 V_24 , T_2 * V_25 )
{
int V_26 ;
T_2 * V_27 = V_25 ;
switch ( V_24 ) {
case V_28 :
for ( V_26 = 0 ; V_26 < V_29 ; V_26 ++ ) {
memcpy ( V_27 , V_30 [ V_26 ] . V_31 ,
V_32 ) ;
V_27 += V_32 ;
}
break;
default:
F_17 ( 1 ) ;
break;
}
}
static int F_18 ( struct V_1 * V_33 , int V_34 )
{
int V_35 ;
switch ( V_34 ) {
case V_28 :
V_35 = V_29 ;
return V_35 ;
default:
return - V_36 ;
}
}
static void F_19 ( struct V_1 * V_2 ,
struct V_37 * V_38 , T_3 * V_25 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_26 ;
char * V_27 ;
if ( V_6 -> V_10 ) {
int V_39 = F_20 ( V_6 -> V_13 ) ;
if ( V_39 )
V_6 -> V_40 . V_41 = V_39 ;
}
for ( V_26 = 0 ; V_26 < V_29 ; V_26 ++ ) {
V_27 = ( char * ) V_6 + V_30 [ V_26 ] . V_42 ;
V_25 [ V_26 ] = ( V_30 [ V_26 ] . V_43 == sizeof( T_3 ) )
? ( * ( T_3 * ) V_27 ) : ( * ( T_1 * ) V_27 ) ;
}
}
static void F_21 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
V_45 -> V_46 = V_47 ;
V_45 -> V_48 = V_49 ;
V_45 -> V_50 = V_51 ;
V_45 -> V_52 = V_53 ;
}
static T_1 F_22 ( T_1 V_54 , struct V_5 * V_6 )
{
unsigned long V_55 = F_23 ( V_6 -> V_56 ) ;
if ( ! V_55 )
return 0 ;
return ( V_54 * 256 ) / ( V_55 / 1000000 ) ;
}
static T_1 F_24 ( T_1 V_57 , struct V_5 * V_6 )
{
unsigned long V_55 = F_23 ( V_6 -> V_56 ) ;
if ( ! V_55 )
return 0 ;
return ( V_57 * ( V_55 / 1000000 ) ) / 256 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_60 )
V_59 -> V_61 = F_22 ( V_6 -> V_62 , V_6 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_62 ;
if ( ! V_59 -> V_61 )
return - V_36 ;
V_62 = F_24 ( V_59 -> V_61 , V_6 ) ;
if ( ( V_62 > V_63 ) || ( V_62 < V_64 ) )
return - V_36 ;
else if ( ! V_6 -> V_60 )
return - V_9 ;
V_6 -> V_62 = V_62 ;
V_6 -> V_65 -> V_66 -> V_67 ( V_6 -> V_68 , V_6 -> V_62 ) ;
return 0 ;
}
static int F_27 ( struct V_5 * V_6 ,
struct V_69 * V_21 )
{
V_21 -> V_25 = 0 ;
switch ( V_21 -> V_70 ) {
case V_71 :
case V_72 :
V_21 -> V_25 |= V_73 | V_74 ;
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
V_21 -> V_25 |= V_80 | V_81 ;
break;
case V_82 :
case V_83 :
V_21 -> V_25 |= V_73 | V_74 ;
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
V_21 -> V_25 |= V_80 | V_81 ;
break;
default:
return - V_36 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_69 * V_21 ,
T_1 * V_89 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_90 = - V_9 ;
switch ( V_21 -> V_21 ) {
case V_91 :
V_90 = F_27 ( V_6 , V_21 ) ;
break;
default:
break;
}
return V_90 ;
}
static int F_29 ( struct V_5 * V_6 ,
struct V_69 * V_21 )
{
T_1 V_92 = 0 ;
if ( V_21 -> V_25 & ~ ( V_80 | V_81 |
V_73 | V_74 ) )
return - V_36 ;
switch ( V_21 -> V_70 ) {
case V_71 :
case V_82 :
if ( ! ( V_21 -> V_25 & V_80 ) ||
! ( V_21 -> V_25 & V_81 ) ||
! ( V_21 -> V_25 & V_73 ) ||
! ( V_21 -> V_25 & V_74 ) )
return - V_36 ;
V_92 = V_93 ;
break;
case V_72 :
case V_83 :
if ( ! ( V_21 -> V_25 & V_80 ) ||
! ( V_21 -> V_25 & V_81 ) ||
! ( V_21 -> V_25 & V_73 ) ||
! ( V_21 -> V_25 & V_74 ) )
return - V_36 ;
V_92 = V_94 ;
break;
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_85 :
case V_86 :
case V_87 :
case V_84 :
case V_79 :
case V_88 :
if ( ! ( V_21 -> V_25 & V_80 ) ||
! ( V_21 -> V_25 & V_81 ) ||
( V_21 -> V_25 & V_73 ) ||
( V_21 -> V_25 & V_74 ) )
return - V_36 ;
V_92 = V_95 ;
break;
default:
return - V_36 ;
}
V_92 |= F_30 ( V_6 -> V_68 + V_96 ) ;
F_31 ( V_92 , V_6 -> V_68 + V_96 ) ;
F_30 ( V_6 -> V_68 + V_96 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_69 * V_21 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_90 = - V_9 ;
switch ( V_21 -> V_21 ) {
case V_97 :
V_90 = F_29 ( V_6 , V_21 ) ;
break;
default:
break;
}
return V_90 ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_98 * V_99 , void * V_100 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 * V_101 = ( T_1 * ) V_100 ;
int V_102 ;
int V_103 = 0 ;
void T_4 * V_68 = V_6 -> V_68 ;
memset ( V_101 , 0x0 , V_104 ) ;
for ( V_102 = V_105 ;
V_102 <= V_106 ; V_102 += 4 ) {
V_101 [ V_103 ] = F_30 ( V_68 + V_102 ) ;
V_103 ++ ;
}
for ( V_102 = V_107 ;
V_102 <= V_108 ; V_102 += 4 ) {
V_101 [ V_103 ] = F_30 ( V_68 + V_102 ) ;
V_103 ++ ;
}
for ( V_102 = V_109 ;
V_102 <= V_110 ; V_102 += 4 ) {
V_101 [ V_103 ] = F_30 ( V_68 + V_102 ) ;
V_103 ++ ;
}
F_34 ( V_103 * 4 > V_104 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
return V_104 ;
}
void F_36 ( struct V_1 * V_33 )
{
F_37 ( V_33 , & V_111 ) ;
}
