static T_1 F_1 ( const struct V_1 * V_2 ,
T_2 V_3 , T_2 V_4 , T_2 * V_5 )
{
T_1 V_6 , V_7 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
V_7 = F_2 ( V_2 , V_3 + V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
V_5 [ V_6 ] = V_7 ;
}
return V_6 ;
}
static T_1 F_3 ( const struct V_1 * V_2 , T_2 V_3 ,
T_2 V_4 , T_2 * V_5 )
{
T_2 V_8 [ 255 ] ;
T_1 V_9 ;
int V_10 = 0 ;
F_4 ( & V_2 -> V_11 , L_1 , V_4 ) ;
V_9 = F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
if ( V_9 < 0 )
return V_9 ;
do {
if ( ++ V_10 > V_12 ) {
F_5 ( & V_2 -> V_11 ,
L_2 ) ;
return - V_13 ;
}
memcpy ( V_8 , V_5 , V_4 ) ;
V_9 = F_1 ( V_2 , V_3 , V_4 ,
V_5 ) ;
if ( V_9 < 0 )
return V_9 ;
} while ( memcmp ( V_8 , V_5 , V_4 ) );
return V_4 ;
}
static T_1 F_6 ( const struct V_1 * V_2 , T_2 V_3 ,
T_2 V_4 , const T_2 * V_5 )
{
T_2 V_14 [ 255 ] ;
int V_10 = 0 ;
F_4 ( & V_2 -> V_11 , L_3 , V_4 ) ;
do {
T_1 V_6 , V_9 ;
if ( ++ V_10 > V_12 ) {
F_5 ( & V_2 -> V_11 ,
L_4 ) ;
return - V_13 ;
}
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
V_9 = F_7 ( V_2 , V_3 + V_6 ,
V_5 [ V_6 ] ) ;
if ( V_9 < 0 )
return V_9 ;
}
V_9 = F_1 ( V_2 , V_3 , V_4 ,
V_14 ) ;
if ( V_9 < 0 )
return V_9 ;
} while ( memcmp ( V_14 , V_5 , V_4 ) );
return V_4 ;
}
static T_1 F_8 ( const struct V_1 * V_2 ,
T_2 V_3 , T_2 V_4 , const T_2 * V_5 )
{
T_2 V_15 = 0 ;
if ( V_4 <= V_16 ) {
T_1 V_17 = F_9 ( V_2 ,
V_3 , V_4 , V_5 ) ;
if ( V_17 < 0 )
return V_17 ;
return V_4 ;
}
while ( V_15 < V_4 ) {
T_1 V_17 = F_9 ( V_2 ,
V_3 + V_15 ,
F_10 ( V_16 , V_4 - V_15 ) ,
V_5 + V_15 ) ;
if ( V_17 < 0 )
return V_17 ;
V_15 += V_16 ;
}
return V_4 ;
}
static T_1 F_11 ( const struct V_1 * V_2 ,
T_2 V_3 , T_2 V_4 , T_2 * V_5 )
{
T_2 V_15 = 0 ;
if ( V_4 <= V_16 )
return F_12 ( V_2 ,
V_3 , V_4 , V_5 ) ;
while ( V_15 < V_4 ) {
T_1 V_17 = F_12 ( V_2 ,
V_3 + V_15 ,
F_10 ( V_16 , V_4 - V_15 ) ,
V_5 + V_15 ) ;
if ( V_17 < 0 )
return V_17 ;
V_15 += V_16 ;
}
return V_4 ;
}
static T_3 F_13 ( int V_18 , void * V_19 )
{
struct V_1 * V_2 = V_19 ;
struct V_20 * V_20 = F_14 ( V_2 ) ;
struct V_21 * V_22 = & V_20 -> V_23 -> V_24 ;
int V_25 , V_26 ;
F_15 ( V_22 ) ;
V_25 = F_2 ( V_2 , V_27 ) ;
if ( V_25 < 0 )
goto V_28;
if ( V_25 & V_29 ) {
V_25 &= ~ V_29 ;
F_7 ( V_2 , V_27 , V_25 ) ;
V_26 = F_2 ( V_2 , V_30 ) ;
if ( V_26 < 0 )
goto V_28;
V_26 &= ~ V_31 ;
F_7 ( V_2 , V_30 , V_26 ) ;
F_16 ( V_20 -> V_23 , 1 , V_32 | V_33 ) ;
}
V_28:
F_17 ( V_22 ) ;
return V_34 ;
}
static int F_18 ( struct V_35 * V_11 , struct V_36 * V_37 )
{
struct V_20 * V_20 = F_19 ( V_11 ) ;
int V_38 ;
V_38 = V_20 -> V_39 ( V_20 -> V_2 ,
V_20 -> V_40 , 7 , V_20 -> V_41 ) ;
if ( V_38 != 7 ) {
F_5 ( V_11 , L_5 , L_6 , V_38 ) ;
return - V_13 ;
}
F_4 ( V_11 , L_7 , L_6 , V_20 -> V_41 ) ;
if ( V_20 -> type == V_42 &&
V_20 -> V_41 [ V_43 ] & V_44 ) {
F_20 ( V_11 , L_8 ) ;
return - V_45 ;
}
V_37 -> V_46 = F_21 ( V_20 -> V_41 [ V_47 ] & 0x7f ) ;
V_37 -> V_48 = F_21 ( V_20 -> V_41 [ V_43 ] & 0x7f ) ;
V_38 = V_20 -> V_41 [ V_49 ] & 0x3f ;
V_37 -> V_50 = F_21 ( V_38 ) ;
V_37 -> V_51 = F_21 ( V_20 -> V_41 [ V_52 ] & 0x07 ) - 1 ;
V_37 -> V_53 = F_21 ( V_20 -> V_41 [ V_54 ] & 0x3f ) ;
V_38 = V_20 -> V_41 [ V_55 ] & 0x1f ;
V_37 -> V_56 = F_21 ( V_38 ) - 1 ;
V_37 -> V_57 = F_21 ( V_20 -> V_41 [ V_58 ] ) + 100 ;
#ifdef F_22
switch ( V_20 -> type ) {
case V_59 :
case V_60 :
case V_61 :
if ( V_20 -> V_41 [ V_55 ] & V_62 )
V_37 -> V_57 += 100 ;
break;
case V_63 :
if ( V_20 -> V_41 [ V_49 ] & V_64 )
V_37 -> V_57 += 100 ;
break;
default:
break;
}
#endif
F_4 ( V_11 , L_9
L_10 ,
L_6 , V_37 -> V_46 , V_37 -> V_48 ,
V_37 -> V_50 , V_37 -> V_53 ,
V_37 -> V_56 , V_37 -> V_57 , V_37 -> V_51 ) ;
return F_23 ( V_37 ) ;
}
static int F_24 ( struct V_35 * V_11 , struct V_36 * V_37 )
{
struct V_20 * V_20 = F_19 ( V_11 ) ;
int V_65 ;
int V_38 ;
T_2 * V_66 = V_20 -> V_41 ;
F_4 ( V_11 , L_9
L_10 ,
L_11 , V_37 -> V_46 , V_37 -> V_48 ,
V_37 -> V_50 , V_37 -> V_53 ,
V_37 -> V_56 , V_37 -> V_57 , V_37 -> V_51 ) ;
#ifdef F_22
if ( V_37 -> V_57 < 100 )
return - V_45 ;
switch ( V_20 -> type ) {
case V_59 :
case V_60 :
case V_61 :
case V_63 :
if ( V_37 -> V_57 > 299 )
return - V_45 ;
default:
if ( V_37 -> V_57 > 199 )
return - V_45 ;
break;
}
#else
if ( V_37 -> V_57 < 100 || V_37 -> V_57 > 199 )
return - V_45 ;
#endif
V_66 [ V_47 ] = F_25 ( V_37 -> V_46 ) ;
V_66 [ V_43 ] = F_25 ( V_37 -> V_48 ) ;
V_66 [ V_49 ] = F_25 ( V_37 -> V_50 ) ;
V_66 [ V_52 ] = F_25 ( V_37 -> V_51 + 1 ) ;
V_66 [ V_54 ] = F_25 ( V_37 -> V_53 ) ;
V_66 [ V_55 ] = F_25 ( V_37 -> V_56 + 1 ) ;
V_38 = V_37 -> V_57 - 100 ;
V_66 [ V_58 ] = F_25 ( V_38 ) ;
switch ( V_20 -> type ) {
case V_59 :
case V_60 :
case V_61 :
if ( V_37 -> V_57 > 199 )
V_66 [ V_55 ] |= V_62 ;
break;
case V_63 :
V_66 [ V_49 ] |= V_67 ;
if ( V_37 -> V_57 > 199 )
V_66 [ V_49 ] |= V_64 ;
break;
case V_68 :
V_66 [ V_47 ] |= V_69 ;
V_66 [ V_52 ] |= V_70 ;
break;
default:
break;
}
F_4 ( V_11 , L_7 , L_11 , V_66 ) ;
V_65 = V_20 -> V_71 ( V_20 -> V_2 ,
V_20 -> V_40 , 7 , V_66 ) ;
if ( V_65 < 0 ) {
F_5 ( V_11 , L_5 , L_11 , V_65 ) ;
return V_65 ;
}
return 0 ;
}
static int F_26 ( struct V_35 * V_11 , struct V_72 * V_37 )
{
struct V_1 * V_2 = F_27 ( V_11 ) ;
struct V_20 * V_20 = F_14 ( V_2 ) ;
int V_9 ;
if ( ! F_28 ( V_73 , & V_20 -> V_74 ) )
return - V_45 ;
V_9 = V_20 -> V_39 ( V_2 ,
V_75 , 9 , V_20 -> V_41 ) ;
if ( V_9 != 9 ) {
F_5 ( V_11 , L_5 , L_12 , V_9 ) ;
return - V_13 ;
}
F_4 ( V_11 , L_13 , L_12 ,
& V_20 -> V_41 [ 0 ] , & V_20 -> V_41 [ 4 ] , & V_20 -> V_41 [ 7 ] ) ;
V_37 -> time . V_46 = F_21 ( V_20 -> V_41 [ 0 ] & 0x7f ) ;
V_37 -> time . V_48 = F_21 ( V_20 -> V_41 [ 1 ] & 0x7f ) ;
V_37 -> time . V_50 = F_21 ( V_20 -> V_41 [ 2 ] & 0x3f ) ;
V_37 -> time . V_53 = F_21 ( V_20 -> V_41 [ 3 ] & 0x3f ) ;
V_37 -> V_76 = ! ! ( V_20 -> V_41 [ 7 ] & V_31 ) ;
V_37 -> V_77 = ! ! ( V_20 -> V_41 [ 8 ] & V_29 ) ;
F_4 ( V_11 , L_9
L_14 ,
L_12 , V_37 -> time . V_46 , V_37 -> time . V_48 ,
V_37 -> time . V_50 , V_37 -> time . V_53 ,
V_37 -> V_76 , V_37 -> V_77 ) ;
return 0 ;
}
static int F_29 ( struct V_35 * V_11 , struct V_72 * V_37 )
{
struct V_1 * V_2 = F_27 ( V_11 ) ;
struct V_20 * V_20 = F_14 ( V_2 ) ;
unsigned char * V_66 = V_20 -> V_41 ;
T_2 V_26 , V_78 ;
int V_9 ;
if ( ! F_28 ( V_73 , & V_20 -> V_74 ) )
return - V_45 ;
F_4 ( V_11 , L_9
L_14 ,
L_15 , V_37 -> time . V_46 , V_37 -> time . V_48 ,
V_37 -> time . V_50 , V_37 -> time . V_53 ,
V_37 -> V_76 , V_37 -> V_77 ) ;
V_9 = V_20 -> V_39 ( V_2 ,
V_75 , 9 , V_66 ) ;
if ( V_9 != 9 ) {
F_5 ( V_11 , L_5 , L_16 , V_9 ) ;
return - V_13 ;
}
V_26 = V_20 -> V_41 [ 7 ] ;
V_78 = V_20 -> V_41 [ 8 ] ;
F_4 ( V_11 , L_17 , L_18 ,
& V_20 -> V_41 [ 0 ] , & V_20 -> V_41 [ 4 ] , V_26 , V_78 ) ;
V_66 [ 0 ] = F_25 ( V_37 -> time . V_46 ) ;
V_66 [ 1 ] = F_25 ( V_37 -> time . V_48 ) ;
V_66 [ 2 ] = F_25 ( V_37 -> time . V_50 ) ;
V_66 [ 3 ] = F_25 ( V_37 -> time . V_53 ) ;
V_66 [ 4 ] = 0 ;
V_66 [ 5 ] = 0 ;
V_66 [ 6 ] = 0 ;
V_66 [ 7 ] = V_26 & ~ ( V_31 | V_79 ) ;
V_66 [ 8 ] = V_78 & ~ ( V_29 | V_80 ) ;
V_9 = V_20 -> V_71 ( V_2 ,
V_75 , 9 , V_66 ) ;
if ( V_9 < 0 ) {
F_5 ( V_11 , L_19 ) ;
return V_9 ;
}
if ( V_37 -> V_76 ) {
F_4 ( V_11 , L_20 ) ;
V_66 [ 7 ] |= V_31 ;
F_7 ( V_2 , V_30 , V_66 [ 7 ] ) ;
}
return 0 ;
}
static int F_30 ( struct V_35 * V_11 , unsigned int V_76 )
{
struct V_1 * V_2 = F_27 ( V_11 ) ;
struct V_20 * V_20 = F_14 ( V_2 ) ;
int V_9 ;
if ( ! F_28 ( V_73 , & V_20 -> V_74 ) )
return - V_81 ;
V_9 = F_2 ( V_2 , V_30 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_76 )
V_9 |= V_31 ;
else
V_9 &= ~ V_31 ;
V_9 = F_7 ( V_2 , V_30 , V_9 ) ;
if ( V_9 < 0 )
return V_9 ;
return 0 ;
}
static T_3 F_31 ( int V_18 , void * V_19 )
{
struct V_1 * V_2 = V_19 ;
struct V_20 * V_20 = F_14 ( V_2 ) ;
struct V_21 * V_22 = & V_20 -> V_23 -> V_24 ;
int V_82 , V_9 ;
F_15 ( V_22 ) ;
V_82 = F_2 ( V_2 , V_83 ) ;
if ( V_82 < 0 )
goto V_28;
if ( ! ( V_82 & V_84 ) )
goto V_28;
V_82 &= ~ V_84 ;
V_9 = F_7 ( V_2 , V_83 , V_82 ) ;
if ( V_9 < 0 )
goto V_28;
V_82 = F_2 ( V_2 , V_85 ) ;
if ( V_82 < 0 )
goto V_28;
V_82 &= ~ V_86 ;
V_9 = F_7 ( V_2 , V_85 , V_82 ) ;
if ( V_9 < 0 )
goto V_28;
F_16 ( V_20 -> V_23 , 1 , V_32 | V_33 ) ;
V_28:
F_17 ( V_22 ) ;
return V_34 ;
}
static int F_32 ( struct V_35 * V_11 , struct V_72 * V_37 )
{
struct V_1 * V_2 = F_27 ( V_11 ) ;
struct V_20 * V_20 = F_14 ( V_2 ) ;
T_2 * V_41 = V_20 -> V_41 ;
int V_9 ;
if ( ! F_28 ( V_73 , & V_20 -> V_74 ) )
return - V_45 ;
V_9 = V_20 -> V_39 ( V_2 , V_85 , 10 , V_41 ) ;
if ( V_9 < 0 )
return V_9 ;
V_37 -> V_76 = ! ! ( V_41 [ 0 ] & V_86 ) ;
V_37 -> time . V_46 = F_21 ( V_20 -> V_41 [ 3 ] & 0x7f ) ;
V_37 -> time . V_48 = F_21 ( V_20 -> V_41 [ 4 ] & 0x7f ) ;
V_37 -> time . V_50 = F_21 ( V_20 -> V_41 [ 5 ] & 0x3f ) ;
V_37 -> time . V_51 = F_21 ( V_20 -> V_41 [ 6 ] & 0x7 ) - 1 ;
V_37 -> time . V_53 = F_21 ( V_20 -> V_41 [ 7 ] & 0x3f ) ;
V_37 -> time . V_56 = F_21 ( V_20 -> V_41 [ 8 ] & 0x1f ) - 1 ;
V_37 -> time . V_57 = - 1 ;
V_37 -> time . V_87 = - 1 ;
V_37 -> time . V_88 = - 1 ;
F_4 ( V_11 , L_21
L_22 , V_89 ,
V_37 -> time . V_46 , V_37 -> time . V_48 , V_37 -> time . V_50 ,
V_37 -> time . V_51 , V_37 -> time . V_53 , V_37 -> time . V_56 , V_37 -> V_76 ,
! ! ( V_20 -> V_41 [ 6 ] & V_90 ) ,
! ! ( V_20 -> V_41 [ 6 ] & V_84 ) ,
( V_20 -> V_41 [ 6 ] & V_91 ) >> 4 ) ;
return 0 ;
}
static int F_33 ( struct V_35 * V_11 , struct V_72 * V_37 )
{
struct V_1 * V_2 = F_27 ( V_11 ) ;
struct V_20 * V_20 = F_14 ( V_2 ) ;
unsigned char * V_41 = V_20 -> V_41 ;
int V_9 ;
if ( ! F_28 ( V_73 , & V_20 -> V_74 ) )
return - V_45 ;
F_4 ( V_11 , L_21
L_23 , V_89 ,
V_37 -> time . V_46 , V_37 -> time . V_48 , V_37 -> time . V_50 ,
V_37 -> time . V_51 , V_37 -> time . V_53 , V_37 -> time . V_56 ,
V_37 -> V_76 , V_37 -> V_77 ) ;
V_9 = V_20 -> V_39 ( V_2 , V_85 , 10 , V_41 ) ;
if ( V_9 < 0 )
return V_9 ;
V_41 [ 3 ] = F_25 ( V_37 -> time . V_46 ) ;
V_41 [ 4 ] = F_25 ( V_37 -> time . V_48 ) ;
V_41 [ 5 ] = F_25 ( V_37 -> time . V_50 ) ;
V_41 [ 6 ] = F_25 ( V_37 -> time . V_51 + 1 ) ;
V_41 [ 7 ] = F_25 ( V_37 -> time . V_53 ) ;
V_41 [ 8 ] = F_25 ( V_37 -> time . V_56 + 1 ) ;
V_41 [ 6 ] &= ~ V_84 ;
V_41 [ 6 ] |= V_91 ;
V_41 [ 0 ] &= ~ V_86 ;
V_9 = V_20 -> V_71 ( V_2 , V_85 , 10 , V_41 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( ! V_37 -> V_76 )
return 0 ;
V_41 [ 0 ] |= V_86 ;
return F_7 ( V_2 , V_85 , V_41 [ 0 ] ) ;
}
static int F_34 ( struct V_35 * V_11 , unsigned int V_76 )
{
struct V_1 * V_2 = F_27 ( V_11 ) ;
struct V_20 * V_20 = F_14 ( V_2 ) ;
int V_82 ;
if ( ! F_28 ( V_73 , & V_20 -> V_74 ) )
return - V_45 ;
V_82 = F_2 ( V_2 , V_85 ) ;
if ( V_82 < 0 )
return V_82 ;
if ( V_76 )
V_82 |= V_86 ;
else
V_82 &= ~ V_86 ;
return F_7 ( V_2 , V_85 , V_82 ) ;
}
static T_4
F_35 ( struct V_92 * V_93 , struct V_94 * V_95 ,
struct V_96 * V_97 ,
char * V_66 , T_5 V_98 , T_6 V_99 )
{
struct V_1 * V_2 ;
struct V_20 * V_20 ;
int V_65 ;
V_2 = F_36 ( V_95 ) ;
V_20 = F_14 ( V_2 ) ;
V_65 = V_20 -> V_39 ( V_2 , V_20 -> V_100 + V_98 ,
V_99 , V_66 ) ;
if ( V_65 < 0 )
F_5 ( & V_2 -> V_11 , L_5 , L_24 , V_65 ) ;
return V_65 ;
}
static T_4
F_37 ( struct V_92 * V_93 , struct V_94 * V_95 ,
struct V_96 * V_97 ,
char * V_66 , T_5 V_98 , T_6 V_99 )
{
struct V_1 * V_2 ;
struct V_20 * V_20 ;
int V_65 ;
V_2 = F_36 ( V_95 ) ;
V_20 = F_14 ( V_2 ) ;
V_65 = V_20 -> V_71 ( V_2 , V_20 -> V_100 + V_98 ,
V_99 , V_66 ) ;
if ( V_65 < 0 ) {
F_5 ( & V_2 -> V_11 , L_5 , L_25 , V_65 ) ;
return V_65 ;
}
return V_99 ;
}
static T_2 F_38 ( struct V_1 * V_2 ,
T_7 V_101 , bool V_102 )
{
T_2 V_103 = ( V_102 ) ? V_104 :
V_105 ;
switch ( V_101 ) {
case 250 :
V_103 |= V_106 ;
break;
case 2000 :
V_103 |= V_107 ;
break;
case 4000 :
V_103 |= V_108 ;
break;
default:
F_39 ( & V_2 -> V_11 ,
L_26 , V_101 ) ;
return 0 ;
}
return V_103 ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_109 * V_110 )
{
T_7 V_101 = 0 ;
bool V_102 = true ;
if ( ! V_110 -> V_111 )
goto V_28;
if ( F_41 ( & V_2 -> V_11 , L_27 , & V_101 ) )
goto V_28;
if ( F_42 ( & V_2 -> V_11 , L_28 ) )
V_102 = false ;
V_110 -> V_112 = V_110 -> V_111 ( V_2 ,
V_101 , V_102 ) ;
V_28:
return;
}
static int F_43 ( struct V_35 * V_11 , T_1 * V_113 )
{
struct V_20 * V_20 = F_19 ( V_11 ) ;
T_2 V_114 [ 2 ] ;
T_8 V_115 ;
int V_9 ;
V_9 = V_20 -> V_39 ( V_20 -> V_2 , V_116 ,
sizeof( V_114 ) , V_114 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 != sizeof( V_114 ) )
return - V_13 ;
V_115 = ( V_114 [ 0 ] << 8 ) | V_114 [ 1 ] ;
V_115 >>= 6 ;
* V_113 = V_115 * 250 ;
return 0 ;
}
static T_4 F_44 ( struct V_35 * V_11 ,
struct V_117 * V_97 , char * V_66 )
{
int V_9 ;
T_1 V_115 ;
V_9 = F_43 ( V_11 , & V_115 ) ;
if ( V_9 )
return V_9 ;
return sprintf ( V_66 , L_29 , V_115 ) ;
}
static void F_45 ( struct V_20 * V_20 )
{
struct V_35 * V_11 ;
if ( V_20 -> type != V_61 )
return;
V_11 = F_46 ( & V_20 -> V_2 -> V_11 ,
V_20 -> V_2 -> V_118 ,
V_20 , V_119 ) ;
if ( F_47 ( V_11 ) ) {
F_39 ( & V_20 -> V_2 -> V_11 ,
L_30 , F_48 ( V_11 ) ) ;
}
}
static void F_45 ( struct V_20 * V_20 )
{
}
static int F_49 ( struct V_20 * V_20 , T_2 V_120 , T_2 V_121 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_21 * V_22 = & V_20 -> V_23 -> V_24 ;
int V_26 ;
int V_9 ;
F_15 ( V_22 ) ;
V_26 = F_2 ( V_2 , V_30 ) ;
if ( V_26 < 0 ) {
V_9 = V_26 ;
goto V_28;
}
V_26 &= ~ V_120 ;
V_26 |= V_121 ;
V_9 = F_7 ( V_2 , V_30 , V_26 ) ;
V_28:
F_17 ( V_22 ) ;
return V_9 ;
}
static unsigned long F_50 ( struct V_122 * V_123 ,
unsigned long V_124 )
{
struct V_20 * V_20 = F_51 ( V_123 ) ;
int V_26 ;
int V_125 = 0 ;
V_26 = F_2 ( V_20 -> V_2 , V_30 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_26 & V_126 )
V_125 += 1 ;
if ( V_26 & V_127 )
V_125 += 2 ;
return V_128 [ V_125 ] ;
}
static long F_52 ( struct V_122 * V_123 , unsigned long V_129 ,
unsigned long * V_130 )
{
int V_6 ;
for ( V_6 = F_53 ( V_128 ) - 1 ; V_6 >= 0 ; V_6 -- ) {
if ( V_128 [ V_6 ] <= V_129 )
return V_128 [ V_6 ] ;
}
return 0 ;
}
static int F_54 ( struct V_122 * V_123 , unsigned long V_129 ,
unsigned long V_124 )
{
struct V_20 * V_20 = F_51 ( V_123 ) ;
int V_26 = 0 ;
int V_125 ;
for ( V_125 = 0 ; V_125 < F_53 ( V_128 ) ;
V_125 ++ ) {
if ( V_128 [ V_125 ] == V_129 )
break;
}
if ( V_125 == F_53 ( V_128 ) )
return - V_45 ;
if ( V_125 & 1 )
V_26 |= V_126 ;
if ( V_125 & 2 )
V_26 |= V_127 ;
return F_49 ( V_20 , V_126 | V_127 ,
V_26 ) ;
}
static int F_55 ( struct V_122 * V_123 )
{
struct V_20 * V_20 = F_51 ( V_123 ) ;
return F_49 ( V_20 , V_131 , 0 ) ;
}
static void F_56 ( struct V_122 * V_123 )
{
struct V_20 * V_20 = F_51 ( V_123 ) ;
F_49 ( V_20 , V_131 , V_131 ) ;
}
static int F_57 ( struct V_122 * V_123 )
{
struct V_20 * V_20 = F_51 ( V_123 ) ;
int V_26 ;
V_26 = F_2 ( V_20 -> V_2 , V_30 ) ;
if ( V_26 < 0 )
return V_26 ;
return ! ( V_26 & V_131 ) ;
}
static unsigned long F_58 ( struct V_122 * V_123 ,
unsigned long V_124 )
{
return 32768 ;
}
static int F_59 ( struct V_20 * V_20 , bool V_132 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_21 * V_22 = & V_20 -> V_23 -> V_24 ;
int V_78 ;
int V_9 ;
F_15 ( V_22 ) ;
V_78 = F_2 ( V_2 , V_27 ) ;
if ( V_78 < 0 ) {
V_9 = V_78 ;
goto V_28;
}
if ( V_132 )
V_78 |= V_133 ;
else
V_78 &= ~ V_133 ;
V_9 = F_7 ( V_2 , V_27 , V_78 ) ;
V_28:
F_17 ( V_22 ) ;
return V_9 ;
}
static int F_60 ( struct V_122 * V_123 )
{
struct V_20 * V_20 = F_61 ( V_123 ) ;
return F_59 ( V_20 , true ) ;
}
static void F_62 ( struct V_122 * V_123 )
{
struct V_20 * V_20 = F_61 ( V_123 ) ;
F_59 ( V_20 , false ) ;
}
static int F_63 ( struct V_122 * V_123 )
{
struct V_20 * V_20 = F_61 ( V_123 ) ;
int V_78 ;
V_78 = F_2 ( V_20 -> V_2 , V_27 ) ;
if ( V_78 < 0 )
return V_78 ;
return ! ! ( V_78 & V_133 ) ;
}
static int F_64 ( struct V_20 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_134 * V_135 = V_2 -> V_11 . V_136 ;
struct V_137 * V_138 ;
int V_6 ;
V_138 = F_65 ( & V_2 -> V_11 , sizeof( * V_138 ) , V_139 ) ;
if ( ! V_138 )
return - V_140 ;
V_138 -> V_141 = F_53 ( V_142 ) ;
V_138 -> V_143 = F_66 ( & V_2 -> V_11 , V_138 -> V_141 ,
sizeof( V_138 -> V_143 [ 0 ] ) , V_139 ) ;
if ( ! V_138 -> V_143 )
return - V_140 ;
for ( V_6 = 0 ; V_6 < F_53 ( V_142 ) ; V_6 ++ ) {
struct V_144 V_145 = V_142 [ V_6 ] ;
if ( V_6 == V_146 && F_28 ( V_73 , & V_20 -> V_74 ) )
continue;
F_67 ( V_135 , L_31 , V_6 ,
& V_145 . V_118 ) ;
V_20 -> V_143 [ V_6 ] . V_145 = & V_145 ;
V_138 -> V_143 [ V_6 ] = F_68 ( & V_2 -> V_11 ,
& V_20 -> V_143 [ V_6 ] ) ;
if ( F_47 ( V_138 -> V_143 [ V_6 ] ) )
return F_48 ( V_138 -> V_143 [ V_6 ] ) ;
}
if ( ! V_135 )
return 0 ;
F_69 ( V_135 , V_147 , V_138 ) ;
return 0 ;
}
static void F_70 ( struct V_20 * V_20 )
{
int V_9 ;
if ( V_20 -> type != V_61 )
return;
V_9 = F_64 ( V_20 ) ;
if ( V_9 ) {
F_39 ( & V_20 -> V_2 -> V_11 ,
L_32 , V_9 ) ;
}
}
static void F_70 ( struct V_20 * V_20 )
{
}
static int F_71 ( struct V_1 * V_2 ,
const struct V_148 * V_149 )
{
struct V_20 * V_20 ;
int V_150 = - V_151 ;
int V_38 , V_152 ;
struct V_109 * V_110 ;
struct V_153 * V_154 = F_72 ( V_2 -> V_11 . V_155 ) ;
bool V_156 = false ;
bool V_157 = false ;
unsigned char * V_66 ;
struct V_158 * V_159 = F_73 ( & V_2 -> V_11 ) ;
struct V_36 V_160 ;
unsigned long V_161 ;
T_9 V_162 = F_13 ;
static const int V_163 [] = {
[ V_59 ] = 0 ,
[ V_60 ] = V_164 ,
[ V_61 ] = V_165 ,
} ;
const struct V_166 * V_167 = & V_168 ;
if ( ! F_74 ( V_154 , V_169 )
&& ! F_74 ( V_154 , V_170 ) )
return - V_13 ;
V_20 = F_65 ( & V_2 -> V_11 , sizeof( struct V_20 ) , V_139 ) ;
if ( ! V_20 )
return - V_140 ;
F_75 ( V_2 , V_20 ) ;
V_20 -> V_2 = V_2 ;
if ( V_2 -> V_11 . V_136 ) {
V_20 -> type = (enum V_171 )
F_76 ( & V_2 -> V_11 ) ;
V_110 = & V_172 [ V_20 -> type ] ;
} else if ( V_149 ) {
V_110 = & V_172 [ V_149 -> V_173 ] ;
V_20 -> type = V_149 -> V_173 ;
} else {
const struct V_174 * V_175 ;
V_175 = F_77 ( F_78 ( V_176 ) ,
& V_2 -> V_11 ) ;
if ( ! V_175 )
return - V_151 ;
V_110 = & V_172 [ V_175 -> V_173 ] ;
V_20 -> type = V_175 -> V_173 ;
}
if ( ! V_159 )
F_40 ( V_2 , V_110 ) ;
else if ( V_159 -> V_112 )
V_110 -> V_112 = V_159 -> V_112 ;
if ( V_110 -> V_112 && V_110 -> V_177 ) {
F_4 ( & V_2 -> V_11 , L_33 ,
V_178 | V_110 -> V_112 ,
V_110 -> V_177 ) ;
F_7 ( V_2 , V_110 -> V_177 ,
V_178 |
V_110 -> V_112 ) ;
}
V_66 = V_20 -> V_41 ;
if ( F_74 ( V_154 , V_170 ) ) {
V_20 -> V_39 = F_11 ;
V_20 -> V_71 = F_8 ;
} else {
V_20 -> V_39 = F_3 ;
V_20 -> V_71 = F_6 ;
}
#ifdef F_79
if ( F_80 ( V_2 -> V_11 . V_136 , L_34 ) ) {
V_157 = true ;
}
if ( F_80 ( V_2 -> V_11 . V_136 ,
L_35 ) ) {
V_157 = true ;
}
#endif
switch ( V_20 -> type ) {
case V_59 :
case V_60 :
case V_61 :
V_38 = V_20 -> V_39 ( V_20 -> V_2 ,
V_30 , 2 , V_66 ) ;
if ( V_38 != 2 ) {
F_4 ( & V_2 -> V_11 , L_36 , V_38 ) ;
V_150 = - V_13 ;
goto exit;
}
if ( V_20 -> V_41 [ 0 ] & V_179 )
V_20 -> V_41 [ 0 ] &= ~ V_179 ;
if ( V_110 -> V_180 && ( V_20 -> V_2 -> V_18 > 0 ||
V_157 ) ) {
V_20 -> V_41 [ 0 ] |= V_131
| V_163 [ V_20 -> type ] ;
V_20 -> V_41 [ 0 ] &= ~ ( V_79 | V_31 ) ;
V_156 = true ;
}
F_7 ( V_2 , V_30 ,
V_20 -> V_41 [ 0 ] ) ;
if ( V_20 -> V_41 [ 1 ] & V_181 ) {
F_7 ( V_2 , V_27 ,
V_20 -> V_41 [ 1 ] & ~ V_181 ) ;
F_39 ( & V_2 -> V_11 , L_37 ) ;
}
break;
case V_182 :
V_38 = F_12 ( V_20 -> V_2 ,
V_183 << 4 | 0x08 , 2 , V_66 ) ;
if ( V_38 != 2 ) {
F_4 ( & V_2 -> V_11 , L_36 , V_38 ) ;
V_150 = - V_13 ;
goto exit;
}
if ( ! ( V_20 -> V_41 [ 1 ] & V_184 ) ) {
V_20 -> V_41 [ 1 ] |= V_184 ;
F_7 ( V_2 ,
V_185 << 4 | 0x08 ,
V_20 -> V_41 [ 1 ] ) ;
F_39 ( & V_2 -> V_11 ,
L_38 ) ;
}
if ( V_20 -> V_41 [ 1 ] & V_186 ) {
V_20 -> V_41 [ 1 ] &= ~ V_186 ;
F_7 ( V_2 ,
V_185 << 4 | 0x08 ,
V_20 -> V_41 [ 1 ] ) ;
F_39 ( & V_2 -> V_11 , L_39 ) ;
}
if ( V_20 -> V_41 [ 1 ] & V_187 ) {
V_20 -> V_41 [ 1 ] &= ~ V_187 ;
F_7 ( V_2 ,
V_185 << 4 | 0x08 ,
V_20 -> V_41 [ 1 ] ) ;
F_39 ( & V_2 -> V_11 , L_40 ) ;
}
if ( ! ( V_20 -> V_41 [ 0 ] & V_188 ) ) {
T_2 V_189 ;
F_7 ( V_2 ,
V_183 << 4 | 0x08 ,
V_20 -> V_41 [ 0 ] |
V_188 ) ;
V_38 = F_12 ( V_20 -> V_2 ,
V_183 << 4 | 0x08 , 2 , V_66 ) ;
if ( V_38 != 2 ) {
F_4 ( & V_2 -> V_11 , L_36 , V_38 ) ;
V_150 = - V_13 ;
goto exit;
}
V_189 = F_21 ( V_20 -> V_41 [ V_49 ] ) ;
if ( V_189 == 12 )
V_189 = 0 ;
if ( V_20 -> V_41 [ V_49 ] & V_190 )
V_189 += 12 ;
F_7 ( V_2 ,
V_49 << 4 | 0x08 ,
V_189 ) ;
}
break;
case V_191 :
V_20 -> V_40 = 1 ;
break;
case V_68 :
V_167 = & V_192 ;
if ( V_20 -> V_2 -> V_18 > 0 && V_110 -> V_180 ) {
V_162 = F_31 ;
V_156 = true ;
}
break;
default:
break;
}
V_193:
V_38 = V_20 -> V_39 ( V_20 -> V_2 , V_20 -> V_40 , 8 , V_66 ) ;
if ( V_38 != 8 ) {
F_4 ( & V_2 -> V_11 , L_36 , V_38 ) ;
V_150 = - V_13 ;
goto exit;
}
V_38 = V_20 -> V_41 [ V_47 ] ;
switch ( V_20 -> type ) {
case V_194 :
case V_42 :
case V_195 :
if ( V_38 & V_196 ) {
F_7 ( V_2 , V_47 , 0 ) ;
F_39 ( & V_2 -> V_11 , L_37 ) ;
goto V_193;
}
break;
case V_197 :
if ( V_38 & V_196 )
F_7 ( V_2 , V_47 , 0 ) ;
if ( V_20 -> V_41 [ V_198 ] & V_199 ) {
F_7 ( V_2 , V_198 ,
V_20 -> V_41 [ V_198 ]
& ~ V_199 ) ;
F_39 ( & V_2 -> V_11 , L_37 ) ;
goto V_193;
}
break;
case V_63 :
if ( V_38 & V_200 )
F_7 ( V_2 , V_47 , 0 ) ;
V_38 = F_2 ( V_2 , V_201 ) ;
if ( V_38 < 0 ) {
F_4 ( & V_2 -> V_11 , L_36 , V_38 ) ;
V_150 = - V_13 ;
goto exit;
}
if ( V_38 & V_202 ) {
F_7 ( V_2 , V_201 , 0 ) ;
F_39 ( & V_2 -> V_11 , L_37 ) ;
}
break;
case V_68 :
if ( ! ( V_20 -> V_41 [ V_52 ] & V_70 ) ) {
F_7 ( V_2 , V_52 ,
V_20 -> V_41 [ V_52 ]
| V_70 ) ;
}
if ( ! ( V_38 & V_69 ) ) {
F_7 ( V_2 , V_47 ,
V_69 ) ;
F_39 ( & V_2 -> V_11 , L_37 ) ;
goto V_193;
}
break;
default:
break;
}
V_38 = V_20 -> V_41 [ V_49 ] ;
switch ( V_20 -> type ) {
case V_63 :
case V_42 :
case V_195 :
break;
case V_182 :
break;
default:
if ( ! ( V_38 & V_203 ) )
break;
V_38 = F_21 ( V_38 & 0x1f ) ;
if ( V_38 == 12 )
V_38 = 0 ;
if ( V_20 -> V_41 [ V_49 ] & V_190 )
V_38 += 12 ;
F_7 ( V_2 ,
V_20 -> V_40 + V_49 ,
F_25 ( V_38 ) ) ;
}
F_18 ( & V_2 -> V_11 , & V_160 ) ;
V_152 = V_160 . V_51 ;
V_161 = F_81 ( & V_160 ) ;
F_82 ( V_161 , & V_160 ) ;
if ( V_152 != V_160 . V_51 ) {
V_152 = F_2 ( V_2 , V_204 ) ;
V_152 = V_152 & ~ V_205 ;
V_152 = V_152 | ( V_160 . V_51 + 1 ) ;
F_7 ( V_2 , V_204 , V_152 ) ;
}
if ( V_156 ) {
F_83 ( & V_2 -> V_11 , true ) ;
F_84 ( V_73 , & V_20 -> V_74 ) ;
}
V_20 -> V_23 = F_85 ( & V_2 -> V_11 , V_2 -> V_118 ,
V_167 , V_206 ) ;
if ( F_47 ( V_20 -> V_23 ) ) {
return F_48 ( V_20 -> V_23 ) ;
}
if ( V_157 && V_20 -> V_2 -> V_18 <= 0 ) {
V_156 = false ;
F_86 ( & V_2 -> V_11 , L_41 ) ;
V_20 -> V_23 -> V_207 = 1 ;
}
if ( V_156 ) {
V_150 = F_87 ( & V_2 -> V_11 ,
V_2 -> V_18 , NULL , V_162 ,
V_208 | V_209 ,
V_20 -> V_23 -> V_118 , V_2 ) ;
if ( V_150 ) {
V_2 -> V_18 = 0 ;
F_83 ( & V_2 -> V_11 , false ) ;
F_88 ( V_73 , & V_20 -> V_74 ) ;
F_5 ( & V_2 -> V_11 , L_42 ) ;
} else
F_4 ( & V_2 -> V_11 , L_43 , V_2 -> V_18 ) ;
}
if ( V_110 -> V_210 ) {
V_20 -> V_211 = F_65 ( & V_2 -> V_11 ,
sizeof( struct V_96 ) ,
V_139 ) ;
if ( ! V_20 -> V_211 ) {
F_5 ( & V_2 -> V_11 , L_44 ) ;
} else {
V_20 -> V_211 -> V_97 . V_118 = L_45 ;
V_20 -> V_211 -> V_97 . V_212 = V_213 | V_214 ;
F_89 ( V_20 -> V_211 ) ;
V_20 -> V_211 -> V_215 = F_35 ;
V_20 -> V_211 -> V_216 = F_37 ;
V_20 -> V_211 -> V_217 = V_110 -> V_210 ;
V_20 -> V_100 = V_110 -> V_100 ;
V_150 = F_90 ( & V_2 -> V_11 . V_95 ,
V_20 -> V_211 ) ;
if ( V_150 ) {
F_5 ( & V_2 -> V_11 ,
L_46 ,
V_20 -> V_211 -> V_97 . V_118 ) ;
} else {
F_84 ( V_218 , & V_20 -> V_74 ) ;
F_86 ( & V_2 -> V_11 , L_47 ,
V_20 -> V_211 -> V_217 ) ;
}
}
}
F_45 ( V_20 ) ;
F_70 ( V_20 ) ;
return 0 ;
exit:
return V_150 ;
}
static int F_91 ( struct V_1 * V_2 )
{
struct V_20 * V_20 = F_14 ( V_2 ) ;
if ( F_92 ( V_218 , & V_20 -> V_74 ) )
F_93 ( & V_2 -> V_11 . V_95 , V_20 -> V_211 ) ;
return 0 ;
}
