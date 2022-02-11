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
V_12 -> V_14 = 0 ;
V_12 -> V_15 = 0 ;
V_12 -> V_16 = V_17 ;
V_12 -> V_18 = 0 ;
F_10 ( & V_12 -> V_19 , 1 ) ;
F_6 ( & V_12 -> V_20 ) ;
return V_12 ;
}
void F_11 ( struct V_2 * V_12 )
{
if ( ! V_12 )
return;
F_12 ( F_13 ( & V_12 -> V_19 ) == 0 ) ;
if ( F_14 ( & V_12 -> V_19 ) ) {
F_12 ( V_12 -> V_14 ) ;
F_12 ( ! F_15 ( & V_12 -> V_20 ) ) ;
F_16 ( V_1 , V_12 ) ;
}
}
static struct V_21 * F_17 ( struct V_22 * V_23 , T_2 V_24 ,
struct V_21 * V_25 )
{
struct V_21 * * V_26 = & V_23 -> V_21 ;
struct V_21 * V_27 = NULL ;
struct V_2 * V_28 ;
while ( * V_26 ) {
V_27 = * V_26 ;
V_28 = F_18 ( V_27 , struct V_2 , V_21 ) ;
F_12 ( ! V_28 -> V_14 ) ;
if ( V_24 < V_28 -> V_29 )
V_26 = & ( * V_26 ) -> V_30 ;
else if ( V_24 >= F_19 ( V_28 ) )
V_26 = & ( * V_26 ) -> V_31 ;
else
return V_27 ;
}
V_28 = F_18 ( V_25 , struct V_2 , V_21 ) ;
V_28 -> V_14 = 1 ;
F_20 ( V_25 , V_27 , V_26 ) ;
F_21 ( V_25 , V_23 ) ;
return NULL ;
}
static struct V_21 * F_22 ( struct V_22 * V_23 , T_2 V_24 ,
struct V_21 * * V_32 ,
struct V_21 * * V_33 )
{
struct V_21 * V_34 = V_23 -> V_21 ;
struct V_21 * V_35 = NULL ;
struct V_21 * V_36 = NULL ;
struct V_2 * V_28 ;
struct V_2 * V_37 = NULL ;
while ( V_34 ) {
V_28 = F_18 ( V_34 , struct V_2 , V_21 ) ;
V_35 = V_34 ;
V_37 = V_28 ;
F_12 ( ! V_28 -> V_14 ) ;
if ( V_24 < V_28 -> V_29 )
V_34 = V_34 -> V_30 ;
else if ( V_24 >= F_19 ( V_28 ) )
V_34 = V_34 -> V_31 ;
else
return V_34 ;
}
if ( V_32 ) {
V_36 = V_35 ;
while ( V_35 && V_24 >= F_19 ( V_37 ) ) {
V_35 = F_23 ( V_35 ) ;
V_37 = F_18 ( V_35 , struct V_2 , V_21 ) ;
}
* V_32 = V_35 ;
V_35 = V_36 ;
}
if ( V_33 ) {
V_37 = F_18 ( V_35 , struct V_2 , V_21 ) ;
while ( V_35 && V_24 < V_37 -> V_29 ) {
V_35 = F_24 ( V_35 ) ;
V_37 = F_18 ( V_35 , struct V_2 , V_21 ) ;
}
* V_33 = V_35 ;
}
return NULL ;
}
static int F_25 ( struct V_2 * V_35 , struct V_2 * V_38 )
{
if ( F_26 ( V_39 , & V_35 -> V_15 ) )
return 0 ;
if ( F_26 ( V_40 , & V_35 -> V_15 ) )
return 0 ;
if ( F_26 ( V_41 , & V_35 -> V_15 ) ||
F_26 ( V_41 , & V_38 -> V_15 ) )
return 0 ;
if ( ! F_15 ( & V_35 -> V_20 ) || ! F_15 ( & V_38 -> V_20 ) )
return 0 ;
if ( F_19 ( V_35 ) == V_38 -> V_29 &&
V_35 -> V_15 == V_38 -> V_15 &&
V_35 -> V_42 == V_38 -> V_42 &&
( ( V_38 -> V_43 == V_44 &&
V_35 -> V_43 == V_44 ) ||
( V_38 -> V_43 == V_45 &&
V_35 -> V_43 == V_45 ) ||
( V_38 -> V_43 == V_46 &&
V_35 -> V_43 == V_46 ) ||
( V_38 -> V_43 < V_47 - 1 &&
V_38 -> V_43 == F_27 ( V_35 ) ) ) ) {
return 1 ;
}
return 0 ;
}
static void F_28 ( struct V_6 * V_7 , struct V_2 * V_12 )
{
struct V_2 * V_48 = NULL ;
struct V_21 * V_49 ;
if ( V_12 -> V_29 != 0 ) {
V_49 = F_24 ( & V_12 -> V_21 ) ;
if ( V_49 )
V_48 = F_18 ( V_49 , struct V_2 , V_21 ) ;
if ( V_49 && F_25 ( V_48 , V_12 ) ) {
V_12 -> V_29 = V_48 -> V_29 ;
V_12 -> V_50 = V_48 -> V_50 ;
V_12 -> V_51 += V_48 -> V_51 ;
V_12 -> V_52 += V_48 -> V_52 ;
V_12 -> V_43 = V_48 -> V_43 ;
V_48 -> V_14 = 0 ;
V_12 -> V_53 = ( V_12 -> V_53 + V_12 -> V_54 ) - V_48 -> V_54 ;
V_12 -> V_54 = V_48 -> V_54 ;
V_12 -> V_18 = F_29 ( V_12 -> V_18 , V_48 -> V_18 ) ;
F_30 ( & V_48 -> V_21 , & V_7 -> V_8 ) ;
F_11 ( V_48 ) ;
}
}
V_49 = F_23 ( & V_12 -> V_21 ) ;
if ( V_49 )
V_48 = F_18 ( V_49 , struct V_2 , V_21 ) ;
if ( V_49 && F_25 ( V_12 , V_48 ) ) {
V_12 -> V_51 += V_48 -> V_51 ;
V_12 -> V_52 += V_48 -> V_51 ;
F_30 ( & V_48 -> V_21 , & V_7 -> V_8 ) ;
V_48 -> V_14 = 0 ;
V_12 -> V_53 = ( V_48 -> V_54 + V_48 -> V_53 ) - V_12 -> V_54 ;
V_12 -> V_18 = F_29 ( V_12 -> V_18 , V_48 -> V_18 ) ;
F_11 ( V_48 ) ;
}
}
int F_31 ( struct V_6 * V_7 , T_2 V_29 , T_2 V_51 ,
T_2 V_55 )
{
int V_56 = 0 ;
struct V_2 * V_12 ;
bool V_57 = false ;
F_32 ( & V_7 -> V_11 ) ;
V_12 = F_33 ( V_7 , V_29 , V_51 ) ;
F_12 ( ! V_12 || V_12 -> V_29 != V_29 ) ;
if ( ! V_12 )
goto V_58;
if ( ! F_26 ( V_41 , & V_12 -> V_15 ) )
F_34 ( & V_12 -> V_20 , & V_7 -> V_10 ) ;
V_12 -> V_18 = V_55 ;
F_35 ( V_39 , & V_12 -> V_15 ) ;
V_12 -> V_54 = V_12 -> V_29 ;
V_12 -> V_53 = V_12 -> V_51 ;
if ( F_26 ( V_59 , & V_12 -> V_15 ) ) {
V_57 = true ;
F_35 ( V_59 , & V_12 -> V_15 ) ;
}
F_28 ( V_7 , V_12 ) ;
if ( V_57 ) {
V_12 -> V_54 = V_12 -> V_29 ;
V_12 -> V_53 = V_12 -> V_51 ;
}
F_11 ( V_12 ) ;
V_58:
F_36 ( & V_7 -> V_11 ) ;
return V_56 ;
}
void F_37 ( struct V_6 * V_7 , struct V_2 * V_12 )
{
F_35 ( V_41 , & V_12 -> V_15 ) ;
if ( V_12 -> V_14 )
F_28 ( V_7 , V_12 ) ;
}
int F_38 ( struct V_6 * V_7 ,
struct V_2 * V_12 , int V_60 )
{
int V_56 = 0 ;
struct V_21 * V_49 ;
struct V_2 * V_61 ;
V_61 = F_33 ( V_7 , V_12 -> V_29 , V_12 -> V_51 ) ;
if ( V_61 ) {
F_11 ( V_61 ) ;
V_56 = - V_62 ;
goto V_58;
}
V_49 = F_17 ( & V_7 -> V_8 , V_12 -> V_29 , & V_12 -> V_21 ) ;
if ( V_49 ) {
V_56 = - V_62 ;
goto V_58;
}
F_39 ( & V_12 -> V_19 ) ;
V_12 -> V_54 = V_12 -> V_29 ;
V_12 -> V_53 = V_12 -> V_51 ;
if ( V_60 )
F_34 ( & V_12 -> V_20 , & V_7 -> V_10 ) ;
else
F_28 ( V_7 , V_12 ) ;
V_58:
return V_56 ;
}
static T_2 F_40 ( T_2 V_29 , T_2 V_51 )
{
if ( V_29 + V_51 < V_29 )
return ( T_2 ) - 1 ;
return V_29 + V_51 ;
}
static struct V_2 *
F_41 ( struct V_6 * V_7 ,
T_2 V_29 , T_2 V_51 , int V_63 )
{
struct V_2 * V_12 ;
struct V_21 * V_21 ;
struct V_21 * V_35 = NULL ;
struct V_21 * V_38 = NULL ;
T_2 V_64 = F_40 ( V_29 , V_51 ) ;
V_21 = F_22 ( & V_7 -> V_8 , V_29 , & V_35 , & V_38 ) ;
if ( ! V_21 ) {
if ( V_35 )
V_21 = V_35 ;
else if ( V_38 )
V_21 = V_38 ;
else
return NULL ;
}
V_12 = F_18 ( V_21 , struct V_2 , V_21 ) ;
if ( V_63 && ! ( V_64 > V_12 -> V_29 && V_29 < F_19 ( V_12 ) ) )
return NULL ;
F_39 ( & V_12 -> V_19 ) ;
return V_12 ;
}
struct V_2 * F_33 ( struct V_6 * V_7 ,
T_2 V_29 , T_2 V_51 )
{
return F_41 ( V_7 , V_29 , V_51 , 1 ) ;
}
struct V_2 * F_42 ( struct V_6 * V_7 ,
T_2 V_29 , T_2 V_51 )
{
return F_41 ( V_7 , V_29 , V_51 , 0 ) ;
}
int F_43 ( struct V_6 * V_7 , struct V_2 * V_12 )
{
int V_56 = 0 ;
F_12 ( F_26 ( V_39 , & V_12 -> V_15 ) ) ;
F_30 ( & V_12 -> V_21 , & V_7 -> V_8 ) ;
if ( ! F_26 ( V_41 , & V_12 -> V_15 ) )
F_44 ( & V_12 -> V_20 ) ;
V_12 -> V_14 = 0 ;
return V_56 ;
}
