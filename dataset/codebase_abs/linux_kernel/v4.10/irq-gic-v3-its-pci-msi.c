static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
F_3 ( V_2 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
}
static int F_7 ( struct V_3 * V_4 )
{
int V_5 , V_6 ;
V_5 = F_8 ( F_9 ( V_4 ) , 0 ) ;
V_6 = F_8 ( F_10 ( V_4 ) , 0 ) ;
return F_8 ( V_5 , V_6 ) ;
}
static int F_11 ( struct V_3 * V_4 , T_1 V_7 , void * V_8 )
{
struct V_9 * V_10 = V_8 ;
if ( V_4 != V_10 -> V_4 )
V_10 -> V_11 += F_7 ( V_4 ) ;
return 0 ;
}
static int F_12 ( struct V_12 * V_13 , struct V_14 * V_15 ,
int V_16 , T_2 * V_17 )
{
struct V_3 * V_4 ;
struct V_9 V_10 ;
struct V_18 * V_19 ;
if ( ! F_13 ( V_15 ) )
return - V_20 ;
V_19 = F_14 ( V_13 -> V_21 ) ;
V_4 = F_15 ( V_15 ) ;
V_10 . V_4 = V_4 ;
V_10 . V_11 = V_16 ;
F_16 ( V_4 , F_11 , & V_10 ) ;
V_17 -> V_22 [ 0 ] . V_23 = F_17 ( V_13 , V_4 ) ;
return V_19 -> V_24 -> V_25 ( V_13 -> V_21 ,
V_15 , V_10 . V_11 , V_17 ) ;
}
static int T_3 F_18 ( struct V_26 * V_27 ,
const char * V_28 )
{
struct V_12 * V_21 ;
V_21 = F_19 ( V_27 , V_29 ) ;
if ( ! V_21 || ! F_14 ( V_21 ) ) {
F_20 ( L_1 , V_28 ) ;
return - V_30 ;
}
if ( ! F_21 ( V_27 , & V_31 ,
V_21 ) ) {
F_20 ( L_2 , V_28 ) ;
return - V_32 ;
}
return 0 ;
}
static int T_3 F_22 ( void )
{
struct V_33 * V_34 ;
for ( V_34 = F_23 ( NULL , V_35 ) ; V_34 ;
V_34 = F_23 ( V_34 , V_35 ) ) {
if ( ! F_24 ( V_34 , L_3 ) )
continue;
if ( F_18 ( F_25 ( V_34 ) , V_34 -> V_36 ) )
continue;
F_26 ( L_4 , V_34 -> V_36 ) ;
}
return 0 ;
}
static int T_3
F_27 ( struct V_37 * V_38 ,
const unsigned long V_39 )
{
struct V_40 * V_41 ;
struct V_26 * V_42 ;
const char * V_43 ;
int V_44 = - V_30 ;
V_41 = (struct V_40 * ) V_38 ;
V_43 = F_28 ( V_45 , L_5 ,
( long ) V_41 -> V_46 ) ;
V_42 = F_29 ( V_41 -> V_47 ) ;
if ( ! V_42 ) {
F_20 ( L_6 , V_43 ) ;
goto V_48;
}
V_44 = F_18 ( V_42 , V_43 ) ;
if ( ! V_44 )
F_26 ( L_4 , V_43 ) ;
V_48:
F_30 ( V_43 ) ;
return V_44 ;
}
static int T_3 F_31 ( void )
{
F_32 ( V_49 ,
F_27 , 0 ) ;
return 0 ;
}
static int T_3 F_31 ( void )
{
return 0 ;
}
static int T_3 F_33 ( void )
{
F_22 () ;
F_31 () ;
return 0 ;
}
