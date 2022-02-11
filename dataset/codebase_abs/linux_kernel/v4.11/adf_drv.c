static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 . V_4 ) ;
F_3 ( V_2 -> V_3 . V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_3 = & V_2 -> V_3 ;
struct V_1 * V_6 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
struct V_9 * V_10 = & V_3 -> V_11 [ V_7 ] ;
if ( V_10 -> V_12 )
F_5 ( V_3 -> V_4 , V_10 -> V_12 ) ;
}
if ( V_2 -> V_13 ) {
switch ( V_3 -> V_4 -> V_14 ) {
case V_15 :
F_6 ( V_2 -> V_13 ) ;
break;
default:
break;
}
F_7 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
}
F_8 ( V_2 ) ;
F_9 ( V_2 -> V_16 ) ;
V_6 = F_10 ( V_3 -> V_4 -> V_17 ) ;
F_11 ( V_2 , V_6 ) ;
}
static int F_12 ( struct V_4 * V_18 , const struct V_19 * V_20 )
{
struct V_1 * V_2 ;
struct V_1 * V_6 ;
struct V_5 * V_3 ;
struct V_21 * V_22 ;
char V_23 [ V_24 ] ;
unsigned int V_7 , V_25 ;
int V_26 , V_27 ;
switch ( V_20 -> V_14 ) {
case V_15 :
break;
default:
F_13 ( & V_18 -> V_28 , L_1 , V_20 -> V_14 ) ;
return - V_29 ;
}
V_2 = F_14 ( sizeof( * V_2 ) , V_30 ,
F_15 ( & V_18 -> V_28 ) ) ;
if ( ! V_2 )
return - V_31 ;
V_2 -> V_32 = true ;
V_6 = F_10 ( V_18 -> V_17 ) ;
V_3 = & V_2 -> V_3 ;
V_3 -> V_4 = V_18 ;
if ( F_16 ( V_2 , V_6 ) ) {
F_13 ( & V_18 -> V_28 , L_2 ) ;
F_7 ( V_2 ) ;
return - V_33 ;
}
F_17 ( & V_2 -> V_34 ) ;
V_2 -> V_35 = V_36 ;
V_22 = F_14 ( sizeof( * V_22 ) , V_30 ,
F_15 ( & V_18 -> V_28 ) ) ;
if ( ! V_22 ) {
V_26 = - V_31 ;
goto V_37;
}
V_2 -> V_13 = V_22 ;
F_18 ( V_2 -> V_13 ) ;
V_22 -> V_38 = V_22 -> V_39 ( V_22 -> V_40 ) ;
V_22 -> V_41 = V_22 -> V_42 ( V_22 -> V_40 ) ;
V_3 -> V_43 = V_22 -> V_44 ( V_22 ) ;
snprintf ( V_23 , sizeof( V_23 ) , L_3 ,
V_45 , V_22 -> V_46 -> V_23 ,
V_18 -> V_47 -> V_48 , F_19 ( V_18 -> V_49 ) ,
F_20 ( V_18 -> V_49 ) ) ;
V_2 -> V_16 = F_21 ( V_23 , NULL ) ;
if ( ! V_2 -> V_16 ) {
F_13 ( & V_18 -> V_28 , L_4 , V_23 ) ;
V_26 = - V_50 ;
goto V_37;
}
V_26 = F_22 ( V_2 ) ;
if ( V_26 )
goto V_37;
if ( F_23 ( V_18 ) ) {
V_26 = - V_33 ;
goto V_37;
}
if ( F_24 ( V_18 , F_25 ( 64 ) ) ) {
if ( ( F_24 ( V_18 , F_25 ( 32 ) ) ) ) {
F_13 ( & V_18 -> V_28 , L_5 ) ;
V_26 = - V_33 ;
goto V_51;
} else {
F_26 ( V_18 , F_25 ( 32 ) ) ;
}
} else {
F_26 ( V_18 , F_25 ( 64 ) ) ;
}
if ( F_27 ( V_18 , V_52 ) ) {
V_26 = - V_33 ;
goto V_51;
}
V_7 = 0 ;
V_27 = F_28 ( V_18 , V_53 ) ;
F_29 (bar_nr, (const unsigned long *)&bar_mask,
ADF_PCI_MAX_BARS * 2 ) {
struct V_9 * V_10 = & V_3 -> V_11 [ V_7 ++ ] ;
V_10 -> V_54 = F_30 ( V_18 , V_25 ) ;
if ( ! V_10 -> V_54 )
break;
V_10 -> V_55 = F_31 ( V_18 , V_25 ) ;
V_10 -> V_12 = F_32 ( V_3 -> V_4 , V_25 , 0 ) ;
if ( ! V_10 -> V_12 ) {
F_13 ( & V_18 -> V_28 , L_6 , V_25 ) ;
V_26 = - V_33 ;
goto V_56;
}
}
F_33 ( V_18 ) ;
F_34 ( & V_2 -> V_57 . V_58 ) ;
V_26 = F_35 ( V_2 ) ;
if ( V_26 )
goto V_56;
F_36 ( V_59 , & V_2 -> V_60 ) ;
V_26 = F_37 ( V_2 ) ;
if ( V_26 )
goto V_61;
V_26 = F_38 ( V_2 ) ;
if ( V_26 )
goto V_62;
return V_26 ;
V_62:
F_39 ( V_2 ) ;
V_61:
F_40 ( V_2 ) ;
V_56:
F_2 ( V_3 -> V_4 ) ;
V_51:
F_3 ( V_3 -> V_4 ) ;
V_37:
F_4 ( V_2 ) ;
F_7 ( V_2 ) ;
return V_26 ;
}
static void F_41 ( struct V_4 * V_18 )
{
struct V_1 * V_2 = F_10 ( V_18 ) ;
if ( ! V_2 ) {
F_42 ( L_7 ) ;
return;
}
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
F_4 ( V_2 ) ;
F_1 ( V_2 ) ;
F_7 ( V_2 ) ;
}
static int T_1 F_43 ( void )
{
F_44 ( L_8 ) ;
if ( F_45 ( & V_63 ) ) {
F_42 ( L_9 ) ;
return - V_33 ;
}
return 0 ;
}
static void T_2 F_46 ( void )
{
F_47 ( & V_63 ) ;
F_48 ( true ) ;
}
