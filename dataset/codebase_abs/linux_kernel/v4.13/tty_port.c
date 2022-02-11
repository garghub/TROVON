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
F_16 ( V_2 , V_24 , V_25 ) ;
return F_20 ( V_24 , V_25 , V_28 , V_29 ,
V_31 ) ;
}
struct V_28 * F_21 ( struct V_1 * V_2 ,
struct V_23 * V_24 , unsigned V_25 ,
struct V_28 * V_28 , void * V_29 ,
const struct V_30 * * V_31 )
{
struct V_28 * V_32 ;
F_16 ( V_2 , V_24 , V_25 ) ;
V_32 = F_22 ( V_2 , V_28 , V_24 , V_25 ) ;
if ( F_23 ( V_32 ) != - V_33 ) {
return V_32 ;
}
return F_20 ( V_24 , V_25 , V_28 , V_29 ,
V_31 ) ;
}
struct V_28 * F_24 ( struct V_1 * V_2 ,
struct V_23 * V_24 , unsigned V_25 ,
struct V_28 * V_28 )
{
return F_21 ( V_2 , V_24 , V_25 ,
V_28 , NULL , NULL ) ;
}
void F_25 ( struct V_1 * V_2 ,
struct V_23 * V_24 , unsigned V_25 )
{
int V_6 ;
V_6 = F_26 ( V_2 ) ;
if ( V_6 == 0 )
return;
F_27 ( V_24 , V_25 ) ;
}
int F_28 ( struct V_1 * V_2 )
{
F_29 ( & V_2 -> V_15 ) ;
if ( V_2 -> V_34 == NULL )
V_2 -> V_34 = ( unsigned char * ) F_30 ( V_35 ) ;
F_31 ( & V_2 -> V_15 ) ;
if ( V_2 -> V_34 == NULL )
return - V_36 ;
return 0 ;
}
void F_32 ( struct V_1 * V_2 )
{
F_29 ( & V_2 -> V_15 ) ;
if ( V_2 -> V_34 != NULL ) {
F_33 ( ( unsigned long ) V_2 -> V_34 ) ;
V_2 -> V_34 = NULL ;
}
F_31 ( & V_2 -> V_15 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
}
static void F_37 ( struct V_22 * V_22 )
{
struct V_1 * V_2 = F_38 ( V_22 , struct V_1 , V_22 ) ;
if ( F_17 ( V_2 -> V_11 ) )
return;
if ( V_2 -> V_34 )
F_33 ( ( unsigned long ) V_2 -> V_34 ) ;
F_34 ( V_2 ) ;
if ( V_2 -> V_37 && V_2 -> V_37 -> V_38 )
V_2 -> V_37 -> V_38 ( V_2 ) ;
else
F_39 ( V_2 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
if ( V_2 )
F_41 ( & V_2 -> V_22 , F_37 ) ;
}
struct V_7 * F_7 ( struct V_1 * V_2 )
{
unsigned long V_39 ;
struct V_7 * V_8 ;
F_42 ( & V_2 -> V_16 , V_39 ) ;
V_8 = F_43 ( V_2 -> V_8 ) ;
F_44 ( & V_2 -> V_16 , V_39 ) ;
return V_8 ;
}
void F_45 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
unsigned long V_39 ;
F_42 ( & V_2 -> V_16 , V_39 ) ;
F_9 ( V_2 -> V_8 ) ;
V_2 -> V_8 = F_43 ( V_8 ) ;
F_44 ( & V_2 -> V_16 , V_39 ) ;
}
static void F_46 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
F_29 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_40 )
goto V_41;
if ( F_47 ( V_2 ) ) {
F_48 ( V_2 , 0 ) ;
if ( V_8 && F_49 ( V_8 ) )
F_50 ( V_2 ) ;
if ( V_2 -> V_37 -> V_42 )
V_2 -> V_37 -> V_42 ( V_2 ) ;
}
V_41:
F_31 ( & V_2 -> V_14 ) ;
}
void F_51 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
unsigned long V_39 ;
F_42 ( & V_2 -> V_16 , V_39 ) ;
V_2 -> V_5 = 0 ;
V_8 = V_2 -> V_8 ;
if ( V_8 )
F_52 ( V_43 , & V_8 -> V_39 ) ;
V_2 -> V_8 = NULL ;
F_44 ( & V_2 -> V_16 , V_39 ) ;
F_53 ( V_2 , 0 ) ;
F_46 ( V_2 , V_8 ) ;
F_9 ( V_8 ) ;
F_54 ( & V_2 -> V_12 ) ;
F_54 ( & V_2 -> V_13 ) ;
}
void F_55 ( struct V_1 * V_2 , bool V_44 )
{
struct V_7 * V_8 = F_7 ( V_2 ) ;
if ( V_8 && ( ! V_44 || ! F_56 ( V_8 ) ) )
F_57 ( V_8 ) ;
F_9 ( V_8 ) ;
}
void F_58 ( struct V_1 * V_2 )
{
V_2 -> V_20 -> V_45 ( V_2 ) ;
}
int F_59 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 -> V_46 == NULL )
return 1 ;
return V_2 -> V_37 -> V_46 ( V_2 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 -> V_47 )
V_2 -> V_37 -> V_47 ( V_2 , 1 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 -> V_47 )
V_2 -> V_37 -> V_47 ( V_2 , 0 ) ;
}
int F_61 ( struct V_1 * V_2 ,
struct V_7 * V_8 , struct V_48 * V_49 )
{
int V_50 = 0 , V_51 ;
unsigned long V_39 ;
F_62 ( V_52 ) ;
if ( F_63 ( V_8 ) ) {
F_53 ( V_2 , 1 ) ;
return 0 ;
}
if ( V_49 == NULL || ( V_49 -> V_53 & V_54 ) ) {
if ( F_64 ( V_8 ) )
F_60 ( V_2 ) ;
F_53 ( V_2 , 1 ) ;
return 0 ;
}
if ( F_56 ( V_8 ) )
V_50 = 1 ;
V_51 = 0 ;
F_42 ( & V_2 -> V_16 , V_39 ) ;
V_2 -> V_5 -- ;
V_2 -> V_55 ++ ;
F_44 ( & V_2 -> V_16 , V_39 ) ;
while ( 1 ) {
if ( F_64 ( V_8 ) && F_47 ( V_2 ) )
F_60 ( V_2 ) ;
F_65 ( & V_2 -> V_12 , & V_52 , V_56 ) ;
if ( F_66 ( V_49 ) || ! F_47 ( V_2 ) ) {
if ( V_2 -> V_39 & V_57 )
V_51 = - V_58 ;
else
V_51 = - V_59 ;
break;
}
if ( V_50 || F_59 ( V_2 ) )
break;
if ( F_67 ( V_60 ) ) {
V_51 = - V_59 ;
break;
}
F_68 ( V_8 ) ;
F_69 () ;
F_70 ( V_8 ) ;
}
F_71 ( & V_2 -> V_12 , & V_52 ) ;
F_42 ( & V_2 -> V_16 , V_39 ) ;
if ( ! F_66 ( V_49 ) )
V_2 -> V_5 ++ ;
V_2 -> V_55 -- ;
F_44 ( & V_2 -> V_16 , V_39 ) ;
if ( V_51 == 0 )
F_53 ( V_2 , 1 ) ;
return V_51 ;
}
static void F_72 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
unsigned int V_61 = F_73 ( V_8 ) ;
long V_62 ;
if ( V_61 > 1200 ) {
V_62 = ( V_18 * 10 * V_2 -> V_63 ) / V_61 ;
V_62 = F_74 ( long , V_62 , V_18 / 10 ) ;
} else {
V_62 = 2 * V_18 ;
}
F_75 ( V_62 ) ;
}
int F_76 ( struct V_1 * V_2 ,
struct V_7 * V_8 , struct V_48 * V_49 )
{
unsigned long V_39 ;
if ( F_66 ( V_49 ) )
return 0 ;
F_42 ( & V_2 -> V_16 , V_39 ) ;
if ( V_8 -> V_5 == 1 && V_2 -> V_5 != 1 ) {
F_77 ( V_8 , L_1 , V_64 ,
V_2 -> V_5 ) ;
V_2 -> V_5 = 1 ;
}
if ( -- V_2 -> V_5 < 0 ) {
F_77 ( V_8 , L_2 , V_64 ,
V_2 -> V_5 ) ;
V_2 -> V_5 = 0 ;
}
if ( V_2 -> V_5 ) {
F_44 ( & V_2 -> V_16 , V_39 ) ;
return 0 ;
}
F_44 ( & V_2 -> V_16 , V_39 ) ;
V_8 -> V_65 = 1 ;
if ( F_47 ( V_2 ) ) {
if ( V_8 -> V_66 )
F_78 ( V_8 ) ;
if ( V_2 -> V_19 != V_67 )
F_79 ( V_8 , V_2 -> V_19 ) ;
if ( V_2 -> V_63 )
F_72 ( V_2 , V_8 ) ;
}
F_80 ( V_8 ) ;
return 1 ;
}
void F_81 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
unsigned long V_39 ;
F_80 ( V_8 ) ;
V_8 -> V_65 = 0 ;
F_42 ( & V_2 -> V_16 , V_39 ) ;
if ( V_2 -> V_55 ) {
F_44 ( & V_2 -> V_16 , V_39 ) ;
if ( V_2 -> V_17 )
F_82 ( F_83 ( V_2 -> V_17 ) ) ;
F_42 ( & V_2 -> V_16 , V_39 ) ;
F_54 ( & V_2 -> V_12 ) ;
}
F_44 ( & V_2 -> V_16 , V_39 ) ;
F_53 ( V_2 , 0 ) ;
}
void F_84 ( struct V_1 * V_2 , struct V_7 * V_8 ,
struct V_48 * V_49 )
{
if ( F_76 ( V_2 , V_8 , V_49 ) == 0 )
return;
F_46 ( V_2 , V_8 ) ;
F_52 ( V_43 , & V_8 -> V_39 ) ;
F_81 ( V_2 , V_8 ) ;
F_45 ( V_2 , NULL ) ;
}
int F_85 ( struct V_1 * V_2 , struct V_23 * V_24 ,
struct V_7 * V_8 )
{
V_8 -> V_2 = V_2 ;
return F_86 ( V_24 , V_8 ) ;
}
int F_87 ( struct V_1 * V_2 , struct V_7 * V_8 ,
struct V_48 * V_49 )
{
F_88 ( & V_2 -> V_16 ) ;
++ V_2 -> V_5 ;
F_89 ( & V_2 -> V_16 ) ;
F_45 ( V_2 , V_8 ) ;
F_29 ( & V_2 -> V_14 ) ;
if ( ! F_47 ( V_2 ) ) {
F_90 ( V_43 , & V_8 -> V_39 ) ;
if ( V_2 -> V_37 -> V_68 ) {
int V_51 = V_2 -> V_37 -> V_68 ( V_2 , V_8 ) ;
if ( V_51 ) {
F_31 ( & V_2 -> V_14 ) ;
return V_51 ;
}
}
F_48 ( V_2 , 1 ) ;
}
F_31 ( & V_2 -> V_14 ) ;
return F_61 ( V_2 , V_8 , V_49 ) ;
}
