static int T_1 F_1 ( void )
{
int V_1 , V_2 = - V_3 ;
F_2 ( V_4 L_1 ,
V_5 , V_6 , V_7 ,
V_8 ) ;
V_9 = F_3 ( int , V_9 , V_10 ) ;
V_9 = F_4 ( int , V_9 , 1 ) ;
V_11 = F_5 ( V_9 , sizeof( struct V_12 ) , V_13 ) ;
if ( ! V_11 )
goto V_14;
for ( V_1 = 0 ; V_1 < V_9 ; ++ V_1 ) {
struct V_12 * V_15 = & V_11 [ V_1 ] ;
struct V_16 * V_17 = & V_15 -> V_17 ;
sprintf ( V_15 -> V_18 , L_2 , V_19 , V_1 + 1 ) ;
V_17 -> V_20 = V_21 ;
V_17 -> V_22 = V_15 -> V_18 ;
V_17 -> V_23 = V_15 ;
V_17 -> V_24 = V_25 ;
V_17 -> V_26 = V_27 ;
V_2 = F_6 ( V_17 ) ;
if ( V_2 ) {
F_2 ( V_28 L_3
L_4 ,
V_19 , V_15 -> V_18 , V_2 ) ;
break;
}
}
V_2 = - V_29 ;
if ( ! V_1 ) {
F_7 ( V_11 ) ;
goto V_14;
}
V_2 = 0 ;
V_9 = V_1 ;
V_14: return V_2 ;
}
static void T_2 F_8 ( void )
{
int V_30 = 0 ;
for (; V_30 < V_9 ; ++ V_30 ) {
struct V_12 * V_15 = & V_11 [ V_30 ] ;
F_9 ( V_15 -> V_18 ) ;
}
F_7 ( V_11 ) ;
}
static int V_25 ( struct V_16 * V_17 , T_3 * V_31 )
{
int V_32 = - V_33 ;
struct V_12 * V_15 ;
int V_34 ;
if ( ! V_17 || ! V_17 -> V_23 || ! V_31 )
goto V_14;
V_15 = V_17 -> V_23 ;
V_32 = - V_35 ;
if ( V_17 -> V_36 != V_37 )
goto V_14;
V_32 = - V_38 ;
if ( ! V_31 -> V_39 || ! V_31 -> V_40 ) {
F_2 ( V_28 L_5
L_6 , V_17 -> V_22 ) ;
goto V_14;
}
if ( V_31 -> V_34 <= 0 ) {
F_2 ( V_28 L_7 ,
V_17 -> V_22 ) ;
goto V_14;
}
V_34 = V_31 -> V_34 == 2 ? 9 : V_31 -> V_34 ;
if ( F_10 ( V_34 , V_41 , 0 , V_17 -> V_22 , V_15 ) ) {
F_2 ( V_28 L_8 ,
V_17 -> V_22 , V_34 ) ;
goto V_14;
}
memset ( & V_15 -> V_42 , 0 , sizeof( V_15 -> V_42 ) ) ;
V_15 -> V_42 . V_34 = V_34 ;
V_15 -> V_42 . V_43 = V_44 ;
V_15 -> V_42 . V_45 = V_46 ;
F_11 ( & V_15 -> V_47 ) ;
F_12 ( & V_15 -> V_48 ) ;
V_32 = F_13 ( & V_15 -> V_42 , V_31 -> V_40 , V_31 -> V_39 , V_31 -> V_49 ) ;
if ( V_32 )
goto V_50;
V_17 -> V_34 = V_34 ;
V_17 -> V_51 = V_17 -> V_52 = 0 ;
V_17 -> V_49 = ( unsigned long ) V_15 -> V_42 . V_53 ;
V_17 -> V_54 = V_15 -> V_42 . V_43 ;
V_17 -> V_55 [ 2 ] = 0 ;
V_17 -> V_55 [ 3 ] = V_15 -> V_42 . V_45 ;
switch ( V_15 -> V_42 . V_45 ) {
#ifdef F_14
case V_46 :
V_32 = F_15 ( V_15 , V_31 ) ;
break;
#endif
default:
F_2 ( V_28 L_9 ,
V_17 -> V_22 ) ;
V_32 = - V_38 ;
}
if ( V_32 ) {
F_16 ( & V_15 -> V_42 ) ;
goto V_50;
}
V_32 = 0 ;
V_14:
return V_32 ;
V_50:
F_17 ( V_34 , V_15 ) ;
goto V_14;
}
static int V_27 ( struct V_16 * V_17 )
{
int V_56 = - V_33 ;
struct V_12 * V_15 ;
if ( ! V_17 || ! V_17 -> V_23 )
goto V_14;
V_56 = 0 ;
if ( V_17 -> V_36 == V_37 )
goto V_14;
V_15 = V_17 -> V_23 ;
V_17 -> V_36 = V_37 ;
F_16 ( & V_15 -> V_42 ) ;
F_2 ( V_4 L_10 , V_17 -> V_22 ,
V_17 -> V_34 ) ;
F_17 ( V_17 -> V_34 , V_15 ) ;
V_14: return V_56 ;
}
static T_4 V_41 ( int V_34 , void * V_57 )
{
struct V_12 * V_15 = V_57 ;
if ( V_15 -> V_17 . V_36 == V_37 )
goto V_14;
if ( V_15 -> V_58 ) {
F_2 ( V_59 L_11 ,
V_15 -> V_18 , V_15 -> V_17 . V_34 ) ;
goto V_14;
}
if ( V_15 -> V_60 )
V_15 -> V_60 ( V_15 ) ;
return V_61 ;
V_14:
return V_62 ;
}
void F_18 ( struct V_12 * V_15 , int V_36 )
{
unsigned long V_63 ;
char * V_64 = NULL ;
F_19 ( & V_15 -> V_47 , V_63 ) ;
if ( V_15 -> V_17 . V_36 != V_36 ) {
switch ( V_36 ) {
case V_65 :
V_64 = L_12 ;
break;
case V_66 :
V_64 = L_13 ;
break;
}
F_2 ( V_4 L_14 , V_15 -> V_18 , V_64 ) ;
V_15 -> V_17 . V_36 = V_36 ;
}
V_15 -> V_67 = V_68 ;
F_20 ( & V_15 -> V_47 , V_63 ) ;
}
