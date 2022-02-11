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
if ( V_2 -> V_14 )
F_5 ( V_2 -> V_14 ) ;
}
static int F_6 ( struct V_15 * V_16 ,
struct V_14 * V_14 ,
struct V_1 * V_17 ,
struct V_1 * V_18 ,
T_2 V_10 , const void * V_19 , int V_20 ,
const unsigned char * V_21 , T_2 V_22 )
{
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_5 * * V_23 ;
struct V_24 * V_25 ;
T_1 V_26 = V_10 & ~ V_27 ;
if ( ! F_7 ( V_14 -> V_28 ) )
return 0 ;
F_8 ( V_18 ) ;
V_8 = F_2 ( V_17 , struct V_7 , V_2 ) ;
F_9 ( & V_17 -> V_9 ) ;
V_23 = & V_8 -> V_6 ;
while ( ( V_6 = * V_23 ) != NULL ) {
if ( ( V_6 -> V_12 & V_26 ) == 0 ) {
V_23 = & V_6 -> V_11 ;
continue;
}
V_25 = & V_6 -> V_29 -> V_30 ;
F_10 ( V_25 , V_6 -> V_31 , V_32 ) ;
if ( V_6 -> V_12 & V_13 )
V_23 = & V_6 -> V_11 ;
else {
* V_23 = V_6 -> V_11 ;
F_11 ( V_33 , V_6 ) ;
F_1 ( V_17 ) ;
}
}
F_12 ( & V_17 -> V_9 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ,
struct V_7 ,
V_2 ) ;
F_8 ( V_8 -> V_6 ) ;
F_11 ( V_34 , V_8 ) ;
}
void F_14 ( struct V_35 * V_36 , T_3 V_37 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_5 * * V_23 ;
struct V_14 * V_14 ;
bool free = false ;
V_14 = F_15 ( V_36 ) ;
if ( ! F_7 ( V_14 -> V_28 ) )
return;
V_2 = F_16 ( V_38 , V_14 ) ;
if ( ! V_2 )
return;
V_8 = F_2 ( V_2 , struct V_7 , V_2 ) ;
F_17 ( & V_38 -> V_39 ) ;
F_9 ( & V_2 -> V_9 ) ;
V_23 = & V_8 -> V_6 ;
while ( ( V_6 = * V_23 ) != NULL ) {
if ( ( V_6 -> V_40 == V_37 ) && ( V_6 -> V_29 == V_36 ) ) {
* V_23 = V_6 -> V_11 ;
F_11 ( V_33 , V_6 ) ;
F_1 ( V_2 ) ;
break;
}
V_23 = & V_6 -> V_11 ;
}
F_12 ( & V_2 -> V_9 ) ;
if ( V_8 -> V_6 == NULL ) {
F_18 ( V_2 ) ;
free = true ;
}
F_19 ( & V_38 -> V_39 ) ;
if ( free )
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
}
static T_1 F_22 ( unsigned long V_41 )
{
T_1 V_3 = V_27 ;
if ( V_41 & V_42 )
V_3 |= V_13 ;
if ( V_41 & V_43 )
V_3 |= ( V_44 | V_45 ) ;
if ( V_41 & V_46 )
V_3 |= V_47 ;
if ( V_41 & V_48 )
V_3 |= V_49 ;
if ( V_41 & V_50 )
V_3 |= V_51 ;
if ( V_41 & V_52 )
V_3 |= V_53 ;
if ( V_41 & V_54 )
V_3 |= ( V_55 | V_56 ) ;
return V_3 ;
}
static int F_23 ( struct V_5 * V_6 , struct V_7 * V_8 ,
T_3 V_37 , int V_57 , struct V_35 * V_36 , T_1 V_10 )
{
struct V_5 * V_58 ;
V_58 = V_8 -> V_6 ;
while ( V_58 != NULL ) {
if ( ( V_58 -> V_40 == V_37 ) && ( V_58 -> V_29 == V_36 ) ) {
V_58 -> V_31 = V_57 ;
V_58 -> V_12 |= V_10 ;
return - V_59 ;
}
V_58 = V_58 -> V_11 ;
}
V_6 -> V_12 = V_10 ;
V_6 -> V_31 = V_57 ;
V_6 -> V_29 = V_36 ;
V_6 -> V_40 = V_37 ;
V_6 -> V_11 = V_8 -> V_6 ;
V_8 -> V_6 = V_6 ;
return 0 ;
}
int F_24 ( int V_57 , struct V_35 * V_36 , unsigned long V_41 )
{
struct V_7 * V_60 , * V_8 ;
struct V_1 * V_61 , * V_2 ;
struct V_5 * V_6 ;
struct V_14 * V_14 ;
T_3 V_37 = V_62 -> V_63 ;
struct V_35 * V_64 ;
int V_65 = 0 , error = 0 ;
T_1 V_10 ;
V_61 = NULL ;
V_6 = NULL ;
if ( ! V_66 ) {
error = - V_67 ;
goto V_68;
}
if ( ( V_41 & ~ V_42 ) == 0 ) {
F_14 ( V_36 , V_37 ) ;
error = 0 ;
goto V_68;
}
V_14 = F_15 ( V_36 ) ;
if ( ! F_7 ( V_14 -> V_28 ) ) {
error = - V_69 ;
goto V_68;
}
V_6 = F_25 ( V_33 , V_70 ) ;
if ( ! V_6 ) {
error = - V_71 ;
goto V_68;
}
V_60 = F_25 ( V_34 , V_70 ) ;
if ( ! V_60 ) {
error = - V_71 ;
goto V_68;
}
V_10 = F_22 ( V_41 ) ;
V_61 = & V_60 -> V_2 ;
F_26 ( V_61 , F_13 ) ;
V_61 -> V_10 = V_10 ;
V_60 -> V_6 = NULL ;
F_17 ( & V_38 -> V_39 ) ;
V_2 = F_16 ( V_38 , V_14 ) ;
if ( V_2 ) {
V_8 = F_2 ( V_2 , struct V_7 , V_2 ) ;
F_9 ( & V_2 -> V_9 ) ;
} else {
F_27 ( V_61 , V_38 , V_14 ,
NULL , 0 ) ;
F_9 ( & V_61 -> V_9 ) ;
V_2 = V_61 ;
V_8 = V_60 ;
V_61 = NULL ;
}
F_28 () ;
V_64 = F_29 ( V_57 ) ;
F_30 () ;
if ( V_64 != V_36 ) {
if ( V_8 == V_60 )
V_65 = 1 ;
goto V_72;
}
F_31 ( V_36 , F_32 ( V_62 ) , V_73 , 0 ) ;
error = F_23 ( V_6 , V_8 , V_37 , V_57 , V_36 , V_10 ) ;
if ( ! error )
V_6 = NULL ;
else if ( error == - V_59 )
error = 0 ;
F_1 ( V_2 ) ;
V_72:
F_12 ( & V_2 -> V_9 ) ;
if ( V_65 )
F_18 ( V_2 ) ;
F_19 ( & V_38 -> V_39 ) ;
if ( V_65 )
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
V_68:
if ( V_61 )
F_21 ( V_61 ) ;
if ( V_6 )
F_11 ( V_33 , V_6 ) ;
return error ;
}
static int T_4 F_33 ( void )
{
V_33 = F_34 ( V_5 , V_74 ) ;
V_34 = F_34 ( V_7 , V_74 ) ;
V_38 = F_35 ( & V_75 ) ;
if ( F_36 ( V_38 ) )
F_37 ( L_1 ) ;
return 0 ;
}
