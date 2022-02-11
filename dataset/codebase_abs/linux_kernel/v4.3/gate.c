static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_1 * V_5 ;
T_1 V_6 , V_7 ;
int V_8 ;
V_8 = F_2 ( V_2 ) ;
V_5 = F_3 ( F_3 ( V_2 ) ) ;
V_4 = F_4 ( V_5 ) ;
if ( ! V_8 ) {
V_7 = V_9 -> V_10 ( V_4 -> V_11 ) ;
V_6 = V_7 ;
V_6 ^= ( 1 << V_4 -> V_12 ) ;
V_9 -> V_13 ( V_6 , V_4 -> V_11 ) ;
V_9 -> V_13 ( V_7 , V_4 -> V_11 ) ;
}
return V_8 ;
}
static struct V_14 * F_5 ( struct V_15 * V_16 , const char * V_17 ,
const char * V_18 , unsigned long V_19 ,
void T_2 * V_11 , T_3 V_20 ,
T_3 V_21 , const struct V_22 * V_23 ,
const struct V_24 * V_25 )
{
struct V_26 V_27 = { NULL } ;
struct V_28 * V_1 ;
struct V_14 * V_14 ;
V_1 = F_6 ( sizeof( * V_1 ) , V_29 ) ;
if ( ! V_1 )
return F_7 ( - V_30 ) ;
V_1 -> V_2 . V_27 = & V_27 ;
V_27 . V_17 = V_17 ;
V_27 . V_23 = V_23 ;
V_1 -> V_31 = V_11 ;
V_1 -> V_32 = V_20 ;
V_1 -> V_23 = V_25 ;
V_1 -> V_19 = V_33 | V_21 ;
V_27 . V_34 = & V_18 ;
V_27 . V_35 = 1 ;
V_27 . V_19 = V_19 ;
V_14 = F_8 ( NULL , & V_1 -> V_2 ) ;
if ( F_9 ( V_14 ) )
F_10 ( V_1 ) ;
return V_14 ;
}
struct V_14 * F_11 ( struct V_36 * V_37 )
{
const struct V_22 * V_23 = & V_38 ;
const struct V_24 * V_25 = NULL ;
T_1 V_11 ;
struct V_39 * V_40 ;
T_1 V_19 = 0 ;
T_3 V_21 = 0 ;
struct V_41 * V_42 ;
V_42 = V_37 -> V_43 ;
if ( V_42 -> V_19 & V_44 )
return F_12 ( V_37 ) ;
V_40 = (struct V_39 * ) & V_11 ;
if ( V_42 -> V_19 & V_45 )
V_19 |= V_46 ;
if ( V_42 -> V_19 & V_47 )
V_21 |= V_48 ;
if ( V_42 -> V_19 & V_49 ) {
V_23 = & V_50 ;
V_25 = & V_51 ;
}
if ( V_42 -> V_19 & V_52 )
V_25 = & V_53 ;
if ( V_42 -> V_19 & V_54 )
V_25 = & V_51 ;
if ( V_42 -> V_19 & V_55 )
V_23 = & V_56 ;
if ( V_42 -> V_19 & V_57 )
V_25 = & V_58 ;
V_40 -> V_59 = V_42 -> V_60 ;
V_40 -> V_61 = V_42 -> V_11 ;
return F_5 ( NULL , V_37 -> V_17 , V_42 -> V_4 , V_19 ,
( void T_2 * ) V_11 , V_42 -> V_62 ,
V_21 , V_23 , V_25 ) ;
}
struct V_1 * F_13 ( struct V_41 * V_37 )
{
struct V_28 * V_42 ;
struct V_39 * V_11 ;
const struct V_24 * V_23 = & V_51 ;
if ( ! V_37 )
return NULL ;
V_42 = F_6 ( sizeof( * V_42 ) , V_29 ) ;
if ( ! V_42 )
return F_7 ( - V_30 ) ;
V_11 = (struct V_39 * ) & V_42 -> V_31 ;
V_11 -> V_59 = V_37 -> V_60 ;
V_11 -> V_61 = V_37 -> V_11 ;
V_42 -> V_32 = V_37 -> V_62 ;
if ( V_37 -> V_19 & V_63 )
V_23 = NULL ;
if ( V_37 -> V_19 & V_44 )
V_23 = & V_64 ;
V_42 -> V_23 = V_23 ;
V_42 -> V_19 = V_33 ;
return & V_42 -> V_2 ;
}
static void T_4 F_14 ( struct V_65 * V_66 ,
const struct V_22 * V_23 ,
const struct V_24 * V_25 )
{
struct V_14 * V_14 ;
const char * V_18 ;
void T_2 * V_11 = NULL ;
T_3 V_32 = 0 ;
T_1 V_67 ;
T_1 V_19 = 0 ;
T_3 V_21 = 0 ;
if ( V_23 != & V_56 ) {
V_11 = F_15 ( V_66 , 0 ) ;
if ( F_9 ( V_11 ) )
return;
if ( ! F_16 ( V_66 , L_1 , & V_67 ) )
V_32 = V_67 ;
}
if ( F_17 ( V_66 ) != 1 ) {
F_18 ( L_2 , V_66 -> V_17 ) ;
return;
}
V_18 = F_19 ( V_66 , 0 ) ;
if ( F_20 ( V_66 , L_3 ) )
V_19 |= V_46 ;
if ( F_20 ( V_66 , L_4 ) )
V_21 |= V_48 ;
V_14 = F_5 ( NULL , V_66 -> V_17 , V_18 , V_19 , V_11 ,
V_32 , V_21 , V_23 , V_25 ) ;
if ( ! F_9 ( V_14 ) )
F_21 ( V_66 , V_68 , V_14 ) ;
}
static void T_4
F_22 ( struct V_65 * V_66 ,
const struct V_24 * V_25 )
{
struct V_28 * V_42 ;
T_1 V_67 = 0 ;
V_42 = F_6 ( sizeof( * V_42 ) , V_29 ) ;
if ( ! V_42 )
return;
V_42 -> V_31 = F_15 ( V_66 , 0 ) ;
if ( F_9 ( V_42 -> V_31 ) )
goto V_69;
F_16 ( V_66 , L_1 , & V_67 ) ;
V_42 -> V_32 = V_67 ;
V_42 -> V_23 = V_25 ;
V_42 -> V_19 = V_33 ;
if ( ! F_23 ( V_66 , & V_42 -> V_2 , V_70 ) )
return;
V_69:
F_10 ( V_42 ) ;
}
static void T_4
F_24 ( struct V_65 * V_66 )
{
F_22 ( V_66 , NULL ) ;
}
static void T_4 F_25 ( struct V_65 * V_66 )
{
F_22 ( V_66 , & V_64 ) ;
}
static void T_4 F_26 ( struct V_65 * V_66 )
{
F_22 ( V_66 , & V_51 ) ;
}
static void T_4 F_27 ( struct V_65 * V_66 )
{
F_14 ( V_66 , & V_56 , NULL ) ;
}
static void T_4 F_28 ( struct V_65 * V_66 )
{
F_14 ( V_66 , & V_50 ,
& V_51 ) ;
}
static void T_4 F_29 ( struct V_65 * V_66 )
{
F_14 ( V_66 , & V_38 , NULL ) ;
}
static void T_4 F_30 ( struct V_65 * V_66 )
{
F_14 ( V_66 , & V_38 , & V_51 ) ;
}
static void T_4 F_31 ( struct V_65 * V_66 )
{
F_14 ( V_66 , & V_38 ,
& V_58 ) ;
}
static void T_4 F_32 ( struct V_65 * V_66 )
{
F_14 ( V_66 , & V_38 ,
& V_53 ) ;
}
