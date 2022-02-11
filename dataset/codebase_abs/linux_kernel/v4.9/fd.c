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
const struct V_28 * V_28 ;
struct V_25 * V_25 ;
unsigned int V_13 ;
if ( V_27 & V_29 )
return - V_30 ;
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
unsigned V_31 = V_9 -> V_31 ;
F_23 () ;
F_12 ( V_5 ) ;
if ( F_24 ( V_11 ) ) {
F_22 () ;
V_28 = F_25 ( V_11 ) ;
V_25 -> V_32 = V_28 -> V_33 ;
V_25 -> V_34 = V_28 -> V_35 ;
F_23 () ;
} else {
V_25 -> V_32 = V_36 ;
V_25 -> V_34 = V_37 ;
}
if ( F_26 ( V_25 -> V_38 ) ) {
unsigned V_38 = V_39 ;
if ( V_31 & V_40 )
V_38 |= V_41 | V_42 ;
if ( V_31 & V_43 )
V_38 |= V_44 | V_42 ;
V_25 -> V_38 = V_38 ;
}
F_27 ( V_11 , V_25 ) ;
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
static int F_28 ( struct V_26 * V_26 , struct V_45 * V_45 )
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
struct V_9 * V_46 ;
F_6 ( & V_5 -> V_14 ) ;
V_46 = F_7 ( V_5 , V_13 ) ;
if ( V_46 ) {
* V_45 = V_46 -> V_19 ;
F_29 ( & V_46 -> V_19 ) ;
V_7 = 0 ;
}
F_11 ( & V_5 -> V_14 ) ;
F_12 ( V_5 ) ;
}
return V_7 ;
}
static int
F_30 ( struct V_25 * V_47 , struct V_26 * V_26 ,
struct V_10 * V_11 , const void * V_48 )
{
unsigned V_13 = ( unsigned long ) V_48 ;
struct V_49 * V_50 ;
struct V_25 * V_25 ;
V_25 = F_31 ( V_47 -> V_51 , V_11 ) ;
if ( ! V_25 )
goto V_22;
V_50 = F_32 ( V_25 ) ;
V_50 -> V_13 = V_13 ;
V_25 -> V_38 = V_39 ;
V_25 -> V_52 = & V_53 ;
V_25 -> V_54 = 64 ;
V_50 -> V_55 . V_56 = F_28 ;
F_33 ( V_26 , & V_57 ) ;
F_34 ( V_26 , V_25 ) ;
if ( F_20 ( V_26 , 0 ) )
return 0 ;
V_22:
return - V_8 ;
}
static struct V_26 * F_35 ( struct V_25 * V_47 ,
struct V_26 * V_26 ,
T_1 V_58 )
{
struct V_10 * V_11 = F_2 ( V_47 ) ;
int V_59 = - V_8 ;
unsigned V_13 = F_36 ( & V_26 -> V_60 ) ;
if ( ! V_11 )
goto V_61;
if ( V_13 == ~ 0U )
goto V_22;
V_59 = V_58 ( V_47 , V_26 , V_11 , ( void * ) ( unsigned long ) V_13 ) ;
V_22:
F_4 ( V_11 ) ;
V_61:
return F_37 ( V_59 ) ;
}
static int F_38 ( struct V_9 * V_9 , struct V_62 * V_63 ,
T_1 V_58 )
{
struct V_10 * V_64 = F_2 ( F_39 ( V_9 ) ) ;
struct V_4 * V_5 ;
unsigned int V_13 ;
if ( ! V_64 )
return - V_8 ;
if ( ! F_40 ( V_9 , V_63 ) )
goto V_22;
V_5 = F_3 ( V_64 ) ;
if ( ! V_5 )
goto V_22;
F_22 () ;
for ( V_13 = V_63 -> V_65 - 2 ;
V_13 < F_8 ( V_5 ) -> V_66 ;
V_13 ++ , V_63 -> V_65 ++ ) {
char V_67 [ V_68 ] ;
int V_69 ;
if ( ! F_7 ( V_5 , V_13 ) )
continue;
F_23 () ;
V_69 = snprintf ( V_67 , sizeof( V_67 ) , L_2 , V_13 ) ;
if ( ! F_41 ( V_9 , V_63 ,
V_67 , V_69 , V_58 , V_64 ,
( void * ) ( unsigned long ) V_13 ) )
goto V_70;
F_42 () ;
F_22 () ;
}
F_23 () ;
V_70:
F_12 ( V_5 ) ;
V_22:
F_4 ( V_64 ) ;
return 0 ;
}
static int F_43 ( struct V_9 * V_9 , struct V_62 * V_63 )
{
return F_38 ( V_9 , V_63 , F_30 ) ;
}
static struct V_26 * F_44 ( struct V_25 * V_47 , struct V_26 * V_26 ,
unsigned int V_27 )
{
return F_35 ( V_47 , V_26 , F_30 ) ;
}
int F_45 ( struct V_25 * V_25 , int V_71 )
{
struct V_10 * V_64 ;
int V_72 ;
V_72 = F_46 ( V_25 , V_71 ) ;
if ( V_72 == 0 )
return V_72 ;
F_22 () ;
V_64 = F_47 ( F_48 ( V_25 ) , V_73 ) ;
if ( V_64 && F_49 ( V_64 , V_74 ) )
V_72 = 0 ;
F_23 () ;
return V_72 ;
}
static int
F_50 ( struct V_25 * V_47 , struct V_26 * V_26 ,
struct V_10 * V_11 , const void * V_48 )
{
unsigned V_13 = ( unsigned long ) V_48 ;
struct V_49 * V_50 ;
struct V_25 * V_25 ;
V_25 = F_31 ( V_47 -> V_51 , V_11 ) ;
if ( ! V_25 )
goto V_22;
V_50 = F_32 ( V_25 ) ;
V_50 -> V_13 = V_13 ;
V_25 -> V_38 = V_75 | V_41 ;
V_25 -> V_76 = & V_77 ;
F_33 ( V_26 , & V_57 ) ;
F_34 ( V_26 , V_25 ) ;
if ( F_20 ( V_26 , 0 ) )
return 0 ;
V_22:
return - V_8 ;
}
static struct V_26 *
F_51 ( struct V_25 * V_47 , struct V_26 * V_26 , unsigned int V_27 )
{
return F_35 ( V_47 , V_26 , F_50 ) ;
}
static int F_52 ( struct V_9 * V_9 , struct V_62 * V_63 )
{
return F_38 ( V_9 , V_63 ,
F_50 ) ;
}
