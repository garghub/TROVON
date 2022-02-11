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
if ( V_4 -> V_74 & V_147 ) {
V_129 = F_46 ( V_4 -> V_97 + V_148 ) ;
if ( V_4 -> V_149 & V_150 )
V_129 |= V_151 ;
else
V_129 &= ~ V_151 ;
F_33 ( V_129 , V_4 -> V_97 + V_148 ) ;
}
#endif
if ( V_4 -> V_74 & V_135 ) {
V_131 |= 0x40000000 | 0x00000020 ;
if ( V_4 -> V_152 == V_153 ||
V_4 -> V_152 == V_154 ||
V_4 -> V_152 == V_155 ||
V_4 -> V_152 == V_156 )
V_131 |= ( 1 << 6 ) ;
else if ( V_4 -> V_152 == V_157 )
V_131 |= ( 1 << 8 ) ;
else
V_131 &= ~ ( 1 << 8 ) ;
if ( V_4 -> V_158 ) {
if ( V_4 -> V_158 -> V_159 == V_160 )
V_133 |= ( 1 << 5 ) ;
else if ( V_4 -> V_158 -> V_159 == V_161 )
V_131 &= ~ ( 1 << 9 ) ;
else
V_131 |= ( 1 << 9 ) ;
}
} else {
#ifdef F_67
if ( V_4 -> V_74 & V_162 ) {
T_4 V_163 ;
F_33 ( 0 , V_4 -> V_97 + F_67 ) ;
while ( F_46 ( V_4 -> V_97 + F_67 ) & 4 )
F_64 ( 1 ) ;
V_163 = ( V_4 -> V_152 == V_157 )
? V_164 : V_165 ;
if ( V_4 -> V_158 && V_4 -> V_158 -> V_159 == V_166 )
V_163 |= V_167 ;
F_33 ( V_163 , V_4 -> V_97 + V_168 ) ;
F_33 ( 2 , V_4 -> V_97 + F_67 ) ;
}
#endif
}
#if ! F_66 ( V_146 )
if ( ( V_4 -> V_169 & V_170 ) ||
( ( V_4 -> V_169 & V_171 ) &&
V_4 -> V_158 && V_4 -> V_158 -> V_172 ) ) {
V_131 |= V_173 ;
F_33 ( V_174 , V_4 -> V_97 + V_175 ) ;
F_33 ( V_176 , V_4 -> V_97 + V_177 ) ;
F_33 ( V_178 , V_4 -> V_97 + V_179 ) ;
F_33 ( V_180 , V_4 -> V_97 + V_181 ) ;
F_33 ( V_182 , V_4 -> V_97 + V_183 ) ;
} else {
V_131 &= ~ V_173 ;
}
#endif
F_33 ( V_131 , V_4 -> V_97 + V_184 ) ;
F_68 ( V_35 ) ;
#ifndef V_146
F_33 ( 0 , V_4 -> V_97 + V_185 ) ;
F_33 ( 0 , V_4 -> V_97 + V_186 ) ;
#endif
if ( V_4 -> V_74 & V_135 ) {
V_133 |= ( 1 << 8 ) ;
F_33 ( 1 << 8 , V_4 -> V_97 + V_187 ) ;
}
if ( V_4 -> V_7 )
V_133 |= ( 1 << 4 ) ;
#ifndef V_146
F_33 ( 0 << 31 , V_4 -> V_97 + V_188 ) ;
#endif
F_33 ( V_133 , V_4 -> V_97 + V_134 ) ;
F_52 ( V_35 ) ;
if ( V_4 -> V_7 )
F_69 ( V_35 ) ;
if ( V_4 -> V_189 )
F_33 ( V_190 , V_4 -> V_97 + V_191 ) ;
else
F_33 ( V_192 , V_4 -> V_97 + V_191 ) ;
F_70 ( V_35 ) ;
}
static void
F_71 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_193 * V_194 = V_4 -> V_86 -> V_87 . V_195 ;
T_4 V_196 = F_46 ( V_4 -> V_97 + V_184 ) & ( 1 << 8 ) ;
T_4 V_129 ;
if ( V_4 -> V_189 ) {
F_33 ( 1 , V_4 -> V_97 + V_143 ) ;
F_64 ( 10 ) ;
if ( ! ( F_46 ( V_4 -> V_97 + V_140 ) & V_197 ) )
F_28 ( V_35 , L_7 ) ;
}
if ( ! ( V_4 -> V_198 & V_199 ) ) {
if ( V_4 -> V_74 & V_75 ) {
F_33 ( 0 , V_4 -> V_97 + V_134 ) ;
} else {
F_33 ( 1 , V_4 -> V_97 + V_134 ) ;
F_64 ( 10 ) ;
}
F_33 ( V_190 , V_4 -> V_97 + V_191 ) ;
} else {
F_33 ( V_190 | V_200 , V_4 -> V_97 + V_191 ) ;
V_129 = F_46 ( V_4 -> V_97 + V_134 ) ;
V_129 |= ( V_201 | V_202 ) ;
F_33 ( V_129 , V_4 -> V_97 + V_134 ) ;
if ( V_194 && V_194 -> V_203 )
V_194 -> V_203 ( true ) ;
}
F_33 ( V_4 -> V_144 , V_4 -> V_97 + V_145 ) ;
if ( V_4 -> V_74 & V_135 &&
! ( V_4 -> V_198 & V_199 ) ) {
F_33 ( 2 , V_4 -> V_97 + V_134 ) ;
F_33 ( V_196 , V_4 -> V_97 + V_184 ) ;
}
}
static void
F_72 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_9 ( V_35 ) ;
V_35 -> V_204 . V_205 ++ ;
F_73 ( & V_4 -> V_206 ) ;
}
static void F_74 ( struct V_207 * V_208 )
{
struct V_3 * V_4 =
F_36 ( V_208 , struct V_3 , V_206 ) ;
struct V_34 * V_35 = V_4 -> V_209 ;
F_75 () ;
if ( F_76 ( V_35 ) || F_77 ( V_35 ) ) {
F_78 ( & V_4 -> V_210 ) ;
F_79 ( V_35 ) ;
F_63 ( V_35 ) ;
F_80 ( V_35 ) ;
F_81 ( V_35 ) ;
F_82 ( & V_4 -> V_210 ) ;
}
F_83 () ;
}
static void
F_84 ( struct V_3 * V_4 , unsigned V_211 ,
struct V_212 * V_213 )
{
unsigned long V_214 ;
T_5 V_215 ;
F_85 ( & V_4 -> V_216 , V_214 ) ;
V_215 = F_86 ( & V_4 -> V_217 , V_211 ) ;
F_87 ( & V_4 -> V_216 , V_214 ) ;
memset ( V_213 , 0 , sizeof( * V_213 ) ) ;
V_213 -> V_218 = F_88 ( V_215 ) ;
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
if ( V_58 & ( V_219 | V_220 |
V_221 | V_222 |
V_223 ) ) {
V_35 -> V_204 . V_205 ++ ;
if ( V_58 & V_219 )
V_35 -> V_204 . V_224 ++ ;
if ( V_58 & V_220 )
V_35 -> V_204 . V_225 ++ ;
if ( V_58 & V_221 )
V_35 -> V_204 . V_226 ++ ;
if ( V_58 & V_222 )
V_35 -> V_204 . V_227 ++ ;
if ( V_58 & V_223 )
V_35 -> V_204 . V_228 ++ ;
} else {
V_35 -> V_204 . V_229 ++ ;
V_35 -> V_204 . V_230 += V_42 -> V_27 ;
}
if ( F_17 ( F_20 ( V_42 ) -> V_70 & V_96 ) &&
V_4 -> V_7 ) {
struct V_212 V_231 ;
struct V_7 * V_53 = (struct V_7 * ) V_2 ;
F_84 ( V_4 , V_53 -> V_211 , & V_231 ) ;
F_92 ( V_42 , & V_231 ) ;
}
if ( V_58 & V_232 )
V_35 -> V_204 . V_233 ++ ;
F_26 ( V_42 ) ;
V_10 -> V_24 = V_2 ;
V_2 = F_1 ( V_2 , V_4 , V_5 ) ;
if ( F_93 ( V_35 ) ) {
V_92 = F_4 ( V_4 , V_10 ) ;
if ( V_92 >= V_10 -> V_234 )
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
F_97 ( V_5 , & V_4 -> V_235 ) ;
F_89 ( V_35 , V_5 ) ;
}
return;
}
static int
F_98 ( struct V_34 * V_35 , struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_236 ;
V_236 = ( ( unsigned long ) V_42 -> V_95 ) & V_4 -> V_237 ;
if ( V_236 )
F_99 ( V_42 , V_4 -> V_237 + 1 - V_236 ) ;
V_2 -> V_38 = F_24 ( & V_4 -> V_86 -> V_87 , V_42 -> V_95 ,
V_238 - V_4 -> V_237 ,
V_239 ) ;
if ( F_25 ( & V_4 -> V_86 -> V_87 , V_2 -> V_38 ) ) {
if ( F_27 () )
F_28 ( V_35 , L_8 ) ;
return - V_240 ;
}
return 0 ;
}
static bool F_100 ( struct V_34 * V_35 , struct V_41 * * V_42 ,
struct V_1 * V_2 , T_4 V_241 , bool V_242 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_41 * V_243 ;
if ( V_241 > V_4 -> V_244 )
return false ;
V_243 = F_101 ( V_35 , V_241 ) ;
if ( ! V_243 )
return false ;
F_102 ( & V_4 -> V_86 -> V_87 , V_2 -> V_38 ,
V_238 - V_4 -> V_237 ,
V_239 ) ;
if ( ! V_242 )
memcpy ( V_243 -> V_95 , ( * V_42 ) -> V_95 , V_241 ) ;
else
F_7 ( V_243 -> V_95 , ( * V_42 ) -> V_95 , V_241 ) ;
* V_42 = V_243 ;
return true ;
}
static int
F_103 ( struct V_34 * V_35 , int V_245 , T_6 V_5 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
unsigned short V_58 ;
struct V_41 * V_246 = NULL ;
struct V_41 * V_42 ;
T_7 V_247 ;
T_8 * V_95 ;
int V_248 = 0 ;
struct V_7 * V_53 = NULL ;
bool V_249 = false ;
T_6 V_250 ;
int V_36 = 0 ;
bool V_251 ;
bool V_252 = V_4 -> V_74 & V_84 ;
#ifdef F_104
F_105 () ;
#endif
V_5 = F_90 ( V_5 ) ;
V_13 = V_4 -> V_14 [ V_5 ] ;
V_2 = V_13 -> V_122 ;
while ( ! ( ( V_58 = V_2 -> V_37 ) & V_120 ) ) {
if ( V_248 >= V_245 )
break;
V_248 ++ ;
if ( ( V_58 & V_253 ) == 0 )
F_28 ( V_35 , L_9 ) ;
if ( V_58 & ( V_254 | V_255 | V_256 |
V_257 | V_258 ) ) {
V_35 -> V_204 . V_259 ++ ;
if ( V_58 & ( V_254 | V_255 ) ) {
V_35 -> V_204 . V_260 ++ ;
}
if ( V_58 & V_256 )
V_35 -> V_204 . V_261 ++ ;
if ( V_58 & V_257 )
V_35 -> V_204 . V_262 ++ ;
if ( V_58 & V_258 )
V_35 -> V_204 . V_263 ++ ;
}
if ( V_58 & V_264 ) {
V_35 -> V_204 . V_259 ++ ;
V_35 -> V_204 . V_261 ++ ;
goto V_265;
}
V_35 -> V_204 . V_266 ++ ;
V_247 = V_2 -> V_39 ;
V_35 -> V_204 . V_267 += V_247 ;
V_36 = F_3 ( V_13 -> V_20 , V_2 , V_4 ) ;
V_42 = V_13 -> V_268 [ V_36 ] ;
V_251 = F_100 ( V_35 , & V_42 , V_2 , V_247 - 4 ,
V_252 ) ;
if ( ! V_251 ) {
V_246 = F_101 ( V_35 , V_238 ) ;
if ( F_17 ( ! V_246 ) ) {
V_35 -> V_204 . V_269 ++ ;
goto V_265;
}
F_29 ( & V_4 -> V_86 -> V_87 , V_2 -> V_38 ,
V_238 - V_4 -> V_237 ,
V_239 ) ;
}
F_106 ( V_42 -> V_95 - V_270 ) ;
F_107 ( V_42 , V_247 - 4 ) ;
V_95 = V_42 -> V_95 ;
if ( ! V_251 && V_252 )
F_5 ( V_95 , V_247 ) ;
V_53 = NULL ;
if ( V_4 -> V_7 )
V_53 = (struct V_7 * ) V_2 ;
V_249 = false ;
if ( ( V_35 -> V_271 & V_272 ) &&
V_4 -> V_7 && ( V_53 -> V_79 & V_273 ) ) {
struct V_274 * V_275 =
(struct V_274 * ) ( V_95 + V_276 ) ;
V_250 = F_108 ( V_275 -> V_277 ) ;
V_249 = true ;
memmove ( V_42 -> V_95 + V_278 , V_95 , V_137 * 2 ) ;
F_109 ( V_42 , V_278 ) ;
}
V_42 -> V_43 = F_110 ( V_42 , V_35 ) ;
if ( V_4 -> V_279 && V_4 -> V_7 )
F_84 ( V_4 , V_53 -> V_211 ,
F_111 ( V_42 ) ) ;
if ( V_4 -> V_7 &&
( V_4 -> V_149 & V_150 ) ) {
if ( ! ( V_53 -> V_79 & V_280 ) ) {
V_42 -> V_46 = V_281 ;
} else {
F_112 ( V_42 ) ;
}
}
if ( V_249 )
F_113 ( V_42 ,
F_14 ( V_282 ) ,
V_250 ) ;
F_114 ( & V_4 -> V_210 , V_42 ) ;
if ( V_251 ) {
F_115 ( & V_4 -> V_86 -> V_87 , V_2 -> V_38 ,
V_238 - V_4 -> V_237 ,
V_239 ) ;
} else {
V_13 -> V_268 [ V_36 ] = V_246 ;
F_98 ( V_35 , V_2 , V_246 ) ;
}
V_265:
V_58 &= ~ V_283 ;
V_58 |= V_120 ;
V_2 -> V_37 = V_58 ;
if ( V_4 -> V_7 ) {
struct V_7 * V_53 = (struct V_7 * ) V_2 ;
V_53 -> V_79 = V_284 ;
V_53 -> V_285 = 0 ;
V_53 -> V_78 = 0 ;
}
V_2 = F_1 ( V_2 , V_4 , V_5 ) ;
F_33 ( 0 , V_4 -> V_97 + F_53 ( V_5 ) ) ;
}
V_13 -> V_122 = V_2 ;
return V_248 ;
}
static int
F_116 ( struct V_34 * V_35 , int V_245 )
{
int V_248 = 0 ;
T_6 V_5 ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_96 (queue_id, &fep->work_rx, FEC_ENET_MAX_RX_QS) {
F_97 ( V_5 , & V_4 -> V_286 ) ;
V_248 += F_103 ( V_35 ,
V_245 - V_248 , V_5 ) ;
}
return V_248 ;
}
static bool
F_117 ( struct V_3 * V_4 , T_9 V_287 )
{
if ( V_287 == 0 )
return false ;
if ( V_287 & V_288 )
V_4 -> V_286 |= ( 1 << 2 ) ;
if ( V_287 & V_289 )
V_4 -> V_286 |= ( 1 << 0 ) ;
if ( V_287 & V_290 )
V_4 -> V_286 |= ( 1 << 1 ) ;
if ( V_287 & V_291 )
V_4 -> V_235 |= ( 1 << 2 ) ;
if ( V_287 & V_292 )
V_4 -> V_235 |= ( 1 << 0 ) ;
if ( V_287 & V_293 )
V_4 -> V_235 |= ( 1 << 1 ) ;
return true ;
}
static T_10
F_118 ( int V_294 , void * V_295 )
{
struct V_34 * V_35 = V_295 ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
T_9 V_287 ;
T_10 V_93 = V_296 ;
V_287 = F_46 ( V_4 -> V_97 + V_140 ) ;
F_33 ( V_287 , V_4 -> V_97 + V_140 ) ;
F_117 ( V_4 , V_287 ) ;
if ( ( V_4 -> V_235 || V_4 -> V_286 ) && V_4 -> V_189 ) {
V_93 = V_297 ;
if ( F_119 ( & V_4 -> V_210 ) ) {
F_33 ( V_192 , V_4 -> V_97 + V_191 ) ;
F_120 ( & V_4 -> V_210 ) ;
}
}
if ( V_287 & V_192 ) {
V_93 = V_297 ;
F_121 ( & V_4 -> V_298 ) ;
}
if ( V_4 -> V_299 )
F_122 ( V_4 ) ;
return V_93 ;
}
static int F_123 ( struct V_300 * V_210 , int V_245 )
{
struct V_34 * V_35 = V_210 -> V_87 ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_301 ;
V_301 = F_116 ( V_35 , V_245 ) ;
F_95 ( V_35 ) ;
if ( V_301 < V_245 ) {
F_124 ( V_210 ) ;
F_33 ( V_190 , V_4 -> V_97 + V_191 ) ;
}
return V_301 ;
}
static void F_125 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_193 * V_194 = F_126 ( & V_4 -> V_86 -> V_87 ) ;
unsigned char * V_302 , V_303 [ V_137 ] ;
V_302 = V_304 ;
if ( ! F_127 ( V_302 ) ) {
struct V_305 * V_306 = V_4 -> V_86 -> V_87 . V_307 ;
if ( V_306 ) {
const char * V_308 = F_128 ( V_306 ) ;
if ( V_308 )
V_302 = ( unsigned char * ) V_308 ;
}
}
if ( ! F_127 ( V_302 ) ) {
#ifdef V_146
if ( V_309 )
V_302 = ( unsigned char * ) V_309 ;
#else
if ( V_194 )
V_302 = ( unsigned char * ) & V_194 -> V_308 ;
#endif
}
if ( ! F_127 ( V_302 ) ) {
* ( ( V_310 * ) & V_303 [ 0 ] ) =
F_65 ( F_46 ( V_4 -> V_97 + V_138 ) ) ;
* ( ( V_311 * ) & V_303 [ 4 ] ) =
F_129 ( F_46 ( V_4 -> V_97 + V_139 ) >> 16 ) ;
V_302 = & V_303 [ 0 ] ;
}
if ( ! F_127 ( V_302 ) ) {
F_28 ( V_35 , L_10 , V_302 ) ;
F_130 ( V_35 ) ;
F_11 ( V_35 , L_11 ,
V_35 -> V_136 ) ;
return;
}
memcpy ( V_35 -> V_136 , V_302 , V_137 ) ;
if ( V_302 == V_304 )
V_35 -> V_136 [ V_137 - 1 ] = V_304 [ V_137 - 1 ] + V_4 -> V_295 ;
}
static void F_131 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_312 * V_158 = V_4 -> V_158 ;
int V_313 = 0 ;
if ( V_4 -> V_314 && V_158 -> V_315 == V_316 ) {
V_158 -> V_315 = V_317 ;
return;
}
if ( ! F_77 ( V_35 ) || ! F_76 ( V_35 ) ) {
V_4 -> V_189 = 0 ;
} else if ( V_158 -> V_189 ) {
if ( ! V_4 -> V_189 ) {
V_4 -> V_189 = V_158 -> V_189 ;
V_313 = 1 ;
}
if ( V_4 -> V_141 != V_158 -> V_318 ) {
V_4 -> V_141 = V_158 -> V_318 ;
V_313 = 1 ;
}
if ( V_158 -> V_159 != V_4 -> V_159 ) {
V_4 -> V_159 = V_158 -> V_159 ;
V_313 = 1 ;
}
if ( V_313 ) {
F_78 ( & V_4 -> V_210 ) ;
F_79 ( V_35 ) ;
F_63 ( V_35 ) ;
F_80 ( V_35 ) ;
F_81 ( V_35 ) ;
F_82 ( & V_4 -> V_210 ) ;
}
} else {
if ( V_4 -> V_189 ) {
F_78 ( & V_4 -> V_210 ) ;
F_79 ( V_35 ) ;
F_71 ( V_35 ) ;
F_81 ( V_35 ) ;
F_82 ( & V_4 -> V_210 ) ;
V_4 -> V_189 = V_158 -> V_189 ;
V_313 = 1 ;
}
}
if ( V_313 )
F_132 ( V_158 ) ;
}
static int F_133 ( struct V_319 * V_320 , int V_321 , int V_322 )
{
struct V_3 * V_4 = V_320 -> V_323 ;
struct V_324 * V_87 = & V_4 -> V_86 -> V_87 ;
unsigned long V_325 ;
int V_93 = 0 ;
V_93 = F_134 ( V_87 ) ;
if ( F_135 ( V_93 ) )
return V_93 ;
V_4 -> V_314 = 0 ;
F_136 ( & V_4 -> V_298 ) ;
F_33 ( V_326 | V_327 |
F_137 ( V_321 ) | F_138 ( V_322 ) |
V_328 , V_4 -> V_97 + V_329 ) ;
V_325 = F_139 ( & V_4 -> V_298 ,
F_140 ( V_330 ) ) ;
if ( V_325 == 0 ) {
V_4 -> V_314 = 1 ;
F_28 ( V_4 -> V_209 , L_12 ) ;
V_93 = - V_331 ;
goto V_332;
}
V_93 = F_141 ( F_46 ( V_4 -> V_97 + V_329 ) ) ;
V_332:
F_142 ( V_87 ) ;
F_143 ( V_87 ) ;
return V_93 ;
}
static int F_144 ( struct V_319 * V_320 , int V_321 , int V_322 ,
T_6 V_333 )
{
struct V_3 * V_4 = V_320 -> V_323 ;
struct V_324 * V_87 = & V_4 -> V_86 -> V_87 ;
unsigned long V_325 ;
int V_93 = 0 ;
V_93 = F_134 ( V_87 ) ;
if ( F_135 ( V_93 ) )
return V_93 ;
V_4 -> V_314 = 0 ;
F_136 ( & V_4 -> V_298 ) ;
F_33 ( V_326 | V_334 |
F_137 ( V_321 ) | F_138 ( V_322 ) |
V_328 | F_141 ( V_333 ) ,
V_4 -> V_97 + V_329 ) ;
V_325 = F_139 ( & V_4 -> V_298 ,
F_140 ( V_330 ) ) ;
if ( V_325 == 0 ) {
V_4 -> V_314 = 1 ;
F_28 ( V_4 -> V_209 , L_13 ) ;
V_93 = - V_331 ;
}
F_142 ( V_87 ) ;
F_143 ( V_87 ) ;
return V_93 ;
}
static int F_145 ( struct V_34 * V_35 , bool V_335 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_93 ;
if ( V_335 ) {
V_93 = F_146 ( V_4 -> V_336 ) ;
if ( V_93 )
return V_93 ;
if ( V_4 -> V_337 ) {
V_93 = F_146 ( V_4 -> V_337 ) ;
if ( V_93 )
goto V_338;
}
if ( V_4 -> V_339 ) {
F_147 ( & V_4 -> V_340 ) ;
V_93 = F_146 ( V_4 -> V_339 ) ;
if ( V_93 ) {
F_148 ( & V_4 -> V_340 ) ;
goto V_341;
} else {
V_4 -> V_342 = true ;
}
F_148 ( & V_4 -> V_340 ) ;
}
if ( V_4 -> V_343 ) {
V_93 = F_146 ( V_4 -> V_343 ) ;
if ( V_93 )
goto V_344;
}
} else {
F_149 ( V_4 -> V_336 ) ;
if ( V_4 -> V_337 )
F_149 ( V_4 -> V_337 ) ;
if ( V_4 -> V_339 ) {
F_147 ( & V_4 -> V_340 ) ;
F_149 ( V_4 -> V_339 ) ;
V_4 -> V_342 = false ;
F_148 ( & V_4 -> V_340 ) ;
}
if ( V_4 -> V_343 )
F_149 ( V_4 -> V_343 ) ;
}
return 0 ;
V_344:
if ( V_4 -> V_343 )
F_149 ( V_4 -> V_343 ) ;
V_341:
if ( V_4 -> V_337 )
F_149 ( V_4 -> V_337 ) ;
V_338:
F_149 ( V_4 -> V_336 ) ;
return V_93 ;
}
static int F_150 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_312 * V_158 = NULL ;
char V_345 [ V_346 ] ;
char V_347 [ V_346 + 3 ] ;
int V_348 ;
int V_295 = V_4 -> V_295 ;
V_4 -> V_158 = NULL ;
if ( V_4 -> V_349 ) {
V_158 = F_151 ( V_35 , V_4 -> V_349 ,
& F_131 , 0 ,
V_4 -> V_152 ) ;
if ( ! V_158 )
return - V_350 ;
} else {
for ( V_348 = 0 ; ( V_348 < V_351 ) ; V_348 ++ ) {
if ( ( V_4 -> V_319 -> V_352 & ( 1 << V_348 ) ) )
continue;
if ( V_4 -> V_319 -> V_353 [ V_348 ] == NULL )
continue;
if ( V_4 -> V_319 -> V_353 [ V_348 ] -> V_348 == 0 )
continue;
if ( V_295 -- )
continue;
F_152 ( V_345 , V_4 -> V_319 -> V_354 , V_346 ) ;
break;
}
if ( V_348 >= V_351 ) {
F_11 ( V_35 , L_14 ) ;
F_152 ( V_345 , L_15 , V_346 ) ;
V_348 = 0 ;
}
snprintf ( V_347 , sizeof( V_347 ) ,
V_355 , V_345 , V_348 ) ;
V_158 = F_153 ( V_35 , V_347 , & F_131 ,
V_4 -> V_152 ) ;
}
if ( F_154 ( V_158 ) ) {
F_28 ( V_35 , L_16 ) ;
return F_155 ( V_158 ) ;
}
if ( V_4 -> V_74 & V_356 ) {
V_158 -> V_357 &= V_358 ;
V_158 -> V_357 &= ~ V_359 ;
#if ! F_66 ( V_146 )
V_158 -> V_357 |= V_360 ;
#endif
}
else
V_158 -> V_357 &= V_361 ;
V_158 -> V_362 = V_158 -> V_357 ;
V_4 -> V_158 = V_158 ;
V_4 -> V_189 = 0 ;
V_4 -> V_141 = 0 ;
F_11 ( V_35 , L_17 ,
V_4 -> V_158 -> V_363 -> V_364 , F_156 ( & V_4 -> V_158 -> V_87 ) ,
V_4 -> V_158 -> V_294 ) ;
return 0 ;
}
static int F_157 ( struct V_365 * V_86 )
{
static struct V_319 * V_366 ;
struct V_34 * V_35 = F_158 ( V_86 ) ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_305 * V_367 ;
int V_368 = - V_369 , V_28 ;
T_4 V_370 , V_371 ;
if ( ( V_4 -> V_74 & V_372 ) && V_4 -> V_295 > 0 ) {
if ( V_373 && V_366 ) {
V_4 -> V_319 = V_366 ;
V_373 ++ ;
return 0 ;
}
return - V_374 ;
}
V_4 -> V_314 = 0 ;
V_370 = F_159 ( F_160 ( V_4 -> V_375 ) , 5000000 ) ;
if ( V_4 -> V_74 & V_135 )
V_370 -- ;
if ( V_370 > 63 ) {
F_161 ( & V_86 -> V_87 ,
L_18 ,
F_160 ( V_4 -> V_375 ) ) ;
V_368 = - V_376 ;
goto V_377;
}
V_371 = F_159 ( F_160 ( V_4 -> V_375 ) , 100000000 ) - 1 ;
V_4 -> V_144 = V_370 << 1 | V_371 << 8 ;
F_33 ( V_4 -> V_144 , V_4 -> V_97 + V_145 ) ;
V_4 -> V_319 = F_162 () ;
if ( V_4 -> V_319 == NULL ) {
V_368 = - V_240 ;
goto V_377;
}
V_4 -> V_319 -> V_364 = L_19 ;
V_4 -> V_319 -> V_378 = F_133 ;
V_4 -> V_319 -> V_379 = F_144 ;
snprintf ( V_4 -> V_319 -> V_354 , V_346 , L_20 ,
V_86 -> V_364 , V_4 -> V_295 + 1 ) ;
V_4 -> V_319 -> V_323 = V_4 ;
V_4 -> V_319 -> V_380 = & V_86 -> V_87 ;
V_4 -> V_319 -> V_294 = F_163 ( sizeof( int ) * V_351 , V_381 ) ;
if ( ! V_4 -> V_319 -> V_294 ) {
V_368 = - V_240 ;
goto V_382;
}
for ( V_28 = 0 ; V_28 < V_351 ; V_28 ++ )
V_4 -> V_319 -> V_294 [ V_28 ] = V_383 ;
V_367 = F_164 ( V_86 -> V_87 . V_307 , L_21 ) ;
if ( V_367 ) {
V_368 = F_165 ( V_4 -> V_319 , V_367 ) ;
F_166 ( V_367 ) ;
} else {
V_368 = F_167 ( V_4 -> V_319 ) ;
}
if ( V_368 )
goto V_384;
V_373 ++ ;
if ( V_4 -> V_74 & V_372 )
V_366 = V_4 -> V_319 ;
return 0 ;
V_384:
F_168 ( V_4 -> V_319 -> V_294 ) ;
V_382:
F_169 ( V_4 -> V_319 ) ;
V_377:
return V_368 ;
}
static void F_170 ( struct V_3 * V_4 )
{
if ( -- V_373 == 0 ) {
F_171 ( V_4 -> V_319 ) ;
F_168 ( V_4 -> V_319 -> V_294 ) ;
F_169 ( V_4 -> V_319 ) ;
}
}
static int F_172 ( struct V_34 * V_35 ,
struct V_385 * V_386 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_312 * V_387 = V_4 -> V_158 ;
if ( ! V_387 )
return - V_350 ;
return F_173 ( V_387 , V_386 ) ;
}
static int F_174 ( struct V_34 * V_35 ,
struct V_385 * V_386 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_312 * V_387 = V_4 -> V_158 ;
if ( ! V_387 )
return - V_350 ;
return F_175 ( V_387 , V_386 ) ;
}
static void F_176 ( struct V_34 * V_35 ,
struct V_388 * V_389 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_152 ( V_389 -> V_390 , V_4 -> V_86 -> V_87 . V_390 -> V_364 ,
sizeof( V_389 -> V_390 ) ) ;
F_152 ( V_389 -> V_45 , L_22 , sizeof( V_389 -> V_45 ) ) ;
F_152 ( V_389 -> V_391 , F_156 ( & V_35 -> V_87 ) , sizeof( V_389 -> V_391 ) ) ;
}
static int F_177 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_392 * V_393 ;
int V_394 = 0 ;
V_393 = F_178 ( V_4 -> V_86 , V_395 , 0 ) ;
if ( V_393 )
V_394 = F_179 ( V_393 ) ;
return V_394 ;
}
static void F_180 ( struct V_34 * V_35 ,
struct V_396 * V_397 , void * V_398 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
T_4 T_11 * V_399 = ( T_4 T_11 * ) V_4 -> V_97 ;
T_4 * V_29 = ( T_4 * ) V_398 ;
T_4 V_28 , V_236 ;
memset ( V_29 , 0 , V_397 -> V_27 ) ;
for ( V_28 = 0 ; V_28 < F_181 ( V_400 ) ; V_28 ++ ) {
V_236 = V_400 [ V_28 ] / 4 ;
V_29 [ V_236 ] = F_46 ( & V_399 [ V_236 ] ) ;
}
}
static int F_182 ( struct V_34 * V_35 ,
struct V_401 * V_389 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
if ( V_4 -> V_7 ) {
V_389 -> V_402 = V_403 |
V_404 |
V_405 |
V_406 |
V_407 |
V_408 ;
if ( V_4 -> V_299 )
V_389 -> V_409 = F_183 ( V_4 -> V_299 ) ;
else
V_389 -> V_409 = - 1 ;
V_389 -> V_410 = ( 1 << V_411 ) |
( 1 << V_412 ) ;
V_389 -> V_413 = ( 1 << V_414 ) |
( 1 << V_415 ) ;
return 0 ;
} else {
return F_184 ( V_35 , V_389 ) ;
}
}
static void F_185 ( struct V_34 * V_35 ,
struct V_416 * V_172 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
V_172 -> V_417 = ( V_4 -> V_169 & V_171 ) != 0 ;
V_172 -> V_418 = ( V_4 -> V_169 & V_170 ) != 0 ;
V_172 -> V_419 = V_172 -> V_418 ;
}
static int F_186 ( struct V_34 * V_35 ,
struct V_416 * V_172 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
if ( ! V_4 -> V_158 )
return - V_350 ;
if ( V_172 -> V_418 != V_172 -> V_419 ) {
F_11 ( V_35 ,
L_23 ) ;
return - V_376 ;
}
V_4 -> V_169 = 0 ;
V_4 -> V_169 |= V_172 -> V_419 ? V_170 : 0 ;
V_4 -> V_169 |= V_172 -> V_417 ? V_171 : 0 ;
if ( V_172 -> V_419 || V_172 -> V_417 ) {
V_4 -> V_158 -> V_357 |= V_420 ;
V_4 -> V_158 -> V_362 |= V_420 ;
} else {
V_4 -> V_158 -> V_357 &= ~ V_420 ;
V_4 -> V_158 -> V_362 &= ~ V_420 ;
}
if ( V_172 -> V_417 ) {
if ( F_77 ( V_35 ) )
F_71 ( V_35 ) ;
F_187 ( V_4 -> V_158 ) ;
}
if ( F_77 ( V_35 ) ) {
F_78 ( & V_4 -> V_210 ) ;
F_79 ( V_35 ) ;
F_63 ( V_35 ) ;
F_80 ( V_35 ) ;
F_81 ( V_35 ) ;
F_82 ( & V_4 -> V_210 ) ;
}
return 0 ;
}
static void F_188 ( struct V_34 * V_87 ,
struct V_421 * V_204 , T_5 * V_95 )
{
struct V_3 * V_4 = F_10 ( V_87 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < F_181 ( V_422 ) ; V_28 ++ )
V_95 [ V_28 ] = F_46 ( V_4 -> V_97 + V_422 [ V_28 ] . V_423 ) ;
}
static void F_189 ( struct V_34 * V_209 ,
T_4 V_424 , T_12 * V_95 )
{
int V_28 ;
switch ( V_424 ) {
case V_425 :
for ( V_28 = 0 ; V_28 < F_181 ( V_422 ) ; V_28 ++ )
memcpy ( V_95 + V_28 * V_426 ,
V_422 [ V_28 ] . V_364 , V_426 ) ;
break;
}
}
static int F_190 ( struct V_34 * V_87 , int V_427 )
{
switch ( V_427 ) {
case V_425 :
return F_181 ( V_422 ) ;
default:
return - V_428 ;
}
}
static int F_191 ( struct V_34 * V_87 )
{
struct V_3 * V_4 = F_10 ( V_87 ) ;
struct V_312 * V_387 = V_4 -> V_158 ;
if ( ! V_387 )
return - V_350 ;
return F_192 ( V_387 ) ;
}
static int F_193 ( struct V_34 * V_35 , int V_429 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
return V_429 * ( V_4 -> V_430 / 64000 ) / 1000 ;
}
static void F_194 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_431 , V_432 ;
if ( ! ( V_4 -> V_74 & V_75 ) )
return;
if ( ! V_4 -> V_433 || ! V_4 -> V_434 ||
! V_4 -> V_435 || ! V_4 -> V_436 )
return;
V_431 = V_437 ;
V_432 = V_437 ;
V_431 |= F_195 ( V_4 -> V_434 ) ;
V_431 |= F_196 ( F_193 ( V_35 , V_4 -> V_433 ) ) ;
V_432 |= F_195 ( V_4 -> V_436 ) ;
V_432 |= F_196 ( F_193 ( V_35 , V_4 -> V_435 ) ) ;
V_431 |= V_438 ;
V_432 |= V_438 ;
F_33 ( V_432 , V_4 -> V_97 + V_439 ) ;
F_33 ( V_431 , V_4 -> V_97 + V_440 ) ;
F_33 ( V_432 , V_4 -> V_97 + V_441 ) ;
F_33 ( V_431 , V_4 -> V_97 + V_442 ) ;
F_33 ( V_432 , V_4 -> V_97 + V_443 ) ;
F_33 ( V_431 , V_4 -> V_97 + V_444 ) ;
}
static int
F_197 ( struct V_34 * V_35 , struct V_445 * V_446 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
if ( ! ( V_4 -> V_74 & V_75 ) )
return - V_428 ;
V_446 -> V_447 = V_4 -> V_433 ;
V_446 -> V_448 = V_4 -> V_434 ;
V_446 -> V_449 = V_4 -> V_435 ;
V_446 -> V_450 = V_4 -> V_436 ;
return 0 ;
}
static int
F_198 ( struct V_34 * V_35 , struct V_445 * V_446 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
unsigned int V_451 ;
if ( ! ( V_4 -> V_74 & V_75 ) )
return - V_428 ;
if ( V_446 -> V_448 > 255 ) {
F_199 ( L_24 ) ;
return - V_376 ;
}
if ( V_446 -> V_450 > 255 ) {
F_199 ( L_25 ) ;
return - V_376 ;
}
V_451 = F_193 ( V_35 , V_4 -> V_433 ) ;
if ( V_451 > 0xFFFF ) {
F_199 ( L_26 ) ;
return - V_376 ;
}
V_451 = F_193 ( V_35 , V_4 -> V_435 ) ;
if ( V_451 > 0xFFFF ) {
F_199 ( L_26 ) ;
return - V_376 ;
}
V_4 -> V_433 = V_446 -> V_447 ;
V_4 -> V_434 = V_446 -> V_448 ;
V_4 -> V_435 = V_446 -> V_449 ;
V_4 -> V_436 = V_446 -> V_450 ;
F_194 ( V_35 ) ;
return 0 ;
}
static void F_70 ( struct V_34 * V_35 )
{
struct V_445 V_446 ;
V_446 . V_447 = V_452 ;
V_446 . V_448 = V_453 ;
V_446 . V_449 = V_452 ;
V_446 . V_450 = V_453 ;
F_198 ( V_35 , & V_446 ) ;
}
static int F_200 ( struct V_34 * V_209 ,
const struct V_454 * V_455 ,
void * V_95 )
{
struct V_3 * V_4 = F_10 ( V_209 ) ;
int V_93 = 0 ;
switch ( V_455 -> V_354 ) {
case V_456 :
* ( T_4 * ) V_95 = V_4 -> V_244 ;
break;
default:
V_93 = - V_376 ;
break;
}
return V_93 ;
}
static int F_201 ( struct V_34 * V_209 ,
const struct V_454 * V_455 ,
const void * V_95 )
{
struct V_3 * V_4 = F_10 ( V_209 ) ;
int V_93 = 0 ;
switch ( V_455 -> V_354 ) {
case V_456 :
V_4 -> V_244 = * ( T_4 * ) V_95 ;
break;
default:
V_93 = - V_376 ;
break;
}
return V_93 ;
}
static void
F_202 ( struct V_34 * V_35 , struct V_457 * V_458 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
if ( V_4 -> V_198 & V_459 ) {
V_458 -> V_357 = V_460 ;
V_458 -> V_461 = V_4 -> V_198 & V_462 ? V_460 : 0 ;
} else {
V_458 -> V_357 = V_458 -> V_461 = 0 ;
}
}
static int
F_203 ( struct V_34 * V_35 , struct V_457 * V_458 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
if ( ! ( V_4 -> V_198 & V_459 ) )
return - V_376 ;
if ( V_458 -> V_461 & ~ V_460 )
return - V_376 ;
F_204 ( & V_35 -> V_87 , V_458 -> V_461 & V_460 ) ;
if ( F_205 ( & V_35 -> V_87 ) ) {
V_4 -> V_198 |= V_462 ;
if ( V_4 -> V_294 [ 0 ] > 0 )
F_206 ( V_4 -> V_294 [ 0 ] ) ;
} else {
V_4 -> V_198 &= ( ~ V_462 ) ;
if ( V_4 -> V_294 [ 0 ] > 0 )
F_207 ( V_4 -> V_294 [ 0 ] ) ;
}
return 0 ;
}
static int F_208 ( struct V_34 * V_35 , struct V_463 * V_464 , int V_386 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_312 * V_387 = V_4 -> V_158 ;
if ( ! F_77 ( V_35 ) )
return - V_376 ;
if ( ! V_387 )
return - V_350 ;
if ( V_4 -> V_7 ) {
if ( V_386 == V_465 )
return F_209 ( V_35 , V_464 ) ;
if ( V_386 == V_466 )
return F_210 ( V_35 , V_464 ) ;
}
return F_211 ( V_387 , V_464 , V_386 ) ;
}
static void F_212 ( struct V_34 * V_35 )
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
V_42 = V_13 -> V_268 [ V_28 ] ;
V_13 -> V_268 [ V_28 ] = NULL ;
if ( V_42 ) {
F_29 ( & V_4 -> V_86 -> V_87 ,
V_2 -> V_38 ,
V_238 - V_4 -> V_237 ,
V_239 ) ;
F_213 ( V_42 ) ;
}
V_2 = F_1 ( V_2 , V_4 , V_118 ) ;
}
}
for ( V_118 = 0 ; V_118 < V_4 -> V_123 ; V_118 ++ ) {
V_10 = V_4 -> V_11 [ V_118 ] ;
V_2 = V_10 -> V_18 ;
for ( V_28 = 0 ; V_28 < V_10 -> V_19 ; V_28 ++ ) {
F_168 ( V_10 -> V_85 [ V_28 ] ) ;
V_10 -> V_85 [ V_28 ] = NULL ;
V_42 = V_10 -> V_40 [ V_28 ] ;
V_10 -> V_40 [ V_28 ] = NULL ;
F_213 ( V_42 ) ;
}
}
}
static void F_214 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_28 ;
struct V_9 * V_10 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_123 ; V_28 ++ )
if ( V_4 -> V_11 [ V_28 ] && V_4 -> V_11 [ V_28 ] -> V_104 ) {
V_10 = V_4 -> V_11 [ V_28 ] ;
F_215 ( NULL ,
V_10 -> V_19 * V_105 ,
V_10 -> V_104 ,
V_10 -> V_106 ) ;
}
for ( V_28 = 0 ; V_28 < V_4 -> V_119 ; V_28 ++ )
F_168 ( V_4 -> V_14 [ V_28 ] ) ;
for ( V_28 = 0 ; V_28 < V_4 -> V_123 ; V_28 ++ )
F_168 ( V_4 -> V_11 [ V_28 ] ) ;
}
static int F_216 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_28 ;
int V_93 = 0 ;
struct V_9 * V_10 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_123 ; V_28 ++ ) {
V_10 = F_217 ( sizeof( * V_10 ) , V_381 ) ;
if ( ! V_10 ) {
V_93 = - V_240 ;
goto V_467;
}
V_4 -> V_11 [ V_28 ] = V_10 ;
V_10 -> V_19 = V_468 ;
V_4 -> V_469 += V_4 -> V_11 [ V_28 ] -> V_19 ;
V_10 -> V_117 = V_470 ;
V_10 -> V_234 =
( V_10 -> V_19 - V_10 -> V_117 ) / 2 ;
V_10 -> V_104 = F_218 ( NULL ,
V_10 -> V_19 * V_105 ,
& V_10 -> V_106 ,
V_381 ) ;
if ( ! V_10 -> V_104 ) {
V_93 = - V_240 ;
goto V_467;
}
}
for ( V_28 = 0 ; V_28 < V_4 -> V_119 ; V_28 ++ ) {
V_4 -> V_14 [ V_28 ] = F_217 ( sizeof( * V_4 -> V_14 [ V_28 ] ) ,
V_381 ) ;
if ( ! V_4 -> V_14 [ V_28 ] ) {
V_93 = - V_240 ;
goto V_467;
}
V_4 -> V_14 [ V_28 ] -> V_21 = V_471 ;
V_4 -> V_472 += V_4 -> V_14 [ V_28 ] -> V_21 ;
}
return V_93 ;
V_467:
F_214 ( V_35 ) ;
return V_93 ;
}
static int
F_219 ( struct V_34 * V_35 , unsigned int V_55 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
unsigned int V_28 ;
struct V_41 * V_42 ;
struct V_1 * V_2 ;
struct V_12 * V_13 ;
V_13 = V_4 -> V_14 [ V_55 ] ;
V_2 = V_13 -> V_20 ;
for ( V_28 = 0 ; V_28 < V_13 -> V_21 ; V_28 ++ ) {
V_42 = F_101 ( V_35 , V_238 ) ;
if ( ! V_42 )
goto V_473;
if ( F_98 ( V_35 , V_2 , V_42 ) ) {
F_213 ( V_42 ) ;
goto V_473;
}
V_13 -> V_268 [ V_28 ] = V_42 ;
V_2 -> V_37 = V_120 ;
if ( V_4 -> V_7 ) {
struct V_7 * V_53 = (struct V_7 * ) V_2 ;
V_53 -> V_79 = V_284 ;
}
V_2 = F_1 ( V_2 , V_4 , V_55 ) ;
}
V_2 = F_2 ( V_2 , V_4 , V_55 ) ;
V_2 -> V_37 |= V_121 ;
return 0 ;
V_473:
F_212 ( V_35 ) ;
return - V_240 ;
}
static int
F_220 ( struct V_34 * V_35 , unsigned int V_55 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
unsigned int V_28 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
V_10 = V_4 -> V_11 [ V_55 ] ;
V_2 = V_10 -> V_18 ;
for ( V_28 = 0 ; V_28 < V_10 -> V_19 ; V_28 ++ ) {
V_10 -> V_85 [ V_28 ] = F_163 ( V_474 , V_381 ) ;
if ( ! V_10 -> V_85 [ V_28 ] )
goto V_473;
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
V_473:
F_212 ( V_35 ) ;
return - V_240 ;
}
static int F_221 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_119 ; V_28 ++ )
if ( F_219 ( V_35 , V_28 ) )
return - V_240 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_123 ; V_28 ++ )
if ( F_220 ( V_35 , V_28 ) )
return - V_240 ;
return 0 ;
}
static int
F_222 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_93 ;
V_93 = F_134 ( & V_4 -> V_86 -> V_87 ) ;
if ( F_135 ( V_93 ) )
return V_93 ;
F_223 ( & V_4 -> V_86 -> V_87 ) ;
V_93 = F_145 ( V_35 , true ) ;
if ( V_93 )
goto V_475;
V_93 = F_221 ( V_35 ) ;
if ( V_93 )
goto V_476;
F_63 ( V_35 ) ;
V_93 = F_150 ( V_35 ) ;
if ( V_93 )
goto V_477;
F_82 ( & V_4 -> V_210 ) ;
F_224 ( V_4 -> V_158 ) ;
F_225 ( V_35 ) ;
F_204 ( & V_35 -> V_87 , V_4 -> V_198 &
V_462 ) ;
return 0 ;
V_477:
F_212 ( V_35 ) ;
V_476:
F_145 ( V_35 , false ) ;
V_475:
F_142 ( & V_4 -> V_86 -> V_87 ) ;
F_143 ( & V_4 -> V_86 -> V_87 ) ;
F_226 ( & V_4 -> V_86 -> V_87 ) ;
return V_93 ;
}
static int
F_227 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_228 ( V_4 -> V_158 ) ;
if ( F_76 ( V_35 ) ) {
F_78 ( & V_4 -> V_210 ) ;
F_229 ( V_35 ) ;
F_71 ( V_35 ) ;
}
F_230 ( V_4 -> V_158 ) ;
V_4 -> V_158 = NULL ;
F_145 ( V_35 , false ) ;
F_226 ( & V_4 -> V_86 -> V_87 ) ;
F_142 ( & V_4 -> V_86 -> V_87 ) ;
F_143 ( & V_4 -> V_86 -> V_87 ) ;
F_212 ( V_35 ) ;
return 0 ;
}
static void F_68 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_478 * V_479 ;
unsigned int V_28 , V_480 , V_95 , V_481 , V_482 ;
unsigned char V_483 ;
if ( V_35 -> V_214 & V_484 ) {
V_482 = F_46 ( V_4 -> V_97 + V_184 ) ;
V_482 |= 0x8 ;
F_33 ( V_482 , V_4 -> V_97 + V_184 ) ;
return;
}
V_482 = F_46 ( V_4 -> V_97 + V_184 ) ;
V_482 &= ~ 0x8 ;
F_33 ( V_482 , V_4 -> V_97 + V_184 ) ;
if ( V_35 -> V_214 & V_485 ) {
F_33 ( 0xffffffff , V_4 -> V_97 + V_486 ) ;
F_33 ( 0xffffffff , V_4 -> V_97 + V_487 ) ;
return;
}
F_33 ( 0 , V_4 -> V_97 + V_486 ) ;
F_33 ( 0 , V_4 -> V_97 + V_487 ) ;
F_231 (ha, ndev) {
V_481 = 0xffffffff ;
for ( V_28 = 0 ; V_28 < V_35 -> V_488 ; V_28 ++ ) {
V_95 = V_479 -> V_61 [ V_28 ] ;
for ( V_480 = 0 ; V_480 < 8 ; V_480 ++ , V_95 >>= 1 ) {
V_481 = ( V_481 >> 1 ) ^
( ( ( V_481 ^ V_95 ) & 1 ) ? V_489 : 0 ) ;
}
}
V_483 = ( V_481 >> ( 32 - V_490 ) ) & 0x3f ;
if ( V_483 > 31 ) {
V_482 = F_46 ( V_4 -> V_97 + V_486 ) ;
V_482 |= 1 << ( V_483 - 32 ) ;
F_33 ( V_482 , V_4 -> V_97 + V_486 ) ;
} else {
V_482 = F_46 ( V_4 -> V_97 + V_487 ) ;
V_482 |= 1 << V_483 ;
F_33 ( V_482 , V_4 -> V_97 + V_487 ) ;
}
}
}
static int
F_232 ( struct V_34 * V_35 , void * V_81 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_491 * V_61 = V_81 ;
if ( V_61 ) {
if ( ! F_127 ( V_61 -> V_492 ) )
return - V_493 ;
memcpy ( V_35 -> V_136 , V_61 -> V_492 , V_35 -> V_488 ) ;
}
F_33 ( V_35 -> V_136 [ 3 ] | ( V_35 -> V_136 [ 2 ] << 8 ) |
( V_35 -> V_136 [ 1 ] << 16 ) | ( V_35 -> V_136 [ 0 ] << 24 ) ,
V_4 -> V_97 + V_138 ) ;
F_33 ( ( V_35 -> V_136 [ 5 ] << 16 ) | ( V_35 -> V_136 [ 4 ] << 24 ) ,
V_4 -> V_97 + V_139 ) ;
return 0 ;
}
static void F_233 ( struct V_34 * V_87 )
{
int V_28 ;
struct V_3 * V_4 = F_10 ( V_87 ) ;
for ( V_28 = 0 ; V_28 < V_494 ; V_28 ++ ) {
if ( V_4 -> V_294 [ V_28 ] > 0 ) {
F_234 ( V_4 -> V_294 [ V_28 ] ) ;
F_118 ( V_4 -> V_294 [ V_28 ] , V_87 ) ;
F_235 ( V_4 -> V_294 [ V_28 ] ) ;
}
}
}
static inline void F_236 ( struct V_34 * V_209 ,
T_13 V_271 )
{
struct V_3 * V_4 = F_10 ( V_209 ) ;
T_13 V_495 = V_271 ^ V_209 -> V_271 ;
V_209 -> V_271 = V_271 ;
if ( V_495 & V_496 ) {
if ( V_271 & V_496 )
V_4 -> V_149 |= V_150 ;
else
V_4 -> V_149 &= ~ V_150 ;
}
}
static int F_237 ( struct V_34 * V_209 ,
T_13 V_271 )
{
struct V_3 * V_4 = F_10 ( V_209 ) ;
T_13 V_495 = V_271 ^ V_209 -> V_271 ;
if ( F_77 ( V_209 ) && V_495 & V_497 ) {
F_78 ( & V_4 -> V_210 ) ;
F_79 ( V_209 ) ;
F_71 ( V_209 ) ;
F_236 ( V_209 , V_271 ) ;
F_63 ( V_209 ) ;
F_238 ( V_209 ) ;
F_81 ( V_209 ) ;
F_82 ( & V_4 -> V_210 ) ;
} else {
F_236 ( V_209 , V_271 ) ;
}
return 0 ;
}
static int F_239 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
struct V_1 * V_498 ;
T_2 V_124 ;
int V_499 ;
unsigned int V_28 ;
#if F_66 ( V_500 )
V_4 -> V_237 = 0xf ;
V_4 -> V_83 = 0xf ;
#else
V_4 -> V_237 = 0x3 ;
V_4 -> V_83 = 0x3 ;
#endif
F_216 ( V_35 ) ;
if ( V_4 -> V_7 )
V_4 -> V_22 = sizeof( struct V_7 ) ;
else
V_4 -> V_22 = sizeof( struct V_1 ) ;
V_499 = ( V_4 -> V_469 + V_4 -> V_472 ) *
V_4 -> V_22 ;
V_498 = F_240 ( & V_4 -> V_86 -> V_87 , V_499 , & V_124 ,
V_381 ) ;
if ( ! V_498 ) {
return - V_240 ;
}
memset ( V_498 , 0 , V_499 ) ;
F_125 ( V_35 ) ;
F_232 ( V_35 , NULL ) ;
for ( V_28 = 0 ; V_28 < V_4 -> V_119 ; V_28 ++ ) {
V_13 = V_4 -> V_14 [ V_28 ] ;
V_13 -> V_36 = V_28 ;
V_13 -> V_20 = (struct V_1 * ) V_498 ;
V_13 -> V_124 = V_124 ;
if ( V_4 -> V_7 ) {
V_124 += sizeof( struct V_7 ) * V_13 -> V_21 ;
V_498 = (struct V_1 * )
( ( (struct V_7 * ) V_498 ) + V_13 -> V_21 ) ;
} else {
V_124 += sizeof( struct V_1 ) * V_13 -> V_21 ;
V_498 += V_13 -> V_21 ;
}
}
for ( V_28 = 0 ; V_28 < V_4 -> V_123 ; V_28 ++ ) {
V_10 = V_4 -> V_11 [ V_28 ] ;
V_10 -> V_36 = V_28 ;
V_10 -> V_18 = (struct V_1 * ) V_498 ;
V_10 -> V_124 = V_124 ;
if ( V_4 -> V_7 ) {
V_124 += sizeof( struct V_7 ) * V_10 -> V_19 ;
V_498 = (struct V_1 * )
( ( (struct V_7 * ) V_498 ) + V_10 -> V_19 ) ;
} else {
V_124 += sizeof( struct V_1 ) * V_10 -> V_19 ;
V_498 += V_10 -> V_19 ;
}
}
V_35 -> V_501 = V_502 ;
V_35 -> V_503 = & V_504 ;
V_35 -> V_505 = & V_506 ;
F_33 ( V_507 , V_4 -> V_97 + V_191 ) ;
F_241 ( V_35 , & V_4 -> V_210 , F_123 , V_508 ) ;
if ( V_4 -> V_74 & V_509 )
V_35 -> V_271 |= V_272 ;
if ( V_4 -> V_74 & V_510 ) {
V_35 -> V_511 = V_512 ;
V_35 -> V_271 |= ( V_513 | V_514
| V_496 | V_515 | V_516 ) ;
V_4 -> V_149 |= V_150 ;
}
if ( V_4 -> V_74 & V_75 ) {
V_4 -> V_83 = 0 ;
V_4 -> V_237 = 0x3f ;
}
V_35 -> V_517 = V_35 -> V_271 ;
F_63 ( V_35 ) ;
return 0 ;
}
static void F_242 ( struct V_365 * V_86 )
{
int V_368 , V_518 ;
int V_519 = 1 ;
struct V_305 * V_306 = V_86 -> V_87 . V_307 ;
if ( ! V_306 )
return;
F_243 ( V_306 , L_27 , & V_519 ) ;
if ( V_519 > 1000 )
V_519 = 1 ;
V_518 = F_244 ( V_306 , L_28 , 0 ) ;
if ( ! F_245 ( V_518 ) )
return;
V_368 = F_246 ( & V_86 -> V_87 , V_518 ,
V_520 , L_29 ) ;
if ( V_368 ) {
F_161 ( & V_86 -> V_87 , L_30 , V_368 ) ;
return;
}
F_247 ( V_519 ) ;
F_248 ( V_518 , 1 ) ;
}
static void F_242 ( struct V_365 * V_86 )
{
}
static void
F_249 ( struct V_365 * V_86 , int * V_521 , int * V_522 )
{
struct V_305 * V_306 = V_86 -> V_87 . V_307 ;
int V_368 ;
* V_521 = * V_522 = 1 ;
if ( ! V_306 || ! F_250 ( V_306 ) )
return;
V_368 = F_243 ( V_306 , L_31 , V_521 ) ;
if ( V_368 )
* V_521 = 1 ;
V_368 = F_243 ( V_306 , L_32 , V_522 ) ;
if ( V_368 )
* V_522 = 1 ;
if ( * V_521 < 1 || * V_521 > V_523 ) {
F_251 ( & V_86 -> V_87 , L_33 ,
* V_521 ) ;
* V_521 = 1 ;
return;
}
if ( * V_522 < 1 || * V_522 > V_524 ) {
F_251 ( & V_86 -> V_87 , L_34 ,
* V_522 ) ;
* V_522 = 1 ;
return;
}
}
static int
F_252 ( struct V_365 * V_86 )
{
struct V_3 * V_4 ;
struct V_193 * V_194 ;
struct V_34 * V_35 ;
int V_28 , V_294 , V_93 = 0 ;
struct V_392 * V_393 ;
const struct V_525 * V_526 ;
static int V_295 ;
struct V_305 * V_306 = V_86 -> V_87 . V_307 , * V_349 ;
int V_527 ;
int V_528 ;
F_249 ( V_86 , & V_527 , & V_528 ) ;
V_35 = F_253 ( sizeof( struct V_3 ) ,
V_527 , V_528 ) ;
if ( ! V_35 )
return - V_240 ;
F_254 ( V_35 , & V_86 -> V_87 ) ;
V_4 = F_10 ( V_35 ) ;
V_526 = F_255 ( V_529 , & V_86 -> V_87 ) ;
if ( V_526 )
V_86 -> V_530 = V_526 -> V_95 ;
V_4 -> V_74 = V_86 -> V_530 -> V_531 ;
V_4 -> V_209 = V_35 ;
V_4 -> V_119 = V_528 ;
V_4 -> V_123 = V_527 ;
#if ! F_66 ( V_146 )
if ( V_4 -> V_74 & V_356 )
V_4 -> V_169 |= V_171 ;
#endif
F_223 ( & V_86 -> V_87 ) ;
V_393 = F_178 ( V_86 , V_395 , 0 ) ;
V_4 -> V_97 = F_256 ( & V_86 -> V_87 , V_393 ) ;
if ( F_154 ( V_4 -> V_97 ) ) {
V_93 = F_155 ( V_4 -> V_97 ) ;
goto V_532;
}
V_4 -> V_86 = V_86 ;
V_4 -> V_295 = V_295 ++ ;
F_257 ( V_86 , V_35 ) ;
if ( F_258 ( V_306 , L_35 , NULL ) )
V_4 -> V_198 |= V_459 ;
V_349 = F_259 ( V_306 , L_36 , 0 ) ;
if ( ! V_349 && F_260 ( V_306 ) ) {
V_93 = F_261 ( V_306 ) ;
if ( V_93 < 0 ) {
F_161 ( & V_86 -> V_87 ,
L_37 ) ;
goto V_533;
}
V_349 = F_262 ( V_306 ) ;
}
V_4 -> V_349 = V_349 ;
V_93 = F_263 ( V_86 -> V_87 . V_307 ) ;
if ( V_93 < 0 ) {
V_194 = F_126 ( & V_86 -> V_87 ) ;
if ( V_194 )
V_4 -> V_152 = V_194 -> V_534 ;
else
V_4 -> V_152 = V_535 ;
} else {
V_4 -> V_152 = V_93 ;
}
V_4 -> V_375 = F_264 ( & V_86 -> V_87 , L_38 ) ;
if ( F_154 ( V_4 -> V_375 ) ) {
V_93 = F_155 ( V_4 -> V_375 ) ;
goto V_536;
}
V_4 -> V_336 = F_264 ( & V_86 -> V_87 , L_39 ) ;
if ( F_154 ( V_4 -> V_336 ) ) {
V_93 = F_155 ( V_4 -> V_336 ) ;
goto V_536;
}
V_4 -> V_430 = F_160 ( V_4 -> V_336 ) ;
V_4 -> V_337 = F_264 ( & V_86 -> V_87 , L_40 ) ;
if ( F_154 ( V_4 -> V_337 ) )
V_4 -> V_337 = NULL ;
V_4 -> V_342 = false ;
F_265 ( & V_4 -> V_340 ) ;
V_4 -> V_343 = F_264 ( & V_86 -> V_87 , L_41 ) ;
if ( F_154 ( V_4 -> V_343 ) )
V_4 -> V_343 = NULL ;
V_4 -> V_7 = V_4 -> V_74 & V_537 ;
V_4 -> V_339 = F_264 ( & V_86 -> V_87 , L_42 ) ;
if ( F_154 ( V_4 -> V_339 ) ) {
V_4 -> V_339 = NULL ;
V_4 -> V_7 = false ;
}
V_93 = F_145 ( V_35 , true ) ;
if ( V_93 )
goto V_536;
V_93 = F_146 ( V_4 -> V_375 ) ;
if ( V_93 )
goto V_538;
V_4 -> V_539 = F_266 ( & V_86 -> V_87 , L_43 ) ;
if ( ! F_154 ( V_4 -> V_539 ) ) {
V_93 = F_267 ( V_4 -> V_539 ) ;
if ( V_93 ) {
F_161 ( & V_86 -> V_87 ,
L_44 , V_93 ) ;
goto V_540;
}
} else {
V_4 -> V_539 = NULL ;
}
F_268 ( & V_86 -> V_87 , V_541 ) ;
F_269 ( & V_86 -> V_87 ) ;
F_270 ( & V_86 -> V_87 ) ;
F_271 ( & V_86 -> V_87 ) ;
F_272 ( & V_86 -> V_87 ) ;
F_242 ( V_86 ) ;
if ( V_4 -> V_7 )
F_273 ( V_86 ) ;
V_93 = F_239 ( V_35 ) ;
if ( V_93 )
goto V_542;
for ( V_28 = 0 ; V_28 < V_494 ; V_28 ++ ) {
V_294 = F_274 ( V_86 , V_28 ) ;
if ( V_294 < 0 ) {
if ( V_28 )
break;
V_93 = V_294 ;
goto V_543;
}
V_93 = F_275 ( & V_86 -> V_87 , V_294 , F_118 ,
0 , V_86 -> V_364 , V_35 ) ;
if ( V_93 )
goto V_543;
V_4 -> V_294 [ V_28 ] = V_294 ;
}
F_276 ( & V_4 -> V_298 ) ;
V_93 = F_157 ( V_86 ) ;
if ( V_93 )
goto V_544;
F_277 ( V_35 ) ;
F_145 ( V_35 , false ) ;
F_226 ( & V_86 -> V_87 ) ;
V_93 = F_278 ( V_35 ) ;
if ( V_93 )
goto V_545;
F_279 ( & V_35 -> V_87 , V_4 -> V_198 &
V_459 ) ;
if ( V_4 -> V_7 && V_4 -> V_299 )
F_11 ( V_35 , L_45 , V_4 -> V_295 ) ;
V_4 -> V_244 = V_546 ;
F_280 ( & V_4 -> V_206 , F_74 ) ;
F_142 ( & V_86 -> V_87 ) ;
F_143 ( & V_86 -> V_87 ) ;
return 0 ;
V_545:
F_170 ( V_4 ) ;
V_544:
V_543:
V_542:
F_281 ( V_86 ) ;
if ( V_4 -> V_539 )
F_282 ( V_4 -> V_539 ) ;
V_540:
F_149 ( V_4 -> V_375 ) ;
V_538:
F_145 ( V_35 , false ) ;
V_536:
V_533:
F_166 ( V_349 ) ;
V_532:
F_283 ( V_35 ) ;
return V_93 ;
}
static int
F_284 ( struct V_365 * V_86 )
{
struct V_34 * V_35 = F_158 ( V_86 ) ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_285 ( & V_4 -> V_206 ) ;
F_281 ( V_86 ) ;
F_286 ( V_35 ) ;
F_170 ( V_4 ) ;
if ( V_4 -> V_539 )
F_282 ( V_4 -> V_539 ) ;
F_166 ( V_4 -> V_349 ) ;
F_283 ( V_35 ) ;
return 0 ;
}
static int T_14 F_287 ( struct V_324 * V_87 )
{
struct V_34 * V_35 = F_288 ( V_87 ) ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_75 () ;
if ( F_77 ( V_35 ) ) {
if ( V_4 -> V_198 & V_462 )
V_4 -> V_198 |= V_199 ;
F_228 ( V_4 -> V_158 ) ;
F_78 ( & V_4 -> V_210 ) ;
F_79 ( V_35 ) ;
F_289 ( V_35 ) ;
F_81 ( V_35 ) ;
F_71 ( V_35 ) ;
F_145 ( V_35 , false ) ;
if ( ! ( V_4 -> V_198 & V_462 ) )
F_226 ( & V_4 -> V_86 -> V_87 ) ;
}
F_83 () ;
if ( V_4 -> V_539 && ! ( V_4 -> V_198 & V_462 ) )
F_282 ( V_4 -> V_539 ) ;
if ( V_4 -> V_337 || V_4 -> V_539 )
V_4 -> V_189 = 0 ;
return 0 ;
}
static int T_14 F_290 ( struct V_324 * V_87 )
{
struct V_34 * V_35 = F_288 ( V_87 ) ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_193 * V_194 = V_4 -> V_86 -> V_87 . V_195 ;
int V_93 ;
int V_129 ;
if ( V_4 -> V_539 && ! ( V_4 -> V_198 & V_462 ) ) {
V_93 = F_267 ( V_4 -> V_539 ) ;
if ( V_93 )
return V_93 ;
}
F_75 () ;
if ( F_77 ( V_35 ) ) {
V_93 = F_145 ( V_35 , true ) ;
if ( V_93 ) {
F_83 () ;
goto V_536;
}
if ( V_4 -> V_198 & V_462 ) {
if ( V_194 && V_194 -> V_203 )
V_194 -> V_203 ( false ) ;
V_129 = F_46 ( V_4 -> V_97 + V_134 ) ;
V_129 &= ~ ( V_201 | V_202 ) ;
F_33 ( V_129 , V_4 -> V_97 + V_134 ) ;
V_4 -> V_198 &= ~ V_199 ;
} else {
F_223 ( & V_4 -> V_86 -> V_87 ) ;
}
F_63 ( V_35 ) ;
F_79 ( V_35 ) ;
F_291 ( V_35 ) ;
F_81 ( V_35 ) ;
F_82 ( & V_4 -> V_210 ) ;
F_224 ( V_4 -> V_158 ) ;
}
F_83 () ;
return 0 ;
V_536:
if ( V_4 -> V_539 )
F_282 ( V_4 -> V_539 ) ;
return V_93 ;
}
static int T_14 F_292 ( struct V_324 * V_87 )
{
struct V_34 * V_35 = F_288 ( V_87 ) ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_149 ( V_4 -> V_375 ) ;
return 0 ;
}
static int T_14 F_293 ( struct V_324 * V_87 )
{
struct V_34 * V_35 = F_288 ( V_87 ) ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
return F_146 ( V_4 -> V_375 ) ;
}
