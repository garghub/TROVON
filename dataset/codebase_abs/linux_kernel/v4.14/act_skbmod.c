static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
int V_9 ;
struct V_10 * V_11 ;
T_1 V_12 ;
int V_13 ;
F_3 ( & V_8 -> V_14 ) ;
F_4 ( F_5 ( V_8 -> V_15 . V_16 ) , V_2 ) ;
V_13 = F_6 ( V_2 , V_17 ) ;
if ( F_7 ( V_13 ) ) {
F_8 ( F_5 ( V_8 -> V_15 . V_18 ) ) ;
return V_19 ;
}
F_9 () ;
V_9 = F_10 ( V_8 -> V_20 ) ;
if ( F_7 ( V_9 == V_19 ) ) {
F_8 ( F_5 ( V_8 -> V_15 . V_18 ) ) ;
F_11 () ;
return V_9 ;
}
V_11 = F_12 ( V_8 -> V_21 ) ;
V_12 = V_11 -> V_12 ;
if ( V_12 & V_22 )
F_13 ( F_14 ( V_2 ) -> V_23 , V_11 -> V_24 ) ;
if ( V_12 & V_25 )
F_13 ( F_14 ( V_2 ) -> V_26 , V_11 -> V_27 ) ;
if ( V_12 & V_28 )
F_14 ( V_2 ) -> V_29 = V_11 -> V_30 ;
F_11 () ;
if ( V_12 & V_31 ) {
T_2 V_32 [ V_33 / 2 ] ;
F_13 ( ( V_34 * ) V_32 , F_14 ( V_2 ) -> V_23 ) ;
F_13 ( F_14 ( V_2 ) -> V_23 , F_14 ( V_2 ) -> V_26 ) ;
F_13 ( F_14 ( V_2 ) -> V_26 , ( V_34 * ) V_32 ) ;
}
return V_9 ;
}
static int F_15 ( struct V_35 * V_35 , struct V_36 * V_37 ,
struct V_36 * V_38 , struct V_3 * * V_4 ,
int V_39 , int V_40 )
{
struct V_41 * V_42 = F_16 ( V_35 , V_43 ) ;
struct V_36 * V_44 [ V_45 + 1 ] ;
struct V_10 * V_11 , * V_46 ;
struct V_47 * V_48 ;
struct V_7 * V_8 ;
bool V_49 = false ;
V_34 * V_50 = NULL ;
V_34 * V_51 = NULL ;
T_2 V_30 = 0 ;
T_3 V_52 = 0 ;
int V_53 = 0 , V_13 ;
if ( ! V_37 )
return - V_54 ;
V_13 = F_17 ( V_44 , V_45 , V_37 , V_55 , NULL ) ;
if ( V_13 < 0 )
return V_13 ;
if ( ! V_44 [ V_56 ] )
return - V_54 ;
if ( V_44 [ V_57 ] ) {
V_50 = F_18 ( V_44 [ V_57 ] ) ;
V_52 |= V_22 ;
}
if ( V_44 [ V_58 ] ) {
V_51 = F_18 ( V_44 [ V_58 ] ) ;
V_52 |= V_25 ;
}
if ( V_44 [ V_59 ] ) {
V_30 = F_19 ( V_44 [ V_59 ] ) ;
V_52 |= V_28 ;
}
V_48 = F_18 ( V_44 [ V_56 ] ) ;
if ( V_48 -> V_12 & V_31 )
V_52 = V_31 ;
V_49 = F_20 ( V_42 , V_48 -> V_60 , V_4 , V_40 ) ;
if ( V_49 && V_40 )
return 0 ;
if ( ! V_52 )
return - V_54 ;
if ( ! V_49 ) {
V_53 = F_21 ( V_42 , V_48 -> V_60 , V_38 , V_4 ,
& V_61 , V_40 , true ) ;
if ( V_53 )
return V_53 ;
V_53 = V_62 ;
} else {
F_22 ( * V_4 , V_40 ) ;
if ( ! V_39 )
return - V_63 ;
}
V_8 = F_2 ( * V_4 ) ;
F_23 () ;
V_11 = F_24 ( sizeof( struct V_10 ) , V_64 ) ;
if ( F_7 ( ! V_11 ) ) {
if ( V_39 )
F_22 ( * V_4 , V_40 ) ;
return - V_65 ;
}
V_11 -> V_12 = V_52 ;
V_8 -> V_20 = V_48 -> V_9 ;
V_46 = F_25 ( V_8 -> V_21 ) ;
if ( V_39 )
F_26 ( & V_8 -> V_66 ) ;
if ( V_52 & V_22 )
F_13 ( V_11 -> V_24 , V_50 ) ;
if ( V_52 & V_25 )
F_13 ( V_11 -> V_27 , V_51 ) ;
if ( V_52 & V_28 )
V_11 -> V_30 = F_27 ( V_30 ) ;
F_28 ( V_8 -> V_21 , V_11 ) ;
if ( V_39 )
F_29 ( & V_8 -> V_66 ) ;
if ( V_46 )
F_30 ( V_46 , V_67 ) ;
if ( V_53 == V_62 )
F_31 ( V_42 , * V_4 ) ;
return V_53 ;
}
static void F_32 ( struct V_3 * V_4 , int V_40 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_10 * V_11 ;
V_11 = F_33 ( V_8 -> V_21 , 1 ) ;
F_30 ( V_11 , V_67 ) ;
}
static int F_34 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_40 , int V_68 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
unsigned char * V_69 = F_35 ( V_2 ) ;
struct V_10 * V_11 = F_25 ( V_8 -> V_21 ) ;
struct V_47 V_70 = {
. V_60 = V_8 -> V_71 ,
. V_72 = V_8 -> V_73 - V_68 ,
. V_74 = V_8 -> V_75 - V_40 ,
. V_9 = V_8 -> V_20 ,
} ;
struct V_76 V_77 ;
V_70 . V_12 = V_11 -> V_12 ;
if ( F_36 ( V_2 , V_56 , sizeof( V_70 ) , & V_70 ) )
goto V_78;
if ( ( V_11 -> V_12 & V_22 ) &&
F_36 ( V_2 , V_57 , V_33 , V_11 -> V_24 ) )
goto V_78;
if ( ( V_11 -> V_12 & V_25 ) &&
F_36 ( V_2 , V_58 , V_33 , V_11 -> V_27 ) )
goto V_78;
if ( ( V_11 -> V_12 & V_28 ) &&
F_37 ( V_2 , V_59 , F_38 ( V_11 -> V_30 ) ) )
goto V_78;
F_39 ( & V_77 , & V_8 -> V_14 ) ;
if ( F_40 ( V_2 , V_79 , sizeof( V_77 ) , & V_77 , V_80 ) )
goto V_78;
return V_2 -> V_81 ;
V_78:
F_41 ( V_2 , V_69 ) ;
return - 1 ;
}
static int F_42 ( struct V_35 * V_35 , struct V_1 * V_2 ,
struct V_82 * V_83 , int type ,
const struct V_84 * V_85 )
{
struct V_41 * V_42 = F_16 ( V_35 , V_43 ) ;
return F_43 ( V_42 , V_2 , V_83 , type , V_85 ) ;
}
static int F_44 ( struct V_35 * V_35 , struct V_3 * * V_4 , T_3 V_60 )
{
struct V_41 * V_42 = F_16 ( V_35 , V_43 ) ;
return F_45 ( V_42 , V_4 , V_60 ) ;
}
static T_4 int F_46 ( struct V_35 * V_35 )
{
struct V_41 * V_42 = F_16 ( V_35 , V_43 ) ;
return F_47 ( V_42 , & V_61 ) ;
}
static void T_5 F_48 ( struct V_35 * V_35 )
{
struct V_41 * V_42 = F_16 ( V_35 , V_43 ) ;
F_49 ( V_42 ) ;
}
static int T_6 F_50 ( void )
{
return F_51 ( & V_61 , & V_86 ) ;
}
static void T_7 F_52 ( void )
{
F_53 ( & V_61 , & V_86 ) ;
}
