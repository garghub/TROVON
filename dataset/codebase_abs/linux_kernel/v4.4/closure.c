static inline void F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = V_3 & V_5 ;
F_2 ( V_3 & V_6 ) ;
F_2 ( ! V_4 && ( V_3 & ~ V_7 ) ) ;
if ( V_4 == 1 && ( V_3 & V_8 ) )
F_3 ( V_2 -> V_9 ) ;
if ( ! V_4 ) {
if ( V_2 -> V_10 && ! ( V_3 & V_7 ) ) {
F_4 ( & V_2 -> V_11 ,
V_12 ) ;
F_5 ( V_2 ) ;
} else {
struct V_1 * V_13 = V_2 -> V_13 ;
T_1 * V_14 = V_2 -> V_10 ;
F_6 ( V_2 ) ;
if ( V_14 )
V_14 ( V_2 ) ;
if ( V_13 )
F_7 ( V_13 ) ;
}
}
}
void F_8 ( struct V_1 * V_2 , int V_15 )
{
F_1 ( V_2 , F_9 ( V_15 , & V_2 -> V_11 ) ) ;
}
void F_7 ( struct V_1 * V_2 )
{
F_1 ( V_2 , F_10 ( & V_2 -> V_11 ) ) ;
}
void F_11 ( struct V_16 * V_17 )
{
struct V_18 * V_19 ;
struct V_1 * V_2 ;
struct V_18 * V_20 = NULL ;
V_19 = F_12 ( & V_17 -> V_19 ) ;
while ( V_19 ) {
struct V_18 * V_21 = V_19 ;
V_19 = F_13 ( V_19 ) ;
V_21 -> V_22 = V_20 ;
V_20 = V_21 ;
}
while ( V_20 ) {
V_2 = F_14 ( V_20 , struct V_1 , V_19 ) ;
V_20 = F_13 ( V_20 ) ;
F_15 ( V_2 , 0 ) ;
F_8 ( V_2 , V_23 + 1 ) ;
}
}
bool F_16 ( struct V_16 * V_24 , struct V_1 * V_2 )
{
if ( F_17 ( & V_2 -> V_11 ) & V_23 )
return false ;
F_15 ( V_2 , V_25 ) ;
F_18 ( V_23 + 1 , & V_2 -> V_11 ) ;
F_19 ( & V_2 -> V_19 , & V_24 -> V_19 ) ;
return true ;
}
void F_20 ( struct V_1 * V_2 )
{
while ( 1 ) {
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
if ( ( F_17 ( & V_2 -> V_11 ) &
V_5 ) == 1 )
break;
F_23 () ;
}
F_24 ( V_2 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( V_2 -> V_26 == V_27 ) ;
V_2 -> V_26 = V_27 ;
F_26 ( & V_28 , V_3 ) ;
F_27 ( & V_2 -> V_29 , & V_30 ) ;
F_28 ( & V_28 , V_3 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( V_2 -> V_26 != V_27 ) ;
V_2 -> V_26 = V_31 ;
F_26 ( & V_28 , V_3 ) ;
F_29 ( & V_2 -> V_29 ) ;
F_28 ( & V_28 , V_3 ) ;
}
static int F_30 ( struct V_32 * V_33 , void * V_34 )
{
struct V_1 * V_2 ;
F_31 ( & V_28 ) ;
F_32 (cl, &closure_list, all) {
int V_4 = F_17 ( & V_2 -> V_11 ) ;
F_33 ( V_33 , L_1 ,
V_2 , ( void * ) V_2 -> V_35 , V_2 -> V_10 , V_2 -> V_13 ,
V_4 & V_5 ) ;
F_33 ( V_33 , L_2 ,
F_34 ( V_36 ,
F_35 ( & V_2 -> V_37 ) ) ? L_3 : L_4 ,
V_4 & V_38 ? L_5 : L_4 ,
V_4 & V_39 ? L_6 : L_4 ,
V_4 & V_8 ? L_7 : L_4 ) ;
if ( V_4 & V_23 )
F_33 ( V_33 , L_8 ,
( void * ) V_2 -> V_40 ) ;
F_33 ( V_33 , L_9 ) ;
}
F_36 ( & V_28 ) ;
return 0 ;
}
static int F_37 ( struct V_41 * V_41 , struct V_42 * V_42 )
{
return F_38 ( V_42 , F_30 , NULL ) ;
}
void T_2 F_39 ( void )
{
V_43 = F_40 ( L_10 , 0400 , NULL , NULL , & V_44 ) ;
}
