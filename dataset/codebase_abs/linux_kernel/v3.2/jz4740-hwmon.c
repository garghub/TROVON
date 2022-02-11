static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_1 ) ;
}
static T_2 F_2 ( int V_6 , void * V_7 )
{
struct V_8 * V_9 = V_7 ;
F_3 ( & V_9 -> V_10 ) ;
return V_11 ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_12 * V_12 = & V_9 -> V_10 ;
long V_13 ;
unsigned long V_14 ;
int V_15 ;
F_6 ( & V_9 -> V_16 ) ;
F_7 ( * V_12 ) ;
F_8 ( V_9 -> V_6 ) ;
V_9 -> V_17 -> V_18 ( F_9 ( V_2 ) ) ;
V_13 = F_10 ( V_12 , V_19 ) ;
if ( V_13 > 0 ) {
V_14 = F_11 ( V_9 -> V_20 ) & 0xfff ;
V_14 = ( V_14 * 3300 ) >> 12 ;
V_15 = sprintf ( V_5 , L_2 , V_14 ) ;
} else {
V_15 = V_13 ? V_13 : - V_21 ;
}
V_9 -> V_17 -> V_22 ( F_9 ( V_2 ) ) ;
F_12 ( V_9 -> V_6 ) ;
F_13 ( & V_9 -> V_16 ) ;
return V_15 ;
}
static int T_3 F_14 ( struct V_23 * V_24 )
{
int V_15 ;
struct V_8 * V_9 ;
V_9 = F_15 ( sizeof( * V_9 ) , V_25 ) ;
if ( ! V_9 ) {
F_16 ( & V_24 -> V_2 , L_3 ) ;
return - V_26 ;
}
V_9 -> V_17 = F_17 ( V_24 ) ;
V_9 -> V_6 = F_18 ( V_24 , 0 ) ;
if ( V_9 -> V_6 < 0 ) {
V_15 = V_9 -> V_6 ;
F_16 ( & V_24 -> V_2 , L_4 , V_15 ) ;
goto V_27;
}
V_9 -> V_28 = F_19 ( V_24 , V_29 , 0 ) ;
if ( ! V_9 -> V_28 ) {
V_15 = - V_30 ;
F_16 ( & V_24 -> V_2 , L_5 ) ;
goto V_27;
}
V_9 -> V_28 = F_20 ( V_9 -> V_28 -> V_31 ,
F_21 ( V_9 -> V_28 ) , V_24 -> V_32 ) ;
if ( ! V_9 -> V_28 ) {
V_15 = - V_33 ;
F_16 ( & V_24 -> V_2 , L_6 ) ;
goto V_27;
}
V_9 -> V_20 = F_22 ( V_9 -> V_28 -> V_31 ,
F_21 ( V_9 -> V_28 ) ) ;
if ( ! V_9 -> V_20 ) {
V_15 = - V_33 ;
F_16 ( & V_24 -> V_2 , L_7 ) ;
goto V_34;
}
F_23 ( & V_9 -> V_10 ) ;
F_24 ( & V_9 -> V_16 ) ;
F_25 ( V_24 , V_9 ) ;
V_15 = F_26 ( V_9 -> V_6 , F_2 , 0 , V_24 -> V_32 , V_9 ) ;
if ( V_15 ) {
F_16 ( & V_24 -> V_2 , L_8 , V_15 ) ;
goto V_35;
}
F_12 ( V_9 -> V_6 ) ;
V_15 = F_27 ( & V_24 -> V_2 . V_36 , & V_37 ) ;
if ( V_15 ) {
F_16 ( & V_24 -> V_2 , L_9 , V_15 ) ;
goto V_38;
}
V_9 -> V_9 = F_28 ( & V_24 -> V_2 ) ;
if ( F_29 ( V_9 -> V_9 ) ) {
V_15 = F_30 ( V_9 -> V_9 ) ;
goto V_39;
}
return 0 ;
V_39:
F_31 ( & V_24 -> V_2 . V_36 , & V_37 ) ;
V_38:
F_32 ( V_9 -> V_6 , V_9 ) ;
V_35:
F_25 ( V_24 , NULL ) ;
F_33 ( V_9 -> V_20 ) ;
V_34:
F_34 ( V_9 -> V_28 -> V_31 , F_21 ( V_9 -> V_28 ) ) ;
V_27:
F_35 ( V_9 ) ;
return V_15 ;
}
static int T_4 F_36 ( struct V_23 * V_24 )
{
struct V_8 * V_9 = F_37 ( V_24 ) ;
F_38 ( V_9 -> V_9 ) ;
F_31 ( & V_24 -> V_2 . V_36 , & V_37 ) ;
F_32 ( V_9 -> V_6 , V_9 ) ;
F_33 ( V_9 -> V_20 ) ;
F_34 ( V_9 -> V_28 -> V_31 , F_21 ( V_9 -> V_28 ) ) ;
F_25 ( V_24 , NULL ) ;
F_35 ( V_9 ) ;
return 0 ;
}
