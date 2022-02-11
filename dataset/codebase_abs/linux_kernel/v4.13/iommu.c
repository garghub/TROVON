static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = F_2 ( V_1 , struct V_2 , V_3 ) ;
if ( V_2 -> V_4 ) {
F_3 ( V_2 -> V_4 , ~ ( V_5 ) 0 ) ;
} else {
unsigned long V_6 ;
int V_7 ;
V_6 = V_2 -> V_8 ;
for ( V_7 = 0 ; V_7 < 16 ; V_7 ++ ) {
F_3 ( V_6 , 0 ) ;
V_6 += 8 ;
}
( void ) F_4 ( V_2 -> V_9 ) ;
}
}
static inline void F_5 ( struct V_2 * V_2 , T_1 * V_10 )
{
unsigned long V_11 = F_6 ( * V_10 ) ;
V_11 &= ~ V_12 ;
V_11 |= V_2 -> V_13 ;
F_6 ( * V_10 ) = V_11 ;
}
int F_7 ( struct V_2 * V_2 , int V_14 ,
T_2 V_15 , T_2 V_16 ,
int V_17 )
{
unsigned long V_18 , V_19 , V_20 , V_21 ;
struct V_22 * V_22 ;
V_21 = V_14 / sizeof( T_1 ) ;
F_8 ( & V_2 -> V_23 ) ;
V_2 -> V_24 = 1 ;
V_2 -> V_3 . V_25 = V_15 ;
V_2 -> V_16 = V_16 ;
V_20 = V_21 / 8 ;
V_20 = ( V_20 + 7UL ) & ~ 7UL ;
V_2 -> V_3 . V_26 = F_9 ( V_20 , V_27 , V_17 ) ;
if ( ! V_2 -> V_3 . V_26 )
return - V_28 ;
memset ( V_2 -> V_3 . V_26 , 0 , V_20 ) ;
F_10 ( & V_2 -> V_3 , V_21 , V_29 ,
( V_30 != V_31 ? F_1 : NULL ) ,
false , 1 , false ) ;
V_22 = F_11 ( V_17 , V_27 , 0 ) ;
if ( ! V_22 ) {
F_12 ( V_32 L_1 ) ;
goto V_33;
}
V_2 -> V_34 = ( unsigned long ) F_13 ( V_22 ) ;
memset ( ( void * ) V_2 -> V_34 , 0 , V_35 ) ;
V_2 -> V_13 = ( unsigned long ) F_14 ( V_2 -> V_34 ) ;
V_19 = F_15 ( V_14 ) ;
V_22 = F_11 ( V_17 , V_27 , V_19 ) ;
if ( ! V_22 ) {
F_12 ( V_32 L_2 ) ;
goto V_36;
}
V_2 -> V_37 = ( T_1 * ) F_13 ( V_22 ) ;
for ( V_18 = 0 ; V_18 < V_21 ; V_18 ++ )
F_5 ( V_2 , & V_2 -> V_37 [ V_18 ] ) ;
return 0 ;
V_36:
F_16 ( V_2 -> V_34 ) ;
V_2 -> V_34 = 0UL ;
V_33:
F_17 ( V_2 -> V_3 . V_26 ) ;
V_2 -> V_3 . V_26 = NULL ;
return - V_28 ;
}
static inline T_1 * F_18 ( struct V_38 * V_39 ,
struct V_2 * V_2 ,
unsigned long V_40 )
{
unsigned long V_7 ;
V_7 = F_19 ( V_39 , & V_2 -> V_3 , V_40 , NULL ,
( unsigned long ) ( - 1 ) , 0 ) ;
if ( F_20 ( V_7 == V_41 ) )
return NULL ;
return V_2 -> V_37 + V_7 ;
}
static int F_21 ( struct V_2 * V_2 )
{
int V_42 = V_2 -> V_24 ;
int V_43 = F_22 ( V_2 -> V_44 , V_45 , V_42 ) ;
if ( F_20 ( V_43 == V_45 ) ) {
V_43 = F_22 ( V_2 -> V_44 , V_42 , 1 ) ;
if ( F_20 ( V_43 == V_42 ) ) {
F_12 ( V_46 L_3 ) ;
V_43 = 0 ;
}
}
if ( V_43 )
F_23 ( V_43 , V_2 -> V_44 ) ;
return V_43 ;
}
static inline void F_24 ( struct V_2 * V_2 , int V_47 )
{
if ( F_25 ( V_47 ) ) {
F_26 ( V_47 , V_2 -> V_44 ) ;
if ( V_47 < V_2 -> V_24 )
V_2 -> V_24 = V_47 ;
}
}
static void * F_27 ( struct V_38 * V_39 , T_3 V_48 ,
T_4 * V_49 , T_5 V_50 ,
unsigned long V_51 )
{
unsigned long V_19 , V_52 ;
struct V_2 * V_2 ;
struct V_22 * V_22 ;
int V_40 , V_53 ;
T_1 * V_10 ;
void * V_54 ;
V_48 = F_28 ( V_48 ) ;
V_19 = F_15 ( V_48 ) ;
if ( V_19 >= 10 )
return NULL ;
V_53 = V_39 -> V_55 . V_17 ;
V_22 = F_11 ( V_53 , V_50 , V_19 ) ;
if ( F_20 ( ! V_22 ) )
return NULL ;
V_52 = ( unsigned long ) F_13 ( V_22 ) ;
memset ( ( char * ) V_52 , 0 , V_35 << V_19 ) ;
V_2 = V_39 -> V_55 . V_2 ;
V_10 = F_18 ( V_39 , V_2 , V_48 >> V_29 ) ;
if ( F_20 ( V_10 == NULL ) ) {
F_29 ( V_52 , V_19 ) ;
return NULL ;
}
* V_49 = ( V_2 -> V_3 . V_25 +
( ( V_10 - V_2 -> V_37 ) << V_29 ) ) ;
V_54 = ( void * ) V_52 ;
V_40 = V_48 >> V_29 ;
V_52 = F_14 ( V_52 ) ;
while ( V_40 -- ) {
F_6 ( * V_10 ) = ( F_30 ( 0UL ) |
V_56 |
( V_52 & V_12 ) ) ;
V_10 ++ ;
V_52 += V_57 ;
}
return V_54 ;
}
static void F_31 ( struct V_38 * V_39 , T_3 V_48 ,
void * V_58 , T_4 V_59 ,
unsigned long V_51 )
{
struct V_2 * V_2 ;
unsigned long V_19 , V_40 ;
V_40 = F_28 ( V_48 ) >> V_29 ;
V_2 = V_39 -> V_55 . V_2 ;
F_32 ( & V_2 -> V_3 , V_59 , V_40 , V_41 ) ;
V_19 = F_15 ( V_48 ) ;
if ( V_19 < 10 )
F_29 ( ( unsigned long ) V_58 , V_19 ) ;
}
static T_4 F_33 ( struct V_38 * V_39 , struct V_22 * V_22 ,
unsigned long V_60 , T_3 V_20 ,
enum V_61 V_62 ,
unsigned long V_51 )
{
struct V_2 * V_2 ;
struct V_63 * V_63 ;
T_1 * V_64 ;
unsigned long V_65 , V_40 , V_66 ;
unsigned long V_18 , V_67 , V_47 ;
T_2 V_68 , V_54 ;
unsigned long V_69 ;
V_2 = V_39 -> V_55 . V_2 ;
V_63 = V_39 -> V_55 . V_70 ;
if ( F_20 ( V_62 == V_71 ) )
goto V_72;
V_66 = ( unsigned long ) ( F_13 ( V_22 ) + V_60 ) ;
V_40 = F_28 ( V_66 + V_20 ) - ( V_66 & V_73 ) ;
V_40 >>= V_29 ;
V_64 = F_18 ( V_39 , V_2 , V_40 ) ;
F_34 ( & V_2 -> V_23 , V_65 ) ;
V_47 = 0 ;
if ( V_2 -> V_74 )
V_47 = F_21 ( V_2 ) ;
F_35 ( & V_2 -> V_23 , V_65 ) ;
if ( F_20 ( ! V_64 ) )
goto V_75;
V_68 = ( V_2 -> V_3 . V_25 +
( ( V_64 - V_2 -> V_37 ) << V_29 ) ) ;
V_54 = V_68 | ( V_66 & ~ V_73 ) ;
V_67 = F_14 ( V_66 & V_73 ) ;
if ( V_63 -> V_76 )
V_69 = F_36 ( V_47 ) ;
else
V_69 = F_30 ( V_47 ) ;
if ( V_62 != V_77 )
V_69 |= V_56 ;
for ( V_18 = 0 ; V_18 < V_40 ; V_18 ++ , V_64 ++ , V_67 += V_57 )
F_6 ( * V_64 ) = V_69 | V_67 ;
return V_54 ;
V_75:
F_24 ( V_2 , V_47 ) ;
V_72:
if ( F_37 () )
F_38 ( 1 ) ;
return V_78 ;
}
static void F_39 ( struct V_63 * V_63 , struct V_2 * V_2 ,
T_2 V_79 , unsigned long V_47 , unsigned long V_40 ,
enum V_61 V_62 )
{
int V_80 ;
if ( V_63 -> V_81 &&
V_2 -> V_74 ) {
unsigned long V_82 , V_83 ;
V_5 V_11 ;
V_83 = V_63 -> V_81 ;
V_82 = F_40 ( V_63 , V_47 ) ;
F_3 ( V_83 , V_47 ) ;
V_11 = F_4 ( V_82 ) ;
V_11 &= 0xffff ;
if ( ! V_11 )
goto V_84;
while ( V_11 ) {
if ( V_11 & 0x1 )
F_3 ( V_83 , V_47 ) ;
V_11 >>= 1 ;
}
V_11 = F_4 ( V_82 ) ;
if ( F_20 ( V_11 ) ) {
F_12 ( V_46 L_4
L_5 ,
V_11 , V_47 ) ;
goto V_85;
}
} else {
unsigned long V_18 ;
V_85:
for ( V_18 = 0 ; V_18 < V_40 ; V_18 ++ , V_79 += V_57 )
F_3 ( V_63 -> V_86 , V_79 ) ;
}
V_84:
if ( V_62 == V_77 )
return;
F_41 ( V_63 ) ;
F_3 ( V_63 -> V_87 , V_63 -> V_88 ) ;
( void ) F_4 ( V_2 -> V_9 ) ;
V_80 = 100000 ;
while ( ! F_42 ( V_63 ) ) {
V_80 -- ;
if ( ! V_80 )
break;
F_43 ( 1 ) ;
F_44 () ;
}
if ( ! V_80 )
F_12 ( V_46 L_6
L_7 ,
V_79 , V_47 , V_40 ) ;
}
static void F_45 ( struct V_38 * V_39 , T_4 V_68 ,
T_3 V_20 , enum V_61 V_62 ,
unsigned long V_51 )
{
struct V_2 * V_2 ;
struct V_63 * V_63 ;
T_1 * V_64 ;
unsigned long V_65 , V_40 , V_47 , V_18 ;
if ( F_20 ( V_62 == V_71 ) ) {
if ( F_37 () )
F_38 ( 1 ) ;
return;
}
V_2 = V_39 -> V_55 . V_2 ;
V_63 = V_39 -> V_55 . V_70 ;
V_40 = F_28 ( V_68 + V_20 ) - ( V_68 & V_73 ) ;
V_40 >>= V_29 ;
V_64 = V_2 -> V_37 +
( ( V_68 - V_2 -> V_3 . V_25 ) >> V_29 ) ;
V_68 &= V_73 ;
F_34 ( & V_2 -> V_23 , V_65 ) ;
V_47 = 0 ;
if ( V_2 -> V_74 )
V_47 = ( F_6 ( * V_64 ) & V_89 ) >> 47UL ;
if ( V_63 -> V_76 && ! ( V_51 & V_90 ) )
F_39 ( V_63 , V_2 , V_68 , V_47 ,
V_40 , V_62 ) ;
for ( V_18 = 0 ; V_18 < V_40 ; V_18 ++ )
F_5 ( V_2 , V_64 + V_18 ) ;
F_24 ( V_2 , V_47 ) ;
F_35 ( & V_2 -> V_23 , V_65 ) ;
F_32 ( & V_2 -> V_3 , V_68 , V_40 , V_41 ) ;
}
static int F_46 ( struct V_38 * V_39 , struct V_91 * V_92 ,
int V_93 , enum V_61 V_62 ,
unsigned long V_51 )
{
struct V_91 * V_94 , * V_95 , * V_96 ;
unsigned long V_65 , V_97 , V_98 , V_47 ;
T_4 V_99 = 0 , V_100 ;
unsigned int V_101 ;
unsigned long V_102 ;
int V_103 , V_104 , V_18 ;
struct V_63 * V_63 ;
struct V_2 * V_2 ;
unsigned long V_105 ;
F_47 ( V_62 == V_71 ) ;
V_2 = V_39 -> V_55 . V_2 ;
V_63 = V_39 -> V_55 . V_70 ;
if ( V_93 == 0 || ! V_2 )
return 0 ;
F_34 ( & V_2 -> V_23 , V_65 ) ;
V_47 = 0 ;
if ( V_2 -> V_74 )
V_47 = F_21 ( V_2 ) ;
if ( V_63 -> V_76 )
V_98 = F_36 ( V_47 ) ;
else
V_98 = F_30 ( V_47 ) ;
if ( V_62 != V_77 )
V_98 |= V_56 ;
V_95 = V_94 = V_96 = & V_92 [ 0 ] ;
V_103 = 1 ;
V_104 = V_93 ;
V_97 = 0 ;
V_95 -> V_106 = 0 ;
V_101 = F_48 ( V_39 ) ;
V_102 = F_49 ( F_50 ( V_39 ) + 1 ,
V_57 ) >> V_29 ;
V_105 = V_2 -> V_3 . V_25 >> V_29 ;
F_51 (sglist, s, nelems, i) {
unsigned long V_107 , V_40 , V_7 , V_108 = 0 , V_109 ;
T_1 * V_64 ;
V_109 = V_94 -> V_110 ;
if ( V_109 == 0 ) {
V_99 = 0 ;
continue;
}
V_107 = ( unsigned long ) F_52 ( V_94 ) ;
V_40 = F_53 ( V_107 , V_109 , V_57 ) ;
V_7 = F_19 ( V_39 , & V_2 -> V_3 , V_40 ,
& V_97 , ( unsigned long ) ( - 1 ) , 0 ) ;
if ( F_20 ( V_7 == V_41 ) ) {
if ( F_37 () )
F_12 ( V_111 L_8
L_9 , V_2 , V_107 , V_40 ) ;
goto V_112;
}
V_64 = V_2 -> V_37 + V_7 ;
V_100 = V_2 -> V_3 . V_25 +
( V_7 << V_29 ) ;
V_100 |= ( V_94 -> V_60 & ~ V_73 ) ;
V_107 &= V_73 ;
while ( V_40 -- ) {
F_6 ( * V_64 ) = V_98 | V_107 ;
V_64 ++ ;
V_107 += V_57 ;
}
if ( V_96 != V_94 ) {
if ( ( V_100 != V_99 ) ||
( V_95 -> V_106 + V_94 -> V_110 > V_101 ) ||
( F_54 ( V_108 , V_105 ,
V_102 , V_95 , V_94 ) ) ) {
V_96 = V_94 ;
V_103 ++ ;
V_95 = F_55 ( V_95 ) ;
} else {
V_95 -> V_106 += V_94 -> V_110 ;
}
}
if ( V_96 == V_94 ) {
V_95 -> V_113 = V_100 ;
V_95 -> V_106 = V_109 ;
V_108 = V_7 ;
}
V_99 = V_100 + V_109 ;
}
F_35 ( & V_2 -> V_23 , V_65 ) ;
if ( V_103 < V_104 ) {
V_95 = F_55 ( V_95 ) ;
V_95 -> V_113 = V_78 ;
V_95 -> V_106 = 0 ;
}
return V_103 ;
V_112:
F_51 (sglist, s, nelems, i) {
if ( V_94 -> V_106 != 0 ) {
unsigned long V_79 , V_40 , V_7 , V_114 ;
T_1 * V_64 ;
V_79 = V_94 -> V_113 & V_73 ;
V_40 = F_53 ( V_94 -> V_113 , V_94 -> V_106 ,
V_57 ) ;
V_7 = ( V_79 - V_2 -> V_3 . V_25 )
>> V_29 ;
V_64 = V_2 -> V_37 + V_7 ;
for ( V_114 = 0 ; V_114 < V_40 ; V_114 ++ )
F_5 ( V_2 , V_64 + V_114 ) ;
F_32 ( & V_2 -> V_3 , V_79 , V_40 ,
V_41 ) ;
V_94 -> V_113 = V_78 ;
V_94 -> V_106 = 0 ;
}
if ( V_94 == V_95 )
break;
}
F_35 ( & V_2 -> V_23 , V_65 ) ;
return 0 ;
}
static unsigned long F_56 ( struct V_2 * V_2 , struct V_91 * V_115 )
{
unsigned long V_47 = 0 ;
if ( V_2 -> V_74 ) {
T_1 * V_64 ;
T_2 V_68 ;
struct V_1 * V_3 = & V_2 -> V_3 ;
V_68 = V_115 -> V_113 & V_73 ;
V_64 = V_2 -> V_37 +
( ( V_68 - V_3 -> V_25 ) >> V_29 ) ;
V_47 = ( F_6 ( * V_64 ) & V_89 ) >> 47UL ;
}
return V_47 ;
}
static void F_57 ( struct V_38 * V_39 , struct V_91 * V_92 ,
int V_93 , enum V_61 V_62 ,
unsigned long V_51 )
{
unsigned long V_65 , V_47 ;
struct V_91 * V_115 ;
struct V_63 * V_63 ;
struct V_2 * V_2 ;
F_47 ( V_62 == V_71 ) ;
V_2 = V_39 -> V_55 . V_2 ;
V_63 = V_39 -> V_55 . V_70 ;
V_47 = F_56 ( V_2 , V_92 ) ;
F_34 ( & V_2 -> V_23 , V_65 ) ;
V_115 = V_92 ;
while ( V_93 -- ) {
T_4 V_116 = V_115 -> V_113 ;
unsigned int V_117 = V_115 -> V_106 ;
unsigned long V_40 , V_7 ;
T_1 * V_64 ;
int V_18 ;
if ( ! V_117 )
break;
V_40 = F_53 ( V_116 , V_117 , V_57 ) ;
V_7 = ( ( V_116 - V_2 -> V_3 . V_25 )
>> V_29 ) ;
V_64 = V_2 -> V_37 + V_7 ;
V_116 &= V_73 ;
if ( V_63 -> V_76 && ! ( V_51 & V_90 ) )
F_39 ( V_63 , V_2 , V_116 , V_47 ,
V_40 , V_62 ) ;
for ( V_18 = 0 ; V_18 < V_40 ; V_18 ++ )
F_5 ( V_2 , V_64 + V_18 ) ;
F_32 ( & V_2 -> V_3 , V_116 , V_40 ,
V_41 ) ;
V_115 = F_55 ( V_115 ) ;
}
F_24 ( V_2 , V_47 ) ;
F_35 ( & V_2 -> V_23 , V_65 ) ;
}
static void F_58 ( struct V_38 * V_39 ,
T_4 V_68 , T_3 V_20 ,
enum V_61 V_62 )
{
struct V_2 * V_2 ;
struct V_63 * V_63 ;
unsigned long V_65 , V_47 , V_40 ;
V_2 = V_39 -> V_55 . V_2 ;
V_63 = V_39 -> V_55 . V_70 ;
if ( ! V_63 -> V_76 )
return;
F_34 ( & V_2 -> V_23 , V_65 ) ;
V_40 = F_28 ( V_68 + V_20 ) - ( V_68 & V_73 ) ;
V_40 >>= V_29 ;
V_68 &= V_73 ;
V_47 = 0 ;
if ( V_2 -> V_74 &&
V_63 -> V_81 ) {
T_1 * V_10 ;
struct V_1 * V_3 = & V_2 -> V_3 ;
V_10 = V_2 -> V_37 +
( ( V_68 - V_3 -> V_25 ) >> V_29 ) ;
V_47 = ( F_6 ( * V_10 ) & V_89 ) >> 47UL ;
}
F_39 ( V_63 , V_2 , V_68 , V_47 , V_40 , V_62 ) ;
F_35 ( & V_2 -> V_23 , V_65 ) ;
}
static void F_59 ( struct V_38 * V_39 ,
struct V_91 * V_92 , int V_93 ,
enum V_61 V_62 )
{
struct V_2 * V_2 ;
struct V_63 * V_63 ;
unsigned long V_65 , V_47 , V_40 , V_18 ;
struct V_91 * V_115 , * V_118 ;
T_2 V_68 ;
V_2 = V_39 -> V_55 . V_2 ;
V_63 = V_39 -> V_55 . V_70 ;
if ( ! V_63 -> V_76 )
return;
F_34 ( & V_2 -> V_23 , V_65 ) ;
V_47 = 0 ;
if ( V_2 -> V_74 &&
V_63 -> V_81 ) {
T_1 * V_10 ;
struct V_1 * V_3 = & V_2 -> V_3 ;
V_10 = V_2 -> V_37 + ( ( V_92 [ 0 ] . V_113 -
V_3 -> V_25 ) >> V_29 ) ;
V_47 = ( F_6 ( * V_10 ) & V_89 ) >> 47UL ;
}
V_68 = V_92 [ 0 ] . V_113 & V_73 ;
V_118 = NULL ;
F_51 (sglist, sg, nelems, i) {
if ( V_115 -> V_106 == 0 )
break;
V_118 = V_115 ;
}
V_40 = ( F_28 ( V_118 -> V_113 + V_118 -> V_106 )
- V_68 ) >> V_29 ;
F_39 ( V_63 , V_2 , V_68 , V_47 , V_40 , V_62 ) ;
F_35 ( & V_2 -> V_23 , V_65 ) ;
}
static int F_60 ( struct V_38 * V_39 , T_4 V_100 )
{
return V_100 == V_78 ;
}
static int F_61 ( struct V_38 * V_39 , V_5 V_119 )
{
struct V_2 * V_2 = V_39 -> V_55 . V_2 ;
if ( V_119 > F_62 ( 32 ) )
return 0 ;
if ( ( V_119 & V_2 -> V_16 ) == V_2 -> V_16 )
return 1 ;
#ifdef F_63
if ( F_64 ( V_39 ) )
return F_65 ( F_66 ( V_39 ) , V_119 ) ;
#endif
return 0 ;
}
