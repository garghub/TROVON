static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = F_2 ( V_2 -> V_4 , sizeof( void * ) ) ;
}
static void F_3 ( struct V_5 * V_2 )
{
V_2 -> V_2 . V_3 = F_2 ( V_2 -> V_2 . V_4 , sizeof( void * ) ) ;
V_2 -> V_6 = F_2 ( V_2 -> V_2 . V_4 ,
sizeof( * V_2 -> V_6 ) ) ;
}
static inline int F_4 ( struct V_7 * V_8 ,
enum V_9 V_10 ,
enum V_9 V_11 )
{
int V_12 = 0 ;
if ( F_5 ( V_8 ) )
return 0 ;
if ( V_10 != V_13 ) {
V_12 = F_6 ( V_8 , 1 ) ;
if ( V_12 )
return V_12 ;
}
if ( V_11 == V_14 )
V_12 = F_7 ( ( unsigned long ) F_8 ( V_8 ) , 1 ) ;
else if ( V_11 == V_15 )
V_12 = F_9 ( V_8 , 1 ) ;
return V_12 ;
}
static inline int F_4 ( struct V_7 * V_8 ,
enum V_9 V_10 ,
enum V_9 V_11 )
{
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
enum V_9 V_16 )
{
int V_17 , V_18 ;
struct V_7 * V_19 ;
int V_12 ;
if ( V_2 -> V_20 == V_16 )
return 0 ;
if ( V_2 -> V_21 == V_22 ) {
V_2 -> V_20 = V_16 ;
return 0 ;
}
if ( V_2 -> V_20 == V_13 )
F_11 ( V_2 -> V_3 , V_2 -> V_4 ) ;
for ( V_17 = 0 ; V_17 < V_2 -> V_4 ; ++ V_17 ) {
V_19 = V_2 -> V_3 [ V_17 ] ;
if ( F_12 ( V_19 != NULL ) ) {
V_12 = F_4 ( V_19 ,
V_2 -> V_20 ,
V_16 ) ;
if ( F_13 ( V_12 != 0 ) )
goto V_23;
}
}
V_2 -> V_20 = V_16 ;
return 0 ;
V_23:
for ( V_18 = 0 ; V_18 < V_17 ; ++ V_18 ) {
V_19 = V_2 -> V_3 [ V_18 ] ;
if ( F_12 ( V_19 != NULL ) ) {
( void ) F_4 ( V_19 , V_16 ,
V_2 -> V_20 ) ;
}
}
return V_12 ;
}
int F_14 ( struct V_1 * V_2 , T_1 V_24 )
{
enum V_9 V_21 ;
if ( V_24 & V_25 )
V_21 = V_14 ;
else if ( V_24 & V_26 )
V_21 = V_15 ;
else
V_21 = V_13 ;
return F_10 ( V_2 , V_21 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
if ( F_13 ( V_2 == NULL ) )
return;
if ( V_2 -> V_21 == V_27 ) {
F_16 ( V_2 ) ;
}
if ( F_12 ( V_2 -> V_3 != NULL ) ) {
V_2 -> V_28 -> V_29 -> V_30 ( V_2 ) ;
}
if ( ! ( V_2 -> V_31 & V_32 ) &&
V_2 -> V_33 )
F_17 ( V_2 -> V_33 ) ;
V_2 -> V_33 = NULL ;
V_2 -> V_34 -> V_35 ( V_2 ) ;
}
int F_18 ( struct V_1 * V_2 , struct V_36 * V_28 ,
unsigned long V_37 , T_1 V_31 ,
struct V_7 * V_38 )
{
V_2 -> V_28 = V_28 ;
V_2 -> V_39 = V_28 -> V_39 ;
V_2 -> V_4 = ( V_37 + V_40 - 1 ) >> V_41 ;
V_2 -> V_20 = V_13 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_38 = V_38 ;
V_2 -> V_21 = V_22 ;
V_2 -> V_33 = NULL ;
F_1 ( V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_15 ( V_2 ) ;
F_19 (KERN_ERR TTM_PFX L_1 ) ;
return - V_42 ;
}
return 0 ;
}
void F_20 ( struct V_1 * V_2 )
{
F_21 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
int F_22 ( struct V_5 * V_43 , struct V_36 * V_28 ,
unsigned long V_37 , T_1 V_31 ,
struct V_7 * V_38 )
{
struct V_1 * V_2 = & V_43 -> V_2 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_39 = V_28 -> V_39 ;
V_2 -> V_4 = ( V_37 + V_40 - 1 ) >> V_41 ;
V_2 -> V_20 = V_13 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_38 = V_38 ;
V_2 -> V_21 = V_22 ;
V_2 -> V_33 = NULL ;
F_23 ( & V_43 -> V_44 ) ;
F_3 ( V_43 ) ;
if ( ! V_2 -> V_3 || ! V_43 -> V_6 ) {
F_15 ( V_2 ) ;
F_19 (KERN_ERR TTM_PFX L_1 ) ;
return - V_42 ;
}
return 0 ;
}
void F_24 ( struct V_5 * V_43 )
{
struct V_1 * V_2 = & V_43 -> V_2 ;
F_21 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
F_21 ( V_43 -> V_6 ) ;
V_43 -> V_6 = NULL ;
}
void F_16 ( struct V_1 * V_2 )
{
int V_12 ;
if ( V_2 -> V_21 == V_27 ) {
V_12 = V_2 -> V_34 -> V_45 ( V_2 ) ;
F_25 ( V_12 ) ;
V_2 -> V_21 = V_46 ;
}
}
int F_26 ( struct V_1 * V_2 , struct V_47 * V_48 )
{
int V_12 = 0 ;
if ( ! V_2 )
return - V_49 ;
if ( V_2 -> V_21 == V_27 )
return 0 ;
V_12 = V_2 -> V_28 -> V_29 -> V_50 ( V_2 ) ;
if ( V_12 )
return V_12 ;
V_12 = V_2 -> V_34 -> V_51 ( V_2 , V_48 ) ;
if ( F_13 ( V_12 != 0 ) )
return V_12 ;
V_2 -> V_21 = V_27 ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 )
{
struct V_52 * V_53 ;
struct V_54 * V_33 ;
struct V_7 * V_55 ;
struct V_7 * V_56 ;
void * V_57 ;
void * V_58 ;
int V_17 ;
int V_12 = - V_42 ;
V_33 = V_2 -> V_33 ;
F_25 ( V_33 == NULL ) ;
V_53 = V_33 -> V_59 . V_60 -> V_61 -> V_62 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_4 ; ++ V_17 ) {
V_55 = F_28 ( V_53 , V_17 ) ;
if ( F_29 ( V_55 ) ) {
V_12 = F_30 ( V_55 ) ;
goto V_23;
}
V_56 = V_2 -> V_3 [ V_17 ] ;
if ( F_13 ( V_56 == NULL ) )
goto V_23;
F_31 () ;
V_57 = F_32 ( V_55 , V_63 ) ;
V_58 = F_32 ( V_56 , V_64 ) ;
memcpy ( V_58 , V_57 , V_40 ) ;
F_33 ( V_58 , V_64 ) ;
F_33 ( V_57 , V_63 ) ;
F_34 () ;
F_35 ( V_55 ) ;
}
if ( ! ( V_2 -> V_31 & V_32 ) )
F_17 ( V_33 ) ;
V_2 -> V_33 = NULL ;
V_2 -> V_31 &= ~ V_65 ;
return 0 ;
V_23:
return V_12 ;
}
int F_36 ( struct V_1 * V_2 , struct V_54 * V_66 )
{
struct V_52 * V_53 ;
struct V_54 * V_33 ;
struct V_7 * V_55 ;
struct V_7 * V_56 ;
void * V_57 ;
void * V_58 ;
int V_17 ;
int V_12 = - V_42 ;
F_25 ( V_2 -> V_21 != V_46 && V_2 -> V_21 != V_22 ) ;
F_25 ( V_2 -> V_20 != V_13 ) ;
if ( ! V_66 ) {
V_33 = F_37 ( L_2 ,
V_2 -> V_4 << V_41 ,
0 ) ;
if ( F_13 ( F_29 ( V_33 ) ) ) {
F_19 ( V_67 L_3 ) ;
return F_30 ( V_33 ) ;
}
} else
V_33 = V_66 ;
V_53 = V_33 -> V_59 . V_60 -> V_61 -> V_62 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_4 ; ++ V_17 ) {
V_55 = V_2 -> V_3 [ V_17 ] ;
if ( F_13 ( V_55 == NULL ) )
continue;
V_56 = F_28 ( V_53 , V_17 ) ;
if ( F_13 ( F_29 ( V_56 ) ) ) {
V_12 = F_30 ( V_56 ) ;
goto V_23;
}
F_31 () ;
V_57 = F_32 ( V_55 , V_63 ) ;
V_58 = F_32 ( V_56 , V_64 ) ;
memcpy ( V_58 , V_57 , V_40 ) ;
F_33 ( V_58 , V_64 ) ;
F_33 ( V_57 , V_63 ) ;
F_34 () ;
F_38 ( V_56 ) ;
F_39 ( V_56 ) ;
F_35 ( V_56 ) ;
}
V_2 -> V_28 -> V_29 -> V_30 ( V_2 ) ;
V_2 -> V_33 = V_33 ;
V_2 -> V_31 |= V_65 ;
if ( V_66 )
V_2 -> V_31 |= V_32 ;
return 0 ;
V_23:
if ( ! V_66 )
F_17 ( V_33 ) ;
return V_12 ;
}
