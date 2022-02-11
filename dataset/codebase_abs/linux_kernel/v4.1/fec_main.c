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
if ( V_4 -> V_151 == V_152 ||
V_4 -> V_151 == V_153 ||
V_4 -> V_151 == V_154 ||
V_4 -> V_151 == V_155 )
V_131 |= ( 1 << 6 ) ;
else if ( V_4 -> V_151 == V_156 )
V_131 |= ( 1 << 8 ) ;
else
V_131 &= ~ ( 1 << 8 ) ;
if ( V_4 -> V_157 ) {
if ( V_4 -> V_157 -> V_158 == V_159 )
V_133 |= ( 1 << 5 ) ;
else if ( V_4 -> V_157 -> V_158 == V_160 )
V_131 &= ~ ( 1 << 9 ) ;
else
V_131 |= ( 1 << 9 ) ;
}
} else {
#ifdef F_67
if ( V_4 -> V_74 & V_161 ) {
T_4 V_162 ;
F_33 ( 0 , V_4 -> V_97 + F_67 ) ;
while ( F_46 ( V_4 -> V_97 + F_67 ) & 4 )
F_64 ( 1 ) ;
V_162 = ( V_4 -> V_151 == V_156 )
? V_163 : V_164 ;
if ( V_4 -> V_157 && V_4 -> V_157 -> V_158 == V_165 )
V_162 |= V_166 ;
F_33 ( V_162 , V_4 -> V_97 + V_167 ) ;
F_33 ( 2 , V_4 -> V_97 + F_67 ) ;
}
#endif
}
#if ! F_66 ( V_146 )
if ( ( V_4 -> V_168 & V_169 ) ||
( ( V_4 -> V_168 & V_170 ) &&
V_4 -> V_157 && V_4 -> V_157 -> V_171 ) ) {
V_131 |= V_172 ;
F_33 ( V_173 , V_4 -> V_97 + V_174 ) ;
F_33 ( V_175 , V_4 -> V_97 + V_176 ) ;
F_33 ( V_177 , V_4 -> V_97 + V_178 ) ;
F_33 ( V_179 , V_4 -> V_97 + V_180 ) ;
F_33 ( V_181 , V_4 -> V_97 + V_182 ) ;
} else {
V_131 &= ~ V_172 ;
}
#endif
F_33 ( V_131 , V_4 -> V_97 + V_183 ) ;
F_68 ( V_35 ) ;
#ifndef V_146
F_33 ( 0 , V_4 -> V_97 + V_184 ) ;
F_33 ( 0 , V_4 -> V_97 + V_185 ) ;
#endif
if ( V_4 -> V_74 & V_135 ) {
V_133 |= ( 1 << 8 ) ;
F_33 ( 1 << 8 , V_4 -> V_97 + V_186 ) ;
}
if ( V_4 -> V_7 )
V_133 |= ( 1 << 4 ) ;
#ifndef V_146
F_33 ( 0 << 31 , V_4 -> V_97 + V_187 ) ;
#endif
F_33 ( V_133 , V_4 -> V_97 + V_134 ) ;
F_52 ( V_35 ) ;
if ( V_4 -> V_7 )
F_69 ( V_35 ) ;
if ( V_4 -> V_188 )
F_33 ( V_189 , V_4 -> V_97 + V_190 ) ;
else
F_33 ( V_191 , V_4 -> V_97 + V_190 ) ;
F_70 ( V_35 ) ;
}
static void
F_71 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_192 * V_193 = V_4 -> V_86 -> V_87 . V_194 ;
T_4 V_195 = F_46 ( V_4 -> V_97 + V_183 ) & ( 1 << 8 ) ;
T_4 V_129 ;
if ( V_4 -> V_188 ) {
F_33 ( 1 , V_4 -> V_97 + V_143 ) ;
F_64 ( 10 ) ;
if ( ! ( F_46 ( V_4 -> V_97 + V_140 ) & V_196 ) )
F_28 ( V_35 , L_7 ) ;
}
if ( ! ( V_4 -> V_197 & V_198 ) ) {
if ( V_4 -> V_74 & V_75 ) {
F_33 ( 0 , V_4 -> V_97 + V_134 ) ;
} else {
F_33 ( 1 , V_4 -> V_97 + V_134 ) ;
F_64 ( 10 ) ;
}
F_33 ( V_189 , V_4 -> V_97 + V_190 ) ;
} else {
F_33 ( V_189 | V_199 , V_4 -> V_97 + V_190 ) ;
V_129 = F_46 ( V_4 -> V_97 + V_134 ) ;
V_129 |= ( V_200 | V_201 ) ;
F_33 ( V_129 , V_4 -> V_97 + V_134 ) ;
if ( V_193 && V_193 -> V_202 )
V_193 -> V_202 ( true ) ;
}
F_33 ( V_4 -> V_144 , V_4 -> V_97 + V_145 ) ;
if ( V_4 -> V_74 & V_135 &&
! ( V_4 -> V_197 & V_198 ) ) {
F_33 ( 2 , V_4 -> V_97 + V_134 ) ;
F_33 ( V_195 , V_4 -> V_97 + V_183 ) ;
}
}
static void
F_72 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_9 ( V_35 ) ;
V_35 -> V_203 . V_204 ++ ;
F_73 ( & V_4 -> V_205 ) ;
}
static void F_74 ( struct V_206 * V_207 )
{
struct V_3 * V_4 =
F_36 ( V_207 , struct V_3 , V_205 ) ;
struct V_34 * V_35 = V_4 -> V_208 ;
F_75 () ;
if ( F_76 ( V_35 ) || F_77 ( V_35 ) ) {
F_78 ( & V_4 -> V_209 ) ;
F_79 ( V_35 ) ;
F_63 ( V_35 ) ;
F_80 ( V_35 ) ;
F_81 ( V_35 ) ;
F_82 ( & V_4 -> V_209 ) ;
}
F_83 () ;
}
static void
F_84 ( struct V_3 * V_4 , unsigned V_210 ,
struct V_211 * V_212 )
{
unsigned long V_213 ;
T_5 V_214 ;
F_85 ( & V_4 -> V_215 , V_213 ) ;
V_214 = F_86 ( & V_4 -> V_216 , V_210 ) ;
F_87 ( & V_4 -> V_215 , V_213 ) ;
memset ( V_212 , 0 , sizeof( * V_212 ) ) ;
V_212 -> V_217 = F_88 ( V_214 ) ;
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
if ( V_58 & ( V_218 | V_219 |
V_220 | V_221 |
V_222 ) ) {
V_35 -> V_203 . V_204 ++ ;
if ( V_58 & V_218 )
V_35 -> V_203 . V_223 ++ ;
if ( V_58 & V_219 )
V_35 -> V_203 . V_224 ++ ;
if ( V_58 & V_220 )
V_35 -> V_203 . V_225 ++ ;
if ( V_58 & V_221 )
V_35 -> V_203 . V_226 ++ ;
if ( V_58 & V_222 )
V_35 -> V_203 . V_227 ++ ;
} else {
V_35 -> V_203 . V_228 ++ ;
V_35 -> V_203 . V_229 += V_42 -> V_27 ;
}
if ( F_17 ( F_20 ( V_42 ) -> V_70 & V_96 ) &&
V_4 -> V_7 ) {
struct V_211 V_230 ;
struct V_7 * V_53 = (struct V_7 * ) V_2 ;
F_84 ( V_4 , V_53 -> V_210 , & V_230 ) ;
F_92 ( V_42 , & V_230 ) ;
}
if ( V_58 & V_231 )
V_35 -> V_203 . V_232 ++ ;
F_26 ( V_42 ) ;
V_10 -> V_24 = V_2 ;
V_2 = F_1 ( V_2 , V_4 , V_5 ) ;
if ( F_93 ( V_35 ) ) {
V_92 = F_4 ( V_4 , V_10 ) ;
if ( V_92 >= V_10 -> V_233 )
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
F_97 ( V_5 , & V_4 -> V_234 ) ;
F_89 ( V_35 , V_5 ) ;
}
return;
}
static int
F_98 ( struct V_34 * V_35 , struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_235 ;
V_235 = ( ( unsigned long ) V_42 -> V_95 ) & V_4 -> V_236 ;
if ( V_235 )
F_99 ( V_42 , V_4 -> V_236 + 1 - V_235 ) ;
V_2 -> V_38 = F_24 ( & V_4 -> V_86 -> V_87 , V_42 -> V_95 ,
V_237 - V_4 -> V_236 ,
V_238 ) ;
if ( F_25 ( & V_4 -> V_86 -> V_87 , V_2 -> V_38 ) ) {
if ( F_27 () )
F_28 ( V_35 , L_8 ) ;
return - V_239 ;
}
return 0 ;
}
static bool F_100 ( struct V_34 * V_35 , struct V_41 * * V_42 ,
struct V_1 * V_2 , T_4 V_240 , bool V_241 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_41 * V_242 ;
if ( V_240 > V_4 -> V_243 )
return false ;
V_242 = F_101 ( V_35 , V_240 ) ;
if ( ! V_242 )
return false ;
F_102 ( & V_4 -> V_86 -> V_87 , V_2 -> V_38 ,
V_237 - V_4 -> V_236 ,
V_238 ) ;
if ( ! V_241 )
memcpy ( V_242 -> V_95 , ( * V_42 ) -> V_95 , V_240 ) ;
else
F_7 ( V_242 -> V_95 , ( * V_42 ) -> V_95 , V_240 ) ;
* V_42 = V_242 ;
return true ;
}
static int
F_103 ( struct V_34 * V_35 , int V_244 , T_6 V_5 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
unsigned short V_58 ;
struct V_41 * V_245 = NULL ;
struct V_41 * V_42 ;
T_7 V_246 ;
T_8 * V_95 ;
int V_247 = 0 ;
struct V_7 * V_53 = NULL ;
bool V_248 = false ;
T_6 V_249 ;
int V_36 = 0 ;
bool V_250 ;
bool V_251 = V_4 -> V_74 & V_84 ;
#ifdef F_104
F_105 () ;
#endif
V_5 = F_90 ( V_5 ) ;
V_13 = V_4 -> V_14 [ V_5 ] ;
V_2 = V_13 -> V_122 ;
while ( ! ( ( V_58 = V_2 -> V_37 ) & V_120 ) ) {
if ( V_247 >= V_244 )
break;
V_247 ++ ;
if ( ( V_58 & V_252 ) == 0 )
F_28 ( V_35 , L_9 ) ;
if ( V_58 & ( V_253 | V_254 | V_255 |
V_256 | V_257 ) ) {
V_35 -> V_203 . V_258 ++ ;
if ( V_58 & ( V_253 | V_254 ) ) {
V_35 -> V_203 . V_259 ++ ;
}
if ( V_58 & V_255 )
V_35 -> V_203 . V_260 ++ ;
if ( V_58 & V_256 )
V_35 -> V_203 . V_261 ++ ;
if ( V_58 & V_257 )
V_35 -> V_203 . V_262 ++ ;
}
if ( V_58 & V_263 ) {
V_35 -> V_203 . V_258 ++ ;
V_35 -> V_203 . V_260 ++ ;
goto V_264;
}
V_35 -> V_203 . V_265 ++ ;
V_246 = V_2 -> V_39 ;
V_35 -> V_203 . V_266 += V_246 ;
V_36 = F_3 ( V_13 -> V_20 , V_2 , V_4 ) ;
V_42 = V_13 -> V_267 [ V_36 ] ;
V_250 = F_100 ( V_35 , & V_42 , V_2 , V_246 - 4 ,
V_251 ) ;
if ( ! V_250 ) {
V_245 = F_101 ( V_35 , V_237 ) ;
if ( F_17 ( ! V_245 ) ) {
V_35 -> V_203 . V_268 ++ ;
goto V_264;
}
F_29 ( & V_4 -> V_86 -> V_87 , V_2 -> V_38 ,
V_237 - V_4 -> V_236 ,
V_238 ) ;
}
F_106 ( V_42 -> V_95 - V_269 ) ;
F_107 ( V_42 , V_246 - 4 ) ;
V_95 = V_42 -> V_95 ;
if ( ! V_250 && V_251 )
F_5 ( V_95 , V_246 ) ;
V_53 = NULL ;
if ( V_4 -> V_7 )
V_53 = (struct V_7 * ) V_2 ;
V_248 = false ;
if ( ( V_35 -> V_270 & V_271 ) &&
V_4 -> V_7 && ( V_53 -> V_79 & V_272 ) ) {
struct V_273 * V_274 =
(struct V_273 * ) ( V_95 + V_275 ) ;
V_249 = F_108 ( V_274 -> V_276 ) ;
V_248 = true ;
memmove ( V_42 -> V_95 + V_277 , V_95 , V_137 * 2 ) ;
F_109 ( V_42 , V_277 ) ;
}
V_42 -> V_43 = F_110 ( V_42 , V_35 ) ;
if ( V_4 -> V_278 && V_4 -> V_7 )
F_84 ( V_4 , V_53 -> V_210 ,
F_111 ( V_42 ) ) ;
if ( V_4 -> V_7 &&
( V_4 -> V_148 & V_149 ) ) {
if ( ! ( V_53 -> V_79 & V_279 ) ) {
V_42 -> V_46 = V_280 ;
} else {
F_112 ( V_42 ) ;
}
}
if ( V_248 )
F_113 ( V_42 ,
F_14 ( V_281 ) ,
V_249 ) ;
F_114 ( & V_4 -> V_209 , V_42 ) ;
if ( V_250 ) {
F_115 ( & V_4 -> V_86 -> V_87 , V_2 -> V_38 ,
V_237 - V_4 -> V_236 ,
V_238 ) ;
} else {
V_13 -> V_267 [ V_36 ] = V_245 ;
F_98 ( V_35 , V_2 , V_245 ) ;
}
V_264:
V_58 &= ~ V_282 ;
V_58 |= V_120 ;
V_2 -> V_37 = V_58 ;
if ( V_4 -> V_7 ) {
struct V_7 * V_53 = (struct V_7 * ) V_2 ;
V_53 -> V_79 = V_283 ;
V_53 -> V_284 = 0 ;
V_53 -> V_78 = 0 ;
}
V_2 = F_1 ( V_2 , V_4 , V_5 ) ;
F_33 ( 0 , V_4 -> V_97 + F_53 ( V_5 ) ) ;
}
V_13 -> V_122 = V_2 ;
return V_247 ;
}
static int
F_116 ( struct V_34 * V_35 , int V_244 )
{
int V_247 = 0 ;
T_6 V_5 ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_96 (queue_id, &fep->work_rx, FEC_ENET_MAX_RX_QS) {
F_97 ( V_5 , & V_4 -> V_285 ) ;
V_247 += F_103 ( V_35 ,
V_244 - V_247 , V_5 ) ;
}
return V_247 ;
}
static bool
F_117 ( struct V_3 * V_4 , T_9 V_286 )
{
if ( V_286 == 0 )
return false ;
if ( V_286 & V_287 )
V_4 -> V_285 |= ( 1 << 2 ) ;
if ( V_286 & V_288 )
V_4 -> V_285 |= ( 1 << 0 ) ;
if ( V_286 & V_289 )
V_4 -> V_285 |= ( 1 << 1 ) ;
if ( V_286 & V_290 )
V_4 -> V_234 |= ( 1 << 2 ) ;
if ( V_286 & V_291 )
V_4 -> V_234 |= ( 1 << 0 ) ;
if ( V_286 & V_292 )
V_4 -> V_234 |= ( 1 << 1 ) ;
return true ;
}
static T_10
F_118 ( int V_293 , void * V_294 )
{
struct V_34 * V_35 = V_294 ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
T_9 V_286 ;
T_10 V_93 = V_295 ;
V_286 = F_46 ( V_4 -> V_97 + V_140 ) ;
F_33 ( V_286 , V_4 -> V_97 + V_140 ) ;
F_117 ( V_4 , V_286 ) ;
if ( ( V_4 -> V_234 || V_4 -> V_285 ) && V_4 -> V_188 ) {
V_93 = V_296 ;
if ( F_119 ( & V_4 -> V_209 ) ) {
F_33 ( V_191 , V_4 -> V_97 + V_190 ) ;
F_120 ( & V_4 -> V_209 ) ;
}
}
if ( V_286 & V_191 ) {
V_93 = V_296 ;
F_121 ( & V_4 -> V_297 ) ;
}
if ( V_4 -> V_298 )
F_122 ( V_4 ) ;
return V_93 ;
}
static int F_123 ( struct V_299 * V_209 , int V_244 )
{
struct V_34 * V_35 = V_209 -> V_87 ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_300 ;
V_300 = F_116 ( V_35 , V_244 ) ;
F_95 ( V_35 ) ;
if ( V_300 < V_244 ) {
F_124 ( V_209 ) ;
F_33 ( V_189 , V_4 -> V_97 + V_190 ) ;
}
return V_300 ;
}
static void F_125 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_192 * V_193 = F_126 ( & V_4 -> V_86 -> V_87 ) ;
unsigned char * V_301 , V_302 [ V_137 ] ;
V_301 = V_303 ;
if ( ! F_127 ( V_301 ) ) {
struct V_304 * V_305 = V_4 -> V_86 -> V_87 . V_306 ;
if ( V_305 ) {
const char * V_307 = F_128 ( V_305 ) ;
if ( V_307 )
V_301 = ( unsigned char * ) V_307 ;
}
}
if ( ! F_127 ( V_301 ) ) {
#ifdef V_146
if ( V_308 )
V_301 = ( unsigned char * ) V_308 ;
#else
if ( V_193 )
V_301 = ( unsigned char * ) & V_193 -> V_307 ;
#endif
}
if ( ! F_127 ( V_301 ) ) {
* ( ( V_309 * ) & V_302 [ 0 ] ) =
F_65 ( F_46 ( V_4 -> V_97 + V_138 ) ) ;
* ( ( V_310 * ) & V_302 [ 4 ] ) =
F_129 ( F_46 ( V_4 -> V_97 + V_139 ) >> 16 ) ;
V_301 = & V_302 [ 0 ] ;
}
if ( ! F_127 ( V_301 ) ) {
F_28 ( V_35 , L_10 , V_301 ) ;
F_130 ( V_35 ) ;
F_11 ( V_35 , L_11 ,
V_35 -> V_136 ) ;
return;
}
memcpy ( V_35 -> V_136 , V_301 , V_137 ) ;
if ( V_301 == V_303 )
V_35 -> V_136 [ V_137 - 1 ] = V_303 [ V_137 - 1 ] + V_4 -> V_294 ;
}
static void F_131 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_311 * V_157 = V_4 -> V_157 ;
int V_312 = 0 ;
if ( V_4 -> V_313 && V_157 -> V_314 == V_315 ) {
V_157 -> V_314 = V_316 ;
return;
}
if ( ! F_77 ( V_35 ) || ! F_76 ( V_35 ) ) {
V_4 -> V_188 = 0 ;
} else if ( V_157 -> V_188 ) {
if ( ! V_4 -> V_188 ) {
V_4 -> V_188 = V_157 -> V_188 ;
V_312 = 1 ;
}
if ( V_4 -> V_141 != V_157 -> V_317 ) {
V_4 -> V_141 = V_157 -> V_317 ;
V_312 = 1 ;
}
if ( V_157 -> V_158 != V_4 -> V_158 ) {
V_4 -> V_158 = V_157 -> V_158 ;
V_312 = 1 ;
}
if ( V_312 ) {
F_78 ( & V_4 -> V_209 ) ;
F_79 ( V_35 ) ;
F_63 ( V_35 ) ;
F_80 ( V_35 ) ;
F_81 ( V_35 ) ;
F_82 ( & V_4 -> V_209 ) ;
}
} else {
if ( V_4 -> V_188 ) {
F_78 ( & V_4 -> V_209 ) ;
F_79 ( V_35 ) ;
F_71 ( V_35 ) ;
F_81 ( V_35 ) ;
F_82 ( & V_4 -> V_209 ) ;
V_4 -> V_188 = V_157 -> V_188 ;
V_312 = 1 ;
}
}
if ( V_312 )
F_132 ( V_157 ) ;
}
static int F_133 ( struct V_318 * V_319 , int V_320 , int V_321 )
{
struct V_3 * V_4 = V_319 -> V_322 ;
unsigned long V_323 ;
V_4 -> V_313 = 0 ;
F_134 ( & V_4 -> V_297 ) ;
F_33 ( V_324 | V_325 |
F_135 ( V_320 ) | F_136 ( V_321 ) |
V_326 , V_4 -> V_97 + V_327 ) ;
V_323 = F_137 ( & V_4 -> V_297 ,
F_138 ( V_328 ) ) ;
if ( V_323 == 0 ) {
V_4 -> V_313 = 1 ;
F_28 ( V_4 -> V_208 , L_12 ) ;
return - V_329 ;
}
return F_139 ( F_46 ( V_4 -> V_97 + V_327 ) ) ;
}
static int F_140 ( struct V_318 * V_319 , int V_320 , int V_321 ,
T_6 V_330 )
{
struct V_3 * V_4 = V_319 -> V_322 ;
unsigned long V_323 ;
V_4 -> V_313 = 0 ;
F_134 ( & V_4 -> V_297 ) ;
F_33 ( V_324 | V_331 |
F_135 ( V_320 ) | F_136 ( V_321 ) |
V_326 | F_139 ( V_330 ) ,
V_4 -> V_97 + V_327 ) ;
V_323 = F_137 ( & V_4 -> V_297 ,
F_138 ( V_328 ) ) ;
if ( V_323 == 0 ) {
V_4 -> V_313 = 1 ;
F_28 ( V_4 -> V_208 , L_13 ) ;
return - V_329 ;
}
return 0 ;
}
static int F_141 ( struct V_34 * V_35 , bool V_332 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_93 ;
if ( V_332 ) {
V_93 = F_142 ( V_4 -> V_333 ) ;
if ( V_93 )
return V_93 ;
V_93 = F_142 ( V_4 -> V_334 ) ;
if ( V_93 )
goto V_335;
if ( V_4 -> V_336 ) {
V_93 = F_142 ( V_4 -> V_336 ) ;
if ( V_93 )
goto V_337;
}
if ( V_4 -> V_338 ) {
F_143 ( & V_4 -> V_339 ) ;
V_93 = F_142 ( V_4 -> V_338 ) ;
if ( V_93 ) {
F_144 ( & V_4 -> V_339 ) ;
goto V_340;
} else {
V_4 -> V_341 = true ;
}
F_144 ( & V_4 -> V_339 ) ;
}
if ( V_4 -> V_342 ) {
V_93 = F_142 ( V_4 -> V_342 ) ;
if ( V_93 )
goto V_343;
}
} else {
F_145 ( V_4 -> V_333 ) ;
F_145 ( V_4 -> V_334 ) ;
if ( V_4 -> V_336 )
F_145 ( V_4 -> V_336 ) ;
if ( V_4 -> V_338 ) {
F_143 ( & V_4 -> V_339 ) ;
F_145 ( V_4 -> V_338 ) ;
V_4 -> V_341 = false ;
F_144 ( & V_4 -> V_339 ) ;
}
if ( V_4 -> V_342 )
F_145 ( V_4 -> V_342 ) ;
}
return 0 ;
V_343:
if ( V_4 -> V_342 )
F_145 ( V_4 -> V_342 ) ;
V_340:
if ( V_4 -> V_336 )
F_145 ( V_4 -> V_336 ) ;
V_337:
F_145 ( V_4 -> V_334 ) ;
V_335:
F_145 ( V_4 -> V_333 ) ;
return V_93 ;
}
static int F_146 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_311 * V_157 = NULL ;
char V_344 [ V_345 ] ;
char V_346 [ V_345 + 3 ] ;
int V_347 ;
int V_294 = V_4 -> V_294 ;
V_4 -> V_157 = NULL ;
if ( V_4 -> V_348 ) {
V_157 = F_147 ( V_35 , V_4 -> V_348 ,
& F_131 , 0 ,
V_4 -> V_151 ) ;
if ( ! V_157 )
return - V_349 ;
} else {
for ( V_347 = 0 ; ( V_347 < V_350 ) ; V_347 ++ ) {
if ( ( V_4 -> V_318 -> V_351 & ( 1 << V_347 ) ) )
continue;
if ( V_4 -> V_318 -> V_352 [ V_347 ] == NULL )
continue;
if ( V_4 -> V_318 -> V_352 [ V_347 ] -> V_347 == 0 )
continue;
if ( V_294 -- )
continue;
F_148 ( V_344 , V_4 -> V_318 -> V_353 , V_345 ) ;
break;
}
if ( V_347 >= V_350 ) {
F_11 ( V_35 , L_14 ) ;
F_148 ( V_344 , L_15 , V_345 ) ;
V_347 = 0 ;
}
snprintf ( V_346 , sizeof( V_346 ) ,
V_354 , V_344 , V_347 ) ;
V_157 = F_149 ( V_35 , V_346 , & F_131 ,
V_4 -> V_151 ) ;
}
if ( F_150 ( V_157 ) ) {
F_28 ( V_35 , L_16 ) ;
return F_151 ( V_157 ) ;
}
if ( V_4 -> V_74 & V_355 ) {
V_157 -> V_356 &= V_357 ;
V_157 -> V_356 &= ~ V_358 ;
#if ! F_66 ( V_146 )
V_157 -> V_356 |= V_359 ;
#endif
}
else
V_157 -> V_356 &= V_360 ;
V_157 -> V_361 = V_157 -> V_356 ;
V_4 -> V_157 = V_157 ;
V_4 -> V_188 = 0 ;
V_4 -> V_141 = 0 ;
F_11 ( V_35 , L_17 ,
V_4 -> V_157 -> V_362 -> V_363 , F_152 ( & V_4 -> V_157 -> V_87 ) ,
V_4 -> V_157 -> V_293 ) ;
return 0 ;
}
static int F_153 ( struct V_364 * V_86 )
{
static struct V_318 * V_365 ;
struct V_34 * V_35 = F_154 ( V_86 ) ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_304 * V_366 ;
int V_367 = - V_368 , V_28 ;
T_4 V_369 , V_370 ;
if ( ( V_4 -> V_74 & V_371 ) && V_4 -> V_294 > 0 ) {
if ( V_372 && V_365 ) {
V_4 -> V_318 = V_365 ;
V_372 ++ ;
return 0 ;
}
return - V_373 ;
}
V_4 -> V_313 = 0 ;
V_369 = F_155 ( F_156 ( V_4 -> V_334 ) , 5000000 ) ;
if ( V_4 -> V_74 & V_135 )
V_369 -- ;
if ( V_369 > 63 ) {
F_157 ( & V_86 -> V_87 ,
L_18 ,
F_156 ( V_4 -> V_334 ) ) ;
V_367 = - V_374 ;
goto V_375;
}
V_370 = F_155 ( F_156 ( V_4 -> V_334 ) , 100000000 ) - 1 ;
V_4 -> V_144 = V_369 << 1 | V_370 << 8 ;
F_33 ( V_4 -> V_144 , V_4 -> V_97 + V_145 ) ;
V_4 -> V_318 = F_158 () ;
if ( V_4 -> V_318 == NULL ) {
V_367 = - V_239 ;
goto V_375;
}
V_4 -> V_318 -> V_363 = L_19 ;
V_4 -> V_318 -> V_376 = F_133 ;
V_4 -> V_318 -> V_377 = F_140 ;
snprintf ( V_4 -> V_318 -> V_353 , V_345 , L_20 ,
V_86 -> V_363 , V_4 -> V_294 + 1 ) ;
V_4 -> V_318 -> V_322 = V_4 ;
V_4 -> V_318 -> V_378 = & V_86 -> V_87 ;
V_4 -> V_318 -> V_293 = F_159 ( sizeof( int ) * V_350 , V_379 ) ;
if ( ! V_4 -> V_318 -> V_293 ) {
V_367 = - V_239 ;
goto V_380;
}
for ( V_28 = 0 ; V_28 < V_350 ; V_28 ++ )
V_4 -> V_318 -> V_293 [ V_28 ] = V_381 ;
V_366 = F_160 ( V_86 -> V_87 . V_306 , L_21 ) ;
if ( V_366 ) {
V_367 = F_161 ( V_4 -> V_318 , V_366 ) ;
F_162 ( V_366 ) ;
} else {
V_367 = F_163 ( V_4 -> V_318 ) ;
}
if ( V_367 )
goto V_382;
V_372 ++ ;
if ( V_4 -> V_74 & V_371 )
V_365 = V_4 -> V_318 ;
return 0 ;
V_382:
F_164 ( V_4 -> V_318 -> V_293 ) ;
V_380:
F_165 ( V_4 -> V_318 ) ;
V_375:
return V_367 ;
}
static void F_166 ( struct V_3 * V_4 )
{
if ( -- V_372 == 0 ) {
F_167 ( V_4 -> V_318 ) ;
F_164 ( V_4 -> V_318 -> V_293 ) ;
F_165 ( V_4 -> V_318 ) ;
}
}
static int F_168 ( struct V_34 * V_35 ,
struct V_383 * V_384 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_311 * V_385 = V_4 -> V_157 ;
if ( ! V_385 )
return - V_349 ;
return F_169 ( V_385 , V_384 ) ;
}
static int F_170 ( struct V_34 * V_35 ,
struct V_383 * V_384 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_311 * V_385 = V_4 -> V_157 ;
if ( ! V_385 )
return - V_349 ;
return F_171 ( V_385 , V_384 ) ;
}
static void F_172 ( struct V_34 * V_35 ,
struct V_386 * V_387 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_148 ( V_387 -> V_388 , V_4 -> V_86 -> V_87 . V_388 -> V_363 ,
sizeof( V_387 -> V_388 ) ) ;
F_148 ( V_387 -> V_45 , L_22 , sizeof( V_387 -> V_45 ) ) ;
F_148 ( V_387 -> V_389 , F_152 ( & V_35 -> V_87 ) , sizeof( V_387 -> V_389 ) ) ;
}
static int F_173 ( struct V_34 * V_35 ,
struct V_390 * V_387 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
if ( V_4 -> V_7 ) {
V_387 -> V_391 = V_392 |
V_393 |
V_394 |
V_395 |
V_396 |
V_397 ;
if ( V_4 -> V_298 )
V_387 -> V_398 = F_174 ( V_4 -> V_298 ) ;
else
V_387 -> V_398 = - 1 ;
V_387 -> V_399 = ( 1 << V_400 ) |
( 1 << V_401 ) ;
V_387 -> V_402 = ( 1 << V_403 ) |
( 1 << V_404 ) ;
return 0 ;
} else {
return F_175 ( V_35 , V_387 ) ;
}
}
static void F_176 ( struct V_34 * V_35 ,
struct V_405 * V_171 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
V_171 -> V_406 = ( V_4 -> V_168 & V_170 ) != 0 ;
V_171 -> V_407 = ( V_4 -> V_168 & V_169 ) != 0 ;
V_171 -> V_408 = V_171 -> V_407 ;
}
static int F_177 ( struct V_34 * V_35 ,
struct V_405 * V_171 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
if ( ! V_4 -> V_157 )
return - V_349 ;
if ( V_171 -> V_407 != V_171 -> V_408 ) {
F_11 ( V_35 ,
L_23 ) ;
return - V_374 ;
}
V_4 -> V_168 = 0 ;
V_4 -> V_168 |= V_171 -> V_408 ? V_169 : 0 ;
V_4 -> V_168 |= V_171 -> V_406 ? V_170 : 0 ;
if ( V_171 -> V_408 || V_171 -> V_406 ) {
V_4 -> V_157 -> V_356 |= V_409 ;
V_4 -> V_157 -> V_361 |= V_409 ;
} else {
V_4 -> V_157 -> V_356 &= ~ V_409 ;
V_4 -> V_157 -> V_361 &= ~ V_409 ;
}
if ( V_171 -> V_406 ) {
if ( F_77 ( V_35 ) )
F_71 ( V_35 ) ;
F_178 ( V_4 -> V_157 ) ;
}
if ( F_77 ( V_35 ) ) {
F_78 ( & V_4 -> V_209 ) ;
F_79 ( V_35 ) ;
F_63 ( V_35 ) ;
F_80 ( V_35 ) ;
F_81 ( V_35 ) ;
F_82 ( & V_4 -> V_209 ) ;
}
return 0 ;
}
static void F_179 ( struct V_34 * V_87 ,
struct V_410 * V_203 , T_5 * V_95 )
{
struct V_3 * V_4 = F_10 ( V_87 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < F_180 ( V_411 ) ; V_28 ++ )
V_95 [ V_28 ] = F_46 ( V_4 -> V_97 + V_411 [ V_28 ] . V_412 ) ;
}
static void F_181 ( struct V_34 * V_208 ,
T_4 V_413 , T_11 * V_95 )
{
int V_28 ;
switch ( V_413 ) {
case V_414 :
for ( V_28 = 0 ; V_28 < F_180 ( V_411 ) ; V_28 ++ )
memcpy ( V_95 + V_28 * V_415 ,
V_411 [ V_28 ] . V_363 , V_415 ) ;
break;
}
}
static int F_182 ( struct V_34 * V_87 , int V_416 )
{
switch ( V_416 ) {
case V_414 :
return F_180 ( V_411 ) ;
default:
return - V_417 ;
}
}
static int F_183 ( struct V_34 * V_87 )
{
struct V_3 * V_4 = F_10 ( V_87 ) ;
struct V_311 * V_385 = V_4 -> V_157 ;
if ( ! V_385 )
return - V_349 ;
return F_184 ( V_385 ) ;
}
static int F_185 ( struct V_34 * V_35 , int V_418 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
return V_418 * ( V_4 -> V_419 / 64000 ) / 1000 ;
}
static void F_186 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_420 , V_421 ;
if ( ! ( V_4 -> V_74 & V_75 ) )
return;
if ( ! V_4 -> V_422 || ! V_4 -> V_423 ||
! V_4 -> V_424 || ! V_4 -> V_425 )
return;
V_420 = V_426 ;
V_421 = V_426 ;
V_420 |= F_187 ( V_4 -> V_423 ) ;
V_420 |= F_188 ( F_185 ( V_35 , V_4 -> V_422 ) ) ;
V_421 |= F_187 ( V_4 -> V_425 ) ;
V_421 |= F_188 ( F_185 ( V_35 , V_4 -> V_424 ) ) ;
V_420 |= V_427 ;
V_421 |= V_427 ;
F_33 ( V_421 , V_4 -> V_97 + V_428 ) ;
F_33 ( V_420 , V_4 -> V_97 + V_429 ) ;
F_33 ( V_421 , V_4 -> V_97 + V_430 ) ;
F_33 ( V_420 , V_4 -> V_97 + V_431 ) ;
F_33 ( V_421 , V_4 -> V_97 + V_432 ) ;
F_33 ( V_420 , V_4 -> V_97 + V_433 ) ;
}
static int
F_189 ( struct V_34 * V_35 , struct V_434 * V_435 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
if ( ! ( V_4 -> V_74 & V_75 ) )
return - V_417 ;
V_435 -> V_436 = V_4 -> V_422 ;
V_435 -> V_437 = V_4 -> V_423 ;
V_435 -> V_438 = V_4 -> V_424 ;
V_435 -> V_439 = V_4 -> V_425 ;
return 0 ;
}
static int
F_190 ( struct V_34 * V_35 , struct V_434 * V_435 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
unsigned int V_440 ;
if ( ! ( V_4 -> V_74 & V_75 ) )
return - V_417 ;
if ( V_435 -> V_437 > 255 ) {
F_191 ( L_24 ) ;
return - V_374 ;
}
if ( V_435 -> V_439 > 255 ) {
F_191 ( L_25 ) ;
return - V_374 ;
}
V_440 = F_185 ( V_35 , V_4 -> V_422 ) ;
if ( V_440 > 0xFFFF ) {
F_191 ( L_26 ) ;
return - V_374 ;
}
V_440 = F_185 ( V_35 , V_4 -> V_424 ) ;
if ( V_440 > 0xFFFF ) {
F_191 ( L_26 ) ;
return - V_374 ;
}
V_4 -> V_422 = V_435 -> V_436 ;
V_4 -> V_423 = V_435 -> V_437 ;
V_4 -> V_424 = V_435 -> V_438 ;
V_4 -> V_425 = V_435 -> V_439 ;
F_186 ( V_35 ) ;
return 0 ;
}
static void F_70 ( struct V_34 * V_35 )
{
struct V_434 V_435 ;
V_435 . V_436 = V_441 ;
V_435 . V_437 = V_442 ;
V_435 . V_438 = V_441 ;
V_435 . V_439 = V_442 ;
F_190 ( V_35 , & V_435 ) ;
}
static int F_192 ( struct V_34 * V_208 ,
const struct V_443 * V_444 ,
void * V_95 )
{
struct V_3 * V_4 = F_10 ( V_208 ) ;
int V_93 = 0 ;
switch ( V_444 -> V_353 ) {
case V_445 :
* ( T_4 * ) V_95 = V_4 -> V_243 ;
break;
default:
V_93 = - V_374 ;
break;
}
return V_93 ;
}
static int F_193 ( struct V_34 * V_208 ,
const struct V_443 * V_444 ,
const void * V_95 )
{
struct V_3 * V_4 = F_10 ( V_208 ) ;
int V_93 = 0 ;
switch ( V_444 -> V_353 ) {
case V_445 :
V_4 -> V_243 = * ( T_4 * ) V_95 ;
break;
default:
V_93 = - V_374 ;
break;
}
return V_93 ;
}
static void
F_194 ( struct V_34 * V_35 , struct V_446 * V_447 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
if ( V_4 -> V_197 & V_448 ) {
V_447 -> V_356 = V_449 ;
V_447 -> V_450 = V_4 -> V_197 & V_451 ? V_449 : 0 ;
} else {
V_447 -> V_356 = V_447 -> V_450 = 0 ;
}
}
static int
F_195 ( struct V_34 * V_35 , struct V_446 * V_447 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
if ( ! ( V_4 -> V_197 & V_448 ) )
return - V_374 ;
if ( V_447 -> V_450 & ~ V_449 )
return - V_374 ;
F_196 ( & V_35 -> V_87 , V_447 -> V_450 & V_449 ) ;
if ( F_197 ( & V_35 -> V_87 ) ) {
V_4 -> V_197 |= V_451 ;
if ( V_4 -> V_293 [ 0 ] > 0 )
F_198 ( V_4 -> V_293 [ 0 ] ) ;
} else {
V_4 -> V_197 &= ( ~ V_451 ) ;
if ( V_4 -> V_293 [ 0 ] > 0 )
F_199 ( V_4 -> V_293 [ 0 ] ) ;
}
return 0 ;
}
static int F_200 ( struct V_34 * V_35 , struct V_452 * V_453 , int V_384 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_311 * V_385 = V_4 -> V_157 ;
if ( ! F_77 ( V_35 ) )
return - V_374 ;
if ( ! V_385 )
return - V_349 ;
if ( V_4 -> V_7 ) {
if ( V_384 == V_454 )
return F_201 ( V_35 , V_453 ) ;
if ( V_384 == V_455 )
return F_202 ( V_35 , V_453 ) ;
}
return F_203 ( V_385 , V_453 , V_384 ) ;
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
V_42 = V_13 -> V_267 [ V_28 ] ;
V_13 -> V_267 [ V_28 ] = NULL ;
if ( V_42 ) {
F_29 ( & V_4 -> V_86 -> V_87 ,
V_2 -> V_38 ,
V_237 - V_4 -> V_236 ,
V_238 ) ;
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
V_10 = F_209 ( sizeof( * V_10 ) , V_379 ) ;
if ( ! V_10 ) {
V_93 = - V_239 ;
goto V_456;
}
V_4 -> V_11 [ V_28 ] = V_10 ;
V_10 -> V_19 = V_457 ;
V_4 -> V_458 += V_4 -> V_11 [ V_28 ] -> V_19 ;
V_10 -> V_117 = V_459 ;
V_10 -> V_233 =
( V_10 -> V_19 - V_10 -> V_117 ) / 2 ;
V_10 -> V_104 = F_210 ( NULL ,
V_10 -> V_19 * V_105 ,
& V_10 -> V_106 ,
V_379 ) ;
if ( ! V_10 -> V_104 ) {
V_93 = - V_239 ;
goto V_456;
}
}
for ( V_28 = 0 ; V_28 < V_4 -> V_119 ; V_28 ++ ) {
V_4 -> V_14 [ V_28 ] = F_209 ( sizeof( * V_4 -> V_14 [ V_28 ] ) ,
V_379 ) ;
if ( ! V_4 -> V_14 [ V_28 ] ) {
V_93 = - V_239 ;
goto V_456;
}
V_4 -> V_14 [ V_28 ] -> V_21 = V_460 ;
V_4 -> V_461 += V_4 -> V_14 [ V_28 ] -> V_21 ;
}
return V_93 ;
V_456:
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
V_42 = F_101 ( V_35 , V_237 ) ;
if ( ! V_42 )
goto V_462;
if ( F_98 ( V_35 , V_2 , V_42 ) ) {
F_205 ( V_42 ) ;
goto V_462;
}
V_13 -> V_267 [ V_28 ] = V_42 ;
V_2 -> V_37 = V_120 ;
if ( V_4 -> V_7 ) {
struct V_7 * V_53 = (struct V_7 * ) V_2 ;
V_53 -> V_79 = V_283 ;
}
V_2 = F_1 ( V_2 , V_4 , V_55 ) ;
}
V_2 = F_2 ( V_2 , V_4 , V_55 ) ;
V_2 -> V_37 |= V_121 ;
return 0 ;
V_462:
F_204 ( V_35 ) ;
return - V_239 ;
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
V_10 -> V_85 [ V_28 ] = F_159 ( V_463 , V_379 ) ;
if ( ! V_10 -> V_85 [ V_28 ] )
goto V_462;
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
V_462:
F_204 ( V_35 ) ;
return - V_239 ;
}
static int F_213 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_119 ; V_28 ++ )
if ( F_211 ( V_35 , V_28 ) )
return - V_239 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_123 ; V_28 ++ )
if ( F_212 ( V_35 , V_28 ) )
return - V_239 ;
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
goto V_464;
V_93 = F_146 ( V_35 ) ;
if ( V_93 )
goto V_465;
F_63 ( V_35 ) ;
F_82 ( & V_4 -> V_209 ) ;
F_216 ( V_4 -> V_157 ) ;
F_217 ( V_35 ) ;
F_196 ( & V_35 -> V_87 , V_4 -> V_197 &
V_451 ) ;
return 0 ;
V_465:
F_204 ( V_35 ) ;
V_464:
F_141 ( V_35 , false ) ;
F_218 ( & V_4 -> V_86 -> V_87 ) ;
return V_93 ;
}
static int
F_219 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_220 ( V_4 -> V_157 ) ;
if ( F_76 ( V_35 ) ) {
F_78 ( & V_4 -> V_209 ) ;
F_221 ( V_35 ) ;
F_71 ( V_35 ) ;
}
F_222 ( V_4 -> V_157 ) ;
V_4 -> V_157 = NULL ;
F_141 ( V_35 , false ) ;
F_218 ( & V_4 -> V_86 -> V_87 ) ;
F_204 ( V_35 ) ;
return 0 ;
}
static void F_68 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_466 * V_467 ;
unsigned int V_28 , V_468 , V_95 , V_469 , V_470 ;
unsigned char V_471 ;
if ( V_35 -> V_213 & V_472 ) {
V_470 = F_46 ( V_4 -> V_97 + V_183 ) ;
V_470 |= 0x8 ;
F_33 ( V_470 , V_4 -> V_97 + V_183 ) ;
return;
}
V_470 = F_46 ( V_4 -> V_97 + V_183 ) ;
V_470 &= ~ 0x8 ;
F_33 ( V_470 , V_4 -> V_97 + V_183 ) ;
if ( V_35 -> V_213 & V_473 ) {
F_33 ( 0xffffffff , V_4 -> V_97 + V_474 ) ;
F_33 ( 0xffffffff , V_4 -> V_97 + V_475 ) ;
return;
}
F_33 ( 0 , V_4 -> V_97 + V_474 ) ;
F_33 ( 0 , V_4 -> V_97 + V_475 ) ;
F_223 (ha, ndev) {
V_469 = 0xffffffff ;
for ( V_28 = 0 ; V_28 < V_35 -> V_476 ; V_28 ++ ) {
V_95 = V_467 -> V_61 [ V_28 ] ;
for ( V_468 = 0 ; V_468 < 8 ; V_468 ++ , V_95 >>= 1 ) {
V_469 = ( V_469 >> 1 ) ^
( ( ( V_469 ^ V_95 ) & 1 ) ? V_477 : 0 ) ;
}
}
V_471 = ( V_469 >> ( 32 - V_478 ) ) & 0x3f ;
if ( V_471 > 31 ) {
V_470 = F_46 ( V_4 -> V_97 + V_474 ) ;
V_470 |= 1 << ( V_471 - 32 ) ;
F_33 ( V_470 , V_4 -> V_97 + V_474 ) ;
} else {
V_470 = F_46 ( V_4 -> V_97 + V_475 ) ;
V_470 |= 1 << V_471 ;
F_33 ( V_470 , V_4 -> V_97 + V_475 ) ;
}
}
}
static int
F_224 ( struct V_34 * V_35 , void * V_81 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_479 * V_61 = V_81 ;
if ( V_61 ) {
if ( ! F_127 ( V_61 -> V_480 ) )
return - V_481 ;
memcpy ( V_35 -> V_136 , V_61 -> V_480 , V_35 -> V_476 ) ;
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
for ( V_28 = 0 ; V_28 < V_482 ; V_28 ++ ) {
if ( V_4 -> V_293 [ V_28 ] > 0 ) {
F_226 ( V_4 -> V_293 [ V_28 ] ) ;
F_118 ( V_4 -> V_293 [ V_28 ] , V_87 ) ;
F_227 ( V_4 -> V_293 [ V_28 ] ) ;
}
}
}
static inline void F_228 ( struct V_34 * V_208 ,
T_12 V_270 )
{
struct V_3 * V_4 = F_10 ( V_208 ) ;
T_12 V_483 = V_270 ^ V_208 -> V_270 ;
V_208 -> V_270 = V_270 ;
if ( V_483 & V_484 ) {
if ( V_270 & V_484 )
V_4 -> V_148 |= V_149 ;
else
V_4 -> V_148 &= ~ V_149 ;
}
}
static int F_229 ( struct V_34 * V_208 ,
T_12 V_270 )
{
struct V_3 * V_4 = F_10 ( V_208 ) ;
T_12 V_483 = V_270 ^ V_208 -> V_270 ;
if ( F_77 ( V_208 ) && V_483 & V_485 ) {
F_78 ( & V_4 -> V_209 ) ;
F_79 ( V_208 ) ;
F_71 ( V_208 ) ;
F_228 ( V_208 , V_270 ) ;
F_63 ( V_208 ) ;
F_230 ( V_208 ) ;
F_81 ( V_208 ) ;
F_82 ( & V_4 -> V_209 ) ;
} else {
F_228 ( V_208 , V_270 ) ;
}
return 0 ;
}
static int F_231 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
struct V_1 * V_486 ;
T_2 V_124 ;
int V_487 ;
unsigned int V_28 ;
#if F_66 ( V_488 )
V_4 -> V_236 = 0xf ;
V_4 -> V_83 = 0xf ;
#else
V_4 -> V_236 = 0x3 ;
V_4 -> V_83 = 0x3 ;
#endif
F_208 ( V_35 ) ;
if ( V_4 -> V_7 )
V_4 -> V_22 = sizeof( struct V_7 ) ;
else
V_4 -> V_22 = sizeof( struct V_1 ) ;
V_487 = ( V_4 -> V_458 + V_4 -> V_461 ) *
V_4 -> V_22 ;
V_486 = F_210 ( NULL , V_487 , & V_124 ,
V_379 ) ;
if ( ! V_486 ) {
return - V_239 ;
}
memset ( V_486 , 0 , V_487 ) ;
F_125 ( V_35 ) ;
F_224 ( V_35 , NULL ) ;
for ( V_28 = 0 ; V_28 < V_4 -> V_119 ; V_28 ++ ) {
V_13 = V_4 -> V_14 [ V_28 ] ;
V_13 -> V_36 = V_28 ;
V_13 -> V_20 = (struct V_1 * ) V_486 ;
V_13 -> V_124 = V_124 ;
if ( V_4 -> V_7 ) {
V_124 += sizeof( struct V_7 ) * V_13 -> V_21 ;
V_486 = (struct V_1 * )
( ( (struct V_7 * ) V_486 ) + V_13 -> V_21 ) ;
} else {
V_124 += sizeof( struct V_1 ) * V_13 -> V_21 ;
V_486 += V_13 -> V_21 ;
}
}
for ( V_28 = 0 ; V_28 < V_4 -> V_123 ; V_28 ++ ) {
V_10 = V_4 -> V_11 [ V_28 ] ;
V_10 -> V_36 = V_28 ;
V_10 -> V_18 = (struct V_1 * ) V_486 ;
V_10 -> V_124 = V_124 ;
if ( V_4 -> V_7 ) {
V_124 += sizeof( struct V_7 ) * V_10 -> V_19 ;
V_486 = (struct V_1 * )
( ( (struct V_7 * ) V_486 ) + V_10 -> V_19 ) ;
} else {
V_124 += sizeof( struct V_1 ) * V_10 -> V_19 ;
V_486 += V_10 -> V_19 ;
}
}
V_35 -> V_489 = V_490 ;
V_35 -> V_491 = & V_492 ;
V_35 -> V_493 = & V_494 ;
F_33 ( V_495 , V_4 -> V_97 + V_190 ) ;
F_232 ( V_35 , & V_4 -> V_209 , F_123 , V_496 ) ;
if ( V_4 -> V_74 & V_497 )
V_35 -> V_270 |= V_271 ;
if ( V_4 -> V_74 & V_498 ) {
V_35 -> V_499 = V_500 ;
V_35 -> V_270 |= ( V_501 | V_502
| V_484 | V_503 | V_504 ) ;
V_4 -> V_148 |= V_149 ;
}
if ( V_4 -> V_74 & V_75 ) {
V_4 -> V_83 = 0 ;
V_4 -> V_236 = 0x3f ;
}
V_35 -> V_505 = V_35 -> V_270 ;
F_63 ( V_35 ) ;
return 0 ;
}
static void F_233 ( struct V_364 * V_86 )
{
int V_367 , V_506 ;
int V_507 = 1 ;
struct V_304 * V_305 = V_86 -> V_87 . V_306 ;
if ( ! V_305 )
return;
F_234 ( V_305 , L_27 , & V_507 ) ;
if ( V_507 > 1000 )
V_507 = 1 ;
V_506 = F_235 ( V_305 , L_28 , 0 ) ;
if ( ! F_236 ( V_506 ) )
return;
V_367 = F_237 ( & V_86 -> V_87 , V_506 ,
V_508 , L_29 ) ;
if ( V_367 ) {
F_157 ( & V_86 -> V_87 , L_30 , V_367 ) ;
return;
}
F_238 ( V_507 ) ;
F_239 ( V_506 , 1 ) ;
}
static void F_233 ( struct V_364 * V_86 )
{
}
static void
F_240 ( struct V_364 * V_86 , int * V_509 , int * V_510 )
{
struct V_304 * V_305 = V_86 -> V_87 . V_306 ;
int V_367 ;
* V_509 = * V_510 = 1 ;
if ( ! V_305 || ! F_241 ( V_305 ) )
return;
V_367 = F_234 ( V_305 , L_31 , V_509 ) ;
if ( V_367 )
* V_509 = 1 ;
V_367 = F_234 ( V_305 , L_32 , V_510 ) ;
if ( V_367 )
* V_510 = 1 ;
if ( * V_509 < 1 || * V_509 > V_511 ) {
F_242 ( & V_86 -> V_87 , L_33 ,
* V_509 ) ;
* V_509 = 1 ;
return;
}
if ( * V_510 < 1 || * V_510 > V_512 ) {
F_242 ( & V_86 -> V_87 , L_34 ,
* V_510 ) ;
* V_510 = 1 ;
return;
}
}
static int
F_243 ( struct V_364 * V_86 )
{
struct V_3 * V_4 ;
struct V_192 * V_193 ;
struct V_34 * V_35 ;
int V_28 , V_293 , V_93 = 0 ;
struct V_513 * V_514 ;
const struct V_515 * V_516 ;
static int V_294 ;
struct V_304 * V_305 = V_86 -> V_87 . V_306 , * V_348 ;
int V_517 ;
int V_518 ;
F_240 ( V_86 , & V_517 , & V_518 ) ;
V_35 = F_244 ( sizeof( struct V_3 ) ,
V_517 , V_518 ) ;
if ( ! V_35 )
return - V_239 ;
F_245 ( V_35 , & V_86 -> V_87 ) ;
V_4 = F_10 ( V_35 ) ;
V_516 = F_246 ( V_519 , & V_86 -> V_87 ) ;
if ( V_516 )
V_86 -> V_520 = V_516 -> V_95 ;
V_4 -> V_74 = V_86 -> V_520 -> V_521 ;
V_4 -> V_208 = V_35 ;
V_4 -> V_119 = V_518 ;
V_4 -> V_123 = V_517 ;
#if ! F_66 ( V_146 )
if ( V_4 -> V_74 & V_355 )
V_4 -> V_168 |= V_170 ;
#endif
F_215 ( & V_86 -> V_87 ) ;
V_514 = F_247 ( V_86 , V_522 , 0 ) ;
V_4 -> V_97 = F_248 ( & V_86 -> V_87 , V_514 ) ;
if ( F_150 ( V_4 -> V_97 ) ) {
V_93 = F_151 ( V_4 -> V_97 ) ;
goto V_523;
}
V_4 -> V_86 = V_86 ;
V_4 -> V_294 = V_294 ++ ;
F_249 ( V_86 , V_35 ) ;
if ( F_250 ( V_305 , L_35 , NULL ) )
V_4 -> V_197 |= V_448 ;
V_348 = F_251 ( V_305 , L_36 , 0 ) ;
if ( ! V_348 && F_252 ( V_305 ) ) {
V_93 = F_253 ( V_305 ) ;
if ( V_93 < 0 ) {
F_157 ( & V_86 -> V_87 ,
L_37 ) ;
goto V_524;
}
V_348 = F_254 ( V_305 ) ;
}
V_4 -> V_348 = V_348 ;
V_93 = F_255 ( V_86 -> V_87 . V_306 ) ;
if ( V_93 < 0 ) {
V_193 = F_126 ( & V_86 -> V_87 ) ;
if ( V_193 )
V_4 -> V_151 = V_193 -> V_525 ;
else
V_4 -> V_151 = V_526 ;
} else {
V_4 -> V_151 = V_93 ;
}
V_4 -> V_334 = F_256 ( & V_86 -> V_87 , L_38 ) ;
if ( F_150 ( V_4 -> V_334 ) ) {
V_93 = F_151 ( V_4 -> V_334 ) ;
goto V_527;
}
V_4 -> V_333 = F_256 ( & V_86 -> V_87 , L_39 ) ;
if ( F_150 ( V_4 -> V_333 ) ) {
V_93 = F_151 ( V_4 -> V_333 ) ;
goto V_527;
}
V_4 -> V_419 = F_156 ( V_4 -> V_333 ) ;
V_4 -> V_336 = F_256 ( & V_86 -> V_87 , L_40 ) ;
if ( F_150 ( V_4 -> V_336 ) )
V_4 -> V_336 = NULL ;
V_4 -> V_341 = false ;
F_257 ( & V_4 -> V_339 ) ;
V_4 -> V_342 = F_256 ( & V_86 -> V_87 , L_41 ) ;
if ( F_150 ( V_4 -> V_342 ) )
V_4 -> V_342 = NULL ;
V_4 -> V_7 = V_4 -> V_74 & V_528 ;
V_4 -> V_338 = F_256 ( & V_86 -> V_87 , L_42 ) ;
if ( F_150 ( V_4 -> V_338 ) ) {
V_4 -> V_338 = NULL ;
V_4 -> V_7 = false ;
}
V_93 = F_141 ( V_35 , true ) ;
if ( V_93 )
goto V_527;
V_4 -> V_529 = F_258 ( & V_86 -> V_87 , L_43 ) ;
if ( ! F_150 ( V_4 -> V_529 ) ) {
V_93 = F_259 ( V_4 -> V_529 ) ;
if ( V_93 ) {
F_157 ( & V_86 -> V_87 ,
L_44 , V_93 ) ;
goto V_530;
}
} else {
V_4 -> V_529 = NULL ;
}
F_233 ( V_86 ) ;
if ( V_4 -> V_7 )
F_260 ( V_86 ) ;
V_93 = F_231 ( V_35 ) ;
if ( V_93 )
goto V_531;
for ( V_28 = 0 ; V_28 < V_482 ; V_28 ++ ) {
V_293 = F_261 ( V_86 , V_28 ) ;
if ( V_293 < 0 ) {
if ( V_28 )
break;
V_93 = V_293 ;
goto V_532;
}
V_93 = F_262 ( & V_86 -> V_87 , V_293 , F_118 ,
0 , V_86 -> V_363 , V_35 ) ;
if ( V_93 )
goto V_532;
V_4 -> V_293 [ V_28 ] = V_293 ;
}
F_134 ( & V_4 -> V_297 ) ;
V_93 = F_153 ( V_86 ) ;
if ( V_93 )
goto V_533;
F_263 ( V_35 ) ;
F_141 ( V_35 , false ) ;
F_218 ( & V_86 -> V_87 ) ;
V_93 = F_264 ( V_35 ) ;
if ( V_93 )
goto V_534;
F_265 ( & V_35 -> V_87 , V_4 -> V_197 &
V_448 ) ;
if ( V_4 -> V_7 && V_4 -> V_298 )
F_11 ( V_35 , L_45 , V_4 -> V_294 ) ;
V_4 -> V_243 = V_535 ;
F_266 ( & V_4 -> V_205 , F_74 ) ;
return 0 ;
V_534:
F_166 ( V_4 ) ;
V_533:
V_532:
V_531:
if ( V_4 -> V_529 )
F_267 ( V_4 -> V_529 ) ;
V_530:
F_141 ( V_35 , false ) ;
V_527:
V_524:
F_162 ( V_348 ) ;
V_523:
F_268 ( V_35 ) ;
return V_93 ;
}
static int
F_269 ( struct V_364 * V_86 )
{
struct V_34 * V_35 = F_154 ( V_86 ) ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_270 ( & V_4 -> V_536 ) ;
F_271 ( & V_4 -> V_205 ) ;
F_272 ( V_35 ) ;
F_166 ( V_4 ) ;
if ( V_4 -> V_529 )
F_267 ( V_4 -> V_529 ) ;
if ( V_4 -> V_298 )
F_273 ( V_4 -> V_298 ) ;
F_162 ( V_4 -> V_348 ) ;
F_268 ( V_35 ) ;
return 0 ;
}
static int T_13 F_274 ( struct V_537 * V_87 )
{
struct V_34 * V_35 = F_275 ( V_87 ) ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_75 () ;
if ( F_77 ( V_35 ) ) {
if ( V_4 -> V_197 & V_451 )
V_4 -> V_197 |= V_198 ;
F_220 ( V_4 -> V_157 ) ;
F_78 ( & V_4 -> V_209 ) ;
F_79 ( V_35 ) ;
F_276 ( V_35 ) ;
F_81 ( V_35 ) ;
F_71 ( V_35 ) ;
F_141 ( V_35 , false ) ;
if ( ! ( V_4 -> V_197 & V_451 ) )
F_218 ( & V_4 -> V_86 -> V_87 ) ;
}
F_83 () ;
if ( V_4 -> V_529 && ! ( V_4 -> V_197 & V_451 ) )
F_267 ( V_4 -> V_529 ) ;
if ( V_4 -> V_336 || V_4 -> V_529 )
V_4 -> V_188 = 0 ;
return 0 ;
}
static int T_13 F_277 ( struct V_537 * V_87 )
{
struct V_34 * V_35 = F_275 ( V_87 ) ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_192 * V_193 = V_4 -> V_86 -> V_87 . V_194 ;
int V_93 ;
int V_129 ;
if ( V_4 -> V_529 && ! ( V_4 -> V_197 & V_451 ) ) {
V_93 = F_259 ( V_4 -> V_529 ) ;
if ( V_93 )
return V_93 ;
}
F_75 () ;
if ( F_77 ( V_35 ) ) {
V_93 = F_141 ( V_35 , true ) ;
if ( V_93 ) {
F_83 () ;
goto V_527;
}
if ( V_4 -> V_197 & V_451 ) {
if ( V_193 && V_193 -> V_202 )
V_193 -> V_202 ( false ) ;
V_129 = F_46 ( V_4 -> V_97 + V_134 ) ;
V_129 &= ~ ( V_200 | V_201 ) ;
F_33 ( V_129 , V_4 -> V_97 + V_134 ) ;
V_4 -> V_197 &= ~ V_198 ;
} else {
F_215 ( & V_4 -> V_86 -> V_87 ) ;
}
F_63 ( V_35 ) ;
F_79 ( V_35 ) ;
F_278 ( V_35 ) ;
F_81 ( V_35 ) ;
F_82 ( & V_4 -> V_209 ) ;
F_216 ( V_4 -> V_157 ) ;
}
F_83 () ;
return 0 ;
V_527:
if ( V_4 -> V_529 )
F_267 ( V_4 -> V_529 ) ;
return V_93 ;
}
