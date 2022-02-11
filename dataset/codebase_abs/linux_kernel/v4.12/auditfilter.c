static void F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> type ) {
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
F_2 ( V_2 -> V_13 ) ;
F_3 ( V_2 -> V_14 ) ;
}
}
static inline void F_4 ( struct V_15 * V_16 )
{
int V_17 ;
struct V_18 * V_19 = & V_16 -> V_20 ;
if ( V_19 -> V_21 )
F_5 ( V_19 -> V_21 ) ;
if ( V_19 -> V_22 )
for ( V_17 = 0 ; V_17 < V_19 -> V_23 ; V_17 ++ )
F_1 ( & V_19 -> V_22 [ V_17 ] ) ;
F_2 ( V_19 -> V_22 ) ;
F_2 ( V_19 -> V_24 ) ;
F_2 ( V_16 ) ;
}
void F_6 ( struct V_25 * V_26 )
{
struct V_15 * V_16 = F_7 ( V_26 , struct V_15 , V_27 ) ;
F_4 ( V_16 ) ;
}
static inline struct V_15 * F_8 ( T_1 V_23 )
{
struct V_15 * V_28 ;
struct V_1 * V_22 ;
V_28 = F_9 ( sizeof( * V_28 ) , V_29 ) ;
if ( F_10 ( ! V_28 ) )
return NULL ;
V_22 = F_11 ( V_23 , sizeof( * V_22 ) , V_29 ) ;
if ( F_10 ( ! V_22 ) ) {
F_2 ( V_28 ) ;
return NULL ;
}
V_28 -> V_20 . V_22 = V_22 ;
return V_28 ;
}
char * F_12 ( void * * V_30 , T_2 * V_31 , T_2 V_32 )
{
char * V_33 ;
if ( ! * V_30 || ( V_32 == 0 ) || ( V_32 > * V_31 ) )
return F_13 ( - V_34 ) ;
if ( V_32 > V_35 )
return F_13 ( - V_36 ) ;
V_33 = F_14 ( V_32 + 1 , V_29 ) ;
if ( F_10 ( ! V_33 ) )
return F_13 ( - V_37 ) ;
memcpy ( V_33 , * V_30 , V_32 ) ;
V_33 [ V_32 ] = 0 ;
* V_30 += V_32 ;
* V_31 -= V_32 ;
return V_33 ;
}
static inline int F_15 ( struct V_18 * V_38 ,
struct V_1 * V_2 )
{
if ( V_38 -> V_39 != V_40 ||
V_38 -> V_41 || V_38 -> V_21 || V_38 -> V_42 ||
( V_2 -> V_43 != V_44 && V_2 -> V_43 != V_45 ) )
return - V_34 ;
V_38 -> V_41 = V_2 ;
return 0 ;
}
int T_3 F_16 ( int V_46 , unsigned * V_47 )
{
T_4 * V_48 = F_11 ( V_49 , sizeof( T_4 ) , V_29 ) ;
if ( ! V_48 )
return - V_37 ;
while ( * V_47 != ~ 0U ) {
unsigned V_50 = * V_47 ++ ;
if ( V_50 >= V_49 * 32 - V_51 ) {
F_2 ( V_48 ) ;
return - V_34 ;
}
V_48 [ F_17 ( V_50 ) ] |= F_18 ( V_50 ) ;
}
if ( V_46 >= V_51 || V_52 [ V_46 ] ) {
F_2 ( V_48 ) ;
return - V_34 ;
}
V_52 [ V_46 ] = V_48 ;
return 0 ;
}
int F_19 ( int V_46 , unsigned V_53 )
{
if ( F_10 ( V_53 >= V_49 * 32 ) )
return 0 ;
if ( F_10 ( V_46 >= V_51 || ! V_52 [ V_46 ] ) )
return 0 ;
return V_52 [ V_46 ] [ F_17 ( V_53 ) ] & F_18 ( V_53 ) ;
}
static inline int F_20 ( int V_46 , T_1 * V_54 )
{
int V_17 ;
if ( V_52 [ V_46 ] ) {
for ( V_17 = 0 ; V_17 < V_49 ; V_17 ++ )
if ( V_54 [ V_17 ] & V_52 [ V_46 ] [ V_17 ] )
return 0 ;
}
return 1 ;
}
static int F_21 ( struct V_15 * V_28 )
{
struct V_1 * V_55 = V_28 -> V_20 . V_56 ;
if ( ! V_55 ) {
return ( F_20 ( V_57 ,
V_28 -> V_20 . V_54 ) &&
F_20 ( V_58 ,
V_28 -> V_20 . V_54 ) ) ;
}
switch( F_22 ( V_55 -> V_59 ) ) {
case 0 :
return ( F_20 ( V_57 ,
V_28 -> V_20 . V_54 ) ) ;
case 1 :
return ( F_20 ( V_58 ,
V_28 -> V_20 . V_54 ) ) ;
default:
return 1 ;
}
}
static inline struct V_15 * F_23 ( struct V_60 * V_20 )
{
unsigned V_39 ;
struct V_15 * V_28 ;
int V_17 , V_61 ;
V_61 = - V_34 ;
V_39 = V_20 -> V_62 & ~ V_63 ;
switch( V_39 ) {
default:
goto V_64;
#ifdef F_24
case V_65 :
if ( V_20 -> V_66 == V_67 )
goto V_64;
case V_40 :
case V_68 :
#endif
case V_69 :
case V_70 :
;
}
if ( F_10 ( V_20 -> V_66 == V_71 ) ) {
F_25 ( L_1 ) ;
goto V_64;
}
if ( V_20 -> V_66 != V_72 && V_20 -> V_66 != V_67 )
goto V_64;
if ( V_20 -> V_23 > V_73 )
goto V_64;
V_61 = - V_37 ;
V_28 = F_8 ( V_20 -> V_23 ) ;
if ( ! V_28 )
goto V_64;
V_28 -> V_20 . V_62 = V_20 -> V_62 & V_63 ;
V_28 -> V_20 . V_39 = V_39 ;
V_28 -> V_20 . V_66 = V_20 -> V_66 ;
V_28 -> V_20 . V_23 = V_20 -> V_23 ;
for ( V_17 = 0 ; V_17 < V_49 ; V_17 ++ )
V_28 -> V_20 . V_54 [ V_17 ] = V_20 -> V_54 [ V_17 ] ;
for ( V_17 = 0 ; V_17 < V_51 ; V_17 ++ ) {
int V_74 = V_49 * 32 - V_17 - 1 ;
T_4 * V_48 = & V_28 -> V_20 . V_54 [ F_17 ( V_74 ) ] ;
T_4 * V_46 ;
if ( ! ( * V_48 & F_18 ( V_74 ) ) )
continue;
* V_48 &= ~ F_18 ( V_74 ) ;
V_46 = V_52 [ V_17 ] ;
if ( V_46 ) {
int V_75 ;
for ( V_75 = 0 ; V_75 < V_49 ; V_75 ++ )
V_28 -> V_20 . V_54 [ V_75 ] |= V_46 [ V_75 ] ;
}
}
return V_28 ;
V_64:
return F_13 ( V_61 ) ;
}
static T_1 F_26 ( T_1 V_43 )
{
T_1 V_50 ;
for ( V_50 = V_44 ; V_50 < V_76 && V_77 [ V_50 ] != V_43 ; V_50 ++ )
;
return V_50 ;
}
static int F_27 ( struct V_15 * V_28 , struct V_1 * V_2 )
{
switch( V_2 -> type ) {
case V_78 :
if ( V_28 -> V_20 . V_39 != V_70 &&
V_28 -> V_20 . V_39 != V_69 )
return - V_34 ;
break;
}
switch( V_2 -> type ) {
default:
return - V_34 ;
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_78 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
if ( V_2 -> V_43 == V_99 || V_2 -> V_43 == V_100 )
return - V_34 ;
break;
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_105 :
case V_106 :
case V_107 :
break;
case V_108 :
if ( ( V_2 -> V_59 != 0 ) && ( V_2 -> V_59 != 1 ) )
return - V_34 ;
case V_109 :
if ( V_2 -> V_43 != V_45 && V_2 -> V_43 != V_44 )
return - V_34 ;
break;
case V_110 :
if ( V_2 -> V_59 & ~ 15 )
return - V_34 ;
break;
case V_111 :
if ( V_2 -> V_59 & ~ V_112 )
return - V_34 ;
break;
case V_113 :
if ( V_2 -> V_59 > V_114 )
return - V_34 ;
break;
case V_115 :
if ( V_2 -> V_43 != V_44 )
return - V_34 ;
if ( V_28 -> V_20 . V_39 != V_40 )
return - V_34 ;
break;
}
return 0 ;
}
static struct V_15 * F_28 ( struct V_60 * V_116 ,
T_2 V_117 )
{
int V_61 = 0 ;
struct V_15 * V_28 ;
void * V_30 ;
T_2 V_31 = V_117 - sizeof( struct V_60 ) ;
int V_17 ;
char * V_33 ;
struct V_118 * V_119 ;
V_28 = F_23 ( V_116 ) ;
if ( F_29 ( V_28 ) )
goto V_120;
V_30 = V_116 -> V_121 ;
for ( V_17 = 0 ; V_17 < V_116 -> V_23 ; V_17 ++ ) {
struct V_1 * V_2 = & V_28 -> V_20 . V_22 [ V_17 ] ;
V_61 = - V_34 ;
V_2 -> V_43 = F_26 ( V_116 -> V_122 [ V_17 ] ) ;
if ( V_2 -> V_43 == V_76 )
goto V_123;
V_2 -> type = V_116 -> V_22 [ V_17 ] ;
V_2 -> V_59 = V_116 -> V_124 [ V_17 ] ;
if ( ( V_2 -> type == V_83 ) && ( V_2 -> V_59 == V_125 ) ) {
V_2 -> type = V_108 ;
V_2 -> V_59 = 0 ;
V_28 -> V_20 . V_126 |= V_127 ;
}
V_61 = F_27 ( V_28 , V_2 ) ;
if ( V_61 )
goto V_123;
V_61 = - V_34 ;
switch ( V_2 -> type ) {
case V_83 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_84 :
V_2 -> V_128 = F_30 ( F_31 () , V_2 -> V_59 ) ;
if ( ! F_32 ( V_2 -> V_128 ) )
goto V_123;
break;
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
V_2 -> V_129 = F_33 ( F_31 () , V_2 -> V_59 ) ;
if ( ! F_34 ( V_2 -> V_129 ) )
goto V_123;
break;
case V_98 :
case V_109 :
V_28 -> V_20 . V_56 = V_2 ;
break;
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
V_33 = F_12 ( & V_30 , & V_31 , V_2 -> V_59 ) ;
if ( F_29 ( V_33 ) )
goto V_123;
V_28 -> V_20 . V_130 += V_2 -> V_59 ;
V_61 = F_35 ( V_2 -> type , V_2 -> V_43 , V_33 ,
( void * * ) & V_2 -> V_14 ) ;
if ( V_61 == - V_34 ) {
F_36 ( L_2 ,
V_33 ) ;
V_61 = 0 ;
}
if ( V_61 ) {
F_2 ( V_33 ) ;
goto V_123;
} else
V_2 -> V_13 = V_33 ;
break;
case V_105 :
V_33 = F_12 ( & V_30 , & V_31 , V_2 -> V_59 ) ;
if ( F_29 ( V_33 ) )
goto V_123;
V_28 -> V_20 . V_130 += V_2 -> V_59 ;
V_61 = F_37 ( & V_28 -> V_20 , V_33 , V_2 -> V_59 , V_2 -> V_43 ) ;
if ( V_61 ) {
F_2 ( V_33 ) ;
goto V_123;
}
break;
case V_106 :
V_33 = F_12 ( & V_30 , & V_31 , V_2 -> V_59 ) ;
if ( F_29 ( V_33 ) )
goto V_123;
V_28 -> V_20 . V_130 += V_2 -> V_59 ;
V_61 = F_38 ( & V_28 -> V_20 , V_33 , V_2 -> V_43 ) ;
F_2 ( V_33 ) ;
if ( V_61 )
goto V_123;
break;
case V_97 :
V_61 = F_15 ( & V_28 -> V_20 , V_2 ) ;
if ( V_61 )
goto V_123;
break;
case V_107 :
if ( V_28 -> V_20 . V_24 || V_2 -> V_59 > V_131 )
goto V_123;
V_33 = F_12 ( & V_30 , & V_31 , V_2 -> V_59 ) ;
if ( F_29 ( V_33 ) )
goto V_123;
V_28 -> V_20 . V_130 += V_2 -> V_59 ;
V_28 -> V_20 . V_24 = V_33 ;
break;
case V_115 :
if ( V_28 -> V_20 . V_132 || V_2 -> V_59 > V_35 )
goto V_123;
V_33 = F_12 ( & V_30 , & V_31 , V_2 -> V_59 ) ;
if ( F_29 ( V_33 ) ) {
V_61 = F_39 ( V_33 ) ;
goto V_123;
}
V_28 -> V_20 . V_130 += V_2 -> V_59 ;
V_119 = F_40 ( & V_28 -> V_20 , V_33 , V_2 -> V_59 ) ;
if ( F_29 ( V_119 ) ) {
F_2 ( V_33 ) ;
V_61 = F_39 ( V_119 ) ;
goto V_123;
}
V_28 -> V_20 . V_132 = V_119 ;
break;
}
}
if ( V_28 -> V_20 . V_41 && V_28 -> V_20 . V_41 -> V_43 == V_45 )
V_28 -> V_20 . V_41 = NULL ;
V_120:
return V_28 ;
V_123:
if ( V_28 -> V_20 . V_42 )
F_41 ( V_28 -> V_20 . V_42 ) ;
if ( V_28 -> V_20 . V_132 )
F_42 ( V_28 -> V_20 . V_132 ) ;
F_4 ( V_28 ) ;
return F_13 ( V_61 ) ;
}
static inline T_2 F_43 ( void * * V_30 , const char * V_33 )
{
T_2 V_32 = strlen ( V_33 ) ;
memcpy ( * V_30 , V_33 , V_32 ) ;
* V_30 += V_32 ;
return V_32 ;
}
static struct V_60 * F_44 ( struct V_18 * V_38 )
{
struct V_60 * V_116 ;
void * V_30 ;
int V_17 ;
V_116 = F_14 ( sizeof( * V_116 ) + V_38 -> V_130 , V_29 ) ;
if ( F_10 ( ! V_116 ) )
return NULL ;
memset ( V_116 , 0 , sizeof( * V_116 ) ) ;
V_116 -> V_62 = V_38 -> V_62 | V_38 -> V_39 ;
V_116 -> V_66 = V_38 -> V_66 ;
V_116 -> V_23 = V_38 -> V_23 ;
V_30 = V_116 -> V_121 ;
for ( V_17 = 0 ; V_17 < V_116 -> V_23 ; V_17 ++ ) {
struct V_1 * V_2 = & V_38 -> V_22 [ V_17 ] ;
V_116 -> V_22 [ V_17 ] = V_2 -> type ;
V_116 -> V_122 [ V_17 ] = V_77 [ V_2 -> V_43 ] ;
switch( V_2 -> type ) {
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
V_116 -> V_130 += V_116 -> V_124 [ V_17 ] =
F_43 ( & V_30 , V_2 -> V_13 ) ;
break;
case V_105 :
V_116 -> V_130 += V_116 -> V_124 [ V_17 ] =
F_43 ( & V_30 ,
F_45 ( V_38 -> V_21 ) ) ;
break;
case V_106 :
V_116 -> V_130 += V_116 -> V_124 [ V_17 ] =
F_43 ( & V_30 ,
F_46 ( V_38 -> V_42 ) ) ;
break;
case V_107 :
V_116 -> V_130 += V_116 -> V_124 [ V_17 ] =
F_43 ( & V_30 , V_38 -> V_24 ) ;
break;
case V_115 :
V_116 -> V_130 += V_116 -> V_124 [ V_17 ] =
F_43 ( & V_30 , F_47 ( V_38 -> V_132 ) ) ;
break;
case V_108 :
if ( V_38 -> V_126 & V_127 && ! V_2 -> V_59 ) {
V_116 -> V_22 [ V_17 ] = V_83 ;
V_116 -> V_124 [ V_17 ] = V_125 ;
break;
}
default:
V_116 -> V_124 [ V_17 ] = V_2 -> V_59 ;
}
}
for ( V_17 = 0 ; V_17 < V_49 ; V_17 ++ ) V_116 -> V_54 [ V_17 ] = V_38 -> V_54 [ V_17 ] ;
return V_116 ;
}
static int F_48 ( struct V_18 * V_133 , struct V_18 * V_134 )
{
int V_17 ;
if ( V_133 -> V_62 != V_134 -> V_62 ||
V_133 -> V_126 != V_134 -> V_126 ||
V_133 -> V_39 != V_134 -> V_39 ||
V_133 -> V_66 != V_134 -> V_66 ||
V_133 -> V_23 != V_134 -> V_23 )
return 1 ;
for ( V_17 = 0 ; V_17 < V_133 -> V_23 ; V_17 ++ ) {
if ( V_133 -> V_22 [ V_17 ] . type != V_134 -> V_22 [ V_17 ] . type ||
V_133 -> V_22 [ V_17 ] . V_43 != V_134 -> V_22 [ V_17 ] . V_43 )
return 1 ;
switch( V_133 -> V_22 [ V_17 ] . type ) {
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
if ( strcmp ( V_133 -> V_22 [ V_17 ] . V_13 , V_134 -> V_22 [ V_17 ] . V_13 ) )
return 1 ;
break;
case V_105 :
if ( strcmp ( F_45 ( V_133 -> V_21 ) ,
F_45 ( V_134 -> V_21 ) ) )
return 1 ;
break;
case V_106 :
if ( strcmp ( F_46 ( V_133 -> V_42 ) ,
F_46 ( V_134 -> V_42 ) ) )
return 1 ;
break;
case V_107 :
if ( strcmp ( V_133 -> V_24 , V_134 -> V_24 ) )
return 1 ;
break;
case V_115 :
if ( strcmp ( F_47 ( V_133 -> V_132 ) ,
F_47 ( V_134 -> V_132 ) ) )
return 1 ;
break;
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
if ( ! F_49 ( V_133 -> V_22 [ V_17 ] . V_128 , V_134 -> V_22 [ V_17 ] . V_128 ) )
return 1 ;
break;
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
if ( ! F_50 ( V_133 -> V_22 [ V_17 ] . V_129 , V_134 -> V_22 [ V_17 ] . V_129 ) )
return 1 ;
break;
default:
if ( V_133 -> V_22 [ V_17 ] . V_59 != V_134 -> V_22 [ V_17 ] . V_59 )
return 1 ;
}
}
for ( V_17 = 0 ; V_17 < V_49 ; V_17 ++ )
if ( V_133 -> V_54 [ V_17 ] != V_134 -> V_54 [ V_17 ] )
return 1 ;
return 0 ;
}
static inline int F_51 ( struct V_1 * V_135 ,
struct V_1 * V_136 )
{
int V_137 = 0 ;
char * V_13 ;
V_13 = F_52 ( V_136 -> V_13 , V_29 ) ;
if ( F_10 ( ! V_13 ) )
return - V_37 ;
V_135 -> V_13 = V_13 ;
V_137 = F_35 ( V_135 -> type , V_135 -> V_43 , V_135 -> V_13 ,
( void * * ) & V_135 -> V_14 ) ;
if ( V_137 == - V_34 ) {
F_36 ( L_2 ,
V_135 -> V_13 ) ;
V_137 = 0 ;
}
return V_137 ;
}
struct V_15 * F_53 ( struct V_18 * V_138 )
{
T_1 V_139 = V_138 -> V_23 ;
struct V_15 * V_28 ;
struct V_18 * V_140 ;
char * V_141 ;
int V_17 , V_61 = 0 ;
V_28 = F_8 ( V_139 ) ;
if ( F_10 ( ! V_28 ) )
return F_13 ( - V_37 ) ;
V_140 = & V_28 -> V_20 ;
V_140 -> V_62 = V_138 -> V_62 ;
V_140 -> V_126 = V_138 -> V_126 ;
V_140 -> V_39 = V_138 -> V_39 ;
V_140 -> V_66 = V_138 -> V_66 ;
for ( V_17 = 0 ; V_17 < V_49 ; V_17 ++ )
V_140 -> V_54 [ V_17 ] = V_138 -> V_54 [ V_17 ] ;
V_140 -> V_142 = V_138 -> V_142 ;
V_140 -> V_130 = V_138 -> V_130 ;
V_140 -> V_41 = V_138 -> V_41 ;
V_140 -> V_23 = V_138 -> V_23 ;
V_140 -> V_42 = V_138 -> V_42 ;
memcpy ( V_140 -> V_22 , V_138 -> V_22 , sizeof( struct V_1 ) * V_139 ) ;
for ( V_17 = 0 ; V_17 < V_139 ; V_17 ++ ) {
switch ( V_140 -> V_22 [ V_17 ] . type ) {
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
V_61 = F_51 ( & V_140 -> V_22 [ V_17 ] ,
& V_138 -> V_22 [ V_17 ] ) ;
break;
case V_107 :
V_141 = F_52 ( V_138 -> V_24 , V_29 ) ;
if ( F_10 ( ! V_141 ) )
V_61 = - V_37 ;
else
V_140 -> V_24 = V_141 ;
break;
case V_115 :
V_61 = F_54 ( V_140 , V_138 ) ;
break;
}
if ( V_61 ) {
if ( V_140 -> V_132 )
F_42 ( V_140 -> V_132 ) ;
F_4 ( V_28 ) ;
return F_13 ( V_61 ) ;
}
}
if ( V_138 -> V_21 ) {
F_55 ( V_138 -> V_21 ) ;
V_140 -> V_21 = V_138 -> V_21 ;
}
return V_28 ;
}
static struct V_15 * F_56 ( struct V_15 * V_28 ,
struct V_143 * * V_48 )
{
struct V_15 * V_16 , * V_144 = NULL ;
struct V_143 * V_47 ;
int V_145 ;
if ( V_28 -> V_20 . V_41 ) {
V_145 = F_57 ( V_28 -> V_20 . V_41 -> V_59 ) ;
* V_48 = V_47 = & V_146 [ V_145 ] ;
} else if ( V_28 -> V_20 . V_21 ) {
for ( V_145 = 0 ; V_145 < V_147 ; V_145 ++ ) {
V_47 = & V_146 [ V_145 ] ;
F_58 (e, list, list)
if ( ! F_48 ( & V_28 -> V_20 , & V_16 -> V_20 ) ) {
V_144 = V_16 ;
goto V_148;
}
}
goto V_148;
} else {
* V_48 = V_47 = & V_149 [ V_28 -> V_20 . V_39 ] ;
}
F_58 (e, list, list)
if ( ! F_48 ( & V_28 -> V_20 , & V_16 -> V_20 ) ) {
V_144 = V_16 ;
goto V_148;
}
V_148:
return V_144 ;
}
static inline int F_59 ( struct V_15 * V_28 )
{
struct V_15 * V_16 ;
struct V_150 * V_21 = V_28 -> V_20 . V_21 ;
struct V_151 * V_42 = V_28 -> V_20 . V_42 ;
struct V_143 * V_47 ;
int V_61 = 0 ;
#ifdef F_24
int V_152 = 0 ;
if ( V_28 -> V_20 . V_39 == V_69 ||
V_28 -> V_20 . V_39 == V_70 )
V_152 = 1 ;
#endif
F_60 ( & V_153 ) ;
V_16 = F_56 ( V_28 , & V_47 ) ;
if ( V_16 ) {
F_61 ( & V_153 ) ;
V_61 = - V_154 ;
if ( V_42 )
F_41 ( V_42 ) ;
return V_61 ;
}
if ( V_21 ) {
V_61 = F_62 ( & V_28 -> V_20 , & V_47 ) ;
if ( V_61 ) {
F_61 ( & V_153 ) ;
if ( V_42 )
F_41 ( V_42 ) ;
return V_61 ;
}
}
if ( V_42 ) {
V_61 = F_63 ( & V_28 -> V_20 ) ;
if ( V_61 ) {
F_61 ( & V_153 ) ;
return V_61 ;
}
}
V_28 -> V_20 . V_142 = ~ 0ULL ;
if ( V_28 -> V_20 . V_39 == V_40 ) {
if ( V_28 -> V_20 . V_62 & V_63 )
V_28 -> V_20 . V_142 = ++ V_155 ;
else
V_28 -> V_20 . V_142 = -- V_156 ;
}
if ( V_28 -> V_20 . V_62 & V_63 ) {
F_64 ( & V_28 -> V_20 . V_47 ,
& V_157 [ V_28 -> V_20 . V_39 ] ) ;
F_65 ( & V_28 -> V_47 , V_47 ) ;
V_28 -> V_20 . V_62 &= ~ V_63 ;
} else {
F_66 ( & V_28 -> V_20 . V_47 ,
& V_157 [ V_28 -> V_20 . V_39 ] ) ;
F_67 ( & V_28 -> V_47 , V_47 ) ;
}
#ifdef F_24
if ( ! V_152 )
V_158 ++ ;
if ( ! F_21 ( V_28 ) )
V_159 ++ ;
#endif
F_61 ( & V_153 ) ;
return V_61 ;
}
int F_68 ( struct V_15 * V_28 )
{
struct V_15 * V_16 ;
struct V_151 * V_42 = V_28 -> V_20 . V_42 ;
struct V_143 * V_47 ;
int V_137 = 0 ;
#ifdef F_24
int V_152 = 0 ;
if ( V_28 -> V_20 . V_39 == V_69 ||
V_28 -> V_20 . V_39 == V_70 )
V_152 = 1 ;
#endif
F_60 ( & V_153 ) ;
V_16 = F_56 ( V_28 , & V_47 ) ;
if ( ! V_16 ) {
V_137 = - V_160 ;
goto V_148;
}
if ( V_16 -> V_20 . V_21 )
F_69 ( & V_16 -> V_20 ) ;
if ( V_16 -> V_20 . V_42 )
F_70 ( & V_16 -> V_20 ) ;
if ( V_16 -> V_20 . V_132 )
F_71 ( & V_16 -> V_20 ) ;
#ifdef F_24
if ( ! V_152 )
V_158 -- ;
if ( ! F_21 ( V_28 ) )
V_159 -- ;
#endif
F_72 ( & V_16 -> V_47 ) ;
F_73 ( & V_16 -> V_20 . V_47 ) ;
F_74 ( & V_16 -> V_27 , F_6 ) ;
V_148:
F_61 ( & V_153 ) ;
if ( V_42 )
F_41 ( V_42 ) ;
return V_137 ;
}
static void F_75 ( int V_161 , struct V_162 * V_163 )
{
struct V_164 * V_165 ;
struct V_18 * V_166 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_167 ; V_17 ++ ) {
F_58 (r, &audit_rules_list[i], list) {
struct V_60 * V_116 ;
V_116 = F_44 ( V_166 ) ;
if ( F_10 ( ! V_116 ) )
break;
V_165 = F_76 ( V_161 , V_168 , 0 , 1 ,
V_116 ,
sizeof( * V_116 ) + V_116 -> V_130 ) ;
if ( V_165 )
F_77 ( V_163 , V_165 ) ;
F_2 ( V_116 ) ;
}
}
V_165 = F_76 ( V_161 , V_168 , 1 , 1 , NULL , 0 ) ;
if ( V_165 )
F_77 ( V_163 , V_165 ) ;
}
static void F_78 ( char * V_66 , struct V_18 * V_20 , int V_169 )
{
struct V_170 * V_171 ;
T_5 V_172 = F_79 ( & V_173 , F_80 ( V_174 ) ) ;
unsigned int V_175 = F_81 ( V_174 ) ;
if ( ! V_176 )
return;
V_171 = F_82 ( NULL , V_29 , V_177 ) ;
if ( ! V_171 )
return;
F_83 ( V_171 , L_3 , V_172 , V_175 ) ;
F_84 ( V_171 ) ;
F_83 ( V_171 , L_4 , V_66 ) ;
F_85 ( V_171 , V_20 -> V_24 ) ;
F_83 ( V_171 , L_5 , V_20 -> V_39 , V_169 ) ;
F_86 ( V_171 ) ;
}
int F_87 ( int type , int V_161 , void * V_116 , T_2 V_117 )
{
int V_61 = 0 ;
struct V_15 * V_28 ;
V_28 = F_28 ( V_116 , V_117 ) ;
if ( F_29 ( V_28 ) )
return F_39 ( V_28 ) ;
switch ( type ) {
case V_178 :
V_61 = F_59 ( V_28 ) ;
F_78 ( L_6 , & V_28 -> V_20 , ! V_61 ) ;
break;
case V_179 :
V_61 = F_68 ( V_28 ) ;
F_78 ( L_7 , & V_28 -> V_20 , ! V_61 ) ;
break;
default:
V_61 = - V_34 ;
F_88 ( 1 ) ;
}
if ( V_61 || type == V_179 ) {
if ( V_28 -> V_20 . V_132 )
F_42 ( V_28 -> V_20 . V_132 ) ;
F_4 ( V_28 ) ;
}
return V_61 ;
}
int F_89 ( struct V_164 * V_180 , int V_161 )
{
T_1 V_181 = F_90 ( V_180 ) . V_181 ;
struct V_182 * V_182 = F_91 ( F_90 ( V_180 ) . V_183 ) ;
struct V_184 * V_185 ;
struct V_186 * V_187 ;
int V_61 = 0 ;
V_187 = F_14 ( sizeof( struct V_186 ) , V_29 ) ;
if ( ! V_187 )
return - V_37 ;
V_187 -> V_182 = F_92 ( V_182 ) ;
V_187 -> V_181 = V_181 ;
F_93 ( & V_187 -> V_163 ) ;
F_60 ( & V_153 ) ;
F_75 ( V_161 , & V_187 -> V_163 ) ;
F_61 ( & V_153 ) ;
V_185 = F_94 ( V_188 , V_187 , L_8 ) ;
if ( F_29 ( V_185 ) ) {
F_95 ( & V_187 -> V_163 ) ;
F_2 ( V_187 ) ;
V_61 = F_39 ( V_185 ) ;
}
return V_61 ;
}
int F_96 ( T_1 V_189 , T_1 V_43 , T_1 V_190 )
{
switch ( V_43 ) {
case V_44 :
return ( V_189 == V_190 ) ;
case V_45 :
return ( V_189 != V_190 ) ;
case V_191 :
return ( V_189 < V_190 ) ;
case V_192 :
return ( V_189 <= V_190 ) ;
case V_193 :
return ( V_189 > V_190 ) ;
case V_194 :
return ( V_189 >= V_190 ) ;
case V_99 :
return ( V_189 & V_190 ) ;
case V_100 :
return ( ( V_189 & V_190 ) == V_190 ) ;
default:
F_97 () ;
return 0 ;
}
}
int F_98 ( T_6 V_189 , T_1 V_43 , T_6 V_190 )
{
switch ( V_43 ) {
case V_44 :
return F_49 ( V_189 , V_190 ) ;
case V_45 :
return ! F_49 ( V_189 , V_190 ) ;
case V_191 :
return F_99 ( V_189 , V_190 ) ;
case V_192 :
return F_100 ( V_189 , V_190 ) ;
case V_193 :
return F_101 ( V_189 , V_190 ) ;
case V_194 :
return F_102 ( V_189 , V_190 ) ;
case V_99 :
case V_100 :
default:
F_97 () ;
return 0 ;
}
}
int F_103 ( T_7 V_189 , T_1 V_43 , T_7 V_190 )
{
switch ( V_43 ) {
case V_44 :
return F_50 ( V_189 , V_190 ) ;
case V_45 :
return ! F_50 ( V_189 , V_190 ) ;
case V_191 :
return F_104 ( V_189 , V_190 ) ;
case V_192 :
return F_105 ( V_189 , V_190 ) ;
case V_193 :
return F_106 ( V_189 , V_190 ) ;
case V_194 :
return F_107 ( V_189 , V_190 ) ;
case V_99 :
case V_100 :
default:
F_97 () ;
return 0 ;
}
}
int F_108 ( const char * V_195 )
{
int V_196 ;
const char * V_48 ;
V_196 = strlen ( V_195 ) ;
if ( V_196 == 0 )
return V_196 ;
V_48 = V_195 + V_196 - 1 ;
while ( ( * V_48 == '/' ) && ( V_48 > V_195 ) )
V_48 -- ;
while ( ( * V_48 != '/' ) && ( V_48 > V_195 ) )
V_48 -- ;
if ( * V_48 == '/' )
V_48 ++ ;
return V_48 - V_195 ;
}
int F_109 ( const char * V_197 , const char * V_195 , int V_198 )
{
int V_199 , V_200 ;
const char * V_48 ;
V_199 = strlen ( V_197 ) ;
V_200 = strlen ( V_195 ) ;
if ( V_200 < V_199 )
return 1 ;
V_198 = V_198 == V_201 ? F_108 ( V_195 ) : V_198 ;
if ( V_200 - V_198 != V_199 )
return 1 ;
V_48 = V_195 + V_198 ;
return strncmp ( V_48 , V_197 , V_199 ) ;
}
int F_110 ( int V_202 , unsigned int V_203 )
{
struct V_15 * V_16 ;
int V_137 = 1 ;
F_111 () ;
if ( F_112 ( & V_149 [ V_203 ] ) )
goto V_204;
F_113 (e, &audit_filter_list[listtype], list) {
int V_17 , V_205 = 0 ;
for ( V_17 = 0 ; V_17 < V_16 -> V_20 . V_23 ; V_17 ++ ) {
struct V_1 * V_2 = & V_16 -> V_20 . V_22 [ V_17 ] ;
T_8 V_206 ;
T_1 V_207 ;
switch ( V_2 -> type ) {
case V_90 :
V_206 = F_114 ( V_174 ) ;
V_205 = F_96 ( V_206 , V_2 -> V_43 , V_2 -> V_59 ) ;
break;
case V_79 :
V_205 = F_98 ( F_115 () , V_2 -> V_43 , V_2 -> V_128 ) ;
break;
case V_85 :
V_205 = F_103 ( F_116 () , V_2 -> V_43 , V_2 -> V_129 ) ;
break;
case V_83 :
V_205 = F_98 ( F_80 ( V_174 ) ,
V_2 -> V_43 , V_2 -> V_128 ) ;
break;
case V_108 :
V_205 = F_96 ( F_117 ( V_174 ) ,
V_2 -> V_43 , V_2 -> V_59 ) ;
break;
case V_78 :
V_205 = F_96 ( V_202 , V_2 -> V_43 , V_2 -> V_59 ) ;
break;
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
if ( V_2 -> V_14 ) {
F_118 ( V_174 , & V_207 ) ;
V_205 = F_119 ( V_207 ,
V_2 -> type , V_2 -> V_43 , V_2 -> V_14 , NULL ) ;
}
break;
default:
goto V_204;
}
if ( V_205 < 0 )
goto V_204;
if ( ! V_205 )
break;
}
if ( V_205 > 0 ) {
if ( V_16 -> V_20 . V_66 == V_72 || V_203 == V_70 )
V_137 = 0 ;
break;
}
}
V_204:
F_120 () ;
return V_137 ;
}
static int F_121 ( struct V_18 * V_166 )
{
struct V_15 * V_28 = F_7 ( V_166 , struct V_15 , V_20 ) ;
struct V_15 * V_208 ;
int V_61 = 0 ;
if ( ! F_122 ( V_166 ) )
return 0 ;
V_208 = F_53 ( V_166 ) ;
if ( V_28 -> V_20 . V_132 )
F_42 ( V_28 -> V_20 . V_132 ) ;
if ( F_29 ( V_208 ) ) {
V_61 = F_39 ( V_208 ) ;
F_123 ( L_9 ) ;
if ( V_166 -> V_21 )
F_73 ( & V_166 -> V_209 ) ;
F_72 ( & V_28 -> V_47 ) ;
F_73 ( & V_166 -> V_47 ) ;
} else {
if ( V_166 -> V_21 || V_166 -> V_42 )
F_124 ( & V_166 -> V_209 , & V_208 -> V_20 . V_209 ) ;
F_125 ( & V_28 -> V_47 , & V_208 -> V_47 ) ;
F_126 ( & V_166 -> V_47 , & V_208 -> V_20 . V_47 ) ;
}
F_74 ( & V_28 -> V_27 , F_6 ) ;
return V_61 ;
}
int F_127 ( void )
{
struct V_18 * V_166 , * V_50 ;
int V_17 , V_61 = 0 ;
F_60 ( & V_153 ) ;
for ( V_17 = 0 ; V_17 < V_167 ; V_17 ++ ) {
F_128 (r, n, &audit_rules_list[i], list) {
int V_169 = F_121 ( V_166 ) ;
if ( ! V_61 )
V_61 = V_169 ;
}
}
F_61 ( & V_153 ) ;
return V_61 ;
}
