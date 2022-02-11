static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
V_4 = F_3 ( V_6 , V_8 ,
V_2 -> V_9 -> V_10 -> V_11 ) ;
if ( ! V_4 ) {
F_4 ( V_2 -> V_7 , L_1 ) ;
return - V_12 ;
}
F_5 ( V_2 -> V_7 , L_2 , ( unsigned int ) V_4 -> V_13 ,
( unsigned int ) F_6 ( V_4 ) ) ;
V_2 -> V_14 = V_4 -> V_13 + V_2 -> V_9 -> V_10 -> V_15 ;
V_2 -> V_16 = V_2 -> V_14 + V_2 -> V_9 -> V_10 -> V_17 - 1 ;
F_5 ( V_2 -> V_7 , L_3 , V_2 -> V_14 ) ;
V_2 -> V_18 = F_7 ( V_2 -> V_7 , V_2 -> V_14 ,
V_2 -> V_9 -> V_10 -> V_17 ) ;
if ( ! V_2 -> V_18 ) {
F_4 ( V_2 -> V_7 , L_4 ) ;
return - V_12 ;
}
V_2 -> V_19 = V_4 -> V_13 + V_2 -> V_9 -> V_10 -> V_20 ;
V_2 -> V_21 = V_2 -> V_19 + V_2 -> V_9 -> V_10 -> V_22 - 1 ;
F_5 ( V_2 -> V_7 , L_5 , V_2 -> V_19 ) ;
V_2 -> V_23 = F_7 ( V_2 -> V_7 , V_2 -> V_19 ,
V_2 -> V_9 -> V_10 -> V_22 ) ;
if ( ! V_2 -> V_23 ) {
F_4 ( V_2 -> V_7 , L_6 ) ;
return - V_12 ;
}
V_2 -> V_24 = V_4 -> V_13 + V_2 -> V_9 -> V_10 -> V_25 ;
F_5 ( V_2 -> V_7 , L_7 , V_2 -> V_24 ) ;
V_2 -> V_26 = F_7 ( V_2 -> V_7 , V_2 -> V_24 ,
V_2 -> V_9 -> V_10 -> V_27 ) ;
if ( ! V_2 -> V_26 ) {
F_4 ( V_2 -> V_7 , L_8 ) ;
return - V_12 ;
}
V_2 -> V_24 = V_2 -> V_9 -> V_10 -> V_28 ;
V_2 -> V_29 = V_4 -> V_13 + V_2 -> V_9 -> V_10 -> V_30 ;
F_5 ( V_2 -> V_7 , L_9 , V_2 -> V_29 ) ;
V_2 -> V_31 = F_7 ( V_2 -> V_7 , V_2 -> V_29 ,
V_2 -> V_9 -> V_10 -> V_32 ) ;
if ( ! V_2 -> V_31 ) {
F_4 ( V_2 -> V_7 , L_10 ) ;
return - V_12 ;
}
V_2 -> V_29 = V_2 -> V_33 . V_34 ;
V_4 = F_3 ( V_6 , V_8 ,
V_2 -> V_9 -> V_10 -> V_35 ) ;
if ( ! V_4 ) {
F_4 ( V_2 -> V_7 , L_11 ) ;
return - V_12 ;
}
V_2 -> V_36 = V_4 -> V_13 ;
V_2 -> V_37 = V_4 -> V_38 ;
F_5 ( V_2 -> V_7 , L_12 , V_2 -> V_36 ) ;
V_2 -> V_39 = F_7 ( V_2 -> V_7 , V_2 -> V_36 ,
F_6 ( V_4 ) ) ;
if ( ! V_2 -> V_39 ) {
F_4 ( V_2 -> V_7 , L_13 ) ;
return - V_12 ;
}
V_2 -> V_40 = F_8 ( V_6 ,
V_2 -> V_9 -> V_10 -> V_41 ) ;
return 0 ;
}
static T_1 F_9 ( T_2 V_42 , T_3 V_43 ,
void * V_44 , void * * V_45 )
{
* ( bool * ) V_44 = true ;
return V_46 ;
}
static struct V_47 * F_10 (
struct V_47 * V_48 )
{
struct V_47 * V_49 ;
bool V_50 = false ;
for ( V_49 = V_48 ; V_49 -> V_51 ; V_49 ++ )
if ( F_11 ( F_12 ( V_49 -> V_51 ,
F_9 ,
& V_50 , NULL ) ) && V_50 )
return V_49 ;
return NULL ;
}
int F_13 ( struct V_5 * V_6 )
{
struct V_52 * V_7 = & V_6 -> V_7 ;
int V_45 = 0 ;
struct V_1 * V_2 ;
const struct V_53 * V_54 ;
struct V_47 * V_49 ;
struct V_5 * V_55 ;
struct V_5 * V_56 ;
unsigned int V_57 ;
V_54 = F_14 ( V_7 -> V_58 -> V_59 , V_7 ) ;
if ( ! V_54 )
return - V_60 ;
F_15 ( V_7 , L_14 , V_54 -> V_54 ) ;
V_49 = (struct V_47 * ) V_54 -> V_61 ;
V_49 = F_10 ( V_49 ) ;
if ( V_49 == NULL ) {
F_4 ( V_7 , L_15 ) ;
return - V_60 ;
}
V_45 = F_16 ( V_54 -> V_54 , 16 , & V_57 ) ;
if ( V_45 < 0 ) {
F_4 ( V_7 , L_16 , V_45 ) ;
return V_45 ;
}
F_15 ( V_7 , L_17 , V_57 ) ;
V_56 = F_17 ( V_7 , V_49 -> V_9 -> V_62 , - 1 , NULL , 0 ) ;
if ( F_18 ( V_56 ) ) {
F_4 ( V_7 , L_18 , V_49 -> V_9 -> V_62 ) ;
return F_19 ( V_56 ) ;
}
V_55 = F_17 ( V_7 , V_49 -> V_63 , - 1 , NULL , 0 ) ;
if ( F_18 ( V_55 ) ) {
F_4 ( V_7 , L_18 , V_49 -> V_63 ) ;
return F_19 ( V_55 ) ;
}
V_45 = F_20 ( & V_2 , V_7 , V_57 ) ;
if ( V_45 < 0 )
return V_45 ;
V_2 -> V_9 = V_49 -> V_9 ;
strcpy ( V_2 -> V_64 , V_49 -> V_65 ) ;
V_45 = F_1 ( V_2 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_21 ( V_2 ) ;
if ( V_45 < 0 )
return V_45 ;
V_2 -> V_66 = F_22 ( V_2 -> V_7 , sizeof( * V_2 -> V_66 ) ,
V_67 ) ;
if ( ! V_2 -> V_66 ) {
return - V_68 ;
goto V_69;
}
F_23 ( V_2 ) ;
F_24 ( V_6 , V_2 ) ;
return V_45 ;
V_69:
F_25 ( V_2 ) ;
F_24 ( V_6 , NULL ) ;
F_4 ( V_2 -> V_7 , L_19 , V_45 ) ;
return V_45 ;
}
int F_26 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_27 ( V_6 ) ;
F_25 ( V_2 ) ;
F_24 ( V_6 , NULL ) ;
return 0 ;
}
