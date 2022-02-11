static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = F_2 ( V_2 -> V_4 , sizeof( void * ) ) ;
}
static void F_3 ( struct V_5 * V_2 )
{
V_2 -> V_2 . V_3 = F_2 ( V_2 -> V_2 . V_4 ,
sizeof( * V_2 -> V_2 . V_3 ) +
sizeof( * V_2 -> V_6 ) ) ;
V_2 -> V_6 = ( void * ) ( V_2 -> V_2 . V_3 + V_2 -> V_2 . V_4 ) ;
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
if ( V_2 == NULL )
return;
F_16 ( V_2 ) ;
if ( V_2 -> V_21 == V_27 )
F_17 ( V_2 ) ;
if ( ! ( V_2 -> V_28 & V_29 ) &&
V_2 -> V_30 )
F_18 ( V_2 -> V_30 ) ;
V_2 -> V_30 = NULL ;
V_2 -> V_31 -> V_32 ( V_2 ) ;
}
int F_19 ( struct V_1 * V_2 , struct V_33 * V_34 ,
unsigned long V_35 , T_1 V_28 ,
struct V_7 * V_36 )
{
V_2 -> V_34 = V_34 ;
V_2 -> V_37 = V_34 -> V_37 ;
V_2 -> V_4 = ( V_35 + V_38 - 1 ) >> V_39 ;
V_2 -> V_20 = V_13 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_36 = V_36 ;
V_2 -> V_21 = V_22 ;
V_2 -> V_30 = NULL ;
F_1 ( V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_15 ( V_2 ) ;
F_20 ( L_1 ) ;
return - V_40 ;
}
return 0 ;
}
void F_21 ( struct V_1 * V_2 )
{
F_22 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
int F_23 ( struct V_5 * V_41 , struct V_33 * V_34 ,
unsigned long V_35 , T_1 V_28 ,
struct V_7 * V_36 )
{
struct V_1 * V_2 = & V_41 -> V_2 ;
V_2 -> V_34 = V_34 ;
V_2 -> V_37 = V_34 -> V_37 ;
V_2 -> V_4 = ( V_35 + V_38 - 1 ) >> V_39 ;
V_2 -> V_20 = V_13 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_36 = V_36 ;
V_2 -> V_21 = V_22 ;
V_2 -> V_30 = NULL ;
F_24 ( & V_41 -> V_42 ) ;
F_3 ( V_41 ) ;
if ( ! V_2 -> V_3 ) {
F_15 ( V_2 ) ;
F_20 ( L_1 ) ;
return - V_40 ;
}
return 0 ;
}
void F_25 ( struct V_5 * V_41 )
{
struct V_1 * V_2 = & V_41 -> V_2 ;
F_22 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
V_41 -> V_6 = NULL ;
}
void F_16 ( struct V_1 * V_2 )
{
int V_12 ;
if ( V_2 -> V_21 == V_43 ) {
V_12 = V_2 -> V_31 -> V_44 ( V_2 ) ;
F_26 ( V_12 ) ;
V_2 -> V_21 = V_27 ;
}
}
int F_27 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
int V_12 = 0 ;
if ( ! V_2 )
return - V_47 ;
if ( V_2 -> V_21 == V_43 )
return 0 ;
V_12 = V_2 -> V_34 -> V_48 -> V_49 ( V_2 ) ;
if ( V_12 )
return V_12 ;
V_12 = V_2 -> V_31 -> V_50 ( V_2 , V_46 ) ;
if ( F_13 ( V_12 != 0 ) )
return V_12 ;
V_2 -> V_21 = V_43 ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 )
{
struct V_51 * V_52 ;
struct V_53 * V_30 ;
struct V_7 * V_54 ;
struct V_7 * V_55 ;
int V_17 ;
int V_12 = - V_40 ;
V_30 = V_2 -> V_30 ;
F_26 ( V_30 == NULL ) ;
V_52 = V_30 -> V_56 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_4 ; ++ V_17 ) {
V_54 = F_29 ( V_52 , V_17 ) ;
if ( F_30 ( V_54 ) ) {
V_12 = F_31 ( V_54 ) ;
goto V_23;
}
V_55 = V_2 -> V_3 [ V_17 ] ;
if ( F_13 ( V_55 == NULL ) )
goto V_23;
F_32 ( V_55 , V_54 ) ;
F_33 ( V_54 ) ;
}
if ( ! ( V_2 -> V_28 & V_29 ) )
F_18 ( V_30 ) ;
V_2 -> V_30 = NULL ;
V_2 -> V_28 &= ~ V_57 ;
return 0 ;
V_23:
return V_12 ;
}
int F_34 ( struct V_1 * V_2 , struct V_53 * V_58 )
{
struct V_51 * V_52 ;
struct V_53 * V_30 ;
struct V_7 * V_54 ;
struct V_7 * V_55 ;
int V_17 ;
int V_12 = - V_40 ;
F_26 ( V_2 -> V_21 != V_27 && V_2 -> V_21 != V_22 ) ;
F_26 ( V_2 -> V_20 != V_13 ) ;
if ( ! V_58 ) {
V_30 = F_35 ( L_2 ,
V_2 -> V_4 << V_39 ,
0 ) ;
if ( F_30 ( V_30 ) ) {
F_20 ( L_3 ) ;
return F_31 ( V_30 ) ;
}
} else
V_30 = V_58 ;
V_52 = V_30 -> V_56 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_4 ; ++ V_17 ) {
V_54 = V_2 -> V_3 [ V_17 ] ;
if ( F_13 ( V_54 == NULL ) )
continue;
V_55 = F_29 ( V_52 , V_17 ) ;
if ( F_30 ( V_55 ) ) {
V_12 = F_31 ( V_55 ) ;
goto V_23;
}
F_32 ( V_55 , V_54 ) ;
F_36 ( V_55 ) ;
F_37 ( V_55 ) ;
F_33 ( V_55 ) ;
}
F_17 ( V_2 ) ;
V_2 -> V_30 = V_30 ;
V_2 -> V_28 |= V_57 ;
if ( V_58 )
V_2 -> V_28 |= V_29 ;
return 0 ;
V_23:
if ( ! V_58 )
F_18 ( V_30 ) ;
return V_12 ;
}
static void F_38 ( struct V_1 * V_2 )
{
T_2 V_17 ;
struct V_7 * * V_7 = V_2 -> V_3 ;
if ( V_2 -> V_28 & V_59 )
return;
for ( V_17 = 0 ; V_17 < V_2 -> V_4 ; ++ V_17 ) {
( * V_7 ) -> V_60 = NULL ;
( * V_7 ++ ) -> V_61 = 0 ;
}
}
void F_17 ( struct V_1 * V_2 )
{
if ( V_2 -> V_21 == V_22 )
return;
F_38 ( V_2 ) ;
V_2 -> V_34 -> V_48 -> F_17 ( V_2 ) ;
}
