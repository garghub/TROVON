static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 , const char * V_5 , unsigned long V_6 ,
const char * V_7 , unsigned long V_8 )
{
struct V_9 * V_10 = F_2 ( V_2 ,
struct V_9 , V_11 ) ;
unsigned long V_12 , V_13 ;
unsigned long V_14 , V_15 ;
int V_16 , V_17 ;
char * V_18 , * V_19 ;
struct V_20 V_21 ;
if ( V_4 != V_22 &&
V_4 != V_23 &&
V_4 != V_24 )
return;
if ( V_4 == V_22 && ! V_10 -> V_25 )
return;
V_18 = V_10 -> V_26 + ( V_10 -> V_27 * V_10 -> V_28 ) ;
V_19 = V_18 ;
memset ( V_18 , '\0' , V_10 -> V_28 ) ;
V_16 = sprintf ( V_18 , L_1 , V_29 ) ;
V_18 += V_16 ;
F_3 ( & V_21 ) ;
V_16 = sprintf ( V_18 , L_2 , ( long ) V_21 . V_30 , ( long ) V_21 . V_31 ) ;
V_18 += V_16 ;
V_17 = V_18 - V_19 ;
V_15 = F_4 ( V_8 , V_10 -> V_28 - V_17 ) ;
V_14 = F_4 ( V_6 , V_10 -> V_28 - V_17 - V_15 ) ;
V_13 = V_8 - V_15 ;
V_12 = V_6 - V_14 ;
memcpy ( V_18 , V_5 + V_12 , V_14 ) ;
memcpy ( V_18 + V_14 , V_7 + V_13 , V_15 ) ;
V_10 -> V_27 = ( V_10 -> V_27 + 1 ) % V_10 -> V_32 ;
}
static int T_1 F_5 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = V_34 -> V_37 . V_38 ;
struct V_9 * V_10 = & V_39 ;
int V_40 = - V_41 ;
if ( ! V_36 -> V_42 || ! V_36 -> V_28 ) {
F_6 ( L_3
L_4 ) ;
goto V_43;
}
F_7 ( V_36 -> V_42 ) ;
F_7 ( V_36 -> V_28 ) ;
if ( V_36 -> V_42 < V_44 &&
V_36 -> V_28 < V_44 ) {
F_6 ( L_5 , V_44 ) ;
goto V_43;
}
if ( V_36 -> V_42 < V_36 -> V_28 ) {
F_6 ( L_6
L_7 ) ;
goto V_43;
}
V_10 -> V_32 = V_36 -> V_42 / V_36 -> V_28 ;
V_10 -> V_27 = 0 ;
V_10 -> V_45 = V_36 -> V_42 ;
V_10 -> V_46 = V_36 -> V_47 ;
V_10 -> V_28 = V_36 -> V_28 ;
V_10 -> V_25 = V_36 -> V_25 ;
V_42 = V_36 -> V_42 ;
V_47 = V_36 -> V_47 ;
V_28 = V_36 -> V_28 ;
V_25 = V_36 -> V_25 ;
if ( ! F_8 ( V_10 -> V_46 , V_10 -> V_45 , L_8 ) ) {
F_6 ( L_9 ) ;
V_40 = - V_41 ;
goto V_43;
}
V_10 -> V_26 = F_9 ( V_10 -> V_46 , V_10 -> V_45 ) ;
if ( ! V_10 -> V_26 ) {
F_6 ( L_10 ) ;
goto V_48;
}
V_10 -> V_11 . V_11 = F_1 ;
V_40 = F_10 ( & V_10 -> V_11 ) ;
if ( V_40 ) {
F_6 ( L_11 ) ;
goto V_49;
}
return 0 ;
V_49:
F_11 ( V_10 -> V_26 ) ;
V_48:
F_12 ( V_10 -> V_46 , V_10 -> V_45 ) ;
V_43:
return V_40 ;
}
static int T_2 F_13 ( struct V_33 * V_34 )
{
struct V_9 * V_10 = & V_39 ;
if ( F_14 ( & V_10 -> V_11 ) < 0 )
F_15 ( L_12 ) ;
F_11 ( V_10 -> V_26 ) ;
F_12 ( V_10 -> V_46 , V_10 -> V_45 ) ;
return 0 ;
}
static int T_1 F_16 ( void )
{
int V_50 ;
V_50 = F_17 ( & V_51 , F_5 ) ;
if ( V_50 == - V_52 ) {
F_18 ( L_13 ) ;
V_53 = F_19 ( sizeof( struct V_35 ) ,
V_54 ) ;
if ( ! V_53 )
return - V_55 ;
V_53 -> V_42 = V_42 ;
V_53 -> V_47 = V_47 ;
V_53 -> V_28 = V_28 ;
V_53 -> V_25 = V_25 ;
V_56 = F_20 ( & V_51 , F_5 ,
NULL , 0 , V_53 ,
sizeof( struct V_35 ) ) ;
if ( F_21 ( V_56 ) )
V_50 = F_22 ( V_56 ) ;
else
V_50 = 0 ;
}
return V_50 ;
}
static void T_2 F_23 ( void )
{
F_24 ( & V_51 ) ;
F_25 ( V_53 ) ;
}
