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
V_6 -> V_35 . V_36 = V_37 * 1024 / V_38 ;
V_10 = F_11 ( & V_6 -> V_35 , L_3 ) ;
if ( V_10 )
goto V_39;
F_12 ( & V_6 -> V_40 ) ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
if ( V_5 -> V_19 . V_9 [ V_11 ] & ( 1 << V_6 -> type ) ) {
V_8 = F_13 (
V_6 -> V_15 , & V_5 -> V_19 . V_41 [ V_11 ] ) ;
if ( F_4 ( V_8 ) ) {
V_10 = F_5 ( V_8 ) ;
goto V_42;
}
V_6 -> V_41 [ V_6 -> V_21 ] = V_8 ;
V_6 -> V_21 ++ ;
}
}
#ifdef F_14
V_6 -> V_43 = F_15 ( V_5 -> V_43 ,
& V_44 ,
V_6 , true ) ;
#endif
F_16 ( V_5 ) ;
V_6 -> V_5 = V_5 ;
V_5 -> V_27 [ V_6 -> type ] = V_6 ;
V_28:
F_8 ( L_4 ,
V_45 [ V_6 -> type ] , V_6 -> V_34 ) ;
F_17 ( & V_3 -> V_15 -> V_26 ) ;
F_18 ( V_5 ) ;
F_19 ( L_5 , V_6 ) ;
return V_6 ;
V_31:
F_17 ( & V_3 -> V_15 -> V_26 ) ;
error:
F_18 ( V_5 ) ;
F_19 ( L_6 , V_10 ) ;
return F_20 ( V_10 ) ;
V_42:
F_21 ( & V_6 -> V_35 ) ;
V_39:
F_17 ( & V_3 -> V_15 -> V_26 ) ;
for ( V_11 = V_6 -> V_21 - 1 ; V_11 >= 0 ; V_11 -- )
F_22 ( V_6 -> V_41 [ V_11 ] ) ;
F_23 ( V_6 ) ;
goto error;
}
void F_24 ( struct V_1 * V_6 )
{
struct V_4 * V_5 ;
int V_11 ;
if ( ! V_6 )
return;
F_2 ( L_7 , V_6 ) ;
F_25 ( F_26 ( & V_6 -> V_32 ) , > , 0 ) ;
V_5 = V_6 -> V_5 ;
F_6 ( & V_5 -> V_15 -> V_26 ) ;
if ( F_27 ( ! F_28 ( & V_6 -> V_32 ) ) ) {
F_17 ( & V_5 -> V_15 -> V_26 ) ;
F_19 ( L_8 ) ;
return;
}
V_5 -> V_27 [ V_6 -> type ] = NULL ;
F_17 ( & V_5 -> V_15 -> V_26 ) ;
#ifdef F_14
F_29 ( V_6 -> V_43 , 0 ) ;
#endif
F_18 ( V_5 ) ;
for ( V_11 = V_6 -> V_21 - 1 ; V_11 >= 0 ; V_11 -- )
F_22 ( V_6 -> V_41 [ V_11 ] ) ;
F_21 ( & V_6 -> V_35 ) ;
F_23 ( V_6 ) ;
F_19 ( L_9 ) ;
}
struct V_7 * F_30 ( struct V_46 * V_47 )
{
struct V_1 * V_6 = V_47 -> V_6 ;
struct V_7 * V_8 ;
int V_10 , V_48 , V_11 ;
F_2 ( L_10 , V_6 -> V_5 -> V_19 . V_49 ) ;
if ( V_47 -> V_8 && V_47 -> V_8 -> V_50 == 0 ) {
F_31 ( V_47 -> V_8 ) ;
F_19 ( L_11 , V_47 -> V_8 ) ;
return V_47 -> V_8 ;
}
F_32 ( & V_6 -> V_40 ) ;
if ( V_6 -> V_21 == 0 ) {
V_10 = V_6 -> V_51 ? - V_17 : - V_52 ;
F_33 ( & V_6 -> V_40 ) ;
F_19 ( L_12 , V_10 ) ;
return F_20 ( V_10 ) ;
}
V_10 = 0 ;
for ( V_11 = 0 ; V_11 < V_6 -> V_21 ; V_11 ++ ) {
V_8 = V_6 -> V_41 [ V_11 ] ;
V_48 = V_8 -> V_50 ;
F_8 ( L_13 , V_11 , V_48 ) ;
switch ( V_48 ) {
case 0 :
F_31 ( V_8 ) ;
F_33 ( & V_6 -> V_40 ) ;
F_19 ( L_14 ,
V_8 , F_34 ( V_8 -> V_53 . V_54 ) ) ;
return V_8 ;
case - V_55 :
if ( V_10 == 0 )
V_10 = V_48 ;
break;
case - V_56 :
if ( V_10 == 0 ||
V_10 == - V_55 )
V_10 = V_48 ;
break;
case - V_57 :
if ( V_10 == 0 ||
V_10 == - V_55 ||
V_10 == - V_56 )
V_10 = V_48 ;
break;
default:
case - V_58 :
if ( V_10 == 0 ||
V_10 == - V_55 ||
V_10 == - V_56 ||
V_10 == - V_57 )
V_10 = V_48 ;
break;
}
}
F_33 ( & V_6 -> V_40 ) ;
F_19 ( L_6 , V_10 ) ;
return F_20 ( V_10 ) ;
}
int F_35 ( struct V_46 * V_47 ,
struct V_7 * V_8 ,
int V_59 )
{
struct V_1 * V_6 = V_47 -> V_6 ;
unsigned V_11 ;
F_2 ( L_15 ,
V_6 -> V_5 -> V_19 . V_49 , F_34 ( V_8 -> V_53 . V_54 ) ,
V_59 ) ;
switch ( V_59 ) {
case 0 :
V_8 -> V_60 = V_61 ;
V_8 -> V_50 = 0 ;
F_19 ( L_8 ) ;
return 1 ;
case - V_17 :
V_8 -> V_60 = V_61 ;
F_6 ( & V_6 -> V_40 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_21 ; V_11 ++ )
if ( V_6 -> V_41 [ V_11 ] == V_8 )
goto V_62;
goto V_63;
V_62:
V_6 -> V_21 -- ;
memmove ( & V_6 -> V_41 [ V_11 ] ,
& V_6 -> V_41 [ V_11 + 1 ] ,
sizeof( V_6 -> V_41 [ V_11 ] ) *
( V_6 -> V_21 - V_11 ) ) ;
V_6 -> V_41 [ V_6 -> V_21 ] = NULL ;
F_22 ( V_8 ) ;
V_6 -> V_51 ++ ;
if ( V_6 -> V_21 > 0 )
goto V_63;
F_17 ( & V_6 -> V_40 ) ;
F_22 ( V_8 ) ;
F_19 ( L_16 ) ;
return 1 ;
case - V_55 :
case - V_56 :
case - V_57 :
case - V_64 :
case - V_65 :
case - V_58 :
F_36 ( & V_8 -> V_66 ) ;
if ( ! V_8 -> V_50 ) {
V_8 -> V_67 = V_61 + V_68 * 10 ;
V_8 -> V_50 = V_59 ;
F_37 ( L_17 , V_59 ) ;
}
F_38 ( & V_8 -> V_66 ) ;
goto V_69;
default:
V_8 -> V_60 = V_61 ;
case - V_29 :
case - V_70 :
F_22 ( V_8 ) ;
F_19 ( L_18 ) ;
return 1 ;
}
V_63:
F_17 ( & V_6 -> V_40 ) ;
V_69:
F_22 ( V_8 ) ;
F_19 ( L_19 ) ;
return 0 ;
}
