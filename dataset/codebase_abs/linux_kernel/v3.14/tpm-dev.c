static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 ( & V_3 -> V_4 ) ;
}
static void F_3 ( struct V_5 * V_4 )
{
struct V_2 * V_3 = F_4 ( V_4 , struct V_2 , V_4 ) ;
F_5 ( & V_3 -> V_6 ) ;
F_6 ( & V_3 -> V_7 , 0 ) ;
memset ( V_3 -> V_8 , 0 , sizeof( V_3 -> V_8 ) ) ;
F_7 ( & V_3 -> V_6 ) ;
}
static int F_8 ( struct V_9 * V_9 , struct V_10 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_14 * V_15 = F_4 ( V_12 , struct V_14 ,
V_16 . V_17 ) ;
struct V_2 * V_3 ;
if ( F_9 ( 0 , & V_15 -> V_18 ) ) {
F_10 ( V_15 -> V_19 , L_1 ) ;
return - V_20 ;
}
V_3 = F_11 ( sizeof( * V_3 ) , V_21 ) ;
if ( V_3 == NULL ) {
F_12 ( 0 , & V_15 -> V_18 ) ;
return - V_22 ;
}
V_3 -> V_15 = V_15 ;
F_6 ( & V_3 -> V_7 , 0 ) ;
F_13 ( & V_3 -> V_6 ) ;
F_14 ( & V_3 -> V_23 , F_1 ,
( unsigned long ) V_3 ) ;
F_15 ( & V_3 -> V_4 , F_3 ) ;
V_10 -> V_13 = V_3 ;
F_16 ( V_15 -> V_19 ) ;
return 0 ;
}
static T_1 F_17 ( struct V_10 * V_10 , char T_2 * V_24 ,
T_3 V_25 , T_4 * V_26 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
T_1 V_27 ;
int V_28 ;
F_18 ( & V_3 -> V_23 ) ;
F_19 ( & V_3 -> V_4 ) ;
V_27 = F_20 ( & V_3 -> V_7 ) ;
if ( V_27 > 0 ) {
T_1 V_29 = V_27 ;
if ( V_25 < V_27 )
V_27 = V_25 ;
F_5 ( & V_3 -> V_6 ) ;
V_28 = F_21 ( V_24 , V_3 -> V_8 , V_27 ) ;
memset ( V_3 -> V_8 , 0 , V_29 ) ;
if ( V_28 )
V_27 = - V_30 ;
F_7 ( & V_3 -> V_6 ) ;
}
F_6 ( & V_3 -> V_7 , 0 ) ;
return V_27 ;
}
static T_1 F_22 ( struct V_10 * V_10 , const char T_2 * V_24 ,
T_3 V_25 , T_4 * V_26 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
T_3 V_31 = V_25 ;
T_1 V_32 ;
if ( F_20 ( & V_3 -> V_7 ) != 0 )
return - V_20 ;
if ( V_31 > V_33 )
return - V_34 ;
F_5 ( & V_3 -> V_6 ) ;
if ( F_23
( V_3 -> V_8 , ( void T_2 * ) V_24 , V_31 ) ) {
F_7 ( & V_3 -> V_6 ) ;
return - V_30 ;
}
V_32 = F_24 ( V_3 -> V_15 , V_3 -> V_8 ,
sizeof( V_3 -> V_8 ) ) ;
if ( V_32 < 0 ) {
F_7 ( & V_3 -> V_6 ) ;
return V_32 ;
}
F_6 ( & V_3 -> V_7 , V_32 ) ;
F_7 ( & V_3 -> V_6 ) ;
F_25 ( & V_3 -> V_23 , V_35 + ( 60 * V_36 ) ) ;
return V_31 ;
}
static int F_26 ( struct V_9 * V_9 , struct V_10 * V_10 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
F_18 ( & V_3 -> V_23 ) ;
F_19 ( & V_3 -> V_4 ) ;
V_10 -> V_13 = NULL ;
F_6 ( & V_3 -> V_7 , 0 ) ;
F_12 ( 0 , & V_3 -> V_15 -> V_18 ) ;
F_27 ( V_3 -> V_15 -> V_19 ) ;
F_28 ( V_3 ) ;
return 0 ;
}
int F_29 ( struct V_14 * V_15 )
{
int V_28 ;
V_15 -> V_16 . V_17 . V_37 = & V_38 ;
if ( V_15 -> V_39 == 0 )
V_15 -> V_16 . V_17 . V_40 = V_41 ;
else
V_15 -> V_16 . V_17 . V_40 = V_42 ;
V_15 -> V_16 . V_17 . V_43 = V_15 -> V_44 ;
V_15 -> V_16 . V_17 . V_45 = V_15 -> V_19 ;
V_28 = F_30 ( & V_15 -> V_16 . V_17 ) ;
if ( V_28 ) {
V_15 -> V_16 . V_17 . V_43 = NULL ;
F_31 ( V_15 -> V_19 ,
L_2 ,
V_15 -> V_16 . V_17 . V_43 ,
V_15 -> V_16 . V_17 . V_40 , V_28 ) ;
}
return V_28 ;
}
void F_32 ( struct V_14 * V_15 )
{
if ( V_15 -> V_16 . V_17 . V_43 )
F_33 ( & V_15 -> V_16 . V_17 ) ;
}
