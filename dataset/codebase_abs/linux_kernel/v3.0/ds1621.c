static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
return F_3 ( V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_5 )
{
return F_5 ( V_2 , V_3 , F_3 ( V_5 ) ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 V_6 , V_7 ;
V_7 = V_6 = F_7 ( V_2 , V_8 ) ;
V_7 &= ~ V_9 ;
if ( V_10 == 0 )
V_7 &= ~ V_11 ;
else if ( V_10 == 1 )
V_7 |= V_11 ;
if ( V_6 != V_7 )
F_8 ( V_2 , V_8 , V_7 ) ;
F_9 ( V_2 , V_12 ) ;
}
static struct V_13 * F_10 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_11 ( V_15 ) ;
struct V_13 * V_16 = F_12 ( V_2 ) ;
T_1 V_7 ;
F_13 ( & V_16 -> V_17 ) ;
if ( F_14 ( V_18 , V_16 -> V_19 + V_20 + V_20 / 2 )
|| ! V_16 -> V_21 ) {
int V_22 ;
F_15 ( & V_2 -> V_15 , L_1 ) ;
V_16 -> V_6 = F_7 ( V_2 , V_8 ) ;
for ( V_22 = 0 ; V_22 < F_16 ( V_16 -> V_23 ) ; V_22 ++ )
V_16 -> V_23 [ V_22 ] = F_1 ( V_2 ,
V_24 [ V_22 ] ) ;
V_7 = V_16 -> V_6 ;
if ( V_16 -> V_23 [ 0 ] > V_16 -> V_23 [ 1 ] )
V_7 &= ~ V_25 ;
if ( V_16 -> V_23 [ 0 ] < V_16 -> V_23 [ 2 ] )
V_7 &= ~ V_26 ;
if ( V_16 -> V_6 != V_7 )
F_8 ( V_2 , V_8 ,
V_7 ) ;
V_16 -> V_19 = V_18 ;
V_16 -> V_21 = 1 ;
}
F_17 ( & V_16 -> V_17 ) ;
return V_16 ;
}
static T_3 F_18 ( struct V_14 * V_15 , struct V_27 * V_28 ,
char * V_29 )
{
struct V_30 * V_31 = F_19 ( V_28 ) ;
struct V_13 * V_16 = F_10 ( V_15 ) ;
return sprintf ( V_29 , L_2 ,
F_20 ( V_16 -> V_23 [ V_31 -> V_32 ] ) ) ;
}
static T_3 F_21 ( struct V_14 * V_15 , struct V_27 * V_28 ,
const char * V_29 , T_4 V_33 )
{
struct V_30 * V_31 = F_19 ( V_28 ) ;
struct V_1 * V_2 = F_11 ( V_15 ) ;
struct V_13 * V_16 = F_12 ( V_2 ) ;
T_2 V_34 = F_22 ( F_23 ( V_29 , NULL , 10 ) ) ;
F_13 ( & V_16 -> V_17 ) ;
V_16 -> V_23 [ V_31 -> V_32 ] = V_34 ;
F_4 ( V_2 , V_24 [ V_31 -> V_32 ] ,
V_16 -> V_23 [ V_31 -> V_32 ] ) ;
F_17 ( & V_16 -> V_17 ) ;
return V_33 ;
}
static T_3 F_24 ( struct V_14 * V_15 , struct V_27 * V_28 ,
char * V_29 )
{
struct V_13 * V_16 = F_10 ( V_15 ) ;
return sprintf ( V_29 , L_2 , F_25 ( V_16 -> V_6 ) ) ;
}
static T_3 F_26 ( struct V_14 * V_15 , struct V_27 * V_28 ,
char * V_29 )
{
struct V_30 * V_31 = F_19 ( V_28 ) ;
struct V_13 * V_16 = F_10 ( V_15 ) ;
return sprintf ( V_29 , L_2 , ! ! ( V_16 -> V_6 & V_31 -> V_32 ) ) ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
int V_6 , V_23 ;
int V_22 ;
if ( ! F_28 ( V_38 , V_39
| V_40
| V_41 ) )
return - V_42 ;
V_6 = F_7 ( V_2 , V_8 ) ;
if ( V_6 < 0 || V_6 & V_43 )
return - V_42 ;
for ( V_22 = 0 ; V_22 < F_16 ( V_24 ) ; V_22 ++ ) {
V_23 = F_2 ( V_2 , V_24 [ V_22 ] ) ;
if ( V_23 < 0 || ( V_23 & 0x7f00 ) )
return - V_42 ;
}
F_29 ( V_36 -> type , L_3 , V_44 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
const struct V_45 * V_46 )
{
struct V_13 * V_16 ;
int V_47 ;
V_16 = F_31 ( sizeof( struct V_13 ) , V_48 ) ;
if ( ! V_16 ) {
V_47 = - V_49 ;
goto exit;
}
F_32 ( V_2 , V_16 ) ;
F_33 ( & V_16 -> V_17 ) ;
F_6 ( V_2 ) ;
if ( ( V_47 = F_34 ( & V_2 -> V_15 . V_50 , & V_51 ) ) )
goto V_52;
V_16 -> V_53 = F_35 ( & V_2 -> V_15 ) ;
if ( F_36 ( V_16 -> V_53 ) ) {
V_47 = F_37 ( V_16 -> V_53 ) ;
goto V_54;
}
return 0 ;
V_54:
F_38 ( & V_2 -> V_15 . V_50 , & V_51 ) ;
V_52:
F_39 ( V_16 ) ;
exit:
return V_47 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_13 * V_16 = F_12 ( V_2 ) ;
F_41 ( V_16 -> V_53 ) ;
F_38 ( & V_2 -> V_15 . V_50 , & V_51 ) ;
F_39 ( V_16 ) ;
return 0 ;
}
static int T_5 F_42 ( void )
{
return F_43 ( & V_55 ) ;
}
static void T_6 F_44 ( void )
{
F_45 ( & V_55 ) ;
}
