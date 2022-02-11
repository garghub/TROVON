static inline T_1 F_1 ( int V_1 )
{
T_1 V_2 = ( ( ( V_1 >> 1 ) | ( V_1 & 0x01 ) << 2 ) << 4 ) ;
V_2 |= V_3 ;
return V_2 ;
}
static struct V_4 * F_2 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_4 * V_9 = F_4 ( V_8 ) ;
F_5 ( & V_9 -> V_10 ) ;
if ( F_6 ( V_11 , V_9 -> V_12 + V_13 + V_13 / 2 )
|| ! V_9 -> V_14 ) {
unsigned int V_1 ;
F_7 ( & V_8 -> V_6 , L_1 ) ;
for ( V_1 = 0 ; V_1 < V_15 ; V_1 ++ ) {
T_1 V_2 = F_1 ( V_1 ) ;
V_9 -> V_16 [ V_1 ] =
F_8 ( V_8 , V_2 ) ;
}
V_9 -> V_12 = V_11 ;
V_9 -> V_14 = 1 ;
}
F_9 ( & V_9 -> V_10 ) ;
return V_9 ;
}
static T_2 F_10 ( struct V_5 * V_6 , struct V_17 * V_18 ,
char * V_19 )
{
struct V_20 * V_21 = F_11 ( V_18 ) ;
struct V_4 * V_9 = F_2 ( V_6 ) ;
return sprintf ( V_19 , L_2 , ( V_9 -> V_16 [ V_21 -> V_22 ] *
V_23 ) / 1000 ) ;
}
static int F_12 ( struct V_7 * V_8 )
{
struct V_4 * V_9 = F_4 ( V_8 ) ;
F_13 ( V_9 -> V_24 ) ;
F_14 ( & V_8 -> V_6 . V_25 , & V_26 ) ;
return 0 ;
}
static int F_15 ( struct V_7 * V_8 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 = V_8 -> V_30 ;
int V_1 ;
if ( ! F_16 ( V_30 , V_31 ) )
return - V_32 ;
for ( V_1 = 0 ; V_1 < V_15 ; V_1 ++ ) {
T_3 V_33 ;
T_1 V_2 = F_1 ( V_1 ) ;
V_33 = F_8 ( V_8 , V_2 ) ;
if ( V_33 & 0xF000 ) {
F_17 ( L_3 ,
V_34 ) ;
return - V_32 ;
}
}
F_18 ( V_28 -> type , L_4 , V_35 ) ;
return 0 ;
}
static int F_19 ( struct V_7 * V_8 ,
const struct V_36 * V_37 )
{
struct V_4 * V_9 ;
int V_38 ;
V_9 = F_20 ( & V_8 -> V_6 , sizeof( struct V_4 ) ,
V_39 ) ;
if ( ! V_9 )
return - V_40 ;
F_21 ( V_8 , V_9 ) ;
F_22 ( & V_9 -> V_10 ) ;
V_38 = F_23 ( & V_8 -> V_6 . V_25 , & V_26 ) ;
if ( V_38 )
return V_38 ;
V_9 -> V_24 = F_24 ( & V_8 -> V_6 ) ;
if ( F_25 ( V_9 -> V_24 ) ) {
V_38 = F_26 ( V_9 -> V_24 ) ;
goto V_41;
}
return 0 ;
V_41:
F_14 ( & V_8 -> V_6 . V_25 , & V_26 ) ;
return V_38 ;
}
static int T_4 F_27 ( void )
{
V_3 = V_42 ?
V_43 : V_44 ;
V_3 |= V_45 ?
V_46 : V_47 ;
V_23 = ( V_48 * 1000 ) / 4096 ;
return F_28 ( & V_49 ) ;
}
static void T_5 F_29 ( void )
{
F_30 ( & V_49 ) ;
}
