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
V_15 = F_6 ( V_12 , V_13 ) ;
if ( F_7 ( V_15 ) )
return F_8 ( V_15 ) ;
F_9 ( V_15 ) ;
if ( F_10 ( V_15 ) ) {
const int V_18 = F_11 () ;
struct V_19 V_20 ;
struct V_1 V_2 ;
V_20 . V_20 = V_15 ;
F_12 ( & V_20 ) ;
F_13 ( & V_2 , NULL , V_21 ) ;
V_2 . V_22 = V_23 ;
V_2 . V_8 . V_9 . V_10 = & V_20 ;
F_14 ( & V_2 , F_1 ) ;
if ( ! V_2 . V_24 )
error = - V_25 ;
else {
struct V_26 * V_27 =
F_15 ( V_15 , true ) ;
if ( ! V_27 ) {
error = - V_28 ;
} else {
struct V_29 * V_29 = F_16 () ;
if ( ! V_29 ) {
error = - V_17 ;
} else {
struct V_26 * V_30 =
V_29 -> V_31 ;
V_29 -> V_31 = V_27 ;
F_17 ( & V_27 -> V_32 ) ;
F_18 ( & V_30 -> V_32 ) ;
F_19 ( V_29 ) ;
error = 0 ;
}
}
}
F_20 ( V_18 ) ;
} else
error = - V_33 ;
F_21 ( V_15 ) ;
return error ? error : V_13 ;
}
static T_1 F_22 ( struct V_11 * V_11 , char T_2 * V_12 ,
T_3 V_13 , T_4 * V_14 )
{
const char * V_34 = F_23 () -> V_10 -> V_20 ;
T_4 V_35 = strlen ( V_34 ) ;
T_4 V_36 = * V_14 ;
if ( V_36 >= V_35 || ! V_13 )
return 0 ;
V_35 -= V_36 ;
if ( V_13 < V_35 )
V_35 = V_13 ;
if ( F_24 ( V_12 , V_34 + V_36 , V_35 ) )
return - V_37 ;
* V_14 += V_35 ;
return V_35 ;
}
static int F_25 ( struct V_38 * V_38 , struct V_11 * V_11 )
{
const int V_39 = ( ( V_40 * ) F_26 ( V_11 ) -> V_41 )
- ( ( V_40 * ) NULL ) ;
return F_27 ( V_39 , V_11 ) ;
}
static int F_28 ( struct V_38 * V_38 , struct V_11 * V_11 )
{
F_29 ( V_11 -> V_42 ) ;
return 0 ;
}
static unsigned int F_30 ( struct V_11 * V_11 , T_5 * V_43 )
{
return F_31 ( V_11 , V_43 ) ;
}
static T_1 F_32 ( struct V_11 * V_11 , char T_2 * V_12 , T_3 V_13 ,
T_4 * V_14 )
{
return F_33 ( V_11 -> V_42 , V_12 , V_13 ) ;
}
static T_1 F_34 ( struct V_11 * V_11 , const char T_2 * V_12 ,
T_3 V_13 , T_4 * V_14 )
{
return F_35 ( V_11 -> V_42 , V_12 , V_13 ) ;
}
static void T_6 F_36 ( const char * V_20 , const T_7 V_44 ,
struct V_45 * V_46 , const V_40 V_39 )
{
F_37 ( V_20 , V_44 , V_46 , ( ( V_40 * ) NULL ) + V_39 ,
& V_47 ) ;
}
static int T_6 F_38 ( void )
{
struct V_45 * V_48 ;
if ( F_39 () -> V_31 != & V_49 )
return 0 ;
V_48 = F_40 ( L_1 , NULL ) ;
F_36 ( L_2 , 0600 , V_48 ,
V_50 ) ;
F_36 ( L_3 , 0600 , V_48 ,
V_51 ) ;
F_36 ( L_4 , 0600 , V_48 ,
V_52 ) ;
F_36 ( L_5 , 0400 , V_48 ,
V_53 ) ;
F_36 ( L_6 , 0600 , V_48 ,
V_54 ) ;
F_36 ( L_7 , 0644 , V_48 ,
V_55 ) ;
F_36 ( L_8 , 0600 , V_48 ,
V_56 ) ;
F_36 ( L_9 , 0600 , V_48 ,
V_57 ) ;
F_36 ( L_10 , 0400 , V_48 ,
V_58 ) ;
F_37 ( L_11 , 0666 , V_48 , NULL ,
& V_59 ) ;
F_41 () ;
return 0 ;
}
