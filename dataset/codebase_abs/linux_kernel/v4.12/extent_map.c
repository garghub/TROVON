int T_1 F_1 ( void )
{
V_1 = F_2 ( L_1 ,
sizeof( struct V_2 ) , 0 ,
V_3 , NULL ) ;
if ( ! V_1 )
return - V_4 ;
return 0 ;
}
void F_3 ( void )
{
F_4 ( V_1 ) ;
}
void F_5 ( struct V_5 * V_6 )
{
V_6 -> V_7 = V_8 ;
F_6 ( & V_6 -> V_9 ) ;
F_7 ( & V_6 -> V_10 ) ;
}
struct V_2 * F_8 ( void )
{
struct V_2 * V_11 ;
V_11 = F_9 ( V_1 , V_12 ) ;
if ( ! V_11 )
return NULL ;
F_10 ( & V_11 -> V_13 ) ;
V_11 -> V_14 = 0 ;
V_11 -> V_15 = V_16 ;
V_11 -> V_17 = 0 ;
F_11 ( & V_11 -> V_18 , 1 ) ;
F_6 ( & V_11 -> V_19 ) ;
return V_11 ;
}
void F_12 ( struct V_2 * V_11 )
{
if ( ! V_11 )
return;
F_13 ( F_14 ( & V_11 -> V_18 ) == 0 ) ;
if ( F_15 ( & V_11 -> V_18 ) ) {
F_13 ( F_16 ( V_11 ) ) ;
F_13 ( ! F_17 ( & V_11 -> V_19 ) ) ;
if ( F_18 ( V_20 , & V_11 -> V_14 ) )
F_19 ( V_11 -> V_21 ) ;
F_20 ( V_1 , V_11 ) ;
}
}
static T_2 F_21 ( T_2 V_22 , T_2 V_23 )
{
if ( V_22 + V_23 < V_22 )
return ( T_2 ) - 1 ;
return V_22 + V_23 ;
}
static int F_22 ( struct V_24 * V_25 , struct V_2 * V_11 )
{
struct V_13 * * V_26 = & V_25 -> V_13 ;
struct V_13 * V_27 = NULL ;
struct V_2 * V_28 = NULL ;
struct V_13 * V_29 = NULL ;
T_2 V_30 = F_21 ( V_11 -> V_22 , V_11 -> V_23 ) ;
while ( * V_26 ) {
V_27 = * V_26 ;
V_28 = F_23 ( V_27 , struct V_2 , V_13 ) ;
if ( V_11 -> V_22 < V_28 -> V_22 )
V_26 = & ( * V_26 ) -> V_31 ;
else if ( V_11 -> V_22 >= F_24 ( V_28 ) )
V_26 = & ( * V_26 ) -> V_32 ;
else
return - V_33 ;
}
V_29 = V_27 ;
while ( V_27 && V_11 -> V_22 >= F_24 ( V_28 ) ) {
V_27 = F_25 ( V_27 ) ;
V_28 = F_23 ( V_27 , struct V_2 , V_13 ) ;
}
if ( V_27 )
if ( V_30 > V_28 -> V_22 && V_11 -> V_22 < F_24 ( V_28 ) )
return - V_33 ;
V_27 = V_29 ;
V_28 = F_23 ( V_27 , struct V_2 , V_13 ) ;
while ( V_27 && V_11 -> V_22 < V_28 -> V_22 ) {
V_27 = F_26 ( V_27 ) ;
V_28 = F_23 ( V_27 , struct V_2 , V_13 ) ;
}
if ( V_27 )
if ( V_30 > V_28 -> V_22 && V_11 -> V_22 < F_24 ( V_28 ) )
return - V_33 ;
F_27 ( & V_11 -> V_13 , V_29 , V_26 ) ;
F_28 ( & V_11 -> V_13 , V_25 ) ;
return 0 ;
}
static struct V_13 * F_29 ( struct V_24 * V_25 , T_2 V_34 ,
struct V_13 * * V_35 ,
struct V_13 * * V_36 )
{
struct V_13 * V_37 = V_25 -> V_13 ;
struct V_13 * V_38 = NULL ;
struct V_13 * V_39 = NULL ;
struct V_2 * V_28 ;
struct V_2 * V_40 = NULL ;
while ( V_37 ) {
V_28 = F_23 ( V_37 , struct V_2 , V_13 ) ;
V_38 = V_37 ;
V_40 = V_28 ;
if ( V_34 < V_28 -> V_22 )
V_37 = V_37 -> V_31 ;
else if ( V_34 >= F_24 ( V_28 ) )
V_37 = V_37 -> V_32 ;
else
return V_37 ;
}
if ( V_35 ) {
V_39 = V_38 ;
while ( V_38 && V_34 >= F_24 ( V_40 ) ) {
V_38 = F_25 ( V_38 ) ;
V_40 = F_23 ( V_38 , struct V_2 , V_13 ) ;
}
* V_35 = V_38 ;
V_38 = V_39 ;
}
if ( V_36 ) {
V_40 = F_23 ( V_38 , struct V_2 , V_13 ) ;
while ( V_38 && V_34 < V_40 -> V_22 ) {
V_38 = F_26 ( V_38 ) ;
V_40 = F_23 ( V_38 , struct V_2 , V_13 ) ;
}
* V_36 = V_38 ;
}
return NULL ;
}
static int F_30 ( struct V_2 * V_38 , struct V_2 * V_41 )
{
if ( F_18 ( V_42 , & V_38 -> V_14 ) )
return 0 ;
if ( F_18 ( V_43 , & V_38 -> V_14 ) )
return 0 ;
if ( F_18 ( V_44 , & V_38 -> V_14 ) ||
F_18 ( V_44 , & V_41 -> V_14 ) )
return 0 ;
if ( ! F_17 ( & V_38 -> V_19 ) || ! F_17 ( & V_41 -> V_19 ) )
return 0 ;
if ( F_24 ( V_38 ) == V_41 -> V_22 &&
V_38 -> V_14 == V_41 -> V_14 &&
V_38 -> V_45 == V_41 -> V_45 &&
( ( V_41 -> V_46 == V_47 &&
V_38 -> V_46 == V_47 ) ||
( V_41 -> V_46 == V_48 &&
V_38 -> V_46 == V_48 ) ||
( V_41 -> V_46 == V_49 &&
V_38 -> V_46 == V_49 ) ||
( V_41 -> V_46 < V_50 - 1 &&
V_41 -> V_46 == F_31 ( V_38 ) ) ) ) {
return 1 ;
}
return 0 ;
}
static void F_32 ( struct V_5 * V_6 , struct V_2 * V_11 )
{
struct V_2 * V_51 = NULL ;
struct V_13 * V_52 ;
if ( V_11 -> V_22 != 0 ) {
V_52 = F_26 ( & V_11 -> V_13 ) ;
if ( V_52 )
V_51 = F_23 ( V_52 , struct V_2 , V_13 ) ;
if ( V_52 && F_30 ( V_51 , V_11 ) ) {
V_11 -> V_22 = V_51 -> V_22 ;
V_11 -> V_53 = V_51 -> V_53 ;
V_11 -> V_23 += V_51 -> V_23 ;
V_11 -> V_54 += V_51 -> V_54 ;
V_11 -> V_46 = V_51 -> V_46 ;
V_11 -> V_55 = ( V_11 -> V_55 + V_11 -> V_56 ) - V_51 -> V_56 ;
V_11 -> V_56 = V_51 -> V_56 ;
V_11 -> V_17 = F_33 ( V_11 -> V_17 , V_51 -> V_17 ) ;
F_34 ( & V_51 -> V_13 , & V_6 -> V_7 ) ;
F_10 ( & V_51 -> V_13 ) ;
F_12 ( V_51 ) ;
}
}
V_52 = F_25 ( & V_11 -> V_13 ) ;
if ( V_52 )
V_51 = F_23 ( V_52 , struct V_2 , V_13 ) ;
if ( V_52 && F_30 ( V_11 , V_51 ) ) {
V_11 -> V_23 += V_51 -> V_23 ;
V_11 -> V_54 += V_51 -> V_54 ;
F_34 ( & V_51 -> V_13 , & V_6 -> V_7 ) ;
F_10 ( & V_51 -> V_13 ) ;
V_11 -> V_55 = ( V_51 -> V_56 + V_51 -> V_55 ) - V_11 -> V_56 ;
V_11 -> V_17 = F_33 ( V_11 -> V_17 , V_51 -> V_17 ) ;
F_12 ( V_51 ) ;
}
}
int F_35 ( struct V_5 * V_6 , T_2 V_22 , T_2 V_23 ,
T_2 V_57 )
{
int V_58 = 0 ;
struct V_2 * V_11 ;
bool V_59 = false ;
F_36 ( & V_6 -> V_10 ) ;
V_11 = F_37 ( V_6 , V_22 , V_23 ) ;
F_13 ( ! V_11 || V_11 -> V_22 != V_22 ) ;
if ( ! V_11 )
goto V_60;
V_11 -> V_17 = V_57 ;
F_38 ( V_42 , & V_11 -> V_14 ) ;
V_11 -> V_56 = V_11 -> V_22 ;
V_11 -> V_55 = V_11 -> V_23 ;
if ( F_18 ( V_61 , & V_11 -> V_14 ) ) {
V_59 = true ;
F_38 ( V_61 , & V_11 -> V_14 ) ;
}
F_32 ( V_6 , V_11 ) ;
if ( V_59 ) {
V_11 -> V_56 = V_11 -> V_22 ;
V_11 -> V_55 = V_11 -> V_23 ;
}
F_12 ( V_11 ) ;
V_60:
F_39 ( & V_6 -> V_10 ) ;
return V_58 ;
}
void F_40 ( struct V_5 * V_6 , struct V_2 * V_11 )
{
F_38 ( V_44 , & V_11 -> V_14 ) ;
if ( F_16 ( V_11 ) )
F_32 ( V_6 , V_11 ) ;
}
static inline void F_41 ( struct V_5 * V_6 ,
struct V_2 * V_11 ,
int V_62 )
{
F_42 ( & V_11 -> V_18 ) ;
V_11 -> V_56 = V_11 -> V_22 ;
V_11 -> V_55 = V_11 -> V_23 ;
if ( V_62 )
F_43 ( & V_11 -> V_19 , & V_6 -> V_9 ) ;
else
F_32 ( V_6 , V_11 ) ;
}
int F_44 ( struct V_5 * V_6 ,
struct V_2 * V_11 , int V_62 )
{
int V_58 = 0 ;
V_58 = F_22 ( & V_6 -> V_7 , V_11 ) ;
if ( V_58 )
goto V_60;
F_41 ( V_6 , V_11 , V_62 ) ;
V_60:
return V_58 ;
}
static struct V_2 *
F_45 ( struct V_5 * V_6 ,
T_2 V_22 , T_2 V_23 , int V_63 )
{
struct V_2 * V_11 ;
struct V_13 * V_13 ;
struct V_13 * V_38 = NULL ;
struct V_13 * V_41 = NULL ;
T_2 V_30 = F_21 ( V_22 , V_23 ) ;
V_13 = F_29 ( & V_6 -> V_7 , V_22 , & V_38 , & V_41 ) ;
if ( ! V_13 ) {
if ( V_38 )
V_13 = V_38 ;
else if ( V_41 )
V_13 = V_41 ;
else
return NULL ;
}
V_11 = F_23 ( V_13 , struct V_2 , V_13 ) ;
if ( V_63 && ! ( V_30 > V_11 -> V_22 && V_22 < F_24 ( V_11 ) ) )
return NULL ;
F_42 ( & V_11 -> V_18 ) ;
return V_11 ;
}
struct V_2 * F_37 ( struct V_5 * V_6 ,
T_2 V_22 , T_2 V_23 )
{
return F_45 ( V_6 , V_22 , V_23 , 1 ) ;
}
struct V_2 * F_46 ( struct V_5 * V_6 ,
T_2 V_22 , T_2 V_23 )
{
return F_45 ( V_6 , V_22 , V_23 , 0 ) ;
}
int F_47 ( struct V_5 * V_6 , struct V_2 * V_11 )
{
int V_58 = 0 ;
F_13 ( F_18 ( V_42 , & V_11 -> V_14 ) ) ;
F_34 ( & V_11 -> V_13 , & V_6 -> V_7 ) ;
if ( ! F_18 ( V_44 , & V_11 -> V_14 ) )
F_48 ( & V_11 -> V_19 ) ;
F_10 ( & V_11 -> V_13 ) ;
return V_58 ;
}
void F_49 ( struct V_5 * V_6 ,
struct V_2 * V_64 ,
struct V_2 * V_65 ,
int V_62 )
{
F_13 ( F_18 ( V_42 , & V_64 -> V_14 ) ) ;
ASSERT ( F_16 ( V_64 ) ) ;
if ( ! F_18 ( V_44 , & V_64 -> V_14 ) )
F_48 ( & V_64 -> V_19 ) ;
F_50 ( & V_64 -> V_13 , & V_65 -> V_13 , & V_6 -> V_7 ) ;
F_10 ( & V_64 -> V_13 ) ;
F_41 ( V_6 , V_65 , V_62 ) ;
}
