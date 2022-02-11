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
V_37 -> V_42 = F_20 ( V_20 -> V_41 [ V_43 ] & 0x7f ) ;
V_37 -> V_44 = F_20 ( V_20 -> V_41 [ V_45 ] & 0x7f ) ;
V_38 = V_20 -> V_41 [ V_46 ] & 0x3f ;
V_37 -> V_47 = F_20 ( V_38 ) ;
V_37 -> V_48 = F_20 ( V_20 -> V_41 [ V_49 ] & 0x07 ) - 1 ;
V_37 -> V_50 = F_20 ( V_20 -> V_41 [ V_51 ] & 0x3f ) ;
V_38 = V_20 -> V_41 [ V_52 ] & 0x1f ;
V_37 -> V_53 = F_20 ( V_38 ) - 1 ;
V_37 -> V_54 = F_20 ( V_20 -> V_41 [ V_55 ] ) + 100 ;
#ifdef F_21
switch ( V_20 -> type ) {
case V_56 :
case V_57 :
case V_58 :
if ( V_20 -> V_41 [ V_52 ] & V_59 )
V_37 -> V_54 += 100 ;
break;
case V_60 :
if ( V_20 -> V_41 [ V_46 ] & V_61 )
V_37 -> V_54 += 100 ;
break;
default:
break;
}
#endif
F_4 ( V_11 , L_8
L_9 ,
L_6 , V_37 -> V_42 , V_37 -> V_44 ,
V_37 -> V_47 , V_37 -> V_50 ,
V_37 -> V_53 , V_37 -> V_54 , V_37 -> V_48 ) ;
return F_22 ( V_37 ) ;
}
static int F_23 ( struct V_35 * V_11 , struct V_36 * V_37 )
{
struct V_20 * V_20 = F_19 ( V_11 ) ;
int V_62 ;
int V_38 ;
T_2 * V_63 = V_20 -> V_41 ;
F_4 ( V_11 , L_8
L_9 ,
L_10 , V_37 -> V_42 , V_37 -> V_44 ,
V_37 -> V_47 , V_37 -> V_50 ,
V_37 -> V_53 , V_37 -> V_54 , V_37 -> V_48 ) ;
#ifdef F_21
if ( V_37 -> V_54 < 100 )
return - V_64 ;
switch ( V_20 -> type ) {
case V_56 :
case V_57 :
case V_58 :
case V_60 :
if ( V_37 -> V_54 > 299 )
return - V_64 ;
default:
if ( V_37 -> V_54 > 199 )
return - V_64 ;
break;
}
#else
if ( V_37 -> V_54 < 100 || V_37 -> V_54 > 199 )
return - V_64 ;
#endif
V_63 [ V_43 ] = F_24 ( V_37 -> V_42 ) ;
V_63 [ V_45 ] = F_24 ( V_37 -> V_44 ) ;
V_63 [ V_46 ] = F_24 ( V_37 -> V_47 ) ;
V_63 [ V_49 ] = F_24 ( V_37 -> V_48 + 1 ) ;
V_63 [ V_51 ] = F_24 ( V_37 -> V_50 ) ;
V_63 [ V_52 ] = F_24 ( V_37 -> V_53 + 1 ) ;
V_38 = V_37 -> V_54 - 100 ;
V_63 [ V_55 ] = F_24 ( V_38 ) ;
switch ( V_20 -> type ) {
case V_56 :
case V_57 :
case V_58 :
if ( V_37 -> V_54 > 199 )
V_63 [ V_52 ] |= V_59 ;
break;
case V_60 :
V_63 [ V_46 ] |= V_65 ;
if ( V_37 -> V_54 > 199 )
V_63 [ V_46 ] |= V_61 ;
break;
case V_66 :
V_63 [ V_43 ] |= V_67 ;
V_63 [ V_49 ] |= V_68 ;
break;
default:
break;
}
F_4 ( V_11 , L_7 , L_10 , V_63 ) ;
V_62 = V_20 -> V_69 ( V_20 -> V_2 ,
V_20 -> V_40 , 7 , V_63 ) ;
if ( V_62 < 0 ) {
F_5 ( V_11 , L_5 , L_10 , V_62 ) ;
return V_62 ;
}
return 0 ;
}
static int F_25 ( struct V_35 * V_11 , struct V_70 * V_37 )
{
struct V_1 * V_2 = F_26 ( V_11 ) ;
struct V_20 * V_20 = F_14 ( V_2 ) ;
int V_9 ;
if ( ! F_27 ( V_71 , & V_20 -> V_72 ) )
return - V_64 ;
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
V_37 -> V_74 = ! ! ( V_20 -> V_41 [ 7 ] & V_31 ) ;
V_37 -> V_75 = ! ! ( V_20 -> V_41 [ 8 ] & V_29 ) ;
F_4 ( V_11 , L_8
L_13 ,
L_11 , V_37 -> time . V_42 , V_37 -> time . V_44 ,
V_37 -> time . V_47 , V_37 -> time . V_50 ,
V_37 -> V_74 , V_37 -> V_75 ) ;
return 0 ;
}
static int F_28 ( struct V_35 * V_11 , struct V_70 * V_37 )
{
struct V_1 * V_2 = F_26 ( V_11 ) ;
struct V_20 * V_20 = F_14 ( V_2 ) ;
unsigned char * V_63 = V_20 -> V_41 ;
T_2 V_26 , V_76 ;
int V_9 ;
if ( ! F_27 ( V_71 , & V_20 -> V_72 ) )
return - V_64 ;
F_4 ( V_11 , L_8
L_13 ,
L_14 , V_37 -> time . V_42 , V_37 -> time . V_44 ,
V_37 -> time . V_47 , V_37 -> time . V_50 ,
V_37 -> V_74 , V_37 -> V_75 ) ;
V_9 = V_20 -> V_39 ( V_2 ,
V_73 , 9 , V_63 ) ;
if ( V_9 != 9 ) {
F_5 ( V_11 , L_5 , L_15 , V_9 ) ;
return - V_13 ;
}
V_26 = V_20 -> V_41 [ 7 ] ;
V_76 = V_20 -> V_41 [ 8 ] ;
F_4 ( V_11 , L_16 , L_17 ,
& V_20 -> V_41 [ 0 ] , & V_20 -> V_41 [ 4 ] , V_26 , V_76 ) ;
V_63 [ 0 ] = F_24 ( V_37 -> time . V_42 ) ;
V_63 [ 1 ] = F_24 ( V_37 -> time . V_44 ) ;
V_63 [ 2 ] = F_24 ( V_37 -> time . V_47 ) ;
V_63 [ 3 ] = F_24 ( V_37 -> time . V_50 ) ;
V_63 [ 4 ] = 0 ;
V_63 [ 5 ] = 0 ;
V_63 [ 6 ] = 0 ;
V_63 [ 7 ] = V_26 & ~ ( V_31 | V_77 ) ;
V_63 [ 8 ] = V_76 & ~ ( V_29 | V_78 ) ;
V_9 = V_20 -> V_69 ( V_2 ,
V_73 , 9 , V_63 ) ;
if ( V_9 < 0 ) {
F_5 ( V_11 , L_18 ) ;
return V_9 ;
}
if ( V_37 -> V_74 ) {
F_4 ( V_11 , L_19 ) ;
V_63 [ 7 ] |= V_31 ;
F_7 ( V_2 , V_30 , V_63 [ 7 ] ) ;
}
return 0 ;
}
static int F_29 ( struct V_35 * V_11 , unsigned int V_74 )
{
struct V_1 * V_2 = F_26 ( V_11 ) ;
struct V_20 * V_20 = F_14 ( V_2 ) ;
int V_9 ;
if ( ! F_27 ( V_71 , & V_20 -> V_72 ) )
return - V_79 ;
V_9 = F_2 ( V_2 , V_30 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_74 )
V_9 |= V_31 ;
else
V_9 &= ~ V_31 ;
V_9 = F_7 ( V_2 , V_30 , V_9 ) ;
if ( V_9 < 0 )
return V_9 ;
return 0 ;
}
static T_3 F_30 ( int V_18 , void * V_19 )
{
struct V_1 * V_2 = V_19 ;
struct V_20 * V_20 = F_14 ( V_2 ) ;
struct V_21 * V_22 = & V_20 -> V_23 -> V_24 ;
int V_80 , V_9 ;
F_15 ( V_22 ) ;
V_80 = F_2 ( V_2 , V_81 ) ;
if ( V_80 < 0 )
goto V_28;
if ( ! ( V_80 & V_82 ) )
goto V_28;
V_80 &= ~ V_82 ;
V_9 = F_7 ( V_2 , V_81 , V_80 ) ;
if ( V_9 < 0 )
goto V_28;
V_80 = F_2 ( V_2 , V_83 ) ;
if ( V_80 < 0 )
goto V_28;
V_80 &= ~ V_84 ;
V_9 = F_7 ( V_2 , V_83 , V_80 ) ;
if ( V_9 < 0 )
goto V_28;
F_16 ( V_20 -> V_23 , 1 , V_32 | V_33 ) ;
V_28:
F_17 ( V_22 ) ;
return V_34 ;
}
static int F_31 ( struct V_35 * V_11 , struct V_70 * V_37 )
{
struct V_1 * V_2 = F_26 ( V_11 ) ;
struct V_20 * V_20 = F_14 ( V_2 ) ;
T_2 * V_41 = V_20 -> V_41 ;
int V_9 ;
if ( ! F_27 ( V_71 , & V_20 -> V_72 ) )
return - V_64 ;
V_9 = V_20 -> V_39 ( V_2 , V_83 , 10 , V_41 ) ;
if ( V_9 < 0 )
return V_9 ;
V_37 -> V_74 = ! ! ( V_41 [ 0 ] & V_84 ) ;
V_37 -> time . V_42 = F_20 ( V_20 -> V_41 [ 3 ] & 0x7f ) ;
V_37 -> time . V_44 = F_20 ( V_20 -> V_41 [ 4 ] & 0x7f ) ;
V_37 -> time . V_47 = F_20 ( V_20 -> V_41 [ 5 ] & 0x3f ) ;
V_37 -> time . V_48 = F_20 ( V_20 -> V_41 [ 6 ] & 0x7 ) - 1 ;
V_37 -> time . V_50 = F_20 ( V_20 -> V_41 [ 7 ] & 0x3f ) ;
V_37 -> time . V_53 = F_20 ( V_20 -> V_41 [ 8 ] & 0x1f ) - 1 ;
V_37 -> time . V_54 = - 1 ;
V_37 -> time . V_85 = - 1 ;
V_37 -> time . V_86 = - 1 ;
F_4 ( V_11 , L_20
L_21 , V_87 ,
V_37 -> time . V_42 , V_37 -> time . V_44 , V_37 -> time . V_47 ,
V_37 -> time . V_48 , V_37 -> time . V_50 , V_37 -> time . V_53 , V_37 -> V_74 ,
! ! ( V_20 -> V_41 [ 6 ] & V_88 ) ,
! ! ( V_20 -> V_41 [ 6 ] & V_82 ) ,
( V_20 -> V_41 [ 6 ] & V_89 ) >> 4 ) ;
return 0 ;
}
static int F_32 ( struct V_35 * V_11 , struct V_70 * V_37 )
{
struct V_1 * V_2 = F_26 ( V_11 ) ;
struct V_20 * V_20 = F_14 ( V_2 ) ;
unsigned char * V_41 = V_20 -> V_41 ;
int V_9 ;
if ( ! F_27 ( V_71 , & V_20 -> V_72 ) )
return - V_64 ;
F_4 ( V_11 , L_20
L_22 , V_87 ,
V_37 -> time . V_42 , V_37 -> time . V_44 , V_37 -> time . V_47 ,
V_37 -> time . V_48 , V_37 -> time . V_50 , V_37 -> time . V_53 ,
V_37 -> V_74 , V_37 -> V_75 ) ;
V_9 = V_20 -> V_39 ( V_2 , V_83 , 10 , V_41 ) ;
if ( V_9 < 0 )
return V_9 ;
V_41 [ 3 ] = F_24 ( V_37 -> time . V_42 ) ;
V_41 [ 4 ] = F_24 ( V_37 -> time . V_44 ) ;
V_41 [ 5 ] = F_24 ( V_37 -> time . V_47 ) ;
V_41 [ 6 ] = F_24 ( V_37 -> time . V_48 + 1 ) ;
V_41 [ 7 ] = F_24 ( V_37 -> time . V_50 ) ;
V_41 [ 8 ] = F_24 ( V_37 -> time . V_53 + 1 ) ;
V_41 [ 6 ] &= ~ V_82 ;
V_41 [ 6 ] |= V_89 ;
V_41 [ 0 ] &= ~ V_84 ;
V_9 = V_20 -> V_69 ( V_2 , V_83 , 10 , V_41 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( ! V_37 -> V_74 )
return 0 ;
V_41 [ 0 ] |= V_84 ;
return F_7 ( V_2 , V_83 , V_41 [ 0 ] ) ;
}
static int F_33 ( struct V_35 * V_11 , unsigned int V_74 )
{
struct V_1 * V_2 = F_26 ( V_11 ) ;
struct V_20 * V_20 = F_14 ( V_2 ) ;
int V_80 ;
if ( ! F_27 ( V_71 , & V_20 -> V_72 ) )
return - V_64 ;
V_80 = F_2 ( V_2 , V_83 ) ;
if ( V_80 < 0 )
return V_80 ;
if ( V_74 )
V_80 |= V_84 ;
else
V_80 &= ~ V_84 ;
return F_7 ( V_2 , V_83 , V_80 ) ;
}
static T_4
F_34 ( struct V_90 * V_91 , struct V_92 * V_93 ,
struct V_94 * V_95 ,
char * V_63 , T_5 V_96 , T_6 V_97 )
{
struct V_1 * V_2 ;
struct V_20 * V_20 ;
int V_62 ;
V_2 = F_35 ( V_93 ) ;
V_20 = F_14 ( V_2 ) ;
V_62 = V_20 -> V_39 ( V_2 , V_20 -> V_98 + V_96 ,
V_97 , V_63 ) ;
if ( V_62 < 0 )
F_5 ( & V_2 -> V_11 , L_5 , L_23 , V_62 ) ;
return V_62 ;
}
static T_4
F_36 ( struct V_90 * V_91 , struct V_92 * V_93 ,
struct V_94 * V_95 ,
char * V_63 , T_5 V_96 , T_6 V_97 )
{
struct V_1 * V_2 ;
struct V_20 * V_20 ;
int V_62 ;
V_2 = F_35 ( V_93 ) ;
V_20 = F_14 ( V_2 ) ;
V_62 = V_20 -> V_69 ( V_2 , V_20 -> V_98 + V_96 ,
V_97 , V_63 ) ;
if ( V_62 < 0 ) {
F_5 ( & V_2 -> V_11 , L_5 , L_24 , V_62 ) ;
return V_62 ;
}
return V_97 ;
}
static T_2 F_37 ( struct V_1 * V_2 ,
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
F_38 ( & V_2 -> V_11 ,
L_25 , V_99 ) ;
return 0 ;
}
return V_101 ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_107 * V_108 )
{
T_7 V_99 = 0 ;
bool V_100 = true ;
if ( ! V_108 -> V_109 )
goto V_28;
if ( F_40 ( & V_2 -> V_11 , L_26 , & V_99 ) )
goto V_28;
if ( F_41 ( & V_2 -> V_11 , L_27 ) )
V_100 = false ;
V_108 -> V_110 = V_108 -> V_109 ( V_2 ,
V_99 , V_100 ) ;
V_28:
return;
}
static int F_42 ( struct V_35 * V_11 , T_1 * V_111 )
{
struct V_20 * V_20 = F_19 ( V_11 ) ;
T_2 V_112 [ 2 ] ;
T_8 V_113 ;
int V_9 ;
V_9 = V_20 -> V_39 ( V_20 -> V_2 , V_114 ,
sizeof( V_112 ) , V_112 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 != sizeof( V_112 ) )
return - V_13 ;
V_113 = ( V_112 [ 0 ] << 8 ) | V_112 [ 1 ] ;
V_113 >>= 6 ;
* V_111 = V_113 * 250 ;
return 0 ;
}
static T_4 F_43 ( struct V_35 * V_11 ,
struct V_115 * V_95 , char * V_63 )
{
int V_9 ;
T_1 V_113 ;
V_9 = F_42 ( V_11 , & V_113 ) ;
if ( V_9 )
return V_9 ;
return sprintf ( V_63 , L_28 , V_113 ) ;
}
static void F_44 ( struct V_20 * V_20 )
{
struct V_35 * V_11 ;
if ( V_20 -> type != V_58 )
return;
V_11 = F_45 ( & V_20 -> V_2 -> V_11 ,
V_20 -> V_2 -> V_116 ,
V_20 , V_117 ) ;
if ( F_46 ( V_11 ) ) {
F_38 ( & V_20 -> V_2 -> V_11 ,
L_29 , F_47 ( V_11 ) ) ;
}
}
static void F_44 ( struct V_20 * V_20 )
{
}
static int F_48 ( struct V_20 * V_20 , T_2 V_118 , T_2 V_119 )
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
V_26 &= ~ V_118 ;
V_26 |= V_119 ;
V_9 = F_7 ( V_2 , V_30 , V_26 ) ;
V_28:
F_17 ( V_22 ) ;
return V_9 ;
}
static unsigned long F_49 ( struct V_120 * V_121 ,
unsigned long V_122 )
{
struct V_20 * V_20 = F_50 ( V_121 ) ;
int V_26 ;
int V_123 = 0 ;
V_26 = F_2 ( V_20 -> V_2 , V_30 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_26 & V_124 )
V_123 += 1 ;
if ( V_26 & V_125 )
V_123 += 2 ;
return V_126 [ V_123 ] ;
}
static long F_51 ( struct V_120 * V_121 , unsigned long V_127 ,
unsigned long * V_128 )
{
int V_6 ;
for ( V_6 = F_52 ( V_126 ) - 1 ; V_6 >= 0 ; V_6 -- ) {
if ( V_126 [ V_6 ] <= V_127 )
return V_126 [ V_6 ] ;
}
return 0 ;
}
static int F_53 ( struct V_120 * V_121 , unsigned long V_127 ,
unsigned long V_122 )
{
struct V_20 * V_20 = F_50 ( V_121 ) ;
int V_26 = 0 ;
int V_123 ;
for ( V_123 = 0 ; V_123 < F_52 ( V_126 ) ;
V_123 ++ ) {
if ( V_126 [ V_123 ] == V_127 )
break;
}
if ( V_123 == F_52 ( V_126 ) )
return - V_64 ;
if ( V_123 & 1 )
V_26 |= V_124 ;
if ( V_123 & 2 )
V_26 |= V_125 ;
return F_48 ( V_20 , V_124 | V_125 ,
V_26 ) ;
}
static int F_54 ( struct V_120 * V_121 )
{
struct V_20 * V_20 = F_50 ( V_121 ) ;
return F_48 ( V_20 , V_129 , 0 ) ;
}
static void F_55 ( struct V_120 * V_121 )
{
struct V_20 * V_20 = F_50 ( V_121 ) ;
F_48 ( V_20 , V_129 , V_129 ) ;
}
static int F_56 ( struct V_120 * V_121 )
{
struct V_20 * V_20 = F_50 ( V_121 ) ;
int V_26 ;
V_26 = F_2 ( V_20 -> V_2 , V_30 ) ;
if ( V_26 < 0 )
return V_26 ;
return ! ( V_26 & V_129 ) ;
}
static unsigned long F_57 ( struct V_120 * V_121 ,
unsigned long V_122 )
{
return 32768 ;
}
static int F_58 ( struct V_20 * V_20 , bool V_130 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_21 * V_22 = & V_20 -> V_23 -> V_24 ;
int V_76 ;
int V_9 ;
F_15 ( V_22 ) ;
V_76 = F_2 ( V_2 , V_27 ) ;
if ( V_76 < 0 ) {
V_9 = V_76 ;
goto V_28;
}
if ( V_130 )
V_76 |= V_131 ;
else
V_76 &= ~ V_131 ;
V_9 = F_7 ( V_2 , V_27 , V_76 ) ;
V_28:
F_17 ( V_22 ) ;
return V_9 ;
}
static int F_59 ( struct V_120 * V_121 )
{
struct V_20 * V_20 = F_60 ( V_121 ) ;
return F_58 ( V_20 , true ) ;
}
static void F_61 ( struct V_120 * V_121 )
{
struct V_20 * V_20 = F_60 ( V_121 ) ;
F_58 ( V_20 , false ) ;
}
static int F_62 ( struct V_120 * V_121 )
{
struct V_20 * V_20 = F_60 ( V_121 ) ;
int V_76 ;
V_76 = F_2 ( V_20 -> V_2 , V_27 ) ;
if ( V_76 < 0 )
return V_76 ;
return ! ! ( V_76 & V_131 ) ;
}
static int F_63 ( struct V_20 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_132 * V_133 = V_2 -> V_11 . V_134 ;
struct V_135 * V_136 ;
int V_6 ;
V_136 = F_64 ( & V_2 -> V_11 , sizeof( * V_136 ) , V_137 ) ;
if ( ! V_136 )
return - V_138 ;
V_136 -> V_139 = F_52 ( V_140 ) ;
V_136 -> V_141 = F_65 ( & V_2 -> V_11 , V_136 -> V_139 ,
sizeof( V_136 -> V_141 [ 0 ] ) , V_137 ) ;
if ( ! V_136 -> V_141 )
return - V_138 ;
for ( V_6 = 0 ; V_6 < F_52 ( V_140 ) ; V_6 ++ ) {
struct V_142 V_143 = V_140 [ V_6 ] ;
if ( V_6 == V_144 && F_27 ( V_71 , & V_20 -> V_72 ) )
continue;
F_66 ( V_133 , L_30 , V_6 ,
& V_143 . V_116 ) ;
V_20 -> V_141 [ V_6 ] . V_143 = & V_143 ;
V_136 -> V_141 [ V_6 ] = F_67 ( & V_2 -> V_11 ,
& V_20 -> V_141 [ V_6 ] ) ;
if ( F_46 ( V_136 -> V_141 [ V_6 ] ) )
return F_47 ( V_136 -> V_141 [ V_6 ] ) ;
}
if ( ! V_133 )
return 0 ;
F_68 ( V_133 , V_145 , V_136 ) ;
return 0 ;
}
static void F_69 ( struct V_20 * V_20 )
{
int V_9 ;
if ( V_20 -> type != V_58 )
return;
V_9 = F_63 ( V_20 ) ;
if ( V_9 ) {
F_38 ( & V_20 -> V_2 -> V_11 ,
L_31 , V_9 ) ;
}
}
static void F_69 ( struct V_20 * V_20 )
{
}
static int F_70 ( struct V_1 * V_2 ,
const struct V_146 * V_147 )
{
struct V_20 * V_20 ;
int V_148 = - V_149 ;
int V_38 , V_150 ;
struct V_107 * V_108 ;
struct V_151 * V_152 = F_71 ( V_2 -> V_11 . V_153 ) ;
bool V_154 = false ;
bool V_155 = false ;
unsigned char * V_63 ;
struct V_156 * V_157 = F_72 ( & V_2 -> V_11 ) ;
struct V_36 V_158 ;
unsigned long V_159 ;
T_9 V_160 = F_13 ;
static const int V_161 [] = {
[ V_56 ] = 0 ,
[ V_57 ] = V_162 ,
[ V_58 ] = V_163 ,
} ;
const struct V_164 * V_165 = & V_166 ;
if ( ! F_73 ( V_152 , V_167 )
&& ! F_73 ( V_152 , V_168 ) )
return - V_13 ;
V_20 = F_64 ( & V_2 -> V_11 , sizeof( struct V_20 ) , V_137 ) ;
if ( ! V_20 )
return - V_138 ;
F_74 ( V_2 , V_20 ) ;
V_20 -> V_2 = V_2 ;
if ( V_147 ) {
V_108 = & V_169 [ V_147 -> V_170 ] ;
V_20 -> type = V_147 -> V_170 ;
} else {
const struct V_171 * V_172 ;
V_172 = F_75 ( F_76 ( V_173 ) ,
& V_2 -> V_11 ) ;
if ( ! V_172 )
return - V_149 ;
V_108 = & V_169 [ V_172 -> V_170 ] ;
V_20 -> type = V_172 -> V_170 ;
}
if ( ! V_157 )
F_39 ( V_2 , V_108 ) ;
else if ( V_157 -> V_110 )
V_108 -> V_110 = V_157 -> V_110 ;
if ( V_108 -> V_110 && V_108 -> V_174 ) {
F_4 ( & V_2 -> V_11 , L_32 ,
V_175 | V_108 -> V_110 ,
V_108 -> V_174 ) ;
F_7 ( V_2 , V_108 -> V_174 ,
V_175 |
V_108 -> V_110 ) ;
}
V_63 = V_20 -> V_41 ;
if ( F_73 ( V_152 , V_168 ) ) {
V_20 -> V_39 = F_11 ;
V_20 -> V_69 = F_8 ;
} else {
V_20 -> V_39 = F_3 ;
V_20 -> V_69 = F_6 ;
}
#ifdef F_77
if ( F_78 ( V_2 -> V_11 . V_134 , L_33 ) ) {
V_155 = true ;
}
if ( F_78 ( V_2 -> V_11 . V_134 ,
L_34 ) ) {
V_155 = true ;
}
#endif
switch ( V_20 -> type ) {
case V_56 :
case V_57 :
case V_58 :
V_38 = V_20 -> V_39 ( V_20 -> V_2 ,
V_30 , 2 , V_63 ) ;
if ( V_38 != 2 ) {
F_4 ( & V_2 -> V_11 , L_35 , V_38 ) ;
V_148 = - V_13 ;
goto exit;
}
if ( V_20 -> V_41 [ 0 ] & V_176 )
V_20 -> V_41 [ 0 ] &= ~ V_176 ;
if ( V_108 -> V_177 && ( V_20 -> V_2 -> V_18 > 0 ||
V_155 ) ) {
V_20 -> V_41 [ 0 ] |= V_129
| V_161 [ V_20 -> type ] ;
V_20 -> V_41 [ 0 ] &= ~ ( V_77 | V_31 ) ;
V_154 = true ;
}
F_7 ( V_2 , V_30 ,
V_20 -> V_41 [ 0 ] ) ;
if ( V_20 -> V_41 [ 1 ] & V_178 ) {
F_7 ( V_2 , V_27 ,
V_20 -> V_41 [ 1 ] & ~ V_178 ) ;
F_38 ( & V_2 -> V_11 , L_36 ) ;
}
break;
case V_179 :
V_38 = F_12 ( V_20 -> V_2 ,
V_180 << 4 | 0x08 , 2 , V_63 ) ;
if ( V_38 != 2 ) {
F_4 ( & V_2 -> V_11 , L_35 , V_38 ) ;
V_148 = - V_13 ;
goto exit;
}
if ( ! ( V_20 -> V_41 [ 1 ] & V_181 ) ) {
V_20 -> V_41 [ 1 ] |= V_181 ;
F_7 ( V_2 ,
V_182 << 4 | 0x08 ,
V_20 -> V_41 [ 1 ] ) ;
F_38 ( & V_2 -> V_11 ,
L_37 ) ;
}
if ( V_20 -> V_41 [ 1 ] & V_183 ) {
V_20 -> V_41 [ 1 ] &= ~ V_183 ;
F_7 ( V_2 ,
V_182 << 4 | 0x08 ,
V_20 -> V_41 [ 1 ] ) ;
F_38 ( & V_2 -> V_11 , L_38 ) ;
}
if ( V_20 -> V_41 [ 1 ] & V_184 ) {
V_20 -> V_41 [ 1 ] &= ~ V_184 ;
F_7 ( V_2 ,
V_182 << 4 | 0x08 ,
V_20 -> V_41 [ 1 ] ) ;
F_38 ( & V_2 -> V_11 , L_39 ) ;
}
if ( ! ( V_20 -> V_41 [ 0 ] & V_185 ) ) {
T_2 V_186 ;
F_7 ( V_2 ,
V_180 << 4 | 0x08 ,
V_20 -> V_41 [ 0 ] |
V_185 ) ;
V_38 = F_12 ( V_20 -> V_2 ,
V_180 << 4 | 0x08 , 2 , V_63 ) ;
if ( V_38 != 2 ) {
F_4 ( & V_2 -> V_11 , L_35 , V_38 ) ;
V_148 = - V_13 ;
goto exit;
}
V_186 = F_20 ( V_20 -> V_41 [ V_46 ] ) ;
if ( V_186 == 12 )
V_186 = 0 ;
if ( V_20 -> V_41 [ V_46 ] & V_187 )
V_186 += 12 ;
F_7 ( V_2 ,
V_46 << 4 | 0x08 ,
V_186 ) ;
}
break;
case V_188 :
V_20 -> V_40 = 1 ;
break;
case V_66 :
V_165 = & V_189 ;
if ( V_20 -> V_2 -> V_18 > 0 && V_108 -> V_177 ) {
V_160 = F_30 ;
V_154 = true ;
}
break;
default:
break;
}
V_190:
V_38 = V_20 -> V_39 ( V_20 -> V_2 , V_20 -> V_40 , 8 , V_63 ) ;
if ( V_38 != 8 ) {
F_4 ( & V_2 -> V_11 , L_35 , V_38 ) ;
V_148 = - V_13 ;
goto exit;
}
V_38 = V_20 -> V_41 [ V_43 ] ;
switch ( V_20 -> type ) {
case V_191 :
case V_192 :
if ( V_38 & V_193 ) {
F_7 ( V_2 , V_43 , 0 ) ;
F_38 ( & V_2 -> V_11 , L_36 ) ;
goto V_190;
}
break;
case V_194 :
if ( V_38 & V_193 )
F_7 ( V_2 , V_43 , 0 ) ;
if ( V_20 -> V_41 [ V_195 ] & V_196 ) {
F_7 ( V_2 , V_195 ,
V_20 -> V_41 [ V_195 ]
& ~ V_196 ) ;
F_38 ( & V_2 -> V_11 , L_36 ) ;
goto V_190;
}
break;
case V_60 :
if ( V_38 & V_197 )
F_7 ( V_2 , V_43 , 0 ) ;
V_38 = F_2 ( V_2 , V_198 ) ;
if ( V_38 < 0 ) {
F_4 ( & V_2 -> V_11 , L_35 , V_38 ) ;
V_148 = - V_13 ;
goto exit;
}
if ( V_38 & V_199 ) {
F_7 ( V_2 , V_198 , 0 ) ;
F_38 ( & V_2 -> V_11 , L_36 ) ;
}
break;
case V_66 :
if ( ! ( V_20 -> V_41 [ V_49 ] & V_68 ) ) {
F_7 ( V_2 , V_49 ,
V_20 -> V_41 [ V_49 ]
| V_68 ) ;
}
if ( ! ( V_38 & V_67 ) ) {
F_7 ( V_2 , V_43 ,
V_67 ) ;
F_38 ( & V_2 -> V_11 , L_36 ) ;
goto V_190;
}
break;
default:
break;
}
V_38 = V_20 -> V_41 [ V_46 ] ;
switch ( V_20 -> type ) {
case V_60 :
case V_192 :
break;
case V_179 :
break;
default:
if ( ! ( V_38 & V_200 ) )
break;
V_38 = F_20 ( V_38 & 0x1f ) ;
if ( V_38 == 12 )
V_38 = 0 ;
if ( V_20 -> V_41 [ V_46 ] & V_187 )
V_38 += 12 ;
F_7 ( V_2 ,
V_20 -> V_40 + V_46 ,
F_24 ( V_38 ) ) ;
}
F_18 ( & V_2 -> V_11 , & V_158 ) ;
V_150 = V_158 . V_48 ;
V_159 = F_79 ( & V_158 ) ;
F_80 ( V_159 , & V_158 ) ;
if ( V_150 != V_158 . V_48 ) {
V_150 = F_2 ( V_2 , V_201 ) ;
V_150 = V_150 & ~ V_202 ;
V_150 = V_150 | ( V_158 . V_48 + 1 ) ;
F_7 ( V_2 , V_201 , V_150 ) ;
}
if ( V_154 ) {
F_81 ( & V_2 -> V_11 , true ) ;
F_82 ( V_71 , & V_20 -> V_72 ) ;
}
V_20 -> V_23 = F_83 ( & V_2 -> V_11 , V_2 -> V_116 ,
V_165 , V_203 ) ;
if ( F_46 ( V_20 -> V_23 ) ) {
return F_47 ( V_20 -> V_23 ) ;
}
if ( V_155 && V_20 -> V_2 -> V_18 <= 0 ) {
V_154 = false ;
F_84 ( & V_2 -> V_11 , L_40 ) ;
V_20 -> V_23 -> V_204 = 1 ;
}
if ( V_154 ) {
V_148 = F_85 ( & V_2 -> V_11 ,
V_2 -> V_18 , NULL , V_160 ,
V_205 | V_206 ,
V_20 -> V_23 -> V_116 , V_2 ) ;
if ( V_148 ) {
V_2 -> V_18 = 0 ;
F_81 ( & V_2 -> V_11 , false ) ;
F_86 ( V_71 , & V_20 -> V_72 ) ;
F_5 ( & V_2 -> V_11 , L_41 ) ;
} else
F_4 ( & V_2 -> V_11 , L_42 , V_2 -> V_18 ) ;
}
if ( V_108 -> V_207 ) {
V_20 -> V_208 = F_64 ( & V_2 -> V_11 ,
sizeof( struct V_94 ) ,
V_137 ) ;
if ( ! V_20 -> V_208 ) {
F_5 ( & V_2 -> V_11 , L_43 ) ;
} else {
V_20 -> V_208 -> V_95 . V_116 = L_44 ;
V_20 -> V_208 -> V_95 . V_209 = V_210 | V_211 ;
F_87 ( V_20 -> V_208 ) ;
V_20 -> V_208 -> V_212 = F_34 ;
V_20 -> V_208 -> V_213 = F_36 ;
V_20 -> V_208 -> V_214 = V_108 -> V_207 ;
V_20 -> V_98 = V_108 -> V_98 ;
V_148 = F_88 ( & V_2 -> V_11 . V_93 ,
V_20 -> V_208 ) ;
if ( V_148 ) {
F_5 ( & V_2 -> V_11 ,
L_45 ,
V_20 -> V_208 -> V_95 . V_116 ) ;
} else {
F_82 ( V_215 , & V_20 -> V_72 ) ;
F_84 ( & V_2 -> V_11 , L_46 ,
V_20 -> V_208 -> V_214 ) ;
}
}
}
F_44 ( V_20 ) ;
F_69 ( V_20 ) ;
return 0 ;
exit:
return V_148 ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_20 * V_20 = F_14 ( V_2 ) ;
if ( F_90 ( V_215 , & V_20 -> V_72 ) )
F_91 ( & V_2 -> V_11 . V_93 , V_20 -> V_208 ) ;
return 0 ;
}
