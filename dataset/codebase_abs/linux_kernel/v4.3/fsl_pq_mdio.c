static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 T_2 * V_9 = V_7 -> V_9 ;
unsigned int V_10 ;
F_2 ( ( V_3 << 8 ) | V_4 , & V_9 -> V_11 ) ;
F_2 ( V_5 , & V_9 -> V_12 ) ;
V_10 = V_13 ;
while ( ( F_3 ( & V_9 -> V_14 ) & V_15 ) && V_10 ) {
F_4 () ;
V_10 -- ;
}
return V_10 ? 0 : - V_16 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 T_2 * V_9 = V_7 -> V_9 ;
unsigned int V_10 ;
T_1 V_5 ;
F_2 ( ( V_3 << 8 ) | V_4 , & V_9 -> V_11 ) ;
F_2 ( 0 , & V_9 -> V_17 ) ;
F_2 ( V_18 , & V_9 -> V_17 ) ;
V_10 = V_13 ;
while ( ( F_3 ( & V_9 -> V_14 ) &
( V_19 | V_15 ) ) && V_10 ) {
F_4 () ;
V_10 -- ;
}
if ( ! V_10 )
return - V_16 ;
V_5 = F_3 ( & V_9 -> V_20 ) ;
F_6 ( & V_2 -> V_21 , L_1 , V_5 , V_3 , V_4 ) ;
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 T_2 * V_9 = V_7 -> V_9 ;
unsigned int V_10 ;
F_8 ( & V_2 -> V_22 ) ;
F_2 ( V_23 , & V_9 -> V_24 ) ;
F_2 ( V_25 , & V_9 -> V_24 ) ;
V_10 = V_13 ;
while ( ( F_3 ( & V_9 -> V_14 ) & V_15 ) && V_10 ) {
F_4 () ;
V_10 -- ;
}
F_9 ( & V_2 -> V_22 ) ;
if ( ! V_10 ) {
F_10 ( & V_2 -> V_21 , L_2 ) ;
return - V_26 ;
}
return 0 ;
}
static T_3 T_2 * F_11 ( void T_2 * V_27 )
{
struct V_28 T_2 * V_29 = V_27 ;
return & V_29 -> V_30 ;
}
static T_3 T_2 * F_12 ( void T_2 * V_27 )
{
return F_11 ( F_13 ( V_27 , struct V_28 , V_31 ) ) ;
}
static T_3 T_2 * F_14 ( void T_2 * V_27 )
{
return V_27 ;
}
static T_3 T_2 * F_15 ( void T_2 * V_27 )
{
struct V_32 T_2 * V_33 = F_13 ( V_27 , struct V_32 , V_34 ) ;
return & V_33 -> V_35 ;
}
static void F_16 ( T_4 V_36 , T_4 V_37 )
{
static bool V_38 ;
struct V_39 * V_40 = NULL ;
if ( V_38 )
return;
F_17 (np, NULL, L_3 ) {
struct V_41 V_42 ;
const T_3 * V_43 ;
T_3 V_44 ;
int V_45 ;
V_45 = F_18 ( V_40 , 0 , & V_42 ) ;
if ( V_45 < 0 ) {
F_19 ( L_4 ,
V_40 -> V_46 ) ;
continue;
}
if ( ( V_36 < V_42 . V_36 ) || ( V_37 > V_42 . V_37 ) )
continue;
V_43 = F_20 ( V_40 , L_5 , NULL ) ;
if ( ! V_43 ) {
V_43 = F_20 ( V_40 , L_6 , NULL ) ;
if ( ! V_43 ) {
F_19 ( L_7 ,
V_40 -> V_46 ) ;
continue;
}
}
V_44 = F_21 ( V_43 ) ;
if ( F_22 ( V_44 - 1 ) < 0 ) {
F_19 ( L_8 ,
V_40 -> V_46 ) ;
continue;
}
F_19 ( L_9 , V_44 ) ;
V_38 = true ;
}
}
static int F_23 ( struct V_47 * V_48 )
{
const struct V_49 * V_44 =
F_24 ( V_50 , & V_48 -> V_21 ) ;
const struct V_51 * V_52 = V_44 -> V_52 ;
struct V_39 * V_40 = V_48 -> V_21 . V_53 ;
struct V_41 V_42 ;
struct V_39 * V_54 ;
struct V_6 * V_7 ;
struct V_1 * V_55 ;
int V_56 ;
F_6 ( & V_48 -> V_21 , L_10 , V_44 -> V_57 ) ;
V_55 = F_25 ( sizeof( * V_7 ) ) ;
if ( ! V_55 )
return - V_58 ;
V_7 = V_55 -> V_7 ;
V_55 -> V_59 = L_11 ,
V_55 -> V_60 = & F_5 ;
V_55 -> V_61 = & F_1 ;
V_55 -> V_62 = & F_7 ;
V_55 -> V_63 = V_7 -> V_64 ;
V_56 = F_18 ( V_40 , 0 , & V_42 ) ;
if ( V_56 < 0 ) {
F_10 ( & V_48 -> V_21 , L_12 ) ;
goto error;
}
snprintf ( V_55 -> V_44 , V_65 , L_13 , V_40 -> V_59 ,
( unsigned long long ) V_42 . V_36 ) ;
V_7 -> V_66 = F_26 ( V_40 , 0 ) ;
if ( ! V_7 -> V_66 ) {
V_56 = - V_58 ;
goto error;
}
if ( V_52 -> V_67 > F_27 ( & V_42 ) ) {
F_10 ( & V_48 -> V_21 , L_14 ) ;
V_56 = - V_68 ;
goto error;
}
V_7 -> V_9 = V_7 -> V_66 + V_52 -> V_67 ;
V_55 -> V_69 = & V_48 -> V_21 ;
F_28 ( V_48 , V_55 ) ;
if ( V_52 -> V_70 ) {
F_29 (np, tbi) {
if ( strcmp ( V_54 -> type , L_15 ) == 0 ) {
F_6 ( & V_48 -> V_21 , L_16 ,
strrchr ( V_54 -> V_46 , '/' ) + 1 ) ;
break;
}
}
if ( V_54 ) {
const T_5 * V_71 = F_20 ( V_54 , L_17 , NULL ) ;
T_3 T_2 * V_30 ;
if ( ! V_71 ) {
F_10 ( & V_48 -> V_21 ,
L_18 ,
V_54 -> V_46 ) ;
V_56 = - V_26 ;
goto error;
}
V_30 = V_52 -> V_70 ( V_7 -> V_66 ) ;
if ( ( void * ) V_30 > V_7 -> V_66 + F_27 ( & V_42 ) - 4 )
F_10 ( & V_48 -> V_21 , L_19 ,
( ( void * ) V_30 - V_7 -> V_66 ) + 4 ) ;
F_2 ( F_21 ( V_71 ) , V_30 ) ;
}
}
if ( V_52 -> F_16 )
V_52 -> F_16 ( V_42 . V_36 , V_42 . V_37 ) ;
V_56 = F_30 ( V_55 , V_40 ) ;
if ( V_56 ) {
F_10 ( & V_48 -> V_21 , L_20 ,
V_55 -> V_59 ) ;
goto error;
}
return 0 ;
error:
if ( V_7 -> V_66 )
F_31 ( V_7 -> V_66 ) ;
F_32 ( V_55 ) ;
return V_56 ;
}
static int F_33 ( struct V_47 * V_48 )
{
struct V_72 * V_72 = & V_48 -> V_21 ;
struct V_1 * V_2 = F_34 ( V_72 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_35 ( V_2 ) ;
F_31 ( V_7 -> V_66 ) ;
F_36 ( V_2 ) ;
return 0 ;
}
