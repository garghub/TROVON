static int T_1 F_1 ( char * V_1 )
{
int V_2 = F_2 ( V_1 , 0 , & V_3 ) ;
if ( V_2 )
return V_2 ;
return 1 ;
}
static int
F_3 ( struct V_4 * V_5 , unsigned long V_6 , void * V_7 )
{
V_8 = 1 ;
return V_9 ;
}
static void F_4 ( struct V_10 * V_11 , unsigned long V_12 )
{
unsigned long V_13 = V_11 -> V_14 + V_11 -> V_15 ;
if ( F_5 ( V_11 -> V_16 & ( V_17 | V_18 ) ) )
return;
if ( F_5 ( ! V_13 ) )
return;
if ( V_13 != V_11 -> V_19 ) {
V_11 -> V_19 = V_13 ;
return;
}
F_6 ( V_11 ) ;
if ( ! V_20 && ! V_3 )
return;
if ( V_20 ) {
if ( V_20 > 0 )
V_20 -- ;
F_7 ( L_1 ,
V_11 -> V_21 , V_11 -> V_22 , V_12 ) ;
F_7 ( L_2 ,
F_8 () , F_9 () -> V_23 ,
( int ) strcspn ( F_9 () -> V_24 , L_3 ) ,
F_9 () -> V_24 ) ;
F_7 ( L_4
L_5 ) ;
F_10 ( V_11 ) ;
V_25 = true ;
}
F_11 () ;
if ( V_3 ) {
if ( V_25 )
F_12 () ;
F_13 () ;
F_14 ( L_6 ) ;
}
}
static bool F_15 ( struct V_10 * V_26 , struct V_10 * V_11 )
{
bool V_27 ;
F_16 ( V_26 ) ;
F_16 ( V_11 ) ;
F_17 () ;
F_18 () ;
F_19 () ;
V_27 = F_20 ( V_26 ) && F_20 ( V_11 ) ;
F_21 ( V_11 ) ;
F_21 ( V_26 ) ;
return V_27 ;
}
static void F_22 ( unsigned long V_12 )
{
int V_28 = V_29 ;
int V_30 = V_31 ;
struct V_10 * V_26 , * V_11 ;
if ( F_23 ( V_32 ) || V_8 )
return;
V_25 = false ;
F_19 () ;
F_24 (g, t) {
if ( ! V_28 -- )
goto V_33;
if ( ! -- V_30 ) {
V_30 = V_31 ;
if ( ! F_15 ( V_26 , V_11 ) )
goto V_33;
}
if ( V_11 -> V_34 == V_35 )
F_4 ( V_11 , V_12 ) ;
}
V_33:
F_17 () ;
if ( V_25 )
F_12 () ;
}
static long F_25 ( unsigned long V_36 ,
unsigned long V_12 )
{
return V_12 ? V_36 - V_37 + V_12 * V_38 :
V_39 ;
}
int F_26 ( struct V_40 * V_41 , int V_42 ,
void T_2 * V_43 ,
T_3 * V_44 , T_4 * V_45 )
{
int V_46 ;
V_46 = F_27 ( V_41 , V_42 , V_43 , V_44 , V_45 ) ;
if ( V_46 || ! V_42 )
goto V_47;
F_28 ( V_48 ) ;
V_47:
return V_46 ;
}
void F_29 ( void )
{
F_30 ( & V_49 , 1 ) ;
}
static int F_31 ( void * V_50 )
{
unsigned long V_51 = V_37 ;
F_32 ( V_52 , 0 ) ;
for ( ; ; ) {
unsigned long V_12 = V_53 ;
long V_11 = F_25 ( V_51 , V_12 ) ;
if ( V_11 <= 0 ) {
if ( ! F_33 ( & V_49 , 0 ) )
F_22 ( V_12 ) ;
V_51 = V_37 ;
continue;
}
F_34 ( V_11 ) ;
}
return 0 ;
}
static int T_1 F_35 ( void )
{
F_36 ( & V_54 , & V_55 ) ;
V_48 = F_37 ( F_31 , NULL , L_7 ) ;
return 0 ;
}
