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
V_4 -> V_13 = V_14 ;
F_4 ( & V_4 -> V_15 ) ;
F_5 ( & V_4 -> V_16 ) ;
F_6 ( & V_4 -> V_17 ) ;
V_4 -> V_18 = V_19 ;
F_5 ( & V_4 -> V_20 ) ;
V_4 -> V_21 = V_22 ;
V_4 -> V_23 = V_24 ;
for ( V_3 = 0 ; V_3 < V_25 ; V_3 ++ )
V_4 -> V_26 [ V_3 ] = V_27 ;
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
int V_28 = 0 ;
struct V_29 * V_29 = V_4 -> V_29 ;
void T_1 * V_30 ;
if ( V_4 -> V_31 & V_32 )
return - V_33 ;
V_30 = V_4 -> V_30 ;
V_4 -> V_30 = NULL ;
F_10 ( V_29 , V_30 ) ;
F_11 ( V_29 ) ;
F_12 ( & V_29 -> V_34 , L_1 , V_35 ) ;
V_28 = F_13 ( V_29 ) ;
if ( V_28 ) {
F_14 ( & V_29 -> V_34 ,
L_2 , V_35 , V_28 ) ;
return V_28 ;
}
F_12 ( & V_29 -> V_34 , L_3 , V_35 , V_28 ) ;
V_4 -> V_31 &= ~ ( V_36 |
V_37 |
V_38 ) ;
V_28 = F_15 ( V_29 , V_39 ) ;
if ( V_28 ) {
F_14 ( & V_29 -> V_34 ,
L_4 , V_35 , V_28 ) ;
return - V_33 ;
}
V_4 -> V_30 = F_16 ( V_29 , 0 , 0 ) ;
if ( V_4 -> V_30 == NULL ) {
F_14 ( & V_29 -> V_34 ,
L_5 , V_35 ) ;
return - V_9 ;
}
return 0 ;
}
bool F_17 ( struct V_1 * V_4 )
{
return ( V_4 -> V_40 & 0xFFFF0ull ) < 0x32170ull ;
}
static void F_18 ( struct V_1 * V_4 )
{
struct V_29 * V_29 = V_4 -> V_29 ;
if ( ( ( V_4 -> V_40 & 0xFFFF0ull ) >= 0x32000ull ) &&
( ( V_4 -> V_40 & 0xFFFF0ull ) <= 0x33250ull ) ) {
F_19 ( & V_29 -> V_34 ,
L_6 ,
V_4 -> V_40 , V_4 -> V_41 ) ;
F_20 ( V_4 , V_42 ,
0xFFFFFFFFFFFFFFFFull ) ;
F_20 ( V_4 , V_43 ,
0x0000000000000000ull ) ;
}
}
int F_21 ( struct V_1 * V_4 )
{
return ( V_4 -> V_40 & 0xFFFF0ull ) >= 0x32170ull ;
}
int F_22 ( struct V_1 * V_4 )
{
return ( V_4 -> V_40 & 0xFFFF0ull ) < 0x32170ull ;
}
static int F_23 ( struct V_1 * V_4 )
{
T_2 V_44 ;
static const int V_45 [] = { 4000 , 5000 , 6000 , 5714 } ;
V_44 = ( T_2 ) ( ( V_4 -> V_40 >> 28 ) & 0x0full ) ;
if ( V_44 >= F_24 ( V_45 ) )
return - 1 ;
return V_45 [ V_44 ] ;
}
static bool F_25 ( struct V_1 * V_4 )
{
T_3 V_45 = F_23 ( V_4 ) ;
T_4 V_46 ;
if ( V_47 == 0 )
return false ;
V_46 = F_26 ( V_47 *
16000000000uL / ( V_45 * 15 ) ) - 10 ;
F_27 ( V_4 , V_48 ,
0xff00 | ( V_46 & 0xff ) , 0 ) ;
return true ;
}
static bool F_28 ( struct V_1 * V_4 )
{
struct V_29 * V_29 = V_4 -> V_29 ;
unsigned int V_49 ;
T_3 V_45 = F_23 ( V_4 ) ;
T_4 V_46 ;
int V_50 ;
V_50 = F_29 ( V_29 ) ;
if ( V_50 <= 0 )
return false ;
for ( V_49 = 0 ; V_49 < V_50 ; V_49 ++ ) {
if ( V_4 -> V_26 [ V_49 ] == 0 )
continue;
V_46 = F_26 ( V_4 -> V_26 [ V_49 ] *
16000000000uL / ( V_45 * 15 ) ) - 10 ;
F_27 ( V_4 , V_48 ,
0xff00 | ( V_46 & 0xff ) , V_49 + 1 ) ;
}
return true ;
}
static int F_30 ( struct V_1 * V_4 )
{
unsigned int type , V_51 = 0 ;
for ( type = 0 ; type < V_52 ; type ++ ) {
switch ( type ) {
case V_53 :
V_51 = F_31 ( V_4 , 0 ) ;
break;
case V_54 :
V_51 = F_31 ( V_4 , 1 ) ;
break;
case V_55 :
V_51 = F_31 ( V_4 , 2 ) ;
break;
case V_56 :
V_51 = V_57 ;
break;
}
V_4 -> V_58 [ type ] . V_59 = V_51 ;
V_4 -> V_58 [ type ] . V_60 =
F_32 ( V_51 , sizeof( struct V_61 ) ,
V_8 ) ;
}
return 0 ;
}
static void F_33 ( struct V_1 * V_4 )
{
unsigned int type ;
for ( type = 0 ; type < V_52 ; type ++ ) {
F_8 ( V_4 -> V_58 [ type ] . V_60 ) ;
V_4 -> V_58 [ type ] . V_60 = NULL ;
}
}
static int F_34 ( struct V_1 * V_4 )
{
int V_62 = 0 ;
int V_63 ;
struct V_29 * V_29 = V_4 -> V_29 ;
V_4 -> V_40 = F_35 ( V_4 , V_64 ) ;
if ( V_4 -> V_40 == V_65 ) {
F_14 ( & V_29 -> V_34 ,
L_7 , V_4 -> V_40 ) ;
V_62 = - V_33 ;
goto V_66;
}
V_63 = F_36 ( V_4 ) ;
if ( V_63 < V_67 || V_63 == 0xff ) {
F_14 ( & V_29 -> V_34 ,
L_8 , V_63 ) ;
V_62 = - V_68 ;
goto V_66;
}
V_4 -> V_41 = F_35 ( V_4 , V_69 ) ;
if ( V_4 -> V_41 == V_65 ) {
F_14 ( & V_29 -> V_34 ,
L_9 , V_4 -> V_41 ) ;
V_62 = - V_33 ;
goto V_66;
}
F_37 ( V_4 , V_4 -> V_70 , sizeof( V_4 -> V_70 ) ) ;
if ( V_29 -> V_71 )
V_4 -> V_72 = 0 ;
else
V_4 -> V_72 = ( F_35 ( V_4 , V_73 )
!= V_65 ) ;
V_66:
return V_62 ;
}
static int F_38 ( struct V_1 * V_4 )
{
int V_62 ;
struct V_29 * V_29 = V_4 -> V_29 ;
V_62 = F_34 ( V_4 ) ;
if ( V_62 )
return V_62 ;
if ( F_39 ( V_4 ) ) {
F_30 ( V_4 ) ;
F_40 ( V_4 ) ;
F_41 ( V_4 , V_4 -> V_58 [ V_56 ] . V_60 ,
V_4 -> V_58 [ V_56 ] . V_59 , 0 ) ;
F_42 ( V_4 , V_53 ,
V_4 -> V_58 [ V_53 ] . V_60 ,
V_4 -> V_58 [ V_53 ] . V_59 ) ;
F_42 ( V_4 , V_54 ,
V_4 -> V_58 [ V_54 ] . V_60 ,
V_4 -> V_58 [ V_54 ] . V_59 ) ;
F_42 ( V_4 , V_55 ,
V_4 -> V_58 [ V_55 ] . V_60 ,
V_4 -> V_58 [ V_55 ] . V_59 ) ;
F_43 ( V_4 ) ;
if ( V_4 -> V_18 == V_74 ) {
F_19 ( & V_29 -> V_34 ,
L_10 , V_35 ) ;
V_4 -> V_75 = 0x7Cull ;
F_20 ( V_4 , V_76 ,
V_4 -> V_75 ) ;
V_62 = F_9 ( V_4 ) ;
if ( V_62 != 0 ) {
F_14 ( & V_29 -> V_34 ,
L_11 ,
V_35 ) ;
goto V_77;
}
V_62 = F_34 ( V_4 ) ;
if ( V_62 )
goto V_77;
}
}
V_62 = F_44 ( V_4 ) ;
if ( V_62 != 0 ) {
F_14 ( & V_29 -> V_34 ,
L_12 , V_35 ) ;
V_62 = - V_7 ;
goto V_77;
}
if ( F_39 ( V_4 ) ) {
F_18 ( V_4 ) ;
F_25 ( V_4 ) ;
F_28 ( V_4 ) ;
}
V_62 = F_45 ( V_4 ) ;
if ( V_62 < 0 ) {
F_14 ( & V_29 -> V_34 ,
L_13 , V_62 ) ;
goto V_78;
}
return 0 ;
V_78:
F_46 ( V_4 ) ;
V_77:
if ( F_39 ( V_4 ) )
F_33 ( V_4 ) ;
return - V_33 ;
}
static int F_47 ( struct V_1 * V_4 )
{
F_48 ( V_4 ) ;
F_49 ( V_4 ) ;
F_46 ( V_4 ) ;
if ( F_39 ( V_4 ) ) {
F_50 ( V_4 -> V_29 ) ;
F_33 ( V_4 ) ;
}
return 0 ;
}
static int F_51 ( struct V_1 * V_4 , int V_79 )
{
int V_28 ;
struct V_29 * V_29 = V_4 -> V_29 ;
F_47 ( V_4 ) ;
if ( ! V_79 ) {
V_4 -> V_75 = 0x70ull ;
F_20 ( V_4 , V_76 , V_4 -> V_75 ) ;
}
V_28 = F_9 ( V_4 ) ;
if ( V_28 != 0 ) {
F_14 ( & V_29 -> V_34 ,
L_14 , V_35 ) ;
return V_28 ;
}
V_28 = F_38 ( V_4 ) ;
if ( V_28 < 0 ) {
F_14 ( & V_29 -> V_34 ,
L_15 , V_35 ) ;
return V_28 ;
}
return 0 ;
}
static int F_52 ( struct V_1 * V_4 , T_4 * V_80 )
{
* V_80 = F_35 ( V_4 , V_81 ) ;
return ( * V_80 & V_82 ) &&
F_21 ( V_4 ) ;
}
static T_4 F_53 ( struct V_1 * V_4 )
{
int V_3 , V_83 = 0 ;
T_4 V_84 , V_85 , V_86 , V_87 , V_80 , V_88 , V_89 , V_90 ;
T_3 V_91 , V_92 , V_93 , V_94 , V_95 ;
struct V_29 * V_29 = V_4 -> V_29 ;
V_96:
V_83 ++ ;
if ( V_83 > 16 ) {
F_14 ( & V_29 -> V_34 , L_16 ,
V_83 ) ;
goto V_97;
}
V_80 = F_35 ( V_4 , V_81 ) ;
if ( V_80 != 0x0 )
F_14 ( & V_29 -> V_34 , L_17 ,
V_81 , V_80 ) ;
if ( V_80 == V_65 )
goto V_97;
if ( V_80 == 0 )
return 0 ;
V_88 = V_80 & V_82 ;
for ( V_87 = 0 ; V_87 < V_98 ; V_87 ++ ) {
V_91 = ( V_87 << 24 ) + 0x08 ;
V_85 = F_35 ( V_4 , V_91 ) ;
if ( V_85 == 0x0 )
continue;
F_14 ( & V_29 -> V_34 , L_17 , V_91 , V_85 ) ;
if ( V_85 == V_65 )
goto V_97;
V_93 = ( V_87 << 24 ) + 0x18 ;
V_86 = F_35 ( V_4 , V_93 ) ;
F_14 ( & V_29 -> V_34 , L_17 , V_93 , V_86 ) ;
if ( V_86 == V_65 )
goto V_97;
for ( V_3 = 0 , V_84 = 1ULL ; V_3 < 64 ; V_3 ++ , V_84 <<= 1 ) {
if ( ( V_85 & V_84 ) == 0x0 )
continue;
V_94 = ( V_87 << 24 ) + 0x100 + 0x08 * V_3 ;
V_89 = F_35 ( V_4 , V_94 ) ;
if ( V_89 == V_65 )
goto V_97;
F_14 ( & V_29 -> V_34 ,
L_17 , V_94 , V_89 ) ;
V_95 = ( V_87 << 24 ) + 0x300 + 0x08 * V_3 ;
V_90 = F_35 ( V_4 , V_95 ) ;
if ( V_90 == V_65 )
goto V_97;
F_14 ( & V_29 -> V_34 ,
L_17 , V_95 , V_90 ) ;
V_80 = F_35 ( V_4 , V_81 ) ;
if ( V_80 == V_65 )
goto V_97;
if ( ( V_88 == 0x0 ) &&
( V_80 & V_82 ) ) {
goto V_96;
}
if ( V_88 == 0x0 ) {
V_94 = ( V_87 << 24 ) + 0x100 + 0x08 * V_3 ;
F_20 ( V_4 , V_94 , V_89 ) ;
F_12 ( & V_29 -> V_34 ,
L_18 ,
V_94 , V_89 ) ;
V_92 = ( V_87 << 24 ) + 0x10 ;
F_20 ( V_4 , V_92 , V_84 ) ;
F_12 ( & V_29 -> V_34 ,
L_19 ,
V_92 , V_84 ) ;
}
}
}
V_80 = F_35 ( V_4 , V_81 ) ;
if ( V_80 == V_65 )
goto V_97;
if ( ( V_88 == 0x0 ) && ( V_80 & V_82 ) ) {
F_12 ( & V_29 -> V_34 , L_20 ,
V_83 ) ;
goto V_96;
}
return V_88 ;
V_97:
return V_65 ;
}
static int F_54 ( struct V_29 * V_29 )
{
int V_28 ;
F_55 ( V_29 ) ;
F_56 ( V_29 ) ;
V_28 = F_57 ( V_29 , V_99 ) ;
if ( ! V_28 ) {
F_58 ( 250 ) ;
F_57 ( V_29 , V_100 ) ;
F_58 ( 2000 ) ;
}
F_59 ( V_29 ) ;
F_60 ( V_29 ) ;
return V_28 ;
}
static int F_61 ( struct V_1 * V_4 )
{
struct V_29 * V_29 = V_4 -> V_29 ;
int V_28 ;
F_62 ( & V_29 -> V_34 ,
L_21 , V_35 ) ;
V_4 -> V_31 &= ~ ( V_36 |
V_37 |
V_38 ) ;
F_47 ( V_4 ) ;
V_28 = F_54 ( V_29 ) ;
if ( ! V_28 ) {
V_28 = F_38 ( V_4 ) ;
if ( ! V_28 )
F_62 ( & V_29 -> V_34 ,
L_22 , V_35 ) ;
else
F_14 ( & V_29 -> V_34 ,
L_23 ,
V_35 , V_28 ) ;
} else {
F_14 ( & V_29 -> V_34 ,
L_24 , V_35 ) ;
}
return V_28 ;
}
static int F_63 ( struct V_1 * V_4 )
{
struct V_29 * V_29 = V_4 -> V_29 ;
int V_28 ;
F_62 ( & V_29 -> V_34 ,
L_25 ,
V_35 ) ;
F_47 ( V_4 ) ;
F_20 ( V_4 , V_76 ,
( V_4 -> V_75 & 0xcull ) | 0x70ull ) ;
V_28 = F_54 ( V_29 ) ;
if ( V_28 ) {
F_14 ( & V_29 -> V_34 ,
L_26 ,
V_35 ) ;
}
V_28 = F_38 ( V_4 ) ;
if ( V_28 ) {
F_14 ( & V_29 -> V_34 ,
L_23 ,
V_35 , V_28 ) ;
return V_28 ;
}
F_62 ( & V_29 -> V_34 ,
L_27 , V_35 ) ;
return 0 ;
}
static int F_64 ( void * V_101 )
{
int V_28 , V_102 = 0 ;
struct V_1 * V_4 = V_101 ;
struct V_29 * V_29 = V_4 -> V_29 ;
T_4 V_80 , V_88 , V_40 , V_41 ;
V_103:
while ( ! F_65 () ) {
V_28 = F_66 ( V_4 -> V_104 ,
( F_52 ( V_4 , & V_80 ) ||
( V_102 = F_65 () ) ) ,
V_105 * V_106 ) ;
if ( V_102 )
break;
if ( V_80 == V_65 ) {
F_14 ( & V_29 -> V_34 ,
L_28 , V_35 , V_80 ) ;
goto V_97;
}
V_40 = F_35 ( V_4 , V_64 ) ;
if ( V_40 == V_65 ) {
F_14 ( & V_29 -> V_34 ,
L_29 ,
V_35 , V_40 ) ;
goto V_97;
}
V_41 = F_35 ( V_4 , V_69 ) ;
if ( V_41 == V_65 ) {
F_14 ( & V_29 -> V_34 ,
L_30 ,
V_35 , V_41 ) ;
goto V_97;
}
V_80 = F_35 ( V_4 , V_81 ) ;
if ( V_80 == V_65 ) {
F_14 ( & V_29 -> V_34 ,
L_31 , V_35 ,
( V_80 & V_82 ) ? L_32 : L_33 ,
V_80 ) ;
goto V_97;
}
V_88 = F_53 ( V_4 ) ;
if ( V_88 == V_65 )
goto V_97;
if ( ( V_88 ) && ! V_4 -> V_107 &&
F_21 ( V_4 ) ) {
V_4 -> V_18 = V_74 ;
V_28 = F_51 ( V_4 , 0 ) ;
if ( V_28 < 0 ) {
goto V_97;
}
}
if ( V_4 -> V_18 == V_108 ) {
V_28 = F_63 ( V_4 ) ;
if ( V_28 )
goto V_97;
}
V_4 -> V_109 = V_80 ;
F_67 () ;
}
return 0 ;
V_97:
if ( V_4 -> V_13 ) {
F_68 ( V_4 -> V_30 + V_81 ) ;
if ( F_69 ( V_29 ) )
return - V_33 ;
V_28 = F_61 ( V_4 ) ;
if ( ! V_28 )
goto V_103;
}
F_14 ( & V_29 -> V_34 ,
L_34 , V_35 ) ;
V_4 -> V_18 = V_74 ;
F_47 ( V_4 ) ;
while ( ! F_65 () )
F_67 () ;
return - V_33 ;
}
static int F_70 ( struct V_1 * V_4 )
{
int V_28 ;
if ( V_105 <= 0 )
return 0 ;
V_4 -> V_110 = F_71 ( F_64 , V_4 ,
V_111 L_35 ,
V_4 -> V_10 ) ;
if ( F_72 ( V_4 -> V_110 ) ) {
V_28 = F_73 ( V_4 -> V_110 ) ;
V_4 -> V_110 = NULL ;
return V_28 ;
}
return 0 ;
}
static int F_74 ( struct V_1 * V_4 )
{
return V_4 -> V_110 != NULL ;
}
static int F_75 ( struct V_1 * V_4 )
{
int V_28 ;
if ( ! F_74 ( V_4 ) )
return - V_33 ;
V_28 = F_76 ( V_4 -> V_110 ) ;
V_4 -> V_110 = NULL ;
return 0 ;
}
static int F_77 ( struct V_1 * V_4 )
{
int V_62 ;
struct V_29 * V_29 = V_4 -> V_29 ;
V_62 = F_78 ( V_29 ) ;
if ( V_62 ) {
F_14 ( & V_29 -> V_34 ,
L_36 , V_62 ) ;
goto V_112;
}
V_62 = F_15 ( V_29 , V_39 ) ;
if ( V_62 ) {
F_14 ( & V_29 -> V_34 ,
L_4 , V_35 , V_62 ) ;
V_62 = - V_33 ;
goto V_113;
}
if ( ! F_79 ( V_29 , F_80 ( 64 ) ) ) {
V_62 = F_81 ( V_29 , F_80 ( 64 ) ) ;
if ( V_62 ) {
F_14 ( & V_29 -> V_34 ,
L_37 ) ;
V_62 = - V_33 ;
goto V_114;
}
} else if ( ! F_79 ( V_29 , F_80 ( 32 ) ) ) {
V_62 = F_81 ( V_29 , F_80 ( 32 ) ) ;
if ( V_62 ) {
F_14 ( & V_29 -> V_34 ,
L_38 ) ;
V_62 = - V_33 ;
goto V_114;
}
} else {
F_14 ( & V_29 -> V_34 ,
L_39 ) ;
V_62 = - V_33 ;
goto V_114;
}
F_82 ( V_29 ) ;
F_83 ( V_29 ) ;
V_29 -> V_115 = 1 ;
V_4 -> V_116 = F_84 ( V_29 , 0 ) ;
V_4 -> V_30 = F_16 ( V_29 , 0 , 0 ) ;
if ( V_4 -> V_30 == NULL ) {
F_14 ( & V_29 -> V_34 ,
L_5 , V_35 ) ;
V_62 = - V_9 ;
goto V_114;
}
V_4 -> V_117 = F_29 ( V_29 ) ;
if ( V_4 -> V_117 < 0 )
V_4 -> V_117 = 0 ;
V_62 = F_34 ( V_4 ) ;
if ( V_62 )
goto V_118;
return 0 ;
V_118:
F_10 ( V_29 , V_4 -> V_30 ) ;
V_114:
F_11 ( V_29 ) ;
V_113:
F_85 ( V_29 ) ;
V_112:
return V_62 ;
}
static void F_86 ( struct V_1 * V_4 )
{
struct V_29 * V_29 = V_4 -> V_29 ;
if ( V_4 -> V_30 )
F_10 ( V_29 , V_4 -> V_30 ) ;
F_11 ( V_29 ) ;
F_85 ( V_29 ) ;
}
static int F_87 ( struct V_29 * V_29 ,
const struct V_119 * V_120 )
{
int V_62 ;
struct V_1 * V_4 ;
F_88 () ;
V_4 = F_1 () ;
if ( F_72 ( V_4 ) ) {
F_14 ( & V_29 -> V_34 , L_40 ,
( int ) F_73 ( V_4 ) ) ;
return F_73 ( V_4 ) ;
}
F_89 ( & V_29 -> V_34 , V_4 ) ;
V_4 -> V_29 = V_29 ;
V_62 = F_77 ( V_4 ) ;
if ( V_62 < 0 ) {
F_14 ( & V_29 -> V_34 ,
L_41 , V_62 ) ;
goto V_121;
}
V_62 = F_38 ( V_4 ) ;
if ( V_62 < 0 ) {
F_14 ( & V_29 -> V_34 ,
L_42 , V_62 ) ;
goto V_122;
}
if ( F_39 ( V_4 ) ) {
V_62 = F_70 ( V_4 ) ;
if ( V_62 < 0 ) {
F_14 ( & V_29 -> V_34 ,
L_43 ,
V_62 ) ;
goto V_123;
}
}
return 0 ;
V_123:
F_47 ( V_4 ) ;
V_122:
F_86 ( V_4 ) ;
V_121:
F_7 ( V_4 ) ;
return V_62 ;
}
static void F_90 ( struct V_29 * V_29 )
{
struct V_1 * V_4 = F_91 ( & V_29 -> V_34 ) ;
F_75 ( V_4 ) ;
F_47 ( V_4 ) ;
F_86 ( V_4 ) ;
F_7 ( V_4 ) ;
}
static T_5 F_92 ( struct V_29 * V_29 ,
enum V_124 V_125 )
{
struct V_1 * V_4 ;
F_14 ( & V_29 -> V_34 , L_44 , V_35 , V_125 ) ;
V_4 = F_91 ( & V_29 -> V_34 ) ;
if ( V_4 == NULL )
return V_126 ;
F_75 ( V_4 ) ;
F_47 ( V_4 ) ;
if ( V_125 == V_127 ) {
return V_126 ;
} else {
F_86 ( V_4 ) ;
return V_128 ;
}
}
static T_5 F_93 ( struct V_29 * V_29 )
{
int V_28 ;
struct V_1 * V_4 = F_91 ( & V_29 -> V_34 ) ;
V_28 = F_77 ( V_4 ) ;
if ( ! V_28 ) {
return V_129 ;
} else {
F_14 ( & V_29 -> V_34 ,
L_41 , V_28 ) ;
return V_126 ;
}
}
static T_5 F_94 ( struct V_29 * V_34 )
{
return V_130 ;
}
static void F_95 ( struct V_29 * V_29 )
{
int V_28 ;
struct V_1 * V_4 = F_91 ( & V_29 -> V_34 ) ;
V_28 = F_38 ( V_4 ) ;
if ( ! V_28 ) {
V_28 = F_70 ( V_4 ) ;
if ( V_28 )
F_14 ( & V_29 -> V_34 ,
L_43 ,
V_28 ) ;
} else {
F_14 ( & V_29 -> V_34 ,
L_42 , V_28 ) ;
}
}
static int F_96 ( struct V_29 * V_34 , int V_131 )
{
int V_28 ;
struct V_1 * V_4 = F_91 ( & V_34 -> V_34 ) ;
if ( V_131 > 0 ) {
F_28 ( V_4 ) ;
V_28 = F_97 ( V_34 , V_131 ) ;
if ( V_28 < 0 )
return V_28 ;
return V_131 ;
}
if ( V_131 == 0 ) {
F_50 ( V_34 ) ;
return 0 ;
}
return 0 ;
}
static char * F_98 ( struct V_132 * V_34 , T_6 * V_133 )
{
if ( V_133 )
* V_133 = 0666 ;
return NULL ;
}
static int T_7 F_99 ( void )
{
int V_28 ;
V_11 = F_100 ( V_134 , V_111 ) ;
if ( F_72 ( V_11 ) ) {
F_101 ( L_45 , V_35 ) ;
return - V_9 ;
}
V_11 -> V_135 = F_98 ;
V_12 = F_102 ( V_111 , NULL ) ;
if ( ! V_12 ) {
V_28 = - V_9 ;
goto V_112;
}
V_28 = F_103 ( & V_136 ) ;
if ( V_28 != 0 ) {
F_101 ( L_46 , V_35 , V_28 ) ;
goto V_137;
}
return V_28 ;
V_137:
F_104 ( V_12 ) ;
V_112:
F_105 ( V_11 ) ;
return V_28 ;
}
static void T_8 F_106 ( void )
{
F_107 ( & V_136 ) ;
F_104 ( V_12 ) ;
F_105 ( V_11 ) ;
}
