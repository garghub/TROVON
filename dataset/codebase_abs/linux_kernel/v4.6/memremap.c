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
int V_5 = F_10 ( V_1 , V_2 ,
V_6 , V_7 ) ;
void * V_8 = NULL ;
if ( ! V_4 )
return NULL ;
if ( V_5 == V_9 ) {
F_11 ( 1 , L_1 ,
& V_1 , ( unsigned long ) V_2 ) ;
return NULL ;
}
if ( V_4 & V_10 ) {
if ( V_5 == V_11 )
V_8 = F_3 ( V_1 , V_2 ) ;
if ( ! V_8 )
V_8 = F_1 ( V_1 , V_2 ) ;
}
if ( ! V_8 && V_5 == V_11 && V_4 != V_10 ) {
F_11 ( 1 , L_2 ,
& V_1 , ( unsigned long ) V_2 ) ;
return NULL ;
}
if ( ! V_8 && ( V_4 & V_12 ) )
V_8 = F_12 ( V_1 , V_2 ) ;
if ( ! V_8 && ( V_4 & V_13 ) )
V_8 = F_13 ( V_1 , V_2 ) ;
return V_8 ;
}
void F_14 ( void * V_8 )
{
if ( F_15 ( V_8 ) )
F_16 ( ( void T_1 * ) V_8 ) ;
}
static void F_17 ( struct V_14 * V_15 , void * V_16 )
{
F_14 ( * ( void * * ) V_16 ) ;
}
static int F_18 ( struct V_14 * V_15 , void * V_16 , void * V_17 )
{
return * ( void * * ) V_16 == V_17 ;
}
void * F_19 ( struct V_14 * V_15 , T_2 V_1 ,
T_3 V_2 , unsigned long V_4 )
{
void * * V_18 , * V_8 ;
V_18 = F_20 ( F_17 , sizeof( * V_18 ) , V_19 ,
F_21 ( V_15 ) ) ;
if ( ! V_18 )
return F_22 ( - V_20 ) ;
V_8 = F_9 ( V_1 , V_2 , V_4 ) ;
if ( V_8 ) {
* V_18 = V_8 ;
F_23 ( V_15 , V_18 ) ;
} else {
F_24 ( V_18 ) ;
return F_22 ( - V_21 ) ;
}
return V_8 ;
}
void F_25 ( struct V_14 * V_15 , void * V_8 )
{
F_26 ( F_27 ( V_15 , F_17 ,
F_18 , V_8 ) ) ;
}
T_4 F_28 ( T_5 V_8 , T_6 V_4 )
{
return F_29 ( V_8 >> V_22 , V_4 ) ;
}
void F_30 ( struct V_23 * V_23 )
{
F_31 ( V_23 -> V_24 -> V_25 ) ;
}
void F_32 ( struct V_23 * V_23 )
{
F_33 ( V_23 -> V_24 ) ;
}
static void F_34 ( struct V_26 * V_16 )
{
T_2 V_27 , V_28 , V_29 , V_30 ;
V_28 = V_16 -> V_31 & ~ ( V_32 - 1 ) ;
V_29 = F_35 ( F_36 ( V_16 ) , V_32 ) ;
V_30 = V_28 + V_29 - 1 ;
F_37 ( & V_33 ) ;
for ( V_27 = V_16 -> V_31 ; V_27 <= V_16 -> V_34 ; V_27 += V_32 )
F_38 ( & V_35 , V_27 >> V_36 ) ;
F_39 ( & V_33 ) ;
}
static unsigned long F_40 ( struct V_37 * V_37 )
{
struct V_38 * V_24 = & V_37 -> V_24 ;
const struct V_26 * V_16 = & V_37 -> V_16 ;
struct V_39 * V_40 = V_24 -> V_40 ;
unsigned long V_3 ;
V_3 = V_16 -> V_31 >> V_22 ;
if ( V_40 )
V_3 += F_41 ( V_40 ) ;
return V_3 ;
}
static unsigned long F_42 ( struct V_37 * V_37 )
{
const struct V_26 * V_16 = & V_37 -> V_16 ;
return ( V_16 -> V_31 + F_36 ( V_16 ) ) >> V_22 ;
}
static void F_43 ( struct V_14 * V_15 , void * V_41 )
{
struct V_37 * V_37 = V_41 ;
struct V_26 * V_16 = & V_37 -> V_16 ;
T_2 V_28 , V_29 ;
struct V_38 * V_24 = & V_37 -> V_24 ;
if ( F_44 ( V_24 -> V_25 ) ) {
F_45 ( V_15 , L_3 , V_42 ) ;
F_46 ( V_24 -> V_25 ) ;
}
V_28 = V_16 -> V_31 & ~ ( V_32 - 1 ) ;
V_29 = F_35 ( F_36 ( V_16 ) , V_32 ) ;
F_47 ( V_28 , V_29 ) ;
F_34 ( V_16 ) ;
F_48 ( V_15 , V_24 -> V_40 && V_24 -> V_40 -> V_43 ,
L_4 , V_42 ) ;
}
struct V_38 * F_49 ( T_2 V_44 )
{
struct V_37 * V_37 ;
F_50 ( ! F_51 () ) ;
V_37 = F_52 ( & V_35 , V_44 >> V_36 ) ;
return V_37 ? & V_37 -> V_24 : NULL ;
}
void * F_53 ( struct V_14 * V_15 , struct V_26 * V_16 ,
struct V_45 * V_25 , struct V_39 * V_40 )
{
T_2 V_27 , V_28 , V_29 , V_30 ;
struct V_38 * V_24 ;
struct V_37 * V_37 ;
int error , V_46 , V_5 ;
unsigned long V_3 ;
V_28 = V_16 -> V_31 & ~ ( V_32 - 1 ) ;
V_29 = F_35 ( V_16 -> V_31 + F_36 ( V_16 ) , V_32 )
- V_28 ;
V_5 = F_10 ( V_28 , V_29 ,
V_6 , V_7 ) ;
if ( V_5 == V_9 ) {
F_11 ( 1 , L_5 ,
V_42 , V_16 ) ;
return F_22 ( - V_21 ) ;
}
if ( V_5 == V_11 )
return F_8 ( V_16 -> V_31 ) ;
if ( V_40 && ! F_54 ( V_47 ) ) {
F_55 ( V_15 , L_6 ,
V_42 ) ;
return F_22 ( - V_21 ) ;
}
if ( ! V_25 )
return F_22 ( - V_48 ) ;
V_37 = F_20 ( F_43 ,
sizeof( * V_37 ) , V_19 , F_21 ( V_15 ) ) ;
if ( ! V_37 )
return F_22 ( - V_20 ) ;
V_24 = & V_37 -> V_24 ;
memcpy ( & V_37 -> V_16 , V_16 , sizeof( * V_16 ) ) ;
V_24 -> V_15 = V_15 ;
if ( V_40 ) {
memcpy ( & V_37 -> V_40 , V_40 , sizeof( * V_40 ) ) ;
V_24 -> V_40 = & V_37 -> V_40 ;
}
V_24 -> V_25 = V_25 ;
V_24 -> V_16 = & V_37 -> V_16 ;
F_37 ( & V_33 ) ;
error = 0 ;
V_30 = V_28 + V_29 - 1 ;
for ( V_27 = V_28 ; V_27 <= V_30 ; V_27 += V_32 ) {
struct V_38 * V_49 ;
F_56 () ;
V_49 = F_49 ( V_27 ) ;
F_57 () ;
if ( V_49 ) {
F_55 ( V_15 , L_7 ,
V_42 , V_16 , F_58 ( V_49 -> V_15 ) ) ;
error = - V_50 ;
break;
}
error = F_59 ( & V_35 , V_27 >> V_36 ,
V_37 ) ;
if ( error ) {
F_55 ( V_15 , L_8 , V_42 , error ) ;
break;
}
}
F_39 ( & V_33 ) ;
if ( error )
goto V_51;
V_46 = F_21 ( V_15 ) ;
if ( V_46 < 0 )
V_46 = F_60 () ;
error = F_61 ( V_46 , V_28 , V_29 , true ) ;
if ( error )
goto V_52;
F_62 (pfn, page_map) {
struct V_23 * V_23 = F_7 ( V_3 ) ;
F_63 ( & V_23 -> V_53 ) ;
V_23 -> V_24 = V_24 ;
}
F_23 ( V_15 , V_37 ) ;
return F_8 ( V_16 -> V_31 ) ;
V_52:
V_51:
F_34 ( V_16 ) ;
F_24 ( V_37 ) ;
return F_22 ( error ) ;
}
unsigned long F_41 ( struct V_39 * V_40 )
{
return V_40 -> V_54 + V_40 -> free ;
}
void F_64 ( struct V_39 * V_40 , unsigned long V_55 )
{
V_40 -> V_43 -= V_55 ;
}
struct V_39 * F_65 ( unsigned long V_56 )
{
struct V_23 * V_23 = (struct V_23 * ) V_56 ;
struct V_38 * V_24 ;
F_56 () ;
V_24 = F_49 ( F_66 ( F_67 ( V_23 ) ) ) ;
F_57 () ;
return V_24 ? V_24 -> V_40 : NULL ;
}
