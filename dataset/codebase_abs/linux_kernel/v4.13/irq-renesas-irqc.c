static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 -> V_5 ;
}
static void F_2 ( struct V_6 * V_7 , char * V_8 )
{
F_3 ( & V_7 -> V_9 -> V_10 -> V_11 , L_1 ,
V_8 , V_7 -> V_12 , V_7 -> V_13 ) ;
}
static int F_4 ( struct V_2 * V_14 , unsigned int type )
{
struct V_1 * V_9 = F_1 ( V_14 ) ;
int V_13 = F_5 ( V_14 ) ;
unsigned char V_15 = V_16 [ type & V_17 ] ;
T_1 V_18 ;
F_2 ( & V_9 -> V_19 [ V_13 ] , L_2 ) ;
if ( ! V_15 )
return - V_20 ;
V_18 = F_6 ( V_9 -> V_21 + F_7 ( V_13 ) ) ;
V_18 &= ~ 0x3f ;
V_18 |= V_15 ;
F_8 ( V_18 , V_9 -> V_21 + F_7 ( V_13 ) ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_14 , unsigned int V_22 )
{
struct V_1 * V_9 = F_1 ( V_14 ) ;
int V_13 = F_5 ( V_14 ) ;
F_10 ( V_9 -> V_19 [ V_13 ] . V_12 , V_22 ) ;
if ( ! V_9 -> V_23 )
return 0 ;
if ( V_22 )
F_11 ( V_9 -> V_23 ) ;
else
F_12 ( V_9 -> V_23 ) ;
return 0 ;
}
static T_2 F_13 ( int V_19 , void * V_24 )
{
struct V_6 * V_7 = V_24 ;
struct V_1 * V_9 = V_7 -> V_9 ;
T_1 V_25 = F_14 ( V_7 -> V_13 ) ;
F_2 ( V_7 , L_3 ) ;
if ( F_6 ( V_9 -> V_21 + V_26 ) & V_25 ) {
F_8 ( V_25 , V_9 -> V_21 + V_26 ) ;
F_2 ( V_7 , L_4 ) ;
F_15 ( F_16 ( V_9 -> V_27 , V_7 -> V_13 ) ) ;
return V_28 ;
}
return V_29 ;
}
static int F_17 ( struct V_30 * V_10 )
{
struct V_1 * V_9 ;
struct V_31 * V_32 ;
struct V_31 * V_19 ;
const char * V_33 = F_18 ( & V_10 -> V_11 ) ;
int V_34 ;
int V_35 ;
V_9 = F_19 ( sizeof( * V_9 ) , V_36 ) ;
if ( ! V_9 ) {
F_20 ( & V_10 -> V_11 , L_5 ) ;
V_34 = - V_37 ;
goto V_38;
}
V_9 -> V_10 = V_10 ;
F_21 ( V_10 , V_9 ) ;
V_9 -> V_23 = F_22 ( & V_10 -> V_11 , NULL ) ;
if ( F_23 ( V_9 -> V_23 ) ) {
F_24 ( & V_10 -> V_11 , L_6 ) ;
V_9 -> V_23 = NULL ;
}
F_25 ( & V_10 -> V_11 ) ;
F_26 ( & V_10 -> V_11 ) ;
V_32 = F_27 ( V_10 , V_39 , 0 ) ;
if ( ! V_32 ) {
F_20 ( & V_10 -> V_11 , L_7 ) ;
V_34 = - V_20 ;
goto V_40;
}
for ( V_35 = 0 ; V_35 < V_41 ; V_35 ++ ) {
V_19 = F_27 ( V_10 , V_42 , V_35 ) ;
if ( ! V_19 )
break;
V_9 -> V_19 [ V_35 ] . V_9 = V_9 ;
V_9 -> V_19 [ V_35 ] . V_13 = V_35 ;
V_9 -> V_19 [ V_35 ] . V_12 = V_19 -> V_43 ;
}
V_9 -> V_44 = V_35 ;
if ( V_9 -> V_44 < 1 ) {
F_20 ( & V_10 -> V_11 , L_8 ) ;
V_34 = - V_20 ;
goto V_40;
}
V_9 -> V_21 = F_28 ( V_32 -> V_43 , F_29 ( V_32 ) ) ;
if ( ! V_9 -> V_21 ) {
F_20 ( & V_10 -> V_11 , L_9 ) ;
V_34 = - V_45 ;
goto V_46;
}
V_9 -> V_47 = V_9 -> V_21 + F_30 ( 0 ) ;
V_9 -> V_27 = F_31 ( V_10 -> V_11 . V_48 ,
V_9 -> V_44 ,
& V_49 , V_9 ) ;
if ( ! V_9 -> V_27 ) {
V_34 = - V_45 ;
F_20 ( & V_10 -> V_11 , L_10 ) ;
goto V_46;
}
V_34 = F_32 ( V_9 -> V_27 , V_9 -> V_44 ,
1 , V_33 , V_50 ,
0 , 0 , V_51 ) ;
if ( V_34 ) {
F_20 ( & V_10 -> V_11 , L_11 ) ;
goto V_52;
}
V_9 -> V_53 = F_33 ( V_9 -> V_27 , 0 ) ;
V_9 -> V_53 -> V_54 = V_9 -> V_47 ;
V_9 -> V_53 -> V_55 [ 0 ] . V_56 . V_57 = V_58 ;
V_9 -> V_53 -> V_55 [ 0 ] . V_56 . V_59 = V_60 ;
V_9 -> V_53 -> V_55 [ 0 ] . V_61 . V_62 = V_63 ;
V_9 -> V_53 -> V_55 [ 0 ] . V_61 . V_64 = V_65 ;
V_9 -> V_53 -> V_55 [ 0 ] . V_61 . V_66 = F_4 ;
V_9 -> V_53 -> V_55 [ 0 ] . V_61 . V_67 = F_9 ;
V_9 -> V_53 -> V_55 [ 0 ] . V_61 . V_68 = V_69 ;
for ( V_35 = 0 ; V_35 < V_9 -> V_44 ; V_35 ++ ) {
if ( F_34 ( V_9 -> V_19 [ V_35 ] . V_12 , F_13 ,
0 , V_33 , & V_9 -> V_19 [ V_35 ] ) ) {
F_20 ( & V_10 -> V_11 , L_12 ) ;
V_34 = - V_70 ;
goto V_71;
}
}
F_35 ( & V_10 -> V_11 , L_13 , V_9 -> V_44 ) ;
return 0 ;
V_71:
while ( -- V_35 >= 0 )
F_36 ( V_9 -> V_19 [ V_35 ] . V_12 , & V_9 -> V_19 [ V_35 ] ) ;
V_52:
F_37 ( V_9 -> V_27 ) ;
V_46:
F_38 ( V_9 -> V_21 ) ;
V_40:
F_39 ( & V_10 -> V_11 ) ;
F_40 ( & V_10 -> V_11 ) ;
F_41 ( V_9 ) ;
V_38:
return V_34 ;
}
static int F_42 ( struct V_30 * V_10 )
{
struct V_1 * V_9 = F_43 ( V_10 ) ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_9 -> V_44 ; V_35 ++ )
F_36 ( V_9 -> V_19 [ V_35 ] . V_12 , & V_9 -> V_19 [ V_35 ] ) ;
F_37 ( V_9 -> V_27 ) ;
F_38 ( V_9 -> V_21 ) ;
F_39 ( & V_10 -> V_11 ) ;
F_40 ( & V_10 -> V_11 ) ;
F_41 ( V_9 ) ;
return 0 ;
}
static int T_3 F_44 ( void )
{
return F_45 ( & V_72 ) ;
}
static void T_4 F_46 ( void )
{
F_47 ( & V_72 ) ;
}
