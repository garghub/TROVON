static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = F_2 ( V_2 -> V_4 , sizeof( void * ) ) ;
}
static void F_3 ( struct V_5 * V_2 )
{
V_2 -> V_2 . V_3 = F_2 ( V_2 -> V_2 . V_4 ,
sizeof( * V_2 -> V_2 . V_3 ) +
sizeof( * V_2 -> V_6 ) +
sizeof( * V_2 -> V_7 ) ) ;
V_2 -> V_7 = ( void * ) ( V_2 -> V_2 . V_3 + V_2 -> V_2 . V_4 ) ;
V_2 -> V_6 = ( void * ) ( V_2 -> V_7 + V_2 -> V_2 . V_4 ) ;
}
static inline int F_4 ( struct V_8 * V_9 ,
enum V_10 V_11 ,
enum V_10 V_12 )
{
int V_13 = 0 ;
if ( F_5 ( V_9 ) )
return 0 ;
if ( V_11 != V_14 ) {
V_13 = F_6 ( V_9 , 1 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_12 == V_15 )
V_13 = F_7 ( ( unsigned long ) F_8 ( V_9 ) , 1 ) ;
else if ( V_12 == V_16 )
V_13 = F_9 ( V_9 , 1 ) ;
return V_13 ;
}
static inline int F_4 ( struct V_8 * V_9 ,
enum V_10 V_11 ,
enum V_10 V_12 )
{
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
enum V_10 V_17 )
{
int V_18 , V_19 ;
struct V_8 * V_20 ;
int V_13 ;
if ( V_2 -> V_21 == V_17 )
return 0 ;
if ( V_2 -> V_22 == V_23 ) {
V_2 -> V_21 = V_17 ;
return 0 ;
}
if ( V_2 -> V_21 == V_14 )
F_11 ( V_2 -> V_3 , V_2 -> V_4 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_4 ; ++ V_18 ) {
V_20 = V_2 -> V_3 [ V_18 ] ;
if ( F_12 ( V_20 != NULL ) ) {
V_13 = F_4 ( V_20 ,
V_2 -> V_21 ,
V_17 ) ;
if ( F_13 ( V_13 != 0 ) )
goto V_24;
}
}
V_2 -> V_21 = V_17 ;
return 0 ;
V_24:
for ( V_19 = 0 ; V_19 < V_18 ; ++ V_19 ) {
V_20 = V_2 -> V_3 [ V_19 ] ;
if ( F_12 ( V_20 != NULL ) ) {
( void ) F_4 ( V_20 , V_17 ,
V_2 -> V_21 ) ;
}
}
return V_13 ;
}
int F_14 ( struct V_1 * V_2 , T_1 V_25 )
{
enum V_10 V_22 ;
if ( V_25 & V_26 )
V_22 = V_15 ;
else if ( V_25 & V_27 )
V_22 = V_16 ;
else
V_22 = V_14 ;
return F_10 ( V_2 , V_22 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
F_16 ( V_2 ) ;
if ( V_2 -> V_22 == V_28 )
F_17 ( V_2 ) ;
if ( ! ( V_2 -> V_29 & V_30 ) &&
V_2 -> V_31 )
F_18 ( V_2 -> V_31 ) ;
V_2 -> V_31 = NULL ;
V_2 -> V_32 -> V_33 ( V_2 ) ;
}
int F_19 ( struct V_1 * V_2 , struct V_34 * V_35 ,
unsigned long V_36 , T_1 V_29 ,
struct V_8 * V_37 )
{
V_2 -> V_35 = V_35 ;
V_2 -> V_38 = V_35 -> V_38 ;
V_2 -> V_4 = ( V_36 + V_39 - 1 ) >> V_40 ;
V_2 -> V_21 = V_14 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_37 = V_37 ;
V_2 -> V_22 = V_23 ;
V_2 -> V_31 = NULL ;
F_1 ( V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_15 ( V_2 ) ;
F_20 ( L_1 ) ;
return - V_41 ;
}
return 0 ;
}
void F_21 ( struct V_1 * V_2 )
{
F_22 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
int F_23 ( struct V_5 * V_42 , struct V_34 * V_35 ,
unsigned long V_36 , T_1 V_29 ,
struct V_8 * V_37 )
{
struct V_1 * V_2 = & V_42 -> V_2 ;
V_2 -> V_35 = V_35 ;
V_2 -> V_38 = V_35 -> V_38 ;
V_2 -> V_4 = ( V_36 + V_39 - 1 ) >> V_40 ;
V_2 -> V_21 = V_14 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_37 = V_37 ;
V_2 -> V_22 = V_23 ;
V_2 -> V_31 = NULL ;
F_24 ( & V_42 -> V_43 ) ;
F_3 ( V_42 ) ;
if ( ! V_2 -> V_3 ) {
F_15 ( V_2 ) ;
F_20 ( L_1 ) ;
return - V_41 ;
}
return 0 ;
}
void F_25 ( struct V_5 * V_42 )
{
struct V_1 * V_2 = & V_42 -> V_2 ;
F_22 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
V_42 -> V_7 = NULL ;
V_42 -> V_6 = NULL ;
}
void F_16 ( struct V_1 * V_2 )
{
int V_13 ;
if ( V_2 -> V_22 == V_44 ) {
V_13 = V_2 -> V_32 -> V_45 ( V_2 ) ;
F_26 ( V_13 ) ;
V_2 -> V_22 = V_28 ;
}
}
int F_27 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
int V_13 = 0 ;
if ( ! V_2 )
return - V_48 ;
if ( V_2 -> V_22 == V_44 )
return 0 ;
V_13 = V_2 -> V_35 -> V_49 -> V_50 ( V_2 ) ;
if ( V_13 )
return V_13 ;
V_13 = V_2 -> V_32 -> V_51 ( V_2 , V_47 ) ;
if ( F_13 ( V_13 != 0 ) )
return V_13 ;
V_2 -> V_22 = V_44 ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 )
{
struct V_52 * V_53 ;
struct V_54 * V_31 ;
struct V_8 * V_55 ;
struct V_8 * V_56 ;
int V_18 ;
int V_13 = - V_41 ;
V_31 = V_2 -> V_31 ;
F_26 ( V_31 == NULL ) ;
V_53 = V_31 -> V_57 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_4 ; ++ V_18 ) {
V_55 = F_29 ( V_53 , V_18 ) ;
if ( F_30 ( V_55 ) ) {
V_13 = F_31 ( V_55 ) ;
goto V_24;
}
V_56 = V_2 -> V_3 [ V_18 ] ;
if ( F_13 ( V_56 == NULL ) )
goto V_24;
F_32 ( V_56 , V_55 ) ;
F_33 ( V_55 ) ;
}
if ( ! ( V_2 -> V_29 & V_30 ) )
F_18 ( V_31 ) ;
V_2 -> V_31 = NULL ;
V_2 -> V_29 &= ~ V_58 ;
return 0 ;
V_24:
return V_13 ;
}
int F_34 ( struct V_1 * V_2 , struct V_54 * V_59 )
{
struct V_52 * V_53 ;
struct V_54 * V_31 ;
struct V_8 * V_55 ;
struct V_8 * V_56 ;
int V_18 ;
int V_13 = - V_41 ;
F_26 ( V_2 -> V_22 != V_28 && V_2 -> V_22 != V_23 ) ;
F_26 ( V_2 -> V_21 != V_14 ) ;
if ( ! V_59 ) {
V_31 = F_35 ( L_2 ,
V_2 -> V_4 << V_40 ,
0 ) ;
if ( F_30 ( V_31 ) ) {
F_20 ( L_3 ) ;
return F_31 ( V_31 ) ;
}
} else
V_31 = V_59 ;
V_53 = V_31 -> V_57 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_4 ; ++ V_18 ) {
V_55 = V_2 -> V_3 [ V_18 ] ;
if ( F_13 ( V_55 == NULL ) )
continue;
V_56 = F_29 ( V_53 , V_18 ) ;
if ( F_30 ( V_56 ) ) {
V_13 = F_31 ( V_56 ) ;
goto V_24;
}
F_32 ( V_56 , V_55 ) ;
F_36 ( V_56 ) ;
F_37 ( V_56 ) ;
F_33 ( V_56 ) ;
}
F_17 ( V_2 ) ;
V_2 -> V_31 = V_31 ;
V_2 -> V_29 |= V_58 ;
if ( V_59 )
V_2 -> V_29 |= V_30 ;
return 0 ;
V_24:
if ( ! V_59 )
F_18 ( V_31 ) ;
return V_13 ;
}
static void F_38 ( struct V_1 * V_2 )
{
T_2 V_18 ;
struct V_8 * * V_8 = V_2 -> V_3 ;
if ( V_2 -> V_29 & V_60 )
return;
for ( V_18 = 0 ; V_18 < V_2 -> V_4 ; ++ V_18 ) {
( * V_8 ) -> V_61 = NULL ;
( * V_8 ++ ) -> V_62 = 0 ;
}
}
void F_17 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 == V_23 )
return;
F_38 ( V_2 ) ;
V_2 -> V_35 -> V_49 -> F_17 ( V_2 ) ;
}
