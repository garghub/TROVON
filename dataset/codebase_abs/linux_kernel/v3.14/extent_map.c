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
static T_2 F_17 ( T_2 V_21 , T_2 V_22 )
{
if ( V_21 + V_22 < V_21 )
return ( T_2 ) - 1 ;
return V_21 + V_22 ;
}
static int F_18 ( struct V_23 * V_24 , struct V_2 * V_12 )
{
struct V_25 * * V_26 = & V_24 -> V_25 ;
struct V_25 * V_27 = NULL ;
struct V_2 * V_28 = NULL ;
struct V_25 * V_29 = NULL ;
T_2 V_30 = F_17 ( V_12 -> V_21 , V_12 -> V_22 ) ;
while ( * V_26 ) {
V_27 = * V_26 ;
V_28 = F_19 ( V_27 , struct V_2 , V_25 ) ;
F_12 ( ! V_28 -> V_14 ) ;
if ( V_12 -> V_21 < V_28 -> V_21 )
V_26 = & ( * V_26 ) -> V_31 ;
else if ( V_12 -> V_21 >= F_20 ( V_28 ) )
V_26 = & ( * V_26 ) -> V_32 ;
else
return - V_33 ;
}
V_29 = V_27 ;
while ( V_27 && V_12 -> V_21 >= F_20 ( V_28 ) ) {
V_27 = F_21 ( V_27 ) ;
V_28 = F_19 ( V_27 , struct V_2 , V_25 ) ;
}
if ( V_27 )
if ( V_30 > V_28 -> V_21 && V_12 -> V_21 < F_20 ( V_28 ) )
return - V_33 ;
V_27 = V_29 ;
V_28 = F_19 ( V_27 , struct V_2 , V_25 ) ;
while ( V_27 && V_12 -> V_21 < V_28 -> V_21 ) {
V_27 = F_22 ( V_27 ) ;
V_28 = F_19 ( V_27 , struct V_2 , V_25 ) ;
}
if ( V_27 )
if ( V_30 > V_28 -> V_21 && V_12 -> V_21 < F_20 ( V_28 ) )
return - V_33 ;
V_12 -> V_14 = 1 ;
F_23 ( & V_12 -> V_25 , V_29 , V_26 ) ;
F_24 ( & V_12 -> V_25 , V_24 ) ;
return 0 ;
}
static struct V_25 * F_25 ( struct V_23 * V_24 , T_2 V_34 ,
struct V_25 * * V_35 ,
struct V_25 * * V_36 )
{
struct V_25 * V_37 = V_24 -> V_25 ;
struct V_25 * V_38 = NULL ;
struct V_25 * V_39 = NULL ;
struct V_2 * V_28 ;
struct V_2 * V_40 = NULL ;
while ( V_37 ) {
V_28 = F_19 ( V_37 , struct V_2 , V_25 ) ;
V_38 = V_37 ;
V_40 = V_28 ;
F_12 ( ! V_28 -> V_14 ) ;
if ( V_34 < V_28 -> V_21 )
V_37 = V_37 -> V_31 ;
else if ( V_34 >= F_20 ( V_28 ) )
V_37 = V_37 -> V_32 ;
else
return V_37 ;
}
if ( V_35 ) {
V_39 = V_38 ;
while ( V_38 && V_34 >= F_20 ( V_40 ) ) {
V_38 = F_21 ( V_38 ) ;
V_40 = F_19 ( V_38 , struct V_2 , V_25 ) ;
}
* V_35 = V_38 ;
V_38 = V_39 ;
}
if ( V_36 ) {
V_40 = F_19 ( V_38 , struct V_2 , V_25 ) ;
while ( V_38 && V_34 < V_40 -> V_21 ) {
V_38 = F_22 ( V_38 ) ;
V_40 = F_19 ( V_38 , struct V_2 , V_25 ) ;
}
* V_36 = V_38 ;
}
return NULL ;
}
static int F_26 ( struct V_2 * V_38 , struct V_2 * V_41 )
{
if ( F_27 ( V_42 , & V_38 -> V_15 ) )
return 0 ;
if ( F_27 ( V_43 , & V_38 -> V_15 ) )
return 0 ;
if ( F_27 ( V_44 , & V_38 -> V_15 ) ||
F_27 ( V_44 , & V_41 -> V_15 ) )
return 0 ;
if ( ! F_15 ( & V_38 -> V_20 ) || ! F_15 ( & V_41 -> V_20 ) )
return 0 ;
if ( F_20 ( V_38 ) == V_41 -> V_21 &&
V_38 -> V_15 == V_41 -> V_15 &&
V_38 -> V_45 == V_41 -> V_45 &&
( ( V_41 -> V_46 == V_47 &&
V_38 -> V_46 == V_47 ) ||
( V_41 -> V_46 == V_48 &&
V_38 -> V_46 == V_48 ) ||
( V_41 -> V_46 == V_49 &&
V_38 -> V_46 == V_49 ) ||
( V_41 -> V_46 < V_50 - 1 &&
V_41 -> V_46 == F_28 ( V_38 ) ) ) ) {
return 1 ;
}
return 0 ;
}
static void F_29 ( struct V_6 * V_7 , struct V_2 * V_12 )
{
struct V_2 * V_51 = NULL ;
struct V_25 * V_52 ;
if ( V_12 -> V_21 != 0 ) {
V_52 = F_22 ( & V_12 -> V_25 ) ;
if ( V_52 )
V_51 = F_19 ( V_52 , struct V_2 , V_25 ) ;
if ( V_52 && F_26 ( V_51 , V_12 ) ) {
V_12 -> V_21 = V_51 -> V_21 ;
V_12 -> V_53 = V_51 -> V_53 ;
V_12 -> V_22 += V_51 -> V_22 ;
V_12 -> V_54 += V_51 -> V_54 ;
V_12 -> V_46 = V_51 -> V_46 ;
V_51 -> V_14 = 0 ;
V_12 -> V_55 = ( V_12 -> V_55 + V_12 -> V_56 ) - V_51 -> V_56 ;
V_12 -> V_56 = V_51 -> V_56 ;
V_12 -> V_18 = F_30 ( V_12 -> V_18 , V_51 -> V_18 ) ;
F_31 ( & V_51 -> V_25 , & V_7 -> V_8 ) ;
F_11 ( V_51 ) ;
}
}
V_52 = F_21 ( & V_12 -> V_25 ) ;
if ( V_52 )
V_51 = F_19 ( V_52 , struct V_2 , V_25 ) ;
if ( V_52 && F_26 ( V_12 , V_51 ) ) {
V_12 -> V_22 += V_51 -> V_22 ;
V_12 -> V_54 += V_51 -> V_54 ;
F_31 ( & V_51 -> V_25 , & V_7 -> V_8 ) ;
V_51 -> V_14 = 0 ;
V_12 -> V_55 = ( V_51 -> V_56 + V_51 -> V_55 ) - V_12 -> V_56 ;
V_12 -> V_18 = F_30 ( V_12 -> V_18 , V_51 -> V_18 ) ;
F_11 ( V_51 ) ;
}
}
int F_32 ( struct V_6 * V_7 , T_2 V_21 , T_2 V_22 ,
T_2 V_57 )
{
int V_58 = 0 ;
struct V_2 * V_12 ;
bool V_59 = false ;
F_33 ( & V_7 -> V_11 ) ;
V_12 = F_34 ( V_7 , V_21 , V_22 ) ;
F_12 ( ! V_12 || V_12 -> V_21 != V_21 ) ;
if ( ! V_12 )
goto V_60;
if ( ! F_27 ( V_44 , & V_12 -> V_15 ) )
F_35 ( & V_12 -> V_20 , & V_7 -> V_10 ) ;
V_12 -> V_18 = V_57 ;
F_36 ( V_42 , & V_12 -> V_15 ) ;
V_12 -> V_56 = V_12 -> V_21 ;
V_12 -> V_55 = V_12 -> V_22 ;
if ( F_27 ( V_61 , & V_12 -> V_15 ) ) {
V_59 = true ;
F_36 ( V_61 , & V_12 -> V_15 ) ;
}
F_29 ( V_7 , V_12 ) ;
if ( V_59 ) {
V_12 -> V_56 = V_12 -> V_21 ;
V_12 -> V_55 = V_12 -> V_22 ;
}
F_11 ( V_12 ) ;
V_60:
F_37 ( & V_7 -> V_11 ) ;
return V_58 ;
}
void F_38 ( struct V_6 * V_7 , struct V_2 * V_12 )
{
F_36 ( V_44 , & V_12 -> V_15 ) ;
if ( V_12 -> V_14 )
F_29 ( V_7 , V_12 ) ;
}
int F_39 ( struct V_6 * V_7 ,
struct V_2 * V_12 , int V_62 )
{
int V_58 = 0 ;
V_58 = F_18 ( & V_7 -> V_8 , V_12 ) ;
if ( V_58 )
goto V_60;
F_40 ( & V_12 -> V_19 ) ;
V_12 -> V_56 = V_12 -> V_21 ;
V_12 -> V_55 = V_12 -> V_22 ;
if ( V_62 )
F_35 ( & V_12 -> V_20 , & V_7 -> V_10 ) ;
else
F_29 ( V_7 , V_12 ) ;
V_60:
return V_58 ;
}
static struct V_2 *
F_41 ( struct V_6 * V_7 ,
T_2 V_21 , T_2 V_22 , int V_63 )
{
struct V_2 * V_12 ;
struct V_25 * V_25 ;
struct V_25 * V_38 = NULL ;
struct V_25 * V_41 = NULL ;
T_2 V_30 = F_17 ( V_21 , V_22 ) ;
V_25 = F_25 ( & V_7 -> V_8 , V_21 , & V_38 , & V_41 ) ;
if ( ! V_25 ) {
if ( V_38 )
V_25 = V_38 ;
else if ( V_41 )
V_25 = V_41 ;
else
return NULL ;
}
V_12 = F_19 ( V_25 , struct V_2 , V_25 ) ;
if ( V_63 && ! ( V_30 > V_12 -> V_21 && V_21 < F_20 ( V_12 ) ) )
return NULL ;
F_40 ( & V_12 -> V_19 ) ;
return V_12 ;
}
struct V_2 * F_34 ( struct V_6 * V_7 ,
T_2 V_21 , T_2 V_22 )
{
return F_41 ( V_7 , V_21 , V_22 , 1 ) ;
}
struct V_2 * F_42 ( struct V_6 * V_7 ,
T_2 V_21 , T_2 V_22 )
{
return F_41 ( V_7 , V_21 , V_22 , 0 ) ;
}
int F_43 ( struct V_6 * V_7 , struct V_2 * V_12 )
{
int V_58 = 0 ;
F_12 ( F_27 ( V_42 , & V_12 -> V_15 ) ) ;
F_31 ( & V_12 -> V_25 , & V_7 -> V_8 ) ;
if ( ! F_27 ( V_44 , & V_12 -> V_15 ) )
F_44 ( & V_12 -> V_20 ) ;
V_12 -> V_14 = 0 ;
return V_58 ;
}
