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
F_17 ( struct V_36 * V_32 , struct V_45 * V_46 )
{
V_46 -> V_47 = V_48 ;
V_46 -> V_49 = V_50 ;
F_18 ( V_46 , V_51 ) ;
V_46 -> V_52 = V_53 ;
V_46 -> V_54 = V_55 ;
V_46 -> V_56 = V_57 ;
return 0 ;
}
static void
F_19 ( struct V_36 * V_32 , struct V_58 * V_59 , T_1 * V_60 )
{
struct V_4 * V_5 = F_15 ( V_32 ) ;
struct V_61 * V_62 = & V_5 -> V_63 ;
memcpy ( V_60 , V_62 , F_20 ( V_64 ) * sizeof( T_1 ) ) ;
}
static void
F_21 ( struct V_36 * V_32 , T_2 V_65 , T_3 * V_66 )
{
switch ( V_65 ) {
case V_67 :
memcpy ( V_66 , & V_64 ,
sizeof( V_64 ) ) ;
break;
default:
F_22 ( 1 ) ;
break;
}
}
static int
F_23 ( struct V_36 * V_32 , int V_68 )
{
switch ( V_68 ) {
case V_67 :
return F_20 ( V_64 ) ;
default:
return - V_69 ;
}
}
static int
F_24 ( struct V_36 * V_32 )
{
return sizeof( T_2 ) * V_70 ;
}
static void
F_25 ( struct V_36 * V_32 , struct V_71 * V_72 , void * V_38 )
{
struct V_4 * V_5 = F_15 ( V_32 ) ;
T_2 * V_73 = V_38 ;
unsigned int V_74 ;
V_72 -> V_41 = 1 ;
memset ( V_73 , 0 , sizeof( T_2 ) * V_70 ) ;
for ( V_74 = 0 ; V_74 < F_20 ( V_75 ) ; V_74 ++ ) {
T_4 V_76 , V_77 ;
F_26 ( V_5 , V_75 [ V_74 ] , & V_77 ) ;
V_76 = V_75 [ V_74 ] >> 8 ;
V_73 [ V_76 ] = V_77 ;
}
}
static void
F_27 ( struct V_36 * V_32 , struct V_78 * V_79 )
{
struct V_4 * V_5 = F_15 ( V_32 ) ;
V_79 -> V_80 = 4 ;
V_79 -> V_81 = V_82 ;
V_79 -> V_83 = 4 ;
V_79 -> V_84 = V_5 -> V_8 . V_85 ;
}
static int
F_28 ( struct V_36 * V_32 , struct V_78 * V_79 )
{
struct V_4 * V_5 = F_15 ( V_32 ) ;
if ( ( V_79 -> V_83 ) ||
( V_79 -> V_86 ) ||
( V_79 -> V_87 ) )
return - V_69 ;
if ( F_29 ( V_32 ) )
F_30 ( V_32 ) ;
V_5 -> V_8 . V_85 = F_31 ( T_2 , V_79 -> V_84 , V_88 ) ;
V_5 -> V_8 . V_85 = F_32 ( T_4 , V_5 -> V_8 . V_85 , V_82 ) ;
if ( F_29 ( V_32 ) )
F_33 ( V_32 ) ;
return 0 ;
}
void F_34 ( struct V_36 * V_32 )
{
V_32 -> V_89 = & V_90 ;
}
