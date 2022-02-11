static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
if ( V_2 -> V_3 >= V_4 || V_2 -> V_4 <= V_3 )
return 0 ;
return 1 ;
}
static T_1 F_2 ( struct V_5 * V_2 )
{
T_1 V_6 = 0 ;
if ( V_2 ) {
struct V_1 * V_7 = F_3 ( V_2 , struct V_1 , V_8 ) ;
V_6 = V_7 -> V_9 ;
}
return V_6 ;
}
static T_1 F_4 ( struct V_1 * V_7 )
{
T_1 V_10 = V_7 -> V_4 , V_11 ;
V_11 = F_2 ( V_7 -> V_8 . V_12 ) ;
if ( V_11 > V_10 )
V_10 = V_11 ;
V_11 = F_2 ( V_7 -> V_8 . V_13 ) ;
if ( V_11 > V_10 )
V_10 = V_11 ;
return V_10 ;
}
static struct V_1 * F_5 ( struct V_14 * V_15 ,
T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_2 = V_15 -> V_5 ;
struct V_1 * V_16 = NULL ;
while ( V_2 ) {
struct V_1 * V_7 = F_3 ( V_2 , struct V_1 , V_8 ) ;
if ( F_2 ( V_2 -> V_13 ) > V_3 ) {
V_2 = V_2 -> V_13 ;
} else if ( F_1 ( V_7 , V_3 , V_4 ) ) {
V_16 = V_7 ;
break;
} else if ( V_3 >= V_7 -> V_3 ) {
V_2 = V_2 -> V_12 ;
} else {
break;
}
}
return V_16 ;
}
static struct V_1 * F_6 ( struct V_14 * V_15 ,
T_1 V_3 , T_1 V_4 , int V_17 )
{
struct V_1 * V_18 ;
V_18 = F_5 ( V_15 , V_3 , V_4 ) ;
while ( V_18 != NULL && V_18 -> V_3 < V_4 ) {
struct V_5 * V_2 ;
if ( ( V_17 == V_19 ) &&
( V_18 -> V_3 == V_3 ) && ( V_18 -> V_4 == V_4 ) )
return V_18 ;
if ( ( V_17 == V_20 ) &&
( V_18 -> V_3 < V_3 ) && ( V_18 -> V_4 == V_4 ) )
return V_18 ;
V_2 = F_7 ( & V_18 -> V_8 ) ;
if ( V_2 )
V_18 = F_3 ( V_2 , struct V_1 , V_8 ) ;
else
V_18 = NULL ;
}
return NULL ;
}
static int F_8 ( struct V_14 * V_15 ,
T_1 V_3 , T_1 V_4 ,
enum V_21 V_22 ,
enum V_21 * V_23 )
{
struct V_5 * V_2 ;
struct V_1 * V_18 ;
enum V_21 V_24 = V_22 ;
V_18 = F_5 ( & V_25 , V_3 , V_4 ) ;
if ( V_18 == NULL )
goto V_26;
if ( V_18 -> type != V_24 && V_23 == NULL )
goto V_27;
F_9 ( L_1 , V_18 -> V_3 , V_18 -> V_4 ) ;
V_24 = V_18 -> type ;
V_2 = F_7 ( & V_18 -> V_8 ) ;
while ( V_2 ) {
V_18 = F_3 ( V_2 , struct V_1 , V_8 ) ;
if ( V_18 -> V_3 >= V_4 )
goto V_26;
if ( F_1 ( V_18 , V_3 , V_4 ) &&
V_18 -> type != V_24 ) {
goto V_27;
}
V_2 = F_7 ( & V_18 -> V_8 ) ;
}
V_26:
if ( V_23 )
* V_23 = V_24 ;
return 0 ;
V_27:
F_10 ( L_2 ,
V_28 -> V_29 , V_28 -> V_30 , V_3 , V_4 ,
F_11 ( V_24 ) , F_11 ( V_18 -> type ) ) ;
return - V_31 ;
}
static void F_12 ( struct V_14 * V_15 , struct V_1 * V_32 )
{
struct V_5 * * V_2 = & ( V_15 -> V_5 ) ;
struct V_5 * V_33 = NULL ;
while ( * V_2 ) {
struct V_1 * V_7 = F_3 ( * V_2 , struct V_1 , V_8 ) ;
V_33 = * V_2 ;
if ( V_7 -> V_9 < V_32 -> V_4 )
V_7 -> V_9 = V_32 -> V_4 ;
if ( V_32 -> V_3 <= V_7 -> V_3 )
V_2 = & ( ( * V_2 ) -> V_13 ) ;
else if ( V_32 -> V_3 > V_7 -> V_3 )
V_2 = & ( ( * V_2 ) -> V_12 ) ;
}
V_32 -> V_9 = V_32 -> V_4 ;
F_13 ( & V_32 -> V_8 , V_33 , V_2 ) ;
F_14 ( & V_32 -> V_8 , V_15 , & V_34 ) ;
}
int F_15 ( struct V_1 * V_35 ,
enum V_21 * V_36 )
{
int V_37 = 0 ;
V_37 = F_8 ( & V_25 , V_35 -> V_3 , V_35 -> V_4 ,
V_35 -> type , V_36 ) ;
if ( ! V_37 ) {
if ( V_36 )
V_35 -> type = * V_36 ;
V_35 -> V_9 = V_35 -> V_4 ;
F_12 ( & V_25 , V_35 ) ;
}
return V_37 ;
}
struct V_1 * F_16 ( T_1 V_3 , T_1 V_4 )
{
struct V_1 * V_7 ;
V_7 = F_6 ( & V_25 , V_3 , V_4 ,
V_19 ) ;
if ( ! V_7 ) {
V_7 = F_6 ( & V_25 , V_3 , V_4 ,
V_20 ) ;
if ( ! V_7 )
return F_17 ( - V_38 ) ;
}
if ( V_7 -> V_3 == V_3 ) {
F_18 ( & V_7 -> V_8 , & V_25 ,
& V_34 ) ;
} else {
F_18 ( & V_7 -> V_8 , & V_25 ,
& V_34 ) ;
V_7 -> V_4 = V_3 ;
V_7 -> V_9 = V_7 -> V_4 ;
F_12 ( & V_25 , V_7 ) ;
return NULL ;
}
return V_7 ;
}
struct V_1 * F_19 ( T_1 V_39 )
{
struct V_1 * V_7 ;
V_7 = F_5 ( & V_25 , V_39 , V_39 + V_40 ) ;
return V_7 ;
}
int F_20 ( struct V_1 * V_41 , T_2 V_42 )
{
struct V_5 * V_2 ;
int V_43 = 1 ;
V_2 = F_21 ( & V_25 ) ;
while ( V_2 && V_42 != V_43 ) {
V_2 = F_7 ( V_2 ) ;
V_43 ++ ;
}
if ( V_2 ) {
struct V_1 * V_44 = F_3 ( V_2 , struct V_1 , V_8 ) ;
* V_41 = * V_44 ;
return 0 ;
} else {
return 1 ;
}
}
