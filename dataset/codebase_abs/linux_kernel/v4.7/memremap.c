__weak void T_1 * F_1 ( T_2 V_1 , unsigned long V_2 )
{
return F_2 ( V_1 , V_2 ) ;
}
static void * F_3 ( T_2 V_1 , unsigned long V_2 )
{
return ( V_3 void * ) F_1 ( V_1 , V_2 ) ;
}
static void * F_4 ( T_2 V_1 , T_3 V_2 )
{
unsigned long V_4 = F_5 ( V_1 ) ;
if ( F_6 ( V_4 ) && ! F_7 ( F_8 ( V_4 ) ) )
return F_9 ( V_1 ) ;
return NULL ;
}
void * F_10 ( T_2 V_1 , T_3 V_2 , unsigned long V_5 )
{
int V_6 = F_11 ( V_1 , V_2 ,
V_7 , V_8 ) ;
void * V_9 = NULL ;
if ( ! V_5 )
return NULL ;
if ( V_6 == V_10 ) {
F_12 ( 1 , L_1 ,
& V_1 , ( unsigned long ) V_2 ) ;
return NULL ;
}
if ( V_5 & V_11 ) {
if ( V_6 == V_12 )
V_9 = F_4 ( V_1 , V_2 ) ;
if ( ! V_9 )
V_9 = F_3 ( V_1 , V_2 ) ;
}
if ( ! V_9 && V_6 == V_12 && V_5 != V_11 ) {
F_12 ( 1 , L_2 ,
& V_1 , ( unsigned long ) V_2 ) ;
return NULL ;
}
if ( ! V_9 && ( V_5 & V_13 ) )
V_9 = F_13 ( V_1 , V_2 ) ;
if ( ! V_9 && ( V_5 & V_14 ) )
V_9 = F_14 ( V_1 , V_2 ) ;
return V_9 ;
}
void F_15 ( void * V_9 )
{
if ( F_16 ( V_9 ) )
F_17 ( ( void T_1 * ) V_9 ) ;
}
static void F_18 ( struct V_15 * V_16 , void * V_17 )
{
F_15 ( * ( void * * ) V_17 ) ;
}
static int F_19 ( struct V_15 * V_16 , void * V_17 , void * V_18 )
{
return * ( void * * ) V_17 == V_18 ;
}
void * F_20 ( struct V_15 * V_16 , T_2 V_1 ,
T_3 V_2 , unsigned long V_5 )
{
void * * V_19 , * V_9 ;
V_19 = F_21 ( F_18 , sizeof( * V_19 ) , V_20 ,
F_22 ( V_16 ) ) ;
if ( ! V_19 )
return F_23 ( - V_21 ) ;
V_9 = F_10 ( V_1 , V_2 , V_5 ) ;
if ( V_9 ) {
* V_19 = V_9 ;
F_24 ( V_16 , V_19 ) ;
} else {
F_25 ( V_19 ) ;
return F_23 ( - V_22 ) ;
}
return V_9 ;
}
void F_26 ( struct V_15 * V_16 , void * V_9 )
{
F_27 ( F_28 ( V_16 , F_18 ,
F_19 , V_9 ) ) ;
}
T_4 F_29 ( T_5 V_9 , T_6 V_5 )
{
return F_30 ( V_9 >> V_23 , V_5 ) ;
}
void F_31 ( struct V_24 * V_24 )
{
F_32 ( V_24 -> V_25 -> V_26 ) ;
}
void F_33 ( struct V_24 * V_24 )
{
F_34 ( V_24 -> V_25 ) ;
}
static void F_35 ( struct V_27 * V_17 )
{
T_2 V_28 , V_29 , V_30 , V_31 ;
V_29 = V_17 -> V_32 & ~ ( V_33 - 1 ) ;
V_30 = F_36 ( F_37 ( V_17 ) , V_33 ) ;
V_31 = V_29 + V_30 - 1 ;
F_38 ( & V_34 ) ;
for ( V_28 = V_17 -> V_32 ; V_28 <= V_17 -> V_35 ; V_28 += V_33 )
F_39 ( & V_36 , V_28 >> V_37 ) ;
F_40 ( & V_34 ) ;
}
static unsigned long F_41 ( struct V_38 * V_38 )
{
struct V_39 * V_25 = & V_38 -> V_25 ;
const struct V_27 * V_17 = & V_38 -> V_17 ;
struct V_40 * V_41 = V_25 -> V_41 ;
unsigned long V_4 ;
V_4 = V_17 -> V_32 >> V_23 ;
if ( V_41 )
V_4 += F_42 ( V_41 ) ;
return V_4 ;
}
static unsigned long F_43 ( struct V_38 * V_38 )
{
const struct V_27 * V_17 = & V_38 -> V_17 ;
return ( V_17 -> V_32 + F_37 ( V_17 ) ) >> V_23 ;
}
static void F_44 ( struct V_15 * V_16 , void * V_42 )
{
struct V_38 * V_38 = V_42 ;
struct V_27 * V_17 = & V_38 -> V_17 ;
T_2 V_29 , V_30 ;
struct V_39 * V_25 = & V_38 -> V_25 ;
if ( F_45 ( V_25 -> V_26 ) ) {
F_46 ( V_16 , L_3 , V_43 ) ;
F_47 ( V_25 -> V_26 ) ;
}
V_29 = V_17 -> V_32 & ~ ( V_33 - 1 ) ;
V_30 = F_36 ( F_37 ( V_17 ) , V_33 ) ;
F_48 ( V_29 , V_30 ) ;
F_35 ( V_17 ) ;
F_49 ( V_16 , V_25 -> V_41 && V_25 -> V_41 -> V_44 ,
L_4 , V_43 ) ;
}
struct V_39 * F_50 ( T_2 V_45 )
{
struct V_38 * V_38 ;
F_51 ( ! F_52 () ) ;
V_38 = F_53 ( & V_36 , V_45 >> V_37 ) ;
return V_38 ? & V_38 -> V_25 : NULL ;
}
void * F_54 ( struct V_15 * V_16 , struct V_27 * V_17 ,
struct V_46 * V_26 , struct V_40 * V_41 )
{
T_2 V_28 , V_29 , V_30 , V_31 ;
struct V_39 * V_25 ;
struct V_38 * V_38 ;
int error , V_47 , V_6 ;
unsigned long V_4 ;
V_29 = V_17 -> V_32 & ~ ( V_33 - 1 ) ;
V_30 = F_36 ( V_17 -> V_32 + F_37 ( V_17 ) , V_33 )
- V_29 ;
V_6 = F_11 ( V_29 , V_30 ,
V_7 , V_8 ) ;
if ( V_6 == V_10 ) {
F_12 ( 1 , L_5 ,
V_43 , V_17 ) ;
return F_23 ( - V_22 ) ;
}
if ( V_6 == V_12 )
return F_9 ( V_17 -> V_32 ) ;
if ( V_41 && ! F_55 ( V_48 ) ) {
F_56 ( V_16 , L_6 ,
V_43 ) ;
return F_23 ( - V_22 ) ;
}
if ( ! V_26 )
return F_23 ( - V_49 ) ;
V_38 = F_21 ( F_44 ,
sizeof( * V_38 ) , V_20 , F_22 ( V_16 ) ) ;
if ( ! V_38 )
return F_23 ( - V_21 ) ;
V_25 = & V_38 -> V_25 ;
memcpy ( & V_38 -> V_17 , V_17 , sizeof( * V_17 ) ) ;
V_25 -> V_16 = V_16 ;
if ( V_41 ) {
memcpy ( & V_38 -> V_41 , V_41 , sizeof( * V_41 ) ) ;
V_25 -> V_41 = & V_38 -> V_41 ;
}
V_25 -> V_26 = V_26 ;
V_25 -> V_17 = & V_38 -> V_17 ;
F_38 ( & V_34 ) ;
error = 0 ;
V_31 = V_29 + V_30 - 1 ;
for ( V_28 = V_29 ; V_28 <= V_31 ; V_28 += V_33 ) {
struct V_39 * V_50 ;
F_57 () ;
V_50 = F_50 ( V_28 ) ;
F_58 () ;
if ( V_50 ) {
F_56 ( V_16 , L_7 ,
V_43 , V_17 , F_59 ( V_50 -> V_16 ) ) ;
error = - V_51 ;
break;
}
error = F_60 ( & V_36 , V_28 >> V_37 ,
V_38 ) ;
if ( error ) {
F_56 ( V_16 , L_8 , V_43 , error ) ;
break;
}
}
F_40 ( & V_34 ) ;
if ( error )
goto V_52;
V_47 = F_22 ( V_16 ) ;
if ( V_47 < 0 )
V_47 = F_61 () ;
error = F_62 ( V_47 , V_29 , V_30 , true ) ;
if ( error )
goto V_53;
F_63 (pfn, page_map) {
struct V_24 * V_24 = F_8 ( V_4 ) ;
F_64 ( & V_24 -> V_54 ) ;
V_24 -> V_25 = V_25 ;
}
F_24 ( V_16 , V_38 ) ;
return F_9 ( V_17 -> V_32 ) ;
V_53:
V_52:
F_35 ( V_17 ) ;
F_25 ( V_38 ) ;
return F_23 ( error ) ;
}
unsigned long F_42 ( struct V_40 * V_41 )
{
return V_41 -> V_55 + V_41 -> free ;
}
void F_65 ( struct V_40 * V_41 , unsigned long V_56 )
{
V_41 -> V_44 -= V_56 ;
}
struct V_40 * F_66 ( unsigned long V_57 )
{
struct V_24 * V_24 = (struct V_24 * ) V_57 ;
struct V_39 * V_25 ;
F_57 () ;
V_25 = F_50 ( F_67 ( F_68 ( V_24 ) ) ) ;
F_58 () ;
return V_25 ? V_25 -> V_41 : NULL ;
}
