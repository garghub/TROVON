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
V_7 = F_4 ( F_5 ( V_6 ) , V_6 . V_9 ) ;
if ( ! V_7 )
return 0 ;
if ( F_6 ( V_7 ) ) {
V_8 = F_7 ( V_7 ) ;
F_8 ( V_7 ) ;
}
F_9 ( V_7 ) ;
return V_8 ;
}
static int F_10 ( struct V_3 * V_4 )
{
struct V_10 * V_11 ;
T_2 V_12 ;
T_2 V_13 ;
int V_14 = 0 ;
V_11 = & V_4 -> V_15 ;
V_12 = ( V_11 -> V_12 + 1 ) << ( V_16 - 9 ) ;
V_13 = ( ( T_2 ) V_11 -> V_17 - 1 ) << ( V_16 - 9 ) ;
if ( V_13 ) {
V_14 = F_11 ( V_4 -> V_18 , V_12 ,
V_13 , V_19 , 0 ) ;
if ( V_14 )
return V_14 ;
F_12 () ;
}
F_13 (se, &si->first_swap_extent.list, list) {
V_12 = V_11 -> V_12 << ( V_16 - 9 ) ;
V_13 = ( T_2 ) V_11 -> V_17 << ( V_16 - 9 ) ;
V_14 = F_11 ( V_4 -> V_18 , V_12 ,
V_13 , V_19 , 0 ) ;
if ( V_14 )
break;
F_12 () ;
}
return V_14 ;
}
static void F_14 ( struct V_3 * V_4 ,
T_3 V_20 , T_3 V_17 )
{
struct V_10 * V_11 = V_4 -> V_21 ;
int V_22 = 0 ;
while ( V_17 ) {
if ( V_11 -> V_20 <= V_20 &&
V_20 < V_11 -> V_20 + V_11 -> V_17 ) {
T_3 V_5 = V_20 - V_11 -> V_20 ;
T_2 V_12 = V_11 -> V_12 + V_5 ;
T_2 V_13 = V_11 -> V_17 - V_5 ;
if ( V_13 > V_17 )
V_13 = V_17 ;
V_20 += V_13 ;
V_17 -= V_13 ;
if ( ! V_22 ++ )
V_4 -> V_21 = V_11 ;
V_12 <<= V_16 - 9 ;
V_13 <<= V_16 - 9 ;
if ( F_11 ( V_4 -> V_18 , V_12 ,
V_13 , V_23 , 0 ) )
break;
}
V_11 = F_15 ( V_11 , V_24 ) ;
}
}
static inline void F_16 ( struct V_25 * V_26 ,
unsigned int V_27 )
{
V_26 -> V_28 = V_27 ;
}
static inline unsigned int F_17 ( struct V_25 * V_26 )
{
return V_26 -> V_29 ;
}
static inline void F_18 ( struct V_25 * V_26 ,
unsigned int V_30 )
{
V_26 -> V_29 = V_30 ;
}
static inline void F_19 ( struct V_25 * V_26 ,
unsigned int V_30 , unsigned int V_31 )
{
V_26 -> V_28 = V_31 ;
V_26 -> V_29 = V_30 ;
}
static inline unsigned int F_20 ( struct V_25 * V_26 )
{
return V_26 -> V_29 ;
}
static inline void F_21 ( struct V_25 * V_26 ,
unsigned int V_32 )
{
V_26 -> V_29 = V_32 ;
}
static inline void F_22 ( struct V_25 * V_26 ,
unsigned int V_32 , unsigned int V_31 )
{
V_26 -> V_28 = V_31 ;
V_26 -> V_29 = V_32 ;
}
static inline bool F_23 ( struct V_25 * V_26 )
{
return V_26 -> V_28 & V_33 ;
}
static inline bool F_24 ( struct V_25 * V_26 )
{
return V_26 -> V_28 & V_34 ;
}
static inline void F_25 ( struct V_25 * V_26 )
{
V_26 -> V_28 = V_34 ;
V_26 -> V_29 = 0 ;
}
static void F_26 ( struct V_3 * V_4 ,
unsigned int V_35 )
{
memset ( V_4 -> V_36 + V_35 * V_37 ,
V_38 , V_37 ) ;
if ( F_24 ( & V_4 -> V_39 ) ) {
F_22 ( & V_4 -> V_39 ,
V_35 , 0 ) ;
F_22 ( & V_4 -> V_40 ,
V_35 , 0 ) ;
} else {
unsigned int V_41 = F_20 ( & V_4 -> V_40 ) ;
F_21 ( & V_4 -> V_42 [ V_41 ] , V_35 ) ;
F_22 ( & V_4 -> V_40 ,
V_35 , 0 ) ;
}
F_27 ( & V_4 -> V_43 ) ;
}
static void F_28 ( struct V_3 * V_4 )
{
struct V_25 * V_26 ;
unsigned int V_35 ;
V_26 = V_4 -> V_42 ;
while ( ! F_24 ( & V_4 -> V_39 ) ) {
V_35 = F_20 ( & V_4 -> V_39 ) ;
F_22 ( & V_4 -> V_39 ,
F_20 ( & V_26 [ V_35 ] ) , 0 ) ;
if ( F_20 ( & V_4 -> V_40 ) == V_35 ) {
F_25 ( & V_4 -> V_39 ) ;
F_25 ( & V_4 -> V_40 ) ;
}
F_29 ( & V_4 -> V_44 ) ;
F_14 ( V_4 , V_35 * V_37 ,
V_37 ) ;
F_30 ( & V_4 -> V_44 ) ;
F_16 ( & V_26 [ V_35 ] , V_33 ) ;
if ( F_24 ( & V_4 -> V_45 ) ) {
F_22 ( & V_4 -> V_45 ,
V_35 , 0 ) ;
F_22 ( & V_4 -> V_46 ,
V_35 , 0 ) ;
} else {
unsigned int V_41 ;
V_41 = F_20 ( & V_4 -> V_46 ) ;
F_21 ( & V_26 [ V_41 ] , V_35 ) ;
F_22 ( & V_4 -> V_46 ,
V_35 , 0 ) ;
}
memset ( V_4 -> V_36 + V_35 * V_37 ,
0 , V_37 ) ;
}
}
static void F_31 ( struct V_47 * V_48 )
{
struct V_3 * V_4 ;
V_4 = F_32 ( V_48 , struct V_3 , V_43 ) ;
F_30 ( & V_4 -> V_44 ) ;
F_28 ( V_4 ) ;
F_29 ( & V_4 -> V_44 ) ;
}
static void F_33 ( struct V_3 * V_49 ,
struct V_25 * V_42 , unsigned long V_50 )
{
unsigned long V_35 = V_50 / V_37 ;
if ( ! V_42 )
return;
if ( F_23 ( & V_42 [ V_35 ] ) ) {
F_34 ( F_20 ( & V_49 -> V_45 ) != V_35 ) ;
F_22 ( & V_49 -> V_45 ,
F_20 ( & V_42 [ V_35 ] ) , 0 ) ;
if ( F_20 ( & V_49 -> V_46 ) == V_35 ) {
F_25 ( & V_49 -> V_46 ) ;
F_25 ( & V_49 -> V_45 ) ;
}
F_19 ( & V_42 [ V_35 ] , 0 , 0 ) ;
}
F_34 ( F_17 ( & V_42 [ V_35 ] ) >= V_37 ) ;
F_18 ( & V_42 [ V_35 ] ,
F_17 ( & V_42 [ V_35 ] ) + 1 ) ;
}
static void F_35 ( struct V_3 * V_49 ,
struct V_25 * V_42 , unsigned long V_50 )
{
unsigned long V_35 = V_50 / V_37 ;
if ( ! V_42 )
return;
F_34 ( F_17 ( & V_42 [ V_35 ] ) == 0 ) ;
F_18 ( & V_42 [ V_35 ] ,
F_17 ( & V_42 [ V_35 ] ) - 1 ) ;
if ( F_17 ( & V_42 [ V_35 ] ) == 0 ) {
if ( ( V_49 -> V_28 & ( V_51 | V_52 ) ) ==
( V_51 | V_52 ) ) {
F_26 ( V_49 , V_35 ) ;
return;
}
F_16 ( & V_42 [ V_35 ] , V_33 ) ;
if ( F_24 ( & V_49 -> V_45 ) ) {
F_22 ( & V_49 -> V_45 , V_35 , 0 ) ;
F_22 ( & V_49 -> V_46 , V_35 , 0 ) ;
} else {
unsigned int V_41 = F_20 ( & V_49 -> V_46 ) ;
F_21 ( & V_42 [ V_41 ] , V_35 ) ;
F_22 ( & V_49 -> V_46 , V_35 , 0 ) ;
}
}
}
static bool
F_36 ( struct V_3 * V_4 ,
unsigned long V_5 )
{
struct V_53 * V_53 ;
bool V_54 ;
V_5 /= V_37 ;
V_54 = ! F_24 ( & V_4 -> V_45 ) &&
V_5 != F_20 ( & V_4 -> V_45 ) &&
F_23 ( & V_4 -> V_42 [ V_5 ] ) ;
if ( ! V_54 )
return false ;
V_53 = F_37 ( V_4 -> V_53 ) ;
F_25 ( & V_53 -> V_55 ) ;
return true ;
}
static void F_38 ( struct V_3 * V_4 ,
unsigned long * V_5 , unsigned long * V_56 )
{
struct V_53 * V_57 ;
bool V_58 ;
unsigned long V_59 ;
V_60:
V_57 = F_37 ( V_4 -> V_53 ) ;
if ( F_24 ( & V_57 -> V_55 ) ) {
if ( ! F_24 ( & V_4 -> V_45 ) ) {
V_57 -> V_55 = V_4 -> V_45 ;
V_57 -> V_61 = F_20 ( & V_57 -> V_55 ) *
V_37 ;
} else if ( ! F_24 ( & V_4 -> V_39 ) ) {
F_28 ( V_4 ) ;
* V_56 = * V_5 = V_4 -> F_20 ;
goto V_60;
} else
return;
}
V_58 = false ;
V_59 = V_57 -> V_61 ;
while ( V_59 < V_4 -> V_62 && V_59 < ( F_20 ( & V_57 -> V_55 ) + 1 ) *
V_37 ) {
if ( ! V_4 -> V_36 [ V_59 ] ) {
V_58 = true ;
break;
}
V_59 ++ ;
}
if ( ! V_58 ) {
F_25 ( & V_57 -> V_55 ) ;
goto V_60;
}
V_57 -> V_61 = V_59 + 1 ;
* V_5 = V_59 ;
* V_56 = V_59 ;
}
static unsigned long F_39 ( struct V_3 * V_4 ,
unsigned char V_63 )
{
unsigned long V_5 ;
unsigned long V_56 ;
unsigned long V_64 = 0 ;
int V_65 = V_66 ;
V_4 -> V_28 += V_67 ;
V_56 = V_5 = V_4 -> F_20 ;
if ( V_4 -> V_42 ) {
F_38 ( V_4 , & V_5 , & V_56 ) ;
goto V_68;
}
if ( F_40 ( ! V_4 -> V_69 -- ) ) {
if ( V_4 -> V_70 - V_4 -> V_71 < V_37 ) {
V_4 -> V_69 = V_37 - 1 ;
goto V_68;
}
F_29 ( & V_4 -> V_44 ) ;
V_56 = V_5 = V_4 -> V_72 ;
V_64 = V_5 + V_37 - 1 ;
for (; V_64 <= V_4 -> V_73 ; V_5 ++ ) {
if ( V_4 -> V_36 [ V_5 ] )
V_64 = V_5 + V_37 ;
else if ( V_5 == V_64 ) {
F_30 ( & V_4 -> V_44 ) ;
V_5 -= V_37 - 1 ;
V_4 -> F_20 = V_5 ;
V_4 -> V_69 = V_37 - 1 ;
goto V_68;
}
if ( F_40 ( -- V_65 < 0 ) ) {
F_12 () ;
V_65 = V_66 ;
}
}
V_5 = V_56 ;
F_30 ( & V_4 -> V_44 ) ;
V_4 -> V_69 = V_37 - 1 ;
}
V_68:
if ( V_4 -> V_42 ) {
while ( F_36 ( V_4 , V_5 ) )
F_38 ( V_4 , & V_5 , & V_56 ) ;
}
if ( ! ( V_4 -> V_28 & V_51 ) )
goto V_74;
if ( ! V_4 -> V_73 )
goto V_74;
if ( V_5 > V_4 -> V_73 )
V_56 = V_5 = V_4 -> V_72 ;
if ( F_41 () && V_4 -> V_36 [ V_5 ] == V_2 ) {
int V_75 ;
F_29 ( & V_4 -> V_44 ) ;
V_75 = F_2 ( V_4 , V_5 ) ;
F_30 ( & V_4 -> V_44 ) ;
if ( V_75 )
goto V_68;
goto V_76;
}
if ( V_4 -> V_36 [ V_5 ] )
goto V_76;
if ( V_5 == V_4 -> V_72 )
V_4 -> V_72 ++ ;
if ( V_5 == V_4 -> V_73 )
V_4 -> V_73 -- ;
V_4 -> V_71 ++ ;
if ( V_4 -> V_71 == V_4 -> V_70 ) {
V_4 -> V_72 = V_4 -> V_62 ;
V_4 -> V_73 = 0 ;
F_30 ( & V_77 ) ;
F_42 ( & V_4 -> V_78 , & V_79 ) ;
F_29 ( & V_77 ) ;
}
V_4 -> V_36 [ V_5 ] = V_63 ;
F_33 ( V_4 , V_4 -> V_42 , V_5 ) ;
V_4 -> F_20 = V_5 + 1 ;
V_4 -> V_28 -= V_67 ;
return V_5 ;
V_76:
F_29 ( & V_4 -> V_44 ) ;
while ( ++ V_5 <= V_4 -> V_73 ) {
if ( ! V_4 -> V_36 [ V_5 ] ) {
F_30 ( & V_4 -> V_44 ) ;
goto V_68;
}
if ( F_41 () && V_4 -> V_36 [ V_5 ] == V_2 ) {
F_30 ( & V_4 -> V_44 ) ;
goto V_68;
}
if ( F_40 ( -- V_65 < 0 ) ) {
F_12 () ;
V_65 = V_66 ;
}
}
V_5 = V_4 -> V_72 ;
while ( V_5 < V_56 ) {
if ( ! V_4 -> V_36 [ V_5 ] ) {
F_30 ( & V_4 -> V_44 ) ;
goto V_68;
}
if ( F_41 () && V_4 -> V_36 [ V_5 ] == V_2 ) {
F_30 ( & V_4 -> V_44 ) ;
goto V_68;
}
if ( F_40 ( -- V_65 < 0 ) ) {
F_12 () ;
V_65 = V_66 ;
}
V_5 ++ ;
}
F_30 ( & V_4 -> V_44 ) ;
V_74:
V_4 -> V_28 -= V_67 ;
return 0 ;
}
T_1 F_43 ( void )
{
struct V_3 * V_4 , * V_61 ;
T_3 V_5 ;
if ( F_44 ( & V_80 ) <= 0 )
goto V_81;
F_45 ( & V_80 ) ;
F_30 ( & V_77 ) ;
V_82:
F_46 (si, next, &swap_avail_head, avail_list) {
F_47 ( & V_4 -> V_78 , & V_79 ) ;
F_29 ( & V_77 ) ;
F_30 ( & V_4 -> V_44 ) ;
if ( ! V_4 -> V_73 || ! ( V_4 -> V_28 & V_51 ) ) {
F_30 ( & V_77 ) ;
if ( F_48 ( & V_4 -> V_78 ) ) {
F_29 ( & V_4 -> V_44 ) ;
goto V_83;
}
F_49 ( ! V_4 -> V_73 ,
L_1 ,
V_4 -> type ) ;
F_49 ( ! ( V_4 -> V_28 & V_51 ) ,
L_2 ,
V_4 -> type ) ;
F_42 ( & V_4 -> V_78 , & V_79 ) ;
F_29 ( & V_4 -> V_44 ) ;
goto V_83;
}
V_5 = F_39 ( V_4 , V_2 ) ;
F_29 ( & V_4 -> V_44 ) ;
if ( V_5 )
return F_3 ( V_4 -> type , V_5 ) ;
F_50 ( L_3 ,
V_4 -> type ) ;
F_30 ( & V_77 ) ;
V_83:
if ( F_48 ( & V_61 -> V_78 ) )
goto V_82;
}
F_29 ( & V_77 ) ;
F_51 ( & V_80 ) ;
V_81:
return ( T_1 ) { 0 } ;
}
T_1 F_52 ( int type )
{
struct V_3 * V_4 ;
T_3 V_5 ;
V_4 = V_84 [ type ] ;
F_30 ( & V_4 -> V_44 ) ;
if ( V_4 && ( V_4 -> V_28 & V_51 ) ) {
F_45 ( & V_80 ) ;
V_5 = F_39 ( V_4 , 1 ) ;
if ( V_5 ) {
F_29 ( & V_4 -> V_44 ) ;
return F_3 ( type , V_5 ) ;
}
F_51 ( & V_80 ) ;
}
F_29 ( & V_4 -> V_44 ) ;
return ( T_1 ) { 0 } ;
}
static struct V_3 * F_53 ( T_1 V_6 )
{
struct V_3 * V_49 ;
unsigned long V_5 , type ;
if ( ! V_6 . V_9 )
goto V_85;
type = F_54 ( V_6 ) ;
if ( type >= V_86 )
goto V_87;
V_49 = V_84 [ type ] ;
if ( ! ( V_49 -> V_28 & V_88 ) )
goto V_89;
V_5 = F_55 ( V_6 ) ;
if ( V_5 >= V_49 -> V_62 )
goto V_90;
if ( ! V_49 -> V_36 [ V_5 ] )
goto V_91;
F_30 ( & V_49 -> V_44 ) ;
return V_49 ;
V_91:
F_56 ( L_4 , V_92 , V_6 . V_9 ) ;
goto V_85;
V_90:
F_56 ( L_4 , V_93 , V_6 . V_9 ) ;
goto V_85;
V_89:
F_56 ( L_4 , V_94 , V_6 . V_9 ) ;
goto V_85;
V_87:
F_56 ( L_4 , V_95 , V_6 . V_9 ) ;
V_85:
return NULL ;
}
static unsigned char F_57 ( struct V_3 * V_49 ,
T_1 V_6 , unsigned char V_63 )
{
unsigned long V_5 = F_55 ( V_6 ) ;
unsigned char V_96 ;
unsigned char V_97 ;
V_96 = V_49 -> V_36 [ V_5 ] ;
V_97 = V_96 & V_2 ;
V_96 &= ~ V_2 ;
if ( V_63 == V_2 ) {
F_34 ( ! V_97 ) ;
V_97 = 0 ;
} else if ( V_96 == V_98 ) {
V_96 = 0 ;
} else if ( ( V_96 & ~ V_99 ) <= V_100 ) {
if ( V_96 == V_99 ) {
if ( F_58 ( V_49 , V_5 , V_96 ) )
V_96 = V_100 | V_99 ;
else
V_96 = V_100 ;
} else
V_96 -- ;
}
V_63 = V_96 | V_97 ;
V_49 -> V_36 [ V_5 ] = V_63 ;
if ( ! V_63 ) {
F_59 ( V_6 ) ;
F_35 ( V_49 , V_49 -> V_42 , V_5 ) ;
if ( V_5 < V_49 -> V_72 )
V_49 -> V_72 = V_5 ;
if ( V_5 > V_49 -> V_73 ) {
bool V_101 = ! V_49 -> V_73 ;
V_49 -> V_73 = V_5 ;
if ( V_101 && ( V_49 -> V_28 & V_51 ) ) {
F_30 ( & V_77 ) ;
F_60 ( ! F_48 ( & V_49 -> V_78 ) ) ;
if ( F_48 ( & V_49 -> V_78 ) )
F_61 ( & V_49 -> V_78 ,
& V_79 ) ;
F_29 ( & V_77 ) ;
}
}
F_51 ( & V_80 ) ;
V_49 -> V_71 -- ;
F_62 ( V_49 -> type , V_5 ) ;
if ( V_49 -> V_28 & V_102 ) {
struct V_103 * V_104 = V_49 -> V_18 -> V_105 ;
if ( V_104 -> V_106 -> V_107 )
V_104 -> V_106 -> V_107 ( V_49 -> V_18 ,
V_5 ) ;
}
}
return V_63 ;
}
void F_63 ( T_1 V_6 )
{
struct V_3 * V_49 ;
V_49 = F_53 ( V_6 ) ;
if ( V_49 ) {
F_57 ( V_49 , V_6 , 1 ) ;
F_29 ( & V_49 -> V_44 ) ;
}
}
void F_64 ( T_1 V_6 )
{
struct V_3 * V_49 ;
V_49 = F_53 ( V_6 ) ;
if ( V_49 ) {
F_57 ( V_49 , V_6 , V_2 ) ;
F_29 ( & V_49 -> V_44 ) ;
}
}
int F_65 ( struct V_7 * V_7 )
{
int V_96 = 0 ;
struct V_3 * V_49 ;
T_1 V_6 ;
V_6 . V_9 = F_66 ( V_7 ) ;
V_49 = F_53 ( V_6 ) ;
if ( V_49 ) {
V_96 = F_1 ( V_49 -> V_36 [ F_55 ( V_6 ) ] ) ;
F_29 ( & V_49 -> V_44 ) ;
}
return V_96 ;
}
int F_67 ( T_1 V_6 )
{
int V_96 , V_108 , V_32 ;
struct V_3 * V_49 ;
struct V_7 * V_7 ;
T_3 V_5 ;
unsigned char * V_109 ;
V_49 = F_53 ( V_6 ) ;
if ( ! V_49 )
return 0 ;
V_96 = F_1 ( V_49 -> V_36 [ F_55 ( V_6 ) ] ) ;
if ( ! ( V_96 & V_99 ) )
goto V_85;
V_96 &= ~ V_99 ;
V_32 = V_100 + 1 ;
V_5 = F_55 ( V_6 ) ;
V_7 = F_68 ( V_49 -> V_36 + V_5 ) ;
V_5 &= ~ V_110 ;
F_34 ( F_66 ( V_7 ) != V_111 ) ;
do {
V_7 = F_15 ( V_7 , V_112 ) ;
V_109 = F_69 ( V_7 ) ;
V_108 = V_109 [ V_5 ] ;
F_70 ( V_109 ) ;
V_96 += ( V_108 & ~ V_99 ) * V_32 ;
V_32 *= ( V_113 + 1 ) ;
} while ( V_108 & V_99 );
V_85:
F_29 ( & V_49 -> V_44 ) ;
return V_96 ;
}
bool F_71 ( struct V_7 * V_7 , int * V_114 )
{
int V_96 ;
F_72 ( ! F_73 ( V_7 ) , V_7 ) ;
if ( F_40 ( F_74 ( V_7 ) ) )
return false ;
V_96 = F_75 ( V_7 , V_114 ) ;
if ( V_96 <= 1 && F_76 ( V_7 ) ) {
V_96 += F_65 ( V_7 ) ;
if ( V_96 == 1 && ! F_77 ( V_7 ) ) {
F_78 ( V_7 ) ;
F_79 ( V_7 ) ;
}
}
return V_96 <= 1 ;
}
int F_7 ( struct V_7 * V_7 )
{
F_72 ( ! F_73 ( V_7 ) , V_7 ) ;
if ( ! F_76 ( V_7 ) )
return 0 ;
if ( F_77 ( V_7 ) )
return 0 ;
if ( F_65 ( V_7 ) )
return 0 ;
if ( F_80 () )
return 0 ;
F_78 ( V_7 ) ;
F_79 ( V_7 ) ;
return 1 ;
}
int F_81 ( T_1 V_6 )
{
struct V_3 * V_49 ;
struct V_7 * V_7 = NULL ;
if ( F_82 ( V_6 ) )
return 1 ;
V_49 = F_53 ( V_6 ) ;
if ( V_49 ) {
if ( F_57 ( V_49 , V_6 , 1 ) == V_2 ) {
V_7 = F_4 ( F_5 ( V_6 ) ,
V_6 . V_9 ) ;
if ( V_7 && ! F_6 ( V_7 ) ) {
F_9 ( V_7 ) ;
V_7 = NULL ;
}
}
F_29 ( & V_49 -> V_44 ) ;
}
if ( V_7 ) {
if ( F_76 ( V_7 ) && ! F_77 ( V_7 ) &&
( ! F_83 ( V_7 ) || F_84 ( V_7 ) ) ) {
F_78 ( V_7 ) ;
F_79 ( V_7 ) ;
}
F_8 ( V_7 ) ;
F_9 ( V_7 ) ;
}
return V_49 != NULL ;
}
int F_85 ( T_4 V_115 , T_2 V_5 , struct V_116 * * V_117 )
{
struct V_116 * V_18 = NULL ;
int type ;
if ( V_115 )
V_18 = F_86 ( V_115 ) ;
F_30 ( & V_118 ) ;
for ( type = 0 ; type < V_86 ; type ++ ) {
struct V_3 * V_119 = V_84 [ type ] ;
if ( ! ( V_119 -> V_28 & V_51 ) )
continue;
if ( ! V_18 ) {
if ( V_117 )
* V_117 = F_87 ( V_119 -> V_18 ) ;
F_29 ( & V_118 ) ;
return type ;
}
if ( V_18 == V_119 -> V_18 ) {
struct V_10 * V_11 = & V_119 -> V_15 ;
if ( V_11 -> V_12 == V_5 ) {
if ( V_117 )
* V_117 = F_87 ( V_119 -> V_18 ) ;
F_29 ( & V_118 ) ;
F_88 ( V_18 ) ;
return type ;
}
}
}
F_29 ( & V_118 ) ;
if ( V_18 )
F_88 ( V_18 ) ;
return - V_120 ;
}
T_2 F_89 ( int type , T_3 V_5 )
{
struct V_116 * V_18 ;
if ( ( unsigned int ) type >= V_86 )
return 0 ;
if ( ! ( V_84 [ type ] -> V_28 & V_51 ) )
return 0 ;
return F_90 ( F_3 ( type , V_5 ) , & V_18 ) ;
}
unsigned int F_91 ( int type , int free )
{
unsigned int V_32 = 0 ;
F_30 ( & V_118 ) ;
if ( ( unsigned int ) type < V_86 ) {
struct V_3 * V_119 = V_84 [ type ] ;
F_30 ( & V_119 -> V_44 ) ;
if ( V_119 -> V_28 & V_51 ) {
V_32 = V_119 -> V_70 ;
if ( free )
V_32 -= V_119 -> V_71 ;
}
F_29 ( & V_119 -> V_44 ) ;
}
F_29 ( & V_118 ) ;
return V_32 ;
}
static inline int F_92 ( T_5 V_121 , T_5 V_122 )
{
return F_93 ( F_94 ( V_121 ) , V_122 ) ;
}
static int F_95 ( struct V_123 * V_124 , T_6 * V_125 ,
unsigned long V_126 , T_1 V_6 , struct V_7 * V_7 )
{
struct V_7 * V_127 ;
struct V_128 * V_129 ;
T_7 * V_130 ;
T_5 * V_121 ;
int V_8 = 1 ;
V_127 = V_7 ;
V_7 = F_96 ( V_7 , V_124 , V_126 ) ;
if ( F_40 ( ! V_7 ) )
return - V_131 ;
if ( F_97 ( V_7 , V_124 -> V_132 , V_19 ,
& V_129 , false ) ) {
V_8 = - V_131 ;
goto V_133;
}
V_121 = F_98 ( V_124 -> V_132 , V_125 , V_126 , & V_130 ) ;
if ( F_40 ( ! F_92 ( * V_121 , F_99 ( V_6 ) ) ) ) {
F_100 ( V_7 , V_129 , false ) ;
V_8 = 0 ;
goto V_85;
}
F_101 ( V_124 -> V_132 , V_134 ) ;
F_102 ( V_124 -> V_132 , V_135 ) ;
F_103 ( V_7 ) ;
F_104 ( V_124 -> V_132 , V_126 , V_121 ,
F_105 ( F_106 ( V_7 , V_124 -> V_136 ) ) ) ;
if ( V_7 == V_127 ) {
F_107 ( V_7 , V_124 , V_126 , false ) ;
F_108 ( V_7 , V_129 , true , false ) ;
} else {
F_109 ( V_7 , V_124 , V_126 , false ) ;
F_108 ( V_7 , V_129 , false , false ) ;
F_110 ( V_7 , V_124 ) ;
}
F_63 ( V_6 ) ;
F_111 ( V_7 ) ;
V_85:
F_112 ( V_121 , V_130 ) ;
V_133:
if ( V_7 != V_127 ) {
F_8 ( V_7 ) ;
F_9 ( V_7 ) ;
}
return V_8 ;
}
static int F_113 ( struct V_123 * V_124 , T_6 * V_125 ,
unsigned long V_126 , unsigned long V_137 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_5 V_122 = F_99 ( V_6 ) ;
T_5 * V_121 ;
int V_8 = 0 ;
V_121 = F_114 ( V_125 , V_126 ) ;
do {
if ( F_40 ( F_92 ( * V_121 , V_122 ) ) ) {
F_115 ( V_121 ) ;
V_8 = F_95 ( V_124 , V_125 , V_126 , V_6 , V_7 ) ;
if ( V_8 )
goto V_85;
V_121 = F_114 ( V_125 , V_126 ) ;
}
} while ( V_121 ++ , V_126 += V_138 , V_126 != V_137 );
F_115 ( V_121 - 1 ) ;
V_85:
return V_8 ;
}
static inline int F_116 ( struct V_123 * V_124 , T_8 * V_139 ,
unsigned long V_126 , unsigned long V_137 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_6 * V_125 ;
unsigned long V_61 ;
int V_8 ;
V_125 = F_117 ( V_139 , V_126 ) ;
do {
V_61 = F_118 ( V_126 , V_137 ) ;
if ( F_119 ( V_125 ) )
continue;
V_8 = F_113 ( V_124 , V_125 , V_126 , V_61 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_125 ++ , V_126 = V_61 , V_126 != V_137 );
return 0 ;
}
static inline int F_120 ( struct V_123 * V_124 , T_9 * V_140 ,
unsigned long V_126 , unsigned long V_137 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_8 * V_139 ;
unsigned long V_61 ;
int V_8 ;
V_139 = F_121 ( V_140 , V_126 ) ;
do {
V_61 = F_122 ( V_126 , V_137 ) ;
if ( F_123 ( V_139 ) )
continue;
V_8 = F_116 ( V_124 , V_139 , V_126 , V_61 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_139 ++ , V_126 = V_61 , V_126 != V_137 );
return 0 ;
}
static int F_124 ( struct V_123 * V_124 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_9 * V_140 ;
unsigned long V_126 , V_137 , V_61 ;
int V_8 ;
if ( F_125 ( V_7 ) ) {
V_126 = F_126 ( V_7 , V_124 ) ;
if ( V_126 == - V_141 )
return 0 ;
else
V_137 = V_126 + V_138 ;
} else {
V_126 = V_124 -> V_142 ;
V_137 = V_124 -> V_143 ;
}
V_140 = F_127 ( V_124 -> V_132 , V_126 ) ;
do {
V_61 = F_128 ( V_126 , V_137 ) ;
if ( F_129 ( V_140 ) )
continue;
V_8 = F_120 ( V_124 , V_140 , V_126 , V_61 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_140 ++ , V_126 = V_61 , V_126 != V_137 );
return 0 ;
}
static int F_130 ( struct V_144 * V_145 ,
T_1 V_6 , struct V_7 * V_7 )
{
struct V_123 * V_124 ;
int V_8 = 0 ;
if ( ! F_131 ( & V_145 -> V_146 ) ) {
F_111 ( V_7 ) ;
F_8 ( V_7 ) ;
F_132 ( & V_145 -> V_146 ) ;
F_133 ( V_7 ) ;
}
for ( V_124 = V_145 -> V_147 ; V_124 ; V_124 = V_124 -> V_148 ) {
if ( V_124 -> V_149 && ( V_8 = F_124 ( V_124 , V_6 , V_7 ) ) )
break;
}
F_134 ( & V_145 -> V_146 ) ;
return ( V_8 < 0 ) ? V_8 : 0 ;
}
static unsigned int F_135 ( struct V_3 * V_4 ,
unsigned int V_150 , bool V_151 )
{
unsigned int V_62 = V_4 -> V_62 ;
unsigned int V_152 = V_150 ;
unsigned char V_96 ;
for (; ; ) {
if ( ++ V_152 >= V_62 ) {
if ( ! V_150 ) {
V_152 = 0 ;
break;
}
V_62 = V_150 + 1 ;
V_150 = 0 ;
V_152 = 1 ;
}
if ( V_151 ) {
if ( F_136 ( V_4 , V_152 ) )
break;
else
continue;
}
V_96 = F_137 ( V_4 -> V_36 [ V_152 ] ) ;
if ( V_96 && F_1 ( V_96 ) != V_38 )
break;
}
return V_152 ;
}
int F_138 ( unsigned int type , bool V_151 ,
unsigned long V_153 )
{
struct V_3 * V_4 = V_84 [ type ] ;
struct V_144 * V_154 ;
volatile unsigned char * V_36 ;
unsigned char V_155 ;
struct V_7 * V_7 ;
T_1 V_6 ;
unsigned int V_152 = 0 ;
int V_156 = 0 ;
V_154 = & V_157 ;
F_139 ( & V_157 . V_158 ) ;
while ( ( V_152 = F_135 ( V_4 , V_152 , V_151 ) ) != 0 ) {
if ( F_140 ( V_159 ) ) {
V_156 = - V_160 ;
break;
}
V_36 = & V_4 -> V_36 [ V_152 ] ;
V_6 = F_3 ( type , V_152 ) ;
V_7 = F_141 ( V_6 ,
V_161 , NULL , 0 ) ;
if ( ! V_7 ) {
V_155 = * V_36 ;
if ( ! V_155 || V_155 == V_38 )
continue;
V_156 = - V_131 ;
break;
}
if ( F_142 ( & V_154 -> V_158 ) == 1 ) {
F_143 ( V_154 ) ;
V_154 = & V_157 ;
F_139 ( & V_157 . V_158 ) ;
}
F_144 ( V_7 ) ;
F_145 ( V_7 ) ;
F_133 ( V_7 ) ;
F_145 ( V_7 ) ;
V_155 = * V_36 ;
if ( F_1 ( V_155 ) == V_98 ) {
V_156 = F_146 ( V_6 , V_7 ) ;
if ( V_156 < 0 )
break;
continue;
}
if ( F_1 ( V_155 ) && V_154 != & V_157 )
V_156 = F_130 ( V_154 , V_6 , V_7 ) ;
if ( F_1 ( * V_36 ) ) {
int V_162 = ( * V_36 >= V_155 ) ;
struct V_163 * V_49 = & V_154 -> V_164 ;
struct V_144 * V_165 = V_154 ;
struct V_144 * V_166 = V_154 ;
struct V_144 * V_145 ;
F_139 ( & V_165 -> V_158 ) ;
F_139 ( & V_166 -> V_158 ) ;
F_30 ( & V_167 ) ;
while ( F_1 ( * V_36 ) && ! V_156 &&
( V_49 = V_49 -> V_61 ) != & V_154 -> V_164 ) {
V_145 = F_147 ( V_49 , struct V_144 , V_164 ) ;
if ( ! F_148 ( & V_145 -> V_158 ) )
continue;
F_29 ( & V_167 ) ;
F_143 ( V_166 ) ;
V_166 = V_145 ;
F_12 () ;
V_155 = * V_36 ;
if ( ! F_1 ( V_155 ) )
;
else if ( V_145 == & V_157 )
V_162 = 1 ;
else
V_156 = F_130 ( V_145 , V_6 , V_7 ) ;
if ( V_162 && * V_36 < V_155 ) {
F_143 ( V_165 ) ;
F_139 ( & V_145 -> V_158 ) ;
V_165 = V_145 ;
V_162 = 0 ;
}
F_30 ( & V_167 ) ;
}
F_29 ( & V_167 ) ;
F_143 ( V_166 ) ;
F_143 ( V_154 ) ;
V_154 = V_165 ;
}
if ( V_156 ) {
F_8 ( V_7 ) ;
F_9 ( V_7 ) ;
break;
}
if ( F_1 ( * V_36 ) &&
F_149 ( V_7 ) && F_76 ( V_7 ) ) {
struct V_168 V_169 = {
. V_170 = V_171 ,
} ;
F_150 ( V_7 , & V_169 ) ;
F_133 ( V_7 ) ;
F_145 ( V_7 ) ;
}
if ( F_76 ( V_7 ) &&
F_151 ( F_66 ( V_7 ) == V_6 . V_9 ) )
F_78 ( V_7 ) ;
F_79 ( V_7 ) ;
F_8 ( V_7 ) ;
F_9 ( V_7 ) ;
F_12 () ;
if ( V_151 && V_153 > 0 ) {
if ( ! -- V_153 )
break;
}
}
F_143 ( V_154 ) ;
return V_156 ;
}
static void F_152 ( void )
{
struct V_163 * V_49 , * V_61 ;
unsigned int type ;
for ( type = 0 ; type < V_86 ; type ++ )
if ( V_84 [ type ] -> V_71 )
return;
F_30 ( & V_167 ) ;
F_153 (p, next, &init_mm.mmlist)
F_154 ( V_49 ) ;
F_29 ( & V_167 ) ;
}
static T_2 F_90 ( T_1 V_6 , struct V_116 * * V_18 )
{
struct V_3 * V_119 ;
struct V_10 * V_172 ;
struct V_10 * V_11 ;
T_3 V_5 ;
V_119 = V_84 [ F_54 ( V_6 ) ] ;
* V_18 = V_119 -> V_18 ;
V_5 = F_55 ( V_6 ) ;
V_172 = V_119 -> V_21 ;
V_11 = V_172 ;
for ( ; ; ) {
if ( V_11 -> V_20 <= V_5 &&
V_5 < ( V_11 -> V_20 + V_11 -> V_17 ) ) {
return V_11 -> V_12 + ( V_5 - V_11 -> V_20 ) ;
}
V_11 = F_15 ( V_11 , V_24 ) ;
V_119 -> V_21 = V_11 ;
F_155 ( V_11 == V_172 ) ;
}
}
T_2 F_156 ( struct V_7 * V_7 , struct V_116 * * V_18 )
{
T_1 V_6 ;
V_6 . V_9 = F_66 ( V_7 ) ;
return F_90 ( V_6 , V_18 ) ;
}
static void F_157 ( struct V_3 * V_119 )
{
while ( ! F_158 ( & V_119 -> V_15 . V_24 ) ) {
struct V_10 * V_11 ;
V_11 = F_159 ( & V_119 -> V_15 . V_24 ,
struct V_10 , V_24 ) ;
F_160 ( & V_11 -> V_24 ) ;
F_161 ( V_11 ) ;
}
if ( V_119 -> V_28 & V_173 ) {
struct V_174 * V_175 = V_119 -> V_175 ;
struct V_176 * V_177 = V_175 -> V_178 ;
V_119 -> V_28 &= ~ V_173 ;
V_177 -> V_179 -> V_180 ( V_175 ) ;
}
}
int
F_162 ( struct V_3 * V_119 , unsigned long V_20 ,
unsigned long V_17 , T_2 V_12 )
{
struct V_10 * V_11 ;
struct V_10 * V_181 ;
struct V_163 * V_182 ;
if ( V_20 == 0 ) {
V_11 = & V_119 -> V_15 ;
V_119 -> V_21 = V_11 ;
V_11 -> V_20 = 0 ;
V_11 -> V_17 = V_17 ;
V_11 -> V_12 = V_12 ;
return 1 ;
} else {
V_182 = V_119 -> V_15 . V_24 . V_150 ;
V_11 = F_147 ( V_182 , struct V_10 , V_24 ) ;
F_155 ( V_11 -> V_20 + V_11 -> V_17 != V_20 ) ;
if ( V_11 -> V_12 + V_11 -> V_17 == V_12 ) {
V_11 -> V_17 += V_17 ;
return 0 ;
}
}
V_181 = F_163 ( sizeof( * V_11 ) , V_19 ) ;
if ( V_181 == NULL )
return - V_131 ;
V_181 -> V_20 = V_20 ;
V_181 -> V_17 = V_17 ;
V_181 -> V_12 = V_12 ;
F_164 ( & V_181 -> V_24 , & V_119 -> V_15 . V_24 ) ;
return 1 ;
}
static int F_165 ( struct V_3 * V_119 , T_2 * V_183 )
{
struct V_174 * V_175 = V_119 -> V_175 ;
struct V_176 * V_177 = V_175 -> V_178 ;
struct V_184 * V_184 = V_177 -> V_185 ;
int V_8 ;
if ( F_166 ( V_184 -> V_186 ) ) {
V_8 = F_162 ( V_119 , 0 , V_119 -> V_62 , 0 ) ;
* V_183 = V_119 -> V_70 ;
return V_8 ;
}
if ( V_177 -> V_179 -> V_187 ) {
V_8 = V_177 -> V_179 -> V_187 ( V_119 , V_175 , V_183 ) ;
if ( ! V_8 ) {
V_119 -> V_28 |= V_173 ;
V_8 = F_162 ( V_119 , 0 , V_119 -> V_62 , 0 ) ;
* V_183 = V_119 -> V_70 ;
}
return V_8 ;
}
return F_167 ( V_119 , V_175 , V_183 ) ;
}
static void F_168 ( struct V_3 * V_49 , int V_188 ,
unsigned char * V_36 ,
struct V_25 * V_42 )
{
if ( V_188 >= 0 )
V_49 -> V_188 = V_188 ;
else
V_49 -> V_188 = -- V_189 ;
V_49 -> V_24 . V_188 = - V_49 -> V_188 ;
V_49 -> V_78 . V_188 = - V_49 -> V_188 ;
V_49 -> V_36 = V_36 ;
V_49 -> V_42 = V_42 ;
V_49 -> V_28 |= V_51 ;
F_169 ( V_49 -> V_70 , & V_80 ) ;
V_190 += V_49 -> V_70 ;
F_170 ( & V_118 ) ;
F_61 ( & V_49 -> V_24 , & V_191 ) ;
F_30 ( & V_77 ) ;
F_61 ( & V_49 -> V_78 , & V_79 ) ;
F_29 ( & V_77 ) ;
}
static void F_171 ( struct V_3 * V_49 , int V_188 ,
unsigned char * V_36 ,
struct V_25 * V_42 ,
unsigned long * V_192 )
{
F_172 ( V_49 -> type , V_192 ) ;
F_30 ( & V_118 ) ;
F_30 ( & V_49 -> V_44 ) ;
F_168 ( V_49 , V_188 , V_36 , V_42 ) ;
F_29 ( & V_49 -> V_44 ) ;
F_29 ( & V_118 ) ;
}
static void F_173 ( struct V_3 * V_49 )
{
F_30 ( & V_118 ) ;
F_30 ( & V_49 -> V_44 ) ;
F_168 ( V_49 , V_49 -> V_188 , V_49 -> V_36 , V_49 -> V_42 ) ;
F_29 ( & V_49 -> V_44 ) ;
F_29 ( & V_118 ) ;
}
static unsigned F_174 ( struct V_174 * V_174 , T_10 * V_193 )
{
struct V_194 * V_195 = V_174 -> V_196 ;
F_175 ( V_174 , & V_197 , V_193 ) ;
if ( V_195 -> V_198 != F_142 ( & V_199 ) ) {
V_195 -> V_198 = F_142 ( & V_199 ) ;
return V_200 | V_201 | V_202 | V_203 ;
}
return V_200 | V_201 ;
}
static void * F_176 ( struct V_194 * V_204 , T_11 * V_205 )
{
struct V_3 * V_4 ;
int type ;
T_11 V_206 = * V_205 ;
F_177 ( & V_207 ) ;
if ( ! V_206 )
return V_208 ;
for ( type = 0 ; type < V_86 ; type ++ ) {
F_178 () ;
V_4 = V_84 [ type ] ;
if ( ! ( V_4 -> V_28 & V_88 ) || ! V_4 -> V_36 )
continue;
if ( ! -- V_206 )
return V_4 ;
}
return NULL ;
}
static void * F_179 ( struct V_194 * V_204 , void * V_209 , T_11 * V_205 )
{
struct V_3 * V_4 = V_209 ;
int type ;
if ( V_209 == V_208 )
type = 0 ;
else
type = V_4 -> type + 1 ;
for (; type < V_86 ; type ++ ) {
F_178 () ;
V_4 = V_84 [ type ] ;
if ( ! ( V_4 -> V_28 & V_88 ) || ! V_4 -> V_36 )
continue;
++ * V_205 ;
return V_4 ;
}
return NULL ;
}
static void F_180 ( struct V_194 * V_204 , void * V_209 )
{
F_181 ( & V_207 ) ;
}
static int F_182 ( struct V_194 * V_204 , void * V_209 )
{
struct V_3 * V_4 = V_209 ;
struct V_174 * V_174 ;
int V_210 ;
if ( V_4 == V_208 ) {
F_183 ( V_204 , L_5 ) ;
return 0 ;
}
V_174 = V_4 -> V_175 ;
V_210 = F_184 ( V_204 , V_174 , L_6 ) ;
F_185 ( V_204 , L_7 ,
V_210 < 40 ? 40 - V_210 : 1 , L_8 ,
F_166 ( F_186 ( V_174 ) -> V_186 ) ?
L_9 : L_10 ,
V_4 -> V_70 << ( V_16 - 10 ) ,
V_4 -> V_71 << ( V_16 - 10 ) ,
V_4 -> V_188 ) ;
return 0 ;
}
static int F_187 ( struct V_184 * V_184 , struct V_174 * V_174 )
{
struct V_194 * V_195 ;
int V_8 ;
V_8 = F_188 ( V_174 , & V_211 ) ;
if ( V_8 )
return V_8 ;
V_195 = V_174 -> V_196 ;
V_195 -> V_198 = F_142 ( & V_199 ) ;
return 0 ;
}
static int T_12 F_189 ( void )
{
F_190 ( L_11 , 0 , NULL , & V_212 ) ;
return 0 ;
}
static int T_12 F_191 ( void )
{
F_192 () ;
return 0 ;
}
static struct V_3 * F_193 ( void )
{
struct V_3 * V_49 ;
unsigned int type ;
V_49 = F_194 ( sizeof( * V_49 ) , V_19 ) ;
if ( ! V_49 )
return F_195 ( - V_131 ) ;
F_30 ( & V_118 ) ;
for ( type = 0 ; type < V_86 ; type ++ ) {
if ( ! ( V_84 [ type ] -> V_28 & V_88 ) )
break;
}
if ( type >= V_213 ) {
F_29 ( & V_118 ) ;
F_161 ( V_49 ) ;
return F_195 ( - V_214 ) ;
}
if ( type >= V_86 ) {
V_49 -> type = type ;
V_84 [ type ] = V_49 ;
F_196 () ;
V_86 ++ ;
} else {
F_161 ( V_49 ) ;
V_49 = V_84 [ type ] ;
}
F_197 ( & V_49 -> V_15 . V_24 ) ;
F_198 ( & V_49 -> V_24 , 0 ) ;
F_198 ( & V_49 -> V_78 , 0 ) ;
V_49 -> V_28 = V_88 ;
F_29 ( & V_118 ) ;
F_199 ( & V_49 -> V_44 ) ;
return V_49 ;
}
static int F_200 ( struct V_3 * V_49 , struct V_184 * V_184 )
{
int error ;
if ( F_166 ( V_184 -> V_186 ) ) {
V_49 -> V_18 = F_87 ( F_201 ( V_184 ) ) ;
error = F_202 ( V_49 -> V_18 ,
V_215 | V_216 | V_217 , V_49 ) ;
if ( error < 0 ) {
V_49 -> V_18 = NULL ;
return error ;
}
V_49 -> V_218 = F_203 ( V_49 -> V_18 ) ;
error = F_204 ( V_49 -> V_18 , V_138 ) ;
if ( error < 0 )
return error ;
V_49 -> V_28 |= V_102 ;
} else if ( F_205 ( V_184 -> V_186 ) ) {
V_49 -> V_18 = V_184 -> V_219 -> V_220 ;
F_206 ( V_184 ) ;
if ( F_207 ( V_184 ) )
return - V_221 ;
} else
return - V_222 ;
return 0 ;
}
static unsigned long F_208 ( struct V_3 * V_49 ,
union V_223 * V_223 ,
struct V_184 * V_184 )
{
int V_152 ;
unsigned long V_224 ;
unsigned long V_225 ;
unsigned long V_226 ;
if ( memcmp ( L_12 , V_223 -> V_227 . V_227 , 10 ) ) {
F_56 ( L_13 ) ;
return 0 ;
}
if ( F_209 ( V_223 -> V_26 . V_228 ) == 1 ) {
F_210 ( & V_223 -> V_26 . V_228 ) ;
F_210 ( & V_223 -> V_26 . V_226 ) ;
F_210 ( & V_223 -> V_26 . V_229 ) ;
for ( V_152 = 0 ; V_152 < V_223 -> V_26 . V_229 ; V_152 ++ )
F_210 ( & V_223 -> V_26 . V_230 [ V_152 ] ) ;
}
if ( V_223 -> V_26 . V_228 != 1 ) {
F_211 ( L_14 ,
V_223 -> V_26 . V_228 ) ;
return 0 ;
}
V_49 -> V_72 = 1 ;
V_49 -> F_20 = 1 ;
V_49 -> V_69 = 0 ;
V_224 = F_55 ( F_212 (
F_99 ( F_3 ( 0 , ~ 0UL ) ) ) ) + 1 ;
V_226 = V_223 -> V_26 . V_226 ;
if ( V_226 > V_224 ) {
F_211 ( L_15 ,
V_224 << ( V_16 - 10 ) ,
V_226 << ( V_16 - 10 ) ) ;
}
if ( V_224 > V_226 ) {
V_224 = V_226 + 1 ;
if ( ( unsigned int ) V_224 == 0 )
V_224 = V_231 ;
}
V_49 -> V_73 = V_224 - 1 ;
if ( ! V_224 )
return 0 ;
V_225 = F_213 ( V_184 ) >> V_16 ;
if ( V_225 && V_224 > V_225 ) {
F_211 ( L_16 ) ;
return 0 ;
}
if ( V_223 -> V_26 . V_229 && F_205 ( V_184 -> V_186 ) )
return 0 ;
if ( V_223 -> V_26 . V_229 > V_232 )
return 0 ;
return V_224 ;
}
static int F_214 ( struct V_3 * V_49 ,
union V_223 * V_223 ,
unsigned char * V_36 ,
struct V_25 * V_42 ,
unsigned long V_224 ,
T_2 * V_183 )
{
int V_152 ;
unsigned int V_233 ;
int V_234 ;
unsigned long V_235 = F_215 ( V_224 , V_37 ) ;
unsigned long V_35 = V_49 -> F_20 / V_37 ;
V_233 = V_224 - 1 ;
F_25 ( & V_49 -> V_45 ) ;
F_25 ( & V_49 -> V_46 ) ;
F_25 ( & V_49 -> V_39 ) ;
F_25 ( & V_49 -> V_40 ) ;
for ( V_152 = 0 ; V_152 < V_223 -> V_26 . V_229 ; V_152 ++ ) {
unsigned int V_50 = V_223 -> V_26 . V_230 [ V_152 ] ;
if ( V_50 == 0 || V_50 > V_223 -> V_26 . V_226 )
return - V_222 ;
if ( V_50 < V_224 ) {
V_36 [ V_50 ] = V_38 ;
V_233 -- ;
F_33 ( V_49 , V_42 , V_50 ) ;
}
}
for ( V_152 = V_224 ; V_152 < F_216 ( V_224 , V_37 ) ; V_152 ++ )
F_33 ( V_49 , V_42 , V_152 ) ;
if ( V_233 ) {
V_36 [ 0 ] = V_38 ;
F_33 ( V_49 , V_42 , 0 ) ;
V_49 -> V_62 = V_224 ;
V_49 -> V_70 = V_233 ;
V_234 = F_165 ( V_49 , V_183 ) ;
if ( V_234 < 0 )
return V_234 ;
V_233 = V_49 -> V_70 ;
}
if ( ! V_233 ) {
F_211 ( L_17 ) ;
return - V_222 ;
}
if ( ! V_42 )
return V_234 ;
for ( V_152 = 0 ; V_152 < V_235 ; V_152 ++ ) {
if ( ! F_17 ( & V_42 [ V_35 ] ) ) {
F_16 ( & V_42 [ V_35 ] , V_33 ) ;
if ( F_24 ( & V_49 -> V_45 ) ) {
F_22 ( & V_49 -> V_45 ,
V_35 , 0 ) ;
F_22 ( & V_49 -> V_46 ,
V_35 , 0 ) ;
} else {
unsigned int V_41 ;
V_41 = F_20 ( & V_49 -> V_46 ) ;
F_21 ( & V_42 [ V_41 ] , V_35 ) ;
F_22 ( & V_49 -> V_46 ,
V_35 , 0 ) ;
}
}
V_35 ++ ;
if ( V_35 == V_235 )
V_35 = 0 ;
}
return V_234 ;
}
static bool F_217 ( struct V_3 * V_4 )
{
struct V_236 * V_237 = F_218 ( V_4 -> V_18 ) ;
if ( ! V_237 || ! F_219 ( V_237 ) )
return false ;
return true ;
}
void F_220 ( struct V_238 * V_9 )
{
unsigned int type ;
unsigned long V_239 = 0 ;
F_30 ( & V_118 ) ;
for ( type = 0 ; type < V_86 ; type ++ ) {
struct V_3 * V_4 = V_84 [ type ] ;
if ( ( V_4 -> V_28 & V_88 ) && ! ( V_4 -> V_28 & V_51 ) )
V_239 += V_4 -> V_71 ;
}
V_9 -> V_240 = F_44 ( & V_80 ) + V_239 ;
V_9 -> V_241 = V_190 + V_239 ;
F_29 ( & V_118 ) ;
}
static int F_221 ( T_1 V_6 , unsigned char V_63 )
{
struct V_3 * V_49 ;
unsigned long V_5 , type ;
unsigned char V_96 ;
unsigned char V_97 ;
int V_14 = - V_222 ;
if ( F_82 ( V_6 ) )
goto V_85;
type = F_54 ( V_6 ) ;
if ( type >= V_86 )
goto V_242;
V_49 = V_84 [ type ] ;
V_5 = F_55 ( V_6 ) ;
F_30 ( & V_49 -> V_44 ) ;
if ( F_40 ( V_5 >= V_49 -> V_62 ) )
goto V_243;
V_96 = V_49 -> V_36 [ V_5 ] ;
if ( F_40 ( F_1 ( V_96 ) == V_38 ) ) {
V_14 = - V_244 ;
goto V_243;
}
V_97 = V_96 & V_2 ;
V_96 &= ~ V_2 ;
V_14 = 0 ;
if ( V_63 == V_2 ) {
if ( ! V_97 && V_96 )
V_97 = V_2 ;
else if ( V_97 )
V_14 = - V_245 ;
else
V_14 = - V_244 ;
} else if ( V_96 || V_97 ) {
if ( ( V_96 & ~ V_99 ) < V_100 )
V_96 += V_63 ;
else if ( ( V_96 & ~ V_99 ) > V_100 )
V_14 = - V_222 ;
else if ( F_58 ( V_49 , V_5 , V_96 ) )
V_96 = V_99 ;
else
V_14 = - V_131 ;
} else
V_14 = - V_244 ;
V_49 -> V_36 [ V_5 ] = V_96 | V_97 ;
V_243:
F_29 ( & V_49 -> V_44 ) ;
V_85:
return V_14 ;
V_242:
F_56 ( L_18 , V_95 , V_6 . V_9 ) ;
goto V_85;
}
void F_222 ( T_1 V_6 )
{
F_221 ( V_6 , V_98 ) ;
}
int F_223 ( T_1 V_6 )
{
int V_14 = 0 ;
while ( ! V_14 && F_221 ( V_6 , 1 ) == - V_131 )
V_14 = F_224 ( V_6 , V_246 ) ;
return V_14 ;
}
int F_225 ( T_1 V_6 )
{
return F_221 ( V_6 , V_2 ) ;
}
struct V_3 * F_226 ( struct V_7 * V_7 )
{
T_1 V_204 = { . V_9 = F_66 (page) } ;
return V_84 [ F_54 ( V_204 ) ] ;
}
struct V_176 * F_227 ( struct V_7 * V_7 )
{
F_72 ( ! F_76 ( V_7 ) , V_7 ) ;
return F_226 ( V_7 ) -> V_175 -> V_178 ;
}
T_3 F_228 ( struct V_7 * V_7 )
{
T_1 V_204 = { . V_9 = F_66 (page) } ;
F_72 ( ! F_76 ( V_7 ) , V_7 ) ;
return F_55 ( V_204 ) ;
}
int F_224 ( T_1 V_6 , T_13 V_247 )
{
struct V_3 * V_4 ;
struct V_7 * V_248 ;
struct V_7 * V_7 ;
struct V_7 * V_249 ;
T_3 V_5 ;
unsigned char V_96 ;
V_7 = F_229 ( V_247 | V_250 ) ;
V_4 = F_53 ( V_6 ) ;
if ( ! V_4 ) {
goto V_251;
}
V_5 = F_55 ( V_6 ) ;
V_96 = V_4 -> V_36 [ V_5 ] & ~ V_2 ;
if ( ( V_96 & ~ V_99 ) != V_100 ) {
goto V_85;
}
if ( ! V_7 ) {
F_29 ( & V_4 -> V_44 ) ;
return - V_131 ;
}
V_248 = F_68 ( V_4 -> V_36 + V_5 ) ;
V_5 &= ~ V_110 ;
if ( ! F_66 ( V_248 ) ) {
F_155 ( V_96 & V_99 ) ;
F_197 ( & V_248 -> V_112 ) ;
F_230 ( V_248 , V_111 ) ;
V_4 -> V_28 |= V_111 ;
}
F_13 (list_page, &head->lru, lru) {
unsigned char * V_109 ;
if ( ! ( V_96 & V_99 ) )
goto V_85;
V_109 = F_69 ( V_249 ) + V_5 ;
V_96 = * V_109 ;
F_70 ( V_109 ) ;
if ( ( V_96 & ~ V_99 ) != V_113 )
goto V_85;
}
F_164 ( & V_7 -> V_112 , & V_248 -> V_112 ) ;
V_7 = NULL ;
V_85:
F_29 ( & V_4 -> V_44 ) ;
V_251:
if ( V_7 )
F_231 ( V_7 ) ;
return 0 ;
}
static bool F_58 ( struct V_3 * V_4 ,
T_3 V_5 , unsigned char V_96 )
{
struct V_7 * V_248 ;
struct V_7 * V_7 ;
unsigned char * V_109 ;
V_248 = F_68 ( V_4 -> V_36 + V_5 ) ;
if ( F_66 ( V_248 ) != V_111 ) {
F_155 ( V_96 & V_99 ) ;
return false ;
}
V_5 &= ~ V_110 ;
V_7 = F_147 ( V_248 -> V_112 . V_61 , struct V_7 , V_112 ) ;
V_109 = F_69 ( V_7 ) + V_5 ;
if ( V_96 == V_100 )
goto V_252;
if ( V_96 == ( V_100 | V_99 ) ) {
while ( * V_109 == ( V_113 | V_99 ) ) {
F_70 ( V_109 ) ;
V_7 = F_147 ( V_7 -> V_112 . V_61 , struct V_7 , V_112 ) ;
F_155 ( V_7 == V_248 ) ;
V_109 = F_69 ( V_7 ) + V_5 ;
}
if ( * V_109 == V_113 ) {
F_70 ( V_109 ) ;
V_7 = F_147 ( V_7 -> V_112 . V_61 , struct V_7 , V_112 ) ;
if ( V_7 == V_248 )
return false ;
V_109 = F_69 ( V_7 ) + V_5 ;
V_252: * V_109 = 0 ;
}
* V_109 += 1 ;
F_70 ( V_109 ) ;
V_7 = F_147 ( V_7 -> V_112 . V_150 , struct V_7 , V_112 ) ;
while ( V_7 != V_248 ) {
V_109 = F_69 ( V_7 ) + V_5 ;
* V_109 = V_99 ;
F_70 ( V_109 ) ;
V_7 = F_147 ( V_7 -> V_112 . V_150 , struct V_7 , V_112 ) ;
}
return true ;
} else {
F_155 ( V_96 != V_99 ) ;
while ( * V_109 == V_99 ) {
F_70 ( V_109 ) ;
V_7 = F_147 ( V_7 -> V_112 . V_61 , struct V_7 , V_112 ) ;
F_155 ( V_7 == V_248 ) ;
V_109 = F_69 ( V_7 ) + V_5 ;
}
F_155 ( * V_109 == 0 ) ;
* V_109 -= 1 ;
if ( * V_109 == 0 )
V_96 = 0 ;
F_70 ( V_109 ) ;
V_7 = F_147 ( V_7 -> V_112 . V_150 , struct V_7 , V_112 ) ;
while ( V_7 != V_248 ) {
V_109 = F_69 ( V_7 ) + V_5 ;
* V_109 = V_113 | V_96 ;
V_96 = V_99 ;
F_70 ( V_109 ) ;
V_7 = F_147 ( V_7 -> V_112 . V_150 , struct V_7 , V_112 ) ;
}
return V_96 == V_99 ;
}
}
static void F_232 ( struct V_3 * V_4 )
{
T_3 V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_62 ; V_5 += V_138 ) {
struct V_7 * V_248 ;
V_248 = F_68 ( V_4 -> V_36 + V_5 ) ;
if ( F_66 ( V_248 ) ) {
struct V_7 * V_7 , * V_61 ;
F_233 (page, next, &head->lru, lru) {
F_160 ( & V_7 -> V_112 ) ;
F_231 ( V_7 ) ;
}
}
}
}
