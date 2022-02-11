static inline int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
T_1 V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
return sizeof( struct V_7 ) +
( F_3 ( V_3 , V_2 -> V_8 ) ) * V_4 ;
}
static struct V_9 * F_4 ( struct V_10 * V_11 ,
T_2 V_12 , T_3 V_13 )
{
int V_14 ;
V_14 = F_5 ( V_11 ) ;
return F_6 ( V_11 , V_12 >> 9 , V_14 , V_13 ) ;
}
static int F_7 ( struct V_15 * V_15 ,
struct V_7 * V_16 ,
T_2 V_17 )
{
int V_18 ;
struct V_19 * V_19 ;
unsigned long V_20 ;
char * V_21 ;
T_4 V_22 ;
T_4 * V_23 = & V_16 -> V_24 ;
if ( F_8 ( V_15 ) -> V_25 & V_26 )
return 0 ;
for ( V_20 = 0 ; V_20 < V_16 -> V_27 ; V_20 ++ ) {
V_19 = V_16 -> V_28 [ V_20 ] ;
V_22 = ~ ( T_4 ) 0 ;
V_21 = F_9 ( V_19 ) ;
V_22 = F_10 ( V_21 , V_22 , V_29 ) ;
F_11 ( V_22 , ( char * ) & V_22 ) ;
F_12 ( V_21 ) ;
if ( V_22 != * V_23 ) {
F_13 ( F_8 ( V_15 ) -> V_2 -> V_5 ,
L_1 ,
F_14 ( V_15 ) , V_17 , V_22 , * V_23 ,
V_16 -> V_30 ) ;
V_18 = - V_31 ;
goto V_32;
}
V_23 ++ ;
}
V_18 = 0 ;
V_32:
return V_18 ;
}
static void F_15 ( struct V_9 * V_9 , int V_33 )
{
struct V_7 * V_16 = V_9 -> V_34 ;
struct V_15 * V_15 ;
struct V_19 * V_19 ;
unsigned long V_35 ;
int V_18 ;
if ( V_33 )
V_16 -> V_36 = 1 ;
if ( ! F_16 ( & V_16 -> V_37 ) )
goto V_38;
V_15 = V_16 -> V_15 ;
V_18 = F_7 ( V_15 , V_16 ,
( T_2 ) V_9 -> V_39 . V_40 << 9 ) ;
if ( V_18 )
goto V_41;
V_18 = F_17 ( V_16 -> V_42 ,
V_16 -> V_28 ,
V_16 -> V_43 ,
V_16 -> V_44 -> V_45 ,
V_16 -> V_44 -> V_46 ,
V_16 -> V_47 ) ;
V_41:
if ( V_18 )
V_16 -> V_36 = 1 ;
V_35 = 0 ;
for ( V_35 = 0 ; V_35 < V_16 -> V_27 ; V_35 ++ ) {
V_19 = V_16 -> V_28 [ V_35 ] ;
V_19 -> V_48 = NULL ;
F_18 ( V_19 ) ;
}
if ( V_16 -> V_36 ) {
F_19 ( V_16 -> V_44 ) ;
} else {
int V_20 ;
struct V_49 * V_50 ;
F_20 (bvec, cb->orig_bio, i)
F_21 ( V_50 -> V_51 ) ;
F_22 ( V_16 -> V_44 , 0 ) ;
}
F_23 ( V_16 -> V_28 ) ;
F_23 ( V_16 ) ;
V_38:
F_24 ( V_9 ) ;
}
static T_5 void F_25 ( struct V_15 * V_15 , T_2 V_43 ,
unsigned long V_52 )
{
unsigned long V_35 = V_43 >> V_53 ;
unsigned long V_54 = ( V_43 + V_52 - 1 ) >> V_53 ;
struct V_19 * V_55 [ 16 ] ;
unsigned long V_27 = V_54 - V_35 + 1 ;
int V_20 ;
int V_18 ;
while ( V_27 > 0 ) {
V_18 = F_26 ( V_15 -> V_56 , V_35 ,
F_27 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_55 ) ;
if ( V_18 == 0 ) {
V_27 -= 1 ;
V_35 += 1 ;
continue;
}
for ( V_20 = 0 ; V_20 < V_18 ; V_20 ++ ) {
F_28 ( V_55 [ V_20 ] ) ;
F_18 ( V_55 [ V_20 ] ) ;
}
V_27 -= V_18 ;
V_35 += V_18 ;
}
}
static void F_29 ( struct V_9 * V_9 , int V_33 )
{
struct V_57 * V_58 ;
struct V_7 * V_16 = V_9 -> V_34 ;
struct V_15 * V_15 ;
struct V_19 * V_19 ;
unsigned long V_35 ;
if ( V_33 )
V_16 -> V_36 = 1 ;
if ( ! F_16 ( & V_16 -> V_37 ) )
goto V_38;
V_15 = V_16 -> V_15 ;
V_58 = & F_8 ( V_15 ) -> V_59 ;
V_16 -> V_28 [ 0 ] -> V_48 = V_16 -> V_15 -> V_56 ;
V_58 -> V_60 -> V_61 ( V_16 -> V_28 [ 0 ] ,
V_16 -> V_43 ,
V_16 -> V_43 + V_16 -> V_62 - 1 ,
NULL , 1 ) ;
V_16 -> V_28 [ 0 ] -> V_48 = NULL ;
F_25 ( V_15 , V_16 -> V_43 , V_16 -> V_62 ) ;
V_35 = 0 ;
for ( V_35 = 0 ; V_35 < V_16 -> V_27 ; V_35 ++ ) {
V_19 = V_16 -> V_28 [ V_35 ] ;
V_19 -> V_48 = NULL ;
F_18 ( V_19 ) ;
}
F_23 ( V_16 -> V_28 ) ;
F_23 ( V_16 ) ;
V_38:
F_24 ( V_9 ) ;
}
int F_30 ( struct V_15 * V_15 , T_2 V_43 ,
unsigned long V_62 , T_2 V_17 ,
unsigned long V_47 ,
struct V_19 * * V_28 ,
unsigned long V_27 )
{
struct V_9 * V_9 = NULL ;
struct V_1 * V_2 = F_8 ( V_15 ) -> V_2 ;
struct V_7 * V_16 ;
unsigned long V_63 ;
struct V_57 * V_59 = & F_8 ( V_15 ) -> V_59 ;
int V_64 = 0 ;
struct V_19 * V_19 ;
T_2 V_12 = V_17 ;
struct V_10 * V_11 ;
int V_18 ;
int V_65 = F_8 ( V_15 ) -> V_25 & V_26 ;
F_31 ( V_43 & ( ( T_2 ) V_29 - 1 ) ) ;
V_16 = F_32 ( F_1 ( V_2 , V_47 ) , V_66 ) ;
if ( ! V_16 )
return - V_67 ;
F_33 ( & V_16 -> V_37 , 0 ) ;
V_16 -> V_36 = 0 ;
V_16 -> V_15 = V_15 ;
V_16 -> V_43 = V_43 ;
V_16 -> V_62 = V_62 ;
V_16 -> V_30 = 0 ;
V_16 -> V_28 = V_28 ;
V_16 -> V_47 = V_47 ;
V_16 -> V_44 = NULL ;
V_16 -> V_27 = V_27 ;
V_11 = F_8 ( V_15 ) -> V_2 -> V_5 -> V_68 -> V_69 ;
V_9 = F_4 ( V_11 , V_12 , V_66 ) ;
if ( ! V_9 ) {
F_23 ( V_16 ) ;
return - V_67 ;
}
V_9 -> V_34 = V_16 ;
V_9 -> V_70 = F_29 ;
F_34 ( & V_16 -> V_37 ) ;
V_63 = V_47 ;
for ( V_64 = 0 ; V_64 < V_16 -> V_27 ; V_64 ++ ) {
V_19 = V_28 [ V_64 ] ;
V_19 -> V_48 = V_15 -> V_56 ;
if ( V_9 -> V_39 . V_71 )
V_18 = V_59 -> V_60 -> V_72 ( V_73 , V_19 , 0 ,
V_29 ,
V_9 , 0 ) ;
else
V_18 = 0 ;
V_19 -> V_48 = NULL ;
if ( V_18 || F_35 ( V_9 , V_19 , V_29 , 0 ) <
V_29 ) {
F_36 ( V_9 ) ;
F_34 ( & V_16 -> V_37 ) ;
V_18 = F_37 ( V_2 -> V_5 , V_9 ,
V_74 ) ;
F_38 ( V_18 ) ;
if ( ! V_65 ) {
V_18 = F_39 ( V_2 , V_15 , V_9 ,
V_43 , 1 ) ;
F_38 ( V_18 ) ;
}
V_18 = F_40 ( V_2 , V_73 , V_9 , 0 , 1 ) ;
F_38 ( V_18 ) ;
F_24 ( V_9 ) ;
V_9 = F_4 ( V_11 , V_12 , V_66 ) ;
F_38 ( ! V_9 ) ;
V_9 -> V_34 = V_16 ;
V_9 -> V_70 = F_29 ;
F_35 ( V_9 , V_19 , V_29 , 0 ) ;
}
if ( V_63 < V_29 ) {
F_13 ( F_8 ( V_15 ) -> V_2 -> V_5 ,
L_2 ,
V_63 , V_16 -> V_47 , V_16 -> V_27 ) ;
}
V_63 -= V_29 ;
V_12 += V_29 ;
F_41 () ;
}
F_36 ( V_9 ) ;
V_18 = F_37 ( V_2 -> V_5 , V_9 , V_74 ) ;
F_38 ( V_18 ) ;
if ( ! V_65 ) {
V_18 = F_39 ( V_2 , V_15 , V_9 , V_43 , 1 ) ;
F_38 ( V_18 ) ;
}
V_18 = F_40 ( V_2 , V_73 , V_9 , 0 , 1 ) ;
F_38 ( V_18 ) ;
F_24 ( V_9 ) ;
return 0 ;
}
static T_5 int F_42 ( struct V_15 * V_15 ,
T_2 V_75 ,
struct V_7 * V_16 )
{
unsigned long V_54 ;
unsigned long V_64 ;
T_2 V_76 ;
T_2 V_77 = F_43 ( V_15 ) ;
int V_18 ;
struct V_19 * V_19 ;
unsigned long V_27 = 0 ;
struct V_78 * V_79 ;
struct V_80 * V_48 = V_15 -> V_56 ;
struct V_81 * V_82 ;
struct V_57 * V_58 ;
T_2 V_83 ;
int V_84 = 0 ;
V_19 = V_16 -> V_44 -> V_45 [ V_16 -> V_44 -> V_46 - 1 ] . V_51 ;
V_76 = ( F_44 ( V_19 ) + V_29 ) ;
V_82 = & F_8 ( V_15 ) -> V_85 ;
V_58 = & F_8 ( V_15 ) -> V_59 ;
if ( V_77 == 0 )
return 0 ;
V_54 = ( F_43 ( V_15 ) - 1 ) >> V_53 ;
while ( V_76 < V_75 ) {
V_64 = V_76 >> V_53 ;
if ( V_64 > V_54 )
break;
F_45 () ;
V_19 = F_46 ( & V_48 -> V_86 , V_64 ) ;
F_47 () ;
if ( V_19 && ! F_48 ( V_19 ) ) {
V_84 ++ ;
if ( V_84 > 4 )
break;
goto V_87;
}
V_19 = F_49 ( F_50 ( V_48 ) &
~ V_88 ) ;
if ( ! V_19 )
break;
if ( F_51 ( V_19 , V_48 , V_64 ,
V_66 ) ) {
F_18 ( V_19 ) ;
goto V_87;
}
V_83 = V_76 + V_29 - 1 ;
F_52 ( V_19 ) ;
F_53 ( V_58 , V_76 , V_83 ) ;
F_54 ( & V_82 -> V_89 ) ;
V_79 = F_55 ( V_82 , V_76 ,
V_29 ) ;
F_56 ( & V_82 -> V_89 ) ;
if ( ! V_79 || V_76 < V_79 -> V_43 ||
( V_76 + V_29 > F_57 ( V_79 ) ) ||
( V_79 -> V_90 >> 9 ) != V_16 -> V_44 -> V_39 . V_40 ) {
F_58 ( V_79 ) ;
F_59 ( V_58 , V_76 , V_83 ) ;
F_60 ( V_19 ) ;
F_18 ( V_19 ) ;
break;
}
F_58 ( V_79 ) ;
if ( V_19 -> V_35 == V_54 ) {
char * V_91 ;
T_6 V_92 = V_77 & ( V_29 - 1 ) ;
if ( V_92 ) {
int V_93 ;
V_93 = V_29 - V_92 ;
V_91 = F_9 ( V_19 ) ;
memset ( V_91 + V_92 , 0 , V_93 ) ;
F_61 ( V_19 ) ;
F_12 ( V_91 ) ;
}
}
V_18 = F_35 ( V_16 -> V_44 , V_19 ,
V_29 , 0 ) ;
if ( V_18 == V_29 ) {
V_27 ++ ;
F_18 ( V_19 ) ;
} else {
F_59 ( V_58 , V_76 , V_83 ) ;
F_60 ( V_19 ) ;
F_18 ( V_19 ) ;
break;
}
V_87:
V_76 += V_29 ;
}
return 0 ;
}
int F_62 ( struct V_15 * V_15 , struct V_9 * V_9 ,
int V_30 , unsigned long V_94 )
{
struct V_57 * V_58 ;
struct V_81 * V_82 ;
struct V_7 * V_16 ;
struct V_1 * V_2 = F_8 ( V_15 ) -> V_2 ;
unsigned long V_95 = V_9 -> V_46 * V_29 ;
unsigned long V_47 ;
unsigned long V_27 ;
unsigned long V_64 ;
struct V_19 * V_19 ;
struct V_10 * V_11 ;
struct V_9 * V_96 ;
T_2 V_97 = ( T_2 ) V_9 -> V_39 . V_40 << 9 ;
T_2 V_98 ;
T_2 V_99 ;
struct V_78 * V_79 ;
int V_18 = - V_67 ;
int V_100 = 0 ;
T_4 * V_24 ;
V_58 = & F_8 ( V_15 ) -> V_59 ;
V_82 = & F_8 ( V_15 ) -> V_85 ;
F_54 ( & V_82 -> V_89 ) ;
V_79 = F_55 ( V_82 ,
F_44 ( V_9 -> V_45 -> V_51 ) ,
V_29 ) ;
F_56 ( & V_82 -> V_89 ) ;
if ( ! V_79 )
return - V_31 ;
V_47 = V_79 -> V_101 ;
V_16 = F_32 ( F_1 ( V_2 , V_47 ) , V_66 ) ;
if ( ! V_16 )
goto V_38;
F_33 ( & V_16 -> V_37 , 0 ) ;
V_16 -> V_36 = 0 ;
V_16 -> V_15 = V_15 ;
V_16 -> V_30 = V_30 ;
V_24 = & V_16 -> V_24 ;
V_16 -> V_43 = V_79 -> V_102 ;
V_98 = V_79 -> V_62 ;
V_99 = V_79 -> V_43 ;
F_58 ( V_79 ) ;
V_79 = NULL ;
V_16 -> V_62 = V_95 ;
V_16 -> V_47 = V_47 ;
V_16 -> V_42 = F_63 ( V_94 ) ;
V_16 -> V_44 = V_9 ;
V_27 = F_3 ( V_47 , V_29 ) ;
V_16 -> V_28 = F_64 ( sizeof( struct V_19 * ) * V_27 ,
V_66 ) ;
if ( ! V_16 -> V_28 )
goto V_103;
V_11 = F_8 ( V_15 ) -> V_2 -> V_5 -> V_68 -> V_69 ;
for ( V_64 = 0 ; V_64 < V_27 ; V_64 ++ ) {
V_16 -> V_28 [ V_64 ] = F_65 ( V_66 |
V_104 ) ;
if ( ! V_16 -> V_28 [ V_64 ] ) {
V_100 = V_64 - 1 ;
V_18 = - V_67 ;
goto V_105;
}
}
V_100 = V_27 - 1 ;
V_16 -> V_27 = V_27 ;
if ( ! ( V_94 & V_106 ) )
F_42 ( V_15 , V_99 + V_98 , V_16 ) ;
V_95 = V_9 -> V_46 * V_29 ;
V_16 -> V_62 = V_95 ;
V_96 = F_4 ( V_11 , V_97 , V_66 ) ;
if ( ! V_96 )
goto V_105;
V_96 -> V_34 = V_16 ;
V_96 -> V_70 = F_15 ;
F_34 ( & V_16 -> V_37 ) ;
for ( V_64 = 0 ; V_64 < V_27 ; V_64 ++ ) {
V_19 = V_16 -> V_28 [ V_64 ] ;
V_19 -> V_48 = V_15 -> V_56 ;
V_19 -> V_35 = V_99 >> V_53 ;
if ( V_96 -> V_39 . V_71 )
V_18 = V_58 -> V_60 -> V_72 ( V_107 , V_19 , 0 ,
V_29 ,
V_96 , 0 ) ;
else
V_18 = 0 ;
V_19 -> V_48 = NULL ;
if ( V_18 || F_35 ( V_96 , V_19 , V_29 , 0 ) <
V_29 ) {
F_36 ( V_96 ) ;
V_18 = F_37 ( V_2 -> V_5 , V_96 ,
V_74 ) ;
F_38 ( V_18 ) ;
F_34 ( & V_16 -> V_37 ) ;
if ( ! ( F_8 ( V_15 ) -> V_25 & V_26 ) ) {
V_18 = F_66 ( V_2 , V_15 ,
V_96 , V_24 ) ;
F_38 ( V_18 ) ;
}
V_24 += F_3 ( V_96 -> V_39 . V_71 ,
V_2 -> V_8 ) ;
V_18 = F_40 ( V_2 , V_107 , V_96 ,
V_30 , 0 ) ;
if ( V_18 )
F_22 ( V_96 , V_18 ) ;
F_24 ( V_96 ) ;
V_96 = F_4 ( V_11 , V_97 ,
V_66 ) ;
F_38 ( ! V_96 ) ;
V_96 -> V_34 = V_16 ;
V_96 -> V_70 = F_15 ;
F_35 ( V_96 , V_19 , V_29 , 0 ) ;
}
V_97 += V_29 ;
}
F_36 ( V_96 ) ;
V_18 = F_37 ( V_2 -> V_5 , V_96 ,
V_74 ) ;
F_38 ( V_18 ) ;
if ( ! ( F_8 ( V_15 ) -> V_25 & V_26 ) ) {
V_18 = F_66 ( V_2 , V_15 , V_96 , V_24 ) ;
F_38 ( V_18 ) ;
}
V_18 = F_40 ( V_2 , V_107 , V_96 , V_30 , 0 ) ;
if ( V_18 )
F_22 ( V_96 , V_18 ) ;
F_24 ( V_96 ) ;
return 0 ;
V_105:
while ( V_100 >= 0 ) {
F_67 ( V_16 -> V_28 [ V_100 ] ) ;
V_100 -- ;
}
F_23 ( V_16 -> V_28 ) ;
V_103:
F_23 ( V_16 ) ;
V_38:
F_58 ( V_79 ) ;
return V_18 ;
}
void T_7 F_68 ( void )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_108 ; V_20 ++ ) {
F_69 ( & V_109 [ V_20 ] ) ;
F_70 ( & V_110 [ V_20 ] ) ;
F_33 ( & V_111 [ V_20 ] , 0 ) ;
F_71 ( & V_112 [ V_20 ] ) ;
}
}
static struct V_113 * F_72 ( int type )
{
struct V_113 * V_114 ;
int V_115 = F_73 () ;
int V_116 = type - 1 ;
struct V_113 * V_117 = & V_109 [ V_116 ] ;
T_8 * V_118 = & V_110 [ V_116 ] ;
T_9 * V_119 = & V_111 [ V_116 ] ;
T_10 * V_120 = & V_112 [ V_116 ] ;
int * V_121 = & V_122 [ V_116 ] ;
V_123:
F_74 ( V_118 ) ;
if ( ! F_75 ( V_117 ) ) {
V_114 = V_117 -> V_87 ;
F_76 ( V_114 ) ;
( * V_121 ) -- ;
F_77 ( V_118 ) ;
return V_114 ;
}
if ( F_78 ( V_119 ) > V_115 ) {
F_79 ( V_124 ) ;
F_77 ( V_118 ) ;
F_80 ( V_120 , & V_124 , V_125 ) ;
if ( F_78 ( V_119 ) > V_115 && ! * V_121 )
F_81 () ;
F_82 ( V_120 , & V_124 ) ;
goto V_123;
}
F_34 ( V_119 ) ;
F_77 ( V_118 ) ;
V_114 = V_126 [ V_116 ] -> V_119 () ;
if ( F_83 ( V_114 ) ) {
F_84 ( V_119 ) ;
F_85 ( V_120 ) ;
}
return V_114 ;
}
static void F_86 ( int type , struct V_113 * V_114 )
{
int V_116 = type - 1 ;
struct V_113 * V_117 = & V_109 [ V_116 ] ;
T_8 * V_118 = & V_110 [ V_116 ] ;
T_9 * V_119 = & V_111 [ V_116 ] ;
T_10 * V_120 = & V_112 [ V_116 ] ;
int * V_121 = & V_122 [ V_116 ] ;
F_74 ( V_118 ) ;
if ( * V_121 < F_73 () ) {
F_87 ( V_114 , V_117 ) ;
( * V_121 ) ++ ;
F_77 ( V_118 ) ;
goto V_127;
}
F_77 ( V_118 ) ;
V_126 [ V_116 ] -> F_86 ( V_114 ) ;
F_84 ( V_119 ) ;
V_127:
F_88 () ;
if ( F_89 ( V_120 ) )
F_85 ( V_120 ) ;
}
static void F_90 ( void )
{
struct V_113 * V_114 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_108 ; V_20 ++ ) {
while ( ! F_75 ( & V_109 [ V_20 ] ) ) {
V_114 = V_109 [ V_20 ] . V_87 ;
F_76 ( V_114 ) ;
V_126 [ V_20 ] -> F_86 ( V_114 ) ;
F_84 ( & V_111 [ V_20 ] ) ;
}
}
}
int F_91 ( int type , struct V_80 * V_48 ,
T_2 V_43 , unsigned long V_62 ,
struct V_19 * * V_55 ,
unsigned long V_128 ,
unsigned long * V_129 ,
unsigned long * V_130 ,
unsigned long * V_131 ,
unsigned long V_132 )
{
struct V_113 * V_114 ;
int V_18 ;
V_114 = F_72 ( type ) ;
if ( F_83 ( V_114 ) )
return F_92 ( V_114 ) ;
V_18 = V_126 [ type - 1 ] -> F_93 ( V_114 , V_48 ,
V_43 , V_62 , V_55 ,
V_128 , V_129 ,
V_130 , V_131 ,
V_132 ) ;
F_86 ( type , V_114 ) ;
return V_18 ;
}
static int F_17 ( int type , struct V_19 * * V_133 ,
T_2 V_17 , struct V_49 * V_50 ,
int V_134 , T_6 V_135 )
{
struct V_113 * V_114 ;
int V_18 ;
V_114 = F_72 ( type ) ;
if ( F_83 ( V_114 ) )
return F_92 ( V_114 ) ;
V_18 = V_126 [ type - 1 ] -> F_94 ( V_114 , V_133 ,
V_17 ,
V_50 , V_134 , V_135 ) ;
F_86 ( type , V_114 ) ;
return V_18 ;
}
int F_95 ( int type , unsigned char * V_136 , struct V_19 * V_137 ,
unsigned long V_138 , T_6 V_135 , T_6 V_139 )
{
struct V_113 * V_114 ;
int V_18 ;
V_114 = F_72 ( type ) ;
if ( F_83 ( V_114 ) )
return F_92 ( V_114 ) ;
V_18 = V_126 [ type - 1 ] -> F_96 ( V_114 , V_136 ,
V_137 , V_138 ,
V_135 , V_139 ) ;
F_86 ( type , V_114 ) ;
return V_18 ;
}
void F_97 ( void )
{
F_90 () ;
}
int F_98 ( char * V_140 , unsigned long V_141 ,
unsigned long V_131 , T_2 V_17 ,
struct V_49 * V_50 , int V_134 ,
unsigned long * V_64 ,
unsigned long * V_142 )
{
unsigned long V_143 ;
unsigned long V_144 ;
unsigned long V_138 ;
unsigned long V_145 = V_131 - V_141 ;
unsigned long V_146 ;
char * V_21 ;
struct V_19 * V_147 = V_50 [ * V_64 ] . V_51 ;
V_138 = F_44 ( V_147 ) - V_17 ;
if ( V_131 <= V_138 )
return 1 ;
if ( V_131 > V_138 && V_141 < V_138 ) {
V_143 = V_138 - V_141 ;
V_145 -= V_143 ;
} else {
V_143 = 0 ;
}
V_144 = V_141 ;
while ( V_145 > 0 ) {
V_146 = F_99 ( V_29 - * V_142 ,
V_29 - V_143 ) ;
V_146 = F_99 ( V_146 , V_145 ) ;
V_21 = F_9 ( V_147 ) ;
memcpy ( V_21 + * V_142 , V_140 + V_143 , V_146 ) ;
F_12 ( V_21 ) ;
F_61 ( V_147 ) ;
* V_142 += V_146 ;
V_143 += V_146 ;
V_145 -= V_146 ;
V_144 += V_146 ;
if ( * V_142 == V_29 ) {
( * V_64 ) ++ ;
if ( * V_64 >= V_134 )
return 0 ;
V_147 = V_50 [ * V_64 ] . V_51 ;
* V_142 = 0 ;
V_138 = F_44 ( V_147 ) - V_17 ;
if ( V_131 <= V_138 )
return 1 ;
if ( V_131 > V_138 &&
V_144 < V_138 ) {
V_143 = V_138 - V_141 ;
V_145 = V_131 - V_138 ;
V_144 = V_141 + V_143 ;
}
}
}
return 1 ;
}
void F_100 ( struct V_49 * V_50 , int V_134 ,
unsigned long V_64 ,
unsigned long V_142 )
{
while ( V_64 < V_134 ) {
struct V_19 * V_19 = V_50 [ V_64 ] . V_51 ;
unsigned long V_148 = V_50 [ V_64 ] . V_149 ;
unsigned long V_62 = V_50 [ V_64 ] . V_150 ;
if ( V_142 < V_148 )
V_142 = V_148 ;
if ( V_142 < V_148 + V_62 ) {
unsigned long V_146 = V_148 + V_62 - V_142 ;
char * V_21 ;
V_21 = F_9 ( V_19 ) ;
memset ( V_21 + V_142 , 0 , V_146 ) ;
F_12 ( V_21 ) ;
}
V_64 ++ ;
V_142 = 0 ;
}
}
