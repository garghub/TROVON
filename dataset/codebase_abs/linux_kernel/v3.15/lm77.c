static inline T_1 F_1 ( int V_1 )
{
int V_2 = F_2 ( V_1 , V_3 , V_4 ) ;
return ( V_2 / 500 ) * 8 ;
}
static inline int F_3 ( T_1 V_5 )
{
return ( V_5 / 8 ) * 500 ;
}
static T_2 F_4 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
struct V_11 * V_12 = F_5 ( V_7 ) ;
return sprintf ( V_10 , L_1 , V_12 -> V_13 - V_12 -> V_14 ) ;
}
static T_2 F_6 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
struct V_11 * V_12 = F_5 ( V_7 ) ;
return sprintf ( V_10 , L_1 , V_12 -> V_15 + V_12 -> V_14 ) ;
}
static T_2 F_7 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
struct V_11 * V_12 = F_5 ( V_7 ) ;
return sprintf ( V_10 , L_1 , V_12 -> V_16 - V_12 -> V_14 ) ;
}
static T_2 F_8 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
const char * V_10 , T_3 V_17 )
{
struct V_18 * V_19 = F_9 ( V_7 ) ;
struct V_11 * V_12 = F_10 ( V_19 ) ;
unsigned long V_20 ;
int V_21 ;
V_21 = F_11 ( V_10 , 10 , & V_20 ) ;
if ( V_21 )
return V_21 ;
F_12 ( & V_12 -> V_22 ) ;
V_12 -> V_14 = V_12 -> V_13 - V_20 ;
F_13 ( V_19 , V_23 ,
F_1 ( V_12 -> V_14 ) ) ;
F_14 ( & V_12 -> V_22 ) ;
return V_17 ;
}
static T_2 F_15 ( struct V_6 * V_7 , struct V_8 * V_9 ,
const char * V_10 , T_3 V_17 )
{
struct V_18 * V_19 = F_9 ( V_7 ) ;
struct V_11 * V_12 = F_10 ( V_19 ) ;
int V_24 ;
unsigned long V_20 ;
int V_21 ;
V_21 = F_11 ( V_10 , 10 , & V_20 ) ;
if ( V_21 )
return V_21 ;
F_12 ( & V_12 -> V_22 ) ;
V_24 = V_12 -> V_13 - V_12 -> V_14 ;
V_12 -> V_13 = V_20 ;
V_12 -> V_14 = V_12 -> V_13 - V_24 ;
F_13 ( V_19 , V_25 ,
F_1 ( V_12 -> V_13 ) ) ;
F_13 ( V_19 , V_23 ,
F_1 ( V_12 -> V_14 ) ) ;
F_14 ( & V_12 -> V_22 ) ;
return V_17 ;
}
static T_2 F_16 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_10 )
{
int V_26 = F_17 ( V_9 ) -> V_27 ;
struct V_11 * V_12 = F_5 ( V_7 ) ;
return sprintf ( V_10 , L_2 , ( V_12 -> V_28 >> V_26 ) & 1 ) ;
}
static int F_18 ( struct V_18 * V_19 , struct V_29 * V_30 )
{
struct V_31 * V_32 = V_19 -> V_32 ;
int V_33 , V_34 , V_35 , V_36 , V_37 , V_38 , V_39 ;
if ( ! F_19 ( V_32 , V_40 |
V_41 ) )
return - V_42 ;
V_34 = F_20 ( V_19 , 0 ) ;
V_35 = F_21 ( V_19 , 1 ) ;
V_36 = F_20 ( V_19 , 2 ) ;
V_37 = F_20 ( V_19 , 3 ) ;
V_38 = F_20 ( V_19 , 4 ) ;
V_39 = F_20 ( V_19 , 5 ) ;
for ( V_33 = 8 ; V_33 <= 0xff ; V_33 += 8 ) {
if ( F_21 ( V_19 , V_33 + 1 ) != V_35
|| F_20 ( V_19 , V_33 + 2 ) != V_36
|| F_20 ( V_19 , V_33 + 3 ) != V_37
|| F_20 ( V_19 , V_33 + 4 ) != V_38
|| F_20 ( V_19 , V_33 + 5 ) != V_39 )
return - V_42 ;
}
if ( ( ( V_34 & 0x00f0 ) != 0xf0 && ( V_34 & 0x00f0 ) != 0x0 )
|| ( ( V_36 & 0x00f0 ) != 0xf0 && ( V_36 & 0x00f0 ) != 0x0 )
|| ( ( V_37 & 0x00f0 ) != 0xf0 && ( V_37 & 0x00f0 ) != 0x0 )
|| ( ( V_38 & 0x00f0 ) != 0xf0 && ( V_38 & 0x00f0 ) != 0x0 )
|| ( ( V_39 & 0x00f0 ) != 0xf0 && ( V_39 & 0x00f0 ) != 0x0 ) )
return - V_42 ;
if ( V_35 & 0xe0 )
return - V_42 ;
V_34 = F_20 ( V_19 , 0 ) ;
if ( F_20 ( V_19 , 6 ) != V_34
|| F_20 ( V_19 , 7 ) != V_34 )
return - V_42 ;
V_36 = F_20 ( V_19 , 2 ) ;
if ( F_20 ( V_19 , 6 ) != V_36
|| F_20 ( V_19 , 7 ) != V_36 )
return - V_42 ;
V_38 = F_20 ( V_19 , 4 ) ;
if ( F_20 ( V_19 , 6 ) != V_38
|| F_20 ( V_19 , 7 ) != V_38 )
return - V_42 ;
F_22 ( V_30 -> type , L_3 , V_43 ) ;
return 0 ;
}
static int F_23 ( struct V_18 * V_19 , const struct V_44 * V_45 )
{
struct V_6 * V_7 = & V_19 -> V_7 ;
struct V_11 * V_12 ;
int V_21 ;
V_12 = F_24 ( V_7 , sizeof( struct V_11 ) , V_46 ) ;
if ( ! V_12 )
return - V_47 ;
F_25 ( V_19 , V_12 ) ;
F_26 ( & V_12 -> V_22 ) ;
F_27 ( V_19 ) ;
V_21 = F_28 ( & V_7 -> V_48 , & V_49 ) ;
if ( V_21 )
return V_21 ;
V_12 -> V_50 = F_29 ( V_7 ) ;
if ( F_30 ( V_12 -> V_50 ) ) {
V_21 = F_31 ( V_12 -> V_50 ) ;
goto V_51;
}
return 0 ;
V_51:
F_32 ( & V_7 -> V_48 , & V_49 ) ;
return V_21 ;
}
static int F_33 ( struct V_18 * V_19 )
{
struct V_11 * V_12 = F_10 ( V_19 ) ;
F_34 ( V_12 -> V_50 ) ;
F_32 ( & V_19 -> V_7 . V_48 , & V_49 ) ;
return 0 ;
}
static T_4 F_35 ( struct V_18 * V_19 , T_5 V_5 )
{
if ( V_5 == V_52 )
return F_21 ( V_19 , V_5 ) ;
else
return F_36 ( V_19 , V_5 ) ;
}
static int F_13 ( struct V_18 * V_19 , T_5 V_5 , T_4 V_53 )
{
if ( V_5 == V_52 )
return F_37 ( V_19 , V_5 , V_53 ) ;
else
return F_38 ( V_19 , V_5 , V_53 ) ;
}
static void F_27 ( struct V_18 * V_19 )
{
int V_35 = F_35 ( V_19 , V_52 ) ;
if ( V_35 & 1 )
F_13 ( V_19 , V_52 , V_35 & 0xfe ) ;
}
static struct V_11 * F_5 ( struct V_6 * V_7 )
{
struct V_18 * V_19 = F_9 ( V_7 ) ;
struct V_11 * V_12 = F_10 ( V_19 ) ;
F_12 ( & V_12 -> V_22 ) ;
if ( F_39 ( V_54 , V_12 -> V_55 + V_56 + V_56 / 2 )
|| ! V_12 -> V_57 ) {
F_40 ( & V_19 -> V_7 , L_4 ) ;
V_12 -> V_58 =
F_3 ( F_35 ( V_19 ,
V_59 ) ) ;
V_12 -> V_14 =
F_3 ( F_35 ( V_19 ,
V_23 ) ) ;
V_12 -> V_13 =
F_3 ( F_35 ( V_19 ,
V_25 ) ) ;
V_12 -> V_15 =
F_3 ( F_35 ( V_19 ,
V_60 ) ) ;
V_12 -> V_16 =
F_3 ( F_35 ( V_19 ,
V_61 ) ) ;
V_12 -> V_28 =
F_35 ( V_19 , V_59 ) & 0x0007 ;
V_12 -> V_55 = V_54 ;
V_12 -> V_57 = 1 ;
}
F_14 ( & V_12 -> V_22 ) ;
return V_12 ;
}
