static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return snprintf ( V_5 , V_8 - 1 , L_1 , V_7 -> V_9 -> V_10 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_11 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_13 * V_14 = V_7 -> V_9 ;
struct V_15 V_16 = { . type = V_17 } ;
int V_18 , V_19 ;
int V_20 = - V_21 ;
V_18 = sscanf ( V_11 , L_2 , & V_16 . V_22 . V_23 , & V_19 ) ;
if ( V_18 != 2 )
goto V_24;
if ( V_16 . V_22 . V_23 >= V_14 -> V_25 )
goto V_24;
V_20 = V_14 -> V_19 ( V_14 , & V_16 , V_19 ? 1 : 0 ) ;
if ( V_20 )
goto V_24;
return V_12 ;
V_24:
return V_20 ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_26 * V_27 = & V_7 -> V_28 ;
struct V_29 V_30 ;
unsigned long V_31 ;
T_2 V_32 ;
int V_18 = 0 ;
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
if ( F_5 ( & V_7 -> V_33 ) )
return - V_34 ;
F_6 ( & V_27 -> V_35 , V_31 ) ;
V_32 = F_7 ( V_27 ) ;
if ( V_32 ) {
V_30 = V_27 -> V_11 [ V_27 -> V_36 ] ;
V_27 -> V_36 = ( V_27 -> V_36 + 1 ) % V_37 ;
}
F_8 ( & V_27 -> V_35 , V_31 ) ;
if ( ! V_32 )
goto V_24;
V_18 = snprintf ( V_5 , V_8 , L_3 ,
V_30 . V_23 , V_30 . V_38 . V_39 , V_30 . V_38 . V_40 ) ;
V_24:
F_9 ( & V_7 -> V_33 ) ;
return V_18 ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_11 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_13 * V_14 = V_7 -> V_9 ;
struct V_15 V_16 = { . type = V_41 } ;
int V_18 , V_19 , V_20 = - V_21 ;
V_18 = sscanf ( V_11 , L_4 , & V_16 . V_42 . V_23 ,
& V_16 . V_42 . V_43 . V_39 , & V_16 . V_42 . V_43 . V_40 ,
& V_16 . V_42 . V_44 . V_39 , & V_16 . V_42 . V_44 . V_40 ) ;
if ( V_18 != 5 )
goto V_24;
if ( V_16 . V_42 . V_23 >= V_14 -> V_45 )
goto V_24;
V_19 = V_16 . V_42 . V_44 . V_39 || V_16 . V_42 . V_44 . V_40 ;
V_20 = V_14 -> V_19 ( V_14 , & V_16 , V_19 ) ;
if ( V_20 )
goto V_24;
return V_12 ;
V_24:
return V_20 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_11 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_13 * V_14 = V_7 -> V_9 ;
struct V_15 V_16 = { . type = V_46 } ;
int V_18 , V_19 ;
int V_20 = - V_21 ;
if ( ! F_12 ( V_47 ) )
return - V_48 ;
V_18 = sscanf ( V_11 , L_5 , & V_19 ) ;
if ( V_18 != 1 )
goto V_24;
V_20 = V_14 -> V_19 ( V_14 , & V_16 , V_19 ? 1 : 0 ) ;
if ( V_20 )
goto V_24;
return V_12 ;
V_24:
return V_20 ;
}
int F_13 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_13 * V_9 = V_7 -> V_9 ;
if ( V_9 -> V_25 ) {
F_14 ( V_2 , & V_49 ) ;
F_14 ( V_2 , & V_50 ) ;
}
if ( V_9 -> V_45 )
F_14 ( V_2 , & V_51 ) ;
if ( V_9 -> V_52 )
F_14 ( V_2 , & V_53 ) ;
return 0 ;
}
int F_15 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_13 * V_9 = V_7 -> V_9 ;
int V_20 ;
if ( V_9 -> V_25 ) {
V_20 = F_16 ( V_2 , & V_49 ) ;
if ( V_20 )
goto V_54;
V_20 = F_16 ( V_2 , & V_50 ) ;
if ( V_20 )
goto V_55;
}
if ( V_9 -> V_45 ) {
V_20 = F_16 ( V_2 , & V_51 ) ;
if ( V_20 )
goto V_56;
}
if ( V_9 -> V_52 ) {
V_20 = F_16 ( V_2 , & V_53 ) ;
if ( V_20 )
goto V_57;
}
return 0 ;
V_57:
if ( V_9 -> V_45 )
F_14 ( V_2 , & V_51 ) ;
V_56:
if ( V_9 -> V_25 )
F_14 ( V_2 , & V_50 ) ;
V_55:
if ( V_9 -> V_25 )
F_14 ( V_2 , & V_49 ) ;
V_54:
return V_20 ;
}
