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
int V_27 = F_4 ( V_1 ) -> V_28 ;
T_1 V_29 = * V_3 ;
int V_4 = F_5 ( T_2 , V_23 , V_30 ) ;
char * V_31 ;
if ( ! V_23 )
return 0 ;
if ( V_27 ) {
if ( V_29 > V_27 )
return 0 ;
if ( V_29 + V_4 > V_27 )
V_4 = V_27 - V_29 ;
}
V_31 = F_6 ( V_4 , V_32 ) ;
if ( ! V_31 )
return - V_33 ;
F_7 ( & V_25 -> V_34 ) ;
V_4 = F_1 ( V_1 , V_25 -> V_2 , V_29 , V_4 ) ;
if ( V_4 < 0 ) {
F_8 ( & V_25 -> V_34 ) ;
goto V_35;
}
memcpy ( V_31 , V_25 -> V_2 , V_4 ) ;
F_8 ( & V_25 -> V_34 ) ;
if ( F_9 ( V_22 , V_31 , V_4 ) ) {
V_4 = - V_36 ;
goto V_35;
}
F_10 ( L_1 , V_29 , * V_3 , V_4 ) ;
* V_3 = V_29 + V_4 ;
V_35:
F_11 ( V_31 ) ;
return V_4 ;
}
static int
F_12 ( struct V_1 * V_1 , char * V_2 , T_1 V_37 , T_2 V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 . V_8 -> V_9 ;
struct V_10 * V_11 = V_6 -> V_12 . V_13 ;
struct V_14 * V_15 = V_6 -> V_16 -> V_17 . V_15 ;
int V_18 ;
if ( ! F_2 ( V_6 ) )
return - V_19 ;
V_18 = - V_20 ;
if ( V_11 -> V_38 )
V_18 = V_11 -> V_38 ( V_1 , V_15 , V_11 , V_2 , V_37 , V_4 ) ;
F_3 ( V_6 ) ;
return V_18 ;
}
static T_3 V_38 ( struct V_1 * V_1 , const char T_4 * V_22 ,
T_2 V_23 , T_1 * V_3 )
{
struct V_24 * V_25 = V_1 -> V_26 ;
int V_27 = F_4 ( V_1 ) -> V_28 ;
T_1 V_29 = * V_3 ;
int V_4 = F_5 ( T_2 , V_23 , V_30 ) ;
char * V_31 ;
if ( ! V_23 )
return 0 ;
if ( V_27 ) {
if ( V_29 > V_27 )
return 0 ;
if ( V_29 + V_4 > V_27 )
V_4 = V_27 - V_29 ;
}
V_31 = F_13 ( V_22 , V_4 ) ;
if ( F_14 ( V_31 ) )
return F_15 ( V_31 ) ;
F_7 ( & V_25 -> V_34 ) ;
memcpy ( V_25 -> V_2 , V_31 , V_4 ) ;
V_4 = F_12 ( V_1 , V_25 -> V_2 , V_29 , V_4 ) ;
F_8 ( & V_25 -> V_34 ) ;
if ( V_4 > 0 )
* V_3 = V_29 + V_4 ;
F_11 ( V_31 ) ;
return V_4 ;
}
static void F_16 ( struct V_39 * V_40 )
{
struct V_1 * V_1 = V_40 -> V_41 ;
struct V_24 * V_25 = V_1 -> V_26 ;
struct V_5 * V_6 = V_1 -> V_7 . V_8 -> V_9 ;
if ( ! V_25 -> V_42 )
return;
if ( ! F_2 ( V_6 ) )
return;
if ( V_25 -> V_42 -> V_43 )
V_25 -> V_42 -> V_43 ( V_40 ) ;
F_3 ( V_6 ) ;
}
static int F_17 ( struct V_39 * V_40 , struct V_44 * V_45 )
{
struct V_1 * V_1 = V_40 -> V_41 ;
struct V_24 * V_25 = V_1 -> V_26 ;
struct V_5 * V_6 = V_1 -> V_7 . V_8 -> V_9 ;
int V_46 ;
if ( ! V_25 -> V_42 )
return V_47 ;
if ( ! F_2 ( V_6 ) )
return V_47 ;
V_46 = V_47 ;
if ( V_25 -> V_42 -> V_48 )
V_46 = V_25 -> V_42 -> V_48 ( V_40 , V_45 ) ;
F_3 ( V_6 ) ;
return V_46 ;
}
static int F_18 ( struct V_39 * V_40 , struct V_44 * V_45 )
{
struct V_1 * V_1 = V_40 -> V_41 ;
struct V_24 * V_25 = V_1 -> V_26 ;
struct V_5 * V_6 = V_1 -> V_7 . V_8 -> V_9 ;
int V_46 ;
if ( ! V_25 -> V_42 )
return V_47 ;
if ( ! F_2 ( V_6 ) )
return V_47 ;
V_46 = 0 ;
if ( V_25 -> V_42 -> V_49 )
V_46 = V_25 -> V_42 -> V_49 ( V_40 , V_45 ) ;
else
F_19 ( V_1 ) ;
F_3 ( V_6 ) ;
return V_46 ;
}
static int F_20 ( struct V_39 * V_40 , unsigned long V_50 ,
void * V_51 , int V_52 , int V_38 )
{
struct V_1 * V_1 = V_40 -> V_41 ;
struct V_24 * V_25 = V_1 -> V_26 ;
struct V_5 * V_6 = V_1 -> V_7 . V_8 -> V_9 ;
int V_46 ;
if ( ! V_25 -> V_42 )
return - V_53 ;
if ( ! F_2 ( V_6 ) )
return - V_53 ;
V_46 = - V_53 ;
if ( V_25 -> V_42 -> V_54 )
V_46 = V_25 -> V_42 -> V_54 ( V_40 , V_50 , V_51 , V_52 , V_38 ) ;
F_3 ( V_6 ) ;
return V_46 ;
}
static int F_21 ( struct V_39 * V_40 , struct V_55 * V_56 )
{
struct V_1 * V_1 = V_40 -> V_41 ;
struct V_24 * V_25 = V_1 -> V_26 ;
struct V_5 * V_6 = V_1 -> V_7 . V_8 -> V_9 ;
int V_46 ;
if ( ! V_25 -> V_42 )
return 0 ;
if ( ! F_2 ( V_6 ) )
return - V_53 ;
V_46 = 0 ;
if ( V_25 -> V_42 -> V_57 )
V_46 = V_25 -> V_42 -> V_57 ( V_40 , V_56 ) ;
F_3 ( V_6 ) ;
return V_46 ;
}
static struct V_55 * F_22 ( struct V_39 * V_40 ,
unsigned long V_50 )
{
struct V_1 * V_1 = V_40 -> V_41 ;
struct V_24 * V_25 = V_1 -> V_26 ;
struct V_5 * V_6 = V_1 -> V_7 . V_8 -> V_9 ;
struct V_55 * V_58 ;
if ( ! V_25 -> V_42 )
return V_40 -> V_59 ;
if ( ! F_2 ( V_6 ) )
return V_40 -> V_59 ;
V_58 = V_40 -> V_59 ;
if ( V_25 -> V_42 -> V_60 )
V_58 = V_25 -> V_42 -> V_60 ( V_40 , V_50 ) ;
F_3 ( V_6 ) ;
return V_58 ;
}
static int F_23 ( struct V_39 * V_40 , const T_5 * V_61 ,
const T_5 * V_62 , unsigned long V_63 )
{
struct V_1 * V_1 = V_40 -> V_41 ;
struct V_24 * V_25 = V_1 -> V_26 ;
struct V_5 * V_6 = V_1 -> V_7 . V_8 -> V_9 ;
int V_46 ;
if ( ! V_25 -> V_42 )
return 0 ;
if ( ! F_2 ( V_6 ) )
return 0 ;
V_46 = 0 ;
if ( V_25 -> V_42 -> V_64 )
V_46 = V_25 -> V_42 -> V_64 ( V_40 , V_61 , V_62 , V_63 ) ;
F_3 ( V_6 ) ;
return V_46 ;
}
static int F_24 ( struct V_1 * V_1 , struct V_39 * V_40 )
{
struct V_24 * V_25 = V_1 -> V_26 ;
struct V_5 * V_6 = V_1 -> V_7 . V_8 -> V_9 ;
struct V_10 * V_11 = V_6 -> V_12 . V_13 ;
struct V_14 * V_15 = V_6 -> V_16 -> V_17 . V_15 ;
int V_18 ;
F_7 ( & V_25 -> V_34 ) ;
V_18 = - V_19 ;
if ( ! F_2 ( V_6 ) )
goto V_65;
V_18 = - V_53 ;
if ( ! V_11 -> F_24 )
goto V_66;
V_18 = V_11 -> F_24 ( V_1 , V_15 , V_11 , V_40 ) ;
if ( V_18 )
goto V_66;
if ( V_40 -> V_41 != V_1 )
goto V_66;
V_18 = - V_53 ;
if ( V_25 -> V_67 && V_25 -> V_42 != V_40 -> V_42 )
goto V_66;
V_18 = - V_53 ;
if ( V_40 -> V_42 && V_40 -> V_42 -> V_68 )
goto V_66;
V_18 = 0 ;
V_25 -> V_67 = 1 ;
V_25 -> V_42 = V_40 -> V_42 ;
V_40 -> V_42 = & V_69 ;
V_66:
F_3 ( V_6 ) ;
V_65:
F_8 ( & V_25 -> V_34 ) ;
return V_18 ;
}
static int V_43 ( struct V_70 * V_70 , struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_7 . V_8 -> V_9 ;
struct V_10 * V_11 = V_6 -> V_12 . V_13 ;
struct V_24 * V_25 = NULL ;
int error ;
if ( ! F_2 ( V_6 ) )
return - V_19 ;
error = - V_71 ;
if ( ( V_1 -> V_72 & V_73 ) && ! ( V_11 -> V_38 || V_11 -> F_24 ) )
goto V_74;
if ( ( V_1 -> V_72 & V_75 ) && ! ( V_11 -> V_21 || V_11 -> F_24 ) )
goto V_74;
error = - V_33 ;
V_25 = F_25 ( sizeof( * V_25 ) , V_32 ) ;
if ( ! V_25 )
goto V_74;
V_25 -> V_2 = F_6 ( V_30 , V_32 ) ;
if ( ! V_25 -> V_2 )
goto V_74;
F_26 ( & V_25 -> V_34 ) ;
V_25 -> V_1 = V_1 ;
V_1 -> V_26 = V_25 ;
F_7 ( & V_76 ) ;
F_27 ( & V_25 -> V_77 , & V_6 -> V_12 . V_78 ) ;
F_8 ( & V_76 ) ;
F_3 ( V_6 ) ;
return 0 ;
V_74:
F_3 ( V_6 ) ;
F_11 ( V_25 ) ;
return error ;
}
static int F_28 ( struct V_70 * V_70 , struct V_1 * V_1 )
{
struct V_24 * V_25 = V_1 -> V_26 ;
F_7 ( & V_76 ) ;
F_29 ( & V_25 -> V_77 ) ;
F_8 ( & V_76 ) ;
F_11 ( V_25 -> V_2 ) ;
F_11 ( V_25 ) ;
return 0 ;
}
void F_30 ( struct V_5 * V_6 )
{
struct V_24 * V_25 ;
if ( F_31 ( V_6 ) != V_79 )
return;
F_7 ( & V_76 ) ;
F_32 (bb, &attr_sd->s_bin_attr.buffers, list) {
struct V_70 * V_70 = F_4 ( V_25 -> V_1 ) ;
F_33 ( V_70 -> V_80 , 0 , 0 , 1 ) ;
}
F_8 ( & V_76 ) ;
}
int F_34 ( struct V_14 * V_15 ,
const struct V_10 * V_11 )
{
F_35 ( ! V_15 || ! V_15 -> V_81 || ! V_11 ) ;
return F_36 ( V_15 -> V_81 , & V_11 -> V_11 , V_79 ) ;
}
void F_37 ( struct V_14 * V_15 ,
const struct V_10 * V_11 )
{
F_38 ( V_15 -> V_81 , NULL , V_11 -> V_11 . V_82 ) ;
}
