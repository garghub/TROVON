static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 V_5 ;
return ! F_2 ( V_2 , & V_5 ) ;
}
static inline void F_3 ( void )
{
V_6 = F_4 ( L_1 , - 1 , NULL , 0 ) ;
}
static int F_5 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
const struct V_11 * V_12 = V_10 -> V_12 ;
struct V_13 * V_14 ;
if ( ! V_6 )
F_3 () ;
V_14 = F_6 ( V_6 ) ;
if ( ! V_14 )
return - V_15 ;
if ( V_12 -> V_16 ) {
F_7 ( V_14 -> V_17 , V_12 -> V_16 ,
F_8 ( & V_8 -> V_18 ) ) ;
return 0 ;
}
if ( ! V_10 -> V_19
|| V_10 -> V_20 < V_12 -> V_21 + V_22 )
return - V_23 ;
V_10 -> V_17 = F_9 ( NULL , F_8 ( & V_8 -> V_18 ) ,
V_14 -> V_24 , 0 ,
V_10 -> V_19 + V_12 -> V_21 ,
0 , 0 , NULL ) ;
if ( F_10 ( V_10 -> V_17 ) )
return F_11 ( V_10 -> V_17 ) ;
F_7 ( V_10 -> V_17 , NULL , F_8 ( & V_8 -> V_18 ) ) ;
return 0 ;
}
static int F_12 ( struct V_7 * V_8 ,
const struct V_25 * V_26 )
{
struct V_11 * V_12 ;
struct V_9 * V_10 ;
struct V_27 * V_28 ;
struct V_29 V_30 ;
int V_31 ;
V_12 = (struct V_11 * ) V_26 -> V_32 ;
if ( ! V_12 )
return F_13 ( V_8 , V_26 ) ;
V_10 = F_14 ( sizeof( * V_10 ) , V_33 ) ;
if ( ! V_10 )
return - V_34 ;
F_15 ( & V_30 ) ;
V_31 = F_16 ( V_8 , & V_30 , F_1 , NULL ) ;
if ( V_31 < 0 )
goto V_35;
F_17 (rentry, &resource_list, node)
if ( F_18 ( & V_28 -> V_2 ) == V_36 ) {
V_10 -> V_20 = F_19 ( & V_28 -> V_2 ) ;
V_10 -> V_19 = F_20 ( V_28 -> V_2 . V_37 ,
V_10 -> V_20 ) ;
V_10 -> V_12 = V_12 ;
break;
}
F_21 ( & V_30 ) ;
if ( V_12 -> V_38 ) {
V_31 = F_5 ( V_8 , V_10 ) ;
if ( V_31 ) {
V_31 = 0 ;
goto V_35;
}
}
V_31 = F_22 ( V_8 ) ;
if ( V_31 ) {
V_31 = 0 ;
goto V_35;
}
V_8 -> V_32 = V_10 ;
V_31 = F_13 ( V_8 , V_26 ) ;
if ( V_31 > 0 )
return V_31 ;
V_8 -> V_32 = NULL ;
V_35:
F_23 ( V_10 ) ;
return V_31 ;
}
static int F_24 ( struct V_39 * V_18 , unsigned int V_40 , T_1 * V_41 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
unsigned long V_42 ;
int V_31 ;
V_31 = F_25 ( F_26 ( V_18 ) , & V_8 ) ;
if ( F_27 ( V_31 ) )
return V_31 ;
F_28 ( & V_18 -> V_43 . V_44 , V_42 ) ;
if ( F_29 ( V_18 ) ) {
V_31 = - V_45 ;
goto V_46;
}
V_10 = F_30 ( V_8 ) ;
if ( F_27 ( ! V_10 || ! V_10 -> V_19 ) ) {
V_31 = - V_15 ;
goto V_46;
}
* V_41 = F_31 ( V_10 -> V_19 + V_10 -> V_12 -> V_21 + V_40 ) ;
V_46:
F_32 ( & V_18 -> V_43 . V_44 , V_42 ) ;
return V_31 ;
}
static T_2 F_33 ( struct V_39 * V_18 , struct V_47 * V_48 ,
char * V_49 )
{
T_1 V_50 = 0 ;
unsigned int V_40 ;
int V_31 ;
V_40 = strcmp ( V_48 -> V_48 . V_24 , L_2 ) ? V_51 : V_52 ;
V_31 = F_24 ( V_18 , V_40 , & V_50 ) ;
if ( V_31 )
return V_31 ;
return snprintf ( V_49 , V_53 , L_3 , V_50 ) ;
}
static T_2 F_34 ( struct V_39 * V_18 ,
struct V_47 * V_48 , char * V_49 )
{
T_1 V_54 = 0 ;
char * V_55 ;
int V_31 ;
V_31 = F_24 ( V_18 , V_56 , & V_54 ) ;
if ( V_31 )
return V_31 ;
V_55 = ( V_54 & V_57 ) ? L_4 : L_5 ;
return sprintf ( V_49 , L_6 , V_55 ) ;
}
static int F_35 ( struct V_58 * V_59 ,
unsigned long V_60 , void * V_61 )
{
struct V_62 * V_63 = F_36 ( V_61 ) ;
struct V_9 * V_10 ;
struct V_7 * V_8 ;
const struct V_25 * V_26 ;
int V_31 = 0 ;
V_26 = F_37 ( V_64 , & V_63 -> V_18 ) ;
if ( ! V_26 || ! V_26 -> V_32 )
return 0 ;
if ( F_25 ( F_26 ( & V_63 -> V_18 ) , & V_8 ) )
return 0 ;
V_10 = F_30 ( V_8 ) ;
if ( ! V_10 || ! V_10 -> V_19 || ! V_10 -> V_12 -> V_65 )
return 0 ;
if ( V_10 -> V_20 < V_10 -> V_12 -> V_21 + V_66 ) {
F_38 ( & V_63 -> V_18 , L_7 ) ;
return 0 ;
}
if ( V_60 == V_67 )
V_31 = F_39 ( & V_63 -> V_18 . V_68 , & V_69 ) ;
else if ( V_60 == V_70 )
F_40 ( & V_63 -> V_18 . V_68 , & V_69 ) ;
return V_31 ;
}
void T_3 F_41 ( void )
{
if ( ! F_42 () ) {
F_43 ( & V_71 , & V_72 ) ;
F_44 ( & V_73 ) ;
}
}
