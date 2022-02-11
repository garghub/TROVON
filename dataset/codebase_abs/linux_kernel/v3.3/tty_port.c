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
int F_6 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_13 == NULL )
V_2 -> V_13 = ( unsigned char * ) F_8 ( V_14 ) ;
F_9 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_13 == NULL )
return - V_15 ;
return 0 ;
}
void F_10 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_13 != NULL ) {
F_11 ( ( unsigned long ) V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
}
F_9 ( & V_2 -> V_7 ) ;
}
static void F_12 ( struct V_12 * V_12 )
{
struct V_1 * V_2 = F_13 ( V_12 , struct V_1 , V_12 ) ;
if ( V_2 -> V_13 )
F_11 ( ( unsigned long ) V_2 -> V_13 ) ;
if ( V_2 -> V_16 -> V_17 )
V_2 -> V_16 -> V_17 ( V_2 ) ;
else
F_14 ( V_2 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
if ( V_2 )
F_16 ( & V_2 -> V_12 , F_12 ) ;
}
struct V_18 * F_17 ( struct V_1 * V_2 )
{
unsigned long V_19 ;
struct V_18 * V_20 ;
F_18 ( & V_2 -> V_8 , V_19 ) ;
V_20 = F_19 ( V_2 -> V_20 ) ;
F_20 ( & V_2 -> V_8 , V_19 ) ;
return V_20 ;
}
void F_21 ( struct V_1 * V_2 , struct V_18 * V_20 )
{
unsigned long V_19 ;
F_18 ( & V_2 -> V_8 , V_19 ) ;
if ( V_2 -> V_20 )
F_22 ( V_2 -> V_20 ) ;
V_2 -> V_20 = F_19 ( V_20 ) ;
F_20 ( & V_2 -> V_8 , V_19 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_16 -> V_21 && ! V_2 -> V_22 &&
F_24 ( V_23 , & V_2 -> V_19 ) )
V_2 -> V_16 -> V_21 ( V_2 ) ;
F_9 ( & V_2 -> V_6 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
unsigned long V_19 ;
F_18 ( & V_2 -> V_8 , V_19 ) ;
V_2 -> V_24 = 0 ;
V_2 -> V_19 &= ~ V_25 ;
if ( V_2 -> V_20 ) {
F_26 ( V_26 , & V_2 -> V_20 -> V_19 ) ;
F_22 ( V_2 -> V_20 ) ;
}
V_2 -> V_20 = NULL ;
F_20 ( & V_2 -> V_8 , V_19 ) ;
F_27 ( & V_2 -> V_3 ) ;
F_27 ( & V_2 -> V_5 ) ;
F_23 ( V_2 ) ;
}
int F_28 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 -> V_27 == NULL )
return 1 ;
return V_2 -> V_16 -> V_27 ( V_2 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 -> V_28 )
V_2 -> V_16 -> V_28 ( V_2 , 1 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 -> V_28 )
V_2 -> V_16 -> V_28 ( V_2 , 0 ) ;
}
int F_31 ( struct V_1 * V_2 ,
struct V_18 * V_20 , struct V_29 * V_30 )
{
int V_31 = 0 , V_32 ;
unsigned long V_19 ;
F_32 ( V_33 ) ;
if ( F_33 ( V_30 ) || V_2 -> V_19 & V_34 ) {
F_34 ( V_2 -> V_4 ,
! ( V_2 -> V_19 & V_34 ) ) ;
if ( V_2 -> V_19 & V_35 )
return - V_36 ;
else
return - V_37 ;
}
if ( V_20 -> V_19 & ( 1 << V_26 ) ) {
V_2 -> V_19 |= V_25 ;
return 0 ;
}
if ( V_30 -> V_38 & V_39 ) {
if ( V_20 -> V_40 -> V_41 & V_42 )
F_29 ( V_2 ) ;
V_2 -> V_19 |= V_25 ;
return 0 ;
}
if ( F_35 ( V_20 ) )
V_31 = 1 ;
V_32 = 0 ;
F_18 ( & V_2 -> V_8 , V_19 ) ;
if ( ! F_33 ( V_30 ) )
V_2 -> V_24 -- ;
V_2 -> V_43 ++ ;
F_20 ( & V_2 -> V_8 , V_19 ) ;
while ( 1 ) {
if ( V_20 -> V_40 -> V_41 & V_42 )
F_29 ( V_2 ) ;
F_36 ( & V_2 -> V_3 , & V_33 , V_44 ) ;
if ( F_33 ( V_30 ) || ! ( V_2 -> V_19 & V_45 ) ) {
if ( V_2 -> V_19 & V_35 )
V_32 = - V_36 ;
else
V_32 = - V_37 ;
break;
}
if ( ! ( V_2 -> V_19 & V_34 ) &&
( V_31 || F_28 ( V_2 ) ) )
break;
if ( F_37 ( V_46 ) ) {
V_32 = - V_37 ;
break;
}
F_38 () ;
F_39 () ;
F_40 () ;
}
F_41 ( & V_2 -> V_3 , & V_33 ) ;
F_18 ( & V_2 -> V_8 , V_19 ) ;
if ( ! F_33 ( V_30 ) )
V_2 -> V_24 ++ ;
V_2 -> V_43 -- ;
if ( V_32 == 0 )
V_2 -> V_19 |= V_25 ;
F_20 ( & V_2 -> V_8 , V_19 ) ;
return V_32 ;
}
int F_42 ( struct V_1 * V_2 ,
struct V_18 * V_20 , struct V_29 * V_30 )
{
unsigned long V_19 ;
F_18 ( & V_2 -> V_8 , V_19 ) ;
if ( F_33 ( V_30 ) ) {
F_20 ( & V_2 -> V_8 , V_19 ) ;
return 0 ;
}
if ( V_20 -> V_24 == 1 && V_2 -> V_24 != 1 ) {
F_43 ( V_47
L_1 ,
V_2 -> V_24 ) ;
V_2 -> V_24 = 1 ;
}
if ( -- V_2 -> V_24 < 0 ) {
F_43 ( V_47 L_2 ,
V_2 -> V_24 ) ;
V_2 -> V_24 = 0 ;
}
if ( V_2 -> V_24 ) {
F_20 ( & V_2 -> V_8 , V_19 ) ;
if ( V_2 -> V_16 -> V_48 )
V_2 -> V_16 -> V_48 ( V_2 ) ;
return 0 ;
}
F_26 ( V_49 , & V_2 -> V_19 ) ;
V_20 -> V_50 = 1 ;
F_20 ( & V_2 -> V_8 , V_19 ) ;
if ( V_20 -> V_51 )
F_44 ( V_20 ) ;
if ( F_45 ( V_23 , & V_2 -> V_19 ) &&
V_2 -> V_11 != V_52 )
F_46 ( V_20 , V_2 -> V_11 ) ;
if ( V_2 -> V_53 ) {
unsigned int V_54 = F_47 ( V_20 ) ;
long V_55 ;
if ( V_54 > 1200 )
V_55 = F_48 ( long ,
( V_10 * 10 * V_2 -> V_53 ) / V_54 , V_10 / 10 ) ;
else
V_55 = 2 * V_10 ;
F_49 ( V_55 ) ;
}
F_50 ( V_20 ) ;
if ( V_20 -> V_40 -> V_41 & V_56 )
F_30 ( V_2 ) ;
return 1 ;
}
void F_51 ( struct V_1 * V_2 , struct V_18 * V_20 )
{
unsigned long V_19 ;
F_18 ( & V_2 -> V_8 , V_19 ) ;
V_20 -> V_50 = 0 ;
if ( V_2 -> V_43 ) {
F_20 ( & V_2 -> V_8 , V_19 ) ;
if ( V_2 -> V_9 ) {
F_52 (
F_53 ( V_2 -> V_9 ) ) ;
}
F_18 ( & V_2 -> V_8 , V_19 ) ;
F_27 ( & V_2 -> V_3 ) ;
}
V_2 -> V_19 &= ~ ( V_25 | V_34 ) ;
F_27 ( & V_2 -> V_4 ) ;
F_20 ( & V_2 -> V_8 , V_19 ) ;
}
void F_54 ( struct V_1 * V_2 , struct V_18 * V_20 ,
struct V_29 * V_30 )
{
if ( F_42 ( V_2 , V_20 , V_30 ) == 0 )
return;
F_23 ( V_2 ) ;
F_26 ( V_26 , & V_20 -> V_19 ) ;
F_51 ( V_2 , V_20 ) ;
F_21 ( V_2 , NULL ) ;
}
int F_55 ( struct V_1 * V_2 , struct V_18 * V_20 ,
struct V_29 * V_30 )
{
F_56 ( & V_2 -> V_8 ) ;
if ( ! F_33 ( V_30 ) )
++ V_2 -> V_24 ;
F_57 ( & V_2 -> V_8 ) ;
F_21 ( V_2 , V_20 ) ;
F_7 ( & V_2 -> V_6 ) ;
if ( ! F_45 ( V_23 , & V_2 -> V_19 ) ) {
F_58 ( V_26 , & V_20 -> V_19 ) ;
if ( V_2 -> V_16 -> V_57 ) {
int V_32 = V_2 -> V_16 -> V_57 ( V_2 , V_20 ) ;
if ( V_32 ) {
F_9 ( & V_2 -> V_6 ) ;
return V_32 ;
}
}
F_26 ( V_23 , & V_2 -> V_19 ) ;
}
F_9 ( & V_2 -> V_6 ) ;
return F_31 ( V_2 , V_20 , V_30 ) ;
}
