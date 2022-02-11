struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = NULL ;
struct V_1 * V_6 = NULL ;
struct V_7 * V_8 = NULL ;
char V_9 ;
int V_10 , V_11 ;
F_2 ( L_1 ,
V_3 -> V_12 , V_3 -> V_12 , V_3 -> V_13 , V_3 -> V_14 ) ;
V_5 = F_3 ( V_3 -> V_15 , V_3 -> V_16 ,
V_3 -> V_13 , V_3 -> V_12 ) ;
if ( F_4 ( V_5 ) ) {
V_10 = F_5 ( V_5 ) ;
V_5 = NULL ;
goto error;
}
V_10 = - V_17 ;
if ( V_3 -> V_18 && ! ( V_5 -> V_19 . V_20 & ( 1 << V_3 -> type ) ) )
goto error;
V_9 = 0 ;
for ( V_11 = 0 ; V_11 < V_5 -> V_19 . V_21 ; V_11 ++ )
V_9 |= V_5 -> V_19 . V_9 [ V_11 ] ;
if ( V_3 -> V_18 ) {
if ( ! ( V_9 & ( 1 << V_3 -> type ) ) )
goto error;
} else if ( V_9 & V_22 ) {
V_3 -> type = V_23 ;
} else if ( V_9 & V_24 ) {
V_3 -> type = V_25 ;
} else {
goto error;
}
F_6 ( & V_3 -> V_15 -> V_26 ) ;
if ( V_5 -> V_27 [ V_3 -> type ] ) {
V_6 = V_5 -> V_27 [ V_3 -> type ] ;
F_7 ( V_6 ) ;
goto V_28;
}
F_8 ( L_2 ) ;
V_10 = - V_29 ;
V_6 = F_9 ( sizeof( struct V_1 ) , V_30 ) ;
if ( ! V_6 )
goto V_31;
F_10 ( & V_6 -> V_32 , 1 ) ;
V_6 -> type = V_3 -> type ;
V_6 -> V_33 = V_3 -> V_18 ;
V_6 -> V_15 = V_3 -> V_15 ;
V_6 -> V_34 = V_5 -> V_19 . V_34 [ V_3 -> type ] ;
F_11 ( & V_6 -> V_35 ) ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
if ( V_5 -> V_19 . V_9 [ V_11 ] & ( 1 << V_6 -> type ) ) {
V_8 = F_12 (
V_6 -> V_15 , & V_5 -> V_19 . V_36 [ V_11 ] ) ;
if ( F_4 ( V_8 ) ) {
V_10 = F_5 ( V_8 ) ;
goto V_37;
}
V_6 -> V_36 [ V_6 -> V_21 ] = V_8 ;
V_6 -> V_21 ++ ;
}
}
#ifdef F_13
V_6 -> V_38 = F_14 ( V_5 -> V_38 ,
& V_39 ,
V_6 , true ) ;
#endif
F_15 ( V_5 ) ;
V_6 -> V_5 = V_5 ;
V_5 -> V_27 [ V_6 -> type ] = V_6 ;
V_28:
F_8 ( L_3 ,
V_40 [ V_6 -> type ] , V_6 -> V_34 ) ;
F_16 ( & V_3 -> V_15 -> V_26 ) ;
F_17 ( V_5 ) ;
F_18 ( L_4 , V_6 ) ;
return V_6 ;
V_31:
F_16 ( & V_3 -> V_15 -> V_26 ) ;
error:
F_17 ( V_5 ) ;
F_18 ( L_5 , V_10 ) ;
return F_19 ( V_10 ) ;
V_37:
F_16 ( & V_3 -> V_15 -> V_26 ) ;
for ( V_11 = V_6 -> V_21 - 1 ; V_11 >= 0 ; V_11 -- )
F_20 ( V_6 -> V_36 [ V_11 ] ) ;
F_21 ( V_6 ) ;
goto error;
}
void F_22 ( struct V_1 * V_6 )
{
struct V_4 * V_5 ;
int V_11 ;
if ( ! V_6 )
return;
F_2 ( L_6 , V_6 ) ;
F_23 ( F_24 ( & V_6 -> V_32 ) , > , 0 ) ;
V_5 = V_6 -> V_5 ;
F_6 ( & V_5 -> V_15 -> V_26 ) ;
if ( F_25 ( ! F_26 ( & V_6 -> V_32 ) ) ) {
F_16 ( & V_5 -> V_15 -> V_26 ) ;
F_18 ( L_7 ) ;
return;
}
V_5 -> V_27 [ V_6 -> type ] = NULL ;
F_16 ( & V_5 -> V_15 -> V_26 ) ;
#ifdef F_13
F_27 ( V_6 -> V_38 , 0 ) ;
#endif
F_17 ( V_5 ) ;
for ( V_11 = V_6 -> V_21 - 1 ; V_11 >= 0 ; V_11 -- )
F_20 ( V_6 -> V_36 [ V_11 ] ) ;
F_21 ( V_6 ) ;
F_18 ( L_8 ) ;
}
struct V_7 * F_28 ( struct V_41 * V_42 )
{
struct V_1 * V_6 = V_42 -> V_6 ;
struct V_7 * V_8 ;
int V_10 , V_43 , V_11 ;
F_2 ( L_9 , V_6 -> V_5 -> V_19 . V_44 ) ;
if ( V_42 -> V_8 && V_42 -> V_8 -> V_45 == 0 ) {
F_29 ( V_42 -> V_8 ) ;
F_18 ( L_10 , V_42 -> V_8 ) ;
return V_42 -> V_8 ;
}
F_30 ( & V_6 -> V_35 ) ;
if ( V_6 -> V_21 == 0 ) {
V_10 = V_6 -> V_46 ? - V_17 : - V_47 ;
F_31 ( & V_6 -> V_35 ) ;
F_18 ( L_11 , V_10 ) ;
return F_19 ( V_10 ) ;
}
V_10 = 0 ;
for ( V_11 = 0 ; V_11 < V_6 -> V_21 ; V_11 ++ ) {
V_8 = V_6 -> V_36 [ V_11 ] ;
V_43 = V_8 -> V_45 ;
F_8 ( L_12 , V_11 , V_43 ) ;
switch ( V_43 ) {
case 0 :
F_29 ( V_8 ) ;
F_31 ( & V_6 -> V_35 ) ;
F_18 ( L_13 ,
V_8 , F_32 ( V_8 -> V_48 . V_49 ) ) ;
return V_8 ;
case - V_50 :
if ( V_10 == 0 )
V_10 = V_43 ;
break;
case - V_51 :
if ( V_10 == 0 ||
V_10 == - V_50 )
V_10 = V_43 ;
break;
case - V_52 :
if ( V_10 == 0 ||
V_10 == - V_50 ||
V_10 == - V_51 )
V_10 = V_43 ;
break;
default:
case - V_53 :
if ( V_10 == 0 ||
V_10 == - V_50 ||
V_10 == - V_51 ||
V_10 == - V_52 )
V_10 = V_43 ;
break;
}
}
F_31 ( & V_6 -> V_35 ) ;
F_18 ( L_5 , V_10 ) ;
return F_19 ( V_10 ) ;
}
int F_33 ( struct V_41 * V_42 ,
struct V_7 * V_8 ,
int V_54 )
{
struct V_1 * V_6 = V_42 -> V_6 ;
unsigned V_11 ;
F_2 ( L_14 ,
V_6 -> V_5 -> V_19 . V_44 , F_32 ( V_8 -> V_48 . V_49 ) ,
V_54 ) ;
switch ( V_54 ) {
case 0 :
V_8 -> V_55 = V_56 ;
V_8 -> V_45 = 0 ;
F_18 ( L_7 ) ;
return 1 ;
case - V_17 :
V_8 -> V_55 = V_56 ;
F_6 ( & V_6 -> V_35 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_21 ; V_11 ++ )
if ( V_6 -> V_36 [ V_11 ] == V_8 )
goto V_57;
goto V_58;
V_57:
V_6 -> V_21 -- ;
memmove ( & V_6 -> V_36 [ V_11 ] ,
& V_6 -> V_36 [ V_11 + 1 ] ,
sizeof( V_6 -> V_36 [ V_11 ] ) *
( V_6 -> V_21 - V_11 ) ) ;
V_6 -> V_36 [ V_6 -> V_21 ] = NULL ;
F_20 ( V_8 ) ;
V_6 -> V_46 ++ ;
if ( V_6 -> V_21 > 0 )
goto V_58;
F_16 ( & V_6 -> V_35 ) ;
F_20 ( V_8 ) ;
F_18 ( L_15 ) ;
return 1 ;
case - V_50 :
case - V_51 :
case - V_52 :
case - V_59 :
case - V_60 :
case - V_53 :
F_34 ( & V_8 -> V_61 ) ;
if ( ! V_8 -> V_45 ) {
V_8 -> V_62 = V_56 + V_63 * 10 ;
V_8 -> V_45 = V_54 ;
F_35 ( L_16 , V_54 ) ;
}
F_36 ( & V_8 -> V_61 ) ;
goto V_64;
default:
V_8 -> V_55 = V_56 ;
case - V_29 :
case - V_65 :
F_20 ( V_8 ) ;
F_18 ( L_17 ) ;
return 1 ;
}
V_58:
F_16 ( & V_6 -> V_35 ) ;
V_64:
F_20 ( V_8 ) ;
F_18 ( L_18 ) ;
return 0 ;
}
