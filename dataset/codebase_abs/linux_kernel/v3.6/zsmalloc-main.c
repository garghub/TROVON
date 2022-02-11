static int F_1 ( struct V_1 * V_1 )
{
return F_2 ( V_1 ) ;
}
static int F_3 ( struct V_1 * V_1 )
{
return F_4 ( V_1 ) ;
}
static void F_5 ( struct V_1 * V_1 , unsigned int * V_2 ,
enum V_3 * V_4 )
{
unsigned long V_5 ;
F_6 ( ! F_1 ( V_1 ) ) ;
V_5 = ( unsigned long ) V_1 -> V_6 ;
* V_4 = V_5 & V_7 ;
* V_2 = ( V_5 >> V_8 ) & V_9 ;
}
static void F_7 ( struct V_1 * V_1 , unsigned int V_2 ,
enum V_3 V_4 )
{
unsigned long V_5 ;
F_6 ( ! F_1 ( V_1 ) ) ;
V_5 = ( ( V_2 & V_9 ) << V_8 ) |
( V_4 & V_7 ) ;
V_1 -> V_6 = (struct V_10 * ) V_5 ;
}
static int F_8 ( int V_11 )
{
int V_12 = 0 ;
if ( F_9 ( V_11 > V_13 ) )
V_12 = F_10 ( V_11 - V_13 ,
V_14 ) ;
return V_12 ;
}
static enum V_3 F_11 ( struct V_1 * V_1 )
{
int V_15 , V_16 ;
enum V_3 V_17 ;
F_6 ( ! F_1 ( V_1 ) ) ;
V_15 = V_1 -> V_15 ;
V_16 = V_1 -> V_18 ;
if ( V_15 == 0 )
V_17 = V_19 ;
else if ( V_15 == V_16 )
V_17 = V_20 ;
else if ( V_15 <= V_16 / V_21 )
V_17 = V_22 ;
else
V_17 = V_23 ;
return V_17 ;
}
static void F_12 ( struct V_1 * V_1 , struct V_24 * V_25 ,
enum V_3 V_4 )
{
struct V_1 * * V_26 ;
F_6 ( ! F_1 ( V_1 ) ) ;
if ( V_4 >= V_27 )
return;
V_26 = & V_25 -> V_28 [ V_4 ] ;
if ( * V_26 )
F_13 ( & V_1 -> V_29 , & ( * V_26 ) -> V_29 ) ;
* V_26 = V_1 ;
}
static void F_14 ( struct V_1 * V_1 , struct V_24 * V_25 ,
enum V_3 V_4 )
{
struct V_1 * * V_26 ;
F_6 ( ! F_1 ( V_1 ) ) ;
if ( V_4 >= V_27 )
return;
V_26 = & V_25 -> V_28 [ V_4 ] ;
F_6 ( ! * V_26 ) ;
if ( F_15 ( & ( * V_26 ) -> V_29 ) )
* V_26 = NULL ;
else if ( * V_26 == V_1 )
* V_26 = (struct V_1 * ) F_16 ( ( * V_26 ) -> V_29 . V_30 ,
struct V_1 , V_29 ) ;
F_17 ( & V_1 -> V_29 ) ;
}
static enum V_3 F_18 ( struct V_31 * V_32 ,
struct V_1 * V_1 )
{
int V_2 ;
struct V_24 * V_25 ;
enum V_3 V_33 , V_34 ;
F_6 ( ! F_1 ( V_1 ) ) ;
F_5 ( V_1 , & V_2 , & V_33 ) ;
V_34 = F_11 ( V_1 ) ;
if ( V_34 == V_33 )
goto V_35;
V_25 = & V_32 -> V_24 [ V_2 ] ;
F_14 ( V_1 , V_25 , V_33 ) ;
F_12 ( V_1 , V_25 , V_34 ) ;
F_7 ( V_1 , V_2 , V_34 ) ;
V_35:
return V_34 ;
}
static int F_19 ( int V_36 )
{
int V_37 , V_38 = 0 ;
int V_39 = 1 ;
for ( V_37 = 1 ; V_37 <= V_40 ; V_37 ++ ) {
int V_41 ;
int V_42 , V_43 ;
V_41 = V_37 * V_44 ;
V_42 = V_41 % V_36 ;
V_43 = ( V_41 - V_42 ) * 100 / V_41 ;
if ( V_43 > V_38 ) {
V_38 = V_43 ;
V_39 = V_37 ;
}
}
return V_39 ;
}
static struct V_1 * F_20 ( struct V_1 * V_1 )
{
if ( F_1 ( V_1 ) )
return V_1 ;
else
return V_1 -> V_45 ;
}
static struct V_1 * F_21 ( struct V_1 * V_1 )
{
struct V_1 * V_30 ;
if ( F_3 ( V_1 ) )
V_30 = NULL ;
else if ( F_1 ( V_1 ) )
V_30 = (struct V_1 * ) V_1 -> V_46 ;
else
V_30 = F_16 ( V_1 -> V_29 . V_30 , struct V_1 , V_29 ) ;
return V_30 ;
}
static void * F_22 ( struct V_1 * V_1 , unsigned long V_47 )
{
unsigned long V_48 ;
if ( ! V_1 ) {
F_6 ( V_47 ) ;
return NULL ;
}
V_48 = F_23 ( V_1 ) << V_49 ;
V_48 |= ( V_47 & V_50 ) ;
return ( void * ) V_48 ;
}
static void F_24 ( unsigned long V_48 , struct V_1 * * V_1 ,
unsigned long * V_47 )
{
* V_1 = F_25 ( V_48 >> V_49 ) ;
* V_47 = V_48 & V_50 ;
}
static unsigned long F_26 ( struct V_1 * V_1 ,
unsigned long V_47 , int V_36 )
{
unsigned long V_51 = 0 ;
if ( ! F_1 ( V_1 ) )
V_51 = V_1 -> V_52 ;
return V_51 + V_47 * V_36 ;
}
static void F_27 ( struct V_1 * V_1 )
{
F_28 ( V_53 , & V_1 -> V_54 ) ;
F_28 ( V_55 , & V_1 -> V_54 ) ;
F_29 ( V_1 , 0 ) ;
V_1 -> V_6 = NULL ;
V_1 -> V_56 = NULL ;
F_30 ( V_1 ) ;
}
static void F_31 ( struct V_1 * V_45 )
{
struct V_1 * V_57 , * V_58 , * V_59 ;
F_6 ( ! F_1 ( V_45 ) ) ;
F_6 ( V_45 -> V_15 ) ;
V_59 = (struct V_1 * ) F_32 ( V_45 ) ;
F_27 ( V_45 ) ;
F_33 ( V_45 ) ;
if ( ! V_59 )
return;
F_34 (nextp, tmp, &head_extra->lru, lru) {
F_35 ( & V_57 -> V_29 ) ;
F_27 ( V_57 ) ;
F_33 ( V_57 ) ;
}
F_27 ( V_59 ) ;
F_33 ( V_59 ) ;
}
static void F_36 ( struct V_1 * V_45 , struct V_24 * V_25 )
{
unsigned long V_51 = 0 ;
struct V_1 * V_1 = V_45 ;
F_6 ( ! F_1 ( V_45 ) ) ;
while ( V_1 ) {
struct V_1 * V_60 ;
struct V_61 * V_62 ;
unsigned int V_37 , V_63 ;
if ( V_1 != V_45 )
V_1 -> V_52 = V_51 ;
V_62 = (struct V_61 * ) F_37 ( V_1 ) +
V_51 / sizeof( * V_62 ) ;
V_63 = ( V_44 - V_51 ) / V_25 -> V_11 ;
for ( V_37 = 1 ; V_37 <= V_63 ; V_37 ++ ) {
V_51 += V_25 -> V_11 ;
if ( V_51 < V_44 ) {
V_62 -> V_30 = F_22 ( V_1 , V_37 ) ;
V_62 += V_25 -> V_11 / sizeof( * V_62 ) ;
}
}
V_60 = F_21 ( V_1 ) ;
V_62 -> V_30 = F_22 ( V_60 , 0 ) ;
F_38 ( V_62 ) ;
V_1 = V_60 ;
V_51 = ( V_51 + V_25 -> V_11 ) % V_44 ;
}
}
static struct V_1 * F_39 ( struct V_24 * V_25 , T_1 V_54 )
{
int V_37 , error ;
struct V_1 * V_45 = NULL , * V_64 ( V_65 ) ;
error = - V_66 ;
for ( V_37 = 0 ; V_37 < V_25 -> V_67 ; V_37 ++ ) {
struct V_1 * V_1 ;
V_1 = F_40 ( V_54 ) ;
if ( ! V_1 )
goto V_68;
F_41 ( & V_1 -> V_29 ) ;
if ( V_37 == 0 ) {
F_42 ( V_1 ) ;
F_29 ( V_1 , 0 ) ;
V_45 = V_1 ;
V_45 -> V_15 = 0 ;
}
if ( V_37 == 1 )
V_45 -> V_46 = ( unsigned long ) V_1 ;
if ( V_37 >= 1 )
V_1 -> V_45 = V_45 ;
if ( V_37 >= 2 )
F_43 ( & V_1 -> V_29 , & V_65 -> V_29 ) ;
if ( V_37 == V_25 -> V_67 - 1 )
F_44 ( V_1 ) ;
V_65 = V_1 ;
}
F_36 ( V_45 , V_25 ) ;
V_45 -> V_56 = F_22 ( V_45 , 0 ) ;
V_45 -> V_18 = V_25 -> V_67 * V_44 / V_25 -> V_11 ;
error = 0 ;
V_68:
if ( F_45 ( error ) && V_45 ) {
F_31 ( V_45 ) ;
V_45 = NULL ;
}
return V_45 ;
}
static struct V_1 * F_46 ( struct V_24 * V_25 )
{
int V_37 ;
struct V_1 * V_1 ;
for ( V_37 = 0 ; V_37 < V_27 ; V_37 ++ ) {
V_1 = V_25 -> V_28 [ V_37 ] ;
if ( V_1 )
break;
}
return V_1 ;
}
static void F_47 ( char * V_69 , struct V_1 * V_70 ,
int V_51 , int V_11 )
{
struct V_1 * V_71 [ 2 ] ;
int V_72 [ 2 ] ;
void * V_73 ;
V_71 [ 0 ] = V_70 ;
V_71 [ 1 ] = F_21 ( V_70 ) ;
F_6 ( ! V_71 [ 1 ] ) ;
V_72 [ 0 ] = V_44 - V_51 ;
V_72 [ 1 ] = V_11 - V_72 [ 0 ] ;
V_73 = F_37 ( V_71 [ 0 ] ) ;
memcpy ( V_69 , V_73 + V_51 , V_72 [ 0 ] ) ;
F_38 ( V_73 ) ;
V_73 = F_37 ( V_71 [ 1 ] ) ;
memcpy ( V_69 + V_72 [ 0 ] , V_73 , V_72 [ 1 ] ) ;
F_38 ( V_73 ) ;
}
static void F_48 ( char * V_69 , struct V_1 * V_70 ,
int V_51 , int V_11 )
{
struct V_1 * V_71 [ 2 ] ;
int V_72 [ 2 ] ;
void * V_73 ;
V_71 [ 0 ] = V_70 ;
V_71 [ 1 ] = F_21 ( V_70 ) ;
F_6 ( ! V_71 [ 1 ] ) ;
V_72 [ 0 ] = V_44 - V_51 ;
V_72 [ 1 ] = V_11 - V_72 [ 0 ] ;
V_73 = F_37 ( V_71 [ 0 ] ) ;
memcpy ( V_73 + V_51 , V_69 , V_72 [ 0 ] ) ;
F_38 ( V_73 ) ;
V_73 = F_37 ( V_71 [ 1 ] ) ;
memcpy ( V_73 , V_69 + V_72 [ 0 ] , V_72 [ 1 ] ) ;
F_38 ( V_73 ) ;
}
static int F_49 ( struct V_74 * V_75 , unsigned long V_76 ,
void * V_77 )
{
int V_78 = ( long ) V_77 ;
struct V_79 * V_80 ;
switch ( V_76 ) {
case V_81 :
V_80 = & F_50 ( V_82 , V_78 ) ;
if ( V_80 -> V_83 )
return 0 ;
V_80 -> V_83 = ( char * ) F_51 ( V_84 ) ;
if ( ! V_80 -> V_83 )
return - V_66 ;
return 0 ;
break;
case V_85 :
case V_86 :
V_80 = & F_50 ( V_82 , V_78 ) ;
if ( V_80 -> V_83 )
F_52 ( ( unsigned long ) V_80 -> V_83 ) ;
V_80 -> V_83 = NULL ;
break;
}
return V_87 ;
}
static void F_53 ( void )
{
int V_78 ;
F_54 (cpu)
F_49 ( NULL , V_85 , ( void * ) ( long ) V_78 ) ;
F_55 ( & V_88 ) ;
}
static int F_56 ( void )
{
int V_78 , V_89 ;
F_57 ( & V_88 ) ;
F_54 (cpu) {
V_89 = F_49 ( NULL , V_81 , ( void * ) ( long ) V_78 ) ;
if ( F_58 ( V_89 ) )
goto V_90;
}
return 0 ;
V_90:
F_53 () ;
return F_58 ( V_89 ) ;
}
struct V_31 * F_59 ( const char * V_91 , T_1 V_54 )
{
int V_37 , V_92 ;
struct V_31 * V_32 ;
if ( ! V_91 )
return NULL ;
V_92 = F_60 ( sizeof( * V_32 ) , V_44 ) ;
V_32 = F_61 ( V_92 , V_84 ) ;
if ( ! V_32 )
return NULL ;
for ( V_37 = 0 ; V_37 < V_93 ; V_37 ++ ) {
int V_11 ;
struct V_24 * V_25 ;
V_11 = V_13 + V_37 * V_14 ;
if ( V_11 > V_94 )
V_11 = V_94 ;
V_25 = & V_32 -> V_24 [ V_37 ] ;
V_25 -> V_11 = V_11 ;
V_25 -> V_52 = V_37 ;
F_62 ( & V_25 -> V_95 ) ;
V_25 -> V_67 = F_19 ( V_11 ) ;
}
V_32 -> V_54 = V_54 ;
V_32 -> V_91 = V_91 ;
return V_32 ;
}
void F_63 ( struct V_31 * V_32 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_93 ; V_37 ++ ) {
int V_17 ;
struct V_24 * V_25 = & V_32 -> V_24 [ V_37 ] ;
for ( V_17 = 0 ; V_17 < V_27 ; V_17 ++ ) {
if ( V_25 -> V_28 [ V_17 ] ) {
F_64 ( L_1
L_2 ,
V_25 -> V_11 , V_17 ) ;
}
}
}
F_65 ( V_32 ) ;
}
unsigned long F_66 ( struct V_31 * V_32 , T_2 V_11 )
{
unsigned long V_96 ;
struct V_61 * V_62 ;
int V_2 ;
struct V_24 * V_25 ;
struct V_1 * V_45 , * V_97 ;
unsigned long V_98 , V_99 ;
if ( F_45 ( ! V_11 || V_11 > V_94 ) )
return 0 ;
V_2 = F_8 ( V_11 ) ;
V_25 = & V_32 -> V_24 [ V_2 ] ;
F_6 ( V_2 != V_25 -> V_52 ) ;
F_67 ( & V_25 -> V_95 ) ;
V_45 = F_46 ( V_25 ) ;
if ( ! V_45 ) {
F_68 ( & V_25 -> V_95 ) ;
V_45 = F_39 ( V_25 , V_32 -> V_54 ) ;
if ( F_45 ( ! V_45 ) )
return 0 ;
F_7 ( V_45 , V_25 -> V_52 , V_19 ) ;
F_67 ( & V_25 -> V_95 ) ;
V_25 -> V_100 += V_25 -> V_67 ;
}
V_96 = ( unsigned long ) V_45 -> V_56 ;
F_24 ( V_96 , & V_97 , & V_98 ) ;
V_99 = F_26 ( V_97 , V_98 , V_25 -> V_11 ) ;
V_62 = (struct V_61 * ) F_37 ( V_97 ) +
V_99 / sizeof( * V_62 ) ;
V_45 -> V_56 = V_62 -> V_30 ;
memset ( V_62 , V_101 , sizeof( * V_62 ) ) ;
F_38 ( V_62 ) ;
V_45 -> V_15 ++ ;
F_18 ( V_32 , V_45 ) ;
F_68 ( & V_25 -> V_95 ) ;
return V_96 ;
}
void F_69 ( struct V_31 * V_32 , unsigned long V_96 )
{
struct V_61 * V_62 ;
struct V_1 * V_45 , * V_102 ;
unsigned long V_103 , V_104 ;
int V_2 ;
struct V_24 * V_25 ;
enum V_3 V_4 ;
if ( F_45 ( ! V_96 ) )
return;
F_24 ( V_96 , & V_102 , & V_103 ) ;
V_45 = F_20 ( V_102 ) ;
F_5 ( V_45 , & V_2 , & V_4 ) ;
V_25 = & V_32 -> V_24 [ V_2 ] ;
V_104 = F_26 ( V_102 , V_103 , V_25 -> V_11 ) ;
F_67 ( & V_25 -> V_95 ) ;
V_62 = (struct V_61 * ) ( ( unsigned char * ) F_37 ( V_102 )
+ V_104 ) ;
V_62 -> V_30 = V_45 -> V_56 ;
F_38 ( V_62 ) ;
V_45 -> V_56 = ( void * ) V_96 ;
V_45 -> V_15 -- ;
V_4 = F_18 ( V_32 , V_45 ) ;
if ( V_4 == V_19 )
V_25 -> V_100 -= V_25 -> V_67 ;
F_68 ( & V_25 -> V_95 ) ;
if ( V_4 == V_19 )
F_31 ( V_45 ) ;
}
void * F_70 ( struct V_31 * V_32 , unsigned long V_48 ,
enum V_105 V_106 )
{
struct V_1 * V_1 ;
unsigned long V_47 , V_51 ;
unsigned int V_2 ;
enum V_3 V_17 ;
struct V_24 * V_25 ;
struct V_79 * V_80 ;
F_6 ( ! V_48 ) ;
F_24 ( V_48 , & V_1 , & V_47 ) ;
F_5 ( F_20 ( V_1 ) , & V_2 , & V_17 ) ;
V_25 = & V_32 -> V_24 [ V_2 ] ;
V_51 = F_26 ( V_1 , V_47 , V_25 -> V_11 ) ;
V_80 = & F_71 ( V_82 ) ;
if ( V_51 + V_25 -> V_11 <= V_44 ) {
V_80 -> V_107 = F_37 ( V_1 ) ;
return V_80 -> V_107 + V_51 ;
}
F_72 () ;
if ( V_106 != V_108 )
F_47 ( V_80 -> V_83 , V_1 , V_51 , V_25 -> V_11 ) ;
V_80 -> V_107 = NULL ;
return V_80 -> V_83 ;
}
void F_73 ( struct V_31 * V_32 , unsigned long V_48 )
{
struct V_1 * V_1 ;
unsigned long V_47 , V_51 ;
unsigned int V_2 ;
enum V_3 V_17 ;
struct V_24 * V_25 ;
struct V_79 * V_80 ;
V_80 = & F_74 ( V_82 ) ;
if ( V_80 -> V_107 ) {
F_38 ( V_80 -> V_107 ) ;
goto V_35;
}
if ( V_80 -> V_109 == V_110 )
goto V_111;
F_6 ( ! V_48 ) ;
F_24 ( V_48 , & V_1 , & V_47 ) ;
F_5 ( F_20 ( V_1 ) , & V_2 , & V_17 ) ;
V_25 = & V_32 -> V_24 [ V_2 ] ;
V_51 = F_26 ( V_1 , V_47 , V_25 -> V_11 ) ;
F_48 ( V_80 -> V_83 , V_1 , V_51 , V_25 -> V_11 ) ;
V_111:
F_75 () ;
V_35:
F_76 ( V_82 ) ;
}
T_3 F_77 ( struct V_31 * V_32 )
{
int V_37 ;
T_3 V_112 = 0 ;
for ( V_37 = 0 ; V_37 < V_93 ; V_37 ++ )
V_112 += V_32 -> V_24 [ V_37 ] . V_100 ;
return V_112 << V_113 ;
}
