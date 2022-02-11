static T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( F_3 ( V_2 , V_3 ) ) ;
}
static inline T_2 F_4 ( int V_4 )
{
T_2 V_5 = ( ( ( V_4 >> 1 ) | ( V_4 & 0x01 ) << 2 ) << 4 ) ;
V_5 |= V_6 ;
return V_5 ;
}
static struct V_7 * F_5 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
struct V_7 * V_10 = F_7 ( V_2 ) ;
F_8 ( & V_10 -> V_11 ) ;
if ( F_9 ( V_12 , V_10 -> V_13 + V_14 + V_14 / 2 )
|| ! V_10 -> V_15 ) {
unsigned int V_4 ;
F_10 ( & V_2 -> V_9 , L_1 ) ;
for ( V_4 = 0 ; V_4 < V_16 ; V_4 ++ ) {
T_2 V_5 = F_4 ( V_4 ) ;
V_10 -> V_17 [ V_4 ] = F_1 ( V_2 , V_5 ) ;
}
V_10 -> V_13 = V_12 ;
V_10 -> V_15 = 1 ;
}
F_11 ( & V_10 -> V_11 ) ;
return V_10 ;
}
static T_3 F_12 ( struct V_8 * V_9 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_21 * V_22 = F_13 ( V_19 ) ;
struct V_7 * V_10 = F_5 ( V_9 ) ;
return sprintf ( V_20 , L_2 , ( V_10 -> V_17 [ V_22 -> V_23 ] *
V_24 ) / 1000 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_7 * V_10 = F_7 ( V_2 ) ;
F_15 ( V_10 -> V_25 ) ;
F_16 ( & V_2 -> V_9 . V_26 , & V_27 ) ;
F_17 ( F_7 ( V_2 ) ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_30 * V_31 = V_2 -> V_31 ;
int V_4 ;
if ( ! F_19 ( V_31 , V_32 ) )
return - V_33 ;
for ( V_4 = 0 ; V_4 < V_16 ; V_4 ++ ) {
T_1 V_34 ;
T_2 V_5 = F_4 ( V_4 ) ;
V_34 = F_1 ( V_2 , V_5 ) ;
if ( V_34 & 0xF000 ) {
F_20 ( L_3 ,
V_35 ) ;
return - V_33 ;
}
}
F_21 ( V_29 -> type , L_4 , V_36 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
const struct V_37 * V_38 )
{
struct V_7 * V_10 ;
int V_39 ;
V_10 = F_23 ( sizeof( struct V_7 ) , V_40 ) ;
if ( ! V_10 ) {
V_39 = - V_41 ;
goto exit;
}
F_24 ( V_2 , V_10 ) ;
F_25 ( & V_10 -> V_11 ) ;
V_39 = F_26 ( & V_2 -> V_9 . V_26 , & V_27 ) ;
if ( V_39 )
goto V_42;
V_10 -> V_25 = F_27 ( & V_2 -> V_9 ) ;
if ( F_28 ( V_10 -> V_25 ) ) {
V_39 = F_29 ( V_10 -> V_25 ) ;
goto V_43;
}
return 0 ;
V_43:
F_16 ( & V_2 -> V_9 . V_26 , & V_27 ) ;
V_42:
F_17 ( V_10 ) ;
exit:
return V_39 ;
}
static int T_4 F_30 ( void )
{
V_6 = V_44 ?
V_45 : V_46 ;
V_6 |= V_47 ?
V_48 : V_49 ;
V_24 = ( V_50 * 1000 ) / 4096 ;
return F_31 ( & V_51 ) ;
}
static void T_5 F_32 ( void )
{
F_33 ( & V_51 ) ;
}
