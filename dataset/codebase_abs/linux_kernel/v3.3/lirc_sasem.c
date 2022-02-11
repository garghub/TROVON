static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_2 ( V_2 -> V_4 ) ;
F_3 ( V_2 -> V_5 -> V_6 ) ;
F_4 ( V_2 -> V_5 -> V_6 ) ;
F_4 ( V_2 -> V_5 ) ;
F_4 ( V_2 ) ;
if ( V_7 )
F_5 ( V_8 L_1 , V_9 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
int V_10 ;
int V_11 = V_2 -> V_5 -> V_11 ;
V_10 = F_7 ( V_11 ) ;
if ( V_10 )
F_8 ( L_2 ,
V_9 , V_10 ) ;
else
F_5 ( V_8 L_3 ,
V_11 ) ;
}
static int F_9 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
struct V_14 * V_15 ;
struct V_1 * V_2 = NULL ;
int V_16 ;
int V_10 = 0 ;
F_10 ( & V_17 ) ;
V_16 = F_11 ( V_12 ) ;
V_15 = F_12 ( & V_18 , V_16 ) ;
if ( ! V_15 ) {
F_8 ( L_4 ,
V_9 , V_16 ) ;
V_10 = - V_19 ;
goto exit;
}
V_2 = F_13 ( V_15 ) ;
if ( ! V_2 ) {
F_8 ( L_5 ,
V_9 , V_16 ) ;
V_10 = - V_19 ;
goto exit;
}
F_10 ( & V_2 -> V_20 ) ;
if ( V_2 -> V_21 ) {
F_8 ( L_6 , V_9 ) ;
V_10 = - V_22 ;
} else {
V_2 -> V_21 = 1 ;
V_13 -> V_23 = V_2 ;
F_5 ( V_8 L_7 ) ;
}
F_14 ( & V_2 -> V_20 ) ;
exit:
F_14 ( & V_17 ) ;
return V_10 ;
}
static long F_15 ( struct V_13 * V_13 , unsigned V_24 , unsigned long V_25 )
{
struct V_1 * V_2 = NULL ;
V_2 = (struct V_1 * ) V_13 -> V_23 ;
if ( ! V_2 ) {
F_8 ( L_8 , V_9 ) ;
return - V_19 ;
}
F_10 ( & V_2 -> V_20 ) ;
switch ( V_24 ) {
case V_26 :
if ( V_25 > 1000 )
V_25 = 1000 ;
V_2 -> V_27 = ( unsigned int ) V_25 ;
break;
default:
F_5 ( V_8 L_9 ) ;
F_14 ( & V_2 -> V_20 ) ;
return - V_28 ;
}
F_14 ( & V_2 -> V_20 ) ;
return 0 ;
}
static int F_16 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
struct V_1 * V_2 = NULL ;
int V_10 = 0 ;
V_2 = (struct V_1 * ) V_13 -> V_23 ;
if ( ! V_2 ) {
F_8 ( L_8 , V_9 ) ;
return - V_19 ;
}
F_10 ( & V_2 -> V_20 ) ;
if ( ! V_2 -> V_21 ) {
F_8 ( L_10 , V_9 ) ;
V_10 = - V_29 ;
} else {
V_2 -> V_21 = 0 ;
F_5 ( V_8 L_11 ) ;
if ( ! V_2 -> V_30 && ! V_2 -> V_31 ) {
F_14 ( & V_2 -> V_20 ) ;
F_1 ( V_2 ) ;
return V_10 ;
}
}
F_14 ( & V_2 -> V_20 ) ;
return V_10 ;
}
static int F_17 ( struct V_1 * V_2 )
{
unsigned int V_32 ;
int V_33 = 0 ;
int V_10 = 0 ;
V_32 = F_18 ( V_2 -> V_34 ,
V_2 -> V_35 -> V_36 ) ;
V_33 = V_2 -> V_35 -> V_37 ;
F_19 ( V_2 -> V_3 , V_2 -> V_34 , V_32 ,
V_2 -> V_38 , sizeof( V_2 -> V_38 ) ,
V_39 , V_2 , V_33 ) ;
V_2 -> V_3 -> V_40 = 0 ;
F_20 ( & V_2 -> V_41 . V_42 ) ;
F_21 ( & ( V_2 -> V_41 . V_43 ) , 1 ) ;
V_10 = F_22 ( V_2 -> V_3 , V_44 ) ;
if ( V_10 ) {
F_21 ( & ( V_2 -> V_41 . V_43 ) , 0 ) ;
F_8 ( L_12 , V_9 , V_10 ) ;
} else {
F_14 ( & V_2 -> V_20 ) ;
F_23 ( & V_2 -> V_41 . V_42 ) ;
F_10 ( & V_2 -> V_20 ) ;
V_10 = V_2 -> V_41 . V_45 ;
if ( V_10 )
F_8 ( L_13 , V_9 , V_10 ) ;
}
return V_10 ;
}
static T_1 F_24 ( struct V_13 * V_13 , const char * V_46 ,
T_2 V_47 , T_3 * V_48 )
{
int V_49 ;
int V_10 = 0 ;
struct V_1 * V_2 ;
int * V_50 = NULL ;
V_2 = (struct V_1 * ) V_13 -> V_23 ;
if ( ! V_2 ) {
F_8 ( L_8 , V_9 ) ;
return - V_19 ;
}
F_10 ( & V_2 -> V_20 ) ;
if ( ! V_2 -> V_30 ) {
F_8 ( L_14 , V_9 ) ;
V_10 = - V_19 ;
goto exit;
}
if ( V_47 <= 0 || V_47 > V_51 ) {
F_8 ( L_15 , V_9 ) ;
V_10 = - V_52 ;
goto exit;
}
V_50 = F_25 ( V_46 , V_47 ) ;
if ( F_26 ( V_50 ) ) {
V_10 = F_27 ( V_50 ) ;
goto exit;
}
memcpy ( V_2 -> V_41 . V_50 , V_50 , V_47 ) ;
for ( V_49 = V_47 ; V_49 < V_51 ; ++ V_49 )
V_2 -> V_41 . V_50 [ V_49 ] = ' ' ;
for ( V_49 = 0 ; V_49 < 9 ; V_49 ++ ) {
switch ( V_49 ) {
case 0 :
memcpy ( V_2 -> V_38 , L_16 , 8 ) ;
V_2 -> V_38 [ 1 ] = ( V_2 -> V_27 ) ?
( 0x2B - ( V_2 -> V_27 - 1 ) / 250 )
: 0x2B ;
break;
case 1 :
memcpy ( V_2 -> V_38 , L_17 , 8 ) ;
break;
case 2 :
memcpy ( V_2 -> V_38 , L_18 , 8 ) ;
break;
case 3 :
memcpy ( V_2 -> V_38 , V_2 -> V_41 . V_50 , 8 ) ;
break;
case 4 :
memcpy ( V_2 -> V_38 ,
V_2 -> V_41 . V_50 + 8 , 8 ) ;
break;
case 5 :
memcpy ( V_2 -> V_38 , L_17 , 8 ) ;
break;
case 6 :
memcpy ( V_2 -> V_38 , L_19 , 8 ) ;
break;
case 7 :
memcpy ( V_2 -> V_38 ,
V_2 -> V_41 . V_50 + 16 , 8 ) ;
break;
case 8 :
memcpy ( V_2 -> V_38 ,
V_2 -> V_41 . V_50 + 24 , 8 ) ;
break;
}
V_10 = F_17 ( V_2 ) ;
if ( V_10 ) {
F_8 ( L_20 ,
V_9 , V_49 ) ;
goto exit;
}
}
exit:
F_14 ( & V_2 -> V_20 ) ;
F_4 ( V_50 ) ;
return ( ! V_10 ) ? V_47 : V_10 ;
}
static void V_39 ( struct V_53 * V_53 )
{
struct V_1 * V_2 ;
if ( ! V_53 )
return;
V_2 = (struct V_1 * ) V_53 -> V_2 ;
if ( ! V_2 )
return;
V_2 -> V_41 . V_45 = V_53 -> V_45 ;
F_21 ( & V_2 -> V_41 . V_43 , 0 ) ;
F_28 ( & V_2 -> V_41 . V_42 ) ;
return;
}
static int F_29 ( void * V_54 )
{
int V_10 = 0 ;
struct V_1 * V_2 ;
F_10 ( & V_17 ) ;
V_2 = (struct V_1 * ) V_54 ;
F_10 ( & V_2 -> V_20 ) ;
if ( V_2 -> V_31 ) {
F_8 ( L_21 , V_9 ) ;
V_10 = - V_22 ;
goto exit;
}
F_19 ( V_2 -> V_4 , V_2 -> V_34 ,
F_30 ( V_2 -> V_34 ,
V_2 -> V_55 -> V_36 ) ,
V_2 -> V_56 , sizeof( V_2 -> V_56 ) ,
V_57 , V_2 , V_2 -> V_55 -> V_37 ) ;
V_10 = F_22 ( V_2 -> V_4 , V_44 ) ;
if ( V_10 )
F_8 ( L_22 ,
V_9 , V_10 ) ;
else {
V_2 -> V_31 = 1 ;
F_5 ( V_8 L_23 ) ;
}
exit:
F_14 ( & V_2 -> V_20 ) ;
F_14 ( & V_17 ) ;
return V_10 ;
}
static void F_31 ( void * V_54 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_54 ;
if ( ! V_2 ) {
F_8 ( L_8 , V_9 ) ;
return;
}
F_10 ( & V_2 -> V_20 ) ;
F_32 ( V_2 -> V_4 ) ;
V_2 -> V_31 = 0 ;
F_5 ( V_8 L_24 ) ;
if ( ! V_2 -> V_30 ) {
F_6 ( V_2 ) ;
if ( ! V_2 -> V_21 ) {
F_14 ( & V_2 -> V_20 ) ;
F_1 ( V_2 ) ;
return;
}
}
F_14 ( & V_2 -> V_20 ) ;
return;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_53 * V_53 )
{
int V_58 = V_53 -> V_40 ;
unsigned char * V_46 = V_53 -> V_59 ;
long V_60 ;
struct V_61 V_62 ;
int V_49 ;
if ( V_58 != 8 ) {
F_5 ( V_63 L_25 ,
V_9 , V_58 ) ;
return;
}
if ( V_7 ) {
F_5 ( V_8 L_26 ) ;
for ( V_49 = 0 ; V_49 < 8 ; ++ V_49 )
F_5 ( V_64 L_27 , V_46 [ V_49 ] ) ;
F_5 ( V_64 L_28 ) ;
}
F_34 ( & V_62 ) ;
V_60 = ( V_62 . V_65 - V_2 -> V_66 . V_65 ) * 1000 +
( V_62 . V_67 - V_2 -> V_66 . V_67 ) / 1000 ;
if ( memcmp ( V_46 , L_29 , 8 ) == 0 ) {
if ( ( V_60 < 250 ) && ( V_2 -> V_68 != 0 ) ) {
memcpy ( V_46 , & V_2 -> V_69 , 8 ) ;
V_2 -> V_66 . V_65 = V_62 . V_65 ;
V_2 -> V_66 . V_67 = V_62 . V_67 ;
}
} else {
memcpy ( & V_2 -> V_69 , V_46 , 8 ) ;
V_2 -> V_68 = 1 ;
V_2 -> V_66 . V_65 = V_62 . V_65 ;
V_2 -> V_66 . V_67 = V_62 . V_67 ;
}
F_35 ( V_2 -> V_5 -> V_6 , V_46 ) ;
F_36 ( & V_2 -> V_5 -> V_6 -> V_70 ) ;
}
static void V_57 ( struct V_53 * V_53 )
{
struct V_1 * V_2 ;
if ( ! V_53 )
return;
V_2 = (struct V_1 * ) V_53 -> V_2 ;
if ( ! V_2 )
return;
switch ( V_53 -> V_45 ) {
case - V_71 :
return;
case 0 :
if ( V_2 -> V_31 )
F_33 ( V_2 , V_53 ) ;
break;
default:
F_5 ( V_63 L_30 ,
V_9 , V_53 -> V_45 ) ;
break;
}
F_22 ( V_2 -> V_4 , V_72 ) ;
return;
}
static int F_37 ( struct V_14 * V_15 ,
const struct V_73 * V_74 )
{
struct V_75 * V_34 = NULL ;
struct V_76 * V_77 = NULL ;
struct V_78 * V_55 = NULL ;
struct V_78 * V_35 = NULL ;
struct V_53 * V_4 = NULL ;
struct V_53 * V_3 = NULL ;
struct V_79 * V_5 = NULL ;
struct V_80 * V_6 = NULL ;
int V_81 = 0 ;
int V_82 ;
int V_10 = 0 ;
int V_83 ;
int V_84 ;
int V_85 ;
struct V_1 * V_2 = NULL ;
int V_49 ;
F_5 ( V_8 L_31 , V_9 ) ;
V_34 = F_38 ( F_39 ( V_15 ) ) ;
V_77 = V_15 -> V_86 ;
V_82 = V_77 -> V_87 . V_88 ;
V_84 = 0 ;
V_83 = 0 ;
for ( V_49 = 0 ; V_49 < V_82 && ! ( V_84 && V_83 ) ; ++ V_49 ) {
struct V_78 * V_89 ;
int V_90 ;
int V_91 ;
V_89 = & V_77 -> V_92 [ V_49 ] . V_87 ;
V_90 = V_89 -> V_36 & V_93 ;
V_91 = V_89 -> V_94 & V_95 ;
if ( ! V_84 &&
V_90 == V_96 &&
V_91 == V_97 ) {
V_55 = V_89 ;
V_84 = 1 ;
if ( V_7 )
F_5 ( V_8 L_32 ,
V_9 ) ;
} else if ( ! V_83 &&
V_90 == V_98 &&
V_91 == V_97 ) {
V_35 = V_89 ;
V_83 = 1 ;
if ( V_7 )
F_5 ( V_8 L_33 ,
V_9 ) ;
}
}
if ( ! V_84 ) {
F_8 ( L_34 , V_9 ) ;
V_10 = - V_19 ;
goto exit;
}
if ( ! V_83 )
F_5 ( V_8 L_35 ,
V_9 ) ;
V_85 = 0 ;
V_2 = F_40 ( sizeof( struct V_1 ) , V_44 ) ;
if ( ! V_2 ) {
F_8 ( L_36 , V_9 ) ;
V_85 = 1 ;
goto V_99;
}
V_5 = F_40 ( sizeof( struct V_79 ) , V_44 ) ;
if ( ! V_5 ) {
F_8 ( L_37 , V_9 ) ;
V_85 = 2 ;
goto V_99;
}
V_6 = F_41 ( sizeof( struct V_80 ) , V_44 ) ;
if ( ! V_6 ) {
F_8 ( L_38 , V_9 ) ;
V_85 = 3 ;
goto V_99;
}
if ( F_42 ( V_6 , V_100 , V_101 ) ) {
F_8 ( L_39 , V_9 ) ;
V_85 = 4 ;
goto V_99;
}
V_4 = F_43 ( 0 , V_44 ) ;
if ( ! V_4 ) {
F_8 ( L_40 , V_9 ) ;
V_85 = 5 ;
goto V_99;
}
if ( V_83 ) {
V_3 = F_43 ( 0 , V_44 ) ;
if ( ! V_3 ) {
F_8 ( L_41 ,
V_9 ) ;
V_85 = 6 ;
goto V_99;
}
}
F_44 ( & V_2 -> V_20 ) ;
strcpy ( V_5 -> V_102 , V_103 ) ;
V_5 -> V_11 = - 1 ;
V_5 -> V_104 = 64 ;
V_5 -> V_105 = 0 ;
V_5 -> V_106 = V_107 ;
V_5 -> V_54 = V_2 ;
V_5 -> V_6 = V_6 ;
V_5 -> V_108 = F_29 ;
V_5 -> V_109 = F_31 ;
V_5 -> V_34 = & V_15 -> V_34 ;
V_5 -> V_110 = V_111 ;
F_10 ( & V_2 -> V_20 ) ;
V_81 = F_45 ( V_5 ) ;
if ( V_81 < 0 ) {
F_8 ( L_42 , V_9 ) ;
V_85 = 7 ;
V_10 = V_81 ;
goto V_112;
} else
F_5 ( V_8 L_43 ,
V_9 , V_81 ) ;
V_5 -> V_11 = V_81 ;
V_2 -> V_34 = V_34 ;
V_2 -> V_30 = 1 ;
V_2 -> V_55 = V_55 ;
V_2 -> V_4 = V_4 ;
if ( V_83 ) {
V_2 -> V_35 = V_35 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_27 = 1000 ;
}
V_2 -> V_5 = V_5 ;
F_46 ( V_15 , V_2 ) ;
if ( V_83 ) {
if ( V_7 )
F_5 ( V_8 L_44 ) ;
if ( F_47 ( V_15 , & V_113 ) )
F_5 ( V_8 L_45
L_46 , V_9 ) ;
}
F_5 ( V_8 L_47 ,
V_9 , V_34 -> V_114 -> V_115 , V_34 -> V_116 ) ;
V_112:
F_14 ( & V_2 -> V_20 ) ;
V_99:
switch ( V_85 ) {
case 7 :
if ( V_83 )
F_2 ( V_3 ) ;
case 6 :
F_2 ( V_4 ) ;
case 5 :
F_3 ( V_6 ) ;
case 4 :
F_4 ( V_6 ) ;
case 3 :
F_4 ( V_5 ) ;
case 2 :
F_4 ( V_2 ) ;
V_2 = NULL ;
case 1 :
if ( V_10 == 0 )
V_10 = - V_117 ;
}
exit:
return V_10 ;
}
static void F_48 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
F_10 ( & V_17 ) ;
V_2 = F_13 ( V_15 ) ;
F_10 ( & V_2 -> V_20 ) ;
F_5 ( V_8 L_48 , V_9 ) ;
F_46 ( V_15 , NULL ) ;
V_2 -> V_30 = 0 ;
F_32 ( V_2 -> V_4 ) ;
if ( F_49 ( & V_2 -> V_41 . V_43 ) ) {
F_32 ( V_2 -> V_3 ) ;
F_23 ( & V_2 -> V_41 . V_42 ) ;
}
if ( ! V_2 -> V_31 )
F_6 ( V_2 ) ;
F_50 ( V_15 , & V_113 ) ;
F_14 ( & V_2 -> V_20 ) ;
if ( ! V_2 -> V_31 && ! V_2 -> V_21 )
F_1 ( V_2 ) ;
F_14 ( & V_17 ) ;
}
