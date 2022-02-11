static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_4 ;
V_4 = F_2 ( sizeof( struct V_4 ) , V_5 ) ;
if ( ! ( V_4 ) ) {
F_3 ( V_6 L_1 ) ;
return - V_7 ;
}
V_4 -> V_8 = V_3 ;
F_4 ( & V_2 -> V_9 , V_10 ) ;
F_4 ( & V_2 -> V_11 , V_10 ) ;
V_2 -> V_12 = ( void * ) V_4 ;
F_3 ( V_13 L_2
L_3 , V_2 -> V_14 ,
V_15 , V_16 ) ;
F_3 ( V_13 L_4
L_5 , V_2 -> V_14 ,
V_4 -> V_8 , F_5 ( & V_2 -> V_11 ) ,
V_17 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_12 ;
F_3 ( V_13 L_6
L_7 , V_2 -> V_14 , V_4 -> V_8 ) ;
F_7 ( V_4 ) ;
V_2 -> V_12 = NULL ;
}
static void F_8 ( struct V_18 * V_18 )
{
T_1 V_19 , V_20 , V_21 = 0 , V_22 ;
struct V_23 * V_24 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
if ( ! V_18 -> V_29 || ! V_18 -> V_30 )
return;
V_24 = V_18 -> V_29 ;
for ( V_19 = 0 ; V_19 < V_18 -> V_30 ; V_19 ++ ) {
V_28 = V_24 [ V_19 ] . V_24 ;
V_22 = V_24 [ V_19 ] . V_31 ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
V_26 = F_9 ( & V_28 [ V_20 ] ) ;
if ( ( V_26 ) ) {
F_10 ( V_26 ) ;
V_21 ++ ;
}
}
F_7 ( V_28 ) ;
}
F_3 ( V_13 L_8
L_9 ,
V_18 -> V_4 -> V_8 , V_18 -> V_32 , V_21 ,
V_18 -> V_30 , ( unsigned long ) V_21 * V_33 ) ;
F_7 ( V_24 ) ;
V_18 -> V_29 = NULL ;
V_18 -> V_30 = 0 ;
}
static int F_11 ( struct V_18 * V_18 )
{
T_1 V_19 = 0 , V_20 , V_34 = 0 , V_22 , V_35 , V_36 ;
T_1 V_37 = ( V_38 /
sizeof( struct V_27 ) ) ;
struct V_23 * V_24 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
if ( V_18 -> V_39 <= 0 ) {
F_3 ( V_6 L_10 ,
V_18 -> V_39 ) ;
return - V_40 ;
}
V_36 = V_18 -> V_39 ;
V_35 = ( V_36 / V_37 ) + 1 ;
V_24 = F_2 ( V_35 * sizeof( struct V_23 ) , V_5 ) ;
if ( ! ( V_24 ) ) {
F_3 ( V_6 L_11
L_12 ) ;
return - V_7 ;
}
V_18 -> V_29 = V_24 ;
V_18 -> V_30 = V_35 ;
while ( V_36 ) {
V_22 = ( V_36 > V_37 ) ?
V_37 : V_36 ;
V_28 = F_2 ( V_22 * sizeof( struct V_27 ) ,
V_5 ) ;
if ( ! ( V_28 ) ) {
F_3 ( V_6 L_13
L_14 ) ;
return - V_7 ;
}
F_12 ( (struct V_27 * ) & V_28 [ 0 ] , V_22 ) ;
V_24 [ V_19 ] . V_24 = V_28 ;
V_24 [ V_19 ] . V_31 = V_22 ;
V_24 [ V_19 ] . V_41 = V_34 ;
V_24 [ V_19 ++ ] . V_42 = ( V_34 + V_22 )
- 1 ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
V_26 = F_13 ( V_5 , 0 ) ;
if ( ! ( V_26 ) ) {
F_3 ( V_6 L_15
L_16 ) ;
return - V_7 ;
}
F_14 ( & V_28 [ V_20 ] , V_26 ) ;
V_28 [ V_20 ] . V_43 = V_33 ;
}
V_34 += V_22 ;
V_36 -= V_22 ;
}
F_3 ( V_13 L_17
L_18 , V_18 -> V_4 -> V_8 ,
V_18 -> V_32 , V_18 -> V_39 ,
V_18 -> V_30 ) ;
return 0 ;
}
static void * F_15 (
struct V_1 * V_2 ,
const char * V_44 ,
int V_45 )
{
struct V_18 * V_18 ;
struct V_4 * V_4 = V_2 -> V_12 ;
V_18 = F_2 ( sizeof( struct V_18 ) , V_5 ) ;
if ( ! ( V_18 ) ) {
F_3 ( V_6 L_19 ) ;
return NULL ;
}
V_18 -> V_4 = V_4 ;
V_18 -> V_45 = V_45 ;
return V_18 ;
}
static void * F_16 ( struct V_1 * V_2 , const char * V_44 )
{
return F_15 ( V_2 , V_44 , 1 ) ;
}
static void * F_17 ( struct V_1 * V_2 , const char * V_44 )
{
return F_15 ( V_2 , V_44 , 0 ) ;
}
static struct V_46 * F_18 (
struct V_1 * V_2 ,
struct V_47 * V_48 ,
void * V_49 ,
int V_45 )
{
struct V_46 * V_50 ;
struct V_51 V_52 ;
struct V_18 * V_18 = V_49 ;
struct V_4 * V_4 = V_2 -> V_12 ;
int V_53 = 0 , V_54 ;
char V_55 [ 16 ] , V_56 [ 4 ] ;
memset ( & V_52 , 0 , sizeof( struct V_51 ) ) ;
V_54 = F_11 ( V_18 ) ;
if ( V_54 < 0 )
goto V_57;
snprintf ( V_55 , 16 , L_20 , ( V_18 -> V_45 ) ? L_21 : L_22 ) ;
snprintf ( V_56 , 4 , L_23 , ( V_18 -> V_45 ) ? V_58 :
V_59 ) ;
V_52 . V_60 . V_61 = V_62 ;
V_52 . V_60 . V_63 = V_17 ;
V_52 . V_60 . V_64 = V_17 ;
V_52 . V_65 = V_66 ;
V_52 . V_67 = V_68 ;
V_50 = F_19 ( V_2 ,
( V_18 -> V_45 ) ? & V_69 :
& V_70 , V_48 , V_53 , ( void * ) V_18 ,
& V_52 , V_55 , V_56 ) ;
if ( ! ( V_50 ) )
goto V_57;
V_18 -> V_32 = V_4 -> V_71 ++ ;
V_18 -> V_72 = V_50 -> V_67 ;
F_3 ( V_13 L_24
L_25 ,
V_4 -> V_8 , ( ! V_18 -> V_45 ) ? L_26 :
L_27 , V_18 -> V_32 , V_18 -> V_39 ,
V_18 -> V_30 ,
( unsigned long ) ( V_18 -> V_39 * V_33 ) ) ;
return V_50 ;
V_57:
F_8 ( V_18 ) ;
return F_20 ( V_54 ) ;
}
static struct V_46 * F_21 (
struct V_1 * V_2 ,
struct V_47 * V_48 ,
void * V_49 )
{
return F_18 ( V_2 , V_48 , V_49 , 1 ) ;
}
static struct V_46 * F_22 (
struct V_1 * V_2 ,
struct V_47 * V_48 ,
void * V_49 )
{
return F_18 ( V_2 , V_48 , V_49 , 0 ) ;
}
static void F_23 ( void * V_49 )
{
struct V_18 * V_18 = V_49 ;
F_8 ( V_18 ) ;
F_7 ( V_18 ) ;
}
static inline struct V_73 * F_24 ( struct V_74 * V_75 )
{
return F_25 ( V_75 , struct V_73 , V_76 ) ;
}
static struct V_74 *
F_26 ( struct V_77 * V_78 )
{
struct V_73 * V_79 ;
V_79 = F_2 ( sizeof( struct V_73 ) , V_5 ) ;
if ( ! V_79 ) {
F_3 ( V_6 L_28 ) ;
return NULL ;
}
V_79 -> V_18 = F_27 ( V_78 ) -> V_80 ;
return & V_79 -> V_76 ;
}
static struct V_23 * F_28 ( struct V_18 * V_18 , T_1 V_25 )
{
T_1 V_19 ;
struct V_23 * V_24 ;
for ( V_19 = 0 ; V_19 < V_18 -> V_30 ; V_19 ++ ) {
V_24 = & V_18 -> V_29 [ V_19 ] ;
if ( ( V_24 -> V_41 <= V_25 ) &&
( V_24 -> V_42 >= V_25 ) )
return V_24 ;
}
F_3 ( V_6 L_29 ,
V_25 ) ;
return NULL ;
}
static int F_29 ( struct V_73 * V_81 )
{
struct V_74 * V_75 = & V_81 -> V_76 ;
struct V_18 * V_50 = V_81 -> V_18 ;
struct V_23 * V_82 ;
struct V_27 * V_83 , * V_84 ;
void * V_85 , * V_86 ;
T_1 V_19 = 0 , V_20 = 0 , V_87 = 0 , V_88 = 0 ;
T_1 V_43 , V_89 = 0 , V_90 ;
T_1 V_91 = V_81 -> V_91 ;
V_82 = F_28 ( V_50 , V_81 -> V_92 ) ;
if ( ! ( V_82 ) )
return - 1 ;
V_90 = ( V_82 -> V_42 - V_81 -> V_92 ) ;
V_83 = V_75 -> V_93 ;
V_84 = & V_82 -> V_24 [ V_81 -> V_92 - V_82 -> V_41 ] ;
#ifdef F_30
F_3 ( V_13 L_30
L_31 , V_50 -> V_32 , V_75 -> V_94 , V_81 -> V_95 ,
V_81 -> V_92 , V_81 -> V_91 ) ;
#endif
V_88 = V_91 ;
while ( V_81 -> V_95 ) {
if ( ( V_83 [ V_19 ] . V_43 - V_87 ) <
( V_84 [ V_20 ] . V_43 - V_88 ) ) {
V_43 = ( V_83 [ V_19 ] . V_43 - V_87 ) ;
#ifdef F_30
F_3 ( V_13 L_32
L_33 , V_19 ,
& V_83 [ V_19 ] , V_83 [ V_19 ] . V_43 , V_83 [ V_19 ] . V_96 , V_20 ,
V_84 [ V_20 ] . V_43 ) ;
F_3 ( V_13 L_34
L_35 , V_43 , V_87 ,
V_88 ) ;
#endif
if ( V_43 > V_81 -> V_95 )
V_43 = V_81 -> V_95 ;
V_85 = F_31 ( & V_83 [ V_19 ++ ] ) + V_87 ;
if ( ! V_85 )
F_32 () ;
V_86 = F_31 ( & V_84 [ V_20 ] ) + V_88 ;
if ( ! V_86 )
F_32 () ;
V_87 = 0 ;
V_88 = V_43 ;
V_89 = 0 ;
} else {
V_43 = ( V_84 [ V_20 ] . V_43 - V_88 ) ;
#ifdef F_30
F_3 ( V_13 L_36
L_33 , V_19 ,
& V_83 [ V_19 ] , V_83 [ V_19 ] . V_43 , V_83 [ V_19 ] . V_96 ,
V_20 , V_84 [ V_20 ] . V_43 ) ;
F_3 ( V_13 L_37
L_35 , V_43 , V_87 ,
V_88 ) ;
#endif
if ( V_43 > V_81 -> V_95 )
V_43 = V_81 -> V_95 ;
V_85 = F_31 ( & V_83 [ V_19 ] ) + V_87 ;
if ( ! V_85 )
F_32 () ;
if ( V_83 [ V_19 ] . V_43 == V_43 ) {
V_19 ++ ;
V_87 = 0 ;
} else
V_87 = V_43 ;
V_86 = F_31 ( & V_84 [ V_20 ++ ] ) + V_88 ;
if ( ! V_86 )
F_32 () ;
V_88 = 0 ;
V_89 = 1 ;
}
memcpy ( V_85 , V_86 , V_43 ) ;
#ifdef F_30
F_3 ( V_13 L_38
L_39 , V_81 -> V_92 ,
( V_81 -> V_95 - V_43 ) , V_43 , V_19 , V_20 ) ;
#endif
V_81 -> V_95 -= V_43 ;
if ( ! ( V_81 -> V_95 ) )
return 0 ;
if ( ! V_89 )
continue;
if ( ++ V_81 -> V_92 <= V_82 -> V_42 ) {
#ifdef F_30
F_3 ( V_13 L_40 ,
V_81 -> V_92 ) ;
#endif
continue;
}
#ifdef F_30
F_3 ( V_13 L_41 ,
V_81 -> V_92 ) ;
#endif
V_82 = F_28 ( V_50 , V_81 -> V_92 ) ;
if ( ! ( V_82 ) )
return - 1 ;
V_84 = & V_82 -> V_24 [ V_20 = 0 ] ;
}
return 0 ;
}
static int F_33 ( struct V_73 * V_81 )
{
struct V_74 * V_75 = & V_81 -> V_76 ;
struct V_18 * V_50 = V_81 -> V_18 ;
struct V_23 * V_82 ;
struct V_27 * V_83 , * V_84 ;
void * V_85 , * V_86 ;
T_1 V_19 = 0 , V_20 = 0 , V_87 = 0 , V_88 = 0 ;
T_1 V_43 , V_89 = 0 , V_90 ;
T_1 V_91 = V_81 -> V_91 ;
V_82 = F_28 ( V_50 , V_81 -> V_92 ) ;
if ( ! ( V_82 ) )
return - 1 ;
V_90 = ( V_82 -> V_42 - V_81 -> V_92 ) ;
V_83 = & V_82 -> V_24 [ V_81 -> V_92 - V_82 -> V_41 ] ;
V_84 = V_75 -> V_93 ;
#ifdef F_30
F_3 ( V_13 L_42
L_43 , V_50 -> V_32 , V_75 -> V_94 , V_81 -> V_95 ,
V_81 -> V_92 , V_81 -> V_91 ) ;
#endif
V_87 = V_91 ;
while ( V_81 -> V_95 ) {
if ( ( V_84 [ V_19 ] . V_43 - V_88 ) <
( V_83 [ V_20 ] . V_43 - V_87 ) ) {
V_43 = ( V_84 [ V_19 ] . V_43 - V_88 ) ;
#ifdef F_30
F_3 ( V_13 L_44
L_45 , V_19 ,
& V_84 [ V_19 ] , V_84 [ V_19 ] . V_43 , V_84 [ V_19 ] . V_96 ,
V_20 , V_83 [ V_20 ] . V_43 ) ;
F_3 ( V_13 L_46
L_47 , V_43 , V_88 ,
V_87 ) ;
#endif
if ( V_43 > V_81 -> V_95 )
V_43 = V_81 -> V_95 ;
V_86 = F_31 ( & V_84 [ V_19 ++ ] ) + V_88 ;
if ( ! V_86 )
F_32 () ;
V_85 = F_31 ( & V_83 [ V_20 ] ) + V_87 ;
if ( ! V_85 )
F_32 () ;
V_88 = 0 ;
V_87 = V_43 ;
V_89 = 0 ;
} else {
V_43 = ( V_83 [ V_20 ] . V_43 - V_87 ) ;
#ifdef F_30
F_3 ( V_13 L_48
L_45 , V_19 ,
& V_84 [ V_19 ] , V_84 [ V_19 ] . V_43 , V_84 [ V_19 ] . V_96 ,
V_20 , V_83 [ V_20 ] . V_43 ) ;
F_3 ( V_13 L_49
L_47 , V_43 , V_88 ,
V_87 ) ;
#endif
if ( V_43 > V_81 -> V_95 )
V_43 = V_81 -> V_95 ;
V_86 = F_31 ( & V_84 [ V_19 ] ) + V_88 ;
if ( ! V_86 )
F_32 () ;
if ( V_84 [ V_19 ] . V_43 == V_43 ) {
V_19 ++ ;
V_88 = 0 ;
} else
V_88 = V_43 ;
V_85 = F_31 ( & V_83 [ V_20 ++ ] ) + V_87 ;
if ( ! V_85 )
F_32 () ;
V_87 = 0 ;
V_89 = 1 ;
}
memcpy ( V_85 , V_86 , V_43 ) ;
#ifdef F_30
F_3 ( V_13 L_38
L_39 , V_81 -> V_92 ,
( V_81 -> V_95 - V_43 ) , V_43 , V_19 , V_20 ) ;
#endif
V_81 -> V_95 -= V_43 ;
if ( ! ( V_81 -> V_95 ) )
return 0 ;
if ( ! V_89 )
continue;
if ( ++ V_81 -> V_92 <= V_82 -> V_42 ) {
#ifdef F_30
F_3 ( V_13 L_40 ,
V_81 -> V_92 ) ;
#endif
continue;
}
#ifdef F_30
F_3 ( V_13 L_41 ,
V_81 -> V_92 ) ;
#endif
V_82 = F_28 ( V_50 , V_81 -> V_92 ) ;
if ( ! ( V_82 ) )
return - 1 ;
V_83 = & V_82 -> V_24 [ V_20 = 0 ] ;
}
return 0 ;
}
static int F_34 ( struct V_74 * V_75 )
{
struct V_46 * V_50 = V_75 -> V_48 ;
struct V_73 * V_81 = F_24 ( V_75 ) ;
unsigned long long V_97 ;
int V_54 ;
V_81 -> V_92 = ( V_75 -> V_94 * F_35 ( V_50 ) -> V_98 ) / V_33 ;
V_97 = V_75 -> V_94 ;
V_81 -> V_91 = ( F_36 ( V_97 ,
( V_33 / F_35 ( V_50 ) -> V_98 ) ) ) *
F_35 ( V_50 ) -> V_98 ;
V_81 -> V_95 = V_75 -> V_99 ;
if ( V_75 -> V_100 == V_101 )
V_54 = F_29 ( V_81 ) ;
else
V_54 = F_33 ( V_81 ) ;
if ( V_54 != 0 )
return V_54 ;
V_75 -> V_102 = V_103 ;
F_37 ( V_75 , 1 ) ;
return V_104 ;
}
static int F_38 (
struct V_74 * V_75 ,
struct V_105 * V_106 ,
T_1 * V_107 ,
T_1 * V_108 )
{
struct V_73 * V_81 = F_24 ( V_75 ) ;
struct V_18 * V_50 = V_81 -> V_18 ;
struct V_23 * V_82 ;
struct V_109 * V_109 ;
struct V_27 * V_84 ;
T_1 V_20 = 0 , V_110 = 1 ;
T_1 V_111 = 0 , V_112 , V_90 ;
V_82 = F_28 ( V_50 , V_81 -> V_92 ) ;
if ( ! ( V_82 ) )
return - 1 ;
V_90 = ( V_82 -> V_42 - V_81 -> V_92 ) ;
V_84 = & V_82 -> V_24 [ V_81 -> V_92 - V_82 -> V_41 ] ;
#ifdef F_39
F_3 ( V_13 L_50 ,
( V_75 -> V_100 == V_113 ) ?
L_51 : L_52 ,
V_75 -> V_94 , V_81 -> V_95 , V_81 -> V_92 , V_81 -> V_91 ) ;
#endif
while ( V_81 -> V_95 ) {
V_109 = F_40 ( V_114 , V_5 ) ;
if ( ! ( V_109 ) ) {
F_3 ( V_6 L_53 ) ;
return - 1 ;
}
F_41 ( & V_109 -> V_115 ) ;
if ( V_110 ) {
V_112 = V_84 [ V_20 ] . V_43 - V_81 -> V_91 ;
if ( V_112 > V_81 -> V_95 )
V_112 = V_81 -> V_95 ;
V_109 -> V_116 = F_9 ( & V_84 [ V_20 ++ ] ) ;
V_109 -> V_117 = V_81 -> V_91 ;
V_109 -> V_118 = V_112 ;
V_110 = 0 ;
V_111 = ( V_20 > V_90 ) ;
goto V_119;
}
V_112 = ( V_81 -> V_95 < V_81 -> V_91 ) ?
V_81 -> V_95 : V_81 -> V_91 ;
V_109 -> V_116 = F_9 ( & V_84 [ V_20 ] ) ;
V_109 -> V_118 = V_112 ;
V_110 = 1 ;
V_119:
#ifdef F_39
F_3 ( V_13 L_54
L_55 ,
V_81 -> V_92 , V_81 -> V_95 , V_112 , V_20 , V_109 ,
V_109 -> V_116 , V_109 -> V_117 , V_109 -> V_118 ) ;
#endif
F_42 ( & V_109 -> V_115 , V_106 ) ;
( * V_107 ) ++ ;
V_81 -> V_95 -= V_112 ;
if ( ! ( V_81 -> V_95 ) )
goto V_120;
if ( ! V_110 && ! V_111 )
continue;
if ( ++ V_81 -> V_92 <= V_82 -> V_42 ) {
#ifdef F_39
F_3 ( V_13 L_40 ,
V_81 -> V_92 ) ;
#endif
continue;
}
#ifdef F_39
F_3 ( V_13 L_41 ,
V_81 -> V_92 ) ;
#endif
V_82 = F_28 ( V_50 , V_81 -> V_92 ) ;
if ( ! ( V_82 ) )
return - 1 ;
V_84 = & V_82 -> V_24 [ V_20 = 0 ] ;
}
V_120:
F_43 ( V_75 -> V_121 ) -> V_122 += * V_107 ;
#ifdef F_39
F_3 ( V_13 L_56 ,
* V_107 ) ;
#endif
return 0 ;
}
static int F_44 (
struct V_74 * V_75 ,
struct V_105 * V_106 ,
T_1 * V_107 ,
T_1 * V_108 )
{
struct V_73 * V_81 = F_24 ( V_75 ) ;
struct V_18 * V_50 = V_81 -> V_18 ;
struct V_23 * V_82 ;
struct V_109 * V_109 ;
struct V_27 * V_84 ;
T_1 V_43 , V_20 = 0 ;
V_82 = F_28 ( V_50 , V_81 -> V_92 ) ;
if ( ! ( V_82 ) )
return - 1 ;
V_84 = & V_82 -> V_24 [ V_81 -> V_92 - V_82 -> V_41 ] ;
#ifdef F_39
F_3 ( V_13 L_57 ,
( V_75 -> V_100 == V_113 ) ?
L_51 : L_52 ,
V_75 -> V_94 , V_81 -> V_95 , V_81 -> V_92 ) ;
#endif
while ( V_81 -> V_95 ) {
V_109 = F_40 ( V_114 , V_5 ) ;
if ( ! ( V_109 ) ) {
F_3 ( V_6 L_53 ) ;
return - 1 ;
}
F_41 ( & V_109 -> V_115 ) ;
V_43 = ( V_81 -> V_95 < V_84 [ V_20 ] . V_43 ) ?
V_81 -> V_95 : V_84 [ V_20 ] . V_43 ;
V_109 -> V_116 = F_9 ( & V_84 [ V_20 ++ ] ) ;
V_109 -> V_118 = V_43 ;
#ifdef F_39
F_3 ( V_13 L_58
L_59 , V_81 -> V_92 ,
V_81 -> V_95 , V_20 , V_109 , V_109 -> V_116 ,
V_109 -> V_117 , V_109 -> V_118 ) ;
#endif
F_42 ( & V_109 -> V_115 , V_106 ) ;
( * V_107 ) ++ ;
V_81 -> V_95 -= V_43 ;
if ( ! ( V_81 -> V_95 ) )
goto V_120;
if ( ++ V_81 -> V_92 <= V_82 -> V_42 ) {
#ifdef F_39
F_3 ( L_40 ,
V_81 -> V_92 ) ;
#endif
continue;
}
#ifdef F_39
F_3 ( V_13 L_41 ,
V_81 -> V_92 ) ;
#endif
V_82 = F_28 ( V_50 , V_81 -> V_92 ) ;
if ( ! ( V_82 ) )
return - 1 ;
V_84 = & V_82 -> V_24 [ V_20 = 0 ] ;
}
V_120:
F_43 ( V_75 -> V_121 ) -> V_122 += * V_107 ;
#ifdef F_39
F_3 ( V_13 L_56 ,
* V_107 ) ;
#endif
return 0 ;
}
static int F_45 (
struct V_74 * V_75 ,
struct V_105 * V_106 ,
void * V_123 ,
struct V_109 * V_124 ,
struct V_109 * * V_125 ,
T_1 * V_107 ,
T_1 * V_126 )
{
struct V_77 * V_78 = V_75 -> V_121 ;
struct V_73 * V_81 = F_24 ( V_75 ) ;
T_1 V_108 = * V_126 ;
unsigned long long V_97 ;
int V_54 ;
V_81 -> V_92 = ( ( V_75 -> V_94 * F_35 ( V_75 -> V_48 ) -> V_98 ) /
V_33 ) ;
V_97 = V_75 -> V_94 ;
V_81 -> V_91 = ( F_36 ( V_97 ,
( V_33 / F_35 ( V_75 -> V_48 ) -> V_98 ) ) ) *
F_35 ( V_75 -> V_48 ) -> V_98 ;
V_81 -> V_95 = V_75 -> V_99 ;
if ( V_81 -> V_91 )
V_54 = F_38 ( V_75 , V_106 , V_107 ,
V_126 ) ;
else
V_54 = F_44 ( V_75 , V_106 , V_107 ,
V_126 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( F_46 ( V_78 ) -> V_127 == 0 )
return 0 ;
if ( V_78 -> V_128 == V_113 ) {
F_3 ( V_6 L_60
L_61 ) ;
return - 1 ;
}
if ( ! ( F_47 ( V_75 ,
F_48 ( F_43 ( V_78 ) -> V_129 -> V_130 ,
struct V_109 , V_115 ) ,
V_108 ) ) )
return - 1 ;
return F_49 ( V_75 , V_106 , V_75 -> V_93 ,
F_48 ( F_43 ( V_78 ) -> V_129 -> V_130 ,
struct V_109 , V_115 ) ,
V_125 , V_107 , V_126 ) ;
}
static int F_50 ( struct V_74 * V_75 )
{
V_75 -> V_102 = V_103 ;
F_37 ( V_75 , 1 ) ;
return V_104 ;
}
static void F_51 ( struct V_74 * V_75 )
{
F_7 ( F_24 ( V_75 ) ) ;
}
static T_2 F_52 (
struct V_1 * V_2 ,
struct V_47 * V_48 ,
const char * V_25 ,
T_2 V_131 )
{
struct V_18 * V_18 = V_48 -> V_132 ;
char * V_133 , * V_134 , * V_135 ;
T_3 args [ V_136 ] ;
int V_54 = 0 , V_137 , V_138 ;
V_135 = F_53 ( V_25 , V_5 ) ;
if ( ! V_135 )
return - V_7 ;
V_133 = V_135 ;
while ( ( V_134 = F_54 ( & V_135 , L_62 ) ) != NULL ) {
if ( ! * V_134 )
continue;
V_138 = F_55 ( V_134 , V_139 , args ) ;
switch ( V_138 ) {
case V_140 :
F_56 ( args , & V_137 ) ;
V_18 -> V_39 = V_137 ;
F_3 ( V_13 L_63
L_64 , V_18 -> V_39 ) ;
V_18 -> V_141 |= V_142 ;
break;
default:
break;
}
}
F_7 ( V_133 ) ;
return ( ! V_54 ) ? V_131 : V_54 ;
}
static T_2 F_57 ( struct V_1 * V_2 , struct V_47 * V_48 )
{
struct V_18 * V_18 = V_48 -> V_132 ;
if ( ! ( V_18 -> V_141 & V_142 ) ) {
F_3 ( V_13 L_65 ) ;
return - 1 ;
}
return 0 ;
}
static T_2 F_58 (
struct V_1 * V_2 ,
struct V_47 * V_48 ,
char * V_143 )
{
struct V_18 * V_18 = V_48 -> V_132 ;
T_2 V_144 = sprintf ( V_143 , L_66 ,
V_18 -> V_32 , ( V_18 -> V_45 ) ?
L_67 : L_68 ) ;
V_144 += sprintf ( V_143 + V_144 , L_69
L_70 , V_18 -> V_39 ,
V_33 , V_18 -> V_30 ) ;
return V_144 ;
}
static unsigned char * F_59 ( struct V_74 * V_75 )
{
struct V_73 * V_81 = F_24 ( V_75 ) ;
return V_81 -> V_145 ;
}
static T_1 F_60 ( struct V_46 * V_50 )
{
return V_146 ;
}
static T_1 F_61 ( struct V_46 * V_50 )
{
return V_147 ;
}
static T_4 F_62 ( struct V_46 * V_50 )
{
struct V_18 * V_18 = V_50 -> V_80 ;
unsigned long long V_148 = ( ( V_18 -> V_39 * V_33 ) /
F_35 ( V_50 ) -> V_98 ) - 1 ;
return V_148 ;
}
int T_5 F_63 ( void )
{
int V_54 ;
V_54 = F_64 ( & V_69 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_64 ( & V_70 ) ;
if ( V_54 < 0 ) {
F_65 ( & V_69 ) ;
return V_54 ;
}
return 0 ;
}
void F_66 ( void )
{
F_65 ( & V_69 ) ;
F_65 ( & V_70 ) ;
}
