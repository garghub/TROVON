static int
F_1 ( struct V_1 * V_1 , char * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 . V_8 -> V_9 ;
struct V_10 * V_11 = V_6 -> V_12 . V_13 ;
struct V_14 * V_15 = V_6 -> V_16 -> V_17 . V_15 ;
int V_18 ;
if ( ! F_2 ( V_6 ) )
return - V_19 ;
V_18 = - V_20 ;
if ( V_11 -> V_21 )
V_18 = V_11 -> V_21 ( V_1 , V_15 , V_11 , V_2 , V_3 , V_4 ) ;
F_3 ( V_6 ) ;
return V_18 ;
}
static T_3
V_21 ( struct V_1 * V_1 , char T_4 * V_22 , T_2 V_23 , T_1 * V_3 )
{
struct V_24 * V_25 = V_1 -> V_26 ;
int V_27 = V_1 -> V_7 . V_8 -> V_28 -> V_29 ;
T_1 V_30 = * V_3 ;
int V_4 = F_4 ( T_2 , V_23 , V_31 ) ;
char * V_32 ;
if ( ! V_23 )
return 0 ;
if ( V_27 ) {
if ( V_30 > V_27 )
return 0 ;
if ( V_30 + V_4 > V_27 )
V_4 = V_27 - V_30 ;
}
V_32 = F_5 ( V_4 , V_33 ) ;
if ( ! V_32 )
return - V_34 ;
F_6 ( & V_25 -> V_35 ) ;
V_4 = F_1 ( V_1 , V_25 -> V_2 , V_30 , V_4 ) ;
if ( V_4 < 0 ) {
F_7 ( & V_25 -> V_35 ) ;
goto V_36;
}
memcpy ( V_32 , V_25 -> V_2 , V_4 ) ;
F_7 ( & V_25 -> V_35 ) ;
if ( F_8 ( V_22 , V_32 , V_4 ) ) {
V_4 = - V_37 ;
goto V_36;
}
F_9 ( L_1 , V_30 , * V_3 , V_4 ) ;
* V_3 = V_30 + V_4 ;
V_36:
F_10 ( V_32 ) ;
return V_4 ;
}
static int
F_11 ( struct V_1 * V_1 , char * V_2 , T_1 V_38 , T_2 V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 . V_8 -> V_9 ;
struct V_10 * V_11 = V_6 -> V_12 . V_13 ;
struct V_14 * V_15 = V_6 -> V_16 -> V_17 . V_15 ;
int V_18 ;
if ( ! F_2 ( V_6 ) )
return - V_19 ;
V_18 = - V_20 ;
if ( V_11 -> V_39 )
V_18 = V_11 -> V_39 ( V_1 , V_15 , V_11 , V_2 , V_38 , V_4 ) ;
F_3 ( V_6 ) ;
return V_18 ;
}
static T_3 V_39 ( struct V_1 * V_1 , const char T_4 * V_22 ,
T_2 V_23 , T_1 * V_3 )
{
struct V_24 * V_25 = V_1 -> V_26 ;
int V_27 = V_1 -> V_7 . V_8 -> V_28 -> V_29 ;
T_1 V_30 = * V_3 ;
int V_4 = F_4 ( T_2 , V_23 , V_31 ) ;
char * V_32 ;
if ( ! V_23 )
return 0 ;
if ( V_27 ) {
if ( V_30 > V_27 )
return 0 ;
if ( V_30 + V_4 > V_27 )
V_4 = V_27 - V_30 ;
}
V_32 = F_12 ( V_22 , V_4 ) ;
if ( F_13 ( V_32 ) )
return F_14 ( V_32 ) ;
F_6 ( & V_25 -> V_35 ) ;
memcpy ( V_25 -> V_2 , V_32 , V_4 ) ;
V_4 = F_11 ( V_1 , V_25 -> V_2 , V_30 , V_4 ) ;
F_7 ( & V_25 -> V_35 ) ;
if ( V_4 > 0 )
* V_3 = V_30 + V_4 ;
F_10 ( V_32 ) ;
return V_4 ;
}
static void F_15 ( struct V_40 * V_41 )
{
struct V_1 * V_1 = V_41 -> V_42 ;
struct V_24 * V_25 = V_1 -> V_26 ;
struct V_5 * V_6 = V_1 -> V_7 . V_8 -> V_9 ;
if ( ! V_25 -> V_43 )
return;
if ( ! F_2 ( V_6 ) )
return;
if ( V_25 -> V_43 -> V_44 )
V_25 -> V_43 -> V_44 ( V_41 ) ;
F_3 ( V_6 ) ;
}
static int F_16 ( struct V_40 * V_41 , struct V_45 * V_46 )
{
struct V_1 * V_1 = V_41 -> V_42 ;
struct V_24 * V_25 = V_1 -> V_26 ;
struct V_5 * V_6 = V_1 -> V_7 . V_8 -> V_9 ;
int V_47 ;
if ( ! V_25 -> V_43 )
return V_48 ;
if ( ! F_2 ( V_6 ) )
return V_48 ;
V_47 = V_48 ;
if ( V_25 -> V_43 -> V_49 )
V_47 = V_25 -> V_43 -> V_49 ( V_41 , V_46 ) ;
F_3 ( V_6 ) ;
return V_47 ;
}
static int F_17 ( struct V_40 * V_41 , struct V_45 * V_46 )
{
struct V_1 * V_1 = V_41 -> V_42 ;
struct V_24 * V_25 = V_1 -> V_26 ;
struct V_5 * V_6 = V_1 -> V_7 . V_8 -> V_9 ;
int V_47 ;
if ( ! V_25 -> V_43 )
return V_48 ;
if ( ! F_2 ( V_6 ) )
return V_48 ;
V_47 = 0 ;
if ( V_25 -> V_43 -> V_50 )
V_47 = V_25 -> V_43 -> V_50 ( V_41 , V_46 ) ;
F_3 ( V_6 ) ;
return V_47 ;
}
static int F_18 ( struct V_40 * V_41 , unsigned long V_51 ,
void * V_52 , int V_53 , int V_39 )
{
struct V_1 * V_1 = V_41 -> V_42 ;
struct V_24 * V_25 = V_1 -> V_26 ;
struct V_5 * V_6 = V_1 -> V_7 . V_8 -> V_9 ;
int V_47 ;
if ( ! V_25 -> V_43 )
return - V_54 ;
if ( ! F_2 ( V_6 ) )
return - V_54 ;
V_47 = - V_54 ;
if ( V_25 -> V_43 -> V_55 )
V_47 = V_25 -> V_43 -> V_55 ( V_41 , V_51 , V_52 , V_53 , V_39 ) ;
F_3 ( V_6 ) ;
return V_47 ;
}
static int F_19 ( struct V_40 * V_41 , struct V_56 * V_57 )
{
struct V_1 * V_1 = V_41 -> V_42 ;
struct V_24 * V_25 = V_1 -> V_26 ;
struct V_5 * V_6 = V_1 -> V_7 . V_8 -> V_9 ;
int V_47 ;
if ( ! V_25 -> V_43 )
return 0 ;
if ( ! F_2 ( V_6 ) )
return - V_54 ;
V_47 = 0 ;
if ( V_25 -> V_43 -> V_58 )
V_47 = V_25 -> V_43 -> V_58 ( V_41 , V_57 ) ;
F_3 ( V_6 ) ;
return V_47 ;
}
static struct V_56 * F_20 ( struct V_40 * V_41 ,
unsigned long V_51 )
{
struct V_1 * V_1 = V_41 -> V_42 ;
struct V_24 * V_25 = V_1 -> V_26 ;
struct V_5 * V_6 = V_1 -> V_7 . V_8 -> V_9 ;
struct V_56 * V_59 ;
if ( ! V_25 -> V_43 )
return V_41 -> V_60 ;
if ( ! F_2 ( V_6 ) )
return V_41 -> V_60 ;
V_59 = V_41 -> V_60 ;
if ( V_25 -> V_43 -> V_61 )
V_59 = V_25 -> V_43 -> V_61 ( V_41 , V_51 ) ;
F_3 ( V_6 ) ;
return V_59 ;
}
static int F_21 ( struct V_40 * V_41 , const T_5 * V_62 ,
const T_5 * V_63 , unsigned long V_64 )
{
struct V_1 * V_1 = V_41 -> V_42 ;
struct V_24 * V_25 = V_1 -> V_26 ;
struct V_5 * V_6 = V_1 -> V_7 . V_8 -> V_9 ;
int V_47 ;
if ( ! V_25 -> V_43 )
return 0 ;
if ( ! F_2 ( V_6 ) )
return 0 ;
V_47 = 0 ;
if ( V_25 -> V_43 -> V_65 )
V_47 = V_25 -> V_43 -> V_65 ( V_41 , V_62 , V_63 , V_64 ) ;
F_3 ( V_6 ) ;
return V_47 ;
}
static int F_22 ( struct V_1 * V_1 , struct V_40 * V_41 )
{
struct V_24 * V_25 = V_1 -> V_26 ;
struct V_5 * V_6 = V_1 -> V_7 . V_8 -> V_9 ;
struct V_10 * V_11 = V_6 -> V_12 . V_13 ;
struct V_14 * V_15 = V_6 -> V_16 -> V_17 . V_15 ;
int V_18 ;
F_6 ( & V_25 -> V_35 ) ;
V_18 = - V_19 ;
if ( ! F_2 ( V_6 ) )
goto V_66;
V_18 = - V_54 ;
if ( ! V_11 -> F_22 )
goto V_67;
V_18 = V_11 -> F_22 ( V_1 , V_15 , V_11 , V_41 ) ;
if ( V_18 )
goto V_67;
if ( V_41 -> V_42 != V_1 )
goto V_67;
V_18 = - V_54 ;
if ( V_25 -> V_68 && V_25 -> V_43 != V_41 -> V_43 )
goto V_67;
V_18 = - V_54 ;
if ( V_41 -> V_43 && V_41 -> V_43 -> V_69 )
goto V_67;
V_18 = 0 ;
V_25 -> V_68 = 1 ;
V_25 -> V_43 = V_41 -> V_43 ;
V_41 -> V_43 = & V_70 ;
V_67:
F_3 ( V_6 ) ;
V_66:
F_7 ( & V_25 -> V_35 ) ;
return V_18 ;
}
static int V_44 ( struct V_71 * V_71 , struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_7 . V_8 -> V_9 ;
struct V_10 * V_11 = V_6 -> V_12 . V_13 ;
struct V_24 * V_25 = NULL ;
int error ;
if ( ! F_2 ( V_6 ) )
return - V_19 ;
error = - V_72 ;
if ( ( V_1 -> V_73 & V_74 ) && ! ( V_11 -> V_39 || V_11 -> F_22 ) )
goto V_75;
if ( ( V_1 -> V_73 & V_76 ) && ! ( V_11 -> V_21 || V_11 -> F_22 ) )
goto V_75;
error = - V_34 ;
V_25 = F_23 ( sizeof( * V_25 ) , V_33 ) ;
if ( ! V_25 )
goto V_75;
V_25 -> V_2 = F_5 ( V_31 , V_33 ) ;
if ( ! V_25 -> V_2 )
goto V_75;
F_24 ( & V_25 -> V_35 ) ;
V_25 -> V_1 = V_1 ;
V_1 -> V_26 = V_25 ;
F_6 ( & V_77 ) ;
F_25 ( & V_25 -> V_78 , & V_6 -> V_12 . V_79 ) ;
F_7 ( & V_77 ) ;
F_3 ( V_6 ) ;
return 0 ;
V_75:
F_3 ( V_6 ) ;
F_10 ( V_25 ) ;
return error ;
}
static int F_26 ( struct V_71 * V_71 , struct V_1 * V_1 )
{
struct V_24 * V_25 = V_1 -> V_26 ;
F_6 ( & V_77 ) ;
F_27 ( & V_25 -> V_78 ) ;
F_7 ( & V_77 ) ;
F_10 ( V_25 -> V_2 ) ;
F_10 ( V_25 ) ;
return 0 ;
}
void F_28 ( struct V_5 * V_6 )
{
struct V_24 * V_25 ;
struct V_80 * V_81 ;
if ( F_29 ( V_6 ) != V_82 )
return;
F_6 ( & V_77 ) ;
F_30 (bb, tmp, &attr_sd->s_bin_attr.buffers, list) {
struct V_71 * V_71 = V_25 -> V_1 -> V_7 . V_8 -> V_28 ;
F_31 ( V_71 -> V_83 , 0 , 0 , 1 ) ;
}
F_7 ( & V_77 ) ;
}
int F_32 ( struct V_14 * V_15 ,
const struct V_10 * V_11 )
{
F_33 ( ! V_15 || ! V_15 -> V_84 || ! V_11 ) ;
return F_34 ( V_15 -> V_84 , & V_11 -> V_11 , V_82 ) ;
}
void F_35 ( struct V_14 * V_15 ,
const struct V_10 * V_11 )
{
F_36 ( V_15 -> V_84 , NULL , V_11 -> V_11 . V_85 ) ;
}
