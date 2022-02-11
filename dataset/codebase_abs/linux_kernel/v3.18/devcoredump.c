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
static T_1 F_14 ( char * V_20 , T_2 V_21 , T_3 V_22 ,
const void * V_6 , T_3 V_24 )
{
if ( V_21 > V_24 )
return - V_26 ;
if ( V_21 + V_22 > V_24 )
V_22 = V_24 - V_21 ;
if ( V_22 )
memcpy ( V_20 , ( ( V_27 * ) V_6 ) + V_21 , V_22 ) ;
return V_22 ;
}
void F_15 ( struct V_2 * V_3 , const void * V_6 , T_3 V_24 ,
T_4 V_28 )
{
F_16 ( V_3 , NULL , V_6 , V_24 , V_28 , F_14 , V_29 ) ;
}
static int F_17 ( struct V_2 * V_3 , const void * V_30 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return V_5 -> V_8 == V_30 ;
}
void F_16 ( struct V_2 * V_3 , struct V_31 * V_7 ,
const void * V_6 , T_3 V_24 , T_4 V_28 ,
T_1 (* V_23)( char * V_20 , T_2 V_21 , T_3 V_22 ,
const void * V_6 , T_3 V_24 ) ,
void (* free)( const void * V_6 ) )
{
static T_5 V_32 = F_18 ( 0 ) ;
struct V_1 * V_5 ;
struct V_2 * V_33 ;
V_33 = F_19 ( & V_34 , NULL , V_3 ,
F_17 ) ;
if ( V_33 ) {
F_6 ( V_33 ) ;
goto free;
}
if ( ! F_20 ( V_7 ) )
goto free;
V_5 = F_21 ( sizeof( * V_5 ) , V_28 ) ;
if ( ! V_5 )
goto V_35;
V_5 -> V_7 = V_7 ;
V_5 -> V_6 = V_6 ;
V_5 -> V_24 = V_24 ;
V_5 -> V_23 = V_23 ;
V_5 -> free = free ;
V_5 -> V_8 = F_22 ( V_3 ) ;
F_23 ( & V_5 -> V_4 ) ;
F_24 ( & V_5 -> V_4 , L_2 ,
F_25 ( & V_32 ) ) ;
V_5 -> V_4 . V_36 = & V_34 ;
if ( F_26 ( & V_5 -> V_4 ) )
goto F_6;
if ( F_27 ( & V_5 -> V_4 . V_9 , & V_3 -> V_9 ,
L_3 ) )
;
if ( F_27 ( & V_3 -> V_9 , & V_5 -> V_4 . V_9 ,
L_1 ) )
;
F_28 ( & V_5 -> V_13 , F_8 ) ;
F_29 ( & V_5 -> V_13 , V_37 ) ;
return;
F_6:
F_6 ( & V_5 -> V_4 ) ;
V_35:
F_4 ( V_7 ) ;
free:
free ( V_6 ) ;
}
static int T_6 F_30 ( void )
{
return F_31 ( & V_34 ) ;
}
static int F_32 ( struct V_2 * V_3 , void * V_6 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_33 ( & V_5 -> V_13 ) ;
return 0 ;
}
static void T_7 F_34 ( void )
{
F_35 ( & V_34 , NULL , NULL , F_32 ) ;
F_36 ( & V_34 ) ;
}
