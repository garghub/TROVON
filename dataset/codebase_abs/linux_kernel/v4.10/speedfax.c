static void
F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 . V_5 = V_5 ;
V_2 -> V_6 . V_7 [ 0 ] . V_8 . V_5 = V_5 ;
V_2 -> V_6 . V_7 [ 1 ] . V_8 . V_5 = V_5 ;
}
static int
F_2 ( const char * V_9 , struct V_10 * V_11 )
{
int V_12 ;
struct V_1 * V_2 ;
V_12 = F_3 ( V_9 , V_11 ) ;
if ( ! V_12 ) {
F_4 ( & V_13 ) ;
F_5 (card, &Cards, list)
F_1 ( V_2 ) ;
F_6 ( & V_13 ) ;
}
return V_12 ;
}
static T_1
F_7 ( int V_14 , void * V_15 )
{
struct V_1 * V_16 = V_15 ;
T_2 V_9 ;
int V_17 = V_18 ;
F_8 ( & V_16 -> V_19 ) ;
V_9 = F_9 ( V_16 -> V_20 + V_21 ) ;
if ( V_9 & V_22 ) {
F_10 ( & V_16 -> V_19 ) ;
return V_23 ;
}
V_16 -> V_24 ++ ;
V_9 = F_11 ( V_16 , V_25 ) ;
V_26:
if ( V_9 & V_27 )
F_12 ( & V_16 -> V_6 ) ;
V_9 = F_13 ( V_16 , V_28 ) ;
if ( V_9 )
F_14 ( & V_16 -> V_3 , V_9 ) ;
V_9 = F_11 ( V_16 , V_25 ) ;
if ( ( V_9 & V_27 ) && V_17 -- )
goto V_26;
if ( V_17 < V_18 )
F_15 ( L_1 , V_16 -> V_29 ,
V_18 - V_17 , F_16 () ) ;
if ( V_18 && ! V_17 )
F_17 ( L_2 , V_16 -> V_29 ,
V_18 , F_16 () ) ;
F_10 ( & V_16 -> V_19 ) ;
return V_30 ;
}
static void
F_18 ( struct V_1 * V_16 )
{
F_19 ( V_16 , V_31 , 0 ) ;
F_20 ( V_16 , V_25 , V_32 ) ;
F_21 ( V_22 , V_16 -> V_20 + V_33 ) ;
}
static void
F_22 ( struct V_1 * V_16 )
{
F_19 ( V_16 , V_31 , 0xFF ) ;
F_20 ( V_16 , V_25 , 0 ) ;
F_21 ( 0 , V_16 -> V_20 + V_33 ) ;
}
static void
F_23 ( struct V_1 * V_16 )
{
F_15 ( L_3 , V_16 -> V_29 ) ;
F_21 ( V_34 , V_16 -> V_20 + V_35 ) ;
F_21 ( V_36 , V_16 -> V_20 + V_37 ) ;
F_24 ( 1 ) ;
F_21 ( V_38 , V_16 -> V_20 + V_35 ) ;
V_16 -> V_39 = V_40 ;
F_21 ( V_16 -> V_39 , V_16 -> V_20 + V_37 ) ;
F_24 ( 1 ) ;
}
static int
F_25 ( struct V_1 * V_16 , T_3 V_41 , T_4 V_42 )
{
int V_12 = 0 ;
switch ( V_41 ) {
case V_43 :
F_23 ( V_16 ) ;
break;
case V_44 :
if ( V_42 & 1 )
V_16 -> V_39 &= ~ V_45 ;
if ( V_42 & 2 )
V_16 -> V_39 &= ~ V_46 ;
F_21 ( V_16 -> V_39 , V_16 -> V_20 + V_37 ) ;
break;
case V_47 :
if ( V_42 & 1 )
V_16 -> V_39 |= V_45 ;
if ( V_42 & 2 )
V_16 -> V_39 |= V_46 ;
F_21 ( V_16 -> V_39 , V_16 -> V_20 + V_37 ) ;
break;
default:
F_26 ( L_4 ,
V_16 -> V_29 , V_48 , V_41 , V_42 ) ;
V_12 = - V_49 ;
break;
}
return V_12 ;
}
static int
F_27 ( struct V_1 * V_16 , struct V_50 * V_51 )
{
int V_12 = 0 ;
switch ( V_51 -> V_52 ) {
case V_53 :
V_51 -> V_52 = V_54 | V_55 ;
break;
case V_54 :
if ( V_51 -> V_56 < 0 || V_51 -> V_56 > 3 ) {
V_12 = - V_49 ;
break;
}
V_12 = V_16 -> V_3 . V_57 ( & V_16 -> V_3 , V_58 , V_51 -> V_56 ) ;
break;
case V_55 :
V_12 = V_16 -> V_3 . V_57 ( & V_16 -> V_3 , V_59 , V_51 -> V_60 ) ;
break;
default:
F_26 ( L_5 , V_16 -> V_29 , V_51 -> V_52 ) ;
V_12 = - V_49 ;
break;
}
return V_12 ;
}
static int
F_28 ( struct V_61 * V_7 , T_3 V_41 , void * V_42 )
{
struct V_62 * V_63 = F_29 ( V_7 , struct V_62 , V_64 ) ;
struct V_65 * V_4 = F_29 ( V_63 , struct V_65 , V_63 ) ;
struct V_1 * V_16 = V_4 -> V_66 ;
struct V_67 * V_68 ;
int V_69 = 0 ;
F_15 ( L_6 , V_16 -> V_29 , V_41 , V_42 ) ;
switch ( V_41 ) {
case V_70 :
V_68 = V_42 ;
if ( V_68 -> V_71 == V_72 )
V_69 = V_16 -> V_3 . V_73 ( & V_16 -> V_3 , V_68 ) ;
else
V_69 = V_16 -> V_6 . V_73 ( & V_16 -> V_6 , V_68 ) ;
if ( V_69 )
break;
if ( ! F_30 ( V_74 ) )
F_26 ( L_7 , V_16 -> V_29 ) ;
break;
case V_75 :
F_15 ( L_8 , V_16 -> V_29 ,
V_4 -> V_63 . V_76 , F_31 ( 0 ) ) ;
F_32 ( V_74 ) ;
break;
case V_77 :
V_69 = F_27 ( V_16 , V_42 ) ;
break;
default:
F_15 ( L_9 , V_16 -> V_29 , V_41 ) ;
return - V_49 ;
}
return V_69 ;
}
static int
F_33 ( struct V_1 * V_16 )
{
int V_12 , V_17 = 3 ;
T_4 V_78 ;
V_12 = F_34 ( V_16 -> V_79 , F_7 , V_80 , V_16 -> V_29 , V_16 ) ;
if ( V_12 ) {
F_26 ( L_10 , V_16 -> V_29 , V_16 -> V_79 ) ;
return V_12 ;
}
while ( V_17 -- ) {
F_35 ( & V_16 -> V_19 , V_78 ) ;
V_12 = V_16 -> V_3 . V_81 ( & V_16 -> V_3 ) ;
if ( V_12 ) {
F_36 ( & V_16 -> V_19 , V_78 ) ;
F_26 ( L_11 ,
V_16 -> V_29 , V_12 ) ;
break;
}
F_18 ( V_16 ) ;
F_19 ( V_16 , V_82 , 0x41 ) ;
F_36 ( & V_16 -> V_19 , V_78 ) ;
F_37 ( 10 ) ;
if ( V_5 & V_83 )
F_17 ( L_12 , V_16 -> V_29 ,
V_16 -> V_79 , V_16 -> V_24 ) ;
if ( ! V_16 -> V_24 ) {
F_26 ( L_13 ,
V_16 -> V_29 , V_16 -> V_79 , 3 - V_17 ) ;
} else
return 0 ;
}
F_38 ( V_16 -> V_79 , V_16 ) ;
return - V_84 ;
}
static int
F_39 ( struct V_1 * V_16 )
{
T_4 V_78 ;
if ( ! F_40 ( V_16 -> V_20 , 256 , V_16 -> V_29 ) ) {
F_26 ( L_14 ,
V_16 -> V_29 , V_16 -> V_20 , V_16 -> V_20 + 255 ) ;
return - V_84 ;
}
F_21 ( 0xff , V_16 -> V_20 ) ;
F_21 ( 0 , V_16 -> V_20 ) ;
F_21 ( 0xdd , V_16 -> V_20 + V_85 ) ;
F_21 ( 0 , V_16 -> V_20 + V_33 ) ;
V_16 -> V_3 . type = V_86 ;
V_16 -> V_87 . V_88 = V_16 -> V_20 + V_89 ;
V_16 -> V_87 . V_90 = V_16 -> V_20 + V_91 ;
V_16 -> V_92 . V_88 = V_16 -> V_20 + V_89 ;
V_16 -> V_92 . V_90 = V_16 -> V_20 + V_93 ;
F_41 ( V_94 , V_95 , V_16 -> V_3 ) ;
F_41 ( V_94 , V_96 , V_16 -> V_6 ) ;
F_35 ( & V_16 -> V_19 , V_78 ) ;
F_23 ( V_16 ) ;
F_22 ( V_16 ) ;
F_36 ( & V_16 -> V_19 , V_78 ) ;
return 0 ;
}
static void
F_42 ( struct V_1 * V_2 ) {
T_4 V_78 ;
F_35 ( & V_2 -> V_19 , V_78 ) ;
F_22 ( V_2 ) ;
F_36 ( & V_2 -> V_19 , V_78 ) ;
V_2 -> V_3 . V_97 ( & V_2 -> V_3 ) ;
F_38 ( V_2 -> V_79 , V_2 ) ;
V_2 -> V_6 . V_97 ( & V_2 -> V_6 ) ;
F_43 ( & V_2 -> V_3 . V_4 . V_63 ) ;
F_44 ( V_2 -> V_20 , 256 ) ;
F_45 ( V_2 -> V_98 ) ;
F_46 ( V_2 -> V_98 , NULL ) ;
F_47 ( & V_13 , V_78 ) ;
F_48 ( & V_2 -> V_99 ) ;
F_49 ( & V_13 , V_78 ) ;
F_50 ( V_2 ) ;
V_100 -- ;
}
static int
F_51 ( struct V_1 * V_2 )
{
const struct V_101 * V_101 ;
int V_102 , V_69 ;
T_4 V_78 ;
snprintf ( V_2 -> V_29 , V_103 - 1 , L_15 , V_100 + 1 ) ;
F_47 ( & V_13 , V_78 ) ;
F_52 ( & V_2 -> V_99 , & V_104 ) ;
F_49 ( & V_13 , V_78 ) ;
F_1 ( V_2 ) ;
F_53 ( & V_2 -> V_19 ) ;
V_2 -> V_3 . V_105 = & V_2 -> V_19 ;
V_2 -> V_6 . V_105 = & V_2 -> V_19 ;
V_2 -> V_6 . V_57 = ( void * ) & F_25 ;
V_2 -> V_3 . V_29 = V_2 -> V_29 ;
V_2 -> V_6 . V_29 = V_2 -> V_29 ;
V_2 -> V_6 . V_106 = V_74 ;
V_69 = F_54 ( & V_101 , L_16 , & V_2 -> V_98 -> V_63 ) ;
if ( V_69 < 0 ) {
F_26 ( L_17 ,
V_2 -> V_29 , V_69 ) ;
goto V_107;
}
if ( V_5 & V_83 )
F_17 ( L_18 ,
V_2 -> V_29 , V_101 -> V_108 ) ;
F_55 ( & V_2 -> V_3 , V_2 ) ;
V_2 -> V_3 . V_4 . V_63 . V_64 . V_57 = F_28 ;
V_2 -> V_3 . V_4 . V_63 . V_109 =
F_56 ( & V_2 -> V_6 , V_2 ) ;
for ( V_102 = 0 ; V_102 < 2 ; V_102 ++ ) {
F_57 ( V_102 + 1 , V_2 -> V_3 . V_4 . V_63 . V_110 ) ;
F_58 ( & V_2 -> V_6 . V_7 [ V_102 ] . V_8 . V_7 . V_99 ,
& V_2 -> V_3 . V_4 . V_63 . V_111 ) ;
}
V_69 = F_39 ( V_2 ) ;
if ( V_69 )
goto V_112;
V_69 = V_2 -> V_6 . V_81 ( & V_2 -> V_6 ) ;
if ( V_69 )
goto error;
V_69 = F_59 ( & V_2 -> V_3 . V_4 . V_63 ,
& V_2 -> V_98 -> V_63 , V_2 -> V_29 ) ;
if ( V_69 )
goto error;
V_69 = F_33 ( V_2 ) ;
if ( V_69 )
goto V_113;
V_69 = V_2 -> V_6 . V_101 ( & V_2 -> V_6 , V_101 -> V_114 , V_101 -> V_108 ) ;
if ( ! V_69 ) {
F_60 ( V_101 ) ;
V_100 ++ ;
F_17 ( L_19 , V_100 ) ;
return 0 ;
}
F_22 ( V_2 ) ;
F_38 ( V_2 -> V_79 , V_2 ) ;
V_113:
F_43 ( & V_2 -> V_3 . V_4 . V_63 ) ;
error:
F_44 ( V_2 -> V_20 , 256 ) ;
V_112:
V_2 -> V_3 . V_97 ( & V_2 -> V_3 ) ;
V_2 -> V_6 . V_97 ( & V_2 -> V_6 ) ;
F_60 ( V_101 ) ;
V_107:
F_45 ( V_2 -> V_98 ) ;
F_47 ( & V_13 , V_78 ) ;
F_48 ( & V_2 -> V_99 ) ;
F_49 ( & V_13 , V_78 ) ;
F_50 ( V_2 ) ;
return V_69 ;
}
static int
F_61 ( struct V_115 * V_98 , const struct V_116 * V_117 )
{
int V_69 = - V_118 ;
struct V_1 * V_2 = F_62 ( sizeof( struct V_1 ) , V_119 ) ;
if ( ! V_2 ) {
F_26 ( L_20 ) ;
return V_69 ;
}
V_2 -> V_98 = V_98 ;
V_69 = F_63 ( V_98 ) ;
if ( V_69 ) {
F_50 ( V_2 ) ;
return V_69 ;
}
F_17 ( L_21 ,
( char * ) V_117 -> V_120 , F_64 ( V_98 ) ) ;
V_2 -> V_20 = F_65 ( V_98 , 0 ) ;
V_2 -> V_79 = V_98 -> V_79 ;
F_46 ( V_98 , V_2 ) ;
V_69 = F_51 ( V_2 ) ;
if ( V_69 )
F_46 ( V_98 , NULL ) ;
return V_69 ;
}
static void
F_66 ( struct V_115 * V_98 )
{
struct V_1 * V_2 = F_67 ( V_98 ) ;
if ( V_2 )
F_42 ( V_2 ) ;
else
F_15 ( L_22 , V_48 ) ;
}
static int T_5
F_68 ( void )
{
int V_69 ;
F_17 ( L_23 ,
V_121 ) ;
V_69 = F_69 ( & V_122 ) ;
return V_69 ;
}
static void T_6
F_70 ( void )
{
F_71 ( & V_122 ) ;
}
