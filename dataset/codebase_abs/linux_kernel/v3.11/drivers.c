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
static void F_8 ( struct V_1 * V_2 )
{
int V_9 ;
struct V_7 * V_8 ;
if ( V_2 -> V_13 ) {
for ( V_9 = 0 ; V_9 < V_2 -> V_14 ; V_9 ++ ) {
V_8 = & V_2 -> V_13 [ V_9 ] ;
if ( V_8 -> V_20 & V_21 )
F_9 ( V_8 -> V_22 ) ;
F_10 ( V_8 ) ;
if ( V_8 -> V_23 ) {
F_11 ( V_2 , V_8 , 0 ) ;
F_9 ( V_8 -> V_23 ) ;
}
}
F_9 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
V_2 -> V_14 = 0 ;
}
F_9 ( V_2 -> V_22 ) ;
V_2 -> V_22 = NULL ;
V_2 -> V_24 = NULL ;
V_2 -> V_25 = NULL ;
V_2 -> V_26 = NULL ;
V_2 -> V_27 = 0 ;
V_2 -> V_28 = 0 ;
V_2 -> V_29 = false ;
V_2 -> V_30 = 0 ;
V_2 -> V_31 = NULL ;
V_2 -> V_32 = NULL ;
V_2 -> V_33 = NULL ;
V_2 -> V_34 = NULL ;
F_3 ( V_2 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
V_2 -> V_35 = false ;
if ( V_2 -> V_24 )
V_2 -> V_24 -> V_36 ( V_2 ) ;
F_8 ( V_2 ) ;
}
static int F_13 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
return - V_10 ;
}
int F_14 ( struct V_1 * V_2 , struct V_7 * V_8 ,
struct V_37 * V_38 , unsigned int * V_39 )
{
return - V_10 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_37 * V_38 , unsigned int * V_39 )
{
struct V_37 V_40 ;
int V_41 ;
static const unsigned V_42 = 32 ;
unsigned V_43 = F_16 ( V_38 -> V_44 ) ;
const unsigned V_45 =
( V_43 < V_42 ) ? 0 : V_43 ;
unsigned int V_46 [ 2 ] ;
memset ( V_46 , 0 , sizeof( V_46 ) ) ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_38 = V_47 ;
V_40 . V_44 = V_45 ;
V_40 . V_48 = 2 ;
V_40 . V_49 = V_38 -> V_49 ;
if ( V_38 -> V_38 == V_50 ) {
if ( ! ( V_8 -> V_51 & V_52 ) )
return - V_10 ;
V_46 [ 0 ] = 1 << ( V_43 - V_45 ) ;
V_46 [ 1 ] = V_39 [ 0 ] ? ( 1 << ( V_43 - V_45 ) )
: 0 ;
}
V_41 = V_8 -> V_53 ( V_2 , V_8 , & V_40 , V_46 ) ;
if ( V_41 < 0 )
return V_41 ;
if ( V_38 -> V_38 == V_54 )
V_39 [ 0 ] = ( V_46 [ 1 ] >> ( V_43 - V_45 ) ) & 1 ;
return 1 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_55 * V_23 ;
unsigned int V_56 ;
int V_41 ;
if ( ( V_8 -> V_51 & ( V_57 | V_58 ) ) == 0 ) {
F_18 ( V_2 -> V_59 ,
L_1 ) ;
return - V_10 ;
}
if ( ! V_8 -> V_60 ) {
F_18 ( V_2 -> V_59 ,
L_2 ) ;
return - V_10 ;
}
V_23 = F_19 ( sizeof( * V_23 ) , V_11 ) ;
if ( ! V_23 )
return - V_12 ;
F_20 ( & V_23 -> V_61 ) ;
V_23 -> V_62 = V_8 ;
V_8 -> V_23 = V_23 ;
V_23 -> V_63 = V_64 * 1024 ;
V_56 = V_65 * 1024 ;
if ( V_56 > V_23 -> V_63 )
V_56 = V_23 -> V_63 ;
if ( F_11 ( V_2 , V_8 , V_56 ) < 0 ) {
F_18 ( V_2 -> V_59 , L_3 ) ;
return - V_12 ;
}
if ( V_8 -> V_66 ) {
V_41 = V_8 -> V_66 ( V_2 , V_8 , V_56 ) ;
if ( V_41 < 0 )
return V_41 ;
}
F_21 ( V_8 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
int V_41 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_14 ; V_9 ++ ) {
V_8 = & V_2 -> V_13 [ V_9 ] ;
if ( V_8 -> type == V_67 )
continue;
if ( V_8 -> V_68 == 0 )
V_8 -> V_68 = 1 ;
if ( V_8 -> V_69 ) {
V_41 = F_17 ( V_2 , V_8 ) ;
if ( V_41 )
return V_41 ;
}
if ( ! V_8 -> V_70 && ! V_8 -> V_71 )
V_8 -> V_70 = & V_72 ;
if ( ! V_8 -> V_73 && V_8 -> V_53 )
V_8 -> V_73 = F_15 ;
if ( ! V_8 -> V_74 && V_8 -> V_53 )
V_8 -> V_74 = F_15 ;
if ( ! V_8 -> V_73 )
V_8 -> V_73 = F_14 ;
if ( ! V_8 -> V_74 )
V_8 -> V_74 = F_14 ;
if ( ! V_8 -> V_53 )
V_8 -> V_53 = F_14 ;
if ( ! V_8 -> V_75 )
V_8 -> V_75 = F_14 ;
if ( ! V_8 -> V_76 )
V_8 -> V_76 = F_13 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_41 ;
V_41 = F_22 ( V_2 ) ;
if ( V_41 < 0 )
return V_41 ;
F_24 () ;
V_2 -> V_35 = true ;
return 0 ;
}
static void * F_25 ( struct V_77 * V_78 , const char * V_79 )
{
char * * V_80 = ( char * * ) V_78 -> V_25 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_78 -> V_81 ; V_9 ++ ) {
if ( strcmp ( * V_80 , V_79 ) == 0 )
return V_80 ;
V_80 = ( void * ) V_80 + V_78 -> V_82 ;
}
return NULL ;
}
static void F_26 ( struct V_77 * V_78 )
{
unsigned int V_9 ;
const char * const * V_80 ;
F_27 ( L_4 ,
V_78 -> V_83 ) ;
V_80 = V_78 -> V_25 ;
for ( V_9 = 0 ; V_9 < V_78 -> V_81 ; V_9 ++ ) {
F_27 ( L_5 , * V_80 ) ;
V_80 = ( const char * * ) ( ( char * ) V_80 + V_78 -> V_82 ) ;
}
if ( V_78 -> V_81 == 0 )
F_27 ( L_5 , V_78 -> V_83 ) ;
}
int F_28 ( struct V_1 * V_2 ,
struct V_3 * V_3 ,
const char * V_79 ,
int (* F_29)( struct V_1 * V_2 ,
const T_1 * V_39 , T_2 V_84 ,
unsigned long V_85 ) ,
unsigned long V_85 )
{
const struct V_86 * V_87 ;
int V_41 ;
if ( ! F_29 )
return - V_10 ;
V_41 = F_30 ( & V_87 , V_79 , V_3 ) ;
if ( V_41 == 0 ) {
V_41 = F_29 ( V_2 , V_87 -> V_39 , V_87 -> V_84 , V_85 ) ;
F_31 ( V_87 ) ;
}
return V_41 ;
}
int F_32 ( struct V_1 * V_2 ,
unsigned long V_88 , unsigned long V_89 )
{
if ( ! V_88 ) {
F_18 ( V_2 -> V_59 ,
L_6 ,
V_2 -> V_25 ) ;
return - V_10 ;
}
if ( ! F_33 ( V_88 , V_89 , V_2 -> V_25 ) ) {
F_18 ( V_2 -> V_59 , L_7 ,
V_2 -> V_25 , V_88 , V_89 ) ;
return - V_90 ;
}
return 0 ;
}
int F_34 ( struct V_1 * V_2 ,
unsigned long V_88 , unsigned long V_89 )
{
int V_41 ;
V_41 = F_32 ( V_2 , V_88 , V_89 ) ;
if ( V_41 == 0 ) {
V_2 -> V_27 = V_88 ;
V_2 -> V_28 = V_89 ;
}
return V_41 ;
}
void F_35 ( struct V_1 * V_2 )
{
if ( V_2 -> V_30 ) {
F_36 ( V_2 -> V_30 , V_2 ) ;
V_2 -> V_30 = 0 ;
}
if ( V_2 -> V_27 && V_2 -> V_28 ) {
F_37 ( V_2 -> V_27 , V_2 -> V_28 ) ;
V_2 -> V_27 = 0 ;
V_2 -> V_28 = 0 ;
}
}
int F_38 ( struct V_1 * V_2 , struct V_91 * V_92 )
{
struct V_77 * V_78 ;
int V_41 ;
if ( V_2 -> V_35 )
return - V_93 ;
for ( V_78 = V_94 ; V_78 ; V_78 = V_78 -> V_95 ) {
if ( ! F_39 ( V_78 -> V_96 ) )
continue;
if ( V_78 -> V_81 ) {
V_2 -> V_26 = F_25 ( V_78 , V_92 -> V_25 ) ;
if ( V_2 -> V_26 )
break;
} else if ( strcmp ( V_78 -> V_83 , V_92 -> V_25 ) == 0 )
break;
F_40 ( V_78 -> V_96 ) ;
}
if ( V_78 == NULL ) {
for ( V_78 = V_94 ; V_78 ; V_78 = V_78 -> V_95 ) {
if ( ! F_39 ( V_78 -> V_96 ) )
continue;
F_26 ( V_78 ) ;
F_40 ( V_78 -> V_96 ) ;
}
return - V_90 ;
}
if ( V_78 -> V_97 == NULL ) {
F_18 ( V_2 -> V_59 ,
L_8 ,
V_78 -> V_83 ) ;
F_40 ( V_78 -> V_96 ) ;
return - V_98 ;
}
V_2 -> V_24 = V_78 ;
V_2 -> V_25 = V_2 -> V_26 ? * ( const char * * ) V_2 -> V_26
: V_2 -> V_24 -> V_83 ;
V_41 = V_78 -> V_97 ( V_2 , V_92 ) ;
if ( V_41 >= 0 )
V_41 = F_23 ( V_2 ) ;
if ( V_41 < 0 ) {
F_12 ( V_2 ) ;
F_40 ( V_78 -> V_96 ) ;
}
return V_41 ;
}
int F_41 ( struct V_3 * V_99 ,
struct V_77 * V_24 , unsigned long V_85 )
{
struct V_1 * V_2 ;
int V_41 ;
if ( ! V_99 ) {
F_42 ( L_9 ) ;
return - V_10 ;
}
if ( ! V_24 ) {
F_18 ( V_99 ,
L_10 ) ;
return - V_10 ;
}
if ( ! V_24 -> V_100 ) {
F_18 ( V_99 ,
L_11 ,
V_24 -> V_83 ) ;
return - V_10 ;
}
V_2 = F_43 ( V_99 ) ;
if ( F_44 ( V_2 ) )
return F_45 ( V_2 ) ;
V_2 -> V_24 = V_24 ;
V_2 -> V_25 = V_2 -> V_24 -> V_83 ;
V_41 = V_24 -> V_100 ( V_2 , V_85 ) ;
if ( V_41 >= 0 )
V_41 = F_23 ( V_2 ) ;
if ( V_41 < 0 )
F_12 ( V_2 ) ;
F_46 ( & V_2 -> V_101 ) ;
if ( V_41 < 0 )
F_47 ( V_99 ) ;
return V_41 ;
}
void F_48 ( struct V_3 * V_99 )
{
if ( V_99 == NULL )
return;
F_47 ( V_99 ) ;
}
int F_49 ( struct V_77 * V_24 )
{
V_24 -> V_95 = V_94 ;
V_94 = V_24 ;
return 0 ;
}
int F_50 ( struct V_77 * V_24 )
{
struct V_77 * V_102 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_103 ; V_9 ++ ) {
struct V_1 * V_2 = F_51 ( V_9 ) ;
if ( ! V_2 )
continue;
F_52 ( & V_2 -> V_101 ) ;
if ( V_2 -> V_35 && V_2 -> V_24 == V_24 ) {
if ( V_2 -> V_104 )
F_18 ( V_2 -> V_59 ,
L_12 ,
V_2 -> V_104 ) ;
F_12 ( V_2 ) ;
}
F_46 ( & V_2 -> V_101 ) ;
}
if ( V_94 == V_24 ) {
V_94 = V_24 -> V_95 ;
return 0 ;
}
for ( V_102 = V_94 ; V_102 -> V_95 ; V_102 = V_102 -> V_95 ) {
if ( V_102 -> V_95 == V_24 ) {
V_102 -> V_95 = V_24 -> V_95 ;
return 0 ;
}
}
return - V_10 ;
}
