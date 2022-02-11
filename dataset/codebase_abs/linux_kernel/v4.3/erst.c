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
int V_68 , V_69 ;
T_1 * V_70 ;
V_68 = V_58 . V_47 * 2 ;
V_68 = F_43 ( V_68 , V_71 ,
V_72 ) ;
if ( V_68 <= V_58 . V_47 ) {
if ( F_44 () )
F_3 ( V_14 L_5 ) ;
return 0 ;
}
V_69 = V_68 * sizeof( V_41 [ 0 ] ) ;
if ( V_69 < V_73 )
V_70 = F_45 ( V_69 , V_74 ) ;
else
V_70 = F_46 ( V_69 ) ;
if ( ! V_70 )
return - V_38 ;
memcpy ( V_70 , V_41 ,
V_58 . V_67 * sizeof( V_41 [ 0 ] ) ) ;
if ( V_58 . V_47 < V_73 )
F_47 ( V_41 ) ;
else
F_48 ( V_41 ) ;
V_58 . V_41 = V_41 = V_70 ;
V_58 . V_47 = V_68 ;
}
V_41 [ V_64 ] = V_61 ;
V_58 . V_67 ++ ;
return 1 ;
}
int F_49 ( int * V_57 , T_1 * V_55 )
{
int V_21 = 0 ;
T_1 * V_41 ;
if ( V_53 )
return - V_4 ;
F_50 ( ! V_58 . V_60 ) ;
F_50 ( * V_57 < 0 || * V_57 > V_58 . V_67 ) ;
F_51 ( & V_58 . V_59 ) ;
V_41 = V_58 . V_41 ;
for (; * V_57 < V_58 . V_67 ; ( * V_57 ) ++ )
if ( V_41 [ * V_57 ] != V_65 )
break;
if ( * V_57 < V_58 . V_67 ) {
* V_55 = V_41 [ * V_57 ] ;
( * V_57 ) ++ ;
goto V_75;
}
V_21 = F_42 () ;
if ( V_21 < 0 )
goto V_75;
if ( V_21 == 1 ) {
* V_55 = V_58 . V_41 [ * V_57 ] ;
( * V_57 ) ++ ;
V_21 = 0 ;
} else {
* V_57 = - 1 ;
* V_55 = V_65 ;
}
V_75:
F_41 ( & V_58 . V_59 ) ;
return V_21 ;
}
static void F_52 ( void )
{
int V_64 , V_76 = 0 ;
T_1 * V_41 ;
if ( V_58 . V_60 )
return;
V_41 = V_58 . V_41 ;
for ( V_64 = 0 ; V_64 < V_58 . V_67 ; V_64 ++ ) {
if ( V_41 [ V_64 ] == V_65 )
continue;
if ( V_76 != V_64 )
V_41 [ V_76 ] = V_41 [ V_64 ] ;
V_76 ++ ;
}
V_58 . V_67 = V_76 ;
}
void F_53 ( void )
{
F_50 ( V_53 ) ;
F_51 ( & V_58 . V_59 ) ;
V_58 . V_60 -- ;
F_50 ( V_58 . V_60 < 0 ) ;
F_52 () ;
F_41 ( & V_58 . V_59 ) ;
}
static int F_54 ( T_1 V_34 )
{
struct V_15 V_16 ;
T_1 V_26 = V_27 ;
T_1 V_22 ;
int V_21 ;
F_27 ( & V_16 ) ;
V_21 = F_55 ( & V_16 , V_77 ) ;
if ( V_21 )
return V_21 ;
F_56 ( & V_16 , V_34 ) ;
V_21 = F_32 ( & V_16 , V_78 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_32 ( & V_16 , V_79 ) ;
if ( V_21 )
return V_21 ;
for (; ; ) {
V_21 = F_32 ( & V_16 , V_80 ) ;
if ( V_21 )
return V_21 ;
V_22 = F_33 ( & V_16 ) ;
if ( ! V_22 )
break;
if ( F_2 ( & V_26 , V_81 ) )
return - V_29 ;
}
V_21 = F_32 ( & V_16 , V_82 ) ;
if ( V_21 )
return V_21 ;
V_22 = F_33 ( & V_16 ) ;
V_21 = F_55 ( & V_16 , V_83 ) ;
if ( V_21 )
return V_21 ;
return F_1 ( V_22 ) ;
}
static int F_57 ( T_1 V_55 , T_1 V_34 )
{
struct V_15 V_16 ;
T_1 V_26 = V_27 ;
T_1 V_22 ;
int V_21 ;
F_27 ( & V_16 ) ;
V_21 = F_55 ( & V_16 , V_84 ) ;
if ( V_21 )
return V_21 ;
F_56 ( & V_16 , V_34 ) ;
V_21 = F_32 ( & V_16 , V_78 ) ;
if ( V_21 )
return V_21 ;
F_56 ( & V_16 , V_55 ) ;
V_21 = F_32 ( & V_16 , V_85 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_32 ( & V_16 , V_79 ) ;
if ( V_21 )
return V_21 ;
for (; ; ) {
V_21 = F_32 ( & V_16 , V_80 ) ;
if ( V_21 )
return V_21 ;
V_22 = F_33 ( & V_16 ) ;
if ( ! V_22 )
break;
if ( F_2 ( & V_26 , V_81 ) )
return - V_29 ;
} ;
V_21 = F_32 ( & V_16 , V_82 ) ;
if ( V_21 )
return V_21 ;
V_22 = F_33 ( & V_16 ) ;
V_21 = F_55 ( & V_16 , V_83 ) ;
if ( V_21 )
return V_21 ;
return F_1 ( V_22 ) ;
}
static int F_58 ( T_1 V_55 )
{
struct V_15 V_16 ;
T_1 V_26 = V_27 ;
T_1 V_22 ;
int V_21 ;
F_27 ( & V_16 ) ;
V_21 = F_55 ( & V_16 , V_86 ) ;
if ( V_21 )
return V_21 ;
F_56 ( & V_16 , V_55 ) ;
V_21 = F_32 ( & V_16 , V_85 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_32 ( & V_16 , V_79 ) ;
if ( V_21 )
return V_21 ;
for (; ; ) {
V_21 = F_32 ( & V_16 , V_80 ) ;
if ( V_21 )
return V_21 ;
V_22 = F_33 ( & V_16 ) ;
if ( ! V_22 )
break;
if ( F_2 ( & V_26 , V_81 ) )
return - V_29 ;
}
V_21 = F_32 ( & V_16 , V_82 ) ;
if ( V_21 )
return V_21 ;
V_22 = F_33 ( & V_16 ) ;
V_21 = F_55 ( & V_16 , V_83 ) ;
if ( V_21 )
return V_21 ;
return F_1 ( V_22 ) ;
}
static void F_59 ( void )
{
if ( F_44 () )
F_3 ( L_6 ) ;
}
static int F_60 ( const struct V_87 * V_88 )
{
return - V_89 ;
}
static int F_61 ( T_1 V_55 , T_1 * V_34 )
{
F_59 () ;
return - V_89 ;
}
static int F_62 ( T_1 V_55 )
{
F_59 () ;
return - V_89 ;
}
int F_63 ( const struct V_87 * V_88 )
{
int V_21 ;
unsigned long V_52 ;
struct V_87 * V_90 ;
if ( V_53 )
return - V_4 ;
if ( memcmp ( V_88 -> V_91 , V_92 , V_93 ) )
return - V_10 ;
if ( V_42 . V_49 & V_94 ) {
if ( ! F_64 ( & V_54 , V_52 ) )
return - V_37 ;
V_21 = F_60 ( V_88 ) ;
F_37 ( & V_54 , V_52 ) ;
return V_21 ;
}
if ( V_88 -> V_95 > V_42 . V_47 )
return - V_10 ;
if ( ! F_64 ( & V_54 , V_52 ) )
return - V_37 ;
memcpy ( V_42 . V_96 , V_88 , V_88 -> V_95 ) ;
V_90 = V_42 . V_96 ;
memcpy ( & V_90 -> V_97 , L_7 , 2 ) ;
V_21 = F_54 ( 0 ) ;
F_37 ( & V_54 , V_52 ) ;
return V_21 ;
}
static int F_65 ( T_1 V_55 , T_1 * V_34 )
{
int V_21 ;
if ( V_42 . V_49 & V_94 )
return F_61 (
V_55 , V_34 ) ;
V_21 = F_57 ( V_55 , 0 ) ;
if ( V_21 )
return V_21 ;
* V_34 = 0 ;
return 0 ;
}
static T_2 F_66 ( T_1 V_55 , struct V_87 * V_88 ,
T_3 V_98 )
{
int V_21 ;
T_1 V_34 , V_67 = 0 ;
struct V_87 * V_99 ;
V_21 = F_65 ( V_55 , & V_34 ) ;
if ( V_21 )
return V_21 ;
V_99 = V_42 . V_96 + V_34 ;
V_67 = V_99 -> V_95 ;
if ( V_67 <= V_98 )
memcpy ( V_88 , V_99 , V_67 ) ;
return V_67 ;
}
T_2 F_67 ( T_1 V_55 , struct V_87 * V_88 ,
T_3 V_98 )
{
T_2 V_67 ;
unsigned long V_52 ;
if ( V_53 )
return - V_4 ;
F_36 ( & V_54 , V_52 ) ;
V_67 = F_66 ( V_55 , V_88 , V_98 ) ;
F_37 ( & V_54 , V_52 ) ;
return V_67 ;
}
int F_68 ( T_1 V_55 )
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
if ( V_42 . V_49 & V_94 )
V_21 = F_62 ( V_55 ) ;
else
V_21 = F_58 ( V_55 ) ;
F_37 ( & V_54 , V_52 ) ;
if ( V_21 )
goto V_100;
V_41 = V_58 . V_41 ;
for ( V_64 = 0 ; V_64 < V_58 . V_67 ; V_64 ++ ) {
if ( V_41 [ V_64 ] == V_55 )
V_41 [ V_64 ] = V_65 ;
}
F_52 () ;
V_100:
F_41 ( & V_58 . V_59 ) ;
return V_21 ;
}
static int T_4 F_69 ( char * V_101 )
{
V_53 = 1 ;
return 0 ;
}
static int F_70 ( struct V_102 * V_40 )
{
if ( ( V_40 -> V_103 !=
( sizeof( struct V_102 ) - sizeof( V_40 -> V_104 ) ) )
&& ( V_40 -> V_103 != sizeof( struct V_102 ) ) )
return - V_10 ;
if ( V_40 -> V_104 . V_105 < sizeof( struct V_102 ) )
return - V_10 ;
if ( V_40 -> V_41 !=
( V_40 -> V_104 . V_105 - sizeof( struct V_102 ) ) /
sizeof( struct V_106 ) )
return - V_10 ;
return 0 ;
}
static int F_71 ( struct V_107 * V_108 )
{
int V_21 ;
if ( V_53 )
return - V_4 ;
V_21 = F_39 ( & V_109 ) ;
return V_21 ;
}
static int F_72 ( struct V_107 * V_108 )
{
F_53 () ;
return 0 ;
}
static T_2 F_73 ( T_1 * V_61 , enum V_110 * type , int * V_51 ,
struct V_111 * time , char * * V_112 ,
bool * V_113 , struct V_107 * V_108 )
{
int V_21 ;
T_2 V_67 = 0 ;
T_1 V_55 ;
struct V_114 * V_115 ;
T_3 V_116 = sizeof( * V_115 ) + V_117 . V_118 ;
if ( V_53 )
return - V_4 ;
V_115 = F_45 ( V_116 , V_74 ) ;
if ( ! V_115 ) {
V_21 = - V_38 ;
goto V_100;
}
V_119:
V_21 = F_49 ( & V_109 , & V_55 ) ;
if ( V_21 )
goto V_100;
if ( V_55 == V_65 ) {
V_21 = - V_10 ;
goto V_100;
}
V_67 = F_67 ( V_55 , & V_115 -> V_120 , V_116 ) ;
if ( V_67 == - V_9 )
goto V_119;
else if ( V_67 < sizeof( * V_115 ) ) {
V_21 = - V_29 ;
goto V_100;
}
if ( F_74 ( V_115 -> V_120 . V_121 , V_122 ) != 0 )
goto V_119;
* V_112 = F_45 ( V_67 , V_74 ) ;
if ( * V_112 == NULL ) {
V_21 = - V_38 ;
goto V_100;
}
memcpy ( * V_112 , V_115 -> V_123 , V_67 - sizeof( * V_115 ) ) ;
* V_61 = V_55 ;
* V_113 = false ;
if ( F_74 ( V_115 -> V_124 . V_125 ,
V_126 ) == 0 ) {
* type = V_127 ;
* V_113 = true ;
} else if ( F_74 ( V_115 -> V_124 . V_125 ,
V_128 ) == 0 )
* type = V_127 ;
else if ( F_74 ( V_115 -> V_124 . V_125 ,
V_129 ) == 0 )
* type = V_130 ;
else
* type = V_131 ;
if ( V_115 -> V_120 . V_132 & V_133 )
time -> V_134 = V_115 -> V_120 . V_135 ;
else
time -> V_134 = 0 ;
time -> V_136 = 0 ;
V_100:
F_47 ( V_115 ) ;
return ( V_21 < 0 ) ? V_21 : ( V_67 - sizeof( * V_115 ) ) ;
}
static int F_75 ( enum V_110 type , enum V_137 V_138 ,
T_1 * V_61 , unsigned int V_139 , int V_51 , bool V_113 ,
T_3 V_47 , struct V_107 * V_108 )
{
struct V_114 * V_115 = (struct V_114 * )
( V_117 . V_112 - sizeof( * V_115 ) ) ;
int V_140 ;
memset ( V_115 , 0 , sizeof( * V_115 ) ) ;
memcpy ( V_115 -> V_120 . V_91 , V_92 , V_93 ) ;
V_115 -> V_120 . V_141 = V_142 ;
V_115 -> V_120 . V_143 = V_144 ;
V_115 -> V_120 . V_145 = 1 ;
V_115 -> V_120 . V_146 = V_147 ;
V_115 -> V_120 . V_132 = V_133 ;
V_115 -> V_120 . V_135 = F_76 () ;
V_115 -> V_120 . V_95 = sizeof( * V_115 ) + V_47 ;
V_115 -> V_120 . V_121 = V_122 ;
V_115 -> V_120 . V_148 = V_149 ;
V_115 -> V_120 . V_55 = F_77 () ;
V_115 -> V_120 . V_52 = V_150 ;
V_115 -> V_124 . V_151 = sizeof( * V_115 ) ;
V_115 -> V_124 . V_152 = V_47 ;
V_115 -> V_124 . V_141 = V_153 ;
V_115 -> V_124 . V_132 = 0 ;
V_115 -> V_124 . V_52 = V_154 ;
switch ( type ) {
case V_127 :
if ( V_113 )
V_115 -> V_124 . V_125 = V_126 ;
else
V_115 -> V_124 . V_125 = V_128 ;
break;
case V_130 :
V_115 -> V_124 . V_125 = V_129 ;
break;
default:
return - V_10 ;
}
V_115 -> V_124 . V_155 = V_147 ;
V_140 = F_63 ( & V_115 -> V_120 ) ;
* V_61 = V_115 -> V_120 . V_55 ;
return V_140 ;
}
static int F_78 ( enum V_110 type , T_1 V_61 , int V_51 ,
struct V_111 time , struct V_107 * V_108 )
{
return F_68 ( V_61 ) ;
}
static int T_4 F_79 ( void )
{
int V_21 = 0 ;
T_5 V_156 ;
struct V_15 V_16 ;
struct V_157 V_158 ;
struct V_159 * V_160 ;
char * V_112 ;
if ( V_161 )
goto V_162;
if ( V_53 ) {
F_80 (
L_8 ) ;
goto V_162;
}
V_156 = F_81 ( V_163 , 0 ,
(struct V_164 * * ) & V_40 ) ;
if ( V_156 == V_165 )
goto V_162;
else if ( F_82 ( V_156 ) ) {
const char * V_166 = F_83 ( V_156 ) ;
F_84 ( L_9 , V_166 ) ;
V_21 = - V_10 ;
goto V_162;
}
V_21 = F_70 ( V_40 ) ;
if ( V_21 ) {
F_84 ( V_167 L_10 ) ;
goto V_162;
}
F_85 ( & V_158 ) ;
F_27 ( & V_16 ) ;
V_21 = F_86 ( & V_16 , & V_158 ) ;
if ( V_21 )
goto V_168;
V_21 = F_87 ( & V_158 , L_11 ) ;
if ( V_21 )
goto V_168;
V_21 = F_88 ( & V_16 ) ;
if ( V_21 )
goto V_169;
V_21 = F_31 ( & V_42 ) ;
if ( V_21 ) {
if ( V_21 == - V_4 )
F_80 (
L_12
L_13 ) ;
else
F_84 ( L_14 ) ;
goto V_170;
}
V_160 = F_89 ( V_42 . V_45 , V_42 . V_47 , L_11 ) ;
if ( ! V_160 ) {
F_84 ( L_15 ,
( unsigned long long ) V_42 . V_45 ,
( unsigned long long ) V_42 . V_45 + V_42 . V_47 - 1 ) ;
V_21 = - V_29 ;
goto V_170;
}
V_21 = - V_38 ;
V_42 . V_96 = F_90 ( V_42 . V_45 ,
V_42 . V_47 ) ;
if ( ! V_42 . V_96 )
goto V_171;
F_80 (
L_16 ) ;
V_112 = F_45 ( V_42 . V_47 , V_74 ) ;
F_91 ( & V_117 . V_172 ) ;
if ( V_112 ) {
V_117 . V_112 = V_112 + sizeof( struct V_114 ) ;
V_117 . V_118 = V_42 . V_47 -
sizeof( struct V_114 ) ;
V_21 = F_92 ( & V_117 ) ;
if ( V_21 ) {
if ( V_21 != - V_173 )
F_80 (
L_17 ) ;
V_117 . V_112 = NULL ;
V_117 . V_118 = 0 ;
F_47 ( V_112 ) ;
}
} else
F_84 (
L_18 ,
V_42 . V_47 ) ;
return 0 ;
V_171:
F_93 ( V_42 . V_45 , V_42 . V_47 ) ;
V_170:
F_94 ( & V_16 ) ;
V_169:
F_95 ( & V_158 ) ;
V_168:
F_96 ( & V_158 ) ;
V_162:
V_53 = 1 ;
return V_21 ;
}
