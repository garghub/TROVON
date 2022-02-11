static void F_1 ( T_1 * V_1 , void * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
T_2 V_7 = ( V_6 -> V_8 - V_6 -> V_9 ) * ( V_6 -> V_10 - V_6 -> y1 ) ;
unsigned int V_11 , V_12 ;
T_1 * V_13 , * V_14 , V_15 ;
V_14 = F_2 ( V_7 , V_16 ) ;
if ( ! V_14 )
return;
F_3 ( V_14 , V_2 , V_4 , V_6 ) ;
V_13 = V_14 ;
for ( V_12 = V_6 -> y1 ; V_12 < V_6 -> V_10 ; V_12 ++ ) {
for ( V_11 = V_6 -> V_9 ; V_11 < V_6 -> V_8 ; V_11 += 3 ) {
V_15 = V_17 [ * V_13 ++ >> 6 ] << 5 ;
V_15 |= V_17 [ * V_13 ++ >> 6 ] << 2 ;
V_15 |= V_17 [ * V_13 ++ >> 6 ] >> 1 ;
* V_1 ++ = V_15 ;
}
}
F_4 ( V_14 ) ;
}
static int F_5 ( void * V_1 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_18 * V_19 = F_6 ( V_4 , 0 ) ;
struct V_20 * V_21 = V_19 -> V_22 . V_21 ;
void * V_13 = V_19 -> V_2 ;
int V_23 = 0 ;
if ( V_21 ) {
V_23 = F_7 ( V_21 -> V_24 ,
V_25 ) ;
if ( V_23 )
return V_23 ;
}
F_1 ( V_1 , V_13 , V_4 , V_6 ) ;
if ( V_21 )
V_23 = F_8 ( V_21 -> V_24 ,
V_25 ) ;
return V_23 ;
}
static int F_9 ( struct V_3 * V_4 ,
struct V_26 * V_27 , unsigned int V_28 ,
unsigned int V_29 , struct V_5 * V_30 ,
unsigned int V_31 )
{
struct V_32 * V_33 = V_4 -> V_34 -> V_35 ;
struct V_36 * V_37 = F_10 ( V_33 ) ;
struct V_5 V_6 ;
int V_38 , V_39 ;
int V_23 = 0 ;
F_11 ( & V_33 -> V_40 ) ;
if ( ! V_37 -> V_41 )
goto V_42;
if ( V_33 -> V_43 . V_44 . V_4 != V_4 )
goto V_42;
F_12 ( & V_6 , V_30 , V_31 , V_28 , V_4 -> V_45 ,
V_4 -> V_46 ) ;
V_6 . V_9 = F_13 ( V_6 . V_9 , 3 ) ;
V_6 . V_8 = F_14 ( V_6 . V_8 , 3 ) ;
F_15 ( L_1 , V_4 -> V_22 . V_47 ,
V_6 . V_9 , V_6 . V_8 , V_6 . y1 , V_6 . V_10 ) ;
V_23 = F_5 ( V_37 -> V_48 , V_4 , & V_6 ) ;
if ( V_23 )
goto V_42;
V_38 = V_6 . V_9 / 3 ;
V_39 = V_6 . V_8 / 3 ;
F_16 ( V_37 , V_49 ,
( V_38 >> 8 ) & 0xFF , V_38 & 0xFF ,
( V_39 >> 8 ) & 0xFF , ( V_39 - 1 ) & 0xFF ) ;
F_16 ( V_37 , V_50 ,
( V_6 . y1 >> 8 ) & 0xFF , V_6 . y1 & 0xFF ,
( V_6 . V_10 >> 8 ) & 0xFF , ( V_6 . V_10 - 1 ) & 0xFF ) ;
V_23 = F_17 ( V_37 , V_51 ,
( T_1 * ) V_37 -> V_48 ,
( V_39 - V_38 ) * ( V_6 . V_10 - V_6 . y1 ) ) ;
V_42:
F_18 ( & V_33 -> V_40 ) ;
if ( V_23 )
F_19 ( V_4 -> V_34 -> V_34 , L_2 ,
V_23 ) ;
return V_23 ;
}
static void F_20 ( struct V_52 * V_43 ,
struct V_53 * V_54 )
{
struct V_32 * V_33 = F_21 ( V_43 ) ;
struct V_36 * V_37 = F_10 ( V_33 ) ;
struct V_3 * V_4 = V_43 -> V_44 . V_4 ;
struct V_55 * V_34 = V_33 -> V_56 -> V_34 ;
int V_23 ;
T_1 V_57 ;
F_22 ( L_3 ) ;
F_23 ( V_37 ) ;
V_23 = F_16 ( V_37 , V_58 , 0x9f ) ;
if ( V_23 ) {
F_24 ( V_34 , L_4 , V_23 ) ;
return;
}
F_16 ( V_37 , V_59 , 0x00 ) ;
F_25 ( 10 ) ;
F_16 ( V_37 , V_60 ) ;
F_25 ( 20 ) ;
F_16 ( V_37 , V_61 ) ;
F_16 ( V_37 , V_62 ) ;
F_16 ( V_37 , V_63 ) ;
F_25 ( 50 ) ;
F_16 ( V_37 , V_64 , 0x00 ) ;
F_16 ( V_37 , V_65 , 0xe3 , 0x00 ) ;
F_16 ( V_37 , V_66 , 0x02 ) ;
F_16 ( V_37 , V_67 , 0x04 ) ;
F_16 ( V_37 , V_68 , 0x1d ) ;
F_16 ( V_37 , V_69 , 0x00 ) ;
F_16 ( V_37 , V_70 ) ;
F_16 ( V_37 , V_71 , 0x02 ) ;
switch ( V_37 -> V_72 ) {
default:
V_57 = 0x00 ;
break;
case 90 :
V_57 = V_73 ;
break;
case 180 :
V_57 = V_74 | V_73 ;
break;
case 270 :
V_57 = V_74 ;
break;
}
F_16 ( V_37 , V_75 , V_57 ) ;
F_16 ( V_37 , V_76 , 0x7f ) ;
F_16 ( V_37 , V_77 , 0xa0 ) ;
F_16 ( V_37 , V_78 , 0x00 , 0x00 , 0x00 , 0x77 ) ;
F_16 ( V_37 , V_79 ) ;
F_25 ( 100 ) ;
F_16 ( V_37 , V_80 ) ;
V_37 -> V_41 = true ;
if ( V_4 )
V_4 -> V_81 -> V_82 ( V_4 , NULL , 0 , 0 , NULL , 0 ) ;
}
static void F_26 ( struct V_52 * V_43 )
{
struct V_32 * V_33 = F_21 ( V_43 ) ;
struct V_36 * V_37 = F_10 ( V_33 ) ;
F_22 ( L_3 ) ;
if ( ! V_37 -> V_41 )
return;
F_16 ( V_37 , V_63 ) ;
V_37 -> V_41 = false ;
}
static int F_27 ( struct V_55 * V_34 , struct V_36 * V_37 ,
const struct V_83 * V_84 ,
struct V_85 * V_86 , const struct V_87 * V_88 ,
unsigned int V_72 )
{
T_2 V_89 = ( V_88 -> V_90 + 2 ) / 3 * V_88 -> V_91 ;
struct V_32 * V_33 = & V_37 -> V_92 ;
int V_23 ;
F_28 ( & V_37 -> V_93 ) ;
V_37 -> V_48 = F_29 ( V_34 , V_89 , V_16 ) ;
if ( ! V_37 -> V_48 )
return - V_94 ;
V_23 = F_30 ( V_34 , V_33 , & V_95 , V_86 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_31 ( V_33 , V_84 ,
V_96 ,
V_97 ,
F_32 ( V_97 ) ,
V_88 , V_72 ) ;
if ( V_23 )
return V_23 ;
V_33 -> V_56 -> V_98 . V_99 = 32 ;
V_37 -> V_72 = V_72 ;
F_33 ( V_33 -> V_56 ) ;
F_22 ( L_5 ,
V_33 -> V_56 -> V_98 . V_99 , V_72 ) ;
return 0 ;
}
static int F_34 ( struct V_100 * V_101 )
{
struct V_55 * V_34 = & V_101 -> V_34 ;
struct V_32 * V_33 ;
struct V_36 * V_37 ;
struct V_102 * V_103 ;
T_3 V_72 = 0 ;
int V_23 ;
V_37 = F_35 ( V_34 , sizeof( * V_37 ) , V_16 ) ;
if ( ! V_37 )
return - V_94 ;
V_37 -> V_104 = F_36 ( V_34 , L_6 , V_105 ) ;
if ( F_37 ( V_37 -> V_104 ) ) {
F_24 ( V_34 , L_7 ) ;
return F_38 ( V_37 -> V_104 ) ;
}
V_103 = F_36 ( V_34 , L_8 , V_106 ) ;
if ( F_37 ( V_103 ) ) {
F_24 ( V_34 , L_9 ) ;
return F_38 ( V_103 ) ;
}
F_39 ( V_34 , L_10 , & V_72 ) ;
V_23 = F_40 ( V_101 , V_37 , V_103 ) ;
if ( V_23 )
return V_23 ;
V_37 -> V_107 = NULL ;
V_37 -> V_108 = true ;
V_23 = F_27 ( & V_101 -> V_34 , V_37 , & V_109 , & V_110 ,
& V_111 , V_72 ) ;
if ( V_23 )
return V_23 ;
V_33 = & V_37 -> V_92 ;
V_23 = F_41 ( V_33 ) ;
if ( V_23 )
return V_23 ;
F_42 ( V_101 , V_37 ) ;
F_43 ( L_11 ,
V_33 -> V_56 -> V_86 -> V_112 , F_44 ( V_34 ) ,
V_101 -> V_113 / 1000000 ,
V_33 -> V_56 -> V_114 -> V_115 ) ;
return 0 ;
}
static void F_45 ( struct V_100 * V_101 )
{
struct V_36 * V_37 = F_46 ( V_101 ) ;
F_47 ( & V_37 -> V_92 ) ;
}
