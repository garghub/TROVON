static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 V_8 ;
int V_9 ;
V_9 =
F_3 ( V_2 , V_4 ,
& V_8 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_4 ( V_6 , & V_8 ) ;
if ( V_9 )
return V_9 ;
F_5 ( V_2 , & V_2 -> V_10 ) ;
return 0 ;
}
static bool F_6 ( struct V_5 * V_6 , void * V_11 )
{
struct V_12 * V_13 = V_11 ;
bool V_14 = false ;
char * V_15 ;
V_15 = F_7 ( V_16 , L_1 , V_13 -> V_17 -> V_18 ,
V_13 -> V_19 ) ;
if ( ( strcmp ( F_8 ( V_6 -> V_20 -> V_21 ) , V_15 ) == 0 ) &&
( V_6 -> V_22 == V_13 -> V_17 -> V_23 ) ) {
V_14 = true ;
}
F_9 ( V_15 ) ;
return V_14 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_26 ;
struct V_27 * V_28 = F_11 ( V_25 -> V_29 -> V_21 ) ;
struct V_30 * V_31 = V_25 -> V_31 ;
struct V_12 V_13 ;
struct V_32 * V_33 ;
V_33 = F_12 ( V_28 , V_34 , V_2 -> V_35 ) ;
if ( ! V_33 )
return - V_36 ;
F_13 ( V_2 ,
& V_37 [ V_2 -> V_35 ] ) ;
V_13 . V_17 = V_33 ;
V_13 . V_19 = V_31 -> V_38 ;
return F_14 ( V_2 , F_6 ,
& V_13 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = V_2 -> V_42 ;
unsigned long V_43 = V_40 -> V_44 ;
V_40 -> V_45 = F_16 ( V_40 -> V_45 ) ;
return F_17 ( V_40 , V_40 -> V_46 ,
F_18 ( V_42 -> V_47 ) + V_43 ,
V_40 -> V_48 - V_40 -> V_46 , V_40 -> V_45 ) ;
}
static void F_19 ( struct V_49 * V_50 )
{
struct V_1 * V_2 ;
struct V_51 * V_52 ;
int V_35 ;
struct V_53 * V_54 ;
V_54 = F_20 ( L_2 ) ;
if ( ! V_54 )
return;
for ( V_35 = 0 ; V_35 < 2 ; V_35 ++ ) {
T_1 V_55 = V_37 [ V_35 ] . V_56 ;
V_2 = V_50 -> V_57 [ V_35 ] . V_2 ;
if ( ! V_2 )
continue;
V_52 = & V_2 -> V_10 ;
if ( ! V_52 -> V_58 )
continue;
F_21 ( V_54 , ( unsigned long ) V_52 -> V_58 , V_55 ) ;
V_52 -> V_58 = NULL ;
}
return;
}
static int F_22 ( struct V_1 * V_2 ,
int V_35 )
{
struct V_51 * V_52 = & V_2 -> V_10 ;
T_1 V_55 = V_37 [ V_35 ] . V_56 ;
struct V_53 * V_54 ;
V_52 -> V_21 . type = V_59 ;
V_52 -> V_21 . V_21 = V_2 -> V_50 -> V_60 -> V_21 ;
V_52 -> V_26 = NULL ;
V_54 = F_20 ( L_2 ) ;
if ( ! V_54 )
return - V_61 ;
V_52 -> V_58 = F_23 ( V_54 , V_55 , & V_52 -> V_62 ) ;
if ( ! V_52 -> V_58 )
return - V_61 ;
V_52 -> V_63 = V_55 ;
return 0 ;
}
static int F_24 ( struct V_24 * V_25 )
{
struct V_1 * V_2 ;
struct V_49 * V_50 = V_25 -> V_50 ;
int V_9 = 0 , V_35 ;
for ( V_35 = 0 ; V_35 < 2 ; V_35 ++ ) {
V_2 = V_50 -> V_57 [ V_35 ] . V_2 ;
V_9 = F_22 ( V_2 , V_35 ) ;
if ( V_9 )
goto V_64;
}
return 0 ;
V_64:
F_19 ( V_50 ) ;
return V_9 ;
}
static int F_25 ( struct V_27 * V_28 )
{
struct V_65 * V_66 = V_28 -> V_21 . V_67 ;
if ( V_66 ) {
V_37 [ V_68 ] . V_56 =
V_66 -> V_69 ;
V_37 [ V_68 ] . V_70 =
V_66 -> V_71 ;
V_37 [ V_72 ] . V_56 =
V_66 -> V_73 ;
V_37 [ V_72 ] . V_70 =
V_66 -> V_74 ;
}
return F_26 ( & V_28 -> V_21 , & V_75 ) ;
}
