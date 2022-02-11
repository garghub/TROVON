static inline T_1 F_1 ( int V_1 )
{
int V_2 = F_2 ( V_1 , V_3 , V_4 ) ;
return ( V_2 / 500 ) * 8 ;
}
static inline int F_3 ( T_1 V_5 )
{
return ( V_5 / 8 ) * 500 ;
}
static T_2 F_4 ( struct V_6 * V_7 , T_3 V_5 )
{
if ( V_5 == V_8 )
return F_5 ( V_7 , V_5 ) ;
else
return F_6 ( V_7 , V_5 ) ;
}
static int F_7 ( struct V_6 * V_7 , T_3 V_5 , T_2 V_9 )
{
if ( V_5 == V_8 )
return F_8 ( V_7 , V_5 , V_9 ) ;
else
return F_9 ( V_7 , V_5 , V_9 ) ;
}
static struct V_10 * F_10 ( struct V_11 * V_12 )
{
struct V_10 * V_13 = F_11 ( V_12 ) ;
struct V_6 * V_7 = V_13 -> V_7 ;
int V_14 ;
F_12 ( & V_13 -> V_15 ) ;
if ( F_13 ( V_16 , V_13 -> V_17 + V_18 + V_18 / 2 )
|| ! V_13 -> V_19 ) {
F_14 ( & V_7 -> V_12 , L_1 ) ;
for ( V_14 = 0 ; V_14 < V_20 ; V_14 ++ ) {
V_13 -> V_1 [ V_14 ] =
F_3 ( F_4 ( V_7 ,
V_21 [ V_14 ] ) ) ;
}
V_13 -> V_22 =
F_4 ( V_7 , V_23 ) & 0x0007 ;
V_13 -> V_17 = V_16 ;
V_13 -> V_19 = 1 ;
}
F_15 ( & V_13 -> V_15 ) ;
return V_13 ;
}
static T_4 F_16 ( struct V_11 * V_12 , struct V_24 * V_25 ,
char * V_26 )
{
struct V_27 * V_28 = F_17 ( V_25 ) ;
struct V_10 * V_13 = F_10 ( V_12 ) ;
return sprintf ( V_26 , L_2 , V_13 -> V_1 [ V_28 -> V_29 ] ) ;
}
static T_4 F_18 ( struct V_11 * V_12 ,
struct V_24 * V_25 , char * V_26 )
{
struct V_27 * V_28 = F_17 ( V_25 ) ;
struct V_10 * V_13 = F_10 ( V_12 ) ;
int V_30 = V_28 -> V_29 ;
int V_1 ;
V_1 = V_30 == V_31 ? V_13 -> V_1 [ V_30 ] + V_13 -> V_1 [ V_32 ] :
V_13 -> V_1 [ V_30 ] - V_13 -> V_1 [ V_32 ] ;
return sprintf ( V_26 , L_2 , V_1 ) ;
}
static T_4 F_19 ( struct V_11 * V_12 , struct V_24 * V_25 ,
const char * V_26 , T_5 V_33 )
{
struct V_27 * V_28 = F_17 ( V_25 ) ;
struct V_10 * V_13 = F_11 ( V_12 ) ;
struct V_6 * V_7 = V_13 -> V_7 ;
int V_30 = V_28 -> V_29 ;
long V_34 ;
int V_35 ;
V_35 = F_20 ( V_26 , 10 , & V_34 ) ;
if ( V_35 )
return V_35 ;
F_12 ( & V_13 -> V_15 ) ;
V_13 -> V_1 [ V_30 ] = V_34 ;
F_7 ( V_7 , V_21 [ V_30 ] , F_1 ( V_34 ) ) ;
F_15 ( & V_13 -> V_15 ) ;
return V_33 ;
}
static T_4 F_21 ( struct V_11 * V_12 ,
struct V_24 * V_25 ,
const char * V_26 , T_5 V_33 )
{
struct V_10 * V_13 = F_11 ( V_12 ) ;
struct V_6 * V_7 = V_13 -> V_7 ;
unsigned long V_34 ;
int V_35 ;
V_35 = F_22 ( V_26 , 10 , & V_34 ) ;
if ( V_35 )
return V_35 ;
F_12 ( & V_13 -> V_15 ) ;
V_13 -> V_1 [ V_32 ] = V_13 -> V_1 [ V_36 ] - V_34 ;
F_7 ( V_7 , V_37 ,
F_1 ( V_13 -> V_1 [ V_32 ] ) ) ;
F_15 ( & V_13 -> V_15 ) ;
return V_33 ;
}
static T_4 F_23 ( struct V_11 * V_12 , struct V_24 * V_28 ,
char * V_26 )
{
int V_38 = F_17 ( V_28 ) -> V_29 ;
struct V_10 * V_13 = F_10 ( V_12 ) ;
return sprintf ( V_26 , L_3 , ( V_13 -> V_22 >> V_38 ) & 1 ) ;
}
static int F_24 ( struct V_6 * V_7 , struct V_39 * V_40 )
{
struct V_41 * V_42 = V_7 -> V_42 ;
int V_14 , V_43 , V_44 , V_45 , V_46 , V_47 , V_48 ;
if ( ! F_25 ( V_42 , V_49 |
V_50 ) )
return - V_51 ;
V_43 = F_26 ( V_7 , 0 ) ;
V_44 = F_5 ( V_7 , 1 ) ;
V_45 = F_26 ( V_7 , 2 ) ;
V_46 = F_26 ( V_7 , 3 ) ;
V_47 = F_26 ( V_7 , 4 ) ;
V_48 = F_26 ( V_7 , 5 ) ;
for ( V_14 = 8 ; V_14 <= 0xff ; V_14 += 8 ) {
if ( F_5 ( V_7 , V_14 + 1 ) != V_44
|| F_26 ( V_7 , V_14 + 2 ) != V_45
|| F_26 ( V_7 , V_14 + 3 ) != V_46
|| F_26 ( V_7 , V_14 + 4 ) != V_47
|| F_26 ( V_7 , V_14 + 5 ) != V_48 )
return - V_51 ;
}
if ( ( ( V_43 & 0x00f0 ) != 0xf0 && ( V_43 & 0x00f0 ) != 0x0 )
|| ( ( V_45 & 0x00f0 ) != 0xf0 && ( V_45 & 0x00f0 ) != 0x0 )
|| ( ( V_46 & 0x00f0 ) != 0xf0 && ( V_46 & 0x00f0 ) != 0x0 )
|| ( ( V_47 & 0x00f0 ) != 0xf0 && ( V_47 & 0x00f0 ) != 0x0 )
|| ( ( V_48 & 0x00f0 ) != 0xf0 && ( V_48 & 0x00f0 ) != 0x0 ) )
return - V_51 ;
if ( V_44 & 0xe0 )
return - V_51 ;
V_43 = F_26 ( V_7 , 0 ) ;
if ( F_26 ( V_7 , 6 ) != V_43
|| F_26 ( V_7 , 7 ) != V_43 )
return - V_51 ;
V_45 = F_26 ( V_7 , 2 ) ;
if ( F_26 ( V_7 , 6 ) != V_45
|| F_26 ( V_7 , 7 ) != V_45 )
return - V_51 ;
V_47 = F_26 ( V_7 , 4 ) ;
if ( F_26 ( V_7 , 6 ) != V_47
|| F_26 ( V_7 , 7 ) != V_47 )
return - V_51 ;
F_27 ( V_40 -> type , L_4 , V_52 ) ;
return 0 ;
}
static void F_28 ( struct V_6 * V_7 )
{
int V_44 = F_4 ( V_7 , V_8 ) ;
if ( V_44 & 1 )
F_7 ( V_7 , V_8 , V_44 & 0xfe ) ;
}
static int F_29 ( struct V_6 * V_7 , const struct V_53 * V_54 )
{
struct V_11 * V_12 = & V_7 -> V_12 ;
struct V_11 * V_55 ;
struct V_10 * V_13 ;
V_13 = F_30 ( V_12 , sizeof( struct V_10 ) , V_56 ) ;
if ( ! V_13 )
return - V_57 ;
V_13 -> V_7 = V_7 ;
F_31 ( & V_13 -> V_15 ) ;
F_28 ( V_7 ) ;
V_55 = F_32 ( V_12 , V_7 -> V_58 ,
V_13 , V_59 ) ;
return F_33 ( V_55 ) ;
}
