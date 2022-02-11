static int F_1 ( int V_1 )
{
return ( V_1 & 0x80 ? V_1 - 0x100 : V_1 ) * 1000 ;
}
static int F_2 ( int V_1 )
{
return ( V_1 < 0 ? V_1 + 0x100 * 1000 : V_1 ) / 1000 ;
}
static struct V_2 * F_3 ( struct V_3 * V_4 )
{
struct V_2 * V_5 = F_4 ( V_4 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
int V_8 , V_9 ;
F_5 ( & V_5 -> V_10 ) ;
if ( F_6 ( V_11 , V_5 -> V_12 + V_13 * 2 ) || ! V_5 -> V_14 ) {
F_7 ( & V_7 -> V_4 , L_1 ) ;
for ( V_9 = 0 ; V_9 < V_15 ; V_9 ++ )
V_5 -> V_16 [ V_9 ] = F_8 ( V_7 ,
V_17 [ V_9 ] ) ;
V_5 -> V_18 = F_8 ( V_7 ,
V_19 ) ;
V_8 = F_8 ( V_7 , V_20 ) ;
if ( ! ( V_8 & 0x20 ) )
V_5 -> V_18 ^= 0x02 ;
V_5 -> V_12 = V_11 ;
V_5 -> V_14 = 1 ;
}
F_9 ( & V_5 -> V_10 ) ;
return V_5 ;
}
static T_1 F_10 ( struct V_3 * V_4 , struct V_21 * V_22 ,
char * V_23 )
{
struct V_24 * V_25 = F_11 ( V_22 ) ;
struct V_2 * V_5 = F_3 ( V_4 ) ;
return sprintf ( V_23 , L_2 , F_1 ( V_5 -> V_16 [ V_25 -> V_26 ] ) ) ;
}
static T_1 F_12 ( struct V_3 * V_4 , struct V_21 * V_22 ,
const char * V_23 , T_2 V_27 )
{
struct V_24 * V_25 = F_11 ( V_22 ) ;
struct V_2 * V_5 = F_4 ( V_4 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
long V_1 ;
int V_28 = F_13 ( V_23 , 10 , & V_1 ) ;
if ( V_28 )
return V_28 ;
F_5 ( & V_5 -> V_10 ) ;
V_5 -> V_16 [ V_25 -> V_26 ] = F_2 ( V_1 ) ;
F_14 ( V_7 , V_29 [ V_25 -> V_26 ] ,
V_5 -> V_16 [ V_25 -> V_26 ] ) ;
F_9 ( & V_5 -> V_10 ) ;
return V_27 ;
}
static T_1 F_15 ( struct V_3 * V_4 , struct V_21 * V_25 ,
char * V_23 )
{
struct V_2 * V_5 = F_3 ( V_4 ) ;
return sprintf ( V_23 , L_2 , V_5 -> V_18 ) ;
}
static T_1 F_16 ( struct V_3 * V_4 , struct V_21 * V_25 ,
char * V_23 )
{
int V_30 = F_11 ( V_25 ) -> V_26 ;
struct V_2 * V_5 = F_3 ( V_4 ) ;
return sprintf ( V_23 , L_2 , ( V_5 -> V_18 >> V_30 ) & 1 ) ;
}
static int F_17 ( struct V_6 * V_7 ,
struct V_31 * V_32 )
{
struct V_33 * V_34 = V_7 -> V_34 ;
T_3 V_35 , V_36 , V_37 , V_38 , V_39 ;
if ( ! F_18 ( V_34 , V_40 ) )
return - V_41 ;
V_35 = F_8 ( V_7 , V_20 ) ;
V_36 = F_8 ( V_7 , V_42 ) ;
V_37 = F_8 ( V_7 , V_19 ) ;
if ( ( V_35 & 0x03 ) != 0x00
|| V_36 > 0x07 || ( V_37 & 0x61 ) != 0x00 ) {
F_7 ( & V_34 -> V_4 , L_3 ,
V_7 -> V_43 ) ;
return - V_41 ;
}
V_38 = F_8 ( V_7 , V_44 ) ;
V_39 = F_8 ( V_7 , V_45 ) ;
if ( V_38 != 0x4D || V_39 != 0x04 ) {
F_19 ( & V_34 -> V_4 ,
L_4 ,
V_38 , V_39 ) ;
return - V_41 ;
}
F_20 ( V_32 -> type , L_5 , V_46 ) ;
return 0 ;
}
static void F_21 ( struct V_6 * V_7 )
{
T_3 V_8 ;
F_14 ( V_7 , V_47 ,
5 ) ;
V_8 = F_8 ( V_7 , V_20 ) ;
if ( V_8 & 0x40 )
F_14 ( V_7 , V_48 ,
V_8 & 0xBF ) ;
}
static int F_22 ( struct V_6 * V_49 ,
const struct V_50 * V_51 )
{
struct V_2 * V_5 ;
struct V_3 * V_52 ;
V_5 = F_23 ( & V_49 -> V_4 , sizeof( struct V_2 ) ,
V_53 ) ;
if ( ! V_5 )
return - V_54 ;
V_5 -> V_7 = V_49 ;
F_24 ( & V_5 -> V_10 ) ;
F_21 ( V_49 ) ;
V_52 = F_25 ( & V_49 -> V_4 ,
V_49 -> V_55 ,
V_5 ,
V_56 ) ;
return F_26 ( V_52 ) ;
}
