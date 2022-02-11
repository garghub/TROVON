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
struct V_189 * V_190 = V_4 -> V_86 -> V_87 . V_191 ;
T_4 V_192 = F_46 ( V_4 -> V_97 + V_180 ) & ( 1 << 8 ) ;
T_4 V_129 ;
if ( V_4 -> V_185 ) {
F_33 ( 1 , V_4 -> V_97 + V_143 ) ;
F_64 ( 10 ) ;
if ( ! ( F_46 ( V_4 -> V_97 + V_140 ) & V_193 ) )
F_28 ( V_35 , L_7 ) ;
}
if ( ! ( V_4 -> V_194 & V_195 ) ) {
if ( V_4 -> V_74 & V_75 ) {
F_33 ( 0 , V_4 -> V_97 + V_134 ) ;
} else {
F_33 ( 1 , V_4 -> V_97 + V_134 ) ;
F_64 ( 10 ) ;
}
F_33 ( V_186 , V_4 -> V_97 + V_187 ) ;
} else {
F_33 ( V_186 | V_196 , V_4 -> V_97 + V_187 ) ;
V_129 = F_46 ( V_4 -> V_97 + V_134 ) ;
V_129 |= ( V_197 | V_198 ) ;
F_33 ( V_129 , V_4 -> V_97 + V_134 ) ;
if ( V_190 && V_190 -> V_199 )
V_190 -> V_199 ( true ) ;
}
F_33 ( V_4 -> V_144 , V_4 -> V_97 + V_145 ) ;
if ( V_4 -> V_74 & V_135 &&
! ( V_4 -> V_194 & V_195 ) ) {
F_33 ( 2 , V_4 -> V_97 + V_134 ) ;
F_33 ( V_192 , V_4 -> V_97 + V_180 ) ;
}
}
static void
F_72 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_9 ( V_35 ) ;
V_35 -> V_200 . V_201 ++ ;
F_73 ( & V_4 -> V_202 ) ;
}
static void F_74 ( struct V_203 * V_204 )
{
struct V_3 * V_4 =
F_36 ( V_204 , struct V_3 , V_202 ) ;
struct V_34 * V_35 = V_4 -> V_205 ;
F_75 () ;
if ( F_76 ( V_35 ) || F_77 ( V_35 ) ) {
F_78 ( & V_4 -> V_206 ) ;
F_79 ( V_35 ) ;
F_63 ( V_35 ) ;
F_80 ( V_35 ) ;
F_81 ( V_35 ) ;
F_82 ( & V_4 -> V_206 ) ;
}
F_83 () ;
}
static void
F_84 ( struct V_3 * V_4 , unsigned V_207 ,
struct V_208 * V_209 )
{
unsigned long V_210 ;
T_5 V_211 ;
F_85 ( & V_4 -> V_212 , V_210 ) ;
V_211 = F_86 ( & V_4 -> V_213 , V_207 ) ;
F_87 ( & V_4 -> V_212 , V_210 ) ;
memset ( V_209 , 0 , sizeof( * V_209 ) ) ;
V_209 -> V_214 = F_88 ( V_211 ) ;
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
if ( V_58 & ( V_215 | V_216 |
V_217 | V_218 |
V_219 ) ) {
V_35 -> V_200 . V_201 ++ ;
if ( V_58 & V_215 )
V_35 -> V_200 . V_220 ++ ;
if ( V_58 & V_216 )
V_35 -> V_200 . V_221 ++ ;
if ( V_58 & V_217 )
V_35 -> V_200 . V_222 ++ ;
if ( V_58 & V_218 )
V_35 -> V_200 . V_223 ++ ;
if ( V_58 & V_219 )
V_35 -> V_200 . V_224 ++ ;
} else {
V_35 -> V_200 . V_225 ++ ;
V_35 -> V_200 . V_226 += V_42 -> V_27 ;
}
if ( F_17 ( F_20 ( V_42 ) -> V_70 & V_96 ) &&
V_4 -> V_7 ) {
struct V_208 V_227 ;
struct V_7 * V_53 = (struct V_7 * ) V_2 ;
F_84 ( V_4 , V_53 -> V_207 , & V_227 ) ;
F_92 ( V_42 , & V_227 ) ;
}
if ( V_58 & V_228 )
V_35 -> V_200 . V_229 ++ ;
F_26 ( V_42 ) ;
V_10 -> V_24 = V_2 ;
V_2 = F_1 ( V_2 , V_4 , V_5 ) ;
if ( F_93 ( V_35 ) ) {
V_92 = F_4 ( V_4 , V_10 ) ;
if ( V_92 >= V_10 -> V_230 )
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
F_97 ( V_5 , & V_4 -> V_231 ) ;
F_89 ( V_35 , V_5 ) ;
}
return;
}
static int
F_98 ( struct V_34 * V_35 , struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_232 ;
V_232 = ( ( unsigned long ) V_42 -> V_95 ) & V_4 -> V_233 ;
if ( V_232 )
F_99 ( V_42 , V_4 -> V_233 + 1 - V_232 ) ;
V_2 -> V_38 = F_24 ( & V_4 -> V_86 -> V_87 , V_42 -> V_95 ,
V_234 - V_4 -> V_233 ,
V_235 ) ;
if ( F_25 ( & V_4 -> V_86 -> V_87 , V_2 -> V_38 ) ) {
if ( F_27 () )
F_28 ( V_35 , L_8 ) ;
return - V_236 ;
}
return 0 ;
}
static bool F_100 ( struct V_34 * V_35 , struct V_41 * * V_42 ,
struct V_1 * V_2 , T_4 V_237 , bool V_238 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_41 * V_239 ;
if ( V_237 > V_4 -> V_240 )
return false ;
V_239 = F_101 ( V_35 , V_237 ) ;
if ( ! V_239 )
return false ;
F_102 ( & V_4 -> V_86 -> V_87 , V_2 -> V_38 ,
V_234 - V_4 -> V_233 ,
V_235 ) ;
if ( ! V_238 )
memcpy ( V_239 -> V_95 , ( * V_42 ) -> V_95 , V_237 ) ;
else
F_7 ( V_239 -> V_95 , ( * V_42 ) -> V_95 , V_237 ) ;
* V_42 = V_239 ;
return true ;
}
static int
F_103 ( struct V_34 * V_35 , int V_241 , T_6 V_5 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
unsigned short V_58 ;
struct V_41 * V_242 = NULL ;
struct V_41 * V_42 ;
T_7 V_243 ;
T_8 * V_95 ;
int V_244 = 0 ;
struct V_7 * V_53 = NULL ;
bool V_245 = false ;
T_6 V_246 ;
int V_36 = 0 ;
bool V_247 ;
bool V_248 = V_4 -> V_74 & V_84 ;
#ifdef F_104
F_105 () ;
#endif
V_5 = F_90 ( V_5 ) ;
V_13 = V_4 -> V_14 [ V_5 ] ;
V_2 = V_13 -> V_122 ;
while ( ! ( ( V_58 = V_2 -> V_37 ) & V_120 ) ) {
if ( V_244 >= V_241 )
break;
V_244 ++ ;
if ( ( V_58 & V_249 ) == 0 )
F_28 ( V_35 , L_9 ) ;
if ( V_58 & ( V_250 | V_251 | V_252 |
V_253 | V_254 ) ) {
V_35 -> V_200 . V_255 ++ ;
if ( V_58 & ( V_250 | V_251 ) ) {
V_35 -> V_200 . V_256 ++ ;
}
if ( V_58 & V_252 )
V_35 -> V_200 . V_257 ++ ;
if ( V_58 & V_253 )
V_35 -> V_200 . V_258 ++ ;
if ( V_58 & V_254 )
V_35 -> V_200 . V_259 ++ ;
}
if ( V_58 & V_260 ) {
V_35 -> V_200 . V_255 ++ ;
V_35 -> V_200 . V_257 ++ ;
goto V_261;
}
V_35 -> V_200 . V_262 ++ ;
V_243 = V_2 -> V_39 ;
V_35 -> V_200 . V_263 += V_243 ;
V_36 = F_3 ( V_13 -> V_20 , V_2 , V_4 ) ;
V_42 = V_13 -> V_264 [ V_36 ] ;
V_247 = F_100 ( V_35 , & V_42 , V_2 , V_243 - 4 ,
V_248 ) ;
if ( ! V_247 ) {
V_242 = F_101 ( V_35 , V_234 ) ;
if ( F_17 ( ! V_242 ) ) {
V_35 -> V_200 . V_265 ++ ;
goto V_261;
}
F_29 ( & V_4 -> V_86 -> V_87 , V_2 -> V_38 ,
V_234 - V_4 -> V_233 ,
V_235 ) ;
}
F_106 ( V_42 -> V_95 - V_266 ) ;
F_107 ( V_42 , V_243 - 4 ) ;
V_95 = V_42 -> V_95 ;
if ( ! V_247 && V_248 )
F_5 ( V_95 , V_243 ) ;
V_53 = NULL ;
if ( V_4 -> V_7 )
V_53 = (struct V_7 * ) V_2 ;
V_245 = false ;
if ( ( V_35 -> V_267 & V_268 ) &&
V_4 -> V_7 && ( V_53 -> V_79 & V_269 ) ) {
struct V_270 * V_271 =
(struct V_270 * ) ( V_95 + V_272 ) ;
V_246 = F_108 ( V_271 -> V_273 ) ;
V_245 = true ;
memmove ( V_42 -> V_95 + V_274 , V_95 , V_137 * 2 ) ;
F_109 ( V_42 , V_274 ) ;
}
V_42 -> V_43 = F_110 ( V_42 , V_35 ) ;
if ( V_4 -> V_275 && V_4 -> V_7 )
F_84 ( V_4 , V_53 -> V_207 ,
F_111 ( V_42 ) ) ;
if ( V_4 -> V_7 &&
( V_4 -> V_148 & V_149 ) ) {
if ( ! ( V_53 -> V_79 & V_276 ) ) {
V_42 -> V_46 = V_277 ;
} else {
F_112 ( V_42 ) ;
}
}
if ( V_245 )
F_113 ( V_42 ,
F_14 ( V_278 ) ,
V_246 ) ;
F_114 ( & V_4 -> V_206 , V_42 ) ;
if ( V_247 ) {
F_115 ( & V_4 -> V_86 -> V_87 , V_2 -> V_38 ,
V_234 - V_4 -> V_233 ,
V_235 ) ;
} else {
V_13 -> V_264 [ V_36 ] = V_242 ;
F_98 ( V_35 , V_2 , V_242 ) ;
}
V_261:
V_58 &= ~ V_279 ;
V_58 |= V_120 ;
V_2 -> V_37 = V_58 ;
if ( V_4 -> V_7 ) {
struct V_7 * V_53 = (struct V_7 * ) V_2 ;
V_53 -> V_79 = V_280 ;
V_53 -> V_281 = 0 ;
V_53 -> V_78 = 0 ;
}
V_2 = F_1 ( V_2 , V_4 , V_5 ) ;
F_33 ( 0 , V_4 -> V_97 + F_53 ( V_5 ) ) ;
}
V_13 -> V_122 = V_2 ;
return V_244 ;
}
static int
F_116 ( struct V_34 * V_35 , int V_241 )
{
int V_244 = 0 ;
T_6 V_5 ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_96 (queue_id, &fep->work_rx, FEC_ENET_MAX_RX_QS) {
F_97 ( V_5 , & V_4 -> V_282 ) ;
V_244 += F_103 ( V_35 ,
V_241 - V_244 , V_5 ) ;
}
return V_244 ;
}
static bool
F_117 ( struct V_3 * V_4 , T_9 V_283 )
{
if ( V_283 == 0 )
return false ;
if ( V_283 & V_284 )
V_4 -> V_282 |= ( 1 << 2 ) ;
if ( V_283 & V_285 )
V_4 -> V_282 |= ( 1 << 0 ) ;
if ( V_283 & V_286 )
V_4 -> V_282 |= ( 1 << 1 ) ;
if ( V_283 & V_287 )
V_4 -> V_231 |= ( 1 << 2 ) ;
if ( V_283 & V_288 )
V_4 -> V_231 |= ( 1 << 0 ) ;
if ( V_283 & V_289 )
V_4 -> V_231 |= ( 1 << 1 ) ;
return true ;
}
static T_10
F_118 ( int V_290 , void * V_291 )
{
struct V_34 * V_35 = V_291 ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
T_9 V_283 ;
T_10 V_93 = V_292 ;
V_283 = F_46 ( V_4 -> V_97 + V_140 ) ;
F_33 ( V_283 , V_4 -> V_97 + V_140 ) ;
F_117 ( V_4 , V_283 ) ;
if ( ( V_4 -> V_231 || V_4 -> V_282 ) && V_4 -> V_185 ) {
V_93 = V_293 ;
if ( F_119 ( & V_4 -> V_206 ) ) {
F_33 ( V_188 , V_4 -> V_97 + V_187 ) ;
F_120 ( & V_4 -> V_206 ) ;
}
}
if ( V_283 & V_188 ) {
V_93 = V_293 ;
F_121 ( & V_4 -> V_294 ) ;
}
if ( V_4 -> V_295 )
F_122 ( V_4 ) ;
return V_93 ;
}
static int F_123 ( struct V_296 * V_206 , int V_241 )
{
struct V_34 * V_35 = V_206 -> V_87 ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_297 ;
V_297 = F_116 ( V_35 , V_241 ) ;
F_95 ( V_35 ) ;
if ( V_297 < V_241 ) {
F_124 ( V_206 ) ;
F_33 ( V_186 , V_4 -> V_97 + V_187 ) ;
}
return V_297 ;
}
static void F_125 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_189 * V_190 = F_126 ( & V_4 -> V_86 -> V_87 ) ;
unsigned char * V_298 , V_299 [ V_137 ] ;
V_298 = V_300 ;
if ( ! F_127 ( V_298 ) ) {
struct V_301 * V_302 = V_4 -> V_86 -> V_87 . V_303 ;
if ( V_302 ) {
const char * V_304 = F_128 ( V_302 ) ;
if ( V_304 )
V_298 = ( unsigned char * ) V_304 ;
}
}
if ( ! F_127 ( V_298 ) ) {
#ifdef V_146
if ( V_305 )
V_298 = ( unsigned char * ) V_305 ;
#else
if ( V_190 )
V_298 = ( unsigned char * ) & V_190 -> V_304 ;
#endif
}
if ( ! F_127 ( V_298 ) ) {
* ( ( V_306 * ) & V_299 [ 0 ] ) =
F_65 ( F_46 ( V_4 -> V_97 + V_138 ) ) ;
* ( ( V_307 * ) & V_299 [ 4 ] ) =
F_129 ( F_46 ( V_4 -> V_97 + V_139 ) >> 16 ) ;
V_298 = & V_299 [ 0 ] ;
}
if ( ! F_127 ( V_298 ) ) {
F_28 ( V_35 , L_10 , V_298 ) ;
F_130 ( V_35 ) ;
F_11 ( V_35 , L_11 ,
V_35 -> V_136 ) ;
return;
}
memcpy ( V_35 -> V_136 , V_298 , V_137 ) ;
if ( V_298 == V_300 )
V_35 -> V_136 [ V_137 - 1 ] = V_300 [ V_137 - 1 ] + V_4 -> V_291 ;
}
static void F_131 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_308 * V_154 = V_4 -> V_154 ;
int V_309 = 0 ;
if ( V_4 -> V_310 && V_154 -> V_311 == V_312 ) {
V_154 -> V_311 = V_313 ;
return;
}
if ( ! F_77 ( V_35 ) || ! F_76 ( V_35 ) ) {
V_4 -> V_185 = 0 ;
} else if ( V_154 -> V_185 ) {
if ( ! V_4 -> V_185 ) {
V_4 -> V_185 = V_154 -> V_185 ;
V_309 = 1 ;
}
if ( V_4 -> V_141 != V_154 -> V_314 ) {
V_4 -> V_141 = V_154 -> V_314 ;
V_309 = 1 ;
}
if ( V_154 -> V_155 != V_4 -> V_155 ) {
V_4 -> V_155 = V_154 -> V_155 ;
V_309 = 1 ;
}
if ( V_309 ) {
F_78 ( & V_4 -> V_206 ) ;
F_79 ( V_35 ) ;
F_63 ( V_35 ) ;
F_80 ( V_35 ) ;
F_81 ( V_35 ) ;
F_82 ( & V_4 -> V_206 ) ;
}
} else {
if ( V_4 -> V_185 ) {
F_78 ( & V_4 -> V_206 ) ;
F_79 ( V_35 ) ;
F_71 ( V_35 ) ;
F_81 ( V_35 ) ;
F_82 ( & V_4 -> V_206 ) ;
V_4 -> V_185 = V_154 -> V_185 ;
V_309 = 1 ;
}
}
if ( V_309 )
F_132 ( V_154 ) ;
}
static int F_133 ( struct V_315 * V_316 , int V_317 , int V_318 )
{
struct V_3 * V_4 = V_316 -> V_319 ;
unsigned long V_320 ;
V_4 -> V_310 = 0 ;
F_134 ( & V_4 -> V_294 ) ;
F_33 ( V_321 | V_322 |
F_135 ( V_317 ) | F_136 ( V_318 ) |
V_323 , V_4 -> V_97 + V_324 ) ;
V_320 = F_137 ( & V_4 -> V_294 ,
F_138 ( V_325 ) ) ;
if ( V_320 == 0 ) {
V_4 -> V_310 = 1 ;
F_28 ( V_4 -> V_205 , L_12 ) ;
return - V_326 ;
}
return F_139 ( F_46 ( V_4 -> V_97 + V_324 ) ) ;
}
static int F_140 ( struct V_315 * V_316 , int V_317 , int V_318 ,
T_6 V_327 )
{
struct V_3 * V_4 = V_316 -> V_319 ;
unsigned long V_320 ;
V_4 -> V_310 = 0 ;
F_134 ( & V_4 -> V_294 ) ;
F_33 ( V_321 | V_328 |
F_135 ( V_317 ) | F_136 ( V_318 ) |
V_323 | F_139 ( V_327 ) ,
V_4 -> V_97 + V_324 ) ;
V_320 = F_137 ( & V_4 -> V_294 ,
F_138 ( V_325 ) ) ;
if ( V_320 == 0 ) {
V_4 -> V_310 = 1 ;
F_28 ( V_4 -> V_205 , L_13 ) ;
return - V_326 ;
}
return 0 ;
}
static int F_141 ( struct V_34 * V_35 , bool V_329 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_93 ;
if ( V_329 ) {
V_93 = F_142 ( V_4 -> V_330 ) ;
if ( V_93 )
return V_93 ;
V_93 = F_142 ( V_4 -> V_331 ) ;
if ( V_93 )
goto V_332;
if ( V_4 -> V_333 ) {
V_93 = F_142 ( V_4 -> V_333 ) ;
if ( V_93 )
goto V_334;
}
if ( V_4 -> V_335 ) {
F_143 ( & V_4 -> V_336 ) ;
V_93 = F_142 ( V_4 -> V_335 ) ;
if ( V_93 ) {
F_144 ( & V_4 -> V_336 ) ;
goto V_337;
} else {
V_4 -> V_338 = true ;
}
F_144 ( & V_4 -> V_336 ) ;
}
if ( V_4 -> V_339 ) {
V_93 = F_142 ( V_4 -> V_339 ) ;
if ( V_93 )
goto V_340;
}
} else {
F_145 ( V_4 -> V_330 ) ;
F_145 ( V_4 -> V_331 ) ;
if ( V_4 -> V_333 )
F_145 ( V_4 -> V_333 ) ;
if ( V_4 -> V_335 ) {
F_143 ( & V_4 -> V_336 ) ;
F_145 ( V_4 -> V_335 ) ;
V_4 -> V_338 = false ;
F_144 ( & V_4 -> V_336 ) ;
}
if ( V_4 -> V_339 )
F_145 ( V_4 -> V_339 ) ;
}
return 0 ;
V_340:
if ( V_4 -> V_339 )
F_145 ( V_4 -> V_339 ) ;
V_337:
if ( V_4 -> V_333 )
F_145 ( V_4 -> V_333 ) ;
V_334:
F_145 ( V_4 -> V_331 ) ;
V_332:
F_145 ( V_4 -> V_330 ) ;
return V_93 ;
}
static int F_146 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_308 * V_154 = NULL ;
char V_341 [ V_342 ] ;
char V_343 [ V_342 + 3 ] ;
int V_344 ;
int V_291 = V_4 -> V_291 ;
V_4 -> V_154 = NULL ;
if ( V_4 -> V_345 ) {
V_154 = F_147 ( V_35 , V_4 -> V_345 ,
& F_131 , 0 ,
V_4 -> V_151 ) ;
if ( ! V_154 )
return - V_346 ;
} else {
for ( V_344 = 0 ; ( V_344 < V_347 ) ; V_344 ++ ) {
if ( ( V_4 -> V_315 -> V_348 & ( 1 << V_344 ) ) )
continue;
if ( V_4 -> V_315 -> V_349 [ V_344 ] == NULL )
continue;
if ( V_4 -> V_315 -> V_349 [ V_344 ] -> V_344 == 0 )
continue;
if ( V_291 -- )
continue;
F_148 ( V_341 , V_4 -> V_315 -> V_350 , V_342 ) ;
break;
}
if ( V_344 >= V_347 ) {
F_11 ( V_35 , L_14 ) ;
F_148 ( V_341 , L_15 , V_342 ) ;
V_344 = 0 ;
}
snprintf ( V_343 , sizeof( V_343 ) ,
V_351 , V_341 , V_344 ) ;
V_154 = F_149 ( V_35 , V_343 , & F_131 ,
V_4 -> V_151 ) ;
}
if ( F_150 ( V_154 ) ) {
F_28 ( V_35 , L_16 ) ;
return F_151 ( V_154 ) ;
}
if ( V_4 -> V_74 & V_352 ) {
V_154 -> V_353 &= V_354 ;
V_154 -> V_353 &= ~ V_355 ;
#if ! F_66 ( V_146 )
V_154 -> V_353 |= V_356 ;
#endif
}
else
V_154 -> V_353 &= V_357 ;
V_154 -> V_358 = V_154 -> V_353 ;
V_4 -> V_154 = V_154 ;
V_4 -> V_185 = 0 ;
V_4 -> V_141 = 0 ;
F_11 ( V_35 , L_17 ,
V_4 -> V_154 -> V_359 -> V_360 , F_152 ( & V_4 -> V_154 -> V_87 ) ,
V_4 -> V_154 -> V_290 ) ;
return 0 ;
}
static int F_153 ( struct V_361 * V_86 )
{
static struct V_315 * V_362 ;
struct V_34 * V_35 = F_154 ( V_86 ) ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_301 * V_363 ;
int V_364 = - V_365 , V_28 ;
T_4 V_366 , V_367 ;
if ( ( V_4 -> V_74 & V_368 ) && V_4 -> V_291 > 0 ) {
if ( V_369 && V_362 ) {
V_4 -> V_315 = V_362 ;
V_369 ++ ;
return 0 ;
}
return - V_370 ;
}
V_4 -> V_310 = 0 ;
V_366 = F_155 ( F_156 ( V_4 -> V_331 ) , 5000000 ) ;
if ( V_4 -> V_74 & V_135 )
V_366 -- ;
if ( V_366 > 63 ) {
F_157 ( & V_86 -> V_87 ,
L_18 ,
F_156 ( V_4 -> V_331 ) ) ;
V_364 = - V_371 ;
goto V_372;
}
V_367 = F_155 ( F_156 ( V_4 -> V_331 ) , 100000000 ) - 1 ;
V_4 -> V_144 = V_366 << 1 | V_367 << 8 ;
F_33 ( V_4 -> V_144 , V_4 -> V_97 + V_145 ) ;
V_4 -> V_315 = F_158 () ;
if ( V_4 -> V_315 == NULL ) {
V_364 = - V_236 ;
goto V_372;
}
V_4 -> V_315 -> V_360 = L_19 ;
V_4 -> V_315 -> V_373 = F_133 ;
V_4 -> V_315 -> V_374 = F_140 ;
snprintf ( V_4 -> V_315 -> V_350 , V_342 , L_20 ,
V_86 -> V_360 , V_4 -> V_291 + 1 ) ;
V_4 -> V_315 -> V_319 = V_4 ;
V_4 -> V_315 -> V_375 = & V_86 -> V_87 ;
V_4 -> V_315 -> V_290 = F_159 ( sizeof( int ) * V_347 , V_376 ) ;
if ( ! V_4 -> V_315 -> V_290 ) {
V_364 = - V_236 ;
goto V_377;
}
for ( V_28 = 0 ; V_28 < V_347 ; V_28 ++ )
V_4 -> V_315 -> V_290 [ V_28 ] = V_378 ;
V_363 = F_160 ( V_86 -> V_87 . V_303 , L_21 ) ;
if ( V_363 ) {
V_364 = F_161 ( V_4 -> V_315 , V_363 ) ;
F_162 ( V_363 ) ;
} else {
V_364 = F_163 ( V_4 -> V_315 ) ;
}
if ( V_364 )
goto V_379;
V_369 ++ ;
if ( V_4 -> V_74 & V_368 )
V_362 = V_4 -> V_315 ;
return 0 ;
V_379:
F_164 ( V_4 -> V_315 -> V_290 ) ;
V_377:
F_165 ( V_4 -> V_315 ) ;
V_372:
return V_364 ;
}
static void F_166 ( struct V_3 * V_4 )
{
if ( -- V_369 == 0 ) {
F_167 ( V_4 -> V_315 ) ;
F_164 ( V_4 -> V_315 -> V_290 ) ;
F_165 ( V_4 -> V_315 ) ;
}
}
static int F_168 ( struct V_34 * V_35 ,
struct V_380 * V_381 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_308 * V_382 = V_4 -> V_154 ;
if ( ! V_382 )
return - V_346 ;
return F_169 ( V_382 , V_381 ) ;
}
static int F_170 ( struct V_34 * V_35 ,
struct V_380 * V_381 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_308 * V_382 = V_4 -> V_154 ;
if ( ! V_382 )
return - V_346 ;
return F_171 ( V_382 , V_381 ) ;
}
static void F_172 ( struct V_34 * V_35 ,
struct V_383 * V_384 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_148 ( V_384 -> V_385 , V_4 -> V_86 -> V_87 . V_385 -> V_360 ,
sizeof( V_384 -> V_385 ) ) ;
F_148 ( V_384 -> V_45 , L_22 , sizeof( V_384 -> V_45 ) ) ;
F_148 ( V_384 -> V_386 , F_152 ( & V_35 -> V_87 ) , sizeof( V_384 -> V_386 ) ) ;
}
static int F_173 ( struct V_34 * V_35 ,
struct V_387 * V_384 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
if ( V_4 -> V_7 ) {
V_384 -> V_388 = V_389 |
V_390 |
V_391 |
V_392 |
V_393 |
V_394 ;
if ( V_4 -> V_295 )
V_384 -> V_395 = F_174 ( V_4 -> V_295 ) ;
else
V_384 -> V_395 = - 1 ;
V_384 -> V_396 = ( 1 << V_397 ) |
( 1 << V_398 ) ;
V_384 -> V_399 = ( 1 << V_400 ) |
( 1 << V_401 ) ;
return 0 ;
} else {
return F_175 ( V_35 , V_384 ) ;
}
}
static void F_176 ( struct V_34 * V_35 ,
struct V_402 * V_168 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
V_168 -> V_403 = ( V_4 -> V_165 & V_167 ) != 0 ;
V_168 -> V_404 = ( V_4 -> V_165 & V_166 ) != 0 ;
V_168 -> V_405 = V_168 -> V_404 ;
}
static int F_177 ( struct V_34 * V_35 ,
struct V_402 * V_168 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
if ( ! V_4 -> V_154 )
return - V_346 ;
if ( V_168 -> V_404 != V_168 -> V_405 ) {
F_11 ( V_35 ,
L_23 ) ;
return - V_371 ;
}
V_4 -> V_165 = 0 ;
V_4 -> V_165 |= V_168 -> V_405 ? V_166 : 0 ;
V_4 -> V_165 |= V_168 -> V_403 ? V_167 : 0 ;
if ( V_168 -> V_405 || V_168 -> V_403 ) {
V_4 -> V_154 -> V_353 |= V_406 ;
V_4 -> V_154 -> V_358 |= V_406 ;
} else {
V_4 -> V_154 -> V_353 &= ~ V_406 ;
V_4 -> V_154 -> V_358 &= ~ V_406 ;
}
if ( V_168 -> V_403 ) {
if ( F_77 ( V_35 ) )
F_71 ( V_35 ) ;
F_178 ( V_4 -> V_154 ) ;
}
if ( F_77 ( V_35 ) ) {
F_78 ( & V_4 -> V_206 ) ;
F_79 ( V_35 ) ;
F_63 ( V_35 ) ;
F_80 ( V_35 ) ;
F_81 ( V_35 ) ;
F_82 ( & V_4 -> V_206 ) ;
}
return 0 ;
}
static void F_179 ( struct V_34 * V_87 ,
struct V_407 * V_200 , T_5 * V_95 )
{
struct V_3 * V_4 = F_10 ( V_87 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < F_180 ( V_408 ) ; V_28 ++ )
V_95 [ V_28 ] = F_46 ( V_4 -> V_97 + V_408 [ V_28 ] . V_409 ) ;
}
static void F_181 ( struct V_34 * V_205 ,
T_4 V_410 , T_11 * V_95 )
{
int V_28 ;
switch ( V_410 ) {
case V_411 :
for ( V_28 = 0 ; V_28 < F_180 ( V_408 ) ; V_28 ++ )
memcpy ( V_95 + V_28 * V_412 ,
V_408 [ V_28 ] . V_360 , V_412 ) ;
break;
}
}
static int F_182 ( struct V_34 * V_87 , int V_413 )
{
switch ( V_413 ) {
case V_411 :
return F_180 ( V_408 ) ;
default:
return - V_414 ;
}
}
static int F_183 ( struct V_34 * V_87 )
{
struct V_3 * V_4 = F_10 ( V_87 ) ;
struct V_308 * V_382 = V_4 -> V_154 ;
if ( ! V_382 )
return - V_346 ;
return F_184 ( V_382 ) ;
}
static int F_185 ( struct V_34 * V_35 , int V_415 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
return V_415 * ( V_4 -> V_416 / 64000 ) / 1000 ;
}
static void F_186 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_417 , V_418 ;
if ( ! ( V_4 -> V_74 & V_75 ) )
return;
if ( ! V_4 -> V_419 || ! V_4 -> V_420 ||
! V_4 -> V_421 || ! V_4 -> V_422 )
return;
V_417 = V_423 ;
V_418 = V_423 ;
V_417 |= F_187 ( V_4 -> V_420 ) ;
V_417 |= F_188 ( F_185 ( V_35 , V_4 -> V_419 ) ) ;
V_418 |= F_187 ( V_4 -> V_422 ) ;
V_418 |= F_188 ( F_185 ( V_35 , V_4 -> V_421 ) ) ;
V_417 |= V_424 ;
V_418 |= V_424 ;
F_33 ( V_418 , V_4 -> V_97 + V_425 ) ;
F_33 ( V_417 , V_4 -> V_97 + V_426 ) ;
F_33 ( V_418 , V_4 -> V_97 + V_427 ) ;
F_33 ( V_417 , V_4 -> V_97 + V_428 ) ;
F_33 ( V_418 , V_4 -> V_97 + V_429 ) ;
F_33 ( V_417 , V_4 -> V_97 + V_430 ) ;
}
static int
F_189 ( struct V_34 * V_35 , struct V_431 * V_432 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
if ( ! ( V_4 -> V_74 & V_75 ) )
return - V_414 ;
V_432 -> V_433 = V_4 -> V_419 ;
V_432 -> V_434 = V_4 -> V_420 ;
V_432 -> V_435 = V_4 -> V_421 ;
V_432 -> V_436 = V_4 -> V_422 ;
return 0 ;
}
static int
F_190 ( struct V_34 * V_35 , struct V_431 * V_432 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
unsigned int V_437 ;
if ( ! ( V_4 -> V_74 & V_75 ) )
return - V_414 ;
if ( V_432 -> V_434 > 255 ) {
F_191 ( L_24 ) ;
return - V_371 ;
}
if ( V_432 -> V_436 > 255 ) {
F_191 ( L_25 ) ;
return - V_371 ;
}
V_437 = F_185 ( V_35 , V_4 -> V_419 ) ;
if ( V_437 > 0xFFFF ) {
F_191 ( L_26 ) ;
return - V_371 ;
}
V_437 = F_185 ( V_35 , V_4 -> V_421 ) ;
if ( V_437 > 0xFFFF ) {
F_191 ( L_26 ) ;
return - V_371 ;
}
V_4 -> V_419 = V_432 -> V_433 ;
V_4 -> V_420 = V_432 -> V_434 ;
V_4 -> V_421 = V_432 -> V_435 ;
V_4 -> V_422 = V_432 -> V_436 ;
F_186 ( V_35 ) ;
return 0 ;
}
static void F_70 ( struct V_34 * V_35 )
{
struct V_431 V_432 ;
V_432 . V_433 = V_438 ;
V_432 . V_434 = V_439 ;
V_432 . V_435 = V_438 ;
V_432 . V_436 = V_439 ;
F_190 ( V_35 , & V_432 ) ;
}
static int F_192 ( struct V_34 * V_205 ,
const struct V_440 * V_441 ,
void * V_95 )
{
struct V_3 * V_4 = F_10 ( V_205 ) ;
int V_93 = 0 ;
switch ( V_441 -> V_350 ) {
case V_442 :
* ( T_4 * ) V_95 = V_4 -> V_240 ;
break;
default:
V_93 = - V_371 ;
break;
}
return V_93 ;
}
static int F_193 ( struct V_34 * V_205 ,
const struct V_440 * V_441 ,
const void * V_95 )
{
struct V_3 * V_4 = F_10 ( V_205 ) ;
int V_93 = 0 ;
switch ( V_441 -> V_350 ) {
case V_442 :
V_4 -> V_240 = * ( T_4 * ) V_95 ;
break;
default:
V_93 = - V_371 ;
break;
}
return V_93 ;
}
static void
F_194 ( struct V_34 * V_35 , struct V_443 * V_444 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
if ( V_4 -> V_194 & V_445 ) {
V_444 -> V_353 = V_446 ;
V_444 -> V_447 = V_4 -> V_194 & V_448 ? V_446 : 0 ;
} else {
V_444 -> V_353 = V_444 -> V_447 = 0 ;
}
}
static int
F_195 ( struct V_34 * V_35 , struct V_443 * V_444 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
if ( ! ( V_4 -> V_194 & V_445 ) )
return - V_371 ;
if ( V_444 -> V_447 & ~ V_446 )
return - V_371 ;
F_196 ( & V_35 -> V_87 , V_444 -> V_447 & V_446 ) ;
if ( F_197 ( & V_35 -> V_87 ) ) {
V_4 -> V_194 |= V_448 ;
if ( V_4 -> V_290 [ 0 ] > 0 )
F_198 ( V_4 -> V_290 [ 0 ] ) ;
} else {
V_4 -> V_194 &= ( ~ V_448 ) ;
if ( V_4 -> V_290 [ 0 ] > 0 )
F_199 ( V_4 -> V_290 [ 0 ] ) ;
}
return 0 ;
}
static int F_200 ( struct V_34 * V_35 , struct V_449 * V_450 , int V_381 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_308 * V_382 = V_4 -> V_154 ;
if ( ! F_77 ( V_35 ) )
return - V_371 ;
if ( ! V_382 )
return - V_346 ;
if ( V_4 -> V_7 ) {
if ( V_381 == V_451 )
return F_201 ( V_35 , V_450 ) ;
if ( V_381 == V_452 )
return F_202 ( V_35 , V_450 ) ;
}
return F_203 ( V_382 , V_450 , V_381 ) ;
}
static void F_204 ( struct V_34 * V_35 )
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
V_42 = V_13 -> V_264 [ V_28 ] ;
V_13 -> V_264 [ V_28 ] = NULL ;
if ( V_42 ) {
F_29 ( & V_4 -> V_86 -> V_87 ,
V_2 -> V_38 ,
V_234 - V_4 -> V_233 ,
V_235 ) ;
F_205 ( V_42 ) ;
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
F_205 ( V_42 ) ;
}
}
}
static void F_206 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_28 ;
struct V_9 * V_10 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_123 ; V_28 ++ )
if ( V_4 -> V_11 [ V_28 ] && V_4 -> V_11 [ V_28 ] -> V_104 ) {
V_10 = V_4 -> V_11 [ V_28 ] ;
F_207 ( NULL ,
V_10 -> V_19 * V_105 ,
V_10 -> V_104 ,
V_10 -> V_106 ) ;
}
for ( V_28 = 0 ; V_28 < V_4 -> V_119 ; V_28 ++ )
F_164 ( V_4 -> V_14 [ V_28 ] ) ;
for ( V_28 = 0 ; V_28 < V_4 -> V_123 ; V_28 ++ )
F_164 ( V_4 -> V_11 [ V_28 ] ) ;
}
static int F_208 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_28 ;
int V_93 = 0 ;
struct V_9 * V_10 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_123 ; V_28 ++ ) {
V_10 = F_209 ( sizeof( * V_10 ) , V_376 ) ;
if ( ! V_10 ) {
V_93 = - V_236 ;
goto V_453;
}
V_4 -> V_11 [ V_28 ] = V_10 ;
V_10 -> V_19 = V_454 ;
V_4 -> V_455 += V_4 -> V_11 [ V_28 ] -> V_19 ;
V_10 -> V_117 = V_456 ;
V_10 -> V_230 =
( V_10 -> V_19 - V_10 -> V_117 ) / 2 ;
V_10 -> V_104 = F_210 ( NULL ,
V_10 -> V_19 * V_105 ,
& V_10 -> V_106 ,
V_376 ) ;
if ( ! V_10 -> V_104 ) {
V_93 = - V_236 ;
goto V_453;
}
}
for ( V_28 = 0 ; V_28 < V_4 -> V_119 ; V_28 ++ ) {
V_4 -> V_14 [ V_28 ] = F_209 ( sizeof( * V_4 -> V_14 [ V_28 ] ) ,
V_376 ) ;
if ( ! V_4 -> V_14 [ V_28 ] ) {
V_93 = - V_236 ;
goto V_453;
}
V_4 -> V_14 [ V_28 ] -> V_21 = V_457 ;
V_4 -> V_458 += V_4 -> V_14 [ V_28 ] -> V_21 ;
}
return V_93 ;
V_453:
F_206 ( V_35 ) ;
return V_93 ;
}
static int
F_211 ( struct V_34 * V_35 , unsigned int V_55 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
unsigned int V_28 ;
struct V_41 * V_42 ;
struct V_1 * V_2 ;
struct V_12 * V_13 ;
V_13 = V_4 -> V_14 [ V_55 ] ;
V_2 = V_13 -> V_20 ;
for ( V_28 = 0 ; V_28 < V_13 -> V_21 ; V_28 ++ ) {
V_42 = F_101 ( V_35 , V_234 ) ;
if ( ! V_42 )
goto V_459;
if ( F_98 ( V_35 , V_2 , V_42 ) ) {
F_205 ( V_42 ) ;
goto V_459;
}
V_13 -> V_264 [ V_28 ] = V_42 ;
V_2 -> V_37 = V_120 ;
if ( V_4 -> V_7 ) {
struct V_7 * V_53 = (struct V_7 * ) V_2 ;
V_53 -> V_79 = V_280 ;
}
V_2 = F_1 ( V_2 , V_4 , V_55 ) ;
}
V_2 = F_2 ( V_2 , V_4 , V_55 ) ;
V_2 -> V_37 |= V_121 ;
return 0 ;
V_459:
F_204 ( V_35 ) ;
return - V_236 ;
}
static int
F_212 ( struct V_34 * V_35 , unsigned int V_55 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
unsigned int V_28 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
V_10 = V_4 -> V_11 [ V_55 ] ;
V_2 = V_10 -> V_18 ;
for ( V_28 = 0 ; V_28 < V_10 -> V_19 ; V_28 ++ ) {
V_10 -> V_85 [ V_28 ] = F_159 ( V_460 , V_376 ) ;
if ( ! V_10 -> V_85 [ V_28 ] )
goto V_459;
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
V_459:
F_204 ( V_35 ) ;
return - V_236 ;
}
static int F_213 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_119 ; V_28 ++ )
if ( F_211 ( V_35 , V_28 ) )
return - V_236 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_123 ; V_28 ++ )
if ( F_212 ( V_35 , V_28 ) )
return - V_236 ;
return 0 ;
}
static int
F_214 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_93 ;
F_215 ( & V_4 -> V_86 -> V_87 ) ;
V_93 = F_141 ( V_35 , true ) ;
if ( V_93 )
return V_93 ;
V_93 = F_213 ( V_35 ) ;
if ( V_93 )
goto V_461;
V_93 = F_146 ( V_35 ) ;
if ( V_93 )
goto V_462;
F_63 ( V_35 ) ;
F_82 ( & V_4 -> V_206 ) ;
F_216 ( V_4 -> V_154 ) ;
F_217 ( V_35 ) ;
F_196 ( & V_35 -> V_87 , V_4 -> V_194 &
V_448 ) ;
return 0 ;
V_462:
F_204 ( V_35 ) ;
V_461:
F_141 ( V_35 , false ) ;
F_218 ( & V_4 -> V_86 -> V_87 ) ;
return V_93 ;
}
static int
F_219 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_220 ( V_4 -> V_154 ) ;
if ( F_76 ( V_35 ) ) {
F_78 ( & V_4 -> V_206 ) ;
F_221 ( V_35 ) ;
F_71 ( V_35 ) ;
}
F_222 ( V_4 -> V_154 ) ;
V_4 -> V_154 = NULL ;
F_141 ( V_35 , false ) ;
F_218 ( & V_4 -> V_86 -> V_87 ) ;
F_204 ( V_35 ) ;
return 0 ;
}
static void F_68 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_463 * V_464 ;
unsigned int V_28 , V_465 , V_95 , V_466 , V_467 ;
unsigned char V_468 ;
if ( V_35 -> V_210 & V_469 ) {
V_467 = F_46 ( V_4 -> V_97 + V_180 ) ;
V_467 |= 0x8 ;
F_33 ( V_467 , V_4 -> V_97 + V_180 ) ;
return;
}
V_467 = F_46 ( V_4 -> V_97 + V_180 ) ;
V_467 &= ~ 0x8 ;
F_33 ( V_467 , V_4 -> V_97 + V_180 ) ;
if ( V_35 -> V_210 & V_470 ) {
F_33 ( 0xffffffff , V_4 -> V_97 + V_471 ) ;
F_33 ( 0xffffffff , V_4 -> V_97 + V_472 ) ;
return;
}
F_33 ( 0 , V_4 -> V_97 + V_471 ) ;
F_33 ( 0 , V_4 -> V_97 + V_472 ) ;
F_223 (ha, ndev) {
V_466 = 0xffffffff ;
for ( V_28 = 0 ; V_28 < V_35 -> V_473 ; V_28 ++ ) {
V_95 = V_464 -> V_61 [ V_28 ] ;
for ( V_465 = 0 ; V_465 < 8 ; V_465 ++ , V_95 >>= 1 ) {
V_466 = ( V_466 >> 1 ) ^
( ( ( V_466 ^ V_95 ) & 1 ) ? V_474 : 0 ) ;
}
}
V_468 = ( V_466 >> ( 32 - V_475 ) ) & 0x3f ;
if ( V_468 > 31 ) {
V_467 = F_46 ( V_4 -> V_97 + V_471 ) ;
V_467 |= 1 << ( V_468 - 32 ) ;
F_33 ( V_467 , V_4 -> V_97 + V_471 ) ;
} else {
V_467 = F_46 ( V_4 -> V_97 + V_472 ) ;
V_467 |= 1 << V_468 ;
F_33 ( V_467 , V_4 -> V_97 + V_472 ) ;
}
}
}
static int
F_224 ( struct V_34 * V_35 , void * V_81 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_476 * V_61 = V_81 ;
if ( V_61 ) {
if ( ! F_127 ( V_61 -> V_477 ) )
return - V_478 ;
memcpy ( V_35 -> V_136 , V_61 -> V_477 , V_35 -> V_473 ) ;
}
F_33 ( V_35 -> V_136 [ 3 ] | ( V_35 -> V_136 [ 2 ] << 8 ) |
( V_35 -> V_136 [ 1 ] << 16 ) | ( V_35 -> V_136 [ 0 ] << 24 ) ,
V_4 -> V_97 + V_138 ) ;
F_33 ( ( V_35 -> V_136 [ 5 ] << 16 ) | ( V_35 -> V_136 [ 4 ] << 24 ) ,
V_4 -> V_97 + V_139 ) ;
return 0 ;
}
static void F_225 ( struct V_34 * V_87 )
{
int V_28 ;
struct V_3 * V_4 = F_10 ( V_87 ) ;
for ( V_28 = 0 ; V_28 < V_479 ; V_28 ++ ) {
if ( V_4 -> V_290 [ V_28 ] > 0 ) {
F_226 ( V_4 -> V_290 [ V_28 ] ) ;
F_118 ( V_4 -> V_290 [ V_28 ] , V_87 ) ;
F_227 ( V_4 -> V_290 [ V_28 ] ) ;
}
}
}
static inline void F_228 ( struct V_34 * V_205 ,
T_12 V_267 )
{
struct V_3 * V_4 = F_10 ( V_205 ) ;
T_12 V_480 = V_267 ^ V_205 -> V_267 ;
V_205 -> V_267 = V_267 ;
if ( V_480 & V_481 ) {
if ( V_267 & V_481 )
V_4 -> V_148 |= V_149 ;
else
V_4 -> V_148 &= ~ V_149 ;
}
}
static int F_229 ( struct V_34 * V_205 ,
T_12 V_267 )
{
struct V_3 * V_4 = F_10 ( V_205 ) ;
T_12 V_480 = V_267 ^ V_205 -> V_267 ;
if ( F_77 ( V_205 ) && V_480 & V_482 ) {
F_78 ( & V_4 -> V_206 ) ;
F_79 ( V_205 ) ;
F_71 ( V_205 ) ;
F_228 ( V_205 , V_267 ) ;
F_63 ( V_205 ) ;
F_230 ( V_205 ) ;
F_81 ( V_205 ) ;
F_82 ( & V_4 -> V_206 ) ;
} else {
F_228 ( V_205 , V_267 ) ;
}
return 0 ;
}
static int F_231 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
struct V_1 * V_483 ;
T_2 V_124 ;
int V_484 ;
unsigned int V_28 ;
#if F_66 ( V_485 )
V_4 -> V_233 = 0xf ;
V_4 -> V_83 = 0xf ;
#else
V_4 -> V_233 = 0x3 ;
V_4 -> V_83 = 0x3 ;
#endif
F_208 ( V_35 ) ;
if ( V_4 -> V_7 )
V_4 -> V_22 = sizeof( struct V_7 ) ;
else
V_4 -> V_22 = sizeof( struct V_1 ) ;
V_484 = ( V_4 -> V_455 + V_4 -> V_458 ) *
V_4 -> V_22 ;
V_483 = F_210 ( NULL , V_484 , & V_124 ,
V_376 ) ;
if ( ! V_483 ) {
return - V_236 ;
}
memset ( V_483 , 0 , V_484 ) ;
F_125 ( V_35 ) ;
F_224 ( V_35 , NULL ) ;
for ( V_28 = 0 ; V_28 < V_4 -> V_119 ; V_28 ++ ) {
V_13 = V_4 -> V_14 [ V_28 ] ;
V_13 -> V_36 = V_28 ;
V_13 -> V_20 = (struct V_1 * ) V_483 ;
V_13 -> V_124 = V_124 ;
if ( V_4 -> V_7 ) {
V_124 += sizeof( struct V_7 ) * V_13 -> V_21 ;
V_483 = (struct V_1 * )
( ( (struct V_7 * ) V_483 ) + V_13 -> V_21 ) ;
} else {
V_124 += sizeof( struct V_1 ) * V_13 -> V_21 ;
V_483 += V_13 -> V_21 ;
}
}
for ( V_28 = 0 ; V_28 < V_4 -> V_123 ; V_28 ++ ) {
V_10 = V_4 -> V_11 [ V_28 ] ;
V_10 -> V_36 = V_28 ;
V_10 -> V_18 = (struct V_1 * ) V_483 ;
V_10 -> V_124 = V_124 ;
if ( V_4 -> V_7 ) {
V_124 += sizeof( struct V_7 ) * V_10 -> V_19 ;
V_483 = (struct V_1 * )
( ( (struct V_7 * ) V_483 ) + V_10 -> V_19 ) ;
} else {
V_124 += sizeof( struct V_1 ) * V_10 -> V_19 ;
V_483 += V_10 -> V_19 ;
}
}
V_35 -> V_486 = V_487 ;
V_35 -> V_488 = & V_489 ;
V_35 -> V_490 = & V_491 ;
F_33 ( V_492 , V_4 -> V_97 + V_187 ) ;
F_232 ( V_35 , & V_4 -> V_206 , F_123 , V_493 ) ;
if ( V_4 -> V_74 & V_494 )
V_35 -> V_267 |= V_268 ;
if ( V_4 -> V_74 & V_495 ) {
V_35 -> V_496 = V_497 ;
V_35 -> V_267 |= ( V_498 | V_499
| V_481 | V_500 | V_501 ) ;
V_4 -> V_148 |= V_149 ;
}
if ( V_4 -> V_74 & V_75 ) {
V_4 -> V_83 = 0 ;
V_4 -> V_233 = 0x3f ;
}
V_35 -> V_502 = V_35 -> V_267 ;
F_63 ( V_35 ) ;
return 0 ;
}
static void F_233 ( struct V_361 * V_86 )
{
int V_364 , V_503 ;
int V_504 = 1 ;
struct V_301 * V_302 = V_86 -> V_87 . V_303 ;
if ( ! V_302 )
return;
F_234 ( V_302 , L_27 , & V_504 ) ;
if ( V_504 > 1000 )
V_504 = 1 ;
V_503 = F_235 ( V_302 , L_28 , 0 ) ;
if ( ! F_236 ( V_503 ) )
return;
V_364 = F_237 ( & V_86 -> V_87 , V_503 ,
V_505 , L_29 ) ;
if ( V_364 ) {
F_157 ( & V_86 -> V_87 , L_30 , V_364 ) ;
return;
}
F_238 ( V_504 ) ;
F_239 ( V_503 , 1 ) ;
}
static void F_233 ( struct V_361 * V_86 )
{
}
static void
F_240 ( struct V_361 * V_86 , int * V_506 , int * V_507 )
{
struct V_301 * V_302 = V_86 -> V_87 . V_303 ;
int V_364 ;
* V_506 = * V_507 = 1 ;
if ( ! V_302 || ! F_241 ( V_302 ) )
return;
V_364 = F_234 ( V_302 , L_31 , V_506 ) ;
if ( V_364 )
* V_506 = 1 ;
V_364 = F_234 ( V_302 , L_32 , V_507 ) ;
if ( V_364 )
* V_507 = 1 ;
if ( * V_506 < 1 || * V_506 > V_508 ) {
F_242 ( & V_86 -> V_87 , L_33 ,
* V_506 ) ;
* V_506 = 1 ;
return;
}
if ( * V_507 < 1 || * V_507 > V_509 ) {
F_242 ( & V_86 -> V_87 , L_34 ,
* V_507 ) ;
* V_507 = 1 ;
return;
}
}
static int
F_243 ( struct V_361 * V_86 )
{
struct V_3 * V_4 ;
struct V_189 * V_190 ;
struct V_34 * V_35 ;
int V_28 , V_290 , V_93 = 0 ;
struct V_510 * V_511 ;
const struct V_512 * V_513 ;
static int V_291 ;
struct V_301 * V_302 = V_86 -> V_87 . V_303 , * V_345 ;
int V_514 ;
int V_515 ;
F_240 ( V_86 , & V_514 , & V_515 ) ;
V_35 = F_244 ( sizeof( struct V_3 ) ,
V_514 , V_515 ) ;
if ( ! V_35 )
return - V_236 ;
F_245 ( V_35 , & V_86 -> V_87 ) ;
V_4 = F_10 ( V_35 ) ;
V_513 = F_246 ( V_516 , & V_86 -> V_87 ) ;
if ( V_513 )
V_86 -> V_517 = V_513 -> V_95 ;
V_4 -> V_74 = V_86 -> V_517 -> V_518 ;
V_4 -> V_205 = V_35 ;
V_4 -> V_119 = V_515 ;
V_4 -> V_123 = V_514 ;
#if ! F_66 ( V_146 )
if ( V_4 -> V_74 & V_352 )
V_4 -> V_165 |= V_167 ;
#endif
F_215 ( & V_86 -> V_87 ) ;
V_511 = F_247 ( V_86 , V_519 , 0 ) ;
V_4 -> V_97 = F_248 ( & V_86 -> V_87 , V_511 ) ;
if ( F_150 ( V_4 -> V_97 ) ) {
V_93 = F_151 ( V_4 -> V_97 ) ;
goto V_520;
}
V_4 -> V_86 = V_86 ;
V_4 -> V_291 = V_291 ++ ;
F_249 ( V_86 , V_35 ) ;
if ( F_250 ( V_302 , L_35 , NULL ) )
V_4 -> V_194 |= V_445 ;
V_345 = F_251 ( V_302 , L_36 , 0 ) ;
if ( ! V_345 && F_252 ( V_302 ) ) {
V_93 = F_253 ( V_302 ) ;
if ( V_93 < 0 ) {
F_157 ( & V_86 -> V_87 ,
L_37 ) ;
goto V_521;
}
V_345 = F_254 ( V_302 ) ;
}
V_4 -> V_345 = V_345 ;
V_93 = F_255 ( V_86 -> V_87 . V_303 ) ;
if ( V_93 < 0 ) {
V_190 = F_126 ( & V_86 -> V_87 ) ;
if ( V_190 )
V_4 -> V_151 = V_190 -> V_522 ;
else
V_4 -> V_151 = V_523 ;
} else {
V_4 -> V_151 = V_93 ;
}
V_4 -> V_331 = F_256 ( & V_86 -> V_87 , L_38 ) ;
if ( F_150 ( V_4 -> V_331 ) ) {
V_93 = F_151 ( V_4 -> V_331 ) ;
goto V_524;
}
V_4 -> V_330 = F_256 ( & V_86 -> V_87 , L_39 ) ;
if ( F_150 ( V_4 -> V_330 ) ) {
V_93 = F_151 ( V_4 -> V_330 ) ;
goto V_524;
}
V_4 -> V_416 = F_156 ( V_4 -> V_330 ) ;
V_4 -> V_333 = F_256 ( & V_86 -> V_87 , L_40 ) ;
if ( F_150 ( V_4 -> V_333 ) )
V_4 -> V_333 = NULL ;
V_4 -> V_338 = false ;
F_257 ( & V_4 -> V_336 ) ;
V_4 -> V_339 = F_256 ( & V_86 -> V_87 , L_41 ) ;
if ( F_150 ( V_4 -> V_339 ) )
V_4 -> V_339 = NULL ;
V_4 -> V_7 = V_4 -> V_74 & V_525 ;
V_4 -> V_335 = F_256 ( & V_86 -> V_87 , L_42 ) ;
if ( F_150 ( V_4 -> V_335 ) ) {
V_4 -> V_335 = NULL ;
V_4 -> V_7 = false ;
}
V_93 = F_141 ( V_35 , true ) ;
if ( V_93 )
goto V_524;
V_4 -> V_526 = F_258 ( & V_86 -> V_87 , L_43 ) ;
if ( ! F_150 ( V_4 -> V_526 ) ) {
V_93 = F_259 ( V_4 -> V_526 ) ;
if ( V_93 ) {
F_157 ( & V_86 -> V_87 ,
L_44 , V_93 ) ;
goto V_527;
}
} else {
V_4 -> V_526 = NULL ;
}
F_233 ( V_86 ) ;
if ( V_4 -> V_7 )
F_260 ( V_86 ) ;
V_93 = F_231 ( V_35 ) ;
if ( V_93 )
goto V_528;
for ( V_28 = 0 ; V_28 < V_479 ; V_28 ++ ) {
V_290 = F_261 ( V_86 , V_28 ) ;
if ( V_290 < 0 ) {
if ( V_28 )
break;
V_93 = V_290 ;
goto V_529;
}
V_93 = F_262 ( & V_86 -> V_87 , V_290 , F_118 ,
0 , V_86 -> V_360 , V_35 ) ;
if ( V_93 )
goto V_529;
V_4 -> V_290 [ V_28 ] = V_290 ;
}
F_134 ( & V_4 -> V_294 ) ;
V_93 = F_153 ( V_86 ) ;
if ( V_93 )
goto V_530;
F_263 ( V_35 ) ;
F_141 ( V_35 , false ) ;
F_218 ( & V_86 -> V_87 ) ;
V_93 = F_264 ( V_35 ) ;
if ( V_93 )
goto V_531;
F_265 ( & V_35 -> V_87 , V_4 -> V_194 &
V_445 ) ;
if ( V_4 -> V_7 && V_4 -> V_295 )
F_11 ( V_35 , L_45 , V_4 -> V_291 ) ;
V_4 -> V_240 = V_532 ;
F_266 ( & V_4 -> V_202 , F_74 ) ;
return 0 ;
V_531:
F_166 ( V_4 ) ;
V_530:
V_529:
V_528:
if ( V_4 -> V_526 )
F_267 ( V_4 -> V_526 ) ;
V_527:
F_141 ( V_35 , false ) ;
V_524:
V_521:
F_162 ( V_345 ) ;
V_520:
F_268 ( V_35 ) ;
return V_93 ;
}
static int
F_269 ( struct V_361 * V_86 )
{
struct V_34 * V_35 = F_154 ( V_86 ) ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_270 ( & V_4 -> V_533 ) ;
F_271 ( & V_4 -> V_202 ) ;
F_272 ( V_35 ) ;
F_166 ( V_4 ) ;
if ( V_4 -> V_526 )
F_267 ( V_4 -> V_526 ) ;
if ( V_4 -> V_295 )
F_273 ( V_4 -> V_295 ) ;
F_162 ( V_4 -> V_345 ) ;
F_268 ( V_35 ) ;
return 0 ;
}
static int T_13 F_274 ( struct V_534 * V_87 )
{
struct V_34 * V_35 = F_275 ( V_87 ) ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_75 () ;
if ( F_77 ( V_35 ) ) {
if ( V_4 -> V_194 & V_448 )
V_4 -> V_194 |= V_195 ;
F_220 ( V_4 -> V_154 ) ;
F_78 ( & V_4 -> V_206 ) ;
F_79 ( V_35 ) ;
F_276 ( V_35 ) ;
F_81 ( V_35 ) ;
F_71 ( V_35 ) ;
F_141 ( V_35 , false ) ;
if ( ! ( V_4 -> V_194 & V_448 ) )
F_218 ( & V_4 -> V_86 -> V_87 ) ;
}
F_83 () ;
if ( V_4 -> V_526 && ! ( V_4 -> V_194 & V_448 ) )
F_267 ( V_4 -> V_526 ) ;
if ( V_4 -> V_333 || V_4 -> V_526 )
V_4 -> V_185 = 0 ;
return 0 ;
}
static int T_13 F_277 ( struct V_534 * V_87 )
{
struct V_34 * V_35 = F_275 ( V_87 ) ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_189 * V_190 = V_4 -> V_86 -> V_87 . V_191 ;
int V_93 ;
int V_129 ;
if ( V_4 -> V_526 && ! ( V_4 -> V_194 & V_448 ) ) {
V_93 = F_259 ( V_4 -> V_526 ) ;
if ( V_93 )
return V_93 ;
}
F_75 () ;
if ( F_77 ( V_35 ) ) {
V_93 = F_141 ( V_35 , true ) ;
if ( V_93 ) {
F_83 () ;
goto V_524;
}
if ( V_4 -> V_194 & V_448 ) {
if ( V_190 && V_190 -> V_199 )
V_190 -> V_199 ( false ) ;
V_129 = F_46 ( V_4 -> V_97 + V_134 ) ;
V_129 &= ~ ( V_197 | V_198 ) ;
F_33 ( V_129 , V_4 -> V_97 + V_134 ) ;
V_4 -> V_194 &= ~ V_195 ;
} else {
F_215 ( & V_4 -> V_86 -> V_87 ) ;
}
F_63 ( V_35 ) ;
F_79 ( V_35 ) ;
F_278 ( V_35 ) ;
F_81 ( V_35 ) ;
F_82 ( & V_4 -> V_206 ) ;
F_216 ( V_4 -> V_154 ) ;
}
F_83 () ;
return 0 ;
V_524:
if ( V_4 -> V_526 )
F_267 ( V_4 -> V_526 ) ;
return V_93 ;
}
