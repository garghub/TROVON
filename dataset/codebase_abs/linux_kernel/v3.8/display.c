void F_1 ( struct V_1 * V_2 ,
T_1 * V_3 , T_1 * V_4 )
{
* V_3 = V_2 -> V_5 . V_6 . V_7 ;
* V_4 = V_2 -> V_5 . V_6 . V_8 ;
}
int F_2 ( struct V_1 * V_2 )
{
switch ( V_2 -> type ) {
case V_9 :
if ( V_2 -> V_10 . V_11 . V_12 == 24 )
return 24 ;
else
return 16 ;
case V_13 :
if ( V_2 -> V_14 . V_15 == 24 )
return 24 ;
else
return 16 ;
case V_16 :
if ( F_3 ( V_2 -> V_5 . V_17 ) > 16 )
return 24 ;
else
return 16 ;
case V_18 :
case V_19 :
case V_20 :
return 24 ;
default:
F_4 () ;
return 0 ;
}
}
void F_5 ( struct V_1 * V_2 ,
struct V_21 * V_6 )
{
* V_6 = V_2 -> V_5 . V_6 ;
}
static int F_6 ( struct V_22 * V_23 , void * V_24 )
{
struct V_1 * V_2 = F_7 ( V_23 ) ;
if ( V_2 -> V_25 != V_26 ) {
V_2 -> V_27 = false ;
return 0 ;
}
V_2 -> V_28 -> V_29 ( V_2 ) ;
V_2 -> V_27 = true ;
return 0 ;
}
int F_8 ( void )
{
int V_30 ;
struct V_31 * V_32 = F_9 () ;
V_30 = F_10 ( V_32 , NULL , NULL , F_6 ) ;
if ( V_30 ) {
F_11 () ;
return V_30 ;
}
return 0 ;
}
static int F_12 ( struct V_22 * V_23 , void * V_24 )
{
int V_30 ;
struct V_1 * V_2 = F_7 ( V_23 ) ;
if ( V_2 -> V_27 ) {
V_30 = V_2 -> V_28 -> V_33 ( V_2 ) ;
if ( V_30 )
return V_30 ;
}
V_2 -> V_27 = false ;
return 0 ;
}
int F_11 ( void )
{
struct V_31 * V_32 = F_9 () ;
return F_10 ( V_32 , NULL , NULL , F_12 ) ;
}
static int F_13 ( struct V_22 * V_23 , void * V_24 )
{
struct V_1 * V_2 = F_7 ( V_23 ) ;
if ( V_2 -> V_25 != V_34 )
V_2 -> V_28 -> V_29 ( V_2 ) ;
return 0 ;
}
void F_14 ( void )
{
struct V_31 * V_32 = F_9 () ;
F_10 ( V_32 , NULL , NULL , F_13 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
F_16 ( & V_2 -> V_23 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
F_18 ( & V_2 -> V_23 ) ;
}
int F_19 ( struct V_22 * V_23 , void * V_24 )
{
return 1 ;
}
struct V_1 * F_20 ( void * V_24 ,
int (* F_19)( struct V_1 * V_2 , void * V_24 ) )
{
struct V_1 * V_2 = NULL ;
while ( ( V_2 = F_21 ( V_2 ) ) != NULL ) {
if ( F_19 ( V_2 , V_24 ) )
return V_2 ;
}
return NULL ;
}
int F_22 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_28 ) {
F_23 ( L_1 ) ;
return - V_35 ;
}
if ( ! F_24 ( V_2 -> V_23 . V_28 -> V_36 ) ) {
return - V_35 ;
}
return 0 ;
}
void F_25 ( struct V_1 * V_2 )
{
F_26 ( V_2 -> V_23 . V_28 -> V_36 ) ;
}
