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
int F_71 ( struct V_7 * V_7 )
{
int V_96 ;
F_72 ( ! F_73 ( V_7 ) , V_7 ) ;
if ( F_40 ( F_74 ( V_7 ) ) )
return 0 ;
if ( F_75 ( V_7 ) )
return 0 ;
V_96 = F_76 ( V_7 ) ;
if ( V_96 <= 1 && F_77 ( V_7 ) ) {
V_96 += F_65 ( V_7 ) ;
if ( V_96 == 1 && ! F_78 ( V_7 ) ) {
F_79 ( V_7 ) ;
F_80 ( V_7 ) ;
}
}
return V_96 <= 1 ;
}
int F_7 ( struct V_7 * V_7 )
{
F_72 ( ! F_73 ( V_7 ) , V_7 ) ;
if ( ! F_77 ( V_7 ) )
return 0 ;
if ( F_78 ( V_7 ) )
return 0 ;
if ( F_65 ( V_7 ) )
return 0 ;
if ( F_81 () )
return 0 ;
F_79 ( V_7 ) ;
F_80 ( V_7 ) ;
return 1 ;
}
int F_82 ( T_1 V_6 )
{
struct V_3 * V_49 ;
struct V_7 * V_7 = NULL ;
if ( F_83 ( V_6 ) )
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
if ( F_77 ( V_7 ) && ! F_78 ( V_7 ) &&
( ! F_84 ( V_7 ) || F_85 ( V_7 ) ) ) {
F_79 ( V_7 ) ;
F_80 ( V_7 ) ;
}
F_8 ( V_7 ) ;
F_9 ( V_7 ) ;
}
return V_49 != NULL ;
}
int F_86 ( T_4 V_114 , T_2 V_5 , struct V_115 * * V_116 )
{
struct V_115 * V_18 = NULL ;
int type ;
if ( V_114 )
V_18 = F_87 ( V_114 ) ;
F_30 ( & V_117 ) ;
for ( type = 0 ; type < V_86 ; type ++ ) {
struct V_3 * V_118 = V_84 [ type ] ;
if ( ! ( V_118 -> V_28 & V_51 ) )
continue;
if ( ! V_18 ) {
if ( V_116 )
* V_116 = F_88 ( V_118 -> V_18 ) ;
F_29 ( & V_117 ) ;
return type ;
}
if ( V_18 == V_118 -> V_18 ) {
struct V_10 * V_11 = & V_118 -> V_15 ;
if ( V_11 -> V_12 == V_5 ) {
if ( V_116 )
* V_116 = F_88 ( V_118 -> V_18 ) ;
F_29 ( & V_117 ) ;
F_89 ( V_18 ) ;
return type ;
}
}
}
F_29 ( & V_117 ) ;
if ( V_18 )
F_89 ( V_18 ) ;
return - V_119 ;
}
T_2 F_90 ( int type , T_3 V_5 )
{
struct V_115 * V_18 ;
if ( ( unsigned int ) type >= V_86 )
return 0 ;
if ( ! ( V_84 [ type ] -> V_28 & V_51 ) )
return 0 ;
return F_91 ( F_3 ( type , V_5 ) , & V_18 ) ;
}
unsigned int F_92 ( int type , int free )
{
unsigned int V_32 = 0 ;
F_30 ( & V_117 ) ;
if ( ( unsigned int ) type < V_86 ) {
struct V_3 * V_118 = V_84 [ type ] ;
F_30 ( & V_118 -> V_44 ) ;
if ( V_118 -> V_28 & V_51 ) {
V_32 = V_118 -> V_70 ;
if ( free )
V_32 -= V_118 -> V_71 ;
}
F_29 ( & V_118 -> V_44 ) ;
}
F_29 ( & V_117 ) ;
return V_32 ;
}
static inline int F_93 ( T_5 V_120 , T_5 V_121 )
{
return F_94 ( F_95 ( V_120 ) , V_121 ) ;
}
static int F_96 ( struct V_122 * V_123 , T_6 * V_124 ,
unsigned long V_125 , T_1 V_6 , struct V_7 * V_7 )
{
struct V_7 * V_126 ;
struct V_127 * V_128 ;
T_7 * V_129 ;
T_5 * V_120 ;
int V_8 = 1 ;
V_126 = V_7 ;
V_7 = F_97 ( V_7 , V_123 , V_125 ) ;
if ( F_40 ( ! V_7 ) )
return - V_130 ;
if ( F_98 ( V_7 , V_123 -> V_131 , V_19 ,
& V_128 , false ) ) {
V_8 = - V_130 ;
goto V_132;
}
V_120 = F_99 ( V_123 -> V_131 , V_124 , V_125 , & V_129 ) ;
if ( F_40 ( ! F_93 ( * V_120 , F_100 ( V_6 ) ) ) ) {
F_101 ( V_7 , V_128 , false ) ;
V_8 = 0 ;
goto V_85;
}
F_102 ( V_123 -> V_131 , V_133 ) ;
F_103 ( V_123 -> V_131 , V_134 ) ;
F_104 ( V_7 ) ;
F_105 ( V_123 -> V_131 , V_125 , V_120 ,
F_106 ( F_107 ( V_7 , V_123 -> V_135 ) ) ) ;
if ( V_7 == V_126 ) {
F_108 ( V_7 , V_123 , V_125 , false ) ;
F_109 ( V_7 , V_128 , true , false ) ;
} else {
F_110 ( V_7 , V_123 , V_125 , false ) ;
F_109 ( V_7 , V_128 , false , false ) ;
F_111 ( V_7 , V_123 ) ;
}
F_63 ( V_6 ) ;
F_112 ( V_7 ) ;
V_85:
F_113 ( V_120 , V_129 ) ;
V_132:
if ( V_7 != V_126 ) {
F_8 ( V_7 ) ;
F_114 ( V_7 ) ;
}
return V_8 ;
}
static int F_115 ( struct V_122 * V_123 , T_6 * V_124 ,
unsigned long V_125 , unsigned long V_136 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_5 V_121 = F_100 ( V_6 ) ;
T_5 * V_120 ;
int V_8 = 0 ;
V_120 = F_116 ( V_124 , V_125 ) ;
do {
if ( F_40 ( F_93 ( * V_120 , V_121 ) ) ) {
F_117 ( V_120 ) ;
V_8 = F_96 ( V_123 , V_124 , V_125 , V_6 , V_7 ) ;
if ( V_8 )
goto V_85;
V_120 = F_116 ( V_124 , V_125 ) ;
}
} while ( V_120 ++ , V_125 += V_137 , V_125 != V_136 );
F_117 ( V_120 - 1 ) ;
V_85:
return V_8 ;
}
static inline int F_118 ( struct V_122 * V_123 , T_8 * V_138 ,
unsigned long V_125 , unsigned long V_136 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_6 * V_124 ;
unsigned long V_61 ;
int V_8 ;
V_124 = F_119 ( V_138 , V_125 ) ;
do {
V_61 = F_120 ( V_125 , V_136 ) ;
if ( F_121 ( V_124 ) )
continue;
V_8 = F_115 ( V_123 , V_124 , V_125 , V_61 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_124 ++ , V_125 = V_61 , V_125 != V_136 );
return 0 ;
}
static inline int F_122 ( struct V_122 * V_123 , T_9 * V_139 ,
unsigned long V_125 , unsigned long V_136 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_8 * V_138 ;
unsigned long V_61 ;
int V_8 ;
V_138 = F_123 ( V_139 , V_125 ) ;
do {
V_61 = F_124 ( V_125 , V_136 ) ;
if ( F_125 ( V_138 ) )
continue;
V_8 = F_118 ( V_123 , V_138 , V_125 , V_61 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_138 ++ , V_125 = V_61 , V_125 != V_136 );
return 0 ;
}
static int F_126 ( struct V_122 * V_123 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_9 * V_139 ;
unsigned long V_125 , V_136 , V_61 ;
int V_8 ;
if ( F_127 ( V_7 ) ) {
V_125 = F_128 ( V_7 , V_123 ) ;
if ( V_125 == - V_140 )
return 0 ;
else
V_136 = V_125 + V_137 ;
} else {
V_125 = V_123 -> V_141 ;
V_136 = V_123 -> V_142 ;
}
V_139 = F_129 ( V_123 -> V_131 , V_125 ) ;
do {
V_61 = F_130 ( V_125 , V_136 ) ;
if ( F_131 ( V_139 ) )
continue;
V_8 = F_122 ( V_123 , V_139 , V_125 , V_61 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_139 ++ , V_125 = V_61 , V_125 != V_136 );
return 0 ;
}
static int F_132 ( struct V_143 * V_144 ,
T_1 V_6 , struct V_7 * V_7 )
{
struct V_122 * V_123 ;
int V_8 = 0 ;
if ( ! F_133 ( & V_144 -> V_145 ) ) {
F_112 ( V_7 ) ;
F_8 ( V_7 ) ;
F_134 ( & V_144 -> V_145 ) ;
F_135 ( V_7 ) ;
}
for ( V_123 = V_144 -> V_146 ; V_123 ; V_123 = V_123 -> V_147 ) {
if ( V_123 -> V_148 && ( V_8 = F_126 ( V_123 , V_6 , V_7 ) ) )
break;
}
F_136 ( & V_144 -> V_145 ) ;
return ( V_8 < 0 ) ? V_8 : 0 ;
}
static unsigned int F_137 ( struct V_3 * V_4 ,
unsigned int V_149 , bool V_150 )
{
unsigned int V_62 = V_4 -> V_62 ;
unsigned int V_151 = V_149 ;
unsigned char V_96 ;
for (; ; ) {
if ( ++ V_151 >= V_62 ) {
if ( ! V_149 ) {
V_151 = 0 ;
break;
}
V_62 = V_149 + 1 ;
V_149 = 0 ;
V_151 = 1 ;
}
if ( V_150 ) {
if ( F_138 ( V_4 , V_151 ) )
break;
else
continue;
}
V_96 = F_139 ( V_4 -> V_36 [ V_151 ] ) ;
if ( V_96 && F_1 ( V_96 ) != V_38 )
break;
}
return V_151 ;
}
int F_140 ( unsigned int type , bool V_150 ,
unsigned long V_152 )
{
struct V_3 * V_4 = V_84 [ type ] ;
struct V_143 * V_153 ;
volatile unsigned char * V_36 ;
unsigned char V_154 ;
struct V_7 * V_7 ;
T_1 V_6 ;
unsigned int V_151 = 0 ;
int V_155 = 0 ;
V_153 = & V_156 ;
F_141 ( & V_156 . V_157 ) ;
while ( ( V_151 = F_137 ( V_4 , V_151 , V_150 ) ) != 0 ) {
if ( F_142 ( V_158 ) ) {
V_155 = - V_159 ;
break;
}
V_36 = & V_4 -> V_36 [ V_151 ] ;
V_6 = F_3 ( type , V_151 ) ;
V_7 = F_143 ( V_6 ,
V_160 , NULL , 0 ) ;
if ( ! V_7 ) {
V_154 = * V_36 ;
if ( ! V_154 || V_154 == V_38 )
continue;
V_155 = - V_130 ;
break;
}
if ( F_144 ( & V_153 -> V_157 ) == 1 ) {
F_145 ( V_153 ) ;
V_153 = & V_156 ;
F_141 ( & V_156 . V_157 ) ;
}
F_146 ( V_7 ) ;
F_147 ( V_7 ) ;
F_135 ( V_7 ) ;
F_147 ( V_7 ) ;
V_154 = * V_36 ;
if ( F_1 ( V_154 ) == V_98 ) {
V_155 = F_148 ( V_6 , V_7 ) ;
if ( V_155 < 0 )
break;
continue;
}
if ( F_1 ( V_154 ) && V_153 != & V_156 )
V_155 = F_132 ( V_153 , V_6 , V_7 ) ;
if ( F_1 ( * V_36 ) ) {
int V_161 = ( * V_36 >= V_154 ) ;
struct V_162 * V_49 = & V_153 -> V_163 ;
struct V_143 * V_164 = V_153 ;
struct V_143 * V_165 = V_153 ;
struct V_143 * V_144 ;
F_141 ( & V_164 -> V_157 ) ;
F_141 ( & V_165 -> V_157 ) ;
F_30 ( & V_166 ) ;
while ( F_1 ( * V_36 ) && ! V_155 &&
( V_49 = V_49 -> V_61 ) != & V_153 -> V_163 ) {
V_144 = F_149 ( V_49 , struct V_143 , V_163 ) ;
if ( ! F_150 ( & V_144 -> V_157 ) )
continue;
F_29 ( & V_166 ) ;
F_145 ( V_165 ) ;
V_165 = V_144 ;
F_12 () ;
V_154 = * V_36 ;
if ( ! F_1 ( V_154 ) )
;
else if ( V_144 == & V_156 )
V_161 = 1 ;
else
V_155 = F_132 ( V_144 , V_6 , V_7 ) ;
if ( V_161 && * V_36 < V_154 ) {
F_145 ( V_164 ) ;
F_141 ( & V_144 -> V_157 ) ;
V_164 = V_144 ;
V_161 = 0 ;
}
F_30 ( & V_166 ) ;
}
F_29 ( & V_166 ) ;
F_145 ( V_165 ) ;
F_145 ( V_153 ) ;
V_153 = V_164 ;
}
if ( V_155 ) {
F_8 ( V_7 ) ;
F_9 ( V_7 ) ;
break;
}
if ( F_1 ( * V_36 ) &&
F_151 ( V_7 ) && F_77 ( V_7 ) ) {
struct V_167 V_168 = {
. V_169 = V_170 ,
} ;
F_152 ( V_7 , & V_168 ) ;
F_135 ( V_7 ) ;
F_147 ( V_7 ) ;
}
if ( F_77 ( V_7 ) &&
F_153 ( F_66 ( V_7 ) == V_6 . V_9 ) )
F_79 ( V_7 ) ;
F_80 ( V_7 ) ;
F_8 ( V_7 ) ;
F_9 ( V_7 ) ;
F_12 () ;
if ( V_150 && V_152 > 0 ) {
if ( ! -- V_152 )
break;
}
}
F_145 ( V_153 ) ;
return V_155 ;
}
static void F_154 ( void )
{
struct V_162 * V_49 , * V_61 ;
unsigned int type ;
for ( type = 0 ; type < V_86 ; type ++ )
if ( V_84 [ type ] -> V_71 )
return;
F_30 ( & V_166 ) ;
F_155 (p, next, &init_mm.mmlist)
F_156 ( V_49 ) ;
F_29 ( & V_166 ) ;
}
static T_2 F_91 ( T_1 V_6 , struct V_115 * * V_18 )
{
struct V_3 * V_118 ;
struct V_10 * V_171 ;
struct V_10 * V_11 ;
T_3 V_5 ;
V_118 = V_84 [ F_54 ( V_6 ) ] ;
* V_18 = V_118 -> V_18 ;
V_5 = F_55 ( V_6 ) ;
V_171 = V_118 -> V_21 ;
V_11 = V_171 ;
for ( ; ; ) {
if ( V_11 -> V_20 <= V_5 &&
V_5 < ( V_11 -> V_20 + V_11 -> V_17 ) ) {
return V_11 -> V_12 + ( V_5 - V_11 -> V_20 ) ;
}
V_11 = F_15 ( V_11 , V_24 ) ;
V_118 -> V_21 = V_11 ;
F_157 ( V_11 == V_171 ) ;
}
}
T_2 F_158 ( struct V_7 * V_7 , struct V_115 * * V_18 )
{
T_1 V_6 ;
V_6 . V_9 = F_66 ( V_7 ) ;
return F_91 ( V_6 , V_18 ) ;
}
static void F_159 ( struct V_3 * V_118 )
{
while ( ! F_160 ( & V_118 -> V_15 . V_24 ) ) {
struct V_10 * V_11 ;
V_11 = F_161 ( & V_118 -> V_15 . V_24 ,
struct V_10 , V_24 ) ;
F_162 ( & V_11 -> V_24 ) ;
F_163 ( V_11 ) ;
}
if ( V_118 -> V_28 & V_172 ) {
struct V_173 * V_174 = V_118 -> V_174 ;
struct V_175 * V_176 = V_174 -> V_177 ;
V_118 -> V_28 &= ~ V_172 ;
V_176 -> V_178 -> V_179 ( V_174 ) ;
}
}
int
F_164 ( struct V_3 * V_118 , unsigned long V_20 ,
unsigned long V_17 , T_2 V_12 )
{
struct V_10 * V_11 ;
struct V_10 * V_180 ;
struct V_162 * V_181 ;
if ( V_20 == 0 ) {
V_11 = & V_118 -> V_15 ;
V_118 -> V_21 = V_11 ;
V_11 -> V_20 = 0 ;
V_11 -> V_17 = V_17 ;
V_11 -> V_12 = V_12 ;
return 1 ;
} else {
V_181 = V_118 -> V_15 . V_24 . V_149 ;
V_11 = F_149 ( V_181 , struct V_10 , V_24 ) ;
F_157 ( V_11 -> V_20 + V_11 -> V_17 != V_20 ) ;
if ( V_11 -> V_12 + V_11 -> V_17 == V_12 ) {
V_11 -> V_17 += V_17 ;
return 0 ;
}
}
V_180 = F_165 ( sizeof( * V_11 ) , V_19 ) ;
if ( V_180 == NULL )
return - V_130 ;
V_180 -> V_20 = V_20 ;
V_180 -> V_17 = V_17 ;
V_180 -> V_12 = V_12 ;
F_166 ( & V_180 -> V_24 , & V_118 -> V_15 . V_24 ) ;
return 1 ;
}
static int F_167 ( struct V_3 * V_118 , T_2 * V_182 )
{
struct V_173 * V_174 = V_118 -> V_174 ;
struct V_175 * V_176 = V_174 -> V_177 ;
struct V_183 * V_183 = V_176 -> V_184 ;
int V_8 ;
if ( F_168 ( V_183 -> V_185 ) ) {
V_8 = F_164 ( V_118 , 0 , V_118 -> V_62 , 0 ) ;
* V_182 = V_118 -> V_70 ;
return V_8 ;
}
if ( V_176 -> V_178 -> V_186 ) {
V_8 = V_176 -> V_178 -> V_186 ( V_118 , V_174 , V_182 ) ;
if ( ! V_8 ) {
V_118 -> V_28 |= V_172 ;
V_8 = F_164 ( V_118 , 0 , V_118 -> V_62 , 0 ) ;
* V_182 = V_118 -> V_70 ;
}
return V_8 ;
}
return F_169 ( V_118 , V_174 , V_182 ) ;
}
static void F_170 ( struct V_3 * V_49 , int V_187 ,
unsigned char * V_36 ,
struct V_25 * V_42 )
{
if ( V_187 >= 0 )
V_49 -> V_187 = V_187 ;
else
V_49 -> V_187 = -- V_188 ;
V_49 -> V_24 . V_187 = - V_49 -> V_187 ;
V_49 -> V_78 . V_187 = - V_49 -> V_187 ;
V_49 -> V_36 = V_36 ;
V_49 -> V_42 = V_42 ;
V_49 -> V_28 |= V_51 ;
F_171 ( V_49 -> V_70 , & V_80 ) ;
V_189 += V_49 -> V_70 ;
F_172 ( & V_117 ) ;
F_61 ( & V_49 -> V_24 , & V_190 ) ;
F_30 ( & V_77 ) ;
F_61 ( & V_49 -> V_78 , & V_79 ) ;
F_29 ( & V_77 ) ;
}
static void F_173 ( struct V_3 * V_49 , int V_187 ,
unsigned char * V_36 ,
struct V_25 * V_42 ,
unsigned long * V_191 )
{
F_174 ( V_49 -> type , V_191 ) ;
F_30 ( & V_117 ) ;
F_30 ( & V_49 -> V_44 ) ;
F_170 ( V_49 , V_187 , V_36 , V_42 ) ;
F_29 ( & V_49 -> V_44 ) ;
F_29 ( & V_117 ) ;
}
static void F_175 ( struct V_3 * V_49 )
{
F_30 ( & V_117 ) ;
F_30 ( & V_49 -> V_44 ) ;
F_170 ( V_49 , V_49 -> V_187 , V_49 -> V_36 , V_49 -> V_42 ) ;
F_29 ( & V_49 -> V_44 ) ;
F_29 ( & V_117 ) ;
}
static unsigned F_176 ( struct V_173 * V_173 , T_10 * V_192 )
{
struct V_193 * V_194 = V_173 -> V_195 ;
F_177 ( V_173 , & V_196 , V_192 ) ;
if ( V_194 -> V_197 != F_144 ( & V_198 ) ) {
V_194 -> V_197 = F_144 ( & V_198 ) ;
return V_199 | V_200 | V_201 | V_202 ;
}
return V_199 | V_200 ;
}
static void * F_178 ( struct V_193 * V_203 , T_11 * V_204 )
{
struct V_3 * V_4 ;
int type ;
T_11 V_205 = * V_204 ;
F_179 ( & V_206 ) ;
if ( ! V_205 )
return V_207 ;
for ( type = 0 ; type < V_86 ; type ++ ) {
F_180 () ;
V_4 = V_84 [ type ] ;
if ( ! ( V_4 -> V_28 & V_88 ) || ! V_4 -> V_36 )
continue;
if ( ! -- V_205 )
return V_4 ;
}
return NULL ;
}
static void * F_181 ( struct V_193 * V_203 , void * V_208 , T_11 * V_204 )
{
struct V_3 * V_4 = V_208 ;
int type ;
if ( V_208 == V_207 )
type = 0 ;
else
type = V_4 -> type + 1 ;
for (; type < V_86 ; type ++ ) {
F_180 () ;
V_4 = V_84 [ type ] ;
if ( ! ( V_4 -> V_28 & V_88 ) || ! V_4 -> V_36 )
continue;
++ * V_204 ;
return V_4 ;
}
return NULL ;
}
static void F_182 ( struct V_193 * V_203 , void * V_208 )
{
F_183 ( & V_206 ) ;
}
static int F_184 ( struct V_193 * V_203 , void * V_208 )
{
struct V_3 * V_4 = V_208 ;
struct V_173 * V_173 ;
int V_209 ;
if ( V_4 == V_207 ) {
F_185 ( V_203 , L_5 ) ;
return 0 ;
}
V_173 = V_4 -> V_174 ;
V_209 = F_186 ( V_203 , V_173 , L_6 ) ;
F_187 ( V_203 , L_7 ,
V_209 < 40 ? 40 - V_209 : 1 , L_8 ,
F_168 ( F_188 ( V_173 ) -> V_185 ) ?
L_9 : L_10 ,
V_4 -> V_70 << ( V_16 - 10 ) ,
V_4 -> V_71 << ( V_16 - 10 ) ,
V_4 -> V_187 ) ;
return 0 ;
}
static int F_189 ( struct V_183 * V_183 , struct V_173 * V_173 )
{
struct V_193 * V_194 ;
int V_8 ;
V_8 = F_190 ( V_173 , & V_210 ) ;
if ( V_8 )
return V_8 ;
V_194 = V_173 -> V_195 ;
V_194 -> V_197 = F_144 ( & V_198 ) ;
return 0 ;
}
static int T_12 F_191 ( void )
{
F_192 ( L_11 , 0 , NULL , & V_211 ) ;
return 0 ;
}
static int T_12 F_193 ( void )
{
F_194 () ;
return 0 ;
}
static struct V_3 * F_195 ( void )
{
struct V_3 * V_49 ;
unsigned int type ;
V_49 = F_196 ( sizeof( * V_49 ) , V_19 ) ;
if ( ! V_49 )
return F_197 ( - V_130 ) ;
F_30 ( & V_117 ) ;
for ( type = 0 ; type < V_86 ; type ++ ) {
if ( ! ( V_84 [ type ] -> V_28 & V_88 ) )
break;
}
if ( type >= V_212 ) {
F_29 ( & V_117 ) ;
F_163 ( V_49 ) ;
return F_197 ( - V_213 ) ;
}
if ( type >= V_86 ) {
V_49 -> type = type ;
V_84 [ type ] = V_49 ;
F_198 () ;
V_86 ++ ;
} else {
F_163 ( V_49 ) ;
V_49 = V_84 [ type ] ;
}
F_199 ( & V_49 -> V_15 . V_24 ) ;
F_200 ( & V_49 -> V_24 , 0 ) ;
F_200 ( & V_49 -> V_78 , 0 ) ;
V_49 -> V_28 = V_88 ;
F_29 ( & V_117 ) ;
F_201 ( & V_49 -> V_44 ) ;
return V_49 ;
}
static int F_202 ( struct V_3 * V_49 , struct V_183 * V_183 )
{
int error ;
if ( F_168 ( V_183 -> V_185 ) ) {
V_49 -> V_18 = F_88 ( F_203 ( V_183 ) ) ;
error = F_204 ( V_49 -> V_18 ,
V_214 | V_215 | V_216 , V_49 ) ;
if ( error < 0 ) {
V_49 -> V_18 = NULL ;
return error ;
}
V_49 -> V_217 = F_205 ( V_49 -> V_18 ) ;
error = F_206 ( V_49 -> V_18 , V_137 ) ;
if ( error < 0 )
return error ;
V_49 -> V_28 |= V_102 ;
} else if ( F_207 ( V_183 -> V_185 ) ) {
V_49 -> V_18 = V_183 -> V_218 -> V_219 ;
F_208 ( V_183 ) ;
if ( F_209 ( V_183 ) )
return - V_220 ;
} else
return - V_221 ;
return 0 ;
}
static unsigned long F_210 ( struct V_3 * V_49 ,
union V_222 * V_222 ,
struct V_183 * V_183 )
{
int V_151 ;
unsigned long V_223 ;
unsigned long V_224 ;
unsigned long V_225 ;
if ( memcmp ( L_12 , V_222 -> V_226 . V_226 , 10 ) ) {
F_56 ( L_13 ) ;
return 0 ;
}
if ( F_211 ( V_222 -> V_26 . V_227 ) == 1 ) {
F_212 ( & V_222 -> V_26 . V_227 ) ;
F_212 ( & V_222 -> V_26 . V_225 ) ;
F_212 ( & V_222 -> V_26 . V_228 ) ;
for ( V_151 = 0 ; V_151 < V_222 -> V_26 . V_228 ; V_151 ++ )
F_212 ( & V_222 -> V_26 . V_229 [ V_151 ] ) ;
}
if ( V_222 -> V_26 . V_227 != 1 ) {
F_213 ( L_14 ,
V_222 -> V_26 . V_227 ) ;
return 0 ;
}
V_49 -> V_72 = 1 ;
V_49 -> F_20 = 1 ;
V_49 -> V_69 = 0 ;
V_223 = F_55 ( F_214 (
F_100 ( F_3 ( 0 , ~ 0UL ) ) ) ) + 1 ;
V_225 = V_222 -> V_26 . V_225 ;
if ( V_225 > V_223 ) {
F_213 ( L_15 ,
V_223 << ( V_16 - 10 ) ,
V_225 << ( V_16 - 10 ) ) ;
}
if ( V_223 > V_225 ) {
V_223 = V_225 + 1 ;
if ( ( unsigned int ) V_223 == 0 )
V_223 = V_230 ;
}
V_49 -> V_73 = V_223 - 1 ;
if ( ! V_223 )
return 0 ;
V_224 = F_215 ( V_183 ) >> V_16 ;
if ( V_224 && V_223 > V_224 ) {
F_213 ( L_16 ) ;
return 0 ;
}
if ( V_222 -> V_26 . V_228 && F_207 ( V_183 -> V_185 ) )
return 0 ;
if ( V_222 -> V_26 . V_228 > V_231 )
return 0 ;
return V_223 ;
}
static int F_216 ( struct V_3 * V_49 ,
union V_222 * V_222 ,
unsigned char * V_36 ,
struct V_25 * V_42 ,
unsigned long V_223 ,
T_2 * V_182 )
{
int V_151 ;
unsigned int V_232 ;
int V_233 ;
unsigned long V_234 = F_217 ( V_223 , V_37 ) ;
unsigned long V_35 = V_49 -> F_20 / V_37 ;
V_232 = V_223 - 1 ;
F_25 ( & V_49 -> V_45 ) ;
F_25 ( & V_49 -> V_46 ) ;
F_25 ( & V_49 -> V_39 ) ;
F_25 ( & V_49 -> V_40 ) ;
for ( V_151 = 0 ; V_151 < V_222 -> V_26 . V_228 ; V_151 ++ ) {
unsigned int V_50 = V_222 -> V_26 . V_229 [ V_151 ] ;
if ( V_50 == 0 || V_50 > V_222 -> V_26 . V_225 )
return - V_221 ;
if ( V_50 < V_223 ) {
V_36 [ V_50 ] = V_38 ;
V_232 -- ;
F_33 ( V_49 , V_42 , V_50 ) ;
}
}
for ( V_151 = V_223 ; V_151 < F_218 ( V_223 , V_37 ) ; V_151 ++ )
F_33 ( V_49 , V_42 , V_151 ) ;
if ( V_232 ) {
V_36 [ 0 ] = V_38 ;
F_33 ( V_49 , V_42 , 0 ) ;
V_49 -> V_62 = V_223 ;
V_49 -> V_70 = V_232 ;
V_233 = F_167 ( V_49 , V_182 ) ;
if ( V_233 < 0 )
return V_233 ;
V_232 = V_49 -> V_70 ;
}
if ( ! V_232 ) {
F_213 ( L_17 ) ;
return - V_221 ;
}
if ( ! V_42 )
return V_233 ;
for ( V_151 = 0 ; V_151 < V_234 ; V_151 ++ ) {
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
if ( V_35 == V_234 )
V_35 = 0 ;
}
return V_233 ;
}
static bool F_219 ( struct V_3 * V_4 )
{
struct V_235 * V_236 = F_220 ( V_4 -> V_18 ) ;
if ( ! V_236 || ! F_221 ( V_236 ) )
return false ;
return true ;
}
void F_222 ( struct V_237 * V_9 )
{
unsigned int type ;
unsigned long V_238 = 0 ;
F_30 ( & V_117 ) ;
for ( type = 0 ; type < V_86 ; type ++ ) {
struct V_3 * V_4 = V_84 [ type ] ;
if ( ( V_4 -> V_28 & V_88 ) && ! ( V_4 -> V_28 & V_51 ) )
V_238 += V_4 -> V_71 ;
}
V_9 -> V_239 = F_44 ( & V_80 ) + V_238 ;
V_9 -> V_240 = V_189 + V_238 ;
F_29 ( & V_117 ) ;
}
static int F_223 ( T_1 V_6 , unsigned char V_63 )
{
struct V_3 * V_49 ;
unsigned long V_5 , type ;
unsigned char V_96 ;
unsigned char V_97 ;
int V_14 = - V_221 ;
if ( F_83 ( V_6 ) )
goto V_85;
type = F_54 ( V_6 ) ;
if ( type >= V_86 )
goto V_241;
V_49 = V_84 [ type ] ;
V_5 = F_55 ( V_6 ) ;
F_30 ( & V_49 -> V_44 ) ;
if ( F_40 ( V_5 >= V_49 -> V_62 ) )
goto V_242;
V_96 = V_49 -> V_36 [ V_5 ] ;
if ( F_40 ( F_1 ( V_96 ) == V_38 ) ) {
V_14 = - V_243 ;
goto V_242;
}
V_97 = V_96 & V_2 ;
V_96 &= ~ V_2 ;
V_14 = 0 ;
if ( V_63 == V_2 ) {
if ( ! V_97 && V_96 )
V_97 = V_2 ;
else if ( V_97 )
V_14 = - V_244 ;
else
V_14 = - V_243 ;
} else if ( V_96 || V_97 ) {
if ( ( V_96 & ~ V_99 ) < V_100 )
V_96 += V_63 ;
else if ( ( V_96 & ~ V_99 ) > V_100 )
V_14 = - V_221 ;
else if ( F_58 ( V_49 , V_5 , V_96 ) )
V_96 = V_99 ;
else
V_14 = - V_130 ;
} else
V_14 = - V_243 ;
V_49 -> V_36 [ V_5 ] = V_96 | V_97 ;
V_242:
F_29 ( & V_49 -> V_44 ) ;
V_85:
return V_14 ;
V_241:
F_56 ( L_18 , V_95 , V_6 . V_9 ) ;
goto V_85;
}
void F_224 ( T_1 V_6 )
{
F_223 ( V_6 , V_98 ) ;
}
int F_225 ( T_1 V_6 )
{
int V_14 = 0 ;
while ( ! V_14 && F_223 ( V_6 , 1 ) == - V_130 )
V_14 = F_226 ( V_6 , V_245 ) ;
return V_14 ;
}
int F_227 ( T_1 V_6 )
{
return F_223 ( V_6 , V_2 ) ;
}
struct V_3 * F_228 ( struct V_7 * V_7 )
{
T_1 V_203 = { . V_9 = F_66 (page) } ;
F_157 ( ! F_77 ( V_7 ) ) ;
return V_84 [ F_54 ( V_203 ) ] ;
}
struct V_175 * F_229 ( struct V_7 * V_7 )
{
F_72 ( ! F_77 ( V_7 ) , V_7 ) ;
return F_228 ( V_7 ) -> V_174 -> V_177 ;
}
T_3 F_230 ( struct V_7 * V_7 )
{
T_1 V_203 = { . V_9 = F_66 (page) } ;
F_72 ( ! F_77 ( V_7 ) , V_7 ) ;
return F_55 ( V_203 ) ;
}
int F_226 ( T_1 V_6 , T_13 V_246 )
{
struct V_3 * V_4 ;
struct V_7 * V_247 ;
struct V_7 * V_7 ;
struct V_7 * V_248 ;
T_3 V_5 ;
unsigned char V_96 ;
V_7 = F_231 ( V_246 | V_249 ) ;
V_4 = F_53 ( V_6 ) ;
if ( ! V_4 ) {
goto V_250;
}
V_5 = F_55 ( V_6 ) ;
V_96 = V_4 -> V_36 [ V_5 ] & ~ V_2 ;
if ( ( V_96 & ~ V_99 ) != V_100 ) {
goto V_85;
}
if ( ! V_7 ) {
F_29 ( & V_4 -> V_44 ) ;
return - V_130 ;
}
V_247 = F_68 ( V_4 -> V_36 + V_5 ) ;
V_5 &= ~ V_110 ;
if ( ! F_66 ( V_247 ) ) {
F_157 ( V_96 & V_99 ) ;
F_199 ( & V_247 -> V_112 ) ;
F_232 ( V_247 , V_111 ) ;
V_4 -> V_28 |= V_111 ;
}
F_13 (list_page, &head->lru, lru) {
unsigned char * V_109 ;
if ( ! ( V_96 & V_99 ) )
goto V_85;
V_109 = F_69 ( V_248 ) + V_5 ;
V_96 = * V_109 ;
F_70 ( V_109 ) ;
if ( ( V_96 & ~ V_99 ) != V_113 )
goto V_85;
}
F_166 ( & V_7 -> V_112 , & V_247 -> V_112 ) ;
V_7 = NULL ;
V_85:
F_29 ( & V_4 -> V_44 ) ;
V_250:
if ( V_7 )
F_233 ( V_7 ) ;
return 0 ;
}
static bool F_58 ( struct V_3 * V_4 ,
T_3 V_5 , unsigned char V_96 )
{
struct V_7 * V_247 ;
struct V_7 * V_7 ;
unsigned char * V_109 ;
V_247 = F_68 ( V_4 -> V_36 + V_5 ) ;
if ( F_66 ( V_247 ) != V_111 ) {
F_157 ( V_96 & V_99 ) ;
return false ;
}
V_5 &= ~ V_110 ;
V_7 = F_149 ( V_247 -> V_112 . V_61 , struct V_7 , V_112 ) ;
V_109 = F_69 ( V_7 ) + V_5 ;
if ( V_96 == V_100 )
goto V_251;
if ( V_96 == ( V_100 | V_99 ) ) {
while ( * V_109 == ( V_113 | V_99 ) ) {
F_70 ( V_109 ) ;
V_7 = F_149 ( V_7 -> V_112 . V_61 , struct V_7 , V_112 ) ;
F_157 ( V_7 == V_247 ) ;
V_109 = F_69 ( V_7 ) + V_5 ;
}
if ( * V_109 == V_113 ) {
F_70 ( V_109 ) ;
V_7 = F_149 ( V_7 -> V_112 . V_61 , struct V_7 , V_112 ) ;
if ( V_7 == V_247 )
return false ;
V_109 = F_69 ( V_7 ) + V_5 ;
V_251: * V_109 = 0 ;
}
* V_109 += 1 ;
F_70 ( V_109 ) ;
V_7 = F_149 ( V_7 -> V_112 . V_149 , struct V_7 , V_112 ) ;
while ( V_7 != V_247 ) {
V_109 = F_69 ( V_7 ) + V_5 ;
* V_109 = V_99 ;
F_70 ( V_109 ) ;
V_7 = F_149 ( V_7 -> V_112 . V_149 , struct V_7 , V_112 ) ;
}
return true ;
} else {
F_157 ( V_96 != V_99 ) ;
while ( * V_109 == V_99 ) {
F_70 ( V_109 ) ;
V_7 = F_149 ( V_7 -> V_112 . V_61 , struct V_7 , V_112 ) ;
F_157 ( V_7 == V_247 ) ;
V_109 = F_69 ( V_7 ) + V_5 ;
}
F_157 ( * V_109 == 0 ) ;
* V_109 -= 1 ;
if ( * V_109 == 0 )
V_96 = 0 ;
F_70 ( V_109 ) ;
V_7 = F_149 ( V_7 -> V_112 . V_149 , struct V_7 , V_112 ) ;
while ( V_7 != V_247 ) {
V_109 = F_69 ( V_7 ) + V_5 ;
* V_109 = V_113 | V_96 ;
V_96 = V_99 ;
F_70 ( V_109 ) ;
V_7 = F_149 ( V_7 -> V_112 . V_149 , struct V_7 , V_112 ) ;
}
return V_96 == V_99 ;
}
}
static void F_234 ( struct V_3 * V_4 )
{
T_3 V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_62 ; V_5 += V_137 ) {
struct V_7 * V_247 ;
V_247 = F_68 ( V_4 -> V_36 + V_5 ) ;
if ( F_66 ( V_247 ) ) {
struct V_7 * V_7 , * V_61 ;
F_235 (page, next, &head->lru, lru) {
F_162 ( & V_7 -> V_112 ) ;
F_233 ( V_7 ) ;
}
}
}
}
