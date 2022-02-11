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
F_26 ( & V_69 -> V_78 ) ;
V_77 = V_69 -> V_79 ( V_69 , & V_75 ) ;
F_27 ( & V_69 -> V_78 ) ;
if ( V_77 < 0 ) {
if ( V_77 == - V_80 )
continue;
return V_77 ;
}
switch ( V_75 . V_81 & V_82 ) {
case V_83 :
if ( V_77 < V_73 )
return - V_84 ;
return V_77 ;
case V_85 :
return - V_18 ;
case V_86 :
F_28 ( 400 , 500 ) ;
break;
}
}
F_7 ( L_2 ) ;
return - V_18 ;
}
T_6 F_29 ( struct V_68 * V_69 , unsigned int V_71 ,
void * V_72 , T_5 V_73 )
{
return F_25 ( V_69 , V_87 , V_71 , V_72 ,
V_73 ) ;
}
T_6 F_30 ( struct V_68 * V_69 , unsigned int V_71 ,
void * V_72 , T_5 V_73 )
{
return F_25 ( V_69 , V_88 , V_71 , V_72 ,
V_73 ) ;
}
int F_31 ( struct V_68 * V_69 ,
T_3 V_89 [ V_39 ] )
{
return F_29 ( V_69 , V_41 , V_89 ,
V_39 ) ;
}
int F_32 ( struct V_68 * V_69 , struct V_90 * V_91 )
{
T_3 V_92 [ 3 ] ;
int V_77 ;
memset ( V_91 , 0 , sizeof( * V_91 ) ) ;
V_77 = F_29 ( V_69 , V_93 , V_92 , sizeof( V_92 ) ) ;
if ( V_77 < 0 )
return V_77 ;
V_91 -> V_94 = V_92 [ 0 ] ;
V_91 -> V_95 = F_24 ( V_92 [ 1 ] ) ;
V_91 -> V_96 = V_92 [ 2 ] & V_97 ;
if ( V_92 [ 2 ] & V_98 )
V_91 -> V_99 |= V_100 ;
return 0 ;
}
int F_33 ( struct V_68 * V_69 , struct V_90 * V_91 )
{
T_3 V_101 ;
int V_77 ;
if ( V_91 -> V_94 < 0x11 )
return 0 ;
V_77 = F_34 ( V_69 , V_102 , & V_101 ) ;
if ( V_77 < 0 )
return V_77 ;
V_101 &= ~ V_103 ;
V_101 |= V_104 ;
V_77 = F_35 ( V_69 , V_102 , V_101 ) ;
if ( V_77 < 0 )
return V_77 ;
F_28 ( 1000 , 2000 ) ;
return 0 ;
}
int F_36 ( struct V_68 * V_69 , struct V_90 * V_91 )
{
T_3 V_92 [ 2 ] ;
int V_77 ;
V_92 [ 0 ] = F_23 ( V_91 -> V_95 ) ;
V_92 [ 1 ] = V_91 -> V_96 ;
if ( V_91 -> V_99 & V_100 )
V_92 [ 1 ] |= V_105 ;
V_77 = F_30 ( V_69 , V_106 , V_92 , sizeof( V_92 ) ) ;
if ( V_77 < 0 )
return V_77 ;
return 0 ;
}
static T_4 F_37 ( struct V_1 * V_2 )
{
return V_30 | V_31 |
V_32 |
V_33 |
V_34 ;
}
static int F_38 ( struct V_68 * V_69 , struct V_74 * V_75 )
{
unsigned int V_76 ;
int V_77 ;
for ( V_76 = 0 ; V_76 < 7 ; V_76 ++ ) {
F_26 ( & V_69 -> V_78 ) ;
V_77 = V_69 -> V_79 ( V_69 , V_75 ) ;
F_27 ( & V_69 -> V_78 ) ;
if ( V_77 < 0 ) {
if ( V_77 == - V_80 )
continue;
F_7 ( L_3 , V_77 ) ;
return V_77 ;
}
switch ( V_75 -> V_81 & V_82 ) {
case V_83 :
break;
case V_85 :
F_7 ( L_4 ) ;
return - V_107 ;
case V_86 :
F_7 ( L_5 ) ;
F_28 ( 500 , 600 ) ;
continue;
default:
F_39 ( L_6 , V_75 -> V_81 ) ;
return - V_107 ;
}
switch ( V_75 -> V_81 & V_108 ) {
case V_109 :
if ( V_77 < V_75 -> V_73 )
return - V_84 ;
return 0 ;
case V_110 :
F_7 ( L_7 ) ;
return - V_107 ;
case V_111 :
F_7 ( L_8 ) ;
F_28 ( 400 , 500 ) ;
continue;
default:
F_39 ( L_9 , V_75 -> V_81 ) ;
return - V_107 ;
}
}
F_7 ( L_2 ) ;
return - V_107 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_20 * V_21 ,
int V_22 )
{
struct V_68 * V_69 = V_2 -> V_7 ;
unsigned int V_43 , V_112 ;
struct V_74 V_75 ;
int V_77 = 0 ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
for ( V_43 = 0 ; V_43 < V_22 ; V_43 ++ ) {
V_75 . V_10 = V_21 [ V_43 ] . V_29 ;
V_75 . V_70 = ( V_21 [ V_43 ] . V_27 & V_28 ) ?
V_113 :
V_114 ;
V_75 . V_70 |= V_115 ;
V_75 . V_72 = NULL ;
V_75 . V_73 = 0 ;
V_77 = F_38 ( V_69 , & V_75 ) ;
if ( V_77 < 0 )
break;
for ( V_112 = 0 ; V_112 < V_21 [ V_43 ] . V_25 ; V_112 ++ ) {
V_75 . V_72 = V_21 [ V_43 ] . V_26 + V_112 ;
V_75 . V_73 = 1 ;
V_77 = F_38 ( V_69 , & V_75 ) ;
if ( V_77 < 0 )
break;
}
if ( V_77 < 0 )
break;
}
if ( V_77 >= 0 )
V_77 = V_22 ;
V_75 . V_70 &= ~ V_115 ;
V_75 . V_72 = NULL ;
V_75 . V_73 = 0 ;
( void ) F_38 ( V_69 , & V_75 ) ;
return V_77 ;
}
int F_41 ( struct V_68 * V_69 )
{
F_42 ( & V_69 -> V_78 ) ;
V_69 -> V_116 . V_35 = & V_117 ;
V_69 -> V_116 . V_7 = V_69 ;
V_69 -> V_116 . V_37 = 3 ;
V_69 -> V_116 . V_118 = V_119 ;
V_69 -> V_116 . V_120 = V_121 ;
V_69 -> V_116 . V_122 . V_123 = V_69 -> V_122 ;
V_69 -> V_116 . V_122 . V_124 = V_69 -> V_122 -> V_124 ;
F_43 ( V_69 -> V_116 . V_125 , V_69 -> V_125 ? V_69 -> V_125 : F_44 ( V_69 -> V_122 ) ,
sizeof( V_69 -> V_116 . V_125 ) ) ;
return F_12 ( & V_69 -> V_116 ) ;
}
void F_45 ( struct V_68 * V_69 )
{
F_46 ( & V_69 -> V_116 ) ;
}
