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
V_20:
F_8 ( & V_2 -> V_17 ) ;
return V_10 ;
}
static T_1 F_9 ( struct V_6 * V_6 , const char T_2 * V_7 ,
T_3 V_8 , T_4 * V_9 )
{
struct V_1 * V_2 ;
T_5 * V_24 ;
int V_10 ;
V_2 = F_4 ( V_6 -> V_11 , struct V_1 , V_12 ) ;
V_24 = F_10 ( V_7 , V_8 ) ;
if ( F_11 ( V_24 ) )
return F_12 ( V_24 ) ;
if ( V_2 -> V_14 == V_18 )
V_10 = - V_19 ;
else
V_10 = V_2 -> V_25 ( V_24 , V_8 ) ;
F_2 ( V_24 ) ;
return V_10 ? V_10 : V_8 ;
}
static unsigned int F_13 ( struct V_6 * V_6 , T_6 * V_26 )
{
struct V_1 * V_2 ;
V_2 = F_4 ( V_6 -> V_11 , struct V_1 , V_12 ) ;
F_14 ( V_6 , & V_2 -> V_13 , V_26 ) ;
if ( V_2 -> V_14 == V_18 )
return V_27 | V_28 ;
if ( V_2 -> V_4 > 0 )
return V_29 | V_30 ;
return 0 ;
}
static int F_15 ( struct V_31 * V_31 , struct V_6 * V_6 )
{
struct V_1 * V_2 ;
int V_10 = 0 ;
bool V_32 = false ;
V_2 = F_4 ( V_6 -> V_11 , struct V_1 , V_12 ) ;
F_6 ( & V_2 -> V_17 ) ;
if ( V_2 -> V_14 == V_18 ) {
V_10 = - V_19 ;
} else if ( V_2 -> V_14 == V_33 ) {
V_2 -> V_14 = V_15 ;
}
else if ( V_2 -> V_14 == V_34 ) {
V_32 = true ;
V_2 -> V_14 = V_15 ;
} else {
V_10 = - V_35 ;
}
if ( V_32 )
F_1 ( V_2 ) ;
F_8 ( & V_2 -> V_17 ) ;
return V_10 ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_17 ( & V_2 -> V_36 ) ;
F_2 ( V_2 -> V_3 ) ;
F_2 ( V_2 ) ;
}
static int F_18 ( struct V_31 * V_31 , struct V_6 * V_6 )
{
struct V_1 * V_2 ;
int V_37 ;
V_2 = F_4 ( V_6 -> V_11 , struct V_1 , V_12 ) ;
F_6 ( & V_2 -> V_17 ) ;
V_37 = V_2 -> V_14 ;
if ( V_2 -> V_14 != V_18 )
V_2 -> V_14 = V_33 ;
F_1 ( V_2 ) ;
F_8 ( & V_2 -> V_17 ) ;
if ( V_37 == V_18 )
F_16 ( V_2 ) ;
return 0 ;
}
static void F_19 ( struct V_38 * V_39 , struct V_40 * V_41 )
{
struct V_1 * V_2 , * V_42 = NULL ;
F_20 ( & V_43 ) ;
F_21 (hvt, &hvt_list, list) {
if ( V_2 -> V_44 . V_45 == V_39 -> V_46 . V_45 &&
V_2 -> V_44 . V_47 == V_39 -> V_46 . V_47 ) {
V_42 = V_2 ;
break;
}
}
F_22 ( & V_43 ) ;
if ( ! V_42 ) {
F_23 ( L_1 ) ;
return;
}
F_6 ( & V_2 -> V_17 ) ;
if ( V_2 -> V_14 == V_33 )
V_2 -> V_14 = V_34 ;
if ( V_2 -> V_14 == V_34 )
V_42 -> V_25 ( V_39 -> V_48 , V_39 -> V_49 ) ;
else
F_23 ( L_2 ) ;
F_8 ( & V_2 -> V_17 ) ;
}
int F_24 ( struct V_1 * V_2 , void * V_39 , int V_49 )
{
struct V_38 * V_38 ;
int V_10 = 0 ;
if ( V_2 -> V_14 == V_33 ||
V_2 -> V_14 == V_18 ) {
return - V_22 ;
} else if ( V_2 -> V_14 == V_34 ) {
V_38 = F_25 ( sizeof( * V_38 ) + V_49 , V_50 ) ;
if ( ! V_38 )
return - V_51 ;
V_38 -> V_46 . V_45 = V_2 -> V_44 . V_45 ;
V_38 -> V_46 . V_47 = V_2 -> V_44 . V_47 ;
V_38 -> V_49 = V_49 ;
memcpy ( V_38 -> V_48 , V_39 , V_49 ) ;
V_10 = F_26 ( V_38 , 0 , 0 , V_50 ) ;
F_2 ( V_38 ) ;
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
V_2 -> V_3 = F_25 ( V_49 , V_52 ) ;
if ( V_2 -> V_3 ) {
memcpy ( V_2 -> V_3 , V_39 , V_49 ) ;
V_2 -> V_4 = V_49 ;
F_27 ( & V_2 -> V_13 ) ;
} else
V_10 = - V_51 ;
V_20:
F_8 ( & V_2 -> V_17 ) ;
return V_10 ;
}
struct V_1 * F_28 ( const char * V_53 ,
T_7 V_54 , T_7 V_55 ,
int (* V_25)( void * , int ) ,
void (* V_5)( void ) )
{
struct V_1 * V_2 ;
V_2 = F_25 ( sizeof( * V_2 ) , V_52 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_44 . V_45 = V_54 ;
V_2 -> V_44 . V_47 = V_55 ;
V_2 -> V_36 . V_56 = V_57 ;
V_2 -> V_36 . V_53 = V_53 ;
V_2 -> V_12 . V_58 = V_59 ;
V_2 -> V_12 . V_60 = F_3 ;
V_2 -> V_12 . V_61 = F_9 ;
V_2 -> V_12 . V_62 = F_13 ;
V_2 -> V_12 . V_63 = F_15 ;
V_2 -> V_12 . V_64 = F_18 ;
V_2 -> V_36 . V_12 = & V_2 -> V_12 ;
F_29 ( & V_2 -> V_13 ) ;
F_30 ( & V_2 -> V_17 ) ;
F_20 ( & V_43 ) ;
F_31 ( & V_2 -> V_65 , & V_66 ) ;
F_22 ( & V_43 ) ;
V_2 -> V_25 = V_25 ;
V_2 -> V_5 = V_5 ;
if ( F_32 ( & V_2 -> V_36 ) )
goto V_67;
if ( V_2 -> V_44 . V_45 > 0 && V_2 -> V_44 . V_47 > 0 &&
F_33 ( & V_2 -> V_44 , V_53 , F_19 ) )
goto V_67;
return V_2 ;
V_67:
F_2 ( V_2 ) ;
return NULL ;
}
void F_34 ( struct V_1 * V_2 )
{
int V_37 ;
F_6 ( & V_2 -> V_17 ) ;
V_37 = V_2 -> V_14 ;
V_2 -> V_14 = V_18 ;
F_27 ( & V_2 -> V_13 ) ;
F_8 ( & V_2 -> V_17 ) ;
F_20 ( & V_43 ) ;
F_35 ( & V_2 -> V_65 ) ;
F_22 ( & V_43 ) ;
if ( V_2 -> V_44 . V_45 > 0 && V_2 -> V_44 . V_47 > 0 )
F_36 ( & V_2 -> V_44 ) ;
if ( V_37 != V_15 )
F_16 ( V_2 ) ;
}
