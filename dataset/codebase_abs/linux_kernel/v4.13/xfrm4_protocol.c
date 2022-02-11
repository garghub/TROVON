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
int F_2 ( struct V_9 * V_10 , int V_11 , T_3 V_12 ,
int V_13 )
{
int V_14 ;
struct V_1 * V_15 ;
struct V_1 T_1 * * V_16 = F_1 ( V_11 ) ;
F_3 ( V_10 ) -> V_17 . V_18 = NULL ;
F_4 ( V_10 ) -> V_19 = V_20 ;
F_4 ( V_10 ) -> V_21 = F_5 ( struct V_22 , V_23 ) ;
if ( ! V_16 )
goto V_24;
F_6 (*head, handler)
if ( ( V_14 = V_15 -> V_25 ( V_10 , V_11 , V_12 , V_13 ) ) != - V_26 )
return V_14 ;
V_24:
F_7 ( V_10 , V_27 , V_28 , 0 ) ;
F_8 ( V_10 ) ;
return 0 ;
}
static int F_9 ( struct V_9 * V_10 )
{
int V_14 ;
struct V_1 * V_15 ;
F_3 ( V_10 ) -> V_17 . V_18 = NULL ;
F_6 (esp4_handlers, handler)
if ( ( V_14 = V_15 -> V_15 ( V_10 ) ) != - V_26 )
return V_14 ;
F_7 ( V_10 , V_27 , V_28 , 0 ) ;
F_8 ( V_10 ) ;
return 0 ;
}
static void F_10 ( struct V_9 * V_10 , T_4 V_29 )
{
struct V_1 * V_15 ;
F_6 (esp4_handlers, handler)
if ( ! V_15 -> V_30 ( V_10 , V_29 ) )
break;
}
static int F_11 ( struct V_9 * V_10 )
{
int V_14 ;
struct V_1 * V_15 ;
F_3 ( V_10 ) -> V_17 . V_18 = NULL ;
F_6 (ah4_handlers, handler)
if ( ( V_14 = V_15 -> V_15 ( V_10 ) ) != - V_26 )
return V_14 ;
F_7 ( V_10 , V_27 , V_28 , 0 ) ;
F_8 ( V_10 ) ;
return 0 ;
}
static void F_12 ( struct V_9 * V_10 , T_4 V_29 )
{
struct V_1 * V_15 ;
F_6 (ah4_handlers, handler)
if ( ! V_15 -> V_30 ( V_10 , V_29 ) )
break;
}
static int F_13 ( struct V_9 * V_10 )
{
int V_14 ;
struct V_1 * V_15 ;
F_3 ( V_10 ) -> V_17 . V_18 = NULL ;
F_6 (ipcomp4_handlers, handler)
if ( ( V_14 = V_15 -> V_15 ( V_10 ) ) != - V_26 )
return V_14 ;
F_7 ( V_10 , V_27 , V_28 , 0 ) ;
F_8 ( V_10 ) ;
return 0 ;
}
static void F_14 ( struct V_9 * V_10 , T_4 V_29 )
{
struct V_1 * V_15 ;
F_6 (ipcomp4_handlers, handler)
if ( ! V_15 -> V_30 ( V_10 , V_29 ) )
break;
}
static inline const struct V_31 * F_15 ( unsigned char V_2 )
{
switch ( V_2 ) {
case V_3 :
return & V_32 ;
case V_5 :
return & V_33 ;
case V_7 :
return & V_34 ;
}
return NULL ;
}
int F_16 ( struct V_1 * V_15 ,
unsigned char V_2 )
{
struct V_1 T_1 * * V_35 ;
struct V_1 * V_36 ;
bool V_37 = false ;
int V_14 = - V_38 ;
int V_39 = V_15 -> V_39 ;
if ( ! F_1 ( V_2 ) || ! F_15 ( V_2 ) )
return - V_26 ;
F_17 ( & V_40 ) ;
if ( ! F_18 ( * F_1 ( V_2 ) ,
F_19 ( & V_40 ) ) )
V_37 = true ;
for ( V_35 = F_1 ( V_2 ) ;
( V_36 = F_18 ( * V_35 ,
F_19 ( & V_40 ) ) ) != NULL ;
V_35 = & V_36 -> V_41 ) {
if ( V_36 -> V_39 < V_39 )
break;
if ( V_36 -> V_39 == V_39 )
goto V_42;
}
V_15 -> V_41 = * V_35 ;
F_20 ( * V_35 , V_15 ) ;
V_14 = 0 ;
V_42:
F_21 ( & V_40 ) ;
if ( V_37 ) {
if ( F_22 ( F_15 ( V_2 ) , V_2 ) ) {
F_23 ( L_1 , V_43 ) ;
V_14 = - V_44 ;
}
}
return V_14 ;
}
int F_24 ( struct V_1 * V_15 ,
unsigned char V_2 )
{
struct V_1 T_1 * * V_35 ;
struct V_1 * V_36 ;
int V_14 = - V_45 ;
if ( ! F_1 ( V_2 ) || ! F_15 ( V_2 ) )
return - V_26 ;
F_17 ( & V_40 ) ;
for ( V_35 = F_1 ( V_2 ) ;
( V_36 = F_18 ( * V_35 ,
F_19 ( & V_40 ) ) ) != NULL ;
V_35 = & V_36 -> V_41 ) {
if ( V_36 == V_15 ) {
* V_35 = V_15 -> V_41 ;
V_14 = 0 ;
break;
}
}
if ( ! F_18 ( * F_1 ( V_2 ) ,
F_19 ( & V_40 ) ) ) {
if ( F_25 ( F_15 ( V_2 ) , V_2 ) < 0 ) {
F_23 ( L_2 , V_43 ) ;
V_14 = - V_44 ;
}
}
F_21 ( & V_40 ) ;
F_26 () ;
return V_14 ;
}
void T_5 F_27 ( void )
{
F_28 ( & V_46 ) ;
}
