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
V_2 -> V_11 = V_5 ;
F_5 ( V_2 ) ;
}
static struct V_12 *
F_6 ( struct V_1 * V_2 , unsigned long * V_13 )
{
if ( ( * V_13 > V_2 -> V_11 ) ||
( V_2 -> V_10 == NULL ) )
return F_7 ( & V_2 -> V_8 ) ;
else {
struct V_12 * V_14 = F_8 ( V_2 -> V_10 ) ;
struct V_15 * V_16 =
F_9 ( V_2 -> V_10 , struct V_15 , V_17 ) ;
* V_13 = V_16 -> V_18 - 1 ;
return V_14 ;
}
}
static void
F_10 ( struct V_1 * V_2 ,
unsigned long V_13 , struct V_15 * V_19 )
{
if ( V_13 != V_2 -> V_11 )
return;
V_2 -> V_10 = & V_19 -> V_17 ;
}
static void
F_11 ( struct V_1 * V_2 , struct V_15 * free )
{
struct V_15 * V_20 ;
struct V_12 * V_21 ;
if ( ! V_2 -> V_10 )
return;
V_21 = V_2 -> V_10 ;
V_20 = F_9 ( V_21 , struct V_15 , V_17 ) ;
if ( free -> V_18 >= V_20 -> V_18 ) {
struct V_12 * V_17 = F_12 ( & free -> V_17 ) ;
struct V_15 * V_15 = F_9 ( V_17 , struct V_15 , V_17 ) ;
if ( V_17 && V_15 -> V_18 < V_2 -> V_11 )
V_2 -> V_10 = V_17 ;
else
V_2 -> V_10 = NULL ;
}
}
static void
F_13 ( struct V_22 * V_23 , struct V_15 * V_15 ,
struct V_12 * V_24 )
{
struct V_12 * * V_19 , * V_25 = NULL ;
V_19 = ( V_24 ) ? & V_24 : & ( V_23 -> V_12 ) ;
while ( * V_19 ) {
struct V_15 * V_26 = F_9 ( * V_19 , struct V_15 , V_17 ) ;
V_25 = * V_19 ;
if ( V_15 -> V_18 < V_26 -> V_18 )
V_19 = & ( ( * V_19 ) -> V_27 ) ;
else if ( V_15 -> V_18 > V_26 -> V_18 )
V_19 = & ( ( * V_19 ) -> V_28 ) ;
else {
F_14 ( 1 ) ;
return;
}
}
F_15 ( & V_15 -> V_17 , V_25 , V_19 ) ;
F_16 ( & V_15 -> V_17 , V_23 ) ;
}
static unsigned int
F_17 ( unsigned int V_29 , unsigned int V_13 )
{
return ( V_13 + 1 - V_29 ) & ( F_18 ( V_29 ) - 1 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
unsigned long V_29 , unsigned long V_13 ,
struct V_15 * V_19 , bool V_30 )
{
struct V_12 * V_31 , * V_21 = NULL ;
unsigned long V_32 ;
unsigned long V_33 ;
unsigned int V_34 = 0 ;
F_20 ( & V_2 -> V_7 , V_32 ) ;
V_33 = V_13 ;
V_21 = F_6 ( V_2 , & V_13 ) ;
V_31 = V_21 ;
while ( V_21 ) {
struct V_15 * V_16 = F_9 ( V_21 , struct V_15 , V_17 ) ;
if ( V_13 < V_16 -> V_18 )
goto V_35;
else if ( V_13 < V_16 -> V_36 )
goto V_37;
else {
if ( V_30 )
V_34 = F_17 ( V_29 , V_13 ) ;
if ( ( V_16 -> V_36 + V_29 + V_34 ) <= V_13 )
break;
}
V_37:
V_13 = V_16 -> V_18 ? ( V_16 -> V_18 - 1 ) : 0 ;
V_35:
V_31 = V_21 ;
V_21 = F_8 ( V_21 ) ;
}
if ( ! V_21 ) {
if ( V_30 )
V_34 = F_17 ( V_29 , V_13 ) ;
if ( ( V_2 -> V_4 + V_29 + V_34 ) > V_13 ) {
F_21 ( & V_2 -> V_7 , V_32 ) ;
return - V_38 ;
}
}
V_19 -> V_18 = V_13 - ( V_29 + V_34 ) + 1 ;
V_19 -> V_36 = V_19 -> V_18 + V_29 - 1 ;
F_13 ( & V_2 -> V_8 , V_19 , V_31 ) ;
F_10 ( V_2 , V_33 , V_19 ) ;
F_21 ( & V_2 -> V_7 , V_32 ) ;
return 0 ;
}
struct V_15 * F_22 ( void )
{
return F_23 ( V_39 , V_40 ) ;
}
void F_24 ( struct V_15 * V_15 )
{
F_25 ( V_39 , V_15 ) ;
}
int F_26 ( void )
{
F_27 ( & V_41 ) ;
if ( ! V_42 ) {
V_39 = F_28 (
L_1 , sizeof( struct V_15 ) , 0 ,
V_43 , NULL ) ;
if ( ! V_39 ) {
F_29 ( & V_41 ) ;
F_30 ( V_44 L_2 ) ;
return - V_38 ;
}
}
V_42 ++ ;
F_29 ( & V_41 ) ;
return 0 ;
}
void F_31 ( void )
{
F_27 ( & V_41 ) ;
if ( F_14 ( ! V_42 ) ) {
F_29 ( & V_41 ) ;
return;
}
V_42 -- ;
if ( ! V_42 )
F_32 ( V_39 ) ;
F_29 ( & V_41 ) ;
}
struct V_15 *
F_33 ( struct V_1 * V_2 , unsigned long V_29 ,
unsigned long V_13 ,
bool V_30 )
{
struct V_15 * V_45 ;
int V_46 ;
V_45 = F_22 () ;
if ( ! V_45 )
return NULL ;
V_46 = F_19 ( V_2 , V_29 , V_13 ,
V_45 , V_30 ) ;
if ( V_46 ) {
F_24 ( V_45 ) ;
return NULL ;
}
return V_45 ;
}
static struct V_15 *
F_34 ( struct V_1 * V_2 , unsigned long V_47 )
{
struct V_12 * V_17 = V_2 -> V_8 . V_12 ;
F_35 ( & V_2 -> V_7 ) ;
while ( V_17 ) {
struct V_15 * V_15 = F_9 ( V_17 , struct V_15 , V_17 ) ;
if ( ( V_47 >= V_15 -> V_18 ) && ( V_47 <= V_15 -> V_36 ) ) {
return V_15 ;
}
if ( V_47 < V_15 -> V_18 )
V_17 = V_17 -> V_27 ;
else if ( V_47 > V_15 -> V_18 )
V_17 = V_17 -> V_28 ;
}
return NULL ;
}
static void F_36 ( struct V_1 * V_2 , struct V_15 * V_15 )
{
F_35 ( & V_2 -> V_7 ) ;
F_11 ( V_2 , V_15 ) ;
F_37 ( & V_15 -> V_17 , & V_2 -> V_8 ) ;
F_24 ( V_15 ) ;
}
struct V_15 * F_38 ( struct V_1 * V_2 , unsigned long V_47 )
{
unsigned long V_32 ;
struct V_15 * V_15 ;
F_20 ( & V_2 -> V_7 , V_32 ) ;
V_15 = F_34 ( V_2 , V_47 ) ;
F_21 ( & V_2 -> V_7 , V_32 ) ;
return V_15 ;
}
void
F_39 ( struct V_1 * V_2 , struct V_15 * V_15 )
{
unsigned long V_32 ;
F_20 ( & V_2 -> V_7 , V_32 ) ;
F_36 ( V_2 , V_15 ) ;
F_21 ( & V_2 -> V_7 , V_32 ) ;
}
void
F_40 ( struct V_1 * V_2 , unsigned long V_47 )
{
struct V_15 * V_15 = F_38 ( V_2 , V_47 ) ;
if ( V_15 )
F_39 ( V_2 , V_15 ) ;
}
unsigned long
F_41 ( struct V_1 * V_2 , unsigned long V_29 ,
unsigned long V_13 )
{
bool V_48 = false ;
unsigned long V_49 ;
struct V_15 * V_45 ;
V_49 = F_42 ( V_2 , V_29 , V_13 ) ;
if ( V_49 )
return V_49 ;
V_50:
V_45 = F_33 ( V_2 , V_29 , V_13 , true ) ;
if ( ! V_45 ) {
unsigned int V_51 ;
if ( V_48 )
return 0 ;
V_48 = true ;
F_43 () ;
F_44 (cpu)
F_45 ( V_51 , V_2 ) ;
F_46 () ;
goto V_50;
}
return V_45 -> V_18 ;
}
void
F_47 ( struct V_1 * V_2 , unsigned long V_47 , unsigned long V_29 )
{
if ( F_48 ( V_2 , V_47 , V_29 ) )
return;
F_40 ( V_2 , V_47 ) ;
}
void F_49 ( struct V_1 * V_2 )
{
struct V_12 * V_17 ;
unsigned long V_32 ;
F_50 ( V_2 ) ;
F_20 ( & V_2 -> V_7 , V_32 ) ;
V_17 = F_51 ( & V_2 -> V_8 ) ;
while ( V_17 ) {
struct V_15 * V_15 = F_9 ( V_17 , struct V_15 , V_17 ) ;
F_37 ( V_17 , & V_2 -> V_8 ) ;
F_24 ( V_15 ) ;
V_17 = F_51 ( & V_2 -> V_8 ) ;
}
F_21 ( & V_2 -> V_7 , V_32 ) ;
}
static int
F_52 ( struct V_12 * V_17 ,
unsigned long V_18 , unsigned long V_36 )
{
struct V_15 * V_15 = F_9 ( V_17 , struct V_15 , V_17 ) ;
if ( ( V_18 <= V_15 -> V_36 ) && ( V_36 >= V_15 -> V_18 ) )
return 1 ;
return 0 ;
}
static inline struct V_15 *
F_53 ( unsigned long V_18 , unsigned long V_36 )
{
struct V_15 * V_15 ;
V_15 = F_22 () ;
if ( V_15 ) {
V_15 -> V_18 = V_18 ;
V_15 -> V_36 = V_36 ;
}
return V_15 ;
}
static struct V_15 *
F_54 ( struct V_1 * V_2 ,
unsigned long V_18 , unsigned long V_36 )
{
struct V_15 * V_15 ;
V_15 = F_53 ( V_18 , V_36 ) ;
if ( V_15 )
F_13 ( & V_2 -> V_8 , V_15 , NULL ) ;
return V_15 ;
}
static void
F_55 ( struct V_15 * V_15 ,
unsigned long * V_18 , unsigned long * V_36 )
{
if ( * V_18 < V_15 -> V_18 )
V_15 -> V_18 = * V_18 ;
if ( * V_36 > V_15 -> V_36 )
* V_18 = V_15 -> V_36 + 1 ;
}
struct V_15 *
F_56 ( struct V_1 * V_2 ,
unsigned long V_18 , unsigned long V_36 )
{
struct V_12 * V_17 ;
unsigned long V_32 ;
struct V_15 * V_15 ;
unsigned int V_52 = 0 ;
F_20 ( & V_2 -> V_7 , V_32 ) ;
for ( V_17 = F_51 ( & V_2 -> V_8 ) ; V_17 ; V_17 = F_12 ( V_17 ) ) {
if ( F_52 ( V_17 , V_18 , V_36 ) ) {
V_15 = F_9 ( V_17 , struct V_15 , V_17 ) ;
F_55 ( V_15 , & V_18 , & V_36 ) ;
if ( ( V_18 >= V_15 -> V_18 ) &&
( V_36 <= V_15 -> V_36 ) )
goto V_53;
V_52 = 1 ;
} else if ( V_52 )
break;
}
V_15 = F_54 ( V_2 , V_18 , V_36 ) ;
V_53:
F_21 ( & V_2 -> V_7 , V_32 ) ;
return V_15 ;
}
void
F_57 ( struct V_1 * V_54 , struct V_1 * V_55 )
{
unsigned long V_32 ;
struct V_12 * V_17 ;
F_20 ( & V_54 -> V_7 , V_32 ) ;
for ( V_17 = F_51 ( & V_54 -> V_8 ) ; V_17 ; V_17 = F_12 ( V_17 ) ) {
struct V_15 * V_15 = F_9 ( V_17 , struct V_15 , V_17 ) ;
struct V_15 * V_45 ;
V_45 = F_56 ( V_55 , V_15 -> V_18 , V_15 -> V_36 ) ;
if ( ! V_45 )
F_30 ( V_44 L_3 ,
V_15 -> V_18 , V_15 -> V_18 ) ;
}
F_21 ( & V_54 -> V_7 , V_32 ) ;
}
struct V_15 *
F_58 ( struct V_1 * V_2 , struct V_15 * V_15 ,
unsigned long V_18 , unsigned long V_36 )
{
unsigned long V_32 ;
struct V_15 * V_31 = NULL , * V_56 = NULL ;
F_20 ( & V_2 -> V_7 , V_32 ) ;
if ( V_15 -> V_18 < V_18 ) {
V_31 = F_53 ( V_15 -> V_18 , V_18 - 1 ) ;
if ( V_31 == NULL )
goto error;
}
if ( V_15 -> V_36 > V_36 ) {
V_56 = F_53 ( V_36 + 1 , V_15 -> V_36 ) ;
if ( V_56 == NULL )
goto error;
}
F_11 ( V_2 , V_15 ) ;
F_37 ( & V_15 -> V_17 , & V_2 -> V_8 ) ;
if ( V_31 ) {
F_13 ( & V_2 -> V_8 , V_31 , NULL ) ;
V_15 -> V_18 = V_18 ;
}
if ( V_56 ) {
F_13 ( & V_2 -> V_8 , V_56 , NULL ) ;
V_15 -> V_36 = V_36 ;
}
F_21 ( & V_2 -> V_7 , V_32 ) ;
return V_15 ;
error:
F_21 ( & V_2 -> V_7 , V_32 ) ;
if ( V_31 )
F_24 ( V_31 ) ;
return NULL ;
}
static struct V_57 * F_59 ( T_1 V_32 )
{
return F_60 ( sizeof( struct V_57 ) , V_32 ) ;
}
static void F_61 ( struct V_57 * V_58 )
{
F_62 ( V_58 ) ;
}
static void
F_63 ( struct V_57 * V_58 , struct V_1 * V_2 )
{
unsigned long V_32 ;
int V_59 ;
if ( ! V_58 )
return;
F_20 ( & V_2 -> V_7 , V_32 ) ;
for ( V_59 = 0 ; V_59 < V_58 -> V_29 ; ++ V_59 ) {
struct V_15 * V_15 = F_34 ( V_2 , V_58 -> V_60 [ V_59 ] ) ;
F_2 ( ! V_15 ) ;
F_36 ( V_2 , V_15 ) ;
}
F_21 ( & V_2 -> V_7 , V_32 ) ;
V_58 -> V_29 = 0 ;
}
static bool F_64 ( struct V_57 * V_58 )
{
return ( V_58 && V_58 -> V_29 == V_61 ) ;
}
static bool F_65 ( struct V_57 * V_58 )
{
return ( ! V_58 || V_58 -> V_29 == 0 ) ;
}
static unsigned long F_66 ( struct V_57 * V_58 ,
unsigned long V_13 )
{
F_2 ( F_65 ( V_58 ) ) ;
if ( V_58 -> V_60 [ V_58 -> V_29 - 1 ] >= V_13 )
return 0 ;
return V_58 -> V_60 [ -- V_58 -> V_29 ] ;
}
static void F_67 ( struct V_57 * V_58 , unsigned long V_47 )
{
F_2 ( F_64 ( V_58 ) ) ;
V_58 -> V_60 [ V_58 -> V_29 ++ ] = V_47 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_62 * V_63 ;
struct V_64 * V_65 ;
unsigned int V_51 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_66 ; ++ V_59 ) {
V_65 = & V_2 -> V_67 [ V_59 ] ;
F_4 ( & V_65 -> V_68 ) ;
V_65 -> V_69 = 0 ;
V_65 -> V_70 = F_68 ( sizeof( * V_63 ) , F_69 () ) ;
if ( F_14 ( ! V_65 -> V_70 ) )
continue;
F_70 (cpu) {
V_63 = F_71 ( V_65 -> V_70 , V_51 ) ;
F_4 ( & V_63 -> V_68 ) ;
V_63 -> V_71 = F_59 ( V_72 ) ;
V_63 -> V_31 = F_59 ( V_72 ) ;
}
}
}
static bool F_72 ( struct V_1 * V_2 ,
struct V_64 * V_65 ,
unsigned long V_49 )
{
struct V_57 * V_73 = NULL ;
struct V_62 * V_63 ;
bool V_74 = false ;
unsigned long V_32 ;
V_63 = F_73 ( V_65 -> V_70 ) ;
F_20 ( & V_63 -> V_68 , V_32 ) ;
if ( ! F_64 ( V_63 -> V_71 ) ) {
V_74 = true ;
} else if ( ! F_64 ( V_63 -> V_31 ) ) {
F_74 ( V_63 -> V_31 , V_63 -> V_71 ) ;
V_74 = true ;
} else {
struct V_57 * V_75 = F_59 ( V_40 ) ;
if ( V_75 ) {
F_75 ( & V_65 -> V_68 ) ;
if ( V_65 -> V_69 < V_76 ) {
V_65 -> V_77 [ V_65 -> V_69 ++ ] =
V_63 -> V_71 ;
} else {
V_73 = V_63 -> V_71 ;
}
F_76 ( & V_65 -> V_68 ) ;
V_63 -> V_71 = V_75 ;
V_74 = true ;
}
}
if ( V_74 )
F_67 ( V_63 -> V_71 , V_49 ) ;
F_21 ( & V_63 -> V_68 , V_32 ) ;
F_77 ( V_65 -> V_70 ) ;
if ( V_73 ) {
F_63 ( V_73 , V_2 ) ;
F_61 ( V_73 ) ;
}
return V_74 ;
}
static bool F_48 ( struct V_1 * V_2 , unsigned long V_47 ,
unsigned long V_29 )
{
unsigned int V_78 = F_78 ( V_29 ) ;
if ( V_78 >= V_66 )
return false ;
return F_72 ( V_2 , & V_2 -> V_67 [ V_78 ] , V_47 ) ;
}
static unsigned long F_79 ( struct V_64 * V_65 ,
unsigned long V_13 )
{
struct V_62 * V_63 ;
unsigned long V_49 = 0 ;
bool V_79 = false ;
unsigned long V_32 ;
V_63 = F_73 ( V_65 -> V_70 ) ;
F_20 ( & V_63 -> V_68 , V_32 ) ;
if ( ! F_65 ( V_63 -> V_71 ) ) {
V_79 = true ;
} else if ( ! F_65 ( V_63 -> V_31 ) ) {
F_74 ( V_63 -> V_31 , V_63 -> V_71 ) ;
V_79 = true ;
} else {
F_75 ( & V_65 -> V_68 ) ;
if ( V_65 -> V_69 > 0 ) {
F_61 ( V_63 -> V_71 ) ;
V_63 -> V_71 = V_65 -> V_77 [ -- V_65 -> V_69 ] ;
V_79 = true ;
}
F_76 ( & V_65 -> V_68 ) ;
}
if ( V_79 )
V_49 = F_66 ( V_63 -> V_71 , V_13 ) ;
F_21 ( & V_63 -> V_68 , V_32 ) ;
F_77 ( V_65 -> V_70 ) ;
return V_49 ;
}
static unsigned long F_42 ( struct V_1 * V_2 ,
unsigned long V_29 ,
unsigned long V_13 )
{
unsigned int V_78 = F_78 ( V_29 ) ;
if ( V_78 >= V_66 )
return 0 ;
return F_79 ( & V_2 -> V_67 [ V_78 ] , V_13 ) ;
}
static void F_80 ( unsigned int V_51 , struct V_1 * V_2 ,
struct V_64 * V_65 )
{
struct V_62 * V_63 = F_71 ( V_65 -> V_70 , V_51 ) ;
unsigned long V_32 ;
F_20 ( & V_63 -> V_68 , V_32 ) ;
F_63 ( V_63 -> V_71 , V_2 ) ;
F_61 ( V_63 -> V_71 ) ;
F_63 ( V_63 -> V_31 , V_2 ) ;
F_61 ( V_63 -> V_31 ) ;
F_21 ( & V_63 -> V_68 , V_32 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_64 * V_65 ;
unsigned long V_32 ;
unsigned int V_51 ;
int V_59 , V_80 ;
for ( V_59 = 0 ; V_59 < V_66 ; ++ V_59 ) {
V_65 = & V_2 -> V_67 [ V_59 ] ;
F_70 (cpu)
F_80 ( V_51 , V_2 , V_65 ) ;
F_20 ( & V_65 -> V_68 , V_32 ) ;
F_81 ( V_65 -> V_70 ) ;
for ( V_80 = 0 ; V_80 < V_65 -> V_69 ; ++ V_80 ) {
F_63 ( V_65 -> V_77 [ V_80 ] , V_2 ) ;
F_61 ( V_65 -> V_77 [ V_80 ] ) ;
}
F_21 ( & V_65 -> V_68 , V_32 ) ;
}
}
void F_45 ( unsigned int V_51 , struct V_1 * V_2 )
{
struct V_62 * V_63 ;
struct V_64 * V_65 ;
unsigned long V_32 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_66 ; ++ V_59 ) {
V_65 = & V_2 -> V_67 [ V_59 ] ;
V_63 = F_71 ( V_65 -> V_70 , V_51 ) ;
F_20 ( & V_63 -> V_68 , V_32 ) ;
F_63 ( V_63 -> V_71 , V_2 ) ;
F_63 ( V_63 -> V_31 , V_2 ) ;
F_21 ( & V_63 -> V_68 , V_32 ) ;
}
}
