static int F_1 ( void * V_1 )
{
int V_2 ;
while ( ! F_2 () ) {
F_3 ( 10000 , 11000 ) ;
if ( ! V_3 ) {
V_2 = F_4 ( V_1 ) ;
if ( V_2 != 0 ) {
F_5 ( L_1 ) ;
V_3 = true ;
}
}
}
return 0 ;
}
static int F_6 ( struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
unsigned V_14 ;
int V_15 , V_2 = 0 , V_16 ;
struct V_17 * V_18 ;
struct V_19 * V_20 = NULL ;
const struct V_21 * V_22 ;
V_18 = F_7 ( sizeof( struct V_17 ) , V_23 ) ;
if ( ! V_18 )
return - V_24 ;
V_13 = F_8 ( V_5 ) ;
F_5 ( L_2 ) ;
F_5 ( L_3 ,
V_13 -> V_25 . V_26 ) ;
V_18 -> V_13 = V_13 ;
V_18 -> V_27 = 0 ;
V_18 -> V_28 = NULL ;
V_18 -> V_29 = F_9 ( 0 , V_23 ) ;
V_18 -> V_30 = F_9 ( 0 , V_23 ) ;
if ( ! V_18 -> V_29 || ! V_18 -> V_30 ) {
V_2 = - V_24 ;
goto V_31;
}
F_5 ( L_4 ) ;
V_14 = V_5 -> V_32 ;
F_5 ( L_5 , V_14 ) ;
V_9 = V_5 -> V_33 ;
F_5 ( L_6 ,
V_9 -> V_34 . V_35 ) ;
F_5 ( L_7 ,
V_9 -> V_34 . V_36 ) ;
F_5 ( L_8 ,
V_9 -> V_34 . V_37 ) ;
F_5 ( L_9 ,
V_9 -> V_34 . V_38 ) ;
F_5 ( L_10 ,
V_9 -> V_34 . V_39 ) ;
F_5 ( L_11 ) ;
F_5 ( L_12 ,
V_9 -> V_11 [ 0 ] . V_34 . V_40 ) ;
F_5 ( L_13 ,
V_9 -> V_11 [ 1 ] . V_34 . V_40 ) ;
F_5 ( L_14 ,
V_9 -> V_11 [ 2 ] . V_34 . V_40 ) ;
for ( V_15 = 0 ; V_15 < V_9 -> V_34 . V_35 ; V_15 ++ ) {
V_11 =
(struct V_10 * ) & V_9 ->
V_11 [ V_15 ] . V_34 ;
F_5 ( L_15 , V_15 ) ;
F_5 ( L_16 ,
V_11 -> V_41 , V_11 -> V_40 ) ;
if ( ( V_11 -> V_41 & V_42 )
&& ( ( V_11 -> V_40 & V_43 ) ==
V_44 ) ) {
V_18 -> V_45 =
V_11 -> V_41 ;
F_5 ( L_17 ,
V_11 -> V_41 ) ;
}
if ( ! ( V_11 -> V_41 & V_42 )
&& ( ( V_11 -> V_40 & V_43 ) ==
V_44 ) ) {
V_18 -> V_46 =
V_11 -> V_41 ;
F_5 ( L_18 ,
V_11 -> V_41 ) ;
}
}
F_5 ( L_19 , V_18 -> V_45 ,
V_18 -> V_46 ) ;
V_2 = F_10 ( & V_22 , L_20 , & V_13 -> V_13 ) ;
if ( V_2 < 0 ) {
F_11 ( L_21 ) ;
goto V_31;
}
V_16 = F_12 ( V_47 , V_22 -> V_16 , 4096 ) ;
V_48 = F_13 ( V_16 , V_23 ) ;
if ( ! V_48 ) {
F_14 ( V_22 ) ;
V_2 = - V_24 ;
goto V_31;
}
memcpy ( V_48 , V_22 -> V_49 , V_22 -> V_16 ) ;
V_50 = V_22 -> V_16 ;
F_14 ( V_22 ) ;
F_5 ( L_22 ) ;
V_2 = F_15 ( V_18 ) ;
if ( V_2 )
goto V_51;
V_20 = F_16 ( V_18 -> V_28 ) ;
F_5 ( L_23 , V_20 ) ;
V_2 = F_17 ( V_18 ) ;
if ( V_2 ) {
F_11 ( L_24 ) ;
goto V_51;
}
V_3 = false ;
V_18 -> V_52 =
F_18 ( F_1 , V_18 , L_25 ) ;
if ( F_19 ( V_18 -> V_52 ) ) {
V_2 = F_20 ( V_18 -> V_52 ) ;
goto V_51;
}
F_21 ( 500 ) ;
while ( ! V_20 -> V_53 ) {
if ( V_3 ) {
V_2 = - V_54 ;
goto V_55;
}
F_21 ( 100 ) ;
F_5 ( L_26 ) ;
}
F_5 ( L_27 ) ;
V_2 = F_22 ( V_18 , V_5 ) ;
if ( V_2 )
goto V_55;
V_18 -> V_56 = 1 ;
return 0 ;
V_55:
F_23 ( V_18 -> V_52 ) ;
V_51:
F_24 ( V_48 ) ;
V_31:
F_25 ( V_18 -> V_30 ) ;
F_25 ( V_18 -> V_29 ) ;
F_24 ( V_18 ) ;
return V_2 ;
}
static void F_26 ( struct V_4 * V_5 )
{
struct V_19 * V_20 ;
struct V_17 * V_18 ;
F_5 ( L_28 ) ;
V_20 = (struct V_19 * ) F_27 ( V_5 ) ;
F_5 ( L_29 , V_20 ) ;
if ( V_20 ) {
V_18 = V_20 -> V_57 ;
if ( V_18 -> V_52 )
F_23 ( V_18 -> V_52 ) ;
F_5 ( L_30 ) ;
if ( V_18 -> V_28 ) {
F_5 ( L_31 ) ;
F_28 ( V_18 -> V_28 ) ;
F_29 ( V_18 -> V_28 ) ;
F_5
( L_32 ) ;
F_30 ( V_18 -> V_28 ) ;
}
F_25 ( V_18 -> V_30 ) ;
F_25 ( V_18 -> V_29 ) ;
F_5 ( L_33 ) ;
F_24 ( V_18 ) ;
}
F_24 ( V_48 ) ;
}
