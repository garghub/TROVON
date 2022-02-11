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
F_3 (FW_WARN ERST_PFX
L_1 ) ;
return 1 ;
}
* V_11 -= V_12 ;
F_4 ( V_12 ) ;
F_5 () ;
return 0 ;
}
static int F_6 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
return F_7 ( V_17 , & V_15 -> V_18 ) ;
}
static int F_8 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
return F_7 ( V_17 , & V_15 -> V_19 ) ;
}
static int F_9 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
return F_10 ( V_17 , V_15 -> V_18 ) ;
}
static int F_11 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
V_15 -> V_18 += V_15 -> V_19 ;
return 0 ;
}
static int F_12 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
V_15 -> V_18 -= V_15 -> V_19 ;
return 0 ;
}
static int F_13 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
int V_20 ;
T_1 V_21 ;
V_20 = F_7 ( V_17 , & V_21 ) ;
if ( V_20 )
return V_20 ;
V_21 += V_15 -> V_22 ;
V_20 = F_10 ( V_17 , V_21 ) ;
return V_20 ;
}
static int F_14 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
int V_20 ;
T_1 V_21 ;
V_20 = F_7 ( V_17 , & V_21 ) ;
if ( V_20 )
return V_20 ;
V_21 -= V_15 -> V_22 ;
V_20 = F_10 ( V_17 , V_21 ) ;
return V_20 ;
}
static int F_15 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
T_1 V_23 ;
if ( V_15 -> V_22 > V_24 ) {
if ( ! F_16 () )
F_3 (FW_WARN ERST_PFX
L_2 ,
ctx->value) ;
V_23 = V_24 ;
} else
V_23 = V_15 -> V_22 ;
F_17 ( V_23 ) ;
return 0 ;
}
static int F_18 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
int V_20 ;
T_1 V_21 ;
T_1 V_25 = V_26 ;
T_1 V_23 ;
if ( V_15 -> V_18 > V_24 ) {
if ( ! F_16 () )
F_3 (FW_WARN ERST_PFX
L_3 ,
ctx->var1) ;
V_23 = V_24 ;
} else
V_23 = V_15 -> V_18 ;
for (; ; ) {
V_20 = F_7 ( V_17 , & V_21 ) ;
if ( V_20 )
return V_20 ;
if ( V_21 != V_15 -> V_22 )
break;
if ( F_2 ( & V_25 , V_23 * V_27 ) )
return - V_28 ;
}
return 0 ;
}
static int F_19 (
struct V_14 * V_15 ,
struct V_16 * V_17 )
{
int V_20 ;
T_1 V_21 ;
V_20 = F_7 ( V_17 , & V_21 ) ;
if ( V_20 )
return V_20 ;
if ( V_21 == V_15 -> V_22 ) {
V_15 -> V_29 += 2 ;
return V_30 ;
}
return 0 ;
}
static int F_20 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
V_15 -> V_29 = V_15 -> V_22 ;
return V_30 ;
}
static int F_21 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
return F_7 ( V_17 , & V_15 -> V_31 ) ;
}
static int F_22 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
return F_7 ( V_17 , & V_15 -> V_32 ) ;
}
static int F_23 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
int V_20 ;
T_1 V_33 ;
void * V_34 , * V_35 ;
if ( F_24 () ) {
F_3 ( V_36
L_4 ) ;
return - V_37 ;
}
V_20 = F_7 ( V_17 , & V_33 ) ;
if ( V_20 )
return V_20 ;
V_34 = F_25 ( V_15 -> V_31 + V_33 , V_15 -> V_19 ) ;
if ( ! V_34 )
return - V_38 ;
V_35 = F_25 ( V_15 -> V_32 + V_33 , V_15 -> V_19 ) ;
if ( ! V_35 )
return - V_38 ;
memmove ( V_35 , V_34 , V_15 -> V_19 ) ;
F_26 ( V_34 ) ;
F_26 ( V_35 ) ;
return 0 ;
}
static inline void F_27 ( struct V_14 * V_15 )
{
F_28 ( V_15 , V_39 , F_29 ( V_39 ) ,
F_30 ( V_40 ) , V_40 -> V_41 ) ;
}
static int F_31 ( struct V_42 * V_43 )
{
struct V_14 V_15 ;
int V_20 ;
F_27 ( & V_15 ) ;
V_20 = F_32 ( & V_15 , V_44 ) ;
if ( V_20 )
return V_20 ;
V_43 -> V_45 = F_33 ( & V_15 ) ;
V_20 = F_32 ( & V_15 , V_46 ) ;
if ( V_20 )
return V_20 ;
V_43 -> V_47 = F_33 ( & V_15 ) ;
V_20 = F_32 ( & V_15 , V_48 ) ;
if ( V_20 )
return V_20 ;
V_43 -> V_49 = F_33 ( & V_15 ) ;
return 0 ;
}
static T_2 F_34 ( void )
{
struct V_14 V_15 ;
int V_20 ;
F_27 ( & V_15 ) ;
V_20 = F_32 ( & V_15 , V_50 ) ;
if ( V_20 )
return V_20 ;
return F_33 ( & V_15 ) ;
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
struct V_14 V_15 ;
int V_20 ;
F_27 ( & V_15 ) ;
V_20 = F_32 ( & V_15 , V_56 ) ;
if ( V_20 )
return V_20 ;
* V_55 = F_33 ( & V_15 ) ;
return 0 ;
}
int F_39 ( int * V_57 )
{
int V_20 ;
if ( V_53 )
return - V_4 ;
V_20 = F_40 ( & V_58 . V_59 ) ;
if ( V_20 )
return V_20 ;
V_58 . V_60 ++ ;
F_41 ( & V_58 . V_59 ) ;
* V_57 = 0 ;
return 0 ;
}
static int F_42 ( void )
{
T_1 V_61 , V_62 , V_63 ;
int V_64 , V_20 ;
T_1 * V_41 ;
unsigned long V_52 ;
V_61 = V_62 = V_63 = V_65 ;
V_66:
F_36 ( & V_54 , V_52 ) ;
V_20 = F_38 ( & V_61 ) ;
F_37 ( & V_54 , V_52 ) ;
if ( V_20 == - V_9 )
return 0 ;
if ( V_20 )
return V_20 ;
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
F_3 (FW_WARN ERST_PFX
L_5 ) ;
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
int V_20 = 0 ;
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
V_20 = F_42 () ;
if ( V_20 < 0 )
goto V_75;
if ( V_20 == 1 ) {
* V_55 = V_58 . V_41 [ * V_57 ] ;
( * V_57 ) ++ ;
V_20 = 0 ;
} else {
* V_57 = - 1 ;
* V_55 = V_65 ;
}
V_75:
F_41 ( & V_58 . V_59 ) ;
return V_20 ;
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
memcpy ( & V_41 [ V_76 ] , & V_41 [ V_64 ] , sizeof( V_41 [ V_64 ] ) ) ;
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
static int F_54 ( T_1 V_33 )
{
struct V_14 V_15 ;
T_1 V_25 = V_26 ;
T_1 V_21 ;
int V_20 ;
F_27 ( & V_15 ) ;
V_20 = F_55 ( & V_15 , V_77 ) ;
if ( V_20 )
return V_20 ;
F_56 ( & V_15 , V_33 ) ;
V_20 = F_32 ( & V_15 , V_78 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_32 ( & V_15 , V_79 ) ;
if ( V_20 )
return V_20 ;
for (; ; ) {
V_20 = F_32 ( & V_15 , V_80 ) ;
if ( V_20 )
return V_20 ;
V_21 = F_33 ( & V_15 ) ;
if ( ! V_21 )
break;
if ( F_2 ( & V_25 , V_81 ) )
return - V_28 ;
}
V_20 = F_32 ( & V_15 , V_82 ) ;
if ( V_20 )
return V_20 ;
V_21 = F_33 ( & V_15 ) ;
V_20 = F_55 ( & V_15 , V_83 ) ;
if ( V_20 )
return V_20 ;
return F_1 ( V_21 ) ;
}
static int F_57 ( T_1 V_55 , T_1 V_33 )
{
struct V_14 V_15 ;
T_1 V_25 = V_26 ;
T_1 V_21 ;
int V_20 ;
F_27 ( & V_15 ) ;
V_20 = F_55 ( & V_15 , V_84 ) ;
if ( V_20 )
return V_20 ;
F_56 ( & V_15 , V_33 ) ;
V_20 = F_32 ( & V_15 , V_78 ) ;
if ( V_20 )
return V_20 ;
F_56 ( & V_15 , V_55 ) ;
V_20 = F_32 ( & V_15 , V_85 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_32 ( & V_15 , V_79 ) ;
if ( V_20 )
return V_20 ;
for (; ; ) {
V_20 = F_32 ( & V_15 , V_80 ) ;
if ( V_20 )
return V_20 ;
V_21 = F_33 ( & V_15 ) ;
if ( ! V_21 )
break;
if ( F_2 ( & V_25 , V_81 ) )
return - V_28 ;
} ;
V_20 = F_32 ( & V_15 , V_82 ) ;
if ( V_20 )
return V_20 ;
V_21 = F_33 ( & V_15 ) ;
V_20 = F_55 ( & V_15 , V_83 ) ;
if ( V_20 )
return V_20 ;
return F_1 ( V_21 ) ;
}
static int F_58 ( T_1 V_55 )
{
struct V_14 V_15 ;
T_1 V_25 = V_26 ;
T_1 V_21 ;
int V_20 ;
F_27 ( & V_15 ) ;
V_20 = F_55 ( & V_15 , V_86 ) ;
if ( V_20 )
return V_20 ;
F_56 ( & V_15 , V_55 ) ;
V_20 = F_32 ( & V_15 , V_85 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_32 ( & V_15 , V_79 ) ;
if ( V_20 )
return V_20 ;
for (; ; ) {
V_20 = F_32 ( & V_15 , V_80 ) ;
if ( V_20 )
return V_20 ;
V_21 = F_33 ( & V_15 ) ;
if ( ! V_21 )
break;
if ( F_2 ( & V_25 , V_81 ) )
return - V_28 ;
}
V_20 = F_32 ( & V_15 , V_82 ) ;
if ( V_20 )
return V_20 ;
V_21 = F_33 ( & V_15 ) ;
V_20 = F_55 ( & V_15 , V_83 ) ;
if ( V_20 )
return V_20 ;
return F_1 ( V_21 ) ;
}
static void F_59 ( void )
{
if ( F_44 () )
F_3 ( V_36
L_6 ) ;
}
static int F_60 ( const struct V_87 * V_88 )
{
return - V_89 ;
}
static int F_61 ( T_1 V_55 , T_1 * V_33 )
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
int V_20 ;
unsigned long V_52 ;
struct V_87 * V_90 ;
if ( V_53 )
return - V_4 ;
if ( memcmp ( V_88 -> V_91 , V_92 , V_93 ) )
return - V_10 ;
if ( V_42 . V_49 & V_94 ) {
if ( ! F_64 ( & V_54 , V_52 ) )
return - V_37 ;
V_20 = F_60 ( V_88 ) ;
F_37 ( & V_54 , V_52 ) ;
return V_20 ;
}
if ( V_88 -> V_95 > V_42 . V_47 )
return - V_10 ;
if ( ! F_64 ( & V_54 , V_52 ) )
return - V_37 ;
memcpy ( V_42 . V_96 , V_88 , V_88 -> V_95 ) ;
V_90 = V_42 . V_96 ;
memcpy ( & V_90 -> V_97 , L_7 , 2 ) ;
V_20 = F_54 ( 0 ) ;
F_37 ( & V_54 , V_52 ) ;
return V_20 ;
}
static int F_65 ( T_1 V_55 , T_1 * V_33 )
{
int V_20 ;
if ( V_42 . V_49 & V_94 )
return F_61 (
V_55 , V_33 ) ;
V_20 = F_57 ( V_55 , 0 ) ;
if ( V_20 )
return V_20 ;
* V_33 = 0 ;
return 0 ;
}
static T_2 F_66 ( T_1 V_55 , struct V_87 * V_88 ,
T_3 V_98 )
{
int V_20 ;
T_1 V_33 , V_67 = 0 ;
struct V_87 * V_99 ;
V_20 = F_65 ( V_55 , & V_33 ) ;
if ( V_20 )
return V_20 ;
V_99 = V_42 . V_96 + V_33 ;
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
int V_20 , V_64 ;
unsigned long V_52 ;
T_1 * V_41 ;
if ( V_53 )
return - V_4 ;
V_20 = F_40 ( & V_58 . V_59 ) ;
if ( V_20 )
return V_20 ;
F_36 ( & V_54 , V_52 ) ;
if ( V_42 . V_49 & V_94 )
V_20 = F_62 ( V_55 ) ;
else
V_20 = F_58 ( V_55 ) ;
F_37 ( & V_54 , V_52 ) ;
if ( V_20 )
goto V_100;
V_41 = V_58 . V_41 ;
for ( V_64 = 0 ; V_64 < V_58 . V_67 ; V_64 ++ ) {
if ( V_41 [ V_64 ] == V_55 )
V_41 [ V_64 ] = V_65 ;
}
F_52 () ;
V_100:
F_41 ( & V_58 . V_59 ) ;
return V_20 ;
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
&& ( V_40 -> V_103 != sizeof( struct V_105 ) ) )
return - V_10 ;
if ( V_40 -> V_104 . V_106 < sizeof( struct V_102 ) )
return - V_10 ;
if ( V_40 -> V_41 !=
( V_40 -> V_104 . V_106 - sizeof( struct V_102 ) ) /
sizeof( struct V_107 ) )
return - V_10 ;
return 0 ;
}
static int F_71 ( struct V_108 * V_109 )
{
int V_20 ;
if ( V_53 )
return - V_4 ;
V_20 = F_39 ( & V_110 ) ;
return V_20 ;
}
static int F_72 ( struct V_108 * V_109 )
{
F_53 () ;
return 0 ;
}
static T_2 F_73 ( T_1 * V_61 , enum V_111 * type ,
struct V_112 * time , char * * V_113 ,
struct V_108 * V_109 )
{
int V_20 ;
T_2 V_67 = 0 ;
T_1 V_55 ;
struct V_114 * V_115 ;
T_3 V_116 = sizeof( * V_115 ) + V_117 . V_118 ;
if ( V_53 )
return - V_4 ;
V_115 = F_45 ( V_116 , V_74 ) ;
if ( ! V_115 ) {
V_20 = - V_38 ;
goto V_100;
}
V_119:
V_20 = F_49 ( & V_110 , & V_55 ) ;
if ( V_20 )
goto V_100;
if ( V_55 == V_65 ) {
V_20 = - V_10 ;
goto V_100;
}
V_67 = F_67 ( V_55 , & V_115 -> V_120 , V_116 ) ;
if ( V_67 == - V_9 )
goto V_119;
else if ( V_67 < sizeof( * V_115 ) ) {
V_20 = - V_28 ;
goto V_100;
}
if ( F_74 ( V_115 -> V_120 . V_121 , V_122 ) != 0 )
goto V_119;
* V_113 = F_45 ( V_67 , V_74 ) ;
if ( * V_113 == NULL ) {
V_20 = - V_38 ;
goto V_100;
}
memcpy ( * V_113 , V_115 -> V_123 , V_67 - sizeof( * V_115 ) ) ;
* V_61 = V_55 ;
if ( F_74 ( V_115 -> V_124 . V_125 ,
V_126 ) == 0 )
* type = V_127 ;
else if ( F_74 ( V_115 -> V_124 . V_125 ,
V_128 ) == 0 )
* type = V_129 ;
else
* type = V_130 ;
if ( V_115 -> V_120 . V_131 & V_132 )
time -> V_133 = V_115 -> V_120 . V_134 ;
else
time -> V_133 = 0 ;
time -> V_135 = 0 ;
V_100:
F_47 ( V_115 ) ;
return ( V_20 < 0 ) ? V_20 : ( V_67 - sizeof( * V_115 ) ) ;
}
static int F_75 ( enum V_111 type , T_1 * V_61 , unsigned int V_136 ,
T_3 V_47 , struct V_108 * V_109 )
{
struct V_114 * V_115 = (struct V_114 * )
( V_117 . V_113 - sizeof( * V_115 ) ) ;
int V_137 ;
memset ( V_115 , 0 , sizeof( * V_115 ) ) ;
memcpy ( V_115 -> V_120 . V_91 , V_92 , V_93 ) ;
V_115 -> V_120 . V_138 = V_139 ;
V_115 -> V_120 . V_140 = V_141 ;
V_115 -> V_120 . V_142 = 1 ;
V_115 -> V_120 . V_143 = V_144 ;
V_115 -> V_120 . V_131 = V_132 ;
V_115 -> V_120 . V_134 = F_76 () ;
V_115 -> V_120 . V_95 = sizeof( * V_115 ) + V_47 ;
V_115 -> V_120 . V_121 = V_122 ;
V_115 -> V_120 . V_145 = V_146 ;
V_115 -> V_120 . V_55 = F_77 () ;
V_115 -> V_120 . V_52 = V_147 ;
V_115 -> V_124 . V_148 = sizeof( * V_115 ) ;
V_115 -> V_124 . V_149 = V_47 ;
V_115 -> V_124 . V_138 = V_150 ;
V_115 -> V_124 . V_131 = 0 ;
V_115 -> V_124 . V_52 = V_151 ;
switch ( type ) {
case V_127 :
V_115 -> V_124 . V_125 = V_126 ;
break;
case V_129 :
V_115 -> V_124 . V_125 = V_128 ;
break;
default:
return - V_10 ;
}
V_115 -> V_124 . V_152 = V_144 ;
V_137 = F_63 ( & V_115 -> V_120 ) ;
* V_61 = V_115 -> V_120 . V_55 ;
return V_137 ;
}
static int F_78 ( enum V_111 type , T_1 V_61 ,
struct V_108 * V_109 )
{
return F_68 ( V_61 ) ;
}
static int T_4 F_79 ( void )
{
int V_20 = 0 ;
T_5 V_153 ;
struct V_14 V_15 ;
struct V_154 V_155 ;
struct V_156 * V_157 ;
char * V_113 ;
if ( V_158 )
goto V_159;
if ( V_53 ) {
F_80 ( V_36
L_8 ) ;
goto V_159;
}
V_153 = F_81 ( V_160 , 0 ,
(struct V_161 * * ) & V_40 ) ;
if ( V_153 == V_162 ) {
F_80 ( V_36 L_9 ) ;
goto V_159;
} else if ( F_82 ( V_153 ) ) {
const char * V_163 = F_83 ( V_153 ) ;
F_84 ( V_36 L_10 , V_163 ) ;
V_20 = - V_10 ;
goto V_159;
}
V_20 = F_70 ( V_40 ) ;
if ( V_20 ) {
F_84 (FW_BUG ERST_PFX L_11 ) ;
goto V_159;
}
F_85 ( & V_155 ) ;
F_27 ( & V_15 ) ;
V_20 = F_86 ( & V_15 , & V_155 ) ;
if ( V_20 )
goto V_164;
V_20 = F_87 ( & V_155 , L_12 ) ;
if ( V_20 )
goto V_164;
V_20 = F_88 ( & V_15 ) ;
if ( V_20 )
goto V_165;
V_20 = F_31 ( & V_42 ) ;
if ( V_20 ) {
if ( V_20 == - V_4 )
F_80 ( V_36
L_13
L_14 ) ;
else
F_84 ( V_36
L_15 ) ;
goto V_166;
}
V_157 = F_89 ( V_42 . V_45 , V_42 . V_47 , L_12 ) ;
if ( ! V_157 ) {
F_84 ( V_36
L_16 ,
( unsigned long long ) V_42 . V_45 ,
( unsigned long long ) V_42 . V_45 + V_42 . V_47 ) ;
V_20 = - V_28 ;
goto V_166;
}
V_20 = - V_38 ;
V_42 . V_96 = F_90 ( V_42 . V_45 ,
V_42 . V_47 ) ;
if ( ! V_42 . V_96 )
goto V_167;
V_113 = F_45 ( V_42 . V_47 , V_74 ) ;
F_91 ( & V_117 . V_168 ) ;
if ( V_113 ) {
V_117 . V_113 = V_113 + sizeof( struct V_114 ) ;
V_117 . V_118 = V_42 . V_47 -
sizeof( struct V_114 ) ;
if ( F_92 ( & V_117 ) ) {
F_80 ( V_36 L_17 ) ;
F_47 ( V_113 ) ;
}
}
F_80 ( V_36
L_18 ) ;
return 0 ;
V_167:
F_93 ( V_42 . V_45 , V_42 . V_47 ) ;
V_166:
F_94 ( & V_15 ) ;
V_165:
F_95 ( & V_155 ) ;
V_164:
F_96 ( & V_155 ) ;
V_159:
V_53 = 1 ;
return V_20 ;
}
