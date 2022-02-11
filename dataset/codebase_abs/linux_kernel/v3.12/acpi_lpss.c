static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_4 -> V_5 + V_6 ;
T_1 V_7 ;
V_7 = F_2 ( V_2 -> V_8 + V_3 ) ;
F_3 ( V_7 | V_9 , V_2 -> V_8 + V_3 ) ;
}
static int F_4 ( struct V_10 * V_11 , void * V_12 )
{
struct V_13 V_14 ;
return ! F_5 ( V_11 , & V_14 ) ;
}
static inline void F_6 ( void )
{
V_15 = F_7 ( L_1 , - 1 , NULL , 0 ) ;
}
static int F_8 ( struct V_16 * V_17 ,
struct V_1 * V_2 )
{
const struct V_18 * V_4 = V_2 -> V_4 ;
struct V_19 * V_20 = V_4 -> V_20 ;
struct V_21 * V_21 = F_9 ( - V_22 ) ;
struct V_23 * V_24 ;
const char * V_25 ;
if ( ! V_15 )
F_6 () ;
V_24 = F_10 ( V_15 ) ;
if ( ! V_24 )
return - V_22 ;
if ( V_4 -> V_26 ) {
F_11 ( V_24 -> V_21 , V_4 -> V_26 ,
F_12 ( & V_17 -> V_27 ) ) ;
return 0 ;
}
if ( ! V_2 -> V_8
|| V_2 -> V_28 < V_4 -> V_5 + V_29 )
return - V_30 ;
V_25 = V_24 -> V_31 ;
if ( V_20 ) {
V_21 = V_20 -> V_21 ;
if ( ! V_21 ) {
V_21 = F_13 ( NULL , V_20 -> V_31 ,
L_2 , 0 ,
V_20 -> V_32 ) ;
V_20 -> V_21 = V_21 ;
}
V_25 = V_20 -> V_31 ;
}
if ( V_4 -> V_33 ) {
V_21 = F_14 ( NULL , F_12 ( & V_17 -> V_27 ) , V_25 , 0 ,
V_2 -> V_8 + V_4 -> V_5 ,
0 , 0 , NULL ) ;
V_2 -> V_21 = V_21 ;
}
if ( F_15 ( V_21 ) )
return F_16 ( V_21 ) ;
F_11 ( V_21 , NULL , F_12 ( & V_17 -> V_27 ) ) ;
return 0 ;
}
static int F_17 ( struct V_16 * V_17 ,
const struct V_34 * V_35 )
{
struct V_18 * V_4 ;
struct V_1 * V_2 ;
struct V_36 * V_37 ;
struct V_38 V_39 ;
int V_40 ;
V_4 = (struct V_18 * ) V_35 -> V_41 ;
if ( ! V_4 )
return F_18 ( V_17 , V_35 ) ;
V_2 = F_19 ( sizeof( * V_2 ) , V_42 ) ;
if ( ! V_2 )
return - V_43 ;
F_20 ( & V_39 ) ;
V_40 = F_21 ( V_17 , & V_39 , F_4 , NULL ) ;
if ( V_40 < 0 )
goto V_44;
F_22 (rentry, &resource_list, node)
if ( F_23 ( & V_37 -> V_11 ) == V_45 ) {
if ( V_4 -> V_46 )
V_2 -> V_28 = V_4 -> V_46 ;
else
V_2 -> V_28 = F_24 ( & V_37 -> V_11 ) ;
V_2 -> V_8 = F_25 ( V_37 -> V_11 . V_47 ,
V_2 -> V_28 ) ;
break;
}
F_26 ( & V_39 ) ;
V_2 -> V_4 = V_4 ;
if ( V_4 -> V_48 ) {
V_40 = F_8 ( V_17 , V_2 ) ;
if ( V_40 ) {
V_40 = 0 ;
goto V_44;
}
}
V_40 = F_27 ( V_17 ) ;
if ( V_40 ) {
V_40 = 0 ;
goto V_44;
}
if ( V_4 -> V_49 )
V_4 -> V_49 ( V_2 ) ;
V_17 -> V_41 = V_2 ;
V_40 = F_18 ( V_17 , V_35 ) ;
if ( V_40 > 0 )
return V_40 ;
V_17 -> V_41 = NULL ;
V_44:
F_28 ( V_2 ) ;
return V_40 ;
}
static int F_29 ( struct V_50 * V_27 , unsigned int V_7 , T_1 * V_51 )
{
struct V_16 * V_17 ;
struct V_1 * V_2 ;
unsigned long V_52 ;
int V_40 ;
V_40 = F_30 ( F_31 ( V_27 ) , & V_17 ) ;
if ( F_32 ( V_40 ) )
return V_40 ;
F_33 ( & V_27 -> V_53 . V_54 , V_52 ) ;
if ( F_34 ( V_27 ) ) {
V_40 = - V_55 ;
goto V_56;
}
V_2 = F_35 ( V_17 ) ;
if ( F_32 ( ! V_2 || ! V_2 -> V_8 ) ) {
V_40 = - V_22 ;
goto V_56;
}
* V_51 = F_2 ( V_2 -> V_8 + V_2 -> V_4 -> V_5 + V_7 ) ;
V_56:
F_36 ( & V_27 -> V_53 . V_54 , V_52 ) ;
return V_40 ;
}
static T_2 F_37 ( struct V_50 * V_27 , struct V_57 * V_58 ,
char * V_59 )
{
T_1 V_60 = 0 ;
unsigned int V_7 ;
int V_40 ;
V_7 = strcmp ( V_58 -> V_58 . V_31 , L_3 ) ? V_61 : V_62 ;
V_40 = F_29 ( V_27 , V_7 , & V_60 ) ;
if ( V_40 )
return V_40 ;
return snprintf ( V_59 , V_63 , L_4 , V_60 ) ;
}
static T_2 F_38 ( struct V_50 * V_27 ,
struct V_57 * V_58 , char * V_59 )
{
T_1 V_64 = 0 ;
char * V_65 ;
int V_40 ;
V_40 = F_29 ( V_27 , V_66 , & V_64 ) ;
if ( V_40 )
return V_40 ;
V_65 = ( V_64 & V_67 ) ? L_5 : L_6 ;
return sprintf ( V_59 , L_7 , V_65 ) ;
}
static int F_39 ( struct V_68 * V_69 ,
unsigned long V_70 , void * V_71 )
{
struct V_72 * V_73 = F_40 ( V_71 ) ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
const struct V_34 * V_35 ;
int V_40 = 0 ;
V_35 = F_41 ( V_74 , & V_73 -> V_27 ) ;
if ( ! V_35 || ! V_35 -> V_41 )
return 0 ;
if ( F_30 ( F_31 ( & V_73 -> V_27 ) , & V_17 ) )
return 0 ;
V_2 = F_35 ( V_17 ) ;
if ( ! V_2 || ! V_2 -> V_8 || ! V_2 -> V_4 -> V_75 )
return 0 ;
if ( V_2 -> V_28 < V_2 -> V_4 -> V_5 + V_76 ) {
F_42 ( & V_73 -> V_27 , L_8 ) ;
return 0 ;
}
if ( V_70 == V_77 )
V_40 = F_43 ( & V_73 -> V_27 . V_78 , & V_79 ) ;
else if ( V_70 == V_80 )
F_44 ( & V_73 -> V_27 . V_78 , & V_79 ) ;
return V_40 ;
}
void T_3 F_45 ( void )
{
if ( ! F_46 () ) {
F_47 ( & V_81 , & V_82 ) ;
F_48 ( & V_83 ) ;
}
}
