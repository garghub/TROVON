static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ,
struct V_7 ,
V_2 ) ;
F_3 ( & V_2 -> V_9 ) ;
V_4 = V_2 -> V_10 ;
V_3 = 0 ;
for ( V_6 = V_8 -> V_6 ; V_6 != NULL ; V_6 = V_6 -> V_11 )
V_3 |= ( V_6 -> V_12 & ~ V_13 ) ;
F_4 ( V_2 , V_3 ) ;
if ( V_4 == V_3 )
return;
if ( V_2 -> V_14 . V_15 )
F_5 ( V_2 -> V_14 . V_15 ) ;
}
static int F_6 ( struct V_16 * V_17 ,
struct V_1 * V_18 ,
struct V_1 * V_19 ,
struct V_20 * V_21 )
{
struct V_7 * V_8 ;
struct V_15 * V_22 ;
struct V_5 * V_6 ;
struct V_5 * * V_23 ;
struct V_24 * V_25 ;
T_1 V_26 = V_21 -> V_10 & ~ V_27 ;
F_7 ( V_19 ) ;
V_22 = V_21 -> V_22 ;
V_8 = F_2 ( V_18 , struct V_7 , V_2 ) ;
F_8 ( & V_18 -> V_9 ) ;
V_23 = & V_8 -> V_6 ;
while ( ( V_6 = * V_23 ) != NULL ) {
if ( ( V_6 -> V_12 & V_26 ) == 0 ) {
V_23 = & V_6 -> V_11 ;
continue;
}
V_25 = & V_6 -> V_28 -> V_29 ;
F_9 ( V_25 , V_6 -> V_30 , V_31 ) ;
if ( V_6 -> V_12 & V_13 )
V_23 = & V_6 -> V_11 ;
else {
* V_23 = V_6 -> V_11 ;
F_10 ( V_32 , V_6 ) ;
F_1 ( V_18 ) ;
}
}
F_11 ( & V_18 -> V_9 ) ;
return 0 ;
}
static bool F_12 ( struct V_16 * V_17 ,
struct V_15 * V_15 ,
struct V_1 * V_18 ,
struct V_1 * V_19 ,
T_1 V_10 , void * V_33 , int V_34 )
{
if ( ! F_13 ( V_15 -> V_35 ) )
return false ;
return true ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ,
struct V_7 ,
V_2 ) ;
F_7 ( V_8 -> V_6 ) ;
F_10 ( V_36 , V_8 ) ;
}
void F_15 ( struct V_37 * V_38 , T_2 V_39 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_5 * * V_23 ;
struct V_15 * V_15 ;
V_15 = F_16 ( V_38 ) ;
if ( ! F_13 ( V_15 -> V_35 ) )
return;
V_2 = F_17 ( V_40 , V_15 ) ;
if ( ! V_2 )
return;
V_8 = F_2 ( V_2 , struct V_7 , V_2 ) ;
F_18 ( & V_40 -> V_41 ) ;
F_8 ( & V_2 -> V_9 ) ;
V_23 = & V_8 -> V_6 ;
while ( ( V_6 = * V_23 ) != NULL ) {
if ( ( V_6 -> V_42 == V_39 ) && ( V_6 -> V_28 == V_38 ) ) {
* V_23 = V_6 -> V_11 ;
F_10 ( V_32 , V_6 ) ;
F_1 ( V_2 ) ;
break;
}
V_23 = & V_6 -> V_11 ;
}
F_11 ( & V_2 -> V_9 ) ;
if ( V_8 -> V_6 == NULL )
F_19 ( V_2 , V_40 ) ;
F_20 ( & V_40 -> V_41 ) ;
F_21 ( V_2 ) ;
}
static T_1 F_22 ( unsigned long V_43 )
{
T_1 V_3 = V_27 ;
if ( V_43 & V_44 )
V_3 |= V_13 ;
if ( V_43 & V_45 )
V_3 |= ( V_46 | V_47 ) ;
if ( V_43 & V_48 )
V_3 |= V_49 ;
if ( V_43 & V_50 )
V_3 |= V_51 ;
if ( V_43 & V_52 )
V_3 |= V_53 ;
if ( V_43 & V_54 )
V_3 |= V_55 ;
if ( V_43 & V_56 )
V_3 |= ( V_57 | V_58 ) ;
return V_3 ;
}
static int F_23 ( struct V_5 * V_6 , struct V_7 * V_8 ,
T_2 V_39 , int V_59 , struct V_37 * V_38 , T_1 V_10 )
{
struct V_5 * V_60 ;
V_60 = V_8 -> V_6 ;
while ( V_60 != NULL ) {
if ( ( V_60 -> V_42 == V_39 ) && ( V_60 -> V_28 == V_38 ) ) {
V_60 -> V_30 = V_59 ;
V_60 -> V_12 |= V_10 ;
return - V_61 ;
}
V_60 = V_60 -> V_11 ;
}
V_6 -> V_12 = V_10 ;
V_6 -> V_30 = V_59 ;
V_6 -> V_28 = V_38 ;
V_6 -> V_42 = V_39 ;
V_6 -> V_11 = V_8 -> V_6 ;
V_8 -> V_6 = V_6 ;
return 0 ;
}
int F_24 ( int V_59 , struct V_37 * V_38 , unsigned long V_43 )
{
struct V_7 * V_62 , * V_8 ;
struct V_1 * V_63 , * V_2 ;
struct V_5 * V_6 ;
struct V_15 * V_15 ;
T_2 V_39 = V_64 -> V_65 ;
struct V_37 * V_66 ;
int V_67 = 0 , error = 0 ;
T_1 V_10 ;
V_63 = NULL ;
V_6 = NULL ;
if ( ! V_68 ) {
error = - V_69 ;
goto V_70;
}
if ( ( V_43 & ~ V_44 ) == 0 ) {
F_15 ( V_38 , V_39 ) ;
error = 0 ;
goto V_70;
}
V_15 = F_16 ( V_38 ) ;
if ( ! F_13 ( V_15 -> V_35 ) ) {
error = - V_71 ;
goto V_70;
}
V_6 = F_25 ( V_32 , V_72 ) ;
if ( ! V_6 ) {
error = - V_73 ;
goto V_70;
}
V_62 = F_25 ( V_36 , V_72 ) ;
if ( ! V_62 ) {
error = - V_73 ;
goto V_70;
}
V_10 = F_22 ( V_43 ) ;
V_63 = & V_62 -> V_2 ;
F_26 ( V_63 , F_14 ) ;
V_63 -> V_10 = V_10 ;
V_62 -> V_6 = NULL ;
F_18 ( & V_40 -> V_41 ) ;
V_2 = F_17 ( V_40 , V_15 ) ;
if ( V_2 ) {
V_8 = F_2 ( V_2 , struct V_7 , V_2 ) ;
F_8 ( & V_2 -> V_9 ) ;
} else {
F_27 ( V_63 , V_40 , V_15 ,
NULL , 0 ) ;
F_8 ( & V_63 -> V_9 ) ;
V_2 = V_63 ;
V_8 = V_62 ;
V_63 = NULL ;
}
F_28 () ;
V_66 = F_29 ( V_59 ) ;
F_30 () ;
if ( V_66 != V_38 ) {
if ( V_8 == V_62 )
V_67 = 1 ;
goto V_74;
}
error = F_31 ( V_38 , F_32 ( V_64 ) , V_75 , 0 ) ;
if ( error ) {
if ( V_8 == V_62 )
V_67 = 1 ;
goto V_74;
}
error = F_23 ( V_6 , V_8 , V_39 , V_59 , V_38 , V_10 ) ;
if ( ! error )
V_6 = NULL ;
else if ( error == - V_61 )
error = 0 ;
F_1 ( V_2 ) ;
V_74:
F_11 ( & V_2 -> V_9 ) ;
if ( V_67 )
F_19 ( V_2 , V_40 ) ;
F_20 ( & V_40 -> V_41 ) ;
F_21 ( V_2 ) ;
V_70:
if ( V_63 )
F_21 ( V_63 ) ;
if ( V_6 )
F_10 ( V_32 , V_6 ) ;
return error ;
}
static int T_3 F_33 ( void )
{
V_32 = F_34 ( V_5 , V_76 ) ;
V_36 = F_34 ( V_7 , V_76 ) ;
V_40 = F_35 ( & V_77 ) ;
if ( F_36 ( V_40 ) )
F_37 ( L_1 ) ;
return 0 ;
}
