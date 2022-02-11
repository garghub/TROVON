static T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
if ( F_2 ( V_2 ) )
return F_3 ( V_3 ) ;
else
return F_4 ( V_3 ) ;
}
static inline T_1 F_5 ( struct V_1 * V_2 ,
T_2 V_3 )
{
if ( F_2 ( V_2 ) )
return F_6 ( V_3 ) ;
else
return F_7 ( V_3 ) ;
}
static inline T_1 F_8 ( struct V_1 * V_2 ,
T_2 V_3 )
{
if ( F_2 ( V_2 ) )
return F_9 ( V_3 ) ;
else
return F_10 ( V_3 ) ;
}
static inline T_1 F_11 ( struct V_1 * V_2 ,
T_2 V_3 )
{
if ( F_2 ( V_2 ) )
return F_12 ( V_3 ) ;
else
return F_13 ( V_3 ) ;
}
static int F_14 ( T_1 V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ )
if ( V_4 & F_15 ( V_5 ) )
break;
return V_5 ;
}
static inline void F_16 ( struct V_1 * V_2 )
{
if ( F_17 ( V_7 , & V_2 -> V_8 ) )
V_2 -> V_9 -> V_10 = & V_11 ;
}
static void F_18 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
V_2 -> V_12 -> V_13 = & V_14 ;
else if ( F_19 ( V_2 ) )
V_2 -> V_12 -> V_13 = & V_15 ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_16 * V_12 ;
V_12 = F_21 ( sizeof( struct V_16 ) , V_17 ) ;
if ( ! V_12 )
return - V_18 ;
V_2 -> V_12 = V_12 ;
V_12 -> V_2 = V_2 ;
F_18 ( V_2 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_16 * V_12 = V_2 -> V_12 ;
if ( ! V_12 )
return;
F_23 ( V_2 , 0 ) ;
while ( F_17 ( V_19 , & V_2 -> V_8 ) )
F_24 ( 10000 , 11000 ) ;
F_25 ( & V_12 -> V_20 ) ;
if ( V_12 -> V_21 ) {
F_26 ( V_12 -> V_21 ) ;
V_12 -> V_21 = NULL ;
}
F_27 ( V_12 -> V_22 ) ;
V_12 -> V_22 = NULL ;
F_27 ( V_12 -> V_23 ) ;
V_12 -> V_23 = NULL ;
F_27 ( V_12 ) ;
V_2 -> V_12 = NULL ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_29 ( V_2 ) ;
F_30 ( V_2 ) ;
F_23 ( V_2 , 1 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_16 * V_12 = V_2 -> V_12 ;
int V_24 = 0 ;
F_32 ( & V_12 -> V_20 , V_25 ) ;
V_12 -> V_21 = F_33 ( L_1 ) ;
if ( ! V_12 -> V_21 ) {
F_34 ( & V_2 -> V_26 -> V_27 ,
L_2 ) ;
return - 1 ;
}
V_12 -> V_22 = F_21 ( sizeof( struct V_28 ) , V_17 ) ;
if ( ! V_12 -> V_22 ) {
V_24 = - V_18 ;
goto V_29;
}
V_12 -> V_23 = F_21 ( sizeof( struct V_30 ) , V_17 ) ;
if ( ! V_12 -> V_23 ) {
V_24 = - V_18 ;
goto V_31;
}
F_35 ( V_2 ) ;
return 0 ;
V_31:
F_27 ( V_12 -> V_22 ) ;
V_12 -> V_22 = NULL ;
V_29:
F_26 ( V_12 -> V_21 ) ;
V_12 -> V_21 = NULL ;
return V_24 ;
}
static int F_36 ( struct V_1 * V_2 ,
char * V_32 )
{
struct V_33 V_34 ;
T_2 V_35 ;
int V_24 ;
V_24 = F_37 ( & V_34 , V_2 , V_36 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_38 ( V_2 , & V_34 ) ;
if ( V_24 ) {
F_34 ( & V_2 -> V_26 -> V_27 ,
L_3 , V_24 ) ;
} else {
V_35 = V_34 . V_37 . V_38 [ 1 ] ;
if ( V_32 )
memcpy ( V_32 , & V_35 , sizeof( T_2 ) ) ;
}
F_39 ( & V_34 ) ;
return V_24 ;
}
static int F_40 ( struct V_1 * V_2 , T_2 * V_3 )
{
struct V_39 * V_40 = & V_2 -> V_12 -> V_22 -> V_41 ;
T_2 V_35 ;
int V_24 ;
memset ( V_40 , 0 , sizeof( struct V_39 ) ) ;
V_24 = F_41 ( V_2 , ( char * ) V_3 ) ;
if ( V_24 )
return V_24 ;
V_35 = * V_3 ;
if ( F_42 ( V_35 ) )
V_40 -> V_42 = true ;
if ( F_43 ( V_35 ) )
V_40 -> V_43 = true ;
V_40 -> V_44 = F_44 ( V_35 ) ;
V_40 -> V_45 = F_45 ( V_35 ) ;
V_40 -> V_46 = F_46 ( V_35 ) ;
if ( V_40 -> V_44 > V_6 ||
V_40 -> V_45 > V_40 -> V_44 ||
V_40 -> V_46 > V_40 -> V_44 ) {
F_34 ( & V_2 -> V_26 -> V_27 , L_4 ) ;
return - V_47 ;
}
return V_24 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_28 * V_22 = V_2 -> V_12 -> V_22 ;
struct V_39 * V_40 ;
T_2 V_35 ;
int V_24 ;
V_24 = F_40 ( V_2 , & V_35 ) ;
if ( V_24 )
return V_24 ;
V_40 = & V_22 -> V_41 ;
V_40 -> V_48 = V_49 | V_50 ;
if ( V_40 -> V_48 && V_40 -> V_42 && V_40 -> V_43 )
F_48 ( V_7 , & V_2 -> V_8 ) ;
return V_24 ;
}
static int F_49 ( struct V_1 * V_2 ,
char * V_32 , T_1 type )
{
T_3 V_51 = sizeof( struct V_52 ) ;
struct V_52 * V_53 ;
struct V_54 * V_27 = & V_2 -> V_26 -> V_27 ;
T_4 V_55 ;
struct V_56 V_37 ;
struct V_33 V_34 ;
T_5 V_57 ;
void * V_58 ;
int V_24 , V_59 ;
switch ( type ) {
case V_60 :
case V_61 :
case V_62 :
break;
default:
F_34 ( V_27 , L_5 , type ) ;
return - V_47 ;
}
V_58 = F_50 ( & V_2 -> V_26 -> V_27 , V_51 , & V_55 ,
V_63 ) ;
if ( V_58 == NULL )
return - V_18 ;
V_53 = V_58 ;
V_24 = F_37 ( & V_34 , V_2 , V_64 ) ;
if ( V_24 )
goto V_65;
V_57 = V_55 ;
V_34 . V_66 . V_38 [ 1 ] = V_51 | ( type << 16 ) ;
V_34 . V_66 . V_38 [ 2 ] = F_51 ( V_57 ) ;
V_34 . V_66 . V_38 [ 3 ] = F_52 ( V_57 ) ;
V_24 = F_38 ( V_2 , & V_34 ) ;
if ( V_24 ) {
F_34 ( V_27 , L_6 , V_24 ) ;
goto V_67;
}
memset ( & V_37 , 0 , sizeof( struct V_56 ) ) ;
V_37 . V_68 [ 0 ] = F_53 ( V_53 -> V_68 [ 0 ] ) ;
V_37 . V_68 [ 1 ] = F_53 ( V_53 -> V_68 [ 1 ] ) ;
V_37 . V_69 [ 0 ] = F_53 ( V_53 -> V_69 [ 0 ] ) ;
V_37 . V_69 [ 1 ] = F_53 ( V_53 -> V_69 [ 1 ] ) ;
V_37 . V_70 [ 0 ] = F_53 ( V_53 -> V_70 [ 0 ] ) ;
V_37 . V_70 [ 1 ] = F_53 ( V_53 -> V_70 [ 1 ] ) ;
V_37 . V_71 [ 0 ] = F_53 ( V_53 -> V_71 [ 0 ] ) ;
V_37 . V_71 [ 1 ] = F_53 ( V_53 -> V_71 [ 1 ] ) ;
for ( V_59 = 0 ; V_59 < V_72 ; V_59 ++ )
V_37 . V_73 [ V_59 ] = F_53 ( V_53 -> V_73 [ V_59 ] ) ;
if ( V_32 )
memcpy ( V_32 , & V_37 , V_51 ) ;
V_67:
F_39 ( & V_34 ) ;
V_65:
F_54 ( & V_2 -> V_26 -> V_27 , V_51 , V_58 , V_55 ) ;
return V_24 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_30 * V_74 ;
int V_24 ;
V_74 = V_2 -> V_12 -> V_23 ;
if ( ! V_74 )
return 0 ;
V_24 = F_56 ( V_2 , ( char * ) & V_74 -> type [ 0 ] ,
V_60 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_56 ( V_2 , ( char * ) & V_74 -> type [ 1 ] ,
V_61 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_56 ( V_2 , ( char * ) & V_74 -> type [ 2 ] ,
V_62 ) ;
if ( V_24 )
return V_24 ;
V_74 -> V_75 = V_76 ;
F_57 ( V_2 ) ;
return V_24 ;
}
static void V_25 ( struct V_77 * V_78 )
{
struct V_1 * V_2 ;
struct V_16 * V_12 ;
V_12 = F_58 ( V_78 , struct V_16 , V_20 . V_78 ) ;
V_2 = V_12 -> V_2 ;
F_30 ( V_2 ) ;
F_59 ( V_19 , & V_2 -> V_8 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
void * V_79 )
{
struct V_16 * V_12 = V_2 -> V_12 ;
if ( F_61 ( V_19 , & V_2 -> V_8 ) )
return;
F_62 ( V_12 -> V_21 , & V_12 -> V_20 , 0 ) ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = & V_2 -> V_12 -> V_22 -> V_41 ;
T_2 V_35 ;
int V_24 ;
V_24 = F_40 ( V_2 , & V_35 ) ;
if ( V_24 )
return V_24 ;
if ( V_35 & V_80 )
V_40 -> V_48 = V_49 ;
if ( V_35 & V_81 )
V_40 -> V_48 |= V_82 ;
if ( V_40 -> V_48 )
V_40 -> V_48 |= V_50 ;
if ( V_40 -> V_48 && V_40 -> V_42 && V_40 -> V_43 )
F_48 ( V_7 , & V_2 -> V_8 ) ;
return V_24 ;
}
static int F_64 ( struct V_1 * V_2 ,
char * V_32 , T_1 V_83 )
{
struct V_30 V_35 ;
int V_24 , V_59 , V_5 , V_84 , V_85 , V_51 ;
struct V_56 * V_86 ;
struct V_33 V_34 ;
T_2 V_3 ;
char * V_87 ;
V_51 = 0 ;
memset ( & V_35 , 0 , sizeof( struct V_30 ) ) ;
memset ( V_32 , 0 , sizeof( struct V_30 ) ) ;
V_24 = F_37 ( & V_34 , V_2 , V_64 ) ;
if ( V_24 )
return V_24 ;
V_34 . V_66 . V_38 [ 0 ] |= V_88 << 29 ;
V_24 = F_38 ( V_2 , & V_34 ) ;
if ( V_24 ) {
F_34 ( & V_2 -> V_26 -> V_27 ,
L_7 , V_24 ) ;
goto V_67;
}
V_35 . V_75 = V_34 . V_37 . V_38 [ 1 ] ;
V_87 = memcpy ( V_32 , & V_35 , sizeof( T_2 ) ) ;
V_84 = 2 ;
V_87 += sizeof( T_2 ) ;
for ( V_5 = 0 ; V_5 < V_89 ; V_5 ++ ) {
V_86 = & V_35 . type [ V_5 ] ;
V_86 -> V_68 [ 0 ] = V_34 . V_37 . V_38 [ V_84 ++ ] ;
V_86 -> V_68 [ 1 ] = V_34 . V_37 . V_38 [ V_84 ++ ] ;
V_86 -> V_69 [ 0 ] = V_34 . V_37 . V_38 [ V_84 ++ ] ;
V_86 -> V_69 [ 1 ] = V_34 . V_37 . V_38 [ V_84 ++ ] ;
V_86 -> V_70 [ 0 ] = V_34 . V_37 . V_38 [ V_84 ++ ] ;
V_86 -> V_70 [ 1 ] = V_34 . V_37 . V_38 [ V_84 ++ ] ;
V_86 -> V_71 [ 0 ] = V_34 . V_37 . V_38 [ V_84 ++ ] ;
V_86 -> V_71 [ 1 ] = V_34 . V_37 . V_38 [ V_84 ++ ] ;
V_3 = V_86 -> V_68 [ 0 ] ;
V_85 = F_1 ( V_2 , V_3 ) ;
for ( V_59 = 0 ; V_59 < V_85 ; V_59 ++ )
V_86 -> V_73 [ V_59 ] = V_34 . V_37 . V_38 [ V_59 + V_84 ] ;
V_51 = 16 * sizeof( T_2 ) ;
memcpy ( V_87 , & V_86 -> V_68 [ 0 ] , V_51 ) ;
V_87 += V_51 ;
if ( V_5 == 0 )
V_84 = 18 ;
else
V_84 = 34 ;
}
V_67:
F_39 ( & V_34 ) ;
return V_24 ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_16 * V_12 = V_2 -> V_12 ;
int V_24 ;
V_24 = F_56 ( V_2 , ( char * ) V_12 -> V_23 , 0 ) ;
if ( V_24 )
return V_24 ;
F_57 ( V_2 ) ;
return V_24 ;
}
static int F_66 ( struct V_1 * V_2 ,
bool V_90 )
{
T_1 V_3 = ( V_90 ? V_91 : V_92 ) ;
struct V_33 V_34 ;
int V_24 ;
V_24 = F_37 ( & V_34 , V_2 , V_3 ) ;
if ( V_24 )
return V_24 ;
V_34 . V_66 . V_38 [ 1 ] = V_93 ;
V_24 = F_38 ( V_2 , & V_34 ) ;
if ( V_24 )
F_34 ( & V_2 -> V_26 -> V_27 , L_8 ,
( V_90 ? L_9 : L_10 ) , V_24 ) ;
F_39 ( & V_34 ) ;
return V_24 ;
}
static void F_67 ( struct V_1 * V_2 ,
void * V_79 )
{
struct V_16 * V_12 = V_2 -> V_12 ;
T_2 * V_3 = V_79 ;
if ( F_61 ( V_19 , & V_2 -> V_8 ) )
return;
if ( * V_3 & V_94 )
F_48 ( V_7 , & V_2 -> V_8 ) ;
else
F_59 ( V_7 , & V_2 -> V_8 ) ;
F_62 ( V_12 -> V_21 , & V_12 -> V_20 , 0 ) ;
}
static void F_68 ( struct V_30 * V_74 ,
struct V_56 * V_86 ,
struct V_95 * type )
{
struct V_96 * V_97 ;
T_1 V_59 , V_98 , V_99 ;
for ( V_59 = 0 ; V_59 < V_100 ; V_59 ++ ) {
V_98 = F_69 ( V_74 -> V_75 , V_59 ) ;
V_97 = & type -> V_97 [ V_98 ] ;
V_97 -> V_101 = true ;
V_97 -> V_4 |= F_15 ( V_59 ) ;
if ( F_70 ( V_86 -> V_68 [ 1 ] , V_59 ) &&
type -> V_102 ) {
V_97 -> V_103 [ V_59 ] . V_101 = true ;
V_97 -> V_103 [ V_59 ] . V_104 = V_105 ;
}
if ( V_59 < 4 )
V_99 = F_71 ( V_86 -> V_69 [ 0 ] , V_59 ) ;
else
V_99 = F_71 ( V_86 -> V_69 [ 1 ] , V_59 ) ;
V_97 -> V_99 = V_99 ;
V_97 -> V_106 = V_107 ;
type -> V_108 [ V_97 -> V_99 ] . V_109 ++ ;
}
}
static void F_72 ( struct V_56 * V_86 ,
struct V_95 * type )
{
struct V_110 * V_108 ;
T_1 V_59 , V_111 , V_112 ;
for ( V_59 = 0 ; V_59 < V_113 ; V_59 ++ ) {
V_108 = & type -> V_108 [ V_59 ] ;
V_108 -> V_101 = true ;
if ( V_59 < 4 ) {
V_112 = F_73 ( V_86 -> V_70 [ 0 ] , V_59 ) ;
V_111 = F_74 ( V_86 -> V_71 [ 0 ] , V_59 ) ;
} else {
V_112 = F_73 ( V_86 -> V_70 [ 1 ] , V_59 ) ;
V_111 = F_74 ( V_86 -> V_71 [ 1 ] , V_59 ) ;
}
V_108 -> V_114 = V_112 ;
V_108 -> V_115 = V_111 ;
}
}
static void
F_75 ( struct V_1 * V_2 , T_1 V_83 ,
struct V_56 * V_86 ,
struct V_95 * type )
{
struct V_116 * V_73 ;
T_1 V_59 , V_117 , V_118 , V_119 ;
struct V_120 V_121 ;
V_117 = F_1 ( V_2 , V_86 -> V_68 [ 0 ] ) ;
for ( V_59 = 0 ; V_59 < V_117 ; V_59 ++ ) {
V_73 = & type -> V_73 [ V_59 ] ;
V_73 -> V_101 = true ;
V_73 -> V_122 = F_76 ( V_86 -> V_73 [ V_59 ] ) - 1 ;
V_121 . V_122 = V_73 -> V_122 ;
V_73 -> V_123 = F_77 ( V_86 -> V_73 [ V_59 ] ) ;
V_121 . V_123 = V_73 -> V_123 ;
V_118 = F_11 ( V_2 , V_86 -> V_73 [ V_59 ] ) ;
V_119 = F_14 ( V_118 ) ;
if ( V_119 >= V_6 )
V_119 = 0 ;
V_73 -> V_124 = V_119 ;
V_121 . V_124 = V_119 ;
if ( V_83 == V_125 && V_2 -> V_9 -> V_10 )
F_78 ( V_2 -> V_9 , & V_121 ) ;
}
}
static void F_79 ( struct V_1 * V_2 , T_1 V_83 )
{
struct V_30 * V_74 = V_2 -> V_12 -> V_23 ;
struct V_56 * V_86 = & V_74 -> type [ V_83 ] ;
struct V_28 * V_22 = V_2 -> V_12 -> V_22 ;
struct V_95 * type = & V_22 -> type [ V_83 ] ;
type -> V_126 = false ;
type -> V_102 = false ;
memset ( type -> V_97 , 0 ,
sizeof( struct V_96 ) * V_6 ) ;
memset ( type -> V_108 , 0 ,
sizeof( struct V_110 ) * V_6 ) ;
if ( F_5 ( V_2 , V_86 -> V_68 [ 0 ] ) &&
V_22 -> V_41 . V_46 )
type -> V_102 = true ;
if ( F_8 ( V_2 , V_86 -> V_68 [ 0 ] ) &&
V_22 -> V_41 . V_45 )
type -> V_126 = true ;
F_68 ( V_74 , V_86 , type ) ;
F_72 ( V_86 , type ) ;
F_75 ( V_2 , V_83 , V_86 , type ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_89 ; V_59 ++ )
F_79 ( V_2 , V_59 ) ;
F_80 ( V_2 -> V_9 , V_127 , V_128 , 0 , 0 ) ;
}
static T_1 F_81 ( struct V_129 * V_9 )
{
struct V_1 * V_2 = F_82 ( V_9 ) ;
return F_17 ( V_7 , & V_2 -> V_8 ) ;
}
static void F_83 ( struct V_129 * V_9 , T_1 * V_58 )
{
memcpy ( V_58 , V_9 -> V_130 , V_9 -> V_131 ) ;
}
static void
F_84 ( struct V_129 * V_9 , int V_98 , T_1 * V_132 ,
T_1 * V_99 , T_1 * V_112 , T_1 * V_4 )
{
struct V_1 * V_2 = F_82 ( V_9 ) ;
struct V_96 * V_97 , * V_133 ;
struct V_95 * type ;
T_1 V_59 , V_119 , V_134 ;
type = & V_2 -> V_12 -> V_22 -> type [ V_125 ] ;
* V_132 = * V_99 = * V_112 = * V_4 = 0 ;
if ( ! F_17 ( V_7 , & V_2 -> V_8 ) ||
! type -> V_126 )
return;
if ( V_98 < 0 || ( V_98 > V_6 ) )
return;
V_97 = & type -> V_97 [ V_98 ] ;
if ( ! V_97 -> V_101 )
return;
* V_99 = V_97 -> V_99 ;
* V_132 = V_97 -> V_106 ;
* V_4 = V_97 -> V_4 ;
V_134 = * V_99 ;
for ( V_59 = 0 , V_119 = 0 ; V_59 < V_6 ; V_59 ++ ) {
V_133 = & type -> V_97 [ V_59 ] ;
if ( V_133 -> V_101 && ( V_134 == V_133 -> V_99 ) )
V_119 ++ ;
}
V_97 -> V_135 = ( 100 / V_119 ) ;
* V_112 = V_97 -> V_135 ;
}
static void F_85 ( struct V_129 * V_9 , int V_99 ,
T_1 * V_136 )
{
struct V_1 * V_2 = F_82 ( V_9 ) ;
struct V_110 * V_137 ;
struct V_95 * type ;
* V_136 = 0 ;
type = & V_2 -> V_12 -> V_22 -> type [ V_125 ] ;
if ( ! F_17 ( V_7 , & V_2 -> V_8 ) ||
! type -> V_126 )
return;
if ( V_99 < 0 || V_99 > V_113 )
return;
V_137 = & type -> V_108 [ V_99 ] ;
if ( ! V_137 -> V_101 )
return;
* V_136 = V_137 -> V_114 ;
}
static void F_86 ( struct V_129 * V_9 , int V_132 ,
T_1 * V_138 )
{
struct V_1 * V_2 = F_82 ( V_9 ) ;
struct V_96 * V_97 ;
T_1 V_3 = F_15 ( V_132 ) ;
struct V_95 * type ;
T_1 V_59 ;
* V_138 = 0 ;
type = & V_2 -> V_12 -> V_22 -> type [ V_125 ] ;
if ( ! F_17 ( V_7 , & V_2 -> V_8 ) ||
! type -> V_102 )
return;
for ( V_59 = 0 ; V_59 < V_6 ; V_59 ++ ) {
V_97 = & type -> V_97 [ V_59 ] ;
if ( ! V_97 -> V_101 )
continue;
if ( ( V_3 & V_97 -> V_4 ) && ( V_97 -> V_103 [ V_132 ] . V_101 ) )
* V_138 = V_97 -> V_103 [ V_132 ] . V_104 ;
}
}
static T_1 F_87 ( struct V_129 * V_9 , int V_139 ,
T_1 * V_40 )
{
struct V_1 * V_2 = F_82 ( V_9 ) ;
if ( ! F_17 ( V_7 , & V_2 -> V_8 ) )
return 0 ;
switch ( V_139 ) {
case V_140 :
case V_141 :
case V_142 :
case V_143 :
* V_40 = true ;
break;
case V_144 :
case V_145 :
* V_40 = 0x80 ;
break;
case V_146 :
* V_40 = V_2 -> V_12 -> V_22 -> V_41 . V_48 ;
break;
default:
* V_40 = false ;
}
return 0 ;
}
static int F_88 ( struct V_129 * V_9 , int V_147 , T_1 * V_148 )
{
struct V_1 * V_2 = F_82 ( V_9 ) ;
struct V_28 * V_22 = V_2 -> V_12 -> V_22 ;
if ( ! F_17 ( V_7 , & V_2 -> V_8 ) )
return - V_47 ;
switch ( V_147 ) {
case V_149 :
* V_148 = V_22 -> V_41 . V_45 ;
return 0 ;
case V_150 :
* V_148 = V_22 -> V_41 . V_46 ;
return 0 ;
default:
return - V_47 ;
}
}
static T_1 F_89 ( struct V_129 * V_9 , T_1 V_151 , T_3 V_152 )
{
struct V_1 * V_2 = F_82 ( V_9 ) ;
struct V_120 V_73 = {
. V_122 = V_151 ,
. V_123 = V_152 ,
} ;
if ( ! F_17 ( V_7 , & V_2 -> V_8 ) )
return 0 ;
return F_90 ( V_9 , & V_73 ) ;
}
static T_1 F_91 ( struct V_129 * V_9 )
{
struct V_1 * V_2 = F_82 ( V_9 ) ;
struct V_16 * V_12 = V_2 -> V_12 ;
if ( ! F_17 ( V_7 , & V_2 -> V_8 ) )
return 0 ;
return V_12 -> V_22 -> type [ V_125 ] . V_102 ;
}
static T_1 F_92 ( struct V_129 * V_9 )
{
struct V_1 * V_2 = F_82 ( V_9 ) ;
struct V_28 * V_22 = V_2 -> V_12 -> V_22 ;
if ( ! F_17 ( V_7 , & V_2 -> V_8 ) )
return 0 ;
return V_22 -> V_41 . V_48 ;
}
static T_1 F_93 ( struct V_129 * V_9 , int V_153 , T_1 * V_90 )
{
struct V_1 * V_2 = F_82 ( V_9 ) ;
struct V_95 * type ;
if ( ! F_17 ( V_7 , & V_2 -> V_8 ) )
return 1 ;
type = & V_2 -> V_12 -> V_22 -> type [ V_125 ] ;
* V_90 = 0 ;
switch ( V_153 ) {
case V_154 :
if ( type -> V_126 )
* V_90 |= V_155 ;
else
* V_90 |= V_156 ;
break;
case V_157 :
if ( type -> V_102 ) {
if ( type -> V_97 [ 0 ] . V_103 [ 0 ] . V_104 )
* V_90 |= V_155 ;
} else {
* V_90 |= V_156 ;
}
break;
case V_158 :
* V_90 |= V_155 ;
break;
default:
F_94 ( V_9 , L_11 , V_153 ) ;
return 1 ;
}
return 0 ;
}
static inline void
F_95 ( struct V_129 * V_9 , int V_132 , T_1 * V_106 ,
T_1 * V_99 , T_1 * V_136 , T_1 * V_159 )
{
* V_106 = * V_99 = * V_136 = * V_159 = 0 ;
}
static inline void
F_96 ( struct V_129 * V_9 , int V_99 , T_1 * V_136 )
{
* V_136 = 0 ;
}
static int F_97 ( struct V_129 * V_9 ,
struct V_160 * V_161 ,
T_3 * V_162 )
{
struct V_1 * V_2 = F_82 ( V_9 ) ;
struct V_95 * V_163 ;
int V_59 ;
* V_162 = 0 ;
if ( ! F_17 ( V_7 , & V_2 -> V_8 ) )
return 0 ;
V_163 = & V_2 -> V_12 -> V_22 -> type [ V_164 ] ;
for ( V_59 = 0 ; V_59 < V_72 ; V_59 ++ ) {
if ( V_163 -> V_73 [ V_59 ] . V_101 )
( * V_162 ) ++ ;
}
return 0 ;
}
static int F_98 ( struct V_129 * V_9 ,
struct V_120 * V_165 )
{
struct V_1 * V_2 = F_82 ( V_9 ) ;
struct V_95 * V_163 ;
struct V_116 * V_73 ;
int V_59 , V_5 ;
if ( ! F_17 ( V_7 , & V_2 -> V_8 ) )
return 0 ;
V_163 = & V_2 -> V_12 -> V_22 -> type [ V_164 ] ;
for ( V_59 = 0 , V_5 = 0 ; V_59 < V_72 ; V_59 ++ ) {
V_73 = & V_163 -> V_73 [ V_59 ] ;
if ( ! V_73 -> V_101 )
continue;
V_165 [ V_5 ] . V_122 = V_73 -> V_122 ;
V_165 [ V_5 ] . V_124 = V_73 -> V_124 ;
V_165 [ V_5 ++ ] . V_123 = V_73 -> V_123 ;
}
return 0 ;
}
static int F_99 ( struct V_129 * V_9 ,
struct V_166 * V_134 )
{
struct V_1 * V_2 = F_82 ( V_9 ) ;
struct V_95 * V_163 ;
T_1 V_59 , V_5 , V_84 , V_118 ;
if ( ! F_17 ( V_7 , & V_2 -> V_8 ) )
return 0 ;
V_163 = & V_2 -> V_12 -> V_22 -> type [ V_164 ] ;
for ( V_59 = 0 , V_5 = 0 ; V_59 < V_113 ; V_59 ++ ) {
if ( ! V_163 -> V_108 [ V_59 ] . V_101 )
continue;
V_134 -> V_167 [ V_5 ] = V_163 -> V_108 [ V_59 ] . V_114 ;
for ( V_84 = 0 ; V_84 < V_6 ; V_84 ++ ) {
if ( V_163 -> V_97 [ V_59 ] . V_101 &&
( V_163 -> V_97 [ V_59 ] . V_99 == V_59 ) ) {
V_118 = V_163 -> V_97 [ V_59 ] . V_4 ;
V_134 -> V_168 [ V_5 ++ ] = V_118 ;
break;
}
}
}
return 0 ;
}
static int F_100 ( struct V_129 * V_9 ,
struct V_169 * V_170 )
{
struct V_1 * V_2 = F_82 ( V_9 ) ;
struct V_28 * V_22 = V_2 -> V_12 -> V_22 ;
struct V_96 * V_98 ;
struct V_95 * V_163 ;
T_1 V_59 , V_138 , V_132 ;
V_170 -> V_171 = 0 ;
if ( ! F_17 ( V_7 , & V_2 -> V_8 ) )
return 0 ;
V_163 = & V_22 -> type [ V_164 ] ;
for ( V_59 = 0 ; V_59 < V_6 ; V_59 ++ ) {
V_98 = & V_163 -> V_97 [ V_59 ] ;
V_132 = F_14 ( V_98 -> V_4 ) ;
V_138 = 0 ;
F_86 ( V_9 , V_132 , & V_138 ) ;
if ( V_138 )
V_170 -> V_171 |= F_15 ( V_59 ) ;
}
V_170 -> V_172 = V_22 -> V_41 . V_46 ;
return 0 ;
}
