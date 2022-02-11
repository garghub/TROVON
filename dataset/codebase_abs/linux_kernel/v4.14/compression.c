static inline int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
T_1 V_4 = F_2 ( V_2 -> V_5 ) ;
return sizeof( struct V_6 ) +
( F_3 ( V_3 , V_2 -> V_7 ) ) * V_4 ;
}
static int F_4 ( struct V_8 * V_9 ,
struct V_6 * V_10 ,
T_2 V_11 )
{
int V_12 ;
struct V_13 * V_13 ;
unsigned long V_14 ;
char * V_15 ;
T_3 V_16 ;
T_3 * V_17 = & V_10 -> V_18 ;
if ( V_9 -> V_19 & V_20 )
return 0 ;
for ( V_14 = 0 ; V_14 < V_10 -> V_21 ; V_14 ++ ) {
V_13 = V_10 -> V_22 [ V_14 ] ;
V_16 = ~ ( T_3 ) 0 ;
V_15 = F_5 ( V_13 ) ;
V_16 = F_6 ( V_15 , V_16 , V_23 ) ;
F_7 ( V_16 , ( V_24 * ) & V_16 ) ;
F_8 ( V_15 ) ;
if ( V_16 != * V_17 ) {
F_9 ( V_9 , V_11 , V_16 ,
* V_17 , V_10 -> V_25 ) ;
V_12 = - V_26 ;
goto V_27;
}
V_17 ++ ;
}
V_12 = 0 ;
V_27:
return V_12 ;
}
static void F_10 ( struct V_28 * V_28 )
{
struct V_6 * V_10 = V_28 -> V_29 ;
struct V_9 * V_9 ;
struct V_13 * V_13 ;
unsigned long V_30 ;
unsigned int V_31 = F_11 ( V_28 ) -> V_25 ;
int V_12 = 0 ;
if ( V_28 -> V_32 )
V_10 -> V_33 = 1 ;
if ( ! F_12 ( & V_10 -> V_34 ) )
goto V_35;
ASSERT ( F_11 ( V_10 -> V_36 ) ) ;
F_11 ( V_10 -> V_36 ) -> V_25 = V_31 ;
V_10 -> V_25 = V_31 ;
if ( V_10 -> V_33 == 1 )
goto V_37;
V_9 = V_10 -> V_9 ;
V_12 = F_4 ( F_13 ( V_9 ) , V_10 ,
( T_2 ) V_28 -> V_38 . V_39 << 9 ) ;
if ( V_12 )
goto V_37;
V_12 = F_14 ( V_10 ) ;
V_37:
if ( V_12 )
V_10 -> V_33 = 1 ;
V_30 = 0 ;
for ( V_30 = 0 ; V_30 < V_10 -> V_21 ; V_30 ++ ) {
V_13 = V_10 -> V_22 [ V_30 ] ;
V_13 -> V_40 = NULL ;
F_15 ( V_13 ) ;
}
if ( V_10 -> V_33 ) {
F_16 ( V_10 -> V_36 ) ;
} else {
int V_14 ;
struct V_41 * V_42 ;
ASSERT ( ! F_17 ( V_28 , V_43 ) ) ;
F_18 (bvec, cb->orig_bio, i)
F_19 ( V_42 -> V_44 ) ;
F_20 ( V_10 -> V_36 ) ;
}
F_21 ( V_10 -> V_22 ) ;
F_21 ( V_10 ) ;
V_35:
F_22 ( V_28 ) ;
}
static T_4 void F_23 ( struct V_9 * V_9 ,
const struct V_6 * V_10 )
{
unsigned long V_30 = V_10 -> V_45 >> V_46 ;
unsigned long V_47 = ( V_10 -> V_45 + V_10 -> V_48 - 1 ) >> V_46 ;
struct V_13 * V_49 [ 16 ] ;
unsigned long V_21 = V_47 - V_30 + 1 ;
int V_14 ;
int V_12 ;
if ( V_10 -> V_33 )
F_24 ( V_9 -> V_50 , - V_26 ) ;
while ( V_21 > 0 ) {
V_12 = F_25 ( V_9 -> V_50 , V_30 ,
F_26 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_49 ) ;
if ( V_12 == 0 ) {
V_21 -= 1 ;
V_30 += 1 ;
continue;
}
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ ) {
if ( V_10 -> V_33 )
F_27 ( V_49 [ V_14 ] ) ;
F_28 ( V_49 [ V_14 ] ) ;
F_15 ( V_49 [ V_14 ] ) ;
}
V_21 -= V_12 ;
V_30 += V_12 ;
}
}
static void F_29 ( struct V_28 * V_28 )
{
struct V_51 * V_52 ;
struct V_6 * V_10 = V_28 -> V_29 ;
struct V_9 * V_9 ;
struct V_13 * V_13 ;
unsigned long V_30 ;
if ( V_28 -> V_32 )
V_10 -> V_33 = 1 ;
if ( ! F_12 ( & V_10 -> V_34 ) )
goto V_35;
V_9 = V_10 -> V_9 ;
V_52 = & F_13 ( V_9 ) -> V_53 ;
V_10 -> V_22 [ 0 ] -> V_40 = V_10 -> V_9 -> V_50 ;
V_52 -> V_54 -> V_55 ( V_10 -> V_22 [ 0 ] ,
V_10 -> V_45 ,
V_10 -> V_45 + V_10 -> V_48 - 1 ,
NULL ,
V_28 -> V_32 ? 0 : 1 ) ;
V_10 -> V_22 [ 0 ] -> V_40 = NULL ;
F_23 ( V_9 , V_10 ) ;
V_30 = 0 ;
for ( V_30 = 0 ; V_30 < V_10 -> V_21 ; V_30 ++ ) {
V_13 = V_10 -> V_22 [ V_30 ] ;
V_13 -> V_40 = NULL ;
F_15 ( V_13 ) ;
}
F_21 ( V_10 -> V_22 ) ;
F_21 ( V_10 ) ;
V_35:
F_22 ( V_28 ) ;
}
T_5 F_30 ( struct V_9 * V_9 , T_2 V_45 ,
unsigned long V_48 , T_2 V_11 ,
unsigned long V_56 ,
struct V_13 * * V_22 ,
unsigned long V_21 )
{
struct V_1 * V_2 = F_31 ( V_9 -> V_57 ) ;
struct V_28 * V_28 = NULL ;
struct V_6 * V_10 ;
unsigned long V_58 ;
struct V_51 * V_53 = & F_13 ( V_9 ) -> V_53 ;
int V_59 = 0 ;
struct V_13 * V_13 ;
T_2 V_60 = V_11 ;
struct V_61 * V_62 ;
T_5 V_12 ;
int V_63 = F_13 ( V_9 ) -> V_19 & V_20 ;
F_32 ( V_45 & ( ( T_2 ) V_23 - 1 ) ) ;
V_10 = F_33 ( F_1 ( V_2 , V_56 ) , V_64 ) ;
if ( ! V_10 )
return V_65 ;
F_34 ( & V_10 -> V_34 , 0 ) ;
V_10 -> V_33 = 0 ;
V_10 -> V_9 = V_9 ;
V_10 -> V_45 = V_45 ;
V_10 -> V_48 = V_48 ;
V_10 -> V_25 = 0 ;
V_10 -> V_22 = V_22 ;
V_10 -> V_56 = V_56 ;
V_10 -> V_36 = NULL ;
V_10 -> V_21 = V_21 ;
V_62 = V_2 -> V_66 -> V_67 ;
V_28 = F_35 ( V_62 , V_60 ) ;
F_36 ( V_28 , V_68 , 0 ) ;
V_28 -> V_29 = V_10 ;
V_28 -> V_69 = F_29 ;
F_34 ( & V_10 -> V_34 , 1 ) ;
V_58 = V_56 ;
for ( V_59 = 0 ; V_59 < V_10 -> V_21 ; V_59 ++ ) {
int V_70 = 0 ;
V_13 = V_22 [ V_59 ] ;
V_13 -> V_40 = V_9 -> V_50 ;
if ( V_28 -> V_38 . V_71 )
V_70 = V_53 -> V_54 -> V_72 ( V_13 , 0 ,
V_23 ,
V_28 , 0 ) ;
V_13 -> V_40 = NULL ;
if ( V_70 || F_37 ( V_28 , V_13 , V_23 , 0 ) <
V_23 ) {
F_38 ( V_28 ) ;
F_39 ( & V_10 -> V_34 ) ;
V_12 = F_40 ( V_2 , V_28 ,
V_73 ) ;
F_41 ( V_12 ) ;
if ( ! V_63 ) {
V_12 = F_42 ( V_9 , V_28 , V_45 , 1 ) ;
F_41 ( V_12 ) ;
}
V_12 = F_43 ( V_2 , V_28 , 0 , 1 ) ;
if ( V_12 ) {
V_28 -> V_32 = V_12 ;
F_20 ( V_28 ) ;
}
F_22 ( V_28 ) ;
V_28 = F_35 ( V_62 , V_60 ) ;
F_36 ( V_28 , V_68 , 0 ) ;
V_28 -> V_29 = V_10 ;
V_28 -> V_69 = F_29 ;
F_37 ( V_28 , V_13 , V_23 , 0 ) ;
}
if ( V_58 < V_23 ) {
F_44 ( V_2 ,
L_1 ,
V_58 , V_10 -> V_56 , V_10 -> V_21 ) ;
}
V_58 -= V_23 ;
V_60 += V_23 ;
F_45 () ;
}
F_38 ( V_28 ) ;
V_12 = F_40 ( V_2 , V_28 , V_73 ) ;
F_41 ( V_12 ) ;
if ( ! V_63 ) {
V_12 = F_42 ( V_9 , V_28 , V_45 , 1 ) ;
F_41 ( V_12 ) ;
}
V_12 = F_43 ( V_2 , V_28 , 0 , 1 ) ;
if ( V_12 ) {
V_28 -> V_32 = V_12 ;
F_20 ( V_28 ) ;
}
F_22 ( V_28 ) ;
return 0 ;
}
static T_2 F_46 ( struct V_28 * V_28 )
{
struct V_41 * V_74 = & V_28 -> V_75 [ V_28 -> V_76 - 1 ] ;
return F_47 ( V_74 -> V_44 ) + V_74 -> V_77 + V_74 -> V_78 ;
}
static T_4 int F_48 ( struct V_9 * V_9 ,
T_2 V_79 ,
struct V_6 * V_10 )
{
unsigned long V_47 ;
unsigned long V_59 ;
T_2 V_80 ;
T_2 V_81 = F_49 ( V_9 ) ;
int V_12 ;
struct V_13 * V_13 ;
unsigned long V_21 = 0 ;
struct V_82 * V_83 ;
struct V_84 * V_40 = V_9 -> V_50 ;
struct V_85 * V_86 ;
struct V_51 * V_52 ;
T_2 V_87 ;
int V_88 = 0 ;
V_80 = F_46 ( V_10 -> V_36 ) ;
V_86 = & F_13 ( V_9 ) -> V_89 ;
V_52 = & F_13 ( V_9 ) -> V_53 ;
if ( V_81 == 0 )
return 0 ;
V_47 = ( F_49 ( V_9 ) - 1 ) >> V_46 ;
while ( V_80 < V_79 ) {
V_59 = V_80 >> V_46 ;
if ( V_59 > V_47 )
break;
F_50 () ;
V_13 = F_51 ( & V_40 -> V_90 , V_59 ) ;
F_52 () ;
if ( V_13 && ! F_53 ( V_13 ) ) {
V_88 ++ ;
if ( V_88 > 4 )
break;
goto V_91;
}
V_13 = F_54 ( F_55 ( V_40 ,
~ V_92 ) ) ;
if ( ! V_13 )
break;
if ( F_56 ( V_13 , V_40 , V_59 , V_64 ) ) {
F_15 ( V_13 ) ;
goto V_91;
}
V_87 = V_80 + V_23 - 1 ;
F_57 ( V_13 ) ;
F_58 ( V_52 , V_80 , V_87 ) ;
F_59 ( & V_86 -> V_93 ) ;
V_83 = F_60 ( V_86 , V_80 ,
V_23 ) ;
F_61 ( & V_86 -> V_93 ) ;
if ( ! V_83 || V_80 < V_83 -> V_45 ||
( V_80 + V_23 > F_62 ( V_83 ) ) ||
( V_83 -> V_94 >> 9 ) != V_10 -> V_36 -> V_38 . V_39 ) {
F_63 ( V_83 ) ;
F_64 ( V_52 , V_80 , V_87 ) ;
F_65 ( V_13 ) ;
F_15 ( V_13 ) ;
break;
}
F_63 ( V_83 ) ;
if ( V_13 -> V_30 == V_47 ) {
char * V_95 ;
T_6 V_96 = V_81 & ( V_23 - 1 ) ;
if ( V_96 ) {
int V_97 ;
V_97 = V_23 - V_96 ;
V_95 = F_5 ( V_13 ) ;
memset ( V_95 + V_96 , 0 , V_97 ) ;
F_66 ( V_13 ) ;
F_8 ( V_95 ) ;
}
}
V_12 = F_37 ( V_10 -> V_36 , V_13 ,
V_23 , 0 ) ;
if ( V_12 == V_23 ) {
V_21 ++ ;
F_15 ( V_13 ) ;
} else {
F_64 ( V_52 , V_80 , V_87 ) ;
F_65 ( V_13 ) ;
F_15 ( V_13 ) ;
break;
}
V_91:
V_80 += V_23 ;
}
return 0 ;
}
T_5 F_67 ( struct V_9 * V_9 , struct V_28 * V_28 ,
int V_25 , unsigned long V_98 )
{
struct V_1 * V_2 = F_31 ( V_9 -> V_57 ) ;
struct V_51 * V_52 ;
struct V_85 * V_86 ;
struct V_6 * V_10 ;
unsigned long V_56 ;
unsigned long V_21 ;
unsigned long V_59 ;
struct V_13 * V_13 ;
struct V_61 * V_62 ;
struct V_28 * V_99 ;
T_2 V_100 = ( T_2 ) V_28 -> V_38 . V_39 << 9 ;
T_2 V_101 ;
T_2 V_102 ;
struct V_82 * V_83 ;
T_5 V_12 = V_65 ;
int V_103 = 0 ;
T_3 * V_18 ;
V_52 = & F_13 ( V_9 ) -> V_53 ;
V_86 = & F_13 ( V_9 ) -> V_89 ;
F_59 ( & V_86 -> V_93 ) ;
V_83 = F_60 ( V_86 ,
F_47 ( V_28 -> V_75 -> V_44 ) ,
V_23 ) ;
F_61 ( & V_86 -> V_93 ) ;
if ( ! V_83 )
return V_104 ;
V_56 = V_83 -> V_105 ;
V_10 = F_33 ( F_1 ( V_2 , V_56 ) , V_64 ) ;
if ( ! V_10 )
goto V_35;
F_34 ( & V_10 -> V_34 , 0 ) ;
V_10 -> V_33 = 0 ;
V_10 -> V_9 = V_9 ;
V_10 -> V_25 = V_25 ;
V_18 = & V_10 -> V_18 ;
V_10 -> V_45 = V_83 -> V_106 ;
V_101 = V_83 -> V_48 ;
V_102 = V_83 -> V_45 ;
F_63 ( V_83 ) ;
V_83 = NULL ;
V_10 -> V_48 = V_28 -> V_38 . V_71 ;
V_10 -> V_56 = V_56 ;
V_10 -> V_107 = F_68 ( V_98 ) ;
V_10 -> V_36 = V_28 ;
V_21 = F_3 ( V_56 , V_23 ) ;
V_10 -> V_22 = F_69 ( V_21 , sizeof( struct V_13 * ) ,
V_64 ) ;
if ( ! V_10 -> V_22 )
goto V_108;
V_62 = V_2 -> V_66 -> V_67 ;
for ( V_59 = 0 ; V_59 < V_21 ; V_59 ++ ) {
V_10 -> V_22 [ V_59 ] = F_70 ( V_64 |
V_109 ) ;
if ( ! V_10 -> V_22 [ V_59 ] ) {
V_103 = V_59 - 1 ;
V_12 = V_65 ;
goto V_110;
}
}
V_103 = V_21 - 1 ;
V_10 -> V_21 = V_21 ;
F_48 ( V_9 , V_102 + V_101 , V_10 ) ;
V_10 -> V_48 = V_28 -> V_38 . V_71 ;
V_99 = F_35 ( V_62 , V_100 ) ;
F_36 ( V_99 , V_111 , 0 ) ;
V_99 -> V_29 = V_10 ;
V_99 -> V_69 = F_10 ;
F_34 ( & V_10 -> V_34 , 1 ) ;
for ( V_59 = 0 ; V_59 < V_21 ; V_59 ++ ) {
int V_70 = 0 ;
V_13 = V_10 -> V_22 [ V_59 ] ;
V_13 -> V_40 = V_9 -> V_50 ;
V_13 -> V_30 = V_102 >> V_46 ;
if ( V_99 -> V_38 . V_71 )
V_70 = V_52 -> V_54 -> V_72 ( V_13 , 0 ,
V_23 ,
V_99 , 0 ) ;
V_13 -> V_40 = NULL ;
if ( V_70 || F_37 ( V_99 , V_13 , V_23 , 0 ) <
V_23 ) {
F_38 ( V_99 ) ;
V_12 = F_40 ( V_2 , V_99 ,
V_73 ) ;
F_41 ( V_12 ) ;
F_39 ( & V_10 -> V_34 ) ;
if ( ! ( F_13 ( V_9 ) -> V_19 & V_20 ) ) {
V_12 = F_71 ( V_9 , V_99 ,
V_18 ) ;
F_41 ( V_12 ) ;
}
V_18 += F_3 ( V_99 -> V_38 . V_71 ,
V_2 -> V_7 ) ;
V_12 = F_43 ( V_2 , V_99 , V_25 , 0 ) ;
if ( V_12 ) {
V_99 -> V_32 = V_12 ;
F_20 ( V_99 ) ;
}
F_22 ( V_99 ) ;
V_99 = F_35 ( V_62 , V_100 ) ;
F_36 ( V_99 , V_111 , 0 ) ;
V_99 -> V_29 = V_10 ;
V_99 -> V_69 = F_10 ;
F_37 ( V_99 , V_13 , V_23 , 0 ) ;
}
V_100 += V_23 ;
}
F_38 ( V_99 ) ;
V_12 = F_40 ( V_2 , V_99 , V_73 ) ;
F_41 ( V_12 ) ;
if ( ! ( F_13 ( V_9 ) -> V_19 & V_20 ) ) {
V_12 = F_71 ( V_9 , V_99 , V_18 ) ;
F_41 ( V_12 ) ;
}
V_12 = F_43 ( V_2 , V_99 , V_25 , 0 ) ;
if ( V_12 ) {
V_99 -> V_32 = V_12 ;
F_20 ( V_99 ) ;
}
F_22 ( V_99 ) ;
return 0 ;
V_110:
while ( V_103 >= 0 ) {
F_72 ( V_10 -> V_22 [ V_103 ] ) ;
V_103 -- ;
}
F_21 ( V_10 -> V_22 ) ;
V_108:
F_21 ( V_10 ) ;
V_35:
F_63 ( V_83 ) ;
return V_12 ;
}
void T_7 F_73 ( void )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_112 ; V_14 ++ ) {
struct V_113 * V_114 ;
F_74 ( & V_115 [ V_14 ] . V_116 ) ;
F_75 ( & V_115 [ V_14 ] . V_117 ) ;
F_76 ( & V_115 [ V_14 ] . V_118 , 0 ) ;
F_77 ( & V_115 [ V_14 ] . V_119 ) ;
V_114 = V_120 [ V_14 ] -> F_78 () ;
if ( F_79 ( V_114 ) ) {
F_80 ( L_2 ) ;
} else {
F_76 ( & V_115 [ V_14 ] . V_118 , 1 ) ;
V_115 [ V_14 ] . V_121 = 1 ;
F_81 ( V_114 , & V_115 [ V_14 ] . V_116 ) ;
}
}
}
static struct V_113 * F_82 ( int type )
{
struct V_113 * V_114 ;
int V_122 = F_83 () ;
int V_123 = type - 1 ;
unsigned V_124 ;
struct V_113 * V_116 = & V_115 [ V_123 ] . V_116 ;
T_8 * V_117 = & V_115 [ V_123 ] . V_117 ;
T_9 * V_118 = & V_115 [ V_123 ] . V_118 ;
T_10 * V_119 = & V_115 [ V_123 ] . V_119 ;
int * V_121 = & V_115 [ V_123 ] . V_121 ;
V_125:
F_84 ( V_117 ) ;
if ( ! F_85 ( V_116 ) ) {
V_114 = V_116 -> V_91 ;
F_86 ( V_114 ) ;
( * V_121 ) -- ;
F_87 ( V_117 ) ;
return V_114 ;
}
if ( F_88 ( V_118 ) > V_122 ) {
F_89 ( V_126 ) ;
F_87 ( V_117 ) ;
F_90 ( V_119 , & V_126 , V_127 ) ;
if ( F_88 ( V_118 ) > V_122 && ! * V_121 )
F_91 () ;
F_92 ( V_119 , & V_126 ) ;
goto V_125;
}
F_93 ( V_118 ) ;
F_87 ( V_117 ) ;
V_124 = F_94 () ;
V_114 = V_120 [ V_123 ] -> F_78 () ;
F_95 ( V_124 ) ;
if ( F_79 ( V_114 ) ) {
F_96 ( V_118 ) ;
F_97 ( V_119 ) ;
if ( F_88 ( V_118 ) == 0 ) {
static F_98 ( V_128 ,
60 * V_129 ,
1 ) ;
if ( F_99 ( & V_128 ) ) {
F_80 ( L_3 ) ;
}
}
goto V_125;
}
return V_114 ;
}
static void F_100 ( int type , struct V_113 * V_114 )
{
int V_123 = type - 1 ;
struct V_113 * V_116 = & V_115 [ V_123 ] . V_116 ;
T_8 * V_117 = & V_115 [ V_123 ] . V_117 ;
T_9 * V_118 = & V_115 [ V_123 ] . V_118 ;
T_10 * V_119 = & V_115 [ V_123 ] . V_119 ;
int * V_121 = & V_115 [ V_123 ] . V_121 ;
F_84 ( V_117 ) ;
if ( * V_121 <= F_83 () ) {
F_81 ( V_114 , V_116 ) ;
( * V_121 ) ++ ;
F_87 ( V_117 ) ;
goto V_130;
}
F_87 ( V_117 ) ;
V_120 [ V_123 ] -> F_100 ( V_114 ) ;
F_96 ( V_118 ) ;
V_130:
F_101 () ;
if ( F_102 ( V_119 ) )
F_97 ( V_119 ) ;
}
static void F_103 ( void )
{
struct V_113 * V_114 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_112 ; V_14 ++ ) {
while ( ! F_85 ( & V_115 [ V_14 ] . V_116 ) ) {
V_114 = V_115 [ V_14 ] . V_116 . V_91 ;
F_86 ( V_114 ) ;
V_120 [ V_14 ] -> F_100 ( V_114 ) ;
F_96 ( & V_115 [ V_14 ] . V_118 ) ;
}
}
}
int F_104 ( int type , struct V_84 * V_40 ,
T_2 V_45 , struct V_13 * * V_49 ,
unsigned long * V_131 ,
unsigned long * V_132 ,
unsigned long * V_133 )
{
struct V_113 * V_114 ;
int V_12 ;
V_114 = F_82 ( type ) ;
V_12 = V_120 [ type - 1 ] -> F_105 ( V_114 , V_40 ,
V_45 , V_49 ,
V_131 ,
V_132 , V_133 ) ;
F_100 ( type , V_114 ) ;
return V_12 ;
}
static int F_14 ( struct V_6 * V_10 )
{
struct V_113 * V_114 ;
int V_12 ;
int type = V_10 -> V_107 ;
V_114 = F_82 ( type ) ;
V_12 = V_120 [ type - 1 ] -> F_106 ( V_114 , V_10 ) ;
F_100 ( type , V_114 ) ;
return V_12 ;
}
int F_107 ( int type , unsigned char * V_134 , struct V_13 * V_135 ,
unsigned long V_136 , T_6 V_137 , T_6 V_138 )
{
struct V_113 * V_114 ;
int V_12 ;
V_114 = F_82 ( type ) ;
V_12 = V_120 [ type - 1 ] -> F_108 ( V_114 , V_134 ,
V_135 , V_136 ,
V_137 , V_138 ) ;
F_100 ( type , V_114 ) ;
return V_12 ;
}
void F_109 ( void )
{
F_103 () ;
}
int F_110 ( const char * V_139 , unsigned long V_140 ,
unsigned long V_133 , T_2 V_11 ,
struct V_28 * V_28 )
{
unsigned long V_141 ;
unsigned long V_142 ;
unsigned long V_136 ;
unsigned long V_143 ;
unsigned long V_144 = V_133 - V_140 ;
unsigned long V_145 ;
char * V_15 ;
struct V_41 V_42 = F_111 ( V_28 , V_28 -> V_38 ) ;
V_136 = F_47 ( V_42 . V_44 ) - V_11 ;
if ( V_133 <= V_136 )
return 1 ;
if ( V_133 > V_136 && V_140 < V_136 ) {
V_141 = V_136 - V_140 ;
V_144 -= V_141 ;
} else {
V_141 = 0 ;
}
V_142 = V_140 ;
while ( V_144 > 0 ) {
V_145 = F_26 (unsigned long, bvec.bv_len,
PAGE_SIZE - buf_offset) ;
V_145 = F_112 ( V_145 , V_144 ) ;
V_15 = F_5 ( V_42 . V_44 ) ;
memcpy ( V_15 + V_42 . V_78 , V_139 + V_141 , V_145 ) ;
F_8 ( V_15 ) ;
F_66 ( V_42 . V_44 ) ;
V_141 += V_145 ;
V_144 -= V_145 ;
V_142 += V_145 ;
F_113 ( V_28 , V_145 ) ;
if ( ! V_28 -> V_38 . V_71 )
return 0 ;
V_42 = F_111 ( V_28 , V_28 -> V_38 ) ;
V_143 = V_136 ;
V_136 = F_47 ( V_42 . V_44 ) - V_11 ;
if ( V_136 != V_143 ) {
if ( V_133 <= V_136 )
return 1 ;
if ( V_133 > V_136 &&
V_142 < V_136 ) {
V_141 = V_136 - V_140 ;
V_144 = V_133 - V_136 ;
V_142 = V_140 + V_141 ;
}
}
}
return 1 ;
}
int F_114 ( struct V_9 * V_9 , T_2 V_45 , T_2 V_87 )
{
T_2 V_30 = V_45 >> V_46 ;
T_2 V_47 = V_87 >> V_46 ;
struct V_13 * V_13 ;
int V_12 = 1 ;
while ( V_30 <= V_47 ) {
V_13 = F_115 ( V_9 -> V_50 , V_30 ) ;
F_116 ( V_13 ) ;
F_117 ( V_13 ) ;
F_15 ( V_13 ) ;
V_30 ++ ;
}
return V_12 ;
}
