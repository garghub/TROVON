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
static int F_16 ( void * V_28 )
{
F_17 () ;
return 0 ;
}
static unsigned long F_18 ( struct V_3 * V_4 ,
unsigned char V_29 )
{
unsigned long V_5 ;
unsigned long V_30 ;
unsigned long V_31 = 0 ;
int V_32 = V_33 ;
int V_34 = 0 ;
V_4 -> V_35 += V_36 ;
V_30 = V_5 = V_4 -> V_37 ;
if ( F_19 ( ! V_4 -> V_38 -- ) ) {
if ( V_4 -> V_39 - V_4 -> V_40 < V_41 ) {
V_4 -> V_38 = V_41 - 1 ;
goto V_42;
}
if ( V_4 -> V_35 & V_43 ) {
if ( V_4 -> V_44 )
goto V_42;
V_4 -> V_44 = V_4 -> V_45 ;
V_4 -> V_46 = 0 ;
}
F_20 ( & V_4 -> V_47 ) ;
if ( ! ( V_4 -> V_35 & V_48 ) )
V_30 = V_5 = V_4 -> V_49 ;
V_31 = V_5 + V_41 - 1 ;
for (; V_31 <= V_4 -> V_50 ; V_5 ++ ) {
if ( V_4 -> V_51 [ V_5 ] )
V_31 = V_5 + V_41 ;
else if ( V_5 == V_31 ) {
F_21 ( & V_4 -> V_47 ) ;
V_5 -= V_41 - 1 ;
V_4 -> V_37 = V_5 ;
V_4 -> V_38 = V_41 - 1 ;
V_34 = 1 ;
goto V_42;
}
if ( F_19 ( -- V_32 < 0 ) ) {
F_12 () ;
V_32 = V_33 ;
}
}
V_5 = V_4 -> V_49 ;
V_31 = V_5 + V_41 - 1 ;
for (; V_31 < V_30 ; V_5 ++ ) {
if ( V_4 -> V_51 [ V_5 ] )
V_31 = V_5 + V_41 ;
else if ( V_5 == V_31 ) {
F_21 ( & V_4 -> V_47 ) ;
V_5 -= V_41 - 1 ;
V_4 -> V_37 = V_5 ;
V_4 -> V_38 = V_41 - 1 ;
V_34 = 1 ;
goto V_42;
}
if ( F_19 ( -- V_32 < 0 ) ) {
F_12 () ;
V_32 = V_33 ;
}
}
V_5 = V_30 ;
F_21 ( & V_4 -> V_47 ) ;
V_4 -> V_38 = V_41 - 1 ;
V_4 -> V_44 = 0 ;
}
V_42:
if ( ! ( V_4 -> V_35 & V_52 ) )
goto V_53;
if ( ! V_4 -> V_50 )
goto V_53;
if ( V_5 > V_4 -> V_50 )
V_30 = V_5 = V_4 -> V_49 ;
if ( F_22 () && V_4 -> V_51 [ V_5 ] == V_2 ) {
int V_54 ;
F_20 ( & V_4 -> V_47 ) ;
V_54 = F_2 ( V_4 , V_5 ) ;
F_21 ( & V_4 -> V_47 ) ;
if ( V_54 )
goto V_42;
goto V_55;
}
if ( V_4 -> V_51 [ V_5 ] )
goto V_55;
if ( V_5 == V_4 -> V_49 )
V_4 -> V_49 ++ ;
if ( V_5 == V_4 -> V_50 )
V_4 -> V_50 -- ;
V_4 -> V_40 ++ ;
if ( V_4 -> V_40 == V_4 -> V_39 ) {
V_4 -> V_49 = V_4 -> V_45 ;
V_4 -> V_50 = 0 ;
}
V_4 -> V_51 [ V_5 ] = V_29 ;
V_4 -> V_37 = V_5 + 1 ;
V_4 -> V_35 -= V_36 ;
if ( V_4 -> V_44 ) {
if ( V_34 ) {
if ( V_5 < V_4 -> V_46 &&
V_4 -> V_44 <= V_31 )
V_31 = V_4 -> V_44 - 1 ;
V_4 -> V_35 |= V_56 ;
F_20 ( & V_4 -> V_47 ) ;
if ( V_5 < V_31 )
F_14 ( V_4 , V_5 ,
V_31 - V_5 + 1 ) ;
F_21 ( & V_4 -> V_47 ) ;
V_4 -> V_44 = 0 ;
V_4 -> V_35 &= ~ V_56 ;
F_23 () ;
F_24 ( & V_4 -> V_35 , F_25 ( V_56 ) ) ;
} else if ( V_4 -> V_35 & V_56 ) {
F_20 ( & V_4 -> V_47 ) ;
F_26 ( & V_4 -> V_35 , F_25 ( V_56 ) ,
F_16 , V_57 ) ;
F_21 ( & V_4 -> V_47 ) ;
} else {
if ( V_5 < V_4 -> V_44 )
V_4 -> V_44 = V_5 ;
if ( V_5 > V_4 -> V_46 )
V_4 -> V_46 = V_5 ;
}
}
return V_5 ;
V_55:
F_20 ( & V_4 -> V_47 ) ;
while ( ++ V_5 <= V_4 -> V_50 ) {
if ( ! V_4 -> V_51 [ V_5 ] ) {
F_21 ( & V_4 -> V_47 ) ;
goto V_42;
}
if ( F_22 () && V_4 -> V_51 [ V_5 ] == V_2 ) {
F_21 ( & V_4 -> V_47 ) ;
goto V_42;
}
if ( F_19 ( -- V_32 < 0 ) ) {
F_12 () ;
V_32 = V_33 ;
}
}
V_5 = V_4 -> V_49 ;
while ( ++ V_5 < V_30 ) {
if ( ! V_4 -> V_51 [ V_5 ] ) {
F_21 ( & V_4 -> V_47 ) ;
goto V_42;
}
if ( F_22 () && V_4 -> V_51 [ V_5 ] == V_2 ) {
F_21 ( & V_4 -> V_47 ) ;
goto V_42;
}
if ( F_19 ( -- V_32 < 0 ) ) {
F_12 () ;
V_32 = V_33 ;
}
}
F_21 ( & V_4 -> V_47 ) ;
V_53:
V_4 -> V_35 -= V_36 ;
return 0 ;
}
T_1 F_27 ( void )
{
struct V_3 * V_4 ;
T_3 V_5 ;
int type , V_27 ;
int V_58 = 0 ;
int V_59 ;
F_21 ( & V_60 ) ;
if ( F_28 ( & V_61 ) <= 0 )
goto V_62;
F_29 ( & V_61 ) ;
for ( type = V_63 . V_27 ; type >= 0 && V_58 < 2 ; type = V_27 ) {
V_59 = F_30 ( & V_64 , - 1 ) ;
if ( V_59 != - 1 && V_59 != type &&
V_65 [ type ] -> V_66 < V_65 [ V_59 ] -> V_66 &&
( V_65 [ V_59 ] -> V_35 & V_52 ) ) {
type = V_59 ;
V_63 . V_27 = type ;
}
V_4 = V_65 [ type ] ;
V_27 = V_4 -> V_27 ;
if ( V_27 < 0 ||
( ! V_58 && V_4 -> V_66 != V_65 [ V_27 ] -> V_66 ) ) {
V_27 = V_63 . V_67 ;
V_58 ++ ;
}
F_21 ( & V_4 -> V_47 ) ;
if ( ! V_4 -> V_50 ) {
F_20 ( & V_4 -> V_47 ) ;
continue;
}
if ( ! ( V_4 -> V_35 & V_52 ) ) {
F_20 ( & V_4 -> V_47 ) ;
continue;
}
V_63 . V_27 = V_27 ;
F_20 ( & V_60 ) ;
V_5 = F_18 ( V_4 , V_2 ) ;
F_20 ( & V_4 -> V_47 ) ;
if ( V_5 )
return F_3 ( type , V_5 ) ;
F_21 ( & V_60 ) ;
V_27 = V_63 . V_27 ;
}
F_31 ( & V_61 ) ;
V_62:
F_20 ( & V_60 ) ;
return ( T_1 ) { 0 } ;
}
T_1 F_32 ( int type )
{
struct V_3 * V_4 ;
T_3 V_5 ;
V_4 = V_65 [ type ] ;
F_21 ( & V_4 -> V_47 ) ;
if ( V_4 && ( V_4 -> V_35 & V_52 ) ) {
F_29 ( & V_61 ) ;
V_5 = F_18 ( V_4 , 1 ) ;
if ( V_5 ) {
F_20 ( & V_4 -> V_47 ) ;
return F_3 ( type , V_5 ) ;
}
F_31 ( & V_61 ) ;
}
F_20 ( & V_4 -> V_47 ) ;
return ( T_1 ) { 0 } ;
}
static struct V_3 * F_33 ( T_1 V_6 )
{
struct V_3 * V_68 ;
unsigned long V_5 , type ;
if ( ! V_6 . V_9 )
goto V_69;
type = F_34 ( V_6 ) ;
if ( type >= V_70 )
goto V_71;
V_68 = V_65 [ type ] ;
if ( ! ( V_68 -> V_35 & V_72 ) )
goto V_73;
V_5 = F_35 ( V_6 ) ;
if ( V_5 >= V_68 -> V_45 )
goto V_74;
if ( ! V_68 -> V_51 [ V_5 ] )
goto V_75;
F_21 ( & V_68 -> V_47 ) ;
return V_68 ;
V_75:
F_36 ( V_76 L_1 , V_77 , V_6 . V_9 ) ;
goto V_69;
V_74:
F_36 ( V_76 L_1 , V_78 , V_6 . V_9 ) ;
goto V_69;
V_73:
F_36 ( V_76 L_1 , V_79 , V_6 . V_9 ) ;
goto V_69;
V_71:
F_36 ( V_76 L_1 , V_80 , V_6 . V_9 ) ;
V_69:
return NULL ;
}
static void F_37 ( int type )
{
int V_81 , V_82 ;
do {
V_81 = F_38 ( & V_64 ) ;
if ( V_81 != - 1 &&
V_65 [ V_81 ] -> V_66 >= V_65 [ type ] -> V_66 )
break;
V_82 = type ;
} while ( F_39 ( & V_64 ,
V_81 , V_82 ) != V_81 );
}
static unsigned char F_40 ( struct V_3 * V_68 ,
T_1 V_6 , unsigned char V_29 )
{
unsigned long V_5 = F_35 ( V_6 ) ;
unsigned char V_83 ;
unsigned char V_84 ;
V_83 = V_68 -> V_51 [ V_5 ] ;
V_84 = V_83 & V_2 ;
V_83 &= ~ V_2 ;
if ( V_29 == V_2 ) {
F_41 ( ! V_84 ) ;
V_84 = 0 ;
} else if ( V_83 == V_85 ) {
V_83 = 0 ;
} else if ( ( V_83 & ~ V_86 ) <= V_87 ) {
if ( V_83 == V_86 ) {
if ( F_42 ( V_68 , V_5 , V_83 ) )
V_83 = V_87 | V_86 ;
else
V_83 = V_87 ;
} else
V_83 -- ;
}
if ( ! V_83 )
F_43 ( V_6 ) ;
V_29 = V_83 | V_84 ;
V_68 -> V_51 [ V_5 ] = V_29 ;
if ( ! V_29 ) {
if ( V_5 < V_68 -> V_49 )
V_68 -> V_49 = V_5 ;
if ( V_5 > V_68 -> V_50 )
V_68 -> V_50 = V_5 ;
F_37 ( V_68 -> type ) ;
F_31 ( & V_61 ) ;
V_68 -> V_40 -- ;
F_44 ( V_68 -> type , V_5 ) ;
if ( V_68 -> V_35 & V_88 ) {
struct V_89 * V_90 = V_68 -> V_18 -> V_91 ;
if ( V_90 -> V_92 -> V_93 )
V_90 -> V_92 -> V_93 ( V_68 -> V_18 ,
V_5 ) ;
}
}
return V_29 ;
}
void F_45 ( T_1 V_6 )
{
struct V_3 * V_68 ;
V_68 = F_33 ( V_6 ) ;
if ( V_68 ) {
F_40 ( V_68 , V_6 , 1 ) ;
F_20 ( & V_68 -> V_47 ) ;
}
}
void F_46 ( T_1 V_6 , struct V_7 * V_7 )
{
struct V_3 * V_68 ;
unsigned char V_83 ;
V_68 = F_33 ( V_6 ) ;
if ( V_68 ) {
V_83 = F_40 ( V_68 , V_6 , V_2 ) ;
if ( V_7 )
F_47 ( V_7 , V_6 , V_83 != 0 ) ;
F_20 ( & V_68 -> V_47 ) ;
}
}
int F_48 ( struct V_7 * V_7 )
{
int V_83 = 0 ;
struct V_3 * V_68 ;
T_1 V_6 ;
V_6 . V_9 = F_49 ( V_7 ) ;
V_68 = F_33 ( V_6 ) ;
if ( V_68 ) {
V_83 = F_1 ( V_68 -> V_51 [ F_35 ( V_6 ) ] ) ;
F_20 ( & V_68 -> V_47 ) ;
}
return V_83 ;
}
int F_50 ( struct V_7 * V_7 )
{
int V_83 ;
F_41 ( ! F_51 ( V_7 ) ) ;
if ( F_19 ( F_52 ( V_7 ) ) )
return 0 ;
V_83 = F_53 ( V_7 ) ;
if ( V_83 <= 1 && F_54 ( V_7 ) ) {
V_83 += F_48 ( V_7 ) ;
if ( V_83 == 1 && ! F_55 ( V_7 ) ) {
F_56 ( V_7 ) ;
F_57 ( V_7 ) ;
}
}
return V_83 <= 1 ;
}
int F_7 ( struct V_7 * V_7 )
{
F_41 ( ! F_51 ( V_7 ) ) ;
if ( ! F_54 ( V_7 ) )
return 0 ;
if ( F_55 ( V_7 ) )
return 0 ;
if ( F_48 ( V_7 ) )
return 0 ;
if ( F_58 () )
return 0 ;
F_56 ( V_7 ) ;
F_57 ( V_7 ) ;
return 1 ;
}
int F_59 ( T_1 V_6 )
{
struct V_3 * V_68 ;
struct V_7 * V_7 = NULL ;
if ( F_60 ( V_6 ) )
return 1 ;
V_68 = F_33 ( V_6 ) ;
if ( V_68 ) {
if ( F_40 ( V_68 , V_6 , 1 ) == V_2 ) {
V_7 = F_4 ( F_5 ( V_6 ) ,
V_6 . V_9 ) ;
if ( V_7 && ! F_6 ( V_7 ) ) {
F_9 ( V_7 ) ;
V_7 = NULL ;
}
}
F_20 ( & V_68 -> V_47 ) ;
}
if ( V_7 ) {
if ( F_54 ( V_7 ) && ! F_55 ( V_7 ) &&
( ! F_61 ( V_7 ) || F_22 () ) ) {
F_56 ( V_7 ) ;
F_57 ( V_7 ) ;
}
F_8 ( V_7 ) ;
F_9 ( V_7 ) ;
}
return V_68 != NULL ;
}
int F_62 ( T_4 V_94 , T_2 V_5 , struct V_95 * * V_96 )
{
struct V_95 * V_18 = NULL ;
int type ;
if ( V_94 )
V_18 = F_63 ( V_94 ) ;
F_21 ( & V_60 ) ;
for ( type = 0 ; type < V_70 ; type ++ ) {
struct V_3 * V_97 = V_65 [ type ] ;
if ( ! ( V_97 -> V_35 & V_52 ) )
continue;
if ( ! V_18 ) {
if ( V_96 )
* V_96 = F_64 ( V_97 -> V_18 ) ;
F_20 ( & V_60 ) ;
return type ;
}
if ( V_18 == V_97 -> V_18 ) {
struct V_10 * V_11 = & V_97 -> V_15 ;
if ( V_11 -> V_12 == V_5 ) {
if ( V_96 )
* V_96 = F_64 ( V_97 -> V_18 ) ;
F_20 ( & V_60 ) ;
F_65 ( V_18 ) ;
return type ;
}
}
}
F_20 ( & V_60 ) ;
if ( V_18 )
F_65 ( V_18 ) ;
return - V_98 ;
}
T_2 F_66 ( int type , T_3 V_5 )
{
struct V_95 * V_18 ;
if ( ( unsigned int ) type >= V_70 )
return 0 ;
if ( ! ( V_65 [ type ] -> V_35 & V_52 ) )
return 0 ;
return F_67 ( F_3 ( type , V_5 ) , & V_18 ) ;
}
unsigned int F_68 ( int type , int free )
{
unsigned int V_99 = 0 ;
F_21 ( & V_60 ) ;
if ( ( unsigned int ) type < V_70 ) {
struct V_3 * V_97 = V_65 [ type ] ;
F_21 ( & V_97 -> V_47 ) ;
if ( V_97 -> V_35 & V_52 ) {
V_99 = V_97 -> V_39 ;
if ( free )
V_99 -= V_97 -> V_40 ;
}
F_20 ( & V_97 -> V_47 ) ;
}
F_20 ( & V_60 ) ;
return V_99 ;
}
static int F_69 ( struct V_100 * V_101 , T_5 * V_102 ,
unsigned long V_103 , T_1 V_6 , struct V_7 * V_7 )
{
struct V_7 * V_104 ;
struct V_105 * V_106 ;
T_6 * V_107 ;
T_7 * V_108 ;
int V_8 = 1 ;
V_104 = V_7 ;
V_7 = F_70 ( V_7 , V_101 , V_103 ) ;
if ( F_19 ( ! V_7 ) )
return - V_109 ;
if ( F_71 ( V_101 -> V_110 , V_7 ,
V_19 , & V_106 ) ) {
V_8 = - V_109 ;
goto V_111;
}
V_108 = F_72 ( V_101 -> V_110 , V_102 , V_103 , & V_107 ) ;
if ( F_19 ( ! F_73 ( * V_108 , F_74 ( V_6 ) ) ) ) {
F_75 ( V_106 ) ;
V_8 = 0 ;
goto V_69;
}
F_76 ( V_101 -> V_110 , V_112 ) ;
F_77 ( V_101 -> V_110 , V_113 ) ;
F_78 ( V_7 ) ;
F_79 ( V_101 -> V_110 , V_103 , V_108 ,
F_80 ( F_81 ( V_7 , V_101 -> V_114 ) ) ) ;
if ( V_7 == V_104 )
F_82 ( V_7 , V_101 , V_103 ) ;
else
F_83 ( V_7 , V_101 , V_103 ) ;
F_84 ( V_7 , V_106 ) ;
F_45 ( V_6 ) ;
F_85 ( V_7 ) ;
V_69:
F_86 ( V_108 , V_107 ) ;
V_111:
if ( V_7 != V_104 ) {
F_8 ( V_7 ) ;
F_87 ( V_7 ) ;
}
return V_8 ;
}
static int F_88 ( struct V_100 * V_101 , T_5 * V_102 ,
unsigned long V_103 , unsigned long V_115 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_7 V_116 = F_74 ( V_6 ) ;
T_7 * V_108 ;
int V_8 = 0 ;
V_108 = F_89 ( V_102 , V_103 ) ;
do {
if ( F_19 ( F_73 ( * V_108 , V_116 ) ) ) {
F_90 ( V_108 ) ;
V_8 = F_69 ( V_101 , V_102 , V_103 , V_6 , V_7 ) ;
if ( V_8 )
goto V_69;
V_108 = F_89 ( V_102 , V_103 ) ;
}
} while ( V_108 ++ , V_103 += V_117 , V_103 != V_115 );
F_90 ( V_108 - 1 ) ;
V_69:
return V_8 ;
}
static inline int F_91 ( struct V_100 * V_101 , T_8 * V_118 ,
unsigned long V_103 , unsigned long V_115 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_5 * V_102 ;
unsigned long V_27 ;
int V_8 ;
V_102 = F_92 ( V_118 , V_103 ) ;
do {
V_27 = F_93 ( V_103 , V_115 ) ;
if ( F_94 ( V_102 ) )
continue;
V_8 = F_88 ( V_101 , V_102 , V_103 , V_27 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_102 ++ , V_103 = V_27 , V_103 != V_115 );
return 0 ;
}
static inline int F_95 ( struct V_100 * V_101 , T_9 * V_119 ,
unsigned long V_103 , unsigned long V_115 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_8 * V_118 ;
unsigned long V_27 ;
int V_8 ;
V_118 = F_96 ( V_119 , V_103 ) ;
do {
V_27 = F_97 ( V_103 , V_115 ) ;
if ( F_98 ( V_118 ) )
continue;
V_8 = F_91 ( V_101 , V_118 , V_103 , V_27 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_118 ++ , V_103 = V_27 , V_103 != V_115 );
return 0 ;
}
static int F_99 ( struct V_100 * V_101 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_9 * V_119 ;
unsigned long V_103 , V_115 , V_27 ;
int V_8 ;
if ( F_100 ( V_7 ) ) {
V_103 = F_101 ( V_7 , V_101 ) ;
if ( V_103 == - V_120 )
return 0 ;
else
V_115 = V_103 + V_117 ;
} else {
V_103 = V_101 -> V_121 ;
V_115 = V_101 -> V_122 ;
}
V_119 = F_102 ( V_101 -> V_110 , V_103 ) ;
do {
V_27 = F_103 ( V_103 , V_115 ) ;
if ( F_104 ( V_119 ) )
continue;
V_8 = F_95 ( V_101 , V_119 , V_103 , V_27 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_119 ++ , V_103 = V_27 , V_103 != V_115 );
return 0 ;
}
static int F_105 ( struct V_123 * V_124 ,
T_1 V_6 , struct V_7 * V_7 )
{
struct V_100 * V_101 ;
int V_8 = 0 ;
if ( ! F_106 ( & V_124 -> V_125 ) ) {
F_85 ( V_7 ) ;
F_8 ( V_7 ) ;
F_107 ( & V_124 -> V_125 ) ;
F_108 ( V_7 ) ;
}
for ( V_101 = V_124 -> V_126 ; V_101 ; V_101 = V_101 -> V_127 ) {
if ( V_101 -> V_128 && ( V_8 = F_99 ( V_101 , V_6 , V_7 ) ) )
break;
}
F_109 ( & V_124 -> V_125 ) ;
return ( V_8 < 0 ) ? V_8 : 0 ;
}
static unsigned int F_110 ( struct V_3 * V_4 ,
unsigned int V_129 , bool V_130 )
{
unsigned int V_45 = V_4 -> V_45 ;
unsigned int V_131 = V_129 ;
unsigned char V_83 ;
for (; ; ) {
if ( ++ V_131 >= V_45 ) {
if ( ! V_129 ) {
V_131 = 0 ;
break;
}
V_45 = V_129 + 1 ;
V_129 = 0 ;
V_131 = 1 ;
}
if ( V_130 ) {
if ( F_111 ( V_4 , V_131 ) )
break;
else
continue;
}
V_83 = V_4 -> V_51 [ V_131 ] ;
if ( V_83 && F_1 ( V_83 ) != V_132 )
break;
}
return V_131 ;
}
int F_112 ( unsigned int type , bool V_130 ,
unsigned long V_133 )
{
struct V_3 * V_4 = V_65 [ type ] ;
struct V_123 * V_134 ;
unsigned char * V_51 ;
unsigned char V_135 ;
struct V_7 * V_7 ;
T_1 V_6 ;
unsigned int V_131 = 0 ;
int V_136 = 0 ;
V_134 = & V_137 ;
F_113 ( & V_137 . V_138 ) ;
while ( ( V_131 = F_110 ( V_4 , V_131 , V_130 ) ) != 0 ) {
if ( F_114 ( V_139 ) ) {
V_136 = - V_140 ;
break;
}
V_51 = & V_4 -> V_51 [ V_131 ] ;
V_6 = F_3 ( type , V_131 ) ;
V_7 = F_115 ( V_6 ,
V_141 , NULL , 0 ) ;
if ( ! V_7 ) {
if ( ! * V_51 )
continue;
V_136 = - V_109 ;
break;
}
if ( F_38 ( & V_134 -> V_138 ) == 1 ) {
F_116 ( V_134 ) ;
V_134 = & V_137 ;
F_113 ( & V_137 . V_138 ) ;
}
F_117 ( V_7 ) ;
F_118 ( V_7 ) ;
F_108 ( V_7 ) ;
F_118 ( V_7 ) ;
V_135 = * V_51 ;
if ( F_1 ( V_135 ) == V_85 ) {
V_136 = F_119 ( V_6 , V_7 ) ;
if ( V_136 < 0 )
break;
continue;
}
if ( F_1 ( V_135 ) && V_134 != & V_137 )
V_136 = F_105 ( V_134 , V_6 , V_7 ) ;
if ( F_1 ( * V_51 ) ) {
int V_142 = ( * V_51 >= V_135 ) ;
struct V_23 * V_68 = & V_134 -> V_143 ;
struct V_123 * V_144 = V_134 ;
struct V_123 * V_145 = V_134 ;
struct V_123 * V_124 ;
F_113 ( & V_144 -> V_138 ) ;
F_113 ( & V_145 -> V_138 ) ;
F_21 ( & V_146 ) ;
while ( F_1 ( * V_51 ) && ! V_136 &&
( V_68 = V_68 -> V_27 ) != & V_134 -> V_143 ) {
V_124 = F_15 ( V_68 , struct V_123 , V_143 ) ;
if ( ! F_120 ( & V_124 -> V_138 ) )
continue;
F_20 ( & V_146 ) ;
F_116 ( V_145 ) ;
V_145 = V_124 ;
F_12 () ;
V_135 = * V_51 ;
if ( ! F_1 ( V_135 ) )
;
else if ( V_124 == & V_137 )
V_142 = 1 ;
else
V_136 = F_105 ( V_124 , V_6 , V_7 ) ;
if ( V_142 && * V_51 < V_135 ) {
F_116 ( V_144 ) ;
F_113 ( & V_124 -> V_138 ) ;
V_144 = V_124 ;
V_142 = 0 ;
}
F_21 ( & V_146 ) ;
}
F_20 ( & V_146 ) ;
F_116 ( V_145 ) ;
F_116 ( V_134 ) ;
V_134 = V_144 ;
}
if ( V_136 ) {
F_8 ( V_7 ) ;
F_9 ( V_7 ) ;
break;
}
if ( F_1 ( * V_51 ) &&
F_121 ( V_7 ) && F_54 ( V_7 ) ) {
struct V_147 V_148 = {
. V_149 = V_150 ,
} ;
F_122 ( V_7 , & V_148 ) ;
F_108 ( V_7 ) ;
F_118 ( V_7 ) ;
}
if ( F_54 ( V_7 ) &&
F_123 ( F_49 ( V_7 ) == V_6 . V_9 ) )
F_56 ( V_7 ) ;
F_57 ( V_7 ) ;
F_8 ( V_7 ) ;
F_9 ( V_7 ) ;
F_12 () ;
if ( V_130 && V_133 > 0 ) {
if ( ! -- V_133 )
break;
}
}
F_116 ( V_134 ) ;
return V_136 ;
}
static void F_124 ( void )
{
struct V_23 * V_68 , * V_27 ;
unsigned int type ;
for ( type = 0 ; type < V_70 ; type ++ )
if ( V_65 [ type ] -> V_40 )
return;
F_21 ( & V_146 ) ;
F_125 (p, next, &init_mm.mmlist)
F_126 ( V_68 ) ;
F_20 ( & V_146 ) ;
}
static T_2 F_67 ( T_1 V_6 , struct V_95 * * V_18 )
{
struct V_3 * V_97 ;
struct V_10 * V_151 ;
struct V_10 * V_11 ;
T_3 V_5 ;
V_97 = V_65 [ F_34 ( V_6 ) ] ;
* V_18 = V_97 -> V_18 ;
V_5 = F_35 ( V_6 ) ;
V_151 = V_97 -> V_21 ;
V_11 = V_151 ;
for ( ; ; ) {
struct V_23 * V_24 ;
if ( V_11 -> V_20 <= V_5 &&
V_5 < ( V_11 -> V_20 + V_11 -> V_17 ) ) {
return V_11 -> V_12 + ( V_5 - V_11 -> V_20 ) ;
}
V_24 = V_11 -> V_26 . V_27 ;
V_11 = F_15 ( V_24 , struct V_10 , V_26 ) ;
V_97 -> V_21 = V_11 ;
F_127 ( V_11 == V_151 ) ;
}
}
T_2 F_128 ( struct V_7 * V_7 , struct V_95 * * V_18 )
{
T_1 V_6 ;
V_6 . V_9 = F_49 ( V_7 ) ;
return F_67 ( V_6 , V_18 ) ;
}
static void F_129 ( struct V_3 * V_97 )
{
while ( ! F_130 ( & V_97 -> V_15 . V_26 ) ) {
struct V_10 * V_11 ;
V_11 = F_15 ( V_97 -> V_15 . V_26 . V_27 ,
struct V_10 , V_26 ) ;
F_131 ( & V_11 -> V_26 ) ;
F_132 ( V_11 ) ;
}
if ( V_97 -> V_35 & V_152 ) {
struct V_153 * V_154 = V_97 -> V_154 ;
struct V_155 * V_156 = V_154 -> V_157 ;
V_97 -> V_35 &= ~ V_152 ;
V_156 -> V_158 -> V_159 ( V_154 ) ;
}
}
int
F_133 ( struct V_3 * V_97 , unsigned long V_20 ,
unsigned long V_17 , T_2 V_12 )
{
struct V_10 * V_11 ;
struct V_10 * V_160 ;
struct V_23 * V_24 ;
if ( V_20 == 0 ) {
V_11 = & V_97 -> V_15 ;
V_97 -> V_21 = V_11 ;
V_11 -> V_20 = 0 ;
V_11 -> V_17 = V_17 ;
V_11 -> V_12 = V_12 ;
return 1 ;
} else {
V_24 = V_97 -> V_15 . V_26 . V_129 ;
V_11 = F_15 ( V_24 , struct V_10 , V_26 ) ;
F_127 ( V_11 -> V_20 + V_11 -> V_17 != V_20 ) ;
if ( V_11 -> V_12 + V_11 -> V_17 == V_12 ) {
V_11 -> V_17 += V_17 ;
return 0 ;
}
}
V_160 = F_134 ( sizeof( * V_11 ) , V_19 ) ;
if ( V_160 == NULL )
return - V_109 ;
V_160 -> V_20 = V_20 ;
V_160 -> V_17 = V_17 ;
V_160 -> V_12 = V_12 ;
F_135 ( & V_160 -> V_26 , & V_97 -> V_15 . V_26 ) ;
return 1 ;
}
static int F_136 ( struct V_3 * V_97 , T_2 * V_161 )
{
struct V_153 * V_154 = V_97 -> V_154 ;
struct V_155 * V_156 = V_154 -> V_157 ;
struct V_162 * V_162 = V_156 -> V_163 ;
int V_8 ;
if ( F_137 ( V_162 -> V_164 ) ) {
V_8 = F_133 ( V_97 , 0 , V_97 -> V_45 , 0 ) ;
* V_161 = V_97 -> V_39 ;
return V_8 ;
}
if ( V_156 -> V_158 -> V_165 ) {
V_8 = V_156 -> V_158 -> V_165 ( V_97 , V_154 , V_161 ) ;
if ( ! V_8 ) {
V_97 -> V_35 |= V_152 ;
V_8 = F_133 ( V_97 , 0 , V_97 -> V_45 , 0 ) ;
* V_161 = V_97 -> V_39 ;
}
return V_8 ;
}
return F_138 ( V_97 , V_154 , V_161 ) ;
}
static void F_139 ( struct V_3 * V_68 , int V_66 ,
unsigned char * V_51 )
{
int V_131 , V_129 ;
if ( V_66 >= 0 )
V_68 -> V_66 = V_66 ;
else
V_68 -> V_66 = -- V_166 ;
V_68 -> V_51 = V_51 ;
V_68 -> V_35 |= V_52 ;
F_140 ( V_68 -> V_39 , & V_61 ) ;
V_167 += V_68 -> V_39 ;
V_129 = - 1 ;
for ( V_131 = V_63 . V_67 ; V_131 >= 0 ; V_131 = V_65 [ V_131 ] -> V_27 ) {
if ( V_68 -> V_66 >= V_65 [ V_131 ] -> V_66 )
break;
V_129 = V_131 ;
}
V_68 -> V_27 = V_131 ;
if ( V_129 < 0 )
V_63 . V_67 = V_63 . V_27 = V_68 -> type ;
else
V_65 [ V_129 ] -> V_27 = V_68 -> type ;
}
static void F_141 ( struct V_3 * V_68 , int V_66 ,
unsigned char * V_51 ,
unsigned long * V_168 )
{
F_142 ( V_68 -> type , V_168 ) ;
F_21 ( & V_60 ) ;
F_21 ( & V_68 -> V_47 ) ;
F_139 ( V_68 , V_66 , V_51 ) ;
F_20 ( & V_68 -> V_47 ) ;
F_20 ( & V_60 ) ;
}
static void F_143 ( struct V_3 * V_68 )
{
F_21 ( & V_60 ) ;
F_21 ( & V_68 -> V_47 ) ;
F_139 ( V_68 , V_68 -> V_66 , V_68 -> V_51 ) ;
F_20 ( & V_68 -> V_47 ) ;
F_20 ( & V_60 ) ;
}
static unsigned F_144 ( struct V_153 * V_153 , T_10 * V_169 )
{
struct V_170 * V_171 = V_153 -> V_172 ;
F_145 ( V_153 , & V_173 , V_169 ) ;
if ( V_171 -> V_174 != F_38 ( & V_175 ) ) {
V_171 -> V_174 = F_38 ( & V_175 ) ;
return V_176 | V_177 | V_178 | V_179 ;
}
return V_176 | V_177 ;
}
static void * F_146 ( struct V_170 * V_180 , T_11 * V_181 )
{
struct V_3 * V_4 ;
int type ;
T_11 V_182 = * V_181 ;
F_147 ( & V_183 ) ;
if ( ! V_182 )
return V_184 ;
for ( type = 0 ; type < V_70 ; type ++ ) {
F_148 () ;
V_4 = V_65 [ type ] ;
if ( ! ( V_4 -> V_35 & V_72 ) || ! V_4 -> V_51 )
continue;
if ( ! -- V_182 )
return V_4 ;
}
return NULL ;
}
static void * F_149 ( struct V_170 * V_180 , void * V_185 , T_11 * V_181 )
{
struct V_3 * V_4 = V_185 ;
int type ;
if ( V_185 == V_184 )
type = 0 ;
else
type = V_4 -> type + 1 ;
for (; type < V_70 ; type ++ ) {
F_148 () ;
V_4 = V_65 [ type ] ;
if ( ! ( V_4 -> V_35 & V_72 ) || ! V_4 -> V_51 )
continue;
++ * V_181 ;
return V_4 ;
}
return NULL ;
}
static void F_150 ( struct V_170 * V_180 , void * V_185 )
{
F_151 ( & V_183 ) ;
}
static int F_152 ( struct V_170 * V_180 , void * V_185 )
{
struct V_3 * V_4 = V_185 ;
struct V_153 * V_153 ;
int V_186 ;
if ( V_4 == V_184 ) {
F_153 ( V_180 , L_2 ) ;
return 0 ;
}
V_153 = V_4 -> V_154 ;
V_186 = F_154 ( V_180 , & V_153 -> V_187 , L_3 ) ;
F_155 ( V_180 , L_4 ,
V_186 < 40 ? 40 - V_186 : 1 , L_5 ,
F_137 ( F_156 ( V_153 ) -> V_164 ) ?
L_6 : L_7 ,
V_4 -> V_39 << ( V_16 - 10 ) ,
V_4 -> V_40 << ( V_16 - 10 ) ,
V_4 -> V_66 ) ;
return 0 ;
}
static int F_157 ( struct V_162 * V_162 , struct V_153 * V_153 )
{
struct V_170 * V_171 ;
int V_8 ;
V_8 = F_158 ( V_153 , & V_188 ) ;
if ( V_8 )
return V_8 ;
V_171 = V_153 -> V_172 ;
V_171 -> V_174 = F_38 ( & V_175 ) ;
return 0 ;
}
static int T_12 F_159 ( void )
{
F_160 ( L_8 , 0 , NULL , & V_189 ) ;
return 0 ;
}
static int T_12 F_161 ( void )
{
F_162 () ;
return 0 ;
}
static struct V_3 * F_163 ( void )
{
struct V_3 * V_68 ;
unsigned int type ;
V_68 = F_164 ( sizeof( * V_68 ) , V_19 ) ;
if ( ! V_68 )
return F_165 ( - V_109 ) ;
F_21 ( & V_60 ) ;
for ( type = 0 ; type < V_70 ; type ++ ) {
if ( ! ( V_65 [ type ] -> V_35 & V_72 ) )
break;
}
if ( type >= V_190 ) {
F_20 ( & V_60 ) ;
F_132 ( V_68 ) ;
return F_165 ( - V_191 ) ;
}
if ( type >= V_70 ) {
V_68 -> type = type ;
V_65 [ type ] = V_68 ;
F_166 () ;
V_70 ++ ;
} else {
F_132 ( V_68 ) ;
V_68 = V_65 [ type ] ;
}
F_167 ( & V_68 -> V_15 . V_26 ) ;
V_68 -> V_35 = V_72 ;
V_68 -> V_27 = - 1 ;
F_20 ( & V_60 ) ;
F_168 ( & V_68 -> V_47 ) ;
return V_68 ;
}
static int F_169 ( struct V_3 * V_68 , struct V_162 * V_162 )
{
int error ;
if ( F_137 ( V_162 -> V_164 ) ) {
V_68 -> V_18 = F_64 ( F_170 ( V_162 ) ) ;
error = F_171 ( V_68 -> V_18 ,
V_192 | V_193 | V_194 ,
V_195 ) ;
if ( error < 0 ) {
V_68 -> V_18 = NULL ;
return - V_196 ;
}
V_68 -> V_197 = F_172 ( V_68 -> V_18 ) ;
error = F_173 ( V_68 -> V_18 , V_117 ) ;
if ( error < 0 )
return error ;
V_68 -> V_35 |= V_88 ;
} else if ( F_174 ( V_162 -> V_164 ) ) {
V_68 -> V_18 = V_162 -> V_198 -> V_199 ;
F_147 ( & V_162 -> V_200 ) ;
if ( F_175 ( V_162 ) )
return - V_201 ;
} else
return - V_196 ;
return 0 ;
}
static unsigned long F_176 ( struct V_3 * V_68 ,
union V_202 * V_202 ,
struct V_162 * V_162 )
{
int V_131 ;
unsigned long V_203 ;
unsigned long V_204 ;
if ( memcmp ( L_9 , V_202 -> V_205 . V_205 , 10 ) ) {
F_36 ( V_76 L_10 ) ;
return 0 ;
}
if ( F_177 ( V_202 -> V_206 . V_207 ) == 1 ) {
F_178 ( & V_202 -> V_206 . V_207 ) ;
F_178 ( & V_202 -> V_206 . V_208 ) ;
F_178 ( & V_202 -> V_206 . V_209 ) ;
for ( V_131 = 0 ; V_131 < V_202 -> V_206 . V_209 ; V_131 ++ )
F_178 ( & V_202 -> V_206 . V_210 [ V_131 ] ) ;
}
if ( V_202 -> V_206 . V_207 != 1 ) {
F_36 ( V_211
L_11 ,
V_202 -> V_206 . V_207 ) ;
return 0 ;
}
V_68 -> V_49 = 1 ;
V_68 -> V_37 = 1 ;
V_68 -> V_38 = 0 ;
V_203 = F_35 ( F_179 (
F_74 ( F_3 ( 0 , ~ 0UL ) ) ) ) + 1 ;
if ( V_203 > V_202 -> V_206 . V_208 ) {
V_203 = V_202 -> V_206 . V_208 + 1 ;
if ( ( unsigned int ) V_203 == 0 )
V_203 = V_212 ;
}
V_68 -> V_50 = V_203 - 1 ;
if ( ! V_203 )
return 0 ;
V_204 = F_180 ( V_162 ) >> V_16 ;
if ( V_204 && V_203 > V_204 ) {
F_36 ( V_211
L_12 ) ;
return 0 ;
}
if ( V_202 -> V_206 . V_209 && F_174 ( V_162 -> V_164 ) )
return 0 ;
if ( V_202 -> V_206 . V_209 > V_213 )
return 0 ;
return V_203 ;
}
static int F_181 ( struct V_3 * V_68 ,
union V_202 * V_202 ,
unsigned char * V_51 ,
unsigned long V_203 ,
T_2 * V_161 )
{
int V_131 ;
unsigned int V_214 ;
int V_215 ;
V_214 = V_203 - 1 ;
for ( V_131 = 0 ; V_131 < V_202 -> V_206 . V_209 ; V_131 ++ ) {
unsigned int V_216 = V_202 -> V_206 . V_210 [ V_131 ] ;
if ( V_216 == 0 || V_216 > V_202 -> V_206 . V_208 )
return - V_196 ;
if ( V_216 < V_203 ) {
V_51 [ V_216 ] = V_132 ;
V_214 -- ;
}
}
if ( V_214 ) {
V_51 [ 0 ] = V_132 ;
V_68 -> V_45 = V_203 ;
V_68 -> V_39 = V_214 ;
V_215 = F_136 ( V_68 , V_161 ) ;
if ( V_215 < 0 )
return V_215 ;
V_214 = V_68 -> V_39 ;
}
if ( ! V_214 ) {
F_36 ( V_211 L_13 ) ;
return - V_196 ;
}
return V_215 ;
}
void F_182 ( struct V_217 * V_9 )
{
unsigned int type ;
unsigned long V_218 = 0 ;
F_21 ( & V_60 ) ;
for ( type = 0 ; type < V_70 ; type ++ ) {
struct V_3 * V_4 = V_65 [ type ] ;
if ( ( V_4 -> V_35 & V_72 ) && ! ( V_4 -> V_35 & V_52 ) )
V_218 += V_4 -> V_40 ;
}
V_9 -> V_219 = F_28 ( & V_61 ) + V_218 ;
V_9 -> V_220 = V_167 + V_218 ;
F_20 ( & V_60 ) ;
}
static int F_183 ( T_1 V_6 , unsigned char V_29 )
{
struct V_3 * V_68 ;
unsigned long V_5 , type ;
unsigned char V_83 ;
unsigned char V_84 ;
int V_14 = - V_196 ;
if ( F_60 ( V_6 ) )
goto V_69;
type = F_34 ( V_6 ) ;
if ( type >= V_70 )
goto V_221;
V_68 = V_65 [ type ] ;
V_5 = F_35 ( V_6 ) ;
F_21 ( & V_68 -> V_47 ) ;
if ( F_19 ( V_5 >= V_68 -> V_45 ) )
goto V_222;
V_83 = V_68 -> V_51 [ V_5 ] ;
V_84 = V_83 & V_2 ;
V_83 &= ~ V_2 ;
V_14 = 0 ;
if ( V_29 == V_2 ) {
if ( ! V_84 && V_83 )
V_84 = V_2 ;
else if ( V_84 )
V_14 = - V_223 ;
else
V_14 = - V_224 ;
} else if ( V_83 || V_84 ) {
if ( ( V_83 & ~ V_86 ) < V_87 )
V_83 += V_29 ;
else if ( ( V_83 & ~ V_86 ) > V_87 )
V_14 = - V_196 ;
else if ( F_42 ( V_68 , V_5 , V_83 ) )
V_83 = V_86 ;
else
V_14 = - V_109 ;
} else
V_14 = - V_224 ;
V_68 -> V_51 [ V_5 ] = V_83 | V_84 ;
V_222:
F_20 ( & V_68 -> V_47 ) ;
V_69:
return V_14 ;
V_221:
F_36 ( V_76 L_14 , V_80 , V_6 . V_9 ) ;
goto V_69;
}
void F_184 ( T_1 V_6 )
{
F_183 ( V_6 , V_85 ) ;
}
int F_185 ( T_1 V_6 )
{
int V_14 = 0 ;
while ( ! V_14 && F_183 ( V_6 , 1 ) == - V_109 )
V_14 = F_186 ( V_6 , V_225 ) ;
return V_14 ;
}
int F_187 ( T_1 V_6 )
{
return F_183 ( V_6 , V_2 ) ;
}
struct V_3 * F_188 ( struct V_7 * V_7 )
{
T_1 V_180 = { . V_9 = F_49 (page) } ;
F_127 ( ! F_54 ( V_7 ) ) ;
return V_65 [ F_34 ( V_180 ) ] ;
}
struct V_155 * F_189 ( struct V_7 * V_7 )
{
F_41 ( ! F_54 ( V_7 ) ) ;
return F_188 ( V_7 ) -> V_154 -> V_157 ;
}
T_3 F_190 ( struct V_7 * V_7 )
{
T_1 V_180 = { . V_9 = F_49 (page) } ;
F_41 ( ! F_54 ( V_7 ) ) ;
return F_35 ( V_180 ) ;
}
int F_186 ( T_1 V_6 , T_13 V_226 )
{
struct V_3 * V_4 ;
struct V_7 * V_67 ;
struct V_7 * V_7 ;
struct V_7 * V_227 ;
T_3 V_5 ;
unsigned char V_83 ;
V_7 = F_191 ( V_226 | V_228 ) ;
V_4 = F_33 ( V_6 ) ;
if ( ! V_4 ) {
goto V_229;
}
V_5 = F_35 ( V_6 ) ;
V_83 = V_4 -> V_51 [ V_5 ] & ~ V_2 ;
if ( ( V_83 & ~ V_86 ) != V_87 ) {
goto V_69;
}
if ( ! V_7 ) {
F_20 ( & V_4 -> V_47 ) ;
return - V_109 ;
}
V_67 = F_192 ( V_4 -> V_51 + V_5 ) ;
V_5 &= ~ V_230 ;
if ( ! F_49 ( V_67 ) ) {
F_127 ( V_83 & V_86 ) ;
F_167 ( & V_67 -> V_231 ) ;
F_193 ( V_67 , V_232 ) ;
V_4 -> V_35 |= V_232 ;
}
F_13 (list_page, &head->lru, lru) {
unsigned char * V_233 ;
if ( ! ( V_83 & V_86 ) )
goto V_69;
V_233 = F_194 ( V_227 ) + V_5 ;
V_83 = * V_233 ;
F_195 ( V_233 ) ;
if ( ( V_83 & ~ V_86 ) != V_234 )
goto V_69;
}
F_135 ( & V_7 -> V_231 , & V_67 -> V_231 ) ;
V_7 = NULL ;
V_69:
F_20 ( & V_4 -> V_47 ) ;
V_229:
if ( V_7 )
F_196 ( V_7 ) ;
return 0 ;
}
static bool F_42 ( struct V_3 * V_4 ,
T_3 V_5 , unsigned char V_83 )
{
struct V_7 * V_67 ;
struct V_7 * V_7 ;
unsigned char * V_233 ;
V_67 = F_192 ( V_4 -> V_51 + V_5 ) ;
if ( F_49 ( V_67 ) != V_232 ) {
F_127 ( V_83 & V_86 ) ;
return false ;
}
V_5 &= ~ V_230 ;
V_7 = F_15 ( V_67 -> V_231 . V_27 , struct V_7 , V_231 ) ;
V_233 = F_194 ( V_7 ) + V_5 ;
if ( V_83 == V_87 )
goto V_235;
if ( V_83 == ( V_87 | V_86 ) ) {
while ( * V_233 == ( V_234 | V_86 ) ) {
F_195 ( V_233 ) ;
V_7 = F_15 ( V_7 -> V_231 . V_27 , struct V_7 , V_231 ) ;
F_127 ( V_7 == V_67 ) ;
V_233 = F_194 ( V_7 ) + V_5 ;
}
if ( * V_233 == V_234 ) {
F_195 ( V_233 ) ;
V_7 = F_15 ( V_7 -> V_231 . V_27 , struct V_7 , V_231 ) ;
if ( V_7 == V_67 )
return false ;
V_233 = F_194 ( V_7 ) + V_5 ;
V_235: * V_233 = 0 ;
}
* V_233 += 1 ;
F_195 ( V_233 ) ;
V_7 = F_15 ( V_7 -> V_231 . V_129 , struct V_7 , V_231 ) ;
while ( V_7 != V_67 ) {
V_233 = F_194 ( V_7 ) + V_5 ;
* V_233 = V_86 ;
F_195 ( V_233 ) ;
V_7 = F_15 ( V_7 -> V_231 . V_129 , struct V_7 , V_231 ) ;
}
return true ;
} else {
F_127 ( V_83 != V_86 ) ;
while ( * V_233 == V_86 ) {
F_195 ( V_233 ) ;
V_7 = F_15 ( V_7 -> V_231 . V_27 , struct V_7 , V_231 ) ;
F_127 ( V_7 == V_67 ) ;
V_233 = F_194 ( V_7 ) + V_5 ;
}
F_127 ( * V_233 == 0 ) ;
* V_233 -= 1 ;
if ( * V_233 == 0 )
V_83 = 0 ;
F_195 ( V_233 ) ;
V_7 = F_15 ( V_7 -> V_231 . V_129 , struct V_7 , V_231 ) ;
while ( V_7 != V_67 ) {
V_233 = F_194 ( V_7 ) + V_5 ;
* V_233 = V_234 | V_83 ;
V_83 = V_86 ;
F_195 ( V_233 ) ;
V_7 = F_15 ( V_7 -> V_231 . V_129 , struct V_7 , V_231 ) ;
}
return V_83 == V_86 ;
}
}
static void F_197 ( struct V_3 * V_4 )
{
T_3 V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_45 ; V_5 += V_117 ) {
struct V_7 * V_67 ;
V_67 = F_192 ( V_4 -> V_51 + V_5 ) ;
if ( F_49 ( V_67 ) ) {
struct V_23 * V_236 , * V_27 ;
F_125 (this, next, &head->lru) {
struct V_7 * V_7 ;
V_7 = F_15 ( V_236 , struct V_7 , V_231 ) ;
F_131 ( V_236 ) ;
F_196 ( V_7 ) ;
}
}
}
}
