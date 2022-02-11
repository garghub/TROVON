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
static void F_29 ( struct V_23 * V_17 )
{
T_2 V_24 , V_25 , V_26 , V_27 ;
V_25 = V_17 -> V_28 & ~ ( V_29 - 1 ) ;
V_26 = F_30 ( F_31 ( V_17 ) , V_29 ) ;
V_27 = V_25 + V_26 - 1 ;
F_32 ( & V_30 ) ;
for ( V_24 = V_17 -> V_28 ; V_24 <= V_17 -> V_31 ; V_24 += V_29 )
F_33 ( & V_32 , V_24 >> V_33 ) ;
F_34 ( & V_30 ) ;
}
static unsigned long F_35 ( struct V_34 * V_34 )
{
struct V_35 * V_36 = & V_34 -> V_36 ;
const struct V_23 * V_17 = & V_34 -> V_17 ;
struct V_37 * V_38 = V_36 -> V_38 ;
unsigned long V_4 ;
V_4 = V_17 -> V_28 >> V_39 ;
if ( V_38 )
V_4 += F_36 ( V_38 ) ;
return V_4 ;
}
static unsigned long F_37 ( struct V_34 * V_34 )
{
const struct V_23 * V_17 = & V_34 -> V_17 ;
return ( V_17 -> V_28 + F_31 ( V_17 ) ) >> V_39 ;
}
static void F_38 ( struct V_15 * V_16 , void * V_40 )
{
struct V_34 * V_34 = V_40 ;
struct V_23 * V_17 = & V_34 -> V_17 ;
T_2 V_25 , V_26 ;
struct V_35 * V_36 = & V_34 -> V_36 ;
unsigned long V_4 ;
F_39 (pfn, page_map)
F_40 ( F_8 ( V_4 ) ) ;
if ( F_41 ( V_36 -> V_41 ) ) {
F_42 ( V_16 , L_3 , V_42 ) ;
F_43 ( V_36 -> V_41 ) ;
}
V_25 = V_17 -> V_28 & ~ ( V_29 - 1 ) ;
V_26 = F_30 ( F_31 ( V_17 ) , V_29 ) ;
F_44 () ;
F_45 ( V_25 , V_26 ) ;
F_46 () ;
F_47 ( NULL , F_5 ( V_25 ) , V_26 ) ;
F_29 ( V_17 ) ;
F_48 ( V_16 , V_36 -> V_38 && V_36 -> V_38 -> V_43 ,
L_4 , V_42 ) ;
}
struct V_35 * F_49 ( T_2 V_44 )
{
struct V_34 * V_34 ;
F_50 ( ! F_51 () ) ;
V_34 = F_52 ( & V_32 , V_44 >> V_33 ) ;
return V_34 ? & V_34 -> V_36 : NULL ;
}
void * F_53 ( struct V_15 * V_16 , struct V_23 * V_17 ,
struct V_45 * V_41 , struct V_37 * V_38 )
{
T_2 V_24 , V_25 , V_26 , V_27 ;
T_4 V_46 = V_47 ;
struct V_35 * V_36 ;
struct V_34 * V_34 ;
int error , V_48 , V_6 ;
unsigned long V_4 ;
V_25 = V_17 -> V_28 & ~ ( V_29 - 1 ) ;
V_26 = F_30 ( V_17 -> V_28 + F_31 ( V_17 ) , V_29 )
- V_25 ;
V_6 = F_11 ( V_25 , V_26 ,
V_7 , V_8 ) ;
if ( V_6 == V_10 ) {
F_12 ( 1 , L_5 ,
V_42 , V_17 ) ;
return F_23 ( - V_22 ) ;
}
if ( V_6 == V_12 )
return F_9 ( V_17 -> V_28 ) ;
if ( ! V_41 )
return F_23 ( - V_49 ) ;
V_34 = F_21 ( F_38 ,
sizeof( * V_34 ) , V_20 , F_22 ( V_16 ) ) ;
if ( ! V_34 )
return F_23 ( - V_21 ) ;
V_36 = & V_34 -> V_36 ;
memcpy ( & V_34 -> V_17 , V_17 , sizeof( * V_17 ) ) ;
V_36 -> V_16 = V_16 ;
if ( V_38 ) {
memcpy ( & V_34 -> V_38 , V_38 , sizeof( * V_38 ) ) ;
V_36 -> V_38 = & V_34 -> V_38 ;
}
V_36 -> V_41 = V_41 ;
V_36 -> V_17 = & V_34 -> V_17 ;
F_32 ( & V_30 ) ;
error = 0 ;
V_27 = V_25 + V_26 - 1 ;
for ( V_24 = V_25 ; V_24 <= V_27 ; V_24 += V_29 ) {
struct V_35 * V_50 ;
F_54 () ;
V_50 = F_49 ( V_24 ) ;
F_55 () ;
if ( V_50 ) {
F_56 ( V_16 , L_6 ,
V_42 , V_17 , F_57 ( V_50 -> V_16 ) ) ;
error = - V_51 ;
break;
}
error = F_58 ( & V_32 , V_24 >> V_33 ,
V_34 ) ;
if ( error ) {
F_56 ( V_16 , L_7 , V_42 , error ) ;
break;
}
}
F_34 ( & V_30 ) ;
if ( error )
goto V_52;
V_48 = F_22 ( V_16 ) ;
if ( V_48 < 0 )
V_48 = F_59 () ;
error = F_60 ( NULL , & V_46 , F_5 ( V_25 ) , 0 ,
V_26 ) ;
if ( error )
goto V_53;
F_44 () ;
error = F_61 ( V_48 , V_25 , V_26 , false ) ;
if ( ! error )
F_62 ( & F_63 ( V_48 ) -> V_54 [ V_55 ] ,
V_25 >> V_39 ,
V_26 >> V_39 ) ;
F_46 () ;
if ( error )
goto V_56;
F_39 (pfn, page_map) {
struct V_57 * V_57 = F_8 ( V_4 ) ;
F_64 ( & V_57 -> V_58 ) ;
V_57 -> V_36 = V_36 ;
F_65 ( V_41 ) ;
}
F_24 ( V_16 , V_34 ) ;
return F_9 ( V_17 -> V_28 ) ;
V_56:
F_47 ( NULL , F_5 ( V_25 ) , V_26 ) ;
V_53:
V_52:
F_29 ( V_17 ) ;
F_25 ( V_34 ) ;
return F_23 ( error ) ;
}
unsigned long F_36 ( struct V_37 * V_38 )
{
return V_38 -> V_59 + V_38 -> free ;
}
void F_66 ( struct V_37 * V_38 , unsigned long V_60 )
{
V_38 -> V_43 -= V_60 ;
}
struct V_37 * F_67 ( unsigned long V_61 )
{
struct V_57 * V_57 = (struct V_57 * ) V_61 ;
struct V_35 * V_36 ;
F_54 () ;
V_36 = F_49 ( F_68 ( F_69 ( V_57 ) ) ) ;
F_55 () ;
return V_36 ? V_36 -> V_38 : NULL ;
}
