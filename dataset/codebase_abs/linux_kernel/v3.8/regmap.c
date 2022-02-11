bool F_1 ( unsigned int V_1 ,
const struct V_2 * V_3 ,
unsigned int V_4 )
{
const struct V_2 * V_5 ;
int V_6 ;
for ( V_6 = 0 , V_5 = V_3 ; V_6 < V_4 ; V_6 ++ , V_5 ++ )
if ( F_2 ( V_1 , V_5 ) )
return true ;
return false ;
}
static bool F_3 ( struct V_7 * V_8 ,
unsigned int V_1 ,
const struct V_9 * V_10 )
{
if ( F_1 ( V_1 , V_10 -> V_11 , V_10 -> V_12 ) )
return false ;
if ( ! V_10 -> V_13 )
return true ;
return F_1 ( V_1 , V_10 -> V_14 ,
V_10 -> V_13 ) ;
}
bool F_4 ( struct V_7 * V_8 , unsigned int V_1 )
{
if ( V_8 -> V_15 && V_1 > V_8 -> V_15 )
return false ;
if ( V_8 -> V_16 )
return V_8 -> V_16 ( V_8 -> V_17 , V_1 ) ;
if ( V_8 -> V_18 )
return F_3 ( V_8 , V_1 , V_8 -> V_18 ) ;
return true ;
}
bool F_5 ( struct V_7 * V_8 , unsigned int V_1 )
{
if ( V_8 -> V_15 && V_1 > V_8 -> V_15 )
return false ;
if ( V_8 -> V_19 . V_20 )
return false ;
if ( V_8 -> V_21 )
return V_8 -> V_21 ( V_8 -> V_17 , V_1 ) ;
if ( V_8 -> V_22 )
return F_3 ( V_8 , V_1 , V_8 -> V_22 ) ;
return true ;
}
bool F_6 ( struct V_7 * V_8 , unsigned int V_1 )
{
if ( ! F_5 ( V_8 , V_1 ) )
return false ;
if ( V_8 -> V_23 )
return V_8 -> V_23 ( V_8 -> V_17 , V_1 ) ;
if ( V_8 -> V_24 )
return F_3 ( V_8 , V_1 , V_8 -> V_24 ) ;
return true ;
}
bool F_7 ( struct V_7 * V_8 , unsigned int V_1 )
{
if ( ! F_5 ( V_8 , V_1 ) )
return false ;
if ( V_8 -> V_25 )
return V_8 -> V_25 ( V_8 -> V_17 , V_1 ) ;
if ( V_8 -> V_26 )
return F_3 ( V_8 , V_1 , V_8 -> V_26 ) ;
return false ;
}
static bool F_8 ( struct V_7 * V_8 , unsigned int V_1 ,
T_1 V_27 )
{
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_27 ; V_6 ++ )
if ( ! F_6 ( V_8 , V_1 + V_6 ) )
return false ;
return true ;
}
static void F_9 ( struct V_7 * V_8 ,
unsigned int V_1 , unsigned int V_28 )
{
T_2 * V_29 = V_8 -> V_30 ;
* V_29 = ( V_1 << 6 ) | V_28 ;
}
static void F_10 ( struct V_7 * V_8 ,
unsigned int V_1 , unsigned int V_28 )
{
T_3 * V_29 = V_8 -> V_30 ;
* V_29 = F_11 ( ( V_1 << 12 ) | V_28 ) ;
}
static void F_12 ( struct V_7 * V_8 ,
unsigned int V_1 , unsigned int V_28 )
{
T_3 * V_29 = V_8 -> V_30 ;
* V_29 = F_11 ( ( V_1 << 9 ) | V_28 ) ;
}
static void F_13 ( struct V_7 * V_8 ,
unsigned int V_1 , unsigned int V_28 )
{
T_2 * V_29 = V_8 -> V_30 ;
V_29 [ 2 ] = V_28 ;
V_29 [ 1 ] = ( V_28 >> 8 ) | ( V_1 << 6 ) ;
V_29 [ 0 ] = V_1 >> 2 ;
}
static void F_14 ( void * V_31 , unsigned int V_28 , unsigned int V_32 )
{
T_2 * V_33 = V_31 ;
V_33 [ 0 ] = V_28 << V_32 ;
}
static void F_15 ( void * V_31 , unsigned int V_28 , unsigned int V_32 )
{
T_3 * V_33 = V_31 ;
V_33 [ 0 ] = F_11 ( V_28 << V_32 ) ;
}
static void F_16 ( void * V_31 , unsigned int V_28 ,
unsigned int V_32 )
{
* ( V_34 * ) V_31 = V_28 << V_32 ;
}
static void F_17 ( void * V_31 , unsigned int V_28 , unsigned int V_32 )
{
T_2 * V_33 = V_31 ;
V_28 <<= V_32 ;
V_33 [ 0 ] = V_28 >> 16 ;
V_33 [ 1 ] = V_28 >> 8 ;
V_33 [ 2 ] = V_28 ;
}
static void F_18 ( void * V_31 , unsigned int V_28 , unsigned int V_32 )
{
T_4 * V_33 = V_31 ;
V_33 [ 0 ] = F_19 ( V_28 << V_32 ) ;
}
static void F_20 ( void * V_31 , unsigned int V_28 ,
unsigned int V_32 )
{
* ( V_35 * ) V_31 = V_28 << V_32 ;
}
static unsigned int F_21 ( void * V_31 )
{
T_2 * V_33 = V_31 ;
return V_33 [ 0 ] ;
}
static unsigned int F_22 ( void * V_31 )
{
T_3 * V_33 = V_31 ;
V_33 [ 0 ] = F_23 ( V_33 [ 0 ] ) ;
return V_33 [ 0 ] ;
}
static unsigned int F_24 ( void * V_31 )
{
return * ( V_34 * ) V_31 ;
}
static unsigned int F_25 ( void * V_31 )
{
T_2 * V_33 = V_31 ;
unsigned int V_36 = V_33 [ 2 ] ;
V_36 |= ( ( unsigned int ) V_33 [ 1 ] ) << 8 ;
V_36 |= ( ( unsigned int ) V_33 [ 0 ] ) << 16 ;
return V_36 ;
}
static unsigned int F_26 ( void * V_31 )
{
T_4 * V_33 = V_31 ;
V_33 [ 0 ] = F_27 ( V_33 [ 0 ] ) ;
return V_33 [ 0 ] ;
}
static unsigned int F_28 ( void * V_31 )
{
return * ( V_35 * ) V_31 ;
}
static void F_29 ( void * V_37 )
{
struct V_7 * V_8 = V_37 ;
F_30 ( & V_8 -> V_38 ) ;
}
static void F_31 ( void * V_37 )
{
struct V_7 * V_8 = V_37 ;
F_32 ( & V_8 -> V_38 ) ;
}
static void F_33 ( void * V_37 )
{
struct V_7 * V_8 = V_37 ;
F_34 ( & V_8 -> V_39 ) ;
}
static void F_35 ( void * V_37 )
{
struct V_7 * V_8 = V_37 ;
F_36 ( & V_8 -> V_39 ) ;
}
static void F_37 ( struct V_40 * V_17 , void * V_41 )
{
}
static bool F_38 ( struct V_7 * V_8 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 = & V_8 -> V_46 ;
struct V_47 * * V_48 = & ( V_45 -> V_47 ) , * V_49 = NULL ;
while ( * V_48 ) {
struct V_42 * V_50 =
F_39 ( * V_48 , struct V_42 , V_51 ) ;
V_49 = * V_48 ;
if ( V_43 -> V_52 < V_50 -> V_53 )
V_48 = & ( ( * V_48 ) -> V_54 ) ;
else if ( V_43 -> V_53 > V_50 -> V_52 )
V_48 = & ( ( * V_48 ) -> V_55 ) ;
else
return false ;
}
F_40 ( & V_43 -> V_51 , V_49 , V_48 ) ;
F_41 ( & V_43 -> V_51 , V_45 ) ;
return true ;
}
static struct V_42 * F_42 ( struct V_7 * V_8 ,
unsigned int V_1 )
{
struct V_47 * V_51 = V_8 -> V_46 . V_47 ;
while ( V_51 ) {
struct V_42 * V_50 =
F_39 ( V_51 , struct V_42 , V_51 ) ;
if ( V_1 < V_50 -> V_53 )
V_51 = V_51 -> V_54 ;
else if ( V_1 > V_50 -> V_52 )
V_51 = V_51 -> V_55 ;
else
return V_50 ;
}
return NULL ;
}
static void F_43 ( struct V_7 * V_8 )
{
struct V_47 * V_56 ;
struct V_42 * V_57 ;
V_56 = F_44 ( & V_8 -> V_46 ) ;
while ( V_56 ) {
V_57 = F_45 ( V_56 , struct V_42 , V_51 ) ;
V_56 = F_46 ( & V_57 -> V_51 ) ;
F_47 ( & V_57 -> V_51 , & V_8 -> V_46 ) ;
F_48 ( V_57 ) ;
}
F_48 ( V_8 -> V_58 ) ;
}
struct V_7 * F_49 ( struct V_40 * V_17 ,
const struct V_59 * V_60 ,
void * V_61 ,
const struct V_62 * V_63 )
{
struct V_7 * V_8 , * * V_64 ;
int V_36 = - V_65 ;
enum V_66 V_67 , V_68 ;
int V_6 , V_69 ;
if ( ! V_60 || ! V_63 )
goto V_70;
V_8 = F_50 ( sizeof( * V_8 ) , V_71 ) ;
if ( V_8 == NULL ) {
V_36 = - V_72 ;
goto V_70;
}
if ( V_63 -> V_73 && V_63 -> V_74 ) {
V_8 -> V_73 = V_63 -> V_73 ;
V_8 -> V_74 = V_63 -> V_74 ;
V_8 -> V_75 = V_63 -> V_75 ;
} else {
if ( V_60 -> V_76 ) {
F_51 ( & V_8 -> V_39 ) ;
V_8 -> V_73 = F_33 ;
V_8 -> V_74 = F_35 ;
} else {
F_52 ( & V_8 -> V_38 ) ;
V_8 -> V_73 = F_29 ;
V_8 -> V_74 = F_31 ;
}
V_8 -> V_75 = V_8 ;
}
V_8 -> V_19 . V_77 = F_53 ( V_63 -> V_78 , 8 ) ;
V_8 -> V_19 . V_79 = V_63 -> V_80 / 8 ;
V_8 -> V_19 . V_81 = F_53 ( V_63 -> V_82 , 8 ) ;
V_8 -> V_19 . V_83 = F_53 ( V_63 -> V_78 +
V_63 -> V_82 + V_63 -> V_80 , 8 ) ;
V_8 -> V_84 = V_63 -> V_80 % 8 ;
if ( V_63 -> V_85 )
V_8 -> V_85 = V_63 -> V_85 ;
else
V_8 -> V_85 = 1 ;
V_8 -> V_86 = V_63 -> V_86 ;
V_8 -> V_17 = V_17 ;
V_8 -> V_60 = V_60 ;
V_8 -> V_61 = V_61 ;
V_8 -> V_15 = V_63 -> V_15 ;
V_8 -> V_18 = V_63 -> V_18 ;
V_8 -> V_22 = V_63 -> V_22 ;
V_8 -> V_24 = V_63 -> V_24 ;
V_8 -> V_26 = V_63 -> V_26 ;
V_8 -> V_16 = V_63 -> V_16 ;
V_8 -> V_21 = V_63 -> V_21 ;
V_8 -> V_23 = V_63 -> V_23 ;
V_8 -> V_25 = V_63 -> V_25 ;
V_8 -> V_87 = V_63 -> V_87 ;
V_8 -> V_88 = V_63 -> V_88 ;
if ( V_63 -> V_89 || V_63 -> V_90 ) {
V_8 -> V_89 = V_63 -> V_89 ;
V_8 -> V_90 = V_63 -> V_90 ;
} else {
V_8 -> V_89 = V_60 -> V_89 ;
}
V_67 = V_63 -> V_91 ;
if ( V_67 == V_92 )
V_67 = V_60 -> V_93 ;
if ( V_67 == V_92 )
V_67 = V_94 ;
V_68 = V_63 -> V_95 ;
if ( V_68 == V_92 )
V_68 = V_60 -> V_96 ;
if ( V_68 == V_92 )
V_68 = V_94 ;
switch ( V_63 -> V_78 + V_8 -> V_84 ) {
case 2 :
switch ( V_63 -> V_82 ) {
case 6 :
V_8 -> V_19 . V_20 = F_9 ;
break;
default:
goto V_97;
}
break;
case 4 :
switch ( V_63 -> V_82 ) {
case 12 :
V_8 -> V_19 . V_20 = F_10 ;
break;
default:
goto V_97;
}
break;
case 7 :
switch ( V_63 -> V_82 ) {
case 9 :
V_8 -> V_19 . V_20 = F_12 ;
break;
default:
goto V_97;
}
break;
case 10 :
switch ( V_63 -> V_82 ) {
case 14 :
V_8 -> V_19 . V_20 = F_13 ;
break;
default:
goto V_97;
}
break;
case 8 :
V_8 -> V_19 . V_98 = F_14 ;
break;
case 16 :
switch ( V_67 ) {
case V_94 :
V_8 -> V_19 . V_98 = F_15 ;
break;
case V_99 :
V_8 -> V_19 . V_98 = F_16 ;
break;
default:
goto V_97;
}
break;
case 32 :
switch ( V_67 ) {
case V_94 :
V_8 -> V_19 . V_98 = F_18 ;
break;
case V_99 :
V_8 -> V_19 . V_98 = F_20 ;
break;
default:
goto V_97;
}
break;
default:
goto V_97;
}
switch ( V_63 -> V_82 ) {
case 8 :
V_8 -> V_19 . V_100 = F_14 ;
V_8 -> V_19 . V_101 = F_21 ;
break;
case 16 :
switch ( V_68 ) {
case V_94 :
V_8 -> V_19 . V_100 = F_15 ;
V_8 -> V_19 . V_101 = F_22 ;
break;
case V_99 :
V_8 -> V_19 . V_100 = F_16 ;
V_8 -> V_19 . V_101 = F_24 ;
break;
default:
goto V_97;
}
break;
case 24 :
if ( V_68 != V_94 )
goto V_97;
V_8 -> V_19 . V_100 = F_17 ;
V_8 -> V_19 . V_101 = F_25 ;
break;
case 32 :
switch ( V_68 ) {
case V_94 :
V_8 -> V_19 . V_100 = F_18 ;
V_8 -> V_19 . V_101 = F_26 ;
break;
case V_99 :
V_8 -> V_19 . V_100 = F_20 ;
V_8 -> V_19 . V_101 = F_28 ;
break;
default:
goto V_97;
}
break;
}
if ( V_8 -> V_19 . V_20 ) {
if ( ( V_67 != V_94 ) ||
( V_68 != V_94 ) )
goto V_97;
V_8 -> V_86 = true ;
}
if ( ! V_8 -> V_19 . V_20 &&
! ( V_8 -> V_19 . V_98 && V_8 -> V_19 . V_100 ) )
goto V_97;
V_8 -> V_30 = F_50 ( V_8 -> V_19 . V_83 , V_71 ) ;
if ( V_8 -> V_30 == NULL ) {
V_36 = - V_72 ;
goto V_97;
}
V_8 -> V_46 = V_102 ;
for ( V_6 = 0 ; V_6 < V_63 -> V_103 ; V_6 ++ ) {
const struct V_104 * V_105 = & V_63 -> V_3 [ V_6 ] ;
struct V_42 * V_48 ;
if ( V_105 -> V_52 < V_105 -> V_53 ) {
F_54 ( V_8 -> V_17 , L_1 , V_6 ,
V_105 -> V_52 , V_105 -> V_53 ) ;
goto V_106;
}
if ( V_105 -> V_52 > V_8 -> V_15 ) {
F_54 ( V_8 -> V_17 , L_2 , V_6 ,
V_105 -> V_52 , V_8 -> V_15 ) ;
goto V_106;
}
if ( V_105 -> V_107 > V_8 -> V_15 ) {
F_54 ( V_8 -> V_17 ,
L_3 , V_6 ) ;
goto V_106;
}
if ( V_105 -> V_108 == 0 ) {
F_54 ( V_8 -> V_17 , L_4 ,
V_6 ) ;
goto V_106;
}
for ( V_69 = 0 ; V_69 < V_63 -> V_103 ; V_69 ++ ) {
unsigned V_109 = V_63 -> V_3 [ V_69 ] . V_107 ;
unsigned V_110 = V_63 -> V_3 [ V_69 ] . V_111 ;
unsigned V_112 = V_110 +
V_63 -> V_3 [ V_69 ] . V_108 - 1 ;
if ( V_105 -> V_53 <= V_109 &&
V_109 <= V_105 -> V_52 ) {
F_54 ( V_8 -> V_17 ,
L_5 ,
V_6 , V_69 ) ;
goto V_106;
}
if ( ! ( V_112 < V_105 -> V_53 ||
V_110 > V_105 -> V_52 ) ) {
F_54 ( V_8 -> V_17 ,
L_6 ,
V_6 , V_69 ) ;
goto V_106;
}
}
V_48 = F_50 ( sizeof( * V_48 ) , V_71 ) ;
if ( V_48 == NULL ) {
V_36 = - V_72 ;
goto V_106;
}
V_48 -> V_8 = V_8 ;
V_48 -> V_88 = V_105 -> V_88 ;
V_48 -> V_53 = V_105 -> V_53 ;
V_48 -> V_52 = V_105 -> V_52 ;
V_48 -> V_107 = V_105 -> V_107 ;
V_48 -> V_113 = V_105 -> V_113 ;
V_48 -> V_114 = V_105 -> V_114 ;
V_48 -> V_111 = V_105 -> V_111 ;
V_48 -> V_108 = V_105 -> V_108 ;
if ( F_38 ( V_8 , V_48 ) == false ) {
F_54 ( V_8 -> V_17 , L_7 , V_6 ) ;
F_48 ( V_48 ) ;
goto V_106;
}
if ( V_8 -> V_58 == NULL ) {
V_8 -> V_58 =
F_50 ( V_8 -> V_19 . V_83 , V_71 ) ;
if ( V_8 -> V_58 == NULL ) {
V_36 = - V_72 ;
goto V_106;
}
}
}
V_36 = F_55 ( V_8 , V_63 ) ;
if ( V_36 != 0 )
goto V_106;
F_56 ( V_8 , V_63 -> V_88 ) ;
V_64 = F_57 ( F_37 , sizeof( * V_64 ) , V_71 ) ;
if ( ! V_64 ) {
V_36 = - V_72 ;
goto V_115;
}
* V_64 = V_8 ;
F_58 ( V_17 , V_64 ) ;
return V_8 ;
V_115:
F_59 ( V_8 ) ;
F_60 ( V_8 ) ;
V_106:
F_43 ( V_8 ) ;
F_48 ( V_8 -> V_30 ) ;
V_97:
F_48 ( V_8 ) ;
V_70:
return F_61 ( V_36 ) ;
}
static void F_62 ( struct V_40 * V_17 , void * V_41 )
{
F_63 ( * (struct V_7 * * ) V_41 ) ;
}
struct V_7 * F_64 ( struct V_40 * V_17 ,
const struct V_59 * V_60 ,
void * V_61 ,
const struct V_62 * V_63 )
{
struct V_7 * * V_116 , * V_7 ;
V_116 = F_57 ( F_62 , sizeof( * V_116 ) , V_71 ) ;
if ( ! V_116 )
return F_61 ( - V_72 ) ;
V_7 = F_49 ( V_17 , V_60 , V_61 , V_63 ) ;
if ( ! F_65 ( V_7 ) ) {
* V_116 = V_7 ;
F_58 ( V_17 , V_116 ) ;
} else {
F_66 ( V_116 ) ;
}
return V_7 ;
}
int F_67 ( struct V_7 * V_8 , const struct V_62 * V_63 )
{
F_60 ( V_8 ) ;
F_59 ( V_8 ) ;
V_8 -> V_15 = V_63 -> V_15 ;
V_8 -> V_16 = V_63 -> V_16 ;
V_8 -> V_21 = V_63 -> V_21 ;
V_8 -> V_23 = V_63 -> V_23 ;
V_8 -> V_25 = V_63 -> V_25 ;
V_8 -> V_87 = V_63 -> V_87 ;
F_56 ( V_8 , V_63 -> V_88 ) ;
V_8 -> V_117 = false ;
V_8 -> V_118 = false ;
return F_55 ( V_8 , V_63 ) ;
}
void F_63 ( struct V_7 * V_8 )
{
F_60 ( V_8 ) ;
F_59 ( V_8 ) ;
F_43 ( V_8 ) ;
if ( V_8 -> V_60 -> V_119 )
V_8 -> V_60 -> V_119 ( V_8 -> V_61 ) ;
F_48 ( V_8 -> V_30 ) ;
F_48 ( V_8 ) ;
}
static int F_68 ( struct V_40 * V_17 , void * V_41 , void * V_43 )
{
struct V_7 * * V_5 = V_41 ;
if ( ! V_5 || ! * V_5 ) {
F_69 ( ! V_5 || ! * V_5 ) ;
return 0 ;
}
if ( V_43 )
return ( * V_5 ) -> V_88 == V_43 ;
else
return 1 ;
}
struct V_7 * F_70 ( struct V_40 * V_17 , const char * V_88 )
{
struct V_7 * * V_5 = F_71 ( V_17 , F_37 ,
F_68 , ( void * ) V_88 ) ;
if ( ! V_5 )
return NULL ;
return * V_5 ;
}
static int F_72 ( struct V_7 * V_8 , unsigned int * V_1 ,
struct V_42 * V_120 ,
unsigned int V_121 )
{
void * V_122 ;
unsigned int V_123 ;
unsigned int V_124 ;
bool V_125 ;
int V_36 ;
V_123 = ( * V_1 - V_120 -> V_53 ) % V_120 -> V_108 ;
V_124 = ( * V_1 - V_120 -> V_53 ) / V_120 -> V_108 ;
if ( V_121 > 1 ) {
if ( * V_1 + V_121 - 1 > V_120 -> V_52 )
return - V_65 ;
if ( V_121 > V_120 -> V_108 - V_123 )
return - V_65 ;
}
if ( V_121 > 1 ||
V_120 -> V_111 + V_123 != V_120 -> V_107 ) {
V_122 = V_8 -> V_30 ;
V_8 -> V_30 = V_8 -> V_58 ;
V_36 = F_73 ( V_8 , V_120 -> V_107 ,
V_120 -> V_113 ,
V_124 << V_120 -> V_114 ,
& V_125 ) ;
V_8 -> V_30 = V_122 ;
if ( V_36 != 0 )
return V_36 ;
}
* V_1 = V_120 -> V_111 + V_123 ;
return 0 ;
}
static int F_74 ( struct V_7 * V_8 , unsigned int V_1 ,
const void * V_28 , T_1 V_126 )
{
struct V_42 * V_120 ;
T_2 * T_2 = V_8 -> V_30 ;
void * V_31 ;
int V_36 = - V_127 ;
T_1 V_128 ;
int V_6 ;
if ( V_8 -> V_16 )
for ( V_6 = 0 ; V_6 < V_126 / V_8 -> V_19 . V_81 ; V_6 ++ )
if ( ! V_8 -> V_16 ( V_8 -> V_17 ,
V_1 + ( V_6 * V_8 -> V_85 ) ) )
return - V_65 ;
if ( ! V_8 -> V_117 && V_8 -> V_19 . V_101 ) {
unsigned int V_129 ;
int V_81 = V_8 -> V_19 . V_81 ;
for ( V_6 = 0 ; V_6 < V_126 / V_81 ; V_6 ++ ) {
memcpy ( V_8 -> V_30 , V_28 + ( V_6 * V_81 ) , V_81 ) ;
V_129 = V_8 -> V_19 . V_101 ( V_8 -> V_30 ) ;
V_36 = F_75 ( V_8 , V_1 + ( V_6 * V_8 -> V_85 ) ,
V_129 ) ;
if ( V_36 ) {
F_54 ( V_8 -> V_17 ,
L_8 ,
V_1 + V_6 , V_36 ) ;
return V_36 ;
}
}
if ( V_8 -> V_118 ) {
V_8 -> V_130 = true ;
return 0 ;
}
}
V_120 = F_42 ( V_8 , V_1 ) ;
if ( V_120 ) {
int V_121 = V_126 / V_8 -> V_19 . V_81 ;
int V_123 = ( V_1 - V_120 -> V_53 ) % V_120 -> V_108 ;
int V_131 = V_120 -> V_108 - V_123 ;
while ( V_121 > V_131 ) {
F_76 ( V_8 -> V_17 , L_9 ,
V_131 , V_126 / V_8 -> V_19 . V_81 ) ;
V_36 = F_74 ( V_8 , V_1 , V_28 , V_131 *
V_8 -> V_19 . V_81 ) ;
if ( V_36 != 0 )
return V_36 ;
V_1 += V_131 ;
V_121 -= V_131 ;
V_28 += V_131 * V_8 -> V_19 . V_81 ;
V_126 -= V_131 * V_8 -> V_19 . V_81 ;
V_123 = ( V_1 - V_120 -> V_53 ) %
V_120 -> V_108 ;
V_131 = V_120 -> V_108 - V_123 ;
}
V_36 = F_72 ( V_8 , & V_1 , V_120 , V_121 ) ;
if ( V_36 != 0 )
return V_36 ;
}
V_8 -> V_19 . V_98 ( V_8 -> V_30 , V_1 , V_8 -> V_84 ) ;
T_2 [ 0 ] |= V_8 -> V_90 ;
F_77 ( V_8 -> V_17 , V_1 ,
V_126 / V_8 -> V_19 . V_81 ) ;
if ( V_28 == ( V_8 -> V_30 + V_8 -> V_19 . V_79 +
V_8 -> V_19 . V_77 ) )
V_36 = V_8 -> V_60 -> V_132 ( V_8 -> V_61 , V_8 -> V_30 ,
V_8 -> V_19 . V_77 +
V_8 -> V_19 . V_79 +
V_126 ) ;
else if ( V_8 -> V_60 -> V_133 )
V_36 = V_8 -> V_60 -> V_133 ( V_8 -> V_61 , V_8 -> V_30 ,
V_8 -> V_19 . V_77 +
V_8 -> V_19 . V_79 ,
V_28 , V_126 ) ;
if ( V_36 == - V_127 ) {
V_128 = V_8 -> V_19 . V_77 + V_8 -> V_19 . V_79 + V_126 ;
V_31 = F_50 ( V_128 , V_71 ) ;
if ( ! V_31 )
return - V_72 ;
memcpy ( V_31 , V_8 -> V_30 , V_8 -> V_19 . V_77 ) ;
memcpy ( V_31 + V_8 -> V_19 . V_77 + V_8 -> V_19 . V_79 ,
V_28 , V_126 ) ;
V_36 = V_8 -> V_60 -> V_132 ( V_8 -> V_61 , V_31 , V_128 ) ;
F_48 ( V_31 ) ;
}
F_78 ( V_8 -> V_17 , V_1 ,
V_126 / V_8 -> V_19 . V_81 ) ;
return V_36 ;
}
int F_79 ( struct V_7 * V_8 , unsigned int V_1 ,
unsigned int V_28 )
{
struct V_42 * V_120 ;
int V_36 ;
F_80 ( ! V_8 -> V_19 . V_20 && ! V_8 -> V_19 . V_100 ) ;
if ( ! V_8 -> V_117 && V_8 -> V_19 . V_20 ) {
V_36 = F_75 ( V_8 , V_1 , V_28 ) ;
if ( V_36 != 0 )
return V_36 ;
if ( V_8 -> V_118 ) {
V_8 -> V_130 = true ;
return 0 ;
}
}
#ifdef F_81
if ( strcmp ( F_82 ( V_8 -> V_17 ) , F_81 ) == 0 )
F_83 ( V_8 -> V_17 , L_10 , V_1 , V_28 ) ;
#endif
F_84 ( V_8 -> V_17 , V_1 , V_28 ) ;
if ( V_8 -> V_19 . V_20 ) {
V_120 = F_42 ( V_8 , V_1 ) ;
if ( V_120 ) {
V_36 = F_72 ( V_8 , & V_1 , V_120 , 1 ) ;
if ( V_36 != 0 )
return V_36 ;
}
V_8 -> V_19 . V_20 ( V_8 , V_1 , V_28 ) ;
F_77 ( V_8 -> V_17 , V_1 , 1 ) ;
V_36 = V_8 -> V_60 -> V_132 ( V_8 -> V_61 , V_8 -> V_30 ,
V_8 -> V_19 . V_83 ) ;
F_78 ( V_8 -> V_17 , V_1 , 1 ) ;
return V_36 ;
} else {
V_8 -> V_19 . V_100 ( V_8 -> V_30 + V_8 -> V_19 . V_77
+ V_8 -> V_19 . V_79 , V_28 , 0 ) ;
return F_74 ( V_8 , V_1 ,
V_8 -> V_30 +
V_8 -> V_19 . V_77 +
V_8 -> V_19 . V_79 ,
V_8 -> V_19 . V_81 ) ;
}
}
int F_85 ( struct V_7 * V_8 , unsigned int V_1 , unsigned int V_28 )
{
int V_36 ;
if ( V_1 % V_8 -> V_85 )
return - V_65 ;
V_8 -> V_73 ( V_8 -> V_75 ) ;
V_36 = F_79 ( V_8 , V_1 , V_28 ) ;
V_8 -> V_74 ( V_8 -> V_75 ) ;
return V_36 ;
}
int F_86 ( struct V_7 * V_8 , unsigned int V_1 ,
const void * V_28 , T_1 V_126 )
{
int V_36 ;
if ( V_126 % V_8 -> V_19 . V_81 )
return - V_65 ;
if ( V_1 % V_8 -> V_85 )
return - V_65 ;
V_8 -> V_73 ( V_8 -> V_75 ) ;
V_36 = F_74 ( V_8 , V_1 , V_28 , V_126 ) ;
V_8 -> V_74 ( V_8 -> V_75 ) ;
return V_36 ;
}
int F_87 ( struct V_7 * V_8 , unsigned int V_1 , const void * V_28 ,
T_1 V_134 )
{
int V_36 = 0 , V_6 ;
T_1 V_81 = V_8 -> V_19 . V_81 ;
void * V_135 ;
if ( ! V_8 -> V_19 . V_101 )
return - V_65 ;
if ( V_1 % V_8 -> V_85 )
return - V_65 ;
V_8 -> V_73 ( V_8 -> V_75 ) ;
if ( V_81 == 1 ) {
V_135 = ( void * ) V_28 ;
} else {
V_135 = F_88 ( V_28 , V_134 * V_81 , V_71 ) ;
if ( ! V_135 ) {
V_36 = - V_72 ;
F_54 ( V_8 -> V_17 , L_11 ) ;
goto V_29;
}
for ( V_6 = 0 ; V_6 < V_134 * V_81 ; V_6 += V_81 )
V_8 -> V_19 . V_101 ( V_135 + V_6 ) ;
}
if ( V_8 -> V_86 ) {
for ( V_6 = 0 ; V_6 < V_134 ; V_6 ++ ) {
V_36 = F_86 ( V_8 ,
V_1 + ( V_6 * V_8 -> V_85 ) ,
V_28 + ( V_6 * V_81 ) ,
V_81 ) ;
if ( V_36 != 0 )
return V_36 ;
}
} else {
V_36 = F_74 ( V_8 , V_1 , V_135 , V_81 * V_134 ) ;
}
if ( V_81 != 1 )
F_48 ( V_135 ) ;
V_29:
V_8 -> V_74 ( V_8 -> V_75 ) ;
return V_36 ;
}
static int F_89 ( struct V_7 * V_8 , unsigned int V_1 , void * V_28 ,
unsigned int V_126 )
{
struct V_42 * V_120 ;
T_2 * T_2 = V_8 -> V_30 ;
int V_36 ;
V_120 = F_42 ( V_8 , V_1 ) ;
if ( V_120 ) {
V_36 = F_72 ( V_8 , & V_1 , V_120 ,
V_126 / V_8 -> V_19 . V_81 ) ;
if ( V_36 != 0 )
return V_36 ;
}
V_8 -> V_19 . V_98 ( V_8 -> V_30 , V_1 , V_8 -> V_84 ) ;
T_2 [ 0 ] |= V_8 -> V_89 ;
F_90 ( V_8 -> V_17 , V_1 ,
V_126 / V_8 -> V_19 . V_81 ) ;
V_36 = V_8 -> V_60 -> V_136 ( V_8 -> V_61 , V_8 -> V_30 ,
V_8 -> V_19 . V_77 + V_8 -> V_19 . V_79 ,
V_28 , V_126 ) ;
F_91 ( V_8 -> V_17 , V_1 ,
V_126 / V_8 -> V_19 . V_81 ) ;
return V_36 ;
}
static int F_92 ( struct V_7 * V_8 , unsigned int V_1 ,
unsigned int * V_28 )
{
int V_36 ;
if ( ! V_8 -> V_117 ) {
V_36 = F_93 ( V_8 , V_1 , V_28 ) ;
if ( V_36 == 0 )
return 0 ;
}
if ( ! V_8 -> V_19 . V_101 )
return - V_65 ;
if ( V_8 -> V_118 )
return - V_137 ;
V_36 = F_89 ( V_8 , V_1 , V_8 -> V_30 , V_8 -> V_19 . V_81 ) ;
if ( V_36 == 0 ) {
* V_28 = V_8 -> V_19 . V_101 ( V_8 -> V_30 ) ;
#ifdef F_81
if ( strcmp ( F_82 ( V_8 -> V_17 ) , F_81 ) == 0 )
F_83 ( V_8 -> V_17 , L_12 , V_1 , * V_28 ) ;
#endif
F_94 ( V_8 -> V_17 , V_1 , * V_28 ) ;
}
if ( V_36 == 0 && ! V_8 -> V_117 )
F_75 ( V_8 , V_1 , * V_28 ) ;
return V_36 ;
}
int F_95 ( struct V_7 * V_8 , unsigned int V_1 , unsigned int * V_28 )
{
int V_36 ;
if ( V_1 % V_8 -> V_85 )
return - V_65 ;
V_8 -> V_73 ( V_8 -> V_75 ) ;
V_36 = F_92 ( V_8 , V_1 , V_28 ) ;
V_8 -> V_74 ( V_8 -> V_75 ) ;
return V_36 ;
}
int F_96 ( struct V_7 * V_8 , unsigned int V_1 , void * V_28 ,
T_1 V_126 )
{
T_1 V_81 = V_8 -> V_19 . V_81 ;
T_1 V_134 = V_126 / V_81 ;
unsigned int V_138 ;
int V_36 , V_6 ;
if ( V_126 % V_8 -> V_19 . V_81 )
return - V_65 ;
if ( V_1 % V_8 -> V_85 )
return - V_65 ;
V_8 -> V_73 ( V_8 -> V_75 ) ;
if ( F_8 ( V_8 , V_1 , V_134 ) || V_8 -> V_117 ||
V_8 -> V_87 == V_139 ) {
V_36 = F_89 ( V_8 , V_1 , V_28 , V_126 ) ;
} else {
for ( V_6 = 0 ; V_6 < V_134 ; V_6 ++ ) {
V_36 = F_92 ( V_8 , V_1 + ( V_6 * V_8 -> V_85 ) ,
& V_138 ) ;
if ( V_36 != 0 )
goto V_29;
V_8 -> V_19 . V_100 ( V_28 + ( V_6 * V_81 ) , V_138 , 0 ) ;
}
}
V_29:
V_8 -> V_74 ( V_8 -> V_75 ) ;
return V_36 ;
}
int F_97 ( struct V_7 * V_8 , unsigned int V_1 , void * V_28 ,
T_1 V_134 )
{
int V_36 , V_6 ;
T_1 V_81 = V_8 -> V_19 . V_81 ;
bool V_140 = F_8 ( V_8 , V_1 , V_134 ) ;
if ( ! V_8 -> V_19 . V_101 )
return - V_65 ;
if ( V_1 % V_8 -> V_85 )
return - V_65 ;
if ( V_140 || V_8 -> V_87 == V_139 ) {
if ( V_8 -> V_86 ) {
for ( V_6 = 0 ; V_6 < V_134 ; V_6 ++ ) {
V_36 = F_96 ( V_8 ,
V_1 + ( V_6 * V_8 -> V_85 ) ,
V_28 + ( V_6 * V_81 ) ,
V_81 ) ;
if ( V_36 != 0 )
return V_36 ;
}
} else {
V_36 = F_96 ( V_8 , V_1 , V_28 ,
V_81 * V_134 ) ;
if ( V_36 != 0 )
return V_36 ;
}
for ( V_6 = 0 ; V_6 < V_134 * V_81 ; V_6 += V_81 )
V_8 -> V_19 . V_101 ( V_28 + V_6 ) ;
} else {
for ( V_6 = 0 ; V_6 < V_134 ; V_6 ++ ) {
unsigned int V_129 ;
V_36 = F_95 ( V_8 , V_1 + ( V_6 * V_8 -> V_85 ) ,
& V_129 ) ;
if ( V_36 != 0 )
return V_36 ;
memcpy ( V_28 + ( V_6 * V_81 ) , & V_129 , V_81 ) ;
}
}
return 0 ;
}
static int F_73 ( struct V_7 * V_8 , unsigned int V_1 ,
unsigned int V_141 , unsigned int V_28 ,
bool * V_142 )
{
int V_36 ;
unsigned int V_143 , V_144 ;
V_36 = F_92 ( V_8 , V_1 , & V_144 ) ;
if ( V_36 != 0 )
return V_36 ;
V_143 = V_144 & ~ V_141 ;
V_143 |= V_28 & V_141 ;
if ( V_143 != V_144 ) {
V_36 = F_79 ( V_8 , V_1 , V_143 ) ;
* V_142 = true ;
} else {
* V_142 = false ;
}
return V_36 ;
}
int F_98 ( struct V_7 * V_8 , unsigned int V_1 ,
unsigned int V_141 , unsigned int V_28 )
{
bool V_142 ;
int V_36 ;
V_8 -> V_73 ( V_8 -> V_75 ) ;
V_36 = F_73 ( V_8 , V_1 , V_141 , V_28 , & V_142 ) ;
V_8 -> V_74 ( V_8 -> V_75 ) ;
return V_36 ;
}
int F_99 ( struct V_7 * V_8 , unsigned int V_1 ,
unsigned int V_141 , unsigned int V_28 ,
bool * V_142 )
{
int V_36 ;
V_8 -> V_73 ( V_8 -> V_75 ) ;
V_36 = F_73 ( V_8 , V_1 , V_141 , V_28 , V_142 ) ;
V_8 -> V_74 ( V_8 -> V_75 ) ;
return V_36 ;
}
int F_100 ( struct V_7 * V_8 , const struct V_145 * V_146 ,
int V_147 )
{
int V_6 , V_36 ;
bool V_148 ;
if ( V_8 -> V_149 )
return - V_137 ;
V_8 -> V_73 ( V_8 -> V_75 ) ;
V_148 = V_8 -> V_117 ;
V_8 -> V_117 = true ;
for ( V_6 = 0 ; V_6 < V_147 ; V_6 ++ ) {
V_36 = F_79 ( V_8 , V_146 [ V_6 ] . V_1 , V_146 [ V_6 ] . V_150 ) ;
if ( V_36 != 0 ) {
F_54 ( V_8 -> V_17 , L_13 ,
V_146 [ V_6 ] . V_1 , V_146 [ V_6 ] . V_150 , V_36 ) ;
goto V_29;
}
}
V_8 -> V_149 = F_101 ( V_147 , sizeof( struct V_145 ) , V_71 ) ;
if ( V_8 -> V_149 != NULL ) {
memcpy ( V_8 -> V_149 , V_146 ,
V_147 * sizeof( struct V_145 ) ) ;
V_8 -> V_151 = V_147 ;
} else {
V_36 = - V_72 ;
}
V_29:
V_8 -> V_117 = V_148 ;
V_8 -> V_74 ( V_8 -> V_75 ) ;
return V_36 ;
}
int F_102 ( struct V_7 * V_8 )
{
if ( V_8 -> V_19 . V_20 )
return - V_65 ;
return V_8 -> V_19 . V_81 ;
}
static int T_5 F_103 ( void )
{
F_104 () ;
return 0 ;
}
