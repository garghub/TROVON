bool F_1 ( void )
{
struct V_1 V_2 ;
if ( V_3 )
return false ;
return F_2 ( F_3 ( V_4 , 0 , & V_2 ) ) ;
}
void T_1 F_4 ( void )
{
const struct V_5 * V_6 ;
const struct V_7 * V_8 ;
struct V_9 V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
T_2 V_17 = 0 ;
T_3 V_18 ;
int V_19 ;
V_18 = F_5 ( V_4 , 0 ,
(struct V_1 * * ) & V_8 ) ;
if ( F_6 ( V_18 ) ) {
return;
}
if ( ! ( V_8 -> V_20 & V_21 ) )
return;
if ( V_8 -> V_22 != 0xff || V_8 -> V_23 != 0xff ||
V_8 -> V_24 != 0xff || V_8 -> V_25 != 0xff )
return;
F_7 ( & V_10 ) ;
V_6 = (struct V_5 * ) ( V_8 + 1 ) ;
for ( V_19 = 0 ; V_19 < V_8 -> V_6 ; V_19 ++ ) {
const struct V_26 * V_27 ;
struct V_11 * V_12 ;
struct V_15 V_28 ;
bool V_29 ;
V_27 = & V_6 [ V_19 ] . V_30 ;
V_28 . V_31 = V_27 -> V_32 ;
if ( V_27 -> V_33 == V_34 ) {
V_28 . V_20 = V_35 ;
V_28 . V_36 = V_28 . V_31 + F_8 ( V_27 -> V_37 , 4 ) ;
} else if ( V_27 -> V_33 == V_38 ) {
V_28 . V_20 = V_39 ;
V_28 . V_36 = V_28 . V_31 + V_27 -> V_37 ;
} else {
F_9 ( L_1 ,
V_27 -> V_33 ) ;
goto V_40;
}
V_29 = false ;
F_10 (rentry, &resource_list) {
if ( F_11 ( V_12 -> V_28 , & V_28 ) ) {
V_29 = true ;
break;
}
}
if ( ! V_29 ) {
V_12 = F_12 ( NULL , 0 ) ;
if ( ! V_12 )
goto V_40;
* V_12 -> V_28 = V_28 ;
F_13 ( V_12 , & V_10 ) ;
V_17 ++ ;
}
}
V_16 = F_14 ( V_17 , sizeof( * V_16 ) , V_41 ) ;
if ( ! V_16 )
goto V_40;
V_19 = 0 ;
F_10 (rentry, &resource_list)
V_16 [ V_19 ++ ] = * V_12 -> V_28 ;
V_14 = F_15 ( L_2 , V_42 ,
V_16 , V_17 ) ;
if ( F_16 ( V_14 ) )
F_17 ( L_3 , F_18 ( V_14 ) ) ;
F_19 ( V_16 ) ;
V_40:
F_20 ( & V_10 ) ;
}
