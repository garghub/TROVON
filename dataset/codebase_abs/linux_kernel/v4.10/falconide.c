static void F_1 ( void )
{
if ( V_1 == 0 ) {
F_2 ( V_2 L_1 , V_3 ) ;
return;
}
V_1 = 0 ;
F_3 () ;
}
static void F_4 ( T_1 V_4 , void * V_5 )
{
if ( V_1 == 0 ) {
if ( F_5 () > 0 )
F_6 ( L_2 ) ;
F_7 ( V_4 , V_5 ) ;
V_1 = 1 ;
}
}
static void F_8 ( T_2 * V_6 , struct V_7 * V_8 ,
void * V_9 , unsigned int V_10 )
{
unsigned long V_11 = V_6 -> V_12 -> V_13 . V_11 ;
if ( V_6 -> V_14 == V_15 && V_8 && ( V_8 -> V_16 & V_17 ) ) {
F_9 ( V_11 , V_9 , ( V_10 + 1 ) / 2 ) ;
return;
}
F_10 ( ( V_18 * ) V_11 , V_9 , ( V_10 + 1 ) / 2 ) ;
}
static void F_11 ( T_2 * V_6 , struct V_7 * V_8 ,
void * V_9 , unsigned int V_10 )
{
unsigned long V_11 = V_6 -> V_12 -> V_13 . V_11 ;
if ( V_6 -> V_14 == V_15 && V_8 && ( V_8 -> V_16 & V_17 ) ) {
F_12 ( V_11 , V_9 , ( V_10 + 1 ) / 2 ) ;
return;
}
F_13 ( ( V_18 * ) V_11 , V_9 , ( V_10 + 1 ) / 2 ) ;
}
static void T_3 F_14 ( struct V_19 * V_20 )
{
int V_21 ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
V_20 -> V_13 . V_11 = V_22 ;
for ( V_21 = 1 ; V_21 < 8 ; V_21 ++ )
V_20 -> V_23 [ V_21 ] = V_22 + 1 + V_21 * 4 ;
V_20 -> V_13 . V_24 = V_22 + V_25 ;
V_20 -> V_26 = V_27 ;
}
static int T_3 F_15 ( void )
{
struct V_28 * V_29 ;
struct V_19 V_20 , * V_30 [] = { & V_20 } ;
int V_31 ;
if ( ! V_32 || ! F_16 ( V_33 ) )
return - V_34 ;
F_2 ( V_35 L_3 ) ;
if ( ! F_17 ( V_22 , 0x40 , V_36 ) ) {
F_2 ( V_2 L_4 , V_36 ) ;
return - V_37 ;
}
F_14 ( & V_20 ) ;
V_29 = F_18 ( & V_38 , V_30 , 1 ) ;
if ( V_29 == NULL ) {
V_31 = - V_39 ;
goto V_40;
}
F_4 ( NULL , NULL ) ;
V_31 = F_19 ( V_29 , & V_38 , V_30 ) ;
F_1 () ;
if ( V_31 )
goto V_41;
return 0 ;
V_41:
F_20 ( V_29 ) ;
V_40:
F_21 ( V_22 , 0x40 ) ;
return V_31 ;
}
