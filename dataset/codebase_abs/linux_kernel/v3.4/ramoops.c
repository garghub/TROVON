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
V_4 != V_23 )
return;
if ( V_4 == V_22 && ! V_10 -> V_24 )
return;
V_18 = V_10 -> V_25 + ( V_10 -> V_26 * V_10 -> V_27 ) ;
V_19 = V_18 ;
memset ( V_18 , '\0' , V_10 -> V_27 ) ;
V_16 = sprintf ( V_18 , L_1 , V_28 ) ;
V_18 += V_16 ;
F_3 ( & V_21 ) ;
V_16 = sprintf ( V_18 , L_2 , ( long ) V_21 . V_29 , ( long ) V_21 . V_30 ) ;
V_18 += V_16 ;
V_17 = V_18 - V_19 ;
V_15 = F_4 ( V_8 , V_10 -> V_27 - V_17 ) ;
V_14 = F_4 ( V_6 , V_10 -> V_27 - V_17 - V_15 ) ;
V_13 = V_8 - V_15 ;
V_12 = V_6 - V_14 ;
memcpy ( V_18 , V_5 + V_12 , V_14 ) ;
memcpy ( V_18 + V_14 , V_7 + V_13 , V_15 ) ;
V_10 -> V_26 = ( V_10 -> V_26 + 1 ) % V_10 -> V_31 ;
}
static int T_1 F_5 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = V_33 -> V_36 . V_37 ;
struct V_9 * V_10 = & V_38 ;
int V_39 = - V_40 ;
if ( ! V_35 -> V_41 || ! V_35 -> V_27 ) {
F_6 ( L_3
L_4 ) ;
goto V_42;
}
V_35 -> V_41 = F_7 ( V_35 -> V_41 ) ;
V_35 -> V_27 = F_7 ( V_35 -> V_27 ) ;
if ( V_35 -> V_41 < V_43 &&
V_35 -> V_27 < V_43 ) {
F_6 ( L_5 , V_43 ) ;
goto V_42;
}
if ( V_35 -> V_41 < V_35 -> V_27 ) {
F_6 ( L_6
L_7 ) ;
goto V_42;
}
V_10 -> V_31 = V_35 -> V_41 / V_35 -> V_27 ;
V_10 -> V_26 = 0 ;
V_10 -> V_44 = V_35 -> V_41 ;
V_10 -> V_45 = V_35 -> V_46 ;
V_10 -> V_27 = V_35 -> V_27 ;
V_10 -> V_24 = V_35 -> V_24 ;
if ( ! F_8 ( V_10 -> V_45 , V_10 -> V_44 , L_8 ) ) {
F_6 ( L_9 ) ;
V_39 = - V_40 ;
goto V_42;
}
V_10 -> V_25 = F_9 ( V_10 -> V_45 , V_10 -> V_44 ) ;
if ( ! V_10 -> V_25 ) {
F_6 ( L_10 ) ;
goto V_47;
}
V_10 -> V_11 . V_11 = F_1 ;
V_39 = F_10 ( & V_10 -> V_11 ) ;
if ( V_39 ) {
F_6 ( L_11 ) ;
goto V_48;
}
V_41 = V_35 -> V_41 ;
V_46 = V_35 -> V_46 ;
V_27 = V_35 -> V_27 ;
V_24 = V_35 -> V_24 ;
return 0 ;
V_48:
F_11 ( V_10 -> V_25 ) ;
V_47:
F_12 ( V_10 -> V_45 , V_10 -> V_44 ) ;
V_42:
return V_39 ;
}
static int T_2 F_13 ( struct V_32 * V_33 )
{
struct V_9 * V_10 = & V_38 ;
if ( F_14 ( & V_10 -> V_11 ) < 0 )
F_15 ( L_12 ) ;
F_11 ( V_10 -> V_25 ) ;
F_12 ( V_10 -> V_45 , V_10 -> V_44 ) ;
return 0 ;
}
static int T_1 F_16 ( void )
{
int V_49 ;
V_49 = F_17 ( & V_50 , F_5 ) ;
if ( V_49 == - V_51 ) {
F_18 ( L_13 ) ;
V_52 = F_19 ( sizeof( struct V_34 ) ,
V_53 ) ;
if ( ! V_52 )
return - V_54 ;
V_52 -> V_41 = V_41 ;
V_52 -> V_46 = V_46 ;
V_52 -> V_27 = V_27 ;
V_52 -> V_24 = V_24 ;
V_55 = F_20 ( & V_50 , F_5 ,
NULL , 0 , V_52 ,
sizeof( struct V_34 ) ) ;
if ( F_21 ( V_55 ) )
V_49 = F_22 ( V_55 ) ;
else
V_49 = 0 ;
}
return V_49 ;
}
static void T_2 F_23 ( void )
{
F_24 ( & V_50 ) ;
F_25 ( V_52 ) ;
}
