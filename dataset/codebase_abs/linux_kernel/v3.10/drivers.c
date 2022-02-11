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
int F_5 ( struct V_1 * V_2 , int V_6 )
{
struct V_7 * V_8 ;
int V_9 ;
if ( V_6 < 1 )
return - V_10 ;
V_8 = F_6 ( V_6 , sizeof( * V_8 ) , V_11 ) ;
if ( ! V_8 )
return - V_12 ;
V_2 -> V_13 = V_8 ;
V_2 -> V_14 = V_6 ;
for ( V_9 = 0 ; V_9 < V_6 ; ++ V_9 ) {
V_8 = & V_2 -> V_13 [ V_9 ] ;
V_8 -> V_3 = V_2 ;
V_8 -> V_15 = V_9 ;
V_8 -> V_16 = V_17 ;
F_7 ( & V_8 -> V_18 ) ;
V_8 -> V_19 = - 1 ;
}
return 0 ;
}
void F_8 ( struct V_1 * V_2 , int V_20 )
{
struct V_7 * V_8 ;
if ( V_2 -> V_13 && V_20 < V_2 -> V_14 ) {
V_8 = & V_2 -> V_13 [ V_20 ] ;
F_9 ( V_8 -> V_21 ) ;
V_8 -> V_21 = NULL ;
}
}
static void F_10 ( struct V_1 * V_2 )
{
int V_9 ;
struct V_7 * V_8 ;
if ( V_2 -> V_13 ) {
for ( V_9 = 0 ; V_9 < V_2 -> V_14 ; V_9 ++ ) {
V_8 = & V_2 -> V_13 [ V_9 ] ;
F_11 ( V_8 ) ;
if ( V_8 -> V_22 ) {
F_12 ( V_2 , V_8 , 0 ) ;
F_9 ( V_8 -> V_22 ) ;
}
}
F_9 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
V_2 -> V_14 = 0 ;
}
F_9 ( V_2 -> V_21 ) ;
V_2 -> V_21 = NULL ;
V_2 -> V_23 = NULL ;
V_2 -> V_24 = NULL ;
V_2 -> V_25 = NULL ;
V_2 -> V_26 = 0 ;
V_2 -> V_27 = 0 ;
V_2 -> V_28 = false ;
V_2 -> V_29 = 0 ;
V_2 -> V_30 = NULL ;
V_2 -> V_31 = NULL ;
V_2 -> V_32 = NULL ;
V_2 -> V_33 = NULL ;
F_3 ( V_2 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
V_2 -> V_34 = false ;
if ( V_2 -> V_23 )
V_2 -> V_23 -> V_35 ( V_2 ) ;
F_10 ( V_2 ) ;
}
static int F_14 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
return - V_10 ;
}
int F_15 ( struct V_1 * V_2 , struct V_7 * V_8 ,
struct V_36 * V_37 , unsigned int * V_38 )
{
return - V_10 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_36 * V_37 , unsigned int * V_38 )
{
struct V_36 V_39 ;
int V_40 ;
static const unsigned V_41 = 32 ;
unsigned V_42 = F_17 ( V_37 -> V_43 ) ;
const unsigned V_44 =
( V_42 < V_41 ) ? 0 : V_42 ;
unsigned int V_45 [ 2 ] ;
memset ( V_45 , 0 , sizeof( V_45 ) ) ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
V_39 . V_37 = V_46 ;
V_39 . V_43 = V_44 ;
V_39 . V_47 = 2 ;
V_39 . V_48 = V_37 -> V_48 ;
if ( V_37 -> V_37 == V_49 ) {
if ( ! ( V_8 -> V_50 & V_51 ) )
return - V_10 ;
V_45 [ 0 ] = 1 << ( V_42 - V_44 ) ;
V_45 [ 1 ] = V_38 [ 0 ] ? ( 1 << ( V_42 - V_44 ) )
: 0 ;
}
V_40 = V_8 -> V_52 ( V_2 , V_8 , & V_39 , V_45 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_37 -> V_37 == V_53 )
V_38 [ 0 ] = ( V_45 [ 1 ] >> ( V_42 - V_44 ) ) & 1 ;
return 1 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_54 * V_22 ;
unsigned int V_55 ;
int V_40 ;
if ( ( V_8 -> V_50 & ( V_56 | V_57 ) ) == 0 ) {
F_19 ( V_2 -> V_58 ,
L_1 ) ;
return - V_10 ;
}
if ( ! V_8 -> V_59 ) {
F_19 ( V_2 -> V_58 ,
L_2 ) ;
return - V_10 ;
}
V_22 = F_20 ( sizeof( * V_22 ) , V_11 ) ;
if ( ! V_22 )
return - V_12 ;
F_21 ( & V_22 -> V_60 ) ;
V_22 -> V_61 = V_8 ;
V_8 -> V_22 = V_22 ;
V_22 -> V_62 = V_63 * 1024 ;
V_55 = V_64 * 1024 ;
if ( V_55 > V_22 -> V_62 )
V_55 = V_22 -> V_62 ;
if ( F_12 ( V_2 , V_8 , V_55 ) < 0 ) {
F_19 ( V_2 -> V_58 , L_3 ) ;
return - V_12 ;
}
if ( V_8 -> V_65 ) {
V_40 = V_8 -> V_65 ( V_2 , V_8 , V_55 ) ;
if ( V_40 < 0 )
return V_40 ;
}
F_22 ( V_8 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
int V_40 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_14 ; V_9 ++ ) {
V_8 = & V_2 -> V_13 [ V_9 ] ;
if ( V_8 -> type == V_66 )
continue;
if ( V_8 -> V_67 == 0 )
V_8 -> V_67 = 1 ;
if ( V_8 -> V_68 ) {
V_40 = F_18 ( V_2 , V_8 ) ;
if ( V_40 )
return V_40 ;
}
if ( ! V_8 -> V_69 && ! V_8 -> V_70 )
V_8 -> V_69 = & V_71 ;
if ( ! V_8 -> V_72 && V_8 -> V_52 )
V_8 -> V_72 = F_16 ;
if ( ! V_8 -> V_73 && V_8 -> V_52 )
V_8 -> V_73 = F_16 ;
if ( ! V_8 -> V_72 )
V_8 -> V_72 = F_15 ;
if ( ! V_8 -> V_73 )
V_8 -> V_73 = F_15 ;
if ( ! V_8 -> V_52 )
V_8 -> V_52 = F_15 ;
if ( ! V_8 -> V_74 )
V_8 -> V_74 = F_15 ;
if ( ! V_8 -> V_75 )
V_8 -> V_75 = F_14 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_40 ;
V_40 = F_23 ( V_2 ) ;
if ( V_40 < 0 )
return V_40 ;
F_25 () ;
V_2 -> V_34 = true ;
return 0 ;
}
static void * F_26 ( struct V_76 * V_77 , const char * V_78 )
{
char * * V_79 = ( char * * ) V_77 -> V_24 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_77 -> V_80 ; V_9 ++ ) {
if ( strcmp ( * V_79 , V_78 ) == 0 )
return V_79 ;
V_79 = ( void * ) V_79 + V_77 -> V_81 ;
}
return NULL ;
}
static void F_27 ( struct V_76 * V_77 )
{
unsigned int V_9 ;
const char * const * V_79 ;
F_28 ( L_4 ,
V_77 -> V_82 ) ;
V_79 = V_77 -> V_24 ;
for ( V_9 = 0 ; V_9 < V_77 -> V_80 ; V_9 ++ ) {
F_28 ( L_5 , * V_79 ) ;
V_79 = ( const char * * ) ( ( char * ) V_79 + V_77 -> V_81 ) ;
}
if ( V_77 -> V_80 == 0 )
F_28 ( L_5 , V_77 -> V_82 ) ;
}
int F_29 ( struct V_1 * V_2 ,
unsigned long V_83 , unsigned long V_84 )
{
if ( ! V_83 ) {
F_19 ( V_2 -> V_58 ,
L_6 ,
V_2 -> V_24 ) ;
return - V_10 ;
}
if ( ! F_30 ( V_83 , V_84 , V_2 -> V_24 ) ) {
F_19 ( V_2 -> V_58 , L_7 ,
V_2 -> V_24 , V_83 , V_84 ) ;
return - V_85 ;
}
return 0 ;
}
int F_31 ( struct V_1 * V_2 ,
unsigned long V_83 , unsigned long V_84 )
{
int V_40 ;
V_40 = F_29 ( V_2 , V_83 , V_84 ) ;
if ( V_40 == 0 ) {
V_2 -> V_26 = V_83 ;
V_2 -> V_27 = V_84 ;
}
return V_40 ;
}
void F_32 ( struct V_1 * V_2 )
{
if ( V_2 -> V_29 ) {
F_33 ( V_2 -> V_29 , V_2 ) ;
V_2 -> V_29 = 0 ;
}
if ( V_2 -> V_26 && V_2 -> V_27 ) {
F_34 ( V_2 -> V_26 , V_2 -> V_27 ) ;
V_2 -> V_26 = 0 ;
V_2 -> V_27 = 0 ;
}
}
int F_35 ( struct V_1 * V_2 , struct V_86 * V_87 )
{
struct V_76 * V_77 ;
int V_40 ;
if ( V_2 -> V_34 )
return - V_88 ;
for ( V_77 = V_89 ; V_77 ; V_77 = V_77 -> V_90 ) {
if ( ! F_36 ( V_77 -> V_91 ) )
continue;
if ( V_77 -> V_80 ) {
V_2 -> V_25 = F_26 ( V_77 , V_87 -> V_24 ) ;
if ( V_2 -> V_25 )
break;
} else if ( strcmp ( V_77 -> V_82 , V_87 -> V_24 ) == 0 )
break;
F_37 ( V_77 -> V_91 ) ;
}
if ( V_77 == NULL ) {
for ( V_77 = V_89 ; V_77 ; V_77 = V_77 -> V_90 ) {
if ( ! F_36 ( V_77 -> V_91 ) )
continue;
F_27 ( V_77 ) ;
F_37 ( V_77 -> V_91 ) ;
}
return - V_85 ;
}
if ( V_77 -> V_92 == NULL ) {
F_19 ( V_2 -> V_58 ,
L_8 ,
V_77 -> V_82 ) ;
F_37 ( V_77 -> V_91 ) ;
return - V_93 ;
}
V_2 -> V_23 = V_77 ;
V_2 -> V_24 = V_2 -> V_25 ? * ( const char * * ) V_2 -> V_25
: V_2 -> V_23 -> V_82 ;
V_40 = V_77 -> V_92 ( V_2 , V_87 ) ;
if ( V_40 >= 0 )
V_40 = F_24 ( V_2 ) ;
if ( V_40 < 0 ) {
F_13 ( V_2 ) ;
F_37 ( V_2 -> V_23 -> V_91 ) ;
}
return V_40 ;
}
int F_38 ( struct V_3 * V_94 ,
struct V_76 * V_23 , unsigned long V_95 )
{
struct V_1 * V_2 ;
int V_40 ;
if ( ! V_94 ) {
F_39 ( L_9 ) ;
return - V_10 ;
}
if ( ! V_23 ) {
F_19 ( V_94 ,
L_10 ) ;
return - V_10 ;
}
if ( ! V_23 -> V_96 ) {
F_19 ( V_94 ,
L_11 ,
V_23 -> V_82 ) ;
return - V_10 ;
}
V_2 = F_40 ( V_94 ) ;
if ( F_41 ( V_2 ) )
return F_42 ( V_2 ) ;
V_2 -> V_23 = V_23 ;
V_2 -> V_24 = V_2 -> V_23 -> V_82 ;
V_40 = V_23 -> V_96 ( V_2 , V_95 ) ;
if ( V_40 >= 0 )
V_40 = F_24 ( V_2 ) ;
if ( V_40 < 0 )
F_13 ( V_2 ) ;
F_43 ( & V_2 -> V_97 ) ;
if ( V_40 < 0 )
F_44 ( V_94 ) ;
return V_40 ;
}
void F_45 ( struct V_3 * V_94 )
{
if ( V_94 == NULL )
return;
F_44 ( V_94 ) ;
}
int F_46 ( struct V_76 * V_23 )
{
V_23 -> V_90 = V_89 ;
V_89 = V_23 ;
return 0 ;
}
int F_47 ( struct V_76 * V_23 )
{
struct V_76 * V_98 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_99 ; V_9 ++ ) {
struct V_1 * V_2 = F_48 ( V_9 ) ;
if ( ! V_2 )
continue;
F_49 ( & V_2 -> V_97 ) ;
if ( V_2 -> V_34 && V_2 -> V_23 == V_23 ) {
if ( V_2 -> V_100 )
F_19 ( V_2 -> V_58 ,
L_12 ,
V_2 -> V_100 ) ;
F_13 ( V_2 ) ;
}
F_43 ( & V_2 -> V_97 ) ;
}
if ( V_89 == V_23 ) {
V_89 = V_23 -> V_90 ;
return 0 ;
}
for ( V_98 = V_89 ; V_98 -> V_90 ; V_98 = V_98 -> V_90 ) {
if ( V_98 -> V_90 == V_23 ) {
V_98 -> V_90 = V_23 -> V_90 ;
return 0 ;
}
}
return - V_10 ;
}
