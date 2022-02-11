static bool F_1 ( T_1 V_1 , T_1 V_2 )
{
struct V_3 * V_4 , * V_5 ;
bool V_6 ;
if ( V_1 + V_2 < V_1 )
return false ;
V_4 = F_2 ( L_1 ) ;
if ( ! V_4 )
return false ;
V_6 = false ;
F_3 (parent, node) {
T_1 V_7 , V_8 , V_9 ;
const T_2 * V_10 ;
const char * V_11 ;
V_10 = F_4 ( V_5 , 0 , & V_8 , NULL ) ;
V_7 = F_5 ( V_10 , 2 ) ;
V_9 = V_7 + V_8 ;
V_11 = F_6 ( V_5 , L_2 , NULL ) ;
if ( ! V_11 )
continue;
if ( V_9 <= V_7 )
continue;
if ( V_1 >= V_7 && V_1 + V_2 <= V_9 ) {
V_6 = true ;
F_7 ( V_5 ) ;
break;
}
}
F_7 ( V_4 ) ;
return V_6 ;
}
static int F_8 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
if ( F_9 ( & V_14 , 1 ) == 1 )
return - V_15 ;
return 0 ;
}
static int F_10 ( struct V_13 * V_13 , struct V_16 * V_17 )
{
T_3 V_1 , V_2 ;
T_4 V_18 ;
int V_19 ;
F_11 ( L_3 ,
V_17 -> V_20 , V_17 -> V_21 , V_17 -> V_22 ,
V_17 -> V_23 ) ;
V_1 = V_17 -> V_22 << V_24 ;
V_2 = V_17 -> V_21 - V_17 -> V_20 ;
if ( ! F_1 ( V_1 , V_2 ) )
return - V_25 ;
V_18 = F_12 ( V_13 , V_17 -> V_22 ,
V_2 , V_17 -> V_26 ) ;
V_19 = F_13 ( V_17 , V_17 -> V_20 , V_17 -> V_22 , V_2 ,
V_18 ) ;
return V_19 ;
}
static bool F_14 ( void )
{
unsigned long V_27 ;
bool V_28 ;
F_15 ( & V_29 , V_27 ) ;
V_28 = F_16 ( & V_30 ) ;
F_17 ( & V_29 , V_27 ) ;
return V_28 ;
}
static unsigned int F_18 ( struct V_13 * V_13 ,
struct V_31 * V_32 )
{
F_19 ( V_13 , & V_33 , V_32 ) ;
if ( ! F_14 () )
return V_34 | V_35 ;
return 0 ;
}
static T_5 F_20 ( struct V_13 * V_13 , char T_6 * V_36 ,
T_3 V_37 , T_7 * V_38 )
{
struct V_39 * V_40 ;
unsigned long V_27 ;
T_5 V_2 , V_41 ;
int V_19 ;
if ( V_37 < sizeof( V_40 -> V_42 ) )
return - V_25 ;
if ( * V_38 )
return - V_43 ;
V_40 = NULL ;
for (; ; ) {
F_15 ( & V_29 , V_27 ) ;
if ( ! F_16 ( & V_30 ) ) {
V_40 = F_21 ( & V_30 ,
struct V_39 , V_44 ) ;
F_22 ( & V_40 -> V_44 ) ;
}
F_17 ( & V_29 , V_27 ) ;
if ( V_40 )
break;
if ( V_13 -> V_45 & V_46 )
return - V_47 ;
V_19 = F_23 ( V_33 ,
! F_14 () ) ;
if ( V_19 )
return - V_48 ;
}
V_2 = F_24 ( V_40 -> V_42 . V_2 ) ;
if ( V_2 > V_37 ) {
V_41 = - V_25 ;
goto V_49;
}
V_19 = F_25 ( V_36 , & V_40 -> V_42 , V_2 ) ;
if ( V_19 ) {
V_41 = - V_50 ;
goto V_49;
}
F_26 ( V_40 ) ;
return V_2 ;
V_49:
F_15 ( & V_29 , V_27 ) ;
F_27 ( & V_40 -> V_44 , & V_30 ) ;
F_17 ( & V_29 , V_27 ) ;
return V_41 ;
}
static T_5 F_28 ( struct V_13 * V_13 , const char T_6 * V_36 ,
T_3 V_37 , T_7 * V_38 )
{
struct V_51 V_52 ;
T_5 V_2 ;
void * V_42 ;
int V_19 ;
V_2 = sizeof( V_52 ) ;
if ( V_37 < V_2 )
return - V_25 ;
V_19 = F_29 ( & V_52 , V_36 , sizeof( V_52 ) ) ;
if ( V_19 )
return - V_50 ;
V_2 = F_24 ( V_52 . V_2 ) ;
V_42 = F_30 ( V_2 , V_53 ) ;
if ( ! V_42 )
return - V_54 ;
V_19 = F_29 ( V_42 , V_36 , V_2 ) ;
if ( V_19 ) {
V_2 = - V_50 ;
goto V_55;
}
V_19 = F_31 ( V_42 ) ;
if ( V_19 ) {
F_32 ( L_4 , V_19 ) ;
V_2 = - V_56 ;
}
V_55:
F_26 ( V_42 ) ;
return V_2 ;
}
static int F_33 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
struct V_51 V_42 ;
V_42 . V_2 = F_34 ( sizeof( V_42 ) ) ;
V_42 . type = V_57 ;
F_31 ( (struct F_31 * ) & V_42 ) ;
F_9 ( & V_14 , 0 ) ;
return 0 ;
}
static long F_35 ( struct V_13 * V_13 , unsigned int V_58 ,
unsigned long V_59 )
{
struct V_60 V_61 ;
struct V_62 V_63 ;
int V_19 = 0 ;
switch ( V_58 ) {
case V_64 :
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_61 . V_65 = V_66 ;
V_19 = F_25 ( ( void T_6 * ) V_59 , & V_61 , sizeof( V_61 ) ) ;
if ( V_19 )
return - V_50 ;
break;
case V_67 :
V_19 = F_29 ( & V_63 , ( void T_6 * ) V_59 , sizeof( V_63 ) ) ;
if ( V_19 )
return - V_50 ;
V_63 . V_19 = F_36 ( V_63 . V_68 , V_63 . V_1 ,
( V_69 * ) & V_63 . V_70 ) ;
V_63 . V_70 = F_37 ( V_63 . V_70 ) ;
F_11 ( L_5 ,
V_63 . V_68 , V_63 . V_1 , V_63 . V_70 , V_63 . V_19 ) ;
V_19 = F_25 ( ( void T_6 * ) V_59 , & V_63 , sizeof( V_63 ) ) ;
if ( V_19 )
return - V_50 ;
break;
case V_71 :
V_19 = F_29 ( & V_63 , ( void T_6 * ) V_59 , sizeof( V_63 ) ) ;
if ( V_19 )
return - V_50 ;
V_63 . V_19 = F_38 ( V_63 . V_68 , V_63 . V_1 , V_63 . V_70 ) ;
F_11 ( L_6 ,
V_63 . V_68 , V_63 . V_1 , V_63 . V_70 , V_63 . V_19 ) ;
V_19 = F_25 ( ( void T_6 * ) V_59 , & V_63 , sizeof( V_63 ) ) ;
if ( V_19 )
return - V_50 ;
break;
default:
V_19 = - V_25 ;
}
return V_19 ;
}
static int F_39 ( struct V_72 * V_73 ,
unsigned long V_74 , void * V_75 )
{
struct V_39 * V_40 ;
struct V_51 * V_52 ;
struct V_76 * V_42 = V_75 ;
int V_77 , V_78 ;
unsigned long V_27 ;
if ( V_74 != V_79 )
return 0 ;
V_52 = ( void * ) V_42 -> V_80 ;
V_77 = F_24 ( V_52 -> V_2 ) ;
V_78 = V_77 + sizeof( * V_40 ) - sizeof( V_40 -> V_42 ) ;
V_40 = F_40 ( V_78 , V_81 ) ;
if ( ! V_40 )
return - V_54 ;
memcpy ( & V_40 -> V_42 , V_42 -> V_80 , V_77 ) ;
F_15 ( & V_29 , V_27 ) ;
F_41 ( & V_40 -> V_44 , & V_30 ) ;
F_17 ( & V_29 , V_27 ) ;
F_42 ( & V_33 ) ;
return 0 ;
}
static int F_43 ( struct V_82 * V_83 )
{
int V_19 ;
if ( ! V_83 || ! V_83 -> V_84 . V_85 )
return - V_86 ;
if ( V_87 )
return - V_15 ;
V_87 = V_83 -> V_84 . V_85 ;
V_19 = F_44 ( V_79 , & V_88 ) ;
if ( V_19 ) {
F_45 ( L_7 ) ;
return V_19 ;
}
V_19 = F_46 ( & V_89 ) ;
if ( V_19 ) {
F_45 ( L_8 ) ;
F_47 ( V_79 ,
& V_88 ) ;
return V_19 ;
}
return 0 ;
}
static int F_48 ( struct V_82 * V_83 )
{
F_49 ( & V_89 ) ;
F_47 ( V_79 , & V_88 ) ;
return 0 ;
}
