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
static int F_6 ( struct V_14 * V_15 ,
struct V_6 * V_16 ,
T_2 V_17 )
{
int V_18 ;
struct V_19 * V_19 ;
unsigned long V_20 ;
char * V_21 ;
T_4 V_22 ;
T_4 * V_23 = & V_16 -> V_24 ;
if ( V_15 -> V_25 & V_26 )
return 0 ;
for ( V_20 = 0 ; V_20 < V_16 -> V_27 ; V_20 ++ ) {
V_19 = V_16 -> V_28 [ V_20 ] ;
V_22 = ~ ( T_4 ) 0 ;
V_21 = F_7 ( V_19 ) ;
V_22 = F_8 ( V_21 , V_22 , V_29 ) ;
F_9 ( V_22 , ( V_30 * ) & V_22 ) ;
F_10 ( V_21 ) ;
if ( V_22 != * V_23 ) {
F_11 ( V_15 , V_17 , V_22 ,
* V_23 , V_16 -> V_31 ) ;
V_18 = - V_32 ;
goto V_33;
}
V_23 ++ ;
}
V_18 = 0 ;
V_33:
return V_18 ;
}
static void F_12 ( struct V_8 * V_8 )
{
struct V_6 * V_16 = V_8 -> V_34 ;
struct V_15 * V_15 ;
struct V_19 * V_19 ;
unsigned long V_35 ;
int V_18 ;
if ( V_8 -> V_36 )
V_16 -> V_37 = 1 ;
if ( ! F_13 ( & V_16 -> V_38 ) )
goto V_39;
V_15 = V_16 -> V_15 ;
V_18 = F_6 ( F_14 ( V_15 ) , V_16 ,
( T_2 ) V_8 -> V_40 . V_41 << 9 ) ;
if ( V_18 )
goto V_42;
V_18 = F_15 ( V_16 -> V_43 ,
V_16 -> V_28 ,
V_16 -> V_44 ,
V_16 -> V_45 ,
V_16 -> V_46 ) ;
V_42:
if ( V_18 )
V_16 -> V_37 = 1 ;
V_35 = 0 ;
for ( V_35 = 0 ; V_35 < V_16 -> V_27 ; V_35 ++ ) {
V_19 = V_16 -> V_28 [ V_35 ] ;
V_19 -> V_47 = NULL ;
F_16 ( V_19 ) ;
}
if ( V_16 -> V_37 ) {
F_17 ( V_16 -> V_45 ) ;
} else {
int V_20 ;
struct V_48 * V_49 ;
F_18 (bvec, cb->orig_bio, i)
F_19 ( V_49 -> V_50 ) ;
F_20 ( V_16 -> V_45 ) ;
}
F_21 ( V_16 -> V_28 ) ;
F_21 ( V_16 ) ;
V_39:
F_22 ( V_8 ) ;
}
static T_5 void F_23 ( struct V_15 * V_15 ,
const struct V_6 * V_16 )
{
unsigned long V_35 = V_16 -> V_44 >> V_51 ;
unsigned long V_52 = ( V_16 -> V_44 + V_16 -> V_53 - 1 ) >> V_51 ;
struct V_19 * V_54 [ 16 ] ;
unsigned long V_27 = V_52 - V_35 + 1 ;
int V_20 ;
int V_18 ;
if ( V_16 -> V_37 )
F_24 ( V_15 -> V_55 , - V_32 ) ;
while ( V_27 > 0 ) {
V_18 = F_25 ( V_15 -> V_55 , V_35 ,
F_26 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_54 ) ;
if ( V_18 == 0 ) {
V_27 -= 1 ;
V_35 += 1 ;
continue;
}
for ( V_20 = 0 ; V_20 < V_18 ; V_20 ++ ) {
if ( V_16 -> V_37 )
F_27 ( V_54 [ V_20 ] ) ;
F_28 ( V_54 [ V_20 ] ) ;
F_16 ( V_54 [ V_20 ] ) ;
}
V_27 -= V_18 ;
V_35 += V_18 ;
}
}
static void F_29 ( struct V_8 * V_8 )
{
struct V_56 * V_57 ;
struct V_6 * V_16 = V_8 -> V_34 ;
struct V_15 * V_15 ;
struct V_19 * V_19 ;
unsigned long V_35 ;
if ( V_8 -> V_36 )
V_16 -> V_37 = 1 ;
if ( ! F_13 ( & V_16 -> V_38 ) )
goto V_39;
V_15 = V_16 -> V_15 ;
V_57 = & F_14 ( V_15 ) -> V_58 ;
V_16 -> V_28 [ 0 ] -> V_47 = V_16 -> V_15 -> V_55 ;
V_57 -> V_59 -> V_60 ( V_16 -> V_28 [ 0 ] ,
V_16 -> V_44 ,
V_16 -> V_44 + V_16 -> V_53 - 1 ,
NULL ,
V_8 -> V_36 ? 0 : 1 ) ;
V_16 -> V_28 [ 0 ] -> V_47 = NULL ;
F_23 ( V_15 , V_16 ) ;
V_35 = 0 ;
for ( V_35 = 0 ; V_35 < V_16 -> V_27 ; V_35 ++ ) {
V_19 = V_16 -> V_28 [ V_35 ] ;
V_19 -> V_47 = NULL ;
F_16 ( V_19 ) ;
}
F_21 ( V_16 -> V_28 ) ;
F_21 ( V_16 ) ;
V_39:
F_22 ( V_8 ) ;
}
int F_30 ( struct V_15 * V_15 , T_2 V_44 ,
unsigned long V_53 , T_2 V_17 ,
unsigned long V_46 ,
struct V_19 * * V_28 ,
unsigned long V_27 )
{
struct V_1 * V_2 = F_31 ( V_15 -> V_61 ) ;
struct V_8 * V_8 = NULL ;
struct V_6 * V_16 ;
unsigned long V_62 ;
struct V_56 * V_58 = & F_14 ( V_15 ) -> V_58 ;
int V_63 = 0 ;
struct V_19 * V_19 ;
T_2 V_11 = V_17 ;
struct V_9 * V_10 ;
int V_18 ;
int V_64 = F_14 ( V_15 ) -> V_25 & V_26 ;
F_32 ( V_44 & ( ( T_2 ) V_29 - 1 ) ) ;
V_16 = F_33 ( F_1 ( V_2 , V_46 ) , V_65 ) ;
if ( ! V_16 )
return - V_66 ;
F_34 ( & V_16 -> V_38 , 0 ) ;
V_16 -> V_37 = 0 ;
V_16 -> V_15 = V_15 ;
V_16 -> V_44 = V_44 ;
V_16 -> V_53 = V_53 ;
V_16 -> V_31 = 0 ;
V_16 -> V_28 = V_28 ;
V_16 -> V_46 = V_46 ;
V_16 -> V_45 = NULL ;
V_16 -> V_27 = V_27 ;
V_10 = V_2 -> V_67 -> V_68 ;
V_8 = F_4 ( V_10 , V_11 , V_65 ) ;
if ( ! V_8 ) {
F_21 ( V_16 ) ;
return - V_66 ;
}
F_35 ( V_8 , V_69 , 0 ) ;
V_8 -> V_34 = V_16 ;
V_8 -> V_70 = F_29 ;
F_36 ( & V_16 -> V_38 ) ;
V_62 = V_46 ;
for ( V_63 = 0 ; V_63 < V_16 -> V_27 ; V_63 ++ ) {
V_19 = V_28 [ V_63 ] ;
V_19 -> V_47 = V_15 -> V_55 ;
if ( V_8 -> V_40 . V_71 )
V_18 = V_58 -> V_59 -> V_72 ( V_19 , 0 ,
V_29 ,
V_8 , 0 ) ;
else
V_18 = 0 ;
V_19 -> V_47 = NULL ;
if ( V_18 || F_37 ( V_8 , V_19 , V_29 , 0 ) <
V_29 ) {
F_38 ( V_8 ) ;
F_36 ( & V_16 -> V_38 ) ;
V_18 = F_39 ( V_2 , V_8 ,
V_73 ) ;
F_40 ( V_18 ) ;
if ( ! V_64 ) {
V_18 = F_41 ( V_15 , V_8 , V_44 , 1 ) ;
F_40 ( V_18 ) ;
}
V_18 = F_42 ( V_2 , V_8 , 0 , 1 ) ;
if ( V_18 ) {
V_8 -> V_36 = V_18 ;
F_20 ( V_8 ) ;
}
F_22 ( V_8 ) ;
V_8 = F_4 ( V_10 , V_11 , V_65 ) ;
F_40 ( ! V_8 ) ;
F_35 ( V_8 , V_69 , 0 ) ;
V_8 -> V_34 = V_16 ;
V_8 -> V_70 = F_29 ;
F_37 ( V_8 , V_19 , V_29 , 0 ) ;
}
if ( V_62 < V_29 ) {
F_43 ( V_2 ,
L_1 ,
V_62 , V_16 -> V_46 , V_16 -> V_27 ) ;
}
V_62 -= V_29 ;
V_11 += V_29 ;
F_44 () ;
}
F_38 ( V_8 ) ;
V_18 = F_39 ( V_2 , V_8 , V_73 ) ;
F_40 ( V_18 ) ;
if ( ! V_64 ) {
V_18 = F_41 ( V_15 , V_8 , V_44 , 1 ) ;
F_40 ( V_18 ) ;
}
V_18 = F_42 ( V_2 , V_8 , 0 , 1 ) ;
if ( V_18 ) {
V_8 -> V_36 = V_18 ;
F_20 ( V_8 ) ;
}
F_22 ( V_8 ) ;
return 0 ;
}
static T_2 F_45 ( struct V_8 * V_8 )
{
struct V_48 * V_74 = & V_8 -> V_75 [ V_8 -> V_76 - 1 ] ;
return F_46 ( V_74 -> V_50 ) + V_74 -> V_77 + V_74 -> V_78 ;
}
static T_5 int F_47 ( struct V_15 * V_15 ,
T_2 V_79 ,
struct V_6 * V_16 )
{
unsigned long V_52 ;
unsigned long V_63 ;
T_2 V_80 ;
T_2 V_81 = F_48 ( V_15 ) ;
int V_18 ;
struct V_19 * V_19 ;
unsigned long V_27 = 0 ;
struct V_82 * V_83 ;
struct V_84 * V_47 = V_15 -> V_55 ;
struct V_85 * V_86 ;
struct V_56 * V_57 ;
T_2 V_87 ;
int V_88 = 0 ;
V_80 = F_45 ( V_16 -> V_45 ) ;
V_86 = & F_14 ( V_15 ) -> V_89 ;
V_57 = & F_14 ( V_15 ) -> V_58 ;
if ( V_81 == 0 )
return 0 ;
V_52 = ( F_48 ( V_15 ) - 1 ) >> V_51 ;
while ( V_80 < V_79 ) {
V_63 = V_80 >> V_51 ;
if ( V_63 > V_52 )
break;
F_49 () ;
V_19 = F_50 ( & V_47 -> V_90 , V_63 ) ;
F_51 () ;
if ( V_19 && ! F_52 ( V_19 ) ) {
V_88 ++ ;
if ( V_88 > 4 )
break;
goto V_91;
}
V_19 = F_53 ( F_54 ( V_47 ,
~ V_92 ) ) ;
if ( ! V_19 )
break;
if ( F_55 ( V_19 , V_47 , V_63 , V_65 ) ) {
F_16 ( V_19 ) ;
goto V_91;
}
V_87 = V_80 + V_29 - 1 ;
F_56 ( V_19 ) ;
F_57 ( V_57 , V_80 , V_87 ) ;
F_58 ( & V_86 -> V_93 ) ;
V_83 = F_59 ( V_86 , V_80 ,
V_29 ) ;
F_60 ( & V_86 -> V_93 ) ;
if ( ! V_83 || V_80 < V_83 -> V_44 ||
( V_80 + V_29 > F_61 ( V_83 ) ) ||
( V_83 -> V_94 >> 9 ) != V_16 -> V_45 -> V_40 . V_41 ) {
F_62 ( V_83 ) ;
F_63 ( V_57 , V_80 , V_87 ) ;
F_64 ( V_19 ) ;
F_16 ( V_19 ) ;
break;
}
F_62 ( V_83 ) ;
if ( V_19 -> V_35 == V_52 ) {
char * V_95 ;
T_6 V_96 = V_81 & ( V_29 - 1 ) ;
if ( V_96 ) {
int V_97 ;
V_97 = V_29 - V_96 ;
V_95 = F_7 ( V_19 ) ;
memset ( V_95 + V_96 , 0 , V_97 ) ;
F_65 ( V_19 ) ;
F_10 ( V_95 ) ;
}
}
V_18 = F_37 ( V_16 -> V_45 , V_19 ,
V_29 , 0 ) ;
if ( V_18 == V_29 ) {
V_27 ++ ;
F_16 ( V_19 ) ;
} else {
F_63 ( V_57 , V_80 , V_87 ) ;
F_64 ( V_19 ) ;
F_16 ( V_19 ) ;
break;
}
V_91:
V_80 += V_29 ;
}
return 0 ;
}
int F_66 ( struct V_15 * V_15 , struct V_8 * V_8 ,
int V_31 , unsigned long V_98 )
{
struct V_1 * V_2 = F_31 ( V_15 -> V_61 ) ;
struct V_56 * V_57 ;
struct V_85 * V_86 ;
struct V_6 * V_16 ;
unsigned long V_46 ;
unsigned long V_27 ;
unsigned long V_63 ;
struct V_19 * V_19 ;
struct V_9 * V_10 ;
struct V_8 * V_99 ;
T_2 V_100 = ( T_2 ) V_8 -> V_40 . V_41 << 9 ;
T_2 V_101 ;
T_2 V_102 ;
struct V_82 * V_83 ;
int V_18 = - V_66 ;
int V_103 = 0 ;
T_4 * V_24 ;
V_57 = & F_14 ( V_15 ) -> V_58 ;
V_86 = & F_14 ( V_15 ) -> V_89 ;
F_58 ( & V_86 -> V_93 ) ;
V_83 = F_59 ( V_86 ,
F_46 ( V_8 -> V_75 -> V_50 ) ,
V_29 ) ;
F_60 ( & V_86 -> V_93 ) ;
if ( ! V_83 )
return - V_32 ;
V_46 = V_83 -> V_104 ;
V_16 = F_33 ( F_1 ( V_2 , V_46 ) , V_65 ) ;
if ( ! V_16 )
goto V_39;
F_34 ( & V_16 -> V_38 , 0 ) ;
V_16 -> V_37 = 0 ;
V_16 -> V_15 = V_15 ;
V_16 -> V_31 = V_31 ;
V_24 = & V_16 -> V_24 ;
V_16 -> V_44 = V_83 -> V_105 ;
V_101 = V_83 -> V_53 ;
V_102 = V_83 -> V_44 ;
F_62 ( V_83 ) ;
V_83 = NULL ;
V_16 -> V_53 = V_8 -> V_40 . V_71 ;
V_16 -> V_46 = V_46 ;
V_16 -> V_43 = F_67 ( V_98 ) ;
V_16 -> V_45 = V_8 ;
V_27 = F_3 ( V_46 , V_29 ) ;
V_16 -> V_28 = F_68 ( V_27 , sizeof( struct V_19 * ) ,
V_65 ) ;
if ( ! V_16 -> V_28 )
goto V_106;
V_10 = V_2 -> V_67 -> V_68 ;
for ( V_63 = 0 ; V_63 < V_27 ; V_63 ++ ) {
V_16 -> V_28 [ V_63 ] = F_69 ( V_65 |
V_107 ) ;
if ( ! V_16 -> V_28 [ V_63 ] ) {
V_103 = V_63 - 1 ;
V_18 = - V_66 ;
goto V_108;
}
}
V_103 = V_27 - 1 ;
V_16 -> V_27 = V_27 ;
F_47 ( V_15 , V_102 + V_101 , V_16 ) ;
V_16 -> V_53 = V_8 -> V_40 . V_71 ;
V_99 = F_4 ( V_10 , V_100 , V_65 ) ;
if ( ! V_99 )
goto V_108;
F_35 ( V_99 , V_109 , 0 ) ;
V_99 -> V_34 = V_16 ;
V_99 -> V_70 = F_12 ;
F_36 ( & V_16 -> V_38 ) ;
for ( V_63 = 0 ; V_63 < V_27 ; V_63 ++ ) {
V_19 = V_16 -> V_28 [ V_63 ] ;
V_19 -> V_47 = V_15 -> V_55 ;
V_19 -> V_35 = V_102 >> V_51 ;
if ( V_99 -> V_40 . V_71 )
V_18 = V_57 -> V_59 -> V_72 ( V_19 , 0 ,
V_29 ,
V_99 , 0 ) ;
else
V_18 = 0 ;
V_19 -> V_47 = NULL ;
if ( V_18 || F_37 ( V_99 , V_19 , V_29 , 0 ) <
V_29 ) {
F_38 ( V_99 ) ;
V_18 = F_39 ( V_2 , V_99 ,
V_73 ) ;
F_40 ( V_18 ) ;
F_36 ( & V_16 -> V_38 ) ;
if ( ! ( F_14 ( V_15 ) -> V_25 & V_26 ) ) {
V_18 = F_70 ( V_15 , V_99 ,
V_24 ) ;
F_40 ( V_18 ) ;
}
V_24 += F_3 ( V_99 -> V_40 . V_71 ,
V_2 -> V_7 ) ;
V_18 = F_42 ( V_2 , V_99 , V_31 , 0 ) ;
if ( V_18 ) {
V_99 -> V_36 = V_18 ;
F_20 ( V_99 ) ;
}
F_22 ( V_99 ) ;
V_99 = F_4 ( V_10 , V_100 ,
V_65 ) ;
F_40 ( ! V_99 ) ;
F_35 ( V_99 , V_109 , 0 ) ;
V_99 -> V_34 = V_16 ;
V_99 -> V_70 = F_12 ;
F_37 ( V_99 , V_19 , V_29 , 0 ) ;
}
V_100 += V_29 ;
}
F_38 ( V_99 ) ;
V_18 = F_39 ( V_2 , V_99 , V_73 ) ;
F_40 ( V_18 ) ;
if ( ! ( F_14 ( V_15 ) -> V_25 & V_26 ) ) {
V_18 = F_70 ( V_15 , V_99 , V_24 ) ;
F_40 ( V_18 ) ;
}
V_18 = F_42 ( V_2 , V_99 , V_31 , 0 ) ;
if ( V_18 ) {
V_99 -> V_36 = V_18 ;
F_20 ( V_99 ) ;
}
F_22 ( V_99 ) ;
return 0 ;
V_108:
while ( V_103 >= 0 ) {
F_71 ( V_16 -> V_28 [ V_103 ] ) ;
V_103 -- ;
}
F_21 ( V_16 -> V_28 ) ;
V_106:
F_21 ( V_16 ) ;
V_39:
F_62 ( V_83 ) ;
return V_18 ;
}
void T_7 F_72 ( void )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_110 ; V_20 ++ ) {
struct V_111 * V_112 ;
F_73 ( & V_113 [ V_20 ] . V_114 ) ;
F_74 ( & V_113 [ V_20 ] . V_115 ) ;
F_34 ( & V_113 [ V_20 ] . V_116 , 0 ) ;
F_75 ( & V_113 [ V_20 ] . V_117 ) ;
V_112 = V_118 [ V_20 ] -> F_76 () ;
if ( F_77 ( V_112 ) ) {
F_78 ( L_2 ) ;
} else {
F_34 ( & V_113 [ V_20 ] . V_116 , 1 ) ;
V_113 [ V_20 ] . V_119 = 1 ;
F_79 ( V_112 , & V_113 [ V_20 ] . V_114 ) ;
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
F_36 ( V_116 ) ;
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
F_78 ( L_3 ) ;
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
int V_20 ;
for ( V_20 = 0 ; V_20 < V_110 ; V_20 ++ ) {
while ( ! F_83 ( & V_113 [ V_20 ] . V_114 ) ) {
V_112 = V_113 [ V_20 ] . V_114 . V_91 ;
F_84 ( V_112 ) ;
V_118 [ V_20 ] -> F_95 ( V_112 ) ;
F_91 ( & V_113 [ V_20 ] . V_116 ) ;
}
}
}
int F_99 ( int type , struct V_84 * V_47 ,
T_2 V_44 , struct V_19 * * V_54 ,
unsigned long * V_128 ,
unsigned long * V_129 ,
unsigned long * V_130 )
{
struct V_111 * V_112 ;
int V_18 ;
V_112 = F_80 ( type ) ;
V_18 = V_118 [ type - 1 ] -> F_100 ( V_112 , V_47 ,
V_44 , V_54 ,
V_128 ,
V_129 , V_130 ) ;
F_95 ( type , V_112 ) ;
return V_18 ;
}
static int F_15 ( int type , struct V_19 * * V_131 ,
T_2 V_17 , struct V_8 * V_45 ,
T_6 V_132 )
{
struct V_111 * V_112 ;
int V_18 ;
V_112 = F_80 ( type ) ;
V_18 = V_118 [ type - 1 ] -> F_101 ( V_112 , V_131 ,
V_17 , V_45 ,
V_132 ) ;
F_95 ( type , V_112 ) ;
return V_18 ;
}
int F_102 ( int type , unsigned char * V_133 , struct V_19 * V_134 ,
unsigned long V_135 , T_6 V_132 , T_6 V_136 )
{
struct V_111 * V_112 ;
int V_18 ;
V_112 = F_80 ( type ) ;
V_18 = V_118 [ type - 1 ] -> F_103 ( V_112 , V_133 ,
V_134 , V_135 ,
V_132 , V_136 ) ;
F_95 ( type , V_112 ) ;
return V_18 ;
}
void F_104 ( void )
{
F_98 () ;
}
int F_105 ( const char * V_137 , unsigned long V_138 ,
unsigned long V_130 , T_2 V_17 ,
struct V_8 * V_8 )
{
unsigned long V_139 ;
unsigned long V_140 ;
unsigned long V_135 ;
unsigned long V_141 ;
unsigned long V_142 = V_130 - V_138 ;
unsigned long V_143 ;
char * V_21 ;
struct V_48 V_49 = F_106 ( V_8 , V_8 -> V_40 ) ;
V_135 = F_46 ( V_49 . V_50 ) - V_17 ;
if ( V_130 <= V_135 )
return 1 ;
if ( V_130 > V_135 && V_138 < V_135 ) {
V_139 = V_135 - V_138 ;
V_142 -= V_139 ;
} else {
V_139 = 0 ;
}
V_140 = V_138 ;
while ( V_142 > 0 ) {
V_143 = F_26 (unsigned long, bvec.bv_len,
PAGE_SIZE - buf_offset) ;
V_143 = F_107 ( V_143 , V_142 ) ;
V_21 = F_7 ( V_49 . V_50 ) ;
memcpy ( V_21 + V_49 . V_78 , V_137 + V_139 , V_143 ) ;
F_10 ( V_21 ) ;
F_65 ( V_49 . V_50 ) ;
V_139 += V_143 ;
V_142 -= V_143 ;
V_140 += V_143 ;
F_108 ( V_8 , V_143 ) ;
if ( ! V_8 -> V_40 . V_71 )
return 0 ;
V_49 = F_106 ( V_8 , V_8 -> V_40 ) ;
V_141 = V_135 ;
V_135 = F_46 ( V_49 . V_50 ) - V_17 ;
if ( V_135 != V_141 ) {
if ( V_130 <= V_135 )
return 1 ;
if ( V_130 > V_135 &&
V_140 < V_135 ) {
V_139 = V_135 - V_138 ;
V_142 = V_130 - V_135 ;
V_140 = V_138 + V_139 ;
}
}
}
return 1 ;
}
