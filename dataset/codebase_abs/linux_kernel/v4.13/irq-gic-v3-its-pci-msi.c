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
static int F_7 ( struct V_3 * V_4 , void * V_5 )
{
int V_6 , V_7 , * V_8 = V_5 ;
V_6 = F_8 ( F_9 ( V_4 ) , 0 ) ;
V_7 = F_8 ( F_10 ( V_4 ) , 0 ) ;
* V_8 += F_8 ( V_6 , V_7 ) ;
return 0 ;
}
static int F_11 ( struct V_3 * V_4 , T_1 V_9 , void * V_5 )
{
struct V_3 * * V_10 = V_5 ;
* V_10 = V_4 ;
return 0 ;
}
static int F_12 ( struct V_11 * V_12 , struct V_13 * V_14 ,
int V_15 , T_2 * V_16 )
{
struct V_3 * V_4 , * V_10 ;
struct V_17 * V_18 ;
int V_19 = 0 ;
if ( ! F_13 ( V_14 ) )
return - V_20 ;
V_18 = F_14 ( V_12 -> V_21 ) ;
V_4 = F_15 ( V_14 ) ;
F_16 ( V_4 , F_11 , & V_10 ) ;
if ( V_10 != V_4 && V_10 -> V_22 )
F_17 ( V_10 -> V_22 , F_7 ,
& V_19 ) ;
V_16 -> V_23 [ 0 ] . V_24 = F_18 ( V_12 , V_4 ) ;
return V_18 -> V_25 -> V_26 ( V_12 -> V_21 ,
V_14 , F_8 ( V_15 , V_19 ) , V_16 ) ;
}
static int T_3 F_19 ( struct V_27 * V_28 ,
const char * V_29 )
{
struct V_11 * V_21 ;
V_21 = F_20 ( V_28 , V_30 ) ;
if ( ! V_21 || ! F_14 ( V_21 ) ) {
F_21 ( L_1 , V_29 ) ;
return - V_31 ;
}
if ( ! F_22 ( V_28 , & V_32 ,
V_21 ) ) {
F_21 ( L_2 , V_29 ) ;
return - V_33 ;
}
return 0 ;
}
static int T_3 F_23 ( void )
{
struct V_34 * V_35 ;
for ( V_35 = F_24 ( NULL , V_36 ) ; V_35 ;
V_35 = F_24 ( V_35 , V_36 ) ) {
if ( ! F_25 ( V_35 , L_3 ) )
continue;
if ( F_19 ( F_26 ( V_35 ) , V_35 -> V_37 ) )
continue;
F_27 ( L_4 , V_35 -> V_37 ) ;
}
return 0 ;
}
static int T_3
F_28 ( struct V_38 * V_39 ,
const unsigned long V_40 )
{
struct V_41 * V_42 ;
struct V_27 * V_43 ;
const char * V_44 ;
int V_45 = - V_31 ;
V_42 = (struct V_41 * ) V_39 ;
V_44 = F_29 ( V_46 , L_5 ,
( long ) V_42 -> V_47 ) ;
V_43 = F_30 ( V_42 -> V_48 ) ;
if ( ! V_43 ) {
F_21 ( L_6 , V_44 ) ;
goto V_49;
}
V_45 = F_19 ( V_43 , V_44 ) ;
if ( ! V_45 )
F_27 ( L_4 , V_44 ) ;
V_49:
F_31 ( V_44 ) ;
return V_45 ;
}
static int T_3 F_32 ( void )
{
F_33 ( V_50 ,
F_28 , 0 ) ;
return 0 ;
}
static int T_3 F_32 ( void )
{
return 0 ;
}
static int T_3 F_34 ( void )
{
F_23 () ;
F_32 () ;
return 0 ;
}
