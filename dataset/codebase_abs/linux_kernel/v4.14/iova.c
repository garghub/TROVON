void
F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
unsigned long V_4 , unsigned long V_5 )
{
F_2 ( ( V_3 > V_6 ) || ! F_3 ( V_3 ) ) ;
F_4 ( & V_2 -> V_7 ) ;
V_2 -> V_8 = V_9 ;
V_2 -> V_10 = NULL ;
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_11 = V_5 + 1 ;
V_2 -> V_12 = NULL ;
V_2 -> V_13 = NULL ;
F_5 ( V_2 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_13 )
return;
if ( F_7 ( & V_2 -> V_14 ) )
F_8 ( & V_2 -> V_14 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
V_2 -> V_12 = NULL ;
V_2 -> V_15 = NULL ;
}
int F_11 ( struct V_1 * V_2 ,
T_1 V_12 , T_2 V_15 )
{
int V_16 ;
F_12 ( & V_2 -> V_17 , 0 ) ;
F_12 ( & V_2 -> V_18 , 0 ) ;
V_2 -> V_13 = F_13 ( struct V_19 ) ;
if ( ! V_2 -> V_13 )
return - V_20 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_15 = V_15 ;
F_14 (cpu) {
struct V_19 * V_13 ;
V_13 = F_15 ( V_2 -> V_13 , V_16 ) ;
V_13 -> V_21 = 0 ;
V_13 -> V_22 = 0 ;
F_4 ( & V_13 -> V_23 ) ;
}
F_16 ( & V_2 -> V_14 , V_24 , ( unsigned long ) V_2 ) ;
F_17 ( & V_2 -> V_25 , 0 ) ;
return 0 ;
}
static struct V_26 *
F_18 ( struct V_1 * V_2 , unsigned long * V_27 )
{
if ( ( * V_27 > V_2 -> V_11 ) ||
( V_2 -> V_10 == NULL ) )
return F_19 ( & V_2 -> V_8 ) ;
else {
struct V_26 * V_28 = F_20 ( V_2 -> V_10 ) ;
struct V_29 * V_30 =
F_21 ( V_2 -> V_10 , struct V_29 , V_31 ) ;
* V_27 = V_30 -> V_32 ;
return V_28 ;
}
}
static void
F_22 ( struct V_1 * V_2 ,
unsigned long V_27 , struct V_29 * V_33 )
{
if ( V_27 != V_2 -> V_11 )
return;
V_2 -> V_10 = & V_33 -> V_31 ;
}
static void
F_23 ( struct V_1 * V_2 , struct V_29 * free )
{
struct V_29 * V_34 ;
struct V_26 * V_35 ;
if ( ! V_2 -> V_10 )
return;
V_35 = V_2 -> V_10 ;
V_34 = F_21 ( V_35 , struct V_29 , V_31 ) ;
if ( free -> V_32 >= V_34 -> V_32 ) {
struct V_26 * V_31 = F_24 ( & free -> V_31 ) ;
struct V_29 * V_29 = F_21 ( V_31 , struct V_29 , V_31 ) ;
if ( V_31 && V_29 -> V_32 < V_2 -> V_11 )
V_2 -> V_10 = V_31 ;
else
V_2 -> V_10 = NULL ;
}
}
static void
F_25 ( struct V_36 * V_37 , struct V_29 * V_29 ,
struct V_26 * V_38 )
{
struct V_26 * * V_33 , * V_39 = NULL ;
V_33 = ( V_38 ) ? & V_38 : & ( V_37 -> V_26 ) ;
while ( * V_33 ) {
struct V_29 * V_40 = F_21 ( * V_33 , struct V_29 , V_31 ) ;
V_39 = * V_33 ;
if ( V_29 -> V_32 < V_40 -> V_32 )
V_33 = & ( ( * V_33 ) -> V_41 ) ;
else if ( V_29 -> V_32 > V_40 -> V_32 )
V_33 = & ( ( * V_33 ) -> V_42 ) ;
else {
F_26 ( 1 ) ;
return;
}
}
F_27 ( & V_29 -> V_31 , V_39 , V_33 ) ;
F_28 ( & V_29 -> V_31 , V_37 ) ;
}
static unsigned int
F_29 ( unsigned int V_43 , unsigned int V_27 )
{
return ( V_27 - V_43 ) & ( F_30 ( V_43 ) - 1 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
unsigned long V_43 , unsigned long V_27 ,
struct V_29 * V_33 , bool V_44 )
{
struct V_26 * V_45 , * V_35 = NULL ;
unsigned long V_46 ;
unsigned long V_47 ;
unsigned int V_48 = 0 ;
F_32 ( & V_2 -> V_7 , V_46 ) ;
V_47 = V_27 ;
V_35 = F_18 ( V_2 , & V_27 ) ;
V_45 = V_35 ;
while ( V_35 ) {
struct V_29 * V_30 = F_21 ( V_35 , struct V_29 , V_31 ) ;
if ( V_27 <= V_30 -> V_32 ) {
goto V_49;
} else if ( V_27 > V_30 -> V_50 ) {
if ( V_44 )
V_48 = F_29 ( V_43 , V_27 ) ;
if ( ( V_30 -> V_50 + V_43 + V_48 ) < V_27 )
break;
}
V_27 = V_30 -> V_32 ;
V_49:
V_45 = V_35 ;
V_35 = F_20 ( V_35 ) ;
}
if ( ! V_35 ) {
if ( V_44 )
V_48 = F_29 ( V_43 , V_27 ) ;
if ( ( V_2 -> V_4 + V_43 + V_48 ) > V_27 ) {
F_33 ( & V_2 -> V_7 , V_46 ) ;
return - V_20 ;
}
}
V_33 -> V_32 = V_27 - ( V_43 + V_48 ) ;
V_33 -> V_50 = V_33 -> V_32 + V_43 - 1 ;
F_25 ( & V_2 -> V_8 , V_33 , V_45 ) ;
F_22 ( V_2 , V_47 , V_33 ) ;
F_33 ( & V_2 -> V_7 , V_46 ) ;
return 0 ;
}
struct V_29 * F_34 ( void )
{
return F_35 ( V_51 , V_52 ) ;
}
void F_36 ( struct V_29 * V_29 )
{
F_37 ( V_51 , V_29 ) ;
}
int F_38 ( void )
{
F_39 ( & V_53 ) ;
if ( ! V_54 ) {
V_51 = F_40 (
L_1 , sizeof( struct V_29 ) , 0 ,
V_55 , NULL ) ;
if ( ! V_51 ) {
F_41 ( & V_53 ) ;
F_42 ( V_56 L_2 ) ;
return - V_20 ;
}
}
V_54 ++ ;
F_41 ( & V_53 ) ;
return 0 ;
}
void F_43 ( void )
{
F_39 ( & V_53 ) ;
if ( F_26 ( ! V_54 ) ) {
F_41 ( & V_53 ) ;
return;
}
V_54 -- ;
if ( ! V_54 )
F_44 ( V_51 ) ;
F_41 ( & V_53 ) ;
}
struct V_29 *
F_45 ( struct V_1 * V_2 , unsigned long V_43 ,
unsigned long V_27 ,
bool V_44 )
{
struct V_29 * V_57 ;
int V_58 ;
V_57 = F_34 () ;
if ( ! V_57 )
return NULL ;
V_58 = F_31 ( V_2 , V_43 , V_27 + 1 ,
V_57 , V_44 ) ;
if ( V_58 ) {
F_36 ( V_57 ) ;
return NULL ;
}
return V_57 ;
}
static struct V_29 *
F_46 ( struct V_1 * V_2 , unsigned long V_59 )
{
struct V_26 * V_31 = V_2 -> V_8 . V_26 ;
F_47 ( & V_2 -> V_7 ) ;
while ( V_31 ) {
struct V_29 * V_29 = F_21 ( V_31 , struct V_29 , V_31 ) ;
if ( ( V_59 >= V_29 -> V_32 ) && ( V_59 <= V_29 -> V_50 ) ) {
return V_29 ;
}
if ( V_59 < V_29 -> V_32 )
V_31 = V_31 -> V_41 ;
else if ( V_59 > V_29 -> V_32 )
V_31 = V_31 -> V_42 ;
}
return NULL ;
}
static void F_48 ( struct V_1 * V_2 , struct V_29 * V_29 )
{
F_47 ( & V_2 -> V_7 ) ;
F_23 ( V_2 , V_29 ) ;
F_49 ( & V_29 -> V_31 , & V_2 -> V_8 ) ;
F_36 ( V_29 ) ;
}
struct V_29 * F_50 ( struct V_1 * V_2 , unsigned long V_59 )
{
unsigned long V_46 ;
struct V_29 * V_29 ;
F_32 ( & V_2 -> V_7 , V_46 ) ;
V_29 = F_46 ( V_2 , V_59 ) ;
F_33 ( & V_2 -> V_7 , V_46 ) ;
return V_29 ;
}
void
F_51 ( struct V_1 * V_2 , struct V_29 * V_29 )
{
unsigned long V_46 ;
F_32 ( & V_2 -> V_7 , V_46 ) ;
F_48 ( V_2 , V_29 ) ;
F_33 ( & V_2 -> V_7 , V_46 ) ;
}
void
F_52 ( struct V_1 * V_2 , unsigned long V_59 )
{
struct V_29 * V_29 = F_50 ( V_2 , V_59 ) ;
if ( V_29 )
F_51 ( V_2 , V_29 ) ;
}
unsigned long
F_53 ( struct V_1 * V_2 , unsigned long V_43 ,
unsigned long V_27 )
{
bool V_60 = false ;
unsigned long V_61 ;
struct V_29 * V_57 ;
V_61 = F_54 ( V_2 , V_43 , V_27 ) ;
if ( V_61 )
return V_61 ;
V_62:
V_57 = F_45 ( V_2 , V_43 , V_27 , true ) ;
if ( ! V_57 ) {
unsigned int V_16 ;
if ( V_60 )
return 0 ;
V_60 = true ;
F_55 (cpu)
F_56 ( V_16 , V_2 ) ;
goto V_62;
}
return V_57 -> V_32 ;
}
void
F_57 ( struct V_1 * V_2 , unsigned long V_59 , unsigned long V_43 )
{
if ( F_58 ( V_2 , V_59 , V_43 ) )
return;
F_52 ( V_2 , V_59 ) ;
}
static inline bool F_59 ( struct V_19 * V_13 )
{
F_47 ( & V_13 -> V_23 ) ;
return ( ( ( V_13 -> V_22 + 1 ) % V_63 ) == V_13 -> V_21 ) ;
}
static inline unsigned F_60 ( struct V_19 * V_13 )
{
unsigned V_64 = V_13 -> V_22 ;
F_47 ( & V_13 -> V_23 ) ;
V_13 -> V_22 = ( V_64 + 1 ) % V_63 ;
return V_64 ;
}
static void F_61 ( struct V_1 * V_2 , struct V_19 * V_13 )
{
T_3 V_65 = F_62 ( & V_2 -> V_18 ) ;
unsigned V_64 ;
F_47 ( & V_13 -> V_23 ) ;
F_63 (idx, fq) {
if ( V_13 -> V_66 [ V_64 ] . V_65 >= V_65 )
break;
if ( V_2 -> V_15 )
V_2 -> V_15 ( V_13 -> V_66 [ V_64 ] . V_67 ) ;
F_57 ( V_2 ,
V_13 -> V_66 [ V_64 ] . V_61 ,
V_13 -> V_66 [ V_64 ] . V_68 ) ;
V_13 -> V_21 = ( V_13 -> V_21 + 1 ) % V_63 ;
}
}
static void F_64 ( struct V_1 * V_2 )
{
F_65 ( & V_2 -> V_17 ) ;
V_2 -> V_12 ( V_2 ) ;
F_65 ( & V_2 -> V_18 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_16 ;
if ( ! V_2 -> V_15 )
return;
F_14 (cpu) {
struct V_19 * V_13 = F_15 ( V_2 -> V_13 , V_16 ) ;
int V_64 ;
F_63 (idx, fq)
V_2 -> V_15 ( V_13 -> V_66 [ V_64 ] . V_67 ) ;
}
}
static void V_24 ( unsigned long V_67 )
{
struct V_1 * V_2 = (struct V_1 * ) V_67 ;
int V_16 ;
F_17 ( & V_2 -> V_25 , 0 ) ;
F_64 ( V_2 ) ;
F_14 (cpu) {
unsigned long V_46 ;
struct V_19 * V_13 ;
V_13 = F_15 ( V_2 -> V_13 , V_16 ) ;
F_32 ( & V_13 -> V_23 , V_46 ) ;
F_61 ( V_2 , V_13 ) ;
F_33 ( & V_13 -> V_23 , V_46 ) ;
}
}
void F_66 ( struct V_1 * V_2 ,
unsigned long V_59 , unsigned long V_68 ,
unsigned long V_67 )
{
struct V_19 * V_13 = F_67 ( V_2 -> V_13 ) ;
unsigned long V_46 ;
unsigned V_64 ;
F_32 ( & V_13 -> V_23 , V_46 ) ;
F_61 ( V_2 , V_13 ) ;
if ( F_59 ( V_13 ) ) {
F_64 ( V_2 ) ;
F_61 ( V_2 , V_13 ) ;
}
V_64 = F_60 ( V_13 ) ;
V_13 -> V_66 [ V_64 ] . V_61 = V_59 ;
V_13 -> V_66 [ V_64 ] . V_68 = V_68 ;
V_13 -> V_66 [ V_64 ] . V_67 = V_67 ;
V_13 -> V_66 [ V_64 ] . V_65 = F_62 ( & V_2 -> V_17 ) ;
F_33 ( & V_13 -> V_23 , V_46 ) ;
if ( F_68 ( & V_2 -> V_25 , 0 , 1 ) == 0 )
F_69 ( & V_2 -> V_14 ,
V_69 + F_70 ( V_70 ) ) ;
F_71 ( V_2 -> V_13 ) ;
}
void F_72 ( struct V_1 * V_2 )
{
struct V_26 * V_31 ;
unsigned long V_46 ;
F_6 ( V_2 ) ;
F_73 ( V_2 ) ;
F_32 ( & V_2 -> V_7 , V_46 ) ;
V_31 = F_74 ( & V_2 -> V_8 ) ;
while ( V_31 ) {
struct V_29 * V_29 = F_21 ( V_31 , struct V_29 , V_31 ) ;
F_49 ( V_31 , & V_2 -> V_8 ) ;
F_36 ( V_29 ) ;
V_31 = F_74 ( & V_2 -> V_8 ) ;
}
F_33 ( & V_2 -> V_7 , V_46 ) ;
}
static int
F_75 ( struct V_26 * V_31 ,
unsigned long V_32 , unsigned long V_50 )
{
struct V_29 * V_29 = F_21 ( V_31 , struct V_29 , V_31 ) ;
if ( ( V_32 <= V_29 -> V_50 ) && ( V_50 >= V_29 -> V_32 ) )
return 1 ;
return 0 ;
}
static inline struct V_29 *
F_76 ( unsigned long V_32 , unsigned long V_50 )
{
struct V_29 * V_29 ;
V_29 = F_34 () ;
if ( V_29 ) {
V_29 -> V_32 = V_32 ;
V_29 -> V_50 = V_50 ;
}
return V_29 ;
}
static struct V_29 *
F_77 ( struct V_1 * V_2 ,
unsigned long V_32 , unsigned long V_50 )
{
struct V_29 * V_29 ;
V_29 = F_76 ( V_32 , V_50 ) ;
if ( V_29 )
F_25 ( & V_2 -> V_8 , V_29 , NULL ) ;
return V_29 ;
}
static void
F_78 ( struct V_29 * V_29 ,
unsigned long * V_32 , unsigned long * V_50 )
{
if ( * V_32 < V_29 -> V_32 )
V_29 -> V_32 = * V_32 ;
if ( * V_50 > V_29 -> V_50 )
* V_32 = V_29 -> V_50 + 1 ;
}
struct V_29 *
F_79 ( struct V_1 * V_2 ,
unsigned long V_32 , unsigned long V_50 )
{
struct V_26 * V_31 ;
unsigned long V_46 ;
struct V_29 * V_29 ;
unsigned int V_71 = 0 ;
F_32 ( & V_2 -> V_7 , V_46 ) ;
for ( V_31 = F_74 ( & V_2 -> V_8 ) ; V_31 ; V_31 = F_24 ( V_31 ) ) {
if ( F_75 ( V_31 , V_32 , V_50 ) ) {
V_29 = F_21 ( V_31 , struct V_29 , V_31 ) ;
F_78 ( V_29 , & V_32 , & V_50 ) ;
if ( ( V_32 >= V_29 -> V_32 ) &&
( V_50 <= V_29 -> V_50 ) )
goto V_72;
V_71 = 1 ;
} else if ( V_71 )
break;
}
V_29 = F_77 ( V_2 , V_32 , V_50 ) ;
V_72:
F_33 ( & V_2 -> V_7 , V_46 ) ;
return V_29 ;
}
void
F_80 ( struct V_1 * V_73 , struct V_1 * V_74 )
{
unsigned long V_46 ;
struct V_26 * V_31 ;
F_32 ( & V_73 -> V_7 , V_46 ) ;
for ( V_31 = F_74 ( & V_73 -> V_8 ) ; V_31 ; V_31 = F_24 ( V_31 ) ) {
struct V_29 * V_29 = F_21 ( V_31 , struct V_29 , V_31 ) ;
struct V_29 * V_57 ;
V_57 = F_79 ( V_74 , V_29 -> V_32 , V_29 -> V_50 ) ;
if ( ! V_57 )
F_42 ( V_56 L_3 ,
V_29 -> V_32 , V_29 -> V_32 ) ;
}
F_33 ( & V_73 -> V_7 , V_46 ) ;
}
struct V_29 *
F_81 ( struct V_1 * V_2 , struct V_29 * V_29 ,
unsigned long V_32 , unsigned long V_50 )
{
unsigned long V_46 ;
struct V_29 * V_45 = NULL , * V_75 = NULL ;
F_32 ( & V_2 -> V_7 , V_46 ) ;
if ( V_29 -> V_32 < V_32 ) {
V_45 = F_76 ( V_29 -> V_32 , V_32 - 1 ) ;
if ( V_45 == NULL )
goto error;
}
if ( V_29 -> V_50 > V_50 ) {
V_75 = F_76 ( V_50 + 1 , V_29 -> V_50 ) ;
if ( V_75 == NULL )
goto error;
}
F_23 ( V_2 , V_29 ) ;
F_49 ( & V_29 -> V_31 , & V_2 -> V_8 ) ;
if ( V_45 ) {
F_25 ( & V_2 -> V_8 , V_45 , NULL ) ;
V_29 -> V_32 = V_32 ;
}
if ( V_75 ) {
F_25 ( & V_2 -> V_8 , V_75 , NULL ) ;
V_29 -> V_50 = V_50 ;
}
F_33 ( & V_2 -> V_7 , V_46 ) ;
return V_29 ;
error:
F_33 ( & V_2 -> V_7 , V_46 ) ;
if ( V_45 )
F_36 ( V_45 ) ;
return NULL ;
}
static struct V_76 * F_82 ( T_4 V_46 )
{
return F_83 ( sizeof( struct V_76 ) , V_46 ) ;
}
static void F_84 ( struct V_76 * V_77 )
{
F_85 ( V_77 ) ;
}
static void
F_86 ( struct V_76 * V_77 , struct V_1 * V_2 )
{
unsigned long V_46 ;
int V_78 ;
if ( ! V_77 )
return;
F_32 ( & V_2 -> V_7 , V_46 ) ;
for ( V_78 = 0 ; V_78 < V_77 -> V_43 ; ++ V_78 ) {
struct V_29 * V_29 = F_46 ( V_2 , V_77 -> V_79 [ V_78 ] ) ;
F_2 ( ! V_29 ) ;
F_48 ( V_2 , V_29 ) ;
}
F_33 ( & V_2 -> V_7 , V_46 ) ;
V_77 -> V_43 = 0 ;
}
static bool F_87 ( struct V_76 * V_77 )
{
return ( V_77 && V_77 -> V_43 == V_80 ) ;
}
static bool F_88 ( struct V_76 * V_77 )
{
return ( ! V_77 || V_77 -> V_43 == 0 ) ;
}
static unsigned long F_89 ( struct V_76 * V_77 ,
unsigned long V_27 )
{
F_2 ( F_88 ( V_77 ) ) ;
if ( V_77 -> V_79 [ V_77 -> V_43 - 1 ] >= V_27 )
return 0 ;
return V_77 -> V_79 [ -- V_77 -> V_43 ] ;
}
static void F_90 ( struct V_76 * V_77 , unsigned long V_59 )
{
F_2 ( F_87 ( V_77 ) ) ;
V_77 -> V_79 [ V_77 -> V_43 ++ ] = V_59 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_81 * V_82 ;
struct V_83 * V_84 ;
unsigned int V_16 ;
int V_78 ;
for ( V_78 = 0 ; V_78 < V_85 ; ++ V_78 ) {
V_84 = & V_2 -> V_86 [ V_78 ] ;
F_4 ( & V_84 -> V_23 ) ;
V_84 -> V_87 = 0 ;
V_84 -> V_88 = F_91 ( sizeof( * V_82 ) , F_92 () ) ;
if ( F_26 ( ! V_84 -> V_88 ) )
continue;
F_14 (cpu) {
V_82 = F_15 ( V_84 -> V_88 , V_16 ) ;
F_4 ( & V_82 -> V_23 ) ;
V_82 -> V_89 = F_82 ( V_90 ) ;
V_82 -> V_45 = F_82 ( V_90 ) ;
}
}
}
static bool F_93 ( struct V_1 * V_2 ,
struct V_83 * V_84 ,
unsigned long V_61 )
{
struct V_76 * V_91 = NULL ;
struct V_81 * V_82 ;
bool V_92 = false ;
unsigned long V_46 ;
V_82 = F_94 ( V_84 -> V_88 ) ;
F_32 ( & V_82 -> V_23 , V_46 ) ;
if ( ! F_87 ( V_82 -> V_89 ) ) {
V_92 = true ;
} else if ( ! F_87 ( V_82 -> V_45 ) ) {
F_95 ( V_82 -> V_45 , V_82 -> V_89 ) ;
V_92 = true ;
} else {
struct V_76 * V_93 = F_82 ( V_52 ) ;
if ( V_93 ) {
F_96 ( & V_84 -> V_23 ) ;
if ( V_84 -> V_87 < V_94 ) {
V_84 -> V_95 [ V_84 -> V_87 ++ ] =
V_82 -> V_89 ;
} else {
V_91 = V_82 -> V_89 ;
}
F_97 ( & V_84 -> V_23 ) ;
V_82 -> V_89 = V_93 ;
V_92 = true ;
}
}
if ( V_92 )
F_90 ( V_82 -> V_89 , V_61 ) ;
F_33 ( & V_82 -> V_23 , V_46 ) ;
if ( V_91 ) {
F_86 ( V_91 , V_2 ) ;
F_84 ( V_91 ) ;
}
return V_92 ;
}
static bool F_58 ( struct V_1 * V_2 , unsigned long V_59 ,
unsigned long V_43 )
{
unsigned int V_96 = F_98 ( V_43 ) ;
if ( V_96 >= V_85 )
return false ;
return F_93 ( V_2 , & V_2 -> V_86 [ V_96 ] , V_59 ) ;
}
static unsigned long F_99 ( struct V_83 * V_84 ,
unsigned long V_27 )
{
struct V_81 * V_82 ;
unsigned long V_61 = 0 ;
bool V_97 = false ;
unsigned long V_46 ;
V_82 = F_94 ( V_84 -> V_88 ) ;
F_32 ( & V_82 -> V_23 , V_46 ) ;
if ( ! F_88 ( V_82 -> V_89 ) ) {
V_97 = true ;
} else if ( ! F_88 ( V_82 -> V_45 ) ) {
F_95 ( V_82 -> V_45 , V_82 -> V_89 ) ;
V_97 = true ;
} else {
F_96 ( & V_84 -> V_23 ) ;
if ( V_84 -> V_87 > 0 ) {
F_84 ( V_82 -> V_89 ) ;
V_82 -> V_89 = V_84 -> V_95 [ -- V_84 -> V_87 ] ;
V_97 = true ;
}
F_97 ( & V_84 -> V_23 ) ;
}
if ( V_97 )
V_61 = F_89 ( V_82 -> V_89 , V_27 ) ;
F_33 ( & V_82 -> V_23 , V_46 ) ;
return V_61 ;
}
static unsigned long F_54 ( struct V_1 * V_2 ,
unsigned long V_43 ,
unsigned long V_27 )
{
unsigned int V_96 = F_98 ( V_43 ) ;
if ( V_96 >= V_85 )
return 0 ;
return F_99 ( & V_2 -> V_86 [ V_96 ] , V_27 ) ;
}
static void F_100 ( unsigned int V_16 , struct V_1 * V_2 ,
struct V_83 * V_84 )
{
struct V_81 * V_82 = F_15 ( V_84 -> V_88 , V_16 ) ;
unsigned long V_46 ;
F_32 ( & V_82 -> V_23 , V_46 ) ;
F_86 ( V_82 -> V_89 , V_2 ) ;
F_84 ( V_82 -> V_89 ) ;
F_86 ( V_82 -> V_45 , V_2 ) ;
F_84 ( V_82 -> V_45 ) ;
F_33 ( & V_82 -> V_23 , V_46 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_83 * V_84 ;
unsigned long V_46 ;
unsigned int V_16 ;
int V_78 , V_98 ;
for ( V_78 = 0 ; V_78 < V_85 ; ++ V_78 ) {
V_84 = & V_2 -> V_86 [ V_78 ] ;
F_14 (cpu)
F_100 ( V_16 , V_2 , V_84 ) ;
F_32 ( & V_84 -> V_23 , V_46 ) ;
F_10 ( V_84 -> V_88 ) ;
for ( V_98 = 0 ; V_98 < V_84 -> V_87 ; ++ V_98 ) {
F_86 ( V_84 -> V_95 [ V_98 ] , V_2 ) ;
F_84 ( V_84 -> V_95 [ V_98 ] ) ;
}
F_33 ( & V_84 -> V_23 , V_46 ) ;
}
}
void F_56 ( unsigned int V_16 , struct V_1 * V_2 )
{
struct V_81 * V_82 ;
struct V_83 * V_84 ;
unsigned long V_46 ;
int V_78 ;
for ( V_78 = 0 ; V_78 < V_85 ; ++ V_78 ) {
V_84 = & V_2 -> V_86 [ V_78 ] ;
V_82 = F_15 ( V_84 -> V_88 , V_16 ) ;
F_32 ( & V_82 -> V_23 , V_46 ) ;
F_86 ( V_82 -> V_89 , V_2 ) ;
F_86 ( V_82 -> V_45 , V_2 ) ;
F_33 ( & V_82 -> V_23 , V_46 ) ;
}
}
