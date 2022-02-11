static int F_1 ( struct V_1 * V_2 ,
const unsigned char * V_3 ,
const unsigned char * V_4 , T_1 V_5 )
{
int V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
V_8 = F_2 ( V_2 -> V_11 ) ;
if ( ! V_8 )
return 0 ;
V_10 = F_3 ( V_8 ) ;
if ( ! V_10 )
return 0 ;
V_6 = F_4 ( V_10 , V_3 , ( char * ) V_4 , V_5 ) ;
F_5 ( V_10 ) ;
return V_6 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_7 ( V_2 ) ;
if ( V_8 ) {
F_8 ( V_8 ) ;
F_9 ( V_8 ) ;
}
}
void F_10 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_11 ( V_2 ) ;
F_12 ( & V_2 -> V_12 ) ;
F_12 ( & V_2 -> V_13 ) ;
F_13 ( & V_2 -> V_14 ) ;
F_13 ( & V_2 -> V_15 ) ;
F_14 ( & V_2 -> V_16 ) ;
V_2 -> V_17 = ( 50 * V_18 ) / 100 ;
V_2 -> V_19 = ( 3000 * V_18 ) / 100 ;
V_2 -> V_20 = & V_21 ;
F_15 ( & V_2 -> V_22 ) ;
}
void F_16 ( struct V_1 * V_2 ,
struct V_23 * V_24 , unsigned V_25 )
{
if ( F_17 ( V_25 >= V_24 -> V_26 ) )
return;
V_24 -> V_27 [ V_25 ] = V_2 ;
}
struct V_28 * F_18 ( struct V_1 * V_2 ,
struct V_23 * V_24 , unsigned V_25 ,
struct V_28 * V_28 )
{
return F_19 ( V_2 , V_24 , V_25 , V_28 , NULL , NULL ) ;
}
struct V_28 * F_19 ( struct V_1 * V_2 ,
struct V_23 * V_24 , unsigned V_25 ,
struct V_28 * V_28 , void * V_29 ,
const struct V_30 * * V_31 )
{
struct V_28 * V_32 ;
F_16 ( V_2 , V_24 , V_25 ) ;
V_32 = F_20 ( V_2 , V_28 , V_24 , V_25 ) ;
if ( F_21 ( V_32 ) != - V_33 )
return V_32 ;
return F_22 ( V_24 , V_25 , V_28 , V_29 ,
V_31 ) ;
}
int F_23 ( struct V_1 * V_2 )
{
F_24 ( & V_2 -> V_15 ) ;
if ( V_2 -> V_34 == NULL )
V_2 -> V_34 = ( unsigned char * ) F_25 ( V_35 ) ;
F_26 ( & V_2 -> V_15 ) ;
if ( V_2 -> V_34 == NULL )
return - V_36 ;
return 0 ;
}
void F_27 ( struct V_1 * V_2 )
{
F_24 ( & V_2 -> V_15 ) ;
if ( V_2 -> V_34 != NULL ) {
F_28 ( ( unsigned long ) V_2 -> V_34 ) ;
V_2 -> V_34 = NULL ;
}
F_26 ( & V_2 -> V_15 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
F_30 ( V_2 ) ;
F_31 ( V_2 ) ;
}
static void F_32 ( struct V_22 * V_22 )
{
struct V_1 * V_2 = F_33 ( V_22 , struct V_1 , V_22 ) ;
if ( F_17 ( V_2 -> V_11 ) )
return;
F_34 ( V_2 ) ;
if ( V_2 -> V_34 )
F_28 ( ( unsigned long ) V_2 -> V_34 ) ;
F_29 ( V_2 ) ;
if ( V_2 -> V_37 && V_2 -> V_37 -> V_38 )
V_2 -> V_37 -> V_38 ( V_2 ) ;
else
F_35 ( V_2 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
if ( V_2 )
F_37 ( & V_2 -> V_22 , F_32 ) ;
}
struct V_7 * F_7 ( struct V_1 * V_2 )
{
unsigned long V_39 ;
struct V_7 * V_8 ;
F_38 ( & V_2 -> V_16 , V_39 ) ;
V_8 = F_39 ( V_2 -> V_8 ) ;
F_40 ( & V_2 -> V_16 , V_39 ) ;
return V_8 ;
}
void F_41 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
unsigned long V_39 ;
F_38 ( & V_2 -> V_16 , V_39 ) ;
F_9 ( V_2 -> V_8 ) ;
V_2 -> V_8 = F_39 ( V_8 ) ;
F_40 ( & V_2 -> V_16 , V_39 ) ;
}
static void F_42 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
F_24 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_40 )
goto V_41;
if ( F_43 ( V_2 ) ) {
F_44 ( V_2 , 0 ) ;
if ( V_8 && F_45 ( V_8 ) )
F_46 ( V_2 ) ;
if ( V_2 -> V_37 -> V_42 )
V_2 -> V_37 -> V_42 ( V_2 ) ;
}
V_41:
F_26 ( & V_2 -> V_14 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
unsigned long V_39 ;
F_38 ( & V_2 -> V_16 , V_39 ) ;
V_2 -> V_5 = 0 ;
V_8 = V_2 -> V_8 ;
if ( V_8 )
F_48 ( V_43 , & V_8 -> V_39 ) ;
V_2 -> V_8 = NULL ;
F_40 ( & V_2 -> V_16 , V_39 ) ;
F_49 ( V_2 , 0 ) ;
F_42 ( V_2 , V_8 ) ;
F_9 ( V_8 ) ;
F_50 ( & V_2 -> V_12 ) ;
F_50 ( & V_2 -> V_13 ) ;
}
void F_51 ( struct V_1 * V_2 , bool V_44 )
{
struct V_7 * V_8 = F_7 ( V_2 ) ;
if ( V_8 && ( ! V_44 || ! F_52 ( V_8 ) ) )
F_53 ( V_8 ) ;
F_9 ( V_8 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
V_2 -> V_20 -> V_45 ( V_2 ) ;
}
int F_55 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 -> V_46 == NULL )
return 1 ;
return V_2 -> V_37 -> V_46 ( V_2 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 -> V_47 )
V_2 -> V_37 -> V_47 ( V_2 , 1 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 -> V_47 )
V_2 -> V_37 -> V_47 ( V_2 , 0 ) ;
}
int F_57 ( struct V_1 * V_2 ,
struct V_7 * V_8 , struct V_48 * V_49 )
{
int V_50 = 0 , V_51 ;
unsigned long V_39 ;
F_58 ( V_52 ) ;
if ( F_59 ( V_8 ) ) {
F_49 ( V_2 , 1 ) ;
return 0 ;
}
if ( V_49 == NULL || ( V_49 -> V_53 & V_54 ) ) {
if ( F_60 ( V_8 ) )
F_56 ( V_2 ) ;
F_49 ( V_2 , 1 ) ;
return 0 ;
}
if ( F_52 ( V_8 ) )
V_50 = 1 ;
V_51 = 0 ;
F_38 ( & V_2 -> V_16 , V_39 ) ;
V_2 -> V_5 -- ;
V_2 -> V_55 ++ ;
F_40 ( & V_2 -> V_16 , V_39 ) ;
while ( 1 ) {
if ( F_60 ( V_8 ) && F_43 ( V_2 ) )
F_56 ( V_2 ) ;
F_61 ( & V_2 -> V_12 , & V_52 , V_56 ) ;
if ( F_62 ( V_49 ) || ! F_43 ( V_2 ) ) {
if ( V_2 -> V_39 & V_57 )
V_51 = - V_58 ;
else
V_51 = - V_59 ;
break;
}
if ( V_50 || F_55 ( V_2 ) )
break;
if ( F_63 ( V_60 ) ) {
V_51 = - V_59 ;
break;
}
F_64 ( V_8 ) ;
F_65 () ;
F_66 ( V_8 ) ;
}
F_67 ( & V_2 -> V_12 , & V_52 ) ;
F_38 ( & V_2 -> V_16 , V_39 ) ;
if ( ! F_62 ( V_49 ) )
V_2 -> V_5 ++ ;
V_2 -> V_55 -- ;
F_40 ( & V_2 -> V_16 , V_39 ) ;
if ( V_51 == 0 )
F_49 ( V_2 , 1 ) ;
return V_51 ;
}
static void F_68 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
unsigned int V_61 = F_69 ( V_8 ) ;
long V_62 ;
if ( V_61 > 1200 ) {
V_62 = ( V_18 * 10 * V_2 -> V_63 ) / V_61 ;
V_62 = F_70 ( long , V_62 , V_18 / 10 ) ;
} else {
V_62 = 2 * V_18 ;
}
F_71 ( V_62 ) ;
}
int F_72 ( struct V_1 * V_2 ,
struct V_7 * V_8 , struct V_48 * V_49 )
{
unsigned long V_39 ;
if ( F_62 ( V_49 ) )
return 0 ;
F_38 ( & V_2 -> V_16 , V_39 ) ;
if ( V_8 -> V_5 == 1 && V_2 -> V_5 != 1 ) {
F_73 ( V_8 , L_1 , V_64 ,
V_2 -> V_5 ) ;
V_2 -> V_5 = 1 ;
}
if ( -- V_2 -> V_5 < 0 ) {
F_73 ( V_8 , L_2 , V_64 ,
V_2 -> V_5 ) ;
V_2 -> V_5 = 0 ;
}
if ( V_2 -> V_5 ) {
F_40 ( & V_2 -> V_16 , V_39 ) ;
return 0 ;
}
F_40 ( & V_2 -> V_16 , V_39 ) ;
V_8 -> V_65 = 1 ;
if ( F_43 ( V_2 ) ) {
if ( V_8 -> V_66 )
F_74 ( V_8 ) ;
if ( V_2 -> V_19 != V_67 )
F_75 ( V_8 , V_2 -> V_19 ) ;
if ( V_2 -> V_63 )
F_68 ( V_2 , V_8 ) ;
}
F_76 ( V_8 ) ;
return 1 ;
}
void F_77 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
unsigned long V_39 ;
F_76 ( V_8 ) ;
V_8 -> V_65 = 0 ;
F_38 ( & V_2 -> V_16 , V_39 ) ;
if ( V_2 -> V_55 ) {
F_40 ( & V_2 -> V_16 , V_39 ) ;
if ( V_2 -> V_17 )
F_78 ( F_79 ( V_2 -> V_17 ) ) ;
F_38 ( & V_2 -> V_16 , V_39 ) ;
F_50 ( & V_2 -> V_12 ) ;
}
F_40 ( & V_2 -> V_16 , V_39 ) ;
F_49 ( V_2 , 0 ) ;
}
void F_80 ( struct V_1 * V_2 , struct V_7 * V_8 ,
struct V_48 * V_49 )
{
if ( F_72 ( V_2 , V_8 , V_49 ) == 0 )
return;
F_42 ( V_2 , V_8 ) ;
F_48 ( V_43 , & V_8 -> V_39 ) ;
F_77 ( V_2 , V_8 ) ;
F_41 ( V_2 , NULL ) ;
}
int F_81 ( struct V_1 * V_2 , struct V_23 * V_24 ,
struct V_7 * V_8 )
{
V_8 -> V_2 = V_2 ;
return F_82 ( V_24 , V_8 ) ;
}
int F_83 ( struct V_1 * V_2 , struct V_7 * V_8 ,
struct V_48 * V_49 )
{
F_84 ( & V_2 -> V_16 ) ;
++ V_2 -> V_5 ;
F_85 ( & V_2 -> V_16 ) ;
F_41 ( V_2 , V_8 ) ;
F_24 ( & V_2 -> V_14 ) ;
if ( ! F_43 ( V_2 ) ) {
F_86 ( V_43 , & V_8 -> V_39 ) ;
if ( V_2 -> V_37 -> V_68 ) {
int V_51 = V_2 -> V_37 -> V_68 ( V_2 , V_8 ) ;
if ( V_51 ) {
F_26 ( & V_2 -> V_14 ) ;
return V_51 ;
}
}
F_44 ( V_2 , 1 ) ;
}
F_26 ( & V_2 -> V_14 ) ;
return F_57 ( V_2 , V_8 , V_49 ) ;
}
