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
V_9 -> V_13 = F_8 ( V_11 ) ;
if ( V_9 -> V_13 == V_14 ) {
V_9 -> V_15 = L_2 ;
} else if ( V_9 -> V_13 == V_16 ) {
V_9 -> V_15 = L_3 ;
} else {
F_9 ( L_4 , V_9 -> V_13 ) ;
V_3 = - V_4 ;
goto V_17;
}
V_10 = F_8 ( V_18 ) ;
V_9 -> V_19 = V_10 & V_20 ;
V_9 -> V_21 = V_10 & V_22 ;
V_9 -> V_23 = V_10 & V_24 ;
V_10 = F_8 ( V_25 ) ;
V_9 -> V_26 = V_10 & V_27 ;
V_9 -> V_28 = V_10 & V_29 ;
V_10 = F_8 ( V_30 ) ;
V_9 -> V_31 = V_10 & ~ V_32 ;
V_17:
F_10 ( V_11 , 4 ) ;
return V_3 ;
}
static T_4 F_11 ( struct V_33 * V_34 , struct V_35 * V_36 ,
char * V_37 )
{
struct V_8 * V_9 = F_12 ( V_34 ) ;
return sprintf ( V_37 , L_5 , V_9 -> V_15 ) ;
}
static T_4 F_13 ( struct V_33 * V_34 , struct V_35 * V_36 ,
char * V_37 )
{
struct V_8 * V_9 = F_12 ( V_34 ) ;
return sprintf ( V_37 , L_6 , V_9 -> V_13 ) ;
}
static T_4 F_14 ( struct V_33 * V_34 , struct V_35 * V_36 ,
char * V_37 )
{
struct V_8 * V_9 = F_12 ( V_34 ) ;
return sprintf ( V_37 , L_6 , V_9 -> V_31 >> 1 ) ;
}
static void F_15 ( struct V_38 * V_39 ,
enum V_40 V_41 )
{
F_16 ( ! ! V_41 , V_30 ) ;
}
static enum V_40 F_17 ( struct V_38 * V_39 )
{
return ( F_8 ( V_30 ) & V_32 ) ? V_42 : V_43 ;
}
static int F_18 ( T_3 V_44 )
{
T_3 V_45 , V_46 ;
F_16 ( V_44 & 0x1f , V_47 ) ;
F_19 ( V_48 ) ;
if ( F_8 ( V_49 ) & V_50 )
return - V_12 ;
V_45 = F_8 ( V_47 ) ;
V_46 = F_8 ( V_51 ) ;
return ( V_46 << 8 ) | V_45 ;
}
static int T_1 F_20 ( void )
{
struct V_52 * V_53 ;
struct V_8 * V_9 ;
int V_54 ;
V_54 = F_1 () ;
if ( V_54 )
return V_54 ;
V_53 = F_21 ( L_1 , - 1 , NULL , 0 ) ;
if ( F_22 ( V_53 ) )
return F_23 ( V_53 ) ;
V_9 = F_24 ( & V_53 -> V_34 , sizeof( struct V_8 ) , V_55 ) ;
if ( ! V_9 ) {
V_54 = - V_5 ;
goto error;
}
V_54 = F_6 ( V_9 ) ;
if ( V_54 )
goto error;
F_25 ( V_53 , V_9 ) ;
V_54 = F_26 ( & V_53 -> V_34 . V_56 , & V_57 ) ;
if ( V_54 )
goto error;
if ( V_9 -> V_13 == V_14 ) {
V_58 . V_34 . V_59 = & V_53 -> V_34 ;
if ( F_27 ( & V_58 ) )
F_28 ( & V_53 -> V_34 , L_7 ) ;
V_60 . V_34 . V_59 = & V_53 -> V_34 ;
if ( F_27 ( & V_60 ) )
F_28 ( & V_53 -> V_34 , L_8 ) ;
}
if ( F_29 ( & V_53 -> V_34 , & V_61 ) )
F_28 ( & V_53 -> V_34 , L_9 ) ;
if ( V_9 -> V_23 ) {
V_62 . V_34 . V_59 = & V_53 -> V_34 ;
if ( F_27 ( & V_62 ) )
F_28 ( & V_53 -> V_34 , L_10 ) ;
}
return 0 ;
error:
F_30 ( V_53 ) ;
return V_54 ;
}
