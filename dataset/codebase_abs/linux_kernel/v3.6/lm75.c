static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
if ( F_4 ( V_9 ) )
return F_5 ( V_9 ) ;
return sprintf ( V_5 , L_1 ,
F_6 ( V_9 -> V_10 [ V_7 -> V_11 ] ) ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_13 * V_14 = F_8 ( V_2 ) ;
struct V_8 * V_9 = F_9 ( V_14 ) ;
int V_15 = V_7 -> V_11 ;
long V_10 ;
int error ;
error = F_10 ( V_5 , 10 , & V_10 ) ;
if ( error )
return error ;
F_11 ( & V_9 -> V_16 ) ;
V_9 -> V_10 [ V_15 ] = F_12 ( V_10 ) ;
F_13 ( V_14 , V_17 [ V_15 ] , V_9 -> V_10 [ V_15 ] ) ;
F_14 ( & V_9 -> V_16 ) ;
return V_12 ;
}
static int
F_15 ( struct V_13 * V_14 , const struct V_18 * V_19 )
{
struct V_8 * V_9 ;
int V_20 ;
T_3 V_21 , V_22 ;
int V_23 ;
if ( ! F_16 ( V_14 -> V_24 ,
V_25 | V_26 ) )
return - V_27 ;
V_9 = F_17 ( & V_14 -> V_2 , sizeof( struct V_8 ) , V_28 ) ;
if ( ! V_9 )
return - V_29 ;
F_18 ( V_14 , V_9 ) ;
F_19 ( & V_9 -> V_16 ) ;
V_21 = 0 ;
V_22 = ( 1 << 0 )
| ( 1 << 6 ) | ( 1 << 5 ) ;
V_20 = F_20 ( V_14 , V_30 ) ;
if ( V_20 < 0 ) {
F_21 ( & V_14 -> V_2 , L_2 , V_20 ) ;
return V_20 ;
}
V_9 -> V_31 = V_20 ;
V_23 = V_20 & ~ V_22 ;
V_23 |= V_21 ;
if ( V_20 != V_23 )
F_13 ( V_14 , V_30 , V_23 ) ;
F_21 ( & V_14 -> V_2 , L_3 , V_23 ) ;
V_20 = F_22 ( & V_14 -> V_2 . V_32 , & V_33 ) ;
if ( V_20 )
return V_20 ;
V_9 -> V_34 = F_23 ( & V_14 -> V_2 ) ;
if ( F_4 ( V_9 -> V_34 ) ) {
V_20 = F_5 ( V_9 -> V_34 ) ;
goto V_35;
}
F_24 ( & V_14 -> V_2 , L_4 ,
F_25 ( V_9 -> V_34 ) , V_14 -> V_36 ) ;
return 0 ;
V_35:
F_26 ( & V_14 -> V_2 . V_32 , & V_33 ) ;
return V_20 ;
}
static int F_27 ( struct V_13 * V_14 )
{
struct V_8 * V_9 = F_9 ( V_14 ) ;
F_28 ( V_9 -> V_34 ) ;
F_26 ( & V_14 -> V_2 . V_32 , & V_33 ) ;
F_13 ( V_14 , V_30 , V_9 -> V_31 ) ;
return 0 ;
}
static int F_29 ( struct V_13 * V_37 ,
struct V_38 * V_39 )
{
struct V_40 * V_24 = V_37 -> V_24 ;
int V_41 ;
int V_42 , V_43 , V_44 ;
bool V_45 = 0 ;
if ( ! F_16 ( V_24 , V_25 |
V_26 ) )
return - V_46 ;
V_42 = F_30 ( V_37 , 1 ) ;
if ( V_42 & 0xe0 )
return - V_46 ;
if ( F_30 ( V_37 , 7 ) == V_47 ) {
if ( F_30 ( V_37 , 4 ) != 0xff
|| F_30 ( V_37 , 5 ) != 0xff
|| F_30 ( V_37 , 6 ) != 0xff )
return - V_46 ;
V_45 = 1 ;
V_43 = F_30 ( V_37 , 2 ) ;
V_44 = F_30 ( V_37 , 3 ) ;
} else {
V_43 = F_30 ( V_37 , 2 ) ;
if ( F_30 ( V_37 , 4 ) != V_43
|| F_30 ( V_37 , 5 ) != V_43
|| F_30 ( V_37 , 6 ) != V_43
|| F_30 ( V_37 , 7 ) != V_43 )
return - V_46 ;
V_44 = F_30 ( V_37 , 3 ) ;
if ( F_30 ( V_37 , 4 ) != V_44
|| F_30 ( V_37 , 5 ) != V_44
|| F_30 ( V_37 , 6 ) != V_44
|| F_30 ( V_37 , 7 ) != V_44 )
return - V_46 ;
}
for ( V_41 = 8 ; V_41 <= 248 ; V_41 += 40 ) {
if ( F_30 ( V_37 , V_41 + 1 ) != V_42
|| F_30 ( V_37 , V_41 + 2 ) != V_43
|| F_30 ( V_37 , V_41 + 3 ) != V_44 )
return - V_46 ;
if ( V_45 && F_30 ( V_37 , V_41 + 7 )
!= V_47 )
return - V_46 ;
}
F_31 ( V_39 -> type , V_45 ? L_5 : L_6 , V_48 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_20 ;
struct V_13 * V_14 = F_8 ( V_2 ) ;
V_20 = F_20 ( V_14 , V_30 ) ;
if ( V_20 < 0 ) {
F_21 ( & V_14 -> V_2 , L_2 , V_20 ) ;
return V_20 ;
}
V_20 = V_20 | V_49 ;
F_13 ( V_14 , V_30 , V_20 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_20 ;
struct V_13 * V_14 = F_8 ( V_2 ) ;
V_20 = F_20 ( V_14 , V_30 ) ;
if ( V_20 < 0 ) {
F_21 ( & V_14 -> V_2 , L_2 , V_20 ) ;
return V_20 ;
}
V_20 = V_20 & ~ V_49 ;
F_13 ( V_14 , V_30 , V_20 ) ;
return 0 ;
}
static int F_20 ( struct V_13 * V_14 , T_3 V_50 )
{
if ( V_50 == V_30 )
return F_30 ( V_14 , V_50 ) ;
else
return F_34 ( V_14 , V_50 ) ;
}
static int F_13 ( struct V_13 * V_14 , T_3 V_50 , T_4 V_51 )
{
if ( V_50 == V_30 )
return F_35 ( V_14 , V_50 , V_51 ) ;
else
return F_36 ( V_14 , V_50 , V_51 ) ;
}
static struct V_8 * F_3 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_8 ( V_2 ) ;
struct V_8 * V_9 = F_9 ( V_14 ) ;
struct V_8 * V_52 = V_9 ;
F_11 ( & V_9 -> V_16 ) ;
if ( F_37 ( V_53 , V_9 -> V_54 + V_55 + V_55 / 2 )
|| ! V_9 -> V_56 ) {
int V_41 ;
F_21 ( & V_14 -> V_2 , L_7 ) ;
for ( V_41 = 0 ; V_41 < F_38 ( V_9 -> V_10 ) ; V_41 ++ ) {
int V_20 ;
V_20 = F_20 ( V_14 , V_17 [ V_41 ] ) ;
if ( F_39 ( V_20 < 0 ) ) {
F_21 ( V_2 ,
L_8 ,
V_17 [ V_41 ] , V_20 ) ;
V_52 = F_40 ( V_20 ) ;
V_9 -> V_56 = 0 ;
goto abort;
}
V_9 -> V_10 [ V_41 ] = V_20 ;
}
V_9 -> V_54 = V_53 ;
V_9 -> V_56 = 1 ;
}
abort:
F_14 ( & V_9 -> V_16 ) ;
return V_52 ;
}
