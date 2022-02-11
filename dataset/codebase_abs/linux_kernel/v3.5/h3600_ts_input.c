static T_1 F_1 ( int V_1 , void * V_2 )
{
int V_3 = ( V_4 & V_5 ) ? 0 : 1 ;
struct V_6 * V_7 = V_2 ;
F_2 ( V_7 , V_8 , V_3 ) ;
F_3 ( V_7 ) ;
return V_9 ;
}
static T_1 F_4 ( int V_1 , void * V_2 )
{
int V_3 = ( V_4 & V_10 ) ? 0 : 1 ;
struct V_6 * V_7 = V_2 ;
F_2 ( V_7 , V_11 , 1 ) ;
F_2 ( V_7 , V_11 , V_3 ) ;
F_3 ( V_7 ) ;
return V_9 ;
}
unsigned int F_5 ( struct V_6 * V_7 , enum V_12 V_13 )
{
unsigned char V_14 = ( V_13 == V_15 ) ? 0 : V_16 ;
struct V_17 * V_18 = F_6 ( V_7 ) ;
F_7 ( V_18 -> V_19 , 1 ) ;
F_7 ( V_18 -> V_19 , V_13 ) ;
F_7 ( V_18 -> V_19 , V_14 ) ;
return 0 ;
}
static void F_8 ( struct V_17 * V_18 )
{
struct V_6 * V_7 = V_18 -> V_7 ;
static int V_20 = 0 ;
int V_21 , V_3 = 0 ;
switch ( V_18 -> V_22 ) {
case V_23 :
V_3 = ( V_18 -> V_24 [ 0 ] & 0x80 ) ? 0 : 1 ;
switch ( V_18 -> V_24 [ 0 ] & 0x7f ) {
case V_25 :
V_21 = V_26 ;
break;
case V_27 :
V_21 = V_28 ;
break;
case V_29 :
V_21 = V_30 ;
break;
case V_31 :
V_21 = V_32 ;
break;
case V_33 :
V_21 = V_34 ;
break;
case V_35 :
V_21 = V_36 ;
break;
case V_37 :
V_21 = V_38 ;
break;
case V_39 :
V_21 = V_40 ;
break;
case V_41 :
V_21 = V_42 ;
break;
default:
V_21 = 0 ;
}
if ( V_21 )
F_2 ( V_7 , V_21 , V_3 ) ;
break;
case V_43 :
if ( ! V_20 ) {
F_2 ( V_7 , V_44 , 1 ) ;
V_20 = 1 ;
}
if ( V_18 -> V_45 ) {
unsigned short V_46 , V_47 ;
V_46 = V_18 -> V_24 [ 0 ] ; V_46 <<= 8 ; V_46 += V_18 -> V_24 [ 1 ] ;
V_47 = V_18 -> V_24 [ 2 ] ; V_47 <<= 8 ; V_47 += V_18 -> V_24 [ 3 ] ;
F_9 ( V_7 , V_48 , V_46 ) ;
F_9 ( V_7 , V_49 , V_47 ) ;
} else {
F_2 ( V_7 , V_44 , 0 ) ;
V_20 = 0 ;
}
break;
default:
break;
}
F_3 ( V_7 ) ;
}
static int F_10 ( struct V_6 * V_7 , unsigned int type ,
unsigned int V_50 , int V_51 )
{
#if 0
struct h3600_dev *ts = input_get_drvdata(dev);
switch (type) {
case EV_LED: {
return 0;
}
}
return -1;
#endif
return 0 ;
}
static T_1 F_11 ( struct V_19 * V_19 , unsigned char V_52 ,
unsigned int V_53 )
{
struct V_17 * V_18 = F_12 ( V_19 ) ;
switch ( V_54 ) {
case V_55 :
if ( V_52 == V_56 )
V_54 = V_57 ;
break;
case V_57 :
V_18 -> V_22 = ( V_52 & 0xf0 ) >> 4 ;
V_18 -> V_45 = ( V_52 & 0xf ) ;
V_18 -> V_58 = 0 ;
if ( V_18 -> V_22 >= V_59 ) {
V_54 = V_55 ;
break;
}
V_18 -> V_60 = V_52 ;
V_54 = ( V_18 -> V_45 > 0 ) ? V_61 : V_62 ;
break;
case V_61 :
V_18 -> V_60 += V_52 ;
V_18 -> V_24 [ V_18 -> V_58 ] = V_52 ;
if ( ++ V_18 -> V_58 == V_18 -> V_45 )
V_54 = V_62 ;
break;
case V_62 :
V_54 = V_55 ;
if ( V_52 == V_63 || V_52 == V_18 -> V_60 )
F_8 ( V_18 ) ;
break;
default:
F_13 ( L_1 ) ;
break;
}
return V_9 ;
}
static int F_14 ( struct V_19 * V_19 , struct V_64 * V_65 )
{
struct V_17 * V_18 ;
struct V_6 * V_6 ;
int V_66 ;
V_18 = F_15 ( sizeof( struct V_17 ) , V_67 ) ;
V_6 = F_16 () ;
if ( ! V_18 || ! V_6 ) {
V_66 = - V_68 ;
goto V_69;
}
V_18 -> V_19 = V_19 ;
V_18 -> V_7 = V_6 ;
snprintf ( V_18 -> V_70 , sizeof( V_18 -> V_70 ) , L_2 , V_19 -> V_70 ) ;
V_6 -> V_71 = L_3 ;
V_6 -> V_70 = V_18 -> V_70 ;
V_6 -> V_72 . V_73 = V_74 ;
V_6 -> V_72 . V_75 = V_76 ;
V_6 -> V_72 . V_77 = 0x0666 ;
V_6 -> V_72 . V_78 = 0x0100 ;
V_6 -> V_7 . V_79 = & V_19 -> V_7 ;
F_17 ( V_6 , V_18 ) ;
V_6 -> V_22 = F_10 ;
V_6 -> V_80 [ 0 ] = F_18 ( V_81 ) | F_18 ( V_82 ) |
F_18 ( V_83 ) | F_18 ( V_84 ) ;
V_6 -> V_85 [ 0 ] = F_18 ( V_86 ) ;
F_19 ( V_6 , V_48 , 60 , 985 , 0 , 0 ) ;
F_19 ( V_6 , V_49 , 35 , 1024 , 0 , 0 ) ;
F_20 ( V_26 , V_6 -> V_87 ) ;
F_20 ( V_32 , V_6 -> V_87 ) ;
F_20 ( V_28 , V_6 -> V_87 ) ;
F_20 ( V_30 , V_6 -> V_87 ) ;
F_20 ( V_34 , V_6 -> V_87 ) ;
F_20 ( V_36 , V_6 -> V_87 ) ;
F_20 ( V_38 , V_6 -> V_87 ) ;
F_20 ( V_40 , V_6 -> V_87 ) ;
F_20 ( V_42 , V_6 -> V_87 ) ;
F_20 ( V_8 , V_6 -> V_87 ) ;
F_20 ( V_11 , V_6 -> V_87 ) ;
F_20 ( V_44 , V_6 -> V_87 ) ;
F_21 ( V_5 , V_88 ) ;
F_21 ( V_10 , V_89 ) ;
if ( F_22 ( V_90 , F_1 ,
V_91 , L_4 , V_18 -> V_7 ) ) {
F_13 ( V_92 L_5 ) ;
V_66 = - V_93 ;
goto V_69;
}
if ( F_22 ( V_94 , F_4 ,
V_91 , L_6 , V_18 -> V_7 ) ) {
F_13 ( V_92 L_7 ) ;
V_66 = - V_93 ;
goto V_95;
}
F_23 ( V_19 , V_18 ) ;
V_66 = F_24 ( V_19 , V_65 ) ;
if ( V_66 )
goto V_96;
V_66 = F_25 ( V_18 -> V_7 ) ;
if ( V_66 )
goto V_97;
return 0 ;
V_97: F_26 ( V_19 ) ;
V_96: F_23 ( V_19 , NULL ) ;
F_27 ( V_94 , V_18 -> V_7 ) ;
V_95: F_27 ( V_90 , V_18 -> V_7 ) ;
V_69: F_28 ( V_6 ) ;
F_29 ( V_18 ) ;
return V_66 ;
}
static void F_30 ( struct V_19 * V_19 )
{
struct V_17 * V_18 = F_12 ( V_19 ) ;
F_27 ( V_90 , V_18 -> V_7 ) ;
F_27 ( V_94 , V_18 -> V_7 ) ;
F_31 ( V_18 -> V_7 ) ;
F_32 ( V_18 -> V_7 ) ;
F_26 ( V_19 ) ;
F_23 ( V_19 , NULL ) ;
F_33 ( V_18 -> V_7 ) ;
F_29 ( V_18 ) ;
}
