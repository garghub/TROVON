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
if ( F_5 ( V_10 -> V_15 & V_16 || ! V_12 ) )
return;
if ( V_12 != V_10 -> V_17 ) {
V_10 -> V_17 = V_12 ;
return;
}
if ( ! V_18 )
return;
V_18 -- ;
F_6 ( V_19 L_1
L_2 , V_10 -> V_20 , V_10 -> V_21 , V_11 ) ;
F_6 ( V_19 L_3
L_4 ) ;
F_7 ( V_10 ) ;
F_8 ( V_10 ) ;
F_9 () ;
if ( V_2 )
F_10 ( L_5 ) ;
}
static void F_11 ( struct V_9 * V_22 , struct V_9 * V_10 )
{
F_12 ( V_22 ) ;
F_12 ( V_10 ) ;
F_13 () ;
F_14 () ;
F_15 () ;
F_16 ( V_10 ) ;
F_16 ( V_22 ) ;
}
static void F_17 ( unsigned long V_11 )
{
int V_23 = V_24 ;
int V_25 = V_26 ;
struct V_9 * V_22 , * V_10 ;
if ( F_18 ( V_27 ) || V_7 )
return;
F_15 () ;
F_19 (g, t) {
if ( ! V_23 -- )
goto V_28;
if ( ! -- V_25 ) {
V_25 = V_26 ;
F_11 ( V_22 , V_10 ) ;
if ( V_10 -> V_29 == V_30 || V_22 -> V_29 == V_30 )
goto V_28;
}
if ( V_10 -> V_29 == V_31 )
F_4 ( V_10 , V_11 ) ;
} F_20 ( V_22 , V_10 ) ;
V_28:
F_13 () ;
}
static unsigned long F_21 ( unsigned long V_11 )
{
return V_11 ? V_11 * V_32 : V_33 ;
}
int F_22 ( struct V_34 * V_35 , int V_36 ,
void T_2 * V_37 ,
T_3 * V_38 , T_4 * V_39 )
{
int V_40 ;
V_40 = F_23 ( V_35 , V_36 , V_37 , V_38 , V_39 ) ;
if ( V_40 || ! V_36 )
goto V_41;
F_24 ( V_42 ) ;
V_41:
return V_40 ;
}
static int F_25 ( void * V_43 )
{
F_26 ( V_44 , 0 ) ;
for ( ; ; ) {
unsigned long V_11 = V_45 ;
while ( F_27 ( F_21 ( V_11 ) ) )
V_11 = V_45 ;
F_17 ( V_11 ) ;
}
return 0 ;
}
static int T_1 F_28 ( void )
{
F_29 ( & V_46 , & V_47 ) ;
V_42 = F_30 ( F_25 , NULL , L_6 ) ;
return 0 ;
}
