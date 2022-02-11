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
V_15 = V_38 -> V_40 . V_41 -> V_42 ;
if ( ! F_13 ( V_15 -> V_35 ) )
return;
V_2 = F_16 ( V_43 , V_15 ) ;
if ( ! V_2 )
return;
V_8 = F_2 ( V_2 , struct V_7 , V_2 ) ;
F_17 ( & V_44 ) ;
F_8 ( & V_2 -> V_9 ) ;
V_23 = & V_8 -> V_6 ;
while ( ( V_6 = * V_23 ) != NULL ) {
if ( ( V_6 -> V_45 == V_39 ) && ( V_6 -> V_28 == V_38 ) ) {
* V_23 = V_6 -> V_11 ;
F_10 ( V_32 , V_6 ) ;
F_1 ( V_2 ) ;
break;
}
V_23 = & V_6 -> V_11 ;
}
F_11 ( & V_2 -> V_9 ) ;
if ( V_8 -> V_6 == NULL )
F_18 ( V_2 ) ;
F_19 ( & V_44 ) ;
F_20 ( V_2 ) ;
}
static T_1 F_21 ( unsigned long V_46 )
{
T_1 V_3 = V_27 ;
if ( V_46 & V_47 )
V_3 |= V_13 ;
if ( V_46 & V_48 )
V_3 |= ( V_49 | V_50 ) ;
if ( V_46 & V_51 )
V_3 |= V_52 ;
if ( V_46 & V_53 )
V_3 |= V_54 ;
if ( V_46 & V_55 )
V_3 |= V_56 ;
if ( V_46 & V_57 )
V_3 |= V_58 ;
if ( V_46 & V_59 )
V_3 |= ( V_60 | V_61 ) ;
return V_3 ;
}
static int F_22 ( struct V_5 * V_6 , struct V_7 * V_8 ,
T_2 V_39 , int V_62 , struct V_37 * V_38 , T_1 V_10 )
{
struct V_5 * V_63 ;
V_63 = V_8 -> V_6 ;
while ( V_63 != NULL ) {
if ( ( V_63 -> V_45 == V_39 ) && ( V_63 -> V_28 == V_38 ) ) {
V_63 -> V_30 = V_62 ;
V_63 -> V_12 |= V_10 ;
return - V_64 ;
}
V_63 = V_63 -> V_11 ;
}
V_6 -> V_12 = V_10 ;
V_6 -> V_30 = V_62 ;
V_6 -> V_28 = V_38 ;
V_6 -> V_45 = V_39 ;
V_6 -> V_11 = V_8 -> V_6 ;
V_8 -> V_6 = V_6 ;
return 0 ;
}
int F_23 ( int V_62 , struct V_37 * V_38 , unsigned long V_46 )
{
struct V_7 * V_65 , * V_8 ;
struct V_1 * V_66 , * V_2 ;
struct V_5 * V_6 ;
struct V_15 * V_15 ;
T_2 V_39 = V_67 -> V_68 ;
struct V_37 * V_69 ;
int V_70 = 0 , error = 0 ;
T_1 V_10 ;
V_66 = NULL ;
V_6 = NULL ;
if ( ! V_71 ) {
error = - V_72 ;
goto V_73;
}
if ( ( V_46 & ~ V_47 ) == 0 ) {
F_15 ( V_38 , V_39 ) ;
error = 0 ;
goto V_73;
}
V_15 = V_38 -> V_40 . V_41 -> V_42 ;
if ( ! F_13 ( V_15 -> V_35 ) ) {
error = - V_74 ;
goto V_73;
}
V_6 = F_24 ( V_32 , V_75 ) ;
if ( ! V_6 ) {
error = - V_76 ;
goto V_73;
}
V_65 = F_24 ( V_36 , V_75 ) ;
if ( ! V_65 ) {
error = - V_76 ;
goto V_73;
}
V_10 = F_21 ( V_46 ) ;
V_66 = & V_65 -> V_2 ;
F_25 ( V_66 , F_14 ) ;
V_66 -> V_10 = V_10 ;
V_65 -> V_6 = NULL ;
F_17 ( & V_44 ) ;
V_2 = F_16 ( V_43 , V_15 ) ;
if ( V_2 ) {
V_8 = F_2 ( V_2 , struct V_7 , V_2 ) ;
F_8 ( & V_2 -> V_9 ) ;
} else {
F_26 ( V_66 , V_43 , V_15 , NULL , 0 ) ;
F_8 ( & V_66 -> V_9 ) ;
V_2 = V_66 ;
V_8 = V_65 ;
V_66 = NULL ;
}
F_27 () ;
V_69 = F_28 ( V_62 ) ;
F_29 () ;
if ( V_69 != V_38 ) {
if ( V_8 == V_65 )
V_70 = 1 ;
goto V_77;
}
error = F_30 ( V_38 , F_31 ( V_67 ) , V_78 , 0 ) ;
if ( error ) {
if ( V_8 == V_65 )
V_70 = 1 ;
goto V_77;
}
error = F_22 ( V_6 , V_8 , V_39 , V_62 , V_38 , V_10 ) ;
if ( ! error )
V_6 = NULL ;
else if ( error == - V_64 )
error = 0 ;
F_1 ( V_2 ) ;
V_77:
F_11 ( & V_2 -> V_9 ) ;
if ( V_70 )
F_18 ( V_2 ) ;
F_19 ( & V_44 ) ;
F_20 ( V_2 ) ;
V_73:
if ( V_66 )
F_20 ( V_66 ) ;
if ( V_6 )
F_10 ( V_32 , V_6 ) ;
return error ;
}
static int T_3 F_32 ( void )
{
V_32 = F_33 ( V_5 , V_79 ) ;
V_36 = F_33 ( V_7 , V_79 ) ;
V_43 = F_34 ( & V_80 ) ;
if ( F_35 ( V_43 ) )
F_36 ( L_1 ) ;
return 0 ;
}
