static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = F_2 ( V_2 -> V_4 , sizeof( void * ) ,
V_5 | V_6 ) ;
}
static void F_3 ( struct V_7 * V_2 )
{
V_2 -> V_2 . V_3 = F_2 ( V_2 -> V_2 . V_4 ,
sizeof( * V_2 -> V_2 . V_3 ) +
sizeof( * V_2 -> V_8 ) ,
V_5 | V_6 ) ;
V_2 -> V_8 = ( void * ) ( V_2 -> V_2 . V_3 + V_2 -> V_2 . V_4 ) ;
}
static inline int F_4 ( struct V_9 * V_10 ,
enum V_11 V_12 ,
enum V_11 V_13 )
{
int V_14 = 0 ;
if ( F_5 ( V_10 ) )
return 0 ;
if ( V_12 != V_15 ) {
V_14 = F_6 ( V_10 , 1 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_13 == V_16 )
V_14 = F_7 ( ( unsigned long ) F_8 ( V_10 ) , 1 ) ;
else if ( V_13 == V_17 )
V_14 = F_9 ( V_10 , 1 ) ;
return V_14 ;
}
static inline int F_4 ( struct V_9 * V_10 ,
enum V_11 V_12 ,
enum V_11 V_13 )
{
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
enum V_11 V_18 )
{
int V_19 , V_20 ;
struct V_9 * V_21 ;
int V_14 ;
if ( V_2 -> V_22 == V_18 )
return 0 ;
if ( V_2 -> V_23 == V_24 ) {
V_2 -> V_22 = V_18 ;
return 0 ;
}
if ( V_2 -> V_22 == V_15 )
F_11 ( V_2 -> V_3 , V_2 -> V_4 ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_4 ; ++ V_19 ) {
V_21 = V_2 -> V_3 [ V_19 ] ;
if ( F_12 ( V_21 != NULL ) ) {
V_14 = F_4 ( V_21 ,
V_2 -> V_22 ,
V_18 ) ;
if ( F_13 ( V_14 != 0 ) )
goto V_25;
}
}
V_2 -> V_22 = V_18 ;
return 0 ;
V_25:
for ( V_20 = 0 ; V_20 < V_19 ; ++ V_20 ) {
V_21 = V_2 -> V_3 [ V_20 ] ;
if ( F_12 ( V_21 != NULL ) ) {
( void ) F_4 ( V_21 , V_18 ,
V_2 -> V_22 ) ;
}
}
return V_14 ;
}
int F_14 ( struct V_1 * V_2 , T_1 V_26 )
{
enum V_11 V_23 ;
if ( V_26 & V_27 )
V_23 = V_16 ;
else if ( V_26 & V_28 )
V_23 = V_17 ;
else
V_23 = V_15 ;
return F_10 ( V_2 , V_23 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
F_16 ( V_2 ) ;
if ( V_2 -> V_23 == V_29 )
F_17 ( V_2 ) ;
if ( ! ( V_2 -> V_30 & V_31 ) &&
V_2 -> V_32 )
F_18 ( V_2 -> V_32 ) ;
V_2 -> V_32 = NULL ;
V_2 -> V_33 -> V_34 ( V_2 ) ;
}
int F_19 ( struct V_1 * V_2 , struct V_35 * V_36 ,
unsigned long V_37 , T_1 V_30 ,
struct V_9 * V_38 )
{
V_2 -> V_36 = V_36 ;
V_2 -> V_39 = V_36 -> V_39 ;
V_2 -> V_4 = ( V_37 + V_40 - 1 ) >> V_41 ;
V_2 -> V_22 = V_15 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_38 = V_38 ;
V_2 -> V_23 = V_24 ;
V_2 -> V_32 = NULL ;
F_1 ( V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_15 ( V_2 ) ;
F_20 ( L_1 ) ;
return - V_42 ;
}
return 0 ;
}
void F_21 ( struct V_1 * V_2 )
{
F_22 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
int F_23 ( struct V_7 * V_43 , struct V_35 * V_36 ,
unsigned long V_37 , T_1 V_30 ,
struct V_9 * V_38 )
{
struct V_1 * V_2 = & V_43 -> V_2 ;
V_2 -> V_36 = V_36 ;
V_2 -> V_39 = V_36 -> V_39 ;
V_2 -> V_4 = ( V_37 + V_40 - 1 ) >> V_41 ;
V_2 -> V_22 = V_15 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_38 = V_38 ;
V_2 -> V_23 = V_24 ;
V_2 -> V_32 = NULL ;
F_24 ( & V_43 -> V_44 ) ;
F_3 ( V_43 ) ;
if ( ! V_2 -> V_3 ) {
F_15 ( V_2 ) ;
F_20 ( L_1 ) ;
return - V_42 ;
}
return 0 ;
}
void F_25 ( struct V_7 * V_43 )
{
struct V_1 * V_2 = & V_43 -> V_2 ;
F_22 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
V_43 -> V_8 = NULL ;
}
void F_16 ( struct V_1 * V_2 )
{
int V_14 ;
if ( V_2 -> V_23 == V_45 ) {
V_14 = V_2 -> V_33 -> V_46 ( V_2 ) ;
F_26 ( V_14 ) ;
V_2 -> V_23 = V_29 ;
}
}
int F_27 ( struct V_1 * V_2 , struct V_47 * V_48 )
{
int V_14 = 0 ;
if ( ! V_2 )
return - V_49 ;
if ( V_2 -> V_23 == V_45 )
return 0 ;
V_14 = V_2 -> V_36 -> V_50 -> V_51 ( V_2 ) ;
if ( V_14 )
return V_14 ;
V_14 = V_2 -> V_33 -> V_52 ( V_2 , V_48 ) ;
if ( F_13 ( V_14 != 0 ) )
return V_14 ;
V_2 -> V_23 = V_45 ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 )
{
struct V_53 * V_54 ;
struct V_55 * V_32 ;
struct V_9 * V_56 ;
struct V_9 * V_57 ;
int V_19 ;
int V_14 = - V_42 ;
V_32 = V_2 -> V_32 ;
F_26 ( V_32 == NULL ) ;
V_54 = V_32 -> V_58 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_4 ; ++ V_19 ) {
V_56 = F_29 ( V_54 , V_19 ) ;
if ( F_30 ( V_56 ) ) {
V_14 = F_31 ( V_56 ) ;
goto V_25;
}
V_57 = V_2 -> V_3 [ V_19 ] ;
if ( F_13 ( V_57 == NULL ) )
goto V_25;
F_32 ( V_57 , V_56 ) ;
F_33 ( V_56 ) ;
}
if ( ! ( V_2 -> V_30 & V_31 ) )
F_18 ( V_32 ) ;
V_2 -> V_32 = NULL ;
V_2 -> V_30 &= ~ V_59 ;
return 0 ;
V_25:
return V_14 ;
}
int F_34 ( struct V_1 * V_2 , struct V_55 * V_60 )
{
struct V_53 * V_54 ;
struct V_55 * V_32 ;
struct V_9 * V_56 ;
struct V_9 * V_57 ;
int V_19 ;
int V_14 = - V_42 ;
F_26 ( V_2 -> V_23 != V_29 && V_2 -> V_23 != V_24 ) ;
F_26 ( V_2 -> V_22 != V_15 ) ;
if ( ! V_60 ) {
V_32 = F_35 ( L_2 ,
V_2 -> V_4 << V_41 ,
0 ) ;
if ( F_30 ( V_32 ) ) {
F_20 ( L_3 ) ;
return F_31 ( V_32 ) ;
}
} else
V_32 = V_60 ;
V_54 = V_32 -> V_58 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_4 ; ++ V_19 ) {
V_56 = V_2 -> V_3 [ V_19 ] ;
if ( F_13 ( V_56 == NULL ) )
continue;
V_57 = F_29 ( V_54 , V_19 ) ;
if ( F_30 ( V_57 ) ) {
V_14 = F_31 ( V_57 ) ;
goto V_25;
}
F_32 ( V_57 , V_56 ) ;
F_36 ( V_57 ) ;
F_37 ( V_57 ) ;
F_33 ( V_57 ) ;
}
F_17 ( V_2 ) ;
V_2 -> V_32 = V_32 ;
V_2 -> V_30 |= V_59 ;
if ( V_60 )
V_2 -> V_30 |= V_31 ;
return 0 ;
V_25:
if ( ! V_60 )
F_18 ( V_32 ) ;
return V_14 ;
}
static void F_38 ( struct V_1 * V_2 )
{
T_2 V_19 ;
struct V_9 * * V_9 = V_2 -> V_3 ;
if ( V_2 -> V_30 & V_61 )
return;
for ( V_19 = 0 ; V_19 < V_2 -> V_4 ; ++ V_19 ) {
( * V_9 ) -> V_62 = NULL ;
( * V_9 ++ ) -> V_63 = 0 ;
}
}
void F_17 ( struct V_1 * V_2 )
{
if ( V_2 -> V_23 == V_24 )
return;
F_38 ( V_2 ) ;
V_2 -> V_36 -> V_50 -> F_17 ( V_2 ) ;
}
