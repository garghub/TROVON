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
} ;
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
if ( V_2 -> V_43 == V_98 || V_2 -> V_43 == V_99 )
return - V_34 ;
break;
case V_100 :
case V_101 :
case V_102 :
case V_103 :
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
case V_104 :
case V_105 :
case V_106 :
break;
case V_107 :
if ( ( V_2 -> V_59 != 0 ) && ( V_2 -> V_59 != 1 ) )
return - V_34 ;
case V_108 :
if ( V_2 -> V_43 != V_45 && V_2 -> V_43 != V_44 )
return - V_34 ;
break;
case V_109 :
if ( V_2 -> V_59 & ~ 15 )
return - V_34 ;
break;
case V_110 :
if ( V_2 -> V_59 & ~ V_111 )
return - V_34 ;
break;
case V_112 :
if ( V_2 -> V_59 > V_113 )
return - V_34 ;
break;
case V_114 :
if ( V_2 -> V_43 != V_44 )
return - V_34 ;
if ( V_28 -> V_20 . V_39 != V_40 )
return - V_34 ;
break;
} ;
return 0 ;
}
static struct V_15 * F_28 ( struct V_60 * V_115 ,
T_2 V_116 )
{
int V_61 = 0 ;
struct V_15 * V_28 ;
void * V_30 ;
T_2 V_31 = V_116 - sizeof( struct V_60 ) ;
int V_17 ;
char * V_33 ;
struct V_117 * V_118 ;
V_28 = F_23 ( V_115 ) ;
if ( F_29 ( V_28 ) )
goto V_119;
V_30 = V_115 -> V_120 ;
for ( V_17 = 0 ; V_17 < V_115 -> V_23 ; V_17 ++ ) {
struct V_1 * V_2 = & V_28 -> V_20 . V_22 [ V_17 ] ;
V_61 = - V_34 ;
V_2 -> V_43 = F_26 ( V_115 -> V_121 [ V_17 ] ) ;
if ( V_2 -> V_43 == V_76 )
goto V_122;
V_2 -> type = V_115 -> V_22 [ V_17 ] ;
V_2 -> V_59 = V_115 -> V_123 [ V_17 ] ;
if ( ( V_2 -> type == V_83 ) && ( V_2 -> V_59 == V_124 ) ) {
V_2 -> type = V_107 ;
V_2 -> V_59 = 0 ;
V_28 -> V_20 . V_125 |= V_126 ;
}
V_61 = F_27 ( V_28 , V_2 ) ;
if ( V_61 )
goto V_122;
V_61 = - V_34 ;
switch ( V_2 -> type ) {
case V_83 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_84 :
V_2 -> V_127 = F_30 ( F_31 () , V_2 -> V_59 ) ;
if ( ! F_32 ( V_2 -> V_127 ) )
goto V_122;
break;
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
V_2 -> V_128 = F_33 ( F_31 () , V_2 -> V_59 ) ;
if ( ! F_34 ( V_2 -> V_128 ) )
goto V_122;
break;
case V_108 :
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
goto V_122;
V_28 -> V_20 . V_129 += V_2 -> V_59 ;
V_61 = F_35 ( V_2 -> type , V_2 -> V_43 , V_33 ,
( void * * ) & V_2 -> V_14 ) ;
if ( V_61 == - V_34 ) {
F_36 ( L_2 ,
V_33 ) ;
V_61 = 0 ;
}
if ( V_61 ) {
F_2 ( V_33 ) ;
goto V_122;
} else
V_2 -> V_13 = V_33 ;
break;
case V_104 :
V_33 = F_12 ( & V_30 , & V_31 , V_2 -> V_59 ) ;
if ( F_29 ( V_33 ) )
goto V_122;
V_28 -> V_20 . V_129 += V_2 -> V_59 ;
V_61 = F_37 ( & V_28 -> V_20 , V_33 , V_2 -> V_59 , V_2 -> V_43 ) ;
if ( V_61 ) {
F_2 ( V_33 ) ;
goto V_122;
}
break;
case V_105 :
V_33 = F_12 ( & V_30 , & V_31 , V_2 -> V_59 ) ;
if ( F_29 ( V_33 ) )
goto V_122;
V_28 -> V_20 . V_129 += V_2 -> V_59 ;
V_61 = F_38 ( & V_28 -> V_20 , V_33 , V_2 -> V_43 ) ;
F_2 ( V_33 ) ;
if ( V_61 )
goto V_122;
break;
case V_97 :
V_61 = F_15 ( & V_28 -> V_20 , V_2 ) ;
if ( V_61 )
goto V_122;
break;
case V_106 :
if ( V_28 -> V_20 . V_24 || V_2 -> V_59 > V_130 )
goto V_122;
V_33 = F_12 ( & V_30 , & V_31 , V_2 -> V_59 ) ;
if ( F_29 ( V_33 ) )
goto V_122;
V_28 -> V_20 . V_129 += V_2 -> V_59 ;
V_28 -> V_20 . V_24 = V_33 ;
break;
case V_114 :
if ( V_28 -> V_20 . V_131 || V_2 -> V_59 > V_35 )
goto V_122;
V_33 = F_12 ( & V_30 , & V_31 , V_2 -> V_59 ) ;
if ( F_29 ( V_33 ) ) {
V_61 = F_39 ( V_33 ) ;
goto V_122;
}
V_28 -> V_20 . V_129 += V_2 -> V_59 ;
V_118 = F_40 ( & V_28 -> V_20 , V_33 , V_2 -> V_59 ) ;
if ( F_29 ( V_118 ) ) {
F_2 ( V_33 ) ;
V_61 = F_39 ( V_118 ) ;
goto V_122;
}
V_28 -> V_20 . V_131 = V_118 ;
break;
}
}
if ( V_28 -> V_20 . V_41 && V_28 -> V_20 . V_41 -> V_43 == V_45 )
V_28 -> V_20 . V_41 = NULL ;
V_119:
return V_28 ;
V_122:
if ( V_28 -> V_20 . V_42 )
F_41 ( V_28 -> V_20 . V_42 ) ;
if ( V_28 -> V_20 . V_131 )
F_42 ( V_28 -> V_20 . V_131 ) ;
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
struct V_60 * V_115 ;
void * V_30 ;
int V_17 ;
V_115 = F_14 ( sizeof( * V_115 ) + V_38 -> V_129 , V_29 ) ;
if ( F_10 ( ! V_115 ) )
return NULL ;
memset ( V_115 , 0 , sizeof( * V_115 ) ) ;
V_115 -> V_62 = V_38 -> V_62 | V_38 -> V_39 ;
V_115 -> V_66 = V_38 -> V_66 ;
V_115 -> V_23 = V_38 -> V_23 ;
V_30 = V_115 -> V_120 ;
for ( V_17 = 0 ; V_17 < V_115 -> V_23 ; V_17 ++ ) {
struct V_1 * V_2 = & V_38 -> V_22 [ V_17 ] ;
V_115 -> V_22 [ V_17 ] = V_2 -> type ;
V_115 -> V_121 [ V_17 ] = V_77 [ V_2 -> V_43 ] ;
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
V_115 -> V_129 += V_115 -> V_123 [ V_17 ] =
F_43 ( & V_30 , V_2 -> V_13 ) ;
break;
case V_104 :
V_115 -> V_129 += V_115 -> V_123 [ V_17 ] =
F_43 ( & V_30 ,
F_45 ( V_38 -> V_21 ) ) ;
break;
case V_105 :
V_115 -> V_129 += V_115 -> V_123 [ V_17 ] =
F_43 ( & V_30 ,
F_46 ( V_38 -> V_42 ) ) ;
break;
case V_106 :
V_115 -> V_129 += V_115 -> V_123 [ V_17 ] =
F_43 ( & V_30 , V_38 -> V_24 ) ;
break;
case V_114 :
V_115 -> V_129 += V_115 -> V_123 [ V_17 ] =
F_43 ( & V_30 , F_47 ( V_38 -> V_131 ) ) ;
break;
case V_107 :
if ( V_38 -> V_125 & V_126 && ! V_2 -> V_59 ) {
V_115 -> V_22 [ V_17 ] = V_83 ;
V_115 -> V_123 [ V_17 ] = V_124 ;
break;
}
default:
V_115 -> V_123 [ V_17 ] = V_2 -> V_59 ;
}
}
for ( V_17 = 0 ; V_17 < V_49 ; V_17 ++ ) V_115 -> V_54 [ V_17 ] = V_38 -> V_54 [ V_17 ] ;
return V_115 ;
}
static int F_48 ( struct V_18 * V_132 , struct V_18 * V_133 )
{
int V_17 ;
if ( V_132 -> V_62 != V_133 -> V_62 ||
V_132 -> V_125 != V_133 -> V_125 ||
V_132 -> V_39 != V_133 -> V_39 ||
V_132 -> V_66 != V_133 -> V_66 ||
V_132 -> V_23 != V_133 -> V_23 )
return 1 ;
for ( V_17 = 0 ; V_17 < V_132 -> V_23 ; V_17 ++ ) {
if ( V_132 -> V_22 [ V_17 ] . type != V_133 -> V_22 [ V_17 ] . type ||
V_132 -> V_22 [ V_17 ] . V_43 != V_133 -> V_22 [ V_17 ] . V_43 )
return 1 ;
switch( V_132 -> V_22 [ V_17 ] . type ) {
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
if ( strcmp ( V_132 -> V_22 [ V_17 ] . V_13 , V_133 -> V_22 [ V_17 ] . V_13 ) )
return 1 ;
break;
case V_104 :
if ( strcmp ( F_45 ( V_132 -> V_21 ) ,
F_45 ( V_133 -> V_21 ) ) )
return 1 ;
break;
case V_105 :
if ( strcmp ( F_46 ( V_132 -> V_42 ) ,
F_46 ( V_133 -> V_42 ) ) )
return 1 ;
break;
case V_106 :
if ( strcmp ( V_132 -> V_24 , V_133 -> V_24 ) )
return 1 ;
break;
case V_114 :
if ( strcmp ( F_47 ( V_132 -> V_131 ) ,
F_47 ( V_133 -> V_131 ) ) )
return 1 ;
break;
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
if ( ! F_49 ( V_132 -> V_22 [ V_17 ] . V_127 , V_133 -> V_22 [ V_17 ] . V_127 ) )
return 1 ;
break;
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
if ( ! F_50 ( V_132 -> V_22 [ V_17 ] . V_128 , V_133 -> V_22 [ V_17 ] . V_128 ) )
return 1 ;
break;
default:
if ( V_132 -> V_22 [ V_17 ] . V_59 != V_133 -> V_22 [ V_17 ] . V_59 )
return 1 ;
}
}
for ( V_17 = 0 ; V_17 < V_49 ; V_17 ++ )
if ( V_132 -> V_54 [ V_17 ] != V_133 -> V_54 [ V_17 ] )
return 1 ;
return 0 ;
}
static inline int F_51 ( struct V_1 * V_134 ,
struct V_1 * V_135 )
{
int V_136 = 0 ;
char * V_13 ;
V_13 = F_52 ( V_135 -> V_13 , V_29 ) ;
if ( F_10 ( ! V_13 ) )
return - V_37 ;
V_134 -> V_13 = V_13 ;
V_136 = F_35 ( V_134 -> type , V_134 -> V_43 , V_134 -> V_13 ,
( void * * ) & V_134 -> V_14 ) ;
if ( V_136 == - V_34 ) {
F_36 ( L_2 ,
V_134 -> V_13 ) ;
V_136 = 0 ;
}
return V_136 ;
}
struct V_15 * F_53 ( struct V_18 * V_137 )
{
T_1 V_138 = V_137 -> V_23 ;
struct V_15 * V_28 ;
struct V_18 * V_139 ;
char * V_140 ;
int V_17 , V_61 = 0 ;
V_28 = F_8 ( V_138 ) ;
if ( F_10 ( ! V_28 ) )
return F_13 ( - V_37 ) ;
V_139 = & V_28 -> V_20 ;
V_139 -> V_62 = V_137 -> V_62 ;
V_139 -> V_125 = V_137 -> V_125 ;
V_139 -> V_39 = V_137 -> V_39 ;
V_139 -> V_66 = V_137 -> V_66 ;
for ( V_17 = 0 ; V_17 < V_49 ; V_17 ++ )
V_139 -> V_54 [ V_17 ] = V_137 -> V_54 [ V_17 ] ;
V_139 -> V_141 = V_137 -> V_141 ;
V_139 -> V_129 = V_137 -> V_129 ;
V_139 -> V_41 = V_137 -> V_41 ;
V_139 -> V_23 = V_137 -> V_23 ;
V_139 -> V_42 = V_137 -> V_42 ;
memcpy ( V_139 -> V_22 , V_137 -> V_22 , sizeof( struct V_1 ) * V_138 ) ;
for ( V_17 = 0 ; V_17 < V_138 ; V_17 ++ ) {
switch ( V_139 -> V_22 [ V_17 ] . type ) {
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
V_61 = F_51 ( & V_139 -> V_22 [ V_17 ] ,
& V_137 -> V_22 [ V_17 ] ) ;
break;
case V_106 :
V_140 = F_52 ( V_137 -> V_24 , V_29 ) ;
if ( F_10 ( ! V_140 ) )
V_61 = - V_37 ;
else
V_139 -> V_24 = V_140 ;
break;
case V_114 :
V_61 = F_54 ( V_139 , V_137 ) ;
break;
}
if ( V_61 ) {
if ( V_139 -> V_131 )
F_42 ( V_139 -> V_131 ) ;
F_4 ( V_28 ) ;
return F_13 ( V_61 ) ;
}
}
if ( V_137 -> V_21 ) {
F_55 ( V_137 -> V_21 ) ;
V_139 -> V_21 = V_137 -> V_21 ;
}
return V_28 ;
}
static struct V_15 * F_56 ( struct V_15 * V_28 ,
struct V_142 * * V_48 )
{
struct V_15 * V_16 , * V_143 = NULL ;
struct V_142 * V_47 ;
int V_144 ;
if ( V_28 -> V_20 . V_41 ) {
V_144 = F_57 ( V_28 -> V_20 . V_41 -> V_59 ) ;
* V_48 = V_47 = & V_145 [ V_144 ] ;
} else if ( V_28 -> V_20 . V_21 ) {
for ( V_144 = 0 ; V_144 < V_146 ; V_144 ++ ) {
V_47 = & V_145 [ V_144 ] ;
F_58 (e, list, list)
if ( ! F_48 ( & V_28 -> V_20 , & V_16 -> V_20 ) ) {
V_143 = V_16 ;
goto V_147;
}
}
goto V_147;
} else {
* V_48 = V_47 = & V_148 [ V_28 -> V_20 . V_39 ] ;
}
F_58 (e, list, list)
if ( ! F_48 ( & V_28 -> V_20 , & V_16 -> V_20 ) ) {
V_143 = V_16 ;
goto V_147;
}
V_147:
return V_143 ;
}
static inline int F_59 ( struct V_15 * V_28 )
{
struct V_15 * V_16 ;
struct V_149 * V_21 = V_28 -> V_20 . V_21 ;
struct V_150 * V_42 = V_28 -> V_20 . V_42 ;
struct V_142 * V_47 ;
int V_61 = 0 ;
#ifdef F_24
int V_151 = 0 ;
if ( V_28 -> V_20 . V_39 == V_69 ||
V_28 -> V_20 . V_39 == V_70 )
V_151 = 1 ;
#endif
F_60 ( & V_152 ) ;
V_16 = F_56 ( V_28 , & V_47 ) ;
if ( V_16 ) {
F_61 ( & V_152 ) ;
V_61 = - V_153 ;
if ( V_42 )
F_41 ( V_42 ) ;
return V_61 ;
}
if ( V_21 ) {
V_61 = F_62 ( & V_28 -> V_20 , & V_47 ) ;
if ( V_61 ) {
F_61 ( & V_152 ) ;
if ( V_42 )
F_41 ( V_42 ) ;
return V_61 ;
}
}
if ( V_42 ) {
V_61 = F_63 ( & V_28 -> V_20 ) ;
if ( V_61 ) {
F_61 ( & V_152 ) ;
return V_61 ;
}
}
V_28 -> V_20 . V_141 = ~ 0ULL ;
if ( V_28 -> V_20 . V_39 == V_40 ) {
if ( V_28 -> V_20 . V_62 & V_63 )
V_28 -> V_20 . V_141 = ++ V_154 ;
else
V_28 -> V_20 . V_141 = -- V_155 ;
}
if ( V_28 -> V_20 . V_62 & V_63 ) {
F_64 ( & V_28 -> V_20 . V_47 ,
& V_156 [ V_28 -> V_20 . V_39 ] ) ;
F_65 ( & V_28 -> V_47 , V_47 ) ;
V_28 -> V_20 . V_62 &= ~ V_63 ;
} else {
F_66 ( & V_28 -> V_20 . V_47 ,
& V_156 [ V_28 -> V_20 . V_39 ] ) ;
F_67 ( & V_28 -> V_47 , V_47 ) ;
}
#ifdef F_24
if ( ! V_151 )
V_157 ++ ;
if ( ! F_21 ( V_28 ) )
V_158 ++ ;
#endif
F_61 ( & V_152 ) ;
return V_61 ;
}
int F_68 ( struct V_15 * V_28 )
{
struct V_15 * V_16 ;
struct V_150 * V_42 = V_28 -> V_20 . V_42 ;
struct V_142 * V_47 ;
int V_136 = 0 ;
#ifdef F_24
int V_151 = 0 ;
if ( V_28 -> V_20 . V_39 == V_69 ||
V_28 -> V_20 . V_39 == V_70 )
V_151 = 1 ;
#endif
F_60 ( & V_152 ) ;
V_16 = F_56 ( V_28 , & V_47 ) ;
if ( ! V_16 ) {
V_136 = - V_159 ;
goto V_147;
}
if ( V_16 -> V_20 . V_21 )
F_69 ( & V_16 -> V_20 ) ;
if ( V_16 -> V_20 . V_42 )
F_70 ( & V_16 -> V_20 ) ;
if ( V_16 -> V_20 . V_131 )
F_71 ( & V_16 -> V_20 ) ;
#ifdef F_24
if ( ! V_151 )
V_157 -- ;
if ( ! F_21 ( V_28 ) )
V_158 -- ;
#endif
F_72 ( & V_16 -> V_47 ) ;
F_73 ( & V_16 -> V_20 . V_47 ) ;
F_74 ( & V_16 -> V_27 , F_6 ) ;
V_147:
F_61 ( & V_152 ) ;
if ( V_42 )
F_41 ( V_42 ) ;
return V_136 ;
}
static void F_75 ( T_4 V_160 , int V_161 , struct V_162 * V_163 )
{
struct V_164 * V_165 ;
struct V_18 * V_166 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_167 ; V_17 ++ ) {
F_58 (r, &audit_rules_list[i], list) {
struct V_60 * V_115 ;
V_115 = F_44 ( V_166 ) ;
if ( F_10 ( ! V_115 ) )
break;
V_165 = F_76 ( V_160 , V_161 , V_168 ,
0 , 1 , V_115 ,
sizeof( * V_115 ) + V_115 -> V_129 ) ;
if ( V_165 )
F_77 ( V_163 , V_165 ) ;
F_2 ( V_115 ) ;
}
}
V_165 = F_76 ( V_160 , V_161 , V_168 , 1 , 1 , NULL , 0 ) ;
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
F_83 ( V_171 , L_4 ) ;
F_85 ( V_171 , V_66 ) ;
F_86 ( V_171 , V_20 -> V_24 ) ;
F_83 ( V_171 , L_5 , V_20 -> V_39 , V_169 ) ;
F_87 ( V_171 ) ;
}
int F_88 ( int type , T_4 V_160 , int V_161 , void * V_115 ,
T_2 V_116 )
{
int V_61 = 0 ;
struct V_15 * V_28 ;
V_28 = F_28 ( V_115 , V_116 ) ;
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
F_89 ( 1 ) ;
}
if ( V_61 || type == V_179 ) {
if ( V_28 -> V_20 . V_131 )
F_42 ( V_28 -> V_20 . V_131 ) ;
F_4 ( V_28 ) ;
}
return V_61 ;
}
int F_90 ( struct V_164 * V_180 , int V_161 )
{
T_1 V_160 = F_91 ( V_180 ) . V_160 ;
struct V_181 * V_181 = F_92 ( F_91 ( V_180 ) . V_182 ) ;
struct V_183 * V_184 ;
struct V_185 * V_186 ;
int V_61 = 0 ;
V_186 = F_14 ( sizeof( struct V_185 ) , V_29 ) ;
if ( ! V_186 )
return - V_37 ;
V_186 -> V_181 = F_93 ( V_181 ) ;
V_186 -> V_160 = V_160 ;
F_94 ( & V_186 -> V_163 ) ;
F_60 ( & V_152 ) ;
F_75 ( V_160 , V_161 , & V_186 -> V_163 ) ;
F_61 ( & V_152 ) ;
V_184 = F_95 ( V_187 , V_186 , L_8 ) ;
if ( F_29 ( V_184 ) ) {
F_96 ( & V_186 -> V_163 ) ;
F_2 ( V_186 ) ;
V_61 = F_39 ( V_184 ) ;
}
return V_61 ;
}
int F_97 ( T_1 V_188 , T_1 V_43 , T_1 V_189 )
{
switch ( V_43 ) {
case V_44 :
return ( V_188 == V_189 ) ;
case V_45 :
return ( V_188 != V_189 ) ;
case V_190 :
return ( V_188 < V_189 ) ;
case V_191 :
return ( V_188 <= V_189 ) ;
case V_192 :
return ( V_188 > V_189 ) ;
case V_193 :
return ( V_188 >= V_189 ) ;
case V_98 :
return ( V_188 & V_189 ) ;
case V_99 :
return ( ( V_188 & V_189 ) == V_189 ) ;
default:
F_98 () ;
return 0 ;
}
}
int F_99 ( T_6 V_188 , T_1 V_43 , T_6 V_189 )
{
switch ( V_43 ) {
case V_44 :
return F_49 ( V_188 , V_189 ) ;
case V_45 :
return ! F_49 ( V_188 , V_189 ) ;
case V_190 :
return F_100 ( V_188 , V_189 ) ;
case V_191 :
return F_101 ( V_188 , V_189 ) ;
case V_192 :
return F_102 ( V_188 , V_189 ) ;
case V_193 :
return F_103 ( V_188 , V_189 ) ;
case V_98 :
case V_99 :
default:
F_98 () ;
return 0 ;
}
}
int F_104 ( T_7 V_188 , T_1 V_43 , T_7 V_189 )
{
switch ( V_43 ) {
case V_44 :
return F_50 ( V_188 , V_189 ) ;
case V_45 :
return ! F_50 ( V_188 , V_189 ) ;
case V_190 :
return F_105 ( V_188 , V_189 ) ;
case V_191 :
return F_106 ( V_188 , V_189 ) ;
case V_192 :
return F_107 ( V_188 , V_189 ) ;
case V_193 :
return F_108 ( V_188 , V_189 ) ;
case V_98 :
case V_99 :
default:
F_98 () ;
return 0 ;
}
}
int F_109 ( const char * V_194 )
{
int V_195 ;
const char * V_48 ;
V_195 = strlen ( V_194 ) ;
if ( V_195 == 0 )
return V_195 ;
V_48 = V_194 + V_195 - 1 ;
while ( ( * V_48 == '/' ) && ( V_48 > V_194 ) )
V_48 -- ;
while ( ( * V_48 != '/' ) && ( V_48 > V_194 ) )
V_48 -- ;
if ( * V_48 == '/' )
V_48 ++ ;
return V_48 - V_194 ;
}
int F_110 ( const char * V_196 , const char * V_194 , int V_197 )
{
int V_198 , V_199 ;
const char * V_48 ;
V_198 = strlen ( V_196 ) ;
V_199 = strlen ( V_194 ) ;
if ( V_199 < V_198 )
return 1 ;
V_197 = V_197 == V_200 ? F_109 ( V_194 ) : V_197 ;
if ( V_199 - V_197 != V_198 )
return 1 ;
V_48 = V_194 + V_197 ;
return strncmp ( V_48 , V_196 , V_198 ) ;
}
int F_111 ( int V_201 , unsigned int V_202 )
{
struct V_15 * V_16 ;
int V_136 = 1 ;
F_112 () ;
if ( F_113 ( & V_148 [ V_202 ] ) )
goto V_203;
F_114 (e, &audit_filter_list[listtype], list) {
int V_17 , V_204 = 0 ;
for ( V_17 = 0 ; V_17 < V_16 -> V_20 . V_23 ; V_17 ++ ) {
struct V_1 * V_2 = & V_16 -> V_20 . V_22 [ V_17 ] ;
T_8 V_205 ;
T_1 V_206 ;
switch ( V_2 -> type ) {
case V_90 :
V_205 = F_115 ( V_174 ) ;
V_204 = F_97 ( V_205 , V_2 -> V_43 , V_2 -> V_59 ) ;
break;
case V_79 :
V_204 = F_99 ( F_116 () , V_2 -> V_43 , V_2 -> V_127 ) ;
break;
case V_85 :
V_204 = F_104 ( F_117 () , V_2 -> V_43 , V_2 -> V_128 ) ;
break;
case V_83 :
V_204 = F_99 ( F_80 ( V_174 ) ,
V_2 -> V_43 , V_2 -> V_127 ) ;
break;
case V_107 :
V_204 = F_97 ( F_118 ( V_174 ) ,
V_2 -> V_43 , V_2 -> V_59 ) ;
break;
case V_78 :
V_204 = F_97 ( V_201 , V_2 -> V_43 , V_2 -> V_59 ) ;
break;
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
if ( V_2 -> V_14 ) {
F_119 ( V_174 , & V_206 ) ;
V_204 = F_120 ( V_206 ,
V_2 -> type , V_2 -> V_43 , V_2 -> V_14 , NULL ) ;
}
break;
default:
goto V_203;
}
if ( V_204 < 0 )
goto V_203;
if ( ! V_204 )
break;
}
if ( V_204 > 0 ) {
if ( V_16 -> V_20 . V_66 == V_72 || V_202 == V_70 )
V_136 = 0 ;
break;
}
}
V_203:
F_121 () ;
return V_136 ;
}
static int F_122 ( struct V_18 * V_166 )
{
struct V_15 * V_28 = F_7 ( V_166 , struct V_15 , V_20 ) ;
struct V_15 * V_207 ;
int V_61 = 0 ;
if ( ! F_123 ( V_166 ) )
return 0 ;
V_207 = F_53 ( V_166 ) ;
if ( V_28 -> V_20 . V_131 )
F_42 ( V_28 -> V_20 . V_131 ) ;
if ( F_29 ( V_207 ) ) {
V_61 = F_39 ( V_207 ) ;
F_124 ( L_9 ) ;
if ( V_166 -> V_21 )
F_73 ( & V_166 -> V_208 ) ;
F_72 ( & V_28 -> V_47 ) ;
F_73 ( & V_166 -> V_47 ) ;
} else {
if ( V_166 -> V_21 || V_166 -> V_42 )
F_125 ( & V_166 -> V_208 , & V_207 -> V_20 . V_208 ) ;
F_126 ( & V_28 -> V_47 , & V_207 -> V_47 ) ;
F_127 ( & V_166 -> V_47 , & V_207 -> V_20 . V_47 ) ;
}
F_74 ( & V_28 -> V_27 , F_6 ) ;
return V_61 ;
}
int F_128 ( void )
{
struct V_18 * V_166 , * V_50 ;
int V_17 , V_61 = 0 ;
F_60 ( & V_152 ) ;
for ( V_17 = 0 ; V_17 < V_167 ; V_17 ++ ) {
F_129 (r, n, &audit_rules_list[i], list) {
int V_169 = F_122 ( V_166 ) ;
if ( ! V_61 )
V_61 = V_169 ;
}
}
F_61 ( & V_152 ) ;
return V_61 ;
}
