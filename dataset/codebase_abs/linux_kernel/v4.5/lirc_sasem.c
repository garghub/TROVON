static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_2 ( V_2 -> V_4 ) ;
F_3 ( V_2 -> V_5 -> V_6 ) ;
F_4 ( V_2 -> V_5 -> V_6 ) ;
F_4 ( V_2 -> V_5 ) ;
F_4 ( V_2 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
int V_7 ;
int V_8 = V_2 -> V_5 -> V_8 ;
V_7 = F_6 ( V_8 ) ;
if ( V_7 )
F_7 ( & V_2 -> V_9 -> V_9 ,
L_1 ,
V_10 , V_7 ) ;
else
F_8 ( & V_2 -> V_9 -> V_9 ,
L_2 , V_8 ) ;
}
static int F_9 ( struct V_11 * V_11 , struct V_12 * V_12 )
{
struct V_13 * V_14 ;
struct V_1 * V_2 = NULL ;
int V_15 ;
int V_7 = 0 ;
F_10 ( & V_16 ) ;
V_15 = F_11 ( V_11 ) ;
V_14 = F_12 ( & V_17 , V_15 ) ;
if ( ! V_14 ) {
F_13 ( L_3 ,
V_10 , V_15 ) ;
V_7 = - V_18 ;
goto exit;
}
V_2 = F_14 ( V_14 ) ;
if ( ! V_2 ) {
F_7 ( & V_14 -> V_9 , L_4 ,
V_15 ) ;
V_7 = - V_18 ;
goto exit;
}
F_10 ( & V_2 -> V_19 ) ;
if ( V_2 -> V_20 ) {
F_7 ( & V_14 -> V_9 ,
L_5 , V_10 ) ;
V_7 = - V_21 ;
} else {
V_2 -> V_20 = 1 ;
V_12 -> V_22 = V_2 ;
F_8 ( & V_14 -> V_9 , L_6 ) ;
}
F_15 ( & V_2 -> V_19 ) ;
exit:
F_15 ( & V_16 ) ;
return V_7 ;
}
static long F_16 ( struct V_12 * V_12 , unsigned V_23 , unsigned long V_24 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_12 -> V_22 ;
if ( ! V_2 ) {
F_13 ( L_7 , V_10 ) ;
return - V_18 ;
}
F_10 ( & V_2 -> V_19 ) ;
switch ( V_23 ) {
case V_25 :
if ( V_24 > 1000 )
V_24 = 1000 ;
V_2 -> V_26 = ( unsigned int ) V_24 ;
break;
default:
F_17 ( L_8 ) ;
F_15 ( & V_2 -> V_19 ) ;
return - V_27 ;
}
F_15 ( & V_2 -> V_19 ) ;
return 0 ;
}
static int F_18 ( struct V_11 * V_11 , struct V_12 * V_12 )
{
struct V_1 * V_2 = NULL ;
int V_7 = 0 ;
V_2 = (struct V_1 * ) V_12 -> V_22 ;
if ( ! V_2 ) {
F_13 ( L_7 , V_10 ) ;
return - V_18 ;
}
F_10 ( & V_2 -> V_19 ) ;
if ( ! V_2 -> V_20 ) {
F_7 ( & V_2 -> V_9 -> V_9 , L_9 , V_10 ) ;
V_7 = - V_28 ;
} else {
V_2 -> V_20 = 0 ;
F_8 ( & V_2 -> V_9 -> V_9 , L_10 ) ;
if ( ! V_2 -> V_29 && ! V_2 -> V_30 ) {
F_15 ( & V_2 -> V_19 ) ;
F_1 ( V_2 ) ;
return V_7 ;
}
}
F_15 ( & V_2 -> V_19 ) ;
return V_7 ;
}
static int F_19 ( struct V_1 * V_2 )
{
unsigned int V_31 ;
int V_32 = 0 ;
int V_7 = 0 ;
V_31 = F_20 ( V_2 -> V_9 ,
V_2 -> V_33 -> V_34 ) ;
V_32 = V_2 -> V_33 -> V_35 ;
F_21 ( V_2 -> V_3 , V_2 -> V_9 , V_31 ,
V_2 -> V_36 , sizeof( V_2 -> V_36 ) ,
V_37 , V_2 , V_32 ) ;
V_2 -> V_3 -> V_38 = 0 ;
F_22 ( & V_2 -> V_39 . V_40 ) ;
F_23 ( & V_2 -> V_39 . V_41 , 1 ) ;
V_7 = F_24 ( V_2 -> V_3 , V_42 ) ;
if ( V_7 ) {
F_23 ( & V_2 -> V_39 . V_41 , 0 ) ;
F_7 ( & V_2 -> V_9 -> V_9 , L_11 ,
V_7 ) ;
} else {
F_15 ( & V_2 -> V_19 ) ;
F_25 ( & V_2 -> V_39 . V_40 ) ;
F_10 ( & V_2 -> V_19 ) ;
V_7 = V_2 -> V_39 . V_43 ;
if ( V_7 )
F_7 ( & V_2 -> V_9 -> V_9 ,
L_12 , V_7 ) ;
}
return V_7 ;
}
static T_1 F_26 ( struct V_12 * V_12 , const char T_2 * V_44 ,
T_3 V_45 , T_4 * V_46 )
{
int V_47 ;
int V_7 = 0 ;
struct V_1 * V_2 ;
int * V_48 = NULL ;
V_2 = (struct V_1 * ) V_12 -> V_22 ;
if ( ! V_2 ) {
F_13 ( L_7 , V_10 ) ;
return - V_18 ;
}
F_10 ( & V_2 -> V_19 ) ;
if ( ! V_2 -> V_29 ) {
F_13 ( L_13 , V_10 ) ;
V_7 = - V_18 ;
goto exit;
}
if ( V_45 <= 0 || V_45 > V_49 ) {
F_7 ( & V_2 -> V_9 -> V_9 , L_14 ,
V_10 ) ;
V_7 = - V_50 ;
goto exit;
}
V_48 = F_27 ( V_44 , V_45 ) ;
if ( F_28 ( V_48 ) ) {
V_7 = F_29 ( V_48 ) ;
V_48 = NULL ;
goto exit;
}
memcpy ( V_2 -> V_39 . V_48 , V_48 , V_45 ) ;
for ( V_47 = V_45 ; V_47 < V_49 ; ++ V_47 )
V_2 -> V_39 . V_48 [ V_47 ] = ' ' ;
for ( V_47 = 0 ; V_47 < 9 ; V_47 ++ ) {
switch ( V_47 ) {
case 0 :
memcpy ( V_2 -> V_36 , L_15 , 8 ) ;
V_2 -> V_36 [ 1 ] = ( V_2 -> V_26 ) ?
( 0x2B - ( V_2 -> V_26 - 1 ) / 250 )
: 0x2B ;
break;
case 1 :
memcpy ( V_2 -> V_36 , L_16 , 8 ) ;
break;
case 2 :
memcpy ( V_2 -> V_36 , L_17 , 8 ) ;
break;
case 3 :
memcpy ( V_2 -> V_36 , V_2 -> V_39 . V_48 , 8 ) ;
break;
case 4 :
memcpy ( V_2 -> V_36 ,
V_2 -> V_39 . V_48 + 8 , 8 ) ;
break;
case 5 :
memcpy ( V_2 -> V_36 , L_16 , 8 ) ;
break;
case 6 :
memcpy ( V_2 -> V_36 , L_18 , 8 ) ;
break;
case 7 :
memcpy ( V_2 -> V_36 ,
V_2 -> V_39 . V_48 + 16 , 8 ) ;
break;
case 8 :
memcpy ( V_2 -> V_36 ,
V_2 -> V_39 . V_48 + 24 , 8 ) ;
break;
}
V_7 = F_19 ( V_2 ) ;
if ( V_7 ) {
F_7 ( & V_2 -> V_9 -> V_9 ,
L_19 , V_47 ) ;
goto exit;
}
}
exit:
F_15 ( & V_2 -> V_19 ) ;
F_4 ( V_48 ) ;
return ( ! V_7 ) ? V_45 : V_7 ;
}
static void V_37 ( struct V_51 * V_51 )
{
struct V_1 * V_2 ;
if ( ! V_51 )
return;
V_2 = (struct V_1 * ) V_51 -> V_2 ;
if ( ! V_2 )
return;
V_2 -> V_39 . V_43 = V_51 -> V_43 ;
F_23 ( & V_2 -> V_39 . V_41 , 0 ) ;
F_30 ( & V_2 -> V_39 . V_40 ) ;
}
static int F_31 ( void * V_52 )
{
int V_7 = 0 ;
struct V_1 * V_2 ;
F_10 ( & V_16 ) ;
V_2 = V_52 ;
F_10 ( & V_2 -> V_19 ) ;
if ( V_2 -> V_30 ) {
F_7 ( & V_2 -> V_9 -> V_9 , L_20 ,
V_10 ) ;
V_7 = - V_21 ;
goto exit;
}
F_21 ( V_2 -> V_4 , V_2 -> V_9 ,
F_32 ( V_2 -> V_9 ,
V_2 -> V_53 -> V_34 ) ,
V_2 -> V_54 , sizeof( V_2 -> V_54 ) ,
V_55 , V_2 , V_2 -> V_53 -> V_35 ) ;
V_7 = F_24 ( V_2 -> V_4 , V_42 ) ;
if ( V_7 )
F_7 ( & V_2 -> V_9 -> V_9 ,
L_21 , V_7 ) ;
else {
V_2 -> V_30 = 1 ;
F_8 ( & V_2 -> V_9 -> V_9 , L_22 ) ;
}
exit:
F_15 ( & V_2 -> V_19 ) ;
F_15 ( & V_16 ) ;
return V_7 ;
}
static void F_33 ( void * V_52 )
{
struct V_1 * V_2 ;
V_2 = V_52 ;
if ( ! V_2 ) {
F_13 ( L_7 , V_10 ) ;
return;
}
F_10 ( & V_2 -> V_19 ) ;
F_34 ( V_2 -> V_4 ) ;
V_2 -> V_30 = 0 ;
F_17 ( L_23 ) ;
if ( ! V_2 -> V_29 ) {
F_5 ( V_2 ) ;
if ( ! V_2 -> V_20 ) {
F_15 ( & V_2 -> V_19 ) ;
F_1 ( V_2 ) ;
return;
}
}
F_15 ( & V_2 -> V_19 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_51 * V_51 )
{
int V_56 = V_51 -> V_38 ;
unsigned char * V_44 = V_51 -> V_57 ;
T_5 V_58 ;
T_6 V_59 ;
if ( V_56 != 8 ) {
F_36 ( & V_2 -> V_9 -> V_9 ,
L_24 ,
V_10 , V_56 ) ;
return;
}
if ( V_60 )
F_8 ( & V_2 -> V_9 -> V_9 , L_25 , V_56 , V_44 ) ;
V_59 = F_37 () ;
V_58 = F_38 ( F_39 ( V_59 , V_2 -> V_61 ) ) ;
if ( memcmp ( V_44 , L_26 , 8 ) == 0 ) {
if ( ( V_58 < 250 * V_62 ) && ( V_2 -> V_63 != 0 ) ) {
memcpy ( V_44 , & V_2 -> V_64 , 8 ) ;
V_2 -> V_61 = V_59 ;
}
} else {
memcpy ( & V_2 -> V_64 , V_44 , 8 ) ;
V_2 -> V_63 = 1 ;
V_2 -> V_61 = V_59 ;
}
F_40 ( V_2 -> V_5 -> V_6 , V_44 ) ;
F_41 ( & V_2 -> V_5 -> V_6 -> V_65 ) ;
}
static void V_55 ( struct V_51 * V_51 )
{
struct V_1 * V_2 ;
if ( ! V_51 )
return;
V_2 = (struct V_1 * ) V_51 -> V_2 ;
if ( ! V_2 )
return;
switch ( V_51 -> V_43 ) {
case - V_66 :
return;
case 0 :
if ( V_2 -> V_30 )
F_35 ( V_2 , V_51 ) ;
break;
default:
F_36 ( & V_51 -> V_9 -> V_9 , L_27 ,
V_10 , V_51 -> V_43 ) ;
break;
}
F_24 ( V_2 -> V_4 , V_67 ) ;
}
static int F_42 ( struct V_13 * V_14 ,
const struct V_68 * V_69 )
{
struct V_70 * V_9 = NULL ;
struct V_71 * V_72 = NULL ;
struct V_73 * V_53 = NULL ;
struct V_73 * V_33 = NULL ;
struct V_51 * V_4 = NULL ;
struct V_51 * V_3 = NULL ;
struct V_74 * V_5 = NULL ;
struct V_75 * V_6 = NULL ;
int V_76 = 0 ;
int V_77 ;
int V_7 = 0 ;
int V_78 ;
int V_79 ;
int V_80 ;
struct V_1 * V_2 = NULL ;
int V_47 ;
F_8 ( & V_14 -> V_9 , L_28 , V_10 ) ;
V_9 = F_43 ( F_44 ( V_14 ) ) ;
V_72 = V_14 -> V_81 ;
V_77 = V_72 -> V_82 . V_83 ;
V_79 = 0 ;
V_78 = 0 ;
for ( V_47 = 0 ; V_47 < V_77 && ! ( V_79 && V_78 ) ; ++ V_47 ) {
struct V_73 * V_84 ;
V_84 = & V_72 -> V_85 [ V_47 ] . V_82 ;
if ( ! V_79 &&
F_45 ( V_84 ) ) {
V_53 = V_84 ;
V_79 = 1 ;
if ( V_60 )
F_8 ( & V_14 -> V_9 ,
L_29 , V_10 ) ;
} else if ( ! V_78 &&
F_46 ( V_84 ) ) {
V_33 = V_84 ;
V_78 = 1 ;
if ( V_60 )
F_8 ( & V_14 -> V_9 ,
L_30 , V_10 ) ;
}
}
if ( ! V_79 ) {
F_7 ( & V_14 -> V_9 ,
L_31 , V_10 ) ;
V_7 = - V_18 ;
goto exit;
}
if ( ! V_78 )
F_8 ( & V_14 -> V_9 ,
L_32 ,
V_10 ) ;
V_80 = 0 ;
V_2 = F_47 ( sizeof( struct V_1 ) , V_42 ) ;
if ( ! V_2 ) {
V_80 = 1 ;
goto V_86;
}
V_5 = F_47 ( sizeof( struct V_74 ) , V_42 ) ;
if ( ! V_5 ) {
V_80 = 2 ;
goto V_86;
}
V_6 = F_48 ( sizeof( struct V_75 ) , V_42 ) ;
if ( ! V_6 ) {
V_80 = 3 ;
goto V_86;
}
if ( F_49 ( V_6 , V_87 , V_88 ) ) {
F_7 ( & V_14 -> V_9 ,
L_33 , V_10 ) ;
V_80 = 4 ;
goto V_86;
}
V_4 = F_50 ( 0 , V_42 ) ;
if ( ! V_4 ) {
F_7 ( & V_14 -> V_9 ,
L_34 , V_10 ) ;
V_80 = 5 ;
goto V_86;
}
if ( V_78 ) {
V_3 = F_50 ( 0 , V_42 ) ;
if ( ! V_3 ) {
F_7 ( & V_14 -> V_9 ,
L_35 ,
V_10 ) ;
V_80 = 6 ;
goto V_86;
}
}
F_51 ( & V_2 -> V_19 ) ;
strcpy ( V_5 -> V_89 , V_90 ) ;
V_5 -> V_8 = - 1 ;
V_5 -> V_91 = 64 ;
V_5 -> V_92 = 0 ;
V_5 -> V_93 = V_94 ;
V_5 -> V_52 = V_2 ;
V_5 -> V_6 = V_6 ;
V_5 -> V_95 = F_31 ;
V_5 -> V_96 = F_33 ;
V_5 -> V_9 = & V_14 -> V_9 ;
V_5 -> V_97 = V_98 ;
F_10 ( & V_2 -> V_19 ) ;
V_76 = F_52 ( V_5 ) ;
if ( V_76 < 0 ) {
F_7 ( & V_14 -> V_9 ,
L_36 , V_10 ) ;
V_80 = 7 ;
V_7 = V_76 ;
goto V_99;
} else
F_8 ( & V_14 -> V_9 ,
L_37 ,
V_10 , V_76 ) ;
V_5 -> V_8 = V_76 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_29 = 1 ;
V_2 -> V_53 = V_53 ;
V_2 -> V_4 = V_4 ;
if ( V_78 ) {
V_2 -> V_33 = V_33 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_26 = 1000 ;
}
V_2 -> V_5 = V_5 ;
F_53 ( V_14 , V_2 ) ;
if ( V_78 ) {
if ( V_60 )
F_8 ( & V_14 -> V_9 ,
L_38 ) ;
if ( F_54 ( V_14 , & V_100 ) )
F_8 ( & V_14 -> V_9 ,
L_39 ,
V_10 ) ;
}
F_8 ( & V_14 -> V_9 ,
L_40 ,
V_10 , V_9 -> V_101 -> V_102 , V_9 -> V_103 ) ;
V_99:
F_15 ( & V_2 -> V_19 ) ;
V_86:
switch ( V_80 ) {
case 7 :
if ( V_78 )
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
if ( V_7 == 0 )
V_7 = - V_104 ;
}
exit:
return V_7 ;
}
static void F_55 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
F_10 ( & V_16 ) ;
V_2 = F_14 ( V_14 ) ;
F_10 ( & V_2 -> V_19 ) ;
F_8 ( & V_14 -> V_9 , L_41 ,
V_10 ) ;
F_53 ( V_14 , NULL ) ;
V_2 -> V_29 = 0 ;
F_34 ( V_2 -> V_4 ) ;
if ( F_56 ( & V_2 -> V_39 . V_41 ) ) {
F_34 ( V_2 -> V_3 ) ;
F_25 ( & V_2 -> V_39 . V_40 ) ;
}
if ( ! V_2 -> V_30 )
F_5 ( V_2 ) ;
F_57 ( V_14 , & V_100 ) ;
F_15 ( & V_2 -> V_19 ) ;
if ( ! V_2 -> V_30 && ! V_2 -> V_20 )
F_1 ( V_2 ) ;
F_15 ( & V_16 ) ;
}
