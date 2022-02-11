static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
V_4 = F_2 ( F_3 ( V_2 ) ) ;
V_6 = V_4 -> V_6 ;
V_7 = F_4 ( V_6 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_5 ( V_6 , ( V_8 ) ( unsigned long ) V_6 ) ;
if ( ! V_7 )
V_4 -> V_9 = V_10 ;
return V_7 ;
}
static int F_6 ( struct V_11 * V_12 ,
unsigned long V_13 ,
void * V_14 )
{
struct V_3 * V_4 =
F_7 ( V_12 , struct V_3 , V_12 ) ;
if ( V_13 == V_15 ) {
struct V_16 * V_17 = V_14 ;
if ( ! F_8 ( & V_4 -> V_18 , V_17 -> V_19 ) )
return V_20 ;
if ( F_1 ( V_4 -> V_2 ) )
return V_21 ;
F_9 ( & V_4 -> V_18 ) ;
return V_20 ;
}
return V_22 ;
}
static T_1 F_10 ( struct V_23 * V_24 , struct V_25 * V_26 , char * V_27 )
{
return sprintf ( V_27 , L_1 ) ;
}
static T_1 F_11 ( struct V_23 * V_24 , struct V_25 * V_26 ,
char * V_27 )
{
return sprintf ( V_27 , L_2 , V_28 ) ;
}
static T_1 F_12 ( struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_27 )
{
struct V_3 * V_4 = F_2 ( V_26 ) ;
return sprintf ( V_27 , L_3 , F_13 ( & V_4 -> V_29 ) ) ;
}
static int F_14 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( F_3 ( V_2 ) ) ;
if ( V_4 -> V_9 == V_30 )
return - V_31 ;
if ( F_15 ( & V_4 -> V_29 ) < 0 )
return - V_32 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_9 = V_10 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( F_3 ( V_2 ) ) ;
if ( ( V_4 -> V_9 != V_30 ) &&
( V_4 -> V_9 != V_33 ) ) {
if ( ! F_1 ( V_2 ) )
V_4 -> V_9 = V_33 ;
}
V_4 -> V_2 = NULL ;
F_17 ( & V_4 -> V_29 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( F_3 ( V_2 ) ) ;
unsigned long V_34 = V_15 ;
V_4 -> V_12 . V_35 = F_6 ;
return F_19 ( F_20 ( V_2 ) , V_36 ,
& V_34 , & V_4 -> V_12 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( F_3 ( V_2 ) ) ;
F_22 ( F_20 ( V_2 ) , V_36 ,
& V_4 -> V_12 ) ;
}
static T_1 F_23 ( struct V_1 * V_2 ,
char T_2 * V_27 ,
T_3 V_37 ,
T_4 * V_38 )
{
struct V_3 * V_4 ;
struct V_39 * V_40 ;
if ( * V_38 + V_37 > sizeof( * V_40 ) )
return - V_41 ;
V_4 = F_2 ( F_3 ( V_2 ) ) ;
V_40 = & V_4 -> V_42 ;
if ( F_24 ( V_27 , ( void * ) V_40 + * V_38 , V_37 ) )
return - V_43 ;
return V_37 ;
}
static T_1 F_25 ( struct V_1 * V_2 ,
const char T_2 * V_27 ,
T_3 V_37 ,
T_4 * V_38 )
{
struct V_3 * V_4 ;
struct V_39 * V_40 ;
if ( * V_38 + V_37 > sizeof( * V_40 ) )
return - V_41 ;
V_4 = F_2 ( F_3 ( V_2 ) ) ;
if ( V_4 -> V_9 != V_10 )
return - V_44 ;
V_40 = & V_4 -> V_42 ;
if ( F_26 ( ( void * ) V_40 + * V_38 , V_27 , V_37 ) )
return - V_43 ;
F_27 ( V_4 , V_45 ) ;
if ( V_40 -> V_46 != 0 ) {
V_4 -> V_9 = V_10 ;
return V_40 -> V_46 ;
}
return V_37 ;
}
static int F_28 ( struct V_47 * V_48 )
{
V_48 -> V_49 = V_50 | V_51 ;
V_48 -> V_52 = V_53 ;
V_48 -> V_54 = V_55 ;
return 0 ;
}
static int F_29 ( struct V_56 * V_48 ,
T_5 * V_57 ,
void * * V_58 )
{
switch ( V_48 -> V_59 ) {
case V_60 :
V_48 -> V_61 = 0 ;
V_48 -> V_62 = sizeof( struct V_39 ) ;
V_48 -> V_49 = V_63
| V_64 ;
return 0 ;
default:
return - V_41 ;
}
}
static int F_30 ( struct V_65 * V_48 )
{
if ( V_48 -> V_59 != V_66 )
return - V_41 ;
V_48 -> V_37 = 1 ;
V_48 -> V_49 = V_67 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
T_6 V_49 ,
void T_2 * V_14 )
{
struct V_3 * V_4 ;
struct V_68 * * V_69 ;
if ( ! ( V_49 & V_70 ) )
return - V_41 ;
V_4 = F_2 ( F_3 ( V_2 ) ) ;
V_69 = & V_4 -> V_71 ;
switch ( V_49 & V_72 ) {
case V_73 :
{
if ( * V_69 )
F_32 ( * V_69 , 1 ) ;
return 0 ;
}
case V_74 :
{
T_7 V_75 ;
if ( F_33 ( V_75 , ( T_7 T_2 * ) V_14 ) )
return - V_43 ;
if ( V_75 && * V_69 )
F_32 ( * V_69 , 1 ) ;
return 0 ;
}
case V_76 :
{
T_8 V_77 ;
if ( F_33 ( V_77 , ( T_8 T_2 * ) V_14 ) )
return - V_43 ;
if ( V_77 == - 1 ) {
if ( * V_69 )
F_34 ( * V_69 ) ;
* V_69 = NULL ;
} else if ( V_77 >= 0 ) {
struct V_68 * V_78 ;
V_78 = F_35 ( V_77 ) ;
if ( F_36 ( V_78 ) )
return F_37 ( V_78 ) ;
if ( * V_69 )
F_34 ( * V_69 ) ;
* V_69 = V_78 ;
} else
return - V_41 ;
return 0 ;
}
default:
return - V_41 ;
}
}
static T_1 F_38 ( struct V_1 * V_2 ,
unsigned int V_79 ,
unsigned long V_80 )
{
int V_7 = 0 ;
unsigned long V_81 ;
switch ( V_79 ) {
case V_82 :
{
struct V_47 V_48 ;
V_81 = F_39 ( struct V_47 , V_54 ) ;
if ( F_26 ( & V_48 , ( void T_2 * ) V_80 , V_81 ) )
return - V_43 ;
if ( V_48 . V_83 < V_81 )
return - V_41 ;
V_7 = F_28 ( & V_48 ) ;
if ( V_7 )
return V_7 ;
return F_24 ( ( void T_2 * ) V_80 , & V_48 , V_81 ) ;
}
case V_84 :
{
struct V_56 V_48 ;
T_5 V_57 = 0 ;
void * V_58 = NULL ;
V_81 = F_39 ( struct V_56 , V_61 ) ;
if ( F_26 ( & V_48 , ( void T_2 * ) V_80 , V_81 ) )
return - V_43 ;
if ( V_48 . V_83 < V_81 )
return - V_41 ;
V_7 = F_29 ( & V_48 , & V_57 ,
& V_58 ) ;
if ( V_7 )
return V_7 ;
return F_24 ( ( void T_2 * ) V_80 , & V_48 , V_81 ) ;
}
case V_85 :
{
struct V_65 V_48 ;
V_81 = F_39 ( struct V_65 , V_37 ) ;
if ( F_26 ( & V_48 , ( void T_2 * ) V_80 , V_81 ) )
return - V_43 ;
if ( V_48 . V_83 < V_81 || V_48 . V_59 >= V_55 )
return - V_41 ;
V_7 = F_30 ( & V_48 ) ;
if ( V_7 )
return V_7 ;
if ( V_48 . V_37 == - 1 )
return - V_41 ;
return F_24 ( ( void T_2 * ) V_80 , & V_48 , V_81 ) ;
}
case V_86 :
{
struct V_87 V_88 ;
T_3 V_89 ;
void T_2 * V_14 ;
V_81 = F_39 ( struct V_87 , V_37 ) ;
if ( F_26 ( & V_88 , ( void T_2 * ) V_80 , V_81 ) )
return - V_43 ;
V_7 = F_40 ( & V_88 , 1 ,
V_55 ,
& V_89 ) ;
if ( V_7 )
return V_7 ;
V_14 = ( void T_2 * ) ( V_80 + V_81 ) ;
return F_31 ( V_2 , V_88 . V_49 , V_14 ) ;
}
case V_90 :
return F_1 ( V_2 ) ;
default:
return - V_91 ;
}
}
int F_41 ( struct V_5 * V_6 )
{
return F_42 ( & V_6 -> V_26 , & V_92 ) ;
}
void F_43 ( struct V_5 * V_6 )
{
F_44 ( & V_6 -> V_26 ) ;
}
