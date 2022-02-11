static inline int F_1 ( T_1 V_1 )
{
return ( ( int ) V_1 / 64 ) * 250 ;
}
static inline int F_2 ( struct V_2 * V_3 , T_2 V_1 )
{
if ( V_1 == V_4 ) {
int V_5 = F_3 ( V_3 , V_1 ) ;
return ( V_5 < 0 ) ? V_5 : F_4 ( V_5 ) ;
} else
return F_5 ( V_3 , V_1 ) ;
}
static inline int F_6 ( struct V_2 * V_3 , T_2 V_1 , T_2 V_5 )
{
return F_7 ( V_3 , V_1 , V_5 ) ;
}
static struct V_6 * F_8 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_9 ( V_8 ) ;
struct V_6 * V_9 = F_10 ( V_3 ) ;
F_11 ( & V_9 -> V_10 ) ;
if ( F_12 ( V_11 , V_9 -> V_12 ) || ! V_9 -> V_13 ) {
int V_5 , V_14 ;
F_13 ( & V_3 -> V_8 , L_1 ) ;
V_5 = F_2 ( V_3 , V_4 ) ;
if ( V_5 < 0 )
F_13 ( & V_3 -> V_8 , L_2 ,
V_5 ) ;
else
V_9 -> V_15 = V_5 ;
for ( V_14 = 0 ; V_14 < F_14 ( V_16 ) ; ++ V_14 ) {
V_5 = F_2 ( V_3 , V_16 [ V_14 ] ) ;
if ( V_5 < 0 )
F_13 ( & V_3 -> V_8 , L_3 ,
V_16 [ V_14 ] , V_5 ) ;
else
V_9 -> V_17 [ V_14 ] = V_5 ;
}
V_9 -> V_12 = V_11 + V_18 + V_18 / 2 ;
V_9 -> V_13 = 1 ;
}
F_15 ( & V_9 -> V_10 ) ;
return V_9 ;
}
static T_3 F_16 ( struct V_7 * V_8 ,
struct V_19 * V_20 , char * V_21 )
{
struct V_6 * V_9 = F_8 ( V_8 ) ;
return sprintf ( V_21 , L_4 , F_1 ( V_9 -> V_15 ) ) ;
}
static T_3 F_17 ( struct V_7 * V_8 , struct V_19 * V_20 ,
char * V_21 )
{
int V_22 = F_18 ( V_20 ) -> V_22 ;
struct V_6 * V_9 = F_8 ( V_8 ) ;
return sprintf ( V_21 , L_4 , V_9 -> V_17 [ V_22 ] * 1000 ) ;
}
static T_3 F_19 ( struct V_7 * V_8 ,
struct V_19 * V_20 ,
const char * V_21 , T_4 V_23 )
{
struct V_2 * V_3 = F_9 ( V_8 ) ;
struct V_6 * V_9 = F_10 ( V_3 ) ;
int V_22 = F_18 ( V_20 ) -> V_22 ;
T_2 V_1 = V_16 [ V_22 ] ;
long V_24 = F_20 ( V_21 , NULL , 10 ) ;
V_24 = F_21 ( V_24 , - 40000 , 85000 ) ;
V_24 = ( V_24 + ( V_24 < 0 ? - 500 : 500 ) ) / 1000 ;
F_11 ( & V_9 -> V_10 ) ;
V_9 -> V_17 [ V_22 ] = V_24 ;
F_6 ( V_3 , V_1 , V_24 ) ;
F_15 ( & V_9 -> V_10 ) ;
return V_23 ;
}
static T_3 F_22 ( struct V_7 * V_8 , struct V_19 * V_20 ,
char * V_21 )
{
int V_25 = F_18 ( V_20 ) -> V_22 ;
struct V_6 * V_9 = F_8 ( V_8 ) ;
int V_5 = ( V_9 -> V_15 >> V_25 ) & 1 ;
return sprintf ( V_21 , L_4 , V_5 ) ;
}
static int F_23 ( struct V_2 * V_3 ,
const struct V_26 * V_27 )
{
struct V_6 * V_9 ;
int V_28 ;
int V_29 ;
if ( ! F_24 ( V_3 -> V_30 , V_31 |
V_32 ) ) {
V_29 = - V_33 ;
goto exit;
}
V_9 = F_25 ( sizeof( struct V_6 ) , V_34 ) ;
if ( ! V_9 ) {
V_29 = - V_35 ;
goto exit;
}
F_26 ( V_3 , V_9 ) ;
F_27 ( & V_9 -> V_10 ) ;
F_28 ( & V_3 -> V_8 , L_5 ) ;
V_28 = F_5 ( V_3 , V_36 ) ;
if ( V_28 < 0 )
F_29 ( & V_3 -> V_8 ,
L_6 ) ;
else {
V_28 &= ~ ( 1 << 7 ) ;
F_7 ( V_3 , V_36 , V_28 ) ;
}
V_29 = F_30 ( & V_3 -> V_8 . V_37 , & V_38 ) ;
if ( V_29 )
goto V_39;
V_9 -> V_40 = F_31 ( & V_3 -> V_8 ) ;
if ( F_32 ( V_9 -> V_40 ) ) {
V_29 = F_33 ( V_9 -> V_40 ) ;
goto V_41;
}
return 0 ;
V_41:
F_34 ( & V_3 -> V_8 . V_37 , & V_38 ) ;
V_39:
F_35 ( V_9 ) ;
exit:
return V_29 ;
}
static int T_5 F_36 ( struct V_2 * V_3 )
{
struct V_6 * V_9 = F_10 ( V_3 ) ;
F_37 ( V_9 -> V_40 ) ;
F_34 ( & V_3 -> V_8 . V_37 , & V_38 ) ;
F_35 ( V_9 ) ;
return 0 ;
}
static int T_6 F_38 ( void )
{
return F_39 ( & V_42 ) ;
}
static void T_7 F_40 ( void )
{
F_41 ( & V_42 ) ;
}
