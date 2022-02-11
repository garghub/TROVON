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
V_7 = F_4 ( & V_9 , V_6 . V_10 ) ;
if ( ! V_7 )
return 0 ;
if ( F_5 ( V_7 ) ) {
V_8 = F_6 ( V_7 ) ;
F_7 ( V_7 ) ;
}
F_8 ( V_7 ) ;
return V_8 ;
}
static int F_9 ( struct V_3 * V_4 )
{
struct V_11 * V_12 ;
T_2 V_13 ;
T_2 V_14 ;
int V_15 = 0 ;
V_12 = & V_4 -> V_16 ;
V_13 = ( V_12 -> V_13 + 1 ) << ( V_17 - 9 ) ;
V_14 = ( ( T_2 ) V_12 -> V_18 - 1 ) << ( V_17 - 9 ) ;
if ( V_14 ) {
V_15 = F_10 ( V_4 -> V_19 , V_13 ,
V_14 , V_20 , 0 ) ;
if ( V_15 )
return V_15 ;
F_11 () ;
}
F_12 (se, &si->first_swap_extent.list, list) {
V_13 = V_12 -> V_13 << ( V_17 - 9 ) ;
V_14 = ( T_2 ) V_12 -> V_18 << ( V_17 - 9 ) ;
V_15 = F_10 ( V_4 -> V_19 , V_13 ,
V_14 , V_20 , 0 ) ;
if ( V_15 )
break;
F_11 () ;
}
return V_15 ;
}
static void F_13 ( struct V_3 * V_4 ,
T_3 V_21 , T_3 V_18 )
{
struct V_11 * V_12 = V_4 -> V_22 ;
int V_23 = 0 ;
while ( V_18 ) {
struct V_24 * V_25 ;
if ( V_12 -> V_21 <= V_21 &&
V_21 < V_12 -> V_21 + V_12 -> V_18 ) {
T_3 V_5 = V_21 - V_12 -> V_21 ;
T_2 V_13 = V_12 -> V_13 + V_5 ;
T_2 V_14 = V_12 -> V_18 - V_5 ;
if ( V_14 > V_18 )
V_14 = V_18 ;
V_21 += V_14 ;
V_18 -= V_14 ;
if ( ! V_23 ++ )
V_4 -> V_22 = V_12 ;
V_13 <<= V_17 - 9 ;
V_14 <<= V_17 - 9 ;
if ( F_10 ( V_4 -> V_19 , V_13 ,
V_14 , V_26 , 0 ) )
break;
}
V_25 = V_12 -> V_27 . V_28 ;
V_12 = F_14 ( V_25 , struct V_11 , V_27 ) ;
}
}
static int F_15 ( void * V_29 )
{
F_16 () ;
return 0 ;
}
static unsigned long F_17 ( struct V_3 * V_4 ,
unsigned char V_30 )
{
unsigned long V_5 ;
unsigned long V_31 ;
unsigned long V_32 = 0 ;
int V_33 = V_34 ;
int V_35 = 0 ;
V_4 -> V_36 += V_37 ;
V_31 = V_5 = V_4 -> V_38 ;
if ( F_18 ( ! V_4 -> V_39 -- ) ) {
if ( V_4 -> V_40 - V_4 -> V_41 < V_42 ) {
V_4 -> V_39 = V_42 - 1 ;
goto V_43;
}
if ( V_4 -> V_36 & V_44 ) {
if ( V_4 -> V_45 )
goto V_43;
V_4 -> V_45 = V_4 -> V_46 ;
V_4 -> V_47 = 0 ;
}
F_19 ( & V_48 ) ;
if ( ! ( V_4 -> V_36 & V_49 ) )
V_31 = V_5 = V_4 -> V_50 ;
V_32 = V_5 + V_42 - 1 ;
for (; V_32 <= V_4 -> V_51 ; V_5 ++ ) {
if ( V_4 -> V_52 [ V_5 ] )
V_32 = V_5 + V_42 ;
else if ( V_5 == V_32 ) {
F_20 ( & V_48 ) ;
V_5 -= V_42 - 1 ;
V_4 -> V_38 = V_5 ;
V_4 -> V_39 = V_42 - 1 ;
V_35 = 1 ;
goto V_43;
}
if ( F_18 ( -- V_33 < 0 ) ) {
F_11 () ;
V_33 = V_34 ;
}
}
V_5 = V_4 -> V_50 ;
V_32 = V_5 + V_42 - 1 ;
for (; V_32 < V_31 ; V_5 ++ ) {
if ( V_4 -> V_52 [ V_5 ] )
V_32 = V_5 + V_42 ;
else if ( V_5 == V_32 ) {
F_20 ( & V_48 ) ;
V_5 -= V_42 - 1 ;
V_4 -> V_38 = V_5 ;
V_4 -> V_39 = V_42 - 1 ;
V_35 = 1 ;
goto V_43;
}
if ( F_18 ( -- V_33 < 0 ) ) {
F_11 () ;
V_33 = V_34 ;
}
}
V_5 = V_31 ;
F_20 ( & V_48 ) ;
V_4 -> V_39 = V_42 - 1 ;
V_4 -> V_45 = 0 ;
}
V_43:
if ( ! ( V_4 -> V_36 & V_53 ) )
goto V_54;
if ( ! V_4 -> V_51 )
goto V_54;
if ( V_5 > V_4 -> V_51 )
V_31 = V_5 = V_4 -> V_50 ;
if ( F_21 () && V_4 -> V_52 [ V_5 ] == V_2 ) {
int V_55 ;
F_19 ( & V_48 ) ;
V_55 = F_2 ( V_4 , V_5 ) ;
F_20 ( & V_48 ) ;
if ( V_55 )
goto V_43;
goto V_56;
}
if ( V_4 -> V_52 [ V_5 ] )
goto V_56;
if ( V_5 == V_4 -> V_50 )
V_4 -> V_50 ++ ;
if ( V_5 == V_4 -> V_51 )
V_4 -> V_51 -- ;
V_4 -> V_41 ++ ;
if ( V_4 -> V_41 == V_4 -> V_40 ) {
V_4 -> V_50 = V_4 -> V_46 ;
V_4 -> V_51 = 0 ;
}
V_4 -> V_52 [ V_5 ] = V_30 ;
V_4 -> V_38 = V_5 + 1 ;
V_4 -> V_36 -= V_37 ;
if ( V_4 -> V_45 ) {
if ( V_35 ) {
if ( V_5 < V_4 -> V_47 &&
V_4 -> V_45 <= V_32 )
V_32 = V_4 -> V_45 - 1 ;
V_4 -> V_36 |= V_57 ;
F_19 ( & V_48 ) ;
if ( V_5 < V_32 )
F_13 ( V_4 , V_5 ,
V_32 - V_5 + 1 ) ;
F_20 ( & V_48 ) ;
V_4 -> V_45 = 0 ;
V_4 -> V_36 &= ~ V_57 ;
F_22 () ;
F_23 ( & V_4 -> V_36 , F_24 ( V_57 ) ) ;
} else if ( V_4 -> V_36 & V_57 ) {
F_19 ( & V_48 ) ;
F_25 ( & V_4 -> V_36 , F_24 ( V_57 ) ,
F_15 , V_58 ) ;
F_20 ( & V_48 ) ;
} else {
if ( V_5 < V_4 -> V_45 )
V_4 -> V_45 = V_5 ;
if ( V_5 > V_4 -> V_47 )
V_4 -> V_47 = V_5 ;
}
}
return V_5 ;
V_56:
F_19 ( & V_48 ) ;
while ( ++ V_5 <= V_4 -> V_51 ) {
if ( ! V_4 -> V_52 [ V_5 ] ) {
F_20 ( & V_48 ) ;
goto V_43;
}
if ( F_21 () && V_4 -> V_52 [ V_5 ] == V_2 ) {
F_20 ( & V_48 ) ;
goto V_43;
}
if ( F_18 ( -- V_33 < 0 ) ) {
F_11 () ;
V_33 = V_34 ;
}
}
V_5 = V_4 -> V_50 ;
while ( ++ V_5 < V_31 ) {
if ( ! V_4 -> V_52 [ V_5 ] ) {
F_20 ( & V_48 ) ;
goto V_43;
}
if ( F_21 () && V_4 -> V_52 [ V_5 ] == V_2 ) {
F_20 ( & V_48 ) ;
goto V_43;
}
if ( F_18 ( -- V_33 < 0 ) ) {
F_11 () ;
V_33 = V_34 ;
}
}
F_20 ( & V_48 ) ;
V_54:
V_4 -> V_36 -= V_37 ;
return 0 ;
}
T_1 F_26 ( void )
{
struct V_3 * V_4 ;
T_3 V_5 ;
int type , V_28 ;
int V_59 = 0 ;
F_20 ( & V_48 ) ;
if ( V_60 <= 0 )
goto V_61;
V_60 -- ;
for ( type = V_62 . V_28 ; type >= 0 && V_59 < 2 ; type = V_28 ) {
V_4 = V_63 [ type ] ;
V_28 = V_4 -> V_28 ;
if ( V_28 < 0 ||
( ! V_59 && V_4 -> V_64 != V_63 [ V_28 ] -> V_64 ) ) {
V_28 = V_62 . V_65 ;
V_59 ++ ;
}
if ( ! V_4 -> V_51 )
continue;
if ( ! ( V_4 -> V_36 & V_53 ) )
continue;
V_62 . V_28 = V_28 ;
V_5 = F_17 ( V_4 , V_2 ) ;
if ( V_5 ) {
F_19 ( & V_48 ) ;
return F_3 ( type , V_5 ) ;
}
V_28 = V_62 . V_28 ;
}
V_60 ++ ;
V_61:
F_19 ( & V_48 ) ;
return ( T_1 ) { 0 } ;
}
T_1 F_27 ( int type )
{
struct V_3 * V_4 ;
T_3 V_5 ;
F_20 ( & V_48 ) ;
V_4 = V_63 [ type ] ;
if ( V_4 && ( V_4 -> V_36 & V_53 ) ) {
V_60 -- ;
V_5 = F_17 ( V_4 , 1 ) ;
if ( V_5 ) {
F_19 ( & V_48 ) ;
return F_3 ( type , V_5 ) ;
}
V_60 ++ ;
}
F_19 ( & V_48 ) ;
return ( T_1 ) { 0 } ;
}
static struct V_3 * F_28 ( T_1 V_6 )
{
struct V_3 * V_66 ;
unsigned long V_5 , type ;
if ( ! V_6 . V_10 )
goto V_67;
type = F_29 ( V_6 ) ;
if ( type >= V_68 )
goto V_69;
V_66 = V_63 [ type ] ;
if ( ! ( V_66 -> V_36 & V_70 ) )
goto V_71;
V_5 = F_30 ( V_6 ) ;
if ( V_5 >= V_66 -> V_46 )
goto V_72;
if ( ! V_66 -> V_52 [ V_5 ] )
goto V_73;
F_20 ( & V_48 ) ;
return V_66 ;
V_73:
F_31 ( V_74 L_1 , V_75 , V_6 . V_10 ) ;
goto V_67;
V_72:
F_31 ( V_74 L_1 , V_76 , V_6 . V_10 ) ;
goto V_67;
V_71:
F_31 ( V_74 L_1 , V_77 , V_6 . V_10 ) ;
goto V_67;
V_69:
F_31 ( V_74 L_1 , V_78 , V_6 . V_10 ) ;
V_67:
return NULL ;
}
static unsigned char F_32 ( struct V_3 * V_66 ,
T_1 V_6 , unsigned char V_30 )
{
unsigned long V_5 = F_30 ( V_6 ) ;
unsigned char V_79 ;
unsigned char V_80 ;
V_79 = V_66 -> V_52 [ V_5 ] ;
V_80 = V_79 & V_2 ;
V_79 &= ~ V_2 ;
if ( V_30 == V_2 ) {
F_33 ( ! V_80 ) ;
V_80 = 0 ;
} else if ( V_79 == V_81 ) {
V_79 = 0 ;
} else if ( ( V_79 & ~ V_82 ) <= V_83 ) {
if ( V_79 == V_82 ) {
if ( F_34 ( V_66 , V_5 , V_79 ) )
V_79 = V_83 | V_82 ;
else
V_79 = V_83 ;
} else
V_79 -- ;
}
if ( ! V_79 )
F_35 ( V_6 ) ;
V_30 = V_79 | V_80 ;
V_66 -> V_52 [ V_5 ] = V_30 ;
if ( ! V_30 ) {
struct V_84 * V_85 = V_66 -> V_19 -> V_86 ;
if ( V_5 < V_66 -> V_50 )
V_66 -> V_50 = V_5 ;
if ( V_5 > V_66 -> V_51 )
V_66 -> V_51 = V_5 ;
if ( V_62 . V_28 >= 0 &&
V_66 -> V_64 > V_63 [ V_62 . V_28 ] -> V_64 )
V_62 . V_28 = V_66 -> type ;
V_60 ++ ;
V_66 -> V_41 -- ;
if ( ( V_66 -> V_36 & V_87 ) &&
V_85 -> V_88 -> V_89 )
V_85 -> V_88 -> V_89 ( V_66 -> V_19 , V_5 ) ;
}
return V_30 ;
}
void F_36 ( T_1 V_6 )
{
struct V_3 * V_66 ;
V_66 = F_28 ( V_6 ) ;
if ( V_66 ) {
F_32 ( V_66 , V_6 , 1 ) ;
F_19 ( & V_48 ) ;
}
}
void F_37 ( T_1 V_6 , struct V_7 * V_7 )
{
struct V_3 * V_66 ;
unsigned char V_79 ;
V_66 = F_28 ( V_6 ) ;
if ( V_66 ) {
V_79 = F_32 ( V_66 , V_6 , V_2 ) ;
if ( V_7 )
F_38 ( V_7 , V_6 , V_79 != 0 ) ;
F_19 ( & V_48 ) ;
}
}
static inline int F_39 ( struct V_7 * V_7 )
{
int V_79 = 0 ;
struct V_3 * V_66 ;
T_1 V_6 ;
V_6 . V_10 = F_40 ( V_7 ) ;
V_66 = F_28 ( V_6 ) ;
if ( V_66 ) {
V_79 = F_1 ( V_66 -> V_52 [ F_30 ( V_6 ) ] ) ;
F_19 ( & V_48 ) ;
}
return V_79 ;
}
int F_41 ( struct V_7 * V_7 )
{
int V_79 ;
F_33 ( ! F_42 ( V_7 ) ) ;
if ( F_18 ( F_43 ( V_7 ) ) )
return 0 ;
V_79 = F_44 ( V_7 ) ;
if ( V_79 <= 1 && F_45 ( V_7 ) ) {
V_79 += F_39 ( V_7 ) ;
if ( V_79 == 1 && ! F_46 ( V_7 ) ) {
F_47 ( V_7 ) ;
F_48 ( V_7 ) ;
}
}
return V_79 <= 1 ;
}
int F_6 ( struct V_7 * V_7 )
{
F_33 ( ! F_42 ( V_7 ) ) ;
if ( ! F_45 ( V_7 ) )
return 0 ;
if ( F_46 ( V_7 ) )
return 0 ;
if ( F_39 ( V_7 ) )
return 0 ;
if ( ! ( V_90 & V_91 ) )
return 0 ;
F_47 ( V_7 ) ;
F_48 ( V_7 ) ;
return 1 ;
}
int F_49 ( T_1 V_6 )
{
struct V_3 * V_66 ;
struct V_7 * V_7 = NULL ;
if ( F_50 ( V_6 ) )
return 1 ;
V_66 = F_28 ( V_6 ) ;
if ( V_66 ) {
if ( F_32 ( V_66 , V_6 , 1 ) == V_2 ) {
V_7 = F_4 ( & V_9 , V_6 . V_10 ) ;
if ( V_7 && ! F_5 ( V_7 ) ) {
F_8 ( V_7 ) ;
V_7 = NULL ;
}
}
F_19 ( & V_48 ) ;
}
if ( V_7 ) {
if ( F_45 ( V_7 ) && ! F_46 ( V_7 ) &&
( ! F_51 ( V_7 ) || F_21 () ) ) {
F_47 ( V_7 ) ;
F_48 ( V_7 ) ;
}
F_7 ( V_7 ) ;
F_8 ( V_7 ) ;
}
return V_66 != NULL ;
}
int F_52 ( T_1 V_1 , struct V_7 * * V_92 )
{
struct V_7 * V_7 ;
struct V_3 * V_66 ;
int V_79 = 0 ;
V_7 = F_4 ( & V_9 , V_1 . V_10 ) ;
if ( V_7 )
V_79 += F_44 ( V_7 ) ;
V_66 = F_28 ( V_1 ) ;
if ( V_66 ) {
V_79 += F_1 ( V_66 -> V_52 [ F_30 ( V_1 ) ] ) ;
F_19 ( & V_48 ) ;
}
* V_92 = V_7 ;
return V_79 ;
}
int F_53 ( T_4 V_93 , T_2 V_5 , struct V_94 * * V_95 )
{
struct V_94 * V_19 = NULL ;
int type ;
if ( V_93 )
V_19 = F_54 ( V_93 ) ;
F_20 ( & V_48 ) ;
for ( type = 0 ; type < V_68 ; type ++ ) {
struct V_3 * V_96 = V_63 [ type ] ;
if ( ! ( V_96 -> V_36 & V_53 ) )
continue;
if ( ! V_19 ) {
if ( V_95 )
* V_95 = F_55 ( V_96 -> V_19 ) ;
F_19 ( & V_48 ) ;
return type ;
}
if ( V_19 == V_96 -> V_19 ) {
struct V_11 * V_12 = & V_96 -> V_16 ;
if ( V_12 -> V_13 == V_5 ) {
if ( V_95 )
* V_95 = F_55 ( V_96 -> V_19 ) ;
F_19 ( & V_48 ) ;
F_56 ( V_19 ) ;
return type ;
}
}
}
F_19 ( & V_48 ) ;
if ( V_19 )
F_56 ( V_19 ) ;
return - V_97 ;
}
T_2 F_57 ( int type , T_3 V_5 )
{
struct V_94 * V_19 ;
if ( ( unsigned int ) type >= V_68 )
return 0 ;
if ( ! ( V_63 [ type ] -> V_36 & V_53 ) )
return 0 ;
return F_58 ( F_3 ( type , V_5 ) , & V_19 ) ;
}
unsigned int F_59 ( int type , int free )
{
unsigned int V_98 = 0 ;
F_20 ( & V_48 ) ;
if ( ( unsigned int ) type < V_68 ) {
struct V_3 * V_96 = V_63 [ type ] ;
if ( V_96 -> V_36 & V_53 ) {
V_98 = V_96 -> V_40 ;
if ( free )
V_98 -= V_96 -> V_41 ;
}
}
F_19 ( & V_48 ) ;
return V_98 ;
}
static int F_60 ( struct V_99 * V_100 , T_5 * V_101 ,
unsigned long V_102 , T_1 V_6 , struct V_7 * V_7 )
{
struct V_103 * V_104 ;
T_6 * V_105 ;
T_7 * V_106 ;
int V_8 = 1 ;
if ( F_61 ( V_100 -> V_107 , V_7 , V_20 , & V_104 ) ) {
V_8 = - V_108 ;
goto V_109;
}
V_106 = F_62 ( V_100 -> V_107 , V_101 , V_102 , & V_105 ) ;
if ( F_18 ( ! F_63 ( * V_106 , F_64 ( V_6 ) ) ) ) {
if ( V_8 > 0 )
F_65 ( V_104 ) ;
V_8 = 0 ;
goto V_67;
}
F_66 ( V_100 -> V_107 , V_110 ) ;
F_67 ( V_100 -> V_107 , V_111 ) ;
F_68 ( V_7 ) ;
F_69 ( V_100 -> V_107 , V_102 , V_106 ,
F_70 ( F_71 ( V_7 , V_100 -> V_112 ) ) ) ;
F_72 ( V_7 , V_100 , V_102 ) ;
F_73 ( V_7 , V_104 ) ;
F_36 ( V_6 ) ;
F_74 ( V_7 ) ;
V_67:
F_75 ( V_106 , V_105 ) ;
V_109:
return V_8 ;
}
static int F_76 ( struct V_99 * V_100 , T_5 * V_101 ,
unsigned long V_102 , unsigned long V_113 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_7 V_114 = F_64 ( V_6 ) ;
T_7 * V_106 ;
int V_8 = 0 ;
V_106 = F_77 ( V_101 , V_102 ) ;
do {
if ( F_18 ( F_63 ( * V_106 , V_114 ) ) ) {
F_78 ( V_106 ) ;
V_8 = F_60 ( V_100 , V_101 , V_102 , V_6 , V_7 ) ;
if ( V_8 )
goto V_67;
V_106 = F_77 ( V_101 , V_102 ) ;
}
} while ( V_106 ++ , V_102 += V_115 , V_102 != V_113 );
F_78 ( V_106 - 1 ) ;
V_67:
return V_8 ;
}
static inline int F_79 ( struct V_99 * V_100 , T_8 * V_116 ,
unsigned long V_102 , unsigned long V_113 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_5 * V_101 ;
unsigned long V_28 ;
int V_8 ;
V_101 = F_80 ( V_116 , V_102 ) ;
do {
V_28 = F_81 ( V_102 , V_113 ) ;
if ( F_18 ( F_82 ( * V_101 ) ) )
continue;
if ( F_83 ( V_101 ) )
continue;
V_8 = F_76 ( V_100 , V_101 , V_102 , V_28 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_101 ++ , V_102 = V_28 , V_102 != V_113 );
return 0 ;
}
static inline int F_84 ( struct V_99 * V_100 , T_9 * V_117 ,
unsigned long V_102 , unsigned long V_113 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_8 * V_116 ;
unsigned long V_28 ;
int V_8 ;
V_116 = F_85 ( V_117 , V_102 ) ;
do {
V_28 = F_86 ( V_102 , V_113 ) ;
if ( F_87 ( V_116 ) )
continue;
V_8 = F_79 ( V_100 , V_116 , V_102 , V_28 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_116 ++ , V_102 = V_28 , V_102 != V_113 );
return 0 ;
}
static int F_88 ( struct V_99 * V_100 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_9 * V_117 ;
unsigned long V_102 , V_113 , V_28 ;
int V_8 ;
if ( F_89 ( V_7 ) ) {
V_102 = F_90 ( V_7 , V_100 ) ;
if ( V_102 == - V_118 )
return 0 ;
else
V_113 = V_102 + V_115 ;
} else {
V_102 = V_100 -> V_119 ;
V_113 = V_100 -> V_120 ;
}
V_117 = F_91 ( V_100 -> V_107 , V_102 ) ;
do {
V_28 = F_92 ( V_102 , V_113 ) ;
if ( F_93 ( V_117 ) )
continue;
V_8 = F_84 ( V_100 , V_117 , V_102 , V_28 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_117 ++ , V_102 = V_28 , V_102 != V_113 );
return 0 ;
}
static int F_94 ( struct V_121 * V_122 ,
T_1 V_6 , struct V_7 * V_7 )
{
struct V_99 * V_100 ;
int V_8 = 0 ;
if ( ! F_95 ( & V_122 -> V_123 ) ) {
F_74 ( V_7 ) ;
F_7 ( V_7 ) ;
F_96 ( & V_122 -> V_123 ) ;
F_97 ( V_7 ) ;
}
for ( V_100 = V_122 -> V_124 ; V_100 ; V_100 = V_100 -> V_125 ) {
if ( V_100 -> V_126 && ( V_8 = F_88 ( V_100 , V_6 , V_7 ) ) )
break;
}
F_98 ( & V_122 -> V_123 ) ;
return ( V_8 < 0 ) ? V_8 : 0 ;
}
static unsigned int F_99 ( struct V_3 * V_4 ,
unsigned int V_127 )
{
unsigned int V_46 = V_4 -> V_46 ;
unsigned int V_128 = V_127 ;
unsigned char V_79 ;
for (; ; ) {
if ( ++ V_128 >= V_46 ) {
if ( ! V_127 ) {
V_128 = 0 ;
break;
}
V_46 = V_127 + 1 ;
V_127 = 0 ;
V_128 = 1 ;
}
V_79 = V_4 -> V_52 [ V_128 ] ;
if ( V_79 && F_1 ( V_79 ) != V_129 )
break;
}
return V_128 ;
}
static int F_100 ( unsigned int type )
{
struct V_3 * V_4 = V_63 [ type ] ;
struct V_121 * V_130 ;
unsigned char * V_52 ;
unsigned char V_131 ;
struct V_7 * V_7 ;
T_1 V_6 ;
unsigned int V_128 = 0 ;
int V_132 = 0 ;
V_130 = & V_133 ;
F_101 ( & V_133 . V_134 ) ;
while ( ( V_128 = F_99 ( V_4 , V_128 ) ) != 0 ) {
if ( F_102 ( V_135 ) ) {
V_132 = - V_136 ;
break;
}
V_52 = & V_4 -> V_52 [ V_128 ] ;
V_6 = F_3 ( type , V_128 ) ;
V_7 = F_103 ( V_6 ,
V_137 , NULL , 0 ) ;
if ( ! V_7 ) {
if ( ! * V_52 )
continue;
V_132 = - V_108 ;
break;
}
if ( F_104 ( & V_130 -> V_134 ) == 1 ) {
F_105 ( V_130 ) ;
V_130 = & V_133 ;
F_101 ( & V_133 . V_134 ) ;
}
F_106 ( V_7 ) ;
F_107 ( V_7 ) ;
F_97 ( V_7 ) ;
F_107 ( V_7 ) ;
V_131 = * V_52 ;
if ( F_1 ( V_131 ) == V_81 ) {
V_132 = F_108 ( V_6 , V_7 ) ;
if ( V_132 < 0 )
break;
continue;
}
if ( F_1 ( V_131 ) && V_130 != & V_133 )
V_132 = F_94 ( V_130 , V_6 , V_7 ) ;
if ( F_1 ( * V_52 ) ) {
int V_138 = ( * V_52 >= V_131 ) ;
struct V_24 * V_66 = & V_130 -> V_139 ;
struct V_121 * V_140 = V_130 ;
struct V_121 * V_141 = V_130 ;
struct V_121 * V_122 ;
F_101 ( & V_140 -> V_134 ) ;
F_101 ( & V_141 -> V_134 ) ;
F_20 ( & V_142 ) ;
while ( F_1 ( * V_52 ) && ! V_132 &&
( V_66 = V_66 -> V_28 ) != & V_130 -> V_139 ) {
V_122 = F_14 ( V_66 , struct V_121 , V_139 ) ;
if ( ! F_109 ( & V_122 -> V_134 ) )
continue;
F_19 ( & V_142 ) ;
F_105 ( V_141 ) ;
V_141 = V_122 ;
F_11 () ;
V_131 = * V_52 ;
if ( ! F_1 ( V_131 ) )
;
else if ( V_122 == & V_133 )
V_138 = 1 ;
else
V_132 = F_94 ( V_122 , V_6 , V_7 ) ;
if ( V_138 && * V_52 < V_131 ) {
F_105 ( V_140 ) ;
F_101 ( & V_122 -> V_134 ) ;
V_140 = V_122 ;
V_138 = 0 ;
}
F_20 ( & V_142 ) ;
}
F_19 ( & V_142 ) ;
F_105 ( V_141 ) ;
F_105 ( V_130 ) ;
V_130 = V_140 ;
}
if ( V_132 ) {
F_7 ( V_7 ) ;
F_8 ( V_7 ) ;
break;
}
if ( F_1 ( * V_52 ) &&
F_110 ( V_7 ) && F_45 ( V_7 ) ) {
struct V_143 V_144 = {
. V_145 = V_146 ,
} ;
F_111 ( V_7 , & V_144 ) ;
F_97 ( V_7 ) ;
F_107 ( V_7 ) ;
}
if ( F_45 ( V_7 ) &&
F_112 ( F_40 ( V_7 ) == V_6 . V_10 ) )
F_47 ( V_7 ) ;
F_48 ( V_7 ) ;
F_7 ( V_7 ) ;
F_8 ( V_7 ) ;
F_11 () ;
}
F_105 ( V_130 ) ;
return V_132 ;
}
static void F_113 ( void )
{
struct V_24 * V_66 , * V_28 ;
unsigned int type ;
for ( type = 0 ; type < V_68 ; type ++ )
if ( V_63 [ type ] -> V_41 )
return;
F_20 ( & V_142 ) ;
F_114 (p, next, &init_mm.mmlist)
F_115 ( V_66 ) ;
F_19 ( & V_142 ) ;
}
static T_2 F_58 ( T_1 V_6 , struct V_94 * * V_19 )
{
struct V_3 * V_96 ;
struct V_11 * V_147 ;
struct V_11 * V_12 ;
T_3 V_5 ;
V_96 = V_63 [ F_29 ( V_6 ) ] ;
* V_19 = V_96 -> V_19 ;
V_5 = F_30 ( V_6 ) ;
V_147 = V_96 -> V_22 ;
V_12 = V_147 ;
for ( ; ; ) {
struct V_24 * V_25 ;
if ( V_12 -> V_21 <= V_5 &&
V_5 < ( V_12 -> V_21 + V_12 -> V_18 ) ) {
return V_12 -> V_13 + ( V_5 - V_12 -> V_21 ) ;
}
V_25 = V_12 -> V_27 . V_28 ;
V_12 = F_14 ( V_25 , struct V_11 , V_27 ) ;
V_96 -> V_22 = V_12 ;
F_116 ( V_12 == V_147 ) ;
}
}
T_2 F_117 ( struct V_7 * V_7 , struct V_94 * * V_19 )
{
T_1 V_6 ;
V_6 . V_10 = F_40 ( V_7 ) ;
return F_58 ( V_6 , V_19 ) ;
}
static void F_118 ( struct V_3 * V_96 )
{
while ( ! F_119 ( & V_96 -> V_16 . V_27 ) ) {
struct V_11 * V_12 ;
V_12 = F_14 ( V_96 -> V_16 . V_27 . V_28 ,
struct V_11 , V_27 ) ;
F_120 ( & V_12 -> V_27 ) ;
F_121 ( V_12 ) ;
}
}
static int
F_122 ( struct V_3 * V_96 , unsigned long V_21 ,
unsigned long V_18 , T_2 V_13 )
{
struct V_11 * V_12 ;
struct V_11 * V_148 ;
struct V_24 * V_25 ;
if ( V_21 == 0 ) {
V_12 = & V_96 -> V_16 ;
V_96 -> V_22 = V_12 ;
V_12 -> V_21 = 0 ;
V_12 -> V_18 = V_18 ;
V_12 -> V_13 = V_13 ;
return 1 ;
} else {
V_25 = V_96 -> V_16 . V_27 . V_127 ;
V_12 = F_14 ( V_25 , struct V_11 , V_27 ) ;
F_116 ( V_12 -> V_21 + V_12 -> V_18 != V_21 ) ;
if ( V_12 -> V_13 + V_12 -> V_18 == V_13 ) {
V_12 -> V_18 += V_18 ;
return 0 ;
}
}
V_148 = F_123 ( sizeof( * V_12 ) , V_20 ) ;
if ( V_148 == NULL )
return - V_108 ;
V_148 -> V_21 = V_21 ;
V_148 -> V_18 = V_18 ;
V_148 -> V_13 = V_13 ;
F_124 ( & V_148 -> V_27 , & V_96 -> V_16 . V_27 ) ;
return 1 ;
}
static int F_125 ( struct V_3 * V_96 , T_2 * V_149 )
{
struct V_150 * V_150 ;
unsigned V_151 ;
unsigned long V_152 ;
unsigned V_153 ;
T_2 V_154 ;
T_2 V_155 ;
T_2 V_156 = - 1 ;
T_2 V_157 = 0 ;
int V_158 = 0 ;
int V_8 ;
V_150 = V_96 -> V_159 -> V_160 -> V_161 ;
if ( F_126 ( V_150 -> V_162 ) ) {
V_8 = F_122 ( V_96 , 0 , V_96 -> V_46 , 0 ) ;
* V_149 = V_96 -> V_40 ;
goto V_67;
}
V_153 = V_150 -> V_163 ;
V_151 = V_115 >> V_153 ;
V_154 = 0 ;
V_152 = 0 ;
V_155 = F_127 ( V_150 ) >> V_153 ;
while ( ( V_154 + V_151 ) <= V_155 &&
V_152 < V_96 -> V_46 ) {
unsigned V_164 ;
T_2 V_165 ;
V_165 = F_128 ( V_150 , V_154 ) ;
if ( V_165 == 0 )
goto V_166;
if ( V_165 & ( V_151 - 1 ) ) {
V_154 ++ ;
goto V_167;
}
for ( V_164 = 1 ; V_164 < V_151 ;
V_164 ++ ) {
T_2 V_168 ;
V_168 = F_128 ( V_150 , V_154 + V_164 ) ;
if ( V_168 == 0 )
goto V_166;
if ( V_168 != V_165 + V_164 ) {
V_154 ++ ;
goto V_167;
}
}
V_165 >>= ( V_17 - V_153 ) ;
if ( V_152 ) {
if ( V_165 < V_156 )
V_156 = V_165 ;
if ( V_165 > V_157 )
V_157 = V_165 ;
}
V_8 = F_122 ( V_96 , V_152 , 1 , V_165 ) ;
if ( V_8 < 0 )
goto V_67;
V_158 += V_8 ;
V_152 ++ ;
V_154 += V_151 ;
V_167:
continue;
}
V_8 = V_158 ;
* V_149 = 1 + V_157 - V_156 ;
if ( V_152 == 0 )
V_152 = 1 ;
V_96 -> V_46 = V_152 ;
V_96 -> V_40 = V_152 - 1 ;
V_96 -> V_51 = V_152 - 1 ;
V_67:
return V_8 ;
V_166:
F_31 ( V_74 L_2 ) ;
V_8 = - V_169 ;
goto V_67;
}
static void F_129 ( struct V_3 * V_66 , int V_64 ,
unsigned char * V_52 )
{
int V_128 , V_127 ;
F_20 ( & V_48 ) ;
if ( V_64 >= 0 )
V_66 -> V_64 = V_64 ;
else
V_66 -> V_64 = -- V_170 ;
V_66 -> V_52 = V_52 ;
V_66 -> V_36 |= V_53 ;
V_60 += V_66 -> V_40 ;
V_171 += V_66 -> V_40 ;
V_127 = - 1 ;
for ( V_128 = V_62 . V_65 ; V_128 >= 0 ; V_128 = V_63 [ V_128 ] -> V_28 ) {
if ( V_66 -> V_64 >= V_63 [ V_128 ] -> V_64 )
break;
V_127 = V_128 ;
}
V_66 -> V_28 = V_128 ;
if ( V_127 < 0 )
V_62 . V_65 = V_62 . V_28 = V_66 -> type ;
else
V_63 [ V_127 ] -> V_28 = V_66 -> type ;
F_19 ( & V_48 ) ;
}
static unsigned F_130 ( struct V_172 * V_172 , T_10 * V_173 )
{
struct V_174 * V_175 = V_172 -> V_176 ;
F_131 ( V_172 , & V_177 , V_173 ) ;
if ( V_175 -> V_178 != F_104 ( & V_179 ) ) {
V_175 -> V_178 = F_104 ( & V_179 ) ;
return V_180 | V_181 | V_182 | V_183 ;
}
return V_180 | V_181 ;
}
static void * F_132 ( struct V_174 * V_184 , T_11 * V_185 )
{
struct V_3 * V_4 ;
int type ;
T_11 V_186 = * V_185 ;
F_133 ( & V_187 ) ;
if ( ! V_186 )
return V_188 ;
for ( type = 0 ; type < V_68 ; type ++ ) {
F_134 () ;
V_4 = V_63 [ type ] ;
if ( ! ( V_4 -> V_36 & V_70 ) || ! V_4 -> V_52 )
continue;
if ( ! -- V_186 )
return V_4 ;
}
return NULL ;
}
static void * F_135 ( struct V_174 * V_184 , void * V_189 , T_11 * V_185 )
{
struct V_3 * V_4 = V_189 ;
int type ;
if ( V_189 == V_188 )
type = 0 ;
else
type = V_4 -> type + 1 ;
for (; type < V_68 ; type ++ ) {
F_134 () ;
V_4 = V_63 [ type ] ;
if ( ! ( V_4 -> V_36 & V_70 ) || ! V_4 -> V_52 )
continue;
++ * V_185 ;
return V_4 ;
}
return NULL ;
}
static void F_136 ( struct V_174 * V_184 , void * V_189 )
{
F_137 ( & V_187 ) ;
}
static int F_138 ( struct V_174 * V_184 , void * V_189 )
{
struct V_3 * V_4 = V_189 ;
struct V_172 * V_172 ;
int V_190 ;
if ( V_4 == V_188 ) {
F_139 ( V_184 , L_3 ) ;
return 0 ;
}
V_172 = V_4 -> V_159 ;
V_190 = F_140 ( V_184 , & V_172 -> V_191 , L_4 ) ;
F_141 ( V_184 , L_5 ,
V_190 < 40 ? 40 - V_190 : 1 , L_6 ,
F_126 ( V_172 -> V_191 . V_192 -> V_193 -> V_162 ) ?
L_7 : L_8 ,
V_4 -> V_40 << ( V_17 - 10 ) ,
V_4 -> V_41 << ( V_17 - 10 ) ,
V_4 -> V_64 ) ;
return 0 ;
}
static int F_142 ( struct V_150 * V_150 , struct V_172 * V_172 )
{
struct V_174 * V_175 ;
int V_8 ;
V_8 = F_143 ( V_172 , & V_194 ) ;
if ( V_8 )
return V_8 ;
V_175 = V_172 -> V_176 ;
V_175 -> V_178 = F_104 ( & V_179 ) ;
return 0 ;
}
static int T_12 F_144 ( void )
{
F_145 ( L_9 , 0 , NULL , & V_195 ) ;
return 0 ;
}
static int T_12 F_146 ( void )
{
F_147 () ;
return 0 ;
}
static struct V_3 * F_148 ( void )
{
struct V_3 * V_66 ;
unsigned int type ;
V_66 = F_149 ( sizeof( * V_66 ) , V_20 ) ;
if ( ! V_66 )
return F_150 ( - V_108 ) ;
F_20 ( & V_48 ) ;
for ( type = 0 ; type < V_68 ; type ++ ) {
if ( ! ( V_63 [ type ] -> V_36 & V_70 ) )
break;
}
if ( type >= V_196 ) {
F_19 ( & V_48 ) ;
F_121 ( V_66 ) ;
return F_150 ( - V_197 ) ;
}
if ( type >= V_68 ) {
V_66 -> type = type ;
V_63 [ type ] = V_66 ;
F_151 () ;
V_68 ++ ;
} else {
F_121 ( V_66 ) ;
V_66 = V_63 [ type ] ;
}
F_152 ( & V_66 -> V_16 . V_27 ) ;
V_66 -> V_36 = V_70 ;
V_66 -> V_28 = - 1 ;
F_19 ( & V_48 ) ;
return V_66 ;
}
static int F_153 ( struct V_3 * V_66 , struct V_150 * V_150 )
{
int error ;
if ( F_126 ( V_150 -> V_162 ) ) {
V_66 -> V_19 = F_55 ( F_154 ( V_150 ) ) ;
error = F_155 ( V_66 -> V_19 ,
V_198 | V_199 | V_200 ,
V_201 ) ;
if ( error < 0 ) {
V_66 -> V_19 = NULL ;
return - V_169 ;
}
V_66 -> V_202 = F_156 ( V_66 -> V_19 ) ;
error = F_157 ( V_66 -> V_19 , V_115 ) ;
if ( error < 0 )
return error ;
V_66 -> V_36 |= V_87 ;
} else if ( F_158 ( V_150 -> V_162 ) ) {
V_66 -> V_19 = V_150 -> V_203 -> V_204 ;
F_133 ( & V_150 -> V_205 ) ;
if ( F_159 ( V_150 ) )
return - V_206 ;
} else
return - V_169 ;
return 0 ;
}
static unsigned long F_160 ( struct V_3 * V_66 ,
union V_207 * V_207 ,
struct V_150 * V_150 )
{
int V_128 ;
unsigned long V_208 ;
unsigned long V_209 ;
if ( memcmp ( L_10 , V_207 -> V_210 . V_210 , 10 ) ) {
F_31 ( V_74 L_11 ) ;
return 0 ;
}
if ( F_161 ( V_207 -> V_211 . V_212 ) == 1 ) {
F_162 ( & V_207 -> V_211 . V_212 ) ;
F_162 ( & V_207 -> V_211 . V_213 ) ;
F_162 ( & V_207 -> V_211 . V_214 ) ;
for ( V_128 = 0 ; V_128 < V_207 -> V_211 . V_214 ; V_128 ++ )
F_162 ( & V_207 -> V_211 . V_215 [ V_128 ] ) ;
}
if ( V_207 -> V_211 . V_212 != 1 ) {
F_31 ( V_216
L_12 ,
V_207 -> V_211 . V_212 ) ;
return 0 ;
}
V_66 -> V_50 = 1 ;
V_66 -> V_38 = 1 ;
V_66 -> V_39 = 0 ;
V_208 = F_30 ( F_163 (
F_64 ( F_3 ( 0 , ~ 0UL ) ) ) ) ;
V_208 = F_30 ( F_164 (
F_165 ( F_3 ( 0 , V_208 ) ) ) ) + 1 ;
if ( V_208 > V_207 -> V_211 . V_213 ) {
V_208 = V_207 -> V_211 . V_213 + 1 ;
if ( ( unsigned int ) V_208 == 0 )
V_208 = V_217 ;
}
V_66 -> V_51 = V_208 - 1 ;
if ( ! V_208 )
return 0 ;
V_209 = F_127 ( V_150 ) >> V_17 ;
if ( V_209 && V_208 > V_209 ) {
F_31 ( V_216
L_13 ) ;
return 0 ;
}
if ( V_207 -> V_211 . V_214 && F_158 ( V_150 -> V_162 ) )
return 0 ;
if ( V_207 -> V_211 . V_214 > V_218 )
return 0 ;
return V_208 ;
}
static int F_166 ( struct V_3 * V_66 ,
union V_207 * V_207 ,
unsigned char * V_52 ,
unsigned long V_208 ,
T_2 * V_149 )
{
int V_128 ;
unsigned int V_219 ;
int V_158 ;
V_219 = V_208 - 1 ;
for ( V_128 = 0 ; V_128 < V_207 -> V_211 . V_214 ; V_128 ++ ) {
unsigned int V_220 = V_207 -> V_211 . V_215 [ V_128 ] ;
if ( V_220 == 0 || V_220 > V_207 -> V_211 . V_213 )
return - V_169 ;
if ( V_220 < V_208 ) {
V_52 [ V_220 ] = V_129 ;
V_219 -- ;
}
}
if ( V_219 ) {
V_52 [ 0 ] = V_129 ;
V_66 -> V_46 = V_208 ;
V_66 -> V_40 = V_219 ;
V_158 = F_125 ( V_66 , V_149 ) ;
if ( V_158 < 0 )
return V_158 ;
V_219 = V_66 -> V_40 ;
}
if ( ! V_219 ) {
F_31 ( V_216 L_14 ) ;
return - V_169 ;
}
return V_158 ;
}
void F_167 ( struct V_221 * V_10 )
{
unsigned int type ;
unsigned long V_222 = 0 ;
F_20 ( & V_48 ) ;
for ( type = 0 ; type < V_68 ; type ++ ) {
struct V_3 * V_4 = V_63 [ type ] ;
if ( ( V_4 -> V_36 & V_70 ) && ! ( V_4 -> V_36 & V_53 ) )
V_222 += V_4 -> V_41 ;
}
V_10 -> V_223 = V_60 + V_222 ;
V_10 -> V_224 = V_171 + V_222 ;
F_19 ( & V_48 ) ;
}
static int F_168 ( T_1 V_6 , unsigned char V_30 )
{
struct V_3 * V_66 ;
unsigned long V_5 , type ;
unsigned char V_79 ;
unsigned char V_80 ;
int V_15 = - V_169 ;
if ( F_50 ( V_6 ) )
goto V_67;
type = F_29 ( V_6 ) ;
if ( type >= V_68 )
goto V_225;
V_66 = V_63 [ type ] ;
V_5 = F_30 ( V_6 ) ;
F_20 ( & V_48 ) ;
if ( F_18 ( V_5 >= V_66 -> V_46 ) )
goto V_226;
V_79 = V_66 -> V_52 [ V_5 ] ;
V_80 = V_79 & V_2 ;
V_79 &= ~ V_2 ;
V_15 = 0 ;
if ( V_30 == V_2 ) {
if ( ! V_80 && V_79 )
V_80 = V_2 ;
else if ( V_80 )
V_15 = - V_227 ;
else
V_15 = - V_228 ;
} else if ( V_79 || V_80 ) {
if ( ( V_79 & ~ V_82 ) < V_83 )
V_79 += V_30 ;
else if ( ( V_79 & ~ V_82 ) > V_83 )
V_15 = - V_169 ;
else if ( F_34 ( V_66 , V_5 , V_79 ) )
V_79 = V_82 ;
else
V_15 = - V_108 ;
} else
V_15 = - V_228 ;
V_66 -> V_52 [ V_5 ] = V_79 | V_80 ;
V_226:
F_19 ( & V_48 ) ;
V_67:
return V_15 ;
V_225:
F_31 ( V_74 L_15 , V_78 , V_6 . V_10 ) ;
goto V_67;
}
void F_169 ( T_1 V_6 )
{
F_168 ( V_6 , V_81 ) ;
}
int F_170 ( T_1 V_6 )
{
int V_15 = 0 ;
while ( ! V_15 && F_168 ( V_6 , 1 ) == - V_108 )
V_15 = F_171 ( V_6 , V_229 ) ;
return V_15 ;
}
int F_172 ( T_1 V_6 )
{
return F_168 ( V_6 , V_2 ) ;
}
int F_173 ( T_1 V_6 , unsigned long * V_5 )
{
struct V_3 * V_4 ;
int V_230 = V_231 ;
T_3 V_232 , V_233 ;
T_3 V_234 , V_113 ;
int V_18 = 0 ;
if ( ! V_230 )
return 0 ;
V_4 = V_63 [ F_29 ( V_6 ) ] ;
V_232 = F_30 ( V_6 ) ;
V_234 = ( V_232 >> V_230 ) << V_230 ;
V_113 = V_234 + ( 1 << V_230 ) ;
if ( ! V_234 )
V_234 ++ ;
F_20 ( & V_48 ) ;
if ( V_113 > V_4 -> V_46 )
V_113 = V_4 -> V_46 ;
for ( V_233 = V_232 ; ++ V_233 < V_113 ; V_18 ++ ) {
if ( ! V_4 -> V_52 [ V_233 ] )
break;
if ( F_1 ( V_4 -> V_52 [ V_233 ] ) == V_129 )
break;
}
for ( V_233 = V_232 ; -- V_233 >= V_234 ; V_18 ++ ) {
if ( ! V_4 -> V_52 [ V_233 ] )
break;
if ( F_1 ( V_4 -> V_52 [ V_233 ] ) == V_129 )
break;
}
F_19 ( & V_48 ) ;
* V_5 = ++ V_233 ;
return V_18 ? ++ V_18 : 0 ;
}
int F_171 ( T_1 V_6 , T_13 V_235 )
{
struct V_3 * V_4 ;
struct V_7 * V_65 ;
struct V_7 * V_7 ;
struct V_7 * V_236 ;
T_3 V_5 ;
unsigned char V_79 ;
V_7 = F_174 ( V_235 | V_237 ) ;
V_4 = F_28 ( V_6 ) ;
if ( ! V_4 ) {
goto V_238;
}
V_5 = F_30 ( V_6 ) ;
V_79 = V_4 -> V_52 [ V_5 ] & ~ V_2 ;
if ( ( V_79 & ~ V_82 ) != V_83 ) {
goto V_67;
}
if ( ! V_7 ) {
F_19 ( & V_48 ) ;
return - V_108 ;
}
V_65 = F_175 ( V_4 -> V_52 + V_5 ) ;
V_5 &= ~ V_239 ;
if ( ! F_40 ( V_65 ) ) {
F_116 ( V_79 & V_82 ) ;
F_152 ( & V_65 -> V_240 ) ;
F_176 ( V_65 , V_241 ) ;
V_4 -> V_36 |= V_241 ;
}
F_12 (list_page, &head->lru, lru) {
unsigned char * V_242 ;
if ( ! ( V_79 & V_82 ) )
goto V_67;
V_242 = F_177 ( V_236 , V_243 ) + V_5 ;
V_79 = * V_242 ;
F_178 ( V_242 , V_243 ) ;
if ( ( V_79 & ~ V_82 ) != V_244 )
goto V_67;
}
F_124 ( & V_7 -> V_240 , & V_65 -> V_240 ) ;
V_7 = NULL ;
V_67:
F_19 ( & V_48 ) ;
V_238:
if ( V_7 )
F_179 ( V_7 ) ;
return 0 ;
}
static bool F_34 ( struct V_3 * V_4 ,
T_3 V_5 , unsigned char V_79 )
{
struct V_7 * V_65 ;
struct V_7 * V_7 ;
unsigned char * V_242 ;
V_65 = F_175 ( V_4 -> V_52 + V_5 ) ;
if ( F_40 ( V_65 ) != V_241 ) {
F_116 ( V_79 & V_82 ) ;
return false ;
}
V_5 &= ~ V_239 ;
V_7 = F_14 ( V_65 -> V_240 . V_28 , struct V_7 , V_240 ) ;
V_242 = F_177 ( V_7 , V_243 ) + V_5 ;
if ( V_79 == V_83 )
goto V_245;
if ( V_79 == ( V_83 | V_82 ) ) {
while ( * V_242 == ( V_244 | V_82 ) ) {
F_178 ( V_242 , V_243 ) ;
V_7 = F_14 ( V_7 -> V_240 . V_28 , struct V_7 , V_240 ) ;
F_116 ( V_7 == V_65 ) ;
V_242 = F_177 ( V_7 , V_243 ) + V_5 ;
}
if ( * V_242 == V_244 ) {
F_178 ( V_242 , V_243 ) ;
V_7 = F_14 ( V_7 -> V_240 . V_28 , struct V_7 , V_240 ) ;
if ( V_7 == V_65 )
return false ;
V_242 = F_177 ( V_7 , V_243 ) + V_5 ;
V_245: * V_242 = 0 ;
}
* V_242 += 1 ;
F_178 ( V_242 , V_243 ) ;
V_7 = F_14 ( V_7 -> V_240 . V_127 , struct V_7 , V_240 ) ;
while ( V_7 != V_65 ) {
V_242 = F_177 ( V_7 , V_243 ) + V_5 ;
* V_242 = V_82 ;
F_178 ( V_242 , V_243 ) ;
V_7 = F_14 ( V_7 -> V_240 . V_127 , struct V_7 , V_240 ) ;
}
return true ;
} else {
F_116 ( V_79 != V_82 ) ;
while ( * V_242 == V_82 ) {
F_178 ( V_242 , V_243 ) ;
V_7 = F_14 ( V_7 -> V_240 . V_28 , struct V_7 , V_240 ) ;
F_116 ( V_7 == V_65 ) ;
V_242 = F_177 ( V_7 , V_243 ) + V_5 ;
}
F_116 ( * V_242 == 0 ) ;
* V_242 -= 1 ;
if ( * V_242 == 0 )
V_79 = 0 ;
F_178 ( V_242 , V_243 ) ;
V_7 = F_14 ( V_7 -> V_240 . V_127 , struct V_7 , V_240 ) ;
while ( V_7 != V_65 ) {
V_242 = F_177 ( V_7 , V_243 ) + V_5 ;
* V_242 = V_244 | V_79 ;
V_79 = V_82 ;
F_178 ( V_242 , V_243 ) ;
V_7 = F_14 ( V_7 -> V_240 . V_127 , struct V_7 , V_240 ) ;
}
return V_79 == V_82 ;
}
}
static void F_180 ( struct V_3 * V_4 )
{
T_3 V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_46 ; V_5 += V_115 ) {
struct V_7 * V_65 ;
V_65 = F_175 ( V_4 -> V_52 + V_5 ) ;
if ( F_40 ( V_65 ) ) {
struct V_24 * V_246 , * V_28 ;
F_114 (this, next, &head->lru) {
struct V_7 * V_7 ;
V_7 = F_14 ( V_246 , struct V_7 , V_240 ) ;
F_120 ( V_246 ) ;
F_179 ( V_7 ) ;
}
}
}
}
