static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! V_2 || ! V_2 -> V_4 )
return;
V_3 = F_2 ( V_2 -> V_4 ) ;
if ( V_3 == 0 ) {
F_3 ( L_1 ) ;
return;
}
if ( V_3 > F_4 ( V_2 -> V_4 ) ) {
F_3 ( L_2 ) ;
return;
}
F_3 ( L_3 ) ;
F_5 ( & V_2 -> V_5 ) ;
}
static int F_6 ( struct V_6 * V_6 , char T_1 * V_7 ,
T_2 V_8 , T_3 * V_9 )
{
int V_10 , V_11 ;
struct V_1 * V_2 ;
struct V_12 * V_13 ;
F_3 ( L_4 , V_8 ) ;
if ( V_8 > V_14 )
return - V_15 ;
V_2 = V_6 -> V_16 ;
if ( ! V_2 || ! V_2 -> V_4 )
return - V_15 ;
V_13 = V_2 -> V_4 ;
V_17:
V_10 = F_7 ( V_2 -> V_5 ,
( F_2 ( V_13 ) > 0 &&
F_4 ( V_13 ) >=
F_2 ( V_13 ) ) ) ;
if ( V_10 < 0 ) {
if ( V_10 != - V_18 )
F_8 ( L_5 , V_10 ) ;
return V_10 ;
}
F_9 ( & V_2 -> V_19 ) ;
V_11 = F_2 ( V_2 -> V_4 ) ;
if ( V_11 == 0 ||
V_11 < F_4 ( V_2 -> V_4 ) ) {
F_10 ( & V_2 -> V_19 ) ;
F_3 ( L_6 ) ;
goto V_17;
}
if ( V_11 > V_8 ) {
F_10 ( & V_2 -> V_19 ) ;
F_11 ( L_7 , V_11 , V_8 ) ;
return - V_15 ;
}
V_10 = F_12 ( V_2 -> V_4 , V_2 -> V_20 , V_11 ) ;
if ( V_10 != V_11 ) {
F_10 ( & V_2 -> V_19 ) ;
F_8 ( L_8 , V_11 , V_10 ) ;
return - V_21 ;
}
F_13 ( L_9 , V_11 , V_2 -> V_20 ) ;
V_10 = F_14 ( V_7 , V_2 -> V_20 , V_11 ) ;
F_10 ( & V_2 -> V_19 ) ;
if ( V_10 ) {
F_8 ( L_10 , V_10 ) ;
return - V_22 ;
}
F_3 ( L_11 , V_11 ) ;
F_1 ( V_2 ) ;
return V_11 ;
}
static int F_15 ( struct V_6 * V_6 , const char T_1 * V_7 ,
T_2 V_8 , T_3 * V_9 )
{
int V_10 ;
struct V_1 * V_2 ;
if ( V_8 > V_14 )
return - V_15 ;
F_3 ( L_12 , V_8 ) ;
V_2 = V_6 -> V_16 ;
if ( ! V_2 || ! V_2 -> V_4 )
return - V_15 ;
F_9 ( & V_2 -> V_23 ) ;
if ( F_16 ( V_2 -> V_4 ) < V_8 ) {
F_10 ( & V_2 -> V_23 ) ;
F_3 ( L_13 ) ;
return - V_24 ;
}
F_13 ( L_14 , V_8 , V_7 ) ;
V_10 = F_17 ( V_2 -> V_25 , V_7 , V_8 ) ;
if ( V_10 ) {
F_10 ( & V_2 -> V_23 ) ;
F_8 ( L_15 , V_10 ) ;
return - V_22 ;
}
V_10 = F_18 ( V_2 -> V_4 , V_2 -> V_25 , V_8 ) ;
if ( V_10 != V_8 ) {
F_10 ( & V_2 -> V_23 ) ;
F_8 ( L_16 , V_8 , V_10 ) ;
return - V_21 ;
}
F_10 ( & V_2 -> V_23 ) ;
F_3 ( L_17 , V_8 ) ;
return V_8 ;
}
static unsigned int F_19 ( struct V_6 * V_6 , T_4 * V_26 )
{
struct V_1 * V_2 ;
unsigned int V_27 = 0 ;
V_2 = V_6 -> V_16 ;
if ( ! V_2 )
return V_28 ;
F_3 ( L_18 ) ;
F_20 ( V_6 , & V_2 -> V_5 , V_26 ) ;
if ( F_4 ( V_2 -> V_4 ) )
V_27 |= V_29 | V_30 ;
F_3 ( L_19 ) ;
return V_27 ;
}
static void F_21 ( void * V_31 , unsigned V_32 )
{
struct V_1 * V_2 = V_31 ;
if ( V_2 -> V_4 == 0 )
return;
switch ( V_32 ) {
case V_33 :
F_3 ( L_20 ) ;
F_1 ( V_2 ) ;
break;
case V_34 :
F_3 ( L_21 ) ;
V_2 -> V_35 = 1 ;
F_5 ( & V_2 -> V_36 ) ;
break;
case V_37 :
V_2 -> V_35 = 0 ;
F_11 ( L_22 ) ;
break;
default:
F_8 ( L_23 , V_32 ) ;
break;
}
}
static int F_22 ( struct V_38 * V_38 , struct V_6 * V_6 )
{
int V_10 = 0 ;
struct V_1 * V_2 ;
V_2 = F_23 ( V_38 -> V_39 , struct V_1 , V_40 ) ;
if ( ! V_2 )
return - V_15 ;
V_6 -> V_16 = V_2 ;
F_9 ( & V_2 -> V_41 ) ;
if ( V_2 -> V_42 == 0 ) {
V_10 = F_24 ( V_43 [ V_2 -> V_44 ] ,
& V_2 -> V_4 , V_2 ,
F_21 ) ;
if ( V_10 < 0 ) {
F_8 ( L_24 ,
V_43 [ V_2 -> V_44 ] , V_10 ) ;
goto V_45;
}
V_10 = F_25 (
V_2 -> V_36 ,
V_2 -> V_35 ,
F_26 ( 2 * V_46 ) ) ;
if ( V_10 == 0 )
V_10 = - V_47 ;
if ( V_10 < 0 ) {
F_8 ( L_5 , V_10 ) ;
F_27 ( V_2 -> V_4 ) ;
V_2 -> V_4 = 0 ;
} else {
V_2 -> V_42 ++ ;
V_10 = 0 ;
}
}
V_45:
F_10 ( & V_2 -> V_41 ) ;
return V_10 ;
}
static int F_28 ( struct V_38 * V_38 , struct V_6 * V_6 )
{
int V_10 = 0 ;
struct V_1 * V_2 = V_6 -> V_16 ;
if ( ! V_2 )
return - V_15 ;
F_9 ( & V_2 -> V_41 ) ;
if ( -- V_2 -> V_42 == 0 ) {
V_10 = F_27 ( V_2 -> V_4 ) ;
V_2 -> V_4 = 0 ;
}
F_10 ( & V_2 -> V_41 ) ;
return V_10 ;
}
static int T_5 F_29 ( void )
{
int V_44 ;
int V_10 ;
V_10 = F_30 ( & V_48 , 0 ,
V_49 , V_50 ) ;
if ( V_10 ) {
F_8 ( L_25 , V_10 ) ;
return V_10 ;
}
V_51 = F_31 ( V_52 , V_50 ) ;
if ( F_32 ( V_51 ) ) {
V_10 = F_33 ( V_51 ) ;
F_8 ( L_26 , V_10 ) ;
goto V_53;
}
for ( V_44 = 0 ; V_44 < V_49 ; ++ V_44 ) {
V_2 [ V_44 ] = F_34 ( sizeof( struct V_1 ) ,
V_54 ) ;
if ( ! V_2 [ V_44 ] ) {
F_8 ( L_27 ) ;
goto V_55;
}
V_2 [ V_44 ] -> V_44 = V_44 ;
F_35 ( & V_2 [ V_44 ] -> V_5 ) ;
V_2 [ V_44 ] -> V_35 = 0 ;
F_35 ( & V_2 [ V_44 ] -> V_36 ) ;
F_36 ( & V_2 [ V_44 ] -> V_41 ) ;
F_36 ( & V_2 [ V_44 ] -> V_19 ) ;
F_36 ( & V_2 [ V_44 ] -> V_23 ) ;
F_37 ( & V_2 [ V_44 ] -> V_40 , & V_56 ) ;
V_2 [ V_44 ] -> V_40 . V_57 = V_52 ;
V_10 = F_38 ( & V_2 [ V_44 ] -> V_40 ,
( V_48 + V_44 ) , 1 ) ;
if ( V_10 ) {
F_8 ( L_28 , V_10 ) ;
F_39 ( V_2 [ V_44 ] ) ;
goto V_55;
}
V_2 [ V_44 ] -> V_58 =
F_40 ( V_51 , NULL ,
( V_48 + V_44 ) , NULL ,
V_59 [ V_44 ] ) ;
if ( F_32 ( V_2 [ V_44 ] -> V_58 ) ) {
V_10 = F_33 ( V_2 [ V_44 ] -> V_58 ) ;
F_8 ( L_29 , V_10 ) ;
F_41 ( & V_2 [ V_44 ] -> V_40 ) ;
F_39 ( V_2 [ V_44 ] ) ;
goto V_55;
}
}
F_11 ( L_30 ) ;
return 0 ;
V_55:
if ( V_44 > 0 ) {
while ( -- V_44 >= 0 ) {
F_42 ( & V_2 [ V_44 ] -> V_41 ) ;
F_42 ( & V_2 [ V_44 ] -> V_19 ) ;
F_42 ( & V_2 [ V_44 ] -> V_23 ) ;
F_41 ( & V_2 [ V_44 ] -> V_40 ) ;
F_39 ( V_2 [ V_44 ] ) ;
F_43 ( V_51 ,
F_44 ( F_45 ( V_48 ) , V_44 ) ) ;
}
}
F_46 ( V_51 ) ;
V_53:
F_47 ( F_45 ( V_48 ) , V_49 ) ;
return V_10 ;
}
static void T_6 F_48 ( void )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_49 ; ++ V_44 ) {
F_42 ( & V_2 [ V_44 ] -> V_41 ) ;
F_42 ( & V_2 [ V_44 ] -> V_19 ) ;
F_42 ( & V_2 [ V_44 ] -> V_23 ) ;
F_41 ( & V_2 [ V_44 ] -> V_40 ) ;
F_39 ( V_2 [ V_44 ] ) ;
F_43 ( V_51 ,
F_44 ( F_45 ( V_48 ) , V_44 ) ) ;
}
F_46 ( V_51 ) ;
F_47 ( F_45 ( V_48 ) , V_49 ) ;
}
