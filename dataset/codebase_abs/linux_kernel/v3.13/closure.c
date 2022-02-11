static struct V_1 * V_1 ( struct V_2 * V_3 )
{
switch ( V_3 -> type ) {
F_1 ( V_4 , V_5 ) ;
default:
return NULL ;
}
}
static inline void F_2 ( struct V_2 * V_3 , int V_6 )
{
int V_7 = V_6 & V_8 ;
F_3 ( V_6 & V_9 ) ;
F_3 ( ! V_7 && ( V_6 & ~ V_10 ) ) ;
if ( V_7 == 1 && ( V_6 & V_11 ) )
F_4 ( V_3 -> V_12 ) ;
if ( ! V_7 ) {
if ( V_3 -> V_13 && ! ( V_6 & V_10 ) ) {
F_5 ( & V_3 -> V_14 ,
V_15 ) ;
F_6 ( V_3 ) ;
} else {
struct V_2 * V_16 = V_3 -> V_16 ;
struct V_1 * V_5 = V_1 ( V_3 ) ;
T_1 * V_17 = V_3 -> V_13 ;
F_7 ( V_3 ) ;
F_8 () ;
F_5 ( & V_3 -> V_14 , - 1 ) ;
if ( V_5 )
F_9 ( V_5 ) ;
if ( V_17 )
V_17 ( V_3 ) ;
if ( V_16 )
F_10 ( V_16 ) ;
}
}
}
void F_11 ( struct V_2 * V_3 , int V_18 )
{
F_2 ( V_3 , F_12 ( V_18 , & V_3 -> V_14 ) ) ;
}
void F_10 ( struct V_2 * V_3 )
{
F_2 ( V_3 , F_13 ( & V_3 -> V_14 ) ) ;
}
static void F_14 ( struct V_2 * V_3 , unsigned long V_19 )
{
#ifdef F_15
V_3 -> V_20 = V_19 ;
#endif
}
void F_16 ( struct V_1 * V_21 )
{
struct V_22 * V_23 ;
struct V_2 * V_3 ;
struct V_22 * V_24 = NULL ;
V_23 = F_17 ( & V_21 -> V_23 ) ;
while ( V_23 ) {
struct V_22 * V_25 = V_23 ;
V_23 = F_18 ( V_23 ) ;
V_25 -> V_26 = V_24 ;
V_24 = V_25 ;
}
while ( V_24 ) {
V_3 = F_19 ( V_24 , struct V_2 , V_23 ) ;
V_24 = F_18 ( V_24 ) ;
F_14 ( V_3 , 0 ) ;
F_11 ( V_3 , V_27 + 1 ) ;
}
}
bool F_20 ( struct V_1 * V_23 , struct V_2 * V_3 )
{
if ( F_21 ( & V_3 -> V_14 ) & V_27 )
return false ;
F_14 ( V_3 , V_28 ) ;
F_22 ( V_27 + 1 , & V_3 -> V_14 ) ;
F_23 ( & V_3 -> V_23 , & V_23 -> V_23 ) ;
return true ;
}
void F_24 ( struct V_2 * V_3 )
{
while ( 1 ) {
F_25 ( V_3 ) ;
F_26 ( V_3 ) ;
if ( ( F_21 ( & V_3 -> V_14 ) &
V_8 ) == 1 )
break;
F_27 () ;
}
F_28 ( V_3 ) ;
}
bool F_29 ( struct V_2 * V_3 , struct V_2 * V_16 )
{
if ( F_30 ( & V_3 -> V_14 , - 1 ,
V_15 ) != - 1 )
return false ;
F_8 () ;
V_3 -> V_16 = V_16 ;
if ( V_16 )
F_31 ( V_16 ) ;
F_26 ( V_3 ) ;
F_32 ( V_3 ) ;
return true ;
}
void F_33 ( struct V_2 * V_3 , struct V_2 * V_16 ,
struct V_1 * V_21 )
{
struct V_2 V_5 ;
F_34 ( & V_5 ) ;
while ( 1 ) {
if ( F_29 ( V_3 , V_16 ) )
return;
F_35 ( V_21 , & V_5 ,
F_21 ( & V_3 -> V_14 ) == - 1 ) ;
}
}
void F_32 ( struct V_2 * V_3 )
{
unsigned long V_6 ;
F_3 ( V_3 -> V_29 == V_30 ) ;
V_3 -> V_29 = V_30 ;
F_36 ( & V_31 , V_6 ) ;
F_37 ( & V_3 -> V_32 , & V_33 ) ;
F_38 ( & V_31 , V_6 ) ;
}
void F_7 ( struct V_2 * V_3 )
{
unsigned long V_6 ;
F_3 ( V_3 -> V_29 != V_30 ) ;
V_3 -> V_29 = V_34 ;
F_36 ( & V_31 , V_6 ) ;
F_39 ( & V_3 -> V_32 ) ;
F_38 ( & V_31 , V_6 ) ;
}
static int F_40 ( struct V_35 * V_19 , void * V_36 )
{
struct V_2 * V_3 ;
F_41 ( & V_31 ) ;
F_42 (cl, &closure_list, all) {
int V_7 = F_21 ( & V_3 -> V_14 ) ;
F_43 ( V_19 , L_1 ,
V_3 , ( void * ) V_3 -> V_37 , V_3 -> V_13 , V_3 -> V_16 ,
V_7 & V_8 ) ;
F_43 ( V_19 , L_2 ,
F_44 ( V_38 ,
F_45 ( & V_3 -> V_39 ) ) ? L_3 : L_4 ,
V_7 & V_40 ? L_5 : L_4 ,
V_7 & V_41 ? L_6 : L_4 ,
V_7 & V_11 ? L_7 : L_4 ) ;
if ( V_7 & V_27 )
F_43 ( V_19 , L_8 ,
( void * ) V_3 -> V_20 ) ;
F_43 ( V_19 , L_9 ) ;
}
F_46 ( & V_31 ) ;
return 0 ;
}
static int F_47 ( struct V_42 * V_42 , struct V_43 * V_43 )
{
return F_48 ( V_43 , F_40 , NULL ) ;
}
void T_2 F_49 ( void )
{
V_44 = F_50 ( L_10 , 0400 , NULL , NULL , & V_45 ) ;
}
