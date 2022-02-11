static T_1 F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
struct V_6 V_7 ;
V_5 -> V_8 = 0 ;
if ( F_2 ( V_2 , V_9 ) == 0 )
return V_10 ;
if ( ! F_3 ( V_2 , V_5 ) ) {
if ( F_4 ( V_2 , & V_7 ) ||
F_5 ( V_2 , & V_7 ) )
* V_5 = V_7 . V_5 ;
}
if ( ( V_5 -> V_8 & V_11 ) ||
( V_5 -> V_8 & V_12 ) )
V_5 -> V_8 = 0 ;
return V_13 ;
}
static bool F_6 ( T_2 V_14 , char * * type )
{
T_1 V_15 ;
struct V_16 * V_17 ;
char * V_18 = NULL ;
bool V_19 = false ;
if ( ! F_7 ( V_14 , L_1 ) )
return false ;
V_15 = F_8 ( V_14 , & V_17 ) ;
if ( F_9 ( V_15 ) ) {
if ( V_17 -> V_20 & V_21 )
V_18 = V_17 -> V_22 . string ;
if ( V_18 ) {
if ( strcmp ( V_18 , L_2 ) == 0 ) {
* type = L_3 ;
V_19 = true ;
} else if ( strcmp ( V_18 , L_4 ) == 0 ) {
* type = L_5 ;
V_19 = true ;
}
}
F_10 ( V_17 ) ;
}
return V_19 ;
}
static T_1 F_11 ( T_2 V_14 , T_3 V_23 ,
void * V_24 , void * * V_25 )
{
T_1 V_15 ;
unsigned long long V_26 ;
struct V_27 * V_28 ;
struct V_29 * V_30 = NULL ;
struct V_4 * V_5 = NULL ;
char * type = NULL ;
if ( ! F_6 ( V_14 , & type ) )
return V_10 ;
F_12 ( & V_31 ) ;
F_13 (ioapic, &ioapic_list, list)
if ( V_28 -> V_14 == V_14 ) {
F_14 ( & V_31 ) ;
return V_10 ;
}
V_15 = F_15 ( V_14 , L_1 , NULL , & V_26 ) ;
if ( F_16 ( V_15 ) ) {
F_17 ( V_14 , L_6 ) ;
goto exit;
}
V_28 = F_18 ( sizeof( * V_28 ) , V_32 ) ;
if ( ! V_28 ) {
F_19 ( L_7 ) ;
goto exit;
} else {
V_28 -> V_33 = ( T_2 ) V_24 ;
V_28 -> V_14 = V_14 ;
V_28 -> V_26 = ( T_3 ) V_26 ;
F_20 ( & V_28 -> V_34 ) ;
}
if ( F_21 ( V_14 , ( T_3 ) V_26 ) )
goto V_35;
V_30 = F_22 ( V_14 ) ;
if ( V_30 && F_23 ( V_30 , 0 ) ) {
if ( F_24 ( V_30 ) < 0 )
goto V_36;
F_25 ( V_30 ) ;
if ( F_26 ( V_30 , 0 , type ) )
goto V_37;
V_5 = & V_30 -> V_4 [ 0 ] ;
V_28 -> V_38 = V_30 ;
} else {
F_27 ( V_30 ) ;
V_30 = NULL ;
V_5 = & V_28 -> V_5 ;
F_28 ( V_14 , V_39 , F_1 , V_5 ) ;
if ( V_5 -> V_8 == 0 ) {
F_17 ( V_14 , L_8 ) ;
goto V_40;
} else if ( F_29 ( & V_41 , V_5 ) ) {
F_17 ( V_14 , L_9 ) ;
goto V_40;
}
}
if ( F_30 ( V_14 , V_5 -> V_42 , ( T_3 ) V_26 ) ) {
F_17 ( V_14 , L_10 ) ;
goto V_43;
}
V_35:
F_31 ( & V_28 -> V_34 , & V_44 ) ;
F_14 ( & V_31 ) ;
if ( V_30 )
F_32 ( & V_30 -> V_30 , L_11 ,
type , V_5 , ( T_3 ) V_26 ) ;
else
F_33 ( V_14 , L_11 ,
type , V_5 , ( T_3 ) V_26 ) ;
return V_10 ;
V_43:
if ( V_30 )
F_34 ( V_30 , 0 ) ;
else
F_35 ( V_5 ) ;
V_37:
if ( V_30 )
F_36 ( V_30 ) ;
V_36:
F_27 ( V_30 ) ;
V_40:
F_10 ( V_28 ) ;
exit:
F_14 ( & V_31 ) ;
* ( T_1 * ) V_25 = V_45 ;
return V_10 ;
}
int F_37 ( struct V_46 * V_47 )
{
T_1 V_15 , V_48 = V_10 ;
V_15 = F_38 ( V_49 , V_47 -> V_50 -> V_14 ,
V_51 , F_11 , NULL ,
V_47 -> V_50 -> V_14 , ( void * * ) & V_48 ) ;
return F_9 ( V_15 ) && F_9 ( V_48 ) ? 0 : - V_52 ;
}
int F_39 ( struct V_46 * V_47 )
{
int V_48 = 0 ;
struct V_27 * V_28 , * V_53 ;
F_12 ( & V_31 ) ;
F_40 (ioapic, tmp, &ioapic_list, list) {
if ( V_47 -> V_50 -> V_14 != V_28 -> V_33 )
continue;
if ( F_41 ( V_28 -> V_14 , V_28 -> V_26 ) )
V_48 = - V_54 ;
if ( V_28 -> V_38 ) {
F_34 ( V_28 -> V_38 , 0 ) ;
F_36 ( V_28 -> V_38 ) ;
F_27 ( V_28 -> V_38 ) ;
} else if ( V_28 -> V_5 . V_8 && V_28 -> V_5 . V_55 ) {
F_35 ( & V_28 -> V_5 ) ;
}
F_42 ( & V_28 -> V_34 ) ;
F_10 ( V_28 ) ;
}
F_14 ( & V_31 ) ;
return V_48 ;
}
