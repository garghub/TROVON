static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 ) ;
F_3 ( V_4 -> V_6 ) ;
F_3 ( V_4 -> V_7 ) ;
F_4 ( V_4 -> V_8 ) ;
F_5 ( V_4 ) ;
}
static int
F_6 ( struct V_9 * V_9 , struct V_10 * V_11 )
{
struct V_3 * V_4 = F_2 ( V_9 -> V_12 ) ;
V_11 -> V_13 = V_14 ;
V_11 -> V_15 = V_9 -> V_12 -> V_16 ;
V_11 -> V_17 = V_4 -> V_18 -> V_19 ;
V_11 -> V_20 = V_4 -> V_18 -> V_21 ;
V_11 -> V_22 = 0 ;
V_11 -> V_23 = 0 ;
V_11 -> V_24 = V_4 -> V_18 -> V_25 ;
V_11 -> V_26 = V_27 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_28 , int * V_29 , char * V_30 )
{
* V_29 |= V_31 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , void * V_32 , int V_33 )
{
struct V_3 * V_4 ;
struct V_34 * V_35 ;
struct V_36 * V_37 = NULL ;
T_1 V_38 ;
struct V_39 * V_40 ;
int V_41 = - V_42 ;
V_2 -> V_43 |= V_31 ;
V_4 = F_9 ( sizeof( * V_4 ) , V_44 ) ;
if ( ! V_4 ) {
F_10 ( V_45 L_1 ) ;
return - V_46 ;
}
V_38 = F_11 ( V_2 , V_47 ) ;
if ( ! V_38 ) {
F_10 ( V_45 L_2 ) ;
goto V_48;
}
V_37 = F_12 ( V_2 , 1 ) ;
if ( ! V_37 || ! F_13 ( V_37 ) ) {
if ( ! V_33 ) {
F_10 ( V_45
L_3 ) ;
}
goto V_48;
}
V_35 = (struct V_34 * ) V_37 -> V_49 ;
if ( V_35 -> V_50 != V_14 ) {
if ( ! V_33 )
F_10 ( V_51 L_4 ) ;
goto V_48;
}
if ( ( V_35 -> V_52 < 2 || V_35 -> V_52 > 4 ) && ! V_33 ) {
F_10 ( V_51 L_5 ,
V_35 -> V_52 ) ;
goto V_48;
}
#ifdef F_14
F_10 ( V_53 L_6 , V_35 -> V_52 ) ;
F_10 ( V_53 L_7 , V_35 -> V_54 ) ;
#endif
V_2 -> V_55 = V_35 -> V_50 ;
V_2 -> V_56 = V_4 ;
V_4 -> V_18 = V_35 ;
V_4 -> V_8 = V_37 ;
V_4 -> V_57 = V_35 -> V_58 [ 0 ] ;
V_4 -> V_59 = V_35 -> V_60 ;
if ( ! F_15 ( V_2 , V_35 -> V_54 ) ) {
F_10 ( V_45 L_8 ) ;
goto V_48;
}
if ( F_16 ( V_2 , V_38 ) ) {
F_10 ( V_45 L_9 ) ;
goto V_48;
}
if ( F_17 ( V_2 ) ) {
F_10 ( V_45 L_10 ) ;
goto V_48;
}
V_2 -> V_61 = & V_62 ;
V_40 = F_18 ( V_2 , V_63 ) ;
if ( F_19 ( V_40 ) ) {
V_41 = F_20 ( V_40 ) ;
goto V_48;
}
V_2 -> V_64 = F_21 ( V_40 ) ;
if ( ! V_2 -> V_64 ) {
F_22 ( V_40 ) ;
F_10 ( V_45 L_11 ) ;
goto V_65;
}
return 0 ;
V_65:
F_3 ( V_4 -> V_5 ) ;
F_3 ( V_4 -> V_6 ) ;
F_3 ( V_4 -> V_7 ) ;
V_48:
F_4 ( V_37 ) ;
F_5 ( V_4 ) ;
return V_41 ;
}
static struct V_9 * F_23 ( struct V_66 * V_67 ,
int V_29 , const char * V_68 , void * V_30 )
{
return F_24 ( V_67 , V_29 , V_68 , V_30 , F_8 ) ;
}
static int T_2
F_25 ( void )
{
int V_69 ;
V_70 = F_26 ( L_12 ,
sizeof( struct V_71 ) , 0 ,
V_72 | V_73 , NULL ) ;
if ( ! V_70 )
return - V_46 ;
V_69 = F_27 ( & V_74 ) ;
if ( V_69 < 0 )
F_28 ( V_70 ) ;
return V_69 ;
}
static void T_3
F_29 ( void )
{
F_30 ( & V_74 ) ;
F_28 ( V_70 ) ;
}
