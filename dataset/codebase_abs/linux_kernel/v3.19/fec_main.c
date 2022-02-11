static inline
struct V_1 * F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_1 * V_6 = V_2 + 1 ;
struct V_7 * V_8 = (struct V_7 * ) V_2 + 1 ;
struct V_9 * V_10 = V_4 -> V_11 [ V_5 ] ;
struct V_12 * V_13 = V_4 -> V_14 [ V_5 ] ;
struct V_7 * V_15 ;
struct V_1 * V_16 ;
int V_17 ;
if ( V_2 >= V_10 -> V_18 ) {
V_16 = V_10 -> V_18 ;
V_17 = V_10 -> V_19 ;
V_15 = (struct V_7 * ) V_10 -> V_18 ;
} else {
V_16 = V_13 -> V_20 ;
V_17 = V_13 -> V_21 ;
V_15 = (struct V_7 * ) V_13 -> V_20 ;
}
if ( V_4 -> V_7 )
return (struct V_1 * ) ( ( V_8 >= ( V_15 + V_17 ) ) ?
V_15 : V_8 ) ;
else
return ( V_6 >= ( V_16 + V_17 ) ) ?
V_16 : V_6 ;
}
static inline
struct V_1 * F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_1 * V_6 = V_2 - 1 ;
struct V_7 * V_8 = (struct V_7 * ) V_2 - 1 ;
struct V_9 * V_10 = V_4 -> V_11 [ V_5 ] ;
struct V_12 * V_13 = V_4 -> V_14 [ V_5 ] ;
struct V_7 * V_15 ;
struct V_1 * V_16 ;
int V_17 ;
if ( V_2 >= V_10 -> V_18 ) {
V_16 = V_10 -> V_18 ;
V_17 = V_10 -> V_19 ;
V_15 = (struct V_7 * ) V_10 -> V_18 ;
} else {
V_16 = V_13 -> V_20 ;
V_17 = V_13 -> V_21 ;
V_15 = (struct V_7 * ) V_13 -> V_20 ;
}
if ( V_4 -> V_7 )
return (struct V_1 * ) ( ( V_8 < V_15 ) ?
( V_8 + V_17 ) : V_8 ) ;
else
return ( V_6 < V_16 ) ? ( V_6 + V_17 ) : V_6 ;
}
static int F_3 ( struct V_1 * V_16 , struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return ( ( const char * ) V_2 - ( const char * ) V_16 ) / V_4 -> V_22 ;
}
static int F_4 ( struct V_3 * V_4 ,
struct V_9 * V_10 )
{
int V_23 ;
V_23 = ( ( const char * ) V_10 -> V_24 -
( const char * ) V_10 -> V_25 ) / V_4 -> V_22 - 1 ;
return V_23 > 0 ? V_23 : V_23 + V_10 -> V_19 ;
}
static void F_5 ( void * V_26 , int V_27 )
{
int V_28 ;
unsigned int * V_29 = V_26 ;
for ( V_28 = 0 ; V_28 < V_27 ; V_28 += 4 , V_29 ++ )
F_6 ( V_29 ) ;
}
static void F_7 ( void * V_30 , void * V_31 , int V_27 )
{
int V_28 ;
unsigned int * V_32 = V_31 ;
unsigned int * V_33 = V_30 ;
for ( V_28 = 0 ; V_28 < V_27 ; V_28 += 4 , V_32 ++ , V_33 ++ )
* V_33 = F_8 ( V_32 ) ;
}
static void F_9 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_36 = 0 ;
F_11 ( V_35 , L_1 ) ;
F_12 ( L_2 ) ;
V_10 = V_4 -> V_11 [ 0 ] ;
V_2 = V_10 -> V_18 ;
do {
F_12 ( L_3 ,
V_36 ,
V_2 == V_10 -> V_25 ? 'S' : ' ' ,
V_2 == V_10 -> V_24 ? 'H' : ' ' ,
V_2 -> V_37 , V_2 -> V_38 , V_2 -> V_39 ,
V_10 -> V_40 [ V_36 ] ) ;
V_2 = F_1 ( V_2 , V_4 , 0 ) ;
V_36 ++ ;
} while ( V_2 != V_10 -> V_18 );
}
static inline bool F_13 ( struct V_41 * V_42 )
{
return V_42 -> V_43 == F_14 ( V_44 ) && F_15 ( V_42 ) -> V_45 == 4 ;
}
static int
F_16 ( struct V_41 * V_42 , struct V_34 * V_35 )
{
if ( V_42 -> V_46 != V_47 )
return 0 ;
if ( F_17 ( F_18 ( V_42 , 0 ) ) )
return - 1 ;
if ( F_13 ( V_42 ) )
F_15 ( V_42 ) -> V_48 = 0 ;
* ( V_49 * ) ( V_42 -> V_50 + V_42 -> V_51 + V_42 -> V_52 ) = 0 ;
return 0 ;
}
static int
F_19 ( struct V_9 * V_10 ,
struct V_41 * V_42 ,
struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_1 * V_2 = V_10 -> V_25 ;
struct V_7 * V_53 ;
int V_54 = F_20 ( V_42 ) -> V_54 ;
unsigned short V_55 = F_21 ( V_42 ) ;
int V_56 , V_57 ;
unsigned short V_58 ;
unsigned int V_59 = 0 ;
T_1 * V_60 ;
unsigned int V_36 ;
void * V_26 ;
T_2 V_61 ;
int V_28 ;
for ( V_56 = 0 ; V_56 < V_54 ; V_56 ++ ) {
V_60 = & F_20 ( V_42 ) -> V_62 [ V_56 ] ;
V_2 = F_1 ( V_2 , V_4 , V_55 ) ;
V_53 = (struct V_7 * ) V_2 ;
V_58 = V_2 -> V_37 ;
V_58 &= ~ V_63 ;
V_58 |= ( V_64 | V_65 ) ;
V_57 = F_20 ( V_42 ) -> V_62 [ V_56 ] . V_66 ;
if ( V_56 == V_54 - 1 ) {
V_58 |= ( V_67 | V_68 ) ;
if ( V_4 -> V_7 ) {
V_59 |= V_69 ;
if ( F_17 ( F_20 ( V_42 ) -> V_70 &
V_71 && V_4 -> V_72 ) )
V_59 |= V_73 ;
}
}
if ( V_4 -> V_7 ) {
if ( V_4 -> V_74 & V_75 )
V_59 |= F_22 ( V_55 ) ;
if ( V_42 -> V_46 == V_47 )
V_59 |= V_76 | V_77 ;
V_53 -> V_78 = 0 ;
V_53 -> V_79 = V_59 ;
}
V_26 = F_23 ( V_60 -> V_80 . V_81 ) + V_60 -> V_82 ;
V_36 = F_3 ( V_10 -> V_18 , V_2 , V_4 ) ;
if ( ( ( unsigned long ) V_26 ) & V_4 -> V_83 ||
V_4 -> V_74 & V_84 ) {
memcpy ( V_10 -> V_85 [ V_36 ] , V_26 , V_57 ) ;
V_26 = V_10 -> V_85 [ V_36 ] ;
if ( V_4 -> V_74 & V_84 )
F_5 ( V_26 , V_57 ) ;
}
V_61 = F_24 ( & V_4 -> V_86 -> V_87 , V_26 , V_57 ,
V_88 ) ;
if ( F_25 ( & V_4 -> V_86 -> V_87 , V_61 ) ) {
F_26 ( V_42 ) ;
if ( F_27 () )
F_28 ( V_35 , L_4 ) ;
goto F_25;
}
V_2 -> V_38 = V_61 ;
V_2 -> V_39 = V_57 ;
V_2 -> V_37 = V_58 ;
}
V_10 -> V_25 = V_2 ;
return 0 ;
F_25:
V_2 = V_10 -> V_25 ;
for ( V_28 = 0 ; V_28 < V_56 ; V_28 ++ ) {
V_2 = F_1 ( V_2 , V_4 , V_55 ) ;
F_29 ( & V_4 -> V_86 -> V_87 , V_2 -> V_38 ,
V_2 -> V_39 , V_88 ) ;
}
return V_89 ;
}
static int F_30 ( struct V_9 * V_10 ,
struct V_41 * V_42 , struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_54 = F_20 ( V_42 ) -> V_54 ;
struct V_1 * V_2 , * V_90 ;
void * V_26 ;
T_2 V_61 ;
unsigned short V_58 ;
unsigned short V_91 ;
unsigned short V_55 ;
unsigned int V_59 = 0 ;
unsigned int V_36 ;
int V_92 ;
int V_93 ;
V_92 = F_4 ( V_4 , V_10 ) ;
if ( V_92 < V_94 + 1 ) {
F_26 ( V_42 ) ;
if ( F_27 () )
F_28 ( V_35 , L_5 ) ;
return V_89 ;
}
if ( F_16 ( V_42 , V_35 ) ) {
F_26 ( V_42 ) ;
return V_89 ;
}
V_2 = V_10 -> V_25 ;
V_58 = V_2 -> V_37 ;
V_58 &= ~ V_63 ;
V_26 = V_42 -> V_95 ;
V_91 = F_31 ( V_42 ) ;
V_55 = F_21 ( V_42 ) ;
V_36 = F_3 ( V_10 -> V_18 , V_2 , V_4 ) ;
if ( ( ( unsigned long ) V_26 ) & V_4 -> V_83 ||
V_4 -> V_74 & V_84 ) {
memcpy ( V_10 -> V_85 [ V_36 ] , V_42 -> V_95 , V_91 ) ;
V_26 = V_10 -> V_85 [ V_36 ] ;
if ( V_4 -> V_74 & V_84 )
F_5 ( V_26 , V_91 ) ;
}
V_61 = F_24 ( & V_4 -> V_86 -> V_87 , V_26 , V_91 , V_88 ) ;
if ( F_25 ( & V_4 -> V_86 -> V_87 , V_61 ) ) {
F_26 ( V_42 ) ;
if ( F_27 () )
F_28 ( V_35 , L_4 ) ;
return V_89 ;
}
if ( V_54 ) {
V_93 = F_19 ( V_10 , V_42 , V_35 ) ;
if ( V_93 )
return V_93 ;
} else {
V_58 |= ( V_67 | V_68 ) ;
if ( V_4 -> V_7 ) {
V_59 = V_69 ;
if ( F_17 ( F_20 ( V_42 ) -> V_70 &
V_71 && V_4 -> V_72 ) )
V_59 |= V_73 ;
}
}
if ( V_4 -> V_7 ) {
struct V_7 * V_53 = (struct V_7 * ) V_2 ;
if ( F_17 ( F_20 ( V_42 ) -> V_70 & V_71 &&
V_4 -> V_72 ) )
F_20 ( V_42 ) -> V_70 |= V_96 ;
if ( V_4 -> V_74 & V_75 )
V_59 |= F_22 ( V_55 ) ;
if ( V_42 -> V_46 == V_47 )
V_59 |= V_76 | V_77 ;
V_53 -> V_78 = 0 ;
V_53 -> V_79 = V_59 ;
}
V_90 = V_10 -> V_25 ;
V_36 = F_3 ( V_10 -> V_18 , V_90 , V_4 ) ;
V_10 -> V_40 [ V_36 ] = V_42 ;
V_2 -> V_39 = V_91 ;
V_2 -> V_38 = V_61 ;
V_58 |= ( V_65 | V_64 ) ;
V_2 -> V_37 = V_58 ;
V_2 = F_1 ( V_90 , V_4 , V_55 ) ;
F_32 ( V_42 ) ;
V_10 -> V_25 = V_2 ;
F_33 ( 0 , V_4 -> V_97 + F_34 ( V_55 ) ) ;
return 0 ;
}
static int
F_35 ( struct V_9 * V_10 , struct V_41 * V_42 ,
struct V_34 * V_35 ,
struct V_1 * V_2 , int V_36 , char * V_95 ,
int V_66 , bool V_98 , bool V_99 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_7 * V_53 = F_36 ( V_2 , struct V_7 , V_100 ) ;
unsigned short V_55 = F_21 ( V_42 ) ;
unsigned short V_58 ;
unsigned int V_59 = 0 ;
T_2 V_61 ;
V_58 = V_2 -> V_37 ;
V_58 &= ~ V_63 ;
V_58 |= ( V_64 | V_65 ) ;
if ( ( ( unsigned long ) V_95 ) & V_4 -> V_83 ||
V_4 -> V_74 & V_84 ) {
memcpy ( V_10 -> V_85 [ V_36 ] , V_95 , V_66 ) ;
V_95 = V_10 -> V_85 [ V_36 ] ;
if ( V_4 -> V_74 & V_84 )
F_5 ( V_95 , V_66 ) ;
}
V_61 = F_24 ( & V_4 -> V_86 -> V_87 , V_95 , V_66 , V_88 ) ;
if ( F_25 ( & V_4 -> V_86 -> V_87 , V_61 ) ) {
F_26 ( V_42 ) ;
if ( F_27 () )
F_28 ( V_35 , L_4 ) ;
return V_101 ;
}
V_2 -> V_39 = V_66 ;
V_2 -> V_38 = V_61 ;
if ( V_4 -> V_7 ) {
if ( V_4 -> V_74 & V_75 )
V_59 |= F_22 ( V_55 ) ;
if ( V_42 -> V_46 == V_47 )
V_59 |= V_76 | V_77 ;
V_53 -> V_78 = 0 ;
V_53 -> V_79 = V_59 ;
}
if ( V_98 )
V_58 |= ( V_68 | V_64 ) ;
if ( V_99 ) {
V_58 |= V_67 ;
if ( V_4 -> V_7 )
V_53 -> V_79 |= V_69 ;
}
V_2 -> V_37 = V_58 ;
return 0 ;
}
static int
F_37 ( struct V_9 * V_10 ,
struct V_41 * V_42 , struct V_34 * V_35 ,
struct V_1 * V_2 , int V_36 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_102 = F_38 ( V_42 ) + F_39 ( V_42 ) ;
struct V_7 * V_53 = F_36 ( V_2 , struct V_7 , V_100 ) ;
unsigned short V_55 = F_21 ( V_42 ) ;
void * V_26 ;
unsigned long V_103 ;
unsigned short V_58 ;
unsigned int V_59 = 0 ;
V_58 = V_2 -> V_37 ;
V_58 &= ~ V_63 ;
V_58 |= ( V_64 | V_65 ) ;
V_26 = V_10 -> V_104 + V_36 * V_105 ;
V_103 = V_10 -> V_106 + V_36 * V_105 ;
if ( ( ( unsigned long ) V_26 ) & V_4 -> V_83 ||
V_4 -> V_74 & V_84 ) {
memcpy ( V_10 -> V_85 [ V_36 ] , V_42 -> V_95 , V_102 ) ;
V_26 = V_10 -> V_85 [ V_36 ] ;
if ( V_4 -> V_74 & V_84 )
F_5 ( V_26 , V_102 ) ;
V_103 = F_24 ( & V_4 -> V_86 -> V_87 , V_26 ,
V_102 , V_88 ) ;
if ( F_25 ( & V_4 -> V_86 -> V_87 , V_103 ) ) {
F_26 ( V_42 ) ;
if ( F_27 () )
F_28 ( V_35 , L_4 ) ;
return V_101 ;
}
}
V_2 -> V_38 = V_103 ;
V_2 -> V_39 = V_102 ;
if ( V_4 -> V_7 ) {
if ( V_4 -> V_74 & V_75 )
V_59 |= F_22 ( V_55 ) ;
if ( V_42 -> V_46 == V_47 )
V_59 |= V_76 | V_77 ;
V_53 -> V_78 = 0 ;
V_53 -> V_79 = V_59 ;
}
V_2 -> V_37 = V_58 ;
return 0 ;
}
static int F_40 ( struct V_9 * V_10 ,
struct V_41 * V_42 ,
struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_102 = F_38 ( V_42 ) + F_39 ( V_42 ) ;
int V_107 , V_108 ;
struct V_1 * V_2 = V_10 -> V_25 ;
unsigned short V_55 = F_21 ( V_42 ) ;
struct V_109 V_110 ;
unsigned int V_36 = 0 ;
int V_93 ;
if ( F_41 ( V_42 ) >= F_4 ( V_4 , V_10 ) ) {
F_26 ( V_42 ) ;
if ( F_27 () )
F_28 ( V_35 , L_6 ) ;
return V_89 ;
}
if ( F_16 ( V_42 , V_35 ) ) {
F_26 ( V_42 ) ;
return V_89 ;
}
F_42 ( V_42 , & V_110 ) ;
V_107 = V_42 -> V_27 - V_102 ;
while ( V_107 > 0 ) {
char * V_111 ;
V_36 = F_3 ( V_10 -> V_18 , V_2 , V_4 ) ;
V_108 = F_43 ( int , F_20 ( V_42 ) -> V_112 , V_107 ) ;
V_107 -= V_108 ;
V_111 = V_10 -> V_104 + V_36 * V_105 ;
F_44 ( V_42 , V_111 , & V_110 , V_108 , V_107 == 0 ) ;
V_93 = F_37 ( V_10 , V_42 , V_35 , V_2 , V_36 ) ;
if ( V_93 )
goto V_113;
while ( V_108 > 0 ) {
int V_66 ;
V_66 = F_43 ( int , V_110 . V_66 , V_108 ) ;
V_2 = F_1 ( V_2 , V_4 , V_55 ) ;
V_36 = F_3 ( V_10 -> V_18 ,
V_2 , V_4 ) ;
V_93 = F_35 ( V_10 , V_42 , V_35 ,
V_2 , V_36 ,
V_110 . V_95 , V_66 ,
V_66 == V_108 ,
V_107 == 0 ) ;
if ( V_93 )
goto V_113;
V_108 -= V_66 ;
F_45 ( V_42 , & V_110 , V_66 ) ;
}
V_2 = F_1 ( V_2 , V_4 , V_55 ) ;
}
V_10 -> V_40 [ V_36 ] = V_42 ;
F_32 ( V_42 ) ;
V_10 -> V_25 = V_2 ;
if ( ! ( V_4 -> V_74 & V_114 ) ||
! F_46 ( V_4 -> V_97 + F_34 ( V_55 ) ) ||
! F_46 ( V_4 -> V_97 + F_34 ( V_55 ) ) ||
! F_46 ( V_4 -> V_97 + F_34 ( V_55 ) ) ||
! F_46 ( V_4 -> V_97 + F_34 ( V_55 ) ) )
F_33 ( 0 , V_4 -> V_97 + F_34 ( V_55 ) ) ;
return 0 ;
V_113:
return V_93 ;
}
static T_3
F_47 ( struct V_41 * V_42 , struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_92 ;
unsigned short V_55 ;
struct V_9 * V_10 ;
struct V_115 * V_116 ;
int V_93 ;
V_55 = F_21 ( V_42 ) ;
V_10 = V_4 -> V_11 [ V_55 ] ;
V_116 = F_48 ( V_35 , V_55 ) ;
if ( F_49 ( V_42 ) )
V_93 = F_40 ( V_10 , V_42 , V_35 ) ;
else
V_93 = F_30 ( V_10 , V_42 , V_35 ) ;
if ( V_93 )
return V_93 ;
V_92 = F_4 ( V_4 , V_10 ) ;
if ( V_92 <= V_10 -> V_117 )
F_50 ( V_116 ) ;
return V_89 ;
}
static void F_51 ( struct V_34 * V_87 )
{
struct V_3 * V_4 = F_10 ( V_87 ) ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
unsigned int V_28 ;
unsigned int V_118 ;
for ( V_118 = 0 ; V_118 < V_4 -> V_119 ; V_118 ++ ) {
V_13 = V_4 -> V_14 [ V_118 ] ;
V_2 = V_13 -> V_20 ;
for ( V_28 = 0 ; V_28 < V_13 -> V_21 ; V_28 ++ ) {
if ( V_2 -> V_38 )
V_2 -> V_37 = V_120 ;
else
V_2 -> V_37 = 0 ;
V_2 = F_1 ( V_2 , V_4 , V_118 ) ;
}
V_2 = F_2 ( V_2 , V_4 , V_118 ) ;
V_2 -> V_37 |= V_121 ;
V_13 -> V_122 = V_13 -> V_20 ;
}
for ( V_118 = 0 ; V_118 < V_4 -> V_123 ; V_118 ++ ) {
V_10 = V_4 -> V_11 [ V_118 ] ;
V_2 = V_10 -> V_18 ;
V_10 -> V_25 = V_2 ;
for ( V_28 = 0 ; V_28 < V_10 -> V_19 ; V_28 ++ ) {
V_2 -> V_37 = 0 ;
if ( V_10 -> V_40 [ V_28 ] ) {
F_26 ( V_10 -> V_40 [ V_28 ] ) ;
V_10 -> V_40 [ V_28 ] = NULL ;
}
V_2 -> V_38 = 0 ;
V_2 = F_1 ( V_2 , V_4 , V_118 ) ;
}
V_2 = F_2 ( V_2 , V_4 , V_118 ) ;
V_2 -> V_37 |= V_121 ;
V_10 -> V_24 = V_2 ;
}
}
static void F_52 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_119 ; V_28 ++ )
F_33 ( 0 , V_4 -> V_97 + F_53 ( V_28 ) ) ;
}
static void F_54 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_119 ; V_28 ++ ) {
V_13 = V_4 -> V_14 [ V_28 ] ;
F_33 ( V_13 -> V_124 , V_4 -> V_97 + F_55 ( V_28 ) ) ;
F_33 ( V_125 , V_4 -> V_97 + F_56 ( V_28 ) ) ;
if ( V_28 )
F_33 ( V_126 | F_57 ( V_28 ) ,
V_4 -> V_97 + F_58 ( V_28 ) ) ;
}
for ( V_28 = 0 ; V_28 < V_4 -> V_123 ; V_28 ++ ) {
V_10 = V_4 -> V_11 [ V_28 ] ;
F_33 ( V_10 -> V_124 , V_4 -> V_97 + F_59 ( V_28 ) ) ;
if ( V_28 )
F_33 ( V_127 | F_60 ( V_28 ) ,
V_4 -> V_97 + F_61 ( V_28 ) ) ;
}
}
static void F_62 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_9 * V_10 ;
int V_28 , V_128 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_123 ; V_28 ++ ) {
V_10 = V_4 -> V_11 [ V_28 ] ;
for ( V_128 = 0 ; V_128 < V_10 -> V_19 ; V_128 ++ ) {
if ( V_10 -> V_40 [ V_128 ] ) {
F_26 ( V_10 -> V_40 [ V_128 ] ) ;
V_10 -> V_40 [ V_128 ] = NULL ;
}
}
}
}
static void
F_63 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
T_4 V_129 ;
T_4 V_130 [ 2 ] ;
T_4 V_131 = V_132 | 0x04 ;
T_4 V_133 = 0x2 ;
if ( V_4 -> V_74 & V_75 ) {
F_33 ( 0 , V_4 -> V_97 + V_134 ) ;
} else {
F_33 ( 1 , V_4 -> V_97 + V_134 ) ;
F_64 ( 10 ) ;
}
if ( V_4 -> V_74 & V_135 ) {
memcpy ( & V_130 , V_35 -> V_136 , V_137 ) ;
F_33 ( F_65 ( V_130 [ 0 ] ) , V_4 -> V_97 + V_138 ) ;
F_33 ( F_65 ( V_130 [ 1 ] ) , V_4 -> V_97 + V_139 ) ;
}
F_33 ( 0xffffffff , V_4 -> V_97 + V_140 ) ;
F_51 ( V_35 ) ;
F_54 ( V_35 ) ;
F_62 ( V_35 ) ;
if ( V_4 -> V_141 == V_142 ) {
F_33 ( 0x04 , V_4 -> V_97 + V_143 ) ;
} else {
V_131 |= 0x02 ;
F_33 ( 0x0 , V_4 -> V_97 + V_143 ) ;
}
F_33 ( V_4 -> V_144 , V_4 -> V_97 + V_145 ) ;
#if ! F_66 ( V_146 )
V_129 = F_46 ( V_4 -> V_97 + V_147 ) ;
if ( V_4 -> V_148 & V_149 )
V_129 |= V_150 ;
else
V_129 &= ~ V_150 ;
F_33 ( V_129 , V_4 -> V_97 + V_147 ) ;
#endif
if ( V_4 -> V_74 & V_135 ) {
V_131 |= 0x40000000 | 0x00000020 ;
if ( V_4 -> V_151 == V_152 )
V_131 |= ( 1 << 6 ) ;
else if ( V_4 -> V_151 == V_153 )
V_131 |= ( 1 << 8 ) ;
else
V_131 &= ~ ( 1 << 8 ) ;
if ( V_4 -> V_154 ) {
if ( V_4 -> V_154 -> V_155 == V_156 )
V_133 |= ( 1 << 5 ) ;
else if ( V_4 -> V_154 -> V_155 == V_157 )
V_131 &= ~ ( 1 << 9 ) ;
else
V_131 |= ( 1 << 9 ) ;
}
} else {
#ifdef F_67
if ( V_4 -> V_74 & V_158 ) {
T_4 V_159 ;
F_33 ( 0 , V_4 -> V_97 + F_67 ) ;
while ( F_46 ( V_4 -> V_97 + F_67 ) & 4 )
F_64 ( 1 ) ;
V_159 = ( V_4 -> V_151 == V_153 )
? V_160 : V_161 ;
if ( V_4 -> V_154 && V_4 -> V_154 -> V_155 == V_162 )
V_159 |= V_163 ;
F_33 ( V_159 , V_4 -> V_97 + V_164 ) ;
F_33 ( 2 , V_4 -> V_97 + F_67 ) ;
}
#endif
}
#if ! F_66 ( V_146 )
if ( ( V_4 -> V_165 & V_166 ) ||
( ( V_4 -> V_165 & V_167 ) &&
V_4 -> V_154 && V_4 -> V_154 -> V_168 ) ) {
V_131 |= V_169 ;
F_33 ( V_170 , V_4 -> V_97 + V_171 ) ;
F_33 ( V_172 , V_4 -> V_97 + V_173 ) ;
F_33 ( V_174 , V_4 -> V_97 + V_175 ) ;
F_33 ( V_176 , V_4 -> V_97 + V_177 ) ;
F_33 ( V_178 , V_4 -> V_97 + V_179 ) ;
} else {
V_131 &= ~ V_169 ;
}
#endif
F_33 ( V_131 , V_4 -> V_97 + V_180 ) ;
F_68 ( V_35 ) ;
#ifndef V_146
F_33 ( 0 , V_4 -> V_97 + V_181 ) ;
F_33 ( 0 , V_4 -> V_97 + V_182 ) ;
#endif
if ( V_4 -> V_74 & V_135 ) {
V_133 |= ( 1 << 8 ) ;
F_33 ( 1 << 8 , V_4 -> V_97 + V_183 ) ;
}
if ( V_4 -> V_7 )
V_133 |= ( 1 << 4 ) ;
#ifndef V_146
F_33 ( 0 << 31 , V_4 -> V_97 + V_184 ) ;
#endif
F_33 ( V_133 , V_4 -> V_97 + V_134 ) ;
F_52 ( V_35 ) ;
if ( V_4 -> V_7 )
F_69 ( V_35 ) ;
if ( V_4 -> V_185 )
F_33 ( V_186 , V_4 -> V_97 + V_187 ) ;
else
F_33 ( V_188 , V_4 -> V_97 + V_187 ) ;
F_70 ( V_35 ) ;
}
static void
F_71 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
T_4 V_189 = F_46 ( V_4 -> V_97 + V_180 ) & ( 1 << 8 ) ;
if ( V_4 -> V_185 ) {
F_33 ( 1 , V_4 -> V_97 + V_143 ) ;
F_64 ( 10 ) ;
if ( ! ( F_46 ( V_4 -> V_97 + V_140 ) & V_190 ) )
F_28 ( V_35 , L_7 ) ;
}
if ( V_4 -> V_74 & V_75 ) {
F_33 ( 0 , V_4 -> V_97 + V_134 ) ;
} else {
F_33 ( 1 , V_4 -> V_97 + V_134 ) ;
F_64 ( 10 ) ;
}
F_33 ( V_4 -> V_144 , V_4 -> V_97 + V_145 ) ;
F_33 ( V_186 , V_4 -> V_97 + V_187 ) ;
if ( V_4 -> V_74 & V_135 ) {
F_33 ( 2 , V_4 -> V_97 + V_134 ) ;
F_33 ( V_189 , V_4 -> V_97 + V_180 ) ;
}
}
static void
F_72 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_9 ( V_35 ) ;
V_35 -> V_191 . V_192 ++ ;
F_73 ( & V_4 -> V_193 ) ;
}
static void F_74 ( struct V_194 * V_195 )
{
struct V_3 * V_4 =
F_36 ( V_195 , struct V_3 , V_193 ) ;
struct V_34 * V_35 = V_4 -> V_196 ;
F_75 () ;
if ( F_76 ( V_35 ) || F_77 ( V_35 ) ) {
F_78 ( & V_4 -> V_197 ) ;
F_79 ( V_35 ) ;
F_63 ( V_35 ) ;
F_80 ( V_35 ) ;
F_81 ( V_35 ) ;
F_82 ( & V_4 -> V_197 ) ;
}
F_83 () ;
}
static void
F_84 ( struct V_3 * V_4 , unsigned V_198 ,
struct V_199 * V_200 )
{
unsigned long V_201 ;
T_5 V_202 ;
F_85 ( & V_4 -> V_203 , V_201 ) ;
V_202 = F_86 ( & V_4 -> V_204 , V_198 ) ;
F_87 ( & V_4 -> V_203 , V_201 ) ;
memset ( V_200 , 0 , sizeof( * V_200 ) ) ;
V_200 -> V_205 = F_88 ( V_202 ) ;
}
static void
F_89 ( struct V_34 * V_35 , T_6 V_5 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
unsigned short V_58 ;
struct V_41 * V_42 ;
struct V_9 * V_10 ;
struct V_115 * V_116 ;
int V_36 = 0 ;
int V_92 ;
V_4 = F_10 ( V_35 ) ;
V_5 = F_90 ( V_5 ) ;
V_10 = V_4 -> V_11 [ V_5 ] ;
V_116 = F_48 ( V_35 , V_5 ) ;
V_2 = V_10 -> V_24 ;
V_2 = F_1 ( V_2 , V_4 , V_5 ) ;
while ( ( ( V_58 = V_2 -> V_37 ) & V_65 ) == 0 ) {
if ( V_2 == V_10 -> V_25 )
break;
V_36 = F_3 ( V_10 -> V_18 , V_2 , V_4 ) ;
V_42 = V_10 -> V_40 [ V_36 ] ;
V_10 -> V_40 [ V_36 ] = NULL ;
if ( ! F_91 ( V_10 , V_2 -> V_38 ) )
F_29 ( & V_4 -> V_86 -> V_87 , V_2 -> V_38 ,
V_2 -> V_39 , V_88 ) ;
V_2 -> V_38 = 0 ;
if ( ! V_42 ) {
V_2 = F_1 ( V_2 , V_4 , V_5 ) ;
continue;
}
if ( V_58 & ( V_206 | V_207 |
V_208 | V_209 |
V_210 ) ) {
V_35 -> V_191 . V_192 ++ ;
if ( V_58 & V_206 )
V_35 -> V_191 . V_211 ++ ;
if ( V_58 & V_207 )
V_35 -> V_191 . V_212 ++ ;
if ( V_58 & V_208 )
V_35 -> V_191 . V_213 ++ ;
if ( V_58 & V_209 )
V_35 -> V_191 . V_214 ++ ;
if ( V_58 & V_210 )
V_35 -> V_191 . V_215 ++ ;
} else {
V_35 -> V_191 . V_216 ++ ;
V_35 -> V_191 . V_217 += V_42 -> V_27 ;
}
if ( F_17 ( F_20 ( V_42 ) -> V_70 & V_96 ) &&
V_4 -> V_7 ) {
struct V_199 V_218 ;
struct V_7 * V_53 = (struct V_7 * ) V_2 ;
F_84 ( V_4 , V_53 -> V_198 , & V_218 ) ;
F_92 ( V_42 , & V_218 ) ;
}
if ( V_58 & V_219 )
V_35 -> V_191 . V_220 ++ ;
F_26 ( V_42 ) ;
V_10 -> V_24 = V_2 ;
V_2 = F_1 ( V_2 , V_4 , V_5 ) ;
if ( F_93 ( V_35 ) ) {
V_92 = F_4 ( V_4 , V_10 ) ;
if ( V_92 >= V_10 -> V_221 )
F_94 ( V_116 ) ;
}
}
if ( V_2 != V_10 -> V_25 &&
F_46 ( V_4 -> V_97 + F_34 ( V_5 ) ) == 0 )
F_33 ( 0 , V_4 -> V_97 + F_34 ( V_5 ) ) ;
}
static void
F_95 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
T_6 V_5 ;
F_96 (queue_id, &fep->work_tx, FEC_ENET_MAX_TX_QS) {
F_97 ( V_5 , & V_4 -> V_222 ) ;
F_89 ( V_35 , V_5 ) ;
}
return;
}
static int
F_98 ( struct V_34 * V_35 , struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_223 ;
V_223 = ( ( unsigned long ) V_42 -> V_95 ) & V_4 -> V_224 ;
if ( V_223 )
F_99 ( V_42 , V_4 -> V_224 + 1 - V_223 ) ;
V_2 -> V_38 = F_24 ( & V_4 -> V_86 -> V_87 , V_42 -> V_95 ,
V_225 - V_4 -> V_224 ,
V_226 ) ;
if ( F_25 ( & V_4 -> V_86 -> V_87 , V_2 -> V_38 ) ) {
if ( F_27 () )
F_28 ( V_35 , L_8 ) ;
return - V_227 ;
}
return 0 ;
}
static bool F_100 ( struct V_34 * V_35 , struct V_41 * * V_42 ,
struct V_1 * V_2 , T_4 V_228 , bool V_229 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_41 * V_230 ;
if ( V_228 > V_4 -> V_231 )
return false ;
V_230 = F_101 ( V_35 , V_228 ) ;
if ( ! V_230 )
return false ;
F_102 ( & V_4 -> V_86 -> V_87 , V_2 -> V_38 ,
V_225 - V_4 -> V_224 ,
V_226 ) ;
if ( ! V_229 )
memcpy ( V_230 -> V_95 , ( * V_42 ) -> V_95 , V_228 ) ;
else
F_7 ( V_230 -> V_95 , ( * V_42 ) -> V_95 , V_228 ) ;
* V_42 = V_230 ;
return true ;
}
static int
F_103 ( struct V_34 * V_35 , int V_232 , T_6 V_5 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
unsigned short V_58 ;
struct V_41 * V_233 = NULL ;
struct V_41 * V_42 ;
T_7 V_234 ;
T_8 * V_95 ;
int V_235 = 0 ;
struct V_7 * V_53 = NULL ;
bool V_236 = false ;
T_6 V_237 ;
int V_36 = 0 ;
bool V_238 ;
bool V_239 = V_4 -> V_74 & V_84 ;
#ifdef F_104
F_105 () ;
#endif
V_5 = F_90 ( V_5 ) ;
V_13 = V_4 -> V_14 [ V_5 ] ;
V_2 = V_13 -> V_122 ;
while ( ! ( ( V_58 = V_2 -> V_37 ) & V_120 ) ) {
if ( V_235 >= V_232 )
break;
V_235 ++ ;
if ( ( V_58 & V_240 ) == 0 )
F_28 ( V_35 , L_9 ) ;
if ( V_58 & ( V_241 | V_242 | V_243 |
V_244 | V_245 ) ) {
V_35 -> V_191 . V_246 ++ ;
if ( V_58 & ( V_241 | V_242 ) ) {
V_35 -> V_191 . V_247 ++ ;
}
if ( V_58 & V_243 )
V_35 -> V_191 . V_248 ++ ;
if ( V_58 & V_244 )
V_35 -> V_191 . V_249 ++ ;
if ( V_58 & V_245 )
V_35 -> V_191 . V_250 ++ ;
}
if ( V_58 & V_251 ) {
V_35 -> V_191 . V_246 ++ ;
V_35 -> V_191 . V_248 ++ ;
goto V_252;
}
V_35 -> V_191 . V_253 ++ ;
V_234 = V_2 -> V_39 ;
V_35 -> V_191 . V_254 += V_234 ;
V_36 = F_3 ( V_13 -> V_20 , V_2 , V_4 ) ;
V_42 = V_13 -> V_255 [ V_36 ] ;
V_238 = F_100 ( V_35 , & V_42 , V_2 , V_234 - 4 ,
V_239 ) ;
if ( ! V_238 ) {
V_233 = F_101 ( V_35 , V_225 ) ;
if ( F_17 ( ! V_233 ) ) {
V_35 -> V_191 . V_256 ++ ;
goto V_252;
}
F_29 ( & V_4 -> V_86 -> V_87 , V_2 -> V_38 ,
V_225 - V_4 -> V_224 ,
V_226 ) ;
}
F_106 ( V_42 -> V_95 - V_257 ) ;
F_107 ( V_42 , V_234 - 4 ) ;
V_95 = V_42 -> V_95 ;
if ( ! V_238 && V_239 )
F_5 ( V_95 , V_234 ) ;
V_53 = NULL ;
if ( V_4 -> V_7 )
V_53 = (struct V_7 * ) V_2 ;
V_236 = false ;
if ( ( V_35 -> V_258 & V_259 ) &&
V_4 -> V_7 && ( V_53 -> V_79 & V_260 ) ) {
struct V_261 * V_262 =
(struct V_261 * ) ( V_95 + V_263 ) ;
V_237 = F_108 ( V_262 -> V_264 ) ;
V_236 = true ;
F_109 ( V_42 , V_265 ,
V_95 , ( 2 * V_137 ) ) ;
F_110 ( V_42 , V_265 ) ;
}
V_42 -> V_43 = F_111 ( V_42 , V_35 ) ;
if ( V_4 -> V_266 && V_4 -> V_7 )
F_84 ( V_4 , V_53 -> V_198 ,
F_112 ( V_42 ) ) ;
if ( V_4 -> V_7 &&
( V_4 -> V_148 & V_149 ) ) {
if ( ! ( V_53 -> V_79 & V_267 ) ) {
V_42 -> V_46 = V_268 ;
} else {
F_113 ( V_42 ) ;
}
}
if ( V_236 )
F_114 ( V_42 ,
F_14 ( V_269 ) ,
V_237 ) ;
F_115 ( & V_4 -> V_197 , V_42 ) ;
if ( V_238 ) {
F_116 ( & V_4 -> V_86 -> V_87 , V_2 -> V_38 ,
V_225 - V_4 -> V_224 ,
V_226 ) ;
} else {
V_13 -> V_255 [ V_36 ] = V_233 ;
F_98 ( V_35 , V_2 , V_233 ) ;
}
V_252:
V_58 &= ~ V_270 ;
V_58 |= V_120 ;
V_2 -> V_37 = V_58 ;
if ( V_4 -> V_7 ) {
struct V_7 * V_53 = (struct V_7 * ) V_2 ;
V_53 -> V_79 = V_271 ;
V_53 -> V_272 = 0 ;
V_53 -> V_78 = 0 ;
}
V_2 = F_1 ( V_2 , V_4 , V_5 ) ;
F_33 ( 0 , V_4 -> V_97 + F_53 ( V_5 ) ) ;
}
V_13 -> V_122 = V_2 ;
return V_235 ;
}
static int
F_117 ( struct V_34 * V_35 , int V_232 )
{
int V_235 = 0 ;
T_6 V_5 ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_96 (queue_id, &fep->work_rx, FEC_ENET_MAX_RX_QS) {
F_97 ( V_5 , & V_4 -> V_273 ) ;
V_235 += F_103 ( V_35 ,
V_232 - V_235 , V_5 ) ;
}
return V_235 ;
}
static bool
F_118 ( struct V_3 * V_4 , T_9 V_274 )
{
if ( V_274 == 0 )
return false ;
if ( V_274 & V_275 )
V_4 -> V_273 |= ( 1 << 2 ) ;
if ( V_274 & V_276 )
V_4 -> V_273 |= ( 1 << 0 ) ;
if ( V_274 & V_277 )
V_4 -> V_273 |= ( 1 << 1 ) ;
if ( V_274 & V_278 )
V_4 -> V_222 |= ( 1 << 2 ) ;
if ( V_274 & V_279 )
V_4 -> V_222 |= ( 1 << 0 ) ;
if ( V_274 & V_280 )
V_4 -> V_222 |= ( 1 << 1 ) ;
return true ;
}
static T_10
F_119 ( int V_281 , void * V_282 )
{
struct V_34 * V_35 = V_282 ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
T_9 V_274 ;
T_10 V_93 = V_283 ;
V_274 = F_46 ( V_4 -> V_97 + V_140 ) ;
F_33 ( V_274 , V_4 -> V_97 + V_140 ) ;
F_118 ( V_4 , V_274 ) ;
if ( V_4 -> V_222 || V_4 -> V_273 ) {
V_93 = V_284 ;
if ( F_120 ( & V_4 -> V_197 ) ) {
F_33 ( V_188 , V_4 -> V_97 + V_187 ) ;
F_121 ( & V_4 -> V_197 ) ;
}
}
if ( V_274 & V_188 ) {
V_93 = V_284 ;
F_122 ( & V_4 -> V_285 ) ;
}
if ( V_4 -> V_286 )
F_123 ( V_4 ) ;
return V_93 ;
}
static int F_124 ( struct V_287 * V_197 , int V_232 )
{
struct V_34 * V_35 = V_197 -> V_87 ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_288 ;
V_288 = F_117 ( V_35 , V_232 ) ;
F_95 ( V_35 ) ;
if ( V_288 < V_232 ) {
F_125 ( V_197 ) ;
F_33 ( V_186 , V_4 -> V_97 + V_187 ) ;
}
return V_288 ;
}
static void F_126 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_289 * V_290 = F_127 ( & V_4 -> V_86 -> V_87 ) ;
unsigned char * V_291 , V_292 [ V_137 ] ;
V_291 = V_293 ;
if ( ! F_128 ( V_291 ) ) {
struct V_294 * V_295 = V_4 -> V_86 -> V_87 . V_296 ;
if ( V_295 ) {
const char * V_297 = F_129 ( V_295 ) ;
if ( V_297 )
V_291 = ( unsigned char * ) V_297 ;
}
}
if ( ! F_128 ( V_291 ) ) {
#ifdef V_146
if ( V_298 )
V_291 = ( unsigned char * ) V_298 ;
#else
if ( V_290 )
V_291 = ( unsigned char * ) & V_290 -> V_297 ;
#endif
}
if ( ! F_128 ( V_291 ) ) {
* ( ( V_299 * ) & V_292 [ 0 ] ) =
F_65 ( F_46 ( V_4 -> V_97 + V_138 ) ) ;
* ( ( V_300 * ) & V_292 [ 4 ] ) =
F_130 ( F_46 ( V_4 -> V_97 + V_139 ) >> 16 ) ;
V_291 = & V_292 [ 0 ] ;
}
if ( ! F_128 ( V_291 ) ) {
F_28 ( V_35 , L_10 , V_291 ) ;
F_131 ( V_35 ) ;
F_11 ( V_35 , L_11 ,
V_35 -> V_136 ) ;
return;
}
memcpy ( V_35 -> V_136 , V_291 , V_137 ) ;
if ( V_291 == V_293 )
V_35 -> V_136 [ V_137 - 1 ] = V_293 [ V_137 - 1 ] + V_4 -> V_282 ;
}
static void F_132 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_301 * V_154 = V_4 -> V_154 ;
int V_302 = 0 ;
if ( V_4 -> V_303 && V_154 -> V_304 == V_305 ) {
V_154 -> V_304 = V_306 ;
return;
}
if ( ! F_77 ( V_35 ) || ! F_76 ( V_35 ) ) {
V_4 -> V_185 = 0 ;
} else if ( V_154 -> V_185 ) {
if ( ! V_4 -> V_185 ) {
V_4 -> V_185 = V_154 -> V_185 ;
V_302 = 1 ;
}
if ( V_4 -> V_141 != V_154 -> V_307 ) {
V_4 -> V_141 = V_154 -> V_307 ;
V_302 = 1 ;
}
if ( V_154 -> V_155 != V_4 -> V_155 ) {
V_4 -> V_155 = V_154 -> V_155 ;
V_302 = 1 ;
}
if ( V_302 ) {
F_78 ( & V_4 -> V_197 ) ;
F_79 ( V_35 ) ;
F_63 ( V_35 ) ;
F_80 ( V_35 ) ;
F_81 ( V_35 ) ;
F_82 ( & V_4 -> V_197 ) ;
}
} else {
if ( V_4 -> V_185 ) {
F_78 ( & V_4 -> V_197 ) ;
F_79 ( V_35 ) ;
F_71 ( V_35 ) ;
F_81 ( V_35 ) ;
F_82 ( & V_4 -> V_197 ) ;
V_4 -> V_185 = V_154 -> V_185 ;
V_302 = 1 ;
}
}
if ( V_302 )
F_133 ( V_154 ) ;
}
static int F_134 ( struct V_308 * V_309 , int V_310 , int V_311 )
{
struct V_3 * V_4 = V_309 -> V_312 ;
unsigned long V_313 ;
V_4 -> V_303 = 0 ;
F_135 ( & V_4 -> V_285 ) ;
F_33 ( V_314 | V_315 |
F_136 ( V_310 ) | F_137 ( V_311 ) |
V_316 , V_4 -> V_97 + V_317 ) ;
V_313 = F_138 ( & V_4 -> V_285 ,
F_139 ( V_318 ) ) ;
if ( V_313 == 0 ) {
V_4 -> V_303 = 1 ;
F_28 ( V_4 -> V_196 , L_12 ) ;
return - V_319 ;
}
return F_140 ( F_46 ( V_4 -> V_97 + V_317 ) ) ;
}
static int F_141 ( struct V_308 * V_309 , int V_310 , int V_311 ,
T_6 V_320 )
{
struct V_3 * V_4 = V_309 -> V_312 ;
unsigned long V_313 ;
V_4 -> V_303 = 0 ;
F_135 ( & V_4 -> V_285 ) ;
F_33 ( V_314 | V_321 |
F_136 ( V_310 ) | F_137 ( V_311 ) |
V_316 | F_140 ( V_320 ) ,
V_4 -> V_97 + V_317 ) ;
V_313 = F_138 ( & V_4 -> V_285 ,
F_139 ( V_318 ) ) ;
if ( V_313 == 0 ) {
V_4 -> V_303 = 1 ;
F_28 ( V_4 -> V_196 , L_13 ) ;
return - V_319 ;
}
return 0 ;
}
static int F_142 ( struct V_34 * V_35 , bool V_322 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_93 ;
if ( V_322 ) {
V_93 = F_143 ( V_4 -> V_323 ) ;
if ( V_93 )
return V_93 ;
V_93 = F_143 ( V_4 -> V_324 ) ;
if ( V_93 )
goto V_325;
if ( V_4 -> V_326 ) {
V_93 = F_143 ( V_4 -> V_326 ) ;
if ( V_93 )
goto V_327;
}
if ( V_4 -> V_328 ) {
F_144 ( & V_4 -> V_329 ) ;
V_93 = F_143 ( V_4 -> V_328 ) ;
if ( V_93 ) {
F_145 ( & V_4 -> V_329 ) ;
goto V_330;
} else {
V_4 -> V_331 = true ;
}
F_145 ( & V_4 -> V_329 ) ;
}
if ( V_4 -> V_332 ) {
V_93 = F_143 ( V_4 -> V_332 ) ;
if ( V_93 )
goto V_333;
}
} else {
F_146 ( V_4 -> V_323 ) ;
F_146 ( V_4 -> V_324 ) ;
if ( V_4 -> V_326 )
F_146 ( V_4 -> V_326 ) ;
if ( V_4 -> V_328 ) {
F_144 ( & V_4 -> V_329 ) ;
F_146 ( V_4 -> V_328 ) ;
V_4 -> V_331 = false ;
F_145 ( & V_4 -> V_329 ) ;
}
if ( V_4 -> V_332 )
F_146 ( V_4 -> V_332 ) ;
}
return 0 ;
V_333:
if ( V_4 -> V_332 )
F_146 ( V_4 -> V_332 ) ;
V_330:
if ( V_4 -> V_326 )
F_146 ( V_4 -> V_326 ) ;
V_327:
F_146 ( V_4 -> V_324 ) ;
V_325:
F_146 ( V_4 -> V_323 ) ;
return V_93 ;
}
static int F_147 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_301 * V_154 = NULL ;
char V_334 [ V_335 ] ;
char V_336 [ V_335 + 3 ] ;
int V_337 ;
int V_282 = V_4 -> V_282 ;
V_4 -> V_154 = NULL ;
if ( V_4 -> V_338 ) {
V_154 = F_148 ( V_35 , V_4 -> V_338 ,
& F_132 , 0 ,
V_4 -> V_151 ) ;
if ( ! V_154 )
return - V_339 ;
} else {
for ( V_337 = 0 ; ( V_337 < V_340 ) ; V_337 ++ ) {
if ( ( V_4 -> V_308 -> V_341 & ( 1 << V_337 ) ) )
continue;
if ( V_4 -> V_308 -> V_342 [ V_337 ] == NULL )
continue;
if ( V_4 -> V_308 -> V_342 [ V_337 ] -> V_337 == 0 )
continue;
if ( V_282 -- )
continue;
F_149 ( V_334 , V_4 -> V_308 -> V_343 , V_335 ) ;
break;
}
if ( V_337 >= V_340 ) {
F_11 ( V_35 , L_14 ) ;
F_149 ( V_334 , L_15 , V_335 ) ;
V_337 = 0 ;
}
snprintf ( V_336 , sizeof( V_336 ) ,
V_344 , V_334 , V_337 ) ;
V_154 = F_150 ( V_35 , V_336 , & F_132 ,
V_4 -> V_151 ) ;
}
if ( F_151 ( V_154 ) ) {
F_28 ( V_35 , L_16 ) ;
return F_152 ( V_154 ) ;
}
if ( V_4 -> V_74 & V_345 ) {
V_154 -> V_346 &= V_347 ;
V_154 -> V_346 &= ~ V_348 ;
#if ! F_66 ( V_146 )
V_154 -> V_346 |= V_349 ;
#endif
}
else
V_154 -> V_346 &= V_350 ;
V_154 -> V_351 = V_154 -> V_346 ;
V_4 -> V_154 = V_154 ;
V_4 -> V_185 = 0 ;
V_4 -> V_141 = 0 ;
F_11 ( V_35 , L_17 ,
V_4 -> V_154 -> V_352 -> V_353 , F_153 ( & V_4 -> V_154 -> V_87 ) ,
V_4 -> V_154 -> V_281 ) ;
return 0 ;
}
static int F_154 ( struct V_354 * V_86 )
{
static struct V_308 * V_355 ;
struct V_34 * V_35 = F_155 ( V_86 ) ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_294 * V_356 ;
int V_357 = - V_358 , V_28 ;
if ( ( V_4 -> V_74 & V_359 ) && V_4 -> V_282 > 0 ) {
if ( V_360 && V_355 ) {
V_4 -> V_308 = V_355 ;
V_360 ++ ;
return 0 ;
}
return - V_361 ;
}
V_4 -> V_303 = 0 ;
V_4 -> V_144 = F_156 ( F_157 ( V_4 -> V_324 ) , 5000000 ) ;
if ( V_4 -> V_74 & V_135 )
V_4 -> V_144 -- ;
V_4 -> V_144 <<= 1 ;
F_33 ( V_4 -> V_144 , V_4 -> V_97 + V_145 ) ;
V_4 -> V_308 = F_158 () ;
if ( V_4 -> V_308 == NULL ) {
V_357 = - V_227 ;
goto V_362;
}
V_4 -> V_308 -> V_353 = L_18 ;
V_4 -> V_308 -> V_363 = F_134 ;
V_4 -> V_308 -> V_364 = F_141 ;
snprintf ( V_4 -> V_308 -> V_343 , V_335 , L_19 ,
V_86 -> V_353 , V_4 -> V_282 + 1 ) ;
V_4 -> V_308 -> V_312 = V_4 ;
V_4 -> V_308 -> V_365 = & V_86 -> V_87 ;
V_4 -> V_308 -> V_281 = F_159 ( sizeof( int ) * V_340 , V_366 ) ;
if ( ! V_4 -> V_308 -> V_281 ) {
V_357 = - V_227 ;
goto V_367;
}
for ( V_28 = 0 ; V_28 < V_340 ; V_28 ++ )
V_4 -> V_308 -> V_281 [ V_28 ] = V_368 ;
V_356 = F_160 ( V_86 -> V_87 . V_296 , L_20 ) ;
if ( V_356 ) {
V_357 = F_161 ( V_4 -> V_308 , V_356 ) ;
F_162 ( V_356 ) ;
} else {
V_357 = F_163 ( V_4 -> V_308 ) ;
}
if ( V_357 )
goto V_369;
V_360 ++ ;
if ( V_4 -> V_74 & V_359 )
V_355 = V_4 -> V_308 ;
return 0 ;
V_369:
F_164 ( V_4 -> V_308 -> V_281 ) ;
V_367:
F_165 ( V_4 -> V_308 ) ;
V_362:
return V_357 ;
}
static void F_166 ( struct V_3 * V_4 )
{
if ( -- V_360 == 0 ) {
F_167 ( V_4 -> V_308 ) ;
F_164 ( V_4 -> V_308 -> V_281 ) ;
F_165 ( V_4 -> V_308 ) ;
}
}
static int F_168 ( struct V_34 * V_35 ,
struct V_370 * V_371 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_301 * V_372 = V_4 -> V_154 ;
if ( ! V_372 )
return - V_339 ;
return F_169 ( V_372 , V_371 ) ;
}
static int F_170 ( struct V_34 * V_35 ,
struct V_370 * V_371 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_301 * V_372 = V_4 -> V_154 ;
if ( ! V_372 )
return - V_339 ;
return F_171 ( V_372 , V_371 ) ;
}
static void F_172 ( struct V_34 * V_35 ,
struct V_373 * V_374 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_149 ( V_374 -> V_375 , V_4 -> V_86 -> V_87 . V_375 -> V_353 ,
sizeof( V_374 -> V_375 ) ) ;
F_149 ( V_374 -> V_45 , L_21 , sizeof( V_374 -> V_45 ) ) ;
F_149 ( V_374 -> V_376 , F_153 ( & V_35 -> V_87 ) , sizeof( V_374 -> V_376 ) ) ;
}
static int F_173 ( struct V_34 * V_35 ,
struct V_377 * V_374 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
if ( V_4 -> V_7 ) {
V_374 -> V_378 = V_379 |
V_380 |
V_381 |
V_382 |
V_383 |
V_384 ;
if ( V_4 -> V_286 )
V_374 -> V_385 = F_174 ( V_4 -> V_286 ) ;
else
V_374 -> V_385 = - 1 ;
V_374 -> V_386 = ( 1 << V_387 ) |
( 1 << V_388 ) ;
V_374 -> V_389 = ( 1 << V_390 ) |
( 1 << V_391 ) ;
return 0 ;
} else {
return F_175 ( V_35 , V_374 ) ;
}
}
static void F_176 ( struct V_34 * V_35 ,
struct V_392 * V_168 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
V_168 -> V_393 = ( V_4 -> V_165 & V_167 ) != 0 ;
V_168 -> V_394 = ( V_4 -> V_165 & V_166 ) != 0 ;
V_168 -> V_395 = V_168 -> V_394 ;
}
static int F_177 ( struct V_34 * V_35 ,
struct V_392 * V_168 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
if ( ! V_4 -> V_154 )
return - V_339 ;
if ( V_168 -> V_394 != V_168 -> V_395 ) {
F_11 ( V_35 ,
L_22 ) ;
return - V_396 ;
}
V_4 -> V_165 = 0 ;
V_4 -> V_165 |= V_168 -> V_395 ? V_166 : 0 ;
V_4 -> V_165 |= V_168 -> V_393 ? V_167 : 0 ;
if ( V_168 -> V_395 || V_168 -> V_393 ) {
V_4 -> V_154 -> V_346 |= V_397 ;
V_4 -> V_154 -> V_351 |= V_397 ;
} else {
V_4 -> V_154 -> V_346 &= ~ V_397 ;
V_4 -> V_154 -> V_351 &= ~ V_397 ;
}
if ( V_168 -> V_393 ) {
if ( F_77 ( V_35 ) )
F_71 ( V_35 ) ;
F_178 ( V_4 -> V_154 ) ;
}
if ( F_77 ( V_35 ) ) {
F_78 ( & V_4 -> V_197 ) ;
F_79 ( V_35 ) ;
F_63 ( V_35 ) ;
F_80 ( V_35 ) ;
F_81 ( V_35 ) ;
F_82 ( & V_4 -> V_197 ) ;
}
return 0 ;
}
static void F_179 ( struct V_34 * V_87 ,
struct V_398 * V_191 , T_5 * V_95 )
{
struct V_3 * V_4 = F_10 ( V_87 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < F_180 ( V_399 ) ; V_28 ++ )
V_95 [ V_28 ] = F_46 ( V_4 -> V_97 + V_399 [ V_28 ] . V_400 ) ;
}
static void F_181 ( struct V_34 * V_196 ,
T_4 V_401 , T_11 * V_95 )
{
int V_28 ;
switch ( V_401 ) {
case V_402 :
for ( V_28 = 0 ; V_28 < F_180 ( V_399 ) ; V_28 ++ )
memcpy ( V_95 + V_28 * V_403 ,
V_399 [ V_28 ] . V_353 , V_403 ) ;
break;
}
}
static int F_182 ( struct V_34 * V_87 , int V_404 )
{
switch ( V_404 ) {
case V_402 :
return F_180 ( V_399 ) ;
default:
return - V_405 ;
}
}
static int F_183 ( struct V_34 * V_87 )
{
struct V_3 * V_4 = F_10 ( V_87 ) ;
struct V_301 * V_372 = V_4 -> V_154 ;
if ( ! V_372 )
return - V_339 ;
return F_184 ( V_372 ) ;
}
static int F_185 ( struct V_34 * V_35 , int V_406 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
return V_406 * ( V_4 -> V_407 / 64000 ) / 1000 ;
}
static void F_186 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_408 , V_409 ;
if ( ! ( V_4 -> V_74 & V_75 ) )
return;
if ( ! V_4 -> V_410 || ! V_4 -> V_411 ||
! V_4 -> V_412 || ! V_4 -> V_413 )
return;
V_408 = V_414 ;
V_409 = V_414 ;
V_408 |= F_187 ( V_4 -> V_411 ) ;
V_408 |= F_188 ( F_185 ( V_35 , V_4 -> V_410 ) ) ;
V_409 |= F_187 ( V_4 -> V_413 ) ;
V_409 |= F_188 ( F_185 ( V_35 , V_4 -> V_412 ) ) ;
V_408 |= V_415 ;
V_409 |= V_415 ;
F_33 ( V_409 , V_4 -> V_97 + V_416 ) ;
F_33 ( V_408 , V_4 -> V_97 + V_417 ) ;
F_33 ( V_409 , V_4 -> V_97 + V_418 ) ;
F_33 ( V_408 , V_4 -> V_97 + V_419 ) ;
F_33 ( V_409 , V_4 -> V_97 + V_420 ) ;
F_33 ( V_408 , V_4 -> V_97 + V_421 ) ;
}
static int
F_189 ( struct V_34 * V_35 , struct V_422 * V_423 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
if ( ! ( V_4 -> V_74 & V_75 ) )
return - V_405 ;
V_423 -> V_424 = V_4 -> V_410 ;
V_423 -> V_425 = V_4 -> V_411 ;
V_423 -> V_426 = V_4 -> V_412 ;
V_423 -> V_427 = V_4 -> V_413 ;
return 0 ;
}
static int
F_190 ( struct V_34 * V_35 , struct V_422 * V_423 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
unsigned int V_428 ;
if ( ! ( V_4 -> V_74 & V_75 ) )
return - V_405 ;
if ( V_423 -> V_425 > 255 ) {
F_191 ( L_23 ) ;
return - V_396 ;
}
if ( V_423 -> V_427 > 255 ) {
F_191 ( L_24 ) ;
return - V_396 ;
}
V_428 = F_185 ( V_35 , V_4 -> V_410 ) ;
if ( V_428 > 0xFFFF ) {
F_191 ( L_25 ) ;
return - V_396 ;
}
V_428 = F_185 ( V_35 , V_4 -> V_412 ) ;
if ( V_428 > 0xFFFF ) {
F_191 ( L_25 ) ;
return - V_396 ;
}
V_4 -> V_410 = V_423 -> V_424 ;
V_4 -> V_411 = V_423 -> V_425 ;
V_4 -> V_412 = V_423 -> V_426 ;
V_4 -> V_413 = V_423 -> V_427 ;
F_186 ( V_35 ) ;
return 0 ;
}
static void F_70 ( struct V_34 * V_35 )
{
struct V_422 V_423 ;
V_423 . V_424 = V_429 ;
V_423 . V_425 = V_430 ;
V_423 . V_426 = V_429 ;
V_423 . V_427 = V_430 ;
F_190 ( V_35 , & V_423 ) ;
}
static int F_192 ( struct V_34 * V_196 ,
const struct V_431 * V_432 ,
void * V_95 )
{
struct V_3 * V_4 = F_10 ( V_196 ) ;
int V_93 = 0 ;
switch ( V_432 -> V_343 ) {
case V_433 :
* ( T_4 * ) V_95 = V_4 -> V_231 ;
break;
default:
V_93 = - V_396 ;
break;
}
return V_93 ;
}
static int F_193 ( struct V_34 * V_196 ,
const struct V_431 * V_432 ,
const void * V_95 )
{
struct V_3 * V_4 = F_10 ( V_196 ) ;
int V_93 = 0 ;
switch ( V_432 -> V_343 ) {
case V_433 :
V_4 -> V_231 = * ( T_4 * ) V_95 ;
break;
default:
V_93 = - V_396 ;
break;
}
return V_93 ;
}
static int F_194 ( struct V_34 * V_35 , struct V_434 * V_435 , int V_371 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_301 * V_372 = V_4 -> V_154 ;
if ( ! F_77 ( V_35 ) )
return - V_396 ;
if ( ! V_372 )
return - V_339 ;
if ( V_4 -> V_7 ) {
if ( V_371 == V_436 )
return F_195 ( V_35 , V_435 ) ;
if ( V_371 == V_437 )
return F_196 ( V_35 , V_435 ) ;
}
return F_197 ( V_372 , V_435 , V_371 ) ;
}
static void F_198 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
unsigned int V_28 ;
struct V_41 * V_42 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
unsigned int V_118 ;
for ( V_118 = 0 ; V_118 < V_4 -> V_119 ; V_118 ++ ) {
V_13 = V_4 -> V_14 [ V_118 ] ;
V_2 = V_13 -> V_20 ;
for ( V_28 = 0 ; V_28 < V_13 -> V_21 ; V_28 ++ ) {
V_42 = V_13 -> V_255 [ V_28 ] ;
V_13 -> V_255 [ V_28 ] = NULL ;
if ( V_42 ) {
F_29 ( & V_4 -> V_86 -> V_87 ,
V_2 -> V_38 ,
V_225 - V_4 -> V_224 ,
V_226 ) ;
F_199 ( V_42 ) ;
}
V_2 = F_1 ( V_2 , V_4 , V_118 ) ;
}
}
for ( V_118 = 0 ; V_118 < V_4 -> V_123 ; V_118 ++ ) {
V_10 = V_4 -> V_11 [ V_118 ] ;
V_2 = V_10 -> V_18 ;
for ( V_28 = 0 ; V_28 < V_10 -> V_19 ; V_28 ++ ) {
F_164 ( V_10 -> V_85 [ V_28 ] ) ;
V_10 -> V_85 [ V_28 ] = NULL ;
V_42 = V_10 -> V_40 [ V_28 ] ;
V_10 -> V_40 [ V_28 ] = NULL ;
F_199 ( V_42 ) ;
}
}
}
static void F_200 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_28 ;
struct V_9 * V_10 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_123 ; V_28 ++ )
if ( V_4 -> V_11 [ V_28 ] && V_4 -> V_11 [ V_28 ] -> V_104 ) {
V_10 = V_4 -> V_11 [ V_28 ] ;
F_201 ( NULL ,
V_10 -> V_19 * V_105 ,
V_10 -> V_104 ,
V_10 -> V_106 ) ;
}
for ( V_28 = 0 ; V_28 < V_4 -> V_119 ; V_28 ++ )
if ( V_4 -> V_14 [ V_28 ] )
F_164 ( V_4 -> V_14 [ V_28 ] ) ;
for ( V_28 = 0 ; V_28 < V_4 -> V_123 ; V_28 ++ )
if ( V_4 -> V_11 [ V_28 ] )
F_164 ( V_4 -> V_11 [ V_28 ] ) ;
}
static int F_202 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_28 ;
int V_93 = 0 ;
struct V_9 * V_10 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_123 ; V_28 ++ ) {
V_10 = F_203 ( sizeof( * V_10 ) , V_366 ) ;
if ( ! V_10 ) {
V_93 = - V_227 ;
goto V_438;
}
V_4 -> V_11 [ V_28 ] = V_10 ;
V_10 -> V_19 = V_439 ;
V_4 -> V_440 += V_4 -> V_11 [ V_28 ] -> V_19 ;
V_10 -> V_117 = V_441 ;
V_10 -> V_221 =
( V_10 -> V_19 - V_10 -> V_117 ) / 2 ;
V_10 -> V_104 = F_204 ( NULL ,
V_10 -> V_19 * V_105 ,
& V_10 -> V_106 ,
V_366 ) ;
if ( ! V_10 -> V_104 ) {
V_93 = - V_227 ;
goto V_438;
}
}
for ( V_28 = 0 ; V_28 < V_4 -> V_119 ; V_28 ++ ) {
V_4 -> V_14 [ V_28 ] = F_203 ( sizeof( * V_4 -> V_14 [ V_28 ] ) ,
V_366 ) ;
if ( ! V_4 -> V_14 [ V_28 ] ) {
V_93 = - V_227 ;
goto V_438;
}
V_4 -> V_14 [ V_28 ] -> V_21 = V_442 ;
V_4 -> V_443 += V_4 -> V_14 [ V_28 ] -> V_21 ;
}
return V_93 ;
V_438:
F_200 ( V_35 ) ;
return V_93 ;
}
static int
F_205 ( struct V_34 * V_35 , unsigned int V_55 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
unsigned int V_28 ;
struct V_41 * V_42 ;
struct V_1 * V_2 ;
struct V_12 * V_13 ;
V_13 = V_4 -> V_14 [ V_55 ] ;
V_2 = V_13 -> V_20 ;
for ( V_28 = 0 ; V_28 < V_13 -> V_21 ; V_28 ++ ) {
V_42 = F_101 ( V_35 , V_225 ) ;
if ( ! V_42 )
goto V_444;
if ( F_98 ( V_35 , V_2 , V_42 ) ) {
F_199 ( V_42 ) ;
goto V_444;
}
V_13 -> V_255 [ V_28 ] = V_42 ;
V_2 -> V_37 = V_120 ;
if ( V_4 -> V_7 ) {
struct V_7 * V_53 = (struct V_7 * ) V_2 ;
V_53 -> V_79 = V_271 ;
}
V_2 = F_1 ( V_2 , V_4 , V_55 ) ;
}
V_2 = F_2 ( V_2 , V_4 , V_55 ) ;
V_2 -> V_37 |= V_121 ;
return 0 ;
V_444:
F_198 ( V_35 ) ;
return - V_227 ;
}
static int
F_206 ( struct V_34 * V_35 , unsigned int V_55 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
unsigned int V_28 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
V_10 = V_4 -> V_11 [ V_55 ] ;
V_2 = V_10 -> V_18 ;
for ( V_28 = 0 ; V_28 < V_10 -> V_19 ; V_28 ++ ) {
V_10 -> V_85 [ V_28 ] = F_159 ( V_445 , V_366 ) ;
if ( ! V_10 -> V_85 [ V_28 ] )
goto V_444;
V_2 -> V_37 = 0 ;
V_2 -> V_38 = 0 ;
if ( V_4 -> V_7 ) {
struct V_7 * V_53 = (struct V_7 * ) V_2 ;
V_53 -> V_79 = V_69 ;
}
V_2 = F_1 ( V_2 , V_4 , V_55 ) ;
}
V_2 = F_2 ( V_2 , V_4 , V_55 ) ;
V_2 -> V_37 |= V_121 ;
return 0 ;
V_444:
F_198 ( V_35 ) ;
return - V_227 ;
}
static int F_207 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_119 ; V_28 ++ )
if ( F_205 ( V_35 , V_28 ) )
return - V_227 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_123 ; V_28 ++ )
if ( F_206 ( V_35 , V_28 ) )
return - V_227 ;
return 0 ;
}
static int
F_208 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_93 ;
F_209 ( & V_4 -> V_86 -> V_87 ) ;
V_93 = F_142 ( V_35 , true ) ;
if ( V_93 )
return V_93 ;
V_93 = F_207 ( V_35 ) ;
if ( V_93 )
goto V_446;
V_93 = F_147 ( V_35 ) ;
if ( V_93 )
goto V_447;
F_63 ( V_35 ) ;
F_82 ( & V_4 -> V_197 ) ;
F_210 ( V_4 -> V_154 ) ;
F_211 ( V_35 ) ;
return 0 ;
V_447:
F_198 ( V_35 ) ;
V_446:
F_142 ( V_35 , false ) ;
F_212 ( & V_4 -> V_86 -> V_87 ) ;
return V_93 ;
}
static int
F_213 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_214 ( V_4 -> V_154 ) ;
if ( F_76 ( V_35 ) ) {
F_78 ( & V_4 -> V_197 ) ;
F_215 ( V_35 ) ;
F_71 ( V_35 ) ;
}
F_216 ( V_4 -> V_154 ) ;
V_4 -> V_154 = NULL ;
F_142 ( V_35 , false ) ;
F_212 ( & V_4 -> V_86 -> V_87 ) ;
F_198 ( V_35 ) ;
return 0 ;
}
static void F_68 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_448 * V_449 ;
unsigned int V_28 , V_450 , V_95 , V_451 , V_452 ;
unsigned char V_453 ;
if ( V_35 -> V_201 & V_454 ) {
V_452 = F_46 ( V_4 -> V_97 + V_180 ) ;
V_452 |= 0x8 ;
F_33 ( V_452 , V_4 -> V_97 + V_180 ) ;
return;
}
V_452 = F_46 ( V_4 -> V_97 + V_180 ) ;
V_452 &= ~ 0x8 ;
F_33 ( V_452 , V_4 -> V_97 + V_180 ) ;
if ( V_35 -> V_201 & V_455 ) {
F_33 ( 0xffffffff , V_4 -> V_97 + V_456 ) ;
F_33 ( 0xffffffff , V_4 -> V_97 + V_457 ) ;
return;
}
F_33 ( 0 , V_4 -> V_97 + V_456 ) ;
F_33 ( 0 , V_4 -> V_97 + V_457 ) ;
F_217 (ha, ndev) {
V_451 = 0xffffffff ;
for ( V_28 = 0 ; V_28 < V_35 -> V_458 ; V_28 ++ ) {
V_95 = V_449 -> V_61 [ V_28 ] ;
for ( V_450 = 0 ; V_450 < 8 ; V_450 ++ , V_95 >>= 1 ) {
V_451 = ( V_451 >> 1 ) ^
( ( ( V_451 ^ V_95 ) & 1 ) ? V_459 : 0 ) ;
}
}
V_453 = ( V_451 >> ( 32 - V_460 ) ) & 0x3f ;
if ( V_453 > 31 ) {
V_452 = F_46 ( V_4 -> V_97 + V_456 ) ;
V_452 |= 1 << ( V_453 - 32 ) ;
F_33 ( V_452 , V_4 -> V_97 + V_456 ) ;
} else {
V_452 = F_46 ( V_4 -> V_97 + V_457 ) ;
V_452 |= 1 << V_453 ;
F_33 ( V_452 , V_4 -> V_97 + V_457 ) ;
}
}
}
static int
F_218 ( struct V_34 * V_35 , void * V_81 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_461 * V_61 = V_81 ;
if ( V_61 ) {
if ( ! F_128 ( V_61 -> V_462 ) )
return - V_463 ;
memcpy ( V_35 -> V_136 , V_61 -> V_462 , V_35 -> V_458 ) ;
}
F_33 ( V_35 -> V_136 [ 3 ] | ( V_35 -> V_136 [ 2 ] << 8 ) |
( V_35 -> V_136 [ 1 ] << 16 ) | ( V_35 -> V_136 [ 0 ] << 24 ) ,
V_4 -> V_97 + V_138 ) ;
F_33 ( ( V_35 -> V_136 [ 5 ] << 16 ) | ( V_35 -> V_136 [ 4 ] << 24 ) ,
V_4 -> V_97 + V_139 ) ;
return 0 ;
}
static void F_219 ( struct V_34 * V_87 )
{
int V_28 ;
struct V_3 * V_4 = F_10 ( V_87 ) ;
for ( V_28 = 0 ; V_28 < V_464 ; V_28 ++ ) {
if ( V_4 -> V_281 [ V_28 ] > 0 ) {
F_220 ( V_4 -> V_281 [ V_28 ] ) ;
F_119 ( V_4 -> V_281 [ V_28 ] , V_87 ) ;
F_221 ( V_4 -> V_281 [ V_28 ] ) ;
}
}
}
static inline void F_222 ( struct V_34 * V_196 ,
T_12 V_258 )
{
struct V_3 * V_4 = F_10 ( V_196 ) ;
T_12 V_465 = V_258 ^ V_196 -> V_258 ;
V_196 -> V_258 = V_258 ;
if ( V_465 & V_466 ) {
if ( V_258 & V_466 )
V_4 -> V_148 |= V_149 ;
else
V_4 -> V_148 &= ~ V_149 ;
}
}
static int F_223 ( struct V_34 * V_196 ,
T_12 V_258 )
{
struct V_3 * V_4 = F_10 ( V_196 ) ;
T_12 V_465 = V_258 ^ V_196 -> V_258 ;
if ( F_77 ( V_196 ) && V_465 & V_467 ) {
F_78 ( & V_4 -> V_197 ) ;
F_79 ( V_196 ) ;
F_71 ( V_196 ) ;
F_222 ( V_196 , V_258 ) ;
F_63 ( V_196 ) ;
F_224 ( V_196 ) ;
F_81 ( V_196 ) ;
F_82 ( & V_4 -> V_197 ) ;
} else {
F_222 ( V_196 , V_258 ) ;
}
return 0 ;
}
static int F_225 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
struct V_1 * V_468 ;
T_2 V_124 ;
int V_469 ;
unsigned int V_28 ;
#if F_66 ( V_470 )
V_4 -> V_224 = 0xf ;
V_4 -> V_83 = 0xf ;
#else
V_4 -> V_224 = 0x3 ;
V_4 -> V_83 = 0x3 ;
#endif
F_202 ( V_35 ) ;
if ( V_4 -> V_7 )
V_4 -> V_22 = sizeof( struct V_7 ) ;
else
V_4 -> V_22 = sizeof( struct V_1 ) ;
V_469 = ( V_4 -> V_440 + V_4 -> V_443 ) *
V_4 -> V_22 ;
V_468 = F_204 ( NULL , V_469 , & V_124 ,
V_366 ) ;
if ( ! V_468 ) {
return - V_227 ;
}
memset ( V_468 , 0 , V_469 ) ;
F_126 ( V_35 ) ;
F_218 ( V_35 , NULL ) ;
for ( V_28 = 0 ; V_28 < V_4 -> V_119 ; V_28 ++ ) {
V_13 = V_4 -> V_14 [ V_28 ] ;
V_13 -> V_36 = V_28 ;
V_13 -> V_20 = (struct V_1 * ) V_468 ;
V_13 -> V_124 = V_124 ;
if ( V_4 -> V_7 ) {
V_124 += sizeof( struct V_7 ) * V_13 -> V_21 ;
V_468 = (struct V_1 * )
( ( (struct V_7 * ) V_468 ) + V_13 -> V_21 ) ;
} else {
V_124 += sizeof( struct V_1 ) * V_13 -> V_21 ;
V_468 += V_13 -> V_21 ;
}
}
for ( V_28 = 0 ; V_28 < V_4 -> V_123 ; V_28 ++ ) {
V_10 = V_4 -> V_11 [ V_28 ] ;
V_10 -> V_36 = V_28 ;
V_10 -> V_18 = (struct V_1 * ) V_468 ;
V_10 -> V_124 = V_124 ;
if ( V_4 -> V_7 ) {
V_124 += sizeof( struct V_7 ) * V_10 -> V_19 ;
V_468 = (struct V_1 * )
( ( (struct V_7 * ) V_468 ) + V_10 -> V_19 ) ;
} else {
V_124 += sizeof( struct V_1 ) * V_10 -> V_19 ;
V_468 += V_10 -> V_19 ;
}
}
V_35 -> V_471 = V_472 ;
V_35 -> V_473 = & V_474 ;
V_35 -> V_475 = & V_476 ;
F_33 ( V_477 , V_4 -> V_97 + V_187 ) ;
F_226 ( V_35 , & V_4 -> V_197 , F_124 , V_478 ) ;
if ( V_4 -> V_74 & V_479 )
V_35 -> V_258 |= V_259 ;
if ( V_4 -> V_74 & V_480 ) {
V_35 -> V_481 = V_482 ;
V_35 -> V_258 |= ( V_483 | V_484
| V_466 | V_485 | V_486 ) ;
V_4 -> V_148 |= V_149 ;
}
if ( V_4 -> V_74 & V_75 ) {
V_4 -> V_83 = 0 ;
V_4 -> V_224 = 0x3f ;
}
V_35 -> V_487 = V_35 -> V_258 ;
F_63 ( V_35 ) ;
return 0 ;
}
static void F_227 ( struct V_354 * V_86 )
{
int V_357 , V_488 ;
int V_489 = 1 ;
struct V_294 * V_295 = V_86 -> V_87 . V_296 ;
if ( ! V_295 )
return;
F_228 ( V_295 , L_26 , & V_489 ) ;
if ( V_489 > 1000 )
V_489 = 1 ;
V_488 = F_229 ( V_295 , L_27 , 0 ) ;
if ( ! F_230 ( V_488 ) )
return;
V_357 = F_231 ( & V_86 -> V_87 , V_488 ,
V_490 , L_28 ) ;
if ( V_357 ) {
F_232 ( & V_86 -> V_87 , L_29 , V_357 ) ;
return;
}
F_233 ( V_489 ) ;
F_234 ( V_488 , 1 ) ;
}
static void F_227 ( struct V_354 * V_86 )
{
}
static void
F_235 ( struct V_354 * V_86 , int * V_491 , int * V_492 )
{
struct V_294 * V_295 = V_86 -> V_87 . V_296 ;
int V_357 ;
* V_491 = * V_492 = 1 ;
if ( ! V_295 || ! F_236 ( V_295 ) )
return;
V_357 = F_228 ( V_295 , L_30 , V_491 ) ;
if ( V_357 )
* V_491 = 1 ;
V_357 = F_228 ( V_295 , L_31 , V_492 ) ;
if ( V_357 )
* V_492 = 1 ;
if ( * V_491 < 1 || * V_491 > V_493 ) {
F_237 ( & V_86 -> V_87 , L_32 ,
* V_491 ) ;
* V_491 = 1 ;
return;
}
if ( * V_492 < 1 || * V_492 > V_494 ) {
F_237 ( & V_86 -> V_87 , L_33 ,
* V_492 ) ;
* V_492 = 1 ;
return;
}
}
static int
F_238 ( struct V_354 * V_86 )
{
struct V_3 * V_4 ;
struct V_289 * V_290 ;
struct V_34 * V_35 ;
int V_28 , V_281 , V_93 = 0 ;
struct V_495 * V_496 ;
const struct V_497 * V_498 ;
static int V_282 ;
struct V_294 * V_295 = V_86 -> V_87 . V_296 , * V_338 ;
int V_499 ;
int V_500 ;
F_235 ( V_86 , & V_499 , & V_500 ) ;
V_35 = F_239 ( sizeof( struct V_3 ) ,
V_499 , V_500 ) ;
if ( ! V_35 )
return - V_227 ;
F_240 ( V_35 , & V_86 -> V_87 ) ;
V_4 = F_10 ( V_35 ) ;
V_498 = F_241 ( V_501 , & V_86 -> V_87 ) ;
if ( V_498 )
V_86 -> V_502 = V_498 -> V_95 ;
V_4 -> V_74 = V_86 -> V_502 -> V_503 ;
V_4 -> V_196 = V_35 ;
V_4 -> V_119 = V_500 ;
V_4 -> V_123 = V_499 ;
#if ! F_66 ( V_146 )
if ( V_4 -> V_74 & V_345 )
V_4 -> V_165 |= V_167 ;
#endif
F_209 ( & V_86 -> V_87 ) ;
V_496 = F_242 ( V_86 , V_504 , 0 ) ;
V_4 -> V_97 = F_243 ( & V_86 -> V_87 , V_496 ) ;
if ( F_151 ( V_4 -> V_97 ) ) {
V_93 = F_152 ( V_4 -> V_97 ) ;
goto V_505;
}
V_4 -> V_86 = V_86 ;
V_4 -> V_282 = V_282 ++ ;
F_244 ( V_86 , V_35 ) ;
V_338 = F_245 ( V_295 , L_34 , 0 ) ;
if ( ! V_338 && F_246 ( V_295 ) ) {
V_93 = F_247 ( V_295 ) ;
if ( V_93 < 0 ) {
F_232 ( & V_86 -> V_87 ,
L_35 ) ;
goto V_506;
}
V_338 = F_248 ( V_295 ) ;
}
V_4 -> V_338 = V_338 ;
V_93 = F_249 ( V_86 -> V_87 . V_296 ) ;
if ( V_93 < 0 ) {
V_290 = F_127 ( & V_86 -> V_87 ) ;
if ( V_290 )
V_4 -> V_151 = V_290 -> V_507 ;
else
V_4 -> V_151 = V_508 ;
} else {
V_4 -> V_151 = V_93 ;
}
V_4 -> V_324 = F_250 ( & V_86 -> V_87 , L_36 ) ;
if ( F_151 ( V_4 -> V_324 ) ) {
V_93 = F_152 ( V_4 -> V_324 ) ;
goto V_509;
}
V_4 -> V_323 = F_250 ( & V_86 -> V_87 , L_37 ) ;
if ( F_151 ( V_4 -> V_323 ) ) {
V_93 = F_152 ( V_4 -> V_323 ) ;
goto V_509;
}
V_4 -> V_407 = F_157 ( V_4 -> V_323 ) ;
V_4 -> V_326 = F_250 ( & V_86 -> V_87 , L_38 ) ;
if ( F_151 ( V_4 -> V_326 ) )
V_4 -> V_326 = NULL ;
V_4 -> V_331 = false ;
F_251 ( & V_4 -> V_329 ) ;
V_4 -> V_332 = F_250 ( & V_86 -> V_87 , L_39 ) ;
if ( F_151 ( V_4 -> V_332 ) )
V_4 -> V_332 = NULL ;
V_4 -> V_7 = V_4 -> V_74 & V_510 ;
V_4 -> V_328 = F_250 ( & V_86 -> V_87 , L_40 ) ;
if ( F_151 ( V_4 -> V_328 ) ) {
V_4 -> V_328 = NULL ;
V_4 -> V_7 = false ;
}
V_93 = F_142 ( V_35 , true ) ;
if ( V_93 )
goto V_509;
V_4 -> V_511 = F_252 ( & V_86 -> V_87 , L_41 ) ;
if ( ! F_151 ( V_4 -> V_511 ) ) {
V_93 = F_253 ( V_4 -> V_511 ) ;
if ( V_93 ) {
F_232 ( & V_86 -> V_87 ,
L_42 , V_93 ) ;
goto V_512;
}
} else {
V_4 -> V_511 = NULL ;
}
F_227 ( V_86 ) ;
if ( V_4 -> V_7 )
F_254 ( V_86 ) ;
V_93 = F_225 ( V_35 ) ;
if ( V_93 )
goto V_513;
for ( V_28 = 0 ; V_28 < V_464 ; V_28 ++ ) {
V_281 = F_255 ( V_86 , V_28 ) ;
if ( V_281 < 0 ) {
if ( V_28 )
break;
V_93 = V_281 ;
goto V_514;
}
V_93 = F_256 ( & V_86 -> V_87 , V_281 , F_119 ,
0 , V_86 -> V_353 , V_35 ) ;
if ( V_93 )
goto V_514;
}
F_135 ( & V_4 -> V_285 ) ;
V_93 = F_154 ( V_86 ) ;
if ( V_93 )
goto V_515;
F_257 ( V_35 ) ;
F_142 ( V_35 , false ) ;
F_212 ( & V_86 -> V_87 ) ;
V_93 = F_258 ( V_35 ) ;
if ( V_93 )
goto V_516;
if ( V_4 -> V_7 && V_4 -> V_286 )
F_11 ( V_35 , L_43 , V_4 -> V_282 ) ;
V_4 -> V_231 = V_517 ;
F_259 ( & V_4 -> V_193 , F_74 ) ;
return 0 ;
V_516:
F_166 ( V_4 ) ;
V_515:
V_514:
V_513:
if ( V_4 -> V_511 )
F_260 ( V_4 -> V_511 ) ;
V_512:
F_142 ( V_35 , false ) ;
V_509:
V_506:
F_162 ( V_338 ) ;
V_505:
F_261 ( V_35 ) ;
return V_93 ;
}
static int
F_262 ( struct V_354 * V_86 )
{
struct V_34 * V_35 = F_155 ( V_86 ) ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_263 ( & V_4 -> V_518 ) ;
F_264 ( & V_4 -> V_193 ) ;
F_265 ( V_35 ) ;
F_166 ( V_4 ) ;
if ( V_4 -> V_511 )
F_260 ( V_4 -> V_511 ) ;
if ( V_4 -> V_286 )
F_266 ( V_4 -> V_286 ) ;
F_142 ( V_35 , false ) ;
F_162 ( V_4 -> V_338 ) ;
F_261 ( V_35 ) ;
return 0 ;
}
static int T_13 F_267 ( struct V_519 * V_87 )
{
struct V_34 * V_35 = F_268 ( V_87 ) ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_75 () ;
if ( F_77 ( V_35 ) ) {
F_214 ( V_4 -> V_154 ) ;
F_78 ( & V_4 -> V_197 ) ;
F_79 ( V_35 ) ;
F_269 ( V_35 ) ;
F_81 ( V_35 ) ;
F_71 ( V_35 ) ;
F_142 ( V_35 , false ) ;
F_212 ( & V_4 -> V_86 -> V_87 ) ;
}
F_83 () ;
if ( V_4 -> V_511 )
F_260 ( V_4 -> V_511 ) ;
if ( V_4 -> V_326 || V_4 -> V_511 )
V_4 -> V_185 = 0 ;
return 0 ;
}
static int T_13 F_270 ( struct V_519 * V_87 )
{
struct V_34 * V_35 = F_268 ( V_87 ) ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_93 ;
if ( V_4 -> V_511 ) {
V_93 = F_253 ( V_4 -> V_511 ) ;
if ( V_93 )
return V_93 ;
}
F_75 () ;
if ( F_77 ( V_35 ) ) {
F_209 ( & V_4 -> V_86 -> V_87 ) ;
V_93 = F_142 ( V_35 , true ) ;
if ( V_93 ) {
F_83 () ;
goto V_509;
}
F_63 ( V_35 ) ;
F_79 ( V_35 ) ;
F_271 ( V_35 ) ;
F_81 ( V_35 ) ;
F_82 ( & V_4 -> V_197 ) ;
F_210 ( V_4 -> V_154 ) ;
}
F_83 () ;
return 0 ;
V_509:
if ( V_4 -> V_511 )
F_260 ( V_4 -> V_511 ) ;
return V_93 ;
}
