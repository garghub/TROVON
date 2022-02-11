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
struct V_21 * V_21 ;
V_4 = F_11 ( V_20 , struct V_3 , V_22 ) ;
V_21 = & V_4 -> V_21 ;
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
static void F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
F_17 ( V_30 ) ;
F_18 ( V_4 , V_31 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = & V_2 -> V_10 . V_11 ;
struct V_3 * V_4 ;
int V_8 ;
if ( V_11 -> V_32 ) {
F_20 ( & V_2 -> V_5 , L_1 ,
F_21 ( & V_2 -> V_5 ) ) ;
return - V_33 ;
}
V_4 = F_22 ( sizeof( * V_4 ) , V_34 | V_35 ) ;
if ( ! V_4 )
return - V_36 ;
V_4 -> V_2 = V_2 ;
F_23 ( & V_2 -> V_5 , V_4 ) ;
F_4 ( V_2 -> V_9 ) ;
V_4 -> V_17 = V_18 ;
V_2 -> V_37 = V_38 ;
V_8 = F_24 ( V_2 , ( V_39 ) ( unsigned long ) V_2 ) ;
F_7 ( V_2 -> V_9 ) ;
if ( V_8 )
goto V_40;
V_8 = F_25 ( V_2 ) ;
if ( V_8 )
goto V_41;
F_26 ( & V_4 -> V_22 , F_10 ) ;
F_27 ( & V_4 -> V_42 , 1 ) ;
V_4 -> V_17 = V_43 ;
return 0 ;
V_41:
F_5 ( V_2 ) ;
V_40:
F_23 ( & V_2 -> V_5 , NULL ) ;
F_28 ( V_4 ) ;
return V_8 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
F_1 ( V_2 ) ;
F_30 ( V_2 ) ;
F_23 ( & V_2 -> V_5 , NULL ) ;
F_28 ( V_4 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
}
static int F_32 ( struct V_1 * V_2 , int V_44 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
unsigned long V_45 ;
F_33 ( V_2 -> V_9 , V_45 ) ;
if ( ! F_34 ( & V_2 -> V_5 ) )
goto V_13;
if ( F_35 ( & V_2 -> V_46 ) )
goto V_13;
if ( F_36 ( V_2 ) ) {
F_18 ( V_4 , V_47 ) ;
goto V_13;
}
V_4 = F_2 ( & V_2 -> V_5 ) ;
if ( V_4 -> V_17 == V_18 ) {
V_4 -> V_17 = V_4 -> V_28 ? V_29 :
V_43 ;
}
V_13:
F_37 ( V_2 -> V_9 , V_45 ) ;
return 0 ;
}
static int T_1 F_38 ( void )
{
int V_8 ;
V_16 = F_39 ( L_2 ) ;
if ( ! V_16 )
return - V_36 ;
F_40 ( V_38 ) ;
V_8 = F_41 ( & V_48 ) ;
if ( V_8 ) {
F_42 ( V_38 ) ;
F_43 ( V_16 ) ;
}
return V_8 ;
}
static void T_2 F_44 ( void )
{
F_45 ( & V_48 ) ;
F_42 ( V_38 ) ;
F_43 ( V_16 ) ;
}
