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
if ( V_97 != 1 )
goto V_86;
if ( ! F_82 ( V_7 ) ) {
F_83 ( V_7 ) ;
F_84 ( V_7 ) ;
} else {
T_1 V_6 ;
struct V_3 * V_49 ;
V_6 . V_85 = F_71 ( V_7 ) ;
V_49 = F_59 ( V_6 ) ;
if ( V_49 -> V_27 & V_116 ) {
F_35 ( & V_49 -> V_45 ) ;
return false ;
}
F_35 ( & V_49 -> V_45 ) ;
}
}
V_86:
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
int F_90 ( T_4 V_117 , T_2 V_5 , struct V_118 * * V_119 )
{
struct V_118 * V_17 = NULL ;
int type ;
if ( V_117 )
V_17 = F_91 ( V_117 ) ;
F_36 ( & V_120 ) ;
for ( type = 0 ; type < V_87 ; type ++ ) {
struct V_3 * V_121 = V_84 [ type ] ;
if ( ! ( V_121 -> V_27 & V_51 ) )
continue;
if ( ! V_17 ) {
if ( V_119 )
* V_119 = F_92 ( V_121 -> V_17 ) ;
F_35 ( & V_120 ) ;
return type ;
}
if ( V_17 == V_121 -> V_17 ) {
struct V_9 * V_10 = & V_121 -> V_14 ;
if ( V_10 -> V_11 == V_5 ) {
if ( V_119 )
* V_119 = F_92 ( V_121 -> V_17 ) ;
F_35 ( & V_120 ) ;
F_93 ( V_17 ) ;
return type ;
}
}
}
F_35 ( & V_120 ) ;
if ( V_17 )
F_93 ( V_17 ) ;
return - V_122 ;
}
T_2 F_94 ( int type , T_3 V_5 )
{
struct V_118 * V_17 ;
if ( ( unsigned int ) type >= V_87 )
return 0 ;
if ( ! ( V_84 [ type ] -> V_27 & V_51 ) )
return 0 ;
return F_95 ( F_3 ( type , V_5 ) , & V_17 ) ;
}
unsigned int F_96 ( int type , int free )
{
unsigned int V_31 = 0 ;
F_36 ( & V_120 ) ;
if ( ( unsigned int ) type < V_87 ) {
struct V_3 * V_121 = V_84 [ type ] ;
F_36 ( & V_121 -> V_45 ) ;
if ( V_121 -> V_27 & V_51 ) {
V_31 = V_121 -> V_70 ;
if ( free )
V_31 -= V_121 -> V_71 ;
}
F_35 ( & V_121 -> V_45 ) ;
}
F_35 ( & V_120 ) ;
return V_31 ;
}
static inline int F_97 ( T_5 V_123 , T_5 V_124 )
{
return F_98 ( F_99 ( V_123 ) , V_124 ) ;
}
static int F_100 ( struct V_125 * V_126 , T_6 * V_127 ,
unsigned long V_128 , T_1 V_6 , struct V_7 * V_7 )
{
struct V_7 * V_129 ;
struct V_130 * V_131 ;
T_7 * V_132 ;
T_5 * V_123 ;
int V_8 = 1 ;
V_129 = V_7 ;
V_7 = F_101 ( V_7 , V_126 , V_128 ) ;
if ( F_46 ( ! V_7 ) )
return - V_133 ;
if ( F_102 ( V_7 , V_126 -> V_134 , V_18 ,
& V_131 , false ) ) {
V_8 = - V_133 ;
goto V_135;
}
V_123 = F_103 ( V_126 -> V_134 , V_127 , V_128 , & V_132 ) ;
if ( F_46 ( ! F_97 ( * V_123 , F_104 ( V_6 ) ) ) ) {
F_105 ( V_7 , V_131 , false ) ;
V_8 = 0 ;
goto V_86;
}
F_106 ( V_126 -> V_134 , V_136 ) ;
F_107 ( V_126 -> V_134 , V_137 ) ;
F_108 ( V_7 ) ;
F_109 ( V_126 -> V_134 , V_128 , V_123 ,
F_110 ( F_111 ( V_7 , V_126 -> V_138 ) ) ) ;
if ( V_7 == V_129 ) {
F_112 ( V_7 , V_126 , V_128 , false ) ;
F_113 ( V_7 , V_131 , true , false ) ;
} else {
F_114 ( V_7 , V_126 , V_128 , false ) ;
F_113 ( V_7 , V_131 , false , false ) ;
F_115 ( V_7 , V_126 ) ;
}
F_68 ( V_6 ) ;
F_116 ( V_7 ) ;
V_86:
F_117 ( V_123 , V_132 ) ;
V_135:
if ( V_7 != V_129 ) {
F_9 ( V_7 ) ;
F_10 ( V_7 ) ;
}
return V_8 ;
}
static int F_118 ( struct V_125 * V_126 , T_6 * V_127 ,
unsigned long V_128 , unsigned long V_139 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_5 V_124 = F_104 ( V_6 ) ;
T_5 * V_123 ;
int V_8 = 0 ;
V_123 = F_119 ( V_127 , V_128 ) ;
do {
if ( F_46 ( F_97 ( * V_123 , V_124 ) ) ) {
F_120 ( V_123 ) ;
V_8 = F_100 ( V_126 , V_127 , V_128 , V_6 , V_7 ) ;
if ( V_8 )
goto V_86;
V_123 = F_119 ( V_127 , V_128 ) ;
}
} while ( V_123 ++ , V_128 += V_140 , V_128 != V_139 );
F_120 ( V_123 - 1 ) ;
V_86:
return V_8 ;
}
static inline int F_121 ( struct V_125 * V_126 , T_8 * V_141 ,
unsigned long V_128 , unsigned long V_139 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_6 * V_127 ;
unsigned long V_61 ;
int V_8 ;
V_127 = F_122 ( V_141 , V_128 ) ;
do {
F_13 () ;
V_61 = F_123 ( V_128 , V_139 ) ;
if ( F_124 ( V_127 ) )
continue;
V_8 = F_118 ( V_126 , V_127 , V_128 , V_61 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_127 ++ , V_128 = V_61 , V_128 != V_139 );
return 0 ;
}
static inline int F_125 ( struct V_125 * V_126 , T_9 * V_142 ,
unsigned long V_128 , unsigned long V_139 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_8 * V_141 ;
unsigned long V_61 ;
int V_8 ;
V_141 = F_126 ( V_142 , V_128 ) ;
do {
V_61 = F_127 ( V_128 , V_139 ) ;
if ( F_128 ( V_141 ) )
continue;
V_8 = F_121 ( V_126 , V_141 , V_128 , V_61 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_141 ++ , V_128 = V_61 , V_128 != V_139 );
return 0 ;
}
static int F_129 ( struct V_125 * V_126 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_9 * V_142 ;
unsigned long V_128 , V_139 , V_61 ;
int V_8 ;
if ( F_130 ( V_7 ) ) {
V_128 = F_131 ( V_7 , V_126 ) ;
if ( V_128 == - V_143 )
return 0 ;
else
V_139 = V_128 + V_140 ;
} else {
V_128 = V_126 -> V_144 ;
V_139 = V_126 -> V_145 ;
}
V_142 = F_132 ( V_126 -> V_134 , V_128 ) ;
do {
V_61 = F_133 ( V_128 , V_139 ) ;
if ( F_134 ( V_142 ) )
continue;
V_8 = F_125 ( V_126 , V_142 , V_128 , V_61 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_142 ++ , V_128 = V_61 , V_128 != V_139 );
return 0 ;
}
static int F_135 ( struct V_146 * V_147 ,
T_1 V_6 , struct V_7 * V_7 )
{
struct V_125 * V_126 ;
int V_8 = 0 ;
if ( ! F_136 ( & V_147 -> V_148 ) ) {
F_116 ( V_7 ) ;
F_9 ( V_7 ) ;
F_137 ( & V_147 -> V_148 ) ;
F_138 ( V_7 ) ;
}
for ( V_126 = V_147 -> V_149 ; V_126 ; V_126 = V_126 -> V_150 ) {
if ( V_126 -> V_151 && ( V_8 = F_129 ( V_126 , V_6 , V_7 ) ) )
break;
F_13 () ;
}
F_139 ( & V_147 -> V_148 ) ;
return ( V_8 < 0 ) ? V_8 : 0 ;
}
static unsigned int F_140 ( struct V_3 * V_4 ,
unsigned int V_152 , bool V_153 )
{
unsigned int V_62 = V_4 -> V_62 ;
unsigned int V_154 = V_152 ;
unsigned char V_97 ;
for (; ; ) {
if ( ++ V_154 >= V_62 ) {
if ( ! V_152 ) {
V_154 = 0 ;
break;
}
V_62 = V_152 + 1 ;
V_152 = 0 ;
V_154 = 1 ;
}
V_97 = F_141 ( V_4 -> V_39 [ V_154 ] ) ;
if ( V_97 && F_1 ( V_97 ) != V_41 )
if ( ! V_153 || F_142 ( V_4 , V_154 ) )
break;
if ( ( V_154 % V_66 ) == 0 )
F_13 () ;
}
return V_154 ;
}
int F_143 ( unsigned int type , bool V_153 ,
unsigned long V_155 )
{
struct V_3 * V_4 = V_84 [ type ] ;
struct V_146 * V_156 ;
volatile unsigned char * V_39 ;
unsigned char V_157 ;
struct V_7 * V_7 ;
T_1 V_6 ;
unsigned int V_154 = 0 ;
int V_158 = 0 ;
V_156 = & V_159 ;
F_144 ( & V_159 . V_160 ) ;
while ( ( V_154 = F_140 ( V_4 , V_154 , V_153 ) ) != 0 ) {
if ( F_145 ( V_161 ) ) {
V_158 = - V_162 ;
break;
}
V_39 = & V_4 -> V_39 [ V_154 ] ;
V_6 = F_3 ( type , V_154 ) ;
V_7 = F_146 ( V_6 ,
V_163 , NULL , 0 ) ;
if ( ! V_7 ) {
V_157 = * V_39 ;
if ( ! V_157 || V_157 == V_41 )
continue;
V_158 = - V_133 ;
break;
}
if ( F_147 ( & V_156 -> V_160 ) == 1 ) {
F_148 ( V_156 ) ;
V_156 = & V_159 ;
F_144 ( & V_159 . V_160 ) ;
}
F_149 ( V_7 ) ;
F_150 ( V_7 ) ;
F_138 ( V_7 ) ;
F_150 ( V_7 ) ;
V_157 = * V_39 ;
if ( F_1 ( V_157 ) == V_99 ) {
V_158 = F_151 ( V_6 , V_7 ) ;
if ( V_158 < 0 )
break;
continue;
}
if ( F_1 ( V_157 ) && V_156 != & V_159 )
V_158 = F_135 ( V_156 , V_6 , V_7 ) ;
if ( F_1 ( * V_39 ) ) {
int V_164 = ( * V_39 >= V_157 ) ;
struct V_165 * V_49 = & V_156 -> V_166 ;
struct V_146 * V_167 = V_156 ;
struct V_146 * V_168 = V_156 ;
struct V_146 * V_147 ;
F_144 ( & V_167 -> V_160 ) ;
F_144 ( & V_168 -> V_160 ) ;
F_36 ( & V_169 ) ;
while ( F_1 ( * V_39 ) && ! V_158 &&
( V_49 = V_49 -> V_61 ) != & V_156 -> V_166 ) {
V_147 = F_152 ( V_49 , struct V_146 , V_166 ) ;
if ( ! F_153 ( & V_147 -> V_160 ) )
continue;
F_35 ( & V_169 ) ;
F_148 ( V_168 ) ;
V_168 = V_147 ;
F_13 () ;
V_157 = * V_39 ;
if ( ! F_1 ( V_157 ) )
;
else if ( V_147 == & V_159 )
V_164 = 1 ;
else
V_158 = F_135 ( V_147 , V_6 , V_7 ) ;
if ( V_164 && * V_39 < V_157 ) {
F_148 ( V_167 ) ;
F_144 ( & V_147 -> V_160 ) ;
V_167 = V_147 ;
V_164 = 0 ;
}
F_36 ( & V_169 ) ;
}
F_35 ( & V_169 ) ;
F_148 ( V_168 ) ;
F_148 ( V_156 ) ;
V_156 = V_167 ;
}
if ( V_158 ) {
F_9 ( V_7 ) ;
F_10 ( V_7 ) ;
break;
}
if ( F_1 ( * V_39 ) &&
F_154 ( V_7 ) && F_81 ( V_7 ) ) {
struct V_170 V_171 = {
. V_172 = V_173 ,
} ;
F_155 ( V_7 , & V_171 ) ;
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
if ( V_153 && V_155 > 0 ) {
if ( ! -- V_155 )
break;
}
}
F_148 ( V_156 ) ;
return V_158 ;
}
static void F_157 ( void )
{
struct V_165 * V_49 , * V_61 ;
unsigned int type ;
for ( type = 0 ; type < V_87 ; type ++ )
if ( V_84 [ type ] -> V_71 )
return;
F_36 ( & V_169 ) ;
F_158 (p, next, &init_mm.mmlist)
F_159 ( V_49 ) ;
F_35 ( & V_169 ) ;
}
static T_2 F_95 ( T_1 V_6 , struct V_118 * * V_17 )
{
struct V_3 * V_121 ;
struct V_9 * V_174 ;
struct V_9 * V_10 ;
T_3 V_5 ;
V_121 = V_84 [ F_60 ( V_6 ) ] ;
* V_17 = V_121 -> V_17 ;
V_5 = F_6 ( V_6 ) ;
V_174 = V_121 -> V_20 ;
V_10 = V_174 ;
for ( ; ; ) {
if ( V_10 -> V_19 <= V_5 &&
V_5 < ( V_10 -> V_19 + V_10 -> V_16 ) ) {
return V_10 -> V_11 + ( V_5 - V_10 -> V_19 ) ;
}
V_10 = F_16 ( V_10 , V_23 ) ;
V_121 -> V_20 = V_10 ;
F_160 ( V_10 == V_174 ) ;
}
}
T_2 F_161 ( struct V_7 * V_7 , struct V_118 * * V_17 )
{
T_1 V_6 ;
V_6 . V_85 = F_71 ( V_7 ) ;
return F_95 ( V_6 , V_17 ) ;
}
static void F_162 ( struct V_3 * V_121 )
{
while ( ! F_163 ( & V_121 -> V_14 . V_23 ) ) {
struct V_9 * V_10 ;
V_10 = F_164 ( & V_121 -> V_14 . V_23 ,
struct V_9 , V_23 ) ;
F_165 ( & V_10 -> V_23 ) ;
F_166 ( V_10 ) ;
}
if ( V_121 -> V_27 & V_175 ) {
struct V_176 * V_177 = V_121 -> V_177 ;
struct V_178 * V_179 = V_177 -> V_180 ;
V_121 -> V_27 &= ~ V_175 ;
V_179 -> V_181 -> V_182 ( V_177 ) ;
}
}
int
F_167 ( struct V_3 * V_121 , unsigned long V_19 ,
unsigned long V_16 , T_2 V_11 )
{
struct V_9 * V_10 ;
struct V_9 * V_183 ;
struct V_165 * V_184 ;
if ( V_19 == 0 ) {
V_10 = & V_121 -> V_14 ;
V_121 -> V_20 = V_10 ;
V_10 -> V_19 = 0 ;
V_10 -> V_16 = V_16 ;
V_10 -> V_11 = V_11 ;
return 1 ;
} else {
V_184 = V_121 -> V_14 . V_23 . V_152 ;
V_10 = F_152 ( V_184 , struct V_9 , V_23 ) ;
F_160 ( V_10 -> V_19 + V_10 -> V_16 != V_19 ) ;
if ( V_10 -> V_11 + V_10 -> V_16 == V_11 ) {
V_10 -> V_16 += V_16 ;
return 0 ;
}
}
V_183 = F_168 ( sizeof( * V_10 ) , V_18 ) ;
if ( V_183 == NULL )
return - V_133 ;
V_183 -> V_19 = V_19 ;
V_183 -> V_16 = V_16 ;
V_183 -> V_11 = V_11 ;
F_169 ( & V_183 -> V_23 , & V_121 -> V_14 . V_23 ) ;
return 1 ;
}
static int F_170 ( struct V_3 * V_121 , T_2 * V_185 )
{
struct V_176 * V_177 = V_121 -> V_177 ;
struct V_178 * V_179 = V_177 -> V_180 ;
struct V_186 * V_186 = V_179 -> V_187 ;
int V_8 ;
if ( F_171 ( V_186 -> V_188 ) ) {
V_8 = F_167 ( V_121 , 0 , V_121 -> V_62 , 0 ) ;
* V_185 = V_121 -> V_70 ;
return V_8 ;
}
if ( V_179 -> V_181 -> V_189 ) {
V_8 = V_179 -> V_181 -> V_189 ( V_121 , V_177 , V_185 ) ;
if ( ! V_8 ) {
V_121 -> V_27 |= V_175 ;
V_8 = F_167 ( V_121 , 0 , V_121 -> V_62 , 0 ) ;
* V_185 = V_121 -> V_70 ;
}
return V_8 ;
}
return F_172 ( V_121 , V_177 , V_185 ) ;
}
static void F_173 ( struct V_3 * V_49 , int V_190 ,
unsigned char * V_39 ,
struct V_24 * V_43 )
{
if ( V_190 >= 0 )
V_49 -> V_190 = V_190 ;
else
V_49 -> V_190 = -- V_191 ;
V_49 -> V_23 . V_190 = - V_49 -> V_190 ;
V_49 -> V_78 . V_190 = - V_49 -> V_190 ;
V_49 -> V_39 = V_39 ;
V_49 -> V_43 = V_43 ;
V_49 -> V_27 |= V_51 ;
F_174 ( V_49 -> V_70 , & V_80 ) ;
V_192 += V_49 -> V_70 ;
F_175 ( & V_120 ) ;
F_66 ( & V_49 -> V_23 , & V_193 ) ;
F_36 ( & V_77 ) ;
F_66 ( & V_49 -> V_78 , & V_79 ) ;
F_35 ( & V_77 ) ;
}
static void F_176 ( struct V_3 * V_49 , int V_190 ,
unsigned char * V_39 ,
struct V_24 * V_43 ,
unsigned long * V_194 )
{
F_177 ( V_49 -> type , V_194 ) ;
F_36 ( & V_120 ) ;
F_36 ( & V_49 -> V_45 ) ;
F_173 ( V_49 , V_190 , V_39 , V_43 ) ;
F_35 ( & V_49 -> V_45 ) ;
F_35 ( & V_120 ) ;
}
static void F_178 ( struct V_3 * V_49 )
{
F_36 ( & V_120 ) ;
F_36 ( & V_49 -> V_45 ) ;
F_173 ( V_49 , V_49 -> V_190 , V_49 -> V_39 , V_49 -> V_43 ) ;
F_35 ( & V_49 -> V_45 ) ;
F_35 ( & V_120 ) ;
}
static unsigned F_179 ( struct V_176 * V_176 , T_10 * V_195 )
{
struct V_196 * V_197 = V_176 -> V_198 ;
F_180 ( V_176 , & V_199 , V_195 ) ;
if ( V_197 -> V_200 != F_147 ( & V_201 ) ) {
V_197 -> V_200 = F_147 ( & V_201 ) ;
return V_202 | V_203 | V_204 | V_205 ;
}
return V_202 | V_203 ;
}
static void * F_181 ( struct V_196 * V_206 , T_11 * V_207 )
{
struct V_3 * V_4 ;
int type ;
T_11 V_208 = * V_207 ;
F_182 ( & V_209 ) ;
if ( ! V_208 )
return V_210 ;
for ( type = 0 ; type < V_87 ; type ++ ) {
F_183 () ;
V_4 = V_84 [ type ] ;
if ( ! ( V_4 -> V_27 & V_89 ) || ! V_4 -> V_39 )
continue;
if ( ! -- V_208 )
return V_4 ;
}
return NULL ;
}
static void * F_184 ( struct V_196 * V_206 , void * V_211 , T_11 * V_207 )
{
struct V_3 * V_4 = V_211 ;
int type ;
if ( V_211 == V_210 )
type = 0 ;
else
type = V_4 -> type + 1 ;
for (; type < V_87 ; type ++ ) {
F_183 () ;
V_4 = V_84 [ type ] ;
if ( ! ( V_4 -> V_27 & V_89 ) || ! V_4 -> V_39 )
continue;
++ * V_207 ;
return V_4 ;
}
return NULL ;
}
static void F_185 ( struct V_196 * V_206 , void * V_211 )
{
F_186 ( & V_209 ) ;
}
static int F_187 ( struct V_196 * V_206 , void * V_211 )
{
struct V_3 * V_4 = V_211 ;
struct V_176 * V_176 ;
int V_212 ;
if ( V_4 == V_210 ) {
F_188 ( V_206 , L_5 ) ;
return 0 ;
}
V_176 = V_4 -> V_177 ;
V_212 = F_189 ( V_206 , V_176 , L_6 ) ;
F_190 ( V_206 , L_7 ,
V_212 < 40 ? 40 - V_212 : 1 , L_8 ,
F_171 ( F_191 ( V_176 ) -> V_188 ) ?
L_9 : L_10 ,
V_4 -> V_70 << ( V_15 - 10 ) ,
V_4 -> V_71 << ( V_15 - 10 ) ,
V_4 -> V_190 ) ;
return 0 ;
}
static int F_192 ( struct V_186 * V_186 , struct V_176 * V_176 )
{
struct V_196 * V_197 ;
int V_8 ;
V_8 = F_193 ( V_176 , & V_213 ) ;
if ( V_8 )
return V_8 ;
V_197 = V_176 -> V_198 ;
V_197 -> V_200 = F_147 ( & V_201 ) ;
return 0 ;
}
static int T_12 F_194 ( void )
{
F_195 ( L_11 , 0 , NULL , & V_214 ) ;
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
return F_200 ( - V_133 ) ;
F_36 ( & V_120 ) ;
for ( type = 0 ; type < V_87 ; type ++ ) {
if ( ! ( V_84 [ type ] -> V_27 & V_89 ) )
break;
}
if ( type >= V_215 ) {
F_35 ( & V_120 ) ;
F_166 ( V_49 ) ;
return F_200 ( - V_216 ) ;
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
F_35 ( & V_120 ) ;
F_204 ( & V_49 -> V_45 ) ;
return V_49 ;
}
static int F_205 ( struct V_3 * V_49 , struct V_186 * V_186 )
{
int error ;
if ( F_171 ( V_186 -> V_188 ) ) {
V_49 -> V_17 = F_92 ( F_206 ( V_186 ) ) ;
error = F_207 ( V_49 -> V_17 ,
V_217 | V_218 | V_219 , V_49 ) ;
if ( error < 0 ) {
V_49 -> V_17 = NULL ;
return error ;
}
V_49 -> V_220 = F_208 ( V_49 -> V_17 ) ;
error = F_209 ( V_49 -> V_17 , V_140 ) ;
if ( error < 0 )
return error ;
V_49 -> V_27 |= V_103 ;
} else if ( F_210 ( V_186 -> V_188 ) ) {
V_49 -> V_17 = V_186 -> V_221 -> V_222 ;
F_211 ( V_186 ) ;
if ( F_212 ( V_186 ) )
return - V_223 ;
} else
return - V_224 ;
return 0 ;
}
static unsigned long F_213 ( struct V_3 * V_49 ,
union V_225 * V_225 ,
struct V_186 * V_186 )
{
int V_154 ;
unsigned long V_226 ;
unsigned long V_227 ;
unsigned long V_228 ;
if ( memcmp ( L_12 , V_225 -> V_229 . V_229 , 10 ) ) {
F_61 ( L_13 ) ;
return 0 ;
}
if ( F_214 ( V_225 -> V_25 . V_230 ) == 1 ) {
F_215 ( & V_225 -> V_25 . V_230 ) ;
F_215 ( & V_225 -> V_25 . V_228 ) ;
F_215 ( & V_225 -> V_25 . V_231 ) ;
if ( V_225 -> V_25 . V_231 > V_232 )
return 0 ;
for ( V_154 = 0 ; V_154 < V_225 -> V_25 . V_231 ; V_154 ++ )
F_215 ( & V_225 -> V_25 . V_233 [ V_154 ] ) ;
}
if ( V_225 -> V_25 . V_230 != 1 ) {
F_216 ( L_14 ,
V_225 -> V_25 . V_230 ) ;
return 0 ;
}
V_49 -> V_72 = 1 ;
V_49 -> F_21 = 1 ;
V_49 -> V_69 = 0 ;
V_226 = F_6 ( F_217 (
F_104 ( F_3 ( 0 , ~ 0UL ) ) ) ) + 1 ;
V_228 = V_225 -> V_25 . V_228 ;
if ( V_228 > V_226 ) {
F_216 ( L_15 ,
V_226 << ( V_15 - 10 ) ,
V_228 << ( V_15 - 10 ) ) ;
}
if ( V_226 > V_228 ) {
V_226 = V_228 + 1 ;
if ( ( unsigned int ) V_226 == 0 )
V_226 = V_234 ;
}
V_49 -> V_73 = V_226 - 1 ;
if ( ! V_226 )
return 0 ;
V_227 = F_218 ( V_186 ) >> V_15 ;
if ( V_227 && V_226 > V_227 ) {
F_216 ( L_16 ) ;
return 0 ;
}
if ( V_225 -> V_25 . V_231 && F_210 ( V_186 -> V_188 ) )
return 0 ;
if ( V_225 -> V_25 . V_231 > V_232 )
return 0 ;
return V_226 ;
}
static int F_219 ( struct V_3 * V_49 ,
union V_225 * V_225 ,
unsigned char * V_39 ,
struct V_24 * V_43 ,
unsigned long V_226 ,
T_2 * V_185 )
{
int V_154 ;
unsigned int V_235 ;
int V_236 ;
unsigned long V_237 = F_220 ( V_226 , V_40 ) ;
unsigned long V_38 = V_49 -> F_21 / V_40 ;
V_235 = V_226 - 1 ;
F_29 ( & V_49 -> V_46 ) ;
F_29 ( & V_49 -> V_42 ) ;
for ( V_154 = 0 ; V_154 < V_225 -> V_25 . V_231 ; V_154 ++ ) {
unsigned int V_50 = V_225 -> V_25 . V_233 [ V_154 ] ;
if ( V_50 == 0 || V_50 > V_225 -> V_25 . V_228 )
return - V_224 ;
if ( V_50 < V_226 ) {
V_39 [ V_50 ] = V_41 ;
V_235 -- ;
F_39 ( V_49 , V_43 , V_50 ) ;
}
}
for ( V_154 = V_226 ; V_154 < F_221 ( V_226 , V_40 ) ; V_154 ++ )
F_39 ( V_49 , V_43 , V_154 ) ;
if ( V_235 ) {
V_39 [ 0 ] = V_41 ;
F_39 ( V_49 , V_43 , 0 ) ;
V_49 -> V_62 = V_226 ;
V_49 -> V_70 = V_235 ;
V_236 = F_170 ( V_49 , V_185 ) ;
if ( V_236 < 0 )
return V_236 ;
V_235 = V_49 -> V_70 ;
}
if ( ! V_235 ) {
F_216 ( L_17 ) ;
return - V_224 ;
}
if ( ! V_43 )
return V_236 ;
for ( V_154 = 0 ; V_154 < V_237 ; V_154 ++ ) {
if ( ! F_18 ( & V_43 [ V_38 ] ) ) {
F_17 ( & V_43 [ V_38 ] , V_32 ) ;
F_30 ( & V_49 -> V_46 , V_43 ,
V_38 ) ;
}
V_38 ++ ;
if ( V_38 == V_237 )
V_38 = 0 ;
}
return V_236 ;
}
static bool F_222 ( struct V_3 * V_4 )
{
struct V_238 * V_239 = F_223 ( V_4 -> V_17 ) ;
if ( ! V_239 || ! F_224 ( V_239 ) )
return false ;
return true ;
}
void F_225 ( struct V_240 * V_85 )
{
unsigned int type ;
unsigned long V_241 = 0 ;
F_36 ( & V_120 ) ;
for ( type = 0 ; type < V_87 ; type ++ ) {
struct V_3 * V_4 = V_84 [ type ] ;
if ( ( V_4 -> V_27 & V_89 ) && ! ( V_4 -> V_27 & V_51 ) )
V_241 += V_4 -> V_71 ;
}
V_85 -> V_242 = F_50 ( & V_80 ) + V_241 ;
V_85 -> V_243 = V_192 + V_241 ;
F_35 ( & V_120 ) ;
}
static int F_226 ( T_1 V_6 , unsigned char V_63 )
{
struct V_3 * V_49 ;
unsigned long V_5 , type ;
unsigned char V_97 ;
unsigned char V_98 ;
int V_13 = - V_224 ;
if ( F_87 ( V_6 ) )
goto V_86;
type = F_60 ( V_6 ) ;
if ( type >= V_87 )
goto V_244;
V_49 = V_84 [ type ] ;
V_5 = F_6 ( V_6 ) ;
F_36 ( & V_49 -> V_45 ) ;
if ( F_46 ( V_5 >= V_49 -> V_62 ) )
goto V_245;
V_97 = V_49 -> V_39 [ V_5 ] ;
if ( F_46 ( F_1 ( V_97 ) == V_41 ) ) {
V_13 = - V_246 ;
goto V_245;
}
V_98 = V_97 & V_2 ;
V_97 &= ~ V_2 ;
V_13 = 0 ;
if ( V_63 == V_2 ) {
if ( ! V_98 && V_97 )
V_98 = V_2 ;
else if ( V_98 )
V_13 = - V_247 ;
else
V_13 = - V_246 ;
} else if ( V_97 || V_98 ) {
if ( ( V_97 & ~ V_100 ) < V_101 )
V_97 += V_63 ;
else if ( ( V_97 & ~ V_100 ) > V_101 )
V_13 = - V_224 ;
else if ( F_63 ( V_49 , V_5 , V_97 ) )
V_97 = V_100 ;
else
V_13 = - V_133 ;
} else
V_13 = - V_246 ;
V_49 -> V_39 [ V_5 ] = V_97 | V_98 ;
V_245:
F_35 ( & V_49 -> V_45 ) ;
V_86:
return V_13 ;
V_244:
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
while ( ! V_13 && F_226 ( V_6 , 1 ) == - V_133 )
V_13 = F_229 ( V_6 , V_248 ) ;
return V_13 ;
}
int F_230 ( T_1 V_6 )
{
return F_226 ( V_6 , V_2 ) ;
}
struct V_3 * F_231 ( struct V_7 * V_7 )
{
T_1 V_206 = { . V_85 = F_71 (page) } ;
return V_84 [ F_60 ( V_206 ) ] ;
}
struct V_178 * F_232 ( struct V_7 * V_7 )
{
F_77 ( ! F_81 ( V_7 ) , V_7 ) ;
return F_231 ( V_7 ) -> V_177 -> V_180 ;
}
T_3 F_233 ( struct V_7 * V_7 )
{
T_1 V_206 = { . V_85 = F_71 (page) } ;
F_77 ( ! F_81 ( V_7 ) , V_7 ) ;
return F_6 ( V_206 ) ;
}
int F_229 ( T_1 V_6 , T_13 V_249 )
{
struct V_3 * V_4 ;
struct V_7 * V_35 ;
struct V_7 * V_7 ;
struct V_7 * V_250 ;
T_3 V_5 ;
unsigned char V_97 ;
V_7 = F_234 ( V_249 | V_251 ) ;
V_4 = F_59 ( V_6 ) ;
if ( ! V_4 ) {
goto V_252;
}
V_5 = F_6 ( V_6 ) ;
V_97 = V_4 -> V_39 [ V_5 ] & ~ V_2 ;
if ( ( V_97 & ~ V_100 ) != V_101 ) {
goto V_86;
}
if ( ! V_7 ) {
F_35 ( & V_4 -> V_45 ) ;
return - V_133 ;
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
V_110 = F_74 ( V_250 ) + V_5 ;
V_97 = * V_110 ;
F_75 ( V_110 ) ;
if ( ( V_97 & ~ V_100 ) != V_114 )
goto V_86;
}
F_169 ( & V_7 -> V_113 , & V_35 -> V_113 ) ;
V_7 = NULL ;
V_86:
F_35 ( & V_4 -> V_45 ) ;
V_252:
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
goto V_253;
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
V_253: * V_110 = 0 ;
}
* V_110 += 1 ;
F_75 ( V_110 ) ;
V_7 = F_152 ( V_7 -> V_113 . V_152 , struct V_7 , V_113 ) ;
while ( V_7 != V_35 ) {
V_110 = F_74 ( V_7 ) + V_5 ;
* V_110 = V_100 ;
F_75 ( V_110 ) ;
V_7 = F_152 ( V_7 -> V_113 . V_152 , struct V_7 , V_113 ) ;
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
V_7 = F_152 ( V_7 -> V_113 . V_152 , struct V_7 , V_113 ) ;
while ( V_7 != V_35 ) {
V_110 = F_74 ( V_7 ) + V_5 ;
* V_110 = V_114 | V_97 ;
V_97 = V_100 ;
F_75 ( V_110 ) ;
V_7 = F_152 ( V_7 -> V_113 . V_152 , struct V_7 , V_113 ) ;
}
return V_97 == V_100 ;
}
}
static void F_237 ( struct V_3 * V_4 )
{
T_3 V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_62 ; V_5 += V_140 ) {
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
