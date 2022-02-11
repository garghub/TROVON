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
static int F_13 ( struct V_6 * V_7 , const char * V_10 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_7 -> V_9 -> V_50 ; V_49 ++ ) {
if ( ! strcmp ( V_7 -> V_9 -> V_51 [ V_49 ] . V_10 , V_10 ) )
return V_49 ;
}
return - 1 ;
}
static T_1 F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned int V_52 , V_53 ;
int V_23 ;
V_23 = F_13 ( V_7 , V_4 -> V_4 . V_10 ) ;
if ( V_23 < 0 )
return - V_21 ;
if ( F_5 ( & V_7 -> V_54 ) )
return - V_34 ;
V_52 = V_7 -> V_9 -> V_51 [ V_23 ] . V_52 ;
V_53 = V_7 -> V_9 -> V_51 [ V_23 ] . V_53 ;
F_9 ( & V_7 -> V_54 ) ;
return snprintf ( V_5 , V_8 , L_6 , V_52 , V_53 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_11 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned int V_52 , V_53 ;
int V_18 , V_20 , V_23 ;
V_18 = sscanf ( V_11 , L_7 , & V_52 , & V_53 ) ;
if ( V_18 != 2 )
return - V_21 ;
V_23 = F_13 ( V_7 , V_4 -> V_4 . V_10 ) ;
if ( V_23 < 0 )
return - V_21 ;
if ( F_5 ( & V_7 -> V_54 ) )
return - V_34 ;
V_20 = F_16 ( V_7 , V_23 , V_52 , V_53 ) ;
F_9 ( & V_7 -> V_54 ) ;
if ( V_20 )
return V_20 ;
return V_12 ;
}
int F_17 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_13 * V_9 = V_7 -> V_9 ;
if ( V_9 -> V_25 ) {
F_18 ( V_2 , & V_55 ) ;
F_18 ( V_2 , & V_56 ) ;
}
if ( V_9 -> V_45 )
F_18 ( V_2 , & V_57 ) ;
if ( V_9 -> V_58 )
F_18 ( V_2 , & V_59 ) ;
if ( V_9 -> V_50 ) {
F_19 ( & V_2 -> V_60 , & V_7 -> V_61 ) ;
F_20 ( V_7 -> V_62 ) ;
F_20 ( V_7 -> V_63 ) ;
}
return 0 ;
}
static int F_21 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_13 * V_9 = V_7 -> V_9 ;
int V_20 = - V_64 , V_49 , V_50 = V_9 -> V_50 ;
V_7 -> V_63 = F_22 ( V_50 * sizeof( * V_7 -> V_63 ) ,
V_65 ) ;
if ( ! V_7 -> V_63 )
goto V_66;
V_7 -> V_62 = F_22 ( ( 1 + V_50 ) * sizeof( struct V_67 * ) ,
V_65 ) ;
if ( ! V_7 -> V_62 )
goto V_68;
for ( V_49 = 0 ; V_49 < V_50 ; V_49 ++ ) {
struct V_3 * V_69 = & V_7 -> V_63 [ V_49 ] ;
F_23 ( & V_69 -> V_4 ) ;
V_69 -> V_4 . V_10 = V_9 -> V_51 [ V_49 ] . V_10 ;
V_69 -> V_4 . V_70 = 0644 ;
V_69 -> V_71 = F_14 ;
V_69 -> V_72 = F_15 ;
V_7 -> V_62 [ V_49 ] = & V_69 -> V_4 ;
}
V_7 -> V_61 . V_10 = L_8 ;
V_7 -> V_61 . V_73 = V_7 -> V_62 ;
V_20 = F_24 ( & V_2 -> V_60 , & V_7 -> V_61 ) ;
if ( V_20 )
goto V_74;
return 0 ;
V_74:
F_20 ( V_7 -> V_62 ) ;
V_68:
F_20 ( V_7 -> V_63 ) ;
V_66:
return V_20 ;
}
int F_25 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_13 * V_9 = V_7 -> V_9 ;
int V_20 ;
if ( V_9 -> V_25 ) {
V_20 = F_26 ( V_2 , & V_55 ) ;
if ( V_20 )
goto V_75;
V_20 = F_26 ( V_2 , & V_56 ) ;
if ( V_20 )
goto V_76;
}
if ( V_9 -> V_45 ) {
V_20 = F_26 ( V_2 , & V_57 ) ;
if ( V_20 )
goto V_77;
}
if ( V_9 -> V_58 ) {
V_20 = F_26 ( V_2 , & V_59 ) ;
if ( V_20 )
goto V_78;
}
if ( V_9 -> V_50 ) {
V_20 = F_21 ( V_7 ) ;
if ( V_20 )
goto V_79;
}
return 0 ;
V_79:
if ( V_9 -> V_58 )
F_18 ( V_2 , & V_59 ) ;
V_78:
if ( V_9 -> V_45 )
F_18 ( V_2 , & V_57 ) ;
V_77:
if ( V_9 -> V_25 )
F_18 ( V_2 , & V_56 ) ;
V_76:
if ( V_9 -> V_25 )
F_18 ( V_2 , & V_55 ) ;
V_75:
return V_20 ;
}
