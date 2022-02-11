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
if ( ( * V_13 != V_2 -> V_11 ) ||
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
static unsigned int
F_13 ( unsigned int V_22 , unsigned int V_13 )
{
return ( V_13 + 1 - V_22 ) & ( F_14 ( V_22 ) - 1 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
unsigned long V_22 , unsigned long V_13 ,
struct V_15 * V_19 , bool V_23 )
{
struct V_12 * V_24 , * V_21 = NULL ;
unsigned long V_25 ;
unsigned long V_26 ;
unsigned int V_27 = 0 ;
F_16 ( & V_2 -> V_7 , V_25 ) ;
V_26 = V_13 ;
V_21 = F_6 ( V_2 , & V_13 ) ;
V_24 = V_21 ;
while ( V_21 ) {
struct V_15 * V_16 = F_9 ( V_21 , struct V_15 , V_17 ) ;
if ( V_13 < V_16 -> V_18 )
goto V_28;
else if ( V_13 < V_16 -> V_29 )
goto V_30;
else {
if ( V_23 )
V_27 = F_13 ( V_22 , V_13 ) ;
if ( ( V_16 -> V_29 + V_22 + V_27 ) <= V_13 )
break;
}
V_30:
V_13 = V_16 -> V_18 - 1 ;
V_28:
V_24 = V_21 ;
V_21 = F_8 ( V_21 ) ;
}
if ( ! V_21 ) {
if ( V_23 )
V_27 = F_13 ( V_22 , V_13 ) ;
if ( ( V_2 -> V_4 + V_22 + V_27 ) > V_13 ) {
F_17 ( & V_2 -> V_7 , V_25 ) ;
return - V_31 ;
}
}
V_19 -> V_18 = V_13 - ( V_22 + V_27 ) + 1 ;
V_19 -> V_29 = V_19 -> V_18 + V_22 - 1 ;
{
struct V_12 * * V_32 , * V_33 = NULL ;
if ( V_24 )
V_32 = & V_24 ;
else
V_32 = & V_2 -> V_8 . V_12 ;
while ( * V_32 ) {
struct V_15 * V_34 = F_9 ( * V_32 ,
struct V_15 , V_17 ) ;
V_33 = * V_32 ;
if ( V_19 -> V_18 < V_34 -> V_18 )
V_32 = & ( ( * V_32 ) -> V_35 ) ;
else if ( V_19 -> V_18 > V_34 -> V_18 )
V_32 = & ( ( * V_32 ) -> V_36 ) ;
else
F_18 () ;
}
F_19 ( & V_19 -> V_17 , V_33 , V_32 ) ;
F_20 ( & V_19 -> V_17 , & V_2 -> V_8 ) ;
}
F_10 ( V_2 , V_26 , V_19 ) ;
F_17 ( & V_2 -> V_7 , V_25 ) ;
return 0 ;
}
static void
F_21 ( struct V_37 * V_38 , struct V_15 * V_15 )
{
struct V_12 * * V_19 = & ( V_38 -> V_12 ) , * V_33 = NULL ;
while ( * V_19 ) {
struct V_15 * V_34 = F_9 ( * V_19 , struct V_15 , V_17 ) ;
V_33 = * V_19 ;
if ( V_15 -> V_18 < V_34 -> V_18 )
V_19 = & ( ( * V_19 ) -> V_35 ) ;
else if ( V_15 -> V_18 > V_34 -> V_18 )
V_19 = & ( ( * V_19 ) -> V_36 ) ;
else
F_18 () ;
}
F_19 ( & V_15 -> V_17 , V_33 , V_19 ) ;
F_20 ( & V_15 -> V_17 , V_38 ) ;
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
return - V_31 ;
}
}
V_42 ++ ;
F_29 ( & V_41 ) ;
return 0 ;
}
void F_31 ( void )
{
F_27 ( & V_41 ) ;
if ( F_32 ( ! V_42 ) ) {
F_29 ( & V_41 ) ;
return;
}
V_42 -- ;
if ( ! V_42 )
F_33 ( V_39 ) ;
F_29 ( & V_41 ) ;
}
struct V_15 *
F_34 ( struct V_1 * V_2 , unsigned long V_22 ,
unsigned long V_13 ,
bool V_23 )
{
struct V_15 * V_45 ;
int V_46 ;
V_45 = F_22 () ;
if ( ! V_45 )
return NULL ;
V_46 = F_15 ( V_2 , V_22 , V_13 ,
V_45 , V_23 ) ;
if ( V_46 ) {
F_24 ( V_45 ) ;
return NULL ;
}
return V_45 ;
}
static struct V_15 *
F_35 ( struct V_1 * V_2 , unsigned long V_47 )
{
struct V_12 * V_17 = V_2 -> V_8 . V_12 ;
F_36 ( & V_2 -> V_7 ) ;
while ( V_17 ) {
struct V_15 * V_15 = F_9 ( V_17 , struct V_15 , V_17 ) ;
if ( ( V_47 >= V_15 -> V_18 ) && ( V_47 <= V_15 -> V_29 ) ) {
return V_15 ;
}
if ( V_47 < V_15 -> V_18 )
V_17 = V_17 -> V_35 ;
else if ( V_47 > V_15 -> V_18 )
V_17 = V_17 -> V_36 ;
}
return NULL ;
}
static void F_37 ( struct V_1 * V_2 , struct V_15 * V_15 )
{
F_36 ( & V_2 -> V_7 ) ;
F_11 ( V_2 , V_15 ) ;
F_38 ( & V_15 -> V_17 , & V_2 -> V_8 ) ;
F_24 ( V_15 ) ;
}
struct V_15 * F_39 ( struct V_1 * V_2 , unsigned long V_47 )
{
unsigned long V_25 ;
struct V_15 * V_15 ;
F_16 ( & V_2 -> V_7 , V_25 ) ;
V_15 = F_35 ( V_2 , V_47 ) ;
F_17 ( & V_2 -> V_7 , V_25 ) ;
return V_15 ;
}
void
F_40 ( struct V_1 * V_2 , struct V_15 * V_15 )
{
unsigned long V_25 ;
F_16 ( & V_2 -> V_7 , V_25 ) ;
F_37 ( V_2 , V_15 ) ;
F_17 ( & V_2 -> V_7 , V_25 ) ;
}
void
F_41 ( struct V_1 * V_2 , unsigned long V_47 )
{
struct V_15 * V_15 = F_39 ( V_2 , V_47 ) ;
if ( V_15 )
F_40 ( V_2 , V_15 ) ;
}
unsigned long
F_42 ( struct V_1 * V_2 , unsigned long V_22 ,
unsigned long V_13 )
{
bool V_48 = false ;
unsigned long V_49 ;
struct V_15 * V_45 ;
V_49 = F_43 ( V_2 , V_22 , V_13 ) ;
if ( V_49 )
return V_49 ;
V_50:
V_45 = F_34 ( V_2 , V_22 , V_13 , true ) ;
if ( ! V_45 ) {
unsigned int V_51 ;
if ( V_48 )
return 0 ;
V_48 = true ;
F_44 () ;
F_45 (cpu)
F_46 ( V_51 , V_2 ) ;
F_47 () ;
goto V_50;
}
return V_45 -> V_18 ;
}
void
F_48 ( struct V_1 * V_2 , unsigned long V_47 , unsigned long V_22 )
{
if ( F_49 ( V_2 , V_47 , V_22 ) )
return;
F_41 ( V_2 , V_47 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
struct V_12 * V_17 ;
unsigned long V_25 ;
F_51 ( V_2 ) ;
F_16 ( & V_2 -> V_7 , V_25 ) ;
V_17 = F_52 ( & V_2 -> V_8 ) ;
while ( V_17 ) {
struct V_15 * V_15 = F_9 ( V_17 , struct V_15 , V_17 ) ;
F_38 ( V_17 , & V_2 -> V_8 ) ;
F_24 ( V_15 ) ;
V_17 = F_52 ( & V_2 -> V_8 ) ;
}
F_17 ( & V_2 -> V_7 , V_25 ) ;
}
static int
F_53 ( struct V_12 * V_17 ,
unsigned long V_18 , unsigned long V_29 )
{
struct V_15 * V_15 = F_9 ( V_17 , struct V_15 , V_17 ) ;
if ( ( V_18 <= V_15 -> V_29 ) && ( V_29 >= V_15 -> V_18 ) )
return 1 ;
return 0 ;
}
static inline struct V_15 *
F_54 ( unsigned long V_18 , unsigned long V_29 )
{
struct V_15 * V_15 ;
V_15 = F_22 () ;
if ( V_15 ) {
V_15 -> V_18 = V_18 ;
V_15 -> V_29 = V_29 ;
}
return V_15 ;
}
static struct V_15 *
F_55 ( struct V_1 * V_2 ,
unsigned long V_18 , unsigned long V_29 )
{
struct V_15 * V_15 ;
V_15 = F_54 ( V_18 , V_29 ) ;
if ( V_15 )
F_21 ( & V_2 -> V_8 , V_15 ) ;
return V_15 ;
}
static void
F_56 ( struct V_15 * V_15 ,
unsigned long * V_18 , unsigned long * V_29 )
{
if ( * V_18 < V_15 -> V_18 )
V_15 -> V_18 = * V_18 ;
if ( * V_29 > V_15 -> V_29 )
* V_18 = V_15 -> V_29 + 1 ;
}
struct V_15 *
F_57 ( struct V_1 * V_2 ,
unsigned long V_18 , unsigned long V_29 )
{
struct V_12 * V_17 ;
unsigned long V_25 ;
struct V_15 * V_15 ;
unsigned int V_52 = 0 ;
F_16 ( & V_2 -> V_7 , V_25 ) ;
for ( V_17 = F_52 ( & V_2 -> V_8 ) ; V_17 ; V_17 = F_12 ( V_17 ) ) {
if ( F_53 ( V_17 , V_18 , V_29 ) ) {
V_15 = F_9 ( V_17 , struct V_15 , V_17 ) ;
F_56 ( V_15 , & V_18 , & V_29 ) ;
if ( ( V_18 >= V_15 -> V_18 ) &&
( V_29 <= V_15 -> V_29 ) )
goto V_53;
V_52 = 1 ;
} else if ( V_52 )
break;
}
V_15 = F_55 ( V_2 , V_18 , V_29 ) ;
V_53:
F_17 ( & V_2 -> V_7 , V_25 ) ;
return V_15 ;
}
void
F_58 ( struct V_1 * V_54 , struct V_1 * V_55 )
{
unsigned long V_25 ;
struct V_12 * V_17 ;
F_16 ( & V_54 -> V_7 , V_25 ) ;
for ( V_17 = F_52 ( & V_54 -> V_8 ) ; V_17 ; V_17 = F_12 ( V_17 ) ) {
struct V_15 * V_15 = F_9 ( V_17 , struct V_15 , V_17 ) ;
struct V_15 * V_45 ;
V_45 = F_57 ( V_55 , V_15 -> V_18 , V_15 -> V_29 ) ;
if ( ! V_45 )
F_30 ( V_44 L_3 ,
V_15 -> V_18 , V_15 -> V_18 ) ;
}
F_17 ( & V_54 -> V_7 , V_25 ) ;
}
struct V_15 *
F_59 ( struct V_1 * V_2 , struct V_15 * V_15 ,
unsigned long V_18 , unsigned long V_29 )
{
unsigned long V_25 ;
struct V_15 * V_24 = NULL , * V_56 = NULL ;
F_16 ( & V_2 -> V_7 , V_25 ) ;
if ( V_15 -> V_18 < V_18 ) {
V_24 = F_54 ( V_15 -> V_18 , V_18 - 1 ) ;
if ( V_24 == NULL )
goto error;
}
if ( V_15 -> V_29 > V_29 ) {
V_56 = F_54 ( V_29 + 1 , V_15 -> V_29 ) ;
if ( V_56 == NULL )
goto error;
}
F_11 ( V_2 , V_15 ) ;
F_38 ( & V_15 -> V_17 , & V_2 -> V_8 ) ;
if ( V_24 ) {
F_21 ( & V_2 -> V_8 , V_24 ) ;
V_15 -> V_18 = V_18 ;
}
if ( V_56 ) {
F_21 ( & V_2 -> V_8 , V_56 ) ;
V_15 -> V_29 = V_29 ;
}
F_17 ( & V_2 -> V_7 , V_25 ) ;
return V_15 ;
error:
F_17 ( & V_2 -> V_7 , V_25 ) ;
if ( V_24 )
F_24 ( V_24 ) ;
return NULL ;
}
static struct V_57 * F_60 ( T_1 V_25 )
{
return F_61 ( sizeof( struct V_57 ) , V_25 ) ;
}
static void F_62 ( struct V_57 * V_58 )
{
F_63 ( V_58 ) ;
}
static void
F_64 ( struct V_57 * V_58 , struct V_1 * V_2 )
{
unsigned long V_25 ;
int V_59 ;
if ( ! V_58 )
return;
F_16 ( & V_2 -> V_7 , V_25 ) ;
for ( V_59 = 0 ; V_59 < V_58 -> V_22 ; ++ V_59 ) {
struct V_15 * V_15 = F_35 ( V_2 , V_58 -> V_60 [ V_59 ] ) ;
F_2 ( ! V_15 ) ;
F_37 ( V_2 , V_15 ) ;
}
F_17 ( & V_2 -> V_7 , V_25 ) ;
V_58 -> V_22 = 0 ;
}
static bool F_65 ( struct V_57 * V_58 )
{
return ( V_58 && V_58 -> V_22 == V_61 ) ;
}
static bool F_66 ( struct V_57 * V_58 )
{
return ( ! V_58 || V_58 -> V_22 == 0 ) ;
}
static unsigned long F_67 ( struct V_57 * V_58 ,
unsigned long V_13 )
{
F_2 ( F_66 ( V_58 ) ) ;
if ( V_58 -> V_60 [ V_58 -> V_22 - 1 ] >= V_13 )
return 0 ;
return V_58 -> V_60 [ -- V_58 -> V_22 ] ;
}
static void F_68 ( struct V_57 * V_58 , unsigned long V_47 )
{
F_2 ( F_65 ( V_58 ) ) ;
V_58 -> V_60 [ V_58 -> V_22 ++ ] = V_47 ;
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
V_65 -> V_70 = F_69 ( sizeof( * V_63 ) , F_70 () ) ;
if ( F_32 ( ! V_65 -> V_70 ) )
continue;
F_71 (cpu) {
V_63 = F_72 ( V_65 -> V_70 , V_51 ) ;
F_4 ( & V_63 -> V_68 ) ;
V_63 -> V_71 = F_60 ( V_72 ) ;
V_63 -> V_24 = F_60 ( V_72 ) ;
}
}
}
static bool F_73 ( struct V_1 * V_2 ,
struct V_64 * V_65 ,
unsigned long V_49 )
{
struct V_57 * V_73 = NULL ;
struct V_62 * V_63 ;
bool V_74 = false ;
unsigned long V_25 ;
V_63 = F_74 ( V_65 -> V_70 ) ;
F_16 ( & V_63 -> V_68 , V_25 ) ;
if ( ! F_65 ( V_63 -> V_71 ) ) {
V_74 = true ;
} else if ( ! F_65 ( V_63 -> V_24 ) ) {
F_75 ( V_63 -> V_24 , V_63 -> V_71 ) ;
V_74 = true ;
} else {
struct V_57 * V_75 = F_60 ( V_40 ) ;
if ( V_75 ) {
F_76 ( & V_65 -> V_68 ) ;
if ( V_65 -> V_69 < V_76 ) {
V_65 -> V_77 [ V_65 -> V_69 ++ ] =
V_63 -> V_71 ;
} else {
V_73 = V_63 -> V_71 ;
}
F_77 ( & V_65 -> V_68 ) ;
V_63 -> V_71 = V_75 ;
V_74 = true ;
}
}
if ( V_74 )
F_68 ( V_63 -> V_71 , V_49 ) ;
F_17 ( & V_63 -> V_68 , V_25 ) ;
F_78 ( V_65 -> V_70 ) ;
if ( V_73 ) {
F_64 ( V_73 , V_2 ) ;
F_62 ( V_73 ) ;
}
return V_74 ;
}
static bool F_49 ( struct V_1 * V_2 , unsigned long V_47 ,
unsigned long V_22 )
{
unsigned int V_78 = F_79 ( V_22 ) ;
if ( V_78 >= V_66 )
return false ;
return F_73 ( V_2 , & V_2 -> V_67 [ V_78 ] , V_47 ) ;
}
static unsigned long F_80 ( struct V_64 * V_65 ,
unsigned long V_13 )
{
struct V_62 * V_63 ;
unsigned long V_49 = 0 ;
bool V_79 = false ;
unsigned long V_25 ;
V_63 = F_74 ( V_65 -> V_70 ) ;
F_16 ( & V_63 -> V_68 , V_25 ) ;
if ( ! F_66 ( V_63 -> V_71 ) ) {
V_79 = true ;
} else if ( ! F_66 ( V_63 -> V_24 ) ) {
F_75 ( V_63 -> V_24 , V_63 -> V_71 ) ;
V_79 = true ;
} else {
F_76 ( & V_65 -> V_68 ) ;
if ( V_65 -> V_69 > 0 ) {
F_62 ( V_63 -> V_71 ) ;
V_63 -> V_71 = V_65 -> V_77 [ -- V_65 -> V_69 ] ;
V_79 = true ;
}
F_77 ( & V_65 -> V_68 ) ;
}
if ( V_79 )
V_49 = F_67 ( V_63 -> V_71 , V_13 ) ;
F_17 ( & V_63 -> V_68 , V_25 ) ;
F_78 ( V_65 -> V_70 ) ;
return V_49 ;
}
static unsigned long F_43 ( struct V_1 * V_2 ,
unsigned long V_22 ,
unsigned long V_13 )
{
unsigned int V_78 = F_79 ( V_22 ) ;
if ( V_78 >= V_66 )
return 0 ;
return F_80 ( & V_2 -> V_67 [ V_78 ] , V_13 ) ;
}
static void F_81 ( unsigned int V_51 , struct V_1 * V_2 ,
struct V_64 * V_65 )
{
struct V_62 * V_63 = F_72 ( V_65 -> V_70 , V_51 ) ;
unsigned long V_25 ;
F_16 ( & V_63 -> V_68 , V_25 ) ;
F_64 ( V_63 -> V_71 , V_2 ) ;
F_62 ( V_63 -> V_71 ) ;
F_64 ( V_63 -> V_24 , V_2 ) ;
F_62 ( V_63 -> V_24 ) ;
F_17 ( & V_63 -> V_68 , V_25 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_64 * V_65 ;
unsigned long V_25 ;
unsigned int V_51 ;
int V_59 , V_80 ;
for ( V_59 = 0 ; V_59 < V_66 ; ++ V_59 ) {
V_65 = & V_2 -> V_67 [ V_59 ] ;
F_71 (cpu)
F_81 ( V_51 , V_2 , V_65 ) ;
F_16 ( & V_65 -> V_68 , V_25 ) ;
F_82 ( V_65 -> V_70 ) ;
for ( V_80 = 0 ; V_80 < V_65 -> V_69 ; ++ V_80 ) {
F_64 ( V_65 -> V_77 [ V_80 ] , V_2 ) ;
F_62 ( V_65 -> V_77 [ V_80 ] ) ;
}
F_17 ( & V_65 -> V_68 , V_25 ) ;
}
}
void F_46 ( unsigned int V_51 , struct V_1 * V_2 )
{
struct V_62 * V_63 ;
struct V_64 * V_65 ;
unsigned long V_25 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_66 ; ++ V_59 ) {
V_65 = & V_2 -> V_67 [ V_59 ] ;
V_63 = F_72 ( V_65 -> V_70 , V_51 ) ;
F_16 ( & V_63 -> V_68 , V_25 ) ;
F_64 ( V_63 -> V_71 , V_2 ) ;
F_64 ( V_63 -> V_24 , V_2 ) ;
F_17 ( & V_63 -> V_68 , V_25 ) ;
}
}
