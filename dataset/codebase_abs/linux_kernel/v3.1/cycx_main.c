static int T_1 F_1 ( void )
{
int V_1 , V_2 = - V_3 ;
F_2 ( L_1 ,
V_4 , V_5 , V_6 ,
V_7 ) ;
V_8 = F_3 ( int , V_8 , V_9 ) ;
V_8 = F_4 ( int , V_8 , 1 ) ;
V_10 = F_5 ( V_8 , sizeof( struct V_11 ) , V_12 ) ;
if ( ! V_10 )
goto V_13;
for ( V_1 = 0 ; V_1 < V_8 ; ++ V_1 ) {
struct V_11 * V_14 = & V_10 [ V_1 ] ;
struct V_15 * V_16 = & V_14 -> V_16 ;
sprintf ( V_14 -> V_17 , L_2 , V_18 , V_1 + 1 ) ;
V_16 -> V_19 = V_20 ;
V_16 -> V_21 = V_14 -> V_17 ;
V_16 -> V_22 = V_14 ;
V_16 -> V_23 = V_24 ;
V_16 -> V_25 = V_26 ;
V_2 = F_6 ( V_16 ) ;
if ( V_2 ) {
F_7 ( L_3 ,
V_14 -> V_17 , V_2 ) ;
break;
}
}
V_2 = - V_27 ;
if ( ! V_1 ) {
F_8 ( V_10 ) ;
goto V_13;
}
V_2 = 0 ;
V_8 = V_1 ;
V_13: return V_2 ;
}
static void T_2 F_9 ( void )
{
int V_28 = 0 ;
for (; V_28 < V_8 ; ++ V_28 ) {
struct V_11 * V_14 = & V_10 [ V_28 ] ;
F_10 ( V_14 -> V_17 ) ;
}
F_8 ( V_10 ) ;
}
static int V_24 ( struct V_15 * V_16 , T_3 * V_29 )
{
int V_30 = - V_31 ;
struct V_11 * V_14 ;
int V_32 ;
if ( ! V_16 || ! V_16 -> V_22 || ! V_29 )
goto V_13;
V_14 = V_16 -> V_22 ;
V_30 = - V_33 ;
if ( V_16 -> V_34 != V_35 )
goto V_13;
V_30 = - V_36 ;
if ( ! V_29 -> V_37 || ! V_29 -> V_38 ) {
F_7 ( L_4 ,
V_16 -> V_21 ) ;
goto V_13;
}
if ( V_29 -> V_32 <= 0 ) {
F_7 ( L_5 , V_16 -> V_21 ) ;
goto V_13;
}
V_32 = V_29 -> V_32 == 2 ? 9 : V_29 -> V_32 ;
if ( F_11 ( V_32 , V_39 , 0 , V_16 -> V_21 , V_14 ) ) {
F_7 ( L_6 , V_16 -> V_21 , V_32 ) ;
goto V_13;
}
memset ( & V_14 -> V_40 , 0 , sizeof( V_14 -> V_40 ) ) ;
V_14 -> V_40 . V_32 = V_32 ;
V_14 -> V_40 . V_41 = V_42 ;
V_14 -> V_40 . V_43 = V_44 ;
F_12 ( & V_14 -> V_45 ) ;
F_13 ( & V_14 -> V_46 ) ;
V_30 = F_14 ( & V_14 -> V_40 , V_29 -> V_38 , V_29 -> V_37 , V_29 -> V_47 ) ;
if ( V_30 )
goto V_48;
V_16 -> V_32 = V_32 ;
V_16 -> V_49 = V_16 -> V_50 = 0 ;
V_16 -> V_47 = ( unsigned long ) V_14 -> V_40 . V_51 ;
V_16 -> V_52 = V_14 -> V_40 . V_41 ;
V_16 -> V_53 [ 2 ] = 0 ;
V_16 -> V_53 [ 3 ] = V_14 -> V_40 . V_43 ;
switch ( V_14 -> V_40 . V_43 ) {
#ifdef F_15
case V_44 :
V_30 = F_16 ( V_14 , V_29 ) ;
break;
#endif
default:
F_7 ( L_7 , V_16 -> V_21 ) ;
V_30 = - V_36 ;
}
if ( V_30 ) {
F_17 ( & V_14 -> V_40 ) ;
goto V_48;
}
V_30 = 0 ;
V_13:
return V_30 ;
V_48:
F_18 ( V_32 , V_14 ) ;
goto V_13;
}
static int V_26 ( struct V_15 * V_16 )
{
int V_54 = - V_31 ;
struct V_11 * V_14 ;
if ( ! V_16 || ! V_16 -> V_22 )
goto V_13;
V_54 = 0 ;
if ( V_16 -> V_34 == V_35 )
goto V_13;
V_14 = V_16 -> V_22 ;
V_16 -> V_34 = V_35 ;
F_17 ( & V_14 -> V_40 ) ;
F_2 ( L_8 , V_16 -> V_21 , V_16 -> V_32 ) ;
F_18 ( V_16 -> V_32 , V_14 ) ;
V_13: return V_54 ;
}
static T_4 V_39 ( int V_32 , void * V_55 )
{
struct V_11 * V_14 = V_55 ;
if ( V_14 -> V_16 . V_34 == V_35 )
goto V_13;
if ( V_14 -> V_56 ) {
F_19 ( L_9 ,
V_14 -> V_17 , V_14 -> V_16 . V_32 ) ;
goto V_13;
}
if ( V_14 -> V_57 )
V_14 -> V_57 ( V_14 ) ;
return V_58 ;
V_13:
return V_59 ;
}
void F_20 ( struct V_11 * V_14 , int V_34 )
{
unsigned long V_60 ;
char * V_61 = NULL ;
F_21 ( & V_14 -> V_45 , V_60 ) ;
if ( V_14 -> V_16 . V_34 != V_34 ) {
switch ( V_34 ) {
case V_62 :
V_61 = L_10 ;
break;
case V_63 :
V_61 = L_11 ;
break;
}
F_2 ( L_12 , V_14 -> V_17 , V_61 ) ;
V_14 -> V_16 . V_34 = V_34 ;
}
V_14 -> V_64 = V_65 ;
F_22 ( & V_14 -> V_45 , V_60 ) ;
}
