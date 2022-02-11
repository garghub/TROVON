static inline int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
T_1 V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
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
V_21 = F_8 ( V_19 ) ;
V_22 = F_9 ( V_2 , V_21 , V_22 , V_29 ) ;
F_10 ( V_22 , ( char * ) & V_22 ) ;
F_11 ( V_21 ) ;
if ( V_22 != * V_23 ) {
F_12 ( V_30 L_1
L_2
L_3 ,
( unsigned long long ) F_13 ( V_15 ) ,
( unsigned long long ) V_17 ,
V_22 , * V_23 , V_16 -> V_31 ) ;
V_18 = - V_32 ;
goto V_33;
}
V_23 ++ ;
}
V_18 = 0 ;
V_33:
return V_18 ;
}
static void F_14 ( struct V_9 * V_9 , int V_34 )
{
struct V_7 * V_16 = V_9 -> V_35 ;
struct V_15 * V_15 ;
struct V_19 * V_19 ;
unsigned long V_36 ;
int V_18 ;
if ( V_34 )
V_16 -> V_37 = 1 ;
if ( ! F_15 ( & V_16 -> V_38 ) )
goto V_39;
V_15 = V_16 -> V_15 ;
V_18 = F_6 ( V_15 , V_16 , ( T_2 ) V_9 -> V_40 << 9 ) ;
if ( V_18 )
goto V_41;
V_18 = F_16 ( V_16 -> V_42 ,
V_16 -> V_28 ,
V_16 -> V_43 ,
V_16 -> V_44 -> V_45 ,
V_16 -> V_44 -> V_46 ,
V_16 -> V_47 ) ;
V_41:
if ( V_18 )
V_16 -> V_37 = 1 ;
V_36 = 0 ;
for ( V_36 = 0 ; V_36 < V_16 -> V_27 ; V_36 ++ ) {
V_19 = V_16 -> V_28 [ V_36 ] ;
V_19 -> V_48 = NULL ;
F_17 ( V_19 ) ;
}
if ( V_16 -> V_37 ) {
F_18 ( V_16 -> V_44 ) ;
} else {
int V_49 = 0 ;
struct V_50 * V_51 = V_16 -> V_44 -> V_45 ;
while ( V_49 < V_16 -> V_44 -> V_46 ) {
F_19 ( V_51 -> V_52 ) ;
V_51 ++ ;
V_49 ++ ;
}
F_20 ( V_16 -> V_44 , 0 ) ;
}
F_21 ( V_16 -> V_28 ) ;
F_21 ( V_16 ) ;
V_39:
F_22 ( V_9 ) ;
}
static T_5 void F_23 ( struct V_15 * V_15 , T_2 V_43 ,
unsigned long V_53 )
{
unsigned long V_36 = V_43 >> V_54 ;
unsigned long V_55 = ( V_43 + V_53 - 1 ) >> V_54 ;
struct V_19 * V_56 [ 16 ] ;
unsigned long V_27 = V_55 - V_36 + 1 ;
int V_20 ;
int V_18 ;
while ( V_27 > 0 ) {
V_18 = F_24 ( V_15 -> V_57 , V_36 ,
F_25 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_56 ) ;
if ( V_18 == 0 ) {
V_27 -= 1 ;
V_36 += 1 ;
continue;
}
for ( V_20 = 0 ; V_20 < V_18 ; V_20 ++ ) {
F_26 ( V_56 [ V_20 ] ) ;
F_17 ( V_56 [ V_20 ] ) ;
}
V_27 -= V_18 ;
V_36 += V_18 ;
}
}
static void F_27 ( struct V_9 * V_9 , int V_34 )
{
struct V_58 * V_59 ;
struct V_7 * V_16 = V_9 -> V_35 ;
struct V_15 * V_15 ;
struct V_19 * V_19 ;
unsigned long V_36 ;
if ( V_34 )
V_16 -> V_37 = 1 ;
if ( ! F_15 ( & V_16 -> V_38 ) )
goto V_39;
V_15 = V_16 -> V_15 ;
V_59 = & F_7 ( V_15 ) -> V_60 ;
V_16 -> V_28 [ 0 ] -> V_48 = V_16 -> V_15 -> V_57 ;
V_59 -> V_61 -> V_62 ( V_16 -> V_28 [ 0 ] ,
V_16 -> V_43 ,
V_16 -> V_43 + V_16 -> V_63 - 1 ,
NULL , 1 ) ;
V_16 -> V_28 [ 0 ] -> V_48 = NULL ;
F_23 ( V_15 , V_16 -> V_43 , V_16 -> V_63 ) ;
V_36 = 0 ;
for ( V_36 = 0 ; V_36 < V_16 -> V_27 ; V_36 ++ ) {
V_19 = V_16 -> V_28 [ V_36 ] ;
V_19 -> V_48 = NULL ;
F_17 ( V_19 ) ;
}
F_21 ( V_16 -> V_28 ) ;
F_21 ( V_16 ) ;
V_39:
F_22 ( V_9 ) ;
}
int F_28 ( struct V_15 * V_15 , T_2 V_43 ,
unsigned long V_63 , T_2 V_17 ,
unsigned long V_47 ,
struct V_19 * * V_28 ,
unsigned long V_27 )
{
struct V_9 * V_9 = NULL ;
struct V_1 * V_2 = F_7 ( V_15 ) -> V_2 ;
struct V_7 * V_16 ;
unsigned long V_64 ;
struct V_58 * V_60 = & F_7 ( V_15 ) -> V_60 ;
int V_65 = 0 ;
struct V_19 * V_19 ;
T_2 V_12 = V_17 ;
struct V_10 * V_11 ;
int V_18 ;
int V_66 = F_7 ( V_15 ) -> V_25 & V_26 ;
F_29 ( V_43 & ( ( T_2 ) V_29 - 1 ) ) ;
V_16 = F_30 ( F_1 ( V_2 , V_47 ) , V_67 ) ;
if ( ! V_16 )
return - V_68 ;
F_31 ( & V_16 -> V_38 , 0 ) ;
V_16 -> V_37 = 0 ;
V_16 -> V_15 = V_15 ;
V_16 -> V_43 = V_43 ;
V_16 -> V_63 = V_63 ;
V_16 -> V_31 = 0 ;
V_16 -> V_28 = V_28 ;
V_16 -> V_47 = V_47 ;
V_16 -> V_44 = NULL ;
V_16 -> V_27 = V_27 ;
V_11 = F_7 ( V_15 ) -> V_2 -> V_5 -> V_69 -> V_70 ;
V_9 = F_3 ( V_11 , V_12 , V_67 ) ;
if( ! V_9 ) {
F_21 ( V_16 ) ;
return - V_68 ;
}
V_9 -> V_35 = V_16 ;
V_9 -> V_71 = F_27 ;
F_32 ( & V_16 -> V_38 ) ;
V_64 = V_47 ;
for ( V_65 = 0 ; V_65 < V_16 -> V_27 ; V_65 ++ ) {
V_19 = V_28 [ V_65 ] ;
V_19 -> V_48 = V_15 -> V_57 ;
if ( V_9 -> V_72 )
V_18 = V_60 -> V_61 -> V_73 ( V_19 , 0 ,
V_29 ,
V_9 , 0 ) ;
else
V_18 = 0 ;
V_19 -> V_48 = NULL ;
if ( V_18 || F_33 ( V_9 , V_19 , V_29 , 0 ) <
V_29 ) {
F_34 ( V_9 ) ;
F_32 ( & V_16 -> V_38 ) ;
V_18 = F_35 ( V_2 -> V_5 , V_9 , 0 ) ;
F_36 ( V_18 ) ;
if ( ! V_66 ) {
V_18 = F_37 ( V_2 , V_15 , V_9 ,
V_43 , 1 ) ;
F_36 ( V_18 ) ;
}
V_18 = F_38 ( V_2 , V_74 , V_9 , 0 , 1 ) ;
F_36 ( V_18 ) ;
F_22 ( V_9 ) ;
V_9 = F_3 ( V_11 , V_12 , V_67 ) ;
F_36 ( ! V_9 ) ;
V_9 -> V_35 = V_16 ;
V_9 -> V_71 = F_27 ;
F_33 ( V_9 , V_19 , V_29 , 0 ) ;
}
if ( V_64 < V_29 ) {
F_12 ( L_4 ,
V_64 , V_16 -> V_47 , V_16 -> V_27 ) ;
}
V_64 -= V_29 ;
V_12 += V_29 ;
F_39 () ;
}
F_34 ( V_9 ) ;
V_18 = F_35 ( V_2 -> V_5 , V_9 , 0 ) ;
F_36 ( V_18 ) ;
if ( ! V_66 ) {
V_18 = F_37 ( V_2 , V_15 , V_9 , V_43 , 1 ) ;
F_36 ( V_18 ) ;
}
V_18 = F_38 ( V_2 , V_74 , V_9 , 0 , 1 ) ;
F_36 ( V_18 ) ;
F_22 ( V_9 ) ;
return 0 ;
}
static T_5 int F_40 ( struct V_15 * V_15 ,
T_2 V_75 ,
struct V_7 * V_16 )
{
unsigned long V_55 ;
unsigned long V_65 ;
T_2 V_76 ;
T_2 V_77 = F_41 ( V_15 ) ;
int V_18 ;
struct V_19 * V_19 ;
unsigned long V_27 = 0 ;
struct V_78 * V_79 ;
struct V_80 * V_48 = V_15 -> V_57 ;
struct V_81 * V_82 ;
struct V_58 * V_59 ;
T_2 V_83 ;
int V_84 = 0 ;
V_19 = V_16 -> V_44 -> V_45 [ V_16 -> V_44 -> V_46 - 1 ] . V_52 ;
V_76 = ( F_42 ( V_19 ) + V_29 ) ;
V_82 = & F_7 ( V_15 ) -> V_85 ;
V_59 = & F_7 ( V_15 ) -> V_60 ;
if ( V_77 == 0 )
return 0 ;
V_55 = ( F_41 ( V_15 ) - 1 ) >> V_54 ;
while ( V_76 < V_75 ) {
V_65 = V_76 >> V_54 ;
if ( V_65 > V_55 )
break;
F_43 () ;
V_19 = F_44 ( & V_48 -> V_86 , V_65 ) ;
F_45 () ;
if ( V_19 ) {
V_84 ++ ;
if ( V_84 > 4 )
break;
goto V_87;
}
V_19 = F_46 ( F_47 ( V_48 ) &
~ V_88 ) ;
if ( ! V_19 )
break;
if ( F_48 ( V_19 , V_48 , V_65 ,
V_67 ) ) {
F_17 ( V_19 ) ;
goto V_87;
}
V_83 = V_76 + V_29 - 1 ;
F_49 ( V_19 ) ;
F_50 ( V_59 , V_76 , V_83 ) ;
F_51 ( & V_82 -> V_89 ) ;
V_79 = F_52 ( V_82 , V_76 ,
V_29 ) ;
F_53 ( & V_82 -> V_89 ) ;
if ( ! V_79 || V_76 < V_79 -> V_43 ||
( V_76 + V_29 > F_54 ( V_79 ) ) ||
( V_79 -> V_90 >> 9 ) != V_16 -> V_44 -> V_40 ) {
F_55 ( V_79 ) ;
F_56 ( V_59 , V_76 , V_83 ) ;
F_57 ( V_19 ) ;
F_17 ( V_19 ) ;
break;
}
F_55 ( V_79 ) ;
if ( V_19 -> V_36 == V_55 ) {
char * V_91 ;
T_6 V_92 = V_77 & ( V_29 - 1 ) ;
if ( V_92 ) {
int V_93 ;
V_93 = V_29 - V_92 ;
V_91 = F_8 ( V_19 ) ;
memset ( V_91 + V_92 , 0 , V_93 ) ;
F_58 ( V_19 ) ;
F_11 ( V_91 ) ;
}
}
V_18 = F_33 ( V_16 -> V_44 , V_19 ,
V_29 , 0 ) ;
if ( V_18 == V_29 ) {
V_27 ++ ;
F_17 ( V_19 ) ;
} else {
F_56 ( V_59 , V_76 , V_83 ) ;
F_57 ( V_19 ) ;
F_17 ( V_19 ) ;
break;
}
V_87:
V_76 += V_29 ;
}
return 0 ;
}
int F_59 ( struct V_15 * V_15 , struct V_9 * V_9 ,
int V_31 , unsigned long V_94 )
{
struct V_58 * V_59 ;
struct V_81 * V_82 ;
struct V_7 * V_16 ;
struct V_1 * V_2 = F_7 ( V_15 ) -> V_2 ;
unsigned long V_95 = V_9 -> V_46 * V_29 ;
unsigned long V_47 ;
unsigned long V_27 ;
unsigned long V_65 ;
struct V_19 * V_19 ;
struct V_10 * V_11 ;
struct V_9 * V_96 ;
T_2 V_97 = ( T_2 ) V_9 -> V_40 << 9 ;
T_2 V_98 ;
T_2 V_99 ;
struct V_78 * V_79 ;
int V_18 = - V_68 ;
int V_100 = 0 ;
T_4 * V_24 ;
V_59 = & F_7 ( V_15 ) -> V_60 ;
V_82 = & F_7 ( V_15 ) -> V_85 ;
F_51 ( & V_82 -> V_89 ) ;
V_79 = F_52 ( V_82 ,
F_42 ( V_9 -> V_45 -> V_52 ) ,
V_29 ) ;
F_53 ( & V_82 -> V_89 ) ;
if ( ! V_79 )
return - V_32 ;
V_47 = V_79 -> V_101 ;
V_16 = F_30 ( F_1 ( V_2 , V_47 ) , V_67 ) ;
if ( ! V_16 )
goto V_39;
F_31 ( & V_16 -> V_38 , 0 ) ;
V_16 -> V_37 = 0 ;
V_16 -> V_15 = V_15 ;
V_16 -> V_31 = V_31 ;
V_24 = & V_16 -> V_24 ;
V_16 -> V_43 = V_79 -> V_102 ;
V_98 = V_79 -> V_63 ;
V_99 = V_79 -> V_43 ;
F_55 ( V_79 ) ;
V_79 = NULL ;
V_16 -> V_63 = V_95 ;
V_16 -> V_47 = V_47 ;
V_16 -> V_42 = F_60 ( V_94 ) ;
V_16 -> V_44 = V_9 ;
V_27 = ( V_47 + V_29 - 1 ) /
V_29 ;
V_16 -> V_28 = F_61 ( sizeof( struct V_19 * ) * V_27 ,
V_67 ) ;
if ( ! V_16 -> V_28 )
goto V_103;
V_11 = F_7 ( V_15 ) -> V_2 -> V_5 -> V_69 -> V_70 ;
for ( V_65 = 0 ; V_65 < V_27 ; V_65 ++ ) {
V_16 -> V_28 [ V_65 ] = F_62 ( V_67 |
V_104 ) ;
if ( ! V_16 -> V_28 [ V_65 ] ) {
V_100 = V_65 - 1 ;
V_18 = - V_68 ;
goto V_105;
}
}
V_100 = V_27 - 1 ;
V_16 -> V_27 = V_27 ;
F_40 ( V_15 , V_99 + V_98 , V_16 ) ;
V_95 = V_9 -> V_46 * V_29 ;
V_16 -> V_63 = V_95 ;
V_96 = F_3 ( V_11 , V_97 , V_67 ) ;
if ( ! V_96 )
goto V_105;
V_96 -> V_35 = V_16 ;
V_96 -> V_71 = F_14 ;
F_32 ( & V_16 -> V_38 ) ;
for ( V_65 = 0 ; V_65 < V_27 ; V_65 ++ ) {
V_19 = V_16 -> V_28 [ V_65 ] ;
V_19 -> V_48 = V_15 -> V_57 ;
V_19 -> V_36 = V_99 >> V_54 ;
if ( V_96 -> V_72 )
V_18 = V_59 -> V_61 -> V_73 ( V_19 , 0 ,
V_29 ,
V_96 , 0 ) ;
else
V_18 = 0 ;
V_19 -> V_48 = NULL ;
if ( V_18 || F_33 ( V_96 , V_19 , V_29 , 0 ) <
V_29 ) {
F_34 ( V_96 ) ;
V_18 = F_35 ( V_2 -> V_5 , V_96 , 0 ) ;
F_36 ( V_18 ) ;
F_32 ( & V_16 -> V_38 ) ;
if ( ! ( F_7 ( V_15 ) -> V_25 & V_26 ) ) {
V_18 = F_63 ( V_2 , V_15 ,
V_96 , V_24 ) ;
F_36 ( V_18 ) ;
}
V_24 += ( V_96 -> V_72 + V_2 -> V_8 - 1 ) /
V_2 -> V_8 ;
V_18 = F_38 ( V_2 , V_106 , V_96 ,
V_31 , 0 ) ;
F_36 ( V_18 ) ;
F_22 ( V_96 ) ;
V_96 = F_3 ( V_11 , V_97 ,
V_67 ) ;
F_36 ( ! V_96 ) ;
V_96 -> V_35 = V_16 ;
V_96 -> V_71 = F_14 ;
F_33 ( V_96 , V_19 , V_29 , 0 ) ;
}
V_97 += V_29 ;
}
F_34 ( V_96 ) ;
V_18 = F_35 ( V_2 -> V_5 , V_96 , 0 ) ;
F_36 ( V_18 ) ;
if ( ! ( F_7 ( V_15 ) -> V_25 & V_26 ) ) {
V_18 = F_63 ( V_2 , V_15 , V_96 , V_24 ) ;
F_36 ( V_18 ) ;
}
V_18 = F_38 ( V_2 , V_106 , V_96 , V_31 , 0 ) ;
F_36 ( V_18 ) ;
F_22 ( V_96 ) ;
return 0 ;
V_105:
while ( V_100 >= 0 ) {
F_64 ( V_16 -> V_28 [ V_100 ] ) ;
V_100 -- ;
}
F_21 ( V_16 -> V_28 ) ;
V_103:
F_21 ( V_16 ) ;
V_39:
F_55 ( V_79 ) ;
return V_18 ;
}
void T_7 F_65 ( void )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_107 ; V_20 ++ ) {
F_66 ( & V_108 [ V_20 ] ) ;
F_67 ( & V_109 [ V_20 ] ) ;
F_31 ( & V_110 [ V_20 ] , 0 ) ;
F_68 ( & V_111 [ V_20 ] ) ;
}
}
static struct V_112 * F_69 ( int type )
{
struct V_112 * V_113 ;
int V_114 = F_70 () ;
int V_115 = type - 1 ;
struct V_112 * V_116 = & V_108 [ V_115 ] ;
T_8 * V_117 = & V_109 [ V_115 ] ;
T_9 * V_118 = & V_110 [ V_115 ] ;
T_10 * V_119 = & V_111 [ V_115 ] ;
int * V_120 = & V_121 [ V_115 ] ;
V_122:
F_71 ( V_117 ) ;
if ( ! F_72 ( V_116 ) ) {
V_113 = V_116 -> V_87 ;
F_73 ( V_113 ) ;
( * V_120 ) -- ;
F_74 ( V_117 ) ;
return V_113 ;
}
if ( F_75 ( V_118 ) > V_114 ) {
F_76 ( V_123 ) ;
F_74 ( V_117 ) ;
F_77 ( V_119 , & V_123 , V_124 ) ;
if ( F_75 ( V_118 ) > V_114 && ! * V_120 )
F_78 () ;
F_79 ( V_119 , & V_123 ) ;
goto V_122;
}
F_32 ( V_118 ) ;
F_74 ( V_117 ) ;
V_113 = V_125 [ V_115 ] -> V_118 () ;
if ( F_80 ( V_113 ) ) {
F_81 ( V_118 ) ;
F_82 ( V_119 ) ;
}
return V_113 ;
}
static void F_83 ( int type , struct V_112 * V_113 )
{
int V_115 = type - 1 ;
struct V_112 * V_116 = & V_108 [ V_115 ] ;
T_8 * V_117 = & V_109 [ V_115 ] ;
T_9 * V_118 = & V_110 [ V_115 ] ;
T_10 * V_119 = & V_111 [ V_115 ] ;
int * V_120 = & V_121 [ V_115 ] ;
F_71 ( V_117 ) ;
if ( * V_120 < F_70 () ) {
F_84 ( V_113 , V_116 ) ;
( * V_120 ) ++ ;
F_74 ( V_117 ) ;
goto V_126;
}
F_74 ( V_117 ) ;
V_125 [ V_115 ] -> F_83 ( V_113 ) ;
F_81 ( V_118 ) ;
V_126:
F_85 () ;
if ( F_86 ( V_119 ) )
F_82 ( V_119 ) ;
}
static void F_87 ( void )
{
struct V_112 * V_113 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_107 ; V_20 ++ ) {
while ( ! F_72 ( & V_108 [ V_20 ] ) ) {
V_113 = V_108 [ V_20 ] . V_87 ;
F_73 ( V_113 ) ;
V_125 [ V_20 ] -> F_83 ( V_113 ) ;
F_81 ( & V_110 [ V_20 ] ) ;
}
}
}
int F_88 ( int type , struct V_80 * V_48 ,
T_2 V_43 , unsigned long V_63 ,
struct V_19 * * V_56 ,
unsigned long V_127 ,
unsigned long * V_128 ,
unsigned long * V_129 ,
unsigned long * V_130 ,
unsigned long V_131 )
{
struct V_112 * V_113 ;
int V_18 ;
V_113 = F_69 ( type ) ;
if ( F_80 ( V_113 ) )
return - 1 ;
V_18 = V_125 [ type - 1 ] -> F_89 ( V_113 , V_48 ,
V_43 , V_63 , V_56 ,
V_127 , V_128 ,
V_129 , V_130 ,
V_131 ) ;
F_83 ( type , V_113 ) ;
return V_18 ;
}
int F_16 ( int type , struct V_19 * * V_132 , T_2 V_17 ,
struct V_50 * V_51 , int V_133 , T_6 V_134 )
{
struct V_112 * V_113 ;
int V_18 ;
V_113 = F_69 ( type ) ;
if ( F_80 ( V_113 ) )
return - V_68 ;
V_18 = V_125 [ type - 1 ] -> F_90 ( V_113 , V_132 ,
V_17 ,
V_51 , V_133 , V_134 ) ;
F_83 ( type , V_113 ) ;
return V_18 ;
}
int F_91 ( int type , unsigned char * V_135 , struct V_19 * V_136 ,
unsigned long V_137 , T_6 V_134 , T_6 V_138 )
{
struct V_112 * V_113 ;
int V_18 ;
V_113 = F_69 ( type ) ;
if ( F_80 ( V_113 ) )
return - V_68 ;
V_18 = V_125 [ type - 1 ] -> F_92 ( V_113 , V_135 ,
V_136 , V_137 ,
V_134 , V_138 ) ;
F_83 ( type , V_113 ) ;
return V_18 ;
}
void F_93 ( void )
{
F_87 () ;
}
int F_94 ( char * V_139 , unsigned long V_140 ,
unsigned long V_130 , T_2 V_17 ,
struct V_50 * V_51 , int V_133 ,
unsigned long * V_65 ,
unsigned long * V_141 )
{
unsigned long V_142 ;
unsigned long V_143 ;
unsigned long V_137 ;
unsigned long V_144 = V_130 - V_140 ;
unsigned long V_145 ;
char * V_21 ;
struct V_19 * V_146 = V_51 [ * V_65 ] . V_52 ;
V_137 = F_42 ( V_146 ) - V_17 ;
if ( V_130 <= V_137 )
return 1 ;
if ( V_130 > V_137 && V_140 < V_137 ) {
V_142 = V_137 - V_140 ;
V_144 -= V_142 ;
} else {
V_142 = 0 ;
}
V_143 = V_140 ;
while ( V_144 > 0 ) {
V_145 = F_95 ( V_29 - * V_141 ,
V_29 - V_142 ) ;
V_145 = F_95 ( V_145 , V_144 ) ;
V_21 = F_8 ( V_146 ) ;
memcpy ( V_21 + * V_141 , V_139 + V_142 , V_145 ) ;
F_11 ( V_21 ) ;
F_58 ( V_146 ) ;
* V_141 += V_145 ;
V_142 += V_145 ;
V_144 -= V_145 ;
V_143 += V_145 ;
if ( * V_141 == V_29 ) {
( * V_65 ) ++ ;
if ( * V_65 >= V_133 )
return 0 ;
V_146 = V_51 [ * V_65 ] . V_52 ;
* V_141 = 0 ;
V_137 = F_42 ( V_146 ) - V_17 ;
if ( V_130 <= V_137 )
return 1 ;
if ( V_130 > V_137 &&
V_143 < V_137 ) {
V_142 = V_137 - V_140 ;
V_144 = V_130 - V_137 ;
V_143 = V_140 + V_142 ;
}
}
}
return 1 ;
}
