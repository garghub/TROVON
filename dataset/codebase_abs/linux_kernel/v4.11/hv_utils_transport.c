static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
V_2 -> V_4 = 0 ;
if ( V_2 -> V_5 )
V_2 -> V_5 () ;
}
static T_1 F_3 ( struct V_6 * V_6 , char T_2 * V_7 ,
T_3 V_8 , T_4 * V_9 )
{
struct V_1 * V_2 ;
int V_10 ;
V_2 = F_4 ( V_6 -> V_11 , struct V_1 , V_12 ) ;
if ( F_5 ( V_2 -> V_13 , V_2 -> V_4 > 0 ||
V_2 -> V_14 != V_15 ) )
return - V_16 ;
F_6 ( & V_2 -> V_17 ) ;
if ( V_2 -> V_14 == V_18 ) {
V_10 = - V_19 ;
goto V_20;
}
if ( ! V_2 -> V_3 ) {
V_10 = - V_21 ;
goto V_20;
}
if ( V_8 < V_2 -> V_4 ) {
V_10 = - V_22 ;
goto V_20;
}
if ( ! F_7 ( V_7 , V_2 -> V_3 , V_2 -> V_4 ) )
V_10 = V_2 -> V_4 ;
else
V_10 = - V_23 ;
F_2 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
V_2 -> V_4 = 0 ;
if ( V_2 -> V_24 )
V_2 -> V_24 () ;
V_2 -> V_24 = NULL ;
V_20:
F_8 ( & V_2 -> V_17 ) ;
return V_10 ;
}
static T_1 F_9 ( struct V_6 * V_6 , const char T_2 * V_7 ,
T_3 V_8 , T_4 * V_9 )
{
struct V_1 * V_2 ;
T_5 * V_25 ;
int V_10 ;
V_2 = F_4 ( V_6 -> V_11 , struct V_1 , V_12 ) ;
V_25 = F_10 ( V_7 , V_8 ) ;
if ( F_11 ( V_25 ) )
return F_12 ( V_25 ) ;
if ( V_2 -> V_14 == V_18 )
V_10 = - V_19 ;
else
V_10 = V_2 -> V_26 ( V_25 , V_8 ) ;
F_2 ( V_25 ) ;
return V_10 ? V_10 : V_8 ;
}
static unsigned int F_13 ( struct V_6 * V_6 , T_6 * V_27 )
{
struct V_1 * V_2 ;
V_2 = F_4 ( V_6 -> V_11 , struct V_1 , V_12 ) ;
F_14 ( V_6 , & V_2 -> V_13 , V_27 ) ;
if ( V_2 -> V_14 == V_18 )
return V_28 | V_29 ;
if ( V_2 -> V_4 > 0 )
return V_30 | V_31 ;
return 0 ;
}
static int F_15 ( struct V_32 * V_32 , struct V_6 * V_6 )
{
struct V_1 * V_2 ;
int V_10 = 0 ;
bool V_33 = false ;
V_2 = F_4 ( V_6 -> V_11 , struct V_1 , V_12 ) ;
F_6 ( & V_2 -> V_17 ) ;
if ( V_2 -> V_14 == V_18 ) {
V_10 = - V_19 ;
} else if ( V_2 -> V_14 == V_34 ) {
V_2 -> V_14 = V_15 ;
}
else if ( V_2 -> V_14 == V_35 ) {
V_33 = true ;
V_2 -> V_14 = V_15 ;
} else {
V_10 = - V_36 ;
}
if ( V_33 )
F_1 ( V_2 ) ;
F_8 ( & V_2 -> V_17 ) ;
return V_10 ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_17 ( & V_2 -> V_37 ) ;
F_2 ( V_2 -> V_3 ) ;
F_2 ( V_2 ) ;
}
static int F_18 ( struct V_32 * V_32 , struct V_6 * V_6 )
{
struct V_1 * V_2 ;
int V_38 ;
V_2 = F_4 ( V_6 -> V_11 , struct V_1 , V_12 ) ;
F_6 ( & V_2 -> V_17 ) ;
V_38 = V_2 -> V_14 ;
if ( V_2 -> V_14 != V_18 )
V_2 -> V_14 = V_34 ;
F_1 ( V_2 ) ;
if ( V_38 == V_18 )
F_19 ( & V_2 -> V_39 ) ;
F_8 ( & V_2 -> V_17 ) ;
return 0 ;
}
static void F_20 ( struct V_40 * V_41 , struct V_42 * V_43 )
{
struct V_1 * V_2 , * V_44 = NULL ;
F_21 ( & V_45 ) ;
F_22 (hvt, &hvt_list, list) {
if ( V_2 -> V_46 . V_47 == V_41 -> V_48 . V_47 &&
V_2 -> V_46 . V_49 == V_41 -> V_48 . V_49 ) {
V_44 = V_2 ;
break;
}
}
F_23 ( & V_45 ) ;
if ( ! V_44 ) {
F_24 ( L_1 ) ;
return;
}
F_6 ( & V_2 -> V_17 ) ;
if ( V_2 -> V_14 == V_34 )
V_2 -> V_14 = V_35 ;
if ( V_2 -> V_14 == V_35 )
V_44 -> V_26 ( V_41 -> V_50 , V_41 -> V_51 ) ;
else
F_24 ( L_2 ) ;
F_8 ( & V_2 -> V_17 ) ;
}
int F_25 ( struct V_1 * V_2 , void * V_41 , int V_51 ,
void (* F_26)( void ) )
{
struct V_40 * V_40 ;
int V_10 = 0 ;
if ( V_2 -> V_14 == V_34 ||
V_2 -> V_14 == V_18 ) {
return - V_22 ;
} else if ( V_2 -> V_14 == V_35 ) {
V_40 = F_27 ( sizeof( * V_40 ) + V_51 , V_52 ) ;
if ( ! V_40 )
return - V_53 ;
V_40 -> V_48 . V_47 = V_2 -> V_46 . V_47 ;
V_40 -> V_48 . V_49 = V_2 -> V_46 . V_49 ;
V_40 -> V_51 = V_51 ;
memcpy ( V_40 -> V_50 , V_41 , V_51 ) ;
V_10 = F_28 ( V_40 , 0 , 0 , V_52 ) ;
F_2 ( V_40 ) ;
if ( F_26 )
F_26 () ;
return V_10 ;
}
F_6 ( & V_2 -> V_17 ) ;
if ( V_2 -> V_14 != V_15 ) {
V_10 = - V_22 ;
goto V_20;
}
if ( V_2 -> V_3 ) {
V_10 = - V_23 ;
goto V_20;
}
V_2 -> V_3 = F_27 ( V_51 , V_54 ) ;
if ( V_2 -> V_3 ) {
memcpy ( V_2 -> V_3 , V_41 , V_51 ) ;
V_2 -> V_4 = V_51 ;
V_2 -> V_24 = F_26 ;
F_29 ( & V_2 -> V_13 ) ;
} else
V_10 = - V_53 ;
V_20:
F_8 ( & V_2 -> V_17 ) ;
return V_10 ;
}
struct V_1 * F_30 ( const char * V_55 ,
T_7 V_56 , T_7 V_57 ,
int (* V_26)( void * , int ) ,
void (* V_5)( void ) )
{
struct V_1 * V_2 ;
V_2 = F_27 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_46 . V_47 = V_56 ;
V_2 -> V_46 . V_49 = V_57 ;
V_2 -> V_37 . V_58 = V_59 ;
V_2 -> V_37 . V_55 = V_55 ;
V_2 -> V_12 . V_60 = V_61 ;
V_2 -> V_12 . V_62 = F_3 ;
V_2 -> V_12 . V_63 = F_9 ;
V_2 -> V_12 . V_64 = F_13 ;
V_2 -> V_12 . V_65 = F_15 ;
V_2 -> V_12 . V_39 = F_18 ;
V_2 -> V_37 . V_12 = & V_2 -> V_12 ;
F_31 ( & V_2 -> V_13 ) ;
F_32 ( & V_2 -> V_17 ) ;
F_33 ( & V_2 -> V_39 ) ;
F_21 ( & V_45 ) ;
F_34 ( & V_2 -> V_66 , & V_67 ) ;
F_23 ( & V_45 ) ;
V_2 -> V_26 = V_26 ;
V_2 -> V_5 = V_5 ;
if ( F_35 ( & V_2 -> V_37 ) )
goto V_68;
if ( V_2 -> V_46 . V_47 > 0 && V_2 -> V_46 . V_49 > 0 &&
F_36 ( & V_2 -> V_46 , V_55 , F_20 ) )
goto V_68;
return V_2 ;
V_68:
F_21 ( & V_45 ) ;
F_37 ( & V_2 -> V_66 ) ;
F_23 ( & V_45 ) ;
F_2 ( V_2 ) ;
return NULL ;
}
void F_38 ( struct V_1 * V_2 )
{
int V_38 ;
F_6 ( & V_2 -> V_17 ) ;
V_38 = V_2 -> V_14 ;
V_2 -> V_14 = V_18 ;
F_29 ( & V_2 -> V_13 ) ;
F_8 ( & V_2 -> V_17 ) ;
F_21 ( & V_45 ) ;
F_37 ( & V_2 -> V_66 ) ;
F_23 ( & V_45 ) ;
if ( V_2 -> V_46 . V_47 > 0 && V_2 -> V_46 . V_49 > 0 )
F_39 ( & V_2 -> V_46 ) ;
if ( V_38 == V_15 )
F_40 ( & V_2 -> V_39 ) ;
F_16 ( V_2 ) ;
}
