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
if ( ! ( V_4 -> V_31 & V_74 ) )
V_59 = V_5 = V_4 -> V_75 ;
V_66 = V_5 + V_40 - 1 ;
for (; V_66 <= V_4 -> V_76 ; V_5 ++ ) {
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
V_5 = V_4 -> V_75 ;
V_66 = V_5 + V_40 - 1 ;
for (; V_66 < V_59 ; V_5 ++ ) {
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
goto V_77;
if ( ! V_4 -> V_76 )
goto V_77;
if ( V_5 > V_4 -> V_76 )
V_59 = V_5 = V_4 -> V_75 ;
if ( F_41 () && V_4 -> V_39 [ V_5 ] == V_2 ) {
int V_78 ;
F_29 ( & V_4 -> V_47 ) ;
V_78 = F_2 ( V_4 , V_5 ) ;
F_30 ( & V_4 -> V_47 ) ;
if ( V_78 )
goto V_70;
goto V_79;
}
if ( V_4 -> V_39 [ V_5 ] )
goto V_79;
if ( V_5 == V_4 -> V_75 )
V_4 -> V_75 ++ ;
if ( V_5 == V_4 -> V_76 )
V_4 -> V_76 -- ;
V_4 -> V_73 ++ ;
if ( V_4 -> V_73 == V_4 -> V_72 ) {
V_4 -> V_75 = V_4 -> V_64 ;
V_4 -> V_76 = 0 ;
}
V_4 -> V_39 [ V_5 ] = V_65 ;
F_33 ( V_4 , V_4 -> V_45 , V_5 ) ;
V_4 -> F_20 = V_5 + 1 ;
V_4 -> V_31 -= V_69 ;
return V_5 ;
V_79:
F_29 ( & V_4 -> V_47 ) ;
while ( ++ V_5 <= V_4 -> V_76 ) {
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
V_5 = V_4 -> V_75 ;
while ( ++ V_5 < V_59 ) {
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
F_30 ( & V_4 -> V_47 ) ;
V_77:
V_4 -> V_31 -= V_69 ;
return 0 ;
}
T_1 F_42 ( void )
{
struct V_3 * V_4 ;
T_3 V_5 ;
int type , V_27 ;
int V_80 = 0 ;
int V_81 ;
F_30 ( & V_82 ) ;
if ( F_43 ( & V_83 ) <= 0 )
goto V_84;
F_44 ( & V_83 ) ;
for ( type = V_85 . V_27 ; type >= 0 && V_80 < 2 ; type = V_27 ) {
V_81 = F_45 ( & V_86 , - 1 ) ;
if ( V_81 != - 1 && V_81 != type &&
V_87 [ type ] -> V_88 < V_87 [ V_81 ] -> V_88 &&
( V_87 [ V_81 ] -> V_31 & V_54 ) ) {
type = V_81 ;
V_85 . V_27 = type ;
}
V_4 = V_87 [ type ] ;
V_27 = V_4 -> V_27 ;
if ( V_27 < 0 ||
( ! V_80 && V_4 -> V_88 != V_87 [ V_27 ] -> V_88 ) ) {
V_27 = V_85 . V_89 ;
V_80 ++ ;
}
F_30 ( & V_4 -> V_47 ) ;
if ( ! V_4 -> V_76 ) {
F_29 ( & V_4 -> V_47 ) ;
continue;
}
if ( ! ( V_4 -> V_31 & V_54 ) ) {
F_29 ( & V_4 -> V_47 ) ;
continue;
}
V_85 . V_27 = V_27 ;
F_29 ( & V_82 ) ;
V_5 = F_39 ( V_4 , V_2 ) ;
F_29 ( & V_4 -> V_47 ) ;
if ( V_5 )
return F_3 ( type , V_5 ) ;
F_30 ( & V_82 ) ;
V_27 = V_85 . V_27 ;
}
F_46 ( & V_83 ) ;
V_84:
F_29 ( & V_82 ) ;
return ( T_1 ) { 0 } ;
}
T_1 F_47 ( int type )
{
struct V_3 * V_4 ;
T_3 V_5 ;
V_4 = V_87 [ type ] ;
F_30 ( & V_4 -> V_47 ) ;
if ( V_4 && ( V_4 -> V_31 & V_54 ) ) {
F_44 ( & V_83 ) ;
V_5 = F_39 ( V_4 , 1 ) ;
if ( V_5 ) {
F_29 ( & V_4 -> V_47 ) ;
return F_3 ( type , V_5 ) ;
}
F_46 ( & V_83 ) ;
}
F_29 ( & V_4 -> V_47 ) ;
return ( T_1 ) { 0 } ;
}
static struct V_3 * F_48 ( T_1 V_6 )
{
struct V_3 * V_52 ;
unsigned long V_5 , type ;
if ( ! V_6 . V_9 )
goto V_90;
type = F_49 ( V_6 ) ;
if ( type >= V_91 )
goto V_92;
V_52 = V_87 [ type ] ;
if ( ! ( V_52 -> V_31 & V_93 ) )
goto V_94;
V_5 = F_50 ( V_6 ) ;
if ( V_5 >= V_52 -> V_64 )
goto V_95;
if ( ! V_52 -> V_39 [ V_5 ] )
goto V_96;
F_30 ( & V_52 -> V_47 ) ;
return V_52 ;
V_96:
F_51 ( L_1 , V_97 , V_6 . V_9 ) ;
goto V_90;
V_95:
F_51 ( L_1 , V_98 , V_6 . V_9 ) ;
goto V_90;
V_94:
F_51 ( L_1 , V_99 , V_6 . V_9 ) ;
goto V_90;
V_92:
F_51 ( L_1 , V_100 , V_6 . V_9 ) ;
V_90:
return NULL ;
}
static void F_52 ( int type )
{
int V_101 , V_102 ;
do {
V_101 = F_53 ( & V_86 ) ;
if ( V_101 != - 1 &&
V_87 [ V_101 ] -> V_88 >= V_87 [ type ] -> V_88 )
break;
V_102 = type ;
} while ( F_54 ( & V_86 ,
V_101 , V_102 ) != V_101 );
}
static unsigned char F_55 ( struct V_3 * V_52 ,
T_1 V_6 , unsigned char V_65 )
{
unsigned long V_5 = F_50 ( V_6 ) ;
unsigned char V_103 ;
unsigned char V_104 ;
V_103 = V_52 -> V_39 [ V_5 ] ;
V_104 = V_103 & V_2 ;
V_103 &= ~ V_2 ;
if ( V_65 == V_2 ) {
F_34 ( ! V_104 ) ;
V_104 = 0 ;
} else if ( V_103 == V_105 ) {
V_103 = 0 ;
} else if ( ( V_103 & ~ V_106 ) <= V_107 ) {
if ( V_103 == V_106 ) {
if ( F_56 ( V_52 , V_5 , V_103 ) )
V_103 = V_107 | V_106 ;
else
V_103 = V_107 ;
} else
V_103 -- ;
}
if ( ! V_103 )
F_57 ( V_6 ) ;
V_65 = V_103 | V_104 ;
V_52 -> V_39 [ V_5 ] = V_65 ;
if ( ! V_65 ) {
F_35 ( V_52 , V_52 -> V_45 , V_5 ) ;
if ( V_5 < V_52 -> V_75 )
V_52 -> V_75 = V_5 ;
if ( V_5 > V_52 -> V_76 )
V_52 -> V_76 = V_5 ;
F_52 ( V_52 -> type ) ;
F_46 ( & V_83 ) ;
V_52 -> V_73 -- ;
F_58 ( V_52 -> type , V_5 ) ;
if ( V_52 -> V_31 & V_108 ) {
struct V_109 * V_110 = V_52 -> V_18 -> V_111 ;
if ( V_110 -> V_112 -> V_113 )
V_110 -> V_112 -> V_113 ( V_52 -> V_18 ,
V_5 ) ;
}
}
return V_65 ;
}
void F_59 ( T_1 V_6 )
{
struct V_3 * V_52 ;
V_52 = F_48 ( V_6 ) ;
if ( V_52 ) {
F_55 ( V_52 , V_6 , 1 ) ;
F_29 ( & V_52 -> V_47 ) ;
}
}
void F_60 ( T_1 V_6 , struct V_7 * V_7 )
{
struct V_3 * V_52 ;
unsigned char V_103 ;
V_52 = F_48 ( V_6 ) ;
if ( V_52 ) {
V_103 = F_55 ( V_52 , V_6 , V_2 ) ;
if ( V_7 )
F_61 ( V_7 , V_6 , V_103 != 0 ) ;
F_29 ( & V_52 -> V_47 ) ;
}
}
int F_62 ( struct V_7 * V_7 )
{
int V_103 = 0 ;
struct V_3 * V_52 ;
T_1 V_6 ;
V_6 . V_9 = F_63 ( V_7 ) ;
V_52 = F_48 ( V_6 ) ;
if ( V_52 ) {
V_103 = F_1 ( V_52 -> V_39 [ F_50 ( V_6 ) ] ) ;
F_29 ( & V_52 -> V_47 ) ;
}
return V_103 ;
}
int F_64 ( struct V_7 * V_7 )
{
int V_103 ;
F_34 ( ! F_65 ( V_7 ) ) ;
if ( F_40 ( F_66 ( V_7 ) ) )
return 0 ;
V_103 = F_67 ( V_7 ) ;
if ( V_103 <= 1 && F_68 ( V_7 ) ) {
V_103 += F_62 ( V_7 ) ;
if ( V_103 == 1 && ! F_69 ( V_7 ) ) {
F_70 ( V_7 ) ;
F_71 ( V_7 ) ;
}
}
return V_103 <= 1 ;
}
int F_7 ( struct V_7 * V_7 )
{
F_34 ( ! F_65 ( V_7 ) ) ;
if ( ! F_68 ( V_7 ) )
return 0 ;
if ( F_69 ( V_7 ) )
return 0 ;
if ( F_62 ( V_7 ) )
return 0 ;
if ( F_72 () )
return 0 ;
F_70 ( V_7 ) ;
F_71 ( V_7 ) ;
return 1 ;
}
int F_73 ( T_1 V_6 )
{
struct V_3 * V_52 ;
struct V_7 * V_7 = NULL ;
if ( F_74 ( V_6 ) )
return 1 ;
V_52 = F_48 ( V_6 ) ;
if ( V_52 ) {
if ( F_55 ( V_52 , V_6 , 1 ) == V_2 ) {
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
if ( F_68 ( V_7 ) && ! F_69 ( V_7 ) &&
( ! F_75 ( V_7 ) || F_41 () ) ) {
F_70 ( V_7 ) ;
F_71 ( V_7 ) ;
}
F_8 ( V_7 ) ;
F_9 ( V_7 ) ;
}
return V_52 != NULL ;
}
int F_76 ( T_4 V_114 , T_2 V_5 , struct V_115 * * V_116 )
{
struct V_115 * V_18 = NULL ;
int type ;
if ( V_114 )
V_18 = F_77 ( V_114 ) ;
F_30 ( & V_82 ) ;
for ( type = 0 ; type < V_91 ; type ++ ) {
struct V_3 * V_117 = V_87 [ type ] ;
if ( ! ( V_117 -> V_31 & V_54 ) )
continue;
if ( ! V_18 ) {
if ( V_116 )
* V_116 = F_78 ( V_117 -> V_18 ) ;
F_29 ( & V_82 ) ;
return type ;
}
if ( V_18 == V_117 -> V_18 ) {
struct V_10 * V_11 = & V_117 -> V_15 ;
if ( V_11 -> V_12 == V_5 ) {
if ( V_116 )
* V_116 = F_78 ( V_117 -> V_18 ) ;
F_29 ( & V_82 ) ;
F_79 ( V_18 ) ;
return type ;
}
}
}
F_29 ( & V_82 ) ;
if ( V_18 )
F_79 ( V_18 ) ;
return - V_118 ;
}
T_2 F_80 ( int type , T_3 V_5 )
{
struct V_115 * V_18 ;
if ( ( unsigned int ) type >= V_91 )
return 0 ;
if ( ! ( V_87 [ type ] -> V_31 & V_54 ) )
return 0 ;
return F_81 ( F_3 ( type , V_5 ) , & V_18 ) ;
}
unsigned int F_82 ( int type , int free )
{
unsigned int V_35 = 0 ;
F_30 ( & V_82 ) ;
if ( ( unsigned int ) type < V_91 ) {
struct V_3 * V_117 = V_87 [ type ] ;
F_30 ( & V_117 -> V_47 ) ;
if ( V_117 -> V_31 & V_54 ) {
V_35 = V_117 -> V_72 ;
if ( free )
V_35 -= V_117 -> V_73 ;
}
F_29 ( & V_117 -> V_47 ) ;
}
F_29 ( & V_82 ) ;
return V_35 ;
}
static inline int F_83 ( T_5 V_119 , T_5 V_120 )
{
#ifdef F_84
T_5 V_121 = F_85 ( V_120 ) ;
return F_86 ( V_119 , V_120 ) || F_86 ( V_119 , V_121 ) ;
#else
return F_86 ( V_119 , V_120 ) ;
#endif
}
static int F_87 ( struct V_122 * V_123 , T_6 * V_124 ,
unsigned long V_125 , T_1 V_6 , struct V_7 * V_7 )
{
struct V_7 * V_126 ;
struct V_127 * V_128 ;
T_7 * V_129 ;
T_5 * V_119 ;
int V_8 = 1 ;
V_126 = V_7 ;
V_7 = F_88 ( V_7 , V_123 , V_125 ) ;
if ( F_40 ( ! V_7 ) )
return - V_130 ;
if ( F_89 ( V_123 -> V_131 , V_7 ,
V_19 , & V_128 ) ) {
V_8 = - V_130 ;
goto V_132;
}
V_119 = F_90 ( V_123 -> V_131 , V_124 , V_125 , & V_129 ) ;
if ( F_40 ( ! F_83 ( * V_119 , F_91 ( V_6 ) ) ) ) {
F_92 ( V_128 ) ;
V_8 = 0 ;
goto V_90;
}
F_93 ( V_123 -> V_131 , V_133 ) ;
F_94 ( V_123 -> V_131 , V_134 ) ;
F_95 ( V_7 ) ;
F_96 ( V_123 -> V_131 , V_125 , V_119 ,
F_97 ( F_98 ( V_7 , V_123 -> V_135 ) ) ) ;
if ( V_7 == V_126 )
F_99 ( V_7 , V_123 , V_125 ) ;
else
F_100 ( V_7 , V_123 , V_125 ) ;
F_101 ( V_7 , V_128 ) ;
F_59 ( V_6 ) ;
F_102 ( V_7 ) ;
V_90:
F_103 ( V_119 , V_129 ) ;
V_132:
if ( V_7 != V_126 ) {
F_8 ( V_7 ) ;
F_104 ( V_7 ) ;
}
return V_8 ;
}
static int F_105 ( struct V_122 * V_123 , T_6 * V_124 ,
unsigned long V_125 , unsigned long V_136 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_5 V_120 = F_91 ( V_6 ) ;
T_5 * V_119 ;
int V_8 = 0 ;
V_119 = F_106 ( V_124 , V_125 ) ;
do {
if ( F_40 ( F_83 ( * V_119 , V_120 ) ) ) {
F_107 ( V_119 ) ;
V_8 = F_87 ( V_123 , V_124 , V_125 , V_6 , V_7 ) ;
if ( V_8 )
goto V_90;
V_119 = F_106 ( V_124 , V_125 ) ;
}
} while ( V_119 ++ , V_125 += V_137 , V_125 != V_136 );
F_107 ( V_119 - 1 ) ;
V_90:
return V_8 ;
}
static inline int F_108 ( struct V_122 * V_123 , T_8 * V_138 ,
unsigned long V_125 , unsigned long V_136 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_6 * V_124 ;
unsigned long V_27 ;
int V_8 ;
V_124 = F_109 ( V_138 , V_125 ) ;
do {
V_27 = F_110 ( V_125 , V_136 ) ;
if ( F_111 ( V_124 ) )
continue;
V_8 = F_105 ( V_123 , V_124 , V_125 , V_27 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_124 ++ , V_125 = V_27 , V_125 != V_136 );
return 0 ;
}
static inline int F_112 ( struct V_122 * V_123 , T_9 * V_139 ,
unsigned long V_125 , unsigned long V_136 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_8 * V_138 ;
unsigned long V_27 ;
int V_8 ;
V_138 = F_113 ( V_139 , V_125 ) ;
do {
V_27 = F_114 ( V_125 , V_136 ) ;
if ( F_115 ( V_138 ) )
continue;
V_8 = F_108 ( V_123 , V_138 , V_125 , V_27 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_138 ++ , V_125 = V_27 , V_125 != V_136 );
return 0 ;
}
static int F_116 ( struct V_122 * V_123 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_9 * V_139 ;
unsigned long V_125 , V_136 , V_27 ;
int V_8 ;
if ( F_117 ( V_7 ) ) {
V_125 = F_118 ( V_7 , V_123 ) ;
if ( V_125 == - V_140 )
return 0 ;
else
V_136 = V_125 + V_137 ;
} else {
V_125 = V_123 -> V_141 ;
V_136 = V_123 -> V_142 ;
}
V_139 = F_119 ( V_123 -> V_131 , V_125 ) ;
do {
V_27 = F_120 ( V_125 , V_136 ) ;
if ( F_121 ( V_139 ) )
continue;
V_8 = F_112 ( V_123 , V_139 , V_125 , V_27 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_139 ++ , V_125 = V_27 , V_125 != V_136 );
return 0 ;
}
static int F_122 ( struct V_143 * V_144 ,
T_1 V_6 , struct V_7 * V_7 )
{
struct V_122 * V_123 ;
int V_8 = 0 ;
if ( ! F_123 ( & V_144 -> V_145 ) ) {
F_102 ( V_7 ) ;
F_8 ( V_7 ) ;
F_124 ( & V_144 -> V_145 ) ;
F_125 ( V_7 ) ;
}
for ( V_123 = V_144 -> V_146 ; V_123 ; V_123 = V_123 -> V_147 ) {
if ( V_123 -> V_148 && ( V_8 = F_116 ( V_123 , V_6 , V_7 ) ) )
break;
}
F_126 ( & V_144 -> V_145 ) ;
return ( V_8 < 0 ) ? V_8 : 0 ;
}
static unsigned int F_127 ( struct V_3 * V_4 ,
unsigned int V_149 , bool V_150 )
{
unsigned int V_64 = V_4 -> V_64 ;
unsigned int V_151 = V_149 ;
unsigned char V_103 ;
for (; ; ) {
if ( ++ V_151 >= V_64 ) {
if ( ! V_149 ) {
V_151 = 0 ;
break;
}
V_64 = V_149 + 1 ;
V_149 = 0 ;
V_151 = 1 ;
}
if ( V_150 ) {
if ( F_128 ( V_4 , V_151 ) )
break;
else
continue;
}
V_103 = F_129 ( V_4 -> V_39 [ V_151 ] ) ;
if ( V_103 && F_1 ( V_103 ) != V_41 )
break;
}
return V_151 ;
}
int F_130 ( unsigned int type , bool V_150 ,
unsigned long V_152 )
{
struct V_3 * V_4 = V_87 [ type ] ;
struct V_143 * V_153 ;
volatile unsigned char * V_39 ;
unsigned char V_154 ;
struct V_7 * V_7 ;
T_1 V_6 ;
unsigned int V_151 = 0 ;
int V_155 = 0 ;
V_153 = & V_156 ;
F_131 ( & V_156 . V_157 ) ;
while ( ( V_151 = F_127 ( V_4 , V_151 , V_150 ) ) != 0 ) {
if ( F_132 ( V_158 ) ) {
V_155 = - V_159 ;
break;
}
V_39 = & V_4 -> V_39 [ V_151 ] ;
V_6 = F_3 ( type , V_151 ) ;
V_7 = F_133 ( V_6 ,
V_160 , NULL , 0 ) ;
if ( ! V_7 ) {
V_154 = * V_39 ;
if ( ! V_154 || V_154 == V_41 )
continue;
V_155 = - V_130 ;
break;
}
if ( F_53 ( & V_153 -> V_157 ) == 1 ) {
F_134 ( V_153 ) ;
V_153 = & V_156 ;
F_131 ( & V_156 . V_157 ) ;
}
F_135 ( V_7 ) ;
F_136 ( V_7 ) ;
F_125 ( V_7 ) ;
F_136 ( V_7 ) ;
V_154 = * V_39 ;
if ( F_1 ( V_154 ) == V_105 ) {
V_155 = F_137 ( V_6 , V_7 ) ;
if ( V_155 < 0 )
break;
continue;
}
if ( F_1 ( V_154 ) && V_153 != & V_156 )
V_155 = F_122 ( V_153 , V_6 , V_7 ) ;
if ( F_1 ( * V_39 ) ) {
int V_161 = ( * V_39 >= V_154 ) ;
struct V_23 * V_52 = & V_153 -> V_162 ;
struct V_143 * V_163 = V_153 ;
struct V_143 * V_164 = V_153 ;
struct V_143 * V_144 ;
F_131 ( & V_163 -> V_157 ) ;
F_131 ( & V_164 -> V_157 ) ;
F_30 ( & V_165 ) ;
while ( F_1 ( * V_39 ) && ! V_155 &&
( V_52 = V_52 -> V_27 ) != & V_153 -> V_162 ) {
V_144 = F_15 ( V_52 , struct V_143 , V_162 ) ;
if ( ! F_138 ( & V_144 -> V_157 ) )
continue;
F_29 ( & V_165 ) ;
F_134 ( V_164 ) ;
V_164 = V_144 ;
F_12 () ;
V_154 = * V_39 ;
if ( ! F_1 ( V_154 ) )
;
else if ( V_144 == & V_156 )
V_161 = 1 ;
else
V_155 = F_122 ( V_144 , V_6 , V_7 ) ;
if ( V_161 && * V_39 < V_154 ) {
F_134 ( V_163 ) ;
F_131 ( & V_144 -> V_157 ) ;
V_163 = V_144 ;
V_161 = 0 ;
}
F_30 ( & V_165 ) ;
}
F_29 ( & V_165 ) ;
F_134 ( V_164 ) ;
F_134 ( V_153 ) ;
V_153 = V_163 ;
}
if ( V_155 ) {
F_8 ( V_7 ) ;
F_9 ( V_7 ) ;
break;
}
if ( F_1 ( * V_39 ) &&
F_139 ( V_7 ) && F_68 ( V_7 ) ) {
struct V_166 V_167 = {
. V_168 = V_169 ,
} ;
F_140 ( V_7 , & V_167 ) ;
F_125 ( V_7 ) ;
F_136 ( V_7 ) ;
}
if ( F_68 ( V_7 ) &&
F_141 ( F_63 ( V_7 ) == V_6 . V_9 ) )
F_70 ( V_7 ) ;
F_71 ( V_7 ) ;
F_8 ( V_7 ) ;
F_9 ( V_7 ) ;
F_12 () ;
if ( V_150 && V_152 > 0 ) {
if ( ! -- V_152 )
break;
}
}
F_134 ( V_153 ) ;
return V_155 ;
}
static void F_142 ( void )
{
struct V_23 * V_52 , * V_27 ;
unsigned int type ;
for ( type = 0 ; type < V_91 ; type ++ )
if ( V_87 [ type ] -> V_73 )
return;
F_30 ( & V_165 ) ;
F_143 (p, next, &init_mm.mmlist)
F_144 ( V_52 ) ;
F_29 ( & V_165 ) ;
}
static T_2 F_81 ( T_1 V_6 , struct V_115 * * V_18 )
{
struct V_3 * V_117 ;
struct V_10 * V_170 ;
struct V_10 * V_11 ;
T_3 V_5 ;
V_117 = V_87 [ F_49 ( V_6 ) ] ;
* V_18 = V_117 -> V_18 ;
V_5 = F_50 ( V_6 ) ;
V_170 = V_117 -> V_21 ;
V_11 = V_170 ;
for ( ; ; ) {
struct V_23 * V_24 ;
if ( V_11 -> V_20 <= V_5 &&
V_5 < ( V_11 -> V_20 + V_11 -> V_17 ) ) {
return V_11 -> V_12 + ( V_5 - V_11 -> V_20 ) ;
}
V_24 = V_11 -> V_26 . V_27 ;
V_11 = F_15 ( V_24 , struct V_10 , V_26 ) ;
V_117 -> V_21 = V_11 ;
F_145 ( V_11 == V_170 ) ;
}
}
T_2 F_146 ( struct V_7 * V_7 , struct V_115 * * V_18 )
{
T_1 V_6 ;
V_6 . V_9 = F_63 ( V_7 ) ;
return F_81 ( V_6 , V_18 ) ;
}
static void F_147 ( struct V_3 * V_117 )
{
while ( ! F_148 ( & V_117 -> V_15 . V_26 ) ) {
struct V_10 * V_11 ;
V_11 = F_15 ( V_117 -> V_15 . V_26 . V_27 ,
struct V_10 , V_26 ) ;
F_149 ( & V_11 -> V_26 ) ;
F_150 ( V_11 ) ;
}
if ( V_117 -> V_31 & V_171 ) {
struct V_172 * V_173 = V_117 -> V_173 ;
struct V_174 * V_175 = V_173 -> V_176 ;
V_117 -> V_31 &= ~ V_171 ;
V_175 -> V_177 -> V_178 ( V_173 ) ;
}
}
int
F_151 ( struct V_3 * V_117 , unsigned long V_20 ,
unsigned long V_17 , T_2 V_12 )
{
struct V_10 * V_11 ;
struct V_10 * V_179 ;
struct V_23 * V_24 ;
if ( V_20 == 0 ) {
V_11 = & V_117 -> V_15 ;
V_117 -> V_21 = V_11 ;
V_11 -> V_20 = 0 ;
V_11 -> V_17 = V_17 ;
V_11 -> V_12 = V_12 ;
return 1 ;
} else {
V_24 = V_117 -> V_15 . V_26 . V_149 ;
V_11 = F_15 ( V_24 , struct V_10 , V_26 ) ;
F_145 ( V_11 -> V_20 + V_11 -> V_17 != V_20 ) ;
if ( V_11 -> V_12 + V_11 -> V_17 == V_12 ) {
V_11 -> V_17 += V_17 ;
return 0 ;
}
}
V_179 = F_152 ( sizeof( * V_11 ) , V_19 ) ;
if ( V_179 == NULL )
return - V_130 ;
V_179 -> V_20 = V_20 ;
V_179 -> V_17 = V_17 ;
V_179 -> V_12 = V_12 ;
F_153 ( & V_179 -> V_26 , & V_117 -> V_15 . V_26 ) ;
return 1 ;
}
static int F_154 ( struct V_3 * V_117 , T_2 * V_180 )
{
struct V_172 * V_173 = V_117 -> V_173 ;
struct V_174 * V_175 = V_173 -> V_176 ;
struct V_181 * V_181 = V_175 -> V_182 ;
int V_8 ;
if ( F_155 ( V_181 -> V_183 ) ) {
V_8 = F_151 ( V_117 , 0 , V_117 -> V_64 , 0 ) ;
* V_180 = V_117 -> V_72 ;
return V_8 ;
}
if ( V_175 -> V_177 -> V_184 ) {
V_8 = V_175 -> V_177 -> V_184 ( V_117 , V_173 , V_180 ) ;
if ( ! V_8 ) {
V_117 -> V_31 |= V_171 ;
V_8 = F_151 ( V_117 , 0 , V_117 -> V_64 , 0 ) ;
* V_180 = V_117 -> V_72 ;
}
return V_8 ;
}
return F_156 ( V_117 , V_173 , V_180 ) ;
}
static void F_157 ( struct V_3 * V_52 , int V_88 ,
unsigned char * V_39 ,
struct V_28 * V_45 )
{
int V_151 , V_149 ;
if ( V_88 >= 0 )
V_52 -> V_88 = V_88 ;
else
V_52 -> V_88 = -- V_185 ;
V_52 -> V_39 = V_39 ;
V_52 -> V_45 = V_45 ;
V_52 -> V_31 |= V_54 ;
F_158 ( V_52 -> V_72 , & V_83 ) ;
V_186 += V_52 -> V_72 ;
V_149 = - 1 ;
for ( V_151 = V_85 . V_89 ; V_151 >= 0 ; V_151 = V_87 [ V_151 ] -> V_27 ) {
if ( V_52 -> V_88 >= V_87 [ V_151 ] -> V_88 )
break;
V_149 = V_151 ;
}
V_52 -> V_27 = V_151 ;
if ( V_149 < 0 )
V_85 . V_89 = V_85 . V_27 = V_52 -> type ;
else
V_87 [ V_149 ] -> V_27 = V_52 -> type ;
}
static void F_159 ( struct V_3 * V_52 , int V_88 ,
unsigned char * V_39 ,
struct V_28 * V_45 ,
unsigned long * V_187 )
{
F_160 ( V_52 -> type , V_187 ) ;
F_30 ( & V_82 ) ;
F_30 ( & V_52 -> V_47 ) ;
F_157 ( V_52 , V_88 , V_39 , V_45 ) ;
F_29 ( & V_52 -> V_47 ) ;
F_29 ( & V_82 ) ;
}
static void F_161 ( struct V_3 * V_52 )
{
F_30 ( & V_82 ) ;
F_30 ( & V_52 -> V_47 ) ;
F_157 ( V_52 , V_52 -> V_88 , V_52 -> V_39 , V_52 -> V_45 ) ;
F_29 ( & V_52 -> V_47 ) ;
F_29 ( & V_82 ) ;
}
static unsigned F_162 ( struct V_172 * V_172 , T_10 * V_188 )
{
struct V_189 * V_190 = V_172 -> V_191 ;
F_163 ( V_172 , & V_192 , V_188 ) ;
if ( V_190 -> V_193 != F_53 ( & V_194 ) ) {
V_190 -> V_193 = F_53 ( & V_194 ) ;
return V_195 | V_196 | V_197 | V_198 ;
}
return V_195 | V_196 ;
}
static void * F_164 ( struct V_189 * V_199 , T_11 * V_200 )
{
struct V_3 * V_4 ;
int type ;
T_11 V_201 = * V_200 ;
F_165 ( & V_202 ) ;
if ( ! V_201 )
return V_203 ;
for ( type = 0 ; type < V_91 ; type ++ ) {
F_166 () ;
V_4 = V_87 [ type ] ;
if ( ! ( V_4 -> V_31 & V_93 ) || ! V_4 -> V_39 )
continue;
if ( ! -- V_201 )
return V_4 ;
}
return NULL ;
}
static void * F_167 ( struct V_189 * V_199 , void * V_204 , T_11 * V_200 )
{
struct V_3 * V_4 = V_204 ;
int type ;
if ( V_204 == V_203 )
type = 0 ;
else
type = V_4 -> type + 1 ;
for (; type < V_91 ; type ++ ) {
F_166 () ;
V_4 = V_87 [ type ] ;
if ( ! ( V_4 -> V_31 & V_93 ) || ! V_4 -> V_39 )
continue;
++ * V_200 ;
return V_4 ;
}
return NULL ;
}
static void F_168 ( struct V_189 * V_199 , void * V_204 )
{
F_169 ( & V_202 ) ;
}
static int F_170 ( struct V_189 * V_199 , void * V_204 )
{
struct V_3 * V_4 = V_204 ;
struct V_172 * V_172 ;
int V_205 ;
if ( V_4 == V_203 ) {
F_171 ( V_199 , L_2 ) ;
return 0 ;
}
V_172 = V_4 -> V_173 ;
V_205 = F_172 ( V_199 , & V_172 -> V_206 , L_3 ) ;
F_173 ( V_199 , L_4 ,
V_205 < 40 ? 40 - V_205 : 1 , L_5 ,
F_155 ( F_174 ( V_172 ) -> V_183 ) ?
L_6 : L_7 ,
V_4 -> V_72 << ( V_16 - 10 ) ,
V_4 -> V_73 << ( V_16 - 10 ) ,
V_4 -> V_88 ) ;
return 0 ;
}
static int F_175 ( struct V_181 * V_181 , struct V_172 * V_172 )
{
struct V_189 * V_190 ;
int V_8 ;
V_8 = F_176 ( V_172 , & V_207 ) ;
if ( V_8 )
return V_8 ;
V_190 = V_172 -> V_191 ;
V_190 -> V_193 = F_53 ( & V_194 ) ;
return 0 ;
}
static int T_12 F_177 ( void )
{
F_178 ( L_8 , 0 , NULL , & V_208 ) ;
return 0 ;
}
static int T_12 F_179 ( void )
{
F_180 () ;
return 0 ;
}
static struct V_3 * F_181 ( void )
{
struct V_3 * V_52 ;
unsigned int type ;
V_52 = F_182 ( sizeof( * V_52 ) , V_19 ) ;
if ( ! V_52 )
return F_183 ( - V_130 ) ;
F_30 ( & V_82 ) ;
for ( type = 0 ; type < V_91 ; type ++ ) {
if ( ! ( V_87 [ type ] -> V_31 & V_93 ) )
break;
}
if ( type >= V_209 ) {
F_29 ( & V_82 ) ;
F_150 ( V_52 ) ;
return F_183 ( - V_210 ) ;
}
if ( type >= V_91 ) {
V_52 -> type = type ;
V_87 [ type ] = V_52 ;
F_184 () ;
V_91 ++ ;
} else {
F_150 ( V_52 ) ;
V_52 = V_87 [ type ] ;
}
F_185 ( & V_52 -> V_15 . V_26 ) ;
V_52 -> V_31 = V_93 ;
V_52 -> V_27 = - 1 ;
F_29 ( & V_82 ) ;
F_186 ( & V_52 -> V_47 ) ;
return V_52 ;
}
static int F_187 ( struct V_3 * V_52 , struct V_181 * V_181 )
{
int error ;
if ( F_155 ( V_181 -> V_183 ) ) {
V_52 -> V_18 = F_78 ( F_188 ( V_181 ) ) ;
error = F_189 ( V_52 -> V_18 ,
V_211 | V_212 | V_213 ,
V_214 ) ;
if ( error < 0 ) {
V_52 -> V_18 = NULL ;
return - V_215 ;
}
V_52 -> V_216 = F_190 ( V_52 -> V_18 ) ;
error = F_191 ( V_52 -> V_18 , V_137 ) ;
if ( error < 0 )
return error ;
V_52 -> V_31 |= V_108 ;
} else if ( F_192 ( V_181 -> V_183 ) ) {
V_52 -> V_18 = V_181 -> V_217 -> V_218 ;
F_165 ( & V_181 -> V_219 ) ;
if ( F_193 ( V_181 ) )
return - V_220 ;
} else
return - V_215 ;
return 0 ;
}
static unsigned long F_194 ( struct V_3 * V_52 ,
union V_221 * V_221 ,
struct V_181 * V_181 )
{
int V_151 ;
unsigned long V_222 ;
unsigned long V_223 ;
unsigned long V_224 ;
if ( memcmp ( L_9 , V_221 -> V_225 . V_225 , 10 ) ) {
F_51 ( L_10 ) ;
return 0 ;
}
if ( F_195 ( V_221 -> V_29 . V_226 ) == 1 ) {
F_196 ( & V_221 -> V_29 . V_226 ) ;
F_196 ( & V_221 -> V_29 . V_224 ) ;
F_196 ( & V_221 -> V_29 . V_227 ) ;
for ( V_151 = 0 ; V_151 < V_221 -> V_29 . V_227 ; V_151 ++ )
F_196 ( & V_221 -> V_29 . V_228 [ V_151 ] ) ;
}
if ( V_221 -> V_29 . V_226 != 1 ) {
F_197 ( L_11 ,
V_221 -> V_29 . V_226 ) ;
return 0 ;
}
V_52 -> V_75 = 1 ;
V_52 -> F_20 = 1 ;
V_52 -> V_71 = 0 ;
V_222 = F_50 ( F_198 (
F_91 ( F_3 ( 0 , ~ 0UL ) ) ) ) + 1 ;
V_224 = V_221 -> V_29 . V_224 ;
if ( V_224 > V_222 ) {
F_197 ( L_12 ,
V_222 << ( V_16 - 10 ) ,
V_224 << ( V_16 - 10 ) ) ;
}
if ( V_222 > V_224 ) {
V_222 = V_224 + 1 ;
if ( ( unsigned int ) V_222 == 0 )
V_222 = V_229 ;
}
V_52 -> V_76 = V_222 - 1 ;
if ( ! V_222 )
return 0 ;
V_223 = F_199 ( V_181 ) >> V_16 ;
if ( V_223 && V_222 > V_223 ) {
F_197 ( L_13 ) ;
return 0 ;
}
if ( V_221 -> V_29 . V_227 && F_192 ( V_181 -> V_183 ) )
return 0 ;
if ( V_221 -> V_29 . V_227 > V_230 )
return 0 ;
return V_222 ;
}
static int F_200 ( struct V_3 * V_52 ,
union V_221 * V_221 ,
unsigned char * V_39 ,
struct V_28 * V_45 ,
unsigned long V_222 ,
T_2 * V_180 )
{
int V_151 ;
unsigned int V_231 ;
int V_232 ;
unsigned long V_233 = F_201 ( V_222 , V_40 ) ;
unsigned long V_38 = V_52 -> F_20 / V_40 ;
V_231 = V_222 - 1 ;
F_25 ( & V_52 -> V_48 ) ;
F_25 ( & V_52 -> V_49 ) ;
F_25 ( & V_52 -> V_42 ) ;
F_25 ( & V_52 -> V_43 ) ;
for ( V_151 = 0 ; V_151 < V_221 -> V_29 . V_227 ; V_151 ++ ) {
unsigned int V_53 = V_221 -> V_29 . V_228 [ V_151 ] ;
if ( V_53 == 0 || V_53 > V_221 -> V_29 . V_224 )
return - V_215 ;
if ( V_53 < V_222 ) {
V_39 [ V_53 ] = V_41 ;
V_231 -- ;
F_33 ( V_52 , V_45 , V_53 ) ;
}
}
for ( V_151 = V_222 ; V_151 < F_202 ( V_222 , V_40 ) ; V_151 ++ )
F_33 ( V_52 , V_45 , V_151 ) ;
if ( V_231 ) {
V_39 [ 0 ] = V_41 ;
F_33 ( V_52 , V_45 , 0 ) ;
V_52 -> V_64 = V_222 ;
V_52 -> V_72 = V_231 ;
V_232 = F_154 ( V_52 , V_180 ) ;
if ( V_232 < 0 )
return V_232 ;
V_231 = V_52 -> V_72 ;
}
if ( ! V_231 ) {
F_197 ( L_14 ) ;
return - V_215 ;
}
if ( ! V_45 )
return V_232 ;
for ( V_151 = 0 ; V_151 < V_233 ; V_151 ++ ) {
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
if ( V_38 == V_233 )
V_38 = 0 ;
}
return V_232 ;
}
static bool F_203 ( struct V_3 * V_4 )
{
struct V_234 * V_235 = F_204 ( V_4 -> V_18 ) ;
if ( ! V_235 || ! F_205 ( V_235 ) )
return false ;
return true ;
}
void F_206 ( struct V_236 * V_9 )
{
unsigned int type ;
unsigned long V_237 = 0 ;
F_30 ( & V_82 ) ;
for ( type = 0 ; type < V_91 ; type ++ ) {
struct V_3 * V_4 = V_87 [ type ] ;
if ( ( V_4 -> V_31 & V_93 ) && ! ( V_4 -> V_31 & V_54 ) )
V_237 += V_4 -> V_73 ;
}
V_9 -> V_238 = F_43 ( & V_83 ) + V_237 ;
V_9 -> V_239 = V_186 + V_237 ;
F_29 ( & V_82 ) ;
}
static int F_207 ( T_1 V_6 , unsigned char V_65 )
{
struct V_3 * V_52 ;
unsigned long V_5 , type ;
unsigned char V_103 ;
unsigned char V_104 ;
int V_14 = - V_215 ;
if ( F_74 ( V_6 ) )
goto V_90;
type = F_49 ( V_6 ) ;
if ( type >= V_91 )
goto V_240;
V_52 = V_87 [ type ] ;
V_5 = F_50 ( V_6 ) ;
F_30 ( & V_52 -> V_47 ) ;
if ( F_40 ( V_5 >= V_52 -> V_64 ) )
goto V_241;
V_103 = V_52 -> V_39 [ V_5 ] ;
if ( F_40 ( F_1 ( V_103 ) == V_41 ) ) {
V_14 = - V_242 ;
goto V_241;
}
V_104 = V_103 & V_2 ;
V_103 &= ~ V_2 ;
V_14 = 0 ;
if ( V_65 == V_2 ) {
if ( ! V_104 && V_103 )
V_104 = V_2 ;
else if ( V_104 )
V_14 = - V_243 ;
else
V_14 = - V_242 ;
} else if ( V_103 || V_104 ) {
if ( ( V_103 & ~ V_106 ) < V_107 )
V_103 += V_65 ;
else if ( ( V_103 & ~ V_106 ) > V_107 )
V_14 = - V_215 ;
else if ( F_56 ( V_52 , V_5 , V_103 ) )
V_103 = V_106 ;
else
V_14 = - V_130 ;
} else
V_14 = - V_242 ;
V_52 -> V_39 [ V_5 ] = V_103 | V_104 ;
V_241:
F_29 ( & V_52 -> V_47 ) ;
V_90:
return V_14 ;
V_240:
F_51 ( L_15 , V_100 , V_6 . V_9 ) ;
goto V_90;
}
void F_208 ( T_1 V_6 )
{
F_207 ( V_6 , V_105 ) ;
}
int F_209 ( T_1 V_6 )
{
int V_14 = 0 ;
while ( ! V_14 && F_207 ( V_6 , 1 ) == - V_130 )
V_14 = F_210 ( V_6 , V_244 ) ;
return V_14 ;
}
int F_211 ( T_1 V_6 )
{
return F_207 ( V_6 , V_2 ) ;
}
struct V_3 * F_212 ( struct V_7 * V_7 )
{
T_1 V_199 = { . V_9 = F_63 (page) } ;
F_145 ( ! F_68 ( V_7 ) ) ;
return V_87 [ F_49 ( V_199 ) ] ;
}
struct V_174 * F_213 ( struct V_7 * V_7 )
{
F_34 ( ! F_68 ( V_7 ) ) ;
return F_212 ( V_7 ) -> V_173 -> V_176 ;
}
T_3 F_214 ( struct V_7 * V_7 )
{
T_1 V_199 = { . V_9 = F_63 (page) } ;
F_34 ( ! F_68 ( V_7 ) ) ;
return F_50 ( V_199 ) ;
}
int F_210 ( T_1 V_6 , T_13 V_245 )
{
struct V_3 * V_4 ;
struct V_7 * V_89 ;
struct V_7 * V_7 ;
struct V_7 * V_246 ;
T_3 V_5 ;
unsigned char V_103 ;
V_7 = F_215 ( V_245 | V_247 ) ;
V_4 = F_48 ( V_6 ) ;
if ( ! V_4 ) {
goto V_248;
}
V_5 = F_50 ( V_6 ) ;
V_103 = V_4 -> V_39 [ V_5 ] & ~ V_2 ;
if ( ( V_103 & ~ V_106 ) != V_107 ) {
goto V_90;
}
if ( ! V_7 ) {
F_29 ( & V_4 -> V_47 ) ;
return - V_130 ;
}
V_89 = F_216 ( V_4 -> V_39 + V_5 ) ;
V_5 &= ~ V_249 ;
if ( ! F_63 ( V_89 ) ) {
F_145 ( V_103 & V_106 ) ;
F_185 ( & V_89 -> V_250 ) ;
F_217 ( V_89 , V_251 ) ;
V_4 -> V_31 |= V_251 ;
}
F_13 (list_page, &head->lru, lru) {
unsigned char * V_252 ;
if ( ! ( V_103 & V_106 ) )
goto V_90;
V_252 = F_218 ( V_246 ) + V_5 ;
V_103 = * V_252 ;
F_219 ( V_252 ) ;
if ( ( V_103 & ~ V_106 ) != V_253 )
goto V_90;
}
F_153 ( & V_7 -> V_250 , & V_89 -> V_250 ) ;
V_7 = NULL ;
V_90:
F_29 ( & V_4 -> V_47 ) ;
V_248:
if ( V_7 )
F_220 ( V_7 ) ;
return 0 ;
}
static bool F_56 ( struct V_3 * V_4 ,
T_3 V_5 , unsigned char V_103 )
{
struct V_7 * V_89 ;
struct V_7 * V_7 ;
unsigned char * V_252 ;
V_89 = F_216 ( V_4 -> V_39 + V_5 ) ;
if ( F_63 ( V_89 ) != V_251 ) {
F_145 ( V_103 & V_106 ) ;
return false ;
}
V_5 &= ~ V_249 ;
V_7 = F_15 ( V_89 -> V_250 . V_27 , struct V_7 , V_250 ) ;
V_252 = F_218 ( V_7 ) + V_5 ;
if ( V_103 == V_107 )
goto V_254;
if ( V_103 == ( V_107 | V_106 ) ) {
while ( * V_252 == ( V_253 | V_106 ) ) {
F_219 ( V_252 ) ;
V_7 = F_15 ( V_7 -> V_250 . V_27 , struct V_7 , V_250 ) ;
F_145 ( V_7 == V_89 ) ;
V_252 = F_218 ( V_7 ) + V_5 ;
}
if ( * V_252 == V_253 ) {
F_219 ( V_252 ) ;
V_7 = F_15 ( V_7 -> V_250 . V_27 , struct V_7 , V_250 ) ;
if ( V_7 == V_89 )
return false ;
V_252 = F_218 ( V_7 ) + V_5 ;
V_254: * V_252 = 0 ;
}
* V_252 += 1 ;
F_219 ( V_252 ) ;
V_7 = F_15 ( V_7 -> V_250 . V_149 , struct V_7 , V_250 ) ;
while ( V_7 != V_89 ) {
V_252 = F_218 ( V_7 ) + V_5 ;
* V_252 = V_106 ;
F_219 ( V_252 ) ;
V_7 = F_15 ( V_7 -> V_250 . V_149 , struct V_7 , V_250 ) ;
}
return true ;
} else {
F_145 ( V_103 != V_106 ) ;
while ( * V_252 == V_106 ) {
F_219 ( V_252 ) ;
V_7 = F_15 ( V_7 -> V_250 . V_27 , struct V_7 , V_250 ) ;
F_145 ( V_7 == V_89 ) ;
V_252 = F_218 ( V_7 ) + V_5 ;
}
F_145 ( * V_252 == 0 ) ;
* V_252 -= 1 ;
if ( * V_252 == 0 )
V_103 = 0 ;
F_219 ( V_252 ) ;
V_7 = F_15 ( V_7 -> V_250 . V_149 , struct V_7 , V_250 ) ;
while ( V_7 != V_89 ) {
V_252 = F_218 ( V_7 ) + V_5 ;
* V_252 = V_253 | V_103 ;
V_103 = V_106 ;
F_219 ( V_252 ) ;
V_7 = F_15 ( V_7 -> V_250 . V_149 , struct V_7 , V_250 ) ;
}
return V_103 == V_106 ;
}
}
static void F_221 ( struct V_3 * V_4 )
{
T_3 V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_64 ; V_5 += V_137 ) {
struct V_7 * V_89 ;
V_89 = F_216 ( V_4 -> V_39 + V_5 ) ;
if ( F_63 ( V_89 ) ) {
struct V_23 * V_255 , * V_27 ;
F_143 (this, next, &head->lru) {
struct V_7 * V_7 ;
V_7 = F_15 ( V_255 , struct V_7 , V_250 ) ;
F_149 ( V_255 ) ;
F_220 ( V_7 ) ;
}
}
}
}
