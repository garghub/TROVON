static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 ,
F_4 ( V_9 -> V_10 [ V_7 -> V_11 ] ) ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_13 * V_14 = F_6 ( V_2 ) ;
struct V_8 * V_9 = F_7 ( V_14 ) ;
int V_15 = V_7 -> V_11 ;
long V_10 ;
int error ;
error = F_8 ( V_5 , 10 , & V_10 ) ;
if ( error )
return error ;
F_9 ( & V_9 -> V_16 ) ;
V_9 -> V_10 [ V_15 ] = F_10 ( V_10 ) ;
F_11 ( V_14 , V_17 [ V_15 ] , V_9 -> V_10 [ V_15 ] ) ;
F_12 ( & V_9 -> V_16 ) ;
return V_12 ;
}
static int
F_13 ( struct V_13 * V_14 , const struct V_18 * V_19 )
{
struct V_8 * V_9 ;
int V_20 ;
T_3 V_21 , V_22 ;
int V_23 ;
if ( ! F_14 ( V_14 -> V_24 ,
V_25 | V_26 ) )
return - V_27 ;
V_9 = F_15 ( sizeof( struct V_8 ) , V_28 ) ;
if ( ! V_9 )
return - V_29 ;
F_16 ( V_14 , V_9 ) ;
F_17 ( & V_9 -> V_16 ) ;
V_21 = 0 ;
V_22 = ( 1 << 0 )
| ( 1 << 6 ) | ( 1 << 5 ) ;
V_20 = F_18 ( V_14 , V_30 ) ;
if ( V_20 < 0 ) {
F_19 ( & V_14 -> V_2 , L_2 , V_20 ) ;
goto V_31;
}
V_9 -> V_32 = V_20 ;
V_23 = V_20 & ~ V_22 ;
V_23 |= V_21 ;
if ( V_20 != V_23 )
F_11 ( V_14 , V_30 , V_23 ) ;
F_19 ( & V_14 -> V_2 , L_3 , V_23 ) ;
V_20 = F_20 ( & V_14 -> V_2 . V_33 , & V_34 ) ;
if ( V_20 )
goto V_31;
V_9 -> V_35 = F_21 ( & V_14 -> V_2 ) ;
if ( F_22 ( V_9 -> V_35 ) ) {
V_20 = F_23 ( V_9 -> V_35 ) ;
goto V_36;
}
F_24 ( & V_14 -> V_2 , L_4 ,
F_25 ( V_9 -> V_35 ) , V_14 -> V_37 ) ;
return 0 ;
V_36:
F_26 ( & V_14 -> V_2 . V_33 , & V_34 ) ;
V_31:
F_27 ( V_9 ) ;
return V_20 ;
}
static int F_28 ( struct V_13 * V_14 )
{
struct V_8 * V_9 = F_7 ( V_14 ) ;
F_29 ( V_9 -> V_35 ) ;
F_26 ( & V_14 -> V_2 . V_33 , & V_34 ) ;
F_11 ( V_14 , V_30 , V_9 -> V_32 ) ;
F_27 ( V_9 ) ;
return 0 ;
}
static int F_30 ( struct V_13 * V_38 ,
struct V_39 * V_40 )
{
struct V_41 * V_24 = V_38 -> V_24 ;
int V_42 ;
int V_43 , V_44 , V_45 ;
bool V_46 = 0 ;
if ( ! F_14 ( V_24 , V_25 |
V_26 ) )
return - V_47 ;
V_43 = F_31 ( V_38 , 1 ) ;
if ( V_43 & 0xe0 )
return - V_47 ;
if ( F_31 ( V_38 , 7 ) == V_48 ) {
if ( F_31 ( V_38 , 4 ) != 0xff
|| F_31 ( V_38 , 5 ) != 0xff
|| F_31 ( V_38 , 6 ) != 0xff )
return - V_47 ;
V_46 = 1 ;
V_44 = F_31 ( V_38 , 2 ) ;
V_45 = F_31 ( V_38 , 3 ) ;
} else {
V_44 = F_31 ( V_38 , 2 ) ;
if ( F_31 ( V_38 , 4 ) != V_44
|| F_31 ( V_38 , 5 ) != V_44
|| F_31 ( V_38 , 6 ) != V_44
|| F_31 ( V_38 , 7 ) != V_44 )
return - V_47 ;
V_45 = F_31 ( V_38 , 3 ) ;
if ( F_31 ( V_38 , 4 ) != V_45
|| F_31 ( V_38 , 5 ) != V_45
|| F_31 ( V_38 , 6 ) != V_45
|| F_31 ( V_38 , 7 ) != V_45 )
return - V_47 ;
}
for ( V_42 = 8 ; V_42 <= 248 ; V_42 += 40 ) {
if ( F_31 ( V_38 , V_42 + 1 ) != V_43
|| F_31 ( V_38 , V_42 + 2 ) != V_44
|| F_31 ( V_38 , V_42 + 3 ) != V_45 )
return - V_47 ;
if ( V_46 && F_31 ( V_38 , V_42 + 7 )
!= V_48 )
return - V_47 ;
}
F_32 ( V_40 -> type , V_46 ? L_5 : L_6 , V_49 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_20 ;
struct V_13 * V_14 = F_6 ( V_2 ) ;
V_20 = F_18 ( V_14 , V_30 ) ;
if ( V_20 < 0 ) {
F_19 ( & V_14 -> V_2 , L_2 , V_20 ) ;
return V_20 ;
}
V_20 = V_20 | V_50 ;
F_11 ( V_14 , V_30 , V_20 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_20 ;
struct V_13 * V_14 = F_6 ( V_2 ) ;
V_20 = F_18 ( V_14 , V_30 ) ;
if ( V_20 < 0 ) {
F_19 ( & V_14 -> V_2 , L_2 , V_20 ) ;
return V_20 ;
}
V_20 = V_20 & ~ V_50 ;
F_11 ( V_14 , V_30 , V_20 ) ;
return 0 ;
}
static int F_18 ( struct V_13 * V_14 , T_3 V_51 )
{
if ( V_51 == V_30 )
return F_31 ( V_14 , V_51 ) ;
else
return F_35 ( V_14 , V_51 ) ;
}
static int F_11 ( struct V_13 * V_14 , T_3 V_51 , T_4 V_52 )
{
if ( V_51 == V_30 )
return F_36 ( V_14 , V_51 , V_52 ) ;
else
return F_37 ( V_14 , V_51 , V_52 ) ;
}
static struct V_8 * F_3 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_6 ( V_2 ) ;
struct V_8 * V_9 = F_7 ( V_14 ) ;
F_9 ( & V_9 -> V_16 ) ;
if ( F_38 ( V_53 , V_9 -> V_54 + V_55 + V_55 / 2 )
|| ! V_9 -> V_56 ) {
int V_42 ;
F_19 ( & V_14 -> V_2 , L_7 ) ;
for ( V_42 = 0 ; V_42 < F_39 ( V_9 -> V_10 ) ; V_42 ++ ) {
int V_20 ;
V_20 = F_18 ( V_14 , V_17 [ V_42 ] ) ;
if ( V_20 < 0 )
F_19 ( & V_14 -> V_2 , L_8 ,
V_17 [ V_42 ] , V_20 ) ;
else
V_9 -> V_10 [ V_42 ] = V_20 ;
}
V_9 -> V_54 = V_53 ;
V_9 -> V_56 = 1 ;
}
F_12 ( & V_9 -> V_16 ) ;
return V_9 ;
}
static int T_5 F_40 ( void )
{
return F_41 ( & V_57 ) ;
}
static void T_6 F_42 ( void )
{
F_43 ( & V_57 ) ;
}
