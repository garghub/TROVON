static inline T_1 F_1 ( int V_1 )
{
int V_2 = F_2 ( V_1 , V_3 , V_4 ) ;
return ( V_2 / 500 ) * 8 ;
}
static inline int F_3 ( T_1 V_5 )
{
return ( V_5 / 8 ) * 500 ;
}
static T_2 F_4 ( struct V_6 * V_7 , struct V_8 * V_9 , char * V_10 )
{
struct V_11 * V_12 = F_5 ( V_7 ) ;
return sprintf ( V_10 , L_1 , V_12 -> V_13 - V_12 -> V_14 ) ;
}
static T_2 F_6 ( struct V_6 * V_7 , struct V_8 * V_9 , char * V_10 )
{
struct V_11 * V_12 = F_5 ( V_7 ) ;
return sprintf ( V_10 , L_1 , V_12 -> V_15 + V_12 -> V_14 ) ;
}
static T_2 F_7 ( struct V_6 * V_7 , struct V_8 * V_9 , char * V_10 )
{
struct V_11 * V_12 = F_5 ( V_7 ) ;
return sprintf ( V_10 , L_1 , V_12 -> V_16 - V_12 -> V_14 ) ;
}
static T_2 F_8 ( struct V_6 * V_7 , struct V_8 * V_9 , const char * V_10 , T_3 V_17 )
{
struct V_18 * V_19 = F_9 ( V_7 ) ;
struct V_11 * V_12 = F_10 ( V_19 ) ;
unsigned long V_20 = F_11 ( V_10 , NULL , 10 ) ;
F_12 ( & V_12 -> V_21 ) ;
V_12 -> V_14 = V_12 -> V_13 - V_20 ;
F_13 ( V_19 , V_22 ,
F_1 ( V_12 -> V_14 ) ) ;
F_14 ( & V_12 -> V_21 ) ;
return V_17 ;
}
static T_2 F_15 ( struct V_6 * V_7 , struct V_8 * V_9 , const char * V_10 , T_3 V_17 )
{
struct V_18 * V_19 = F_9 ( V_7 ) ;
struct V_11 * V_12 = F_10 ( V_19 ) ;
long V_20 = F_11 ( V_10 , NULL , 10 ) ;
int V_23 ;
F_12 ( & V_12 -> V_21 ) ;
V_23 = V_12 -> V_13 - V_12 -> V_14 ;
V_12 -> V_13 = V_20 ;
V_12 -> V_14 = V_12 -> V_13 - V_23 ;
F_13 ( V_19 , V_24 ,
F_1 ( V_12 -> V_13 ) ) ;
F_13 ( V_19 , V_22 ,
F_1 ( V_12 -> V_14 ) ) ;
F_14 ( & V_12 -> V_21 ) ;
return V_17 ;
}
static T_2 F_16 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_10 )
{
int V_25 = F_17 ( V_9 ) -> V_26 ;
struct V_11 * V_12 = F_5 ( V_7 ) ;
return sprintf ( V_10 , L_2 , ( V_12 -> V_27 >> V_25 ) & 1 ) ;
}
static int F_18 ( struct V_18 * V_28 ,
struct V_29 * V_30 )
{
struct V_31 * V_32 = V_28 -> V_32 ;
int V_33 , V_34 , V_35 , V_36 , V_37 , V_38 , V_39 ;
if ( ! F_19 ( V_32 , V_40 |
V_41 ) )
return - V_42 ;
V_34 = F_20 ( V_28 , 0 ) ;
V_35 = F_21 ( V_28 , 1 ) ;
V_36 = F_20 ( V_28 , 2 ) ;
V_37 = F_20 ( V_28 , 3 ) ;
V_38 = F_20 ( V_28 , 4 ) ;
V_39 = F_20 ( V_28 , 5 ) ;
for ( V_33 = 8 ; V_33 <= 0xff ; V_33 += 8 ) {
if ( F_21 ( V_28 , V_33 + 1 ) != V_35
|| F_20 ( V_28 , V_33 + 2 ) != V_36
|| F_20 ( V_28 , V_33 + 3 ) != V_37
|| F_20 ( V_28 , V_33 + 4 ) != V_38
|| F_20 ( V_28 , V_33 + 5 ) != V_39 )
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
V_34 = F_20 ( V_28 , 0 ) ;
if ( F_20 ( V_28 , 6 ) != V_34
|| F_20 ( V_28 , 7 ) != V_34 )
return - V_42 ;
V_36 = F_20 ( V_28 , 2 ) ;
if ( F_20 ( V_28 , 6 ) != V_36
|| F_20 ( V_28 , 7 ) != V_36 )
return - V_42 ;
V_38 = F_20 ( V_28 , 4 ) ;
if ( F_20 ( V_28 , 6 ) != V_38
|| F_20 ( V_28 , 7 ) != V_38 )
return - V_42 ;
F_22 ( V_30 -> type , L_3 , V_43 ) ;
return 0 ;
}
static int F_23 ( struct V_18 * V_28 ,
const struct V_44 * V_45 )
{
struct V_11 * V_12 ;
int V_46 ;
V_12 = F_24 ( sizeof( struct V_11 ) , V_47 ) ;
if ( ! V_12 ) {
V_46 = - V_48 ;
goto exit;
}
F_25 ( V_28 , V_12 ) ;
V_12 -> V_49 = 0 ;
F_26 ( & V_12 -> V_21 ) ;
F_27 ( V_28 ) ;
if ( ( V_46 = F_28 ( & V_28 -> V_7 . V_50 , & V_51 ) ) )
goto V_52;
V_12 -> V_53 = F_29 ( & V_28 -> V_7 ) ;
if ( F_30 ( V_12 -> V_53 ) ) {
V_46 = F_31 ( V_12 -> V_53 ) ;
goto V_54;
}
return 0 ;
V_54:
F_32 ( & V_28 -> V_7 . V_50 , & V_51 ) ;
V_52:
F_33 ( V_12 ) ;
exit:
return V_46 ;
}
static int F_34 ( struct V_18 * V_19 )
{
struct V_11 * V_12 = F_10 ( V_19 ) ;
F_35 ( V_12 -> V_53 ) ;
F_32 ( & V_19 -> V_7 . V_50 , & V_51 ) ;
F_33 ( V_12 ) ;
return 0 ;
}
static T_4 F_36 ( struct V_18 * V_19 , T_5 V_5 )
{
if ( V_5 == V_55 )
return F_21 ( V_19 , V_5 ) ;
else
return F_37 ( V_19 , V_5 ) ;
}
static int F_13 ( struct V_18 * V_19 , T_5 V_5 , T_4 V_56 )
{
if ( V_5 == V_55 )
return F_38 ( V_19 , V_5 , V_56 ) ;
else
return F_39 ( V_19 , V_5 , V_56 ) ;
}
static void F_27 ( struct V_18 * V_19 )
{
int V_35 = F_36 ( V_19 , V_55 ) ;
if ( V_35 & 1 )
F_13 ( V_19 , V_55 , V_35 & 0xfe ) ;
}
static struct V_11 * F_5 ( struct V_6 * V_7 )
{
struct V_18 * V_19 = F_9 ( V_7 ) ;
struct V_11 * V_12 = F_10 ( V_19 ) ;
F_12 ( & V_12 -> V_21 ) ;
if ( F_40 ( V_57 , V_12 -> V_58 + V_59 + V_59 / 2 )
|| ! V_12 -> V_49 ) {
F_41 ( & V_19 -> V_7 , L_4 ) ;
V_12 -> V_60 =
F_3 ( F_36 ( V_19 ,
V_61 ) ) ;
V_12 -> V_14 =
F_3 ( F_36 ( V_19 ,
V_22 ) ) ;
V_12 -> V_13 =
F_3 ( F_36 ( V_19 ,
V_24 ) ) ;
V_12 -> V_15 =
F_3 ( F_36 ( V_19 ,
V_62 ) ) ;
V_12 -> V_16 =
F_3 ( F_36 ( V_19 ,
V_63 ) ) ;
V_12 -> V_27 =
F_36 ( V_19 , V_61 ) & 0x0007 ;
V_12 -> V_58 = V_57 ;
V_12 -> V_49 = 1 ;
}
F_14 ( & V_12 -> V_21 ) ;
return V_12 ;
}
static int T_6 F_42 ( void )
{
return F_43 ( & V_64 ) ;
}
static void T_7 F_44 ( void )
{
F_45 ( & V_64 ) ;
}
