static int F_1 ( struct V_1 * V_2 , char * V_3 , int V_4 )
{
struct V_5 * V_6 ;
static const char * const V_7 [] = {
L_1 , L_2 , L_3 , L_4 ,
} ;
struct V_8 * V_9 ;
int V_10 ;
V_9 = F_2 ( sizeof( * V_9 ) + sizeof( * V_6 ) , V_11 ) ;
if ( ! V_9 )
return - V_12 ;
V_9 -> V_13 = 0 ;
V_9 -> V_14 = V_15 + V_2 -> V_16 ;
V_9 -> V_17 = sizeof( * V_6 ) ;
V_9 -> V_18 = 0 ;
V_10 = F_3 ( V_2 -> V_19 , V_9 ) ;
if ( V_10 < 0 )
goto exit;
if ( V_9 -> V_20 != V_21 ) {
snprintf ( V_3 , V_4 ,
L_5 ,
V_22 , V_9 -> V_20 ) ;
V_10 = - V_23 ;
goto exit;
}
V_6 = (struct V_5 * ) V_9 -> V_24 ;
if ( V_6 -> V_25 >= F_4 ( V_7 ) )
V_6 -> V_25 = 3 ;
snprintf ( V_3 , V_4 , L_6 , V_22 ,
V_6 -> V_26 , V_6 -> V_27 ,
V_7 [ V_6 -> V_25 ] ) ;
V_10 = 0 ;
exit:
F_5 ( V_9 ) ;
return V_10 ;
}
static int F_6 ( struct V_28 * V_28 , struct V_29 * V_30 )
{
struct V_1 * V_2 = F_7 ( V_28 -> V_31 ,
struct V_1 , V_32 ) ;
V_30 -> V_33 = V_2 ;
F_8 ( V_28 , V_30 ) ;
return 0 ;
}
static int F_9 ( struct V_28 * V_28 , struct V_29 * V_30 )
{
return 0 ;
}
static T_1 F_10 ( struct V_29 * V_30 , char T_2 * V_34 ,
T_3 V_35 , T_4 * V_36 )
{
struct V_1 * V_2 = V_30 -> V_33 ;
char V_9 [ sizeof( struct V_5 ) +
sizeof( V_22 ) ] ;
T_3 V_37 ;
int V_10 ;
if ( * V_36 != 0 )
return 0 ;
V_10 = F_1 ( V_2 , V_9 , sizeof( V_9 ) ) ;
if ( V_10 )
return V_10 ;
V_37 = F_11 ( V_35 , strlen ( V_9 ) ) ;
if ( F_12 ( V_34 , V_9 , V_37 ) )
return - V_38 ;
* V_36 = V_37 ;
return V_37 ;
}
static long F_13 ( struct V_1 * V_2 , void T_2 * V_39 )
{
long V_10 ;
struct V_8 V_40 ;
struct V_8 * V_41 ;
if ( F_14 ( & V_40 , V_39 , sizeof( V_40 ) ) )
return - V_38 ;
if ( ( V_40 . V_18 > V_42 ) ||
( V_40 . V_17 > V_42 ) )
return - V_23 ;
V_41 = F_2 ( sizeof( * V_41 ) + F_15 ( V_40 . V_18 , V_40 . V_17 ) ,
V_11 ) ;
if ( ! V_41 )
return - V_12 ;
if ( F_14 ( V_41 , V_39 , sizeof( * V_41 ) + V_40 . V_18 ) ) {
V_10 = - V_38 ;
goto exit;
}
if ( V_40 . V_18 != V_41 -> V_18 ||
V_40 . V_17 != V_41 -> V_17 ) {
V_10 = - V_23 ;
goto exit;
}
V_41 -> V_14 += V_2 -> V_16 ;
V_10 = F_3 ( V_2 -> V_19 , V_41 ) ;
if ( V_10 < 0 )
goto exit;
if ( F_12 ( V_39 , V_41 , sizeof( * V_41 ) + V_41 -> V_17 ) )
V_10 = - V_38 ;
exit:
F_5 ( V_41 ) ;
return V_10 ;
}
static long F_16 ( struct V_1 * V_2 , void T_2 * V_39 )
{
struct V_43 * V_19 = V_2 -> V_19 ;
struct V_44 V_45 = { } ;
long V_46 ;
if ( ! V_19 -> V_47 )
return - V_48 ;
if ( F_14 ( & V_45 , V_39 , sizeof( V_45 ) ) )
return - V_38 ;
V_46 = V_19 -> V_47 ( V_19 , V_45 . V_36 , V_45 . V_49 ,
V_45 . V_34 ) ;
if ( V_46 <= 0 )
return V_46 ;
if ( F_12 ( ( void T_2 * ) V_39 , & V_45 , sizeof( V_45 ) ) )
return - V_38 ;
return 0 ;
}
static long F_17 ( struct V_29 * V_30 , unsigned int V_50 ,
unsigned long V_39 )
{
struct V_1 * V_2 = V_30 -> V_33 ;
if ( F_18 ( V_50 ) != V_51 )
return - V_48 ;
switch ( V_50 ) {
case V_52 :
return F_13 ( V_2 , ( void T_2 * ) V_39 ) ;
case V_53 :
return F_16 ( V_2 , ( void T_2 * ) V_39 ) ;
}
return - V_48 ;
}
static void F_19 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_7 ( V_55 , struct V_1 ,
V_56 ) ;
F_5 ( V_2 ) ;
}
static int F_20 ( struct V_57 * V_58 )
{
int V_59 = - V_12 ;
struct V_54 * V_55 = & V_58 -> V_55 ;
struct V_60 * V_61 = F_21 ( V_55 ) ;
T_5 V_62 = F_22 ( V_63 , V_58 -> V_64 ) ;
struct V_1 * V_2 = F_23 ( sizeof( * V_2 ) , V_11 ) ;
if ( ! V_2 )
return V_59 ;
F_24 ( V_55 , V_2 ) ;
V_2 -> V_19 = F_25 ( V_55 -> V_65 ) ;
V_2 -> V_55 = V_55 ;
V_2 -> V_16 = V_61 -> V_16 ;
F_26 ( & V_2 -> V_56 ) ;
F_27 ( & V_2 -> V_32 , & V_66 ) ;
V_2 -> V_32 . V_67 . V_65 = & V_2 -> V_56 . V_67 ;
V_59 = F_28 ( & V_2 -> V_32 , V_62 , 1 ) ;
if ( V_59 ) {
F_29 ( V_55 , L_7 ) ;
goto V_68;
}
V_2 -> V_56 . V_69 = V_2 -> V_32 . V_55 ;
V_2 -> V_56 . V_70 = & V_71 ;
V_2 -> V_56 . V_65 = V_55 ;
V_2 -> V_56 . V_72 = F_19 ;
V_59 = F_30 ( & V_2 -> V_56 , L_8 , V_61 -> V_73 ) ;
if ( V_59 ) {
F_29 ( V_55 , L_9 , V_59 ) ;
goto V_74;
}
V_59 = F_31 ( & V_2 -> V_56 ) ;
if ( V_59 ) {
F_29 ( V_55 , L_10 , V_59 ) ;
goto V_75;
}
return 0 ;
V_75:
V_74:
F_24 ( V_55 , NULL ) ;
F_32 ( & V_2 -> V_32 ) ;
V_68:
F_5 ( V_2 ) ;
return V_59 ;
}
static int F_33 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_25 ( & V_58 -> V_55 ) ;
F_32 ( & V_2 -> V_32 ) ;
F_34 ( & V_2 -> V_56 ) ;
return 0 ;
}
static int T_6 F_35 ( void )
{
int V_10 ;
T_5 V_55 = 0 ;
V_10 = F_36 ( & V_71 ) ;
if ( V_10 ) {
F_37 ( V_76 L_11 ) ;
return V_10 ;
}
V_10 = F_38 ( & V_55 , 0 , V_77 , V_76 ) ;
if ( V_10 < 0 ) {
F_37 ( V_76 L_12 ) ;
goto V_78;
}
V_63 = F_39 ( V_55 ) ;
V_10 = F_40 ( & V_79 ) ;
if ( V_10 < 0 ) {
F_41 ( V_76 L_13 , V_10 ) ;
goto V_80;
}
return 0 ;
V_80:
F_42 ( F_22 ( V_63 , 0 ) , V_77 ) ;
V_78:
F_43 ( & V_71 ) ;
return V_10 ;
}
static void T_7 F_44 ( void )
{
F_45 ( & V_79 ) ;
F_46 ( V_63 , V_76 ) ;
F_43 ( & V_71 ) ;
}
