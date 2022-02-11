static inline int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
T_1 V_4 = F_2 ( & V_2 -> V_5 -> V_6 ) ;
return sizeof( struct V_7 ) +
( ( V_3 + V_2 -> V_8 - 1 ) / V_2 -> V_8 ) *
V_4 ;
}
static struct V_9 * F_3 ( struct V_10 * V_11 ,
T_2 V_12 , T_3 V_13 )
{
int V_14 ;
V_14 = F_4 ( V_11 ) ;
return F_5 ( V_11 , V_12 >> 9 , V_14 , V_13 ) ;
}
static int F_6 ( struct V_15 * V_15 ,
struct V_7 * V_16 ,
T_2 V_17 )
{
int V_18 ;
struct V_1 * V_2 = F_7 ( V_15 ) -> V_2 ;
struct V_19 * V_19 ;
unsigned long V_20 ;
char * V_21 ;
T_4 V_22 ;
T_4 * V_23 = & V_16 -> V_24 ;
if ( F_7 ( V_15 ) -> V_25 & V_26 )
return 0 ;
for ( V_20 = 0 ; V_20 < V_16 -> V_27 ; V_20 ++ ) {
V_19 = V_16 -> V_28 [ V_20 ] ;
V_22 = ~ ( T_4 ) 0 ;
V_21 = F_8 ( V_19 , V_29 ) ;
V_22 = F_9 ( V_2 , V_21 , V_22 , V_30 ) ;
F_10 ( V_22 , ( char * ) & V_22 ) ;
F_11 ( V_21 , V_29 ) ;
if ( V_22 != * V_23 ) {
F_12 ( V_31 L_1
L_2
L_3 ,
( unsigned long long ) F_13 ( V_15 ) ,
( unsigned long long ) V_17 ,
V_22 , * V_23 , V_16 -> V_32 ) ;
V_18 = - V_33 ;
goto V_34;
}
V_23 ++ ;
}
V_18 = 0 ;
V_34:
return V_18 ;
}
static void F_14 ( struct V_9 * V_9 , int V_35 )
{
struct V_7 * V_16 = V_9 -> V_36 ;
struct V_15 * V_15 ;
struct V_19 * V_19 ;
unsigned long V_37 ;
int V_18 ;
if ( V_35 )
V_16 -> V_38 = 1 ;
if ( ! F_15 ( & V_16 -> V_39 ) )
goto V_40;
V_15 = V_16 -> V_15 ;
V_18 = F_6 ( V_15 , V_16 , ( T_2 ) V_9 -> V_41 << 9 ) ;
if ( V_18 )
goto V_42;
V_18 = F_16 ( V_16 -> V_43 ,
V_16 -> V_28 ,
V_16 -> V_44 ,
V_16 -> V_45 -> V_46 ,
V_16 -> V_45 -> V_47 ,
V_16 -> V_48 ) ;
V_42:
if ( V_18 )
V_16 -> V_38 = 1 ;
V_37 = 0 ;
for ( V_37 = 0 ; V_37 < V_16 -> V_27 ; V_37 ++ ) {
V_19 = V_16 -> V_28 [ V_37 ] ;
V_19 -> V_49 = NULL ;
F_17 ( V_19 ) ;
}
if ( V_16 -> V_38 ) {
F_18 ( V_16 -> V_45 ) ;
} else {
int V_50 = 0 ;
struct V_51 * V_52 = V_16 -> V_45 -> V_46 ;
while ( V_50 < V_16 -> V_45 -> V_47 ) {
F_19 ( V_52 -> V_53 ) ;
V_52 ++ ;
V_50 ++ ;
}
F_20 ( V_16 -> V_45 , 0 ) ;
}
F_21 ( V_16 -> V_28 ) ;
F_21 ( V_16 ) ;
V_40:
F_22 ( V_9 ) ;
}
static T_5 int F_23 ( struct V_15 * V_15 , T_2 V_44 ,
unsigned long V_54 )
{
unsigned long V_37 = V_44 >> V_55 ;
unsigned long V_56 = ( V_44 + V_54 - 1 ) >> V_55 ;
struct V_19 * V_57 [ 16 ] ;
unsigned long V_27 = V_56 - V_37 + 1 ;
int V_20 ;
int V_18 ;
while ( V_27 > 0 ) {
V_18 = F_24 ( V_15 -> V_58 , V_37 ,
F_25 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_57 ) ;
if ( V_18 == 0 ) {
V_27 -= 1 ;
V_37 += 1 ;
continue;
}
for ( V_20 = 0 ; V_20 < V_18 ; V_20 ++ ) {
F_26 ( V_57 [ V_20 ] ) ;
F_17 ( V_57 [ V_20 ] ) ;
}
V_27 -= V_18 ;
V_37 += V_18 ;
}
return 0 ;
}
static void F_27 ( struct V_9 * V_9 , int V_35 )
{
struct V_59 * V_60 ;
struct V_7 * V_16 = V_9 -> V_36 ;
struct V_15 * V_15 ;
struct V_19 * V_19 ;
unsigned long V_37 ;
if ( V_35 )
V_16 -> V_38 = 1 ;
if ( ! F_15 ( & V_16 -> V_39 ) )
goto V_40;
V_15 = V_16 -> V_15 ;
V_60 = & F_7 ( V_15 ) -> V_61 ;
V_16 -> V_28 [ 0 ] -> V_49 = V_16 -> V_15 -> V_58 ;
V_60 -> V_62 -> V_63 ( V_16 -> V_28 [ 0 ] ,
V_16 -> V_44 ,
V_16 -> V_44 + V_16 -> V_64 - 1 ,
NULL , 1 ) ;
V_16 -> V_28 [ 0 ] -> V_49 = NULL ;
F_23 ( V_15 , V_16 -> V_44 , V_16 -> V_64 ) ;
V_37 = 0 ;
for ( V_37 = 0 ; V_37 < V_16 -> V_27 ; V_37 ++ ) {
V_19 = V_16 -> V_28 [ V_37 ] ;
V_19 -> V_49 = NULL ;
F_17 ( V_19 ) ;
}
F_21 ( V_16 -> V_28 ) ;
F_21 ( V_16 ) ;
V_40:
F_22 ( V_9 ) ;
}
int F_28 ( struct V_15 * V_15 , T_2 V_44 ,
unsigned long V_64 , T_2 V_17 ,
unsigned long V_48 ,
struct V_19 * * V_28 ,
unsigned long V_27 )
{
struct V_9 * V_9 = NULL ;
struct V_1 * V_2 = F_7 ( V_15 ) -> V_2 ;
struct V_7 * V_16 ;
unsigned long V_65 ;
struct V_59 * V_61 = & F_7 ( V_15 ) -> V_61 ;
int V_66 = 0 ;
struct V_19 * V_19 ;
T_2 V_12 = V_17 ;
struct V_10 * V_11 ;
int V_18 ;
F_29 ( V_44 & ( ( T_2 ) V_30 - 1 ) ) ;
V_16 = F_30 ( F_1 ( V_2 , V_48 ) , V_67 ) ;
if ( ! V_16 )
return - V_68 ;
F_31 ( & V_16 -> V_39 , 0 ) ;
V_16 -> V_38 = 0 ;
V_16 -> V_15 = V_15 ;
V_16 -> V_44 = V_44 ;
V_16 -> V_64 = V_64 ;
V_16 -> V_32 = 0 ;
V_16 -> V_28 = V_28 ;
V_16 -> V_48 = V_48 ;
V_16 -> V_45 = NULL ;
V_16 -> V_27 = V_27 ;
V_11 = F_7 ( V_15 ) -> V_2 -> V_5 -> V_69 -> V_70 ;
V_9 = F_3 ( V_11 , V_12 , V_67 ) ;
if( ! V_9 ) {
F_21 ( V_16 ) ;
return - V_68 ;
}
V_9 -> V_36 = V_16 ;
V_9 -> V_71 = F_27 ;
F_32 ( & V_16 -> V_39 ) ;
V_65 = V_48 ;
for ( V_66 = 0 ; V_66 < V_16 -> V_27 ; V_66 ++ ) {
V_19 = V_28 [ V_66 ] ;
V_19 -> V_49 = V_15 -> V_58 ;
if ( V_9 -> V_72 )
V_18 = V_61 -> V_62 -> V_73 ( V_19 , 0 ,
V_30 ,
V_9 , 0 ) ;
else
V_18 = 0 ;
V_19 -> V_49 = NULL ;
if ( V_18 || F_33 ( V_9 , V_19 , V_30 , 0 ) <
V_30 ) {
F_34 ( V_9 ) ;
F_32 ( & V_16 -> V_39 ) ;
V_18 = F_35 ( V_2 -> V_5 , V_9 , 0 ) ;
F_36 ( V_18 ) ;
V_18 = F_37 ( V_2 , V_15 , V_9 , V_44 , 1 ) ;
F_36 ( V_18 ) ;
V_18 = F_38 ( V_2 , V_74 , V_9 , 0 , 1 ) ;
F_36 ( V_18 ) ;
F_22 ( V_9 ) ;
V_9 = F_3 ( V_11 , V_12 , V_67 ) ;
V_9 -> V_36 = V_16 ;
V_9 -> V_71 = F_27 ;
F_33 ( V_9 , V_19 , V_30 , 0 ) ;
}
if ( V_65 < V_30 ) {
F_12 ( L_4 ,
V_65 , V_16 -> V_48 , V_16 -> V_27 ) ;
}
V_65 -= V_30 ;
V_12 += V_30 ;
F_39 () ;
}
F_34 ( V_9 ) ;
V_18 = F_35 ( V_2 -> V_5 , V_9 , 0 ) ;
F_36 ( V_18 ) ;
V_18 = F_37 ( V_2 , V_15 , V_9 , V_44 , 1 ) ;
F_36 ( V_18 ) ;
V_18 = F_38 ( V_2 , V_74 , V_9 , 0 , 1 ) ;
F_36 ( V_18 ) ;
F_22 ( V_9 ) ;
return 0 ;
}
static T_5 int F_40 ( struct V_15 * V_15 ,
T_2 V_75 ,
struct V_7 * V_16 )
{
unsigned long V_56 ;
unsigned long V_66 ;
T_2 V_76 ;
T_2 V_77 = F_41 ( V_15 ) ;
int V_18 ;
struct V_19 * V_19 ;
unsigned long V_27 = 0 ;
struct V_78 * V_79 ;
struct V_80 * V_49 = V_15 -> V_58 ;
struct V_81 * V_82 ;
struct V_59 * V_60 ;
T_2 V_83 ;
int V_84 = 0 ;
V_19 = V_16 -> V_45 -> V_46 [ V_16 -> V_45 -> V_47 - 1 ] . V_53 ;
V_76 = ( F_42 ( V_19 ) + V_30 ) ;
V_82 = & F_7 ( V_15 ) -> V_85 ;
V_60 = & F_7 ( V_15 ) -> V_61 ;
if ( V_77 == 0 )
return 0 ;
V_56 = ( F_41 ( V_15 ) - 1 ) >> V_55 ;
while ( V_76 < V_75 ) {
V_66 = V_76 >> V_55 ;
if ( V_66 > V_56 )
break;
F_43 () ;
V_19 = F_44 ( & V_49 -> V_86 , V_66 ) ;
F_45 () ;
if ( V_19 ) {
V_84 ++ ;
if ( V_84 > 4 )
break;
goto V_87;
}
V_19 = F_46 ( F_47 ( V_49 ) &
~ V_88 ) ;
if ( ! V_19 )
break;
if ( F_48 ( V_19 , V_49 , V_66 ,
V_67 ) ) {
F_17 ( V_19 ) ;
goto V_87;
}
V_83 = V_76 + V_30 - 1 ;
F_49 ( V_19 ) ;
F_50 ( V_60 , V_76 , V_83 , V_67 ) ;
F_51 ( & V_82 -> V_89 ) ;
V_79 = F_52 ( V_82 , V_76 ,
V_30 ) ;
F_53 ( & V_82 -> V_89 ) ;
if ( ! V_79 || V_76 < V_79 -> V_44 ||
( V_76 + V_30 > F_54 ( V_79 ) ) ||
( V_79 -> V_90 >> 9 ) != V_16 -> V_45 -> V_41 ) {
F_55 ( V_79 ) ;
F_56 ( V_60 , V_76 , V_83 , V_67 ) ;
F_57 ( V_19 ) ;
F_17 ( V_19 ) ;
break;
}
F_55 ( V_79 ) ;
if ( V_19 -> V_37 == V_56 ) {
char * V_91 ;
T_6 V_92 = V_77 & ( V_30 - 1 ) ;
if ( V_92 ) {
int V_93 ;
V_93 = V_30 - V_92 ;
V_91 = F_8 ( V_19 , V_29 ) ;
memset ( V_91 + V_92 , 0 , V_93 ) ;
F_58 ( V_19 ) ;
F_11 ( V_91 , V_29 ) ;
}
}
V_18 = F_33 ( V_16 -> V_45 , V_19 ,
V_30 , 0 ) ;
if ( V_18 == V_30 ) {
V_27 ++ ;
F_17 ( V_19 ) ;
} else {
F_56 ( V_60 , V_76 , V_83 , V_67 ) ;
F_57 ( V_19 ) ;
F_17 ( V_19 ) ;
break;
}
V_87:
V_76 += V_30 ;
}
return 0 ;
}
int F_59 ( struct V_15 * V_15 , struct V_9 * V_9 ,
int V_32 , unsigned long V_94 )
{
struct V_59 * V_60 ;
struct V_81 * V_82 ;
struct V_7 * V_16 ;
struct V_1 * V_2 = F_7 ( V_15 ) -> V_2 ;
unsigned long V_95 = V_9 -> V_47 * V_30 ;
unsigned long V_48 ;
unsigned long V_27 ;
unsigned long V_66 ;
struct V_19 * V_19 ;
struct V_10 * V_11 ;
struct V_9 * V_96 ;
T_2 V_97 = ( T_2 ) V_9 -> V_41 << 9 ;
T_2 V_98 ;
T_2 V_99 ;
struct V_78 * V_79 ;
int V_18 = - V_68 ;
T_4 * V_24 ;
V_60 = & F_7 ( V_15 ) -> V_61 ;
V_82 = & F_7 ( V_15 ) -> V_85 ;
F_51 ( & V_82 -> V_89 ) ;
V_79 = F_52 ( V_82 ,
F_42 ( V_9 -> V_46 -> V_53 ) ,
V_30 ) ;
F_53 ( & V_82 -> V_89 ) ;
V_48 = V_79 -> V_100 ;
V_16 = F_30 ( F_1 ( V_2 , V_48 ) , V_67 ) ;
if ( ! V_16 )
goto V_40;
F_31 ( & V_16 -> V_39 , 0 ) ;
V_16 -> V_38 = 0 ;
V_16 -> V_15 = V_15 ;
V_16 -> V_32 = V_32 ;
V_24 = & V_16 -> V_24 ;
V_16 -> V_44 = V_79 -> V_101 ;
V_98 = V_79 -> V_64 ;
V_99 = V_79 -> V_44 ;
F_55 ( V_79 ) ;
V_79 = NULL ;
V_16 -> V_64 = V_95 ;
V_16 -> V_48 = V_48 ;
V_16 -> V_43 = F_60 ( V_94 ) ;
V_16 -> V_45 = V_9 ;
V_27 = ( V_48 + V_30 - 1 ) /
V_30 ;
V_16 -> V_28 = F_61 ( sizeof( struct V_19 * ) * V_27 ,
V_67 ) ;
if ( ! V_16 -> V_28 )
goto V_102;
V_11 = F_7 ( V_15 ) -> V_2 -> V_5 -> V_69 -> V_70 ;
for ( V_66 = 0 ; V_66 < V_27 ; V_66 ++ ) {
V_16 -> V_28 [ V_66 ] = F_62 ( V_67 |
V_103 ) ;
if ( ! V_16 -> V_28 [ V_66 ] )
goto V_104;
}
V_16 -> V_27 = V_27 ;
F_40 ( V_15 , V_99 + V_98 , V_16 ) ;
V_95 = V_9 -> V_47 * V_30 ;
V_16 -> V_64 = V_95 ;
V_96 = F_3 ( V_11 , V_97 , V_67 ) ;
if ( ! V_96 )
goto V_104;
V_96 -> V_36 = V_16 ;
V_96 -> V_71 = F_14 ;
F_32 ( & V_16 -> V_39 ) ;
for ( V_66 = 0 ; V_66 < V_27 ; V_66 ++ ) {
V_19 = V_16 -> V_28 [ V_66 ] ;
V_19 -> V_49 = V_15 -> V_58 ;
V_19 -> V_37 = V_99 >> V_55 ;
if ( V_96 -> V_72 )
V_18 = V_60 -> V_62 -> V_73 ( V_19 , 0 ,
V_30 ,
V_96 , 0 ) ;
else
V_18 = 0 ;
V_19 -> V_49 = NULL ;
if ( V_18 || F_33 ( V_96 , V_19 , V_30 , 0 ) <
V_30 ) {
F_34 ( V_96 ) ;
V_18 = F_35 ( V_2 -> V_5 , V_96 , 0 ) ;
F_36 ( V_18 ) ;
F_32 ( & V_16 -> V_39 ) ;
if ( ! ( F_7 ( V_15 ) -> V_25 & V_26 ) ) {
V_18 = F_63 ( V_2 , V_15 ,
V_96 , V_24 ) ;
F_36 ( V_18 ) ;
}
V_24 += ( V_96 -> V_72 + V_2 -> V_8 - 1 ) /
V_2 -> V_8 ;
V_18 = F_38 ( V_2 , V_105 , V_96 ,
V_32 , 0 ) ;
F_36 ( V_18 ) ;
F_22 ( V_96 ) ;
V_96 = F_3 ( V_11 , V_97 ,
V_67 ) ;
V_96 -> V_36 = V_16 ;
V_96 -> V_71 = F_14 ;
F_33 ( V_96 , V_19 , V_30 , 0 ) ;
}
V_97 += V_30 ;
}
F_34 ( V_96 ) ;
V_18 = F_35 ( V_2 -> V_5 , V_96 , 0 ) ;
F_36 ( V_18 ) ;
if ( ! ( F_7 ( V_15 ) -> V_25 & V_26 ) ) {
V_18 = F_63 ( V_2 , V_15 , V_96 , V_24 ) ;
F_36 ( V_18 ) ;
}
V_18 = F_38 ( V_2 , V_105 , V_96 , V_32 , 0 ) ;
F_36 ( V_18 ) ;
F_22 ( V_96 ) ;
return 0 ;
V_104:
for ( V_66 = 0 ; V_66 < V_27 ; V_66 ++ )
F_64 ( ( unsigned long ) V_16 -> V_28 [ V_66 ] ) ;
F_21 ( V_16 -> V_28 ) ;
V_102:
F_21 ( V_16 ) ;
V_40:
F_55 ( V_79 ) ;
return V_18 ;
}
int T_7 F_65 ( void )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_106 ; V_20 ++ ) {
F_66 ( & V_107 [ V_20 ] ) ;
F_67 ( & V_108 [ V_20 ] ) ;
F_31 ( & V_109 [ V_20 ] , 0 ) ;
F_68 ( & V_110 [ V_20 ] ) ;
}
return 0 ;
}
static struct V_111 * F_69 ( int type )
{
struct V_111 * V_112 ;
int V_113 = F_70 () ;
int V_114 = type - 1 ;
struct V_111 * V_115 = & V_107 [ V_114 ] ;
T_8 * V_116 = & V_108 [ V_114 ] ;
T_9 * V_117 = & V_109 [ V_114 ] ;
T_10 * V_118 = & V_110 [ V_114 ] ;
int * V_119 = & V_120 [ V_114 ] ;
V_121:
F_71 ( V_116 ) ;
if ( ! F_72 ( V_115 ) ) {
V_112 = V_115 -> V_87 ;
F_73 ( V_112 ) ;
( * V_119 ) -- ;
F_74 ( V_116 ) ;
return V_112 ;
}
if ( F_75 ( V_117 ) > V_113 ) {
F_76 ( V_122 ) ;
F_74 ( V_116 ) ;
F_77 ( V_118 , & V_122 , V_123 ) ;
if ( F_75 ( V_117 ) > V_113 && ! * V_119 )
F_78 () ;
F_79 ( V_118 , & V_122 ) ;
goto V_121;
}
F_32 ( V_117 ) ;
F_74 ( V_116 ) ;
V_112 = V_124 [ V_114 ] -> V_117 () ;
if ( F_80 ( V_112 ) ) {
F_81 ( V_117 ) ;
F_82 ( V_118 ) ;
}
return V_112 ;
}
static void F_83 ( int type , struct V_111 * V_112 )
{
int V_114 = type - 1 ;
struct V_111 * V_115 = & V_107 [ V_114 ] ;
T_8 * V_116 = & V_108 [ V_114 ] ;
T_9 * V_117 = & V_109 [ V_114 ] ;
T_10 * V_118 = & V_110 [ V_114 ] ;
int * V_119 = & V_120 [ V_114 ] ;
F_71 ( V_116 ) ;
if ( * V_119 < F_70 () ) {
F_84 ( V_112 , V_115 ) ;
( * V_119 ) ++ ;
F_74 ( V_116 ) ;
goto V_125;
}
F_74 ( V_116 ) ;
V_124 [ V_114 ] -> F_83 ( V_112 ) ;
F_81 ( V_117 ) ;
V_125:
if ( F_85 ( V_118 ) )
F_82 ( V_118 ) ;
}
static void F_86 ( void )
{
struct V_111 * V_112 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_106 ; V_20 ++ ) {
while ( ! F_72 ( & V_107 [ V_20 ] ) ) {
V_112 = V_107 [ V_20 ] . V_87 ;
F_73 ( V_112 ) ;
V_124 [ V_20 ] -> F_83 ( V_112 ) ;
F_81 ( & V_109 [ V_20 ] ) ;
}
}
}
int F_87 ( int type , struct V_80 * V_49 ,
T_2 V_44 , unsigned long V_64 ,
struct V_19 * * V_57 ,
unsigned long V_126 ,
unsigned long * V_127 ,
unsigned long * V_128 ,
unsigned long * V_129 ,
unsigned long V_130 )
{
struct V_111 * V_112 ;
int V_18 ;
V_112 = F_69 ( type ) ;
if ( F_80 ( V_112 ) )
return - 1 ;
V_18 = V_124 [ type - 1 ] -> F_88 ( V_112 , V_49 ,
V_44 , V_64 , V_57 ,
V_126 , V_127 ,
V_128 , V_129 ,
V_130 ) ;
F_83 ( type , V_112 ) ;
return V_18 ;
}
int F_16 ( int type , struct V_19 * * V_131 , T_2 V_17 ,
struct V_51 * V_52 , int V_132 , T_6 V_133 )
{
struct V_111 * V_112 ;
int V_18 ;
V_112 = F_69 ( type ) ;
if ( F_80 ( V_112 ) )
return - V_68 ;
V_18 = V_124 [ type - 1 ] -> F_89 ( V_112 , V_131 ,
V_17 ,
V_52 , V_132 , V_133 ) ;
F_83 ( type , V_112 ) ;
return V_18 ;
}
int F_90 ( int type , unsigned char * V_134 , struct V_19 * V_135 ,
unsigned long V_136 , T_6 V_133 , T_6 V_137 )
{
struct V_111 * V_112 ;
int V_18 ;
V_112 = F_69 ( type ) ;
if ( F_80 ( V_112 ) )
return - V_68 ;
V_18 = V_124 [ type - 1 ] -> F_91 ( V_112 , V_134 ,
V_135 , V_136 ,
V_133 , V_137 ) ;
F_83 ( type , V_112 ) ;
return V_18 ;
}
void F_92 ( void )
{
F_86 () ;
}
int F_93 ( char * V_138 , unsigned long V_139 ,
unsigned long V_129 , T_2 V_17 ,
struct V_51 * V_52 , int V_132 ,
unsigned long * V_66 ,
unsigned long * V_140 )
{
unsigned long V_141 ;
unsigned long V_142 ;
unsigned long V_136 ;
unsigned long V_143 = V_129 - V_139 ;
unsigned long V_144 ;
char * V_21 ;
struct V_19 * V_145 = V_52 [ * V_66 ] . V_53 ;
V_136 = F_42 ( V_145 ) - V_17 ;
if ( V_129 <= V_136 )
return 1 ;
if ( V_129 > V_136 && V_139 < V_136 ) {
V_141 = V_136 - V_139 ;
V_143 -= V_141 ;
} else {
V_141 = 0 ;
}
V_142 = V_139 ;
while ( V_143 > 0 ) {
V_144 = F_94 ( V_30 - * V_140 ,
V_30 - V_141 ) ;
V_144 = F_94 ( V_144 , V_143 ) ;
V_21 = F_8 ( V_145 , V_29 ) ;
memcpy ( V_21 + * V_140 , V_138 + V_141 , V_144 ) ;
F_11 ( V_21 , V_29 ) ;
F_58 ( V_145 ) ;
* V_140 += V_144 ;
V_141 += V_144 ;
V_143 -= V_144 ;
V_142 += V_144 ;
if ( * V_140 == V_30 ) {
( * V_66 ) ++ ;
if ( * V_66 >= V_132 )
return 0 ;
V_145 = V_52 [ * V_66 ] . V_53 ;
* V_140 = 0 ;
V_136 = F_42 ( V_145 ) - V_17 ;
if ( V_129 <= V_136 )
return 1 ;
if ( V_129 > V_136 &&
V_142 < V_136 ) {
V_141 = V_136 - V_139 ;
V_143 = V_129 - V_136 ;
V_142 = V_139 + V_141 ;
}
}
}
return 1 ;
}
