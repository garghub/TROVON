__weak void T_1 * F_1 ( T_2 V_1 , unsigned long V_2 )
{
return F_2 ( V_1 , V_2 ) ;
}
static void * F_3 ( T_2 V_1 , T_3 V_2 )
{
unsigned long V_3 = F_4 ( V_1 ) ;
if ( F_5 ( V_3 ) && ! F_6 ( F_7 ( V_3 ) ) )
return F_8 ( V_1 ) ;
return NULL ;
}
void * F_9 ( T_2 V_1 , T_3 V_2 , unsigned long V_4 )
{
int V_5 = F_10 ( V_1 , V_2 , L_1 ) ;
void * V_6 = NULL ;
if ( V_5 == V_7 ) {
F_11 ( 1 , L_2 ,
& V_1 , ( unsigned long ) V_2 ) ;
return NULL ;
}
if ( V_4 & V_8 ) {
V_4 &= ~ V_8 ;
if ( V_5 == V_9 )
V_6 = F_3 ( V_1 , V_2 ) ;
if ( ! V_6 )
V_6 = F_1 ( V_1 , V_2 ) ;
}
if ( ! V_6 && V_5 == V_9 && V_4 ) {
F_11 ( 1 , L_3 ,
& V_1 , ( unsigned long ) V_2 ) ;
return NULL ;
}
if ( ! V_6 && ( V_4 & V_10 ) ) {
V_4 &= ~ V_10 ;
V_6 = F_12 ( V_1 , V_2 ) ;
}
return V_6 ;
}
void F_13 ( void * V_6 )
{
if ( F_14 ( V_6 ) )
F_15 ( ( void T_1 * ) V_6 ) ;
}
static void F_16 ( struct V_11 * V_12 , void * V_13 )
{
F_13 ( * ( void * * ) V_13 ) ;
}
static int F_17 ( struct V_11 * V_12 , void * V_13 , void * V_14 )
{
return * ( void * * ) V_13 == V_14 ;
}
void * F_18 ( struct V_11 * V_12 , T_2 V_1 ,
T_3 V_2 , unsigned long V_4 )
{
void * * V_15 , * V_6 ;
V_15 = F_19 ( F_16 , sizeof( * V_15 ) , V_16 ,
F_20 ( V_12 ) ) ;
if ( ! V_15 )
return F_21 ( - V_17 ) ;
V_6 = F_9 ( V_1 , V_2 , V_4 ) ;
if ( V_6 ) {
* V_15 = V_6 ;
F_22 ( V_12 , V_15 ) ;
} else {
F_23 ( V_15 ) ;
return F_21 ( - V_18 ) ;
}
return V_6 ;
}
void F_24 ( struct V_11 * V_12 , void * V_6 )
{
F_25 ( F_26 ( V_12 , F_16 ,
F_17 , V_6 ) ) ;
}
T_4 F_27 ( T_5 V_6 , T_6 V_4 )
{
return F_28 ( V_6 >> V_19 , V_4 ) ;
}
void F_29 ( struct V_20 * V_20 )
{
F_30 ( V_20 -> V_21 -> V_22 ) ;
}
void F_31 ( struct V_20 * V_20 )
{
F_32 ( V_20 -> V_21 ) ;
}
static void F_33 ( struct V_23 * V_13 )
{
T_2 V_24 , V_25 , V_26 , V_27 ;
V_25 = V_13 -> V_28 & ~ ( V_29 - 1 ) ;
V_26 = F_34 ( F_35 ( V_13 ) , V_29 ) ;
V_27 = V_25 + V_26 - 1 ;
F_36 ( & V_30 ) ;
for ( V_24 = V_13 -> V_28 ; V_24 <= V_13 -> V_31 ; V_24 += V_29 )
F_37 ( & V_32 , V_24 >> V_33 ) ;
F_38 ( & V_30 ) ;
}
static unsigned long F_39 ( struct V_34 * V_34 )
{
struct V_35 * V_21 = & V_34 -> V_21 ;
const struct V_23 * V_13 = & V_34 -> V_13 ;
struct V_36 * V_37 = V_21 -> V_37 ;
unsigned long V_3 ;
V_3 = V_13 -> V_28 >> V_19 ;
if ( V_37 )
V_3 += F_40 ( V_37 ) ;
return V_3 ;
}
static unsigned long F_41 ( struct V_34 * V_34 )
{
const struct V_23 * V_13 = & V_34 -> V_13 ;
return ( V_13 -> V_28 + F_35 ( V_13 ) ) >> V_19 ;
}
static void F_42 ( struct V_11 * V_12 , void * V_38 )
{
struct V_34 * V_34 = V_38 ;
struct V_23 * V_13 = & V_34 -> V_13 ;
T_2 V_25 , V_26 ;
struct V_35 * V_21 = & V_34 -> V_21 ;
if ( F_43 ( V_21 -> V_22 ) ) {
F_44 ( V_12 , L_4 , V_39 ) ;
F_45 ( V_21 -> V_22 ) ;
}
V_25 = V_13 -> V_28 & ~ ( V_29 - 1 ) ;
V_26 = F_34 ( F_35 ( V_13 ) , V_29 ) ;
F_46 ( V_25 , V_26 ) ;
F_33 ( V_13 ) ;
F_47 ( V_12 , V_21 -> V_37 && V_21 -> V_37 -> V_40 ,
L_5 , V_39 ) ;
}
struct V_35 * F_48 ( T_2 V_41 )
{
struct V_34 * V_34 ;
F_49 ( ! F_50 () ) ;
V_34 = F_51 ( & V_32 , V_41 >> V_33 ) ;
return V_34 ? & V_34 -> V_21 : NULL ;
}
void * F_52 ( struct V_11 * V_12 , struct V_23 * V_13 ,
struct V_42 * V_22 , struct V_36 * V_37 )
{
T_2 V_24 , V_25 , V_26 , V_27 ;
struct V_35 * V_21 ;
struct V_34 * V_34 ;
int error , V_43 , V_5 ;
unsigned long V_3 ;
V_25 = V_13 -> V_28 & ~ ( V_29 - 1 ) ;
V_26 = F_34 ( V_13 -> V_28 + F_35 ( V_13 ) , V_29 )
- V_25 ;
V_5 = F_10 ( V_25 , V_26 , L_1 ) ;
if ( V_5 == V_7 ) {
F_11 ( 1 , L_6 ,
V_39 , V_13 ) ;
return F_21 ( - V_18 ) ;
}
if ( V_5 == V_9 )
return F_8 ( V_13 -> V_28 ) ;
if ( V_37 && ! F_53 ( V_44 ) ) {
F_54 ( V_12 , L_7 ,
V_39 ) ;
return F_21 ( - V_18 ) ;
}
if ( ! V_22 )
return F_21 ( - V_45 ) ;
V_34 = F_19 ( F_42 ,
sizeof( * V_34 ) , V_16 , F_20 ( V_12 ) ) ;
if ( ! V_34 )
return F_21 ( - V_17 ) ;
V_21 = & V_34 -> V_21 ;
memcpy ( & V_34 -> V_13 , V_13 , sizeof( * V_13 ) ) ;
V_21 -> V_12 = V_12 ;
if ( V_37 ) {
memcpy ( & V_34 -> V_37 , V_37 , sizeof( * V_37 ) ) ;
V_21 -> V_37 = & V_34 -> V_37 ;
}
V_21 -> V_22 = V_22 ;
V_21 -> V_13 = & V_34 -> V_13 ;
F_36 ( & V_30 ) ;
error = 0 ;
V_27 = V_25 + V_26 - 1 ;
for ( V_24 = V_25 ; V_24 <= V_27 ; V_24 += V_29 ) {
struct V_35 * V_46 ;
F_55 () ;
V_46 = F_48 ( V_24 ) ;
F_56 () ;
if ( V_46 ) {
F_54 ( V_12 , L_8 ,
V_39 , V_13 , F_57 ( V_46 -> V_12 ) ) ;
error = - V_47 ;
break;
}
error = F_58 ( & V_32 , V_24 >> V_33 ,
V_34 ) ;
if ( error ) {
F_54 ( V_12 , L_9 , V_39 , error ) ;
break;
}
}
F_38 ( & V_30 ) ;
if ( error )
goto V_48;
V_43 = F_20 ( V_12 ) ;
if ( V_43 < 0 )
V_43 = F_59 () ;
error = F_60 ( V_43 , V_25 , V_26 , true ) ;
if ( error )
goto V_49;
F_61 (pfn, page_map) {
struct V_20 * V_20 = F_7 ( V_3 ) ;
F_62 ( & V_20 -> V_50 ) ;
V_20 -> V_21 = V_21 ;
}
F_22 ( V_12 , V_34 ) ;
return F_8 ( V_13 -> V_28 ) ;
V_49:
V_48:
F_33 ( V_13 ) ;
F_23 ( V_34 ) ;
return F_21 ( error ) ;
}
unsigned long F_40 ( struct V_36 * V_37 )
{
return V_37 -> V_51 + V_37 -> free ;
}
void F_63 ( struct V_36 * V_37 , unsigned long V_52 )
{
V_37 -> V_40 -= V_52 ;
}
struct V_36 * F_64 ( unsigned long V_53 )
{
struct V_20 * V_20 = (struct V_20 * ) V_53 ;
struct V_35 * V_21 ;
F_55 () ;
V_21 = F_48 ( F_65 ( F_66 ( V_20 ) ) ) ;
F_56 () ;
return V_21 ? V_21 -> V_37 : NULL ;
}
