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
static int
F_27 ( struct V_21 * V_45 , struct V_22 * V_22 ,
struct V_10 * V_11 , const void * V_46 )
{
unsigned V_13 = ( unsigned long ) V_46 ;
struct V_47 * V_48 ;
struct V_21 * V_21 ;
V_21 = F_28 ( V_45 -> V_49 , V_11 ) ;
if ( ! V_21 )
goto V_50;
V_48 = F_29 ( V_21 ) ;
V_48 -> V_13 = V_13 ;
V_21 -> V_35 = V_36 ;
V_21 -> V_51 = & V_52 ;
V_21 -> V_53 = 64 ;
V_48 -> V_54 . V_55 = F_25 ;
F_30 ( V_22 , & V_56 ) ;
F_31 ( V_22 , V_21 ) ;
if ( F_17 ( V_22 , 0 ) )
return 0 ;
V_50:
return - V_8 ;
}
static struct V_22 * F_32 ( struct V_21 * V_45 ,
struct V_22 * V_22 ,
T_1 V_57 )
{
struct V_10 * V_11 = F_2 ( V_45 ) ;
int V_58 = - V_8 ;
unsigned V_13 = F_33 ( V_22 ) ;
if ( ! V_11 )
goto V_59;
if ( V_13 == ~ 0U )
goto V_50;
V_58 = V_57 ( V_45 , V_22 , V_11 , ( void * ) ( unsigned long ) V_13 ) ;
V_50:
F_4 ( V_11 ) ;
V_59:
return F_34 ( V_58 ) ;
}
static int F_35 ( struct V_9 * V_9 , struct V_60 * V_61 ,
T_1 V_57 )
{
struct V_10 * V_62 = F_2 ( F_36 ( V_9 ) ) ;
struct V_4 * V_5 ;
unsigned int V_13 ;
if ( ! V_62 )
return - V_8 ;
if ( ! F_37 ( V_9 , V_61 ) )
goto V_50;
V_5 = F_3 ( V_62 ) ;
if ( ! V_5 )
goto V_50;
F_18 () ;
for ( V_13 = V_61 -> V_63 - 2 ;
V_13 < F_8 ( V_5 ) -> V_64 ;
V_13 ++ , V_61 -> V_63 ++ ) {
char V_65 [ V_66 ] ;
int V_67 ;
if ( ! F_7 ( V_5 , V_13 ) )
continue;
F_19 () ;
V_67 = snprintf ( V_65 , sizeof( V_65 ) , L_2 , V_13 ) ;
if ( ! F_38 ( V_9 , V_61 ,
V_65 , V_67 , V_57 , V_62 ,
( void * ) ( unsigned long ) V_13 ) )
goto V_68;
F_18 () ;
}
F_19 () ;
V_68:
F_12 ( V_5 ) ;
V_50:
F_4 ( V_62 ) ;
return 0 ;
}
static int F_39 ( struct V_9 * V_9 , struct V_60 * V_61 )
{
return F_35 ( V_9 , V_61 , F_27 ) ;
}
static struct V_22 * F_40 ( struct V_21 * V_45 , struct V_22 * V_22 ,
unsigned int V_23 )
{
return F_32 ( V_45 , V_22 , F_27 ) ;
}
int F_41 ( struct V_21 * V_21 , int V_69 )
{
int V_70 = F_42 ( V_21 , V_69 ) ;
if ( V_70 == 0 )
return 0 ;
if ( F_43 ( V_71 ) == F_44 ( V_21 ) )
V_70 = 0 ;
return V_70 ;
}
static int
F_45 ( struct V_21 * V_45 , struct V_22 * V_22 ,
struct V_10 * V_11 , const void * V_46 )
{
unsigned V_13 = ( unsigned long ) V_46 ;
struct V_47 * V_48 ;
struct V_21 * V_21 ;
V_21 = F_28 ( V_45 -> V_49 , V_11 ) ;
if ( ! V_21 )
goto V_50;
V_48 = F_29 ( V_21 ) ;
V_48 -> V_13 = V_13 ;
V_21 -> V_35 = V_72 | V_38 ;
V_21 -> V_73 = & V_74 ;
F_30 ( V_22 , & V_56 ) ;
F_31 ( V_22 , V_21 ) ;
if ( F_17 ( V_22 , 0 ) )
return 0 ;
V_50:
return - V_8 ;
}
static struct V_22 *
F_46 ( struct V_21 * V_45 , struct V_22 * V_22 , unsigned int V_23 )
{
return F_32 ( V_45 , V_22 , F_45 ) ;
}
static int F_47 ( struct V_9 * V_9 , struct V_60 * V_61 )
{
return F_35 ( V_9 , V_61 ,
F_45 ) ;
}
