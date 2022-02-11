struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 = NULL ;
struct V_7 V_8 ;
struct V_9 * V_10 = F_2 ( V_5 ) ;
struct V_11 * V_12 ;
unsigned int V_13 = 0 ;
V_8 . V_14 = V_10 -> V_15 . V_14 ;
V_8 . V_16 = V_10 -> V_15 . V_16 & V_17 ;
do {
F_3 ( & V_3 -> V_18 , & V_13 ) ;
V_12 = F_4 ( V_3 -> V_19 . V_11 ) ;
while ( V_12 ) {
V_6 = F_5 ( V_12 , struct V_1 , V_20 ) ;
if ( V_6 -> V_21 . V_22 < V_8 . V_22 )
V_12 = F_4 ( V_12 -> V_23 ) ;
else if ( V_6 -> V_21 . V_22 > V_8 . V_22 )
V_12 = F_4 ( V_12 -> V_24 ) ;
else
goto V_25;
V_6 = NULL ;
}
} while ( F_6 ( & V_3 -> V_18 , V_13 ) );
V_25:
F_7 ( & V_3 -> V_18 , V_13 ) ;
F_8 ( L_1 , V_6 ? V_6 -> V_26 : - 1 ) ;
return V_6 ;
}
static void F_9 ( struct V_2 * V_3 ,
struct V_1 * V_6 )
{
struct V_1 * V_27 = NULL ;
struct V_7 V_8 = V_6 -> V_21 ;
struct V_11 * * V_28 , * V_29 ;
F_10 ( & V_3 -> V_18 ) ;
V_28 = & V_3 -> V_19 . V_11 ;
V_29 = NULL ;
while ( * V_28 ) {
V_29 = * V_28 ;
V_27 = F_5 ( V_29 ,
struct V_1 , V_20 ) ;
if ( V_27 -> V_21 . V_22 < V_8 . V_22 )
V_28 = & ( * V_28 ) -> V_23 ;
else if ( V_27 -> V_21 . V_22 > V_8 . V_22 )
V_28 = & ( * V_28 ) -> V_24 ;
else
goto V_30;
}
F_11 ( & V_6 -> V_20 , V_29 , V_28 ) ;
F_12 ( & V_6 -> V_20 , & V_3 -> V_19 ) ;
V_31:
F_13 ( V_32 , & V_6 -> V_33 ) ;
F_14 ( & V_3 -> V_18 ) ;
F_8 ( L_2 , V_6 -> V_26 ) ;
return;
V_30:
if ( F_15 ( & V_27 -> V_34 ) == 0 )
goto V_35;
F_14 ( & V_3 -> V_18 ) ;
F_16 () ;
V_35:
F_17 ( L_3 ) ;
F_18 ( & V_27 -> V_20 ,
& V_6 -> V_20 ,
& V_3 -> V_19 ) ;
F_19 ( V_32 , & V_27 -> V_33 ) ;
goto V_31;
}
struct V_1 * F_20 ( T_1 V_36 )
{
struct V_1 * V_6 = F_21 ( V_36 ) ;
if ( V_6 ) {
V_6 -> V_37 = V_38 ;
F_22 ( & V_6 -> V_34 , 2 ) ;
F_23 ( & V_39 ) ;
F_24 ( & V_6 -> V_40 , & V_41 ) ;
F_24 ( & V_6 -> V_42 , & V_43 ) ;
F_25 ( & V_39 ) ;
F_26 ( V_6 , V_44 ,
F_15 ( & V_6 -> V_34 ) ,
F_27 ( 0 ) ) ;
}
return V_6 ;
}
void F_28 ( struct V_1 * V_6 ,
struct V_4 * V_5 )
{
struct V_9 * V_10 = F_2 ( V_5 ) ;
F_29 ( L_4 ) ;
V_6 -> V_21 . V_14 = V_10 -> V_15 . V_14 ;
V_6 -> V_21 . V_16 = V_10 -> V_15 . V_16 & V_17 ;
V_6 -> V_45 . V_46 = V_10 -> V_15 . V_47 ;
V_6 -> V_48 = V_10 -> V_15 . V_49 ;
V_6 -> V_50 = 0 ;
if ( V_6 -> V_48 )
V_6 -> V_37 = V_51 ;
else
V_6 -> V_37 = V_52 ;
F_9 ( V_6 -> V_45 . V_3 , V_6 ) ;
F_30 ( L_5 , V_6 -> V_26 , V_6 -> V_21 . V_16 ) ;
}
void F_31 ( struct V_1 * V_6 )
{
struct V_2 * V_3 = V_6 -> V_45 . V_3 ;
F_10 ( & V_3 -> V_18 ) ;
if ( F_32 ( V_32 , & V_6 -> V_33 ) )
F_33 ( & V_6 -> V_20 , & V_3 -> V_19 ) ;
F_14 ( & V_3 -> V_18 ) ;
}
