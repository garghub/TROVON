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
( long long ) V_9 -> V_18 , V_6 ,
F_14 ( V_9 -> V_19 . V_20 ) -> V_21 ) ;
if ( V_9 -> V_22 -> V_23 )
V_9 -> V_22 -> V_23 ( V_2 , V_9 ) ;
V_7 = F_15 ( V_2 ) ;
F_16 ( V_9 ) ;
}
return V_7 ;
}
static int F_17 ( struct V_24 * V_24 , struct V_9 * V_9 )
{
return F_18 ( V_9 , F_1 , V_24 ) ;
}
static int F_19 ( struct V_25 * V_25 , unsigned int V_26 )
{
struct V_4 * V_5 ;
struct V_10 * V_11 ;
const struct V_27 * V_27 ;
struct V_24 * V_24 ;
int V_13 ;
if ( V_26 & V_28 )
return - V_29 ;
V_24 = V_25 -> V_30 ;
V_11 = F_2 ( V_24 ) ;
V_13 = F_5 ( V_24 ) ;
if ( V_11 ) {
V_5 = F_3 ( V_11 ) ;
if ( V_5 ) {
struct V_9 * V_9 ;
F_20 () ;
V_9 = F_7 ( V_5 , V_13 ) ;
if ( V_9 ) {
unsigned V_31 = V_9 -> V_31 ;
F_21 () ;
F_12 ( V_5 ) ;
if ( F_22 ( V_11 ) ) {
F_20 () ;
V_27 = F_23 ( V_11 ) ;
V_24 -> V_32 = V_27 -> V_33 ;
V_24 -> V_34 = V_27 -> V_35 ;
F_21 () ;
} else {
V_24 -> V_32 = V_36 ;
V_24 -> V_34 = V_37 ;
}
if ( F_24 ( V_24 -> V_38 ) ) {
unsigned V_38 = V_39 ;
if ( V_31 & V_40 )
V_38 |= V_41 | V_42 ;
if ( V_31 & V_43 )
V_38 |= V_44 | V_42 ;
V_24 -> V_38 = V_38 ;
}
F_25 ( V_11 , V_24 ) ;
F_4 ( V_11 ) ;
return 1 ;
}
F_21 () ;
F_12 ( V_5 ) ;
}
F_4 ( V_11 ) ;
}
return 0 ;
}
static int F_26 ( struct V_25 * V_25 , struct V_45 * V_45 )
{
struct V_4 * V_5 = NULL ;
struct V_10 * V_11 ;
int V_7 = - V_8 ;
V_11 = F_2 ( V_25 -> V_30 ) ;
if ( V_11 ) {
V_5 = F_3 ( V_11 ) ;
F_4 ( V_11 ) ;
}
if ( V_5 ) {
int V_13 = F_5 ( V_25 -> V_30 ) ;
struct V_9 * V_46 ;
F_6 ( & V_5 -> V_14 ) ;
V_46 = F_7 ( V_5 , V_13 ) ;
if ( V_46 ) {
* V_45 = V_46 -> V_19 ;
F_27 ( & V_46 -> V_19 ) ;
V_7 = 0 ;
}
F_11 ( & V_5 -> V_14 ) ;
F_12 ( V_5 ) ;
}
return V_7 ;
}
static int
F_28 ( struct V_24 * V_47 , struct V_25 * V_25 ,
struct V_10 * V_11 , const void * V_48 )
{
unsigned V_13 = ( unsigned long ) V_48 ;
struct V_49 * V_50 ;
struct V_24 * V_24 ;
V_24 = F_29 ( V_47 -> V_51 , V_11 ) ;
if ( ! V_24 )
goto V_52;
V_50 = F_30 ( V_24 ) ;
V_50 -> V_13 = V_13 ;
V_24 -> V_38 = V_39 ;
V_24 -> V_53 = & V_54 ;
V_24 -> V_55 = 64 ;
V_50 -> V_56 . V_57 = F_26 ;
F_31 ( V_25 , & V_58 ) ;
F_32 ( V_25 , V_24 ) ;
if ( F_19 ( V_25 , 0 ) )
return 0 ;
V_52:
return - V_8 ;
}
static struct V_25 * F_33 ( struct V_24 * V_47 ,
struct V_25 * V_25 ,
T_1 V_59 )
{
struct V_10 * V_11 = F_2 ( V_47 ) ;
int V_60 = - V_8 ;
unsigned V_13 = F_34 ( & V_25 -> V_61 ) ;
if ( ! V_11 )
goto V_62;
if ( V_13 == ~ 0U )
goto V_52;
V_60 = V_59 ( V_47 , V_25 , V_11 , ( void * ) ( unsigned long ) V_13 ) ;
V_52:
F_4 ( V_11 ) ;
V_62:
return F_35 ( V_60 ) ;
}
static int F_36 ( struct V_9 * V_9 , struct V_63 * V_64 ,
T_1 V_59 )
{
struct V_10 * V_65 = F_2 ( F_37 ( V_9 ) ) ;
struct V_4 * V_5 ;
unsigned int V_13 ;
if ( ! V_65 )
return - V_8 ;
if ( ! F_38 ( V_9 , V_64 ) )
goto V_52;
V_5 = F_3 ( V_65 ) ;
if ( ! V_5 )
goto V_52;
F_20 () ;
for ( V_13 = V_64 -> V_66 - 2 ;
V_13 < F_8 ( V_5 ) -> V_67 ;
V_13 ++ , V_64 -> V_66 ++ ) {
char V_68 [ V_69 ] ;
int V_70 ;
if ( ! F_7 ( V_5 , V_13 ) )
continue;
F_21 () ;
V_70 = snprintf ( V_68 , sizeof( V_68 ) , L_2 , V_13 ) ;
if ( ! F_39 ( V_9 , V_64 ,
V_68 , V_70 , V_59 , V_65 ,
( void * ) ( unsigned long ) V_13 ) )
goto V_71;
F_20 () ;
}
F_21 () ;
V_71:
F_12 ( V_5 ) ;
V_52:
F_4 ( V_65 ) ;
return 0 ;
}
static int F_40 ( struct V_9 * V_9 , struct V_63 * V_64 )
{
return F_36 ( V_9 , V_64 , F_28 ) ;
}
static struct V_25 * F_41 ( struct V_24 * V_47 , struct V_25 * V_25 ,
unsigned int V_26 )
{
return F_33 ( V_47 , V_25 , F_28 ) ;
}
int F_42 ( struct V_24 * V_24 , int V_72 )
{
int V_73 = F_43 ( V_24 , V_72 ) ;
if ( V_73 == 0 )
return 0 ;
if ( F_44 ( V_74 ) == F_45 ( V_24 ) )
V_73 = 0 ;
return V_73 ;
}
static int
F_46 ( struct V_24 * V_47 , struct V_25 * V_25 ,
struct V_10 * V_11 , const void * V_48 )
{
unsigned V_13 = ( unsigned long ) V_48 ;
struct V_49 * V_50 ;
struct V_24 * V_24 ;
V_24 = F_29 ( V_47 -> V_51 , V_11 ) ;
if ( ! V_24 )
goto V_52;
V_50 = F_30 ( V_24 ) ;
V_50 -> V_13 = V_13 ;
V_24 -> V_38 = V_75 | V_41 ;
V_24 -> V_76 = & V_77 ;
F_31 ( V_25 , & V_58 ) ;
F_32 ( V_25 , V_24 ) ;
if ( F_19 ( V_25 , 0 ) )
return 0 ;
V_52:
return - V_8 ;
}
static struct V_25 *
F_47 ( struct V_24 * V_47 , struct V_25 * V_25 , unsigned int V_26 )
{
return F_33 ( V_47 , V_25 , F_46 ) ;
}
static int F_48 ( struct V_9 * V_9 , struct V_63 * V_64 )
{
return F_36 ( V_9 , V_64 ,
F_46 ) ;
}
