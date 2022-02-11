static inline T_1 F_1 ( int V_1 )
{
return ( V_1 / 500 ) * 8 ;
}
static inline int F_2 ( T_1 V_2 )
{
return ( V_2 / 8 ) * 500 ;
}
static T_2 F_3 ( struct V_3 * V_4 , T_3 V_2 )
{
if ( V_2 == V_5 )
return F_4 ( V_4 , V_2 ) ;
else
return F_5 ( V_4 , V_2 ) ;
}
static int F_6 ( struct V_3 * V_4 , T_3 V_2 , T_2 V_6 )
{
if ( V_2 == V_5 )
return F_7 ( V_4 , V_2 , V_6 ) ;
else
return F_8 ( V_4 , V_2 , V_6 ) ;
}
static struct V_7 * F_9 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_10 ( V_9 ) ;
struct V_3 * V_4 = V_10 -> V_4 ;
int V_11 ;
F_11 ( & V_10 -> V_12 ) ;
if ( F_12 ( V_13 , V_10 -> V_14 + V_15 + V_15 / 2 )
|| ! V_10 -> V_16 ) {
F_13 ( & V_4 -> V_9 , L_1 ) ;
for ( V_11 = 0 ; V_11 < V_17 ; V_11 ++ ) {
V_10 -> V_1 [ V_11 ] =
F_2 ( F_3 ( V_4 ,
V_18 [ V_11 ] ) ) ;
}
V_10 -> V_19 =
F_3 ( V_4 , V_20 ) & 0x0007 ;
V_10 -> V_14 = V_13 ;
V_10 -> V_16 = 1 ;
}
F_14 ( & V_10 -> V_12 ) ;
return V_10 ;
}
static T_4 F_15 ( struct V_8 * V_9 , struct V_21 * V_22 ,
char * V_23 )
{
struct V_24 * V_25 = F_16 ( V_22 ) ;
struct V_7 * V_10 = F_9 ( V_9 ) ;
return sprintf ( V_23 , L_2 , V_10 -> V_1 [ V_25 -> V_26 ] ) ;
}
static T_4 F_17 ( struct V_8 * V_9 ,
struct V_21 * V_22 , char * V_23 )
{
struct V_24 * V_25 = F_16 ( V_22 ) ;
struct V_7 * V_10 = F_9 ( V_9 ) ;
int V_27 = V_25 -> V_26 ;
int V_1 ;
V_1 = V_27 == V_28 ? V_10 -> V_1 [ V_27 ] + V_10 -> V_1 [ V_29 ] :
V_10 -> V_1 [ V_27 ] - V_10 -> V_1 [ V_29 ] ;
return sprintf ( V_23 , L_2 , V_1 ) ;
}
static T_4 F_18 ( struct V_8 * V_9 , struct V_21 * V_22 ,
const char * V_23 , T_5 V_30 )
{
struct V_24 * V_25 = F_16 ( V_22 ) ;
struct V_7 * V_10 = F_10 ( V_9 ) ;
struct V_3 * V_4 = V_10 -> V_4 ;
int V_27 = V_25 -> V_26 ;
long V_31 ;
int V_32 ;
V_32 = F_19 ( V_23 , 10 , & V_31 ) ;
if ( V_32 )
return V_32 ;
V_31 = F_20 ( V_31 , V_33 , V_34 ) ;
F_11 ( & V_10 -> V_12 ) ;
V_10 -> V_1 [ V_27 ] = V_31 ;
F_6 ( V_4 , V_18 [ V_27 ] , F_1 ( V_31 ) ) ;
F_14 ( & V_10 -> V_12 ) ;
return V_30 ;
}
static T_4 F_21 ( struct V_8 * V_9 ,
struct V_21 * V_22 ,
const char * V_23 , T_5 V_30 )
{
struct V_7 * V_10 = F_10 ( V_9 ) ;
struct V_3 * V_4 = V_10 -> V_4 ;
long V_31 ;
int V_32 ;
V_32 = F_19 ( V_23 , 10 , & V_31 ) ;
if ( V_32 )
return V_32 ;
F_11 ( & V_10 -> V_12 ) ;
V_31 = F_20 ( V_10 -> V_1 [ V_35 ] - V_31 , V_33 , V_34 ) ;
V_10 -> V_1 [ V_29 ] = V_31 ;
F_6 ( V_4 , V_36 ,
F_1 ( V_10 -> V_1 [ V_29 ] ) ) ;
F_14 ( & V_10 -> V_12 ) ;
return V_30 ;
}
static T_4 F_22 ( struct V_8 * V_9 , struct V_21 * V_25 ,
char * V_23 )
{
int V_37 = F_16 ( V_25 ) -> V_26 ;
struct V_7 * V_10 = F_9 ( V_9 ) ;
return sprintf ( V_23 , L_3 , ( V_10 -> V_19 >> V_37 ) & 1 ) ;
}
static int F_23 ( struct V_3 * V_4 , struct V_38 * V_39 )
{
struct V_40 * V_41 = V_4 -> V_41 ;
int V_11 , V_42 , V_43 , V_44 , V_45 , V_46 , V_47 ;
if ( ! F_24 ( V_41 , V_48 |
V_49 ) )
return - V_50 ;
V_42 = F_25 ( V_4 , 0 ) ;
V_43 = F_4 ( V_4 , 1 ) ;
V_44 = F_25 ( V_4 , 2 ) ;
V_45 = F_25 ( V_4 , 3 ) ;
V_46 = F_25 ( V_4 , 4 ) ;
V_47 = F_25 ( V_4 , 5 ) ;
for ( V_11 = 8 ; V_11 <= 0xff ; V_11 += 8 ) {
if ( F_4 ( V_4 , V_11 + 1 ) != V_43
|| F_25 ( V_4 , V_11 + 2 ) != V_44
|| F_25 ( V_4 , V_11 + 3 ) != V_45
|| F_25 ( V_4 , V_11 + 4 ) != V_46
|| F_25 ( V_4 , V_11 + 5 ) != V_47 )
return - V_50 ;
}
if ( ( ( V_42 & 0x00f0 ) != 0xf0 && ( V_42 & 0x00f0 ) != 0x0 )
|| ( ( V_44 & 0x00f0 ) != 0xf0 && ( V_44 & 0x00f0 ) != 0x0 )
|| ( ( V_45 & 0x00f0 ) != 0xf0 && ( V_45 & 0x00f0 ) != 0x0 )
|| ( ( V_46 & 0x00f0 ) != 0xf0 && ( V_46 & 0x00f0 ) != 0x0 )
|| ( ( V_47 & 0x00f0 ) != 0xf0 && ( V_47 & 0x00f0 ) != 0x0 ) )
return - V_50 ;
if ( V_43 & 0xe0 )
return - V_50 ;
V_42 = F_25 ( V_4 , 0 ) ;
if ( F_25 ( V_4 , 6 ) != V_42
|| F_25 ( V_4 , 7 ) != V_42 )
return - V_50 ;
V_44 = F_25 ( V_4 , 2 ) ;
if ( F_25 ( V_4 , 6 ) != V_44
|| F_25 ( V_4 , 7 ) != V_44 )
return - V_50 ;
V_46 = F_25 ( V_4 , 4 ) ;
if ( F_25 ( V_4 , 6 ) != V_46
|| F_25 ( V_4 , 7 ) != V_46 )
return - V_50 ;
F_26 ( V_39 -> type , L_4 , V_51 ) ;
return 0 ;
}
static void F_27 ( struct V_3 * V_4 )
{
int V_43 = F_3 ( V_4 , V_5 ) ;
if ( V_43 & 1 )
F_6 ( V_4 , V_5 , V_43 & 0xfe ) ;
}
static int F_28 ( struct V_3 * V_4 , const struct V_52 * V_53 )
{
struct V_8 * V_9 = & V_4 -> V_9 ;
struct V_8 * V_54 ;
struct V_7 * V_10 ;
V_10 = F_29 ( V_9 , sizeof( struct V_7 ) , V_55 ) ;
if ( ! V_10 )
return - V_56 ;
V_10 -> V_4 = V_4 ;
F_30 ( & V_10 -> V_12 ) ;
F_27 ( V_4 ) ;
V_54 = F_31 ( V_9 , V_4 -> V_57 ,
V_10 , V_58 ) ;
return F_32 ( V_54 ) ;
}
