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
struct V_25 * V_26 ;
struct V_41 * V_42 ;
int V_14 ;
V_42 = F_13 ( V_38 , V_43 , V_2 -> V_16 ) ;
if ( ! V_42 )
return - V_44 ;
F_14 ( V_2 ,
& V_45 [ V_2 -> V_16 ] ) ;
V_26 = F_15 ( & V_38 -> V_34 ,
sizeof( struct V_25 ) , V_29 ) ;
if ( V_26 == NULL )
return - V_46 ;
V_26 -> V_30 = V_42 ;
V_26 -> V_32 = V_15 -> V_47 ;
V_14 = F_16 ( V_2 , F_7 , V_26 ) ;
if ( V_14 ) {
F_17 ( & V_38 -> V_34 , V_26 ) ;
return V_14 ;
}
F_18 ( V_2 , V_26 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_20 ( V_2 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_37 * V_38 = F_12 ( V_8 -> V_39 -> V_34 ) ;
F_21 ( V_2 ) ;
F_17 ( & V_38 -> V_34 , V_26 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_48 * V_49 )
{
struct V_50 * V_51 = V_2 -> V_51 ;
unsigned long V_52 = V_49 -> V_53 ;
V_49 -> V_54 = F_23 ( V_49 -> V_54 ) ;
return F_24 ( V_49 , V_49 -> V_55 ,
F_25 ( V_51 -> V_56 ) + V_52 ,
V_49 -> V_57 - V_49 -> V_55 , V_49 -> V_54 ) ;
}
static void F_26 ( struct V_58 * V_59 )
{
struct V_1 * V_2 ;
struct V_60 * V_61 ;
int V_16 ;
struct V_62 * V_63 ;
V_63 = F_27 ( L_2 ) ;
if ( ! V_63 )
return;
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ ) {
T_1 V_64 = V_45 [ V_16 ] . V_65 ;
V_2 = V_59 -> V_66 [ V_16 ] . V_2 ;
if ( ! V_2 )
continue;
V_61 = & V_2 -> V_23 ;
if ( ! V_61 -> V_67 )
continue;
F_28 ( V_63 , ( unsigned long ) V_61 -> V_67 , V_64 ) ;
V_61 -> V_67 = NULL ;
}
return;
}
static int F_29 ( struct V_1 * V_2 ,
int V_16 )
{
struct V_60 * V_61 = & V_2 -> V_23 ;
T_1 V_64 = V_45 [ V_16 ] . V_65 ;
struct V_62 * V_63 ;
V_61 -> V_34 . type = V_68 ;
V_61 -> V_34 . V_34 = V_2 -> V_59 -> V_69 -> V_34 ;
V_61 -> V_9 = NULL ;
V_63 = F_27 ( L_2 ) ;
if ( ! V_63 )
return - V_46 ;
V_61 -> V_67 = ( unsigned char * ) F_30 ( V_63 , V_64 ) ;
if ( ! V_61 -> V_67 )
return - V_46 ;
V_61 -> V_70 = F_31 ( V_63 , ( unsigned long ) V_61 -> V_67 ) ;
V_61 -> V_71 = V_64 ;
return 0 ;
}
int F_32 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
struct V_58 * V_59 = V_8 -> V_59 ;
int V_14 = 0 , V_16 ;
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ ) {
V_2 = V_59 -> V_66 [ V_16 ] . V_2 ;
V_14 = F_29 ( V_2 , V_16 ) ;
if ( V_14 )
goto V_72;
}
return 0 ;
V_72:
F_26 ( V_59 ) ;
return V_14 ;
}
static int F_33 ( struct V_37 * V_38 )
{
struct V_73 * V_74 = V_38 -> V_34 . V_75 ;
if ( V_74 ) {
V_45 [ V_17 ] . V_65 =
V_74 -> V_76 ;
V_45 [ V_17 ] . V_77 =
V_74 -> V_78 ;
V_45 [ V_79 ] . V_65 =
V_74 -> V_80 ;
V_45 [ V_79 ] . V_77 =
V_74 -> V_81 ;
}
return F_34 ( & V_38 -> V_34 , & V_82 ) ;
}
static int F_35 ( struct V_37 * V_38 )
{
F_36 ( & V_38 -> V_34 ) ;
return 0 ;
}
