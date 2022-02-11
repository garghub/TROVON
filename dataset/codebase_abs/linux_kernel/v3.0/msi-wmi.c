static int F_1 ( int V_1 , int * V_2 )
{
T_1 V_3 ;
union V_4 * V_5 ;
struct V_6 V_7 = { V_8 , NULL } ;
V_3 = F_2 ( V_9 , V_1 , & V_7 ) ;
V_5 = V_7 . V_10 ;
if ( ! V_5 || V_5 -> type != V_11 ) {
if ( V_5 ) {
F_3 ( L_1
L_2 , V_5 -> type ,
V_5 -> type == V_12 ?
V_5 -> V_13 . V_14 : 0 ) ;
}
F_4 ( V_5 ) ;
return - V_15 ;
}
* V_2 = V_5 -> integer . V_16 ;
F_4 ( V_5 ) ;
return 0 ;
}
static int F_5 ( int V_1 , int V_16 )
{
T_1 V_3 ;
struct V_6 V_17 = { sizeof( int ) , & V_16 } ;
F_6 ( L_3 ,
V_1 , V_16 ) ;
V_3 = F_7 ( V_9 , V_1 , & V_17 ) ;
return F_8 ( V_3 ) ? 0 : 1 ;
}
static int F_9 ( struct V_18 * V_19 )
{
int V_20 , V_21 , V_2 ;
V_21 = F_1 ( 1 , & V_2 ) ;
if ( V_21 ) {
F_3 ( L_4 , V_21 ) ;
return - V_15 ;
}
F_6 ( L_5 , V_2 ) ;
for ( V_20 = 0 ; V_20 < F_10 ( V_22 ) ; V_20 ++ ) {
if ( V_22 [ V_20 ] == V_2 ) {
F_6 ( L_6 ,
V_22 [ V_20 ] , V_20 ) ;
break;
}
}
if ( V_20 == F_10 ( V_22 ) ) {
F_3 ( L_7 , V_2 ) ;
return - V_15 ;
}
return V_20 ;
}
static int F_11 ( struct V_18 * V_19 )
{
int V_23 = V_19 -> V_24 . V_25 ;
if ( V_23 >= F_10 ( V_22 ) || V_23 < 0 )
return - V_15 ;
return F_5 ( 0 , V_22 [ V_23 ] ) ;
}
static void F_12 ( T_2 V_16 , void * V_26 )
{
struct V_6 V_27 = { V_8 , NULL } ;
static struct V_28 * V_29 ;
union V_4 * V_5 ;
T_3 V_30 ;
T_1 V_3 ;
V_3 = F_13 ( V_16 , & V_27 ) ;
if ( V_3 != V_31 ) {
F_14 ( L_8 , V_3 ) ;
return;
}
V_5 = (union V_4 * ) V_27 . V_10 ;
if ( V_5 && V_5 -> type == V_11 ) {
int V_32 = V_5 -> integer . V_16 ;
F_6 ( L_9 , V_32 ) ;
V_29 = F_15 ( V_33 ,
V_32 ) ;
if ( V_29 ) {
T_3 V_34 ;
V_30 = F_16 () ;
V_34 = F_17 ( V_30 , V_35 [ V_29 -> V_36 -
V_37 ] ) ;
if ( F_18 ( V_34 ) < 1000 * 50 ) {
F_6 ( L_10
L_11 ,
V_29 -> V_36 , F_18 ( V_34 ) ) ;
return;
}
V_35 [ V_29 -> V_36 - V_37 ] = V_30 ;
if ( V_29 -> type == V_38 &&
( ! F_19 () ||
( V_29 -> V_36 != V_39 &&
V_29 -> V_36 != V_40 ) ) ) {
F_6 ( L_12
L_13 ,
V_29 -> V_36 , V_29 -> V_41 ) ;
F_20 ( V_33 ,
V_29 , 1 , true ) ;
}
} else
F_14 ( L_14 , V_32 ) ;
} else
F_14 ( L_15 ) ;
F_4 ( V_27 . V_10 ) ;
}
static int T_4 F_21 ( void )
{
int V_21 ;
V_33 = F_22 () ;
if ( ! V_33 )
return - V_42 ;
V_33 -> V_43 = L_16 ;
V_33 -> V_44 = L_17 ;
V_33 -> V_45 . V_46 = V_47 ;
V_21 = F_23 ( V_33 , V_48 , NULL ) ;
if ( V_21 )
goto V_49;
V_21 = F_24 ( V_33 ) ;
if ( V_21 )
goto V_50;
memset ( V_35 , 0 , sizeof( V_35 ) ) ;
return 0 ;
V_50:
F_25 ( V_33 ) ;
V_49:
F_26 ( V_33 ) ;
return V_21 ;
}
static int T_4 F_27 ( void )
{
int V_21 ;
if ( ! F_28 ( V_51 ) ) {
F_3 ( L_18 ) ;
return - V_52 ;
}
V_21 = F_29 ( V_51 ,
F_12 , NULL ) ;
if ( F_30 ( V_21 ) )
return - V_15 ;
V_21 = F_21 () ;
if ( V_21 )
goto V_53;
if ( ! F_19 () ) {
struct V_54 V_24 ;
memset ( & V_24 , 0 , sizeof( struct V_54 ) ) ;
V_24 . type = V_55 ;
V_24 . V_56 = F_10 ( V_22 ) - 1 ;
V_57 = F_31 ( V_58 , NULL , NULL ,
& V_59 ,
& V_24 ) ;
if ( F_32 ( V_57 ) ) {
V_21 = F_33 ( V_57 ) ;
goto V_60;
}
V_21 = F_9 ( NULL ) ;
if ( V_21 < 0 )
goto V_61;
V_57 -> V_24 . V_25 = V_21 ;
}
F_6 ( L_19 ) ;
return 0 ;
V_61:
F_34 ( V_57 ) ;
V_60:
F_35 ( V_33 ) ;
V_53:
F_36 ( V_51 ) ;
return V_21 ;
}
static void T_5 F_37 ( void )
{
if ( F_28 ( V_51 ) ) {
F_36 ( V_51 ) ;
F_25 ( V_33 ) ;
F_35 ( V_33 ) ;
F_34 ( V_57 ) ;
}
}
