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
unsigned int * V_42 ,
unsigned int V_43 )
{
unsigned int V_44 = 1 << F_21 ( V_41 -> V_45 ) ;
if ( ! V_43 )
V_43 = V_44 ;
switch ( V_42 [ 0 ] ) {
case V_46 :
V_11 -> V_47 &= ~ V_43 ;
break;
case V_48 :
V_11 -> V_47 |= V_43 ;
break;
case V_49 :
V_42 [ 1 ] = ( V_11 -> V_47 & V_43 ) ? V_50 : V_51 ;
return V_41 -> V_52 ;
default:
return - V_13 ;
}
return 0 ;
}
unsigned int F_22 ( struct V_10 * V_11 ,
unsigned int * V_42 )
{
unsigned int V_53 = ( V_11 -> V_54 < 32 ) ? ( ( 1 << V_11 -> V_54 ) - 1 )
: 0xffffffff ;
unsigned int V_43 = V_42 [ 0 ] & V_53 ;
unsigned int V_55 = V_42 [ 1 ] ;
if ( V_43 ) {
V_11 -> V_56 &= ~ V_43 ;
V_11 -> V_56 |= ( V_55 & V_43 ) ;
}
return V_43 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_40 * V_41 , unsigned int * V_42 )
{
struct V_40 V_57 ;
int V_58 ;
static const unsigned V_59 = 32 ;
unsigned V_60 = F_21 ( V_41 -> V_45 ) ;
const unsigned V_61 =
( V_60 < V_59 ) ? 0 : V_60 ;
unsigned int V_62 [ 2 ] ;
memset ( V_62 , 0 , sizeof( V_62 ) ) ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_41 = V_63 ;
V_57 . V_45 = V_61 ;
V_57 . V_52 = 2 ;
V_57 . V_64 = V_41 -> V_64 ;
if ( V_41 -> V_41 == V_65 ) {
if ( ! ( V_11 -> V_66 & V_67 ) )
return - V_13 ;
V_62 [ 0 ] = 1 << ( V_60 - V_61 ) ;
V_62 [ 1 ] = V_42 [ 0 ] ? ( 1 << ( V_60 - V_61 ) )
: 0 ;
}
V_58 = V_11 -> V_68 ( V_2 , V_11 , & V_57 , V_62 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_41 -> V_41 == V_69 )
V_42 [ 0 ] = ( V_62 [ 1 ] >> ( V_60 - V_61 ) ) & 1 ;
return 1 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_70 * V_24 ;
unsigned int V_71 ;
int V_58 ;
if ( ( V_11 -> V_66 & ( V_72 | V_73 ) ) == 0 ) {
F_25 ( V_2 -> V_74 ,
L_1 ) ;
return - V_13 ;
}
if ( ! V_11 -> V_75 ) {
F_25 ( V_2 -> V_74 ,
L_2 ) ;
return - V_13 ;
}
V_24 = F_6 ( sizeof( * V_24 ) , V_8 ) ;
if ( ! V_24 )
return - V_14 ;
F_26 ( & V_24 -> V_76 ) ;
V_24 -> V_77 = V_11 ;
V_11 -> V_24 = V_24 ;
V_24 -> V_78 = V_79 * 1024 ;
V_71 = V_80 * 1024 ;
if ( V_71 > V_24 -> V_78 )
V_71 = V_24 -> V_78 ;
if ( F_13 ( V_2 , V_11 , V_71 ) < 0 ) {
F_25 ( V_2 -> V_74 , L_3 ) ;
return - V_14 ;
}
if ( V_11 -> V_81 ) {
V_58 = V_11 -> V_81 ( V_2 , V_11 , V_71 ) ;
if ( V_58 < 0 )
return V_58 ;
}
F_27 ( V_11 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_58 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_16 ; V_12 ++ ) {
V_11 = & V_2 -> V_15 [ V_12 ] ;
if ( V_11 -> type == V_82 )
continue;
if ( V_11 -> type == V_83 ) {
if ( V_11 -> V_54 < 32 )
V_11 -> V_47 = ( 1 << V_11 -> V_54 ) - 1 ;
else
V_11 -> V_47 = 0xffffffff ;
}
if ( V_11 -> V_84 == 0 )
V_11 -> V_84 = 1 ;
if ( V_11 -> V_85 ) {
V_58 = F_24 ( V_2 , V_11 ) ;
if ( V_58 )
return V_58 ;
}
if ( ! V_11 -> V_86 && ! V_11 -> V_87 )
V_11 -> V_86 = & V_88 ;
if ( ! V_11 -> V_89 && V_11 -> V_68 )
V_11 -> V_89 = F_23 ;
if ( ! V_11 -> V_90 && V_11 -> V_68 )
V_11 -> V_90 = F_23 ;
if ( ! V_11 -> V_89 )
V_11 -> V_89 = F_19 ;
if ( ! V_11 -> V_90 )
V_11 -> V_90 = F_19 ;
if ( ! V_11 -> V_68 )
V_11 -> V_68 = F_19 ;
if ( ! V_11 -> V_91 )
V_11 -> V_91 = F_19 ;
if ( ! V_11 -> V_92 )
V_11 -> V_92 = F_18 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_58 ;
V_58 = F_28 ( V_2 ) ;
if ( V_58 < 0 )
return V_58 ;
F_16 ( & V_2 -> V_36 ) ;
V_2 -> V_37 = true ;
F_17 ( & V_2 -> V_36 ) ;
return 0 ;
}
static void * F_30 ( struct V_93 * V_94 , const char * V_95 )
{
char * * V_96 = ( char * * ) V_94 -> V_26 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_94 -> V_97 ; V_12 ++ ) {
if ( strcmp ( * V_96 , V_95 ) == 0 )
return V_96 ;
V_96 = ( void * ) V_96 + V_94 -> V_98 ;
}
return NULL ;
}
static void F_31 ( struct V_93 * V_94 )
{
unsigned int V_12 ;
const char * const * V_96 ;
F_32 ( L_4 ,
V_94 -> V_99 ) ;
V_96 = V_94 -> V_26 ;
for ( V_12 = 0 ; V_12 < V_94 -> V_97 ; V_12 ++ ) {
F_32 ( L_5 , * V_96 ) ;
V_96 = ( const char * * ) ( ( char * ) V_96 + V_94 -> V_98 ) ;
}
if ( V_94 -> V_97 == 0 )
F_32 ( L_5 , V_94 -> V_99 ) ;
}
int F_33 ( struct V_1 * V_2 ,
struct V_3 * V_3 ,
const char * V_95 ,
int (* F_34)( struct V_1 * V_2 ,
const T_2 * V_42 , T_1 V_6 ,
unsigned long V_100 ) ,
unsigned long V_100 )
{
const struct V_101 * V_102 ;
int V_58 ;
if ( ! F_34 )
return - V_13 ;
V_58 = F_35 ( & V_102 , V_95 , V_3 ) ;
if ( V_58 == 0 ) {
V_58 = F_34 ( V_2 , V_102 -> V_42 , V_102 -> V_6 , V_100 ) ;
F_36 ( V_102 ) ;
}
return V_58 < 0 ? V_58 : 0 ;
}
int F_37 ( struct V_1 * V_2 ,
unsigned long V_103 , unsigned long V_104 )
{
if ( ! V_103 ) {
F_25 ( V_2 -> V_74 ,
L_6 ,
V_2 -> V_26 ) ;
return - V_13 ;
}
if ( ! F_38 ( V_103 , V_104 , V_2 -> V_26 ) ) {
F_25 ( V_2 -> V_74 , L_7 ,
V_2 -> V_26 , V_103 , V_104 ) ;
return - V_105 ;
}
return 0 ;
}
int F_39 ( struct V_1 * V_2 ,
unsigned long V_103 , unsigned long V_104 )
{
int V_58 ;
V_58 = F_37 ( V_2 , V_103 , V_104 ) ;
if ( V_58 == 0 ) {
V_2 -> V_28 = V_103 ;
V_2 -> V_29 = V_104 ;
}
return V_58 ;
}
void F_40 ( struct V_1 * V_2 )
{
if ( V_2 -> V_31 ) {
F_41 ( V_2 -> V_31 , V_2 ) ;
V_2 -> V_31 = 0 ;
}
if ( V_2 -> V_28 && V_2 -> V_29 ) {
F_42 ( V_2 -> V_28 , V_2 -> V_29 ) ;
V_2 -> V_28 = 0 ;
V_2 -> V_29 = 0 ;
}
}
int F_43 ( struct V_1 * V_2 , struct V_106 * V_107 )
{
struct V_93 * V_94 ;
int V_58 ;
if ( V_2 -> V_37 )
return - V_108 ;
F_44 ( & V_109 ) ;
for ( V_94 = V_110 ; V_94 ; V_94 = V_94 -> V_111 ) {
if ( ! F_45 ( V_94 -> V_112 ) )
continue;
if ( V_94 -> V_97 ) {
V_2 -> V_27 = F_30 ( V_94 , V_107 -> V_26 ) ;
if ( V_2 -> V_27 )
break;
} else if ( strcmp ( V_94 -> V_99 , V_107 -> V_26 ) == 0 )
break;
F_46 ( V_94 -> V_112 ) ;
}
if ( V_94 == NULL ) {
for ( V_94 = V_110 ; V_94 ; V_94 = V_94 -> V_111 ) {
if ( ! F_45 ( V_94 -> V_112 ) )
continue;
F_31 ( V_94 ) ;
F_46 ( V_94 -> V_112 ) ;
}
V_58 = - V_105 ;
goto V_113;
}
if ( V_94 -> V_114 == NULL ) {
F_25 ( V_2 -> V_74 ,
L_8 ,
V_94 -> V_99 ) ;
F_46 ( V_94 -> V_112 ) ;
V_58 = - V_115 ;
goto V_113;
}
V_2 -> V_25 = V_94 ;
V_2 -> V_26 = V_2 -> V_27 ? * ( const char * * ) V_2 -> V_27
: V_2 -> V_25 -> V_99 ;
V_58 = V_94 -> V_114 ( V_2 , V_107 ) ;
if ( V_58 >= 0 )
V_58 = F_29 ( V_2 ) ;
if ( V_58 < 0 ) {
F_14 ( V_2 ) ;
F_46 ( V_94 -> V_112 ) ;
}
V_113:
F_47 ( & V_109 ) ;
return V_58 ;
}
int F_48 ( struct V_3 * V_116 ,
struct V_93 * V_25 , unsigned long V_100 )
{
struct V_1 * V_2 ;
int V_58 ;
if ( ! V_116 ) {
F_49 ( L_9 ) ;
return - V_13 ;
}
if ( ! V_25 ) {
F_25 ( V_116 ,
L_10 ) ;
return - V_13 ;
}
if ( ! V_25 -> V_117 ) {
F_25 ( V_116 ,
L_11 ,
V_25 -> V_99 ) ;
return - V_13 ;
}
V_2 = F_50 ( V_116 ) ;
if ( F_51 ( V_2 ) ) {
F_25 ( V_116 ,
L_12 ,
V_25 -> V_99 ) ;
return F_52 ( V_2 ) ;
}
V_2 -> V_25 = V_25 ;
V_2 -> V_26 = V_2 -> V_25 -> V_99 ;
V_58 = V_25 -> V_117 ( V_2 , V_100 ) ;
if ( V_58 >= 0 )
V_58 = F_29 ( V_2 ) ;
F_47 ( & V_2 -> V_118 ) ;
if ( V_58 < 0 ) {
F_25 ( V_116 ,
L_13 ,
V_25 -> V_99 ) ;
F_53 ( V_116 ) ;
} else {
F_54 ( V_2 -> V_74 ,
L_14 ,
V_25 -> V_99 , V_2 -> V_26 ) ;
}
return V_58 ;
}
void F_55 ( struct V_3 * V_116 )
{
if ( V_116 == NULL )
return;
F_53 ( V_116 ) ;
}
int F_56 ( struct V_93 * V_25 )
{
F_44 ( & V_109 ) ;
V_25 -> V_111 = V_110 ;
V_110 = V_25 ;
F_47 ( & V_109 ) ;
return 0 ;
}
void F_57 ( struct V_93 * V_25 )
{
struct V_93 * V_119 ;
int V_12 ;
F_44 ( & V_109 ) ;
if ( V_110 == V_25 ) {
V_110 = V_25 -> V_111 ;
} else {
for ( V_119 = V_110 ; V_119 -> V_111 ; V_119 = V_119 -> V_111 ) {
if ( V_119 -> V_111 == V_25 ) {
V_119 -> V_111 = V_25 -> V_111 ;
break;
}
}
}
F_47 ( & V_109 ) ;
for ( V_12 = 0 ; V_12 < V_120 ; V_12 ++ ) {
struct V_1 * V_2 = F_58 ( V_12 ) ;
if ( ! V_2 )
continue;
F_44 ( & V_2 -> V_118 ) ;
if ( V_2 -> V_37 && V_2 -> V_25 == V_25 ) {
if ( V_2 -> V_121 )
F_25 ( V_2 -> V_74 ,
L_15 ,
V_2 -> V_121 ) ;
F_14 ( V_2 ) ;
}
F_47 ( & V_2 -> V_118 ) ;
F_59 ( V_2 ) ;
}
}
