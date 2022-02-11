static struct V_1 * F_1 ( T_1 V_2 )
{
unsigned int V_3 = F_2 ( V_2 ) ;
struct V_1 * V_4 = NULL ;
if ( V_3 < F_3 ( V_5 ) )
V_4 = & V_5 [ V_3 ] ;
return V_4 ;
}
static T_1 F_4 ( int V_6 )
{
struct V_1 * V_4 ;
unsigned int V_7 ;
T_1 V_2 ;
V_2 = V_8 [ V_6 ] ;
V_4 = F_1 ( V_2 ) ;
V_7 = F_5 ( V_4 -> V_9 ) ;
V_2 |= F_6 ( F_7 ( V_7 ) ) ;
return V_2 ;
}
static bool F_8 ( unsigned int V_10 )
{
if ( V_10 == V_11 ) {
if ( V_12 . V_13 != 3 &&
V_12 . V_13 != 4 &&
V_12 . V_13 != 6 )
return false ;
}
return true ;
}
static int F_9 ( struct V_14 * V_15 )
{
unsigned int V_16 , V_17 ;
V_16 = F_2 ( V_15 -> V_18 . V_2 ) ;
if ( V_16 >= F_3 ( V_5 ) )
return - V_19 ;
if ( ! F_8 ( V_16 ) )
return - V_19 ;
if ( F_10 () && V_5 [ V_16 ] . V_20 ) {
if ( F_11 () && ! F_12 ( V_21 ) )
return - V_22 ;
}
V_17 = F_13 ( V_15 -> V_18 . V_2 ) & V_23 ;
if ( V_17 & ~ V_5 [ V_16 ] . V_24 )
return - V_19 ;
if ( F_14 ( V_15 -> V_18 . V_2 , V_25 ) )
return - V_19 ;
V_16 = F_15 ( V_15 -> V_18 . V_2 ) ;
if ( V_16 >= F_3 ( V_26 ) )
return - V_19 ;
return 0 ;
}
static int F_16 ( struct V_14 * V_15 )
{
int V_27 = F_17 () ;
int V_28 = 0 ;
T_2 V_29 , V_30 ;
V_30 = F_18 ( V_27 ) ;
V_29 = F_19 ( V_27 , V_15 -> V_18 . V_31 ,
V_15 -> V_18 . V_32 ) ;
V_15 -> V_33 . V_2 = F_20 ( V_29 ) |
F_6 ( V_30 ) ;
if ( F_10 () && F_21 ( V_27 ) )
V_15 -> V_33 . V_2 = F_22 ( V_15 -> V_33 . V_2 ) ;
if ( V_15 -> V_18 . type == V_34 ) {
struct V_1 * V_4 ;
unsigned int V_7 ;
V_15 -> V_18 . V_2 &= V_35 ;
V_28 = F_9 ( V_15 ) ;
if ( V_28 )
goto V_36;
V_15 -> V_33 . V_2 |= V_15 -> V_18 . V_2 ;
V_4 = F_1 ( V_15 -> V_18 . V_2 ) ;
if ( ! V_4 ) {
V_28 = - V_19 ;
goto V_36;
}
V_7 = F_5 ( V_4 -> V_9 ) ;
V_15 -> V_33 . V_2 |= F_6 ( F_7 ( V_7 ) ) ;
}
V_28 = F_23 ( V_15 ) ;
V_36:
F_24 () ;
return V_28 ;
}
static inline int F_25 ( struct V_37 * V_38 )
{
T_1 V_16 ;
F_26 ( V_38 -> V_39 , V_16 ) ;
if ( V_16 & V_40 ) {
F_27 ( V_38 -> V_39 , V_16 & ~ V_40 ) ;
return 1 ;
}
F_26 ( V_38 -> V_41 , V_16 ) ;
if ( ! ( V_16 & V_42 ) )
return 1 ;
return 0 ;
}
static void F_28 ( void )
{
}
static inline void F_29 ( struct V_14 * V_15 )
{
struct V_37 * V_38 = & V_15 -> V_33 ;
( void ) F_30 ( V_38 -> V_39 ,
( T_1 ) ( F_31 ( V_38 -> V_2 ) ) &
~ V_43 & ~ V_40 & ~ V_44 ) ;
}
static void F_32 ( void )
{
struct V_45 * V_46 = & F_33 ( V_45 ) ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_48 . V_49 ; V_47 ++ ) {
struct V_14 * V_15 = V_46 -> V_50 [ V_47 ] ;
if ( ! F_34 ( V_47 , V_46 -> V_51 ) )
continue;
F_29 ( V_15 ) ;
}
F_28 () ;
}
static void F_35 ( T_1 V_2 )
{
struct V_52 * V_4 ;
unsigned int V_47 ;
F_36 ( V_53 > V_54 ) ;
V_47 = F_15 ( V_2 ) ;
if ( V_47 == V_55 )
return;
V_4 = & V_26 [ V_47 ] ;
( void ) F_30 ( V_56 , ( T_1 ) V_4 -> V_57 ) ;
( void ) F_30 ( V_58 , ( T_1 ) V_4 -> V_59 ) ;
}
static void F_37 ( struct V_14 * V_15 )
{
struct V_37 * V_38 = & V_15 -> V_33 ;
int V_60 = F_38 ( V_38 -> V_2 ) ;
T_1 V_61 = F_13 ( F_39 ( V_38 -> V_2 ) ) ;
unsigned int V_47 = F_2 ( V_38 -> V_2 ) ;
struct V_1 * V_4 ;
T_1 V_62 , V_30 ;
V_4 = & V_5 [ V_47 ] ;
V_62 = ( T_1 ) V_4 -> V_63 [ V_60 ] ;
F_40 ( F_41 ( V_38 -> V_2 ) ) ;
F_40 ( V_38 -> V_47 == 1 ) ;
V_61 &= ~ V_64 ;
V_61 |= F_42 ( F_43 ( V_4 -> V_9 ) ) ;
V_30 = F_31 ( V_38 -> V_2 ) ;
F_35 ( V_38 -> V_2 ) ;
( void ) F_30 ( V_62 , V_61 ) ;
( void ) F_30 ( V_38 -> V_39 ,
( V_30 & ~ V_44 ) | V_43 ) ;
}
static void F_44 ( int V_65 )
{
struct V_45 * V_46 = & F_33 ( V_45 ) ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_48 . V_49 ; V_47 ++ ) {
struct V_14 * V_15 = V_46 -> V_50 [ V_47 ] ;
if ( ! F_34 ( V_47 , V_46 -> V_51 ) )
continue;
F_37 ( V_15 ) ;
}
}
static int F_45 ( struct V_66 * V_67 )
{
struct V_68 V_69 ;
struct V_45 * V_46 ;
struct V_14 * V_15 ;
struct V_37 * V_38 ;
int V_47 , V_70 = 0 ;
T_1 V_71 ;
F_46 ( & V_69 , 0 ) ;
V_46 = & F_33 ( V_45 ) ;
for ( V_47 = 0 ; V_47 < V_48 . V_49 ; V_47 ++ ) {
int V_72 ;
if ( ! F_34 ( V_47 , V_46 -> V_51 ) ) {
if ( F_47 ( V_47 , V_46 -> V_73 ) )
V_70 ++ ;
continue;
}
V_15 = V_46 -> V_50 [ V_47 ] ;
V_38 = & V_15 -> V_33 ;
F_40 ( V_38 -> V_47 != V_47 ) ;
V_72 = F_25 ( V_38 ) ;
V_71 = F_48 ( V_15 ) ;
if ( ! V_72 && ( V_71 & ( 1ULL << ( V_48 . V_74 - 1 ) ) ) )
continue;
V_70 += V_72 ;
V_69 . V_75 = V_15 -> V_33 . V_76 ;
if ( ! F_49 ( V_15 ) )
continue;
if ( F_50 ( V_15 , 1 , & V_69 , V_67 ) )
F_51 ( V_15 , 0 ) ;
}
if ( V_70 )
F_52 ( V_77 ) ;
F_53 ( V_78 , V_79 ) ;
return V_70 ;
}
static void F_54 ( struct V_37 * V_38 , int V_27 )
{
T_2 V_29 , V_30 ;
if ( ! F_55 ( V_38 -> V_2 , V_27 ) )
return;
V_29 = F_13 ( V_38 -> V_2 ) ;
V_30 = F_31 ( V_38 -> V_2 ) ;
if ( F_21 ( V_27 ) ) {
V_30 &= ~ V_80 ;
V_30 |= V_81 ;
if ( V_29 & V_82 ) {
V_29 &= ~ V_82 ;
V_29 |= V_83 ;
}
if ( V_29 & V_84 ) {
V_29 &= ~ V_84 ;
V_29 |= V_85 ;
}
V_38 -> V_2 = F_20 ( V_29 ) ;
V_38 -> V_2 |= F_6 ( V_30 ) ;
V_38 -> V_2 |= V_86 ;
} else {
V_30 &= ~ V_81 ;
V_30 |= V_80 ;
if ( V_29 & V_83 ) {
V_29 &= ~ V_83 ;
V_29 |= V_82 ;
}
if ( V_29 & V_85 ) {
V_29 &= ~ V_85 ;
V_29 |= V_84 ;
}
V_38 -> V_2 = F_20 ( V_29 ) ;
V_38 -> V_2 |= F_6 ( V_30 ) ;
V_38 -> V_2 &= ~ V_86 ;
}
}
static int F_56 ( unsigned int V_87 )
{
unsigned int V_47 = F_57 ( V_87 ) ;
if ( F_58 ( V_47 >= V_88 ||
! V_89 [ V_47 ] ||
V_89 [ V_47 ] != V_87 ) ) {
F_59 ( 1 , L_1 , V_87 ) ;
return - 1 ;
}
return V_47 ;
}
static int F_60 ( int V_60 , unsigned long * V_90 ,
struct V_1 * V_4 )
{
int V_91 , V_92 ;
for ( V_91 = 0 ; V_91 < V_93 ; V_91 ++ ) {
V_92 = V_4 -> V_94 [ V_60 ] [ V_91 ] ;
if ( V_92 != - 1 && ! F_34 ( V_92 , V_90 ) )
return V_92 ;
}
return - 1 ;
}
static int F_61 ( struct V_45 * V_46 , int V_95 , int * V_96 )
{
unsigned long V_90 [ F_62 ( V_97 ) ] ;
unsigned long V_98 [ F_62 ( V_88 ) ] ;
int V_27 = F_63 () ;
struct V_37 * V_38 ;
struct V_1 * V_4 ;
unsigned int V_91 , V_60 , V_99 ;
int V_100 , V_101 ;
F_64 ( V_90 , V_97 ) ;
F_64 ( V_98 , V_88 ) ;
for ( V_91 = 0 , V_99 = V_95 ; V_91 < V_95 ; V_91 ++ , V_99 -- ) {
V_38 = & V_46 -> V_102 [ V_91 ] -> V_33 ;
V_60 = F_21 ( V_27 ) ;
V_4 = F_1 ( V_38 -> V_2 ) ;
V_101 = F_56 ( V_4 -> V_63 [ V_60 ] ) ;
if ( F_58 ( V_101 == - 1 ) )
goto V_103;
if ( V_38 -> V_47 != - 1 && ! F_55 ( V_38 -> V_2 , V_27 ) ) {
V_100 = V_38 -> V_47 ;
if ( V_96 )
V_96 [ V_91 ] = V_38 -> V_47 ;
goto V_104;
}
V_100 = F_60 ( V_60 , V_90 , V_4 ) ;
if ( V_100 == - 1 || F_34 ( V_101 , V_98 ) )
goto V_103;
F_54 ( V_38 , V_27 ) ;
if ( V_96 )
V_96 [ V_91 ] = V_100 ;
V_104:
F_65 ( V_100 , V_90 ) ;
F_65 ( V_101 , V_98 ) ;
}
V_103:
return V_99 ? - V_105 : 0 ;
}
static T_3 int F_66 ( void )
{
unsigned int V_106 , V_107 ;
F_36 ( V_108 > V_109 ) ;
F_67 ( V_110 , V_106 , V_107 ) ;
if ( ! ( V_106 & ( 1 << 7 ) ) ) {
F_68 ( L_2 ,
V_12 . V_13 ) ;
return - V_111 ;
}
memcpy ( V_112 , V_113 ,
sizeof( V_112 ) ) ;
F_68 ( L_3 ) ;
V_48 = V_114 ;
return 0 ;
}
