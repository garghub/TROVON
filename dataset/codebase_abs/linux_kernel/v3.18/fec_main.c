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
static void * F_5 ( void * V_26 , int V_27 )
{
int V_28 ;
unsigned int * V_29 = V_26 ;
for ( V_28 = 0 ; V_28 < F_6 ( V_27 , 4 ) ; V_28 ++ , V_29 ++ )
* V_29 = F_7 ( * V_29 ) ;
return V_26 ;
}
static void F_8 ( void * V_30 , void * V_31 , int V_27 )
{
int V_28 ;
unsigned int * V_32 = V_31 ;
unsigned int * V_33 = V_30 ;
for ( V_28 = 0 ; V_28 < V_27 ; V_28 += 4 , V_32 ++ , V_33 ++ )
* V_33 = F_9 ( V_32 ) ;
}
static void F_10 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_36 = 0 ;
F_12 ( V_35 , L_1 ) ;
F_13 ( L_2 ) ;
V_10 = V_4 -> V_11 [ 0 ] ;
V_2 = V_10 -> V_18 ;
do {
F_13 ( L_3 ,
V_36 ,
V_2 == V_10 -> V_25 ? 'S' : ' ' ,
V_2 == V_10 -> V_24 ? 'H' : ' ' ,
V_2 -> V_37 , V_2 -> V_38 , V_2 -> V_39 ,
V_10 -> V_40 [ V_36 ] ) ;
V_2 = F_1 ( V_2 , V_4 , 0 ) ;
V_36 ++ ;
} while ( V_2 != V_10 -> V_18 );
}
static inline bool F_14 ( struct V_41 * V_42 )
{
return V_42 -> V_43 == F_15 ( V_44 ) && F_16 ( V_42 ) -> V_45 == 4 ;
}
static int
F_17 ( struct V_41 * V_42 , struct V_34 * V_35 )
{
if ( V_42 -> V_46 != V_47 )
return 0 ;
if ( F_18 ( F_19 ( V_42 , 0 ) ) )
return - 1 ;
if ( F_14 ( V_42 ) )
F_16 ( V_42 ) -> V_48 = 0 ;
* ( V_49 * ) ( V_42 -> V_50 + V_42 -> V_51 + V_42 -> V_52 ) = 0 ;
return 0 ;
}
static int
F_20 ( struct V_9 * V_10 ,
struct V_41 * V_42 ,
struct V_34 * V_35 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
const struct V_53 * V_54 =
F_21 ( V_4 -> V_55 ) ;
struct V_1 * V_2 = V_10 -> V_25 ;
struct V_7 * V_56 ;
int V_57 = F_22 ( V_42 ) -> V_57 ;
unsigned short V_58 = F_23 ( V_42 ) ;
int V_59 , V_60 ;
unsigned short V_61 ;
unsigned int V_62 = 0 ;
T_1 * V_63 ;
unsigned int V_36 ;
void * V_26 ;
T_2 V_64 ;
int V_28 ;
for ( V_59 = 0 ; V_59 < V_57 ; V_59 ++ ) {
V_63 = & F_22 ( V_42 ) -> V_65 [ V_59 ] ;
V_2 = F_1 ( V_2 , V_4 , V_58 ) ;
V_56 = (struct V_7 * ) V_2 ;
V_61 = V_2 -> V_37 ;
V_61 &= ~ V_66 ;
V_61 |= ( V_67 | V_68 ) ;
V_60 = F_22 ( V_42 ) -> V_65 [ V_59 ] . V_69 ;
if ( V_59 == V_57 - 1 ) {
V_61 |= ( V_70 | V_71 ) ;
if ( V_4 -> V_7 ) {
V_62 |= V_72 ;
if ( F_18 ( F_22 ( V_42 ) -> V_73 &
V_74 && V_4 -> V_75 ) )
V_62 |= V_76 ;
}
}
if ( V_4 -> V_7 ) {
if ( V_54 -> V_77 & V_78 )
V_62 |= F_24 ( V_58 ) ;
if ( V_42 -> V_46 == V_47 )
V_62 |= V_79 | V_80 ;
V_56 -> V_81 = 0 ;
V_56 -> V_82 = V_62 ;
}
V_26 = F_25 ( V_63 -> V_83 . V_84 ) + V_63 -> V_85 ;
V_36 = F_3 ( V_10 -> V_18 , V_2 , V_4 ) ;
if ( ( ( unsigned long ) V_26 ) & V_4 -> V_86 ||
V_54 -> V_77 & V_87 ) {
memcpy ( V_10 -> V_88 [ V_36 ] , V_26 , V_60 ) ;
V_26 = V_10 -> V_88 [ V_36 ] ;
if ( V_54 -> V_77 & V_87 )
F_5 ( V_26 , V_60 ) ;
}
V_64 = F_26 ( & V_4 -> V_55 -> V_89 , V_26 , V_60 ,
V_90 ) ;
if ( F_27 ( & V_4 -> V_55 -> V_89 , V_64 ) ) {
F_28 ( V_42 ) ;
if ( F_29 () )
F_30 ( V_35 , L_4 ) ;
goto F_27;
}
V_2 -> V_38 = V_64 ;
V_2 -> V_39 = V_60 ;
V_2 -> V_37 = V_61 ;
}
V_10 -> V_25 = V_2 ;
return 0 ;
F_27:
V_2 = V_10 -> V_25 ;
for ( V_28 = 0 ; V_28 < V_59 ; V_28 ++ ) {
V_2 = F_1 ( V_2 , V_4 , V_58 ) ;
F_31 ( & V_4 -> V_55 -> V_89 , V_2 -> V_38 ,
V_2 -> V_39 , V_90 ) ;
}
return V_91 ;
}
static int F_32 ( struct V_9 * V_10 ,
struct V_41 * V_42 , struct V_34 * V_35 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
const struct V_53 * V_54 =
F_21 ( V_4 -> V_55 ) ;
int V_57 = F_22 ( V_42 ) -> V_57 ;
struct V_1 * V_2 , * V_92 ;
void * V_26 ;
T_2 V_64 ;
unsigned short V_61 ;
unsigned short V_93 ;
unsigned short V_58 ;
unsigned int V_62 = 0 ;
unsigned int V_36 ;
int V_94 ;
int V_95 ;
V_94 = F_4 ( V_4 , V_10 ) ;
if ( V_94 < V_96 + 1 ) {
F_28 ( V_42 ) ;
if ( F_29 () )
F_30 ( V_35 , L_5 ) ;
return V_91 ;
}
if ( F_17 ( V_42 , V_35 ) ) {
F_28 ( V_42 ) ;
return V_91 ;
}
V_2 = V_10 -> V_25 ;
V_61 = V_2 -> V_37 ;
V_61 &= ~ V_66 ;
V_26 = V_42 -> V_97 ;
V_93 = F_33 ( V_42 ) ;
V_58 = F_23 ( V_42 ) ;
V_36 = F_3 ( V_10 -> V_18 , V_2 , V_4 ) ;
if ( ( ( unsigned long ) V_26 ) & V_4 -> V_86 ||
V_54 -> V_77 & V_87 ) {
memcpy ( V_10 -> V_88 [ V_36 ] , V_42 -> V_97 , V_93 ) ;
V_26 = V_10 -> V_88 [ V_36 ] ;
if ( V_54 -> V_77 & V_87 )
F_5 ( V_26 , V_93 ) ;
}
V_64 = F_26 ( & V_4 -> V_55 -> V_89 , V_26 , V_93 , V_90 ) ;
if ( F_27 ( & V_4 -> V_55 -> V_89 , V_64 ) ) {
F_28 ( V_42 ) ;
if ( F_29 () )
F_30 ( V_35 , L_4 ) ;
return V_91 ;
}
if ( V_57 ) {
V_95 = F_20 ( V_10 , V_42 , V_35 ) ;
if ( V_95 )
return V_95 ;
} else {
V_61 |= ( V_70 | V_71 ) ;
if ( V_4 -> V_7 ) {
V_62 = V_72 ;
if ( F_18 ( F_22 ( V_42 ) -> V_73 &
V_74 && V_4 -> V_75 ) )
V_62 |= V_76 ;
}
}
if ( V_4 -> V_7 ) {
struct V_7 * V_56 = (struct V_7 * ) V_2 ;
if ( F_18 ( F_22 ( V_42 ) -> V_73 & V_74 &&
V_4 -> V_75 ) )
F_22 ( V_42 ) -> V_73 |= V_98 ;
if ( V_54 -> V_77 & V_78 )
V_62 |= F_24 ( V_58 ) ;
if ( V_42 -> V_46 == V_47 )
V_62 |= V_79 | V_80 ;
V_56 -> V_81 = 0 ;
V_56 -> V_82 = V_62 ;
}
V_92 = V_10 -> V_25 ;
V_36 = F_3 ( V_10 -> V_18 , V_92 , V_4 ) ;
V_10 -> V_40 [ V_36 ] = V_42 ;
V_2 -> V_39 = V_93 ;
V_2 -> V_38 = V_64 ;
V_61 |= ( V_68 | V_67 ) ;
V_2 -> V_37 = V_61 ;
V_2 = F_1 ( V_92 , V_4 , V_58 ) ;
F_34 ( V_42 ) ;
V_10 -> V_25 = V_2 ;
F_35 ( 0 , V_4 -> V_99 + F_36 ( V_58 ) ) ;
return 0 ;
}
static int
F_37 ( struct V_9 * V_10 , struct V_41 * V_42 ,
struct V_34 * V_35 ,
struct V_1 * V_2 , int V_36 , char * V_97 ,
int V_69 , bool V_100 , bool V_101 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
const struct V_53 * V_54 =
F_21 ( V_4 -> V_55 ) ;
struct V_7 * V_56 = F_38 ( V_2 , struct V_7 , V_102 ) ;
unsigned short V_58 = F_23 ( V_42 ) ;
unsigned short V_61 ;
unsigned int V_62 = 0 ;
T_2 V_64 ;
V_61 = V_2 -> V_37 ;
V_61 &= ~ V_66 ;
V_61 |= ( V_67 | V_68 ) ;
if ( ( ( unsigned long ) V_97 ) & V_4 -> V_86 ||
V_54 -> V_77 & V_87 ) {
memcpy ( V_10 -> V_88 [ V_36 ] , V_97 , V_69 ) ;
V_97 = V_10 -> V_88 [ V_36 ] ;
if ( V_54 -> V_77 & V_87 )
F_5 ( V_97 , V_69 ) ;
}
V_64 = F_26 ( & V_4 -> V_55 -> V_89 , V_97 , V_69 , V_90 ) ;
if ( F_27 ( & V_4 -> V_55 -> V_89 , V_64 ) ) {
F_28 ( V_42 ) ;
if ( F_29 () )
F_30 ( V_35 , L_4 ) ;
return V_103 ;
}
V_2 -> V_39 = V_69 ;
V_2 -> V_38 = V_64 ;
if ( V_4 -> V_7 ) {
if ( V_54 -> V_77 & V_78 )
V_62 |= F_24 ( V_58 ) ;
if ( V_42 -> V_46 == V_47 )
V_62 |= V_79 | V_80 ;
V_56 -> V_81 = 0 ;
V_56 -> V_82 = V_62 ;
}
if ( V_100 )
V_61 |= ( V_71 | V_67 ) ;
if ( V_101 ) {
V_61 |= V_70 ;
if ( V_4 -> V_7 )
V_56 -> V_82 |= V_72 ;
}
V_2 -> V_37 = V_61 ;
return 0 ;
}
static int
F_39 ( struct V_9 * V_10 ,
struct V_41 * V_42 , struct V_34 * V_35 ,
struct V_1 * V_2 , int V_36 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
const struct V_53 * V_54 =
F_21 ( V_4 -> V_55 ) ;
int V_104 = F_40 ( V_42 ) + F_41 ( V_42 ) ;
struct V_7 * V_56 = F_38 ( V_2 , struct V_7 , V_102 ) ;
unsigned short V_58 = F_23 ( V_42 ) ;
void * V_26 ;
unsigned long V_105 ;
unsigned short V_61 ;
unsigned int V_62 = 0 ;
V_61 = V_2 -> V_37 ;
V_61 &= ~ V_66 ;
V_61 |= ( V_67 | V_68 ) ;
V_26 = V_10 -> V_106 + V_36 * V_107 ;
V_105 = V_10 -> V_108 + V_36 * V_107 ;
if ( ( ( unsigned long ) V_26 ) & V_4 -> V_86 ||
V_54 -> V_77 & V_87 ) {
memcpy ( V_10 -> V_88 [ V_36 ] , V_42 -> V_97 , V_104 ) ;
V_26 = V_10 -> V_88 [ V_36 ] ;
if ( V_54 -> V_77 & V_87 )
F_5 ( V_26 , V_104 ) ;
V_105 = F_26 ( & V_4 -> V_55 -> V_89 , V_26 ,
V_104 , V_90 ) ;
if ( F_27 ( & V_4 -> V_55 -> V_89 , V_105 ) ) {
F_28 ( V_42 ) ;
if ( F_29 () )
F_30 ( V_35 , L_4 ) ;
return V_103 ;
}
}
V_2 -> V_38 = V_105 ;
V_2 -> V_39 = V_104 ;
if ( V_4 -> V_7 ) {
if ( V_54 -> V_77 & V_78 )
V_62 |= F_24 ( V_58 ) ;
if ( V_42 -> V_46 == V_47 )
V_62 |= V_79 | V_80 ;
V_56 -> V_81 = 0 ;
V_56 -> V_82 = V_62 ;
}
V_2 -> V_37 = V_61 ;
return 0 ;
}
static int F_42 ( struct V_9 * V_10 ,
struct V_41 * V_42 ,
struct V_34 * V_35 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
int V_104 = F_40 ( V_42 ) + F_41 ( V_42 ) ;
int V_109 , V_110 ;
struct V_1 * V_2 = V_10 -> V_25 ;
unsigned short V_58 = F_23 ( V_42 ) ;
struct V_111 V_112 ;
unsigned int V_36 = 0 ;
int V_95 ;
const struct V_53 * V_54 =
F_21 ( V_4 -> V_55 ) ;
if ( F_43 ( V_42 ) >= F_4 ( V_4 , V_10 ) ) {
F_28 ( V_42 ) ;
if ( F_29 () )
F_30 ( V_35 , L_6 ) ;
return V_91 ;
}
if ( F_17 ( V_42 , V_35 ) ) {
F_28 ( V_42 ) ;
return V_91 ;
}
F_44 ( V_42 , & V_112 ) ;
V_109 = V_42 -> V_27 - V_104 ;
while ( V_109 > 0 ) {
char * V_113 ;
V_36 = F_3 ( V_10 -> V_18 , V_2 , V_4 ) ;
V_110 = F_45 ( int , F_22 ( V_42 ) -> V_114 , V_109 ) ;
V_109 -= V_110 ;
V_113 = V_10 -> V_106 + V_36 * V_107 ;
F_46 ( V_42 , V_113 , & V_112 , V_110 , V_109 == 0 ) ;
V_95 = F_39 ( V_10 , V_42 , V_35 , V_2 , V_36 ) ;
if ( V_95 )
goto V_115;
while ( V_110 > 0 ) {
int V_69 ;
V_69 = F_45 ( int , V_112 . V_69 , V_110 ) ;
V_2 = F_1 ( V_2 , V_4 , V_58 ) ;
V_36 = F_3 ( V_10 -> V_18 ,
V_2 , V_4 ) ;
V_95 = F_37 ( V_10 , V_42 , V_35 ,
V_2 , V_36 ,
V_112 . V_97 , V_69 ,
V_69 == V_110 ,
V_109 == 0 ) ;
if ( V_95 )
goto V_115;
V_110 -= V_69 ;
F_47 ( V_42 , & V_112 , V_69 ) ;
}
V_2 = F_1 ( V_2 , V_4 , V_58 ) ;
}
V_10 -> V_40 [ V_36 ] = V_42 ;
F_34 ( V_42 ) ;
V_10 -> V_25 = V_2 ;
if ( ! ( V_54 -> V_77 & V_116 ) ||
! F_48 ( V_4 -> V_99 + F_36 ( V_58 ) ) ||
! F_48 ( V_4 -> V_99 + F_36 ( V_58 ) ) ||
! F_48 ( V_4 -> V_99 + F_36 ( V_58 ) ) ||
! F_48 ( V_4 -> V_99 + F_36 ( V_58 ) ) )
F_35 ( 0 , V_4 -> V_99 + F_36 ( V_58 ) ) ;
return 0 ;
V_115:
return V_95 ;
}
static T_3
F_49 ( struct V_41 * V_42 , struct V_34 * V_35 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
int V_94 ;
unsigned short V_58 ;
struct V_9 * V_10 ;
struct V_117 * V_118 ;
int V_95 ;
V_58 = F_23 ( V_42 ) ;
V_10 = V_4 -> V_11 [ V_58 ] ;
V_118 = F_50 ( V_35 , V_58 ) ;
if ( F_51 ( V_42 ) )
V_95 = F_42 ( V_10 , V_42 , V_35 ) ;
else
V_95 = F_32 ( V_10 , V_42 , V_35 ) ;
if ( V_95 )
return V_95 ;
V_94 = F_4 ( V_4 , V_10 ) ;
if ( V_94 <= V_10 -> V_119 )
F_52 ( V_118 ) ;
return V_91 ;
}
static void F_53 ( struct V_34 * V_89 )
{
struct V_3 * V_4 = F_11 ( V_89 ) ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
unsigned int V_28 ;
unsigned int V_120 ;
for ( V_120 = 0 ; V_120 < V_4 -> V_121 ; V_120 ++ ) {
V_13 = V_4 -> V_14 [ V_120 ] ;
V_2 = V_13 -> V_20 ;
for ( V_28 = 0 ; V_28 < V_13 -> V_21 ; V_28 ++ ) {
if ( V_2 -> V_38 )
V_2 -> V_37 = V_122 ;
else
V_2 -> V_37 = 0 ;
V_2 = F_1 ( V_2 , V_4 , V_120 ) ;
}
V_2 = F_2 ( V_2 , V_4 , V_120 ) ;
V_2 -> V_37 |= V_123 ;
V_13 -> V_124 = V_13 -> V_20 ;
}
for ( V_120 = 0 ; V_120 < V_4 -> V_125 ; V_120 ++ ) {
V_10 = V_4 -> V_11 [ V_120 ] ;
V_2 = V_10 -> V_18 ;
V_10 -> V_25 = V_2 ;
for ( V_28 = 0 ; V_28 < V_10 -> V_19 ; V_28 ++ ) {
V_2 -> V_37 = 0 ;
if ( V_10 -> V_40 [ V_28 ] ) {
F_28 ( V_10 -> V_40 [ V_28 ] ) ;
V_10 -> V_40 [ V_28 ] = NULL ;
}
V_2 -> V_38 = 0 ;
V_2 = F_1 ( V_2 , V_4 , V_120 ) ;
}
V_2 = F_2 ( V_2 , V_4 , V_120 ) ;
V_2 -> V_37 |= V_123 ;
V_10 -> V_24 = V_2 ;
}
}
static void F_54 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_121 ; V_28 ++ )
F_35 ( 0 , V_4 -> V_99 + F_55 ( V_28 ) ) ;
}
static void F_56 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_121 ; V_28 ++ ) {
V_13 = V_4 -> V_14 [ V_28 ] ;
F_35 ( V_13 -> V_126 , V_4 -> V_99 + F_57 ( V_28 ) ) ;
if ( V_28 )
F_35 ( V_127 | F_58 ( V_28 ) ,
V_4 -> V_99 + F_59 ( V_28 ) ) ;
}
for ( V_28 = 0 ; V_28 < V_4 -> V_125 ; V_28 ++ ) {
V_10 = V_4 -> V_11 [ V_28 ] ;
F_35 ( V_10 -> V_126 , V_4 -> V_99 + F_60 ( V_28 ) ) ;
if ( V_28 )
F_35 ( V_128 | F_61 ( V_28 ) ,
V_4 -> V_99 + F_62 ( V_28 ) ) ;
}
}
static void F_63 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
struct V_9 * V_10 ;
int V_28 , V_129 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_125 ; V_28 ++ ) {
V_10 = V_4 -> V_11 [ V_28 ] ;
for ( V_129 = 0 ; V_129 < V_10 -> V_19 ; V_129 ++ ) {
if ( V_10 -> V_40 [ V_129 ] ) {
F_28 ( V_10 -> V_40 [ V_129 ] ) ;
V_10 -> V_40 [ V_129 ] = NULL ;
}
}
}
}
static void
F_64 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
const struct V_53 * V_54 =
F_21 ( V_4 -> V_55 ) ;
T_4 V_130 ;
T_4 V_131 [ 2 ] ;
T_4 V_132 = V_133 | 0x04 ;
T_4 V_134 = 0x2 ;
if ( V_54 && V_54 -> V_77 & V_78 ) {
F_35 ( 0 , V_4 -> V_99 + V_135 ) ;
} else {
F_35 ( 1 , V_4 -> V_99 + V_135 ) ;
F_65 ( 10 ) ;
}
if ( V_54 -> V_77 & V_136 ) {
memcpy ( & V_131 , V_35 -> V_137 , V_138 ) ;
F_35 ( F_7 ( V_131 [ 0 ] ) , V_4 -> V_99 + V_139 ) ;
F_35 ( F_7 ( V_131 [ 1 ] ) , V_4 -> V_99 + V_140 ) ;
}
F_35 ( 0xffc00000 , V_4 -> V_99 + V_141 ) ;
F_35 ( V_142 , V_4 -> V_99 + V_143 ) ;
F_53 ( V_35 ) ;
F_56 ( V_35 ) ;
F_63 ( V_35 ) ;
if ( V_4 -> V_144 == V_145 ) {
F_35 ( 0x04 , V_4 -> V_99 + V_146 ) ;
} else {
V_132 |= 0x02 ;
F_35 ( 0x0 , V_4 -> V_99 + V_146 ) ;
}
F_35 ( V_4 -> V_147 , V_4 -> V_99 + V_148 ) ;
#if ! F_66 ( V_149 )
V_130 = F_48 ( V_4 -> V_99 + V_150 ) ;
if ( V_4 -> V_151 & V_152 )
V_130 |= V_153 ;
else
V_130 &= ~ V_153 ;
F_35 ( V_130 , V_4 -> V_99 + V_150 ) ;
#endif
if ( V_54 -> V_77 & V_136 ) {
V_132 |= 0x40000000 | 0x00000020 ;
if ( V_4 -> V_154 == V_155 )
V_132 |= ( 1 << 6 ) ;
else if ( V_4 -> V_154 == V_156 )
V_132 |= ( 1 << 8 ) ;
else
V_132 &= ~ ( 1 << 8 ) ;
if ( V_4 -> V_157 ) {
if ( V_4 -> V_157 -> V_158 == V_159 )
V_134 |= ( 1 << 5 ) ;
else if ( V_4 -> V_157 -> V_158 == V_160 )
V_132 &= ~ ( 1 << 9 ) ;
else
V_132 |= ( 1 << 9 ) ;
}
} else {
#ifdef F_67
if ( V_54 -> V_77 & V_161 ) {
T_4 V_162 ;
F_35 ( 0 , V_4 -> V_99 + F_67 ) ;
while ( F_48 ( V_4 -> V_99 + F_67 ) & 4 )
F_65 ( 1 ) ;
V_162 = ( V_4 -> V_154 == V_156 )
? V_163 : V_164 ;
if ( V_4 -> V_157 && V_4 -> V_157 -> V_158 == V_165 )
V_162 |= V_166 ;
F_35 ( V_162 , V_4 -> V_99 + V_167 ) ;
F_35 ( 2 , V_4 -> V_99 + F_67 ) ;
}
#endif
}
#if ! F_66 ( V_149 )
if ( ( V_4 -> V_168 & V_169 ) ||
( ( V_4 -> V_168 & V_170 ) &&
V_4 -> V_157 && V_4 -> V_157 -> V_171 ) ) {
V_132 |= V_172 ;
F_35 ( V_173 , V_4 -> V_99 + V_174 ) ;
F_35 ( V_175 , V_4 -> V_99 + V_176 ) ;
F_35 ( V_177 , V_4 -> V_99 + V_178 ) ;
F_35 ( V_179 , V_4 -> V_99 + V_180 ) ;
F_35 ( V_181 , V_4 -> V_99 + V_182 ) ;
} else {
V_132 &= ~ V_172 ;
}
#endif
F_35 ( V_132 , V_4 -> V_99 + V_183 ) ;
F_68 ( V_35 ) ;
#ifndef V_149
F_35 ( 0 , V_4 -> V_99 + V_184 ) ;
F_35 ( 0 , V_4 -> V_99 + V_185 ) ;
#endif
if ( V_54 -> V_77 & V_136 ) {
V_134 |= ( 1 << 8 ) ;
F_35 ( 1 << 8 , V_4 -> V_99 + V_186 ) ;
}
if ( V_4 -> V_7 )
V_134 |= ( 1 << 4 ) ;
#ifndef V_149
F_35 ( 0 << 31 , V_4 -> V_99 + V_187 ) ;
#endif
F_35 ( V_134 , V_4 -> V_99 + V_135 ) ;
F_54 ( V_35 ) ;
if ( V_4 -> V_7 )
F_69 ( V_35 ) ;
F_35 ( V_188 , V_4 -> V_99 + V_189 ) ;
F_70 ( V_35 ) ;
}
static void
F_71 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
const struct V_53 * V_54 =
F_21 ( V_4 -> V_55 ) ;
T_4 V_190 = F_48 ( V_4 -> V_99 + V_183 ) & ( 1 << 8 ) ;
if ( V_4 -> V_191 ) {
F_35 ( 1 , V_4 -> V_99 + V_146 ) ;
F_65 ( 10 ) ;
if ( ! ( F_48 ( V_4 -> V_99 + V_141 ) & V_192 ) )
F_30 ( V_35 , L_7 ) ;
}
if ( V_54 && V_54 -> V_77 & V_78 ) {
F_35 ( 0 , V_4 -> V_99 + V_135 ) ;
} else {
F_35 ( 1 , V_4 -> V_99 + V_135 ) ;
F_65 ( 10 ) ;
}
F_35 ( V_4 -> V_147 , V_4 -> V_99 + V_148 ) ;
F_35 ( V_188 , V_4 -> V_99 + V_189 ) ;
if ( V_54 -> V_77 & V_136 ) {
F_35 ( 2 , V_4 -> V_99 + V_135 ) ;
F_35 ( V_190 , V_4 -> V_99 + V_183 ) ;
}
}
static void
F_72 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
F_10 ( V_35 ) ;
V_35 -> V_193 . V_194 ++ ;
F_73 ( & V_4 -> V_195 ) ;
}
static void F_74 ( struct V_196 * V_197 )
{
struct V_3 * V_4 =
F_38 ( V_197 , struct V_3 , V_195 ) ;
struct V_34 * V_35 = V_4 -> V_198 ;
F_75 () ;
if ( F_76 ( V_35 ) || F_77 ( V_35 ) ) {
F_78 ( & V_4 -> V_199 ) ;
F_79 ( V_35 ) ;
F_64 ( V_35 ) ;
F_80 ( V_35 ) ;
F_81 ( V_35 ) ;
F_82 ( & V_4 -> V_199 ) ;
}
F_83 () ;
}
static void
F_84 ( struct V_3 * V_4 , unsigned V_200 ,
struct V_201 * V_202 )
{
unsigned long V_203 ;
T_5 V_204 ;
F_85 ( & V_4 -> V_205 , V_203 ) ;
V_204 = F_86 ( & V_4 -> V_206 , V_200 ) ;
F_87 ( & V_4 -> V_205 , V_203 ) ;
memset ( V_202 , 0 , sizeof( * V_202 ) ) ;
V_202 -> V_207 = F_88 ( V_204 ) ;
}
static void
F_89 ( struct V_34 * V_35 , T_6 V_5 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
unsigned short V_61 ;
struct V_41 * V_42 ;
struct V_9 * V_10 ;
struct V_117 * V_118 ;
int V_36 = 0 ;
int V_94 ;
V_4 = F_11 ( V_35 ) ;
V_5 = F_90 ( V_5 ) ;
V_10 = V_4 -> V_11 [ V_5 ] ;
V_118 = F_50 ( V_35 , V_5 ) ;
V_2 = V_10 -> V_24 ;
V_2 = F_1 ( V_2 , V_4 , V_5 ) ;
while ( ( ( V_61 = V_2 -> V_37 ) & V_68 ) == 0 ) {
if ( V_2 == V_10 -> V_25 )
break;
V_36 = F_3 ( V_10 -> V_18 , V_2 , V_4 ) ;
V_42 = V_10 -> V_40 [ V_36 ] ;
V_10 -> V_40 [ V_36 ] = NULL ;
if ( ! F_91 ( V_10 , V_2 -> V_38 ) )
F_31 ( & V_4 -> V_55 -> V_89 , V_2 -> V_38 ,
V_2 -> V_39 , V_90 ) ;
V_2 -> V_38 = 0 ;
if ( ! V_42 ) {
V_2 = F_1 ( V_2 , V_4 , V_5 ) ;
continue;
}
if ( V_61 & ( V_208 | V_209 |
V_210 | V_211 |
V_212 ) ) {
V_35 -> V_193 . V_194 ++ ;
if ( V_61 & V_208 )
V_35 -> V_193 . V_213 ++ ;
if ( V_61 & V_209 )
V_35 -> V_193 . V_214 ++ ;
if ( V_61 & V_210 )
V_35 -> V_193 . V_215 ++ ;
if ( V_61 & V_211 )
V_35 -> V_193 . V_216 ++ ;
if ( V_61 & V_212 )
V_35 -> V_193 . V_217 ++ ;
} else {
V_35 -> V_193 . V_218 ++ ;
V_35 -> V_193 . V_219 += V_42 -> V_27 ;
}
if ( F_18 ( F_22 ( V_42 ) -> V_73 & V_98 ) &&
V_4 -> V_7 ) {
struct V_201 V_220 ;
struct V_7 * V_56 = (struct V_7 * ) V_2 ;
F_84 ( V_4 , V_56 -> V_200 , & V_220 ) ;
F_92 ( V_42 , & V_220 ) ;
}
if ( V_61 & V_221 )
V_35 -> V_193 . V_222 ++ ;
F_28 ( V_42 ) ;
V_10 -> V_24 = V_2 ;
V_2 = F_1 ( V_2 , V_4 , V_5 ) ;
if ( F_93 ( V_35 ) ) {
V_94 = F_4 ( V_4 , V_10 ) ;
if ( V_94 >= V_10 -> V_223 )
F_94 ( V_118 ) ;
}
}
if ( V_2 != V_10 -> V_25 &&
F_48 ( V_4 -> V_99 + F_36 ( V_5 ) ) == 0 )
F_35 ( 0 , V_4 -> V_99 + F_36 ( V_5 ) ) ;
}
static void
F_95 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
T_6 V_5 ;
F_96 (queue_id, &fep->work_tx, FEC_ENET_MAX_TX_QS) {
F_97 ( V_5 , & V_4 -> V_224 ) ;
F_89 ( V_35 , V_5 ) ;
}
return;
}
static int
F_98 ( struct V_34 * V_35 , struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
int V_225 ;
V_225 = ( ( unsigned long ) V_42 -> V_97 ) & V_4 -> V_226 ;
if ( V_225 )
F_99 ( V_42 , V_4 -> V_226 + 1 - V_225 ) ;
V_2 -> V_38 = F_26 ( & V_4 -> V_55 -> V_89 , V_42 -> V_97 ,
V_227 - V_4 -> V_226 ,
V_228 ) ;
if ( F_27 ( & V_4 -> V_55 -> V_89 , V_2 -> V_38 ) ) {
if ( F_29 () )
F_30 ( V_35 , L_8 ) ;
return - V_229 ;
}
return 0 ;
}
static bool F_100 ( struct V_34 * V_35 , struct V_41 * * V_42 ,
struct V_1 * V_2 , T_4 V_230 , bool V_231 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
struct V_41 * V_232 ;
if ( V_230 > V_4 -> V_233 )
return false ;
V_232 = F_101 ( V_35 , V_230 ) ;
if ( ! V_232 )
return false ;
F_102 ( & V_4 -> V_55 -> V_89 , V_2 -> V_38 ,
V_227 - V_4 -> V_226 ,
V_228 ) ;
if ( ! V_231 )
memcpy ( V_232 -> V_97 , ( * V_42 ) -> V_97 , V_230 ) ;
else
F_8 ( V_232 -> V_97 , ( * V_42 ) -> V_97 , V_230 ) ;
* V_42 = V_232 ;
return true ;
}
static int
F_103 ( struct V_34 * V_35 , int V_234 , T_6 V_5 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
const struct V_53 * V_54 =
F_21 ( V_4 -> V_55 ) ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
unsigned short V_61 ;
struct V_41 * V_235 = NULL ;
struct V_41 * V_42 ;
T_7 V_236 ;
T_8 * V_97 ;
int V_237 = 0 ;
struct V_7 * V_56 = NULL ;
bool V_238 = false ;
T_6 V_239 ;
int V_36 = 0 ;
bool V_240 ;
bool V_241 = V_54 -> V_77 & V_87 ;
#ifdef F_104
F_105 () ;
#endif
V_5 = F_90 ( V_5 ) ;
V_13 = V_4 -> V_14 [ V_5 ] ;
V_2 = V_13 -> V_124 ;
while ( ! ( ( V_61 = V_2 -> V_37 ) & V_122 ) ) {
if ( V_237 >= V_234 )
break;
V_237 ++ ;
if ( ( V_61 & V_242 ) == 0 )
F_30 ( V_35 , L_9 ) ;
if ( V_61 & ( V_243 | V_244 | V_245 |
V_246 | V_247 ) ) {
V_35 -> V_193 . V_248 ++ ;
if ( V_61 & ( V_243 | V_244 ) ) {
V_35 -> V_193 . V_249 ++ ;
}
if ( V_61 & V_245 )
V_35 -> V_193 . V_250 ++ ;
if ( V_61 & V_246 )
V_35 -> V_193 . V_251 ++ ;
if ( V_61 & V_247 )
V_35 -> V_193 . V_252 ++ ;
}
if ( V_61 & V_253 ) {
V_35 -> V_193 . V_248 ++ ;
V_35 -> V_193 . V_250 ++ ;
goto V_254;
}
V_35 -> V_193 . V_255 ++ ;
V_236 = V_2 -> V_39 ;
V_35 -> V_193 . V_256 += V_236 ;
V_36 = F_3 ( V_13 -> V_20 , V_2 , V_4 ) ;
V_42 = V_13 -> V_257 [ V_36 ] ;
V_240 = F_100 ( V_35 , & V_42 , V_2 , V_236 - 4 ,
V_241 ) ;
if ( ! V_240 ) {
V_235 = F_101 ( V_35 , V_227 ) ;
if ( F_18 ( ! V_235 ) ) {
V_35 -> V_193 . V_258 ++ ;
goto V_254;
}
F_31 ( & V_4 -> V_55 -> V_89 , V_2 -> V_38 ,
V_227 - V_4 -> V_226 ,
V_228 ) ;
}
F_106 ( V_42 -> V_97 - V_259 ) ;
F_107 ( V_42 , V_236 - 4 ) ;
V_97 = V_42 -> V_97 ;
if ( ! V_240 && V_241 )
F_5 ( V_97 , V_236 ) ;
V_56 = NULL ;
if ( V_4 -> V_7 )
V_56 = (struct V_7 * ) V_2 ;
V_238 = false ;
if ( ( V_35 -> V_260 & V_261 ) &&
V_4 -> V_7 && ( V_56 -> V_82 & V_262 ) ) {
struct V_263 * V_264 =
(struct V_263 * ) ( V_97 + V_265 ) ;
V_239 = F_108 ( V_264 -> V_266 ) ;
V_238 = true ;
F_109 ( V_42 , V_267 ,
V_97 , ( 2 * V_138 ) ) ;
F_110 ( V_42 , V_267 ) ;
}
V_42 -> V_43 = F_111 ( V_42 , V_35 ) ;
if ( V_4 -> V_268 && V_4 -> V_7 )
F_84 ( V_4 , V_56 -> V_200 ,
F_112 ( V_42 ) ) ;
if ( V_4 -> V_7 &&
( V_4 -> V_151 & V_152 ) ) {
if ( ! ( V_56 -> V_82 & V_269 ) ) {
V_42 -> V_46 = V_270 ;
} else {
F_113 ( V_42 ) ;
}
}
if ( V_238 )
F_114 ( V_42 ,
F_15 ( V_271 ) ,
V_239 ) ;
F_115 ( & V_4 -> V_199 , V_42 ) ;
if ( V_240 ) {
F_116 ( & V_4 -> V_55 -> V_89 , V_2 -> V_38 ,
V_227 - V_4 -> V_226 ,
V_228 ) ;
} else {
V_13 -> V_257 [ V_36 ] = V_235 ;
F_98 ( V_35 , V_2 , V_235 ) ;
}
V_254:
V_61 &= ~ V_272 ;
V_61 |= V_122 ;
V_2 -> V_37 = V_61 ;
if ( V_4 -> V_7 ) {
struct V_7 * V_56 = (struct V_7 * ) V_2 ;
V_56 -> V_82 = V_273 ;
V_56 -> V_274 = 0 ;
V_56 -> V_81 = 0 ;
}
V_2 = F_1 ( V_2 , V_4 , V_5 ) ;
F_35 ( 0 , V_4 -> V_99 + F_55 ( V_5 ) ) ;
}
V_13 -> V_124 = V_2 ;
return V_237 ;
}
static int
F_117 ( struct V_34 * V_35 , int V_234 )
{
int V_237 = 0 ;
T_6 V_5 ;
struct V_3 * V_4 = F_11 ( V_35 ) ;
F_96 (queue_id, &fep->work_rx, FEC_ENET_MAX_RX_QS) {
F_97 ( V_5 , & V_4 -> V_275 ) ;
V_237 += F_103 ( V_35 ,
V_234 - V_237 , V_5 ) ;
}
return V_237 ;
}
static bool
F_118 ( struct V_3 * V_4 , T_9 V_276 )
{
if ( V_276 == 0 )
return false ;
if ( V_276 & V_277 )
V_4 -> V_275 |= ( 1 << 2 ) ;
if ( V_276 & V_278 )
V_4 -> V_275 |= ( 1 << 0 ) ;
if ( V_276 & V_279 )
V_4 -> V_275 |= ( 1 << 1 ) ;
if ( V_276 & V_280 )
V_4 -> V_224 |= ( 1 << 2 ) ;
if ( V_276 & V_281 )
V_4 -> V_224 |= ( 1 << 0 ) ;
if ( V_276 & V_282 )
V_4 -> V_224 |= ( 1 << 1 ) ;
return true ;
}
static T_10
F_119 ( int V_283 , void * V_284 )
{
struct V_34 * V_35 = V_284 ;
struct V_3 * V_4 = F_11 ( V_35 ) ;
const unsigned V_285 = V_277 | V_280 ;
T_9 V_276 ;
T_10 V_95 = V_286 ;
V_276 = F_48 ( V_4 -> V_99 + V_141 ) ;
F_35 ( V_276 & ~ V_285 , V_4 -> V_99 + V_141 ) ;
F_118 ( V_4 , V_276 ) ;
if ( V_276 & V_285 ) {
V_95 = V_287 ;
F_35 ( V_288 , V_4 -> V_99 + V_189 ) ;
F_120 ( & V_4 -> V_199 ) ;
}
if ( V_276 & V_288 ) {
V_95 = V_287 ;
F_121 ( & V_4 -> V_289 ) ;
}
if ( V_4 -> V_290 )
F_122 ( V_4 ) ;
return V_95 ;
}
static int F_123 ( struct V_291 * V_199 , int V_234 )
{
struct V_34 * V_35 = V_199 -> V_89 ;
struct V_3 * V_4 = F_11 ( V_35 ) ;
int V_292 ;
F_35 ( V_277 | V_280 , V_4 -> V_99 + V_141 ) ;
V_292 = F_117 ( V_35 , V_234 ) ;
F_95 ( V_35 ) ;
if ( V_292 < V_234 ) {
F_124 ( V_199 ) ;
F_35 ( V_188 , V_4 -> V_99 + V_189 ) ;
}
return V_292 ;
}
static void F_125 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
struct V_293 * V_294 = F_126 ( & V_4 -> V_55 -> V_89 ) ;
unsigned char * V_295 , V_296 [ V_138 ] ;
V_295 = V_297 ;
if ( ! F_127 ( V_295 ) ) {
struct V_298 * V_299 = V_4 -> V_55 -> V_89 . V_300 ;
if ( V_299 ) {
const char * V_301 = F_128 ( V_299 ) ;
if ( V_301 )
V_295 = ( unsigned char * ) V_301 ;
}
}
if ( ! F_127 ( V_295 ) ) {
#ifdef V_149
if ( V_302 )
V_295 = ( unsigned char * ) V_302 ;
#else
if ( V_294 )
V_295 = ( unsigned char * ) & V_294 -> V_301 ;
#endif
}
if ( ! F_127 ( V_295 ) ) {
* ( ( V_303 * ) & V_296 [ 0 ] ) =
F_7 ( F_48 ( V_4 -> V_99 + V_139 ) ) ;
* ( ( V_304 * ) & V_296 [ 4 ] ) =
F_129 ( F_48 ( V_4 -> V_99 + V_140 ) >> 16 ) ;
V_295 = & V_296 [ 0 ] ;
}
if ( ! F_127 ( V_295 ) ) {
F_30 ( V_35 , L_10 , V_295 ) ;
F_130 ( V_35 ) ;
F_12 ( V_35 , L_11 ,
V_35 -> V_137 ) ;
return;
}
memcpy ( V_35 -> V_137 , V_295 , V_138 ) ;
if ( V_295 == V_297 )
V_35 -> V_137 [ V_138 - 1 ] = V_297 [ V_138 - 1 ] + V_4 -> V_284 ;
}
static void F_131 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
struct V_305 * V_157 = V_4 -> V_157 ;
int V_306 = 0 ;
if ( V_4 -> V_307 && V_157 -> V_308 == V_309 ) {
V_157 -> V_308 = V_310 ;
return;
}
if ( ! F_77 ( V_35 ) || ! F_76 ( V_35 ) ) {
V_4 -> V_191 = 0 ;
} else if ( V_157 -> V_191 ) {
if ( ! V_4 -> V_191 ) {
V_4 -> V_191 = V_157 -> V_191 ;
V_306 = 1 ;
}
if ( V_4 -> V_144 != V_157 -> V_311 ) {
V_4 -> V_144 = V_157 -> V_311 ;
V_306 = 1 ;
}
if ( V_157 -> V_158 != V_4 -> V_158 ) {
V_4 -> V_158 = V_157 -> V_158 ;
V_306 = 1 ;
}
if ( V_306 ) {
F_78 ( & V_4 -> V_199 ) ;
F_79 ( V_35 ) ;
F_64 ( V_35 ) ;
F_80 ( V_35 ) ;
F_81 ( V_35 ) ;
F_82 ( & V_4 -> V_199 ) ;
}
} else {
if ( V_4 -> V_191 ) {
F_78 ( & V_4 -> V_199 ) ;
F_79 ( V_35 ) ;
F_71 ( V_35 ) ;
F_81 ( V_35 ) ;
F_82 ( & V_4 -> V_199 ) ;
V_4 -> V_191 = V_157 -> V_191 ;
V_306 = 1 ;
}
}
if ( V_306 )
F_132 ( V_157 ) ;
}
static int F_133 ( struct V_312 * V_313 , int V_314 , int V_315 )
{
struct V_3 * V_4 = V_313 -> V_316 ;
unsigned long V_317 ;
V_4 -> V_307 = 0 ;
F_134 ( & V_4 -> V_289 ) ;
F_35 ( V_318 | V_319 |
F_135 ( V_314 ) | F_136 ( V_315 ) |
V_320 , V_4 -> V_99 + V_321 ) ;
V_317 = F_137 ( & V_4 -> V_289 ,
F_138 ( V_322 ) ) ;
if ( V_317 == 0 ) {
V_4 -> V_307 = 1 ;
F_30 ( V_4 -> V_198 , L_12 ) ;
return - V_323 ;
}
return F_139 ( F_48 ( V_4 -> V_99 + V_321 ) ) ;
}
static int F_140 ( struct V_312 * V_313 , int V_314 , int V_315 ,
T_6 V_324 )
{
struct V_3 * V_4 = V_313 -> V_316 ;
unsigned long V_317 ;
V_4 -> V_307 = 0 ;
F_134 ( & V_4 -> V_289 ) ;
F_35 ( V_318 | V_325 |
F_135 ( V_314 ) | F_136 ( V_315 ) |
V_320 | F_139 ( V_324 ) ,
V_4 -> V_99 + V_321 ) ;
V_317 = F_137 ( & V_4 -> V_289 ,
F_138 ( V_322 ) ) ;
if ( V_317 == 0 ) {
V_4 -> V_307 = 1 ;
F_30 ( V_4 -> V_198 , L_13 ) ;
return - V_323 ;
}
return 0 ;
}
static int F_141 ( struct V_34 * V_35 , bool V_326 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
int V_95 ;
if ( V_326 ) {
V_95 = F_142 ( V_4 -> V_327 ) ;
if ( V_95 )
return V_95 ;
V_95 = F_142 ( V_4 -> V_328 ) ;
if ( V_95 )
goto V_329;
if ( V_4 -> V_330 ) {
V_95 = F_142 ( V_4 -> V_330 ) ;
if ( V_95 )
goto V_331;
}
if ( V_4 -> V_332 ) {
F_143 ( & V_4 -> V_333 ) ;
V_95 = F_142 ( V_4 -> V_332 ) ;
if ( V_95 ) {
F_144 ( & V_4 -> V_333 ) ;
goto V_334;
} else {
V_4 -> V_335 = true ;
}
F_144 ( & V_4 -> V_333 ) ;
}
if ( V_4 -> V_336 ) {
V_95 = F_142 ( V_4 -> V_336 ) ;
if ( V_95 )
goto V_337;
}
} else {
F_145 ( V_4 -> V_327 ) ;
F_145 ( V_4 -> V_328 ) ;
if ( V_4 -> V_330 )
F_145 ( V_4 -> V_330 ) ;
if ( V_4 -> V_332 ) {
F_143 ( & V_4 -> V_333 ) ;
F_145 ( V_4 -> V_332 ) ;
V_4 -> V_335 = false ;
F_144 ( & V_4 -> V_333 ) ;
}
if ( V_4 -> V_336 )
F_145 ( V_4 -> V_336 ) ;
}
return 0 ;
V_337:
if ( V_4 -> V_336 )
F_145 ( V_4 -> V_336 ) ;
V_334:
if ( V_4 -> V_330 )
F_145 ( V_4 -> V_330 ) ;
V_331:
F_145 ( V_4 -> V_328 ) ;
V_329:
F_145 ( V_4 -> V_327 ) ;
return V_95 ;
}
static int F_146 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
const struct V_53 * V_54 =
F_21 ( V_4 -> V_55 ) ;
struct V_305 * V_157 = NULL ;
char V_338 [ V_339 ] ;
char V_340 [ V_339 + 3 ] ;
int V_341 ;
int V_284 = V_4 -> V_284 ;
V_4 -> V_157 = NULL ;
if ( V_4 -> V_342 ) {
V_157 = F_147 ( V_35 , V_4 -> V_342 ,
& F_131 , 0 ,
V_4 -> V_154 ) ;
} else {
for ( V_341 = 0 ; ( V_341 < V_343 ) ; V_341 ++ ) {
if ( ( V_4 -> V_312 -> V_344 & ( 1 << V_341 ) ) )
continue;
if ( V_4 -> V_312 -> V_345 [ V_341 ] == NULL )
continue;
if ( V_4 -> V_312 -> V_345 [ V_341 ] -> V_341 == 0 )
continue;
if ( V_284 -- )
continue;
F_148 ( V_338 , V_4 -> V_312 -> V_346 , V_339 ) ;
break;
}
if ( V_341 >= V_343 ) {
F_12 ( V_35 , L_14 ) ;
F_148 ( V_338 , L_15 , V_339 ) ;
V_341 = 0 ;
}
snprintf ( V_340 , sizeof( V_340 ) ,
V_347 , V_338 , V_341 ) ;
V_157 = F_149 ( V_35 , V_340 , & F_131 ,
V_4 -> V_154 ) ;
}
if ( F_150 ( V_157 ) ) {
F_30 ( V_35 , L_16 ) ;
return F_151 ( V_157 ) ;
}
if ( V_54 -> V_77 & V_348 ) {
V_157 -> V_349 &= V_350 ;
V_157 -> V_349 &= ~ V_351 ;
#if ! F_66 ( V_149 )
V_157 -> V_349 |= V_352 ;
#endif
}
else
V_157 -> V_349 &= V_353 ;
V_157 -> V_354 = V_157 -> V_349 ;
V_4 -> V_157 = V_157 ;
V_4 -> V_191 = 0 ;
V_4 -> V_144 = 0 ;
F_12 ( V_35 , L_17 ,
V_4 -> V_157 -> V_355 -> V_356 , F_152 ( & V_4 -> V_157 -> V_89 ) ,
V_4 -> V_157 -> V_283 ) ;
return 0 ;
}
static int F_153 ( struct V_357 * V_55 )
{
static struct V_312 * V_358 ;
struct V_34 * V_35 = F_154 ( V_55 ) ;
struct V_3 * V_4 = F_11 ( V_35 ) ;
const struct V_53 * V_54 =
F_21 ( V_4 -> V_55 ) ;
struct V_298 * V_359 ;
int V_360 = - V_361 , V_28 ;
if ( ( V_54 -> V_77 & V_136 ) && V_4 -> V_284 > 0 ) {
if ( V_362 && V_358 ) {
V_4 -> V_312 = V_358 ;
V_362 ++ ;
return 0 ;
}
return - V_363 ;
}
V_4 -> V_307 = 0 ;
V_4 -> V_147 = F_6 ( F_155 ( V_4 -> V_328 ) , 5000000 ) ;
if ( V_54 -> V_77 & V_136 )
V_4 -> V_147 -- ;
V_4 -> V_147 <<= 1 ;
F_35 ( V_4 -> V_147 , V_4 -> V_99 + V_148 ) ;
V_4 -> V_312 = F_156 () ;
if ( V_4 -> V_312 == NULL ) {
V_360 = - V_229 ;
goto V_364;
}
V_4 -> V_312 -> V_356 = L_18 ;
V_4 -> V_312 -> V_365 = F_133 ;
V_4 -> V_312 -> V_366 = F_140 ;
snprintf ( V_4 -> V_312 -> V_346 , V_339 , L_19 ,
V_55 -> V_356 , V_4 -> V_284 + 1 ) ;
V_4 -> V_312 -> V_316 = V_4 ;
V_4 -> V_312 -> V_367 = & V_55 -> V_89 ;
V_4 -> V_312 -> V_283 = F_157 ( sizeof( int ) * V_343 , V_368 ) ;
if ( ! V_4 -> V_312 -> V_283 ) {
V_360 = - V_229 ;
goto V_369;
}
for ( V_28 = 0 ; V_28 < V_343 ; V_28 ++ )
V_4 -> V_312 -> V_283 [ V_28 ] = V_370 ;
V_359 = F_158 ( V_55 -> V_89 . V_300 , L_20 ) ;
if ( V_359 ) {
V_360 = F_159 ( V_4 -> V_312 , V_359 ) ;
F_160 ( V_359 ) ;
} else {
V_360 = F_161 ( V_4 -> V_312 ) ;
}
if ( V_360 )
goto V_371;
V_362 ++ ;
if ( V_54 -> V_77 & V_136 )
V_358 = V_4 -> V_312 ;
return 0 ;
V_371:
F_162 ( V_4 -> V_312 -> V_283 ) ;
V_369:
F_163 ( V_4 -> V_312 ) ;
V_364:
return V_360 ;
}
static void F_164 ( struct V_3 * V_4 )
{
if ( -- V_362 == 0 ) {
F_165 ( V_4 -> V_312 ) ;
F_162 ( V_4 -> V_312 -> V_283 ) ;
F_163 ( V_4 -> V_312 ) ;
}
}
static int F_166 ( struct V_34 * V_35 ,
struct V_372 * V_373 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
struct V_305 * V_374 = V_4 -> V_157 ;
if ( ! V_374 )
return - V_375 ;
return F_167 ( V_374 , V_373 ) ;
}
static int F_168 ( struct V_34 * V_35 ,
struct V_372 * V_373 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
struct V_305 * V_374 = V_4 -> V_157 ;
if ( ! V_374 )
return - V_375 ;
return F_169 ( V_374 , V_373 ) ;
}
static void F_170 ( struct V_34 * V_35 ,
struct V_376 * V_377 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
F_148 ( V_377 -> V_378 , V_4 -> V_55 -> V_89 . V_378 -> V_356 ,
sizeof( V_377 -> V_378 ) ) ;
F_148 ( V_377 -> V_45 , L_21 , sizeof( V_377 -> V_45 ) ) ;
F_148 ( V_377 -> V_379 , F_152 ( & V_35 -> V_89 ) , sizeof( V_377 -> V_379 ) ) ;
}
static int F_171 ( struct V_34 * V_35 ,
struct V_380 * V_377 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
if ( V_4 -> V_7 ) {
V_377 -> V_381 = V_382 |
V_383 |
V_384 |
V_385 |
V_386 |
V_387 ;
if ( V_4 -> V_290 )
V_377 -> V_388 = F_172 ( V_4 -> V_290 ) ;
else
V_377 -> V_388 = - 1 ;
V_377 -> V_389 = ( 1 << V_390 ) |
( 1 << V_391 ) ;
V_377 -> V_392 = ( 1 << V_393 ) |
( 1 << V_394 ) ;
return 0 ;
} else {
return F_173 ( V_35 , V_377 ) ;
}
}
static void F_174 ( struct V_34 * V_35 ,
struct V_395 * V_171 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
V_171 -> V_396 = ( V_4 -> V_168 & V_170 ) != 0 ;
V_171 -> V_397 = ( V_4 -> V_168 & V_169 ) != 0 ;
V_171 -> V_398 = V_171 -> V_397 ;
}
static int F_175 ( struct V_34 * V_35 ,
struct V_395 * V_171 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
if ( ! V_4 -> V_157 )
return - V_375 ;
if ( V_171 -> V_397 != V_171 -> V_398 ) {
F_12 ( V_35 ,
L_22 ) ;
return - V_399 ;
}
V_4 -> V_168 = 0 ;
V_4 -> V_168 |= V_171 -> V_398 ? V_169 : 0 ;
V_4 -> V_168 |= V_171 -> V_396 ? V_170 : 0 ;
if ( V_171 -> V_398 || V_171 -> V_396 ) {
V_4 -> V_157 -> V_349 |= V_400 ;
V_4 -> V_157 -> V_354 |= V_400 ;
} else {
V_4 -> V_157 -> V_349 &= ~ V_400 ;
V_4 -> V_157 -> V_354 &= ~ V_400 ;
}
if ( V_171 -> V_396 ) {
if ( F_77 ( V_35 ) )
F_71 ( V_35 ) ;
F_176 ( V_4 -> V_157 ) ;
}
if ( F_77 ( V_35 ) ) {
F_78 ( & V_4 -> V_199 ) ;
F_79 ( V_35 ) ;
F_64 ( V_35 ) ;
F_80 ( V_35 ) ;
F_81 ( V_35 ) ;
F_82 ( & V_4 -> V_199 ) ;
}
return 0 ;
}
static void F_177 ( struct V_34 * V_89 ,
struct V_401 * V_193 , T_5 * V_97 )
{
struct V_3 * V_4 = F_11 ( V_89 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < F_178 ( V_402 ) ; V_28 ++ )
V_97 [ V_28 ] = F_48 ( V_4 -> V_99 + V_402 [ V_28 ] . V_403 ) ;
}
static void F_179 ( struct V_34 * V_198 ,
T_4 V_404 , T_11 * V_97 )
{
int V_28 ;
switch ( V_404 ) {
case V_405 :
for ( V_28 = 0 ; V_28 < F_178 ( V_402 ) ; V_28 ++ )
memcpy ( V_97 + V_28 * V_406 ,
V_402 [ V_28 ] . V_356 , V_406 ) ;
break;
}
}
static int F_180 ( struct V_34 * V_89 , int V_407 )
{
switch ( V_407 ) {
case V_405 :
return F_178 ( V_402 ) ;
default:
return - V_408 ;
}
}
static int F_181 ( struct V_34 * V_89 )
{
struct V_3 * V_4 = F_11 ( V_89 ) ;
struct V_305 * V_374 = V_4 -> V_157 ;
if ( ! V_374 )
return - V_375 ;
return F_182 ( V_374 ) ;
}
static int F_183 ( struct V_34 * V_35 , int V_409 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
return V_409 * ( V_4 -> V_410 / 64000 ) / 1000 ;
}
static void F_184 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
const struct V_53 * V_54 =
F_21 ( V_4 -> V_55 ) ;
int V_411 , V_412 ;
if ( ! ( V_54 -> V_77 & V_78 ) )
return;
if ( ! V_4 -> V_413 || ! V_4 -> V_414 ||
! V_4 -> V_415 || ! V_4 -> V_416 )
return;
V_411 = V_417 ;
V_412 = V_417 ;
V_411 |= F_185 ( V_4 -> V_414 ) ;
V_411 |= F_186 ( F_183 ( V_35 , V_4 -> V_413 ) ) ;
V_412 |= F_185 ( V_4 -> V_416 ) ;
V_412 |= F_186 ( F_183 ( V_35 , V_4 -> V_415 ) ) ;
V_411 |= V_418 ;
V_412 |= V_418 ;
F_35 ( V_412 , V_4 -> V_99 + V_419 ) ;
F_35 ( V_411 , V_4 -> V_99 + V_420 ) ;
F_35 ( V_412 , V_4 -> V_99 + V_421 ) ;
F_35 ( V_411 , V_4 -> V_99 + V_422 ) ;
F_35 ( V_412 , V_4 -> V_99 + V_423 ) ;
F_35 ( V_411 , V_4 -> V_99 + V_424 ) ;
}
static int
F_187 ( struct V_34 * V_35 , struct V_425 * V_426 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
const struct V_53 * V_54 =
F_21 ( V_4 -> V_55 ) ;
if ( ! ( V_54 -> V_77 & V_78 ) )
return - V_408 ;
V_426 -> V_427 = V_4 -> V_413 ;
V_426 -> V_428 = V_4 -> V_414 ;
V_426 -> V_429 = V_4 -> V_415 ;
V_426 -> V_430 = V_4 -> V_416 ;
return 0 ;
}
static int
F_188 ( struct V_34 * V_35 , struct V_425 * V_426 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
const struct V_53 * V_54 =
F_21 ( V_4 -> V_55 ) ;
unsigned int V_431 ;
if ( ! ( V_54 -> V_77 & V_78 ) )
return - V_408 ;
if ( V_426 -> V_428 > 255 ) {
F_189 ( L_23 ) ;
return - V_399 ;
}
if ( V_426 -> V_430 > 255 ) {
F_189 ( L_24 ) ;
return - V_399 ;
}
V_431 = F_183 ( V_35 , V_4 -> V_413 ) ;
if ( V_431 > 0xFFFF ) {
F_189 ( L_25 ) ;
return - V_399 ;
}
V_431 = F_183 ( V_35 , V_4 -> V_415 ) ;
if ( V_431 > 0xFFFF ) {
F_189 ( L_25 ) ;
return - V_399 ;
}
V_4 -> V_413 = V_426 -> V_427 ;
V_4 -> V_414 = V_426 -> V_428 ;
V_4 -> V_415 = V_426 -> V_429 ;
V_4 -> V_416 = V_426 -> V_430 ;
F_184 ( V_35 ) ;
return 0 ;
}
static void F_70 ( struct V_34 * V_35 )
{
struct V_425 V_426 ;
V_426 . V_427 = V_432 ;
V_426 . V_428 = V_433 ;
V_426 . V_429 = V_432 ;
V_426 . V_430 = V_433 ;
F_188 ( V_35 , & V_426 ) ;
}
static int F_190 ( struct V_34 * V_198 ,
const struct V_434 * V_435 ,
void * V_97 )
{
struct V_3 * V_4 = F_11 ( V_198 ) ;
int V_95 = 0 ;
switch ( V_435 -> V_346 ) {
case V_436 :
* ( T_4 * ) V_97 = V_4 -> V_233 ;
break;
default:
V_95 = - V_399 ;
break;
}
return V_95 ;
}
static int F_191 ( struct V_34 * V_198 ,
const struct V_434 * V_435 ,
const void * V_97 )
{
struct V_3 * V_4 = F_11 ( V_198 ) ;
int V_95 = 0 ;
switch ( V_435 -> V_346 ) {
case V_436 :
V_4 -> V_233 = * ( T_4 * ) V_97 ;
break;
default:
V_95 = - V_399 ;
break;
}
return V_95 ;
}
static int F_192 ( struct V_34 * V_35 , struct V_437 * V_438 , int V_373 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
struct V_305 * V_374 = V_4 -> V_157 ;
if ( ! F_77 ( V_35 ) )
return - V_399 ;
if ( ! V_374 )
return - V_375 ;
if ( V_4 -> V_7 ) {
if ( V_373 == V_439 )
return F_193 ( V_35 , V_438 ) ;
if ( V_373 == V_440 )
return F_194 ( V_35 , V_438 ) ;
}
return F_195 ( V_374 , V_438 , V_373 ) ;
}
static void F_196 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
unsigned int V_28 ;
struct V_41 * V_42 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
unsigned int V_120 ;
for ( V_120 = 0 ; V_120 < V_4 -> V_121 ; V_120 ++ ) {
V_13 = V_4 -> V_14 [ V_120 ] ;
V_2 = V_13 -> V_20 ;
for ( V_28 = 0 ; V_28 < V_13 -> V_21 ; V_28 ++ ) {
V_42 = V_13 -> V_257 [ V_28 ] ;
V_13 -> V_257 [ V_28 ] = NULL ;
if ( V_42 ) {
F_31 ( & V_4 -> V_55 -> V_89 ,
V_2 -> V_38 ,
V_227 - V_4 -> V_226 ,
V_228 ) ;
F_197 ( V_42 ) ;
}
V_2 = F_1 ( V_2 , V_4 , V_120 ) ;
}
}
for ( V_120 = 0 ; V_120 < V_4 -> V_125 ; V_120 ++ ) {
V_10 = V_4 -> V_11 [ V_120 ] ;
V_2 = V_10 -> V_18 ;
for ( V_28 = 0 ; V_28 < V_10 -> V_19 ; V_28 ++ ) {
F_162 ( V_10 -> V_88 [ V_28 ] ) ;
V_10 -> V_88 [ V_28 ] = NULL ;
V_42 = V_10 -> V_40 [ V_28 ] ;
V_10 -> V_40 [ V_28 ] = NULL ;
F_197 ( V_42 ) ;
}
}
}
static void F_198 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
int V_28 ;
struct V_9 * V_10 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_125 ; V_28 ++ )
if ( V_4 -> V_11 [ V_28 ] && V_4 -> V_11 [ V_28 ] -> V_106 ) {
V_10 = V_4 -> V_11 [ V_28 ] ;
F_199 ( NULL ,
V_10 -> V_19 * V_107 ,
V_10 -> V_106 ,
V_10 -> V_108 ) ;
}
for ( V_28 = 0 ; V_28 < V_4 -> V_121 ; V_28 ++ )
if ( V_4 -> V_14 [ V_28 ] )
F_162 ( V_4 -> V_14 [ V_28 ] ) ;
for ( V_28 = 0 ; V_28 < V_4 -> V_125 ; V_28 ++ )
if ( V_4 -> V_11 [ V_28 ] )
F_162 ( V_4 -> V_11 [ V_28 ] ) ;
}
static int F_200 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
int V_28 ;
int V_95 = 0 ;
struct V_9 * V_10 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_125 ; V_28 ++ ) {
V_10 = F_201 ( sizeof( * V_10 ) , V_368 ) ;
if ( ! V_10 ) {
V_95 = - V_229 ;
goto V_441;
}
V_4 -> V_11 [ V_28 ] = V_10 ;
V_10 -> V_19 = V_442 ;
V_4 -> V_443 += V_4 -> V_11 [ V_28 ] -> V_19 ;
V_10 -> V_119 = V_444 ;
V_10 -> V_223 =
( V_10 -> V_19 - V_10 -> V_119 ) / 2 ;
V_10 -> V_106 = F_202 ( NULL ,
V_10 -> V_19 * V_107 ,
& V_10 -> V_108 ,
V_368 ) ;
if ( ! V_10 -> V_106 ) {
V_95 = - V_229 ;
goto V_441;
}
}
for ( V_28 = 0 ; V_28 < V_4 -> V_121 ; V_28 ++ ) {
V_4 -> V_14 [ V_28 ] = F_201 ( sizeof( * V_4 -> V_14 [ V_28 ] ) ,
V_368 ) ;
if ( ! V_4 -> V_14 [ V_28 ] ) {
V_95 = - V_229 ;
goto V_441;
}
V_4 -> V_14 [ V_28 ] -> V_21 = V_445 ;
V_4 -> V_446 += V_4 -> V_14 [ V_28 ] -> V_21 ;
}
return V_95 ;
V_441:
F_198 ( V_35 ) ;
return V_95 ;
}
static int
F_203 ( struct V_34 * V_35 , unsigned int V_58 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
unsigned int V_28 ;
struct V_41 * V_42 ;
struct V_1 * V_2 ;
struct V_12 * V_13 ;
V_13 = V_4 -> V_14 [ V_58 ] ;
V_2 = V_13 -> V_20 ;
for ( V_28 = 0 ; V_28 < V_13 -> V_21 ; V_28 ++ ) {
V_42 = F_101 ( V_35 , V_227 ) ;
if ( ! V_42 )
goto V_447;
if ( F_98 ( V_35 , V_2 , V_42 ) ) {
F_197 ( V_42 ) ;
goto V_447;
}
V_13 -> V_257 [ V_28 ] = V_42 ;
V_2 -> V_37 = V_122 ;
if ( V_4 -> V_7 ) {
struct V_7 * V_56 = (struct V_7 * ) V_2 ;
V_56 -> V_82 = V_273 ;
}
V_2 = F_1 ( V_2 , V_4 , V_58 ) ;
}
V_2 = F_2 ( V_2 , V_4 , V_58 ) ;
V_2 -> V_37 |= V_123 ;
return 0 ;
V_447:
F_196 ( V_35 ) ;
return - V_229 ;
}
static int
F_204 ( struct V_34 * V_35 , unsigned int V_58 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
unsigned int V_28 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
V_10 = V_4 -> V_11 [ V_58 ] ;
V_2 = V_10 -> V_18 ;
for ( V_28 = 0 ; V_28 < V_10 -> V_19 ; V_28 ++ ) {
V_10 -> V_88 [ V_28 ] = F_157 ( V_448 , V_368 ) ;
if ( ! V_10 -> V_88 [ V_28 ] )
goto V_447;
V_2 -> V_37 = 0 ;
V_2 -> V_38 = 0 ;
if ( V_4 -> V_7 ) {
struct V_7 * V_56 = (struct V_7 * ) V_2 ;
V_56 -> V_82 = V_72 ;
}
V_2 = F_1 ( V_2 , V_4 , V_58 ) ;
}
V_2 = F_2 ( V_2 , V_4 , V_58 ) ;
V_2 -> V_37 |= V_123 ;
return 0 ;
V_447:
F_196 ( V_35 ) ;
return - V_229 ;
}
static int F_205 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_121 ; V_28 ++ )
if ( F_203 ( V_35 , V_28 ) )
return - V_229 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_125 ; V_28 ++ )
if ( F_204 ( V_35 , V_28 ) )
return - V_229 ;
return 0 ;
}
static int
F_206 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
int V_95 ;
F_207 ( & V_4 -> V_55 -> V_89 ) ;
V_95 = F_141 ( V_35 , true ) ;
if ( V_95 )
return V_95 ;
V_95 = F_205 ( V_35 ) ;
if ( V_95 )
goto V_449;
V_95 = F_146 ( V_35 ) ;
if ( V_95 )
goto V_450;
F_64 ( V_35 ) ;
F_82 ( & V_4 -> V_199 ) ;
F_208 ( V_4 -> V_157 ) ;
F_209 ( V_35 ) ;
return 0 ;
V_450:
F_196 ( V_35 ) ;
V_449:
F_141 ( V_35 , false ) ;
F_210 ( & V_4 -> V_55 -> V_89 ) ;
return V_95 ;
}
static int
F_211 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
F_212 ( V_4 -> V_157 ) ;
if ( F_76 ( V_35 ) ) {
F_78 ( & V_4 -> V_199 ) ;
F_213 ( V_35 ) ;
F_71 ( V_35 ) ;
}
F_214 ( V_4 -> V_157 ) ;
V_4 -> V_157 = NULL ;
F_141 ( V_35 , false ) ;
F_210 ( & V_4 -> V_55 -> V_89 ) ;
F_196 ( V_35 ) ;
return 0 ;
}
static void F_68 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
struct V_451 * V_452 ;
unsigned int V_28 , V_453 , V_97 , V_454 , V_455 ;
unsigned char V_456 ;
if ( V_35 -> V_203 & V_457 ) {
V_455 = F_48 ( V_4 -> V_99 + V_183 ) ;
V_455 |= 0x8 ;
F_35 ( V_455 , V_4 -> V_99 + V_183 ) ;
return;
}
V_455 = F_48 ( V_4 -> V_99 + V_183 ) ;
V_455 &= ~ 0x8 ;
F_35 ( V_455 , V_4 -> V_99 + V_183 ) ;
if ( V_35 -> V_203 & V_458 ) {
F_35 ( 0xffffffff , V_4 -> V_99 + V_459 ) ;
F_35 ( 0xffffffff , V_4 -> V_99 + V_460 ) ;
return;
}
F_35 ( 0 , V_4 -> V_99 + V_459 ) ;
F_35 ( 0 , V_4 -> V_99 + V_460 ) ;
F_215 (ha, ndev) {
V_454 = 0xffffffff ;
for ( V_28 = 0 ; V_28 < V_35 -> V_461 ; V_28 ++ ) {
V_97 = V_452 -> V_64 [ V_28 ] ;
for ( V_453 = 0 ; V_453 < 8 ; V_453 ++ , V_97 >>= 1 ) {
V_454 = ( V_454 >> 1 ) ^
( ( ( V_454 ^ V_97 ) & 1 ) ? V_462 : 0 ) ;
}
}
V_456 = ( V_454 >> ( 32 - V_463 ) ) & 0x3f ;
if ( V_456 > 31 ) {
V_455 = F_48 ( V_4 -> V_99 + V_459 ) ;
V_455 |= 1 << ( V_456 - 32 ) ;
F_35 ( V_455 , V_4 -> V_99 + V_459 ) ;
} else {
V_455 = F_48 ( V_4 -> V_99 + V_460 ) ;
V_455 |= 1 << V_456 ;
F_35 ( V_455 , V_4 -> V_99 + V_460 ) ;
}
}
}
static int
F_216 ( struct V_34 * V_35 , void * V_84 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
struct V_464 * V_64 = V_84 ;
if ( V_64 ) {
if ( ! F_127 ( V_64 -> V_465 ) )
return - V_466 ;
memcpy ( V_35 -> V_137 , V_64 -> V_465 , V_35 -> V_461 ) ;
}
F_35 ( V_35 -> V_137 [ 3 ] | ( V_35 -> V_137 [ 2 ] << 8 ) |
( V_35 -> V_137 [ 1 ] << 16 ) | ( V_35 -> V_137 [ 0 ] << 24 ) ,
V_4 -> V_99 + V_139 ) ;
F_35 ( ( V_35 -> V_137 [ 5 ] << 16 ) | ( V_35 -> V_137 [ 4 ] << 24 ) ,
V_4 -> V_99 + V_140 ) ;
return 0 ;
}
static void F_217 ( struct V_34 * V_89 )
{
int V_28 ;
struct V_3 * V_4 = F_11 ( V_89 ) ;
for ( V_28 = 0 ; V_28 < V_467 ; V_28 ++ ) {
if ( V_4 -> V_283 [ V_28 ] > 0 ) {
F_218 ( V_4 -> V_283 [ V_28 ] ) ;
F_119 ( V_4 -> V_283 [ V_28 ] , V_89 ) ;
F_219 ( V_4 -> V_283 [ V_28 ] ) ;
}
}
}
static inline void F_220 ( struct V_34 * V_198 ,
T_12 V_260 )
{
struct V_3 * V_4 = F_11 ( V_198 ) ;
T_12 V_468 = V_260 ^ V_198 -> V_260 ;
V_198 -> V_260 = V_260 ;
if ( V_468 & V_469 ) {
if ( V_260 & V_469 )
V_4 -> V_151 |= V_152 ;
else
V_4 -> V_151 &= ~ V_152 ;
}
}
static int F_221 ( struct V_34 * V_198 ,
T_12 V_260 )
{
struct V_3 * V_4 = F_11 ( V_198 ) ;
T_12 V_468 = V_260 ^ V_198 -> V_260 ;
if ( F_77 ( V_198 ) && V_468 & V_470 ) {
F_78 ( & V_4 -> V_199 ) ;
F_79 ( V_198 ) ;
F_71 ( V_198 ) ;
F_220 ( V_198 , V_260 ) ;
F_64 ( V_198 ) ;
F_222 ( V_198 ) ;
F_81 ( V_198 ) ;
F_82 ( & V_4 -> V_199 ) ;
} else {
F_220 ( V_198 , V_260 ) ;
}
return 0 ;
}
static int F_223 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_11 ( V_35 ) ;
const struct V_53 * V_54 =
F_21 ( V_4 -> V_55 ) ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
struct V_1 * V_471 ;
T_2 V_126 ;
int V_472 ;
unsigned int V_28 ;
#if F_66 ( V_473 )
V_4 -> V_226 = 0xf ;
V_4 -> V_86 = 0xf ;
#else
V_4 -> V_226 = 0x3 ;
V_4 -> V_86 = 0x3 ;
#endif
F_200 ( V_35 ) ;
if ( V_4 -> V_7 )
V_4 -> V_22 = sizeof( struct V_7 ) ;
else
V_4 -> V_22 = sizeof( struct V_1 ) ;
V_472 = ( V_4 -> V_443 + V_4 -> V_446 ) *
V_4 -> V_22 ;
V_471 = F_202 ( NULL , V_472 , & V_126 ,
V_368 ) ;
if ( ! V_471 ) {
return - V_229 ;
}
memset ( V_471 , 0 , V_472 ) ;
F_125 ( V_35 ) ;
F_216 ( V_35 , NULL ) ;
for ( V_28 = 0 ; V_28 < V_4 -> V_121 ; V_28 ++ ) {
V_13 = V_4 -> V_14 [ V_28 ] ;
V_13 -> V_36 = V_28 ;
V_13 -> V_20 = (struct V_1 * ) V_471 ;
V_13 -> V_126 = V_126 ;
if ( V_4 -> V_7 ) {
V_126 += sizeof( struct V_7 ) * V_13 -> V_21 ;
V_471 = (struct V_1 * )
( ( (struct V_7 * ) V_471 ) + V_13 -> V_21 ) ;
} else {
V_126 += sizeof( struct V_1 ) * V_13 -> V_21 ;
V_471 += V_13 -> V_21 ;
}
}
for ( V_28 = 0 ; V_28 < V_4 -> V_125 ; V_28 ++ ) {
V_10 = V_4 -> V_11 [ V_28 ] ;
V_10 -> V_36 = V_28 ;
V_10 -> V_18 = (struct V_1 * ) V_471 ;
V_10 -> V_126 = V_126 ;
if ( V_4 -> V_7 ) {
V_126 += sizeof( struct V_7 ) * V_10 -> V_19 ;
V_471 = (struct V_1 * )
( ( (struct V_7 * ) V_471 ) + V_10 -> V_19 ) ;
} else {
V_126 += sizeof( struct V_1 ) * V_10 -> V_19 ;
V_471 += V_10 -> V_19 ;
}
}
V_35 -> V_474 = V_475 ;
V_35 -> V_476 = & V_477 ;
V_35 -> V_478 = & V_479 ;
F_35 ( V_480 , V_4 -> V_99 + V_189 ) ;
F_224 ( V_35 , & V_4 -> V_199 , F_123 , V_481 ) ;
if ( V_54 -> V_77 & V_482 )
V_35 -> V_260 |= V_261 ;
if ( V_54 -> V_77 & V_483 ) {
V_35 -> V_484 = V_485 ;
V_35 -> V_260 |= ( V_486 | V_487
| V_469 | V_488 | V_489 ) ;
V_4 -> V_151 |= V_152 ;
}
if ( V_54 -> V_77 & V_78 ) {
V_4 -> V_86 = 0 ;
V_4 -> V_226 = 0x3f ;
}
V_35 -> V_490 = V_35 -> V_260 ;
F_64 ( V_35 ) ;
return 0 ;
}
static void F_225 ( struct V_357 * V_55 )
{
int V_360 , V_491 ;
int V_492 = 1 ;
struct V_298 * V_299 = V_55 -> V_89 . V_300 ;
if ( ! V_299 )
return;
F_226 ( V_299 , L_26 , & V_492 ) ;
if ( V_492 > 1000 )
V_492 = 1 ;
V_491 = F_227 ( V_299 , L_27 , 0 ) ;
if ( ! F_228 ( V_491 ) )
return;
V_360 = F_229 ( & V_55 -> V_89 , V_491 ,
V_493 , L_28 ) ;
if ( V_360 ) {
F_230 ( & V_55 -> V_89 , L_29 , V_360 ) ;
return;
}
F_231 ( V_492 ) ;
F_232 ( V_491 , 1 ) ;
}
static void F_225 ( struct V_357 * V_55 )
{
}
static void
F_233 ( struct V_357 * V_55 , int * V_494 , int * V_495 )
{
struct V_298 * V_299 = V_55 -> V_89 . V_300 ;
int V_360 ;
* V_494 = * V_495 = 1 ;
if ( ! V_299 || ! F_234 ( V_299 ) )
return;
V_360 = F_226 ( V_299 , L_30 , V_494 ) ;
if ( V_360 )
* V_494 = 1 ;
V_360 = F_226 ( V_299 , L_31 , V_495 ) ;
if ( V_360 )
* V_495 = 1 ;
if ( * V_494 < 1 || * V_494 > V_496 ) {
F_235 ( & V_55 -> V_89 , L_32 ,
* V_494 ) ;
* V_494 = 1 ;
return;
}
if ( * V_495 < 1 || * V_495 > V_497 ) {
F_235 ( & V_55 -> V_89 , L_33 ,
* V_495 ) ;
* V_495 = 1 ;
return;
}
}
static int
F_236 ( struct V_357 * V_55 )
{
struct V_3 * V_4 ;
struct V_293 * V_294 ;
struct V_34 * V_35 ;
int V_28 , V_283 , V_95 = 0 ;
struct V_498 * V_499 ;
const struct V_500 * V_501 ;
static int V_284 ;
struct V_298 * V_299 = V_55 -> V_89 . V_300 , * V_342 ;
int V_502 ;
int V_503 ;
V_501 = F_237 ( V_504 , & V_55 -> V_89 ) ;
if ( V_501 )
V_55 -> V_54 = V_501 -> V_97 ;
F_233 ( V_55 , & V_502 , & V_503 ) ;
V_35 = F_238 ( sizeof( struct V_3 ) ,
V_502 , V_503 ) ;
if ( ! V_35 )
return - V_229 ;
F_239 ( V_35 , & V_55 -> V_89 ) ;
V_4 = F_11 ( V_35 ) ;
V_4 -> V_121 = V_503 ;
V_4 -> V_125 = V_502 ;
#if ! F_66 ( V_149 )
if ( V_55 -> V_54 &&
( V_55 -> V_54 -> V_77 & V_348 ) )
V_4 -> V_168 |= V_170 ;
#endif
F_207 ( & V_55 -> V_89 ) ;
V_499 = F_240 ( V_55 , V_505 , 0 ) ;
V_4 -> V_99 = F_241 ( & V_55 -> V_89 , V_499 ) ;
if ( F_150 ( V_4 -> V_99 ) ) {
V_95 = F_151 ( V_4 -> V_99 ) ;
goto V_506;
}
V_4 -> V_55 = V_55 ;
V_4 -> V_284 = V_284 ++ ;
V_4 -> V_7 = 0 ;
F_242 ( V_55 , V_35 ) ;
V_342 = F_243 ( V_299 , L_34 , 0 ) ;
if ( ! V_342 && F_244 ( V_299 ) ) {
V_95 = F_245 ( V_299 ) ;
if ( V_95 < 0 ) {
F_230 ( & V_55 -> V_89 ,
L_35 ) ;
goto V_507;
}
V_342 = F_246 ( V_299 ) ;
}
V_4 -> V_342 = V_342 ;
V_95 = F_247 ( V_55 -> V_89 . V_300 ) ;
if ( V_95 < 0 ) {
V_294 = F_126 ( & V_55 -> V_89 ) ;
if ( V_294 )
V_4 -> V_154 = V_294 -> V_508 ;
else
V_4 -> V_154 = V_509 ;
} else {
V_4 -> V_154 = V_95 ;
}
V_4 -> V_328 = F_248 ( & V_55 -> V_89 , L_36 ) ;
if ( F_150 ( V_4 -> V_328 ) ) {
V_95 = F_151 ( V_4 -> V_328 ) ;
goto V_510;
}
V_4 -> V_327 = F_248 ( & V_55 -> V_89 , L_37 ) ;
if ( F_150 ( V_4 -> V_327 ) ) {
V_95 = F_151 ( V_4 -> V_327 ) ;
goto V_510;
}
V_4 -> V_410 = F_155 ( V_4 -> V_327 ) ;
V_4 -> V_330 = F_248 ( & V_55 -> V_89 , L_38 ) ;
if ( F_150 ( V_4 -> V_330 ) )
V_4 -> V_330 = NULL ;
V_4 -> V_335 = false ;
F_249 ( & V_4 -> V_333 ) ;
V_4 -> V_336 = F_248 ( & V_55 -> V_89 , L_39 ) ;
if ( F_150 ( V_4 -> V_336 ) )
V_4 -> V_336 = NULL ;
V_4 -> V_332 = F_248 ( & V_55 -> V_89 , L_40 ) ;
V_4 -> V_7 =
V_55 -> V_54 -> V_77 & V_511 ;
if ( F_150 ( V_4 -> V_332 ) ) {
V_4 -> V_332 = NULL ;
V_4 -> V_7 = 0 ;
}
V_95 = F_141 ( V_35 , true ) ;
if ( V_95 )
goto V_510;
V_4 -> V_512 = F_250 ( & V_55 -> V_89 , L_41 ) ;
if ( ! F_150 ( V_4 -> V_512 ) ) {
V_95 = F_251 ( V_4 -> V_512 ) ;
if ( V_95 ) {
F_230 ( & V_55 -> V_89 ,
L_42 , V_95 ) ;
goto V_513;
}
} else {
V_4 -> V_512 = NULL ;
}
F_225 ( V_55 ) ;
if ( V_4 -> V_7 )
F_252 ( V_55 ) ;
V_95 = F_223 ( V_35 ) ;
if ( V_95 )
goto V_514;
for ( V_28 = 0 ; V_28 < V_467 ; V_28 ++ ) {
V_283 = F_253 ( V_55 , V_28 ) ;
if ( V_283 < 0 ) {
if ( V_28 )
break;
V_95 = V_283 ;
goto V_515;
}
V_95 = F_254 ( & V_55 -> V_89 , V_283 , F_119 ,
0 , V_55 -> V_356 , V_35 ) ;
if ( V_95 )
goto V_515;
}
F_134 ( & V_4 -> V_289 ) ;
V_95 = F_153 ( V_55 ) ;
if ( V_95 )
goto V_516;
F_255 ( V_35 ) ;
F_141 ( V_35 , false ) ;
F_210 ( & V_55 -> V_89 ) ;
V_95 = F_256 ( V_35 ) ;
if ( V_95 )
goto V_517;
if ( V_4 -> V_7 && V_4 -> V_290 )
F_12 ( V_35 , L_43 , V_4 -> V_284 ) ;
V_4 -> V_233 = V_518 ;
F_257 ( & V_4 -> V_195 , F_74 ) ;
return 0 ;
V_517:
F_164 ( V_4 ) ;
V_516:
V_515:
V_514:
if ( V_4 -> V_512 )
F_258 ( V_4 -> V_512 ) ;
V_513:
F_141 ( V_35 , false ) ;
V_510:
V_507:
F_160 ( V_342 ) ;
V_506:
F_259 ( V_35 ) ;
return V_95 ;
}
static int
F_260 ( struct V_357 * V_55 )
{
struct V_34 * V_35 = F_154 ( V_55 ) ;
struct V_3 * V_4 = F_11 ( V_35 ) ;
F_261 ( & V_4 -> V_519 ) ;
F_262 ( & V_4 -> V_195 ) ;
F_263 ( V_35 ) ;
F_164 ( V_4 ) ;
if ( V_4 -> V_512 )
F_258 ( V_4 -> V_512 ) ;
if ( V_4 -> V_290 )
F_264 ( V_4 -> V_290 ) ;
F_141 ( V_35 , false ) ;
F_160 ( V_4 -> V_342 ) ;
F_259 ( V_35 ) ;
return 0 ;
}
static int T_13 F_265 ( struct V_520 * V_89 )
{
struct V_34 * V_35 = F_266 ( V_89 ) ;
struct V_3 * V_4 = F_11 ( V_35 ) ;
F_75 () ;
if ( F_77 ( V_35 ) ) {
F_212 ( V_4 -> V_157 ) ;
F_78 ( & V_4 -> V_199 ) ;
F_79 ( V_35 ) ;
F_267 ( V_35 ) ;
F_81 ( V_35 ) ;
F_71 ( V_35 ) ;
F_141 ( V_35 , false ) ;
F_210 ( & V_4 -> V_55 -> V_89 ) ;
}
F_83 () ;
if ( V_4 -> V_512 )
F_258 ( V_4 -> V_512 ) ;
return 0 ;
}
static int T_13 F_268 ( struct V_520 * V_89 )
{
struct V_34 * V_35 = F_266 ( V_89 ) ;
struct V_3 * V_4 = F_11 ( V_35 ) ;
int V_95 ;
if ( V_4 -> V_512 ) {
V_95 = F_251 ( V_4 -> V_512 ) ;
if ( V_95 )
return V_95 ;
}
F_75 () ;
if ( F_77 ( V_35 ) ) {
F_207 ( & V_4 -> V_55 -> V_89 ) ;
V_95 = F_141 ( V_35 , true ) ;
if ( V_95 ) {
F_83 () ;
goto V_510;
}
F_64 ( V_35 ) ;
F_79 ( V_35 ) ;
F_269 ( V_35 ) ;
F_81 ( V_35 ) ;
F_82 ( & V_4 -> V_199 ) ;
F_208 ( V_4 -> V_157 ) ;
}
F_83 () ;
return 0 ;
V_510:
if ( V_4 -> V_512 )
F_258 ( V_4 -> V_512 ) ;
return V_95 ;
}
