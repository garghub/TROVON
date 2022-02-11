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
F_31 ( L_1 ,
( unsigned int ) V_58 -> V_6 [ 0 ] ) ;
return - V_61 ;
}
switch ( V_58 -> V_6 [ 1 ] ) {
case V_52 :
switch ( V_31 -> V_34 ) {
case V_42 :
switch ( V_58 -> V_6 [ 4 ] ) {
case V_62 :
F_32 ( & V_31 -> V_63 , 0 ) ;
break;
case V_53 :
F_32 ( & V_31 -> V_63 , V_59 = 1 ) ;
break;
}
break;
case V_41 :
if ( V_58 -> V_6 [ 4 ] == V_53 )
F_32 ( & V_31 -> V_63 , V_59 = 1 ) ;
break;
}
break;
case V_57 :
if ( V_31 -> V_34 != V_40 )
break;
F_33 ( V_59 = V_58 -> V_6 [ 4 ] , & V_31 -> V_63 ) ;
break;
default:
F_31 ( L_2 ,
( unsigned int ) V_58 -> V_6 [ 1 ] ) ;
return - V_61 ;
}
if ( V_59 )
V_13 -> V_64 ( V_13 ) ;
return 0 ;
}
static int F_34 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_18 * V_58 = F_14 ( V_2 ) ;
T_1 V_65 = V_58 -> V_6 [ 0 ] ;
V_31 -> V_35 = V_31 -> V_34 = V_42 ;
F_4 ( V_2 , sizeof( * V_58 ) ) ;
while ( V_65 > 0 ) {
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
V_65 -- ;
}
return 0 ;
}
static int F_35 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_18 * V_58 = F_14 ( V_2 ) ;
struct V_66 * V_67 ;
int V_68 = 0 ;
F_29 ( V_13 -> V_50 == V_69 ) ;
switch ( V_58 -> V_26 ) {
case V_70 :
F_24 ( V_13 , V_2 , V_71 , V_37 ) ;
break;
case V_72 :
F_13 ( V_13 , V_2 , V_44 , NULL , 0 , V_37 ) ;
V_13 -> V_50 = V_69 ;
if ( ! F_36 ( V_13 , V_73 ) )
V_13 -> V_74 ( V_13 ) ;
break;
case V_75 :
F_13 ( V_13 , V_2 , V_44 , NULL , 0 , V_37 ) ;
break;
case V_76 :
switch ( V_58 -> V_77 ) {
case V_78 :
V_31 -> V_79 = 0 ;
break;
case V_80 :
V_31 -> V_79 = 1 ;
break;
default:
V_68 = - V_60 ;
goto V_81;
}
case V_82 :
F_32 ( & V_31 -> V_63 , 0 ) ;
F_13 ( V_13 , V_2 , V_44 , NULL , 0 , V_37 ) ;
break;
case V_83 :
if ( F_37 ( & V_31 -> V_84 ) >= V_85 ) {
F_38 ( & V_13 -> V_86 ) ;
break;
}
F_4 ( V_2 , 4 ) ;
V_67 = & V_31 -> V_84 ;
goto V_67;
case V_87 :
F_4 ( V_2 , 1 ) ;
case V_88 :
F_4 ( V_2 , 3 ) ;
if ( ! F_39 ( V_31 -> V_35 ) ) {
V_68 = F_40 ( V_13 , V_2 ) ;
if ( ! V_68 )
return V_89 ;
V_68 = - V_90 ;
break;
}
if ( V_31 -> V_54 == 0 ) {
F_38 ( & V_13 -> V_86 ) ;
V_68 = - V_90 ;
break;
}
V_31 -> V_54 -- ;
V_67 = & V_13 -> V_91 ;
goto V_67;
case V_48 :
F_30 ( V_13 , V_2 ) ;
break;
case V_92 :
V_68 = F_34 ( V_13 , V_2 ) ;
break;
case V_36 :
V_68 = F_34 ( V_13 , V_2 ) ;
if ( V_68 )
break;
case V_93 :
if ( ! V_31 -> V_79 )
break;
case V_94 :
if ( ! F_39 ( V_31 -> V_34 ) ) {
F_32 ( & V_31 -> V_63 , 1 ) ;
V_13 -> V_64 ( V_13 ) ;
}
if ( V_13 -> V_50 == V_51 )
break;
V_13 -> V_50 = V_51 ;
F_28 ( V_13 , V_37 ) ;
break;
case V_95 :
V_13 -> V_50 = V_96 ;
V_31 -> V_54 = 0 ;
break;
default:
F_31 ( L_3 ,
V_58 -> V_26 ) ;
V_68 = - V_60 ;
}
V_81:
F_41 ( V_2 ) ;
return ( V_68 == - V_90 ) ? V_97 : V_89 ;
V_67:
V_2 -> V_98 = NULL ;
F_42 ( V_2 , V_13 ) ;
F_43 ( V_67 , V_2 ) ;
if ( ! F_36 ( V_13 , V_73 ) )
V_13 -> V_99 ( V_13 ) ;
return V_89 ;
}
static void F_44 ( struct V_12 * V_13 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
F_45 ( & V_13 -> V_91 ) ;
F_45 ( & V_31 -> V_84 ) ;
}
static T_1 F_46 ( const T_1 * V_100 , unsigned int V_101 )
{
unsigned int V_102 ;
T_1 V_103 = V_104 ;
for ( V_102 = 0 ; V_102 < V_101 ; V_102 ++ ) {
T_1 V_105 = V_100 [ V_102 ] ;
if ( V_105 > V_103 && V_105 < V_106 )
V_103 = V_105 ;
}
return V_103 ;
}
static int F_47 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_18 * V_58 ;
T_1 V_65 ;
if ( ! F_48 ( V_2 , sizeof( * V_58 ) + 4 ) )
return - V_60 ;
V_58 = F_14 ( V_2 ) ;
if ( V_58 -> V_28 != V_44 )
return - V_107 ;
V_65 = V_58 -> V_6 [ 4 ] ;
while ( V_65 > 0 ) {
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
V_65 -- ;
}
return F_20 ( V_13 ) ;
}
static int F_49 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_18 * V_58 = F_14 ( V_2 ) ;
if ( V_58 -> V_28 != V_44 )
return - V_107 ;
return F_17 ( V_13 , V_94 , 0 ,
NULL , 0 , V_37 ) ;
}
static void F_50 ( struct V_12 * V_13 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
if ( ! F_39 ( V_31 -> V_34 ) ) {
F_32 ( & V_31 -> V_63 , 1 ) ;
V_13 -> V_64 ( V_13 ) ;
}
F_28 ( V_13 , V_37 ) ;
}
static int F_51 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_18 * V_58 = F_14 ( V_2 ) ;
int V_68 = V_89 ;
switch ( V_58 -> V_26 ) {
case V_87 :
F_4 ( V_2 , 1 ) ;
case V_88 :
F_4 ( V_2 , 3 ) ;
if ( ! F_39 ( V_31 -> V_35 ) ) {
V_68 = F_40 ( V_13 , V_2 ) ;
if ( ! V_68 )
return V_89 ;
V_68 = V_97 ;
break;
}
if ( V_31 -> V_54 == 0 ) {
F_38 ( & V_13 -> V_86 ) ;
V_68 = V_97 ;
break;
}
V_31 -> V_54 -- ;
V_2 -> V_98 = NULL ;
F_42 ( V_2 , V_13 ) ;
F_43 ( & V_13 -> V_91 , V_2 ) ;
if ( ! F_36 ( V_13 , V_73 ) )
V_13 -> V_99 ( V_13 ) ;
return V_89 ;
case V_108 :
if ( V_13 -> V_50 != V_109 )
break;
if ( ! F_36 ( V_13 , V_73 ) )
V_13 -> V_74 ( V_13 ) ;
if ( F_47 ( V_13 , V_2 ) ) {
V_13 -> V_50 = V_69 ;
break;
}
if ( V_31 -> V_79 == V_78 )
V_13 -> V_50 = V_96 ;
else {
V_13 -> V_50 = V_51 ;
F_50 ( V_13 ) ;
}
break;
case V_110 :
if ( V_13 -> V_50 != V_109 )
break;
if ( F_49 ( V_13 , V_2 ) ) {
V_13 -> V_50 = V_69 ;
break;
}
V_13 -> V_50 = V_51 ;
F_50 ( V_13 ) ;
break;
case V_111 :
break;
case V_48 :
F_30 ( V_13 , V_2 ) ;
break;
}
F_41 ( V_2 ) ;
return V_68 ;
}
static struct V_12 * F_52 ( const struct V_112 * V_113 ,
const struct V_22 * V_45 ,
T_1 V_27 )
{
struct V_12 * V_114 ;
T_3 V_115 = F_53 ( V_45 ) ;
F_54 (sknode, hlist) {
struct V_30 * V_116 = F_18 ( V_114 ) ;
if ( V_116 -> V_117 . V_118 != V_115 )
continue;
if ( V_116 -> V_27 != V_27 )
continue;
if ( V_114 -> V_50 == V_69 )
continue;
F_55 ( V_114 ) ;
return V_114 ;
}
return NULL ;
}
static int F_56 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_12 * V_114 ;
struct V_18 * V_58 ;
struct V_22 V_45 ;
T_1 V_27 ;
if ( ! F_3 ( V_2 , sizeof( * V_58 ) ) )
goto V_119;
V_58 = F_14 ( V_2 ) ;
V_27 = V_58 -> V_27 ;
if ( V_27 == V_120 )
goto V_119;
F_57 ( V_2 , & V_45 ) ;
V_114 = F_52 ( & V_31 -> V_113 , & V_45 , V_27 ) ;
if ( V_114 )
return F_58 ( V_114 , V_2 , 1 ) ;
switch ( V_58 -> V_26 ) {
case V_70 :
if ( V_13 -> V_50 != V_121 || F_59 ( V_13 ) ) {
F_24 ( V_13 , V_2 , V_71 ,
V_37 ) ;
break;
}
F_60 ( & V_13 -> V_91 , V_2 ) ;
F_61 ( V_13 ) ;
if ( ! F_36 ( V_13 , V_73 ) )
V_13 -> V_99 ( V_13 ) ;
return V_89 ;
case V_72 :
F_13 ( V_13 , V_2 , V_44 , NULL , 0 , V_37 ) ;
break;
case V_83 :
F_26 ( V_13 , V_2 , V_120 , V_37 ) ;
break;
case V_76 :
case V_75 :
case V_82 :
break;
default:
if ( ( 1 << V_13 -> V_50 )
& ~ ( V_122 | V_123 | V_124 ) )
return F_51 ( V_13 , V_2 ) ;
}
V_119:
F_41 ( V_2 ) ;
return V_89 ;
}
static int F_62 ( struct V_12 * V_13 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_18 * V_9 ;
struct V_1 * V_2 ;
V_2 = F_5 ( V_13 , NULL , 0 , V_32 ) ;
if ( ! V_2 )
return - V_24 ;
V_9 = F_14 ( V_2 ) ;
V_9 -> V_25 = 0 ;
V_9 -> V_26 = V_125 ;
V_9 -> V_27 = V_31 -> V_27 ;
V_9 -> V_6 [ 0 ] = V_38 ;
return F_16 ( V_13 , V_2 , NULL ) ;
}
static void F_63 ( struct V_12 * V_13 , long V_126 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
int V_127 = 0 ;
F_55 ( V_13 ) ;
F_64 ( V_13 ) ;
F_65 ( V_13 ) ;
if ( ( 1 << V_13 -> V_50 ) & ( V_128 | V_129 ) ) {
if ( V_13 -> V_130 == F_35 )
F_62 ( V_13 ) ;
else
F_19 ( V_13 , V_72 , V_38 ,
NULL , 0 ) ;
}
V_13 -> V_50 = V_131 ;
V_127 = V_31 -> V_127 ;
V_31 -> V_127 = 0 ;
F_66 ( V_13 ) ;
if ( V_127 )
F_67 ( V_13 ) ;
F_68 ( V_13 ) ;
}
static struct V_12 * F_69 ( struct V_12 * V_13 , int V_132 , int * V_133 )
{
struct V_30 * V_31 = F_18 ( V_13 ) , * V_134 ;
struct V_12 * V_135 = NULL ;
struct V_1 * V_2 ;
struct V_18 * V_58 ;
struct V_22 V_45 , V_136 ;
int V_68 ;
T_3 V_137 ;
T_1 V_27 , V_138 , V_65 ;
T_1 V_139 = 0 ;
V_2 = F_70 ( V_13 , 0 , V_132 & V_140 , V_133 ) ;
if ( ! V_2 )
return NULL ;
F_65 ( V_13 ) ;
if ( V_13 -> V_50 != V_121 ) {
V_68 = - V_60 ;
goto V_119;
}
F_71 ( V_13 ) ;
V_68 = - V_141 ;
if ( ! F_3 ( V_2 , sizeof( * V_58 ) + 4 ) )
goto V_119;
V_58 = F_14 ( V_2 ) ;
V_27 = V_58 -> V_27 ;
switch ( V_58 -> V_142 ) {
case V_78 :
V_138 = 0 ;
break;
case V_80 :
V_138 = 1 ;
break;
default:
F_24 ( V_13 , V_2 , V_143 ,
V_32 ) ;
goto V_119;
}
V_137 = V_58 -> V_144 << 8 ;
V_65 = V_58 -> V_6 [ 4 ] ;
while ( V_65 > 0 ) {
T_1 type , V_5 [ 1 ] , V_15 = sizeof( V_5 ) ;
const T_1 * V_6 = F_1 ( V_2 , & type , & V_15 , V_5 ) ;
if ( V_6 == NULL )
goto V_119;
switch ( type ) {
case V_145 :
if ( V_15 < 1 )
goto V_119;
V_137 = ( V_137 & 0xff00 ) | V_6 [ 0 ] ;
break;
case V_146 :
V_139 = V_6 [ 0 ] != 0 ;
break;
}
V_65 -- ;
}
V_135 = F_52 ( & V_31 -> V_113 , & V_45 , V_27 ) ;
if ( F_72 ( V_135 ) ) {
F_73 ( V_135 ) ;
V_135 = NULL ;
F_24 ( V_13 , V_2 , V_71 , V_32 ) ;
goto V_119;
}
V_135 = F_74 ( F_75 ( V_13 ) , V_147 , V_32 , V_13 -> V_148 , 0 ) ;
if ( ! V_135 ) {
F_24 ( V_13 , V_2 , V_149 , V_32 ) ;
V_68 = - V_90 ;
goto V_119;
}
F_76 ( NULL , V_135 ) ;
V_135 -> V_50 = V_96 ;
V_135 -> V_130 = F_35 ;
V_135 -> V_150 = V_13 -> V_150 ;
V_135 -> V_151 = F_44 ;
V_134 = F_18 ( V_135 ) ;
F_57 ( V_2 , & V_45 ) ;
F_15 ( V_2 , & V_136 ) ;
V_134 -> V_117 . V_118 = F_53 ( & V_45 ) ;
V_134 -> V_117 . V_152 = F_53 ( & V_136 ) ;
V_134 -> V_117 . V_153 = F_77 ( & V_45 ) ;
F_55 ( V_13 ) ;
V_134 -> V_154 = V_13 ;
F_78 ( & V_134 -> V_84 ) ;
V_134 -> V_27 = V_27 ;
F_32 ( & V_134 -> V_63 , 0 ) ;
V_134 -> V_127 = 0 ;
V_134 -> V_137 = V_137 ;
V_134 -> V_54 = 0 ;
V_134 -> V_35 = V_134 -> V_34 = V_42 ;
V_134 -> V_79 = V_138 ;
V_134 -> V_139 = V_139 ;
V_68 = F_22 ( V_135 , V_2 ) ;
if ( V_68 ) {
F_68 ( V_135 ) ;
V_135 = NULL ;
goto V_119;
}
F_79 ( V_135 , & V_31 -> V_113 ) ;
V_119:
F_66 ( V_13 ) ;
F_41 ( V_2 ) ;
* V_133 = V_68 ;
return V_135 ;
}
static int F_80 ( struct V_12 * V_13 , struct V_155 * V_156 , int V_15 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
int V_68 ;
T_1 V_6 [ 4 ] = { 0 , V_38 , V_38 , V_38 } ;
if ( V_31 -> V_27 == V_120 )
V_31 -> V_27 = 1 ;
V_68 = F_19 ( V_13 , V_70 ,
V_31 -> V_79 , V_6 , 4 ) ;
if ( V_68 ) {
V_31 -> V_27 = V_120 ;
return V_68 ;
}
V_13 -> V_50 = V_109 ;
return 0 ;
}
static int F_81 ( struct V_12 * V_13 , struct V_155 * V_156 , int V_15 )
{
int V_68 ;
V_68 = F_19 ( V_13 , V_75 , V_38 ,
NULL , 0 ) ;
if ( V_68 )
return V_68 ;
V_13 -> V_50 = V_109 ;
return 0 ;
}
static int F_82 ( struct V_12 * V_13 , int V_157 , unsigned long V_158 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
int V_159 ;
int V_160 = - V_161 ;
switch ( V_157 ) {
case V_162 :
if ( V_13 -> V_50 == V_121 ) {
V_160 = - V_60 ;
break;
}
F_65 ( V_13 ) ;
if ( F_36 ( V_13 , V_163 ) &&
! F_83 ( & V_31 -> V_84 ) )
V_159 = F_84 ( & V_31 -> V_84 ) -> V_15 ;
else if ( ! F_83 ( & V_13 -> V_91 ) )
V_159 = F_84 ( & V_13 -> V_91 ) -> V_15 ;
else
V_159 = 0 ;
F_66 ( V_13 ) ;
V_160 = F_85 ( V_159 , ( int V_164 * ) V_158 ) ;
break;
case V_165 :
F_65 ( V_13 ) ;
if ( V_13 -> V_50 == V_109 )
V_160 = - V_166 ;
else if ( V_13 -> V_50 == V_51 )
V_160 = - V_167 ;
else
V_160 = F_81 ( V_13 , NULL , 0 ) ;
F_66 ( V_13 ) ;
break;
}
return V_160 ;
}
static int F_86 ( struct V_12 * V_13 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
V_13 -> V_151 = F_44 ;
F_87 ( & V_31 -> V_113 ) ;
V_31 -> V_154 = NULL ;
F_78 ( & V_31 -> V_84 ) ;
F_32 ( & V_31 -> V_63 , 0 ) ;
V_31 -> V_127 = 0 ;
V_31 -> V_137 = 0 ;
V_31 -> V_27 = V_120 ;
V_31 -> V_54 = 0 ;
V_31 -> V_35 = V_31 -> V_34 = V_42 ;
V_31 -> V_79 = 1 ;
V_31 -> V_139 = 0 ;
return 0 ;
}
static int F_88 ( struct V_12 * V_13 , int V_168 , int V_169 ,
char V_164 * V_170 , unsigned int V_171 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
int V_172 = 0 , V_68 = 0 ;
if ( V_168 != V_173 )
return - V_174 ;
if ( V_171 >= sizeof( int ) ) {
if ( F_89 ( V_172 , ( int V_164 * ) V_170 ) )
return - V_175 ;
}
F_65 ( V_13 ) ;
switch ( V_169 ) {
case V_176 :
if ( V_172 && V_172 != V_177 ) {
V_68 = - V_60 ;
break;
}
if ( ! V_31 -> V_127 == ! V_172 )
break;
if ( ! F_90 ( V_178 ) ) {
V_68 = - V_179 ;
break;
}
if ( V_172 ) {
F_66 ( V_13 ) ;
V_68 = F_91 ( V_13 ) ;
if ( V_68 > 0 ) {
V_31 -> V_127 = V_68 ;
V_68 = 0 ;
}
} else {
V_31 -> V_127 = 0 ;
F_66 ( V_13 ) ;
F_67 ( V_13 ) ;
V_68 = 0 ;
}
goto V_180;
case V_181 :
if ( ( V_13 -> V_50 == V_131 ) &&
( V_172 >= 0 ) && ( V_172 < V_120 ) )
V_31 -> V_27 = V_172 ;
else
V_68 = - V_60 ;
break;
case V_182 :
V_31 -> V_79 = ! ! V_172 ;
break;
default:
V_68 = - V_174 ;
}
F_66 ( V_13 ) ;
V_180:
return V_68 ;
}
static int F_92 ( struct V_12 * V_13 , int V_168 , int V_169 ,
char V_164 * V_170 , int V_164 * V_171 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
int V_15 , V_172 ;
if ( V_168 != V_173 )
return - V_174 ;
if ( F_89 ( V_15 , V_171 ) )
return - V_175 ;
switch ( V_169 ) {
case V_176 :
V_172 = V_31 -> V_127 ? V_177 : V_183 ;
break;
case V_184 :
V_172 = V_31 -> V_127 ;
break;
case V_181 :
V_172 = V_31 -> V_27 ;
if ( V_172 == V_120 )
return - V_60 ;
break;
case V_182 :
V_172 = V_31 -> V_79 ;
break;
default:
return - V_174 ;
}
V_15 = F_93 (unsigned int, sizeof(int), len) ;
if ( F_85 ( V_15 , V_171 ) )
return - V_175 ;
if ( F_85 ( V_172 , ( int V_164 * ) V_170 ) )
return - V_175 ;
return 0 ;
}
static int F_94 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_18 * V_9 ;
int V_68 ;
if ( F_39 ( V_31 -> V_34 ) &&
! F_95 ( & V_31 -> V_63 , - 1 , 0 ) ) {
F_41 ( V_2 ) ;
return - V_90 ;
}
F_96 ( V_2 , 3 + V_31 -> V_139 ) ;
F_12 ( V_2 ) ;
V_9 = F_14 ( V_2 ) ;
V_9 -> V_25 = 0 ;
if ( V_31 -> V_139 ) {
V_9 -> V_26 = V_87 ;
V_9 -> V_6 [ 0 ] = 0 ;
} else
V_9 -> V_26 = V_88 ;
V_9 -> V_27 = V_31 -> V_27 ;
V_68 = F_16 ( V_13 , V_2 , NULL ) ;
if ( V_68 && F_39 ( V_31 -> V_34 ) )
F_38 ( & V_31 -> V_63 ) ;
return V_68 ;
}
static int F_97 ( struct V_12 * V_13 , struct V_185 * V_186 , T_4 V_15 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_1 * V_2 ;
long V_187 ;
int V_132 = V_186 -> V_188 ;
int V_68 , V_189 ;
if ( V_15 > V_190 )
return - V_191 ;
if ( ( V_186 -> V_188 & ~ ( V_192 | V_193 | V_194 |
V_195 ) ) ||
! ( V_186 -> V_188 & V_193 ) )
return - V_61 ;
V_2 = F_98 ( V_13 , V_17 + V_15 ,
V_132 & V_192 , & V_68 ) ;
if ( ! V_2 )
return V_68 ;
F_8 ( V_2 , V_196 + 3 + V_31 -> V_139 ) ;
V_68 = F_99 ( F_100 ( V_2 , V_15 ) , V_186 , V_15 ) ;
if ( V_68 < 0 )
goto V_197;
F_65 ( V_13 ) ;
V_187 = F_101 ( V_13 , V_132 & V_192 ) ;
if ( ( 1 << V_13 -> V_50 ) & ( V_123 | V_122 ) ) {
V_68 = - V_198 ;
goto V_81;
}
if ( V_13 -> V_50 != V_51 ) {
V_199:
V_68 = F_102 ( V_13 , & V_187 ) ;
if ( V_68 )
goto V_81;
if ( V_13 -> V_50 == V_69 ) {
V_68 = - V_200 ;
goto V_81;
}
}
F_29 ( V_13 -> V_50 != V_51 ) ;
V_189 = F_103 ( & V_31 -> V_63 ) ;
while ( ! V_189 ) {
F_104 ( V_201 , V_202 ) ;
if ( ! V_187 ) {
V_68 = - V_203 ;
goto V_81;
}
if ( F_105 ( V_204 ) ) {
V_68 = F_106 ( V_187 ) ;
goto V_81;
}
F_107 ( F_108 ( V_13 ) , & V_201 ) ;
V_189 = F_109 ( V_13 , & V_187 , F_103 ( & V_31 -> V_63 ) , & V_201 ) ;
F_110 ( F_108 ( V_13 ) , & V_201 ) ;
if ( V_13 -> V_50 != V_51 )
goto V_199;
}
V_68 = F_94 ( V_13 , V_2 ) ;
if ( V_68 >= 0 )
V_68 = V_15 ;
V_2 = NULL ;
V_81:
F_66 ( V_13 ) ;
V_197:
F_41 ( V_2 ) ;
return V_68 ;
}
int F_111 ( struct V_12 * V_13 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
return F_103 ( & V_31 -> V_63 ) ;
}
int F_112 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_1 * V_205 , * V_206 ;
int V_207 = 0 ;
if ( F_18 ( V_13 ) -> V_139 )
return F_94 ( V_13 , V_2 ) ;
V_205 = F_6 ( V_17 , V_37 ) ;
if ( ! V_205 ) {
F_41 ( V_2 ) ;
return - V_24 ;
}
F_113 ( V_205 ) -> V_208 = V_2 ;
V_205 -> V_15 += V_2 -> V_15 ;
V_205 -> V_209 += V_205 -> V_15 ;
V_205 -> V_210 += V_205 -> V_15 ;
F_114 (skb, fs)
V_207 += V_206 -> V_15 ;
V_2 -> V_211 = F_113 ( V_2 ) -> V_208 ;
F_115 ( V_2 ) ;
V_2 -> V_15 -= V_207 ;
V_2 -> V_209 -= V_207 ;
V_2 -> V_210 -= V_207 ;
F_8 ( V_205 , V_196 + 3 ) ;
return F_94 ( V_13 , V_205 ) ;
}
struct V_1 * F_116 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_117 ( & V_13 -> V_91 ) ;
if ( V_13 -> V_50 == V_51 )
F_28 ( V_13 , V_37 ) ;
return V_2 ;
}
static int F_118 ( struct V_12 * V_13 , struct V_185 * V_186 , T_4 V_15 ,
int V_212 , int V_132 , int * V_213 )
{
struct V_1 * V_2 ;
int V_68 ;
if ( V_132 & ~ ( V_214 | V_215 | V_216 | V_192 | V_217 |
V_194 | V_195 ) )
return - V_61 ;
if ( F_72 ( 1 << V_13 -> V_50 & ( V_123 | V_122 ) ) )
return - V_198 ;
if ( ( V_132 & V_214 ) || F_36 ( V_13 , V_163 ) ) {
struct V_30 * V_31 = F_18 ( V_13 ) ;
if ( V_132 & V_215 )
return - V_61 ;
V_2 = F_117 ( & V_31 -> V_84 ) ;
if ( V_2 ) {
F_26 ( V_13 , V_2 , V_44 ,
V_32 ) ;
V_186 -> V_188 |= V_214 ;
goto V_218;
}
if ( V_132 & V_214 )
return - V_60 ;
}
V_2 = F_70 ( V_13 , V_132 , V_212 , & V_68 ) ;
F_65 ( V_13 ) ;
if ( V_2 == NULL ) {
if ( V_68 == - V_198 && V_13 -> V_50 == V_69 )
V_68 = - V_200 ;
F_66 ( V_13 ) ;
return V_68 ;
}
if ( V_13 -> V_50 == V_51 )
F_28 ( V_13 , V_32 ) ;
F_66 ( V_13 ) ;
V_218:
V_186 -> V_188 |= V_193 ;
if ( V_2 -> V_15 > V_15 )
V_186 -> V_188 |= V_216 ;
else
V_15 = V_2 -> V_15 ;
V_68 = F_119 ( V_2 , 0 , V_186 , V_15 ) ;
if ( ! V_68 )
V_68 = ( V_132 & V_216 ) ? V_2 -> V_15 : V_15 ;
F_120 ( V_13 , V_2 ) ;
return V_68 ;
}
static void F_121 ( struct V_12 * V_13 )
{
struct V_30 * V_31 = F_18 ( V_13 ) ;
struct V_12 * V_219 = NULL ;
F_65 ( V_13 ) ;
if ( V_31 -> V_154 != NULL ) {
V_219 = V_31 -> V_154 ;
V_31 -> V_154 = NULL ;
F_66 ( V_13 ) ;
V_31 = F_18 ( V_219 ) ;
F_65 ( V_219 ) ;
F_122 ( V_13 ) ;
V_13 = V_219 ;
}
if ( F_123 ( & V_31 -> V_113 ) )
F_124 ( & V_31 -> V_117 . V_13 ) ;
F_66 ( V_13 ) ;
if ( V_219 )
F_68 ( V_219 ) ;
}
static int T_5 F_125 ( void )
{
return F_126 ( V_220 , & V_221 ) ;
}
static void T_6 F_127 ( void )
{
F_128 ( V_220 , & V_221 ) ;
}
