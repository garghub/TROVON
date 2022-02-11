static int T_1 F_1 ( char * V_1 )
{
V_2 = F_2 ( V_1 , NULL , 0 ) ;
return 1 ;
}
static int
F_3 ( struct V_3 * V_4 , unsigned long V_5 , void * V_6 )
{
V_7 = 1 ;
return V_8 ;
}
static void F_4 ( struct V_9 * V_10 , unsigned long V_11 )
{
unsigned long V_12 = V_10 -> V_13 + V_10 -> V_14 ;
if ( F_5 ( V_10 -> V_15 & ( V_16 | V_17 ) ) )
return;
if ( F_5 ( ! V_12 ) )
return;
if ( V_12 != V_10 -> V_18 ) {
V_10 -> V_18 = V_12 ;
return;
}
F_6 ( V_10 ) ;
if ( ! V_19 )
return;
V_19 -- ;
F_7 ( L_1 ,
V_10 -> V_20 , V_10 -> V_21 , V_11 ) ;
F_7 ( L_2 ,
F_8 () , F_9 () -> V_22 ,
( int ) strcspn ( F_9 () -> V_23 , L_3 ) ,
F_9 () -> V_23 ) ;
F_7 ( L_4
L_5 ) ;
F_10 ( V_10 ) ;
F_11 ( V_10 ) ;
F_12 () ;
if ( V_2 ) {
F_13 () ;
F_14 ( L_6 ) ;
}
}
static bool F_15 ( struct V_9 * V_24 , struct V_9 * V_10 )
{
bool V_25 ;
F_16 ( V_24 ) ;
F_16 ( V_10 ) ;
F_17 () ;
F_18 () ;
F_19 () ;
V_25 = F_20 ( V_24 ) && F_20 ( V_10 ) ;
F_21 ( V_10 ) ;
F_21 ( V_24 ) ;
return V_25 ;
}
static void F_22 ( unsigned long V_11 )
{
int V_26 = V_27 ;
int V_28 = V_29 ;
struct V_9 * V_24 , * V_10 ;
if ( F_23 ( V_30 ) || V_7 )
return;
F_19 () ;
F_24 (g, t) {
if ( ! V_26 -- )
goto V_31;
if ( ! -- V_28 ) {
V_28 = V_29 ;
if ( ! F_15 ( V_24 , V_10 ) )
goto V_31;
}
if ( V_10 -> V_32 == V_33 )
F_4 ( V_10 , V_11 ) ;
} F_25 ( V_24 , V_10 ) ;
V_31:
F_17 () ;
}
static unsigned long F_26 ( unsigned long V_11 )
{
return V_11 ? V_11 * V_34 : V_35 ;
}
int F_27 ( struct V_36 * V_37 , int V_38 ,
void T_2 * V_39 ,
T_3 * V_40 , T_4 * V_41 )
{
int V_42 ;
V_42 = F_28 ( V_37 , V_38 , V_39 , V_40 , V_41 ) ;
if ( V_42 || ! V_38 )
goto V_43;
F_29 ( V_44 ) ;
V_43:
return V_42 ;
}
void F_30 ( void )
{
F_31 ( & V_45 , 1 ) ;
}
static int F_32 ( void * V_46 )
{
F_33 ( V_47 , 0 ) ;
for ( ; ; ) {
unsigned long V_11 = V_48 ;
while ( F_34 ( F_26 ( V_11 ) ) )
V_11 = V_48 ;
if ( F_35 ( & V_45 , 0 ) )
continue;
F_22 ( V_11 ) ;
}
return 0 ;
}
static int T_1 F_36 ( void )
{
F_37 ( & V_49 , & V_50 ) ;
V_44 = F_38 ( F_32 , NULL , L_7 ) ;
return 0 ;
}
