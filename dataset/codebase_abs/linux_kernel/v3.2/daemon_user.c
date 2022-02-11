static struct V_1 * F_1 ( void * V_2 , int V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( struct V_1 ) , V_5 ) ;
if ( V_4 == NULL ) {
F_3 ( V_6 L_1
L_2 ) ;
return NULL ;
}
V_4 -> V_7 = V_8 ;
memcpy ( V_4 -> V_9 , V_2 , V_3 ) ;
return V_4 ;
}
static int F_4 ( struct V_10 * V_11 )
{
struct V_1 * V_12 = V_11 -> V_12 ;
struct V_1 * V_13 = V_11 -> V_13 ;
struct V_1 * V_4 ;
struct V_14 V_15 ;
int V_16 , V_17 , V_18 ;
V_11 -> V_19 = F_5 ( V_8 , V_20 , 0 ) ;
if ( V_11 -> V_19 < 0 ) {
V_18 = - V_21 ;
F_3 ( V_6 L_3
L_4 , - V_18 ) ;
return V_18 ;
}
if ( F_6 ( V_11 -> V_19 , (struct V_22 * ) V_12 ,
sizeof( * V_12 ) ) < 0 ) {
V_18 = - V_21 ;
F_3 ( V_6 L_5
L_4 , - V_18 ) ;
goto V_23;
}
V_16 = F_5 ( V_8 , V_24 , 0 ) ;
if ( V_16 < 0 ) {
V_18 = - V_21 ;
F_3 ( V_6 L_6
L_4 , - V_18 ) ;
goto V_23;
}
if ( F_7 ( V_16 , (struct V_22 * ) V_13 , sizeof( * V_13 ) ) < 0 ) {
V_18 = - V_21 ;
F_3 ( V_6 L_7
L_4 , - V_18 ) ;
goto V_25;
}
V_4 = F_2 ( sizeof( struct V_1 ) , V_5 ) ;
if ( V_4 == NULL ) {
F_3 ( V_6 L_1
L_2 ) ;
V_18 = - V_26 ;
goto V_25;
}
V_15 . V_27 = V_28 ;
V_15 . V_29 = V_30 ;
V_15 . type = V_31 ;
V_15 . V_32 = * V_13 ;
V_17 = F_8 ( V_11 -> V_19 , & V_15 , sizeof( V_15 ) ) ;
if ( V_17 != sizeof( V_15 ) ) {
F_3 ( V_6 L_8
L_9 , - V_21 ) ;
V_18 = - V_33 ;
goto V_34;
}
V_17 = F_9 ( V_11 -> V_19 , V_4 , sizeof( * V_4 ) ) ;
if ( V_17 != sizeof( * V_4 ) ) {
F_3 ( V_6 L_10
L_11 , - V_21 ) ;
V_18 = - V_33 ;
goto V_34;
}
V_11 -> V_35 = V_4 ;
return V_16 ;
V_34:
F_10 ( V_4 ) ;
V_25:
F_11 ( V_16 ) ;
V_23:
F_11 ( V_11 -> V_19 ) ;
return V_18 ;
}
static int F_12 ( void * V_36 , void * V_37 )
{
struct V_10 * V_11 = V_36 ;
struct V_38 V_39 ;
struct {
char V_40 ;
int V_41 ;
int V_42 ;
} V_2 ;
if ( ! strcmp ( V_11 -> V_43 , L_12 ) )
V_11 -> V_12 = F_1 ( V_11 -> V_44 ,
strlen ( V_11 -> V_44 ) + 1 ) ;
V_2 . V_40 = 0 ;
V_2 . V_41 = F_13 () ;
F_14 ( & V_39 , NULL ) ;
V_2 . V_42 = V_39 . V_45 ;
V_11 -> V_13 = F_1 ( & V_2 , sizeof( V_2 ) ) ;
V_11 -> V_37 = V_37 ;
V_11 -> V_16 = F_4 ( V_11 ) ;
if ( V_11 -> V_16 < 0 ) {
F_10 ( V_11 -> V_13 ) ;
V_11 -> V_13 = NULL ;
return V_11 -> V_16 ;
}
return 0 ;
}
static int F_15 ( void * V_36 )
{
struct V_10 * V_11 = V_36 ;
return V_11 -> V_16 ;
}
static void F_16 ( void * V_36 )
{
struct V_10 * V_11 = V_36 ;
F_11 ( V_11 -> V_16 ) ;
V_11 -> V_16 = - 1 ;
F_11 ( V_11 -> V_19 ) ;
V_11 -> V_19 = - 1 ;
F_10 ( V_11 -> V_35 ) ;
V_11 -> V_35 = NULL ;
F_10 ( V_11 -> V_12 ) ;
V_11 -> V_12 = NULL ;
F_10 ( V_11 -> V_13 ) ;
V_11 -> V_13 = NULL ;
}
int F_17 ( int V_16 , void * V_46 , int V_3 , struct V_10 * V_11 )
{
struct V_1 * V_35 = V_11 -> V_35 ;
return F_18 ( V_16 , V_46 , V_3 , V_35 , sizeof( * V_35 ) ) ;
}
