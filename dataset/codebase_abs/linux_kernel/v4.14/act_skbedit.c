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
if ( V_7 -> V_11 & V_18 ) {
V_2 -> V_19 &= ~ V_7 -> V_20 ;
V_2 -> V_19 |= V_7 -> V_19 & V_7 -> V_20 ;
}
if ( V_7 -> V_11 & V_21 )
V_2 -> V_22 = V_7 -> V_23 ;
F_7 ( & V_7 -> V_8 ) ;
return V_7 -> V_24 ;
}
static int F_8 ( struct V_25 * V_25 , struct V_26 * V_27 ,
struct V_26 * V_28 , struct V_3 * * V_4 ,
int V_29 , int V_30 )
{
struct V_31 * V_32 = F_9 ( V_25 , V_33 ) ;
struct V_26 * V_34 [ V_35 + 1 ] ;
struct V_36 * V_37 ;
struct F_1 * V_7 ;
T_1 V_11 = 0 , * V_13 = NULL , * V_19 = NULL , * V_20 = NULL ;
T_2 * V_17 = NULL , * V_23 = NULL ;
bool V_38 = false ;
int V_39 = 0 , V_40 ;
if ( V_27 == NULL )
return - V_41 ;
V_40 = F_10 ( V_34 , V_35 , V_27 , V_42 , NULL ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_34 [ V_43 ] == NULL )
return - V_41 ;
if ( V_34 [ V_44 ] != NULL ) {
V_11 |= V_12 ;
V_13 = F_11 ( V_34 [ V_44 ] ) ;
}
if ( V_34 [ V_45 ] != NULL ) {
V_11 |= V_14 ;
V_17 = F_11 ( V_34 [ V_45 ] ) ;
}
if ( V_34 [ V_46 ] != NULL ) {
V_23 = F_11 ( V_34 [ V_46 ] ) ;
if ( ! F_12 ( * V_23 ) )
return - V_41 ;
V_11 |= V_21 ;
}
if ( V_34 [ V_47 ] != NULL ) {
V_11 |= V_18 ;
V_19 = F_11 ( V_34 [ V_47 ] ) ;
}
if ( V_34 [ V_48 ] != NULL ) {
V_11 |= V_49 ;
V_20 = F_11 ( V_34 [ V_48 ] ) ;
}
V_37 = F_11 ( V_34 [ V_43 ] ) ;
V_38 = F_13 ( V_32 , V_37 -> V_50 , V_4 , V_30 ) ;
if ( V_38 && V_30 )
return 0 ;
if ( ! V_11 ) {
F_14 ( * V_4 , V_30 ) ;
return - V_41 ;
}
if ( ! V_38 ) {
V_39 = F_15 ( V_32 , V_37 -> V_50 , V_28 , V_4 ,
& V_51 , V_30 , false ) ;
if ( V_39 )
return V_39 ;
V_7 = F_2 ( * V_4 ) ;
V_39 = V_52 ;
} else {
V_7 = F_2 ( * V_4 ) ;
F_14 ( * V_4 , V_30 ) ;
if ( ! V_29 )
return - V_53 ;
}
F_16 ( & V_7 -> V_8 ) ;
V_7 -> V_11 = V_11 ;
if ( V_11 & V_12 )
V_7 -> V_13 = * V_13 ;
if ( V_11 & V_14 )
V_7 -> V_17 = * V_17 ;
if ( V_11 & V_18 )
V_7 -> V_19 = * V_19 ;
if ( V_11 & V_21 )
V_7 -> V_23 = * V_23 ;
V_7 -> V_20 = 0xffffffff ;
if ( V_11 & V_49 )
V_7 -> V_20 = * V_20 ;
V_7 -> V_24 = V_37 -> V_54 ;
F_17 ( & V_7 -> V_8 ) ;
if ( V_39 == V_52 )
F_18 ( V_32 , * V_4 ) ;
return V_39 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_30 , int V_55 )
{
unsigned char * V_56 = F_20 ( V_2 ) ;
struct F_1 * V_7 = F_2 ( V_4 ) ;
struct V_36 V_57 = {
. V_50 = V_7 -> V_58 ,
. V_59 = V_7 -> V_60 - V_55 ,
. V_61 = V_7 -> V_62 - V_30 ,
. V_54 = V_7 -> V_24 ,
} ;
struct V_63 V_64 ;
if ( F_21 ( V_2 , V_43 , sizeof( V_57 ) , & V_57 ) )
goto V_65;
if ( ( V_7 -> V_11 & V_12 ) &&
F_22 ( V_2 , V_44 , V_7 -> V_13 ) )
goto V_65;
if ( ( V_7 -> V_11 & V_14 ) &&
F_23 ( V_2 , V_45 , V_7 -> V_17 ) )
goto V_65;
if ( ( V_7 -> V_11 & V_18 ) &&
F_22 ( V_2 , V_47 , V_7 -> V_19 ) )
goto V_65;
if ( ( V_7 -> V_11 & V_21 ) &&
F_23 ( V_2 , V_46 , V_7 -> V_23 ) )
goto V_65;
if ( ( V_7 -> V_11 & V_49 ) &&
F_22 ( V_2 , V_48 , V_7 -> V_20 ) )
goto V_65;
F_24 ( & V_64 , & V_7 -> V_9 ) ;
if ( F_25 ( V_2 , V_66 , sizeof( V_64 ) , & V_64 , V_67 ) )
goto V_65;
return V_2 -> V_68 ;
V_65:
F_26 ( V_2 , V_56 ) ;
return - 1 ;
}
static int F_27 ( struct V_25 * V_25 , struct V_1 * V_2 ,
struct V_69 * V_70 , int type ,
const struct V_71 * V_72 )
{
struct V_31 * V_32 = F_9 ( V_25 , V_33 ) ;
return F_28 ( V_32 , V_2 , V_70 , type , V_72 ) ;
}
static int F_29 ( struct V_25 * V_25 , struct V_3 * * V_4 , T_1 V_50 )
{
struct V_31 * V_32 = F_9 ( V_25 , V_33 ) ;
return F_30 ( V_32 , V_4 , V_50 ) ;
}
static T_3 int F_31 ( struct V_25 * V_25 )
{
struct V_31 * V_32 = F_9 ( V_25 , V_33 ) ;
return F_32 ( V_32 , & V_51 ) ;
}
static void T_4 F_33 ( struct V_25 * V_25 )
{
struct V_31 * V_32 = F_9 ( V_25 , V_33 ) ;
F_34 ( V_32 ) ;
}
static int T_5 F_35 ( void )
{
return F_36 ( & V_51 , & V_73 ) ;
}
static void T_6 F_37 ( void )
{
F_38 ( & V_51 , & V_73 ) ;
}
