static int F_1 ( void )
{
int V_1 ;
V_1 = 0 ;
if ( ! V_2 ) {
F_2 ( & V_3 ) ;
if ( ! V_2 ) {
V_2 =
F_3 ( L_1 ) ;
if ( ! V_2 )
V_1 = - V_4 ;
}
F_4 ( & V_3 ) ;
}
return V_1 ;
}
void T_1 F_5 ( void )
{
if ( V_2 )
F_6 ( V_2 ) ;
}
void F_7 ( struct V_5 * V_6 )
{
F_8 ( L_2 , V_6 -> V_7 . V_8 , V_6 -> V_7 . V_6 ) ;
F_9 ( V_2 , & V_6 -> V_9 , 0 ) ;
}
static void F_10 ( struct V_5 * V_6 )
{
F_9 ( V_2 , & V_6 -> V_9 ,
V_10 * V_11 / 2 ) ;
}
static void F_11 ( struct V_5 * V_6 , struct V_12 * V_13 )
{
struct V_12 * V_14 , * V_15 ;
F_12 ( & V_13 -> V_16 . V_17 . V_18 , & V_6 -> V_19 ) ;
if ( V_13 -> V_20 == V_21 ) {
F_13 (p, _p, &vnode->pending_locks,
fl_u.afs.link) {
if ( V_14 -> V_20 == V_21 ) {
V_14 -> V_16 . V_17 . V_22 = V_23 ;
F_12 ( & V_14 -> V_16 . V_17 . V_18 ,
& V_6 -> V_19 ) ;
F_14 ( & V_14 -> V_24 ) ;
}
}
}
}
void F_15 ( struct V_25 * V_26 )
{
struct V_5 * V_6 =
F_16 ( V_26 , struct V_5 , V_9 . V_26 ) ;
struct V_12 * V_13 ;
T_2 type ;
struct V_27 * V_27 ;
int V_1 ;
F_8 ( L_2 , V_6 -> V_7 . V_8 , V_6 -> V_7 . V_6 ) ;
F_17 ( & V_6 -> V_28 ) ;
if ( F_18 ( V_29 , & V_6 -> V_30 ) ) {
F_19 ( L_3 ) ;
F_20 ( & V_6 -> V_28 ) ;
V_1 = F_21 ( V_6 , V_6 -> V_31 ) ;
if ( V_1 < 0 )
F_22 ( V_32 L_4
L_5 ,
V_6 -> V_7 . V_8 , V_6 -> V_7 . V_6 , V_1 ) ;
F_17 ( & V_6 -> V_28 ) ;
F_23 ( V_6 -> V_31 ) ;
V_6 -> V_31 = NULL ;
F_24 ( V_29 , & V_6 -> V_30 ) ;
}
if ( ! F_25 ( & V_6 -> V_19 ) ) {
F_19 ( L_6 ) ;
if ( F_26 ( V_33 , & V_6 -> V_30 ) )
F_27 () ;
V_13 = F_28 ( V_6 -> V_19 . V_34 ,
struct V_12 , V_16 . V_17 . V_18 ) ;
V_27 = F_29 ( V_13 -> V_35 -> V_36 ) ;
F_20 ( & V_6 -> V_28 ) ;
V_1 = F_30 ( V_6 , V_27 ) ;
F_24 ( V_33 , & V_6 -> V_30 ) ;
F_23 ( V_27 ) ;
switch ( V_1 ) {
case 0 :
F_10 ( V_6 ) ;
break;
default:
F_22 ( V_32 L_4
L_7 ,
V_6 -> V_7 . V_8 , V_6 -> V_7 . V_6 , V_1 ) ;
F_9 ( V_2 , & V_6 -> V_9 ,
V_11 * 10 ) ;
break;
}
F_31 ( L_8 ) ;
return;
}
if ( ! F_25 ( & V_6 -> V_37 ) ) {
F_19 ( L_9 ) ;
if ( F_26 ( V_33 , & V_6 -> V_30 ) )
F_27 () ;
V_13 = F_28 ( V_6 -> V_37 . V_34 ,
struct V_12 , V_16 . V_17 . V_18 ) ;
V_27 = F_29 ( V_13 -> V_35 -> V_36 ) ;
type = ( V_13 -> V_20 == V_21 ) ?
V_38 : V_39 ;
F_20 ( & V_6 -> V_28 ) ;
V_1 = F_32 ( V_6 , V_27 , type ) ;
F_24 ( V_33 , & V_6 -> V_30 ) ;
switch ( V_1 ) {
case - V_40 :
F_19 ( L_10 ) ;
break;
case 0 :
F_19 ( L_11 ) ;
if ( type == V_38 )
F_33 ( V_41 , & V_6 -> V_30 ) ;
else
F_33 ( V_42 , & V_6 -> V_30 ) ;
V_1 = V_23 ;
default:
F_17 ( & V_6 -> V_28 ) ;
if ( F_28 ( V_6 -> V_37 . V_34 ,
struct V_12 , V_16 . V_17 . V_18 ) == V_13 ) {
V_13 -> V_16 . V_17 . V_22 = V_1 ;
if ( V_1 == V_23 )
F_11 ( V_6 , V_13 ) ;
else
F_34 ( & V_13 -> V_16 . V_17 . V_18 ) ;
F_14 ( & V_13 -> V_24 ) ;
F_20 ( & V_6 -> V_28 ) ;
} else {
F_19 ( L_12 ) ;
F_24 ( V_41 , & V_6 -> V_30 ) ;
F_24 ( V_42 , & V_6 -> V_30 ) ;
F_20 ( & V_6 -> V_28 ) ;
F_21 ( V_6 , V_27 ) ;
if ( ! F_25 ( & V_6 -> V_37 ) )
F_7 ( V_6 ) ;
}
break;
}
F_23 ( V_27 ) ;
F_31 ( L_13 ) ;
return;
}
F_20 ( & V_6 -> V_28 ) ;
F_31 ( L_14 ) ;
}
static void F_35 ( struct V_5 * V_6 , struct V_27 * V_27 )
{
F_36 ( & V_6 -> V_9 ) ;
if ( ! F_37 ( V_41 , & V_6 -> V_30 ) &&
! F_37 ( V_42 , & V_6 -> V_30 ) )
F_27 () ;
if ( F_26 ( V_29 , & V_6 -> V_30 ) )
F_27 () ;
V_6 -> V_31 = F_29 ( V_27 ) ;
F_7 ( V_6 ) ;
}
static int F_38 ( struct V_43 * V_43 , struct V_12 * V_13 )
{
struct V_44 * V_44 = F_39 ( V_43 ) ;
struct V_5 * V_6 = F_40 ( V_44 ) ;
T_2 type ;
struct V_27 * V_27 = V_43 -> V_36 ;
int V_1 ;
F_8 ( L_15 , V_6 -> V_7 . V_8 , V_6 -> V_7 . V_6 , V_13 -> V_20 ) ;
if ( V_13 -> V_45 != 0 || V_13 -> V_46 != V_47 )
return - V_48 ;
V_1 = F_1 () ;
if ( V_1 < 0 )
return V_1 ;
V_13 -> V_49 = & V_50 ;
F_41 ( & V_13 -> V_16 . V_17 . V_18 ) ;
V_13 -> V_16 . V_17 . V_22 = V_51 ;
type = ( V_13 -> V_20 == V_21 ) ? V_38 : V_39 ;
F_17 ( & V_44 -> V_52 ) ;
V_1 = F_42 ( V_6 , NULL , V_27 ) ;
if ( V_1 < 0 )
goto error;
if ( V_6 -> V_53 . V_54 != 0 && ! ( V_13 -> V_55 & V_56 ) ) {
V_1 = - V_57 ;
goto error;
}
F_17 ( & V_6 -> V_28 ) ;
if ( type == V_38 &&
V_6 -> V_30 & ( 1 << V_41 ) ) {
F_19 ( L_16 ) ;
F_43 ( V_6 -> V_30 &
( ( 1 << V_33 ) |
( 1 << V_42 ) ) , == , 0 ) ;
ASSERT ( ! F_25 ( & V_6 -> V_19 ) ) ;
goto V_58;
}
if ( F_25 ( & V_6 -> V_37 ) &&
F_25 ( & V_6 -> V_19 ) ) {
F_19 ( L_17 ) ;
F_43 ( V_6 -> V_30 &
( ( 1 << V_33 ) |
( 1 << V_41 ) |
( 1 << V_42 ) ) , == , 0 ) ;
F_44 ( & V_13 -> V_16 . V_17 . V_18 , & V_6 -> V_37 ) ;
F_33 ( V_33 , & V_6 -> V_30 ) ;
F_20 ( & V_6 -> V_28 ) ;
V_1 = F_32 ( V_6 , V_27 , type ) ;
F_24 ( V_33 , & V_6 -> V_30 ) ;
switch ( V_1 ) {
case 0 :
F_19 ( L_11 ) ;
goto V_59;
case - V_40 :
F_19 ( L_18 ) ;
F_17 ( & V_6 -> V_28 ) ;
ASSERT ( F_25 ( & V_6 -> V_19 ) ) ;
F_43 ( V_6 -> V_37 . V_34 , == ,
& V_13 -> V_16 . V_17 . V_18 ) ;
goto V_60;
default:
F_17 ( & V_6 -> V_28 ) ;
F_34 ( & V_13 -> V_16 . V_17 . V_18 ) ;
F_20 ( & V_6 -> V_28 ) ;
goto error;
}
}
F_19 ( L_19 ) ;
F_44 ( & V_13 -> V_16 . V_17 . V_18 , & V_6 -> V_37 ) ;
V_60:
if ( ! ( V_13 -> V_55 & V_56 ) ) {
F_19 ( L_20 ) ;
V_1 = - V_57 ;
goto V_61;
}
F_20 ( & V_6 -> V_28 ) ;
F_19 ( L_21 ) ;
V_1 = F_45 ( V_13 -> V_24 ,
V_13 -> V_16 . V_17 . V_22 <= V_23 ) ;
if ( V_13 -> V_16 . V_17 . V_22 <= V_23 ) {
V_1 = V_13 -> V_16 . V_17 . V_22 ;
if ( V_1 < 0 )
goto error;
F_17 ( & V_6 -> V_28 ) ;
goto V_62;
}
F_19 ( L_22 ) ;
F_43 ( V_1 , == , - V_63 ) ;
F_17 ( & V_6 -> V_28 ) ;
if ( V_13 -> V_16 . V_17 . V_22 <= V_23 ) {
V_1 = V_13 -> V_16 . V_17 . V_22 ;
if ( V_1 < 0 ) {
F_20 ( & V_6 -> V_28 ) ;
goto error;
}
goto V_62;
}
V_61:
F_19 ( L_23 ) ;
if ( F_25 ( & V_6 -> V_19 ) &&
V_6 -> V_37 . V_34 == & V_13 -> V_16 . V_17 . V_18 ) {
if ( V_6 -> V_37 . V_64 != & V_13 -> V_16 . V_17 . V_18 ) {
F_34 ( & V_13 -> V_16 . V_17 . V_18 ) ;
F_7 ( V_6 ) ;
}
} else {
F_34 ( & V_13 -> V_16 . V_17 . V_18 ) ;
}
F_20 ( & V_6 -> V_28 ) ;
goto error;
V_59:
F_17 ( & V_6 -> V_28 ) ;
F_10 ( V_6 ) ;
if ( type == V_38 )
F_33 ( V_41 , & V_6 -> V_30 ) ;
else
F_33 ( V_42 , & V_6 -> V_30 ) ;
V_58:
V_13 -> V_16 . V_17 . V_22 = V_23 ;
F_12 ( & V_13 -> V_16 . V_17 . V_18 , & V_6 -> V_19 ) ;
V_62:
ASSERT ( ! ( V_6 -> V_30 & ( 1 << V_33 ) ) ) ;
ASSERT ( ( V_6 -> V_30 & ( ( 1 << V_41 ) |
( 1 << V_42 ) ) ) != 0 ) ;
V_1 = F_46 ( V_43 , V_13 , NULL ) ;
if ( V_1 < 0 )
goto V_65;
F_20 ( & V_6 -> V_28 ) ;
F_42 ( V_6 , NULL , V_27 ) ;
error:
F_20 ( & V_44 -> V_52 ) ;
F_31 ( L_24 , V_1 ) ;
return V_1 ;
V_65:
F_19 ( L_25 , V_1 ) ;
F_34 ( & V_13 -> V_16 . V_17 . V_18 ) ;
if ( F_25 ( & V_6 -> V_19 ) )
F_35 ( V_6 , V_27 ) ;
goto V_61;
}
static int F_47 ( struct V_43 * V_43 , struct V_12 * V_13 )
{
struct V_5 * V_6 = F_40 ( V_43 -> V_66 -> V_67 ) ;
struct V_27 * V_27 = V_43 -> V_36 ;
int V_1 ;
F_8 ( L_15 , V_6 -> V_7 . V_8 , V_6 -> V_7 . V_6 , V_13 -> V_20 ) ;
if ( V_13 -> V_45 != 0 || V_13 -> V_46 != V_47 )
return - V_48 ;
V_13 -> V_49 = & V_50 ;
F_41 ( & V_13 -> V_16 . V_17 . V_18 ) ;
V_13 -> V_16 . V_17 . V_22 = V_51 ;
F_17 ( & V_6 -> V_28 ) ;
V_1 = F_46 ( V_43 , V_13 , NULL ) ;
if ( V_1 < 0 ) {
F_20 ( & V_6 -> V_28 ) ;
F_31 ( L_26 , V_1 ) ;
return V_1 ;
}
if ( F_25 ( & V_6 -> V_19 ) )
F_35 ( V_6 , V_27 ) ;
F_20 ( & V_6 -> V_28 ) ;
F_31 ( L_27 ) ;
return 0 ;
}
static int F_48 ( struct V_43 * V_43 , struct V_12 * V_13 )
{
struct V_5 * V_6 = F_40 ( V_43 -> V_66 -> V_67 ) ;
struct V_27 * V_27 = V_43 -> V_36 ;
int V_1 , V_54 ;
F_8 ( L_28 ) ;
V_13 -> V_20 = V_68 ;
F_2 ( & V_6 -> V_69 . V_70 ) ;
V_1 = 0 ;
F_49 ( V_43 , V_13 ) ;
if ( V_13 -> V_20 == V_68 ) {
V_1 = F_42 ( V_6 , NULL , V_27 ) ;
if ( V_1 < 0 )
goto error;
V_54 = V_6 -> V_53 . V_54 ;
if ( V_54 ) {
if ( V_54 > 0 )
V_13 -> V_20 = V_21 ;
else
V_13 -> V_20 = V_71 ;
V_13 -> V_45 = 0 ;
V_13 -> V_46 = V_47 ;
}
}
error:
F_4 ( & V_6 -> V_69 . V_70 ) ;
F_31 ( L_29 , V_1 , V_13 -> V_20 ) ;
return V_1 ;
}
int F_50 ( struct V_43 * V_43 , int V_72 , struct V_12 * V_13 )
{
struct V_5 * V_6 = F_40 ( F_39 ( V_43 ) ) ;
F_8 ( L_30 ,
V_6 -> V_7 . V_8 , V_6 -> V_7 . V_6 , V_72 ,
V_13 -> V_20 , V_13 -> V_55 ,
( long long ) V_13 -> V_45 , ( long long ) V_13 -> V_46 ) ;
if ( F_51 ( & V_6 -> V_69 ) && V_13 -> V_20 != V_68 )
return - V_73 ;
if ( F_52 ( V_72 ) )
return F_48 ( V_43 , V_13 ) ;
if ( V_13 -> V_20 == V_68 )
return F_47 ( V_43 , V_13 ) ;
return F_38 ( V_43 , V_13 ) ;
}
int F_53 ( struct V_43 * V_43 , int V_72 , struct V_12 * V_13 )
{
struct V_5 * V_6 = F_40 ( F_39 ( V_43 ) ) ;
F_8 ( L_31 ,
V_6 -> V_7 . V_8 , V_6 -> V_7 . V_6 , V_72 ,
V_13 -> V_20 , V_13 -> V_55 ) ;
if ( ! ( V_13 -> V_55 & V_74 ) )
return - V_73 ;
V_13 -> V_75 = ( V_76 ) V_43 ;
V_13 -> V_45 = 0 ;
V_13 -> V_46 = V_47 ;
if ( V_13 -> V_20 == V_68 )
return F_47 ( V_43 , V_13 ) ;
return F_38 ( V_43 , V_13 ) ;
}
static void F_54 ( struct V_12 * V_77 , struct V_12 * V_13 )
{
F_8 ( L_28 ) ;
F_55 ( & V_77 -> V_16 . V_17 . V_18 , & V_13 -> V_16 . V_17 . V_18 ) ;
}
static void F_56 ( struct V_12 * V_13 )
{
F_8 ( L_28 ) ;
F_34 ( & V_13 -> V_16 . V_17 . V_18 ) ;
}
