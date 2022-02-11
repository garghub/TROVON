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
V_20 = F_11 ( & V_18 -> V_18 ) ;
if ( V_5 -> V_21 != NULL ) {
F_12 ( V_5 -> V_21 ) ;
F_13 ( V_5 -> V_21 ) ;
}
if ( V_5 -> V_2 . V_16 != NULL )
F_14 ( V_5 -> V_2 . V_16 ) ;
if ( V_5 -> V_22 != NULL )
F_15 ( V_5 -> V_22 -> V_23 , F_16 ( V_5 -> V_22 ) ) ;
F_17 ( V_5 ) ;
if ( V_20 -> V_24 )
V_20 -> V_24 ( V_20 -> V_10 ) ;
return 0 ;
}
static int F_18 ( struct V_17 * V_18 )
{
struct V_19 * V_20 ;
struct V_4 * V_5 ;
T_3 V_25 = V_18 -> V_26 -> V_23 ;
T_3 V_27 = F_16 ( V_18 -> V_26 ) ;
char * * V_28 ;
int V_29 ;
int V_30 ;
V_20 = F_11 ( & V_18 -> V_18 ) ;
if ( V_20 == NULL )
return - V_31 ;
F_19 ( L_1
L_2 ,
( unsigned long long ) V_27 , ( unsigned long long ) V_25 ) ;
V_29 = V_18 -> V_32 ;
if ( V_20 -> V_33 ) {
V_30 = V_20 -> V_33 ( V_20 -> V_10 , V_29 ) ;
if ( V_30 != 0 )
return V_30 ;
}
V_5 = F_20 ( sizeof( struct V_4 ) , V_34 ) ;
if ( V_5 == NULL ) {
V_30 = - V_35 ;
goto V_24;
}
F_21 ( V_18 , V_5 ) ;
V_5 -> V_22 = F_22 ( V_25 , V_27 , V_36 ) ;
if ( V_5 -> V_22 == NULL ) {
F_23 ( & V_18 -> V_18 , L_3 ) ;
V_30 = - V_37 ;
goto V_38;
}
V_5 -> V_2 . V_39 = V_36 ;
V_5 -> V_2 . V_40 = V_20 -> V_40 ;
V_5 -> V_2 . V_41 = V_20 -> V_42 ;
V_5 -> V_2 . V_43 = V_44 ;
V_5 -> V_2 . V_16 = F_24 ( V_25 , V_27 ) ;
if ( ! V_5 -> V_2 . V_16 ) {
V_30 = - V_35 ;
goto V_45;
}
V_5 -> V_2 . V_7 = ( unsigned long ) V_5 ;
V_5 -> V_2 . V_46 = F_1 ;
V_5 -> V_2 . V_47 = F_7 ;
V_5 -> V_2 . V_48 = F_5 ;
V_5 -> V_9 = V_20 -> V_9 ;
V_5 -> V_10 = V_20 -> V_10 ;
V_5 -> V_11 = V_27 - 1 ;
F_25 ( & V_5 -> V_8 ) ;
for ( V_28 = V_49 ; ! V_5 -> V_21 && * V_28 ;
V_28 ++ )
V_5 -> V_21 = F_26 ( * V_28 , & V_5 -> V_2 ) ;
if ( V_5 -> V_21 == NULL ) {
F_23 ( & V_18 -> V_18 , L_4 ) ;
V_30 = - V_31 ;
goto F_14;
}
V_5 -> V_21 -> V_18 . V_50 = & V_18 -> V_18 ;
F_27 ( V_5 -> V_21 , NULL , NULL ,
V_20 -> V_51 ,
V_20 -> V_52 ) ;
return 0 ;
F_14:
F_14 ( V_5 -> V_2 . V_16 ) ;
V_45:
F_15 ( V_5 -> V_22 -> V_23 , F_16 ( V_5 -> V_22 ) ) ;
V_38:
F_17 ( V_5 ) ;
V_24:
if ( V_20 -> V_24 )
V_20 -> V_24 ( V_20 -> V_10 ) ;
return V_30 ;
}
