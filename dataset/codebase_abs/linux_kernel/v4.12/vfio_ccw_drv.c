int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
F_3 ( V_6 ) ;
int V_7 , V_8 = 0 ;
F_4 ( V_2 -> V_9 ) ;
if ( ! V_2 -> V_10 . V_11 . V_12 )
goto V_13;
V_8 = F_5 ( V_2 ) ;
if ( V_8 != - V_14 )
goto V_13;
do {
V_7 = 255 ;
V_8 = F_6 ( V_2 , & V_7 ) ;
while ( V_8 == - V_14 ) {
V_4 -> V_6 = & V_6 ;
F_7 ( V_2 -> V_9 ) ;
F_8 ( & V_6 , 3 * V_15 ) ;
F_4 ( V_2 -> V_9 ) ;
V_4 -> V_6 = NULL ;
F_9 ( V_16 ) ;
V_8 = F_6 ( V_2 , & V_7 ) ;
} ;
V_8 = F_5 ( V_2 ) ;
} while ( V_8 == - V_14 );
V_13:
V_4 -> V_17 = V_18 ;
F_7 ( V_2 -> V_9 ) ;
return V_8 ;
}
static void F_10 ( struct V_19 * V_20 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_21 * V_21 ;
V_4 = F_11 ( V_20 , struct V_3 , V_22 ) ;
V_21 = & V_4 -> V_21 ;
V_2 = V_4 -> V_2 ;
if ( F_12 ( & V_21 -> V_23 ) ) {
F_13 ( & V_4 -> V_24 , & V_21 -> V_23 ) ;
F_14 ( & V_4 -> V_24 ) ;
}
memcpy ( V_4 -> V_25 . V_26 , V_21 , sizeof( * V_21 ) ) ;
if ( V_4 -> V_27 )
F_15 ( V_4 -> V_27 , 1 ) ;
if ( V_4 -> V_28 )
V_4 -> V_17 = V_29 ;
}
static T_1 F_16 ( struct V_30 * V_5 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_1 * V_2 = F_17 ( V_5 ) ;
struct V_34 * V_35 = & V_2 -> V_36 ;
T_1 V_8 = 0 ;
int V_37 ;
int V_38 ;
for ( V_37 = 0 ; V_37 < 8 ; V_37 ++ ) {
V_38 = 0x80 >> V_37 ;
if ( V_35 -> V_39 & V_38 )
V_8 += sprintf ( V_33 + V_8 , L_1 , V_35 -> V_40 [ V_37 ] . V_41 ) ;
else
V_8 += sprintf ( V_33 + V_8 , L_2 ) ;
}
V_8 += sprintf ( V_33 + V_8 , L_3 ) ;
return V_8 ;
}
static T_1 F_18 ( struct V_30 * V_5 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_1 * V_2 = F_17 ( V_5 ) ;
struct V_11 * V_11 = & V_2 -> V_10 . V_11 ;
return sprintf ( V_33 , L_4 ,
V_11 -> V_42 , V_11 -> V_43 , V_11 -> V_44 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
F_20 ( V_45 ) ;
F_21 ( V_4 , V_46 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = & V_2 -> V_10 . V_11 ;
struct V_3 * V_4 ;
int V_8 ;
if ( V_11 -> V_47 ) {
F_23 ( & V_2 -> V_5 , L_5 ,
F_24 ( & V_2 -> V_5 ) ) ;
return - V_48 ;
}
V_4 = F_25 ( sizeof( * V_4 ) , V_49 | V_50 ) ;
if ( ! V_4 )
return - V_51 ;
V_4 -> V_2 = V_2 ;
F_26 ( & V_2 -> V_5 , V_4 ) ;
F_4 ( V_2 -> V_9 ) ;
V_4 -> V_17 = V_18 ;
V_2 -> V_52 = V_53 ;
V_8 = F_27 ( V_2 , ( V_54 ) ( unsigned long ) V_2 ) ;
F_7 ( V_2 -> V_9 ) ;
if ( V_8 )
goto V_55;
V_8 = F_28 ( & V_2 -> V_5 . V_56 , & V_57 ) ;
if ( V_8 )
goto V_58;
V_8 = F_29 ( V_2 ) ;
if ( V_8 )
goto V_59;
F_30 ( & V_4 -> V_22 , F_10 ) ;
F_31 ( & V_4 -> V_60 , 1 ) ;
V_4 -> V_17 = V_61 ;
return 0 ;
V_59:
F_32 ( & V_2 -> V_5 . V_56 , & V_57 ) ;
V_58:
F_5 ( V_2 ) ;
V_55:
F_26 ( & V_2 -> V_5 , NULL ) ;
F_33 ( V_4 ) ;
return V_8 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
F_1 ( V_2 ) ;
F_35 ( V_2 ) ;
F_32 ( & V_2 -> V_5 . V_56 , & V_57 ) ;
F_26 ( & V_2 -> V_5 , NULL ) ;
F_33 ( V_4 ) ;
return 0 ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
}
static int F_37 ( struct V_1 * V_2 , int V_62 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
unsigned long V_63 ;
F_38 ( V_2 -> V_9 , V_63 ) ;
if ( ! F_39 ( & V_2 -> V_5 ) )
goto V_13;
if ( F_40 ( & V_2 -> V_64 ) )
goto V_13;
if ( F_41 ( V_2 ) ) {
F_21 ( V_4 , V_65 ) ;
goto V_13;
}
V_4 = F_2 ( & V_2 -> V_5 ) ;
if ( V_4 -> V_17 == V_18 ) {
V_4 -> V_17 = V_4 -> V_28 ? V_29 :
V_61 ;
}
V_13:
F_42 ( V_2 -> V_9 , V_63 ) ;
return 0 ;
}
static int T_2 F_43 ( void )
{
int V_8 ;
V_16 = F_44 ( L_6 ) ;
if ( ! V_16 )
return - V_51 ;
F_45 ( V_53 ) ;
V_8 = F_46 ( & V_66 ) ;
if ( V_8 ) {
F_47 ( V_53 ) ;
F_48 ( V_16 ) ;
}
return V_8 ;
}
static void T_3 F_49 ( void )
{
F_50 ( & V_66 ) ;
F_47 ( V_53 ) ;
F_48 ( V_16 ) ;
}
