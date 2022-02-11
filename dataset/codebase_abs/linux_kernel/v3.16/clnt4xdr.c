static T_1 F_1 ( T_2 V_1 )
{
T_1 V_2 ;
if ( V_1 >= V_3 )
V_2 = V_3 ;
else if ( V_1 <= - V_3 )
V_2 = - V_3 ;
else
V_2 = V_1 ;
return V_2 ;
}
static void F_2 ( const struct V_4 * V_5 ,
T_3 * V_6 , T_3 * V_7 )
{
const struct V_8 * V_9 = & V_5 -> V_9 ;
* V_6 = F_1 ( V_9 -> V_10 ) ;
if ( V_9 -> V_11 == V_12 )
* V_7 = 0 ;
else
* V_7 = F_1 ( V_9 -> V_11 - V_9 -> V_10 + 1 ) ;
}
static void F_3 ( const char * V_13 , const struct V_14 * V_15 )
{
F_4 ( L_1
L_2 ,
V_13 , V_15 -> V_16 - V_15 -> V_17 ) ;
}
static void F_5 ( struct V_14 * V_15 , const int V_18 )
{
T_4 * V_17 ;
V_17 = F_6 ( V_15 , 4 ) ;
* V_17 = V_18 ? V_19 : V_20 ;
}
static void F_7 ( struct V_14 * V_15 , const T_5 V_18 )
{
T_4 * V_17 ;
V_17 = F_6 ( V_15 , 4 ) ;
* V_17 = F_8 ( V_18 ) ;
}
static void F_9 ( struct V_14 * V_15 ,
const T_6 * V_21 , const unsigned int V_22 )
{
T_4 * V_17 ;
V_17 = F_6 ( V_15 , 4 + V_22 ) ;
F_10 ( V_17 , V_21 , V_22 ) ;
}
static int F_11 ( struct V_14 * V_15 ,
struct V_23 * V_24 )
{
T_7 V_22 ;
T_4 * V_17 ;
V_17 = F_12 ( V_15 , 4 ) ;
if ( F_13 ( V_17 == NULL ) )
goto V_25;
V_22 = F_14 ( V_17 ++ ) ;
if ( F_13 ( V_22 > V_26 ) )
goto V_27;
V_24 -> V_28 = V_22 ;
V_24 -> V_21 = ( T_6 * ) V_17 ;
return 0 ;
V_27:
F_4 ( L_3 , V_22 ) ;
return - V_29 ;
V_25:
F_3 ( V_30 , V_15 ) ;
return - V_29 ;
}
static void F_15 ( struct V_14 * V_15 ,
const struct V_31 * V_32 )
{
F_9 ( V_15 , ( T_6 * ) & V_32 -> V_21 , V_32 -> V_28 ) ;
}
static int F_16 ( struct V_14 * V_15 ,
struct V_31 * V_32 )
{
T_7 V_22 ;
T_4 * V_17 ;
V_17 = F_12 ( V_15 , 4 ) ;
if ( F_13 ( V_17 == NULL ) )
goto V_25;
V_22 = F_14 ( V_17 ++ ) ;
if ( V_22 == 0 )
goto V_33;
if ( V_22 > V_34 )
goto V_27;
V_17 = F_12 ( V_15 , V_22 ) ;
if ( F_13 ( V_17 == NULL ) )
goto V_25;
V_32 -> V_28 = V_22 ;
memcpy ( V_32 -> V_21 , V_17 , V_22 ) ;
return 0 ;
V_33:
V_32 -> V_28 = 4 ;
memset ( V_32 -> V_21 , 0 , 4 ) ;
return 0 ;
V_27:
F_4 ( L_4 , V_22 ) ;
return - V_29 ;
V_25:
F_3 ( V_30 , V_15 ) ;
return - V_29 ;
}
static void F_17 ( struct V_14 * V_15 , const struct V_35 * V_36 )
{
F_9 ( V_15 , ( T_6 * ) & V_36 -> V_21 , V_36 -> V_37 ) ;
}
static void F_18 ( struct V_14 * V_15 ,
const T_4 V_38 )
{
T_4 * V_17 ;
F_19 ( F_20 ( V_38 ) > V_39 ) ;
V_17 = F_6 ( V_15 , 4 ) ;
* V_17 = V_38 ;
}
static int F_21 ( struct V_14 * V_15 , T_4 * V_38 )
{
T_4 * V_17 ;
V_17 = F_12 ( V_15 , 4 ) ;
if ( F_13 ( V_17 == NULL ) )
goto V_25;
if ( F_13 ( F_22 ( * V_17 ) > F_22 ( V_40 ) ) )
goto V_41;
* V_38 = * V_17 ;
return 0 ;
V_41:
F_4 ( L_5 ,
V_30 , F_14 ( V_17 ) ) ;
return - V_29 ;
V_25:
F_3 ( V_30 , V_15 ) ;
return - V_29 ;
}
static void F_23 ( struct V_14 * V_15 ,
const struct V_42 * V_43 )
{
const struct V_4 * V_5 = & V_43 -> V_5 ;
T_3 V_6 , V_7 ;
T_4 * V_17 ;
F_5 ( V_15 , V_5 -> V_9 . V_44 == V_45 ) ;
F_7 ( V_15 , V_5 -> V_46 ) ;
F_9 ( V_15 , V_5 -> V_47 . V_21 , V_5 -> V_47 . V_28 ) ;
V_17 = F_6 ( V_15 , 4 + 4 ) ;
F_2 ( V_5 , & V_6 , & V_7 ) ;
V_17 = F_24 ( V_17 , V_6 ) ;
F_24 ( V_17 , V_7 ) ;
}
static int F_25 ( struct V_14 * V_15 , struct V_42 * V_43 )
{
struct V_4 * V_5 = & V_43 -> V_5 ;
struct V_8 * V_9 = & V_5 -> V_9 ;
T_3 V_6 , V_7 ;
T_7 V_48 ;
int error ;
T_4 * V_17 ;
T_5 V_16 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_26 ( V_9 ) ;
V_17 = F_12 ( V_15 , 4 + 4 ) ;
if ( F_13 ( V_17 == NULL ) )
goto V_25;
V_48 = F_14 ( V_17 ++ ) ;
V_5 -> V_46 = F_14 ( V_17 ) ;
V_9 -> V_49 = ( V_50 ) V_5 -> V_46 ;
error = F_11 ( V_15 , & V_5 -> V_47 ) ;
if ( F_13 ( error ) )
goto V_51;
V_17 = F_12 ( V_15 , 8 + 8 ) ;
if ( F_13 ( V_17 == NULL ) )
goto V_25;
V_9 -> V_52 = V_53 ;
V_9 -> V_44 = V_48 != 0 ? V_54 : V_45 ;
V_17 = F_27 ( V_17 , & V_6 ) ;
F_27 ( V_17 , & V_7 ) ;
V_16 = V_6 + V_7 - 1 ;
V_9 -> V_10 = ( T_2 ) V_6 ;
if ( V_7 == 0 || V_16 < 0 )
V_9 -> V_11 = V_12 ;
else
V_9 -> V_11 = ( T_2 ) V_16 ;
error = 0 ;
V_51:
return error ;
V_25:
F_3 ( V_30 , V_15 ) ;
return - V_29 ;
}
static void F_28 ( struct V_14 * V_15 , const char * V_55 )
{
T_7 V_22 = strlen ( V_55 ) ;
T_4 * V_17 ;
V_17 = F_6 ( V_15 , 4 + V_22 ) ;
F_10 ( V_17 , V_55 , V_22 ) ;
}
static void F_29 ( struct V_14 * V_15 ,
const struct V_4 * V_5 )
{
T_3 V_6 , V_7 ;
T_4 * V_17 ;
F_28 ( V_15 , V_5 -> V_56 ) ;
F_17 ( V_15 , & V_5 -> V_36 ) ;
F_9 ( V_15 , V_5 -> V_47 . V_21 , V_5 -> V_47 . V_28 ) ;
V_17 = F_6 ( V_15 , 4 + 8 + 8 ) ;
* V_17 ++ = F_8 ( V_5 -> V_46 ) ;
F_2 ( V_5 , & V_6 , & V_7 ) ;
V_17 = F_24 ( V_17 , V_6 ) ;
F_24 ( V_17 , V_7 ) ;
}
static void F_30 ( struct V_57 * V_58 ,
struct V_14 * V_15 ,
const struct V_59 * args )
{
const struct V_4 * V_5 = & args -> V_5 ;
F_15 ( V_15 , & args -> V_32 ) ;
F_5 ( V_15 , V_5 -> V_9 . V_44 == V_54 ) ;
F_29 ( V_15 , V_5 ) ;
}
static void F_31 ( struct V_57 * V_58 ,
struct V_14 * V_15 ,
const struct V_59 * args )
{
const struct V_4 * V_5 = & args -> V_5 ;
F_15 ( V_15 , & args -> V_32 ) ;
F_5 ( V_15 , args -> V_60 ) ;
F_5 ( V_15 , V_5 -> V_9 . V_44 == V_54 ) ;
F_29 ( V_15 , V_5 ) ;
F_5 ( V_15 , args -> V_61 ) ;
F_7 ( V_15 , args -> V_62 ) ;
}
static void F_32 ( struct V_57 * V_58 ,
struct V_14 * V_15 ,
const struct V_59 * args )
{
const struct V_4 * V_5 = & args -> V_5 ;
F_15 ( V_15 , & args -> V_32 ) ;
F_5 ( V_15 , args -> V_60 ) ;
F_5 ( V_15 , V_5 -> V_9 . V_44 == V_54 ) ;
F_29 ( V_15 , V_5 ) ;
}
static void F_33 ( struct V_57 * V_58 ,
struct V_14 * V_15 ,
const struct V_59 * args )
{
const struct V_4 * V_5 = & args -> V_5 ;
F_15 ( V_15 , & args -> V_32 ) ;
F_29 ( V_15 , V_5 ) ;
}
static void F_34 ( struct V_57 * V_58 ,
struct V_14 * V_15 ,
const struct V_42 * V_43 )
{
F_15 ( V_15 , & V_43 -> V_32 ) ;
F_18 ( V_15 , V_43 -> V_63 ) ;
}
static void F_35 ( struct V_57 * V_58 ,
struct V_14 * V_15 ,
const struct V_42 * V_43 )
{
F_15 ( V_15 , & V_43 -> V_32 ) ;
F_18 ( V_15 , V_43 -> V_63 ) ;
if ( V_43 -> V_63 == V_64 )
F_23 ( V_15 , V_43 ) ;
}
static int F_36 ( struct V_14 * V_15 ,
struct V_42 * V_43 )
{
int error ;
error = F_21 ( V_15 , & V_43 -> V_63 ) ;
if ( F_13 ( error ) )
goto V_51;
if ( V_43 -> V_63 == V_64 )
error = F_25 ( V_15 , V_43 ) ;
V_51:
return error ;
}
static int F_37 ( struct V_57 * V_58 ,
struct V_14 * V_15 ,
struct V_42 * V_43 )
{
int error ;
error = F_16 ( V_15 , & V_43 -> V_32 ) ;
if ( F_13 ( error ) )
goto V_51;
error = F_36 ( V_15 , V_43 ) ;
V_51:
return error ;
}
static int F_38 ( struct V_57 * V_58 ,
struct V_14 * V_15 ,
struct V_42 * V_43 )
{
int error ;
error = F_16 ( V_15 , & V_43 -> V_32 ) ;
if ( F_13 ( error ) )
goto V_51;
error = F_21 ( V_15 , & V_43 -> V_63 ) ;
V_51:
return error ;
}
