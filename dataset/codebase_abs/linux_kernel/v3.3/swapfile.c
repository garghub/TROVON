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
if ( F_49 () )
return 0 ;
F_47 ( V_7 ) ;
F_48 ( V_7 ) ;
return 1 ;
}
int F_50 ( T_1 V_6 )
{
struct V_3 * V_66 ;
struct V_7 * V_7 = NULL ;
if ( F_51 ( V_6 ) )
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
( ! F_52 ( V_7 ) || F_21 () ) ) {
F_47 ( V_7 ) ;
F_48 ( V_7 ) ;
}
F_7 ( V_7 ) ;
F_8 ( V_7 ) ;
}
return V_66 != NULL ;
}
int F_53 ( T_1 V_1 , struct V_7 * * V_90 )
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
* V_90 = V_7 ;
return V_79 ;
}
int F_54 ( T_4 V_91 , T_2 V_5 , struct V_92 * * V_93 )
{
struct V_92 * V_19 = NULL ;
int type ;
if ( V_91 )
V_19 = F_55 ( V_91 ) ;
F_20 ( & V_48 ) ;
for ( type = 0 ; type < V_68 ; type ++ ) {
struct V_3 * V_94 = V_63 [ type ] ;
if ( ! ( V_94 -> V_36 & V_53 ) )
continue;
if ( ! V_19 ) {
if ( V_93 )
* V_93 = F_56 ( V_94 -> V_19 ) ;
F_19 ( & V_48 ) ;
return type ;
}
if ( V_19 == V_94 -> V_19 ) {
struct V_11 * V_12 = & V_94 -> V_16 ;
if ( V_12 -> V_13 == V_5 ) {
if ( V_93 )
* V_93 = F_56 ( V_94 -> V_19 ) ;
F_19 ( & V_48 ) ;
F_57 ( V_19 ) ;
return type ;
}
}
}
F_19 ( & V_48 ) ;
if ( V_19 )
F_57 ( V_19 ) ;
return - V_95 ;
}
T_2 F_58 ( int type , T_3 V_5 )
{
struct V_92 * V_19 ;
if ( ( unsigned int ) type >= V_68 )
return 0 ;
if ( ! ( V_63 [ type ] -> V_36 & V_53 ) )
return 0 ;
return F_59 ( F_3 ( type , V_5 ) , & V_19 ) ;
}
unsigned int F_60 ( int type , int free )
{
unsigned int V_96 = 0 ;
F_20 ( & V_48 ) ;
if ( ( unsigned int ) type < V_68 ) {
struct V_3 * V_94 = V_63 [ type ] ;
if ( V_94 -> V_36 & V_53 ) {
V_96 = V_94 -> V_40 ;
if ( free )
V_96 -= V_94 -> V_41 ;
}
}
F_19 ( & V_48 ) ;
return V_96 ;
}
static int F_61 ( struct V_97 * V_98 , T_5 * V_99 ,
unsigned long V_100 , T_1 V_6 , struct V_7 * V_7 )
{
struct V_101 * V_102 ;
T_6 * V_103 ;
T_7 * V_104 ;
int V_8 = 1 ;
if ( F_62 ( V_98 -> V_105 , V_7 ,
V_20 , & V_102 ) ) {
V_8 = - V_106 ;
goto V_107;
}
V_104 = F_63 ( V_98 -> V_105 , V_99 , V_100 , & V_103 ) ;
if ( F_18 ( ! F_64 ( * V_104 , F_65 ( V_6 ) ) ) ) {
if ( V_8 > 0 )
F_66 ( V_102 ) ;
V_8 = 0 ;
goto V_67;
}
F_67 ( V_98 -> V_105 , V_108 ) ;
F_68 ( V_98 -> V_105 , V_109 ) ;
F_69 ( V_7 ) ;
F_70 ( V_98 -> V_105 , V_100 , V_104 ,
F_71 ( F_72 ( V_7 , V_98 -> V_110 ) ) ) ;
F_73 ( V_7 , V_98 , V_100 ) ;
F_74 ( V_7 , V_102 ) ;
F_36 ( V_6 ) ;
F_75 ( V_7 ) ;
V_67:
F_76 ( V_104 , V_103 ) ;
V_107:
return V_8 ;
}
static int F_77 ( struct V_97 * V_98 , T_5 * V_99 ,
unsigned long V_100 , unsigned long V_111 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_7 V_112 = F_65 ( V_6 ) ;
T_7 * V_104 ;
int V_8 = 0 ;
V_104 = F_78 ( V_99 , V_100 ) ;
do {
if ( F_18 ( F_64 ( * V_104 , V_112 ) ) ) {
F_79 ( V_104 ) ;
V_8 = F_61 ( V_98 , V_99 , V_100 , V_6 , V_7 ) ;
if ( V_8 )
goto V_67;
V_104 = F_78 ( V_99 , V_100 ) ;
}
} while ( V_104 ++ , V_100 += V_113 , V_100 != V_111 );
F_79 ( V_104 - 1 ) ;
V_67:
return V_8 ;
}
static inline int F_80 ( struct V_97 * V_98 , T_8 * V_114 ,
unsigned long V_100 , unsigned long V_111 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_5 * V_99 ;
unsigned long V_28 ;
int V_8 ;
V_99 = F_81 ( V_114 , V_100 ) ;
do {
V_28 = F_82 ( V_100 , V_111 ) ;
if ( F_18 ( F_83 ( * V_99 ) ) )
continue;
if ( F_84 ( V_99 ) )
continue;
V_8 = F_77 ( V_98 , V_99 , V_100 , V_28 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_99 ++ , V_100 = V_28 , V_100 != V_111 );
return 0 ;
}
static inline int F_85 ( struct V_97 * V_98 , T_9 * V_115 ,
unsigned long V_100 , unsigned long V_111 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_8 * V_114 ;
unsigned long V_28 ;
int V_8 ;
V_114 = F_86 ( V_115 , V_100 ) ;
do {
V_28 = F_87 ( V_100 , V_111 ) ;
if ( F_88 ( V_114 ) )
continue;
V_8 = F_80 ( V_98 , V_114 , V_100 , V_28 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_114 ++ , V_100 = V_28 , V_100 != V_111 );
return 0 ;
}
static int F_89 ( struct V_97 * V_98 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_9 * V_115 ;
unsigned long V_100 , V_111 , V_28 ;
int V_8 ;
if ( F_90 ( V_7 ) ) {
V_100 = F_91 ( V_7 , V_98 ) ;
if ( V_100 == - V_116 )
return 0 ;
else
V_111 = V_100 + V_113 ;
} else {
V_100 = V_98 -> V_117 ;
V_111 = V_98 -> V_118 ;
}
V_115 = F_92 ( V_98 -> V_105 , V_100 ) ;
do {
V_28 = F_93 ( V_100 , V_111 ) ;
if ( F_94 ( V_115 ) )
continue;
V_8 = F_85 ( V_98 , V_115 , V_100 , V_28 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_115 ++ , V_100 = V_28 , V_100 != V_111 );
return 0 ;
}
static int F_95 ( struct V_119 * V_120 ,
T_1 V_6 , struct V_7 * V_7 )
{
struct V_97 * V_98 ;
int V_8 = 0 ;
if ( ! F_96 ( & V_120 -> V_121 ) ) {
F_75 ( V_7 ) ;
F_7 ( V_7 ) ;
F_97 ( & V_120 -> V_121 ) ;
F_98 ( V_7 ) ;
}
for ( V_98 = V_120 -> V_122 ; V_98 ; V_98 = V_98 -> V_123 ) {
if ( V_98 -> V_124 && ( V_8 = F_89 ( V_98 , V_6 , V_7 ) ) )
break;
}
F_99 ( & V_120 -> V_121 ) ;
return ( V_8 < 0 ) ? V_8 : 0 ;
}
static unsigned int F_100 ( struct V_3 * V_4 ,
unsigned int V_125 )
{
unsigned int V_46 = V_4 -> V_46 ;
unsigned int V_126 = V_125 ;
unsigned char V_79 ;
for (; ; ) {
if ( ++ V_126 >= V_46 ) {
if ( ! V_125 ) {
V_126 = 0 ;
break;
}
V_46 = V_125 + 1 ;
V_125 = 0 ;
V_126 = 1 ;
}
V_79 = V_4 -> V_52 [ V_126 ] ;
if ( V_79 && F_1 ( V_79 ) != V_127 )
break;
}
return V_126 ;
}
static int F_101 ( unsigned int type )
{
struct V_3 * V_4 = V_63 [ type ] ;
struct V_119 * V_128 ;
unsigned char * V_52 ;
unsigned char V_129 ;
struct V_7 * V_7 ;
T_1 V_6 ;
unsigned int V_126 = 0 ;
int V_130 = 0 ;
V_128 = & V_131 ;
F_102 ( & V_131 . V_132 ) ;
while ( ( V_126 = F_100 ( V_4 , V_126 ) ) != 0 ) {
if ( F_103 ( V_133 ) ) {
V_130 = - V_134 ;
break;
}
V_52 = & V_4 -> V_52 [ V_126 ] ;
V_6 = F_3 ( type , V_126 ) ;
V_7 = F_104 ( V_6 ,
V_135 , NULL , 0 ) ;
if ( ! V_7 ) {
if ( ! * V_52 )
continue;
V_130 = - V_106 ;
break;
}
if ( F_105 ( & V_128 -> V_132 ) == 1 ) {
F_106 ( V_128 ) ;
V_128 = & V_131 ;
F_102 ( & V_131 . V_132 ) ;
}
F_107 ( V_7 ) ;
F_108 ( V_7 ) ;
F_98 ( V_7 ) ;
F_108 ( V_7 ) ;
V_129 = * V_52 ;
if ( F_1 ( V_129 ) == V_81 ) {
V_130 = F_109 ( V_6 , V_7 ) ;
if ( V_130 < 0 )
break;
continue;
}
if ( F_1 ( V_129 ) && V_128 != & V_131 )
V_130 = F_95 ( V_128 , V_6 , V_7 ) ;
if ( F_1 ( * V_52 ) ) {
int V_136 = ( * V_52 >= V_129 ) ;
struct V_24 * V_66 = & V_128 -> V_137 ;
struct V_119 * V_138 = V_128 ;
struct V_119 * V_139 = V_128 ;
struct V_119 * V_120 ;
F_102 ( & V_138 -> V_132 ) ;
F_102 ( & V_139 -> V_132 ) ;
F_20 ( & V_140 ) ;
while ( F_1 ( * V_52 ) && ! V_130 &&
( V_66 = V_66 -> V_28 ) != & V_128 -> V_137 ) {
V_120 = F_14 ( V_66 , struct V_119 , V_137 ) ;
if ( ! F_110 ( & V_120 -> V_132 ) )
continue;
F_19 ( & V_140 ) ;
F_106 ( V_139 ) ;
V_139 = V_120 ;
F_11 () ;
V_129 = * V_52 ;
if ( ! F_1 ( V_129 ) )
;
else if ( V_120 == & V_131 )
V_136 = 1 ;
else
V_130 = F_95 ( V_120 , V_6 , V_7 ) ;
if ( V_136 && * V_52 < V_129 ) {
F_106 ( V_138 ) ;
F_102 ( & V_120 -> V_132 ) ;
V_138 = V_120 ;
V_136 = 0 ;
}
F_20 ( & V_140 ) ;
}
F_19 ( & V_140 ) ;
F_106 ( V_139 ) ;
F_106 ( V_128 ) ;
V_128 = V_138 ;
}
if ( V_130 ) {
F_7 ( V_7 ) ;
F_8 ( V_7 ) ;
break;
}
if ( F_1 ( * V_52 ) &&
F_111 ( V_7 ) && F_45 ( V_7 ) ) {
struct V_141 V_142 = {
. V_143 = V_144 ,
} ;
F_112 ( V_7 , & V_142 ) ;
F_98 ( V_7 ) ;
F_108 ( V_7 ) ;
}
if ( F_45 ( V_7 ) &&
F_113 ( F_40 ( V_7 ) == V_6 . V_10 ) )
F_47 ( V_7 ) ;
F_48 ( V_7 ) ;
F_7 ( V_7 ) ;
F_8 ( V_7 ) ;
F_11 () ;
}
F_106 ( V_128 ) ;
return V_130 ;
}
static void F_114 ( void )
{
struct V_24 * V_66 , * V_28 ;
unsigned int type ;
for ( type = 0 ; type < V_68 ; type ++ )
if ( V_63 [ type ] -> V_41 )
return;
F_20 ( & V_140 ) ;
F_115 (p, next, &init_mm.mmlist)
F_116 ( V_66 ) ;
F_19 ( & V_140 ) ;
}
static T_2 F_59 ( T_1 V_6 , struct V_92 * * V_19 )
{
struct V_3 * V_94 ;
struct V_11 * V_145 ;
struct V_11 * V_12 ;
T_3 V_5 ;
V_94 = V_63 [ F_29 ( V_6 ) ] ;
* V_19 = V_94 -> V_19 ;
V_5 = F_30 ( V_6 ) ;
V_145 = V_94 -> V_22 ;
V_12 = V_145 ;
for ( ; ; ) {
struct V_24 * V_25 ;
if ( V_12 -> V_21 <= V_5 &&
V_5 < ( V_12 -> V_21 + V_12 -> V_18 ) ) {
return V_12 -> V_13 + ( V_5 - V_12 -> V_21 ) ;
}
V_25 = V_12 -> V_27 . V_28 ;
V_12 = F_14 ( V_25 , struct V_11 , V_27 ) ;
V_94 -> V_22 = V_12 ;
F_117 ( V_12 == V_145 ) ;
}
}
T_2 F_118 ( struct V_7 * V_7 , struct V_92 * * V_19 )
{
T_1 V_6 ;
V_6 . V_10 = F_40 ( V_7 ) ;
return F_59 ( V_6 , V_19 ) ;
}
static void F_119 ( struct V_3 * V_94 )
{
while ( ! F_120 ( & V_94 -> V_16 . V_27 ) ) {
struct V_11 * V_12 ;
V_12 = F_14 ( V_94 -> V_16 . V_27 . V_28 ,
struct V_11 , V_27 ) ;
F_121 ( & V_12 -> V_27 ) ;
F_122 ( V_12 ) ;
}
}
static int
F_123 ( struct V_3 * V_94 , unsigned long V_21 ,
unsigned long V_18 , T_2 V_13 )
{
struct V_11 * V_12 ;
struct V_11 * V_146 ;
struct V_24 * V_25 ;
if ( V_21 == 0 ) {
V_12 = & V_94 -> V_16 ;
V_94 -> V_22 = V_12 ;
V_12 -> V_21 = 0 ;
V_12 -> V_18 = V_18 ;
V_12 -> V_13 = V_13 ;
return 1 ;
} else {
V_25 = V_94 -> V_16 . V_27 . V_125 ;
V_12 = F_14 ( V_25 , struct V_11 , V_27 ) ;
F_117 ( V_12 -> V_21 + V_12 -> V_18 != V_21 ) ;
if ( V_12 -> V_13 + V_12 -> V_18 == V_13 ) {
V_12 -> V_18 += V_18 ;
return 0 ;
}
}
V_146 = F_124 ( sizeof( * V_12 ) , V_20 ) ;
if ( V_146 == NULL )
return - V_106 ;
V_146 -> V_21 = V_21 ;
V_146 -> V_18 = V_18 ;
V_146 -> V_13 = V_13 ;
F_125 ( & V_146 -> V_27 , & V_94 -> V_16 . V_27 ) ;
return 1 ;
}
static int F_126 ( struct V_3 * V_94 , T_2 * V_147 )
{
struct V_148 * V_148 ;
unsigned V_149 ;
unsigned long V_150 ;
unsigned V_151 ;
T_2 V_152 ;
T_2 V_153 ;
T_2 V_154 = - 1 ;
T_2 V_155 = 0 ;
int V_156 = 0 ;
int V_8 ;
V_148 = V_94 -> V_157 -> V_158 -> V_159 ;
if ( F_127 ( V_148 -> V_160 ) ) {
V_8 = F_123 ( V_94 , 0 , V_94 -> V_46 , 0 ) ;
* V_147 = V_94 -> V_40 ;
goto V_67;
}
V_151 = V_148 -> V_161 ;
V_149 = V_113 >> V_151 ;
V_152 = 0 ;
V_150 = 0 ;
V_153 = F_128 ( V_148 ) >> V_151 ;
while ( ( V_152 + V_149 ) <= V_153 &&
V_150 < V_94 -> V_46 ) {
unsigned V_162 ;
T_2 V_163 ;
V_163 = F_129 ( V_148 , V_152 ) ;
if ( V_163 == 0 )
goto V_164;
if ( V_163 & ( V_149 - 1 ) ) {
V_152 ++ ;
goto V_165;
}
for ( V_162 = 1 ; V_162 < V_149 ;
V_162 ++ ) {
T_2 V_166 ;
V_166 = F_129 ( V_148 , V_152 + V_162 ) ;
if ( V_166 == 0 )
goto V_164;
if ( V_166 != V_163 + V_162 ) {
V_152 ++ ;
goto V_165;
}
}
V_163 >>= ( V_17 - V_151 ) ;
if ( V_150 ) {
if ( V_163 < V_154 )
V_154 = V_163 ;
if ( V_163 > V_155 )
V_155 = V_163 ;
}
V_8 = F_123 ( V_94 , V_150 , 1 , V_163 ) ;
if ( V_8 < 0 )
goto V_67;
V_156 += V_8 ;
V_150 ++ ;
V_152 += V_149 ;
V_165:
continue;
}
V_8 = V_156 ;
* V_147 = 1 + V_155 - V_154 ;
if ( V_150 == 0 )
V_150 = 1 ;
V_94 -> V_46 = V_150 ;
V_94 -> V_40 = V_150 - 1 ;
V_94 -> V_51 = V_150 - 1 ;
V_67:
return V_8 ;
V_164:
F_31 ( V_74 L_2 ) ;
V_8 = - V_167 ;
goto V_67;
}
static void F_130 ( struct V_3 * V_66 , int V_64 ,
unsigned char * V_52 )
{
int V_126 , V_125 ;
F_20 ( & V_48 ) ;
if ( V_64 >= 0 )
V_66 -> V_64 = V_64 ;
else
V_66 -> V_64 = -- V_168 ;
V_66 -> V_52 = V_52 ;
V_66 -> V_36 |= V_53 ;
V_60 += V_66 -> V_40 ;
V_169 += V_66 -> V_40 ;
V_125 = - 1 ;
for ( V_126 = V_62 . V_65 ; V_126 >= 0 ; V_126 = V_63 [ V_126 ] -> V_28 ) {
if ( V_66 -> V_64 >= V_63 [ V_126 ] -> V_64 )
break;
V_125 = V_126 ;
}
V_66 -> V_28 = V_126 ;
if ( V_125 < 0 )
V_62 . V_65 = V_62 . V_28 = V_66 -> type ;
else
V_63 [ V_125 ] -> V_28 = V_66 -> type ;
F_19 ( & V_48 ) ;
}
static unsigned F_131 ( struct V_170 * V_170 , T_10 * V_171 )
{
struct V_172 * V_173 = V_170 -> V_174 ;
F_132 ( V_170 , & V_175 , V_171 ) ;
if ( V_173 -> V_176 != F_105 ( & V_177 ) ) {
V_173 -> V_176 = F_105 ( & V_177 ) ;
return V_178 | V_179 | V_180 | V_181 ;
}
return V_178 | V_179 ;
}
static void * F_133 ( struct V_172 * V_182 , T_11 * V_183 )
{
struct V_3 * V_4 ;
int type ;
T_11 V_184 = * V_183 ;
F_134 ( & V_185 ) ;
if ( ! V_184 )
return V_186 ;
for ( type = 0 ; type < V_68 ; type ++ ) {
F_135 () ;
V_4 = V_63 [ type ] ;
if ( ! ( V_4 -> V_36 & V_70 ) || ! V_4 -> V_52 )
continue;
if ( ! -- V_184 )
return V_4 ;
}
return NULL ;
}
static void * F_136 ( struct V_172 * V_182 , void * V_187 , T_11 * V_183 )
{
struct V_3 * V_4 = V_187 ;
int type ;
if ( V_187 == V_186 )
type = 0 ;
else
type = V_4 -> type + 1 ;
for (; type < V_68 ; type ++ ) {
F_135 () ;
V_4 = V_63 [ type ] ;
if ( ! ( V_4 -> V_36 & V_70 ) || ! V_4 -> V_52 )
continue;
++ * V_183 ;
return V_4 ;
}
return NULL ;
}
static void F_137 ( struct V_172 * V_182 , void * V_187 )
{
F_138 ( & V_185 ) ;
}
static int F_139 ( struct V_172 * V_182 , void * V_187 )
{
struct V_3 * V_4 = V_187 ;
struct V_170 * V_170 ;
int V_188 ;
if ( V_4 == V_186 ) {
F_140 ( V_182 , L_3 ) ;
return 0 ;
}
V_170 = V_4 -> V_157 ;
V_188 = F_141 ( V_182 , & V_170 -> V_189 , L_4 ) ;
F_142 ( V_182 , L_5 ,
V_188 < 40 ? 40 - V_188 : 1 , L_6 ,
F_127 ( V_170 -> V_189 . V_190 -> V_191 -> V_160 ) ?
L_7 : L_8 ,
V_4 -> V_40 << ( V_17 - 10 ) ,
V_4 -> V_41 << ( V_17 - 10 ) ,
V_4 -> V_64 ) ;
return 0 ;
}
static int F_143 ( struct V_148 * V_148 , struct V_170 * V_170 )
{
struct V_172 * V_173 ;
int V_8 ;
V_8 = F_144 ( V_170 , & V_192 ) ;
if ( V_8 )
return V_8 ;
V_173 = V_170 -> V_174 ;
V_173 -> V_176 = F_105 ( & V_177 ) ;
return 0 ;
}
static int T_12 F_145 ( void )
{
F_146 ( L_9 , 0 , NULL , & V_193 ) ;
return 0 ;
}
static int T_12 F_147 ( void )
{
F_148 () ;
return 0 ;
}
static struct V_3 * F_149 ( void )
{
struct V_3 * V_66 ;
unsigned int type ;
V_66 = F_150 ( sizeof( * V_66 ) , V_20 ) ;
if ( ! V_66 )
return F_151 ( - V_106 ) ;
F_20 ( & V_48 ) ;
for ( type = 0 ; type < V_68 ; type ++ ) {
if ( ! ( V_63 [ type ] -> V_36 & V_70 ) )
break;
}
if ( type >= V_194 ) {
F_19 ( & V_48 ) ;
F_122 ( V_66 ) ;
return F_151 ( - V_195 ) ;
}
if ( type >= V_68 ) {
V_66 -> type = type ;
V_63 [ type ] = V_66 ;
F_152 () ;
V_68 ++ ;
} else {
F_122 ( V_66 ) ;
V_66 = V_63 [ type ] ;
}
F_153 ( & V_66 -> V_16 . V_27 ) ;
V_66 -> V_36 = V_70 ;
V_66 -> V_28 = - 1 ;
F_19 ( & V_48 ) ;
return V_66 ;
}
static int F_154 ( struct V_3 * V_66 , struct V_148 * V_148 )
{
int error ;
if ( F_127 ( V_148 -> V_160 ) ) {
V_66 -> V_19 = F_56 ( F_155 ( V_148 ) ) ;
error = F_156 ( V_66 -> V_19 ,
V_196 | V_197 | V_198 ,
V_199 ) ;
if ( error < 0 ) {
V_66 -> V_19 = NULL ;
return - V_167 ;
}
V_66 -> V_200 = F_157 ( V_66 -> V_19 ) ;
error = F_158 ( V_66 -> V_19 , V_113 ) ;
if ( error < 0 )
return error ;
V_66 -> V_36 |= V_87 ;
} else if ( F_159 ( V_148 -> V_160 ) ) {
V_66 -> V_19 = V_148 -> V_201 -> V_202 ;
F_134 ( & V_148 -> V_203 ) ;
if ( F_160 ( V_148 ) )
return - V_204 ;
} else
return - V_167 ;
return 0 ;
}
static unsigned long F_161 ( struct V_3 * V_66 ,
union V_205 * V_205 ,
struct V_148 * V_148 )
{
int V_126 ;
unsigned long V_206 ;
unsigned long V_207 ;
if ( memcmp ( L_10 , V_205 -> V_208 . V_208 , 10 ) ) {
F_31 ( V_74 L_11 ) ;
return 0 ;
}
if ( F_162 ( V_205 -> V_209 . V_210 ) == 1 ) {
F_163 ( & V_205 -> V_209 . V_210 ) ;
F_163 ( & V_205 -> V_209 . V_211 ) ;
F_163 ( & V_205 -> V_209 . V_212 ) ;
for ( V_126 = 0 ; V_126 < V_205 -> V_209 . V_212 ; V_126 ++ )
F_163 ( & V_205 -> V_209 . V_213 [ V_126 ] ) ;
}
if ( V_205 -> V_209 . V_210 != 1 ) {
F_31 ( V_214
L_12 ,
V_205 -> V_209 . V_210 ) ;
return 0 ;
}
V_66 -> V_50 = 1 ;
V_66 -> V_38 = 1 ;
V_66 -> V_39 = 0 ;
V_206 = F_30 ( F_164 (
F_65 ( F_3 ( 0 , ~ 0UL ) ) ) ) ;
V_206 = F_30 ( F_165 (
F_166 ( F_3 ( 0 , V_206 ) ) ) ) + 1 ;
if ( V_206 > V_205 -> V_209 . V_211 ) {
V_206 = V_205 -> V_209 . V_211 + 1 ;
if ( ( unsigned int ) V_206 == 0 )
V_206 = V_215 ;
}
V_66 -> V_51 = V_206 - 1 ;
if ( ! V_206 )
return 0 ;
V_207 = F_128 ( V_148 ) >> V_17 ;
if ( V_207 && V_206 > V_207 ) {
F_31 ( V_214
L_13 ) ;
return 0 ;
}
if ( V_205 -> V_209 . V_212 && F_159 ( V_148 -> V_160 ) )
return 0 ;
if ( V_205 -> V_209 . V_212 > V_216 )
return 0 ;
return V_206 ;
}
static int F_167 ( struct V_3 * V_66 ,
union V_205 * V_205 ,
unsigned char * V_52 ,
unsigned long V_206 ,
T_2 * V_147 )
{
int V_126 ;
unsigned int V_217 ;
int V_156 ;
V_217 = V_206 - 1 ;
for ( V_126 = 0 ; V_126 < V_205 -> V_209 . V_212 ; V_126 ++ ) {
unsigned int V_218 = V_205 -> V_209 . V_213 [ V_126 ] ;
if ( V_218 == 0 || V_218 > V_205 -> V_209 . V_211 )
return - V_167 ;
if ( V_218 < V_206 ) {
V_52 [ V_218 ] = V_127 ;
V_217 -- ;
}
}
if ( V_217 ) {
V_52 [ 0 ] = V_127 ;
V_66 -> V_46 = V_206 ;
V_66 -> V_40 = V_217 ;
V_156 = F_126 ( V_66 , V_147 ) ;
if ( V_156 < 0 )
return V_156 ;
V_217 = V_66 -> V_40 ;
}
if ( ! V_217 ) {
F_31 ( V_214 L_14 ) ;
return - V_167 ;
}
return V_156 ;
}
void F_168 ( struct V_219 * V_10 )
{
unsigned int type ;
unsigned long V_220 = 0 ;
F_20 ( & V_48 ) ;
for ( type = 0 ; type < V_68 ; type ++ ) {
struct V_3 * V_4 = V_63 [ type ] ;
if ( ( V_4 -> V_36 & V_70 ) && ! ( V_4 -> V_36 & V_53 ) )
V_220 += V_4 -> V_41 ;
}
V_10 -> V_221 = V_60 + V_220 ;
V_10 -> V_222 = V_169 + V_220 ;
F_19 ( & V_48 ) ;
}
static int F_169 ( T_1 V_6 , unsigned char V_30 )
{
struct V_3 * V_66 ;
unsigned long V_5 , type ;
unsigned char V_79 ;
unsigned char V_80 ;
int V_15 = - V_167 ;
if ( F_51 ( V_6 ) )
goto V_67;
type = F_29 ( V_6 ) ;
if ( type >= V_68 )
goto V_223;
V_66 = V_63 [ type ] ;
V_5 = F_30 ( V_6 ) ;
F_20 ( & V_48 ) ;
if ( F_18 ( V_5 >= V_66 -> V_46 ) )
goto V_224;
V_79 = V_66 -> V_52 [ V_5 ] ;
V_80 = V_79 & V_2 ;
V_79 &= ~ V_2 ;
V_15 = 0 ;
if ( V_30 == V_2 ) {
if ( ! V_80 && V_79 )
V_80 = V_2 ;
else if ( V_80 )
V_15 = - V_225 ;
else
V_15 = - V_226 ;
} else if ( V_79 || V_80 ) {
if ( ( V_79 & ~ V_82 ) < V_83 )
V_79 += V_30 ;
else if ( ( V_79 & ~ V_82 ) > V_83 )
V_15 = - V_167 ;
else if ( F_34 ( V_66 , V_5 , V_79 ) )
V_79 = V_82 ;
else
V_15 = - V_106 ;
} else
V_15 = - V_226 ;
V_66 -> V_52 [ V_5 ] = V_79 | V_80 ;
V_224:
F_19 ( & V_48 ) ;
V_67:
return V_15 ;
V_223:
F_31 ( V_74 L_15 , V_78 , V_6 . V_10 ) ;
goto V_67;
}
void F_170 ( T_1 V_6 )
{
F_169 ( V_6 , V_81 ) ;
}
int F_171 ( T_1 V_6 )
{
int V_15 = 0 ;
while ( ! V_15 && F_169 ( V_6 , 1 ) == - V_106 )
V_15 = F_172 ( V_6 , V_227 ) ;
return V_15 ;
}
int F_173 ( T_1 V_6 )
{
return F_169 ( V_6 , V_2 ) ;
}
int F_174 ( T_1 V_6 , unsigned long * V_5 )
{
struct V_3 * V_4 ;
int V_228 = V_229 ;
T_3 V_230 , V_231 ;
T_3 V_232 , V_111 ;
int V_18 = 0 ;
if ( ! V_228 )
return 0 ;
V_4 = V_63 [ F_29 ( V_6 ) ] ;
V_230 = F_30 ( V_6 ) ;
V_232 = ( V_230 >> V_228 ) << V_228 ;
V_111 = V_232 + ( 1 << V_228 ) ;
if ( ! V_232 )
V_232 ++ ;
F_20 ( & V_48 ) ;
if ( V_111 > V_4 -> V_46 )
V_111 = V_4 -> V_46 ;
for ( V_231 = V_230 ; ++ V_231 < V_111 ; V_18 ++ ) {
if ( ! V_4 -> V_52 [ V_231 ] )
break;
if ( F_1 ( V_4 -> V_52 [ V_231 ] ) == V_127 )
break;
}
for ( V_231 = V_230 ; -- V_231 >= V_232 ; V_18 ++ ) {
if ( ! V_4 -> V_52 [ V_231 ] )
break;
if ( F_1 ( V_4 -> V_52 [ V_231 ] ) == V_127 )
break;
}
F_19 ( & V_48 ) ;
* V_5 = ++ V_231 ;
return V_18 ? ++ V_18 : 0 ;
}
int F_172 ( T_1 V_6 , T_13 V_233 )
{
struct V_3 * V_4 ;
struct V_7 * V_65 ;
struct V_7 * V_7 ;
struct V_7 * V_234 ;
T_3 V_5 ;
unsigned char V_79 ;
V_7 = F_175 ( V_233 | V_235 ) ;
V_4 = F_28 ( V_6 ) ;
if ( ! V_4 ) {
goto V_236;
}
V_5 = F_30 ( V_6 ) ;
V_79 = V_4 -> V_52 [ V_5 ] & ~ V_2 ;
if ( ( V_79 & ~ V_82 ) != V_83 ) {
goto V_67;
}
if ( ! V_7 ) {
F_19 ( & V_48 ) ;
return - V_106 ;
}
V_65 = F_176 ( V_4 -> V_52 + V_5 ) ;
V_5 &= ~ V_237 ;
if ( ! F_40 ( V_65 ) ) {
F_117 ( V_79 & V_82 ) ;
F_153 ( & V_65 -> V_238 ) ;
F_177 ( V_65 , V_239 ) ;
V_4 -> V_36 |= V_239 ;
}
F_12 (list_page, &head->lru, lru) {
unsigned char * V_240 ;
if ( ! ( V_79 & V_82 ) )
goto V_67;
V_240 = F_178 ( V_234 , V_241 ) + V_5 ;
V_79 = * V_240 ;
F_179 ( V_240 , V_241 ) ;
if ( ( V_79 & ~ V_82 ) != V_242 )
goto V_67;
}
F_125 ( & V_7 -> V_238 , & V_65 -> V_238 ) ;
V_7 = NULL ;
V_67:
F_19 ( & V_48 ) ;
V_236:
if ( V_7 )
F_180 ( V_7 ) ;
return 0 ;
}
static bool F_34 ( struct V_3 * V_4 ,
T_3 V_5 , unsigned char V_79 )
{
struct V_7 * V_65 ;
struct V_7 * V_7 ;
unsigned char * V_240 ;
V_65 = F_176 ( V_4 -> V_52 + V_5 ) ;
if ( F_40 ( V_65 ) != V_239 ) {
F_117 ( V_79 & V_82 ) ;
return false ;
}
V_5 &= ~ V_237 ;
V_7 = F_14 ( V_65 -> V_238 . V_28 , struct V_7 , V_238 ) ;
V_240 = F_178 ( V_7 , V_241 ) + V_5 ;
if ( V_79 == V_83 )
goto V_243;
if ( V_79 == ( V_83 | V_82 ) ) {
while ( * V_240 == ( V_242 | V_82 ) ) {
F_179 ( V_240 , V_241 ) ;
V_7 = F_14 ( V_7 -> V_238 . V_28 , struct V_7 , V_238 ) ;
F_117 ( V_7 == V_65 ) ;
V_240 = F_178 ( V_7 , V_241 ) + V_5 ;
}
if ( * V_240 == V_242 ) {
F_179 ( V_240 , V_241 ) ;
V_7 = F_14 ( V_7 -> V_238 . V_28 , struct V_7 , V_238 ) ;
if ( V_7 == V_65 )
return false ;
V_240 = F_178 ( V_7 , V_241 ) + V_5 ;
V_243: * V_240 = 0 ;
}
* V_240 += 1 ;
F_179 ( V_240 , V_241 ) ;
V_7 = F_14 ( V_7 -> V_238 . V_125 , struct V_7 , V_238 ) ;
while ( V_7 != V_65 ) {
V_240 = F_178 ( V_7 , V_241 ) + V_5 ;
* V_240 = V_82 ;
F_179 ( V_240 , V_241 ) ;
V_7 = F_14 ( V_7 -> V_238 . V_125 , struct V_7 , V_238 ) ;
}
return true ;
} else {
F_117 ( V_79 != V_82 ) ;
while ( * V_240 == V_82 ) {
F_179 ( V_240 , V_241 ) ;
V_7 = F_14 ( V_7 -> V_238 . V_28 , struct V_7 , V_238 ) ;
F_117 ( V_7 == V_65 ) ;
V_240 = F_178 ( V_7 , V_241 ) + V_5 ;
}
F_117 ( * V_240 == 0 ) ;
* V_240 -= 1 ;
if ( * V_240 == 0 )
V_79 = 0 ;
F_179 ( V_240 , V_241 ) ;
V_7 = F_14 ( V_7 -> V_238 . V_125 , struct V_7 , V_238 ) ;
while ( V_7 != V_65 ) {
V_240 = F_178 ( V_7 , V_241 ) + V_5 ;
* V_240 = V_242 | V_79 ;
V_79 = V_82 ;
F_179 ( V_240 , V_241 ) ;
V_7 = F_14 ( V_7 -> V_238 . V_125 , struct V_7 , V_238 ) ;
}
return V_79 == V_82 ;
}
}
static void F_181 ( struct V_3 * V_4 )
{
T_3 V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_46 ; V_5 += V_113 ) {
struct V_7 * V_65 ;
V_65 = F_176 ( V_4 -> V_52 + V_5 ) ;
if ( F_40 ( V_65 ) ) {
struct V_24 * V_244 , * V_28 ;
F_115 (this, next, &head->lru) {
struct V_7 * V_7 ;
V_7 = F_14 ( V_244 , struct V_7 , V_238 ) ;
F_121 ( V_244 ) ;
F_180 ( V_7 ) ;
}
}
}
}
