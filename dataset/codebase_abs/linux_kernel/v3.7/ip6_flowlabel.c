static inline struct V_1 * F_1 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_1 * V_4 ;
for ( V_4 = V_5 [ F_2 ( V_3 ) ] ; V_4 ; V_4 = V_4 -> V_6 ) {
if ( V_4 -> V_3 == V_3 && F_3 ( V_4 -> V_7 , V_2 ) )
return V_4 ;
}
return NULL ;
}
static struct V_1 * F_4 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_1 * V_4 ;
F_5 ( & V_8 ) ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 )
F_6 ( & V_4 -> V_9 ) ;
F_7 ( & V_8 ) ;
return V_4 ;
}
static void F_8 ( struct V_1 * V_4 )
{
if ( V_4 ) {
if ( V_4 -> V_10 == V_11 )
F_9 ( V_4 -> V_12 . V_13 ) ;
F_10 ( V_4 -> V_7 ) ;
F_11 ( V_4 -> V_14 ) ;
}
F_11 ( V_4 ) ;
}
static void F_12 ( struct V_1 * V_4 )
{
F_13 ( & V_8 ) ;
V_4 -> V_15 = V_16 ;
if ( F_14 ( & V_4 -> V_9 ) ) {
unsigned long V_17 = V_4 -> V_15 + V_4 -> V_18 ;
if ( F_15 ( V_17 , V_4 -> V_19 ) )
V_4 -> V_19 = V_17 ;
V_17 = V_4 -> V_19 ;
if ( V_4 -> V_14 && V_4 -> V_10 == V_20 ) {
struct V_21 * V_14 = V_4 -> V_14 ;
V_4 -> V_14 = NULL ;
F_11 ( V_14 ) ;
}
if ( ! F_16 ( & V_22 ) ||
F_15 ( V_22 . V_19 , V_17 ) )
F_17 ( & V_22 , V_17 ) ;
}
F_18 ( & V_8 ) ;
}
static void F_19 ( unsigned long V_23 )
{
int V_24 ;
unsigned long V_25 = V_16 ;
unsigned long V_26 = 0 ;
F_20 ( & V_8 ) ;
for ( V_24 = 0 ; V_24 <= V_27 ; V_24 ++ ) {
struct V_1 * V_4 , * * V_28 ;
V_28 = & V_5 [ V_24 ] ;
while ( ( V_4 = * V_28 ) != NULL ) {
if ( F_21 ( & V_4 -> V_9 ) == 0 ) {
unsigned long V_17 = V_4 -> V_15 + V_4 -> V_18 ;
if ( F_15 ( V_17 , V_4 -> V_19 ) )
V_4 -> V_19 = V_17 ;
V_17 = V_4 -> V_19 ;
if ( F_22 ( V_25 , V_17 ) ) {
* V_28 = V_4 -> V_6 ;
F_8 ( V_4 ) ;
F_23 ( & V_29 ) ;
continue;
}
if ( ! V_26 || F_24 ( V_17 , V_26 ) )
V_26 = V_17 ;
}
V_28 = & V_4 -> V_6 ;
}
}
if ( ! V_26 && F_21 ( & V_29 ) )
V_26 = V_25 + V_30 ;
if ( V_26 ) {
F_17 ( & V_22 , V_26 ) ;
}
F_25 ( & V_8 ) ;
}
static void T_2 F_26 ( struct V_2 * V_2 )
{
int V_24 ;
F_20 ( & V_8 ) ;
for ( V_24 = 0 ; V_24 <= V_27 ; V_24 ++ ) {
struct V_1 * V_4 , * * V_28 ;
V_28 = & V_5 [ V_24 ] ;
while ( ( V_4 = * V_28 ) != NULL ) {
if ( F_3 ( V_4 -> V_7 , V_2 ) &&
F_21 ( & V_4 -> V_9 ) == 0 ) {
* V_28 = V_4 -> V_6 ;
F_8 ( V_4 ) ;
F_23 ( & V_29 ) ;
continue;
}
V_28 = & V_4 -> V_6 ;
}
}
F_25 ( & V_8 ) ;
}
static struct V_1 * F_27 ( struct V_2 * V_2 ,
struct V_1 * V_4 , T_1 V_3 )
{
struct V_1 * V_31 ;
V_4 -> V_3 = V_3 & V_32 ;
F_13 ( & V_8 ) ;
if ( V_3 == 0 ) {
for (; ; ) {
V_4 -> V_3 = F_28 ( F_29 () ) & V_32 ;
if ( V_4 -> V_3 ) {
V_31 = F_1 ( V_2 , V_4 -> V_3 ) ;
if ( V_31 == NULL )
break;
}
}
} else {
V_31 = F_1 ( V_2 , V_4 -> V_3 ) ;
if ( V_31 != NULL ) {
F_6 ( & V_31 -> V_9 ) ;
F_18 ( & V_8 ) ;
return V_31 ;
}
}
V_4 -> V_15 = V_16 ;
V_4 -> V_6 = V_5 [ F_2 ( V_4 -> V_3 ) ] ;
V_5 [ F_2 ( V_4 -> V_3 ) ] = V_4 ;
F_6 ( & V_29 ) ;
F_18 ( & V_8 ) ;
return NULL ;
}
struct V_1 * F_30 ( struct V_33 * V_34 , T_1 V_3 )
{
struct V_35 * V_36 ;
struct V_37 * V_38 = F_31 ( V_34 ) ;
V_3 &= V_32 ;
F_5 ( & V_39 ) ;
for ( V_36 = V_38 -> V_40 ; V_36 ; V_36 = V_36 -> V_6 ) {
struct V_1 * V_4 = V_36 -> V_4 ;
if ( V_4 -> V_3 == V_3 ) {
V_4 -> V_15 = V_16 ;
F_6 ( & V_4 -> V_9 ) ;
F_7 ( & V_39 ) ;
return V_4 ;
}
}
F_7 ( & V_39 ) ;
return NULL ;
}
void F_32 ( struct V_33 * V_34 )
{
struct V_37 * V_38 = F_31 ( V_34 ) ;
struct V_35 * V_36 ;
while ( ( V_36 = V_38 -> V_40 ) != NULL ) {
V_38 -> V_40 = V_36 -> V_6 ;
F_12 ( V_36 -> V_4 ) ;
F_11 ( V_36 ) ;
}
}
struct V_21 * F_33 ( struct V_21 * V_41 ,
struct V_1 * V_4 ,
struct V_21 * V_42 )
{
struct V_21 * V_43 = V_4 -> V_14 ;
if ( V_42 == NULL || V_42 -> V_44 == 0 )
return V_43 ;
if ( V_43 != NULL ) {
V_41 -> V_45 = V_43 -> V_45 ;
V_41 -> V_46 = V_43 -> V_46 ;
V_41 -> V_47 = V_43 -> V_47 ;
V_41 -> V_48 = V_43 -> V_48 ;
} else {
if ( V_42 -> V_48 == 0 )
return V_42 ;
V_41 -> V_45 = NULL ;
V_41 -> V_46 = NULL ;
V_41 -> V_47 = NULL ;
V_41 -> V_48 = 0 ;
}
V_41 -> V_49 = V_42 -> V_49 ;
V_41 -> V_44 = V_42 -> V_44 ;
return V_41 ;
}
static unsigned long F_34 ( unsigned long V_50 )
{
if ( V_50 < V_51 )
return V_51 * V_52 ;
if ( V_50 > V_30 && ! F_35 ( V_53 ) )
return 0 ;
return V_50 * V_52 ;
}
static int F_36 ( struct V_1 * V_4 , unsigned long V_18 , unsigned long V_19 )
{
V_18 = F_34 ( V_18 ) ;
if ( ! V_18 )
return - V_54 ;
V_19 = F_34 ( V_19 ) ;
if ( ! V_19 )
return - V_54 ;
V_4 -> V_15 = V_16 ;
if ( F_24 ( V_4 -> V_18 , V_18 ) )
V_4 -> V_18 = V_18 ;
if ( F_24 ( V_19 , V_4 -> V_18 ) )
V_19 = V_4 -> V_18 ;
if ( F_24 ( V_4 -> V_19 , V_4 -> V_15 + V_19 ) )
V_4 -> V_19 = V_4 -> V_15 + V_19 ;
return 0 ;
}
static struct V_1 *
F_37 ( struct V_2 * V_2 , struct V_33 * V_34 , struct V_55 * V_56 ,
char T_3 * V_57 , int V_58 , int * V_59 )
{
struct V_1 * V_4 = NULL ;
int V_60 ;
int V_61 ;
int V_62 ;
V_60 = V_58 - F_38 ( sizeof( * V_56 ) ) ;
V_62 = - V_63 ;
if ( V_60 > 64 * 1024 )
goto V_64;
V_62 = - V_65 ;
V_4 = F_39 ( sizeof( * V_4 ) , V_66 ) ;
if ( V_4 == NULL )
goto V_64;
if ( V_60 > 0 ) {
struct V_67 V_68 ;
struct V_69 V_69 ;
int V_70 ;
V_62 = - V_65 ;
V_4 -> V_14 = F_40 ( sizeof( * V_4 -> V_14 ) + V_60 , V_66 ) ;
if ( V_4 -> V_14 == NULL )
goto V_64;
memset ( V_4 -> V_14 , 0 , sizeof( * V_4 -> V_14 ) ) ;
V_4 -> V_14 -> V_71 = sizeof( * V_4 -> V_14 ) + V_60 ;
V_62 = - V_72 ;
if ( F_41 ( V_4 -> V_14 + 1 , V_57 + F_38 ( sizeof( * V_56 ) ) , V_60 ) )
goto V_64;
V_68 . V_73 = V_60 ;
V_68 . V_74 = ( void * ) ( V_4 -> V_14 + 1 ) ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_62 = F_42 ( V_2 , V_34 , & V_68 , & V_69 , V_4 -> V_14 , & V_70 ,
& V_70 , & V_70 ) ;
if ( V_62 )
goto V_64;
V_62 = - V_63 ;
if ( V_4 -> V_14 -> V_44 )
goto V_64;
if ( V_4 -> V_14 -> V_48 == 0 ) {
F_11 ( V_4 -> V_14 ) ;
V_4 -> V_14 = NULL ;
}
}
V_4 -> V_7 = F_43 ( V_2 ) ;
V_4 -> V_19 = V_16 ;
V_62 = F_36 ( V_4 , V_56 -> V_75 , V_56 -> V_76 ) ;
if ( V_62 )
goto V_64;
V_4 -> V_10 = V_56 -> V_77 ;
V_61 = F_44 ( & V_56 -> V_78 ) ;
if ( ( V_61 & V_79 ) ||
V_61 == V_80 ) {
V_62 = - V_63 ;
goto V_64;
}
V_4 -> V_81 = V_56 -> V_78 ;
F_45 ( & V_4 -> V_9 , 1 ) ;
switch ( V_4 -> V_10 ) {
case V_20 :
case V_82 :
break;
case V_11 :
V_4 -> V_12 . V_13 = F_46 ( V_83 , V_84 ) ;
break;
case V_85 :
V_4 -> V_12 . V_86 = F_47 () ;
break;
default:
V_62 = - V_63 ;
goto V_64;
}
return V_4 ;
V_64:
F_8 ( V_4 ) ;
* V_59 = V_62 ;
return NULL ;
}
static int F_48 ( struct V_33 * V_34 )
{
struct V_37 * V_38 = F_31 ( V_34 ) ;
struct V_35 * V_36 ;
int V_87 = V_88 - F_21 ( & V_29 ) ;
int V_89 = 0 ;
if ( V_87 > V_88 - V_90 )
return 0 ;
for ( V_36 = V_38 -> V_40 ; V_36 ; V_36 = V_36 -> V_6 )
V_89 ++ ;
if ( V_87 <= 0 ||
( ( V_89 >= V_90 ||
( V_89 > 0 && V_87 < V_88 / 2 ) || V_87 < V_88 / 4 ) &&
! F_35 ( V_53 ) ) )
return - V_91 ;
return 0 ;
}
static bool F_49 ( struct V_92 * V_93 , struct V_92 * V_94 )
{
if ( V_93 == V_94 )
return false ;
if ( V_93 == NULL || V_94 == NULL )
return true ;
if ( V_93 -> V_95 != V_94 -> V_95 )
return true ;
return memcmp ( V_93 + 1 , V_94 + 1 , ( ( V_93 -> V_95 + 1 ) << 3 ) - sizeof( * V_93 ) ) ;
}
static bool F_50 ( struct V_21 * V_96 , struct V_21 * V_97 )
{
if ( V_96 == V_97 )
return false ;
if ( V_96 == NULL || V_97 == NULL )
return true ;
if ( V_96 -> V_48 != V_97 -> V_48 )
return true ;
if ( F_49 ( V_96 -> V_45 , V_97 -> V_45 ) )
return true ;
if ( F_49 ( V_96 -> V_46 , V_97 -> V_46 ) )
return true ;
if ( F_49 ( (struct V_92 * ) V_96 -> V_47 , (struct V_92 * ) V_97 -> V_47 ) )
return true ;
return false ;
}
static inline void F_51 ( struct V_37 * V_38 , struct V_35 * V_36 ,
struct V_1 * V_4 )
{
F_13 ( & V_39 ) ;
V_36 -> V_4 = V_4 ;
V_36 -> V_6 = V_38 -> V_40 ;
V_38 -> V_40 = V_36 ;
F_18 ( & V_39 ) ;
}
int F_52 ( struct V_33 * V_34 , char T_3 * V_57 , int V_58 )
{
int V_98 ( V_62 ) ;
struct V_2 * V_2 = F_53 ( V_34 ) ;
struct V_37 * V_38 = F_31 ( V_34 ) ;
struct V_55 V_56 ;
struct V_35 * V_99 = NULL ;
struct V_35 * V_36 , * * V_100 ;
struct V_1 * V_4 , * V_101 = NULL ;
if ( V_58 < sizeof( V_56 ) )
return - V_63 ;
if ( F_41 ( & V_56 , V_57 , sizeof( V_56 ) ) )
return - V_72 ;
switch ( V_56 . V_102 ) {
case V_103 :
F_13 ( & V_39 ) ;
for ( V_100 = & V_38 -> V_40 ; ( V_36 = * V_100 ) != NULL ; V_100 = & V_36 -> V_6 ) {
if ( V_36 -> V_4 -> V_3 == V_56 . V_104 ) {
if ( V_56 . V_104 == ( V_38 -> V_105 & V_32 ) )
V_38 -> V_105 &= ~ V_32 ;
* V_100 = V_36 -> V_6 ;
F_18 ( & V_39 ) ;
F_12 ( V_36 -> V_4 ) ;
F_11 ( V_36 ) ;
return 0 ;
}
}
F_18 ( & V_39 ) ;
return - V_106 ;
case V_107 :
F_5 ( & V_39 ) ;
for ( V_36 = V_38 -> V_40 ; V_36 ; V_36 = V_36 -> V_6 ) {
if ( V_36 -> V_4 -> V_3 == V_56 . V_104 ) {
V_62 = F_36 ( V_36 -> V_4 , V_56 . V_75 , V_56 . V_76 ) ;
F_7 ( & V_39 ) ;
return V_62 ;
}
}
F_7 ( & V_39 ) ;
if ( V_56 . V_77 == V_108 && F_35 ( V_53 ) ) {
V_4 = F_4 ( V_2 , V_56 . V_104 ) ;
if ( V_4 ) {
V_62 = F_36 ( V_4 , V_56 . V_75 , V_56 . V_76 ) ;
F_12 ( V_4 ) ;
return V_62 ;
}
}
return - V_106 ;
case V_109 :
if ( V_56 . V_104 & ~ V_32 )
return - V_63 ;
V_4 = F_37 ( V_2 , V_34 , & V_56 , V_57 , V_58 , & V_62 ) ;
if ( V_4 == NULL )
return V_62 ;
V_99 = F_40 ( sizeof( * V_99 ) , V_66 ) ;
if ( V_56 . V_104 ) {
V_62 = - V_110 ;
F_5 ( & V_39 ) ;
for ( V_36 = V_38 -> V_40 ; V_36 ; V_36 = V_36 -> V_6 ) {
if ( V_36 -> V_4 -> V_3 == V_56 . V_104 ) {
if ( V_56 . V_111 & V_112 ) {
F_7 ( & V_39 ) ;
goto V_64;
}
V_101 = V_36 -> V_4 ;
F_6 ( & V_101 -> V_9 ) ;
break;
}
}
F_7 ( & V_39 ) ;
if ( V_101 == NULL )
V_101 = F_4 ( V_2 , V_56 . V_104 ) ;
if ( V_101 ) {
V_113:
V_62 = - V_110 ;
if ( V_56 . V_111 & V_112 )
goto V_114;
V_62 = - V_54 ;
if ( V_101 -> V_10 == V_20 ||
V_101 -> V_10 != V_4 -> V_10 ||
( ( V_101 -> V_10 == V_11 ) &&
( V_101 -> V_12 . V_13 == V_4 -> V_12 . V_13 ) ) ||
( ( V_101 -> V_10 == V_85 ) &&
F_54 ( V_101 -> V_12 . V_86 , V_4 -> V_12 . V_86 ) ) )
goto V_114;
V_62 = - V_63 ;
if ( ! F_55 ( & V_101 -> V_81 , & V_4 -> V_81 ) ||
F_50 ( V_101 -> V_14 , V_4 -> V_14 ) )
goto V_114;
V_62 = - V_65 ;
if ( V_99 == NULL )
goto V_114;
if ( V_4 -> V_18 > V_101 -> V_18 )
V_101 -> V_18 = V_4 -> V_18 ;
if ( ( long ) ( V_4 -> V_19 - V_101 -> V_19 ) > 0 )
V_101 -> V_19 = V_4 -> V_19 ;
F_51 ( V_38 , V_99 , V_101 ) ;
F_8 ( V_4 ) ;
return 0 ;
V_114:
F_12 ( V_101 ) ;
goto V_64;
}
}
V_62 = - V_115 ;
if ( ! ( V_56 . V_111 & V_116 ) )
goto V_64;
V_62 = - V_65 ;
if ( V_99 == NULL || ( V_62 = F_48 ( V_34 ) ) != 0 )
goto V_64;
V_101 = F_27 ( V_2 , V_4 , V_56 . V_104 ) ;
if ( V_101 != NULL )
goto V_113;
if ( ! V_56 . V_104 ) {
if ( F_56 ( & ( (struct V_55 T_3 * ) V_57 ) -> V_104 ,
& V_4 -> V_3 , sizeof( V_4 -> V_3 ) ) ) {
}
}
F_51 ( V_38 , V_99 , V_4 ) ;
return 0 ;
default:
return - V_63 ;
}
V_64:
F_8 ( V_4 ) ;
F_11 ( V_99 ) ;
return V_62 ;
}
static struct V_1 * F_57 ( struct V_117 * V_118 )
{
struct V_1 * V_4 = NULL ;
struct V_119 * V_120 = F_58 ( V_118 ) ;
struct V_2 * V_2 = F_59 ( V_118 ) ;
for ( V_120 -> V_121 = 0 ; V_120 -> V_121 <= V_27 ; ++ V_120 -> V_121 ) {
V_4 = V_5 [ V_120 -> V_121 ] ;
while ( V_4 && ! F_3 ( V_4 -> V_7 , V_2 ) )
V_4 = V_4 -> V_6 ;
if ( V_4 )
break;
}
return V_4 ;
}
static struct V_1 * F_60 ( struct V_117 * V_118 , struct V_1 * V_4 )
{
struct V_119 * V_120 = F_58 ( V_118 ) ;
struct V_2 * V_2 = F_59 ( V_118 ) ;
V_4 = V_4 -> V_6 ;
V_122:
while ( V_4 && ! F_3 ( V_4 -> V_7 , V_2 ) )
V_4 = V_4 -> V_6 ;
while ( ! V_4 ) {
if ( ++ V_120 -> V_121 <= V_27 ) {
V_4 = V_5 [ V_120 -> V_121 ] ;
goto V_122;
} else
break;
}
return V_4 ;
}
static struct V_1 * F_61 ( struct V_117 * V_118 , T_4 V_123 )
{
struct V_1 * V_4 = F_57 ( V_118 ) ;
if ( V_4 )
while ( V_123 && ( V_4 = F_60 ( V_118 , V_4 ) ) != NULL )
-- V_123 ;
return V_123 ? NULL : V_4 ;
}
static void * F_62 ( struct V_117 * V_118 , T_4 * V_123 )
__acquires( V_8 )
{
F_5 ( & V_8 ) ;
return * V_123 ? F_61 ( V_118 , * V_123 - 1 ) : V_124 ;
}
static void * F_63 ( struct V_117 * V_118 , void * V_125 , T_4 * V_123 )
{
struct V_1 * V_4 ;
if ( V_125 == V_124 )
V_4 = F_57 ( V_118 ) ;
else
V_4 = F_60 ( V_118 , V_125 ) ;
++ * V_123 ;
return V_4 ;
}
static void F_64 ( struct V_117 * V_118 , void * V_125 )
__releases( V_8 )
{
F_7 ( & V_8 ) ;
}
static int F_65 ( struct V_117 * V_118 , void * V_125 )
{
struct V_119 * V_120 = F_58 ( V_118 ) ;
if ( V_125 == V_124 )
F_66 ( V_118 , L_1 ,
L_2 , L_3 , L_4 , L_5 , L_6 , L_7 , L_8 , L_9 ) ;
else {
struct V_1 * V_4 = V_125 ;
F_66 ( V_118 ,
L_10 ,
( unsigned int ) F_67 ( V_4 -> V_3 ) ,
V_4 -> V_10 ,
( ( V_4 -> V_10 == V_11 ) ?
F_68 ( V_4 -> V_12 . V_13 , V_120 -> V_126 ) :
( ( V_4 -> V_10 == V_85 ) ?
F_69 ( F_70 ( V_118 ) , V_4 -> V_12 . V_86 ) :
0 ) ) ,
F_21 ( & V_4 -> V_9 ) ,
V_4 -> V_18 / V_52 ,
( long ) ( V_4 -> V_19 - V_16 ) / V_52 ,
& V_4 -> V_81 ,
V_4 -> V_14 ? V_4 -> V_14 -> V_48 : 0 ) ;
}
return 0 ;
}
static int F_71 ( struct V_127 * V_127 , struct V_128 * V_128 )
{
struct V_117 * V_118 ;
struct V_119 * V_120 ;
int V_62 ;
V_62 = F_72 ( V_127 , V_128 , & V_129 ,
sizeof( struct V_119 ) ) ;
if ( ! V_62 ) {
V_118 = V_128 -> V_130 ;
V_120 = F_58 ( V_118 ) ;
F_73 () ;
V_120 -> V_126 = F_74 ( F_75 ( V_83 ) ) ;
F_76 () ;
}
return V_62 ;
}
static int F_77 ( struct V_127 * V_127 , struct V_128 * V_128 )
{
struct V_117 * V_118 = V_128 -> V_130 ;
struct V_119 * V_120 = F_58 ( V_118 ) ;
F_78 ( V_120 -> V_126 ) ;
return F_79 ( V_127 , V_128 ) ;
}
static int T_5 F_80 ( struct V_2 * V_2 )
{
if ( ! F_81 ( V_2 , L_11 ,
V_131 , & V_132 ) )
return - V_65 ;
return 0 ;
}
static void T_2 F_82 ( struct V_2 * V_2 )
{
F_83 ( V_2 , L_11 ) ;
}
static inline int F_80 ( struct V_2 * V_2 )
{
return 0 ;
}
static inline void F_82 ( struct V_2 * V_2 )
{
}
static void T_2 F_84 ( struct V_2 * V_2 )
{
F_26 ( V_2 ) ;
F_82 ( V_2 ) ;
}
int F_85 ( void )
{
return F_86 ( & V_133 ) ;
}
void F_87 ( void )
{
F_88 ( & V_22 ) ;
F_89 ( & V_133 ) ;
}
