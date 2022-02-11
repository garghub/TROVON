void F_1 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_2 ( V_2 ) ;
F_3 ( & V_2 -> V_3 ) ;
F_3 ( & V_2 -> V_4 ) ;
F_4 ( & V_2 -> V_5 ) ;
F_4 ( & V_2 -> V_6 ) ;
F_5 ( & V_2 -> V_7 ) ;
V_2 -> V_8 = ( 50 * V_9 ) / 100 ;
V_2 -> V_10 = ( 3000 * V_9 ) / 100 ;
F_6 ( & V_2 -> V_11 ) ;
}
void F_7 ( struct V_1 * V_2 ,
struct V_12 * V_13 , unsigned V_14 )
{
if ( F_8 ( V_14 >= V_13 -> V_15 ) )
return;
V_13 -> V_16 [ V_14 ] = V_2 ;
}
struct V_17 * F_9 ( struct V_1 * V_2 ,
struct V_12 * V_13 , unsigned V_14 ,
struct V_17 * V_17 )
{
F_7 ( V_2 , V_13 , V_14 ) ;
return F_10 ( V_13 , V_14 , V_17 ) ;
}
struct V_17 * F_11 ( struct V_1 * V_2 ,
struct V_12 * V_13 , unsigned V_14 ,
struct V_17 * V_17 , void * V_18 ,
const struct V_19 * * V_20 )
{
F_7 ( V_2 , V_13 , V_14 ) ;
return F_12 ( V_13 , V_14 , V_17 , V_18 ,
V_20 ) ;
}
int F_13 ( struct V_1 * V_2 )
{
F_14 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_21 == NULL )
V_2 -> V_21 = ( unsigned char * ) F_15 ( V_22 ) ;
F_16 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_21 == NULL )
return - V_23 ;
return 0 ;
}
void F_17 ( struct V_1 * V_2 )
{
F_14 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_21 != NULL ) {
F_18 ( ( unsigned long ) V_2 -> V_21 ) ;
V_2 -> V_21 = NULL ;
}
F_16 ( & V_2 -> V_6 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
}
static void F_22 ( struct V_11 * V_11 )
{
struct V_1 * V_2 = F_23 ( V_11 , struct V_1 , V_11 ) ;
if ( F_8 ( V_2 -> V_24 ) )
return;
if ( V_2 -> V_21 )
F_18 ( ( unsigned long ) V_2 -> V_21 ) ;
F_19 ( V_2 ) ;
if ( V_2 -> V_25 && V_2 -> V_25 -> V_26 )
V_2 -> V_25 -> V_26 ( V_2 ) ;
else
F_24 ( V_2 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
if ( V_2 )
F_26 ( & V_2 -> V_11 , F_22 ) ;
}
struct V_27 * F_27 ( struct V_1 * V_2 )
{
unsigned long V_28 ;
struct V_27 * V_29 ;
F_28 ( & V_2 -> V_7 , V_28 ) ;
V_29 = F_29 ( V_2 -> V_29 ) ;
F_30 ( & V_2 -> V_7 , V_28 ) ;
return V_29 ;
}
void F_31 ( struct V_1 * V_2 , struct V_27 * V_29 )
{
unsigned long V_28 ;
F_28 ( & V_2 -> V_7 , V_28 ) ;
F_32 ( V_2 -> V_29 ) ;
V_2 -> V_29 = F_29 ( V_29 ) ;
F_30 ( & V_2 -> V_7 , V_28 ) ;
}
static void F_33 ( struct V_1 * V_2 , struct V_27 * V_29 )
{
F_14 ( & V_2 -> V_5 ) ;
if ( V_2 -> V_30 )
goto V_31;
if ( F_34 ( V_32 , & V_2 -> V_28 ) ) {
if ( V_29 && F_35 ( V_29 ) )
F_36 ( V_2 ) ;
if ( V_2 -> V_25 -> V_33 )
V_2 -> V_25 -> V_33 ( V_2 ) ;
}
V_31:
F_16 ( & V_2 -> V_5 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
struct V_27 * V_29 ;
unsigned long V_28 ;
F_28 ( & V_2 -> V_7 , V_28 ) ;
V_2 -> V_34 = 0 ;
V_2 -> V_28 &= ~ V_35 ;
V_29 = V_2 -> V_29 ;
if ( V_29 )
F_38 ( V_36 , & V_29 -> V_28 ) ;
V_2 -> V_29 = NULL ;
F_30 ( & V_2 -> V_7 , V_28 ) ;
F_33 ( V_2 , V_29 ) ;
F_32 ( V_29 ) ;
F_39 ( & V_2 -> V_3 ) ;
F_39 ( & V_2 -> V_4 ) ;
}
void F_40 ( struct V_1 * V_2 , bool V_37 )
{
struct V_27 * V_29 = F_27 ( V_2 ) ;
if ( V_29 && ( ! V_37 || ! F_41 ( V_29 ) ) )
F_42 ( V_29 ) ;
F_32 ( V_29 ) ;
}
void F_43 ( struct V_1 * V_2 )
{
struct V_27 * V_29 = F_27 ( V_2 ) ;
if ( V_29 ) {
F_44 ( V_29 ) ;
F_32 ( V_29 ) ;
}
}
int F_45 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 -> V_38 == NULL )
return 1 ;
return V_2 -> V_25 -> V_38 ( V_2 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 -> V_39 )
V_2 -> V_25 -> V_39 ( V_2 , 1 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 -> V_39 )
V_2 -> V_25 -> V_39 ( V_2 , 0 ) ;
}
int F_47 ( struct V_1 * V_2 ,
struct V_27 * V_29 , struct V_40 * V_41 )
{
int V_42 = 0 , V_43 ;
unsigned long V_28 ;
F_48 ( V_44 ) ;
if ( V_29 -> V_28 & ( 1 << V_36 ) ) {
V_2 -> V_28 |= V_35 ;
return 0 ;
}
if ( V_41 -> V_45 & V_46 ) {
if ( V_29 -> V_47 . V_48 & V_49 )
F_46 ( V_2 ) ;
V_2 -> V_28 |= V_35 ;
return 0 ;
}
if ( F_41 ( V_29 ) )
V_42 = 1 ;
V_43 = 0 ;
F_28 ( & V_2 -> V_7 , V_28 ) ;
V_2 -> V_34 -- ;
V_2 -> V_50 ++ ;
F_30 ( & V_2 -> V_7 , V_28 ) ;
while ( 1 ) {
if ( F_49 ( V_29 ) && F_50 ( V_32 , & V_2 -> V_28 ) )
F_46 ( V_2 ) ;
F_51 ( & V_2 -> V_3 , & V_44 , V_51 ) ;
if ( F_52 ( V_41 ) || ! ( V_2 -> V_28 & V_52 ) ) {
if ( V_2 -> V_28 & V_53 )
V_43 = - V_54 ;
else
V_43 = - V_55 ;
break;
}
if ( V_42 || F_45 ( V_2 ) )
break;
if ( F_53 ( V_56 ) ) {
V_43 = - V_55 ;
break;
}
F_54 ( V_29 ) ;
F_55 () ;
F_56 ( V_29 ) ;
}
F_57 ( & V_2 -> V_3 , & V_44 ) ;
F_28 ( & V_2 -> V_7 , V_28 ) ;
if ( ! F_52 ( V_41 ) )
V_2 -> V_34 ++ ;
V_2 -> V_50 -- ;
if ( V_43 == 0 )
V_2 -> V_28 |= V_35 ;
F_30 ( & V_2 -> V_7 , V_28 ) ;
return V_43 ;
}
static void F_58 ( struct V_1 * V_2 , struct V_27 * V_29 )
{
unsigned int V_57 = F_59 ( V_29 ) ;
long V_58 ;
if ( V_57 > 1200 ) {
V_58 = ( V_9 * 10 * V_2 -> V_59 ) / V_57 ;
V_58 = F_60 ( long , V_58 , V_9 / 10 ) ;
} else {
V_58 = 2 * V_9 ;
}
F_61 ( V_58 ) ;
}
int F_62 ( struct V_1 * V_2 ,
struct V_27 * V_29 , struct V_40 * V_41 )
{
unsigned long V_28 ;
if ( F_52 ( V_41 ) )
return 0 ;
F_28 ( & V_2 -> V_7 , V_28 ) ;
if ( V_29 -> V_34 == 1 && V_2 -> V_34 != 1 ) {
F_63 ( V_60
L_1 ,
V_2 -> V_34 ) ;
V_2 -> V_34 = 1 ;
}
if ( -- V_2 -> V_34 < 0 ) {
F_63 ( V_60 L_2 ,
V_2 -> V_34 ) ;
V_2 -> V_34 = 0 ;
}
if ( V_2 -> V_34 ) {
F_30 ( & V_2 -> V_7 , V_28 ) ;
return 0 ;
}
F_38 ( V_61 , & V_2 -> V_28 ) ;
F_30 ( & V_2 -> V_7 , V_28 ) ;
V_29 -> V_62 = 1 ;
if ( F_50 ( V_32 , & V_2 -> V_28 ) ) {
if ( V_29 -> V_63 )
F_64 ( V_29 ) ;
if ( V_2 -> V_10 != V_64 )
F_65 ( V_29 , V_2 -> V_10 ) ;
if ( V_2 -> V_59 )
F_58 ( V_2 , V_29 ) ;
}
F_66 ( V_29 ) ;
return 1 ;
}
void F_67 ( struct V_1 * V_2 , struct V_27 * V_29 )
{
unsigned long V_28 ;
F_66 ( V_29 ) ;
V_29 -> V_62 = 0 ;
F_28 ( & V_2 -> V_7 , V_28 ) ;
if ( V_2 -> V_50 ) {
F_30 ( & V_2 -> V_7 , V_28 ) ;
if ( V_2 -> V_8 ) {
F_68 (
F_69 ( V_2 -> V_8 ) ) ;
}
F_28 ( & V_2 -> V_7 , V_28 ) ;
F_39 ( & V_2 -> V_3 ) ;
}
V_2 -> V_28 &= ~ ( V_35 | V_65 ) ;
F_30 ( & V_2 -> V_7 , V_28 ) ;
}
void F_70 ( struct V_1 * V_2 , struct V_27 * V_29 ,
struct V_40 * V_41 )
{
if ( F_62 ( V_2 , V_29 , V_41 ) == 0 )
return;
F_33 ( V_2 , V_29 ) ;
F_38 ( V_36 , & V_29 -> V_28 ) ;
F_67 ( V_2 , V_29 ) ;
F_31 ( V_2 , NULL ) ;
}
int F_71 ( struct V_1 * V_2 , struct V_12 * V_13 ,
struct V_27 * V_29 )
{
V_29 -> V_2 = V_2 ;
return F_72 ( V_13 , V_29 ) ;
}
int F_73 ( struct V_1 * V_2 , struct V_27 * V_29 ,
struct V_40 * V_41 )
{
F_74 ( & V_2 -> V_7 ) ;
++ V_2 -> V_34 ;
F_75 ( & V_2 -> V_7 ) ;
F_31 ( V_2 , V_29 ) ;
F_14 ( & V_2 -> V_5 ) ;
if ( ! F_50 ( V_32 , & V_2 -> V_28 ) ) {
F_76 ( V_36 , & V_29 -> V_28 ) ;
if ( V_2 -> V_25 -> V_66 ) {
int V_43 = V_2 -> V_25 -> V_66 ( V_2 , V_29 ) ;
if ( V_43 ) {
F_16 ( & V_2 -> V_5 ) ;
return V_43 ;
}
}
F_38 ( V_32 , & V_2 -> V_28 ) ;
}
F_16 ( & V_2 -> V_5 ) ;
return F_47 ( V_2 , V_29 , V_41 ) ;
}
