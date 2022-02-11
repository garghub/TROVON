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
static void F_24 ( void * V_48 , struct V_1 * * V_1 ,
unsigned long * V_47 )
{
unsigned long V_51 = ( unsigned long ) V_48 ;
* V_1 = F_25 ( V_51 >> V_49 ) ;
* V_47 = V_51 & V_50 ;
}
static unsigned long F_26 ( struct V_1 * V_1 ,
unsigned long V_47 , int V_36 )
{
unsigned long V_52 = 0 ;
if ( ! F_1 ( V_1 ) )
V_52 = V_1 -> V_53 ;
return V_52 + V_47 * V_36 ;
}
static void F_27 ( struct V_1 * V_1 )
{
F_28 ( V_54 , & V_1 -> V_55 ) ;
F_28 ( V_56 , & V_1 -> V_55 ) ;
F_29 ( V_1 , 0 ) ;
V_1 -> V_6 = NULL ;
V_1 -> V_57 = NULL ;
F_30 ( V_1 ) ;
}
static void F_31 ( struct V_1 * V_45 )
{
struct V_1 * V_58 , * V_59 , * V_60 ;
F_6 ( ! F_1 ( V_45 ) ) ;
F_6 ( V_45 -> V_15 ) ;
V_60 = (struct V_1 * ) F_32 ( V_45 ) ;
F_27 ( V_45 ) ;
F_33 ( V_45 ) ;
if ( ! V_60 )
return;
F_34 (nextp, tmp, &head_extra->lru, lru) {
F_35 ( & V_58 -> V_29 ) ;
F_27 ( V_58 ) ;
F_33 ( V_58 ) ;
}
F_27 ( V_60 ) ;
F_33 ( V_60 ) ;
}
static void F_36 ( struct V_1 * V_45 , struct V_24 * V_25 )
{
unsigned long V_52 = 0 ;
struct V_1 * V_1 = V_45 ;
F_6 ( ! F_1 ( V_45 ) ) ;
while ( V_1 ) {
struct V_1 * V_61 ;
struct V_62 * V_63 ;
unsigned int V_37 , V_64 ;
if ( V_1 != V_45 )
V_1 -> V_53 = V_52 ;
V_63 = (struct V_62 * ) F_37 ( V_1 ) +
V_52 / sizeof( * V_63 ) ;
V_64 = ( V_44 - V_52 ) / V_25 -> V_11 ;
for ( V_37 = 1 ; V_37 <= V_64 ; V_37 ++ ) {
V_52 += V_25 -> V_11 ;
if ( V_52 < V_44 ) {
V_63 -> V_30 = F_22 ( V_1 , V_37 ) ;
V_63 += V_25 -> V_11 / sizeof( * V_63 ) ;
}
}
V_61 = F_21 ( V_1 ) ;
V_63 -> V_30 = F_22 ( V_61 , 0 ) ;
F_38 ( V_63 ) ;
V_1 = V_61 ;
V_52 = ( V_52 + V_25 -> V_11 ) % V_44 ;
}
}
static struct V_1 * F_39 ( struct V_24 * V_25 , T_1 V_55 )
{
int V_37 , error ;
struct V_1 * V_45 = NULL ;
error = - V_65 ;
for ( V_37 = 0 ; V_37 < V_25 -> V_66 ; V_37 ++ ) {
struct V_1 * V_1 , * V_67 ;
V_1 = F_40 ( V_55 ) ;
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
F_43 ( & V_1 -> V_29 , & V_67 -> V_29 ) ;
if ( V_37 == V_25 -> V_66 - 1 )
F_44 ( V_1 ) ;
V_67 = V_1 ;
}
F_36 ( V_45 , V_25 ) ;
V_45 -> V_57 = F_22 ( V_45 , 0 ) ;
V_45 -> V_18 = V_25 -> V_66 * V_44 / V_25 -> V_11 ;
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
static int F_47 ( struct V_69 * V_70 , unsigned long V_71 ,
void * V_72 )
{
int V_73 = ( long ) V_72 ;
struct V_74 * V_75 ;
switch ( V_71 ) {
case V_76 :
V_75 = & F_48 ( V_77 , V_73 ) ;
if ( V_75 -> V_78 )
break;
V_75 -> V_78 = F_49 ( 2 * V_44 , V_75 -> V_79 ) ;
if ( ! V_75 -> V_78 )
return F_50 ( - V_65 ) ;
break;
case V_80 :
case V_81 :
V_75 = & F_48 ( V_77 , V_73 ) ;
if ( V_75 -> V_78 )
F_51 ( V_75 -> V_78 ) ;
V_75 -> V_78 = NULL ;
break;
}
return V_82 ;
}
static void F_52 ( void )
{
int V_73 ;
F_53 (cpu)
F_47 ( NULL , V_80 , ( void * ) ( long ) V_73 ) ;
F_54 ( & V_83 ) ;
}
static int F_55 ( void )
{
int V_73 , V_84 ;
F_56 ( & V_83 ) ;
F_53 (cpu) {
V_84 = F_47 ( NULL , V_76 , ( void * ) ( long ) V_73 ) ;
if ( F_57 ( V_84 ) )
goto V_85;
}
return 0 ;
V_85:
F_52 () ;
return F_57 ( V_84 ) ;
}
struct V_31 * F_58 ( const char * V_86 , T_1 V_55 )
{
int V_37 , error , V_87 ;
struct V_31 * V_32 ;
if ( ! V_86 )
return NULL ;
V_87 = F_59 ( sizeof( * V_32 ) , V_44 ) ;
V_32 = F_60 ( V_87 , V_88 ) ;
if ( ! V_32 )
return NULL ;
for ( V_37 = 0 ; V_37 < V_89 ; V_37 ++ ) {
int V_11 ;
struct V_24 * V_25 ;
V_11 = V_13 + V_37 * V_14 ;
if ( V_11 > V_90 )
V_11 = V_90 ;
V_25 = & V_32 -> V_24 [ V_37 ] ;
V_25 -> V_11 = V_11 ;
V_25 -> V_53 = V_37 ;
F_61 ( & V_25 -> V_91 ) ;
V_25 -> V_66 = F_19 ( V_11 ) ;
}
if ( ! V_92 ) {
error = F_55 () ;
if ( error )
goto V_68;
V_92 = 1 ;
}
V_32 -> V_55 = V_55 ;
V_32 -> V_86 = V_86 ;
error = 0 ;
V_68:
if ( error ) {
F_62 ( V_32 ) ;
V_32 = NULL ;
}
return V_32 ;
}
void F_62 ( struct V_31 * V_32 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_89 ; V_37 ++ ) {
int V_17 ;
struct V_24 * V_25 = & V_32 -> V_24 [ V_37 ] ;
for ( V_17 = 0 ; V_17 < V_27 ; V_17 ++ ) {
if ( V_25 -> V_28 [ V_17 ] ) {
F_63 ( L_1
L_2 ,
V_25 -> V_11 , V_17 ) ;
}
}
}
F_64 ( V_32 ) ;
}
void * F_65 ( struct V_31 * V_32 , T_2 V_11 )
{
void * V_93 ;
struct V_62 * V_63 ;
int V_2 ;
struct V_24 * V_25 ;
struct V_1 * V_45 , * V_94 ;
unsigned long V_95 , V_96 ;
if ( F_45 ( ! V_11 || V_11 > V_90 ) )
return NULL ;
V_2 = F_8 ( V_11 ) ;
V_25 = & V_32 -> V_24 [ V_2 ] ;
F_6 ( V_2 != V_25 -> V_53 ) ;
F_66 ( & V_25 -> V_91 ) ;
V_45 = F_46 ( V_25 ) ;
if ( ! V_45 ) {
F_67 ( & V_25 -> V_91 ) ;
V_45 = F_39 ( V_25 , V_32 -> V_55 ) ;
if ( F_45 ( ! V_45 ) )
return NULL ;
F_7 ( V_45 , V_25 -> V_53 , V_19 ) ;
F_66 ( & V_25 -> V_91 ) ;
V_25 -> V_97 += V_25 -> V_66 ;
}
V_93 = V_45 -> V_57 ;
F_24 ( V_93 , & V_94 , & V_95 ) ;
V_96 = F_26 ( V_94 , V_95 , V_25 -> V_11 ) ;
V_63 = (struct V_62 * ) F_37 ( V_94 ) +
V_96 / sizeof( * V_63 ) ;
V_45 -> V_57 = V_63 -> V_30 ;
memset ( V_63 , V_98 , sizeof( * V_63 ) ) ;
F_38 ( V_63 ) ;
V_45 -> V_15 ++ ;
F_18 ( V_32 , V_45 ) ;
F_67 ( & V_25 -> V_91 ) ;
return V_93 ;
}
void F_68 ( struct V_31 * V_32 , void * V_93 )
{
struct V_62 * V_63 ;
struct V_1 * V_45 , * V_99 ;
unsigned long V_100 , V_101 ;
int V_2 ;
struct V_24 * V_25 ;
enum V_3 V_4 ;
if ( F_45 ( ! V_93 ) )
return;
F_24 ( V_93 , & V_99 , & V_100 ) ;
V_45 = F_20 ( V_99 ) ;
F_5 ( V_45 , & V_2 , & V_4 ) ;
V_25 = & V_32 -> V_24 [ V_2 ] ;
V_101 = F_26 ( V_99 , V_100 , V_25 -> V_11 ) ;
F_66 ( & V_25 -> V_91 ) ;
V_63 = (struct V_62 * ) ( ( unsigned char * ) F_37 ( V_99 )
+ V_101 ) ;
V_63 -> V_30 = V_45 -> V_57 ;
F_38 ( V_63 ) ;
V_45 -> V_57 = V_93 ;
V_45 -> V_15 -- ;
V_4 = F_18 ( V_32 , V_45 ) ;
if ( V_4 == V_19 )
V_25 -> V_97 -= V_25 -> V_66 ;
F_67 ( & V_25 -> V_91 ) ;
if ( V_4 == V_19 )
F_31 ( V_45 ) ;
}
void * F_69 ( struct V_31 * V_32 , void * V_48 )
{
struct V_1 * V_1 ;
unsigned long V_47 , V_52 ;
unsigned int V_2 ;
enum V_3 V_17 ;
struct V_24 * V_25 ;
struct V_74 * V_75 ;
F_6 ( ! V_48 ) ;
F_24 ( V_48 , & V_1 , & V_47 ) ;
F_5 ( F_20 ( V_1 ) , & V_2 , & V_17 ) ;
V_25 = & V_32 -> V_24 [ V_2 ] ;
V_52 = F_26 ( V_1 , V_47 , V_25 -> V_11 ) ;
V_75 = & F_70 ( V_77 ) ;
if ( V_52 + V_25 -> V_11 <= V_44 ) {
V_75 -> V_102 = F_37 ( V_1 ) ;
} else {
struct V_1 * V_58 ;
V_58 = F_21 ( V_1 ) ;
F_6 ( ! V_58 ) ;
F_71 ( V_75 -> V_79 [ 0 ] , F_72 ( V_1 , V_103 ) ) ;
F_71 ( V_75 -> V_79 [ 1 ] , F_72 ( V_58 , V_103 ) ) ;
V_75 -> V_102 = V_75 -> V_78 -> V_104 ;
}
return V_75 -> V_102 + V_52 ;
}
void F_73 ( struct V_31 * V_32 , void * V_48 )
{
struct V_1 * V_1 ;
unsigned long V_47 , V_52 ;
unsigned int V_2 ;
enum V_3 V_17 ;
struct V_24 * V_25 ;
struct V_74 * V_75 ;
F_6 ( ! V_48 ) ;
F_24 ( V_48 , & V_1 , & V_47 ) ;
F_5 ( F_20 ( V_1 ) , & V_2 , & V_17 ) ;
V_25 = & V_32 -> V_24 [ V_2 ] ;
V_52 = F_26 ( V_1 , V_47 , V_25 -> V_11 ) ;
V_75 = & F_74 ( V_77 ) ;
if ( V_52 + V_25 -> V_11 <= V_44 ) {
F_38 ( V_75 -> V_102 ) ;
} else {
F_71 ( V_75 -> V_79 [ 0 ] , F_75 ( 0 ) ) ;
F_71 ( V_75 -> V_79 [ 1 ] , F_75 ( 0 ) ) ;
F_76 ( ( unsigned long ) V_75 -> V_102 ) ;
F_76 ( ( unsigned long ) V_75 -> V_102 + V_44 ) ;
}
F_77 ( V_77 ) ;
}
T_3 F_78 ( struct V_31 * V_32 )
{
int V_37 ;
T_3 V_105 = 0 ;
for ( V_37 = 0 ; V_37 < V_89 ; V_37 ++ )
V_105 += V_32 -> V_24 [ V_37 ] . V_97 ;
return V_105 << V_106 ;
}
