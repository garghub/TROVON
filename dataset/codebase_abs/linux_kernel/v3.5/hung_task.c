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
if ( ! V_19 )
return;
V_19 -- ;
F_6 ( V_20 L_1
L_2 , V_10 -> V_21 , V_10 -> V_22 , V_11 ) ;
F_6 ( V_20 L_3
L_4 ) ;
F_7 ( V_10 ) ;
F_8 ( V_10 ) ;
F_9 () ;
if ( V_2 ) {
F_10 () ;
F_11 ( L_5 ) ;
}
}
static bool F_12 ( struct V_9 * V_23 , struct V_9 * V_10 )
{
bool V_24 ;
F_13 ( V_23 ) ;
F_13 ( V_10 ) ;
F_14 () ;
F_15 () ;
F_16 () ;
V_24 = F_17 ( V_23 ) && F_17 ( V_10 ) ;
F_18 ( V_10 ) ;
F_18 ( V_23 ) ;
return V_24 ;
}
static void F_19 ( unsigned long V_11 )
{
int V_25 = V_26 ;
int V_27 = V_28 ;
struct V_9 * V_23 , * V_10 ;
if ( F_20 ( V_29 ) || V_7 )
return;
F_16 () ;
F_21 (g, t) {
if ( ! V_25 -- )
goto V_30;
if ( ! -- V_27 ) {
V_27 = V_28 ;
if ( ! F_12 ( V_23 , V_10 ) )
goto V_30;
}
if ( V_10 -> V_31 == V_32 )
F_4 ( V_10 , V_11 ) ;
} F_22 ( V_23 , V_10 ) ;
V_30:
F_14 () ;
}
static unsigned long F_23 ( unsigned long V_11 )
{
return V_11 ? V_11 * V_33 : V_34 ;
}
int F_24 ( struct V_35 * V_36 , int V_37 ,
void T_2 * V_38 ,
T_3 * V_39 , T_4 * V_40 )
{
int V_41 ;
V_41 = F_25 ( V_36 , V_37 , V_38 , V_39 , V_40 ) ;
if ( V_41 || ! V_37 )
goto V_42;
F_26 ( V_43 ) ;
V_42:
return V_41 ;
}
static int F_27 ( void * V_44 )
{
F_28 ( V_45 , 0 ) ;
for ( ; ; ) {
unsigned long V_11 = V_46 ;
while ( F_29 ( F_23 ( V_11 ) ) )
V_11 = V_46 ;
F_19 ( V_11 ) ;
}
return 0 ;
}
static int T_1 F_30 ( void )
{
F_31 ( & V_47 , & V_48 ) ;
V_43 = F_32 ( F_27 , NULL , L_6 ) ;
return 0 ;
}
