static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
struct V_4 * V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ,
struct V_6 ,
V_2 ) ;
F_3 ( & V_2 -> V_8 ) ;
for ( V_5 = V_7 -> V_5 ; V_5 != NULL ; V_5 = V_5 -> V_9 )
V_3 |= ( V_5 -> V_10 & ~ V_11 ) ;
if ( V_2 -> V_12 == V_3 )
return;
V_2 -> V_12 = V_3 ;
F_4 ( V_2 -> V_13 ) ;
}
static int F_5 ( struct V_14 * V_15 ,
struct V_16 * V_16 ,
struct V_1 * V_17 ,
struct V_1 * V_18 ,
T_2 V_12 , const void * V_19 , int V_20 ,
const unsigned char * V_21 , T_2 V_22 ,
struct V_23 * V_24 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_4 * * V_25 ;
struct V_26 * V_27 ;
T_1 V_28 = V_12 & ~ V_29 ;
if ( ! F_6 ( V_16 -> V_30 ) )
return 0 ;
F_7 ( V_18 ) ;
V_7 = F_2 ( V_17 , struct V_6 , V_2 ) ;
F_8 ( & V_17 -> V_8 ) ;
V_25 = & V_7 -> V_5 ;
while ( ( V_5 = * V_25 ) != NULL ) {
if ( ( V_5 -> V_10 & V_28 ) == 0 ) {
V_25 = & V_5 -> V_9 ;
continue;
}
V_27 = & V_5 -> V_31 -> V_32 ;
F_9 ( V_27 , V_5 -> V_33 , V_34 ) ;
if ( V_5 -> V_10 & V_11 )
V_25 = & V_5 -> V_9 ;
else {
* V_25 = V_5 -> V_9 ;
F_10 ( V_35 , V_5 ) ;
F_1 ( V_17 ) ;
}
}
F_11 ( & V_17 -> V_8 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ,
struct V_6 ,
V_2 ) ;
F_7 ( V_7 -> V_5 ) ;
F_10 ( V_36 , V_7 ) ;
}
void F_13 ( struct V_37 * V_38 , T_3 V_39 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_4 * * V_25 ;
struct V_16 * V_16 ;
bool free = false ;
V_16 = F_14 ( V_38 ) ;
if ( ! F_6 ( V_16 -> V_30 ) )
return;
V_2 = F_15 ( & V_16 -> V_40 , V_41 ) ;
if ( ! V_2 )
return;
V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
F_16 ( & V_41 -> V_42 ) ;
F_8 ( & V_2 -> V_8 ) ;
V_25 = & V_7 -> V_5 ;
while ( ( V_5 = * V_25 ) != NULL ) {
if ( ( V_5 -> V_43 == V_39 ) && ( V_5 -> V_31 == V_38 ) ) {
* V_25 = V_5 -> V_9 ;
F_10 ( V_35 , V_5 ) ;
F_1 ( V_2 ) ;
break;
}
V_25 = & V_5 -> V_9 ;
}
F_11 ( & V_2 -> V_8 ) ;
if ( V_7 -> V_5 == NULL ) {
F_17 ( V_2 ) ;
free = true ;
}
F_18 ( & V_41 -> V_42 ) ;
if ( free )
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
}
static T_1 F_21 ( unsigned long V_44 )
{
T_1 V_3 = V_29 ;
if ( V_44 & V_45 )
V_3 |= V_11 ;
if ( V_44 & V_46 )
V_3 |= ( V_47 | V_48 ) ;
if ( V_44 & V_49 )
V_3 |= V_50 ;
if ( V_44 & V_51 )
V_3 |= V_52 ;
if ( V_44 & V_53 )
V_3 |= V_54 ;
if ( V_44 & V_55 )
V_3 |= V_56 ;
if ( V_44 & V_57 )
V_3 |= ( V_58 | V_59 ) ;
return V_3 ;
}
static int F_22 ( struct V_4 * V_5 , struct V_6 * V_7 ,
T_3 V_39 , int V_60 , struct V_37 * V_38 , T_1 V_12 )
{
struct V_4 * V_61 ;
V_61 = V_7 -> V_5 ;
while ( V_61 != NULL ) {
if ( ( V_61 -> V_43 == V_39 ) && ( V_61 -> V_31 == V_38 ) ) {
V_61 -> V_33 = V_60 ;
V_61 -> V_10 |= V_12 ;
return - V_62 ;
}
V_61 = V_61 -> V_9 ;
}
V_5 -> V_10 = V_12 ;
V_5 -> V_33 = V_60 ;
V_5 -> V_31 = V_38 ;
V_5 -> V_43 = V_39 ;
V_5 -> V_9 = V_7 -> V_5 ;
V_7 -> V_5 = V_5 ;
return 0 ;
}
int F_23 ( int V_60 , struct V_37 * V_38 , unsigned long V_44 )
{
struct V_6 * V_63 , * V_7 ;
struct V_1 * V_64 , * V_2 ;
struct V_4 * V_5 ;
struct V_16 * V_16 ;
T_3 V_39 = V_65 -> V_66 ;
struct V_37 * V_67 ;
int V_68 = 0 , error = 0 ;
T_1 V_12 ;
V_64 = NULL ;
V_5 = NULL ;
if ( ! V_69 ) {
error = - V_70 ;
goto V_71;
}
if ( ( V_44 & ~ V_45 ) == 0 ) {
F_13 ( V_38 , V_39 ) ;
error = 0 ;
goto V_71;
}
V_16 = F_14 ( V_38 ) ;
if ( ! F_6 ( V_16 -> V_30 ) ) {
error = - V_72 ;
goto V_71;
}
V_5 = F_24 ( V_35 , V_73 ) ;
if ( ! V_5 ) {
error = - V_74 ;
goto V_71;
}
V_63 = F_24 ( V_36 , V_73 ) ;
if ( ! V_63 ) {
error = - V_74 ;
goto V_71;
}
V_12 = F_21 ( V_44 ) ;
V_64 = & V_63 -> V_2 ;
F_25 ( V_64 , V_41 ) ;
V_64 -> V_12 = V_12 ;
V_63 -> V_5 = NULL ;
F_16 ( & V_41 -> V_42 ) ;
V_2 = F_15 ( & V_16 -> V_40 , V_41 ) ;
if ( V_2 ) {
V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
F_8 ( & V_2 -> V_8 ) ;
} else {
F_26 ( V_64 , V_16 , NULL , 0 ) ;
F_8 ( & V_64 -> V_8 ) ;
V_2 = V_64 ;
V_7 = V_63 ;
V_64 = NULL ;
}
F_27 () ;
V_67 = F_28 ( V_60 ) ;
F_29 () ;
if ( V_67 != V_38 ) {
if ( V_7 == V_63 )
V_68 = 1 ;
goto V_75;
}
F_30 ( V_38 , F_31 ( V_65 ) , V_76 , 0 ) ;
error = F_22 ( V_5 , V_7 , V_39 , V_60 , V_38 , V_12 ) ;
if ( ! error )
V_5 = NULL ;
else if ( error == - V_62 )
error = 0 ;
F_1 ( V_2 ) ;
V_75:
F_11 ( & V_2 -> V_8 ) ;
if ( V_68 )
F_17 ( V_2 ) ;
F_18 ( & V_41 -> V_42 ) ;
if ( V_68 )
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
V_71:
if ( V_64 )
F_20 ( V_64 ) ;
if ( V_5 )
F_10 ( V_35 , V_5 ) ;
return error ;
}
static int T_4 F_32 ( void )
{
V_35 = F_33 ( V_4 , V_77 ) ;
V_36 = F_33 ( V_6 , V_77 ) ;
V_41 = F_34 ( & V_78 ) ;
if ( F_35 ( V_41 ) )
F_36 ( L_1 ) ;
return 0 ;
}
