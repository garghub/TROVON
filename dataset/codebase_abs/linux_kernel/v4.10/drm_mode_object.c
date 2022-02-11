int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 ,
bool V_6 ,
void (* F_2)( struct V_7 * V_7 ) )
{
int V_8 ;
F_3 ( & V_2 -> V_9 . V_10 ) ;
V_8 = F_4 ( & V_2 -> V_9 . V_11 , V_6 ? V_4 : NULL , 1 , 0 , V_12 ) ;
if ( V_8 >= 0 ) {
V_4 -> V_13 = V_8 ;
V_4 -> type = V_5 ;
if ( F_2 ) {
V_4 -> V_14 = F_2 ;
F_5 ( & V_4 -> V_15 ) ;
}
}
F_6 ( & V_2 -> V_9 . V_10 ) ;
return V_8 < 0 ? V_8 : 0 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
return F_1 ( V_2 , V_4 , V_5 , true , NULL ) ;
}
void F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_3 ( & V_2 -> V_9 . V_10 ) ;
F_9 ( & V_2 -> V_9 . V_11 , V_4 , V_4 -> V_13 ) ;
F_6 ( & V_2 -> V_9 . V_10 ) ;
}
void F_10 ( struct V_1 * V_2 ,
struct V_3 * V_16 )
{
F_3 ( & V_2 -> V_9 . V_10 ) ;
if ( V_16 -> V_13 ) {
F_11 ( & V_2 -> V_9 . V_11 , V_16 -> V_13 ) ;
V_16 -> V_13 = 0 ;
}
F_6 ( & V_2 -> V_9 . V_10 ) ;
}
struct V_3 * F_12 ( struct V_1 * V_2 ,
T_1 V_13 , T_1 type )
{
struct V_3 * V_4 = NULL ;
F_3 ( & V_2 -> V_9 . V_10 ) ;
V_4 = F_13 ( & V_2 -> V_9 . V_11 , V_13 ) ;
if ( V_4 && type != V_17 && V_4 -> type != type )
V_4 = NULL ;
if ( V_4 && V_4 -> V_13 != V_13 )
V_4 = NULL ;
if ( V_4 && V_4 -> V_14 ) {
if ( ! F_14 ( & V_4 -> V_15 ) )
V_4 = NULL ;
}
F_6 ( & V_2 -> V_9 . V_10 ) ;
return V_4 ;
}
struct V_3 * F_15 ( struct V_1 * V_2 ,
T_1 V_13 , T_1 type )
{
struct V_3 * V_4 = NULL ;
V_4 = F_12 ( V_2 , V_13 , type ) ;
return V_4 ;
}
void F_16 ( struct V_3 * V_4 )
{
if ( V_4 -> V_14 ) {
F_17 ( L_1 , V_4 -> V_13 , F_18 ( & V_4 -> V_15 . V_15 ) ) ;
F_19 ( & V_4 -> V_15 , V_4 -> V_14 ) ;
}
}
void F_20 ( struct V_3 * V_4 )
{
if ( V_4 -> V_14 ) {
F_17 ( L_1 , V_4 -> V_13 , F_18 ( & V_4 -> V_15 . V_15 ) ) ;
F_21 ( & V_4 -> V_15 ) ;
}
}
void F_22 ( struct V_3 * V_4 ,
struct V_18 * V_19 ,
T_2 V_20 )
{
int V_21 = V_4 -> V_22 -> V_21 ;
if ( V_21 == V_23 ) {
F_23 ( 1 , L_2
L_3
L_4 ,
V_4 -> type ) ;
return;
}
V_4 -> V_22 -> V_22 [ V_21 ] = V_19 ;
V_4 -> V_22 -> V_24 [ V_21 ] = V_20 ;
V_4 -> V_22 -> V_21 ++ ;
}
int F_24 ( struct V_3 * V_4 ,
struct V_18 * V_19 , T_2 V_25 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_22 -> V_21 ; V_26 ++ ) {
if ( V_4 -> V_22 -> V_22 [ V_26 ] == V_19 ) {
V_4 -> V_22 -> V_24 [ V_26 ] = V_25 ;
return 0 ;
}
}
return - V_27 ;
}
int F_25 ( struct V_3 * V_4 ,
struct V_18 * V_19 , T_2 * V_25 )
{
int V_26 ;
if ( F_26 ( V_19 -> V_2 , V_28 ) &&
! ( V_19 -> V_29 & V_30 ) )
return F_27 ( V_4 , V_19 , V_25 ) ;
for ( V_26 = 0 ; V_26 < V_4 -> V_22 -> V_21 ; V_26 ++ ) {
if ( V_4 -> V_22 -> V_22 [ V_26 ] == V_19 ) {
* V_25 = V_4 -> V_22 -> V_24 [ V_26 ] ;
return 0 ;
}
}
return - V_27 ;
}
int F_28 ( struct V_3 * V_4 , bool V_31 ,
T_1 T_3 * V_32 ,
T_2 T_3 * V_33 ,
T_1 * V_34 )
{
int V_26 , V_8 , V_21 ;
for ( V_26 = 0 , V_21 = 0 ; V_26 < V_4 -> V_22 -> V_21 ; V_26 ++ ) {
struct V_18 * V_35 = V_4 -> V_22 -> V_22 [ V_26 ] ;
T_2 V_25 ;
if ( ( V_35 -> V_29 & V_36 ) && ! V_31 )
continue;
if ( * V_34 > V_21 ) {
V_8 = F_25 ( V_4 , V_35 , & V_25 ) ;
if ( V_8 )
return V_8 ;
if ( F_29 ( V_35 -> V_37 . V_13 , V_32 + V_21 ) )
return - V_38 ;
if ( F_29 ( V_25 , V_33 + V_21 ) )
return - V_38 ;
}
V_21 ++ ;
}
* V_34 = V_21 ;
return 0 ;
}
int F_30 ( struct V_1 * V_2 , void * V_39 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_39 ;
struct V_3 * V_4 ;
int V_8 = 0 ;
if ( ! F_26 ( V_2 , V_44 ) )
return - V_27 ;
F_31 ( V_2 ) ;
V_4 = F_15 ( V_2 , V_43 -> V_45 , V_43 -> V_5 ) ;
if ( ! V_4 ) {
V_8 = - V_46 ;
goto V_47;
}
if ( ! V_4 -> V_22 ) {
V_8 = - V_27 ;
goto V_48;
}
V_8 = F_28 ( V_4 , V_41 -> V_31 ,
( T_1 T_3 * ) ( unsigned long ) ( V_43 -> V_49 ) ,
( T_2 T_3 * ) ( unsigned long ) ( V_43 -> V_50 ) ,
& V_43 -> V_51 ) ;
V_48:
F_16 ( V_4 ) ;
V_47:
F_32 ( V_2 ) ;
return V_8 ;
}
struct V_18 * F_33 ( struct V_3 * V_4 ,
T_1 V_52 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_22 -> V_21 ; V_26 ++ )
if ( V_4 -> V_22 -> V_22 [ V_26 ] -> V_37 . V_13 == V_52 )
return V_4 -> V_22 -> V_22 [ V_26 ] ;
return NULL ;
}
int F_34 ( struct V_1 * V_2 , void * V_39 ,
struct V_40 * V_41 )
{
struct V_53 * V_43 = V_39 ;
struct V_3 * V_54 ;
struct V_18 * V_19 ;
int V_8 = - V_27 ;
struct V_3 * V_55 ;
if ( ! F_26 ( V_2 , V_44 ) )
return - V_27 ;
F_31 ( V_2 ) ;
V_54 = F_15 ( V_2 , V_43 -> V_45 , V_43 -> V_5 ) ;
if ( ! V_54 ) {
V_8 = - V_46 ;
goto V_47;
}
if ( ! V_54 -> V_22 )
goto V_48;
V_19 = F_33 ( V_54 , V_43 -> V_52 ) ;
if ( ! V_19 )
goto V_48;
if ( ! F_35 ( V_19 , V_43 -> V_56 , & V_55 ) )
goto V_48;
switch ( V_54 -> type ) {
case V_57 :
V_8 = F_36 ( V_54 , V_19 ,
V_43 -> V_56 ) ;
break;
case V_58 :
V_8 = F_37 ( V_54 , V_19 , V_43 -> V_56 ) ;
break;
case V_59 :
V_8 = F_38 ( F_39 ( V_54 ) ,
V_19 , V_43 -> V_56 ) ;
break;
}
F_40 ( V_19 , V_55 ) ;
V_48:
F_16 ( V_54 ) ;
V_47:
F_32 ( V_2 ) ;
return V_8 ;
}
