static void F_1 ( struct V_1 * V_2 , char * V_3 )
{
F_2 ( & V_2 -> V_4 -> V_5 -> V_6 , L_1 ,
V_3 , V_2 -> V_7 , V_2 -> V_8 , V_2 -> V_9 ) ;
}
static void F_3 ( struct V_10 * V_11 )
{
struct V_12 * V_4 = F_4 ( V_11 ) ;
int V_8 = F_5 ( V_11 ) ;
F_1 ( & V_4 -> V_13 [ V_8 ] , L_2 ) ;
F_6 ( F_7 ( V_8 ) , V_4 -> V_14 + V_15 ) ;
}
static void F_8 ( struct V_10 * V_11 )
{
struct V_12 * V_4 = F_4 ( V_11 ) ;
int V_8 = F_5 ( V_11 ) ;
F_1 ( & V_4 -> V_13 [ V_8 ] , L_3 ) ;
F_6 ( F_7 ( V_8 ) , V_4 -> V_14 + V_16 ) ;
}
static int F_9 ( struct V_10 * V_11 , unsigned int type )
{
struct V_12 * V_4 = F_4 ( V_11 ) ;
int V_8 = F_5 ( V_11 ) ;
unsigned char V_17 = V_18 [ type & V_19 ] ;
unsigned long V_20 ;
F_1 ( & V_4 -> V_13 [ V_8 ] , L_4 ) ;
if ( ! ( V_17 & V_21 ) )
return - V_22 ;
V_20 = F_10 ( V_4 -> V_23 + F_11 ( V_8 ) ) ;
V_20 &= ~ 0x3f ;
V_20 |= V_17 ^ V_21 ;
F_6 ( V_20 , V_4 -> V_23 + F_11 ( V_8 ) ) ;
return 0 ;
}
static T_1 F_12 ( int V_13 , void * V_24 )
{
struct V_1 * V_2 = V_24 ;
struct V_12 * V_4 = V_2 -> V_4 ;
unsigned long V_25 = F_7 ( V_2 -> V_8 ) ;
F_1 ( V_2 , L_5 ) ;
if ( F_10 ( V_4 -> V_23 + V_26 ) & V_25 ) {
F_6 ( V_25 , V_4 -> V_23 + V_26 ) ;
F_1 ( V_2 , L_6 ) ;
F_13 ( V_2 -> V_9 ) ;
return V_27 ;
}
return V_28 ;
}
static int F_14 ( struct V_29 * V_30 , unsigned int V_31 ,
T_2 V_32 )
{
struct V_12 * V_4 = V_30 -> V_33 ;
V_4 -> V_13 [ V_32 ] . V_9 = V_31 ;
V_4 -> V_13 [ V_32 ] . V_8 = V_32 ;
F_1 ( & V_4 -> V_13 [ V_32 ] , L_7 ) ;
F_15 ( V_31 , V_30 -> V_33 ) ;
F_16 ( V_31 , & V_4 -> V_34 , V_35 ) ;
F_17 ( V_31 , V_36 ) ;
return 0 ;
}
static int F_18 ( struct V_37 * V_5 )
{
struct V_38 * V_39 = V_5 -> V_6 . V_40 ;
struct V_12 * V_4 ;
struct V_41 * V_42 ;
struct V_41 * V_13 ;
struct V_34 * V_34 ;
const char * V_43 = F_19 ( & V_5 -> V_6 ) ;
int V_44 ;
int V_45 ;
V_4 = F_20 ( sizeof( * V_4 ) , V_46 ) ;
if ( ! V_4 ) {
F_21 ( & V_5 -> V_6 , L_8 ) ;
V_44 = - V_47 ;
goto V_48;
}
if ( V_39 )
memcpy ( & V_4 -> V_49 , V_39 , sizeof( * V_39 ) ) ;
V_4 -> V_5 = V_5 ;
F_22 ( V_5 , V_4 ) ;
V_42 = F_23 ( V_5 , V_50 , 0 ) ;
if ( ! V_42 ) {
F_21 ( & V_5 -> V_6 , L_9 ) ;
V_44 = - V_22 ;
goto V_51;
}
for ( V_45 = 0 ; V_45 < V_52 ; V_45 ++ ) {
V_13 = F_23 ( V_5 , V_53 , V_45 ) ;
if ( ! V_13 )
break;
V_4 -> V_13 [ V_45 ] . V_4 = V_4 ;
V_4 -> V_13 [ V_45 ] . V_7 = V_13 -> V_54 ;
}
V_4 -> V_55 = V_45 ;
if ( V_4 -> V_55 < 1 ) {
F_21 ( & V_5 -> V_6 , L_10 ) ;
V_44 = - V_22 ;
goto V_51;
}
V_4 -> V_23 = F_24 ( V_42 -> V_54 , F_25 ( V_42 ) ) ;
if ( ! V_4 -> V_23 ) {
F_21 ( & V_5 -> V_6 , L_11 ) ;
V_44 = - V_56 ;
goto V_57;
}
V_4 -> V_14 = V_4 -> V_23 + F_26 ( 0 ) ;
V_34 = & V_4 -> V_34 ;
V_34 -> V_43 = V_43 ;
V_34 -> V_58 = F_8 ;
V_34 -> V_59 = F_3 ;
V_34 -> V_60 = F_3 ;
V_34 -> V_61 = F_8 ;
V_34 -> V_62 = F_9 ;
V_34 -> V_63 = V_64 ;
V_4 -> V_29 = F_27 ( V_5 -> V_6 . V_65 ,
V_4 -> V_55 ,
V_4 -> V_49 . V_66 ,
& V_67 , V_4 ) ;
if ( ! V_4 -> V_29 ) {
V_44 = - V_56 ;
F_21 ( & V_5 -> V_6 , L_12 ) ;
goto V_57;
}
for ( V_45 = 0 ; V_45 < V_4 -> V_55 ; V_45 ++ ) {
if ( F_28 ( V_4 -> V_13 [ V_45 ] . V_7 , F_12 ,
0 , V_43 , & V_4 -> V_13 [ V_45 ] ) ) {
F_21 ( & V_5 -> V_6 , L_13 ) ;
V_44 = - V_68 ;
goto V_69;
}
}
F_29 ( & V_5 -> V_6 , L_14 , V_4 -> V_55 ) ;
if ( V_4 -> V_49 . V_66 ) {
if ( V_4 -> V_49 . V_66 != V_4 -> V_13 [ 0 ] . V_9 )
F_30 ( & V_5 -> V_6 , L_15 ,
V_4 -> V_49 . V_66 , V_4 -> V_13 [ 0 ] . V_9 ) ;
}
return 0 ;
V_69:
for (; V_45 >= 0 ; V_45 -- )
F_31 ( V_4 -> V_13 [ V_45 - 1 ] . V_7 , & V_4 -> V_13 [ V_45 - 1 ] ) ;
F_32 ( V_4 -> V_29 ) ;
V_57:
F_33 ( V_4 -> V_23 ) ;
V_51:
F_34 ( V_4 ) ;
V_48:
return V_44 ;
}
static int F_35 ( struct V_37 * V_5 )
{
struct V_12 * V_4 = F_36 ( V_5 ) ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_4 -> V_55 ; V_45 ++ )
F_31 ( V_4 -> V_13 [ V_45 ] . V_7 , & V_4 -> V_13 [ V_45 ] ) ;
F_32 ( V_4 -> V_29 ) ;
F_33 ( V_4 -> V_23 ) ;
F_34 ( V_4 ) ;
return 0 ;
}
static int T_3 F_37 ( void )
{
return F_38 ( & V_70 ) ;
}
static void T_4 F_39 ( void )
{
F_40 ( & V_70 ) ;
}
