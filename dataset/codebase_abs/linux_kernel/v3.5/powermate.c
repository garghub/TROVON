static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_5 * V_6 = & V_3 -> V_7 -> V_6 ;
int V_8 ;
switch ( V_1 -> V_9 ) {
case 0 :
break;
case - V_10 :
case - V_11 :
case - V_12 :
F_2 ( V_6 , L_1 ,
V_13 , V_1 -> V_9 ) ;
return;
default:
F_2 ( V_6 , L_2 ,
V_13 , V_1 -> V_9 ) ;
goto exit;
}
F_3 ( V_3 -> V_14 , V_15 , V_3 -> V_16 [ 0 ] & 0x01 ) ;
F_4 ( V_3 -> V_14 , V_17 , V_3 -> V_16 [ 1 ] ) ;
F_5 ( V_3 -> V_14 ) ;
exit:
V_8 = F_6 ( V_1 , V_18 ) ;
if ( V_8 )
F_7 ( V_6 , L_3 ,
V_13 , V_8 ) ;
}
static void F_8 ( struct V_2 * V_3 )
{
if ( V_3 -> V_19 == 0 )
return;
if ( V_3 -> V_20 -> V_9 == - V_21 )
return;
if ( V_3 -> V_19 & V_22 ) {
V_3 -> V_23 -> V_24 = F_9 ( V_25 ) ;
V_3 -> V_23 -> V_26 = F_9 ( V_3 -> V_27 ? 1 : 0 ) ;
V_3 -> V_19 &= ~ V_22 ;
} else if ( V_3 -> V_19 & V_28 ) {
V_3 -> V_23 -> V_24 = F_9 ( V_29 ) ;
V_3 -> V_23 -> V_26 = F_9 ( V_3 -> V_30 ? 1 : 0 ) ;
V_3 -> V_19 &= ~ V_28 ;
} else if ( V_3 -> V_19 & V_31 ) {
int V_32 , V_33 ;
if ( V_3 -> V_34 < 255 ) {
V_32 = 0 ;
V_33 = 255 - V_3 -> V_34 ;
} else if ( V_3 -> V_34 > 255 ) {
V_32 = 2 ;
V_33 = V_3 -> V_34 - 255 ;
} else {
V_32 = 1 ;
V_33 = 0 ;
}
V_3 -> V_23 -> V_24 = F_9 ( ( V_3 -> V_35 << 8 ) | V_36 ) ;
V_3 -> V_23 -> V_26 = F_9 ( ( V_33 << 8 ) | V_32 ) ;
V_3 -> V_19 &= ~ V_31 ;
} else if ( V_3 -> V_19 & V_37 ) {
V_3 -> V_23 -> V_24 = F_9 ( V_38 ) ;
V_3 -> V_23 -> V_26 = F_9 ( V_3 -> V_39 ) ;
V_3 -> V_19 &= ~ V_37 ;
} else {
F_10 ( V_40 L_4 ) ;
V_3 -> V_19 = 0 ;
return;
}
V_3 -> V_23 -> V_41 = 0x41 ;
V_3 -> V_23 -> V_42 = 0x01 ;
V_3 -> V_23 -> V_43 = 0 ;
F_11 ( V_3 -> V_20 , V_3 -> V_44 , F_12 ( V_3 -> V_44 , 0 ) ,
( void * ) V_3 -> V_23 , NULL , 0 ,
V_45 , V_3 ) ;
if ( F_6 ( V_3 -> V_20 , V_18 ) )
F_10 ( V_40 L_5 ) ;
}
static void V_45 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
unsigned long V_46 ;
if ( V_1 -> V_9 )
F_10 ( V_40 L_6 , V_1 -> V_9 ) ;
F_13 ( & V_3 -> V_47 , V_46 ) ;
F_8 ( V_3 ) ;
F_14 ( & V_3 -> V_47 , V_46 ) ;
}
static void F_15 ( struct V_2 * V_3 , int V_39 , int V_34 ,
int V_35 , int V_27 , int V_30 )
{
unsigned long V_46 ;
if ( V_34 < 0 )
V_34 = 0 ;
if ( V_35 < 0 )
V_35 = 0 ;
if ( V_34 > 510 )
V_34 = 510 ;
if ( V_35 > 2 )
V_35 = 2 ;
V_27 = ! ! V_27 ;
V_30 = ! ! V_30 ;
F_13 ( & V_3 -> V_47 , V_46 ) ;
if ( V_39 != V_3 -> V_39 ) {
V_3 -> V_39 = V_39 ;
V_3 -> V_19 |= V_37 ;
}
if ( V_27 != V_3 -> V_27 ) {
V_3 -> V_27 = V_27 ;
V_3 -> V_19 |= ( V_22 | V_37 ) ;
}
if ( V_30 != V_3 -> V_30 ) {
V_3 -> V_30 = V_30 ;
V_3 -> V_19 |= ( V_28 | V_37 ) ;
}
if ( V_34 != V_3 -> V_34 || V_35 != V_3 -> V_35 ) {
V_3 -> V_34 = V_34 ;
V_3 -> V_35 = V_35 ;
V_3 -> V_19 |= V_31 ;
}
F_8 ( V_3 ) ;
F_14 ( & V_3 -> V_47 , V_46 ) ;
}
static int F_16 ( struct V_48 * V_6 , unsigned int type , unsigned int V_49 , int V_50 )
{
unsigned int V_51 = ( unsigned int ) V_50 ;
struct V_2 * V_3 = F_17 ( V_6 ) ;
if ( type == V_52 && V_49 == V_53 ) {
int V_39 = V_51 & 0xFF ;
int V_34 = ( V_51 >> 8 ) & 0x1FF ;
int V_35 = ( V_51 >> 17 ) & 0x3 ;
int V_27 = ( V_51 >> 19 ) & 0x1 ;
int V_30 = ( V_51 >> 20 ) & 0x1 ;
F_15 ( V_3 , V_39 , V_34 , V_35 , V_27 , V_30 ) ;
}
return 0 ;
}
static int F_18 ( struct V_54 * V_44 , struct V_2 * V_3 )
{
V_3 -> V_16 = F_19 ( V_44 , V_55 ,
V_18 , & V_3 -> V_56 ) ;
if ( ! V_3 -> V_16 )
return - 1 ;
V_3 -> V_23 = F_20 ( sizeof( * ( V_3 -> V_23 ) ) , V_57 ) ;
if ( ! V_3 -> V_23 )
return - V_58 ;
return 0 ;
}
static void F_21 ( struct V_54 * V_44 , struct V_2 * V_3 )
{
F_22 ( V_44 , V_55 ,
V_3 -> V_16 , V_3 -> V_56 ) ;
F_23 ( V_3 -> V_23 ) ;
}
static int F_24 ( struct V_59 * V_7 , const struct V_60 * V_61 )
{
struct V_54 * V_44 = F_25 ( V_7 ) ;
struct V_62 * V_63 ;
struct V_64 * V_65 ;
struct V_2 * V_3 ;
struct V_48 * V_48 ;
int V_66 , V_67 ;
int error = - V_58 ;
V_63 = V_7 -> V_68 ;
V_65 = & V_63 -> V_65 [ 0 ] . V_69 ;
if ( ! F_26 ( V_65 ) )
return - V_70 ;
F_27 ( V_44 , F_12 ( V_44 , 0 ) ,
0x0a , V_71 | V_72 ,
0 , V_63 -> V_69 . V_73 , NULL , 0 ,
V_74 ) ;
V_3 = F_28 ( sizeof( struct V_2 ) , V_57 ) ;
V_48 = F_29 () ;
if ( ! V_3 || ! V_48 )
goto V_75;
if ( F_18 ( V_44 , V_3 ) )
goto V_76;
V_3 -> V_77 = F_30 ( 0 , V_57 ) ;
if ( ! V_3 -> V_77 )
goto V_76;
V_3 -> V_20 = F_30 ( 0 , V_57 ) ;
if ( ! V_3 -> V_20 )
goto V_78;
V_3 -> V_44 = V_44 ;
V_3 -> V_7 = V_7 ;
V_3 -> V_14 = V_48 ;
F_31 ( V_44 , V_3 -> V_79 , sizeof( V_3 -> V_79 ) ) ;
F_32 ( V_3 -> V_79 , L_7 , sizeof( V_3 -> V_79 ) ) ;
F_33 ( & V_3 -> V_47 ) ;
switch ( F_34 ( V_44 -> V_80 . V_81 ) ) {
case V_82 :
V_48 -> V_83 = V_84 ;
break;
case V_85 :
V_48 -> V_83 = V_86 ;
break;
default:
V_48 -> V_83 = V_86 ;
F_10 ( V_87 L_8 ,
F_34 ( V_44 -> V_80 . V_81 ) ) ;
}
V_48 -> V_79 = V_3 -> V_79 ;
F_35 ( V_44 , & V_48 -> V_61 ) ;
V_48 -> V_6 . V_88 = & V_7 -> V_6 ;
F_36 ( V_48 , V_3 ) ;
V_48 -> V_89 = F_16 ;
V_48 -> V_90 [ 0 ] = F_37 ( V_91 ) | F_37 ( V_92 ) |
F_37 ( V_52 ) ;
V_48 -> V_93 [ F_38 ( V_15 ) ] = F_37 ( V_15 ) ;
V_48 -> V_94 [ F_38 ( V_17 ) ] = F_37 ( V_17 ) ;
V_48 -> V_95 [ F_38 ( V_53 ) ] = F_37 ( V_53 ) ;
V_66 = F_39 ( V_44 , V_65 -> V_96 ) ;
V_67 = F_40 ( V_44 , V_66 , F_41 ( V_66 ) ) ;
if ( V_67 < V_97 || V_67 > V_55 ) {
F_10 ( V_87 L_9 ,
V_97 , V_55 , V_67 ) ;
V_67 = V_55 ;
}
F_42 ( V_3 -> V_77 , V_44 , V_66 , V_3 -> V_16 ,
V_67 , F_1 ,
V_3 , V_65 -> V_98 ) ;
V_3 -> V_77 -> V_99 = V_3 -> V_56 ;
V_3 -> V_77 -> V_100 |= V_101 ;
if ( F_6 ( V_3 -> V_77 , V_57 ) ) {
error = - V_70 ;
goto V_102;
}
error = F_43 ( V_3 -> V_14 ) ;
if ( error )
goto V_103;
V_3 -> V_19 = V_22 | V_28 | V_31 | V_37 ;
F_15 ( V_3 , 0x80 , 255 , 0 , 1 , 0 ) ;
F_44 ( V_7 , V_3 ) ;
return 0 ;
V_103: F_45 ( V_3 -> V_77 ) ;
V_102: F_46 ( V_3 -> V_20 ) ;
V_78: F_46 ( V_3 -> V_77 ) ;
V_76: F_21 ( V_44 , V_3 ) ;
V_75: F_47 ( V_48 ) ;
F_23 ( V_3 ) ;
return error ;
}
static void F_48 ( struct V_59 * V_7 )
{
struct V_2 * V_3 = F_49 ( V_7 ) ;
F_44 ( V_7 , NULL ) ;
if ( V_3 ) {
V_3 -> V_19 = 0 ;
F_45 ( V_3 -> V_77 ) ;
F_50 ( V_3 -> V_14 ) ;
F_46 ( V_3 -> V_77 ) ;
F_46 ( V_3 -> V_20 ) ;
F_21 ( F_25 ( V_7 ) , V_3 ) ;
F_23 ( V_3 ) ;
}
}
