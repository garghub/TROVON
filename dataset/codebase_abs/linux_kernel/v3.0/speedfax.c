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
V_51 -> V_52 = V_54 ;
break;
case V_54 :
if ( V_51 -> V_55 < 0 || V_51 -> V_55 > 3 ) {
V_12 = - V_49 ;
break;
}
V_12 = V_16 -> V_3 . V_56 ( & V_16 -> V_3 , V_57 , V_51 -> V_55 ) ;
break;
default:
F_26 ( L_5 , V_16 -> V_29 , V_51 -> V_52 ) ;
V_12 = - V_49 ;
break;
}
return V_12 ;
}
static int
F_28 ( struct V_58 * V_7 , T_3 V_41 , void * V_42 )
{
struct V_59 * V_60 = F_29 ( V_7 , struct V_59 , V_61 ) ;
struct V_62 * V_4 = F_29 ( V_60 , struct V_62 , V_60 ) ;
struct V_1 * V_16 = V_4 -> V_63 ;
struct V_64 * V_65 ;
int V_66 = 0 ;
F_15 ( L_6 , V_16 -> V_29 , V_41 , V_42 ) ;
switch ( V_41 ) {
case V_67 :
V_65 = V_42 ;
if ( V_65 -> V_68 == V_69 )
V_66 = V_16 -> V_3 . V_70 ( & V_16 -> V_3 , V_65 ) ;
else
V_66 = V_16 -> V_6 . V_70 ( & V_16 -> V_6 , V_65 ) ;
if ( V_66 )
break;
if ( ! F_30 ( V_71 ) )
F_26 ( L_7 , V_16 -> V_29 ) ;
break;
case V_72 :
F_15 ( L_8 , V_16 -> V_29 ,
V_4 -> V_60 . V_73 , F_31 ( 0 ) ) ;
F_32 ( V_71 ) ;
break;
case V_74 :
V_66 = F_27 ( V_16 , V_42 ) ;
break;
default:
F_15 ( L_9 , V_16 -> V_29 , V_41 ) ;
return - V_49 ;
}
return V_66 ;
}
static int T_5
F_33 ( struct V_1 * V_16 )
{
int V_12 , V_17 = 3 ;
T_4 V_75 ;
V_12 = F_34 ( V_16 -> V_76 , F_7 , V_77 , V_16 -> V_29 , V_16 ) ;
if ( V_12 ) {
F_26 ( L_10 , V_16 -> V_29 , V_16 -> V_76 ) ;
return V_12 ;
}
while ( V_17 -- ) {
F_35 ( & V_16 -> V_19 , V_75 ) ;
V_12 = V_16 -> V_3 . V_78 ( & V_16 -> V_3 ) ;
if ( V_12 ) {
F_36 ( & V_16 -> V_19 , V_75 ) ;
F_26 ( L_11 ,
V_16 -> V_29 , V_12 ) ;
break;
}
F_18 ( V_16 ) ;
F_19 ( V_16 , V_79 , 0x41 ) ;
F_36 ( & V_16 -> V_19 , V_75 ) ;
F_37 ( 10 ) ;
if ( V_5 & V_80 )
F_17 ( L_12 , V_16 -> V_29 ,
V_16 -> V_76 , V_16 -> V_24 ) ;
if ( ! V_16 -> V_24 ) {
F_26 ( L_13 ,
V_16 -> V_29 , V_16 -> V_76 , 3 - V_17 ) ;
} else
return 0 ;
}
F_38 ( V_16 -> V_76 , V_16 ) ;
return - V_81 ;
}
static int T_5
F_39 ( struct V_1 * V_16 )
{
T_4 V_75 ;
if ( ! F_40 ( V_16 -> V_20 , 256 , V_16 -> V_29 ) ) {
F_26 ( L_14 ,
V_16 -> V_29 , V_16 -> V_20 , V_16 -> V_20 + 255 ) ;
return - V_81 ;
}
F_21 ( 0xff , V_16 -> V_20 ) ;
F_21 ( 0 , V_16 -> V_20 ) ;
F_21 ( 0xdd , V_16 -> V_20 + V_82 ) ;
F_21 ( 0 , V_16 -> V_20 + V_33 ) ;
V_16 -> V_3 . type = V_83 ;
V_16 -> V_84 . V_85 = V_16 -> V_20 + V_86 ;
V_16 -> V_84 . V_87 = V_16 -> V_20 + V_88 ;
V_16 -> V_89 . V_85 = V_16 -> V_20 + V_86 ;
V_16 -> V_89 . V_87 = V_16 -> V_20 + V_90 ;
F_41 ( V_91 , V_92 , V_16 -> V_3 ) ;
F_41 ( V_91 , V_93 , V_16 -> V_6 ) ;
F_35 ( & V_16 -> V_19 , V_75 ) ;
F_23 ( V_16 ) ;
F_22 ( V_16 ) ;
F_36 ( & V_16 -> V_19 , V_75 ) ;
return 0 ;
}
static void
F_42 ( struct V_1 * V_2 ) {
T_4 V_75 ;
F_35 ( & V_2 -> V_19 , V_75 ) ;
F_22 ( V_2 ) ;
F_36 ( & V_2 -> V_19 , V_75 ) ;
V_2 -> V_3 . V_94 ( & V_2 -> V_3 ) ;
F_38 ( V_2 -> V_76 , V_2 ) ;
V_2 -> V_6 . V_94 ( & V_2 -> V_6 ) ;
F_43 ( & V_2 -> V_3 . V_4 . V_60 ) ;
F_44 ( V_2 -> V_20 , 256 ) ;
F_45 ( V_2 -> V_95 ) ;
F_46 ( V_2 -> V_95 , NULL ) ;
F_47 ( & V_13 , V_75 ) ;
F_48 ( & V_2 -> V_96 ) ;
F_49 ( & V_13 , V_75 ) ;
F_50 ( V_2 ) ;
V_97 -- ;
}
static int T_5
F_51 ( struct V_1 * V_2 )
{
const struct V_98 * V_98 ;
int V_99 , V_66 ;
T_4 V_75 ;
snprintf ( V_2 -> V_29 , V_100 - 1 , L_15 , V_97 + 1 ) ;
F_47 ( & V_13 , V_75 ) ;
F_52 ( & V_2 -> V_96 , & V_101 ) ;
F_49 ( & V_13 , V_75 ) ;
F_1 ( V_2 ) ;
F_53 ( & V_2 -> V_19 ) ;
V_2 -> V_3 . V_102 = & V_2 -> V_19 ;
V_2 -> V_6 . V_102 = & V_2 -> V_19 ;
V_2 -> V_6 . V_56 = ( void * ) & F_25 ;
V_2 -> V_3 . V_29 = V_2 -> V_29 ;
V_2 -> V_6 . V_29 = V_2 -> V_29 ;
V_2 -> V_6 . V_103 = V_71 ;
V_66 = F_54 ( & V_98 , L_16 , & V_2 -> V_95 -> V_60 ) ;
if ( V_66 < 0 ) {
F_26 ( L_17 ,
V_2 -> V_29 , V_66 ) ;
goto V_104;
}
if ( V_5 & V_80 )
F_17 ( L_18 ,
V_2 -> V_29 , V_98 -> V_105 ) ;
F_55 ( & V_2 -> V_3 , V_2 ) ;
V_2 -> V_3 . V_4 . V_60 . V_61 . V_56 = F_28 ;
V_2 -> V_3 . V_4 . V_60 . V_106 =
F_56 ( & V_2 -> V_6 , V_2 ) ;
for ( V_99 = 0 ; V_99 < 2 ; V_99 ++ ) {
F_57 ( V_99 + 1 , V_2 -> V_3 . V_4 . V_60 . V_107 ) ;
F_58 ( & V_2 -> V_6 . V_7 [ V_99 ] . V_8 . V_7 . V_96 ,
& V_2 -> V_3 . V_4 . V_60 . V_108 ) ;
}
V_66 = F_39 ( V_2 ) ;
if ( V_66 )
goto V_109;
V_66 = V_2 -> V_6 . V_78 ( & V_2 -> V_6 ) ;
if ( V_66 )
goto error;
V_66 = F_59 ( & V_2 -> V_3 . V_4 . V_60 ,
& V_2 -> V_95 -> V_60 , V_2 -> V_29 ) ;
if ( V_66 )
goto error;
V_66 = F_33 ( V_2 ) ;
if ( V_66 )
goto V_110;
V_66 = V_2 -> V_6 . V_98 ( & V_2 -> V_6 , V_98 -> V_111 , V_98 -> V_105 ) ;
if ( ! V_66 ) {
F_60 ( V_98 ) ;
V_97 ++ ;
F_17 ( L_19 , V_97 ) ;
return 0 ;
}
F_22 ( V_2 ) ;
F_38 ( V_2 -> V_76 , V_2 ) ;
V_110:
F_43 ( & V_2 -> V_3 . V_4 . V_60 ) ;
error:
F_44 ( V_2 -> V_20 , 256 ) ;
V_109:
V_2 -> V_3 . V_94 ( & V_2 -> V_3 ) ;
V_2 -> V_6 . V_94 ( & V_2 -> V_6 ) ;
F_60 ( V_98 ) ;
V_104:
F_45 ( V_2 -> V_95 ) ;
F_47 ( & V_13 , V_75 ) ;
F_48 ( & V_2 -> V_96 ) ;
F_49 ( & V_13 , V_75 ) ;
F_50 ( V_2 ) ;
return V_66 ;
}
static int T_5
F_61 ( struct V_112 * V_95 , const struct V_113 * V_114 )
{
int V_66 = - V_115 ;
struct V_1 * V_2 = F_62 ( sizeof( struct V_1 ) , V_116 ) ;
if ( ! V_2 ) {
F_26 ( L_20 ) ;
return V_66 ;
}
V_2 -> V_95 = V_95 ;
V_66 = F_63 ( V_95 ) ;
if ( V_66 ) {
F_50 ( V_2 ) ;
return V_66 ;
}
F_17 ( L_21 ,
( char * ) V_114 -> V_117 , F_64 ( V_95 ) ) ;
V_2 -> V_20 = F_65 ( V_95 , 0 ) ;
V_2 -> V_76 = V_95 -> V_76 ;
F_46 ( V_95 , V_2 ) ;
V_66 = F_51 ( V_2 ) ;
if ( V_66 )
F_46 ( V_95 , NULL ) ;
return V_66 ;
}
static void T_6
F_66 ( struct V_112 * V_95 )
{
struct V_1 * V_2 = F_67 ( V_95 ) ;
if ( V_2 )
F_42 ( V_2 ) ;
else
F_15 ( L_22 , V_48 ) ;
}
static int T_7
F_68 ( void )
{
int V_66 ;
F_17 ( L_23 ,
V_118 ) ;
V_66 = F_69 ( & V_119 ) ;
return V_66 ;
}
static void T_8
F_70 ( void )
{
F_71 ( & V_119 ) ;
}
