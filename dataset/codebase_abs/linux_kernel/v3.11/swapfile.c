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
static inline int F_69 ( T_5 V_100 , T_5 V_101 )
{
#ifdef F_70
T_5 V_102 = F_71 ( V_101 ) ;
return F_72 ( V_100 , V_101 ) || F_72 ( V_100 , V_102 ) ;
#else
return F_72 ( V_100 , V_101 ) ;
#endif
}
static int F_73 ( struct V_103 * V_104 , T_6 * V_105 ,
unsigned long V_106 , T_1 V_6 , struct V_7 * V_7 )
{
struct V_7 * V_107 ;
struct V_108 * V_109 ;
T_7 * V_110 ;
T_5 * V_100 ;
int V_8 = 1 ;
V_107 = V_7 ;
V_7 = F_74 ( V_7 , V_104 , V_106 ) ;
if ( F_19 ( ! V_7 ) )
return - V_111 ;
if ( F_75 ( V_104 -> V_112 , V_7 ,
V_19 , & V_109 ) ) {
V_8 = - V_111 ;
goto V_113;
}
V_100 = F_76 ( V_104 -> V_112 , V_105 , V_106 , & V_110 ) ;
if ( F_19 ( ! F_69 ( * V_100 , F_77 ( V_6 ) ) ) ) {
F_78 ( V_109 ) ;
V_8 = 0 ;
goto V_69;
}
F_79 ( V_104 -> V_112 , V_114 ) ;
F_80 ( V_104 -> V_112 , V_115 ) ;
F_81 ( V_7 ) ;
F_82 ( V_104 -> V_112 , V_106 , V_100 ,
F_83 ( F_84 ( V_7 , V_104 -> V_116 ) ) ) ;
if ( V_7 == V_107 )
F_85 ( V_7 , V_104 , V_106 ) ;
else
F_86 ( V_7 , V_104 , V_106 ) ;
F_87 ( V_7 , V_109 ) ;
F_45 ( V_6 ) ;
F_88 ( V_7 ) ;
V_69:
F_89 ( V_100 , V_110 ) ;
V_113:
if ( V_7 != V_107 ) {
F_8 ( V_7 ) ;
F_90 ( V_7 ) ;
}
return V_8 ;
}
static int F_91 ( struct V_103 * V_104 , T_6 * V_105 ,
unsigned long V_106 , unsigned long V_117 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_5 V_101 = F_77 ( V_6 ) ;
T_5 * V_100 ;
int V_8 = 0 ;
V_100 = F_92 ( V_105 , V_106 ) ;
do {
if ( F_19 ( F_69 ( * V_100 , V_101 ) ) ) {
F_93 ( V_100 ) ;
V_8 = F_73 ( V_104 , V_105 , V_106 , V_6 , V_7 ) ;
if ( V_8 )
goto V_69;
V_100 = F_92 ( V_105 , V_106 ) ;
}
} while ( V_100 ++ , V_106 += V_118 , V_106 != V_117 );
F_93 ( V_100 - 1 ) ;
V_69:
return V_8 ;
}
static inline int F_94 ( struct V_103 * V_104 , T_8 * V_119 ,
unsigned long V_106 , unsigned long V_117 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_6 * V_105 ;
unsigned long V_27 ;
int V_8 ;
V_105 = F_95 ( V_119 , V_106 ) ;
do {
V_27 = F_96 ( V_106 , V_117 ) ;
if ( F_97 ( V_105 ) )
continue;
V_8 = F_91 ( V_104 , V_105 , V_106 , V_27 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_105 ++ , V_106 = V_27 , V_106 != V_117 );
return 0 ;
}
static inline int F_98 ( struct V_103 * V_104 , T_9 * V_120 ,
unsigned long V_106 , unsigned long V_117 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_8 * V_119 ;
unsigned long V_27 ;
int V_8 ;
V_119 = F_99 ( V_120 , V_106 ) ;
do {
V_27 = F_100 ( V_106 , V_117 ) ;
if ( F_101 ( V_119 ) )
continue;
V_8 = F_94 ( V_104 , V_119 , V_106 , V_27 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_119 ++ , V_106 = V_27 , V_106 != V_117 );
return 0 ;
}
static int F_102 ( struct V_103 * V_104 ,
T_1 V_6 , struct V_7 * V_7 )
{
T_9 * V_120 ;
unsigned long V_106 , V_117 , V_27 ;
int V_8 ;
if ( F_103 ( V_7 ) ) {
V_106 = F_104 ( V_7 , V_104 ) ;
if ( V_106 == - V_121 )
return 0 ;
else
V_117 = V_106 + V_118 ;
} else {
V_106 = V_104 -> V_122 ;
V_117 = V_104 -> V_123 ;
}
V_120 = F_105 ( V_104 -> V_112 , V_106 ) ;
do {
V_27 = F_106 ( V_106 , V_117 ) ;
if ( F_107 ( V_120 ) )
continue;
V_8 = F_98 ( V_104 , V_120 , V_106 , V_27 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
} while ( V_120 ++ , V_106 = V_27 , V_106 != V_117 );
return 0 ;
}
static int F_108 ( struct V_124 * V_125 ,
T_1 V_6 , struct V_7 * V_7 )
{
struct V_103 * V_104 ;
int V_8 = 0 ;
if ( ! F_109 ( & V_125 -> V_126 ) ) {
F_88 ( V_7 ) ;
F_8 ( V_7 ) ;
F_110 ( & V_125 -> V_126 ) ;
F_111 ( V_7 ) ;
}
for ( V_104 = V_125 -> V_127 ; V_104 ; V_104 = V_104 -> V_128 ) {
if ( V_104 -> V_129 && ( V_8 = F_102 ( V_104 , V_6 , V_7 ) ) )
break;
}
F_112 ( & V_125 -> V_126 ) ;
return ( V_8 < 0 ) ? V_8 : 0 ;
}
static unsigned int F_113 ( struct V_3 * V_4 ,
unsigned int V_130 , bool V_131 )
{
unsigned int V_45 = V_4 -> V_45 ;
unsigned int V_132 = V_130 ;
unsigned char V_83 ;
for (; ; ) {
if ( ++ V_132 >= V_45 ) {
if ( ! V_130 ) {
V_132 = 0 ;
break;
}
V_45 = V_130 + 1 ;
V_130 = 0 ;
V_132 = 1 ;
}
if ( V_131 ) {
if ( F_114 ( V_4 , V_132 ) )
break;
else
continue;
}
V_83 = V_4 -> V_51 [ V_132 ] ;
if ( V_83 && F_1 ( V_83 ) != V_133 )
break;
}
return V_132 ;
}
int F_115 ( unsigned int type , bool V_131 ,
unsigned long V_134 )
{
struct V_3 * V_4 = V_65 [ type ] ;
struct V_124 * V_135 ;
unsigned char * V_51 ;
unsigned char V_136 ;
struct V_7 * V_7 ;
T_1 V_6 ;
unsigned int V_132 = 0 ;
int V_137 = 0 ;
V_135 = & V_138 ;
F_116 ( & V_138 . V_139 ) ;
while ( ( V_132 = F_113 ( V_4 , V_132 , V_131 ) ) != 0 ) {
if ( F_117 ( V_140 ) ) {
V_137 = - V_141 ;
break;
}
V_51 = & V_4 -> V_51 [ V_132 ] ;
V_6 = F_3 ( type , V_132 ) ;
V_7 = F_118 ( V_6 ,
V_142 , NULL , 0 ) ;
if ( ! V_7 ) {
if ( ! * V_51 )
continue;
V_137 = - V_111 ;
break;
}
if ( F_38 ( & V_135 -> V_139 ) == 1 ) {
F_119 ( V_135 ) ;
V_135 = & V_138 ;
F_116 ( & V_138 . V_139 ) ;
}
F_120 ( V_7 ) ;
F_121 ( V_7 ) ;
F_111 ( V_7 ) ;
F_121 ( V_7 ) ;
V_136 = * V_51 ;
if ( F_1 ( V_136 ) == V_85 ) {
V_137 = F_122 ( V_6 , V_7 ) ;
if ( V_137 < 0 )
break;
continue;
}
if ( F_1 ( V_136 ) && V_135 != & V_138 )
V_137 = F_108 ( V_135 , V_6 , V_7 ) ;
if ( F_1 ( * V_51 ) ) {
int V_143 = ( * V_51 >= V_136 ) ;
struct V_23 * V_68 = & V_135 -> V_144 ;
struct V_124 * V_145 = V_135 ;
struct V_124 * V_146 = V_135 ;
struct V_124 * V_125 ;
F_116 ( & V_145 -> V_139 ) ;
F_116 ( & V_146 -> V_139 ) ;
F_21 ( & V_147 ) ;
while ( F_1 ( * V_51 ) && ! V_137 &&
( V_68 = V_68 -> V_27 ) != & V_135 -> V_144 ) {
V_125 = F_15 ( V_68 , struct V_124 , V_144 ) ;
if ( ! F_123 ( & V_125 -> V_139 ) )
continue;
F_20 ( & V_147 ) ;
F_119 ( V_146 ) ;
V_146 = V_125 ;
F_12 () ;
V_136 = * V_51 ;
if ( ! F_1 ( V_136 ) )
;
else if ( V_125 == & V_138 )
V_143 = 1 ;
else
V_137 = F_108 ( V_125 , V_6 , V_7 ) ;
if ( V_143 && * V_51 < V_136 ) {
F_119 ( V_145 ) ;
F_116 ( & V_125 -> V_139 ) ;
V_145 = V_125 ;
V_143 = 0 ;
}
F_21 ( & V_147 ) ;
}
F_20 ( & V_147 ) ;
F_119 ( V_146 ) ;
F_119 ( V_135 ) ;
V_135 = V_145 ;
}
if ( V_137 ) {
F_8 ( V_7 ) ;
F_9 ( V_7 ) ;
break;
}
if ( F_1 ( * V_51 ) &&
F_124 ( V_7 ) && F_54 ( V_7 ) ) {
struct V_148 V_149 = {
. V_150 = V_151 ,
} ;
F_125 ( V_7 , & V_149 ) ;
F_111 ( V_7 ) ;
F_121 ( V_7 ) ;
}
if ( F_54 ( V_7 ) &&
F_126 ( F_49 ( V_7 ) == V_6 . V_9 ) )
F_56 ( V_7 ) ;
F_57 ( V_7 ) ;
F_8 ( V_7 ) ;
F_9 ( V_7 ) ;
F_12 () ;
if ( V_131 && V_134 > 0 ) {
if ( ! -- V_134 )
break;
}
}
F_119 ( V_135 ) ;
return V_137 ;
}
static void F_127 ( void )
{
struct V_23 * V_68 , * V_27 ;
unsigned int type ;
for ( type = 0 ; type < V_70 ; type ++ )
if ( V_65 [ type ] -> V_40 )
return;
F_21 ( & V_147 ) ;
F_128 (p, next, &init_mm.mmlist)
F_129 ( V_68 ) ;
F_20 ( & V_147 ) ;
}
static T_2 F_67 ( T_1 V_6 , struct V_95 * * V_18 )
{
struct V_3 * V_97 ;
struct V_10 * V_152 ;
struct V_10 * V_11 ;
T_3 V_5 ;
V_97 = V_65 [ F_34 ( V_6 ) ] ;
* V_18 = V_97 -> V_18 ;
V_5 = F_35 ( V_6 ) ;
V_152 = V_97 -> V_21 ;
V_11 = V_152 ;
for ( ; ; ) {
struct V_23 * V_24 ;
if ( V_11 -> V_20 <= V_5 &&
V_5 < ( V_11 -> V_20 + V_11 -> V_17 ) ) {
return V_11 -> V_12 + ( V_5 - V_11 -> V_20 ) ;
}
V_24 = V_11 -> V_26 . V_27 ;
V_11 = F_15 ( V_24 , struct V_10 , V_26 ) ;
V_97 -> V_21 = V_11 ;
F_130 ( V_11 == V_152 ) ;
}
}
T_2 F_131 ( struct V_7 * V_7 , struct V_95 * * V_18 )
{
T_1 V_6 ;
V_6 . V_9 = F_49 ( V_7 ) ;
return F_67 ( V_6 , V_18 ) ;
}
static void F_132 ( struct V_3 * V_97 )
{
while ( ! F_133 ( & V_97 -> V_15 . V_26 ) ) {
struct V_10 * V_11 ;
V_11 = F_15 ( V_97 -> V_15 . V_26 . V_27 ,
struct V_10 , V_26 ) ;
F_134 ( & V_11 -> V_26 ) ;
F_135 ( V_11 ) ;
}
if ( V_97 -> V_35 & V_153 ) {
struct V_154 * V_155 = V_97 -> V_155 ;
struct V_156 * V_157 = V_155 -> V_158 ;
V_97 -> V_35 &= ~ V_153 ;
V_157 -> V_159 -> V_160 ( V_155 ) ;
}
}
int
F_136 ( struct V_3 * V_97 , unsigned long V_20 ,
unsigned long V_17 , T_2 V_12 )
{
struct V_10 * V_11 ;
struct V_10 * V_161 ;
struct V_23 * V_24 ;
if ( V_20 == 0 ) {
V_11 = & V_97 -> V_15 ;
V_97 -> V_21 = V_11 ;
V_11 -> V_20 = 0 ;
V_11 -> V_17 = V_17 ;
V_11 -> V_12 = V_12 ;
return 1 ;
} else {
V_24 = V_97 -> V_15 . V_26 . V_130 ;
V_11 = F_15 ( V_24 , struct V_10 , V_26 ) ;
F_130 ( V_11 -> V_20 + V_11 -> V_17 != V_20 ) ;
if ( V_11 -> V_12 + V_11 -> V_17 == V_12 ) {
V_11 -> V_17 += V_17 ;
return 0 ;
}
}
V_161 = F_137 ( sizeof( * V_11 ) , V_19 ) ;
if ( V_161 == NULL )
return - V_111 ;
V_161 -> V_20 = V_20 ;
V_161 -> V_17 = V_17 ;
V_161 -> V_12 = V_12 ;
F_138 ( & V_161 -> V_26 , & V_97 -> V_15 . V_26 ) ;
return 1 ;
}
static int F_139 ( struct V_3 * V_97 , T_2 * V_162 )
{
struct V_154 * V_155 = V_97 -> V_155 ;
struct V_156 * V_157 = V_155 -> V_158 ;
struct V_163 * V_163 = V_157 -> V_164 ;
int V_8 ;
if ( F_140 ( V_163 -> V_165 ) ) {
V_8 = F_136 ( V_97 , 0 , V_97 -> V_45 , 0 ) ;
* V_162 = V_97 -> V_39 ;
return V_8 ;
}
if ( V_157 -> V_159 -> V_166 ) {
V_8 = V_157 -> V_159 -> V_166 ( V_97 , V_155 , V_162 ) ;
if ( ! V_8 ) {
V_97 -> V_35 |= V_153 ;
V_8 = F_136 ( V_97 , 0 , V_97 -> V_45 , 0 ) ;
* V_162 = V_97 -> V_39 ;
}
return V_8 ;
}
return F_141 ( V_97 , V_155 , V_162 ) ;
}
static void F_142 ( struct V_3 * V_68 , int V_66 ,
unsigned char * V_51 )
{
int V_132 , V_130 ;
if ( V_66 >= 0 )
V_68 -> V_66 = V_66 ;
else
V_68 -> V_66 = -- V_167 ;
V_68 -> V_51 = V_51 ;
V_68 -> V_35 |= V_52 ;
F_143 ( V_68 -> V_39 , & V_61 ) ;
V_168 += V_68 -> V_39 ;
V_130 = - 1 ;
for ( V_132 = V_63 . V_67 ; V_132 >= 0 ; V_132 = V_65 [ V_132 ] -> V_27 ) {
if ( V_68 -> V_66 >= V_65 [ V_132 ] -> V_66 )
break;
V_130 = V_132 ;
}
V_68 -> V_27 = V_132 ;
if ( V_130 < 0 )
V_63 . V_67 = V_63 . V_27 = V_68 -> type ;
else
V_65 [ V_130 ] -> V_27 = V_68 -> type ;
}
static void F_144 ( struct V_3 * V_68 , int V_66 ,
unsigned char * V_51 ,
unsigned long * V_169 )
{
F_145 ( V_68 -> type , V_169 ) ;
F_21 ( & V_60 ) ;
F_21 ( & V_68 -> V_47 ) ;
F_142 ( V_68 , V_66 , V_51 ) ;
F_20 ( & V_68 -> V_47 ) ;
F_20 ( & V_60 ) ;
}
static void F_146 ( struct V_3 * V_68 )
{
F_21 ( & V_60 ) ;
F_21 ( & V_68 -> V_47 ) ;
F_142 ( V_68 , V_68 -> V_66 , V_68 -> V_51 ) ;
F_20 ( & V_68 -> V_47 ) ;
F_20 ( & V_60 ) ;
}
static unsigned F_147 ( struct V_154 * V_154 , T_10 * V_170 )
{
struct V_171 * V_172 = V_154 -> V_173 ;
F_148 ( V_154 , & V_174 , V_170 ) ;
if ( V_172 -> V_175 != F_38 ( & V_176 ) ) {
V_172 -> V_175 = F_38 ( & V_176 ) ;
return V_177 | V_178 | V_179 | V_180 ;
}
return V_177 | V_178 ;
}
static void * F_149 ( struct V_171 * V_181 , T_11 * V_182 )
{
struct V_3 * V_4 ;
int type ;
T_11 V_183 = * V_182 ;
F_150 ( & V_184 ) ;
if ( ! V_183 )
return V_185 ;
for ( type = 0 ; type < V_70 ; type ++ ) {
F_151 () ;
V_4 = V_65 [ type ] ;
if ( ! ( V_4 -> V_35 & V_72 ) || ! V_4 -> V_51 )
continue;
if ( ! -- V_183 )
return V_4 ;
}
return NULL ;
}
static void * F_152 ( struct V_171 * V_181 , void * V_186 , T_11 * V_182 )
{
struct V_3 * V_4 = V_186 ;
int type ;
if ( V_186 == V_185 )
type = 0 ;
else
type = V_4 -> type + 1 ;
for (; type < V_70 ; type ++ ) {
F_151 () ;
V_4 = V_65 [ type ] ;
if ( ! ( V_4 -> V_35 & V_72 ) || ! V_4 -> V_51 )
continue;
++ * V_182 ;
return V_4 ;
}
return NULL ;
}
static void F_153 ( struct V_171 * V_181 , void * V_186 )
{
F_154 ( & V_184 ) ;
}
static int F_155 ( struct V_171 * V_181 , void * V_186 )
{
struct V_3 * V_4 = V_186 ;
struct V_154 * V_154 ;
int V_187 ;
if ( V_4 == V_185 ) {
F_156 ( V_181 , L_2 ) ;
return 0 ;
}
V_154 = V_4 -> V_155 ;
V_187 = F_157 ( V_181 , & V_154 -> V_188 , L_3 ) ;
F_158 ( V_181 , L_4 ,
V_187 < 40 ? 40 - V_187 : 1 , L_5 ,
F_140 ( F_159 ( V_154 ) -> V_165 ) ?
L_6 : L_7 ,
V_4 -> V_39 << ( V_16 - 10 ) ,
V_4 -> V_40 << ( V_16 - 10 ) ,
V_4 -> V_66 ) ;
return 0 ;
}
static int F_160 ( struct V_163 * V_163 , struct V_154 * V_154 )
{
struct V_171 * V_172 ;
int V_8 ;
V_8 = F_161 ( V_154 , & V_189 ) ;
if ( V_8 )
return V_8 ;
V_172 = V_154 -> V_173 ;
V_172 -> V_175 = F_38 ( & V_176 ) ;
return 0 ;
}
static int T_12 F_162 ( void )
{
F_163 ( L_8 , 0 , NULL , & V_190 ) ;
return 0 ;
}
static int T_12 F_164 ( void )
{
F_165 () ;
return 0 ;
}
static struct V_3 * F_166 ( void )
{
struct V_3 * V_68 ;
unsigned int type ;
V_68 = F_167 ( sizeof( * V_68 ) , V_19 ) ;
if ( ! V_68 )
return F_168 ( - V_111 ) ;
F_21 ( & V_60 ) ;
for ( type = 0 ; type < V_70 ; type ++ ) {
if ( ! ( V_65 [ type ] -> V_35 & V_72 ) )
break;
}
if ( type >= V_191 ) {
F_20 ( & V_60 ) ;
F_135 ( V_68 ) ;
return F_168 ( - V_192 ) ;
}
if ( type >= V_70 ) {
V_68 -> type = type ;
V_65 [ type ] = V_68 ;
F_169 () ;
V_70 ++ ;
} else {
F_135 ( V_68 ) ;
V_68 = V_65 [ type ] ;
}
F_170 ( & V_68 -> V_15 . V_26 ) ;
V_68 -> V_35 = V_72 ;
V_68 -> V_27 = - 1 ;
F_20 ( & V_60 ) ;
F_171 ( & V_68 -> V_47 ) ;
return V_68 ;
}
static int F_172 ( struct V_3 * V_68 , struct V_163 * V_163 )
{
int error ;
if ( F_140 ( V_163 -> V_165 ) ) {
V_68 -> V_18 = F_64 ( F_173 ( V_163 ) ) ;
error = F_174 ( V_68 -> V_18 ,
V_193 | V_194 | V_195 ,
V_196 ) ;
if ( error < 0 ) {
V_68 -> V_18 = NULL ;
return - V_197 ;
}
V_68 -> V_198 = F_175 ( V_68 -> V_18 ) ;
error = F_176 ( V_68 -> V_18 , V_118 ) ;
if ( error < 0 )
return error ;
V_68 -> V_35 |= V_88 ;
} else if ( F_177 ( V_163 -> V_165 ) ) {
V_68 -> V_18 = V_163 -> V_199 -> V_200 ;
F_150 ( & V_163 -> V_201 ) ;
if ( F_178 ( V_163 ) )
return - V_202 ;
} else
return - V_197 ;
return 0 ;
}
static unsigned long F_179 ( struct V_3 * V_68 ,
union V_203 * V_203 ,
struct V_163 * V_163 )
{
int V_132 ;
unsigned long V_204 ;
unsigned long V_205 ;
if ( memcmp ( L_9 , V_203 -> V_206 . V_206 , 10 ) ) {
F_36 ( V_76 L_10 ) ;
return 0 ;
}
if ( F_180 ( V_203 -> V_207 . V_208 ) == 1 ) {
F_181 ( & V_203 -> V_207 . V_208 ) ;
F_181 ( & V_203 -> V_207 . V_209 ) ;
F_181 ( & V_203 -> V_207 . V_210 ) ;
for ( V_132 = 0 ; V_132 < V_203 -> V_207 . V_210 ; V_132 ++ )
F_181 ( & V_203 -> V_207 . V_211 [ V_132 ] ) ;
}
if ( V_203 -> V_207 . V_208 != 1 ) {
F_36 ( V_212
L_11 ,
V_203 -> V_207 . V_208 ) ;
return 0 ;
}
V_68 -> V_49 = 1 ;
V_68 -> V_37 = 1 ;
V_68 -> V_38 = 0 ;
V_204 = F_35 ( F_182 (
F_77 ( F_3 ( 0 , ~ 0UL ) ) ) ) + 1 ;
if ( V_204 > V_203 -> V_207 . V_209 ) {
V_204 = V_203 -> V_207 . V_209 + 1 ;
if ( ( unsigned int ) V_204 == 0 )
V_204 = V_213 ;
}
V_68 -> V_50 = V_204 - 1 ;
if ( ! V_204 )
return 0 ;
V_205 = F_183 ( V_163 ) >> V_16 ;
if ( V_205 && V_204 > V_205 ) {
F_36 ( V_212
L_12 ) ;
return 0 ;
}
if ( V_203 -> V_207 . V_210 && F_177 ( V_163 -> V_165 ) )
return 0 ;
if ( V_203 -> V_207 . V_210 > V_214 )
return 0 ;
return V_204 ;
}
static int F_184 ( struct V_3 * V_68 ,
union V_203 * V_203 ,
unsigned char * V_51 ,
unsigned long V_204 ,
T_2 * V_162 )
{
int V_132 ;
unsigned int V_215 ;
int V_216 ;
V_215 = V_204 - 1 ;
for ( V_132 = 0 ; V_132 < V_203 -> V_207 . V_210 ; V_132 ++ ) {
unsigned int V_217 = V_203 -> V_207 . V_211 [ V_132 ] ;
if ( V_217 == 0 || V_217 > V_203 -> V_207 . V_209 )
return - V_197 ;
if ( V_217 < V_204 ) {
V_51 [ V_217 ] = V_133 ;
V_215 -- ;
}
}
if ( V_215 ) {
V_51 [ 0 ] = V_133 ;
V_68 -> V_45 = V_204 ;
V_68 -> V_39 = V_215 ;
V_216 = F_139 ( V_68 , V_162 ) ;
if ( V_216 < 0 )
return V_216 ;
V_215 = V_68 -> V_39 ;
}
if ( ! V_215 ) {
F_36 ( V_212 L_13 ) ;
return - V_197 ;
}
return V_216 ;
}
static bool F_185 ( struct V_3 * V_4 )
{
struct V_218 * V_219 = F_186 ( V_4 -> V_18 ) ;
if ( ! V_219 || ! F_187 ( V_219 ) )
return false ;
return true ;
}
void F_188 ( struct V_220 * V_9 )
{
unsigned int type ;
unsigned long V_221 = 0 ;
F_21 ( & V_60 ) ;
for ( type = 0 ; type < V_70 ; type ++ ) {
struct V_3 * V_4 = V_65 [ type ] ;
if ( ( V_4 -> V_35 & V_72 ) && ! ( V_4 -> V_35 & V_52 ) )
V_221 += V_4 -> V_40 ;
}
V_9 -> V_222 = F_28 ( & V_61 ) + V_221 ;
V_9 -> V_223 = V_168 + V_221 ;
F_20 ( & V_60 ) ;
}
static int F_189 ( T_1 V_6 , unsigned char V_29 )
{
struct V_3 * V_68 ;
unsigned long V_5 , type ;
unsigned char V_83 ;
unsigned char V_84 ;
int V_14 = - V_197 ;
if ( F_60 ( V_6 ) )
goto V_69;
type = F_34 ( V_6 ) ;
if ( type >= V_70 )
goto V_224;
V_68 = V_65 [ type ] ;
V_5 = F_35 ( V_6 ) ;
F_21 ( & V_68 -> V_47 ) ;
if ( F_19 ( V_5 >= V_68 -> V_45 ) )
goto V_225;
V_83 = V_68 -> V_51 [ V_5 ] ;
V_84 = V_83 & V_2 ;
V_83 &= ~ V_2 ;
V_14 = 0 ;
if ( V_29 == V_2 ) {
if ( ! V_84 && V_83 )
V_84 = V_2 ;
else if ( V_84 )
V_14 = - V_226 ;
else
V_14 = - V_227 ;
} else if ( V_83 || V_84 ) {
if ( ( V_83 & ~ V_86 ) < V_87 )
V_83 += V_29 ;
else if ( ( V_83 & ~ V_86 ) > V_87 )
V_14 = - V_197 ;
else if ( F_42 ( V_68 , V_5 , V_83 ) )
V_83 = V_86 ;
else
V_14 = - V_111 ;
} else
V_14 = - V_227 ;
V_68 -> V_51 [ V_5 ] = V_83 | V_84 ;
V_225:
F_20 ( & V_68 -> V_47 ) ;
V_69:
return V_14 ;
V_224:
F_36 ( V_76 L_14 , V_80 , V_6 . V_9 ) ;
goto V_69;
}
void F_190 ( T_1 V_6 )
{
F_189 ( V_6 , V_85 ) ;
}
int F_191 ( T_1 V_6 )
{
int V_14 = 0 ;
while ( ! V_14 && F_189 ( V_6 , 1 ) == - V_111 )
V_14 = F_192 ( V_6 , V_228 ) ;
return V_14 ;
}
int F_193 ( T_1 V_6 )
{
return F_189 ( V_6 , V_2 ) ;
}
struct V_3 * F_194 ( struct V_7 * V_7 )
{
T_1 V_181 = { . V_9 = F_49 (page) } ;
F_130 ( ! F_54 ( V_7 ) ) ;
return V_65 [ F_34 ( V_181 ) ] ;
}
struct V_156 * F_195 ( struct V_7 * V_7 )
{
F_41 ( ! F_54 ( V_7 ) ) ;
return F_194 ( V_7 ) -> V_155 -> V_158 ;
}
T_3 F_196 ( struct V_7 * V_7 )
{
T_1 V_181 = { . V_9 = F_49 (page) } ;
F_41 ( ! F_54 ( V_7 ) ) ;
return F_35 ( V_181 ) ;
}
int F_192 ( T_1 V_6 , T_13 V_229 )
{
struct V_3 * V_4 ;
struct V_7 * V_67 ;
struct V_7 * V_7 ;
struct V_7 * V_230 ;
T_3 V_5 ;
unsigned char V_83 ;
V_7 = F_197 ( V_229 | V_231 ) ;
V_4 = F_33 ( V_6 ) ;
if ( ! V_4 ) {
goto V_232;
}
V_5 = F_35 ( V_6 ) ;
V_83 = V_4 -> V_51 [ V_5 ] & ~ V_2 ;
if ( ( V_83 & ~ V_86 ) != V_87 ) {
goto V_69;
}
if ( ! V_7 ) {
F_20 ( & V_4 -> V_47 ) ;
return - V_111 ;
}
V_67 = F_198 ( V_4 -> V_51 + V_5 ) ;
V_5 &= ~ V_233 ;
if ( ! F_49 ( V_67 ) ) {
F_130 ( V_83 & V_86 ) ;
F_170 ( & V_67 -> V_234 ) ;
F_199 ( V_67 , V_235 ) ;
V_4 -> V_35 |= V_235 ;
}
F_13 (list_page, &head->lru, lru) {
unsigned char * V_236 ;
if ( ! ( V_83 & V_86 ) )
goto V_69;
V_236 = F_200 ( V_230 ) + V_5 ;
V_83 = * V_236 ;
F_201 ( V_236 ) ;
if ( ( V_83 & ~ V_86 ) != V_237 )
goto V_69;
}
F_138 ( & V_7 -> V_234 , & V_67 -> V_234 ) ;
V_7 = NULL ;
V_69:
F_20 ( & V_4 -> V_47 ) ;
V_232:
if ( V_7 )
F_202 ( V_7 ) ;
return 0 ;
}
static bool F_42 ( struct V_3 * V_4 ,
T_3 V_5 , unsigned char V_83 )
{
struct V_7 * V_67 ;
struct V_7 * V_7 ;
unsigned char * V_236 ;
V_67 = F_198 ( V_4 -> V_51 + V_5 ) ;
if ( F_49 ( V_67 ) != V_235 ) {
F_130 ( V_83 & V_86 ) ;
return false ;
}
V_5 &= ~ V_233 ;
V_7 = F_15 ( V_67 -> V_234 . V_27 , struct V_7 , V_234 ) ;
V_236 = F_200 ( V_7 ) + V_5 ;
if ( V_83 == V_87 )
goto V_238;
if ( V_83 == ( V_87 | V_86 ) ) {
while ( * V_236 == ( V_237 | V_86 ) ) {
F_201 ( V_236 ) ;
V_7 = F_15 ( V_7 -> V_234 . V_27 , struct V_7 , V_234 ) ;
F_130 ( V_7 == V_67 ) ;
V_236 = F_200 ( V_7 ) + V_5 ;
}
if ( * V_236 == V_237 ) {
F_201 ( V_236 ) ;
V_7 = F_15 ( V_7 -> V_234 . V_27 , struct V_7 , V_234 ) ;
if ( V_7 == V_67 )
return false ;
V_236 = F_200 ( V_7 ) + V_5 ;
V_238: * V_236 = 0 ;
}
* V_236 += 1 ;
F_201 ( V_236 ) ;
V_7 = F_15 ( V_7 -> V_234 . V_130 , struct V_7 , V_234 ) ;
while ( V_7 != V_67 ) {
V_236 = F_200 ( V_7 ) + V_5 ;
* V_236 = V_86 ;
F_201 ( V_236 ) ;
V_7 = F_15 ( V_7 -> V_234 . V_130 , struct V_7 , V_234 ) ;
}
return true ;
} else {
F_130 ( V_83 != V_86 ) ;
while ( * V_236 == V_86 ) {
F_201 ( V_236 ) ;
V_7 = F_15 ( V_7 -> V_234 . V_27 , struct V_7 , V_234 ) ;
F_130 ( V_7 == V_67 ) ;
V_236 = F_200 ( V_7 ) + V_5 ;
}
F_130 ( * V_236 == 0 ) ;
* V_236 -= 1 ;
if ( * V_236 == 0 )
V_83 = 0 ;
F_201 ( V_236 ) ;
V_7 = F_15 ( V_7 -> V_234 . V_130 , struct V_7 , V_234 ) ;
while ( V_7 != V_67 ) {
V_236 = F_200 ( V_7 ) + V_5 ;
* V_236 = V_237 | V_83 ;
V_83 = V_86 ;
F_201 ( V_236 ) ;
V_7 = F_15 ( V_7 -> V_234 . V_130 , struct V_7 , V_234 ) ;
}
return V_83 == V_86 ;
}
}
static void F_203 ( struct V_3 * V_4 )
{
T_3 V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_45 ; V_5 += V_118 ) {
struct V_7 * V_67 ;
V_67 = F_198 ( V_4 -> V_51 + V_5 ) ;
if ( F_49 ( V_67 ) ) {
struct V_23 * V_239 , * V_27 ;
F_128 (this, next, &head->lru) {
struct V_7 * V_7 ;
V_7 = F_15 ( V_239 , struct V_7 , V_234 ) ;
F_134 ( V_239 ) ;
F_202 ( V_7 ) ;
}
}
}
}
