static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = F_2 ( V_2 -> V_4 , sizeof( * V_2 -> V_3 ) ) ;
V_2 -> V_5 = F_2 ( V_2 -> V_4 ,
sizeof( * V_2 -> V_5 ) ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
F_4 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
static void F_5 ( struct V_1 * V_2 )
{
int V_6 ;
int V_7 ;
struct V_8 * V_8 ;
int V_9 ;
struct V_10 * V_11 = V_2 -> V_11 ;
F_6 ( ! ( V_2 -> V_12 & V_13 ) ) ;
V_6 = ( ( V_2 -> V_12 & V_14 ) != 0 ) ;
V_7 = ( ( V_2 -> V_12 & V_15 ) != 0 ) ;
if ( V_11 )
V_11 -> V_16 -> V_17 ( V_11 ) ;
for ( V_9 = 0 ; V_9 < V_2 -> V_4 ; ++ V_9 ) {
V_8 = V_2 -> V_3 [ V_9 ] ;
if ( V_8 == NULL )
continue;
if ( V_8 == V_2 -> V_18 ) {
F_6 ( V_6 ) ;
continue;
}
if ( V_6 && V_7 && ! F_7 ( V_8 ) )
F_8 ( V_8 ) ;
V_2 -> V_3 [ V_9 ] = NULL ;
F_9 ( V_2 -> V_19 -> V_20 , V_21 ) ;
F_10 ( V_8 ) ;
}
V_2 -> V_22 = V_23 ;
V_2 -> V_24 = V_2 -> V_4 ;
V_2 -> V_25 = - 1 ;
}
static struct V_8 * F_11 ( struct V_1 * V_2 , int V_26 )
{
struct V_8 * V_27 ;
struct V_28 V_29 ;
struct V_30 * V_20 = V_2 -> V_19 -> V_20 ;
int V_31 ;
while ( NULL == ( V_27 = V_2 -> V_3 [ V_26 ] ) ) {
F_12 ( & V_29 ) ;
V_31 = F_13 ( & V_29 , V_2 -> V_12 , V_2 -> V_32 , 1 ,
& V_2 -> V_5 [ V_26 ] ) ;
if ( V_31 != 0 )
return NULL ;
V_27 = F_14 ( & V_29 , struct V_8 , V_33 ) ;
V_31 = F_15 ( V_20 , V_27 , false , false ) ;
if ( F_16 ( V_31 != 0 ) )
goto V_34;
if ( F_17 ( V_27 ) )
V_2 -> V_3 [ -- V_2 -> V_24 ] = V_27 ;
else
V_2 -> V_3 [ ++ V_2 -> V_25 ] = V_27 ;
}
return V_27 ;
V_34:
F_10 ( V_27 ) ;
return NULL ;
}
struct V_8 * F_18 ( struct V_1 * V_2 , int V_26 )
{
int V_31 ;
if ( F_16 ( V_2 -> V_12 & V_35 ) ) {
V_31 = F_19 ( V_2 ) ;
if ( F_16 ( V_31 != 0 ) )
return NULL ;
}
return F_11 ( V_2 , V_26 ) ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_8 * V_8 ;
unsigned long V_9 ;
struct V_10 * V_11 ;
int V_31 ;
if ( V_2 -> V_22 != V_23 )
return 0 ;
if ( F_16 ( V_2 -> V_12 & V_35 ) ) {
V_31 = F_19 ( V_2 ) ;
if ( F_16 ( V_31 != 0 ) )
return V_31 ;
}
V_11 = V_2 -> V_11 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_4 ; ++ V_9 ) {
V_8 = F_11 ( V_2 , V_9 ) ;
if ( ! V_8 )
return - V_36 ;
}
V_11 -> V_16 -> V_37 ( V_11 , V_2 -> V_4 , V_2 -> V_3 ,
V_2 -> V_18 , V_2 -> V_5 ) ;
V_2 -> V_22 = V_38 ;
return 0 ;
}
static inline int F_21 ( struct V_8 * V_27 ,
enum V_39 V_40 ,
enum V_39 V_41 )
{
int V_31 = 0 ;
if ( F_17 ( V_27 ) )
return 0 ;
if ( V_40 != V_42 ) {
V_31 = F_22 ( V_27 , 1 ) ;
if ( V_31 )
return V_31 ;
}
if ( V_41 == V_43 )
V_31 = F_23 ( ( unsigned long ) F_24 ( V_27 ) , 1 ) ;
else if ( V_41 == V_44 )
V_31 = F_25 ( V_27 , 1 ) ;
return V_31 ;
}
static inline int F_21 ( struct V_8 * V_27 ,
enum V_39 V_40 ,
enum V_39 V_41 )
{
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
enum V_39 V_45 )
{
int V_9 , V_46 ;
struct V_8 * V_47 ;
int V_31 ;
if ( V_2 -> V_32 == V_45 )
return 0 ;
if ( V_2 -> V_22 == V_23 ) {
V_2 -> V_32 = V_45 ;
return 0 ;
}
if ( V_2 -> V_32 == V_42 )
F_27 ( V_2 -> V_3 , V_2 -> V_4 ) ;
for ( V_9 = 0 ; V_9 < V_2 -> V_4 ; ++ V_9 ) {
V_47 = V_2 -> V_3 [ V_9 ] ;
if ( F_28 ( V_47 != NULL ) ) {
V_31 = F_21 ( V_47 ,
V_2 -> V_32 ,
V_45 ) ;
if ( F_16 ( V_31 != 0 ) )
goto V_34;
}
}
V_2 -> V_32 = V_45 ;
return 0 ;
V_34:
for ( V_46 = 0 ; V_46 < V_9 ; ++ V_46 ) {
V_47 = V_2 -> V_3 [ V_46 ] ;
if ( F_28 ( V_47 != NULL ) ) {
( void ) F_21 ( V_47 , V_45 ,
V_2 -> V_32 ) ;
}
}
return V_31 ;
}
int F_29 ( struct V_1 * V_2 , T_1 V_48 )
{
enum V_39 V_22 ;
if ( V_48 & V_49 )
V_22 = V_43 ;
else if ( V_48 & V_50 )
V_22 = V_44 ;
else
V_22 = V_42 ;
return F_26 ( V_2 , V_22 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
int V_9 ;
unsigned V_51 = 0 ;
struct V_28 V_29 ;
struct V_8 * V_47 ;
struct V_10 * V_11 = V_2 -> V_11 ;
F_12 ( & V_29 ) ;
if ( V_11 )
V_11 -> V_16 -> V_17 ( V_11 ) ;
for ( V_9 = 0 ; V_9 < V_2 -> V_4 ; ++ V_9 ) {
V_47 = V_2 -> V_3 [ V_9 ] ;
V_2 -> V_3 [ V_9 ] = NULL ;
if ( V_47 ) {
if ( F_31 ( V_47 ) != 1 )
F_32 (KERN_ERR TTM_PFX
L_1
L_2 ) ;
F_33 ( V_2 -> V_19 -> V_20 ,
V_47 ) ;
F_34 ( & V_47 -> V_33 , & V_29 ) ;
V_51 ++ ;
}
}
F_35 ( & V_29 , V_51 , V_2 -> V_12 , V_2 -> V_32 ,
V_2 -> V_5 ) ;
V_2 -> V_22 = V_23 ;
V_2 -> V_24 = V_2 -> V_4 ;
V_2 -> V_25 = - 1 ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
if ( F_16 ( V_2 == NULL ) )
return;
V_11 = V_2 -> V_11 ;
if ( F_28 ( V_11 != NULL ) ) {
V_11 -> V_16 -> V_52 ( V_11 ) ;
V_2 -> V_11 = NULL ;
}
if ( F_28 ( V_2 -> V_3 != NULL ) ) {
if ( V_2 -> V_12 & V_13 )
F_5 ( V_2 ) ;
else
F_30 ( V_2 ) ;
F_3 ( V_2 ) ;
}
if ( ! ( V_2 -> V_12 & V_53 ) &&
V_2 -> V_54 )
F_37 ( V_2 -> V_54 ) ;
F_38 ( V_2 ) ;
}
int F_39 ( struct V_1 * V_2 ,
struct V_55 * V_56 ,
unsigned long V_57 , unsigned long V_4 )
{
struct V_58 * V_59 = V_56 -> V_59 ;
int V_31 ;
int V_6 = ( V_2 -> V_12 & V_14 ) != 0 ;
struct V_30 * V_20 = V_2 -> V_19 -> V_20 ;
F_6 ( V_4 != V_2 -> V_4 ) ;
F_6 ( ( V_2 -> V_12 & V_13 ) == 0 ) ;
V_31 = F_40 ( V_20 , V_4 * V_21 ,
false , false ) ;
if ( F_16 ( V_31 != 0 ) )
return V_31 ;
F_41 ( & V_59 -> V_60 ) ;
V_31 = F_42 ( V_56 , V_59 , V_57 , V_4 ,
V_6 , 0 , V_2 -> V_3 , NULL ) ;
F_43 ( & V_59 -> V_60 ) ;
if ( V_31 != V_4 && V_6 ) {
F_5 ( V_2 ) ;
F_9 ( V_20 , V_4 * V_21 ) ;
return - V_36 ;
}
V_2 -> V_56 = V_56 ;
V_2 -> V_57 = V_57 ;
V_2 -> V_22 = V_38 ;
return 0 ;
}
struct V_1 * F_44 ( struct V_61 * V_62 , unsigned long V_63 ,
T_1 V_12 , struct V_8 * V_18 )
{
struct V_64 * V_65 = V_62 -> V_66 ;
struct V_1 * V_2 ;
if ( ! V_65 )
return NULL ;
V_2 = F_45 ( sizeof( * V_2 ) , V_67 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_19 = V_62 -> V_19 ;
V_2 -> V_4 = ( V_63 + V_21 - 1 ) >> V_68 ;
V_2 -> V_24 = V_2 -> V_4 ;
V_2 -> V_25 = - 1 ;
V_2 -> V_32 = V_42 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_18 = V_18 ;
F_1 ( V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_36 ( V_2 ) ;
F_32 (KERN_ERR TTM_PFX L_3 ) ;
return NULL ;
}
V_2 -> V_11 = V_65 -> V_69 ( V_62 ) ;
if ( ! V_2 -> V_11 ) {
F_36 ( V_2 ) ;
F_32 (KERN_ERR TTM_PFX L_4 ) ;
return NULL ;
}
V_2 -> V_22 = V_23 ;
return V_2 ;
}
void F_46 ( struct V_1 * V_2 )
{
int V_31 ;
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_2 -> V_22 == V_70 ) {
V_31 = V_11 -> V_16 -> V_71 ( V_11 ) ;
F_6 ( V_31 ) ;
V_2 -> V_22 = V_38 ;
}
}
int F_47 ( struct V_1 * V_2 , struct V_72 * V_73 )
{
int V_31 = 0 ;
struct V_10 * V_11 ;
if ( ! V_2 )
return - V_74 ;
if ( V_2 -> V_22 == V_70 )
return 0 ;
V_11 = V_2 -> V_11 ;
V_31 = F_20 ( V_2 ) ;
if ( V_31 )
return V_31 ;
V_31 = V_11 -> V_16 -> V_75 ( V_11 , V_73 ) ;
if ( F_16 ( V_31 != 0 ) )
return V_31 ;
V_2 -> V_22 = V_70 ;
if ( V_2 -> V_12 & V_13 )
V_2 -> V_12 |= V_15 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_76 * V_77 ;
struct V_78 * V_54 ;
struct V_8 * V_79 ;
struct V_8 * V_80 ;
void * V_81 ;
void * V_82 ;
int V_9 ;
int V_31 = - V_36 ;
if ( V_2 -> V_12 & V_13 ) {
V_31 = F_39 ( V_2 , V_2 -> V_56 , V_2 -> V_57 ,
V_2 -> V_4 ) ;
if ( F_16 ( V_31 != 0 ) )
return V_31 ;
V_2 -> V_12 &= ~ V_35 ;
return 0 ;
}
V_54 = V_2 -> V_54 ;
F_6 ( V_54 == NULL ) ;
V_77 = V_54 -> V_83 . V_84 -> V_85 -> V_86 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_4 ; ++ V_9 ) {
V_79 = F_48 ( V_77 , V_9 ) ;
if ( F_49 ( V_79 ) ) {
V_31 = F_50 ( V_79 ) ;
goto V_34;
}
V_80 = F_11 ( V_2 , V_9 ) ;
if ( F_16 ( V_80 == NULL ) )
goto V_34;
F_51 () ;
V_81 = F_52 ( V_79 , V_87 ) ;
V_82 = F_52 ( V_80 , V_88 ) ;
memcpy ( V_82 , V_81 , V_21 ) ;
F_53 ( V_82 , V_88 ) ;
F_53 ( V_81 , V_87 ) ;
F_54 () ;
F_55 ( V_79 ) ;
}
if ( ! ( V_2 -> V_12 & V_53 ) )
F_37 ( V_54 ) ;
V_2 -> V_54 = NULL ;
V_2 -> V_12 &= ~ V_35 ;
return 0 ;
V_34:
F_30 ( V_2 ) ;
return V_31 ;
}
int F_56 ( struct V_1 * V_2 , struct V_78 * V_89 )
{
struct V_76 * V_77 ;
struct V_78 * V_54 ;
struct V_8 * V_79 ;
struct V_8 * V_80 ;
void * V_81 ;
void * V_82 ;
int V_9 ;
int V_31 = - V_36 ;
F_6 ( V_2 -> V_22 != V_38 && V_2 -> V_22 != V_23 ) ;
F_6 ( V_2 -> V_32 != V_42 ) ;
if ( V_2 -> V_12 & V_13 ) {
F_5 ( V_2 ) ;
V_2 -> V_12 |= V_35 ;
V_2 -> V_54 = NULL ;
return 0 ;
}
if ( ! V_89 ) {
V_54 = F_57 ( L_5 ,
V_2 -> V_4 << V_68 ,
0 ) ;
if ( F_16 ( F_49 ( V_54 ) ) ) {
F_32 ( V_90 L_6 ) ;
return F_50 ( V_54 ) ;
}
} else
V_54 = V_89 ;
V_77 = V_54 -> V_83 . V_84 -> V_85 -> V_86 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_4 ; ++ V_9 ) {
V_79 = V_2 -> V_3 [ V_9 ] ;
if ( F_16 ( V_79 == NULL ) )
continue;
V_80 = F_48 ( V_77 , V_9 ) ;
if ( F_16 ( F_49 ( V_80 ) ) ) {
V_31 = F_50 ( V_80 ) ;
goto V_34;
}
F_51 () ;
V_81 = F_52 ( V_79 , V_87 ) ;
V_82 = F_52 ( V_80 , V_88 ) ;
memcpy ( V_82 , V_81 , V_21 ) ;
F_53 ( V_82 , V_88 ) ;
F_53 ( V_81 , V_87 ) ;
F_54 () ;
F_58 ( V_80 ) ;
F_59 ( V_80 ) ;
F_55 ( V_80 ) ;
}
F_30 ( V_2 ) ;
V_2 -> V_54 = V_54 ;
V_2 -> V_12 |= V_35 ;
if ( V_89 )
V_2 -> V_12 |= V_53 ;
return 0 ;
V_34:
if ( ! V_89 )
F_37 ( V_54 ) ;
return V_31 ;
}
