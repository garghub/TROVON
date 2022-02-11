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
V_41 = F_2 ( sizeof( * V_41 ) + F_15 ( V_40 . V_18 , V_40 . V_17 ) ,
V_11 ) ;
if ( ! V_41 )
return - V_12 ;
if ( F_14 ( V_41 , V_39 , sizeof( * V_41 ) + V_40 . V_18 ) ) {
V_10 = - V_38 ;
goto exit;
}
V_41 -> V_14 += V_2 -> V_16 ;
V_10 = F_3 ( V_2 -> V_19 , V_41 ) ;
if ( V_10 < 0 )
goto exit;
if ( F_12 ( V_39 , V_41 , sizeof( * V_41 ) + V_40 . V_17 ) )
V_10 = - V_38 ;
exit:
F_5 ( V_41 ) ;
return V_10 ;
}
static long F_16 ( struct V_1 * V_2 , void T_2 * V_39 )
{
struct V_42 * V_19 = V_2 -> V_19 ;
struct V_43 V_44 = { } ;
long V_45 ;
if ( ! V_19 -> V_46 )
return - V_47 ;
if ( F_14 ( & V_44 , V_39 , sizeof( V_44 ) ) )
return - V_38 ;
V_45 = V_19 -> V_46 ( V_19 , V_44 . V_36 , V_44 . V_48 ,
V_44 . V_34 ) ;
if ( V_45 <= 0 )
return V_45 ;
if ( F_12 ( ( void T_2 * ) V_39 , & V_44 , sizeof( V_44 ) ) )
return - V_38 ;
return 0 ;
}
static long F_17 ( struct V_29 * V_30 , unsigned int V_49 ,
unsigned long V_39 )
{
struct V_1 * V_2 = V_30 -> V_33 ;
if ( F_18 ( V_49 ) != V_50 )
return - V_47 ;
switch ( V_49 ) {
case V_51 :
return F_13 ( V_2 , ( void T_2 * ) V_39 ) ;
case V_52 :
return F_16 ( V_2 , ( void T_2 * ) V_39 ) ;
}
return - V_47 ;
}
static void F_19 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_7 ( V_54 , struct V_1 ,
V_55 ) ;
F_5 ( V_2 ) ;
}
static int F_20 ( struct V_56 * V_57 )
{
int V_58 = - V_12 ;
struct V_53 * V_54 = & V_57 -> V_54 ;
struct V_59 * V_60 = F_21 ( V_54 ) ;
T_5 V_61 = F_22 ( V_62 , V_57 -> V_63 ) ;
struct V_1 * V_2 = F_23 ( sizeof( * V_2 ) , V_11 ) ;
if ( ! V_2 )
return V_58 ;
F_24 ( V_54 , V_2 ) ;
V_2 -> V_19 = F_25 ( V_54 -> V_64 ) ;
V_2 -> V_54 = V_54 ;
V_2 -> V_16 = V_60 -> V_16 ;
F_26 ( & V_2 -> V_55 ) ;
F_27 ( & V_2 -> V_32 , & V_65 ) ;
V_2 -> V_32 . V_66 . V_64 = & V_2 -> V_55 . V_66 ;
V_58 = F_28 ( & V_2 -> V_32 , V_61 , 1 ) ;
if ( V_58 ) {
F_29 ( V_54 , L_7 ) ;
goto V_67;
}
V_2 -> V_55 . V_68 = V_2 -> V_32 . V_54 ;
V_2 -> V_55 . V_69 = & V_70 ;
V_2 -> V_55 . V_64 = V_54 ;
V_2 -> V_55 . V_71 = F_19 ;
V_58 = F_30 ( & V_2 -> V_55 , L_8 , V_60 -> V_72 ) ;
if ( V_58 ) {
F_29 ( V_54 , L_9 , V_58 ) ;
goto V_73;
}
V_58 = F_31 ( & V_2 -> V_55 ) ;
if ( V_58 ) {
F_29 ( V_54 , L_10 , V_58 ) ;
goto V_74;
}
return 0 ;
V_74:
V_73:
F_24 ( V_54 , NULL ) ;
F_32 ( & V_2 -> V_32 ) ;
V_67:
F_5 ( V_2 ) ;
return V_58 ;
}
static int F_33 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_25 ( & V_57 -> V_54 ) ;
F_32 ( & V_2 -> V_32 ) ;
F_34 ( & V_2 -> V_55 ) ;
return 0 ;
}
static int T_6 F_35 ( void )
{
int V_10 ;
T_5 V_54 = 0 ;
V_10 = F_36 ( & V_70 ) ;
if ( V_10 ) {
F_37 ( V_75 L_11 ) ;
return V_10 ;
}
V_10 = F_38 ( & V_54 , 0 , V_76 , V_75 ) ;
if ( V_10 < 0 ) {
F_37 ( V_75 L_12 ) ;
goto V_77;
}
V_62 = F_39 ( V_54 ) ;
V_10 = F_40 ( & V_78 ) ;
if ( V_10 < 0 ) {
F_41 ( V_75 L_13 , V_10 ) ;
goto V_79;
}
return 0 ;
V_79:
F_42 ( F_22 ( V_62 , 0 ) , V_76 ) ;
V_77:
F_43 ( & V_70 ) ;
return V_10 ;
}
static void T_7 F_44 ( void )
{
F_45 ( & V_78 ) ;
F_46 ( V_62 , V_75 ) ;
F_43 ( & V_70 ) ;
}
