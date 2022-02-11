static int F_1 ( void )
{
int V_1 = 0 ;
if ( V_2 -> V_3 != V_4 ) {
F_2 ( L_1 ) ;
return - V_5 ;
}
if ( V_2 -> V_6 == V_7 ) {
F_3 ( L_2 ) ;
V_1 = F_4 ( V_2 -> V_8 ) ;
if ( V_1 ) {
F_3 ( L_3 , V_1 ) ;
return V_1 ;
}
}
if ( V_2 -> V_6 == V_9 ) {
V_1 = F_5 () ;
if ( V_1 )
return - V_10 ;
if ( V_2 -> V_11 == V_12 ) {
V_1 = V_2 -> V_13 ;
if ( V_1 != V_14
&& V_2 -> V_15 != V_16 )
F_6 ( V_1 ) ;
}
}
return 0 ;
}
int F_7 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
unsigned int V_1 ;
F_8 ( & V_2 -> V_21 ) ;
F_9 ( & V_2 -> V_8 -> V_22 ) ;
V_1 = F_1 () ;
if ( V_1 ) {
F_10 ( & V_2 -> V_8 -> V_22 ) ;
F_11 ( & V_2 -> V_21 ) ;
return V_1 ;
}
if ( V_2 -> V_23 < V_24 ) {
struct V_25 * V_26 =
F_12 ( sizeof( struct V_25 ) , V_27 ) ;
if ( ! V_26 ) {
F_10 ( & V_2 -> V_8 -> V_22 ) ;
F_11 ( & V_2 -> V_21 ) ;
return - V_28 ;
}
V_2 -> V_23 ++ ;
F_11 ( & V_2 -> V_21 ) ;
V_26 -> V_29 = F_13 ( V_2 ) ;
V_26 -> V_30 = 0 ;
V_20 -> V_31 = ( void * ) V_26 ;
F_3 ( L_4 , V_26 -> V_29 ) ;
} else {
V_1 = - V_32 ;
F_10 ( & V_2 -> V_8 -> V_22 ) ;
F_11 ( & V_2 -> V_21 ) ;
}
return V_1 ;
}
int F_14 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
unsigned int V_1 ;
F_8 ( & V_2 -> V_21 ) ;
F_9 ( & V_2 -> V_8 -> V_22 ) ;
V_1 = F_1 () ;
if ( V_1 ) {
F_10 ( & V_2 -> V_8 -> V_22 ) ;
F_11 ( & V_2 -> V_21 ) ;
return V_1 ;
}
if ( V_2 -> V_33 < V_34 ) {
V_2 -> V_33 ++ ;
F_3 ( L_5 ) ;
V_20 -> V_31 = NULL ;
} else {
V_1 = - V_35 ;
F_10 ( & V_2 -> V_8 -> V_22 ) ;
}
F_11 ( & V_2 -> V_21 ) ;
return V_1 ;
}
int F_15 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
struct V_25 * V_26 = V_20 -> V_31 ;
F_3 ( L_6 ) ;
F_8 ( & V_2 -> V_21 ) ;
V_2 -> V_23 -- ;
V_2 -> V_36 -- ;
F_10 ( & V_2 -> V_8 -> V_22 ) ;
F_11 ( & V_2 -> V_21 ) ;
F_16 ( V_26 -> V_30 ) ;
F_17 ( V_26 ) ;
return 0 ;
}
int F_18 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
F_8 ( & V_2 -> V_21 ) ;
V_2 -> V_33 -- ;
F_10 ( & V_2 -> V_8 -> V_22 ) ;
F_11 ( & V_2 -> V_21 ) ;
F_3 ( L_7 ) ;
return 0 ;
}
int F_19 ( struct V_19 * V_20 , struct V_37 * V_38 )
{
int V_1 , V_39 ;
struct V_25 * V_26 =
(struct V_25 * ) V_20 -> V_31 ;
int V_30 = V_26 -> V_30 ;
void * V_40 ;
V_1 = F_20 ( V_30 ) ;
if ( V_1 )
return - V_41 ;
V_39 = V_38 -> V_42 - V_38 -> V_43 ;
F_3 ( L_8 , V_30 , V_39 ) ;
if ( V_39 > V_2 -> V_44 )
return - V_28 ;
if ( ! V_2 -> V_45 )
return - V_5 ;
V_40 = ( void * ) F_21 ( ( unsigned int ) V_2 -> V_45 ) ;
V_1 = F_22 ( V_38 ,
V_38 -> V_43 ,
F_23 ( ( void * ) V_40 ) >> V_46 ,
V_39 ,
V_38 -> V_47 ) ;
if ( V_1 )
V_2 -> V_48 [ V_30 ] . V_49 = false ;
else
V_2 -> V_48 [ V_30 ] . V_49 = true ;
F_3 ( L_9 , V_1 ) ;
return V_1 ;
}
static int F_24 ( T_1 V_30 ,
struct V_50 * V_51 )
{
struct V_52 * V_53 ;
int V_1 , V_54 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
struct V_57 * V_59 ;
F_3 ( L_10 , V_30 ) ;
V_1 = F_20 ( V_30 ) ;
if ( V_1 )
return - V_41 ;
V_56 = & V_2 -> V_48 [ V_30 ] ;
if ( V_56 -> V_49 != true )
return - V_5 ;
if ( V_56 -> V_60 == V_61 ||
V_56 -> V_60 == V_62 ) {
return - V_63 ;
}
V_56 -> V_64 = 0 ;
V_56 -> V_65 = 0 ;
V_59 = F_25 ( V_51 -> V_66 , sizeof( * V_59 ) , V_27 ) ;
if ( ! V_59 )
return - V_28 ;
if ( F_26 ( V_59 , ( void V_67 * ) V_51 -> V_68 ,
V_51 -> V_66 * sizeof( * V_59 ) ) ) {
V_1 = - V_69 ;
goto V_70;
}
F_3 ( L_11 ,
V_51 -> V_66 , V_56 -> V_60 ) ;
V_58 = V_59 ;
for ( V_54 = 0 ; V_54 < V_51 -> V_66 ; V_54 ++ ) {
V_53 = F_12 ( sizeof( * V_53 ) , V_27 ) ;
if ( ! V_53 ) {
V_1 = - V_28 ;
goto V_70;
}
V_53 -> V_71 = V_58 -> V_71 ;
V_53 -> V_72 = V_58 -> V_72 ;
V_53 -> V_73 = V_2 -> V_45 ;
V_53 -> V_74 = false ;
V_58 ++ ;
F_8 ( & V_56 -> V_75 ) ;
F_27 ( & V_53 -> V_76 , & V_56 -> V_53 ) ;
F_11 ( & V_56 -> V_75 ) ;
}
F_8 ( & V_56 -> V_75 ) ;
V_56 -> V_77 . V_78 = false ;
V_56 -> V_77 . V_79 = 0 ;
if ( V_56 -> V_60 == V_80 &&
V_56 -> V_81 != V_61 &&
V_56 -> V_82 != true ) {
V_56 -> V_81 = V_56 -> V_60 ;
V_56 -> V_60 = V_83 ;
if ( V_56 -> V_84 == V_85 ) {
if ( F_28 ( V_30 ) < 0 ) {
F_2 ( L_12 ) ;
F_11 ( & V_56 -> V_75 ) ;
V_1 = - V_5 ;
goto V_70;
}
} else if ( V_56 -> V_84 == V_86 ) {
if ( F_29 ( V_30 ) < 0 ) {
F_2 ( L_13 ) ;
F_11 ( & V_56 -> V_75 ) ;
V_1 = - V_5 ;
goto V_70;
}
}
}
F_11 ( & V_56 -> V_75 ) ;
if ( ! F_30 ( & V_56 -> V_53 ) ) {
V_56 -> V_77 . V_87 = true ;
V_1 = F_31 ( V_2 ,
& V_56 -> V_77 ) ;
}
if ( V_1 >= 0 )
V_1 = V_56 -> V_65 ;
F_3 ( L_14 , V_1 ) ;
V_70:
F_17 ( V_59 ) ;
return V_1 ;
}
static int F_32 ( struct V_55 * V_56 , int V_30 )
{
int V_1 ;
V_56 -> V_77 . V_79 = 0 ;
V_56 -> V_77 . V_87 = true ;
V_56 -> V_77 . V_78 = false ;
F_8 ( & V_56 -> V_75 ) ;
if ( V_56 -> V_60 == V_80 && V_56 -> V_81 != V_61 ) {
V_56 -> V_81 = V_56 -> V_60 ;
V_56 -> V_60 = V_83 ;
}
if ( V_56 -> V_60 == V_80 && V_56 -> V_81 == V_61 ) {
F_3 ( L_15 ,
V_56 -> V_60 , V_56 -> V_81 ) ;
} else if ( ( V_56 -> V_60 == V_83 ||
V_56 -> V_60 == V_88 ) &&
V_56 -> V_82 != true ) {
if ( V_56 -> V_84 == V_85 ||
V_56 -> V_84 == V_89 ) {
if ( F_28 ( V_30 ) < 0 ) {
F_2 ( L_16 ) ;
F_11 ( & V_56 -> V_75 ) ;
return - V_5 ;
}
} else if ( V_56 -> V_84 == V_86 ) {
if ( F_29 ( V_30 ) < 0 ) {
F_2 ( L_17 ) ;
F_11 ( & V_56 -> V_75 ) ;
return - V_5 ;
}
}
} else {
F_11 ( & V_56 -> V_75 ) ;
return - V_5 ;
}
F_11 ( & V_56 -> V_75 ) ;
V_1 = F_31 ( V_2 , & V_56 -> V_77 ) ;
if ( V_1 ) {
V_56 -> V_60 = V_80 ;
F_3 ( L_18 ) ;
}
return V_1 ;
}
static int F_33 ( struct V_55 * V_56 ,
const struct V_90 * V_90 , unsigned long V_91 ,
struct V_92 * V_93 )
{
struct V_52 * V_94 ;
unsigned long V_95 , V_44 ;
unsigned char V_67 * V_96 ;
unsigned long V_71 , V_97 ;
int V_1 = 0 , V_98 = 0 ;
static int V_99 ;
static unsigned long V_100 ;
#ifdef F_34
if ( V_56 -> V_84 == V_89 ) {
for ( V_95 = V_56 -> V_101 ; V_95 < V_91 ; V_95 ++ ) {
T_2 V_102 ;
struct V_52 * V_94 =
F_12 ( sizeof( * V_94 ) , V_27 ) ;
V_56 -> V_101 = V_95 ;
if ( ! V_94 )
return - V_28 ;
if ( F_26 ( ( void * ) & V_102 ,
V_90 [ V_95 ] . V_103 ,
sizeof( T_2 ) ) )
return - V_69 ;
V_94 -> V_73 = ( char * ) V_102 ;
V_94 -> V_74 = false ;
V_94 -> V_71 = V_90 [ 0 ] . V_104 ;
F_8 ( & V_56 -> V_75 ) ;
F_27 ( & V_94 -> V_76 , & V_56 -> V_53 ) ;
F_11 ( & V_56 -> V_75 ) ;
}
V_56 -> V_101 = V_95 ;
return V_1 ;
}
#endif
V_94 = F_12 ( sizeof( * V_94 ) , V_27 ) ;
if ( ! V_94 )
return - V_28 ;
V_94 -> V_73 = V_2 -> V_45 ;
V_44 = V_2 -> V_44 ;
V_94 -> V_73 = V_2 -> V_45 ;
V_96 = V_56 -> V_105 ;
V_97 = 0 ;
if ( ! V_56 -> V_101 )
V_100 = V_99 = 0 ;
for ( V_95 = V_56 -> V_101 ; V_95 < V_91 ; V_95 ++ ) {
V_56 -> V_101 = V_95 ;
if ( ! V_56 -> V_105 )
V_96 = V_90 [ V_95 ] . V_103 ;
V_71 = ( ( unsigned long ) V_90 [ V_95 ] . V_103
+ V_90 [ V_95 ] . V_104 ) - ( unsigned long ) V_96 ;
if ( ( V_97 + V_71 ) > V_44 )
V_71 = V_44 - V_97 ;
if ( V_56 -> V_84 == V_85 ) {
if ( F_26 ( ( void * )
( V_94 -> V_73 + V_97 ) ,
V_96 , V_71 ) ) {
V_1 = - V_69 ;
break;
}
} else if ( V_56 -> V_84 == V_86 ) {
struct V_106 * V_107 =
F_12 ( sizeof( * V_107 ) , V_27 ) ;
if ( ! V_107 ) {
F_17 ( V_94 ) ;
return - V_28 ;
}
V_107 -> V_108 = V_95 ;
V_107 -> V_109 = ( unsigned long ) V_96 -
( unsigned long ) V_90 [ V_95 ] . V_103 ;
V_107 -> V_72 = V_97 ;
V_107 -> V_71 = V_71 ;
F_27 ( & V_107 -> V_76 , V_93 ) ;
}
V_56 -> V_105 = V_96 + V_71 ;
if ( ( ( unsigned long ) V_90 [ V_95 ] . V_103
+ V_90 [ V_95 ] . V_104 ) <
( ( unsigned long ) V_90 [ V_95 ] . V_103 ) ) {
F_3 ( L_19 ) ;
F_17 ( V_94 ) ;
return - V_41 ;
}
if ( ( ( unsigned long ) V_90 [ V_95 ] . V_103
+ V_90 [ V_95 ] . V_104 ) ==
( unsigned long ) V_56 -> V_105 ) {
V_56 -> V_105 = NULL ;
V_56 -> V_101 ++ ;
}
V_97 += V_71 ;
F_3 ( L_20 , V_97 ) ;
if ( ( V_97 >= V_44 ) ||
( V_56 -> V_101 == V_91 ) ) {
V_98 = 1 ;
}
if ( V_98 ) {
V_94 -> V_74 = false ;
V_94 -> V_71 = V_97 ;
F_8 ( & V_56 -> V_75 ) ;
F_27 ( & V_94 -> V_76 , & V_56 -> V_53 ) ;
F_11 ( & V_56 -> V_75 ) ;
break;
}
}
return V_1 ;
}
static int F_35 ( struct V_55 * V_56 ,
const struct V_90 * V_90 ,
struct V_92 * V_93 )
{
struct V_106 * V_107 , * V_110 ;
struct V_52 * V_111 = NULL , * V_112 ;
int V_1 = 0 ;
F_3 ( L_21 ) ;
F_36 (kbufs, _kbufs, &stream->bufs, node) {
if ( V_111 -> V_74 == true ) {
F_36 (entry, _entry,
copy_to_list, node) {
if ( F_37 ( V_90 [ V_107 -> V_108 ] . V_103 + V_107 -> V_109 ,
V_111 -> V_73 + V_107 -> V_72 ,
V_107 -> V_71 ) ) {
V_1 = - V_69 ;
break;
}
F_38 ( & V_107 -> V_76 ) ;
F_17 ( V_107 ) ;
}
}
}
F_3 ( L_22 ) ;
return V_1 ;
}
static int F_39 ( const struct V_90 * V_90 ,
unsigned long V_91 , unsigned int V_30 ,
struct V_55 * V_56 )
{
int V_1 ;
F_40 ( V_93 ) ;
V_1 = F_33 ( V_56 , V_90 , V_91 ,
& V_93 ) ;
V_1 = F_32 ( V_56 , V_30 ) ;
if ( V_1 < 0 )
return V_1 ;
if ( V_56 -> V_84 == V_86 ) {
V_1 = F_35 ( V_56 , V_90 ,
& V_93 ) ;
}
return V_1 ;
}
static int F_41 ( unsigned int V_30 , char V_67 * V_113 ,
T_3 V_114 )
{
int V_1 ;
struct V_55 * V_56 ;
struct V_90 V_90 ;
unsigned long V_91 ;
V_1 = F_20 ( V_30 ) ;
if ( V_1 )
return - V_41 ;
V_56 = & V_2 -> V_48 [ V_30 ] ;
if ( V_56 -> V_49 == true ) {
F_2 ( L_23 ) ;
return - V_5 ;
}
if ( ! V_114 )
return - V_41 ;
V_56 -> V_64 = 0 ;
V_56 -> V_65 = 0 ;
F_3 ( L_24 ,
V_113 , ( int ) V_114 , ( int ) V_56 -> V_60 ) ;
V_56 -> V_115 = V_116 ;
V_90 . V_103 = V_113 ;
V_90 . V_104 = V_114 ;
V_91 = 1 ;
do {
V_1 = F_39 (
& V_90 , V_91 , V_30 , V_56 ) ;
if ( V_1 < 0 )
break;
} while ( V_56 -> V_101 < V_91 );
V_56 -> V_101 = 0 ;
V_56 -> V_105 = NULL ;
if ( V_1 >= 0 )
V_1 = V_56 -> V_65 ;
F_3 ( L_25 , V_1 ) ;
return V_1 ;
}
int F_42 ( struct V_19 * V_20 , const char V_67 * V_113 ,
T_3 V_114 , T_4 * V_72 )
{
struct V_25 * V_26 = V_20 -> V_31 ;
int V_30 = V_26 -> V_30 ;
struct V_55 * V_56 = & V_2 -> V_48 [ V_30 ] ;
F_3 ( L_26 , V_30 ) ;
if ( V_56 -> V_60 == V_61 ||
V_56 -> V_60 == V_62 ) {
return - V_63 ;
}
return F_41 ( V_30 , ( char V_67 * ) V_113 , V_114 ) ;
}
T_5 F_43 ( struct V_117 * V_117 , const struct V_90 * V_118 ,
unsigned long V_91 , T_4 V_72 )
{
int V_1 ;
struct V_25 * V_26 = V_117 -> V_119 -> V_31 ;
int V_30 = V_26 -> V_30 ;
struct V_55 * V_56 ;
F_3 ( L_27 , V_91 ) ;
if ( F_44 ( V_117 ) == false )
return - V_41 ;
F_3 ( L_10 , V_30 ) ;
V_1 = F_20 ( V_30 ) ;
if ( V_1 )
return - V_41 ;
V_56 = & V_2 -> V_48 [ V_30 ] ;
if ( V_56 -> V_49 == true )
return - V_5 ;
if ( V_56 -> V_60 == V_61 ||
V_56 -> V_60 == V_62 ) {
return - V_63 ;
}
V_56 -> V_64 = 0 ;
V_56 -> V_65 = 0 ;
F_3 ( L_28 ,
V_91 , ( int ) V_72 , ( int ) V_56 -> V_60 ) ;
V_56 -> V_115 = V_116 ;
do {
V_1 = F_39 ( V_118 , V_91 ,
V_30 , V_56 ) ;
if ( V_1 < 0 )
break;
} while ( V_56 -> V_101 < V_91 );
V_56 -> V_101 = 0 ;
V_56 -> V_105 = NULL ;
if ( V_1 >= 0 )
V_1 = V_56 -> V_65 ;
F_3 ( L_25 , V_1 ) ;
return V_1 ;
}
int F_45 ( struct V_19 * V_20 , char V_67 * V_113 ,
T_3 V_114 , T_4 * V_72 )
{
struct V_25 * V_26 = V_20 -> V_31 ;
int V_30 = V_26 -> V_30 ;
struct V_55 * V_56 = & V_2 -> V_48 [ V_30 ] ;
F_3 ( L_26 , V_30 ) ;
if ( V_56 -> V_60 == V_61 ||
V_56 -> V_60 == V_62 )
return - V_63 ;
return F_41 ( V_30 , V_113 , V_114 ) ;
}
T_5 F_46 ( struct V_117 * V_117 , const struct V_90 * V_118 ,
unsigned long V_91 , T_4 V_72 )
{
int V_1 ;
struct V_25 * V_26 = V_117 -> V_119 -> V_31 ;
int V_30 = V_26 -> V_30 ;
struct V_55 * V_56 ;
F_3 ( L_27 , V_91 ) ;
if ( F_44 ( V_117 ) == false ) {
F_3 ( L_29 ) ;
return - V_41 ;
}
F_3 ( L_10 , V_30 ) ;
V_1 = F_20 ( V_30 ) ;
if ( V_1 )
return - V_41 ;
V_56 = & V_2 -> V_48 [ V_30 ] ;
if ( V_56 -> V_49 == true )
return - V_5 ;
if ( V_56 -> V_60 == V_61 ||
V_56 -> V_60 == V_62 )
return - V_63 ;
V_56 -> V_64 = 0 ;
V_56 -> V_65 = 0 ;
F_3 ( L_28 ,
V_91 , ( int ) V_72 , ( int ) V_56 -> V_60 ) ;
V_56 -> V_115 = V_116 ;
do {
V_1 = F_39 ( V_118 , V_91 ,
V_30 , V_56 ) ;
if ( V_1 < 0 )
break;
} while ( V_56 -> V_101 < V_91 );
V_56 -> V_101 = 0 ;
V_56 -> V_105 = NULL ;
if ( V_1 >= 0 )
V_1 = V_56 -> V_65 ;
F_3 ( L_25 , V_1 ) ;
return V_1 ;
}
static void F_47 ( struct V_120 * V_121 )
{
F_3 ( L_30 ,
V_121 -> V_122 . V_123 ) ;
F_3 ( L_31 ,
V_121 -> V_122 . V_124 ) ;
F_3 ( L_32 ,
V_121 -> V_122 . V_125 ) ;
F_3 ( L_33 ,
V_121 -> V_122 . V_84 ) ;
F_3 ( L_34 ,
V_121 -> V_122 . V_126 ) ;
F_3 ( L_35 ,
V_121 -> V_127 . V_128 ) ;
F_3 ( L_36 ,
V_121 -> V_127 . V_129 ) ;
F_3 ( L_37 ,
V_121 -> V_127 . V_130 ) ;
return;
}
int F_48 ( struct V_131 * V_132 ,
struct V_133 * * V_134 )
{
if ( F_49 ( V_134 ) )
return - V_28 ;
F_50 ( & ( * V_134 ) -> V_135 ,
V_136 , 1 , V_132 -> V_30 ) ;
( * V_134 ) -> V_135 . V_137 . V_26 = sizeof( T_1 ) +
sizeof( * V_132 ) + V_132 -> V_71 ;
memcpy ( ( * V_134 ) -> V_138 , & ( * V_134 ) -> V_135 , sizeof( T_1 ) ) ;
memcpy ( ( * V_134 ) -> V_138 + sizeof( T_1 ) ,
V_132 , sizeof( * V_132 ) ) ;
return 0 ;
}
int F_51 ( struct V_133 * * V_134 )
{
V_2 -> V_139 . V_78 = false ;
V_2 -> V_139 . V_79 = 0 ;
V_2 -> V_139 . V_87 = true ;
V_2 -> V_139 . V_26 = NULL ;
F_52 ( & V_2 -> V_140 ) ;
F_27 ( & ( * V_134 ) -> V_76 , & V_2 -> V_141 ) ;
F_53 ( & V_2 -> V_140 ) ;
F_54 ( & V_2 -> V_142 ) ;
return F_55 ( V_2 ,
& V_2 -> V_139 , V_143 ) ;
}
long F_56 ( unsigned int V_144 , unsigned long V_145 )
{
int V_1 = 0 ;
struct V_131 V_132 ;
struct V_131 * V_146 ;
struct V_133 * V_134 ;
switch ( F_57 ( V_144 ) ) {
case F_57 ( V_147 ) :
if ( F_26 ( & V_132 , ( void V_67 * ) V_145 ,
sizeof( V_132 ) ) )
return - V_69 ;
if ( V_132 . V_71 > V_148 )
return - V_149 ;
F_3 ( L_38 ,
V_132 . V_150 , V_132 . V_30 ,
V_132 . V_151 , V_132 . V_71 ) ;
V_1 = F_48 ( & V_132 , & V_134 ) ;
if ( V_1 )
break;
V_132 . V_152 = 0 ;
if ( F_26 ( V_134 -> V_138 + sizeof( V_132 ) ,
V_132 . V_153 , V_132 . V_71 ) )
return - V_69 ;
V_1 = F_51 ( & V_134 ) ;
if ( V_1 ) {
F_3 ( L_39 , V_1 ) ;
V_1 = - V_5 ;
}
break;
case F_57 ( V_154 ) :
if ( F_26 ( & V_132 , ( void V_67 * ) V_145 ,
sizeof( V_132 ) ) )
return - V_69 ;
F_3 ( L_38 ,
V_132 . V_150 , V_132 . V_30 ,
V_132 . V_151 , V_132 . V_71 ) ;
V_1 = F_48 ( & V_132 , & V_134 ) ;
if ( V_1 )
break;
V_132 . V_152 = 1 ;
V_1 = F_51 ( & V_134 ) ;
if ( V_1 ) {
F_3 ( L_40 , V_1 ) ;
V_1 = - V_5 ;
break;
}
V_146 = (struct V_131 * )
V_2 -> V_139 . V_26 ;
if ( V_146 -> V_71 > V_132 . V_71 ) {
F_3 ( L_41 ) ;
V_1 = - V_149 ;
goto V_155;
} else {
char V_67 * V_156 ;
if ( F_37 ( V_132 . V_153 ,
V_146 -> V_153 ,
V_146 -> V_71 ) ) {
V_1 = - V_69 ;
goto V_155;
}
V_156 = ( char V_67 * ) V_145 + F_58 (
struct V_131 , V_71 ) ;
if ( F_37 ( V_156 , & V_146 -> V_71 ,
sizeof( T_2 ) ) ) {
V_1 = - V_69 ;
goto V_155;
}
}
V_155:
F_17 ( V_146 -> V_153 ) ;
F_17 ( V_146 ) ;
break;
}
return V_1 ;
}
int F_59 ( unsigned long V_145 )
{
struct V_157 V_153 ;
struct V_133 * V_134 ;
if ( F_26 ( & V_153 , ( void V_67 * ) V_145 , sizeof( V_153 ) ) )
return - V_69 ;
if ( V_153 . V_71 > V_148 )
return - V_28 ;
F_3 ( L_42 , V_153 . type ,
V_153 . V_30 , V_153 . V_71 ) ;
if ( F_49 ( & V_134 ) )
return - V_28 ;
F_50 ( & V_134 -> V_135 , V_158 , 1 , V_153 . V_30 ) ;
V_134 -> V_135 . V_137 . V_26 = sizeof( T_1 ) + sizeof( V_153 ) + V_153 . V_71 ;
memcpy ( V_134 -> V_138 , & V_134 -> V_135 . V_159 , sizeof( T_1 ) ) ;
memcpy ( V_134 -> V_138 + sizeof( T_1 ) , & V_153 , sizeof( V_153 ) ) ;
if ( F_26 ( V_134 -> V_138 + sizeof( V_153 ) ,
( void V_67 * ) ( unsigned long ) V_153 . V_73 ,
V_153 . V_71 ) ) {
F_17 ( V_134 -> V_138 ) ;
F_17 ( V_134 ) ;
return - V_69 ;
}
return F_51 ( & V_134 ) ;
}
long F_60 ( struct V_19 * V_20 , unsigned int V_144 , unsigned long V_145 )
{
int V_1 = 0 ;
struct V_25 * V_26 = NULL ;
int V_30 = 0 , V_160 = 0 ;
V_26 = V_20 -> V_31 ;
if ( V_26 ) {
V_160 = 0 ;
V_30 = V_26 -> V_30 ;
} else
V_160 = 1 ;
if ( V_2 -> V_6 != V_161 )
return - V_162 ;
switch ( F_57 ( V_144 ) ) {
case F_57 ( V_163 ) :
F_3 ( L_43 , V_30 ) ;
if ( V_160 != V_164 ) {
V_1 = - V_63 ;
break;
}
V_1 = F_61 ( V_30 ) ;
break;
case F_57 ( V_165 ) :
F_3 ( L_44 ) ;
if ( V_160 != V_164 ) {
V_1 = - V_63 ;
break;
}
V_1 = F_62 ( V_30 ) ;
break;
case F_57 ( V_166 ) : {
struct V_167 V_168 ;
F_3 ( L_45 ) ;
if ( V_160 != V_164 ) {
V_1 = - V_63 ;
break;
}
if ( F_26 ( & V_168 , ( void V_67 * ) V_145 ,
sizeof( V_168 ) ) ) {
V_1 = - V_69 ;
break;
}
if ( ! V_30 ) {
V_1 = F_63 ( & V_168 ) ;
if ( V_1 > 0 ) {
struct V_55 * V_169 ;
char V_67 * V_170 ;
V_2 -> V_36 ++ ;
V_26 -> V_30 = V_1 ;
V_169 = & V_2 -> V_48 [ V_1 ] ;
V_169 -> V_171 = V_172 ;
V_170 = ( char V_67 * ) V_145 + F_58 ( struct V_167 , V_124 ) ;
V_1 = F_37 ( V_170 , & V_1 , sizeof( T_2 ) ) ;
if ( V_1 )
V_1 = - V_69 ;
} else {
if ( V_1 == - V_173 )
V_1 = - V_41 ;
}
} else {
F_3 ( L_46 ) ;
V_1 = F_64 ( V_30 , & V_168 ) ;
if ( ! V_1 ) {
int V_128 = 0 , V_174 = 0 , V_175 = 0 ;
V_128 = V_168 . V_176 . V_177 . V_127 . V_128 ;
V_174 = V_168 . V_176 . V_177 . V_127 . V_130 ;
V_175 = V_168 . V_176 . V_177 . V_127 . V_129 ;
if ( V_168 . V_84 == V_86 ) {
V_2 -> V_178 ->\
V_179 ( V_128 ,
V_174 , V_175 ) ;
}
}
}
break;
}
case F_57 ( V_180 ) : {
struct V_181 V_182 ;
if ( F_26 ( & V_182 , ( void V_67 * ) V_145 ,
sizeof( V_182 ) ) ) {
F_3 ( L_47 ) ;
V_1 = - V_69 ;
break;
}
F_3 ( L_48 ,
V_182 . V_124 ) ;
if ( V_160 == V_164 && V_182 . V_124 == 0 ) {
F_3 ( L_49 ) ;
V_1 = - V_183 ;
break;
}
V_1 = F_65 ( & V_182 ) ;
break;
}
case F_57 ( V_184 ) : {
struct V_181 V_185 ;
if ( F_26 ( & V_185 , ( void V_67 * ) V_145 ,
sizeof( V_185 ) ) ) {
V_1 = - V_69 ;
break;
}
F_3 ( L_50 ,
V_185 . V_124 ) ;
if ( V_160 == V_164 && V_185 . V_124 == 0 ) {
F_3 ( L_49 ) ;
V_1 = - V_183 ;
break;
}
V_1 = F_66 ( & V_185 ) ;
if ( V_1 ) {
V_1 = - V_5 ;
break;
}
F_3 ( L_51 ,
V_185 . V_124 , V_185 . V_186 ,
V_185 . V_187 , V_185 . V_188 ) ;
if ( F_37 ( (struct V_181 V_67 * ) V_145 ,
& V_185 , sizeof( V_185 ) ) ) {
V_1 = - V_69 ;
break;
}
break;
}
case F_57 ( V_189 ) : {
struct V_190 V_191 ;
if ( F_26 ( & V_191 , ( void V_67 * ) V_145 ,
sizeof( V_191 ) ) ) {
V_1 = - V_69 ;
break;
}
F_3 ( L_52 ,
V_191 . V_124 ) ;
if ( V_160 == V_164 && V_191 . V_124 == 0 ) {
V_1 = - V_183 ;
break;
}
V_1 = F_67 ( & V_191 ) ;
break;
}
case F_57 ( V_192 ) : {
struct V_120 V_193 ;
F_3 ( L_53 ) ;
if ( V_160 != 0 ) {
V_1 = - V_63 ;
break;
}
V_1 = F_68 ( V_30 , & V_193 ) ;
if ( V_1 ) {
V_1 = - V_5 ;
break;
}
if ( F_37 ( (struct V_120 V_67 * ) V_145 ,
& V_193 , sizeof( V_193 ) ) ) {
V_1 = - V_69 ;
break;
}
F_47 ( & V_193 ) ;
break;
}
case F_57 ( V_194 ) :
case F_57 ( V_195 ) : {
struct V_50 V_51 ;
F_3 ( L_54 ) ;
if ( V_160 != V_164 ) {
V_1 = - V_63 ;
break;
}
if ( F_26 ( & V_51 , ( void V_67 * ) V_145 ,
sizeof( V_51 ) ) ) {
V_1 = - V_69 ;
break;
}
V_1 = F_24 ( V_30 , & V_51 ) ;
break;
}
case F_57 ( V_196 ) :
F_3 ( L_55 ) ;
if ( V_160 != V_164 ) {
V_1 = - V_41 ;
break;
}
V_1 = F_69 ( V_30 ) ;
break;
case F_57 ( V_197 ) : {
struct V_198 V_199 = { 0 } ;
unsigned long long time , V_200 , V_201 ;
F_3 ( L_56 ) ;
if ( V_160 != V_164 ) {
V_1 = - V_63 ;
break;
}
F_70 ( & V_199 ,
V_2 -> V_202 + V_203 + V_30 * sizeof( V_199 ) ,
sizeof( V_199 ) ) ;
time = V_199 . V_204 ;
V_200 = ( unsigned long long ) V_199 . V_205 ;
time = time * 1000 ;
V_201 = F_71 ( time , V_200 ) ;
if ( F_37 ( ( void V_67 * ) V_145 , & time ,
sizeof( unsigned long long ) ) )
V_1 = - V_69 ;
break;
}
case F_57 ( V_206 ) : {
struct V_55 * V_56 ;
F_3 ( L_57 ) ;
if ( V_160 != V_164 ) {
V_1 = - V_41 ;
break;
}
V_1 = F_20 ( V_30 ) ;
if ( V_1 )
break;
V_56 = & V_2 -> V_48 [ V_30 ] ;
F_8 ( & V_56 -> V_75 ) ;
if ( V_56 -> V_60 == V_80 &&
V_56 -> V_82 != true ) {
V_56 -> V_81 = V_56 -> V_60 ;
V_56 -> V_60 = V_83 ;
if ( V_56 -> V_84 == V_85 ||
V_56 -> V_84 == V_89 ) {
V_1 = F_28 ( V_30 ) ;
} else if ( V_56 -> V_84 == V_86 )
V_1 = F_29 ( V_30 ) ;
else {
V_1 = - V_41 ;
F_11 ( & V_56 -> V_75 ) ;
break;
}
if ( V_1 < 0 ) {
V_56 -> V_60 = V_80 ;
F_11 ( & V_56 -> V_75 ) ;
break;
}
} else {
V_1 = - V_41 ;
}
F_11 ( & V_56 -> V_75 ) ;
break;
}
case F_57 ( V_207 ) : {
struct V_208 V_209 ;
F_3 ( L_58 ) ;
if ( F_26 ( & V_209 , ( void V_67 * ) V_145 ,
sizeof( V_209 ) ) ) {
V_1 = - V_69 ;
break;
}
if ( V_160 != V_210 ) {
V_1 = - V_63 ;
break;
}
V_1 = F_72 ( & V_209 ) ;
break;
}
case F_57 ( V_211 ) : {
struct V_212 V_213 ;
F_3 ( L_59 ) ;
V_213 . V_214 = V_215 ;
V_213 . V_216 = V_2 -> V_36 -
V_2 -> V_23 ;
V_213 . V_217 = V_2 -> V_23 ;
V_213 . V_218 = V_219 - V_24 ;
V_213 . V_220 = V_24 ;
V_213 . V_221 = V_2 -> V_44 ;
if ( F_37 ( ( void V_67 * ) V_145 , & V_213 ,
sizeof( V_213 ) ) )
V_1 = - V_69 ;
break;
}
case F_57 ( V_222 ) : {
struct V_223 V_224 ;
struct V_223 V_225 ;
struct V_226 V_227 , V_228 ;
struct V_229 * V_230 , * V_231 ;
char V_67 * V_170 ;
F_3 ( L_60 ) ;
if ( V_160 != V_164 ) {
V_1 = - V_63 ;
break;
}
if ( F_26 ( & V_224 , ( void V_67 * ) V_145 ,
sizeof( V_224 ) ) ) {
V_1 = - V_69 ;
break;
}
V_225 . V_232 = V_224 . V_232 ;
V_225 . V_233 =
V_224 . V_233 ;
if ( F_26 ( & V_227 , ( void V_67 * ) V_224 . V_227 , sizeof( V_227 ) ) ) {
V_1 = - V_69 ;
break;
}
if ( F_26 ( & V_228 , ( void V_67 * ) V_224 . V_228 , sizeof( V_228 ) ) ) {
V_1 = - V_69 ;
break;
}
V_230 = F_25 ( V_227 . V_66 , sizeof( * V_230 ) , V_27 ) ;
V_231 = F_25 ( V_228 . V_66 , sizeof( * V_231 ) , V_27 ) ;
if ( ! V_230 || ! V_231 ) {
V_1 = - V_28 ;
goto V_234;
}
if ( F_26 ( V_230 , ( void V_67 * ) V_227 . V_235 ,
V_227 . V_66 * sizeof( * V_230 ) ) ) {
V_1 = - V_69 ;
goto V_234;
}
V_227 . V_235 = V_230 ;
V_225 . V_227 = & V_227 ;
if ( F_26 ( V_231 , ( void V_67 * ) V_228 . V_235 ,
V_228 . V_66 * sizeof( * V_231 ) ) ) {
V_1 = - V_69 ;
goto V_234;
}
V_228 . V_235 = V_231 ;
V_225 . V_228 = & V_228 ;
V_1 = F_73 ( V_30 , & V_225 ) ;
if ( V_1 ) {
V_1 = - V_236 ;
goto V_234;
}
V_170 = ( char V_67 * ) V_145 + F_58 ( struct V_223 , V_232 ) ;
if ( F_37 ( V_170 ,
& V_225 . V_232 ,
sizeof( unsigned long long ) ) ) {
V_1 = - V_69 ;
goto V_234;
}
V_170 = ( char V_67 * ) V_145 + F_58 ( struct V_223 , V_232 ) ;
if ( F_37 ( V_170 ,
& V_225 . V_233 ,
sizeof( unsigned long long ) ) ) {
V_1 = - V_69 ;
goto V_234;
}
V_234:
F_17 ( V_230 ) ;
F_17 ( V_231 ) ;
break;
}
case F_57 ( V_237 ) :
F_3 ( L_61 ) ;
if ( V_160 != V_164 ) {
V_1 = - V_41 ;
break;
}
V_1 = F_74 ( V_30 ) ;
break;
case F_57 ( V_238 ) : {
unsigned long long V_67 * V_239 = ( unsigned long long V_67 * ) V_145 ;
struct V_198 V_199 = { 0 } ;
F_3 ( L_62 ) ;
if ( V_160 != V_164 ) {
V_1 = - V_41 ;
break;
}
F_70 ( & V_199 ,
V_2 -> V_202 + V_203 + V_30 * sizeof( V_199 ) ,
sizeof( V_199 ) ) ;
if ( F_37 ( V_239 , & V_199 . V_240 ,
sizeof( * V_239 ) ) )
V_1 = - V_69 ;
break;
}
case F_57 ( V_241 ) : {
struct V_242 * V_243 ;
F_3 ( L_63 ) ;
V_243 = F_12 ( sizeof( * V_243 ) , V_244 ) ;
if ( ! V_243 ) {
V_1 = - V_28 ;
break;
}
V_1 = F_75 ( V_243 ) ;
if ( V_1 ) {
V_1 = - V_5 ;
F_17 ( V_243 ) ;
break;
}
if ( F_37 ( (struct V_223 V_67 * ) V_145 ,
V_243 , sizeof( * V_243 ) ) ) {
F_17 ( V_243 ) ;
V_1 = - V_69 ;
break;
}
F_17 ( V_243 ) ;
break;
}
case F_57 ( V_154 ) :
case F_57 ( V_147 ) :
if ( V_160 != V_210 ) {
V_1 = - V_63 ;
break;
}
V_1 = F_56 ( V_144 , V_145 ) ;
break;
case F_57 ( V_245 ) :
if ( V_160 != V_210 ) {
V_1 = - V_63 ;
break;
}
V_1 = F_59 ( V_145 ) ;
break;
default:
V_1 = - V_41 ;
}
F_3 ( L_64 , V_1 ) ;
return V_1 ;
}
