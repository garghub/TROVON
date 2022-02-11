static struct V_1 * F_1 ( void )
{
unsigned int V_2 = 0 , V_3 ;
struct V_1 * V_4 ;
for ( V_2 = 0 ; V_2 < V_5 ; V_2 ++ ) {
if ( V_6 [ V_2 ] == NULL )
break;
}
if ( V_2 >= V_5 )
return F_2 ( - V_7 ) ;
V_4 = F_3 ( sizeof( struct V_1 ) , V_8 ) ;
if ( ! V_4 )
return F_2 ( - V_9 ) ;
V_4 -> V_10 = V_2 ;
V_4 -> V_11 = V_11 ;
V_4 -> V_12 = V_12 ;
F_4 ( & V_4 -> V_13 ) ;
F_5 ( & V_4 -> V_14 ) ;
F_6 ( & V_4 -> V_15 ) ;
V_4 -> V_16 = V_17 ;
F_5 ( & V_4 -> V_18 ) ;
V_4 -> V_19 = V_20 ;
V_4 -> V_21 = V_22 ;
for ( V_3 = 0 ; V_3 < V_23 ; V_3 ++ )
V_4 -> V_24 [ V_3 ] = V_25 ;
V_6 [ V_2 ] = V_4 ;
return V_4 ;
}
static void F_7 ( struct V_1 * V_4 )
{
if ( ! V_4 )
return;
V_6 [ V_4 -> V_10 ] = NULL ;
F_8 ( V_4 ) ;
}
static int F_9 ( struct V_1 * V_4 )
{
int V_26 , V_27 = 0 ;
struct V_28 * V_28 = V_4 -> V_28 ;
void T_1 * V_29 ;
if ( V_4 -> V_30 & V_31 )
return - V_32 ;
V_29 = V_4 -> V_29 ;
V_4 -> V_29 = NULL ;
F_10 ( V_28 , V_29 ) ;
V_26 = F_11 ( V_28 , V_33 ) ;
F_12 ( V_28 , V_26 ) ;
F_13 ( & V_28 -> V_34 , L_1 , V_35 ) ;
V_27 = F_14 ( V_28 ) ;
if ( V_27 ) {
F_15 ( & V_28 -> V_34 ,
L_2 , V_35 , V_27 ) ;
return V_27 ;
}
F_13 ( & V_28 -> V_34 , L_3 , V_35 , V_27 ) ;
V_4 -> V_30 &= ~ ( V_36 |
V_37 |
V_38 ) ;
V_27 = F_16 ( V_28 , V_26 , V_39 ) ;
if ( V_27 ) {
F_15 ( & V_28 -> V_34 ,
L_4 , V_35 , V_27 ) ;
return - V_32 ;
}
V_4 -> V_29 = F_17 ( V_28 , 0 , 0 ) ;
if ( V_4 -> V_29 == NULL ) {
F_15 ( & V_28 -> V_34 ,
L_5 , V_35 ) ;
return - V_9 ;
}
return 0 ;
}
bool F_18 ( struct V_1 * V_4 )
{
return ( V_4 -> V_40 & 0xFFFF0ull ) < 0x32170ull ;
}
static void F_19 ( struct V_1 * V_4 )
{
struct V_28 * V_28 = V_4 -> V_28 ;
if ( ( ( V_4 -> V_40 & 0xFFFF0ull ) >= 0x32000ull ) &&
( ( V_4 -> V_40 & 0xFFFF0ull ) <= 0x33250ull ) ) {
F_20 ( & V_28 -> V_34 ,
L_6 ,
V_4 -> V_40 , V_4 -> V_41 ) ;
F_21 ( V_4 , V_42 ,
0xFFFFFFFFFFFFFFFFull ) ;
F_21 ( V_4 , V_43 ,
0x0000000000000000ull ) ;
}
}
int F_22 ( struct V_1 * V_4 )
{
return ( V_4 -> V_40 & 0xFFFF0ull ) >= 0x32170ull ;
}
int F_23 ( struct V_1 * V_4 )
{
return ( V_4 -> V_40 & 0xFFFF0ull ) < 0x32170ull ;
}
static int F_24 ( struct V_1 * V_4 )
{
T_2 V_44 ;
static const int V_45 [] = { 4000 , 5000 , 6000 , 5714 } ;
V_44 = ( T_2 ) ( ( V_4 -> V_40 >> 28 ) & 0x0full ) ;
if ( V_44 >= F_25 ( V_45 ) )
return - 1 ;
return V_45 [ V_44 ] ;
}
static bool F_26 ( struct V_1 * V_4 )
{
T_3 V_45 = F_24 ( V_4 ) ;
T_4 V_46 ;
if ( V_47 == 0 )
return false ;
V_46 = F_27 ( V_47 *
16000000000uL / ( V_45 * 15 ) ) - 10 ;
F_28 ( V_4 , V_48 ,
0xff00 | ( V_46 & 0xff ) , 0 ) ;
return true ;
}
static bool F_29 ( struct V_1 * V_4 )
{
struct V_28 * V_28 = V_4 -> V_28 ;
unsigned int V_49 ;
T_3 V_45 = F_24 ( V_4 ) ;
T_4 V_46 ;
for ( V_49 = 0 ; V_49 < F_30 ( V_28 ) ; V_49 ++ ) {
if ( V_4 -> V_24 [ V_49 ] == 0 )
continue;
V_46 = F_27 ( V_4 -> V_24 [ V_49 ] *
16000000000uL / ( V_45 * 15 ) ) - 10 ;
F_28 ( V_4 , V_48 ,
0xff00 | ( V_46 & 0xff ) , V_49 + 1 ) ;
}
return true ;
}
static int F_31 ( struct V_1 * V_4 )
{
unsigned int type , V_50 = 0 ;
for ( type = 0 ; type < V_51 ; type ++ ) {
switch ( type ) {
case V_52 :
V_50 = F_32 ( V_4 , 0 ) ;
break;
case V_53 :
V_50 = F_32 ( V_4 , 1 ) ;
break;
case V_54 :
V_50 = F_32 ( V_4 , 2 ) ;
break;
case V_55 :
V_50 = V_56 ;
break;
}
V_4 -> V_57 [ type ] . V_58 = V_50 ;
V_4 -> V_57 [ type ] . V_59 = F_33 ( V_50 * sizeof( struct V_60 ) ,
V_8 ) ;
}
return 0 ;
}
static void F_34 ( struct V_1 * V_4 )
{
unsigned int type ;
for ( type = 0 ; type < V_51 ; type ++ ) {
F_8 ( V_4 -> V_57 [ type ] . V_59 ) ;
V_4 -> V_57 [ type ] . V_59 = NULL ;
}
}
static int F_35 ( struct V_1 * V_4 )
{
int V_61 = 0 ;
int V_62 ;
struct V_28 * V_28 = V_4 -> V_28 ;
V_4 -> V_40 = F_36 ( V_4 , V_63 ) ;
if ( V_4 -> V_40 == V_64 ) {
F_15 ( & V_28 -> V_34 ,
L_7 , V_4 -> V_40 ) ;
V_61 = - V_32 ;
goto V_65;
}
V_62 = F_37 ( V_4 ) ;
if ( V_62 < V_66 || V_62 == 0xff ) {
F_15 ( & V_28 -> V_34 ,
L_8 , V_62 ) ;
V_61 = - V_67 ;
goto V_65;
}
V_4 -> V_41 = F_36 ( V_4 , V_68 ) ;
if ( V_4 -> V_41 == V_64 ) {
F_15 ( & V_28 -> V_34 ,
L_9 , V_4 -> V_41 ) ;
V_61 = - V_32 ;
goto V_65;
}
F_38 ( V_4 , V_4 -> V_69 , sizeof( V_4 -> V_69 ) ) ;
if ( V_28 -> V_70 )
V_4 -> V_71 = 0 ;
else
V_4 -> V_71 = ( F_36 ( V_4 , V_72 )
!= V_64 ) ;
V_65:
return V_61 ;
}
static int F_39 ( struct V_1 * V_4 )
{
int V_61 ;
struct V_28 * V_28 = V_4 -> V_28 ;
V_61 = F_35 ( V_4 ) ;
if ( V_61 )
return V_61 ;
if ( F_40 ( V_4 ) ) {
F_31 ( V_4 ) ;
F_41 ( V_4 ) ;
F_42 ( V_4 , V_4 -> V_57 [ V_55 ] . V_59 ,
V_4 -> V_57 [ V_55 ] . V_58 , 0 ) ;
F_43 ( V_4 , V_52 ,
V_4 -> V_57 [ V_52 ] . V_59 ,
V_4 -> V_57 [ V_52 ] . V_58 ) ;
F_43 ( V_4 , V_53 ,
V_4 -> V_57 [ V_53 ] . V_59 ,
V_4 -> V_57 [ V_53 ] . V_58 ) ;
F_43 ( V_4 , V_54 ,
V_4 -> V_57 [ V_54 ] . V_59 ,
V_4 -> V_57 [ V_54 ] . V_58 ) ;
F_44 ( V_4 ) ;
if ( V_4 -> V_16 == V_73 ) {
F_20 ( & V_28 -> V_34 ,
L_10 , V_35 ) ;
V_4 -> V_74 = 0x7Cull ;
F_21 ( V_4 , V_75 ,
V_4 -> V_74 ) ;
V_61 = F_9 ( V_4 ) ;
if ( V_61 != 0 ) {
F_15 ( & V_28 -> V_34 ,
L_11 ,
V_35 ) ;
goto V_76;
}
V_61 = F_35 ( V_4 ) ;
if ( V_61 )
goto V_76;
}
}
V_61 = F_45 ( V_4 ) ;
if ( V_61 != 0 ) {
F_15 ( & V_28 -> V_34 ,
L_12 , V_35 ) ;
V_61 = - V_7 ;
goto V_76;
}
if ( F_40 ( V_4 ) ) {
F_19 ( V_4 ) ;
F_26 ( V_4 ) ;
F_29 ( V_4 ) ;
}
V_61 = F_46 ( V_4 ) ;
if ( V_61 < 0 ) {
F_15 ( & V_28 -> V_34 ,
L_13 , V_61 ) ;
goto V_77;
}
return 0 ;
V_77:
F_47 ( V_4 ) ;
V_76:
if ( F_40 ( V_4 ) )
F_34 ( V_4 ) ;
return - V_32 ;
}
static int F_48 ( struct V_1 * V_4 )
{
F_49 ( V_4 ) ;
F_50 ( V_4 ) ;
F_47 ( V_4 ) ;
if ( F_40 ( V_4 ) ) {
F_51 ( V_4 -> V_28 ) ;
F_34 ( V_4 ) ;
}
return 0 ;
}
static int F_52 ( struct V_1 * V_4 , int V_78 )
{
int V_27 ;
struct V_28 * V_28 = V_4 -> V_28 ;
F_48 ( V_4 ) ;
if ( ! V_78 ) {
V_4 -> V_74 = 0x70ull ;
F_21 ( V_4 , V_75 , V_4 -> V_74 ) ;
}
V_27 = F_9 ( V_4 ) ;
if ( V_27 != 0 ) {
F_15 ( & V_28 -> V_34 ,
L_14 , V_35 ) ;
return V_27 ;
}
V_27 = F_39 ( V_4 ) ;
if ( V_27 < 0 ) {
F_15 ( & V_28 -> V_34 ,
L_15 , V_35 ) ;
return V_27 ;
}
return 0 ;
}
static int F_53 ( struct V_1 * V_4 , T_4 * V_79 )
{
* V_79 = F_36 ( V_4 , V_80 ) ;
return ( * V_79 & V_81 ) &&
F_22 ( V_4 ) ;
}
static T_4 F_54 ( struct V_1 * V_4 )
{
int V_3 , V_82 = 0 ;
T_4 V_83 , V_84 , V_85 , V_86 , V_79 , V_87 , V_88 , V_89 ;
T_3 V_90 , V_91 , V_92 , V_93 , V_94 ;
struct V_28 * V_28 = V_4 -> V_28 ;
V_95:
V_82 ++ ;
if ( V_82 > 16 ) {
F_15 ( & V_28 -> V_34 , L_16 ,
V_82 ) ;
goto V_96;
}
V_79 = F_36 ( V_4 , V_80 ) ;
if ( V_79 != 0x0 )
F_15 ( & V_28 -> V_34 , L_17 ,
V_80 , V_79 ) ;
if ( V_79 == V_64 )
goto V_96;
if ( V_79 == 0 )
return 0 ;
V_87 = V_79 & V_81 ;
for ( V_86 = 0 ; V_86 < V_97 ; V_86 ++ ) {
V_90 = ( V_86 << 24 ) + 0x08 ;
V_84 = F_36 ( V_4 , V_90 ) ;
if ( V_84 == 0x0 )
continue;
F_15 ( & V_28 -> V_34 , L_17 , V_90 , V_84 ) ;
if ( V_84 == V_64 )
goto V_96;
V_92 = ( V_86 << 24 ) + 0x18 ;
V_85 = F_36 ( V_4 , V_92 ) ;
F_15 ( & V_28 -> V_34 , L_17 , V_92 , V_85 ) ;
if ( V_85 == V_64 )
goto V_96;
for ( V_3 = 0 , V_83 = 1ULL ; V_3 < 64 ; V_3 ++ , V_83 <<= 1 ) {
if ( ( V_84 & V_83 ) == 0x0 )
continue;
V_93 = ( V_86 << 24 ) + 0x100 + 0x08 * V_3 ;
V_88 = F_36 ( V_4 , V_93 ) ;
if ( V_88 == V_64 )
goto V_96;
F_15 ( & V_28 -> V_34 ,
L_17 , V_93 , V_88 ) ;
V_94 = ( V_86 << 24 ) + 0x300 + 0x08 * V_3 ;
V_89 = F_36 ( V_4 , V_94 ) ;
if ( V_89 == V_64 )
goto V_96;
F_15 ( & V_28 -> V_34 ,
L_17 , V_94 , V_89 ) ;
V_79 = F_36 ( V_4 , V_80 ) ;
if ( V_79 == V_64 )
goto V_96;
if ( ( V_87 == 0x0 ) &&
( V_79 & V_81 ) ) {
goto V_95;
}
if ( V_87 == 0x0 ) {
V_93 = ( V_86 << 24 ) + 0x100 + 0x08 * V_3 ;
F_21 ( V_4 , V_93 , V_88 ) ;
F_13 ( & V_28 -> V_34 ,
L_18
L_19 , V_93 , V_88 ) ;
V_91 = ( V_86 << 24 ) + 0x10 ;
F_21 ( V_4 , V_91 , V_83 ) ;
F_13 ( & V_28 -> V_34 ,
L_20
L_19 , V_91 ,
V_83 ) ;
}
}
}
V_79 = F_36 ( V_4 , V_80 ) ;
if ( V_79 == V_64 )
goto V_96;
if ( ( V_87 == 0x0 ) && ( V_79 & V_81 ) ) {
F_13 ( & V_28 -> V_34 , L_21 ,
V_82 ) ;
goto V_95;
}
return V_87 ;
V_96:
return V_64 ;
}
static int F_55 ( void * V_98 )
{
int V_27 , V_99 = 0 ;
struct V_1 * V_4 = V_98 ;
struct V_28 * V_28 = V_4 -> V_28 ;
T_4 V_79 , V_87 , V_40 , V_41 ;
while ( ! F_56 () ) {
V_27 = F_57 ( V_4 -> V_100 ,
( F_53 ( V_4 , & V_79 ) ||
( V_99 = F_56 () ) ) ,
V_101 * V_102 ) ;
if ( V_99 )
break;
if ( V_79 == V_64 ) {
F_15 ( & V_28 -> V_34 ,
L_22 , V_35 , V_79 ) ;
goto V_96;
}
V_40 = F_36 ( V_4 , V_63 ) ;
if ( V_40 == V_64 ) {
F_15 ( & V_28 -> V_34 ,
L_23 ,
V_35 , V_40 ) ;
goto V_96;
}
V_41 = F_36 ( V_4 , V_68 ) ;
if ( V_41 == V_64 ) {
F_15 ( & V_28 -> V_34 ,
L_24 ,
V_35 , V_41 ) ;
goto V_96;
}
V_79 = F_36 ( V_4 , V_80 ) ;
if ( V_79 == V_64 ) {
F_15 ( & V_28 -> V_34 ,
L_25 , V_35 ,
( V_79 & V_81 ) ? L_26 : L_27 ,
V_79 ) ;
goto V_96;
}
V_87 = F_54 ( V_4 ) ;
if ( V_87 == V_64 )
goto V_96;
if ( ( V_87 ) && ! V_4 -> V_103 &&
F_22 ( V_4 ) ) {
V_4 -> V_16 = V_73 ;
V_27 = F_52 ( V_4 , 0 ) ;
if ( V_27 < 0 ) {
goto V_96;
}
}
V_4 -> V_104 = V_79 ;
F_58 () ;
}
return 0 ;
V_96:
F_15 ( & V_28 -> V_34 ,
L_28 , V_35 ) ;
V_4 -> V_16 = V_73 ;
F_48 ( V_4 ) ;
while ( ! F_56 () )
F_58 () ;
return - V_32 ;
}
static int F_59 ( struct V_1 * V_4 )
{
int V_27 ;
if ( V_101 <= 0 )
return 0 ;
V_4 -> V_105 = F_60 ( F_55 , V_4 ,
V_106 L_29 ,
V_4 -> V_10 ) ;
if ( F_61 ( V_4 -> V_105 ) ) {
V_27 = F_62 ( V_4 -> V_105 ) ;
V_4 -> V_105 = NULL ;
return V_27 ;
}
return 0 ;
}
static int F_63 ( struct V_1 * V_4 )
{
return V_4 -> V_105 != NULL ;
}
static int F_64 ( struct V_1 * V_4 )
{
int V_27 ;
if ( ! F_63 ( V_4 ) )
return - V_32 ;
V_27 = F_65 ( V_4 -> V_105 ) ;
V_4 -> V_105 = NULL ;
return 0 ;
}
static int F_66 ( struct V_1 * V_4 )
{
int V_61 , V_26 ;
struct V_28 * V_28 = V_4 -> V_28 ;
V_26 = F_11 ( V_28 , V_33 ) ;
V_61 = F_67 ( V_28 ) ;
if ( V_61 ) {
F_15 ( & V_28 -> V_34 ,
L_30 , V_61 ) ;
goto V_107;
}
V_61 = F_16 ( V_28 , V_26 , V_39 ) ;
if ( V_61 ) {
F_15 ( & V_28 -> V_34 ,
L_4 , V_35 , V_61 ) ;
V_61 = - V_32 ;
goto V_108;
}
if ( ! F_68 ( V_28 , F_69 ( 64 ) ) ) {
V_61 = F_70 ( V_28 , F_69 ( 64 ) ) ;
if ( V_61 ) {
F_15 ( & V_28 -> V_34 ,
L_31 ) ;
V_61 = - V_32 ;
goto V_109;
}
} else if ( ! F_68 ( V_28 , F_69 ( 32 ) ) ) {
V_61 = F_70 ( V_28 , F_69 ( 32 ) ) ;
if ( V_61 ) {
F_15 ( & V_28 -> V_34 ,
L_32 ) ;
V_61 = - V_32 ;
goto V_109;
}
} else {
F_15 ( & V_28 -> V_34 ,
L_33 ) ;
V_61 = - V_32 ;
goto V_109;
}
F_71 ( V_28 ) ;
F_72 ( V_28 ) ;
V_4 -> V_110 = F_73 ( V_28 , 0 ) ;
V_4 -> V_29 = F_17 ( V_28 , 0 , 0 ) ;
if ( V_4 -> V_29 == NULL ) {
F_15 ( & V_28 -> V_34 ,
L_5 , V_35 ) ;
V_61 = - V_9 ;
goto V_109;
}
V_4 -> V_111 = F_30 ( V_28 ) ;
V_61 = F_35 ( V_4 ) ;
if ( V_61 )
goto V_112;
return 0 ;
V_112:
F_10 ( V_28 , V_4 -> V_29 ) ;
V_109:
F_12 ( V_28 , V_26 ) ;
V_108:
F_74 ( V_28 ) ;
V_107:
return V_61 ;
}
static void F_75 ( struct V_1 * V_4 )
{
int V_26 ;
struct V_28 * V_28 = V_4 -> V_28 ;
if ( V_4 -> V_29 )
F_10 ( V_28 , V_4 -> V_29 ) ;
V_26 = F_11 ( V_28 , V_33 ) ;
F_12 ( V_28 , V_26 ) ;
F_74 ( V_28 ) ;
}
static int F_76 ( struct V_28 * V_28 ,
const struct V_113 * V_114 )
{
int V_61 ;
struct V_1 * V_4 ;
F_77 () ;
V_4 = F_1 () ;
if ( F_61 ( V_4 ) ) {
F_15 ( & V_28 -> V_34 , L_34 ,
( int ) F_62 ( V_4 ) ) ;
return F_62 ( V_4 ) ;
}
F_78 ( & V_28 -> V_34 , V_4 ) ;
V_4 -> V_28 = V_28 ;
V_61 = F_66 ( V_4 ) ;
if ( V_61 < 0 ) {
F_15 ( & V_28 -> V_34 ,
L_35 , V_61 ) ;
goto V_115;
}
V_61 = F_39 ( V_4 ) ;
if ( V_61 < 0 ) {
F_15 ( & V_28 -> V_34 ,
L_36 , V_61 ) ;
goto V_116;
}
if ( F_40 ( V_4 ) ) {
V_61 = F_59 ( V_4 ) ;
if ( V_61 < 0 ) {
F_15 ( & V_28 -> V_34 ,
L_37
L_38 , V_61 ) ;
goto V_117;
}
}
return 0 ;
V_117:
F_48 ( V_4 ) ;
V_116:
F_75 ( V_4 ) ;
V_115:
F_7 ( V_4 ) ;
return V_61 ;
}
static void F_79 ( struct V_28 * V_28 )
{
struct V_1 * V_4 = F_80 ( & V_28 -> V_34 ) ;
F_64 ( V_4 ) ;
F_48 ( V_4 ) ;
F_75 ( V_4 ) ;
F_7 ( V_4 ) ;
}
static T_5 F_81 ( struct V_28 * V_28 ,
enum V_118 V_119 )
{
struct V_1 * V_4 ;
F_15 ( & V_28 -> V_34 , L_39 , V_35 , V_119 ) ;
if ( V_28 == NULL )
return V_120 ;
V_4 = F_80 ( & V_28 -> V_34 ) ;
if ( V_4 == NULL )
return V_120 ;
switch ( V_119 ) {
case V_121 :
return V_122 ;
case V_123 :
return V_120 ;
case V_124 :
return V_125 ;
}
return V_120 ;
}
static T_5 F_82 ( struct V_28 * V_34 )
{
return V_126 ;
}
static void F_83 ( struct V_28 * V_34 )
{
}
static int F_84 ( struct V_28 * V_34 , int V_127 )
{
struct V_1 * V_4 = F_80 ( & V_34 -> V_34 ) ;
if ( V_127 > 0 ) {
F_29 ( V_4 ) ;
F_85 ( V_34 , V_127 ) ;
return V_127 ;
}
if ( V_127 == 0 ) {
F_51 ( V_34 ) ;
return 0 ;
}
return 0 ;
}
static int T_6 F_86 ( void )
{
int V_27 ;
V_11 = F_87 ( V_128 , V_106 ) ;
if ( F_61 ( V_11 ) ) {
F_88 ( L_40 , V_35 ) ;
return - V_9 ;
}
V_12 = F_89 ( V_106 , NULL ) ;
if ( ! V_12 ) {
V_27 = - V_9 ;
goto V_107;
}
V_27 = F_90 ( & V_129 ) ;
if ( V_27 != 0 ) {
F_88 ( L_41 , V_35 , V_27 ) ;
goto V_130;
}
return V_27 ;
V_130:
F_91 ( V_12 ) ;
V_107:
F_92 ( V_11 ) ;
return V_27 ;
}
static void T_7 F_93 ( void )
{
F_94 ( & V_129 ) ;
F_91 ( V_12 ) ;
F_92 ( V_11 ) ;
}
