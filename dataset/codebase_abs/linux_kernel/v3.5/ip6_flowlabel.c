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
F_9 ( V_4 -> V_7 ) ;
F_10 ( V_4 -> V_10 ) ;
}
F_10 ( V_4 ) ;
}
static void F_11 ( struct V_1 * V_4 )
{
F_12 ( & V_8 ) ;
V_4 -> V_11 = V_12 ;
if ( F_13 ( & V_4 -> V_9 ) ) {
unsigned long V_13 = V_4 -> V_11 + V_4 -> V_14 ;
if ( F_14 ( V_13 , V_4 -> V_15 ) )
V_4 -> V_15 = V_13 ;
V_13 = V_4 -> V_15 ;
if ( V_4 -> V_10 && V_4 -> V_16 == V_17 ) {
struct V_18 * V_10 = V_4 -> V_10 ;
V_4 -> V_10 = NULL ;
F_10 ( V_10 ) ;
}
if ( ! F_15 ( & V_19 ) ||
F_14 ( V_19 . V_15 , V_13 ) )
F_16 ( & V_19 , V_13 ) ;
}
F_17 ( & V_8 ) ;
}
static void F_18 ( unsigned long V_20 )
{
int V_21 ;
unsigned long V_22 = V_12 ;
unsigned long V_23 = 0 ;
F_19 ( & V_8 ) ;
for ( V_21 = 0 ; V_21 <= V_24 ; V_21 ++ ) {
struct V_1 * V_4 , * * V_25 ;
V_25 = & V_5 [ V_21 ] ;
while ( ( V_4 = * V_25 ) != NULL ) {
if ( F_20 ( & V_4 -> V_9 ) == 0 ) {
unsigned long V_13 = V_4 -> V_11 + V_4 -> V_14 ;
if ( F_14 ( V_13 , V_4 -> V_15 ) )
V_4 -> V_15 = V_13 ;
V_13 = V_4 -> V_15 ;
if ( F_21 ( V_22 , V_13 ) ) {
* V_25 = V_4 -> V_6 ;
F_8 ( V_4 ) ;
F_22 ( & V_26 ) ;
continue;
}
if ( ! V_23 || F_23 ( V_13 , V_23 ) )
V_23 = V_13 ;
}
V_25 = & V_4 -> V_6 ;
}
}
if ( ! V_23 && F_20 ( & V_26 ) )
V_23 = V_22 + V_27 ;
if ( V_23 ) {
F_16 ( & V_19 , V_23 ) ;
}
F_24 ( & V_8 ) ;
}
static void T_2 F_25 ( struct V_2 * V_2 )
{
int V_21 ;
F_19 ( & V_8 ) ;
for ( V_21 = 0 ; V_21 <= V_24 ; V_21 ++ ) {
struct V_1 * V_4 , * * V_25 ;
V_25 = & V_5 [ V_21 ] ;
while ( ( V_4 = * V_25 ) != NULL ) {
if ( F_3 ( V_4 -> V_7 , V_2 ) &&
F_20 ( & V_4 -> V_9 ) == 0 ) {
* V_25 = V_4 -> V_6 ;
F_8 ( V_4 ) ;
F_22 ( & V_26 ) ;
continue;
}
V_25 = & V_4 -> V_6 ;
}
}
F_24 ( & V_8 ) ;
}
static struct V_1 * F_26 ( struct V_2 * V_2 ,
struct V_1 * V_4 , T_1 V_3 )
{
struct V_1 * V_28 ;
V_4 -> V_3 = V_3 & V_29 ;
F_12 ( & V_8 ) ;
if ( V_3 == 0 ) {
for (; ; ) {
V_4 -> V_3 = F_27 ( F_28 () ) & V_29 ;
if ( V_4 -> V_3 ) {
V_28 = F_1 ( V_2 , V_4 -> V_3 ) ;
if ( V_28 == NULL )
break;
}
}
} else {
V_28 = F_1 ( V_2 , V_4 -> V_3 ) ;
if ( V_28 != NULL ) {
F_6 ( & V_28 -> V_9 ) ;
F_17 ( & V_8 ) ;
return V_28 ;
}
}
V_4 -> V_11 = V_12 ;
V_4 -> V_6 = V_5 [ F_2 ( V_4 -> V_3 ) ] ;
V_5 [ F_2 ( V_4 -> V_3 ) ] = V_4 ;
F_6 ( & V_26 ) ;
F_17 ( & V_8 ) ;
return NULL ;
}
struct V_1 * F_29 ( struct V_30 * V_31 , T_1 V_3 )
{
struct V_32 * V_33 ;
struct V_34 * V_35 = F_30 ( V_31 ) ;
V_3 &= V_29 ;
F_5 ( & V_36 ) ;
for ( V_33 = V_35 -> V_37 ; V_33 ; V_33 = V_33 -> V_6 ) {
struct V_1 * V_4 = V_33 -> V_4 ;
if ( V_4 -> V_3 == V_3 ) {
V_4 -> V_11 = V_12 ;
F_6 ( & V_4 -> V_9 ) ;
F_7 ( & V_36 ) ;
return V_4 ;
}
}
F_7 ( & V_36 ) ;
return NULL ;
}
void F_31 ( struct V_30 * V_31 )
{
struct V_34 * V_35 = F_30 ( V_31 ) ;
struct V_32 * V_33 ;
while ( ( V_33 = V_35 -> V_37 ) != NULL ) {
V_35 -> V_37 = V_33 -> V_6 ;
F_11 ( V_33 -> V_4 ) ;
F_10 ( V_33 ) ;
}
}
struct V_18 * F_32 ( struct V_18 * V_38 ,
struct V_1 * V_4 ,
struct V_18 * V_39 )
{
struct V_18 * V_40 = V_4 -> V_10 ;
if ( V_39 == NULL || V_39 -> V_41 == 0 )
return V_40 ;
if ( V_40 != NULL ) {
V_38 -> V_42 = V_40 -> V_42 ;
V_38 -> V_43 = V_40 -> V_43 ;
V_38 -> V_44 = V_40 -> V_44 ;
V_38 -> V_45 = V_40 -> V_45 ;
} else {
if ( V_39 -> V_45 == 0 )
return V_39 ;
V_38 -> V_42 = NULL ;
V_38 -> V_43 = NULL ;
V_38 -> V_44 = NULL ;
V_38 -> V_45 = 0 ;
}
V_38 -> V_46 = V_39 -> V_46 ;
V_38 -> V_41 = V_39 -> V_41 ;
return V_38 ;
}
static unsigned long F_33 ( unsigned long V_47 )
{
if ( V_47 < V_48 )
return V_48 * V_49 ;
if ( V_47 > V_27 && ! F_34 ( V_50 ) )
return 0 ;
return V_47 * V_49 ;
}
static int F_35 ( struct V_1 * V_4 , unsigned long V_14 , unsigned long V_15 )
{
V_14 = F_33 ( V_14 ) ;
if ( ! V_14 )
return - V_51 ;
V_15 = F_33 ( V_15 ) ;
if ( ! V_15 )
return - V_51 ;
V_4 -> V_11 = V_12 ;
if ( F_23 ( V_4 -> V_14 , V_14 ) )
V_4 -> V_14 = V_14 ;
if ( F_23 ( V_15 , V_4 -> V_14 ) )
V_15 = V_4 -> V_14 ;
if ( F_23 ( V_4 -> V_15 , V_4 -> V_11 + V_15 ) )
V_4 -> V_15 = V_4 -> V_11 + V_15 ;
return 0 ;
}
static struct V_1 *
F_36 ( struct V_2 * V_2 , struct V_30 * V_31 , struct V_52 * V_53 ,
char T_3 * V_54 , int V_55 , int * V_56 )
{
struct V_1 * V_4 = NULL ;
int V_57 ;
int V_58 ;
int V_59 ;
V_57 = V_55 - F_37 ( sizeof( * V_53 ) ) ;
V_59 = - V_60 ;
if ( V_57 > 64 * 1024 )
goto V_61;
V_59 = - V_62 ;
V_4 = F_38 ( sizeof( * V_4 ) , V_63 ) ;
if ( V_4 == NULL )
goto V_61;
if ( V_57 > 0 ) {
struct V_64 V_65 ;
struct V_66 V_66 ;
int V_67 ;
V_59 = - V_62 ;
V_4 -> V_10 = F_39 ( sizeof( * V_4 -> V_10 ) + V_57 , V_63 ) ;
if ( V_4 -> V_10 == NULL )
goto V_61;
memset ( V_4 -> V_10 , 0 , sizeof( * V_4 -> V_10 ) ) ;
V_4 -> V_10 -> V_68 = sizeof( * V_4 -> V_10 ) + V_57 ;
V_59 = - V_69 ;
if ( F_40 ( V_4 -> V_10 + 1 , V_54 + F_37 ( sizeof( * V_53 ) ) , V_57 ) )
goto V_61;
V_65 . V_70 = V_57 ;
V_65 . V_71 = ( void * ) ( V_4 -> V_10 + 1 ) ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_59 = F_41 ( V_2 , V_31 , & V_65 , & V_66 , V_4 -> V_10 , & V_67 ,
& V_67 , & V_67 ) ;
if ( V_59 )
goto V_61;
V_59 = - V_60 ;
if ( V_4 -> V_10 -> V_41 )
goto V_61;
if ( V_4 -> V_10 -> V_45 == 0 ) {
F_10 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
}
}
V_4 -> V_7 = F_42 ( V_2 ) ;
V_4 -> V_15 = V_12 ;
V_59 = F_35 ( V_4 , V_53 -> V_72 , V_53 -> V_73 ) ;
if ( V_59 )
goto V_61;
V_4 -> V_16 = V_53 -> V_74 ;
V_58 = F_43 ( & V_53 -> V_75 ) ;
if ( ( V_58 & V_76 ) ||
V_58 == V_77 ) {
V_59 = - V_60 ;
goto V_61;
}
V_4 -> V_78 = V_53 -> V_75 ;
F_44 ( & V_4 -> V_9 , 1 ) ;
switch ( V_4 -> V_16 ) {
case V_17 :
case V_79 :
break;
case V_80 :
V_4 -> V_81 = V_82 -> V_83 ;
break;
case V_84 :
V_4 -> V_81 = F_45 () ;
break;
default:
V_59 = - V_60 ;
goto V_61;
}
return V_4 ;
V_61:
F_8 ( V_4 ) ;
* V_56 = V_59 ;
return NULL ;
}
static int F_46 ( struct V_30 * V_31 )
{
struct V_34 * V_35 = F_30 ( V_31 ) ;
struct V_32 * V_33 ;
int V_85 = V_86 - F_20 ( & V_26 ) ;
int V_87 = 0 ;
if ( V_85 > V_86 - V_88 )
return 0 ;
for ( V_33 = V_35 -> V_37 ; V_33 ; V_33 = V_33 -> V_6 )
V_87 ++ ;
if ( V_85 <= 0 ||
( ( V_87 >= V_88 ||
( V_87 > 0 && V_85 < V_86 / 2 ) || V_85 < V_86 / 4 ) &&
! F_34 ( V_50 ) ) )
return - V_89 ;
return 0 ;
}
static bool F_47 ( struct V_90 * V_91 , struct V_90 * V_92 )
{
if ( V_91 == V_92 )
return false ;
if ( V_91 == NULL || V_92 == NULL )
return true ;
if ( V_91 -> V_93 != V_92 -> V_93 )
return true ;
return memcmp ( V_91 + 1 , V_92 + 1 , ( ( V_91 -> V_93 + 1 ) << 3 ) - sizeof( * V_91 ) ) ;
}
static bool F_48 ( struct V_18 * V_94 , struct V_18 * V_95 )
{
if ( V_94 == V_95 )
return false ;
if ( V_94 == NULL || V_95 == NULL )
return true ;
if ( V_94 -> V_45 != V_95 -> V_45 )
return true ;
if ( F_47 ( V_94 -> V_42 , V_95 -> V_42 ) )
return true ;
if ( F_47 ( V_94 -> V_43 , V_95 -> V_43 ) )
return true ;
if ( F_47 ( (struct V_90 * ) V_94 -> V_44 , (struct V_90 * ) V_95 -> V_44 ) )
return true ;
return false ;
}
static inline void F_49 ( struct V_34 * V_35 , struct V_32 * V_33 ,
struct V_1 * V_4 )
{
F_12 ( & V_36 ) ;
V_33 -> V_4 = V_4 ;
V_33 -> V_6 = V_35 -> V_37 ;
V_35 -> V_37 = V_33 ;
F_17 ( & V_36 ) ;
}
int F_50 ( struct V_30 * V_31 , char T_3 * V_54 , int V_55 )
{
int V_96 ( V_59 ) ;
struct V_2 * V_2 = F_51 ( V_31 ) ;
struct V_34 * V_35 = F_30 ( V_31 ) ;
struct V_52 V_53 ;
struct V_32 * V_97 = NULL ;
struct V_32 * V_33 , * * V_98 ;
struct V_1 * V_4 , * V_99 = NULL ;
if ( V_55 < sizeof( V_53 ) )
return - V_60 ;
if ( F_40 ( & V_53 , V_54 , sizeof( V_53 ) ) )
return - V_69 ;
switch ( V_53 . V_100 ) {
case V_101 :
F_12 ( & V_36 ) ;
for ( V_98 = & V_35 -> V_37 ; ( V_33 = * V_98 ) != NULL ; V_98 = & V_33 -> V_6 ) {
if ( V_33 -> V_4 -> V_3 == V_53 . V_102 ) {
if ( V_53 . V_102 == ( V_35 -> V_103 & V_29 ) )
V_35 -> V_103 &= ~ V_29 ;
* V_98 = V_33 -> V_6 ;
F_17 ( & V_36 ) ;
F_11 ( V_33 -> V_4 ) ;
F_10 ( V_33 ) ;
return 0 ;
}
}
F_17 ( & V_36 ) ;
return - V_104 ;
case V_105 :
F_5 ( & V_36 ) ;
for ( V_33 = V_35 -> V_37 ; V_33 ; V_33 = V_33 -> V_6 ) {
if ( V_33 -> V_4 -> V_3 == V_53 . V_102 ) {
V_59 = F_35 ( V_33 -> V_4 , V_53 . V_72 , V_53 . V_73 ) ;
F_7 ( & V_36 ) ;
return V_59 ;
}
}
F_7 ( & V_36 ) ;
if ( V_53 . V_74 == V_106 && F_34 ( V_50 ) ) {
V_4 = F_4 ( V_2 , V_53 . V_102 ) ;
if ( V_4 ) {
V_59 = F_35 ( V_4 , V_53 . V_72 , V_53 . V_73 ) ;
F_11 ( V_4 ) ;
return V_59 ;
}
}
return - V_104 ;
case V_107 :
if ( V_53 . V_102 & ~ V_29 )
return - V_60 ;
V_4 = F_36 ( V_2 , V_31 , & V_53 , V_54 , V_55 , & V_59 ) ;
if ( V_4 == NULL )
return V_59 ;
V_97 = F_39 ( sizeof( * V_97 ) , V_63 ) ;
if ( V_53 . V_102 ) {
V_59 = - V_108 ;
F_5 ( & V_36 ) ;
for ( V_33 = V_35 -> V_37 ; V_33 ; V_33 = V_33 -> V_6 ) {
if ( V_33 -> V_4 -> V_3 == V_53 . V_102 ) {
if ( V_53 . V_109 & V_110 ) {
F_7 ( & V_36 ) ;
goto V_61;
}
V_99 = V_33 -> V_4 ;
F_6 ( & V_99 -> V_9 ) ;
break;
}
}
F_7 ( & V_36 ) ;
if ( V_99 == NULL )
V_99 = F_4 ( V_2 , V_53 . V_102 ) ;
if ( V_99 ) {
V_111:
V_59 = - V_108 ;
if ( V_53 . V_109 & V_110 )
goto V_112;
V_59 = - V_51 ;
if ( V_99 -> V_16 == V_17 ||
V_99 -> V_16 != V_4 -> V_16 ||
V_99 -> V_81 != V_4 -> V_81 )
goto V_112;
V_59 = - V_60 ;
if ( ! F_52 ( & V_99 -> V_78 , & V_4 -> V_78 ) ||
F_48 ( V_99 -> V_10 , V_4 -> V_10 ) )
goto V_112;
V_59 = - V_62 ;
if ( V_97 == NULL )
goto V_112;
if ( V_4 -> V_14 > V_99 -> V_14 )
V_99 -> V_14 = V_4 -> V_14 ;
if ( ( long ) ( V_4 -> V_15 - V_99 -> V_15 ) > 0 )
V_99 -> V_15 = V_4 -> V_15 ;
F_49 ( V_35 , V_97 , V_99 ) ;
F_8 ( V_4 ) ;
return 0 ;
V_112:
F_11 ( V_99 ) ;
goto V_61;
}
}
V_59 = - V_113 ;
if ( ! ( V_53 . V_109 & V_114 ) )
goto V_61;
V_59 = - V_62 ;
if ( V_97 == NULL || ( V_59 = F_46 ( V_31 ) ) != 0 )
goto V_61;
V_99 = F_26 ( V_2 , V_4 , V_53 . V_102 ) ;
if ( V_99 != NULL )
goto V_111;
if ( ! V_53 . V_102 ) {
if ( F_53 ( & ( (struct V_52 T_3 * ) V_54 ) -> V_102 ,
& V_4 -> V_3 , sizeof( V_4 -> V_3 ) ) ) {
}
}
F_49 ( V_35 , V_97 , V_4 ) ;
return 0 ;
default:
return - V_60 ;
}
V_61:
F_8 ( V_4 ) ;
F_10 ( V_97 ) ;
return V_59 ;
}
static struct V_1 * F_54 ( struct V_115 * V_116 )
{
struct V_1 * V_4 = NULL ;
struct V_117 * V_118 = F_55 ( V_116 ) ;
struct V_2 * V_2 = F_56 ( V_116 ) ;
for ( V_118 -> V_119 = 0 ; V_118 -> V_119 <= V_24 ; ++ V_118 -> V_119 ) {
V_4 = V_5 [ V_118 -> V_119 ] ;
while ( V_4 && ! F_3 ( V_4 -> V_7 , V_2 ) )
V_4 = V_4 -> V_6 ;
if ( V_4 )
break;
}
return V_4 ;
}
static struct V_1 * F_57 ( struct V_115 * V_116 , struct V_1 * V_4 )
{
struct V_117 * V_118 = F_55 ( V_116 ) ;
struct V_2 * V_2 = F_56 ( V_116 ) ;
V_4 = V_4 -> V_6 ;
V_120:
while ( V_4 && ! F_3 ( V_4 -> V_7 , V_2 ) )
V_4 = V_4 -> V_6 ;
while ( ! V_4 ) {
if ( ++ V_118 -> V_119 <= V_24 ) {
V_4 = V_5 [ V_118 -> V_119 ] ;
goto V_120;
} else
break;
}
return V_4 ;
}
static struct V_1 * F_58 ( struct V_115 * V_116 , T_4 V_121 )
{
struct V_1 * V_4 = F_54 ( V_116 ) ;
if ( V_4 )
while ( V_121 && ( V_4 = F_57 ( V_116 , V_4 ) ) != NULL )
-- V_121 ;
return V_121 ? NULL : V_4 ;
}
static void * F_59 ( struct V_115 * V_116 , T_4 * V_121 )
__acquires( V_8 )
{
F_5 ( & V_8 ) ;
return * V_121 ? F_58 ( V_116 , * V_121 - 1 ) : V_122 ;
}
static void * F_60 ( struct V_115 * V_116 , void * V_123 , T_4 * V_121 )
{
struct V_1 * V_4 ;
if ( V_123 == V_122 )
V_4 = F_54 ( V_116 ) ;
else
V_4 = F_57 ( V_116 , V_123 ) ;
++ * V_121 ;
return V_4 ;
}
static void F_61 ( struct V_115 * V_116 , void * V_123 )
__releases( V_8 )
{
F_7 ( & V_8 ) ;
}
static int F_62 ( struct V_115 * V_116 , void * V_123 )
{
if ( V_123 == V_122 )
F_63 ( V_116 , L_1 ,
L_2 , L_3 , L_4 , L_5 , L_6 , L_7 , L_8 , L_9 ) ;
else {
struct V_1 * V_4 = V_123 ;
F_63 ( V_116 ,
L_10 ,
( unsigned int ) F_64 ( V_4 -> V_3 ) ,
V_4 -> V_16 ,
( int ) V_4 -> V_81 ,
F_20 ( & V_4 -> V_9 ) ,
V_4 -> V_14 / V_49 ,
( long ) ( V_4 -> V_15 - V_12 ) / V_49 ,
& V_4 -> V_78 ,
V_4 -> V_10 ? V_4 -> V_10 -> V_45 : 0 ) ;
}
return 0 ;
}
static int F_65 ( struct V_124 * V_124 , struct V_125 * V_125 )
{
return F_66 ( V_124 , V_125 , & V_126 ,
sizeof( struct V_117 ) ) ;
}
static int T_5 F_67 ( struct V_2 * V_2 )
{
if ( ! F_68 ( V_2 , L_11 ,
V_127 , & V_128 ) )
return - V_62 ;
return 0 ;
}
static void T_2 F_69 ( struct V_2 * V_2 )
{
F_70 ( V_2 , L_11 ) ;
}
static inline int F_67 ( struct V_2 * V_2 )
{
return 0 ;
}
static inline void F_69 ( struct V_2 * V_2 )
{
}
static void T_2 F_71 ( struct V_2 * V_2 )
{
F_25 ( V_2 ) ;
F_69 ( V_2 ) ;
}
int F_72 ( void )
{
return F_73 ( & V_129 ) ;
}
void F_74 ( void )
{
F_75 ( & V_19 ) ;
F_76 ( & V_129 ) ;
}
