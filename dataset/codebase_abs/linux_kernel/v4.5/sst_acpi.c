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
static int F_9 ( struct V_5 * V_6 )
{
struct V_42 * V_7 = & V_6 -> V_7 ;
int V_43 = 0 ;
struct V_1 * V_2 ;
const struct V_44 * V_45 ;
struct V_46 * V_47 ;
struct V_5 * V_48 ;
struct V_5 * V_49 ;
struct V_50 * V_9 ;
unsigned int V_51 ;
V_45 = F_10 ( V_7 -> V_52 -> V_53 , V_7 ) ;
if ( ! V_45 )
return - V_54 ;
F_11 ( V_7 , L_14 , V_45 -> V_45 ) ;
V_47 = (struct V_46 * ) V_45 -> V_55 ;
V_47 = F_12 ( V_47 ) ;
if ( V_47 == NULL ) {
F_4 ( V_7 , L_15 ) ;
return - V_54 ;
}
V_9 = V_47 -> V_9 ;
V_43 = F_13 ( V_45 -> V_45 , 16 , & V_51 ) ;
if ( V_43 < 0 ) {
F_4 ( V_7 , L_16 , V_43 ) ;
return V_43 ;
}
F_11 ( V_7 , L_17 , V_51 ) ;
V_49 = F_14 ( V_7 , V_9 -> V_56 , - 1 ,
NULL , 0 ) ;
if ( F_15 ( V_49 ) ) {
F_4 ( V_7 , L_18 ,
V_9 -> V_56 ) ;
return F_16 ( V_49 ) ;
}
V_48 = F_14 ( V_7 , V_47 -> V_57 , - 1 ,
( const void * ) V_47 , sizeof( * V_47 ) ) ;
if ( F_15 ( V_48 ) ) {
F_4 ( V_7 , L_18 ,
V_47 -> V_57 ) ;
return F_16 ( V_48 ) ;
}
V_43 = F_17 ( & V_2 , V_7 , V_51 ) ;
if ( V_43 < 0 )
return V_43 ;
V_2 -> V_9 = V_9 ;
strcpy ( V_2 -> V_58 , V_47 -> V_59 ) ;
V_43 = F_1 ( V_2 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_18 ( V_2 ) ;
if ( V_43 < 0 )
return V_43 ;
V_2 -> V_60 = F_19 ( V_2 -> V_7 , sizeof( * V_2 -> V_60 ) ,
V_61 ) ;
if ( ! V_2 -> V_60 ) {
V_43 = - V_62 ;
goto V_63;
}
F_20 ( V_2 ) ;
F_21 ( V_6 , V_2 ) ;
return V_43 ;
V_63:
F_22 ( V_2 ) ;
F_21 ( V_6 , NULL ) ;
F_4 ( V_2 -> V_7 , L_19 , V_43 ) ;
return V_43 ;
}
static int F_23 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_24 ( V_6 ) ;
F_22 ( V_2 ) ;
F_21 ( V_6 , NULL ) ;
return 0 ;
}
