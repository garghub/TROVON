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
void F_64 ( T_1 V_6 , struct V_7 * V_7 )
{
struct V_3 * V_52 ;
unsigned char V_98 ;
V_52 = F_53 ( V_6 ) ;
if ( V_52 ) {
V_98 = F_57 ( V_52 , V_6 , V_2 ) ;
if ( V_7 )
F_65 ( V_7 , V_6 , V_98 != 0 ) ;
F_29 ( & V_52 -> V_47 ) ;
}
}
int F_66 ( struct V_7 * V_7 )
{
int V_98 = 0 ;
struct V_3 * V_52 ;
T_1 V_6 ;
V_6 . V_9 = F_67 ( V_7 ) ;
V_52 = F_53 ( V_6 ) ;
if ( V_52 ) {
V_98 = F_1 ( V_52 -> V_39 [ F_55 ( V_6 ) ] ) ;
F_29 ( & V_52 -> V_47 ) ;
}
return V_98 ;
}
int F_68 ( struct V_7 * V_7 )
{
int V_98 ;
F_69 ( ! F_70 ( V_7 ) , V_7 ) ;
if ( F_40 ( F_71 ( V_7 ) ) )
return 0 ;
V_98 = F_72 ( V_7 ) ;
if ( V_98 <= 1 && F_73 ( V_7 ) ) {
V_98 += F_66 ( V_7 ) ;
if ( V_98 == 1 && ! F_74 ( V_7 ) ) {
F_75 ( V_7 ) ;
F_76 ( V_7 ) ;
}
}
return V_98 <= 1 ;
}
int F_7 ( struct V_7 * V_7 )
{
F_69 ( ! F_70 ( V_7 ) , V_7 ) ;
if ( ! F_73 ( V_7 ) )
return 0 ;
if ( F_74 ( V_7 ) )
return 0 ;
if ( F_66 ( V_7 ) )
return 0 ;
if ( F_77 () )
return 0 ;
F_75 ( V_7 ) ;
F_76 ( V_7 ) ;
return 1 ;
}
int F_78 ( T_1 V_6 )
{
struct V_3 * V_52 ;
struct V_7 * V_7 = NULL ;
if ( F_79 ( V_6 ) )
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
if ( F_73 ( V_7 ) && ! F_74 ( V_7 ) &&
( ! F_80 ( V_7 ) || F_41 () ) ) {
F_75 ( V_7 ) ;
F_76 ( V_7 ) ;
}
F_8 ( V_7 ) ;
F_9 ( V_7 ) ;
}
return V_52 != NULL ;
}
int F_81 ( T_4 V_110 , T_2 V_5 , struct V_111 * * V_112 )
{
struct V_111 * V_18 = NULL ;
int type ;
if ( V_110 )
V_18 = F_82 ( V_110 ) ;
F_30 ( & V_113 ) ;
for ( type = 0 ; type < V_88 ; type ++ ) {
struct V_3 * V_114 = V_86 [ type ] ;
if ( ! ( V_114 -> V_31 & V_54 ) )
continue;
if ( ! V_18 ) {
if ( V_112 )
* V_112 = F_83 ( V_114 -> V_18 ) ;
F_29 ( & V_113 ) ;
return type ;
}
if ( V_18 == V_114 -> V_18 ) {
struct V_10 * V_11 = & V_114 -> V_15 ;
if ( V_11 -> V_12 == V_5 ) {
if ( V_112 )
* V_112 = F_83 ( V_114 -> V_18 ) ;
F_29 ( & V_113 ) ;
F_84 ( V_18 ) ;
return type ;
}
}
}
F_29 ( & V_113 ) ;
if ( V_18 )
F_84 ( V_18 ) ;
return - V_115 ;
}
T_2 F_85 ( int type , T_3 V_5 )
{
struct V_111 * V_18 ;
if ( ( unsigned int ) type >= V_88 )
return 0 ;
if ( ! ( V_86 [ type ] -> V_31 & V_54 ) )
return 0 ;
return F_86 ( F_3 ( type , V_5 ) , & V_18 ) ;
}
unsigned int F_87 ( int type , int free )
{
unsigned int V_35 = 0 ;
F_30 ( & V_113 ) ;
if ( ( unsigned int ) type < V_88 ) {
struct V_3 * V_114 = V_86 [ type ] ;
F_30 ( & V_114 -> V_47 ) ;
if ( V_114 -> V_31 & V_54 ) {
V_35 = V_114 -> V_72 ;
if ( free )
V_35 -= V_114 -> V_73 ;
}
F_29 ( & V_114 -> V_47 ) ;
}
F_29 ( & V_113 ) ;
return V_35 ;
}
static inline int F_88 ( T_5 V_116 , T_5 V_117 )
{
#ifdef F_89
T_5 V_118 = F_90 ( V_117 ) ;
return F_91 ( V_116 , V_117 ) || F_91 ( V_116 , V_118 ) ;
#else
return F_91 ( V_116 , V_117 ) ;
#endif
}
static int F_92 ( struct V_119 * V_120 , T_6 * V_121 ,
unsigned long V_122 , T_1 V_6 , struct V_7 * V_7 )
{
struct V_7 * V_123 ;
struct V_124 * V_125 ;
T_7 * V_126 ;
T_5 * V_116 ;
int V_8 = 1 ;
V_123 = V_7 ;
V_7 = F_93 ( V_7 , V_120 , V_122 ) ;
if ( F_40 ( ! V_7 ) )
return - V_127 ;
if ( F_94 ( V_120 -> V_128 , V_7 ,
V_19 , & V_125 ) ) {
V_8 = - V_127 ;
goto V_129;
}
V_116 = F_95 ( V_120 -> V_128 , V_121 , V_122 , & V_126 ) ;
if ( F_40 ( ! F_88 ( * V_116 , F_96 ( V_6 ) ) ) ) {
F_97 ( V_125 ) ;
V_8 = 0 ;
goto V_87;
}
F_98 ( V_120 -> V_128 , V_130 ) ;
F_99 ( V_120 -> V_128 , V_131 ) ;
F_100 ( V_7 ) ;
F_101 ( V_120 -> V_128 , V_122 , V_116 ,
F_102 ( F_103 ( V_7 , V_120 -> V_132 ) ) ) ;
if ( V_7 == V_123 )
F_104 ( V_7 , V_120 , V_122 ) ;
else
F_105 ( V_7 , V_120 , V_122 ) ;
F_106 ( V_7 , V_125 ) ;
F_63 ( V_6 ) ;
F_107 ( V_7 ) ;
V_87:
F_108 ( V_116 , V_126 ) ;
V_129:
if ( V_7 != V_123 ) {
F_8 ( V_7 ) ;
F_109 ( V_7 ) ;
}
return V_8 ;
}
static int F_110 ( struct V_119 * V_120 , T_6 * V_121 ,
unsigned long V_122 , unsigned long V_133 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_5 V_117 = F_96 ( V_6 ) ;
T_5 * V_116 ;
int V_8 = 0 ;
V_116 = F_111 ( V_121 , V_122 ) ;
do {
if ( F_40 ( F_88 ( * V_116 , V_117 ) ) ) {
F_112 ( V_116 ) ;
V_8 = F_92 ( V_120 , V_121 , V_122 , V_6 , V_7 ) ;
if ( V_8 )
goto V_87;
V_116 = F_111 ( V_121 , V_122 ) ;
}
} while ( V_116 ++ , V_122 += V_134 , V_122 != V_133 );
F_112 ( V_116 - 1 ) ;
V_87:
return V_8 ;
}
static inline int F_113 ( struct V_119 * V_120 , T_8 * V_135 ,
unsigned long V_122 , unsigned long V_133 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_6 * V_121 ;
unsigned long V_27 ;
int V_8 ;
V_121 = F_114 ( V_135 , V_122 ) ;
do {
V_27 = F_115 ( V_122 , V_133 ) ;
if ( F_116 ( V_121 ) )
continue;
V_8 = F_110 ( V_120 , V_121 , V_122 , V_27 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_121 ++ , V_122 = V_27 , V_122 != V_133 );
return 0 ;
}
static inline int F_117 ( struct V_119 * V_120 , T_9 * V_136 ,
unsigned long V_122 , unsigned long V_133 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_8 * V_135 ;
unsigned long V_27 ;
int V_8 ;
V_135 = F_118 ( V_136 , V_122 ) ;
do {
V_27 = F_119 ( V_122 , V_133 ) ;
if ( F_120 ( V_135 ) )
continue;
V_8 = F_113 ( V_120 , V_135 , V_122 , V_27 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_135 ++ , V_122 = V_27 , V_122 != V_133 );
return 0 ;
}
static int F_121 ( struct V_119 * V_120 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_9 * V_136 ;
unsigned long V_122 , V_133 , V_27 ;
int V_8 ;
if ( F_122 ( V_7 ) ) {
V_122 = F_123 ( V_7 , V_120 ) ;
if ( V_122 == - V_137 )
return 0 ;
else
V_133 = V_122 + V_134 ;
} else {
V_122 = V_120 -> V_138 ;
V_133 = V_120 -> V_139 ;
}
V_136 = F_124 ( V_120 -> V_128 , V_122 ) ;
do {
V_27 = F_125 ( V_122 , V_133 ) ;
if ( F_126 ( V_136 ) )
continue;
V_8 = F_117 ( V_120 , V_136 , V_122 , V_27 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_136 ++ , V_122 = V_27 , V_122 != V_133 );
return 0 ;
}
static int F_127 ( struct V_140 * V_141 ,
T_1 V_6 , struct V_7 * V_7 )
{
struct V_119 * V_120 ;
int V_8 = 0 ;
if ( ! F_128 ( & V_141 -> V_142 ) ) {
F_107 ( V_7 ) ;
F_8 ( V_7 ) ;
F_129 ( & V_141 -> V_142 ) ;
F_130 ( V_7 ) ;
}
for ( V_120 = V_141 -> V_143 ; V_120 ; V_120 = V_120 -> V_144 ) {
if ( V_120 -> V_145 && ( V_8 = F_121 ( V_120 , V_6 , V_7 ) ) )
break;
}
F_131 ( & V_141 -> V_142 ) ;
return ( V_8 < 0 ) ? V_8 : 0 ;
}
static unsigned int F_132 ( struct V_3 * V_4 ,
unsigned int V_146 , bool V_147 )
{
unsigned int V_64 = V_4 -> V_64 ;
unsigned int V_148 = V_146 ;
unsigned char V_98 ;
for (; ; ) {
if ( ++ V_148 >= V_64 ) {
if ( ! V_146 ) {
V_148 = 0 ;
break;
}
V_64 = V_146 + 1 ;
V_146 = 0 ;
V_148 = 1 ;
}
if ( V_147 ) {
if ( F_133 ( V_4 , V_148 ) )
break;
else
continue;
}
V_98 = F_134 ( V_4 -> V_39 [ V_148 ] ) ;
if ( V_98 && F_1 ( V_98 ) != V_41 )
break;
}
return V_148 ;
}
int F_135 ( unsigned int type , bool V_147 ,
unsigned long V_149 )
{
struct V_3 * V_4 = V_86 [ type ] ;
struct V_140 * V_150 ;
volatile unsigned char * V_39 ;
unsigned char V_151 ;
struct V_7 * V_7 ;
T_1 V_6 ;
unsigned int V_148 = 0 ;
int V_152 = 0 ;
V_150 = & V_153 ;
F_136 ( & V_153 . V_154 ) ;
while ( ( V_148 = F_132 ( V_4 , V_148 , V_147 ) ) != 0 ) {
if ( F_137 ( V_155 ) ) {
V_152 = - V_156 ;
break;
}
V_39 = & V_4 -> V_39 [ V_148 ] ;
V_6 = F_3 ( type , V_148 ) ;
V_7 = F_138 ( V_6 ,
V_157 , NULL , 0 ) ;
if ( ! V_7 ) {
V_151 = * V_39 ;
if ( ! V_151 || V_151 == V_41 )
continue;
V_152 = - V_127 ;
break;
}
if ( F_139 ( & V_150 -> V_154 ) == 1 ) {
F_140 ( V_150 ) ;
V_150 = & V_153 ;
F_136 ( & V_153 . V_154 ) ;
}
F_141 ( V_7 ) ;
F_142 ( V_7 ) ;
F_130 ( V_7 ) ;
F_142 ( V_7 ) ;
V_151 = * V_39 ;
if ( F_1 ( V_151 ) == V_100 ) {
V_152 = F_143 ( V_6 , V_7 ) ;
if ( V_152 < 0 )
break;
continue;
}
if ( F_1 ( V_151 ) && V_150 != & V_153 )
V_152 = F_127 ( V_150 , V_6 , V_7 ) ;
if ( F_1 ( * V_39 ) ) {
int V_158 = ( * V_39 >= V_151 ) ;
struct V_23 * V_52 = & V_150 -> V_159 ;
struct V_140 * V_160 = V_150 ;
struct V_140 * V_161 = V_150 ;
struct V_140 * V_141 ;
F_136 ( & V_160 -> V_154 ) ;
F_136 ( & V_161 -> V_154 ) ;
F_30 ( & V_162 ) ;
while ( F_1 ( * V_39 ) && ! V_152 &&
( V_52 = V_52 -> V_27 ) != & V_150 -> V_159 ) {
V_141 = F_15 ( V_52 , struct V_140 , V_159 ) ;
if ( ! F_144 ( & V_141 -> V_154 ) )
continue;
F_29 ( & V_162 ) ;
F_140 ( V_161 ) ;
V_161 = V_141 ;
F_12 () ;
V_151 = * V_39 ;
if ( ! F_1 ( V_151 ) )
;
else if ( V_141 == & V_153 )
V_158 = 1 ;
else
V_152 = F_127 ( V_141 , V_6 , V_7 ) ;
if ( V_158 && * V_39 < V_151 ) {
F_140 ( V_160 ) ;
F_136 ( & V_141 -> V_154 ) ;
V_160 = V_141 ;
V_158 = 0 ;
}
F_30 ( & V_162 ) ;
}
F_29 ( & V_162 ) ;
F_140 ( V_161 ) ;
F_140 ( V_150 ) ;
V_150 = V_160 ;
}
if ( V_152 ) {
F_8 ( V_7 ) ;
F_9 ( V_7 ) ;
break;
}
if ( F_1 ( * V_39 ) &&
F_145 ( V_7 ) && F_73 ( V_7 ) ) {
struct V_163 V_164 = {
. V_165 = V_166 ,
} ;
F_146 ( V_7 , & V_164 ) ;
F_130 ( V_7 ) ;
F_142 ( V_7 ) ;
}
if ( F_73 ( V_7 ) &&
F_147 ( F_67 ( V_7 ) == V_6 . V_9 ) )
F_75 ( V_7 ) ;
F_76 ( V_7 ) ;
F_8 ( V_7 ) ;
F_9 ( V_7 ) ;
F_12 () ;
if ( V_147 && V_149 > 0 ) {
if ( ! -- V_149 )
break;
}
}
F_140 ( V_150 ) ;
return V_152 ;
}
static void F_148 ( void )
{
struct V_23 * V_52 , * V_27 ;
unsigned int type ;
for ( type = 0 ; type < V_88 ; type ++ )
if ( V_86 [ type ] -> V_73 )
return;
F_30 ( & V_162 ) ;
F_149 (p, next, &init_mm.mmlist)
F_150 ( V_52 ) ;
F_29 ( & V_162 ) ;
}
static T_2 F_86 ( T_1 V_6 , struct V_111 * * V_18 )
{
struct V_3 * V_114 ;
struct V_10 * V_167 ;
struct V_10 * V_11 ;
T_3 V_5 ;
V_114 = V_86 [ F_54 ( V_6 ) ] ;
* V_18 = V_114 -> V_18 ;
V_5 = F_55 ( V_6 ) ;
V_167 = V_114 -> V_21 ;
V_11 = V_167 ;
for ( ; ; ) {
struct V_23 * V_24 ;
if ( V_11 -> V_20 <= V_5 &&
V_5 < ( V_11 -> V_20 + V_11 -> V_17 ) ) {
return V_11 -> V_12 + ( V_5 - V_11 -> V_20 ) ;
}
V_24 = V_11 -> V_26 . V_27 ;
V_11 = F_15 ( V_24 , struct V_10 , V_26 ) ;
V_114 -> V_21 = V_11 ;
F_151 ( V_11 == V_167 ) ;
}
}
T_2 F_152 ( struct V_7 * V_7 , struct V_111 * * V_18 )
{
T_1 V_6 ;
V_6 . V_9 = F_67 ( V_7 ) ;
return F_86 ( V_6 , V_18 ) ;
}
static void F_153 ( struct V_3 * V_114 )
{
while ( ! F_154 ( & V_114 -> V_15 . V_26 ) ) {
struct V_10 * V_11 ;
V_11 = F_15 ( V_114 -> V_15 . V_26 . V_27 ,
struct V_10 , V_26 ) ;
F_155 ( & V_11 -> V_26 ) ;
F_156 ( V_11 ) ;
}
if ( V_114 -> V_31 & V_168 ) {
struct V_169 * V_170 = V_114 -> V_170 ;
struct V_171 * V_172 = V_170 -> V_173 ;
V_114 -> V_31 &= ~ V_168 ;
V_172 -> V_174 -> V_175 ( V_170 ) ;
}
}
int
F_157 ( struct V_3 * V_114 , unsigned long V_20 ,
unsigned long V_17 , T_2 V_12 )
{
struct V_10 * V_11 ;
struct V_10 * V_176 ;
struct V_23 * V_24 ;
if ( V_20 == 0 ) {
V_11 = & V_114 -> V_15 ;
V_114 -> V_21 = V_11 ;
V_11 -> V_20 = 0 ;
V_11 -> V_17 = V_17 ;
V_11 -> V_12 = V_12 ;
return 1 ;
} else {
V_24 = V_114 -> V_15 . V_26 . V_146 ;
V_11 = F_15 ( V_24 , struct V_10 , V_26 ) ;
F_151 ( V_11 -> V_20 + V_11 -> V_17 != V_20 ) ;
if ( V_11 -> V_12 + V_11 -> V_17 == V_12 ) {
V_11 -> V_17 += V_17 ;
return 0 ;
}
}
V_176 = F_158 ( sizeof( * V_11 ) , V_19 ) ;
if ( V_176 == NULL )
return - V_127 ;
V_176 -> V_20 = V_20 ;
V_176 -> V_17 = V_17 ;
V_176 -> V_12 = V_12 ;
F_159 ( & V_176 -> V_26 , & V_114 -> V_15 . V_26 ) ;
return 1 ;
}
static int F_160 ( struct V_3 * V_114 , T_2 * V_177 )
{
struct V_169 * V_170 = V_114 -> V_170 ;
struct V_171 * V_172 = V_170 -> V_173 ;
struct V_178 * V_178 = V_172 -> V_179 ;
int V_8 ;
if ( F_161 ( V_178 -> V_180 ) ) {
V_8 = F_157 ( V_114 , 0 , V_114 -> V_64 , 0 ) ;
* V_177 = V_114 -> V_72 ;
return V_8 ;
}
if ( V_172 -> V_174 -> V_181 ) {
V_8 = V_172 -> V_174 -> V_181 ( V_114 , V_170 , V_177 ) ;
if ( ! V_8 ) {
V_114 -> V_31 |= V_168 ;
V_8 = F_157 ( V_114 , 0 , V_114 -> V_64 , 0 ) ;
* V_177 = V_114 -> V_72 ;
}
return V_8 ;
}
return F_162 ( V_114 , V_170 , V_177 ) ;
}
static void F_163 ( struct V_3 * V_52 , int V_182 ,
unsigned char * V_39 ,
struct V_28 * V_45 )
{
if ( V_182 >= 0 )
V_52 -> V_182 = V_182 ;
else
V_52 -> V_182 = -- V_183 ;
V_52 -> V_26 . V_182 = - V_52 -> V_182 ;
V_52 -> V_80 . V_182 = - V_52 -> V_182 ;
V_52 -> V_39 = V_39 ;
V_52 -> V_45 = V_45 ;
V_52 -> V_31 |= V_54 ;
F_164 ( V_52 -> V_72 , & V_82 ) ;
V_184 += V_52 -> V_72 ;
F_165 ( & V_113 ) ;
F_61 ( & V_52 -> V_26 , & V_185 ) ;
F_30 ( & V_79 ) ;
F_61 ( & V_52 -> V_80 , & V_81 ) ;
F_29 ( & V_79 ) ;
}
static void F_166 ( struct V_3 * V_52 , int V_182 ,
unsigned char * V_39 ,
struct V_28 * V_45 ,
unsigned long * V_186 )
{
F_167 ( V_52 -> type , V_186 ) ;
F_30 ( & V_113 ) ;
F_30 ( & V_52 -> V_47 ) ;
F_163 ( V_52 , V_182 , V_39 , V_45 ) ;
F_29 ( & V_52 -> V_47 ) ;
F_29 ( & V_113 ) ;
}
static void F_168 ( struct V_3 * V_52 )
{
F_30 ( & V_113 ) ;
F_30 ( & V_52 -> V_47 ) ;
F_163 ( V_52 , V_52 -> V_182 , V_52 -> V_39 , V_52 -> V_45 ) ;
F_29 ( & V_52 -> V_47 ) ;
F_29 ( & V_113 ) ;
}
static unsigned F_169 ( struct V_169 * V_169 , T_10 * V_187 )
{
struct V_188 * V_189 = V_169 -> V_190 ;
F_170 ( V_169 , & V_191 , V_187 ) ;
if ( V_189 -> V_192 != F_139 ( & V_193 ) ) {
V_189 -> V_192 = F_139 ( & V_193 ) ;
return V_194 | V_195 | V_196 | V_197 ;
}
return V_194 | V_195 ;
}
static void * F_171 ( struct V_188 * V_198 , T_11 * V_199 )
{
struct V_3 * V_4 ;
int type ;
T_11 V_200 = * V_199 ;
F_172 ( & V_201 ) ;
if ( ! V_200 )
return V_202 ;
for ( type = 0 ; type < V_88 ; type ++ ) {
F_173 () ;
V_4 = V_86 [ type ] ;
if ( ! ( V_4 -> V_31 & V_90 ) || ! V_4 -> V_39 )
continue;
if ( ! -- V_200 )
return V_4 ;
}
return NULL ;
}
static void * F_174 ( struct V_188 * V_198 , void * V_203 , T_11 * V_199 )
{
struct V_3 * V_4 = V_203 ;
int type ;
if ( V_203 == V_202 )
type = 0 ;
else
type = V_4 -> type + 1 ;
for (; type < V_88 ; type ++ ) {
F_173 () ;
V_4 = V_86 [ type ] ;
if ( ! ( V_4 -> V_31 & V_90 ) || ! V_4 -> V_39 )
continue;
++ * V_199 ;
return V_4 ;
}
return NULL ;
}
static void F_175 ( struct V_188 * V_198 , void * V_203 )
{
F_176 ( & V_201 ) ;
}
static int F_177 ( struct V_188 * V_198 , void * V_203 )
{
struct V_3 * V_4 = V_203 ;
struct V_169 * V_169 ;
int V_204 ;
if ( V_4 == V_202 ) {
F_178 ( V_198 , L_5 ) ;
return 0 ;
}
V_169 = V_4 -> V_170 ;
V_204 = F_179 ( V_198 , & V_169 -> V_205 , L_6 ) ;
F_180 ( V_198 , L_7 ,
V_204 < 40 ? 40 - V_204 : 1 , L_8 ,
F_161 ( F_181 ( V_169 ) -> V_180 ) ?
L_9 : L_10 ,
V_4 -> V_72 << ( V_16 - 10 ) ,
V_4 -> V_73 << ( V_16 - 10 ) ,
V_4 -> V_182 ) ;
return 0 ;
}
static int F_182 ( struct V_178 * V_178 , struct V_169 * V_169 )
{
struct V_188 * V_189 ;
int V_8 ;
V_8 = F_183 ( V_169 , & V_206 ) ;
if ( V_8 )
return V_8 ;
V_189 = V_169 -> V_190 ;
V_189 -> V_192 = F_139 ( & V_193 ) ;
return 0 ;
}
static int T_12 F_184 ( void )
{
F_185 ( L_11 , 0 , NULL , & V_207 ) ;
return 0 ;
}
static int T_12 F_186 ( void )
{
F_187 () ;
return 0 ;
}
static struct V_3 * F_188 ( void )
{
struct V_3 * V_52 ;
unsigned int type ;
V_52 = F_189 ( sizeof( * V_52 ) , V_19 ) ;
if ( ! V_52 )
return F_190 ( - V_127 ) ;
F_30 ( & V_113 ) ;
for ( type = 0 ; type < V_88 ; type ++ ) {
if ( ! ( V_86 [ type ] -> V_31 & V_90 ) )
break;
}
if ( type >= V_208 ) {
F_29 ( & V_113 ) ;
F_156 ( V_52 ) ;
return F_190 ( - V_209 ) ;
}
if ( type >= V_88 ) {
V_52 -> type = type ;
V_86 [ type ] = V_52 ;
F_191 () ;
V_88 ++ ;
} else {
F_156 ( V_52 ) ;
V_52 = V_86 [ type ] ;
}
F_192 ( & V_52 -> V_15 . V_26 ) ;
F_193 ( & V_52 -> V_26 , 0 ) ;
F_193 ( & V_52 -> V_80 , 0 ) ;
V_52 -> V_31 = V_90 ;
F_29 ( & V_113 ) ;
F_194 ( & V_52 -> V_47 ) ;
return V_52 ;
}
static int F_195 ( struct V_3 * V_52 , struct V_178 * V_178 )
{
int error ;
if ( F_161 ( V_178 -> V_180 ) ) {
V_52 -> V_18 = F_83 ( F_196 ( V_178 ) ) ;
error = F_197 ( V_52 -> V_18 ,
V_210 | V_211 | V_212 ,
V_213 ) ;
if ( error < 0 ) {
V_52 -> V_18 = NULL ;
return - V_214 ;
}
V_52 -> V_215 = F_198 ( V_52 -> V_18 ) ;
error = F_199 ( V_52 -> V_18 , V_134 ) ;
if ( error < 0 )
return error ;
V_52 -> V_31 |= V_104 ;
} else if ( F_200 ( V_178 -> V_180 ) ) {
V_52 -> V_18 = V_178 -> V_216 -> V_217 ;
F_172 ( & V_178 -> V_218 ) ;
if ( F_201 ( V_178 ) )
return - V_219 ;
} else
return - V_214 ;
return 0 ;
}
static unsigned long F_202 ( struct V_3 * V_52 ,
union V_220 * V_220 ,
struct V_178 * V_178 )
{
int V_148 ;
unsigned long V_221 ;
unsigned long V_222 ;
unsigned long V_223 ;
if ( memcmp ( L_12 , V_220 -> V_224 . V_224 , 10 ) ) {
F_56 ( L_13 ) ;
return 0 ;
}
if ( F_203 ( V_220 -> V_29 . V_225 ) == 1 ) {
F_204 ( & V_220 -> V_29 . V_225 ) ;
F_204 ( & V_220 -> V_29 . V_223 ) ;
F_204 ( & V_220 -> V_29 . V_226 ) ;
for ( V_148 = 0 ; V_148 < V_220 -> V_29 . V_226 ; V_148 ++ )
F_204 ( & V_220 -> V_29 . V_227 [ V_148 ] ) ;
}
if ( V_220 -> V_29 . V_225 != 1 ) {
F_205 ( L_14 ,
V_220 -> V_29 . V_225 ) ;
return 0 ;
}
V_52 -> V_74 = 1 ;
V_52 -> F_20 = 1 ;
V_52 -> V_71 = 0 ;
V_221 = F_55 ( F_206 (
F_96 ( F_3 ( 0 , ~ 0UL ) ) ) ) + 1 ;
V_223 = V_220 -> V_29 . V_223 ;
if ( V_223 > V_221 ) {
F_205 ( L_15 ,
V_221 << ( V_16 - 10 ) ,
V_223 << ( V_16 - 10 ) ) ;
}
if ( V_221 > V_223 ) {
V_221 = V_223 + 1 ;
if ( ( unsigned int ) V_221 == 0 )
V_221 = V_228 ;
}
V_52 -> V_75 = V_221 - 1 ;
if ( ! V_221 )
return 0 ;
V_222 = F_207 ( V_178 ) >> V_16 ;
if ( V_222 && V_221 > V_222 ) {
F_205 ( L_16 ) ;
return 0 ;
}
if ( V_220 -> V_29 . V_226 && F_200 ( V_178 -> V_180 ) )
return 0 ;
if ( V_220 -> V_29 . V_226 > V_229 )
return 0 ;
return V_221 ;
}
static int F_208 ( struct V_3 * V_52 ,
union V_220 * V_220 ,
unsigned char * V_39 ,
struct V_28 * V_45 ,
unsigned long V_221 ,
T_2 * V_177 )
{
int V_148 ;
unsigned int V_230 ;
int V_231 ;
unsigned long V_232 = F_209 ( V_221 , V_40 ) ;
unsigned long V_38 = V_52 -> F_20 / V_40 ;
V_230 = V_221 - 1 ;
F_25 ( & V_52 -> V_48 ) ;
F_25 ( & V_52 -> V_49 ) ;
F_25 ( & V_52 -> V_42 ) ;
F_25 ( & V_52 -> V_43 ) ;
for ( V_148 = 0 ; V_148 < V_220 -> V_29 . V_226 ; V_148 ++ ) {
unsigned int V_53 = V_220 -> V_29 . V_227 [ V_148 ] ;
if ( V_53 == 0 || V_53 > V_220 -> V_29 . V_223 )
return - V_214 ;
if ( V_53 < V_221 ) {
V_39 [ V_53 ] = V_41 ;
V_230 -- ;
F_33 ( V_52 , V_45 , V_53 ) ;
}
}
for ( V_148 = V_221 ; V_148 < F_210 ( V_221 , V_40 ) ; V_148 ++ )
F_33 ( V_52 , V_45 , V_148 ) ;
if ( V_230 ) {
V_39 [ 0 ] = V_41 ;
F_33 ( V_52 , V_45 , 0 ) ;
V_52 -> V_64 = V_221 ;
V_52 -> V_72 = V_230 ;
V_231 = F_160 ( V_52 , V_177 ) ;
if ( V_231 < 0 )
return V_231 ;
V_230 = V_52 -> V_72 ;
}
if ( ! V_230 ) {
F_205 ( L_17 ) ;
return - V_214 ;
}
if ( ! V_45 )
return V_231 ;
for ( V_148 = 0 ; V_148 < V_232 ; V_148 ++ ) {
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
if ( V_38 == V_232 )
V_38 = 0 ;
}
return V_231 ;
}
static bool F_211 ( struct V_3 * V_4 )
{
struct V_233 * V_234 = F_212 ( V_4 -> V_18 ) ;
if ( ! V_234 || ! F_213 ( V_234 ) )
return false ;
return true ;
}
void F_214 ( struct V_235 * V_9 )
{
unsigned int type ;
unsigned long V_236 = 0 ;
F_30 ( & V_113 ) ;
for ( type = 0 ; type < V_88 ; type ++ ) {
struct V_3 * V_4 = V_86 [ type ] ;
if ( ( V_4 -> V_31 & V_90 ) && ! ( V_4 -> V_31 & V_54 ) )
V_236 += V_4 -> V_73 ;
}
V_9 -> V_237 = F_44 ( & V_82 ) + V_236 ;
V_9 -> V_238 = V_184 + V_236 ;
F_29 ( & V_113 ) ;
}
static int F_215 ( T_1 V_6 , unsigned char V_65 )
{
struct V_3 * V_52 ;
unsigned long V_5 , type ;
unsigned char V_98 ;
unsigned char V_99 ;
int V_14 = - V_214 ;
if ( F_79 ( V_6 ) )
goto V_87;
type = F_54 ( V_6 ) ;
if ( type >= V_88 )
goto V_239;
V_52 = V_86 [ type ] ;
V_5 = F_55 ( V_6 ) ;
F_30 ( & V_52 -> V_47 ) ;
if ( F_40 ( V_5 >= V_52 -> V_64 ) )
goto V_240;
V_98 = V_52 -> V_39 [ V_5 ] ;
if ( F_40 ( F_1 ( V_98 ) == V_41 ) ) {
V_14 = - V_241 ;
goto V_240;
}
V_99 = V_98 & V_2 ;
V_98 &= ~ V_2 ;
V_14 = 0 ;
if ( V_65 == V_2 ) {
if ( ! V_99 && V_98 )
V_99 = V_2 ;
else if ( V_99 )
V_14 = - V_242 ;
else
V_14 = - V_241 ;
} else if ( V_98 || V_99 ) {
if ( ( V_98 & ~ V_101 ) < V_102 )
V_98 += V_65 ;
else if ( ( V_98 & ~ V_101 ) > V_102 )
V_14 = - V_214 ;
else if ( F_58 ( V_52 , V_5 , V_98 ) )
V_98 = V_101 ;
else
V_14 = - V_127 ;
} else
V_14 = - V_241 ;
V_52 -> V_39 [ V_5 ] = V_98 | V_99 ;
V_240:
F_29 ( & V_52 -> V_47 ) ;
V_87:
return V_14 ;
V_239:
F_56 ( L_18 , V_97 , V_6 . V_9 ) ;
goto V_87;
}
void F_216 ( T_1 V_6 )
{
F_215 ( V_6 , V_100 ) ;
}
int F_217 ( T_1 V_6 )
{
int V_14 = 0 ;
while ( ! V_14 && F_215 ( V_6 , 1 ) == - V_127 )
V_14 = F_218 ( V_6 , V_243 ) ;
return V_14 ;
}
int F_219 ( T_1 V_6 )
{
return F_215 ( V_6 , V_2 ) ;
}
struct V_3 * F_220 ( struct V_7 * V_7 )
{
T_1 V_198 = { . V_9 = F_67 (page) } ;
F_151 ( ! F_73 ( V_7 ) ) ;
return V_86 [ F_54 ( V_198 ) ] ;
}
struct V_171 * F_221 ( struct V_7 * V_7 )
{
F_69 ( ! F_73 ( V_7 ) , V_7 ) ;
return F_220 ( V_7 ) -> V_170 -> V_173 ;
}
T_3 F_222 ( struct V_7 * V_7 )
{
T_1 V_198 = { . V_9 = F_67 (page) } ;
F_69 ( ! F_73 ( V_7 ) , V_7 ) ;
return F_55 ( V_198 ) ;
}
int F_218 ( T_1 V_6 , T_13 V_244 )
{
struct V_3 * V_4 ;
struct V_7 * V_245 ;
struct V_7 * V_7 ;
struct V_7 * V_246 ;
T_3 V_5 ;
unsigned char V_98 ;
V_7 = F_223 ( V_244 | V_247 ) ;
V_4 = F_53 ( V_6 ) ;
if ( ! V_4 ) {
goto V_248;
}
V_5 = F_55 ( V_6 ) ;
V_98 = V_4 -> V_39 [ V_5 ] & ~ V_2 ;
if ( ( V_98 & ~ V_101 ) != V_102 ) {
goto V_87;
}
if ( ! V_7 ) {
F_29 ( & V_4 -> V_47 ) ;
return - V_127 ;
}
V_245 = F_224 ( V_4 -> V_39 + V_5 ) ;
V_5 &= ~ V_249 ;
if ( ! F_67 ( V_245 ) ) {
F_151 ( V_98 & V_101 ) ;
F_192 ( & V_245 -> V_250 ) ;
F_225 ( V_245 , V_251 ) ;
V_4 -> V_31 |= V_251 ;
}
F_13 (list_page, &head->lru, lru) {
unsigned char * V_252 ;
if ( ! ( V_98 & V_101 ) )
goto V_87;
V_252 = F_226 ( V_246 ) + V_5 ;
V_98 = * V_252 ;
F_227 ( V_252 ) ;
if ( ( V_98 & ~ V_101 ) != V_253 )
goto V_87;
}
F_159 ( & V_7 -> V_250 , & V_245 -> V_250 ) ;
V_7 = NULL ;
V_87:
F_29 ( & V_4 -> V_47 ) ;
V_248:
if ( V_7 )
F_228 ( V_7 ) ;
return 0 ;
}
static bool F_58 ( struct V_3 * V_4 ,
T_3 V_5 , unsigned char V_98 )
{
struct V_7 * V_245 ;
struct V_7 * V_7 ;
unsigned char * V_252 ;
V_245 = F_224 ( V_4 -> V_39 + V_5 ) ;
if ( F_67 ( V_245 ) != V_251 ) {
F_151 ( V_98 & V_101 ) ;
return false ;
}
V_5 &= ~ V_249 ;
V_7 = F_15 ( V_245 -> V_250 . V_27 , struct V_7 , V_250 ) ;
V_252 = F_226 ( V_7 ) + V_5 ;
if ( V_98 == V_102 )
goto V_254;
if ( V_98 == ( V_102 | V_101 ) ) {
while ( * V_252 == ( V_253 | V_101 ) ) {
F_227 ( V_252 ) ;
V_7 = F_15 ( V_7 -> V_250 . V_27 , struct V_7 , V_250 ) ;
F_151 ( V_7 == V_245 ) ;
V_252 = F_226 ( V_7 ) + V_5 ;
}
if ( * V_252 == V_253 ) {
F_227 ( V_252 ) ;
V_7 = F_15 ( V_7 -> V_250 . V_27 , struct V_7 , V_250 ) ;
if ( V_7 == V_245 )
return false ;
V_252 = F_226 ( V_7 ) + V_5 ;
V_254: * V_252 = 0 ;
}
* V_252 += 1 ;
F_227 ( V_252 ) ;
V_7 = F_15 ( V_7 -> V_250 . V_146 , struct V_7 , V_250 ) ;
while ( V_7 != V_245 ) {
V_252 = F_226 ( V_7 ) + V_5 ;
* V_252 = V_101 ;
F_227 ( V_252 ) ;
V_7 = F_15 ( V_7 -> V_250 . V_146 , struct V_7 , V_250 ) ;
}
return true ;
} else {
F_151 ( V_98 != V_101 ) ;
while ( * V_252 == V_101 ) {
F_227 ( V_252 ) ;
V_7 = F_15 ( V_7 -> V_250 . V_27 , struct V_7 , V_250 ) ;
F_151 ( V_7 == V_245 ) ;
V_252 = F_226 ( V_7 ) + V_5 ;
}
F_151 ( * V_252 == 0 ) ;
* V_252 -= 1 ;
if ( * V_252 == 0 )
V_98 = 0 ;
F_227 ( V_252 ) ;
V_7 = F_15 ( V_7 -> V_250 . V_146 , struct V_7 , V_250 ) ;
while ( V_7 != V_245 ) {
V_252 = F_226 ( V_7 ) + V_5 ;
* V_252 = V_253 | V_98 ;
V_98 = V_101 ;
F_227 ( V_252 ) ;
V_7 = F_15 ( V_7 -> V_250 . V_146 , struct V_7 , V_250 ) ;
}
return V_98 == V_101 ;
}
}
static void F_229 ( struct V_3 * V_4 )
{
T_3 V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_64 ; V_5 += V_134 ) {
struct V_7 * V_245 ;
V_245 = F_224 ( V_4 -> V_39 + V_5 ) ;
if ( F_67 ( V_245 ) ) {
struct V_23 * V_255 , * V_27 ;
F_149 (this, next, &head->lru) {
struct V_7 * V_7 ;
V_7 = F_15 ( V_255 , struct V_7 , V_250 ) ;
F_155 ( V_255 ) ;
F_228 ( V_7 ) ;
}
}
}
}
