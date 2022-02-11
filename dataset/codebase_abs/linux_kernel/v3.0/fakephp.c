static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , F_3 ( * V_7 ) , V_2 ) ;
strcpy ( V_5 , L_1 ) ;
return 2 ;
}
static void F_4 ( void * V_8 )
{
F_5 ( (struct V_9 * ) V_8 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 , F_3 ( * V_7 ) , V_2 ) ;
unsigned long V_11 ;
if ( F_7 ( V_5 , 0 , & V_11 ) < 0 )
return - V_12 ;
if ( V_11 )
F_8 ( V_7 -> V_13 -> V_14 ) ;
else
F_9 ( & V_7 -> V_13 -> V_13 . V_2 , F_4 ,
V_7 -> V_13 , V_15 ) ;
return V_10 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 , F_3 ( * V_7 ) , V_2 ) ;
F_11 ( V_7 -> V_13 ) ;
F_12 ( V_7 ) ;
}
static int F_13 ( struct V_9 * V_16 )
{
struct V_6 * V_7 = F_14 ( sizeof( * V_7 ) , V_17 ) ;
if ( ! V_7 )
return - V_18 ;
if ( F_15 ( & V_7 -> V_2 , & V_19 ,
& V_20 -> V_2 , L_2 ,
F_16 ( & V_16 -> V_13 ) ) ) {
F_17 ( & V_16 -> V_13 , L_3 ) ;
return - V_12 ;
}
V_7 -> V_13 = F_18 ( V_16 ) ;
F_19 ( & V_7 -> V_21 , & V_22 ) ;
return 0 ;
}
static int F_20 ( struct V_23 * V_24 ,
unsigned long V_25 , void * V_8 )
{
struct V_9 * V_16 = F_21 ( V_8 ) ;
if ( V_25 == V_26 ) {
F_13 ( V_16 ) ;
} else if ( V_25 == V_27 ) {
struct V_6 * V_7 ;
F_22 (slot, &legacy_list, list)
if ( V_7 -> V_13 == V_16 )
goto V_28;
F_17 ( & V_16 -> V_13 , L_4 ) ;
return - V_29 ;
V_28:
F_23 ( & V_7 -> V_2 ) ;
F_24 ( & V_7 -> V_21 ) ;
F_25 ( & V_7 -> V_2 ) ;
}
return 0 ;
}
static int T_3 F_26 ( void )
{
struct V_9 * V_16 = NULL ;
F_27 (pdev)
F_13 ( V_16 ) ;
F_28 ( & V_30 , & V_31 ) ;
return 0 ;
}
static void T_4 F_29 ( void )
{
struct V_6 * V_7 , * V_32 ;
F_30 ( & V_30 , & V_31 ) ;
F_31 (slot, tmp, &legacy_list, list) {
F_24 ( & V_7 -> V_21 ) ;
F_23 ( & V_7 -> V_2 ) ;
F_25 ( & V_7 -> V_2 ) ;
}
}
