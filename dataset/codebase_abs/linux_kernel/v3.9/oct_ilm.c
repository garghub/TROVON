static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
T_1 V_4 , V_5 , V_6 , V_7 ;
struct V_8 V_9 = V_10 ;
V_4 = F_2 () ;
V_6 = ( V_9 . V_11 * 1000000000 ) / V_4 ;
V_7 = ( V_9 . V_12 * 1000000000 ) / V_4 ;
V_5 = ( V_9 . V_13 * 1000000000 ) / ( V_4 * V_9 . V_14 ) ;
F_3 ( V_2 , L_1 ,
V_9 . V_14 , V_5 , V_6 , V_7 ) ;
return 0 ;
}
static int F_4 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
return F_5 ( V_16 , F_1 , NULL ) ;
}
static int F_6 ( void * V_17 , T_1 V_18 )
{
V_19 = true ;
return 0 ;
}
static int F_7 ( void )
{
struct V_20 * V_21 ;
V_22 = F_8 ( L_2 , 0 ) ;
if ( ! V_22 ) {
F_9 ( L_3 ) ;
return - 1 ;
}
V_21 = F_10 ( L_4 , 0222 , V_22 , NULL ,
& V_23 ) ;
if ( ! V_21 ) {
F_9 ( L_5 ) ;
return - 1 ;
}
V_21 = F_10 ( L_6 , 0222 , V_22 , NULL ,
& V_24 ) ;
if ( ! V_21 ) {
F_9 ( L_7 ) ;
return - 1 ;
}
return 0 ;
}
static void F_11 ( struct V_8 * V_10 , int V_25 )
{
int V_26 = 1 ;
if ( V_25 ) {
V_10 -> V_27 = ( F_12 () * V_26 ) / 1000 ;
V_10 -> V_28 = ( F_2 () * V_26 ) / 1000 ;
}
V_10 -> V_29 = 0 ;
V_10 -> V_30 = 0 ;
V_10 -> V_11 = 0 ;
V_10 -> V_12 = ( T_1 ) - 1 ;
V_10 -> V_13 = 0 ;
V_10 -> V_14 = 0 ;
}
static void F_13 ( int V_31 , T_1 V_26 )
{
union V_32 V_33 ;
unsigned long V_34 ;
V_33 . T_1 = 0 ;
V_33 . V_35 . V_36 = 1 ;
V_33 . V_35 . V_37 = V_26 ;
F_14 ( V_34 ) ;
V_10 . V_29 = F_15 () ;
F_16 ( F_17 ( V_31 ) , V_33 . T_1 ) ;
V_33 . T_1 = F_18 ( F_17 ( V_31 ) ) ;
V_10 . V_30 = F_15 () ;
F_19 ( V_34 ) ;
}
static T_2 F_20 ( int V_38 , void * V_39 )
{
T_1 V_40 ;
T_1 V_41 ;
if ( V_19 ) {
F_11 ( & V_10 , 0 ) ;
V_19 = false ;
} else {
V_41 = F_15 () ;
V_40 = V_41 - ( V_10 . V_29 + V_10 . V_28 ) ;
V_10 . V_14 ++ ;
V_10 . V_13 += V_40 ;
if ( V_40 > V_10 . V_11 )
V_10 . V_11 = V_40 ;
if ( V_40 < V_10 . V_12 )
V_10 . V_12 = V_40 ;
}
F_13 ( V_42 , V_10 . V_27 ) ;
return V_43 ;
}
static void F_21 ( int V_31 )
{
union V_32 V_33 ;
V_33 . V_35 . V_36 = 0 ;
V_33 . V_35 . V_37 = 0 ;
F_16 ( F_17 ( V_31 ) , V_33 . T_1 ) ;
V_33 . T_1 = F_18 ( F_17 ( V_31 ) ) ;
}
static T_3 int F_22 ( void )
{
int V_44 ;
int V_45 = V_46 + V_42 ;
V_44 = F_7 () ;
if ( V_44 ) {
F_23 ( 1 , L_8 ) ;
return V_44 ;
}
V_44 = F_24 ( V_45 , F_20 , V_47 ,
L_2 , 0 ) ;
if ( V_44 ) {
F_23 ( 1 , L_9 , V_45 ) ;
goto V_48;
}
F_11 ( & V_10 , 1 ) ;
F_13 ( V_42 , V_10 . V_27 ) ;
return 0 ;
V_48:
F_25 ( V_22 ) ;
return V_44 ;
}
static T_4 void F_26 ( void )
{
F_21 ( V_42 ) ;
if ( V_22 )
F_25 ( V_22 ) ;
F_27 ( V_46 + V_42 , 0 ) ;
}
