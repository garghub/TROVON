static inline T_1 F_1 ( T_2 V_1 )
{
return V_1 & ( V_2 - 1 ) ;
}
static inline T_1 F_2 ( T_2 V_1 )
{
return V_1 & ( V_3 - 1 ) ;
}
T_3 F_3 ( int V_4 )
{
switch ( V_4 ) {
case V_5 :
return V_6 ;
case V_7 :
return V_8 ;
case V_9 :
return V_10 ;
case V_11 :
return V_12 ;
default:
return 0 ;
}
}
static struct V_13 * F_4 ( T_4 V_14 , int V_4 )
{
struct V_13 * V_15 ;
V_15 = F_5 ( sizeof( * V_15 ) , V_16 ) ;
if ( ! V_15 )
return NULL ;
F_6 ( & V_15 -> V_17 ) ;
V_15 -> V_18 = V_14 ;
V_15 -> V_19 = V_4 ;
return V_15 ;
}
static void F_7 ( struct V_13 * V_15 )
{
if ( ! F_8 ( & V_15 -> V_17 ) )
F_9 ( & V_15 -> V_17 ) ;
F_10 ( V_15 ) ;
}
static struct V_13 * F_11 ( struct V_20 * V_21 ,
T_4 V_14 )
{
struct V_13 * V_15 ;
struct V_22 * V_23 = & V_21 -> V_24 [ F_1 ( V_14 ) ] ;
F_12 (rce, head, rce_list)
if ( V_15 -> V_18 == V_14 )
return V_15 ;
return NULL ;
}
struct V_13 * F_13 ( struct V_20 * V_21 , T_4 V_14 )
{
struct V_13 * V_15 ;
F_14 ( & V_21 -> V_25 ) ;
V_15 = F_11 ( V_21 , V_14 ) ;
F_15 ( & V_21 -> V_25 ) ;
return V_15 ;
}
int F_16 ( struct V_20 * V_21 , T_4 V_14 , int V_4 )
{
struct V_13 * V_15 , * V_26 ;
V_15 = F_4 ( V_14 , V_4 ) ;
if ( V_15 == NULL )
return - V_27 ;
F_14 ( & V_21 -> V_25 ) ;
V_26 = F_11 ( V_21 , V_14 ) ;
if ( F_17 ( V_26 != NULL ) ) {
F_18 ( L_1
L_2 , ( int ) V_14 , V_4 ) ;
F_7 ( V_26 ) ;
}
F_19 ( & V_15 -> V_17 , & V_21 -> V_24 [ F_1 ( V_14 ) ] ) ;
F_15 ( & V_21 -> V_25 ) ;
return 0 ;
}
int F_20 ( struct V_20 * V_21 , T_4 V_14 )
{
struct V_13 * V_15 ;
F_14 ( & V_21 -> V_25 ) ;
V_15 = F_11 ( V_21 , V_14 ) ;
if ( V_15 )
F_7 ( V_15 ) ;
F_15 ( & V_21 -> V_25 ) ;
return V_15 ? 0 : - V_28 ;
}
void F_21 ( struct V_20 * V_21 )
{
int V_29 ;
F_22 ( & V_21 -> V_25 ) ;
for ( V_29 = 0 ; V_29 < V_2 ; V_29 ++ )
F_6 ( & V_21 -> V_24 [ V_29 ] ) ;
}
void F_23 ( struct V_20 * V_21 )
{
struct V_13 * V_15 ;
int V_29 ;
F_14 ( & V_21 -> V_25 ) ;
for ( V_29 = 0 ; V_29 < V_2 ; V_29 ++ )
while ( ! F_8 ( & V_21 -> V_24 [ V_29 ] ) ) {
V_15 = F_24 ( V_21 -> V_24 [ V_29 ] . V_30 ,
struct V_13 , V_17 ) ;
F_7 ( V_15 ) ;
}
F_15 ( & V_21 -> V_25 ) ;
}
static struct V_31 * F_25 ( T_4 V_14 , struct V_32 * V_33 , int type ,
T_5 * V_34 )
{
struct V_31 * V_35 ;
V_35 = F_5 ( sizeof( * V_35 ) , V_16 ) ;
if ( ! V_35 )
return NULL ;
F_6 ( & V_35 -> V_36 ) ;
V_35 -> V_37 = V_14 ;
V_35 -> V_38 = * V_33 ;
V_35 -> V_39 = type ;
V_35 -> V_40 = V_34 ;
return V_35 ;
}
void F_26 ( struct V_31 * V_35 )
{
if ( ! F_8 ( & V_35 -> V_36 ) )
F_9 ( & V_35 -> V_36 ) ;
if ( V_35 -> V_40 )
F_27 ( V_35 -> V_40 ) ;
F_10 ( V_35 ) ;
}
static struct V_31 * F_28 ( struct V_41 * V_42 , T_4 V_14 ,
struct V_32 * V_33 , int type )
{
struct V_31 * V_35 ;
struct V_22 * V_23 = & V_42 -> V_43 [ F_2 ( V_14 ) ] ;
F_29 ( V_33 != NULL ) ;
F_12 (ee, head, ee_list)
if ( V_35 -> V_37 == V_14 ) {
if ( F_30 ( & V_35 -> V_38 , V_33 ) &&
V_35 -> V_39 == type ) {
F_31 ( & V_35 -> V_36 ) ;
return V_35 ;
}
}
return NULL ;
}
struct V_31 * F_32 ( struct V_41 * V_42 , T_4 V_14 ,
struct V_32 * V_33 , int type )
{
struct V_31 * V_35 ;
F_14 ( & V_42 -> V_44 ) ;
V_35 = F_28 ( V_42 , V_14 , V_33 , type ) ;
F_15 ( & V_42 -> V_44 ) ;
return V_35 ;
}
void F_33 ( struct V_41 * V_42 , T_4 V_14 )
{
struct V_31 * V_35 , * V_30 ;
struct V_22 * V_23 = & V_42 -> V_43 [ F_2 ( V_14 ) ] ;
F_14 ( & V_42 -> V_44 ) ;
F_34 (ee, next, head, ee_list)
if ( V_35 -> V_37 == V_14 )
F_26 ( V_35 ) ;
F_15 ( & V_42 -> V_44 ) ;
}
int F_35 ( struct V_41 * V_42 , T_4 V_14 , struct V_32 * V_33 , int type ,
T_5 * V_34 )
{
struct V_31 * V_35 , * V_26 ;
V_35 = F_25 ( V_14 , V_33 , type , V_34 ) ;
if ( V_35 == NULL )
return - V_27 ;
F_14 ( & V_42 -> V_44 ) ;
V_26 = F_28 ( V_42 , V_14 , V_33 , type ) ;
if ( F_17 ( V_26 != NULL ) ) {
F_18 ( L_3
L_4 V_45 L_5 ,
( int ) V_14 , F_36 ( V_33 ) , type ) ;
F_26 ( V_26 ) ;
}
F_19 ( & V_35 -> V_36 , & V_42 -> V_43 [ F_2 ( V_14 ) ] ) ;
F_15 ( & V_42 -> V_44 ) ;
return 0 ;
}
void F_37 ( struct V_41 * V_42 )
{
int V_29 ;
F_22 ( & V_42 -> V_44 ) ;
for ( V_29 = 0 ; V_29 < V_3 ; V_29 ++ )
F_6 ( & V_42 -> V_43 [ V_29 ] ) ;
}
void F_38 ( struct V_41 * V_42 )
{
struct V_31 * V_35 ;
int V_29 ;
F_14 ( & V_42 -> V_44 ) ;
for ( V_29 = 0 ; V_29 < V_3 ; V_29 ++ )
while ( ! F_8 ( & V_42 -> V_43 [ V_29 ] ) ) {
V_35 = F_24 ( V_42 -> V_43 [ V_29 ] . V_30 ,
struct V_31 , V_36 ) ;
F_26 ( V_35 ) ;
}
F_15 ( & V_42 -> V_44 ) ;
}
