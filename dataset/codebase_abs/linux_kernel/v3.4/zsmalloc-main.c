static int F_1 ( struct V_1 * V_1 )
{
return F_2 ( V_2 , & V_1 -> V_3 ) ;
}
static int F_3 ( struct V_1 * V_1 )
{
return F_2 ( V_4 , & V_1 -> V_3 ) ;
}
static void F_4 ( struct V_1 * V_1 , unsigned int * V_5 ,
enum V_6 * V_7 )
{
unsigned long V_8 ;
F_5 ( ! F_1 ( V_1 ) ) ;
V_8 = ( unsigned long ) V_1 -> V_9 ;
* V_7 = V_8 & V_10 ;
* V_5 = ( V_8 >> V_11 ) & V_12 ;
}
static void F_6 ( struct V_1 * V_1 , unsigned int V_5 ,
enum V_6 V_7 )
{
unsigned long V_8 ;
F_5 ( ! F_1 ( V_1 ) ) ;
V_8 = ( ( V_5 & V_12 ) << V_11 ) |
( V_7 & V_10 ) ;
V_1 -> V_9 = (struct V_13 * ) V_8 ;
}
static int F_7 ( int V_14 )
{
int V_15 = 0 ;
if ( F_8 ( V_14 > V_16 ) )
V_15 = F_9 ( V_14 - V_16 ,
V_17 ) ;
return V_15 ;
}
static enum V_6 F_10 ( struct V_1 * V_1 )
{
int V_18 , V_19 ;
enum V_6 V_20 ;
F_5 ( ! F_1 ( V_1 ) ) ;
V_18 = V_1 -> V_18 ;
V_19 = V_1 -> V_21 ;
if ( V_18 == 0 )
V_20 = V_22 ;
else if ( V_18 == V_19 )
V_20 = V_23 ;
else if ( V_18 <= V_19 / V_24 )
V_20 = V_25 ;
else
V_20 = V_26 ;
return V_20 ;
}
static void F_11 ( struct V_1 * V_1 , struct V_27 * V_28 ,
enum V_6 V_7 )
{
struct V_1 * * V_29 ;
F_5 ( ! F_1 ( V_1 ) ) ;
if ( V_7 >= V_30 )
return;
V_29 = & V_28 -> V_31 [ V_7 ] ;
if ( * V_29 )
F_12 ( & V_1 -> V_32 , & ( * V_29 ) -> V_32 ) ;
* V_29 = V_1 ;
}
static void F_13 ( struct V_1 * V_1 , struct V_27 * V_28 ,
enum V_6 V_7 )
{
struct V_1 * * V_29 ;
F_5 ( ! F_1 ( V_1 ) ) ;
if ( V_7 >= V_30 )
return;
V_29 = & V_28 -> V_31 [ V_7 ] ;
F_5 ( ! * V_29 ) ;
if ( F_14 ( & ( * V_29 ) -> V_32 ) )
* V_29 = NULL ;
else if ( * V_29 == V_1 )
* V_29 = (struct V_1 * ) F_15 ( ( * V_29 ) -> V_32 . V_33 ,
struct V_1 , V_32 ) ;
F_16 ( & V_1 -> V_32 ) ;
}
static enum V_6 F_17 ( struct V_34 * V_35 ,
struct V_1 * V_1 )
{
int V_5 ;
struct V_27 * V_28 ;
enum V_6 V_36 , V_37 ;
F_5 ( ! F_1 ( V_1 ) ) ;
F_4 ( V_1 , & V_5 , & V_36 ) ;
V_37 = F_10 ( V_1 ) ;
if ( V_37 == V_36 )
goto V_38;
V_28 = & V_35 -> V_27 [ V_5 ] ;
F_13 ( V_1 , V_28 , V_36 ) ;
F_11 ( V_1 , V_28 , V_37 ) ;
F_6 ( V_1 , V_5 , V_37 ) ;
V_38:
return V_37 ;
}
static int F_18 ( int V_39 )
{
int V_40 , V_41 = 0 ;
int V_42 = 1 ;
for ( V_40 = 1 ; V_40 <= V_43 ; V_40 ++ ) {
int V_44 ;
int V_45 , V_46 ;
V_44 = V_40 * V_47 ;
V_45 = V_44 % V_39 ;
V_46 = ( V_44 - V_45 ) * 100 / V_44 ;
if ( V_46 > V_41 ) {
V_41 = V_46 ;
V_42 = V_40 ;
}
}
return V_42 ;
}
static struct V_1 * F_19 ( struct V_1 * V_1 )
{
if ( F_1 ( V_1 ) )
return V_1 ;
else
return V_1 -> V_48 ;
}
static struct V_1 * F_20 ( struct V_1 * V_1 )
{
struct V_1 * V_33 ;
if ( F_3 ( V_1 ) )
V_33 = NULL ;
else if ( F_1 ( V_1 ) )
V_33 = (struct V_1 * ) V_1 -> V_49 ;
else
V_33 = F_15 ( V_1 -> V_32 . V_33 , struct V_1 , V_32 ) ;
return V_33 ;
}
static void * F_21 ( struct V_1 * V_1 , unsigned long V_50 )
{
unsigned long V_51 ;
if ( ! V_1 ) {
F_5 ( V_50 ) ;
return NULL ;
}
V_51 = F_22 ( V_1 ) << V_52 ;
V_51 |= ( V_50 & V_53 ) ;
return ( void * ) V_51 ;
}
static void F_23 ( void * V_51 , struct V_1 * * V_1 ,
unsigned long * V_50 )
{
unsigned long V_54 = ( unsigned long ) V_51 ;
* V_1 = F_24 ( V_54 >> V_52 ) ;
* V_50 = V_54 & V_53 ;
}
static unsigned long F_25 ( struct V_1 * V_1 ,
unsigned long V_50 , int V_39 )
{
unsigned long V_55 = 0 ;
if ( ! F_1 ( V_1 ) )
V_55 = V_1 -> V_56 ;
return V_55 + V_50 * V_39 ;
}
static void F_26 ( struct V_1 * V_1 )
{
F_27 ( V_2 , & V_1 -> V_3 ) ;
F_27 ( V_4 , & V_1 -> V_3 ) ;
F_28 ( V_1 , 0 ) ;
V_1 -> V_9 = NULL ;
V_1 -> V_57 = NULL ;
F_29 ( V_1 ) ;
}
static void F_30 ( struct V_1 * V_48 )
{
struct V_1 * V_58 , * V_59 , * V_60 ;
F_5 ( ! F_1 ( V_48 ) ) ;
F_5 ( V_48 -> V_18 ) ;
V_60 = (struct V_1 * ) F_31 ( V_48 ) ;
F_26 ( V_48 ) ;
F_32 ( V_48 ) ;
if ( ! V_60 )
return;
F_33 (nextp, tmp, &head_extra->lru, lru) {
F_34 ( & V_58 -> V_32 ) ;
F_26 ( V_58 ) ;
F_32 ( V_58 ) ;
}
F_26 ( V_60 ) ;
F_32 ( V_60 ) ;
}
static void F_35 ( struct V_1 * V_48 , struct V_27 * V_28 )
{
unsigned long V_55 = 0 ;
struct V_1 * V_1 = V_48 ;
F_5 ( ! F_1 ( V_48 ) ) ;
while ( V_1 ) {
struct V_1 * V_61 ;
struct V_62 * V_63 ;
unsigned int V_40 , V_64 ;
if ( V_1 != V_48 )
V_1 -> V_56 = V_55 ;
V_63 = (struct V_62 * ) F_36 ( V_1 ) +
V_55 / sizeof( * V_63 ) ;
V_64 = ( V_47 - V_55 ) / V_28 -> V_14 ;
for ( V_40 = 1 ; V_40 <= V_64 ; V_40 ++ ) {
V_55 += V_28 -> V_14 ;
if ( V_55 < V_47 ) {
V_63 -> V_33 = F_21 ( V_1 , V_40 ) ;
V_63 += V_28 -> V_14 / sizeof( * V_63 ) ;
}
}
V_61 = F_20 ( V_1 ) ;
V_63 -> V_33 = F_21 ( V_61 , 0 ) ;
F_37 ( V_63 ) ;
V_1 = V_61 ;
V_55 = ( V_55 + V_28 -> V_14 ) % V_47 ;
}
}
static struct V_1 * F_38 ( struct V_27 * V_28 , T_1 V_3 )
{
int V_40 , error ;
struct V_1 * V_48 = NULL ;
error = - V_65 ;
for ( V_40 = 0 ; V_40 < V_28 -> V_66 ; V_40 ++ ) {
struct V_1 * V_1 , * V_67 ;
V_1 = F_39 ( V_3 ) ;
if ( ! V_1 )
goto V_68;
F_40 ( & V_1 -> V_32 ) ;
if ( V_40 == 0 ) {
F_41 ( V_2 , & V_1 -> V_3 ) ;
F_28 ( V_1 , 0 ) ;
V_48 = V_1 ;
V_48 -> V_18 = 0 ;
}
if ( V_40 == 1 )
V_48 -> V_49 = ( unsigned long ) V_1 ;
if ( V_40 >= 1 )
V_1 -> V_48 = V_48 ;
if ( V_40 >= 2 )
F_42 ( & V_1 -> V_32 , & V_67 -> V_32 ) ;
if ( V_40 == V_28 -> V_66 - 1 )
F_41 ( V_4 , & V_1 -> V_3 ) ;
V_67 = V_1 ;
}
F_35 ( V_48 , V_28 ) ;
V_48 -> V_57 = F_21 ( V_48 , 0 ) ;
V_48 -> V_21 = V_28 -> V_66 * V_47 / V_28 -> V_14 ;
error = 0 ;
V_68:
if ( F_43 ( error ) && V_48 ) {
F_30 ( V_48 ) ;
V_48 = NULL ;
}
return V_48 ;
}
static struct V_1 * F_44 ( struct V_27 * V_28 )
{
int V_40 ;
struct V_1 * V_1 ;
for ( V_40 = 0 ; V_40 < V_30 ; V_40 ++ ) {
V_1 = V_28 -> V_31 [ V_40 ] ;
if ( V_1 )
break;
}
return V_1 ;
}
static int F_45 ( struct V_69 * V_70 , unsigned long V_71 ,
void * V_72 )
{
int V_73 = ( long ) V_72 ;
struct V_74 * V_75 ;
switch ( V_71 ) {
case V_76 :
V_75 = & F_46 ( V_77 , V_73 ) ;
if ( V_75 -> V_78 )
break;
V_75 -> V_78 = F_47 ( 2 * V_47 , V_75 -> V_79 ) ;
if ( ! V_75 -> V_78 )
return F_48 ( - V_65 ) ;
break;
case V_80 :
case V_81 :
V_75 = & F_46 ( V_77 , V_73 ) ;
if ( V_75 -> V_78 )
F_49 ( V_75 -> V_78 ) ;
V_75 -> V_78 = NULL ;
break;
}
return V_82 ;
}
static void F_50 ( void )
{
int V_73 ;
F_51 (cpu)
F_45 ( NULL , V_80 , ( void * ) ( long ) V_73 ) ;
F_52 ( & V_83 ) ;
}
static int F_53 ( void )
{
int V_73 , V_84 ;
F_54 ( & V_83 ) ;
F_51 (cpu) {
V_84 = F_45 ( NULL , V_76 , ( void * ) ( long ) V_73 ) ;
if ( F_55 ( V_84 ) )
goto V_85;
}
return 0 ;
V_85:
F_50 () ;
return F_55 ( V_84 ) ;
}
struct V_34 * F_56 ( const char * V_86 , T_1 V_3 )
{
int V_40 , error , V_87 ;
struct V_34 * V_35 ;
if ( ! V_86 )
return NULL ;
V_87 = F_57 ( sizeof( * V_35 ) , V_47 ) ;
V_35 = F_58 ( V_87 , V_88 ) ;
if ( ! V_35 )
return NULL ;
for ( V_40 = 0 ; V_40 < V_89 ; V_40 ++ ) {
int V_14 ;
struct V_27 * V_28 ;
V_14 = V_16 + V_40 * V_17 ;
if ( V_14 > V_90 )
V_14 = V_90 ;
V_28 = & V_35 -> V_27 [ V_40 ] ;
V_28 -> V_14 = V_14 ;
V_28 -> V_56 = V_40 ;
F_59 ( & V_28 -> V_91 ) ;
V_28 -> V_66 = F_18 ( V_14 ) ;
}
if ( ! V_92 ) {
error = F_53 () ;
if ( error )
goto V_68;
V_92 = 1 ;
}
V_35 -> V_3 = V_3 ;
V_35 -> V_86 = V_86 ;
error = 0 ;
V_68:
if ( error ) {
F_60 ( V_35 ) ;
V_35 = NULL ;
}
return V_35 ;
}
void F_60 ( struct V_34 * V_35 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_89 ; V_40 ++ ) {
int V_20 ;
struct V_27 * V_28 = & V_35 -> V_27 [ V_40 ] ;
for ( V_20 = 0 ; V_20 < V_30 ; V_20 ++ ) {
if ( V_28 -> V_31 [ V_20 ] ) {
F_61 ( L_1
L_2 ,
V_28 -> V_14 , V_20 ) ;
}
}
}
F_62 ( V_35 ) ;
}
void * F_63 ( struct V_34 * V_35 , T_2 V_14 )
{
void * V_93 ;
struct V_62 * V_63 ;
int V_5 ;
struct V_27 * V_28 ;
struct V_1 * V_48 , * V_94 ;
unsigned long V_95 , V_96 ;
if ( F_43 ( ! V_14 || V_14 > V_90 ) )
return NULL ;
V_5 = F_7 ( V_14 ) ;
V_28 = & V_35 -> V_27 [ V_5 ] ;
F_5 ( V_5 != V_28 -> V_56 ) ;
F_64 ( & V_28 -> V_91 ) ;
V_48 = F_44 ( V_28 ) ;
if ( ! V_48 ) {
F_65 ( & V_28 -> V_91 ) ;
V_48 = F_38 ( V_28 , V_35 -> V_3 ) ;
if ( F_43 ( ! V_48 ) )
return NULL ;
F_6 ( V_48 , V_28 -> V_56 , V_22 ) ;
F_64 ( & V_28 -> V_91 ) ;
V_28 -> V_97 += V_28 -> V_66 ;
}
V_93 = V_48 -> V_57 ;
F_23 ( V_93 , & V_94 , & V_95 ) ;
V_96 = F_25 ( V_94 , V_95 , V_28 -> V_14 ) ;
V_63 = (struct V_62 * ) F_36 ( V_94 ) +
V_96 / sizeof( * V_63 ) ;
V_48 -> V_57 = V_63 -> V_33 ;
memset ( V_63 , V_98 , sizeof( * V_63 ) ) ;
F_37 ( V_63 ) ;
V_48 -> V_18 ++ ;
F_17 ( V_35 , V_48 ) ;
F_65 ( & V_28 -> V_91 ) ;
return V_93 ;
}
void F_66 ( struct V_34 * V_35 , void * V_93 )
{
struct V_62 * V_63 ;
struct V_1 * V_48 , * V_99 ;
unsigned long V_100 , V_101 ;
int V_5 ;
struct V_27 * V_28 ;
enum V_6 V_7 ;
if ( F_43 ( ! V_93 ) )
return;
F_23 ( V_93 , & V_99 , & V_100 ) ;
V_48 = F_19 ( V_99 ) ;
F_4 ( V_48 , & V_5 , & V_7 ) ;
V_28 = & V_35 -> V_27 [ V_5 ] ;
V_101 = F_25 ( V_99 , V_100 , V_28 -> V_14 ) ;
F_64 ( & V_28 -> V_91 ) ;
V_63 = (struct V_62 * ) ( ( unsigned char * ) F_36 ( V_99 )
+ V_101 ) ;
V_63 -> V_33 = V_48 -> V_57 ;
F_37 ( V_63 ) ;
V_48 -> V_57 = V_93 ;
V_48 -> V_18 -- ;
V_7 = F_17 ( V_35 , V_48 ) ;
if ( V_7 == V_22 )
V_28 -> V_97 -= V_28 -> V_66 ;
F_65 ( & V_28 -> V_91 ) ;
if ( V_7 == V_22 )
F_30 ( V_48 ) ;
}
void * F_67 ( struct V_34 * V_35 , void * V_51 )
{
struct V_1 * V_1 ;
unsigned long V_50 , V_55 ;
unsigned int V_5 ;
enum V_6 V_20 ;
struct V_27 * V_28 ;
struct V_74 * V_75 ;
F_5 ( ! V_51 ) ;
F_23 ( V_51 , & V_1 , & V_50 ) ;
F_4 ( F_19 ( V_1 ) , & V_5 , & V_20 ) ;
V_28 = & V_35 -> V_27 [ V_5 ] ;
V_55 = F_25 ( V_1 , V_50 , V_28 -> V_14 ) ;
V_75 = & F_68 ( V_77 ) ;
if ( V_55 + V_28 -> V_14 <= V_47 ) {
V_75 -> V_102 = F_36 ( V_1 ) ;
} else {
struct V_1 * V_58 ;
V_58 = F_20 ( V_1 ) ;
F_5 ( ! V_58 ) ;
F_69 ( V_75 -> V_79 [ 0 ] , F_70 ( V_1 , V_103 ) ) ;
F_69 ( V_75 -> V_79 [ 1 ] , F_70 ( V_58 , V_103 ) ) ;
V_75 -> V_102 = V_75 -> V_78 -> V_104 ;
}
return V_75 -> V_102 + V_55 ;
}
void F_71 ( struct V_34 * V_35 , void * V_51 )
{
struct V_1 * V_1 ;
unsigned long V_50 , V_55 ;
unsigned int V_5 ;
enum V_6 V_20 ;
struct V_27 * V_28 ;
struct V_74 * V_75 ;
F_5 ( ! V_51 ) ;
F_23 ( V_51 , & V_1 , & V_50 ) ;
F_4 ( F_19 ( V_1 ) , & V_5 , & V_20 ) ;
V_28 = & V_35 -> V_27 [ V_5 ] ;
V_55 = F_25 ( V_1 , V_50 , V_28 -> V_14 ) ;
V_75 = & F_72 ( V_77 ) ;
if ( V_55 + V_28 -> V_14 <= V_47 ) {
F_37 ( V_75 -> V_102 ) ;
} else {
F_69 ( V_75 -> V_79 [ 0 ] , F_73 ( 0 ) ) ;
F_69 ( V_75 -> V_79 [ 1 ] , F_73 ( 0 ) ) ;
F_74 ( ( unsigned long ) V_75 -> V_102 ) ;
F_74 ( ( unsigned long ) V_75 -> V_102 + V_47 ) ;
}
F_75 ( V_77 ) ;
}
T_3 F_76 ( struct V_34 * V_35 )
{
int V_40 ;
T_3 V_105 = 0 ;
for ( V_40 = 0 ; V_40 < V_89 ; V_40 ++ )
V_105 += V_35 -> V_27 [ V_40 ] . V_97 ;
return V_105 << V_106 ;
}
