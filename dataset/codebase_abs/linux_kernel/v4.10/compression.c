static inline int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
T_1 V_4 = F_2 ( V_2 -> V_5 ) ;
return sizeof( struct V_6 ) +
( F_3 ( V_3 , V_2 -> V_7 ) ) * V_4 ;
}
static struct V_8 * F_4 ( struct V_9 * V_10 ,
T_2 V_11 , T_3 V_12 )
{
return F_5 ( V_10 , V_11 >> 9 , V_13 , V_12 ) ;
}
static int F_6 ( struct V_14 * V_14 ,
struct V_6 * V_15 ,
T_2 V_16 )
{
int V_17 ;
struct V_18 * V_18 ;
unsigned long V_19 ;
char * V_20 ;
T_4 V_21 ;
T_4 * V_22 = & V_15 -> V_23 ;
if ( F_7 ( V_14 ) -> V_24 & V_25 )
return 0 ;
for ( V_19 = 0 ; V_19 < V_15 -> V_26 ; V_19 ++ ) {
V_18 = V_15 -> V_27 [ V_19 ] ;
V_21 = ~ ( T_4 ) 0 ;
V_20 = F_8 ( V_18 ) ;
V_21 = F_9 ( V_20 , V_21 , V_28 ) ;
F_10 ( V_21 , ( V_29 * ) & V_21 ) ;
F_11 ( V_20 ) ;
if ( V_21 != * V_22 ) {
F_12 ( F_7 ( V_14 ) -> V_30 -> V_2 ,
L_1 ,
F_13 ( V_14 ) , V_16 , V_21 , * V_22 ,
V_15 -> V_31 ) ;
V_17 = - V_32 ;
goto V_33;
}
V_22 ++ ;
}
V_17 = 0 ;
V_33:
return V_17 ;
}
static void F_14 ( struct V_8 * V_8 )
{
struct V_6 * V_15 = V_8 -> V_34 ;
struct V_14 * V_14 ;
struct V_18 * V_18 ;
unsigned long V_35 ;
int V_17 ;
if ( V_8 -> V_36 )
V_15 -> V_37 = 1 ;
if ( ! F_15 ( & V_15 -> V_38 ) )
goto V_39;
V_14 = V_15 -> V_14 ;
V_17 = F_6 ( V_14 , V_15 ,
( T_2 ) V_8 -> V_40 . V_41 << 9 ) ;
if ( V_17 )
goto V_42;
V_17 = F_16 ( V_15 -> V_43 ,
V_15 -> V_27 ,
V_15 -> V_44 ,
V_15 -> V_45 ,
V_15 -> V_46 ) ;
V_42:
if ( V_17 )
V_15 -> V_37 = 1 ;
V_35 = 0 ;
for ( V_35 = 0 ; V_35 < V_15 -> V_26 ; V_35 ++ ) {
V_18 = V_15 -> V_27 [ V_35 ] ;
V_18 -> V_47 = NULL ;
F_17 ( V_18 ) ;
}
if ( V_15 -> V_37 ) {
F_18 ( V_15 -> V_45 ) ;
} else {
int V_19 ;
struct V_48 * V_49 ;
F_19 (bvec, cb->orig_bio, i)
F_20 ( V_49 -> V_50 ) ;
F_21 ( V_15 -> V_45 ) ;
}
F_22 ( V_15 -> V_27 ) ;
F_22 ( V_15 ) ;
V_39:
F_23 ( V_8 ) ;
}
static T_5 void F_24 ( struct V_14 * V_14 ,
const struct V_6 * V_15 )
{
unsigned long V_35 = V_15 -> V_44 >> V_51 ;
unsigned long V_52 = ( V_15 -> V_44 + V_15 -> V_53 - 1 ) >> V_51 ;
struct V_18 * V_54 [ 16 ] ;
unsigned long V_26 = V_52 - V_35 + 1 ;
int V_19 ;
int V_17 ;
if ( V_15 -> V_37 )
F_25 ( V_14 -> V_55 , - V_32 ) ;
while ( V_26 > 0 ) {
V_17 = F_26 ( V_14 -> V_55 , V_35 ,
F_27 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_54 ) ;
if ( V_17 == 0 ) {
V_26 -= 1 ;
V_35 += 1 ;
continue;
}
for ( V_19 = 0 ; V_19 < V_17 ; V_19 ++ ) {
if ( V_15 -> V_37 )
F_28 ( V_54 [ V_19 ] ) ;
F_29 ( V_54 [ V_19 ] ) ;
F_17 ( V_54 [ V_19 ] ) ;
}
V_26 -= V_17 ;
V_35 += V_17 ;
}
}
static void F_30 ( struct V_8 * V_8 )
{
struct V_56 * V_57 ;
struct V_6 * V_15 = V_8 -> V_34 ;
struct V_14 * V_14 ;
struct V_18 * V_18 ;
unsigned long V_35 ;
if ( V_8 -> V_36 )
V_15 -> V_37 = 1 ;
if ( ! F_15 ( & V_15 -> V_38 ) )
goto V_39;
V_14 = V_15 -> V_14 ;
V_57 = & F_7 ( V_14 ) -> V_58 ;
V_15 -> V_27 [ 0 ] -> V_47 = V_15 -> V_14 -> V_55 ;
V_57 -> V_59 -> V_60 ( V_15 -> V_27 [ 0 ] ,
V_15 -> V_44 ,
V_15 -> V_44 + V_15 -> V_53 - 1 ,
NULL ,
V_8 -> V_36 ? 0 : 1 ) ;
V_15 -> V_27 [ 0 ] -> V_47 = NULL ;
F_24 ( V_14 , V_15 ) ;
V_35 = 0 ;
for ( V_35 = 0 ; V_35 < V_15 -> V_26 ; V_35 ++ ) {
V_18 = V_15 -> V_27 [ V_35 ] ;
V_18 -> V_47 = NULL ;
F_17 ( V_18 ) ;
}
F_22 ( V_15 -> V_27 ) ;
F_22 ( V_15 ) ;
V_39:
F_23 ( V_8 ) ;
}
int F_31 ( struct V_14 * V_14 , T_2 V_44 ,
unsigned long V_53 , T_2 V_16 ,
unsigned long V_46 ,
struct V_18 * * V_27 ,
unsigned long V_26 )
{
struct V_1 * V_2 = F_32 ( V_14 -> V_61 ) ;
struct V_8 * V_8 = NULL ;
struct V_6 * V_15 ;
unsigned long V_62 ;
struct V_56 * V_58 = & F_7 ( V_14 ) -> V_58 ;
int V_63 = 0 ;
struct V_18 * V_18 ;
T_2 V_11 = V_16 ;
struct V_9 * V_10 ;
int V_17 ;
int V_64 = F_7 ( V_14 ) -> V_24 & V_25 ;
F_33 ( V_44 & ( ( T_2 ) V_28 - 1 ) ) ;
V_15 = F_34 ( F_1 ( V_2 , V_46 ) , V_65 ) ;
if ( ! V_15 )
return - V_66 ;
F_35 ( & V_15 -> V_38 , 0 ) ;
V_15 -> V_37 = 0 ;
V_15 -> V_14 = V_14 ;
V_15 -> V_44 = V_44 ;
V_15 -> V_53 = V_53 ;
V_15 -> V_31 = 0 ;
V_15 -> V_27 = V_27 ;
V_15 -> V_46 = V_46 ;
V_15 -> V_45 = NULL ;
V_15 -> V_26 = V_26 ;
V_10 = V_2 -> V_67 -> V_68 ;
V_8 = F_4 ( V_10 , V_11 , V_65 ) ;
if ( ! V_8 ) {
F_22 ( V_15 ) ;
return - V_66 ;
}
F_36 ( V_8 , V_69 , 0 ) ;
V_8 -> V_34 = V_15 ;
V_8 -> V_70 = F_30 ;
F_37 ( & V_15 -> V_38 ) ;
V_62 = V_46 ;
for ( V_63 = 0 ; V_63 < V_15 -> V_26 ; V_63 ++ ) {
V_18 = V_27 [ V_63 ] ;
V_18 -> V_47 = V_14 -> V_55 ;
if ( V_8 -> V_40 . V_71 )
V_17 = V_58 -> V_59 -> V_72 ( V_18 , 0 ,
V_28 ,
V_8 , 0 ) ;
else
V_17 = 0 ;
V_18 -> V_47 = NULL ;
if ( V_17 || F_38 ( V_8 , V_18 , V_28 , 0 ) <
V_28 ) {
F_39 ( V_8 ) ;
F_37 ( & V_15 -> V_38 ) ;
V_17 = F_40 ( V_2 , V_8 ,
V_73 ) ;
F_41 ( V_17 ) ;
if ( ! V_64 ) {
V_17 = F_42 ( V_14 , V_8 , V_44 , 1 ) ;
F_41 ( V_17 ) ;
}
V_17 = F_43 ( V_2 , V_8 , 0 , 1 ) ;
if ( V_17 ) {
V_8 -> V_36 = V_17 ;
F_21 ( V_8 ) ;
}
F_23 ( V_8 ) ;
V_8 = F_4 ( V_10 , V_11 , V_65 ) ;
F_41 ( ! V_8 ) ;
F_36 ( V_8 , V_69 , 0 ) ;
V_8 -> V_34 = V_15 ;
V_8 -> V_70 = F_30 ;
F_38 ( V_8 , V_18 , V_28 , 0 ) ;
}
if ( V_62 < V_28 ) {
F_12 ( V_2 ,
L_2 ,
V_62 , V_15 -> V_46 , V_15 -> V_26 ) ;
}
V_62 -= V_28 ;
V_11 += V_28 ;
F_44 () ;
}
F_39 ( V_8 ) ;
V_17 = F_40 ( V_2 , V_8 , V_73 ) ;
F_41 ( V_17 ) ;
if ( ! V_64 ) {
V_17 = F_42 ( V_14 , V_8 , V_44 , 1 ) ;
F_41 ( V_17 ) ;
}
V_17 = F_43 ( V_2 , V_8 , 0 , 1 ) ;
if ( V_17 ) {
V_8 -> V_36 = V_17 ;
F_21 ( V_8 ) ;
}
F_23 ( V_8 ) ;
return 0 ;
}
static T_2 F_45 ( struct V_8 * V_8 )
{
struct V_48 * V_74 = & V_8 -> V_75 [ V_8 -> V_76 - 1 ] ;
return F_46 ( V_74 -> V_50 ) + V_74 -> V_77 + V_74 -> V_78 ;
}
static T_5 int F_47 ( struct V_14 * V_14 ,
T_2 V_79 ,
struct V_6 * V_15 )
{
unsigned long V_52 ;
unsigned long V_63 ;
T_2 V_80 ;
T_2 V_81 = F_48 ( V_14 ) ;
int V_17 ;
struct V_18 * V_18 ;
unsigned long V_26 = 0 ;
struct V_82 * V_83 ;
struct V_84 * V_47 = V_14 -> V_55 ;
struct V_85 * V_86 ;
struct V_56 * V_57 ;
T_2 V_87 ;
int V_88 = 0 ;
V_80 = F_45 ( V_15 -> V_45 ) ;
V_86 = & F_7 ( V_14 ) -> V_89 ;
V_57 = & F_7 ( V_14 ) -> V_58 ;
if ( V_81 == 0 )
return 0 ;
V_52 = ( F_48 ( V_14 ) - 1 ) >> V_51 ;
while ( V_80 < V_79 ) {
V_63 = V_80 >> V_51 ;
if ( V_63 > V_52 )
break;
F_49 () ;
V_18 = F_50 ( & V_47 -> V_90 , V_63 ) ;
F_51 () ;
if ( V_18 && ! F_52 ( V_18 ) ) {
V_88 ++ ;
if ( V_88 > 4 )
break;
goto V_91;
}
V_18 = F_53 ( F_54 ( V_47 ,
~ V_92 ) ) ;
if ( ! V_18 )
break;
if ( F_55 ( V_18 , V_47 , V_63 , V_65 ) ) {
F_17 ( V_18 ) ;
goto V_91;
}
V_87 = V_80 + V_28 - 1 ;
F_56 ( V_18 ) ;
F_57 ( V_57 , V_80 , V_87 ) ;
F_58 ( & V_86 -> V_93 ) ;
V_83 = F_59 ( V_86 , V_80 ,
V_28 ) ;
F_60 ( & V_86 -> V_93 ) ;
if ( ! V_83 || V_80 < V_83 -> V_44 ||
( V_80 + V_28 > F_61 ( V_83 ) ) ||
( V_83 -> V_94 >> 9 ) != V_15 -> V_45 -> V_40 . V_41 ) {
F_62 ( V_83 ) ;
F_63 ( V_57 , V_80 , V_87 ) ;
F_64 ( V_18 ) ;
F_17 ( V_18 ) ;
break;
}
F_62 ( V_83 ) ;
if ( V_18 -> V_35 == V_52 ) {
char * V_95 ;
T_6 V_96 = V_81 & ( V_28 - 1 ) ;
if ( V_96 ) {
int V_97 ;
V_97 = V_28 - V_96 ;
V_95 = F_8 ( V_18 ) ;
memset ( V_95 + V_96 , 0 , V_97 ) ;
F_65 ( V_18 ) ;
F_11 ( V_95 ) ;
}
}
V_17 = F_38 ( V_15 -> V_45 , V_18 ,
V_28 , 0 ) ;
if ( V_17 == V_28 ) {
V_26 ++ ;
F_17 ( V_18 ) ;
} else {
F_63 ( V_57 , V_80 , V_87 ) ;
F_64 ( V_18 ) ;
F_17 ( V_18 ) ;
break;
}
V_91:
V_80 += V_28 ;
}
return 0 ;
}
int F_66 ( struct V_14 * V_14 , struct V_8 * V_8 ,
int V_31 , unsigned long V_98 )
{
struct V_1 * V_2 = F_32 ( V_14 -> V_61 ) ;
struct V_56 * V_57 ;
struct V_85 * V_86 ;
struct V_6 * V_15 ;
unsigned long V_46 ;
unsigned long V_26 ;
unsigned long V_63 ;
struct V_18 * V_18 ;
struct V_9 * V_10 ;
struct V_8 * V_99 ;
T_2 V_100 = ( T_2 ) V_8 -> V_40 . V_41 << 9 ;
T_2 V_101 ;
T_2 V_102 ;
struct V_82 * V_83 ;
int V_17 = - V_66 ;
int V_103 = 0 ;
T_4 * V_23 ;
V_57 = & F_7 ( V_14 ) -> V_58 ;
V_86 = & F_7 ( V_14 ) -> V_89 ;
F_58 ( & V_86 -> V_93 ) ;
V_83 = F_59 ( V_86 ,
F_46 ( V_8 -> V_75 -> V_50 ) ,
V_28 ) ;
F_60 ( & V_86 -> V_93 ) ;
if ( ! V_83 )
return - V_32 ;
V_46 = V_83 -> V_104 ;
V_15 = F_34 ( F_1 ( V_2 , V_46 ) , V_65 ) ;
if ( ! V_15 )
goto V_39;
F_35 ( & V_15 -> V_38 , 0 ) ;
V_15 -> V_37 = 0 ;
V_15 -> V_14 = V_14 ;
V_15 -> V_31 = V_31 ;
V_23 = & V_15 -> V_23 ;
V_15 -> V_44 = V_83 -> V_105 ;
V_101 = V_83 -> V_53 ;
V_102 = V_83 -> V_44 ;
F_62 ( V_83 ) ;
V_83 = NULL ;
V_15 -> V_53 = V_8 -> V_40 . V_71 ;
V_15 -> V_46 = V_46 ;
V_15 -> V_43 = F_67 ( V_98 ) ;
V_15 -> V_45 = V_8 ;
V_26 = F_3 ( V_46 , V_28 ) ;
V_15 -> V_27 = F_68 ( V_26 , sizeof( struct V_18 * ) ,
V_65 ) ;
if ( ! V_15 -> V_27 )
goto V_106;
V_10 = V_2 -> V_67 -> V_68 ;
for ( V_63 = 0 ; V_63 < V_26 ; V_63 ++ ) {
V_15 -> V_27 [ V_63 ] = F_69 ( V_65 |
V_107 ) ;
if ( ! V_15 -> V_27 [ V_63 ] ) {
V_103 = V_63 - 1 ;
V_17 = - V_66 ;
goto V_108;
}
}
V_103 = V_26 - 1 ;
V_15 -> V_26 = V_26 ;
F_47 ( V_14 , V_102 + V_101 , V_15 ) ;
V_15 -> V_53 = V_8 -> V_40 . V_71 ;
V_99 = F_4 ( V_10 , V_100 , V_65 ) ;
if ( ! V_99 )
goto V_108;
F_36 ( V_99 , V_109 , 0 ) ;
V_99 -> V_34 = V_15 ;
V_99 -> V_70 = F_14 ;
F_37 ( & V_15 -> V_38 ) ;
for ( V_63 = 0 ; V_63 < V_26 ; V_63 ++ ) {
V_18 = V_15 -> V_27 [ V_63 ] ;
V_18 -> V_47 = V_14 -> V_55 ;
V_18 -> V_35 = V_102 >> V_51 ;
if ( V_99 -> V_40 . V_71 )
V_17 = V_57 -> V_59 -> V_72 ( V_18 , 0 ,
V_28 ,
V_99 , 0 ) ;
else
V_17 = 0 ;
V_18 -> V_47 = NULL ;
if ( V_17 || F_38 ( V_99 , V_18 , V_28 , 0 ) <
V_28 ) {
F_39 ( V_99 ) ;
V_17 = F_40 ( V_2 , V_99 ,
V_73 ) ;
F_41 ( V_17 ) ;
F_37 ( & V_15 -> V_38 ) ;
if ( ! ( F_7 ( V_14 ) -> V_24 & V_25 ) ) {
V_17 = F_70 ( V_14 , V_99 ,
V_23 ) ;
F_41 ( V_17 ) ;
}
V_23 += F_3 ( V_99 -> V_40 . V_71 ,
V_2 -> V_7 ) ;
V_17 = F_43 ( V_2 , V_99 , V_31 , 0 ) ;
if ( V_17 ) {
V_99 -> V_36 = V_17 ;
F_21 ( V_99 ) ;
}
F_23 ( V_99 ) ;
V_99 = F_4 ( V_10 , V_100 ,
V_65 ) ;
F_41 ( ! V_99 ) ;
F_36 ( V_99 , V_109 , 0 ) ;
V_99 -> V_34 = V_15 ;
V_99 -> V_70 = F_14 ;
F_38 ( V_99 , V_18 , V_28 , 0 ) ;
}
V_100 += V_28 ;
}
F_39 ( V_99 ) ;
V_17 = F_40 ( V_2 , V_99 , V_73 ) ;
F_41 ( V_17 ) ;
if ( ! ( F_7 ( V_14 ) -> V_24 & V_25 ) ) {
V_17 = F_70 ( V_14 , V_99 , V_23 ) ;
F_41 ( V_17 ) ;
}
V_17 = F_43 ( V_2 , V_99 , V_31 , 0 ) ;
if ( V_17 ) {
V_99 -> V_36 = V_17 ;
F_21 ( V_99 ) ;
}
F_23 ( V_99 ) ;
return 0 ;
V_108:
while ( V_103 >= 0 ) {
F_71 ( V_15 -> V_27 [ V_103 ] ) ;
V_103 -- ;
}
F_22 ( V_15 -> V_27 ) ;
V_106:
F_22 ( V_15 ) ;
V_39:
F_62 ( V_83 ) ;
return V_17 ;
}
void T_7 F_72 ( void )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_110 ; V_19 ++ ) {
struct V_111 * V_112 ;
F_73 ( & V_113 [ V_19 ] . V_114 ) ;
F_74 ( & V_113 [ V_19 ] . V_115 ) ;
F_35 ( & V_113 [ V_19 ] . V_116 , 0 ) ;
F_75 ( & V_113 [ V_19 ] . V_117 ) ;
V_112 = V_118 [ V_19 ] -> F_76 () ;
if ( F_77 ( V_112 ) ) {
F_78 ( L_3 ) ;
} else {
F_35 ( & V_113 [ V_19 ] . V_116 , 1 ) ;
V_113 [ V_19 ] . V_119 = 1 ;
F_79 ( V_112 , & V_113 [ V_19 ] . V_114 ) ;
}
}
}
static struct V_111 * F_80 ( int type )
{
struct V_111 * V_112 ;
int V_120 = F_81 () ;
int V_121 = type - 1 ;
struct V_111 * V_114 = & V_113 [ V_121 ] . V_114 ;
T_8 * V_115 = & V_113 [ V_121 ] . V_115 ;
T_9 * V_116 = & V_113 [ V_121 ] . V_116 ;
T_10 * V_117 = & V_113 [ V_121 ] . V_117 ;
int * V_119 = & V_113 [ V_121 ] . V_119 ;
V_122:
F_82 ( V_115 ) ;
if ( ! F_83 ( V_114 ) ) {
V_112 = V_114 -> V_91 ;
F_84 ( V_112 ) ;
( * V_119 ) -- ;
F_85 ( V_115 ) ;
return V_112 ;
}
if ( F_86 ( V_116 ) > V_120 ) {
F_87 ( V_123 ) ;
F_85 ( V_115 ) ;
F_88 ( V_117 , & V_123 , V_124 ) ;
if ( F_86 ( V_116 ) > V_120 && ! * V_119 )
F_89 () ;
F_90 ( V_117 , & V_123 ) ;
goto V_122;
}
F_37 ( V_116 ) ;
F_85 ( V_115 ) ;
V_112 = V_118 [ V_121 ] -> F_76 () ;
if ( F_77 ( V_112 ) ) {
F_91 ( V_116 ) ;
F_92 ( V_117 ) ;
if ( F_86 ( V_116 ) == 0 ) {
static F_93 ( V_125 ,
60 * V_126 ,
1 ) ;
if ( F_94 ( & V_125 ) ) {
F_78 ( L_4 ) ;
}
}
goto V_122;
}
return V_112 ;
}
static void F_95 ( int type , struct V_111 * V_112 )
{
int V_121 = type - 1 ;
struct V_111 * V_114 = & V_113 [ V_121 ] . V_114 ;
T_8 * V_115 = & V_113 [ V_121 ] . V_115 ;
T_9 * V_116 = & V_113 [ V_121 ] . V_116 ;
T_10 * V_117 = & V_113 [ V_121 ] . V_117 ;
int * V_119 = & V_113 [ V_121 ] . V_119 ;
F_82 ( V_115 ) ;
if ( * V_119 < F_81 () ) {
F_79 ( V_112 , V_114 ) ;
( * V_119 ) ++ ;
F_85 ( V_115 ) ;
goto V_127;
}
F_85 ( V_115 ) ;
V_118 [ V_121 ] -> F_95 ( V_112 ) ;
F_91 ( V_116 ) ;
V_127:
F_96 () ;
if ( F_97 ( V_117 ) )
F_92 ( V_117 ) ;
}
static void F_98 ( void )
{
struct V_111 * V_112 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_110 ; V_19 ++ ) {
while ( ! F_83 ( & V_113 [ V_19 ] . V_114 ) ) {
V_112 = V_113 [ V_19 ] . V_114 . V_91 ;
F_84 ( V_112 ) ;
V_118 [ V_19 ] -> F_95 ( V_112 ) ;
F_91 ( & V_113 [ V_19 ] . V_116 ) ;
}
}
}
int F_99 ( int type , struct V_84 * V_47 ,
T_2 V_44 , unsigned long V_53 ,
struct V_18 * * V_54 ,
unsigned long V_128 ,
unsigned long * V_129 ,
unsigned long * V_130 ,
unsigned long * V_131 ,
unsigned long V_132 )
{
struct V_111 * V_112 ;
int V_17 ;
V_112 = F_80 ( type ) ;
V_17 = V_118 [ type - 1 ] -> F_100 ( V_112 , V_47 ,
V_44 , V_53 , V_54 ,
V_128 , V_129 ,
V_130 , V_131 ,
V_132 ) ;
F_95 ( type , V_112 ) ;
return V_17 ;
}
static int F_16 ( int type , struct V_18 * * V_133 ,
T_2 V_16 , struct V_8 * V_45 ,
T_6 V_134 )
{
struct V_111 * V_112 ;
int V_17 ;
V_112 = F_80 ( type ) ;
V_17 = V_118 [ type - 1 ] -> F_101 ( V_112 , V_133 ,
V_16 , V_45 ,
V_134 ) ;
F_95 ( type , V_112 ) ;
return V_17 ;
}
int F_102 ( int type , unsigned char * V_135 , struct V_18 * V_136 ,
unsigned long V_137 , T_6 V_134 , T_6 V_138 )
{
struct V_111 * V_112 ;
int V_17 ;
V_112 = F_80 ( type ) ;
V_17 = V_118 [ type - 1 ] -> F_103 ( V_112 , V_135 ,
V_136 , V_137 ,
V_134 , V_138 ) ;
F_95 ( type , V_112 ) ;
return V_17 ;
}
void F_104 ( void )
{
F_98 () ;
}
int F_105 ( char * V_139 , unsigned long V_140 ,
unsigned long V_131 , T_2 V_16 ,
struct V_8 * V_8 )
{
unsigned long V_141 ;
unsigned long V_142 ;
unsigned long V_137 ;
unsigned long V_143 ;
unsigned long V_144 = V_131 - V_140 ;
unsigned long V_145 ;
char * V_20 ;
struct V_48 V_49 = F_106 ( V_8 , V_8 -> V_40 ) ;
V_137 = F_46 ( V_49 . V_50 ) - V_16 ;
if ( V_131 <= V_137 )
return 1 ;
if ( V_131 > V_137 && V_140 < V_137 ) {
V_141 = V_137 - V_140 ;
V_144 -= V_141 ;
} else {
V_141 = 0 ;
}
V_142 = V_140 ;
while ( V_144 > 0 ) {
V_145 = F_27 (unsigned long, bvec.bv_len,
PAGE_SIZE - buf_offset) ;
V_145 = F_107 ( V_145 , V_144 ) ;
V_20 = F_8 ( V_49 . V_50 ) ;
memcpy ( V_20 + V_49 . V_78 , V_139 + V_141 , V_145 ) ;
F_11 ( V_20 ) ;
F_65 ( V_49 . V_50 ) ;
V_141 += V_145 ;
V_144 -= V_145 ;
V_142 += V_145 ;
F_108 ( V_8 , V_145 ) ;
if ( ! V_8 -> V_40 . V_71 )
return 0 ;
V_49 = F_106 ( V_8 , V_8 -> V_40 ) ;
V_143 = V_137 ;
V_137 = F_46 ( V_49 . V_50 ) - V_16 ;
if ( V_137 != V_143 ) {
if ( V_131 <= V_137 )
return 1 ;
if ( V_131 > V_137 &&
V_142 < V_137 ) {
V_141 = V_137 - V_140 ;
V_144 = V_131 - V_137 ;
V_142 = V_140 + V_141 ;
}
}
}
return 1 ;
}
