static T_1 F_1 ( T_1 V_1 )
{
T_1 V_2 ;
int V_3 ;
if ( ! ( V_1 & V_4 ) )
return 0 ;
V_2 = V_1 & V_5 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_6 ) ; V_3 ++ ) {
if ( V_2 == V_6 [ V_3 ] . V_7 ) {
V_2 = V_6 [ V_3 ] . V_8 ;
break;
} else if ( V_2 == V_6 [ V_3 ] . V_8 ) {
V_2 = V_6 [ V_3 ] . V_7 ;
break;
}
}
if ( V_3 >= F_2 ( V_6 ) )
return 0 ;
return V_2 | ( V_1 & V_9 ) ;
}
static struct V_10 * F_3 ( T_1 V_1 )
{
unsigned int V_11 = F_4 ( V_1 ) ;
struct V_10 * V_12 = NULL ;
if ( V_11 < F_2 ( V_13 ) )
V_12 = & V_13 [ V_11 ] ;
return V_12 ;
}
static T_1 F_5 ( int V_14 )
{
struct V_10 * V_12 ;
unsigned int V_15 ;
T_1 V_1 ;
V_1 = V_16 [ V_14 ] ;
V_12 = F_3 ( V_1 ) ;
V_15 = F_6 ( V_12 -> V_17 ) ;
V_1 |= F_7 ( F_8 ( V_15 ) ) ;
return V_1 ;
}
static bool F_9 ( unsigned int V_18 )
{
if ( V_18 == V_19 ) {
if ( V_20 . V_21 != 3 &&
V_20 . V_21 != 4 &&
V_20 . V_21 != 6 )
return false ;
}
return true ;
}
static int F_10 ( struct V_22 * V_23 )
{
unsigned int V_24 , V_25 ;
V_24 = F_4 ( V_23 -> V_26 . V_1 ) ;
if ( V_24 >= F_2 ( V_13 ) )
return - V_27 ;
if ( ! F_9 ( V_24 ) )
return - V_27 ;
if ( F_11 () && V_13 [ V_24 ] . V_28 ) {
if ( F_12 () && ! F_13 ( V_29 ) )
return - V_30 ;
}
V_25 = F_14 ( V_23 -> V_26 . V_1 ) & V_31 ;
if ( V_25 & ~ V_13 [ V_24 ] . V_32 )
return - V_27 ;
if ( F_15 ( V_23 -> V_26 . V_1 , V_33 ) )
return - V_27 ;
V_24 = F_16 ( V_23 -> V_26 . V_1 ) ;
if ( V_24 >= F_2 ( V_34 ) )
return - V_27 ;
return 0 ;
}
static int F_17 ( struct V_22 * V_23 )
{
int V_35 = F_18 () ;
int V_36 = 0 ;
T_2 V_37 , V_38 ;
V_38 = F_19 ( V_35 ) ;
V_37 = F_20 ( V_35 , V_23 -> V_26 . V_39 ,
V_23 -> V_26 . V_40 ) ;
V_23 -> V_41 . V_1 = F_21 ( V_37 ) |
F_7 ( V_38 ) ;
if ( F_11 () && F_22 ( V_35 ) )
V_23 -> V_41 . V_1 = F_23 ( V_23 -> V_41 . V_1 ) ;
if ( V_23 -> V_26 . type == V_42 ) {
struct V_10 * V_12 ;
unsigned int V_15 ;
V_23 -> V_26 . V_1 &= V_43 ;
V_36 = F_10 ( V_23 ) ;
if ( V_36 )
goto V_44;
V_23 -> V_41 . V_1 |= V_23 -> V_26 . V_1 ;
V_12 = F_3 ( V_23 -> V_26 . V_1 ) ;
if ( ! V_12 ) {
V_36 = - V_27 ;
goto V_44;
}
V_15 = F_6 ( V_12 -> V_17 ) ;
V_23 -> V_41 . V_1 |= F_7 ( F_8 ( V_15 ) ) ;
}
V_36 = F_24 ( V_23 ) ;
V_44:
F_25 () ;
return V_36 ;
}
static inline int F_26 ( struct V_45 * V_46 )
{
T_1 V_24 ;
F_27 ( V_46 -> V_47 , V_24 ) ;
if ( V_24 & V_48 ) {
F_28 ( V_46 -> V_47 , V_24 & ~ V_48 ) ;
return 1 ;
}
F_27 ( V_46 -> V_49 , V_24 ) ;
if ( ! ( V_24 & V_50 ) )
return 1 ;
return 0 ;
}
static void F_29 ( void )
{
}
static inline void F_30 ( struct V_22 * V_23 )
{
struct V_45 * V_46 = & V_23 -> V_41 ;
( void ) F_31 ( V_46 -> V_47 ,
( T_1 ) ( F_32 ( V_46 -> V_1 ) ) &
~ V_51 & ~ V_48 & ~ V_52 ) ;
}
static void F_33 ( void )
{
struct V_53 * V_54 = & F_34 ( V_53 ) ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_56 . V_57 ; V_55 ++ ) {
struct V_22 * V_23 = V_54 -> V_58 [ V_55 ] ;
if ( ! F_35 ( V_55 , V_54 -> V_59 ) )
continue;
F_30 ( V_23 ) ;
}
F_29 () ;
}
static void F_36 ( T_1 V_1 )
{
struct V_60 * V_12 ;
unsigned int V_55 ;
F_37 ( V_61 > V_62 ) ;
V_55 = F_16 ( V_1 ) ;
if ( V_55 == V_63 )
return;
V_12 = & V_34 [ V_55 ] ;
( void ) F_31 ( V_64 , ( T_1 ) V_12 -> V_65 ) ;
( void ) F_31 ( V_66 , ( T_1 ) V_12 -> V_67 ) ;
}
static void F_38 ( struct V_22 * V_23 )
{
struct V_45 * V_46 = & V_23 -> V_41 ;
int V_68 = F_39 ( V_46 -> V_1 ) ;
T_1 V_69 = F_14 ( F_40 ( V_46 -> V_1 ) ) ;
unsigned int V_55 = F_4 ( V_46 -> V_1 ) ;
struct V_10 * V_12 ;
T_1 V_70 , V_38 ;
V_12 = & V_13 [ V_55 ] ;
V_70 = ( T_1 ) V_12 -> V_71 [ V_68 ] ;
F_41 ( F_42 ( V_46 -> V_1 ) ) ;
F_41 ( V_46 -> V_55 == 1 ) ;
V_69 &= ~ V_72 ;
V_69 |= F_43 ( F_44 ( V_12 -> V_17 ) ) ;
V_38 = F_32 ( V_46 -> V_1 ) ;
F_36 ( V_46 -> V_1 ) ;
( void ) F_31 ( V_70 , V_69 ) ;
( void ) F_31 ( V_46 -> V_47 ,
( V_38 & ~ V_52 ) | V_51 ) ;
}
static void F_45 ( int V_73 )
{
struct V_53 * V_54 = & F_34 ( V_53 ) ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_56 . V_57 ; V_55 ++ ) {
struct V_22 * V_23 = V_54 -> V_58 [ V_55 ] ;
if ( ! F_35 ( V_55 , V_54 -> V_59 ) )
continue;
F_38 ( V_23 ) ;
}
}
static int F_46 ( struct V_74 * V_75 )
{
struct V_76 V_77 ;
struct V_53 * V_54 ;
struct V_22 * V_23 ;
struct V_45 * V_46 ;
int V_55 , V_78 = 0 ;
T_1 V_79 ;
F_47 ( & V_77 , 0 ) ;
V_54 = & F_34 ( V_53 ) ;
for ( V_55 = 0 ; V_55 < V_56 . V_57 ; V_55 ++ ) {
int V_80 ;
if ( ! F_35 ( V_55 , V_54 -> V_59 ) ) {
if ( F_48 ( V_55 , V_54 -> V_81 ) )
V_78 ++ ;
continue;
}
V_23 = V_54 -> V_58 [ V_55 ] ;
V_46 = & V_23 -> V_41 ;
F_41 ( V_46 -> V_55 != V_55 ) ;
V_80 = F_26 ( V_46 ) ;
V_79 = F_49 ( V_23 ) ;
if ( ! V_80 && ( V_79 & ( 1ULL << ( V_56 . V_82 - 1 ) ) ) )
continue;
V_78 += V_80 ;
V_77 . V_83 = V_23 -> V_41 . V_84 ;
if ( ! F_50 ( V_23 ) )
continue;
if ( F_51 ( V_23 , & V_77 , V_75 ) )
F_52 ( V_23 , 0 ) ;
}
if ( V_78 )
F_53 ( V_85 ) ;
F_54 ( V_86 , V_87 ) ;
return V_78 ;
}
static void F_55 ( struct V_45 * V_46 , int V_35 )
{
T_2 V_37 , V_38 ;
if ( ! F_56 ( V_46 -> V_1 , V_35 ) )
return;
V_37 = F_14 ( V_46 -> V_1 ) ;
V_38 = F_32 ( V_46 -> V_1 ) ;
if ( F_22 ( V_35 ) ) {
V_38 &= ~ V_88 ;
V_38 |= V_89 ;
if ( V_37 & V_90 ) {
V_37 &= ~ V_90 ;
V_37 |= V_91 ;
}
if ( V_37 & V_92 ) {
V_37 &= ~ V_92 ;
V_37 |= V_93 ;
}
V_46 -> V_1 = F_21 ( V_37 ) ;
V_46 -> V_1 |= F_7 ( V_38 ) ;
V_46 -> V_1 |= V_94 ;
} else {
V_38 &= ~ V_89 ;
V_38 |= V_88 ;
if ( V_37 & V_91 ) {
V_37 &= ~ V_91 ;
V_37 |= V_90 ;
}
if ( V_37 & V_93 ) {
V_37 &= ~ V_93 ;
V_37 |= V_92 ;
}
V_46 -> V_1 = F_21 ( V_37 ) ;
V_46 -> V_1 |= F_7 ( V_38 ) ;
V_46 -> V_1 &= ~ V_94 ;
}
}
static int F_57 ( unsigned int V_95 )
{
unsigned int V_55 = F_58 ( V_95 ) ;
if ( F_59 ( V_55 >= V_96 ||
! V_97 [ V_55 ] ||
V_97 [ V_55 ] != V_95 ) ) {
F_60 ( 1 , L_1 , V_95 ) ;
return - 1 ;
}
return V_55 ;
}
static int F_61 ( int V_68 , unsigned long * V_98 ,
struct V_10 * V_12 )
{
int V_3 , V_99 ;
for ( V_3 = 0 ; V_3 < V_100 ; V_3 ++ ) {
V_99 = V_12 -> V_101 [ V_68 ] [ V_3 ] ;
if ( V_99 != - 1 && ! F_35 ( V_99 , V_98 ) )
return V_99 ;
}
return - 1 ;
}
static int F_62 ( struct V_53 * V_54 , int V_102 , int * V_103 )
{
unsigned long V_98 [ F_63 ( V_104 ) ] ;
unsigned long V_105 [ F_63 ( V_96 ) ] ;
int V_35 = F_64 () ;
struct V_45 * V_46 ;
struct V_10 * V_12 ;
unsigned int V_3 , V_68 , V_106 ;
int V_107 , V_108 ;
T_1 V_109 ;
int V_110 ;
F_65 ( V_98 , V_104 ) ;
F_65 ( V_105 , V_96 ) ;
for ( V_3 = 0 , V_106 = V_102 ; V_3 < V_102 ; V_3 ++ , V_106 -- ) {
V_46 = & V_54 -> V_111 [ V_3 ] -> V_41 ;
V_68 = F_22 ( V_35 ) ;
V_110 = 0 ;
V_112:
if ( V_110 > 2 )
goto V_113;
V_12 = F_3 ( V_46 -> V_1 ) ;
V_108 = F_57 ( V_12 -> V_71 [ V_68 ] ) ;
if ( F_59 ( V_108 == - 1 ) )
goto V_113;
if ( V_46 -> V_55 != - 1 && ! F_56 ( V_46 -> V_1 , V_35 ) ) {
V_107 = V_46 -> V_55 ;
if ( V_103 )
V_103 [ V_3 ] = V_46 -> V_55 ;
goto V_114;
}
V_107 = F_61 ( V_68 , V_98 , V_12 ) ;
if ( V_107 == - 1 || F_35 ( V_108 , V_105 ) ) {
V_109 = F_1 ( V_46 -> V_1 ) ;
if ( ! V_109 )
goto V_113;
V_46 -> V_1 = V_109 ;
V_110 ++ ;
goto V_112;
}
F_55 ( V_46 , V_35 ) ;
if ( V_103 )
V_103 [ V_3 ] = V_107 ;
V_114:
F_66 ( V_107 , V_98 ) ;
F_66 ( V_108 , V_105 ) ;
}
V_113:
return V_106 ? - V_115 : 0 ;
}
static T_3 int F_67 ( void )
{
unsigned int V_116 , V_117 ;
F_37 ( V_118 > V_119 ) ;
F_68 ( V_120 , V_116 , V_117 ) ;
if ( ! ( V_116 & ( 1 << 7 ) ) ) {
F_69 ( L_2 ,
V_20 . V_21 ) ;
return - V_121 ;
}
memcpy ( V_122 , V_123 ,
sizeof( V_122 ) ) ;
F_69 ( L_3 ) ;
V_56 = V_124 ;
return 0 ;
}
