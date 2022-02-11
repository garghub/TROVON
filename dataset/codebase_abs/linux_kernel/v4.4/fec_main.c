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
static struct V_1 *
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
return V_2 ;
F_25:
V_2 = V_10 -> V_25 ;
for ( V_28 = 0 ; V_28 < V_56 ; V_28 ++ ) {
V_2 = F_1 ( V_2 , V_4 , V_55 ) ;
F_29 ( & V_4 -> V_86 -> V_87 , V_2 -> V_38 ,
V_2 -> V_39 , V_88 ) ;
}
return F_30 ( - V_89 ) ;
}
static int F_31 ( struct V_9 * V_10 ,
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
V_92 = F_4 ( V_4 , V_10 ) ;
if ( V_92 < V_93 + 1 ) {
F_26 ( V_42 ) ;
if ( F_27 () )
F_28 ( V_35 , L_5 ) ;
return V_94 ;
}
if ( F_16 ( V_42 , V_35 ) ) {
F_26 ( V_42 ) ;
return V_94 ;
}
V_2 = V_10 -> V_25 ;
V_90 = V_2 ;
V_58 = V_2 -> V_37 ;
V_58 &= ~ V_63 ;
V_26 = V_42 -> V_95 ;
V_91 = F_32 ( V_42 ) ;
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
return V_94 ;
}
if ( V_54 ) {
V_90 = F_19 ( V_10 , V_42 , V_35 ) ;
if ( F_33 ( V_90 ) )
return V_94 ;
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
V_36 = F_3 ( V_10 -> V_18 , V_90 , V_4 ) ;
V_10 -> V_40 [ V_36 ] = V_42 ;
V_2 -> V_39 = V_91 ;
V_2 -> V_38 = V_61 ;
V_58 |= ( V_65 | V_64 ) ;
V_2 -> V_37 = V_58 ;
V_2 = F_1 ( V_90 , V_4 , V_55 ) ;
F_34 ( V_42 ) ;
F_35 () ;
V_10 -> V_25 = V_2 ;
F_36 ( 0 , V_4 -> V_97 + F_37 ( V_55 ) ) ;
return 0 ;
}
static int
F_38 ( struct V_9 * V_10 , struct V_41 * V_42 ,
struct V_34 * V_35 ,
struct V_1 * V_2 , int V_36 , char * V_95 ,
int V_66 , bool V_98 , bool V_99 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_7 * V_53 = F_39 ( V_2 , struct V_7 , V_100 ) ;
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
F_40 ( struct V_9 * V_10 ,
struct V_41 * V_42 , struct V_34 * V_35 ,
struct V_1 * V_2 , int V_36 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_102 = F_41 ( V_42 ) + F_42 ( V_42 ) ;
struct V_7 * V_53 = F_39 ( V_2 , struct V_7 , V_100 ) ;
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
static int F_43 ( struct V_9 * V_10 ,
struct V_41 * V_42 ,
struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_102 = F_41 ( V_42 ) + F_42 ( V_42 ) ;
int V_107 , V_108 ;
struct V_1 * V_2 = V_10 -> V_25 ;
unsigned short V_55 = F_21 ( V_42 ) ;
struct V_109 V_110 ;
unsigned int V_36 = 0 ;
int V_111 ;
if ( F_44 ( V_42 ) >= F_4 ( V_4 , V_10 ) ) {
F_26 ( V_42 ) ;
if ( F_27 () )
F_28 ( V_35 , L_6 ) ;
return V_94 ;
}
if ( F_16 ( V_42 , V_35 ) ) {
F_26 ( V_42 ) ;
return V_94 ;
}
F_45 ( V_42 , & V_110 ) ;
V_107 = V_42 -> V_27 - V_102 ;
while ( V_107 > 0 ) {
char * V_112 ;
V_36 = F_3 ( V_10 -> V_18 , V_2 , V_4 ) ;
V_108 = F_46 ( int , F_20 ( V_42 ) -> V_113 , V_107 ) ;
V_107 -= V_108 ;
V_112 = V_10 -> V_104 + V_36 * V_105 ;
F_47 ( V_42 , V_112 , & V_110 , V_108 , V_107 == 0 ) ;
V_111 = F_40 ( V_10 , V_42 , V_35 , V_2 , V_36 ) ;
if ( V_111 )
goto V_114;
while ( V_108 > 0 ) {
int V_66 ;
V_66 = F_46 ( int , V_110 . V_66 , V_108 ) ;
V_2 = F_1 ( V_2 , V_4 , V_55 ) ;
V_36 = F_3 ( V_10 -> V_18 ,
V_2 , V_4 ) ;
V_111 = F_38 ( V_10 , V_42 , V_35 ,
V_2 , V_36 ,
V_110 . V_95 , V_66 ,
V_66 == V_108 ,
V_107 == 0 ) ;
if ( V_111 )
goto V_114;
V_108 -= V_66 ;
F_48 ( V_42 , & V_110 , V_66 ) ;
}
V_2 = F_1 ( V_2 , V_4 , V_55 ) ;
}
V_10 -> V_40 [ V_36 ] = V_42 ;
F_34 ( V_42 ) ;
V_10 -> V_25 = V_2 ;
if ( ! ( V_4 -> V_74 & V_115 ) ||
! F_49 ( V_4 -> V_97 + F_37 ( V_55 ) ) ||
! F_49 ( V_4 -> V_97 + F_37 ( V_55 ) ) ||
! F_49 ( V_4 -> V_97 + F_37 ( V_55 ) ) ||
! F_49 ( V_4 -> V_97 + F_37 ( V_55 ) ) )
F_36 ( 0 , V_4 -> V_97 + F_37 ( V_55 ) ) ;
return 0 ;
V_114:
return V_111 ;
}
static T_3
F_50 ( struct V_41 * V_42 , struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_92 ;
unsigned short V_55 ;
struct V_9 * V_10 ;
struct V_116 * V_117 ;
int V_111 ;
V_55 = F_21 ( V_42 ) ;
V_10 = V_4 -> V_11 [ V_55 ] ;
V_117 = F_51 ( V_35 , V_55 ) ;
if ( F_52 ( V_42 ) )
V_111 = F_43 ( V_10 , V_42 , V_35 ) ;
else
V_111 = F_31 ( V_10 , V_42 , V_35 ) ;
if ( V_111 )
return V_111 ;
V_92 = F_4 ( V_4 , V_10 ) ;
if ( V_92 <= V_10 -> V_118 )
F_53 ( V_117 ) ;
return V_94 ;
}
static void F_54 ( struct V_34 * V_87 )
{
struct V_3 * V_4 = F_10 ( V_87 ) ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
unsigned int V_28 ;
unsigned int V_119 ;
for ( V_119 = 0 ; V_119 < V_4 -> V_120 ; V_119 ++ ) {
V_13 = V_4 -> V_14 [ V_119 ] ;
V_2 = V_13 -> V_20 ;
for ( V_28 = 0 ; V_28 < V_13 -> V_21 ; V_28 ++ ) {
if ( V_2 -> V_38 )
V_2 -> V_37 = V_121 ;
else
V_2 -> V_37 = 0 ;
V_2 = F_1 ( V_2 , V_4 , V_119 ) ;
}
V_2 = F_2 ( V_2 , V_4 , V_119 ) ;
V_2 -> V_37 |= V_122 ;
V_13 -> V_123 = V_13 -> V_20 ;
}
for ( V_119 = 0 ; V_119 < V_4 -> V_124 ; V_119 ++ ) {
V_10 = V_4 -> V_11 [ V_119 ] ;
V_2 = V_10 -> V_18 ;
V_10 -> V_25 = V_2 ;
for ( V_28 = 0 ; V_28 < V_10 -> V_19 ; V_28 ++ ) {
V_2 -> V_37 = 0 ;
if ( V_10 -> V_40 [ V_28 ] ) {
F_26 ( V_10 -> V_40 [ V_28 ] ) ;
V_10 -> V_40 [ V_28 ] = NULL ;
}
V_2 -> V_38 = 0 ;
V_2 = F_1 ( V_2 , V_4 , V_119 ) ;
}
V_2 = F_2 ( V_2 , V_4 , V_119 ) ;
V_2 -> V_37 |= V_122 ;
V_10 -> V_24 = V_2 ;
}
}
static void F_55 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_120 ; V_28 ++ )
F_36 ( 0 , V_4 -> V_97 + F_56 ( V_28 ) ) ;
}
static void F_57 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_120 ; V_28 ++ ) {
V_13 = V_4 -> V_14 [ V_28 ] ;
F_36 ( V_13 -> V_125 , V_4 -> V_97 + F_58 ( V_28 ) ) ;
F_36 ( V_126 , V_4 -> V_97 + F_59 ( V_28 ) ) ;
if ( V_28 )
F_36 ( V_127 | F_60 ( V_28 ) ,
V_4 -> V_97 + F_61 ( V_28 ) ) ;
}
for ( V_28 = 0 ; V_28 < V_4 -> V_124 ; V_28 ++ ) {
V_10 = V_4 -> V_11 [ V_28 ] ;
F_36 ( V_10 -> V_125 , V_4 -> V_97 + F_62 ( V_28 ) ) ;
if ( V_28 )
F_36 ( V_128 | F_63 ( V_28 ) ,
V_4 -> V_97 + F_64 ( V_28 ) ) ;
}
}
static void F_65 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_9 * V_10 ;
int V_28 , V_129 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_124 ; V_28 ++ ) {
V_10 = V_4 -> V_11 [ V_28 ] ;
for ( V_129 = 0 ; V_129 < V_10 -> V_19 ; V_129 ++ ) {
if ( V_10 -> V_40 [ V_129 ] ) {
F_26 ( V_10 -> V_40 [ V_129 ] ) ;
V_10 -> V_40 [ V_129 ] = NULL ;
}
}
}
}
static void
F_66 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
T_4 V_130 ;
T_4 V_131 [ 2 ] ;
T_4 V_132 = V_133 | 0x04 ;
T_4 V_134 = 0x2 ;
if ( V_4 -> V_74 & V_75 ) {
F_36 ( 0 , V_4 -> V_97 + V_135 ) ;
} else {
F_36 ( 1 , V_4 -> V_97 + V_135 ) ;
F_67 ( 10 ) ;
}
if ( V_4 -> V_74 & V_136 ) {
memcpy ( & V_131 , V_35 -> V_137 , V_138 ) ;
F_36 ( F_68 ( V_131 [ 0 ] ) , V_4 -> V_97 + V_139 ) ;
F_36 ( F_68 ( V_131 [ 1 ] ) , V_4 -> V_97 + V_140 ) ;
}
F_36 ( 0xffffffff , V_4 -> V_97 + V_141 ) ;
F_54 ( V_35 ) ;
F_57 ( V_35 ) ;
F_65 ( V_35 ) ;
if ( V_4 -> V_142 == V_143 ) {
F_36 ( 0x04 , V_4 -> V_97 + V_144 ) ;
} else {
V_132 |= 0x02 ;
F_36 ( 0x0 , V_4 -> V_97 + V_144 ) ;
}
F_36 ( V_4 -> V_145 , V_4 -> V_97 + V_146 ) ;
#if ! F_69 ( V_147 )
if ( V_4 -> V_74 & V_148 ) {
V_130 = F_49 ( V_4 -> V_97 + V_149 ) ;
if ( V_4 -> V_150 & V_151 )
V_130 |= V_152 ;
else
V_130 &= ~ V_152 ;
F_36 ( V_130 , V_4 -> V_97 + V_149 ) ;
}
#endif
if ( V_4 -> V_74 & V_136 ) {
V_132 |= 0x40000000 | 0x00000020 ;
if ( V_4 -> V_153 == V_154 ||
V_4 -> V_153 == V_155 ||
V_4 -> V_153 == V_156 ||
V_4 -> V_153 == V_157 )
V_132 |= ( 1 << 6 ) ;
else if ( V_4 -> V_153 == V_158 )
V_132 |= ( 1 << 8 ) ;
else
V_132 &= ~ ( 1 << 8 ) ;
if ( V_4 -> V_159 ) {
if ( V_4 -> V_159 -> V_160 == V_161 )
V_134 |= ( 1 << 5 ) ;
else if ( V_4 -> V_159 -> V_160 == V_162 )
V_132 &= ~ ( 1 << 9 ) ;
else
V_132 |= ( 1 << 9 ) ;
}
} else {
#ifdef F_70
if ( V_4 -> V_74 & V_163 ) {
T_4 V_164 ;
F_36 ( 0 , V_4 -> V_97 + F_70 ) ;
while ( F_49 ( V_4 -> V_97 + F_70 ) & 4 )
F_67 ( 1 ) ;
V_164 = ( V_4 -> V_153 == V_158 )
? V_165 : V_166 ;
if ( V_4 -> V_159 && V_4 -> V_159 -> V_160 == V_167 )
V_164 |= V_168 ;
F_36 ( V_164 , V_4 -> V_97 + V_169 ) ;
F_36 ( 2 , V_4 -> V_97 + F_70 ) ;
}
#endif
}
#if ! F_69 ( V_147 )
if ( ( V_4 -> V_170 & V_171 ) ||
( ( V_4 -> V_170 & V_172 ) &&
V_4 -> V_159 && V_4 -> V_159 -> V_173 ) ) {
V_132 |= V_174 ;
F_36 ( V_175 , V_4 -> V_97 + V_176 ) ;
F_36 ( V_177 , V_4 -> V_97 + V_178 ) ;
F_36 ( V_179 , V_4 -> V_97 + V_180 ) ;
F_36 ( V_181 , V_4 -> V_97 + V_182 ) ;
F_36 ( V_183 , V_4 -> V_97 + V_184 ) ;
} else {
V_132 &= ~ V_174 ;
}
#endif
F_36 ( V_132 , V_4 -> V_97 + V_185 ) ;
F_71 ( V_35 ) ;
#ifndef V_147
F_36 ( 0 , V_4 -> V_97 + V_186 ) ;
F_36 ( 0 , V_4 -> V_97 + V_187 ) ;
#endif
if ( V_4 -> V_74 & V_136 ) {
V_134 |= ( 1 << 8 ) ;
F_36 ( 1 << 8 , V_4 -> V_97 + V_188 ) ;
}
if ( V_4 -> V_7 )
V_134 |= ( 1 << 4 ) ;
#ifndef V_147
F_36 ( 0 << 31 , V_4 -> V_97 + V_189 ) ;
#endif
F_36 ( V_134 , V_4 -> V_97 + V_135 ) ;
F_55 ( V_35 ) ;
if ( V_4 -> V_7 )
F_72 ( V_35 ) ;
if ( V_4 -> V_190 )
F_36 ( V_191 , V_4 -> V_97 + V_192 ) ;
else
F_36 ( V_193 , V_4 -> V_97 + V_192 ) ;
F_73 ( V_35 ) ;
}
static void
F_74 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_194 * V_195 = V_4 -> V_86 -> V_87 . V_196 ;
T_4 V_197 = F_49 ( V_4 -> V_97 + V_185 ) & ( 1 << 8 ) ;
T_4 V_130 ;
if ( V_4 -> V_190 ) {
F_36 ( 1 , V_4 -> V_97 + V_144 ) ;
F_67 ( 10 ) ;
if ( ! ( F_49 ( V_4 -> V_97 + V_141 ) & V_198 ) )
F_28 ( V_35 , L_7 ) ;
}
if ( ! ( V_4 -> V_199 & V_200 ) ) {
if ( V_4 -> V_74 & V_75 ) {
F_36 ( 0 , V_4 -> V_97 + V_135 ) ;
} else {
F_36 ( 1 , V_4 -> V_97 + V_135 ) ;
F_67 ( 10 ) ;
}
F_36 ( V_191 , V_4 -> V_97 + V_192 ) ;
} else {
F_36 ( V_191 | V_201 , V_4 -> V_97 + V_192 ) ;
V_130 = F_49 ( V_4 -> V_97 + V_135 ) ;
V_130 |= ( V_202 | V_203 ) ;
F_36 ( V_130 , V_4 -> V_97 + V_135 ) ;
if ( V_195 && V_195 -> V_204 )
V_195 -> V_204 ( true ) ;
}
F_36 ( V_4 -> V_145 , V_4 -> V_97 + V_146 ) ;
if ( V_4 -> V_74 & V_136 &&
! ( V_4 -> V_199 & V_200 ) ) {
F_36 ( 2 , V_4 -> V_97 + V_135 ) ;
F_36 ( V_197 , V_4 -> V_97 + V_185 ) ;
}
}
static void
F_75 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_9 ( V_35 ) ;
V_35 -> V_205 . V_206 ++ ;
F_76 ( & V_4 -> V_207 ) ;
}
static void F_77 ( struct V_208 * V_209 )
{
struct V_3 * V_4 =
F_39 ( V_209 , struct V_3 , V_207 ) ;
struct V_34 * V_35 = V_4 -> V_210 ;
F_78 () ;
if ( F_79 ( V_35 ) || F_80 ( V_35 ) ) {
F_81 ( & V_4 -> V_211 ) ;
F_82 ( V_35 ) ;
F_66 ( V_35 ) ;
F_83 ( V_35 ) ;
F_84 ( V_35 ) ;
F_85 ( & V_4 -> V_211 ) ;
}
F_86 () ;
}
static void
F_87 ( struct V_3 * V_4 , unsigned V_212 ,
struct V_213 * V_214 )
{
unsigned long V_215 ;
T_5 V_216 ;
F_88 ( & V_4 -> V_217 , V_215 ) ;
V_216 = F_89 ( & V_4 -> V_218 , V_212 ) ;
F_90 ( & V_4 -> V_217 , V_215 ) ;
memset ( V_214 , 0 , sizeof( * V_214 ) ) ;
V_214 -> V_219 = F_91 ( V_216 ) ;
}
static void
F_92 ( struct V_34 * V_35 , T_6 V_5 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
unsigned short V_58 ;
struct V_41 * V_42 ;
struct V_9 * V_10 ;
struct V_116 * V_117 ;
int V_36 = 0 ;
int V_92 ;
V_4 = F_10 ( V_35 ) ;
V_5 = F_93 ( V_5 ) ;
V_10 = V_4 -> V_11 [ V_5 ] ;
V_117 = F_51 ( V_35 , V_5 ) ;
V_2 = V_10 -> V_24 ;
V_2 = F_1 ( V_2 , V_4 , V_5 ) ;
while ( V_2 != F_94 ( V_10 -> V_25 ) ) {
F_95 () ;
V_58 = F_94 ( V_2 -> V_37 ) ;
if ( V_58 & V_65 )
break;
V_36 = F_3 ( V_10 -> V_18 , V_2 , V_4 ) ;
V_42 = V_10 -> V_40 [ V_36 ] ;
V_10 -> V_40 [ V_36 ] = NULL ;
if ( ! F_96 ( V_10 , V_2 -> V_38 ) )
F_29 ( & V_4 -> V_86 -> V_87 , V_2 -> V_38 ,
V_2 -> V_39 , V_88 ) ;
V_2 -> V_38 = 0 ;
if ( ! V_42 ) {
V_2 = F_1 ( V_2 , V_4 , V_5 ) ;
continue;
}
if ( V_58 & ( V_220 | V_221 |
V_222 | V_223 |
V_224 ) ) {
V_35 -> V_205 . V_206 ++ ;
if ( V_58 & V_220 )
V_35 -> V_205 . V_225 ++ ;
if ( V_58 & V_221 )
V_35 -> V_205 . V_226 ++ ;
if ( V_58 & V_222 )
V_35 -> V_205 . V_227 ++ ;
if ( V_58 & V_223 )
V_35 -> V_205 . V_228 ++ ;
if ( V_58 & V_224 )
V_35 -> V_205 . V_229 ++ ;
} else {
V_35 -> V_205 . V_230 ++ ;
V_35 -> V_205 . V_231 += V_42 -> V_27 ;
}
if ( F_17 ( F_20 ( V_42 ) -> V_70 & V_96 ) &&
V_4 -> V_7 ) {
struct V_213 V_232 ;
struct V_7 * V_53 = (struct V_7 * ) V_2 ;
F_87 ( V_4 , V_53 -> V_212 , & V_232 ) ;
F_97 ( V_42 , & V_232 ) ;
}
if ( V_58 & V_233 )
V_35 -> V_205 . V_234 ++ ;
F_26 ( V_42 ) ;
F_35 () ;
V_10 -> V_24 = V_2 ;
V_2 = F_1 ( V_2 , V_4 , V_5 ) ;
if ( F_98 ( V_35 ) ) {
V_92 = F_4 ( V_4 , V_10 ) ;
if ( V_92 >= V_10 -> V_235 )
F_99 ( V_117 ) ;
}
}
if ( V_2 != V_10 -> V_25 &&
F_49 ( V_4 -> V_97 + F_37 ( V_5 ) ) == 0 )
F_36 ( 0 , V_4 -> V_97 + F_37 ( V_5 ) ) ;
}
static void
F_100 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
T_6 V_5 ;
F_101 (queue_id, &fep->work_tx, FEC_ENET_MAX_TX_QS) {
F_102 ( V_5 , & V_4 -> V_236 ) ;
F_92 ( V_35 , V_5 ) ;
}
return;
}
static int
F_103 ( struct V_34 * V_35 , struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_237 ;
V_237 = ( ( unsigned long ) V_42 -> V_95 ) & V_4 -> V_238 ;
if ( V_237 )
F_104 ( V_42 , V_4 -> V_238 + 1 - V_237 ) ;
V_2 -> V_38 = F_24 ( & V_4 -> V_86 -> V_87 , V_42 -> V_95 ,
V_239 - V_4 -> V_238 ,
V_240 ) ;
if ( F_25 ( & V_4 -> V_86 -> V_87 , V_2 -> V_38 ) ) {
if ( F_27 () )
F_28 ( V_35 , L_8 ) ;
return - V_89 ;
}
return 0 ;
}
static bool F_105 ( struct V_34 * V_35 , struct V_41 * * V_42 ,
struct V_1 * V_2 , T_4 V_241 , bool V_242 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_41 * V_243 ;
if ( V_241 > V_4 -> V_244 )
return false ;
V_243 = F_106 ( V_35 , V_241 ) ;
if ( ! V_243 )
return false ;
F_107 ( & V_4 -> V_86 -> V_87 , V_2 -> V_38 ,
V_239 - V_4 -> V_238 ,
V_240 ) ;
if ( ! V_242 )
memcpy ( V_243 -> V_95 , ( * V_42 ) -> V_95 , V_241 ) ;
else
F_7 ( V_243 -> V_95 , ( * V_42 ) -> V_95 , V_241 ) ;
* V_42 = V_243 ;
return true ;
}
static int
F_108 ( struct V_34 * V_35 , int V_245 , T_6 V_5 )
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
#ifdef F_109
F_110 () ;
#endif
V_5 = F_93 ( V_5 ) ;
V_13 = V_4 -> V_14 [ V_5 ] ;
V_2 = V_13 -> V_123 ;
while ( ! ( ( V_58 = V_2 -> V_37 ) & V_121 ) ) {
if ( V_248 >= V_245 )
break;
V_248 ++ ;
if ( ( V_58 & V_253 ) == 0 )
F_28 ( V_35 , L_9 ) ;
F_36 ( V_254 , V_4 -> V_97 + V_141 ) ;
if ( V_58 & ( V_255 | V_256 | V_257 |
V_258 | V_259 ) ) {
V_35 -> V_205 . V_260 ++ ;
if ( V_58 & ( V_255 | V_256 ) ) {
V_35 -> V_205 . V_261 ++ ;
}
if ( V_58 & V_257 )
V_35 -> V_205 . V_262 ++ ;
if ( V_58 & V_258 )
V_35 -> V_205 . V_263 ++ ;
if ( V_58 & V_259 )
V_35 -> V_205 . V_264 ++ ;
}
if ( V_58 & V_265 ) {
V_35 -> V_205 . V_260 ++ ;
V_35 -> V_205 . V_262 ++ ;
goto V_266;
}
V_35 -> V_205 . V_267 ++ ;
V_247 = V_2 -> V_39 ;
V_35 -> V_205 . V_268 += V_247 ;
V_36 = F_3 ( V_13 -> V_20 , V_2 , V_4 ) ;
V_42 = V_13 -> V_269 [ V_36 ] ;
V_251 = F_105 ( V_35 , & V_42 , V_2 , V_247 - 4 ,
V_252 ) ;
if ( ! V_251 ) {
V_246 = F_106 ( V_35 , V_239 ) ;
if ( F_17 ( ! V_246 ) ) {
V_35 -> V_205 . V_270 ++ ;
goto V_266;
}
F_29 ( & V_4 -> V_86 -> V_87 , V_2 -> V_38 ,
V_239 - V_4 -> V_238 ,
V_240 ) ;
}
F_111 ( V_42 -> V_95 - V_271 ) ;
F_112 ( V_42 , V_247 - 4 ) ;
V_95 = V_42 -> V_95 ;
if ( ! V_251 && V_252 )
F_5 ( V_95 , V_247 ) ;
V_53 = NULL ;
if ( V_4 -> V_7 )
V_53 = (struct V_7 * ) V_2 ;
V_249 = false ;
if ( ( V_35 -> V_272 & V_273 ) &&
V_4 -> V_7 && ( V_53 -> V_79 & V_274 ) ) {
struct V_275 * V_276 =
(struct V_275 * ) ( V_95 + V_277 ) ;
V_250 = F_113 ( V_276 -> V_278 ) ;
V_249 = true ;
memmove ( V_42 -> V_95 + V_279 , V_95 , V_138 * 2 ) ;
F_114 ( V_42 , V_279 ) ;
}
V_42 -> V_43 = F_115 ( V_42 , V_35 ) ;
if ( V_4 -> V_280 && V_4 -> V_7 )
F_87 ( V_4 , V_53 -> V_212 ,
F_116 ( V_42 ) ) ;
if ( V_4 -> V_7 &&
( V_4 -> V_150 & V_151 ) ) {
if ( ! ( V_53 -> V_79 & V_281 ) ) {
V_42 -> V_46 = V_282 ;
} else {
F_117 ( V_42 ) ;
}
}
if ( V_249 )
F_118 ( V_42 ,
F_14 ( V_283 ) ,
V_250 ) ;
F_119 ( & V_4 -> V_211 , V_42 ) ;
if ( V_251 ) {
F_120 ( & V_4 -> V_86 -> V_87 , V_2 -> V_38 ,
V_239 - V_4 -> V_238 ,
V_240 ) ;
} else {
V_13 -> V_269 [ V_36 ] = V_246 ;
F_103 ( V_35 , V_2 , V_246 ) ;
}
V_266:
V_58 &= ~ V_284 ;
V_58 |= V_121 ;
V_2 -> V_37 = V_58 ;
if ( V_4 -> V_7 ) {
struct V_7 * V_53 = (struct V_7 * ) V_2 ;
V_53 -> V_79 = V_285 ;
V_53 -> V_286 = 0 ;
V_53 -> V_78 = 0 ;
}
V_2 = F_1 ( V_2 , V_4 , V_5 ) ;
F_36 ( 0 , V_4 -> V_97 + F_56 ( V_5 ) ) ;
}
V_13 -> V_123 = V_2 ;
return V_248 ;
}
static int
F_121 ( struct V_34 * V_35 , int V_245 )
{
int V_248 = 0 ;
T_6 V_5 ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_101 (queue_id, &fep->work_rx, FEC_ENET_MAX_RX_QS) {
F_102 ( V_5 , & V_4 -> V_287 ) ;
V_248 += F_108 ( V_35 ,
V_245 - V_248 , V_5 ) ;
}
return V_248 ;
}
static bool
F_122 ( struct V_3 * V_4 , T_9 V_288 )
{
if ( V_288 == 0 )
return false ;
if ( V_288 & V_254 )
V_4 -> V_287 |= ( 1 << 2 ) ;
if ( V_288 & V_289 )
V_4 -> V_287 |= ( 1 << 0 ) ;
if ( V_288 & V_290 )
V_4 -> V_287 |= ( 1 << 1 ) ;
if ( V_288 & V_291 )
V_4 -> V_236 |= ( 1 << 2 ) ;
if ( V_288 & V_292 )
V_4 -> V_236 |= ( 1 << 0 ) ;
if ( V_288 & V_293 )
V_4 -> V_236 |= ( 1 << 1 ) ;
return true ;
}
static T_10
F_123 ( int V_294 , void * V_295 )
{
struct V_34 * V_35 = V_295 ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
T_9 V_288 ;
T_10 V_111 = V_296 ;
V_288 = F_49 ( V_4 -> V_97 + V_141 ) ;
F_36 ( V_288 , V_4 -> V_97 + V_141 ) ;
F_122 ( V_4 , V_288 ) ;
if ( ( V_4 -> V_236 || V_4 -> V_287 ) && V_4 -> V_190 ) {
V_111 = V_297 ;
if ( F_124 ( & V_4 -> V_211 ) ) {
F_36 ( V_193 , V_4 -> V_97 + V_192 ) ;
F_125 ( & V_4 -> V_211 ) ;
}
}
if ( V_288 & V_193 ) {
V_111 = V_297 ;
F_126 ( & V_4 -> V_298 ) ;
}
if ( V_4 -> V_299 )
F_127 ( V_4 ) ;
return V_111 ;
}
static int F_128 ( struct V_300 * V_211 , int V_245 )
{
struct V_34 * V_35 = V_211 -> V_87 ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_301 ;
V_301 = F_121 ( V_35 , V_245 ) ;
F_100 ( V_35 ) ;
if ( V_301 < V_245 ) {
F_129 ( V_211 ) ;
F_36 ( V_191 , V_4 -> V_97 + V_192 ) ;
}
return V_301 ;
}
static void F_130 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_194 * V_195 = F_131 ( & V_4 -> V_86 -> V_87 ) ;
unsigned char * V_302 , V_303 [ V_138 ] ;
V_302 = V_304 ;
if ( ! F_132 ( V_302 ) ) {
struct V_305 * V_306 = V_4 -> V_86 -> V_87 . V_307 ;
if ( V_306 ) {
const char * V_308 = F_133 ( V_306 ) ;
if ( V_308 )
V_302 = ( unsigned char * ) V_308 ;
}
}
if ( ! F_132 ( V_302 ) ) {
#ifdef V_147
if ( V_309 )
V_302 = ( unsigned char * ) V_309 ;
#else
if ( V_195 )
V_302 = ( unsigned char * ) & V_195 -> V_308 ;
#endif
}
if ( ! F_132 ( V_302 ) ) {
* ( ( V_310 * ) & V_303 [ 0 ] ) =
F_68 ( F_49 ( V_4 -> V_97 + V_139 ) ) ;
* ( ( V_311 * ) & V_303 [ 4 ] ) =
F_134 ( F_49 ( V_4 -> V_97 + V_140 ) >> 16 ) ;
V_302 = & V_303 [ 0 ] ;
}
if ( ! F_132 ( V_302 ) ) {
F_28 ( V_35 , L_10 , V_302 ) ;
F_135 ( V_35 ) ;
F_11 ( V_35 , L_11 ,
V_35 -> V_137 ) ;
return;
}
memcpy ( V_35 -> V_137 , V_302 , V_138 ) ;
if ( V_302 == V_304 )
V_35 -> V_137 [ V_138 - 1 ] = V_304 [ V_138 - 1 ] + V_4 -> V_295 ;
}
static void F_136 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_312 * V_159 = V_4 -> V_159 ;
int V_313 = 0 ;
if ( V_4 -> V_314 && V_159 -> V_315 == V_316 ) {
V_159 -> V_315 = V_317 ;
return;
}
if ( ! F_80 ( V_35 ) || ! F_79 ( V_35 ) ) {
V_4 -> V_190 = 0 ;
} else if ( V_159 -> V_190 ) {
if ( ! V_4 -> V_190 ) {
V_4 -> V_190 = V_159 -> V_190 ;
V_313 = 1 ;
}
if ( V_4 -> V_142 != V_159 -> V_318 ) {
V_4 -> V_142 = V_159 -> V_318 ;
V_313 = 1 ;
}
if ( V_159 -> V_160 != V_4 -> V_160 ) {
V_4 -> V_160 = V_159 -> V_160 ;
V_313 = 1 ;
}
if ( V_313 ) {
F_81 ( & V_4 -> V_211 ) ;
F_82 ( V_35 ) ;
F_66 ( V_35 ) ;
F_83 ( V_35 ) ;
F_84 ( V_35 ) ;
F_85 ( & V_4 -> V_211 ) ;
}
} else {
if ( V_4 -> V_190 ) {
F_81 ( & V_4 -> V_211 ) ;
F_82 ( V_35 ) ;
F_74 ( V_35 ) ;
F_84 ( V_35 ) ;
F_85 ( & V_4 -> V_211 ) ;
V_4 -> V_190 = V_159 -> V_190 ;
V_313 = 1 ;
}
}
if ( V_313 )
F_137 ( V_159 ) ;
}
static int F_138 ( struct V_319 * V_320 , int V_321 , int V_322 )
{
struct V_3 * V_4 = V_320 -> V_323 ;
struct V_324 * V_87 = & V_4 -> V_86 -> V_87 ;
unsigned long V_325 ;
int V_111 = 0 ;
V_111 = F_139 ( V_87 ) ;
if ( V_111 < 0 )
return V_111 ;
V_4 -> V_314 = 0 ;
F_140 ( & V_4 -> V_298 ) ;
F_36 ( V_326 | V_327 |
F_141 ( V_321 ) | F_142 ( V_322 ) |
V_328 , V_4 -> V_97 + V_329 ) ;
V_325 = F_143 ( & V_4 -> V_298 ,
F_144 ( V_330 ) ) ;
if ( V_325 == 0 ) {
V_4 -> V_314 = 1 ;
F_28 ( V_4 -> V_210 , L_12 ) ;
V_111 = - V_331 ;
goto V_332;
}
V_111 = F_145 ( F_49 ( V_4 -> V_97 + V_329 ) ) ;
V_332:
F_146 ( V_87 ) ;
F_147 ( V_87 ) ;
return V_111 ;
}
static int F_148 ( struct V_319 * V_320 , int V_321 , int V_322 ,
T_6 V_333 )
{
struct V_3 * V_4 = V_320 -> V_323 ;
struct V_324 * V_87 = & V_4 -> V_86 -> V_87 ;
unsigned long V_325 ;
int V_111 ;
V_111 = F_139 ( V_87 ) ;
if ( V_111 < 0 )
return V_111 ;
else
V_111 = 0 ;
V_4 -> V_314 = 0 ;
F_140 ( & V_4 -> V_298 ) ;
F_36 ( V_326 | V_334 |
F_141 ( V_321 ) | F_142 ( V_322 ) |
V_328 | F_145 ( V_333 ) ,
V_4 -> V_97 + V_329 ) ;
V_325 = F_143 ( & V_4 -> V_298 ,
F_144 ( V_330 ) ) ;
if ( V_325 == 0 ) {
V_4 -> V_314 = 1 ;
F_28 ( V_4 -> V_210 , L_13 ) ;
V_111 = - V_331 ;
}
F_146 ( V_87 ) ;
F_147 ( V_87 ) ;
return V_111 ;
}
static int F_149 ( struct V_34 * V_35 , bool V_335 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_111 ;
if ( V_335 ) {
V_111 = F_150 ( V_4 -> V_336 ) ;
if ( V_111 )
return V_111 ;
if ( V_4 -> V_337 ) {
V_111 = F_150 ( V_4 -> V_337 ) ;
if ( V_111 )
goto V_338;
}
if ( V_4 -> V_339 ) {
F_151 ( & V_4 -> V_340 ) ;
V_111 = F_150 ( V_4 -> V_339 ) ;
if ( V_111 ) {
F_152 ( & V_4 -> V_340 ) ;
goto V_341;
} else {
V_4 -> V_342 = true ;
}
F_152 ( & V_4 -> V_340 ) ;
}
if ( V_4 -> V_343 ) {
V_111 = F_150 ( V_4 -> V_343 ) ;
if ( V_111 )
goto V_344;
}
} else {
F_153 ( V_4 -> V_336 ) ;
if ( V_4 -> V_337 )
F_153 ( V_4 -> V_337 ) ;
if ( V_4 -> V_339 ) {
F_151 ( & V_4 -> V_340 ) ;
F_153 ( V_4 -> V_339 ) ;
V_4 -> V_342 = false ;
F_152 ( & V_4 -> V_340 ) ;
}
if ( V_4 -> V_343 )
F_153 ( V_4 -> V_343 ) ;
}
return 0 ;
V_344:
if ( V_4 -> V_343 )
F_153 ( V_4 -> V_343 ) ;
V_341:
if ( V_4 -> V_337 )
F_153 ( V_4 -> V_337 ) ;
V_338:
F_153 ( V_4 -> V_336 ) ;
return V_111 ;
}
static int F_154 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_312 * V_159 = NULL ;
char V_345 [ V_346 ] ;
char V_347 [ V_346 + 3 ] ;
int V_348 ;
int V_295 = V_4 -> V_295 ;
V_4 -> V_159 = NULL ;
if ( V_4 -> V_349 ) {
V_159 = F_155 ( V_35 , V_4 -> V_349 ,
& F_136 , 0 ,
V_4 -> V_153 ) ;
if ( ! V_159 )
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
F_156 ( V_345 , V_4 -> V_319 -> V_354 , V_346 ) ;
break;
}
if ( V_348 >= V_351 ) {
F_11 ( V_35 , L_14 ) ;
F_156 ( V_345 , L_15 , V_346 ) ;
V_348 = 0 ;
}
snprintf ( V_347 , sizeof( V_347 ) ,
V_355 , V_345 , V_348 ) ;
V_159 = F_157 ( V_35 , V_347 , & F_136 ,
V_4 -> V_153 ) ;
}
if ( F_33 ( V_159 ) ) {
F_28 ( V_35 , L_16 ) ;
return F_158 ( V_159 ) ;
}
if ( V_4 -> V_74 & V_356 ) {
V_159 -> V_357 &= V_358 ;
V_159 -> V_357 &= ~ V_359 ;
#if ! F_69 ( V_147 )
V_159 -> V_357 |= V_360 ;
#endif
}
else
V_159 -> V_357 &= V_361 ;
V_159 -> V_362 = V_159 -> V_357 ;
V_4 -> V_159 = V_159 ;
V_4 -> V_190 = 0 ;
V_4 -> V_142 = 0 ;
F_11 ( V_35 , L_17 ,
V_4 -> V_159 -> V_363 -> V_364 , F_159 ( & V_4 -> V_159 -> V_87 ) ,
V_4 -> V_159 -> V_294 ) ;
return 0 ;
}
static int F_160 ( struct V_365 * V_86 )
{
static struct V_319 * V_366 ;
struct V_34 * V_35 = F_161 ( V_86 ) ;
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
V_370 = F_162 ( F_163 ( V_4 -> V_375 ) , 5000000 ) ;
if ( V_4 -> V_74 & V_136 )
V_370 -- ;
if ( V_370 > 63 ) {
F_164 ( & V_86 -> V_87 ,
L_18 ,
F_163 ( V_4 -> V_375 ) ) ;
V_368 = - V_376 ;
goto V_377;
}
V_371 = F_162 ( F_163 ( V_4 -> V_375 ) , 100000000 ) - 1 ;
V_4 -> V_145 = V_370 << 1 | V_371 << 8 ;
F_36 ( V_4 -> V_145 , V_4 -> V_97 + V_146 ) ;
V_4 -> V_319 = F_165 () ;
if ( V_4 -> V_319 == NULL ) {
V_368 = - V_89 ;
goto V_377;
}
V_4 -> V_319 -> V_364 = L_19 ;
V_4 -> V_319 -> V_378 = F_138 ;
V_4 -> V_319 -> V_379 = F_148 ;
snprintf ( V_4 -> V_319 -> V_354 , V_346 , L_20 ,
V_86 -> V_364 , V_4 -> V_295 + 1 ) ;
V_4 -> V_319 -> V_323 = V_4 ;
V_4 -> V_319 -> V_380 = & V_86 -> V_87 ;
V_4 -> V_319 -> V_294 = F_166 ( sizeof( int ) * V_351 , V_381 ) ;
if ( ! V_4 -> V_319 -> V_294 ) {
V_368 = - V_89 ;
goto V_382;
}
for ( V_28 = 0 ; V_28 < V_351 ; V_28 ++ )
V_4 -> V_319 -> V_294 [ V_28 ] = V_383 ;
V_367 = F_167 ( V_86 -> V_87 . V_307 , L_21 ) ;
if ( V_367 ) {
V_368 = F_168 ( V_4 -> V_319 , V_367 ) ;
F_169 ( V_367 ) ;
} else {
V_368 = F_170 ( V_4 -> V_319 ) ;
}
if ( V_368 )
goto V_384;
V_373 ++ ;
if ( V_4 -> V_74 & V_372 )
V_366 = V_4 -> V_319 ;
return 0 ;
V_384:
F_171 ( V_4 -> V_319 -> V_294 ) ;
V_382:
F_172 ( V_4 -> V_319 ) ;
V_377:
return V_368 ;
}
static void F_173 ( struct V_3 * V_4 )
{
if ( -- V_373 == 0 ) {
F_174 ( V_4 -> V_319 ) ;
F_171 ( V_4 -> V_319 -> V_294 ) ;
F_172 ( V_4 -> V_319 ) ;
}
}
static int F_175 ( struct V_34 * V_35 ,
struct V_385 * V_386 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_312 * V_387 = V_4 -> V_159 ;
if ( ! V_387 )
return - V_350 ;
return F_176 ( V_387 , V_386 ) ;
}
static int F_177 ( struct V_34 * V_35 ,
struct V_385 * V_386 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_312 * V_387 = V_4 -> V_159 ;
if ( ! V_387 )
return - V_350 ;
return F_178 ( V_387 , V_386 ) ;
}
static void F_179 ( struct V_34 * V_35 ,
struct V_388 * V_389 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_156 ( V_389 -> V_390 , V_4 -> V_86 -> V_87 . V_390 -> V_364 ,
sizeof( V_389 -> V_390 ) ) ;
F_156 ( V_389 -> V_45 , L_22 , sizeof( V_389 -> V_45 ) ) ;
F_156 ( V_389 -> V_391 , F_159 ( & V_35 -> V_87 ) , sizeof( V_389 -> V_391 ) ) ;
}
static int F_180 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_392 * V_393 ;
int V_394 = 0 ;
V_393 = F_181 ( V_4 -> V_86 , V_395 , 0 ) ;
if ( V_393 )
V_394 = F_182 ( V_393 ) ;
return V_394 ;
}
static void F_183 ( struct V_34 * V_35 ,
struct V_396 * V_397 , void * V_398 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
T_4 T_11 * V_399 = ( T_4 T_11 * ) V_4 -> V_97 ;
T_4 * V_29 = ( T_4 * ) V_398 ;
T_4 V_28 , V_237 ;
memset ( V_29 , 0 , V_397 -> V_27 ) ;
for ( V_28 = 0 ; V_28 < F_184 ( V_400 ) ; V_28 ++ ) {
V_237 = V_400 [ V_28 ] / 4 ;
V_29 [ V_237 ] = F_49 ( & V_399 [ V_237 ] ) ;
}
}
static int F_185 ( struct V_34 * V_35 ,
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
V_389 -> V_409 = F_186 ( V_4 -> V_299 ) ;
else
V_389 -> V_409 = - 1 ;
V_389 -> V_410 = ( 1 << V_411 ) |
( 1 << V_412 ) ;
V_389 -> V_413 = ( 1 << V_414 ) |
( 1 << V_415 ) ;
return 0 ;
} else {
return F_187 ( V_35 , V_389 ) ;
}
}
static void F_188 ( struct V_34 * V_35 ,
struct V_416 * V_173 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
V_173 -> V_417 = ( V_4 -> V_170 & V_172 ) != 0 ;
V_173 -> V_418 = ( V_4 -> V_170 & V_171 ) != 0 ;
V_173 -> V_419 = V_173 -> V_418 ;
}
static int F_189 ( struct V_34 * V_35 ,
struct V_416 * V_173 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
if ( ! V_4 -> V_159 )
return - V_350 ;
if ( V_173 -> V_418 != V_173 -> V_419 ) {
F_11 ( V_35 ,
L_23 ) ;
return - V_376 ;
}
V_4 -> V_170 = 0 ;
V_4 -> V_170 |= V_173 -> V_419 ? V_171 : 0 ;
V_4 -> V_170 |= V_173 -> V_417 ? V_172 : 0 ;
if ( V_173 -> V_419 || V_173 -> V_417 ) {
V_4 -> V_159 -> V_357 |= V_420 ;
V_4 -> V_159 -> V_362 |= V_420 ;
} else {
V_4 -> V_159 -> V_357 &= ~ V_420 ;
V_4 -> V_159 -> V_362 &= ~ V_420 ;
}
if ( V_173 -> V_417 ) {
if ( F_80 ( V_35 ) )
F_74 ( V_35 ) ;
F_190 ( V_4 -> V_159 ) ;
}
if ( F_80 ( V_35 ) ) {
F_81 ( & V_4 -> V_211 ) ;
F_82 ( V_35 ) ;
F_66 ( V_35 ) ;
F_83 ( V_35 ) ;
F_84 ( V_35 ) ;
F_85 ( & V_4 -> V_211 ) ;
}
return 0 ;
}
static void F_191 ( struct V_34 * V_87 ,
struct V_421 * V_205 , T_5 * V_95 )
{
struct V_3 * V_4 = F_10 ( V_87 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < F_184 ( V_422 ) ; V_28 ++ )
V_95 [ V_28 ] = F_49 ( V_4 -> V_97 + V_422 [ V_28 ] . V_423 ) ;
}
static void F_192 ( struct V_34 * V_210 ,
T_4 V_424 , T_12 * V_95 )
{
int V_28 ;
switch ( V_424 ) {
case V_425 :
for ( V_28 = 0 ; V_28 < F_184 ( V_422 ) ; V_28 ++ )
memcpy ( V_95 + V_28 * V_426 ,
V_422 [ V_28 ] . V_364 , V_426 ) ;
break;
}
}
static int F_193 ( struct V_34 * V_87 , int V_427 )
{
switch ( V_427 ) {
case V_425 :
return F_184 ( V_422 ) ;
default:
return - V_428 ;
}
}
static int F_194 ( struct V_34 * V_87 )
{
struct V_3 * V_4 = F_10 ( V_87 ) ;
struct V_312 * V_387 = V_4 -> V_159 ;
if ( ! V_387 )
return - V_350 ;
return F_195 ( V_387 ) ;
}
static int F_196 ( struct V_34 * V_35 , int V_429 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
return V_429 * ( V_4 -> V_430 / 64000 ) / 1000 ;
}
static void F_197 ( struct V_34 * V_35 )
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
V_431 |= F_198 ( V_4 -> V_434 ) ;
V_431 |= F_199 ( F_196 ( V_35 , V_4 -> V_433 ) ) ;
V_432 |= F_198 ( V_4 -> V_436 ) ;
V_432 |= F_199 ( F_196 ( V_35 , V_4 -> V_435 ) ) ;
V_431 |= V_438 ;
V_432 |= V_438 ;
F_36 ( V_432 , V_4 -> V_97 + V_439 ) ;
F_36 ( V_431 , V_4 -> V_97 + V_440 ) ;
F_36 ( V_432 , V_4 -> V_97 + V_441 ) ;
F_36 ( V_431 , V_4 -> V_97 + V_442 ) ;
F_36 ( V_432 , V_4 -> V_97 + V_443 ) ;
F_36 ( V_431 , V_4 -> V_97 + V_444 ) ;
}
static int
F_200 ( struct V_34 * V_35 , struct V_445 * V_446 )
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
F_201 ( struct V_34 * V_35 , struct V_445 * V_446 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
unsigned int V_451 ;
if ( ! ( V_4 -> V_74 & V_75 ) )
return - V_428 ;
if ( V_446 -> V_448 > 255 ) {
F_202 ( L_24 ) ;
return - V_376 ;
}
if ( V_446 -> V_450 > 255 ) {
F_202 ( L_25 ) ;
return - V_376 ;
}
V_451 = F_196 ( V_35 , V_4 -> V_433 ) ;
if ( V_451 > 0xFFFF ) {
F_202 ( L_26 ) ;
return - V_376 ;
}
V_451 = F_196 ( V_35 , V_4 -> V_435 ) ;
if ( V_451 > 0xFFFF ) {
F_202 ( L_26 ) ;
return - V_376 ;
}
V_4 -> V_433 = V_446 -> V_447 ;
V_4 -> V_434 = V_446 -> V_448 ;
V_4 -> V_435 = V_446 -> V_449 ;
V_4 -> V_436 = V_446 -> V_450 ;
F_197 ( V_35 ) ;
return 0 ;
}
static void F_73 ( struct V_34 * V_35 )
{
struct V_445 V_446 ;
V_446 . V_447 = V_452 ;
V_446 . V_448 = V_453 ;
V_446 . V_449 = V_452 ;
V_446 . V_450 = V_453 ;
F_201 ( V_35 , & V_446 ) ;
}
static int F_203 ( struct V_34 * V_210 ,
const struct V_454 * V_455 ,
void * V_95 )
{
struct V_3 * V_4 = F_10 ( V_210 ) ;
int V_111 = 0 ;
switch ( V_455 -> V_354 ) {
case V_456 :
* ( T_4 * ) V_95 = V_4 -> V_244 ;
break;
default:
V_111 = - V_376 ;
break;
}
return V_111 ;
}
static int F_204 ( struct V_34 * V_210 ,
const struct V_454 * V_455 ,
const void * V_95 )
{
struct V_3 * V_4 = F_10 ( V_210 ) ;
int V_111 = 0 ;
switch ( V_455 -> V_354 ) {
case V_456 :
V_4 -> V_244 = * ( T_4 * ) V_95 ;
break;
default:
V_111 = - V_376 ;
break;
}
return V_111 ;
}
static void
F_205 ( struct V_34 * V_35 , struct V_457 * V_458 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
if ( V_4 -> V_199 & V_459 ) {
V_458 -> V_357 = V_460 ;
V_458 -> V_461 = V_4 -> V_199 & V_462 ? V_460 : 0 ;
} else {
V_458 -> V_357 = V_458 -> V_461 = 0 ;
}
}
static int
F_206 ( struct V_34 * V_35 , struct V_457 * V_458 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
if ( ! ( V_4 -> V_199 & V_459 ) )
return - V_376 ;
if ( V_458 -> V_461 & ~ V_460 )
return - V_376 ;
F_207 ( & V_35 -> V_87 , V_458 -> V_461 & V_460 ) ;
if ( F_208 ( & V_35 -> V_87 ) ) {
V_4 -> V_199 |= V_462 ;
if ( V_4 -> V_294 [ 0 ] > 0 )
F_209 ( V_4 -> V_294 [ 0 ] ) ;
} else {
V_4 -> V_199 &= ( ~ V_462 ) ;
if ( V_4 -> V_294 [ 0 ] > 0 )
F_210 ( V_4 -> V_294 [ 0 ] ) ;
}
return 0 ;
}
static int F_211 ( struct V_34 * V_35 , struct V_463 * V_464 , int V_386 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_312 * V_387 = V_4 -> V_159 ;
if ( ! F_80 ( V_35 ) )
return - V_376 ;
if ( ! V_387 )
return - V_350 ;
if ( V_4 -> V_7 ) {
if ( V_386 == V_465 )
return F_212 ( V_35 , V_464 ) ;
if ( V_386 == V_466 )
return F_213 ( V_35 , V_464 ) ;
}
return F_214 ( V_387 , V_464 , V_386 ) ;
}
static void F_215 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
unsigned int V_28 ;
struct V_41 * V_42 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
unsigned int V_119 ;
for ( V_119 = 0 ; V_119 < V_4 -> V_120 ; V_119 ++ ) {
V_13 = V_4 -> V_14 [ V_119 ] ;
V_2 = V_13 -> V_20 ;
for ( V_28 = 0 ; V_28 < V_13 -> V_21 ; V_28 ++ ) {
V_42 = V_13 -> V_269 [ V_28 ] ;
V_13 -> V_269 [ V_28 ] = NULL ;
if ( V_42 ) {
F_29 ( & V_4 -> V_86 -> V_87 ,
V_2 -> V_38 ,
V_239 - V_4 -> V_238 ,
V_240 ) ;
F_216 ( V_42 ) ;
}
V_2 = F_1 ( V_2 , V_4 , V_119 ) ;
}
}
for ( V_119 = 0 ; V_119 < V_4 -> V_124 ; V_119 ++ ) {
V_10 = V_4 -> V_11 [ V_119 ] ;
V_2 = V_10 -> V_18 ;
for ( V_28 = 0 ; V_28 < V_10 -> V_19 ; V_28 ++ ) {
F_171 ( V_10 -> V_85 [ V_28 ] ) ;
V_10 -> V_85 [ V_28 ] = NULL ;
V_42 = V_10 -> V_40 [ V_28 ] ;
V_10 -> V_40 [ V_28 ] = NULL ;
F_216 ( V_42 ) ;
}
}
}
static void F_217 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_28 ;
struct V_9 * V_10 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_124 ; V_28 ++ )
if ( V_4 -> V_11 [ V_28 ] && V_4 -> V_11 [ V_28 ] -> V_104 ) {
V_10 = V_4 -> V_11 [ V_28 ] ;
F_218 ( NULL ,
V_10 -> V_19 * V_105 ,
V_10 -> V_104 ,
V_10 -> V_106 ) ;
}
for ( V_28 = 0 ; V_28 < V_4 -> V_120 ; V_28 ++ )
F_171 ( V_4 -> V_14 [ V_28 ] ) ;
for ( V_28 = 0 ; V_28 < V_4 -> V_124 ; V_28 ++ )
F_171 ( V_4 -> V_11 [ V_28 ] ) ;
}
static int F_219 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_28 ;
int V_111 = 0 ;
struct V_9 * V_10 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_124 ; V_28 ++ ) {
V_10 = F_220 ( sizeof( * V_10 ) , V_381 ) ;
if ( ! V_10 ) {
V_111 = - V_89 ;
goto V_467;
}
V_4 -> V_11 [ V_28 ] = V_10 ;
V_10 -> V_19 = V_468 ;
V_4 -> V_469 += V_4 -> V_11 [ V_28 ] -> V_19 ;
V_10 -> V_118 = V_470 ;
V_10 -> V_235 =
( V_10 -> V_19 - V_10 -> V_118 ) / 2 ;
V_10 -> V_104 = F_221 ( NULL ,
V_10 -> V_19 * V_105 ,
& V_10 -> V_106 ,
V_381 ) ;
if ( ! V_10 -> V_104 ) {
V_111 = - V_89 ;
goto V_467;
}
}
for ( V_28 = 0 ; V_28 < V_4 -> V_120 ; V_28 ++ ) {
V_4 -> V_14 [ V_28 ] = F_220 ( sizeof( * V_4 -> V_14 [ V_28 ] ) ,
V_381 ) ;
if ( ! V_4 -> V_14 [ V_28 ] ) {
V_111 = - V_89 ;
goto V_467;
}
V_4 -> V_14 [ V_28 ] -> V_21 = V_471 ;
V_4 -> V_472 += V_4 -> V_14 [ V_28 ] -> V_21 ;
}
return V_111 ;
V_467:
F_217 ( V_35 ) ;
return V_111 ;
}
static int
F_222 ( struct V_34 * V_35 , unsigned int V_55 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
unsigned int V_28 ;
struct V_41 * V_42 ;
struct V_1 * V_2 ;
struct V_12 * V_13 ;
V_13 = V_4 -> V_14 [ V_55 ] ;
V_2 = V_13 -> V_20 ;
for ( V_28 = 0 ; V_28 < V_13 -> V_21 ; V_28 ++ ) {
V_42 = F_106 ( V_35 , V_239 ) ;
if ( ! V_42 )
goto V_473;
if ( F_103 ( V_35 , V_2 , V_42 ) ) {
F_216 ( V_42 ) ;
goto V_473;
}
V_13 -> V_269 [ V_28 ] = V_42 ;
V_2 -> V_37 = V_121 ;
if ( V_4 -> V_7 ) {
struct V_7 * V_53 = (struct V_7 * ) V_2 ;
V_53 -> V_79 = V_285 ;
}
V_2 = F_1 ( V_2 , V_4 , V_55 ) ;
}
V_2 = F_2 ( V_2 , V_4 , V_55 ) ;
V_2 -> V_37 |= V_122 ;
return 0 ;
V_473:
F_215 ( V_35 ) ;
return - V_89 ;
}
static int
F_223 ( struct V_34 * V_35 , unsigned int V_55 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
unsigned int V_28 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
V_10 = V_4 -> V_11 [ V_55 ] ;
V_2 = V_10 -> V_18 ;
for ( V_28 = 0 ; V_28 < V_10 -> V_19 ; V_28 ++ ) {
V_10 -> V_85 [ V_28 ] = F_166 ( V_474 , V_381 ) ;
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
V_2 -> V_37 |= V_122 ;
return 0 ;
V_473:
F_215 ( V_35 ) ;
return - V_89 ;
}
static int F_224 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_120 ; V_28 ++ )
if ( F_222 ( V_35 , V_28 ) )
return - V_89 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_124 ; V_28 ++ )
if ( F_223 ( V_35 , V_28 ) )
return - V_89 ;
return 0 ;
}
static int
F_225 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_111 ;
V_111 = F_139 ( & V_4 -> V_86 -> V_87 ) ;
if ( V_111 < 0 )
return V_111 ;
F_226 ( & V_4 -> V_86 -> V_87 ) ;
V_111 = F_149 ( V_35 , true ) ;
if ( V_111 )
goto V_475;
V_111 = F_224 ( V_35 ) ;
if ( V_111 )
goto V_476;
F_66 ( V_35 ) ;
V_111 = F_154 ( V_35 ) ;
if ( V_111 )
goto V_477;
F_85 ( & V_4 -> V_211 ) ;
F_227 ( V_4 -> V_159 ) ;
F_228 ( V_35 ) ;
F_207 ( & V_35 -> V_87 , V_4 -> V_199 &
V_462 ) ;
return 0 ;
V_477:
F_215 ( V_35 ) ;
V_476:
F_149 ( V_35 , false ) ;
V_475:
F_146 ( & V_4 -> V_86 -> V_87 ) ;
F_147 ( & V_4 -> V_86 -> V_87 ) ;
F_229 ( & V_4 -> V_86 -> V_87 ) ;
return V_111 ;
}
static int
F_230 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_231 ( V_4 -> V_159 ) ;
if ( F_79 ( V_35 ) ) {
F_81 ( & V_4 -> V_211 ) ;
F_232 ( V_35 ) ;
F_74 ( V_35 ) ;
}
F_233 ( V_4 -> V_159 ) ;
V_4 -> V_159 = NULL ;
F_149 ( V_35 , false ) ;
F_229 ( & V_4 -> V_86 -> V_87 ) ;
F_146 ( & V_4 -> V_86 -> V_87 ) ;
F_147 ( & V_4 -> V_86 -> V_87 ) ;
F_215 ( V_35 ) ;
return 0 ;
}
static void F_71 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_478 * V_479 ;
unsigned int V_28 , V_480 , V_95 , V_481 , V_482 ;
unsigned char V_483 ;
if ( V_35 -> V_215 & V_484 ) {
V_482 = F_49 ( V_4 -> V_97 + V_185 ) ;
V_482 |= 0x8 ;
F_36 ( V_482 , V_4 -> V_97 + V_185 ) ;
return;
}
V_482 = F_49 ( V_4 -> V_97 + V_185 ) ;
V_482 &= ~ 0x8 ;
F_36 ( V_482 , V_4 -> V_97 + V_185 ) ;
if ( V_35 -> V_215 & V_485 ) {
F_36 ( 0xffffffff , V_4 -> V_97 + V_486 ) ;
F_36 ( 0xffffffff , V_4 -> V_97 + V_487 ) ;
return;
}
F_36 ( 0 , V_4 -> V_97 + V_486 ) ;
F_36 ( 0 , V_4 -> V_97 + V_487 ) ;
F_234 (ha, ndev) {
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
V_482 = F_49 ( V_4 -> V_97 + V_486 ) ;
V_482 |= 1 << ( V_483 - 32 ) ;
F_36 ( V_482 , V_4 -> V_97 + V_486 ) ;
} else {
V_482 = F_49 ( V_4 -> V_97 + V_487 ) ;
V_482 |= 1 << V_483 ;
F_36 ( V_482 , V_4 -> V_97 + V_487 ) ;
}
}
}
static int
F_235 ( struct V_34 * V_35 , void * V_81 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_491 * V_61 = V_81 ;
if ( V_61 ) {
if ( ! F_132 ( V_61 -> V_492 ) )
return - V_493 ;
memcpy ( V_35 -> V_137 , V_61 -> V_492 , V_35 -> V_488 ) ;
}
if ( ! F_80 ( V_35 ) )
return 0 ;
F_36 ( V_35 -> V_137 [ 3 ] | ( V_35 -> V_137 [ 2 ] << 8 ) |
( V_35 -> V_137 [ 1 ] << 16 ) | ( V_35 -> V_137 [ 0 ] << 24 ) ,
V_4 -> V_97 + V_139 ) ;
F_36 ( ( V_35 -> V_137 [ 5 ] << 16 ) | ( V_35 -> V_137 [ 4 ] << 24 ) ,
V_4 -> V_97 + V_140 ) ;
return 0 ;
}
static void F_236 ( struct V_34 * V_87 )
{
int V_28 ;
struct V_3 * V_4 = F_10 ( V_87 ) ;
for ( V_28 = 0 ; V_28 < V_494 ; V_28 ++ ) {
if ( V_4 -> V_294 [ V_28 ] > 0 ) {
F_237 ( V_4 -> V_294 [ V_28 ] ) ;
F_123 ( V_4 -> V_294 [ V_28 ] , V_87 ) ;
F_238 ( V_4 -> V_294 [ V_28 ] ) ;
}
}
}
static inline void F_239 ( struct V_34 * V_210 ,
T_13 V_272 )
{
struct V_3 * V_4 = F_10 ( V_210 ) ;
T_13 V_495 = V_272 ^ V_210 -> V_272 ;
V_210 -> V_272 = V_272 ;
if ( V_495 & V_496 ) {
if ( V_272 & V_496 )
V_4 -> V_150 |= V_151 ;
else
V_4 -> V_150 &= ~ V_151 ;
}
}
static int F_240 ( struct V_34 * V_210 ,
T_13 V_272 )
{
struct V_3 * V_4 = F_10 ( V_210 ) ;
T_13 V_495 = V_272 ^ V_210 -> V_272 ;
if ( F_80 ( V_210 ) && V_495 & V_496 ) {
F_81 ( & V_4 -> V_211 ) ;
F_82 ( V_210 ) ;
F_74 ( V_210 ) ;
F_239 ( V_210 , V_272 ) ;
F_66 ( V_210 ) ;
F_241 ( V_210 ) ;
F_84 ( V_210 ) ;
F_85 ( & V_4 -> V_211 ) ;
} else {
F_239 ( V_210 , V_272 ) ;
}
return 0 ;
}
static int F_242 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
struct V_1 * V_497 ;
T_2 V_125 ;
int V_498 ;
unsigned int V_28 ;
#if F_69 ( V_499 )
V_4 -> V_238 = 0xf ;
V_4 -> V_83 = 0xf ;
#else
V_4 -> V_238 = 0x3 ;
V_4 -> V_83 = 0x3 ;
#endif
F_219 ( V_35 ) ;
if ( V_4 -> V_7 )
V_4 -> V_22 = sizeof( struct V_7 ) ;
else
V_4 -> V_22 = sizeof( struct V_1 ) ;
V_498 = ( V_4 -> V_469 + V_4 -> V_472 ) *
V_4 -> V_22 ;
V_497 = F_243 ( & V_4 -> V_86 -> V_87 , V_498 , & V_125 ,
V_381 ) ;
if ( ! V_497 ) {
return - V_89 ;
}
memset ( V_497 , 0 , V_498 ) ;
F_130 ( V_35 ) ;
F_235 ( V_35 , NULL ) ;
for ( V_28 = 0 ; V_28 < V_4 -> V_120 ; V_28 ++ ) {
V_13 = V_4 -> V_14 [ V_28 ] ;
V_13 -> V_36 = V_28 ;
V_13 -> V_20 = (struct V_1 * ) V_497 ;
V_13 -> V_125 = V_125 ;
if ( V_4 -> V_7 ) {
V_125 += sizeof( struct V_7 ) * V_13 -> V_21 ;
V_497 = (struct V_1 * )
( ( (struct V_7 * ) V_497 ) + V_13 -> V_21 ) ;
} else {
V_125 += sizeof( struct V_1 ) * V_13 -> V_21 ;
V_497 += V_13 -> V_21 ;
}
}
for ( V_28 = 0 ; V_28 < V_4 -> V_124 ; V_28 ++ ) {
V_10 = V_4 -> V_11 [ V_28 ] ;
V_10 -> V_36 = V_28 ;
V_10 -> V_18 = (struct V_1 * ) V_497 ;
V_10 -> V_125 = V_125 ;
if ( V_4 -> V_7 ) {
V_125 += sizeof( struct V_7 ) * V_10 -> V_19 ;
V_497 = (struct V_1 * )
( ( (struct V_7 * ) V_497 ) + V_10 -> V_19 ) ;
} else {
V_125 += sizeof( struct V_1 ) * V_10 -> V_19 ;
V_497 += V_10 -> V_19 ;
}
}
V_35 -> V_500 = V_501 ;
V_35 -> V_502 = & V_503 ;
V_35 -> V_504 = & V_505 ;
F_36 ( V_506 , V_4 -> V_97 + V_192 ) ;
F_244 ( V_35 , & V_4 -> V_211 , F_128 , V_507 ) ;
if ( V_4 -> V_74 & V_508 )
V_35 -> V_272 |= V_273 ;
if ( V_4 -> V_74 & V_509 ) {
V_35 -> V_510 = V_511 ;
V_35 -> V_272 |= ( V_512 | V_513
| V_496 | V_514 | V_515 ) ;
V_4 -> V_150 |= V_151 ;
}
if ( V_4 -> V_74 & V_75 ) {
V_4 -> V_83 = 0 ;
V_4 -> V_238 = 0x3f ;
}
V_35 -> V_516 = V_35 -> V_272 ;
F_66 ( V_35 ) ;
return 0 ;
}
static void F_245 ( struct V_365 * V_86 )
{
int V_368 , V_517 ;
int V_518 = 1 ;
struct V_305 * V_306 = V_86 -> V_87 . V_307 ;
if ( ! V_306 )
return;
F_246 ( V_306 , L_27 , & V_518 ) ;
if ( V_518 > 1000 )
V_518 = 1 ;
V_517 = F_247 ( V_306 , L_28 , 0 ) ;
if ( ! F_248 ( V_517 ) )
return;
V_368 = F_249 ( & V_86 -> V_87 , V_517 ,
V_519 , L_29 ) ;
if ( V_368 ) {
F_164 ( & V_86 -> V_87 , L_30 , V_368 ) ;
return;
}
F_250 ( V_518 ) ;
F_251 ( V_517 , 1 ) ;
}
static void F_245 ( struct V_365 * V_86 )
{
}
static void
F_252 ( struct V_365 * V_86 , int * V_520 , int * V_521 )
{
struct V_305 * V_306 = V_86 -> V_87 . V_307 ;
int V_368 ;
* V_520 = * V_521 = 1 ;
if ( ! V_306 || ! F_253 ( V_306 ) )
return;
V_368 = F_246 ( V_306 , L_31 , V_520 ) ;
if ( V_368 )
* V_520 = 1 ;
V_368 = F_246 ( V_306 , L_32 , V_521 ) ;
if ( V_368 )
* V_521 = 1 ;
if ( * V_520 < 1 || * V_520 > V_522 ) {
F_254 ( & V_86 -> V_87 , L_33 ,
* V_520 ) ;
* V_520 = 1 ;
return;
}
if ( * V_521 < 1 || * V_521 > V_523 ) {
F_254 ( & V_86 -> V_87 , L_34 ,
* V_521 ) ;
* V_521 = 1 ;
return;
}
}
static int
F_255 ( struct V_365 * V_86 )
{
struct V_3 * V_4 ;
struct V_194 * V_195 ;
struct V_34 * V_35 ;
int V_28 , V_294 , V_111 = 0 ;
struct V_392 * V_393 ;
const struct V_524 * V_525 ;
static int V_295 ;
struct V_305 * V_306 = V_86 -> V_87 . V_307 , * V_349 ;
int V_526 ;
int V_527 ;
F_252 ( V_86 , & V_526 , & V_527 ) ;
V_35 = F_256 ( sizeof( struct V_3 ) ,
V_526 , V_527 ) ;
if ( ! V_35 )
return - V_89 ;
F_257 ( V_35 , & V_86 -> V_87 ) ;
V_4 = F_10 ( V_35 ) ;
V_525 = F_258 ( V_528 , & V_86 -> V_87 ) ;
if ( V_525 )
V_86 -> V_529 = V_525 -> V_95 ;
V_4 -> V_74 = V_86 -> V_529 -> V_530 ;
V_4 -> V_210 = V_35 ;
V_4 -> V_120 = V_527 ;
V_4 -> V_124 = V_526 ;
#if ! F_69 ( V_147 )
if ( V_4 -> V_74 & V_356 )
V_4 -> V_170 |= V_172 ;
#endif
F_226 ( & V_86 -> V_87 ) ;
V_393 = F_181 ( V_86 , V_395 , 0 ) ;
V_4 -> V_97 = F_259 ( & V_86 -> V_87 , V_393 ) ;
if ( F_33 ( V_4 -> V_97 ) ) {
V_111 = F_158 ( V_4 -> V_97 ) ;
goto V_531;
}
V_4 -> V_86 = V_86 ;
V_4 -> V_295 = V_295 ++ ;
F_260 ( V_86 , V_35 ) ;
if ( F_261 ( V_306 , L_35 , NULL ) )
V_4 -> V_199 |= V_459 ;
V_349 = F_262 ( V_306 , L_36 , 0 ) ;
if ( ! V_349 && F_263 ( V_306 ) ) {
V_111 = F_264 ( V_306 ) ;
if ( V_111 < 0 ) {
F_164 ( & V_86 -> V_87 ,
L_37 ) ;
goto V_532;
}
V_349 = F_265 ( V_306 ) ;
}
V_4 -> V_349 = V_349 ;
V_111 = F_266 ( V_86 -> V_87 . V_307 ) ;
if ( V_111 < 0 ) {
V_195 = F_131 ( & V_86 -> V_87 ) ;
if ( V_195 )
V_4 -> V_153 = V_195 -> V_533 ;
else
V_4 -> V_153 = V_534 ;
} else {
V_4 -> V_153 = V_111 ;
}
V_4 -> V_375 = F_267 ( & V_86 -> V_87 , L_38 ) ;
if ( F_33 ( V_4 -> V_375 ) ) {
V_111 = F_158 ( V_4 -> V_375 ) ;
goto V_535;
}
V_4 -> V_336 = F_267 ( & V_86 -> V_87 , L_39 ) ;
if ( F_33 ( V_4 -> V_336 ) ) {
V_111 = F_158 ( V_4 -> V_336 ) ;
goto V_535;
}
V_4 -> V_430 = F_163 ( V_4 -> V_336 ) ;
V_4 -> V_337 = F_267 ( & V_86 -> V_87 , L_40 ) ;
if ( F_33 ( V_4 -> V_337 ) )
V_4 -> V_337 = NULL ;
V_4 -> V_342 = false ;
F_268 ( & V_4 -> V_340 ) ;
V_4 -> V_343 = F_267 ( & V_86 -> V_87 , L_41 ) ;
if ( F_33 ( V_4 -> V_343 ) )
V_4 -> V_343 = NULL ;
V_4 -> V_7 = V_4 -> V_74 & V_536 ;
V_4 -> V_339 = F_267 ( & V_86 -> V_87 , L_42 ) ;
if ( F_33 ( V_4 -> V_339 ) ) {
V_4 -> V_339 = NULL ;
V_4 -> V_7 = false ;
}
V_111 = F_149 ( V_35 , true ) ;
if ( V_111 )
goto V_535;
V_111 = F_150 ( V_4 -> V_375 ) ;
if ( V_111 )
goto V_537;
V_4 -> V_538 = F_269 ( & V_86 -> V_87 , L_43 ) ;
if ( ! F_33 ( V_4 -> V_538 ) ) {
V_111 = F_270 ( V_4 -> V_538 ) ;
if ( V_111 ) {
F_164 ( & V_86 -> V_87 ,
L_44 , V_111 ) ;
goto V_539;
}
} else {
V_4 -> V_538 = NULL ;
}
F_271 ( & V_86 -> V_87 , V_540 ) ;
F_272 ( & V_86 -> V_87 ) ;
F_273 ( & V_86 -> V_87 ) ;
F_274 ( & V_86 -> V_87 ) ;
F_275 ( & V_86 -> V_87 ) ;
F_245 ( V_86 ) ;
if ( V_4 -> V_7 )
F_276 ( V_86 ) ;
V_111 = F_242 ( V_35 ) ;
if ( V_111 )
goto V_541;
for ( V_28 = 0 ; V_28 < V_494 ; V_28 ++ ) {
V_294 = F_277 ( V_86 , V_28 ) ;
if ( V_294 < 0 ) {
if ( V_28 )
break;
V_111 = V_294 ;
goto V_542;
}
V_111 = F_278 ( & V_86 -> V_87 , V_294 , F_123 ,
0 , V_86 -> V_364 , V_35 ) ;
if ( V_111 )
goto V_542;
V_4 -> V_294 [ V_28 ] = V_294 ;
}
F_279 ( & V_4 -> V_298 ) ;
V_111 = F_160 ( V_86 ) ;
if ( V_111 )
goto V_543;
F_280 ( V_35 ) ;
F_149 ( V_35 , false ) ;
F_229 ( & V_86 -> V_87 ) ;
V_111 = F_281 ( V_35 ) ;
if ( V_111 )
goto V_544;
F_282 ( & V_35 -> V_87 , V_4 -> V_199 &
V_459 ) ;
if ( V_4 -> V_7 && V_4 -> V_299 )
F_11 ( V_35 , L_45 , V_4 -> V_295 ) ;
V_4 -> V_244 = V_545 ;
F_283 ( & V_4 -> V_207 , F_77 ) ;
F_146 ( & V_86 -> V_87 ) ;
F_147 ( & V_86 -> V_87 ) ;
return 0 ;
V_544:
F_173 ( V_4 ) ;
V_543:
V_542:
V_541:
F_284 ( V_86 ) ;
if ( V_4 -> V_538 )
F_285 ( V_4 -> V_538 ) ;
V_539:
F_153 ( V_4 -> V_375 ) ;
V_537:
F_149 ( V_35 , false ) ;
V_535:
V_532:
F_169 ( V_349 ) ;
V_531:
F_286 ( V_35 ) ;
return V_111 ;
}
static int
F_287 ( struct V_365 * V_86 )
{
struct V_34 * V_35 = F_161 ( V_86 ) ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_288 ( & V_4 -> V_207 ) ;
F_284 ( V_86 ) ;
F_289 ( V_35 ) ;
F_173 ( V_4 ) ;
if ( V_4 -> V_538 )
F_285 ( V_4 -> V_538 ) ;
F_169 ( V_4 -> V_349 ) ;
F_286 ( V_35 ) ;
return 0 ;
}
static int T_14 F_290 ( struct V_324 * V_87 )
{
struct V_34 * V_35 = F_291 ( V_87 ) ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_78 () ;
if ( F_80 ( V_35 ) ) {
if ( V_4 -> V_199 & V_462 )
V_4 -> V_199 |= V_200 ;
F_231 ( V_4 -> V_159 ) ;
F_81 ( & V_4 -> V_211 ) ;
F_82 ( V_35 ) ;
F_292 ( V_35 ) ;
F_84 ( V_35 ) ;
F_74 ( V_35 ) ;
F_149 ( V_35 , false ) ;
if ( ! ( V_4 -> V_199 & V_462 ) )
F_229 ( & V_4 -> V_86 -> V_87 ) ;
}
F_86 () ;
if ( V_4 -> V_538 && ! ( V_4 -> V_199 & V_462 ) )
F_285 ( V_4 -> V_538 ) ;
if ( V_4 -> V_337 || V_4 -> V_538 )
V_4 -> V_190 = 0 ;
return 0 ;
}
static int T_14 F_293 ( struct V_324 * V_87 )
{
struct V_34 * V_35 = F_291 ( V_87 ) ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_194 * V_195 = V_4 -> V_86 -> V_87 . V_196 ;
int V_111 ;
int V_130 ;
if ( V_4 -> V_538 && ! ( V_4 -> V_199 & V_462 ) ) {
V_111 = F_270 ( V_4 -> V_538 ) ;
if ( V_111 )
return V_111 ;
}
F_78 () ;
if ( F_80 ( V_35 ) ) {
V_111 = F_149 ( V_35 , true ) ;
if ( V_111 ) {
F_86 () ;
goto V_535;
}
if ( V_4 -> V_199 & V_462 ) {
if ( V_195 && V_195 -> V_204 )
V_195 -> V_204 ( false ) ;
V_130 = F_49 ( V_4 -> V_97 + V_135 ) ;
V_130 &= ~ ( V_202 | V_203 ) ;
F_36 ( V_130 , V_4 -> V_97 + V_135 ) ;
V_4 -> V_199 &= ~ V_200 ;
} else {
F_226 ( & V_4 -> V_86 -> V_87 ) ;
}
F_66 ( V_35 ) ;
F_82 ( V_35 ) ;
F_294 ( V_35 ) ;
F_84 ( V_35 ) ;
F_85 ( & V_4 -> V_211 ) ;
F_227 ( V_4 -> V_159 ) ;
}
F_86 () ;
return 0 ;
V_535:
if ( V_4 -> V_538 )
F_285 ( V_4 -> V_538 ) ;
return V_111 ;
}
static int T_14 F_295 ( struct V_324 * V_87 )
{
struct V_34 * V_35 = F_291 ( V_87 ) ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_153 ( V_4 -> V_375 ) ;
return 0 ;
}
static int T_14 F_296 ( struct V_324 * V_87 )
{
struct V_34 * V_35 = F_291 ( V_87 ) ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
return F_150 ( V_4 -> V_375 ) ;
}
