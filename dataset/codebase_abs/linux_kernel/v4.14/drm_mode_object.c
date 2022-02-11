int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , bool V_6 ,
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
F_17 ( L_1 , V_4 -> V_13 , F_18 ( & V_4 -> V_15 ) ) ;
F_19 ( & V_4 -> V_15 , V_4 -> V_14 ) ;
}
}
void F_20 ( struct V_3 * V_4 )
{
if ( V_4 -> V_14 ) {
F_17 ( L_1 , V_4 -> V_13 , F_18 ( & V_4 -> V_15 ) ) ;
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
F_25 ( F_26 ( V_19 -> V_2 ) &&
! ( V_19 -> V_27 & V_28 ) ) ;
for ( V_26 = 0 ; V_26 < V_4 -> V_22 -> V_21 ; V_26 ++ ) {
if ( V_4 -> V_22 -> V_22 [ V_26 ] == V_19 ) {
V_4 -> V_22 -> V_24 [ V_26 ] = V_25 ;
return 0 ;
}
}
return - V_29 ;
}
int F_27 ( struct V_3 * V_4 ,
struct V_18 * V_19 , T_2 * V_25 )
{
int V_26 ;
if ( F_26 ( V_19 -> V_2 ) &&
! ( V_19 -> V_27 & V_28 ) )
return F_28 ( V_4 , V_19 , V_25 ) ;
for ( V_26 = 0 ; V_26 < V_4 -> V_22 -> V_21 ; V_26 ++ ) {
if ( V_4 -> V_22 -> V_22 [ V_26 ] == V_19 ) {
* V_25 = V_4 -> V_22 -> V_24 [ V_26 ] ;
return 0 ;
}
}
return - V_29 ;
}
int F_29 ( struct V_3 * V_4 ,
struct V_18 * V_19 , T_2 * V_25 )
{
F_25 ( F_26 ( V_19 -> V_2 ) ) ;
return F_27 ( V_4 , V_19 , V_25 ) ;
}
int F_30 ( struct V_3 * V_4 , bool V_30 ,
T_1 T_3 * V_31 ,
T_2 T_3 * V_32 ,
T_1 * V_33 )
{
int V_26 , V_8 , V_21 ;
for ( V_26 = 0 , V_21 = 0 ; V_26 < V_4 -> V_22 -> V_21 ; V_26 ++ ) {
struct V_18 * V_34 = V_4 -> V_22 -> V_22 [ V_26 ] ;
T_2 V_25 ;
if ( ( V_34 -> V_27 & V_35 ) && ! V_30 )
continue;
if ( * V_33 > V_21 ) {
V_8 = F_27 ( V_4 , V_34 , & V_25 ) ;
if ( V_8 )
return V_8 ;
if ( F_31 ( V_34 -> V_36 . V_13 , V_31 + V_21 ) )
return - V_37 ;
if ( F_31 ( V_25 , V_32 + V_21 ) )
return - V_37 ;
}
V_21 ++ ;
}
* V_33 = V_21 ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 , void * V_38 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = V_38 ;
struct V_3 * V_4 ;
int V_8 = 0 ;
if ( ! F_33 ( V_2 , V_43 ) )
return - V_29 ;
F_34 ( V_2 ) ;
V_4 = F_15 ( V_2 , V_42 -> V_44 , V_42 -> V_5 ) ;
if ( ! V_4 ) {
V_8 = - V_45 ;
goto V_46;
}
if ( ! V_4 -> V_22 ) {
V_8 = - V_29 ;
goto V_47;
}
V_8 = F_30 ( V_4 , V_40 -> V_30 ,
( T_1 T_3 * ) ( unsigned long ) ( V_42 -> V_48 ) ,
( T_2 T_3 * ) ( unsigned long ) ( V_42 -> V_49 ) ,
& V_42 -> V_50 ) ;
V_47:
F_16 ( V_4 ) ;
V_46:
F_35 ( V_2 ) ;
return V_8 ;
}
struct V_18 * F_36 ( struct V_3 * V_4 ,
T_1 V_51 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_22 -> V_21 ; V_26 ++ )
if ( V_4 -> V_22 -> V_22 [ V_26 ] -> V_36 . V_13 == V_51 )
return V_4 -> V_22 -> V_22 [ V_26 ] ;
return NULL ;
}
static int F_37 ( struct V_3 * V_4 ,
struct V_18 * V_34 ,
T_2 V_52 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_3 * V_53 ;
int V_8 = - V_29 ;
if ( ! F_38 ( V_34 , V_52 , & V_53 ) )
return - V_29 ;
F_34 ( V_2 ) ;
switch ( V_4 -> type ) {
case V_54 :
V_8 = F_39 ( V_4 , V_34 ,
V_52 ) ;
break;
case V_55 :
V_8 = F_40 ( V_4 , V_34 , V_52 ) ;
break;
case V_56 :
V_8 = F_41 ( F_42 ( V_4 ) ,
V_34 , V_52 ) ;
break;
}
F_43 ( V_34 , V_53 ) ;
F_35 ( V_2 ) ;
return V_8 ;
}
static int F_44 ( struct V_3 * V_4 ,
struct V_18 * V_34 ,
T_2 V_52 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_57 * V_58 ;
struct V_59 V_60 ;
int V_8 ;
F_45 ( & V_60 , 0 ) ;
V_58 = F_46 ( V_2 ) ;
if ( ! V_58 )
return - V_61 ;
V_58 -> V_62 = & V_60 ;
V_63:
if ( V_34 == V_58 -> V_2 -> V_9 . V_64 ) {
if ( V_4 -> type != V_54 ) {
V_8 = - V_29 ;
goto V_46;
}
V_8 = F_47 ( V_58 ,
F_48 ( V_4 ) ,
V_52 ) ;
} else {
V_8 = F_49 ( V_58 , V_4 , V_34 , V_52 ) ;
if ( V_8 )
goto V_46;
V_8 = F_50 ( V_58 ) ;
}
V_46:
if ( V_8 == - V_65 ) {
F_51 ( V_58 ) ;
F_52 ( & V_60 ) ;
goto V_63;
}
F_53 ( V_58 ) ;
F_54 ( & V_60 ) ;
F_55 ( & V_60 ) ;
return V_8 ;
}
int F_56 ( struct V_1 * V_2 , void * V_38 ,
struct V_39 * V_40 )
{
struct V_66 * V_42 = V_38 ;
struct V_3 * V_67 ;
struct V_18 * V_19 ;
int V_8 = - V_29 ;
if ( ! F_33 ( V_2 , V_43 ) )
return - V_29 ;
V_67 = F_15 ( V_2 , V_42 -> V_44 , V_42 -> V_5 ) ;
if ( ! V_67 )
return - V_45 ;
if ( ! V_67 -> V_22 )
goto V_47;
V_19 = F_36 ( V_67 , V_42 -> V_51 ) ;
if ( ! V_19 )
goto V_47;
if ( F_26 ( V_19 -> V_2 ) )
V_8 = F_44 ( V_67 , V_19 , V_42 -> V_68 ) ;
else
V_8 = F_37 ( V_67 , V_19 , V_42 -> V_68 ) ;
V_47:
F_16 ( V_67 ) ;
return V_8 ;
}
