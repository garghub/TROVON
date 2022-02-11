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
F_3 ( V_9 -> V_10 > V_3 ) ;
F_3 ( V_9 -> V_11 > V_3 &&
V_9 -> V_11 != V_12 ) ;
* V_6 = F_1 ( V_9 -> V_10 ) ;
if ( V_9 -> V_11 == V_12 )
* V_7 = 0 ;
else
* V_7 = F_1 ( V_9 -> V_11 - V_9 -> V_10 + 1 ) ;
}
static void F_4 ( const char * V_13 , const struct V_14 * V_15 )
{
F_5 ( L_1
L_2 ,
V_13 , V_15 -> V_16 - V_15 -> V_17 ) ;
}
static void F_6 ( struct V_14 * V_15 , const int V_18 )
{
T_4 * V_17 ;
V_17 = F_7 ( V_15 , 4 ) ;
* V_17 = V_18 ? V_19 : V_20 ;
}
static void F_8 ( struct V_14 * V_15 , const T_5 V_18 )
{
T_4 * V_17 ;
V_17 = F_7 ( V_15 , 4 ) ;
* V_17 = F_9 ( V_18 ) ;
}
static void F_10 ( struct V_14 * V_15 ,
const T_6 * V_21 , const unsigned int V_22 )
{
T_4 * V_17 ;
F_3 ( V_22 > V_23 ) ;
V_17 = F_7 ( V_15 , 4 + V_22 ) ;
F_11 ( V_17 , V_21 , V_22 ) ;
}
static int F_12 ( struct V_14 * V_15 ,
struct V_24 * V_25 )
{
T_7 V_22 ;
T_4 * V_17 ;
V_17 = F_13 ( V_15 , 4 ) ;
if ( F_14 ( V_17 == NULL ) )
goto V_26;
V_22 = F_15 ( V_17 ++ ) ;
if ( F_14 ( V_22 > V_23 ) )
goto V_27;
V_25 -> V_28 = V_22 ;
V_25 -> V_21 = ( T_6 * ) V_17 ;
return 0 ;
V_27:
F_5 ( L_3 , V_22 ) ;
return - V_29 ;
V_26:
F_4 ( V_30 , V_15 ) ;
return - V_29 ;
}
static void F_16 ( struct V_14 * V_15 ,
const struct V_31 * V_32 )
{
F_3 ( V_32 -> V_28 > V_33 ) ;
F_10 ( V_15 , ( T_6 * ) & V_32 -> V_21 , V_32 -> V_28 ) ;
}
static int F_17 ( struct V_14 * V_15 ,
struct V_31 * V_32 )
{
T_7 V_22 ;
T_4 * V_17 ;
V_17 = F_13 ( V_15 , 4 ) ;
if ( F_14 ( V_17 == NULL ) )
goto V_26;
V_22 = F_15 ( V_17 ++ ) ;
if ( V_22 == 0 )
goto V_34;
if ( V_22 > V_33 )
goto V_27;
V_17 = F_13 ( V_15 , V_22 ) ;
if ( F_14 ( V_17 == NULL ) )
goto V_26;
V_32 -> V_28 = V_22 ;
memcpy ( V_32 -> V_21 , V_17 , V_22 ) ;
return 0 ;
V_34:
V_32 -> V_28 = 4 ;
memset ( V_32 -> V_21 , 0 , 4 ) ;
return 0 ;
V_27:
F_5 ( L_4 , V_22 ) ;
return - V_29 ;
V_26:
F_4 ( V_30 , V_15 ) ;
return - V_29 ;
}
static void F_18 ( struct V_14 * V_15 , const struct V_35 * V_36 )
{
F_3 ( V_36 -> V_37 > V_38 ) ;
F_10 ( V_15 , ( T_6 * ) & V_36 -> V_21 , V_36 -> V_37 ) ;
}
static void F_19 ( struct V_14 * V_15 ,
const T_4 V_39 )
{
T_4 * V_17 ;
F_3 ( F_20 ( V_39 ) > V_40 ) ;
V_17 = F_7 ( V_15 , 4 ) ;
* V_17 = V_39 ;
}
static int F_21 ( struct V_14 * V_15 , T_4 * V_39 )
{
T_4 * V_17 ;
V_17 = F_13 ( V_15 , 4 ) ;
if ( F_14 ( V_17 == NULL ) )
goto V_26;
if ( F_14 ( F_22 ( * V_17 ) > F_22 ( V_41 ) ) )
goto V_42;
* V_39 = * V_17 ;
return 0 ;
V_42:
F_5 ( L_5 ,
V_30 , F_15 ( V_17 ) ) ;
return - V_29 ;
V_26:
F_4 ( V_30 , V_15 ) ;
return - V_29 ;
}
static void F_23 ( struct V_14 * V_15 ,
const struct V_43 * V_44 )
{
const struct V_4 * V_5 = & V_44 -> V_5 ;
T_3 V_6 , V_7 ;
T_4 * V_17 ;
F_6 ( V_15 , V_5 -> V_9 . V_45 == V_46 ) ;
F_8 ( V_15 , V_5 -> V_47 ) ;
F_10 ( V_15 , V_5 -> V_48 . V_21 , V_5 -> V_48 . V_28 ) ;
V_17 = F_7 ( V_15 , 4 + 4 ) ;
F_2 ( V_5 , & V_6 , & V_7 ) ;
V_17 = F_24 ( V_17 , V_6 ) ;
F_24 ( V_17 , V_7 ) ;
}
static int F_25 ( struct V_14 * V_15 , struct V_43 * V_44 )
{
struct V_4 * V_5 = & V_44 -> V_5 ;
struct V_8 * V_9 = & V_5 -> V_9 ;
T_3 V_6 , V_7 ;
T_7 V_49 ;
int error ;
T_4 * V_17 ;
T_5 V_16 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_26 ( V_9 ) ;
V_17 = F_13 ( V_15 , 4 + 4 ) ;
if ( F_14 ( V_17 == NULL ) )
goto V_26;
V_49 = F_15 ( V_17 ++ ) ;
V_5 -> V_47 = F_15 ( V_17 ) ;
V_9 -> V_50 = ( V_51 ) V_5 -> V_47 ;
error = F_12 ( V_15 , & V_5 -> V_48 ) ;
if ( F_14 ( error ) )
goto V_52;
V_17 = F_13 ( V_15 , 8 + 8 ) ;
if ( F_14 ( V_17 == NULL ) )
goto V_26;
V_9 -> V_53 = V_54 ;
V_9 -> V_45 = V_49 != 0 ? V_55 : V_46 ;
V_17 = F_27 ( V_17 , & V_6 ) ;
F_27 ( V_17 , & V_7 ) ;
V_16 = V_6 + V_7 - 1 ;
V_9 -> V_10 = ( T_2 ) V_6 ;
if ( V_7 == 0 || V_16 < 0 )
V_9 -> V_11 = V_12 ;
else
V_9 -> V_11 = ( T_2 ) V_16 ;
error = 0 ;
V_52:
return error ;
V_26:
F_4 ( V_30 , V_15 ) ;
return - V_29 ;
}
static void F_28 ( struct V_14 * V_15 , const char * V_56 )
{
T_7 V_22 = strlen ( V_56 ) ;
T_4 * V_17 ;
F_3 ( V_22 > V_57 ) ;
V_17 = F_7 ( V_15 , 4 + V_22 ) ;
F_11 ( V_17 , V_56 , V_22 ) ;
}
static void F_29 ( struct V_14 * V_15 ,
const struct V_4 * V_5 )
{
T_3 V_6 , V_7 ;
T_4 * V_17 ;
F_28 ( V_15 , V_5 -> V_58 ) ;
F_18 ( V_15 , & V_5 -> V_36 ) ;
F_10 ( V_15 , V_5 -> V_48 . V_21 , V_5 -> V_48 . V_28 ) ;
V_17 = F_7 ( V_15 , 4 + 8 + 8 ) ;
* V_17 ++ = F_9 ( V_5 -> V_47 ) ;
F_2 ( V_5 , & V_6 , & V_7 ) ;
V_17 = F_24 ( V_17 , V_6 ) ;
F_24 ( V_17 , V_7 ) ;
}
static void F_30 ( struct V_59 * V_60 ,
struct V_14 * V_15 ,
const struct V_61 * args )
{
const struct V_4 * V_5 = & args -> V_5 ;
F_16 ( V_15 , & args -> V_32 ) ;
F_6 ( V_15 , V_5 -> V_9 . V_45 == V_55 ) ;
F_29 ( V_15 , V_5 ) ;
}
static void F_31 ( struct V_59 * V_60 ,
struct V_14 * V_15 ,
const struct V_61 * args )
{
const struct V_4 * V_5 = & args -> V_5 ;
F_16 ( V_15 , & args -> V_32 ) ;
F_6 ( V_15 , args -> V_62 ) ;
F_6 ( V_15 , V_5 -> V_9 . V_45 == V_55 ) ;
F_29 ( V_15 , V_5 ) ;
F_6 ( V_15 , args -> V_63 ) ;
F_8 ( V_15 , args -> V_64 ) ;
}
static void F_32 ( struct V_59 * V_60 ,
struct V_14 * V_15 ,
const struct V_61 * args )
{
const struct V_4 * V_5 = & args -> V_5 ;
F_16 ( V_15 , & args -> V_32 ) ;
F_6 ( V_15 , args -> V_62 ) ;
F_6 ( V_15 , V_5 -> V_9 . V_45 == V_55 ) ;
F_29 ( V_15 , V_5 ) ;
}
static void F_33 ( struct V_59 * V_60 ,
struct V_14 * V_15 ,
const struct V_61 * args )
{
const struct V_4 * V_5 = & args -> V_5 ;
F_16 ( V_15 , & args -> V_32 ) ;
F_29 ( V_15 , V_5 ) ;
}
static void F_34 ( struct V_59 * V_60 ,
struct V_14 * V_15 ,
const struct V_43 * V_44 )
{
F_16 ( V_15 , & V_44 -> V_32 ) ;
F_19 ( V_15 , V_44 -> V_65 ) ;
}
static void F_35 ( struct V_59 * V_60 ,
struct V_14 * V_15 ,
const struct V_43 * V_44 )
{
F_16 ( V_15 , & V_44 -> V_32 ) ;
F_19 ( V_15 , V_44 -> V_65 ) ;
if ( V_44 -> V_65 == V_66 )
F_23 ( V_15 , V_44 ) ;
}
static int F_36 ( struct V_14 * V_15 ,
struct V_43 * V_44 )
{
int error ;
error = F_21 ( V_15 , & V_44 -> V_65 ) ;
if ( F_14 ( error ) )
goto V_52;
if ( V_44 -> V_65 == V_66 )
error = F_25 ( V_15 , V_44 ) ;
V_52:
return error ;
}
static int F_37 ( struct V_59 * V_60 ,
struct V_14 * V_15 ,
struct V_43 * V_44 )
{
int error ;
error = F_17 ( V_15 , & V_44 -> V_32 ) ;
if ( F_14 ( error ) )
goto V_52;
error = F_36 ( V_15 , V_44 ) ;
V_52:
return error ;
}
static int F_38 ( struct V_59 * V_60 ,
struct V_14 * V_15 ,
struct V_43 * V_44 )
{
int error ;
error = F_17 ( V_15 , & V_44 -> V_32 ) ;
if ( F_14 ( error ) )
goto V_52;
error = F_21 ( V_15 , & V_44 -> V_65 ) ;
V_52:
return error ;
}
