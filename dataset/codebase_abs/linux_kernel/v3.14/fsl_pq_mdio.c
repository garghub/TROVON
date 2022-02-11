static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 T_2 * V_9 = V_7 -> V_9 ;
T_3 V_10 ;
F_2 ( & V_9 -> V_11 , ( V_3 << 8 ) | V_4 ) ;
F_2 ( & V_9 -> V_12 , V_5 ) ;
V_10 = F_3 ( ! ( F_4 ( & V_9 -> V_13 ) & V_14 ) ,
V_15 , 0 ) ;
return V_10 ? 0 : - V_16 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 T_2 * V_9 = V_7 -> V_9 ;
T_3 V_10 ;
T_1 V_5 ;
F_2 ( & V_9 -> V_11 , ( V_3 << 8 ) | V_4 ) ;
F_2 ( & V_9 -> V_17 , 0 ) ;
F_2 ( & V_9 -> V_17 , V_18 ) ;
V_10 = F_3 ( ! ( F_4 ( & V_9 -> V_13 ) &
( V_19 | V_14 ) ) ,
V_15 , 0 ) ;
if ( ! V_10 )
return - V_16 ;
V_5 = F_4 ( & V_9 -> V_20 ) ;
F_6 ( & V_2 -> V_21 , L_1 , V_5 , V_3 , V_4 ) ;
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 T_2 * V_9 = V_7 -> V_9 ;
T_3 V_10 ;
F_8 ( & V_2 -> V_22 ) ;
F_2 ( & V_9 -> V_23 , V_24 ) ;
F_2 ( & V_9 -> V_23 , V_25 ) ;
V_10 = F_3 ( ! ( F_4 ( & V_9 -> V_13 ) & V_14 ) ,
V_15 , 0 ) ;
F_9 ( & V_2 -> V_22 ) ;
if ( ! V_10 ) {
F_10 ( & V_2 -> V_21 , L_2 ) ;
return - V_26 ;
}
return 0 ;
}
static T_4 T_2 * F_11 ( void T_2 * V_27 )
{
struct V_28 T_2 * V_29 = V_27 ;
return & V_29 -> V_30 ;
}
static T_4 T_2 * F_12 ( void T_2 * V_27 )
{
return V_27 ;
}
static T_4 T_2 * F_13 ( void T_2 * V_27 )
{
struct V_31 T_2 * V_32 = V_27 ;
return & V_32 -> V_33 ;
}
static void F_14 ( T_5 V_34 , T_5 V_35 )
{
static bool V_36 ;
struct V_37 * V_38 = NULL ;
if ( V_36 )
return;
F_15 (np, NULL, L_3 ) {
struct V_39 V_40 ;
const T_4 * V_41 ;
T_4 V_42 ;
int V_43 ;
V_43 = F_16 ( V_38 , 0 , & V_40 ) ;
if ( V_43 < 0 ) {
F_17 ( L_4 ,
V_38 -> V_44 ) ;
continue;
}
if ( ( V_34 < V_40 . V_34 ) || ( V_35 > V_40 . V_35 ) )
continue;
V_41 = F_18 ( V_38 , L_5 , NULL ) ;
if ( ! V_41 ) {
V_41 = F_18 ( V_38 , L_6 , NULL ) ;
if ( ! V_41 ) {
F_17 ( L_7 ,
V_38 -> V_44 ) ;
continue;
}
}
V_42 = F_19 ( V_41 ) ;
if ( F_20 ( V_42 - 1 ) < 0 ) {
F_17 ( L_8 ,
V_38 -> V_44 ) ;
continue;
}
F_17 ( L_9 , V_42 ) ;
V_36 = true ;
}
}
static int F_21 ( struct V_45 * V_46 )
{
const struct V_47 * V_42 =
F_22 ( V_48 , & V_46 -> V_21 ) ;
const struct V_49 * V_50 = V_42 -> V_50 ;
struct V_37 * V_38 = V_46 -> V_21 . V_51 ;
struct V_39 V_40 ;
struct V_37 * V_52 ;
struct V_6 * V_7 ;
struct V_1 * V_53 ;
int V_54 ;
F_6 ( & V_46 -> V_21 , L_10 , V_42 -> V_55 ) ;
V_53 = F_23 ( sizeof( * V_7 ) ) ;
if ( ! V_53 )
return - V_56 ;
V_7 = V_53 -> V_7 ;
V_53 -> V_57 = L_11 ,
V_53 -> V_58 = & F_5 ;
V_53 -> V_59 = & F_1 ;
V_53 -> V_60 = & F_7 ;
V_53 -> V_61 = V_7 -> V_62 ;
V_54 = F_16 ( V_38 , 0 , & V_40 ) ;
if ( V_54 < 0 ) {
F_10 ( & V_46 -> V_21 , L_12 ) ;
goto error;
}
snprintf ( V_53 -> V_42 , V_63 , L_13 , V_38 -> V_57 ,
( unsigned long long ) V_40 . V_34 ) ;
V_7 -> V_64 = F_24 ( V_38 , 0 ) ;
if ( ! V_7 -> V_64 ) {
V_54 = - V_56 ;
goto error;
}
if ( V_50 -> V_65 > F_25 ( & V_40 ) ) {
F_10 ( & V_46 -> V_21 , L_14 ) ;
V_54 = - V_66 ;
goto error;
}
V_7 -> V_9 = V_7 -> V_64 + V_50 -> V_65 ;
V_53 -> V_67 = & V_46 -> V_21 ;
F_26 ( V_46 , V_53 ) ;
if ( V_50 -> V_68 ) {
F_27 (np, tbi) {
if ( strcmp ( V_52 -> type , L_15 ) == 0 ) {
F_6 ( & V_46 -> V_21 , L_16 ,
strrchr ( V_52 -> V_44 , '/' ) + 1 ) ;
break;
}
}
if ( V_52 ) {
const T_3 * V_69 = F_18 ( V_52 , L_17 , NULL ) ;
T_4 T_2 * V_30 ;
if ( ! V_69 ) {
F_10 ( & V_46 -> V_21 ,
L_18 ,
V_52 -> V_44 ) ;
V_54 = - V_26 ;
goto error;
}
V_30 = V_50 -> V_68 ( V_7 -> V_64 ) ;
F_2 ( V_30 , F_19 ( V_69 ) ) ;
}
}
if ( V_50 -> F_14 )
V_50 -> F_14 ( V_40 . V_34 , V_40 . V_35 ) ;
V_54 = F_28 ( V_53 , V_38 ) ;
if ( V_54 ) {
F_10 ( & V_46 -> V_21 , L_19 ,
V_53 -> V_57 ) ;
goto error;
}
return 0 ;
error:
if ( V_7 -> V_64 )
F_29 ( V_7 -> V_64 ) ;
F_30 ( V_53 ) ;
return V_54 ;
}
static int F_31 ( struct V_45 * V_46 )
{
struct V_70 * V_70 = & V_46 -> V_21 ;
struct V_1 * V_2 = F_32 ( V_70 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_33 ( V_2 ) ;
F_29 ( V_7 -> V_64 ) ;
F_34 ( V_2 ) ;
return 0 ;
}
