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
struct V_15 * V_15 ,
struct V_1 * V_18 ,
struct V_1 * V_19 ,
T_2 V_10 , void * V_20 , int V_21 ,
const unsigned char * V_22 , T_2 V_23 )
{
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_5 * * V_24 ;
struct V_25 * V_26 ;
T_1 V_27 = V_10 & ~ V_28 ;
if ( ! F_7 ( V_15 -> V_29 ) )
return 0 ;
F_8 ( V_19 ) ;
V_8 = F_2 ( V_18 , struct V_7 , V_2 ) ;
F_9 ( & V_18 -> V_9 ) ;
V_24 = & V_8 -> V_6 ;
while ( ( V_6 = * V_24 ) != NULL ) {
if ( ( V_6 -> V_12 & V_27 ) == 0 ) {
V_24 = & V_6 -> V_11 ;
continue;
}
V_26 = & V_6 -> V_30 -> V_31 ;
F_10 ( V_26 , V_6 -> V_32 , V_33 ) ;
if ( V_6 -> V_12 & V_13 )
V_24 = & V_6 -> V_11 ;
else {
* V_24 = V_6 -> V_11 ;
F_11 ( V_34 , V_6 ) ;
F_1 ( V_18 ) ;
}
}
F_12 ( & V_18 -> V_9 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ,
struct V_7 ,
V_2 ) ;
F_8 ( V_8 -> V_6 ) ;
F_11 ( V_35 , V_8 ) ;
}
void F_14 ( struct V_36 * V_37 , T_3 V_38 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_5 * * V_24 ;
struct V_15 * V_15 ;
V_15 = F_15 ( V_37 ) ;
if ( ! F_7 ( V_15 -> V_29 ) )
return;
V_2 = F_16 ( V_39 , V_15 ) ;
if ( ! V_2 )
return;
V_8 = F_2 ( V_2 , struct V_7 , V_2 ) ;
F_17 ( & V_39 -> V_40 ) ;
F_9 ( & V_2 -> V_9 ) ;
V_24 = & V_8 -> V_6 ;
while ( ( V_6 = * V_24 ) != NULL ) {
if ( ( V_6 -> V_41 == V_38 ) && ( V_6 -> V_30 == V_37 ) ) {
* V_24 = V_6 -> V_11 ;
F_11 ( V_34 , V_6 ) ;
F_1 ( V_2 ) ;
break;
}
V_24 = & V_6 -> V_11 ;
}
F_12 ( & V_2 -> V_9 ) ;
if ( V_8 -> V_6 == NULL )
F_18 ( V_2 , V_39 ) ;
F_19 ( & V_39 -> V_40 ) ;
F_20 ( V_2 ) ;
}
static T_1 F_21 ( unsigned long V_42 )
{
T_1 V_3 = V_28 ;
if ( V_42 & V_43 )
V_3 |= V_13 ;
if ( V_42 & V_44 )
V_3 |= ( V_45 | V_46 ) ;
if ( V_42 & V_47 )
V_3 |= V_48 ;
if ( V_42 & V_49 )
V_3 |= V_50 ;
if ( V_42 & V_51 )
V_3 |= V_52 ;
if ( V_42 & V_53 )
V_3 |= V_54 ;
if ( V_42 & V_55 )
V_3 |= ( V_56 | V_57 ) ;
return V_3 ;
}
static int F_22 ( struct V_5 * V_6 , struct V_7 * V_8 ,
T_3 V_38 , int V_58 , struct V_36 * V_37 , T_1 V_10 )
{
struct V_5 * V_59 ;
V_59 = V_8 -> V_6 ;
while ( V_59 != NULL ) {
if ( ( V_59 -> V_41 == V_38 ) && ( V_59 -> V_30 == V_37 ) ) {
V_59 -> V_32 = V_58 ;
V_59 -> V_12 |= V_10 ;
return - V_60 ;
}
V_59 = V_59 -> V_11 ;
}
V_6 -> V_12 = V_10 ;
V_6 -> V_32 = V_58 ;
V_6 -> V_30 = V_37 ;
V_6 -> V_41 = V_38 ;
V_6 -> V_11 = V_8 -> V_6 ;
V_8 -> V_6 = V_6 ;
return 0 ;
}
int F_23 ( int V_58 , struct V_36 * V_37 , unsigned long V_42 )
{
struct V_7 * V_61 , * V_8 ;
struct V_1 * V_62 , * V_2 ;
struct V_5 * V_6 ;
struct V_15 * V_15 ;
T_3 V_38 = V_63 -> V_64 ;
struct V_36 * V_65 ;
int V_66 = 0 , error = 0 ;
T_1 V_10 ;
V_62 = NULL ;
V_6 = NULL ;
if ( ! V_67 ) {
error = - V_68 ;
goto V_69;
}
if ( ( V_42 & ~ V_43 ) == 0 ) {
F_14 ( V_37 , V_38 ) ;
error = 0 ;
goto V_69;
}
V_15 = F_15 ( V_37 ) ;
if ( ! F_7 ( V_15 -> V_29 ) ) {
error = - V_70 ;
goto V_69;
}
V_6 = F_24 ( V_34 , V_71 ) ;
if ( ! V_6 ) {
error = - V_72 ;
goto V_69;
}
V_61 = F_24 ( V_35 , V_71 ) ;
if ( ! V_61 ) {
error = - V_72 ;
goto V_69;
}
V_10 = F_21 ( V_42 ) ;
V_62 = & V_61 -> V_2 ;
F_25 ( V_62 , F_13 ) ;
V_62 -> V_10 = V_10 ;
V_61 -> V_6 = NULL ;
F_17 ( & V_39 -> V_40 ) ;
V_2 = F_16 ( V_39 , V_15 ) ;
if ( V_2 ) {
V_8 = F_2 ( V_2 , struct V_7 , V_2 ) ;
F_9 ( & V_2 -> V_9 ) ;
} else {
F_26 ( V_62 , V_39 , V_15 ,
NULL , 0 ) ;
F_9 ( & V_62 -> V_9 ) ;
V_2 = V_62 ;
V_8 = V_61 ;
V_62 = NULL ;
}
F_27 () ;
V_65 = F_28 ( V_58 ) ;
F_29 () ;
if ( V_65 != V_37 ) {
if ( V_8 == V_61 )
V_66 = 1 ;
goto V_73;
}
F_30 ( V_37 , F_31 ( V_63 ) , V_74 , 0 ) ;
error = F_22 ( V_6 , V_8 , V_38 , V_58 , V_37 , V_10 ) ;
if ( ! error )
V_6 = NULL ;
else if ( error == - V_60 )
error = 0 ;
F_1 ( V_2 ) ;
V_73:
F_12 ( & V_2 -> V_9 ) ;
if ( V_66 )
F_18 ( V_2 , V_39 ) ;
F_19 ( & V_39 -> V_40 ) ;
F_20 ( V_2 ) ;
V_69:
if ( V_62 )
F_20 ( V_62 ) ;
if ( V_6 )
F_11 ( V_34 , V_6 ) ;
return error ;
}
static int T_4 F_32 ( void )
{
V_34 = F_33 ( V_5 , V_75 ) ;
V_35 = F_33 ( V_7 , V_75 ) ;
V_39 = F_34 ( & V_76 ) ;
if ( F_35 ( V_39 ) )
F_36 ( L_1 ) ;
return 0 ;
}
