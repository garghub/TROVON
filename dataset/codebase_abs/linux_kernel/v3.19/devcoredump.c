static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
V_5 -> free ( V_5 -> V_6 ) ;
F_4 ( V_5 -> V_7 ) ;
if ( V_5 -> V_8 -> V_9 . V_10 )
F_5 ( & V_5 -> V_8 -> V_9 , & V_3 -> V_9 ,
L_1 ) ;
F_6 ( V_5 -> V_8 ) ;
F_7 ( V_5 ) ;
}
static void F_8 ( struct V_11 * V_12 )
{
struct V_1 * V_5 ;
V_5 = F_2 ( V_12 , struct V_1 , V_13 . V_14 ) ;
F_9 ( & V_5 -> V_4 ) ;
F_6 ( & V_5 -> V_4 ) ;
}
static T_1 F_10 ( struct V_15 * V_16 , struct V_17 * V_9 ,
struct V_18 * V_19 ,
char * V_20 , T_2 V_21 , T_3 V_22 )
{
struct V_2 * V_3 = F_11 ( V_9 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
return V_5 -> V_23 ( V_20 , V_21 , V_22 , V_5 -> V_6 , V_5 -> V_24 ) ;
}
static T_1 F_12 ( struct V_15 * V_16 , struct V_17 * V_9 ,
struct V_18 * V_19 ,
char * V_20 , T_2 V_21 , T_3 V_22 )
{
struct V_2 * V_3 = F_11 ( V_9 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_13 ( V_25 , & V_5 -> V_13 , 0 ) ;
return V_22 ;
}
static int F_14 ( struct V_2 * V_3 , void * V_6 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_15 ( & V_5 -> V_13 ) ;
return 0 ;
}
static T_1 F_16 ( struct V_26 * V_26 , struct V_27 * V_28 ,
char * V_29 )
{
return sprintf ( V_29 , L_2 , V_30 ) ;
}
static T_1 F_17 ( struct V_26 * V_26 , struct V_27 * V_28 ,
const char * V_29 , T_3 V_22 )
{
long V_31 = F_18 ( V_29 , NULL , 10 ) ;
if ( V_31 != 1 )
return - V_32 ;
V_30 = true ;
F_19 ( & V_33 , NULL , NULL , F_14 ) ;
return V_22 ;
}
static T_1 F_20 ( char * V_20 , T_2 V_21 , T_3 V_22 ,
const void * V_6 , T_3 V_24 )
{
if ( V_21 > V_24 )
return - V_32 ;
if ( V_21 + V_22 > V_24 )
V_22 = V_24 - V_21 ;
if ( V_22 )
memcpy ( V_20 , ( ( V_34 * ) V_6 ) + V_21 , V_22 ) ;
return V_22 ;
}
void F_21 ( struct V_2 * V_3 , const void * V_6 , T_3 V_24 ,
T_4 V_35 )
{
F_22 ( V_3 , NULL , V_6 , V_24 , V_35 , F_20 , V_36 ) ;
}
static int F_23 ( struct V_2 * V_3 , const void * V_37 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return V_5 -> V_8 == V_37 ;
}
void F_22 ( struct V_2 * V_3 , struct V_38 * V_7 ,
const void * V_6 , T_3 V_24 , T_4 V_35 ,
T_1 (* V_23)( char * V_20 , T_2 V_21 , T_3 V_22 ,
const void * V_6 , T_3 V_24 ) ,
void (* free)( const void * V_6 ) )
{
static T_5 V_39 = F_24 ( 0 ) ;
struct V_1 * V_5 ;
struct V_2 * V_40 ;
if ( V_30 )
goto free;
V_40 = F_25 ( & V_33 , NULL , V_3 ,
F_23 ) ;
if ( V_40 ) {
F_6 ( V_40 ) ;
goto free;
}
if ( ! F_26 ( V_7 ) )
goto free;
V_5 = F_27 ( sizeof( * V_5 ) , V_35 ) ;
if ( ! V_5 )
goto V_41;
V_5 -> V_7 = V_7 ;
V_5 -> V_6 = V_6 ;
V_5 -> V_24 = V_24 ;
V_5 -> V_23 = V_23 ;
V_5 -> free = free ;
V_5 -> V_8 = F_28 ( V_3 ) ;
F_29 ( & V_5 -> V_4 ) ;
F_30 ( & V_5 -> V_4 , L_3 ,
F_31 ( & V_39 ) ) ;
V_5 -> V_4 . V_26 = & V_33 ;
if ( F_32 ( & V_5 -> V_4 ) )
goto F_6;
if ( F_33 ( & V_5 -> V_4 . V_9 , & V_3 -> V_9 ,
L_4 ) )
;
if ( F_33 ( & V_3 -> V_9 , & V_5 -> V_4 . V_9 ,
L_1 ) )
;
F_34 ( & V_5 -> V_13 , F_8 ) ;
F_35 ( & V_5 -> V_13 , V_42 ) ;
return;
F_6:
F_6 ( & V_5 -> V_4 ) ;
V_41:
F_4 ( V_7 ) ;
free:
free ( V_6 ) ;
}
static int T_6 F_36 ( void )
{
return F_37 ( & V_33 ) ;
}
static void T_7 F_38 ( void )
{
F_19 ( & V_33 , NULL , NULL , F_14 ) ;
F_39 ( & V_33 ) ;
}
