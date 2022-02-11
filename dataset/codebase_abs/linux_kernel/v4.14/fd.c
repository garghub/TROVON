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
unsigned int V_13 = F_5 ( V_2 -> V_12 ) ;
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
if ( V_7 )
return V_7 ;
F_13 ( V_2 , L_1 ,
( long long ) V_9 -> V_18 , V_6 ,
F_14 ( V_9 -> V_19 . V_20 ) -> V_21 ) ;
F_15 ( V_2 , V_9 , V_5 ) ;
if ( F_16 ( V_2 ) )
goto V_22;
if ( V_9 -> V_23 -> V_24 )
V_9 -> V_23 -> V_24 ( V_2 , V_9 ) ;
V_22:
F_17 ( V_9 ) ;
return 0 ;
}
static int F_18 ( struct V_25 * V_25 , struct V_9 * V_9 )
{
return F_19 ( V_9 , F_1 , V_25 ) ;
}
static int F_20 ( struct V_26 * V_26 , unsigned int V_27 )
{
struct V_4 * V_5 ;
struct V_10 * V_11 ;
struct V_25 * V_25 ;
unsigned int V_13 ;
if ( V_27 & V_28 )
return - V_29 ;
V_25 = F_21 ( V_26 ) ;
V_11 = F_2 ( V_25 ) ;
V_13 = F_5 ( V_25 ) ;
if ( V_11 ) {
V_5 = F_3 ( V_11 ) ;
if ( V_5 ) {
struct V_9 * V_9 ;
F_22 () ;
V_9 = F_7 ( V_5 , V_13 ) ;
if ( V_9 ) {
unsigned V_30 = V_9 -> V_30 ;
F_23 () ;
F_12 ( V_5 ) ;
F_24 ( V_11 , 0 , & V_25 -> V_31 , & V_25 -> V_32 ) ;
if ( F_25 ( V_25 -> V_33 ) ) {
unsigned V_33 = V_34 ;
if ( V_30 & V_35 )
V_33 |= V_36 | V_37 ;
if ( V_30 & V_38 )
V_33 |= V_39 | V_37 ;
V_25 -> V_33 = V_33 ;
}
F_26 ( V_11 , V_25 ) ;
F_4 ( V_11 ) ;
return 1 ;
}
F_23 () ;
F_12 ( V_5 ) ;
}
F_4 ( V_11 ) ;
}
return 0 ;
}
static int F_27 ( struct V_26 * V_26 , struct V_40 * V_40 )
{
struct V_4 * V_5 = NULL ;
struct V_10 * V_11 ;
int V_7 = - V_8 ;
V_11 = F_2 ( F_21 ( V_26 ) ) ;
if ( V_11 ) {
V_5 = F_3 ( V_11 ) ;
F_4 ( V_11 ) ;
}
if ( V_5 ) {
unsigned int V_13 = F_5 ( F_21 ( V_26 ) ) ;
struct V_9 * V_41 ;
F_6 ( & V_5 -> V_14 ) ;
V_41 = F_7 ( V_5 , V_13 ) ;
if ( V_41 ) {
* V_40 = V_41 -> V_19 ;
F_28 ( & V_41 -> V_19 ) ;
V_7 = 0 ;
}
F_11 ( & V_5 -> V_14 ) ;
F_12 ( V_5 ) ;
}
return V_7 ;
}
static int
F_29 ( struct V_25 * V_42 , struct V_26 * V_26 ,
struct V_10 * V_11 , const void * V_43 )
{
unsigned V_13 = ( unsigned long ) V_43 ;
struct V_44 * V_45 ;
struct V_25 * V_25 ;
V_25 = F_30 ( V_42 -> V_46 , V_11 , V_34 ) ;
if ( ! V_25 )
goto V_22;
V_45 = F_31 ( V_25 ) ;
V_45 -> V_13 = V_13 ;
V_25 -> V_47 = & V_48 ;
V_25 -> V_49 = 64 ;
V_45 -> V_50 . V_51 = F_27 ;
F_32 ( V_26 , & V_52 ) ;
F_33 ( V_26 , V_25 ) ;
if ( F_20 ( V_26 , 0 ) )
return 0 ;
V_22:
return - V_8 ;
}
static struct V_26 * F_34 ( struct V_25 * V_42 ,
struct V_26 * V_26 ,
T_1 V_53 )
{
struct V_10 * V_11 = F_2 ( V_42 ) ;
int V_54 = - V_8 ;
unsigned V_13 = F_35 ( & V_26 -> V_55 ) ;
if ( ! V_11 )
goto V_56;
if ( V_13 == ~ 0U )
goto V_22;
V_54 = V_53 ( V_42 , V_26 , V_11 , ( void * ) ( unsigned long ) V_13 ) ;
V_22:
F_4 ( V_11 ) ;
V_56:
return F_36 ( V_54 ) ;
}
static int F_37 ( struct V_9 * V_9 , struct V_57 * V_58 ,
T_1 V_53 )
{
struct V_10 * V_59 = F_2 ( F_38 ( V_9 ) ) ;
struct V_4 * V_5 ;
unsigned int V_13 ;
if ( ! V_59 )
return - V_8 ;
if ( ! F_39 ( V_9 , V_58 ) )
goto V_22;
V_5 = F_3 ( V_59 ) ;
if ( ! V_5 )
goto V_22;
F_22 () ;
for ( V_13 = V_58 -> V_60 - 2 ;
V_13 < F_8 ( V_5 ) -> V_61 ;
V_13 ++ , V_58 -> V_60 ++ ) {
char V_62 [ V_63 ] ;
int V_64 ;
if ( ! F_7 ( V_5 , V_13 ) )
continue;
F_23 () ;
V_64 = snprintf ( V_62 , sizeof( V_62 ) , L_2 , V_13 ) ;
if ( ! F_40 ( V_9 , V_58 ,
V_62 , V_64 , V_53 , V_59 ,
( void * ) ( unsigned long ) V_13 ) )
goto V_65;
F_41 () ;
F_22 () ;
}
F_23 () ;
V_65:
F_12 ( V_5 ) ;
V_22:
F_4 ( V_59 ) ;
return 0 ;
}
static int F_42 ( struct V_9 * V_9 , struct V_57 * V_58 )
{
return F_37 ( V_9 , V_58 , F_29 ) ;
}
static struct V_26 * F_43 ( struct V_25 * V_42 , struct V_26 * V_26 ,
unsigned int V_27 )
{
return F_34 ( V_42 , V_26 , F_29 ) ;
}
int F_44 ( struct V_25 * V_25 , int V_66 )
{
struct V_10 * V_59 ;
int V_67 ;
V_67 = F_45 ( V_25 , V_66 ) ;
if ( V_67 == 0 )
return V_67 ;
F_22 () ;
V_59 = F_46 ( F_47 ( V_25 ) , V_68 ) ;
if ( V_59 && F_48 ( V_59 , V_69 ) )
V_67 = 0 ;
F_23 () ;
return V_67 ;
}
static int
F_49 ( struct V_25 * V_42 , struct V_26 * V_26 ,
struct V_10 * V_11 , const void * V_43 )
{
unsigned V_13 = ( unsigned long ) V_43 ;
struct V_44 * V_45 ;
struct V_25 * V_25 ;
V_25 = F_30 ( V_42 -> V_46 , V_11 , V_70 | V_36 ) ;
if ( ! V_25 )
goto V_22;
V_45 = F_31 ( V_25 ) ;
V_45 -> V_13 = V_13 ;
V_25 -> V_71 = & V_72 ;
F_32 ( V_26 , & V_52 ) ;
F_33 ( V_26 , V_25 ) ;
if ( F_20 ( V_26 , 0 ) )
return 0 ;
V_22:
return - V_8 ;
}
static struct V_26 *
F_50 ( struct V_25 * V_42 , struct V_26 * V_26 , unsigned int V_27 )
{
return F_34 ( V_42 , V_26 , F_49 ) ;
}
static int F_51 ( struct V_9 * V_9 , struct V_57 * V_58 )
{
return F_37 ( V_9 , V_58 ,
F_49 ) ;
}
