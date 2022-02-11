static bool F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_5 * V_6 = F_2 ( V_4 , F_3 ( * V_6 ) ,
V_7 ) ;
return ! F_4 ( V_2 -> V_8 . V_9 . V_10 , V_6 -> V_10 ) ;
}
static T_1 F_5 ( struct V_11 * V_11 , const char T_2 * V_12 ,
T_3 V_13 , T_4 * V_14 )
{
char * V_15 ;
int error ;
if ( ! V_13 || V_13 >= V_16 - 10 )
return - V_17 ;
V_15 = F_6 ( V_13 + 1 , V_18 ) ;
if ( ! V_15 )
return - V_17 ;
if ( F_7 ( V_15 , V_12 , V_13 ) ) {
error = - V_19 ;
goto V_20;
}
F_8 ( V_15 ) ;
if ( F_9 ( V_15 ) ) {
const int V_21 = F_10 () ;
struct V_22 V_23 ;
struct V_1 V_2 ;
V_23 . V_23 = V_15 ;
F_11 ( & V_23 ) ;
F_12 ( & V_2 , NULL , V_24 ) ;
V_2 . V_25 = V_26 ;
V_2 . V_8 . V_9 . V_10 = & V_23 ;
F_13 ( & V_2 , F_1 ) ;
if ( ! V_2 . V_27 )
error = - V_28 ;
else {
struct V_29 * V_30 =
F_14 ( V_15 , true ) ;
if ( ! V_30 ) {
error = - V_31 ;
} else {
struct V_32 * V_32 = F_15 () ;
if ( ! V_32 ) {
error = - V_17 ;
} else {
struct V_29 * V_33 =
V_32 -> V_34 ;
V_32 -> V_34 = V_30 ;
F_16 ( & V_30 -> V_35 ) ;
F_17 ( & V_33 -> V_35 ) ;
F_18 ( V_32 ) ;
error = 0 ;
}
}
}
F_19 ( V_21 ) ;
} else
error = - V_36 ;
V_20:
F_20 ( V_15 ) ;
return error ? error : V_13 ;
}
static T_1 F_21 ( struct V_11 * V_11 , char T_2 * V_12 ,
T_3 V_13 , T_4 * V_14 )
{
const char * V_37 = F_22 () -> V_10 -> V_23 ;
T_4 V_38 = strlen ( V_37 ) ;
T_4 V_39 = * V_14 ;
if ( V_39 >= V_38 || ! V_13 )
return 0 ;
V_38 -= V_39 ;
if ( V_13 < V_38 )
V_38 = V_13 ;
if ( F_23 ( V_12 , V_37 + V_39 , V_38 ) )
return - V_19 ;
* V_14 += V_38 ;
return V_38 ;
}
static int F_24 ( struct V_40 * V_40 , struct V_11 * V_11 )
{
const int V_41 = ( ( V_42 * ) V_11 -> V_43 . V_44 -> V_45 -> V_46 )
- ( ( V_42 * ) NULL ) ;
return F_25 ( V_41 , V_11 ) ;
}
static int F_26 ( struct V_40 * V_40 , struct V_11 * V_11 )
{
return F_27 ( V_11 -> V_47 ) ;
}
static unsigned int F_28 ( struct V_11 * V_11 , T_5 * V_48 )
{
return F_29 ( V_11 , V_48 ) ;
}
static T_1 F_30 ( struct V_11 * V_11 , char T_2 * V_12 , T_3 V_13 ,
T_4 * V_14 )
{
return F_31 ( V_11 -> V_47 , V_12 , V_13 ) ;
}
static T_1 F_32 ( struct V_11 * V_11 , const char T_2 * V_12 ,
T_3 V_13 , T_4 * V_14 )
{
return F_33 ( V_11 -> V_47 , V_12 , V_13 ) ;
}
static void T_6 F_34 ( const char * V_23 , const T_7 V_49 ,
struct V_44 * V_50 , const V_42 V_41 )
{
F_35 ( V_23 , V_49 , V_50 , ( ( V_42 * ) NULL ) + V_41 ,
& V_51 ) ;
}
static int T_6 F_36 ( void )
{
struct V_44 * V_52 ;
if ( F_37 () -> V_34 != & V_53 )
return 0 ;
V_52 = F_38 ( L_1 , NULL ) ;
F_34 ( L_2 , 0600 , V_52 ,
V_54 ) ;
F_34 ( L_3 , 0600 , V_52 ,
V_55 ) ;
F_34 ( L_4 , 0600 , V_52 ,
V_56 ) ;
F_34 ( L_5 , 0400 , V_52 ,
V_57 ) ;
F_34 ( L_6 , 0600 , V_52 ,
V_58 ) ;
F_34 ( L_7 , 0644 , V_52 ,
V_59 ) ;
F_34 ( L_8 , 0600 , V_52 ,
V_60 ) ;
F_34 ( L_9 , 0600 , V_52 ,
V_61 ) ;
F_34 ( L_10 , 0400 , V_52 ,
V_62 ) ;
F_35 ( L_11 , 0666 , V_52 , NULL ,
& V_63 ) ;
F_39 () ;
return 0 ;
}
