static struct V_1 * F_1 ( const struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return V_5 -> V_6 ;
}
static struct V_1 * F_3 ( const struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_4 ( F_5 ( & V_6 -> V_3 ) ) ;
}
static T_1 F_6 ( const struct V_2 * V_3 )
{
F_7 ( V_3 -> type != V_7 ) ;
return F_8 ( 0xeba1 ) ;
}
static T_1 F_9 ( const struct V_2 * V_3 )
{
F_7 ( V_3 -> type != V_7 ) ;
return F_8 ( 0x1 ) ;
}
static T_2 F_10 ( const struct V_2 * V_3 )
{
F_7 ( V_3 -> type != V_7 ) ;
return 0x00 ;
}
static int F_11 ( struct V_2 * V_3 ,
struct V_8 * V_9 , T_2 V_10 , T_2 V_11 , T_2 V_12 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_12 ( & V_6 -> V_13 ) ;
V_6 -> V_14 = V_10 ;
V_6 -> V_15 = V_11 ;
F_13 ( & V_6 -> V_13 ) ;
return F_14 ( V_3 , F_9 ( V_3 ) ,
V_16 ) ;
}
static int F_15 ( struct V_2 * V_3 ,
struct V_8 * V_9 , T_1 V_17 , T_2 V_18 )
{
return 0 ;
}
static int F_16 ( struct V_2 * V_3 ,
struct V_8 * V_9 , T_2 V_19 )
{
return F_17 ( V_3 , V_16 ) ;
}
static int F_18 ( struct V_2 * V_3 ,
struct V_8 * V_9 , T_2 V_10 , T_2 V_11 ,
T_2 V_20 , T_2 V_21 , T_2 V_22 , T_2 V_23 ,
T_2 V_24 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_12 ( & V_6 -> V_13 ) ;
V_6 -> V_14 = V_10 ;
V_6 -> V_15 = V_11 ;
F_13 ( & V_6 -> V_13 ) ;
F_19 ( V_3 , V_25 ) ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 , T_2 type , T_3 V_26 ,
T_2 V_11 , T_2 V_27 )
{
T_2 V_28 [ 27 ] = {} ;
return F_21 ( V_3 , V_16 , type ,
V_26 , V_11 ,
type == V_29 ? V_28 : NULL ) ;
}
static int F_22 ( struct V_2 * V_3 )
{
F_23 ( V_3 ) ;
return 0 ;
}
static int F_24 ( struct V_2 * V_3 )
{
F_25 ( V_3 ) ;
return 0 ;
}
static T_4 F_26 ( struct V_30 * V_31 ,
struct V_2 * V_3 )
{
V_3 -> V_32 . V_33 ++ ;
V_3 -> V_32 . V_34 += V_31 -> V_35 ;
F_27 ( V_31 ) ;
return V_36 ;
}
static int F_28 ( struct V_2 * V_3 , struct V_37 * V_38 ,
int V_39 )
{
struct V_40 * V_41 =
(struct V_40 * ) & V_38 -> V_42 ;
T_5 V_43 , V_17 ;
switch ( V_39 ) {
case V_44 :
V_43 = F_29 ( F_6 ( V_3 ) ) ;
V_17 = F_29 ( F_9 ( V_3 ) ) ;
if ( V_43 == V_45 ||
V_17 == V_46 )
return - V_47 ;
V_41 -> V_48 = V_49 ;
V_41 -> V_9 . V_50 = V_51 ;
V_41 -> V_9 . V_43 = V_43 ;
V_41 -> V_9 . V_17 = V_17 ;
return 0 ;
}
return - V_52 ;
}
static int F_30 ( struct V_2 * V_3 , void * V_53 )
{
return - V_54 ;
}
static void F_31 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_32 ( V_6 ) ;
F_33 ( V_3 ) ;
F_34 ( V_6 ) ;
}
static void F_35 ( struct V_2 * V_3 )
{
V_3 -> V_55 = V_56 ;
memset ( V_3 -> V_57 , 0xff , V_56 ) ;
V_3 -> V_58 = V_59 ;
V_3 -> V_60 = 2 ;
V_3 -> V_61 = 127 ;
V_3 -> V_62 = 10 ;
V_3 -> type = V_7 ;
V_3 -> V_63 = V_64 | V_65 ;
V_3 -> V_66 = 0 ;
V_3 -> V_67 = F_31 ;
}
static int F_36 ( struct V_68 * V_69 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
struct V_1 * V_6 = F_37 ( 0 ) ;
int V_70 ;
if ( ! V_6 )
return - V_71 ;
V_3 = F_38 ( sizeof( struct V_4 ) , L_1 , F_35 ) ;
if ( ! V_3 ) {
F_34 ( V_6 ) ;
return - V_71 ;
}
memcpy ( V_3 -> V_72 , L_2 ,
V_3 -> V_55 ) ;
V_6 -> V_73 [ 0 ] |= 0x7FFF800 ;
V_6 -> V_73 [ 3 ] |= 0x3fff ;
V_6 -> V_74 = 0xbf ;
V_3 -> V_75 = & V_76 ;
V_3 -> V_77 = & V_78 ;
V_5 = F_2 ( V_3 ) ;
V_5 -> V_6 = V_6 ;
F_39 ( V_6 , & V_69 -> V_3 ) ;
F_40 ( V_3 , & V_6 -> V_3 ) ;
F_41 ( V_69 , V_3 ) ;
V_70 = F_42 ( V_6 ) ;
if ( V_70 )
goto V_79;
V_70 = F_43 ( V_3 ) ;
if ( V_70 < 0 )
goto V_79;
F_44 ( & V_69 -> V_3 , L_3 ) ;
return 0 ;
V_79:
F_45 ( V_3 ) ;
return V_70 ;
}
static int F_46 ( struct V_68 * V_69 )
{
struct V_2 * V_3 = F_47 ( V_69 ) ;
F_45 ( V_3 ) ;
return 0 ;
}
static T_6 int F_48 ( void )
{
V_80 = F_49 (
L_4 , - 1 , NULL , 0 ) ;
return F_50 ( & V_81 ) ;
}
static T_7 void F_51 ( void )
{
F_52 ( & V_81 ) ;
F_53 ( V_80 ) ;
}
