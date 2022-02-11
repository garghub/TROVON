static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
T_1 V_8 , V_9 ;
T_2 V_10 , V_11 , V_12 ;
struct V_13 * V_14 ;
int V_15 = 0 ;
int V_16 ;
if ( V_3 ) {
V_9 = V_17 ;
V_8 = V_18 ;
V_14 = & V_2 -> V_19 . V_20 ;
V_12 = F_2 ( V_2 ) ;
V_10 = F_3 ( V_5 ) ;
V_11 = F_4 ( V_5 ) ;
} else {
V_9 = V_21 ;
V_8 = V_22 ;
V_14 = & V_2 -> V_19 . V_23 ;
V_12 = F_5 ( V_2 ) ;
V_10 = F_6 ( V_5 ) ;
V_11 = F_7 ( V_5 ) ;
}
F_8 ( & V_7 -> V_24 . V_25 ) ;
V_26:
V_16 = F_9 ( & V_7 -> V_27 . V_28 . V_29 ,
V_14 , V_12 , 4096 , 0 ,
V_10 , V_11 , V_9 ,
V_8 ) ;
if ( V_16 ) {
V_16 = F_10 ( & V_7 -> V_27 . V_28 ,
V_12 , 4096 , 0 , V_10 , V_11 , 0 ) ;
if ( V_16 == 0 && ++ V_15 < 3 )
goto V_26;
F_11 ( L_1 ,
V_3 ? L_2 : L_3 , V_15 ) ;
}
F_12 ( & V_7 -> V_24 . V_25 ) ;
return V_16 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
int V_16 ;
V_16 = F_1 ( V_2 , false ) ;
if ( V_16 )
return V_16 ;
V_16 = F_1 ( V_2 , true ) ;
if ( V_16 )
goto V_30;
F_14 ( L_4 , V_2 -> V_31 ,
F_15 ( V_2 ) , F_5 ( V_2 ) ) ;
F_14 ( L_5 , V_2 -> V_31 ,
F_16 ( V_2 ) , F_2 ( V_2 ) ) ;
return 0 ;
V_30:
F_8 ( & V_7 -> V_24 . V_25 ) ;
F_17 ( & V_2 -> V_19 . V_23 ) ;
F_12 ( & V_7 -> V_24 . V_25 ) ;
return V_16 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_7 ;
F_8 ( & V_7 -> V_24 . V_25 ) ;
F_17 ( & V_2 -> V_19 . V_23 ) ;
F_17 ( & V_2 -> V_19 . V_20 ) ;
F_12 ( & V_7 -> V_24 . V_25 ) ;
}
void F_19 ( struct V_1 * V_2 ,
T_1 V_32 , T_2 V_33 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_34 * V_35 ;
T_3 V_36 , V_37 ;
F_20 ( V_7 ) ;
if ( F_21 ( V_32 > F_22 ( V_2 ) ) )
return;
V_35 = V_2 -> V_32 . V_38 [ V_32 ] ;
if ( F_21 ( ! V_35 ) )
return;
V_36 = F_23 ( V_35 -> V_31 ) ;
V_37 = F_24 ( V_35 -> V_31 ) ;
F_25 ( V_36 , 0 ) ;
F_26 ( V_36 ) ;
F_25 ( V_37 , F_27 ( V_33 ) ) ;
F_25 ( V_36 , F_28 ( V_33 ) ) ;
F_26 ( V_36 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < F_22 ( V_2 ) ; V_39 ++ )
F_19 ( V_2 , V_39 , 0 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_34 * V_35 ;
T_1 V_39 ;
if ( F_21 ( ! F_22 ( V_2 ) ) )
return;
F_31 ( V_7 ) ;
F_8 ( & V_7 -> V_24 . V_25 ) ;
F_29 ( V_2 ) ;
for ( V_39 = 0 ; V_39 < F_22 ( V_2 ) ; V_39 ++ ) {
V_35 = V_2 -> V_32 . V_38 [ V_39 ] ;
F_32 ( & V_35 -> V_40 ,
& V_7 -> V_29 . V_41 ) ;
}
F_12 ( & V_7 -> V_24 . V_25 ) ;
F_33 ( V_7 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_34 * V_35 ;
int V_39 ;
struct V_42 * V_43 , * V_44 ;
F_31 ( V_7 ) ;
F_8 ( & V_7 -> V_24 . V_25 ) ;
V_39 = 0 ;
F_35 (pos, q, &dev_priv->mm.fence_list) {
V_35 = F_36 ( V_43 , struct V_34 , V_40 ) ;
if ( V_35 -> V_45 || V_35 -> V_46 )
continue;
F_37 ( V_43 ) ;
V_2 -> V_32 . V_38 [ V_39 ] = V_35 ;
if ( ++ V_39 == F_22 ( V_2 ) )
break;
}
if ( V_39 != F_22 ( V_2 ) )
goto V_47;
F_29 ( V_2 ) ;
F_12 ( & V_7 -> V_24 . V_25 ) ;
F_33 ( V_7 ) ;
return 0 ;
V_47:
for ( V_39 = 0 ; V_39 < F_22 ( V_2 ) ; V_39 ++ ) {
V_35 = V_2 -> V_32 . V_38 [ V_39 ] ;
if ( ! V_35 )
continue;
F_32 ( & V_35 -> V_40 ,
& V_7 -> V_29 . V_41 ) ;
}
F_12 ( & V_7 -> V_24 . V_25 ) ;
F_33 ( V_7 ) ;
return - V_48 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_19 . V_49 -= F_5 ( V_2 ) ;
V_5 -> V_19 . V_50 -= F_2 ( V_2 ) ;
V_5 -> V_32 . V_51 -= F_22 ( V_2 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned long V_54 , V_55 , V_56 , V_57 ;
const char * V_58 ;
if ( ! V_53 -> V_59 || ! V_53 -> V_60 || ! V_53 -> V_61 ) {
F_11 ( L_6 ) ;
return - V_62 ;
}
V_58 = L_7 ;
V_56 = F_40 ( V_5 ) - V_63 ;
V_57 = V_5 -> V_19 . V_49 ;
V_55 = V_56 - V_57 ;
V_54 = F_41 ( V_53 -> V_59 ) ;
if ( V_54 > V_55 )
goto V_64;
F_5 ( V_2 ) = V_54 ;
V_58 = L_8 ;
V_56 = F_42 ( V_5 ) - V_65 ;
V_57 = V_5 -> V_19 . V_50 ;
V_55 = V_56 - V_57 ;
V_54 = F_41 ( V_53 -> V_60 ) ;
if ( V_54 > V_55 )
goto V_64;
F_2 ( V_2 ) = V_54 ;
V_58 = L_9 ;
V_56 = F_43 ( V_5 ) - V_66 ;
V_57 = V_5 -> V_32 . V_51 ;
V_55 = V_56 - V_57 ;
V_54 = V_53 -> V_61 ;
if ( V_54 > V_55 )
goto V_64;
F_22 ( V_2 ) = V_54 ;
V_5 -> V_19 . V_49 += F_41 ( V_53 -> V_59 ) ;
V_5 -> V_19 . V_50 += F_41 ( V_53 -> V_60 ) ;
V_5 -> V_32 . V_51 += V_53 -> V_61 ;
return 0 ;
V_64:
F_11 ( L_10 , V_2 -> V_31 , V_58 ) ;
F_11 ( L_11 ,
V_2 -> V_31 , F_44 ( V_54 ) , F_44 ( V_55 ) ,
F_44 ( V_56 ) , F_44 ( V_57 ) ) ;
return - V_48 ;
}
void F_45 ( struct V_1 * V_2 )
{
F_18 ( V_2 ) ;
F_30 ( V_2 ) ;
F_38 ( V_2 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_7 ;
F_31 ( V_7 ) ;
F_29 ( V_2 ) ;
F_33 ( V_7 ) ;
}
int F_47 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
int V_16 ;
V_16 = F_39 ( V_2 , V_53 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_13 ( V_2 ) ;
if ( V_16 )
goto V_67;
V_16 = F_34 ( V_2 ) ;
if ( V_16 )
goto V_68;
return 0 ;
V_68:
F_18 ( V_2 ) ;
V_67:
F_38 ( V_2 ) ;
return V_16 ;
}
