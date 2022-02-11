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
if ( V_4 <= V_16 )
return F_9 ( V_2 ,
V_3 , V_4 , V_5 ) ;
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
V_37 -> V_42 = F_20 ( V_20 -> V_41 [ V_43 ] & 0x7f ) ;
V_37 -> V_44 = F_20 ( V_20 -> V_41 [ V_45 ] & 0x7f ) ;
V_38 = V_20 -> V_41 [ V_46 ] & 0x3f ;
V_37 -> V_47 = F_20 ( V_38 ) ;
V_37 -> V_48 = F_20 ( V_20 -> V_41 [ V_49 ] & 0x07 ) - 1 ;
V_37 -> V_50 = F_20 ( V_20 -> V_41 [ V_51 ] & 0x3f ) ;
V_38 = V_20 -> V_41 [ V_52 ] & 0x1f ;
V_37 -> V_53 = F_20 ( V_38 ) - 1 ;
V_37 -> V_54 = F_20 ( V_20 -> V_41 [ V_55 ] ) + 100 ;
F_4 ( V_11 , L_8
L_9 ,
L_6 , V_37 -> V_42 , V_37 -> V_44 ,
V_37 -> V_47 , V_37 -> V_50 ,
V_37 -> V_53 , V_37 -> V_54 , V_37 -> V_48 ) ;
return F_21 ( V_37 ) ;
}
static int F_22 ( struct V_35 * V_11 , struct V_36 * V_37 )
{
struct V_20 * V_20 = F_19 ( V_11 ) ;
int V_56 ;
int V_38 ;
T_2 * V_57 = V_20 -> V_41 ;
F_4 ( V_11 , L_8
L_9 ,
L_10 , V_37 -> V_42 , V_37 -> V_44 ,
V_37 -> V_47 , V_37 -> V_50 ,
V_37 -> V_53 , V_37 -> V_54 , V_37 -> V_48 ) ;
V_57 [ V_43 ] = F_23 ( V_37 -> V_42 ) ;
V_57 [ V_45 ] = F_23 ( V_37 -> V_44 ) ;
V_57 [ V_46 ] = F_23 ( V_37 -> V_47 ) ;
V_57 [ V_49 ] = F_23 ( V_37 -> V_48 + 1 ) ;
V_57 [ V_51 ] = F_23 ( V_37 -> V_50 ) ;
V_57 [ V_52 ] = F_23 ( V_37 -> V_53 + 1 ) ;
V_38 = V_37 -> V_54 - 100 ;
V_57 [ V_55 ] = F_23 ( V_38 ) ;
switch ( V_20 -> type ) {
case V_58 :
case V_59 :
case V_60 :
V_57 [ V_52 ] |= V_61 ;
break;
case V_62 :
V_57 [ V_46 ] |= V_63
| V_64 ;
break;
case V_65 :
V_57 [ V_43 ] |= V_66 ;
V_57 [ V_49 ] |= V_67 ;
break;
default:
break;
}
F_4 ( V_11 , L_7 , L_10 , V_57 ) ;
V_56 = V_20 -> V_68 ( V_20 -> V_2 ,
V_20 -> V_40 , 7 , V_57 ) ;
if ( V_56 < 0 ) {
F_5 ( V_11 , L_5 , L_10 , V_56 ) ;
return V_56 ;
}
return 0 ;
}
static int F_24 ( struct V_35 * V_11 , struct V_69 * V_37 )
{
struct V_1 * V_2 = F_25 ( V_11 ) ;
struct V_20 * V_20 = F_14 ( V_2 ) ;
int V_9 ;
if ( ! F_26 ( V_70 , & V_20 -> V_71 ) )
return - V_72 ;
V_9 = V_20 -> V_39 ( V_2 ,
V_73 , 9 , V_20 -> V_41 ) ;
if ( V_9 != 9 ) {
F_5 ( V_11 , L_5 , L_11 , V_9 ) ;
return - V_13 ;
}
F_4 ( V_11 , L_12 , L_11 ,
& V_20 -> V_41 [ 0 ] , & V_20 -> V_41 [ 4 ] , & V_20 -> V_41 [ 7 ] ) ;
V_37 -> time . V_42 = F_20 ( V_20 -> V_41 [ 0 ] & 0x7f ) ;
V_37 -> time . V_44 = F_20 ( V_20 -> V_41 [ 1 ] & 0x7f ) ;
V_37 -> time . V_47 = F_20 ( V_20 -> V_41 [ 2 ] & 0x3f ) ;
V_37 -> time . V_50 = F_20 ( V_20 -> V_41 [ 3 ] & 0x3f ) ;
V_37 -> time . V_53 = - 1 ;
V_37 -> time . V_54 = - 1 ;
V_37 -> time . V_48 = - 1 ;
V_37 -> time . V_74 = - 1 ;
V_37 -> time . V_75 = - 1 ;
V_37 -> V_76 = ! ! ( V_20 -> V_41 [ 7 ] & V_31 ) ;
V_37 -> V_77 = ! ! ( V_20 -> V_41 [ 8 ] & V_29 ) ;
F_4 ( V_11 , L_8
L_13 ,
L_11 , V_37 -> time . V_42 , V_37 -> time . V_44 ,
V_37 -> time . V_47 , V_37 -> time . V_50 ,
V_37 -> V_76 , V_37 -> V_77 ) ;
return 0 ;
}
static int F_27 ( struct V_35 * V_11 , struct V_69 * V_37 )
{
struct V_1 * V_2 = F_25 ( V_11 ) ;
struct V_20 * V_20 = F_14 ( V_2 ) ;
unsigned char * V_57 = V_20 -> V_41 ;
T_2 V_26 , V_78 ;
int V_9 ;
if ( ! F_26 ( V_70 , & V_20 -> V_71 ) )
return - V_72 ;
F_4 ( V_11 , L_8
L_13 ,
L_14 , V_37 -> time . V_42 , V_37 -> time . V_44 ,
V_37 -> time . V_47 , V_37 -> time . V_50 ,
V_37 -> V_76 , V_37 -> V_77 ) ;
V_9 = V_20 -> V_39 ( V_2 ,
V_73 , 9 , V_57 ) ;
if ( V_9 != 9 ) {
F_5 ( V_11 , L_5 , L_15 , V_9 ) ;
return - V_13 ;
}
V_26 = V_20 -> V_41 [ 7 ] ;
V_78 = V_20 -> V_41 [ 8 ] ;
F_4 ( V_11 , L_16 , L_17 ,
& V_20 -> V_41 [ 0 ] , & V_20 -> V_41 [ 4 ] , V_26 , V_78 ) ;
V_57 [ 0 ] = F_23 ( V_37 -> time . V_42 ) ;
V_57 [ 1 ] = F_23 ( V_37 -> time . V_44 ) ;
V_57 [ 2 ] = F_23 ( V_37 -> time . V_47 ) ;
V_57 [ 3 ] = F_23 ( V_37 -> time . V_50 ) ;
V_57 [ 4 ] = 0 ;
V_57 [ 5 ] = 0 ;
V_57 [ 6 ] = 0 ;
V_57 [ 7 ] = V_26 & ~ ( V_31 | V_79 ) ;
if ( V_37 -> V_76 ) {
F_4 ( V_11 , L_18 ) ;
V_57 [ 7 ] |= V_31 ;
}
V_57 [ 8 ] = V_78 & ~ ( V_29 | V_80 ) ;
V_9 = V_20 -> V_68 ( V_2 ,
V_73 , 9 , V_57 ) ;
if ( V_9 < 0 ) {
F_5 ( V_11 , L_19 ) ;
return V_9 ;
}
return 0 ;
}
static int F_28 ( struct V_35 * V_11 , unsigned int V_76 )
{
struct V_1 * V_2 = F_25 ( V_11 ) ;
struct V_20 * V_20 = F_14 ( V_2 ) ;
int V_9 ;
if ( ! F_26 ( V_70 , & V_20 -> V_71 ) )
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
static T_3 F_29 ( int V_18 , void * V_19 )
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
static int F_30 ( struct V_35 * V_11 , struct V_69 * V_37 )
{
struct V_1 * V_2 = F_25 ( V_11 ) ;
struct V_20 * V_20 = F_14 ( V_2 ) ;
T_2 * V_41 = V_20 -> V_41 ;
int V_9 ;
if ( ! F_26 ( V_70 , & V_20 -> V_71 ) )
return - V_72 ;
V_9 = V_20 -> V_39 ( V_2 , V_85 , 10 , V_41 ) ;
if ( V_9 < 0 )
return V_9 ;
V_37 -> V_76 = ! ! ( V_41 [ 0 ] & V_86 ) ;
V_37 -> time . V_42 = F_20 ( V_20 -> V_41 [ 3 ] & 0x7f ) ;
V_37 -> time . V_44 = F_20 ( V_20 -> V_41 [ 4 ] & 0x7f ) ;
V_37 -> time . V_47 = F_20 ( V_20 -> V_41 [ 5 ] & 0x3f ) ;
V_37 -> time . V_48 = F_20 ( V_20 -> V_41 [ 6 ] & 0x7 ) - 1 ;
V_37 -> time . V_50 = F_20 ( V_20 -> V_41 [ 7 ] & 0x3f ) ;
V_37 -> time . V_53 = F_20 ( V_20 -> V_41 [ 8 ] & 0x1f ) - 1 ;
V_37 -> time . V_54 = - 1 ;
V_37 -> time . V_74 = - 1 ;
V_37 -> time . V_75 = - 1 ;
F_4 ( V_11 , L_20
L_21 , V_87 ,
V_37 -> time . V_42 , V_37 -> time . V_44 , V_37 -> time . V_47 ,
V_37 -> time . V_48 , V_37 -> time . V_50 , V_37 -> time . V_53 , V_37 -> V_76 ,
! ! ( V_20 -> V_41 [ 6 ] & V_88 ) ,
! ! ( V_20 -> V_41 [ 6 ] & V_84 ) ,
( V_20 -> V_41 [ 6 ] & V_89 ) >> 4 ) ;
return 0 ;
}
static int F_31 ( struct V_35 * V_11 , struct V_69 * V_37 )
{
struct V_1 * V_2 = F_25 ( V_11 ) ;
struct V_20 * V_20 = F_14 ( V_2 ) ;
unsigned char * V_41 = V_20 -> V_41 ;
int V_9 ;
if ( ! F_26 ( V_70 , & V_20 -> V_71 ) )
return - V_72 ;
F_4 ( V_11 , L_20
L_22 , V_87 ,
V_37 -> time . V_42 , V_37 -> time . V_44 , V_37 -> time . V_47 ,
V_37 -> time . V_48 , V_37 -> time . V_50 , V_37 -> time . V_53 ,
V_37 -> V_76 , V_37 -> V_77 ) ;
V_9 = V_20 -> V_39 ( V_2 , V_85 , 10 , V_41 ) ;
if ( V_9 < 0 )
return V_9 ;
V_41 [ 3 ] = F_23 ( V_37 -> time . V_42 ) ;
V_41 [ 4 ] = F_23 ( V_37 -> time . V_44 ) ;
V_41 [ 5 ] = F_23 ( V_37 -> time . V_47 ) ;
V_41 [ 6 ] = F_23 ( V_37 -> time . V_48 + 1 ) ;
V_41 [ 7 ] = F_23 ( V_37 -> time . V_50 ) ;
V_41 [ 8 ] = F_23 ( V_37 -> time . V_53 + 1 ) ;
V_41 [ 6 ] &= ~ V_84 ;
V_41 [ 6 ] |= V_89 ;
V_41 [ 0 ] &= ~ V_86 ;
V_9 = V_20 -> V_68 ( V_2 , V_85 , 10 , V_41 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( ! V_37 -> V_76 )
return 0 ;
V_41 [ 0 ] |= V_86 ;
return F_7 ( V_2 , V_85 , V_41 [ 0 ] ) ;
}
static int F_32 ( struct V_35 * V_11 , unsigned int V_76 )
{
struct V_1 * V_2 = F_25 ( V_11 ) ;
struct V_20 * V_20 = F_14 ( V_2 ) ;
int V_82 ;
if ( ! F_26 ( V_70 , & V_20 -> V_71 ) )
return - V_72 ;
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
F_33 ( struct V_90 * V_91 , struct V_92 * V_93 ,
struct V_94 * V_95 ,
char * V_57 , T_5 V_96 , T_6 V_97 )
{
struct V_1 * V_2 ;
struct V_20 * V_20 ;
int V_56 ;
V_2 = F_34 ( V_93 ) ;
V_20 = F_14 ( V_2 ) ;
V_56 = V_20 -> V_39 ( V_2 , V_20 -> V_98 + V_96 ,
V_97 , V_57 ) ;
if ( V_56 < 0 )
F_5 ( & V_2 -> V_11 , L_5 , L_23 , V_56 ) ;
return V_56 ;
}
static T_4
F_35 ( struct V_90 * V_91 , struct V_92 * V_93 ,
struct V_94 * V_95 ,
char * V_57 , T_5 V_96 , T_6 V_97 )
{
struct V_1 * V_2 ;
struct V_20 * V_20 ;
int V_56 ;
V_2 = F_34 ( V_93 ) ;
V_20 = F_14 ( V_2 ) ;
V_56 = V_20 -> V_68 ( V_2 , V_20 -> V_98 + V_96 ,
V_97 , V_57 ) ;
if ( V_56 < 0 ) {
F_5 ( & V_2 -> V_11 , L_5 , L_24 , V_56 ) ;
return V_56 ;
}
return V_97 ;
}
static T_2 F_36 ( struct V_1 * V_2 ,
T_7 V_99 , bool V_100 )
{
T_2 V_101 = ( V_100 ) ? V_102 :
V_103 ;
switch ( V_99 ) {
case 250 :
V_101 |= V_104 ;
break;
case 2000 :
V_101 |= V_105 ;
break;
case 4000 :
V_101 |= V_106 ;
break;
default:
F_37 ( & V_2 -> V_11 ,
L_25 , V_99 ) ;
return 0 ;
}
return V_101 ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_107 * V_108 )
{
T_7 V_99 = 0 ;
bool V_100 = true ;
if ( ! V_108 -> V_109 )
goto V_28;
if ( F_39 ( V_2 -> V_11 . V_110 , L_26 , & V_99 ) )
goto V_28;
if ( F_40 ( V_2 -> V_11 . V_110 , L_27 ) )
V_100 = false ;
V_108 -> V_111 = V_108 -> V_109 ( V_2 ,
V_99 , V_100 ) ;
V_28:
return;
}
static int F_41 ( struct V_35 * V_11 , T_1 * V_112 )
{
struct V_20 * V_20 = F_19 ( V_11 ) ;
T_2 V_113 [ 2 ] ;
T_8 V_114 ;
int V_9 ;
V_9 = V_20 -> V_39 ( V_20 -> V_2 , V_115 ,
sizeof( V_113 ) , V_113 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 != sizeof( V_113 ) )
return - V_13 ;
V_114 = ( V_113 [ 0 ] << 8 ) | V_113 [ 1 ] ;
V_114 >>= 6 ;
* V_112 = V_114 * 250 ;
return 0 ;
}
static T_4 F_42 ( struct V_35 * V_11 ,
struct V_116 * V_95 , char * V_57 )
{
int V_9 ;
T_1 V_114 ;
V_9 = F_41 ( V_11 , & V_114 ) ;
if ( V_9 )
return V_9 ;
return sprintf ( V_57 , L_28 , V_114 ) ;
}
static void F_43 ( struct V_20 * V_20 )
{
struct V_35 * V_11 ;
if ( V_20 -> type != V_60 )
return;
V_11 = F_44 ( & V_20 -> V_2 -> V_11 ,
V_20 -> V_2 -> V_117 ,
V_20 , V_118 ) ;
if ( F_45 ( V_11 ) ) {
F_37 ( & V_20 -> V_2 -> V_11 ,
L_29 , F_46 ( V_11 ) ) ;
}
}
static void F_43 ( struct V_20 * V_20 )
{
}
static int F_47 ( struct V_20 * V_20 , T_2 V_119 , T_2 V_120 )
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
V_26 &= ~ V_119 ;
V_26 |= V_120 ;
V_9 = F_7 ( V_2 , V_30 , V_26 ) ;
V_28:
F_17 ( V_22 ) ;
return V_9 ;
}
static unsigned long F_48 ( struct V_121 * V_122 ,
unsigned long V_123 )
{
struct V_20 * V_20 = F_49 ( V_122 ) ;
int V_26 ;
int V_124 = 0 ;
V_26 = F_2 ( V_20 -> V_2 , V_30 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_26 & V_125 )
V_124 += 1 ;
if ( V_26 & V_126 )
V_124 += 2 ;
return V_127 [ V_124 ] ;
}
static long F_50 ( struct V_121 * V_122 , unsigned long V_128 ,
unsigned long * V_129 )
{
int V_6 ;
for ( V_6 = F_51 ( V_127 ) - 1 ; V_6 >= 0 ; V_6 -- ) {
if ( V_127 [ V_6 ] <= V_128 )
return V_127 [ V_6 ] ;
}
return 0 ;
}
static int F_52 ( struct V_121 * V_122 , unsigned long V_128 ,
unsigned long V_123 )
{
struct V_20 * V_20 = F_49 ( V_122 ) ;
int V_26 = 0 ;
int V_124 ;
for ( V_124 = 0 ; V_124 < F_51 ( V_127 ) ;
V_124 ++ ) {
if ( V_127 [ V_124 ] == V_128 )
break;
}
if ( V_124 == F_51 ( V_127 ) )
return - V_72 ;
if ( V_124 & 1 )
V_26 |= V_125 ;
if ( V_124 & 2 )
V_26 |= V_126 ;
return F_47 ( V_20 , V_125 | V_126 ,
V_26 ) ;
}
static int F_53 ( struct V_121 * V_122 )
{
struct V_20 * V_20 = F_49 ( V_122 ) ;
return F_47 ( V_20 , V_130 , 0 ) ;
}
static void F_54 ( struct V_121 * V_122 )
{
struct V_20 * V_20 = F_49 ( V_122 ) ;
F_47 ( V_20 , V_130 , V_130 ) ;
}
static int F_55 ( struct V_121 * V_122 )
{
struct V_20 * V_20 = F_49 ( V_122 ) ;
int V_26 ;
V_26 = F_2 ( V_20 -> V_2 , V_30 ) ;
if ( V_26 < 0 )
return V_26 ;
return ! ( V_26 & V_130 ) ;
}
static unsigned long F_56 ( struct V_121 * V_122 ,
unsigned long V_123 )
{
return 32768 ;
}
static int F_57 ( struct V_20 * V_20 , bool V_131 )
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
if ( V_131 )
V_78 |= V_132 ;
else
V_78 &= ~ V_132 ;
V_9 = F_7 ( V_2 , V_27 , V_78 ) ;
V_28:
F_17 ( V_22 ) ;
return V_9 ;
}
static int F_58 ( struct V_121 * V_122 )
{
struct V_20 * V_20 = F_59 ( V_122 ) ;
return F_57 ( V_20 , true ) ;
}
static void F_60 ( struct V_121 * V_122 )
{
struct V_20 * V_20 = F_59 ( V_122 ) ;
F_57 ( V_20 , false ) ;
}
static int F_61 ( struct V_121 * V_122 )
{
struct V_20 * V_20 = F_59 ( V_122 ) ;
int V_78 ;
V_78 = F_2 ( V_20 -> V_2 , V_27 ) ;
if ( V_78 < 0 )
return V_78 ;
return ! ! ( V_78 & V_132 ) ;
}
static int F_62 ( struct V_20 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_133 * V_134 = V_2 -> V_11 . V_110 ;
struct V_135 * V_136 ;
int V_6 ;
V_136 = F_63 ( & V_2 -> V_11 , sizeof( * V_136 ) , V_137 ) ;
if ( ! V_136 )
return - V_138 ;
V_136 -> V_139 = F_51 ( V_140 ) ;
V_136 -> V_141 = F_64 ( & V_2 -> V_11 , V_136 -> V_139 ,
sizeof( V_136 -> V_141 [ 0 ] ) , V_137 ) ;
if ( ! V_136 -> V_141 )
return - V_138 ;
for ( V_6 = 0 ; V_6 < F_51 ( V_140 ) ; V_6 ++ ) {
struct V_142 V_143 = V_140 [ V_6 ] ;
if ( V_6 == V_144 && F_26 ( V_70 , & V_20 -> V_71 ) )
continue;
F_65 ( V_134 , L_30 , V_6 ,
& V_143 . V_117 ) ;
V_20 -> V_141 [ V_6 ] . V_143 = & V_143 ;
V_136 -> V_141 [ V_6 ] = F_66 ( & V_2 -> V_11 ,
& V_20 -> V_141 [ V_6 ] ) ;
if ( F_45 ( V_136 -> V_141 [ V_6 ] ) )
return F_46 ( V_136 -> V_141 [ V_6 ] ) ;
}
if ( ! V_134 )
return 0 ;
F_67 ( V_134 , V_145 , V_136 ) ;
return 0 ;
}
static void F_68 ( struct V_20 * V_20 )
{
int V_9 ;
if ( V_20 -> type != V_60 )
return;
V_9 = F_62 ( V_20 ) ;
if ( V_9 ) {
F_37 ( & V_20 -> V_2 -> V_11 ,
L_31 , V_9 ) ;
}
}
static void F_68 ( struct V_20 * V_20 )
{
}
static int F_69 ( struct V_1 * V_2 ,
const struct V_146 * V_147 )
{
struct V_20 * V_20 ;
int V_148 = - V_149 ;
int V_38 ;
struct V_107 * V_108 = & V_150 [ V_147 -> V_151 ] ;
struct V_152 * V_153 = F_70 ( V_2 -> V_11 . V_154 ) ;
bool V_155 = false ;
bool V_156 = false ;
unsigned char * V_57 ;
struct V_157 * V_158 = F_71 ( & V_2 -> V_11 ) ;
T_9 V_159 = F_13 ;
static const int V_160 [] = {
[ V_58 ] = 0 ,
[ V_59 ] = V_161 ,
[ V_60 ] = V_162 ,
} ;
const struct V_163 * V_164 = & V_165 ;
if ( ! F_72 ( V_153 , V_166 )
&& ! F_72 ( V_153 , V_167 ) )
return - V_13 ;
V_20 = F_63 ( & V_2 -> V_11 , sizeof( struct V_20 ) , V_137 ) ;
if ( ! V_20 )
return - V_138 ;
F_73 ( V_2 , V_20 ) ;
V_20 -> V_2 = V_2 ;
V_20 -> type = V_147 -> V_151 ;
if ( ! V_158 && V_2 -> V_11 . V_110 )
F_38 ( V_2 , V_108 ) ;
else if ( V_158 && V_158 -> V_111 )
V_108 -> V_111 = V_158 -> V_111 ;
if ( V_108 -> V_111 && V_108 -> V_168 ) {
F_4 ( & V_2 -> V_11 , L_32 ,
V_169 | V_108 -> V_111 ,
V_108 -> V_168 ) ;
F_7 ( V_2 , V_108 -> V_168 ,
V_169 |
V_108 -> V_111 ) ;
}
V_57 = V_20 -> V_41 ;
if ( F_72 ( V_153 , V_167 ) ) {
V_20 -> V_39 = F_11 ;
V_20 -> V_68 = F_8 ;
} else {
V_20 -> V_39 = F_3 ;
V_20 -> V_68 = F_6 ;
}
#ifdef F_74
if ( F_40 ( V_2 -> V_11 . V_110 , L_33 ) ) {
V_156 = true ;
}
#endif
switch ( V_20 -> type ) {
case V_58 :
case V_59 :
case V_60 :
V_38 = V_20 -> V_39 ( V_20 -> V_2 ,
V_30 , 2 , V_57 ) ;
if ( V_38 != 2 ) {
F_4 ( & V_2 -> V_11 , L_34 , V_38 ) ;
V_148 = - V_13 ;
goto exit;
}
if ( V_20 -> V_41 [ 0 ] & V_170 )
V_20 -> V_41 [ 0 ] &= ~ V_170 ;
if ( V_108 -> V_171 && ( V_20 -> V_2 -> V_18 > 0 ||
V_156 ) ) {
V_20 -> V_41 [ 0 ] |= V_130
| V_160 [ V_20 -> type ] ;
V_20 -> V_41 [ 0 ] &= ~ ( V_79 | V_31 ) ;
V_155 = true ;
}
F_7 ( V_2 , V_30 ,
V_20 -> V_41 [ 0 ] ) ;
if ( V_20 -> V_41 [ 1 ] & V_172 ) {
F_7 ( V_2 , V_27 ,
V_20 -> V_41 [ 1 ] & ~ V_172 ) ;
F_37 ( & V_2 -> V_11 , L_35 ) ;
}
break;
case V_173 :
V_38 = F_12 ( V_20 -> V_2 ,
V_174 << 4 | 0x08 , 2 , V_57 ) ;
if ( V_38 != 2 ) {
F_4 ( & V_2 -> V_11 , L_34 , V_38 ) ;
V_148 = - V_13 ;
goto exit;
}
if ( ! ( V_20 -> V_41 [ 1 ] & V_175 ) ) {
V_20 -> V_41 [ 1 ] |= V_175 ;
F_7 ( V_2 ,
V_176 << 4 | 0x08 ,
V_20 -> V_41 [ 1 ] ) ;
F_37 ( & V_2 -> V_11 ,
L_36 ) ;
}
if ( V_20 -> V_41 [ 1 ] & V_177 ) {
V_20 -> V_41 [ 1 ] &= ~ V_177 ;
F_7 ( V_2 ,
V_176 << 4 | 0x08 ,
V_20 -> V_41 [ 1 ] ) ;
F_37 ( & V_2 -> V_11 , L_37 ) ;
}
if ( V_20 -> V_41 [ 1 ] & V_178 ) {
V_20 -> V_41 [ 1 ] &= ~ V_178 ;
F_7 ( V_2 ,
V_176 << 4 | 0x08 ,
V_20 -> V_41 [ 1 ] ) ;
F_37 ( & V_2 -> V_11 , L_38 ) ;
}
if ( ! ( V_20 -> V_41 [ 0 ] & V_179 ) ) {
T_2 V_180 ;
F_7 ( V_2 ,
V_174 << 4 | 0x08 ,
V_20 -> V_41 [ 0 ] |
V_179 ) ;
V_38 = F_12 ( V_20 -> V_2 ,
V_174 << 4 | 0x08 , 2 , V_57 ) ;
if ( V_38 != 2 ) {
F_4 ( & V_2 -> V_11 , L_34 , V_38 ) ;
V_148 = - V_13 ;
goto exit;
}
V_180 = F_20 ( V_20 -> V_41 [ V_46 ] ) ;
if ( V_180 == 12 )
V_180 = 0 ;
if ( V_20 -> V_41 [ V_46 ] & V_181 )
V_180 += 12 ;
F_7 ( V_2 ,
V_46 << 4 | 0x08 ,
V_180 ) ;
}
break;
case V_182 :
V_20 -> V_40 = 1 ;
break;
case V_65 :
V_164 = & V_183 ;
if ( V_20 -> V_2 -> V_18 > 0 && V_108 -> V_171 ) {
V_159 = F_29 ;
V_155 = true ;
}
break;
default:
break;
}
V_184:
V_38 = V_20 -> V_39 ( V_20 -> V_2 , V_20 -> V_40 , 8 , V_57 ) ;
if ( V_38 != 8 ) {
F_4 ( & V_2 -> V_11 , L_34 , V_38 ) ;
V_148 = - V_13 ;
goto exit;
}
V_38 = V_20 -> V_41 [ V_43 ] ;
switch ( V_20 -> type ) {
case V_185 :
case V_186 :
if ( V_38 & V_187 ) {
F_7 ( V_2 , V_43 , 0 ) ;
F_37 ( & V_2 -> V_11 , L_35 ) ;
goto V_184;
}
break;
case V_188 :
if ( V_38 & V_187 )
F_7 ( V_2 , V_43 , 0 ) ;
if ( V_20 -> V_41 [ V_189 ] & V_190 ) {
F_7 ( V_2 , V_189 ,
V_20 -> V_41 [ V_189 ]
& ~ V_190 ) ;
F_37 ( & V_2 -> V_11 , L_35 ) ;
goto V_184;
}
break;
case V_62 :
if ( V_38 & V_191 )
F_7 ( V_2 , V_43 , 0 ) ;
V_38 = F_2 ( V_2 , V_192 ) ;
if ( V_38 < 0 ) {
F_4 ( & V_2 -> V_11 , L_34 , V_38 ) ;
V_148 = - V_13 ;
goto exit;
}
if ( V_38 & V_193 ) {
F_7 ( V_2 , V_192 , 0 ) ;
F_37 ( & V_2 -> V_11 , L_35 ) ;
}
break;
case V_65 :
if ( ! ( V_20 -> V_41 [ V_49 ] & V_67 ) ) {
F_7 ( V_2 , V_49 ,
V_20 -> V_41 [ V_49 ]
| V_67 ) ;
}
if ( ! ( V_38 & V_66 ) ) {
F_7 ( V_2 , V_43 ,
V_66 ) ;
F_37 ( & V_2 -> V_11 , L_35 ) ;
goto V_184;
}
break;
default:
break;
}
V_38 = V_20 -> V_41 [ V_46 ] ;
switch ( V_20 -> type ) {
case V_62 :
case V_186 :
break;
case V_173 :
break;
default:
if ( ! ( V_38 & V_194 ) )
break;
V_38 = F_20 ( V_38 & 0x1f ) ;
if ( V_38 == 12 )
V_38 = 0 ;
if ( V_20 -> V_41 [ V_46 ] & V_181 )
V_38 += 12 ;
F_7 ( V_2 ,
V_20 -> V_40 + V_46 ,
F_23 ( V_38 ) ) ;
}
if ( V_155 ) {
F_75 ( & V_2 -> V_11 , true ) ;
F_76 ( V_70 , & V_20 -> V_71 ) ;
}
V_20 -> V_23 = F_77 ( & V_2 -> V_11 , V_2 -> V_117 ,
V_164 , V_195 ) ;
if ( F_45 ( V_20 -> V_23 ) ) {
return F_46 ( V_20 -> V_23 ) ;
}
if ( V_156 && V_20 -> V_2 -> V_18 <= 0 ) {
V_155 = false ;
F_78 ( & V_2 -> V_11 , L_39 ) ;
V_20 -> V_23 -> V_196 = 1 ;
}
if ( V_155 ) {
V_148 = F_79 ( & V_2 -> V_11 ,
V_2 -> V_18 , NULL , V_159 ,
V_197 | V_198 ,
V_20 -> V_23 -> V_117 , V_2 ) ;
if ( V_148 ) {
V_2 -> V_18 = 0 ;
F_75 ( & V_2 -> V_11 , false ) ;
F_80 ( V_70 , & V_20 -> V_71 ) ;
F_5 ( & V_2 -> V_11 , L_40 ) ;
} else
F_4 ( & V_2 -> V_11 , L_41 , V_2 -> V_18 ) ;
}
if ( V_108 -> V_199 ) {
V_20 -> V_200 = F_63 ( & V_2 -> V_11 ,
sizeof( struct V_94 ) ,
V_137 ) ;
if ( ! V_20 -> V_200 ) {
F_5 ( & V_2 -> V_11 , L_42 ) ;
} else {
V_20 -> V_200 -> V_95 . V_117 = L_43 ;
V_20 -> V_200 -> V_95 . V_201 = V_202 | V_203 ;
F_81 ( V_20 -> V_200 ) ;
V_20 -> V_200 -> V_204 = F_33 ;
V_20 -> V_200 -> V_205 = F_35 ;
V_20 -> V_200 -> V_206 = V_108 -> V_199 ;
V_20 -> V_98 = V_108 -> V_98 ;
V_148 = F_82 ( & V_2 -> V_11 . V_93 ,
V_20 -> V_200 ) ;
if ( V_148 ) {
F_5 ( & V_2 -> V_11 ,
L_44 ,
V_20 -> V_200 -> V_95 . V_117 ) ;
} else {
F_76 ( V_207 , & V_20 -> V_71 ) ;
F_78 ( & V_2 -> V_11 , L_45 ,
V_20 -> V_200 -> V_206 ) ;
}
}
}
F_43 ( V_20 ) ;
F_68 ( V_20 ) ;
return 0 ;
exit:
return V_148 ;
}
static int F_83 ( struct V_1 * V_2 )
{
struct V_20 * V_20 = F_14 ( V_2 ) ;
if ( F_84 ( V_207 , & V_20 -> V_71 ) )
F_85 ( & V_2 -> V_11 . V_93 , V_20 -> V_200 ) ;
return 0 ;
}
