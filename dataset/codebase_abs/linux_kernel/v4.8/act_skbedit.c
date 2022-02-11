static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct F_1 * V_7 = F_2 ( V_4 ) ;
F_3 ( & V_7 -> V_8 ) ;
F_4 ( & V_7 -> V_9 ) ;
F_5 ( & V_7 -> V_10 , V_2 ) ;
if ( V_7 -> V_11 & V_12 )
V_2 -> V_13 = V_7 -> V_13 ;
if ( V_7 -> V_11 & V_14 &&
V_2 -> V_15 -> V_16 > V_7 -> V_17 )
F_6 ( V_2 , V_7 -> V_17 ) ;
if ( V_7 -> V_11 & V_18 )
V_2 -> V_19 = V_7 -> V_19 ;
if ( V_7 -> V_11 & V_20 )
V_2 -> V_21 = V_7 -> V_22 ;
F_7 ( & V_7 -> V_8 ) ;
return V_7 -> V_23 ;
}
static int F_8 ( struct V_24 * V_24 , struct V_25 * V_26 ,
struct V_25 * V_27 , struct V_3 * * V_4 ,
int V_28 , int V_29 )
{
struct V_30 * V_31 = F_9 ( V_24 , V_32 ) ;
struct V_25 * V_33 [ V_34 + 1 ] ;
struct V_35 * V_36 ;
struct F_1 * V_7 ;
T_1 V_11 = 0 , * V_13 = NULL , * V_19 = NULL ;
T_2 * V_17 = NULL , * V_22 = NULL ;
bool V_37 = false ;
int V_38 = 0 , V_39 ;
if ( V_26 == NULL )
return - V_40 ;
V_39 = F_10 ( V_33 , V_34 , V_26 , V_41 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_33 [ V_42 ] == NULL )
return - V_40 ;
if ( V_33 [ V_43 ] != NULL ) {
V_11 |= V_12 ;
V_13 = F_11 ( V_33 [ V_43 ] ) ;
}
if ( V_33 [ V_44 ] != NULL ) {
V_11 |= V_14 ;
V_17 = F_11 ( V_33 [ V_44 ] ) ;
}
if ( V_33 [ V_45 ] != NULL ) {
V_22 = F_11 ( V_33 [ V_45 ] ) ;
if ( ! F_12 ( * V_22 ) )
return - V_40 ;
V_11 |= V_20 ;
}
if ( V_33 [ V_46 ] != NULL ) {
V_11 |= V_18 ;
V_19 = F_11 ( V_33 [ V_46 ] ) ;
}
V_36 = F_11 ( V_33 [ V_42 ] ) ;
V_37 = F_13 ( V_31 , V_36 -> V_47 , V_4 , V_29 ) ;
if ( V_37 && V_29 )
return 0 ;
if ( ! V_11 ) {
F_14 ( * V_4 , V_29 ) ;
return - V_40 ;
}
if ( ! V_37 ) {
V_38 = F_15 ( V_31 , V_36 -> V_47 , V_27 , V_4 ,
& V_48 , V_29 , false ) ;
if ( V_38 )
return V_38 ;
V_7 = F_2 ( * V_4 ) ;
V_38 = V_49 ;
} else {
V_7 = F_2 ( * V_4 ) ;
F_14 ( * V_4 , V_29 ) ;
if ( ! V_28 )
return - V_50 ;
}
F_16 ( & V_7 -> V_8 ) ;
V_7 -> V_11 = V_11 ;
if ( V_11 & V_12 )
V_7 -> V_13 = * V_13 ;
if ( V_11 & V_14 )
V_7 -> V_17 = * V_17 ;
if ( V_11 & V_18 )
V_7 -> V_19 = * V_19 ;
if ( V_11 & V_20 )
V_7 -> V_22 = * V_22 ;
V_7 -> V_23 = V_36 -> V_51 ;
F_17 ( & V_7 -> V_8 ) ;
if ( V_38 == V_49 )
F_18 ( V_31 , * V_4 ) ;
return V_38 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_29 , int V_52 )
{
unsigned char * V_53 = F_20 ( V_2 ) ;
struct F_1 * V_7 = F_2 ( V_4 ) ;
struct V_35 V_54 = {
. V_47 = V_7 -> V_55 ,
. V_56 = V_7 -> V_57 - V_52 ,
. V_58 = V_7 -> V_59 - V_29 ,
. V_51 = V_7 -> V_23 ,
} ;
struct V_60 V_61 ;
if ( F_21 ( V_2 , V_42 , sizeof( V_54 ) , & V_54 ) )
goto V_62;
if ( ( V_7 -> V_11 & V_12 ) &&
F_22 ( V_2 , V_43 , V_7 -> V_13 ) )
goto V_62;
if ( ( V_7 -> V_11 & V_14 ) &&
F_23 ( V_2 , V_44 , V_7 -> V_17 ) )
goto V_62;
if ( ( V_7 -> V_11 & V_18 ) &&
F_22 ( V_2 , V_46 , V_7 -> V_19 ) )
goto V_62;
if ( ( V_7 -> V_11 & V_20 ) &&
F_23 ( V_2 , V_45 , V_7 -> V_22 ) )
goto V_62;
F_24 ( & V_61 , & V_7 -> V_9 ) ;
if ( F_25 ( V_2 , V_63 , sizeof( V_61 ) , & V_61 , V_64 ) )
goto V_62;
return V_2 -> V_65 ;
V_62:
F_26 ( V_2 , V_53 ) ;
return - 1 ;
}
static int F_27 ( struct V_24 * V_24 , struct V_1 * V_2 ,
struct V_66 * V_67 , int type ,
const struct V_68 * V_69 )
{
struct V_30 * V_31 = F_9 ( V_24 , V_32 ) ;
return F_28 ( V_31 , V_2 , V_67 , type , V_69 ) ;
}
static int F_29 ( struct V_24 * V_24 , struct V_3 * * V_4 , T_1 V_47 )
{
struct V_30 * V_31 = F_9 ( V_24 , V_32 ) ;
return F_30 ( V_31 , V_4 , V_47 ) ;
}
static T_3 int F_31 ( struct V_24 * V_24 )
{
struct V_30 * V_31 = F_9 ( V_24 , V_32 ) ;
return F_32 ( V_31 , & V_48 , V_70 ) ;
}
static void T_4 F_33 ( struct V_24 * V_24 )
{
struct V_30 * V_31 = F_9 ( V_24 , V_32 ) ;
F_34 ( V_31 ) ;
}
static int T_5 F_35 ( void )
{
return F_36 ( & V_48 , & V_71 ) ;
}
static void T_6 F_37 ( void )
{
F_38 ( & V_48 , & V_71 ) ;
}
