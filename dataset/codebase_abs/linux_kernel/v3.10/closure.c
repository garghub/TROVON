void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 ) {
F_2 ( & V_2 -> V_5 , V_2 -> V_5 . V_6 ) ;
F_3 ( ! F_4 ( V_4 , & V_2 -> V_5 ) ) ;
} else
V_2 -> V_7 ( V_2 ) ;
}
static struct V_8 * V_8 ( struct V_1 * V_2 )
{
switch ( V_2 -> type ) {
F_5 ( V_9 , V_10 ) ;
F_5 ( V_11 , V_10 ) ;
default:
return NULL ;
}
}
static struct V_12 * F_6 ( struct V_1 * V_2 )
{
switch ( V_2 -> type ) {
F_5 ( V_13 , V_14 ) ;
F_5 ( V_11 , V_14 ) ;
default:
return NULL ;
}
}
static inline void F_7 ( struct V_1 * V_2 , int V_15 )
{
int V_16 = V_15 & V_17 ;
F_3 ( V_15 & V_18 ) ;
F_3 ( ! V_16 && ( V_15 & ~ ( V_19 | V_20 ) ) ) ;
if ( V_16 == 1 && ( V_15 & V_21 ) )
F_8 ( V_2 -> V_22 ) ;
if ( ! V_16 ) {
if ( V_2 -> V_7 && ! ( V_15 & V_19 ) ) {
F_9 ( & V_2 -> V_23 ,
V_24 ) ;
F_1 ( V_2 ) ;
} else {
struct V_1 * V_25 = V_2 -> V_25 ;
struct V_8 * V_10 = V_8 ( V_2 ) ;
F_10 ( V_2 ) ;
F_9 ( & V_2 -> V_23 , - 1 ) ;
if ( V_10 )
F_11 ( V_10 ) ;
if ( V_2 -> V_7 )
V_2 -> V_7 ( V_2 ) ;
if ( V_25 )
F_12 ( V_25 ) ;
}
}
}
void F_13 ( struct V_1 * V_2 , int V_26 )
{
F_7 ( V_2 , F_14 ( V_26 , & V_2 -> V_23 ) ) ;
}
void F_12 ( struct V_1 * V_2 )
{
F_7 ( V_2 , F_15 ( & V_2 -> V_23 ) ) ;
}
static void F_16 ( struct V_1 * V_2 , unsigned long V_27 )
{
#ifdef F_17
V_2 -> V_28 = V_27 ;
#endif
}
void F_18 ( struct V_8 * V_29 )
{
struct V_30 * V_31 ;
struct V_1 * V_2 ;
struct V_30 * V_32 = NULL ;
V_31 = F_19 ( & V_29 -> V_31 ) ;
while ( V_31 ) {
struct V_30 * V_33 = V_31 ;
V_31 = F_20 ( V_31 ) ;
V_33 -> V_34 = V_32 ;
V_32 = V_33 ;
}
while ( V_32 ) {
V_2 = F_21 ( V_32 , struct V_1 , V_31 ) ;
V_32 = F_20 ( V_32 ) ;
F_16 ( V_2 , 0 ) ;
F_13 ( V_2 , V_35 + 1 ) ;
}
}
bool F_22 ( struct V_8 * V_31 , struct V_1 * V_2 )
{
if ( F_23 ( & V_2 -> V_23 ) & V_35 )
return false ;
F_16 ( V_2 , V_36 ) ;
F_24 ( V_35 + 1 , & V_2 -> V_23 ) ;
F_25 ( & V_2 -> V_31 , & V_31 -> V_31 ) ;
return true ;
}
void F_26 ( struct V_1 * V_2 )
{
while ( 1 ) {
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
if ( ( F_23 ( & V_2 -> V_23 ) &
V_17 ) == 1 )
break;
F_29 () ;
}
F_30 ( V_2 ) ;
}
bool F_31 ( struct V_1 * V_2 , struct V_1 * V_25 )
{
if ( F_32 ( & V_2 -> V_23 , - 1 ,
V_24 ) != - 1 )
return false ;
F_28 ( V_2 ) ;
F_33 () ;
V_2 -> V_25 = V_25 ;
if ( V_25 )
F_34 ( V_25 ) ;
F_35 ( V_2 ) ;
return true ;
}
void F_36 ( struct V_1 * V_2 , struct V_1 * V_25 ,
struct V_8 * V_29 )
{
struct V_1 V_10 ;
F_37 ( & V_10 ) ;
while ( 1 ) {
if ( F_31 ( V_2 , V_25 ) )
return;
F_38 ( V_29 , & V_10 ,
F_23 ( & V_2 -> V_23 ) == - 1 ) ;
}
}
static void F_39 ( unsigned long V_37 )
{
struct V_1 * V_2 = (struct V_1 * ) V_37 ;
F_13 ( V_2 , V_38 + 1 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
struct V_12 * V_14 = F_6 ( V_2 ) ;
F_41 ( V_14 ) ;
V_14 -> V_37 = ( unsigned long ) V_2 ;
V_14 -> V_39 = F_39 ;
}
bool F_42 ( struct V_1 * V_2 , unsigned long V_40 ,
struct V_12 * V_14 )
{
if ( F_23 ( & V_2 -> V_23 ) & V_38 )
return false ;
F_3 ( F_43 ( V_14 ) ) ;
V_14 -> V_41 = V_42 + V_40 ;
F_24 ( V_38 + 1 , & V_2 -> V_23 ) ;
F_44 ( V_14 ) ;
return true ;
}
void F_45 ( struct V_1 * V_2 , struct V_12 * V_14 )
{
if ( F_46 ( V_14 ) )
F_13 ( V_2 , V_38 + 1 ) ;
}
void F_47 ( struct V_1 * V_2 , struct V_12 * V_14 )
{
if ( F_48 ( V_14 ) )
F_13 ( V_2 , V_38 + 1 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
unsigned long V_15 ;
F_3 ( V_2 -> V_43 == V_44 ) ;
V_2 -> V_43 = V_44 ;
F_49 ( & V_45 , V_15 ) ;
F_50 ( & V_2 -> V_46 , & V_47 ) ;
F_51 ( & V_45 , V_15 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
unsigned long V_15 ;
F_3 ( V_2 -> V_43 != V_44 ) ;
V_2 -> V_43 = V_48 ;
F_49 ( & V_45 , V_15 ) ;
F_52 ( & V_2 -> V_46 ) ;
F_51 ( & V_45 , V_15 ) ;
}
static int F_53 ( struct V_49 * V_27 , void * V_37 )
{
struct V_1 * V_2 ;
F_54 ( & V_45 ) ;
F_55 (cl, &closure_list, all) {
int V_16 = F_23 ( & V_2 -> V_23 ) ;
F_56 ( V_27 , L_1 ,
V_2 , ( void * ) V_2 -> V_50 , V_2 -> V_7 , V_2 -> V_25 ,
V_16 & V_17 ) ;
F_56 ( V_27 , L_2 ,
F_57 ( V_51 ,
F_58 ( & V_2 -> V_5 ) ) ? L_3 : L_4 ,
V_16 & V_52 ? L_5 : L_4 ,
V_16 & V_20 ? L_6 : L_4 ,
V_16 & V_53 ? L_7 : L_4 ,
V_16 & V_21 ? L_8 : L_4 ,
V_16 & V_38 ? L_9 : L_4 ) ;
if ( V_16 & V_35 )
F_56 ( V_27 , L_10 ,
( void * ) V_2 -> V_28 ) ;
F_56 ( V_27 , L_11 ) ;
}
F_59 ( & V_45 ) ;
return 0 ;
}
static int F_60 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
return F_61 ( V_55 , F_53 , NULL ) ;
}
void T_1 F_62 ( void )
{
V_56 = F_63 ( L_12 , 0400 , NULL , NULL , & V_57 ) ;
}
