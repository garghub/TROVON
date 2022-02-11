static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
int V_6 ;
int V_7 = 0 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
V_7 = F_2 (
V_2 ,
V_4 [ V_6 ] . V_8 , V_4 [ V_6 ] . V_9 ) ;
if ( V_7 )
break;
}
return V_7 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_7 ;
int V_10 = 10 ;
int V_11 ;
V_7 = F_2 ( V_2 , 0xC7 , 0x00 ) ;
if ( V_7 )
goto V_12;
do {
F_4 ( 1 ) ;
V_7 = F_5 ( V_2 , 0x1B ) ;
} while ( ( V_7 != V_13 ) && V_10 -- );
if ( V_7 != V_13 )
return - V_14 ;
V_7 = F_2 ( V_2 , 0x1A , 0x11 ) ;
if ( V_7 )
goto V_12;
V_11 = F_6 ( V_15 ) ;
V_7 = F_7 ( V_2 , V_15 , V_11 ) ;
if ( V_7 != V_11 ) {
V_7 = - V_16 ;
goto V_12;
}
V_7 = F_2 ( V_2 , 0x08 , 0x20 ) ;
if ( V_7 )
goto V_12;
V_11 = F_6 ( V_17 ) ;
V_7 = F_7 ( V_2 , V_17 , V_11 ) ;
if ( V_7 != V_11 ) {
V_7 = - V_16 ;
goto V_12;
}
V_7 = F_1 ( V_2 , V_18 , F_6 ( V_18 ) ) ;
if ( V_7 )
goto V_12;
V_11 = F_6 ( V_19 ) ;
V_7 = F_7 ( V_2 , V_19 , V_11 ) ;
if ( V_7 != V_11 ) {
V_7 = - V_16 ;
goto V_12;
}
V_7 = F_1 ( V_2 , V_20 , F_6 ( V_20 ) ) ;
if ( V_7 )
goto V_12;
V_11 = F_6 ( V_21 ) ;
V_7 = F_7 ( V_2 , V_21 , V_11 ) ;
if ( V_7 != V_11 ) {
V_7 = - V_16 ;
goto V_12;
}
V_7 = F_1 ( V_2 , V_22 , F_6 ( V_22 ) ) ;
if ( V_7 )
goto V_12;
return 0 ;
V_12:
F_8 ( V_23 L_1 , V_24 , V_7 ) ;
return V_7 ;
}
static int F_9 ( struct V_1 * V_2 ,
const struct V_25 * V_26 )
{
int V_7 ;
if ( ! F_10 ( V_2 -> V_27 ,
V_28 | V_29 ) )
return - V_14 ;
V_7 = F_3 ( V_2 ) ;
return V_7 ;
}
static int T_1 F_11 ( void )
{
int V_30 ;
struct V_31 V_32 ;
if ( F_12 ( L_2 ) )
return 0 ;
V_32 . V_33 = 1366 ;
V_32 . V_34 = 768 ;
V_32 . type = V_35 ;
V_32 . V_36 = V_37 ;
V_32 . V_38 = 0 ;
V_32 . V_39 = 24 ;
V_32 . V_40 = 2 ;
V_32 . V_41 = 74250000 ;
V_32 . V_42 . V_43 = 120 ;
V_32 . V_42 . V_44 = 20 ;
V_32 . V_42 . V_45 = 40 ;
V_32 . V_42 . V_46 = 25 ;
V_32 . V_42 . V_47 = 1 ;
V_32 . V_42 . V_48 = 7 ;
V_32 . V_42 . V_49 = 0 ;
V_32 . V_42 . V_50 = 0xff ;
V_32 . V_42 . V_51 = 0 ;
V_30 = F_13 ( & V_32 ) ;
if ( V_30 ) {
F_8 ( V_23 L_3 , V_24 ) ;
goto V_52;
}
V_30 = F_14 ( & V_53 ) ;
if ( V_30 )
F_8 ( V_23 L_4 , V_24 ) ;
V_52:
return V_30 ;
}
