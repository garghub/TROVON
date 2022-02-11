static struct V_1 * F_1 ( unsigned long V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( V_2 == V_4 [ V_3 ] . V_2 )
return & V_4 [ V_3 ] . V_5 ;
}
return NULL ;
}
static int F_3 ( struct V_6 * V_7 , int V_8 )
{
struct V_9 * V_10 = F_4 ( V_7 ) ;
int V_11 ;
int V_12 = V_13 ;
if ( V_8 && ! V_10 -> V_14 ) {
V_11 = F_5 ( V_10 -> V_15 , V_16 ) ;
V_11 |= V_17 ;
F_6 ( V_10 -> V_15 , V_16 , V_11 ) ;
do {
V_11 = F_5 ( V_10 -> V_15 , V_18 ) ;
if ( V_11 & V_19 )
break;
F_7 ( 1 ) ;
} while ( -- V_12 );
F_8 ( V_10 -> V_20 , 0 ) ;
V_10 -> V_14 = 1 ;
} else if ( ! V_8 && V_10 -> V_14 ) {
V_10 -> V_14 = 0 ;
V_11 = F_5 ( V_10 -> V_15 , V_16 ) ;
V_11 &= ~ V_17 ;
F_6 ( V_10 -> V_15 , V_16 , V_11 ) ;
do {
V_11 = F_5 ( V_10 -> V_15 , V_18 ) ;
if ( ! ( V_11 & V_19 ) )
break;
F_7 ( 1 ) ;
} while ( -- V_12 );
}
return 0 ;
}
static void F_9 ( struct V_9 * V_10 )
{
T_1 V_11 ;
unsigned long V_12 ;
F_6 ( V_10 -> V_15 , V_21 , V_22 ) ;
V_12 = V_23 + F_10 ( 20 ) ;
do {
V_11 = F_5 ( V_10 -> V_15 , V_18 ) ;
if ( V_11 & V_24 )
break;
} while ( ! F_11 ( F_12 ( V_23 , V_12 ) ) );
}
static int F_13 ( struct V_9 * V_10 )
{
T_1 V_11 ;
unsigned long V_2 ;
struct V_1 * V_25 ;
V_2 = F_14 ( V_10 -> V_26 ) ;
V_25 = F_1 ( V_2 ) ;
if ( ! V_25 ) {
F_15 ( V_10 -> V_27 ,
L_1 , V_2 ) ;
return - V_28 ;
}
V_11 = F_5 ( V_10 -> V_15 , V_29 ) ;
V_11 &= ~ V_30 ;
V_11 |= V_25 -> V_31 << V_32 ;
F_6 ( V_10 -> V_15 , V_29 , V_11 ) ;
V_11 = F_5 ( V_10 -> V_15 , V_16 ) ;
V_11 &= ~ V_33 ;
V_11 |= V_25 -> V_34 << V_35 ;
F_6 ( V_10 -> V_15 , V_16 , V_11 ) ;
V_11 = F_5 ( V_10 -> V_15 , V_29 ) ;
V_11 &= ~ V_36 ;
V_11 |= V_25 -> V_37 << V_38 ;
F_6 ( V_10 -> V_15 , V_29 , V_11 ) ;
V_11 = F_5 ( V_10 -> V_15 , V_39 ) ;
V_11 &= ~ V_40 ;
V_11 |= V_25 -> V_41 << V_42 ;
F_6 ( V_10 -> V_15 , V_39 , V_11 ) ;
V_11 = F_5 ( V_10 -> V_15 , V_43 ) ;
V_11 &= ~ V_44 ;
V_11 |= V_25 -> V_45 << V_46 ;
F_6 ( V_10 -> V_15 , V_43 , V_11 ) ;
F_9 ( V_10 ) ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_4 ( V_7 ) ;
int V_47 ;
V_47 = F_13 ( V_10 ) ;
if ( V_47 )
return V_47 ;
F_8 ( V_10 -> V_20 , 1 ) ;
return 0 ;
}
static int F_17 ( struct V_48 * V_49 )
{
struct V_9 * V_10 ;
struct V_50 * V_51 ;
V_10 = F_18 ( & V_49 -> V_27 , sizeof( * V_10 ) , V_52 ) ;
if ( ! V_10 ) {
F_15 ( & V_49 -> V_27 , L_2 ) ;
return - V_53 ;
}
V_51 = F_19 ( V_49 , V_54 , L_3 ) ;
V_10 -> V_15 = F_20 ( & V_49 -> V_27 , V_51 ) ;
if ( F_21 ( V_10 -> V_15 ) )
return F_22 ( V_10 -> V_15 ) ;
V_10 -> V_27 = & V_49 -> V_27 ;
V_10 -> V_10 . V_27 = V_10 -> V_27 ;
V_10 -> V_10 . V_55 = L_4 ;
V_10 -> V_10 . V_56 = F_16 ;
V_10 -> V_10 . V_57 = F_3 ;
V_10 -> V_10 . type = V_58 ;
V_10 -> V_14 = 1 ;
V_10 -> V_59 = F_23 ( V_10 -> V_27 , L_5 ) ;
if ( F_21 ( V_10 -> V_59 ) ) {
F_15 ( & V_49 -> V_27 , L_6 ) ;
return F_22 ( V_10 -> V_59 ) ;
}
F_24 ( V_10 -> V_59 ) ;
V_10 -> V_60 = F_23 ( V_10 -> V_27 , L_7 ) ;
if ( F_21 ( V_10 -> V_60 ) ) {
F_15 ( & V_49 -> V_27 , L_8 ) ;
return F_22 ( V_10 -> V_60 ) ;
}
F_24 ( V_10 -> V_60 ) ;
V_10 -> V_26 = F_23 ( V_10 -> V_27 , L_9 ) ;
if ( F_21 ( V_10 -> V_26 ) ) {
F_25 ( L_10 , V_61 ) ;
return - V_28 ;
}
V_10 -> V_20 = F_26 () ;
if ( F_21 ( V_10 -> V_20 ) ) {
F_27 ( & V_49 -> V_27 , L_11 ) ;
return - V_62 ;
}
F_8 ( V_10 -> V_20 , 0 ) ;
F_28 ( & V_10 -> V_10 ) ;
F_29 ( V_49 , V_10 ) ;
F_30 ( V_10 -> V_27 ) ;
F_31 ( & V_49 -> V_27 ) ;
return 0 ;
}
static int F_32 ( struct V_48 * V_49 )
{
struct V_9 * V_10 = F_33 ( V_49 ) ;
F_34 ( V_10 -> V_59 ) ;
F_34 ( V_10 -> V_60 ) ;
F_35 ( & V_10 -> V_10 ) ;
if ( ! F_36 ( & V_49 -> V_27 ) )
F_37 ( & V_49 -> V_27 ) ;
F_38 ( & V_49 -> V_27 ) ;
return 0 ;
}
static int F_39 ( struct V_63 * V_27 )
{
struct V_48 * V_49 = F_40 ( V_27 ) ;
struct V_9 * V_10 = F_33 ( V_49 ) ;
F_41 ( V_10 -> V_59 ) ;
F_41 ( V_10 -> V_60 ) ;
return 0 ;
}
static int F_42 ( struct V_63 * V_27 )
{
T_1 V_47 = 0 ;
struct V_48 * V_49 = F_40 ( V_27 ) ;
struct V_9 * V_10 = F_33 ( V_49 ) ;
V_47 = F_43 ( V_10 -> V_60 ) ;
if ( V_47 ) {
F_15 ( V_10 -> V_27 , L_12 , V_47 ) ;
goto V_64;
}
V_47 = F_43 ( V_10 -> V_59 ) ;
if ( V_47 ) {
F_15 ( V_10 -> V_27 , L_13 , V_47 ) ;
goto V_65;
}
return 0 ;
V_65:
F_41 ( V_10 -> V_60 ) ;
V_64:
return V_47 ;
}
