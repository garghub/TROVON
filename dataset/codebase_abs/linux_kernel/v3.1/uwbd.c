static
int F_1 ( struct V_1 * V_2 )
{
int V_3 = - V_4 ;
struct V_5 * V_6 ;
T_1 V_7 ;
T_2 type , V_8 ;
T_3 V_9 ;
type = V_2 -> V_10 . V_11 -> V_12 ;
V_9 = F_2 ( V_2 -> V_10 . V_11 -> V_13 ) ;
V_8 = V_2 -> V_10 . V_11 -> V_14 ;
if ( type >= F_3 ( V_15 ) )
goto V_16;
V_6 = & V_15 [ type ] ;
if ( V_6 -> V_17 == NULL )
goto V_16;
if ( V_9 >= V_6 -> V_18 )
goto V_16;
V_7 = V_6 -> V_17 [ V_9 ] . V_7 ;
if ( V_7 == NULL )
goto V_16;
V_3 = (* V_7)( V_2 ) ;
V_16:
if ( V_3 < 0 )
F_4 ( & V_2 -> V_19 -> V_20 . V_21 ,
L_1 ,
type , V_9 , V_8 , V_3 ) ;
return V_3 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_22 * V_19 ;
int V_3 ;
V_19 = V_2 -> V_19 ;
if ( V_2 -> V_23 < 0 || V_2 -> V_23 >= F_3 ( V_24 ) ) {
F_4 ( & V_19 -> V_20 . V_21 , L_2 , V_2 -> V_23 ) ;
return;
}
V_3 = V_24 [ V_2 -> V_23 ] . V_7 ( V_2 ) ;
if ( V_3 < 0 )
F_4 ( & V_19 -> V_20 . V_21 , L_3 ,
V_24 [ V_2 -> V_23 ] . V_25 , V_3 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_22 * V_19 ;
int V_26 ;
V_19 = V_2 -> V_19 ;
if ( V_19 -> V_27 ) {
switch ( V_2 -> type ) {
case V_28 :
V_26 = F_1 ( V_2 ) ;
if ( V_26 <= 0 )
F_7 ( V_2 -> V_10 . V_11 ) ;
break;
case V_29 :
F_5 ( V_2 ) ;
break;
default:
F_4 ( & V_19 -> V_20 . V_21 , L_4 , V_2 -> type ) ;
break;
}
}
F_8 ( V_19 ) ;
}
static int F_9 ( void * V_30 )
{
struct V_22 * V_19 = V_30 ;
unsigned long V_31 ;
struct V_1 * V_2 ;
int V_32 = 0 ;
while ( 1 ) {
F_10 (
V_19 -> F_9 . V_33 ,
! F_11 ( & V_19 -> F_9 . V_34 )
|| ( V_32 = F_12 () ) ,
V_35 ) ;
if ( V_32 )
break;
F_13 () ;
F_14 ( & V_19 -> F_9 . V_36 , V_31 ) ;
if ( ! F_11 ( & V_19 -> F_9 . V_34 ) ) {
V_2 = F_15 ( & V_19 -> F_9 . V_34 , struct V_1 , V_37 ) ;
F_16 ( & V_2 -> V_37 ) ;
} else
V_2 = NULL ;
F_17 ( & V_19 -> F_9 . V_36 , V_31 ) ;
if ( V_2 ) {
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
}
F_18 ( V_19 ) ;
}
return 0 ;
}
void F_19 ( struct V_22 * V_19 )
{
V_19 -> F_9 . V_38 = F_20 ( F_9 , V_19 , L_5 ) ;
if ( V_19 -> F_9 . V_38 == NULL )
F_21 ( V_39 L_6
L_7 ) ;
else
V_19 -> F_9 . V_40 = V_19 -> F_9 . V_38 -> V_40 ;
}
void F_22 ( struct V_22 * V_19 )
{
F_23 ( V_19 -> F_9 . V_38 ) ;
F_24 ( V_19 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
struct V_22 * V_19 = V_2 -> V_19 ;
unsigned long V_31 ;
F_14 ( & V_19 -> F_9 . V_36 , V_31 ) ;
if ( V_19 -> F_9 . V_40 != 0 ) {
F_26 ( & V_2 -> V_37 , & V_19 -> F_9 . V_34 ) ;
F_27 ( & V_19 -> F_9 . V_33 ) ;
} else {
F_8 ( V_2 -> V_19 ) ;
if ( V_2 -> type == V_28 )
F_7 ( V_2 -> V_10 . V_11 ) ;
F_7 ( V_2 ) ;
}
F_17 ( & V_19 -> F_9 . V_36 , V_31 ) ;
return;
}
void F_24 ( struct V_22 * V_19 )
{
struct V_1 * V_2 , * V_41 ;
F_28 ( & V_19 -> F_9 . V_36 ) ;
F_29 (evt, nxt, &rc->uwbd.event_list, list_node) {
if ( V_2 -> V_19 == V_19 ) {
F_8 ( V_19 ) ;
F_16 ( & V_2 -> V_37 ) ;
if ( V_2 -> type == V_28 )
F_7 ( V_2 -> V_10 . V_11 ) ;
F_7 ( V_2 ) ;
}
}
F_30 ( & V_19 -> F_9 . V_36 ) ;
}
