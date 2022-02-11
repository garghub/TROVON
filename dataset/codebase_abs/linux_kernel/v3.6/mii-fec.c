static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_6 T_1 * V_8 = V_6 -> V_8 ;
int V_9 , V_10 = - 1 ;
F_2 ( ( F_3 ( & V_8 -> V_11 ) & V_12 ) == 0 ) ;
F_4 ( & V_8 -> V_13 , ( V_3 << 23 ) | F_5 ( V_4 ) ) ;
for ( V_9 = 0 ; V_9 < V_14 ; V_9 ++ )
if ( ( F_3 ( & V_8 -> V_15 ) & V_16 ) != 0 )
break;
if ( V_9 < V_14 ) {
F_4 ( & V_8 -> V_15 , V_16 ) ;
V_10 = F_3 ( & V_8 -> V_13 ) & 0xffff ;
}
return V_10 ;
}
static int F_6 ( struct V_1 * V_2 , int V_3 , int V_4 , T_2 V_17 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_6 T_1 * V_8 = V_6 -> V_8 ;
int V_9 ;
F_2 ( ( F_3 ( & V_8 -> V_11 ) & V_12 ) == 0 ) ;
F_4 ( & V_8 -> V_13 , ( V_3 << 23 ) | F_7 ( V_4 , V_17 ) ) ;
for ( V_9 = 0 ; V_9 < V_14 ; V_9 ++ )
if ( ( F_3 ( & V_8 -> V_15 ) & V_16 ) != 0 )
break;
if ( V_9 < V_14 )
F_4 ( & V_8 -> V_15 , V_16 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
return 0 ;
}
static int T_3 F_9 ( struct V_18 * V_19 )
{
const struct V_20 * V_21 ;
struct V_22 V_23 ;
struct V_1 * V_24 ;
struct V_5 * V_6 ;
int (* F_10)( struct V_25 * );
int V_10 = - V_26 , clock , V_27 ;
V_21 = F_11 ( V_28 , & V_19 -> V_29 ) ;
if ( ! V_21 )
return - V_30 ;
F_10 = V_21 -> V_31 ;
V_24 = F_12 () ;
if ( ! V_24 )
goto V_32;
V_6 = F_13 ( sizeof( struct V_5 ) , V_33 ) ;
if ( ! V_6 )
goto V_34;
V_24 -> V_7 = V_6 ;
V_24 -> V_35 = L_1 ;
V_24 -> V_36 = & F_1 ;
V_24 -> V_37 = & F_6 ;
V_24 -> V_38 = & F_8 ;
V_10 = F_14 ( V_19 -> V_29 . V_39 , 0 , & V_23 ) ;
if ( V_10 )
goto V_40;
snprintf ( V_24 -> V_41 , V_42 , L_2 , V_23 . V_43 ) ;
V_6 -> V_8 = F_15 ( V_23 . V_43 , F_16 ( & V_23 ) ) ;
if ( ! V_6 -> V_8 ) {
V_10 = - V_26 ;
goto V_44;
}
if ( F_10 ) {
clock = F_10 ( V_19 -> V_29 . V_39 ) ;
if ( ! clock ) {
F_17 ( & V_19 -> V_29 , L_3 ) ;
clock = 0x3F * 5000000 ;
}
} else
clock = V_45 ;
V_27 = ( clock + 4999999 ) / 5000000 ;
if ( V_27 > 0x3F ) {
V_27 = 0x3F ;
F_18 ( & V_19 -> V_29 ,
L_4 ,
clock / V_27 ) ;
}
V_6 -> V_46 = V_27 << 1 ;
F_19 ( & V_6 -> V_8 -> V_11 , V_12 ) ;
F_19 ( & V_6 -> V_8 -> V_47 , V_48 |
V_49 ) ;
F_4 ( & V_6 -> V_8 -> V_15 , V_16 ) ;
F_20 ( & V_6 -> V_8 -> V_50 , 0x7E , V_6 -> V_46 ) ;
V_24 -> V_51 = ~ 0 ;
V_24 -> V_52 = F_21 ( sizeof( int ) * V_53 , V_33 ) ;
if ( ! V_24 -> V_52 ) {
V_10 = - V_26 ;
goto V_54;
}
V_24 -> V_55 = & V_19 -> V_29 ;
F_22 ( & V_19 -> V_29 , V_24 ) ;
V_10 = F_23 ( V_24 , V_19 -> V_29 . V_39 ) ;
if ( V_10 )
goto V_56;
return 0 ;
V_56:
F_22 ( & V_19 -> V_29 , NULL ) ;
F_24 ( V_24 -> V_52 ) ;
V_54:
F_25 ( V_6 -> V_8 ) ;
V_40:
V_44:
F_24 ( V_6 ) ;
V_34:
F_26 ( V_24 ) ;
V_32:
return V_10 ;
}
static int F_27 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_28 ( & V_19 -> V_29 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_29 ( V_2 ) ;
F_22 ( & V_19 -> V_29 , NULL ) ;
F_24 ( V_2 -> V_52 ) ;
F_25 ( V_6 -> V_8 ) ;
F_24 ( V_6 ) ;
F_26 ( V_2 ) ;
return 0 ;
}
