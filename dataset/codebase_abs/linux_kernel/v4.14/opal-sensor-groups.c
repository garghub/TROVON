static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 , struct V_7 , V_4 ) ;
struct V_9 V_10 ;
T_3 V_11 ;
int V_12 , V_13 ;
V_12 = F_3 ( V_5 , 0 , & V_11 ) ;
if ( V_12 )
return V_12 ;
if ( V_11 != 1 )
return - V_14 ;
V_13 = F_4 () ;
if ( V_13 < 0 ) {
F_5 ( L_1 ) ;
return V_13 ;
}
V_12 = F_6 ( & V_15 ) ;
if ( V_12 )
goto V_16;
V_12 = F_7 ( V_8 -> V_17 , V_13 ) ;
switch ( V_12 ) {
case V_18 :
V_12 = F_8 ( V_13 , & V_10 ) ;
if ( V_12 ) {
F_5 ( L_2 ) ;
V_12 = - V_19 ;
goto V_20;
}
V_12 = F_9 ( F_10 ( V_10 ) ) ;
if ( ! V_12 )
V_12 = V_6 ;
break;
case V_21 :
V_12 = V_6 ;
break;
default:
V_12 = F_9 ( V_12 ) ;
}
V_20:
F_11 ( & V_15 ) ;
V_16:
F_12 ( V_13 ) ;
return V_12 ;
}
static void F_13 ( int V_17 , struct V_7 * V_4 , int V_22 )
{
V_4 -> V_17 = V_17 ;
F_14 ( & V_4 -> V_4 . V_4 ) ;
V_4 -> V_4 . V_4 . V_23 = V_24 [ V_22 ] . V_25 ;
V_4 -> V_4 . V_4 . V_26 = 0220 ;
V_4 -> V_4 . V_27 = V_24 [ V_22 ] . V_27 ;
}
static int F_15 ( const T_4 * V_28 , int V_29 , struct V_30 * V_31 ,
T_3 V_17 )
{
int V_32 , V_33 ;
int V_6 = 0 ;
for ( V_32 = 0 ; V_32 < V_29 ; V_32 ++ )
for ( V_33 = 0 ; V_33 < F_16 ( V_24 ) ; V_33 ++ )
if ( F_17 ( V_28 [ V_32 ] ) == V_24 [ V_33 ] . V_34 ) {
F_13 ( V_17 , & V_31 -> V_35 [ V_6 ] , V_33 ) ;
V_31 -> V_31 . V_36 [ V_6 ] =
& V_31 -> V_35 [ V_6 ] . V_4 . V_4 ;
V_6 ++ ;
}
return F_18 ( V_37 , & V_31 -> V_31 ) ;
}
static int F_19 ( const T_4 * V_28 , int V_29 )
{
int V_32 , V_33 ;
int V_38 = 0 ;
for ( V_32 = 0 ; V_32 < V_29 ; V_32 ++ )
for ( V_33 = 0 ; V_33 < F_16 ( V_24 ) ; V_33 ++ )
if ( F_17 ( V_28 [ V_32 ] ) == V_24 [ V_33 ] . V_34 )
V_38 ++ ;
return V_38 ;
}
void T_5 F_20 ( void )
{
struct V_39 * V_31 , * V_40 ;
int V_32 = 0 ;
V_31 = F_21 ( NULL , NULL , L_3 ) ;
if ( ! V_31 ) {
F_5 ( L_4 ) ;
return;
}
V_41 = F_22 ( F_23 ( V_31 ) , sizeof( * V_41 ) , V_42 ) ;
if ( ! V_41 )
return;
V_37 = F_24 ( L_5 , V_43 ) ;
if ( ! V_37 ) {
F_25 ( L_6 ) ;
goto V_44;
}
F_26 (sg, node) {
const T_4 * V_28 ;
T_3 V_45 , V_29 , V_38 , V_46 ;
V_28 = F_27 ( V_40 , L_7 , & V_29 ) ;
if ( ! V_28 )
continue;
V_38 = F_19 ( V_28 , V_29 ) ;
if ( ! V_38 )
continue;
V_41 [ V_32 ] . V_35 = F_22 ( V_38 , sizeof( struct V_7 ) ,
V_42 ) ;
if ( ! V_41 [ V_32 ] . V_35 )
goto V_47;
V_41 [ V_32 ] . V_31 . V_36 = F_22 ( V_38 + 1 ,
sizeof( struct V_48 * ) ,
V_42 ) ;
if ( ! V_41 [ V_32 ] . V_31 . V_36 ) {
F_28 ( V_41 [ V_32 ] . V_35 ) ;
goto V_47;
}
if ( F_29 ( V_40 , L_8 , & V_45 ) ) {
F_25 ( L_9 ) ;
goto V_47;
}
if ( ! F_29 ( V_40 , L_10 , & V_46 ) )
sprintf ( V_41 [ V_32 ] . V_23 , L_11 , V_40 -> V_23 , V_46 ) ;
else
sprintf ( V_41 [ V_32 ] . V_23 , L_12 , V_40 -> V_23 ) ;
V_41 [ V_32 ] . V_31 . V_23 = V_41 [ V_32 ] . V_23 ;
if ( F_15 ( V_28 , V_29 , & V_41 [ V_32 ] , V_45 ) ) {
F_25 ( L_13 ,
V_41 [ V_32 ] . V_31 . V_23 ) ;
goto V_47;
}
V_32 ++ ;
}
return;
V_47:
while ( -- V_32 >= 0 ) {
F_28 ( V_41 [ V_32 ] . V_35 ) ;
F_28 ( V_41 [ V_32 ] . V_31 . V_36 ) ;
}
F_30 ( V_37 ) ;
V_44:
F_28 ( V_41 ) ;
}
