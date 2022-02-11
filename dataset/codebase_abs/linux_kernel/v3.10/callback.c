void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( L_1 , V_2 ) ;
F_3 ( & V_2 -> V_5 ) ;
while ( ! F_4 ( & V_2 -> V_6 ) ) {
V_4 = F_5 ( V_2 -> V_6 . V_7 ,
struct V_3 , V_8 ) ;
F_6 ( L_2 ,
V_4 -> V_9 . V_10 , V_4 -> V_9 . V_4 , V_4 -> V_9 . V_11 ) ;
F_7 ( & V_4 -> V_8 , & V_2 -> V_6 ) ;
V_4 -> V_12 = false ;
}
F_8 ( & V_2 -> V_5 ) ;
F_9 ( L_3 ) ;
}
void F_10 ( struct V_13 * V_14 )
{
struct V_3 * V_4 =
F_11 ( V_14 , struct V_3 , V_15 ) ;
F_2 ( L_3 ) ;
if ( F_12 ( V_16 , & V_4 -> V_17 ) )
return;
if ( ! F_13 ( & V_4 -> V_18 ) )
return;
if ( F_12 ( V_19 , & V_4 -> V_17 ) ) {
if ( F_14 ( V_4 -> V_20 . V_21 ) )
F_15 ( V_4 ) ;
if ( F_16 ( V_4 , NULL , NULL ) < 0 )
goto V_22;
if ( F_12 ( V_16 , & V_4 -> V_17 ) )
goto V_22;
if ( F_17 ( V_23 , & V_4 -> V_17 ) )
F_18 ( V_4 ) ;
}
V_22:
F_19 ( & V_4 -> V_18 ) ;
if ( F_12 ( V_19 , & V_4 -> V_17 ) ) {
F_6 ( L_4 ) ;
F_20 ( V_24 , & V_4 -> V_15 ) ;
}
F_9 ( L_3 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( L_3 ) ;
F_22 ( V_19 , & V_4 -> V_17 ) ;
if ( V_4 -> V_12 ) {
F_3 ( & V_4 -> V_25 ) ;
F_6 ( L_5 ) ;
F_3 ( & V_2 -> V_5 ) ;
if ( V_4 -> V_12 ) {
F_7 ( & V_4 -> V_8 , & V_2 -> V_6 ) ;
V_4 -> V_12 = false ;
}
F_8 ( & V_2 -> V_5 ) ;
F_20 ( V_24 , & V_4 -> V_15 ) ;
if ( F_23 ( & V_4 -> V_26 ) &&
! F_23 ( & V_4 -> V_27 ) )
F_24 ( V_4 ) ;
F_8 ( & V_4 -> V_25 ) ;
}
}
static void F_25 ( struct V_1 * V_2 ,
struct V_28 * V_9 )
{
struct V_3 * V_4 ;
struct V_7 * V_29 ;
F_6 ( L_6 ) ;
F_3 ( & V_2 -> V_30 ) ;
V_29 = V_2 -> V_31 . V_7 ;
while ( V_29 ) {
V_4 = F_5 ( V_29 , struct V_3 , V_32 ) ;
if ( V_9 -> V_10 < V_4 -> V_9 . V_10 )
V_29 = V_29 -> V_33 ;
else if ( V_9 -> V_10 > V_4 -> V_9 . V_10 )
V_29 = V_29 -> V_34 ;
else if ( V_9 -> V_4 < V_4 -> V_9 . V_4 )
V_29 = V_29 -> V_33 ;
else if ( V_9 -> V_4 > V_4 -> V_9 . V_4 )
V_29 = V_29 -> V_34 ;
else if ( V_9 -> V_11 < V_4 -> V_9 . V_11 )
V_29 = V_29 -> V_33 ;
else if ( V_9 -> V_11 > V_4 -> V_9 . V_11 )
V_29 = V_29 -> V_34 ;
else
goto V_35;
}
V_36:
F_6 ( L_7 ) ;
F_8 ( & V_2 -> V_30 ) ;
F_9 ( L_3 ) ;
return;
V_35:
F_6 ( L_8 ) ;
F_26 ( V_2 , == , V_4 -> V_2 ) ;
if ( ! F_27 ( F_28 ( V_4 ) ) )
goto V_36;
F_8 ( & V_2 -> V_30 ) ;
F_21 ( V_2 , V_4 ) ;
F_29 ( & V_4 -> V_20 ) ;
F_9 ( L_3 ) ;
}
void F_30 ( struct V_1 * V_2 , T_1 V_37 ,
struct V_38 V_39 [] )
{
F_2 ( L_9 , V_2 , V_37 ) ;
ASSERT ( V_2 != NULL ) ;
F_26 ( V_37 , <= , V_40 ) ;
for (; V_37 > 0 ; V_39 ++ , V_37 -- ) {
F_6 ( L_10 ,
V_39 -> V_9 . V_10 ,
V_39 -> V_9 . V_4 ,
V_39 -> V_9 . V_11 ,
V_39 -> V_41 ,
V_39 -> V_42 ,
V_39 -> type
) ;
F_25 ( V_2 , & V_39 -> V_9 ) ;
}
F_9 ( L_3 ) ;
return;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_38 * V_43 ;
F_2 ( L_11 , V_2 , V_4 ) ;
V_43 = & V_2 -> V_44 [ V_2 -> V_45 ] ;
V_43 -> V_9 = V_4 -> V_9 ;
V_43 -> V_41 = V_4 -> V_46 ;
V_43 -> V_42 = V_4 -> V_47 ;
V_43 -> type = V_4 -> V_48 ;
F_32 () ;
V_2 -> V_45 =
( V_2 -> V_45 + 1 ) &
( F_33 ( V_2 -> V_44 ) - 1 ) ;
switch ( F_34 ( & V_2 -> V_49 ) ) {
case 1 ... V_40 - 1 :
F_35 ( V_24 ,
& V_2 -> V_50 , V_51 * 2 ) ;
break;
case V_40 :
F_36 ( V_2 ) ;
break;
default:
break;
}
ASSERT ( V_2 -> V_6 . V_7 != NULL ) ;
F_7 ( & V_4 -> V_8 , & V_2 -> V_6 ) ;
V_4 -> V_12 = false ;
F_9 ( L_3 ) ;
}
void F_37 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_2 ( L_12 , V_4 -> V_12 ) ;
if ( ! V_4 -> V_12 ) {
F_9 ( L_13 ) ;
return;
}
ASSERT ( V_2 != NULL ) ;
F_3 ( & V_2 -> V_5 ) ;
if ( V_4 -> V_12 ) {
ASSERT ( V_2 -> V_6 . V_7 != NULL ) ;
F_7 ( & V_4 -> V_8 , & V_2 -> V_6 ) ;
V_4 -> V_12 = false ;
}
F_8 ( & V_2 -> V_5 ) ;
F_9 ( L_3 ) ;
}
void F_38 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_39 ( V_52 , V_53 ) ;
F_2 ( L_12 , V_4 -> V_12 ) ;
F_6 ( L_14 , & V_4 -> V_20 ) ;
if ( ! V_4 -> V_12 ) {
F_9 ( L_13 ) ;
return;
}
ASSERT ( V_2 != NULL ) ;
F_3 ( & V_2 -> V_5 ) ;
if ( V_4 -> V_12 && F_40 ( V_2 ) == 0 ) {
F_41 ( & V_2 -> V_54 , & V_52 ) ;
for (; ; ) {
F_42 ( V_55 ) ;
if ( ! V_4 -> V_12 ||
F_40 ( V_2 ) != 0 )
break;
F_8 ( & V_2 -> V_5 ) ;
F_43 () ;
F_3 ( & V_2 -> V_5 ) ;
}
F_44 ( & V_2 -> V_54 , & V_52 ) ;
F_45 ( V_56 ) ;
}
if ( V_4 -> V_12 )
F_31 ( V_2 , V_4 ) ;
F_8 ( & V_2 -> V_5 ) ;
F_9 ( L_3 ) ;
}
void F_46 ( struct V_13 * V_14 )
{
struct V_1 * V_2 =
F_11 ( V_14 , struct V_1 , V_50 . V_14 ) ;
F_2 ( L_3 ) ;
F_47 ( V_2 , & V_57 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
F_48 ( V_24 , & V_2 -> V_50 , 0 ) ;
}
int T_2 F_49 ( void )
{
V_24 =
F_50 ( L_15 ) ;
return V_24 ? 0 : - V_58 ;
}
void F_51 ( void )
{
F_52 ( V_24 ) ;
}
