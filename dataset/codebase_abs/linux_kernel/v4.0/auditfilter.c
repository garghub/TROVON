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
} ;
return 0 ;
}
static struct V_15 * F_28 ( struct V_60 * V_114 ,
T_2 V_115 )
{
int V_61 = 0 ;
struct V_15 * V_28 ;
void * V_30 ;
T_2 V_31 = V_115 - sizeof( struct V_60 ) ;
int V_17 ;
char * V_33 ;
V_28 = F_23 ( V_114 ) ;
if ( F_29 ( V_28 ) )
goto V_116;
V_30 = V_114 -> V_117 ;
for ( V_17 = 0 ; V_17 < V_114 -> V_23 ; V_17 ++ ) {
struct V_1 * V_2 = & V_28 -> V_20 . V_22 [ V_17 ] ;
V_61 = - V_34 ;
V_2 -> V_43 = F_26 ( V_114 -> V_118 [ V_17 ] ) ;
if ( V_2 -> V_43 == V_76 )
goto V_119;
V_2 -> type = V_114 -> V_22 [ V_17 ] ;
V_2 -> V_59 = V_114 -> V_120 [ V_17 ] ;
if ( ( V_2 -> type == V_83 ) && ( V_2 -> V_59 == V_121 ) ) {
V_2 -> type = V_107 ;
V_2 -> V_59 = 0 ;
V_28 -> V_20 . V_122 |= V_123 ;
}
V_61 = F_27 ( V_28 , V_2 ) ;
if ( V_61 )
goto V_119;
V_61 = - V_34 ;
switch ( V_2 -> type ) {
case V_83 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_84 :
V_2 -> V_124 = F_30 ( F_31 () , V_2 -> V_59 ) ;
if ( ! F_32 ( V_2 -> V_124 ) )
goto V_119;
break;
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
V_2 -> V_125 = F_33 ( F_31 () , V_2 -> V_59 ) ;
if ( ! F_34 ( V_2 -> V_125 ) )
goto V_119;
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
goto V_119;
V_28 -> V_20 . V_126 += V_2 -> V_59 ;
V_61 = F_35 ( V_2 -> type , V_2 -> V_43 , V_33 ,
( void * * ) & V_2 -> V_14 ) ;
if ( V_61 == - V_34 ) {
F_36 ( L_2 ,
V_33 ) ;
V_61 = 0 ;
}
if ( V_61 ) {
F_2 ( V_33 ) ;
goto V_119;
} else
V_2 -> V_13 = V_33 ;
break;
case V_104 :
V_33 = F_12 ( & V_30 , & V_31 , V_2 -> V_59 ) ;
if ( F_29 ( V_33 ) )
goto V_119;
V_28 -> V_20 . V_126 += V_2 -> V_59 ;
V_61 = F_37 ( & V_28 -> V_20 , V_33 , V_2 -> V_59 , V_2 -> V_43 ) ;
if ( V_61 ) {
F_2 ( V_33 ) ;
goto V_119;
}
break;
case V_105 :
V_33 = F_12 ( & V_30 , & V_31 , V_2 -> V_59 ) ;
if ( F_29 ( V_33 ) )
goto V_119;
V_28 -> V_20 . V_126 += V_2 -> V_59 ;
V_61 = F_38 ( & V_28 -> V_20 , V_33 , V_2 -> V_43 ) ;
F_2 ( V_33 ) ;
if ( V_61 )
goto V_119;
break;
case V_97 :
V_61 = F_15 ( & V_28 -> V_20 , V_2 ) ;
if ( V_61 )
goto V_119;
break;
case V_106 :
if ( V_28 -> V_20 . V_24 || V_2 -> V_59 > V_127 )
goto V_119;
V_33 = F_12 ( & V_30 , & V_31 , V_2 -> V_59 ) ;
if ( F_29 ( V_33 ) )
goto V_119;
V_28 -> V_20 . V_126 += V_2 -> V_59 ;
V_28 -> V_20 . V_24 = V_33 ;
break;
}
}
if ( V_28 -> V_20 . V_41 && V_28 -> V_20 . V_41 -> V_43 == V_45 )
V_28 -> V_20 . V_41 = NULL ;
V_116:
return V_28 ;
V_119:
if ( V_28 -> V_20 . V_21 )
F_5 ( V_28 -> V_20 . V_21 ) ;
if ( V_28 -> V_20 . V_42 )
F_39 ( V_28 -> V_20 . V_42 ) ;
F_4 ( V_28 ) ;
return F_13 ( V_61 ) ;
}
static inline T_2 F_40 ( void * * V_30 , const char * V_33 )
{
T_2 V_32 = strlen ( V_33 ) ;
memcpy ( * V_30 , V_33 , V_32 ) ;
* V_30 += V_32 ;
return V_32 ;
}
static struct V_60 * F_41 ( struct V_18 * V_38 )
{
struct V_60 * V_114 ;
void * V_30 ;
int V_17 ;
V_114 = F_14 ( sizeof( * V_114 ) + V_38 -> V_126 , V_29 ) ;
if ( F_10 ( ! V_114 ) )
return NULL ;
memset ( V_114 , 0 , sizeof( * V_114 ) ) ;
V_114 -> V_62 = V_38 -> V_62 | V_38 -> V_39 ;
V_114 -> V_66 = V_38 -> V_66 ;
V_114 -> V_23 = V_38 -> V_23 ;
V_30 = V_114 -> V_117 ;
for ( V_17 = 0 ; V_17 < V_114 -> V_23 ; V_17 ++ ) {
struct V_1 * V_2 = & V_38 -> V_22 [ V_17 ] ;
V_114 -> V_22 [ V_17 ] = V_2 -> type ;
V_114 -> V_118 [ V_17 ] = V_77 [ V_2 -> V_43 ] ;
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
V_114 -> V_126 += V_114 -> V_120 [ V_17 ] =
F_40 ( & V_30 , V_2 -> V_13 ) ;
break;
case V_104 :
V_114 -> V_126 += V_114 -> V_120 [ V_17 ] =
F_40 ( & V_30 ,
F_42 ( V_38 -> V_21 ) ) ;
break;
case V_105 :
V_114 -> V_126 += V_114 -> V_120 [ V_17 ] =
F_40 ( & V_30 ,
F_43 ( V_38 -> V_42 ) ) ;
break;
case V_106 :
V_114 -> V_126 += V_114 -> V_120 [ V_17 ] =
F_40 ( & V_30 , V_38 -> V_24 ) ;
break;
case V_107 :
if ( V_38 -> V_122 & V_123 && ! V_2 -> V_59 ) {
V_114 -> V_22 [ V_17 ] = V_83 ;
V_114 -> V_120 [ V_17 ] = V_121 ;
break;
}
default:
V_114 -> V_120 [ V_17 ] = V_2 -> V_59 ;
}
}
for ( V_17 = 0 ; V_17 < V_49 ; V_17 ++ ) V_114 -> V_54 [ V_17 ] = V_38 -> V_54 [ V_17 ] ;
return V_114 ;
}
static int F_44 ( struct V_18 * V_128 , struct V_18 * V_129 )
{
int V_17 ;
if ( V_128 -> V_62 != V_129 -> V_62 ||
V_128 -> V_122 != V_129 -> V_122 ||
V_128 -> V_39 != V_129 -> V_39 ||
V_128 -> V_66 != V_129 -> V_66 ||
V_128 -> V_23 != V_129 -> V_23 )
return 1 ;
for ( V_17 = 0 ; V_17 < V_128 -> V_23 ; V_17 ++ ) {
if ( V_128 -> V_22 [ V_17 ] . type != V_129 -> V_22 [ V_17 ] . type ||
V_128 -> V_22 [ V_17 ] . V_43 != V_129 -> V_22 [ V_17 ] . V_43 )
return 1 ;
switch( V_128 -> V_22 [ V_17 ] . type ) {
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
if ( strcmp ( V_128 -> V_22 [ V_17 ] . V_13 , V_129 -> V_22 [ V_17 ] . V_13 ) )
return 1 ;
break;
case V_104 :
if ( strcmp ( F_42 ( V_128 -> V_21 ) ,
F_42 ( V_129 -> V_21 ) ) )
return 1 ;
break;
case V_105 :
if ( strcmp ( F_43 ( V_128 -> V_42 ) ,
F_43 ( V_129 -> V_42 ) ) )
return 1 ;
break;
case V_106 :
if ( strcmp ( V_128 -> V_24 , V_129 -> V_24 ) )
return 1 ;
break;
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
if ( ! F_45 ( V_128 -> V_22 [ V_17 ] . V_124 , V_129 -> V_22 [ V_17 ] . V_124 ) )
return 1 ;
break;
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
if ( ! F_46 ( V_128 -> V_22 [ V_17 ] . V_125 , V_129 -> V_22 [ V_17 ] . V_125 ) )
return 1 ;
break;
default:
if ( V_128 -> V_22 [ V_17 ] . V_59 != V_129 -> V_22 [ V_17 ] . V_59 )
return 1 ;
}
}
for ( V_17 = 0 ; V_17 < V_49 ; V_17 ++ )
if ( V_128 -> V_54 [ V_17 ] != V_129 -> V_54 [ V_17 ] )
return 1 ;
return 0 ;
}
static inline int F_47 ( struct V_1 * V_130 ,
struct V_1 * V_131 )
{
int V_132 = 0 ;
char * V_13 ;
V_13 = F_48 ( V_131 -> V_13 , V_29 ) ;
if ( F_10 ( ! V_13 ) )
return - V_37 ;
V_130 -> V_13 = V_13 ;
V_132 = F_35 ( V_130 -> type , V_130 -> V_43 , V_130 -> V_13 ,
( void * * ) & V_130 -> V_14 ) ;
if ( V_132 == - V_34 ) {
F_36 ( L_2 ,
V_130 -> V_13 ) ;
V_132 = 0 ;
}
return V_132 ;
}
struct V_15 * F_49 ( struct V_18 * V_133 )
{
T_1 V_134 = V_133 -> V_23 ;
struct V_15 * V_28 ;
struct V_18 * V_135 ;
char * V_136 ;
int V_17 , V_61 = 0 ;
V_28 = F_8 ( V_134 ) ;
if ( F_10 ( ! V_28 ) )
return F_13 ( - V_37 ) ;
V_135 = & V_28 -> V_20 ;
V_135 -> V_62 = V_133 -> V_62 ;
V_135 -> V_122 = V_133 -> V_122 ;
V_135 -> V_39 = V_133 -> V_39 ;
V_135 -> V_66 = V_133 -> V_66 ;
for ( V_17 = 0 ; V_17 < V_49 ; V_17 ++ )
V_135 -> V_54 [ V_17 ] = V_133 -> V_54 [ V_17 ] ;
V_135 -> V_137 = V_133 -> V_137 ;
V_135 -> V_126 = V_133 -> V_126 ;
V_135 -> V_41 = V_133 -> V_41 ;
V_135 -> V_23 = V_133 -> V_23 ;
V_135 -> V_42 = V_133 -> V_42 ;
memcpy ( V_135 -> V_22 , V_133 -> V_22 , sizeof( struct V_1 ) * V_134 ) ;
for ( V_17 = 0 ; V_17 < V_134 ; V_17 ++ ) {
switch ( V_135 -> V_22 [ V_17 ] . type ) {
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
V_61 = F_47 ( & V_135 -> V_22 [ V_17 ] ,
& V_133 -> V_22 [ V_17 ] ) ;
break;
case V_106 :
V_136 = F_48 ( V_133 -> V_24 , V_29 ) ;
if ( F_10 ( ! V_136 ) )
V_61 = - V_37 ;
else
V_135 -> V_24 = V_136 ;
}
if ( V_61 ) {
F_4 ( V_28 ) ;
return F_13 ( V_61 ) ;
}
}
if ( V_133 -> V_21 ) {
F_50 ( V_133 -> V_21 ) ;
V_135 -> V_21 = V_133 -> V_21 ;
}
return V_28 ;
}
static struct V_15 * F_51 ( struct V_15 * V_28 ,
struct V_138 * * V_48 )
{
struct V_15 * V_16 , * V_139 = NULL ;
struct V_138 * V_47 ;
int V_140 ;
if ( V_28 -> V_20 . V_41 ) {
V_140 = F_52 ( V_28 -> V_20 . V_41 -> V_59 ) ;
* V_48 = V_47 = & V_141 [ V_140 ] ;
} else if ( V_28 -> V_20 . V_21 ) {
for ( V_140 = 0 ; V_140 < V_142 ; V_140 ++ ) {
V_47 = & V_141 [ V_140 ] ;
F_53 (e, list, list)
if ( ! F_44 ( & V_28 -> V_20 , & V_16 -> V_20 ) ) {
V_139 = V_16 ;
goto V_143;
}
}
goto V_143;
} else {
* V_48 = V_47 = & V_144 [ V_28 -> V_20 . V_39 ] ;
}
F_53 (e, list, list)
if ( ! F_44 ( & V_28 -> V_20 , & V_16 -> V_20 ) ) {
V_139 = V_16 ;
goto V_143;
}
V_143:
return V_139 ;
}
static inline int F_54 ( struct V_15 * V_28 )
{
struct V_15 * V_16 ;
struct V_145 * V_21 = V_28 -> V_20 . V_21 ;
struct V_146 * V_42 = V_28 -> V_20 . V_42 ;
struct V_138 * V_47 ;
int V_61 ;
#ifdef F_24
int V_147 = 0 ;
if ( V_28 -> V_20 . V_39 == V_69 ||
V_28 -> V_20 . V_39 == V_70 )
V_147 = 1 ;
#endif
F_55 ( & V_148 ) ;
V_16 = F_51 ( V_28 , & V_47 ) ;
if ( V_16 ) {
F_56 ( & V_148 ) ;
V_61 = - V_149 ;
if ( V_42 )
F_39 ( V_42 ) ;
goto error;
}
if ( V_21 ) {
V_61 = F_57 ( & V_28 -> V_20 , & V_47 ) ;
if ( V_61 ) {
F_56 ( & V_148 ) ;
if ( V_42 )
F_39 ( V_42 ) ;
goto error;
}
}
if ( V_42 ) {
V_61 = F_58 ( & V_28 -> V_20 ) ;
if ( V_61 ) {
F_56 ( & V_148 ) ;
goto error;
}
}
V_28 -> V_20 . V_137 = ~ 0ULL ;
if ( V_28 -> V_20 . V_39 == V_40 ) {
if ( V_28 -> V_20 . V_62 & V_63 )
V_28 -> V_20 . V_137 = ++ V_150 ;
else
V_28 -> V_20 . V_137 = -- V_151 ;
}
if ( V_28 -> V_20 . V_62 & V_63 ) {
F_59 ( & V_28 -> V_20 . V_47 ,
& V_152 [ V_28 -> V_20 . V_39 ] ) ;
F_60 ( & V_28 -> V_47 , V_47 ) ;
V_28 -> V_20 . V_62 &= ~ V_63 ;
} else {
F_61 ( & V_28 -> V_20 . V_47 ,
& V_152 [ V_28 -> V_20 . V_39 ] ) ;
F_62 ( & V_28 -> V_47 , V_47 ) ;
}
#ifdef F_24
if ( ! V_147 )
V_153 ++ ;
if ( ! F_21 ( V_28 ) )
V_154 ++ ;
#endif
F_56 ( & V_148 ) ;
return 0 ;
error:
if ( V_21 )
F_5 ( V_21 ) ;
return V_61 ;
}
static inline int F_63 ( struct V_15 * V_28 )
{
struct V_15 * V_16 ;
struct V_145 * V_21 = V_28 -> V_20 . V_21 ;
struct V_146 * V_42 = V_28 -> V_20 . V_42 ;
struct V_138 * V_47 ;
int V_132 = 0 ;
#ifdef F_24
int V_147 = 0 ;
if ( V_28 -> V_20 . V_39 == V_69 ||
V_28 -> V_20 . V_39 == V_70 )
V_147 = 1 ;
#endif
F_55 ( & V_148 ) ;
V_16 = F_51 ( V_28 , & V_47 ) ;
if ( ! V_16 ) {
F_56 ( & V_148 ) ;
V_132 = - V_155 ;
goto V_143;
}
if ( V_16 -> V_20 . V_21 )
F_64 ( & V_16 -> V_20 ) ;
if ( V_16 -> V_20 . V_42 )
F_65 ( & V_16 -> V_20 ) ;
F_66 ( & V_16 -> V_47 ) ;
F_67 ( & V_16 -> V_20 . V_47 ) ;
F_68 ( & V_16 -> V_27 , F_6 ) ;
#ifdef F_24
if ( ! V_147 )
V_153 -- ;
if ( ! F_21 ( V_28 ) )
V_154 -- ;
#endif
F_56 ( & V_148 ) ;
V_143:
if ( V_21 )
F_5 ( V_21 ) ;
if ( V_42 )
F_39 ( V_42 ) ;
return V_132 ;
}
static void F_69 ( T_4 V_156 , int V_157 , struct V_158 * V_159 )
{
struct V_160 * V_161 ;
struct V_18 * V_162 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_163 ; V_17 ++ ) {
F_53 (r, &audit_rules_list[i], list) {
struct V_60 * V_114 ;
V_114 = F_41 ( V_162 ) ;
if ( F_10 ( ! V_114 ) )
break;
V_161 = F_70 ( V_156 , V_157 , V_164 ,
0 , 1 , V_114 ,
sizeof( * V_114 ) + V_114 -> V_126 ) ;
if ( V_161 )
F_71 ( V_159 , V_161 ) ;
F_2 ( V_114 ) ;
}
}
V_161 = F_70 ( V_156 , V_157 , V_164 , 1 , 1 , NULL , 0 ) ;
if ( V_161 )
F_71 ( V_159 , V_161 ) ;
}
static void F_72 ( char * V_66 , struct V_18 * V_20 , int V_165 )
{
struct V_166 * V_167 ;
T_5 V_168 = F_73 ( & V_169 , F_74 ( V_170 ) ) ;
unsigned int V_171 = F_75 ( V_170 ) ;
if ( ! V_172 )
return;
V_167 = F_76 ( NULL , V_29 , V_173 ) ;
if ( ! V_167 )
return;
F_77 ( V_167 , L_3 , V_168 , V_171 ) ;
F_78 ( V_167 ) ;
F_77 ( V_167 , L_4 ) ;
F_79 ( V_167 , V_66 ) ;
F_80 ( V_167 , V_20 -> V_24 ) ;
F_77 ( V_167 , L_5 , V_20 -> V_39 , V_165 ) ;
F_81 ( V_167 ) ;
}
int F_82 ( int type , T_4 V_156 , int V_157 , void * V_114 ,
T_2 V_115 )
{
int V_61 = 0 ;
struct V_15 * V_28 ;
V_28 = F_28 ( V_114 , V_115 ) ;
if ( F_29 ( V_28 ) )
return F_83 ( V_28 ) ;
switch ( type ) {
case V_174 :
V_61 = F_54 ( V_28 ) ;
F_72 ( L_6 , & V_28 -> V_20 , ! V_61 ) ;
break;
case V_175 :
V_61 = F_63 ( V_28 ) ;
F_72 ( L_7 , & V_28 -> V_20 , ! V_61 ) ;
break;
default:
V_61 = - V_34 ;
F_84 ( 1 ) ;
}
if ( V_61 || type == V_175 )
F_4 ( V_28 ) ;
return V_61 ;
}
int F_85 ( struct V_160 * V_176 , int V_157 )
{
T_1 V_156 = F_86 ( V_176 ) . V_156 ;
struct V_177 * V_177 = F_87 ( F_86 ( V_176 ) . V_178 ) ;
struct V_179 * V_180 ;
struct V_181 * V_182 ;
int V_61 = 0 ;
V_182 = F_14 ( sizeof( struct V_181 ) , V_29 ) ;
if ( ! V_182 )
return - V_37 ;
V_182 -> V_177 = F_88 ( V_177 ) ;
V_182 -> V_156 = V_156 ;
F_89 ( & V_182 -> V_159 ) ;
F_55 ( & V_148 ) ;
F_69 ( V_156 , V_157 , & V_182 -> V_159 ) ;
F_56 ( & V_148 ) ;
V_180 = F_90 ( V_183 , V_182 , L_8 ) ;
if ( F_29 ( V_180 ) ) {
F_91 ( & V_182 -> V_159 ) ;
F_2 ( V_182 ) ;
V_61 = F_83 ( V_180 ) ;
}
return V_61 ;
}
int F_92 ( T_1 V_184 , T_1 V_43 , T_1 V_185 )
{
switch ( V_43 ) {
case V_44 :
return ( V_184 == V_185 ) ;
case V_45 :
return ( V_184 != V_185 ) ;
case V_186 :
return ( V_184 < V_185 ) ;
case V_187 :
return ( V_184 <= V_185 ) ;
case V_188 :
return ( V_184 > V_185 ) ;
case V_189 :
return ( V_184 >= V_185 ) ;
case V_98 :
return ( V_184 & V_185 ) ;
case V_99 :
return ( ( V_184 & V_185 ) == V_185 ) ;
default:
F_93 () ;
return 0 ;
}
}
int F_94 ( T_6 V_184 , T_1 V_43 , T_6 V_185 )
{
switch ( V_43 ) {
case V_44 :
return F_45 ( V_184 , V_185 ) ;
case V_45 :
return ! F_45 ( V_184 , V_185 ) ;
case V_186 :
return F_95 ( V_184 , V_185 ) ;
case V_187 :
return F_96 ( V_184 , V_185 ) ;
case V_188 :
return F_97 ( V_184 , V_185 ) ;
case V_189 :
return F_98 ( V_184 , V_185 ) ;
case V_98 :
case V_99 :
default:
F_93 () ;
return 0 ;
}
}
int F_99 ( T_7 V_184 , T_1 V_43 , T_7 V_185 )
{
switch ( V_43 ) {
case V_44 :
return F_46 ( V_184 , V_185 ) ;
case V_45 :
return ! F_46 ( V_184 , V_185 ) ;
case V_186 :
return F_100 ( V_184 , V_185 ) ;
case V_187 :
return F_101 ( V_184 , V_185 ) ;
case V_188 :
return F_102 ( V_184 , V_185 ) ;
case V_189 :
return F_103 ( V_184 , V_185 ) ;
case V_98 :
case V_99 :
default:
F_93 () ;
return 0 ;
}
}
int F_104 ( const char * V_190 )
{
int V_191 ;
const char * V_48 ;
V_191 = strlen ( V_190 ) ;
if ( V_191 == 0 )
return V_191 ;
V_48 = V_190 + V_191 - 1 ;
while ( ( * V_48 == '/' ) && ( V_48 > V_190 ) )
V_48 -- ;
while ( ( * V_48 != '/' ) && ( V_48 > V_190 ) )
V_48 -- ;
if ( * V_48 == '/' )
V_48 ++ ;
return V_48 - V_190 ;
}
int F_105 ( const char * V_192 , const char * V_190 , int V_193 )
{
int V_194 , V_195 ;
const char * V_48 ;
V_194 = strlen ( V_192 ) ;
V_195 = strlen ( V_190 ) ;
if ( V_195 < V_194 )
return 1 ;
V_193 = V_193 == V_196 ? F_104 ( V_190 ) : V_193 ;
if ( V_195 - V_193 != V_194 )
return 1 ;
V_48 = V_190 + V_193 ;
return strncmp ( V_48 , V_192 , V_194 ) ;
}
static int F_106 ( struct V_18 * V_20 , int type ,
enum V_197 * V_198 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_20 -> V_23 ; V_17 ++ ) {
struct V_1 * V_2 = & V_20 -> V_22 [ V_17 ] ;
T_8 V_199 ;
int V_200 = 0 ;
T_1 V_201 ;
switch ( V_2 -> type ) {
case V_90 :
V_199 = F_107 ( V_170 ) ;
V_200 = F_92 ( V_199 , V_2 -> V_43 , V_2 -> V_59 ) ;
break;
case V_79 :
V_200 = F_94 ( F_108 () , V_2 -> V_43 , V_2 -> V_124 ) ;
break;
case V_85 :
V_200 = F_99 ( F_109 () , V_2 -> V_43 , V_2 -> V_125 ) ;
break;
case V_83 :
V_200 = F_94 ( F_74 ( V_170 ) ,
V_2 -> V_43 , V_2 -> V_124 ) ;
break;
case V_107 :
V_200 = F_92 ( F_110 ( V_170 ) ,
V_2 -> V_43 , V_2 -> V_59 ) ;
break;
case V_78 :
V_200 = F_92 ( type , V_2 -> V_43 , V_2 -> V_59 ) ;
break;
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
if ( V_2 -> V_14 ) {
F_111 ( V_170 , & V_201 ) ;
V_200 = F_112 ( V_201 ,
V_2 -> type ,
V_2 -> V_43 ,
V_2 -> V_14 ,
NULL ) ;
}
break;
}
if ( ! V_200 )
return 0 ;
}
switch ( V_20 -> V_66 ) {
case V_72 : * V_198 = V_202 ; break;
case V_67 : * V_198 = V_203 ; break;
}
return 1 ;
}
int F_113 ( int type )
{
enum V_197 V_198 = V_202 ;
struct V_15 * V_16 ;
int V_204 , V_132 ;
V_132 = 1 ;
F_114 () ;
F_115 (e, &audit_filter_list[AUDIT_FILTER_USER], list) {
V_204 = F_106 ( & V_16 -> V_20 , type , & V_198 ) ;
if ( V_204 ) {
if ( V_204 > 0 && V_198 == V_202 )
V_132 = 0 ;
break;
}
}
F_116 () ;
return V_132 ;
}
int F_117 ( int type )
{
struct V_15 * V_16 ;
int V_200 = 0 ;
F_114 () ;
if ( F_118 ( & V_144 [ V_70 ] ) )
goto V_205;
F_115 (e, &audit_filter_list[AUDIT_FILTER_TYPE],
list) {
int V_17 ;
for ( V_17 = 0 ; V_17 < V_16 -> V_20 . V_23 ; V_17 ++ ) {
struct V_1 * V_2 = & V_16 -> V_20 . V_22 [ V_17 ] ;
if ( V_2 -> type == V_78 ) {
V_200 = F_92 ( type , V_2 -> V_43 , V_2 -> V_59 ) ;
if ( ! V_200 )
break;
}
}
if ( V_200 )
goto V_205;
}
V_205:
F_116 () ;
return V_200 ;
}
static int F_119 ( struct V_18 * V_162 )
{
struct V_15 * V_28 = F_7 ( V_162 , struct V_15 , V_20 ) ;
struct V_15 * V_206 ;
int V_61 = 0 ;
if ( ! F_120 ( V_162 ) )
return 0 ;
V_206 = F_49 ( V_162 ) ;
if ( F_29 ( V_206 ) ) {
V_61 = F_83 ( V_206 ) ;
F_121 ( L_9 ) ;
if ( V_162 -> V_21 )
F_67 ( & V_162 -> V_207 ) ;
F_66 ( & V_28 -> V_47 ) ;
F_67 ( & V_162 -> V_47 ) ;
} else {
if ( V_162 -> V_21 || V_162 -> V_42 )
F_122 ( & V_162 -> V_207 , & V_206 -> V_20 . V_207 ) ;
F_123 ( & V_28 -> V_47 , & V_206 -> V_47 ) ;
F_124 ( & V_162 -> V_47 , & V_206 -> V_20 . V_47 ) ;
}
F_68 ( & V_28 -> V_27 , F_6 ) ;
return V_61 ;
}
int F_125 ( void )
{
struct V_18 * V_162 , * V_50 ;
int V_17 , V_61 = 0 ;
F_55 ( & V_148 ) ;
for ( V_17 = 0 ; V_17 < V_163 ; V_17 ++ ) {
F_126 (r, n, &audit_rules_list[i], list) {
int V_165 = F_119 ( V_162 ) ;
if ( ! V_61 )
V_61 = V_165 ;
}
}
F_56 ( & V_148 ) ;
return V_61 ;
}
