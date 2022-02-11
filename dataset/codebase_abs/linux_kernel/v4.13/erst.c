static inline int F_1 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
return 0 ;
case V_3 :
return - V_4 ;
case V_5 :
return - V_6 ;
case V_7 :
case V_8 :
return - V_9 ;
default:
return - V_10 ;
}
}
static int F_2 ( T_1 * V_11 , T_1 V_12 )
{
if ( ( V_13 ) * V_11 < V_12 ) {
F_3 ( V_14 L_1 ) ;
return 1 ;
}
* V_11 -= V_12 ;
F_4 ( V_12 ) ;
F_5 () ;
return 0 ;
}
static int F_6 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
return F_7 ( V_18 , & V_16 -> V_19 ) ;
}
static int F_8 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
return F_7 ( V_18 , & V_16 -> V_20 ) ;
}
static int F_9 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
return F_10 ( V_18 , V_16 -> V_19 ) ;
}
static int F_11 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
V_16 -> V_19 += V_16 -> V_20 ;
return 0 ;
}
static int F_12 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
V_16 -> V_19 -= V_16 -> V_20 ;
return 0 ;
}
static int F_13 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
int V_21 ;
T_1 V_22 ;
V_21 = F_7 ( V_18 , & V_22 ) ;
if ( V_21 )
return V_21 ;
V_22 += V_16 -> V_23 ;
V_21 = F_10 ( V_18 , V_22 ) ;
return V_21 ;
}
static int F_14 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
int V_21 ;
T_1 V_22 ;
V_21 = F_7 ( V_18 , & V_22 ) ;
if ( V_21 )
return V_21 ;
V_22 -= V_16 -> V_23 ;
V_21 = F_10 ( V_18 , V_22 ) ;
return V_21 ;
}
static int F_15 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
T_1 V_24 ;
if ( V_16 -> V_23 > V_25 ) {
if ( ! F_16 () )
F_3 ( V_14
L_2 ,
V_16 -> V_23 ) ;
V_24 = V_25 ;
} else
V_24 = V_16 -> V_23 ;
F_17 ( V_24 ) ;
return 0 ;
}
static int F_18 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
int V_21 ;
T_1 V_22 ;
T_1 V_26 = V_27 ;
T_1 V_24 ;
if ( V_16 -> V_19 > V_25 ) {
if ( ! F_16 () )
F_3 ( V_14
L_3 ,
V_16 -> V_19 ) ;
V_24 = V_25 ;
} else
V_24 = V_16 -> V_19 ;
for (; ; ) {
V_21 = F_7 ( V_18 , & V_22 ) ;
if ( V_21 )
return V_21 ;
if ( V_22 != V_16 -> V_23 )
break;
if ( F_2 ( & V_26 , V_24 * V_28 ) )
return - V_29 ;
}
return 0 ;
}
static int F_19 (
struct V_15 * V_16 ,
struct V_17 * V_18 )
{
int V_21 ;
T_1 V_22 ;
V_21 = F_7 ( V_18 , & V_22 ) ;
if ( V_21 )
return V_21 ;
if ( V_22 == V_16 -> V_23 ) {
V_16 -> V_30 += 2 ;
return V_31 ;
}
return 0 ;
}
static int F_20 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
V_16 -> V_30 = V_16 -> V_23 ;
return V_31 ;
}
static int F_21 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
return F_7 ( V_18 , & V_16 -> V_32 ) ;
}
static int F_22 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
return F_7 ( V_18 , & V_16 -> V_33 ) ;
}
static int F_23 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
int V_21 ;
T_1 V_34 ;
void * V_35 , * V_36 ;
if ( F_24 () ) {
F_3 ( L_4 ) ;
return - V_37 ;
}
V_21 = F_7 ( V_18 , & V_34 ) ;
if ( V_21 )
return V_21 ;
V_35 = F_25 ( V_16 -> V_32 + V_34 , V_16 -> V_20 ) ;
if ( ! V_35 )
return - V_38 ;
V_36 = F_25 ( V_16 -> V_33 + V_34 , V_16 -> V_20 ) ;
if ( ! V_36 ) {
F_26 ( V_35 ) ;
return - V_38 ;
}
memmove ( V_36 , V_35 , V_16 -> V_20 ) ;
F_26 ( V_35 ) ;
F_26 ( V_36 ) ;
return 0 ;
}
static inline void F_27 ( struct V_15 * V_16 )
{
F_28 ( V_16 , V_39 , F_29 ( V_39 ) ,
F_30 ( V_40 ) , V_40 -> V_41 ) ;
}
static int F_31 ( struct V_42 * V_43 )
{
struct V_15 V_16 ;
int V_21 ;
F_27 ( & V_16 ) ;
V_21 = F_32 ( & V_16 , V_44 ) ;
if ( V_21 )
return V_21 ;
V_43 -> V_45 = F_33 ( & V_16 ) ;
V_21 = F_32 ( & V_16 , V_46 ) ;
if ( V_21 )
return V_21 ;
V_43 -> V_47 = F_33 ( & V_16 ) ;
V_21 = F_32 ( & V_16 , V_48 ) ;
if ( V_21 )
return V_21 ;
V_43 -> V_49 = F_33 ( & V_16 ) ;
return 0 ;
}
static T_2 F_34 ( void )
{
struct V_15 V_16 ;
int V_21 ;
F_27 ( & V_16 ) ;
V_21 = F_32 ( & V_16 , V_50 ) ;
if ( V_21 )
return V_21 ;
return F_33 ( & V_16 ) ;
}
T_2 F_35 ( void )
{
T_2 V_51 ;
unsigned long V_52 ;
if ( V_53 )
return - V_4 ;
F_36 ( & V_54 , V_52 ) ;
V_51 = F_34 () ;
F_37 ( & V_54 , V_52 ) ;
return V_51 ;
}
static int F_38 ( T_1 * V_55 )
{
struct V_15 V_16 ;
int V_21 ;
F_27 ( & V_16 ) ;
V_21 = F_32 ( & V_16 , V_56 ) ;
if ( V_21 )
return V_21 ;
* V_55 = F_33 ( & V_16 ) ;
return 0 ;
}
int F_39 ( int * V_57 )
{
int V_21 ;
if ( V_53 )
return - V_4 ;
V_21 = F_40 ( & V_58 . V_59 ) ;
if ( V_21 )
return V_21 ;
V_58 . V_60 ++ ;
F_41 ( & V_58 . V_59 ) ;
* V_57 = 0 ;
return 0 ;
}
static int F_42 ( void )
{
T_1 V_61 , V_62 , V_63 ;
int V_64 , V_21 ;
T_1 * V_41 ;
unsigned long V_52 ;
V_61 = V_62 = V_63 = V_65 ;
V_66:
F_36 ( & V_54 , V_52 ) ;
V_21 = F_38 ( & V_61 ) ;
F_37 ( & V_54 , V_52 ) ;
if ( V_21 == - V_9 )
return 0 ;
if ( V_21 )
return V_21 ;
if ( V_61 == V_65 )
return 0 ;
if ( V_61 == V_62 || V_61 == V_63 )
return 0 ;
if ( V_63 == V_65 )
V_63 = V_61 ;
V_62 = V_61 ;
V_41 = V_58 . V_41 ;
for ( V_64 = 0 ; V_64 < V_58 . V_67 ; V_64 ++ ) {
if ( V_41 [ V_64 ] == V_61 )
break;
}
if ( V_64 < V_58 . V_67 )
goto V_66;
if ( V_58 . V_67 >= V_58 . V_47 ) {
int V_68 ;
T_1 * V_69 ;
V_68 = V_58 . V_47 * 2 ;
V_68 = F_43 ( V_68 , V_70 ,
V_71 ) ;
if ( V_68 <= V_58 . V_47 ) {
if ( F_44 () )
F_3 ( V_14 L_5 ) ;
return 0 ;
}
V_69 = F_45 ( V_68 * sizeof( V_41 [ 0 ] ) , V_72 ) ;
if ( ! V_69 )
return - V_38 ;
memcpy ( V_69 , V_41 ,
V_58 . V_67 * sizeof( V_41 [ 0 ] ) ) ;
F_46 ( V_41 ) ;
V_58 . V_41 = V_41 = V_69 ;
V_58 . V_47 = V_68 ;
}
V_41 [ V_64 ] = V_61 ;
V_58 . V_67 ++ ;
return 1 ;
}
int F_47 ( int * V_57 , T_1 * V_55 )
{
int V_21 = 0 ;
T_1 * V_41 ;
if ( V_53 )
return - V_4 ;
F_48 ( ! V_58 . V_60 ) ;
F_48 ( * V_57 < 0 || * V_57 > V_58 . V_67 ) ;
F_49 ( & V_58 . V_59 ) ;
V_41 = V_58 . V_41 ;
for (; * V_57 < V_58 . V_67 ; ( * V_57 ) ++ )
if ( V_41 [ * V_57 ] != V_65 )
break;
if ( * V_57 < V_58 . V_67 ) {
* V_55 = V_41 [ * V_57 ] ;
( * V_57 ) ++ ;
goto V_73;
}
V_21 = F_42 () ;
if ( V_21 < 0 )
goto V_73;
if ( V_21 == 1 ) {
* V_55 = V_58 . V_41 [ * V_57 ] ;
( * V_57 ) ++ ;
V_21 = 0 ;
} else {
* V_57 = - 1 ;
* V_55 = V_65 ;
}
V_73:
F_41 ( & V_58 . V_59 ) ;
return V_21 ;
}
static void F_50 ( void )
{
int V_64 , V_74 = 0 ;
T_1 * V_41 ;
if ( V_58 . V_60 )
return;
V_41 = V_58 . V_41 ;
for ( V_64 = 0 ; V_64 < V_58 . V_67 ; V_64 ++ ) {
if ( V_41 [ V_64 ] == V_65 )
continue;
if ( V_74 != V_64 )
V_41 [ V_74 ] = V_41 [ V_64 ] ;
V_74 ++ ;
}
V_58 . V_67 = V_74 ;
}
void F_51 ( void )
{
F_48 ( V_53 ) ;
F_49 ( & V_58 . V_59 ) ;
V_58 . V_60 -- ;
F_48 ( V_58 . V_60 < 0 ) ;
F_50 () ;
F_41 ( & V_58 . V_59 ) ;
}
static int F_52 ( T_1 V_34 )
{
struct V_15 V_16 ;
T_1 V_26 = V_27 ;
T_1 V_22 ;
int V_21 ;
F_27 ( & V_16 ) ;
V_21 = F_53 ( & V_16 , V_75 ) ;
if ( V_21 )
return V_21 ;
F_54 ( & V_16 , V_34 ) ;
V_21 = F_32 ( & V_16 , V_76 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_32 ( & V_16 , V_77 ) ;
if ( V_21 )
return V_21 ;
for (; ; ) {
V_21 = F_32 ( & V_16 , V_78 ) ;
if ( V_21 )
return V_21 ;
V_22 = F_33 ( & V_16 ) ;
if ( ! V_22 )
break;
if ( F_2 ( & V_26 , V_79 ) )
return - V_29 ;
}
V_21 = F_32 ( & V_16 , V_80 ) ;
if ( V_21 )
return V_21 ;
V_22 = F_33 ( & V_16 ) ;
V_21 = F_53 ( & V_16 , V_81 ) ;
if ( V_21 )
return V_21 ;
return F_1 ( V_22 ) ;
}
static int F_55 ( T_1 V_55 , T_1 V_34 )
{
struct V_15 V_16 ;
T_1 V_26 = V_27 ;
T_1 V_22 ;
int V_21 ;
F_27 ( & V_16 ) ;
V_21 = F_53 ( & V_16 , V_82 ) ;
if ( V_21 )
return V_21 ;
F_54 ( & V_16 , V_34 ) ;
V_21 = F_32 ( & V_16 , V_76 ) ;
if ( V_21 )
return V_21 ;
F_54 ( & V_16 , V_55 ) ;
V_21 = F_32 ( & V_16 , V_83 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_32 ( & V_16 , V_77 ) ;
if ( V_21 )
return V_21 ;
for (; ; ) {
V_21 = F_32 ( & V_16 , V_78 ) ;
if ( V_21 )
return V_21 ;
V_22 = F_33 ( & V_16 ) ;
if ( ! V_22 )
break;
if ( F_2 ( & V_26 , V_79 ) )
return - V_29 ;
} ;
V_21 = F_32 ( & V_16 , V_80 ) ;
if ( V_21 )
return V_21 ;
V_22 = F_33 ( & V_16 ) ;
V_21 = F_53 ( & V_16 , V_81 ) ;
if ( V_21 )
return V_21 ;
return F_1 ( V_22 ) ;
}
static int F_56 ( T_1 V_55 )
{
struct V_15 V_16 ;
T_1 V_26 = V_27 ;
T_1 V_22 ;
int V_21 ;
F_27 ( & V_16 ) ;
V_21 = F_53 ( & V_16 , V_84 ) ;
if ( V_21 )
return V_21 ;
F_54 ( & V_16 , V_55 ) ;
V_21 = F_32 ( & V_16 , V_83 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_32 ( & V_16 , V_77 ) ;
if ( V_21 )
return V_21 ;
for (; ; ) {
V_21 = F_32 ( & V_16 , V_78 ) ;
if ( V_21 )
return V_21 ;
V_22 = F_33 ( & V_16 ) ;
if ( ! V_22 )
break;
if ( F_2 ( & V_26 , V_79 ) )
return - V_29 ;
}
V_21 = F_32 ( & V_16 , V_80 ) ;
if ( V_21 )
return V_21 ;
V_22 = F_33 ( & V_16 ) ;
V_21 = F_53 ( & V_16 , V_81 ) ;
if ( V_21 )
return V_21 ;
return F_1 ( V_22 ) ;
}
static void F_57 ( void )
{
if ( F_44 () )
F_3 ( L_6 ) ;
}
static int F_58 ( const struct V_85 * V_86 )
{
return - V_87 ;
}
static int F_59 ( T_1 V_55 , T_1 * V_34 )
{
F_57 () ;
return - V_87 ;
}
static int F_60 ( T_1 V_55 )
{
F_57 () ;
return - V_87 ;
}
int F_61 ( const struct V_85 * V_86 )
{
int V_21 ;
unsigned long V_52 ;
struct V_85 * V_88 ;
if ( V_53 )
return - V_4 ;
if ( memcmp ( V_86 -> V_89 , V_90 , V_91 ) )
return - V_10 ;
if ( V_42 . V_49 & V_92 ) {
if ( ! F_62 ( & V_54 , V_52 ) )
return - V_37 ;
V_21 = F_58 ( V_86 ) ;
F_37 ( & V_54 , V_52 ) ;
return V_21 ;
}
if ( V_86 -> V_93 > V_42 . V_47 )
return - V_10 ;
if ( ! F_62 ( & V_54 , V_52 ) )
return - V_37 ;
memcpy ( V_42 . V_94 , V_86 , V_86 -> V_93 ) ;
V_88 = V_42 . V_94 ;
memcpy ( & V_88 -> V_95 , L_7 , 2 ) ;
V_21 = F_52 ( 0 ) ;
F_37 ( & V_54 , V_52 ) ;
return V_21 ;
}
static int F_63 ( T_1 V_55 , T_1 * V_34 )
{
int V_21 ;
if ( V_42 . V_49 & V_92 )
return F_59 (
V_55 , V_34 ) ;
V_21 = F_55 ( V_55 , 0 ) ;
if ( V_21 )
return V_21 ;
* V_34 = 0 ;
return 0 ;
}
static T_2 F_64 ( T_1 V_55 , struct V_85 * V_86 ,
T_3 V_96 )
{
int V_21 ;
T_1 V_34 , V_67 = 0 ;
struct V_85 * V_97 ;
V_21 = F_63 ( V_55 , & V_34 ) ;
if ( V_21 )
return V_21 ;
V_97 = V_42 . V_94 + V_34 ;
V_67 = V_97 -> V_93 ;
if ( V_67 <= V_96 )
memcpy ( V_86 , V_97 , V_67 ) ;
return V_67 ;
}
T_2 F_65 ( T_1 V_55 , struct V_85 * V_86 ,
T_3 V_96 )
{
T_2 V_67 ;
unsigned long V_52 ;
if ( V_53 )
return - V_4 ;
F_36 ( & V_54 , V_52 ) ;
V_67 = F_64 ( V_55 , V_86 , V_96 ) ;
F_37 ( & V_54 , V_52 ) ;
return V_67 ;
}
int F_66 ( T_1 V_55 )
{
int V_21 , V_64 ;
unsigned long V_52 ;
T_1 * V_41 ;
if ( V_53 )
return - V_4 ;
V_21 = F_40 ( & V_58 . V_59 ) ;
if ( V_21 )
return V_21 ;
F_36 ( & V_54 , V_52 ) ;
if ( V_42 . V_49 & V_92 )
V_21 = F_60 ( V_55 ) ;
else
V_21 = F_56 ( V_55 ) ;
F_37 ( & V_54 , V_52 ) ;
if ( V_21 )
goto V_98;
V_41 = V_58 . V_41 ;
for ( V_64 = 0 ; V_64 < V_58 . V_67 ; V_64 ++ ) {
if ( V_41 [ V_64 ] == V_55 )
V_41 [ V_64 ] = V_65 ;
}
F_50 () ;
V_98:
F_41 ( & V_58 . V_59 ) ;
return V_21 ;
}
static int T_4 F_67 ( char * V_99 )
{
V_53 = 1 ;
return 0 ;
}
static int F_68 ( struct V_100 * V_40 )
{
if ( ( V_40 -> V_101 !=
( sizeof( struct V_100 ) - sizeof( V_40 -> V_102 ) ) )
&& ( V_40 -> V_101 != sizeof( struct V_100 ) ) )
return - V_10 ;
if ( V_40 -> V_102 . V_103 < sizeof( struct V_100 ) )
return - V_10 ;
if ( V_40 -> V_41 !=
( V_40 -> V_102 . V_103 - sizeof( struct V_100 ) ) /
sizeof( struct V_104 ) )
return - V_10 ;
return 0 ;
}
static int F_69 ( struct V_105 * V_106 )
{
int V_21 ;
if ( V_53 )
return - V_4 ;
V_21 = F_39 ( & V_107 ) ;
return V_21 ;
}
static int F_70 ( struct V_105 * V_106 )
{
F_51 () ;
return 0 ;
}
static T_2 F_71 ( struct V_108 * V_86 )
{
int V_21 ;
T_2 V_67 = 0 ;
T_1 V_55 ;
struct V_109 * V_110 ;
T_3 V_111 = sizeof( * V_110 ) + V_112 . V_113 ;
if ( V_53 )
return - V_4 ;
V_110 = F_72 ( V_111 , V_72 ) ;
if ( ! V_110 ) {
V_21 = - V_38 ;
goto V_98;
}
V_114:
V_21 = F_47 ( & V_107 , & V_55 ) ;
if ( V_21 )
goto V_98;
if ( V_55 == V_65 ) {
V_21 = - V_10 ;
goto V_98;
}
V_67 = F_65 ( V_55 , & V_110 -> V_115 , V_111 ) ;
if ( V_67 == - V_9 )
goto V_114;
else if ( V_67 < sizeof( * V_110 ) ) {
V_21 = - V_29 ;
goto V_98;
}
if ( F_73 ( V_110 -> V_115 . V_116 , V_117 ) != 0 )
goto V_114;
V_86 -> V_118 = F_72 ( V_67 , V_72 ) ;
if ( V_86 -> V_118 == NULL ) {
V_21 = - V_38 ;
goto V_98;
}
memcpy ( V_86 -> V_118 , V_110 -> V_119 , V_67 - sizeof( * V_110 ) ) ;
V_86 -> V_61 = V_55 ;
V_86 -> V_120 = false ;
V_86 -> V_121 = 0 ;
if ( F_73 ( V_110 -> V_122 . V_123 ,
V_124 ) == 0 ) {
V_86 -> type = V_125 ;
V_86 -> V_120 = true ;
} else if ( F_73 ( V_110 -> V_122 . V_123 ,
V_126 ) == 0 )
V_86 -> type = V_125 ;
else if ( F_73 ( V_110 -> V_122 . V_123 ,
V_127 ) == 0 )
V_86 -> type = V_128 ;
else
V_86 -> type = V_129 ;
if ( V_110 -> V_115 . V_130 & V_131 )
V_86 -> time . V_132 = V_110 -> V_115 . V_133 ;
else
V_86 -> time . V_132 = 0 ;
V_86 -> time . V_134 = 0 ;
V_98:
F_74 ( V_110 ) ;
return ( V_21 < 0 ) ? V_21 : ( V_67 - sizeof( * V_110 ) ) ;
}
static int F_75 ( struct V_108 * V_86 )
{
struct V_109 * V_110 = (struct V_109 * )
( V_112 . V_118 - sizeof( * V_110 ) ) ;
int V_135 ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
memcpy ( V_110 -> V_115 . V_89 , V_90 , V_91 ) ;
V_110 -> V_115 . V_136 = V_137 ;
V_110 -> V_115 . V_138 = V_139 ;
V_110 -> V_115 . V_140 = 1 ;
V_110 -> V_115 . V_141 = V_142 ;
V_110 -> V_115 . V_130 = V_131 ;
V_110 -> V_115 . V_133 = F_76 () ;
V_110 -> V_115 . V_93 = sizeof( * V_110 ) + V_86 -> V_47 ;
V_110 -> V_115 . V_116 = V_117 ;
V_110 -> V_115 . V_143 = V_144 ;
V_110 -> V_115 . V_55 = F_77 () ;
V_110 -> V_115 . V_52 = V_145 ;
V_110 -> V_122 . V_146 = sizeof( * V_110 ) ;
V_110 -> V_122 . V_147 = V_86 -> V_47 ;
V_110 -> V_122 . V_136 = V_148 ;
V_110 -> V_122 . V_130 = 0 ;
V_110 -> V_122 . V_52 = V_149 ;
switch ( V_86 -> type ) {
case V_125 :
if ( V_86 -> V_120 )
V_110 -> V_122 . V_123 = V_124 ;
else
V_110 -> V_122 . V_123 = V_126 ;
break;
case V_128 :
V_110 -> V_122 . V_123 = V_127 ;
break;
default:
return - V_10 ;
}
V_110 -> V_122 . V_150 = V_142 ;
V_135 = F_61 ( & V_110 -> V_115 ) ;
V_86 -> V_61 = V_110 -> V_115 . V_55 ;
return V_135 ;
}
static int F_78 ( struct V_108 * V_86 )
{
return F_66 ( V_86 -> V_61 ) ;
}
static int T_4 F_79 ( void )
{
int V_21 = 0 ;
T_5 V_151 ;
struct V_15 V_16 ;
struct V_152 V_153 ;
struct V_154 * V_155 ;
char * V_118 ;
if ( V_156 )
goto V_157;
if ( V_53 ) {
F_80 (
L_8 ) ;
goto V_157;
}
V_151 = F_81 ( V_158 , 0 ,
(struct V_159 * * ) & V_40 ) ;
if ( V_151 == V_160 )
goto V_157;
else if ( F_82 ( V_151 ) ) {
const char * V_161 = F_83 ( V_151 ) ;
F_84 ( L_9 , V_161 ) ;
V_21 = - V_10 ;
goto V_157;
}
V_21 = F_68 ( V_40 ) ;
if ( V_21 ) {
F_84 ( V_162 L_10 ) ;
goto V_157;
}
F_85 ( & V_153 ) ;
F_27 ( & V_16 ) ;
V_21 = F_86 ( & V_16 , & V_153 ) ;
if ( V_21 )
goto V_163;
V_21 = F_87 ( & V_153 , L_11 ) ;
if ( V_21 )
goto V_163;
V_21 = F_88 ( & V_16 ) ;
if ( V_21 )
goto V_164;
V_21 = F_31 ( & V_42 ) ;
if ( V_21 ) {
if ( V_21 == - V_4 )
F_80 (
L_12
L_13 ) ;
else
F_84 ( L_14 ) ;
goto V_165;
}
V_155 = F_89 ( V_42 . V_45 , V_42 . V_47 , L_11 ) ;
if ( ! V_155 ) {
F_84 ( L_15 ,
( unsigned long long ) V_42 . V_45 ,
( unsigned long long ) V_42 . V_45 + V_42 . V_47 - 1 ) ;
V_21 = - V_29 ;
goto V_165;
}
V_21 = - V_38 ;
V_42 . V_94 = F_90 ( V_42 . V_45 ,
V_42 . V_47 ) ;
if ( ! V_42 . V_94 )
goto V_166;
F_80 (
L_16 ) ;
V_118 = F_72 ( V_42 . V_47 , V_72 ) ;
F_91 ( & V_112 . V_167 ) ;
if ( V_118 ) {
V_112 . V_118 = V_118 + sizeof( struct V_109 ) ;
V_112 . V_113 = V_42 . V_47 -
sizeof( struct V_109 ) ;
V_21 = F_92 ( & V_112 ) ;
if ( V_21 ) {
if ( V_21 != - V_168 )
F_80 (
L_17 ) ;
V_112 . V_118 = NULL ;
V_112 . V_113 = 0 ;
F_74 ( V_118 ) ;
}
} else
F_84 (
L_18 ,
V_42 . V_47 ) ;
F_93 ( & V_153 ) ;
return 0 ;
V_166:
F_94 ( V_42 . V_45 , V_42 . V_47 ) ;
V_165:
F_95 ( & V_16 ) ;
V_164:
F_96 ( & V_153 ) ;
V_163:
F_93 ( & V_153 ) ;
V_157:
V_53 = 1 ;
return V_21 ;
}
