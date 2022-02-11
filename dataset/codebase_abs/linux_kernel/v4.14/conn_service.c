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
break;
V_6 = NULL ;
}
} while ( F_6 ( & V_3 -> V_18 , V_13 ) );
F_7 ( & V_3 -> V_18 , V_13 ) ;
F_8 ( L_1 , V_6 ? V_6 -> V_25 : - 1 ) ;
return V_6 ;
}
static void F_9 ( struct V_2 * V_3 ,
struct V_1 * V_6 )
{
struct V_1 * V_26 = NULL ;
struct V_7 V_8 = V_6 -> V_21 ;
struct V_11 * * V_27 , * V_28 ;
F_10 ( & V_3 -> V_18 ) ;
V_27 = & V_3 -> V_19 . V_11 ;
V_28 = NULL ;
while ( * V_27 ) {
V_28 = * V_27 ;
V_26 = F_5 ( V_28 ,
struct V_1 , V_20 ) ;
if ( V_26 -> V_21 . V_22 < V_8 . V_22 )
V_27 = & ( * V_27 ) -> V_23 ;
else if ( V_26 -> V_21 . V_22 > V_8 . V_22 )
V_27 = & ( * V_27 ) -> V_24 ;
else
goto V_29;
}
F_11 ( & V_6 -> V_20 , V_28 , V_27 ) ;
F_12 ( & V_6 -> V_20 , & V_3 -> V_19 ) ;
V_30:
F_13 ( V_31 , & V_6 -> V_32 ) ;
F_14 ( & V_3 -> V_18 ) ;
F_8 ( L_2 , V_6 -> V_25 ) ;
return;
V_29:
if ( F_15 ( & V_26 -> V_33 ) == 0 )
goto V_34;
F_14 ( & V_3 -> V_18 ) ;
F_16 () ;
V_34:
F_17 ( L_3 ) ;
F_18 ( & V_26 -> V_20 ,
& V_6 -> V_20 ,
& V_3 -> V_19 ) ;
F_19 ( V_31 , & V_26 -> V_32 ) ;
goto V_30;
}
struct V_1 * F_20 ( struct V_35 * V_36 ,
T_1 V_37 )
{
struct V_1 * V_6 = F_21 ( V_37 ) ;
if ( V_6 ) {
V_6 -> V_38 = V_39 ;
F_22 ( & V_6 -> V_33 , 2 ) ;
F_23 ( & V_36 -> V_40 ) ;
F_24 ( & V_6 -> V_41 , & V_36 -> V_19 ) ;
F_24 ( & V_6 -> V_42 , & V_36 -> V_43 ) ;
F_25 ( & V_36 -> V_40 ) ;
F_26 ( V_6 , V_44 ,
F_15 ( & V_6 -> V_33 ) ,
F_27 ( 0 ) ) ;
}
return V_6 ;
}
void F_28 ( struct V_45 * V_46 ,
struct V_1 * V_6 ,
struct V_4 * V_5 )
{
struct V_9 * V_10 = F_2 ( V_5 ) ;
F_29 ( L_4 ) ;
V_6 -> V_21 . V_14 = V_10 -> V_15 . V_14 ;
V_6 -> V_21 . V_16 = V_10 -> V_15 . V_16 & V_17 ;
V_6 -> V_47 . V_48 = V_10 -> V_15 . V_49 ;
V_6 -> V_48 = V_10 -> V_15 . V_49 ;
V_6 -> V_50 = V_10 -> V_15 . V_51 ;
V_6 -> V_52 = 0 ;
if ( V_6 -> V_50 )
V_6 -> V_38 = V_53 ;
else
V_6 -> V_38 = V_54 ;
if ( V_10 -> V_15 . V_55 == V_56 &&
V_6 -> V_48 == V_46 -> V_57 . V_58 )
V_6 -> V_48 = V_46 -> V_57 . V_59 ;
F_9 ( V_6 -> V_47 . V_3 , V_6 ) ;
F_30 ( L_5 , V_6 -> V_25 , V_6 -> V_21 . V_16 ) ;
}
void F_31 ( struct V_1 * V_6 )
{
struct V_2 * V_3 = V_6 -> V_47 . V_3 ;
F_10 ( & V_3 -> V_18 ) ;
if ( F_32 ( V_31 , & V_6 -> V_32 ) )
F_33 ( & V_6 -> V_20 , & V_3 -> V_19 ) ;
F_14 ( & V_3 -> V_18 ) ;
}
