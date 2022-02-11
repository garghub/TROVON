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
V_2 -> V_36 = false ;
if ( V_2 -> V_25 )
V_2 -> V_25 -> V_37 ( V_2 ) ;
F_10 ( V_2 ) ;
}
static int F_15 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
return - V_13 ;
}
int F_16 ( struct V_1 * V_2 , struct V_10 * V_11 ,
struct V_38 * V_39 , unsigned int * V_40 )
{
return - V_13 ;
}
int F_17 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_38 * V_39 ,
unsigned int * V_40 ,
unsigned int V_41 )
{
unsigned int V_42 = 1 << F_18 ( V_39 -> V_43 ) ;
if ( ! V_41 )
V_41 = V_42 ;
switch ( V_40 [ 0 ] ) {
case V_44 :
V_11 -> V_45 &= ~ V_41 ;
break;
case V_46 :
V_11 -> V_45 |= V_41 ;
break;
case V_47 :
V_40 [ 1 ] = ( V_11 -> V_45 & V_41 ) ? V_48 : V_49 ;
return V_39 -> V_50 ;
default:
return - V_13 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_38 * V_39 , unsigned int * V_40 )
{
struct V_38 V_51 ;
int V_52 ;
static const unsigned V_53 = 32 ;
unsigned V_54 = F_18 ( V_39 -> V_43 ) ;
const unsigned V_55 =
( V_54 < V_53 ) ? 0 : V_54 ;
unsigned int V_56 [ 2 ] ;
memset ( V_56 , 0 , sizeof( V_56 ) ) ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
V_51 . V_39 = V_57 ;
V_51 . V_43 = V_55 ;
V_51 . V_50 = 2 ;
V_51 . V_58 = V_39 -> V_58 ;
if ( V_39 -> V_39 == V_59 ) {
if ( ! ( V_11 -> V_60 & V_61 ) )
return - V_13 ;
V_56 [ 0 ] = 1 << ( V_54 - V_55 ) ;
V_56 [ 1 ] = V_40 [ 0 ] ? ( 1 << ( V_54 - V_55 ) )
: 0 ;
}
V_52 = V_11 -> V_62 ( V_2 , V_11 , & V_51 , V_56 ) ;
if ( V_52 < 0 )
return V_52 ;
if ( V_39 -> V_39 == V_63 )
V_40 [ 0 ] = ( V_56 [ 1 ] >> ( V_54 - V_55 ) ) & 1 ;
return 1 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_64 * V_24 ;
unsigned int V_65 ;
int V_52 ;
if ( ( V_11 -> V_60 & ( V_66 | V_67 ) ) == 0 ) {
F_21 ( V_2 -> V_68 ,
L_1 ) ;
return - V_13 ;
}
if ( ! V_11 -> V_69 ) {
F_21 ( V_2 -> V_68 ,
L_2 ) ;
return - V_13 ;
}
V_24 = F_6 ( sizeof( * V_24 ) , V_8 ) ;
if ( ! V_24 )
return - V_14 ;
F_22 ( & V_24 -> V_70 ) ;
V_24 -> V_71 = V_11 ;
V_11 -> V_24 = V_24 ;
V_24 -> V_72 = V_73 * 1024 ;
V_65 = V_74 * 1024 ;
if ( V_65 > V_24 -> V_72 )
V_65 = V_24 -> V_72 ;
if ( F_13 ( V_2 , V_11 , V_65 ) < 0 ) {
F_21 ( V_2 -> V_68 , L_3 ) ;
return - V_14 ;
}
if ( V_11 -> V_75 ) {
V_52 = V_11 -> V_75 ( V_2 , V_11 , V_65 ) ;
if ( V_52 < 0 )
return V_52 ;
}
F_23 ( V_11 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_52 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_16 ; V_12 ++ ) {
V_11 = & V_2 -> V_15 [ V_12 ] ;
if ( V_11 -> type == V_76 )
continue;
if ( V_11 -> V_77 == 0 )
V_11 -> V_77 = 1 ;
if ( V_11 -> V_78 ) {
V_52 = F_20 ( V_2 , V_11 ) ;
if ( V_52 )
return V_52 ;
}
if ( ! V_11 -> V_79 && ! V_11 -> V_80 )
V_11 -> V_79 = & V_81 ;
if ( ! V_11 -> V_82 && V_11 -> V_62 )
V_11 -> V_82 = F_19 ;
if ( ! V_11 -> V_83 && V_11 -> V_62 )
V_11 -> V_83 = F_19 ;
if ( ! V_11 -> V_82 )
V_11 -> V_82 = F_16 ;
if ( ! V_11 -> V_83 )
V_11 -> V_83 = F_16 ;
if ( ! V_11 -> V_62 )
V_11 -> V_62 = F_16 ;
if ( ! V_11 -> V_84 )
V_11 -> V_84 = F_16 ;
if ( ! V_11 -> V_85 )
V_11 -> V_85 = F_15 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_52 ;
V_52 = F_24 ( V_2 ) ;
if ( V_52 < 0 )
return V_52 ;
F_26 () ;
V_2 -> V_36 = true ;
return 0 ;
}
static void * F_27 ( struct V_86 * V_87 , const char * V_88 )
{
char * * V_89 = ( char * * ) V_87 -> V_26 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_87 -> V_90 ; V_12 ++ ) {
if ( strcmp ( * V_89 , V_88 ) == 0 )
return V_89 ;
V_89 = ( void * ) V_89 + V_87 -> V_91 ;
}
return NULL ;
}
static void F_28 ( struct V_86 * V_87 )
{
unsigned int V_12 ;
const char * const * V_89 ;
F_29 ( L_4 ,
V_87 -> V_92 ) ;
V_89 = V_87 -> V_26 ;
for ( V_12 = 0 ; V_12 < V_87 -> V_90 ; V_12 ++ ) {
F_29 ( L_5 , * V_89 ) ;
V_89 = ( const char * * ) ( ( char * ) V_89 + V_87 -> V_91 ) ;
}
if ( V_87 -> V_90 == 0 )
F_29 ( L_5 , V_87 -> V_92 ) ;
}
int F_30 ( struct V_1 * V_2 ,
struct V_3 * V_3 ,
const char * V_88 ,
int (* F_31)( struct V_1 * V_2 ,
const T_2 * V_40 , T_1 V_6 ,
unsigned long V_93 ) ,
unsigned long V_93 )
{
const struct V_94 * V_95 ;
int V_52 ;
if ( ! F_31 )
return - V_13 ;
V_52 = F_32 ( & V_95 , V_88 , V_3 ) ;
if ( V_52 == 0 ) {
V_52 = F_31 ( V_2 , V_95 -> V_40 , V_95 -> V_6 , V_93 ) ;
F_33 ( V_95 ) ;
}
return V_52 ;
}
int F_34 ( struct V_1 * V_2 ,
unsigned long V_96 , unsigned long V_97 )
{
if ( ! V_96 ) {
F_21 ( V_2 -> V_68 ,
L_6 ,
V_2 -> V_26 ) ;
return - V_13 ;
}
if ( ! F_35 ( V_96 , V_97 , V_2 -> V_26 ) ) {
F_21 ( V_2 -> V_68 , L_7 ,
V_2 -> V_26 , V_96 , V_97 ) ;
return - V_98 ;
}
return 0 ;
}
int F_36 ( struct V_1 * V_2 ,
unsigned long V_96 , unsigned long V_97 )
{
int V_52 ;
V_52 = F_34 ( V_2 , V_96 , V_97 ) ;
if ( V_52 == 0 ) {
V_2 -> V_28 = V_96 ;
V_2 -> V_29 = V_97 ;
}
return V_52 ;
}
void F_37 ( struct V_1 * V_2 )
{
if ( V_2 -> V_31 ) {
F_38 ( V_2 -> V_31 , V_2 ) ;
V_2 -> V_31 = 0 ;
}
if ( V_2 -> V_28 && V_2 -> V_29 ) {
F_39 ( V_2 -> V_28 , V_2 -> V_29 ) ;
V_2 -> V_28 = 0 ;
V_2 -> V_29 = 0 ;
}
}
int F_40 ( struct V_1 * V_2 , struct V_99 * V_100 )
{
struct V_86 * V_87 ;
int V_52 ;
if ( V_2 -> V_36 )
return - V_101 ;
F_41 ( & V_102 ) ;
for ( V_87 = V_103 ; V_87 ; V_87 = V_87 -> V_104 ) {
if ( ! F_42 ( V_87 -> V_105 ) )
continue;
if ( V_87 -> V_90 ) {
V_2 -> V_27 = F_27 ( V_87 , V_100 -> V_26 ) ;
if ( V_2 -> V_27 )
break;
} else if ( strcmp ( V_87 -> V_92 , V_100 -> V_26 ) == 0 )
break;
F_43 ( V_87 -> V_105 ) ;
}
if ( V_87 == NULL ) {
for ( V_87 = V_103 ; V_87 ; V_87 = V_87 -> V_104 ) {
if ( ! F_42 ( V_87 -> V_105 ) )
continue;
F_28 ( V_87 ) ;
F_43 ( V_87 -> V_105 ) ;
}
V_52 = - V_98 ;
goto V_106;
}
if ( V_87 -> V_107 == NULL ) {
F_21 ( V_2 -> V_68 ,
L_8 ,
V_87 -> V_92 ) ;
F_43 ( V_87 -> V_105 ) ;
V_52 = - V_108 ;
goto V_106;
}
V_2 -> V_25 = V_87 ;
V_2 -> V_26 = V_2 -> V_27 ? * ( const char * * ) V_2 -> V_27
: V_2 -> V_25 -> V_92 ;
V_52 = V_87 -> V_107 ( V_2 , V_100 ) ;
if ( V_52 >= 0 )
V_52 = F_25 ( V_2 ) ;
if ( V_52 < 0 ) {
F_14 ( V_2 ) ;
F_43 ( V_87 -> V_105 ) ;
}
V_106:
F_44 ( & V_102 ) ;
return V_52 ;
}
int F_45 ( struct V_3 * V_109 ,
struct V_86 * V_25 , unsigned long V_93 )
{
struct V_1 * V_2 ;
int V_52 ;
if ( ! V_109 ) {
F_46 ( L_9 ) ;
return - V_13 ;
}
if ( ! V_25 ) {
F_21 ( V_109 ,
L_10 ) ;
return - V_13 ;
}
if ( ! V_25 -> V_110 ) {
F_21 ( V_109 ,
L_11 ,
V_25 -> V_92 ) ;
return - V_13 ;
}
V_2 = F_47 ( V_109 ) ;
if ( F_48 ( V_2 ) )
return F_49 ( V_2 ) ;
V_2 -> V_25 = V_25 ;
V_2 -> V_26 = V_2 -> V_25 -> V_92 ;
V_52 = V_25 -> V_110 ( V_2 , V_93 ) ;
if ( V_52 >= 0 )
V_52 = F_25 ( V_2 ) ;
if ( V_52 < 0 )
F_14 ( V_2 ) ;
F_44 ( & V_2 -> V_111 ) ;
if ( V_52 < 0 )
F_50 ( V_109 ) ;
return V_52 ;
}
void F_51 ( struct V_3 * V_109 )
{
if ( V_109 == NULL )
return;
F_50 ( V_109 ) ;
}
int F_52 ( struct V_86 * V_25 )
{
F_41 ( & V_102 ) ;
V_25 -> V_104 = V_103 ;
V_103 = V_25 ;
F_44 ( & V_102 ) ;
return 0 ;
}
void F_53 ( struct V_86 * V_25 )
{
struct V_86 * V_112 ;
int V_12 ;
F_41 ( & V_102 ) ;
if ( V_103 == V_25 ) {
V_103 = V_25 -> V_104 ;
} else {
for ( V_112 = V_103 ; V_112 -> V_104 ; V_112 = V_112 -> V_104 ) {
if ( V_112 -> V_104 == V_25 ) {
V_112 -> V_104 = V_25 -> V_104 ;
break;
}
}
}
F_44 ( & V_102 ) ;
for ( V_12 = 0 ; V_12 < V_113 ; V_12 ++ ) {
struct V_1 * V_2 = F_54 ( V_12 ) ;
if ( ! V_2 )
continue;
F_41 ( & V_2 -> V_111 ) ;
if ( V_2 -> V_36 && V_2 -> V_25 == V_25 ) {
if ( V_2 -> V_114 )
F_21 ( V_2 -> V_68 ,
L_12 ,
V_2 -> V_114 ) ;
F_14 ( V_2 ) ;
}
F_44 ( & V_2 -> V_111 ) ;
}
}
