int F_1 ( struct V_1 * V_2 ,
int V_3 ,
T_1 type , T_1 V_4 ,
void * V_5 ,
T_2 V_6 )
{
static unsigned V_7 = 1 ;
int V_8 ;
int V_9 ;
struct {
struct V_10 V_11 ;
struct V_12 V_13 ;
T_3 V_14 [] ;
} * V_15 ;
T_2 V_16 = sizeof( * V_15 ) + V_6 ;
if ( F_2 ( V_16 >= 256 ) )
return - V_17 ;
V_15 = F_3 ( V_16 , V_18 ) ;
if ( ! V_15 )
return - V_19 ;
F_4 ( & V_2 -> V_20 ) ;
V_15 -> V_11 . V_21 = F_5 ( V_22 ) ;
V_15 -> V_11 . V_23 = F_5 ( sizeof( struct V_12 ) + V_6 ) ;
V_15 -> V_13 . V_7 = F_5 ( V_7 ++ ) ;
V_15 -> V_13 . V_24 = F_5 ( V_3 ) ;
V_15 -> V_13 . type = F_5 ( type ) ;
V_15 -> V_13 . V_4 = F_5 ( V_4 ) ;
V_15 -> V_13 . V_25 = F_5 ( V_6 ) ;
memcpy ( V_15 -> V_14 , V_5 , V_6 ) ;
V_9 = F_6 ( V_2 -> V_26 , V_15 , V_16 ) ;
if ( V_9 )
goto V_27;
V_8 = F_7 ( & V_2 -> V_28 , V_29 ) ;
if ( ! V_8 )
V_9 = - V_30 ;
else
V_9 = V_2 -> V_31 ;
V_27:
F_8 ( V_15 ) ;
F_9 ( & V_2 -> V_20 ) ;
return V_9 ;
}
static int F_10 ( struct V_32 * V_33 ,
const void * V_34 ,
T_2 V_6 )
{
const struct V_10 * V_11 = V_34 ;
T_2 V_35 = F_11 ( V_11 -> V_23 ) ;
const struct V_36 * V_37 ;
struct V_1 * V_2 = F_12 ( V_33 ) ;
const T_3 * V_5 = V_34 + sizeof( struct V_10 ) ;
const T_3 * V_38 = V_5 + V_35 ;
char V_39 [ 32 ] ;
int V_40 = 0 ;
T_1 V_41 , V_42 ;
if ( F_11 ( V_11 -> V_21 ) != V_22 ||
V_35 < sizeof( struct V_36 ) ) {
F_13 ( V_2 -> V_43 , L_1 ) ;
return 0 ;
}
while ( V_5 < V_38 ) {
V_37 = (struct V_36 * ) V_5 ;
V_42 = F_11 ( V_37 -> V_23 ) ;
switch ( F_11 ( V_37 -> V_44 ) ) {
case V_45 :
break;
case V_46 :
V_41 = F_14 ( T_1 , F_15 ( V_42 , 4 ) , sizeof( V_39 ) ) ;
F_16 ( V_39 , V_37 -> V_47 , V_41 ) ;
V_39 [ V_41 - 1 ] = 0 ;
if ( ! strcmp ( V_39 , L_2 ) )
V_40 = - V_48 ;
else
V_40 = - V_17 ;
break;
}
V_5 = F_17 ( V_5 + 2 * sizeof( T_1 ) + V_42 , 4 ) ;
}
V_2 -> V_31 = V_40 ;
F_18 ( & V_2 -> V_28 ) ;
return 0 ;
}
static int F_19 ( struct V_49 * V_50 )
{
struct V_1 * V_2 ;
V_2 = F_20 ( & V_50 -> V_43 , sizeof( * V_2 ) , V_18 ) ;
if ( ! V_2 )
return - V_19 ;
F_21 ( & V_2 -> V_20 ) ;
F_22 ( & V_2 -> V_28 ) ;
V_2 -> V_43 = & V_50 -> V_43 ;
V_2 -> V_26 = V_50 -> V_33 ;
F_23 ( V_50 -> V_33 , V_2 ) ;
F_24 ( & V_50 -> V_43 , V_2 ) ;
return F_25 ( V_50 -> V_43 . V_51 , NULL , NULL , & V_50 -> V_43 ) ;
}
static void F_26 ( struct V_49 * V_50 )
{
F_27 ( & V_50 -> V_43 ) ;
}
static int T_4 F_28 ( void )
{
return F_29 ( & V_52 ) ;
}
static void T_5 F_30 ( void )
{
F_31 ( & V_52 ) ;
}
