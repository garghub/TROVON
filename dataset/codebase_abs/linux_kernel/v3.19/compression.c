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
static T_5 void F_25 ( struct V_15 * V_15 ,
const struct V_7 * V_16 )
{
unsigned long V_35 = V_16 -> V_43 >> V_52 ;
unsigned long V_53 = ( V_16 -> V_43 + V_16 -> V_54 - 1 ) >> V_52 ;
struct V_19 * V_55 [ 16 ] ;
unsigned long V_27 = V_53 - V_35 + 1 ;
int V_20 ;
int V_18 ;
if ( V_16 -> V_36 )
F_26 ( V_15 -> V_56 , - V_31 ) ;
while ( V_27 > 0 ) {
V_18 = F_27 ( V_15 -> V_56 , V_35 ,
F_28 (unsigned long,
nr_pages, ARRAY_SIZE(pages)) , V_55 ) ;
if ( V_18 == 0 ) {
V_27 -= 1 ;
V_35 += 1 ;
continue;
}
for ( V_20 = 0 ; V_20 < V_18 ; V_20 ++ ) {
if ( V_16 -> V_36 )
F_29 ( V_55 [ V_20 ] ) ;
F_30 ( V_55 [ V_20 ] ) ;
F_18 ( V_55 [ V_20 ] ) ;
}
V_27 -= V_18 ;
V_35 += V_18 ;
}
}
static void F_31 ( struct V_9 * V_9 , int V_33 )
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
V_16 -> V_43 + V_16 -> V_54 - 1 ,
NULL ,
V_33 ? 0 : 1 ) ;
V_16 -> V_28 [ 0 ] -> V_48 = NULL ;
F_25 ( V_15 , V_16 ) ;
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
int F_32 ( struct V_15 * V_15 , T_2 V_43 ,
unsigned long V_54 , T_2 V_17 ,
unsigned long V_47 ,
struct V_19 * * V_28 ,
unsigned long V_27 )
{
struct V_9 * V_9 = NULL ;
struct V_1 * V_2 = F_8 ( V_15 ) -> V_2 ;
struct V_7 * V_16 ;
unsigned long V_62 ;
struct V_57 * V_59 = & F_8 ( V_15 ) -> V_59 ;
int V_63 = 0 ;
struct V_19 * V_19 ;
T_2 V_12 = V_17 ;
struct V_10 * V_11 ;
int V_18 ;
int V_64 = F_8 ( V_15 ) -> V_25 & V_26 ;
F_33 ( V_43 & ( ( T_2 ) V_29 - 1 ) ) ;
V_16 = F_34 ( F_1 ( V_2 , V_47 ) , V_65 ) ;
if ( ! V_16 )
return - V_66 ;
F_35 ( & V_16 -> V_37 , 0 ) ;
V_16 -> V_36 = 0 ;
V_16 -> V_15 = V_15 ;
V_16 -> V_43 = V_43 ;
V_16 -> V_54 = V_54 ;
V_16 -> V_30 = 0 ;
V_16 -> V_28 = V_28 ;
V_16 -> V_47 = V_47 ;
V_16 -> V_44 = NULL ;
V_16 -> V_27 = V_27 ;
V_11 = F_8 ( V_15 ) -> V_2 -> V_5 -> V_67 -> V_68 ;
V_9 = F_4 ( V_11 , V_12 , V_65 ) ;
if ( ! V_9 ) {
F_23 ( V_16 ) ;
return - V_66 ;
}
V_9 -> V_34 = V_16 ;
V_9 -> V_69 = F_31 ;
F_36 ( & V_16 -> V_37 ) ;
V_62 = V_47 ;
for ( V_63 = 0 ; V_63 < V_16 -> V_27 ; V_63 ++ ) {
V_19 = V_28 [ V_63 ] ;
V_19 -> V_48 = V_15 -> V_56 ;
if ( V_9 -> V_39 . V_70 )
V_18 = V_59 -> V_60 -> V_71 ( V_72 , V_19 , 0 ,
V_29 ,
V_9 , 0 ) ;
else
V_18 = 0 ;
V_19 -> V_48 = NULL ;
if ( V_18 || F_37 ( V_9 , V_19 , V_29 , 0 ) <
V_29 ) {
F_38 ( V_9 ) ;
F_36 ( & V_16 -> V_37 ) ;
V_18 = F_39 ( V_2 -> V_5 , V_9 ,
V_73 ) ;
F_40 ( V_18 ) ;
if ( ! V_64 ) {
V_18 = F_41 ( V_2 , V_15 , V_9 ,
V_43 , 1 ) ;
F_40 ( V_18 ) ;
}
V_18 = F_42 ( V_2 , V_72 , V_9 , 0 , 1 ) ;
F_40 ( V_18 ) ;
F_24 ( V_9 ) ;
V_9 = F_4 ( V_11 , V_12 , V_65 ) ;
F_40 ( ! V_9 ) ;
V_9 -> V_34 = V_16 ;
V_9 -> V_69 = F_31 ;
F_37 ( V_9 , V_19 , V_29 , 0 ) ;
}
if ( V_62 < V_29 ) {
F_13 ( F_8 ( V_15 ) -> V_2 -> V_5 ,
L_2 ,
V_62 , V_16 -> V_47 , V_16 -> V_27 ) ;
}
V_62 -= V_29 ;
V_12 += V_29 ;
F_43 () ;
}
F_38 ( V_9 ) ;
V_18 = F_39 ( V_2 -> V_5 , V_9 , V_73 ) ;
F_40 ( V_18 ) ;
if ( ! V_64 ) {
V_18 = F_41 ( V_2 , V_15 , V_9 , V_43 , 1 ) ;
F_40 ( V_18 ) ;
}
V_18 = F_42 ( V_2 , V_72 , V_9 , 0 , 1 ) ;
F_40 ( V_18 ) ;
F_24 ( V_9 ) ;
return 0 ;
}
static T_5 int F_44 ( struct V_15 * V_15 ,
T_2 V_74 ,
struct V_7 * V_16 )
{
unsigned long V_53 ;
unsigned long V_63 ;
T_2 V_75 ;
T_2 V_76 = F_45 ( V_15 ) ;
int V_18 ;
struct V_19 * V_19 ;
unsigned long V_27 = 0 ;
struct V_77 * V_78 ;
struct V_79 * V_48 = V_15 -> V_56 ;
struct V_80 * V_81 ;
struct V_57 * V_58 ;
T_2 V_82 ;
int V_83 = 0 ;
V_19 = V_16 -> V_44 -> V_45 [ V_16 -> V_44 -> V_46 - 1 ] . V_51 ;
V_75 = ( F_46 ( V_19 ) + V_29 ) ;
V_81 = & F_8 ( V_15 ) -> V_84 ;
V_58 = & F_8 ( V_15 ) -> V_59 ;
if ( V_76 == 0 )
return 0 ;
V_53 = ( F_45 ( V_15 ) - 1 ) >> V_52 ;
while ( V_75 < V_74 ) {
V_63 = V_75 >> V_52 ;
if ( V_63 > V_53 )
break;
F_47 () ;
V_19 = F_48 ( & V_48 -> V_85 , V_63 ) ;
F_49 () ;
if ( V_19 && ! F_50 ( V_19 ) ) {
V_83 ++ ;
if ( V_83 > 4 )
break;
goto V_86;
}
V_19 = F_51 ( F_52 ( V_48 ) &
~ V_87 ) ;
if ( ! V_19 )
break;
if ( F_53 ( V_19 , V_48 , V_63 ,
V_65 ) ) {
F_18 ( V_19 ) ;
goto V_86;
}
V_82 = V_75 + V_29 - 1 ;
F_54 ( V_19 ) ;
F_55 ( V_58 , V_75 , V_82 ) ;
F_56 ( & V_81 -> V_88 ) ;
V_78 = F_57 ( V_81 , V_75 ,
V_29 ) ;
F_58 ( & V_81 -> V_88 ) ;
if ( ! V_78 || V_75 < V_78 -> V_43 ||
( V_75 + V_29 > F_59 ( V_78 ) ) ||
( V_78 -> V_89 >> 9 ) != V_16 -> V_44 -> V_39 . V_40 ) {
F_60 ( V_78 ) ;
F_61 ( V_58 , V_75 , V_82 ) ;
F_62 ( V_19 ) ;
F_18 ( V_19 ) ;
break;
}
F_60 ( V_78 ) ;
if ( V_19 -> V_35 == V_53 ) {
char * V_90 ;
T_6 V_91 = V_76 & ( V_29 - 1 ) ;
if ( V_91 ) {
int V_92 ;
V_92 = V_29 - V_91 ;
V_90 = F_9 ( V_19 ) ;
memset ( V_90 + V_91 , 0 , V_92 ) ;
F_63 ( V_19 ) ;
F_12 ( V_90 ) ;
}
}
V_18 = F_37 ( V_16 -> V_44 , V_19 ,
V_29 , 0 ) ;
if ( V_18 == V_29 ) {
V_27 ++ ;
F_18 ( V_19 ) ;
} else {
F_61 ( V_58 , V_75 , V_82 ) ;
F_62 ( V_19 ) ;
F_18 ( V_19 ) ;
break;
}
V_86:
V_75 += V_29 ;
}
return 0 ;
}
int F_64 ( struct V_15 * V_15 , struct V_9 * V_9 ,
int V_30 , unsigned long V_93 )
{
struct V_57 * V_58 ;
struct V_80 * V_81 ;
struct V_7 * V_16 ;
struct V_1 * V_2 = F_8 ( V_15 ) -> V_2 ;
unsigned long V_94 = V_9 -> V_46 * V_29 ;
unsigned long V_47 ;
unsigned long V_27 ;
unsigned long V_63 ;
struct V_19 * V_19 ;
struct V_10 * V_11 ;
struct V_9 * V_95 ;
T_2 V_96 = ( T_2 ) V_9 -> V_39 . V_40 << 9 ;
T_2 V_97 ;
T_2 V_98 ;
struct V_77 * V_78 ;
int V_18 = - V_66 ;
int V_99 = 0 ;
T_4 * V_24 ;
V_58 = & F_8 ( V_15 ) -> V_59 ;
V_81 = & F_8 ( V_15 ) -> V_84 ;
F_56 ( & V_81 -> V_88 ) ;
V_78 = F_57 ( V_81 ,
F_46 ( V_9 -> V_45 -> V_51 ) ,
V_29 ) ;
F_58 ( & V_81 -> V_88 ) ;
if ( ! V_78 )
return - V_31 ;
V_47 = V_78 -> V_100 ;
V_16 = F_34 ( F_1 ( V_2 , V_47 ) , V_65 ) ;
if ( ! V_16 )
goto V_38;
F_35 ( & V_16 -> V_37 , 0 ) ;
V_16 -> V_36 = 0 ;
V_16 -> V_15 = V_15 ;
V_16 -> V_30 = V_30 ;
V_24 = & V_16 -> V_24 ;
V_16 -> V_43 = V_78 -> V_101 ;
V_97 = V_78 -> V_54 ;
V_98 = V_78 -> V_43 ;
F_60 ( V_78 ) ;
V_78 = NULL ;
V_16 -> V_54 = V_94 ;
V_16 -> V_47 = V_47 ;
V_16 -> V_42 = F_65 ( V_93 ) ;
V_16 -> V_44 = V_9 ;
V_27 = F_3 ( V_47 , V_29 ) ;
V_16 -> V_28 = F_66 ( sizeof( struct V_19 * ) * V_27 ,
V_65 ) ;
if ( ! V_16 -> V_28 )
goto V_102;
V_11 = F_8 ( V_15 ) -> V_2 -> V_5 -> V_67 -> V_68 ;
for ( V_63 = 0 ; V_63 < V_27 ; V_63 ++ ) {
V_16 -> V_28 [ V_63 ] = F_67 ( V_65 |
V_103 ) ;
if ( ! V_16 -> V_28 [ V_63 ] ) {
V_99 = V_63 - 1 ;
V_18 = - V_66 ;
goto V_104;
}
}
V_99 = V_27 - 1 ;
V_16 -> V_27 = V_27 ;
if ( ! ( V_93 & V_105 ) )
F_44 ( V_15 , V_98 + V_97 , V_16 ) ;
V_94 = V_9 -> V_46 * V_29 ;
V_16 -> V_54 = V_94 ;
V_95 = F_4 ( V_11 , V_96 , V_65 ) ;
if ( ! V_95 )
goto V_104;
V_95 -> V_34 = V_16 ;
V_95 -> V_69 = F_15 ;
F_36 ( & V_16 -> V_37 ) ;
for ( V_63 = 0 ; V_63 < V_27 ; V_63 ++ ) {
V_19 = V_16 -> V_28 [ V_63 ] ;
V_19 -> V_48 = V_15 -> V_56 ;
V_19 -> V_35 = V_98 >> V_52 ;
if ( V_95 -> V_39 . V_70 )
V_18 = V_58 -> V_60 -> V_71 ( V_106 , V_19 , 0 ,
V_29 ,
V_95 , 0 ) ;
else
V_18 = 0 ;
V_19 -> V_48 = NULL ;
if ( V_18 || F_37 ( V_95 , V_19 , V_29 , 0 ) <
V_29 ) {
F_38 ( V_95 ) ;
V_18 = F_39 ( V_2 -> V_5 , V_95 ,
V_73 ) ;
F_40 ( V_18 ) ;
F_36 ( & V_16 -> V_37 ) ;
if ( ! ( F_8 ( V_15 ) -> V_25 & V_26 ) ) {
V_18 = F_68 ( V_2 , V_15 ,
V_95 , V_24 ) ;
F_40 ( V_18 ) ;
}
V_24 += F_3 ( V_95 -> V_39 . V_70 ,
V_2 -> V_8 ) ;
V_18 = F_42 ( V_2 , V_106 , V_95 ,
V_30 , 0 ) ;
if ( V_18 )
F_22 ( V_95 , V_18 ) ;
F_24 ( V_95 ) ;
V_95 = F_4 ( V_11 , V_96 ,
V_65 ) ;
F_40 ( ! V_95 ) ;
V_95 -> V_34 = V_16 ;
V_95 -> V_69 = F_15 ;
F_37 ( V_95 , V_19 , V_29 , 0 ) ;
}
V_96 += V_29 ;
}
F_38 ( V_95 ) ;
V_18 = F_39 ( V_2 -> V_5 , V_95 ,
V_73 ) ;
F_40 ( V_18 ) ;
if ( ! ( F_8 ( V_15 ) -> V_25 & V_26 ) ) {
V_18 = F_68 ( V_2 , V_15 , V_95 , V_24 ) ;
F_40 ( V_18 ) ;
}
V_18 = F_42 ( V_2 , V_106 , V_95 , V_30 , 0 ) ;
if ( V_18 )
F_22 ( V_95 , V_18 ) ;
F_24 ( V_95 ) ;
return 0 ;
V_104:
while ( V_99 >= 0 ) {
F_69 ( V_16 -> V_28 [ V_99 ] ) ;
V_99 -- ;
}
F_23 ( V_16 -> V_28 ) ;
V_102:
F_23 ( V_16 ) ;
V_38:
F_60 ( V_78 ) ;
return V_18 ;
}
void T_7 F_70 ( void )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_107 ; V_20 ++ ) {
F_71 ( & V_108 [ V_20 ] ) ;
F_72 ( & V_109 [ V_20 ] ) ;
F_35 ( & V_110 [ V_20 ] , 0 ) ;
F_73 ( & V_111 [ V_20 ] ) ;
}
}
static struct V_112 * F_74 ( int type )
{
struct V_112 * V_113 ;
int V_114 = F_75 () ;
int V_115 = type - 1 ;
struct V_112 * V_116 = & V_108 [ V_115 ] ;
T_8 * V_117 = & V_109 [ V_115 ] ;
T_9 * V_118 = & V_110 [ V_115 ] ;
T_10 * V_119 = & V_111 [ V_115 ] ;
int * V_120 = & V_121 [ V_115 ] ;
V_122:
F_76 ( V_117 ) ;
if ( ! F_77 ( V_116 ) ) {
V_113 = V_116 -> V_86 ;
F_78 ( V_113 ) ;
( * V_120 ) -- ;
F_79 ( V_117 ) ;
return V_113 ;
}
if ( F_80 ( V_118 ) > V_114 ) {
F_81 ( V_123 ) ;
F_79 ( V_117 ) ;
F_82 ( V_119 , & V_123 , V_124 ) ;
if ( F_80 ( V_118 ) > V_114 && ! * V_120 )
F_83 () ;
F_84 ( V_119 , & V_123 ) ;
goto V_122;
}
F_36 ( V_118 ) ;
F_79 ( V_117 ) ;
V_113 = V_125 [ V_115 ] -> V_118 () ;
if ( F_85 ( V_113 ) ) {
F_86 ( V_118 ) ;
F_87 ( V_119 ) ;
}
return V_113 ;
}
static void F_88 ( int type , struct V_112 * V_113 )
{
int V_115 = type - 1 ;
struct V_112 * V_116 = & V_108 [ V_115 ] ;
T_8 * V_117 = & V_109 [ V_115 ] ;
T_9 * V_118 = & V_110 [ V_115 ] ;
T_10 * V_119 = & V_111 [ V_115 ] ;
int * V_120 = & V_121 [ V_115 ] ;
F_76 ( V_117 ) ;
if ( * V_120 < F_75 () ) {
F_89 ( V_113 , V_116 ) ;
( * V_120 ) ++ ;
F_79 ( V_117 ) ;
goto V_126;
}
F_79 ( V_117 ) ;
V_125 [ V_115 ] -> F_88 ( V_113 ) ;
F_86 ( V_118 ) ;
V_126:
F_90 () ;
if ( F_91 ( V_119 ) )
F_87 ( V_119 ) ;
}
static void F_92 ( void )
{
struct V_112 * V_113 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_107 ; V_20 ++ ) {
while ( ! F_77 ( & V_108 [ V_20 ] ) ) {
V_113 = V_108 [ V_20 ] . V_86 ;
F_78 ( V_113 ) ;
V_125 [ V_20 ] -> F_88 ( V_113 ) ;
F_86 ( & V_110 [ V_20 ] ) ;
}
}
}
int F_93 ( int type , struct V_79 * V_48 ,
T_2 V_43 , unsigned long V_54 ,
struct V_19 * * V_55 ,
unsigned long V_127 ,
unsigned long * V_128 ,
unsigned long * V_129 ,
unsigned long * V_130 ,
unsigned long V_131 )
{
struct V_112 * V_113 ;
int V_18 ;
V_113 = F_74 ( type ) ;
if ( F_85 ( V_113 ) )
return F_94 ( V_113 ) ;
V_18 = V_125 [ type - 1 ] -> F_95 ( V_113 , V_48 ,
V_43 , V_54 , V_55 ,
V_127 , V_128 ,
V_129 , V_130 ,
V_131 ) ;
F_88 ( type , V_113 ) ;
return V_18 ;
}
static int F_17 ( int type , struct V_19 * * V_132 ,
T_2 V_17 , struct V_49 * V_50 ,
int V_133 , T_6 V_134 )
{
struct V_112 * V_113 ;
int V_18 ;
V_113 = F_74 ( type ) ;
if ( F_85 ( V_113 ) )
return F_94 ( V_113 ) ;
V_18 = V_125 [ type - 1 ] -> F_96 ( V_113 , V_132 ,
V_17 ,
V_50 , V_133 , V_134 ) ;
F_88 ( type , V_113 ) ;
return V_18 ;
}
int F_97 ( int type , unsigned char * V_135 , struct V_19 * V_136 ,
unsigned long V_137 , T_6 V_134 , T_6 V_138 )
{
struct V_112 * V_113 ;
int V_18 ;
V_113 = F_74 ( type ) ;
if ( F_85 ( V_113 ) )
return F_94 ( V_113 ) ;
V_18 = V_125 [ type - 1 ] -> F_98 ( V_113 , V_135 ,
V_136 , V_137 ,
V_134 , V_138 ) ;
F_88 ( type , V_113 ) ;
return V_18 ;
}
void F_99 ( void )
{
F_92 () ;
}
int F_100 ( char * V_139 , unsigned long V_140 ,
unsigned long V_130 , T_2 V_17 ,
struct V_49 * V_50 , int V_133 ,
unsigned long * V_63 ,
unsigned long * V_141 )
{
unsigned long V_142 ;
unsigned long V_143 ;
unsigned long V_137 ;
unsigned long V_144 = V_130 - V_140 ;
unsigned long V_145 ;
char * V_21 ;
struct V_19 * V_146 = V_50 [ * V_63 ] . V_51 ;
V_137 = F_46 ( V_146 ) - V_17 ;
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
V_145 = F_101 ( V_29 - * V_141 ,
V_29 - V_142 ) ;
V_145 = F_101 ( V_145 , V_144 ) ;
V_21 = F_9 ( V_146 ) ;
memcpy ( V_21 + * V_141 , V_139 + V_142 , V_145 ) ;
F_12 ( V_21 ) ;
F_63 ( V_146 ) ;
* V_141 += V_145 ;
V_142 += V_145 ;
V_144 -= V_145 ;
V_143 += V_145 ;
if ( * V_141 == V_29 ) {
( * V_63 ) ++ ;
if ( * V_63 >= V_133 )
return 0 ;
V_146 = V_50 [ * V_63 ] . V_51 ;
* V_141 = 0 ;
V_137 = F_46 ( V_146 ) - V_17 ;
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
void F_102 ( struct V_49 * V_50 , int V_133 ,
unsigned long V_63 ,
unsigned long V_141 )
{
while ( V_63 < V_133 ) {
struct V_19 * V_19 = V_50 [ V_63 ] . V_51 ;
unsigned long V_147 = V_50 [ V_63 ] . V_148 ;
unsigned long V_54 = V_50 [ V_63 ] . V_149 ;
if ( V_141 < V_147 )
V_141 = V_147 ;
if ( V_141 < V_147 + V_54 ) {
unsigned long V_145 = V_147 + V_54 - V_141 ;
char * V_21 ;
V_21 = F_9 ( V_19 ) ;
memset ( V_21 + V_141 , 0 , V_145 ) ;
F_12 ( V_21 ) ;
}
V_63 ++ ;
V_141 = 0 ;
}
}
