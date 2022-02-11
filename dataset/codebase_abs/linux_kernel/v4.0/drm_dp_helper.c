static T_1 F_1 ( const T_1 V_1 [ V_2 ] , int V_3 )
{
return V_1 [ V_3 - V_4 ] ;
}
static T_1 F_2 ( const T_1 V_1 [ V_2 ] ,
int V_5 )
{
int V_6 = V_4 + ( V_5 >> 1 ) ;
int V_7 = ( V_5 & 1 ) * 4 ;
T_1 V_8 = F_1 ( V_1 , V_6 ) ;
return ( V_8 >> V_7 ) & 0xf ;
}
bool F_3 ( const T_1 V_1 [ V_2 ] ,
int V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
int V_5 ;
V_10 = F_1 ( V_1 ,
V_12 ) ;
if ( ( V_10 & V_13 ) == 0 )
return false ;
for ( V_5 = 0 ; V_5 < V_9 ; V_5 ++ ) {
V_11 = F_2 ( V_1 , V_5 ) ;
if ( ( V_11 & V_14 ) != V_14 )
return false ;
}
return true ;
}
bool F_4 ( const T_1 V_1 [ V_2 ] ,
int V_9 )
{
int V_5 ;
T_1 V_11 ;
for ( V_5 = 0 ; V_5 < V_9 ; V_5 ++ ) {
V_11 = F_2 ( V_1 , V_5 ) ;
if ( ( V_11 & V_15 ) == 0 )
return false ;
}
return true ;
}
T_1 F_5 ( const T_1 V_1 [ V_2 ] ,
int V_5 )
{
int V_6 = V_16 + ( V_5 >> 1 ) ;
int V_7 = ( ( V_5 & 1 ) ?
V_17 :
V_18 ) ;
T_1 V_8 = F_1 ( V_1 , V_6 ) ;
return ( ( V_8 >> V_7 ) & 0x3 ) << V_19 ;
}
T_1 F_6 ( const T_1 V_1 [ V_2 ] ,
int V_5 )
{
int V_6 = V_16 + ( V_5 >> 1 ) ;
int V_7 = ( ( V_5 & 1 ) ?
V_20 :
V_21 ) ;
T_1 V_8 = F_1 ( V_1 , V_6 ) ;
return ( ( V_8 >> V_7 ) & 0x3 ) << V_22 ;
}
void F_7 ( const T_1 V_23 [ V_24 ] ) {
if ( V_23 [ V_25 ] == 0 )
F_8 ( 100 ) ;
else
F_9 ( V_23 [ V_25 ] * 4 ) ;
}
void F_10 ( const T_1 V_23 [ V_24 ] ) {
if ( V_23 [ V_25 ] == 0 )
F_8 ( 400 ) ;
else
F_9 ( V_23 [ V_25 ] * 4 ) ;
}
T_1 F_11 ( int V_26 )
{
switch ( V_26 ) {
case 162000 :
default:
return V_27 ;
case 270000 :
return V_28 ;
case 540000 :
return V_29 ;
}
}
int F_12 ( T_1 V_30 )
{
switch ( V_30 ) {
case V_27 :
default:
return 162000 ;
case V_28 :
return 270000 ;
case V_29 :
return 540000 ;
}
}
static int F_13 ( struct V_31 * V_32 , T_1 V_33 ,
unsigned int V_34 , void * V_35 , T_2 V_36 )
{
struct V_37 V_38 ;
unsigned int V_39 ;
int V_40 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_41 = V_34 ;
V_38 . V_33 = V_33 ;
V_38 . V_35 = V_35 ;
V_38 . V_36 = V_36 ;
for ( V_39 = 0 ; V_39 < 32 ; V_39 ++ ) {
F_14 ( & V_32 -> V_42 ) ;
V_40 = V_32 -> V_43 ( V_32 , & V_38 ) ;
F_15 ( & V_32 -> V_42 ) ;
if ( V_40 < 0 ) {
if ( V_40 == - V_44 )
continue;
return V_40 ;
}
switch ( V_38 . V_45 & V_46 ) {
case V_47 :
if ( V_40 < V_36 )
return - V_48 ;
return V_40 ;
case V_49 :
return - V_50 ;
case V_51 :
F_16 ( 400 , 500 ) ;
break;
}
}
F_17 ( L_1 ) ;
return - V_50 ;
}
T_3 F_18 ( struct V_31 * V_32 , unsigned int V_34 ,
void * V_35 , T_2 V_36 )
{
return F_13 ( V_32 , V_52 , V_34 , V_35 ,
V_36 ) ;
}
T_3 F_19 ( struct V_31 * V_32 , unsigned int V_34 ,
void * V_35 , T_2 V_36 )
{
return F_13 ( V_32 , V_53 , V_34 , V_35 ,
V_36 ) ;
}
int F_20 ( struct V_31 * V_32 ,
T_1 V_54 [ V_2 ] )
{
return F_18 ( V_32 , V_4 , V_54 ,
V_2 ) ;
}
int F_21 ( struct V_31 * V_32 , struct V_55 * V_56 )
{
T_1 V_57 [ 3 ] ;
int V_40 ;
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
V_40 = F_18 ( V_32 , V_58 , V_57 , sizeof( V_57 ) ) ;
if ( V_40 < 0 )
return V_40 ;
V_56 -> V_59 = V_57 [ 0 ] ;
V_56 -> V_60 = F_12 ( V_57 [ 1 ] ) ;
V_56 -> V_61 = V_57 [ 2 ] & V_62 ;
if ( V_57 [ 2 ] & V_63 )
V_56 -> V_64 |= V_65 ;
return 0 ;
}
int F_22 ( struct V_31 * V_32 , struct V_55 * V_56 )
{
T_1 V_66 ;
int V_40 ;
if ( V_56 -> V_59 < 0x11 )
return 0 ;
V_40 = F_23 ( V_32 , V_67 , & V_66 ) ;
if ( V_40 < 0 )
return V_40 ;
V_66 &= ~ V_68 ;
V_66 |= V_69 ;
V_40 = F_24 ( V_32 , V_67 , V_66 ) ;
if ( V_40 < 0 )
return V_40 ;
F_16 ( 1000 , 2000 ) ;
return 0 ;
}
int F_25 ( struct V_31 * V_32 , struct V_55 * V_56 )
{
T_1 V_66 ;
int V_40 ;
if ( V_56 -> V_59 < 0x11 )
return 0 ;
V_40 = F_23 ( V_32 , V_67 , & V_66 ) ;
if ( V_40 < 0 )
return V_40 ;
V_66 &= ~ V_68 ;
V_66 |= V_70 ;
V_40 = F_24 ( V_32 , V_67 , V_66 ) ;
if ( V_40 < 0 )
return V_40 ;
return 0 ;
}
int F_26 ( struct V_31 * V_32 , struct V_55 * V_56 )
{
T_1 V_57 [ 2 ] ;
int V_40 ;
V_57 [ 0 ] = F_11 ( V_56 -> V_60 ) ;
V_57 [ 1 ] = V_56 -> V_61 ;
if ( V_56 -> V_64 & V_65 )
V_57 [ 1 ] |= V_71 ;
V_40 = F_19 ( V_32 , V_72 , V_57 , sizeof( V_57 ) ) ;
if ( V_40 < 0 )
return V_40 ;
return 0 ;
}
static T_4 F_27 ( struct V_73 * V_74 )
{
return V_75 | V_76 |
V_77 |
V_78 |
V_79 ;
}
static int F_28 ( struct V_31 * V_32 , struct V_37 * V_38 )
{
unsigned int V_39 ;
int V_40 ;
for ( V_39 = 0 ; V_39 < 7 ; V_39 ++ ) {
F_14 ( & V_32 -> V_42 ) ;
V_40 = V_32 -> V_43 ( V_32 , V_38 ) ;
F_15 ( & V_32 -> V_42 ) ;
if ( V_40 < 0 ) {
if ( V_40 == - V_44 )
continue;
F_17 ( L_2 , V_40 ) ;
return V_40 ;
}
switch ( V_38 -> V_45 & V_46 ) {
case V_47 :
break;
case V_49 :
F_17 ( L_3 ) ;
return - V_80 ;
case V_51 :
F_17 ( L_4 ) ;
F_16 ( 500 , 600 ) ;
continue;
default:
F_29 ( L_5 , V_38 -> V_45 ) ;
return - V_80 ;
}
switch ( V_38 -> V_45 & V_81 ) {
case V_82 :
if ( V_40 < V_38 -> V_36 )
return - V_48 ;
return 0 ;
case V_83 :
F_17 ( L_6 ) ;
V_32 -> V_84 ++ ;
return - V_80 ;
case V_85 :
F_17 ( L_7 ) ;
V_32 -> V_86 ++ ;
F_16 ( 400 , 500 ) ;
continue;
default:
F_29 ( L_8 , V_38 -> V_45 ) ;
return - V_80 ;
}
}
F_17 ( L_1 ) ;
return - V_80 ;
}
static int F_30 ( struct V_73 * V_74 , struct V_87 * V_88 ,
int V_89 )
{
struct V_31 * V_32 = V_74 -> V_90 ;
unsigned int V_6 , V_91 ;
struct V_37 V_38 ;
int V_40 = 0 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
for ( V_6 = 0 ; V_6 < V_89 ; V_6 ++ ) {
V_38 . V_41 = V_88 [ V_6 ] . V_92 ;
V_38 . V_33 = ( V_88 [ V_6 ] . V_93 & V_94 ) ?
V_95 :
V_96 ;
V_38 . V_33 |= V_97 ;
V_38 . V_35 = NULL ;
V_38 . V_36 = 0 ;
V_40 = F_28 ( V_32 , & V_38 ) ;
if ( V_40 < 0 )
break;
for ( V_91 = 0 ; V_91 < V_88 [ V_6 ] . V_98 ; V_91 ++ ) {
V_38 . V_35 = V_88 [ V_6 ] . V_99 + V_91 ;
V_38 . V_36 = 1 ;
V_40 = F_28 ( V_32 , & V_38 ) ;
if ( V_40 < 0 )
break;
}
if ( V_40 < 0 )
break;
}
if ( V_40 >= 0 )
V_40 = V_89 ;
V_38 . V_33 &= ~ V_97 ;
V_38 . V_35 = NULL ;
V_38 . V_36 = 0 ;
( void ) F_28 ( V_32 , & V_38 ) ;
return V_40 ;
}
int F_31 ( struct V_31 * V_32 )
{
F_32 ( & V_32 -> V_42 ) ;
V_32 -> V_100 . V_101 = & V_102 ;
V_32 -> V_100 . V_90 = V_32 ;
V_32 -> V_100 . V_103 = 3 ;
V_32 -> V_100 . V_104 = V_105 ;
V_32 -> V_100 . V_106 = V_107 ;
V_32 -> V_100 . V_108 . V_109 = V_32 -> V_108 ;
V_32 -> V_100 . V_108 . V_110 = V_32 -> V_108 -> V_110 ;
F_33 ( V_32 -> V_100 . V_111 , V_32 -> V_111 ? V_32 -> V_111 : F_34 ( V_32 -> V_108 ) ,
sizeof( V_32 -> V_100 . V_111 ) ) ;
return F_35 ( & V_32 -> V_100 ) ;
}
void F_36 ( struct V_31 * V_32 )
{
F_37 ( & V_32 -> V_100 ) ;
}
