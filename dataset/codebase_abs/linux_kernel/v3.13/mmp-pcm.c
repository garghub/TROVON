static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 ;
struct V_12 V_13 ;
int V_14 ;
V_11 = F_3 ( V_8 -> V_15 , V_2 ) ;
if ( ! V_11 )
return 0 ;
V_14 = F_4 ( V_2 , V_4 , & V_13 ) ;
if ( V_14 )
return V_14 ;
if ( V_2 -> V_16 == V_17 ) {
V_13 . V_18 = V_11 -> V_19 ;
V_13 . V_20 = 4 ;
} else {
V_13 . V_21 = V_11 -> V_19 ;
V_13 . V_22 = 4 ;
}
V_14 = F_5 ( V_6 , & V_13 ) ;
if ( V_14 )
return V_14 ;
F_6 ( V_2 , & V_2 -> V_23 ) ;
return 0 ;
}
static bool F_7 ( struct V_5 * V_6 , void * V_24 )
{
struct V_25 * V_26 = V_24 ;
bool V_27 = false ;
char * V_28 ;
V_28 = F_8 ( V_29 , L_1 , V_26 -> V_30 -> V_31 ,
V_26 -> V_32 ) ;
if ( ( strcmp ( F_9 ( V_6 -> V_33 -> V_34 ) , V_28 ) == 0 ) &&
( V_6 -> V_35 == V_26 -> V_30 -> V_36 ) ) {
V_27 = true ;
}
F_10 ( V_28 ) ;
return V_27 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_37 * V_38 = F_12 ( V_8 -> V_39 -> V_34 ) ;
struct V_40 * V_15 = V_8 -> V_15 ;
struct V_25 V_26 ;
struct V_41 * V_42 ;
V_42 = F_13 ( V_38 , V_43 , V_2 -> V_16 ) ;
if ( ! V_42 )
return - V_44 ;
F_14 ( V_2 ,
& V_45 [ V_2 -> V_16 ] ) ;
V_26 . V_30 = V_42 ;
V_26 . V_32 = V_15 -> V_46 ;
return F_15 ( V_2 , F_7 ,
& V_26 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_49 * V_50 = V_2 -> V_50 ;
unsigned long V_51 = V_48 -> V_52 ;
V_48 -> V_53 = F_17 ( V_48 -> V_53 ) ;
return F_18 ( V_48 , V_48 -> V_54 ,
F_19 ( V_50 -> V_55 ) + V_51 ,
V_48 -> V_56 - V_48 -> V_54 , V_48 -> V_53 ) ;
}
static void F_20 ( struct V_57 * V_58 )
{
struct V_1 * V_2 ;
struct V_59 * V_60 ;
int V_16 ;
struct V_61 * V_62 ;
V_62 = F_21 ( L_2 ) ;
if ( ! V_62 )
return;
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ ) {
T_1 V_63 = V_45 [ V_16 ] . V_64 ;
V_2 = V_58 -> V_65 [ V_16 ] . V_2 ;
if ( ! V_2 )
continue;
V_60 = & V_2 -> V_23 ;
if ( ! V_60 -> V_66 )
continue;
F_22 ( V_62 , ( unsigned long ) V_60 -> V_66 , V_63 ) ;
V_60 -> V_66 = NULL ;
}
return;
}
static int F_23 ( struct V_1 * V_2 ,
int V_16 )
{
struct V_59 * V_60 = & V_2 -> V_23 ;
T_1 V_63 = V_45 [ V_16 ] . V_64 ;
struct V_61 * V_62 ;
V_60 -> V_34 . type = V_67 ;
V_60 -> V_34 . V_34 = V_2 -> V_58 -> V_68 -> V_34 ;
V_60 -> V_9 = NULL ;
V_62 = F_21 ( L_2 ) ;
if ( ! V_62 )
return - V_69 ;
V_60 -> V_66 = F_24 ( V_62 , V_63 , & V_60 -> V_19 ) ;
if ( ! V_60 -> V_66 )
return - V_69 ;
V_60 -> V_70 = V_63 ;
return 0 ;
}
static int F_25 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
struct V_57 * V_58 = V_8 -> V_58 ;
int V_14 = 0 , V_16 ;
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ ) {
V_2 = V_58 -> V_65 [ V_16 ] . V_2 ;
V_14 = F_23 ( V_2 , V_16 ) ;
if ( V_14 )
goto V_71;
}
return 0 ;
V_71:
F_20 ( V_58 ) ;
return V_14 ;
}
static int F_26 ( struct V_37 * V_38 )
{
struct V_72 * V_73 = V_38 -> V_34 . V_74 ;
if ( V_73 ) {
V_45 [ V_17 ] . V_64 =
V_73 -> V_75 ;
V_45 [ V_17 ] . V_76 =
V_73 -> V_77 ;
V_45 [ V_78 ] . V_64 =
V_73 -> V_79 ;
V_45 [ V_78 ] . V_76 =
V_73 -> V_80 ;
}
return F_27 ( & V_38 -> V_34 , & V_81 ) ;
}
static int F_28 ( struct V_37 * V_38 )
{
F_29 ( & V_38 -> V_34 ) ;
return 0 ;
}
