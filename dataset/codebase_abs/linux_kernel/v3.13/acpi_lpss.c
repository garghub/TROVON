static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
T_1 V_4 ;
V_3 = V_2 -> V_5 -> V_6 + V_7 ;
V_4 = F_2 ( V_2 -> V_8 + V_3 ) ;
F_3 ( V_4 | V_9 , V_2 -> V_8 + V_3 ) ;
V_3 = V_2 -> V_5 -> V_6 + V_10 ;
V_4 = F_2 ( V_2 -> V_8 + V_3 ) ;
F_3 ( V_4 | V_11 , V_2 -> V_8 + V_3 ) ;
}
static int F_4 ( struct V_12 * V_13 , void * V_14 )
{
struct V_15 V_16 ;
return ! F_5 ( V_13 , & V_16 ) ;
}
static inline void F_6 ( void )
{
V_17 = F_7 ( L_1 , - 1 , NULL , 0 ) ;
}
static int F_8 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
const struct V_20 * V_5 = V_2 -> V_5 ;
struct V_21 * V_22 = V_5 -> V_22 ;
struct V_23 * V_23 = F_9 ( - V_24 ) ;
struct V_25 * V_26 ;
const char * V_27 ;
if ( ! V_17 )
F_6 () ;
V_26 = F_10 ( V_17 ) ;
if ( ! V_26 )
return - V_24 ;
if ( V_5 -> V_28 ) {
F_11 ( V_26 -> V_23 , V_5 -> V_28 ,
F_12 ( & V_19 -> V_29 ) ) ;
return 0 ;
}
if ( ! V_2 -> V_8
|| V_2 -> V_30 < V_5 -> V_6 + V_31 )
return - V_32 ;
V_27 = V_26 -> V_33 ;
if ( V_22 ) {
V_23 = V_22 -> V_23 ;
if ( ! V_23 ) {
V_23 = F_13 ( NULL , V_22 -> V_33 ,
L_2 , 0 ,
V_22 -> V_34 ) ;
V_22 -> V_23 = V_23 ;
}
V_27 = V_22 -> V_33 ;
}
if ( V_5 -> V_35 ) {
V_23 = F_14 ( NULL , F_12 ( & V_19 -> V_29 ) , V_27 , 0 ,
V_2 -> V_8 + V_5 -> V_6 ,
0 , 0 , NULL ) ;
V_2 -> V_23 = V_23 ;
}
if ( F_15 ( V_23 ) )
return F_16 ( V_23 ) ;
F_11 ( V_23 , NULL , F_12 ( & V_19 -> V_29 ) ) ;
return 0 ;
}
static int F_17 ( struct V_18 * V_19 ,
const struct V_36 * V_37 )
{
struct V_20 * V_5 ;
struct V_1 * V_2 ;
struct V_38 * V_39 ;
struct V_40 V_41 ;
int V_42 ;
V_5 = (struct V_20 * ) V_37 -> V_43 ;
if ( ! V_5 )
return F_18 ( V_19 , V_37 ) ;
V_2 = F_19 ( sizeof( * V_2 ) , V_44 ) ;
if ( ! V_2 )
return - V_45 ;
F_20 ( & V_41 ) ;
V_42 = F_21 ( V_19 , & V_41 , F_4 , NULL ) ;
if ( V_42 < 0 )
goto V_46;
F_22 (rentry, &resource_list, node)
if ( F_23 ( & V_39 -> V_13 ) == V_47 ) {
if ( V_5 -> V_48 )
V_2 -> V_30 = V_5 -> V_48 ;
else
V_2 -> V_30 = F_24 ( & V_39 -> V_13 ) ;
V_2 -> V_8 = F_25 ( V_39 -> V_13 . V_49 ,
V_2 -> V_30 ) ;
break;
}
F_26 ( & V_41 ) ;
V_2 -> V_5 = V_5 ;
if ( V_5 -> V_50 ) {
V_42 = F_8 ( V_19 , V_2 ) ;
if ( V_42 ) {
V_42 = 0 ;
goto V_46;
}
}
V_42 = F_27 ( V_19 ) ;
if ( V_42 ) {
V_42 = 0 ;
goto V_46;
}
if ( V_5 -> V_51 )
V_5 -> V_51 ( V_2 ) ;
V_19 -> V_43 = V_2 ;
V_42 = F_18 ( V_19 , V_37 ) ;
if ( V_42 > 0 )
return V_42 ;
V_19 -> V_43 = NULL ;
V_46:
F_28 ( V_2 ) ;
return V_42 ;
}
static int F_29 ( struct V_52 * V_29 , unsigned int V_4 , T_1 * V_53 )
{
struct V_18 * V_19 ;
struct V_1 * V_2 ;
unsigned long V_54 ;
int V_42 ;
V_42 = F_30 ( F_31 ( V_29 ) , & V_19 ) ;
if ( F_32 ( V_42 ) )
return V_42 ;
F_33 ( & V_29 -> V_55 . V_56 , V_54 ) ;
if ( F_34 ( V_29 ) ) {
V_42 = - V_57 ;
goto V_58;
}
V_2 = F_35 ( V_19 ) ;
if ( F_32 ( ! V_2 || ! V_2 -> V_8 ) ) {
V_42 = - V_24 ;
goto V_58;
}
* V_53 = F_2 ( V_2 -> V_8 + V_2 -> V_5 -> V_6 + V_4 ) ;
V_58:
F_36 ( & V_29 -> V_55 . V_56 , V_54 ) ;
return V_42 ;
}
static T_2 F_37 ( struct V_52 * V_29 , struct V_59 * V_60 ,
char * V_61 )
{
T_1 V_62 = 0 ;
unsigned int V_4 ;
int V_42 ;
V_4 = strcmp ( V_60 -> V_60 . V_33 , L_3 ) ? V_63 : V_64 ;
V_42 = F_29 ( V_29 , V_4 , & V_62 ) ;
if ( V_42 )
return V_42 ;
return snprintf ( V_61 , V_65 , L_4 , V_62 ) ;
}
static T_2 F_38 ( struct V_52 * V_29 ,
struct V_59 * V_60 , char * V_61 )
{
T_1 V_66 = 0 ;
char * V_67 ;
int V_42 ;
V_42 = F_29 ( V_29 , V_10 , & V_66 ) ;
if ( V_42 )
return V_42 ;
V_67 = ( V_66 & V_68 ) ? L_5 : L_6 ;
return sprintf ( V_61 , L_7 , V_67 ) ;
}
static int F_39 ( struct V_69 * V_70 ,
unsigned long V_71 , void * V_72 )
{
struct V_73 * V_74 = F_40 ( V_72 ) ;
struct V_1 * V_2 ;
struct V_18 * V_19 ;
const struct V_36 * V_37 ;
int V_42 = 0 ;
V_37 = F_41 ( V_75 , & V_74 -> V_29 ) ;
if ( ! V_37 || ! V_37 -> V_43 )
return 0 ;
if ( F_30 ( F_31 ( & V_74 -> V_29 ) , & V_19 ) )
return 0 ;
V_2 = F_35 ( V_19 ) ;
if ( ! V_2 || ! V_2 -> V_8 || ! V_2 -> V_5 -> V_76 )
return 0 ;
if ( V_2 -> V_30 < V_2 -> V_5 -> V_6 + V_77 ) {
F_42 ( & V_74 -> V_29 , L_8 ) ;
return 0 ;
}
if ( V_71 == V_78 )
V_42 = F_43 ( & V_74 -> V_29 . V_79 , & V_80 ) ;
else if ( V_71 == V_81 )
F_44 ( & V_74 -> V_29 . V_79 , & V_80 ) ;
return V_42 ;
}
void T_3 F_45 ( void )
{
if ( ! F_46 () ) {
F_47 ( & V_82 , & V_83 ) ;
F_48 ( & V_84 ) ;
}
}
