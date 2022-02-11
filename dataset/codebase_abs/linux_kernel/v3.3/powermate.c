static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
int V_5 ;
switch ( V_1 -> V_6 ) {
case 0 :
break;
case - V_7 :
case - V_8 :
case - V_9 :
F_2 ( L_1 , V_10 , V_1 -> V_6 ) ;
return;
default:
F_2 ( L_2 , V_10 , V_1 -> V_6 ) ;
goto exit;
}
F_3 ( V_3 -> V_11 , V_12 , V_3 -> V_13 [ 0 ] & 0x01 ) ;
F_4 ( V_3 -> V_11 , V_14 , V_3 -> V_13 [ 1 ] ) ;
F_5 ( V_3 -> V_11 ) ;
exit:
V_5 = F_6 ( V_1 , V_15 ) ;
if ( V_5 )
F_7 ( L_3 ,
V_10 , V_5 ) ;
}
static void F_8 ( struct V_2 * V_3 )
{
if ( V_3 -> V_16 == 0 )
return;
if ( V_3 -> V_17 -> V_6 == - V_18 )
return;
if ( V_3 -> V_16 & V_19 ) {
V_3 -> V_20 -> V_21 = F_9 ( V_22 ) ;
V_3 -> V_20 -> V_23 = F_9 ( V_3 -> V_24 ? 1 : 0 ) ;
V_3 -> V_16 &= ~ V_19 ;
} else if ( V_3 -> V_16 & V_25 ) {
V_3 -> V_20 -> V_21 = F_9 ( V_26 ) ;
V_3 -> V_20 -> V_23 = F_9 ( V_3 -> V_27 ? 1 : 0 ) ;
V_3 -> V_16 &= ~ V_25 ;
} else if ( V_3 -> V_16 & V_28 ) {
int V_29 , V_30 ;
if ( V_3 -> V_31 < 255 ) {
V_29 = 0 ;
V_30 = 255 - V_3 -> V_31 ;
} else if ( V_3 -> V_31 > 255 ) {
V_29 = 2 ;
V_30 = V_3 -> V_31 - 255 ;
} else {
V_29 = 1 ;
V_30 = 0 ;
}
V_3 -> V_20 -> V_21 = F_9 ( ( V_3 -> V_32 << 8 ) | V_33 ) ;
V_3 -> V_20 -> V_23 = F_9 ( ( V_30 << 8 ) | V_29 ) ;
V_3 -> V_16 &= ~ V_28 ;
} else if ( V_3 -> V_16 & V_34 ) {
V_3 -> V_20 -> V_21 = F_9 ( V_35 ) ;
V_3 -> V_20 -> V_23 = F_9 ( V_3 -> V_36 ) ;
V_3 -> V_16 &= ~ V_34 ;
} else {
F_10 ( V_37 L_4 ) ;
V_3 -> V_16 = 0 ;
return;
}
V_3 -> V_20 -> V_38 = 0x41 ;
V_3 -> V_20 -> V_39 = 0x01 ;
V_3 -> V_20 -> V_40 = 0 ;
F_11 ( V_3 -> V_17 , V_3 -> V_41 , F_12 ( V_3 -> V_41 , 0 ) ,
( void * ) V_3 -> V_20 , NULL , 0 ,
V_42 , V_3 ) ;
if ( F_6 ( V_3 -> V_17 , V_15 ) )
F_10 ( V_37 L_5 ) ;
}
static void V_42 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
unsigned long V_43 ;
if ( V_1 -> V_6 )
F_10 ( V_37 L_6 , V_1 -> V_6 ) ;
F_13 ( & V_3 -> V_44 , V_43 ) ;
F_8 ( V_3 ) ;
F_14 ( & V_3 -> V_44 , V_43 ) ;
}
static void F_15 ( struct V_2 * V_3 , int V_36 , int V_31 ,
int V_32 , int V_24 , int V_27 )
{
unsigned long V_43 ;
if ( V_31 < 0 )
V_31 = 0 ;
if ( V_32 < 0 )
V_32 = 0 ;
if ( V_31 > 510 )
V_31 = 510 ;
if ( V_32 > 2 )
V_32 = 2 ;
V_24 = ! ! V_24 ;
V_27 = ! ! V_27 ;
F_13 ( & V_3 -> V_44 , V_43 ) ;
if ( V_36 != V_3 -> V_36 ) {
V_3 -> V_36 = V_36 ;
V_3 -> V_16 |= V_34 ;
}
if ( V_24 != V_3 -> V_24 ) {
V_3 -> V_24 = V_24 ;
V_3 -> V_16 |= ( V_19 | V_34 ) ;
}
if ( V_27 != V_3 -> V_27 ) {
V_3 -> V_27 = V_27 ;
V_3 -> V_16 |= ( V_25 | V_34 ) ;
}
if ( V_31 != V_3 -> V_31 || V_32 != V_3 -> V_32 ) {
V_3 -> V_31 = V_31 ;
V_3 -> V_32 = V_32 ;
V_3 -> V_16 |= V_28 ;
}
F_8 ( V_3 ) ;
F_14 ( & V_3 -> V_44 , V_43 ) ;
}
static int F_16 ( struct V_45 * V_46 , unsigned int type , unsigned int V_47 , int V_48 )
{
unsigned int V_49 = ( unsigned int ) V_48 ;
struct V_2 * V_3 = F_17 ( V_46 ) ;
if ( type == V_50 && V_47 == V_51 ) {
int V_36 = V_49 & 0xFF ;
int V_31 = ( V_49 >> 8 ) & 0x1FF ;
int V_32 = ( V_49 >> 17 ) & 0x3 ;
int V_24 = ( V_49 >> 19 ) & 0x1 ;
int V_27 = ( V_49 >> 20 ) & 0x1 ;
F_15 ( V_3 , V_36 , V_31 , V_32 , V_24 , V_27 ) ;
}
return 0 ;
}
static int F_18 ( struct V_52 * V_41 , struct V_2 * V_3 )
{
V_3 -> V_13 = F_19 ( V_41 , V_53 ,
V_15 , & V_3 -> V_54 ) ;
if ( ! V_3 -> V_13 )
return - 1 ;
V_3 -> V_20 = F_20 ( sizeof( * ( V_3 -> V_20 ) ) , V_55 ) ;
if ( ! V_3 -> V_20 )
return - V_56 ;
return 0 ;
}
static void F_21 ( struct V_52 * V_41 , struct V_2 * V_3 )
{
F_22 ( V_41 , V_53 ,
V_3 -> V_13 , V_3 -> V_54 ) ;
F_23 ( V_3 -> V_20 ) ;
}
static int F_24 ( struct V_57 * V_58 , const struct V_59 * V_60 )
{
struct V_52 * V_41 = F_25 ( V_58 ) ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
struct V_2 * V_3 ;
struct V_45 * V_45 ;
int V_65 , V_66 ;
int error = - V_56 ;
V_62 = V_58 -> V_67 ;
V_64 = & V_62 -> V_64 [ 0 ] . V_68 ;
if ( ! F_26 ( V_64 ) )
return - V_69 ;
F_27 ( V_41 , F_12 ( V_41 , 0 ) ,
0x0a , V_70 | V_71 ,
0 , V_62 -> V_68 . V_72 , NULL , 0 ,
V_73 ) ;
V_3 = F_28 ( sizeof( struct V_2 ) , V_55 ) ;
V_45 = F_29 () ;
if ( ! V_3 || ! V_45 )
goto V_74;
if ( F_18 ( V_41 , V_3 ) )
goto V_75;
V_3 -> V_76 = F_30 ( 0 , V_55 ) ;
if ( ! V_3 -> V_76 )
goto V_75;
V_3 -> V_17 = F_30 ( 0 , V_55 ) ;
if ( ! V_3 -> V_17 )
goto V_77;
V_3 -> V_41 = V_41 ;
V_3 -> V_11 = V_45 ;
F_31 ( V_41 , V_3 -> V_78 , sizeof( V_3 -> V_78 ) ) ;
F_32 ( V_3 -> V_78 , L_7 , sizeof( V_3 -> V_78 ) ) ;
F_33 ( & V_3 -> V_44 ) ;
switch ( F_34 ( V_41 -> V_79 . V_80 ) ) {
case V_81 :
V_45 -> V_82 = V_83 ;
break;
case V_84 :
V_45 -> V_82 = V_85 ;
break;
default:
V_45 -> V_82 = V_85 ;
F_10 ( V_86 L_8 ,
F_34 ( V_41 -> V_79 . V_80 ) ) ;
}
V_45 -> V_78 = V_3 -> V_78 ;
F_35 ( V_41 , & V_45 -> V_60 ) ;
V_45 -> V_46 . V_87 = & V_58 -> V_46 ;
F_36 ( V_45 , V_3 ) ;
V_45 -> V_88 = F_16 ;
V_45 -> V_89 [ 0 ] = F_37 ( V_90 ) | F_37 ( V_91 ) |
F_37 ( V_50 ) ;
V_45 -> V_92 [ F_38 ( V_12 ) ] = F_37 ( V_12 ) ;
V_45 -> V_93 [ F_38 ( V_14 ) ] = F_37 ( V_14 ) ;
V_45 -> V_94 [ F_38 ( V_51 ) ] = F_37 ( V_51 ) ;
V_65 = F_39 ( V_41 , V_64 -> V_95 ) ;
V_66 = F_40 ( V_41 , V_65 , F_41 ( V_65 ) ) ;
if ( V_66 < V_96 || V_66 > V_53 ) {
F_10 ( V_86 L_9 ,
V_96 , V_53 , V_66 ) ;
V_66 = V_53 ;
}
F_42 ( V_3 -> V_76 , V_41 , V_65 , V_3 -> V_13 ,
V_66 , F_1 ,
V_3 , V_64 -> V_97 ) ;
V_3 -> V_76 -> V_98 = V_3 -> V_54 ;
V_3 -> V_76 -> V_99 |= V_100 ;
if ( F_6 ( V_3 -> V_76 , V_55 ) ) {
error = - V_69 ;
goto V_101;
}
error = F_43 ( V_3 -> V_11 ) ;
if ( error )
goto V_102;
V_3 -> V_16 = V_19 | V_25 | V_28 | V_34 ;
F_15 ( V_3 , 0x80 , 255 , 0 , 1 , 0 ) ;
F_44 ( V_58 , V_3 ) ;
return 0 ;
V_102: F_45 ( V_3 -> V_76 ) ;
V_101: F_46 ( V_3 -> V_17 ) ;
V_77: F_46 ( V_3 -> V_76 ) ;
V_75: F_21 ( V_41 , V_3 ) ;
V_74: F_47 ( V_45 ) ;
F_23 ( V_3 ) ;
return error ;
}
static void F_48 ( struct V_57 * V_58 )
{
struct V_2 * V_3 = F_49 ( V_58 ) ;
F_44 ( V_58 , NULL ) ;
if ( V_3 ) {
V_3 -> V_16 = 0 ;
F_45 ( V_3 -> V_76 ) ;
F_50 ( V_3 -> V_11 ) ;
F_46 ( V_3 -> V_76 ) ;
F_46 ( V_3 -> V_17 ) ;
F_21 ( F_25 ( V_58 ) , V_3 ) ;
F_23 ( V_3 ) ;
}
}
