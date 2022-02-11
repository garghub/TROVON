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
V_20 = F_32 ( & V_15 , V_77 ) ;
if ( V_20 )
return V_20 ;
F_55 ( & V_15 , V_33 ) ;
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
V_20 = F_32 ( & V_15 , V_83 ) ;
if ( V_20 )
return V_20 ;
return F_1 ( V_21 ) ;
}
static int F_56 ( T_1 V_55 , T_1 V_33 )
{
struct V_14 V_15 ;
T_1 V_25 = V_26 ;
T_1 V_21 ;
int V_20 ;
F_27 ( & V_15 ) ;
V_20 = F_32 ( & V_15 , V_84 ) ;
if ( V_20 )
return V_20 ;
F_55 ( & V_15 , V_33 ) ;
V_20 = F_32 ( & V_15 , V_78 ) ;
if ( V_20 )
return V_20 ;
F_55 ( & V_15 , V_55 ) ;
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
V_20 = F_32 ( & V_15 , V_83 ) ;
if ( V_20 )
return V_20 ;
return F_1 ( V_21 ) ;
}
static int F_57 ( T_1 V_55 )
{
struct V_14 V_15 ;
T_1 V_25 = V_26 ;
T_1 V_21 ;
int V_20 ;
F_27 ( & V_15 ) ;
V_20 = F_32 ( & V_15 , V_86 ) ;
if ( V_20 )
return V_20 ;
F_55 ( & V_15 , V_55 ) ;
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
V_20 = F_32 ( & V_15 , V_83 ) ;
if ( V_20 )
return V_20 ;
return F_1 ( V_21 ) ;
}
static void F_58 ( void )
{
if ( F_44 () )
F_3 ( V_36
L_6 ) ;
}
static int F_59 ( const struct V_87 * V_88 )
{
return - V_89 ;
}
static int F_60 ( T_1 V_55 , T_1 * V_33 )
{
F_58 () ;
return - V_89 ;
}
static int F_61 ( T_1 V_55 )
{
F_58 () ;
return - V_89 ;
}
int F_62 ( const struct V_87 * V_88 )
{
int V_20 ;
unsigned long V_52 ;
struct V_87 * V_90 ;
if ( V_53 )
return - V_4 ;
if ( memcmp ( V_88 -> V_91 , V_92 , V_93 ) )
return - V_10 ;
if ( V_42 . V_49 & V_94 ) {
if ( ! F_63 ( & V_54 , V_52 ) )
return - V_37 ;
V_20 = F_59 ( V_88 ) ;
F_37 ( & V_54 , V_52 ) ;
return V_20 ;
}
if ( V_88 -> V_95 > V_42 . V_47 )
return - V_10 ;
if ( ! F_63 ( & V_54 , V_52 ) )
return - V_37 ;
memcpy ( V_42 . V_96 , V_88 , V_88 -> V_95 ) ;
V_90 = V_42 . V_96 ;
memcpy ( & V_90 -> V_97 , L_7 , 2 ) ;
V_20 = F_54 ( 0 ) ;
F_37 ( & V_54 , V_52 ) ;
return V_20 ;
}
static int F_64 ( T_1 V_55 , T_1 * V_33 )
{
int V_20 ;
if ( V_42 . V_49 & V_94 )
return F_60 (
V_55 , V_33 ) ;
V_20 = F_56 ( V_55 , 0 ) ;
if ( V_20 )
return V_20 ;
* V_33 = 0 ;
return 0 ;
}
static T_2 F_65 ( T_1 V_55 , struct V_87 * V_88 ,
T_3 V_98 )
{
int V_20 ;
T_1 V_33 , V_67 = 0 ;
struct V_87 * V_99 ;
V_20 = F_64 ( V_55 , & V_33 ) ;
if ( V_20 )
return V_20 ;
V_99 = V_42 . V_96 + V_33 ;
V_67 = V_99 -> V_95 ;
if ( V_67 <= V_98 )
memcpy ( V_88 , V_99 , V_67 ) ;
return V_67 ;
}
T_2 F_66 ( T_1 V_55 , struct V_87 * V_88 ,
T_3 V_98 )
{
T_2 V_67 ;
unsigned long V_52 ;
if ( V_53 )
return - V_4 ;
F_36 ( & V_54 , V_52 ) ;
V_67 = F_65 ( V_55 , V_88 , V_98 ) ;
F_37 ( & V_54 , V_52 ) ;
return V_67 ;
}
int F_67 ( T_1 V_55 )
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
V_20 = F_61 ( V_55 ) ;
else
V_20 = F_57 ( V_55 ) ;
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
static int T_4 F_68 ( char * V_101 )
{
V_53 = 1 ;
return 0 ;
}
static int F_69 ( struct V_102 * V_40 )
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
static int F_70 ( struct V_108 * V_109 )
{
int V_20 ;
if ( V_53 )
return - V_4 ;
V_20 = F_39 ( & V_110 ) ;
return V_20 ;
}
static int F_71 ( struct V_108 * V_109 )
{
F_53 () ;
return 0 ;
}
static T_2 F_72 ( T_1 * V_61 , enum V_111 * type ,
struct V_112 * time )
{
int V_20 ;
T_2 V_67 = 0 ;
T_1 V_55 ;
struct V_113 * V_114 = (struct V_113 * )
( V_115 . V_116 - sizeof( * V_114 ) ) ;
if ( V_53 )
return - V_4 ;
V_117:
V_20 = F_49 ( & V_110 , & V_55 ) ;
if ( V_20 )
goto V_100;
if ( V_55 == V_65 ) {
V_20 = - 1 ;
goto V_100;
}
V_67 = F_66 ( V_55 , & V_114 -> V_118 , sizeof( * V_114 ) +
V_115 . V_119 ) ;
if ( V_67 == - V_9 )
goto V_117;
else if ( V_67 < 0 ) {
V_20 = - 1 ;
goto V_100;
}
if ( F_73 ( V_114 -> V_118 . V_120 , V_121 ) != 0 )
goto V_117;
* V_61 = V_55 ;
if ( F_73 ( V_114 -> V_122 . V_123 ,
V_124 ) == 0 )
* type = V_125 ;
else if ( F_73 ( V_114 -> V_122 . V_123 ,
V_126 ) == 0 )
* type = V_127 ;
else
* type = V_128 ;
if ( V_114 -> V_118 . V_129 & V_130 )
time -> V_131 = V_114 -> V_118 . V_132 ;
else
time -> V_131 = 0 ;
time -> V_133 = 0 ;
V_100:
return ( V_20 < 0 ) ? V_20 : ( V_67 - sizeof( * V_114 ) ) ;
}
static T_1 F_74 ( enum V_111 type , T_3 V_47 )
{
struct V_113 * V_114 = (struct V_113 * )
( V_115 . V_116 - sizeof( * V_114 ) ) ;
memset ( V_114 , 0 , sizeof( * V_114 ) ) ;
memcpy ( V_114 -> V_118 . V_91 , V_92 , V_93 ) ;
V_114 -> V_118 . V_134 = V_135 ;
V_114 -> V_118 . V_136 = V_137 ;
V_114 -> V_118 . V_138 = 1 ;
V_114 -> V_118 . V_139 = V_140 ;
V_114 -> V_118 . V_129 = V_130 ;
V_114 -> V_118 . V_132 = F_75 () ;
V_114 -> V_118 . V_95 = sizeof( * V_114 ) + V_47 ;
V_114 -> V_118 . V_120 = V_121 ;
V_114 -> V_118 . V_141 = V_142 ;
V_114 -> V_118 . V_55 = F_76 () ;
V_114 -> V_118 . V_52 = V_143 ;
V_114 -> V_122 . V_144 = sizeof( * V_114 ) ;
V_114 -> V_122 . V_145 = V_47 ;
V_114 -> V_122 . V_134 = V_146 ;
V_114 -> V_122 . V_129 = 0 ;
V_114 -> V_122 . V_52 = V_147 ;
switch ( type ) {
case V_125 :
V_114 -> V_122 . V_123 = V_124 ;
break;
case V_127 :
V_114 -> V_122 . V_123 = V_126 ;
break;
default:
return - V_10 ;
}
V_114 -> V_122 . V_148 = V_140 ;
F_62 ( & V_114 -> V_118 ) ;
return V_114 -> V_118 . V_55 ;
}
static int T_4 F_77 ( void )
{
int V_20 = 0 ;
T_5 V_149 ;
struct V_14 V_15 ;
struct V_150 V_151 ;
struct V_152 * V_153 ;
char * V_116 ;
if ( V_154 )
goto V_155;
if ( V_53 ) {
F_78 ( V_36
L_8 ) ;
goto V_155;
}
V_149 = F_79 ( V_156 , 0 ,
(struct V_157 * * ) & V_40 ) ;
if ( V_149 == V_158 ) {
F_78 ( V_36 L_9 ) ;
goto V_155;
} else if ( F_80 ( V_149 ) ) {
const char * V_159 = F_81 ( V_149 ) ;
F_82 ( V_36 L_10 , V_159 ) ;
V_20 = - V_10 ;
goto V_155;
}
V_20 = F_69 ( V_40 ) ;
if ( V_20 ) {
F_82 (FW_BUG ERST_PFX L_11 ) ;
goto V_155;
}
F_83 ( & V_151 ) ;
F_27 ( & V_15 ) ;
V_20 = F_84 ( & V_15 , & V_151 ) ;
if ( V_20 )
goto V_160;
V_20 = F_85 ( & V_151 , L_12 ) ;
if ( V_20 )
goto V_160;
V_20 = F_86 ( & V_15 ) ;
if ( V_20 )
goto V_161;
V_20 = F_31 ( & V_42 ) ;
if ( V_20 ) {
if ( V_20 == - V_4 )
F_78 ( V_36
L_13
L_14 ) ;
else
F_82 ( V_36
L_15 ) ;
goto V_162;
}
V_153 = F_87 ( V_42 . V_45 , V_42 . V_47 , L_12 ) ;
if ( ! V_153 ) {
F_82 ( V_36
L_16 ,
( unsigned long long ) V_42 . V_45 ,
( unsigned long long ) V_42 . V_45 + V_42 . V_47 ) ;
V_20 = - V_28 ;
goto V_162;
}
V_20 = - V_38 ;
V_42 . V_96 = F_88 ( V_42 . V_45 ,
V_42 . V_47 ) ;
if ( ! V_42 . V_96 )
goto V_163;
V_116 = F_45 ( V_42 . V_47 , V_74 ) ;
F_89 ( & V_115 . V_164 ) ;
if ( V_116 ) {
V_115 . V_116 = V_116 + sizeof( struct V_113 ) ;
V_115 . V_119 = V_42 . V_47 -
sizeof( struct V_113 ) ;
if ( F_90 ( & V_115 ) ) {
F_78 ( V_36 L_17 ) ;
F_47 ( V_116 ) ;
}
}
F_78 ( V_36
L_18 ) ;
return 0 ;
V_163:
F_91 ( V_42 . V_45 , V_42 . V_47 ) ;
V_162:
F_92 ( & V_15 ) ;
V_161:
F_93 ( & V_151 ) ;
V_160:
F_94 ( & V_151 ) ;
V_155:
V_53 = 1 ;
return V_20 ;
}
