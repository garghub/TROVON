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
unsigned int F_19 ( struct V_10 * V_11 ,
unsigned int * V_40 )
{
unsigned int V_51 = ( V_11 -> V_52 < 32 ) ? ( ( 1 << V_11 -> V_52 ) - 1 )
: 0xffffffff ;
unsigned int V_41 = V_40 [ 0 ] & V_51 ;
unsigned int V_53 = V_40 [ 1 ] ;
if ( V_41 ) {
V_11 -> V_54 &= ~ V_41 ;
V_11 -> V_54 |= ( V_53 & V_41 ) ;
}
return V_41 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_38 * V_39 , unsigned int * V_40 )
{
struct V_38 V_55 ;
int V_56 ;
static const unsigned V_57 = 32 ;
unsigned V_58 = F_18 ( V_39 -> V_43 ) ;
const unsigned V_59 =
( V_58 < V_57 ) ? 0 : V_58 ;
unsigned int V_60 [ 2 ] ;
memset ( V_60 , 0 , sizeof( V_60 ) ) ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_39 = V_61 ;
V_55 . V_43 = V_59 ;
V_55 . V_50 = 2 ;
V_55 . V_62 = V_39 -> V_62 ;
if ( V_39 -> V_39 == V_63 ) {
if ( ! ( V_11 -> V_64 & V_65 ) )
return - V_13 ;
V_60 [ 0 ] = 1 << ( V_58 - V_59 ) ;
V_60 [ 1 ] = V_40 [ 0 ] ? ( 1 << ( V_58 - V_59 ) )
: 0 ;
}
V_56 = V_11 -> V_66 ( V_2 , V_11 , & V_55 , V_60 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_39 -> V_39 == V_67 )
V_40 [ 0 ] = ( V_60 [ 1 ] >> ( V_58 - V_59 ) ) & 1 ;
return 1 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_68 * V_24 ;
unsigned int V_69 ;
int V_56 ;
if ( ( V_11 -> V_64 & ( V_70 | V_71 ) ) == 0 ) {
F_22 ( V_2 -> V_72 ,
L_1 ) ;
return - V_13 ;
}
if ( ! V_11 -> V_73 ) {
F_22 ( V_2 -> V_72 ,
L_2 ) ;
return - V_13 ;
}
V_24 = F_6 ( sizeof( * V_24 ) , V_8 ) ;
if ( ! V_24 )
return - V_14 ;
F_23 ( & V_24 -> V_74 ) ;
V_24 -> V_75 = V_11 ;
V_11 -> V_24 = V_24 ;
V_24 -> V_76 = V_77 * 1024 ;
V_69 = V_78 * 1024 ;
if ( V_69 > V_24 -> V_76 )
V_69 = V_24 -> V_76 ;
if ( F_13 ( V_2 , V_11 , V_69 ) < 0 ) {
F_22 ( V_2 -> V_72 , L_3 ) ;
return - V_14 ;
}
if ( V_11 -> V_79 ) {
V_56 = V_11 -> V_79 ( V_2 , V_11 , V_69 ) ;
if ( V_56 < 0 )
return V_56 ;
}
F_24 ( V_11 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_56 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_16 ; V_12 ++ ) {
V_11 = & V_2 -> V_15 [ V_12 ] ;
if ( V_11 -> type == V_80 )
continue;
if ( V_11 -> type == V_81 ) {
if ( V_11 -> V_52 < 32 )
V_11 -> V_45 = ( 1 << V_11 -> V_52 ) - 1 ;
else
V_11 -> V_45 = 0xffffffff ;
}
if ( V_11 -> V_82 == 0 )
V_11 -> V_82 = 1 ;
if ( V_11 -> V_83 ) {
V_56 = F_21 ( V_2 , V_11 ) ;
if ( V_56 )
return V_56 ;
}
if ( ! V_11 -> V_84 && ! V_11 -> V_85 )
V_11 -> V_84 = & V_86 ;
if ( ! V_11 -> V_87 && V_11 -> V_66 )
V_11 -> V_87 = F_20 ;
if ( ! V_11 -> V_88 && V_11 -> V_66 )
V_11 -> V_88 = F_20 ;
if ( ! V_11 -> V_87 )
V_11 -> V_87 = F_16 ;
if ( ! V_11 -> V_88 )
V_11 -> V_88 = F_16 ;
if ( ! V_11 -> V_66 )
V_11 -> V_66 = F_16 ;
if ( ! V_11 -> V_89 )
V_11 -> V_89 = F_16 ;
if ( ! V_11 -> V_90 )
V_11 -> V_90 = F_15 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_56 ;
V_56 = F_25 ( V_2 ) ;
if ( V_56 < 0 )
return V_56 ;
F_27 () ;
V_2 -> V_36 = true ;
return 0 ;
}
static void * F_28 ( struct V_91 * V_92 , const char * V_93 )
{
char * * V_94 = ( char * * ) V_92 -> V_26 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_92 -> V_95 ; V_12 ++ ) {
if ( strcmp ( * V_94 , V_93 ) == 0 )
return V_94 ;
V_94 = ( void * ) V_94 + V_92 -> V_96 ;
}
return NULL ;
}
static void F_29 ( struct V_91 * V_92 )
{
unsigned int V_12 ;
const char * const * V_94 ;
F_30 ( L_4 ,
V_92 -> V_97 ) ;
V_94 = V_92 -> V_26 ;
for ( V_12 = 0 ; V_12 < V_92 -> V_95 ; V_12 ++ ) {
F_30 ( L_5 , * V_94 ) ;
V_94 = ( const char * * ) ( ( char * ) V_94 + V_92 -> V_96 ) ;
}
if ( V_92 -> V_95 == 0 )
F_30 ( L_5 , V_92 -> V_97 ) ;
}
int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_3 ,
const char * V_93 ,
int (* F_32)( struct V_1 * V_2 ,
const T_2 * V_40 , T_1 V_6 ,
unsigned long V_98 ) ,
unsigned long V_98 )
{
const struct V_99 * V_100 ;
int V_56 ;
if ( ! F_32 )
return - V_13 ;
V_56 = F_33 ( & V_100 , V_93 , V_3 ) ;
if ( V_56 == 0 ) {
V_56 = F_32 ( V_2 , V_100 -> V_40 , V_100 -> V_6 , V_98 ) ;
F_34 ( V_100 ) ;
}
return V_56 < 0 ? V_56 : 0 ;
}
int F_35 ( struct V_1 * V_2 ,
unsigned long V_101 , unsigned long V_102 )
{
if ( ! V_101 ) {
F_22 ( V_2 -> V_72 ,
L_6 ,
V_2 -> V_26 ) ;
return - V_13 ;
}
if ( ! F_36 ( V_101 , V_102 , V_2 -> V_26 ) ) {
F_22 ( V_2 -> V_72 , L_7 ,
V_2 -> V_26 , V_101 , V_102 ) ;
return - V_103 ;
}
return 0 ;
}
int F_37 ( struct V_1 * V_2 ,
unsigned long V_101 , unsigned long V_102 )
{
int V_56 ;
V_56 = F_35 ( V_2 , V_101 , V_102 ) ;
if ( V_56 == 0 ) {
V_2 -> V_28 = V_101 ;
V_2 -> V_29 = V_102 ;
}
return V_56 ;
}
void F_38 ( struct V_1 * V_2 )
{
if ( V_2 -> V_31 ) {
F_39 ( V_2 -> V_31 , V_2 ) ;
V_2 -> V_31 = 0 ;
}
if ( V_2 -> V_28 && V_2 -> V_29 ) {
F_40 ( V_2 -> V_28 , V_2 -> V_29 ) ;
V_2 -> V_28 = 0 ;
V_2 -> V_29 = 0 ;
}
}
int F_41 ( struct V_1 * V_2 , struct V_104 * V_105 )
{
struct V_91 * V_92 ;
int V_56 ;
if ( V_2 -> V_36 )
return - V_106 ;
F_42 ( & V_107 ) ;
for ( V_92 = V_108 ; V_92 ; V_92 = V_92 -> V_109 ) {
if ( ! F_43 ( V_92 -> V_110 ) )
continue;
if ( V_92 -> V_95 ) {
V_2 -> V_27 = F_28 ( V_92 , V_105 -> V_26 ) ;
if ( V_2 -> V_27 )
break;
} else if ( strcmp ( V_92 -> V_97 , V_105 -> V_26 ) == 0 )
break;
F_44 ( V_92 -> V_110 ) ;
}
if ( V_92 == NULL ) {
for ( V_92 = V_108 ; V_92 ; V_92 = V_92 -> V_109 ) {
if ( ! F_43 ( V_92 -> V_110 ) )
continue;
F_29 ( V_92 ) ;
F_44 ( V_92 -> V_110 ) ;
}
V_56 = - V_103 ;
goto V_111;
}
if ( V_92 -> V_112 == NULL ) {
F_22 ( V_2 -> V_72 ,
L_8 ,
V_92 -> V_97 ) ;
F_44 ( V_92 -> V_110 ) ;
V_56 = - V_113 ;
goto V_111;
}
V_2 -> V_25 = V_92 ;
V_2 -> V_26 = V_2 -> V_27 ? * ( const char * * ) V_2 -> V_27
: V_2 -> V_25 -> V_97 ;
V_56 = V_92 -> V_112 ( V_2 , V_105 ) ;
if ( V_56 >= 0 )
V_56 = F_26 ( V_2 ) ;
if ( V_56 < 0 ) {
F_14 ( V_2 ) ;
F_44 ( V_92 -> V_110 ) ;
}
V_111:
F_45 ( & V_107 ) ;
return V_56 ;
}
int F_46 ( struct V_3 * V_114 ,
struct V_91 * V_25 , unsigned long V_98 )
{
struct V_1 * V_2 ;
int V_56 ;
if ( ! V_114 ) {
F_47 ( L_9 ) ;
return - V_13 ;
}
if ( ! V_25 ) {
F_22 ( V_114 ,
L_10 ) ;
return - V_13 ;
}
if ( ! V_25 -> V_115 ) {
F_22 ( V_114 ,
L_11 ,
V_25 -> V_97 ) ;
return - V_13 ;
}
V_2 = F_48 ( V_114 ) ;
if ( F_49 ( V_2 ) )
return F_50 ( V_2 ) ;
V_2 -> V_25 = V_25 ;
V_2 -> V_26 = V_2 -> V_25 -> V_97 ;
V_56 = V_25 -> V_115 ( V_2 , V_98 ) ;
if ( V_56 >= 0 )
V_56 = F_26 ( V_2 ) ;
if ( V_56 < 0 )
F_14 ( V_2 ) ;
F_45 ( & V_2 -> V_116 ) ;
if ( V_56 < 0 )
F_51 ( V_114 ) ;
return V_56 ;
}
void F_52 ( struct V_3 * V_114 )
{
if ( V_114 == NULL )
return;
F_51 ( V_114 ) ;
}
int F_53 ( struct V_91 * V_25 )
{
F_42 ( & V_107 ) ;
V_25 -> V_109 = V_108 ;
V_108 = V_25 ;
F_45 ( & V_107 ) ;
return 0 ;
}
void F_54 ( struct V_91 * V_25 )
{
struct V_91 * V_117 ;
int V_12 ;
F_42 ( & V_107 ) ;
if ( V_108 == V_25 ) {
V_108 = V_25 -> V_109 ;
} else {
for ( V_117 = V_108 ; V_117 -> V_109 ; V_117 = V_117 -> V_109 ) {
if ( V_117 -> V_109 == V_25 ) {
V_117 -> V_109 = V_25 -> V_109 ;
break;
}
}
}
F_45 ( & V_107 ) ;
for ( V_12 = 0 ; V_12 < V_118 ; V_12 ++ ) {
struct V_1 * V_2 = F_55 ( V_12 ) ;
if ( ! V_2 )
continue;
F_42 ( & V_2 -> V_116 ) ;
if ( V_2 -> V_36 && V_2 -> V_25 == V_25 ) {
if ( V_2 -> V_119 )
F_22 ( V_2 -> V_72 ,
L_12 ,
V_2 -> V_119 ) ;
F_14 ( V_2 ) ;
}
F_45 ( & V_2 -> V_116 ) ;
}
}
