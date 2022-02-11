static int
F_1 ( struct V_1 * V_2 , int V_3 ,
T_1 V_4 , T_1 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
V_8 = (* V_7 -> V_9 )( V_2 , V_3 ,
V_4 , V_5 ) ;
return V_8 ;
}
static int
F_2 ( struct V_1 * V_2 , T_2 V_10 , bool V_11 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_3 = V_12 ;
int V_8 ;
if ( V_11 )
V_3 |= V_13 ;
else
V_3 |= V_14 ;
V_7 -> V_10 = V_10 ;
V_7 -> V_15 = true ;
V_8 = F_1 ( V_2 , V_3 , 0 , NULL ) ;
return V_8 ;
}
static void
F_3 ( struct V_1 * V_2 , bool V_11 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_3 = V_16 ;
if ( V_11 )
V_3 |= V_13 ;
else
V_3 |= V_14 ;
if ( V_7 -> V_15 ) {
( void ) F_1 ( V_2 , V_3 , 0 , NULL ) ;
V_7 -> V_15 = false ;
}
}
static int
F_4 ( struct V_1 * V_2 , T_3 V_17 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
if ( ! V_7 -> V_15 )
return - V_18 ;
V_8 = F_1 ( V_2 , V_14 , V_17 , NULL ) ;
return V_8 ;
}
static int
F_5 ( struct V_1 * V_2 , T_3 * V_19 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
if ( ! V_7 -> V_15 )
return - V_18 ;
V_8 = F_1 ( V_2 , V_13 , 0 , V_19 ) ;
return V_8 ;
}
static int
F_6 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
int V_22 )
{
int V_8 = 0 ;
bool V_11 = false ;
int V_23 ;
int V_24 ;
for ( V_23 = 0 ; V_23 < V_22 ; V_23 ++ ) {
T_2 V_25 = V_21 [ V_23 ] . V_25 ;
T_3 * V_26 = V_21 [ V_23 ] . V_26 ;
V_11 = ( V_21 [ V_23 ] . V_27 & V_28 ) != 0 ;
V_8 = F_2 ( V_2 , V_21 [ V_23 ] . V_29 , V_11 ) ;
if ( V_8 < 0 )
break;
if ( V_11 ) {
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
V_8 = F_5 ( V_2 , & V_26 [ V_24 ] ) ;
if ( V_8 < 0 )
break;
}
} else {
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
V_8 = F_4 ( V_2 , V_26 [ V_24 ] ) ;
if ( V_8 < 0 )
break;
}
}
if ( V_8 < 0 )
break;
}
if ( V_8 >= 0 )
V_8 = V_22 ;
F_3 ( V_2 , V_11 ) ;
F_7 ( L_1 , V_8 ) ;
return V_8 ;
}
static T_4
F_8 ( struct V_1 * V_2 )
{
return V_30 | V_31 |
V_32 |
V_33 |
V_34 ;
}
static void
F_9 ( struct V_1 * V_2 )
{
( void ) F_2 ( V_2 , 0 , false ) ;
( void ) F_3 ( V_2 , false ) ;
}
static int
F_10 ( struct V_1 * V_2 )
{
V_2 -> V_35 = & V_36 ;
V_2 -> V_37 = 3 ;
F_9 ( V_2 ) ;
return 0 ;
}
int
F_11 ( struct V_1 * V_2 )
{
int error ;
error = F_10 ( V_2 ) ;
if ( error )
return error ;
error = F_12 ( V_2 ) ;
return error ;
}
static T_3 F_13 ( const T_3 V_38 [ V_39 ] , int V_40 )
{
return V_38 [ V_40 - V_41 ] ;
}
static T_3 F_14 ( const T_3 V_38 [ V_39 ] ,
int V_42 )
{
int V_43 = V_41 + ( V_42 >> 1 ) ;
int V_44 = ( V_42 & 1 ) * 4 ;
T_3 V_45 = F_13 ( V_38 , V_43 ) ;
return ( V_45 >> V_44 ) & 0xf ;
}
bool F_15 ( const T_3 V_38 [ V_39 ] ,
int V_46 )
{
T_3 V_47 ;
T_3 V_48 ;
int V_42 ;
V_47 = F_13 ( V_38 ,
V_49 ) ;
if ( ( V_47 & V_50 ) == 0 )
return false ;
for ( V_42 = 0 ; V_42 < V_46 ; V_42 ++ ) {
V_48 = F_14 ( V_38 , V_42 ) ;
if ( ( V_48 & V_51 ) != V_51 )
return false ;
}
return true ;
}
bool F_16 ( const T_3 V_38 [ V_39 ] ,
int V_46 )
{
int V_42 ;
T_3 V_48 ;
for ( V_42 = 0 ; V_42 < V_46 ; V_42 ++ ) {
V_48 = F_14 ( V_38 , V_42 ) ;
if ( ( V_48 & V_52 ) == 0 )
return false ;
}
return true ;
}
T_3 F_17 ( const T_3 V_38 [ V_39 ] ,
int V_42 )
{
int V_43 = V_53 + ( V_42 >> 1 ) ;
int V_44 = ( ( V_42 & 1 ) ?
V_54 :
V_55 ) ;
T_3 V_45 = F_13 ( V_38 , V_43 ) ;
return ( ( V_45 >> V_44 ) & 0x3 ) << V_56 ;
}
T_3 F_18 ( const T_3 V_38 [ V_39 ] ,
int V_42 )
{
int V_43 = V_53 + ( V_42 >> 1 ) ;
int V_44 = ( ( V_42 & 1 ) ?
V_57 :
V_58 ) ;
T_3 V_45 = F_13 ( V_38 , V_43 ) ;
return ( ( V_45 >> V_44 ) & 0x3 ) << V_59 ;
}
void F_19 ( const T_3 V_60 [ V_61 ] ) {
if ( V_60 [ V_62 ] == 0 )
F_20 ( 100 ) ;
else
F_21 ( V_60 [ V_62 ] * 4 ) ;
}
void F_22 ( const T_3 V_60 [ V_61 ] ) {
if ( V_60 [ V_62 ] == 0 )
F_20 ( 400 ) ;
else
F_21 ( V_60 [ V_62 ] * 4 ) ;
}
T_3 F_23 ( int V_63 )
{
switch ( V_63 ) {
case 162000 :
default:
return V_64 ;
case 270000 :
return V_65 ;
case 540000 :
return V_66 ;
}
}
int F_24 ( T_3 V_67 )
{
switch ( V_67 ) {
case V_64 :
default:
return 162000 ;
case V_65 :
return 270000 ;
case V_66 :
return 540000 ;
}
}
static int F_25 ( struct V_68 * V_69 , T_3 V_70 ,
unsigned int V_71 , void * V_72 , T_5 V_73 )
{
struct V_74 V_75 ;
unsigned int V_76 ;
int V_77 ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_10 = V_71 ;
V_75 . V_70 = V_70 ;
V_75 . V_72 = V_72 ;
V_75 . V_73 = V_73 ;
for ( V_76 = 0 ; V_76 < 7 ; V_76 ++ ) {
V_77 = V_69 -> V_78 ( V_69 , & V_75 ) ;
if ( V_77 < 0 ) {
if ( V_77 == - V_79 )
continue;
return V_77 ;
}
switch ( V_75 . V_80 & V_81 ) {
case V_82 :
if ( V_77 < V_73 )
return - V_83 ;
return V_77 ;
case V_84 :
return - V_18 ;
case V_85 :
F_26 ( 400 , 500 ) ;
break;
}
}
F_7 ( L_2 ) ;
return - V_18 ;
}
T_6 F_27 ( struct V_68 * V_69 , unsigned int V_71 ,
void * V_72 , T_5 V_73 )
{
return F_25 ( V_69 , V_86 , V_71 , V_72 ,
V_73 ) ;
}
T_6 F_28 ( struct V_68 * V_69 , unsigned int V_71 ,
void * V_72 , T_5 V_73 )
{
return F_25 ( V_69 , V_87 , V_71 , V_72 ,
V_73 ) ;
}
int F_29 ( struct V_68 * V_69 ,
T_3 V_88 [ V_39 ] )
{
return F_27 ( V_69 , V_41 , V_88 ,
V_39 ) ;
}
int F_30 ( struct V_68 * V_69 , struct V_89 * V_90 )
{
T_3 V_91 [ 3 ] ;
int V_77 ;
memset ( V_90 , 0 , sizeof( * V_90 ) ) ;
V_77 = F_27 ( V_69 , V_92 , V_91 , sizeof( V_91 ) ) ;
if ( V_77 < 0 )
return V_77 ;
V_90 -> V_93 = V_91 [ 0 ] ;
V_90 -> V_94 = F_24 ( V_91 [ 1 ] ) ;
V_90 -> V_95 = V_91 [ 2 ] & V_96 ;
if ( V_91 [ 2 ] & V_97 )
V_90 -> V_98 |= V_99 ;
return 0 ;
}
int F_31 ( struct V_68 * V_69 , struct V_89 * V_90 )
{
T_3 V_100 ;
int V_77 ;
if ( V_90 -> V_93 < 0x11 )
return 0 ;
V_77 = F_32 ( V_69 , V_101 , & V_100 ) ;
if ( V_77 < 0 )
return V_77 ;
V_100 &= ~ V_102 ;
V_100 |= V_103 ;
V_77 = F_33 ( V_69 , V_101 , V_100 ) ;
if ( V_77 < 0 )
return V_77 ;
F_26 ( 1000 , 2000 ) ;
return 0 ;
}
int F_34 ( struct V_68 * V_69 , struct V_89 * V_90 )
{
T_3 V_91 [ 2 ] ;
int V_77 ;
V_91 [ 0 ] = F_23 ( V_90 -> V_94 ) ;
V_91 [ 1 ] = V_90 -> V_95 ;
if ( V_90 -> V_98 & V_99 )
V_91 [ 1 ] |= V_104 ;
V_77 = F_28 ( V_69 , V_105 , V_91 , sizeof( V_91 ) ) ;
if ( V_77 < 0 )
return V_77 ;
return 0 ;
}
static T_4 F_35 ( struct V_1 * V_2 )
{
return V_30 | V_31 |
V_32 |
V_33 |
V_34 ;
}
static int F_36 ( struct V_68 * V_69 , struct V_74 * V_75 )
{
unsigned int V_76 ;
int V_77 ;
for ( V_76 = 0 ; V_76 < 7 ; V_76 ++ ) {
V_77 = V_69 -> V_78 ( V_69 , V_75 ) ;
if ( V_77 < 0 ) {
if ( V_77 == - V_79 )
continue;
F_7 ( L_3 , V_77 ) ;
return V_77 ;
}
switch ( V_75 -> V_80 & V_81 ) {
case V_82 :
break;
case V_84 :
F_7 ( L_4 ) ;
return - V_106 ;
case V_85 :
F_7 ( L_5 ) ;
F_26 ( 500 , 600 ) ;
continue;
default:
F_37 ( L_6 , V_75 -> V_80 ) ;
return - V_106 ;
}
switch ( V_75 -> V_80 & V_107 ) {
case V_108 :
if ( V_77 < V_75 -> V_73 )
return - V_83 ;
return 0 ;
case V_109 :
F_7 ( L_7 ) ;
return - V_106 ;
case V_110 :
F_7 ( L_8 ) ;
F_26 ( 400 , 500 ) ;
continue;
default:
F_37 ( L_9 , V_75 -> V_80 ) ;
return - V_106 ;
}
}
F_7 ( L_2 ) ;
return - V_106 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_20 * V_21 ,
int V_22 )
{
struct V_68 * V_69 = V_2 -> V_7 ;
unsigned int V_43 , V_111 ;
struct V_74 V_75 ;
int V_77 = 0 ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
for ( V_43 = 0 ; V_43 < V_22 ; V_43 ++ ) {
V_75 . V_10 = V_21 [ V_43 ] . V_29 ;
V_75 . V_70 = ( V_21 [ V_43 ] . V_27 & V_28 ) ?
V_112 :
V_113 ;
V_75 . V_70 |= V_114 ;
V_75 . V_72 = NULL ;
V_75 . V_73 = 0 ;
V_77 = F_36 ( V_69 , & V_75 ) ;
if ( V_77 < 0 )
break;
for ( V_111 = 0 ; V_111 < V_21 [ V_43 ] . V_25 ; V_111 ++ ) {
V_75 . V_72 = V_21 [ V_43 ] . V_26 + V_111 ;
V_75 . V_73 = 1 ;
V_77 = F_36 ( V_69 , & V_75 ) ;
if ( V_77 < 0 )
break;
}
if ( V_77 < 0 )
break;
}
if ( V_77 >= 0 )
V_77 = V_22 ;
V_75 . V_70 &= ~ V_114 ;
V_75 . V_72 = NULL ;
V_75 . V_73 = 0 ;
( void ) F_36 ( V_69 , & V_75 ) ;
return V_77 ;
}
int F_39 ( struct V_68 * V_69 )
{
V_69 -> V_115 . V_35 = & V_116 ;
V_69 -> V_115 . V_7 = V_69 ;
V_69 -> V_115 . V_37 = 3 ;
V_69 -> V_115 . V_117 = V_118 ;
V_69 -> V_115 . V_119 = V_120 ;
V_69 -> V_115 . V_121 . V_122 = V_69 -> V_121 ;
V_69 -> V_115 . V_121 . V_123 = V_69 -> V_121 -> V_123 ;
F_40 ( V_69 -> V_115 . V_124 , V_69 -> V_124 ? V_69 -> V_124 : F_41 ( V_69 -> V_121 ) ,
sizeof( V_69 -> V_115 . V_124 ) ) ;
return F_12 ( & V_69 -> V_115 ) ;
}
void F_42 ( struct V_68 * V_69 )
{
F_43 ( & V_69 -> V_115 ) ;
}
