void F_1 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_2 ( V_2 ) ;
F_3 ( & V_2 -> V_3 ) ;
F_3 ( & V_2 -> V_4 ) ;
F_3 ( & V_2 -> V_5 ) ;
F_4 ( & V_2 -> V_6 ) ;
F_4 ( & V_2 -> V_7 ) ;
F_5 ( & V_2 -> V_8 ) ;
V_2 -> V_9 = ( 50 * V_10 ) / 100 ;
V_2 -> V_11 = ( 3000 * V_10 ) / 100 ;
F_6 ( & V_2 -> V_12 ) ;
}
void F_7 ( struct V_1 * V_2 ,
struct V_13 * V_14 , unsigned V_15 )
{
if ( F_8 ( V_15 >= V_14 -> V_16 ) )
return;
V_14 -> V_17 [ V_15 ] = V_2 ;
}
struct V_18 * F_9 ( struct V_1 * V_2 ,
struct V_13 * V_14 , unsigned V_15 ,
struct V_18 * V_18 )
{
F_7 ( V_2 , V_14 , V_15 ) ;
return F_10 ( V_14 , V_15 , V_18 ) ;
}
struct V_18 * F_11 ( struct V_1 * V_2 ,
struct V_13 * V_14 , unsigned V_15 ,
struct V_18 * V_18 , void * V_19 ,
const struct V_20 * * V_21 )
{
F_7 ( V_2 , V_14 , V_15 ) ;
return F_12 ( V_14 , V_15 , V_18 , V_19 ,
V_21 ) ;
}
int F_13 ( struct V_1 * V_2 )
{
F_14 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_22 == NULL )
V_2 -> V_22 = ( unsigned char * ) F_15 ( V_23 ) ;
F_16 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_22 == NULL )
return - V_24 ;
return 0 ;
}
void F_17 ( struct V_1 * V_2 )
{
F_14 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_22 != NULL ) {
F_18 ( ( unsigned long ) V_2 -> V_22 ) ;
V_2 -> V_22 = NULL ;
}
F_16 ( & V_2 -> V_7 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
F_20 ( & V_2 -> V_25 . V_26 ) ;
F_21 ( V_2 ) ;
}
static void F_22 ( struct V_12 * V_12 )
{
struct V_1 * V_2 = F_23 ( V_12 , struct V_1 , V_12 ) ;
if ( F_8 ( V_2 -> V_27 ) )
return;
if ( V_2 -> V_22 )
F_18 ( ( unsigned long ) V_2 -> V_22 ) ;
F_19 ( V_2 ) ;
if ( V_2 -> V_28 && V_2 -> V_28 -> V_29 )
V_2 -> V_28 -> V_29 ( V_2 ) ;
else
F_24 ( V_2 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
if ( V_2 )
F_26 ( & V_2 -> V_12 , F_22 ) ;
}
struct V_30 * F_27 ( struct V_1 * V_2 )
{
unsigned long V_31 ;
struct V_30 * V_32 ;
F_28 ( & V_2 -> V_8 , V_31 ) ;
V_32 = F_29 ( V_2 -> V_32 ) ;
F_30 ( & V_2 -> V_8 , V_31 ) ;
return V_32 ;
}
void F_31 ( struct V_1 * V_2 , struct V_30 * V_32 )
{
unsigned long V_31 ;
F_28 ( & V_2 -> V_8 , V_31 ) ;
if ( V_2 -> V_32 )
F_32 ( V_2 -> V_32 ) ;
V_2 -> V_32 = F_29 ( V_32 ) ;
F_30 ( & V_2 -> V_8 , V_31 ) ;
}
static void F_33 ( struct V_1 * V_2 , struct V_30 * V_32 )
{
F_14 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_33 )
goto V_34;
if ( F_34 ( V_35 , & V_2 -> V_31 ) ) {
if ( V_32 && F_35 ( V_32 ) )
F_36 ( V_2 ) ;
if ( V_2 -> V_28 -> V_36 )
V_2 -> V_28 -> V_36 ( V_2 ) ;
}
V_34:
F_16 ( & V_2 -> V_6 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
struct V_30 * V_32 ;
unsigned long V_31 ;
F_28 ( & V_2 -> V_8 , V_31 ) ;
V_2 -> V_37 = 0 ;
V_2 -> V_31 &= ~ V_38 ;
V_32 = V_2 -> V_32 ;
if ( V_32 )
F_38 ( V_39 , & V_32 -> V_31 ) ;
V_2 -> V_32 = NULL ;
F_30 ( & V_2 -> V_8 , V_31 ) ;
F_33 ( V_2 , V_32 ) ;
F_32 ( V_32 ) ;
F_39 ( & V_2 -> V_3 ) ;
F_39 ( & V_2 -> V_5 ) ;
}
void F_40 ( struct V_1 * V_2 , bool V_40 )
{
struct V_30 * V_32 = F_27 ( V_2 ) ;
if ( V_32 && ( ! V_40 || ! F_41 ( V_32 ) ) )
F_42 ( V_32 ) ;
F_32 ( V_32 ) ;
}
void F_43 ( struct V_1 * V_2 )
{
struct V_30 * V_32 = F_27 ( V_2 ) ;
if ( V_32 ) {
F_44 ( V_32 ) ;
F_32 ( V_32 ) ;
}
}
int F_45 ( struct V_1 * V_2 )
{
if ( V_2 -> V_28 -> V_41 == NULL )
return 1 ;
return V_2 -> V_28 -> V_41 ( V_2 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
if ( V_2 -> V_28 -> V_42 )
V_2 -> V_28 -> V_42 ( V_2 , 1 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
if ( V_2 -> V_28 -> V_42 )
V_2 -> V_28 -> V_42 ( V_2 , 0 ) ;
}
int F_47 ( struct V_1 * V_2 ,
struct V_30 * V_32 , struct V_43 * V_44 )
{
int V_45 = 0 , V_46 ;
unsigned long V_31 ;
F_48 ( V_47 ) ;
if ( F_49 ( V_44 ) || V_2 -> V_31 & V_48 ) {
F_50 ( V_32 , V_2 -> V_4 ,
! ( V_2 -> V_31 & V_48 ) ) ;
if ( V_2 -> V_31 & V_49 )
return - V_50 ;
else
return - V_51 ;
}
if ( V_32 -> V_31 & ( 1 << V_39 ) ) {
V_2 -> V_31 |= V_38 ;
return 0 ;
}
if ( V_44 -> V_52 & V_53 ) {
if ( V_32 -> V_54 . V_55 & V_56 )
F_46 ( V_2 ) ;
V_2 -> V_31 |= V_38 ;
return 0 ;
}
if ( F_41 ( V_32 ) )
V_45 = 1 ;
V_46 = 0 ;
F_28 ( & V_2 -> V_8 , V_31 ) ;
if ( ! F_49 ( V_44 ) )
V_2 -> V_37 -- ;
V_2 -> V_57 ++ ;
F_30 ( & V_2 -> V_8 , V_31 ) ;
while ( 1 ) {
if ( F_51 ( V_32 ) && F_52 ( V_35 , & V_2 -> V_31 ) )
F_46 ( V_2 ) ;
F_53 ( & V_2 -> V_3 , & V_47 , V_58 ) ;
if ( F_49 ( V_44 ) || ! ( V_2 -> V_31 & V_59 ) ) {
if ( V_2 -> V_31 & V_49 )
V_46 = - V_50 ;
else
V_46 = - V_51 ;
break;
}
if ( ! ( V_2 -> V_31 & V_48 ) &&
( V_45 || F_45 ( V_2 ) ) )
break;
if ( F_54 ( V_60 ) ) {
V_46 = - V_51 ;
break;
}
F_55 ( V_32 ) ;
F_56 () ;
F_57 ( V_32 ) ;
}
F_58 ( & V_2 -> V_3 , & V_47 ) ;
F_28 ( & V_2 -> V_8 , V_31 ) ;
if ( ! F_49 ( V_44 ) )
V_2 -> V_37 ++ ;
V_2 -> V_57 -- ;
if ( V_46 == 0 )
V_2 -> V_31 |= V_38 ;
F_30 ( & V_2 -> V_8 , V_31 ) ;
return V_46 ;
}
static void F_59 ( struct V_1 * V_2 , struct V_30 * V_32 )
{
unsigned int V_61 = F_60 ( V_32 ) ;
long V_62 ;
if ( V_61 > 1200 ) {
V_62 = ( V_10 * 10 * V_2 -> V_63 ) / V_61 ;
V_62 = F_61 ( long , V_62 , V_10 / 10 ) ;
} else {
V_62 = 2 * V_10 ;
}
F_62 ( V_62 ) ;
}
int F_63 ( struct V_1 * V_2 ,
struct V_30 * V_32 , struct V_43 * V_44 )
{
unsigned long V_31 ;
F_28 ( & V_2 -> V_8 , V_31 ) ;
if ( F_49 ( V_44 ) ) {
F_30 ( & V_2 -> V_8 , V_31 ) ;
return 0 ;
}
if ( V_32 -> V_37 == 1 && V_2 -> V_37 != 1 ) {
F_64 ( V_64
L_1 ,
V_2 -> V_37 ) ;
V_2 -> V_37 = 1 ;
}
if ( -- V_2 -> V_37 < 0 ) {
F_64 ( V_64 L_2 ,
V_2 -> V_37 ) ;
V_2 -> V_37 = 0 ;
}
if ( V_2 -> V_37 ) {
F_30 ( & V_2 -> V_8 , V_31 ) ;
return 0 ;
}
F_38 ( V_65 , & V_2 -> V_31 ) ;
V_32 -> V_66 = 1 ;
F_30 ( & V_2 -> V_8 , V_31 ) ;
if ( F_52 ( V_35 , & V_2 -> V_31 ) ) {
if ( V_32 -> V_67 )
F_65 ( V_32 ) ;
if ( V_2 -> V_11 != V_68 )
F_66 ( V_32 , V_2 -> V_11 ) ;
if ( V_2 -> V_63 )
F_59 ( V_2 , V_32 ) ;
}
F_67 ( V_32 ) ;
return 1 ;
}
void F_68 ( struct V_1 * V_2 , struct V_30 * V_32 )
{
unsigned long V_31 ;
F_28 ( & V_2 -> V_8 , V_31 ) ;
V_32 -> V_66 = 0 ;
if ( V_2 -> V_57 ) {
F_30 ( & V_2 -> V_8 , V_31 ) ;
if ( V_2 -> V_9 ) {
F_69 (
F_70 ( V_2 -> V_9 ) ) ;
}
F_28 ( & V_2 -> V_8 , V_31 ) ;
F_39 ( & V_2 -> V_3 ) ;
}
V_2 -> V_31 &= ~ ( V_38 | V_48 ) ;
F_39 ( & V_2 -> V_4 ) ;
F_30 ( & V_2 -> V_8 , V_31 ) ;
}
void F_71 ( struct V_1 * V_2 , struct V_30 * V_32 ,
struct V_43 * V_44 )
{
if ( F_63 ( V_2 , V_32 , V_44 ) == 0 )
return;
F_33 ( V_2 , V_32 ) ;
F_38 ( V_39 , & V_32 -> V_31 ) ;
F_68 ( V_2 , V_32 ) ;
F_31 ( V_2 , NULL ) ;
}
int F_72 ( struct V_1 * V_2 , struct V_13 * V_14 ,
struct V_30 * V_32 )
{
V_32 -> V_2 = V_2 ;
return F_73 ( V_14 , V_32 ) ;
}
int F_74 ( struct V_1 * V_2 , struct V_30 * V_32 ,
struct V_43 * V_44 )
{
F_75 ( & V_2 -> V_8 ) ;
if ( ! F_49 ( V_44 ) )
++ V_2 -> V_37 ;
F_76 ( & V_2 -> V_8 ) ;
F_31 ( V_2 , V_32 ) ;
F_14 ( & V_2 -> V_6 ) ;
if ( ! F_52 ( V_35 , & V_2 -> V_31 ) ) {
F_77 ( V_39 , & V_32 -> V_31 ) ;
if ( V_2 -> V_28 -> V_69 ) {
int V_46 = V_2 -> V_28 -> V_69 ( V_2 , V_32 ) ;
if ( V_46 ) {
F_16 ( & V_2 -> V_6 ) ;
return V_46 ;
}
}
F_38 ( V_35 , & V_2 -> V_31 ) ;
}
F_16 ( & V_2 -> V_6 ) ;
return F_47 ( V_2 , V_32 , V_44 ) ;
}
