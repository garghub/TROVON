static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
int V_4 ;
int V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
char * V_11 ;
T_1 * V_12 = NULL ;
struct V_13 * V_14 ;
int V_15 = 0 ;
T_2 V_16 = 0 ;
if ( ! V_9 )
goto V_17;
F_2 ( & V_2 -> V_18 ) ;
V_4 = F_3 ( V_9 , L_1 ) ;
if ( ! V_4 || ( V_4 == - V_19 ) ) {
F_4 ( V_7 , L_2 ,
V_20 ) ;
} else if ( V_4 < 0 ) {
F_5 ( V_7 , L_3 ,
V_20 , V_4 ) ;
V_3 = V_4 ;
}
if ( V_4 <= 0 )
goto V_17;
if ( ! F_6 ( V_9 , L_4 , & V_15 ) ) {
F_4 ( V_7 , L_5 ) ;
goto V_17;
}
if ( V_15 <= 0 )
goto V_17;
V_16 = V_15 / sizeof( * V_12 ) ;
if ( V_16 != 2 * V_4 ) {
F_5 ( V_7 , L_6 , L_4 ) ;
V_3 = - V_19 ;
goto V_17;
}
V_12 = F_7 ( V_7 , V_16 * sizeof( * V_12 ) ,
V_21 ) ;
if ( ! V_12 ) {
V_3 = - V_22 ;
goto V_17;
}
V_3 = F_8 ( V_9 , L_4 ,
V_12 , V_16 ) ;
if ( V_3 && ( V_3 != - V_19 ) ) {
F_5 ( V_7 , L_7 ,
L_4 , V_3 ) ;
return V_3 ;
}
for ( V_5 = 0 ; V_5 < V_16 ; V_5 += 2 ) {
V_3 = F_9 ( V_9 ,
L_1 , V_5 / 2 , ( const char * * ) & V_11 ) ;
if ( V_3 )
goto V_17;
V_14 = F_7 ( V_7 , sizeof( * V_14 ) , V_21 ) ;
if ( ! V_14 ) {
V_3 = - V_22 ;
goto V_17;
}
V_14 -> V_23 = V_12 [ V_5 ] ;
V_14 -> V_24 = V_12 [ V_5 + 1 ] ;
V_14 -> V_11 = F_10 ( V_11 , V_21 ) ;
F_11 ( V_7 , L_8 , L_4 ,
V_14 -> V_23 , V_14 -> V_24 , V_14 -> V_11 ) ;
F_12 ( & V_14 -> V_25 , & V_2 -> V_18 ) ;
}
V_17:
return V_3 ;
}
static int F_13 ( struct V_6 * V_7 , const char * V_11 ,
struct V_26 * * V_27 )
{
int V_3 = 0 ;
char V_28 [ V_29 ] ;
struct V_26 * V_30 = NULL ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( ! V_9 ) {
F_5 ( V_7 , L_9 , V_20 ) ;
goto V_17;
}
snprintf ( V_28 , V_29 , L_10 , V_11 ) ;
if ( ! F_14 ( V_9 , V_28 , 0 ) ) {
F_4 ( V_7 , L_11 ,
V_20 , V_28 ) ;
goto V_17;
}
V_30 = F_7 ( V_7 , sizeof( * V_30 ) , V_21 ) ;
if ( ! V_30 )
return - V_22 ;
V_30 -> V_11 = F_10 ( V_11 , V_21 ) ;
snprintf ( V_28 , V_29 , L_12 , V_11 ) ;
if ( F_15 ( V_9 , V_28 ) )
goto V_17;
snprintf ( V_28 , V_29 , L_13 , V_11 ) ;
V_3 = F_16 ( V_9 , V_28 , & V_30 -> V_31 ) ;
if ( V_3 ) {
F_5 ( V_7 , L_14 ,
V_20 , V_28 , V_3 ) ;
goto V_17;
}
V_30 -> V_32 = 0 ;
if ( ! strcmp ( V_11 , L_15 ) ) {
if ( F_15 ( V_9 , L_16 ) ) {
V_30 -> V_33 = V_34 ;
V_30 -> V_35 = V_36 ;
} else {
V_30 -> V_33 = V_37 ;
V_30 -> V_35 = V_38 ;
}
} else if ( ! strcmp ( V_11 , L_17 ) ) {
V_30 -> V_33 = V_39 ;
V_30 -> V_35 = V_40 ;
} else if ( ! strcmp ( V_11 , L_18 ) ) {
V_30 -> V_33 = V_41 ;
V_30 -> V_35 = V_42 ;
}
goto V_17;
V_17:
if ( ! V_3 )
* V_27 = V_30 ;
return V_3 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_43 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_44 * V_45 = & V_2 -> V_46 ;
V_43 = F_13 ( V_7 , L_19 , & V_45 -> V_47 ) ;
if ( V_43 )
goto V_17;
V_43 = F_13 ( V_7 , L_15 , & V_45 -> V_48 ) ;
if ( V_43 )
goto V_17;
V_43 = F_13 ( V_7 , L_17 , & V_45 -> V_49 ) ;
if ( V_43 )
goto V_17;
V_43 = F_13 ( V_7 , L_18 , & V_45 -> V_50 ) ;
V_17:
return V_43 ;
}
int F_18 ( struct V_6 * V_7 )
{
return F_19 ( F_20 ( V_7 ) ) ;
}
int F_21 ( struct V_6 * V_7 )
{
return F_22 ( F_20 ( V_7 ) ) ;
}
int F_23 ( struct V_6 * V_7 )
{
return F_24 ( F_20 ( V_7 ) ) ;
}
int F_25 ( struct V_6 * V_7 )
{
return F_26 ( F_20 ( V_7 ) ) ;
}
int F_27 ( struct V_6 * V_7 )
{
return F_28 ( F_20 ( V_7 ) ) ;
}
void F_29 ( struct V_51 * V_52 )
{
F_30 ( (struct V_1 * ) F_31 ( V_52 ) ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_3 ;
V_3 = F_16 ( V_7 -> V_10 , L_20 ,
& V_2 -> V_53 ) ;
if ( V_3 ) {
F_11 ( V_2 -> V_7 ,
L_21 ,
V_20 , V_3 ) ;
V_2 -> V_53 = V_54 ;
}
}
int F_33 ( struct V_51 * V_52 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 ;
void T_3 * V_57 ;
struct V_58 * V_59 ;
int V_60 , V_43 ;
struct V_6 * V_7 = & V_52 -> V_7 ;
V_59 = F_34 ( V_52 , V_61 , 0 ) ;
V_57 = F_35 ( V_7 , V_59 ) ;
if ( F_36 ( V_57 ) ) {
V_43 = F_37 ( V_57 ) ;
goto V_17;
}
V_60 = F_38 ( V_52 , 0 ) ;
if ( V_60 < 0 ) {
F_5 ( V_7 , L_22 ) ;
V_43 = - V_62 ;
goto V_17;
}
V_43 = F_39 ( V_7 , & V_2 ) ;
if ( V_43 ) {
F_5 ( & V_52 -> V_7 , L_23 ) ;
goto V_17;
}
V_2 -> V_56 = V_56 ;
V_43 = F_1 ( V_2 ) ;
if ( V_43 ) {
F_5 ( & V_52 -> V_7 , L_24 ,
V_20 , V_43 ) ;
goto V_63;
}
V_43 = F_17 ( V_2 ) ;
if ( V_43 ) {
F_5 ( & V_52 -> V_7 , L_25 ,
V_20 , V_43 ) ;
goto V_63;
}
F_40 ( & V_52 -> V_7 ) ;
F_41 ( & V_52 -> V_7 ) ;
F_32 ( V_2 ) ;
V_43 = F_42 ( V_2 , V_57 , V_60 ) ;
if ( V_43 ) {
F_5 ( V_7 , L_26 ) ;
goto V_64;
}
F_43 ( V_52 , V_2 ) ;
return 0 ;
V_64:
F_44 ( & V_52 -> V_7 ) ;
F_45 ( & V_52 -> V_7 ) ;
V_63:
F_46 ( V_2 ) ;
V_17:
return V_43 ;
}
