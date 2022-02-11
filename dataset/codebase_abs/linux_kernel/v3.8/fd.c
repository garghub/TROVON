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
if ( V_9 -> V_19 -> V_20 )
V_7 = V_9 -> V_19 -> V_20 ( V_2 , V_9 ) ;
F_14 ( V_9 ) ;
}
return V_7 ;
}
static int F_15 ( struct V_21 * V_21 , struct V_9 * V_9 )
{
return F_16 ( V_9 , F_1 , V_21 ) ;
}
static int F_17 ( struct V_22 * V_22 , unsigned int V_23 )
{
struct V_4 * V_5 ;
struct V_10 * V_11 ;
const struct V_24 * V_24 ;
struct V_21 * V_21 ;
int V_13 ;
if ( V_23 & V_25 )
return - V_26 ;
V_21 = V_22 -> V_27 ;
V_11 = F_2 ( V_21 ) ;
V_13 = F_5 ( V_21 ) ;
if ( V_11 ) {
V_5 = F_3 ( V_11 ) ;
if ( V_5 ) {
struct V_9 * V_9 ;
F_18 () ;
V_9 = F_7 ( V_5 , V_13 ) ;
if ( V_9 ) {
unsigned V_28 = V_9 -> V_28 ;
F_19 () ;
F_12 ( V_5 ) ;
if ( F_20 ( V_11 ) ) {
F_18 () ;
V_24 = F_21 ( V_11 ) ;
V_21 -> V_29 = V_24 -> V_30 ;
V_21 -> V_31 = V_24 -> V_32 ;
F_19 () ;
} else {
V_21 -> V_29 = V_33 ;
V_21 -> V_31 = V_34 ;
}
if ( F_22 ( V_21 -> V_35 ) ) {
unsigned V_35 = V_36 ;
if ( V_28 & V_37 )
V_35 |= V_38 | V_39 ;
if ( V_28 & V_40 )
V_35 |= V_41 | V_39 ;
V_21 -> V_35 = V_35 ;
}
F_23 ( V_11 , V_21 ) ;
F_4 ( V_11 ) ;
return 1 ;
}
F_19 () ;
F_12 ( V_5 ) ;
}
F_4 ( V_11 ) ;
}
F_24 ( V_22 ) ;
return 0 ;
}
static int F_25 ( struct V_22 * V_22 , struct V_42 * V_42 )
{
struct V_4 * V_5 = NULL ;
struct V_10 * V_11 ;
int V_7 = - V_8 ;
V_11 = F_2 ( V_22 -> V_27 ) ;
if ( V_11 ) {
V_5 = F_3 ( V_11 ) ;
F_4 ( V_11 ) ;
}
if ( V_5 ) {
int V_13 = F_5 ( V_22 -> V_27 ) ;
struct V_9 * V_43 ;
F_6 ( & V_5 -> V_14 ) ;
V_43 = F_7 ( V_5 , V_13 ) ;
if ( V_43 ) {
* V_42 = V_43 -> V_44 ;
F_26 ( & V_43 -> V_44 ) ;
V_7 = 0 ;
}
F_11 ( & V_5 -> V_14 ) ;
F_12 ( V_5 ) ;
}
return V_7 ;
}
static struct V_22 *
F_27 ( struct V_21 * V_45 , struct V_22 * V_22 ,
struct V_10 * V_11 , const void * V_46 )
{
struct V_22 * error = F_28 ( - V_8 ) ;
unsigned V_13 = ( unsigned long ) V_46 ;
struct V_47 * V_48 ;
struct V_21 * V_21 ;
V_21 = F_29 ( V_45 -> V_49 , V_11 ) ;
if ( ! V_21 )
goto V_50;
V_48 = F_30 ( V_21 ) ;
V_48 -> V_13 = V_13 ;
V_21 -> V_35 = V_36 ;
V_21 -> V_51 = & V_52 ;
V_21 -> V_53 = 64 ;
V_48 -> V_54 . V_55 = F_25 ;
F_31 ( V_22 , & V_56 ) ;
F_32 ( V_22 , V_21 ) ;
if ( F_17 ( V_22 , 0 ) )
error = NULL ;
V_50:
return error ;
}
static struct V_22 * F_33 ( struct V_21 * V_45 ,
struct V_22 * V_22 ,
T_1 V_57 )
{
struct V_10 * V_11 = F_2 ( V_45 ) ;
struct V_22 * V_58 = F_28 ( - V_8 ) ;
unsigned V_13 = F_34 ( V_22 ) ;
if ( ! V_11 )
goto V_59;
if ( V_13 == ~ 0U )
goto V_50;
V_58 = V_57 ( V_45 , V_22 , V_11 , ( void * ) ( unsigned long ) V_13 ) ;
V_50:
F_4 ( V_11 ) ;
V_59:
return V_58 ;
}
static int F_35 ( struct V_9 * V_60 , void * V_61 ,
T_2 V_62 , T_1 V_57 )
{
struct V_22 * V_22 = V_60 -> V_44 . V_22 ;
struct V_21 * V_21 = V_22 -> V_27 ;
struct V_10 * V_63 = F_2 ( V_21 ) ;
struct V_4 * V_5 ;
unsigned int V_13 , V_64 ;
int V_65 ;
V_65 = - V_8 ;
if ( ! V_63 )
goto V_59;
V_65 = 0 ;
V_13 = V_60 -> V_18 ;
switch ( V_13 ) {
case 0 :
if ( V_62 ( V_61 , L_2 , 1 , 0 , V_21 -> V_66 , V_67 ) < 0 )
goto V_50;
V_60 -> V_18 ++ ;
case 1 :
V_64 = F_36 ( V_22 ) ;
if ( V_62 ( V_61 , L_3 , 2 , 1 , V_64 , V_67 ) < 0 )
goto V_50;
V_60 -> V_18 ++ ;
default:
V_5 = F_3 ( V_63 ) ;
if ( ! V_5 )
goto V_50;
F_18 () ;
for ( V_13 = V_60 -> V_18 - 2 ;
V_13 < F_8 ( V_5 ) -> V_68 ;
V_13 ++ , V_60 -> V_18 ++ ) {
char V_69 [ V_70 ] ;
int V_71 ;
int V_72 ;
if ( ! F_7 ( V_5 , V_13 ) )
continue;
F_19 () ;
V_71 = snprintf ( V_69 , sizeof( V_69 ) , L_4 , V_13 ) ;
V_72 = F_37 ( V_60 , V_61 , V_62 ,
V_69 , V_71 , V_57 , V_63 ,
( void * ) ( unsigned long ) V_13 ) ;
if ( V_72 < 0 )
goto V_73;
F_18 () ;
}
F_19 () ;
V_73:
F_12 ( V_5 ) ;
}
V_50:
F_4 ( V_63 ) ;
V_59:
return V_65 ;
}
static int F_38 ( struct V_9 * V_60 , void * V_61 , T_2 V_62 )
{
return F_35 ( V_60 , V_61 , V_62 , F_27 ) ;
}
static struct V_22 * F_39 ( struct V_21 * V_45 , struct V_22 * V_22 ,
unsigned int V_23 )
{
return F_33 ( V_45 , V_22 , F_27 ) ;
}
int F_40 ( struct V_21 * V_21 , int V_74 )
{
int V_72 = F_41 ( V_21 , V_74 ) ;
if ( V_72 == 0 )
return 0 ;
if ( F_42 ( V_75 ) == F_43 ( V_21 ) )
V_72 = 0 ;
return V_72 ;
}
static struct V_22 *
F_44 ( struct V_21 * V_45 , struct V_22 * V_22 ,
struct V_10 * V_11 , const void * V_46 )
{
struct V_22 * error = F_28 ( - V_8 ) ;
unsigned V_13 = ( unsigned long ) V_46 ;
struct V_47 * V_48 ;
struct V_21 * V_21 ;
V_21 = F_29 ( V_45 -> V_49 , V_11 ) ;
if ( ! V_21 )
goto V_50;
V_48 = F_30 ( V_21 ) ;
V_48 -> V_13 = V_13 ;
V_21 -> V_35 = V_76 | V_38 ;
V_21 -> V_77 = & V_78 ;
F_31 ( V_22 , & V_56 ) ;
F_32 ( V_22 , V_21 ) ;
if ( F_17 ( V_22 , 0 ) )
error = NULL ;
V_50:
return error ;
}
static struct V_22 *
F_45 ( struct V_21 * V_45 , struct V_22 * V_22 , unsigned int V_23 )
{
return F_33 ( V_45 , V_22 , F_44 ) ;
}
static int F_46 ( struct V_9 * V_60 , void * V_61 , T_2 V_62 )
{
return F_35 ( V_60 , V_61 , V_62 ,
F_44 ) ;
}
