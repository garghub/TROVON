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
* V_13 = V_16 -> V_18 ;
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
return ( V_13 - V_29 ) & ( F_18 ( V_29 ) - 1 ) ;
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
if ( V_13 <= V_16 -> V_18 ) {
goto V_35;
} else if ( V_13 > V_16 -> V_36 ) {
if ( V_30 )
V_34 = F_17 ( V_29 , V_13 ) ;
if ( ( V_16 -> V_36 + V_29 + V_34 ) < V_13 )
break;
}
V_13 = V_16 -> V_18 ;
V_35:
V_31 = V_21 ;
V_21 = F_8 ( V_21 ) ;
}
if ( ! V_21 ) {
if ( V_30 )
V_34 = F_17 ( V_29 , V_13 ) ;
if ( ( V_2 -> V_4 + V_29 + V_34 ) > V_13 ) {
F_21 ( & V_2 -> V_7 , V_32 ) ;
return - V_37 ;
}
}
V_19 -> V_18 = V_13 - ( V_29 + V_34 ) ;
V_19 -> V_36 = V_19 -> V_18 + V_29 - 1 ;
F_13 ( & V_2 -> V_8 , V_19 , V_31 ) ;
F_10 ( V_2 , V_33 , V_19 ) ;
F_21 ( & V_2 -> V_7 , V_32 ) ;
return 0 ;
}
struct V_15 * F_22 ( void )
{
return F_23 ( V_38 , V_39 ) ;
}
void F_24 ( struct V_15 * V_15 )
{
F_25 ( V_38 , V_15 ) ;
}
int F_26 ( void )
{
F_27 ( & V_40 ) ;
if ( ! V_41 ) {
V_38 = F_28 (
L_1 , sizeof( struct V_15 ) , 0 ,
V_42 , NULL ) ;
if ( ! V_38 ) {
F_29 ( & V_40 ) ;
F_30 ( V_43 L_2 ) ;
return - V_37 ;
}
}
V_41 ++ ;
F_29 ( & V_40 ) ;
return 0 ;
}
void F_31 ( void )
{
F_27 ( & V_40 ) ;
if ( F_14 ( ! V_41 ) ) {
F_29 ( & V_40 ) ;
return;
}
V_41 -- ;
if ( ! V_41 )
F_32 ( V_38 ) ;
F_29 ( & V_40 ) ;
}
struct V_15 *
F_33 ( struct V_1 * V_2 , unsigned long V_29 ,
unsigned long V_13 ,
bool V_30 )
{
struct V_15 * V_44 ;
int V_45 ;
V_44 = F_22 () ;
if ( ! V_44 )
return NULL ;
V_45 = F_19 ( V_2 , V_29 , V_13 + 1 ,
V_44 , V_30 ) ;
if ( V_45 ) {
F_24 ( V_44 ) ;
return NULL ;
}
return V_44 ;
}
static struct V_15 *
F_34 ( struct V_1 * V_2 , unsigned long V_46 )
{
struct V_12 * V_17 = V_2 -> V_8 . V_12 ;
F_35 ( & V_2 -> V_7 ) ;
while ( V_17 ) {
struct V_15 * V_15 = F_9 ( V_17 , struct V_15 , V_17 ) ;
if ( ( V_46 >= V_15 -> V_18 ) && ( V_46 <= V_15 -> V_36 ) ) {
return V_15 ;
}
if ( V_46 < V_15 -> V_18 )
V_17 = V_17 -> V_27 ;
else if ( V_46 > V_15 -> V_18 )
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
struct V_15 * F_38 ( struct V_1 * V_2 , unsigned long V_46 )
{
unsigned long V_32 ;
struct V_15 * V_15 ;
F_20 ( & V_2 -> V_7 , V_32 ) ;
V_15 = F_34 ( V_2 , V_46 ) ;
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
F_40 ( struct V_1 * V_2 , unsigned long V_46 )
{
struct V_15 * V_15 = F_38 ( V_2 , V_46 ) ;
if ( V_15 )
F_39 ( V_2 , V_15 ) ;
}
unsigned long
F_41 ( struct V_1 * V_2 , unsigned long V_29 ,
unsigned long V_13 )
{
bool V_47 = false ;
unsigned long V_48 ;
struct V_15 * V_44 ;
V_48 = F_42 ( V_2 , V_29 , V_13 ) ;
if ( V_48 )
return V_48 ;
V_49:
V_44 = F_33 ( V_2 , V_29 , V_13 , true ) ;
if ( ! V_44 ) {
unsigned int V_50 ;
if ( V_47 )
return 0 ;
V_47 = true ;
F_43 (cpu)
F_44 ( V_50 , V_2 ) ;
goto V_49;
}
return V_44 -> V_18 ;
}
void
F_45 ( struct V_1 * V_2 , unsigned long V_46 , unsigned long V_29 )
{
if ( F_46 ( V_2 , V_46 , V_29 ) )
return;
F_40 ( V_2 , V_46 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_12 * V_17 ;
unsigned long V_32 ;
F_48 ( V_2 ) ;
F_20 ( & V_2 -> V_7 , V_32 ) ;
V_17 = F_49 ( & V_2 -> V_8 ) ;
while ( V_17 ) {
struct V_15 * V_15 = F_9 ( V_17 , struct V_15 , V_17 ) ;
F_37 ( V_17 , & V_2 -> V_8 ) ;
F_24 ( V_15 ) ;
V_17 = F_49 ( & V_2 -> V_8 ) ;
}
F_21 ( & V_2 -> V_7 , V_32 ) ;
}
static int
F_50 ( struct V_12 * V_17 ,
unsigned long V_18 , unsigned long V_36 )
{
struct V_15 * V_15 = F_9 ( V_17 , struct V_15 , V_17 ) ;
if ( ( V_18 <= V_15 -> V_36 ) && ( V_36 >= V_15 -> V_18 ) )
return 1 ;
return 0 ;
}
static inline struct V_15 *
F_51 ( unsigned long V_18 , unsigned long V_36 )
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
F_52 ( struct V_1 * V_2 ,
unsigned long V_18 , unsigned long V_36 )
{
struct V_15 * V_15 ;
V_15 = F_51 ( V_18 , V_36 ) ;
if ( V_15 )
F_13 ( & V_2 -> V_8 , V_15 , NULL ) ;
return V_15 ;
}
static void
F_53 ( struct V_15 * V_15 ,
unsigned long * V_18 , unsigned long * V_36 )
{
if ( * V_18 < V_15 -> V_18 )
V_15 -> V_18 = * V_18 ;
if ( * V_36 > V_15 -> V_36 )
* V_18 = V_15 -> V_36 + 1 ;
}
struct V_15 *
F_54 ( struct V_1 * V_2 ,
unsigned long V_18 , unsigned long V_36 )
{
struct V_12 * V_17 ;
unsigned long V_32 ;
struct V_15 * V_15 ;
unsigned int V_51 = 0 ;
F_20 ( & V_2 -> V_7 , V_32 ) ;
for ( V_17 = F_49 ( & V_2 -> V_8 ) ; V_17 ; V_17 = F_12 ( V_17 ) ) {
if ( F_50 ( V_17 , V_18 , V_36 ) ) {
V_15 = F_9 ( V_17 , struct V_15 , V_17 ) ;
F_53 ( V_15 , & V_18 , & V_36 ) ;
if ( ( V_18 >= V_15 -> V_18 ) &&
( V_36 <= V_15 -> V_36 ) )
goto V_52;
V_51 = 1 ;
} else if ( V_51 )
break;
}
V_15 = F_52 ( V_2 , V_18 , V_36 ) ;
V_52:
F_21 ( & V_2 -> V_7 , V_32 ) ;
return V_15 ;
}
void
F_55 ( struct V_1 * V_53 , struct V_1 * V_54 )
{
unsigned long V_32 ;
struct V_12 * V_17 ;
F_20 ( & V_53 -> V_7 , V_32 ) ;
for ( V_17 = F_49 ( & V_53 -> V_8 ) ; V_17 ; V_17 = F_12 ( V_17 ) ) {
struct V_15 * V_15 = F_9 ( V_17 , struct V_15 , V_17 ) ;
struct V_15 * V_44 ;
V_44 = F_54 ( V_54 , V_15 -> V_18 , V_15 -> V_36 ) ;
if ( ! V_44 )
F_30 ( V_43 L_3 ,
V_15 -> V_18 , V_15 -> V_18 ) ;
}
F_21 ( & V_53 -> V_7 , V_32 ) ;
}
struct V_15 *
F_56 ( struct V_1 * V_2 , struct V_15 * V_15 ,
unsigned long V_18 , unsigned long V_36 )
{
unsigned long V_32 ;
struct V_15 * V_31 = NULL , * V_55 = NULL ;
F_20 ( & V_2 -> V_7 , V_32 ) ;
if ( V_15 -> V_18 < V_18 ) {
V_31 = F_51 ( V_15 -> V_18 , V_18 - 1 ) ;
if ( V_31 == NULL )
goto error;
}
if ( V_15 -> V_36 > V_36 ) {
V_55 = F_51 ( V_36 + 1 , V_15 -> V_36 ) ;
if ( V_55 == NULL )
goto error;
}
F_11 ( V_2 , V_15 ) ;
F_37 ( & V_15 -> V_17 , & V_2 -> V_8 ) ;
if ( V_31 ) {
F_13 ( & V_2 -> V_8 , V_31 , NULL ) ;
V_15 -> V_18 = V_18 ;
}
if ( V_55 ) {
F_13 ( & V_2 -> V_8 , V_55 , NULL ) ;
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
static struct V_56 * F_57 ( T_1 V_32 )
{
return F_58 ( sizeof( struct V_56 ) , V_32 ) ;
}
static void F_59 ( struct V_56 * V_57 )
{
F_60 ( V_57 ) ;
}
static void
F_61 ( struct V_56 * V_57 , struct V_1 * V_2 )
{
unsigned long V_32 ;
int V_58 ;
if ( ! V_57 )
return;
F_20 ( & V_2 -> V_7 , V_32 ) ;
for ( V_58 = 0 ; V_58 < V_57 -> V_29 ; ++ V_58 ) {
struct V_15 * V_15 = F_34 ( V_2 , V_57 -> V_59 [ V_58 ] ) ;
F_2 ( ! V_15 ) ;
F_36 ( V_2 , V_15 ) ;
}
F_21 ( & V_2 -> V_7 , V_32 ) ;
V_57 -> V_29 = 0 ;
}
static bool F_62 ( struct V_56 * V_57 )
{
return ( V_57 && V_57 -> V_29 == V_60 ) ;
}
static bool F_63 ( struct V_56 * V_57 )
{
return ( ! V_57 || V_57 -> V_29 == 0 ) ;
}
static unsigned long F_64 ( struct V_56 * V_57 ,
unsigned long V_13 )
{
F_2 ( F_63 ( V_57 ) ) ;
if ( V_57 -> V_59 [ V_57 -> V_29 - 1 ] >= V_13 )
return 0 ;
return V_57 -> V_59 [ -- V_57 -> V_29 ] ;
}
static void F_65 ( struct V_56 * V_57 , unsigned long V_46 )
{
F_2 ( F_62 ( V_57 ) ) ;
V_57 -> V_59 [ V_57 -> V_29 ++ ] = V_46 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_61 * V_62 ;
struct V_63 * V_64 ;
unsigned int V_50 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_65 ; ++ V_58 ) {
V_64 = & V_2 -> V_66 [ V_58 ] ;
F_4 ( & V_64 -> V_67 ) ;
V_64 -> V_68 = 0 ;
V_64 -> V_69 = F_66 ( sizeof( * V_62 ) , F_67 () ) ;
if ( F_14 ( ! V_64 -> V_69 ) )
continue;
F_68 (cpu) {
V_62 = F_69 ( V_64 -> V_69 , V_50 ) ;
F_4 ( & V_62 -> V_67 ) ;
V_62 -> V_70 = F_57 ( V_71 ) ;
V_62 -> V_31 = F_57 ( V_71 ) ;
}
}
}
static bool F_70 ( struct V_1 * V_2 ,
struct V_63 * V_64 ,
unsigned long V_48 )
{
struct V_56 * V_72 = NULL ;
struct V_61 * V_62 ;
bool V_73 = false ;
unsigned long V_32 ;
V_62 = F_71 ( V_64 -> V_69 ) ;
F_20 ( & V_62 -> V_67 , V_32 ) ;
if ( ! F_62 ( V_62 -> V_70 ) ) {
V_73 = true ;
} else if ( ! F_62 ( V_62 -> V_31 ) ) {
F_72 ( V_62 -> V_31 , V_62 -> V_70 ) ;
V_73 = true ;
} else {
struct V_56 * V_74 = F_57 ( V_39 ) ;
if ( V_74 ) {
F_73 ( & V_64 -> V_67 ) ;
if ( V_64 -> V_68 < V_75 ) {
V_64 -> V_76 [ V_64 -> V_68 ++ ] =
V_62 -> V_70 ;
} else {
V_72 = V_62 -> V_70 ;
}
F_74 ( & V_64 -> V_67 ) ;
V_62 -> V_70 = V_74 ;
V_73 = true ;
}
}
if ( V_73 )
F_65 ( V_62 -> V_70 , V_48 ) ;
F_21 ( & V_62 -> V_67 , V_32 ) ;
if ( V_72 ) {
F_61 ( V_72 , V_2 ) ;
F_59 ( V_72 ) ;
}
return V_73 ;
}
static bool F_46 ( struct V_1 * V_2 , unsigned long V_46 ,
unsigned long V_29 )
{
unsigned int V_77 = F_75 ( V_29 ) ;
if ( V_77 >= V_65 )
return false ;
return F_70 ( V_2 , & V_2 -> V_66 [ V_77 ] , V_46 ) ;
}
static unsigned long F_76 ( struct V_63 * V_64 ,
unsigned long V_13 )
{
struct V_61 * V_62 ;
unsigned long V_48 = 0 ;
bool V_78 = false ;
unsigned long V_32 ;
V_62 = F_71 ( V_64 -> V_69 ) ;
F_20 ( & V_62 -> V_67 , V_32 ) ;
if ( ! F_63 ( V_62 -> V_70 ) ) {
V_78 = true ;
} else if ( ! F_63 ( V_62 -> V_31 ) ) {
F_72 ( V_62 -> V_31 , V_62 -> V_70 ) ;
V_78 = true ;
} else {
F_73 ( & V_64 -> V_67 ) ;
if ( V_64 -> V_68 > 0 ) {
F_59 ( V_62 -> V_70 ) ;
V_62 -> V_70 = V_64 -> V_76 [ -- V_64 -> V_68 ] ;
V_78 = true ;
}
F_74 ( & V_64 -> V_67 ) ;
}
if ( V_78 )
V_48 = F_64 ( V_62 -> V_70 , V_13 ) ;
F_21 ( & V_62 -> V_67 , V_32 ) ;
return V_48 ;
}
static unsigned long F_42 ( struct V_1 * V_2 ,
unsigned long V_29 ,
unsigned long V_13 )
{
unsigned int V_77 = F_75 ( V_29 ) ;
if ( V_77 >= V_65 )
return 0 ;
return F_76 ( & V_2 -> V_66 [ V_77 ] , V_13 ) ;
}
static void F_77 ( unsigned int V_50 , struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_61 * V_62 = F_69 ( V_64 -> V_69 , V_50 ) ;
unsigned long V_32 ;
F_20 ( & V_62 -> V_67 , V_32 ) ;
F_61 ( V_62 -> V_70 , V_2 ) ;
F_59 ( V_62 -> V_70 ) ;
F_61 ( V_62 -> V_31 , V_2 ) ;
F_59 ( V_62 -> V_31 ) ;
F_21 ( & V_62 -> V_67 , V_32 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_63 * V_64 ;
unsigned long V_32 ;
unsigned int V_50 ;
int V_58 , V_79 ;
for ( V_58 = 0 ; V_58 < V_65 ; ++ V_58 ) {
V_64 = & V_2 -> V_66 [ V_58 ] ;
F_68 (cpu)
F_77 ( V_50 , V_2 , V_64 ) ;
F_20 ( & V_64 -> V_67 , V_32 ) ;
F_78 ( V_64 -> V_69 ) ;
for ( V_79 = 0 ; V_79 < V_64 -> V_68 ; ++ V_79 ) {
F_61 ( V_64 -> V_76 [ V_79 ] , V_2 ) ;
F_59 ( V_64 -> V_76 [ V_79 ] ) ;
}
F_21 ( & V_64 -> V_67 , V_32 ) ;
}
}
void F_44 ( unsigned int V_50 , struct V_1 * V_2 )
{
struct V_61 * V_62 ;
struct V_63 * V_64 ;
unsigned long V_32 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_65 ; ++ V_58 ) {
V_64 = & V_2 -> V_66 [ V_58 ] ;
V_62 = F_69 ( V_64 -> V_69 , V_50 ) ;
F_20 ( & V_62 -> V_67 , V_32 ) ;
F_61 ( V_62 -> V_70 , V_2 ) ;
F_61 ( V_62 -> V_31 , V_2 ) ;
F_21 ( & V_62 -> V_67 , V_32 ) ;
}
}
