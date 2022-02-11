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
static int F_18 ( struct V_18 * V_29 ,
struct V_30 * V_31 )
{
struct V_32 * V_33 = V_29 -> V_33 ;
int V_34 , V_35 , V_36 , V_37 , V_38 , V_39 , V_40 ;
if ( ! F_19 ( V_33 , V_41 |
V_42 ) )
return - V_43 ;
V_35 = F_20 ( V_29 , 0 ) ;
V_36 = F_21 ( V_29 , 1 ) ;
V_37 = F_20 ( V_29 , 2 ) ;
V_38 = F_20 ( V_29 , 3 ) ;
V_39 = F_20 ( V_29 , 4 ) ;
V_40 = F_20 ( V_29 , 5 ) ;
for ( V_34 = 8 ; V_34 <= 0xff ; V_34 += 8 ) {
if ( F_21 ( V_29 , V_34 + 1 ) != V_36
|| F_20 ( V_29 , V_34 + 2 ) != V_37
|| F_20 ( V_29 , V_34 + 3 ) != V_38
|| F_20 ( V_29 , V_34 + 4 ) != V_39
|| F_20 ( V_29 , V_34 + 5 ) != V_40 )
return - V_43 ;
}
if ( ( ( V_35 & 0x00f0 ) != 0xf0 && ( V_35 & 0x00f0 ) != 0x0 )
|| ( ( V_37 & 0x00f0 ) != 0xf0 && ( V_37 & 0x00f0 ) != 0x0 )
|| ( ( V_38 & 0x00f0 ) != 0xf0 && ( V_38 & 0x00f0 ) != 0x0 )
|| ( ( V_39 & 0x00f0 ) != 0xf0 && ( V_39 & 0x00f0 ) != 0x0 )
|| ( ( V_40 & 0x00f0 ) != 0xf0 && ( V_40 & 0x00f0 ) != 0x0 ) )
return - V_43 ;
if ( V_36 & 0xe0 )
return - V_43 ;
V_35 = F_20 ( V_29 , 0 ) ;
if ( F_20 ( V_29 , 6 ) != V_35
|| F_20 ( V_29 , 7 ) != V_35 )
return - V_43 ;
V_37 = F_20 ( V_29 , 2 ) ;
if ( F_20 ( V_29 , 6 ) != V_37
|| F_20 ( V_29 , 7 ) != V_37 )
return - V_43 ;
V_39 = F_20 ( V_29 , 4 ) ;
if ( F_20 ( V_29 , 6 ) != V_39
|| F_20 ( V_29 , 7 ) != V_39 )
return - V_43 ;
F_22 ( V_31 -> type , L_3 , V_44 ) ;
return 0 ;
}
static int F_23 ( struct V_18 * V_29 ,
const struct V_45 * V_46 )
{
struct V_11 * V_12 ;
int V_21 ;
V_12 = F_24 ( sizeof( struct V_11 ) , V_47 ) ;
if ( ! V_12 ) {
V_21 = - V_48 ;
goto exit;
}
F_25 ( V_29 , V_12 ) ;
V_12 -> V_49 = 0 ;
F_26 ( & V_12 -> V_22 ) ;
F_27 ( V_29 ) ;
V_21 = F_28 ( & V_29 -> V_7 . V_50 , & V_51 ) ;
if ( V_21 )
goto V_52;
V_12 -> V_53 = F_29 ( & V_29 -> V_7 ) ;
if ( F_30 ( V_12 -> V_53 ) ) {
V_21 = F_31 ( V_12 -> V_53 ) ;
goto V_54;
}
return 0 ;
V_54:
F_32 ( & V_29 -> V_7 . V_50 , & V_51 ) ;
V_52:
F_33 ( V_12 ) ;
exit:
return V_21 ;
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
int V_36 = F_36 ( V_19 , V_55 ) ;
if ( V_36 & 1 )
F_13 ( V_19 , V_55 , V_36 & 0xfe ) ;
}
static struct V_11 * F_5 ( struct V_6 * V_7 )
{
struct V_18 * V_19 = F_9 ( V_7 ) ;
struct V_11 * V_12 = F_10 ( V_19 ) ;
F_12 ( & V_12 -> V_22 ) ;
if ( F_40 ( V_57 , V_12 -> V_58 + V_59 + V_59 / 2 )
|| ! V_12 -> V_49 ) {
F_41 ( & V_19 -> V_7 , L_4 ) ;
V_12 -> V_60 =
F_3 ( F_36 ( V_19 ,
V_61 ) ) ;
V_12 -> V_14 =
F_3 ( F_36 ( V_19 ,
V_23 ) ) ;
V_12 -> V_13 =
F_3 ( F_36 ( V_19 ,
V_25 ) ) ;
V_12 -> V_15 =
F_3 ( F_36 ( V_19 ,
V_62 ) ) ;
V_12 -> V_16 =
F_3 ( F_36 ( V_19 ,
V_63 ) ) ;
V_12 -> V_28 =
F_36 ( V_19 , V_61 ) & 0x0007 ;
V_12 -> V_58 = V_57 ;
V_12 -> V_49 = 1 ;
}
F_14 ( & V_12 -> V_22 ) ;
return V_12 ;
}
