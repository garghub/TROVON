int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 == V_2 -> V_4 )
return 0 ;
if ( V_2 -> V_4 != NULL )
return - V_5 ;
V_2 -> V_4 = F_2 ( V_4 ) ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
void * F_5 ( struct V_1 * V_2 , T_1 V_6 )
{
V_2 -> V_7 = F_6 ( V_6 , V_8 ) ;
return V_2 -> V_7 ;
}
int F_7 ( struct V_1 * V_2 , int V_9 )
{
struct V_10 * V_11 ;
int V_12 ;
if ( V_9 < 1 )
return - V_13 ;
V_11 = F_8 ( V_9 , sizeof( * V_11 ) , V_8 ) ;
if ( ! V_11 )
return - V_14 ;
V_2 -> V_15 = V_11 ;
V_2 -> V_16 = V_9 ;
for ( V_12 = 0 ; V_12 < V_9 ; ++ V_12 ) {
V_11 = & V_2 -> V_15 [ V_12 ] ;
V_11 -> V_3 = V_2 ;
V_11 -> V_17 = V_12 ;
V_11 -> V_18 = V_19 ;
F_9 ( & V_11 -> V_20 ) ;
V_11 -> V_21 = - 1 ;
}
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
int V_12 ;
struct V_10 * V_11 ;
if ( V_2 -> V_15 ) {
for ( V_12 = 0 ; V_12 < V_2 -> V_16 ; V_12 ++ ) {
V_11 = & V_2 -> V_15 [ V_12 ] ;
if ( V_11 -> V_22 & V_23 )
F_11 ( V_11 -> V_7 ) ;
F_12 ( V_11 ) ;
if ( V_11 -> V_24 ) {
F_13 ( V_2 , V_11 , 0 ) ;
F_11 ( V_11 -> V_24 ) ;
}
}
F_11 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
V_2 -> V_16 = 0 ;
}
F_11 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
V_2 -> V_25 = NULL ;
V_2 -> V_26 = NULL ;
V_2 -> V_27 = NULL ;
V_2 -> V_28 = 0 ;
V_2 -> V_29 = 0 ;
V_2 -> V_30 = false ;
V_2 -> V_31 = 0 ;
V_2 -> V_32 = NULL ;
V_2 -> V_33 = NULL ;
V_2 -> V_34 = NULL ;
V_2 -> V_35 = NULL ;
F_3 ( V_2 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
F_15 ( V_2 ) ;
F_16 ( & V_2 -> V_36 ) ;
V_2 -> V_37 = false ;
V_2 -> V_38 ++ ;
if ( V_2 -> V_25 )
V_2 -> V_25 -> V_39 ( V_2 ) ;
F_10 ( V_2 ) ;
F_17 ( & V_2 -> V_36 ) ;
}
static int F_18 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
return - V_13 ;
}
int F_19 ( struct V_1 * V_2 , struct V_10 * V_11 ,
struct V_40 * V_41 , unsigned int * V_42 )
{
return - V_13 ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_40 * V_41 ,
int (* F_21)( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_40 * V_41 ,
unsigned long V_43 ) ,
unsigned long V_43 )
{
unsigned long V_44 = V_45 + F_22 ( V_46 ) ;
int V_47 ;
while ( F_23 ( V_45 , V_44 ) ) {
V_47 = F_21 ( V_2 , V_11 , V_41 , V_43 ) ;
if ( V_47 != - V_48 )
return V_47 ;
F_24 () ;
}
return - V_49 ;
}
int F_25 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_40 * V_41 ,
unsigned int * V_42 ,
unsigned int V_50 )
{
unsigned int V_51 = 1 << F_26 ( V_41 -> V_52 ) ;
if ( ! V_50 )
V_50 = V_51 ;
switch ( V_42 [ 0 ] ) {
case V_53 :
V_11 -> V_54 &= ~ V_50 ;
break;
case V_55 :
V_11 -> V_54 |= V_50 ;
break;
case V_56 :
V_42 [ 1 ] = ( V_11 -> V_54 & V_50 ) ? V_57 : V_58 ;
return V_41 -> V_59 ;
default:
return - V_13 ;
}
return 0 ;
}
unsigned int F_27 ( struct V_10 * V_11 ,
unsigned int * V_42 )
{
unsigned int V_60 = ( V_11 -> V_61 < 32 ) ? ( ( 1 << V_11 -> V_61 ) - 1 )
: 0xffffffff ;
unsigned int V_50 = V_42 [ 0 ] & V_60 ;
unsigned int V_62 = V_42 [ 1 ] ;
if ( V_50 ) {
V_11 -> V_63 &= ~ V_50 ;
V_11 -> V_63 |= ( V_62 & V_50 ) ;
}
return V_50 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_40 * V_41 , unsigned int * V_42 )
{
struct V_40 V_64 ;
int V_47 ;
static const unsigned V_65 = 32 ;
unsigned V_66 = F_26 ( V_41 -> V_52 ) ;
const unsigned V_67 =
( V_66 < V_65 ) ? 0 : V_66 ;
unsigned int V_68 [ 2 ] ;
memset ( V_68 , 0 , sizeof( V_68 ) ) ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
V_64 . V_41 = V_69 ;
V_64 . V_52 = V_67 ;
V_64 . V_59 = 2 ;
V_64 . V_70 = V_41 -> V_70 ;
if ( V_41 -> V_41 == V_71 ) {
if ( ! ( V_11 -> V_72 & V_73 ) )
return - V_13 ;
V_68 [ 0 ] = 1 << ( V_66 - V_67 ) ;
V_68 [ 1 ] = V_42 [ 0 ] ? ( 1 << ( V_66 - V_67 ) )
: 0 ;
}
V_47 = V_11 -> V_74 ( V_2 , V_11 , & V_64 , V_68 ) ;
if ( V_47 < 0 )
return V_47 ;
if ( V_41 -> V_41 == V_75 )
V_42 [ 0 ] = ( V_68 [ 1 ] >> ( V_66 - V_67 ) ) & 1 ;
return 1 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_76 * V_24 ;
unsigned int V_77 ;
int V_47 ;
if ( ( V_11 -> V_72 & ( V_78 | V_79 ) ) == 0 ) {
F_30 ( V_2 -> V_80 ,
L_1 ) ;
return - V_13 ;
}
if ( ! V_11 -> V_81 ) {
F_30 ( V_2 -> V_80 ,
L_2 ) ;
return - V_13 ;
}
V_24 = F_6 ( sizeof( * V_24 ) , V_8 ) ;
if ( ! V_24 )
return - V_14 ;
F_31 ( & V_24 -> V_82 ) ;
V_11 -> V_24 = V_24 ;
V_24 -> V_83 = V_84 * 1024 ;
V_77 = V_85 * 1024 ;
if ( V_77 > V_24 -> V_83 )
V_77 = V_24 -> V_83 ;
if ( F_13 ( V_2 , V_11 , V_77 ) < 0 ) {
F_30 ( V_2 -> V_80 , L_3 ) ;
return - V_14 ;
}
if ( V_11 -> V_86 ) {
V_47 = V_11 -> V_86 ( V_2 , V_11 , V_77 ) ;
if ( V_47 < 0 )
return V_47 ;
}
F_32 ( V_11 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_47 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_16 ; V_12 ++ ) {
V_11 = & V_2 -> V_15 [ V_12 ] ;
if ( V_11 -> type == V_87 )
continue;
if ( V_11 -> type == V_88 ) {
if ( V_11 -> V_61 < 32 )
V_11 -> V_54 = ( 1 << V_11 -> V_61 ) - 1 ;
else
V_11 -> V_54 = 0xffffffff ;
}
if ( V_11 -> V_89 == 0 )
V_11 -> V_89 = 1 ;
if ( V_11 -> V_90 ) {
V_47 = F_29 ( V_2 , V_11 ) ;
if ( V_47 )
return V_47 ;
}
if ( ! V_11 -> V_91 && ! V_11 -> V_92 )
V_11 -> V_91 = & V_93 ;
if ( ! V_11 -> V_94 && V_11 -> V_74 )
V_11 -> V_94 = F_28 ;
if ( ! V_11 -> V_95 && V_11 -> V_74 )
V_11 -> V_95 = F_28 ;
if ( ! V_11 -> V_94 )
V_11 -> V_94 = F_19 ;
if ( ! V_11 -> V_95 )
V_11 -> V_95 = F_19 ;
if ( ! V_11 -> V_74 )
V_11 -> V_74 = F_19 ;
if ( ! V_11 -> V_96 )
V_11 -> V_96 = F_19 ;
if ( ! V_11 -> V_97 )
V_11 -> V_97 = F_18 ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_47 ;
V_47 = F_33 ( V_2 ) ;
if ( V_47 < 0 )
return V_47 ;
F_16 ( & V_2 -> V_36 ) ;
V_2 -> V_37 = true ;
F_17 ( & V_2 -> V_36 ) ;
return 0 ;
}
static void * F_35 ( struct V_98 * V_99 , const char * V_100 )
{
char * * V_101 = ( char * * ) V_99 -> V_26 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_99 -> V_102 ; V_12 ++ ) {
if ( strcmp ( * V_101 , V_100 ) == 0 )
return V_101 ;
V_101 = ( void * ) V_101 + V_99 -> V_103 ;
}
return NULL ;
}
static void F_36 ( struct V_98 * V_99 )
{
unsigned int V_12 ;
const char * const * V_101 ;
F_37 ( L_4 ,
V_99 -> V_104 ) ;
V_101 = V_99 -> V_26 ;
for ( V_12 = 0 ; V_12 < V_99 -> V_102 ; V_12 ++ ) {
F_37 ( L_5 , * V_101 ) ;
V_101 = ( const char * * ) ( ( char * ) V_101 + V_99 -> V_103 ) ;
}
if ( V_99 -> V_102 == 0 )
F_37 ( L_5 , V_99 -> V_104 ) ;
}
int F_38 ( struct V_1 * V_2 ,
struct V_3 * V_3 ,
const char * V_100 ,
int (* F_21)( struct V_1 * V_2 ,
const T_2 * V_42 , T_1 V_6 ,
unsigned long V_43 ) ,
unsigned long V_43 )
{
const struct V_105 * V_106 ;
int V_47 ;
if ( ! F_21 )
return - V_13 ;
V_47 = F_39 ( & V_106 , V_100 , V_3 ) ;
if ( V_47 == 0 ) {
V_47 = F_21 ( V_2 , V_106 -> V_42 , V_106 -> V_6 , V_43 ) ;
F_40 ( V_106 ) ;
}
return V_47 < 0 ? V_47 : 0 ;
}
int F_41 ( struct V_1 * V_2 ,
unsigned long V_107 , unsigned long V_108 )
{
if ( ! V_107 ) {
F_30 ( V_2 -> V_80 ,
L_6 ,
V_2 -> V_26 ) ;
return - V_13 ;
}
if ( ! F_42 ( V_107 , V_108 , V_2 -> V_26 ) ) {
F_30 ( V_2 -> V_80 , L_7 ,
V_2 -> V_26 , V_107 , V_108 ) ;
return - V_109 ;
}
return 0 ;
}
int F_43 ( struct V_1 * V_2 ,
unsigned long V_107 , unsigned long V_108 )
{
int V_47 ;
V_47 = F_41 ( V_2 , V_107 , V_108 ) ;
if ( V_47 == 0 ) {
V_2 -> V_28 = V_107 ;
V_2 -> V_29 = V_108 ;
}
return V_47 ;
}
void F_44 ( struct V_1 * V_2 )
{
if ( V_2 -> V_31 ) {
F_45 ( V_2 -> V_31 , V_2 ) ;
V_2 -> V_31 = 0 ;
}
if ( V_2 -> V_28 && V_2 -> V_29 ) {
F_46 ( V_2 -> V_28 , V_2 -> V_29 ) ;
V_2 -> V_28 = 0 ;
V_2 -> V_29 = 0 ;
}
}
int F_47 ( struct V_1 * V_2 , struct V_110 * V_111 )
{
struct V_98 * V_99 ;
int V_47 ;
if ( V_2 -> V_37 )
return - V_48 ;
F_48 ( & V_112 ) ;
for ( V_99 = V_113 ; V_99 ; V_99 = V_99 -> V_114 ) {
if ( ! F_49 ( V_99 -> V_115 ) )
continue;
if ( V_99 -> V_102 ) {
V_2 -> V_27 = F_35 ( V_99 , V_111 -> V_26 ) ;
if ( V_2 -> V_27 )
break;
} else if ( strcmp ( V_99 -> V_104 , V_111 -> V_26 ) == 0 )
break;
F_50 ( V_99 -> V_115 ) ;
}
if ( V_99 == NULL ) {
for ( V_99 = V_113 ; V_99 ; V_99 = V_99 -> V_114 ) {
if ( ! F_49 ( V_99 -> V_115 ) )
continue;
F_36 ( V_99 ) ;
F_50 ( V_99 -> V_115 ) ;
}
V_47 = - V_109 ;
goto V_116;
}
if ( V_99 -> V_117 == NULL ) {
F_30 ( V_2 -> V_80 ,
L_8 ,
V_99 -> V_104 ) ;
F_50 ( V_99 -> V_115 ) ;
V_47 = - V_118 ;
goto V_116;
}
V_2 -> V_25 = V_99 ;
V_2 -> V_26 = V_2 -> V_27 ? * ( const char * * ) V_2 -> V_27
: V_2 -> V_25 -> V_104 ;
V_47 = V_99 -> V_117 ( V_2 , V_111 ) ;
if ( V_47 >= 0 )
V_47 = F_34 ( V_2 ) ;
if ( V_47 < 0 ) {
F_14 ( V_2 ) ;
F_50 ( V_99 -> V_115 ) ;
}
V_116:
F_51 ( & V_112 ) ;
return V_47 ;
}
int F_52 ( struct V_3 * V_119 ,
struct V_98 * V_25 , unsigned long V_43 )
{
struct V_1 * V_2 ;
int V_47 ;
if ( ! V_119 ) {
F_53 ( L_9 ) ;
return - V_13 ;
}
if ( ! V_25 ) {
F_30 ( V_119 ,
L_10 ) ;
return - V_13 ;
}
if ( ! V_25 -> V_120 ) {
F_30 ( V_119 ,
L_11 ,
V_25 -> V_104 ) ;
return - V_13 ;
}
V_2 = F_54 ( V_119 ) ;
if ( F_55 ( V_2 ) ) {
F_30 ( V_119 ,
L_12 ,
V_25 -> V_104 ) ;
return F_56 ( V_2 ) ;
}
V_2 -> V_25 = V_25 ;
V_2 -> V_26 = V_2 -> V_25 -> V_104 ;
V_47 = V_25 -> V_120 ( V_2 , V_43 ) ;
if ( V_47 >= 0 )
V_47 = F_34 ( V_2 ) ;
F_51 ( & V_2 -> V_121 ) ;
if ( V_47 < 0 ) {
F_30 ( V_119 ,
L_13 ,
V_25 -> V_104 ) ;
F_57 ( V_119 ) ;
} else {
F_58 ( V_2 -> V_80 ,
L_14 ,
V_25 -> V_104 , V_2 -> V_26 ) ;
}
return V_47 ;
}
void F_59 ( struct V_3 * V_119 )
{
if ( V_119 == NULL )
return;
F_57 ( V_119 ) ;
}
int F_60 ( struct V_98 * V_25 )
{
F_48 ( & V_112 ) ;
V_25 -> V_114 = V_113 ;
V_113 = V_25 ;
F_51 ( & V_112 ) ;
return 0 ;
}
void F_61 ( struct V_98 * V_25 )
{
struct V_98 * V_122 ;
int V_12 ;
F_48 ( & V_112 ) ;
if ( V_113 == V_25 ) {
V_113 = V_25 -> V_114 ;
} else {
for ( V_122 = V_113 ; V_122 -> V_114 ; V_122 = V_122 -> V_114 ) {
if ( V_122 -> V_114 == V_25 ) {
V_122 -> V_114 = V_25 -> V_114 ;
break;
}
}
}
F_51 ( & V_112 ) ;
for ( V_12 = 0 ; V_12 < V_123 ; V_12 ++ ) {
struct V_1 * V_2 = F_62 ( V_12 ) ;
if ( ! V_2 )
continue;
F_48 ( & V_2 -> V_121 ) ;
if ( V_2 -> V_37 && V_2 -> V_25 == V_25 ) {
if ( V_2 -> V_124 )
F_30 ( V_2 -> V_80 ,
L_15 ,
V_2 -> V_124 ) ;
F_14 ( V_2 ) ;
}
F_51 ( & V_2 -> V_121 ) ;
F_63 ( V_2 ) ;
}
}
