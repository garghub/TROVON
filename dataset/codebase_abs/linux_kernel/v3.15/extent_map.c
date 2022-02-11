int T_1 F_1 ( void )
{
V_1 = F_2 ( L_1 ,
sizeof( struct V_2 ) , 0 ,
V_3 | V_4 , NULL ) ;
if ( ! V_1 )
return - V_5 ;
return 0 ;
}
void F_3 ( void )
{
if ( V_1 )
F_4 ( V_1 ) ;
}
void F_5 ( struct V_6 * V_7 )
{
V_7 -> V_8 = V_9 ;
F_6 ( & V_7 -> V_10 ) ;
F_7 ( & V_7 -> V_11 ) ;
}
struct V_2 * F_8 ( void )
{
struct V_2 * V_12 ;
V_12 = F_9 ( V_1 , V_13 ) ;
if ( ! V_12 )
return NULL ;
F_10 ( & V_12 -> V_14 ) ;
V_12 -> V_15 = 0 ;
V_12 -> V_16 = V_17 ;
V_12 -> V_18 = 0 ;
F_11 ( & V_12 -> V_19 , 1 ) ;
F_6 ( & V_12 -> V_20 ) ;
return V_12 ;
}
void F_12 ( struct V_2 * V_12 )
{
if ( ! V_12 )
return;
F_13 ( F_14 ( & V_12 -> V_19 ) == 0 ) ;
if ( F_15 ( & V_12 -> V_19 ) ) {
F_13 ( F_16 ( V_12 ) ) ;
F_13 ( ! F_17 ( & V_12 -> V_20 ) ) ;
F_18 ( V_1 , V_12 ) ;
}
}
static T_2 F_19 ( T_2 V_21 , T_2 V_22 )
{
if ( V_21 + V_22 < V_21 )
return ( T_2 ) - 1 ;
return V_21 + V_22 ;
}
static int F_20 ( struct V_23 * V_24 , struct V_2 * V_12 )
{
struct V_14 * * V_25 = & V_24 -> V_14 ;
struct V_14 * V_26 = NULL ;
struct V_2 * V_27 = NULL ;
struct V_14 * V_28 = NULL ;
T_2 V_29 = F_19 ( V_12 -> V_21 , V_12 -> V_22 ) ;
while ( * V_25 ) {
V_26 = * V_25 ;
V_27 = F_21 ( V_26 , struct V_2 , V_14 ) ;
if ( V_12 -> V_21 < V_27 -> V_21 )
V_25 = & ( * V_25 ) -> V_30 ;
else if ( V_12 -> V_21 >= F_22 ( V_27 ) )
V_25 = & ( * V_25 ) -> V_31 ;
else
return - V_32 ;
}
V_28 = V_26 ;
while ( V_26 && V_12 -> V_21 >= F_22 ( V_27 ) ) {
V_26 = F_23 ( V_26 ) ;
V_27 = F_21 ( V_26 , struct V_2 , V_14 ) ;
}
if ( V_26 )
if ( V_29 > V_27 -> V_21 && V_12 -> V_21 < F_22 ( V_27 ) )
return - V_32 ;
V_26 = V_28 ;
V_27 = F_21 ( V_26 , struct V_2 , V_14 ) ;
while ( V_26 && V_12 -> V_21 < V_27 -> V_21 ) {
V_26 = F_24 ( V_26 ) ;
V_27 = F_21 ( V_26 , struct V_2 , V_14 ) ;
}
if ( V_26 )
if ( V_29 > V_27 -> V_21 && V_12 -> V_21 < F_22 ( V_27 ) )
return - V_32 ;
F_25 ( & V_12 -> V_14 , V_28 , V_25 ) ;
F_26 ( & V_12 -> V_14 , V_24 ) ;
return 0 ;
}
static struct V_14 * F_27 ( struct V_23 * V_24 , T_2 V_33 ,
struct V_14 * * V_34 ,
struct V_14 * * V_35 )
{
struct V_14 * V_36 = V_24 -> V_14 ;
struct V_14 * V_37 = NULL ;
struct V_14 * V_38 = NULL ;
struct V_2 * V_27 ;
struct V_2 * V_39 = NULL ;
while ( V_36 ) {
V_27 = F_21 ( V_36 , struct V_2 , V_14 ) ;
V_37 = V_36 ;
V_39 = V_27 ;
if ( V_33 < V_27 -> V_21 )
V_36 = V_36 -> V_30 ;
else if ( V_33 >= F_22 ( V_27 ) )
V_36 = V_36 -> V_31 ;
else
return V_36 ;
}
if ( V_34 ) {
V_38 = V_37 ;
while ( V_37 && V_33 >= F_22 ( V_39 ) ) {
V_37 = F_23 ( V_37 ) ;
V_39 = F_21 ( V_37 , struct V_2 , V_14 ) ;
}
* V_34 = V_37 ;
V_37 = V_38 ;
}
if ( V_35 ) {
V_39 = F_21 ( V_37 , struct V_2 , V_14 ) ;
while ( V_37 && V_33 < V_39 -> V_21 ) {
V_37 = F_24 ( V_37 ) ;
V_39 = F_21 ( V_37 , struct V_2 , V_14 ) ;
}
* V_35 = V_37 ;
}
return NULL ;
}
static int F_28 ( struct V_2 * V_37 , struct V_2 * V_40 )
{
if ( F_29 ( V_41 , & V_37 -> V_15 ) )
return 0 ;
if ( F_29 ( V_42 , & V_37 -> V_15 ) )
return 0 ;
if ( F_29 ( V_43 , & V_37 -> V_15 ) ||
F_29 ( V_43 , & V_40 -> V_15 ) )
return 0 ;
if ( ! F_17 ( & V_37 -> V_20 ) || ! F_17 ( & V_40 -> V_20 ) )
return 0 ;
if ( F_22 ( V_37 ) == V_40 -> V_21 &&
V_37 -> V_15 == V_40 -> V_15 &&
V_37 -> V_44 == V_40 -> V_44 &&
( ( V_40 -> V_45 == V_46 &&
V_37 -> V_45 == V_46 ) ||
( V_40 -> V_45 == V_47 &&
V_37 -> V_45 == V_47 ) ||
( V_40 -> V_45 == V_48 &&
V_37 -> V_45 == V_48 ) ||
( V_40 -> V_45 < V_49 - 1 &&
V_40 -> V_45 == F_30 ( V_37 ) ) ) ) {
return 1 ;
}
return 0 ;
}
static void F_31 ( struct V_6 * V_7 , struct V_2 * V_12 )
{
struct V_2 * V_50 = NULL ;
struct V_14 * V_51 ;
if ( V_12 -> V_21 != 0 ) {
V_51 = F_24 ( & V_12 -> V_14 ) ;
if ( V_51 )
V_50 = F_21 ( V_51 , struct V_2 , V_14 ) ;
if ( V_51 && F_28 ( V_50 , V_12 ) ) {
V_12 -> V_21 = V_50 -> V_21 ;
V_12 -> V_52 = V_50 -> V_52 ;
V_12 -> V_22 += V_50 -> V_22 ;
V_12 -> V_53 += V_50 -> V_53 ;
V_12 -> V_45 = V_50 -> V_45 ;
V_12 -> V_54 = ( V_12 -> V_54 + V_12 -> V_55 ) - V_50 -> V_55 ;
V_12 -> V_55 = V_50 -> V_55 ;
V_12 -> V_18 = F_32 ( V_12 -> V_18 , V_50 -> V_18 ) ;
F_33 ( & V_50 -> V_14 , & V_7 -> V_8 ) ;
F_10 ( & V_50 -> V_14 ) ;
F_12 ( V_50 ) ;
}
}
V_51 = F_23 ( & V_12 -> V_14 ) ;
if ( V_51 )
V_50 = F_21 ( V_51 , struct V_2 , V_14 ) ;
if ( V_51 && F_28 ( V_12 , V_50 ) ) {
V_12 -> V_22 += V_50 -> V_22 ;
V_12 -> V_53 += V_50 -> V_53 ;
F_33 ( & V_50 -> V_14 , & V_7 -> V_8 ) ;
F_10 ( & V_50 -> V_14 ) ;
V_12 -> V_54 = ( V_50 -> V_55 + V_50 -> V_54 ) - V_12 -> V_55 ;
V_12 -> V_18 = F_32 ( V_12 -> V_18 , V_50 -> V_18 ) ;
F_12 ( V_50 ) ;
}
}
int F_34 ( struct V_6 * V_7 , T_2 V_21 , T_2 V_22 ,
T_2 V_56 )
{
int V_57 = 0 ;
struct V_2 * V_12 ;
bool V_58 = false ;
F_35 ( & V_7 -> V_11 ) ;
V_12 = F_36 ( V_7 , V_21 , V_22 ) ;
F_13 ( ! V_12 || V_12 -> V_21 != V_21 ) ;
if ( ! V_12 )
goto V_59;
if ( ! F_29 ( V_43 , & V_12 -> V_15 ) )
F_37 ( & V_12 -> V_20 , & V_7 -> V_10 ) ;
V_12 -> V_18 = V_56 ;
F_38 ( V_41 , & V_12 -> V_15 ) ;
V_12 -> V_55 = V_12 -> V_21 ;
V_12 -> V_54 = V_12 -> V_22 ;
if ( F_29 ( V_60 , & V_12 -> V_15 ) ) {
V_58 = true ;
F_38 ( V_60 , & V_12 -> V_15 ) ;
}
F_31 ( V_7 , V_12 ) ;
if ( V_58 ) {
V_12 -> V_55 = V_12 -> V_21 ;
V_12 -> V_54 = V_12 -> V_22 ;
}
F_12 ( V_12 ) ;
V_59:
F_39 ( & V_7 -> V_11 ) ;
return V_57 ;
}
void F_40 ( struct V_6 * V_7 , struct V_2 * V_12 )
{
F_38 ( V_43 , & V_12 -> V_15 ) ;
if ( F_16 ( V_12 ) )
F_31 ( V_7 , V_12 ) ;
}
static inline void F_41 ( struct V_6 * V_7 ,
struct V_2 * V_12 ,
int V_61 )
{
F_42 ( & V_12 -> V_19 ) ;
V_12 -> V_55 = V_12 -> V_21 ;
V_12 -> V_54 = V_12 -> V_22 ;
if ( V_61 )
F_37 ( & V_12 -> V_20 , & V_7 -> V_10 ) ;
else
F_31 ( V_7 , V_12 ) ;
}
int F_43 ( struct V_6 * V_7 ,
struct V_2 * V_12 , int V_61 )
{
int V_57 = 0 ;
V_57 = F_20 ( & V_7 -> V_8 , V_12 ) ;
if ( V_57 )
goto V_59;
F_41 ( V_7 , V_12 , V_61 ) ;
V_59:
return V_57 ;
}
static struct V_2 *
F_44 ( struct V_6 * V_7 ,
T_2 V_21 , T_2 V_22 , int V_62 )
{
struct V_2 * V_12 ;
struct V_14 * V_14 ;
struct V_14 * V_37 = NULL ;
struct V_14 * V_40 = NULL ;
T_2 V_29 = F_19 ( V_21 , V_22 ) ;
V_14 = F_27 ( & V_7 -> V_8 , V_21 , & V_37 , & V_40 ) ;
if ( ! V_14 ) {
if ( V_37 )
V_14 = V_37 ;
else if ( V_40 )
V_14 = V_40 ;
else
return NULL ;
}
V_12 = F_21 ( V_14 , struct V_2 , V_14 ) ;
if ( V_62 && ! ( V_29 > V_12 -> V_21 && V_21 < F_22 ( V_12 ) ) )
return NULL ;
F_42 ( & V_12 -> V_19 ) ;
return V_12 ;
}
struct V_2 * F_36 ( struct V_6 * V_7 ,
T_2 V_21 , T_2 V_22 )
{
return F_44 ( V_7 , V_21 , V_22 , 1 ) ;
}
struct V_2 * F_45 ( struct V_6 * V_7 ,
T_2 V_21 , T_2 V_22 )
{
return F_44 ( V_7 , V_21 , V_22 , 0 ) ;
}
int F_46 ( struct V_6 * V_7 , struct V_2 * V_12 )
{
int V_57 = 0 ;
F_13 ( F_29 ( V_41 , & V_12 -> V_15 ) ) ;
F_33 ( & V_12 -> V_14 , & V_7 -> V_8 ) ;
if ( ! F_29 ( V_43 , & V_12 -> V_15 ) )
F_47 ( & V_12 -> V_20 ) ;
F_10 ( & V_12 -> V_14 ) ;
return V_57 ;
}
void F_48 ( struct V_6 * V_7 ,
struct V_2 * V_63 ,
struct V_2 * V_64 ,
int V_61 )
{
F_13 ( F_29 ( V_41 , & V_63 -> V_15 ) ) ;
ASSERT ( F_16 ( V_63 ) ) ;
if ( ! F_29 ( V_43 , & V_63 -> V_15 ) )
F_47 ( & V_63 -> V_20 ) ;
F_49 ( & V_63 -> V_14 , & V_64 -> V_14 , & V_7 -> V_8 ) ;
F_10 ( & V_63 -> V_14 ) ;
F_41 ( V_7 , V_64 , V_61 ) ;
}
