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
if ( F_18 ( V_21 , & V_12 -> V_15 ) )
F_19 ( V_12 -> V_22 ) ;
F_20 ( V_1 , V_12 ) ;
}
}
static T_2 F_21 ( T_2 V_23 , T_2 V_24 )
{
if ( V_23 + V_24 < V_23 )
return ( T_2 ) - 1 ;
return V_23 + V_24 ;
}
static int F_22 ( struct V_25 * V_26 , struct V_2 * V_12 )
{
struct V_14 * * V_27 = & V_26 -> V_14 ;
struct V_14 * V_28 = NULL ;
struct V_2 * V_29 = NULL ;
struct V_14 * V_30 = NULL ;
T_2 V_31 = F_21 ( V_12 -> V_23 , V_12 -> V_24 ) ;
while ( * V_27 ) {
V_28 = * V_27 ;
V_29 = F_23 ( V_28 , struct V_2 , V_14 ) ;
if ( V_12 -> V_23 < V_29 -> V_23 )
V_27 = & ( * V_27 ) -> V_32 ;
else if ( V_12 -> V_23 >= F_24 ( V_29 ) )
V_27 = & ( * V_27 ) -> V_33 ;
else
return - V_34 ;
}
V_30 = V_28 ;
while ( V_28 && V_12 -> V_23 >= F_24 ( V_29 ) ) {
V_28 = F_25 ( V_28 ) ;
V_29 = F_23 ( V_28 , struct V_2 , V_14 ) ;
}
if ( V_28 )
if ( V_31 > V_29 -> V_23 && V_12 -> V_23 < F_24 ( V_29 ) )
return - V_34 ;
V_28 = V_30 ;
V_29 = F_23 ( V_28 , struct V_2 , V_14 ) ;
while ( V_28 && V_12 -> V_23 < V_29 -> V_23 ) {
V_28 = F_26 ( V_28 ) ;
V_29 = F_23 ( V_28 , struct V_2 , V_14 ) ;
}
if ( V_28 )
if ( V_31 > V_29 -> V_23 && V_12 -> V_23 < F_24 ( V_29 ) )
return - V_34 ;
F_27 ( & V_12 -> V_14 , V_30 , V_27 ) ;
F_28 ( & V_12 -> V_14 , V_26 ) ;
return 0 ;
}
static struct V_14 * F_29 ( struct V_25 * V_26 , T_2 V_35 ,
struct V_14 * * V_36 ,
struct V_14 * * V_37 )
{
struct V_14 * V_38 = V_26 -> V_14 ;
struct V_14 * V_39 = NULL ;
struct V_14 * V_40 = NULL ;
struct V_2 * V_29 ;
struct V_2 * V_41 = NULL ;
while ( V_38 ) {
V_29 = F_23 ( V_38 , struct V_2 , V_14 ) ;
V_39 = V_38 ;
V_41 = V_29 ;
if ( V_35 < V_29 -> V_23 )
V_38 = V_38 -> V_32 ;
else if ( V_35 >= F_24 ( V_29 ) )
V_38 = V_38 -> V_33 ;
else
return V_38 ;
}
if ( V_36 ) {
V_40 = V_39 ;
while ( V_39 && V_35 >= F_24 ( V_41 ) ) {
V_39 = F_25 ( V_39 ) ;
V_41 = F_23 ( V_39 , struct V_2 , V_14 ) ;
}
* V_36 = V_39 ;
V_39 = V_40 ;
}
if ( V_37 ) {
V_41 = F_23 ( V_39 , struct V_2 , V_14 ) ;
while ( V_39 && V_35 < V_41 -> V_23 ) {
V_39 = F_26 ( V_39 ) ;
V_41 = F_23 ( V_39 , struct V_2 , V_14 ) ;
}
* V_37 = V_39 ;
}
return NULL ;
}
static int F_30 ( struct V_2 * V_39 , struct V_2 * V_42 )
{
if ( F_18 ( V_43 , & V_39 -> V_15 ) )
return 0 ;
if ( F_18 ( V_44 , & V_39 -> V_15 ) )
return 0 ;
if ( F_18 ( V_45 , & V_39 -> V_15 ) ||
F_18 ( V_45 , & V_42 -> V_15 ) )
return 0 ;
if ( ! F_17 ( & V_39 -> V_20 ) || ! F_17 ( & V_42 -> V_20 ) )
return 0 ;
if ( F_24 ( V_39 ) == V_42 -> V_23 &&
V_39 -> V_15 == V_42 -> V_15 &&
V_39 -> V_46 == V_42 -> V_46 &&
( ( V_42 -> V_47 == V_48 &&
V_39 -> V_47 == V_48 ) ||
( V_42 -> V_47 == V_49 &&
V_39 -> V_47 == V_49 ) ||
( V_42 -> V_47 == V_50 &&
V_39 -> V_47 == V_50 ) ||
( V_42 -> V_47 < V_51 - 1 &&
V_42 -> V_47 == F_31 ( V_39 ) ) ) ) {
return 1 ;
}
return 0 ;
}
static void F_32 ( struct V_6 * V_7 , struct V_2 * V_12 )
{
struct V_2 * V_52 = NULL ;
struct V_14 * V_53 ;
if ( V_12 -> V_23 != 0 ) {
V_53 = F_26 ( & V_12 -> V_14 ) ;
if ( V_53 )
V_52 = F_23 ( V_53 , struct V_2 , V_14 ) ;
if ( V_53 && F_30 ( V_52 , V_12 ) ) {
V_12 -> V_23 = V_52 -> V_23 ;
V_12 -> V_54 = V_52 -> V_54 ;
V_12 -> V_24 += V_52 -> V_24 ;
V_12 -> V_55 += V_52 -> V_55 ;
V_12 -> V_47 = V_52 -> V_47 ;
V_12 -> V_56 = ( V_12 -> V_56 + V_12 -> V_57 ) - V_52 -> V_57 ;
V_12 -> V_57 = V_52 -> V_57 ;
V_12 -> V_18 = F_33 ( V_12 -> V_18 , V_52 -> V_18 ) ;
F_34 ( & V_52 -> V_14 , & V_7 -> V_8 ) ;
F_10 ( & V_52 -> V_14 ) ;
F_12 ( V_52 ) ;
}
}
V_53 = F_25 ( & V_12 -> V_14 ) ;
if ( V_53 )
V_52 = F_23 ( V_53 , struct V_2 , V_14 ) ;
if ( V_53 && F_30 ( V_12 , V_52 ) ) {
V_12 -> V_24 += V_52 -> V_24 ;
V_12 -> V_55 += V_52 -> V_55 ;
F_34 ( & V_52 -> V_14 , & V_7 -> V_8 ) ;
F_10 ( & V_52 -> V_14 ) ;
V_12 -> V_56 = ( V_52 -> V_57 + V_52 -> V_56 ) - V_12 -> V_57 ;
V_12 -> V_18 = F_33 ( V_12 -> V_18 , V_52 -> V_18 ) ;
F_12 ( V_52 ) ;
}
}
int F_35 ( struct V_6 * V_7 , T_2 V_23 , T_2 V_24 ,
T_2 V_58 )
{
int V_59 = 0 ;
struct V_2 * V_12 ;
bool V_60 = false ;
F_36 ( & V_7 -> V_11 ) ;
V_12 = F_37 ( V_7 , V_23 , V_24 ) ;
F_13 ( ! V_12 || V_12 -> V_23 != V_23 ) ;
if ( ! V_12 )
goto V_61;
V_12 -> V_18 = V_58 ;
F_38 ( V_43 , & V_12 -> V_15 ) ;
V_12 -> V_57 = V_12 -> V_23 ;
V_12 -> V_56 = V_12 -> V_24 ;
if ( F_18 ( V_62 , & V_12 -> V_15 ) ) {
V_60 = true ;
F_38 ( V_62 , & V_12 -> V_15 ) ;
}
F_32 ( V_7 , V_12 ) ;
if ( V_60 ) {
V_12 -> V_57 = V_12 -> V_23 ;
V_12 -> V_56 = V_12 -> V_24 ;
}
F_12 ( V_12 ) ;
V_61:
F_39 ( & V_7 -> V_11 ) ;
return V_59 ;
}
void F_40 ( struct V_6 * V_7 , struct V_2 * V_12 )
{
F_38 ( V_45 , & V_12 -> V_15 ) ;
if ( F_16 ( V_12 ) )
F_32 ( V_7 , V_12 ) ;
}
static inline void F_41 ( struct V_6 * V_7 ,
struct V_2 * V_12 ,
int V_63 )
{
F_42 ( & V_12 -> V_19 ) ;
V_12 -> V_57 = V_12 -> V_23 ;
V_12 -> V_56 = V_12 -> V_24 ;
if ( V_63 )
F_43 ( & V_12 -> V_20 , & V_7 -> V_10 ) ;
else
F_32 ( V_7 , V_12 ) ;
}
int F_44 ( struct V_6 * V_7 ,
struct V_2 * V_12 , int V_63 )
{
int V_59 = 0 ;
V_59 = F_22 ( & V_7 -> V_8 , V_12 ) ;
if ( V_59 )
goto V_61;
F_41 ( V_7 , V_12 , V_63 ) ;
V_61:
return V_59 ;
}
static struct V_2 *
F_45 ( struct V_6 * V_7 ,
T_2 V_23 , T_2 V_24 , int V_64 )
{
struct V_2 * V_12 ;
struct V_14 * V_14 ;
struct V_14 * V_39 = NULL ;
struct V_14 * V_42 = NULL ;
T_2 V_31 = F_21 ( V_23 , V_24 ) ;
V_14 = F_29 ( & V_7 -> V_8 , V_23 , & V_39 , & V_42 ) ;
if ( ! V_14 ) {
if ( V_39 )
V_14 = V_39 ;
else if ( V_42 )
V_14 = V_42 ;
else
return NULL ;
}
V_12 = F_23 ( V_14 , struct V_2 , V_14 ) ;
if ( V_64 && ! ( V_31 > V_12 -> V_23 && V_23 < F_24 ( V_12 ) ) )
return NULL ;
F_42 ( & V_12 -> V_19 ) ;
return V_12 ;
}
struct V_2 * F_37 ( struct V_6 * V_7 ,
T_2 V_23 , T_2 V_24 )
{
return F_45 ( V_7 , V_23 , V_24 , 1 ) ;
}
struct V_2 * F_46 ( struct V_6 * V_7 ,
T_2 V_23 , T_2 V_24 )
{
return F_45 ( V_7 , V_23 , V_24 , 0 ) ;
}
int F_47 ( struct V_6 * V_7 , struct V_2 * V_12 )
{
int V_59 = 0 ;
F_13 ( F_18 ( V_43 , & V_12 -> V_15 ) ) ;
F_34 ( & V_12 -> V_14 , & V_7 -> V_8 ) ;
if ( ! F_18 ( V_45 , & V_12 -> V_15 ) )
F_48 ( & V_12 -> V_20 ) ;
F_10 ( & V_12 -> V_14 ) ;
return V_59 ;
}
void F_49 ( struct V_6 * V_7 ,
struct V_2 * V_65 ,
struct V_2 * V_66 ,
int V_63 )
{
F_13 ( F_18 ( V_43 , & V_65 -> V_15 ) ) ;
ASSERT ( F_16 ( V_65 ) ) ;
if ( ! F_18 ( V_45 , & V_65 -> V_15 ) )
F_48 ( & V_65 -> V_20 ) ;
F_50 ( & V_65 -> V_14 , & V_66 -> V_14 , & V_7 -> V_8 ) ;
F_10 ( & V_65 -> V_14 ) ;
F_41 ( V_7 , V_66 , V_63 ) ;
}
