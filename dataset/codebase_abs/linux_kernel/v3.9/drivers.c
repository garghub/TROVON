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
F_9 ( V_8 ) ;
if ( V_8 -> V_20 ) {
F_10 ( V_2 , V_8 , 0 ) ;
F_11 ( V_8 -> V_20 ) ;
}
}
F_11 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
V_2 -> V_14 = 0 ;
}
F_11 ( V_2 -> V_21 ) ;
V_2 -> V_21 = NULL ;
V_2 -> V_22 = NULL ;
V_2 -> V_23 = NULL ;
V_2 -> V_24 = NULL ;
V_2 -> V_25 = 0 ;
V_2 -> V_26 = 0 ;
V_2 -> V_27 = NULL ;
V_2 -> V_28 = NULL ;
V_2 -> V_29 = NULL ;
V_2 -> V_30 = NULL ;
F_3 ( V_2 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
V_2 -> V_31 = 0 ;
if ( V_2 -> V_22 )
V_2 -> V_22 -> V_32 ( V_2 ) ;
else
F_13 ( V_2 -> V_33 ,
L_1 ) ;
F_8 ( V_2 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_31 )
return;
F_12 ( V_2 ) ;
}
static int F_15 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
return - V_10 ;
}
int F_16 ( struct V_1 * V_2 , struct V_7 * V_8 ,
struct V_34 * V_35 , unsigned int * V_36 )
{
return - V_10 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_34 * V_35 , unsigned int * V_36 )
{
struct V_34 V_37 ;
int V_38 ;
static const unsigned V_39 = 32 ;
unsigned V_40 = F_18 ( V_35 -> V_41 ) ;
const unsigned V_42 =
( V_40 < V_39 ) ? 0 : V_40 ;
unsigned int V_43 [ 2 ] ;
memset ( V_43 , 0 , sizeof( V_43 ) ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_35 = V_44 ;
V_37 . V_41 = V_42 ;
V_37 . V_45 = 2 ;
V_37 . V_46 = V_35 -> V_46 ;
if ( V_35 -> V_35 == V_47 ) {
if ( ! ( V_8 -> V_48 & V_49 ) )
return - V_10 ;
V_43 [ 0 ] = 1 << ( V_40 - V_42 ) ;
V_43 [ 1 ] = V_36 [ 0 ] ? ( 1 << ( V_40 - V_42 ) )
: 0 ;
}
V_38 = V_8 -> V_50 ( V_2 , V_8 , & V_37 , V_43 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_35 -> V_35 == V_51 )
V_36 [ 0 ] = ( V_43 [ 1 ] >> ( V_40 - V_42 ) ) & 1 ;
return 1 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_52 * V_20 ;
unsigned int V_53 ;
int V_38 ;
if ( ( V_8 -> V_48 & ( V_54 | V_55 ) ) == 0 ) {
F_13 ( V_2 -> V_33 ,
L_2 ) ;
return - V_10 ;
}
if ( ! V_8 -> V_56 ) {
F_13 ( V_2 -> V_33 ,
L_3 ) ;
return - V_10 ;
}
V_20 = F_20 ( sizeof( * V_20 ) , V_11 ) ;
if ( ! V_20 )
return - V_12 ;
F_21 ( & V_20 -> V_57 ) ;
V_20 -> V_58 = V_8 ;
V_8 -> V_20 = V_20 ;
V_20 -> V_59 = V_60 * 1024 ;
V_53 = V_61 * 1024 ;
if ( V_53 > V_20 -> V_59 )
V_53 = V_20 -> V_59 ;
if ( F_10 ( V_2 , V_8 , V_53 ) < 0 ) {
F_13 ( V_2 -> V_33 , L_4 ) ;
return - V_12 ;
}
if ( V_8 -> V_62 ) {
V_38 = V_8 -> V_62 ( V_2 , V_8 , V_53 ) ;
if ( V_38 < 0 )
return V_38 ;
}
F_22 ( V_8 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
int V_38 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_14 ; V_9 ++ ) {
V_8 = & V_2 -> V_13 [ V_9 ] ;
if ( V_8 -> type == V_63 )
continue;
if ( V_8 -> V_64 == 0 )
V_8 -> V_64 = 1 ;
if ( V_8 -> V_65 ) {
V_38 = F_19 ( V_2 , V_8 ) ;
if ( V_38 )
return V_38 ;
}
if ( ! V_8 -> V_66 && ! V_8 -> V_67 )
V_8 -> V_66 = & V_68 ;
if ( ! V_8 -> V_69 && V_8 -> V_50 )
V_8 -> V_69 = F_17 ;
if ( ! V_8 -> V_70 && V_8 -> V_50 )
V_8 -> V_70 = F_17 ;
if ( ! V_8 -> V_69 )
V_8 -> V_69 = F_16 ;
if ( ! V_8 -> V_70 )
V_8 -> V_70 = F_16 ;
if ( ! V_8 -> V_50 )
V_8 -> V_50 = F_16 ;
if ( ! V_8 -> V_71 )
V_8 -> V_71 = F_16 ;
if ( ! V_8 -> V_72 )
V_8 -> V_72 = F_15 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_38 = F_23 ( V_2 ) ;
F_25 ( V_2 -> V_22 -> V_73 ) ;
if ( V_38 < 0 ) {
F_12 ( V_2 ) ;
return V_38 ;
}
if ( ! V_2 -> V_23 ) {
F_13 ( V_2 -> V_33 , L_5 ) ;
V_2 -> V_23 = L_6 ;
}
F_26 () ;
V_2 -> V_31 = 1 ;
return 0 ;
}
static void * F_27 ( struct V_74 * V_75 , const char * V_76 )
{
char * * V_77 = ( char * * ) V_75 -> V_23 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_75 -> V_78 ; V_9 ++ ) {
if ( strcmp ( * V_77 , V_76 ) == 0 )
return V_77 ;
V_77 = ( void * ) V_77 + V_75 -> V_79 ;
}
return NULL ;
}
static void F_28 ( struct V_74 * V_75 )
{
unsigned int V_9 ;
const char * const * V_77 ;
F_29 ( L_7 ,
V_75 -> V_80 ) ;
V_77 = V_75 -> V_23 ;
for ( V_9 = 0 ; V_9 < V_75 -> V_78 ; V_9 ++ ) {
F_29 ( L_8 , * V_77 ) ;
V_77 = ( const char * * ) ( ( char * ) V_77 + V_75 -> V_79 ) ;
}
if ( V_75 -> V_78 == 0 )
F_29 ( L_8 , V_75 -> V_80 ) ;
}
int F_30 ( struct V_1 * V_2 , struct V_81 * V_82 )
{
struct V_74 * V_75 ;
int V_38 ;
if ( V_2 -> V_31 )
return - V_83 ;
for ( V_75 = V_84 ; V_75 ; V_75 = V_75 -> V_85 ) {
if ( ! F_31 ( V_75 -> V_73 ) )
continue;
if ( V_75 -> V_78 ) {
V_2 -> V_24 = F_27 ( V_75 , V_82 -> V_23 ) ;
if ( V_2 -> V_24 )
break;
} else if ( strcmp ( V_75 -> V_80 , V_82 -> V_23 ) == 0 )
break;
F_25 ( V_75 -> V_73 ) ;
}
if ( V_75 == NULL ) {
for ( V_75 = V_84 ; V_75 ; V_75 = V_75 -> V_85 ) {
if ( ! F_31 ( V_75 -> V_73 ) )
continue;
F_28 ( V_75 ) ;
F_25 ( V_75 -> V_73 ) ;
}
return - V_86 ;
}
if ( V_75 -> V_87 == NULL ) {
F_13 ( V_2 -> V_33 ,
L_9 ,
V_75 -> V_80 ) ;
F_25 ( V_75 -> V_73 ) ;
return - V_88 ;
}
V_2 -> V_22 = V_75 ;
V_38 = V_75 -> V_87 ( V_2 , V_82 ) ;
if ( V_38 < 0 ) {
F_25 ( V_2 -> V_22 -> V_73 ) ;
F_12 ( V_2 ) ;
return V_38 ;
}
return F_24 ( V_2 ) ;
}
int F_32 ( struct V_3 * V_89 ,
struct V_74 * V_22 , unsigned long V_90 )
{
int V_19 ;
struct V_1 * V_91 ;
int V_38 ;
if ( ! V_22 -> V_92 ) {
F_13 ( V_89 ,
L_10 ,
V_22 -> V_80 ) ;
return - V_10 ;
}
V_19 = F_33 ( V_89 ) ;
if ( V_19 < 0 )
return V_19 ;
V_91 = F_34 ( V_19 ) ;
F_35 ( & V_91 -> V_93 ) ;
if ( V_91 -> V_31 )
V_38 = - V_83 ;
else if ( ! F_31 ( V_22 -> V_73 ) )
V_38 = - V_86 ;
else {
F_1 ( V_91 , V_89 ) ;
V_91 -> V_22 = V_22 ;
V_38 = V_22 -> V_92 ( V_91 , V_90 ) ;
if ( V_38 < 0 ) {
F_25 ( V_22 -> V_73 ) ;
F_12 ( V_91 ) ;
} else {
V_38 = F_24 ( V_91 ) ;
}
}
F_36 ( & V_91 -> V_93 ) ;
if ( V_38 < 0 )
F_37 ( V_19 ) ;
return V_38 ;
}
void F_38 ( struct V_3 * V_89 )
{
int V_19 ;
if ( V_89 == NULL )
return;
V_19 = F_39 ( V_89 ) ;
if ( V_19 < 0 )
return;
F_37 ( V_19 ) ;
}
int F_40 ( struct V_74 * V_22 )
{
V_22 -> V_85 = V_84 ;
V_84 = V_22 ;
return 0 ;
}
int F_41 ( struct V_74 * V_22 )
{
struct V_74 * V_94 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_95 ; V_9 ++ ) {
struct V_1 * V_2 = F_34 ( V_9 ) ;
if ( ! V_2 )
continue;
F_35 ( & V_2 -> V_93 ) ;
if ( V_2 -> V_31 && V_2 -> V_22 == V_22 ) {
if ( V_2 -> V_96 )
F_13 ( V_2 -> V_33 ,
L_11 ,
V_2 -> V_96 ) ;
F_14 ( V_2 ) ;
}
F_36 ( & V_2 -> V_93 ) ;
}
if ( V_84 == V_22 ) {
V_84 = V_22 -> V_85 ;
return 0 ;
}
for ( V_94 = V_84 ; V_94 -> V_85 ; V_94 = V_94 -> V_85 ) {
if ( V_94 -> V_85 == V_22 ) {
V_94 -> V_85 = V_22 -> V_85 ;
return 0 ;
}
}
return - V_10 ;
}
