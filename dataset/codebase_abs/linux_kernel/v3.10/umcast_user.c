static struct V_1 * F_1 ( char * V_2 , unsigned short V_3 )
{
struct V_1 * sin ;
sin = F_2 ( sizeof( struct V_1 ) , V_4 ) ;
if ( sin == NULL ) {
F_3 ( V_5 L_1
L_2 ) ;
return NULL ;
}
sin -> V_6 = V_7 ;
if ( V_2 )
sin -> V_8 . V_9 = F_4 ( V_2 ) ;
else
sin -> V_8 . V_9 = V_10 ;
sin -> V_11 = F_5 ( V_3 ) ;
return sin ;
}
static int F_6 ( void * V_12 , void * V_13 )
{
struct V_14 * V_15 = V_12 ;
V_15 -> V_16 = F_1 ( V_15 -> V_2 , V_15 -> V_17 ) ;
if ( V_15 -> V_18 )
V_15 -> V_19 = F_1 ( NULL , V_15 -> V_20 ) ;
else
V_15 -> V_19 = V_15 -> V_16 ;
V_15 -> V_13 = V_13 ;
return 0 ;
}
static void F_7 ( void * V_12 )
{
struct V_14 * V_15 = V_12 ;
F_8 ( V_15 -> V_19 ) ;
if ( V_15 -> V_18 )
F_8 ( V_15 -> V_16 ) ;
V_15 -> V_19 = V_15 -> V_16 = NULL ;
}
static int F_9 ( void * V_12 )
{
struct V_14 * V_15 = V_12 ;
struct V_1 * V_21 = V_15 -> V_19 ;
struct V_1 * V_22 = V_15 -> V_16 ;
struct V_23 V_24 ;
int V_25 , V_26 = 1 , V_27 = - V_28 ;
if ( ( ! V_15 -> V_18 && V_21 -> V_8 . V_9 == 0 ) ||
( V_22 -> V_8 . V_9 == 0 ) ||
( V_21 -> V_11 == 0 ) || ( V_22 -> V_11 == 0 ) )
goto V_29;
V_25 = F_10 ( V_7 , V_30 , 0 ) ;
if ( V_25 < 0 ) {
V_27 = - V_31 ;
F_3 ( V_5 L_3
L_4 , V_31 ) ;
goto V_29;
}
if ( F_11 ( V_25 , V_32 , V_33 , & V_26 , sizeof( V_26 ) ) < 0 ) {
V_27 = - V_31 ;
F_3 ( V_5 L_5
L_4 , V_31 ) ;
goto V_34;
}
if ( ! V_15 -> V_18 ) {
if ( F_11 ( V_25 , V_35 , V_36 , & V_15 -> V_37 ,
sizeof( V_15 -> V_37 ) ) < 0 ) {
V_27 = - V_31 ;
F_3 ( V_5 L_6
L_7 , V_31 ) ;
goto V_34;
}
if ( F_11 ( V_25 , V_35 , V_38 ,
& V_26 , sizeof( V_26 ) ) < 0 ) {
V_27 = - V_31 ;
F_3 ( V_5 L_8
L_7 , V_31 ) ;
goto V_34;
}
}
if ( F_12 ( V_25 , (struct V_39 * ) V_21 , sizeof( * V_21 ) ) < 0 ) {
V_27 = - V_31 ;
F_3 ( V_5 L_9
L_4 , V_31 ) ;
goto V_34;
}
if ( ! V_15 -> V_18 ) {
V_24 . V_40 . V_9 = V_21 -> V_8 . V_9 ;
V_24 . V_41 . V_9 = 0 ;
if ( F_11 ( V_25 , V_35 , V_42 ,
& V_24 , sizeof( V_24 ) ) < 0 ) {
V_27 = - V_31 ;
F_3 ( V_5 L_10
L_7 , V_31 ) ;
F_3 ( V_5 L_11
L_12
L_13 ) ;
F_3 ( V_5 L_14
L_15 ) ;
goto V_34;
}
}
return V_25 ;
V_34:
F_13 ( V_25 ) ;
V_29:
return V_27 ;
}
static void F_14 ( int V_25 , void * V_12 )
{
struct V_14 * V_15 = V_12 ;
if ( ! V_15 -> V_18 ) {
struct V_23 V_24 ;
struct V_1 * V_21 = V_15 -> V_19 ;
V_24 . V_40 . V_9 = V_21 -> V_8 . V_9 ;
V_24 . V_41 . V_9 = 0 ;
if ( F_11 ( V_25 , V_35 , V_43 ,
& V_24 , sizeof( V_24 ) ) < 0 ) {
F_3 ( V_5 L_16
L_7 , V_31 ) ;
}
}
F_13 ( V_25 ) ;
}
int F_15 ( int V_25 , void * V_44 , int V_45 , struct V_14 * V_15 )
{
struct V_1 * V_46 = V_15 -> V_16 ;
return F_16 ( V_25 , V_44 , V_45 , V_46 , sizeof( * V_46 ) ) ;
}
