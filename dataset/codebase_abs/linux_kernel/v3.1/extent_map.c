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
}
struct V_2 * F_7 ( void )
{
struct V_2 * V_11 ;
V_11 = F_8 ( V_1 , V_12 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_13 = 0 ;
V_11 -> V_14 = 0 ;
V_11 -> V_15 = V_16 ;
F_9 ( & V_11 -> V_17 , 1 ) ;
return V_11 ;
}
void F_10 ( struct V_2 * V_11 )
{
if ( ! V_11 )
return;
F_11 ( F_12 ( & V_11 -> V_17 ) == 0 ) ;
if ( F_13 ( & V_11 -> V_17 ) ) {
F_11 ( V_11 -> V_13 ) ;
F_14 ( V_1 , V_11 ) ;
}
}
static struct V_18 * F_15 ( struct V_19 * V_20 , T_2 V_21 ,
struct V_18 * V_22 )
{
struct V_18 * * V_23 = & V_20 -> V_18 ;
struct V_18 * V_24 = NULL ;
struct V_2 * V_25 ;
while ( * V_23 ) {
V_24 = * V_23 ;
V_25 = F_16 ( V_24 , struct V_2 , V_18 ) ;
F_11 ( ! V_25 -> V_13 ) ;
if ( V_21 < V_25 -> V_26 )
V_23 = & ( * V_23 ) -> V_27 ;
else if ( V_21 >= F_17 ( V_25 ) )
V_23 = & ( * V_23 ) -> V_28 ;
else
return V_24 ;
}
V_25 = F_16 ( V_22 , struct V_2 , V_18 ) ;
V_25 -> V_13 = 1 ;
F_18 ( V_22 , V_24 , V_23 ) ;
F_19 ( V_22 , V_20 ) ;
return NULL ;
}
static struct V_18 * F_20 ( struct V_19 * V_20 , T_2 V_21 ,
struct V_18 * * V_29 ,
struct V_18 * * V_30 )
{
struct V_18 * V_31 = V_20 -> V_18 ;
struct V_18 * V_32 = NULL ;
struct V_18 * V_33 = NULL ;
struct V_2 * V_25 ;
struct V_2 * V_34 = NULL ;
while ( V_31 ) {
V_25 = F_16 ( V_31 , struct V_2 , V_18 ) ;
V_32 = V_31 ;
V_34 = V_25 ;
F_11 ( ! V_25 -> V_13 ) ;
if ( V_21 < V_25 -> V_26 )
V_31 = V_31 -> V_27 ;
else if ( V_21 >= F_17 ( V_25 ) )
V_31 = V_31 -> V_28 ;
else
return V_31 ;
}
if ( V_29 ) {
V_33 = V_32 ;
while ( V_32 && V_21 >= F_17 ( V_34 ) ) {
V_32 = F_21 ( V_32 ) ;
V_34 = F_16 ( V_32 , struct V_2 , V_18 ) ;
}
* V_29 = V_32 ;
V_32 = V_33 ;
}
if ( V_30 ) {
V_34 = F_16 ( V_32 , struct V_2 , V_18 ) ;
while ( V_32 && V_21 < V_34 -> V_26 ) {
V_32 = F_22 ( V_32 ) ;
V_34 = F_16 ( V_32 , struct V_2 , V_18 ) ;
}
* V_30 = V_32 ;
}
return NULL ;
}
static int F_23 ( struct V_2 * V_32 , struct V_2 * V_35 )
{
if ( F_24 ( V_36 , & V_32 -> V_14 ) )
return 0 ;
if ( F_24 ( V_37 , & V_32 -> V_14 ) )
return 0 ;
if ( F_17 ( V_32 ) == V_35 -> V_26 &&
V_32 -> V_14 == V_35 -> V_14 &&
V_32 -> V_38 == V_35 -> V_38 &&
( ( V_35 -> V_39 == V_40 &&
V_32 -> V_39 == V_40 ) ||
( V_35 -> V_39 == V_41 &&
V_32 -> V_39 == V_41 ) ||
( V_35 -> V_39 == V_42 &&
V_32 -> V_39 == V_42 ) ||
( V_35 -> V_39 < V_43 - 1 &&
V_35 -> V_39 == F_25 ( V_32 ) ) ) ) {
return 1 ;
}
return 0 ;
}
static void F_26 ( struct V_6 * V_7 , struct V_2 * V_11 )
{
struct V_2 * V_44 = NULL ;
struct V_18 * V_45 ;
if ( V_11 -> V_26 != 0 ) {
V_45 = F_22 ( & V_11 -> V_18 ) ;
if ( V_45 )
V_44 = F_16 ( V_45 , struct V_2 , V_18 ) ;
if ( V_45 && F_23 ( V_44 , V_11 ) ) {
V_11 -> V_26 = V_44 -> V_26 ;
V_11 -> V_46 += V_44 -> V_46 ;
V_11 -> V_47 += V_44 -> V_47 ;
V_11 -> V_39 = V_44 -> V_39 ;
V_44 -> V_13 = 0 ;
F_27 ( & V_44 -> V_18 , & V_7 -> V_8 ) ;
F_10 ( V_44 ) ;
}
}
V_45 = F_21 ( & V_11 -> V_18 ) ;
if ( V_45 )
V_44 = F_16 ( V_45 , struct V_2 , V_18 ) ;
if ( V_45 && F_23 ( V_11 , V_44 ) ) {
V_11 -> V_46 += V_44 -> V_46 ;
V_11 -> V_47 += V_44 -> V_46 ;
F_27 ( & V_44 -> V_18 , & V_7 -> V_8 ) ;
V_44 -> V_13 = 0 ;
F_10 ( V_44 ) ;
}
}
int F_28 ( struct V_6 * V_7 , T_2 V_26 , T_2 V_46 )
{
int V_48 = 0 ;
struct V_2 * V_11 ;
F_29 ( & V_7 -> V_10 ) ;
V_11 = F_30 ( V_7 , V_26 , V_46 ) ;
F_11 ( ! V_11 || V_11 -> V_26 != V_26 ) ;
if ( ! V_11 )
goto V_49;
F_31 ( V_36 , & V_11 -> V_14 ) ;
F_26 ( V_7 , V_11 ) ;
F_10 ( V_11 ) ;
V_49:
F_32 ( & V_7 -> V_10 ) ;
return V_48 ;
}
int F_33 ( struct V_6 * V_7 ,
struct V_2 * V_11 )
{
int V_48 = 0 ;
struct V_18 * V_45 ;
struct V_2 * V_50 ;
V_50 = F_30 ( V_7 , V_11 -> V_26 , V_11 -> V_46 ) ;
if ( V_50 ) {
F_10 ( V_50 ) ;
V_48 = - V_51 ;
goto V_49;
}
V_45 = F_15 ( & V_7 -> V_8 , V_11 -> V_26 , & V_11 -> V_18 ) ;
if ( V_45 ) {
V_48 = - V_51 ;
goto V_49;
}
F_34 ( & V_11 -> V_17 ) ;
F_26 ( V_7 , V_11 ) ;
V_49:
return V_48 ;
}
static T_2 F_35 ( T_2 V_26 , T_2 V_46 )
{
if ( V_26 + V_46 < V_26 )
return ( T_2 ) - 1 ;
return V_26 + V_46 ;
}
struct V_2 * F_36 ( struct V_6 * V_7 ,
T_2 V_26 , T_2 V_46 , int V_52 )
{
struct V_2 * V_11 ;
struct V_18 * V_18 ;
struct V_18 * V_32 = NULL ;
struct V_18 * V_35 = NULL ;
T_2 V_53 = F_35 ( V_26 , V_46 ) ;
V_18 = F_20 ( & V_7 -> V_8 , V_26 , & V_32 , & V_35 ) ;
if ( ! V_18 ) {
if ( V_32 )
V_18 = V_32 ;
else if ( V_35 )
V_18 = V_35 ;
else
return NULL ;
}
V_11 = F_16 ( V_18 , struct V_2 , V_18 ) ;
if ( V_52 && ! ( V_53 > V_11 -> V_26 && V_26 < F_17 ( V_11 ) ) )
return NULL ;
F_34 ( & V_11 -> V_17 ) ;
return V_11 ;
}
struct V_2 * F_30 ( struct V_6 * V_7 ,
T_2 V_26 , T_2 V_46 )
{
return F_36 ( V_7 , V_26 , V_46 , 1 ) ;
}
struct V_2 * F_37 ( struct V_6 * V_7 ,
T_2 V_26 , T_2 V_46 )
{
return F_36 ( V_7 , V_26 , V_46 , 0 ) ;
}
int F_38 ( struct V_6 * V_7 , struct V_2 * V_11 )
{
int V_48 = 0 ;
F_11 ( F_24 ( V_36 , & V_11 -> V_14 ) ) ;
F_27 ( & V_11 -> V_18 , & V_7 -> V_8 ) ;
V_11 -> V_13 = 0 ;
return V_48 ;
}
