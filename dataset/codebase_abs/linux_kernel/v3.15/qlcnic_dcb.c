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
static inline void F_16 ( struct V_7 * V_8 )
{
if ( F_17 ( V_9 , & V_8 -> V_10 ) )
V_8 -> V_2 -> V_11 -> V_12 = & V_13 ;
}
static void F_18 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
V_2 -> V_8 -> V_14 = & V_15 ;
else if ( F_19 ( V_2 ) )
V_2 -> V_8 -> V_14 = & V_16 ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
if ( F_21 ( V_2 ) )
return 0 ;
V_8 = F_22 ( sizeof( struct V_7 ) , V_17 ) ;
if ( ! V_8 )
return - V_18 ;
V_2 -> V_8 = V_8 ;
V_8 -> V_2 = V_2 ;
F_18 ( V_2 ) ;
V_8 -> V_10 = 0 ;
return 0 ;
}
static void F_23 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
if ( ! V_8 )
return;
V_2 = V_8 -> V_2 ;
while ( F_17 ( V_19 , & V_8 -> V_10 ) )
F_24 ( 10000 , 11000 ) ;
F_25 ( & V_8 -> V_20 ) ;
if ( V_8 -> V_21 ) {
F_26 ( V_8 -> V_21 ) ;
V_8 -> V_21 = NULL ;
}
F_27 ( V_8 -> V_22 ) ;
V_8 -> V_22 = NULL ;
F_27 ( V_8 -> V_23 ) ;
V_8 -> V_23 = NULL ;
F_27 ( V_8 ) ;
V_2 -> V_8 = NULL ;
}
static void F_28 ( struct V_7 * V_8 )
{
F_29 ( V_8 ) ;
F_30 ( V_8 ) ;
}
static int F_31 ( struct V_7 * V_8 )
{
int V_24 = 0 ;
F_32 ( & V_8 -> V_20 , V_25 ) ;
V_8 -> V_21 = F_33 ( L_1 ) ;
if ( ! V_8 -> V_21 ) {
F_34 ( & V_8 -> V_2 -> V_26 -> V_27 ,
L_2 ) ;
return - 1 ;
}
V_8 -> V_22 = F_22 ( sizeof( struct V_28 ) , V_17 ) ;
if ( ! V_8 -> V_22 ) {
V_24 = - V_18 ;
goto V_29;
}
V_8 -> V_23 = F_22 ( sizeof( struct V_30 ) , V_17 ) ;
if ( ! V_8 -> V_23 ) {
V_24 = - V_18 ;
goto V_31;
}
return 0 ;
V_31:
F_27 ( V_8 -> V_22 ) ;
V_8 -> V_22 = NULL ;
V_29:
F_26 ( V_8 -> V_21 ) ;
V_8 -> V_21 = NULL ;
return V_24 ;
}
static int F_35 ( struct V_7 * V_8 , char * V_32 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_33 V_34 ;
T_2 V_35 ;
int V_24 ;
V_24 = F_36 ( & V_34 , V_2 , V_36 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_37 ( V_2 , & V_34 ) ;
if ( V_24 ) {
F_34 ( & V_2 -> V_26 -> V_27 ,
L_3 , V_24 ) ;
} else {
V_35 = V_34 . V_37 . V_38 [ 1 ] ;
if ( V_32 )
memcpy ( V_32 , & V_35 , sizeof( T_2 ) ) ;
}
F_38 ( & V_34 ) ;
return V_24 ;
}
static int F_39 ( struct V_7 * V_8 , T_2 * V_3 )
{
struct V_39 * V_40 = & V_8 -> V_22 -> V_41 ;
T_2 V_35 ;
int V_24 ;
memset ( V_40 , 0 , sizeof( struct V_39 ) ) ;
V_24 = F_40 ( V_8 , ( char * ) V_3 ) ;
if ( V_24 )
return V_24 ;
V_35 = * V_3 ;
if ( F_41 ( V_35 ) )
V_40 -> V_42 = true ;
if ( F_42 ( V_35 ) )
V_40 -> V_43 = true ;
V_40 -> V_44 = F_43 ( V_35 ) ;
V_40 -> V_45 = F_44 ( V_35 ) ;
V_40 -> V_46 = F_45 ( V_35 ) ;
if ( V_40 -> V_44 > V_6 ||
V_40 -> V_45 > V_40 -> V_44 ||
V_40 -> V_46 > V_40 -> V_44 ) {
F_34 ( & V_8 -> V_2 -> V_26 -> V_27 , L_4 ) ;
return - V_47 ;
}
return V_24 ;
}
static int F_46 ( struct V_7 * V_8 )
{
struct V_28 * V_22 = V_8 -> V_22 ;
struct V_39 * V_40 ;
T_2 V_35 ;
int V_24 ;
V_24 = F_39 ( V_8 , & V_35 ) ;
if ( V_24 )
return V_24 ;
V_40 = & V_22 -> V_41 ;
V_40 -> V_48 = V_49 | V_50 ;
if ( V_40 -> V_48 && V_40 -> V_42 && V_40 -> V_43 )
F_47 ( V_9 , & V_8 -> V_10 ) ;
return V_24 ;
}
static int F_48 ( struct V_7 * V_8 ,
char * V_32 , T_1 type )
{
T_3 V_51 = sizeof( struct V_52 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
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
V_58 = F_49 ( V_27 , V_51 , & V_55 , V_63 ) ;
if ( V_58 == NULL )
return - V_18 ;
V_53 = V_58 ;
V_24 = F_36 ( & V_34 , V_2 , V_64 ) ;
if ( V_24 )
goto V_65;
V_57 = V_55 ;
V_34 . V_66 . V_38 [ 1 ] = V_51 | ( type << 16 ) ;
V_34 . V_66 . V_38 [ 2 ] = F_50 ( V_57 ) ;
V_34 . V_66 . V_38 [ 3 ] = F_51 ( V_57 ) ;
V_24 = F_37 ( V_2 , & V_34 ) ;
if ( V_24 ) {
F_34 ( V_27 , L_6 , V_24 ) ;
goto V_67;
}
memset ( & V_37 , 0 , sizeof( struct V_56 ) ) ;
V_37 . V_68 [ 0 ] = F_52 ( V_53 -> V_68 [ 0 ] ) ;
V_37 . V_68 [ 1 ] = F_52 ( V_53 -> V_68 [ 1 ] ) ;
V_37 . V_69 [ 0 ] = F_52 ( V_53 -> V_69 [ 0 ] ) ;
V_37 . V_69 [ 1 ] = F_52 ( V_53 -> V_69 [ 1 ] ) ;
V_37 . V_70 [ 0 ] = F_52 ( V_53 -> V_70 [ 0 ] ) ;
V_37 . V_70 [ 1 ] = F_52 ( V_53 -> V_70 [ 1 ] ) ;
V_37 . V_71 [ 0 ] = F_52 ( V_53 -> V_71 [ 0 ] ) ;
V_37 . V_71 [ 1 ] = F_52 ( V_53 -> V_71 [ 1 ] ) ;
for ( V_59 = 0 ; V_59 < V_72 ; V_59 ++ )
V_37 . V_73 [ V_59 ] = F_52 ( V_53 -> V_73 [ V_59 ] ) ;
if ( V_32 )
memcpy ( V_32 , & V_37 , V_51 ) ;
V_67:
F_38 ( & V_34 ) ;
V_65:
F_53 ( V_27 , V_51 , V_58 , V_55 ) ;
return V_24 ;
}
static int F_54 ( struct V_7 * V_8 )
{
struct V_30 * V_74 ;
int V_24 ;
V_74 = V_8 -> V_23 ;
if ( ! V_74 )
return 0 ;
V_24 = F_55 ( V_8 , ( char * ) & V_74 -> type [ 0 ] ,
V_60 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_55 ( V_8 , ( char * ) & V_74 -> type [ 1 ] ,
V_61 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_55 ( V_8 , ( char * ) & V_74 -> type [ 2 ] ,
V_62 ) ;
if ( V_24 )
return V_24 ;
V_74 -> V_75 = V_76 ;
F_56 ( V_8 -> V_2 ) ;
return V_24 ;
}
static void V_25 ( struct V_77 * V_78 )
{
struct V_7 * V_8 ;
V_8 = F_57 ( V_78 , struct V_7 , V_20 . V_78 ) ;
F_30 ( V_8 ) ;
F_58 ( V_19 , & V_8 -> V_10 ) ;
}
static void F_59 ( struct V_7 * V_8 , void * V_79 )
{
if ( F_60 ( V_19 , & V_8 -> V_10 ) )
return;
F_61 ( V_8 -> V_21 , & V_8 -> V_20 , 0 ) ;
}
static int F_62 ( struct V_7 * V_8 )
{
struct V_39 * V_40 = & V_8 -> V_22 -> V_41 ;
T_2 V_35 ;
int V_24 ;
V_24 = F_39 ( V_8 , & V_35 ) ;
if ( V_24 )
return V_24 ;
if ( V_35 & V_80 )
V_40 -> V_48 = V_49 ;
if ( V_35 & V_81 )
V_40 -> V_48 |= V_82 ;
if ( V_40 -> V_48 )
V_40 -> V_48 |= V_50 ;
if ( V_40 -> V_48 && V_40 -> V_42 && V_40 -> V_43 )
F_47 ( V_9 , & V_8 -> V_10 ) ;
return V_24 ;
}
static int F_63 ( struct V_7 * V_8 ,
char * V_32 , T_1 V_83 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_30 V_35 ;
int V_24 , V_59 , V_5 , V_84 , V_85 , V_51 ;
struct V_56 * V_86 ;
struct V_33 V_34 ;
T_2 V_3 ;
char * V_87 ;
V_51 = 0 ;
memset ( & V_35 , 0 , sizeof( struct V_30 ) ) ;
memset ( V_32 , 0 , sizeof( struct V_30 ) ) ;
V_24 = F_36 ( & V_34 , V_2 , V_64 ) ;
if ( V_24 )
return V_24 ;
V_34 . V_66 . V_38 [ 0 ] |= V_88 << 29 ;
V_24 = F_37 ( V_2 , & V_34 ) ;
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
F_38 ( & V_34 ) ;
return V_24 ;
}
static int F_64 ( struct V_7 * V_8 )
{
int V_24 ;
V_24 = F_55 ( V_8 , ( char * ) V_8 -> V_23 , 0 ) ;
if ( V_24 )
return V_24 ;
F_56 ( V_8 -> V_2 ) ;
return V_24 ;
}
static void F_65 ( struct V_7 * V_8 , void * V_79 )
{
T_2 * V_3 = V_79 ;
if ( F_60 ( V_19 , & V_8 -> V_10 ) )
return;
if ( * V_3 & V_90 )
F_47 ( V_9 , & V_8 -> V_10 ) ;
else
F_58 ( V_9 , & V_8 -> V_10 ) ;
F_61 ( V_8 -> V_21 , & V_8 -> V_20 , 0 ) ;
}
static void F_66 ( struct V_30 * V_74 ,
struct V_56 * V_86 ,
struct V_91 * type )
{
struct V_92 * V_93 ;
T_1 V_59 , V_94 , V_95 ;
for ( V_59 = 0 ; V_59 < V_96 ; V_59 ++ ) {
V_94 = F_67 ( V_74 -> V_75 , V_59 ) ;
V_93 = & type -> V_93 [ V_94 ] ;
V_93 -> V_97 = true ;
V_93 -> V_4 |= F_15 ( V_59 ) ;
if ( F_68 ( V_86 -> V_68 [ 1 ] , V_59 ) &&
type -> V_98 ) {
V_93 -> V_99 [ V_59 ] . V_97 = true ;
V_93 -> V_99 [ V_59 ] . V_100 = V_101 ;
}
if ( V_59 < 4 )
V_95 = F_69 ( V_86 -> V_69 [ 0 ] , V_59 ) ;
else
V_95 = F_69 ( V_86 -> V_69 [ 1 ] , V_59 ) ;
V_93 -> V_95 = V_95 ;
V_93 -> V_102 = V_103 ;
type -> V_104 [ V_93 -> V_95 ] . V_105 ++ ;
}
}
static void F_70 ( struct V_56 * V_86 ,
struct V_91 * type )
{
struct V_106 * V_104 ;
T_1 V_59 , V_107 , V_108 ;
for ( V_59 = 0 ; V_59 < V_109 ; V_59 ++ ) {
V_104 = & type -> V_104 [ V_59 ] ;
V_104 -> V_97 = true ;
if ( V_59 < 4 ) {
V_108 = F_71 ( V_86 -> V_70 [ 0 ] , V_59 ) ;
V_107 = F_72 ( V_86 -> V_71 [ 0 ] , V_59 ) ;
} else {
V_108 = F_71 ( V_86 -> V_70 [ 1 ] , V_59 ) ;
V_107 = F_72 ( V_86 -> V_71 [ 1 ] , V_59 ) ;
}
V_104 -> V_110 = V_108 ;
V_104 -> V_111 = V_107 ;
}
}
static void
F_73 ( struct V_1 * V_2 , T_1 V_83 ,
struct V_56 * V_86 ,
struct V_91 * type )
{
struct V_112 * V_73 ;
T_1 V_59 , V_113 , V_114 , V_115 ;
struct V_116 V_117 ;
V_113 = F_1 ( V_2 , V_86 -> V_68 [ 0 ] ) ;
for ( V_59 = 0 ; V_59 < V_113 ; V_59 ++ ) {
V_73 = & type -> V_73 [ V_59 ] ;
V_73 -> V_97 = true ;
V_73 -> V_118 = F_74 ( V_86 -> V_73 [ V_59 ] ) - 1 ;
V_117 . V_118 = V_73 -> V_118 ;
V_73 -> V_119 = F_75 ( V_86 -> V_73 [ V_59 ] ) ;
V_117 . V_119 = V_73 -> V_119 ;
V_114 = F_11 ( V_2 , V_86 -> V_73 [ V_59 ] ) ;
V_115 = F_14 ( V_114 ) ;
if ( V_115 >= V_6 )
V_115 = 0 ;
V_73 -> V_120 = V_115 ;
V_117 . V_120 = V_115 ;
if ( V_83 == V_121 && V_2 -> V_11 -> V_12 )
F_76 ( V_2 -> V_11 , & V_117 ) ;
}
}
static void F_77 ( struct V_1 * V_2 , T_1 V_83 )
{
struct V_30 * V_74 = V_2 -> V_8 -> V_23 ;
struct V_56 * V_86 = & V_74 -> type [ V_83 ] ;
struct V_28 * V_22 = V_2 -> V_8 -> V_22 ;
struct V_91 * type = & V_22 -> type [ V_83 ] ;
type -> V_122 = false ;
type -> V_98 = false ;
memset ( type -> V_93 , 0 ,
sizeof( struct V_92 ) * V_6 ) ;
memset ( type -> V_104 , 0 ,
sizeof( struct V_106 ) * V_6 ) ;
if ( F_5 ( V_2 , V_86 -> V_68 [ 0 ] ) &&
V_22 -> V_41 . V_46 )
type -> V_98 = true ;
if ( F_8 ( V_2 , V_86 -> V_68 [ 0 ] ) &&
V_22 -> V_41 . V_45 )
type -> V_122 = true ;
F_66 ( V_74 , V_86 , type ) ;
F_70 ( V_86 , type ) ;
F_73 ( V_2 , V_83 , V_86 , type ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_89 ; V_59 ++ )
F_77 ( V_2 , V_59 ) ;
F_78 ( V_2 -> V_11 , V_123 , V_124 , 0 , 0 ) ;
}
static T_1 F_79 ( struct V_125 * V_11 )
{
struct V_1 * V_2 = F_80 ( V_11 ) ;
return F_17 ( V_9 , & V_2 -> V_8 -> V_10 ) ;
}
static void F_81 ( struct V_125 * V_11 , T_1 * V_58 )
{
memcpy ( V_58 , V_11 -> V_126 , V_11 -> V_127 ) ;
}
static void
F_82 ( struct V_125 * V_11 , int V_94 , T_1 * V_128 ,
T_1 * V_95 , T_1 * V_108 , T_1 * V_4 )
{
struct V_1 * V_2 = F_80 ( V_11 ) ;
struct V_92 * V_93 , * V_129 ;
struct V_91 * type ;
T_1 V_59 , V_115 , V_130 ;
type = & V_2 -> V_8 -> V_22 -> type [ V_121 ] ;
* V_128 = * V_95 = * V_108 = * V_4 = 0 ;
if ( ! F_17 ( V_9 , & V_2 -> V_8 -> V_10 ) ||
! type -> V_122 )
return;
if ( V_94 < 0 || ( V_94 >= V_6 ) )
return;
V_93 = & type -> V_93 [ V_94 ] ;
if ( ! V_93 -> V_97 )
return;
* V_95 = V_93 -> V_95 ;
* V_128 = V_93 -> V_102 ;
* V_4 = V_93 -> V_4 ;
V_130 = * V_95 ;
for ( V_59 = 0 , V_115 = 0 ; V_59 < V_6 ; V_59 ++ ) {
V_129 = & type -> V_93 [ V_59 ] ;
if ( V_129 -> V_97 && ( V_130 == V_129 -> V_95 ) )
V_115 ++ ;
}
V_93 -> V_131 = ( 100 / V_115 ) ;
* V_108 = V_93 -> V_131 ;
}
static void F_83 ( struct V_125 * V_11 , int V_95 ,
T_1 * V_132 )
{
struct V_1 * V_2 = F_80 ( V_11 ) ;
struct V_106 * V_133 ;
struct V_91 * type ;
* V_132 = 0 ;
type = & V_2 -> V_8 -> V_22 -> type [ V_121 ] ;
if ( ! F_17 ( V_9 , & V_2 -> V_8 -> V_10 ) ||
! type -> V_122 )
return;
if ( V_95 < 0 || V_95 >= V_109 )
return;
V_133 = & type -> V_104 [ V_95 ] ;
if ( ! V_133 -> V_97 )
return;
* V_132 = V_133 -> V_110 ;
}
static void F_84 ( struct V_125 * V_11 , int V_128 ,
T_1 * V_134 )
{
struct V_1 * V_2 = F_80 ( V_11 ) ;
struct V_92 * V_93 ;
T_1 V_3 = F_15 ( V_128 ) ;
struct V_91 * type ;
T_1 V_59 ;
* V_134 = 0 ;
type = & V_2 -> V_8 -> V_22 -> type [ V_121 ] ;
if ( ! F_17 ( V_9 , & V_2 -> V_8 -> V_10 ) ||
! type -> V_98 )
return;
for ( V_59 = 0 ; V_59 < V_6 ; V_59 ++ ) {
V_93 = & type -> V_93 [ V_59 ] ;
if ( ! V_93 -> V_97 )
continue;
if ( ( V_3 & V_93 -> V_4 ) && ( V_93 -> V_99 [ V_128 ] . V_97 ) )
* V_134 = V_93 -> V_99 [ V_128 ] . V_100 ;
}
}
static T_1 F_85 ( struct V_125 * V_11 , int V_135 ,
T_1 * V_40 )
{
struct V_1 * V_2 = F_80 ( V_11 ) ;
if ( ! F_17 ( V_9 , & V_2 -> V_8 -> V_10 ) )
return 0 ;
switch ( V_135 ) {
case V_136 :
case V_137 :
case V_138 :
case V_139 :
* V_40 = true ;
break;
case V_140 :
case V_141 :
* V_40 = 0x80 ;
break;
case V_142 :
* V_40 = V_2 -> V_8 -> V_22 -> V_41 . V_48 ;
break;
default:
* V_40 = false ;
}
return 0 ;
}
static int F_86 ( struct V_125 * V_11 , int V_143 , T_1 * V_144 )
{
struct V_1 * V_2 = F_80 ( V_11 ) ;
struct V_28 * V_22 = V_2 -> V_8 -> V_22 ;
if ( ! F_17 ( V_9 , & V_2 -> V_8 -> V_10 ) )
return - V_47 ;
switch ( V_143 ) {
case V_145 :
* V_144 = V_22 -> V_41 . V_45 ;
return 0 ;
case V_146 :
* V_144 = V_22 -> V_41 . V_46 ;
return 0 ;
default:
return - V_47 ;
}
}
static T_1 F_87 ( struct V_125 * V_11 , T_1 V_147 , T_3 V_148 )
{
struct V_1 * V_2 = F_80 ( V_11 ) ;
struct V_116 V_73 = {
. V_118 = V_147 ,
. V_119 = V_148 ,
} ;
if ( ! F_17 ( V_9 , & V_2 -> V_8 -> V_10 ) )
return 0 ;
return F_88 ( V_11 , & V_73 ) ;
}
static T_1 F_89 ( struct V_125 * V_11 )
{
struct V_1 * V_2 = F_80 ( V_11 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
if ( ! F_17 ( V_9 , & V_8 -> V_10 ) )
return 0 ;
return V_8 -> V_22 -> type [ V_121 ] . V_98 ;
}
static T_1 F_90 ( struct V_125 * V_11 )
{
struct V_1 * V_2 = F_80 ( V_11 ) ;
struct V_28 * V_22 = V_2 -> V_8 -> V_22 ;
if ( ! F_17 ( V_9 , & V_2 -> V_8 -> V_10 ) )
return 0 ;
return V_22 -> V_41 . V_48 ;
}
static T_1 F_91 ( struct V_125 * V_11 , int V_149 , T_1 * V_150 )
{
struct V_1 * V_2 = F_80 ( V_11 ) ;
struct V_91 * type ;
if ( ! F_17 ( V_9 , & V_2 -> V_8 -> V_10 ) )
return 1 ;
type = & V_2 -> V_8 -> V_22 -> type [ V_121 ] ;
* V_150 = 0 ;
switch ( V_149 ) {
case V_151 :
if ( type -> V_122 )
* V_150 |= V_152 ;
else
* V_150 |= V_153 ;
break;
case V_154 :
if ( type -> V_98 ) {
if ( type -> V_93 [ 0 ] . V_99 [ 0 ] . V_100 )
* V_150 |= V_152 ;
} else {
* V_150 |= V_153 ;
}
break;
case V_155 :
* V_150 |= V_152 ;
break;
default:
F_92 ( V_11 , L_8 , V_149 ) ;
return 1 ;
}
return 0 ;
}
static inline void
F_93 ( struct V_125 * V_11 , int V_128 , T_1 * V_102 ,
T_1 * V_95 , T_1 * V_132 , T_1 * V_156 )
{
* V_102 = * V_95 = * V_132 = * V_156 = 0 ;
}
static inline void
F_94 ( struct V_125 * V_11 , int V_95 , T_1 * V_132 )
{
* V_132 = 0 ;
}
static int F_95 ( struct V_125 * V_11 ,
struct V_157 * V_158 ,
T_3 * V_159 )
{
struct V_1 * V_2 = F_80 ( V_11 ) ;
struct V_91 * V_160 ;
int V_59 ;
memset ( V_158 , 0 , sizeof( * V_158 ) ) ;
* V_159 = 0 ;
if ( ! F_17 ( V_9 , & V_2 -> V_8 -> V_10 ) )
return 0 ;
V_160 = & V_2 -> V_8 -> V_22 -> type [ V_161 ] ;
for ( V_59 = 0 ; V_59 < V_72 ; V_59 ++ ) {
if ( V_160 -> V_73 [ V_59 ] . V_97 )
( * V_159 ) ++ ;
}
return 0 ;
}
static int F_96 ( struct V_125 * V_11 ,
struct V_116 * V_162 )
{
struct V_1 * V_2 = F_80 ( V_11 ) ;
struct V_91 * V_160 ;
struct V_112 * V_73 ;
int V_59 , V_5 ;
if ( ! F_17 ( V_9 , & V_2 -> V_8 -> V_10 ) )
return 0 ;
V_160 = & V_2 -> V_8 -> V_22 -> type [ V_161 ] ;
for ( V_59 = 0 , V_5 = 0 ; V_59 < V_72 ; V_59 ++ ) {
V_73 = & V_160 -> V_73 [ V_59 ] ;
if ( ! V_73 -> V_97 )
continue;
V_162 [ V_5 ] . V_118 = V_73 -> V_118 ;
V_162 [ V_5 ] . V_120 = V_73 -> V_120 ;
V_162 [ V_5 ++ ] . V_119 = V_73 -> V_119 ;
}
return 0 ;
}
static int F_97 ( struct V_125 * V_11 ,
struct V_163 * V_130 )
{
struct V_1 * V_2 = F_80 ( V_11 ) ;
struct V_91 * V_160 ;
T_1 V_59 , V_5 , V_84 , V_114 ;
if ( ! F_17 ( V_9 , & V_2 -> V_8 -> V_10 ) )
return 0 ;
V_160 = & V_2 -> V_8 -> V_22 -> type [ V_161 ] ;
for ( V_59 = 0 , V_5 = 0 ; V_59 < V_109 ; V_59 ++ ) {
if ( ! V_160 -> V_104 [ V_59 ] . V_97 )
continue;
V_130 -> V_164 [ V_5 ] = V_160 -> V_104 [ V_59 ] . V_110 ;
for ( V_84 = 0 ; V_84 < V_6 ; V_84 ++ ) {
if ( V_160 -> V_93 [ V_59 ] . V_97 &&
( V_160 -> V_93 [ V_59 ] . V_95 == V_59 ) ) {
V_114 = V_160 -> V_93 [ V_59 ] . V_4 ;
V_130 -> V_165 [ V_5 ++ ] = V_114 ;
break;
}
}
}
return 0 ;
}
static int F_98 ( struct V_125 * V_11 ,
struct V_166 * V_167 )
{
struct V_1 * V_2 = F_80 ( V_11 ) ;
struct V_28 * V_22 = V_2 -> V_8 -> V_22 ;
struct V_92 * V_94 ;
struct V_91 * V_160 ;
T_1 V_59 , V_134 , V_128 ;
V_167 -> V_168 = 0 ;
if ( ! F_17 ( V_9 , & V_2 -> V_8 -> V_10 ) )
return 0 ;
V_160 = & V_22 -> type [ V_161 ] ;
for ( V_59 = 0 ; V_59 < V_6 ; V_59 ++ ) {
V_94 = & V_160 -> V_93 [ V_59 ] ;
V_128 = F_14 ( V_94 -> V_4 ) ;
V_134 = 0 ;
F_84 ( V_11 , V_128 , & V_134 ) ;
if ( V_134 )
V_167 -> V_168 |= F_15 ( V_59 ) ;
}
V_167 -> V_169 = V_22 -> V_41 . V_46 ;
return 0 ;
}
