static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
struct V_8 * V_9 = & V_2 -> V_10 -> V_11 ;
int V_12 = V_2 -> V_10 -> V_13 . V_12 ;
int V_14 = V_2 -> V_10 -> V_13 . V_14 ;
if ( V_3 )
goto V_15;
if ( V_5 -> V_16 . V_17 != V_12 ) {
V_5 -> V_16 . V_17 = V_12 ;
V_3 = F_3 ( V_5 ) ;
}
V_15:
F_4 ( 2 , L_1
L_2 , V_9 -> V_18 , V_9 -> V_19 , V_3 , V_14 , V_12 ,
V_5 -> V_20 ) ;
F_5 ( V_2 , V_3 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = & V_2 -> V_10 -> V_22 ;
struct V_23 * V_24 = V_2 -> V_10 -> V_25 ;
V_24 -> V_26 = V_27 ;
V_24 -> V_28 = 0 ;
V_24 -> V_29 = 0 ;
V_24 -> V_13 = V_30 ;
V_22 -> V_24 = V_24 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
struct V_21 * V_22 = & V_2 -> V_10 -> V_22 ;
V_22 -> V_31 = F_8 ( V_22 -> V_31 , V_5 -> V_32 . V_33 . V_34 & V_5 -> V_35 ) ;
if ( ! V_22 -> V_31 )
goto V_36;
F_6 ( V_2 ) ;
F_9 ( V_2 ) ;
return;
V_36:
F_1 ( V_2 , V_5 -> V_20 ? 0 : - V_37 ) ;
}
static enum V_38 F_10 ( struct V_1 * V_2 , void * V_39 ,
struct V_40 * V_40 , enum V_38 V_41 )
{
if ( V_41 == V_42 && V_40 -> V_43 . V_44 . V_45 == 0 )
return V_46 ;
return V_41 ;
}
static void F_11 ( struct V_1 * V_2 , void * V_39 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
struct V_21 * V_22 = & V_2 -> V_10 -> V_22 ;
if ( V_3 == 0 )
V_5 -> V_20 |= V_22 -> V_31 ;
else if ( V_3 != - V_37 )
goto V_47;
V_22 -> V_31 >>= 1 ;
F_7 ( V_2 ) ;
return;
V_47:
F_1 ( V_2 , V_3 ) ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_48 )
{
struct V_21 * V_22 = & V_2 -> V_10 -> V_22 ;
struct V_23 * V_24 = V_2 -> V_10 -> V_25 ;
int V_49 = 8 - F_13 ( V_22 -> V_31 ) ;
struct V_50 * V_50 = & V_2 -> V_10 -> V_50 [ V_49 ] ;
V_50 -> V_51 . V_52 = V_48 ;
V_24 -> V_26 = V_53 ;
V_24 -> V_28 = ( V_54 ) ( V_55 ) V_50 ;
V_24 -> V_29 = sizeof( * V_50 ) ;
V_24 -> V_13 = V_30 ;
V_22 -> V_24 = V_24 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
struct V_21 * V_22 = & V_2 -> V_10 -> V_22 ;
T_1 V_48 ;
V_22 -> V_31 = F_8 ( V_22 -> V_31 , V_2 -> V_10 -> V_56 ) ;
if ( ! V_22 -> V_31 )
goto V_36;
if ( V_22 -> V_31 & V_5 -> V_35 )
V_48 = V_57 ;
else
V_48 = V_58 ;
if ( V_2 -> V_10 -> V_13 . V_12 )
V_48 |= V_59 ;
F_12 ( V_2 , V_48 ) ;
F_9 ( V_2 ) ;
return;
V_36:
F_1 ( V_2 , V_5 -> V_20 ? 0 : - V_37 ) ;
}
static void F_15 ( struct V_1 * V_2 , void * V_39 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
struct V_21 * V_22 = & V_2 -> V_10 -> V_22 ;
switch ( V_3 ) {
case 0 :
V_5 -> V_20 |= V_22 -> V_31 & V_5 -> V_35 ;
break;
case - V_37 :
break;
case - V_60 :
if ( V_2 -> V_10 -> V_13 . V_12 ) {
V_2 -> V_10 -> V_13 . V_12 = 0 ;
goto V_61;
}
V_2 -> V_10 -> V_13 . V_14 = 0 ;
goto V_61;
default:
goto V_47;
}
V_22 -> V_31 >>= 1 ;
F_14 ( V_2 ) ;
return;
V_61:
F_16 ( V_2 ) ;
return;
V_47:
F_1 ( V_2 , V_3 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = & V_2 -> V_10 -> V_22 ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_22 -> V_62 = V_63 ;
V_22 -> V_64 = V_65 ;
V_22 -> V_31 = 0x80 ;
V_22 -> V_66 = 1 ;
V_22 -> V_67 = F_15 ;
F_14 ( V_2 ) ;
}
static int F_18 ( struct V_50 * V_68 )
{
char * V_69 ;
for ( V_69 = ( char * ) V_68 + 1 ; V_69 < ( char * ) ( V_68 + 1 ) ; V_69 ++ ) {
if ( * V_69 != 0 )
return 0 ;
}
return 1 ;
}
static int F_19 ( struct V_50 * V_70 , struct V_50 * V_71 )
{
return memcmp ( ( char * ) V_70 + 1 , ( char * ) V_71 + 1 ,
sizeof( struct V_50 ) - 1 ) ;
}
static void F_20 ( struct V_1 * V_2 , struct V_50 * * V_68 ,
int * V_72 , int * V_73 , T_1 * V_74 )
{
struct V_50 * V_50 = & V_2 -> V_10 -> V_50 [ 0 ] ;
struct V_50 * V_75 = NULL ;
int V_31 ;
int V_49 ;
* V_72 = 0 ;
* V_73 = 0 ;
* V_74 = 0 ;
for ( V_49 = 0 , V_31 = 0x80 ; V_49 < 8 ; V_49 ++ , V_50 ++ , V_31 >>= 1 ) {
if ( ( V_2 -> V_10 -> V_76 & V_31 ) == 0 )
continue;
if ( V_50 -> V_51 . V_77 . V_78 == V_79 )
* V_73 = 1 ;
if ( F_18 ( V_50 ) ) {
* V_74 |= V_31 ;
continue;
}
if ( ! V_75 ) {
V_75 = V_50 ;
continue;
}
if ( F_19 ( V_50 , V_75 ) != 0 )
* V_72 = 1 ;
}
if ( ! V_75 )
V_75 = & V_80 [ 0 ] -> V_81 ;
* V_68 = V_75 ;
}
static T_1 F_21 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
struct V_50 * V_50 ;
int V_49 ;
int V_31 ;
T_1 V_82 = 0 ;
for ( V_49 = 0 ; V_49 < 8 ; V_49 ++ ) {
V_31 = 0x80 >> V_49 ;
if ( ( V_2 -> V_10 -> V_76 & V_31 ) == 0 )
continue;
V_50 = & V_2 -> V_10 -> V_50 [ V_49 ] ;
if ( V_5 -> V_35 & V_31 ) {
if ( V_50 -> V_51 . V_77 . V_83 != V_84 )
continue;
} else {
if ( V_50 -> V_51 . V_77 . V_83 != V_85 )
continue;
}
if ( V_2 -> V_10 -> V_13 . V_12 ) {
if ( V_50 -> V_51 . V_77 . V_86 != V_87 )
continue;
} else {
if ( V_50 -> V_51 . V_77 . V_86 != V_88 )
continue;
}
V_82 |= V_31 ;
}
return V_82 ;
}
static void F_22 ( struct V_1 * V_2 , struct V_50 * V_50 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < 8 ; V_49 ++ )
memcpy ( & V_2 -> V_10 -> V_50 [ V_49 ] , V_50 , sizeof( struct V_50 ) ) ;
}
static void F_23 ( struct V_1 * V_2 , int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_10 -> V_11 ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
struct V_50 * V_50 ;
int V_72 = 0 ;
int V_73 = 0 ;
T_1 V_74 = 0 ;
T_1 V_82 ;
if ( V_3 )
goto V_15;
F_20 ( V_2 , & V_50 , & V_72 , & V_73 , & V_74 ) ;
if ( V_73 )
V_3 = - V_89 ;
else if ( V_72 )
V_3 = - V_60 ;
else {
V_82 = F_21 ( V_2 ) ;
V_5 -> V_20 = V_82 & V_5 -> V_35 ;
V_2 -> V_10 -> V_56 &= ~ V_82 ;
V_2 -> V_10 -> V_90 |= V_74 ;
F_22 ( V_2 , V_50 ) ;
}
V_15:
F_4 ( 2 , L_3
L_4 , V_9 -> V_18 ,
V_9 -> V_19 , V_3 , V_2 -> V_10 -> V_76 , V_5 -> V_20 ,
V_2 -> V_10 -> V_56 , V_72 , V_73 , V_74 ) ;
switch ( V_3 ) {
case 0 :
if ( V_2 -> V_10 -> V_56 == 0 ) {
F_1 ( V_2 , V_5 -> V_20 == 0 ? - V_37 : 0 ) ;
return;
}
F_17 ( V_2 ) ;
break;
case - V_60 :
V_2 -> V_10 -> V_13 . V_14 = 0 ;
V_2 -> V_10 -> V_13 . V_12 = 0 ;
F_16 ( V_2 ) ;
break;
default:
F_1 ( V_2 , V_3 ) ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = & V_2 -> V_10 -> V_22 ;
struct V_23 * V_24 = V_2 -> V_10 -> V_25 ;
int V_49 = 8 - F_13 ( V_22 -> V_31 ) ;
V_24 -> V_26 = V_91 ;
V_24 -> V_28 = ( V_54 ) ( V_55 ) & V_2 -> V_10 -> V_50 [ V_49 ] ;
V_24 -> V_29 = sizeof( struct V_50 ) ;
V_24 -> V_13 = V_30 ;
V_22 -> V_24 = V_24 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
struct V_21 * V_22 = & V_2 -> V_10 -> V_22 ;
V_22 -> V_31 = F_8 ( V_22 -> V_31 , V_5 -> V_32 . V_33 . V_34 ) ;
if ( ! V_22 -> V_31 )
goto V_36;
F_24 ( V_2 ) ;
F_9 ( V_2 ) ;
return;
V_36:
F_23 ( V_2 , V_2 -> V_10 -> V_76 ? 0 : - V_37 ) ;
}
static void F_26 ( struct V_1 * V_2 , void * V_39 , int V_3 )
{
struct V_21 * V_22 = & V_2 -> V_10 -> V_22 ;
if ( V_3 == 0 )
V_2 -> V_10 -> V_76 |= V_22 -> V_31 ;
else if ( V_3 != - V_37 )
goto V_47;
V_22 -> V_31 >>= 1 ;
F_25 ( V_2 ) ;
return;
V_47:
F_23 ( V_2 , V_3 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
struct V_21 * V_22 = & V_2 -> V_10 -> V_22 ;
struct V_8 * V_92 = & V_2 -> V_10 -> V_11 ;
V_5 -> V_20 = 0 ;
V_5 -> V_31 = V_5 -> V_32 . V_33 . V_34 ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_22 -> V_62 = V_63 ;
V_22 -> V_64 = V_65 ;
V_22 -> V_31 = 0x80 ;
V_22 -> V_66 = 1 ;
if ( V_2 -> V_10 -> V_13 . V_14 ) {
F_27 ( 4 , L_5 ) ;
F_28 ( 4 , V_92 , sizeof( * V_92 ) ) ;
V_22 -> V_67 = F_26 ;
F_25 ( V_2 ) ;
} else {
F_27 ( 4 , L_6 ) ;
F_28 ( 4 , V_92 , sizeof( * V_92 ) ) ;
V_22 -> V_93 = F_10 ;
V_22 -> V_67 = F_11 ;
F_7 ( V_2 ) ;
}
}
void F_29 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
F_27 ( 4 , L_7 ) ;
F_28 ( 4 , & V_2 -> V_10 -> V_11 , sizeof( V_2 -> V_10 -> V_11 ) ) ;
memset ( V_2 -> V_10 -> V_50 , 0 , sizeof( V_2 -> V_10 -> V_50 ) ) ;
V_2 -> V_10 -> V_76 = 0 ;
V_2 -> V_10 -> V_56 = V_5 -> V_32 . V_33 . V_34 ;
V_2 -> V_10 -> V_13 . V_14 = V_2 -> V_10 -> V_94 . V_14 ;
V_2 -> V_10 -> V_13 . V_12 = V_2 -> V_10 -> V_94 . V_12 ;
V_2 -> V_10 -> V_13 . V_95 = 0 ;
F_16 ( V_2 ) ;
}
static void F_30 ( struct V_1 * V_2 , void * V_39 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
struct V_8 * V_9 = & V_2 -> V_10 -> V_11 ;
if ( V_3 )
goto V_15;
V_2 -> V_10 -> V_13 . V_12 = 0 ;
if ( V_5 -> V_16 . V_17 ) {
V_5 -> V_16 . V_17 = 0 ;
V_3 = F_3 ( V_5 ) ;
}
V_15:
F_4 ( 0 , L_8 , V_9 -> V_18 , V_9 -> V_19 ,
V_3 ) ;
F_31 ( V_2 , V_3 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
struct V_21 * V_22 = & V_2 -> V_10 -> V_22 ;
T_1 V_48 ;
F_27 ( 4 , L_9 ) ;
F_28 ( 4 , & V_2 -> V_10 -> V_11 , sizeof( V_2 -> V_10 -> V_11 ) ) ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_22 -> V_62 = V_63 ;
V_22 -> V_64 = V_65 ;
V_22 -> V_31 = V_5 -> V_32 . V_33 . V_34 & V_5 -> V_35 ;
V_22 -> V_66 = 1 ;
V_22 -> V_67 = F_30 ;
V_48 = V_96 ;
if ( V_2 -> V_10 -> V_13 . V_12 )
V_48 |= V_59 ;
F_12 ( V_2 , V_48 ) ;
F_9 ( V_2 ) ;
}
static void F_33 ( struct V_1 * V_2 , void * V_97 , void * V_98 )
{
struct V_21 * V_22 = & V_2 -> V_10 -> V_22 ;
struct V_23 * V_24 = V_2 -> V_10 -> V_25 ;
V_24 [ 0 ] . V_26 = V_99 ;
V_24 [ 0 ] . V_28 = ( V_54 ) ( V_55 ) V_97 ;
V_24 [ 0 ] . V_29 = 32 ;
V_24 [ 0 ] . V_13 = V_100 ;
V_24 [ 1 ] . V_26 = V_101 ;
V_24 [ 1 ] . V_28 = ( V_54 ) ( V_55 ) V_98 ;
V_24 [ 1 ] . V_29 = 32 ;
V_24 [ 1 ] . V_13 = 0 ;
V_22 -> V_24 = V_24 ;
}
static void F_34 ( struct V_1 * V_2 , void * V_39 , int V_3 )
{
F_35 ( V_2 , V_39 , V_3 ) ;
}
void F_36 ( struct V_1 * V_2 , void * V_39 , void * V_97 ,
void * V_98 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
struct V_21 * V_22 = & V_2 -> V_10 -> V_22 ;
F_27 ( 4 , L_10 ) ;
F_28 ( 4 , & V_2 -> V_10 -> V_11 , sizeof( V_2 -> V_10 -> V_11 ) ) ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_22 -> V_62 = V_63 ;
V_22 -> V_64 = V_65 ;
V_22 -> V_31 = V_5 -> V_32 . V_33 . V_34 & V_5 -> V_35 ;
V_22 -> V_39 = V_39 ;
V_22 -> V_67 = F_34 ;
F_33 ( V_2 , V_97 , V_98 ) ;
F_9 ( V_2 ) ;
}
