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
const T_1 * V_18 ;
T_1 V_19 ;
int V_20 , V_21 ;
struct V_22 V_23 ;
struct V_24 * V_5 , * V_25 ;
int V_26 = - V_27 ;
V_5 = F_14 ( V_17 -> V_5 , NULL ) ;
if ( ! V_5 )
goto V_28;
V_25 = F_15 ( NULL , NULL , L_1 ) ;
if ( ! V_25 )
V_25 = F_15 ( NULL , NULL ,
L_2 ) ;
if ( ! V_25 )
goto V_28;
V_26 = F_16 ( V_25 , 0 , & V_23 ) ;
F_17 ( V_25 ) ;
if ( V_26 )
goto V_28;
V_12 = F_18 ( V_23 . V_29 + V_30 , 0x2000 ) ;
if ( ! V_12 ) {
V_26 = - V_31 ;
goto V_28;
}
V_25 = F_15 ( NULL , NULL , L_3 ) ;
if ( ! V_25 )
V_25 = F_15 ( NULL , NULL ,
L_4 ) ;
if ( ! V_25 ) {
V_26 = - V_27 ;
goto V_32;
}
V_26 = F_16 ( V_25 , 0 , & V_23 ) ;
F_17 ( V_25 ) ;
if ( V_26 )
goto V_32;
V_3 = F_18 ( V_23 . V_29 , 0x1000 ) ;
if ( ! V_3 ) {
V_26 = - V_31 ;
goto V_32;
}
F_19 ( L_5 , V_17 -> V_5 ) ;
V_18 = F_20 ( V_5 , L_6 , NULL ) ;
if ( ! V_18 ) {
V_26 = - V_31 ;
goto V_33;
}
V_19 = * V_18 / 1000 ;
F_19 ( L_7 , V_19 ) ;
F_19 ( L_8 ) ;
for ( V_20 = 0 ; V_34 [ V_20 ] . V_35 != V_36 ; V_20 ++ ) {
V_34 [ V_20 ] . V_35 =
F_1 ( V_34 [ V_20 ] . V_37 ) * 100000 ;
F_19 ( L_9 , V_20 , V_34 [ V_20 ] . V_35 ) ;
}
V_17 -> V_38 . V_39 = F_4 () ;
V_21 = F_3 ( V_17 -> V_5 ) ;
F_19 ( L_10 , V_21 ) ;
V_17 -> V_40 = V_34 [ V_21 ] . V_35 ;
F_21 ( V_17 -> V_41 , V_42 ) ;
V_43 = V_17 -> V_40 * 1000ul ;
F_22 ( V_34 , V_17 -> V_5 ) ;
return F_23 ( V_17 , V_34 ) ;
V_33:
F_24 ( V_3 ) ;
V_32:
F_24 ( V_12 ) ;
V_28:
return V_26 ;
}
static int F_25 ( struct V_16 * V_17 )
{
if ( V_44 != V_45 )
return 0 ;
if ( V_12 )
F_24 ( V_12 ) ;
if ( V_3 )
F_24 ( V_3 ) ;
F_26 ( V_17 -> V_5 ) ;
return 0 ;
}
static int F_27 ( struct V_16 * V_17 )
{
return F_28 ( V_17 , V_34 ) ;
}
static int F_29 ( struct V_16 * V_17 ,
unsigned int V_46 ,
unsigned int V_47 )
{
struct V_48 V_49 ;
int V_50 ;
int V_20 ;
F_30 ( V_17 ,
V_34 ,
V_46 ,
V_47 ,
& V_50 ) ;
V_49 . V_51 = V_17 -> V_40 ;
V_49 . V_52 = V_34 [ V_50 ] . V_35 ;
F_31 ( & V_53 ) ;
F_32 ( V_17 , & V_49 , V_54 ) ;
F_19 ( L_11 ,
V_17 -> V_5 ,
V_34 [ V_50 ] . V_35 ,
V_34 [ V_50 ] . V_37 ) ;
V_15 = V_50 ;
F_33 (i)
F_5 ( V_20 , V_50 ) ;
F_32 ( V_17 , & V_49 , V_55 ) ;
F_34 ( & V_53 ) ;
V_43 = V_49 . V_52 * 1000ul ;
return 0 ;
}
static int T_2 F_35 ( void )
{
if ( ! F_36 ( L_12 ) &&
! F_36 ( L_13 ) )
return - V_27 ;
return F_37 ( & V_56 ) ;
}
static void T_3 F_38 ( void )
{
F_39 ( & V_56 ) ;
}
