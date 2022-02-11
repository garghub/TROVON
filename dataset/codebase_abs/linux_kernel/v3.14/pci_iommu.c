static inline unsigned long
F_1 ( unsigned long V_1 )
{
return ( V_1 >> ( V_2 - 1 ) ) | 1 ;
}
unsigned long
F_2 ( unsigned long V_3 )
{
unsigned long V_4 = V_5 << V_2 ;
if ( V_4 < V_3 )
V_3 = F_3 ( V_4 ) ;
return V_3 ;
}
struct V_6 * T_1
F_4 ( int V_7 , struct V_8 * V_9 , T_2 V_10 ,
unsigned long V_11 , unsigned long V_12 )
{
unsigned long V_13 ;
struct V_6 * V_14 ;
V_13 = V_11 / ( V_15 / sizeof( unsigned long ) ) ;
if ( V_12 < V_13 )
V_12 = V_13 ;
#ifdef F_5
V_14 = F_6 ( F_7 ( V_7 ) , sizeof( * V_14 ) ) ;
if ( ! F_7 ( V_7 ) || ! V_14 ) {
F_8 ( L_1
L_2 ,
V_16 , V_7 ) ;
V_14 = F_9 ( sizeof( * V_14 ) ) ;
}
V_14 -> V_17 = F_10 ( F_7 ( V_7 ) , V_13 , V_12 , 0 ) ;
if ( ! F_7 ( V_7 ) || ! V_14 -> V_17 ) {
F_8 ( L_3
L_2 ,
V_16 , V_7 ) ;
V_14 -> V_17 = F_11 ( V_13 , V_12 , 0 ) ;
}
#else
V_14 = F_9 ( sizeof( * V_14 ) ) ;
V_14 -> V_17 = F_11 ( V_13 , V_12 , 0 ) ;
#endif
F_12 ( & V_14 -> V_18 ) ;
V_14 -> V_9 = V_9 ;
V_14 -> V_19 = V_10 ;
V_14 -> V_20 = V_11 ;
V_14 -> V_21 = 0 ;
V_14 -> V_22 = 1 ;
return V_14 ;
}
struct V_6 * T_1
F_13 ( struct V_8 * V_9 , T_2 V_10 ,
unsigned long V_11 , unsigned long V_12 )
{
return F_4 ( 0 , V_9 , V_10 , V_11 , V_12 ) ;
}
static long
F_14 ( struct V_23 * V_24 , struct V_6 * V_14 ,
long V_25 , long V_26 )
{
unsigned long * V_17 ;
long V_27 , V_28 , V_29 ;
int V_30 = 0 ;
unsigned long V_10 ;
unsigned long V_31 ;
V_10 = V_14 -> V_19 >> V_2 ;
if ( V_24 ) {
V_31 = F_15 ( V_24 ) + 1 ;
V_31 >>= V_2 ;
} else {
V_31 = 1UL << ( 32 - V_2 ) ;
}
V_17 = V_14 -> V_17 ;
V_29 = V_14 -> V_20 >> V_2 ;
V_28 = F_16 ( V_14 -> V_21 , V_26 + 1 ) ;
V_27 = 0 ;
V_32:
while ( V_27 < V_25 && V_28 + V_27 < V_29 ) {
if ( ! V_27 && F_17 ( V_28 , V_25 , V_10 , V_31 ) ) {
V_28 = F_16 ( V_28 + 1 , V_26 + 1 ) ;
goto V_32;
}
if ( V_17 [ V_28 + V_27 ] )
V_28 = F_16 ( V_28 + V_27 + 1 , V_26 + 1 ) , V_27 = 0 ;
else
V_27 = V_27 + 1 ;
}
if ( V_27 < V_25 ) {
if ( V_30 < 1 ) {
V_33 . V_34 ( V_14 -> V_9 , 0 , - 1 ) ;
V_30 ++ ;
V_28 = 0 ;
V_27 = 0 ;
goto V_32;
} else
return - 1 ;
}
return V_28 ;
}
static long
F_18 ( struct V_23 * V_24 , struct V_6 * V_14 , long V_25 ,
unsigned int V_12 )
{
unsigned long V_35 ;
unsigned long * V_17 ;
long V_27 , V_28 , V_26 ;
F_19 ( & V_14 -> V_18 , V_35 ) ;
V_17 = V_14 -> V_17 ;
V_26 = V_3 ( V_12 , V_14 -> V_22 ) - 1 ;
V_28 = F_14 ( V_24 , V_14 , V_25 , V_26 ) ;
if ( V_28 < 0 ) {
F_20 ( & V_14 -> V_18 , V_35 ) ;
return - 1 ;
}
for ( V_27 = 0 ; V_27 < V_25 ; ++ V_27 )
V_17 [ V_28 + V_27 ] = V_36 ;
V_14 -> V_21 = V_28 + V_25 ;
F_20 ( & V_14 -> V_18 , V_35 ) ;
return V_28 ;
}
static void
F_21 ( struct V_6 * V_14 , long V_37 , long V_25 )
{
unsigned long * V_28 ;
long V_27 ;
V_28 = V_14 -> V_17 + V_37 ;
for ( V_27 = 0 ; V_27 < V_25 ; ++ V_27 )
V_28 [ V_27 ] = 0 ;
}
static int F_22 ( struct V_38 * V_24 , T_3 V_26 )
{
T_2 V_39 = V_33 . V_40 ;
int V_41 = 1 ;
if ( V_39 == 0 )
V_41 = 0 ;
if ( ( V_39 & V_24 -> V_42 ) != V_39 )
V_41 = 0 ;
F_23 ( L_4 ,
V_41 ? L_5 : L_6 , F_24 ( 0 ) ) ;
return V_41 ;
}
static T_2
F_25 ( struct V_38 * V_43 , void * V_44 , T_4 V_20 ,
int V_45 )
{
struct V_8 * V_9 = V_43 ? V_43 -> V_46 : V_47 ;
T_2 V_48 = V_43 ? V_43 -> V_42 : V_49 ;
struct V_6 * V_14 ;
long V_50 , V_51 , V_27 ;
unsigned long V_1 ;
T_2 V_52 ;
unsigned int V_12 = 0 ;
struct V_23 * V_24 = V_43 ? & V_43 -> V_24 : NULL ;
V_1 = F_26 ( V_44 ) ;
#if ! V_53
if ( V_1 + V_20 + V_54 - 1 <= V_48
&& V_1 + V_20 <= V_55 ) {
V_52 = V_1 + V_54 ;
F_27 ( L_7 ,
V_44 , V_20 , V_52 , F_24 ( 0 ) ) ;
return V_52 ;
}
#endif
if ( V_45 ) {
V_52 = V_1 + V_33 . V_40 ;
F_27 ( L_8 ,
V_44 , V_20 , V_52 , F_24 ( 0 ) ) ;
return V_52 ;
}
if ( ! V_33 . V_34 ) {
F_28 ( V_56 L_9 ) ;
return 0 ;
}
V_14 = V_9 -> V_57 ;
if ( ! V_14 || V_14 -> V_19 + V_14 -> V_20 - 1 > V_48 )
V_14 = V_9 -> V_58 ;
V_50 = F_29 ( V_1 , V_20 , V_15 ) ;
if ( V_43 && V_43 == V_59 )
V_12 = 8 ;
V_51 = F_18 ( V_24 , V_14 , V_50 , V_12 ) ;
if ( V_51 < 0 ) {
F_8 ( V_56 L_10
L_11 ) ;
return 0 ;
}
V_1 &= V_60 ;
for ( V_27 = 0 ; V_27 < V_50 ; ++ V_27 , V_1 += V_15 )
V_14 -> V_17 [ V_27 + V_51 ] = F_1 ( V_1 ) ;
V_52 = V_14 -> V_19 + V_51 * V_15 ;
V_52 += ( unsigned long ) V_44 & ~ V_60 ;
F_27 ( L_12 ,
V_44 , V_20 , V_50 , V_52 , F_24 ( 0 ) ) ;
return V_52 ;
}
static struct V_38 * F_30 ( struct V_23 * V_24 )
{
if ( V_24 && F_31 ( V_24 ) )
return F_32 ( V_24 ) ;
F_33 ( ! V_59 ) ;
if ( ! V_24 || ! V_24 -> V_42 || ! * V_24 -> V_42 )
return V_59 ;
if ( * V_24 -> V_42 >= V_59 -> V_42 )
return V_59 ;
return NULL ;
}
static T_2 F_34 ( struct V_23 * V_24 , struct V_61 * V_61 ,
unsigned long V_62 , T_4 V_20 ,
enum V_63 V_64 ,
struct V_65 * V_66 )
{
struct V_38 * V_43 = F_30 ( V_24 ) ;
int V_45 ;
F_33 ( V_64 == V_67 ) ;
V_45 = V_43 ? F_22 ( V_43 , V_43 -> V_42 ) : 0 ;
return F_25 ( V_43 , ( char * ) F_35 ( V_61 ) + V_62 ,
V_20 , V_45 ) ;
}
static void F_36 ( struct V_23 * V_24 , T_2 V_68 ,
T_4 V_20 , enum V_63 V_64 ,
struct V_65 * V_66 )
{
unsigned long V_35 ;
struct V_38 * V_43 = F_30 ( V_24 ) ;
struct V_8 * V_9 = V_43 ? V_43 -> V_46 : V_47 ;
struct V_6 * V_14 ;
long V_51 , V_50 ;
F_33 ( V_64 == V_67 ) ;
if ( V_68 >= V_54
&& V_68 < V_54 + V_55 ) {
F_27 ( L_13 ,
V_68 , V_20 , F_24 ( 0 ) ) ;
return;
}
if ( V_68 > 0xffffffff ) {
F_27 ( L_14 ,
V_68 , V_20 , F_24 ( 0 ) ) ;
return;
}
V_14 = V_9 -> V_57 ;
if ( ! V_14 || V_68 < V_14 -> V_19 )
V_14 = V_9 -> V_58 ;
V_51 = ( V_68 - V_14 -> V_19 ) >> V_2 ;
if ( V_51 * V_15 >= V_14 -> V_20 ) {
F_8 ( V_69 L_15
L_16 ,
V_68 , V_14 -> V_19 , V_14 -> V_20 ) ;
return;
F_37 () ;
}
V_50 = F_29 ( V_68 , V_20 , V_15 ) ;
F_19 ( & V_14 -> V_18 , V_35 ) ;
F_21 ( V_14 , V_51 , V_50 ) ;
if ( V_51 >= V_14 -> V_21 )
V_33 . V_34 ( V_9 , V_68 , V_68 + V_20 - 1 ) ;
F_20 ( & V_14 -> V_18 , V_35 ) ;
F_27 ( L_17 ,
V_68 , V_20 , V_50 , F_24 ( 0 ) ) ;
}
static void * F_38 ( struct V_23 * V_24 , T_4 V_20 ,
T_2 * V_70 , T_5 V_71 ,
struct V_65 * V_66 )
{
struct V_38 * V_43 = F_30 ( V_24 ) ;
void * V_44 ;
long V_72 = F_39 ( V_20 ) ;
V_71 &= ~ V_73 ;
V_74:
V_44 = ( void * ) F_40 ( V_71 , V_72 ) ;
if ( ! V_44 ) {
F_8 ( V_75 L_18
L_19 ,
F_24 ( 0 ) ) ;
return NULL ;
}
memset ( V_44 , 0 , V_20 ) ;
* V_70 = F_25 ( V_43 , V_44 , V_20 , 0 ) ;
if ( * V_70 == 0 ) {
F_41 ( ( unsigned long ) V_44 , V_72 ) ;
if ( V_33 . V_34 || ( V_71 & V_73 ) )
return NULL ;
V_71 |= V_73 ;
goto V_74;
}
F_27 ( L_20 ,
V_20 , V_44 , * V_70 , F_24 ( 0 ) ) ;
return V_44 ;
}
static void F_42 ( struct V_23 * V_24 , T_4 V_20 ,
void * V_44 , T_2 V_68 ,
struct V_65 * V_66 )
{
struct V_38 * V_43 = F_30 ( V_24 ) ;
F_43 ( V_43 , V_68 , V_20 , V_76 ) ;
F_41 ( ( unsigned long ) V_44 , F_39 ( V_20 ) ) ;
F_27 ( L_21 ,
V_68 , V_20 , F_24 ( 0 ) ) ;
}
static void
F_44 ( struct V_23 * V_24 , struct V_77 * V_78 , struct V_77 * V_79 ,
int V_80 )
{
unsigned long V_81 ;
struct V_77 * V_82 ;
long V_83 , V_84 ;
unsigned int V_85 ;
V_82 = V_78 ;
V_83 = 0 ;
V_84 = V_82 -> V_86 ;
V_81 = F_45 ( V_82 ) + V_84 ;
V_85 = V_24 ? F_46 ( V_24 ) : 0 ;
for ( ++ V_78 ; V_78 < V_79 ; ++ V_78 ) {
unsigned long V_87 , V_88 ;
V_87 = F_45 ( V_78 ) ;
V_88 = V_78 -> V_86 ;
if ( V_84 + V_88 > V_85 )
goto V_89;
if ( V_81 == V_87 ) {
V_78 -> V_90 = - 1 ;
V_84 += V_88 ;
} else if ( ( ( V_81 | V_87 ) & ~ V_60 ) == 0 && V_80 ) {
V_78 -> V_90 = - 2 ;
V_83 = 1 ;
V_84 += V_88 ;
} else {
V_89:
V_82 -> V_90 = V_83 ;
V_82 -> V_91 = V_84 ;
V_82 = V_78 ;
V_83 = 0 ;
V_84 = V_88 ;
}
V_81 = V_87 + V_88 ;
}
V_82 -> V_90 = V_83 ;
V_82 -> V_91 = V_84 ;
}
static int
F_47 ( struct V_23 * V_24 , struct V_77 * V_82 , struct V_77 * V_79 ,
struct V_77 * V_92 , struct V_6 * V_14 ,
T_2 V_48 , int V_45 )
{
unsigned long V_1 = F_45 ( V_82 ) ;
long V_20 = V_82 -> V_91 ;
struct V_77 * V_78 ;
unsigned long * V_17 ;
long V_50 , V_51 , V_27 ;
#if ! V_53
if ( V_82 -> V_90 == 0
&& V_1 + V_20 + V_54 - 1 <= V_48
&& V_1 + V_20 <= V_55 ) {
V_92 -> V_90 = V_1 + V_54 ;
V_92 -> V_91 = V_20 ;
F_23 ( L_22 ,
F_48 ( V_1 ) , V_20 , V_92 -> V_90 ) ;
return 0 ;
}
#endif
if ( V_82 -> V_90 == 0 && V_45 ) {
V_92 -> V_90 = V_1 + V_33 . V_40 ;
V_92 -> V_91 = V_20 ;
F_23 ( L_23 ,
F_48 ( V_1 ) , V_20 , V_92 -> V_90 ) ;
return 0 ;
}
V_1 &= ~ V_60 ;
V_50 = F_29 ( V_1 , V_20 , V_15 ) ;
V_51 = F_18 ( V_24 , V_14 , V_50 , 0 ) ;
if ( V_51 < 0 ) {
if ( V_82 -> V_90 == 0 )
return - 1 ;
F_44 ( V_24 , V_82 , V_79 , 0 ) ;
return F_47 ( V_24 , V_82 , V_79 , V_92 , V_14 , V_48 , V_45 ) ;
}
V_92 -> V_90 = V_14 -> V_19 + V_51 * V_15 + V_1 ;
V_92 -> V_91 = V_20 ;
F_23 ( L_24 ,
F_48 ( V_1 ) , V_20 , V_92 -> V_90 , V_50 ) ;
V_17 = & V_14 -> V_17 [ V_51 ] ;
V_78 = V_82 ;
do {
#if V_93 > 0
struct V_77 * V_94 = V_78 ;
#endif
V_20 = V_78 -> V_86 ;
V_1 = F_45 ( V_78 ) ;
while ( V_78 + 1 < V_79 && ( int ) V_78 [ 1 ] . V_90 == - 1 ) {
V_20 += V_78 [ 1 ] . V_86 ;
V_78 ++ ;
}
V_50 = F_29 ( V_1 , V_20 , V_15 ) ;
V_1 &= V_60 ;
for ( V_27 = 0 ; V_27 < V_50 ; ++ V_27 , V_1 += V_15 )
* V_17 ++ = F_1 ( V_1 ) ;
#if V_93 > 0
F_23 ( L_25 ,
V_94 - V_82 , F_49 ( V_94 ) ,
V_94 -> V_86 , V_50 ) ;
while ( ++ V_94 <= V_78 ) {
F_23 ( L_26 ,
V_94 - V_82 , F_49 ( V_94 ) ,
V_94 -> V_86 ) ;
}
#endif
} while ( ++ V_78 < V_79 && ( int ) V_78 -> V_90 < 0 );
return 1 ;
}
static int F_50 ( struct V_23 * V_24 , struct V_77 * V_78 ,
int V_95 , enum V_63 V_64 ,
struct V_65 * V_66 )
{
struct V_38 * V_43 = F_30 ( V_24 ) ;
struct V_77 * V_96 , * V_79 , * V_92 ;
struct V_8 * V_9 ;
struct V_6 * V_14 ;
T_2 V_48 ;
int V_45 ;
F_33 ( V_64 == V_67 ) ;
V_45 = V_24 ? F_22 ( V_43 , V_43 -> V_42 ) : 0 ;
if ( V_95 == 1 ) {
V_78 -> V_91 = V_78 -> V_86 ;
V_78 -> V_90
= F_25 ( V_43 , F_49 ( V_78 ) ,
V_78 -> V_86 , V_45 ) ;
return V_78 -> V_90 != 0 ;
}
V_96 = V_78 ;
V_79 = V_78 + V_95 ;
F_44 ( V_24 , V_78 , V_79 , V_33 . V_34 != 0 ) ;
if ( V_33 . V_34 ) {
V_9 = V_43 ? V_43 -> V_46 : V_47 ;
V_48 = V_43 ? V_43 -> V_42 : V_49 ;
V_14 = V_9 -> V_57 ;
if ( ! V_14 || V_14 -> V_19 + V_14 -> V_20 - 1 > V_48 )
V_14 = V_9 -> V_58 ;
} else {
V_48 = - 1 ;
V_14 = NULL ;
V_9 = NULL ;
}
for ( V_92 = V_78 ; V_78 < V_79 ; ++ V_78 ) {
if ( ( int ) V_78 -> V_90 < 0 )
continue;
if ( F_47 ( V_24 , V_78 , V_79 , V_92 , V_14 , V_48 , V_45 ) < 0 )
goto error;
V_92 ++ ;
}
if ( V_92 < V_79 )
V_92 -> V_91 = 0 ;
if ( V_92 - V_96 == 0 )
F_8 ( V_56 L_27 ) ;
F_23 ( L_28 , V_92 - V_96 ) ;
return V_92 - V_96 ;
error:
F_8 ( V_56 L_29
L_11 ) ;
if ( V_92 > V_96 )
F_51 ( V_43 , V_96 , V_92 - V_96 , V_64 ) ;
return 0 ;
}
static void F_52 ( struct V_23 * V_24 , struct V_77 * V_78 ,
int V_95 , enum V_63 V_64 ,
struct V_65 * V_66 )
{
struct V_38 * V_43 = F_30 ( V_24 ) ;
unsigned long V_35 ;
struct V_8 * V_9 ;
struct V_6 * V_14 ;
struct V_77 * V_79 ;
T_2 V_48 ;
T_2 V_97 , V_98 ;
F_33 ( V_64 == V_67 ) ;
if ( ! V_33 . V_34 )
return;
V_9 = V_43 ? V_43 -> V_46 : V_47 ;
V_48 = V_43 ? V_43 -> V_42 : V_49 ;
V_14 = V_9 -> V_57 ;
if ( ! V_14 || V_14 -> V_19 + V_14 -> V_20 - 1 > V_48 )
V_14 = V_9 -> V_58 ;
V_97 = - 1 , V_98 = 0 ;
F_19 ( & V_14 -> V_18 , V_35 ) ;
for ( V_79 = V_78 + V_95 ; V_78 < V_79 ; ++ V_78 ) {
T_2 V_87 ;
T_4 V_20 ;
long V_50 , V_37 ;
T_2 V_99 ;
V_87 = V_78 -> V_90 ;
V_20 = V_78 -> V_91 ;
if ( ! V_20 )
break;
if ( V_87 > 0xffffffff ) {
F_23 ( L_30 ,
V_78 - V_79 + V_95 , V_87 , V_20 ) ;
continue;
}
if ( V_87 >= V_54
&& V_87 < V_54 + V_55 ) {
F_23 ( L_31 ,
V_78 - V_79 + V_95 , V_87 , V_20 ) ;
continue;
}
F_23 ( L_32 ,
V_78 - V_79 + V_95 , V_87 , V_20 ) ;
V_50 = F_29 ( V_87 , V_20 , V_15 ) ;
V_37 = ( V_87 - V_14 -> V_19 ) >> V_2 ;
F_21 ( V_14 , V_37 , V_50 ) ;
V_99 = V_87 + V_20 - 1 ;
if ( V_97 > V_87 ) V_97 = V_87 ;
if ( V_98 < V_99 ) V_98 = V_99 ;
}
if ( ( V_98 - V_14 -> V_19 ) >> V_2 >= V_14 -> V_21 )
V_33 . V_34 ( V_9 , V_97 , V_98 ) ;
F_20 ( & V_14 -> V_18 , V_35 ) ;
F_23 ( L_33 , V_95 - ( V_79 - V_78 ) ) ;
}
static int F_53 ( struct V_23 * V_24 , T_3 V_26 )
{
struct V_38 * V_43 = F_30 ( V_24 ) ;
struct V_8 * V_9 ;
struct V_6 * V_14 ;
if ( V_55 != 0
&& ( V_54 + V_55 - 1 <= V_26 ||
V_54 + ( V_5 << V_2 ) - 1 <= V_26 ) )
return 1 ;
V_9 = V_43 ? V_43 -> V_46 : V_47 ;
V_14 = V_9 -> V_58 ;
if ( V_14 && V_14 -> V_19 + V_14 -> V_20 - 1 <= V_26 )
return 1 ;
V_14 = V_9 -> V_57 ;
if ( V_14 && V_14 -> V_19 + V_14 -> V_20 - 1 <= V_26 )
return 1 ;
if ( ! V_54 && V_100 - V_101 - 1 <= V_26 )
return 1 ;
return 0 ;
}
int
F_54 ( struct V_6 * V_14 , long V_102 , long V_103 )
{
unsigned long V_35 ;
unsigned long * V_17 ;
long V_27 , V_28 ;
if ( ! V_14 ) return - V_104 ;
F_19 ( & V_14 -> V_18 , V_35 ) ;
V_17 = V_14 -> V_17 ;
V_28 = F_14 ( NULL , V_14 , V_102 , V_103 ) ;
if ( V_28 < 0 ) {
F_20 ( & V_14 -> V_18 , V_35 ) ;
return - 1 ;
}
for ( V_27 = 0 ; V_27 < V_102 ; ++ V_27 )
V_17 [ V_28 + V_27 ] = V_105 ;
V_14 -> V_21 = V_28 + V_102 ;
F_20 ( & V_14 -> V_18 , V_35 ) ;
return V_28 ;
}
int
F_55 ( struct V_6 * V_14 , long V_106 , long V_102 )
{
unsigned long * V_17 ;
long V_27 ;
if ( ! V_14 ) return - V_104 ;
V_17 = V_14 -> V_17 ;
for( V_27 = V_106 ; V_27 < V_106 + V_102 ; V_27 ++ )
if ( V_17 [ V_27 ] != V_105 )
return - V_107 ;
F_21 ( V_14 , V_106 , V_102 ) ;
return 0 ;
}
int
F_56 ( struct V_6 * V_14 , long V_106 , long V_102 ,
struct V_61 * * V_108 )
{
unsigned long V_35 ;
unsigned long * V_17 ;
long V_27 , V_109 ;
if ( ! V_14 ) return - V_104 ;
F_19 ( & V_14 -> V_18 , V_35 ) ;
V_17 = V_14 -> V_17 ;
for( V_109 = V_106 ; V_109 < V_106 + V_102 ; V_109 ++ ) {
if ( V_17 [ V_109 ] != V_105 ) {
F_20 ( & V_14 -> V_18 , V_35 ) ;
return - V_107 ;
}
}
for( V_27 = 0 , V_109 = V_106 ; V_27 < V_102 ; V_27 ++ , V_109 ++ )
V_17 [ V_109 ] = F_1 ( F_57 ( V_108 [ V_27 ] ) ) ;
F_20 ( & V_14 -> V_18 , V_35 ) ;
return 0 ;
}
int
F_58 ( struct V_6 * V_14 , long V_106 , long V_102 )
{
unsigned long * V_28 ;
long V_27 ;
if ( ! V_14 ) return - V_104 ;
V_28 = V_14 -> V_17 + V_106 ;
for( V_27 = 0 ; V_27 < V_102 ; V_27 ++ )
V_28 [ V_27 ] = V_105 ;
return 0 ;
}
static int F_59 ( struct V_23 * V_24 , T_2 V_68 )
{
return V_68 == 0 ;
}
static int F_60 ( struct V_23 * V_24 , T_3 V_26 )
{
if ( ! V_24 -> V_42 ||
! F_61 ( F_30 ( V_24 ) , V_26 ) )
return - V_110 ;
* V_24 -> V_42 = V_26 ;
return 0 ;
}
