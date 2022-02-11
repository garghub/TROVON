static int T_1 F_1 ( void )
{
void T_2 * V_1 ;
int V_2 , V_3 = - V_4 ;
V_1 = F_2 ( 0xf0000 , 0x10000 ) ;
if ( ! V_1 )
return - V_5 ;
for ( V_2 = 0 ; V_2 < F_3 ( V_6 ) ; V_2 ++ ) {
if ( F_4 ( V_1 + V_6 [ V_2 ] . V_7 ,
V_6 [ V_2 ] . string ,
strlen ( V_6 [ V_2 ] . string ) ) ) {
V_3 = 0 ;
break;
}
}
F_5 ( V_1 ) ;
return V_3 ;
}
static int T_1 F_6 ( struct V_8 * V_9 )
{
T_3 V_10 ;
int V_3 = 0 ;
if ( ! F_7 ( V_11 , 4 , L_1 ) )
return - V_12 ;
V_10 = F_8 ( V_11 ) ;
if ( V_10 != V_13 ) {
F_9 ( L_2 , V_10 ) ;
V_3 = - V_4 ;
goto V_14;
}
V_9 -> V_15 = V_10 ;
V_10 = F_8 ( V_16 ) ;
V_9 -> V_17 = V_10 & V_18 ;
V_9 -> V_19 = V_10 & V_20 ;
V_9 -> V_21 = V_10 & V_22 ;
V_10 = F_8 ( V_23 ) ;
V_9 -> V_24 = V_10 & V_25 ;
V_9 -> V_26 = V_10 & V_27 ;
V_10 = F_8 ( V_28 ) ;
V_9 -> V_29 = V_10 & ~ V_30 ;
V_14:
F_10 ( V_11 , 4 ) ;
return V_3 ;
}
static T_4 F_11 ( struct V_31 * V_32 ,
struct V_33 * V_34 , char * V_35 )
{
struct V_8 * V_9 = F_12 ( V_32 ) ;
return sprintf ( V_35 , L_3 , V_9 -> V_15 ) ;
}
static T_4 F_13 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
char * V_35 )
{
struct V_8 * V_9 = F_12 ( V_32 ) ;
return sprintf ( V_35 , L_3 , V_9 -> V_29 >> 1 ) ;
}
static void F_14 ( struct V_36 * V_37 ,
enum V_38 V_39 )
{
F_15 ( ! ! V_39 , V_28 ) ;
}
static enum V_38 F_16 ( struct V_36 * V_37 )
{
return ( F_8 ( V_28 ) & V_30 ) ? V_40 : V_41 ;
}
static int F_17 ( T_3 V_42 )
{
T_3 V_43 , V_44 ;
F_15 ( V_42 & 0x1f , V_45 ) ;
F_18 ( V_46 ) ;
if ( F_8 ( V_47 ) & V_48 )
return - V_12 ;
V_43 = F_8 ( V_45 ) ;
V_44 = F_8 ( V_49 ) ;
return ( V_44 << 8 ) | V_43 ;
}
static int T_1 F_19 ( void )
{
struct V_50 * V_51 ;
struct V_8 * V_9 ;
int V_52 ;
V_52 = F_1 () ;
if ( V_52 )
return V_52 ;
V_51 = F_20 ( L_1 , - 1 , NULL , 0 ) ;
if ( F_21 ( V_51 ) )
return F_22 ( V_51 ) ;
V_9 = F_23 ( & V_51 -> V_32 , sizeof( struct V_8 ) , V_53 ) ;
if ( ! V_9 ) {
V_52 = - V_5 ;
goto error;
}
V_52 = F_6 ( V_9 ) ;
if ( V_52 )
goto error;
F_24 ( V_51 , V_9 ) ;
V_52 = F_25 ( & V_51 -> V_32 . V_54 , & V_55 ) ;
if ( V_52 )
goto error;
V_56 . V_32 . V_57 = & V_51 -> V_32 ;
if ( F_26 ( & V_56 ) )
F_27 ( & V_51 -> V_32 , L_4 ) ;
V_58 . V_32 . V_57 = & V_51 -> V_32 ;
if ( F_26 ( & V_58 ) )
F_27 ( & V_51 -> V_32 , L_5 ) ;
if ( F_28 ( & V_51 -> V_32 , & V_59 ) )
F_27 ( & V_51 -> V_32 , L_6 ) ;
if ( V_9 -> V_21 ) {
V_60 . V_32 . V_57 = & V_51 -> V_32 ;
if ( F_26 ( & V_60 ) )
F_27 ( & V_51 -> V_32 , L_7 ) ;
}
return 0 ;
error:
F_29 ( V_51 ) ;
return V_52 ;
}
