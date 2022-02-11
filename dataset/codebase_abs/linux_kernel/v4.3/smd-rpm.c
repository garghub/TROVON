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
T_3 V_14 [ V_6 ] ;
} V_15 ;
if ( F_2 ( sizeof( V_15 ) >= 256 ) )
return - V_16 ;
F_3 ( & V_2 -> V_17 ) ;
V_15 . V_11 . V_18 = V_19 ;
V_15 . V_11 . V_20 = sizeof( struct V_12 ) + V_6 ;
V_15 . V_13 . V_7 = V_7 ++ ;
V_15 . V_13 . V_21 = F_4 ( V_3 ) ;
V_15 . V_13 . type = type ;
V_15 . V_13 . V_4 = V_4 ;
V_15 . V_13 . V_22 = V_6 ;
memcpy ( V_15 . V_14 , V_5 , V_6 ) ;
V_9 = F_5 ( V_2 -> V_23 , & V_15 , sizeof( V_15 ) ) ;
if ( V_9 )
goto V_24;
V_8 = F_6 ( & V_2 -> V_25 , V_26 ) ;
if ( ! V_8 )
V_9 = - V_27 ;
else
V_9 = V_2 -> V_28 ;
V_24:
F_7 ( & V_2 -> V_17 ) ;
return V_9 ;
}
static int F_8 ( struct V_29 * V_30 ,
const void * V_31 ,
T_2 V_6 )
{
const struct V_10 * V_11 = V_31 ;
const struct V_32 * V_33 ;
struct V_1 * V_2 = F_9 ( & V_30 -> V_34 ) ;
const T_3 * V_5 = V_31 + sizeof( struct V_10 ) ;
const T_3 * V_35 = V_5 + V_11 -> V_20 ;
char V_36 [ 32 ] ;
int V_37 = 0 ;
T_1 V_38 ;
if ( V_11 -> V_18 != V_19 ||
V_11 -> V_20 < sizeof( struct V_32 ) ) {
F_10 ( & V_30 -> V_34 , L_1 ) ;
return 0 ;
}
while ( V_5 < V_35 ) {
V_33 = (struct V_32 * ) V_5 ;
switch ( V_33 -> V_39 ) {
case V_40 :
break;
case V_41 :
V_38 = F_11 ( T_1 , F_12 ( V_33 -> V_20 , 4 ) , sizeof( V_36 ) ) ;
F_13 ( V_36 , V_33 -> V_42 , V_38 ) ;
V_36 [ V_38 - 1 ] = 0 ;
if ( ! strcmp ( V_36 , L_2 ) )
V_37 = - V_43 ;
else
V_37 = - V_16 ;
break;
}
V_5 = F_14 ( V_5 + 2 * sizeof( T_1 ) + V_33 -> V_20 , 4 ) ;
}
V_2 -> V_28 = V_37 ;
F_15 ( & V_2 -> V_25 ) ;
return 0 ;
}
static int F_16 ( struct V_29 * V_44 )
{
struct V_1 * V_2 ;
V_2 = F_17 ( & V_44 -> V_34 , sizeof( * V_2 ) , V_45 ) ;
if ( ! V_2 )
return - V_46 ;
F_18 ( & V_2 -> V_17 ) ;
F_19 ( & V_2 -> V_25 ) ;
V_2 -> V_23 = V_44 -> V_47 ;
F_20 ( & V_44 -> V_34 , V_2 ) ;
return F_21 ( V_44 -> V_34 . V_48 , NULL , NULL , & V_44 -> V_34 ) ;
}
static void F_22 ( struct V_29 * V_44 )
{
F_23 ( & V_44 -> V_34 ) ;
}
static int T_4 F_24 ( void )
{
return F_25 ( & V_49 ) ;
}
static void T_5 F_26 ( void )
{
F_27 ( & V_49 ) ;
}
