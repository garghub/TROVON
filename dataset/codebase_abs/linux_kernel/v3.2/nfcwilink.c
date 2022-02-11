static void F_1 ( void * V_1 , char V_2 )
{
struct V_3 * V_4 = V_1 ;
F_2 ( & V_4 -> V_5 -> V_6 , L_1 ) ;
V_4 -> V_7 = V_2 ;
F_3 ( & V_4 -> V_8 ) ;
}
static long F_4 ( void * V_1 , struct V_9 * V_10 )
{
struct V_3 * V_4 = V_1 ;
int V_11 ;
F_2 ( & V_4 -> V_5 -> V_6 , L_2 , V_10 -> V_12 ) ;
if ( ! V_10 )
return - V_13 ;
if ( ! V_4 ) {
F_5 ( V_10 ) ;
return - V_13 ;
}
F_6 ( V_10 , ( V_14 - 1 ) ) ;
V_10 -> V_6 = ( void * ) V_4 -> V_15 ;
V_11 = F_7 ( V_10 ) ;
if ( V_11 < 0 ) {
F_8 ( & V_4 -> V_5 -> V_6 , L_3 , V_11 ) ;
return V_11 ;
}
return 0 ;
}
static int F_9 ( struct V_16 * V_15 )
{
struct V_3 * V_4 = F_10 ( V_15 ) ;
unsigned long V_17 ;
int V_11 ;
F_2 ( & V_4 -> V_5 -> V_6 , L_4 ) ;
if ( F_11 ( V_18 , & V_4 -> V_19 ) ) {
V_11 = - V_20 ;
goto exit;
}
V_21 . V_1 = V_4 ;
F_12 ( & V_4 -> V_8 ) ;
V_4 -> V_7 = - V_22 ;
V_11 = F_13 ( & V_21 ) ;
if ( V_11 < 0 ) {
if ( V_11 == - V_22 ) {
V_17 = F_14 (
& V_4 -> V_8 ,
F_15 ( V_23 ) ) ;
F_2 ( & V_4 -> V_5 -> V_6 ,
L_5 ,
V_17 ) ;
if ( V_17 == 0 ) {
V_11 = - V_24 ;
goto V_25;
} else if ( V_4 -> V_7 != 0 ) {
V_11 = V_4 -> V_7 ;
F_8 ( & V_4 -> V_5 -> V_6 ,
L_6 , V_11 ) ;
goto V_25;
}
} else {
F_8 ( & V_4 -> V_5 -> V_6 ,
L_7 , V_11 ) ;
goto V_25;
}
}
F_16 ( V_21 . V_26 == NULL ) ;
V_4 -> V_27 = V_21 . V_26 ;
goto exit;
V_25:
F_17 ( V_18 , & V_4 -> V_19 ) ;
exit:
return V_11 ;
}
static int F_18 ( struct V_16 * V_15 )
{
struct V_3 * V_4 = F_10 ( V_15 ) ;
int V_11 ;
F_2 ( & V_4 -> V_5 -> V_6 , L_8 ) ;
if ( ! F_19 ( V_18 , & V_4 -> V_19 ) )
return 0 ;
V_11 = F_20 ( & V_21 ) ;
if ( V_11 )
F_8 ( & V_4 -> V_5 -> V_6 , L_9 , V_11 ) ;
V_4 -> V_27 = NULL ;
return V_11 ;
}
static int F_21 ( struct V_9 * V_10 )
{
struct V_16 * V_15 = (struct V_16 * ) V_10 -> V_6 ;
struct V_3 * V_4 = F_10 ( V_15 ) ;
struct V_28 V_29 = { V_30 , V_31 , 0x0000 } ;
long V_12 ;
F_2 ( & V_4 -> V_5 -> V_6 , L_10 , V_10 -> V_12 ) ;
if ( ! F_22 ( V_18 , & V_4 -> V_19 ) )
return - V_20 ;
V_29 . V_12 = V_10 -> V_12 ;
memcpy ( F_23 ( V_10 , V_14 ) , & V_29 , V_14 ) ;
V_12 = V_4 -> V_27 ( V_10 ) ;
if ( V_12 < 0 ) {
F_5 ( V_10 ) ;
F_8 ( & V_4 -> V_5 -> V_6 , L_11 , V_12 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_24 ( struct V_32 * V_5 )
{
static struct V_3 * V_4 ;
int V_11 ;
T_1 V_33 ;
F_2 ( & V_5 -> V_6 , L_12 ) ;
V_4 = F_25 ( sizeof( struct V_3 ) , V_34 ) ;
if ( ! V_4 ) {
V_11 = - V_35 ;
goto exit;
}
V_4 -> V_5 = V_5 ;
V_33 = V_36
| V_37 | V_38
| V_39
| V_40 ;
V_4 -> V_15 = F_26 ( & V_41 ,
V_33 ,
V_14 ,
0 ) ;
if ( ! V_4 -> V_15 ) {
F_8 ( & V_5 -> V_6 , L_13 ) ;
V_11 = - V_35 ;
goto V_42;
}
F_27 ( V_4 -> V_15 , & V_5 -> V_6 ) ;
F_28 ( V_4 -> V_15 , V_4 ) ;
V_11 = F_29 ( V_4 -> V_15 ) ;
if ( V_11 < 0 ) {
F_8 ( & V_5 -> V_6 , L_14 , V_11 ) ;
goto V_43;
}
F_30 ( & V_5 -> V_6 , V_4 ) ;
goto exit;
V_43:
F_31 ( V_4 -> V_15 ) ;
V_42:
F_32 ( V_4 ) ;
exit:
return V_11 ;
}
static int F_33 ( struct V_32 * V_5 )
{
struct V_3 * V_4 = F_34 ( & V_5 -> V_6 ) ;
struct V_16 * V_15 ;
F_2 ( & V_5 -> V_6 , L_15 ) ;
if ( ! V_4 )
return - V_13 ;
V_15 = V_4 -> V_15 ;
F_35 ( V_15 ) ;
F_31 ( V_15 ) ;
F_32 ( V_4 ) ;
F_30 ( & V_5 -> V_6 , NULL ) ;
return 0 ;
}
static int T_2 F_36 ( void )
{
F_37 ( V_44 L_16 ) ;
return F_38 ( & V_45 ) ;
}
static void T_3 F_39 ( void )
{
F_40 ( & V_45 ) ;
}
