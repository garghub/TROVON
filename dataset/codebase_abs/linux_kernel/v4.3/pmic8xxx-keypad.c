static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_3 == 0x00 )
return 1 << V_2 -> V_4 ;
else
return V_3 & ( ( 1 << V_2 -> V_4 ) - 1 ) ;
}
static int F_2 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned int V_6 ;
V_5 = F_3 ( V_2 -> V_7 , V_8 , & V_6 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_9 , L_1 , V_5 ) ;
return V_5 ;
}
V_6 |= 0x1 ;
V_5 = F_5 ( V_2 -> V_7 , V_8 , V_6 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_9 , L_2 , V_5 ) ;
return V_5 ;
}
F_6 ( ( 2 * F_7 ( V_10 , V_11 ) ) + 1 ) ;
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 , T_2 * V_12 ,
T_2 V_13 , int V_14 )
{
int V_5 , V_15 ;
unsigned int V_16 ;
for ( V_15 = 0 ; V_15 < V_14 ; V_15 ++ ) {
V_5 = F_3 ( V_2 -> V_7 , V_13 , & V_16 ) ;
if ( V_5 )
return V_5 ;
F_9 ( V_2 -> V_9 , L_3 , V_15 , V_16 ) ;
V_12 [ V_15 ] = F_1 ( V_2 , V_16 ) ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 * V_17 ,
T_2 * V_18 )
{
int V_5 , V_14 ;
unsigned int V_6 ;
if ( V_2 -> V_19 < V_20 )
V_14 = V_20 ;
else
V_14 = V_2 -> V_19 ;
F_2 ( V_2 ) ;
if ( V_18 ) {
V_5 = F_8 ( V_2 , V_18 , V_21 ,
V_14 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_9 ,
L_4 , V_5 ) ;
return V_5 ;
}
}
V_5 = F_8 ( V_2 , V_17 , V_22 ,
V_14 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_9 ,
L_5 , V_5 ) ;
return V_5 ;
}
F_6 ( ( 4 * F_7 ( V_10 , V_11 ) ) + 1 ) ;
V_5 = F_3 ( V_2 -> V_7 , V_8 , & V_6 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_9 , L_1 , V_5 ) ;
return V_5 ;
}
V_6 &= 0xFE ;
V_5 = F_5 ( V_2 -> V_7 , V_8 , V_6 ) ;
if ( V_5 < 0 )
F_4 ( V_2 -> V_9 , L_2 , V_5 ) ;
return V_5 ;
}
static void F_11 ( struct V_1 * V_2 , T_2 * V_17 ,
T_2 * V_18 )
{
int V_15 , V_3 , V_23 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_19 ; V_15 ++ ) {
int V_24 = V_17 [ V_15 ] ^ V_18 [ V_15 ] ;
if ( ! V_24 )
continue;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
if ( ! ( V_24 & ( 1 << V_3 ) ) )
continue;
F_9 ( V_2 -> V_9 , L_6 , V_15 , V_3 ,
! ( V_17 [ V_15 ] & ( 1 << V_3 ) ) ?
L_7 : L_8 ) ;
V_23 = F_12 ( V_15 , V_3 , V_25 ) ;
F_13 ( V_2 -> V_26 , V_27 , V_28 , V_23 ) ;
F_14 ( V_2 -> V_26 ,
V_2 -> V_29 [ V_23 ] ,
! ( V_17 [ V_15 ] & ( 1 << V_3 ) ) ) ;
F_15 ( V_2 -> V_26 ) ;
}
}
}
static bool F_16 ( struct V_1 * V_2 , T_2 * V_17 )
{
int V_15 , V_30 = - 1 ;
T_2 V_31 , V_32 ;
V_31 = 0 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_19 ; V_15 ++ ) {
V_32 = ( ~ V_17 [ V_15 ] ) &
( ( 1 << V_2 -> V_4 ) - 1 ) ;
if ( F_17 ( V_32 ) > 1 ) {
if ( V_30 == - 1 )
V_30 = V_15 ;
if ( V_31 & V_32 ) {
F_9 ( V_2 -> V_9 , L_9
L_10 , V_30 , V_15 ) ;
return true ;
}
}
V_31 |= V_32 ;
}
return false ;
}
static int F_18 ( struct V_1 * V_2 , unsigned int V_33 )
{
T_2 V_17 [ V_34 ] ;
T_2 V_18 [ V_34 ] ;
int V_5 ;
switch ( V_33 ) {
case 0x1 :
V_5 = F_10 ( V_2 , V_17 , NULL ) ;
if ( V_5 < 0 )
return V_5 ;
if ( F_16 ( V_2 , V_17 ) )
return 0 ;
F_11 ( V_2 , V_17 , V_2 -> V_35 ) ;
memcpy ( V_2 -> V_35 , V_17 , sizeof( V_17 ) ) ;
break;
case 0x3 :
V_5 = F_10 ( V_2 , V_17 , V_18 ) ;
if ( V_5 < 0 )
return V_5 ;
F_11 ( V_2 , V_18 , V_2 -> V_35 ) ;
F_11 ( V_2 , V_17 , V_18 ) ;
memcpy ( V_2 -> V_35 , V_17 , sizeof( V_17 ) ) ;
break;
case 0x2 :
F_9 ( V_2 -> V_9 , L_11 ) ;
V_5 = F_10 ( V_2 , V_17 , V_18 ) ;
if ( V_5 < 0 )
return V_5 ;
F_11 ( V_2 , V_18 , V_2 -> V_35 ) ;
F_11 ( V_2 , V_17 , V_18 ) ;
memcpy ( V_2 -> V_35 , V_17 , sizeof( V_17 ) ) ;
break;
default:
V_5 = - V_36 ;
}
return V_5 ;
}
static T_3 F_19 ( int V_37 , void * V_38 )
{
T_2 V_17 [ V_34 ] ;
T_2 V_18 [ V_34 ] ;
int V_5 ;
struct V_1 * V_2 = V_38 ;
V_5 = F_10 ( V_2 , V_17 , V_18 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_9 , L_12 ) ;
return V_39 ;
}
F_11 ( V_2 , V_17 , V_2 -> V_40 ) ;
return V_39 ;
}
static T_3 F_20 ( int V_37 , void * V_38 )
{
struct V_1 * V_2 = V_38 ;
unsigned int V_41 , V_33 ;
int V_5 ;
V_5 = F_3 ( V_2 -> V_7 , V_42 , & V_41 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_9 , L_13 ) ;
return V_39 ;
}
V_33 = V_41 & V_43 ;
V_5 = F_18 ( V_2 , V_33 ) ;
if ( V_5 < 0 )
F_4 ( V_2 -> V_9 , L_14 ) ;
return V_39 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
const struct V_46 * V_47 = V_45 -> V_9 . V_47 ;
unsigned int V_48 ;
unsigned int V_49 ;
unsigned int V_50 ;
int V_51 , V_5 , V_52 ;
T_1 V_6 = 0 , V_41 = 0 ;
static const T_1 V_53 [] = {
0 , 1 , 2 , 3 , 4 , 4 , 5 , 5 , 6 , 6 , 6 , 7 , 7 , 7 ,
} ;
if ( V_2 -> V_4 < V_54 )
V_51 = 0 ;
else
V_51 = V_2 -> V_4 - V_54 ;
V_41 = ( V_51 & V_55 ) <<
V_56 ;
if ( V_2 -> V_19 < V_57 )
V_51 = 0 ;
else
V_51 = V_53 [ V_2 -> V_19 - V_57 ] ;
V_41 |= ( V_51 << V_58 ) ;
V_5 = F_5 ( V_2 -> V_7 , V_42 , V_41 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_9 , L_15 , V_5 ) ;
return V_5 ;
}
if ( F_22 ( V_47 , L_16 , & V_48 ) )
V_48 = V_59 ;
if ( V_48 > V_60 || V_48 < V_59 ||
! F_23 ( V_48 ) ) {
F_4 ( & V_45 -> V_9 , L_17 ) ;
return - V_36 ;
}
if ( F_22 ( V_47 , L_18 , & V_49 ) )
V_49 = V_61 ;
if ( V_49 > V_62 ||
V_49 < V_61 ||
( ( V_49 % V_61 ) != 0 ) ) {
F_4 ( & V_45 -> V_9 , L_19 ) ;
return - V_36 ;
}
if ( F_22 ( V_47 , L_20 , & V_50 ) )
V_50 = V_63 ;
if ( ( ( V_50 % 5 ) != 0 ) ||
V_50 > V_64 ||
V_50 < V_63 ) {
F_4 ( & V_45 -> V_9 , L_21 ) ;
return - V_36 ;
}
V_51 = ( V_50 / 5 ) - 1 ;
V_6 |= ( V_51 << V_65 ) ;
V_51 = F_24 ( V_48 ) - 1 ;
V_6 |= ( V_51 << V_66 ) ;
V_52 = ( V_49 * V_11 ) / V_67 ;
V_6 |= ( V_52 << V_68 ) ;
V_5 = F_5 ( V_2 -> V_7 , V_8 , V_6 ) ;
if ( V_5 )
F_4 ( V_2 -> V_9 , L_2 , V_5 ) ;
return V_5 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_5 ;
V_2 -> V_69 |= V_70 ;
V_5 = F_5 ( V_2 -> V_7 , V_42 , V_2 -> V_69 ) ;
if ( V_5 < 0 )
F_4 ( V_2 -> V_9 , L_15 , V_5 ) ;
return V_5 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_5 ;
V_2 -> V_69 &= ~ V_70 ;
V_5 = F_5 ( V_2 -> V_7 , V_42 , V_2 -> V_69 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_5 ;
}
static int F_27 ( struct V_71 * V_9 )
{
struct V_1 * V_2 = F_28 ( V_9 ) ;
return F_25 ( V_2 ) ;
}
static void F_29 ( struct V_71 * V_9 )
{
struct V_1 * V_2 = F_28 ( V_9 ) ;
F_26 ( V_2 ) ;
}
static int F_30 ( struct V_44 * V_45 )
{
struct V_46 * V_72 = V_45 -> V_9 . V_47 ;
unsigned int V_73 , V_74 ;
bool V_75 ;
bool V_76 ;
struct V_1 * V_2 ;
int V_5 ;
unsigned int V_41 ;
V_5 = F_31 ( & V_45 -> V_9 , & V_73 , & V_74 ) ;
if ( V_5 )
return V_5 ;
if ( V_74 > V_77 || V_73 > V_34 ||
V_74 < V_78 ) {
F_4 ( & V_45 -> V_9 , L_22 ) ;
return - V_36 ;
}
V_75 = ! F_32 ( V_72 , L_23 ) ;
V_76 = F_32 ( V_72 , L_24 ) ||
F_32 ( V_72 , L_25 ) ;
V_2 = F_33 ( & V_45 -> V_9 , sizeof( * V_2 ) , V_79 ) ;
if ( ! V_2 )
return - V_80 ;
V_2 -> V_7 = F_34 ( V_45 -> V_9 . V_81 , NULL ) ;
if ( ! V_2 -> V_7 )
return - V_82 ;
F_35 ( V_45 , V_2 ) ;
V_2 -> V_19 = V_73 ;
V_2 -> V_4 = V_74 ;
V_2 -> V_9 = & V_45 -> V_9 ;
V_2 -> V_26 = F_36 ( & V_45 -> V_9 ) ;
if ( ! V_2 -> V_26 ) {
F_4 ( & V_45 -> V_9 , L_26 ) ;
return - V_80 ;
}
V_2 -> V_83 = F_37 ( V_45 , 0 ) ;
if ( V_2 -> V_83 < 0 ) {
F_4 ( & V_45 -> V_9 , L_27 ) ;
return V_2 -> V_83 ;
}
V_2 -> V_84 = F_37 ( V_45 , 1 ) ;
if ( V_2 -> V_84 < 0 ) {
F_4 ( & V_45 -> V_9 , L_28 ) ;
return V_2 -> V_84 ;
}
V_2 -> V_26 -> V_85 = L_29 ;
V_2 -> V_26 -> V_86 = L_30 ;
V_2 -> V_26 -> V_87 . V_88 = V_89 ;
V_2 -> V_26 -> V_87 . V_90 = 0x0001 ;
V_2 -> V_26 -> V_87 . V_91 = 0x0001 ;
V_2 -> V_26 -> V_87 . V_92 = 0x0001 ;
V_2 -> V_26 -> V_93 = F_27 ;
V_2 -> V_26 -> V_94 = F_29 ;
V_5 = F_38 ( NULL , NULL ,
V_34 , V_77 ,
V_2 -> V_29 , V_2 -> V_26 ) ;
if ( V_5 ) {
F_4 ( & V_45 -> V_9 , L_31 ) ;
return V_5 ;
}
if ( V_75 )
F_39 ( V_95 , V_2 -> V_26 -> V_96 ) ;
F_40 ( V_2 -> V_26 , V_27 , V_28 ) ;
F_41 ( V_2 -> V_26 , V_2 ) ;
memset ( V_2 -> V_35 , 0xff , sizeof( V_2 -> V_35 ) ) ;
memset ( V_2 -> V_40 , 0xff , sizeof( V_2 -> V_40 ) ) ;
V_5 = F_21 ( V_2 , V_45 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_45 -> V_9 , L_32 ) ;
return V_5 ;
}
V_5 = F_42 ( & V_45 -> V_9 , V_2 -> V_83 ,
F_20 , V_97 , L_33 ,
V_2 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_45 -> V_9 , L_34 ) ;
return V_5 ;
}
V_5 = F_42 ( & V_45 -> V_9 , V_2 -> V_84 ,
F_19 , V_97 ,
L_35 , V_2 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_45 -> V_9 , L_36 ) ;
return V_5 ;
}
V_5 = F_3 ( V_2 -> V_7 , V_42 , & V_41 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_45 -> V_9 , L_37 ) ;
return V_5 ;
}
V_2 -> V_69 = V_41 ;
V_5 = F_43 ( V_2 -> V_26 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_45 -> V_9 , L_38 ) ;
return V_5 ;
}
F_44 ( & V_45 -> V_9 , V_76 ) ;
return 0 ;
}
static int F_45 ( struct V_98 * V_9 )
{
struct V_44 * V_45 = F_46 ( V_9 ) ;
struct V_1 * V_2 = F_47 ( V_45 ) ;
struct V_71 * V_71 = V_2 -> V_26 ;
if ( F_48 ( V_9 ) ) {
F_49 ( V_2 -> V_83 ) ;
} else {
F_50 ( & V_71 -> V_99 ) ;
if ( V_71 -> V_100 )
F_26 ( V_2 ) ;
F_51 ( & V_71 -> V_99 ) ;
}
return 0 ;
}
static int F_52 ( struct V_98 * V_9 )
{
struct V_44 * V_45 = F_46 ( V_9 ) ;
struct V_1 * V_2 = F_47 ( V_45 ) ;
struct V_71 * V_71 = V_2 -> V_26 ;
if ( F_48 ( V_9 ) ) {
F_53 ( V_2 -> V_83 ) ;
} else {
F_50 ( & V_71 -> V_99 ) ;
if ( V_71 -> V_100 )
F_25 ( V_2 ) ;
F_51 ( & V_71 -> V_99 ) ;
}
return 0 ;
}
