static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_3 ) ;
}
static int F_5 ( struct V_4 * V_5 )
{
struct V_6 * V_2 = F_6 ( V_5 ) ;
int V_7 = 0 ;
V_2 -> V_8 = V_5 -> V_9 ;
V_2 -> V_9 = V_5 -> V_9 + F_7 ( V_2 , F_8 ( V_2 ,
& V_2 -> V_8 -> V_10 ) ) ;
V_2 -> V_11 = F_8 ( V_2 , & V_2 -> V_8 -> V_11 ) ;
V_7 = F_9 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_10 ( V_5 ) ;
if ( V_7 )
return V_7 ;
F_11 ( V_2 ) ;
F_12 ( V_2 , 0 ) ;
return V_7 ;
}
static int F_13 ( struct V_12 * V_13 )
{
struct V_4 * V_5 = F_14 ( V_13 ) ;
struct V_6 * V_2 = F_6 ( V_5 ) ;
unsigned long V_14 ;
int V_15 = 0 ;
if ( F_15 ( V_16 , V_2 -> V_17 ) )
F_16 ( 10 ) ;
F_17 ( & V_2 -> V_18 , V_14 ) ;
F_18 ( V_2 , F_19 ( V_13 ) ) ;
F_20 ( V_2 , 0 , & V_2 -> V_9 -> V_19 ) ;
F_8 ( V_2 , & V_2 -> V_9 -> V_19 ) ;
F_21 ( & V_2 -> V_18 , V_14 ) ;
return V_15 ;
}
static int F_22 ( struct V_12 * V_13 )
{
struct V_4 * V_5 = F_14 ( V_13 ) ;
struct V_6 * V_2 = F_6 ( V_5 ) ;
if ( F_15 ( V_16 , V_2 -> V_17 ) )
F_16 ( 100 ) ;
if ( F_8 ( V_2 , & V_2 -> V_9 -> V_20 ) == V_21 ) {
int V_22 = V_23 ;
F_23 ( V_2 ) ;
if ( ! V_5 -> V_24 . V_25 -> V_26 )
V_22 &= ~ V_27 ;
F_20 ( V_2 , V_22 , & V_2 -> V_9 -> V_19 ) ;
F_8 ( V_2 , & V_2 -> V_9 -> V_19 ) ;
return 0 ;
}
F_24 ( V_5 -> V_24 . V_25 ) ;
F_9 ( V_2 ) ;
F_11 ( V_2 ) ;
F_25 ( & V_2 -> V_18 ) ;
if ( V_2 -> V_28 )
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
F_28 ( & V_2 -> V_18 ) ;
F_20 ( V_2 , V_2 -> V_29 , & V_2 -> V_9 -> V_29 ) ;
F_20 ( V_2 , V_21 , & V_2 -> V_9 -> V_20 ) ;
F_8 ( V_2 , & V_2 -> V_9 -> V_29 ) ;
F_12 ( V_2 , 1 ) ;
return 0 ;
}
static int F_29 ( struct V_30 * V_31 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
struct V_32 * V_33 ;
struct V_3 * V_34 ;
const struct V_35 * V_36 = & V_37 ;
int V_38 , V_7 ;
char V_39 [ 20 ] = L_1 ;
static int V_40 = - 1 ;
if ( F_30 () )
return - V_41 ;
V_38 = F_31 ( V_31 , 0 ) ;
if ( V_38 < 0 ) {
V_7 = V_38 ;
goto V_42;
}
if ( ! V_31 -> V_13 . V_43 )
V_31 -> V_13 . V_43 = & V_44 ;
if ( V_31 -> V_45 < 0 )
V_40 ++ ;
else
V_40 = V_31 -> V_45 ;
sprintf ( V_39 , L_2 , V_40 ) ;
V_34 = F_32 ( NULL , V_39 ) ;
if ( F_33 ( V_34 ) ) {
F_34 ( & V_31 -> V_13 , L_3 ) ;
V_7 = F_35 ( V_34 ) ;
goto V_46;
}
V_5 = F_36 ( V_36 , & V_31 -> V_13 , F_37 ( & V_31 -> V_13 ) ) ;
if ( ! V_5 ) {
V_7 = - V_47 ;
goto V_48;
}
V_33 = F_38 ( V_31 , V_49 , 0 ) ;
if ( ! V_33 ) {
V_7 = - V_41 ;
goto V_50;
}
V_5 -> V_51 = V_33 -> V_52 ;
V_5 -> V_53 = F_39 ( V_33 ) ;
if ( ! F_40 ( V_5 -> V_51 , V_5 -> V_53 ,
V_36 -> V_54 ) ) {
V_7 = - V_55 ;
goto V_50;
}
V_5 -> V_9 = F_41 ( V_5 -> V_51 , V_5 -> V_53 ) ;
if ( V_5 -> V_9 == NULL ) {
F_42 ( & V_31 -> V_13 , L_4 ) ;
V_7 = - V_47 ;
goto V_56;
}
V_2 = (struct V_1 * ) F_6 ( V_5 ) ;
V_2 -> V_3 = V_34 ;
F_1 ( V_2 ) ;
V_7 = F_43 ( V_5 , V_38 , V_57 ) ;
if ( V_7 )
goto V_58;
return V_7 ;
V_58:
F_3 ( V_2 ) ;
F_44 ( V_5 -> V_9 ) ;
V_56:
F_45 ( V_5 -> V_51 , V_5 -> V_53 ) ;
V_50:
F_46 ( V_5 ) ;
V_48:
F_47 ( V_34 ) ;
V_46:
V_42:
F_34 ( & V_31 -> V_13 , L_5 , V_7 ) ;
return V_7 ;
}
static int F_48 ( struct V_30 * V_31 )
{
struct V_4 * V_5 = F_49 ( V_31 ) ;
struct V_1 * V_59 = F_50 ( V_5 ) ;
if ( ! V_5 )
return 0 ;
if ( F_51 () )
F_52 () ;
F_53 ( V_5 ) ;
if ( V_59 -> V_3 )
F_3 ( V_59 ) ;
F_44 ( V_5 -> V_9 ) ;
F_45 ( V_5 -> V_51 , V_5 -> V_53 ) ;
F_46 ( V_5 ) ;
if ( V_59 -> V_3 )
F_47 ( V_59 -> V_3 ) ;
return 0 ;
}
