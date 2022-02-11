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
F_20 ( V_2 ) ;
}
static void F_21 ( struct V_12 * V_12 )
{
struct V_1 * V_2 = F_22 ( V_12 , struct V_1 , V_12 ) ;
if ( V_2 -> V_22 )
F_18 ( ( unsigned long ) V_2 -> V_22 ) ;
F_19 ( V_2 ) ;
if ( V_2 -> V_25 && V_2 -> V_25 -> V_26 )
V_2 -> V_25 -> V_26 ( V_2 ) ;
else
F_23 ( V_2 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
if ( V_2 )
F_25 ( & V_2 -> V_12 , F_21 ) ;
}
struct V_27 * F_26 ( struct V_1 * V_2 )
{
unsigned long V_28 ;
struct V_27 * V_29 ;
F_27 ( & V_2 -> V_8 , V_28 ) ;
V_29 = F_28 ( V_2 -> V_29 ) ;
F_29 ( & V_2 -> V_8 , V_28 ) ;
return V_29 ;
}
void F_30 ( struct V_1 * V_2 , struct V_27 * V_29 )
{
unsigned long V_28 ;
F_27 ( & V_2 -> V_8 , V_28 ) ;
if ( V_2 -> V_29 )
F_31 ( V_2 -> V_29 ) ;
V_2 -> V_29 = F_28 ( V_29 ) ;
F_29 ( & V_2 -> V_8 , V_28 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_14 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_25 -> V_30 && ! V_2 -> V_31 &&
F_33 ( V_32 , & V_2 -> V_28 ) )
V_2 -> V_25 -> V_30 ( V_2 ) ;
F_16 ( & V_2 -> V_6 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
unsigned long V_28 ;
F_27 ( & V_2 -> V_8 , V_28 ) ;
V_2 -> V_33 = 0 ;
V_2 -> V_28 &= ~ V_34 ;
if ( V_2 -> V_29 ) {
F_35 ( V_35 , & V_2 -> V_29 -> V_28 ) ;
F_31 ( V_2 -> V_29 ) ;
}
V_2 -> V_29 = NULL ;
F_29 ( & V_2 -> V_8 , V_28 ) ;
F_36 ( & V_2 -> V_3 ) ;
F_36 ( & V_2 -> V_5 ) ;
F_32 ( V_2 ) ;
}
int F_37 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 -> V_36 == NULL )
return 1 ;
return V_2 -> V_25 -> V_36 ( V_2 ) ;
}
void F_38 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 -> V_37 )
V_2 -> V_25 -> V_37 ( V_2 , 1 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 -> V_37 )
V_2 -> V_25 -> V_37 ( V_2 , 0 ) ;
}
int F_40 ( struct V_1 * V_2 ,
struct V_27 * V_29 , struct V_38 * V_39 )
{
int V_40 = 0 , V_41 ;
unsigned long V_28 ;
F_41 ( V_42 ) ;
if ( F_42 ( V_39 ) || V_2 -> V_28 & V_43 ) {
F_43 ( V_29 , V_2 -> V_4 ,
! ( V_2 -> V_28 & V_43 ) ) ;
if ( V_2 -> V_28 & V_44 )
return - V_45 ;
else
return - V_46 ;
}
if ( V_29 -> V_28 & ( 1 << V_35 ) ) {
V_2 -> V_28 |= V_34 ;
return 0 ;
}
if ( V_39 -> V_47 & V_48 ) {
if ( V_29 -> V_49 . V_50 & V_51 )
F_38 ( V_2 ) ;
V_2 -> V_28 |= V_34 ;
return 0 ;
}
if ( F_44 ( V_29 ) )
V_40 = 1 ;
V_41 = 0 ;
F_27 ( & V_2 -> V_8 , V_28 ) ;
if ( ! F_42 ( V_39 ) )
V_2 -> V_33 -- ;
V_2 -> V_52 ++ ;
F_29 ( & V_2 -> V_8 , V_28 ) ;
while ( 1 ) {
if ( V_29 -> V_49 . V_50 & V_51 )
F_38 ( V_2 ) ;
F_45 ( & V_2 -> V_3 , & V_42 , V_53 ) ;
if ( F_42 ( V_39 ) || ! ( V_2 -> V_28 & V_54 ) ) {
if ( V_2 -> V_28 & V_44 )
V_41 = - V_45 ;
else
V_41 = - V_46 ;
break;
}
if ( ! ( V_2 -> V_28 & V_43 ) &&
( V_40 || F_37 ( V_2 ) ) )
break;
if ( F_46 ( V_55 ) ) {
V_41 = - V_46 ;
break;
}
F_47 ( V_29 ) ;
F_48 () ;
F_49 ( V_29 ) ;
}
F_50 ( & V_2 -> V_3 , & V_42 ) ;
F_27 ( & V_2 -> V_8 , V_28 ) ;
if ( ! F_42 ( V_39 ) )
V_2 -> V_33 ++ ;
V_2 -> V_52 -- ;
if ( V_41 == 0 )
V_2 -> V_28 |= V_34 ;
F_29 ( & V_2 -> V_8 , V_28 ) ;
return V_41 ;
}
int F_51 ( struct V_1 * V_2 ,
struct V_27 * V_29 , struct V_38 * V_39 )
{
unsigned long V_28 ;
F_27 ( & V_2 -> V_8 , V_28 ) ;
if ( F_42 ( V_39 ) ) {
F_29 ( & V_2 -> V_8 , V_28 ) ;
return 0 ;
}
if ( V_29 -> V_33 == 1 && V_2 -> V_33 != 1 ) {
F_52 ( V_56
L_1 ,
V_2 -> V_33 ) ;
V_2 -> V_33 = 1 ;
}
if ( -- V_2 -> V_33 < 0 ) {
F_52 ( V_56 L_2 ,
V_2 -> V_33 ) ;
V_2 -> V_33 = 0 ;
}
if ( V_2 -> V_33 ) {
F_29 ( & V_2 -> V_8 , V_28 ) ;
if ( V_2 -> V_25 -> V_57 )
V_2 -> V_25 -> V_57 ( V_2 ) ;
return 0 ;
}
F_35 ( V_58 , & V_2 -> V_28 ) ;
V_29 -> V_59 = 1 ;
F_29 ( & V_2 -> V_8 , V_28 ) ;
if ( V_29 -> V_60 )
F_53 ( V_29 ) ;
if ( F_54 ( V_32 , & V_2 -> V_28 ) &&
V_2 -> V_11 != V_61 )
F_55 ( V_29 , V_2 -> V_11 ) ;
if ( V_2 -> V_62 ) {
unsigned int V_63 = F_56 ( V_29 ) ;
long V_64 ;
if ( V_63 > 1200 )
V_64 = F_57 ( long ,
( V_10 * 10 * V_2 -> V_62 ) / V_63 , V_10 / 10 ) ;
else
V_64 = 2 * V_10 ;
F_58 ( V_64 ) ;
}
F_59 ( V_29 ) ;
if ( V_29 -> V_49 . V_50 & V_65 )
F_39 ( V_2 ) ;
return 1 ;
}
void F_60 ( struct V_1 * V_2 , struct V_27 * V_29 )
{
unsigned long V_28 ;
F_27 ( & V_2 -> V_8 , V_28 ) ;
V_29 -> V_59 = 0 ;
if ( V_2 -> V_52 ) {
F_29 ( & V_2 -> V_8 , V_28 ) ;
if ( V_2 -> V_9 ) {
F_61 (
F_62 ( V_2 -> V_9 ) ) ;
}
F_27 ( & V_2 -> V_8 , V_28 ) ;
F_36 ( & V_2 -> V_3 ) ;
}
V_2 -> V_28 &= ~ ( V_34 | V_43 ) ;
F_36 ( & V_2 -> V_4 ) ;
F_29 ( & V_2 -> V_8 , V_28 ) ;
}
void F_63 ( struct V_1 * V_2 , struct V_27 * V_29 ,
struct V_38 * V_39 )
{
if ( F_51 ( V_2 , V_29 , V_39 ) == 0 )
return;
F_32 ( V_2 ) ;
F_35 ( V_35 , & V_29 -> V_28 ) ;
F_60 ( V_2 , V_29 ) ;
F_30 ( V_2 , NULL ) ;
}
int F_64 ( struct V_1 * V_2 , struct V_13 * V_14 ,
struct V_27 * V_29 )
{
V_29 -> V_2 = V_2 ;
return F_65 ( V_14 , V_29 ) ;
}
int F_66 ( struct V_1 * V_2 , struct V_27 * V_29 ,
struct V_38 * V_39 )
{
F_67 ( & V_2 -> V_8 ) ;
if ( ! F_42 ( V_39 ) )
++ V_2 -> V_33 ;
F_68 ( & V_2 -> V_8 ) ;
F_30 ( V_2 , V_29 ) ;
F_14 ( & V_2 -> V_6 ) ;
if ( ! F_54 ( V_32 , & V_2 -> V_28 ) ) {
F_69 ( V_35 , & V_29 -> V_28 ) ;
if ( V_2 -> V_25 -> V_66 ) {
int V_41 = V_2 -> V_25 -> V_66 ( V_2 , V_29 ) ;
if ( V_41 ) {
F_16 ( & V_2 -> V_6 ) ;
return V_41 ;
}
}
F_35 ( V_32 , & V_2 -> V_28 ) ;
}
F_16 ( & V_2 -> V_6 ) ;
return F_40 ( V_2 , V_29 , V_39 ) ;
}
