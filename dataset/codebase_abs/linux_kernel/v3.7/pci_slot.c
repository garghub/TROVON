static int
F_1 ( T_1 V_1 , unsigned long long * V_2 )
{
int V_3 = - 1 ;
unsigned long long V_4 , V_5 ;
T_2 V_6 ;
struct V_7 V_8 = { V_9 , NULL } ;
F_2 ( V_1 , V_10 , & V_8 ) ;
F_3 ( L_1 , ( char * ) V_8 . V_11 ) ;
if ( V_12 ) {
V_6 = F_4 ( V_1 , L_2 , NULL , & V_5 ) ;
if ( F_5 ( V_6 ) && ! ( V_5 & V_13 ) )
goto V_14;
}
V_6 = F_4 ( V_1 , L_3 , NULL , & V_4 ) ;
if ( F_6 ( V_6 ) ) {
F_3 ( L_4 , V_6 , ( char * ) V_8 . V_11 ) ;
goto V_14;
}
V_6 = F_4 ( V_1 , L_5 , NULL , V_2 ) ;
if ( F_6 ( V_6 ) ) {
F_3 ( L_6 , V_6 , ( char * ) V_8 . V_11 ) ;
goto V_14;
}
V_3 = ( V_4 >> 16 ) & 0xffff ;
V_14:
F_7 ( V_8 . V_11 ) ;
return V_3 ;
}
static T_2
F_8 ( T_1 V_1 , T_3 V_15 , void * V_16 , void * * V_17 )
{
int V_3 ;
unsigned long long V_2 ;
char V_18 [ V_19 ] ;
struct V_20 * V_21 ;
struct V_22 * V_22 ;
struct V_23 * V_24 = V_16 ;
struct V_25 * V_25 = V_24 -> V_25 ;
V_3 = F_1 ( V_1 , & V_2 ) ;
if ( V_3 < 0 )
return V_26 ;
V_21 = F_9 ( sizeof( * V_21 ) , V_27 ) ;
if ( ! V_21 ) {
F_10 ( L_7 , V_28 ) ;
return V_26 ;
}
snprintf ( V_18 , sizeof( V_18 ) , L_8 , V_2 ) ;
V_22 = F_11 ( V_25 , V_3 , V_18 , NULL ) ;
if ( F_12 ( V_22 ) ) {
F_10 ( L_9 , F_13 ( V_22 ) ) ;
F_7 ( V_21 ) ;
return V_26 ;
}
V_21 -> V_29 = V_24 -> V_29 ;
V_21 -> V_22 = V_22 ;
F_14 ( & V_21 -> V_30 ) ;
F_15 ( & V_31 ) ;
F_16 ( & V_21 -> V_30 , & V_32 ) ;
F_17 ( & V_31 ) ;
F_18 ( & V_25 -> V_33 ) ;
F_3 ( L_10 ,
V_22 , V_25 -> V_34 , V_3 , V_18 ) ;
return V_26 ;
}
static T_2
F_19 ( T_1 V_1 , T_3 V_15 , void * V_16 , void * * V_17 )
{
int V_3 , V_35 ;
unsigned long long V_4 ;
T_2 V_6 ;
T_1 V_36 ;
T_4 V_37 ;
struct V_38 * V_33 ;
struct V_25 * V_25 ;
struct V_23 V_39 ;
struct V_23 * V_24 = V_16 ;
V_25 = V_24 -> V_25 ;
V_37 = V_24 -> V_37 ;
V_6 = F_20 ( V_1 , L_3 , & V_36 ) ;
if ( F_6 ( V_6 ) )
return V_26 ;
V_6 = F_4 ( V_1 , L_3 , NULL , & V_4 ) ;
if ( F_6 ( V_6 ) )
return V_26 ;
V_3 = ( V_4 >> 16 ) & 0xffff ;
V_35 = V_4 & 0xffff ;
V_33 = F_21 ( V_25 , F_22 ( V_3 , V_35 ) ) ;
if ( ! V_33 || ! V_33 -> V_40 )
goto V_14;
V_39 . V_25 = V_33 -> V_40 ;
V_39 . V_37 = V_37 ;
V_39 . V_29 = V_24 -> V_29 ;
F_3 ( L_11 , V_33 -> V_40 -> V_34 ) ;
V_6 = F_23 ( V_41 , V_1 , ( T_3 ) 1 ,
V_37 , NULL , & V_39 , NULL ) ;
if ( F_6 ( V_6 ) )
goto V_14;
V_6 = F_23 ( V_41 , V_1 , ( T_3 ) 1 ,
F_19 , NULL , & V_39 , NULL ) ;
V_14:
F_24 ( V_33 ) ;
return V_26 ;
}
static int
F_25 ( struct V_42 * V_43 , T_4 V_37 )
{
T_2 V_6 ;
T_1 V_1 = V_43 -> V_3 -> V_1 ;
struct V_25 * V_25 = V_43 -> V_44 ;
struct V_23 V_16 ;
V_16 . V_25 = V_25 ;
V_16 . V_37 = V_37 ;
V_16 . V_29 = V_1 ;
F_3 ( L_12 , V_25 -> V_34 ) ;
V_6 = F_23 ( V_41 , V_1 , ( T_3 ) 1 ,
V_37 , NULL , & V_16 , NULL ) ;
if ( F_6 ( V_6 ) )
return V_6 ;
V_6 = F_23 ( V_41 , V_1 , ( T_3 ) 1 ,
F_19 , NULL , & V_16 , NULL ) ;
if ( F_6 ( V_6 ) )
F_10 ( L_13 , V_28 , V_6 ) ;
return V_6 ;
}
static int
F_26 ( struct V_42 * V_43 )
{
T_2 V_6 ;
V_6 = F_25 ( V_43 , F_8 ) ;
if ( F_6 ( V_6 ) )
F_10 ( L_14 , V_28 , V_6 ) ;
return V_6 ;
}
static void
F_27 ( struct V_42 * V_43 )
{
struct V_20 * V_21 , * V_45 ;
struct V_25 * V_46 ;
T_1 V_1 = V_43 -> V_3 -> V_1 ;
F_15 ( & V_31 ) ;
F_28 (slot, tmp, &slot_list, list) {
if ( V_21 -> V_29 == V_1 ) {
F_29 ( & V_21 -> V_30 ) ;
V_46 = V_21 -> V_22 -> V_44 ;
F_30 ( V_21 -> V_22 ) ;
F_31 ( & V_46 -> V_33 ) ;
F_7 ( V_21 ) ;
}
}
F_17 ( & V_31 ) ;
}
static int F_32 ( const struct V_47 * V_48 )
{
F_33 ( L_15 , V_48 -> V_49 ) ;
V_12 = 1 ;
return 0 ;
}
static int T_5
F_34 ( void )
{
F_35 ( V_50 ) ;
F_36 ( & V_51 ) ;
return 0 ;
}
static void T_6
F_37 ( void )
{
F_38 ( & V_51 ) ;
}
