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
F_3 ( L_4 ,
V_6 , ( char * ) V_8 . V_11 ) ;
goto V_14;
}
V_6 = F_4 ( V_1 , L_5 , NULL , V_2 ) ;
if ( F_6 ( V_6 ) ) {
F_3 ( L_6 ,
V_6 , ( char * ) V_8 . V_11 ) ;
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
struct V_23 * V_23 = V_16 ;
V_3 = F_1 ( V_1 , & V_2 ) ;
if ( V_3 < 0 )
return V_24 ;
F_9 (slot, &slot_list, list) {
V_22 = V_21 -> V_22 ;
if ( V_22 -> V_25 == V_23 && V_22 -> V_26 == V_3 )
return V_24 ;
}
V_21 = F_10 ( sizeof( * V_21 ) , V_27 ) ;
if ( ! V_21 )
return V_24 ;
snprintf ( V_18 , sizeof( V_18 ) , L_7 , V_2 ) ;
V_22 = F_11 ( V_23 , V_3 , V_18 , NULL ) ;
if ( F_12 ( V_22 ) ) {
F_13 ( L_8 , F_14 ( V_22 ) ) ;
F_7 ( V_21 ) ;
return V_24 ;
}
V_21 -> V_22 = V_22 ;
F_15 ( & V_21 -> V_28 , & V_29 ) ;
F_16 ( & V_23 -> V_30 ) ;
F_3 ( L_9 ,
V_22 , V_23 -> V_26 , V_3 , V_18 ) ;
return V_24 ;
}
void F_17 ( struct V_23 * V_25 )
{
T_1 V_1 = F_18 ( V_25 -> V_31 ) ;
if ( V_1 ) {
F_19 ( & V_32 ) ;
F_20 ( V_33 , V_1 , 1 ,
F_8 , NULL , V_25 , NULL ) ;
F_21 ( & V_32 ) ;
}
}
void F_22 ( struct V_23 * V_25 )
{
struct V_20 * V_21 , * V_34 ;
F_19 ( & V_32 ) ;
F_23 (slot, tmp, &slot_list, list) {
if ( V_21 -> V_22 -> V_25 == V_25 ) {
F_24 ( & V_21 -> V_28 ) ;
F_25 ( V_21 -> V_22 ) ;
F_26 ( & V_25 -> V_30 ) ;
F_7 ( V_21 ) ;
}
}
F_21 ( & V_32 ) ;
}
static int F_27 ( const struct V_35 * V_36 )
{
F_28 ( L_10 ,
V_36 -> V_37 ) ;
V_12 = 1 ;
return 0 ;
}
void T_4 F_29 ( void )
{
F_30 ( V_38 ) ;
}
