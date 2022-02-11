static T_1 F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 ;
T_1 V_6 ;
V_5 = (struct V_4 * ) V_2 -> V_7 ;
F_2 ( & V_5 -> V_8 ) ;
V_5 -> V_9 ( V_3 , V_5 -> V_10 ) ;
V_6 = F_3 ( V_2 , V_5 -> V_11 & V_3 ) ;
F_4 ( & V_5 -> V_8 ) ;
return V_6 ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_6 , unsigned long V_3 )
{
struct V_4 * V_5 ;
V_5 = (struct V_4 * ) V_2 -> V_7 ;
F_2 ( & V_5 -> V_8 ) ;
V_5 -> V_9 ( V_3 , V_5 -> V_10 ) ;
F_6 ( V_2 , V_6 , V_5 -> V_11 & V_3 ) ;
F_4 ( & V_5 -> V_8 ) ;
}
static void F_7 ( struct V_1 * V_2 , void * V_12 ,
unsigned long V_13 , T_2 V_14 )
{
struct V_4 * V_5 =
(struct V_4 * ) V_2 -> V_7 ;
unsigned V_15 ;
while ( V_14 > 0 ) {
V_15 = V_5 -> V_11 + 1 - ( V_13 & V_5 -> V_11 ) ;
if ( V_15 > V_14 )
V_15 = V_14 ;
F_2 ( & V_5 -> V_8 ) ;
V_5 -> V_9 ( V_13 , V_5 -> V_10 ) ;
F_8 ( V_12 , V_2 -> V_16 + ( V_13 & V_5 -> V_11 ) , V_15 ) ;
F_4 ( & V_5 -> V_8 ) ;
V_12 += V_15 ;
V_13 += V_15 ;
V_14 -= V_15 ;
}
}
static int F_9 ( struct V_17 * V_18 )
{
struct V_4 * V_5 ;
struct V_19 * V_20 ;
V_5 = F_10 ( V_18 ) ;
if ( V_5 == NULL )
return 0 ;
F_11 ( V_18 , NULL ) ;
V_20 = V_18 -> V_18 . V_21 ;
if ( V_5 -> V_22 != NULL ) {
if ( V_5 -> V_23 )
F_12 ( V_5 -> V_24 ) ;
F_13 ( V_5 -> V_22 ) ;
F_14 ( V_5 -> V_22 ) ;
}
if ( V_5 -> V_2 . V_16 != NULL )
F_15 ( V_5 -> V_2 . V_16 ) ;
if ( V_5 -> V_25 != NULL )
F_16 ( V_5 -> V_25 -> V_26 , F_17 ( V_5 -> V_25 ) ) ;
F_12 ( V_5 ) ;
if ( V_20 -> V_27 )
V_20 -> V_27 ( V_20 -> V_10 ) ;
return 0 ;
}
static int T_3 F_18 ( struct V_17 * V_18 )
{
struct V_19 * V_20 ;
struct V_4 * V_5 ;
T_4 V_28 = V_18 -> V_29 -> V_26 ;
T_4 V_30 = F_17 ( V_18 -> V_29 ) ;
char * * V_31 ;
int V_32 ;
int V_33 ;
V_20 = V_18 -> V_18 . V_21 ;
if ( V_20 == NULL )
return - V_34 ;
F_19 ( L_1
L_2 ,
( unsigned long long ) V_30 , ( unsigned long long ) V_28 ) ;
V_32 = V_18 -> V_35 ;
if ( V_20 -> V_36 ) {
V_33 = V_20 -> V_36 ( V_20 -> V_10 , V_32 ) ;
if ( V_33 != 0 )
return V_33 ;
}
V_5 = F_20 ( sizeof( struct V_4 ) , V_37 ) ;
if ( V_5 == NULL ) {
V_33 = - V_38 ;
goto V_27;
}
F_11 ( V_18 , V_5 ) ;
V_5 -> V_25 = F_21 ( V_28 , V_30 , V_39 ) ;
if ( V_5 -> V_25 == NULL ) {
F_22 ( & V_18 -> V_18 , L_3 ) ;
V_33 = - V_40 ;
goto V_41;
}
V_5 -> V_2 . V_42 = V_39 ;
V_5 -> V_2 . V_43 = V_20 -> V_43 ;
V_5 -> V_2 . V_44 = V_20 -> V_45 ;
V_5 -> V_2 . V_46 = V_47 ;
V_5 -> V_2 . V_16 = F_23 ( V_28 , V_30 ) ;
if ( ! V_5 -> V_2 . V_16 ) {
V_33 = - V_38 ;
goto V_48;
}
V_5 -> V_2 . V_7 = ( unsigned long ) V_5 ;
V_5 -> V_2 . V_49 = F_1 ;
V_5 -> V_2 . V_50 = F_7 ;
V_5 -> V_2 . V_51 = F_5 ;
V_5 -> V_9 = V_20 -> V_9 ;
V_5 -> V_10 = V_20 -> V_10 ;
V_5 -> V_11 = V_30 - 1 ;
F_24 ( & V_5 -> V_8 ) ;
for ( V_31 = V_52 ; ! V_5 -> V_22 && * V_31 ;
V_31 ++ )
V_5 -> V_22 = F_25 ( * V_31 , & V_5 -> V_2 ) ;
if ( V_5 -> V_22 == NULL ) {
F_22 ( & V_18 -> V_18 , L_4 ) ;
V_33 = - V_34 ;
goto F_15;
}
V_5 -> V_22 -> V_53 = V_54 ;
V_33 = F_26 ( V_5 -> V_22 , ( const char * * ) V_55 ,
& V_5 -> V_24 , 0 ) ;
if ( V_33 > 0 ) {
F_27 ( V_5 -> V_22 , V_5 -> V_24 , V_33 ) ;
return 0 ;
}
if ( V_20 -> V_23 ) {
F_19 ( L_5 ) ;
F_27 ( V_5 -> V_22 ,
V_20 -> V_24 ,
V_20 -> V_23 ) ;
return 0 ;
}
F_27 ( V_5 -> V_22 , NULL , 0 ) ;
return 0 ;
F_15:
F_15 ( V_5 -> V_2 . V_16 ) ;
V_48:
F_16 ( V_5 -> V_25 -> V_26 , F_17 ( V_5 -> V_25 ) ) ;
V_41:
F_12 ( V_5 ) ;
V_27:
if ( V_20 -> V_27 )
V_20 -> V_27 ( V_20 -> V_10 ) ;
return V_33 ;
}
static int T_5 F_28 ( void )
{
return F_29 ( & V_56 ) ;
}
static void T_6 F_30 ( void )
{
F_31 ( & V_56 ) ;
}
