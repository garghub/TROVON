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
if ( ! V_20 )
return;
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
F_11 ( V_11 ) ;
F_12 () ;
if ( V_3 ) {
F_13 () ;
F_14 ( L_6 ) ;
}
}
static bool F_15 ( struct V_10 * V_25 , struct V_10 * V_11 )
{
bool V_26 ;
F_16 ( V_25 ) ;
F_16 ( V_11 ) ;
F_17 () ;
F_18 () ;
F_19 () ;
V_26 = F_20 ( V_25 ) && F_20 ( V_11 ) ;
F_21 ( V_11 ) ;
F_21 ( V_25 ) ;
return V_26 ;
}
static void F_22 ( unsigned long V_12 )
{
int V_27 = V_28 ;
int V_29 = V_30 ;
struct V_10 * V_25 , * V_11 ;
if ( F_23 ( V_31 ) || V_8 )
return;
F_19 () ;
F_24 (g, t) {
if ( ! V_27 -- )
goto V_32;
if ( ! -- V_29 ) {
V_29 = V_30 ;
if ( ! F_15 ( V_25 , V_11 ) )
goto V_32;
}
if ( V_11 -> V_33 == V_34 )
F_4 ( V_11 , V_12 ) ;
}
V_32:
F_17 () ;
}
static unsigned long F_25 ( unsigned long V_12 )
{
return V_12 ? V_12 * V_35 : V_36 ;
}
int F_26 ( struct V_37 * V_38 , int V_39 ,
void T_2 * V_40 ,
T_3 * V_41 , T_4 * V_42 )
{
int V_43 ;
V_43 = F_27 ( V_38 , V_39 , V_40 , V_41 , V_42 ) ;
if ( V_43 || ! V_39 )
goto V_44;
F_28 ( V_45 ) ;
V_44:
return V_43 ;
}
void F_29 ( void )
{
F_30 ( & V_46 , 1 ) ;
}
static int F_31 ( void * V_47 )
{
F_32 ( V_48 , 0 ) ;
for ( ; ; ) {
unsigned long V_12 = V_49 ;
while ( F_33 ( F_25 ( V_12 ) ) )
V_12 = V_49 ;
if ( F_34 ( & V_46 , 0 ) )
continue;
F_22 ( V_12 ) ;
}
return 0 ;
}
static int T_1 F_35 ( void )
{
F_36 ( & V_50 , & V_51 ) ;
V_45 = F_37 ( F_31 , NULL , L_7 ) ;
return 0 ;
}
