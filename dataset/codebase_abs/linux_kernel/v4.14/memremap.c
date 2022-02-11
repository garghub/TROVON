__weak void T_1 * F_1 ( T_2 V_1 , unsigned long V_2 )
{
return F_2 ( V_1 , V_2 ) ;
}
static void * F_3 ( T_2 V_1 , unsigned long V_2 )
{
return ( V_3 void * ) F_1 ( V_1 , V_2 ) ;
}
static bool F_4 ( T_2 V_1 , T_3 V_2 ,
unsigned long V_4 )
{
return true ;
}
static void * F_5 ( T_2 V_1 , T_3 V_2 ,
unsigned long V_4 )
{
unsigned long V_5 = F_6 ( V_1 ) ;
if ( F_7 ( V_5 ) && ! F_8 ( F_9 ( V_5 ) ) &&
F_4 ( V_1 , V_2 , V_4 ) )
return F_10 ( V_1 ) ;
return NULL ;
}
void * F_11 ( T_2 V_1 , T_3 V_2 , unsigned long V_4 )
{
int V_6 = F_12 ( V_1 , V_2 ,
V_7 , V_8 ) ;
void * V_9 = NULL ;
if ( ! V_4 )
return NULL ;
if ( V_6 == V_10 ) {
F_13 ( 1 , L_1 ,
& V_1 , ( unsigned long ) V_2 ) ;
return NULL ;
}
if ( V_4 & V_11 ) {
if ( V_6 == V_12 )
V_9 = F_5 ( V_1 , V_2 , V_4 ) ;
if ( ! V_9 )
V_9 = F_3 ( V_1 , V_2 ) ;
}
if ( ! V_9 && V_6 == V_12 && V_4 != V_11 ) {
F_13 ( 1 , L_2 ,
& V_1 , ( unsigned long ) V_2 ) ;
return NULL ;
}
if ( ! V_9 && ( V_4 & V_13 ) )
V_9 = F_14 ( V_1 , V_2 ) ;
if ( ! V_9 && ( V_4 & V_14 ) )
V_9 = F_15 ( V_1 , V_2 ) ;
return V_9 ;
}
void F_16 ( void * V_9 )
{
if ( F_17 ( V_9 ) )
F_18 ( ( void T_1 * ) V_9 ) ;
}
static void F_19 ( struct V_15 * V_16 , void * V_17 )
{
F_16 ( * ( void * * ) V_17 ) ;
}
static int F_20 ( struct V_15 * V_16 , void * V_17 , void * V_18 )
{
return * ( void * * ) V_17 == V_18 ;
}
void * F_21 ( struct V_15 * V_16 , T_2 V_1 ,
T_3 V_2 , unsigned long V_4 )
{
void * * V_19 , * V_9 ;
V_19 = F_22 ( F_19 , sizeof( * V_19 ) , V_20 ,
F_23 ( V_16 ) ) ;
if ( ! V_19 )
return F_24 ( - V_21 ) ;
V_9 = F_11 ( V_1 , V_2 , V_4 ) ;
if ( V_9 ) {
* V_19 = V_9 ;
F_25 ( V_16 , V_19 ) ;
} else {
F_26 ( V_19 ) ;
return F_24 ( - V_22 ) ;
}
return V_9 ;
}
void F_27 ( struct V_15 * V_16 , void * V_9 )
{
F_28 ( F_29 ( V_16 , F_19 ,
F_20 , V_9 ) ) ;
}
static unsigned long F_30 ( struct V_23 * V_17 , unsigned long V_24 )
{
unsigned long V_25 = F_6 ( V_17 -> V_26 ) + V_24 ;
unsigned long V_27 , V_28 ;
V_27 = F_6 ( F_31 ( V_17 ) ) ;
if ( V_27 == V_24 )
return V_29 ;
V_28 = V_25 | F_32 ( V_27 - V_24 ) ;
if ( ! V_28 )
return V_29 ;
return F_33 ( & V_28 , V_30 ) ;
}
int F_34 ( struct V_31 * V_32 ,
unsigned long V_9 ,
T_4 V_33 ,
unsigned int V_4 ,
T_5 * V_34 )
{
struct V_35 * V_35 = F_35 ( V_33 ) ;
return V_35 -> V_36 -> V_37 ( V_32 , V_9 , V_35 , V_4 , V_34 ) ;
}
static void F_36 ( struct V_23 * V_17 )
{
unsigned long V_24 , V_38 ;
F_37 ( & V_39 ) ;
F_38 (res, order, pgoff)
F_39 ( & V_40 , F_6 ( V_17 -> V_26 ) + V_24 ) ;
F_40 ( & V_39 ) ;
F_41 () ;
}
static unsigned long F_42 ( struct V_41 * V_41 )
{
struct V_42 * V_36 = & V_41 -> V_36 ;
const struct V_23 * V_17 = & V_41 -> V_17 ;
struct V_43 * V_44 = V_36 -> V_44 ;
unsigned long V_5 ;
V_5 = V_17 -> V_26 >> V_45 ;
if ( V_44 )
V_5 += F_43 ( V_44 ) ;
return V_5 ;
}
static unsigned long F_44 ( struct V_41 * V_41 )
{
const struct V_23 * V_17 = & V_41 -> V_17 ;
return ( V_17 -> V_26 + F_31 ( V_17 ) ) >> V_45 ;
}
static void F_45 ( struct V_15 * V_16 , void * V_46 )
{
struct V_41 * V_41 = V_46 ;
struct V_23 * V_17 = & V_41 -> V_17 ;
T_2 V_47 , V_48 ;
struct V_42 * V_36 = & V_41 -> V_36 ;
unsigned long V_5 ;
F_46 (pfn, page_map)
F_47 ( F_9 ( V_5 ) ) ;
if ( F_48 ( V_36 -> V_49 ) ) {
F_49 ( V_16 , L_3 , V_50 ) ;
F_50 ( V_36 -> V_49 ) ;
}
V_47 = V_17 -> V_26 & ~ ( V_51 - 1 ) ;
V_48 = F_51 ( F_31 ( V_17 ) , V_51 ) ;
F_52 () ;
F_53 ( V_47 , V_48 ) ;
F_54 () ;
F_55 ( NULL , F_6 ( V_47 ) , V_48 ) ;
F_36 ( V_17 ) ;
F_56 ( V_16 , V_36 -> V_44 && V_36 -> V_44 -> V_52 ,
L_4 , V_50 ) ;
}
struct V_42 * F_57 ( T_2 V_53 )
{
struct V_41 * V_41 ;
F_58 ( ! F_59 () ) ;
V_41 = F_60 ( & V_40 , F_6 ( V_53 ) ) ;
return V_41 ? & V_41 -> V_36 : NULL ;
}
void * F_61 ( struct V_15 * V_16 , struct V_23 * V_17 ,
struct V_54 * V_49 , struct V_43 * V_44 )
{
T_2 V_47 , V_48 , V_55 ;
unsigned long V_5 , V_24 , V_38 ;
T_6 V_56 = V_57 ;
struct V_42 * V_36 ;
struct V_41 * V_41 ;
int error , V_58 , V_6 , V_59 = 0 ;
V_47 = V_17 -> V_26 & ~ ( V_51 - 1 ) ;
V_48 = F_51 ( V_17 -> V_26 + F_31 ( V_17 ) , V_51 )
- V_47 ;
V_6 = F_12 ( V_47 , V_48 ,
V_7 , V_8 ) ;
if ( V_6 == V_10 ) {
F_13 ( 1 , L_5 ,
V_50 , V_17 ) ;
return F_24 ( - V_22 ) ;
}
if ( V_6 == V_12 )
return F_10 ( V_17 -> V_26 ) ;
if ( ! V_49 )
return F_24 ( - V_60 ) ;
V_41 = F_22 ( F_45 ,
sizeof( * V_41 ) , V_20 , F_23 ( V_16 ) ) ;
if ( ! V_41 )
return F_24 ( - V_21 ) ;
V_36 = & V_41 -> V_36 ;
memcpy ( & V_41 -> V_17 , V_17 , sizeof( * V_17 ) ) ;
V_36 -> V_16 = V_16 ;
if ( V_44 ) {
memcpy ( & V_41 -> V_44 , V_44 , sizeof( * V_44 ) ) ;
V_36 -> V_44 = & V_41 -> V_44 ;
}
V_36 -> V_49 = V_49 ;
V_36 -> V_17 = & V_41 -> V_17 ;
V_36 -> type = V_61 ;
V_36 -> V_37 = NULL ;
V_36 -> V_62 = NULL ;
V_36 -> V_46 = NULL ;
F_37 ( & V_39 ) ;
error = 0 ;
V_55 = V_47 + V_48 - 1 ;
F_38 (res, order, pgoff) {
struct V_42 * V_63 ;
F_62 () ;
V_63 = F_57 ( V_17 -> V_26 + F_63 ( V_24 ) ) ;
F_64 () ;
if ( V_63 ) {
F_65 ( V_16 , L_6 ,
V_50 , V_17 , F_66 ( V_63 -> V_16 ) ) ;
error = - V_64 ;
break;
}
error = F_67 ( & V_40 ,
F_6 ( V_17 -> V_26 ) + V_24 , V_38 , V_41 ) ;
if ( error ) {
F_65 ( V_16 , L_7 , V_50 , error ) ;
break;
}
}
F_40 ( & V_39 ) ;
if ( error )
goto V_65;
V_58 = F_23 ( V_16 ) ;
if ( V_58 < 0 )
V_58 = F_68 () ;
error = F_69 ( NULL , & V_56 , F_6 ( V_47 ) , 0 ,
V_48 ) ;
if ( error )
goto V_66;
F_52 () ;
error = F_70 ( V_58 , V_47 , V_48 , false ) ;
if ( ! error )
F_71 ( & F_72 ( V_58 ) -> V_67 [ V_68 ] ,
V_47 >> V_45 ,
V_48 >> V_45 ) ;
F_54 () ;
if ( error )
goto V_69;
F_46 (pfn, page_map) {
struct V_35 * V_35 = F_9 ( V_5 ) ;
F_73 ( & V_35 -> V_70 ) ;
V_35 -> V_36 = V_36 ;
F_74 ( V_49 ) ;
if ( ! ( ++ V_59 % 1024 ) )
F_75 () ;
}
F_25 ( V_16 , V_41 ) ;
return F_10 ( V_17 -> V_26 ) ;
V_69:
F_55 ( NULL , F_6 ( V_47 ) , V_48 ) ;
V_66:
V_65:
F_36 ( V_17 ) ;
F_26 ( V_41 ) ;
return F_24 ( error ) ;
}
unsigned long F_43 ( struct V_43 * V_44 )
{
return V_44 -> V_71 + V_44 -> free ;
}
void F_76 ( struct V_43 * V_44 , unsigned long V_72 )
{
V_44 -> V_52 -= V_72 ;
}
struct V_43 * F_77 ( unsigned long V_73 )
{
struct V_35 * V_35 = (struct V_35 * ) V_73 ;
struct V_42 * V_36 ;
F_62 () ;
V_36 = F_57 ( F_78 ( F_79 ( V_35 ) ) ) ;
F_64 () ;
return V_36 ? V_36 -> V_44 : NULL ;
}
void F_80 ( struct V_35 * V_35 )
{
int V_74 = F_81 ( V_35 ) ;
if ( V_74 == 1 ) {
F_82 ( V_35 ) ;
F_83 ( V_35 ) ;
V_35 -> V_75 = NULL ;
F_84 ( V_35 ) ;
V_35 -> V_36 -> V_62 ( V_35 , V_35 -> V_36 -> V_46 ) ;
} else if ( ! V_74 )
F_85 ( V_35 ) ;
}
