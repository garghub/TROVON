static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 . V_4 ) ;
F_3 ( V_2 -> V_3 . V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_3 = & V_2 -> V_3 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
struct V_8 * V_9 = & V_3 -> V_10 [ V_6 ] ;
if ( V_9 -> V_11 )
F_5 ( V_3 -> V_4 , V_9 -> V_11 ) ;
}
if ( V_2 -> V_12 ) {
switch ( V_3 -> V_4 -> V_13 ) {
case V_14 :
F_6 ( V_2 -> V_12 ) ;
break;
default:
break;
}
F_7 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
}
F_8 ( V_2 ) ;
F_9 ( V_2 -> V_15 ) ;
F_10 ( V_2 , NULL ) ;
}
static int F_11 ( struct V_4 * V_16 , const struct V_17 * V_18 )
{
struct V_1 * V_2 ;
struct V_5 * V_3 ;
struct V_19 * V_20 ;
char V_21 [ V_22 ] ;
unsigned int V_6 , V_23 ;
int V_24 , V_25 ;
switch ( V_18 -> V_13 ) {
case V_14 :
break;
default:
F_12 ( & V_16 -> V_26 , L_1 , V_18 -> V_13 ) ;
return - V_27 ;
}
if ( F_13 () > 1 && F_14 ( & V_16 -> V_26 ) < 0 ) {
F_12 ( & V_16 -> V_26 , L_2 ) ;
return - V_28 ;
}
V_2 = F_15 ( sizeof( * V_2 ) , V_29 ,
F_14 ( & V_16 -> V_26 ) ) ;
if ( ! V_2 )
return - V_30 ;
F_16 ( & V_2 -> V_31 ) ;
V_3 = & V_2 -> V_3 ;
V_3 -> V_4 = V_16 ;
if ( F_17 ( V_2 , NULL ) ) {
F_12 ( & V_16 -> V_26 , L_3 ) ;
F_7 ( V_2 ) ;
return - V_32 ;
}
V_2 -> V_33 = V_34 ;
V_20 = F_15 ( sizeof( * V_20 ) , V_29 ,
F_14 ( & V_16 -> V_26 ) ) ;
if ( ! V_20 ) {
V_24 = - V_30 ;
goto V_35;
}
V_2 -> V_12 = V_20 ;
F_18 ( V_2 -> V_12 ) ;
F_19 ( V_16 , V_36 , & V_3 -> V_37 ) ;
F_20 ( V_16 , V_38 ,
& V_20 -> V_39 ) ;
V_20 -> V_40 = V_20 -> V_41 ( V_20 -> V_39 ) ;
V_20 -> V_42 = V_20 -> V_43 ( V_20 -> V_39 ) ;
V_3 -> V_44 = V_20 -> V_45 ( V_20 ) ;
if ( ! V_20 -> V_40 || ! V_20 -> V_42 ||
( ( ~ V_20 -> V_42 ) & 0x01 ) ) {
F_12 ( & V_16 -> V_26 , L_4 ) ;
V_24 = - V_32 ;
goto V_35;
}
snprintf ( V_21 , sizeof( V_21 ) , L_5 ,
V_46 , V_20 -> V_47 -> V_21 ,
V_16 -> V_48 -> V_49 , F_21 ( V_16 -> V_50 ) ,
F_22 ( V_16 -> V_50 ) ) ;
V_2 -> V_15 = F_23 ( V_21 , NULL ) ;
if ( ! V_2 -> V_15 ) {
F_12 ( & V_16 -> V_26 , L_6 , V_21 ) ;
V_24 = - V_28 ;
goto V_35;
}
V_24 = F_24 ( V_2 ) ;
if ( V_24 )
goto V_35;
if ( F_25 ( V_16 ) ) {
V_24 = - V_32 ;
goto V_35;
}
if ( F_26 ( V_16 , F_27 ( 64 ) ) ) {
if ( ( F_26 ( V_16 , F_27 ( 32 ) ) ) ) {
F_12 ( & V_16 -> V_26 , L_7 ) ;
V_24 = - V_32 ;
goto V_51;
} else {
F_28 ( V_16 , F_27 ( 32 ) ) ;
}
} else {
F_28 ( V_16 , F_27 ( 64 ) ) ;
}
if ( F_29 ( V_16 , V_52 ) ) {
V_24 = - V_32 ;
goto V_51;
}
F_20 ( V_16 , V_53 ,
& V_20 -> V_54 ) ;
V_6 = ( V_20 -> V_39 & V_55 ) ? 1 : 0 ;
V_25 = F_30 ( V_16 , V_56 ) ;
F_31 (bar_nr, (const unsigned long *)&bar_mask,
ADF_PCI_MAX_BARS * 2 ) {
struct V_8 * V_9 = & V_3 -> V_10 [ V_6 ++ ] ;
V_9 -> V_57 = F_32 ( V_16 , V_23 ) ;
if ( ! V_9 -> V_57 )
break;
V_9 -> V_58 = F_33 ( V_16 , V_23 ) ;
V_9 -> V_11 = F_34 ( V_3 -> V_4 , V_23 , 0 ) ;
if ( ! V_9 -> V_11 ) {
F_12 ( & V_16 -> V_26 , L_8 , V_23 ) ;
V_24 = - V_32 ;
goto V_59;
}
}
F_35 ( V_16 ) ;
if ( F_36 ( V_2 , & V_60 ) ) {
F_12 ( & V_16 -> V_26 , L_9 ) ;
V_24 = - V_32 ;
goto V_59;
}
if ( F_37 ( V_16 ) ) {
F_12 ( & V_16 -> V_26 , L_10 ) ;
V_24 = - V_30 ;
goto V_59;
}
V_24 = F_38 ( V_2 ) ;
if ( V_24 )
goto V_59;
V_24 = F_39 ( V_2 ) ;
if ( V_24 )
goto V_61;
V_24 = F_40 ( V_2 ) ;
if ( V_24 )
goto V_62;
return V_24 ;
V_62:
F_41 ( V_2 ) ;
V_61:
F_42 ( V_2 ) ;
V_59:
F_2 ( V_3 -> V_4 ) ;
V_51:
F_3 ( V_3 -> V_4 ) ;
V_35:
F_4 ( V_2 ) ;
F_7 ( V_2 ) ;
return V_24 ;
}
static void F_43 ( struct V_4 * V_16 )
{
struct V_1 * V_2 = F_44 ( V_16 ) ;
if ( ! V_2 ) {
F_45 ( L_11 ) ;
return;
}
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
F_46 ( V_2 ) ;
F_4 ( V_2 ) ;
F_1 ( V_2 ) ;
F_7 ( V_2 ) ;
}
static int T_1 F_47 ( void )
{
F_48 ( L_12 ) ;
if ( F_49 ( & V_60 ) ) {
F_45 ( L_13 ) ;
return - V_32 ;
}
return 0 ;
}
static void T_2 F_50 ( void )
{
F_51 ( & V_60 ) ;
}
