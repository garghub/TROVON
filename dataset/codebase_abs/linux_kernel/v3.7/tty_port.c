void F_1 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_2 ( & V_2 -> V_3 ) ;
F_2 ( & V_2 -> V_4 ) ;
F_2 ( & V_2 -> V_5 ) ;
F_3 ( & V_2 -> V_6 ) ;
F_3 ( & V_2 -> V_7 ) ;
F_4 ( & V_2 -> V_8 ) ;
V_2 -> V_9 = ( 50 * V_10 ) / 100 ;
V_2 -> V_11 = ( 3000 * V_10 ) / 100 ;
F_5 ( & V_2 -> V_12 ) ;
}
void F_6 ( struct V_1 * V_2 ,
struct V_13 * V_14 , unsigned V_15 )
{
if ( F_7 ( V_15 >= V_14 -> V_16 ) )
return;
V_14 -> V_17 [ V_15 ] = V_2 ;
}
struct V_18 * F_8 ( struct V_1 * V_2 ,
struct V_13 * V_14 , unsigned V_15 ,
struct V_18 * V_18 )
{
F_6 ( V_2 , V_14 , V_15 ) ;
return F_9 ( V_14 , V_15 , V_18 ) ;
}
struct V_18 * F_10 ( struct V_1 * V_2 ,
struct V_13 * V_14 , unsigned V_15 ,
struct V_18 * V_18 , void * V_19 ,
const struct V_20 * * V_21 )
{
F_6 ( V_2 , V_14 , V_15 ) ;
return F_11 ( V_14 , V_15 , V_18 , V_19 ,
V_21 ) ;
}
int F_12 ( struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_22 == NULL )
V_2 -> V_22 = ( unsigned char * ) F_14 ( V_23 ) ;
F_15 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_22 == NULL )
return - V_24 ;
return 0 ;
}
void F_16 ( struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_22 != NULL ) {
F_17 ( ( unsigned long ) V_2 -> V_22 ) ;
V_2 -> V_22 = NULL ;
}
F_15 ( & V_2 -> V_7 ) ;
}
static void F_18 ( struct V_12 * V_12 )
{
struct V_1 * V_2 = F_19 ( V_12 , struct V_1 , V_12 ) ;
if ( V_2 -> V_22 )
F_17 ( ( unsigned long ) V_2 -> V_22 ) ;
if ( V_2 -> V_25 -> V_26 )
V_2 -> V_25 -> V_26 ( V_2 ) ;
else
F_20 ( V_2 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
if ( V_2 )
F_22 ( & V_2 -> V_12 , F_18 ) ;
}
struct V_27 * F_23 ( struct V_1 * V_2 )
{
unsigned long V_28 ;
struct V_27 * V_29 ;
F_24 ( & V_2 -> V_8 , V_28 ) ;
V_29 = F_25 ( V_2 -> V_29 ) ;
F_26 ( & V_2 -> V_8 , V_28 ) ;
return V_29 ;
}
void F_27 ( struct V_1 * V_2 , struct V_27 * V_29 )
{
unsigned long V_28 ;
F_24 ( & V_2 -> V_8 , V_28 ) ;
if ( V_2 -> V_29 )
F_28 ( V_2 -> V_29 ) ;
V_2 -> V_29 = F_25 ( V_29 ) ;
F_26 ( & V_2 -> V_8 , V_28 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_25 -> V_30 && ! V_2 -> V_31 &&
F_30 ( V_32 , & V_2 -> V_28 ) )
V_2 -> V_25 -> V_30 ( V_2 ) ;
F_15 ( & V_2 -> V_6 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
unsigned long V_28 ;
F_24 ( & V_2 -> V_8 , V_28 ) ;
V_2 -> V_33 = 0 ;
V_2 -> V_28 &= ~ V_34 ;
if ( V_2 -> V_29 ) {
F_32 ( V_35 , & V_2 -> V_29 -> V_28 ) ;
F_28 ( V_2 -> V_29 ) ;
}
V_2 -> V_29 = NULL ;
F_26 ( & V_2 -> V_8 , V_28 ) ;
F_33 ( & V_2 -> V_3 ) ;
F_33 ( & V_2 -> V_5 ) ;
F_29 ( V_2 ) ;
}
int F_34 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 -> V_36 == NULL )
return 1 ;
return V_2 -> V_25 -> V_36 ( V_2 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 -> V_37 )
V_2 -> V_25 -> V_37 ( V_2 , 1 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 -> V_37 )
V_2 -> V_25 -> V_37 ( V_2 , 0 ) ;
}
int F_37 ( struct V_1 * V_2 ,
struct V_27 * V_29 , struct V_38 * V_39 )
{
int V_40 = 0 , V_41 ;
unsigned long V_28 ;
F_38 ( V_42 ) ;
if ( F_39 ( V_39 ) || V_2 -> V_28 & V_43 ) {
F_40 ( V_29 , V_2 -> V_4 ,
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
F_35 ( V_2 ) ;
V_2 -> V_28 |= V_34 ;
return 0 ;
}
if ( F_41 ( V_29 ) )
V_40 = 1 ;
V_41 = 0 ;
F_24 ( & V_2 -> V_8 , V_28 ) ;
if ( ! F_39 ( V_39 ) )
V_2 -> V_33 -- ;
V_2 -> V_52 ++ ;
F_26 ( & V_2 -> V_8 , V_28 ) ;
while ( 1 ) {
if ( V_29 -> V_49 . V_50 & V_51 )
F_35 ( V_2 ) ;
F_42 ( & V_2 -> V_3 , & V_42 , V_53 ) ;
if ( F_39 ( V_39 ) || ! ( V_2 -> V_28 & V_54 ) ) {
if ( V_2 -> V_28 & V_44 )
V_41 = - V_45 ;
else
V_41 = - V_46 ;
break;
}
if ( ! ( V_2 -> V_28 & V_43 ) &&
( V_40 || F_34 ( V_2 ) ) )
break;
if ( F_43 ( V_55 ) ) {
V_41 = - V_46 ;
break;
}
F_44 ( V_29 ) ;
F_45 () ;
F_46 ( V_29 ) ;
}
F_47 ( & V_2 -> V_3 , & V_42 ) ;
F_24 ( & V_2 -> V_8 , V_28 ) ;
if ( ! F_39 ( V_39 ) )
V_2 -> V_33 ++ ;
V_2 -> V_52 -- ;
if ( V_41 == 0 )
V_2 -> V_28 |= V_34 ;
F_26 ( & V_2 -> V_8 , V_28 ) ;
return V_41 ;
}
int F_48 ( struct V_1 * V_2 ,
struct V_27 * V_29 , struct V_38 * V_39 )
{
unsigned long V_28 ;
F_24 ( & V_2 -> V_8 , V_28 ) ;
if ( F_39 ( V_39 ) ) {
F_26 ( & V_2 -> V_8 , V_28 ) ;
return 0 ;
}
if ( V_29 -> V_33 == 1 && V_2 -> V_33 != 1 ) {
F_49 ( V_56
L_1 ,
V_2 -> V_33 ) ;
V_2 -> V_33 = 1 ;
}
if ( -- V_2 -> V_33 < 0 ) {
F_49 ( V_56 L_2 ,
V_2 -> V_33 ) ;
V_2 -> V_33 = 0 ;
}
if ( V_2 -> V_33 ) {
F_26 ( & V_2 -> V_8 , V_28 ) ;
if ( V_2 -> V_25 -> V_57 )
V_2 -> V_25 -> V_57 ( V_2 ) ;
return 0 ;
}
F_32 ( V_58 , & V_2 -> V_28 ) ;
V_29 -> V_59 = 1 ;
F_26 ( & V_2 -> V_8 , V_28 ) ;
if ( V_29 -> V_60 )
F_50 ( V_29 ) ;
if ( F_51 ( V_32 , & V_2 -> V_28 ) &&
V_2 -> V_11 != V_61 )
F_52 ( V_29 , V_2 -> V_11 ) ;
if ( V_2 -> V_62 ) {
unsigned int V_63 = F_53 ( V_29 ) ;
long V_64 ;
if ( V_63 > 1200 )
V_64 = F_54 ( long ,
( V_10 * 10 * V_2 -> V_62 ) / V_63 , V_10 / 10 ) ;
else
V_64 = 2 * V_10 ;
F_55 ( V_64 ) ;
}
F_56 ( V_29 ) ;
if ( V_29 -> V_49 . V_50 & V_65 )
F_36 ( V_2 ) ;
return 1 ;
}
void F_57 ( struct V_1 * V_2 , struct V_27 * V_29 )
{
unsigned long V_28 ;
F_24 ( & V_2 -> V_8 , V_28 ) ;
V_29 -> V_59 = 0 ;
if ( V_2 -> V_52 ) {
F_26 ( & V_2 -> V_8 , V_28 ) ;
if ( V_2 -> V_9 ) {
F_58 (
F_59 ( V_2 -> V_9 ) ) ;
}
F_24 ( & V_2 -> V_8 , V_28 ) ;
F_33 ( & V_2 -> V_3 ) ;
}
V_2 -> V_28 &= ~ ( V_34 | V_43 ) ;
F_33 ( & V_2 -> V_4 ) ;
F_26 ( & V_2 -> V_8 , V_28 ) ;
}
void F_60 ( struct V_1 * V_2 , struct V_27 * V_29 ,
struct V_38 * V_39 )
{
if ( F_48 ( V_2 , V_29 , V_39 ) == 0 )
return;
F_29 ( V_2 ) ;
F_32 ( V_35 , & V_29 -> V_28 ) ;
F_57 ( V_2 , V_29 ) ;
F_27 ( V_2 , NULL ) ;
}
int F_61 ( struct V_1 * V_2 , struct V_13 * V_14 ,
struct V_27 * V_29 )
{
V_29 -> V_2 = V_2 ;
return F_62 ( V_14 , V_29 ) ;
}
int F_63 ( struct V_1 * V_2 , struct V_27 * V_29 ,
struct V_38 * V_39 )
{
F_64 ( & V_2 -> V_8 ) ;
if ( ! F_39 ( V_39 ) )
++ V_2 -> V_33 ;
F_65 ( & V_2 -> V_8 ) ;
F_27 ( V_2 , V_29 ) ;
F_13 ( & V_2 -> V_6 ) ;
if ( ! F_51 ( V_32 , & V_2 -> V_28 ) ) {
F_66 ( V_35 , & V_29 -> V_28 ) ;
if ( V_2 -> V_25 -> V_66 ) {
int V_41 = V_2 -> V_25 -> V_66 ( V_2 , V_29 ) ;
if ( V_41 ) {
F_15 ( & V_2 -> V_6 ) ;
return V_41 ;
}
}
F_32 ( V_32 , & V_2 -> V_28 ) ;
}
F_15 ( & V_2 -> V_6 ) ;
return F_37 ( V_2 , V_29 , V_39 ) ;
}
