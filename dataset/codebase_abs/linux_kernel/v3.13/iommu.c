static void F_1 ( struct V_1 * V_1 )
{
if ( V_1 -> V_2 ) {
F_2 ( V_1 -> V_2 , ~ ( V_3 ) 0 ) ;
} else {
unsigned long V_4 ;
int V_5 ;
V_4 = V_1 -> V_6 ;
for ( V_5 = 0 ; V_5 < 16 ; V_5 ++ ) {
F_2 ( V_4 , 0 ) ;
V_4 += 8 ;
}
( void ) F_3 ( V_1 -> V_7 ) ;
}
}
static inline void F_4 ( struct V_1 * V_1 , T_1 * V_8 )
{
unsigned long V_9 = F_5 ( * V_8 ) ;
V_9 &= ~ V_10 ;
V_9 |= V_1 -> V_11 ;
F_5 ( * V_8 ) = V_9 ;
}
unsigned long F_6 ( struct V_12 * V_13 ,
struct V_1 * V_1 ,
unsigned long V_14 ,
unsigned long * V_15 )
{
unsigned long V_16 , V_17 , V_18 , V_19 , V_20 ;
struct V_21 * V_22 = & V_1 -> V_22 ;
int V_23 = 0 ;
if ( F_7 ( V_14 == 0 ) ) {
if ( F_8 () )
F_9 ( 1 ) ;
return V_24 ;
}
if ( V_15 && * V_15 )
V_18 = * V_15 ;
else
V_18 = V_22 -> V_25 ;
V_19 = V_22 -> V_19 ;
if ( V_18 >= V_19 ) {
V_18 = 0 ;
if ( V_1 -> V_26 )
V_1 -> V_26 ( V_1 ) ;
}
V_27:
if ( V_13 )
V_20 = F_10 ( F_11 ( V_13 ) + 1 ,
1 << V_28 ) ;
else
V_20 = F_10 ( 1UL << 32 , 1 << V_28 ) ;
V_16 = F_12 ( V_22 -> V_29 , V_19 , V_18 , V_14 ,
V_1 -> V_30 >> V_28 ,
V_20 >> V_28 , 0 ) ;
if ( V_16 == - 1 ) {
if ( F_13 ( V_23 < 1 ) ) {
V_18 = 0 ;
if ( V_1 -> V_26 )
V_1 -> V_26 ( V_1 ) ;
V_23 ++ ;
goto V_27;
} else {
return V_24 ;
}
}
V_17 = V_16 + V_14 ;
V_22 -> V_25 = V_17 ;
if ( V_15 )
* V_15 = V_17 ;
return V_16 ;
}
void F_14 ( struct V_1 * V_1 , T_2 V_31 , unsigned long V_14 )
{
struct V_21 * V_22 = & V_1 -> V_22 ;
unsigned long V_5 ;
V_5 = ( V_31 - V_1 -> V_30 ) >> V_28 ;
F_15 ( V_22 -> V_29 , V_5 , V_14 ) ;
}
int F_16 ( struct V_1 * V_1 , int V_32 ,
T_3 V_33 , T_3 V_34 ,
int V_35 )
{
unsigned long V_36 , V_37 , V_38 , V_39 ;
struct V_40 * V_40 ;
V_39 = V_32 / sizeof( T_1 ) ;
F_17 ( & V_1 -> V_41 ) ;
V_1 -> V_42 = 1 ;
V_1 -> V_30 = V_33 ;
V_1 -> V_34 = V_34 ;
V_38 = V_39 / 8 ;
V_38 = ( V_38 + 7UL ) & ~ 7UL ;
V_1 -> V_22 . V_29 = F_18 ( V_38 , V_43 , V_35 ) ;
if ( ! V_1 -> V_22 . V_29 ) {
F_19 ( V_44 L_1 ) ;
return - V_45 ;
}
memset ( V_1 -> V_22 . V_29 , 0 , V_38 ) ;
V_1 -> V_22 . V_19 = V_39 ;
if ( V_46 != V_47 )
V_1 -> V_26 = F_1 ;
V_40 = F_20 ( V_35 , V_43 , 0 ) ;
if ( ! V_40 ) {
F_19 ( V_44 L_2 ) ;
goto V_48;
}
V_1 -> V_49 = ( unsigned long ) F_21 ( V_40 ) ;
memset ( ( void * ) V_1 -> V_49 , 0 , V_50 ) ;
V_1 -> V_11 = ( unsigned long ) F_22 ( V_1 -> V_49 ) ;
V_37 = F_23 ( V_32 ) ;
V_40 = F_20 ( V_35 , V_43 , V_37 ) ;
if ( ! V_40 ) {
F_19 ( V_44 L_3 ) ;
goto V_51;
}
V_1 -> V_52 = ( T_1 * ) F_21 ( V_40 ) ;
for ( V_36 = 0 ; V_36 < V_39 ; V_36 ++ )
F_4 ( V_1 , & V_1 -> V_52 [ V_36 ] ) ;
return 0 ;
V_51:
F_24 ( V_1 -> V_49 ) ;
V_1 -> V_49 = 0UL ;
V_48:
F_25 ( V_1 -> V_22 . V_29 ) ;
V_1 -> V_22 . V_29 = NULL ;
return - V_45 ;
}
static inline T_1 * F_26 ( struct V_12 * V_13 , struct V_1 * V_1 ,
unsigned long V_14 )
{
unsigned long V_5 ;
V_5 = F_6 ( V_13 , V_1 , V_14 , NULL ) ;
if ( F_7 ( V_5 == V_24 ) )
return NULL ;
return V_1 -> V_52 + V_5 ;
}
static int F_27 ( struct V_1 * V_1 )
{
int V_53 = V_1 -> V_42 ;
int V_16 = F_28 ( V_1 -> V_54 , V_55 , V_53 ) ;
if ( F_7 ( V_16 == V_55 ) ) {
V_16 = F_28 ( V_1 -> V_54 , V_53 , 1 ) ;
if ( F_7 ( V_16 == V_53 ) ) {
F_19 ( V_56 L_4 ) ;
V_16 = 0 ;
}
}
if ( V_16 )
F_29 ( V_16 , V_1 -> V_54 ) ;
return V_16 ;
}
static inline void F_30 ( struct V_1 * V_1 , int V_57 )
{
if ( F_13 ( V_57 ) ) {
F_31 ( V_57 , V_1 -> V_54 ) ;
if ( V_57 < V_1 -> V_42 )
V_1 -> V_42 = V_57 ;
}
}
static void * F_32 ( struct V_12 * V_13 , T_4 V_58 ,
T_2 * V_59 , T_5 V_60 ,
struct V_61 * V_62 )
{
unsigned long V_63 , V_37 , V_64 ;
struct V_1 * V_1 ;
struct V_40 * V_40 ;
int V_14 , V_65 ;
T_1 * V_8 ;
void * V_66 ;
V_58 = F_33 ( V_58 ) ;
V_37 = F_23 ( V_58 ) ;
if ( V_37 >= 10 )
return NULL ;
V_65 = V_13 -> V_67 . V_35 ;
V_40 = F_20 ( V_65 , V_60 , V_37 ) ;
if ( F_7 ( ! V_40 ) )
return NULL ;
V_64 = ( unsigned long ) F_21 ( V_40 ) ;
memset ( ( char * ) V_64 , 0 , V_50 << V_37 ) ;
V_1 = V_13 -> V_67 . V_1 ;
F_34 ( & V_1 -> V_41 , V_63 ) ;
V_8 = F_26 ( V_13 , V_1 , V_58 >> V_28 ) ;
F_35 ( & V_1 -> V_41 , V_63 ) ;
if ( F_7 ( V_8 == NULL ) ) {
F_36 ( V_64 , V_37 ) ;
return NULL ;
}
* V_59 = ( V_1 -> V_30 +
( ( V_8 - V_1 -> V_52 ) << V_28 ) ) ;
V_66 = ( void * ) V_64 ;
V_14 = V_58 >> V_28 ;
V_64 = F_22 ( V_64 ) ;
while ( V_14 -- ) {
F_5 ( * V_8 ) = ( F_37 ( 0UL ) |
V_68 |
( V_64 & V_10 ) ) ;
V_8 ++ ;
V_64 += V_69 ;
}
return V_66 ;
}
static void F_38 ( struct V_12 * V_13 , T_4 V_58 ,
void * V_70 , T_2 V_71 ,
struct V_61 * V_62 )
{
struct V_1 * V_1 ;
unsigned long V_63 , V_37 , V_14 ;
V_14 = F_33 ( V_58 ) >> V_28 ;
V_1 = V_13 -> V_67 . V_1 ;
F_34 ( & V_1 -> V_41 , V_63 ) ;
F_14 ( V_1 , V_71 , V_14 ) ;
F_35 ( & V_1 -> V_41 , V_63 ) ;
V_37 = F_23 ( V_58 ) ;
if ( V_37 < 10 )
F_36 ( ( unsigned long ) V_70 , V_37 ) ;
}
static T_2 F_39 ( struct V_12 * V_13 , struct V_40 * V_40 ,
unsigned long V_72 , T_4 V_38 ,
enum V_73 V_74 ,
struct V_61 * V_62 )
{
struct V_1 * V_1 ;
struct V_75 * V_75 ;
T_1 * V_76 ;
unsigned long V_63 , V_14 , V_77 ;
unsigned long V_36 , V_78 , V_57 ;
T_3 V_79 , V_66 ;
unsigned long V_80 ;
V_1 = V_13 -> V_67 . V_1 ;
V_75 = V_13 -> V_67 . V_81 ;
if ( F_7 ( V_74 == V_82 ) )
goto V_83;
V_77 = ( unsigned long ) ( F_21 ( V_40 ) + V_72 ) ;
V_14 = F_33 ( V_77 + V_38 ) - ( V_77 & V_84 ) ;
V_14 >>= V_28 ;
F_34 ( & V_1 -> V_41 , V_63 ) ;
V_76 = F_26 ( V_13 , V_1 , V_14 ) ;
V_57 = 0 ;
if ( V_1 -> V_85 )
V_57 = F_27 ( V_1 ) ;
F_35 ( & V_1 -> V_41 , V_63 ) ;
if ( F_7 ( ! V_76 ) )
goto V_86;
V_79 = ( V_1 -> V_30 +
( ( V_76 - V_1 -> V_52 ) << V_28 ) ) ;
V_66 = V_79 | ( V_77 & ~ V_84 ) ;
V_78 = F_22 ( V_77 & V_84 ) ;
if ( V_75 -> V_87 )
V_80 = F_40 ( V_57 ) ;
else
V_80 = F_37 ( V_57 ) ;
if ( V_74 != V_88 )
V_80 |= V_68 ;
for ( V_36 = 0 ; V_36 < V_14 ; V_36 ++ , V_76 ++ , V_78 += V_69 )
F_5 ( * V_76 ) = V_80 | V_78 ;
return V_66 ;
V_86:
F_30 ( V_1 , V_57 ) ;
V_83:
if ( F_8 () )
F_9 ( 1 ) ;
return V_24 ;
}
static void F_41 ( struct V_75 * V_75 , struct V_1 * V_1 ,
T_3 V_89 , unsigned long V_57 , unsigned long V_14 ,
enum V_73 V_74 )
{
int V_19 ;
if ( V_75 -> V_90 &&
V_1 -> V_85 ) {
unsigned long V_91 , V_92 ;
V_3 V_9 ;
V_92 = V_75 -> V_90 ;
V_91 = F_42 ( V_75 , V_57 ) ;
F_2 ( V_92 , V_57 ) ;
V_9 = F_3 ( V_91 ) ;
V_9 &= 0xffff ;
if ( ! V_9 )
goto V_93;
while ( V_9 ) {
if ( V_9 & 0x1 )
F_2 ( V_92 , V_57 ) ;
V_9 >>= 1 ;
}
V_9 = F_3 ( V_91 ) ;
if ( F_7 ( V_9 ) ) {
F_19 ( V_56 L_5
L_6 ,
V_9 , V_57 ) ;
goto V_94;
}
} else {
unsigned long V_36 ;
V_94:
for ( V_36 = 0 ; V_36 < V_14 ; V_36 ++ , V_89 += V_69 )
F_2 ( V_75 -> V_95 , V_89 ) ;
}
V_93:
if ( V_74 == V_88 )
return;
F_43 ( V_75 ) ;
F_2 ( V_75 -> V_96 , V_75 -> V_97 ) ;
( void ) F_3 ( V_1 -> V_7 ) ;
V_19 = 100000 ;
while ( ! F_44 ( V_75 ) ) {
V_19 -- ;
if ( ! V_19 )
break;
F_45 ( 1 ) ;
F_46 () ;
}
if ( ! V_19 )
F_19 ( V_56 L_7
L_8 ,
V_89 , V_57 , V_14 ) ;
}
static void F_47 ( struct V_12 * V_13 , T_2 V_79 ,
T_4 V_38 , enum V_73 V_74 ,
struct V_61 * V_62 )
{
struct V_1 * V_1 ;
struct V_75 * V_75 ;
T_1 * V_76 ;
unsigned long V_63 , V_14 , V_57 , V_36 ;
if ( F_7 ( V_74 == V_82 ) ) {
if ( F_8 () )
F_9 ( 1 ) ;
return;
}
V_1 = V_13 -> V_67 . V_1 ;
V_75 = V_13 -> V_67 . V_81 ;
V_14 = F_33 ( V_79 + V_38 ) - ( V_79 & V_84 ) ;
V_14 >>= V_28 ;
V_76 = V_1 -> V_52 +
( ( V_79 - V_1 -> V_30 ) >> V_28 ) ;
V_79 &= V_84 ;
F_34 ( & V_1 -> V_41 , V_63 ) ;
V_57 = 0 ;
if ( V_1 -> V_85 )
V_57 = ( F_5 ( * V_76 ) & V_98 ) >> 47UL ;
if ( V_75 -> V_87 )
F_41 ( V_75 , V_1 , V_79 , V_57 ,
V_14 , V_74 ) ;
for ( V_36 = 0 ; V_36 < V_14 ; V_36 ++ )
F_4 ( V_1 , V_76 + V_36 ) ;
F_14 ( V_1 , V_79 , V_14 ) ;
F_30 ( V_1 , V_57 ) ;
F_35 ( & V_1 -> V_41 , V_63 ) ;
}
static int F_48 ( struct V_12 * V_13 , struct V_99 * V_100 ,
int V_101 , enum V_73 V_74 ,
struct V_61 * V_62 )
{
struct V_99 * V_102 , * V_103 , * V_104 ;
unsigned long V_63 , V_15 , V_105 , V_57 ;
T_2 V_106 = 0 , V_31 ;
unsigned int V_107 ;
unsigned long V_108 ;
int V_109 , V_110 , V_36 ;
struct V_75 * V_75 ;
struct V_1 * V_1 ;
unsigned long V_111 ;
F_49 ( V_74 == V_82 ) ;
V_1 = V_13 -> V_67 . V_1 ;
V_75 = V_13 -> V_67 . V_81 ;
if ( V_101 == 0 || ! V_1 )
return 0 ;
F_34 ( & V_1 -> V_41 , V_63 ) ;
V_57 = 0 ;
if ( V_1 -> V_85 )
V_57 = F_27 ( V_1 ) ;
if ( V_75 -> V_87 )
V_105 = F_40 ( V_57 ) ;
else
V_105 = F_37 ( V_57 ) ;
if ( V_74 != V_88 )
V_105 |= V_68 ;
V_103 = V_102 = V_104 = & V_100 [ 0 ] ;
V_109 = 1 ;
V_110 = V_101 ;
V_15 = 0 ;
V_103 -> V_112 = 0 ;
V_107 = F_50 ( V_13 ) ;
V_108 = F_10 ( F_11 ( V_13 ) + 1 ,
V_69 ) >> V_28 ;
V_111 = V_1 -> V_30 >> V_28 ;
F_51 (sglist, s, nelems, i) {
unsigned long V_113 , V_14 , V_5 , V_114 = 0 , V_115 ;
T_1 * V_76 ;
V_115 = V_102 -> V_116 ;
if ( V_115 == 0 ) {
V_106 = 0 ;
continue;
}
V_113 = ( unsigned long ) F_52 ( V_102 ) ;
V_14 = F_53 ( V_113 , V_115 , V_69 ) ;
V_5 = F_6 ( V_13 , V_1 , V_14 , & V_15 ) ;
if ( F_7 ( V_5 == V_24 ) ) {
if ( F_8 () )
F_19 ( V_117 L_9
L_10 , V_1 , V_113 , V_14 ) ;
goto V_118;
}
V_76 = V_1 -> V_52 + V_5 ;
V_31 = V_1 -> V_30 +
( V_5 << V_28 ) ;
V_31 |= ( V_102 -> V_72 & ~ V_84 ) ;
V_113 &= V_84 ;
while ( V_14 -- ) {
F_5 ( * V_76 ) = V_105 | V_113 ;
V_76 ++ ;
V_113 += V_69 ;
}
if ( V_104 != V_102 ) {
if ( ( V_31 != V_106 ) ||
( V_103 -> V_112 + V_102 -> V_116 > V_107 ) ||
( F_54 ( V_114 , V_111 ,
V_108 , V_103 , V_102 ) ) ) {
V_104 = V_102 ;
V_109 ++ ;
V_103 = F_55 ( V_103 ) ;
} else {
V_103 -> V_112 += V_102 -> V_116 ;
}
}
if ( V_104 == V_102 ) {
V_103 -> V_119 = V_31 ;
V_103 -> V_112 = V_115 ;
V_114 = V_5 ;
}
V_106 = V_31 + V_115 ;
}
F_35 ( & V_1 -> V_41 , V_63 ) ;
if ( V_109 < V_110 ) {
V_103 = F_55 ( V_103 ) ;
V_103 -> V_119 = V_24 ;
V_103 -> V_112 = 0 ;
}
return V_109 ;
V_118:
F_51 (sglist, s, nelems, i) {
if ( V_102 -> V_112 != 0 ) {
unsigned long V_89 , V_14 , V_5 , V_120 ;
T_1 * V_76 ;
V_89 = V_102 -> V_119 & V_84 ;
V_14 = F_53 ( V_102 -> V_119 , V_102 -> V_112 ,
V_69 ) ;
F_14 ( V_1 , V_89 , V_14 ) ;
V_5 = ( V_89 - V_1 -> V_30 )
>> V_28 ;
V_76 = V_1 -> V_52 + V_5 ;
for ( V_120 = 0 ; V_120 < V_14 ; V_120 ++ )
F_4 ( V_1 , V_76 + V_120 ) ;
V_102 -> V_119 = V_24 ;
V_102 -> V_112 = 0 ;
}
if ( V_102 == V_103 )
break;
}
F_35 ( & V_1 -> V_41 , V_63 ) ;
return 0 ;
}
static unsigned long F_56 ( struct V_1 * V_1 , struct V_99 * V_121 )
{
unsigned long V_57 = 0 ;
if ( V_1 -> V_85 ) {
T_1 * V_76 ;
T_3 V_79 ;
V_79 = V_121 -> V_119 & V_84 ;
V_76 = V_1 -> V_52 +
( ( V_79 - V_1 -> V_30 ) >> V_28 ) ;
V_57 = ( F_5 ( * V_76 ) & V_98 ) >> 47UL ;
}
return V_57 ;
}
static void F_57 ( struct V_12 * V_13 , struct V_99 * V_100 ,
int V_101 , enum V_73 V_74 ,
struct V_61 * V_62 )
{
unsigned long V_63 , V_57 ;
struct V_99 * V_121 ;
struct V_75 * V_75 ;
struct V_1 * V_1 ;
F_49 ( V_74 == V_82 ) ;
V_1 = V_13 -> V_67 . V_1 ;
V_75 = V_13 -> V_67 . V_81 ;
V_57 = F_56 ( V_1 , V_100 ) ;
F_34 ( & V_1 -> V_41 , V_63 ) ;
V_121 = V_100 ;
while ( V_101 -- ) {
T_2 V_122 = V_121 -> V_119 ;
unsigned int V_123 = V_121 -> V_112 ;
unsigned long V_14 , V_5 ;
T_1 * V_76 ;
int V_36 ;
if ( ! V_123 )
break;
V_14 = F_53 ( V_122 , V_123 , V_69 ) ;
F_14 ( V_1 , V_122 , V_14 ) ;
V_5 = ( ( V_122 - V_1 -> V_30 )
>> V_28 ) ;
V_76 = V_1 -> V_52 + V_5 ;
V_122 &= V_84 ;
if ( V_75 -> V_87 )
F_41 ( V_75 , V_1 , V_122 , V_57 ,
V_14 , V_74 ) ;
for ( V_36 = 0 ; V_36 < V_14 ; V_36 ++ )
F_4 ( V_1 , V_76 + V_36 ) ;
V_121 = F_55 ( V_121 ) ;
}
F_30 ( V_1 , V_57 ) ;
F_35 ( & V_1 -> V_41 , V_63 ) ;
}
static void F_58 ( struct V_12 * V_13 ,
T_2 V_79 , T_4 V_38 ,
enum V_73 V_74 )
{
struct V_1 * V_1 ;
struct V_75 * V_75 ;
unsigned long V_63 , V_57 , V_14 ;
V_1 = V_13 -> V_67 . V_1 ;
V_75 = V_13 -> V_67 . V_81 ;
if ( ! V_75 -> V_87 )
return;
F_34 ( & V_1 -> V_41 , V_63 ) ;
V_14 = F_33 ( V_79 + V_38 ) - ( V_79 & V_84 ) ;
V_14 >>= V_28 ;
V_79 &= V_84 ;
V_57 = 0 ;
if ( V_1 -> V_85 &&
V_75 -> V_90 ) {
T_1 * V_8 ;
V_8 = V_1 -> V_52 +
( ( V_79 - V_1 -> V_30 ) >> V_28 ) ;
V_57 = ( F_5 ( * V_8 ) & V_98 ) >> 47UL ;
}
F_41 ( V_75 , V_1 , V_79 , V_57 , V_14 , V_74 ) ;
F_35 ( & V_1 -> V_41 , V_63 ) ;
}
static void F_59 ( struct V_12 * V_13 ,
struct V_99 * V_100 , int V_101 ,
enum V_73 V_74 )
{
struct V_1 * V_1 ;
struct V_75 * V_75 ;
unsigned long V_63 , V_57 , V_14 , V_36 ;
struct V_99 * V_121 , * V_124 ;
T_3 V_79 ;
V_1 = V_13 -> V_67 . V_1 ;
V_75 = V_13 -> V_67 . V_81 ;
if ( ! V_75 -> V_87 )
return;
F_34 ( & V_1 -> V_41 , V_63 ) ;
V_57 = 0 ;
if ( V_1 -> V_85 &&
V_75 -> V_90 ) {
T_1 * V_8 ;
V_8 = V_1 -> V_52 +
( ( V_100 [ 0 ] . V_119 - V_1 -> V_30 ) >> V_28 ) ;
V_57 = ( F_5 ( * V_8 ) & V_98 ) >> 47UL ;
}
V_79 = V_100 [ 0 ] . V_119 & V_84 ;
V_124 = NULL ;
F_51 (sglist, sg, nelems, i) {
if ( V_121 -> V_112 == 0 )
break;
V_124 = V_121 ;
}
V_14 = ( F_33 ( V_124 -> V_119 + V_124 -> V_112 )
- V_79 ) >> V_28 ;
F_41 ( V_75 , V_1 , V_79 , V_57 , V_14 , V_74 ) ;
F_35 ( & V_1 -> V_41 , V_63 ) ;
}
int F_60 ( struct V_12 * V_13 , V_3 V_125 )
{
struct V_1 * V_1 = V_13 -> V_67 . V_1 ;
V_3 V_34 = V_1 -> V_34 ;
if ( V_125 >= ( 1UL << 32UL ) )
return 0 ;
if ( ( V_125 & V_34 ) == V_34 )
return 1 ;
#ifdef F_61
if ( F_62 ( V_13 ) )
return F_63 ( F_64 ( V_13 ) , V_125 ) ;
#endif
return 0 ;
}
