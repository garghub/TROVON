static T_1 T_2 F_1 ( T_3 * V_1 )
{
return F_2 ( V_1 -> V_2 + V_3 ) & V_4 ;
}
static T_1 void F_3 ( T_3 * V_1 , T_2 V_5 )
{
T_2 V_6 = F_2 ( V_1 -> V_2 + V_3 ) ;
F_4 ( ( V_6 & ~ V_4 ) | V_5 , V_1 -> V_2 + V_3 ) ;
}
static void F_5 ( T_4 * V_7 )
{
T_3 * V_1 = V_7 -> V_1 ;
int V_2 = V_1 -> V_2 ;
T_2 V_8 = F_2 ( V_2 + V_9 ) ;
T_2 V_10 = F_6 ( V_7 ) ;
T_2 V_11 = V_7 -> V_11 & V_12 ;
T_2 V_13 = V_7 -> V_13 & V_12 ;
switch( V_7 -> V_14 . V_15 ) {
case V_16 :
V_8 |= V_7 -> V_17 ? V_18 : V_19 ;
V_11 |= V_20 ;
V_13 |= V_21 ;
break;
case V_22 :
V_8 |= V_7 -> V_17 ? V_18 : V_19 ;
V_11 |= V_23 ;
V_13 |= V_24 ;
break;
case V_25 :
V_8 |= V_7 -> V_17 ? V_18 : V_19 ;
V_11 |= V_23 ;
V_13 |= V_21 ;
break;
default:
V_8 &= V_7 -> V_17 ? ~ V_18 : ~ V_19 ;
V_11 |= V_23 ;
V_13 |= V_26 ;
}
F_4 ( V_8 , V_2 + V_9 ) ;
V_7 -> V_11 = V_11 ;
V_7 -> V_13 = V_13 ;
F_7 ( V_11 , V_10 + V_27 , V_1 ) ;
F_7 ( V_13 , V_10 + V_28 , V_1 ) ;
F_8 ( V_7 ) ;
}
static int F_9 ( struct V_29 * V_30 )
{
T_4 * V_7 = F_10 ( V_30 ) ;
int V_2 = V_7 -> V_1 -> V_2 ;
T_2 V_8 = F_2 ( V_2 + V_9 ) | ( V_7 -> V_17 ? V_31 : V_32 ) ;
int V_33 ;
V_33 = F_11 ( V_30 ) ;
if ( V_33 )
return V_33 ;
V_8 &= V_7 -> V_17 ? ~ V_34 : ~ V_35 ;
F_4 ( V_8 , V_2 + V_9 ) ;
F_4 ( F_2 ( V_2 + V_36 ) | V_37 , V_2 + V_36 ) ;
F_4 ( F_2 ( V_2 + V_3 ) | V_38 , V_2 + V_3 ) ;
F_12 ( V_30 ) ;
F_5 ( V_7 ) ;
return 0 ;
}
static int F_13 ( struct V_29 * V_30 )
{
T_4 * V_7 = F_10 ( V_30 ) ;
int V_2 = V_7 -> V_1 -> V_2 ;
T_2 V_8 = F_2 ( V_2 + V_9 ) | ( V_7 -> V_17 ? V_31 : V_32 ) ;
F_14 ( V_30 ) ;
V_8 |= V_7 -> V_17 ? V_34 : V_35 ;
F_4 ( V_8 , V_2 + V_9 ) ;
F_15 ( V_30 ) ;
return 0 ;
}
static int F_16 ( struct V_29 * V_30 , struct V_39 * V_40 , int V_41 )
{
const T_5 V_42 = sizeof( V_43 ) ;
V_43 V_44 ;
V_43 T_6 * line = V_40 -> V_45 . V_46 . V_47 ;
T_4 * V_7 = F_10 ( V_30 ) ;
#ifdef F_17
if ( V_41 == V_48 ) {
F_18 ( V_30 ) ;
return 0 ;
}
#endif
if ( V_41 != V_49 )
return F_19 ( V_30 , V_40 , V_41 ) ;
switch( V_40 -> V_45 . type ) {
case V_50 :
V_40 -> V_45 . type = V_51 ;
if ( V_40 -> V_45 . V_42 < V_42 ) {
V_40 -> V_45 . V_42 = V_42 ;
return - V_52 ;
}
if ( F_20 ( line , & V_7 -> V_14 , V_42 ) )
return - V_53 ;
return 0 ;
case V_51 :
if( ! F_21 ( V_54 ) )
return - V_55 ;
if ( F_22 ( & V_44 , line , V_42 ) )
return - V_53 ;
if ( V_44 . V_15 != V_56 &&
V_44 . V_15 != V_25 &&
V_44 . V_15 != V_16 &&
V_44 . V_15 != V_22 )
return - V_57 ;
if ( V_44 . V_58 != 0 && V_44 . V_58 != 1 )
return - V_57 ;
memcpy ( & V_7 -> V_14 , & V_44 , V_42 ) ;
F_5 ( V_7 ) ;
return 0 ;
default:
return F_19 ( V_30 , V_40 , V_41 ) ;
}
}
static void F_23 ( T_3 * V_1 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < 2 ; V_59 ++ )
if ( V_1 -> V_60 [ V_59 ] . V_1 ) {
struct V_29 * V_30 = F_24 ( & V_1 -> V_60 [ V_59 ] ) ;
F_25 ( V_30 ) ;
}
if ( V_1 -> V_61 )
F_26 ( V_1 -> V_61 , V_1 ) ;
if ( V_1 -> V_62 ) {
F_27 ( V_1 -> V_62 ) ;
F_28 ( V_1 -> V_63 , V_64 ) ;
}
if ( V_1 -> V_2 )
F_29 ( V_1 -> V_2 , V_65 ) ;
if ( V_1 -> V_60 [ 0 ] . V_30 )
F_30 ( V_1 -> V_60 [ 0 ] . V_30 ) ;
if ( V_1 -> V_60 [ 1 ] . V_30 )
F_30 ( V_1 -> V_60 [ 1 ] . V_30 ) ;
F_31 ( V_1 ) ;
}
static int T_7 F_32 ( unsigned long V_2 , unsigned long V_61 ,
unsigned long V_62 , long V_66 , long V_67 )
{
T_3 * V_1 ;
T_2 V_59 , V_68 ;
int V_69 ;
if ( V_2 < 0x200 || V_2 > 0x3FF || ( V_2 % V_65 ) != 0 ) {
F_33 ( L_1 ) ;
return - V_70 ;
}
if ( V_61 < 3 || V_61 > 15 || V_61 == 6 ) {
F_33 ( L_2 ) ;
return - V_70 ;
}
if ( V_62 < 0xA0000 || V_62 > 0xFFFFF || ( V_62 & 0xFFF ) != 0 ) {
F_33 ( L_3 ) ;
return - V_70 ;
}
V_1 = F_34 ( sizeof( T_3 ) , V_71 ) ;
if ( V_1 == NULL )
return - V_52 ;
V_1 -> V_60 [ 0 ] . V_30 = F_35 ( & V_1 -> V_60 [ 0 ] ) ;
V_1 -> V_60 [ 1 ] . V_30 = F_35 ( & V_1 -> V_60 [ 1 ] ) ;
if ( ! V_1 -> V_60 [ 0 ] . V_30 || ! V_1 -> V_60 [ 1 ] . V_30 ) {
F_33 ( L_4 ) ;
F_23 ( V_1 ) ;
return - V_72 ;
}
if ( ! F_36 ( V_2 , V_65 , V_73 ) ) {
F_33 ( L_5 ) ;
F_23 ( V_1 ) ;
return - V_74 ;
}
V_1 -> V_2 = V_2 ;
if ( F_37 ( V_61 , V_75 , 0 , V_73 , V_1 ) ) {
F_33 ( L_6 ) ;
F_23 ( V_1 ) ;
return - V_74 ;
}
V_1 -> V_61 = V_61 ;
if ( ! F_38 ( V_62 , V_64 , V_73 ) ) {
F_33 ( L_7 ) ;
F_23 ( V_1 ) ;
return - V_74 ;
}
V_1 -> V_63 = V_62 ;
V_1 -> V_62 = F_39 ( V_62 , V_64 ) ;
if ( ! V_1 -> V_62 ) {
F_33 ( L_8 ) ;
F_23 ( V_1 ) ;
return - V_53 ;
}
F_4 ( 0 , V_2 + V_36 ) ;
F_4 ( V_62 >> 12 , V_2 + V_76 ) ;
switch ( V_64 ) {
case 16384 :
F_4 ( V_77 , V_2 + V_3 ) ;
break;
case 32768 :
F_4 ( V_78 , V_2 + V_3 ) ;
break;
case 65536 :
F_4 ( V_79 , V_2 + V_3 ) ;
break;
default:
F_33 ( L_9 ) ;
F_23 ( V_1 ) ;
return - V_70 ;
}
V_68 = V_37 | V_80 | ( V_81 ? V_82 : 0 ) ;
F_4 ( V_68 , V_2 + V_36 ) ;
V_1 -> V_83 = F_40 ( V_1 , V_1 -> V_62 , V_84 ) ;
V_69 = V_1 -> V_83 / ( ( V_66 + V_67 ) * ( sizeof( V_85 ) +
V_86 ) ) ;
V_1 -> V_87 = F_41 ( V_69 / 2 , V_88 ) ;
V_1 -> V_89 = V_69 - V_1 -> V_87 ;
V_1 -> V_90 = ( V_66 + V_67 ) * sizeof( V_85 ) *
( V_1 -> V_87 + V_1 -> V_89 ) ;
F_42 ( L_10 ,
V_1 -> V_83 / 1024 , V_1 -> V_61 ,
V_1 -> V_87 , V_1 -> V_89 ) ;
if ( V_1 -> V_87 < 1 ) {
F_33 ( L_11 ) ;
F_23 ( V_1 ) ;
return - V_91 ;
}
V_68 |= V_92 ;
F_4 ( V_68 , V_2 + V_36 ) ;
F_4 ( 0 , V_2 + V_9 ) ;
F_43 ( V_1 , 0 ) ;
for ( V_59 = 0 ; V_59 < 2 ; V_59 ++ ) {
T_4 * V_7 = & V_1 -> V_60 [ V_59 ] ;
struct V_29 * V_30 = F_24 ( V_7 ) ;
T_8 * V_93 = F_44 ( V_30 ) ;
if ( ( V_59 == 0 && ! V_66 ) || ( V_59 == 1 && ! V_67 ) )
continue;
V_7 -> V_17 = V_59 ;
V_7 -> V_94 = 1 ;
if ( ( V_59 == 1 ) && V_66 )
V_7 -> V_95 = 1 ;
F_45 ( & V_7 -> V_96 ) ;
V_30 -> V_61 = V_61 ;
V_30 -> V_97 = V_62 ;
V_30 -> V_98 = V_62 + V_64 - 1 ;
V_30 -> V_99 = 50 ;
V_30 -> V_100 = & V_101 ;
V_93 -> V_102 = V_103 ;
V_93 -> V_104 = V_105 ;
V_7 -> V_14 . V_15 = V_56 ;
V_7 -> V_1 = V_1 ;
if ( F_46 ( V_30 ) ) {
F_47 ( L_12 ) ;
V_7 -> V_1 = NULL ;
F_23 ( V_1 ) ;
return - V_52 ;
}
F_48 ( V_7 ) ;
F_49 ( V_30 , L_13 , V_7 -> V_17 ) ;
}
* V_106 = V_1 ;
V_106 = & V_1 -> V_107 ;
return 0 ;
}
static int T_7 F_50 ( void )
{
if ( V_108 == NULL ) {
#ifdef F_51
F_42 ( L_14 ) ;
#endif
return - V_57 ;
}
F_42 ( L_15 , V_109 ) ;
do {
unsigned long V_2 , V_61 , V_110 ;
long V_94 [ 2 ] = { 0 , 0 } ;
V_2 = F_52 ( V_108 , & V_108 , 0 ) ;
if ( * V_108 ++ != ',' )
break;
V_61 = F_52 ( V_108 , & V_108 , 0 ) ;
if ( * V_108 ++ != ',' )
break;
V_110 = F_52 ( V_108 , & V_108 , 0 ) ;
if ( * V_108 ++ != ',' )
break;
while( 1 ) {
if ( * V_108 == '0' && ! V_94 [ 0 ] )
V_94 [ 0 ] = 1 ;
else if ( * V_108 == '1' && ! V_94 [ 1 ] )
V_94 [ 1 ] = 1 ;
else
break;
V_108 ++ ;
}
if ( ! V_94 [ 0 ] && ! V_94 [ 1 ] )
break;
if ( * V_108 == ':' || * V_108 == '\x0' )
F_32 ( V_2 , V_61 , V_110 , V_94 [ 0 ] , V_94 [ 1 ] ) ;
if ( * V_108 == '\x0' )
return V_111 ? 0 : - V_57 ;
}while( * V_108 ++ == ':' );
F_33 ( L_16 ) ;
return V_111 ? 0 : - V_57 ;
}
static void T_9 F_53 ( void )
{
T_3 * V_1 = V_111 ;
while ( V_1 ) {
T_3 * V_112 = V_1 ;
V_1 = V_1 -> V_107 ;
F_23 ( V_112 ) ;
}
}
