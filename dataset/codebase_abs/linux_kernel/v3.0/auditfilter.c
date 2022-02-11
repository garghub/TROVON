static inline void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
if ( V_5 -> V_7 )
F_2 ( V_5 -> V_7 ) ;
if ( V_5 -> V_8 )
for ( V_3 = 0 ; V_3 < V_5 -> V_9 ; V_3 ++ ) {
struct V_10 * V_11 = & V_5 -> V_8 [ V_3 ] ;
F_3 ( V_11 -> V_12 ) ;
F_4 ( V_11 -> V_13 ) ;
}
F_3 ( V_5 -> V_8 ) ;
F_3 ( V_5 -> V_14 ) ;
F_3 ( V_2 ) ;
}
void F_5 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_6 ( V_16 , struct V_1 , V_17 ) ;
F_1 ( V_2 ) ;
}
static inline struct V_1 * F_7 ( T_1 V_9 )
{
struct V_1 * V_18 ;
struct V_10 * V_8 ;
V_18 = F_8 ( sizeof( * V_18 ) , V_19 ) ;
if ( F_9 ( ! V_18 ) )
return NULL ;
V_8 = F_8 ( sizeof( * V_8 ) * V_9 , V_19 ) ;
if ( F_9 ( ! V_8 ) ) {
F_3 ( V_18 ) ;
return NULL ;
}
V_18 -> V_6 . V_8 = V_8 ;
return V_18 ;
}
char * F_10 ( void * * V_20 , T_2 * V_21 , T_2 V_22 )
{
char * V_23 ;
if ( ! * V_20 || ( V_22 == 0 ) || ( V_22 > * V_21 ) )
return F_11 ( - V_24 ) ;
if ( V_22 > V_25 )
return F_11 ( - V_26 ) ;
V_23 = F_12 ( V_22 + 1 , V_19 ) ;
if ( F_9 ( ! V_23 ) )
return F_11 ( - V_27 ) ;
memcpy ( V_23 , * V_20 , V_22 ) ;
V_23 [ V_22 ] = 0 ;
* V_20 += V_22 ;
* V_21 -= V_22 ;
return V_23 ;
}
static inline int F_13 ( struct V_4 * V_28 ,
struct V_10 * V_11 )
{
if ( V_28 -> V_29 != V_30 ||
V_28 -> V_7 || V_28 -> V_31 || V_28 -> V_32 ||
( V_11 -> V_33 != V_34 && V_11 -> V_33 != V_35 ) )
return - V_24 ;
V_28 -> V_31 = V_11 ;
return 0 ;
}
int T_3 F_14 ( int V_36 , unsigned * V_37 )
{
T_4 * V_38 = F_8 ( V_39 * sizeof( T_4 ) , V_19 ) ;
if ( ! V_38 )
return - V_27 ;
while ( * V_37 != ~ 0U ) {
unsigned V_40 = * V_37 ++ ;
if ( V_40 >= V_39 * 32 - V_41 ) {
F_3 ( V_38 ) ;
return - V_24 ;
}
V_38 [ F_15 ( V_40 ) ] |= F_16 ( V_40 ) ;
}
if ( V_36 >= V_41 || V_42 [ V_36 ] ) {
F_3 ( V_38 ) ;
return - V_24 ;
}
V_42 [ V_36 ] = V_38 ;
return 0 ;
}
int F_17 ( int V_36 , unsigned V_43 )
{
if ( F_9 ( V_43 >= V_39 * 32 ) )
return 0 ;
if ( F_9 ( V_36 >= V_41 || ! V_42 [ V_36 ] ) )
return 0 ;
return V_42 [ V_36 ] [ F_15 ( V_43 ) ] & F_16 ( V_43 ) ;
}
static inline int F_18 ( int V_36 , T_1 * V_44 )
{
int V_3 ;
if ( V_42 [ V_36 ] ) {
for ( V_3 = 0 ; V_3 < V_39 ; V_3 ++ )
if ( V_44 [ V_3 ] & V_42 [ V_36 ] [ V_3 ] )
return 0 ;
}
return 1 ;
}
static int F_19 ( struct V_1 * V_18 )
{
struct V_10 * V_45 = V_18 -> V_6 . V_46 ;
if ( ! V_45 ) {
return ( F_18 ( V_47 ,
V_18 -> V_6 . V_44 ) &&
F_18 ( V_48 ,
V_18 -> V_6 . V_44 ) ) ;
}
switch( F_20 ( V_45 -> V_49 ) ) {
case 0 :
return ( F_18 ( V_47 ,
V_18 -> V_6 . V_44 ) ) ;
case 1 :
return ( F_18 ( V_48 ,
V_18 -> V_6 . V_44 ) ) ;
default:
return 1 ;
}
}
static inline struct V_1 * F_21 ( struct V_50 * V_6 )
{
unsigned V_29 ;
struct V_1 * V_18 ;
int V_3 , V_51 ;
V_51 = - V_24 ;
V_29 = V_6 -> V_52 & ~ V_53 ;
switch( V_29 ) {
default:
goto V_54;
case V_55 :
case V_56 :
#ifdef F_22
case V_57 :
case V_30 :
case V_58 :
#endif
;
}
if ( F_9 ( V_6 -> V_59 == V_60 ) ) {
F_23 ( V_61 L_1 ) ;
goto V_54;
}
if ( V_6 -> V_59 != V_62 && V_6 -> V_59 != V_63 )
goto V_54;
if ( V_6 -> V_9 > V_64 )
goto V_54;
V_51 = - V_27 ;
V_18 = F_7 ( V_6 -> V_9 ) ;
if ( ! V_18 )
goto V_54;
V_18 -> V_6 . V_52 = V_6 -> V_52 & V_53 ;
V_18 -> V_6 . V_29 = V_29 ;
V_18 -> V_6 . V_59 = V_6 -> V_59 ;
V_18 -> V_6 . V_9 = V_6 -> V_9 ;
for ( V_3 = 0 ; V_3 < V_39 ; V_3 ++ )
V_18 -> V_6 . V_44 [ V_3 ] = V_6 -> V_44 [ V_3 ] ;
for ( V_3 = 0 ; V_3 < V_41 ; V_3 ++ ) {
int V_65 = V_39 * 32 - V_3 - 1 ;
T_4 * V_38 = & V_18 -> V_6 . V_44 [ F_15 ( V_65 ) ] ;
T_4 * V_36 ;
if ( ! ( * V_38 & F_16 ( V_65 ) ) )
continue;
* V_38 &= ~ F_16 ( V_65 ) ;
V_36 = V_42 [ V_3 ] ;
if ( V_36 ) {
int V_66 ;
for ( V_66 = 0 ; V_66 < V_39 ; V_66 ++ )
V_18 -> V_6 . V_44 [ V_66 ] |= V_36 [ V_66 ] ;
}
}
return V_18 ;
V_54:
return F_11 ( V_51 ) ;
}
static T_1 F_24 ( T_1 V_33 )
{
T_1 V_40 ;
for ( V_40 = V_34 ; V_40 < V_67 && V_68 [ V_40 ] != V_33 ; V_40 ++ )
;
return V_40 ;
}
static struct V_1 * F_25 ( struct V_50 * V_6 )
{
struct V_1 * V_18 ;
int V_51 = 0 ;
int V_3 ;
V_18 = F_21 ( V_6 ) ;
if ( F_26 ( V_18 ) )
goto V_69;
for ( V_3 = 0 ; V_3 < V_6 -> V_9 ; V_3 ++ ) {
struct V_10 * V_11 = & V_18 -> V_6 . V_8 [ V_3 ] ;
T_1 V_40 ;
V_40 = V_6 -> V_8 [ V_3 ] & ( V_70 | V_71 ) ;
if ( V_40 & V_70 )
V_11 -> V_33 = V_35 ;
else if ( ! V_40 )
V_11 -> V_33 = V_34 ;
else
V_11 -> V_33 = F_24 ( V_40 ) ;
V_18 -> V_6 . V_72 = ( V_40 & V_71 ) ? 2 : 1 ;
V_11 -> type = V_6 -> V_8 [ V_3 ] & ~ ( V_70 | V_71 ) ;
V_11 -> V_49 = V_6 -> V_73 [ V_3 ] ;
V_51 = - V_24 ;
if ( V_11 -> V_33 == V_67 )
goto V_74;
switch( V_11 -> type ) {
default:
goto V_74;
case V_75 :
case V_76 :
case V_77 :
case V_78 :
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
if ( V_11 -> V_33 == V_92 || V_11 -> V_33 == V_93 )
goto V_74;
break;
case V_94 :
case V_95 :
case V_96 :
case V_97 :
break;
case V_98 :
if ( V_11 -> V_33 != V_35 && V_11 -> V_33 != V_34 )
goto V_74;
V_18 -> V_6 . V_46 = V_11 ;
break;
case V_99 :
if ( V_11 -> V_49 & ~ 15 )
goto V_74;
break;
case V_100 :
if ( ( V_11 -> V_49 & ~ V_101 ) > V_101 )
goto V_74;
break;
case V_102 :
V_51 = F_13 ( & V_18 -> V_6 , V_11 ) ;
if ( V_51 )
goto V_74;
break;
}
}
if ( V_18 -> V_6 . V_31 && V_18 -> V_6 . V_31 -> V_33 == V_35 )
V_18 -> V_6 . V_31 = NULL ;
V_69:
return V_18 ;
V_74:
F_1 ( V_18 ) ;
return F_11 ( V_51 ) ;
}
static struct V_1 * F_27 ( struct V_103 * V_104 ,
T_2 V_105 )
{
int V_51 = 0 ;
struct V_1 * V_18 ;
void * V_20 ;
T_2 V_21 = V_105 - sizeof( struct V_103 ) ;
int V_3 ;
char * V_23 ;
V_18 = F_21 ( (struct V_50 * ) V_104 ) ;
if ( F_26 ( V_18 ) )
goto V_69;
V_20 = V_104 -> V_106 ;
V_18 -> V_6 . V_72 = 2 ;
for ( V_3 = 0 ; V_3 < V_104 -> V_9 ; V_3 ++ ) {
struct V_10 * V_11 = & V_18 -> V_6 . V_8 [ V_3 ] ;
V_51 = - V_24 ;
V_11 -> V_33 = F_24 ( V_104 -> V_107 [ V_3 ] ) ;
if ( V_11 -> V_33 == V_67 )
goto V_74;
V_11 -> type = V_104 -> V_8 [ V_3 ] ;
V_11 -> V_49 = V_104 -> V_73 [ V_3 ] ;
V_11 -> V_12 = NULL ;
V_11 -> V_13 = NULL ;
switch( V_11 -> type ) {
case V_75 :
case V_76 :
case V_77 :
case V_78 :
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
case V_94 :
case V_95 :
case V_96 :
case V_97 :
break;
case V_98 :
V_18 -> V_6 . V_46 = V_11 ;
break;
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
V_23 = F_10 ( & V_20 , & V_21 , V_11 -> V_49 ) ;
if ( F_26 ( V_23 ) )
goto V_74;
V_18 -> V_6 . V_118 += V_11 -> V_49 ;
V_51 = F_28 ( V_11 -> type , V_11 -> V_33 , V_23 ,
( void * * ) & V_11 -> V_13 ) ;
if ( V_51 == - V_24 ) {
F_23 ( V_119 L_2
L_3 , V_23 ) ;
V_51 = 0 ;
}
if ( V_51 ) {
F_3 ( V_23 ) ;
goto V_74;
} else
V_11 -> V_12 = V_23 ;
break;
case V_120 :
V_23 = F_10 ( & V_20 , & V_21 , V_11 -> V_49 ) ;
if ( F_26 ( V_23 ) )
goto V_74;
V_18 -> V_6 . V_118 += V_11 -> V_49 ;
V_51 = F_29 ( & V_18 -> V_6 , V_23 , V_11 -> V_49 , V_11 -> V_33 ) ;
if ( V_51 ) {
F_3 ( V_23 ) ;
goto V_74;
}
break;
case V_121 :
V_23 = F_10 ( & V_20 , & V_21 , V_11 -> V_49 ) ;
if ( F_26 ( V_23 ) )
goto V_74;
V_18 -> V_6 . V_118 += V_11 -> V_49 ;
V_51 = F_30 ( & V_18 -> V_6 , V_23 , V_11 -> V_33 ) ;
F_3 ( V_23 ) ;
if ( V_51 )
goto V_74;
break;
case V_102 :
V_51 = F_13 ( & V_18 -> V_6 , V_11 ) ;
if ( V_51 )
goto V_74;
break;
case V_122 :
V_51 = - V_24 ;
if ( V_18 -> V_6 . V_14 || V_11 -> V_49 > V_123 )
goto V_74;
V_23 = F_10 ( & V_20 , & V_21 , V_11 -> V_49 ) ;
if ( F_26 ( V_23 ) )
goto V_74;
V_18 -> V_6 . V_118 += V_11 -> V_49 ;
V_18 -> V_6 . V_14 = V_23 ;
break;
case V_99 :
if ( V_11 -> V_49 & ~ 15 )
goto V_74;
break;
case V_100 :
if ( ( V_11 -> V_49 & ~ V_101 ) > V_101 )
goto V_74;
break;
default:
goto V_74;
}
}
if ( V_18 -> V_6 . V_31 && V_18 -> V_6 . V_31 -> V_33 == V_35 )
V_18 -> V_6 . V_31 = NULL ;
V_69:
return V_18 ;
V_74:
F_1 ( V_18 ) ;
return F_11 ( V_51 ) ;
}
static inline T_2 F_31 ( void * * V_20 , const char * V_23 )
{
T_2 V_22 = strlen ( V_23 ) ;
memcpy ( * V_20 , V_23 , V_22 ) ;
* V_20 += V_22 ;
return V_22 ;
}
static struct V_50 * F_32 ( struct V_4 * V_28 )
{
struct V_50 * V_6 ;
int V_3 ;
V_6 = F_8 ( sizeof( * V_6 ) , V_19 ) ;
if ( F_9 ( ! V_6 ) )
return NULL ;
V_6 -> V_52 = V_28 -> V_52 | V_28 -> V_29 ;
V_6 -> V_59 = V_28 -> V_59 ;
V_6 -> V_9 = V_28 -> V_9 ;
for ( V_3 = 0 ; V_3 < V_6 -> V_9 ; V_3 ++ ) {
V_6 -> V_73 [ V_3 ] = V_28 -> V_8 [ V_3 ] . V_49 ;
V_6 -> V_8 [ V_3 ] = V_28 -> V_8 [ V_3 ] . type ;
if ( V_28 -> V_72 == 1 ) {
if ( V_28 -> V_8 [ V_3 ] . V_33 == V_35 )
V_6 -> V_8 [ V_3 ] |= V_70 ;
} else {
V_6 -> V_8 [ V_3 ] |= V_68 [ V_28 -> V_8 [ V_3 ] . V_33 ] ;
}
}
for ( V_3 = 0 ; V_3 < V_39 ; V_3 ++ ) V_6 -> V_44 [ V_3 ] = V_28 -> V_44 [ V_3 ] ;
return V_6 ;
}
static struct V_103 * F_33 ( struct V_4 * V_28 )
{
struct V_103 * V_104 ;
void * V_20 ;
int V_3 ;
V_104 = F_12 ( sizeof( * V_104 ) + V_28 -> V_118 , V_19 ) ;
if ( F_9 ( ! V_104 ) )
return NULL ;
memset ( V_104 , 0 , sizeof( * V_104 ) ) ;
V_104 -> V_52 = V_28 -> V_52 | V_28 -> V_29 ;
V_104 -> V_59 = V_28 -> V_59 ;
V_104 -> V_9 = V_28 -> V_9 ;
V_20 = V_104 -> V_106 ;
for ( V_3 = 0 ; V_3 < V_104 -> V_9 ; V_3 ++ ) {
struct V_10 * V_11 = & V_28 -> V_8 [ V_3 ] ;
V_104 -> V_8 [ V_3 ] = V_11 -> type ;
V_104 -> V_107 [ V_3 ] = V_68 [ V_11 -> V_33 ] ;
switch( V_11 -> type ) {
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
V_104 -> V_118 += V_104 -> V_73 [ V_3 ] =
F_31 ( & V_20 , V_11 -> V_12 ) ;
break;
case V_120 :
V_104 -> V_118 += V_104 -> V_73 [ V_3 ] =
F_31 ( & V_20 ,
F_34 ( V_28 -> V_7 ) ) ;
break;
case V_121 :
V_104 -> V_118 += V_104 -> V_73 [ V_3 ] =
F_31 ( & V_20 ,
F_35 ( V_28 -> V_32 ) ) ;
break;
case V_122 :
V_104 -> V_118 += V_104 -> V_73 [ V_3 ] =
F_31 ( & V_20 , V_28 -> V_14 ) ;
break;
default:
V_104 -> V_73 [ V_3 ] = V_11 -> V_49 ;
}
}
for ( V_3 = 0 ; V_3 < V_39 ; V_3 ++ ) V_104 -> V_44 [ V_3 ] = V_28 -> V_44 [ V_3 ] ;
return V_104 ;
}
static int F_36 ( struct V_4 * V_124 , struct V_4 * V_125 )
{
int V_3 ;
if ( V_124 -> V_52 != V_125 -> V_52 ||
V_124 -> V_29 != V_125 -> V_29 ||
V_124 -> V_59 != V_125 -> V_59 ||
V_124 -> V_9 != V_125 -> V_9 )
return 1 ;
for ( V_3 = 0 ; V_3 < V_124 -> V_9 ; V_3 ++ ) {
if ( V_124 -> V_8 [ V_3 ] . type != V_125 -> V_8 [ V_3 ] . type ||
V_124 -> V_8 [ V_3 ] . V_33 != V_125 -> V_8 [ V_3 ] . V_33 )
return 1 ;
switch( V_124 -> V_8 [ V_3 ] . type ) {
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
if ( strcmp ( V_124 -> V_8 [ V_3 ] . V_12 , V_125 -> V_8 [ V_3 ] . V_12 ) )
return 1 ;
break;
case V_120 :
if ( strcmp ( F_34 ( V_124 -> V_7 ) ,
F_34 ( V_125 -> V_7 ) ) )
return 1 ;
break;
case V_121 :
if ( strcmp ( F_35 ( V_124 -> V_32 ) ,
F_35 ( V_125 -> V_32 ) ) )
return 1 ;
break;
case V_122 :
if ( strcmp ( V_124 -> V_14 , V_125 -> V_14 ) )
return 1 ;
break;
default:
if ( V_124 -> V_8 [ V_3 ] . V_49 != V_125 -> V_8 [ V_3 ] . V_49 )
return 1 ;
}
}
for ( V_3 = 0 ; V_3 < V_39 ; V_3 ++ )
if ( V_124 -> V_44 [ V_3 ] != V_125 -> V_44 [ V_3 ] )
return 1 ;
return 0 ;
}
static inline int F_37 ( struct V_10 * V_126 ,
struct V_10 * V_127 )
{
int V_128 = 0 ;
char * V_12 ;
V_12 = F_38 ( V_127 -> V_12 , V_19 ) ;
if ( F_9 ( ! V_12 ) )
return - V_27 ;
V_126 -> V_12 = V_12 ;
V_128 = F_28 ( V_126 -> type , V_126 -> V_33 , V_126 -> V_12 ,
( void * * ) & V_126 -> V_13 ) ;
if ( V_128 == - V_24 ) {
F_23 ( V_119 L_4
L_5 , V_126 -> V_12 ) ;
V_128 = 0 ;
}
return V_128 ;
}
struct V_1 * F_39 ( struct V_4 * V_129 )
{
T_1 V_130 = V_129 -> V_9 ;
struct V_1 * V_18 ;
struct V_4 * V_131 ;
char * V_132 ;
int V_3 , V_51 = 0 ;
V_18 = F_7 ( V_130 ) ;
if ( F_9 ( ! V_18 ) )
return F_11 ( - V_27 ) ;
V_131 = & V_18 -> V_6 ;
V_131 -> V_72 = V_129 -> V_72 ;
V_131 -> V_52 = V_129 -> V_52 ;
V_131 -> V_29 = V_129 -> V_29 ;
V_131 -> V_59 = V_129 -> V_59 ;
for ( V_3 = 0 ; V_3 < V_39 ; V_3 ++ )
V_131 -> V_44 [ V_3 ] = V_129 -> V_44 [ V_3 ] ;
V_131 -> V_133 = V_129 -> V_133 ;
V_131 -> V_118 = V_129 -> V_118 ;
V_131 -> V_31 = V_129 -> V_31 ;
V_131 -> V_9 = V_129 -> V_9 ;
V_131 -> V_32 = V_129 -> V_32 ;
memcpy ( V_131 -> V_8 , V_129 -> V_8 , sizeof( struct V_10 ) * V_130 ) ;
for ( V_3 = 0 ; V_3 < V_130 ; V_3 ++ ) {
switch ( V_131 -> V_8 [ V_3 ] . type ) {
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
V_51 = F_37 ( & V_131 -> V_8 [ V_3 ] ,
& V_129 -> V_8 [ V_3 ] ) ;
break;
case V_122 :
V_132 = F_38 ( V_129 -> V_14 , V_19 ) ;
if ( F_9 ( ! V_132 ) )
V_51 = - V_27 ;
else
V_131 -> V_14 = V_132 ;
}
if ( V_51 ) {
F_1 ( V_18 ) ;
return F_11 ( V_51 ) ;
}
}
if ( V_129 -> V_7 ) {
F_40 ( V_129 -> V_7 ) ;
V_131 -> V_7 = V_129 -> V_7 ;
}
return V_18 ;
}
static struct V_1 * F_41 ( struct V_1 * V_18 ,
struct V_134 * * V_38 )
{
struct V_1 * V_2 , * V_135 = NULL ;
struct V_134 * V_37 ;
int V_136 ;
if ( V_18 -> V_6 . V_31 ) {
V_136 = F_42 ( V_18 -> V_6 . V_31 -> V_49 ) ;
* V_38 = V_37 = & V_137 [ V_136 ] ;
} else if ( V_18 -> V_6 . V_7 ) {
for ( V_136 = 0 ; V_136 < V_138 ; V_136 ++ ) {
V_37 = & V_137 [ V_136 ] ;
F_43 (e, list, list)
if ( ! F_36 ( & V_18 -> V_6 , & V_2 -> V_6 ) ) {
V_135 = V_2 ;
goto V_139;
}
}
goto V_139;
} else {
* V_38 = V_37 = & V_140 [ V_18 -> V_6 . V_29 ] ;
}
F_43 (e, list, list)
if ( ! F_36 ( & V_18 -> V_6 , & V_2 -> V_6 ) ) {
V_135 = V_2 ;
goto V_139;
}
V_139:
return V_135 ;
}
static inline int F_44 ( struct V_1 * V_18 )
{
struct V_1 * V_2 ;
struct V_141 * V_7 = V_18 -> V_6 . V_7 ;
struct V_142 * V_32 = V_18 -> V_6 . V_32 ;
struct V_134 * V_37 ;
int V_51 ;
#ifdef F_22
int V_143 = 0 ;
if ( V_18 -> V_6 . V_29 == V_55 ||
V_18 -> V_6 . V_29 == V_56 )
V_143 = 1 ;
#endif
F_45 ( & V_144 ) ;
V_2 = F_41 ( V_18 , & V_37 ) ;
if ( V_2 ) {
F_46 ( & V_144 ) ;
V_51 = - V_145 ;
if ( V_32 )
F_47 ( V_32 ) ;
goto error;
}
if ( V_7 ) {
V_51 = F_48 ( & V_18 -> V_6 , & V_37 ) ;
if ( V_51 ) {
F_46 ( & V_144 ) ;
goto error;
}
}
if ( V_32 ) {
V_51 = F_49 ( & V_18 -> V_6 ) ;
if ( V_51 ) {
F_46 ( & V_144 ) ;
goto error;
}
}
V_18 -> V_6 . V_133 = ~ 0ULL ;
if ( V_18 -> V_6 . V_29 == V_30 ) {
if ( V_18 -> V_6 . V_52 & V_53 )
V_18 -> V_6 . V_133 = ++ V_146 ;
else
V_18 -> V_6 . V_133 = -- V_147 ;
}
if ( V_18 -> V_6 . V_52 & V_53 ) {
F_50 ( & V_18 -> V_6 . V_37 ,
& V_148 [ V_18 -> V_6 . V_29 ] ) ;
F_51 ( & V_18 -> V_37 , V_37 ) ;
V_18 -> V_6 . V_52 &= ~ V_53 ;
} else {
F_52 ( & V_18 -> V_6 . V_37 ,
& V_148 [ V_18 -> V_6 . V_29 ] ) ;
F_53 ( & V_18 -> V_37 , V_37 ) ;
}
#ifdef F_22
if ( ! V_143 )
V_149 ++ ;
if ( ! F_19 ( V_18 ) )
V_150 ++ ;
#endif
F_46 ( & V_144 ) ;
return 0 ;
error:
if ( V_7 )
F_2 ( V_7 ) ;
return V_51 ;
}
static inline int F_54 ( struct V_1 * V_18 )
{
struct V_1 * V_2 ;
struct V_141 * V_7 = V_18 -> V_6 . V_7 ;
struct V_142 * V_32 = V_18 -> V_6 . V_32 ;
struct V_134 * V_37 ;
int V_128 = 0 ;
#ifdef F_22
int V_143 = 0 ;
if ( V_18 -> V_6 . V_29 == V_55 ||
V_18 -> V_6 . V_29 == V_56 )
V_143 = 1 ;
#endif
F_45 ( & V_144 ) ;
V_2 = F_41 ( V_18 , & V_37 ) ;
if ( ! V_2 ) {
F_46 ( & V_144 ) ;
V_128 = - V_151 ;
goto V_139;
}
if ( V_2 -> V_6 . V_7 )
F_55 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_6 . V_32 )
F_56 ( & V_2 -> V_6 ) ;
F_57 ( & V_2 -> V_37 ) ;
F_58 ( & V_2 -> V_6 . V_37 ) ;
F_59 ( & V_2 -> V_17 , F_5 ) ;
#ifdef F_22
if ( ! V_143 )
V_149 -- ;
if ( ! F_19 ( V_18 ) )
V_150 -- ;
#endif
F_46 ( & V_144 ) ;
V_139:
if ( V_7 )
F_2 ( V_7 ) ;
if ( V_32 )
F_47 ( V_32 ) ;
return V_128 ;
}
static void F_60 ( int V_152 , int V_153 , struct V_154 * V_155 )
{
struct V_156 * V_157 ;
struct V_4 * V_158 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_159 ; V_3 ++ ) {
F_43 (r, &audit_rules_list[i], list) {
struct V_50 * V_6 ;
V_6 = F_32 ( V_158 ) ;
if ( F_9 ( ! V_6 ) )
break;
V_157 = F_61 ( V_152 , V_153 , V_160 , 0 , 1 ,
V_6 , sizeof( * V_6 ) ) ;
if ( V_157 )
F_62 ( V_155 , V_157 ) ;
F_3 ( V_6 ) ;
}
}
V_157 = F_61 ( V_152 , V_153 , V_160 , 1 , 1 , NULL , 0 ) ;
if ( V_157 )
F_62 ( V_155 , V_157 ) ;
}
static void F_63 ( int V_152 , int V_153 , struct V_154 * V_155 )
{
struct V_156 * V_157 ;
struct V_4 * V_158 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_159 ; V_3 ++ ) {
F_43 (r, &audit_rules_list[i], list) {
struct V_103 * V_104 ;
V_104 = F_33 ( V_158 ) ;
if ( F_9 ( ! V_104 ) )
break;
V_157 = F_61 ( V_152 , V_153 , V_161 , 0 , 1 ,
V_104 , sizeof( * V_104 ) + V_104 -> V_118 ) ;
if ( V_157 )
F_62 ( V_155 , V_157 ) ;
F_3 ( V_104 ) ;
}
}
V_157 = F_61 ( V_152 , V_153 , V_161 , 1 , 1 , NULL , 0 ) ;
if ( V_157 )
F_62 ( V_155 , V_157 ) ;
}
static void F_64 ( T_5 V_162 , T_1 V_163 , T_1 V_164 ,
char * V_59 , struct V_4 * V_6 ,
int V_165 )
{
struct V_166 * V_167 ;
if ( ! V_168 )
return;
V_167 = F_65 ( NULL , V_19 , V_169 ) ;
if ( ! V_167 )
return;
F_66 ( V_167 , L_6 , V_162 , V_163 ) ;
if ( V_164 ) {
char * V_170 = NULL ;
T_1 V_22 ;
if ( F_67 ( V_164 , & V_170 , & V_22 ) )
F_66 ( V_167 , L_7 , V_164 ) ;
else {
F_66 ( V_167 , L_8 , V_170 ) ;
F_68 ( V_170 , V_22 ) ;
}
}
F_66 ( V_167 , L_9 ) ;
F_69 ( V_167 , V_59 ) ;
F_70 ( V_167 , V_6 -> V_14 ) ;
F_66 ( V_167 , L_10 , V_6 -> V_29 , V_165 ) ;
F_71 ( V_167 ) ;
}
int F_72 ( int type , int V_152 , int V_171 , int V_153 , void * V_104 ,
T_2 V_105 , T_5 V_162 , T_1 V_163 , T_1 V_164 )
{
struct V_172 * V_173 ;
struct V_174 * V_175 ;
int V_51 = 0 ;
struct V_1 * V_18 ;
switch ( type ) {
case V_160 :
case V_161 :
V_175 = F_12 ( sizeof( struct V_174 ) , V_19 ) ;
if ( ! V_175 )
return - V_27 ;
V_175 -> V_152 = V_152 ;
F_73 ( & V_175 -> V_155 ) ;
F_45 ( & V_144 ) ;
if ( type == V_160 )
F_60 ( V_152 , V_153 , & V_175 -> V_155 ) ;
else
F_63 ( V_152 , V_153 , & V_175 -> V_155 ) ;
F_46 ( & V_144 ) ;
V_173 = F_74 ( V_176 , V_175 , L_11 ) ;
if ( F_26 ( V_173 ) ) {
F_75 ( & V_175 -> V_155 ) ;
F_3 ( V_175 ) ;
V_51 = F_76 ( V_173 ) ;
}
break;
case V_177 :
case V_178 :
if ( type == V_177 )
V_18 = F_25 ( V_104 ) ;
else
V_18 = F_27 ( V_104 , V_105 ) ;
if ( F_26 ( V_18 ) )
return F_76 ( V_18 ) ;
V_51 = F_44 ( V_18 ) ;
F_64 ( V_162 , V_163 , V_164 , L_12 ,
& V_18 -> V_6 , ! V_51 ) ;
if ( V_51 )
F_1 ( V_18 ) ;
break;
case V_179 :
case V_180 :
if ( type == V_179 )
V_18 = F_25 ( V_104 ) ;
else
V_18 = F_27 ( V_104 , V_105 ) ;
if ( F_26 ( V_18 ) )
return F_76 ( V_18 ) ;
V_51 = F_54 ( V_18 ) ;
F_64 ( V_162 , V_163 , V_164 , L_13 ,
& V_18 -> V_6 , ! V_51 ) ;
F_1 ( V_18 ) ;
break;
default:
return - V_24 ;
}
return V_51 ;
}
int F_77 ( T_1 V_181 , T_1 V_33 , T_1 V_182 )
{
switch ( V_33 ) {
case V_34 :
return ( V_181 == V_182 ) ;
case V_35 :
return ( V_181 != V_182 ) ;
case V_183 :
return ( V_181 < V_182 ) ;
case V_184 :
return ( V_181 <= V_182 ) ;
case V_185 :
return ( V_181 > V_182 ) ;
case V_186 :
return ( V_181 >= V_182 ) ;
case V_92 :
return ( V_181 & V_182 ) ;
case V_93 :
return ( ( V_181 & V_182 ) == V_182 ) ;
default:
F_78 () ;
return 0 ;
}
}
int F_79 ( const char * V_187 , const char * V_188 ,
int * V_189 )
{
int V_190 , V_191 ;
const char * V_38 ;
if ( ! V_187 || ! V_188 )
return 1 ;
V_190 = strlen ( V_187 ) ;
V_191 = strlen ( V_188 ) ;
if ( V_191 < V_190 )
return 1 ;
V_38 = V_188 + V_191 - 1 ;
while ( ( * V_38 == '/' ) && ( V_38 > V_188 ) )
V_38 -- ;
V_38 = V_38 - V_190 + 1 ;
if ( V_38 < V_188 )
return 1 ;
else if ( V_38 > V_188 ) {
if ( * -- V_38 != '/' )
return 1 ;
else
V_38 ++ ;
}
if ( V_189 )
* V_189 = V_38 - V_188 ;
return strncmp ( V_38 , V_187 , V_190 ) ;
}
static int F_80 ( struct V_192 * V_193 ,
struct V_4 * V_6 ,
enum V_194 * V_195 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_6 -> V_9 ; V_3 ++ ) {
struct V_10 * V_11 = & V_6 -> V_8 [ V_3 ] ;
int V_196 = 0 ;
T_1 V_164 ;
switch ( V_11 -> type ) {
case V_75 :
V_196 = F_77 ( V_193 -> V_197 . V_152 , V_11 -> V_33 , V_11 -> V_49 ) ;
break;
case V_76 :
V_196 = F_77 ( V_193 -> V_197 . V_171 , V_11 -> V_33 , V_11 -> V_49 ) ;
break;
case V_80 :
V_196 = F_77 ( V_193 -> V_197 . V_198 , V_11 -> V_33 , V_11 -> V_49 ) ;
break;
case V_84 :
V_196 = F_77 ( F_81 ( V_199 ) ,
V_11 -> V_33 , V_11 -> V_49 ) ;
break;
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
if ( V_11 -> V_13 ) {
F_82 ( V_199 , & V_164 ) ;
V_196 = F_83 ( V_164 ,
V_11 -> type ,
V_11 -> V_33 ,
V_11 -> V_13 ,
NULL ) ;
}
break;
}
if ( ! V_196 )
return 0 ;
}
switch ( V_6 -> V_59 ) {
case V_62 : * V_195 = V_200 ; break;
case V_63 : * V_195 = V_201 ; break;
}
return 1 ;
}
int F_84 ( struct V_192 * V_193 )
{
enum V_194 V_195 = V_200 ;
struct V_1 * V_2 ;
int V_128 = 1 ;
F_85 () ;
F_86 (e, &audit_filter_list[AUDIT_FILTER_USER], list) {
if ( F_80 ( V_193 , & V_2 -> V_6 , & V_195 ) ) {
if ( V_195 == V_200 )
V_128 = 0 ;
break;
}
}
F_87 () ;
return V_128 ;
}
int F_88 ( int type )
{
struct V_1 * V_2 ;
int V_196 = 0 ;
F_85 () ;
if ( F_89 ( & V_140 [ V_56 ] ) )
goto V_202;
F_86 (e, &audit_filter_list[AUDIT_FILTER_TYPE],
list) {
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_6 . V_9 ; V_3 ++ ) {
struct V_10 * V_11 = & V_2 -> V_6 . V_8 [ V_3 ] ;
if ( V_11 -> type == V_86 ) {
V_196 = F_77 ( type , V_11 -> V_33 , V_11 -> V_49 ) ;
if ( ! V_196 )
break;
}
}
if ( V_196 )
goto V_202;
}
V_202:
F_87 () ;
return V_196 ;
}
static int F_90 ( struct V_4 * V_158 )
{
struct V_1 * V_18 = F_6 ( V_158 , struct V_1 , V_6 ) ;
struct V_1 * V_203 ;
int V_51 = 0 ;
if ( ! F_91 ( V_158 ) )
return 0 ;
V_203 = F_39 ( V_158 ) ;
if ( F_26 ( V_203 ) ) {
V_51 = F_76 ( V_203 ) ;
F_92 ( L_14 ) ;
if ( V_158 -> V_7 )
F_58 ( & V_158 -> V_204 ) ;
F_57 ( & V_18 -> V_37 ) ;
F_58 ( & V_158 -> V_37 ) ;
} else {
if ( V_158 -> V_7 || V_158 -> V_32 )
F_93 ( & V_158 -> V_204 , & V_203 -> V_6 . V_204 ) ;
F_94 ( & V_18 -> V_37 , & V_203 -> V_37 ) ;
F_95 ( & V_158 -> V_37 , & V_203 -> V_6 . V_37 ) ;
}
F_59 ( & V_18 -> V_17 , F_5 ) ;
return V_51 ;
}
int F_96 ( void )
{
struct V_4 * V_158 , * V_40 ;
int V_3 , V_51 = 0 ;
F_45 ( & V_144 ) ;
for ( V_3 = 0 ; V_3 < V_159 ; V_3 ++ ) {
F_97 (r, n, &audit_rules_list[i], list) {
int V_165 = F_90 ( V_158 ) ;
if ( ! V_51 )
V_51 = V_165 ;
}
}
F_46 ( & V_144 ) ;
return V_51 ;
}
