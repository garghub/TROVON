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
int V_12 ;
if ( V_28 -> V_31 )
V_10 -> V_32 = 1 ;
if ( ! F_11 ( & V_10 -> V_33 ) )
goto V_34;
V_9 = V_10 -> V_9 ;
V_12 = F_4 ( F_12 ( V_9 ) , V_10 ,
( T_2 ) V_28 -> V_35 . V_36 << 9 ) ;
if ( V_12 )
goto V_37;
V_12 = F_13 ( V_10 ) ;
V_37:
if ( V_12 )
V_10 -> V_32 = 1 ;
V_30 = 0 ;
for ( V_30 = 0 ; V_30 < V_10 -> V_21 ; V_30 ++ ) {
V_13 = V_10 -> V_22 [ V_30 ] ;
V_13 -> V_38 = NULL ;
F_14 ( V_13 ) ;
}
if ( V_10 -> V_32 ) {
F_15 ( V_10 -> V_39 ) ;
} else {
int V_14 ;
struct V_40 * V_41 ;
ASSERT ( ! F_16 ( V_28 , V_42 ) ) ;
F_17 (bvec, cb->orig_bio, i)
F_18 ( V_41 -> V_43 ) ;
F_19 ( V_10 -> V_39 ) ;
}
F_20 ( V_10 -> V_22 ) ;
F_20 ( V_10 ) ;
V_34:
F_21 ( V_28 ) ;
}
static T_4 void F_22 ( struct V_9 * V_9 ,
const struct V_6 * V_10 )
{
unsigned long V_30 = V_10 -> V_44 >> V_45 ;
unsigned long V_46 = ( V_10 -> V_44 + V_10 -> V_47 - 1 ) >> V_45 ;
struct V_13 * V_48 [ 16 ] ;
unsigned long V_21 = V_46 - V_30 + 1 ;
int V_14 ;
int V_12 ;
if ( V_10 -> V_32 )
F_23 ( V_9 -> V_49 , - V_26 ) ;
while ( V_21 > 0 ) {
V_12 = F_24 ( V_9 -> V_49 , V_30 ,
F_25 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_48 ) ;
if ( V_12 == 0 ) {
V_21 -= 1 ;
V_30 += 1 ;
continue;
}
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ ) {
if ( V_10 -> V_32 )
F_26 ( V_48 [ V_14 ] ) ;
F_27 ( V_48 [ V_14 ] ) ;
F_14 ( V_48 [ V_14 ] ) ;
}
V_21 -= V_12 ;
V_30 += V_12 ;
}
}
static void F_28 ( struct V_28 * V_28 )
{
struct V_50 * V_51 ;
struct V_6 * V_10 = V_28 -> V_29 ;
struct V_9 * V_9 ;
struct V_13 * V_13 ;
unsigned long V_30 ;
if ( V_28 -> V_31 )
V_10 -> V_32 = 1 ;
if ( ! F_11 ( & V_10 -> V_33 ) )
goto V_34;
V_9 = V_10 -> V_9 ;
V_51 = & F_12 ( V_9 ) -> V_52 ;
V_10 -> V_22 [ 0 ] -> V_38 = V_10 -> V_9 -> V_49 ;
V_51 -> V_53 -> V_54 ( V_10 -> V_22 [ 0 ] ,
V_10 -> V_44 ,
V_10 -> V_44 + V_10 -> V_47 - 1 ,
NULL ,
V_28 -> V_31 ? 0 : 1 ) ;
V_10 -> V_22 [ 0 ] -> V_38 = NULL ;
F_22 ( V_9 , V_10 ) ;
V_30 = 0 ;
for ( V_30 = 0 ; V_30 < V_10 -> V_21 ; V_30 ++ ) {
V_13 = V_10 -> V_22 [ V_30 ] ;
V_13 -> V_38 = NULL ;
F_14 ( V_13 ) ;
}
F_20 ( V_10 -> V_22 ) ;
F_20 ( V_10 ) ;
V_34:
F_21 ( V_28 ) ;
}
T_5 F_29 ( struct V_9 * V_9 , T_2 V_44 ,
unsigned long V_47 , T_2 V_11 ,
unsigned long V_55 ,
struct V_13 * * V_22 ,
unsigned long V_21 )
{
struct V_1 * V_2 = F_30 ( V_9 -> V_56 ) ;
struct V_28 * V_28 = NULL ;
struct V_6 * V_10 ;
unsigned long V_57 ;
struct V_50 * V_52 = & F_12 ( V_9 ) -> V_52 ;
int V_58 = 0 ;
struct V_13 * V_13 ;
T_2 V_59 = V_11 ;
struct V_60 * V_61 ;
T_5 V_12 ;
int V_62 = F_12 ( V_9 ) -> V_19 & V_20 ;
F_31 ( V_44 & ( ( T_2 ) V_23 - 1 ) ) ;
V_10 = F_32 ( F_1 ( V_2 , V_55 ) , V_63 ) ;
if ( ! V_10 )
return V_64 ;
F_33 ( & V_10 -> V_33 , 0 ) ;
V_10 -> V_32 = 0 ;
V_10 -> V_9 = V_9 ;
V_10 -> V_44 = V_44 ;
V_10 -> V_47 = V_47 ;
V_10 -> V_25 = 0 ;
V_10 -> V_22 = V_22 ;
V_10 -> V_55 = V_55 ;
V_10 -> V_39 = NULL ;
V_10 -> V_21 = V_21 ;
V_61 = V_2 -> V_65 -> V_66 ;
V_28 = F_34 ( V_61 , V_59 ) ;
F_35 ( V_28 , V_67 , 0 ) ;
V_28 -> V_29 = V_10 ;
V_28 -> V_68 = F_28 ;
F_33 ( & V_10 -> V_33 , 1 ) ;
V_57 = V_55 ;
for ( V_58 = 0 ; V_58 < V_10 -> V_21 ; V_58 ++ ) {
int V_69 = 0 ;
V_13 = V_22 [ V_58 ] ;
V_13 -> V_38 = V_9 -> V_49 ;
if ( V_28 -> V_35 . V_70 )
V_69 = V_52 -> V_53 -> V_71 ( V_13 , 0 ,
V_23 ,
V_28 , 0 ) ;
V_13 -> V_38 = NULL ;
if ( V_69 || F_36 ( V_28 , V_13 , V_23 , 0 ) <
V_23 ) {
F_37 ( V_28 ) ;
F_38 ( & V_10 -> V_33 ) ;
V_12 = F_39 ( V_2 , V_28 ,
V_72 ) ;
F_40 ( V_12 ) ;
if ( ! V_62 ) {
V_12 = F_41 ( V_9 , V_28 , V_44 , 1 ) ;
F_40 ( V_12 ) ;
}
V_12 = F_42 ( V_2 , V_28 , 0 , 1 ) ;
if ( V_12 ) {
V_28 -> V_31 = V_12 ;
F_19 ( V_28 ) ;
}
F_21 ( V_28 ) ;
V_28 = F_34 ( V_61 , V_59 ) ;
F_35 ( V_28 , V_67 , 0 ) ;
V_28 -> V_29 = V_10 ;
V_28 -> V_68 = F_28 ;
F_36 ( V_28 , V_13 , V_23 , 0 ) ;
}
if ( V_57 < V_23 ) {
F_43 ( V_2 ,
L_1 ,
V_57 , V_10 -> V_55 , V_10 -> V_21 ) ;
}
V_57 -= V_23 ;
V_59 += V_23 ;
F_44 () ;
}
F_37 ( V_28 ) ;
V_12 = F_39 ( V_2 , V_28 , V_72 ) ;
F_40 ( V_12 ) ;
if ( ! V_62 ) {
V_12 = F_41 ( V_9 , V_28 , V_44 , 1 ) ;
F_40 ( V_12 ) ;
}
V_12 = F_42 ( V_2 , V_28 , 0 , 1 ) ;
if ( V_12 ) {
V_28 -> V_31 = V_12 ;
F_19 ( V_28 ) ;
}
F_21 ( V_28 ) ;
return 0 ;
}
static T_2 F_45 ( struct V_28 * V_28 )
{
struct V_40 * V_73 = & V_28 -> V_74 [ V_28 -> V_75 - 1 ] ;
return F_46 ( V_73 -> V_43 ) + V_73 -> V_76 + V_73 -> V_77 ;
}
static T_4 int F_47 ( struct V_9 * V_9 ,
T_2 V_78 ,
struct V_6 * V_10 )
{
unsigned long V_46 ;
unsigned long V_58 ;
T_2 V_79 ;
T_2 V_80 = F_48 ( V_9 ) ;
int V_12 ;
struct V_13 * V_13 ;
unsigned long V_21 = 0 ;
struct V_81 * V_82 ;
struct V_83 * V_38 = V_9 -> V_49 ;
struct V_84 * V_85 ;
struct V_50 * V_51 ;
T_2 V_86 ;
int V_87 = 0 ;
V_79 = F_45 ( V_10 -> V_39 ) ;
V_85 = & F_12 ( V_9 ) -> V_88 ;
V_51 = & F_12 ( V_9 ) -> V_52 ;
if ( V_80 == 0 )
return 0 ;
V_46 = ( F_48 ( V_9 ) - 1 ) >> V_45 ;
while ( V_79 < V_78 ) {
V_58 = V_79 >> V_45 ;
if ( V_58 > V_46 )
break;
F_49 () ;
V_13 = F_50 ( & V_38 -> V_89 , V_58 ) ;
F_51 () ;
if ( V_13 && ! F_52 ( V_13 ) ) {
V_87 ++ ;
if ( V_87 > 4 )
break;
goto V_90;
}
V_13 = F_53 ( F_54 ( V_38 ,
~ V_91 ) ) ;
if ( ! V_13 )
break;
if ( F_55 ( V_13 , V_38 , V_58 , V_63 ) ) {
F_14 ( V_13 ) ;
goto V_90;
}
V_86 = V_79 + V_23 - 1 ;
F_56 ( V_13 ) ;
F_57 ( V_51 , V_79 , V_86 ) ;
F_58 ( & V_85 -> V_92 ) ;
V_82 = F_59 ( V_85 , V_79 ,
V_23 ) ;
F_60 ( & V_85 -> V_92 ) ;
if ( ! V_82 || V_79 < V_82 -> V_44 ||
( V_79 + V_23 > F_61 ( V_82 ) ) ||
( V_82 -> V_93 >> 9 ) != V_10 -> V_39 -> V_35 . V_36 ) {
F_62 ( V_82 ) ;
F_63 ( V_51 , V_79 , V_86 ) ;
F_64 ( V_13 ) ;
F_14 ( V_13 ) ;
break;
}
F_62 ( V_82 ) ;
if ( V_13 -> V_30 == V_46 ) {
char * V_94 ;
T_6 V_95 = V_80 & ( V_23 - 1 ) ;
if ( V_95 ) {
int V_96 ;
V_96 = V_23 - V_95 ;
V_94 = F_5 ( V_13 ) ;
memset ( V_94 + V_95 , 0 , V_96 ) ;
F_65 ( V_13 ) ;
F_8 ( V_94 ) ;
}
}
V_12 = F_36 ( V_10 -> V_39 , V_13 ,
V_23 , 0 ) ;
if ( V_12 == V_23 ) {
V_21 ++ ;
F_14 ( V_13 ) ;
} else {
F_63 ( V_51 , V_79 , V_86 ) ;
F_64 ( V_13 ) ;
F_14 ( V_13 ) ;
break;
}
V_90:
V_79 += V_23 ;
}
return 0 ;
}
T_5 F_66 ( struct V_9 * V_9 , struct V_28 * V_28 ,
int V_25 , unsigned long V_97 )
{
struct V_1 * V_2 = F_30 ( V_9 -> V_56 ) ;
struct V_50 * V_51 ;
struct V_84 * V_85 ;
struct V_6 * V_10 ;
unsigned long V_55 ;
unsigned long V_21 ;
unsigned long V_58 ;
struct V_13 * V_13 ;
struct V_60 * V_61 ;
struct V_28 * V_98 ;
T_2 V_99 = ( T_2 ) V_28 -> V_35 . V_36 << 9 ;
T_2 V_100 ;
T_2 V_101 ;
struct V_81 * V_82 ;
T_5 V_12 = V_64 ;
int V_102 = 0 ;
T_3 * V_18 ;
V_51 = & F_12 ( V_9 ) -> V_52 ;
V_85 = & F_12 ( V_9 ) -> V_88 ;
F_58 ( & V_85 -> V_92 ) ;
V_82 = F_59 ( V_85 ,
F_46 ( V_28 -> V_74 -> V_43 ) ,
V_23 ) ;
F_60 ( & V_85 -> V_92 ) ;
if ( ! V_82 )
return V_103 ;
V_55 = V_82 -> V_104 ;
V_10 = F_32 ( F_1 ( V_2 , V_55 ) , V_63 ) ;
if ( ! V_10 )
goto V_34;
F_33 ( & V_10 -> V_33 , 0 ) ;
V_10 -> V_32 = 0 ;
V_10 -> V_9 = V_9 ;
V_10 -> V_25 = V_25 ;
V_18 = & V_10 -> V_18 ;
V_10 -> V_44 = V_82 -> V_105 ;
V_100 = V_82 -> V_47 ;
V_101 = V_82 -> V_44 ;
F_62 ( V_82 ) ;
V_82 = NULL ;
V_10 -> V_47 = V_28 -> V_35 . V_70 ;
V_10 -> V_55 = V_55 ;
V_10 -> V_106 = F_67 ( V_97 ) ;
V_10 -> V_39 = V_28 ;
V_21 = F_3 ( V_55 , V_23 ) ;
V_10 -> V_22 = F_68 ( V_21 , sizeof( struct V_13 * ) ,
V_63 ) ;
if ( ! V_10 -> V_22 )
goto V_107;
V_61 = V_2 -> V_65 -> V_66 ;
for ( V_58 = 0 ; V_58 < V_21 ; V_58 ++ ) {
V_10 -> V_22 [ V_58 ] = F_69 ( V_63 |
V_108 ) ;
if ( ! V_10 -> V_22 [ V_58 ] ) {
V_102 = V_58 - 1 ;
V_12 = V_64 ;
goto V_109;
}
}
V_102 = V_21 - 1 ;
V_10 -> V_21 = V_21 ;
F_47 ( V_9 , V_101 + V_100 , V_10 ) ;
V_10 -> V_47 = V_28 -> V_35 . V_70 ;
V_98 = F_34 ( V_61 , V_99 ) ;
F_35 ( V_98 , V_110 , 0 ) ;
V_98 -> V_29 = V_10 ;
V_98 -> V_68 = F_10 ;
F_33 ( & V_10 -> V_33 , 1 ) ;
for ( V_58 = 0 ; V_58 < V_21 ; V_58 ++ ) {
int V_69 = 0 ;
V_13 = V_10 -> V_22 [ V_58 ] ;
V_13 -> V_38 = V_9 -> V_49 ;
V_13 -> V_30 = V_101 >> V_45 ;
if ( V_98 -> V_35 . V_70 )
V_69 = V_51 -> V_53 -> V_71 ( V_13 , 0 ,
V_23 ,
V_98 , 0 ) ;
V_13 -> V_38 = NULL ;
if ( V_69 || F_36 ( V_98 , V_13 , V_23 , 0 ) <
V_23 ) {
F_37 ( V_98 ) ;
V_12 = F_39 ( V_2 , V_98 ,
V_72 ) ;
F_40 ( V_12 ) ;
F_38 ( & V_10 -> V_33 ) ;
if ( ! ( F_12 ( V_9 ) -> V_19 & V_20 ) ) {
V_12 = F_70 ( V_9 , V_98 ,
V_18 ) ;
F_40 ( V_12 ) ;
}
V_18 += F_3 ( V_98 -> V_35 . V_70 ,
V_2 -> V_7 ) ;
V_12 = F_42 ( V_2 , V_98 , V_25 , 0 ) ;
if ( V_12 ) {
V_98 -> V_31 = V_12 ;
F_19 ( V_98 ) ;
}
F_21 ( V_98 ) ;
V_98 = F_34 ( V_61 , V_99 ) ;
F_35 ( V_98 , V_110 , 0 ) ;
V_98 -> V_29 = V_10 ;
V_98 -> V_68 = F_10 ;
F_36 ( V_98 , V_13 , V_23 , 0 ) ;
}
V_99 += V_23 ;
}
F_37 ( V_98 ) ;
V_12 = F_39 ( V_2 , V_98 , V_72 ) ;
F_40 ( V_12 ) ;
if ( ! ( F_12 ( V_9 ) -> V_19 & V_20 ) ) {
V_12 = F_70 ( V_9 , V_98 , V_18 ) ;
F_40 ( V_12 ) ;
}
V_12 = F_42 ( V_2 , V_98 , V_25 , 0 ) ;
if ( V_12 ) {
V_98 -> V_31 = V_12 ;
F_19 ( V_98 ) ;
}
F_21 ( V_98 ) ;
return 0 ;
V_109:
while ( V_102 >= 0 ) {
F_71 ( V_10 -> V_22 [ V_102 ] ) ;
V_102 -- ;
}
F_20 ( V_10 -> V_22 ) ;
V_107:
F_20 ( V_10 ) ;
V_34:
F_62 ( V_82 ) ;
return V_12 ;
}
void T_7 F_72 ( void )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_111 ; V_14 ++ ) {
struct V_112 * V_113 ;
F_73 ( & V_114 [ V_14 ] . V_115 ) ;
F_74 ( & V_114 [ V_14 ] . V_116 ) ;
F_75 ( & V_114 [ V_14 ] . V_117 , 0 ) ;
F_76 ( & V_114 [ V_14 ] . V_118 ) ;
V_113 = V_119 [ V_14 ] -> F_77 () ;
if ( F_78 ( V_113 ) ) {
F_79 ( L_2 ) ;
} else {
F_75 ( & V_114 [ V_14 ] . V_117 , 1 ) ;
V_114 [ V_14 ] . V_120 = 1 ;
F_80 ( V_113 , & V_114 [ V_14 ] . V_115 ) ;
}
}
}
static struct V_112 * F_81 ( int type )
{
struct V_112 * V_113 ;
int V_121 = F_82 () ;
int V_122 = type - 1 ;
unsigned V_123 ;
struct V_112 * V_115 = & V_114 [ V_122 ] . V_115 ;
T_8 * V_116 = & V_114 [ V_122 ] . V_116 ;
T_9 * V_117 = & V_114 [ V_122 ] . V_117 ;
T_10 * V_118 = & V_114 [ V_122 ] . V_118 ;
int * V_120 = & V_114 [ V_122 ] . V_120 ;
V_124:
F_83 ( V_116 ) ;
if ( ! F_84 ( V_115 ) ) {
V_113 = V_115 -> V_90 ;
F_85 ( V_113 ) ;
( * V_120 ) -- ;
F_86 ( V_116 ) ;
return V_113 ;
}
if ( F_87 ( V_117 ) > V_121 ) {
F_88 ( V_125 ) ;
F_86 ( V_116 ) ;
F_89 ( V_118 , & V_125 , V_126 ) ;
if ( F_87 ( V_117 ) > V_121 && ! * V_120 )
F_90 () ;
F_91 ( V_118 , & V_125 ) ;
goto V_124;
}
F_92 ( V_117 ) ;
F_86 ( V_116 ) ;
V_123 = F_93 () ;
V_113 = V_119 [ V_122 ] -> F_77 () ;
F_94 ( V_123 ) ;
if ( F_78 ( V_113 ) ) {
F_95 ( V_117 ) ;
F_96 ( V_118 ) ;
if ( F_87 ( V_117 ) == 0 ) {
static F_97 ( V_127 ,
60 * V_128 ,
1 ) ;
if ( F_98 ( & V_127 ) ) {
F_79 ( L_3 ) ;
}
}
goto V_124;
}
return V_113 ;
}
static void F_99 ( int type , struct V_112 * V_113 )
{
int V_122 = type - 1 ;
struct V_112 * V_115 = & V_114 [ V_122 ] . V_115 ;
T_8 * V_116 = & V_114 [ V_122 ] . V_116 ;
T_9 * V_117 = & V_114 [ V_122 ] . V_117 ;
T_10 * V_118 = & V_114 [ V_122 ] . V_118 ;
int * V_120 = & V_114 [ V_122 ] . V_120 ;
F_83 ( V_116 ) ;
if ( * V_120 < F_82 () ) {
F_80 ( V_113 , V_115 ) ;
( * V_120 ) ++ ;
F_86 ( V_116 ) ;
goto V_129;
}
F_86 ( V_116 ) ;
V_119 [ V_122 ] -> F_99 ( V_113 ) ;
F_95 ( V_117 ) ;
V_129:
F_100 () ;
if ( F_101 ( V_118 ) )
F_96 ( V_118 ) ;
}
static void F_102 ( void )
{
struct V_112 * V_113 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_111 ; V_14 ++ ) {
while ( ! F_84 ( & V_114 [ V_14 ] . V_115 ) ) {
V_113 = V_114 [ V_14 ] . V_115 . V_90 ;
F_85 ( V_113 ) ;
V_119 [ V_14 ] -> F_99 ( V_113 ) ;
F_95 ( & V_114 [ V_14 ] . V_117 ) ;
}
}
}
int F_103 ( int type , struct V_83 * V_38 ,
T_2 V_44 , struct V_13 * * V_48 ,
unsigned long * V_130 ,
unsigned long * V_131 ,
unsigned long * V_132 )
{
struct V_112 * V_113 ;
int V_12 ;
V_113 = F_81 ( type ) ;
V_12 = V_119 [ type - 1 ] -> F_104 ( V_113 , V_38 ,
V_44 , V_48 ,
V_130 ,
V_131 , V_132 ) ;
F_99 ( type , V_113 ) ;
return V_12 ;
}
static int F_13 ( struct V_6 * V_10 )
{
struct V_112 * V_113 ;
int V_12 ;
int type = V_10 -> V_106 ;
V_113 = F_81 ( type ) ;
V_12 = V_119 [ type - 1 ] -> F_105 ( V_113 , V_10 ) ;
F_99 ( type , V_113 ) ;
return V_12 ;
}
int F_106 ( int type , unsigned char * V_133 , struct V_13 * V_134 ,
unsigned long V_135 , T_6 V_136 , T_6 V_137 )
{
struct V_112 * V_113 ;
int V_12 ;
V_113 = F_81 ( type ) ;
V_12 = V_119 [ type - 1 ] -> F_107 ( V_113 , V_133 ,
V_134 , V_135 ,
V_136 , V_137 ) ;
F_99 ( type , V_113 ) ;
return V_12 ;
}
void F_108 ( void )
{
F_102 () ;
}
int F_109 ( const char * V_138 , unsigned long V_139 ,
unsigned long V_132 , T_2 V_11 ,
struct V_28 * V_28 )
{
unsigned long V_140 ;
unsigned long V_141 ;
unsigned long V_135 ;
unsigned long V_142 ;
unsigned long V_143 = V_132 - V_139 ;
unsigned long V_144 ;
char * V_15 ;
struct V_40 V_41 = F_110 ( V_28 , V_28 -> V_35 ) ;
V_135 = F_46 ( V_41 . V_43 ) - V_11 ;
if ( V_132 <= V_135 )
return 1 ;
if ( V_132 > V_135 && V_139 < V_135 ) {
V_140 = V_135 - V_139 ;
V_143 -= V_140 ;
} else {
V_140 = 0 ;
}
V_141 = V_139 ;
while ( V_143 > 0 ) {
V_144 = F_25 (unsigned long, bvec.bv_len,
PAGE_SIZE - buf_offset) ;
V_144 = F_111 ( V_144 , V_143 ) ;
V_15 = F_5 ( V_41 . V_43 ) ;
memcpy ( V_15 + V_41 . V_77 , V_138 + V_140 , V_144 ) ;
F_8 ( V_15 ) ;
F_65 ( V_41 . V_43 ) ;
V_140 += V_144 ;
V_143 -= V_144 ;
V_141 += V_144 ;
F_112 ( V_28 , V_144 ) ;
if ( ! V_28 -> V_35 . V_70 )
return 0 ;
V_41 = F_110 ( V_28 , V_28 -> V_35 ) ;
V_142 = V_135 ;
V_135 = F_46 ( V_41 . V_43 ) - V_11 ;
if ( V_135 != V_142 ) {
if ( V_132 <= V_135 )
return 1 ;
if ( V_132 > V_135 &&
V_141 < V_135 ) {
V_140 = V_135 - V_139 ;
V_143 = V_132 - V_135 ;
V_141 = V_139 + V_140 ;
}
}
}
return 1 ;
}
