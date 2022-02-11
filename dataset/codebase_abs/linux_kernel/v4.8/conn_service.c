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
static struct V_1 *
F_9 ( struct V_2 * V_3 ,
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
return V_6 ;
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
struct V_1 * F_20 ( struct V_36 * V_37 ,
struct V_38 * V_39 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 ;
struct V_9 * V_10 = F_2 ( V_5 ) ;
struct V_2 * V_3 ;
const char * V_40 = L_4 ;
F_21 ( L_5 ) ;
V_3 = F_22 ( V_37 , V_39 , V_41 ) ;
if ( ! V_3 ) {
F_17 ( L_6 ) ;
return F_23 ( - V_42 ) ;
}
ASSERT ( V_10 -> V_15 . V_33 & V_43 ) ;
F_24 () ;
V_3 = F_25 ( V_37 , V_39 ) ;
if ( V_3 ) {
V_6 = F_1 ( V_3 , V_5 ) ;
if ( V_6 ) {
if ( V_10 -> V_15 . V_44 != V_6 -> V_45 )
goto V_46;
if ( F_26 ( V_6 ) )
goto V_47;
}
if ( ! F_27 ( V_3 ) )
V_3 = NULL ;
}
F_28 () ;
if ( ! V_3 ) {
V_3 = F_22 ( V_37 , V_39 , V_41 ) ;
if ( ! V_3 )
goto V_48;
}
V_6 = F_29 ( V_41 ) ;
if ( ! V_6 )
goto V_49;
V_6 -> V_21 . V_14 = V_10 -> V_15 . V_14 ;
V_6 -> V_21 . V_16 = V_10 -> V_15 . V_16 & V_17 ;
V_6 -> V_50 . V_37 = V_37 ;
V_6 -> V_50 . V_3 = V_3 ;
V_6 -> V_50 . V_51 = V_10 -> V_15 . V_52 ;
V_6 -> V_45 = V_10 -> V_15 . V_44 ;
V_6 -> V_53 = 0 ;
V_6 -> V_54 = V_55 ;
if ( V_6 -> V_50 . V_51 )
V_6 -> V_54 = V_56 ;
F_30 ( V_37 ) ;
F_31 ( & V_57 ) ;
F_32 ( & V_6 -> V_58 , & V_59 ) ;
F_33 ( & V_57 ) ;
F_9 ( V_3 , V_6 ) ;
V_40 = L_7 ;
V_60:
F_34 ( L_8 , V_40 , V_6 -> V_26 , V_6 -> V_21 . V_16 ) ;
F_8 ( L_9 , V_6 , F_15 ( & V_6 -> V_34 ) ) ;
return V_6 ;
V_47:
F_28 () ;
goto V_60;
V_46:
F_28 () ;
F_8 ( L_10 ) ;
return F_23 ( - V_61 ) ;
V_49:
F_35 ( V_3 ) ;
V_48:
F_8 ( L_11 ) ;
return F_23 ( - V_62 ) ;
}
void F_36 ( struct V_1 * V_6 )
{
struct V_2 * V_3 = V_6 -> V_50 . V_3 ;
F_10 ( & V_3 -> V_18 ) ;
if ( F_37 ( V_32 , & V_6 -> V_33 ) )
F_38 ( & V_6 -> V_20 , & V_3 -> V_19 ) ;
F_14 ( & V_3 -> V_18 ) ;
}
