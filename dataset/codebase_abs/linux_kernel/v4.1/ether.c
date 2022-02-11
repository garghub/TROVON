static inline bool F_1 ( void )
{
#ifdef F_2
return true ;
#else
return false ;
#endif
}
static int F_3 ( struct V_1 * V_2 )
{
int V_3 ;
if ( F_4 ( V_2 -> V_4 -> V_5 ) ) {
V_2 -> V_6 = V_7 ;
V_2 -> V_8 |= V_9 ;
}
V_10 = F_5 ( V_11 ) ;
if ( F_6 ( V_10 ) )
return F_7 ( V_10 ) ;
V_3 = F_8 ( V_2 , V_10 ) ;
if ( V_3 < 0 )
F_9 ( V_10 ) ;
return V_3 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( F_4 ( V_2 -> V_4 -> V_5 ) ) {
V_2 -> V_6 = V_7 ;
V_2 -> V_8 |= V_9 ;
}
if ( V_12 ) {
V_13 = F_5 ( V_14 ) ;
if ( F_6 ( V_13 ) )
return F_7 ( V_13 ) ;
V_3 = F_8 ( V_2 , V_13 ) ;
if ( V_3 < 0 )
F_9 ( V_13 ) ;
return V_3 ;
} else if ( F_11 ( V_2 -> V_4 -> V_5 ) ) {
V_15 = F_5 ( V_16 ) ;
if ( F_6 ( V_15 ) )
return F_7 ( V_15 ) ;
V_3 = F_8 ( V_2 , V_15 ) ;
if ( V_3 < 0 )
F_9 ( V_15 ) ;
return V_3 ;
} else {
V_17 = F_5 ( V_18 ) ;
if ( F_6 ( V_17 ) )
return F_7 ( V_17 ) ;
V_3 = F_8 ( V_2 , V_17 ) ;
if ( V_3 < 0 )
F_9 ( V_17 ) ;
return V_3 ;
}
}
static int F_12 ( struct V_19 * V_4 )
{
struct V_20 * V_5 = V_4 -> V_5 ;
struct V_21 * V_22 = NULL ;
struct V_23 * V_24 = NULL ;
struct V_25 * V_26 = NULL ;
struct V_27 * V_28 ;
int V_3 ;
if ( V_12 ) {
V_14 = F_13 ( L_1 ) ;
if ( F_6 ( V_14 ) )
return F_7 ( V_14 ) ;
V_22 = F_14 ( V_14 , struct V_21 , V_29 ) ;
V_28 = V_22 -> V_28 ;
V_30 . V_31 = L_2 ;
V_32 . V_33 = F_15 ( V_34 ) ;
V_32 . V_35 = F_15 ( V_36 ) ;
} else if ( F_11 ( V_5 ) ) {
V_16 = F_13 ( L_3 ) ;
if ( F_6 ( V_16 ) )
return F_7 ( V_16 ) ;
V_24 = F_14 ( V_16 , struct V_23 , V_29 ) ;
V_28 = V_24 -> V_28 ;
V_30 . V_31 = L_4 ;
} else {
V_18 = F_13 ( L_5 ) ;
if ( F_6 ( V_18 ) )
return F_7 ( V_18 ) ;
V_26 = F_14 ( V_18 , struct V_25 ,
V_29 ) ;
V_28 = V_26 -> V_28 ;
V_30 . V_31 = L_6 ;
V_32 . V_33 = F_15 ( V_37 ) ;
V_32 . V_35 = F_15 ( V_38 ) ;
if ( ! F_1 () )
V_32 . V_39 = V_40 ;
}
F_16 ( V_28 , V_41 ) ;
if ( ! F_17 ( V_28 , V_42 ) )
F_18 ( L_7 , V_42 ) ;
if ( ! F_19 ( V_28 , V_43 ) )
F_18 ( L_8 , V_43 ) ;
if ( F_1 () ) {
F_20 ( V_28 , V_4 -> V_5 ) ;
V_3 = F_21 ( V_28 ) ;
if ( V_3 )
goto V_44;
if ( V_12 )
V_22 -> V_45 = true ;
else if ( F_11 ( V_5 ) )
V_24 -> V_45 = true ;
else
V_26 -> V_45 = true ;
V_11 = F_13 ( L_9 ) ;
if ( F_6 ( V_11 ) ) {
V_3 = F_7 ( V_11 ) ;
goto V_44;
}
F_22 ( V_11 , V_28 ) ;
V_32 . V_33 = F_15 ( V_46 ) ;
V_32 . V_35 = F_15 ( V_47 ) ;
V_32 . V_48 = 2 ;
}
V_3 = F_23 ( V_4 , V_49 ) ;
if ( V_3 < 0 )
goto V_50;
V_32 . V_51 = V_49 [ V_52 ] . V_53 ;
V_32 . V_54 = V_49 [ V_55 ] . V_53 ;
if ( F_1 () ) {
V_3 = F_24 ( V_4 , & V_56 ,
F_3 ) ;
if ( V_3 < 0 )
goto V_50;
}
V_3 = F_24 ( V_4 , & V_30 , F_10 ) ;
if ( V_3 < 0 )
goto V_50;
F_25 ( V_4 , & V_57 ) ;
F_26 ( & V_5 -> V_58 , L_10 V_59 L_11 ,
V_60 ) ;
return 0 ;
V_50:
if ( F_1 () )
F_27 ( V_11 ) ;
V_44:
if ( V_12 )
F_27 ( V_14 ) ;
else if ( F_11 ( V_5 ) )
F_27 ( V_16 ) ;
else
F_27 ( V_18 ) ;
return V_3 ;
}
static int F_28 ( struct V_19 * V_4 )
{
if ( F_1 () ) {
F_9 ( V_10 ) ;
F_27 ( V_11 ) ;
}
if ( V_12 ) {
F_9 ( V_13 ) ;
F_27 ( V_14 ) ;
} else if ( F_11 ( V_4 -> V_5 ) ) {
F_9 ( V_15 ) ;
F_27 ( V_16 ) ;
} else {
F_9 ( V_17 ) ;
F_27 ( V_18 ) ;
}
return 0 ;
}
