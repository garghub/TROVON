static int F_1 ( int V_1 )
{
T_1 V_2 ;
V_2 = F_2 ( V_3 + V_4 + ( V_1 * 0x10 ) ) ;
return V_2 & 0x3f ;
}
static int F_3 ( int V_5 )
{
T_1 V_2 ;
V_2 = F_2 ( V_3 + V_6 ) ;
V_2 = ( V_2 >> ( V_5 * 4 ) ) & 0x7 ;
return V_2 ;
}
static int F_4 ( void )
{
T_1 V_7 , V_2 ;
V_7 = F_2 ( V_3 + V_8 ) ;
if ( V_7 & V_9 )
V_2 = ( V_7 & V_10 ) * 128000 ;
else
V_2 = ( V_7 & V_10 ) * 1000 ;
return V_2 ;
}
static void F_5 ( int V_5 , unsigned int V_1 )
{
unsigned long V_11 ;
if ( F_6 ( ! V_12 ) )
return;
F_7 ( V_11 ) ;
F_8 ( V_12 + V_13 + V_14 * V_5 , V_1 ) ;
F_9 ( V_11 ) ;
}
int F_10 ( void )
{
return F_3 ( F_11 () ) ;
}
void F_12 ( int V_5 )
{
F_5 ( V_5 , V_15 ) ;
}
static int F_13 ( struct V_16 * V_17 )
{
struct V_18 * V_19 ;
const T_1 * V_20 ;
T_1 V_21 ;
int V_22 ;
struct V_23 V_24 ;
struct V_25 * V_5 , * V_26 ;
int V_27 = - V_28 ;
V_5 = F_14 ( V_17 -> V_5 , NULL ) ;
if ( ! V_5 )
goto V_29;
V_26 = F_15 ( NULL , NULL , L_1 ) ;
if ( ! V_26 )
V_26 = F_15 ( NULL , NULL ,
L_2 ) ;
if ( ! V_26 )
goto V_29;
V_27 = F_16 ( V_26 , 0 , & V_24 ) ;
F_17 ( V_26 ) ;
if ( V_27 )
goto V_29;
V_12 = F_18 ( V_24 . V_30 + V_31 , 0x2000 ) ;
if ( ! V_12 ) {
V_27 = - V_32 ;
goto V_29;
}
V_26 = F_15 ( NULL , NULL , L_3 ) ;
if ( ! V_26 )
V_26 = F_15 ( NULL , NULL ,
L_4 ) ;
if ( ! V_26 ) {
V_27 = - V_28 ;
goto V_33;
}
V_27 = F_16 ( V_26 , 0 , & V_24 ) ;
F_17 ( V_26 ) ;
if ( V_27 )
goto V_33;
V_3 = F_18 ( V_24 . V_30 , 0x1000 ) ;
if ( ! V_3 ) {
V_27 = - V_32 ;
goto V_33;
}
F_19 ( L_5 , V_17 -> V_5 ) ;
V_20 = F_20 ( V_5 , L_6 , NULL ) ;
if ( ! V_20 ) {
V_27 = - V_32 ;
goto V_34;
}
V_21 = * V_20 / 1000 ;
F_19 ( L_7 , V_21 ) ;
F_19 ( L_8 ) ;
F_21 (pos, pas_freqs) {
V_19 -> V_35 = F_1 ( V_19 -> V_36 ) * 100000 ;
F_19 ( L_9 , ( int ) ( V_19 - V_37 ) , V_19 -> V_35 ) ;
}
V_22 = F_3 ( V_17 -> V_5 ) ;
F_19 ( L_10 , V_22 ) ;
V_17 -> V_38 = V_37 [ V_22 ] . V_35 ;
V_39 = V_17 -> V_38 * 1000ul ;
return F_22 ( V_17 , V_37 , F_4 () ) ;
V_34:
F_23 ( V_3 ) ;
V_33:
F_23 ( V_12 ) ;
V_29:
return V_27 ;
}
static int F_24 ( struct V_16 * V_17 )
{
if ( V_40 != V_41 )
return 0 ;
if ( V_12 )
F_23 ( V_12 ) ;
if ( V_3 )
F_23 ( V_3 ) ;
return 0 ;
}
static int F_25 ( struct V_16 * V_17 ,
unsigned int V_42 )
{
int V_43 ;
F_19 ( L_11 ,
V_17 -> V_5 ,
V_37 [ V_42 ] . V_35 ,
V_37 [ V_42 ] . V_36 ) ;
V_15 = V_42 ;
F_26 (i)
F_5 ( V_43 , V_42 ) ;
V_39 = V_37 [ V_42 ] . V_35 * 1000ul ;
return 0 ;
}
static int T_2 F_27 ( void )
{
if ( ! F_28 ( L_12 ) &&
! F_28 ( L_13 ) )
return - V_28 ;
return F_29 ( & V_44 ) ;
}
static void T_3 F_30 ( void )
{
F_31 ( & V_44 ) ;
}
