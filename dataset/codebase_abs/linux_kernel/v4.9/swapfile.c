static inline unsigned char F_1 ( unsigned char V_1 )
{
return V_1 & ~ V_2 ;
}
static int
F_2 ( struct V_3 * V_4 , unsigned long V_5 )
{
T_1 V_6 = F_3 ( V_4 -> type , V_5 ) ;
struct V_7 * V_7 ;
int V_8 = 0 ;
V_7 = F_4 ( F_5 ( V_6 ) , F_6 ( V_6 ) ) ;
if ( ! V_7 )
return 0 ;
if ( F_7 ( V_7 ) ) {
V_8 = F_8 ( V_7 ) ;
F_9 ( V_7 ) ;
}
F_10 ( V_7 ) ;
return V_8 ;
}
static int F_11 ( struct V_3 * V_4 )
{
struct V_9 * V_10 ;
T_2 V_11 ;
T_2 V_12 ;
int V_13 = 0 ;
V_10 = & V_4 -> V_14 ;
V_11 = ( V_10 -> V_11 + 1 ) << ( V_15 - 9 ) ;
V_12 = ( ( T_2 ) V_10 -> V_16 - 1 ) << ( V_15 - 9 ) ;
if ( V_12 ) {
V_13 = F_12 ( V_4 -> V_17 , V_11 ,
V_12 , V_18 , 0 ) ;
if ( V_13 )
return V_13 ;
F_13 () ;
}
F_14 (se, &si->first_swap_extent.list, list) {
V_11 = V_10 -> V_11 << ( V_15 - 9 ) ;
V_12 = ( T_2 ) V_10 -> V_16 << ( V_15 - 9 ) ;
V_13 = F_12 ( V_4 -> V_17 , V_11 ,
V_12 , V_18 , 0 ) ;
if ( V_13 )
break;
F_13 () ;
}
return V_13 ;
}
static void F_15 ( struct V_3 * V_4 ,
T_3 V_19 , T_3 V_16 )
{
struct V_9 * V_10 = V_4 -> V_20 ;
int V_21 = 0 ;
while ( V_16 ) {
if ( V_10 -> V_19 <= V_19 &&
V_19 < V_10 -> V_19 + V_10 -> V_16 ) {
T_3 V_5 = V_19 - V_10 -> V_19 ;
T_2 V_11 = V_10 -> V_11 + V_5 ;
T_2 V_12 = V_10 -> V_16 - V_5 ;
if ( V_12 > V_16 )
V_12 = V_16 ;
V_19 += V_12 ;
V_16 -= V_12 ;
if ( ! V_21 ++ )
V_4 -> V_20 = V_10 ;
V_11 <<= V_15 - 9 ;
V_12 <<= V_15 - 9 ;
if ( F_12 ( V_4 -> V_17 , V_11 ,
V_12 , V_22 , 0 ) )
break;
}
V_10 = F_16 ( V_10 , V_23 ) ;
}
}
static inline void F_17 ( struct V_24 * V_25 ,
unsigned int V_26 )
{
V_25 -> V_27 = V_26 ;
}
static inline unsigned int F_18 ( struct V_24 * V_25 )
{
return V_25 -> V_28 ;
}
static inline void F_19 ( struct V_24 * V_25 ,
unsigned int V_29 )
{
V_25 -> V_28 = V_29 ;
}
static inline void F_20 ( struct V_24 * V_25 ,
unsigned int V_29 , unsigned int V_30 )
{
V_25 -> V_27 = V_30 ;
V_25 -> V_28 = V_29 ;
}
static inline unsigned int F_21 ( struct V_24 * V_25 )
{
return V_25 -> V_28 ;
}
static inline void F_22 ( struct V_24 * V_25 ,
unsigned int V_31 )
{
V_25 -> V_28 = V_31 ;
}
static inline void F_23 ( struct V_24 * V_25 ,
unsigned int V_31 , unsigned int V_30 )
{
V_25 -> V_27 = V_30 ;
V_25 -> V_28 = V_31 ;
}
static inline bool F_24 ( struct V_24 * V_25 )
{
return V_25 -> V_27 & V_32 ;
}
static inline bool F_25 ( struct V_24 * V_25 )
{
return V_25 -> V_27 & V_33 ;
}
static inline void F_26 ( struct V_24 * V_25 )
{
V_25 -> V_27 = V_33 ;
V_25 -> V_28 = 0 ;
}
static inline bool F_27 ( struct V_34 * V_23 )
{
return F_25 ( & V_23 -> V_35 ) ;
}
static inline unsigned int F_28 ( struct V_34 * V_23 )
{
return F_21 ( & V_23 -> V_35 ) ;
}
static void F_29 ( struct V_34 * V_23 )
{
F_26 ( & V_23 -> V_35 ) ;
F_26 ( & V_23 -> V_36 ) ;
}
static void F_30 ( struct V_34 * V_23 ,
struct V_24 * V_37 ,
unsigned int V_38 )
{
if ( F_27 ( V_23 ) ) {
F_23 ( & V_23 -> V_35 , V_38 , 0 ) ;
F_23 ( & V_23 -> V_36 , V_38 , 0 ) ;
} else {
unsigned int V_36 = F_21 ( & V_23 -> V_36 ) ;
F_22 ( & V_37 [ V_36 ] , V_38 ) ;
F_23 ( & V_23 -> V_36 , V_38 , 0 ) ;
}
}
static unsigned int F_31 ( struct V_34 * V_23 ,
struct V_24 * V_37 )
{
unsigned int V_38 ;
V_38 = F_21 ( & V_23 -> V_35 ) ;
if ( F_21 ( & V_23 -> V_36 ) == V_38 ) {
F_26 ( & V_23 -> V_35 ) ;
F_26 ( & V_23 -> V_36 ) ;
} else
F_23 ( & V_23 -> V_35 ,
F_21 ( & V_37 [ V_38 ] ) , 0 ) ;
return V_38 ;
}
static void F_32 ( struct V_3 * V_4 ,
unsigned int V_38 )
{
memset ( V_4 -> V_39 + V_38 * V_40 ,
V_41 , V_40 ) ;
F_30 ( & V_4 -> V_42 , V_4 -> V_43 , V_38 ) ;
F_33 ( & V_4 -> V_44 ) ;
}
static void F_34 ( struct V_3 * V_4 )
{
struct V_24 * V_25 ;
unsigned int V_38 ;
V_25 = V_4 -> V_43 ;
while ( ! F_27 ( & V_4 -> V_42 ) ) {
V_38 = F_31 ( & V_4 -> V_42 , V_25 ) ;
F_35 ( & V_4 -> V_45 ) ;
F_15 ( V_4 , V_38 * V_40 ,
V_40 ) ;
F_36 ( & V_4 -> V_45 ) ;
F_17 ( & V_25 [ V_38 ] , V_32 ) ;
F_30 ( & V_4 -> V_46 , V_25 , V_38 ) ;
memset ( V_4 -> V_39 + V_38 * V_40 ,
0 , V_40 ) ;
}
}
static void F_37 ( struct V_47 * V_48 )
{
struct V_3 * V_4 ;
V_4 = F_38 ( V_48 , struct V_3 , V_44 ) ;
F_36 ( & V_4 -> V_45 ) ;
F_34 ( V_4 ) ;
F_35 ( & V_4 -> V_45 ) ;
}
static void F_39 ( struct V_3 * V_49 ,
struct V_24 * V_43 , unsigned long V_50 )
{
unsigned long V_38 = V_50 / V_40 ;
if ( ! V_43 )
return;
if ( F_24 ( & V_43 [ V_38 ] ) ) {
F_40 ( F_28 ( & V_49 -> V_46 ) != V_38 ) ;
F_31 ( & V_49 -> V_46 , V_43 ) ;
F_20 ( & V_43 [ V_38 ] , 0 , 0 ) ;
}
F_40 ( F_18 ( & V_43 [ V_38 ] ) >= V_40 ) ;
F_19 ( & V_43 [ V_38 ] ,
F_18 ( & V_43 [ V_38 ] ) + 1 ) ;
}
static void F_41 ( struct V_3 * V_49 ,
struct V_24 * V_43 , unsigned long V_50 )
{
unsigned long V_38 = V_50 / V_40 ;
if ( ! V_43 )
return;
F_40 ( F_18 ( & V_43 [ V_38 ] ) == 0 ) ;
F_19 ( & V_43 [ V_38 ] ,
F_18 ( & V_43 [ V_38 ] ) - 1 ) ;
if ( F_18 ( & V_43 [ V_38 ] ) == 0 ) {
if ( ( V_49 -> V_27 & ( V_51 | V_52 ) ) ==
( V_51 | V_52 ) ) {
F_32 ( V_49 , V_38 ) ;
return;
}
F_17 ( & V_43 [ V_38 ] , V_32 ) ;
F_30 ( & V_49 -> V_46 , V_43 , V_38 ) ;
}
}
static bool
F_42 ( struct V_3 * V_4 ,
unsigned long V_5 )
{
struct V_53 * V_53 ;
bool V_54 ;
V_5 /= V_40 ;
V_54 = ! F_27 ( & V_4 -> V_46 ) &&
V_5 != F_28 ( & V_4 -> V_46 ) &&
F_24 ( & V_4 -> V_43 [ V_5 ] ) ;
if ( ! V_54 )
return false ;
V_53 = F_43 ( V_4 -> V_53 ) ;
F_26 ( & V_53 -> V_55 ) ;
return true ;
}
static void F_44 ( struct V_3 * V_4 ,
unsigned long * V_5 , unsigned long * V_56 )
{
struct V_53 * V_57 ;
bool V_58 ;
unsigned long V_59 ;
V_60:
V_57 = F_43 ( V_4 -> V_53 ) ;
if ( F_25 ( & V_57 -> V_55 ) ) {
if ( ! F_27 ( & V_4 -> V_46 ) ) {
V_57 -> V_55 = V_4 -> V_46 . V_35 ;
V_57 -> V_61 = F_21 ( & V_57 -> V_55 ) *
V_40 ;
} else if ( ! F_27 ( & V_4 -> V_42 ) ) {
F_34 ( V_4 ) ;
* V_56 = * V_5 = V_4 -> F_21 ;
goto V_60;
} else
return;
}
V_58 = false ;
V_59 = V_57 -> V_61 ;
while ( V_59 < V_4 -> V_62 && V_59 < ( F_21 ( & V_57 -> V_55 ) + 1 ) *
V_40 ) {
if ( ! V_4 -> V_39 [ V_59 ] ) {
V_58 = true ;
break;
}
V_59 ++ ;
}
if ( ! V_58 ) {
F_26 ( & V_57 -> V_55 ) ;
goto V_60;
}
V_57 -> V_61 = V_59 + 1 ;
* V_5 = V_59 ;
* V_56 = V_59 ;
}
static unsigned long F_45 ( struct V_3 * V_4 ,
unsigned char V_63 )
{
unsigned long V_5 ;
unsigned long V_56 ;
unsigned long V_64 = 0 ;
int V_65 = V_66 ;
V_4 -> V_27 += V_67 ;
V_56 = V_5 = V_4 -> F_21 ;
if ( V_4 -> V_43 ) {
F_44 ( V_4 , & V_5 , & V_56 ) ;
goto V_68;
}
if ( F_46 ( ! V_4 -> V_69 -- ) ) {
if ( V_4 -> V_70 - V_4 -> V_71 < V_40 ) {
V_4 -> V_69 = V_40 - 1 ;
goto V_68;
}
F_35 ( & V_4 -> V_45 ) ;
V_56 = V_5 = V_4 -> V_72 ;
V_64 = V_5 + V_40 - 1 ;
for (; V_64 <= V_4 -> V_73 ; V_5 ++ ) {
if ( V_4 -> V_39 [ V_5 ] )
V_64 = V_5 + V_40 ;
else if ( V_5 == V_64 ) {
F_36 ( & V_4 -> V_45 ) ;
V_5 -= V_40 - 1 ;
V_4 -> F_21 = V_5 ;
V_4 -> V_69 = V_40 - 1 ;
goto V_68;
}
if ( F_46 ( -- V_65 < 0 ) ) {
F_13 () ;
V_65 = V_66 ;
}
}
V_5 = V_56 ;
F_36 ( & V_4 -> V_45 ) ;
V_4 -> V_69 = V_40 - 1 ;
}
V_68:
if ( V_4 -> V_43 ) {
while ( F_42 ( V_4 , V_5 ) )
F_44 ( V_4 , & V_5 , & V_56 ) ;
}
if ( ! ( V_4 -> V_27 & V_51 ) )
goto V_74;
if ( ! V_4 -> V_73 )
goto V_74;
if ( V_5 > V_4 -> V_73 )
V_56 = V_5 = V_4 -> V_72 ;
if ( F_47 () && V_4 -> V_39 [ V_5 ] == V_2 ) {
int V_75 ;
F_35 ( & V_4 -> V_45 ) ;
V_75 = F_2 ( V_4 , V_5 ) ;
F_36 ( & V_4 -> V_45 ) ;
if ( V_75 )
goto V_68;
goto V_76;
}
if ( V_4 -> V_39 [ V_5 ] )
goto V_76;
if ( V_5 == V_4 -> V_72 )
V_4 -> V_72 ++ ;
if ( V_5 == V_4 -> V_73 )
V_4 -> V_73 -- ;
V_4 -> V_71 ++ ;
if ( V_4 -> V_71 == V_4 -> V_70 ) {
V_4 -> V_72 = V_4 -> V_62 ;
V_4 -> V_73 = 0 ;
F_36 ( & V_77 ) ;
F_48 ( & V_4 -> V_78 , & V_79 ) ;
F_35 ( & V_77 ) ;
}
V_4 -> V_39 [ V_5 ] = V_63 ;
F_39 ( V_4 , V_4 -> V_43 , V_5 ) ;
V_4 -> F_21 = V_5 + 1 ;
V_4 -> V_27 -= V_67 ;
return V_5 ;
V_76:
F_35 ( & V_4 -> V_45 ) ;
while ( ++ V_5 <= V_4 -> V_73 ) {
if ( ! V_4 -> V_39 [ V_5 ] ) {
F_36 ( & V_4 -> V_45 ) ;
goto V_68;
}
if ( F_47 () && V_4 -> V_39 [ V_5 ] == V_2 ) {
F_36 ( & V_4 -> V_45 ) ;
goto V_68;
}
if ( F_46 ( -- V_65 < 0 ) ) {
F_13 () ;
V_65 = V_66 ;
}
}
V_5 = V_4 -> V_72 ;
while ( V_5 < V_56 ) {
if ( ! V_4 -> V_39 [ V_5 ] ) {
F_36 ( & V_4 -> V_45 ) ;
goto V_68;
}
if ( F_47 () && V_4 -> V_39 [ V_5 ] == V_2 ) {
F_36 ( & V_4 -> V_45 ) ;
goto V_68;
}
if ( F_46 ( -- V_65 < 0 ) ) {
F_13 () ;
V_65 = V_66 ;
}
V_5 ++ ;
}
F_36 ( & V_4 -> V_45 ) ;
V_74:
V_4 -> V_27 -= V_67 ;
return 0 ;
}
T_1 F_49 ( void )
{
struct V_3 * V_4 , * V_61 ;
T_3 V_5 ;
if ( F_50 ( & V_80 ) <= 0 )
goto V_81;
F_51 ( & V_80 ) ;
F_36 ( & V_77 ) ;
V_82:
F_52 (si, next, &swap_avail_head, avail_list) {
F_53 ( & V_4 -> V_78 , & V_79 ) ;
F_35 ( & V_77 ) ;
F_36 ( & V_4 -> V_45 ) ;
if ( ! V_4 -> V_73 || ! ( V_4 -> V_27 & V_51 ) ) {
F_36 ( & V_77 ) ;
if ( F_54 ( & V_4 -> V_78 ) ) {
F_35 ( & V_4 -> V_45 ) ;
goto V_83;
}
F_55 ( ! V_4 -> V_73 ,
L_1 ,
V_4 -> type ) ;
F_55 ( ! ( V_4 -> V_27 & V_51 ) ,
L_2 ,
V_4 -> type ) ;
F_48 ( & V_4 -> V_78 , & V_79 ) ;
F_35 ( & V_4 -> V_45 ) ;
goto V_83;
}
V_5 = F_45 ( V_4 , V_2 ) ;
F_35 ( & V_4 -> V_45 ) ;
if ( V_5 )
return F_3 ( V_4 -> type , V_5 ) ;
F_56 ( L_3 ,
V_4 -> type ) ;
F_36 ( & V_77 ) ;
V_83:
if ( F_54 ( & V_61 -> V_78 ) )
goto V_82;
}
F_35 ( & V_77 ) ;
F_57 ( & V_80 ) ;
V_81:
return ( T_1 ) { 0 } ;
}
T_1 F_58 ( int type )
{
struct V_3 * V_4 ;
T_3 V_5 ;
V_4 = V_84 [ type ] ;
F_36 ( & V_4 -> V_45 ) ;
if ( V_4 && ( V_4 -> V_27 & V_51 ) ) {
F_51 ( & V_80 ) ;
V_5 = F_45 ( V_4 , 1 ) ;
if ( V_5 ) {
F_35 ( & V_4 -> V_45 ) ;
return F_3 ( type , V_5 ) ;
}
F_57 ( & V_80 ) ;
}
F_35 ( & V_4 -> V_45 ) ;
return ( T_1 ) { 0 } ;
}
static struct V_3 * F_59 ( T_1 V_6 )
{
struct V_3 * V_49 ;
unsigned long V_5 , type ;
if ( ! V_6 . V_85 )
goto V_86;
type = F_60 ( V_6 ) ;
if ( type >= V_87 )
goto V_88;
V_49 = V_84 [ type ] ;
if ( ! ( V_49 -> V_27 & V_89 ) )
goto V_90;
V_5 = F_6 ( V_6 ) ;
if ( V_5 >= V_49 -> V_62 )
goto V_91;
if ( ! V_49 -> V_39 [ V_5 ] )
goto V_92;
F_36 ( & V_49 -> V_45 ) ;
return V_49 ;
V_92:
F_61 ( L_4 , V_93 , V_6 . V_85 ) ;
goto V_86;
V_91:
F_61 ( L_4 , V_94 , V_6 . V_85 ) ;
goto V_86;
V_90:
F_61 ( L_4 , V_95 , V_6 . V_85 ) ;
goto V_86;
V_88:
F_61 ( L_4 , V_96 , V_6 . V_85 ) ;
V_86:
return NULL ;
}
static unsigned char F_62 ( struct V_3 * V_49 ,
T_1 V_6 , unsigned char V_63 )
{
unsigned long V_5 = F_6 ( V_6 ) ;
unsigned char V_97 ;
unsigned char V_98 ;
V_97 = V_49 -> V_39 [ V_5 ] ;
V_98 = V_97 & V_2 ;
V_97 &= ~ V_2 ;
if ( V_63 == V_2 ) {
F_40 ( ! V_98 ) ;
V_98 = 0 ;
} else if ( V_97 == V_99 ) {
V_97 = 0 ;
} else if ( ( V_97 & ~ V_100 ) <= V_101 ) {
if ( V_97 == V_100 ) {
if ( F_63 ( V_49 , V_5 , V_97 ) )
V_97 = V_101 | V_100 ;
else
V_97 = V_101 ;
} else
V_97 -- ;
}
V_63 = V_97 | V_98 ;
V_49 -> V_39 [ V_5 ] = V_63 ;
if ( ! V_63 ) {
F_64 ( V_6 ) ;
F_41 ( V_49 , V_49 -> V_43 , V_5 ) ;
if ( V_5 < V_49 -> V_72 )
V_49 -> V_72 = V_5 ;
if ( V_5 > V_49 -> V_73 ) {
bool V_102 = ! V_49 -> V_73 ;
V_49 -> V_73 = V_5 ;
if ( V_102 && ( V_49 -> V_27 & V_51 ) ) {
F_36 ( & V_77 ) ;
F_65 ( ! F_54 ( & V_49 -> V_78 ) ) ;
if ( F_54 ( & V_49 -> V_78 ) )
F_66 ( & V_49 -> V_78 ,
& V_79 ) ;
F_35 ( & V_77 ) ;
}
}
F_57 ( & V_80 ) ;
V_49 -> V_71 -- ;
F_67 ( V_49 -> type , V_5 ) ;
if ( V_49 -> V_27 & V_103 ) {
struct V_104 * V_105 = V_49 -> V_17 -> V_106 ;
if ( V_105 -> V_107 -> V_108 )
V_105 -> V_107 -> V_108 ( V_49 -> V_17 ,
V_5 ) ;
}
}
return V_63 ;
}
void F_68 ( T_1 V_6 )
{
struct V_3 * V_49 ;
V_49 = F_59 ( V_6 ) ;
if ( V_49 ) {
F_62 ( V_49 , V_6 , 1 ) ;
F_35 ( & V_49 -> V_45 ) ;
}
}
void F_69 ( T_1 V_6 )
{
struct V_3 * V_49 ;
V_49 = F_59 ( V_6 ) ;
if ( V_49 ) {
F_62 ( V_49 , V_6 , V_2 ) ;
F_35 ( & V_49 -> V_45 ) ;
}
}
int F_70 ( struct V_7 * V_7 )
{
int V_97 = 0 ;
struct V_3 * V_49 ;
T_1 V_6 ;
V_6 . V_85 = F_71 ( V_7 ) ;
V_49 = F_59 ( V_6 ) ;
if ( V_49 ) {
V_97 = F_1 ( V_49 -> V_39 [ F_6 ( V_6 ) ] ) ;
F_35 ( & V_49 -> V_45 ) ;
}
return V_97 ;
}
int F_72 ( T_1 V_6 )
{
int V_97 , V_109 , V_31 ;
struct V_3 * V_49 ;
struct V_7 * V_7 ;
T_3 V_5 ;
unsigned char * V_110 ;
V_49 = F_59 ( V_6 ) ;
if ( ! V_49 )
return 0 ;
V_97 = F_1 ( V_49 -> V_39 [ F_6 ( V_6 ) ] ) ;
if ( ! ( V_97 & V_100 ) )
goto V_86;
V_97 &= ~ V_100 ;
V_31 = V_101 + 1 ;
V_5 = F_6 ( V_6 ) ;
V_7 = F_73 ( V_49 -> V_39 + V_5 ) ;
V_5 &= ~ V_111 ;
F_40 ( F_71 ( V_7 ) != V_112 ) ;
do {
V_7 = F_16 ( V_7 , V_113 ) ;
V_110 = F_74 ( V_7 ) ;
V_109 = V_110 [ V_5 ] ;
F_75 ( V_110 ) ;
V_97 += ( V_109 & ~ V_100 ) * V_31 ;
V_31 *= ( V_114 + 1 ) ;
} while ( V_109 & V_100 );
V_86:
F_35 ( & V_49 -> V_45 ) ;
return V_97 ;
}
bool F_76 ( struct V_7 * V_7 , int * V_115 )
{
int V_97 ;
F_77 ( ! F_78 ( V_7 ) , V_7 ) ;
if ( F_46 ( F_79 ( V_7 ) ) )
return false ;
V_97 = F_80 ( V_7 , V_115 ) ;
if ( V_97 <= 1 && F_81 ( V_7 ) ) {
V_97 += F_70 ( V_7 ) ;
if ( V_97 == 1 && ! F_82 ( V_7 ) ) {
F_83 ( V_7 ) ;
F_84 ( V_7 ) ;
}
}
return V_97 <= 1 ;
}
int F_8 ( struct V_7 * V_7 )
{
F_77 ( ! F_78 ( V_7 ) , V_7 ) ;
if ( ! F_81 ( V_7 ) )
return 0 ;
if ( F_82 ( V_7 ) )
return 0 ;
if ( F_70 ( V_7 ) )
return 0 ;
if ( F_85 () )
return 0 ;
F_83 ( V_7 ) ;
F_84 ( V_7 ) ;
return 1 ;
}
int F_86 ( T_1 V_6 )
{
struct V_3 * V_49 ;
struct V_7 * V_7 = NULL ;
if ( F_87 ( V_6 ) )
return 1 ;
V_49 = F_59 ( V_6 ) ;
if ( V_49 ) {
if ( F_62 ( V_49 , V_6 , 1 ) == V_2 ) {
V_7 = F_4 ( F_5 ( V_6 ) ,
F_6 ( V_6 ) ) ;
if ( V_7 && ! F_7 ( V_7 ) ) {
F_10 ( V_7 ) ;
V_7 = NULL ;
}
}
F_35 ( & V_49 -> V_45 ) ;
}
if ( V_7 ) {
if ( F_81 ( V_7 ) && ! F_82 ( V_7 ) &&
( ! F_88 ( V_7 ) || F_89 ( V_7 ) ) ) {
F_83 ( V_7 ) ;
F_84 ( V_7 ) ;
}
F_9 ( V_7 ) ;
F_10 ( V_7 ) ;
}
return V_49 != NULL ;
}
int F_90 ( T_4 V_116 , T_2 V_5 , struct V_117 * * V_118 )
{
struct V_117 * V_17 = NULL ;
int type ;
if ( V_116 )
V_17 = F_91 ( V_116 ) ;
F_36 ( & V_119 ) ;
for ( type = 0 ; type < V_87 ; type ++ ) {
struct V_3 * V_120 = V_84 [ type ] ;
if ( ! ( V_120 -> V_27 & V_51 ) )
continue;
if ( ! V_17 ) {
if ( V_118 )
* V_118 = F_92 ( V_120 -> V_17 ) ;
F_35 ( & V_119 ) ;
return type ;
}
if ( V_17 == V_120 -> V_17 ) {
struct V_9 * V_10 = & V_120 -> V_14 ;
if ( V_10 -> V_11 == V_5 ) {
if ( V_118 )
* V_118 = F_92 ( V_120 -> V_17 ) ;
F_35 ( & V_119 ) ;
F_93 ( V_17 ) ;
return type ;
}
}
}
F_35 ( & V_119 ) ;
if ( V_17 )
F_93 ( V_17 ) ;
return - V_121 ;
}
T_2 F_94 ( int type , T_3 V_5 )
{
struct V_117 * V_17 ;
if ( ( unsigned int ) type >= V_87 )
return 0 ;
if ( ! ( V_84 [ type ] -> V_27 & V_51 ) )
return 0 ;
return F_95 ( F_3 ( type , V_5 ) , & V_17 ) ;
}
unsigned int F_96 ( int type , int free )
{
unsigned int V_31 = 0 ;
F_36 ( & V_119 ) ;
if ( ( unsigned int ) type < V_87 ) {
struct V_3 * V_120 = V_84 [ type ] ;
F_36 ( & V_120 -> V_45 ) ;
if ( V_120 -> V_27 & V_51 ) {
V_31 = V_120 -> V_70 ;
if ( free )
V_31 -= V_120 -> V_71 ;
}
F_35 ( & V_120 -> V_45 ) ;
}
F_35 ( & V_119 ) ;
return V_31 ;
}
static inline int F_97 ( T_5 V_122 , T_5 V_123 )
{
return F_98 ( F_99 ( V_122 ) , V_123 ) ;
}
static int F_100 ( struct V_124 * V_125 , T_6 * V_126 ,
unsigned long V_127 , T_1 V_6 , struct V_7 * V_7 )
{
struct V_7 * V_128 ;
struct V_129 * V_130 ;
T_7 * V_131 ;
T_5 * V_122 ;
int V_8 = 1 ;
V_128 = V_7 ;
V_7 = F_101 ( V_7 , V_125 , V_127 ) ;
if ( F_46 ( ! V_7 ) )
return - V_132 ;
if ( F_102 ( V_7 , V_125 -> V_133 , V_18 ,
& V_130 , false ) ) {
V_8 = - V_132 ;
goto V_134;
}
V_122 = F_103 ( V_125 -> V_133 , V_126 , V_127 , & V_131 ) ;
if ( F_46 ( ! F_97 ( * V_122 , F_104 ( V_6 ) ) ) ) {
F_105 ( V_7 , V_130 , false ) ;
V_8 = 0 ;
goto V_86;
}
F_106 ( V_125 -> V_133 , V_135 ) ;
F_107 ( V_125 -> V_133 , V_136 ) ;
F_108 ( V_7 ) ;
F_109 ( V_125 -> V_133 , V_127 , V_122 ,
F_110 ( F_111 ( V_7 , V_125 -> V_137 ) ) ) ;
if ( V_7 == V_128 ) {
F_112 ( V_7 , V_125 , V_127 , false ) ;
F_113 ( V_7 , V_130 , true , false ) ;
} else {
F_114 ( V_7 , V_125 , V_127 , false ) ;
F_113 ( V_7 , V_130 , false , false ) ;
F_115 ( V_7 , V_125 ) ;
}
F_68 ( V_6 ) ;
F_116 ( V_7 ) ;
V_86:
F_117 ( V_122 , V_131 ) ;
V_134:
if ( V_7 != V_128 ) {
F_9 ( V_7 ) ;
F_10 ( V_7 ) ;
}
return V_8 ;
}
static int F_118 ( struct V_124 * V_125 , T_6 * V_126 ,
unsigned long V_127 , unsigned long V_138 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_5 V_123 = F_104 ( V_6 ) ;
T_5 * V_122 ;
int V_8 = 0 ;
V_122 = F_119 ( V_126 , V_127 ) ;
do {
if ( F_46 ( F_97 ( * V_122 , V_123 ) ) ) {
F_120 ( V_122 ) ;
V_8 = F_100 ( V_125 , V_126 , V_127 , V_6 , V_7 ) ;
if ( V_8 )
goto V_86;
V_122 = F_119 ( V_126 , V_127 ) ;
}
} while ( V_122 ++ , V_127 += V_139 , V_127 != V_138 );
F_120 ( V_122 - 1 ) ;
V_86:
return V_8 ;
}
static inline int F_121 ( struct V_124 * V_125 , T_8 * V_140 ,
unsigned long V_127 , unsigned long V_138 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_6 * V_126 ;
unsigned long V_61 ;
int V_8 ;
V_126 = F_122 ( V_140 , V_127 ) ;
do {
V_61 = F_123 ( V_127 , V_138 ) ;
if ( F_124 ( V_126 ) )
continue;
V_8 = F_118 ( V_125 , V_126 , V_127 , V_61 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_126 ++ , V_127 = V_61 , V_127 != V_138 );
return 0 ;
}
static inline int F_125 ( struct V_124 * V_125 , T_9 * V_141 ,
unsigned long V_127 , unsigned long V_138 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_8 * V_140 ;
unsigned long V_61 ;
int V_8 ;
V_140 = F_126 ( V_141 , V_127 ) ;
do {
V_61 = F_127 ( V_127 , V_138 ) ;
if ( F_128 ( V_140 ) )
continue;
V_8 = F_121 ( V_125 , V_140 , V_127 , V_61 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_140 ++ , V_127 = V_61 , V_127 != V_138 );
return 0 ;
}
static int F_129 ( struct V_124 * V_125 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_9 * V_141 ;
unsigned long V_127 , V_138 , V_61 ;
int V_8 ;
if ( F_130 ( V_7 ) ) {
V_127 = F_131 ( V_7 , V_125 ) ;
if ( V_127 == - V_142 )
return 0 ;
else
V_138 = V_127 + V_139 ;
} else {
V_127 = V_125 -> V_143 ;
V_138 = V_125 -> V_144 ;
}
V_141 = F_132 ( V_125 -> V_133 , V_127 ) ;
do {
V_61 = F_133 ( V_127 , V_138 ) ;
if ( F_134 ( V_141 ) )
continue;
V_8 = F_125 ( V_125 , V_141 , V_127 , V_61 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_141 ++ , V_127 = V_61 , V_127 != V_138 );
return 0 ;
}
static int F_135 ( struct V_145 * V_146 ,
T_1 V_6 , struct V_7 * V_7 )
{
struct V_124 * V_125 ;
int V_8 = 0 ;
if ( ! F_136 ( & V_146 -> V_147 ) ) {
F_116 ( V_7 ) ;
F_9 ( V_7 ) ;
F_137 ( & V_146 -> V_147 ) ;
F_138 ( V_7 ) ;
}
for ( V_125 = V_146 -> V_148 ; V_125 ; V_125 = V_125 -> V_149 ) {
if ( V_125 -> V_150 && ( V_8 = F_129 ( V_125 , V_6 , V_7 ) ) )
break;
}
F_139 ( & V_146 -> V_147 ) ;
return ( V_8 < 0 ) ? V_8 : 0 ;
}
static unsigned int F_140 ( struct V_3 * V_4 ,
unsigned int V_151 , bool V_152 )
{
unsigned int V_62 = V_4 -> V_62 ;
unsigned int V_153 = V_151 ;
unsigned char V_97 ;
for (; ; ) {
if ( ++ V_153 >= V_62 ) {
if ( ! V_151 ) {
V_153 = 0 ;
break;
}
V_62 = V_151 + 1 ;
V_151 = 0 ;
V_153 = 1 ;
}
if ( V_152 ) {
if ( F_141 ( V_4 , V_153 ) )
break;
else
continue;
}
V_97 = F_142 ( V_4 -> V_39 [ V_153 ] ) ;
if ( V_97 && F_1 ( V_97 ) != V_41 )
break;
}
return V_153 ;
}
int F_143 ( unsigned int type , bool V_152 ,
unsigned long V_154 )
{
struct V_3 * V_4 = V_84 [ type ] ;
struct V_145 * V_155 ;
volatile unsigned char * V_39 ;
unsigned char V_156 ;
struct V_7 * V_7 ;
T_1 V_6 ;
unsigned int V_153 = 0 ;
int V_157 = 0 ;
V_155 = & V_158 ;
F_144 ( & V_158 . V_159 ) ;
while ( ( V_153 = F_140 ( V_4 , V_153 , V_152 ) ) != 0 ) {
if ( F_145 ( V_160 ) ) {
V_157 = - V_161 ;
break;
}
V_39 = & V_4 -> V_39 [ V_153 ] ;
V_6 = F_3 ( type , V_153 ) ;
V_7 = F_146 ( V_6 ,
V_162 , NULL , 0 ) ;
if ( ! V_7 ) {
V_156 = * V_39 ;
if ( ! V_156 || V_156 == V_41 )
continue;
V_157 = - V_132 ;
break;
}
if ( F_147 ( & V_155 -> V_159 ) == 1 ) {
F_148 ( V_155 ) ;
V_155 = & V_158 ;
F_144 ( & V_158 . V_159 ) ;
}
F_149 ( V_7 ) ;
F_150 ( V_7 ) ;
F_138 ( V_7 ) ;
F_150 ( V_7 ) ;
V_156 = * V_39 ;
if ( F_1 ( V_156 ) == V_99 ) {
V_157 = F_151 ( V_6 , V_7 ) ;
if ( V_157 < 0 )
break;
continue;
}
if ( F_1 ( V_156 ) && V_155 != & V_158 )
V_157 = F_135 ( V_155 , V_6 , V_7 ) ;
if ( F_1 ( * V_39 ) ) {
int V_163 = ( * V_39 >= V_156 ) ;
struct V_164 * V_49 = & V_155 -> V_165 ;
struct V_145 * V_166 = V_155 ;
struct V_145 * V_167 = V_155 ;
struct V_145 * V_146 ;
F_144 ( & V_166 -> V_159 ) ;
F_144 ( & V_167 -> V_159 ) ;
F_36 ( & V_168 ) ;
while ( F_1 ( * V_39 ) && ! V_157 &&
( V_49 = V_49 -> V_61 ) != & V_155 -> V_165 ) {
V_146 = F_152 ( V_49 , struct V_145 , V_165 ) ;
if ( ! F_153 ( & V_146 -> V_159 ) )
continue;
F_35 ( & V_168 ) ;
F_148 ( V_167 ) ;
V_167 = V_146 ;
F_13 () ;
V_156 = * V_39 ;
if ( ! F_1 ( V_156 ) )
;
else if ( V_146 == & V_158 )
V_163 = 1 ;
else
V_157 = F_135 ( V_146 , V_6 , V_7 ) ;
if ( V_163 && * V_39 < V_156 ) {
F_148 ( V_166 ) ;
F_144 ( & V_146 -> V_159 ) ;
V_166 = V_146 ;
V_163 = 0 ;
}
F_36 ( & V_168 ) ;
}
F_35 ( & V_168 ) ;
F_148 ( V_167 ) ;
F_148 ( V_155 ) ;
V_155 = V_166 ;
}
if ( V_157 ) {
F_9 ( V_7 ) ;
F_10 ( V_7 ) ;
break;
}
if ( F_1 ( * V_39 ) &&
F_154 ( V_7 ) && F_81 ( V_7 ) ) {
struct V_169 V_170 = {
. V_171 = V_172 ,
} ;
F_155 ( V_7 , & V_170 ) ;
F_138 ( V_7 ) ;
F_150 ( V_7 ) ;
}
if ( F_81 ( V_7 ) &&
F_156 ( F_71 ( V_7 ) == V_6 . V_85 ) )
F_83 ( V_7 ) ;
F_84 ( V_7 ) ;
F_9 ( V_7 ) ;
F_10 ( V_7 ) ;
F_13 () ;
if ( V_152 && V_154 > 0 ) {
if ( ! -- V_154 )
break;
}
}
F_148 ( V_155 ) ;
return V_157 ;
}
static void F_157 ( void )
{
struct V_164 * V_49 , * V_61 ;
unsigned int type ;
for ( type = 0 ; type < V_87 ; type ++ )
if ( V_84 [ type ] -> V_71 )
return;
F_36 ( & V_168 ) ;
F_158 (p, next, &init_mm.mmlist)
F_159 ( V_49 ) ;
F_35 ( & V_168 ) ;
}
static T_2 F_95 ( T_1 V_6 , struct V_117 * * V_17 )
{
struct V_3 * V_120 ;
struct V_9 * V_173 ;
struct V_9 * V_10 ;
T_3 V_5 ;
V_120 = V_84 [ F_60 ( V_6 ) ] ;
* V_17 = V_120 -> V_17 ;
V_5 = F_6 ( V_6 ) ;
V_173 = V_120 -> V_20 ;
V_10 = V_173 ;
for ( ; ; ) {
if ( V_10 -> V_19 <= V_5 &&
V_5 < ( V_10 -> V_19 + V_10 -> V_16 ) ) {
return V_10 -> V_11 + ( V_5 - V_10 -> V_19 ) ;
}
V_10 = F_16 ( V_10 , V_23 ) ;
V_120 -> V_20 = V_10 ;
F_160 ( V_10 == V_173 ) ;
}
}
T_2 F_161 ( struct V_7 * V_7 , struct V_117 * * V_17 )
{
T_1 V_6 ;
V_6 . V_85 = F_71 ( V_7 ) ;
return F_95 ( V_6 , V_17 ) ;
}
static void F_162 ( struct V_3 * V_120 )
{
while ( ! F_163 ( & V_120 -> V_14 . V_23 ) ) {
struct V_9 * V_10 ;
V_10 = F_164 ( & V_120 -> V_14 . V_23 ,
struct V_9 , V_23 ) ;
F_165 ( & V_10 -> V_23 ) ;
F_166 ( V_10 ) ;
}
if ( V_120 -> V_27 & V_174 ) {
struct V_175 * V_176 = V_120 -> V_176 ;
struct V_177 * V_178 = V_176 -> V_179 ;
V_120 -> V_27 &= ~ V_174 ;
V_178 -> V_180 -> V_181 ( V_176 ) ;
}
}
int
F_167 ( struct V_3 * V_120 , unsigned long V_19 ,
unsigned long V_16 , T_2 V_11 )
{
struct V_9 * V_10 ;
struct V_9 * V_182 ;
struct V_164 * V_183 ;
if ( V_19 == 0 ) {
V_10 = & V_120 -> V_14 ;
V_120 -> V_20 = V_10 ;
V_10 -> V_19 = 0 ;
V_10 -> V_16 = V_16 ;
V_10 -> V_11 = V_11 ;
return 1 ;
} else {
V_183 = V_120 -> V_14 . V_23 . V_151 ;
V_10 = F_152 ( V_183 , struct V_9 , V_23 ) ;
F_160 ( V_10 -> V_19 + V_10 -> V_16 != V_19 ) ;
if ( V_10 -> V_11 + V_10 -> V_16 == V_11 ) {
V_10 -> V_16 += V_16 ;
return 0 ;
}
}
V_182 = F_168 ( sizeof( * V_10 ) , V_18 ) ;
if ( V_182 == NULL )
return - V_132 ;
V_182 -> V_19 = V_19 ;
V_182 -> V_16 = V_16 ;
V_182 -> V_11 = V_11 ;
F_169 ( & V_182 -> V_23 , & V_120 -> V_14 . V_23 ) ;
return 1 ;
}
static int F_170 ( struct V_3 * V_120 , T_2 * V_184 )
{
struct V_175 * V_176 = V_120 -> V_176 ;
struct V_177 * V_178 = V_176 -> V_179 ;
struct V_185 * V_185 = V_178 -> V_186 ;
int V_8 ;
if ( F_171 ( V_185 -> V_187 ) ) {
V_8 = F_167 ( V_120 , 0 , V_120 -> V_62 , 0 ) ;
* V_184 = V_120 -> V_70 ;
return V_8 ;
}
if ( V_178 -> V_180 -> V_188 ) {
V_8 = V_178 -> V_180 -> V_188 ( V_120 , V_176 , V_184 ) ;
if ( ! V_8 ) {
V_120 -> V_27 |= V_174 ;
V_8 = F_167 ( V_120 , 0 , V_120 -> V_62 , 0 ) ;
* V_184 = V_120 -> V_70 ;
}
return V_8 ;
}
return F_172 ( V_120 , V_176 , V_184 ) ;
}
static void F_173 ( struct V_3 * V_49 , int V_189 ,
unsigned char * V_39 ,
struct V_24 * V_43 )
{
if ( V_189 >= 0 )
V_49 -> V_189 = V_189 ;
else
V_49 -> V_189 = -- V_190 ;
V_49 -> V_23 . V_189 = - V_49 -> V_189 ;
V_49 -> V_78 . V_189 = - V_49 -> V_189 ;
V_49 -> V_39 = V_39 ;
V_49 -> V_43 = V_43 ;
V_49 -> V_27 |= V_51 ;
F_174 ( V_49 -> V_70 , & V_80 ) ;
V_191 += V_49 -> V_70 ;
F_175 ( & V_119 ) ;
F_66 ( & V_49 -> V_23 , & V_192 ) ;
F_36 ( & V_77 ) ;
F_66 ( & V_49 -> V_78 , & V_79 ) ;
F_35 ( & V_77 ) ;
}
static void F_176 ( struct V_3 * V_49 , int V_189 ,
unsigned char * V_39 ,
struct V_24 * V_43 ,
unsigned long * V_193 )
{
F_177 ( V_49 -> type , V_193 ) ;
F_36 ( & V_119 ) ;
F_36 ( & V_49 -> V_45 ) ;
F_173 ( V_49 , V_189 , V_39 , V_43 ) ;
F_35 ( & V_49 -> V_45 ) ;
F_35 ( & V_119 ) ;
}
static void F_178 ( struct V_3 * V_49 )
{
F_36 ( & V_119 ) ;
F_36 ( & V_49 -> V_45 ) ;
F_173 ( V_49 , V_49 -> V_189 , V_49 -> V_39 , V_49 -> V_43 ) ;
F_35 ( & V_49 -> V_45 ) ;
F_35 ( & V_119 ) ;
}
static unsigned F_179 ( struct V_175 * V_175 , T_10 * V_194 )
{
struct V_195 * V_196 = V_175 -> V_197 ;
F_180 ( V_175 , & V_198 , V_194 ) ;
if ( V_196 -> V_199 != F_147 ( & V_200 ) ) {
V_196 -> V_199 = F_147 ( & V_200 ) ;
return V_201 | V_202 | V_203 | V_204 ;
}
return V_201 | V_202 ;
}
static void * F_181 ( struct V_195 * V_205 , T_11 * V_206 )
{
struct V_3 * V_4 ;
int type ;
T_11 V_207 = * V_206 ;
F_182 ( & V_208 ) ;
if ( ! V_207 )
return V_209 ;
for ( type = 0 ; type < V_87 ; type ++ ) {
F_183 () ;
V_4 = V_84 [ type ] ;
if ( ! ( V_4 -> V_27 & V_89 ) || ! V_4 -> V_39 )
continue;
if ( ! -- V_207 )
return V_4 ;
}
return NULL ;
}
static void * F_184 ( struct V_195 * V_205 , void * V_210 , T_11 * V_206 )
{
struct V_3 * V_4 = V_210 ;
int type ;
if ( V_210 == V_209 )
type = 0 ;
else
type = V_4 -> type + 1 ;
for (; type < V_87 ; type ++ ) {
F_183 () ;
V_4 = V_84 [ type ] ;
if ( ! ( V_4 -> V_27 & V_89 ) || ! V_4 -> V_39 )
continue;
++ * V_206 ;
return V_4 ;
}
return NULL ;
}
static void F_185 ( struct V_195 * V_205 , void * V_210 )
{
F_186 ( & V_208 ) ;
}
static int F_187 ( struct V_195 * V_205 , void * V_210 )
{
struct V_3 * V_4 = V_210 ;
struct V_175 * V_175 ;
int V_211 ;
if ( V_4 == V_209 ) {
F_188 ( V_205 , L_5 ) ;
return 0 ;
}
V_175 = V_4 -> V_176 ;
V_211 = F_189 ( V_205 , V_175 , L_6 ) ;
F_190 ( V_205 , L_7 ,
V_211 < 40 ? 40 - V_211 : 1 , L_8 ,
F_171 ( F_191 ( V_175 ) -> V_187 ) ?
L_9 : L_10 ,
V_4 -> V_70 << ( V_15 - 10 ) ,
V_4 -> V_71 << ( V_15 - 10 ) ,
V_4 -> V_189 ) ;
return 0 ;
}
static int F_192 ( struct V_185 * V_185 , struct V_175 * V_175 )
{
struct V_195 * V_196 ;
int V_8 ;
V_8 = F_193 ( V_175 , & V_212 ) ;
if ( V_8 )
return V_8 ;
V_196 = V_175 -> V_197 ;
V_196 -> V_199 = F_147 ( & V_200 ) ;
return 0 ;
}
static int T_12 F_194 ( void )
{
F_195 ( L_11 , 0 , NULL , & V_213 ) ;
return 0 ;
}
static int T_12 F_196 ( void )
{
F_197 () ;
return 0 ;
}
static struct V_3 * F_198 ( void )
{
struct V_3 * V_49 ;
unsigned int type ;
V_49 = F_199 ( sizeof( * V_49 ) , V_18 ) ;
if ( ! V_49 )
return F_200 ( - V_132 ) ;
F_36 ( & V_119 ) ;
for ( type = 0 ; type < V_87 ; type ++ ) {
if ( ! ( V_84 [ type ] -> V_27 & V_89 ) )
break;
}
if ( type >= V_214 ) {
F_35 ( & V_119 ) ;
F_166 ( V_49 ) ;
return F_200 ( - V_215 ) ;
}
if ( type >= V_87 ) {
V_49 -> type = type ;
V_84 [ type ] = V_49 ;
F_201 () ;
V_87 ++ ;
} else {
F_166 ( V_49 ) ;
V_49 = V_84 [ type ] ;
}
F_202 ( & V_49 -> V_14 . V_23 ) ;
F_203 ( & V_49 -> V_23 , 0 ) ;
F_203 ( & V_49 -> V_78 , 0 ) ;
V_49 -> V_27 = V_89 ;
F_35 ( & V_119 ) ;
F_204 ( & V_49 -> V_45 ) ;
return V_49 ;
}
static int F_205 ( struct V_3 * V_49 , struct V_185 * V_185 )
{
int error ;
if ( F_171 ( V_185 -> V_187 ) ) {
V_49 -> V_17 = F_92 ( F_206 ( V_185 ) ) ;
error = F_207 ( V_49 -> V_17 ,
V_216 | V_217 | V_218 , V_49 ) ;
if ( error < 0 ) {
V_49 -> V_17 = NULL ;
return error ;
}
V_49 -> V_219 = F_208 ( V_49 -> V_17 ) ;
error = F_209 ( V_49 -> V_17 , V_139 ) ;
if ( error < 0 )
return error ;
V_49 -> V_27 |= V_103 ;
} else if ( F_210 ( V_185 -> V_187 ) ) {
V_49 -> V_17 = V_185 -> V_220 -> V_221 ;
F_211 ( V_185 ) ;
if ( F_212 ( V_185 ) )
return - V_222 ;
} else
return - V_223 ;
return 0 ;
}
static unsigned long F_213 ( struct V_3 * V_49 ,
union V_224 * V_224 ,
struct V_185 * V_185 )
{
int V_153 ;
unsigned long V_225 ;
unsigned long V_226 ;
unsigned long V_227 ;
if ( memcmp ( L_12 , V_224 -> V_228 . V_228 , 10 ) ) {
F_61 ( L_13 ) ;
return 0 ;
}
if ( F_214 ( V_224 -> V_25 . V_229 ) == 1 ) {
F_215 ( & V_224 -> V_25 . V_229 ) ;
F_215 ( & V_224 -> V_25 . V_227 ) ;
F_215 ( & V_224 -> V_25 . V_230 ) ;
if ( V_224 -> V_25 . V_230 > V_231 )
return 0 ;
for ( V_153 = 0 ; V_153 < V_224 -> V_25 . V_230 ; V_153 ++ )
F_215 ( & V_224 -> V_25 . V_232 [ V_153 ] ) ;
}
if ( V_224 -> V_25 . V_229 != 1 ) {
F_216 ( L_14 ,
V_224 -> V_25 . V_229 ) ;
return 0 ;
}
V_49 -> V_72 = 1 ;
V_49 -> F_21 = 1 ;
V_49 -> V_69 = 0 ;
V_225 = F_6 ( F_217 (
F_104 ( F_3 ( 0 , ~ 0UL ) ) ) ) + 1 ;
V_227 = V_224 -> V_25 . V_227 ;
if ( V_227 > V_225 ) {
F_216 ( L_15 ,
V_225 << ( V_15 - 10 ) ,
V_227 << ( V_15 - 10 ) ) ;
}
if ( V_225 > V_227 ) {
V_225 = V_227 + 1 ;
if ( ( unsigned int ) V_225 == 0 )
V_225 = V_233 ;
}
V_49 -> V_73 = V_225 - 1 ;
if ( ! V_225 )
return 0 ;
V_226 = F_218 ( V_185 ) >> V_15 ;
if ( V_226 && V_225 > V_226 ) {
F_216 ( L_16 ) ;
return 0 ;
}
if ( V_224 -> V_25 . V_230 && F_210 ( V_185 -> V_187 ) )
return 0 ;
if ( V_224 -> V_25 . V_230 > V_231 )
return 0 ;
return V_225 ;
}
static int F_219 ( struct V_3 * V_49 ,
union V_224 * V_224 ,
unsigned char * V_39 ,
struct V_24 * V_43 ,
unsigned long V_225 ,
T_2 * V_184 )
{
int V_153 ;
unsigned int V_234 ;
int V_235 ;
unsigned long V_236 = F_220 ( V_225 , V_40 ) ;
unsigned long V_38 = V_49 -> F_21 / V_40 ;
V_234 = V_225 - 1 ;
F_29 ( & V_49 -> V_46 ) ;
F_29 ( & V_49 -> V_42 ) ;
for ( V_153 = 0 ; V_153 < V_224 -> V_25 . V_230 ; V_153 ++ ) {
unsigned int V_50 = V_224 -> V_25 . V_232 [ V_153 ] ;
if ( V_50 == 0 || V_50 > V_224 -> V_25 . V_227 )
return - V_223 ;
if ( V_50 < V_225 ) {
V_39 [ V_50 ] = V_41 ;
V_234 -- ;
F_39 ( V_49 , V_43 , V_50 ) ;
}
}
for ( V_153 = V_225 ; V_153 < F_221 ( V_225 , V_40 ) ; V_153 ++ )
F_39 ( V_49 , V_43 , V_153 ) ;
if ( V_234 ) {
V_39 [ 0 ] = V_41 ;
F_39 ( V_49 , V_43 , 0 ) ;
V_49 -> V_62 = V_225 ;
V_49 -> V_70 = V_234 ;
V_235 = F_170 ( V_49 , V_184 ) ;
if ( V_235 < 0 )
return V_235 ;
V_234 = V_49 -> V_70 ;
}
if ( ! V_234 ) {
F_216 ( L_17 ) ;
return - V_223 ;
}
if ( ! V_43 )
return V_235 ;
for ( V_153 = 0 ; V_153 < V_236 ; V_153 ++ ) {
if ( ! F_18 ( & V_43 [ V_38 ] ) ) {
F_17 ( & V_43 [ V_38 ] , V_32 ) ;
F_30 ( & V_49 -> V_46 , V_43 ,
V_38 ) ;
}
V_38 ++ ;
if ( V_38 == V_236 )
V_38 = 0 ;
}
return V_235 ;
}
static bool F_222 ( struct V_3 * V_4 )
{
struct V_237 * V_238 = F_223 ( V_4 -> V_17 ) ;
if ( ! V_238 || ! F_224 ( V_238 ) )
return false ;
return true ;
}
void F_225 ( struct V_239 * V_85 )
{
unsigned int type ;
unsigned long V_240 = 0 ;
F_36 ( & V_119 ) ;
for ( type = 0 ; type < V_87 ; type ++ ) {
struct V_3 * V_4 = V_84 [ type ] ;
if ( ( V_4 -> V_27 & V_89 ) && ! ( V_4 -> V_27 & V_51 ) )
V_240 += V_4 -> V_71 ;
}
V_85 -> V_241 = F_50 ( & V_80 ) + V_240 ;
V_85 -> V_242 = V_191 + V_240 ;
F_35 ( & V_119 ) ;
}
static int F_226 ( T_1 V_6 , unsigned char V_63 )
{
struct V_3 * V_49 ;
unsigned long V_5 , type ;
unsigned char V_97 ;
unsigned char V_98 ;
int V_13 = - V_223 ;
if ( F_87 ( V_6 ) )
goto V_86;
type = F_60 ( V_6 ) ;
if ( type >= V_87 )
goto V_243;
V_49 = V_84 [ type ] ;
V_5 = F_6 ( V_6 ) ;
F_36 ( & V_49 -> V_45 ) ;
if ( F_46 ( V_5 >= V_49 -> V_62 ) )
goto V_244;
V_97 = V_49 -> V_39 [ V_5 ] ;
if ( F_46 ( F_1 ( V_97 ) == V_41 ) ) {
V_13 = - V_245 ;
goto V_244;
}
V_98 = V_97 & V_2 ;
V_97 &= ~ V_2 ;
V_13 = 0 ;
if ( V_63 == V_2 ) {
if ( ! V_98 && V_97 )
V_98 = V_2 ;
else if ( V_98 )
V_13 = - V_246 ;
else
V_13 = - V_245 ;
} else if ( V_97 || V_98 ) {
if ( ( V_97 & ~ V_100 ) < V_101 )
V_97 += V_63 ;
else if ( ( V_97 & ~ V_100 ) > V_101 )
V_13 = - V_223 ;
else if ( F_63 ( V_49 , V_5 , V_97 ) )
V_97 = V_100 ;
else
V_13 = - V_132 ;
} else
V_13 = - V_245 ;
V_49 -> V_39 [ V_5 ] = V_97 | V_98 ;
V_244:
F_35 ( & V_49 -> V_45 ) ;
V_86:
return V_13 ;
V_243:
F_61 ( L_18 , V_96 , V_6 . V_85 ) ;
goto V_86;
}
void F_227 ( T_1 V_6 )
{
F_226 ( V_6 , V_99 ) ;
}
int F_228 ( T_1 V_6 )
{
int V_13 = 0 ;
while ( ! V_13 && F_226 ( V_6 , 1 ) == - V_132 )
V_13 = F_229 ( V_6 , V_247 ) ;
return V_13 ;
}
int F_230 ( T_1 V_6 )
{
return F_226 ( V_6 , V_2 ) ;
}
struct V_3 * F_231 ( struct V_7 * V_7 )
{
T_1 V_205 = { . V_85 = F_71 (page) } ;
return V_84 [ F_60 ( V_205 ) ] ;
}
struct V_177 * F_232 ( struct V_7 * V_7 )
{
F_77 ( ! F_81 ( V_7 ) , V_7 ) ;
return F_231 ( V_7 ) -> V_176 -> V_179 ;
}
T_3 F_233 ( struct V_7 * V_7 )
{
T_1 V_205 = { . V_85 = F_71 (page) } ;
F_77 ( ! F_81 ( V_7 ) , V_7 ) ;
return F_6 ( V_205 ) ;
}
int F_229 ( T_1 V_6 , T_13 V_248 )
{
struct V_3 * V_4 ;
struct V_7 * V_35 ;
struct V_7 * V_7 ;
struct V_7 * V_249 ;
T_3 V_5 ;
unsigned char V_97 ;
V_7 = F_234 ( V_248 | V_250 ) ;
V_4 = F_59 ( V_6 ) ;
if ( ! V_4 ) {
goto V_251;
}
V_5 = F_6 ( V_6 ) ;
V_97 = V_4 -> V_39 [ V_5 ] & ~ V_2 ;
if ( ( V_97 & ~ V_100 ) != V_101 ) {
goto V_86;
}
if ( ! V_7 ) {
F_35 ( & V_4 -> V_45 ) ;
return - V_132 ;
}
V_35 = F_73 ( V_4 -> V_39 + V_5 ) ;
V_5 &= ~ V_111 ;
if ( ! F_71 ( V_35 ) ) {
F_160 ( V_97 & V_100 ) ;
F_202 ( & V_35 -> V_113 ) ;
F_235 ( V_35 , V_112 ) ;
V_4 -> V_27 |= V_112 ;
}
F_14 (list_page, &head->lru, lru) {
unsigned char * V_110 ;
if ( ! ( V_97 & V_100 ) )
goto V_86;
V_110 = F_74 ( V_249 ) + V_5 ;
V_97 = * V_110 ;
F_75 ( V_110 ) ;
if ( ( V_97 & ~ V_100 ) != V_114 )
goto V_86;
}
F_169 ( & V_7 -> V_113 , & V_35 -> V_113 ) ;
V_7 = NULL ;
V_86:
F_35 ( & V_4 -> V_45 ) ;
V_251:
if ( V_7 )
F_236 ( V_7 ) ;
return 0 ;
}
static bool F_63 ( struct V_3 * V_4 ,
T_3 V_5 , unsigned char V_97 )
{
struct V_7 * V_35 ;
struct V_7 * V_7 ;
unsigned char * V_110 ;
V_35 = F_73 ( V_4 -> V_39 + V_5 ) ;
if ( F_71 ( V_35 ) != V_112 ) {
F_160 ( V_97 & V_100 ) ;
return false ;
}
V_5 &= ~ V_111 ;
V_7 = F_152 ( V_35 -> V_113 . V_61 , struct V_7 , V_113 ) ;
V_110 = F_74 ( V_7 ) + V_5 ;
if ( V_97 == V_101 )
goto V_252;
if ( V_97 == ( V_101 | V_100 ) ) {
while ( * V_110 == ( V_114 | V_100 ) ) {
F_75 ( V_110 ) ;
V_7 = F_152 ( V_7 -> V_113 . V_61 , struct V_7 , V_113 ) ;
F_160 ( V_7 == V_35 ) ;
V_110 = F_74 ( V_7 ) + V_5 ;
}
if ( * V_110 == V_114 ) {
F_75 ( V_110 ) ;
V_7 = F_152 ( V_7 -> V_113 . V_61 , struct V_7 , V_113 ) ;
if ( V_7 == V_35 )
return false ;
V_110 = F_74 ( V_7 ) + V_5 ;
V_252: * V_110 = 0 ;
}
* V_110 += 1 ;
F_75 ( V_110 ) ;
V_7 = F_152 ( V_7 -> V_113 . V_151 , struct V_7 , V_113 ) ;
while ( V_7 != V_35 ) {
V_110 = F_74 ( V_7 ) + V_5 ;
* V_110 = V_100 ;
F_75 ( V_110 ) ;
V_7 = F_152 ( V_7 -> V_113 . V_151 , struct V_7 , V_113 ) ;
}
return true ;
} else {
F_160 ( V_97 != V_100 ) ;
while ( * V_110 == V_100 ) {
F_75 ( V_110 ) ;
V_7 = F_152 ( V_7 -> V_113 . V_61 , struct V_7 , V_113 ) ;
F_160 ( V_7 == V_35 ) ;
V_110 = F_74 ( V_7 ) + V_5 ;
}
F_160 ( * V_110 == 0 ) ;
* V_110 -= 1 ;
if ( * V_110 == 0 )
V_97 = 0 ;
F_75 ( V_110 ) ;
V_7 = F_152 ( V_7 -> V_113 . V_151 , struct V_7 , V_113 ) ;
while ( V_7 != V_35 ) {
V_110 = F_74 ( V_7 ) + V_5 ;
* V_110 = V_114 | V_97 ;
V_97 = V_100 ;
F_75 ( V_110 ) ;
V_7 = F_152 ( V_7 -> V_113 . V_151 , struct V_7 , V_113 ) ;
}
return V_97 == V_100 ;
}
}
static void F_237 ( struct V_3 * V_4 )
{
T_3 V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_62 ; V_5 += V_139 ) {
struct V_7 * V_35 ;
V_35 = F_73 ( V_4 -> V_39 + V_5 ) ;
if ( F_71 ( V_35 ) ) {
struct V_7 * V_7 , * V_61 ;
F_238 (page, next, &head->lru, lru) {
F_165 ( & V_7 -> V_113 ) ;
F_236 ( V_7 ) ;
}
}
}
}
