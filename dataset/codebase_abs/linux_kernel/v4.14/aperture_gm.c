static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
unsigned int V_8 ;
T_1 V_9 , V_10 , V_11 ;
struct V_12 * V_13 ;
int V_14 ;
if ( V_3 ) {
V_13 = & V_2 -> V_15 . V_16 ;
V_11 = F_2 ( V_2 ) ;
V_9 = F_3 ( F_4 ( V_5 ) , V_17 ) ;
V_10 = F_3 ( F_5 ( V_5 ) , V_17 ) ;
V_8 = V_18 ;
} else {
V_13 = & V_2 -> V_15 . V_19 ;
V_11 = F_6 ( V_2 ) ;
V_9 = F_3 ( F_7 ( V_5 ) , V_17 ) ;
V_10 = F_3 ( F_8 ( V_5 ) , V_17 ) ;
V_8 = V_20 ;
}
F_9 ( & V_7 -> V_21 . V_22 ) ;
V_14 = F_10 ( & V_7 -> V_23 . V_24 , V_13 ,
V_11 , V_17 ,
V_25 ,
V_9 , V_10 , V_8 ) ;
F_11 ( & V_7 -> V_21 . V_22 ) ;
if ( V_14 )
F_12 ( L_1 ,
V_3 ? L_2 : L_3 ) ;
return V_14 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
int V_14 ;
V_14 = F_1 ( V_2 , false ) ;
if ( V_14 )
return V_14 ;
V_14 = F_1 ( V_2 , true ) ;
if ( V_14 )
goto V_26;
F_14 ( L_4 , V_2 -> V_27 ,
F_15 ( V_2 ) , F_6 ( V_2 ) ) ;
F_14 ( L_5 , V_2 -> V_27 ,
F_16 ( V_2 ) , F_2 ( V_2 ) ) ;
return 0 ;
V_26:
F_9 ( & V_7 -> V_21 . V_22 ) ;
F_17 ( & V_2 -> V_15 . V_19 ) ;
F_11 ( & V_7 -> V_21 . V_22 ) ;
return V_14 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_7 ;
F_9 ( & V_7 -> V_21 . V_22 ) ;
F_17 ( & V_2 -> V_15 . V_19 ) ;
F_17 ( & V_2 -> V_15 . V_16 ) ;
F_11 ( & V_7 -> V_21 . V_22 ) ;
}
void F_19 ( struct V_1 * V_2 ,
T_2 V_28 , T_1 V_29 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_30 * V_31 ;
T_3 V_32 , V_33 ;
F_20 ( V_7 ) ;
if ( F_21 ( V_28 > F_22 ( V_2 ) ) )
return;
V_31 = V_2 -> V_28 . V_34 [ V_28 ] ;
if ( F_21 ( ! V_31 ) )
return;
V_32 = F_23 ( V_31 -> V_27 ) ;
V_33 = F_24 ( V_31 -> V_27 ) ;
F_25 ( V_32 , 0 ) ;
F_26 ( V_32 ) ;
F_25 ( V_33 , F_27 ( V_29 ) ) ;
F_25 ( V_32 , F_28 ( V_29 ) ) ;
F_26 ( V_32 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < F_22 ( V_2 ) ; V_35 ++ )
F_19 ( V_2 , V_35 , 0 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_30 * V_31 ;
T_2 V_35 ;
if ( F_21 ( ! F_22 ( V_2 ) ) )
return;
F_31 ( V_7 ) ;
F_9 ( & V_7 -> V_21 . V_22 ) ;
F_29 ( V_2 ) ;
for ( V_35 = 0 ; V_35 < F_22 ( V_2 ) ; V_35 ++ ) {
V_31 = V_2 -> V_28 . V_34 [ V_35 ] ;
F_32 ( & V_31 -> V_36 ,
& V_7 -> V_37 . V_38 ) ;
}
F_11 ( & V_7 -> V_21 . V_22 ) ;
F_33 ( V_7 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_30 * V_31 ;
int V_35 ;
struct V_39 * V_40 , * V_41 ;
F_31 ( V_7 ) ;
F_9 ( & V_7 -> V_21 . V_22 ) ;
V_35 = 0 ;
F_35 (pos, q, &dev_priv->mm.fence_list) {
V_31 = F_36 ( V_40 , struct V_30 , V_36 ) ;
if ( V_31 -> V_42 || V_31 -> V_43 )
continue;
F_37 ( V_40 ) ;
V_2 -> V_28 . V_34 [ V_35 ] = V_31 ;
if ( ++ V_35 == F_22 ( V_2 ) )
break;
}
if ( V_35 != F_22 ( V_2 ) )
goto V_44;
F_29 ( V_2 ) ;
F_11 ( & V_7 -> V_21 . V_22 ) ;
F_33 ( V_7 ) ;
return 0 ;
V_44:
for ( V_35 = 0 ; V_35 < F_22 ( V_2 ) ; V_35 ++ ) {
V_31 = V_2 -> V_28 . V_34 [ V_35 ] ;
if ( ! V_31 )
continue;
F_32 ( & V_31 -> V_36 ,
& V_7 -> V_37 . V_38 ) ;
}
F_11 ( & V_7 -> V_21 . V_22 ) ;
F_33 ( V_7 ) ;
return - V_45 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_15 . V_46 -= F_6 ( V_2 ) ;
V_5 -> V_15 . V_47 -= F_2 ( V_2 ) ;
V_5 -> V_28 . V_48 -= F_22 ( V_2 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned long V_51 , V_52 , V_53 , V_54 ;
const char * V_55 ;
if ( ! V_50 -> V_56 || ! V_50 -> V_57 || ! V_50 -> V_58 ) {
F_40 ( L_6 ) ;
return - V_59 ;
}
V_55 = L_7 ;
V_53 = F_41 ( V_5 ) - V_60 ;
V_54 = V_5 -> V_15 . V_46 ;
V_52 = V_53 - V_54 ;
V_51 = F_42 ( V_50 -> V_56 ) ;
if ( V_51 > V_52 )
goto V_61;
F_6 ( V_2 ) = F_3 ( V_51 , V_17 ) ;
V_55 = L_8 ;
V_53 = F_43 ( V_5 ) - V_62 ;
V_54 = V_5 -> V_15 . V_47 ;
V_52 = V_53 - V_54 ;
V_51 = F_42 ( V_50 -> V_57 ) ;
if ( V_51 > V_52 )
goto V_61;
F_2 ( V_2 ) = F_3 ( V_51 , V_17 ) ;
V_55 = L_9 ;
V_53 = F_44 ( V_5 ) - V_63 ;
V_54 = V_5 -> V_28 . V_48 ;
V_52 = V_53 - V_54 ;
V_51 = V_50 -> V_58 ;
if ( V_51 > V_52 )
goto V_61;
F_22 ( V_2 ) = V_51 ;
V_5 -> V_15 . V_46 += F_42 ( V_50 -> V_56 ) ;
V_5 -> V_15 . V_47 += F_42 ( V_50 -> V_57 ) ;
V_5 -> V_28 . V_48 += V_50 -> V_58 ;
return 0 ;
V_61:
F_12 ( L_10 , V_55 ) ;
F_12 ( L_11 ,
F_45 ( V_51 ) , F_45 ( V_52 ) ,
F_45 ( V_53 ) , F_45 ( V_54 ) ) ;
return - V_45 ;
}
void F_46 ( struct V_1 * V_2 )
{
F_18 ( V_2 ) ;
F_30 ( V_2 ) ;
F_38 ( V_2 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_7 ;
F_31 ( V_7 ) ;
F_29 ( V_2 ) ;
F_33 ( V_7 ) ;
}
int F_48 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
int V_14 ;
V_14 = F_39 ( V_2 , V_50 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_13 ( V_2 ) ;
if ( V_14 )
goto V_64;
V_14 = F_34 ( V_2 ) ;
if ( V_14 )
goto V_65;
return 0 ;
V_65:
F_18 ( V_2 ) ;
V_64:
F_38 ( V_2 ) ;
return V_14 ;
}
