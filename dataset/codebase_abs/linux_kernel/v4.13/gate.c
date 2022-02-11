static void F_1 ( void T_1 * V_1 , void T_1 * V_2 ,
T_2 V_3 , T_2 V_4 )
{
T_2 V_5 , V_6 , V_7 , V_8 , V_9 , V_10 ;
T_2 V_11 = V_12 ;
V_9 = F_2 ( V_1 + V_13 ) ;
V_9 &= ~ V_14 ;
V_9 |= V_3 ;
if ( V_3 == V_15 )
V_9 &= ~ V_16 ;
F_3 ( V_9 , V_1 + V_13 ) ;
V_6 = F_2 ( V_2 + V_17 ) ;
if ( ! ( V_6 & V_18 ) ) {
V_7 = F_2 ( V_2 + V_19 ) ;
V_7 |= V_20 ;
F_3 ( V_7 , V_2 + V_19 ) ;
}
V_5 = 1 << V_4 ;
F_3 ( V_5 , V_21 + V_22 ) ;
do {
V_10 = F_2 ( V_21 + V_23 ) ;
} while ( ( ( V_10 >> V_4 ) & 1 ) && V_11 -- );
V_11 = V_12 ;
do {
V_8 = F_2 ( V_1 + V_24 ) ;
} while ( ! ( ( V_8 & V_14 ) == V_3 ) && V_11 -- );
}
static int F_4 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_29 * V_30 = V_28 -> V_31 ;
T_2 V_8 = F_2 ( V_30 -> V_1 + V_24 ) ;
return ( V_8 & V_32 ) ? 1 : 0 ;
}
static int F_6 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_29 * V_30 = V_28 -> V_31 ;
unsigned long V_33 = 0 ;
if ( V_28 -> V_34 )
F_7 ( V_28 -> V_34 , V_33 ) ;
F_1 ( V_30 -> V_1 , V_30 -> V_2 ,
V_35 , V_30 -> V_4 ) ;
if ( V_28 -> V_34 )
F_8 ( V_28 -> V_34 , V_33 ) ;
return 0 ;
}
static void F_9 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_29 * V_30 = V_28 -> V_31 ;
unsigned long V_33 = 0 ;
if ( V_28 -> V_34 )
F_7 ( V_28 -> V_34 , V_33 ) ;
F_1 ( V_30 -> V_1 , V_30 -> V_2 ,
V_15 , V_30 -> V_4 ) ;
if ( V_28 -> V_34 )
F_8 ( V_28 -> V_34 , V_33 ) ;
}
static struct V_36 * F_10 ( struct V_37 * V_38 ,
const char * V_39 ,
const char * V_40 ,
struct V_29 * V_31 ,
T_3 * V_34 )
{
struct V_41 V_42 ;
struct V_27 * V_28 ;
struct V_36 * V_36 ;
V_28 = F_11 ( sizeof( * V_28 ) , V_43 ) ;
if ( ! V_28 )
return F_12 ( - V_44 ) ;
V_42 . V_39 = V_39 ;
V_42 . V_45 = & V_46 ;
V_42 . V_33 = 0 ;
V_42 . V_47 = ( V_40 ? & V_40 : NULL ) ;
V_42 . V_48 = ( V_40 ? 1 : 0 ) ;
V_28 -> V_31 = V_31 ;
V_28 -> V_34 = V_34 ;
V_28 -> V_26 . V_42 = & V_42 ;
V_36 = F_13 ( NULL , & V_28 -> V_26 ) ;
if ( F_14 ( V_36 ) )
F_15 ( V_28 ) ;
return V_36 ;
}
static void T_4 F_16 ( struct V_49 * V_50 , T_3 * V_34 )
{
const char * V_51 = V_50 -> V_39 ;
const char * V_40 ;
struct V_29 * V_30 ;
struct V_36 * V_36 ;
int V_52 ;
V_30 = F_11 ( sizeof( * V_30 ) , V_43 ) ;
if ( ! V_30 ) {
F_17 ( L_1 , V_53 ) ;
return;
}
V_52 = F_18 ( V_50 , L_2 , L_3 ) ;
V_30 -> V_1 = F_19 ( V_50 , V_52 ) ;
if ( ! V_30 -> V_1 ) {
F_17 ( L_4 , V_53 ) ;
goto V_54;
}
V_52 = F_18 ( V_50 , L_2 , L_5 ) ;
V_30 -> V_2 = F_19 ( V_50 , V_52 ) ;
if ( ! V_30 -> V_2 ) {
F_17 ( L_6 , V_53 ) ;
goto V_55;
}
F_20 ( V_50 , L_7 , & V_30 -> V_4 ) ;
if ( ! V_21 && ! V_30 -> V_4 )
V_21 = V_30 -> V_2 ;
F_21 ( V_50 , L_8 , & V_51 ) ;
V_40 = F_22 ( V_50 , 0 ) ;
if ( ! V_40 ) {
F_17 ( L_9 , V_53 ) ;
goto V_56;
}
V_36 = F_10 ( NULL , V_51 , V_40 , V_30 , V_34 ) ;
if ( ! F_14 ( V_36 ) ) {
F_23 ( V_50 , V_57 , V_36 ) ;
return;
}
F_17 ( L_10 , V_53 , V_50 -> V_39 ) ;
V_56:
F_24 ( V_30 -> V_2 ) ;
V_55:
F_24 ( V_30 -> V_1 ) ;
V_54:
F_15 ( V_30 ) ;
return;
}
static void T_4 F_25 ( struct V_49 * V_50 )
{
F_16 ( V_50 , & V_58 ) ;
}
