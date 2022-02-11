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
F_8 ( & V_2 -> V_17 ) ;
if ( V_38 == V_18 )
F_16 ( V_2 ) ;
return 0 ;
}
static void F_19 ( struct V_39 * V_40 , struct V_41 * V_42 )
{
struct V_1 * V_2 , * V_43 = NULL ;
F_20 ( & V_44 ) ;
F_21 (hvt, &hvt_list, list) {
if ( V_2 -> V_45 . V_46 == V_40 -> V_47 . V_46 &&
V_2 -> V_45 . V_48 == V_40 -> V_47 . V_48 ) {
V_43 = V_2 ;
break;
}
}
F_22 ( & V_44 ) ;
if ( ! V_43 ) {
F_23 ( L_1 ) ;
return;
}
F_6 ( & V_2 -> V_17 ) ;
if ( V_2 -> V_14 == V_34 )
V_2 -> V_14 = V_35 ;
if ( V_2 -> V_14 == V_35 )
V_43 -> V_26 ( V_40 -> V_49 , V_40 -> V_50 ) ;
else
F_23 ( L_2 ) ;
F_8 ( & V_2 -> V_17 ) ;
}
int F_24 ( struct V_1 * V_2 , void * V_40 , int V_50 ,
void (* F_25)( void ) )
{
struct V_39 * V_39 ;
int V_10 = 0 ;
if ( V_2 -> V_14 == V_34 ||
V_2 -> V_14 == V_18 ) {
return - V_22 ;
} else if ( V_2 -> V_14 == V_35 ) {
V_39 = F_26 ( sizeof( * V_39 ) + V_50 , V_51 ) ;
if ( ! V_39 )
return - V_52 ;
V_39 -> V_47 . V_46 = V_2 -> V_45 . V_46 ;
V_39 -> V_47 . V_48 = V_2 -> V_45 . V_48 ;
V_39 -> V_50 = V_50 ;
memcpy ( V_39 -> V_49 , V_40 , V_50 ) ;
V_10 = F_27 ( V_39 , 0 , 0 , V_51 ) ;
F_2 ( V_39 ) ;
if ( F_25 )
F_25 () ;
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
V_2 -> V_3 = F_26 ( V_50 , V_53 ) ;
if ( V_2 -> V_3 ) {
memcpy ( V_2 -> V_3 , V_40 , V_50 ) ;
V_2 -> V_4 = V_50 ;
V_2 -> V_24 = F_25 ;
F_28 ( & V_2 -> V_13 ) ;
} else
V_10 = - V_52 ;
V_20:
F_8 ( & V_2 -> V_17 ) ;
return V_10 ;
}
struct V_1 * F_29 ( const char * V_54 ,
T_7 V_55 , T_7 V_56 ,
int (* V_26)( void * , int ) ,
void (* V_5)( void ) )
{
struct V_1 * V_2 ;
V_2 = F_26 ( sizeof( * V_2 ) , V_53 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_45 . V_46 = V_55 ;
V_2 -> V_45 . V_48 = V_56 ;
V_2 -> V_37 . V_57 = V_58 ;
V_2 -> V_37 . V_54 = V_54 ;
V_2 -> V_12 . V_59 = V_60 ;
V_2 -> V_12 . V_61 = F_3 ;
V_2 -> V_12 . V_62 = F_9 ;
V_2 -> V_12 . V_63 = F_13 ;
V_2 -> V_12 . V_64 = F_15 ;
V_2 -> V_12 . V_65 = F_18 ;
V_2 -> V_37 . V_12 = & V_2 -> V_12 ;
F_30 ( & V_2 -> V_13 ) ;
F_31 ( & V_2 -> V_17 ) ;
F_20 ( & V_44 ) ;
F_32 ( & V_2 -> V_66 , & V_67 ) ;
F_22 ( & V_44 ) ;
V_2 -> V_26 = V_26 ;
V_2 -> V_5 = V_5 ;
if ( F_33 ( & V_2 -> V_37 ) )
goto V_68;
if ( V_2 -> V_45 . V_46 > 0 && V_2 -> V_45 . V_48 > 0 &&
F_34 ( & V_2 -> V_45 , V_54 , F_19 ) )
goto V_68;
return V_2 ;
V_68:
F_20 ( & V_44 ) ;
F_35 ( & V_2 -> V_66 ) ;
F_22 ( & V_44 ) ;
F_2 ( V_2 ) ;
return NULL ;
}
void F_36 ( struct V_1 * V_2 )
{
int V_38 ;
F_6 ( & V_2 -> V_17 ) ;
V_38 = V_2 -> V_14 ;
V_2 -> V_14 = V_18 ;
F_28 ( & V_2 -> V_13 ) ;
F_8 ( & V_2 -> V_17 ) ;
F_20 ( & V_44 ) ;
F_35 ( & V_2 -> V_66 ) ;
F_22 ( & V_44 ) ;
if ( V_2 -> V_45 . V_46 > 0 && V_2 -> V_45 . V_48 > 0 )
F_37 ( & V_2 -> V_45 ) ;
if ( V_38 != V_15 )
F_16 ( V_2 ) ;
}
