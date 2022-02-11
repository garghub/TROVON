static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = NULL ;
int V_6 = 0 , V_7 = - V_8 ;
struct V_9 * V_9 = NULL ;
struct V_10 * V_11 ;
V_11 = F_2 ( V_2 -> V_12 ) ;
if ( ! V_11 )
return - V_8 ;
V_5 = F_3 ( V_11 ) ;
F_4 ( V_11 ) ;
if ( V_5 ) {
int V_13 = F_5 ( V_2 -> V_12 ) ;
F_6 ( & V_5 -> V_14 ) ;
V_9 = F_7 ( V_5 , V_13 ) ;
if ( V_9 ) {
struct V_15 * V_16 = F_8 ( V_5 ) ;
V_6 = V_9 -> V_6 ;
if ( F_9 ( V_13 , V_16 ) )
V_6 |= V_17 ;
F_10 ( V_9 ) ;
V_7 = 0 ;
}
F_11 ( & V_5 -> V_14 ) ;
F_12 ( V_5 ) ;
}
if ( ! V_7 ) {
F_13 ( V_2 , L_1 ,
( long long ) V_9 -> V_18 , V_6 ) ;
F_14 ( V_9 ) ;
}
return V_7 ;
}
static int F_15 ( struct V_19 * V_19 , struct V_9 * V_9 )
{
return F_16 ( V_9 , F_1 , V_19 ) ;
}
static int F_17 ( struct V_20 * V_20 , unsigned int V_21 )
{
struct V_4 * V_5 ;
struct V_10 * V_11 ;
const struct V_22 * V_22 ;
struct V_19 * V_19 ;
int V_13 ;
if ( V_21 & V_23 )
return - V_24 ;
V_19 = V_20 -> V_25 ;
V_11 = F_2 ( V_19 ) ;
V_13 = F_5 ( V_19 ) ;
if ( V_11 ) {
V_5 = F_3 ( V_11 ) ;
if ( V_5 ) {
struct V_9 * V_9 ;
F_18 () ;
V_9 = F_7 ( V_5 , V_13 ) ;
if ( V_9 ) {
unsigned V_26 = V_9 -> V_26 ;
F_19 () ;
F_12 ( V_5 ) ;
if ( F_20 ( V_11 ) ) {
F_18 () ;
V_22 = F_21 ( V_11 ) ;
V_19 -> V_27 = V_22 -> V_28 ;
V_19 -> V_29 = V_22 -> V_30 ;
F_19 () ;
} else {
V_19 -> V_27 = V_31 ;
V_19 -> V_29 = V_32 ;
}
if ( F_22 ( V_19 -> V_33 ) ) {
unsigned V_33 = V_34 ;
if ( V_26 & V_35 )
V_33 |= V_36 | V_37 ;
if ( V_26 & V_38 )
V_33 |= V_39 | V_37 ;
V_19 -> V_33 = V_33 ;
}
F_23 ( V_11 , V_19 ) ;
F_4 ( V_11 ) ;
return 1 ;
}
F_19 () ;
F_12 ( V_5 ) ;
}
F_4 ( V_11 ) ;
}
F_24 ( V_20 ) ;
return 0 ;
}
static int F_25 ( struct V_20 * V_20 , struct V_40 * V_40 )
{
struct V_4 * V_5 = NULL ;
struct V_10 * V_11 ;
int V_7 = - V_8 ;
V_11 = F_2 ( V_20 -> V_25 ) ;
if ( V_11 ) {
V_5 = F_3 ( V_11 ) ;
F_4 ( V_11 ) ;
}
if ( V_5 ) {
int V_13 = F_5 ( V_20 -> V_25 ) ;
struct V_9 * V_41 ;
F_6 ( & V_5 -> V_14 ) ;
V_41 = F_7 ( V_5 , V_13 ) ;
if ( V_41 ) {
* V_40 = V_41 -> V_42 ;
F_26 ( & V_41 -> V_42 ) ;
V_7 = 0 ;
}
F_11 ( & V_5 -> V_14 ) ;
F_12 ( V_5 ) ;
}
return V_7 ;
}
static struct V_20 *
F_27 ( struct V_19 * V_43 , struct V_20 * V_20 ,
struct V_10 * V_11 , const void * V_44 )
{
struct V_20 * error = F_28 ( - V_8 ) ;
unsigned V_13 = ( unsigned long ) V_44 ;
struct V_45 * V_46 ;
struct V_19 * V_19 ;
V_19 = F_29 ( V_43 -> V_47 , V_11 ) ;
if ( ! V_19 )
goto V_48;
V_46 = F_30 ( V_19 ) ;
V_46 -> V_13 = V_13 ;
V_19 -> V_33 = V_34 ;
V_19 -> V_49 = & V_50 ;
V_19 -> V_51 = 64 ;
V_46 -> V_52 . V_53 = F_25 ;
F_31 ( V_20 , & V_54 ) ;
F_32 ( V_20 , V_19 ) ;
if ( F_17 ( V_20 , 0 ) )
error = NULL ;
V_48:
return error ;
}
static struct V_20 * F_33 ( struct V_19 * V_43 ,
struct V_20 * V_20 ,
T_1 V_55 )
{
struct V_10 * V_11 = F_2 ( V_43 ) ;
struct V_20 * V_56 = F_28 ( - V_8 ) ;
unsigned V_13 = F_34 ( V_20 ) ;
if ( ! V_11 )
goto V_57;
if ( V_13 == ~ 0U )
goto V_48;
V_56 = V_55 ( V_43 , V_20 , V_11 , ( void * ) ( unsigned long ) V_13 ) ;
V_48:
F_4 ( V_11 ) ;
V_57:
return V_56 ;
}
static int F_35 ( struct V_9 * V_58 , void * V_59 ,
T_2 V_60 , T_1 V_55 )
{
struct V_20 * V_20 = V_58 -> V_42 . V_20 ;
struct V_19 * V_19 = V_20 -> V_25 ;
struct V_10 * V_61 = F_2 ( V_19 ) ;
struct V_4 * V_5 ;
unsigned int V_13 , V_62 ;
int V_63 ;
V_63 = - V_8 ;
if ( ! V_61 )
goto V_57;
V_63 = 0 ;
V_13 = V_58 -> V_18 ;
switch ( V_13 ) {
case 0 :
if ( V_60 ( V_59 , L_2 , 1 , 0 , V_19 -> V_64 , V_65 ) < 0 )
goto V_48;
V_58 -> V_18 ++ ;
case 1 :
V_62 = F_36 ( V_20 ) ;
if ( V_60 ( V_59 , L_3 , 2 , 1 , V_62 , V_65 ) < 0 )
goto V_48;
V_58 -> V_18 ++ ;
default:
V_5 = F_3 ( V_61 ) ;
if ( ! V_5 )
goto V_48;
F_18 () ;
for ( V_13 = V_58 -> V_18 - 2 ;
V_13 < F_8 ( V_5 ) -> V_66 ;
V_13 ++ , V_58 -> V_18 ++ ) {
char V_67 [ V_68 ] ;
int V_69 ;
int V_70 ;
if ( ! F_7 ( V_5 , V_13 ) )
continue;
F_19 () ;
V_69 = snprintf ( V_67 , sizeof( V_67 ) , L_4 , V_13 ) ;
V_70 = F_37 ( V_58 , V_59 , V_60 ,
V_67 , V_69 , V_55 , V_61 ,
( void * ) ( unsigned long ) V_13 ) ;
if ( V_70 < 0 )
goto V_71;
F_18 () ;
}
F_19 () ;
V_71:
F_12 ( V_5 ) ;
}
V_48:
F_4 ( V_61 ) ;
V_57:
return V_63 ;
}
static int F_38 ( struct V_9 * V_58 , void * V_59 , T_2 V_60 )
{
return F_35 ( V_58 , V_59 , V_60 , F_27 ) ;
}
static struct V_20 * F_39 ( struct V_19 * V_43 , struct V_20 * V_20 ,
unsigned int V_21 )
{
return F_33 ( V_43 , V_20 , F_27 ) ;
}
int F_40 ( struct V_19 * V_19 , int V_72 )
{
int V_70 = F_41 ( V_19 , V_72 ) ;
if ( V_70 == 0 )
return 0 ;
if ( F_42 ( V_73 ) == F_43 ( V_19 ) )
V_70 = 0 ;
return V_70 ;
}
static struct V_20 *
F_44 ( struct V_19 * V_43 , struct V_20 * V_20 ,
struct V_10 * V_11 , const void * V_44 )
{
struct V_20 * error = F_28 ( - V_8 ) ;
unsigned V_13 = ( unsigned long ) V_44 ;
struct V_45 * V_46 ;
struct V_19 * V_19 ;
V_19 = F_29 ( V_43 -> V_47 , V_11 ) ;
if ( ! V_19 )
goto V_48;
V_46 = F_30 ( V_19 ) ;
V_46 -> V_13 = V_13 ;
V_19 -> V_33 = V_74 | V_36 ;
V_19 -> V_75 = & V_76 ;
F_31 ( V_20 , & V_54 ) ;
F_32 ( V_20 , V_19 ) ;
if ( F_17 ( V_20 , 0 ) )
error = NULL ;
V_48:
return error ;
}
static struct V_20 *
F_45 ( struct V_19 * V_43 , struct V_20 * V_20 , unsigned int V_21 )
{
return F_33 ( V_43 , V_20 , F_44 ) ;
}
static int F_46 ( struct V_9 * V_58 , void * V_59 , T_2 V_60 )
{
return F_35 ( V_58 , V_59 , V_60 ,
F_44 ) ;
}
