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
F_5 ( V_15 ) ;
if ( ! V_15 )
return NULL ;
F_6 ( & V_15 -> V_16 ) ;
V_15 -> V_17 = V_14 ;
V_15 -> V_18 = V_4 ;
return V_15 ;
}
static void F_7 ( struct V_13 * V_15 )
{
if ( ! F_8 ( & V_15 -> V_16 ) )
F_9 ( & V_15 -> V_16 ) ;
F_10 ( V_15 ) ;
}
static struct V_13 * F_11 ( struct V_19 * V_20 ,
T_4 V_14 )
{
struct V_13 * V_15 ;
struct V_21 * V_22 = & V_20 -> V_23 [ F_1 ( V_14 ) ] ;
F_12 (rce, head, rce_list)
if ( V_15 -> V_17 == V_14 )
return V_15 ;
return NULL ;
}
struct V_13 * F_13 ( struct V_19 * V_20 , T_4 V_14 )
{
struct V_13 * V_15 ;
F_14 ( & V_20 -> V_24 ) ;
V_15 = F_11 ( V_20 , V_14 ) ;
F_15 ( & V_20 -> V_24 ) ;
return V_15 ;
}
int F_16 ( struct V_19 * V_20 , T_4 V_14 , int V_4 )
{
struct V_13 * V_15 , * V_25 ;
V_15 = F_4 ( V_14 , V_4 ) ;
if ( V_15 == NULL )
return - V_26 ;
F_14 ( & V_20 -> V_24 ) ;
V_25 = F_11 ( V_20 , V_14 ) ;
if ( F_17 ( V_25 != NULL ) ) {
F_18 ( L_1
L_2 , ( int ) V_14 , V_4 ) ;
F_7 ( V_25 ) ;
}
F_19 ( & V_15 -> V_16 , & V_20 -> V_23 [ F_1 ( V_14 ) ] ) ;
F_15 ( & V_20 -> V_24 ) ;
return 0 ;
}
int F_20 ( struct V_19 * V_20 , T_4 V_14 )
{
struct V_13 * V_15 ;
F_14 ( & V_20 -> V_24 ) ;
V_15 = F_11 ( V_20 , V_14 ) ;
if ( V_15 )
F_7 ( V_15 ) ;
F_15 ( & V_20 -> V_24 ) ;
return V_15 ? 0 : - V_27 ;
}
void F_21 ( struct V_19 * V_20 )
{
int V_28 ;
F_22 ( & V_20 -> V_24 ) ;
for ( V_28 = 0 ; V_28 < V_2 ; V_28 ++ )
F_6 ( & V_20 -> V_23 [ V_28 ] ) ;
}
void F_23 ( struct V_19 * V_20 )
{
struct V_13 * V_15 ;
int V_28 ;
F_14 ( & V_20 -> V_24 ) ;
for ( V_28 = 0 ; V_28 < V_2 ; V_28 ++ )
while ( ! F_8 ( & V_20 -> V_23 [ V_28 ] ) ) {
V_15 = F_24 ( V_20 -> V_23 [ V_28 ] . V_29 ,
struct V_13 , V_16 ) ;
F_7 ( V_15 ) ;
}
F_15 ( & V_20 -> V_24 ) ;
}
static struct V_30 * F_25 ( T_4 V_14 , struct V_31 * V_32 , int type ,
T_5 * V_33 )
{
struct V_30 * V_34 ;
F_5 ( V_34 ) ;
if ( ! V_34 )
return NULL ;
F_6 ( & V_34 -> V_35 ) ;
V_34 -> V_36 = V_14 ;
V_34 -> V_37 = * V_32 ;
V_34 -> V_38 = type ;
V_34 -> V_39 = V_33 ;
return V_34 ;
}
void F_26 ( struct V_30 * V_34 )
{
if ( ! F_8 ( & V_34 -> V_35 ) )
F_9 ( & V_34 -> V_35 ) ;
if ( V_34 -> V_39 )
F_27 ( V_34 -> V_39 ) ;
F_10 ( V_34 ) ;
}
static struct V_30 * F_28 ( struct V_40 * V_41 , T_4 V_14 ,
struct V_31 * V_32 , int type )
{
struct V_30 * V_34 ;
struct V_21 * V_22 = & V_41 -> V_42 [ F_2 ( V_14 ) ] ;
F_29 ( V_32 != NULL ) ;
F_12 (ee, head, ee_list)
if ( V_34 -> V_36 == V_14 ) {
if ( F_30 ( & V_34 -> V_37 , V_32 ) &&
V_34 -> V_38 == type ) {
F_31 ( & V_34 -> V_35 ) ;
return V_34 ;
}
}
return NULL ;
}
struct V_30 * F_32 ( struct V_40 * V_41 , T_4 V_14 ,
struct V_31 * V_32 , int type )
{
struct V_30 * V_34 ;
F_14 ( & V_41 -> V_43 ) ;
V_34 = F_28 ( V_41 , V_14 , V_32 , type ) ;
F_15 ( & V_41 -> V_43 ) ;
return V_34 ;
}
void F_33 ( struct V_40 * V_41 , T_4 V_14 )
{
struct V_30 * V_34 , * V_29 ;
struct V_21 * V_22 = & V_41 -> V_42 [ F_2 ( V_14 ) ] ;
F_14 ( & V_41 -> V_43 ) ;
F_34 (ee, next, head, ee_list)
if ( V_34 -> V_36 == V_14 )
F_26 ( V_34 ) ;
F_15 ( & V_41 -> V_43 ) ;
}
int F_35 ( struct V_40 * V_41 , T_4 V_14 , struct V_31 * V_32 , int type ,
T_5 * V_33 )
{
struct V_30 * V_34 , * V_25 ;
V_34 = F_25 ( V_14 , V_32 , type , V_33 ) ;
if ( V_34 == NULL )
return - V_26 ;
F_14 ( & V_41 -> V_43 ) ;
V_25 = F_28 ( V_41 , V_14 , V_32 , type ) ;
if ( F_17 ( V_25 != NULL ) ) {
F_18 ( L_3
L_4 V_44 L_5 ,
( int ) V_14 , F_36 ( V_32 ) , type ) ;
F_26 ( V_25 ) ;
}
F_19 ( & V_34 -> V_35 , & V_41 -> V_42 [ F_2 ( V_14 ) ] ) ;
F_15 ( & V_41 -> V_43 ) ;
return 0 ;
}
void F_37 ( struct V_40 * V_41 )
{
int V_28 ;
F_22 ( & V_41 -> V_43 ) ;
for ( V_28 = 0 ; V_28 < V_3 ; V_28 ++ )
F_6 ( & V_41 -> V_42 [ V_28 ] ) ;
}
void F_38 ( struct V_40 * V_41 )
{
struct V_30 * V_34 ;
int V_28 ;
F_14 ( & V_41 -> V_43 ) ;
for ( V_28 = 0 ; V_28 < V_3 ; V_28 ++ )
while ( ! F_8 ( & V_41 -> V_42 [ V_28 ] ) ) {
V_34 = F_24 ( V_41 -> V_42 [ V_28 ] . V_29 ,
struct V_30 , V_35 ) ;
F_26 ( V_34 ) ;
}
F_15 ( & V_41 -> V_43 ) ;
}
