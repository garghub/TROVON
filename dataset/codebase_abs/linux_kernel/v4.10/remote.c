static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> type == V_3 ) {
unsigned char V_4 = V_2 -> V_5 ;
F_2 ( L_1 ,
V_2 -> V_6 . V_7 . V_8 , V_2 -> V_6 . V_7 . V_9 ,
( V_4 ) ? L_2 : L_3 ,
( V_4 & V_10 ) ? L_4 : L_3 ,
( V_4 & V_11 ) ? L_5 : L_3 ,
( V_4 & V_12 ) ? L_6 : L_3
) ;
} else {
F_2 ( L_7
L_8 ,
V_2 -> V_6 . V_13 . V_14 ,
V_2 -> V_6 . V_13 . V_14 ,
V_2 -> V_6 . V_13 . V_15 ,
V_2 -> V_6 . V_13 . V_16
) ;
}
}
static void F_3 ( struct V_17 * V_18 , struct V_1 * V_2 )
{
unsigned char V_4 = V_2 -> V_5 ;
F_4 ( V_18 , V_19 , V_2 -> V_6 . V_7 . V_8 ) ;
F_4 ( V_18 , V_20 , V_2 -> V_6 . V_7 . V_9 ) ;
F_5 ( V_18 , V_21 , V_4 & V_10 ) ;
F_5 ( V_18 , V_22 , V_4 & V_11 ) ;
F_5 ( V_18 , V_23 , V_4 & V_12 ) ;
F_6 ( V_18 ) ;
}
static void F_7 ( struct V_17 * V_18 ,
struct V_1 * V_2 )
{
unsigned int V_24 ;
unsigned short V_25 = V_2 -> V_6 . V_13 . V_14 ;
if ( V_25 & 0xff00 )
V_24 = V_26 [ V_25 & 0xff ] ;
else
V_24 = V_27 [ V_25 ] ;
F_5 ( V_18 , V_24 , V_2 -> V_6 . V_13 . V_16 ) ;
F_6 ( V_18 ) ;
}
void F_8 ( struct V_28 * V_29 )
{
unsigned long V_30 ;
unsigned long V_31 ;
struct V_1 V_2 ;
V_30 = F_9 ( V_29 ) ;
V_31 = F_10 ( V_29 ) ;
while ( V_30 != V_31 ) {
F_11 ( & V_2 , F_12 ( V_29 , V_30 ) ,
sizeof( struct V_1 ) ) ;
F_1 ( & V_2 ) ;
if ( V_2 . type == V_3 ) {
F_3 ( V_29 -> V_32 . V_33 , & V_2 ) ;
} else if ( V_2 . type == V_34 ) {
F_7 ( V_29 -> V_32 . V_35 , & V_2 ) ;
} else
break;
V_30 = F_13 ( V_29 , V_30 ) ;
V_31 = F_10 ( V_29 ) ;
}
}
int F_14 ( struct V_28 * V_29 )
{
struct V_17 * V_33 , * V_35 ;
struct V_36 * V_37 = F_15 ( V_29 -> V_18 ) ;
int error = - V_38 ;
int V_39 ;
V_29 -> V_32 . V_33 = V_33 = F_16 () ;
V_29 -> V_32 . V_35 = V_35 = F_16 () ;
if ( ! V_33 || ! V_35 )
goto V_40;
V_33 -> V_41 . V_42 = V_43 ;
V_33 -> V_41 . V_44 = V_37 -> V_44 ;
V_33 -> V_41 . V_45 = V_37 -> V_46 ;
V_33 -> V_41 . V_47 = 1 ;
V_33 -> V_18 . V_48 = V_29 -> V_18 ;
V_33 -> V_49 [ 0 ] = F_17 ( V_50 ) | F_17 ( V_51 ) ;
V_33 -> V_52 [ F_18 ( V_53 ) ] = F_17 ( V_21 ) |
F_17 ( V_23 ) | F_17 ( V_22 ) ;
F_19 ( V_54 , V_33 -> V_52 ) ;
V_33 -> V_55 = L_9 ;
F_20 ( V_33 , V_19 , 0 , V_56 , 0 , 0 ) ;
F_20 ( V_33 , V_20 , 0 , V_57 , 0 , 0 ) ;
V_35 -> V_41 . V_42 = V_43 ;
V_35 -> V_41 . V_44 = V_37 -> V_44 ;
V_35 -> V_41 . V_45 = V_37 -> V_46 ;
V_35 -> V_41 . V_47 = 2 ;
V_35 -> V_18 . V_48 = V_29 -> V_18 ;
V_35 -> V_49 [ 0 ] = F_17 ( V_50 ) ;
V_35 -> V_55 = L_10 ;
for ( V_39 = 0 ; V_39 < V_58 ; V_39 ++ ) {
if ( V_26 [ V_39 ] )
F_19 ( V_26 [ V_39 ] , V_35 -> V_52 ) ;
if ( V_27 [ V_39 ] )
F_19 ( V_27 [ V_39 ] , V_35 -> V_52 ) ;
}
error = F_21 ( V_33 ) ;
if ( error )
goto V_40;
error = F_21 ( V_35 ) ;
if ( error )
goto V_59;
F_22 ( V_29 ) ;
F_23 ( V_60 L_11 , V_29 -> V_61 ) ;
return 0 ;
V_59:
F_24 ( V_33 ) ;
V_33 = NULL ;
V_40:
F_25 ( V_33 ) ;
F_25 ( V_35 ) ;
return error ;
}
void F_26 ( struct V_28 * V_29 )
{
F_27 ( V_29 ) ;
F_24 ( V_29 -> V_32 . V_33 ) ;
F_24 ( V_29 -> V_32 . V_35 ) ;
}
