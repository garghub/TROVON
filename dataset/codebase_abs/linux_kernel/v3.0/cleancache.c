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
int (* F_5)( struct V_15 * , T_1 * V_16 , int * , int );
int V_17 = 0 , V_18 = V_19 ;
struct V_5 * V_6 = V_12 -> V_20 ;
V_14 -> V_21 . V_22 = V_12 -> V_23 ;
if ( V_6 -> V_24 != NULL ) {
F_5 = V_6 -> V_24 -> V_25 ;
if ( F_5 ) {
struct V_15 V_26 ;
V_26 . V_27 = V_12 ;
V_17 = (* F_5)( & V_26 , & V_14 -> V_21 . V_16 [ 0 ] , & V_18 , 0 ) ;
if ( V_17 <= 0 || V_17 == 255 )
return - 1 ;
if ( V_18 > V_19 )
return - 1 ;
}
}
return 0 ;
}
int F_6 ( struct V_28 * V_28 )
{
int V_29 = - 1 ;
int V_30 ;
struct V_13 V_14 = { . V_21 . V_14 = { 0 } } ;
F_7 ( ! F_8 ( V_28 ) ) ;
V_30 = V_28 -> V_31 -> V_32 -> V_20 -> V_7 ;
if ( V_30 < 0 )
goto V_33;
if ( F_4 ( V_28 -> V_31 -> V_32 , & V_14 ) < 0 )
goto V_33;
V_29 = (* V_1 . V_34 )( V_30 , V_14 , V_28 -> V_35 , V_28 ) ;
if ( V_29 == 0 )
V_36 ++ ;
else
V_37 ++ ;
V_33:
return V_29 ;
}
void F_9 ( struct V_28 * V_28 )
{
int V_30 ;
struct V_13 V_14 = { . V_21 . V_14 = { 0 } } ;
F_7 ( ! F_8 ( V_28 ) ) ;
V_30 = V_28 -> V_31 -> V_32 -> V_20 -> V_7 ;
if ( V_30 >= 0 &&
F_4 ( V_28 -> V_31 -> V_32 , & V_14 ) >= 0 ) {
(* V_1 . V_38 )( V_30 , V_14 , V_28 -> V_35 , V_28 ) ;
V_39 ++ ;
}
}
void F_10 ( struct V_40 * V_31 , struct V_28 * V_28 )
{
int V_30 = V_31 -> V_32 -> V_20 -> V_7 ;
struct V_13 V_14 = { . V_21 . V_14 = { 0 } } ;
if ( V_30 >= 0 ) {
F_7 ( ! F_8 ( V_28 ) ) ;
if ( F_4 ( V_31 -> V_32 , & V_14 ) >= 0 ) {
(* V_1 . V_41 )( V_30 , V_14 , V_28 -> V_35 ) ;
V_42 ++ ;
}
}
}
void F_11 ( struct V_40 * V_31 )
{
int V_30 = V_31 -> V_32 -> V_20 -> V_7 ;
struct V_13 V_14 = { . V_21 . V_14 = { 0 } } ;
if ( V_30 >= 0 && F_4 ( V_31 -> V_32 , & V_14 ) >= 0 )
(* V_1 . V_43 )( V_30 , V_14 ) ;
}
void F_12 ( struct V_5 * V_6 )
{
if ( V_6 -> V_7 >= 0 ) {
int V_44 = V_6 -> V_7 ;
V_6 -> V_7 = - 1 ;
(* V_1 . V_45 )( V_44 ) ;
}
}
static int T_2 F_13 ( void )
{
#ifdef F_14
int V_46 ;
V_46 = F_15 ( V_47 , & V_48 ) ;
#endif
return 0 ;
}
