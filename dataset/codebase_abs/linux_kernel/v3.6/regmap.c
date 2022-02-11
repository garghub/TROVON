bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_2 -> V_4 && V_3 > V_2 -> V_4 )
return false ;
if ( V_2 -> V_5 )
return V_2 -> V_5 ( V_2 -> V_6 , V_3 ) ;
return true ;
}
bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_2 -> V_4 && V_3 > V_2 -> V_4 )
return false ;
if ( V_2 -> V_7 . V_8 )
return false ;
if ( V_2 -> V_9 )
return V_2 -> V_9 ( V_2 -> V_6 , V_3 ) ;
return true ;
}
bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( ! F_2 ( V_2 , V_3 ) )
return false ;
if ( V_2 -> V_10 )
return V_2 -> V_10 ( V_2 -> V_6 , V_3 ) ;
return true ;
}
bool F_4 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( ! F_2 ( V_2 , V_3 ) )
return false ;
if ( V_2 -> V_11 )
return V_2 -> V_11 ( V_2 -> V_6 , V_3 ) ;
return false ;
}
static bool F_5 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_12 )
{
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ )
if ( ! F_3 ( V_2 , V_3 + V_13 ) )
return false ;
return true ;
}
static void F_6 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_14 )
{
T_1 * V_15 = V_2 -> V_16 ;
* V_15 = ( V_3 << 6 ) | V_14 ;
}
static void F_7 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_14 )
{
T_2 * V_15 = V_2 -> V_16 ;
* V_15 = F_8 ( ( V_3 << 12 ) | V_14 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_14 )
{
T_2 * V_15 = V_2 -> V_16 ;
* V_15 = F_8 ( ( V_3 << 9 ) | V_14 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_14 )
{
T_1 * V_15 = V_2 -> V_16 ;
V_15 [ 2 ] = V_14 ;
V_15 [ 1 ] = ( V_14 >> 8 ) | ( V_3 << 6 ) ;
V_15 [ 0 ] = V_3 >> 2 ;
}
static void F_11 ( void * V_17 , unsigned int V_14 , unsigned int V_18 )
{
T_1 * V_19 = V_17 ;
V_19 [ 0 ] = V_14 << V_18 ;
}
static void F_12 ( void * V_17 , unsigned int V_14 , unsigned int V_18 )
{
T_2 * V_19 = V_17 ;
V_19 [ 0 ] = F_8 ( V_14 << V_18 ) ;
}
static void F_13 ( void * V_17 , unsigned int V_14 ,
unsigned int V_18 )
{
* ( V_20 * ) V_17 = V_14 << V_18 ;
}
static void F_14 ( void * V_17 , unsigned int V_14 , unsigned int V_18 )
{
T_1 * V_19 = V_17 ;
V_14 <<= V_18 ;
V_19 [ 0 ] = V_14 >> 16 ;
V_19 [ 1 ] = V_14 >> 8 ;
V_19 [ 2 ] = V_14 ;
}
static void F_15 ( void * V_17 , unsigned int V_14 , unsigned int V_18 )
{
T_3 * V_19 = V_17 ;
V_19 [ 0 ] = F_16 ( V_14 << V_18 ) ;
}
static void F_17 ( void * V_17 , unsigned int V_14 ,
unsigned int V_18 )
{
* ( V_21 * ) V_17 = V_14 << V_18 ;
}
static unsigned int F_18 ( void * V_17 )
{
T_1 * V_19 = V_17 ;
return V_19 [ 0 ] ;
}
static unsigned int F_19 ( void * V_17 )
{
T_2 * V_19 = V_17 ;
V_19 [ 0 ] = F_20 ( V_19 [ 0 ] ) ;
return V_19 [ 0 ] ;
}
static unsigned int F_21 ( void * V_17 )
{
return * ( V_20 * ) V_17 ;
}
static unsigned int F_22 ( void * V_17 )
{
T_1 * V_19 = V_17 ;
unsigned int V_22 = V_19 [ 2 ] ;
V_22 |= ( ( unsigned int ) V_19 [ 1 ] ) << 8 ;
V_22 |= ( ( unsigned int ) V_19 [ 0 ] ) << 16 ;
return V_22 ;
}
static unsigned int F_23 ( void * V_17 )
{
T_3 * V_19 = V_17 ;
V_19 [ 0 ] = F_24 ( V_19 [ 0 ] ) ;
return V_19 [ 0 ] ;
}
static unsigned int F_25 ( void * V_17 )
{
return * ( V_21 * ) V_17 ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_27 ( & V_2 -> V_23 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_29 ( & V_2 -> V_23 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_31 ( & V_2 -> V_24 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_33 ( & V_2 -> V_24 ) ;
}
static void F_34 ( struct V_25 * V_6 , void * V_26 )
{
}
static bool F_35 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 = & V_2 -> V_31 ;
struct V_32 * * V_33 = & ( V_30 -> V_32 ) , * V_34 = NULL ;
while ( * V_33 ) {
struct V_27 * V_35 =
F_36 ( * V_33 , struct V_27 , V_36 ) ;
V_34 = * V_33 ;
if ( V_28 -> V_37 < V_35 -> V_38 )
V_33 = & ( ( * V_33 ) -> V_39 ) ;
else if ( V_28 -> V_38 > V_35 -> V_37 )
V_33 = & ( ( * V_33 ) -> V_40 ) ;
else
return false ;
}
F_37 ( & V_28 -> V_36 , V_34 , V_33 ) ;
F_38 ( & V_28 -> V_36 , V_30 ) ;
return true ;
}
static struct V_27 * F_39 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_32 * V_36 = V_2 -> V_31 . V_32 ;
while ( V_36 ) {
struct V_27 * V_35 =
F_36 ( V_36 , struct V_27 , V_36 ) ;
if ( V_3 < V_35 -> V_38 )
V_36 = V_36 -> V_39 ;
else if ( V_3 > V_35 -> V_37 )
V_36 = V_36 -> V_40 ;
else
return V_35 ;
}
return NULL ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_32 * V_41 ;
struct V_27 * V_42 ;
V_41 = F_41 ( & V_2 -> V_31 ) ;
while ( V_41 ) {
V_42 = F_42 ( V_41 , struct V_27 , V_36 ) ;
V_41 = F_43 ( & V_42 -> V_36 ) ;
F_44 ( & V_42 -> V_36 , & V_2 -> V_31 ) ;
F_45 ( V_42 ) ;
}
F_45 ( V_2 -> V_43 ) ;
}
struct V_1 * F_46 ( struct V_25 * V_6 ,
const struct V_44 * V_45 ,
void * V_46 ,
const struct V_47 * V_48 )
{
struct V_1 * V_2 , * * V_49 ;
int V_22 = - V_50 ;
enum V_51 V_52 , V_53 ;
int V_13 , V_54 ;
if ( ! V_45 || ! V_48 )
goto V_55;
V_2 = F_47 ( sizeof( * V_2 ) , V_56 ) ;
if ( V_2 == NULL ) {
V_22 = - V_57 ;
goto V_55;
}
if ( V_45 -> V_58 ) {
F_48 ( & V_2 -> V_24 ) ;
V_2 -> V_59 = F_30 ;
V_2 -> V_60 = F_32 ;
} else {
F_49 ( & V_2 -> V_23 ) ;
V_2 -> V_59 = F_26 ;
V_2 -> V_60 = F_28 ;
}
V_2 -> V_7 . V_61 = F_50 ( V_48 -> V_62 , 8 ) ;
V_2 -> V_7 . V_63 = V_48 -> V_64 / 8 ;
V_2 -> V_7 . V_65 = F_50 ( V_48 -> V_66 , 8 ) ;
V_2 -> V_7 . V_67 = F_50 ( V_48 -> V_62 +
V_48 -> V_66 + V_48 -> V_64 , 8 ) ;
V_2 -> V_68 = V_48 -> V_64 % 8 ;
if ( V_48 -> V_69 )
V_2 -> V_69 = V_48 -> V_69 ;
else
V_2 -> V_69 = 1 ;
V_2 -> V_70 = V_48 -> V_70 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_45 = V_45 ;
V_2 -> V_46 = V_46 ;
V_2 -> V_4 = V_48 -> V_4 ;
V_2 -> V_5 = V_48 -> V_5 ;
V_2 -> V_9 = V_48 -> V_9 ;
V_2 -> V_10 = V_48 -> V_10 ;
V_2 -> V_11 = V_48 -> V_11 ;
V_2 -> V_71 = V_48 -> V_71 ;
V_2 -> V_72 = V_48 -> V_72 ;
if ( V_48 -> V_73 || V_48 -> V_74 ) {
V_2 -> V_73 = V_48 -> V_73 ;
V_2 -> V_74 = V_48 -> V_74 ;
} else {
V_2 -> V_73 = V_45 -> V_73 ;
}
V_52 = V_48 -> V_75 ;
if ( V_52 == V_76 )
V_52 = V_45 -> V_77 ;
if ( V_52 == V_76 )
V_52 = V_78 ;
V_53 = V_48 -> V_79 ;
if ( V_53 == V_76 )
V_53 = V_45 -> V_80 ;
if ( V_53 == V_76 )
V_53 = V_78 ;
switch ( V_48 -> V_62 + V_2 -> V_68 ) {
case 2 :
switch ( V_48 -> V_66 ) {
case 6 :
V_2 -> V_7 . V_8 = F_6 ;
break;
default:
goto V_81;
}
break;
case 4 :
switch ( V_48 -> V_66 ) {
case 12 :
V_2 -> V_7 . V_8 = F_7 ;
break;
default:
goto V_81;
}
break;
case 7 :
switch ( V_48 -> V_66 ) {
case 9 :
V_2 -> V_7 . V_8 = F_9 ;
break;
default:
goto V_81;
}
break;
case 10 :
switch ( V_48 -> V_66 ) {
case 14 :
V_2 -> V_7 . V_8 = F_10 ;
break;
default:
goto V_81;
}
break;
case 8 :
V_2 -> V_7 . V_82 = F_11 ;
break;
case 16 :
switch ( V_52 ) {
case V_78 :
V_2 -> V_7 . V_82 = F_12 ;
break;
case V_83 :
V_2 -> V_7 . V_82 = F_13 ;
break;
default:
goto V_81;
}
break;
case 32 :
switch ( V_52 ) {
case V_78 :
V_2 -> V_7 . V_82 = F_15 ;
break;
case V_83 :
V_2 -> V_7 . V_82 = F_17 ;
break;
default:
goto V_81;
}
break;
default:
goto V_81;
}
switch ( V_48 -> V_66 ) {
case 8 :
V_2 -> V_7 . V_84 = F_11 ;
V_2 -> V_7 . V_85 = F_18 ;
break;
case 16 :
switch ( V_53 ) {
case V_78 :
V_2 -> V_7 . V_84 = F_12 ;
V_2 -> V_7 . V_85 = F_19 ;
break;
case V_83 :
V_2 -> V_7 . V_84 = F_13 ;
V_2 -> V_7 . V_85 = F_21 ;
break;
default:
goto V_81;
}
break;
case 24 :
if ( V_53 != V_78 )
goto V_81;
V_2 -> V_7 . V_84 = F_14 ;
V_2 -> V_7 . V_85 = F_22 ;
break;
case 32 :
switch ( V_53 ) {
case V_78 :
V_2 -> V_7 . V_84 = F_15 ;
V_2 -> V_7 . V_85 = F_23 ;
break;
case V_83 :
V_2 -> V_7 . V_84 = F_17 ;
V_2 -> V_7 . V_85 = F_25 ;
break;
default:
goto V_81;
}
break;
}
if ( V_2 -> V_7 . V_8 ) {
if ( ( V_52 != V_78 ) ||
( V_53 != V_78 ) )
goto V_81;
V_2 -> V_70 = true ;
}
if ( ! V_2 -> V_7 . V_8 &&
! ( V_2 -> V_7 . V_82 && V_2 -> V_7 . V_84 ) )
goto V_81;
V_2 -> V_16 = F_47 ( V_2 -> V_7 . V_67 , V_56 ) ;
if ( V_2 -> V_16 == NULL ) {
V_22 = - V_57 ;
goto V_81;
}
V_2 -> V_31 = V_86 ;
for ( V_13 = 0 ; V_13 < V_48 -> V_87 ; V_13 ++ ) {
const struct V_88 * V_89 = & V_48 -> V_90 [ V_13 ] ;
struct V_27 * V_33 ;
if ( V_89 -> V_37 < V_89 -> V_38 ||
V_89 -> V_37 > V_2 -> V_4 ||
V_89 -> V_91 > V_2 -> V_4 ||
V_89 -> V_92 == 0 )
goto V_93;
for ( V_54 = 0 ; V_54 < V_48 -> V_87 ; V_54 ++ ) {
unsigned V_94 = V_48 -> V_90 [ V_54 ] . V_91 ;
unsigned V_95 = V_48 -> V_90 [ V_54 ] . V_96 ;
unsigned V_97 = V_95 +
V_48 -> V_90 [ V_54 ] . V_92 - 1 ;
if ( V_89 -> V_38 <= V_94 &&
V_94 <= V_89 -> V_37 ) {
goto V_93;
}
if ( ! ( V_97 < V_89 -> V_38 ||
V_95 > V_89 -> V_37 ) ) {
goto V_93;
}
}
V_33 = F_47 ( sizeof( * V_33 ) , V_56 ) ;
if ( V_33 == NULL ) {
V_22 = - V_57 ;
goto V_93;
}
V_33 -> V_38 = V_89 -> V_38 ;
V_33 -> V_37 = V_89 -> V_37 ;
V_33 -> V_91 = V_89 -> V_91 ;
V_33 -> V_98 = V_89 -> V_98 ;
V_33 -> V_99 = V_89 -> V_99 ;
V_33 -> V_96 = V_89 -> V_96 ;
V_33 -> V_92 = V_89 -> V_92 ;
if ( F_35 ( V_2 , V_33 ) == false ) {
F_45 ( V_33 ) ;
goto V_93;
}
if ( V_2 -> V_43 == NULL ) {
V_2 -> V_43 =
F_47 ( V_2 -> V_7 . V_67 , V_56 ) ;
if ( V_2 -> V_43 == NULL ) {
V_22 = - V_57 ;
goto V_93;
}
}
}
V_22 = F_51 ( V_2 , V_48 ) ;
if ( V_22 < 0 )
goto V_93;
F_52 ( V_2 , V_48 -> V_72 ) ;
V_49 = F_53 ( F_34 , sizeof( * V_49 ) , V_56 ) ;
if ( ! V_49 ) {
V_22 = - V_57 ;
goto V_100;
}
* V_49 = V_2 ;
F_54 ( V_6 , V_49 ) ;
return V_2 ;
V_100:
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
V_93:
F_40 ( V_2 ) ;
F_45 ( V_2 -> V_16 ) ;
V_81:
F_45 ( V_2 ) ;
V_55:
return F_57 ( V_22 ) ;
}
static void F_58 ( struct V_25 * V_6 , void * V_26 )
{
F_59 ( * (struct V_1 * * ) V_26 ) ;
}
struct V_1 * F_60 ( struct V_25 * V_6 ,
const struct V_44 * V_45 ,
void * V_46 ,
const struct V_47 * V_48 )
{
struct V_1 * * V_101 , * V_1 ;
V_101 = F_53 ( F_58 , sizeof( * V_101 ) , V_56 ) ;
if ( ! V_101 )
return F_57 ( - V_57 ) ;
V_1 = F_46 ( V_6 , V_45 , V_46 , V_48 ) ;
if ( ! F_61 ( V_1 ) ) {
* V_101 = V_1 ;
F_54 ( V_6 , V_101 ) ;
} else {
F_62 ( V_101 ) ;
}
return V_1 ;
}
int F_63 ( struct V_1 * V_2 , const struct V_47 * V_48 )
{
int V_22 ;
V_2 -> V_59 ( V_2 ) ;
F_56 ( V_2 ) ;
F_55 ( V_2 ) ;
V_2 -> V_4 = V_48 -> V_4 ;
V_2 -> V_5 = V_48 -> V_5 ;
V_2 -> V_9 = V_48 -> V_9 ;
V_2 -> V_10 = V_48 -> V_10 ;
V_2 -> V_11 = V_48 -> V_11 ;
V_2 -> V_71 = V_48 -> V_71 ;
F_52 ( V_2 , V_48 -> V_72 ) ;
V_2 -> V_102 = false ;
V_2 -> V_103 = false ;
V_22 = F_51 ( V_2 , V_48 ) ;
V_2 -> V_60 ( V_2 ) ;
return V_22 ;
}
void F_59 ( struct V_1 * V_2 )
{
F_56 ( V_2 ) ;
F_55 ( V_2 ) ;
F_40 ( V_2 ) ;
if ( V_2 -> V_45 -> V_104 )
V_2 -> V_45 -> V_104 ( V_2 -> V_46 ) ;
F_45 ( V_2 -> V_16 ) ;
F_45 ( V_2 ) ;
}
static int F_64 ( struct V_25 * V_6 , void * V_26 , void * V_28 )
{
struct V_1 * * V_105 = V_26 ;
if ( ! V_105 || ! * V_105 ) {
F_65 ( ! V_105 || ! * V_105 ) ;
return 0 ;
}
if ( V_28 )
return ( * V_105 ) -> V_72 == V_28 ;
else
return 1 ;
}
struct V_1 * F_66 ( struct V_25 * V_6 , const char * V_72 )
{
struct V_1 * * V_105 = F_67 ( V_6 , F_34 ,
F_64 , ( void * ) V_72 ) ;
if ( ! V_105 )
return NULL ;
return * V_105 ;
}
static int F_68 ( struct V_1 * V_2 , unsigned int * V_3 ,
unsigned int V_106 )
{
struct V_27 * V_107 ;
void * V_108 ;
unsigned int V_109 ;
unsigned int V_110 ;
bool V_111 ;
int V_22 ;
V_107 = F_39 ( V_2 , * V_3 ) ;
if ( V_107 ) {
V_109 = ( * V_3 - V_107 -> V_38 ) % V_107 -> V_92 ;
V_110 = ( * V_3 - V_107 -> V_38 ) / V_107 -> V_92 ;
if ( V_106 > 1 ) {
if ( * V_3 + V_106 - 1 > V_107 -> V_37 )
return - V_50 ;
if ( V_106 > V_107 -> V_92 - V_109 )
return - V_50 ;
}
if ( V_106 > 1 ||
V_107 -> V_96 + V_109 != V_107 -> V_91 ) {
V_108 = V_2 -> V_16 ;
V_2 -> V_16 = V_2 -> V_43 ;
V_22 = F_69 ( V_2 , V_107 -> V_91 ,
V_107 -> V_98 ,
V_110 << V_107 -> V_99 ,
& V_111 ) ;
V_2 -> V_16 = V_108 ;
if ( V_22 < 0 )
return V_22 ;
}
* V_3 = V_107 -> V_96 + V_109 ;
}
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , unsigned int V_3 ,
const void * V_14 , T_4 V_112 )
{
T_1 * T_1 = V_2 -> V_16 ;
void * V_17 ;
int V_22 = - V_113 ;
T_4 V_114 ;
int V_13 ;
if ( V_2 -> V_5 )
for ( V_13 = 0 ; V_13 < V_112 / V_2 -> V_7 . V_65 ; V_13 ++ )
if ( ! V_2 -> V_5 ( V_2 -> V_6 ,
V_3 + ( V_13 * V_2 -> V_69 ) ) )
return - V_50 ;
if ( ! V_2 -> V_102 && V_2 -> V_7 . V_85 ) {
unsigned int V_115 ;
int V_65 = V_2 -> V_7 . V_65 ;
for ( V_13 = 0 ; V_13 < V_112 / V_65 ; V_13 ++ ) {
memcpy ( V_2 -> V_16 , V_14 + ( V_13 * V_65 ) , V_65 ) ;
V_115 = V_2 -> V_7 . V_85 ( V_2 -> V_16 ) ;
V_22 = F_71 ( V_2 , V_3 + ( V_13 * V_2 -> V_69 ) ,
V_115 ) ;
if ( V_22 ) {
F_72 ( V_2 -> V_6 ,
L_1 ,
V_3 + V_13 , V_22 ) ;
return V_22 ;
}
}
if ( V_2 -> V_103 ) {
V_2 -> V_116 = true ;
return 0 ;
}
}
V_22 = F_68 ( V_2 , & V_3 , V_112 / V_2 -> V_7 . V_65 ) ;
if ( V_22 < 0 )
return V_22 ;
V_2 -> V_7 . V_82 ( V_2 -> V_16 , V_3 , V_2 -> V_68 ) ;
T_1 [ 0 ] |= V_2 -> V_74 ;
F_73 ( V_2 -> V_6 , V_3 ,
V_112 / V_2 -> V_7 . V_65 ) ;
if ( V_14 == ( V_2 -> V_16 + V_2 -> V_7 . V_63 +
V_2 -> V_7 . V_61 ) )
V_22 = V_2 -> V_45 -> V_117 ( V_2 -> V_46 , V_2 -> V_16 ,
V_2 -> V_7 . V_61 +
V_2 -> V_7 . V_63 +
V_112 ) ;
else if ( V_2 -> V_45 -> V_118 )
V_22 = V_2 -> V_45 -> V_118 ( V_2 -> V_46 , V_2 -> V_16 ,
V_2 -> V_7 . V_61 +
V_2 -> V_7 . V_63 ,
V_14 , V_112 ) ;
if ( V_22 == - V_113 ) {
V_114 = V_2 -> V_7 . V_61 + V_2 -> V_7 . V_63 + V_112 ;
V_17 = F_47 ( V_114 , V_56 ) ;
if ( ! V_17 )
return - V_57 ;
memcpy ( V_17 , V_2 -> V_16 , V_2 -> V_7 . V_61 ) ;
memcpy ( V_17 + V_2 -> V_7 . V_61 + V_2 -> V_7 . V_63 ,
V_14 , V_112 ) ;
V_22 = V_2 -> V_45 -> V_117 ( V_2 -> V_46 , V_17 , V_114 ) ;
F_45 ( V_17 ) ;
}
F_74 ( V_2 -> V_6 , V_3 ,
V_112 / V_2 -> V_7 . V_65 ) ;
return V_22 ;
}
int F_75 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_14 )
{
int V_22 ;
F_76 ( ! V_2 -> V_7 . V_8 && ! V_2 -> V_7 . V_84 ) ;
if ( ! V_2 -> V_102 && V_2 -> V_7 . V_8 ) {
V_22 = F_71 ( V_2 , V_3 , V_14 ) ;
if ( V_22 != 0 )
return V_22 ;
if ( V_2 -> V_103 ) {
V_2 -> V_116 = true ;
return 0 ;
}
}
#ifdef F_77
if ( strcmp ( F_78 ( V_2 -> V_6 ) , F_77 ) == 0 )
F_79 ( V_2 -> V_6 , L_2 , V_3 , V_14 ) ;
#endif
F_80 ( V_2 -> V_6 , V_3 , V_14 ) ;
if ( V_2 -> V_7 . V_8 ) {
V_22 = F_68 ( V_2 , & V_3 , 1 ) ;
if ( V_22 < 0 )
return V_22 ;
V_2 -> V_7 . V_8 ( V_2 , V_3 , V_14 ) ;
F_73 ( V_2 -> V_6 , V_3 , 1 ) ;
V_22 = V_2 -> V_45 -> V_117 ( V_2 -> V_46 , V_2 -> V_16 ,
V_2 -> V_7 . V_67 ) ;
F_74 ( V_2 -> V_6 , V_3 , 1 ) ;
return V_22 ;
} else {
V_2 -> V_7 . V_84 ( V_2 -> V_16 + V_2 -> V_7 . V_61
+ V_2 -> V_7 . V_63 , V_14 , 0 ) ;
return F_70 ( V_2 , V_3 ,
V_2 -> V_16 +
V_2 -> V_7 . V_61 +
V_2 -> V_7 . V_63 ,
V_2 -> V_7 . V_65 ) ;
}
}
int F_81 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int V_14 )
{
int V_22 ;
if ( V_3 % V_2 -> V_69 )
return - V_50 ;
V_2 -> V_59 ( V_2 ) ;
V_22 = F_75 ( V_2 , V_3 , V_14 ) ;
V_2 -> V_60 ( V_2 ) ;
return V_22 ;
}
int F_82 ( struct V_1 * V_2 , unsigned int V_3 ,
const void * V_14 , T_4 V_112 )
{
int V_22 ;
if ( V_112 % V_2 -> V_7 . V_65 )
return - V_50 ;
if ( V_3 % V_2 -> V_69 )
return - V_50 ;
V_2 -> V_59 ( V_2 ) ;
V_22 = F_70 ( V_2 , V_3 , V_14 , V_112 ) ;
V_2 -> V_60 ( V_2 ) ;
return V_22 ;
}
int F_83 ( struct V_1 * V_2 , unsigned int V_3 , const void * V_14 ,
T_4 V_119 )
{
int V_22 = 0 , V_13 ;
T_4 V_65 = V_2 -> V_7 . V_65 ;
void * V_120 ;
if ( ! V_2 -> V_7 . V_85 )
return - V_50 ;
if ( V_3 % V_2 -> V_69 )
return - V_50 ;
V_2 -> V_59 ( V_2 ) ;
if ( V_65 == 1 ) {
V_120 = ( void * ) V_14 ;
} else {
V_120 = F_84 ( V_14 , V_119 * V_65 , V_56 ) ;
if ( ! V_120 ) {
V_22 = - V_57 ;
F_72 ( V_2 -> V_6 , L_3 ) ;
goto V_15;
}
for ( V_13 = 0 ; V_13 < V_119 * V_65 ; V_13 += V_65 )
V_2 -> V_7 . V_85 ( V_120 + V_13 ) ;
}
if ( V_2 -> V_70 ) {
for ( V_13 = 0 ; V_13 < V_119 ; V_13 ++ ) {
V_22 = F_82 ( V_2 ,
V_3 + ( V_13 * V_2 -> V_69 ) ,
V_14 + ( V_13 * V_65 ) ,
V_65 ) ;
if ( V_22 != 0 )
return V_22 ;
}
} else {
V_22 = F_70 ( V_2 , V_3 , V_120 , V_65 * V_119 ) ;
}
if ( V_65 != 1 )
F_45 ( V_120 ) ;
V_15:
V_2 -> V_60 ( V_2 ) ;
return V_22 ;
}
static int F_85 ( struct V_1 * V_2 , unsigned int V_3 , void * V_14 ,
unsigned int V_112 )
{
T_1 * T_1 = V_2 -> V_16 ;
int V_22 ;
V_22 = F_68 ( V_2 , & V_3 , V_112 / V_2 -> V_7 . V_65 ) ;
if ( V_22 < 0 )
return V_22 ;
V_2 -> V_7 . V_82 ( V_2 -> V_16 , V_3 , V_2 -> V_68 ) ;
T_1 [ 0 ] |= V_2 -> V_73 ;
F_86 ( V_2 -> V_6 , V_3 ,
V_112 / V_2 -> V_7 . V_65 ) ;
V_22 = V_2 -> V_45 -> V_121 ( V_2 -> V_46 , V_2 -> V_16 ,
V_2 -> V_7 . V_61 + V_2 -> V_7 . V_63 ,
V_14 , V_112 ) ;
F_87 ( V_2 -> V_6 , V_3 ,
V_112 / V_2 -> V_7 . V_65 ) ;
return V_22 ;
}
static int F_88 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int * V_14 )
{
int V_22 ;
if ( ! V_2 -> V_102 ) {
V_22 = F_89 ( V_2 , V_3 , V_14 ) ;
if ( V_22 == 0 )
return 0 ;
}
if ( ! V_2 -> V_7 . V_85 )
return - V_50 ;
if ( V_2 -> V_103 )
return - V_122 ;
V_22 = F_85 ( V_2 , V_3 , V_2 -> V_16 , V_2 -> V_7 . V_65 ) ;
if ( V_22 == 0 ) {
* V_14 = V_2 -> V_7 . V_85 ( V_2 -> V_16 ) ;
#ifdef F_77
if ( strcmp ( F_78 ( V_2 -> V_6 ) , F_77 ) == 0 )
F_79 ( V_2 -> V_6 , L_4 , V_3 , * V_14 ) ;
#endif
F_90 ( V_2 -> V_6 , V_3 , * V_14 ) ;
}
if ( V_22 == 0 && ! V_2 -> V_102 )
F_71 ( V_2 , V_3 , * V_14 ) ;
return V_22 ;
}
int F_91 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int * V_14 )
{
int V_22 ;
if ( V_3 % V_2 -> V_69 )
return - V_50 ;
V_2 -> V_59 ( V_2 ) ;
V_22 = F_88 ( V_2 , V_3 , V_14 ) ;
V_2 -> V_60 ( V_2 ) ;
return V_22 ;
}
int F_92 ( struct V_1 * V_2 , unsigned int V_3 , void * V_14 ,
T_4 V_112 )
{
T_4 V_65 = V_2 -> V_7 . V_65 ;
T_4 V_119 = V_112 / V_65 ;
unsigned int V_123 ;
int V_22 , V_13 ;
if ( V_112 % V_2 -> V_7 . V_65 )
return - V_50 ;
if ( V_3 % V_2 -> V_69 )
return - V_50 ;
V_2 -> V_59 ( V_2 ) ;
if ( F_5 ( V_2 , V_3 , V_119 ) || V_2 -> V_102 ||
V_2 -> V_71 == V_124 ) {
V_22 = F_85 ( V_2 , V_3 , V_14 , V_112 ) ;
} else {
for ( V_13 = 0 ; V_13 < V_119 ; V_13 ++ ) {
V_22 = F_88 ( V_2 , V_3 + ( V_13 * V_2 -> V_69 ) ,
& V_123 ) ;
if ( V_22 != 0 )
goto V_15;
V_2 -> V_7 . V_84 ( V_14 + ( V_13 * V_65 ) , V_123 , 0 ) ;
}
}
V_15:
V_2 -> V_60 ( V_2 ) ;
return V_22 ;
}
int F_93 ( struct V_1 * V_2 , unsigned int V_3 , void * V_14 ,
T_4 V_119 )
{
int V_22 , V_13 ;
T_4 V_65 = V_2 -> V_7 . V_65 ;
bool V_125 = F_5 ( V_2 , V_3 , V_119 ) ;
if ( ! V_2 -> V_7 . V_85 )
return - V_50 ;
if ( V_3 % V_2 -> V_69 )
return - V_50 ;
if ( V_125 || V_2 -> V_71 == V_124 ) {
if ( V_2 -> V_70 ) {
for ( V_13 = 0 ; V_13 < V_119 ; V_13 ++ ) {
V_22 = F_92 ( V_2 ,
V_3 + ( V_13 * V_2 -> V_69 ) ,
V_14 + ( V_13 * V_65 ) ,
V_65 ) ;
if ( V_22 != 0 )
return V_22 ;
}
} else {
V_22 = F_92 ( V_2 , V_3 , V_14 ,
V_65 * V_119 ) ;
if ( V_22 != 0 )
return V_22 ;
}
for ( V_13 = 0 ; V_13 < V_119 * V_65 ; V_13 += V_65 )
V_2 -> V_7 . V_85 ( V_14 + V_13 ) ;
} else {
for ( V_13 = 0 ; V_13 < V_119 ; V_13 ++ ) {
unsigned int V_115 ;
V_22 = F_91 ( V_2 , V_3 + ( V_13 * V_2 -> V_69 ) ,
& V_115 ) ;
if ( V_22 != 0 )
return V_22 ;
memcpy ( V_14 + ( V_13 * V_65 ) , & V_115 , V_65 ) ;
}
}
return 0 ;
}
static int F_69 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_126 , unsigned int V_14 ,
bool * V_127 )
{
int V_22 ;
unsigned int V_128 , V_129 ;
V_22 = F_88 ( V_2 , V_3 , & V_129 ) ;
if ( V_22 != 0 )
return V_22 ;
V_128 = V_129 & ~ V_126 ;
V_128 |= V_14 & V_126 ;
if ( V_128 != V_129 ) {
V_22 = F_75 ( V_2 , V_3 , V_128 ) ;
* V_127 = true ;
} else {
* V_127 = false ;
}
return V_22 ;
}
int F_94 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_126 , unsigned int V_14 )
{
bool V_127 ;
int V_22 ;
V_2 -> V_59 ( V_2 ) ;
V_22 = F_69 ( V_2 , V_3 , V_126 , V_14 , & V_127 ) ;
V_2 -> V_60 ( V_2 ) ;
return V_22 ;
}
int F_95 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_126 , unsigned int V_14 ,
bool * V_127 )
{
int V_22 ;
V_2 -> V_59 ( V_2 ) ;
V_22 = F_69 ( V_2 , V_3 , V_126 , V_14 , V_127 ) ;
V_2 -> V_60 ( V_2 ) ;
return V_22 ;
}
int F_96 ( struct V_1 * V_2 , const struct V_130 * V_131 ,
int V_132 )
{
int V_13 , V_22 ;
bool V_133 ;
if ( V_2 -> V_134 )
return - V_122 ;
V_2 -> V_59 ( V_2 ) ;
V_133 = V_2 -> V_102 ;
V_2 -> V_102 = true ;
for ( V_13 = 0 ; V_13 < V_132 ; V_13 ++ ) {
V_22 = F_75 ( V_2 , V_131 [ V_13 ] . V_3 , V_131 [ V_13 ] . V_135 ) ;
if ( V_22 != 0 ) {
F_72 ( V_2 -> V_6 , L_5 ,
V_131 [ V_13 ] . V_3 , V_131 [ V_13 ] . V_135 , V_22 ) ;
goto V_15;
}
}
V_2 -> V_134 = F_97 ( V_132 , sizeof( struct V_130 ) , V_56 ) ;
if ( V_2 -> V_134 != NULL ) {
memcpy ( V_2 -> V_134 , V_131 ,
V_132 * sizeof( struct V_130 ) ) ;
V_2 -> V_136 = V_132 ;
} else {
V_22 = - V_57 ;
}
V_15:
V_2 -> V_102 = V_133 ;
V_2 -> V_60 ( V_2 ) ;
return V_22 ;
}
int F_98 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 . V_8 )
return - V_50 ;
return V_2 -> V_7 . V_65 ;
}
static int T_5 F_99 ( void )
{
F_100 () ;
return 0 ;
}
