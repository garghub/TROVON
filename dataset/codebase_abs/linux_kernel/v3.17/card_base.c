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
int V_28 , V_29 = 0 ;
struct V_30 * V_30 = V_4 -> V_30 ;
void T_1 * V_31 ;
if ( V_4 -> V_32 & V_33 )
return - V_34 ;
V_31 = V_4 -> V_31 ;
V_4 -> V_31 = NULL ;
F_10 ( V_30 , V_31 ) ;
V_28 = F_11 ( V_30 , V_35 ) ;
F_12 ( V_30 , V_28 ) ;
F_13 ( & V_30 -> V_36 , L_1 , V_37 ) ;
V_29 = F_14 ( V_30 ) ;
if ( V_29 ) {
F_15 ( & V_30 -> V_36 ,
L_2 , V_37 , V_29 ) ;
return V_29 ;
}
F_13 ( & V_30 -> V_36 , L_3 , V_37 , V_29 ) ;
V_4 -> V_32 &= ~ ( V_38 |
V_39 |
V_40 ) ;
V_29 = F_16 ( V_30 , V_28 , V_41 ) ;
if ( V_29 ) {
F_15 ( & V_30 -> V_36 ,
L_4 , V_37 , V_29 ) ;
return - V_34 ;
}
V_4 -> V_31 = F_17 ( V_30 , 0 , 0 ) ;
if ( V_4 -> V_31 == NULL ) {
F_15 ( & V_30 -> V_36 ,
L_5 , V_37 ) ;
return - V_9 ;
}
return 0 ;
}
bool F_18 ( struct V_1 * V_4 )
{
return ( V_4 -> V_42 & 0xFFFF0ull ) < 0x32170ull ;
}
static void F_19 ( struct V_1 * V_4 )
{
struct V_30 * V_30 = V_4 -> V_30 ;
if ( ( ( V_4 -> V_42 & 0xFFFF0ull ) >= 0x32000ull ) &&
( ( V_4 -> V_42 & 0xFFFF0ull ) <= 0x33250ull ) ) {
F_20 ( & V_30 -> V_36 ,
L_6 ,
V_4 -> V_42 , V_4 -> V_43 ) ;
F_21 ( V_4 , V_44 ,
0xFFFFFFFFFFFFFFFFull ) ;
F_21 ( V_4 , V_45 ,
0x0000000000000000ull ) ;
}
}
int F_22 ( struct V_1 * V_4 )
{
return ( V_4 -> V_42 & 0xFFFF0ull ) >= 0x32170ull ;
}
int F_23 ( struct V_1 * V_4 )
{
return ( V_4 -> V_42 & 0xFFFF0ull ) < 0x32170ull ;
}
static int F_24 ( struct V_1 * V_4 )
{
T_2 V_46 ;
static const int V_47 [] = { 4000 , 5000 , 6000 , 5714 } ;
V_46 = ( T_2 ) ( ( V_4 -> V_42 >> 28 ) & 0x0full ) ;
if ( V_46 >= F_25 ( V_47 ) )
return - 1 ;
return V_47 [ V_46 ] ;
}
static bool F_26 ( struct V_1 * V_4 )
{
T_3 V_47 = F_24 ( V_4 ) ;
T_4 V_48 ;
if ( V_49 == 0 )
return false ;
V_48 = F_27 ( V_49 *
16000000000uL / ( V_47 * 15 ) ) - 10 ;
F_28 ( V_4 , V_50 ,
0xff00 | ( V_48 & 0xff ) , 0 ) ;
return true ;
}
static bool F_29 ( struct V_1 * V_4 )
{
struct V_30 * V_30 = V_4 -> V_30 ;
unsigned int V_51 ;
T_3 V_47 = F_24 ( V_4 ) ;
T_4 V_48 ;
for ( V_51 = 0 ; V_51 < F_30 ( V_30 ) ; V_51 ++ ) {
if ( V_4 -> V_26 [ V_51 ] == 0 )
continue;
V_48 = F_27 ( V_4 -> V_26 [ V_51 ] *
16000000000uL / ( V_47 * 15 ) ) - 10 ;
F_28 ( V_4 , V_50 ,
0xff00 | ( V_48 & 0xff ) , V_51 + 1 ) ;
}
return true ;
}
static int F_31 ( struct V_1 * V_4 )
{
unsigned int type , V_52 = 0 ;
for ( type = 0 ; type < V_53 ; type ++ ) {
switch ( type ) {
case V_54 :
V_52 = F_32 ( V_4 , 0 ) ;
break;
case V_55 :
V_52 = F_32 ( V_4 , 1 ) ;
break;
case V_56 :
V_52 = F_32 ( V_4 , 2 ) ;
break;
case V_57 :
V_52 = V_58 ;
break;
}
V_4 -> V_59 [ type ] . V_60 = V_52 ;
V_4 -> V_59 [ type ] . V_61 = F_33 ( V_52 * sizeof( struct V_62 ) ,
V_8 ) ;
}
return 0 ;
}
static void F_34 ( struct V_1 * V_4 )
{
unsigned int type ;
for ( type = 0 ; type < V_53 ; type ++ ) {
F_8 ( V_4 -> V_59 [ type ] . V_61 ) ;
V_4 -> V_59 [ type ] . V_61 = NULL ;
}
}
static int F_35 ( struct V_1 * V_4 )
{
int V_63 = 0 ;
int V_64 ;
struct V_30 * V_30 = V_4 -> V_30 ;
V_4 -> V_42 = F_36 ( V_4 , V_65 ) ;
if ( V_4 -> V_42 == V_66 ) {
F_15 ( & V_30 -> V_36 ,
L_7 , V_4 -> V_42 ) ;
V_63 = - V_34 ;
goto V_67;
}
V_64 = F_37 ( V_4 ) ;
if ( V_64 < V_68 || V_64 == 0xff ) {
F_15 ( & V_30 -> V_36 ,
L_8 , V_64 ) ;
V_63 = - V_69 ;
goto V_67;
}
V_4 -> V_43 = F_36 ( V_4 , V_70 ) ;
if ( V_4 -> V_43 == V_66 ) {
F_15 ( & V_30 -> V_36 ,
L_9 , V_4 -> V_43 ) ;
V_63 = - V_34 ;
goto V_67;
}
F_38 ( V_4 , V_4 -> V_71 , sizeof( V_4 -> V_71 ) ) ;
if ( V_30 -> V_72 )
V_4 -> V_73 = 0 ;
else
V_4 -> V_73 = ( F_36 ( V_4 , V_74 )
!= V_66 ) ;
V_67:
return V_63 ;
}
static int F_39 ( struct V_1 * V_4 )
{
int V_63 ;
struct V_30 * V_30 = V_4 -> V_30 ;
V_63 = F_35 ( V_4 ) ;
if ( V_63 )
return V_63 ;
if ( F_40 ( V_4 ) ) {
F_31 ( V_4 ) ;
F_41 ( V_4 ) ;
F_42 ( V_4 , V_4 -> V_59 [ V_57 ] . V_61 ,
V_4 -> V_59 [ V_57 ] . V_60 , 0 ) ;
F_43 ( V_4 , V_54 ,
V_4 -> V_59 [ V_54 ] . V_61 ,
V_4 -> V_59 [ V_54 ] . V_60 ) ;
F_43 ( V_4 , V_55 ,
V_4 -> V_59 [ V_55 ] . V_61 ,
V_4 -> V_59 [ V_55 ] . V_60 ) ;
F_43 ( V_4 , V_56 ,
V_4 -> V_59 [ V_56 ] . V_61 ,
V_4 -> V_59 [ V_56 ] . V_60 ) ;
F_44 ( V_4 ) ;
if ( V_4 -> V_18 == V_75 ) {
F_20 ( & V_30 -> V_36 ,
L_10 , V_37 ) ;
V_4 -> V_76 = 0x7Cull ;
F_21 ( V_4 , V_77 ,
V_4 -> V_76 ) ;
V_63 = F_9 ( V_4 ) ;
if ( V_63 != 0 ) {
F_15 ( & V_30 -> V_36 ,
L_11 ,
V_37 ) ;
goto V_78;
}
V_63 = F_35 ( V_4 ) ;
if ( V_63 )
goto V_78;
}
}
V_63 = F_45 ( V_4 ) ;
if ( V_63 != 0 ) {
F_15 ( & V_30 -> V_36 ,
L_12 , V_37 ) ;
V_63 = - V_7 ;
goto V_78;
}
if ( F_40 ( V_4 ) ) {
F_19 ( V_4 ) ;
F_26 ( V_4 ) ;
F_29 ( V_4 ) ;
}
V_63 = F_46 ( V_4 ) ;
if ( V_63 < 0 ) {
F_15 ( & V_30 -> V_36 ,
L_13 , V_63 ) ;
goto V_79;
}
return 0 ;
V_79:
F_47 ( V_4 ) ;
V_78:
if ( F_40 ( V_4 ) )
F_34 ( V_4 ) ;
return - V_34 ;
}
static int F_48 ( struct V_1 * V_4 )
{
F_49 ( V_4 ) ;
F_50 ( V_4 ) ;
F_47 ( V_4 ) ;
if ( F_40 ( V_4 ) ) {
F_51 ( V_4 -> V_30 ) ;
F_34 ( V_4 ) ;
}
return 0 ;
}
static int F_52 ( struct V_1 * V_4 , int V_80 )
{
int V_29 ;
struct V_30 * V_30 = V_4 -> V_30 ;
F_48 ( V_4 ) ;
if ( ! V_80 ) {
V_4 -> V_76 = 0x70ull ;
F_21 ( V_4 , V_77 , V_4 -> V_76 ) ;
}
V_29 = F_9 ( V_4 ) ;
if ( V_29 != 0 ) {
F_15 ( & V_30 -> V_36 ,
L_14 , V_37 ) ;
return V_29 ;
}
V_29 = F_39 ( V_4 ) ;
if ( V_29 < 0 ) {
F_15 ( & V_30 -> V_36 ,
L_15 , V_37 ) ;
return V_29 ;
}
return 0 ;
}
static int F_53 ( struct V_1 * V_4 , T_4 * V_81 )
{
* V_81 = F_36 ( V_4 , V_82 ) ;
return ( * V_81 & V_83 ) &&
F_22 ( V_4 ) ;
}
static T_4 F_54 ( struct V_1 * V_4 )
{
int V_3 , V_84 = 0 ;
T_4 V_85 , V_86 , V_87 , V_88 , V_81 , V_89 , V_90 , V_91 ;
T_3 V_92 , V_93 , V_94 , V_95 , V_96 ;
struct V_30 * V_30 = V_4 -> V_30 ;
V_97:
V_84 ++ ;
if ( V_84 > 16 ) {
F_15 ( & V_30 -> V_36 , L_16 ,
V_84 ) ;
goto V_98;
}
V_81 = F_36 ( V_4 , V_82 ) ;
if ( V_81 != 0x0 )
F_15 ( & V_30 -> V_36 , L_17 ,
V_82 , V_81 ) ;
if ( V_81 == V_66 )
goto V_98;
if ( V_81 == 0 )
return 0 ;
V_89 = V_81 & V_83 ;
for ( V_88 = 0 ; V_88 < V_99 ; V_88 ++ ) {
V_92 = ( V_88 << 24 ) + 0x08 ;
V_86 = F_36 ( V_4 , V_92 ) ;
if ( V_86 == 0x0 )
continue;
F_15 ( & V_30 -> V_36 , L_17 , V_92 , V_86 ) ;
if ( V_86 == V_66 )
goto V_98;
V_94 = ( V_88 << 24 ) + 0x18 ;
V_87 = F_36 ( V_4 , V_94 ) ;
F_15 ( & V_30 -> V_36 , L_17 , V_94 , V_87 ) ;
if ( V_87 == V_66 )
goto V_98;
for ( V_3 = 0 , V_85 = 1ULL ; V_3 < 64 ; V_3 ++ , V_85 <<= 1 ) {
if ( ( V_86 & V_85 ) == 0x0 )
continue;
V_95 = ( V_88 << 24 ) + 0x100 + 0x08 * V_3 ;
V_90 = F_36 ( V_4 , V_95 ) ;
if ( V_90 == V_66 )
goto V_98;
F_15 ( & V_30 -> V_36 ,
L_17 , V_95 , V_90 ) ;
V_96 = ( V_88 << 24 ) + 0x300 + 0x08 * V_3 ;
V_91 = F_36 ( V_4 , V_96 ) ;
if ( V_91 == V_66 )
goto V_98;
F_15 ( & V_30 -> V_36 ,
L_17 , V_96 , V_91 ) ;
V_81 = F_36 ( V_4 , V_82 ) ;
if ( V_81 == V_66 )
goto V_98;
if ( ( V_89 == 0x0 ) &&
( V_81 & V_83 ) ) {
goto V_97;
}
if ( V_89 == 0x0 ) {
V_95 = ( V_88 << 24 ) + 0x100 + 0x08 * V_3 ;
F_21 ( V_4 , V_95 , V_90 ) ;
F_13 ( & V_30 -> V_36 ,
L_18
L_19 , V_95 , V_90 ) ;
V_93 = ( V_88 << 24 ) + 0x10 ;
F_21 ( V_4 , V_93 , V_85 ) ;
F_13 ( & V_30 -> V_36 ,
L_20
L_19 , V_93 ,
V_85 ) ;
}
}
}
V_81 = F_36 ( V_4 , V_82 ) ;
if ( V_81 == V_66 )
goto V_98;
if ( ( V_89 == 0x0 ) && ( V_81 & V_83 ) ) {
F_13 ( & V_30 -> V_36 , L_21 ,
V_84 ) ;
goto V_97;
}
return V_89 ;
V_98:
return V_66 ;
}
static int F_55 ( struct V_30 * V_30 )
{
int V_29 ;
F_56 ( V_30 ) ;
F_57 ( V_30 ) ;
V_29 = F_58 ( V_30 , V_100 ) ;
if ( ! V_29 ) {
F_59 ( 250 ) ;
F_58 ( V_30 , V_101 ) ;
F_59 ( 2000 ) ;
}
F_60 ( V_30 ) ;
F_61 ( V_30 ) ;
return V_29 ;
}
static int F_62 ( struct V_1 * V_4 )
{
struct V_30 * V_30 = V_4 -> V_30 ;
int V_29 ;
F_63 ( & V_30 -> V_36 ,
L_22 , V_37 ) ;
V_4 -> V_32 &= ~ ( V_38 |
V_39 |
V_40 ) ;
F_48 ( V_4 ) ;
V_29 = F_55 ( V_30 ) ;
if ( ! V_29 ) {
V_29 = F_39 ( V_4 ) ;
if ( ! V_29 )
F_63 ( & V_30 -> V_36 ,
L_23 , V_37 ) ;
else
F_15 ( & V_30 -> V_36 ,
L_24 ,
V_37 , V_29 ) ;
} else {
F_15 ( & V_30 -> V_36 ,
L_25 , V_37 ) ;
}
return V_29 ;
}
static int F_64 ( struct V_1 * V_4 )
{
struct V_30 * V_30 = V_4 -> V_30 ;
int V_29 ;
F_63 ( & V_30 -> V_36 ,
L_26 ,
V_37 ) ;
F_48 ( V_4 ) ;
F_21 ( V_4 , V_77 ,
( V_4 -> V_76 & 0xcull ) | 0x70ull ) ;
V_29 = F_55 ( V_30 ) ;
if ( V_29 ) {
F_15 ( & V_30 -> V_36 ,
L_27 ,
V_37 ) ;
}
V_29 = F_39 ( V_4 ) ;
if ( V_29 ) {
F_15 ( & V_30 -> V_36 ,
L_24 ,
V_37 , V_29 ) ;
return V_29 ;
}
F_63 ( & V_30 -> V_36 ,
L_28 , V_37 ) ;
return 0 ;
}
static int F_65 ( void * V_102 )
{
int V_29 , V_103 = 0 ;
struct V_1 * V_4 = V_102 ;
struct V_30 * V_30 = V_4 -> V_30 ;
T_4 V_81 , V_89 , V_42 , V_43 ;
V_104:
while ( ! F_66 () ) {
V_29 = F_67 ( V_4 -> V_105 ,
( F_53 ( V_4 , & V_81 ) ||
( V_103 = F_66 () ) ) ,
V_106 * V_107 ) ;
if ( V_103 )
break;
if ( V_81 == V_66 ) {
F_15 ( & V_30 -> V_36 ,
L_29 , V_37 , V_81 ) ;
goto V_98;
}
V_42 = F_36 ( V_4 , V_65 ) ;
if ( V_42 == V_66 ) {
F_15 ( & V_30 -> V_36 ,
L_30 ,
V_37 , V_42 ) ;
goto V_98;
}
V_43 = F_36 ( V_4 , V_70 ) ;
if ( V_43 == V_66 ) {
F_15 ( & V_30 -> V_36 ,
L_31 ,
V_37 , V_43 ) ;
goto V_98;
}
V_81 = F_36 ( V_4 , V_82 ) ;
if ( V_81 == V_66 ) {
F_15 ( & V_30 -> V_36 ,
L_32 , V_37 ,
( V_81 & V_83 ) ? L_33 : L_34 ,
V_81 ) ;
goto V_98;
}
V_89 = F_54 ( V_4 ) ;
if ( V_89 == V_66 )
goto V_98;
if ( ( V_89 ) && ! V_4 -> V_108 &&
F_22 ( V_4 ) ) {
V_4 -> V_18 = V_75 ;
V_29 = F_52 ( V_4 , 0 ) ;
if ( V_29 < 0 ) {
goto V_98;
}
}
if ( V_4 -> V_18 == V_109 ) {
V_29 = F_64 ( V_4 ) ;
if ( V_29 )
goto V_98;
}
V_4 -> V_110 = V_81 ;
F_68 () ;
}
return 0 ;
V_98:
if ( V_4 -> V_13 ) {
F_69 ( V_4 -> V_31 + V_82 ) ;
if ( F_70 ( V_30 ) )
return - V_34 ;
V_29 = F_62 ( V_4 ) ;
if ( ! V_29 )
goto V_104;
}
F_15 ( & V_30 -> V_36 ,
L_35 , V_37 ) ;
V_4 -> V_18 = V_75 ;
F_48 ( V_4 ) ;
while ( ! F_66 () )
F_68 () ;
return - V_34 ;
}
static int F_71 ( struct V_1 * V_4 )
{
int V_29 ;
if ( V_106 <= 0 )
return 0 ;
V_4 -> V_111 = F_72 ( F_65 , V_4 ,
V_112 L_36 ,
V_4 -> V_10 ) ;
if ( F_73 ( V_4 -> V_111 ) ) {
V_29 = F_74 ( V_4 -> V_111 ) ;
V_4 -> V_111 = NULL ;
return V_29 ;
}
return 0 ;
}
static int F_75 ( struct V_1 * V_4 )
{
return V_4 -> V_111 != NULL ;
}
static int F_76 ( struct V_1 * V_4 )
{
int V_29 ;
if ( ! F_75 ( V_4 ) )
return - V_34 ;
V_29 = F_77 ( V_4 -> V_111 ) ;
V_4 -> V_111 = NULL ;
return 0 ;
}
static int F_78 ( struct V_1 * V_4 )
{
int V_63 , V_28 ;
struct V_30 * V_30 = V_4 -> V_30 ;
V_28 = F_11 ( V_30 , V_35 ) ;
V_63 = F_79 ( V_30 ) ;
if ( V_63 ) {
F_15 ( & V_30 -> V_36 ,
L_37 , V_63 ) ;
goto V_113;
}
V_63 = F_16 ( V_30 , V_28 , V_41 ) ;
if ( V_63 ) {
F_15 ( & V_30 -> V_36 ,
L_4 , V_37 , V_63 ) ;
V_63 = - V_34 ;
goto V_114;
}
if ( ! F_80 ( V_30 , F_81 ( 64 ) ) ) {
V_63 = F_82 ( V_30 , F_81 ( 64 ) ) ;
if ( V_63 ) {
F_15 ( & V_30 -> V_36 ,
L_38 ) ;
V_63 = - V_34 ;
goto V_115;
}
} else if ( ! F_80 ( V_30 , F_81 ( 32 ) ) ) {
V_63 = F_82 ( V_30 , F_81 ( 32 ) ) ;
if ( V_63 ) {
F_15 ( & V_30 -> V_36 ,
L_39 ) ;
V_63 = - V_34 ;
goto V_115;
}
} else {
F_15 ( & V_30 -> V_36 ,
L_40 ) ;
V_63 = - V_34 ;
goto V_115;
}
F_83 ( V_30 ) ;
F_84 ( V_30 ) ;
V_30 -> V_116 = 1 ;
V_4 -> V_117 = F_85 ( V_30 , 0 ) ;
V_4 -> V_31 = F_17 ( V_30 , 0 , 0 ) ;
if ( V_4 -> V_31 == NULL ) {
F_15 ( & V_30 -> V_36 ,
L_5 , V_37 ) ;
V_63 = - V_9 ;
goto V_115;
}
V_4 -> V_118 = F_30 ( V_30 ) ;
V_63 = F_35 ( V_4 ) ;
if ( V_63 )
goto V_119;
return 0 ;
V_119:
F_10 ( V_30 , V_4 -> V_31 ) ;
V_115:
F_12 ( V_30 , V_28 ) ;
V_114:
F_86 ( V_30 ) ;
V_113:
return V_63 ;
}
static void F_87 ( struct V_1 * V_4 )
{
int V_28 ;
struct V_30 * V_30 = V_4 -> V_30 ;
if ( V_4 -> V_31 )
F_10 ( V_30 , V_4 -> V_31 ) ;
V_28 = F_11 ( V_30 , V_35 ) ;
F_12 ( V_30 , V_28 ) ;
F_86 ( V_30 ) ;
}
static int F_88 ( struct V_30 * V_30 ,
const struct V_120 * V_121 )
{
int V_63 ;
struct V_1 * V_4 ;
F_89 () ;
V_4 = F_1 () ;
if ( F_73 ( V_4 ) ) {
F_15 ( & V_30 -> V_36 , L_41 ,
( int ) F_74 ( V_4 ) ) ;
return F_74 ( V_4 ) ;
}
F_90 ( & V_30 -> V_36 , V_4 ) ;
V_4 -> V_30 = V_30 ;
V_63 = F_78 ( V_4 ) ;
if ( V_63 < 0 ) {
F_15 ( & V_30 -> V_36 ,
L_42 , V_63 ) ;
goto V_122;
}
V_63 = F_39 ( V_4 ) ;
if ( V_63 < 0 ) {
F_15 ( & V_30 -> V_36 ,
L_43 , V_63 ) ;
goto V_123;
}
if ( F_40 ( V_4 ) ) {
V_63 = F_71 ( V_4 ) ;
if ( V_63 < 0 ) {
F_15 ( & V_30 -> V_36 ,
L_44
L_45 , V_63 ) ;
goto V_124;
}
}
return 0 ;
V_124:
F_48 ( V_4 ) ;
V_123:
F_87 ( V_4 ) ;
V_122:
F_7 ( V_4 ) ;
return V_63 ;
}
static void F_91 ( struct V_30 * V_30 )
{
struct V_1 * V_4 = F_92 ( & V_30 -> V_36 ) ;
F_76 ( V_4 ) ;
F_48 ( V_4 ) ;
F_87 ( V_4 ) ;
F_7 ( V_4 ) ;
}
static T_5 F_93 ( struct V_30 * V_30 ,
enum V_125 V_126 )
{
struct V_1 * V_4 ;
F_15 ( & V_30 -> V_36 , L_46 , V_37 , V_126 ) ;
V_4 = F_92 ( & V_30 -> V_36 ) ;
if ( V_4 == NULL )
return V_127 ;
F_76 ( V_4 ) ;
F_48 ( V_4 ) ;
if ( V_126 == V_128 ) {
return V_127 ;
} else {
F_87 ( V_4 ) ;
return V_129 ;
}
}
static T_5 F_94 ( struct V_30 * V_30 )
{
int V_29 ;
struct V_1 * V_4 = F_92 ( & V_30 -> V_36 ) ;
V_29 = F_78 ( V_4 ) ;
if ( ! V_29 ) {
return V_130 ;
} else {
F_15 ( & V_30 -> V_36 ,
L_42 , V_29 ) ;
return V_127 ;
}
}
static T_5 F_95 ( struct V_30 * V_36 )
{
return V_131 ;
}
static void F_96 ( struct V_30 * V_30 )
{
int V_29 ;
struct V_1 * V_4 = F_92 ( & V_30 -> V_36 ) ;
V_29 = F_39 ( V_4 ) ;
if ( ! V_29 ) {
V_29 = F_71 ( V_4 ) ;
if ( V_29 )
F_15 ( & V_30 -> V_36 ,
L_47 ,
V_29 ) ;
} else {
F_15 ( & V_30 -> V_36 ,
L_43 , V_29 ) ;
}
}
static int F_97 ( struct V_30 * V_36 , int V_132 )
{
struct V_1 * V_4 = F_92 ( & V_36 -> V_36 ) ;
if ( V_132 > 0 ) {
F_29 ( V_4 ) ;
F_98 ( V_36 , V_132 ) ;
return V_132 ;
}
if ( V_132 == 0 ) {
F_51 ( V_36 ) ;
return 0 ;
}
return 0 ;
}
static int T_6 F_99 ( void )
{
int V_29 ;
V_11 = F_100 ( V_133 , V_112 ) ;
if ( F_73 ( V_11 ) ) {
F_101 ( L_48 , V_37 ) ;
return - V_9 ;
}
V_12 = F_102 ( V_112 , NULL ) ;
if ( ! V_12 ) {
V_29 = - V_9 ;
goto V_113;
}
V_29 = F_103 ( & V_134 ) ;
if ( V_29 != 0 ) {
F_101 ( L_49 , V_37 , V_29 ) ;
goto V_135;
}
return V_29 ;
V_135:
F_104 ( V_12 ) ;
V_113:
F_105 ( V_11 ) ;
return V_29 ;
}
static void T_7 F_106 ( void )
{
F_107 ( & V_134 ) ;
F_104 ( V_12 ) ;
F_105 ( V_11 ) ;
}
