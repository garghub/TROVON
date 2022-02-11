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
F_13 ( V_2 -> V_37 ) ,
F_14 ( V_2 -> V_38 ) ,
F_13 ( V_2 -> V_39 ) ,
V_10 -> V_40 [ V_36 ] ) ;
V_2 = F_1 ( V_2 , V_4 , 0 ) ;
V_36 ++ ;
} while ( V_2 != V_10 -> V_18 );
}
static inline bool F_15 ( struct V_41 * V_42 )
{
return V_42 -> V_43 == F_16 ( V_44 ) && F_17 ( V_42 ) -> V_45 == 4 ;
}
static int
F_18 ( struct V_41 * V_42 , struct V_34 * V_35 )
{
if ( V_42 -> V_46 != V_47 )
return 0 ;
if ( F_19 ( F_20 ( V_42 , 0 ) ) )
return - 1 ;
if ( F_15 ( V_42 ) )
F_17 ( V_42 ) -> V_48 = 0 ;
* ( V_49 * ) ( V_42 -> V_50 + V_42 -> V_51 + V_42 -> V_52 ) = 0 ;
return 0 ;
}
static struct V_1 *
F_21 ( struct V_9 * V_10 ,
struct V_41 * V_42 ,
struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_1 * V_2 = V_10 -> V_25 ;
struct V_7 * V_53 ;
int V_54 = F_22 ( V_42 ) -> V_54 ;
unsigned short V_55 = F_23 ( V_42 ) ;
int V_56 , V_57 ;
unsigned short V_58 ;
unsigned int V_59 = 0 ;
T_1 * V_60 ;
unsigned int V_36 ;
void * V_26 ;
T_2 V_61 ;
int V_28 ;
for ( V_56 = 0 ; V_56 < V_54 ; V_56 ++ ) {
V_60 = & F_22 ( V_42 ) -> V_62 [ V_56 ] ;
V_2 = F_1 ( V_2 , V_4 , V_55 ) ;
V_53 = (struct V_7 * ) V_2 ;
V_58 = F_13 ( V_2 -> V_37 ) ;
V_58 &= ~ V_63 ;
V_58 |= ( V_64 | V_65 ) ;
V_57 = F_22 ( V_42 ) -> V_62 [ V_56 ] . V_66 ;
if ( V_56 == V_54 - 1 ) {
V_58 |= ( V_67 | V_68 ) ;
if ( V_4 -> V_7 ) {
V_59 |= V_69 ;
if ( F_19 ( F_22 ( V_42 ) -> V_70 &
V_71 && V_4 -> V_72 ) )
V_59 |= V_73 ;
}
}
if ( V_4 -> V_7 ) {
if ( V_4 -> V_74 & V_75 )
V_59 |= F_24 ( V_55 ) ;
if ( V_42 -> V_46 == V_47 )
V_59 |= V_76 | V_77 ;
V_53 -> V_78 = 0 ;
V_53 -> V_79 = F_25 ( V_59 ) ;
}
V_26 = F_26 ( V_60 -> V_80 . V_81 ) + V_60 -> V_82 ;
V_36 = F_3 ( V_10 -> V_18 , V_2 , V_4 ) ;
if ( ( ( unsigned long ) V_26 ) & V_4 -> V_83 ||
V_4 -> V_74 & V_84 ) {
memcpy ( V_10 -> V_85 [ V_36 ] , V_26 , V_57 ) ;
V_26 = V_10 -> V_85 [ V_36 ] ;
if ( V_4 -> V_74 & V_84 )
F_5 ( V_26 , V_57 ) ;
}
V_61 = F_27 ( & V_4 -> V_86 -> V_87 , V_26 , V_57 ,
V_88 ) ;
if ( F_28 ( & V_4 -> V_86 -> V_87 , V_61 ) ) {
F_29 ( V_42 ) ;
if ( F_30 () )
F_31 ( V_35 , L_4 ) ;
goto F_28;
}
V_2 -> V_38 = F_25 ( V_61 ) ;
V_2 -> V_39 = F_32 ( V_57 ) ;
V_2 -> V_37 = F_32 ( V_58 ) ;
}
return V_2 ;
F_28:
V_2 = V_10 -> V_25 ;
for ( V_28 = 0 ; V_28 < V_56 ; V_28 ++ ) {
V_2 = F_1 ( V_2 , V_4 , V_55 ) ;
F_33 ( & V_4 -> V_86 -> V_87 , F_14 ( V_2 -> V_38 ) ,
F_13 ( V_2 -> V_39 ) , V_88 ) ;
}
return F_34 ( - V_89 ) ;
}
static int F_35 ( struct V_9 * V_10 ,
struct V_41 * V_42 , struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_54 = F_22 ( V_42 ) -> V_54 ;
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
F_29 ( V_42 ) ;
if ( F_30 () )
F_31 ( V_35 , L_5 ) ;
return V_94 ;
}
if ( F_18 ( V_42 , V_35 ) ) {
F_29 ( V_42 ) ;
return V_94 ;
}
V_2 = V_10 -> V_25 ;
V_90 = V_2 ;
V_58 = F_13 ( V_2 -> V_37 ) ;
V_58 &= ~ V_63 ;
V_26 = V_42 -> V_95 ;
V_91 = F_36 ( V_42 ) ;
V_55 = F_23 ( V_42 ) ;
V_36 = F_3 ( V_10 -> V_18 , V_2 , V_4 ) ;
if ( ( ( unsigned long ) V_26 ) & V_4 -> V_83 ||
V_4 -> V_74 & V_84 ) {
memcpy ( V_10 -> V_85 [ V_36 ] , V_42 -> V_95 , V_91 ) ;
V_26 = V_10 -> V_85 [ V_36 ] ;
if ( V_4 -> V_74 & V_84 )
F_5 ( V_26 , V_91 ) ;
}
V_61 = F_27 ( & V_4 -> V_86 -> V_87 , V_26 , V_91 , V_88 ) ;
if ( F_28 ( & V_4 -> V_86 -> V_87 , V_61 ) ) {
F_29 ( V_42 ) ;
if ( F_30 () )
F_31 ( V_35 , L_4 ) ;
return V_94 ;
}
if ( V_54 ) {
V_90 = F_21 ( V_10 , V_42 , V_35 ) ;
if ( F_37 ( V_90 ) )
return V_94 ;
} else {
V_58 |= ( V_67 | V_68 ) ;
if ( V_4 -> V_7 ) {
V_59 = V_69 ;
if ( F_19 ( F_22 ( V_42 ) -> V_70 &
V_71 && V_4 -> V_72 ) )
V_59 |= V_73 ;
}
}
if ( V_4 -> V_7 ) {
struct V_7 * V_53 = (struct V_7 * ) V_2 ;
if ( F_19 ( F_22 ( V_42 ) -> V_70 & V_71 &&
V_4 -> V_72 ) )
F_22 ( V_42 ) -> V_70 |= V_96 ;
if ( V_4 -> V_74 & V_75 )
V_59 |= F_24 ( V_55 ) ;
if ( V_42 -> V_46 == V_47 )
V_59 |= V_76 | V_77 ;
V_53 -> V_78 = 0 ;
V_53 -> V_79 = F_25 ( V_59 ) ;
}
V_36 = F_3 ( V_10 -> V_18 , V_90 , V_4 ) ;
V_10 -> V_40 [ V_36 ] = V_42 ;
V_2 -> V_39 = F_32 ( V_91 ) ;
V_2 -> V_38 = F_25 ( V_61 ) ;
V_58 |= ( V_65 | V_64 ) ;
V_2 -> V_37 = F_32 ( V_58 ) ;
V_2 = F_1 ( V_90 , V_4 , V_55 ) ;
F_38 ( V_42 ) ;
F_39 () ;
V_10 -> V_25 = V_2 ;
F_40 ( 0 , V_4 -> V_97 + F_41 ( V_55 ) ) ;
return 0 ;
}
static int
F_42 ( struct V_9 * V_10 , struct V_41 * V_42 ,
struct V_34 * V_35 ,
struct V_1 * V_2 , int V_36 , char * V_95 ,
int V_66 , bool V_98 , bool V_99 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_7 * V_53 = F_43 ( V_2 , struct V_7 , V_100 ) ;
unsigned short V_55 = F_23 ( V_42 ) ;
unsigned short V_58 ;
unsigned int V_59 = 0 ;
T_2 V_61 ;
V_58 = F_13 ( V_2 -> V_37 ) ;
V_58 &= ~ V_63 ;
V_58 |= ( V_64 | V_65 ) ;
if ( ( ( unsigned long ) V_95 ) & V_4 -> V_83 ||
V_4 -> V_74 & V_84 ) {
memcpy ( V_10 -> V_85 [ V_36 ] , V_95 , V_66 ) ;
V_95 = V_10 -> V_85 [ V_36 ] ;
if ( V_4 -> V_74 & V_84 )
F_5 ( V_95 , V_66 ) ;
}
V_61 = F_27 ( & V_4 -> V_86 -> V_87 , V_95 , V_66 , V_88 ) ;
if ( F_28 ( & V_4 -> V_86 -> V_87 , V_61 ) ) {
F_29 ( V_42 ) ;
if ( F_30 () )
F_31 ( V_35 , L_4 ) ;
return V_101 ;
}
V_2 -> V_39 = F_32 ( V_66 ) ;
V_2 -> V_38 = F_25 ( V_61 ) ;
if ( V_4 -> V_7 ) {
if ( V_4 -> V_74 & V_75 )
V_59 |= F_24 ( V_55 ) ;
if ( V_42 -> V_46 == V_47 )
V_59 |= V_76 | V_77 ;
V_53 -> V_78 = 0 ;
V_53 -> V_79 = F_25 ( V_59 ) ;
}
if ( V_98 )
V_58 |= ( V_68 | V_64 ) ;
if ( V_99 ) {
V_58 |= V_67 ;
if ( V_4 -> V_7 )
V_53 -> V_79 |= F_25 ( V_69 ) ;
}
V_2 -> V_37 = F_32 ( V_58 ) ;
return 0 ;
}
static int
F_44 ( struct V_9 * V_10 ,
struct V_41 * V_42 , struct V_34 * V_35 ,
struct V_1 * V_2 , int V_36 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_102 = F_45 ( V_42 ) + F_46 ( V_42 ) ;
struct V_7 * V_53 = F_43 ( V_2 , struct V_7 , V_100 ) ;
unsigned short V_55 = F_23 ( V_42 ) ;
void * V_26 ;
unsigned long V_103 ;
unsigned short V_58 ;
unsigned int V_59 = 0 ;
V_58 = F_13 ( V_2 -> V_37 ) ;
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
V_103 = F_27 ( & V_4 -> V_86 -> V_87 , V_26 ,
V_102 , V_88 ) ;
if ( F_28 ( & V_4 -> V_86 -> V_87 , V_103 ) ) {
F_29 ( V_42 ) ;
if ( F_30 () )
F_31 ( V_35 , L_4 ) ;
return V_101 ;
}
}
V_2 -> V_38 = F_25 ( V_103 ) ;
V_2 -> V_39 = F_32 ( V_102 ) ;
if ( V_4 -> V_7 ) {
if ( V_4 -> V_74 & V_75 )
V_59 |= F_24 ( V_55 ) ;
if ( V_42 -> V_46 == V_47 )
V_59 |= V_76 | V_77 ;
V_53 -> V_78 = 0 ;
V_53 -> V_79 = F_25 ( V_59 ) ;
}
V_2 -> V_37 = F_32 ( V_58 ) ;
return 0 ;
}
static int F_47 ( struct V_9 * V_10 ,
struct V_41 * V_42 ,
struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_102 = F_45 ( V_42 ) + F_46 ( V_42 ) ;
int V_107 , V_108 ;
struct V_1 * V_2 = V_10 -> V_25 ;
unsigned short V_55 = F_23 ( V_42 ) ;
struct V_109 V_110 ;
unsigned int V_36 = 0 ;
int V_111 ;
if ( F_48 ( V_42 ) >= F_4 ( V_4 , V_10 ) ) {
F_29 ( V_42 ) ;
if ( F_30 () )
F_31 ( V_35 , L_6 ) ;
return V_94 ;
}
if ( F_18 ( V_42 , V_35 ) ) {
F_29 ( V_42 ) ;
return V_94 ;
}
F_49 ( V_42 , & V_110 ) ;
V_107 = V_42 -> V_27 - V_102 ;
while ( V_107 > 0 ) {
char * V_112 ;
V_36 = F_3 ( V_10 -> V_18 , V_2 , V_4 ) ;
V_108 = F_50 ( int , F_22 ( V_42 ) -> V_113 , V_107 ) ;
V_107 -= V_108 ;
V_112 = V_10 -> V_104 + V_36 * V_105 ;
F_51 ( V_42 , V_112 , & V_110 , V_108 , V_107 == 0 ) ;
V_111 = F_44 ( V_10 , V_42 , V_35 , V_2 , V_36 ) ;
if ( V_111 )
goto V_114;
while ( V_108 > 0 ) {
int V_66 ;
V_66 = F_50 ( int , V_110 . V_66 , V_108 ) ;
V_2 = F_1 ( V_2 , V_4 , V_55 ) ;
V_36 = F_3 ( V_10 -> V_18 ,
V_2 , V_4 ) ;
V_111 = F_42 ( V_10 , V_42 , V_35 ,
V_2 , V_36 ,
V_110 . V_95 , V_66 ,
V_66 == V_108 ,
V_107 == 0 ) ;
if ( V_111 )
goto V_114;
V_108 -= V_66 ;
F_52 ( V_42 , & V_110 , V_66 ) ;
}
V_2 = F_1 ( V_2 , V_4 , V_55 ) ;
}
V_10 -> V_40 [ V_36 ] = V_42 ;
F_38 ( V_42 ) ;
V_10 -> V_25 = V_2 ;
if ( ! ( V_4 -> V_74 & V_115 ) ||
! F_53 ( V_4 -> V_97 + F_41 ( V_55 ) ) ||
! F_53 ( V_4 -> V_97 + F_41 ( V_55 ) ) ||
! F_53 ( V_4 -> V_97 + F_41 ( V_55 ) ) ||
! F_53 ( V_4 -> V_97 + F_41 ( V_55 ) ) )
F_40 ( 0 , V_4 -> V_97 + F_41 ( V_55 ) ) ;
return 0 ;
V_114:
return V_111 ;
}
static T_3
F_54 ( struct V_41 * V_42 , struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_92 ;
unsigned short V_55 ;
struct V_9 * V_10 ;
struct V_116 * V_117 ;
int V_111 ;
V_55 = F_23 ( V_42 ) ;
V_10 = V_4 -> V_11 [ V_55 ] ;
V_117 = F_55 ( V_35 , V_55 ) ;
if ( F_56 ( V_42 ) )
V_111 = F_47 ( V_10 , V_42 , V_35 ) ;
else
V_111 = F_35 ( V_10 , V_42 , V_35 ) ;
if ( V_111 )
return V_111 ;
V_92 = F_4 ( V_4 , V_10 ) ;
if ( V_92 <= V_10 -> V_118 )
F_57 ( V_117 ) ;
return V_94 ;
}
static void F_58 ( struct V_34 * V_87 )
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
V_2 -> V_37 = F_32 ( V_121 ) ;
else
V_2 -> V_37 = F_32 ( 0 ) ;
V_2 = F_1 ( V_2 , V_4 , V_119 ) ;
}
V_2 = F_2 ( V_2 , V_4 , V_119 ) ;
V_2 -> V_37 |= F_32 ( V_122 ) ;
V_13 -> V_123 = V_13 -> V_20 ;
}
for ( V_119 = 0 ; V_119 < V_4 -> V_124 ; V_119 ++ ) {
V_10 = V_4 -> V_11 [ V_119 ] ;
V_2 = V_10 -> V_18 ;
V_10 -> V_25 = V_2 ;
for ( V_28 = 0 ; V_28 < V_10 -> V_19 ; V_28 ++ ) {
V_2 -> V_37 = F_32 ( 0 ) ;
if ( V_10 -> V_40 [ V_28 ] ) {
F_29 ( V_10 -> V_40 [ V_28 ] ) ;
V_10 -> V_40 [ V_28 ] = NULL ;
}
V_2 -> V_38 = F_25 ( 0 ) ;
V_2 = F_1 ( V_2 , V_4 , V_119 ) ;
}
V_2 = F_2 ( V_2 , V_4 , V_119 ) ;
V_2 -> V_37 |= F_32 ( V_122 ) ;
V_10 -> V_24 = V_2 ;
}
}
static void F_59 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_120 ; V_28 ++ )
F_40 ( 0 , V_4 -> V_97 + F_60 ( V_28 ) ) ;
}
static void F_61 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_120 ; V_28 ++ ) {
V_13 = V_4 -> V_14 [ V_28 ] ;
F_40 ( V_13 -> V_125 , V_4 -> V_97 + F_62 ( V_28 ) ) ;
F_40 ( V_126 , V_4 -> V_97 + F_63 ( V_28 ) ) ;
if ( V_28 )
F_40 ( V_127 | F_64 ( V_28 ) ,
V_4 -> V_97 + F_65 ( V_28 ) ) ;
}
for ( V_28 = 0 ; V_28 < V_4 -> V_124 ; V_28 ++ ) {
V_10 = V_4 -> V_11 [ V_28 ] ;
F_40 ( V_10 -> V_125 , V_4 -> V_97 + F_66 ( V_28 ) ) ;
if ( V_28 )
F_40 ( V_128 | F_67 ( V_28 ) ,
V_4 -> V_97 + F_68 ( V_28 ) ) ;
}
}
static void F_69 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_9 * V_10 ;
int V_28 , V_129 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_124 ; V_28 ++ ) {
V_10 = V_4 -> V_11 [ V_28 ] ;
for ( V_129 = 0 ; V_129 < V_10 -> V_19 ; V_129 ++ ) {
if ( V_10 -> V_40 [ V_129 ] ) {
F_29 ( V_10 -> V_40 [ V_129 ] ) ;
V_10 -> V_40 [ V_129 ] = NULL ;
}
}
}
}
static void
F_70 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
T_4 V_130 ;
T_4 V_131 [ 2 ] ;
T_4 V_132 = V_133 | 0x04 ;
T_4 V_134 = 0x2 ;
if ( V_4 -> V_74 & V_75 ) {
F_40 ( 0 , V_4 -> V_97 + V_135 ) ;
} else {
F_40 ( 1 , V_4 -> V_97 + V_135 ) ;
F_71 ( 10 ) ;
}
if ( V_4 -> V_74 & V_136 ) {
memcpy ( & V_131 , V_35 -> V_137 , V_138 ) ;
F_40 ( ( V_139 T_4 ) F_72 ( V_131 [ 0 ] ) ,
V_4 -> V_97 + V_140 ) ;
F_40 ( ( V_139 T_4 ) F_72 ( V_131 [ 1 ] ) ,
V_4 -> V_97 + V_141 ) ;
}
F_40 ( 0xffffffff , V_4 -> V_97 + V_142 ) ;
F_58 ( V_35 ) ;
F_61 ( V_35 ) ;
F_69 ( V_35 ) ;
if ( V_4 -> V_143 == V_144 ) {
F_40 ( 0x04 , V_4 -> V_97 + V_145 ) ;
} else {
V_132 |= 0x02 ;
F_40 ( 0x0 , V_4 -> V_97 + V_145 ) ;
}
F_40 ( V_4 -> V_146 , V_4 -> V_97 + V_147 ) ;
#if ! F_73 ( V_148 )
if ( V_4 -> V_74 & V_149 ) {
V_130 = F_53 ( V_4 -> V_97 + V_150 ) ;
if ( V_4 -> V_151 & V_152 )
V_130 |= V_153 ;
else
V_130 &= ~ V_153 ;
F_40 ( V_130 , V_4 -> V_97 + V_150 ) ;
}
#endif
if ( V_4 -> V_74 & V_136 ) {
V_132 |= 0x40000000 | 0x00000020 ;
if ( V_4 -> V_154 == V_155 ||
V_4 -> V_154 == V_156 ||
V_4 -> V_154 == V_157 ||
V_4 -> V_154 == V_158 )
V_132 |= ( 1 << 6 ) ;
else if ( V_4 -> V_154 == V_159 )
V_132 |= ( 1 << 8 ) ;
else
V_132 &= ~ ( 1 << 8 ) ;
if ( V_4 -> V_160 ) {
if ( V_4 -> V_160 -> V_161 == V_162 )
V_134 |= ( 1 << 5 ) ;
else if ( V_4 -> V_160 -> V_161 == V_163 )
V_132 &= ~ ( 1 << 9 ) ;
else
V_132 |= ( 1 << 9 ) ;
}
} else {
#ifdef F_74
if ( V_4 -> V_74 & V_164 ) {
T_4 V_165 ;
F_40 ( 0 , V_4 -> V_97 + F_74 ) ;
while ( F_53 ( V_4 -> V_97 + F_74 ) & 4 )
F_71 ( 1 ) ;
V_165 = ( V_4 -> V_154 == V_159 )
? V_166 : V_167 ;
if ( V_4 -> V_160 && V_4 -> V_160 -> V_161 == V_168 )
V_165 |= V_169 ;
F_40 ( V_165 , V_4 -> V_97 + V_170 ) ;
F_40 ( 2 , V_4 -> V_97 + F_74 ) ;
}
#endif
}
#if ! F_73 ( V_148 )
if ( ( V_4 -> V_171 & V_172 ) ||
( ( V_4 -> V_171 & V_173 ) &&
V_4 -> V_160 && V_4 -> V_160 -> V_174 ) ) {
V_132 |= V_175 ;
F_40 ( V_176 , V_4 -> V_97 + V_177 ) ;
F_40 ( V_178 , V_4 -> V_97 + V_179 ) ;
F_40 ( V_180 , V_4 -> V_97 + V_181 ) ;
F_40 ( V_182 , V_4 -> V_97 + V_183 ) ;
F_40 ( V_184 , V_4 -> V_97 + V_185 ) ;
} else {
V_132 &= ~ V_175 ;
}
#endif
F_40 ( V_132 , V_4 -> V_97 + V_186 ) ;
F_75 ( V_35 ) ;
#ifndef V_148
F_40 ( 0 , V_4 -> V_97 + V_187 ) ;
F_40 ( 0 , V_4 -> V_97 + V_188 ) ;
#endif
if ( V_4 -> V_74 & V_136 ) {
V_134 |= ( 1 << 8 ) ;
F_40 ( 1 << 8 , V_4 -> V_97 + V_189 ) ;
}
if ( V_4 -> V_7 )
V_134 |= ( 1 << 4 ) ;
#ifndef V_148
F_40 ( 0 << 31 , V_4 -> V_97 + V_190 ) ;
#endif
F_40 ( V_134 , V_4 -> V_97 + V_135 ) ;
F_59 ( V_35 ) ;
if ( V_4 -> V_7 )
F_76 ( V_35 ) ;
if ( V_4 -> V_191 )
F_40 ( V_192 , V_4 -> V_97 + V_193 ) ;
else
F_40 ( V_194 , V_4 -> V_97 + V_193 ) ;
F_77 ( V_35 ) ;
}
static void
F_78 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_195 * V_196 = V_4 -> V_86 -> V_87 . V_197 ;
T_4 V_198 = F_53 ( V_4 -> V_97 + V_186 ) & ( 1 << 8 ) ;
T_4 V_130 ;
if ( V_4 -> V_191 ) {
F_40 ( 1 , V_4 -> V_97 + V_145 ) ;
F_71 ( 10 ) ;
if ( ! ( F_53 ( V_4 -> V_97 + V_142 ) & V_199 ) )
F_31 ( V_35 , L_7 ) ;
}
if ( ! ( V_4 -> V_200 & V_201 ) ) {
if ( V_4 -> V_74 & V_75 ) {
F_40 ( 0 , V_4 -> V_97 + V_135 ) ;
} else {
F_40 ( 1 , V_4 -> V_97 + V_135 ) ;
F_71 ( 10 ) ;
}
F_40 ( V_192 , V_4 -> V_97 + V_193 ) ;
} else {
F_40 ( V_192 | V_202 , V_4 -> V_97 + V_193 ) ;
V_130 = F_53 ( V_4 -> V_97 + V_135 ) ;
V_130 |= ( V_203 | V_204 ) ;
F_40 ( V_130 , V_4 -> V_97 + V_135 ) ;
if ( V_196 && V_196 -> V_205 )
V_196 -> V_205 ( true ) ;
}
F_40 ( V_4 -> V_146 , V_4 -> V_97 + V_147 ) ;
if ( V_4 -> V_74 & V_136 &&
! ( V_4 -> V_200 & V_201 ) ) {
F_40 ( 2 , V_4 -> V_97 + V_135 ) ;
F_40 ( V_198 , V_4 -> V_97 + V_186 ) ;
}
}
static void
F_79 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_9 ( V_35 ) ;
V_35 -> V_206 . V_207 ++ ;
F_80 ( & V_4 -> V_208 ) ;
}
static void F_81 ( struct V_209 * V_210 )
{
struct V_3 * V_4 =
F_43 ( V_210 , struct V_3 , V_208 ) ;
struct V_34 * V_35 = V_4 -> V_211 ;
F_82 () ;
if ( F_83 ( V_35 ) || F_84 ( V_35 ) ) {
F_85 ( & V_4 -> V_212 ) ;
F_86 ( V_35 ) ;
F_70 ( V_35 ) ;
F_87 ( V_35 ) ;
F_88 ( V_35 ) ;
F_89 ( & V_4 -> V_212 ) ;
}
F_90 () ;
}
static void
F_91 ( struct V_3 * V_4 , unsigned V_213 ,
struct V_214 * V_215 )
{
unsigned long V_216 ;
T_5 V_217 ;
F_92 ( & V_4 -> V_218 , V_216 ) ;
V_217 = F_93 ( & V_4 -> V_219 , V_213 ) ;
F_94 ( & V_4 -> V_218 , V_216 ) ;
memset ( V_215 , 0 , sizeof( * V_215 ) ) ;
V_215 -> V_220 = F_95 ( V_217 ) ;
}
static void
F_96 ( struct V_34 * V_35 , T_6 V_5 )
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
V_5 = F_97 ( V_5 ) ;
V_10 = V_4 -> V_11 [ V_5 ] ;
V_117 = F_55 ( V_35 , V_5 ) ;
V_2 = V_10 -> V_24 ;
V_2 = F_1 ( V_2 , V_4 , V_5 ) ;
while ( V_2 != F_98 ( V_10 -> V_25 ) ) {
F_99 () ;
V_58 = F_13 ( F_98 ( V_2 -> V_37 ) ) ;
if ( V_58 & V_65 )
break;
V_36 = F_3 ( V_10 -> V_18 , V_2 , V_4 ) ;
V_42 = V_10 -> V_40 [ V_36 ] ;
V_10 -> V_40 [ V_36 ] = NULL ;
if ( ! F_100 ( V_10 , F_14 ( V_2 -> V_38 ) ) )
F_33 ( & V_4 -> V_86 -> V_87 ,
F_14 ( V_2 -> V_38 ) ,
F_13 ( V_2 -> V_39 ) ,
V_88 ) ;
V_2 -> V_38 = F_25 ( 0 ) ;
if ( ! V_42 ) {
V_2 = F_1 ( V_2 , V_4 , V_5 ) ;
continue;
}
if ( V_58 & ( V_221 | V_222 |
V_223 | V_224 |
V_225 ) ) {
V_35 -> V_206 . V_207 ++ ;
if ( V_58 & V_221 )
V_35 -> V_206 . V_226 ++ ;
if ( V_58 & V_222 )
V_35 -> V_206 . V_227 ++ ;
if ( V_58 & V_223 )
V_35 -> V_206 . V_228 ++ ;
if ( V_58 & V_224 )
V_35 -> V_206 . V_229 ++ ;
if ( V_58 & V_225 )
V_35 -> V_206 . V_230 ++ ;
} else {
V_35 -> V_206 . V_231 ++ ;
V_35 -> V_206 . V_232 += V_42 -> V_27 ;
}
if ( F_19 ( F_22 ( V_42 ) -> V_70 & V_96 ) &&
V_4 -> V_7 ) {
struct V_214 V_233 ;
struct V_7 * V_53 = (struct V_7 * ) V_2 ;
F_91 ( V_4 , F_14 ( V_53 -> V_213 ) , & V_233 ) ;
F_101 ( V_42 , & V_233 ) ;
}
if ( V_58 & V_234 )
V_35 -> V_206 . V_235 ++ ;
F_29 ( V_42 ) ;
F_39 () ;
V_10 -> V_24 = V_2 ;
V_2 = F_1 ( V_2 , V_4 , V_5 ) ;
if ( F_102 ( V_35 ) ) {
V_92 = F_4 ( V_4 , V_10 ) ;
if ( V_92 >= V_10 -> V_236 )
F_103 ( V_117 ) ;
}
}
if ( V_2 != V_10 -> V_25 &&
F_53 ( V_4 -> V_97 + F_41 ( V_5 ) ) == 0 )
F_40 ( 0 , V_4 -> V_97 + F_41 ( V_5 ) ) ;
}
static void
F_104 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
T_6 V_5 ;
F_105 (queue_id, &fep->work_tx, FEC_ENET_MAX_TX_QS) {
F_106 ( V_5 , & V_4 -> V_237 ) ;
F_96 ( V_35 , V_5 ) ;
}
return;
}
static int
F_107 ( struct V_34 * V_35 , struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_238 ;
V_238 = ( ( unsigned long ) V_42 -> V_95 ) & V_4 -> V_239 ;
if ( V_238 )
F_108 ( V_42 , V_4 -> V_239 + 1 - V_238 ) ;
V_2 -> V_38 = F_25 ( F_27 ( & V_4 -> V_86 -> V_87 , V_42 -> V_95 , V_240 - V_4 -> V_239 , V_241 ) ) ;
if ( F_28 ( & V_4 -> V_86 -> V_87 , F_14 ( V_2 -> V_38 ) ) ) {
if ( F_30 () )
F_31 ( V_35 , L_8 ) ;
return - V_89 ;
}
return 0 ;
}
static bool F_109 ( struct V_34 * V_35 , struct V_41 * * V_42 ,
struct V_1 * V_2 , T_4 V_242 , bool V_243 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_41 * V_244 ;
if ( V_242 > V_4 -> V_245 )
return false ;
V_244 = F_110 ( V_35 , V_242 ) ;
if ( ! V_244 )
return false ;
F_111 ( & V_4 -> V_86 -> V_87 ,
F_14 ( V_2 -> V_38 ) ,
V_240 - V_4 -> V_239 ,
V_241 ) ;
if ( ! V_243 )
memcpy ( V_244 -> V_95 , ( * V_42 ) -> V_95 , V_242 ) ;
else
F_7 ( V_244 -> V_95 , ( * V_42 ) -> V_95 , V_242 ) ;
* V_42 = V_244 ;
return true ;
}
static int
F_112 ( struct V_34 * V_35 , int V_246 , T_6 V_5 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
unsigned short V_58 ;
struct V_41 * V_247 = NULL ;
struct V_41 * V_42 ;
T_7 V_248 ;
T_8 * V_95 ;
int V_249 = 0 ;
struct V_7 * V_53 = NULL ;
bool V_250 = false ;
T_6 V_251 ;
int V_36 = 0 ;
bool V_252 ;
bool V_253 = V_4 -> V_74 & V_84 ;
#ifdef F_113
F_114 () ;
#endif
V_5 = F_97 ( V_5 ) ;
V_13 = V_4 -> V_14 [ V_5 ] ;
V_2 = V_13 -> V_123 ;
while ( ! ( ( V_58 = F_13 ( V_2 -> V_37 ) ) & V_121 ) ) {
if ( V_249 >= V_246 )
break;
V_249 ++ ;
if ( ( V_58 & V_254 ) == 0 )
F_31 ( V_35 , L_9 ) ;
F_40 ( V_255 , V_4 -> V_97 + V_142 ) ;
if ( V_58 & ( V_256 | V_257 | V_258 |
V_259 | V_260 ) ) {
V_35 -> V_206 . V_261 ++ ;
if ( V_58 & ( V_256 | V_257 ) ) {
V_35 -> V_206 . V_262 ++ ;
}
if ( V_58 & V_258 )
V_35 -> V_206 . V_263 ++ ;
if ( V_58 & V_259 )
V_35 -> V_206 . V_264 ++ ;
if ( V_58 & V_260 )
V_35 -> V_206 . V_265 ++ ;
}
if ( V_58 & V_266 ) {
V_35 -> V_206 . V_261 ++ ;
V_35 -> V_206 . V_263 ++ ;
goto V_267;
}
V_35 -> V_206 . V_268 ++ ;
V_248 = F_13 ( V_2 -> V_39 ) ;
V_35 -> V_206 . V_269 += V_248 ;
V_36 = F_3 ( V_13 -> V_20 , V_2 , V_4 ) ;
V_42 = V_13 -> V_270 [ V_36 ] ;
V_252 = F_109 ( V_35 , & V_42 , V_2 , V_248 - 4 ,
V_253 ) ;
if ( ! V_252 ) {
V_247 = F_110 ( V_35 , V_240 ) ;
if ( F_19 ( ! V_247 ) ) {
V_35 -> V_206 . V_271 ++ ;
goto V_267;
}
F_33 ( & V_4 -> V_86 -> V_87 ,
F_14 ( V_2 -> V_38 ) ,
V_240 - V_4 -> V_239 ,
V_241 ) ;
}
F_115 ( V_42 -> V_95 - V_272 ) ;
F_116 ( V_42 , V_248 - 4 ) ;
V_95 = V_42 -> V_95 ;
if ( ! V_252 && V_253 )
F_5 ( V_95 , V_248 ) ;
V_53 = NULL ;
if ( V_4 -> V_7 )
V_53 = (struct V_7 * ) V_2 ;
V_250 = false ;
if ( ( V_35 -> V_273 & V_274 ) &&
V_4 -> V_7 &&
( V_53 -> V_79 & F_25 ( V_275 ) ) ) {
struct V_276 * V_277 =
(struct V_276 * ) ( V_95 + V_278 ) ;
V_251 = F_117 ( V_277 -> V_279 ) ;
V_250 = true ;
memmove ( V_42 -> V_95 + V_280 , V_95 , V_138 * 2 ) ;
F_118 ( V_42 , V_280 ) ;
}
V_42 -> V_43 = F_119 ( V_42 , V_35 ) ;
if ( V_4 -> V_281 && V_4 -> V_7 )
F_91 ( V_4 , F_14 ( V_53 -> V_213 ) ,
F_120 ( V_42 ) ) ;
if ( V_4 -> V_7 &&
( V_4 -> V_151 & V_152 ) ) {
if ( ! ( V_53 -> V_79 & F_25 ( V_282 ) ) ) {
V_42 -> V_46 = V_283 ;
} else {
F_121 ( V_42 ) ;
}
}
if ( V_250 )
F_122 ( V_42 ,
F_16 ( V_284 ) ,
V_251 ) ;
F_123 ( & V_4 -> V_212 , V_42 ) ;
if ( V_252 ) {
F_124 ( & V_4 -> V_86 -> V_87 ,
F_14 ( V_2 -> V_38 ) ,
V_240 - V_4 -> V_239 ,
V_241 ) ;
} else {
V_13 -> V_270 [ V_36 ] = V_247 ;
F_107 ( V_35 , V_2 , V_247 ) ;
}
V_267:
V_58 &= ~ V_285 ;
V_58 |= V_121 ;
V_2 -> V_37 = F_32 ( V_58 ) ;
if ( V_4 -> V_7 ) {
struct V_7 * V_53 = (struct V_7 * ) V_2 ;
V_53 -> V_79 = F_25 ( V_286 ) ;
V_53 -> V_287 = 0 ;
V_53 -> V_78 = 0 ;
}
V_2 = F_1 ( V_2 , V_4 , V_5 ) ;
F_40 ( 0 , V_4 -> V_97 + F_60 ( V_5 ) ) ;
}
V_13 -> V_123 = V_2 ;
return V_249 ;
}
static int
F_125 ( struct V_34 * V_35 , int V_246 )
{
int V_249 = 0 ;
T_6 V_5 ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_105 (queue_id, &fep->work_rx, FEC_ENET_MAX_RX_QS) {
F_106 ( V_5 , & V_4 -> V_288 ) ;
V_249 += F_112 ( V_35 ,
V_246 - V_249 , V_5 ) ;
}
return V_249 ;
}
static bool
F_126 ( struct V_3 * V_4 , T_9 V_289 )
{
if ( V_289 == 0 )
return false ;
if ( V_289 & V_255 )
V_4 -> V_288 |= ( 1 << 2 ) ;
if ( V_289 & V_290 )
V_4 -> V_288 |= ( 1 << 0 ) ;
if ( V_289 & V_291 )
V_4 -> V_288 |= ( 1 << 1 ) ;
if ( V_289 & V_292 )
V_4 -> V_237 |= ( 1 << 2 ) ;
if ( V_289 & V_293 )
V_4 -> V_237 |= ( 1 << 0 ) ;
if ( V_289 & V_294 )
V_4 -> V_237 |= ( 1 << 1 ) ;
return true ;
}
static T_10
F_127 ( int V_295 , void * V_296 )
{
struct V_34 * V_35 = V_296 ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
T_9 V_289 ;
T_10 V_111 = V_297 ;
V_289 = F_53 ( V_4 -> V_97 + V_142 ) ;
F_40 ( V_289 , V_4 -> V_97 + V_142 ) ;
F_126 ( V_4 , V_289 ) ;
if ( ( V_4 -> V_237 || V_4 -> V_288 ) && V_4 -> V_191 ) {
V_111 = V_298 ;
if ( F_128 ( & V_4 -> V_212 ) ) {
F_40 ( V_194 , V_4 -> V_97 + V_193 ) ;
F_129 ( & V_4 -> V_212 ) ;
}
}
if ( V_289 & V_194 ) {
V_111 = V_298 ;
F_130 ( & V_4 -> V_299 ) ;
}
if ( V_4 -> V_300 )
F_131 ( V_4 ) ;
return V_111 ;
}
static int F_132 ( struct V_301 * V_212 , int V_246 )
{
struct V_34 * V_35 = V_212 -> V_87 ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_302 ;
V_302 = F_125 ( V_35 , V_246 ) ;
F_104 ( V_35 ) ;
if ( V_302 < V_246 ) {
F_133 ( V_212 ) ;
F_40 ( V_192 , V_4 -> V_97 + V_193 ) ;
}
return V_302 ;
}
static void F_134 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_195 * V_196 = F_135 ( & V_4 -> V_86 -> V_87 ) ;
unsigned char * V_303 , V_304 [ V_138 ] ;
V_303 = V_305 ;
if ( ! F_136 ( V_303 ) ) {
struct V_306 * V_307 = V_4 -> V_86 -> V_87 . V_308 ;
if ( V_307 ) {
const char * V_309 = F_137 ( V_307 ) ;
if ( V_309 )
V_303 = ( unsigned char * ) V_309 ;
}
}
if ( ! F_136 ( V_303 ) ) {
#ifdef V_148
if ( V_310 )
V_303 = ( unsigned char * ) V_310 ;
#else
if ( V_196 )
V_303 = ( unsigned char * ) & V_196 -> V_309 ;
#endif
}
if ( ! F_136 ( V_303 ) ) {
* ( ( V_311 * ) & V_304 [ 0 ] ) =
F_72 ( F_53 ( V_4 -> V_97 + V_140 ) ) ;
* ( ( V_312 * ) & V_304 [ 4 ] ) =
F_138 ( F_53 ( V_4 -> V_97 + V_141 ) >> 16 ) ;
V_303 = & V_304 [ 0 ] ;
}
if ( ! F_136 ( V_303 ) ) {
F_31 ( V_35 , L_10 , V_303 ) ;
F_139 ( V_35 ) ;
F_11 ( V_35 , L_11 ,
V_35 -> V_137 ) ;
return;
}
memcpy ( V_35 -> V_137 , V_303 , V_138 ) ;
if ( V_303 == V_305 )
V_35 -> V_137 [ V_138 - 1 ] = V_305 [ V_138 - 1 ] + V_4 -> V_296 ;
}
static void F_140 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_313 * V_160 = V_4 -> V_160 ;
int V_314 = 0 ;
if ( V_4 -> V_315 && V_160 -> V_316 == V_317 ) {
V_160 -> V_316 = V_318 ;
return;
}
if ( ! F_84 ( V_35 ) || ! F_83 ( V_35 ) ) {
V_4 -> V_191 = 0 ;
} else if ( V_160 -> V_191 ) {
if ( ! V_4 -> V_191 ) {
V_4 -> V_191 = V_160 -> V_191 ;
V_314 = 1 ;
}
if ( V_4 -> V_143 != V_160 -> V_319 ) {
V_4 -> V_143 = V_160 -> V_319 ;
V_314 = 1 ;
}
if ( V_160 -> V_161 != V_4 -> V_161 ) {
V_4 -> V_161 = V_160 -> V_161 ;
V_314 = 1 ;
}
if ( V_314 ) {
F_85 ( & V_4 -> V_212 ) ;
F_86 ( V_35 ) ;
F_70 ( V_35 ) ;
F_87 ( V_35 ) ;
F_88 ( V_35 ) ;
F_89 ( & V_4 -> V_212 ) ;
}
} else {
if ( V_4 -> V_191 ) {
F_85 ( & V_4 -> V_212 ) ;
F_86 ( V_35 ) ;
F_78 ( V_35 ) ;
F_88 ( V_35 ) ;
F_89 ( & V_4 -> V_212 ) ;
V_4 -> V_191 = V_160 -> V_191 ;
V_314 = 1 ;
}
}
if ( V_314 )
F_141 ( V_160 ) ;
}
static int F_142 ( struct V_320 * V_321 , int V_322 , int V_323 )
{
struct V_3 * V_4 = V_321 -> V_324 ;
struct V_325 * V_87 = & V_4 -> V_86 -> V_87 ;
unsigned long V_326 ;
int V_111 = 0 ;
V_111 = F_143 ( V_87 ) ;
if ( V_111 < 0 )
return V_111 ;
V_4 -> V_315 = 0 ;
F_144 ( & V_4 -> V_299 ) ;
F_40 ( V_327 | V_328 |
F_145 ( V_322 ) | F_146 ( V_323 ) |
V_329 , V_4 -> V_97 + V_330 ) ;
V_326 = F_147 ( & V_4 -> V_299 ,
F_148 ( V_331 ) ) ;
if ( V_326 == 0 ) {
V_4 -> V_315 = 1 ;
F_31 ( V_4 -> V_211 , L_12 ) ;
V_111 = - V_332 ;
goto V_333;
}
V_111 = F_149 ( F_53 ( V_4 -> V_97 + V_330 ) ) ;
V_333:
F_150 ( V_87 ) ;
F_151 ( V_87 ) ;
return V_111 ;
}
static int F_152 ( struct V_320 * V_321 , int V_322 , int V_323 ,
T_6 V_334 )
{
struct V_3 * V_4 = V_321 -> V_324 ;
struct V_325 * V_87 = & V_4 -> V_86 -> V_87 ;
unsigned long V_326 ;
int V_111 ;
V_111 = F_143 ( V_87 ) ;
if ( V_111 < 0 )
return V_111 ;
else
V_111 = 0 ;
V_4 -> V_315 = 0 ;
F_144 ( & V_4 -> V_299 ) ;
F_40 ( V_327 | V_335 |
F_145 ( V_322 ) | F_146 ( V_323 ) |
V_329 | F_149 ( V_334 ) ,
V_4 -> V_97 + V_330 ) ;
V_326 = F_147 ( & V_4 -> V_299 ,
F_148 ( V_331 ) ) ;
if ( V_326 == 0 ) {
V_4 -> V_315 = 1 ;
F_31 ( V_4 -> V_211 , L_13 ) ;
V_111 = - V_332 ;
}
F_150 ( V_87 ) ;
F_151 ( V_87 ) ;
return V_111 ;
}
static int F_153 ( struct V_34 * V_35 , bool V_336 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_111 ;
if ( V_336 ) {
V_111 = F_154 ( V_4 -> V_337 ) ;
if ( V_111 )
return V_111 ;
if ( V_4 -> V_338 ) {
V_111 = F_154 ( V_4 -> V_338 ) ;
if ( V_111 )
goto V_339;
}
if ( V_4 -> V_340 ) {
F_155 ( & V_4 -> V_341 ) ;
V_111 = F_154 ( V_4 -> V_340 ) ;
if ( V_111 ) {
F_156 ( & V_4 -> V_341 ) ;
goto V_342;
} else {
V_4 -> V_343 = true ;
}
F_156 ( & V_4 -> V_341 ) ;
}
if ( V_4 -> V_344 ) {
V_111 = F_154 ( V_4 -> V_344 ) ;
if ( V_111 )
goto V_345;
}
} else {
F_157 ( V_4 -> V_337 ) ;
if ( V_4 -> V_338 )
F_157 ( V_4 -> V_338 ) ;
if ( V_4 -> V_340 ) {
F_155 ( & V_4 -> V_341 ) ;
F_157 ( V_4 -> V_340 ) ;
V_4 -> V_343 = false ;
F_156 ( & V_4 -> V_341 ) ;
}
if ( V_4 -> V_344 )
F_157 ( V_4 -> V_344 ) ;
}
return 0 ;
V_345:
if ( V_4 -> V_344 )
F_157 ( V_4 -> V_344 ) ;
V_342:
if ( V_4 -> V_338 )
F_157 ( V_4 -> V_338 ) ;
V_339:
F_157 ( V_4 -> V_337 ) ;
return V_111 ;
}
static int F_158 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_313 * V_160 = NULL ;
char V_346 [ V_347 ] ;
char V_348 [ V_347 + 3 ] ;
int V_349 ;
int V_296 = V_4 -> V_296 ;
V_4 -> V_160 = NULL ;
if ( V_4 -> V_350 ) {
V_160 = F_159 ( V_35 , V_4 -> V_350 ,
& F_140 , 0 ,
V_4 -> V_154 ) ;
if ( ! V_160 )
return - V_351 ;
} else {
for ( V_349 = 0 ; ( V_349 < V_352 ) ; V_349 ++ ) {
if ( ! F_160 ( V_4 -> V_320 , V_349 ) )
continue;
if ( V_296 -- )
continue;
F_161 ( V_346 , V_4 -> V_320 -> V_353 , V_347 ) ;
break;
}
if ( V_349 >= V_352 ) {
F_11 ( V_35 , L_14 ) ;
F_161 ( V_346 , L_15 , V_347 ) ;
V_349 = 0 ;
}
snprintf ( V_348 , sizeof( V_348 ) ,
V_354 , V_346 , V_349 ) ;
V_160 = F_162 ( V_35 , V_348 , & F_140 ,
V_4 -> V_154 ) ;
}
if ( F_37 ( V_160 ) ) {
F_31 ( V_35 , L_16 ) ;
return F_163 ( V_160 ) ;
}
if ( V_4 -> V_74 & V_355 ) {
V_160 -> V_356 &= V_357 ;
V_160 -> V_356 &= ~ V_358 ;
#if ! F_73 ( V_148 )
V_160 -> V_356 |= V_359 ;
#endif
}
else
V_160 -> V_356 &= V_360 ;
V_160 -> V_361 = V_160 -> V_356 ;
V_4 -> V_160 = V_160 ;
V_4 -> V_191 = 0 ;
V_4 -> V_143 = 0 ;
F_164 ( V_160 ) ;
return 0 ;
}
static int F_165 ( struct V_362 * V_86 )
{
static struct V_320 * V_363 ;
struct V_34 * V_35 = F_166 ( V_86 ) ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_306 * V_364 ;
int V_365 = - V_366 ;
T_4 V_367 , V_368 ;
if ( ( V_4 -> V_74 & V_369 ) && V_4 -> V_296 > 0 ) {
if ( V_370 && V_363 ) {
V_4 -> V_320 = V_363 ;
V_370 ++ ;
return 0 ;
}
return - V_371 ;
}
V_4 -> V_315 = 0 ;
V_367 = F_167 ( F_168 ( V_4 -> V_372 ) , 5000000 ) ;
if ( V_4 -> V_74 & V_136 )
V_367 -- ;
if ( V_367 > 63 ) {
F_169 ( & V_86 -> V_87 ,
L_17 ,
F_168 ( V_4 -> V_372 ) ) ;
V_365 = - V_373 ;
goto V_374;
}
V_368 = F_167 ( F_168 ( V_4 -> V_372 ) , 100000000 ) - 1 ;
V_4 -> V_146 = V_367 << 1 | V_368 << 8 ;
F_40 ( V_4 -> V_146 , V_4 -> V_97 + V_147 ) ;
V_4 -> V_320 = F_170 () ;
if ( V_4 -> V_320 == NULL ) {
V_365 = - V_89 ;
goto V_374;
}
V_4 -> V_320 -> V_375 = L_18 ;
V_4 -> V_320 -> V_376 = F_142 ;
V_4 -> V_320 -> V_377 = F_152 ;
snprintf ( V_4 -> V_320 -> V_353 , V_347 , L_19 ,
V_86 -> V_375 , V_4 -> V_296 + 1 ) ;
V_4 -> V_320 -> V_324 = V_4 ;
V_4 -> V_320 -> V_378 = & V_86 -> V_87 ;
V_364 = F_171 ( V_86 -> V_87 . V_308 , L_20 ) ;
if ( V_364 ) {
V_365 = F_172 ( V_4 -> V_320 , V_364 ) ;
F_173 ( V_364 ) ;
} else {
V_365 = F_174 ( V_4 -> V_320 ) ;
}
if ( V_365 )
goto V_379;
V_370 ++ ;
if ( V_4 -> V_74 & V_369 )
V_363 = V_4 -> V_320 ;
return 0 ;
V_379:
F_175 ( V_4 -> V_320 ) ;
V_374:
return V_365 ;
}
static void F_176 ( struct V_3 * V_4 )
{
if ( -- V_370 == 0 ) {
F_177 ( V_4 -> V_320 ) ;
F_175 ( V_4 -> V_320 ) ;
}
}
static int F_178 ( struct V_34 * V_35 ,
struct V_380 * V_381 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_313 * V_382 = V_4 -> V_160 ;
if ( ! V_382 )
return - V_351 ;
return F_179 ( V_382 , V_381 ) ;
}
static int F_180 ( struct V_34 * V_35 ,
struct V_380 * V_381 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_313 * V_382 = V_4 -> V_160 ;
if ( ! V_382 )
return - V_351 ;
return F_181 ( V_382 , V_381 ) ;
}
static void F_182 ( struct V_34 * V_35 ,
struct V_383 * V_384 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_161 ( V_384 -> V_385 , V_4 -> V_86 -> V_87 . V_385 -> V_375 ,
sizeof( V_384 -> V_385 ) ) ;
F_161 ( V_384 -> V_45 , L_21 , sizeof( V_384 -> V_45 ) ) ;
F_161 ( V_384 -> V_386 , F_183 ( & V_35 -> V_87 ) , sizeof( V_384 -> V_386 ) ) ;
}
static int F_184 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_387 * V_388 ;
int V_389 = 0 ;
V_388 = F_185 ( V_4 -> V_86 , V_390 , 0 ) ;
if ( V_388 )
V_389 = F_186 ( V_388 ) ;
return V_389 ;
}
static void F_187 ( struct V_34 * V_35 ,
struct V_391 * V_392 , void * V_393 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
T_4 T_11 * V_394 = ( T_4 T_11 * ) V_4 -> V_97 ;
T_4 * V_29 = ( T_4 * ) V_393 ;
T_4 V_28 , V_238 ;
memset ( V_29 , 0 , V_392 -> V_27 ) ;
for ( V_28 = 0 ; V_28 < F_188 ( V_395 ) ; V_28 ++ ) {
V_238 = V_395 [ V_28 ] / 4 ;
V_29 [ V_238 ] = F_53 ( & V_394 [ V_238 ] ) ;
}
}
static int F_189 ( struct V_34 * V_35 ,
struct V_396 * V_384 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
if ( V_4 -> V_7 ) {
V_384 -> V_397 = V_398 |
V_399 |
V_400 |
V_401 |
V_402 |
V_403 ;
if ( V_4 -> V_300 )
V_384 -> V_404 = F_190 ( V_4 -> V_300 ) ;
else
V_384 -> V_404 = - 1 ;
V_384 -> V_405 = ( 1 << V_406 ) |
( 1 << V_407 ) ;
V_384 -> V_408 = ( 1 << V_409 ) |
( 1 << V_410 ) ;
return 0 ;
} else {
return F_191 ( V_35 , V_384 ) ;
}
}
static void F_192 ( struct V_34 * V_35 ,
struct V_411 * V_174 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
V_174 -> V_412 = ( V_4 -> V_171 & V_173 ) != 0 ;
V_174 -> V_413 = ( V_4 -> V_171 & V_172 ) != 0 ;
V_174 -> V_414 = V_174 -> V_413 ;
}
static int F_193 ( struct V_34 * V_35 ,
struct V_411 * V_174 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
if ( ! V_4 -> V_160 )
return - V_351 ;
if ( V_174 -> V_413 != V_174 -> V_414 ) {
F_11 ( V_35 ,
L_22 ) ;
return - V_373 ;
}
V_4 -> V_171 = 0 ;
V_4 -> V_171 |= V_174 -> V_414 ? V_172 : 0 ;
V_4 -> V_171 |= V_174 -> V_412 ? V_173 : 0 ;
if ( V_174 -> V_414 || V_174 -> V_412 ) {
V_4 -> V_160 -> V_356 |= V_415 ;
V_4 -> V_160 -> V_361 |= V_415 ;
} else {
V_4 -> V_160 -> V_356 &= ~ V_415 ;
V_4 -> V_160 -> V_361 &= ~ V_415 ;
}
if ( V_174 -> V_412 ) {
if ( F_84 ( V_35 ) )
F_78 ( V_35 ) ;
F_194 ( V_4 -> V_160 ) ;
}
if ( F_84 ( V_35 ) ) {
F_85 ( & V_4 -> V_212 ) ;
F_86 ( V_35 ) ;
F_70 ( V_35 ) ;
F_87 ( V_35 ) ;
F_88 ( V_35 ) ;
F_89 ( & V_4 -> V_212 ) ;
}
return 0 ;
}
static void F_195 ( struct V_34 * V_87 ,
struct V_416 * V_206 , T_5 * V_95 )
{
struct V_3 * V_4 = F_10 ( V_87 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < F_188 ( V_417 ) ; V_28 ++ )
V_95 [ V_28 ] = F_53 ( V_4 -> V_97 + V_417 [ V_28 ] . V_418 ) ;
}
static void F_196 ( struct V_34 * V_211 ,
T_4 V_419 , T_12 * V_95 )
{
int V_28 ;
switch ( V_419 ) {
case V_420 :
for ( V_28 = 0 ; V_28 < F_188 ( V_417 ) ; V_28 ++ )
memcpy ( V_95 + V_28 * V_421 ,
V_417 [ V_28 ] . V_375 , V_421 ) ;
break;
}
}
static int F_197 ( struct V_34 * V_87 , int V_422 )
{
switch ( V_422 ) {
case V_420 :
return F_188 ( V_417 ) ;
default:
return - V_423 ;
}
}
static int F_198 ( struct V_34 * V_87 )
{
struct V_3 * V_4 = F_10 ( V_87 ) ;
struct V_313 * V_382 = V_4 -> V_160 ;
if ( ! V_382 )
return - V_351 ;
return F_199 ( V_382 ) ;
}
static int F_200 ( struct V_34 * V_35 , int V_424 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
return V_424 * ( V_4 -> V_425 / 64000 ) / 1000 ;
}
static void F_201 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_426 , V_427 ;
if ( ! ( V_4 -> V_74 & V_75 ) )
return;
if ( ! V_4 -> V_428 || ! V_4 -> V_429 ||
! V_4 -> V_430 || ! V_4 -> V_431 )
return;
V_426 = V_432 ;
V_427 = V_432 ;
V_426 |= F_202 ( V_4 -> V_429 ) ;
V_426 |= F_203 ( F_200 ( V_35 , V_4 -> V_428 ) ) ;
V_427 |= F_202 ( V_4 -> V_431 ) ;
V_427 |= F_203 ( F_200 ( V_35 , V_4 -> V_430 ) ) ;
V_426 |= V_433 ;
V_427 |= V_433 ;
F_40 ( V_427 , V_4 -> V_97 + V_434 ) ;
F_40 ( V_426 , V_4 -> V_97 + V_435 ) ;
F_40 ( V_427 , V_4 -> V_97 + V_436 ) ;
F_40 ( V_426 , V_4 -> V_97 + V_437 ) ;
F_40 ( V_427 , V_4 -> V_97 + V_438 ) ;
F_40 ( V_426 , V_4 -> V_97 + V_439 ) ;
}
static int
F_204 ( struct V_34 * V_35 , struct V_440 * V_441 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
if ( ! ( V_4 -> V_74 & V_75 ) )
return - V_423 ;
V_441 -> V_442 = V_4 -> V_428 ;
V_441 -> V_443 = V_4 -> V_429 ;
V_441 -> V_444 = V_4 -> V_430 ;
V_441 -> V_445 = V_4 -> V_431 ;
return 0 ;
}
static int
F_205 ( struct V_34 * V_35 , struct V_440 * V_441 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
unsigned int V_446 ;
if ( ! ( V_4 -> V_74 & V_75 ) )
return - V_423 ;
if ( V_441 -> V_443 > 255 ) {
F_206 ( L_23 ) ;
return - V_373 ;
}
if ( V_441 -> V_445 > 255 ) {
F_206 ( L_24 ) ;
return - V_373 ;
}
V_446 = F_200 ( V_35 , V_4 -> V_428 ) ;
if ( V_446 > 0xFFFF ) {
F_206 ( L_25 ) ;
return - V_373 ;
}
V_446 = F_200 ( V_35 , V_4 -> V_430 ) ;
if ( V_446 > 0xFFFF ) {
F_206 ( L_25 ) ;
return - V_373 ;
}
V_4 -> V_428 = V_441 -> V_442 ;
V_4 -> V_429 = V_441 -> V_443 ;
V_4 -> V_430 = V_441 -> V_444 ;
V_4 -> V_431 = V_441 -> V_445 ;
F_201 ( V_35 ) ;
return 0 ;
}
static void F_77 ( struct V_34 * V_35 )
{
struct V_440 V_441 ;
V_441 . V_442 = V_447 ;
V_441 . V_443 = V_448 ;
V_441 . V_444 = V_447 ;
V_441 . V_445 = V_448 ;
F_205 ( V_35 , & V_441 ) ;
}
static int F_207 ( struct V_34 * V_211 ,
const struct V_449 * V_450 ,
void * V_95 )
{
struct V_3 * V_4 = F_10 ( V_211 ) ;
int V_111 = 0 ;
switch ( V_450 -> V_353 ) {
case V_451 :
* ( T_4 * ) V_95 = V_4 -> V_245 ;
break;
default:
V_111 = - V_373 ;
break;
}
return V_111 ;
}
static int F_208 ( struct V_34 * V_211 ,
const struct V_449 * V_450 ,
const void * V_95 )
{
struct V_3 * V_4 = F_10 ( V_211 ) ;
int V_111 = 0 ;
switch ( V_450 -> V_353 ) {
case V_451 :
V_4 -> V_245 = * ( T_4 * ) V_95 ;
break;
default:
V_111 = - V_373 ;
break;
}
return V_111 ;
}
static void
F_209 ( struct V_34 * V_35 , struct V_452 * V_453 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
if ( V_4 -> V_200 & V_454 ) {
V_453 -> V_356 = V_455 ;
V_453 -> V_456 = V_4 -> V_200 & V_457 ? V_455 : 0 ;
} else {
V_453 -> V_356 = V_453 -> V_456 = 0 ;
}
}
static int
F_210 ( struct V_34 * V_35 , struct V_452 * V_453 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
if ( ! ( V_4 -> V_200 & V_454 ) )
return - V_373 ;
if ( V_453 -> V_456 & ~ V_455 )
return - V_373 ;
F_211 ( & V_35 -> V_87 , V_453 -> V_456 & V_455 ) ;
if ( F_212 ( & V_35 -> V_87 ) ) {
V_4 -> V_200 |= V_457 ;
if ( V_4 -> V_295 [ 0 ] > 0 )
F_213 ( V_4 -> V_295 [ 0 ] ) ;
} else {
V_4 -> V_200 &= ( ~ V_457 ) ;
if ( V_4 -> V_295 [ 0 ] > 0 )
F_214 ( V_4 -> V_295 [ 0 ] ) ;
}
return 0 ;
}
static int F_215 ( struct V_34 * V_35 , struct V_458 * V_459 , int V_381 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_313 * V_382 = V_4 -> V_160 ;
if ( ! F_84 ( V_35 ) )
return - V_373 ;
if ( ! V_382 )
return - V_351 ;
if ( V_4 -> V_7 ) {
if ( V_381 == V_460 )
return F_216 ( V_35 , V_459 ) ;
if ( V_381 == V_461 )
return F_217 ( V_35 , V_459 ) ;
}
return F_218 ( V_382 , V_459 , V_381 ) ;
}
static void F_219 ( struct V_34 * V_35 )
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
V_42 = V_13 -> V_270 [ V_28 ] ;
V_13 -> V_270 [ V_28 ] = NULL ;
if ( V_42 ) {
F_33 ( & V_4 -> V_86 -> V_87 ,
F_14 ( V_2 -> V_38 ) ,
V_240 - V_4 -> V_239 ,
V_241 ) ;
F_220 ( V_42 ) ;
}
V_2 = F_1 ( V_2 , V_4 , V_119 ) ;
}
}
for ( V_119 = 0 ; V_119 < V_4 -> V_124 ; V_119 ++ ) {
V_10 = V_4 -> V_11 [ V_119 ] ;
V_2 = V_10 -> V_18 ;
for ( V_28 = 0 ; V_28 < V_10 -> V_19 ; V_28 ++ ) {
F_221 ( V_10 -> V_85 [ V_28 ] ) ;
V_10 -> V_85 [ V_28 ] = NULL ;
V_42 = V_10 -> V_40 [ V_28 ] ;
V_10 -> V_40 [ V_28 ] = NULL ;
F_220 ( V_42 ) ;
}
}
}
static void F_222 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_28 ;
struct V_9 * V_10 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_124 ; V_28 ++ )
if ( V_4 -> V_11 [ V_28 ] && V_4 -> V_11 [ V_28 ] -> V_104 ) {
V_10 = V_4 -> V_11 [ V_28 ] ;
F_223 ( NULL ,
V_10 -> V_19 * V_105 ,
V_10 -> V_104 ,
V_10 -> V_106 ) ;
}
for ( V_28 = 0 ; V_28 < V_4 -> V_120 ; V_28 ++ )
F_221 ( V_4 -> V_14 [ V_28 ] ) ;
for ( V_28 = 0 ; V_28 < V_4 -> V_124 ; V_28 ++ )
F_221 ( V_4 -> V_11 [ V_28 ] ) ;
}
static int F_224 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_28 ;
int V_111 = 0 ;
struct V_9 * V_10 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_124 ; V_28 ++ ) {
V_10 = F_225 ( sizeof( * V_10 ) , V_462 ) ;
if ( ! V_10 ) {
V_111 = - V_89 ;
goto V_463;
}
V_4 -> V_11 [ V_28 ] = V_10 ;
V_10 -> V_19 = V_464 ;
V_4 -> V_465 += V_4 -> V_11 [ V_28 ] -> V_19 ;
V_10 -> V_118 = V_466 ;
V_10 -> V_236 =
( V_10 -> V_19 - V_10 -> V_118 ) / 2 ;
V_10 -> V_104 = F_226 ( NULL ,
V_10 -> V_19 * V_105 ,
& V_10 -> V_106 ,
V_462 ) ;
if ( ! V_10 -> V_104 ) {
V_111 = - V_89 ;
goto V_463;
}
}
for ( V_28 = 0 ; V_28 < V_4 -> V_120 ; V_28 ++ ) {
V_4 -> V_14 [ V_28 ] = F_225 ( sizeof( * V_4 -> V_14 [ V_28 ] ) ,
V_462 ) ;
if ( ! V_4 -> V_14 [ V_28 ] ) {
V_111 = - V_89 ;
goto V_463;
}
V_4 -> V_14 [ V_28 ] -> V_21 = V_467 ;
V_4 -> V_468 += V_4 -> V_14 [ V_28 ] -> V_21 ;
}
return V_111 ;
V_463:
F_222 ( V_35 ) ;
return V_111 ;
}
static int
F_227 ( struct V_34 * V_35 , unsigned int V_55 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
unsigned int V_28 ;
struct V_41 * V_42 ;
struct V_1 * V_2 ;
struct V_12 * V_13 ;
V_13 = V_4 -> V_14 [ V_55 ] ;
V_2 = V_13 -> V_20 ;
for ( V_28 = 0 ; V_28 < V_13 -> V_21 ; V_28 ++ ) {
V_42 = F_110 ( V_35 , V_240 ) ;
if ( ! V_42 )
goto V_469;
if ( F_107 ( V_35 , V_2 , V_42 ) ) {
F_220 ( V_42 ) ;
goto V_469;
}
V_13 -> V_270 [ V_28 ] = V_42 ;
V_2 -> V_37 = F_32 ( V_121 ) ;
if ( V_4 -> V_7 ) {
struct V_7 * V_53 = (struct V_7 * ) V_2 ;
V_53 -> V_79 = F_25 ( V_286 ) ;
}
V_2 = F_1 ( V_2 , V_4 , V_55 ) ;
}
V_2 = F_2 ( V_2 , V_4 , V_55 ) ;
V_2 -> V_37 |= F_32 ( V_122 ) ;
return 0 ;
V_469:
F_219 ( V_35 ) ;
return - V_89 ;
}
static int
F_228 ( struct V_34 * V_35 , unsigned int V_55 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
unsigned int V_28 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
V_10 = V_4 -> V_11 [ V_55 ] ;
V_2 = V_10 -> V_18 ;
for ( V_28 = 0 ; V_28 < V_10 -> V_19 ; V_28 ++ ) {
V_10 -> V_85 [ V_28 ] = F_229 ( V_470 , V_462 ) ;
if ( ! V_10 -> V_85 [ V_28 ] )
goto V_469;
V_2 -> V_37 = F_32 ( 0 ) ;
V_2 -> V_38 = F_25 ( 0 ) ;
if ( V_4 -> V_7 ) {
struct V_7 * V_53 = (struct V_7 * ) V_2 ;
V_53 -> V_79 = F_25 ( V_69 ) ;
}
V_2 = F_1 ( V_2 , V_4 , V_55 ) ;
}
V_2 = F_2 ( V_2 , V_4 , V_55 ) ;
V_2 -> V_37 |= F_32 ( V_122 ) ;
return 0 ;
V_469:
F_219 ( V_35 ) ;
return - V_89 ;
}
static int F_230 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_120 ; V_28 ++ )
if ( F_227 ( V_35 , V_28 ) )
return - V_89 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_124 ; V_28 ++ )
if ( F_228 ( V_35 , V_28 ) )
return - V_89 ;
return 0 ;
}
static int
F_231 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
int V_111 ;
V_111 = F_143 ( & V_4 -> V_86 -> V_87 ) ;
if ( V_111 < 0 )
return V_111 ;
F_232 ( & V_4 -> V_86 -> V_87 ) ;
V_111 = F_153 ( V_35 , true ) ;
if ( V_111 )
goto V_471;
V_111 = F_230 ( V_35 ) ;
if ( V_111 )
goto V_472;
F_70 ( V_35 ) ;
V_111 = F_158 ( V_35 ) ;
if ( V_111 )
goto V_473;
F_89 ( & V_4 -> V_212 ) ;
F_233 ( V_4 -> V_160 ) ;
F_234 ( V_35 ) ;
F_211 ( & V_35 -> V_87 , V_4 -> V_200 &
V_457 ) ;
return 0 ;
V_473:
F_219 ( V_35 ) ;
V_472:
F_153 ( V_35 , false ) ;
V_471:
F_150 ( & V_4 -> V_86 -> V_87 ) ;
F_151 ( & V_4 -> V_86 -> V_87 ) ;
F_235 ( & V_4 -> V_86 -> V_87 ) ;
return V_111 ;
}
static int
F_236 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_237 ( V_4 -> V_160 ) ;
if ( F_83 ( V_35 ) ) {
F_85 ( & V_4 -> V_212 ) ;
F_238 ( V_35 ) ;
F_78 ( V_35 ) ;
}
F_239 ( V_4 -> V_160 ) ;
V_4 -> V_160 = NULL ;
F_153 ( V_35 , false ) ;
F_235 ( & V_4 -> V_86 -> V_87 ) ;
F_150 ( & V_4 -> V_86 -> V_87 ) ;
F_151 ( & V_4 -> V_86 -> V_87 ) ;
F_219 ( V_35 ) ;
return 0 ;
}
static void F_75 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_474 * V_475 ;
unsigned int V_28 , V_476 , V_95 , V_477 , V_478 ;
unsigned char V_479 ;
if ( V_35 -> V_216 & V_480 ) {
V_478 = F_53 ( V_4 -> V_97 + V_186 ) ;
V_478 |= 0x8 ;
F_40 ( V_478 , V_4 -> V_97 + V_186 ) ;
return;
}
V_478 = F_53 ( V_4 -> V_97 + V_186 ) ;
V_478 &= ~ 0x8 ;
F_40 ( V_478 , V_4 -> V_97 + V_186 ) ;
if ( V_35 -> V_216 & V_481 ) {
F_40 ( 0xffffffff , V_4 -> V_97 + V_482 ) ;
F_40 ( 0xffffffff , V_4 -> V_97 + V_483 ) ;
return;
}
F_40 ( 0 , V_4 -> V_97 + V_482 ) ;
F_40 ( 0 , V_4 -> V_97 + V_483 ) ;
F_240 (ha, ndev) {
V_477 = 0xffffffff ;
for ( V_28 = 0 ; V_28 < V_35 -> V_484 ; V_28 ++ ) {
V_95 = V_475 -> V_61 [ V_28 ] ;
for ( V_476 = 0 ; V_476 < 8 ; V_476 ++ , V_95 >>= 1 ) {
V_477 = ( V_477 >> 1 ) ^
( ( ( V_477 ^ V_95 ) & 1 ) ? V_485 : 0 ) ;
}
}
V_479 = ( V_477 >> ( 32 - V_486 ) ) & 0x3f ;
if ( V_479 > 31 ) {
V_478 = F_53 ( V_4 -> V_97 + V_482 ) ;
V_478 |= 1 << ( V_479 - 32 ) ;
F_40 ( V_478 , V_4 -> V_97 + V_482 ) ;
} else {
V_478 = F_53 ( V_4 -> V_97 + V_483 ) ;
V_478 |= 1 << V_479 ;
F_40 ( V_478 , V_4 -> V_97 + V_483 ) ;
}
}
}
static int
F_241 ( struct V_34 * V_35 , void * V_81 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_487 * V_61 = V_81 ;
if ( V_61 ) {
if ( ! F_136 ( V_61 -> V_488 ) )
return - V_489 ;
memcpy ( V_35 -> V_137 , V_61 -> V_488 , V_35 -> V_484 ) ;
}
if ( ! F_84 ( V_35 ) )
return 0 ;
F_40 ( V_35 -> V_137 [ 3 ] | ( V_35 -> V_137 [ 2 ] << 8 ) |
( V_35 -> V_137 [ 1 ] << 16 ) | ( V_35 -> V_137 [ 0 ] << 24 ) ,
V_4 -> V_97 + V_140 ) ;
F_40 ( ( V_35 -> V_137 [ 5 ] << 16 ) | ( V_35 -> V_137 [ 4 ] << 24 ) ,
V_4 -> V_97 + V_141 ) ;
return 0 ;
}
static void F_242 ( struct V_34 * V_87 )
{
int V_28 ;
struct V_3 * V_4 = F_10 ( V_87 ) ;
for ( V_28 = 0 ; V_28 < V_490 ; V_28 ++ ) {
if ( V_4 -> V_295 [ V_28 ] > 0 ) {
F_243 ( V_4 -> V_295 [ V_28 ] ) ;
F_127 ( V_4 -> V_295 [ V_28 ] , V_87 ) ;
F_244 ( V_4 -> V_295 [ V_28 ] ) ;
}
}
}
static inline void F_245 ( struct V_34 * V_211 ,
T_13 V_273 )
{
struct V_3 * V_4 = F_10 ( V_211 ) ;
T_13 V_491 = V_273 ^ V_211 -> V_273 ;
V_211 -> V_273 = V_273 ;
if ( V_491 & V_492 ) {
if ( V_273 & V_492 )
V_4 -> V_151 |= V_152 ;
else
V_4 -> V_151 &= ~ V_152 ;
}
}
static int F_246 ( struct V_34 * V_211 ,
T_13 V_273 )
{
struct V_3 * V_4 = F_10 ( V_211 ) ;
T_13 V_491 = V_273 ^ V_211 -> V_273 ;
if ( F_84 ( V_211 ) && V_491 & V_492 ) {
F_85 ( & V_4 -> V_212 ) ;
F_86 ( V_211 ) ;
F_78 ( V_211 ) ;
F_245 ( V_211 , V_273 ) ;
F_70 ( V_211 ) ;
F_247 ( V_211 ) ;
F_88 ( V_211 ) ;
F_89 ( & V_4 -> V_212 ) ;
} else {
F_245 ( V_211 , V_273 ) ;
}
return 0 ;
}
static int F_248 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
struct V_1 * V_493 ;
T_2 V_125 ;
int V_494 ;
unsigned int V_28 ;
#if F_73 ( V_495 )
V_4 -> V_239 = 0xf ;
V_4 -> V_83 = 0xf ;
#else
V_4 -> V_239 = 0x3 ;
V_4 -> V_83 = 0x3 ;
#endif
F_224 ( V_35 ) ;
if ( V_4 -> V_7 )
V_4 -> V_22 = sizeof( struct V_7 ) ;
else
V_4 -> V_22 = sizeof( struct V_1 ) ;
V_494 = ( V_4 -> V_465 + V_4 -> V_468 ) *
V_4 -> V_22 ;
V_493 = F_249 ( & V_4 -> V_86 -> V_87 , V_494 , & V_125 ,
V_462 ) ;
if ( ! V_493 ) {
return - V_89 ;
}
memset ( V_493 , 0 , V_494 ) ;
F_134 ( V_35 ) ;
F_241 ( V_35 , NULL ) ;
for ( V_28 = 0 ; V_28 < V_4 -> V_120 ; V_28 ++ ) {
V_13 = V_4 -> V_14 [ V_28 ] ;
V_13 -> V_36 = V_28 ;
V_13 -> V_20 = (struct V_1 * ) V_493 ;
V_13 -> V_125 = V_125 ;
if ( V_4 -> V_7 ) {
V_125 += sizeof( struct V_7 ) * V_13 -> V_21 ;
V_493 = (struct V_1 * )
( ( (struct V_7 * ) V_493 ) + V_13 -> V_21 ) ;
} else {
V_125 += sizeof( struct V_1 ) * V_13 -> V_21 ;
V_493 += V_13 -> V_21 ;
}
}
for ( V_28 = 0 ; V_28 < V_4 -> V_124 ; V_28 ++ ) {
V_10 = V_4 -> V_11 [ V_28 ] ;
V_10 -> V_36 = V_28 ;
V_10 -> V_18 = (struct V_1 * ) V_493 ;
V_10 -> V_125 = V_125 ;
if ( V_4 -> V_7 ) {
V_125 += sizeof( struct V_7 ) * V_10 -> V_19 ;
V_493 = (struct V_1 * )
( ( (struct V_7 * ) V_493 ) + V_10 -> V_19 ) ;
} else {
V_125 += sizeof( struct V_1 ) * V_10 -> V_19 ;
V_493 += V_10 -> V_19 ;
}
}
V_35 -> V_496 = V_497 ;
V_35 -> V_498 = & V_499 ;
V_35 -> V_500 = & V_501 ;
F_40 ( V_502 , V_4 -> V_97 + V_193 ) ;
F_250 ( V_35 , & V_4 -> V_212 , F_132 , V_503 ) ;
if ( V_4 -> V_74 & V_504 )
V_35 -> V_273 |= V_274 ;
if ( V_4 -> V_74 & V_505 ) {
V_35 -> V_506 = V_507 ;
V_35 -> V_273 |= ( V_508 | V_509
| V_492 | V_510 | V_511 ) ;
V_4 -> V_151 |= V_152 ;
}
if ( V_4 -> V_74 & V_75 ) {
V_4 -> V_83 = 0 ;
V_4 -> V_239 = 0x3f ;
}
V_35 -> V_512 = V_35 -> V_273 ;
F_70 ( V_35 ) ;
return 0 ;
}
static void F_251 ( struct V_362 * V_86 )
{
int V_365 , V_513 ;
int V_514 = 1 ;
struct V_306 * V_307 = V_86 -> V_87 . V_308 ;
if ( ! V_307 )
return;
F_252 ( V_307 , L_26 , & V_514 ) ;
if ( V_514 > 1000 )
V_514 = 1 ;
V_513 = F_253 ( V_307 , L_27 , 0 ) ;
if ( ! F_254 ( V_513 ) )
return;
V_365 = F_255 ( & V_86 -> V_87 , V_513 ,
V_515 , L_28 ) ;
if ( V_365 ) {
F_169 ( & V_86 -> V_87 , L_29 , V_365 ) ;
return;
}
F_256 ( V_514 ) ;
F_257 ( V_513 , 1 ) ;
}
static void F_251 ( struct V_362 * V_86 )
{
}
static void
F_258 ( struct V_362 * V_86 , int * V_516 , int * V_517 )
{
struct V_306 * V_307 = V_86 -> V_87 . V_308 ;
* V_516 = * V_517 = 1 ;
if ( ! V_307 || ! F_259 ( V_307 ) )
return;
F_252 ( V_307 , L_30 , V_516 ) ;
F_252 ( V_307 , L_31 , V_517 ) ;
if ( * V_516 < 1 || * V_516 > V_518 ) {
F_260 ( & V_86 -> V_87 , L_32 ,
* V_516 ) ;
* V_516 = 1 ;
return;
}
if ( * V_517 < 1 || * V_517 > V_519 ) {
F_260 ( & V_86 -> V_87 , L_33 ,
* V_517 ) ;
* V_517 = 1 ;
return;
}
}
static int
F_261 ( struct V_362 * V_86 )
{
struct V_3 * V_4 ;
struct V_195 * V_196 ;
struct V_34 * V_35 ;
int V_28 , V_295 , V_111 = 0 ;
struct V_387 * V_388 ;
const struct V_520 * V_521 ;
static int V_296 ;
struct V_306 * V_307 = V_86 -> V_87 . V_308 , * V_350 ;
int V_522 ;
int V_523 ;
F_258 ( V_86 , & V_522 , & V_523 ) ;
V_35 = F_262 ( sizeof( struct V_3 ) ,
V_522 , V_523 ) ;
if ( ! V_35 )
return - V_89 ;
F_263 ( V_35 , & V_86 -> V_87 ) ;
V_4 = F_10 ( V_35 ) ;
V_521 = F_264 ( V_524 , & V_86 -> V_87 ) ;
if ( V_521 )
V_86 -> V_525 = V_521 -> V_95 ;
V_4 -> V_74 = V_86 -> V_525 -> V_526 ;
V_4 -> V_211 = V_35 ;
V_4 -> V_120 = V_523 ;
V_4 -> V_124 = V_522 ;
#if ! F_73 ( V_148 )
if ( V_4 -> V_74 & V_355 )
V_4 -> V_171 |= V_173 ;
#endif
F_232 ( & V_86 -> V_87 ) ;
V_388 = F_185 ( V_86 , V_390 , 0 ) ;
V_4 -> V_97 = F_265 ( & V_86 -> V_87 , V_388 ) ;
if ( F_37 ( V_4 -> V_97 ) ) {
V_111 = F_163 ( V_4 -> V_97 ) ;
goto V_527;
}
V_4 -> V_86 = V_86 ;
V_4 -> V_296 = V_296 ++ ;
F_266 ( V_86 , V_35 ) ;
if ( F_267 ( V_307 , L_34 , NULL ) )
V_4 -> V_200 |= V_454 ;
V_350 = F_268 ( V_307 , L_35 , 0 ) ;
if ( ! V_350 && F_269 ( V_307 ) ) {
V_111 = F_270 ( V_307 ) ;
if ( V_111 < 0 ) {
F_169 ( & V_86 -> V_87 ,
L_36 ) ;
goto V_528;
}
V_350 = F_271 ( V_307 ) ;
}
V_4 -> V_350 = V_350 ;
V_111 = F_272 ( V_86 -> V_87 . V_308 ) ;
if ( V_111 < 0 ) {
V_196 = F_135 ( & V_86 -> V_87 ) ;
if ( V_196 )
V_4 -> V_154 = V_196 -> V_529 ;
else
V_4 -> V_154 = V_530 ;
} else {
V_4 -> V_154 = V_111 ;
}
V_4 -> V_372 = F_273 ( & V_86 -> V_87 , L_37 ) ;
if ( F_37 ( V_4 -> V_372 ) ) {
V_111 = F_163 ( V_4 -> V_372 ) ;
goto V_531;
}
V_4 -> V_337 = F_273 ( & V_86 -> V_87 , L_38 ) ;
if ( F_37 ( V_4 -> V_337 ) ) {
V_111 = F_163 ( V_4 -> V_337 ) ;
goto V_531;
}
V_4 -> V_425 = F_168 ( V_4 -> V_337 ) ;
V_4 -> V_338 = F_273 ( & V_86 -> V_87 , L_39 ) ;
if ( F_37 ( V_4 -> V_338 ) )
V_4 -> V_338 = NULL ;
V_4 -> V_343 = false ;
F_274 ( & V_4 -> V_341 ) ;
V_4 -> V_344 = F_273 ( & V_86 -> V_87 , L_40 ) ;
if ( F_37 ( V_4 -> V_344 ) )
V_4 -> V_344 = NULL ;
V_4 -> V_7 = V_4 -> V_74 & V_532 ;
V_4 -> V_340 = F_273 ( & V_86 -> V_87 , L_41 ) ;
if ( F_37 ( V_4 -> V_340 ) ) {
V_4 -> V_340 = NULL ;
V_4 -> V_7 = false ;
}
V_111 = F_153 ( V_35 , true ) ;
if ( V_111 )
goto V_531;
V_111 = F_154 ( V_4 -> V_372 ) ;
if ( V_111 )
goto V_533;
V_4 -> V_534 = F_275 ( & V_86 -> V_87 , L_42 ) ;
if ( ! F_37 ( V_4 -> V_534 ) ) {
V_111 = F_276 ( V_4 -> V_534 ) ;
if ( V_111 ) {
F_169 ( & V_86 -> V_87 ,
L_43 , V_111 ) ;
goto V_535;
}
} else {
V_4 -> V_534 = NULL ;
}
F_277 ( & V_86 -> V_87 , V_536 ) ;
F_278 ( & V_86 -> V_87 ) ;
F_279 ( & V_86 -> V_87 ) ;
F_280 ( & V_86 -> V_87 ) ;
F_281 ( & V_86 -> V_87 ) ;
F_251 ( V_86 ) ;
if ( V_4 -> V_7 )
F_282 ( V_86 ) ;
V_111 = F_248 ( V_35 ) ;
if ( V_111 )
goto V_537;
for ( V_28 = 0 ; V_28 < V_490 ; V_28 ++ ) {
V_295 = F_283 ( V_86 , V_28 ) ;
if ( V_295 < 0 ) {
if ( V_28 )
break;
V_111 = V_295 ;
goto V_538;
}
V_111 = F_284 ( & V_86 -> V_87 , V_295 , F_127 ,
0 , V_86 -> V_375 , V_35 ) ;
if ( V_111 )
goto V_538;
V_4 -> V_295 [ V_28 ] = V_295 ;
}
F_285 ( & V_4 -> V_299 ) ;
V_111 = F_165 ( V_86 ) ;
if ( V_111 )
goto V_539;
F_286 ( V_35 ) ;
F_153 ( V_35 , false ) ;
F_235 ( & V_86 -> V_87 ) ;
V_111 = F_287 ( V_35 ) ;
if ( V_111 )
goto V_540;
F_288 ( & V_35 -> V_87 , V_4 -> V_200 &
V_454 ) ;
if ( V_4 -> V_7 && V_4 -> V_300 )
F_11 ( V_35 , L_44 , V_4 -> V_296 ) ;
V_4 -> V_245 = V_541 ;
F_289 ( & V_4 -> V_208 , F_81 ) ;
F_150 ( & V_86 -> V_87 ) ;
F_151 ( & V_86 -> V_87 ) ;
return 0 ;
V_540:
F_176 ( V_4 ) ;
V_539:
V_538:
V_537:
F_290 ( V_86 ) ;
if ( V_4 -> V_534 )
F_291 ( V_4 -> V_534 ) ;
V_535:
F_157 ( V_4 -> V_372 ) ;
V_533:
F_153 ( V_35 , false ) ;
V_531:
V_528:
F_173 ( V_350 ) ;
V_527:
F_292 ( V_35 ) ;
return V_111 ;
}
static int
F_293 ( struct V_362 * V_86 )
{
struct V_34 * V_35 = F_166 ( V_86 ) ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_294 ( & V_4 -> V_208 ) ;
F_290 ( V_86 ) ;
F_295 ( V_35 ) ;
F_176 ( V_4 ) ;
if ( V_4 -> V_534 )
F_291 ( V_4 -> V_534 ) ;
F_173 ( V_4 -> V_350 ) ;
F_292 ( V_35 ) ;
return 0 ;
}
static int T_14 F_296 ( struct V_325 * V_87 )
{
struct V_34 * V_35 = F_297 ( V_87 ) ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_82 () ;
if ( F_84 ( V_35 ) ) {
if ( V_4 -> V_200 & V_457 )
V_4 -> V_200 |= V_201 ;
F_237 ( V_4 -> V_160 ) ;
F_85 ( & V_4 -> V_212 ) ;
F_86 ( V_35 ) ;
F_298 ( V_35 ) ;
F_88 ( V_35 ) ;
F_78 ( V_35 ) ;
F_153 ( V_35 , false ) ;
if ( ! ( V_4 -> V_200 & V_457 ) )
F_235 ( & V_4 -> V_86 -> V_87 ) ;
}
F_90 () ;
if ( V_4 -> V_534 && ! ( V_4 -> V_200 & V_457 ) )
F_291 ( V_4 -> V_534 ) ;
if ( V_4 -> V_338 || V_4 -> V_534 )
V_4 -> V_191 = 0 ;
return 0 ;
}
static int T_14 F_299 ( struct V_325 * V_87 )
{
struct V_34 * V_35 = F_297 ( V_87 ) ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
struct V_195 * V_196 = V_4 -> V_86 -> V_87 . V_197 ;
int V_111 ;
int V_130 ;
if ( V_4 -> V_534 && ! ( V_4 -> V_200 & V_457 ) ) {
V_111 = F_276 ( V_4 -> V_534 ) ;
if ( V_111 )
return V_111 ;
}
F_82 () ;
if ( F_84 ( V_35 ) ) {
V_111 = F_153 ( V_35 , true ) ;
if ( V_111 ) {
F_90 () ;
goto V_531;
}
if ( V_4 -> V_200 & V_457 ) {
if ( V_196 && V_196 -> V_205 )
V_196 -> V_205 ( false ) ;
V_130 = F_53 ( V_4 -> V_97 + V_135 ) ;
V_130 &= ~ ( V_203 | V_204 ) ;
F_40 ( V_130 , V_4 -> V_97 + V_135 ) ;
V_4 -> V_200 &= ~ V_201 ;
} else {
F_232 ( & V_4 -> V_86 -> V_87 ) ;
}
F_70 ( V_35 ) ;
F_86 ( V_35 ) ;
F_300 ( V_35 ) ;
F_88 ( V_35 ) ;
F_89 ( & V_4 -> V_212 ) ;
F_233 ( V_4 -> V_160 ) ;
}
F_90 () ;
return 0 ;
V_531:
if ( V_4 -> V_534 )
F_291 ( V_4 -> V_534 ) ;
return V_111 ;
}
static int T_14 F_301 ( struct V_325 * V_87 )
{
struct V_34 * V_35 = F_297 ( V_87 ) ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
F_157 ( V_4 -> V_372 ) ;
return 0 ;
}
static int T_14 F_302 ( struct V_325 * V_87 )
{
struct V_34 * V_35 = F_297 ( V_87 ) ;
struct V_3 * V_4 = F_10 ( V_35 ) ;
return F_154 ( V_4 -> V_372 ) ;
}
