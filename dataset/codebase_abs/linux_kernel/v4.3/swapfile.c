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
struct V_23 * V_24 ;
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
V_13 , V_25 , 0 ) )
break;
}
V_24 = V_11 -> V_26 . V_27 ;
V_11 = F_15 ( V_24 , struct V_10 , V_26 ) ;
}
}
static inline void F_16 ( struct V_28 * V_29 ,
unsigned int V_30 )
{
V_29 -> V_31 = V_30 ;
}
static inline unsigned int F_17 ( struct V_28 * V_29 )
{
return V_29 -> V_32 ;
}
static inline void F_18 ( struct V_28 * V_29 ,
unsigned int V_33 )
{
V_29 -> V_32 = V_33 ;
}
static inline void F_19 ( struct V_28 * V_29 ,
unsigned int V_33 , unsigned int V_34 )
{
V_29 -> V_31 = V_34 ;
V_29 -> V_32 = V_33 ;
}
static inline unsigned int F_20 ( struct V_28 * V_29 )
{
return V_29 -> V_32 ;
}
static inline void F_21 ( struct V_28 * V_29 ,
unsigned int V_35 )
{
V_29 -> V_32 = V_35 ;
}
static inline void F_22 ( struct V_28 * V_29 ,
unsigned int V_35 , unsigned int V_34 )
{
V_29 -> V_31 = V_34 ;
V_29 -> V_32 = V_35 ;
}
static inline bool F_23 ( struct V_28 * V_29 )
{
return V_29 -> V_31 & V_36 ;
}
static inline bool F_24 ( struct V_28 * V_29 )
{
return V_29 -> V_31 & V_37 ;
}
static inline void F_25 ( struct V_28 * V_29 )
{
V_29 -> V_31 = V_37 ;
V_29 -> V_32 = 0 ;
}
static void F_26 ( struct V_3 * V_4 ,
unsigned int V_38 )
{
memset ( V_4 -> V_39 + V_38 * V_40 ,
V_41 , V_40 ) ;
if ( F_24 ( & V_4 -> V_42 ) ) {
F_22 ( & V_4 -> V_42 ,
V_38 , 0 ) ;
F_22 ( & V_4 -> V_43 ,
V_38 , 0 ) ;
} else {
unsigned int V_44 = F_20 ( & V_4 -> V_43 ) ;
F_21 ( & V_4 -> V_45 [ V_44 ] , V_38 ) ;
F_22 ( & V_4 -> V_43 ,
V_38 , 0 ) ;
}
F_27 ( & V_4 -> V_46 ) ;
}
static void F_28 ( struct V_3 * V_4 )
{
struct V_28 * V_29 ;
unsigned int V_38 ;
V_29 = V_4 -> V_45 ;
while ( ! F_24 ( & V_4 -> V_42 ) ) {
V_38 = F_20 ( & V_4 -> V_42 ) ;
F_22 ( & V_4 -> V_42 ,
F_20 ( & V_29 [ V_38 ] ) , 0 ) ;
if ( F_20 ( & V_4 -> V_43 ) == V_38 ) {
F_25 ( & V_4 -> V_42 ) ;
F_25 ( & V_4 -> V_43 ) ;
}
F_29 ( & V_4 -> V_47 ) ;
F_14 ( V_4 , V_38 * V_40 ,
V_40 ) ;
F_30 ( & V_4 -> V_47 ) ;
F_16 ( & V_29 [ V_38 ] , V_36 ) ;
if ( F_24 ( & V_4 -> V_48 ) ) {
F_22 ( & V_4 -> V_48 ,
V_38 , 0 ) ;
F_22 ( & V_4 -> V_49 ,
V_38 , 0 ) ;
} else {
unsigned int V_44 ;
V_44 = F_20 ( & V_4 -> V_49 ) ;
F_21 ( & V_29 [ V_44 ] , V_38 ) ;
F_22 ( & V_4 -> V_49 ,
V_38 , 0 ) ;
}
memset ( V_4 -> V_39 + V_38 * V_40 ,
0 , V_40 ) ;
}
}
static void F_31 ( struct V_50 * V_51 )
{
struct V_3 * V_4 ;
V_4 = F_32 ( V_51 , struct V_3 , V_46 ) ;
F_30 ( & V_4 -> V_47 ) ;
F_28 ( V_4 ) ;
F_29 ( & V_4 -> V_47 ) ;
}
static void F_33 ( struct V_3 * V_52 ,
struct V_28 * V_45 , unsigned long V_53 )
{
unsigned long V_38 = V_53 / V_40 ;
if ( ! V_45 )
return;
if ( F_23 ( & V_45 [ V_38 ] ) ) {
F_34 ( F_20 ( & V_52 -> V_48 ) != V_38 ) ;
F_22 ( & V_52 -> V_48 ,
F_20 ( & V_45 [ V_38 ] ) , 0 ) ;
if ( F_20 ( & V_52 -> V_49 ) == V_38 ) {
F_25 ( & V_52 -> V_49 ) ;
F_25 ( & V_52 -> V_48 ) ;
}
F_19 ( & V_45 [ V_38 ] , 0 , 0 ) ;
}
F_34 ( F_17 ( & V_45 [ V_38 ] ) >= V_40 ) ;
F_18 ( & V_45 [ V_38 ] ,
F_17 ( & V_45 [ V_38 ] ) + 1 ) ;
}
static void F_35 ( struct V_3 * V_52 ,
struct V_28 * V_45 , unsigned long V_53 )
{
unsigned long V_38 = V_53 / V_40 ;
if ( ! V_45 )
return;
F_34 ( F_17 ( & V_45 [ V_38 ] ) == 0 ) ;
F_18 ( & V_45 [ V_38 ] ,
F_17 ( & V_45 [ V_38 ] ) - 1 ) ;
if ( F_17 ( & V_45 [ V_38 ] ) == 0 ) {
if ( ( V_52 -> V_31 & ( V_54 | V_55 ) ) ==
( V_54 | V_55 ) ) {
F_26 ( V_52 , V_38 ) ;
return;
}
F_16 ( & V_45 [ V_38 ] , V_36 ) ;
if ( F_24 ( & V_52 -> V_48 ) ) {
F_22 ( & V_52 -> V_48 , V_38 , 0 ) ;
F_22 ( & V_52 -> V_49 , V_38 , 0 ) ;
} else {
unsigned int V_44 = F_20 ( & V_52 -> V_49 ) ;
F_21 ( & V_45 [ V_44 ] , V_38 ) ;
F_22 ( & V_52 -> V_49 , V_38 , 0 ) ;
}
}
}
static bool
F_36 ( struct V_3 * V_4 ,
unsigned long V_5 )
{
struct V_56 * V_56 ;
bool V_57 ;
V_5 /= V_40 ;
V_57 = ! F_24 ( & V_4 -> V_48 ) &&
V_5 != F_20 ( & V_4 -> V_48 ) &&
F_23 ( & V_4 -> V_45 [ V_5 ] ) ;
if ( ! V_57 )
return false ;
V_56 = F_37 ( V_4 -> V_56 ) ;
F_25 ( & V_56 -> V_58 ) ;
return true ;
}
static void F_38 ( struct V_3 * V_4 ,
unsigned long * V_5 , unsigned long * V_59 )
{
struct V_56 * V_60 ;
bool V_61 ;
unsigned long V_62 ;
V_63:
V_60 = F_37 ( V_4 -> V_56 ) ;
if ( F_24 ( & V_60 -> V_58 ) ) {
if ( ! F_24 ( & V_4 -> V_48 ) ) {
V_60 -> V_58 = V_4 -> V_48 ;
V_60 -> V_27 = F_20 ( & V_60 -> V_58 ) *
V_40 ;
} else if ( ! F_24 ( & V_4 -> V_42 ) ) {
F_28 ( V_4 ) ;
* V_59 = * V_5 = V_4 -> F_20 ;
goto V_63;
} else
return;
}
V_61 = false ;
V_62 = V_60 -> V_27 ;
while ( V_62 < V_4 -> V_64 && V_62 < ( F_20 ( & V_60 -> V_58 ) + 1 ) *
V_40 ) {
if ( ! V_4 -> V_39 [ V_62 ] ) {
V_61 = true ;
break;
}
V_62 ++ ;
}
if ( ! V_61 ) {
F_25 ( & V_60 -> V_58 ) ;
goto V_63;
}
V_60 -> V_27 = V_62 + 1 ;
* V_5 = V_62 ;
* V_59 = V_62 ;
}
static unsigned long F_39 ( struct V_3 * V_4 ,
unsigned char V_65 )
{
unsigned long V_5 ;
unsigned long V_59 ;
unsigned long V_66 = 0 ;
int V_67 = V_68 ;
V_4 -> V_31 += V_69 ;
V_59 = V_5 = V_4 -> F_20 ;
if ( V_4 -> V_45 ) {
F_38 ( V_4 , & V_5 , & V_59 ) ;
goto V_70;
}
if ( F_40 ( ! V_4 -> V_71 -- ) ) {
if ( V_4 -> V_72 - V_4 -> V_73 < V_40 ) {
V_4 -> V_71 = V_40 - 1 ;
goto V_70;
}
F_29 ( & V_4 -> V_47 ) ;
V_59 = V_5 = V_4 -> V_74 ;
V_66 = V_5 + V_40 - 1 ;
for (; V_66 <= V_4 -> V_75 ; V_5 ++ ) {
if ( V_4 -> V_39 [ V_5 ] )
V_66 = V_5 + V_40 ;
else if ( V_5 == V_66 ) {
F_30 ( & V_4 -> V_47 ) ;
V_5 -= V_40 - 1 ;
V_4 -> F_20 = V_5 ;
V_4 -> V_71 = V_40 - 1 ;
goto V_70;
}
if ( F_40 ( -- V_67 < 0 ) ) {
F_12 () ;
V_67 = V_68 ;
}
}
V_5 = V_59 ;
F_30 ( & V_4 -> V_47 ) ;
V_4 -> V_71 = V_40 - 1 ;
}
V_70:
if ( V_4 -> V_45 ) {
while ( F_36 ( V_4 , V_5 ) )
F_38 ( V_4 , & V_5 , & V_59 ) ;
}
if ( ! ( V_4 -> V_31 & V_54 ) )
goto V_76;
if ( ! V_4 -> V_75 )
goto V_76;
if ( V_5 > V_4 -> V_75 )
V_59 = V_5 = V_4 -> V_74 ;
if ( F_41 () && V_4 -> V_39 [ V_5 ] == V_2 ) {
int V_77 ;
F_29 ( & V_4 -> V_47 ) ;
V_77 = F_2 ( V_4 , V_5 ) ;
F_30 ( & V_4 -> V_47 ) ;
if ( V_77 )
goto V_70;
goto V_78;
}
if ( V_4 -> V_39 [ V_5 ] )
goto V_78;
if ( V_5 == V_4 -> V_74 )
V_4 -> V_74 ++ ;
if ( V_5 == V_4 -> V_75 )
V_4 -> V_75 -- ;
V_4 -> V_73 ++ ;
if ( V_4 -> V_73 == V_4 -> V_72 ) {
V_4 -> V_74 = V_4 -> V_64 ;
V_4 -> V_75 = 0 ;
F_30 ( & V_79 ) ;
F_42 ( & V_4 -> V_80 , & V_81 ) ;
F_29 ( & V_79 ) ;
}
V_4 -> V_39 [ V_5 ] = V_65 ;
F_33 ( V_4 , V_4 -> V_45 , V_5 ) ;
V_4 -> F_20 = V_5 + 1 ;
V_4 -> V_31 -= V_69 ;
return V_5 ;
V_78:
F_29 ( & V_4 -> V_47 ) ;
while ( ++ V_5 <= V_4 -> V_75 ) {
if ( ! V_4 -> V_39 [ V_5 ] ) {
F_30 ( & V_4 -> V_47 ) ;
goto V_70;
}
if ( F_41 () && V_4 -> V_39 [ V_5 ] == V_2 ) {
F_30 ( & V_4 -> V_47 ) ;
goto V_70;
}
if ( F_40 ( -- V_67 < 0 ) ) {
F_12 () ;
V_67 = V_68 ;
}
}
V_5 = V_4 -> V_74 ;
while ( V_5 < V_59 ) {
if ( ! V_4 -> V_39 [ V_5 ] ) {
F_30 ( & V_4 -> V_47 ) ;
goto V_70;
}
if ( F_41 () && V_4 -> V_39 [ V_5 ] == V_2 ) {
F_30 ( & V_4 -> V_47 ) ;
goto V_70;
}
if ( F_40 ( -- V_67 < 0 ) ) {
F_12 () ;
V_67 = V_68 ;
}
V_5 ++ ;
}
F_30 ( & V_4 -> V_47 ) ;
V_76:
V_4 -> V_31 -= V_69 ;
return 0 ;
}
T_1 F_43 ( void )
{
struct V_3 * V_4 , * V_27 ;
T_3 V_5 ;
if ( F_44 ( & V_82 ) <= 0 )
goto V_83;
F_45 ( & V_82 ) ;
F_30 ( & V_79 ) ;
V_84:
F_46 (si, next, &swap_avail_head, avail_list) {
F_47 ( & V_4 -> V_80 , & V_81 ) ;
F_29 ( & V_79 ) ;
F_30 ( & V_4 -> V_47 ) ;
if ( ! V_4 -> V_75 || ! ( V_4 -> V_31 & V_54 ) ) {
F_30 ( & V_79 ) ;
if ( F_48 ( & V_4 -> V_80 ) ) {
F_29 ( & V_4 -> V_47 ) ;
goto V_85;
}
F_49 ( ! V_4 -> V_75 ,
L_1 ,
V_4 -> type ) ;
F_49 ( ! ( V_4 -> V_31 & V_54 ) ,
L_2 ,
V_4 -> type ) ;
F_42 ( & V_4 -> V_80 , & V_81 ) ;
F_29 ( & V_4 -> V_47 ) ;
goto V_85;
}
V_5 = F_39 ( V_4 , V_2 ) ;
F_29 ( & V_4 -> V_47 ) ;
if ( V_5 )
return F_3 ( V_4 -> type , V_5 ) ;
F_50 ( L_3 ,
V_4 -> type ) ;
F_30 ( & V_79 ) ;
V_85:
if ( F_48 ( & V_27 -> V_80 ) )
goto V_84;
}
F_29 ( & V_79 ) ;
F_51 ( & V_82 ) ;
V_83:
return ( T_1 ) { 0 } ;
}
T_1 F_52 ( int type )
{
struct V_3 * V_4 ;
T_3 V_5 ;
V_4 = V_86 [ type ] ;
F_30 ( & V_4 -> V_47 ) ;
if ( V_4 && ( V_4 -> V_31 & V_54 ) ) {
F_45 ( & V_82 ) ;
V_5 = F_39 ( V_4 , 1 ) ;
if ( V_5 ) {
F_29 ( & V_4 -> V_47 ) ;
return F_3 ( type , V_5 ) ;
}
F_51 ( & V_82 ) ;
}
F_29 ( & V_4 -> V_47 ) ;
return ( T_1 ) { 0 } ;
}
static struct V_3 * F_53 ( T_1 V_6 )
{
struct V_3 * V_52 ;
unsigned long V_5 , type ;
if ( ! V_6 . V_9 )
goto V_87;
type = F_54 ( V_6 ) ;
if ( type >= V_88 )
goto V_89;
V_52 = V_86 [ type ] ;
if ( ! ( V_52 -> V_31 & V_90 ) )
goto V_91;
V_5 = F_55 ( V_6 ) ;
if ( V_5 >= V_52 -> V_64 )
goto V_92;
if ( ! V_52 -> V_39 [ V_5 ] )
goto V_93;
F_30 ( & V_52 -> V_47 ) ;
return V_52 ;
V_93:
F_56 ( L_4 , V_94 , V_6 . V_9 ) ;
goto V_87;
V_92:
F_56 ( L_4 , V_95 , V_6 . V_9 ) ;
goto V_87;
V_91:
F_56 ( L_4 , V_96 , V_6 . V_9 ) ;
goto V_87;
V_89:
F_56 ( L_4 , V_97 , V_6 . V_9 ) ;
V_87:
return NULL ;
}
static unsigned char F_57 ( struct V_3 * V_52 ,
T_1 V_6 , unsigned char V_65 )
{
unsigned long V_5 = F_55 ( V_6 ) ;
unsigned char V_98 ;
unsigned char V_99 ;
V_98 = V_52 -> V_39 [ V_5 ] ;
V_99 = V_98 & V_2 ;
V_98 &= ~ V_2 ;
if ( V_65 == V_2 ) {
F_34 ( ! V_99 ) ;
V_99 = 0 ;
} else if ( V_98 == V_100 ) {
V_98 = 0 ;
} else if ( ( V_98 & ~ V_101 ) <= V_102 ) {
if ( V_98 == V_101 ) {
if ( F_58 ( V_52 , V_5 , V_98 ) )
V_98 = V_102 | V_101 ;
else
V_98 = V_102 ;
} else
V_98 -- ;
}
if ( ! V_98 )
F_59 ( V_6 ) ;
V_65 = V_98 | V_99 ;
V_52 -> V_39 [ V_5 ] = V_65 ;
if ( ! V_65 ) {
F_35 ( V_52 , V_52 -> V_45 , V_5 ) ;
if ( V_5 < V_52 -> V_74 )
V_52 -> V_74 = V_5 ;
if ( V_5 > V_52 -> V_75 ) {
bool V_103 = ! V_52 -> V_75 ;
V_52 -> V_75 = V_5 ;
if ( V_103 && ( V_52 -> V_31 & V_54 ) ) {
F_30 ( & V_79 ) ;
F_60 ( ! F_48 ( & V_52 -> V_80 ) ) ;
if ( F_48 ( & V_52 -> V_80 ) )
F_61 ( & V_52 -> V_80 ,
& V_81 ) ;
F_29 ( & V_79 ) ;
}
}
F_51 ( & V_82 ) ;
V_52 -> V_73 -- ;
F_62 ( V_52 -> type , V_5 ) ;
if ( V_52 -> V_31 & V_104 ) {
struct V_105 * V_106 = V_52 -> V_18 -> V_107 ;
if ( V_106 -> V_108 -> V_109 )
V_106 -> V_108 -> V_109 ( V_52 -> V_18 ,
V_5 ) ;
}
}
return V_65 ;
}
void F_63 ( T_1 V_6 )
{
struct V_3 * V_52 ;
V_52 = F_53 ( V_6 ) ;
if ( V_52 ) {
F_57 ( V_52 , V_6 , 1 ) ;
F_29 ( & V_52 -> V_47 ) ;
}
}
void F_64 ( T_1 V_6 )
{
struct V_3 * V_52 ;
V_52 = F_53 ( V_6 ) ;
if ( V_52 ) {
F_57 ( V_52 , V_6 , V_2 ) ;
F_29 ( & V_52 -> V_47 ) ;
}
}
int F_65 ( struct V_7 * V_7 )
{
int V_98 = 0 ;
struct V_3 * V_52 ;
T_1 V_6 ;
V_6 . V_9 = F_66 ( V_7 ) ;
V_52 = F_53 ( V_6 ) ;
if ( V_52 ) {
V_98 = F_1 ( V_52 -> V_39 [ F_55 ( V_6 ) ] ) ;
F_29 ( & V_52 -> V_47 ) ;
}
return V_98 ;
}
int F_67 ( T_1 V_6 )
{
int V_98 , V_110 , V_35 ;
struct V_3 * V_52 ;
struct V_7 * V_7 ;
T_3 V_5 ;
unsigned char * V_111 ;
V_52 = F_53 ( V_6 ) ;
if ( ! V_52 )
return 0 ;
V_98 = F_1 ( V_52 -> V_39 [ F_55 ( V_6 ) ] ) ;
if ( ! ( V_98 & V_101 ) )
goto V_87;
V_98 &= ~ V_101 ;
V_35 = V_102 + 1 ;
V_5 = F_55 ( V_6 ) ;
V_7 = F_68 ( V_52 -> V_39 + V_5 ) ;
V_5 &= ~ V_112 ;
F_34 ( F_66 ( V_7 ) != V_113 ) ;
do {
V_7 = F_15 ( V_7 -> V_114 . V_27 , struct V_7 , V_114 ) ;
V_111 = F_69 ( V_7 ) ;
V_110 = V_111 [ V_5 ] ;
F_70 ( V_111 ) ;
V_98 += ( V_110 & ~ V_101 ) * V_35 ;
V_35 *= ( V_115 + 1 ) ;
} while ( V_110 & V_101 );
V_87:
F_29 ( & V_52 -> V_47 ) ;
return V_98 ;
}
int F_71 ( struct V_7 * V_7 )
{
int V_98 ;
F_72 ( ! F_73 ( V_7 ) , V_7 ) ;
if ( F_40 ( F_74 ( V_7 ) ) )
return 0 ;
V_98 = F_75 ( V_7 ) ;
if ( V_98 <= 1 && F_76 ( V_7 ) ) {
V_98 += F_65 ( V_7 ) ;
if ( V_98 == 1 && ! F_77 ( V_7 ) ) {
F_78 ( V_7 ) ;
F_79 ( V_7 ) ;
}
}
return V_98 <= 1 ;
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
struct V_3 * V_52 ;
struct V_7 * V_7 = NULL ;
if ( F_82 ( V_6 ) )
return 1 ;
V_52 = F_53 ( V_6 ) ;
if ( V_52 ) {
if ( F_57 ( V_52 , V_6 , 1 ) == V_2 ) {
V_7 = F_4 ( F_5 ( V_6 ) ,
V_6 . V_9 ) ;
if ( V_7 && ! F_6 ( V_7 ) ) {
F_9 ( V_7 ) ;
V_7 = NULL ;
}
}
F_29 ( & V_52 -> V_47 ) ;
}
if ( V_7 ) {
if ( F_76 ( V_7 ) && ! F_77 ( V_7 ) &&
( ! F_83 ( V_7 ) || F_41 () ) ) {
F_78 ( V_7 ) ;
F_79 ( V_7 ) ;
}
F_8 ( V_7 ) ;
F_9 ( V_7 ) ;
}
return V_52 != NULL ;
}
int F_84 ( T_4 V_116 , T_2 V_5 , struct V_117 * * V_118 )
{
struct V_117 * V_18 = NULL ;
int type ;
if ( V_116 )
V_18 = F_85 ( V_116 ) ;
F_30 ( & V_119 ) ;
for ( type = 0 ; type < V_88 ; type ++ ) {
struct V_3 * V_120 = V_86 [ type ] ;
if ( ! ( V_120 -> V_31 & V_54 ) )
continue;
if ( ! V_18 ) {
if ( V_118 )
* V_118 = F_86 ( V_120 -> V_18 ) ;
F_29 ( & V_119 ) ;
return type ;
}
if ( V_18 == V_120 -> V_18 ) {
struct V_10 * V_11 = & V_120 -> V_15 ;
if ( V_11 -> V_12 == V_5 ) {
if ( V_118 )
* V_118 = F_86 ( V_120 -> V_18 ) ;
F_29 ( & V_119 ) ;
F_87 ( V_18 ) ;
return type ;
}
}
}
F_29 ( & V_119 ) ;
if ( V_18 )
F_87 ( V_18 ) ;
return - V_121 ;
}
T_2 F_88 ( int type , T_3 V_5 )
{
struct V_117 * V_18 ;
if ( ( unsigned int ) type >= V_88 )
return 0 ;
if ( ! ( V_86 [ type ] -> V_31 & V_54 ) )
return 0 ;
return F_89 ( F_3 ( type , V_5 ) , & V_18 ) ;
}
unsigned int F_90 ( int type , int free )
{
unsigned int V_35 = 0 ;
F_30 ( & V_119 ) ;
if ( ( unsigned int ) type < V_88 ) {
struct V_3 * V_120 = V_86 [ type ] ;
F_30 ( & V_120 -> V_47 ) ;
if ( V_120 -> V_31 & V_54 ) {
V_35 = V_120 -> V_72 ;
if ( free )
V_35 -= V_120 -> V_73 ;
}
F_29 ( & V_120 -> V_47 ) ;
}
F_29 ( & V_119 ) ;
return V_35 ;
}
static inline int F_91 ( T_5 V_122 , T_5 V_123 )
{
#ifdef F_92
T_5 V_124 = F_93 ( V_123 ) ;
return F_94 ( V_122 , V_123 ) || F_94 ( V_122 , V_124 ) ;
#else
return F_94 ( V_122 , V_123 ) ;
#endif
}
static int F_95 ( struct V_125 * V_126 , T_6 * V_127 ,
unsigned long V_128 , T_1 V_6 , struct V_7 * V_7 )
{
struct V_7 * V_129 ;
struct V_130 * V_131 ;
T_7 * V_132 ;
T_5 * V_122 ;
int V_8 = 1 ;
V_129 = V_7 ;
V_7 = F_96 ( V_7 , V_126 , V_128 ) ;
if ( F_40 ( ! V_7 ) )
return - V_133 ;
if ( F_97 ( V_7 , V_126 -> V_134 , V_19 , & V_131 ) ) {
V_8 = - V_133 ;
goto V_135;
}
V_122 = F_98 ( V_126 -> V_134 , V_127 , V_128 , & V_132 ) ;
if ( F_40 ( ! F_91 ( * V_122 , F_99 ( V_6 ) ) ) ) {
F_100 ( V_7 , V_131 ) ;
V_8 = 0 ;
goto V_87;
}
F_101 ( V_126 -> V_134 , V_136 ) ;
F_102 ( V_126 -> V_134 , V_137 ) ;
F_103 ( V_7 ) ;
F_104 ( V_126 -> V_134 , V_128 , V_122 ,
F_105 ( F_106 ( V_7 , V_126 -> V_138 ) ) ) ;
if ( V_7 == V_129 ) {
F_107 ( V_7 , V_126 , V_128 ) ;
F_108 ( V_7 , V_131 , true ) ;
} else {
F_109 ( V_7 , V_126 , V_128 ) ;
F_108 ( V_7 , V_131 , false ) ;
F_110 ( V_7 , V_126 ) ;
}
F_63 ( V_6 ) ;
F_111 ( V_7 ) ;
V_87:
F_112 ( V_122 , V_132 ) ;
V_135:
if ( V_7 != V_129 ) {
F_8 ( V_7 ) ;
F_113 ( V_7 ) ;
}
return V_8 ;
}
static int F_114 ( struct V_125 * V_126 , T_6 * V_127 ,
unsigned long V_128 , unsigned long V_139 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_5 V_123 = F_99 ( V_6 ) ;
T_5 * V_122 ;
int V_8 = 0 ;
V_122 = F_115 ( V_127 , V_128 ) ;
do {
if ( F_40 ( F_91 ( * V_122 , V_123 ) ) ) {
F_116 ( V_122 ) ;
V_8 = F_95 ( V_126 , V_127 , V_128 , V_6 , V_7 ) ;
if ( V_8 )
goto V_87;
V_122 = F_115 ( V_127 , V_128 ) ;
}
} while ( V_122 ++ , V_128 += V_140 , V_128 != V_139 );
F_116 ( V_122 - 1 ) ;
V_87:
return V_8 ;
}
static inline int F_117 ( struct V_125 * V_126 , T_8 * V_141 ,
unsigned long V_128 , unsigned long V_139 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_6 * V_127 ;
unsigned long V_27 ;
int V_8 ;
V_127 = F_118 ( V_141 , V_128 ) ;
do {
V_27 = F_119 ( V_128 , V_139 ) ;
if ( F_120 ( V_127 ) )
continue;
V_8 = F_114 ( V_126 , V_127 , V_128 , V_27 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_127 ++ , V_128 = V_27 , V_128 != V_139 );
return 0 ;
}
static inline int F_121 ( struct V_125 * V_126 , T_9 * V_142 ,
unsigned long V_128 , unsigned long V_139 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_8 * V_141 ;
unsigned long V_27 ;
int V_8 ;
V_141 = F_122 ( V_142 , V_128 ) ;
do {
V_27 = F_123 ( V_128 , V_139 ) ;
if ( F_124 ( V_141 ) )
continue;
V_8 = F_117 ( V_126 , V_141 , V_128 , V_27 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_141 ++ , V_128 = V_27 , V_128 != V_139 );
return 0 ;
}
static int F_125 ( struct V_125 * V_126 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_9 * V_142 ;
unsigned long V_128 , V_139 , V_27 ;
int V_8 ;
if ( F_126 ( V_7 ) ) {
V_128 = F_127 ( V_7 , V_126 ) ;
if ( V_128 == - V_143 )
return 0 ;
else
V_139 = V_128 + V_140 ;
} else {
V_128 = V_126 -> V_144 ;
V_139 = V_126 -> V_145 ;
}
V_142 = F_128 ( V_126 -> V_134 , V_128 ) ;
do {
V_27 = F_129 ( V_128 , V_139 ) ;
if ( F_130 ( V_142 ) )
continue;
V_8 = F_121 ( V_126 , V_142 , V_128 , V_27 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_142 ++ , V_128 = V_27 , V_128 != V_139 );
return 0 ;
}
static int F_131 ( struct V_146 * V_147 ,
T_1 V_6 , struct V_7 * V_7 )
{
struct V_125 * V_126 ;
int V_8 = 0 ;
if ( ! F_132 ( & V_147 -> V_148 ) ) {
F_111 ( V_7 ) ;
F_8 ( V_7 ) ;
F_133 ( & V_147 -> V_148 ) ;
F_134 ( V_7 ) ;
}
for ( V_126 = V_147 -> V_149 ; V_126 ; V_126 = V_126 -> V_150 ) {
if ( V_126 -> V_151 && ( V_8 = F_125 ( V_126 , V_6 , V_7 ) ) )
break;
}
F_135 ( & V_147 -> V_148 ) ;
return ( V_8 < 0 ) ? V_8 : 0 ;
}
static unsigned int F_136 ( struct V_3 * V_4 ,
unsigned int V_152 , bool V_153 )
{
unsigned int V_64 = V_4 -> V_64 ;
unsigned int V_154 = V_152 ;
unsigned char V_98 ;
for (; ; ) {
if ( ++ V_154 >= V_64 ) {
if ( ! V_152 ) {
V_154 = 0 ;
break;
}
V_64 = V_152 + 1 ;
V_152 = 0 ;
V_154 = 1 ;
}
if ( V_153 ) {
if ( F_137 ( V_4 , V_154 ) )
break;
else
continue;
}
V_98 = F_138 ( V_4 -> V_39 [ V_154 ] ) ;
if ( V_98 && F_1 ( V_98 ) != V_41 )
break;
}
return V_154 ;
}
int F_139 ( unsigned int type , bool V_153 ,
unsigned long V_155 )
{
struct V_3 * V_4 = V_86 [ type ] ;
struct V_146 * V_156 ;
volatile unsigned char * V_39 ;
unsigned char V_157 ;
struct V_7 * V_7 ;
T_1 V_6 ;
unsigned int V_154 = 0 ;
int V_158 = 0 ;
V_156 = & V_159 ;
F_140 ( & V_159 . V_160 ) ;
while ( ( V_154 = F_136 ( V_4 , V_154 , V_153 ) ) != 0 ) {
if ( F_141 ( V_161 ) ) {
V_158 = - V_162 ;
break;
}
V_39 = & V_4 -> V_39 [ V_154 ] ;
V_6 = F_3 ( type , V_154 ) ;
V_7 = F_142 ( V_6 ,
V_163 , NULL , 0 ) ;
if ( ! V_7 ) {
V_157 = * V_39 ;
if ( ! V_157 || V_157 == V_41 )
continue;
V_158 = - V_133 ;
break;
}
if ( F_143 ( & V_156 -> V_160 ) == 1 ) {
F_144 ( V_156 ) ;
V_156 = & V_159 ;
F_140 ( & V_159 . V_160 ) ;
}
F_145 ( V_7 ) ;
F_146 ( V_7 ) ;
F_134 ( V_7 ) ;
F_146 ( V_7 ) ;
V_157 = * V_39 ;
if ( F_1 ( V_157 ) == V_100 ) {
V_158 = F_147 ( V_6 , V_7 ) ;
if ( V_158 < 0 )
break;
continue;
}
if ( F_1 ( V_157 ) && V_156 != & V_159 )
V_158 = F_131 ( V_156 , V_6 , V_7 ) ;
if ( F_1 ( * V_39 ) ) {
int V_164 = ( * V_39 >= V_157 ) ;
struct V_23 * V_52 = & V_156 -> V_165 ;
struct V_146 * V_166 = V_156 ;
struct V_146 * V_167 = V_156 ;
struct V_146 * V_147 ;
F_140 ( & V_166 -> V_160 ) ;
F_140 ( & V_167 -> V_160 ) ;
F_30 ( & V_168 ) ;
while ( F_1 ( * V_39 ) && ! V_158 &&
( V_52 = V_52 -> V_27 ) != & V_156 -> V_165 ) {
V_147 = F_15 ( V_52 , struct V_146 , V_165 ) ;
if ( ! F_148 ( & V_147 -> V_160 ) )
continue;
F_29 ( & V_168 ) ;
F_144 ( V_167 ) ;
V_167 = V_147 ;
F_12 () ;
V_157 = * V_39 ;
if ( ! F_1 ( V_157 ) )
;
else if ( V_147 == & V_159 )
V_164 = 1 ;
else
V_158 = F_131 ( V_147 , V_6 , V_7 ) ;
if ( V_164 && * V_39 < V_157 ) {
F_144 ( V_166 ) ;
F_140 ( & V_147 -> V_160 ) ;
V_166 = V_147 ;
V_164 = 0 ;
}
F_30 ( & V_168 ) ;
}
F_29 ( & V_168 ) ;
F_144 ( V_167 ) ;
F_144 ( V_156 ) ;
V_156 = V_166 ;
}
if ( V_158 ) {
F_8 ( V_7 ) ;
F_9 ( V_7 ) ;
break;
}
if ( F_1 ( * V_39 ) &&
F_149 ( V_7 ) && F_76 ( V_7 ) ) {
struct V_169 V_170 = {
. V_171 = V_172 ,
} ;
F_150 ( V_7 , & V_170 ) ;
F_134 ( V_7 ) ;
F_146 ( V_7 ) ;
}
if ( F_76 ( V_7 ) &&
F_151 ( F_66 ( V_7 ) == V_6 . V_9 ) )
F_78 ( V_7 ) ;
F_79 ( V_7 ) ;
F_8 ( V_7 ) ;
F_9 ( V_7 ) ;
F_12 () ;
if ( V_153 && V_155 > 0 ) {
if ( ! -- V_155 )
break;
}
}
F_144 ( V_156 ) ;
return V_158 ;
}
static void F_152 ( void )
{
struct V_23 * V_52 , * V_27 ;
unsigned int type ;
for ( type = 0 ; type < V_88 ; type ++ )
if ( V_86 [ type ] -> V_73 )
return;
F_30 ( & V_168 ) ;
F_153 (p, next, &init_mm.mmlist)
F_154 ( V_52 ) ;
F_29 ( & V_168 ) ;
}
static T_2 F_89 ( T_1 V_6 , struct V_117 * * V_18 )
{
struct V_3 * V_120 ;
struct V_10 * V_173 ;
struct V_10 * V_11 ;
T_3 V_5 ;
V_120 = V_86 [ F_54 ( V_6 ) ] ;
* V_18 = V_120 -> V_18 ;
V_5 = F_55 ( V_6 ) ;
V_173 = V_120 -> V_21 ;
V_11 = V_173 ;
for ( ; ; ) {
struct V_23 * V_24 ;
if ( V_11 -> V_20 <= V_5 &&
V_5 < ( V_11 -> V_20 + V_11 -> V_17 ) ) {
return V_11 -> V_12 + ( V_5 - V_11 -> V_20 ) ;
}
V_24 = V_11 -> V_26 . V_27 ;
V_11 = F_15 ( V_24 , struct V_10 , V_26 ) ;
V_120 -> V_21 = V_11 ;
F_155 ( V_11 == V_173 ) ;
}
}
T_2 F_156 ( struct V_7 * V_7 , struct V_117 * * V_18 )
{
T_1 V_6 ;
V_6 . V_9 = F_66 ( V_7 ) ;
return F_89 ( V_6 , V_18 ) ;
}
static void F_157 ( struct V_3 * V_120 )
{
while ( ! F_158 ( & V_120 -> V_15 . V_26 ) ) {
struct V_10 * V_11 ;
V_11 = F_15 ( V_120 -> V_15 . V_26 . V_27 ,
struct V_10 , V_26 ) ;
F_159 ( & V_11 -> V_26 ) ;
F_160 ( V_11 ) ;
}
if ( V_120 -> V_31 & V_174 ) {
struct V_175 * V_176 = V_120 -> V_176 ;
struct V_177 * V_178 = V_176 -> V_179 ;
V_120 -> V_31 &= ~ V_174 ;
V_178 -> V_180 -> V_181 ( V_176 ) ;
}
}
int
F_161 ( struct V_3 * V_120 , unsigned long V_20 ,
unsigned long V_17 , T_2 V_12 )
{
struct V_10 * V_11 ;
struct V_10 * V_182 ;
struct V_23 * V_24 ;
if ( V_20 == 0 ) {
V_11 = & V_120 -> V_15 ;
V_120 -> V_21 = V_11 ;
V_11 -> V_20 = 0 ;
V_11 -> V_17 = V_17 ;
V_11 -> V_12 = V_12 ;
return 1 ;
} else {
V_24 = V_120 -> V_15 . V_26 . V_152 ;
V_11 = F_15 ( V_24 , struct V_10 , V_26 ) ;
F_155 ( V_11 -> V_20 + V_11 -> V_17 != V_20 ) ;
if ( V_11 -> V_12 + V_11 -> V_17 == V_12 ) {
V_11 -> V_17 += V_17 ;
return 0 ;
}
}
V_182 = F_162 ( sizeof( * V_11 ) , V_19 ) ;
if ( V_182 == NULL )
return - V_133 ;
V_182 -> V_20 = V_20 ;
V_182 -> V_17 = V_17 ;
V_182 -> V_12 = V_12 ;
F_163 ( & V_182 -> V_26 , & V_120 -> V_15 . V_26 ) ;
return 1 ;
}
static int F_164 ( struct V_3 * V_120 , T_2 * V_183 )
{
struct V_175 * V_176 = V_120 -> V_176 ;
struct V_177 * V_178 = V_176 -> V_179 ;
struct V_184 * V_184 = V_178 -> V_185 ;
int V_8 ;
if ( F_165 ( V_184 -> V_186 ) ) {
V_8 = F_161 ( V_120 , 0 , V_120 -> V_64 , 0 ) ;
* V_183 = V_120 -> V_72 ;
return V_8 ;
}
if ( V_178 -> V_180 -> V_187 ) {
V_8 = V_178 -> V_180 -> V_187 ( V_120 , V_176 , V_183 ) ;
if ( ! V_8 ) {
V_120 -> V_31 |= V_174 ;
V_8 = F_161 ( V_120 , 0 , V_120 -> V_64 , 0 ) ;
* V_183 = V_120 -> V_72 ;
}
return V_8 ;
}
return F_166 ( V_120 , V_176 , V_183 ) ;
}
static void F_167 ( struct V_3 * V_52 , int V_188 ,
unsigned char * V_39 ,
struct V_28 * V_45 )
{
if ( V_188 >= 0 )
V_52 -> V_188 = V_188 ;
else
V_52 -> V_188 = -- V_189 ;
V_52 -> V_26 . V_188 = - V_52 -> V_188 ;
V_52 -> V_80 . V_188 = - V_52 -> V_188 ;
V_52 -> V_39 = V_39 ;
V_52 -> V_45 = V_45 ;
V_52 -> V_31 |= V_54 ;
F_168 ( V_52 -> V_72 , & V_82 ) ;
V_190 += V_52 -> V_72 ;
F_169 ( & V_119 ) ;
F_61 ( & V_52 -> V_26 , & V_191 ) ;
F_30 ( & V_79 ) ;
F_61 ( & V_52 -> V_80 , & V_81 ) ;
F_29 ( & V_79 ) ;
}
static void F_170 ( struct V_3 * V_52 , int V_188 ,
unsigned char * V_39 ,
struct V_28 * V_45 ,
unsigned long * V_192 )
{
F_171 ( V_52 -> type , V_192 ) ;
F_30 ( & V_119 ) ;
F_30 ( & V_52 -> V_47 ) ;
F_167 ( V_52 , V_188 , V_39 , V_45 ) ;
F_29 ( & V_52 -> V_47 ) ;
F_29 ( & V_119 ) ;
}
static void F_172 ( struct V_3 * V_52 )
{
F_30 ( & V_119 ) ;
F_30 ( & V_52 -> V_47 ) ;
F_167 ( V_52 , V_52 -> V_188 , V_52 -> V_39 , V_52 -> V_45 ) ;
F_29 ( & V_52 -> V_47 ) ;
F_29 ( & V_119 ) ;
}
static unsigned F_173 ( struct V_175 * V_175 , T_10 * V_193 )
{
struct V_194 * V_195 = V_175 -> V_196 ;
F_174 ( V_175 , & V_197 , V_193 ) ;
if ( V_195 -> V_198 != F_143 ( & V_199 ) ) {
V_195 -> V_198 = F_143 ( & V_199 ) ;
return V_200 | V_201 | V_202 | V_203 ;
}
return V_200 | V_201 ;
}
static void * F_175 ( struct V_194 * V_204 , T_11 * V_205 )
{
struct V_3 * V_4 ;
int type ;
T_11 V_206 = * V_205 ;
F_176 ( & V_207 ) ;
if ( ! V_206 )
return V_208 ;
for ( type = 0 ; type < V_88 ; type ++ ) {
F_177 () ;
V_4 = V_86 [ type ] ;
if ( ! ( V_4 -> V_31 & V_90 ) || ! V_4 -> V_39 )
continue;
if ( ! -- V_206 )
return V_4 ;
}
return NULL ;
}
static void * F_178 ( struct V_194 * V_204 , void * V_209 , T_11 * V_205 )
{
struct V_3 * V_4 = V_209 ;
int type ;
if ( V_209 == V_208 )
type = 0 ;
else
type = V_4 -> type + 1 ;
for (; type < V_88 ; type ++ ) {
F_177 () ;
V_4 = V_86 [ type ] ;
if ( ! ( V_4 -> V_31 & V_90 ) || ! V_4 -> V_39 )
continue;
++ * V_205 ;
return V_4 ;
}
return NULL ;
}
static void F_179 ( struct V_194 * V_204 , void * V_209 )
{
F_180 ( & V_207 ) ;
}
static int F_181 ( struct V_194 * V_204 , void * V_209 )
{
struct V_3 * V_4 = V_209 ;
struct V_175 * V_175 ;
int V_210 ;
if ( V_4 == V_208 ) {
F_182 ( V_204 , L_5 ) ;
return 0 ;
}
V_175 = V_4 -> V_176 ;
V_210 = F_183 ( V_204 , V_175 , L_6 ) ;
F_184 ( V_204 , L_7 ,
V_210 < 40 ? 40 - V_210 : 1 , L_8 ,
F_165 ( F_185 ( V_175 ) -> V_186 ) ?
L_9 : L_10 ,
V_4 -> V_72 << ( V_16 - 10 ) ,
V_4 -> V_73 << ( V_16 - 10 ) ,
V_4 -> V_188 ) ;
return 0 ;
}
static int F_186 ( struct V_184 * V_184 , struct V_175 * V_175 )
{
struct V_194 * V_195 ;
int V_8 ;
V_8 = F_187 ( V_175 , & V_211 ) ;
if ( V_8 )
return V_8 ;
V_195 = V_175 -> V_196 ;
V_195 -> V_198 = F_143 ( & V_199 ) ;
return 0 ;
}
static int T_12 F_188 ( void )
{
F_189 ( L_11 , 0 , NULL , & V_212 ) ;
return 0 ;
}
static int T_12 F_190 ( void )
{
F_191 () ;
return 0 ;
}
static struct V_3 * F_192 ( void )
{
struct V_3 * V_52 ;
unsigned int type ;
V_52 = F_193 ( sizeof( * V_52 ) , V_19 ) ;
if ( ! V_52 )
return F_194 ( - V_133 ) ;
F_30 ( & V_119 ) ;
for ( type = 0 ; type < V_88 ; type ++ ) {
if ( ! ( V_86 [ type ] -> V_31 & V_90 ) )
break;
}
if ( type >= V_213 ) {
F_29 ( & V_119 ) ;
F_160 ( V_52 ) ;
return F_194 ( - V_214 ) ;
}
if ( type >= V_88 ) {
V_52 -> type = type ;
V_86 [ type ] = V_52 ;
F_195 () ;
V_88 ++ ;
} else {
F_160 ( V_52 ) ;
V_52 = V_86 [ type ] ;
}
F_196 ( & V_52 -> V_15 . V_26 ) ;
F_197 ( & V_52 -> V_26 , 0 ) ;
F_197 ( & V_52 -> V_80 , 0 ) ;
V_52 -> V_31 = V_90 ;
F_29 ( & V_119 ) ;
F_198 ( & V_52 -> V_47 ) ;
return V_52 ;
}
static int F_199 ( struct V_3 * V_52 , struct V_184 * V_184 )
{
int error ;
if ( F_165 ( V_184 -> V_186 ) ) {
V_52 -> V_18 = F_86 ( F_200 ( V_184 ) ) ;
error = F_201 ( V_52 -> V_18 ,
V_215 | V_216 | V_217 , V_52 ) ;
if ( error < 0 ) {
V_52 -> V_18 = NULL ;
return error ;
}
V_52 -> V_218 = F_202 ( V_52 -> V_18 ) ;
error = F_203 ( V_52 -> V_18 , V_140 ) ;
if ( error < 0 )
return error ;
V_52 -> V_31 |= V_104 ;
} else if ( F_204 ( V_184 -> V_186 ) ) {
V_52 -> V_18 = V_184 -> V_219 -> V_220 ;
F_176 ( & V_184 -> V_221 ) ;
if ( F_205 ( V_184 ) )
return - V_222 ;
} else
return - V_223 ;
return 0 ;
}
static unsigned long F_206 ( struct V_3 * V_52 ,
union V_224 * V_224 ,
struct V_184 * V_184 )
{
int V_154 ;
unsigned long V_225 ;
unsigned long V_226 ;
unsigned long V_227 ;
if ( memcmp ( L_12 , V_224 -> V_228 . V_228 , 10 ) ) {
F_56 ( L_13 ) ;
return 0 ;
}
if ( F_207 ( V_224 -> V_29 . V_229 ) == 1 ) {
F_208 ( & V_224 -> V_29 . V_229 ) ;
F_208 ( & V_224 -> V_29 . V_227 ) ;
F_208 ( & V_224 -> V_29 . V_230 ) ;
for ( V_154 = 0 ; V_154 < V_224 -> V_29 . V_230 ; V_154 ++ )
F_208 ( & V_224 -> V_29 . V_231 [ V_154 ] ) ;
}
if ( V_224 -> V_29 . V_229 != 1 ) {
F_209 ( L_14 ,
V_224 -> V_29 . V_229 ) ;
return 0 ;
}
V_52 -> V_74 = 1 ;
V_52 -> F_20 = 1 ;
V_52 -> V_71 = 0 ;
V_225 = F_55 ( F_210 (
F_99 ( F_3 ( 0 , ~ 0UL ) ) ) ) + 1 ;
V_227 = V_224 -> V_29 . V_227 ;
if ( V_227 > V_225 ) {
F_209 ( L_15 ,
V_225 << ( V_16 - 10 ) ,
V_227 << ( V_16 - 10 ) ) ;
}
if ( V_225 > V_227 ) {
V_225 = V_227 + 1 ;
if ( ( unsigned int ) V_225 == 0 )
V_225 = V_232 ;
}
V_52 -> V_75 = V_225 - 1 ;
if ( ! V_225 )
return 0 ;
V_226 = F_211 ( V_184 ) >> V_16 ;
if ( V_226 && V_225 > V_226 ) {
F_209 ( L_16 ) ;
return 0 ;
}
if ( V_224 -> V_29 . V_230 && F_204 ( V_184 -> V_186 ) )
return 0 ;
if ( V_224 -> V_29 . V_230 > V_233 )
return 0 ;
return V_225 ;
}
static int F_212 ( struct V_3 * V_52 ,
union V_224 * V_224 ,
unsigned char * V_39 ,
struct V_28 * V_45 ,
unsigned long V_225 ,
T_2 * V_183 )
{
int V_154 ;
unsigned int V_234 ;
int V_235 ;
unsigned long V_236 = F_213 ( V_225 , V_40 ) ;
unsigned long V_38 = V_52 -> F_20 / V_40 ;
V_234 = V_225 - 1 ;
F_25 ( & V_52 -> V_48 ) ;
F_25 ( & V_52 -> V_49 ) ;
F_25 ( & V_52 -> V_42 ) ;
F_25 ( & V_52 -> V_43 ) ;
for ( V_154 = 0 ; V_154 < V_224 -> V_29 . V_230 ; V_154 ++ ) {
unsigned int V_53 = V_224 -> V_29 . V_231 [ V_154 ] ;
if ( V_53 == 0 || V_53 > V_224 -> V_29 . V_227 )
return - V_223 ;
if ( V_53 < V_225 ) {
V_39 [ V_53 ] = V_41 ;
V_234 -- ;
F_33 ( V_52 , V_45 , V_53 ) ;
}
}
for ( V_154 = V_225 ; V_154 < F_214 ( V_225 , V_40 ) ; V_154 ++ )
F_33 ( V_52 , V_45 , V_154 ) ;
if ( V_234 ) {
V_39 [ 0 ] = V_41 ;
F_33 ( V_52 , V_45 , 0 ) ;
V_52 -> V_64 = V_225 ;
V_52 -> V_72 = V_234 ;
V_235 = F_164 ( V_52 , V_183 ) ;
if ( V_235 < 0 )
return V_235 ;
V_234 = V_52 -> V_72 ;
}
if ( ! V_234 ) {
F_209 ( L_17 ) ;
return - V_223 ;
}
if ( ! V_45 )
return V_235 ;
for ( V_154 = 0 ; V_154 < V_236 ; V_154 ++ ) {
if ( ! F_17 ( & V_45 [ V_38 ] ) ) {
F_16 ( & V_45 [ V_38 ] , V_36 ) ;
if ( F_24 ( & V_52 -> V_48 ) ) {
F_22 ( & V_52 -> V_48 ,
V_38 , 0 ) ;
F_22 ( & V_52 -> V_49 ,
V_38 , 0 ) ;
} else {
unsigned int V_44 ;
V_44 = F_20 ( & V_52 -> V_49 ) ;
F_21 ( & V_45 [ V_44 ] , V_38 ) ;
F_22 ( & V_52 -> V_49 ,
V_38 , 0 ) ;
}
}
V_38 ++ ;
if ( V_38 == V_236 )
V_38 = 0 ;
}
return V_235 ;
}
static bool F_215 ( struct V_3 * V_4 )
{
struct V_237 * V_238 = F_216 ( V_4 -> V_18 ) ;
if ( ! V_238 || ! F_217 ( V_238 ) )
return false ;
return true ;
}
void F_218 ( struct V_239 * V_9 )
{
unsigned int type ;
unsigned long V_240 = 0 ;
F_30 ( & V_119 ) ;
for ( type = 0 ; type < V_88 ; type ++ ) {
struct V_3 * V_4 = V_86 [ type ] ;
if ( ( V_4 -> V_31 & V_90 ) && ! ( V_4 -> V_31 & V_54 ) )
V_240 += V_4 -> V_73 ;
}
V_9 -> V_241 = F_44 ( & V_82 ) + V_240 ;
V_9 -> V_242 = V_190 + V_240 ;
F_29 ( & V_119 ) ;
}
static int F_219 ( T_1 V_6 , unsigned char V_65 )
{
struct V_3 * V_52 ;
unsigned long V_5 , type ;
unsigned char V_98 ;
unsigned char V_99 ;
int V_14 = - V_223 ;
if ( F_82 ( V_6 ) )
goto V_87;
type = F_54 ( V_6 ) ;
if ( type >= V_88 )
goto V_243;
V_52 = V_86 [ type ] ;
V_5 = F_55 ( V_6 ) ;
F_30 ( & V_52 -> V_47 ) ;
if ( F_40 ( V_5 >= V_52 -> V_64 ) )
goto V_244;
V_98 = V_52 -> V_39 [ V_5 ] ;
if ( F_40 ( F_1 ( V_98 ) == V_41 ) ) {
V_14 = - V_245 ;
goto V_244;
}
V_99 = V_98 & V_2 ;
V_98 &= ~ V_2 ;
V_14 = 0 ;
if ( V_65 == V_2 ) {
if ( ! V_99 && V_98 )
V_99 = V_2 ;
else if ( V_99 )
V_14 = - V_246 ;
else
V_14 = - V_245 ;
} else if ( V_98 || V_99 ) {
if ( ( V_98 & ~ V_101 ) < V_102 )
V_98 += V_65 ;
else if ( ( V_98 & ~ V_101 ) > V_102 )
V_14 = - V_223 ;
else if ( F_58 ( V_52 , V_5 , V_98 ) )
V_98 = V_101 ;
else
V_14 = - V_133 ;
} else
V_14 = - V_245 ;
V_52 -> V_39 [ V_5 ] = V_98 | V_99 ;
V_244:
F_29 ( & V_52 -> V_47 ) ;
V_87:
return V_14 ;
V_243:
F_56 ( L_18 , V_97 , V_6 . V_9 ) ;
goto V_87;
}
void F_220 ( T_1 V_6 )
{
F_219 ( V_6 , V_100 ) ;
}
int F_221 ( T_1 V_6 )
{
int V_14 = 0 ;
while ( ! V_14 && F_219 ( V_6 , 1 ) == - V_133 )
V_14 = F_222 ( V_6 , V_247 ) ;
return V_14 ;
}
int F_223 ( T_1 V_6 )
{
return F_219 ( V_6 , V_2 ) ;
}
struct V_3 * F_224 ( struct V_7 * V_7 )
{
T_1 V_204 = { . V_9 = F_66 (page) } ;
F_155 ( ! F_76 ( V_7 ) ) ;
return V_86 [ F_54 ( V_204 ) ] ;
}
struct V_177 * F_225 ( struct V_7 * V_7 )
{
F_72 ( ! F_76 ( V_7 ) , V_7 ) ;
return F_224 ( V_7 ) -> V_176 -> V_179 ;
}
T_3 F_226 ( struct V_7 * V_7 )
{
T_1 V_204 = { . V_9 = F_66 (page) } ;
F_72 ( ! F_76 ( V_7 ) , V_7 ) ;
return F_55 ( V_204 ) ;
}
int F_222 ( T_1 V_6 , T_13 V_248 )
{
struct V_3 * V_4 ;
struct V_7 * V_249 ;
struct V_7 * V_7 ;
struct V_7 * V_250 ;
T_3 V_5 ;
unsigned char V_98 ;
V_7 = F_227 ( V_248 | V_251 ) ;
V_4 = F_53 ( V_6 ) ;
if ( ! V_4 ) {
goto V_252;
}
V_5 = F_55 ( V_6 ) ;
V_98 = V_4 -> V_39 [ V_5 ] & ~ V_2 ;
if ( ( V_98 & ~ V_101 ) != V_102 ) {
goto V_87;
}
if ( ! V_7 ) {
F_29 ( & V_4 -> V_47 ) ;
return - V_133 ;
}
V_249 = F_68 ( V_4 -> V_39 + V_5 ) ;
V_5 &= ~ V_112 ;
if ( ! F_66 ( V_249 ) ) {
F_155 ( V_98 & V_101 ) ;
F_196 ( & V_249 -> V_114 ) ;
F_228 ( V_249 , V_113 ) ;
V_4 -> V_31 |= V_113 ;
}
F_13 (list_page, &head->lru, lru) {
unsigned char * V_111 ;
if ( ! ( V_98 & V_101 ) )
goto V_87;
V_111 = F_69 ( V_250 ) + V_5 ;
V_98 = * V_111 ;
F_70 ( V_111 ) ;
if ( ( V_98 & ~ V_101 ) != V_115 )
goto V_87;
}
F_163 ( & V_7 -> V_114 , & V_249 -> V_114 ) ;
V_7 = NULL ;
V_87:
F_29 ( & V_4 -> V_47 ) ;
V_252:
if ( V_7 )
F_229 ( V_7 ) ;
return 0 ;
}
static bool F_58 ( struct V_3 * V_4 ,
T_3 V_5 , unsigned char V_98 )
{
struct V_7 * V_249 ;
struct V_7 * V_7 ;
unsigned char * V_111 ;
V_249 = F_68 ( V_4 -> V_39 + V_5 ) ;
if ( F_66 ( V_249 ) != V_113 ) {
F_155 ( V_98 & V_101 ) ;
return false ;
}
V_5 &= ~ V_112 ;
V_7 = F_15 ( V_249 -> V_114 . V_27 , struct V_7 , V_114 ) ;
V_111 = F_69 ( V_7 ) + V_5 ;
if ( V_98 == V_102 )
goto V_253;
if ( V_98 == ( V_102 | V_101 ) ) {
while ( * V_111 == ( V_115 | V_101 ) ) {
F_70 ( V_111 ) ;
V_7 = F_15 ( V_7 -> V_114 . V_27 , struct V_7 , V_114 ) ;
F_155 ( V_7 == V_249 ) ;
V_111 = F_69 ( V_7 ) + V_5 ;
}
if ( * V_111 == V_115 ) {
F_70 ( V_111 ) ;
V_7 = F_15 ( V_7 -> V_114 . V_27 , struct V_7 , V_114 ) ;
if ( V_7 == V_249 )
return false ;
V_111 = F_69 ( V_7 ) + V_5 ;
V_253: * V_111 = 0 ;
}
* V_111 += 1 ;
F_70 ( V_111 ) ;
V_7 = F_15 ( V_7 -> V_114 . V_152 , struct V_7 , V_114 ) ;
while ( V_7 != V_249 ) {
V_111 = F_69 ( V_7 ) + V_5 ;
* V_111 = V_101 ;
F_70 ( V_111 ) ;
V_7 = F_15 ( V_7 -> V_114 . V_152 , struct V_7 , V_114 ) ;
}
return true ;
} else {
F_155 ( V_98 != V_101 ) ;
while ( * V_111 == V_101 ) {
F_70 ( V_111 ) ;
V_7 = F_15 ( V_7 -> V_114 . V_27 , struct V_7 , V_114 ) ;
F_155 ( V_7 == V_249 ) ;
V_111 = F_69 ( V_7 ) + V_5 ;
}
F_155 ( * V_111 == 0 ) ;
* V_111 -= 1 ;
if ( * V_111 == 0 )
V_98 = 0 ;
F_70 ( V_111 ) ;
V_7 = F_15 ( V_7 -> V_114 . V_152 , struct V_7 , V_114 ) ;
while ( V_7 != V_249 ) {
V_111 = F_69 ( V_7 ) + V_5 ;
* V_111 = V_115 | V_98 ;
V_98 = V_101 ;
F_70 ( V_111 ) ;
V_7 = F_15 ( V_7 -> V_114 . V_152 , struct V_7 , V_114 ) ;
}
return V_98 == V_101 ;
}
}
static void F_230 ( struct V_3 * V_4 )
{
T_3 V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_64 ; V_5 += V_140 ) {
struct V_7 * V_249 ;
V_249 = F_68 ( V_4 -> V_39 + V_5 ) ;
if ( F_66 ( V_249 ) ) {
struct V_23 * V_254 , * V_27 ;
F_153 (this, next, &head->lru) {
struct V_7 * V_7 ;
V_7 = F_15 ( V_254 , struct V_7 , V_114 ) ;
F_159 ( V_254 ) ;
F_229 ( V_7 ) ;
}
}
}
}
