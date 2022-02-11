static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( & V_5 -> V_6 ) ;
if ( V_5 -> V_7 ) {
F_4 ( V_5 -> V_7 ) ;
V_5 -> V_7 = NULL ;
}
F_5 ( & V_5 -> V_6 ) ;
F_6 ( & V_5 -> V_8 ) ;
F_7 ( & V_5 -> V_2 ) ;
F_8 ( & V_5 -> V_2 ) ;
return 0 ;
}
static int F_9 ( struct V_9 * V_10 , void * V_11 , int V_12 ,
void * V_13 , T_1 V_14 )
{
struct V_4 * V_5 = V_13 ;
struct V_15 * V_16 ;
V_16 = F_10 ( V_12 , V_17 ) ;
if ( ! V_16 )
return - V_18 ;
F_11 ( V_16 , V_11 , V_12 ) ;
F_12 ( & V_5 -> V_19 ) ;
F_13 ( & V_5 -> V_20 , V_16 ) ;
F_14 ( & V_5 -> V_19 ) ;
F_6 ( & V_5 -> V_8 ) ;
return 0 ;
}
static int F_15 ( struct V_21 * V_21 , struct V_22 * V_23 )
{
struct V_4 * V_5 = F_16 ( V_21 -> V_24 ) ;
struct V_25 * V_7 ;
struct V_9 * V_10 = V_5 -> V_10 ;
struct V_1 * V_2 = & V_5 -> V_2 ;
F_17 ( V_2 ) ;
V_7 = F_18 ( V_10 , F_9 , V_5 , V_5 -> V_26 ) ;
if ( ! V_7 ) {
F_19 ( V_2 , L_1 , V_5 -> V_26 . V_27 ) ;
F_8 ( V_2 ) ;
return - V_28 ;
}
V_5 -> V_7 = V_7 ;
V_23 -> V_29 = V_5 ;
return 0 ;
}
static int F_20 ( struct V_21 * V_21 , struct V_22 * V_23 )
{
struct V_4 * V_5 = F_16 ( V_21 -> V_24 ) ;
struct V_1 * V_2 = & V_5 -> V_2 ;
struct V_15 * V_16 ;
F_3 ( & V_5 -> V_6 ) ;
if ( V_5 -> V_7 ) {
F_4 ( V_5 -> V_7 ) ;
V_5 -> V_7 = NULL ;
}
F_5 ( & V_5 -> V_6 ) ;
while ( ! F_21 ( & V_5 -> V_20 ) ) {
V_16 = F_22 ( & V_5 -> V_20 ) ;
F_23 ( V_16 ) ;
}
F_8 ( V_2 ) ;
return 0 ;
}
static T_2 F_24 ( struct V_22 * V_23 , char T_3 * V_11 ,
T_4 V_12 , T_5 * V_30 )
{
struct V_4 * V_5 = V_23 -> V_29 ;
unsigned long V_31 ;
struct V_15 * V_16 ;
int V_32 ;
if ( ! V_5 -> V_7 )
return - V_33 ;
F_25 ( & V_5 -> V_19 , V_31 ) ;
if ( F_21 ( & V_5 -> V_20 ) ) {
F_26 ( & V_5 -> V_19 , V_31 ) ;
if ( V_23 -> V_34 & V_35 )
return - V_36 ;
if ( F_27 ( V_5 -> V_8 ,
! F_21 ( & V_5 -> V_20 ) ||
! V_5 -> V_7 ) )
return - V_37 ;
if ( ! V_5 -> V_7 )
return - V_33 ;
F_25 ( & V_5 -> V_19 , V_31 ) ;
}
V_16 = F_22 ( & V_5 -> V_20 ) ;
F_26 ( & V_5 -> V_19 , V_31 ) ;
if ( ! V_16 )
return - V_38 ;
V_32 = F_28 ( T_4 , V_12 , V_16 -> V_12 ) ;
if ( F_29 ( V_11 , V_16 -> V_3 , V_32 ) )
V_32 = - V_38 ;
F_23 ( V_16 ) ;
return V_32 ;
}
static T_2 F_30 ( struct V_22 * V_23 , const char T_3 * V_11 ,
T_4 V_12 , T_5 * V_30 )
{
struct V_4 * V_5 = V_23 -> V_29 ;
void * V_39 ;
int V_40 ;
V_39 = F_31 ( V_11 , V_12 ) ;
if ( F_32 ( V_39 ) )
return F_33 ( V_39 ) ;
if ( F_34 ( & V_5 -> V_6 ) ) {
V_40 = - V_37 ;
goto V_41;
}
if ( ! V_5 -> V_7 ) {
V_40 = - V_33 ;
goto V_42;
}
if ( V_23 -> V_34 & V_35 )
V_40 = F_35 ( V_5 -> V_7 , V_39 , V_12 ) ;
else
V_40 = F_36 ( V_5 -> V_7 , V_39 , V_12 ) ;
V_42:
F_5 ( & V_5 -> V_6 ) ;
V_41:
F_37 ( V_39 ) ;
return V_40 < 0 ? V_40 : V_12 ;
}
static unsigned int F_38 ( struct V_22 * V_23 , T_6 * V_43 )
{
struct V_4 * V_5 = V_23 -> V_29 ;
unsigned int V_44 = 0 ;
if ( ! V_5 -> V_7 )
return V_45 ;
F_39 ( V_23 , & V_5 -> V_8 , V_43 ) ;
if ( ! F_21 ( & V_5 -> V_20 ) )
V_44 |= V_46 | V_47 ;
V_44 |= F_40 ( V_5 -> V_7 , V_23 , V_43 ) ;
return V_44 ;
}
static long F_41 ( struct V_22 * V_48 , unsigned int V_49 ,
unsigned long V_50 )
{
struct V_4 * V_5 = V_48 -> V_29 ;
if ( V_49 != V_51 )
return - V_28 ;
return F_1 ( & V_5 -> V_2 , NULL ) ;
}
static T_2 F_42 ( struct V_1 * V_2 , struct V_52 * V_53 ,
char * V_11 )
{
struct V_4 * V_5 = F_43 ( V_2 ) ;
return sprintf ( V_11 , L_2 , V_5 -> V_26 . V_27 ) ;
}
static T_2 F_44 ( struct V_1 * V_2 , struct V_52 * V_53 ,
char * V_11 )
{
struct V_4 * V_5 = F_43 ( V_2 ) ;
return sprintf ( V_11 , L_3 , V_5 -> V_26 . V_54 ) ;
}
static T_2 F_45 ( struct V_1 * V_2 , struct V_52 * V_53 ,
char * V_11 )
{
struct V_4 * V_5 = F_43 ( V_2 ) ;
return sprintf ( V_11 , L_3 , V_5 -> V_26 . V_55 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_47 ( & V_56 , V_2 -> V_57 ) ;
F_47 ( & V_58 , F_48 ( V_5 -> V_2 . V_59 ) ) ;
F_49 ( & V_5 -> V_60 ) ;
F_37 ( V_5 ) ;
}
static int F_50 ( struct V_61 * V_62 ,
struct V_63 V_26 )
{
struct V_9 * V_10 = V_62 -> V_10 ;
struct V_4 * V_5 ;
struct V_1 * V_2 ;
int V_40 ;
V_5 = F_51 ( sizeof( * V_5 ) , V_64 ) ;
if ( ! V_5 )
return - V_18 ;
V_2 = & V_5 -> V_2 ;
V_5 -> V_10 = V_10 ;
V_5 -> V_26 = V_26 ;
F_52 ( & V_5 -> V_6 ) ;
F_53 ( & V_5 -> V_19 ) ;
F_54 ( & V_5 -> V_20 ) ;
F_55 ( & V_5 -> V_8 ) ;
F_56 ( V_2 ) ;
V_2 -> V_65 = V_66 ;
V_2 -> V_67 = & V_62 -> V_2 ;
V_2 -> V_68 = V_69 ;
F_57 ( V_2 , V_5 ) ;
F_58 ( & V_5 -> V_60 , & V_70 ) ;
V_5 -> V_60 . V_71 = V_72 ;
V_40 = F_59 ( & V_58 , 0 , V_73 , V_64 ) ;
if ( V_40 < 0 )
goto V_74;
V_2 -> V_59 = F_60 ( F_61 ( V_75 ) , V_40 ) ;
V_40 = F_59 ( & V_56 , 0 , 0 , V_64 ) ;
if ( V_40 < 0 )
goto V_76;
V_2 -> V_57 = V_40 ;
F_62 ( V_2 , L_4 , V_40 ) ;
V_40 = F_63 ( & V_5 -> V_60 , V_2 -> V_59 , 1 ) ;
if ( V_40 )
goto V_77;
V_2 -> V_78 = F_46 ;
V_40 = F_64 ( V_2 ) ;
if ( V_40 ) {
F_19 ( V_2 , L_5 , V_40 ) ;
F_8 ( V_2 ) ;
}
return V_40 ;
V_77:
F_47 ( & V_56 , V_2 -> V_57 ) ;
V_76:
F_47 ( & V_58 , F_48 ( V_2 -> V_59 ) ) ;
V_74:
F_8 ( V_2 ) ;
F_37 ( V_5 ) ;
return V_40 ;
}
static int F_65 ( struct V_21 * V_21 , struct V_22 * V_23 )
{
struct V_61 * V_62 = F_66 ( V_21 -> V_24 ) ;
F_17 ( & V_62 -> V_2 ) ;
V_23 -> V_29 = V_62 ;
return 0 ;
}
static int F_67 ( struct V_21 * V_21 , struct V_22 * V_23 )
{
struct V_61 * V_62 = F_66 ( V_21 -> V_24 ) ;
F_8 ( & V_62 -> V_2 ) ;
return 0 ;
}
static long F_68 ( struct V_22 * V_48 , unsigned int V_49 ,
unsigned long V_50 )
{
struct V_61 * V_62 = V_48 -> V_29 ;
void T_3 * V_79 = ( void T_3 * ) V_50 ;
struct V_80 V_81 ;
struct V_63 V_26 ;
if ( V_49 != V_82 )
return - V_28 ;
if ( F_69 ( & V_81 , V_79 , sizeof( V_81 ) ) )
return - V_38 ;
memcpy ( V_26 . V_27 , V_81 . V_27 , V_83 ) ;
V_26 . V_27 [ V_83 - 1 ] = '\0' ;
V_26 . V_54 = V_81 . V_54 ;
V_26 . V_55 = V_81 . V_55 ;
return F_50 ( V_62 , V_26 ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = F_71 ( V_2 ) ;
F_47 ( & V_84 , V_2 -> V_57 ) ;
F_47 ( & V_58 , F_48 ( V_2 -> V_59 ) ) ;
F_49 ( & V_62 -> V_60 ) ;
F_37 ( V_62 ) ;
}
static int F_72 ( struct V_9 * V_10 )
{
struct V_61 * V_62 ;
struct V_1 * V_2 ;
int V_40 ;
V_62 = F_51 ( sizeof( * V_62 ) , V_64 ) ;
if ( ! V_62 )
return - V_18 ;
V_62 -> V_10 = V_10 ;
V_2 = & V_62 -> V_2 ;
F_56 ( V_2 ) ;
V_2 -> V_67 = & V_10 -> V_2 ;
V_2 -> V_65 = V_66 ;
F_58 ( & V_62 -> V_60 , & V_85 ) ;
V_62 -> V_60 . V_71 = V_72 ;
V_40 = F_59 ( & V_58 , 0 , V_73 , V_64 ) ;
if ( V_40 < 0 )
goto V_86;
V_2 -> V_59 = F_60 ( F_61 ( V_75 ) , V_40 ) ;
V_40 = F_59 ( & V_84 , 0 , 0 , V_64 ) ;
if ( V_40 < 0 )
goto V_76;
V_2 -> V_57 = V_40 ;
F_62 ( & V_62 -> V_2 , L_6 , V_40 ) ;
V_40 = F_63 ( & V_62 -> V_60 , V_2 -> V_59 , 1 ) ;
if ( V_40 )
goto V_87;
V_2 -> V_78 = F_70 ;
V_40 = F_64 ( V_2 ) ;
if ( V_40 ) {
F_19 ( & V_10 -> V_2 , L_5 , V_40 ) ;
F_8 ( V_2 ) ;
}
F_57 ( & V_10 -> V_2 , V_62 ) ;
return V_40 ;
V_87:
F_47 ( & V_84 , V_2 -> V_57 ) ;
V_76:
F_47 ( & V_58 , F_48 ( V_2 -> V_59 ) ) ;
V_86:
F_8 ( V_2 ) ;
F_37 ( V_62 ) ;
return V_40 ;
}
static void F_73 ( struct V_9 * V_10 )
{
struct V_61 * V_62 = F_43 ( & V_10 -> V_2 ) ;
int V_40 ;
V_40 = F_74 ( & V_62 -> V_2 , NULL , F_1 ) ;
if ( V_40 )
F_75 ( & V_10 -> V_2 , L_7 , V_40 ) ;
F_7 ( & V_62 -> V_2 ) ;
F_8 ( & V_62 -> V_2 ) ;
}
static int F_76 ( void )
{
int V_40 ;
V_40 = F_77 ( & V_75 , 0 , V_73 , L_8 ) ;
if ( V_40 < 0 ) {
F_78 ( L_9 ) ;
return V_40 ;
}
V_66 = F_79 ( V_72 , L_8 ) ;
if ( F_32 ( V_66 ) ) {
F_78 ( L_10 ) ;
F_80 ( V_75 , V_73 ) ;
return F_33 ( V_66 ) ;
}
V_40 = F_81 ( & V_88 ) ;
if ( V_40 < 0 ) {
F_78 ( L_11 ) ;
F_82 ( V_66 ) ;
F_80 ( V_75 , V_73 ) ;
}
return V_40 ;
}
static void F_83 ( void )
{
F_84 ( & V_88 ) ;
F_82 ( V_66 ) ;
F_80 ( V_75 , V_73 ) ;
}
