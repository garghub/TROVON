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
static T_3 F_13 ( struct V_49 * V_50 ,
struct V_51 * V_4 , int V_52 )
{
struct V_1 * V_2 = F_14 ( V_50 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_13 * V_9 = V_7 -> V_9 ;
T_3 V_53 = V_4 -> V_53 ;
if ( V_4 == & V_54 . V_4 ||
V_4 == & V_55 . V_4 ) {
if ( ! V_9 -> V_25 )
V_53 = 0 ;
} else if ( V_4 == & V_56 . V_4 ) {
if ( ! V_9 -> V_45 )
V_53 = 0 ;
} else if ( V_4 == & V_57 . V_4 ) {
if ( ! V_9 -> V_58 )
V_53 = 0 ;
}
return V_53 ;
}
static int F_15 ( struct V_6 * V_7 , const char * V_10 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_7 -> V_9 -> V_60 ; V_59 ++ ) {
if ( ! strcmp ( V_7 -> V_9 -> V_61 [ V_59 ] . V_10 , V_10 ) )
return V_59 ;
}
return - 1 ;
}
static T_1 F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned int V_62 , V_63 ;
int V_23 ;
V_23 = F_15 ( V_7 , V_4 -> V_4 . V_10 ) ;
if ( V_23 < 0 )
return - V_21 ;
if ( F_5 ( & V_7 -> V_64 ) )
return - V_34 ;
V_62 = V_7 -> V_9 -> V_61 [ V_23 ] . V_62 ;
V_63 = V_7 -> V_9 -> V_61 [ V_23 ] . V_63 ;
F_9 ( & V_7 -> V_64 ) ;
return snprintf ( V_5 , V_8 , L_6 , V_62 , V_63 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_11 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned int V_62 , V_63 ;
int V_18 , V_20 , V_23 ;
V_18 = sscanf ( V_11 , L_7 , & V_62 , & V_63 ) ;
if ( V_18 != 2 )
return - V_21 ;
V_23 = F_15 ( V_7 , V_4 -> V_4 . V_10 ) ;
if ( V_23 < 0 )
return - V_21 ;
if ( F_5 ( & V_7 -> V_64 ) )
return - V_34 ;
V_20 = F_18 ( V_7 , V_23 , V_62 , V_63 ) ;
F_9 ( & V_7 -> V_64 ) ;
if ( V_20 )
return V_20 ;
return V_12 ;
}
int F_19 ( struct V_6 * V_7 )
{
struct V_13 * V_9 = V_7 -> V_9 ;
int V_20 = - V_65 , V_59 , V_60 = V_9 -> V_60 ;
if ( ! V_60 )
return 0 ;
V_7 -> V_66 = F_20 ( V_60 , sizeof( * V_7 -> V_66 ) ,
V_67 ) ;
if ( ! V_7 -> V_66 )
goto V_68;
V_7 -> V_69 = F_20 ( 1 + V_60 , sizeof( * V_7 -> V_69 ) , V_67 ) ;
if ( ! V_7 -> V_69 )
goto V_70;
for ( V_59 = 0 ; V_59 < V_60 ; V_59 ++ ) {
struct V_3 * V_71 = & V_7 -> V_66 [ V_59 ] ;
F_21 ( & V_71 -> V_4 ) ;
V_71 -> V_4 . V_10 = V_9 -> V_61 [ V_59 ] . V_10 ;
V_71 -> V_4 . V_53 = 0644 ;
V_71 -> V_72 = F_16 ;
V_71 -> V_73 = F_17 ;
V_7 -> V_69 [ V_59 ] = & V_71 -> V_4 ;
}
V_7 -> V_74 . V_10 = L_8 ;
V_7 -> V_74 . V_75 = V_7 -> V_69 ;
V_7 -> V_76 [ 0 ] = & V_7 -> V_74 ;
return 0 ;
V_70:
F_22 ( V_7 -> V_66 ) ;
V_68:
return V_20 ;
}
void F_23 ( struct V_6 * V_7 )
{
F_22 ( V_7 -> V_69 ) ;
F_22 ( V_7 -> V_66 ) ;
}
