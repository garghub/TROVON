static unsigned char * F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 ,
void * V_5 )
{
void * V_6 = NULL ;
struct {
T_1 V_7 ;
T_1 V_8 ;
} * V_9 , V_10 ;
int V_11 = * V_4 ;
V_9 = F_2 ( V_2 , 0 , 2 , & V_10 ) ;
if ( V_9 == NULL || V_9 -> V_8 < 2 || ! F_3 ( V_2 , V_9 -> V_8 ) )
return NULL ;
V_9 -> V_8 -= 2 ;
* V_3 = V_9 -> V_7 ;
* V_4 = V_9 -> V_8 ;
if ( V_11 > V_9 -> V_8 )
V_11 = V_9 -> V_8 ;
V_6 = F_2 ( V_2 , 2 , V_11 , V_5 ) ;
F_4 ( V_2 , 2 + V_9 -> V_8 ) ;
return V_6 ;
}
static struct V_1 * F_5 ( struct V_12 * V_13 , const void * V_14 ,
int V_15 , T_2 V_16 )
{
struct V_1 * V_2 = F_6 ( V_17 + V_15 , V_16 ) ;
if ( ! V_2 )
return NULL ;
F_7 ( V_2 , V_13 ) ;
F_8 ( V_2 , V_17 ) ;
F_9 ( V_2 , V_15 ) ;
F_10 ( V_2 , V_14 , V_15 ) ;
F_11 ( V_2 , sizeof( struct V_18 ) ) ;
F_12 ( V_2 ) ;
return V_2 ;
}
static int F_13 ( struct V_12 * V_13 , struct V_1 * V_19 , T_1 V_20 ,
const void * V_6 , int V_15 , T_2 V_16 )
{
const struct V_18 * V_21 = F_14 ( V_19 ) ;
struct V_18 * V_9 ;
struct V_1 * V_2 ;
struct V_22 V_23 ;
V_2 = F_5 ( V_13 , V_6 , V_15 , V_16 ) ;
if ( ! V_2 )
return - V_24 ;
V_9 = F_14 ( V_2 ) ;
V_9 -> V_25 = V_21 -> V_25 ;
V_9 -> V_26 = V_21 -> V_26 + 1 ;
V_9 -> V_27 = V_21 -> V_27 ;
V_9 -> V_28 = V_20 ;
F_15 ( V_19 , & V_23 ) ;
return F_16 ( V_13 , V_2 , & V_23 ) ;
}
static int F_17 ( struct V_12 * V_13 , T_1 V_29 , T_1 V_20 ,
const void * V_6 , int V_15 , T_2 V_16 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_18 * V_9 ;
struct V_1 * V_2 ;
V_2 = F_5 ( V_13 , V_6 , V_15 , V_16 ) ;
if ( ! V_2 )
return - V_24 ;
V_9 = F_14 ( V_2 ) ;
V_9 -> V_25 = 0 ;
V_9 -> V_26 = V_29 ;
V_9 -> V_27 = V_31 -> V_27 ;
V_9 -> V_6 [ 0 ] = V_20 ;
return F_16 ( V_13 , V_2 , NULL ) ;
}
static int F_19 ( struct V_12 * V_13 , T_1 V_29 , T_1 V_20 ,
const void * V_6 , int V_15 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_18 * V_9 ;
struct V_1 * V_2 ;
V_2 = F_5 ( V_13 , V_6 , V_15 , V_32 ) ;
if ( ! V_2 )
return - V_24 ;
V_9 = F_14 ( V_2 ) ;
V_9 -> V_25 = V_29 ;
V_9 -> V_26 = V_29 ;
V_9 -> V_27 = V_31 -> V_27 ;
V_9 -> V_6 [ 0 ] = V_20 ;
return F_16 ( V_13 , V_2 , NULL ) ;
}
static int F_20 ( struct V_12 * V_13 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
T_1 V_6 [ 4 ] = {
V_33 , F_21 ( 2 ) ,
V_31 -> V_34 , V_31 -> V_35 ,
} ;
return F_17 ( V_13 , V_36 , 1 ,
V_6 , 4 , V_37 ) ;
}
static int F_22 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
static const T_1 V_6 [ 20 ] = {
V_38 , V_38 , V_38 , 2 ,
V_39 , F_21 ( 5 ) , 3 , V_38 ,
V_40 ,
V_41 ,
V_42 ,
V_38 ,
V_43 , F_21 ( 5 ) , 3 , V_38 ,
V_40 ,
V_41 ,
V_42 ,
V_38 ,
} ;
F_23 () ;
return F_13 ( V_13 , V_2 , V_44 , V_6 , sizeof( V_6 ) ,
V_32 ) ;
}
static int F_24 ( struct V_12 * V_13 , struct V_1 * V_2 , T_1 V_20 ,
T_2 V_16 )
{
static const T_1 V_6 [ 4 ] = { V_38 , V_38 , V_38 , 0 } ;
F_25 ( V_20 == V_44 ) ;
return F_13 ( V_13 , V_2 , V_20 , V_6 , sizeof( V_6 ) , V_16 ) ;
}
static int F_26 ( struct V_12 * V_13 , struct V_1 * V_19 , T_1 V_20 ,
T_2 V_16 )
{
const struct V_18 * V_21 = F_14 ( V_19 ) ;
struct V_1 * V_2 ;
struct V_18 * V_9 ;
struct V_22 V_45 ;
T_1 V_6 [ 4 ] = {
V_21 -> V_6 [ 0 ] ,
V_20 ,
V_38 , V_38 ,
} ;
V_2 = F_5 ( V_13 , V_6 , 4 , V_16 ) ;
if ( ! V_2 )
return - V_24 ;
V_9 = F_14 ( V_2 ) ;
V_9 -> V_25 = V_21 -> V_25 ;
V_9 -> V_26 = V_46 ;
V_9 -> V_27 = V_21 -> V_27 ;
V_9 -> V_6 [ 0 ] = V_21 -> V_6 [ 1 ] ;
F_15 ( V_19 , & V_45 ) ;
return F_16 ( V_13 , V_2 , & V_45 ) ;
}
static int F_27 ( struct V_12 * V_13 , T_1 type , T_1 V_47 , T_2 V_16 )
{
T_1 V_6 [ 4 ] = { type , V_38 , V_38 , V_47 } ;
return F_17 ( V_13 , V_48 , V_49 ,
V_6 , 4 , V_16 ) ;
}
static void F_28 ( struct V_12 * V_13 , T_2 V_16 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
F_29 ( V_13 -> V_50 != V_51 ) ;
switch ( V_31 -> V_35 ) {
case V_42 :
break;
case V_41 :
if ( F_27 ( V_13 , V_52 ,
V_53 , V_16 ) == 0 )
V_31 -> V_54 = 1 ;
break;
case V_40 :
if ( ( V_31 -> V_54 + V_55 ) > V_56 )
break;
if ( F_27 ( V_13 , V_57 ,
V_56 - V_31 -> V_54 ,
V_16 ) == 0 )
V_31 -> V_54 = V_56 ;
break;
}
}
static int F_30 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_18 * V_58 ;
int V_59 = 0 ;
if ( ! F_3 ( V_2 , sizeof( * V_58 ) + 4 ) )
return - V_60 ;
V_58 = F_14 ( V_2 ) ;
if ( V_58 -> V_6 [ 0 ] != V_49 ) {
F_31 ( V_61 L_1 ,
( unsigned ) V_58 -> V_6 [ 0 ] ) ;
return - V_62 ;
}
switch ( V_58 -> V_6 [ 1 ] ) {
case V_52 :
switch ( V_31 -> V_34 ) {
case V_42 :
switch ( V_58 -> V_6 [ 4 ] ) {
case V_63 :
F_32 ( & V_31 -> V_64 , 0 ) ;
break;
case V_53 :
F_32 ( & V_31 -> V_64 , V_59 = 1 ) ;
break;
}
break;
case V_41 :
if ( V_58 -> V_6 [ 4 ] == V_53 )
F_32 ( & V_31 -> V_64 , V_59 = 1 ) ;
break;
}
break;
case V_57 :
if ( V_31 -> V_34 != V_40 )
break;
F_33 ( V_59 = V_58 -> V_6 [ 4 ] , & V_31 -> V_64 ) ;
break;
default:
F_31 ( V_61 L_2 ,
( unsigned ) V_58 -> V_6 [ 1 ] ) ;
return - V_62 ;
}
if ( V_59 )
V_13 -> V_65 ( V_13 ) ;
return 0 ;
}
static int F_34 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_18 * V_58 = F_14 ( V_2 ) ;
T_1 V_66 = V_58 -> V_6 [ 0 ] ;
V_31 -> V_35 = V_31 -> V_34 = V_42 ;
F_4 ( V_2 , sizeof( * V_58 ) ) ;
while ( V_66 > 0 ) {
T_1 type , V_5 [ 2 ] , V_15 = sizeof( V_5 ) ;
T_1 * V_6 = F_1 ( V_2 , & type , & V_15 , V_5 ) ;
if ( V_6 == NULL )
return - V_60 ;
switch ( type ) {
case V_33 :
if ( V_15 < 2 || ( V_6 [ 0 ] | V_6 [ 1 ] ) > 3 )
break;
V_31 -> V_34 = V_6 [ 0 ] & 3 ;
V_31 -> V_35 = V_6 [ 1 ] & 3 ;
break;
}
V_66 -- ;
}
return 0 ;
}
static int F_35 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_18 * V_58 = F_14 ( V_2 ) ;
struct V_67 * V_68 ;
int V_69 = 0 ;
F_29 ( V_13 -> V_50 == V_70 ) ;
switch ( V_58 -> V_26 ) {
case V_71 :
F_24 ( V_13 , V_2 , V_72 , V_37 ) ;
break;
case V_73 :
F_13 ( V_13 , V_2 , V_44 , NULL , 0 , V_37 ) ;
V_13 -> V_50 = V_70 ;
if ( ! F_36 ( V_13 , V_74 ) )
V_13 -> V_75 ( V_13 ) ;
break;
case V_76 :
F_13 ( V_13 , V_2 , V_44 , NULL , 0 , V_37 ) ;
break;
case V_77 :
switch ( V_58 -> V_78 ) {
case V_79 :
V_31 -> V_80 = 0 ;
break;
case V_81 :
V_31 -> V_80 = 1 ;
break;
default:
V_69 = - V_60 ;
goto V_82;
}
case V_83 :
F_32 ( & V_31 -> V_64 , 0 ) ;
F_13 ( V_13 , V_2 , V_44 , NULL , 0 , V_37 ) ;
break;
case V_84 :
if ( F_37 ( & V_31 -> V_85 ) >= V_86 ) {
F_38 ( & V_13 -> V_87 ) ;
break;
}
F_4 ( V_2 , 4 ) ;
V_68 = & V_31 -> V_85 ;
goto V_68;
case V_88 :
F_4 ( V_2 , 1 ) ;
case V_89 :
F_4 ( V_2 , 3 ) ;
if ( ! F_39 ( V_31 -> V_35 ) ) {
V_69 = F_40 ( V_13 , V_2 ) ;
if ( ! V_69 )
return V_90 ;
V_69 = - V_91 ;
break;
}
if ( V_31 -> V_54 == 0 ) {
F_38 ( & V_13 -> V_87 ) ;
V_69 = - V_91 ;
break;
}
V_31 -> V_54 -- ;
V_68 = & V_13 -> V_92 ;
goto V_68;
case V_48 :
F_30 ( V_13 , V_2 ) ;
break;
case V_93 :
V_69 = F_34 ( V_13 , V_2 ) ;
break;
case V_36 :
V_69 = F_34 ( V_13 , V_2 ) ;
if ( V_69 )
break;
case V_94 :
if ( ! V_31 -> V_80 )
break;
case V_95 :
if ( ! F_39 ( V_31 -> V_34 ) ) {
F_32 ( & V_31 -> V_64 , 1 ) ;
V_13 -> V_65 ( V_13 ) ;
}
if ( V_13 -> V_50 == V_51 )
break;
V_13 -> V_50 = V_51 ;
F_28 ( V_13 , V_37 ) ;
break;
case V_96 :
V_13 -> V_50 = V_97 ;
V_31 -> V_54 = 0 ;
break;
default:
F_31 ( V_61 L_3 ,
V_58 -> V_26 ) ;
V_69 = - V_60 ;
}
V_82:
F_41 ( V_2 ) ;
return ( V_69 == - V_91 ) ? V_98 : V_90 ;
V_68:
V_2 -> V_99 = NULL ;
F_42 ( V_2 , V_13 ) ;
V_69 = V_2 -> V_15 ;
F_43 ( V_68 , V_2 ) ;
if ( ! F_36 ( V_13 , V_74 ) )
V_13 -> V_100 ( V_13 , V_69 ) ;
return V_90 ;
}
static void F_44 ( struct V_12 * V_13 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
F_45 ( & V_13 -> V_92 ) ;
F_45 ( & V_31 -> V_85 ) ;
}
static T_1 F_46 ( const T_1 * V_101 , unsigned V_102 )
{
unsigned V_103 ;
T_1 V_104 = V_105 ;
for ( V_103 = 0 ; V_103 < V_102 ; V_103 ++ ) {
T_1 V_106 = V_101 [ V_103 ] ;
if ( V_106 > V_104 && V_106 < V_107 )
V_104 = V_106 ;
}
return V_104 ;
}
static int F_47 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_18 * V_58 ;
T_1 V_66 ;
if ( ! F_48 ( V_2 , sizeof( * V_58 ) + 4 ) )
return - V_60 ;
V_58 = F_14 ( V_2 ) ;
if ( V_58 -> V_28 != V_44 )
return - V_108 ;
V_66 = V_58 -> V_6 [ 4 ] ;
while ( V_66 > 0 ) {
T_1 type , V_5 [ 6 ] , V_15 = sizeof( V_5 ) ;
const T_1 * V_6 = F_1 ( V_2 , & type , & V_15 , V_5 ) ;
if ( V_6 == NULL )
return - V_60 ;
switch ( type ) {
case V_39 :
if ( V_15 < 2 || V_15 < V_6 [ 0 ] )
break;
V_31 -> V_34 = F_46 ( V_6 + 2 , V_15 - 2 ) ;
break;
case V_43 :
if ( V_15 < 2 || V_15 < V_6 [ 0 ] )
break;
V_31 -> V_35 = F_46 ( V_6 + 2 , V_15 - 2 ) ;
break;
}
V_66 -- ;
}
return F_20 ( V_13 ) ;
}
static int F_49 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_18 * V_58 = F_14 ( V_2 ) ;
int V_69 = V_90 ;
switch ( V_58 -> V_26 ) {
case V_88 :
F_4 ( V_2 , 1 ) ;
case V_89 :
F_4 ( V_2 , 3 ) ;
if ( ! F_39 ( V_31 -> V_35 ) ) {
V_69 = F_40 ( V_13 , V_2 ) ;
if ( ! V_69 )
return V_90 ;
V_69 = V_98 ;
break;
}
if ( V_31 -> V_54 == 0 ) {
F_38 ( & V_13 -> V_87 ) ;
V_69 = V_98 ;
break;
}
V_31 -> V_54 -- ;
V_2 -> V_99 = NULL ;
F_42 ( V_2 , V_13 ) ;
V_69 = V_2 -> V_15 ;
F_43 ( & V_13 -> V_92 , V_2 ) ;
if ( ! F_36 ( V_13 , V_74 ) )
V_13 -> V_100 ( V_13 , V_69 ) ;
return V_90 ;
case V_109 :
if ( V_13 -> V_50 != V_110 )
break;
if ( ! F_36 ( V_13 , V_74 ) )
V_13 -> V_75 ( V_13 ) ;
if ( F_47 ( V_13 , V_2 ) ) {
V_13 -> V_50 = V_70 ;
break;
}
V_13 -> V_50 = V_51 ;
if ( ! F_39 ( V_31 -> V_34 ) ) {
F_32 ( & V_31 -> V_64 , 1 ) ;
V_13 -> V_65 ( V_13 ) ;
}
F_28 ( V_13 , V_37 ) ;
break;
case V_111 :
break;
case V_48 :
F_30 ( V_13 , V_2 ) ;
break;
}
F_41 ( V_2 ) ;
return V_69 ;
}
static struct V_12 * F_50 ( const struct V_112 * V_113 ,
const struct V_22 * V_45 ,
T_1 V_27 )
{
struct V_114 * V_115 ;
struct V_12 * V_116 ;
T_3 V_117 = F_51 ( V_45 ) ;
F_52 (sknode, node, hlist) {
struct V_30 * V_118 = F_18 ( V_116 ) ;
if ( V_118 -> V_119 . V_120 != V_117 )
continue;
if ( V_118 -> V_27 != V_27 )
continue;
if ( V_116 -> V_50 == V_70 )
continue;
F_53 ( V_116 ) ;
return V_116 ;
}
return NULL ;
}
static int F_54 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_12 * V_116 ;
struct V_18 * V_58 ;
struct V_22 V_45 ;
T_1 V_27 ;
if ( ! F_3 ( V_2 , sizeof( * V_58 ) ) )
goto V_121;
V_58 = F_14 ( V_2 ) ;
V_27 = V_58 -> V_27 ;
if ( V_27 == V_122 )
goto V_121;
F_55 ( V_2 , & V_45 ) ;
V_116 = F_50 ( & V_31 -> V_113 , & V_45 , V_27 ) ;
if ( V_116 )
return F_56 ( V_116 , V_2 , 1 ) ;
switch ( V_58 -> V_26 ) {
case V_71 :
if ( V_13 -> V_50 != V_123 || F_57 ( V_13 ) ) {
F_24 ( V_13 , V_2 , V_72 ,
V_37 ) ;
break;
}
F_58 ( & V_13 -> V_92 , V_2 ) ;
F_59 ( V_13 ) ;
if ( ! F_36 ( V_13 , V_74 ) )
V_13 -> V_100 ( V_13 , 0 ) ;
return V_90 ;
case V_73 :
F_13 ( V_13 , V_2 , V_44 , NULL , 0 , V_37 ) ;
break;
case V_84 :
F_26 ( V_13 , V_2 , V_122 , V_37 ) ;
break;
case V_77 :
case V_76 :
case V_83 :
break;
default:
if ( ( 1 << V_13 -> V_50 )
& ~ ( V_124 | V_125 | V_126 ) )
return F_49 ( V_13 , V_2 ) ;
}
V_121:
F_41 ( V_2 ) ;
return V_90 ;
}
static int F_60 ( struct V_12 * V_13 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_18 * V_9 ;
struct V_1 * V_2 ;
V_2 = F_5 ( V_13 , NULL , 0 , V_32 ) ;
if ( ! V_2 )
return - V_24 ;
V_9 = F_14 ( V_2 ) ;
V_9 -> V_25 = 0 ;
V_9 -> V_26 = V_127 ;
V_9 -> V_27 = V_31 -> V_27 ;
V_9 -> V_6 [ 0 ] = V_38 ;
return F_16 ( V_13 , V_2 , NULL ) ;
}
static void F_61 ( struct V_12 * V_13 , long V_128 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
int V_129 = 0 ;
F_53 ( V_13 ) ;
F_62 ( V_13 ) ;
F_63 ( V_13 ) ;
if ( ( 1 << V_13 -> V_50 ) & ( V_130 | V_131 ) ) {
if ( V_13 -> V_132 == F_35 )
F_60 ( V_13 ) ;
else
F_19 ( V_13 , V_73 , V_38 ,
NULL , 0 ) ;
}
V_13 -> V_50 = V_133 ;
V_129 = V_31 -> V_129 ;
V_31 -> V_129 = 0 ;
F_64 ( V_13 ) ;
if ( V_129 )
F_65 ( V_13 ) ;
F_66 ( V_13 ) ;
}
static struct V_12 * F_67 ( struct V_12 * V_13 , int V_134 , int * V_135 )
{
struct V_30 * V_31 = F_18 ( V_13 ) , * V_136 ;
struct V_12 * V_137 = NULL ;
struct V_1 * V_2 ;
struct V_18 * V_58 ;
struct V_22 V_45 , V_138 ;
int V_69 ;
T_3 V_139 ;
T_1 V_27 , V_140 , V_66 ;
T_1 V_141 = 0 ;
V_2 = F_68 ( V_13 , 0 , V_134 & V_142 , V_135 ) ;
if ( ! V_2 )
return NULL ;
F_63 ( V_13 ) ;
if ( V_13 -> V_50 != V_123 ) {
V_69 = - V_60 ;
goto V_121;
}
F_69 ( V_13 ) ;
V_69 = - V_143 ;
if ( ! F_3 ( V_2 , sizeof( * V_58 ) + 4 ) )
goto V_121;
V_58 = F_14 ( V_2 ) ;
V_27 = V_58 -> V_27 ;
switch ( V_58 -> V_144 ) {
case V_79 :
V_140 = 0 ;
break;
case V_81 :
V_140 = 1 ;
break;
default:
F_24 ( V_13 , V_2 , V_145 ,
V_32 ) ;
goto V_121;
}
V_139 = V_58 -> V_146 << 8 ;
V_66 = V_58 -> V_6 [ 4 ] ;
while ( V_66 > 0 ) {
T_1 type , V_5 [ 1 ] , V_15 = sizeof( V_5 ) ;
const T_1 * V_6 = F_1 ( V_2 , & type , & V_15 , V_5 ) ;
if ( V_6 == NULL )
goto V_121;
switch ( type ) {
case V_147 :
if ( V_15 < 1 )
goto V_121;
V_139 = ( V_139 & 0xff00 ) | V_6 [ 0 ] ;
break;
case V_148 :
V_141 = V_6 [ 0 ] != 0 ;
break;
}
V_66 -- ;
}
V_137 = F_50 ( & V_31 -> V_113 , & V_45 , V_27 ) ;
if ( F_70 ( V_137 ) ) {
F_71 ( V_137 ) ;
V_137 = NULL ;
F_24 ( V_13 , V_2 , V_72 , V_32 ) ;
goto V_121;
}
V_137 = F_72 ( F_73 ( V_13 ) , V_149 , V_32 , V_13 -> V_150 ) ;
if ( ! V_137 ) {
F_24 ( V_13 , V_2 , V_151 , V_32 ) ;
V_69 = - V_91 ;
goto V_121;
}
F_74 ( NULL , V_137 ) ;
V_137 -> V_50 = V_97 ;
V_137 -> V_132 = F_35 ;
V_137 -> V_152 = V_13 -> V_152 ;
V_137 -> V_153 = F_44 ;
V_136 = F_18 ( V_137 ) ;
F_55 ( V_2 , & V_45 ) ;
F_15 ( V_2 , & V_138 ) ;
V_136 -> V_119 . V_120 = F_51 ( & V_45 ) ;
V_136 -> V_119 . V_154 = F_51 ( & V_138 ) ;
V_136 -> V_119 . V_155 = F_75 ( & V_45 ) ;
F_53 ( V_13 ) ;
V_136 -> V_156 = V_13 ;
F_76 ( & V_136 -> V_85 ) ;
V_136 -> V_27 = V_27 ;
F_32 ( & V_136 -> V_64 , 0 ) ;
V_136 -> V_129 = 0 ;
V_136 -> V_139 = V_139 ;
V_136 -> V_54 = 0 ;
V_136 -> V_35 = V_136 -> V_34 = V_42 ;
V_136 -> V_80 = V_140 ;
V_136 -> V_141 = V_141 ;
V_69 = F_22 ( V_137 , V_2 ) ;
if ( V_69 ) {
F_66 ( V_137 ) ;
V_137 = NULL ;
goto V_121;
}
F_77 ( V_137 , & V_31 -> V_113 ) ;
V_121:
F_64 ( V_13 ) ;
F_41 ( V_2 ) ;
* V_135 = V_69 ;
return V_137 ;
}
static int F_78 ( struct V_12 * V_13 , struct V_157 * V_158 , int V_15 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
int V_69 ;
T_1 V_6 [ 4 ] = { 0 , V_38 , V_38 , V_38 } ;
V_31 -> V_27 = 1 ;
V_69 = F_19 ( V_13 , V_71 ,
V_81 , V_6 , 4 ) ;
if ( V_69 ) {
V_31 -> V_27 = V_122 ;
return V_69 ;
}
V_13 -> V_50 = V_110 ;
return 0 ;
}
static int F_79 ( struct V_12 * V_13 , int V_159 , unsigned long V_160 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
int V_161 ;
switch ( V_159 ) {
case V_162 :
if ( V_13 -> V_50 == V_123 )
return - V_60 ;
F_63 ( V_13 ) ;
if ( F_36 ( V_13 , V_163 ) &&
! F_80 ( & V_31 -> V_85 ) )
V_161 = F_81 ( & V_31 -> V_85 ) -> V_15 ;
else if ( ! F_80 ( & V_13 -> V_92 ) )
V_161 = F_81 ( & V_13 -> V_92 ) -> V_15 ;
else
V_161 = 0 ;
F_64 ( V_13 ) ;
return F_82 ( V_161 , ( int V_164 * ) V_160 ) ;
}
return - V_165 ;
}
static int F_83 ( struct V_12 * V_13 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
V_13 -> V_153 = F_44 ;
F_84 ( & V_31 -> V_113 ) ;
V_31 -> V_156 = NULL ;
F_76 ( & V_31 -> V_85 ) ;
F_32 ( & V_31 -> V_64 , 0 ) ;
V_31 -> V_129 = 0 ;
V_31 -> V_139 = 0 ;
V_31 -> V_27 = V_122 ;
V_31 -> V_54 = 0 ;
V_31 -> V_35 = V_31 -> V_34 = V_42 ;
V_31 -> V_80 = 1 ;
V_31 -> V_141 = 0 ;
return 0 ;
}
static int F_85 ( struct V_12 * V_13 , int V_166 , int V_167 ,
char V_164 * V_168 , unsigned int V_169 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
int V_170 = 0 , V_69 = 0 ;
if ( V_166 != V_171 )
return - V_172 ;
if ( V_169 >= sizeof( int ) ) {
if ( F_86 ( V_170 , ( int V_164 * ) V_168 ) )
return - V_173 ;
}
F_63 ( V_13 ) ;
switch ( V_167 ) {
case V_174 :
if ( V_170 && V_170 != V_175 ) {
V_69 = - V_60 ;
break;
}
if ( ! V_31 -> V_129 == ! V_170 )
break;
if ( ! F_87 ( V_176 ) ) {
V_69 = - V_177 ;
break;
}
if ( V_170 ) {
F_64 ( V_13 ) ;
V_69 = F_88 ( V_13 ) ;
if ( V_69 > 0 ) {
V_31 -> V_129 = V_69 ;
V_69 = 0 ;
}
} else {
V_31 -> V_129 = 0 ;
F_64 ( V_13 ) ;
F_65 ( V_13 ) ;
V_69 = 0 ;
}
goto V_178;
default:
V_69 = - V_172 ;
}
F_64 ( V_13 ) ;
V_178:
return V_69 ;
}
static int F_89 ( struct V_12 * V_13 , int V_166 , int V_167 ,
char V_164 * V_168 , int V_164 * V_169 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
int V_15 , V_170 ;
if ( V_166 != V_171 )
return - V_172 ;
if ( F_86 ( V_15 , V_169 ) )
return - V_173 ;
switch ( V_167 ) {
case V_174 :
V_170 = V_31 -> V_129 ? V_175 : V_179 ;
break;
case V_180 :
V_170 = V_31 -> V_129 ;
break;
case V_181 :
V_170 = V_31 -> V_27 ;
if ( V_170 == V_122 )
return - V_60 ;
break;
default:
return - V_172 ;
}
V_15 = F_90 (unsigned int, sizeof(int), len) ;
if ( F_82 ( V_15 , V_169 ) )
return - V_173 ;
if ( F_82 ( V_170 , ( int V_164 * ) V_168 ) )
return - V_173 ;
return 0 ;
}
static int F_91 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_18 * V_9 ;
int V_69 ;
if ( F_39 ( V_31 -> V_34 ) &&
! F_92 ( & V_31 -> V_64 , - 1 , 0 ) ) {
F_41 ( V_2 ) ;
return - V_91 ;
}
F_93 ( V_2 , 3 + V_31 -> V_141 ) ;
F_12 ( V_2 ) ;
V_9 = F_14 ( V_2 ) ;
V_9 -> V_25 = 0 ;
if ( V_31 -> V_141 ) {
V_9 -> V_26 = V_88 ;
V_9 -> V_6 [ 0 ] = 0 ;
} else
V_9 -> V_26 = V_89 ;
V_9 -> V_27 = V_31 -> V_27 ;
V_69 = F_16 ( V_13 , V_2 , NULL ) ;
if ( V_69 && F_39 ( V_31 -> V_34 ) )
F_38 ( & V_31 -> V_64 ) ;
return V_69 ;
}
static int F_94 ( struct V_182 * V_183 , struct V_12 * V_13 ,
struct V_184 * V_185 , T_4 V_15 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_1 * V_2 ;
long V_186 ;
int V_134 = V_185 -> V_187 ;
int V_69 , V_188 ;
if ( ( V_185 -> V_187 & ~ ( V_189 | V_190 | V_191 |
V_192 ) ) ||
! ( V_185 -> V_187 & V_190 ) )
return - V_62 ;
V_2 = F_95 ( V_13 , V_17 + V_15 ,
V_134 & V_189 , & V_69 ) ;
if ( ! V_2 )
return V_69 ;
F_8 ( V_2 , V_193 + 3 + V_31 -> V_141 ) ;
V_69 = F_96 ( F_97 ( V_2 , V_15 ) , V_185 -> V_194 , V_15 ) ;
if ( V_69 < 0 )
goto V_195;
F_63 ( V_13 ) ;
V_186 = F_98 ( V_13 , V_134 & V_189 ) ;
if ( ( 1 << V_13 -> V_50 ) & ( V_125 | V_124 ) ) {
V_69 = - V_196 ;
goto V_82;
}
if ( V_13 -> V_50 != V_51 ) {
V_197:
V_69 = F_99 ( V_13 , & V_186 ) ;
if ( V_69 )
goto V_82;
if ( V_13 -> V_50 == V_70 ) {
V_69 = - V_198 ;
goto V_82;
}
}
F_29 ( V_13 -> V_50 != V_51 ) ;
V_188 = F_100 ( & V_31 -> V_64 ) ;
while ( ! V_188 ) {
F_101 ( V_199 ) ;
if ( ! V_186 ) {
V_69 = - V_200 ;
goto V_82;
}
if ( F_102 ( V_201 ) ) {
V_69 = F_103 ( V_186 ) ;
goto V_82;
}
F_104 ( F_105 ( V_13 ) , & V_199 ,
V_202 ) ;
V_188 = F_106 ( V_13 , & V_186 , F_100 ( & V_31 -> V_64 ) ) ;
F_107 ( F_105 ( V_13 ) , & V_199 ) ;
if ( V_13 -> V_50 != V_51 )
goto V_197;
}
V_69 = F_91 ( V_13 , V_2 ) ;
if ( V_69 >= 0 )
V_69 = V_15 ;
V_2 = NULL ;
V_82:
F_64 ( V_13 ) ;
V_195:
F_41 ( V_2 ) ;
return V_69 ;
}
int F_108 ( struct V_12 * V_13 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
return F_100 ( & V_31 -> V_64 ) ;
}
int F_109 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_1 * V_203 , * V_204 ;
int V_205 = 0 ;
if ( F_18 ( V_13 ) -> V_141 )
return F_91 ( V_13 , V_2 ) ;
V_203 = F_6 ( V_17 , V_37 ) ;
if ( ! V_203 ) {
F_41 ( V_2 ) ;
return - V_24 ;
}
F_110 ( V_203 ) -> V_206 = V_2 ;
V_203 -> V_15 += V_2 -> V_15 ;
V_203 -> V_207 += V_203 -> V_15 ;
V_203 -> V_208 += V_203 -> V_15 ;
F_111 (skb, fs)
V_205 += V_204 -> V_15 ;
V_2 -> V_209 = F_110 ( V_2 ) -> V_206 ;
F_112 ( V_2 ) ;
V_2 -> V_15 -= V_205 ;
V_2 -> V_207 -= V_205 ;
V_2 -> V_208 -= V_205 ;
F_8 ( V_203 , V_193 + 3 ) ;
return F_91 ( V_13 , V_203 ) ;
}
struct V_1 * F_113 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_114 ( & V_13 -> V_92 ) ;
if ( V_13 -> V_50 == V_51 )
F_28 ( V_13 , V_37 ) ;
return V_2 ;
}
static int F_115 ( struct V_182 * V_183 , struct V_12 * V_13 ,
struct V_184 * V_185 , T_4 V_15 , int V_210 ,
int V_134 , int * V_211 )
{
struct V_1 * V_2 ;
int V_69 ;
if ( V_134 & ~ ( V_212 | V_213 | V_214 | V_189 | V_215 |
V_191 | V_192 ) )
return - V_62 ;
if ( F_70 ( 1 << V_13 -> V_50 & ( V_125 | V_124 ) ) )
return - V_196 ;
if ( ( V_134 & V_212 ) || F_36 ( V_13 , V_163 ) ) {
struct V_30 * V_31 = F_18 ( V_13 ) ;
if ( V_134 & V_213 )
return - V_62 ;
V_2 = F_114 ( & V_31 -> V_85 ) ;
if ( V_2 ) {
F_26 ( V_13 , V_2 , V_44 ,
V_32 ) ;
V_185 -> V_187 |= V_212 ;
goto V_216;
}
if ( V_134 & V_212 )
return - V_60 ;
}
V_2 = F_68 ( V_13 , V_134 , V_210 , & V_69 ) ;
F_63 ( V_13 ) ;
if ( V_2 == NULL ) {
if ( V_69 == - V_196 && V_13 -> V_50 == V_70 )
V_69 = - V_198 ;
F_64 ( V_13 ) ;
return V_69 ;
}
if ( V_13 -> V_50 == V_51 )
F_28 ( V_13 , V_32 ) ;
F_64 ( V_13 ) ;
V_216:
V_185 -> V_187 |= V_190 ;
if ( V_2 -> V_15 > V_15 )
V_185 -> V_187 |= V_214 ;
else
V_15 = V_2 -> V_15 ;
V_69 = F_116 ( V_2 , 0 , V_185 -> V_194 , V_15 ) ;
if ( ! V_69 )
V_69 = ( V_134 & V_214 ) ? V_2 -> V_15 : V_15 ;
F_117 ( V_13 , V_2 ) ;
return V_69 ;
}
static void F_118 ( struct V_12 * V_13 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_12 * V_217 = NULL ;
F_63 ( V_13 ) ;
if ( V_31 -> V_156 != NULL ) {
V_217 = V_31 -> V_156 ;
V_31 -> V_156 = NULL ;
F_64 ( V_13 ) ;
V_31 = F_18 ( V_217 ) ;
F_63 ( V_217 ) ;
F_119 ( V_13 ) ;
V_13 = V_217 ;
}
if ( F_120 ( & V_31 -> V_113 ) )
F_121 ( & V_31 -> V_119 . V_13 ) ;
F_64 ( V_13 ) ;
if ( V_217 )
F_66 ( V_217 ) ;
}
static int T_5 F_122 ( void )
{
return F_123 ( V_218 , & V_219 ) ;
}
static void T_6 F_124 ( void )
{
F_125 ( V_218 , & V_219 ) ;
}
