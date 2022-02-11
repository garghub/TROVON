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
F_12 ( V_5 -> V_22 ) ;
F_13 ( V_5 -> V_22 ) ;
}
if ( V_5 -> V_2 . V_16 != NULL )
F_14 ( V_5 -> V_2 . V_16 ) ;
if ( V_5 -> V_23 != NULL )
F_15 ( V_5 -> V_23 -> V_24 , F_16 ( V_5 -> V_23 ) ) ;
F_17 ( V_5 ) ;
if ( V_20 -> V_25 )
V_20 -> V_25 ( V_20 -> V_10 ) ;
return 0 ;
}
static int F_18 ( struct V_17 * V_18 )
{
struct V_19 * V_20 ;
struct V_4 * V_5 ;
T_3 V_26 = V_18 -> V_27 -> V_24 ;
T_3 V_28 = F_16 ( V_18 -> V_27 ) ;
char * * V_29 ;
int V_30 ;
int V_31 ;
V_20 = V_18 -> V_18 . V_21 ;
if ( V_20 == NULL )
return - V_32 ;
F_19 ( L_1
L_2 ,
( unsigned long long ) V_28 , ( unsigned long long ) V_26 ) ;
V_30 = V_18 -> V_33 ;
if ( V_20 -> V_34 ) {
V_31 = V_20 -> V_34 ( V_20 -> V_10 , V_30 ) ;
if ( V_31 != 0 )
return V_31 ;
}
V_5 = F_20 ( sizeof( struct V_4 ) , V_35 ) ;
if ( V_5 == NULL ) {
V_31 = - V_36 ;
goto V_25;
}
F_11 ( V_18 , V_5 ) ;
V_5 -> V_23 = F_21 ( V_26 , V_28 , V_37 ) ;
if ( V_5 -> V_23 == NULL ) {
F_22 ( & V_18 -> V_18 , L_3 ) ;
V_31 = - V_38 ;
goto V_39;
}
V_5 -> V_2 . V_40 = V_37 ;
V_5 -> V_2 . V_41 = V_20 -> V_41 ;
V_5 -> V_2 . V_42 = V_20 -> V_43 ;
V_5 -> V_2 . V_44 = V_45 ;
V_5 -> V_2 . V_16 = F_23 ( V_26 , V_28 ) ;
if ( ! V_5 -> V_2 . V_16 ) {
V_31 = - V_36 ;
goto V_46;
}
V_5 -> V_2 . V_7 = ( unsigned long ) V_5 ;
V_5 -> V_2 . V_47 = F_1 ;
V_5 -> V_2 . V_48 = F_7 ;
V_5 -> V_2 . V_49 = F_5 ;
V_5 -> V_9 = V_20 -> V_9 ;
V_5 -> V_10 = V_20 -> V_10 ;
V_5 -> V_11 = V_28 - 1 ;
F_24 ( & V_5 -> V_8 ) ;
for ( V_29 = V_50 ; ! V_5 -> V_22 && * V_29 ;
V_29 ++ )
V_5 -> V_22 = F_25 ( * V_29 , & V_5 -> V_2 ) ;
if ( V_5 -> V_22 == NULL ) {
F_22 ( & V_18 -> V_18 , L_4 ) ;
V_31 = - V_32 ;
goto F_14;
}
V_5 -> V_22 -> V_51 = V_52 ;
F_26 ( V_5 -> V_22 , NULL , NULL ,
V_20 -> V_53 ,
V_20 -> V_54 ) ;
return 0 ;
F_14:
F_14 ( V_5 -> V_2 . V_16 ) ;
V_46:
F_15 ( V_5 -> V_23 -> V_24 , F_16 ( V_5 -> V_23 ) ) ;
V_39:
F_17 ( V_5 ) ;
V_25:
if ( V_20 -> V_25 )
V_20 -> V_25 ( V_20 -> V_10 ) ;
return V_31 ;
}
