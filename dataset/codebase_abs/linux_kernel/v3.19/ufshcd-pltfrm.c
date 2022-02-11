static struct V_1 * F_1 ( struct V_2 * V_3 )
{
if ( V_3 -> V_4 ) {
const struct V_5 * V_6 ;
V_6 = F_2 ( V_7 , V_3 -> V_4 ) ;
if ( V_6 )
return (struct V_1 * ) V_6 -> V_8 ;
}
return NULL ;
}
static int F_3 ( struct V_9 * V_10 )
{
int V_11 = 0 ;
int V_12 ;
int V_13 ;
struct V_2 * V_3 = V_10 -> V_3 ;
struct V_14 * V_15 = V_3 -> V_4 ;
char * V_16 ;
T_1 * V_17 = NULL ;
struct V_18 * V_19 ;
int V_20 = 0 ;
T_2 V_21 = 0 ;
if ( ! V_15 )
goto V_22;
F_4 ( & V_10 -> V_23 ) ;
V_12 = F_5 ( V_15 , L_1 ) ;
if ( ! V_12 || ( V_12 == - V_24 ) ) {
F_6 ( V_3 , L_2 ,
V_25 ) ;
} else if ( V_12 < 0 ) {
F_7 ( V_3 , L_3 ,
V_25 , V_12 ) ;
V_11 = V_12 ;
}
if ( V_12 <= 0 )
goto V_22;
if ( ! F_8 ( V_15 , L_4 , & V_20 ) ) {
F_6 ( V_3 , L_5 ) ;
goto V_22;
}
if ( V_20 <= 0 )
goto V_22;
V_21 = V_20 / sizeof( * V_17 ) ;
if ( V_21 != 2 * V_12 ) {
F_7 ( V_3 , L_6 , L_4 ) ;
V_11 = - V_24 ;
goto V_22;
}
V_17 = F_9 ( V_3 , V_21 * sizeof( * V_17 ) ,
V_26 ) ;
if ( ! V_17 ) {
V_11 = - V_27 ;
goto V_22;
}
V_11 = F_10 ( V_15 , L_4 ,
V_17 , V_21 ) ;
if ( V_11 && ( V_11 != - V_24 ) ) {
F_7 ( V_3 , L_7 ,
L_4 , V_11 ) ;
return V_11 ;
}
for ( V_13 = 0 ; V_13 < V_21 ; V_13 += 2 ) {
V_11 = F_11 ( V_15 ,
L_1 , V_13 / 2 , ( const char * * ) & V_16 ) ;
if ( V_11 )
goto V_22;
V_19 = F_9 ( V_3 , sizeof( * V_19 ) , V_26 ) ;
if ( ! V_19 ) {
V_11 = - V_27 ;
goto V_22;
}
V_19 -> V_28 = V_17 [ V_13 ] ;
V_19 -> V_29 = V_17 [ V_13 + 1 ] ;
V_19 -> V_16 = F_12 ( V_16 , V_26 ) ;
F_13 ( V_3 , L_8 , L_4 ,
V_19 -> V_28 , V_19 -> V_29 , V_19 -> V_16 ) ;
F_14 ( & V_19 -> V_30 , & V_10 -> V_23 ) ;
}
V_22:
return V_11 ;
}
static int F_15 ( struct V_2 * V_3 , const char * V_16 ,
struct V_31 * * V_32 )
{
int V_11 = 0 ;
char V_33 [ V_34 ] ;
struct V_31 * V_35 = NULL ;
struct V_14 * V_15 = V_3 -> V_4 ;
if ( ! V_15 ) {
F_7 ( V_3 , L_9 , V_25 ) ;
goto V_22;
}
snprintf ( V_33 , V_34 , L_10 , V_16 ) ;
if ( ! F_16 ( V_15 , V_33 , 0 ) ) {
F_6 ( V_3 , L_11 ,
V_25 , V_33 ) ;
goto V_22;
}
V_35 = F_9 ( V_3 , sizeof( * V_35 ) , V_26 ) ;
if ( ! V_35 )
return - V_27 ;
V_35 -> V_16 = F_12 ( V_16 , V_26 ) ;
snprintf ( V_33 , V_34 , L_12 , V_16 ) ;
if ( F_17 ( V_15 , V_33 ) )
goto V_22;
snprintf ( V_33 , V_34 , L_13 , V_16 ) ;
V_11 = F_18 ( V_15 , V_33 , & V_35 -> V_36 ) ;
if ( V_11 ) {
F_7 ( V_3 , L_14 ,
V_25 , V_33 , V_11 ) ;
goto V_37;
}
V_35 -> V_38 = 0 ;
if ( ! strcmp ( V_16 , L_15 ) ) {
if ( F_17 ( V_15 , L_16 ) ) {
V_35 -> V_39 = V_40 ;
V_35 -> V_41 = V_42 ;
} else {
V_35 -> V_39 = V_43 ;
V_35 -> V_41 = V_44 ;
}
} else if ( ! strcmp ( V_16 , L_17 ) ) {
V_35 -> V_39 = V_45 ;
V_35 -> V_41 = V_46 ;
} else if ( ! strcmp ( V_16 , L_18 ) ) {
V_35 -> V_39 = V_47 ;
V_35 -> V_41 = V_48 ;
}
goto V_22;
V_37:
F_19 ( V_3 , V_35 ) ;
V_35 = NULL ;
V_22:
if ( ! V_11 )
* V_32 = V_35 ;
return V_11 ;
}
static int F_20 ( struct V_9 * V_10 )
{
int V_49 ;
struct V_2 * V_3 = V_10 -> V_3 ;
struct V_50 * V_51 = & V_10 -> V_52 ;
V_49 = F_15 ( V_3 , L_19 , & V_51 -> V_53 ) ;
if ( V_49 )
goto V_22;
V_49 = F_15 ( V_3 , L_15 , & V_51 -> V_54 ) ;
if ( V_49 )
goto V_22;
V_49 = F_15 ( V_3 , L_17 , & V_51 -> V_55 ) ;
if ( V_49 )
goto V_22;
V_49 = F_15 ( V_3 , L_18 , & V_51 -> V_56 ) ;
V_22:
return V_49 ;
}
static int F_21 ( struct V_2 * V_3 )
{
return F_22 ( F_23 ( V_3 ) ) ;
}
static int F_24 ( struct V_2 * V_3 )
{
return F_25 ( F_23 ( V_3 ) ) ;
}
static int F_26 ( struct V_2 * V_3 )
{
return F_27 ( F_23 ( V_3 ) ) ;
}
static int F_28 ( struct V_2 * V_3 )
{
return F_29 ( F_23 ( V_3 ) ) ;
}
static int F_30 ( struct V_2 * V_3 )
{
return F_31 ( F_23 ( V_3 ) ) ;
}
static void F_32 ( struct V_57 * V_58 )
{
F_33 ( (struct V_9 * ) F_34 ( V_58 ) ) ;
}
static int F_35 ( struct V_57 * V_58 )
{
struct V_9 * V_10 ;
void T_3 * V_59 ;
struct V_60 * V_61 ;
int V_62 , V_49 ;
struct V_2 * V_3 = & V_58 -> V_3 ;
V_61 = F_36 ( V_58 , V_63 , 0 ) ;
V_59 = F_37 ( V_3 , V_61 ) ;
if ( F_38 ( * ( void * * ) & V_59 ) ) {
V_49 = F_39 ( * ( void * * ) & V_59 ) ;
goto V_22;
}
V_62 = F_40 ( V_58 , 0 ) ;
if ( V_62 < 0 ) {
F_7 ( V_3 , L_20 ) ;
V_49 = - V_64 ;
goto V_22;
}
V_49 = F_41 ( V_3 , & V_10 ) ;
if ( V_49 ) {
F_7 ( & V_58 -> V_3 , L_21 ) ;
goto V_22;
}
V_10 -> V_65 = F_1 ( & V_58 -> V_3 ) ;
V_49 = F_3 ( V_10 ) ;
if ( V_49 ) {
F_7 ( & V_58 -> V_3 , L_22 ,
V_25 , V_49 ) ;
goto V_22;
}
V_49 = F_20 ( V_10 ) ;
if ( V_49 ) {
F_7 ( & V_58 -> V_3 , L_23 ,
V_25 , V_49 ) ;
goto V_22;
}
F_42 ( & V_58 -> V_3 ) ;
F_43 ( & V_58 -> V_3 ) ;
V_49 = F_44 ( V_10 , V_59 , V_62 ) ;
if ( V_49 ) {
F_7 ( V_3 , L_24 ) ;
goto V_66;
}
F_45 ( V_58 , V_10 ) ;
return 0 ;
V_66:
F_46 ( & V_58 -> V_3 ) ;
F_47 ( & V_58 -> V_3 ) ;
V_22:
return V_49 ;
}
static int F_48 ( struct V_57 * V_58 )
{
struct V_9 * V_10 = F_34 ( V_58 ) ;
F_49 ( & ( V_58 ) -> V_3 ) ;
F_50 ( V_10 ) ;
return 0 ;
}
