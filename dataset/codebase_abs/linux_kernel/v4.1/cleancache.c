static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
switch ( V_2 -> V_4 ) {
case V_5 :
F_2 ( V_2 ) ;
break;
case V_6 :
F_3 ( V_2 ) ;
break;
}
}
int F_4 ( struct V_7 * V_8 )
{
if ( F_5 ( & V_7 , NULL , V_8 ) )
return - V_9 ;
F_6 ( F_1 , NULL ) ;
return 0 ;
}
void F_2 ( struct V_1 * V_2 )
{
int V_10 = V_5 ;
if ( V_7 ) {
V_10 = V_7 -> V_11 ( V_12 ) ;
if ( V_10 < 0 )
V_10 = V_13 ;
}
V_2 -> V_4 = V_10 ;
}
void F_3 ( struct V_1 * V_2 )
{
int V_10 = V_6 ;
if ( V_7 ) {
V_10 = V_7 -> V_14 ( V_2 -> V_15 , V_12 ) ;
if ( V_10 < 0 )
V_10 = V_13 ;
}
V_2 -> V_4 = V_10 ;
}
static int F_7 ( struct V_16 * V_16 ,
struct V_17 * V_18 )
{
int (* F_8)( struct V_16 * , T_1 * V_19 , int * , struct V_16 * );
int V_20 = 0 , V_21 = V_22 ;
struct V_1 * V_2 = V_16 -> V_23 ;
V_18 -> V_24 . V_25 = V_16 -> V_26 ;
if ( V_2 -> V_27 != NULL ) {
F_8 = V_2 -> V_27 -> V_28 ;
if ( F_8 ) {
V_20 = (* F_8)( V_16 , & V_18 -> V_24 . V_19 [ 0 ] , & V_21 , NULL ) ;
if ( V_20 <= V_29 || V_20 == V_30 )
return - 1 ;
if ( V_21 > V_22 )
return - 1 ;
}
}
return 0 ;
}
int F_9 ( struct V_31 * V_31 )
{
int V_32 = - 1 ;
int V_10 ;
struct V_17 V_18 = { . V_24 . V_18 = { 0 } } ;
if ( ! V_7 ) {
V_33 ++ ;
goto V_34;
}
F_10 ( ! F_11 ( V_31 ) , V_31 ) ;
V_10 = V_31 -> V_35 -> V_36 -> V_23 -> V_4 ;
if ( V_10 < 0 )
goto V_34;
if ( F_7 ( V_31 -> V_35 -> V_36 , & V_18 ) < 0 )
goto V_34;
V_32 = V_7 -> V_37 ( V_10 , V_18 , V_31 -> V_38 , V_31 ) ;
if ( V_32 == 0 )
V_39 ++ ;
else
V_33 ++ ;
V_34:
return V_32 ;
}
void F_12 ( struct V_31 * V_31 )
{
int V_10 ;
struct V_17 V_18 = { . V_24 . V_18 = { 0 } } ;
if ( ! V_7 ) {
V_40 ++ ;
return;
}
F_10 ( ! F_11 ( V_31 ) , V_31 ) ;
V_10 = V_31 -> V_35 -> V_36 -> V_23 -> V_4 ;
if ( V_10 >= 0 &&
F_7 ( V_31 -> V_35 -> V_36 , & V_18 ) >= 0 ) {
V_7 -> V_41 ( V_10 , V_18 , V_31 -> V_38 , V_31 ) ;
V_40 ++ ;
}
}
void F_13 ( struct V_42 * V_35 ,
struct V_31 * V_31 )
{
int V_10 = V_35 -> V_36 -> V_23 -> V_4 ;
struct V_17 V_18 = { . V_24 . V_18 = { 0 } } ;
if ( ! V_7 )
return;
if ( V_10 >= 0 ) {
F_10 ( ! F_11 ( V_31 ) , V_31 ) ;
if ( F_7 ( V_35 -> V_36 , & V_18 ) >= 0 ) {
V_7 -> V_43 ( V_10 ,
V_18 , V_31 -> V_38 ) ;
V_44 ++ ;
}
}
}
void F_14 ( struct V_42 * V_35 )
{
int V_10 = V_35 -> V_36 -> V_23 -> V_4 ;
struct V_17 V_18 = { . V_24 . V_18 = { 0 } } ;
if ( ! V_7 )
return;
if ( V_10 >= 0 && F_7 ( V_35 -> V_36 , & V_18 ) >= 0 )
V_7 -> V_45 ( V_10 , V_18 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
int V_10 ;
V_10 = V_2 -> V_4 ;
V_2 -> V_4 = V_13 ;
if ( V_7 && V_10 >= 0 )
V_7 -> V_46 ( V_10 ) ;
}
static int T_2 F_16 ( void )
{
#ifdef F_17
struct V_47 * V_48 = F_18 ( L_1 , NULL ) ;
if ( V_48 == NULL )
return - V_49 ;
F_19 ( L_2 , V_50 , V_48 , & V_39 ) ;
F_19 ( L_3 , V_50 ,
V_48 , & V_33 ) ;
F_19 ( L_4 , V_50 , V_48 , & V_40 ) ;
F_19 ( L_5 , V_50 ,
V_48 , & V_44 ) ;
#endif
return 0 ;
}
