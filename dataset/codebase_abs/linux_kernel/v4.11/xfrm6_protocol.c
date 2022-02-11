static inline struct V_1 T_1 * * F_1 ( T_2 V_2 )
{
switch ( V_2 ) {
case V_3 :
return & V_4 ;
case V_5 :
return & V_6 ;
case V_7 :
return & V_8 ;
}
return NULL ;
}
static int F_2 ( struct V_9 * V_10 )
{
int V_11 ;
struct V_1 * V_12 ;
F_3 ( V_10 ) -> V_13 . V_14 = NULL ;
F_4 (esp6_handlers, handler)
if ( ( V_11 = V_12 -> V_12 ( V_10 ) ) != - V_15 )
return V_11 ;
F_5 ( V_10 , V_16 , V_17 , 0 ) ;
F_6 ( V_10 ) ;
return 0 ;
}
static void F_7 ( struct V_9 * V_10 , struct V_18 * V_19 ,
T_2 type , T_2 V_20 , int V_21 , T_3 V_22 )
{
struct V_1 * V_12 ;
F_4 (esp6_handlers, handler)
if ( ! V_12 -> V_23 ( V_10 , V_19 , type , V_20 , V_21 , V_22 ) )
break;
}
static int F_8 ( struct V_9 * V_10 )
{
int V_11 ;
struct V_1 * V_12 ;
F_3 ( V_10 ) -> V_13 . V_14 = NULL ;
F_4 (ah6_handlers, handler)
if ( ( V_11 = V_12 -> V_12 ( V_10 ) ) != - V_15 )
return V_11 ;
F_5 ( V_10 , V_16 , V_17 , 0 ) ;
F_6 ( V_10 ) ;
return 0 ;
}
static void F_9 ( struct V_9 * V_10 , struct V_18 * V_19 ,
T_2 type , T_2 V_20 , int V_21 , T_3 V_22 )
{
struct V_1 * V_12 ;
F_4 (ah6_handlers, handler)
if ( ! V_12 -> V_23 ( V_10 , V_19 , type , V_20 , V_21 , V_22 ) )
break;
}
static int F_10 ( struct V_9 * V_10 )
{
int V_11 ;
struct V_1 * V_12 ;
F_3 ( V_10 ) -> V_13 . V_14 = NULL ;
F_4 (ipcomp6_handlers, handler)
if ( ( V_11 = V_12 -> V_12 ( V_10 ) ) != - V_15 )
return V_11 ;
F_5 ( V_10 , V_16 , V_17 , 0 ) ;
F_6 ( V_10 ) ;
return 0 ;
}
static void F_11 ( struct V_9 * V_10 , struct V_18 * V_19 ,
T_2 type , T_2 V_20 , int V_21 , T_3 V_22 )
{
struct V_1 * V_12 ;
F_4 (ipcomp6_handlers, handler)
if ( ! V_12 -> V_23 ( V_10 , V_19 , type , V_20 , V_21 , V_22 ) )
break;
}
static inline const struct V_24 * F_12 ( unsigned char V_2 )
{
switch ( V_2 ) {
case V_3 :
return & V_25 ;
case V_5 :
return & V_26 ;
case V_7 :
return & V_27 ;
}
return NULL ;
}
int F_13 ( struct V_1 * V_12 ,
unsigned char V_2 )
{
struct V_1 T_1 * * V_28 ;
struct V_1 * V_29 ;
bool V_30 = false ;
int V_11 = - V_31 ;
int V_32 = V_12 -> V_32 ;
if ( ! F_1 ( V_2 ) || ! F_12 ( V_2 ) )
return - V_15 ;
F_14 ( & V_33 ) ;
if ( ! F_15 ( * F_1 ( V_2 ) ,
F_16 ( & V_33 ) ) )
V_30 = true ;
for ( V_28 = F_1 ( V_2 ) ;
( V_29 = F_15 ( * V_28 ,
F_16 ( & V_33 ) ) ) != NULL ;
V_28 = & V_29 -> V_34 ) {
if ( V_29 -> V_32 < V_32 )
break;
if ( V_29 -> V_32 == V_32 )
goto V_35;
}
V_12 -> V_34 = * V_28 ;
F_17 ( * V_28 , V_12 ) ;
V_11 = 0 ;
V_35:
F_18 ( & V_33 ) ;
if ( V_30 ) {
if ( F_19 ( F_12 ( V_2 ) , V_2 ) ) {
F_20 ( L_1 , V_36 ) ;
V_11 = - V_37 ;
}
}
return V_11 ;
}
int F_21 ( struct V_1 * V_12 ,
unsigned char V_2 )
{
struct V_1 T_1 * * V_28 ;
struct V_1 * V_29 ;
int V_11 = - V_38 ;
if ( ! F_1 ( V_2 ) || ! F_12 ( V_2 ) )
return - V_15 ;
F_14 ( & V_33 ) ;
for ( V_28 = F_1 ( V_2 ) ;
( V_29 = F_15 ( * V_28 ,
F_16 ( & V_33 ) ) ) != NULL ;
V_28 = & V_29 -> V_34 ) {
if ( V_29 == V_12 ) {
* V_28 = V_12 -> V_34 ;
V_11 = 0 ;
break;
}
}
if ( ! F_15 ( * F_1 ( V_2 ) ,
F_16 ( & V_33 ) ) ) {
if ( F_22 ( F_12 ( V_2 ) , V_2 ) < 0 ) {
F_20 ( L_2 , V_36 ) ;
V_11 = - V_37 ;
}
}
F_18 ( & V_33 ) ;
F_23 () ;
return V_11 ;
}
int T_4 F_24 ( void )
{
return F_25 ( & V_39 ) ;
}
void F_26 ( void )
{
F_27 ( & V_39 ) ;
}
