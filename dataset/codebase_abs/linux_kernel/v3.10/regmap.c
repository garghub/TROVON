static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_5 ) ;
F_3 ( V_4 -> V_6 ) ;
F_3 ( V_4 ) ;
}
bool F_4 ( unsigned int V_7 ,
const struct V_8 * V_9 ,
unsigned int V_10 )
{
const struct V_8 * V_11 ;
int V_12 ;
for ( V_12 = 0 , V_11 = V_9 ; V_12 < V_10 ; V_12 ++ , V_11 ++ )
if ( F_5 ( V_7 , V_11 ) )
return true ;
return false ;
}
static bool F_6 ( struct V_13 * V_14 ,
unsigned int V_7 ,
const struct V_15 * V_16 )
{
if ( F_4 ( V_7 , V_16 -> V_17 , V_16 -> V_18 ) )
return false ;
if ( ! V_16 -> V_19 )
return true ;
return F_4 ( V_7 , V_16 -> V_20 ,
V_16 -> V_19 ) ;
}
bool F_7 ( struct V_13 * V_14 , unsigned int V_7 )
{
if ( V_14 -> V_21 && V_7 > V_14 -> V_21 )
return false ;
if ( V_14 -> V_22 )
return V_14 -> V_22 ( V_14 -> V_23 , V_7 ) ;
if ( V_14 -> V_24 )
return F_6 ( V_14 , V_7 , V_14 -> V_24 ) ;
return true ;
}
bool F_8 ( struct V_13 * V_14 , unsigned int V_7 )
{
if ( V_14 -> V_21 && V_7 > V_14 -> V_21 )
return false ;
if ( V_14 -> V_25 . V_26 )
return false ;
if ( V_14 -> V_27 )
return V_14 -> V_27 ( V_14 -> V_23 , V_7 ) ;
if ( V_14 -> V_28 )
return F_6 ( V_14 , V_7 , V_14 -> V_28 ) ;
return true ;
}
bool F_9 ( struct V_13 * V_14 , unsigned int V_7 )
{
if ( ! F_8 ( V_14 , V_7 ) )
return false ;
if ( V_14 -> V_29 )
return V_14 -> V_29 ( V_14 -> V_23 , V_7 ) ;
if ( V_14 -> V_30 )
return F_6 ( V_14 , V_7 , V_14 -> V_30 ) ;
return true ;
}
bool F_10 ( struct V_13 * V_14 , unsigned int V_7 )
{
if ( ! F_8 ( V_14 , V_7 ) )
return false ;
if ( V_14 -> V_31 )
return V_14 -> V_31 ( V_14 -> V_23 , V_7 ) ;
if ( V_14 -> V_32 )
return F_6 ( V_14 , V_7 , V_14 -> V_32 ) ;
return false ;
}
static bool F_11 ( struct V_13 * V_14 , unsigned int V_7 ,
T_1 V_33 )
{
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_33 ; V_12 ++ )
if ( ! F_9 ( V_14 , V_7 + V_12 ) )
return false ;
return true ;
}
static void F_12 ( struct V_13 * V_14 ,
unsigned int V_7 , unsigned int V_34 )
{
T_2 * V_35 = V_14 -> V_6 ;
* V_35 = ( V_7 << 6 ) | V_34 ;
}
static void F_13 ( struct V_13 * V_14 ,
unsigned int V_7 , unsigned int V_34 )
{
T_3 * V_35 = V_14 -> V_6 ;
* V_35 = F_14 ( ( V_7 << 12 ) | V_34 ) ;
}
static void F_15 ( struct V_13 * V_14 ,
unsigned int V_7 , unsigned int V_34 )
{
T_3 * V_35 = V_14 -> V_6 ;
* V_35 = F_14 ( ( V_7 << 9 ) | V_34 ) ;
}
static void F_16 ( struct V_13 * V_14 ,
unsigned int V_7 , unsigned int V_34 )
{
T_2 * V_35 = V_14 -> V_6 ;
V_35 [ 2 ] = V_34 ;
V_35 [ 1 ] = ( V_34 >> 8 ) | ( V_7 << 6 ) ;
V_35 [ 0 ] = V_7 >> 2 ;
}
static void F_17 ( void * V_36 , unsigned int V_34 , unsigned int V_37 )
{
T_2 * V_38 = V_36 ;
V_38 [ 0 ] = V_34 << V_37 ;
}
static void F_18 ( void * V_36 , unsigned int V_34 , unsigned int V_37 )
{
T_3 * V_38 = V_36 ;
V_38 [ 0 ] = F_14 ( V_34 << V_37 ) ;
}
static void F_19 ( void * V_36 , unsigned int V_34 ,
unsigned int V_37 )
{
* ( V_39 * ) V_36 = V_34 << V_37 ;
}
static void F_20 ( void * V_36 , unsigned int V_34 , unsigned int V_37 )
{
T_2 * V_38 = V_36 ;
V_34 <<= V_37 ;
V_38 [ 0 ] = V_34 >> 16 ;
V_38 [ 1 ] = V_34 >> 8 ;
V_38 [ 2 ] = V_34 ;
}
static void F_21 ( void * V_36 , unsigned int V_34 , unsigned int V_37 )
{
T_4 * V_38 = V_36 ;
V_38 [ 0 ] = F_22 ( V_34 << V_37 ) ;
}
static void F_23 ( void * V_36 , unsigned int V_34 ,
unsigned int V_37 )
{
* ( V_40 * ) V_36 = V_34 << V_37 ;
}
static void F_24 ( void * V_36 )
{
}
static unsigned int F_25 ( const void * V_36 )
{
const T_2 * V_38 = V_36 ;
return V_38 [ 0 ] ;
}
static unsigned int F_26 ( const void * V_36 )
{
const T_3 * V_38 = V_36 ;
return F_27 ( V_38 [ 0 ] ) ;
}
static void F_28 ( void * V_36 )
{
T_3 * V_38 = V_36 ;
V_38 [ 0 ] = F_27 ( V_38 [ 0 ] ) ;
}
static unsigned int F_29 ( const void * V_36 )
{
return * ( V_39 * ) V_36 ;
}
static unsigned int F_30 ( const void * V_36 )
{
const T_2 * V_38 = V_36 ;
unsigned int V_41 = V_38 [ 2 ] ;
V_41 |= ( ( unsigned int ) V_38 [ 1 ] ) << 8 ;
V_41 |= ( ( unsigned int ) V_38 [ 0 ] ) << 16 ;
return V_41 ;
}
static unsigned int F_31 ( const void * V_36 )
{
const T_4 * V_38 = V_36 ;
return F_32 ( V_38 [ 0 ] ) ;
}
static void F_33 ( void * V_36 )
{
T_4 * V_38 = V_36 ;
V_38 [ 0 ] = F_32 ( V_38 [ 0 ] ) ;
}
static unsigned int F_34 ( const void * V_36 )
{
return * ( V_40 * ) V_36 ;
}
static void F_35 ( void * V_42 )
{
struct V_13 * V_14 = V_42 ;
F_36 ( & V_14 -> V_43 ) ;
}
static void F_37 ( void * V_42 )
{
struct V_13 * V_14 = V_42 ;
F_38 ( & V_14 -> V_43 ) ;
}
static void F_39 ( void * V_42 )
{
struct V_13 * V_14 = V_42 ;
F_40 ( & V_14 -> V_44 ) ;
}
static void F_41 ( void * V_42 )
{
struct V_13 * V_14 = V_42 ;
F_42 ( & V_14 -> V_44 ) ;
}
static void F_43 ( struct V_45 * V_23 , void * V_46 )
{
}
static bool F_44 ( struct V_13 * V_14 ,
struct V_47 * V_48 )
{
struct V_49 * V_50 = & V_14 -> V_51 ;
struct V_52 * * V_53 = & ( V_50 -> V_52 ) , * V_54 = NULL ;
while ( * V_53 ) {
struct V_47 * V_55 =
F_2 ( * V_53 , struct V_47 , V_56 ) ;
V_54 = * V_53 ;
if ( V_48 -> V_57 < V_55 -> V_58 )
V_53 = & ( ( * V_53 ) -> V_59 ) ;
else if ( V_48 -> V_58 > V_55 -> V_57 )
V_53 = & ( ( * V_53 ) -> V_60 ) ;
else
return false ;
}
F_45 ( & V_48 -> V_56 , V_54 , V_53 ) ;
F_46 ( & V_48 -> V_56 , V_50 ) ;
return true ;
}
static struct V_47 * F_47 ( struct V_13 * V_14 ,
unsigned int V_7 )
{
struct V_52 * V_56 = V_14 -> V_51 . V_52 ;
while ( V_56 ) {
struct V_47 * V_55 =
F_2 ( V_56 , struct V_47 , V_56 ) ;
if ( V_7 < V_55 -> V_58 )
V_56 = V_56 -> V_59 ;
else if ( V_7 > V_55 -> V_57 )
V_56 = V_56 -> V_60 ;
else
return V_55 ;
}
return NULL ;
}
static void F_48 ( struct V_13 * V_14 )
{
struct V_52 * V_61 ;
struct V_47 * V_62 ;
V_61 = F_49 ( & V_14 -> V_51 ) ;
while ( V_61 ) {
V_62 = F_50 ( V_61 , struct V_47 , V_56 ) ;
V_61 = F_51 ( & V_62 -> V_56 ) ;
F_52 ( & V_62 -> V_56 , & V_14 -> V_51 ) ;
F_3 ( V_62 ) ;
}
F_3 ( V_14 -> V_63 ) ;
}
struct V_13 * F_53 ( struct V_45 * V_23 ,
const struct V_64 * V_65 ,
void * V_66 ,
const struct V_67 * V_68 )
{
struct V_13 * V_14 , * * V_69 ;
int V_41 = - V_70 ;
enum V_71 V_72 , V_73 ;
int V_12 , V_74 ;
if ( ! V_68 )
goto V_75;
V_14 = F_54 ( sizeof( * V_14 ) , V_76 ) ;
if ( V_14 == NULL ) {
V_41 = - V_77 ;
goto V_75;
}
if ( V_68 -> V_78 && V_68 -> V_79 ) {
V_14 -> V_78 = V_68 -> V_78 ;
V_14 -> V_79 = V_68 -> V_79 ;
V_14 -> V_80 = V_68 -> V_80 ;
} else {
if ( ( V_65 && V_65 -> V_81 ) ||
V_68 -> V_81 ) {
F_55 ( & V_14 -> V_44 ) ;
V_14 -> V_78 = F_39 ;
V_14 -> V_79 = F_41 ;
} else {
F_56 ( & V_14 -> V_43 ) ;
V_14 -> V_78 = F_35 ;
V_14 -> V_79 = F_37 ;
}
V_14 -> V_80 = V_14 ;
}
V_14 -> V_25 . V_82 = F_57 ( V_68 -> V_83 , 8 ) ;
V_14 -> V_25 . V_84 = V_68 -> V_85 / 8 ;
V_14 -> V_25 . V_86 = F_57 ( V_68 -> V_87 , 8 ) ;
V_14 -> V_25 . V_88 = F_57 ( V_68 -> V_83 +
V_68 -> V_87 + V_68 -> V_85 , 8 ) ;
V_14 -> V_89 = V_68 -> V_85 % 8 ;
if ( V_68 -> V_90 )
V_14 -> V_90 = V_68 -> V_90 ;
else
V_14 -> V_90 = 1 ;
V_14 -> V_91 = V_68 -> V_91 ;
V_14 -> V_23 = V_23 ;
V_14 -> V_65 = V_65 ;
V_14 -> V_66 = V_66 ;
V_14 -> V_21 = V_68 -> V_21 ;
V_14 -> V_24 = V_68 -> V_24 ;
V_14 -> V_28 = V_68 -> V_28 ;
V_14 -> V_30 = V_68 -> V_30 ;
V_14 -> V_32 = V_68 -> V_32 ;
V_14 -> V_22 = V_68 -> V_22 ;
V_14 -> V_27 = V_68 -> V_27 ;
V_14 -> V_29 = V_68 -> V_29 ;
V_14 -> V_31 = V_68 -> V_31 ;
V_14 -> V_92 = V_68 -> V_92 ;
V_14 -> V_93 = V_68 -> V_93 ;
F_55 ( & V_14 -> V_94 ) ;
F_58 ( & V_14 -> V_95 ) ;
F_59 ( & V_14 -> V_96 ) ;
if ( V_68 -> V_97 || V_68 -> V_98 ) {
V_14 -> V_97 = V_68 -> V_97 ;
V_14 -> V_98 = V_68 -> V_98 ;
} else if ( V_65 ) {
V_14 -> V_97 = V_65 -> V_97 ;
}
if ( ! V_65 ) {
V_14 -> V_99 = V_68 -> V_99 ;
V_14 -> V_100 = V_68 -> V_100 ;
V_14 -> V_101 = false ;
goto V_102;
} else {
V_14 -> V_99 = V_103 ;
}
V_72 = V_68 -> V_104 ;
if ( V_72 == V_105 )
V_72 = V_65 -> V_106 ;
if ( V_72 == V_105 )
V_72 = V_107 ;
V_73 = V_68 -> V_108 ;
if ( V_73 == V_105 )
V_73 = V_65 -> V_109 ;
if ( V_73 == V_105 )
V_73 = V_107 ;
switch ( V_68 -> V_83 + V_14 -> V_89 ) {
case 2 :
switch ( V_68 -> V_87 ) {
case 6 :
V_14 -> V_25 . V_26 = F_12 ;
break;
default:
goto V_110;
}
break;
case 4 :
switch ( V_68 -> V_87 ) {
case 12 :
V_14 -> V_25 . V_26 = F_13 ;
break;
default:
goto V_110;
}
break;
case 7 :
switch ( V_68 -> V_87 ) {
case 9 :
V_14 -> V_25 . V_26 = F_15 ;
break;
default:
goto V_110;
}
break;
case 10 :
switch ( V_68 -> V_87 ) {
case 14 :
V_14 -> V_25 . V_26 = F_16 ;
break;
default:
goto V_110;
}
break;
case 8 :
V_14 -> V_25 . V_111 = F_17 ;
break;
case 16 :
switch ( V_72 ) {
case V_107 :
V_14 -> V_25 . V_111 = F_18 ;
break;
case V_112 :
V_14 -> V_25 . V_111 = F_19 ;
break;
default:
goto V_110;
}
break;
case 24 :
if ( V_72 != V_107 )
goto V_110;
V_14 -> V_25 . V_111 = F_20 ;
break;
case 32 :
switch ( V_72 ) {
case V_107 :
V_14 -> V_25 . V_111 = F_21 ;
break;
case V_112 :
V_14 -> V_25 . V_111 = F_23 ;
break;
default:
goto V_110;
}
break;
default:
goto V_110;
}
if ( V_73 == V_112 )
V_14 -> V_25 . V_113 = F_24 ;
switch ( V_68 -> V_87 ) {
case 8 :
V_14 -> V_25 . V_114 = F_17 ;
V_14 -> V_25 . V_115 = F_25 ;
V_14 -> V_25 . V_113 = F_24 ;
break;
case 16 :
switch ( V_73 ) {
case V_107 :
V_14 -> V_25 . V_114 = F_18 ;
V_14 -> V_25 . V_115 = F_26 ;
V_14 -> V_25 . V_113 = F_28 ;
break;
case V_112 :
V_14 -> V_25 . V_114 = F_19 ;
V_14 -> V_25 . V_115 = F_29 ;
break;
default:
goto V_110;
}
break;
case 24 :
if ( V_73 != V_107 )
goto V_110;
V_14 -> V_25 . V_114 = F_20 ;
V_14 -> V_25 . V_115 = F_30 ;
break;
case 32 :
switch ( V_73 ) {
case V_107 :
V_14 -> V_25 . V_114 = F_21 ;
V_14 -> V_25 . V_115 = F_31 ;
V_14 -> V_25 . V_113 = F_33 ;
break;
case V_112 :
V_14 -> V_25 . V_114 = F_23 ;
V_14 -> V_25 . V_115 = F_34 ;
break;
default:
goto V_110;
}
break;
}
if ( V_14 -> V_25 . V_26 ) {
if ( ( V_72 != V_107 ) ||
( V_73 != V_107 ) )
goto V_110;
V_14 -> V_91 = true ;
}
if ( ! V_14 -> V_25 . V_26 &&
! ( V_14 -> V_25 . V_111 && V_14 -> V_25 . V_114 ) )
goto V_110;
V_14 -> V_6 = F_54 ( V_14 -> V_25 . V_88 , V_76 ) ;
if ( V_14 -> V_6 == NULL ) {
V_41 = - V_77 ;
goto V_110;
}
if ( V_14 -> V_25 . V_26 ) {
V_14 -> V_101 = false ;
V_14 -> V_100 = V_116 ;
} else if ( V_14 -> V_25 . V_114 ) {
V_14 -> V_101 = true ;
V_14 -> V_100 = V_117 ;
}
V_102:
V_14 -> V_51 = V_118 ;
for ( V_12 = 0 ; V_12 < V_68 -> V_119 ; V_12 ++ ) {
const struct V_120 * V_121 = & V_68 -> V_9 [ V_12 ] ;
struct V_47 * V_53 ;
if ( V_121 -> V_57 < V_121 -> V_58 ) {
F_60 ( V_14 -> V_23 , L_1 , V_12 ,
V_121 -> V_57 , V_121 -> V_58 ) ;
goto V_122;
}
if ( V_121 -> V_57 > V_14 -> V_21 ) {
F_60 ( V_14 -> V_23 , L_2 , V_12 ,
V_121 -> V_57 , V_14 -> V_21 ) ;
goto V_122;
}
if ( V_121 -> V_123 > V_14 -> V_21 ) {
F_60 ( V_14 -> V_23 ,
L_3 , V_12 ) ;
goto V_122;
}
if ( V_121 -> V_124 == 0 ) {
F_60 ( V_14 -> V_23 , L_4 ,
V_12 ) ;
goto V_122;
}
for ( V_74 = 0 ; V_74 < V_68 -> V_119 ; V_74 ++ ) {
unsigned V_125 = V_68 -> V_9 [ V_74 ] . V_123 ;
unsigned V_126 = V_68 -> V_9 [ V_74 ] . V_127 ;
unsigned V_128 = V_126 +
V_68 -> V_9 [ V_74 ] . V_124 - 1 ;
if ( V_121 -> V_58 <= V_125 &&
V_125 <= V_121 -> V_57 ) {
F_60 ( V_14 -> V_23 ,
L_5 ,
V_12 , V_74 ) ;
goto V_122;
}
if ( ! ( V_128 < V_121 -> V_58 ||
V_126 > V_121 -> V_57 ) ) {
F_60 ( V_14 -> V_23 ,
L_6 ,
V_12 , V_74 ) ;
goto V_122;
}
}
V_53 = F_54 ( sizeof( * V_53 ) , V_76 ) ;
if ( V_53 == NULL ) {
V_41 = - V_77 ;
goto V_122;
}
V_53 -> V_14 = V_14 ;
V_53 -> V_93 = V_121 -> V_93 ;
V_53 -> V_58 = V_121 -> V_58 ;
V_53 -> V_57 = V_121 -> V_57 ;
V_53 -> V_123 = V_121 -> V_123 ;
V_53 -> V_129 = V_121 -> V_129 ;
V_53 -> V_130 = V_121 -> V_130 ;
V_53 -> V_127 = V_121 -> V_127 ;
V_53 -> V_124 = V_121 -> V_124 ;
if ( F_44 ( V_14 , V_53 ) == false ) {
F_60 ( V_14 -> V_23 , L_7 , V_12 ) ;
F_3 ( V_53 ) ;
goto V_122;
}
if ( V_14 -> V_63 == NULL ) {
V_14 -> V_63 =
F_54 ( V_14 -> V_25 . V_88 , V_76 ) ;
if ( V_14 -> V_63 == NULL ) {
V_41 = - V_77 ;
goto V_122;
}
}
}
F_61 ( V_14 , V_68 -> V_93 ) ;
V_41 = F_62 ( V_14 , V_68 ) ;
if ( V_41 != 0 )
goto V_122;
V_69 = F_63 ( F_43 , sizeof( * V_69 ) , V_76 ) ;
if ( ! V_69 ) {
V_41 = - V_77 ;
goto V_131;
}
* V_69 = V_14 ;
F_64 ( V_23 , V_69 ) ;
return V_14 ;
V_131:
F_65 ( V_14 ) ;
F_66 ( V_14 ) ;
V_122:
F_48 ( V_14 ) ;
F_3 ( V_14 -> V_6 ) ;
V_110:
F_3 ( V_14 ) ;
V_75:
return F_67 ( V_41 ) ;
}
static void F_68 ( struct V_45 * V_23 , void * V_46 )
{
F_69 ( * (struct V_13 * * ) V_46 ) ;
}
struct V_13 * F_70 ( struct V_45 * V_23 ,
const struct V_64 * V_65 ,
void * V_66 ,
const struct V_67 * V_68 )
{
struct V_13 * * V_132 , * V_13 ;
V_132 = F_63 ( F_68 , sizeof( * V_132 ) , V_76 ) ;
if ( ! V_132 )
return F_67 ( - V_77 ) ;
V_13 = F_53 ( V_23 , V_65 , V_66 , V_68 ) ;
if ( ! F_71 ( V_13 ) ) {
* V_132 = V_13 ;
F_64 ( V_23 , V_132 ) ;
} else {
F_72 ( V_132 ) ;
}
return V_13 ;
}
int F_73 ( struct V_13 * V_14 , const struct V_67 * V_68 )
{
F_66 ( V_14 ) ;
F_65 ( V_14 ) ;
V_14 -> V_21 = V_68 -> V_21 ;
V_14 -> V_22 = V_68 -> V_22 ;
V_14 -> V_27 = V_68 -> V_27 ;
V_14 -> V_29 = V_68 -> V_29 ;
V_14 -> V_31 = V_68 -> V_31 ;
V_14 -> V_92 = V_68 -> V_92 ;
F_61 ( V_14 , V_68 -> V_93 ) ;
V_14 -> V_133 = false ;
V_14 -> V_134 = false ;
return F_62 ( V_14 , V_68 ) ;
}
void F_69 ( struct V_13 * V_14 )
{
F_66 ( V_14 ) ;
F_65 ( V_14 ) ;
F_48 ( V_14 ) ;
if ( V_14 -> V_65 && V_14 -> V_65 -> V_135 )
V_14 -> V_65 -> V_135 ( V_14 -> V_66 ) ;
F_3 ( V_14 -> V_6 ) ;
F_3 ( V_14 ) ;
}
static int F_74 ( struct V_45 * V_23 , void * V_46 , void * V_48 )
{
struct V_13 * * V_11 = V_46 ;
if ( ! V_11 || ! * V_11 ) {
F_75 ( ! V_11 || ! * V_11 ) ;
return 0 ;
}
if ( V_48 )
return ( * V_11 ) -> V_93 == V_48 ;
else
return 1 ;
}
struct V_13 * F_76 ( struct V_45 * V_23 , const char * V_93 )
{
struct V_13 * * V_11 = F_77 ( V_23 , F_43 ,
F_74 , ( void * ) V_93 ) ;
if ( ! V_11 )
return NULL ;
return * V_11 ;
}
static int F_78 ( struct V_13 * V_14 , unsigned int * V_7 ,
struct V_47 * V_136 ,
unsigned int V_137 )
{
void * V_138 ;
unsigned int V_139 ;
unsigned int V_140 ;
bool V_141 ;
int V_41 ;
V_139 = ( * V_7 - V_136 -> V_58 ) % V_136 -> V_124 ;
V_140 = ( * V_7 - V_136 -> V_58 ) / V_136 -> V_124 ;
if ( V_137 > 1 ) {
if ( * V_7 + V_137 - 1 > V_136 -> V_57 )
return - V_70 ;
if ( V_137 > V_136 -> V_124 - V_139 )
return - V_70 ;
}
if ( V_137 > 1 ||
V_136 -> V_127 + V_139 != V_136 -> V_123 ) {
V_138 = V_14 -> V_6 ;
V_14 -> V_6 = V_14 -> V_63 ;
V_41 = F_79 ( V_14 , V_136 -> V_123 ,
V_136 -> V_129 ,
V_140 << V_136 -> V_130 ,
& V_141 ) ;
V_14 -> V_6 = V_138 ;
if ( V_41 != 0 )
return V_41 ;
}
* V_7 = V_136 -> V_127 + V_139 ;
return 0 ;
}
int F_80 ( struct V_13 * V_14 , unsigned int V_7 ,
const void * V_34 , T_1 V_142 , bool V_4 )
{
struct V_47 * V_136 ;
unsigned long V_143 ;
T_2 * T_2 = V_14 -> V_6 ;
void * V_144 = V_14 -> V_6 + V_14 -> V_25 . V_82 +
V_14 -> V_25 . V_84 ;
void * V_36 ;
int V_41 = - V_145 ;
T_1 V_146 ;
int V_12 ;
F_75 ( ! V_14 -> V_65 ) ;
if ( V_14 -> V_22 )
for ( V_12 = 0 ; V_12 < V_142 / V_14 -> V_25 . V_86 ; V_12 ++ )
if ( ! V_14 -> V_22 ( V_14 -> V_23 ,
V_7 + ( V_12 * V_14 -> V_90 ) ) )
return - V_70 ;
if ( ! V_14 -> V_133 && V_14 -> V_25 . V_115 ) {
unsigned int V_147 ;
int V_86 = V_14 -> V_25 . V_86 ;
for ( V_12 = 0 ; V_12 < V_142 / V_86 ; V_12 ++ ) {
V_147 = V_14 -> V_25 . V_115 ( V_34 + ( V_12 * V_86 ) ) ;
V_41 = F_81 ( V_14 , V_7 + ( V_12 * V_14 -> V_90 ) ,
V_147 ) ;
if ( V_41 ) {
F_60 ( V_14 -> V_23 ,
L_8 ,
V_7 + V_12 , V_41 ) ;
return V_41 ;
}
}
if ( V_14 -> V_134 ) {
V_14 -> V_148 = true ;
return 0 ;
}
}
V_136 = F_47 ( V_14 , V_7 ) ;
if ( V_136 ) {
int V_137 = V_142 / V_14 -> V_25 . V_86 ;
int V_139 = ( V_7 - V_136 -> V_58 ) % V_136 -> V_124 ;
int V_149 = V_136 -> V_124 - V_139 ;
while ( V_137 > V_149 ) {
F_82 ( V_14 -> V_23 , L_9 ,
V_149 , V_142 / V_14 -> V_25 . V_86 ) ;
V_41 = F_80 ( V_14 , V_7 , V_34 , V_149 *
V_14 -> V_25 . V_86 , V_4 ) ;
if ( V_41 != 0 )
return V_41 ;
V_7 += V_149 ;
V_137 -= V_149 ;
V_34 += V_149 * V_14 -> V_25 . V_86 ;
V_142 -= V_149 * V_14 -> V_25 . V_86 ;
V_139 = ( V_7 - V_136 -> V_58 ) %
V_136 -> V_124 ;
V_149 = V_136 -> V_124 - V_139 ;
}
V_41 = F_78 ( V_14 , & V_7 , V_136 , V_137 ) ;
if ( V_41 != 0 )
return V_41 ;
}
V_14 -> V_25 . V_111 ( V_14 -> V_6 , V_7 , V_14 -> V_89 ) ;
T_2 [ 0 ] |= V_14 -> V_98 ;
if ( V_4 && V_14 -> V_65 -> V_150 ) {
struct V_3 * V_4 = V_14 -> V_65 -> V_151 () ;
if ( ! V_4 )
return - V_77 ;
F_83 ( V_14 -> V_23 , V_7 , V_142 ) ;
V_4 -> V_6 = F_54 ( V_14 -> V_25 . V_88 ,
V_76 | V_152 ) ;
if ( ! V_4 -> V_6 ) {
F_3 ( V_4 ) ;
return - V_77 ;
}
F_84 ( & V_4 -> V_5 , F_1 ) ;
V_4 -> V_14 = V_14 ;
memcpy ( V_4 -> V_6 , V_14 -> V_6 , V_14 -> V_25 . V_84 +
V_14 -> V_25 . V_82 + V_14 -> V_25 . V_86 ) ;
if ( V_34 == V_144 )
V_34 = V_4 -> V_6 + V_14 -> V_25 . V_84 +
V_14 -> V_25 . V_82 ;
F_85 ( & V_14 -> V_94 , V_143 ) ;
F_86 ( & V_4 -> V_153 , & V_14 -> V_95 ) ;
F_87 ( & V_14 -> V_94 , V_143 ) ;
V_41 = V_14 -> V_65 -> V_150 ( V_14 -> V_66 , V_4 -> V_6 ,
V_14 -> V_25 . V_82 +
V_14 -> V_25 . V_84 ,
V_34 , V_142 , V_4 ) ;
if ( V_41 != 0 ) {
F_60 ( V_14 -> V_23 , L_10 ,
V_41 ) ;
F_85 ( & V_14 -> V_94 , V_143 ) ;
F_88 ( & V_4 -> V_153 ) ;
F_87 ( & V_14 -> V_94 , V_143 ) ;
F_3 ( V_4 -> V_6 ) ;
F_3 ( V_4 ) ;
}
return V_41 ;
}
F_89 ( V_14 -> V_23 , V_7 ,
V_142 / V_14 -> V_25 . V_86 ) ;
if ( V_34 == V_144 )
V_41 = V_14 -> V_65 -> V_154 ( V_14 -> V_66 , V_14 -> V_6 ,
V_14 -> V_25 . V_82 +
V_14 -> V_25 . V_84 +
V_142 ) ;
else if ( V_14 -> V_65 -> V_155 )
V_41 = V_14 -> V_65 -> V_155 ( V_14 -> V_66 , V_14 -> V_6 ,
V_14 -> V_25 . V_82 +
V_14 -> V_25 . V_84 ,
V_34 , V_142 ) ;
if ( V_41 == - V_145 ) {
V_146 = V_14 -> V_25 . V_82 + V_14 -> V_25 . V_84 + V_142 ;
V_36 = F_54 ( V_146 , V_76 ) ;
if ( ! V_36 )
return - V_77 ;
memcpy ( V_36 , V_14 -> V_6 , V_14 -> V_25 . V_82 ) ;
memcpy ( V_36 + V_14 -> V_25 . V_82 + V_14 -> V_25 . V_84 ,
V_34 , V_142 ) ;
V_41 = V_14 -> V_65 -> V_154 ( V_14 -> V_66 , V_36 , V_146 ) ;
F_3 ( V_36 ) ;
}
F_90 ( V_14 -> V_23 , V_7 ,
V_142 / V_14 -> V_25 . V_86 ) ;
return V_41 ;
}
bool F_91 ( struct V_13 * V_14 )
{
return V_14 -> V_65 && V_14 -> V_25 . V_114 && V_14 -> V_25 . V_111 ;
}
static int V_116 ( void * V_156 , unsigned int V_7 ,
unsigned int V_34 )
{
int V_41 ;
struct V_47 * V_136 ;
struct V_13 * V_14 = V_156 ;
F_75 ( ! V_14 -> V_65 || ! V_14 -> V_25 . V_26 ) ;
V_136 = F_47 ( V_14 , V_7 ) ;
if ( V_136 ) {
V_41 = F_78 ( V_14 , & V_7 , V_136 , 1 ) ;
if ( V_41 != 0 )
return V_41 ;
}
V_14 -> V_25 . V_26 ( V_14 , V_7 , V_34 ) ;
F_89 ( V_14 -> V_23 , V_7 , 1 ) ;
V_41 = V_14 -> V_65 -> V_154 ( V_14 -> V_66 , V_14 -> V_6 ,
V_14 -> V_25 . V_88 ) ;
F_90 ( V_14 -> V_23 , V_7 , 1 ) ;
return V_41 ;
}
static int V_117 ( void * V_156 , unsigned int V_7 ,
unsigned int V_34 )
{
struct V_13 * V_14 = V_156 ;
F_75 ( ! V_14 -> V_65 || ! V_14 -> V_25 . V_114 ) ;
V_14 -> V_25 . V_114 ( V_14 -> V_6 + V_14 -> V_25 . V_82
+ V_14 -> V_25 . V_84 , V_34 , 0 ) ;
return F_80 ( V_14 , V_7 ,
V_14 -> V_6 +
V_14 -> V_25 . V_82 +
V_14 -> V_25 . V_84 ,
V_14 -> V_25 . V_86 , false ) ;
}
static inline void * F_92 ( struct V_13 * V_14 )
{
return ( V_14 -> V_65 ) ? V_14 : V_14 -> V_66 ;
}
int F_93 ( struct V_13 * V_14 , unsigned int V_7 ,
unsigned int V_34 )
{
int V_41 ;
void * V_156 = F_92 ( V_14 ) ;
if ( ! V_14 -> V_133 && ! V_14 -> V_101 ) {
V_41 = F_81 ( V_14 , V_7 , V_34 ) ;
if ( V_41 != 0 )
return V_41 ;
if ( V_14 -> V_134 ) {
V_14 -> V_148 = true ;
return 0 ;
}
}
#ifdef F_94
if ( strcmp ( F_95 ( V_14 -> V_23 ) , F_94 ) == 0 )
F_96 ( V_14 -> V_23 , L_11 , V_7 , V_34 ) ;
#endif
F_97 ( V_14 -> V_23 , V_7 , V_34 ) ;
return V_14 -> V_100 ( V_156 , V_7 , V_34 ) ;
}
int F_98 ( struct V_13 * V_14 , unsigned int V_7 , unsigned int V_34 )
{
int V_41 ;
if ( V_7 % V_14 -> V_90 )
return - V_70 ;
V_14 -> V_78 ( V_14 -> V_80 ) ;
V_41 = F_93 ( V_14 , V_7 , V_34 ) ;
V_14 -> V_79 ( V_14 -> V_80 ) ;
return V_41 ;
}
int F_99 ( struct V_13 * V_14 , unsigned int V_7 ,
const void * V_34 , T_1 V_142 )
{
int V_41 ;
if ( ! F_91 ( V_14 ) )
return - V_70 ;
if ( V_142 % V_14 -> V_25 . V_86 )
return - V_70 ;
V_14 -> V_78 ( V_14 -> V_80 ) ;
V_41 = F_80 ( V_14 , V_7 , V_34 , V_142 , false ) ;
V_14 -> V_79 ( V_14 -> V_80 ) ;
return V_41 ;
}
int F_100 ( struct V_13 * V_14 , unsigned int V_7 , const void * V_34 ,
T_1 V_157 )
{
int V_41 = 0 , V_12 ;
T_1 V_86 = V_14 -> V_25 . V_86 ;
void * V_158 ;
if ( ! V_14 -> V_65 )
return - V_70 ;
if ( ! V_14 -> V_25 . V_113 )
return - V_70 ;
if ( V_7 % V_14 -> V_90 )
return - V_70 ;
V_14 -> V_78 ( V_14 -> V_80 ) ;
if ( V_86 == 1 ) {
V_158 = ( void * ) V_34 ;
} else {
V_158 = F_101 ( V_34 , V_157 * V_86 , V_76 ) ;
if ( ! V_158 ) {
V_41 = - V_77 ;
F_60 ( V_14 -> V_23 , L_12 ) ;
goto V_35;
}
for ( V_12 = 0 ; V_12 < V_157 * V_86 ; V_12 += V_86 )
V_14 -> V_25 . V_113 ( V_158 + V_12 ) ;
}
if ( V_14 -> V_91 ) {
for ( V_12 = 0 ; V_12 < V_157 ; V_12 ++ ) {
V_41 = F_99 ( V_14 ,
V_7 + ( V_12 * V_14 -> V_90 ) ,
V_34 + ( V_12 * V_86 ) ,
V_86 ) ;
if ( V_41 != 0 )
return V_41 ;
}
} else {
V_41 = F_80 ( V_14 , V_7 , V_158 , V_86 * V_157 ,
false ) ;
}
if ( V_86 != 1 )
F_3 ( V_158 ) ;
V_35:
V_14 -> V_79 ( V_14 -> V_80 ) ;
return V_41 ;
}
int F_102 ( struct V_13 * V_14 , unsigned int V_7 ,
const void * V_34 , T_1 V_142 )
{
int V_41 ;
if ( V_142 % V_14 -> V_25 . V_86 )
return - V_70 ;
if ( V_7 % V_14 -> V_90 )
return - V_70 ;
V_14 -> V_78 ( V_14 -> V_80 ) ;
V_41 = F_80 ( V_14 , V_7 , V_34 , V_142 , true ) ;
V_14 -> V_79 ( V_14 -> V_80 ) ;
return V_41 ;
}
static int F_103 ( struct V_13 * V_14 , unsigned int V_7 , void * V_34 ,
unsigned int V_142 )
{
struct V_47 * V_136 ;
T_2 * T_2 = V_14 -> V_6 ;
int V_41 ;
F_75 ( ! V_14 -> V_65 ) ;
V_136 = F_47 ( V_14 , V_7 ) ;
if ( V_136 ) {
V_41 = F_78 ( V_14 , & V_7 , V_136 ,
V_142 / V_14 -> V_25 . V_86 ) ;
if ( V_41 != 0 )
return V_41 ;
}
V_14 -> V_25 . V_111 ( V_14 -> V_6 , V_7 , V_14 -> V_89 ) ;
T_2 [ 0 ] |= V_14 -> V_97 ;
F_104 ( V_14 -> V_23 , V_7 ,
V_142 / V_14 -> V_25 . V_86 ) ;
V_41 = V_14 -> V_65 -> V_159 ( V_14 -> V_66 , V_14 -> V_6 ,
V_14 -> V_25 . V_82 + V_14 -> V_25 . V_84 ,
V_34 , V_142 ) ;
F_105 ( V_14 -> V_23 , V_7 ,
V_142 / V_14 -> V_25 . V_86 ) ;
return V_41 ;
}
static int V_103 ( void * V_156 , unsigned int V_7 ,
unsigned int * V_34 )
{
int V_41 ;
struct V_13 * V_14 = V_156 ;
if ( ! V_14 -> V_25 . V_115 )
return - V_70 ;
V_41 = F_103 ( V_14 , V_7 , V_14 -> V_6 , V_14 -> V_25 . V_86 ) ;
if ( V_41 == 0 )
* V_34 = V_14 -> V_25 . V_115 ( V_14 -> V_6 ) ;
return V_41 ;
}
static int F_106 ( struct V_13 * V_14 , unsigned int V_7 ,
unsigned int * V_34 )
{
int V_41 ;
void * V_156 = F_92 ( V_14 ) ;
F_75 ( ! V_14 -> V_99 ) ;
if ( ! V_14 -> V_133 ) {
V_41 = F_107 ( V_14 , V_7 , V_34 ) ;
if ( V_41 == 0 )
return 0 ;
}
if ( V_14 -> V_134 )
return - V_160 ;
V_41 = V_14 -> V_99 ( V_156 , V_7 , V_34 ) ;
if ( V_41 == 0 ) {
#ifdef F_94
if ( strcmp ( F_95 ( V_14 -> V_23 ) , F_94 ) == 0 )
F_96 ( V_14 -> V_23 , L_13 , V_7 , * V_34 ) ;
#endif
F_108 ( V_14 -> V_23 , V_7 , * V_34 ) ;
if ( ! V_14 -> V_133 )
F_81 ( V_14 , V_7 , * V_34 ) ;
}
return V_41 ;
}
int F_109 ( struct V_13 * V_14 , unsigned int V_7 , unsigned int * V_34 )
{
int V_41 ;
if ( V_7 % V_14 -> V_90 )
return - V_70 ;
V_14 -> V_78 ( V_14 -> V_80 ) ;
V_41 = F_106 ( V_14 , V_7 , V_34 ) ;
V_14 -> V_79 ( V_14 -> V_80 ) ;
return V_41 ;
}
int F_110 ( struct V_13 * V_14 , unsigned int V_7 , void * V_34 ,
T_1 V_142 )
{
T_1 V_86 = V_14 -> V_25 . V_86 ;
T_1 V_157 = V_142 / V_86 ;
unsigned int V_161 ;
int V_41 , V_12 ;
if ( ! V_14 -> V_65 )
return - V_70 ;
if ( V_142 % V_14 -> V_25 . V_86 )
return - V_70 ;
if ( V_7 % V_14 -> V_90 )
return - V_70 ;
V_14 -> V_78 ( V_14 -> V_80 ) ;
if ( F_11 ( V_14 , V_7 , V_157 ) || V_14 -> V_133 ||
V_14 -> V_92 == V_162 ) {
V_41 = F_103 ( V_14 , V_7 , V_34 , V_142 ) ;
} else {
for ( V_12 = 0 ; V_12 < V_157 ; V_12 ++ ) {
V_41 = F_106 ( V_14 , V_7 + ( V_12 * V_14 -> V_90 ) ,
& V_161 ) ;
if ( V_41 != 0 )
goto V_35;
V_14 -> V_25 . V_114 ( V_34 + ( V_12 * V_86 ) , V_161 , 0 ) ;
}
}
V_35:
V_14 -> V_79 ( V_14 -> V_80 ) ;
return V_41 ;
}
int F_111 ( struct V_13 * V_14 , unsigned int V_7 , void * V_34 ,
T_1 V_157 )
{
int V_41 , V_12 ;
T_1 V_86 = V_14 -> V_25 . V_86 ;
bool V_163 = F_11 ( V_14 , V_7 , V_157 ) ;
if ( ! V_14 -> V_65 )
return - V_70 ;
if ( ! V_14 -> V_25 . V_113 )
return - V_70 ;
if ( V_7 % V_14 -> V_90 )
return - V_70 ;
if ( V_163 || V_14 -> V_92 == V_162 ) {
if ( V_14 -> V_91 ) {
for ( V_12 = 0 ; V_12 < V_157 ; V_12 ++ ) {
V_41 = F_110 ( V_14 ,
V_7 + ( V_12 * V_14 -> V_90 ) ,
V_34 + ( V_12 * V_86 ) ,
V_86 ) ;
if ( V_41 != 0 )
return V_41 ;
}
} else {
V_41 = F_110 ( V_14 , V_7 , V_34 ,
V_86 * V_157 ) ;
if ( V_41 != 0 )
return V_41 ;
}
for ( V_12 = 0 ; V_12 < V_157 * V_86 ; V_12 += V_86 )
V_14 -> V_25 . V_113 ( V_34 + V_12 ) ;
} else {
for ( V_12 = 0 ; V_12 < V_157 ; V_12 ++ ) {
unsigned int V_147 ;
V_41 = F_109 ( V_14 , V_7 + ( V_12 * V_14 -> V_90 ) ,
& V_147 ) ;
if ( V_41 != 0 )
return V_41 ;
memcpy ( V_34 + ( V_12 * V_86 ) , & V_147 , V_86 ) ;
}
}
return 0 ;
}
static int F_79 ( struct V_13 * V_14 , unsigned int V_7 ,
unsigned int V_164 , unsigned int V_34 ,
bool * V_165 )
{
int V_41 ;
unsigned int V_166 , V_167 ;
V_41 = F_106 ( V_14 , V_7 , & V_167 ) ;
if ( V_41 != 0 )
return V_41 ;
V_166 = V_167 & ~ V_164 ;
V_166 |= V_34 & V_164 ;
if ( V_166 != V_167 ) {
V_41 = F_93 ( V_14 , V_7 , V_166 ) ;
* V_165 = true ;
} else {
* V_165 = false ;
}
return V_41 ;
}
int F_112 ( struct V_13 * V_14 , unsigned int V_7 ,
unsigned int V_164 , unsigned int V_34 )
{
bool V_165 ;
int V_41 ;
V_14 -> V_78 ( V_14 -> V_80 ) ;
V_41 = F_79 ( V_14 , V_7 , V_164 , V_34 , & V_165 ) ;
V_14 -> V_79 ( V_14 -> V_80 ) ;
return V_41 ;
}
int F_113 ( struct V_13 * V_14 , unsigned int V_7 ,
unsigned int V_164 , unsigned int V_34 ,
bool * V_165 )
{
int V_41 ;
V_14 -> V_78 ( V_14 -> V_80 ) ;
V_41 = F_79 ( V_14 , V_7 , V_164 , V_34 , V_165 ) ;
V_14 -> V_79 ( V_14 -> V_80 ) ;
return V_41 ;
}
void F_114 ( struct V_3 * V_4 , int V_41 )
{
struct V_13 * V_14 = V_4 -> V_14 ;
bool V_168 ;
F_115 ( V_14 -> V_23 ) ;
F_40 ( & V_14 -> V_94 ) ;
F_88 ( & V_4 -> V_153 ) ;
V_168 = F_116 ( & V_14 -> V_95 ) ;
if ( V_41 != 0 )
V_14 -> V_169 = V_41 ;
F_42 ( & V_14 -> V_94 ) ;
F_117 ( & V_4 -> V_5 ) ;
if ( V_168 )
F_118 ( & V_14 -> V_96 ) ;
}
static int F_119 ( struct V_13 * V_14 )
{
unsigned long V_143 ;
int V_41 ;
F_85 ( & V_14 -> V_94 , V_143 ) ;
V_41 = F_116 ( & V_14 -> V_95 ) ;
F_87 ( & V_14 -> V_94 , V_143 ) ;
return V_41 ;
}
int F_120 ( struct V_13 * V_14 )
{
unsigned long V_143 ;
int V_41 ;
if ( ! V_14 -> V_65 -> V_150 )
return 0 ;
F_121 ( V_14 -> V_23 ) ;
F_122 ( V_14 -> V_96 , F_119 ( V_14 ) ) ;
F_85 ( & V_14 -> V_94 , V_143 ) ;
V_41 = V_14 -> V_169 ;
V_14 -> V_169 = 0 ;
F_87 ( & V_14 -> V_94 , V_143 ) ;
F_123 ( V_14 -> V_23 ) ;
return V_41 ;
}
int F_124 ( struct V_13 * V_14 , const struct V_170 * V_171 ,
int V_172 )
{
int V_12 , V_41 ;
bool V_173 ;
if ( V_14 -> V_174 )
return - V_160 ;
V_14 -> V_78 ( V_14 -> V_80 ) ;
V_173 = V_14 -> V_133 ;
V_14 -> V_133 = true ;
for ( V_12 = 0 ; V_12 < V_172 ; V_12 ++ ) {
V_41 = F_93 ( V_14 , V_171 [ V_12 ] . V_7 , V_171 [ V_12 ] . V_175 ) ;
if ( V_41 != 0 ) {
F_60 ( V_14 -> V_23 , L_14 ,
V_171 [ V_12 ] . V_7 , V_171 [ V_12 ] . V_175 , V_41 ) ;
goto V_35;
}
}
V_14 -> V_174 = F_125 ( V_172 , sizeof( struct V_170 ) , V_76 ) ;
if ( V_14 -> V_174 != NULL ) {
memcpy ( V_14 -> V_174 , V_171 ,
V_172 * sizeof( struct V_170 ) ) ;
V_14 -> V_176 = V_172 ;
} else {
V_41 = - V_77 ;
}
V_35:
V_14 -> V_133 = V_173 ;
V_14 -> V_79 ( V_14 -> V_80 ) ;
return V_41 ;
}
int F_126 ( struct V_13 * V_14 )
{
if ( V_14 -> V_25 . V_26 )
return - V_70 ;
return V_14 -> V_25 . V_86 ;
}
static int T_5 F_127 ( void )
{
F_128 () ;
return 0 ;
}
