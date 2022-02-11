static int
F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_2 , L_1 ,
( unsigned long ) V_5 -> V_7 ) ;
F_3 ( V_2 , L_2 ) ;
if ( V_5 -> V_8 . V_9 [ V_5 -> V_8 . V_10 ] == NULL )
F_3 ( V_2 , L_3 ) ;
else if ( V_5 -> V_8 . V_9 [ V_5 -> V_8 . V_11 ] )
F_3 ( V_2 , L_4 ) ;
else
F_3 ( V_2 , L_5 ) ;
F_3 ( V_2 , L_6 ) ;
F_2 ( V_2 , L_7 ,
V_5 -> V_8 . V_12 ) ;
F_2 ( V_2 , L_8 ,
( unsigned int ) V_5 -> V_13 ) ;
switch ( V_5 -> V_13 ) {
case V_14 :
F_3 ( V_2 , L_9 ) ;
break;
case V_15 :
F_3 ( V_2 , L_10 ) ;
break;
case V_16 :
F_3 ( V_2 , L_11 ) ;
break;
default:
F_3 ( V_2 , L_12 ) ;
break;
}
F_3 ( V_2 , L_13 ) ;
F_2 ( V_2 , L_14 ,
V_5 -> V_17 -> V_18 ) ;
F_2 ( V_2 , L_15 ,
V_5 -> V_19 ) ;
F_2 ( V_2 , L_16 ,
V_5 -> V_20 ) ;
F_2 ( V_2 , L_17 ,
( unsigned long ) V_5 -> V_17 -> V_21 ) ;
F_2 ( V_2 , L_18 ,
V_5 -> V_17 -> V_22 ) ;
F_2 ( V_2 , L_19 ,
( unsigned int ) V_5 -> V_17 -> V_23 ) ;
F_2 ( V_2 , L_20 ,
( unsigned int ) V_5 -> V_24 ) ;
F_2 ( V_2 , L_21 ,
( unsigned int ) V_5 -> V_25 ) ;
return 0 ;
}
static int
F_4 ( struct V_26 * V_26 , struct V_27 * V_27 )
{
return F_5 ( V_27 , F_1 , V_26 -> V_28 ) ;
}
void
F_6 ( struct V_4 * V_5 )
{
struct V_29 * V_30 ;
V_30 = F_7 ( F_8 ( & V_5 -> V_31 -> V_32 ) , NULL ) ;
V_5 -> V_30 = V_30 ;
if ( F_9 ( V_30 ) || ! V_30 ) {
F_10 ( L_22 ,
F_8 ( & V_5 -> V_31 -> V_32 ) ) ;
return;
}
F_11 ( L_23 , V_33 | V_34 , V_30 , V_5 ,
& V_35 ) ;
}
void
F_12 ( struct V_4 * V_5 )
{
F_13 ( V_5 -> V_30 ) ;
}
void
F_6 ( struct V_4 * V_5 )
{
}
void
F_12 ( struct V_4 * V_5 )
{
}
static void
F_14 ( struct V_36 * V_32 , struct V_37 * V_38 )
{
struct V_4 * V_5 = F_15 ( V_32 ) ;
F_16 ( V_38 -> V_39 , V_40 , sizeof( V_38 -> V_39 ) ) ;
F_16 ( V_38 -> V_41 , V_42 , sizeof( V_38 -> V_41 ) ) ;
F_16 ( V_38 -> V_43 , L_24 , sizeof( V_38 -> V_43 ) ) ;
F_16 ( V_38 -> V_44 , F_8 ( & V_5 -> V_17 -> V_32 ) ,
sizeof( V_38 -> V_44 ) ) ;
}
static int
F_17 ( struct V_36 * V_32 ,
struct V_45 * V_46 )
{
F_18 ( V_46 , V_47 ) ;
F_19 ( V_46 , V_47 , 10baseT_Half ) ;
V_46 -> V_48 . V_49 = V_50 ;
V_46 -> V_48 . V_51 = V_52 ;
V_46 -> V_48 . V_53 = V_54 ;
V_46 -> V_48 . V_55 = V_56 ;
return 0 ;
}
static void
F_20 ( struct V_36 * V_32 , struct V_57 * V_58 , T_1 * V_59 )
{
struct V_4 * V_5 = F_15 ( V_32 ) ;
struct V_60 * V_61 = & V_5 -> V_62 ;
memcpy ( V_59 , V_61 , F_21 ( V_63 ) * sizeof( T_1 ) ) ;
}
static void
F_22 ( struct V_36 * V_32 , T_2 V_64 , T_3 * V_65 )
{
switch ( V_64 ) {
case V_66 :
memcpy ( V_65 , & V_63 ,
sizeof( V_63 ) ) ;
break;
default:
F_23 ( 1 ) ;
break;
}
}
static int
F_24 ( struct V_36 * V_32 , int V_67 )
{
switch ( V_67 ) {
case V_66 :
return F_21 ( V_63 ) ;
default:
return - V_68 ;
}
}
static int
F_25 ( struct V_36 * V_32 )
{
return sizeof( T_2 ) * V_69 ;
}
static void
F_26 ( struct V_36 * V_32 , struct V_70 * V_71 , void * V_38 )
{
struct V_4 * V_5 = F_15 ( V_32 ) ;
T_2 * V_72 = V_38 ;
unsigned int V_73 ;
V_71 -> V_41 = 1 ;
memset ( V_72 , 0 , sizeof( T_2 ) * V_69 ) ;
for ( V_73 = 0 ; V_73 < F_21 ( V_74 ) ; V_73 ++ ) {
T_4 V_75 , V_76 ;
F_27 ( V_5 , V_74 [ V_73 ] , & V_76 ) ;
V_75 = V_74 [ V_73 ] >> 8 ;
V_72 [ V_75 ] = V_76 ;
}
}
static void
F_28 ( struct V_36 * V_32 , struct V_77 * V_78 )
{
struct V_4 * V_5 = F_15 ( V_32 ) ;
V_78 -> V_79 = 4 ;
V_78 -> V_80 = V_81 ;
V_78 -> V_82 = 4 ;
V_78 -> V_83 = V_5 -> V_8 . V_84 ;
}
static int
F_29 ( struct V_36 * V_32 , struct V_77 * V_78 )
{
struct V_4 * V_5 = F_15 ( V_32 ) ;
if ( ( V_78 -> V_82 ) ||
( V_78 -> V_85 ) ||
( V_78 -> V_86 ) )
return - V_68 ;
if ( F_30 ( V_32 ) )
F_31 ( V_32 ) ;
V_5 -> V_8 . V_84 = F_32 ( T_2 , V_78 -> V_83 , V_87 ) ;
V_5 -> V_8 . V_84 = F_33 ( T_4 , V_5 -> V_8 . V_84 , V_81 ) ;
if ( F_30 ( V_32 ) )
F_34 ( V_32 ) ;
return 0 ;
}
void F_35 ( struct V_36 * V_32 )
{
V_32 -> V_88 = & V_89 ;
}
