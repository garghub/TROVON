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
void F_29 ( struct V_23 * V_23 )
{
F_30 ( V_23 -> V_24 -> V_25 ) ;
}
void F_31 ( struct V_23 * V_23 )
{
F_32 ( V_23 -> V_24 ) ;
}
static void F_33 ( struct V_26 * V_17 )
{
T_2 V_27 , V_28 , V_29 , V_30 ;
V_28 = V_17 -> V_31 & ~ ( V_32 - 1 ) ;
V_29 = F_34 ( F_35 ( V_17 ) , V_32 ) ;
V_30 = V_28 + V_29 - 1 ;
F_36 ( & V_33 ) ;
for ( V_27 = V_17 -> V_31 ; V_27 <= V_17 -> V_34 ; V_27 += V_32 )
F_37 ( & V_35 , V_27 >> V_36 ) ;
F_38 ( & V_33 ) ;
}
static unsigned long F_39 ( struct V_37 * V_37 )
{
struct V_38 * V_24 = & V_37 -> V_24 ;
const struct V_26 * V_17 = & V_37 -> V_17 ;
struct V_39 * V_40 = V_24 -> V_40 ;
unsigned long V_4 ;
V_4 = V_17 -> V_31 >> V_41 ;
if ( V_40 )
V_4 += F_40 ( V_40 ) ;
return V_4 ;
}
static unsigned long F_41 ( struct V_37 * V_37 )
{
const struct V_26 * V_17 = & V_37 -> V_17 ;
return ( V_17 -> V_31 + F_35 ( V_17 ) ) >> V_41 ;
}
static void F_42 ( struct V_15 * V_16 , void * V_42 )
{
struct V_37 * V_37 = V_42 ;
struct V_26 * V_17 = & V_37 -> V_17 ;
T_2 V_28 , V_29 ;
struct V_38 * V_24 = & V_37 -> V_24 ;
if ( F_43 ( V_24 -> V_25 ) ) {
F_44 ( V_16 , L_3 , V_43 ) ;
F_45 ( V_24 -> V_25 ) ;
}
V_28 = V_17 -> V_31 & ~ ( V_32 - 1 ) ;
V_29 = F_34 ( F_35 ( V_17 ) , V_32 ) ;
F_46 ( V_28 , V_29 ) ;
F_47 ( NULL , F_5 ( V_28 ) , V_29 ) ;
F_33 ( V_17 ) ;
F_48 ( V_16 , V_24 -> V_40 && V_24 -> V_40 -> V_44 ,
L_4 , V_43 ) ;
}
struct V_38 * F_49 ( T_2 V_45 )
{
struct V_37 * V_37 ;
F_50 ( ! F_51 () ) ;
V_37 = F_52 ( & V_35 , V_45 >> V_36 ) ;
return V_37 ? & V_37 -> V_24 : NULL ;
}
void * F_53 ( struct V_15 * V_16 , struct V_26 * V_17 ,
struct V_46 * V_25 , struct V_39 * V_40 )
{
T_2 V_27 , V_28 , V_29 , V_30 ;
T_4 V_47 = V_48 ;
struct V_38 * V_24 ;
struct V_37 * V_37 ;
int error , V_49 , V_6 ;
unsigned long V_4 ;
V_28 = V_17 -> V_31 & ~ ( V_32 - 1 ) ;
V_29 = F_34 ( V_17 -> V_31 + F_35 ( V_17 ) , V_32 )
- V_28 ;
V_6 = F_11 ( V_28 , V_29 ,
V_7 , V_8 ) ;
if ( V_6 == V_10 ) {
F_12 ( 1 , L_5 ,
V_43 , V_17 ) ;
return F_23 ( - V_22 ) ;
}
if ( V_6 == V_12 )
return F_9 ( V_17 -> V_31 ) ;
if ( ! V_25 )
return F_23 ( - V_50 ) ;
V_37 = F_21 ( F_42 ,
sizeof( * V_37 ) , V_20 , F_22 ( V_16 ) ) ;
if ( ! V_37 )
return F_23 ( - V_21 ) ;
V_24 = & V_37 -> V_24 ;
memcpy ( & V_37 -> V_17 , V_17 , sizeof( * V_17 ) ) ;
V_24 -> V_16 = V_16 ;
if ( V_40 ) {
memcpy ( & V_37 -> V_40 , V_40 , sizeof( * V_40 ) ) ;
V_24 -> V_40 = & V_37 -> V_40 ;
}
V_24 -> V_25 = V_25 ;
V_24 -> V_17 = & V_37 -> V_17 ;
F_36 ( & V_33 ) ;
error = 0 ;
V_30 = V_28 + V_29 - 1 ;
for ( V_27 = V_28 ; V_27 <= V_30 ; V_27 += V_32 ) {
struct V_38 * V_51 ;
F_54 () ;
V_51 = F_49 ( V_27 ) ;
F_55 () ;
if ( V_51 ) {
F_56 ( V_16 , L_6 ,
V_43 , V_17 , F_57 ( V_51 -> V_16 ) ) ;
error = - V_52 ;
break;
}
error = F_58 ( & V_35 , V_27 >> V_36 ,
V_37 ) ;
if ( error ) {
F_56 ( V_16 , L_7 , V_43 , error ) ;
break;
}
}
F_38 ( & V_33 ) ;
if ( error )
goto V_53;
V_49 = F_22 ( V_16 ) ;
if ( V_49 < 0 )
V_49 = F_59 () ;
error = F_60 ( NULL , & V_47 , F_5 ( V_28 ) , 0 ,
V_29 ) ;
if ( error )
goto V_54;
error = F_61 ( V_49 , V_28 , V_29 , true ) ;
if ( error )
goto V_55;
F_62 (pfn, page_map) {
struct V_23 * V_23 = F_8 ( V_4 ) ;
F_63 ( & V_23 -> V_56 ) ;
V_23 -> V_24 = V_24 ;
}
F_24 ( V_16 , V_37 ) ;
return F_9 ( V_17 -> V_31 ) ;
V_55:
F_47 ( NULL , F_5 ( V_28 ) , V_29 ) ;
V_54:
V_53:
F_33 ( V_17 ) ;
F_25 ( V_37 ) ;
return F_23 ( error ) ;
}
unsigned long F_40 ( struct V_39 * V_40 )
{
return V_40 -> V_57 + V_40 -> free ;
}
void F_64 ( struct V_39 * V_40 , unsigned long V_58 )
{
V_40 -> V_44 -= V_58 ;
}
struct V_39 * F_65 ( unsigned long V_59 )
{
struct V_23 * V_23 = (struct V_23 * ) V_59 ;
struct V_38 * V_24 ;
F_54 () ;
V_24 = F_49 ( F_66 ( F_67 ( V_23 ) ) ) ;
F_55 () ;
return V_24 ? V_24 -> V_40 : NULL ;
}
