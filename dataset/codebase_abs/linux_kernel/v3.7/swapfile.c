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
if ( V_5 < V_66 -> V_50 )
V_66 -> V_50 = V_5 ;
if ( V_5 > V_66 -> V_51 )
V_66 -> V_51 = V_5 ;
if ( V_62 . V_28 >= 0 &&
V_66 -> V_64 > V_63 [ V_62 . V_28 ] -> V_64 )
V_62 . V_28 = V_66 -> type ;
V_60 ++ ;
V_66 -> V_41 -- ;
F_36 ( V_66 -> type , V_5 ) ;
if ( V_66 -> V_36 & V_84 ) {
struct V_85 * V_86 = V_66 -> V_19 -> V_87 ;
if ( V_86 -> V_88 -> V_89 )
V_86 -> V_88 -> V_89 ( V_66 -> V_19 ,
V_5 ) ;
}
}
return V_30 ;
}
void F_37 ( T_1 V_6 )
{
struct V_3 * V_66 ;
V_66 = F_28 ( V_6 ) ;
if ( V_66 ) {
F_32 ( V_66 , V_6 , 1 ) ;
F_19 ( & V_48 ) ;
}
}
void F_38 ( T_1 V_6 , struct V_7 * V_7 )
{
struct V_3 * V_66 ;
unsigned char V_79 ;
V_66 = F_28 ( V_6 ) ;
if ( V_66 ) {
V_79 = F_32 ( V_66 , V_6 , V_2 ) ;
if ( V_7 )
F_39 ( V_7 , V_6 , V_79 != 0 ) ;
F_19 ( & V_48 ) ;
}
}
int F_40 ( struct V_7 * V_7 )
{
int V_79 = 0 ;
struct V_3 * V_66 ;
T_1 V_6 ;
V_6 . V_10 = F_41 ( V_7 ) ;
V_66 = F_28 ( V_6 ) ;
if ( V_66 ) {
V_79 = F_1 ( V_66 -> V_52 [ F_30 ( V_6 ) ] ) ;
F_19 ( & V_48 ) ;
}
return V_79 ;
}
int F_42 ( struct V_7 * V_7 )
{
int V_79 ;
F_33 ( ! F_43 ( V_7 ) ) ;
if ( F_18 ( F_44 ( V_7 ) ) )
return 0 ;
V_79 = F_45 ( V_7 ) ;
if ( V_79 <= 1 && F_46 ( V_7 ) ) {
V_79 += F_40 ( V_7 ) ;
if ( V_79 == 1 && ! F_47 ( V_7 ) ) {
F_48 ( V_7 ) ;
F_49 ( V_7 ) ;
}
}
return V_79 <= 1 ;
}
int F_6 ( struct V_7 * V_7 )
{
F_33 ( ! F_43 ( V_7 ) ) ;
if ( ! F_46 ( V_7 ) )
return 0 ;
if ( F_47 ( V_7 ) )
return 0 ;
if ( F_40 ( V_7 ) )
return 0 ;
if ( F_50 () )
return 0 ;
F_48 ( V_7 ) ;
F_49 ( V_7 ) ;
return 1 ;
}
int F_51 ( T_1 V_6 )
{
struct V_3 * V_66 ;
struct V_7 * V_7 = NULL ;
if ( F_52 ( V_6 ) )
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
if ( F_46 ( V_7 ) && ! F_47 ( V_7 ) &&
( ! F_53 ( V_7 ) || F_21 () ) ) {
F_48 ( V_7 ) ;
F_49 ( V_7 ) ;
}
F_7 ( V_7 ) ;
F_8 ( V_7 ) ;
}
return V_66 != NULL ;
}
int F_54 ( T_4 V_90 , T_2 V_5 , struct V_91 * * V_92 )
{
struct V_91 * V_19 = NULL ;
int type ;
if ( V_90 )
V_19 = F_55 ( V_90 ) ;
F_20 ( & V_48 ) ;
for ( type = 0 ; type < V_68 ; type ++ ) {
struct V_3 * V_93 = V_63 [ type ] ;
if ( ! ( V_93 -> V_36 & V_53 ) )
continue;
if ( ! V_19 ) {
if ( V_92 )
* V_92 = F_56 ( V_93 -> V_19 ) ;
F_19 ( & V_48 ) ;
return type ;
}
if ( V_19 == V_93 -> V_19 ) {
struct V_11 * V_12 = & V_93 -> V_16 ;
if ( V_12 -> V_13 == V_5 ) {
if ( V_92 )
* V_92 = F_56 ( V_93 -> V_19 ) ;
F_19 ( & V_48 ) ;
F_57 ( V_19 ) ;
return type ;
}
}
}
F_19 ( & V_48 ) ;
if ( V_19 )
F_57 ( V_19 ) ;
return - V_94 ;
}
T_2 F_58 ( int type , T_3 V_5 )
{
struct V_91 * V_19 ;
if ( ( unsigned int ) type >= V_68 )
return 0 ;
if ( ! ( V_63 [ type ] -> V_36 & V_53 ) )
return 0 ;
return F_59 ( F_3 ( type , V_5 ) , & V_19 ) ;
}
unsigned int F_60 ( int type , int free )
{
unsigned int V_95 = 0 ;
F_20 ( & V_48 ) ;
if ( ( unsigned int ) type < V_68 ) {
struct V_3 * V_93 = V_63 [ type ] ;
if ( V_93 -> V_36 & V_53 ) {
V_95 = V_93 -> V_40 ;
if ( free )
V_95 -= V_93 -> V_41 ;
}
}
F_19 ( & V_48 ) ;
return V_95 ;
}
static int F_61 ( struct V_96 * V_97 , T_5 * V_98 ,
unsigned long V_99 , T_1 V_6 , struct V_7 * V_7 )
{
struct V_100 * V_101 ;
T_6 * V_102 ;
T_7 * V_103 ;
int V_8 = 1 ;
if ( F_62 ( V_97 -> V_104 , V_7 ,
V_20 , & V_101 ) ) {
V_8 = - V_105 ;
goto V_106;
}
V_103 = F_63 ( V_97 -> V_104 , V_98 , V_99 , & V_102 ) ;
if ( F_18 ( ! F_64 ( * V_103 , F_65 ( V_6 ) ) ) ) {
F_66 ( V_101 ) ;
V_8 = 0 ;
goto V_67;
}
F_67 ( V_97 -> V_104 , V_107 ) ;
F_68 ( V_97 -> V_104 , V_108 ) ;
F_69 ( V_7 ) ;
F_70 ( V_97 -> V_104 , V_99 , V_103 ,
F_71 ( F_72 ( V_7 , V_97 -> V_109 ) ) ) ;
F_73 ( V_7 , V_97 , V_99 ) ;
F_74 ( V_7 , V_101 ) ;
F_37 ( V_6 ) ;
F_75 ( V_7 ) ;
V_67:
F_76 ( V_103 , V_102 ) ;
V_106:
return V_8 ;
}
static int F_77 ( struct V_96 * V_97 , T_5 * V_98 ,
unsigned long V_99 , unsigned long V_110 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_7 V_111 = F_65 ( V_6 ) ;
T_7 * V_103 ;
int V_8 = 0 ;
V_103 = F_78 ( V_98 , V_99 ) ;
do {
if ( F_18 ( F_64 ( * V_103 , V_111 ) ) ) {
F_79 ( V_103 ) ;
V_8 = F_61 ( V_97 , V_98 , V_99 , V_6 , V_7 ) ;
if ( V_8 )
goto V_67;
V_103 = F_78 ( V_98 , V_99 ) ;
}
} while ( V_103 ++ , V_99 += V_112 , V_99 != V_110 );
F_79 ( V_103 - 1 ) ;
V_67:
return V_8 ;
}
static inline int F_80 ( struct V_96 * V_97 , T_8 * V_113 ,
unsigned long V_99 , unsigned long V_110 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_5 * V_98 ;
unsigned long V_28 ;
int V_8 ;
V_98 = F_81 ( V_113 , V_99 ) ;
do {
V_28 = F_82 ( V_99 , V_110 ) ;
if ( F_83 ( V_98 ) )
continue;
V_8 = F_77 ( V_97 , V_98 , V_99 , V_28 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_98 ++ , V_99 = V_28 , V_99 != V_110 );
return 0 ;
}
static inline int F_84 ( struct V_96 * V_97 , T_9 * V_114 ,
unsigned long V_99 , unsigned long V_110 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_8 * V_113 ;
unsigned long V_28 ;
int V_8 ;
V_113 = F_85 ( V_114 , V_99 ) ;
do {
V_28 = F_86 ( V_99 , V_110 ) ;
if ( F_87 ( V_113 ) )
continue;
V_8 = F_80 ( V_97 , V_113 , V_99 , V_28 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_113 ++ , V_99 = V_28 , V_99 != V_110 );
return 0 ;
}
static int F_88 ( struct V_96 * V_97 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_9 * V_114 ;
unsigned long V_99 , V_110 , V_28 ;
int V_8 ;
if ( F_89 ( V_7 ) ) {
V_99 = F_90 ( V_7 , V_97 ) ;
if ( V_99 == - V_115 )
return 0 ;
else
V_110 = V_99 + V_112 ;
} else {
V_99 = V_97 -> V_116 ;
V_110 = V_97 -> V_117 ;
}
V_114 = F_91 ( V_97 -> V_104 , V_99 ) ;
do {
V_28 = F_92 ( V_99 , V_110 ) ;
if ( F_93 ( V_114 ) )
continue;
V_8 = F_84 ( V_97 , V_114 , V_99 , V_28 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_114 ++ , V_99 = V_28 , V_99 != V_110 );
return 0 ;
}
static int F_94 ( struct V_118 * V_119 ,
T_1 V_6 , struct V_7 * V_7 )
{
struct V_96 * V_97 ;
int V_8 = 0 ;
if ( ! F_95 ( & V_119 -> V_120 ) ) {
F_75 ( V_7 ) ;
F_7 ( V_7 ) ;
F_96 ( & V_119 -> V_120 ) ;
F_97 ( V_7 ) ;
}
for ( V_97 = V_119 -> V_121 ; V_97 ; V_97 = V_97 -> V_122 ) {
if ( V_97 -> V_123 && ( V_8 = F_88 ( V_97 , V_6 , V_7 ) ) )
break;
}
F_98 ( & V_119 -> V_120 ) ;
return ( V_8 < 0 ) ? V_8 : 0 ;
}
static unsigned int F_99 ( struct V_3 * V_4 ,
unsigned int V_124 , bool V_125 )
{
unsigned int V_46 = V_4 -> V_46 ;
unsigned int V_126 = V_124 ;
unsigned char V_79 ;
for (; ; ) {
if ( ++ V_126 >= V_46 ) {
if ( ! V_124 ) {
V_126 = 0 ;
break;
}
V_46 = V_124 + 1 ;
V_124 = 0 ;
V_126 = 1 ;
}
if ( V_125 ) {
if ( F_100 ( V_4 , V_126 ) )
break;
else
continue;
}
V_79 = V_4 -> V_52 [ V_126 ] ;
if ( V_79 && F_1 ( V_79 ) != V_127 )
break;
}
return V_126 ;
}
int F_101 ( unsigned int type , bool V_125 ,
unsigned long V_128 )
{
struct V_3 * V_4 = V_63 [ type ] ;
struct V_118 * V_129 ;
unsigned char * V_52 ;
unsigned char V_130 ;
struct V_7 * V_7 ;
T_1 V_6 ;
unsigned int V_126 = 0 ;
int V_131 = 0 ;
V_129 = & V_132 ;
F_102 ( & V_132 . V_133 ) ;
while ( ( V_126 = F_99 ( V_4 , V_126 , V_125 ) ) != 0 ) {
if ( F_103 ( V_134 ) ) {
V_131 = - V_135 ;
break;
}
V_52 = & V_4 -> V_52 [ V_126 ] ;
V_6 = F_3 ( type , V_126 ) ;
V_7 = F_104 ( V_6 ,
V_136 , NULL , 0 ) ;
if ( ! V_7 ) {
if ( ! * V_52 )
continue;
V_131 = - V_105 ;
break;
}
if ( F_105 ( & V_129 -> V_133 ) == 1 ) {
F_106 ( V_129 ) ;
V_129 = & V_132 ;
F_102 ( & V_132 . V_133 ) ;
}
F_107 ( V_7 ) ;
F_108 ( V_7 ) ;
F_97 ( V_7 ) ;
F_108 ( V_7 ) ;
V_130 = * V_52 ;
if ( F_1 ( V_130 ) == V_81 ) {
V_131 = F_109 ( V_6 , V_7 ) ;
if ( V_131 < 0 )
break;
continue;
}
if ( F_1 ( V_130 ) && V_129 != & V_132 )
V_131 = F_94 ( V_129 , V_6 , V_7 ) ;
if ( F_1 ( * V_52 ) ) {
int V_137 = ( * V_52 >= V_130 ) ;
struct V_24 * V_66 = & V_129 -> V_138 ;
struct V_118 * V_139 = V_129 ;
struct V_118 * V_140 = V_129 ;
struct V_118 * V_119 ;
F_102 ( & V_139 -> V_133 ) ;
F_102 ( & V_140 -> V_133 ) ;
F_20 ( & V_141 ) ;
while ( F_1 ( * V_52 ) && ! V_131 &&
( V_66 = V_66 -> V_28 ) != & V_129 -> V_138 ) {
V_119 = F_14 ( V_66 , struct V_118 , V_138 ) ;
if ( ! F_110 ( & V_119 -> V_133 ) )
continue;
F_19 ( & V_141 ) ;
F_106 ( V_140 ) ;
V_140 = V_119 ;
F_11 () ;
V_130 = * V_52 ;
if ( ! F_1 ( V_130 ) )
;
else if ( V_119 == & V_132 )
V_137 = 1 ;
else
V_131 = F_94 ( V_119 , V_6 , V_7 ) ;
if ( V_137 && * V_52 < V_130 ) {
F_106 ( V_139 ) ;
F_102 ( & V_119 -> V_133 ) ;
V_139 = V_119 ;
V_137 = 0 ;
}
F_20 ( & V_141 ) ;
}
F_19 ( & V_141 ) ;
F_106 ( V_140 ) ;
F_106 ( V_129 ) ;
V_129 = V_139 ;
}
if ( V_131 ) {
F_7 ( V_7 ) ;
F_8 ( V_7 ) ;
break;
}
if ( F_1 ( * V_52 ) &&
F_111 ( V_7 ) && F_46 ( V_7 ) ) {
struct V_142 V_143 = {
. V_144 = V_145 ,
} ;
F_112 ( V_7 , & V_143 ) ;
F_97 ( V_7 ) ;
F_108 ( V_7 ) ;
}
if ( F_46 ( V_7 ) &&
F_113 ( F_41 ( V_7 ) == V_6 . V_10 ) )
F_48 ( V_7 ) ;
F_49 ( V_7 ) ;
F_7 ( V_7 ) ;
F_8 ( V_7 ) ;
F_11 () ;
if ( V_125 && V_128 > 0 ) {
if ( ! -- V_128 )
break;
}
}
F_106 ( V_129 ) ;
return V_131 ;
}
static void F_114 ( void )
{
struct V_24 * V_66 , * V_28 ;
unsigned int type ;
for ( type = 0 ; type < V_68 ; type ++ )
if ( V_63 [ type ] -> V_41 )
return;
F_20 ( & V_141 ) ;
F_115 (p, next, &init_mm.mmlist)
F_116 ( V_66 ) ;
F_19 ( & V_141 ) ;
}
static T_2 F_59 ( T_1 V_6 , struct V_91 * * V_19 )
{
struct V_3 * V_93 ;
struct V_11 * V_146 ;
struct V_11 * V_12 ;
T_3 V_5 ;
V_93 = V_63 [ F_29 ( V_6 ) ] ;
* V_19 = V_93 -> V_19 ;
V_5 = F_30 ( V_6 ) ;
V_146 = V_93 -> V_22 ;
V_12 = V_146 ;
for ( ; ; ) {
struct V_24 * V_25 ;
if ( V_12 -> V_21 <= V_5 &&
V_5 < ( V_12 -> V_21 + V_12 -> V_18 ) ) {
return V_12 -> V_13 + ( V_5 - V_12 -> V_21 ) ;
}
V_25 = V_12 -> V_27 . V_28 ;
V_12 = F_14 ( V_25 , struct V_11 , V_27 ) ;
V_93 -> V_22 = V_12 ;
F_117 ( V_12 == V_146 ) ;
}
}
T_2 F_118 ( struct V_7 * V_7 , struct V_91 * * V_19 )
{
T_1 V_6 ;
V_6 . V_10 = F_41 ( V_7 ) ;
return F_59 ( V_6 , V_19 ) ;
}
static void F_119 ( struct V_3 * V_93 )
{
while ( ! F_120 ( & V_93 -> V_16 . V_27 ) ) {
struct V_11 * V_12 ;
V_12 = F_14 ( V_93 -> V_16 . V_27 . V_28 ,
struct V_11 , V_27 ) ;
F_121 ( & V_12 -> V_27 ) ;
F_122 ( V_12 ) ;
}
if ( V_93 -> V_36 & V_147 ) {
struct V_148 * V_149 = V_93 -> V_149 ;
struct V_150 * V_151 = V_149 -> V_152 ;
V_93 -> V_36 &= ~ V_147 ;
V_151 -> V_153 -> V_154 ( V_149 ) ;
}
}
int
F_123 ( struct V_3 * V_93 , unsigned long V_21 ,
unsigned long V_18 , T_2 V_13 )
{
struct V_11 * V_12 ;
struct V_11 * V_155 ;
struct V_24 * V_25 ;
if ( V_21 == 0 ) {
V_12 = & V_93 -> V_16 ;
V_93 -> V_22 = V_12 ;
V_12 -> V_21 = 0 ;
V_12 -> V_18 = V_18 ;
V_12 -> V_13 = V_13 ;
return 1 ;
} else {
V_25 = V_93 -> V_16 . V_27 . V_124 ;
V_12 = F_14 ( V_25 , struct V_11 , V_27 ) ;
F_117 ( V_12 -> V_21 + V_12 -> V_18 != V_21 ) ;
if ( V_12 -> V_13 + V_12 -> V_18 == V_13 ) {
V_12 -> V_18 += V_18 ;
return 0 ;
}
}
V_155 = F_124 ( sizeof( * V_12 ) , V_20 ) ;
if ( V_155 == NULL )
return - V_105 ;
V_155 -> V_21 = V_21 ;
V_155 -> V_18 = V_18 ;
V_155 -> V_13 = V_13 ;
F_125 ( & V_155 -> V_27 , & V_93 -> V_16 . V_27 ) ;
return 1 ;
}
static int F_126 ( struct V_3 * V_93 , T_2 * V_156 )
{
struct V_148 * V_149 = V_93 -> V_149 ;
struct V_150 * V_151 = V_149 -> V_152 ;
struct V_157 * V_157 = V_151 -> V_158 ;
int V_8 ;
if ( F_127 ( V_157 -> V_159 ) ) {
V_8 = F_123 ( V_93 , 0 , V_93 -> V_46 , 0 ) ;
* V_156 = V_93 -> V_40 ;
return V_8 ;
}
if ( V_151 -> V_153 -> V_160 ) {
V_8 = V_151 -> V_153 -> V_160 ( V_93 , V_149 , V_156 ) ;
if ( ! V_8 ) {
V_93 -> V_36 |= V_147 ;
V_8 = F_123 ( V_93 , 0 , V_93 -> V_46 , 0 ) ;
* V_156 = V_93 -> V_40 ;
}
return V_8 ;
}
return F_128 ( V_93 , V_149 , V_156 ) ;
}
static void F_129 ( struct V_3 * V_66 , int V_64 ,
unsigned char * V_52 ,
unsigned long * V_161 )
{
int V_126 , V_124 ;
F_20 ( & V_48 ) ;
if ( V_64 >= 0 )
V_66 -> V_64 = V_64 ;
else
V_66 -> V_64 = -- V_162 ;
V_66 -> V_52 = V_52 ;
F_130 ( V_66 , V_161 ) ;
V_66 -> V_36 |= V_53 ;
V_60 += V_66 -> V_40 ;
V_163 += V_66 -> V_40 ;
V_124 = - 1 ;
for ( V_126 = V_62 . V_65 ; V_126 >= 0 ; V_126 = V_63 [ V_126 ] -> V_28 ) {
if ( V_66 -> V_64 >= V_63 [ V_126 ] -> V_64 )
break;
V_124 = V_126 ;
}
V_66 -> V_28 = V_126 ;
if ( V_124 < 0 )
V_62 . V_65 = V_62 . V_28 = V_66 -> type ;
else
V_63 [ V_124 ] -> V_28 = V_66 -> type ;
F_131 ( V_66 -> type ) ;
F_19 ( & V_48 ) ;
}
static unsigned F_132 ( struct V_148 * V_148 , T_10 * V_164 )
{
struct V_165 * V_166 = V_148 -> V_167 ;
F_133 ( V_148 , & V_168 , V_164 ) ;
if ( V_166 -> V_169 != F_105 ( & V_170 ) ) {
V_166 -> V_169 = F_105 ( & V_170 ) ;
return V_171 | V_172 | V_173 | V_174 ;
}
return V_171 | V_172 ;
}
static void * F_134 ( struct V_165 * V_175 , T_11 * V_176 )
{
struct V_3 * V_4 ;
int type ;
T_11 V_177 = * V_176 ;
F_135 ( & V_178 ) ;
if ( ! V_177 )
return V_179 ;
for ( type = 0 ; type < V_68 ; type ++ ) {
F_136 () ;
V_4 = V_63 [ type ] ;
if ( ! ( V_4 -> V_36 & V_70 ) || ! V_4 -> V_52 )
continue;
if ( ! -- V_177 )
return V_4 ;
}
return NULL ;
}
static void * F_137 ( struct V_165 * V_175 , void * V_180 , T_11 * V_176 )
{
struct V_3 * V_4 = V_180 ;
int type ;
if ( V_180 == V_179 )
type = 0 ;
else
type = V_4 -> type + 1 ;
for (; type < V_68 ; type ++ ) {
F_136 () ;
V_4 = V_63 [ type ] ;
if ( ! ( V_4 -> V_36 & V_70 ) || ! V_4 -> V_52 )
continue;
++ * V_176 ;
return V_4 ;
}
return NULL ;
}
static void F_138 ( struct V_165 * V_175 , void * V_180 )
{
F_139 ( & V_178 ) ;
}
static int F_140 ( struct V_165 * V_175 , void * V_180 )
{
struct V_3 * V_4 = V_180 ;
struct V_148 * V_148 ;
int V_181 ;
if ( V_4 == V_179 ) {
F_141 ( V_175 , L_2 ) ;
return 0 ;
}
V_148 = V_4 -> V_149 ;
V_181 = F_142 ( V_175 , & V_148 -> V_182 , L_3 ) ;
F_143 ( V_175 , L_4 ,
V_181 < 40 ? 40 - V_181 : 1 , L_5 ,
F_127 ( V_148 -> V_182 . V_183 -> V_184 -> V_159 ) ?
L_6 : L_7 ,
V_4 -> V_40 << ( V_17 - 10 ) ,
V_4 -> V_41 << ( V_17 - 10 ) ,
V_4 -> V_64 ) ;
return 0 ;
}
static int F_144 ( struct V_157 * V_157 , struct V_148 * V_148 )
{
struct V_165 * V_166 ;
int V_8 ;
V_8 = F_145 ( V_148 , & V_185 ) ;
if ( V_8 )
return V_8 ;
V_166 = V_148 -> V_167 ;
V_166 -> V_169 = F_105 ( & V_170 ) ;
return 0 ;
}
static int T_12 F_146 ( void )
{
F_147 ( L_8 , 0 , NULL , & V_186 ) ;
return 0 ;
}
static int T_12 F_148 ( void )
{
F_149 () ;
return 0 ;
}
static struct V_3 * F_150 ( void )
{
struct V_3 * V_66 ;
unsigned int type ;
V_66 = F_151 ( sizeof( * V_66 ) , V_20 ) ;
if ( ! V_66 )
return F_152 ( - V_105 ) ;
F_20 ( & V_48 ) ;
for ( type = 0 ; type < V_68 ; type ++ ) {
if ( ! ( V_63 [ type ] -> V_36 & V_70 ) )
break;
}
if ( type >= V_187 ) {
F_19 ( & V_48 ) ;
F_122 ( V_66 ) ;
return F_152 ( - V_188 ) ;
}
if ( type >= V_68 ) {
V_66 -> type = type ;
V_63 [ type ] = V_66 ;
F_153 () ;
V_68 ++ ;
} else {
F_122 ( V_66 ) ;
V_66 = V_63 [ type ] ;
}
F_154 ( & V_66 -> V_16 . V_27 ) ;
V_66 -> V_36 = V_70 ;
V_66 -> V_28 = - 1 ;
F_19 ( & V_48 ) ;
return V_66 ;
}
static int F_155 ( struct V_3 * V_66 , struct V_157 * V_157 )
{
int error ;
if ( F_127 ( V_157 -> V_159 ) ) {
V_66 -> V_19 = F_56 ( F_156 ( V_157 ) ) ;
error = F_157 ( V_66 -> V_19 ,
V_189 | V_190 | V_191 ,
V_192 ) ;
if ( error < 0 ) {
V_66 -> V_19 = NULL ;
return - V_193 ;
}
V_66 -> V_194 = F_158 ( V_66 -> V_19 ) ;
error = F_159 ( V_66 -> V_19 , V_112 ) ;
if ( error < 0 )
return error ;
V_66 -> V_36 |= V_84 ;
} else if ( F_160 ( V_157 -> V_159 ) ) {
V_66 -> V_19 = V_157 -> V_195 -> V_196 ;
F_135 ( & V_157 -> V_197 ) ;
if ( F_161 ( V_157 ) )
return - V_198 ;
} else
return - V_193 ;
return 0 ;
}
static unsigned long F_162 ( struct V_3 * V_66 ,
union V_199 * V_199 ,
struct V_157 * V_157 )
{
int V_126 ;
unsigned long V_200 ;
unsigned long V_201 ;
if ( memcmp ( L_9 , V_199 -> V_202 . V_202 , 10 ) ) {
F_31 ( V_74 L_10 ) ;
return 0 ;
}
if ( F_163 ( V_199 -> V_203 . V_204 ) == 1 ) {
F_164 ( & V_199 -> V_203 . V_204 ) ;
F_164 ( & V_199 -> V_203 . V_205 ) ;
F_164 ( & V_199 -> V_203 . V_206 ) ;
for ( V_126 = 0 ; V_126 < V_199 -> V_203 . V_206 ; V_126 ++ )
F_164 ( & V_199 -> V_203 . V_207 [ V_126 ] ) ;
}
if ( V_199 -> V_203 . V_204 != 1 ) {
F_31 ( V_208
L_11 ,
V_199 -> V_203 . V_204 ) ;
return 0 ;
}
V_66 -> V_50 = 1 ;
V_66 -> V_38 = 1 ;
V_66 -> V_39 = 0 ;
V_200 = F_30 ( F_165 (
F_65 ( F_3 ( 0 , ~ 0UL ) ) ) ) + 1 ;
if ( V_200 > V_199 -> V_203 . V_205 ) {
V_200 = V_199 -> V_203 . V_205 + 1 ;
if ( ( unsigned int ) V_200 == 0 )
V_200 = V_209 ;
}
V_66 -> V_51 = V_200 - 1 ;
if ( ! V_200 )
return 0 ;
V_201 = F_166 ( V_157 ) >> V_17 ;
if ( V_201 && V_200 > V_201 ) {
F_31 ( V_208
L_12 ) ;
return 0 ;
}
if ( V_199 -> V_203 . V_206 && F_160 ( V_157 -> V_159 ) )
return 0 ;
if ( V_199 -> V_203 . V_206 > V_210 )
return 0 ;
return V_200 ;
}
static int F_167 ( struct V_3 * V_66 ,
union V_199 * V_199 ,
unsigned char * V_52 ,
unsigned long V_200 ,
T_2 * V_156 )
{
int V_126 ;
unsigned int V_211 ;
int V_212 ;
V_211 = V_200 - 1 ;
for ( V_126 = 0 ; V_126 < V_199 -> V_203 . V_206 ; V_126 ++ ) {
unsigned int V_213 = V_199 -> V_203 . V_207 [ V_126 ] ;
if ( V_213 == 0 || V_213 > V_199 -> V_203 . V_205 )
return - V_193 ;
if ( V_213 < V_200 ) {
V_52 [ V_213 ] = V_127 ;
V_211 -- ;
}
}
if ( V_211 ) {
V_52 [ 0 ] = V_127 ;
V_66 -> V_46 = V_200 ;
V_66 -> V_40 = V_211 ;
V_212 = F_126 ( V_66 , V_156 ) ;
if ( V_212 < 0 )
return V_212 ;
V_211 = V_66 -> V_40 ;
}
if ( ! V_211 ) {
F_31 ( V_208 L_13 ) ;
return - V_193 ;
}
return V_212 ;
}
void F_168 ( struct V_214 * V_10 )
{
unsigned int type ;
unsigned long V_215 = 0 ;
F_20 ( & V_48 ) ;
for ( type = 0 ; type < V_68 ; type ++ ) {
struct V_3 * V_4 = V_63 [ type ] ;
if ( ( V_4 -> V_36 & V_70 ) && ! ( V_4 -> V_36 & V_53 ) )
V_215 += V_4 -> V_41 ;
}
V_10 -> V_216 = V_60 + V_215 ;
V_10 -> V_217 = V_163 + V_215 ;
F_19 ( & V_48 ) ;
}
static int F_169 ( T_1 V_6 , unsigned char V_30 )
{
struct V_3 * V_66 ;
unsigned long V_5 , type ;
unsigned char V_79 ;
unsigned char V_80 ;
int V_15 = - V_193 ;
if ( F_52 ( V_6 ) )
goto V_67;
type = F_29 ( V_6 ) ;
if ( type >= V_68 )
goto V_218;
V_66 = V_63 [ type ] ;
V_5 = F_30 ( V_6 ) ;
F_20 ( & V_48 ) ;
if ( F_18 ( V_5 >= V_66 -> V_46 ) )
goto V_219;
V_79 = V_66 -> V_52 [ V_5 ] ;
V_80 = V_79 & V_2 ;
V_79 &= ~ V_2 ;
V_15 = 0 ;
if ( V_30 == V_2 ) {
if ( ! V_80 && V_79 )
V_80 = V_2 ;
else if ( V_80 )
V_15 = - V_220 ;
else
V_15 = - V_221 ;
} else if ( V_79 || V_80 ) {
if ( ( V_79 & ~ V_82 ) < V_83 )
V_79 += V_30 ;
else if ( ( V_79 & ~ V_82 ) > V_83 )
V_15 = - V_193 ;
else if ( F_34 ( V_66 , V_5 , V_79 ) )
V_79 = V_82 ;
else
V_15 = - V_105 ;
} else
V_15 = - V_221 ;
V_66 -> V_52 [ V_5 ] = V_79 | V_80 ;
V_219:
F_19 ( & V_48 ) ;
V_67:
return V_15 ;
V_218:
F_31 ( V_74 L_14 , V_78 , V_6 . V_10 ) ;
goto V_67;
}
void F_170 ( T_1 V_6 )
{
F_169 ( V_6 , V_81 ) ;
}
int F_171 ( T_1 V_6 )
{
int V_15 = 0 ;
while ( ! V_15 && F_169 ( V_6 , 1 ) == - V_105 )
V_15 = F_172 ( V_6 , V_222 ) ;
return V_15 ;
}
int F_173 ( T_1 V_6 )
{
return F_169 ( V_6 , V_2 ) ;
}
struct V_3 * F_174 ( struct V_7 * V_7 )
{
T_1 V_175 = { . V_10 = F_41 (page) } ;
F_117 ( ! F_46 ( V_7 ) ) ;
return V_63 [ F_29 ( V_175 ) ] ;
}
struct V_150 * F_175 ( struct V_7 * V_7 )
{
F_33 ( ! F_46 ( V_7 ) ) ;
return F_174 ( V_7 ) -> V_149 -> V_152 ;
}
T_3 F_176 ( struct V_7 * V_7 )
{
T_1 V_175 = { . V_10 = F_41 (page) } ;
F_33 ( ! F_46 ( V_7 ) ) ;
return F_30 ( V_175 ) ;
}
int F_172 ( T_1 V_6 , T_13 V_223 )
{
struct V_3 * V_4 ;
struct V_7 * V_65 ;
struct V_7 * V_7 ;
struct V_7 * V_224 ;
T_3 V_5 ;
unsigned char V_79 ;
V_7 = F_177 ( V_223 | V_225 ) ;
V_4 = F_28 ( V_6 ) ;
if ( ! V_4 ) {
goto V_226;
}
V_5 = F_30 ( V_6 ) ;
V_79 = V_4 -> V_52 [ V_5 ] & ~ V_2 ;
if ( ( V_79 & ~ V_82 ) != V_83 ) {
goto V_67;
}
if ( ! V_7 ) {
F_19 ( & V_48 ) ;
return - V_105 ;
}
V_65 = F_178 ( V_4 -> V_52 + V_5 ) ;
V_5 &= ~ V_227 ;
if ( ! F_41 ( V_65 ) ) {
F_117 ( V_79 & V_82 ) ;
F_154 ( & V_65 -> V_228 ) ;
F_179 ( V_65 , V_229 ) ;
V_4 -> V_36 |= V_229 ;
}
F_12 (list_page, &head->lru, lru) {
unsigned char * V_230 ;
if ( ! ( V_79 & V_82 ) )
goto V_67;
V_230 = F_180 ( V_224 ) + V_5 ;
V_79 = * V_230 ;
F_181 ( V_230 ) ;
if ( ( V_79 & ~ V_82 ) != V_231 )
goto V_67;
}
F_125 ( & V_7 -> V_228 , & V_65 -> V_228 ) ;
V_7 = NULL ;
V_67:
F_19 ( & V_48 ) ;
V_226:
if ( V_7 )
F_182 ( V_7 ) ;
return 0 ;
}
static bool F_34 ( struct V_3 * V_4 ,
T_3 V_5 , unsigned char V_79 )
{
struct V_7 * V_65 ;
struct V_7 * V_7 ;
unsigned char * V_230 ;
V_65 = F_178 ( V_4 -> V_52 + V_5 ) ;
if ( F_41 ( V_65 ) != V_229 ) {
F_117 ( V_79 & V_82 ) ;
return false ;
}
V_5 &= ~ V_227 ;
V_7 = F_14 ( V_65 -> V_228 . V_28 , struct V_7 , V_228 ) ;
V_230 = F_180 ( V_7 ) + V_5 ;
if ( V_79 == V_83 )
goto V_232;
if ( V_79 == ( V_83 | V_82 ) ) {
while ( * V_230 == ( V_231 | V_82 ) ) {
F_181 ( V_230 ) ;
V_7 = F_14 ( V_7 -> V_228 . V_28 , struct V_7 , V_228 ) ;
F_117 ( V_7 == V_65 ) ;
V_230 = F_180 ( V_7 ) + V_5 ;
}
if ( * V_230 == V_231 ) {
F_181 ( V_230 ) ;
V_7 = F_14 ( V_7 -> V_228 . V_28 , struct V_7 , V_228 ) ;
if ( V_7 == V_65 )
return false ;
V_230 = F_180 ( V_7 ) + V_5 ;
V_232: * V_230 = 0 ;
}
* V_230 += 1 ;
F_181 ( V_230 ) ;
V_7 = F_14 ( V_7 -> V_228 . V_124 , struct V_7 , V_228 ) ;
while ( V_7 != V_65 ) {
V_230 = F_180 ( V_7 ) + V_5 ;
* V_230 = V_82 ;
F_181 ( V_230 ) ;
V_7 = F_14 ( V_7 -> V_228 . V_124 , struct V_7 , V_228 ) ;
}
return true ;
} else {
F_117 ( V_79 != V_82 ) ;
while ( * V_230 == V_82 ) {
F_181 ( V_230 ) ;
V_7 = F_14 ( V_7 -> V_228 . V_28 , struct V_7 , V_228 ) ;
F_117 ( V_7 == V_65 ) ;
V_230 = F_180 ( V_7 ) + V_5 ;
}
F_117 ( * V_230 == 0 ) ;
* V_230 -= 1 ;
if ( * V_230 == 0 )
V_79 = 0 ;
F_181 ( V_230 ) ;
V_7 = F_14 ( V_7 -> V_228 . V_124 , struct V_7 , V_228 ) ;
while ( V_7 != V_65 ) {
V_230 = F_180 ( V_7 ) + V_5 ;
* V_230 = V_231 | V_79 ;
V_79 = V_82 ;
F_181 ( V_230 ) ;
V_7 = F_14 ( V_7 -> V_228 . V_124 , struct V_7 , V_228 ) ;
}
return V_79 == V_82 ;
}
}
static void F_183 ( struct V_3 * V_4 )
{
T_3 V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_46 ; V_5 += V_112 ) {
struct V_7 * V_65 ;
V_65 = F_178 ( V_4 -> V_52 + V_5 ) ;
if ( F_41 ( V_65 ) ) {
struct V_24 * V_233 , * V_28 ;
F_115 (this, next, &head->lru) {
struct V_7 * V_7 ;
V_7 = F_14 ( V_233 , struct V_7 , V_228 ) ;
F_121 ( V_233 ) ;
F_182 ( V_7 ) ;
}
}
}
}
