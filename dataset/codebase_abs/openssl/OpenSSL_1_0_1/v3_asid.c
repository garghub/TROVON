int F_1 ( const T_1 * V_1 ,
void * V_2 ,
T_2 * V_3 ,
int V_4 )
{
T_3 * V_5 = V_2 ;
return ( F_2 ( V_3 , V_5 -> V_6 , V_4 ,
L_1 ) &&
F_2 ( V_3 , V_5 -> V_7 , V_4 ,
L_2 ) ) ;
}
static int F_3 ( const T_4 * const * V_8 ,
const T_4 * const * V_9 )
{
const T_4 * V_10 = * V_8 , * V_11 = * V_9 ;
F_4 ( ( V_10 -> type == V_12 && V_10 -> V_13 . V_14 != NULL ) ||
( V_10 -> type == V_15 && V_10 -> V_13 . V_16 != NULL &&
V_10 -> V_13 . V_16 -> V_17 != NULL && V_10 -> V_13 . V_16 -> V_18 != NULL ) ) ;
F_4 ( ( V_11 -> type == V_12 && V_11 -> V_13 . V_14 != NULL ) ||
( V_11 -> type == V_15 && V_11 -> V_13 . V_16 != NULL &&
V_11 -> V_13 . V_16 -> V_17 != NULL && V_11 -> V_13 . V_16 -> V_18 != NULL ) ) ;
if ( V_10 -> type == V_12 && V_11 -> type == V_12 )
return F_5 ( V_10 -> V_13 . V_14 , V_11 -> V_13 . V_14 ) ;
if ( V_10 -> type == V_15 && V_11 -> type == V_15 ) {
int V_19 = F_5 ( V_10 -> V_13 . V_16 -> V_17 , V_11 -> V_13 . V_16 -> V_17 ) ;
return V_19 != 0 ? V_19 : F_5 ( V_10 -> V_13 . V_16 -> V_18 , V_11 -> V_13 . V_16 -> V_18 ) ;
}
if ( V_10 -> type == V_12 )
return F_5 ( V_10 -> V_13 . V_14 , V_11 -> V_13 . V_16 -> V_17 ) ;
else
return F_5 ( V_10 -> V_13 . V_16 -> V_17 , V_11 -> V_13 . V_14 ) ;
}
int F_6 ( T_3 * V_5 , int V_20 )
{
T_5 * * V_21 ;
if ( V_5 == NULL )
return 0 ;
switch ( V_20 ) {
case V_22 :
V_21 = & V_5 -> V_6 ;
break;
case V_23 :
V_21 = & V_5 -> V_7 ;
break;
default:
return 0 ;
}
if ( * V_21 == NULL ) {
if ( ( * V_21 = F_7 () ) == NULL )
return 0 ;
F_4 ( ( * V_21 ) -> V_13 . V_24 == NULL ) ;
if ( ( ( * V_21 ) -> V_13 . V_24 = F_8 () ) == NULL )
return 0 ;
( * V_21 ) -> type = V_25 ;
}
return ( * V_21 ) -> type == V_25 ;
}
int F_9 ( T_3 * V_5 ,
int V_20 ,
T_6 * V_17 ,
T_6 * V_18 )
{
T_5 * * V_21 ;
T_4 * V_26 ;
if ( V_5 == NULL )
return 0 ;
switch ( V_20 ) {
case V_22 :
V_21 = & V_5 -> V_6 ;
break;
case V_23 :
V_21 = & V_5 -> V_7 ;
break;
default:
return 0 ;
}
if ( * V_21 != NULL && ( * V_21 ) -> type == V_25 )
return 0 ;
if ( * V_21 == NULL ) {
if ( ( * V_21 = F_7 () ) == NULL )
return 0 ;
F_4 ( ( * V_21 ) -> V_13 . V_27 == NULL ) ;
( * V_21 ) -> V_13 . V_27 = F_10 ( F_3 ) ;
if ( ( * V_21 ) -> V_13 . V_27 == NULL )
return 0 ;
( * V_21 ) -> type = V_28 ;
}
if ( ( V_26 = F_11 () ) == NULL )
return 0 ;
if ( V_18 == NULL ) {
V_26 -> type = V_12 ;
V_26 -> V_13 . V_14 = V_17 ;
} else {
V_26 -> type = V_15 ;
if ( ( V_26 -> V_13 . V_16 = F_12 () ) == NULL )
goto V_29;
F_13 ( V_26 -> V_13 . V_16 -> V_17 ) ;
V_26 -> V_13 . V_16 -> V_17 = V_17 ;
F_13 ( V_26 -> V_13 . V_16 -> V_18 ) ;
V_26 -> V_13 . V_16 -> V_18 = V_18 ;
}
if ( ! ( F_14 ( ( * V_21 ) -> V_13 . V_27 , V_26 ) ) )
goto V_29;
return 1 ;
V_29:
F_15 ( V_26 ) ;
return 0 ;
}
static void F_16 ( T_4 * V_26 ,
T_6 * * V_17 ,
T_6 * * V_18 )
{
F_4 ( V_26 != NULL && V_17 != NULL && V_18 != NULL ) ;
switch ( V_26 -> type ) {
case V_12 :
* V_17 = V_26 -> V_13 . V_14 ;
* V_18 = V_26 -> V_13 . V_14 ;
return;
case V_15 :
* V_17 = V_26 -> V_13 . V_16 -> V_17 ;
* V_18 = V_26 -> V_13 . V_16 -> V_18 ;
return;
}
}
static int F_17 ( T_5 * V_21 )
{
T_6 * V_30 = NULL ;
T_7 * V_31 = NULL ;
int V_32 , V_33 = 0 ;
if ( V_21 == NULL || V_21 -> type == V_25 )
return 1 ;
if ( V_21 -> type != V_28 ||
F_18 ( V_21 -> V_13 . V_27 ) == 0 )
return 0 ;
for ( V_32 = 0 ; V_32 < F_18 ( V_21 -> V_13 . V_27 ) - 1 ; V_32 ++ ) {
T_4 * V_10 = F_19 ( V_21 -> V_13 . V_27 , V_32 ) ;
T_4 * V_11 = F_19 ( V_21 -> V_13 . V_27 , V_32 + 1 ) ;
T_6 * V_34 , * V_35 , * V_36 , * V_37 ;
F_16 ( V_10 , & V_34 , & V_35 ) ;
F_16 ( V_11 , & V_36 , & V_37 ) ;
if ( F_5 ( V_34 , V_36 ) >= 0 ||
F_5 ( V_34 , V_35 ) > 0 ||
F_5 ( V_36 , V_37 ) > 0 )
goto V_38;
if ( ( V_31 == NULL && ( V_31 = F_20 () ) == NULL ) ||
F_21 ( V_35 , V_31 ) == NULL ||
! F_22 ( V_31 , 1 ) ||
( V_30 = F_23 ( V_31 , V_30 ) ) == NULL ) {
F_24 ( V_39 ,
V_40 ) ;
goto V_38;
}
if ( F_5 ( V_30 , V_36 ) >= 0 )
goto V_38;
}
V_32 = F_18 ( V_21 -> V_13 . V_27 ) - 1 ;
{
T_4 * V_10 = F_19 ( V_21 -> V_13 . V_27 , V_32 ) ;
T_6 * V_34 , * V_35 ;
if ( V_10 != NULL && V_10 -> type == V_15 ) {
F_16 ( V_10 , & V_34 , & V_35 ) ;
if ( F_5 ( V_34 , V_35 ) > 0 )
goto V_38;
}
}
V_33 = 1 ;
V_38:
F_13 ( V_30 ) ;
F_25 ( V_31 ) ;
return V_33 ;
}
int F_26 ( T_3 * V_5 )
{
return ( V_5 == NULL ||
( F_17 ( V_5 -> V_6 ) &&
F_17 ( V_5 -> V_7 ) ) ) ;
}
static int F_27 ( T_5 * V_21 )
{
T_6 * V_30 = NULL ;
T_7 * V_31 = NULL ;
int V_32 , V_33 = 0 ;
if ( V_21 == NULL || V_21 -> type == V_25 )
return 1 ;
if ( V_21 -> type != V_28 ||
F_18 ( V_21 -> V_13 . V_27 ) == 0 ) {
F_24 ( V_41 ,
V_42 ) ;
return 0 ;
}
F_28 ( V_21 -> V_13 . V_27 ) ;
for ( V_32 = 0 ; V_32 < F_18 ( V_21 -> V_13 . V_27 ) - 1 ; V_32 ++ ) {
T_4 * V_10 = F_19 ( V_21 -> V_13 . V_27 , V_32 ) ;
T_4 * V_11 = F_19 ( V_21 -> V_13 . V_27 , V_32 + 1 ) ;
T_6 * V_34 , * V_35 , * V_36 , * V_37 ;
F_16 ( V_10 , & V_34 , & V_35 ) ;
F_16 ( V_11 , & V_36 , & V_37 ) ;
F_4 ( F_5 ( V_34 , V_36 ) <= 0 ) ;
if ( F_5 ( V_34 , V_35 ) > 0 ||
F_5 ( V_36 , V_37 ) > 0 )
goto V_38;
if ( F_5 ( V_35 , V_36 ) >= 0 ) {
F_24 ( V_41 ,
V_42 ) ;
goto V_38;
}
if ( ( V_31 == NULL && ( V_31 = F_20 () ) == NULL ) ||
F_21 ( V_35 , V_31 ) == NULL ||
! F_22 ( V_31 , 1 ) ||
( V_30 = F_23 ( V_31 , V_30 ) ) == NULL ) {
F_24 ( V_41 , V_40 ) ;
goto V_38;
}
if ( F_5 ( V_30 , V_36 ) == 0 ) {
T_8 * V_19 ;
switch ( V_10 -> type ) {
case V_12 :
if ( ( V_19 = F_29 ( sizeof( T_8 ) ) ) == NULL ) {
F_24 ( V_41 ,
V_40 ) ;
goto V_38;
}
V_19 -> V_17 = V_34 ;
V_19 -> V_18 = V_37 ;
V_10 -> type = V_15 ;
V_10 -> V_13 . V_16 = V_19 ;
break;
case V_15 :
F_13 ( V_10 -> V_13 . V_16 -> V_18 ) ;
V_10 -> V_13 . V_16 -> V_18 = V_37 ;
break;
}
switch ( V_11 -> type ) {
case V_12 :
V_11 -> V_13 . V_14 = NULL ;
break;
case V_15 :
V_11 -> V_13 . V_16 -> V_18 = NULL ;
break;
}
F_15 ( V_11 ) ;
( void ) F_30 ( V_21 -> V_13 . V_27 , V_32 + 1 ) ;
V_32 -- ;
continue;
}
}
V_32 = F_18 ( V_21 -> V_13 . V_27 ) - 1 ;
{
T_4 * V_10 = F_19 ( V_21 -> V_13 . V_27 , V_32 ) ;
T_6 * V_34 , * V_35 ;
if ( V_10 != NULL && V_10 -> type == V_15 ) {
F_16 ( V_10 , & V_34 , & V_35 ) ;
if ( F_5 ( V_34 , V_35 ) > 0 )
goto V_38;
}
}
F_4 ( F_17 ( V_21 ) ) ;
V_33 = 1 ;
V_38:
F_13 ( V_30 ) ;
F_25 ( V_31 ) ;
return V_33 ;
}
int F_31 ( T_3 * V_5 )
{
return ( V_5 == NULL ||
( F_27 ( V_5 -> V_6 ) &&
F_27 ( V_5 -> V_7 ) ) ) ;
}
int F_32 ( T_3 * V_5 )
{
return ( V_5 != NULL &&
( ( V_5 -> V_6 != NULL &&
V_5 -> V_6 -> type == V_25 ) ||
( V_5 -> V_7 != NULL &&
V_5 -> V_7 -> type == V_25 ) ) ) ;
}
static int F_33 ( T_9 * V_43 , T_9 * V_44 )
{
T_6 * V_45 , * V_46 , * V_47 , * V_48 ;
int V_49 , V_50 ;
if ( V_44 == NULL || V_43 == V_44 )
return 1 ;
if ( V_43 == NULL )
return 0 ;
V_49 = 0 ;
for ( V_50 = 0 ; V_50 < F_18 ( V_44 ) ; V_50 ++ ) {
F_16 ( F_19 ( V_44 , V_50 ) , & V_47 , & V_48 ) ;
for (; ; V_49 ++ ) {
if ( V_49 >= F_18 ( V_43 ) )
return 0 ;
F_16 ( F_19 ( V_43 , V_49 ) , & V_45 , & V_46 ) ;
if ( F_5 ( V_46 , V_48 ) < 0 )
continue;
if ( F_5 ( V_45 , V_47 ) > 0 )
return 0 ;
break;
}
}
return 1 ;
}
int F_34 ( T_3 * V_10 , T_3 * V_11 )
{
return ( V_10 == NULL ||
V_10 == V_11 ||
( V_11 != NULL &&
! F_32 ( V_10 ) &&
! F_32 ( V_11 ) &&
F_33 ( V_11 -> V_6 -> V_13 . V_27 ,
V_10 -> V_6 -> V_13 . V_27 ) &&
F_33 ( V_11 -> V_7 -> V_13 . V_27 ,
V_10 -> V_7 -> V_13 . V_27 ) ) ) ;
}
int F_35 ( T_10 * V_51 )
{
return F_36 ( V_51 , V_51 -> V_52 , NULL ) ;
}
