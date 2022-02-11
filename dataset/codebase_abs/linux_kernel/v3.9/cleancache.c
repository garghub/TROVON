struct V_1 F_1 ( struct V_1 * V_2 )
{
struct V_1 V_3 = V_1 ;
V_1 = * V_2 ;
V_4 = 1 ;
return V_3 ;
}
void F_2 ( struct V_5 * V_6 )
{
V_6 -> V_7 = (* V_1 . V_8 )( V_9 ) ;
}
void F_3 ( char * V_10 , struct V_5 * V_6 )
{
V_6 -> V_7 =
(* V_1 . V_11 )( V_10 , V_9 ) ;
}
static int F_4 ( struct V_12 * V_12 ,
struct V_13 * V_14 )
{
int (* F_5)( struct V_12 * , T_1 * V_15 , int * , struct V_12 * );
int V_16 = 0 , V_17 = V_18 ;
struct V_5 * V_6 = V_12 -> V_19 ;
V_14 -> V_20 . V_21 = V_12 -> V_22 ;
if ( V_6 -> V_23 != NULL ) {
F_5 = V_6 -> V_23 -> V_24 ;
if ( F_5 ) {
V_16 = (* F_5)( V_12 , & V_14 -> V_20 . V_15 [ 0 ] , & V_17 , NULL ) ;
if ( V_16 <= V_25 || V_16 == V_26 )
return - 1 ;
if ( V_17 > V_18 )
return - 1 ;
}
}
return 0 ;
}
int F_6 ( struct V_27 * V_27 )
{
int V_28 = - 1 ;
int V_29 ;
struct V_13 V_14 = { . V_20 . V_14 = { 0 } } ;
F_7 ( ! F_8 ( V_27 ) ) ;
V_29 = V_27 -> V_30 -> V_31 -> V_19 -> V_7 ;
if ( V_29 < 0 )
goto V_32;
if ( F_4 ( V_27 -> V_30 -> V_31 , & V_14 ) < 0 )
goto V_32;
V_28 = (* V_1 . V_33 )( V_29 , V_14 , V_27 -> V_34 , V_27 ) ;
if ( V_28 == 0 )
V_35 ++ ;
else
V_36 ++ ;
V_32:
return V_28 ;
}
void F_9 ( struct V_27 * V_27 )
{
int V_29 ;
struct V_13 V_14 = { . V_20 . V_14 = { 0 } } ;
F_7 ( ! F_8 ( V_27 ) ) ;
V_29 = V_27 -> V_30 -> V_31 -> V_19 -> V_7 ;
if ( V_29 >= 0 &&
F_4 ( V_27 -> V_30 -> V_31 , & V_14 ) >= 0 ) {
(* V_1 . V_37 )( V_29 , V_14 , V_27 -> V_34 , V_27 ) ;
V_38 ++ ;
}
}
void F_10 ( struct V_39 * V_30 ,
struct V_27 * V_27 )
{
int V_29 = V_30 -> V_31 -> V_19 -> V_7 ;
struct V_13 V_14 = { . V_20 . V_14 = { 0 } } ;
if ( V_29 >= 0 ) {
F_7 ( ! F_8 ( V_27 ) ) ;
if ( F_4 ( V_30 -> V_31 , & V_14 ) >= 0 ) {
(* V_1 . V_40 )( V_29 ,
V_14 , V_27 -> V_34 ) ;
V_41 ++ ;
}
}
}
void F_11 ( struct V_39 * V_30 )
{
int V_29 = V_30 -> V_31 -> V_19 -> V_7 ;
struct V_13 V_14 = { . V_20 . V_14 = { 0 } } ;
if ( V_29 >= 0 && F_4 ( V_30 -> V_31 , & V_14 ) >= 0 )
(* V_1 . V_42 )( V_29 , V_14 ) ;
}
void F_12 ( struct V_5 * V_6 )
{
if ( V_6 -> V_7 >= 0 ) {
int V_43 = V_6 -> V_7 ;
V_6 -> V_7 = - 1 ;
(* V_1 . V_44 )( V_43 ) ;
}
}
static int T_2 F_13 ( void )
{
#ifdef F_14
struct V_45 * V_46 = F_15 ( L_1 , NULL ) ;
if ( V_46 == NULL )
return - V_47 ;
F_16 ( L_2 , V_48 , V_46 , & V_35 ) ;
F_16 ( L_3 , V_48 ,
V_46 , & V_36 ) ;
F_16 ( L_4 , V_48 , V_46 , & V_38 ) ;
F_16 ( L_5 , V_48 ,
V_46 , & V_41 ) ;
#endif
return 0 ;
}
