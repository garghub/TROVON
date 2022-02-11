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
if ( ! V_17 )
return - V_21 ;
V_20 = F_10 ( V_4 -> V_22 + F_11 ( V_8 ) ) ;
V_20 &= ~ 0x3f ;
V_20 |= V_17 ;
F_6 ( V_20 , V_4 -> V_22 + F_11 ( V_8 ) ) ;
return 0 ;
}
static T_1 F_12 ( int V_13 , void * V_23 )
{
struct V_1 * V_2 = V_23 ;
struct V_12 * V_4 = V_2 -> V_4 ;
unsigned long V_24 = F_7 ( V_2 -> V_8 ) ;
F_1 ( V_2 , L_5 ) ;
if ( F_10 ( V_4 -> V_22 + V_25 ) & V_24 ) {
F_6 ( V_24 , V_4 -> V_22 + V_25 ) ;
F_1 ( V_2 , L_6 ) ;
F_13 ( V_2 -> V_9 ) ;
return V_26 ;
}
return V_27 ;
}
static int F_14 ( struct V_28 * V_29 , unsigned int V_30 ,
T_2 V_31 )
{
struct V_12 * V_4 = V_29 -> V_32 ;
V_4 -> V_13 [ V_31 ] . V_9 = V_30 ;
V_4 -> V_13 [ V_31 ] . V_8 = V_31 ;
F_1 ( & V_4 -> V_13 [ V_31 ] , L_7 ) ;
F_15 ( V_30 , V_29 -> V_32 ) ;
F_16 ( V_30 , & V_4 -> V_33 , V_34 ) ;
F_17 ( V_30 , V_35 ) ;
return 0 ;
}
static int F_18 ( struct V_36 * V_5 )
{
struct V_37 * V_38 = V_5 -> V_6 . V_39 ;
struct V_12 * V_4 ;
struct V_40 * V_41 ;
struct V_40 * V_13 ;
struct V_33 * V_33 ;
const char * V_42 = F_19 ( & V_5 -> V_6 ) ;
int V_43 ;
int V_44 ;
V_4 = F_20 ( sizeof( * V_4 ) , V_45 ) ;
if ( ! V_4 ) {
F_21 ( & V_5 -> V_6 , L_8 ) ;
V_43 = - V_46 ;
goto V_47;
}
if ( V_38 )
memcpy ( & V_4 -> V_48 , V_38 , sizeof( * V_38 ) ) ;
V_4 -> V_5 = V_5 ;
F_22 ( V_5 , V_4 ) ;
V_41 = F_23 ( V_5 , V_49 , 0 ) ;
if ( ! V_41 ) {
F_21 ( & V_5 -> V_6 , L_9 ) ;
V_43 = - V_21 ;
goto V_50;
}
for ( V_44 = 0 ; V_44 < V_51 ; V_44 ++ ) {
V_13 = F_23 ( V_5 , V_52 , V_44 ) ;
if ( ! V_13 )
break;
V_4 -> V_13 [ V_44 ] . V_4 = V_4 ;
V_4 -> V_13 [ V_44 ] . V_7 = V_13 -> V_53 ;
}
V_4 -> V_54 = V_44 ;
if ( V_4 -> V_54 < 1 ) {
F_21 ( & V_5 -> V_6 , L_10 ) ;
V_43 = - V_21 ;
goto V_50;
}
V_4 -> V_22 = F_24 ( V_41 -> V_53 , F_25 ( V_41 ) ) ;
if ( ! V_4 -> V_22 ) {
F_21 ( & V_5 -> V_6 , L_11 ) ;
V_43 = - V_55 ;
goto V_56;
}
V_4 -> V_14 = V_4 -> V_22 + F_26 ( 0 ) ;
V_33 = & V_4 -> V_33 ;
V_33 -> V_42 = V_42 ;
V_33 -> V_57 = F_8 ;
V_33 -> V_58 = F_3 ;
V_33 -> V_59 = F_9 ;
V_33 -> V_60 = V_61 | V_62 ;
V_4 -> V_28 = F_27 ( V_5 -> V_6 . V_63 ,
V_4 -> V_54 ,
V_4 -> V_48 . V_64 ,
& V_65 , V_4 ) ;
if ( ! V_4 -> V_28 ) {
V_43 = - V_55 ;
F_21 ( & V_5 -> V_6 , L_12 ) ;
goto V_56;
}
for ( V_44 = 0 ; V_44 < V_4 -> V_54 ; V_44 ++ ) {
if ( F_28 ( V_4 -> V_13 [ V_44 ] . V_7 , F_12 ,
0 , V_42 , & V_4 -> V_13 [ V_44 ] ) ) {
F_21 ( & V_5 -> V_6 , L_13 ) ;
V_43 = - V_66 ;
goto V_67;
}
}
F_29 ( & V_5 -> V_6 , L_14 , V_4 -> V_54 ) ;
if ( V_4 -> V_48 . V_64 ) {
if ( V_4 -> V_48 . V_64 != V_4 -> V_13 [ 0 ] . V_9 )
F_30 ( & V_5 -> V_6 , L_15 ,
V_4 -> V_48 . V_64 , V_4 -> V_13 [ 0 ] . V_9 ) ;
}
return 0 ;
V_67:
while ( -- V_44 >= 0 )
F_31 ( V_4 -> V_13 [ V_44 ] . V_7 , & V_4 -> V_13 [ V_44 ] ) ;
F_32 ( V_4 -> V_28 ) ;
V_56:
F_33 ( V_4 -> V_22 ) ;
V_50:
F_34 ( V_4 ) ;
V_47:
return V_43 ;
}
static int F_35 ( struct V_36 * V_5 )
{
struct V_12 * V_4 = F_36 ( V_5 ) ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_4 -> V_54 ; V_44 ++ )
F_31 ( V_4 -> V_13 [ V_44 ] . V_7 , & V_4 -> V_13 [ V_44 ] ) ;
F_32 ( V_4 -> V_28 ) ;
F_33 ( V_4 -> V_22 ) ;
F_34 ( V_4 ) ;
return 0 ;
}
static int T_3 F_37 ( void )
{
return F_38 ( & V_68 ) ;
}
static void T_4 F_39 ( void )
{
F_40 ( & V_68 ) ;
}
