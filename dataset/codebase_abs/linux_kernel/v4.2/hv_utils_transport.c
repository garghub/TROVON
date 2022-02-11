static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_3 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
V_2 -> V_5 = 0 ;
F_4 ( & V_2 -> V_3 ) ;
if ( V_2 -> V_6 )
V_2 -> V_6 () ;
}
static T_1 F_5 ( struct V_7 * V_7 , char T_2 * V_8 ,
T_3 V_9 , T_4 * V_10 )
{
struct V_1 * V_2 ;
int V_11 ;
V_2 = F_6 ( V_7 -> V_12 , struct V_1 , V_13 ) ;
if ( F_7 ( V_2 -> V_14 , V_2 -> V_5 > 0 ) )
return - V_15 ;
F_2 ( & V_2 -> V_3 ) ;
if ( ! V_2 -> V_4 ) {
V_11 = - V_16 ;
goto V_17;
}
if ( V_9 < V_2 -> V_5 ) {
V_11 = - V_18 ;
goto V_17;
}
if ( ! F_8 ( V_8 , V_2 -> V_4 , V_2 -> V_5 ) )
V_11 = V_2 -> V_5 ;
else
V_11 = - V_19 ;
F_3 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
V_2 -> V_5 = 0 ;
V_17:
F_4 ( & V_2 -> V_3 ) ;
return V_11 ;
}
static T_1 F_9 ( struct V_7 * V_7 , const char T_2 * V_8 ,
T_3 V_9 , T_4 * V_10 )
{
struct V_1 * V_2 ;
T_5 * V_20 ;
V_2 = F_6 ( V_7 -> V_12 , struct V_1 , V_13 ) ;
V_20 = F_10 ( V_9 , V_21 ) ;
if ( F_11 ( V_20 , V_8 , V_9 ) ) {
F_3 ( V_20 ) ;
return - V_19 ;
}
if ( V_2 -> V_22 ( V_20 , V_9 ) )
return - V_19 ;
F_3 ( V_20 ) ;
return V_9 ;
}
static unsigned int F_12 ( struct V_7 * V_7 , T_6 * V_23 )
{
struct V_1 * V_2 ;
V_2 = F_6 ( V_7 -> V_12 , struct V_1 , V_13 ) ;
F_13 ( V_7 , & V_2 -> V_14 , V_23 ) ;
if ( V_2 -> V_5 > 0 )
return V_24 | V_25 ;
return 0 ;
}
static int F_14 ( struct V_26 * V_26 , struct V_7 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_6 ( V_7 -> V_12 , struct V_1 , V_13 ) ;
if ( V_2 -> V_27 == V_28 )
V_2 -> V_27 = V_29 ;
else if ( V_2 -> V_27 == V_30 ) {
F_1 ( V_2 ) ;
V_2 -> V_27 = V_29 ;
} else
return - V_31 ;
return 0 ;
}
static int F_15 ( struct V_26 * V_26 , struct V_7 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_6 ( V_7 -> V_12 , struct V_1 , V_13 ) ;
V_2 -> V_27 = V_28 ;
F_1 ( V_2 ) ;
return 0 ;
}
static void F_16 ( struct V_32 * V_33 , struct V_34 * V_35 )
{
struct V_1 * V_2 , * V_36 = NULL ;
F_17 ( & V_37 ) ;
F_18 (hvt, &hvt_list, list) {
if ( V_2 -> V_38 . V_39 == V_33 -> V_40 . V_39 &&
V_2 -> V_38 . V_41 == V_33 -> V_40 . V_41 ) {
V_36 = V_2 ;
break;
}
}
F_19 ( & V_37 ) ;
if ( ! V_36 ) {
F_20 ( L_1 ) ;
return;
}
if ( V_2 -> V_27 == V_28 )
V_2 -> V_27 = V_30 ;
if ( V_2 -> V_27 == V_30 )
V_36 -> V_22 ( V_33 -> V_42 , V_33 -> V_43 ) ;
else
F_20 ( L_2 ) ;
}
int F_21 ( struct V_1 * V_2 , void * V_33 , int V_43 )
{
struct V_32 * V_32 ;
int V_11 = 0 ;
if ( V_2 -> V_27 == V_28 ) {
return - V_18 ;
} else if ( V_2 -> V_27 == V_30 ) {
V_32 = F_10 ( sizeof( * V_32 ) + V_43 , V_44 ) ;
if ( ! V_33 )
return - V_45 ;
V_32 -> V_40 . V_39 = V_2 -> V_38 . V_39 ;
V_32 -> V_40 . V_41 = V_2 -> V_38 . V_41 ;
V_32 -> V_43 = V_43 ;
memcpy ( V_32 -> V_42 , V_33 , V_43 ) ;
V_11 = F_22 ( V_32 , 0 , 0 , V_44 ) ;
F_3 ( V_32 ) ;
return V_11 ;
}
F_2 ( & V_2 -> V_3 ) ;
if ( V_2 -> V_4 ) {
V_11 = - V_19 ;
goto V_17;
}
V_2 -> V_4 = F_10 ( V_43 , V_21 ) ;
memcpy ( V_2 -> V_4 , V_33 , V_43 ) ;
V_2 -> V_5 = V_43 ;
F_23 ( & V_2 -> V_14 ) ;
V_17:
F_4 ( & V_2 -> V_3 ) ;
return V_11 ;
}
struct V_1 * F_24 ( const char * V_46 ,
T_7 V_47 , T_7 V_48 ,
int (* V_22)( void * , int ) ,
void (* V_6)( void ) )
{
struct V_1 * V_2 ;
V_2 = F_10 ( sizeof( * V_2 ) , V_21 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_38 . V_39 = V_47 ;
V_2 -> V_38 . V_41 = V_48 ;
V_2 -> V_49 . V_50 = V_51 ;
V_2 -> V_49 . V_46 = V_46 ;
V_2 -> V_13 . V_52 = V_53 ;
V_2 -> V_13 . V_54 = F_5 ;
V_2 -> V_13 . V_55 = F_9 ;
V_2 -> V_13 . V_56 = F_12 ;
V_2 -> V_13 . V_57 = F_14 ;
V_2 -> V_13 . V_58 = F_15 ;
V_2 -> V_49 . V_13 = & V_2 -> V_13 ;
F_25 ( & V_2 -> V_14 ) ;
F_26 ( & V_2 -> V_3 ) ;
F_17 ( & V_37 ) ;
F_27 ( & V_2 -> V_59 , & V_60 ) ;
F_19 ( & V_37 ) ;
V_2 -> V_22 = V_22 ;
V_2 -> V_6 = V_6 ;
if ( F_28 ( & V_2 -> V_49 ) )
goto V_61;
if ( V_2 -> V_38 . V_39 > 0 && V_2 -> V_38 . V_41 > 0 &&
F_29 ( & V_2 -> V_38 , V_46 , F_16 ) )
goto V_61;
return V_2 ;
V_61:
F_3 ( V_2 ) ;
return NULL ;
}
void F_30 ( struct V_1 * V_2 )
{
F_17 ( & V_37 ) ;
F_31 ( & V_2 -> V_59 ) ;
F_19 ( & V_37 ) ;
if ( V_2 -> V_38 . V_39 > 0 && V_2 -> V_38 . V_41 > 0 )
F_32 ( & V_2 -> V_38 ) ;
F_33 ( & V_2 -> V_49 ) ;
F_3 ( V_2 -> V_4 ) ;
F_3 ( V_2 ) ;
}
