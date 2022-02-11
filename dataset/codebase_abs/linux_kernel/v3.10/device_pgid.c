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
V_22 -> V_31 = F_8 ( V_22 -> V_31 , V_5 -> V_32 . V_33 . V_34 & V_5 -> V_35 &
~ V_2 -> V_10 -> V_36 ) ;
if ( ! V_22 -> V_31 )
goto V_37;
F_6 ( V_2 ) ;
F_9 ( V_2 ) ;
return;
V_37:
F_1 ( V_2 , V_5 -> V_20 ? 0 : - V_38 ) ;
}
static enum V_39 F_10 ( struct V_1 * V_2 , void * V_40 ,
struct V_41 * V_41 , enum V_39 V_42 )
{
if ( V_42 == V_43 && V_41 -> V_44 . V_45 . V_46 == 0 )
return V_47 ;
return V_42 ;
}
static void F_11 ( struct V_1 * V_2 , void * V_40 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
struct V_21 * V_22 = & V_2 -> V_10 -> V_22 ;
switch ( V_3 ) {
case 0 :
V_5 -> V_20 |= V_22 -> V_31 ;
break;
case - V_48 :
V_2 -> V_10 -> V_36 |= V_22 -> V_31 ;
break;
case - V_38 :
V_2 -> V_10 -> V_49 |= V_22 -> V_31 ;
break;
default:
goto V_50;
}
V_22 -> V_31 >>= 1 ;
F_7 ( V_2 ) ;
return;
V_50:
F_1 ( V_2 , V_3 ) ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_51 )
{
struct V_21 * V_22 = & V_2 -> V_10 -> V_22 ;
struct V_23 * V_24 = V_2 -> V_10 -> V_25 ;
int V_52 = 8 - F_13 ( V_22 -> V_31 ) ;
struct V_53 * V_53 = & V_2 -> V_10 -> V_53 [ V_52 ] ;
V_53 -> V_54 . V_55 = V_51 ;
V_24 -> V_26 = V_56 ;
V_24 -> V_28 = ( V_57 ) ( V_58 ) V_53 ;
V_24 -> V_29 = sizeof( * V_53 ) ;
V_24 -> V_13 = V_30 ;
V_22 -> V_24 = V_24 ;
}
static void F_14 ( struct V_1 * V_2 , void * V_40 , int V_3 )
{
if ( V_3 ) {
F_1 ( V_2 , V_3 ) ;
return;
}
V_2 -> V_10 -> V_13 . V_59 = 0 ;
F_15 ( V_2 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
struct V_8 * V_9 = & V_2 -> V_10 -> V_11 ;
struct V_21 * V_22 = & V_2 -> V_10 -> V_22 ;
T_1 V_51 ;
F_4 ( 2 , L_3 ,
V_9 -> V_18 , V_9 -> V_19 , V_2 -> V_10 -> V_60 ,
V_2 -> V_10 -> V_36 ) ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_22 -> V_61 = V_62 ;
V_22 -> V_63 = V_64 ;
V_22 -> V_31 = V_5 -> V_32 . V_33 . V_34 ;
V_22 -> V_65 = F_14 ;
V_51 = V_66 ;
if ( V_2 -> V_10 -> V_13 . V_12 )
V_51 |= V_67 ;
F_12 ( V_2 , V_51 ) ;
F_9 ( V_2 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
struct V_21 * V_22 = & V_2 -> V_10 -> V_22 ;
T_1 V_51 ;
V_22 -> V_31 = F_8 ( V_22 -> V_31 , V_2 -> V_10 -> V_68 ) ;
if ( ! V_22 -> V_31 )
goto V_37;
if ( V_22 -> V_31 & V_5 -> V_35 )
V_51 = V_69 ;
else
V_51 = V_70 ;
if ( V_2 -> V_10 -> V_13 . V_12 )
V_51 |= V_67 ;
F_12 ( V_2 , V_51 ) ;
F_9 ( V_2 ) ;
return;
V_37:
if ( V_2 -> V_10 -> V_13 . V_59 ) {
F_16 ( V_2 ) ;
return;
}
F_1 ( V_2 , V_5 -> V_20 ? 0 : - V_38 ) ;
}
static void F_18 ( struct V_1 * V_2 , void * V_40 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
struct V_21 * V_22 = & V_2 -> V_10 -> V_22 ;
switch ( V_3 ) {
case 0 :
V_5 -> V_20 |= V_22 -> V_31 & V_5 -> V_35 ;
break;
case - V_48 :
V_2 -> V_10 -> V_13 . V_59 = 1 ;
V_2 -> V_10 -> V_36 |= V_22 -> V_31 ;
break;
case - V_38 :
V_2 -> V_10 -> V_49 |= V_22 -> V_31 ;
break;
case - V_71 :
if ( V_2 -> V_10 -> V_13 . V_12 ) {
V_2 -> V_10 -> V_13 . V_12 = 0 ;
goto V_72;
}
V_2 -> V_10 -> V_13 . V_14 = 0 ;
goto V_72;
default:
goto V_50;
}
V_22 -> V_31 >>= 1 ;
F_17 ( V_2 ) ;
return;
V_72:
F_15 ( V_2 ) ;
return;
V_50:
F_1 ( V_2 , V_3 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = & V_2 -> V_10 -> V_22 ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_22 -> V_61 = V_62 ;
V_22 -> V_63 = V_64 ;
V_22 -> V_31 = 0x80 ;
V_22 -> V_73 = 1 ;
V_22 -> V_65 = F_18 ;
F_17 ( V_2 ) ;
}
static int F_20 ( struct V_53 * V_74 )
{
char * V_75 ;
for ( V_75 = ( char * ) V_74 + 1 ; V_75 < ( char * ) ( V_74 + 1 ) ; V_75 ++ ) {
if ( * V_75 != 0 )
return 0 ;
}
return 1 ;
}
static int F_21 ( struct V_53 * V_76 , struct V_53 * V_77 )
{
return memcmp ( ( char * ) V_76 + 1 , ( char * ) V_77 + 1 ,
sizeof( struct V_53 ) - 1 ) ;
}
static void F_22 ( struct V_1 * V_2 , struct V_53 * * V_74 ,
int * V_78 , T_1 * V_79 , T_1 * V_80 )
{
struct V_53 * V_53 = & V_2 -> V_10 -> V_53 [ 0 ] ;
struct V_53 * V_81 = NULL ;
int V_31 ;
int V_52 ;
* V_78 = 0 ;
* V_79 = 0 ;
* V_80 = 0 ;
for ( V_52 = 0 , V_31 = 0x80 ; V_52 < 8 ; V_52 ++ , V_53 ++ , V_31 >>= 1 ) {
if ( ( V_2 -> V_10 -> V_60 & V_31 ) == 0 )
continue;
if ( V_53 -> V_54 . V_82 . V_83 == V_84 )
* V_79 |= V_31 ;
if ( F_20 ( V_53 ) ) {
* V_80 |= V_31 ;
continue;
}
if ( ! V_81 ) {
V_81 = V_53 ;
continue;
}
if ( F_21 ( V_53 , V_81 ) != 0 )
* V_78 = 1 ;
}
if ( ! V_81 )
V_81 = & V_85 [ 0 ] -> V_86 ;
* V_74 = V_81 ;
}
static T_1 F_23 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
struct V_53 * V_53 ;
int V_52 ;
int V_31 ;
T_1 V_87 = 0 ;
for ( V_52 = 0 ; V_52 < 8 ; V_52 ++ ) {
V_31 = 0x80 >> V_52 ;
if ( ( V_2 -> V_10 -> V_60 & V_31 ) == 0 )
continue;
V_53 = & V_2 -> V_10 -> V_53 [ V_52 ] ;
if ( V_5 -> V_35 & V_31 ) {
if ( V_53 -> V_54 . V_82 . V_88 != V_89 )
continue;
} else {
if ( V_53 -> V_54 . V_82 . V_88 != V_90 )
continue;
}
if ( V_2 -> V_10 -> V_13 . V_12 ) {
if ( V_53 -> V_54 . V_82 . V_91 != V_92 )
continue;
} else {
if ( V_53 -> V_54 . V_82 . V_91 != V_93 )
continue;
}
V_87 |= V_31 ;
}
return V_87 ;
}
static void F_24 ( struct V_1 * V_2 , struct V_53 * V_53 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < 8 ; V_52 ++ )
memcpy ( & V_2 -> V_10 -> V_53 [ V_52 ] , V_53 , sizeof( struct V_53 ) ) ;
}
static void F_25 ( struct V_1 * V_2 , int V_3 )
{
struct V_8 * V_9 = & V_2 -> V_10 -> V_11 ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
struct V_53 * V_53 ;
int V_78 = 0 ;
T_1 V_79 = 0 ;
T_1 V_80 = 0 ;
T_1 V_87 ;
if ( V_3 )
goto V_15;
F_22 ( V_2 , & V_53 , & V_78 , & V_79 , & V_80 ) ;
if ( V_79 == V_2 -> V_10 -> V_60 )
V_3 = - V_94 ;
else if ( V_78 )
V_3 = - V_71 ;
else {
V_87 = F_23 ( V_2 ) ;
V_5 -> V_20 = V_87 & V_5 -> V_35 ;
V_2 -> V_10 -> V_95 |= V_80 ;
V_2 -> V_10 -> V_68 &=
~ ( V_87 | V_2 -> V_10 -> V_36 ) ;
F_24 ( V_2 , V_53 ) ;
}
V_15:
F_4 ( 2 , L_4
L_5 , V_9 -> V_18 ,
V_9 -> V_19 , V_3 , V_2 -> V_10 -> V_60 , V_5 -> V_20 ,
V_2 -> V_10 -> V_68 , V_78 , V_79 , V_80 ) ;
switch ( V_3 ) {
case 0 :
if ( V_2 -> V_10 -> V_13 . V_59 ) {
F_16 ( V_2 ) ;
return;
}
if ( V_2 -> V_10 -> V_68 == 0 ) {
F_1 ( V_2 , V_5 -> V_20 == 0 ? - V_38 : 0 ) ;
return;
}
F_19 ( V_2 ) ;
break;
case - V_71 :
V_2 -> V_10 -> V_13 . V_14 = 0 ;
V_2 -> V_10 -> V_13 . V_12 = 0 ;
F_15 ( V_2 ) ;
break;
default:
F_1 ( V_2 , V_3 ) ;
}
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = & V_2 -> V_10 -> V_22 ;
struct V_23 * V_24 = V_2 -> V_10 -> V_25 ;
int V_52 = 8 - F_13 ( V_22 -> V_31 ) ;
V_24 -> V_26 = V_96 ;
V_24 -> V_28 = ( V_57 ) ( V_58 ) & V_2 -> V_10 -> V_53 [ V_52 ] ;
V_24 -> V_29 = sizeof( struct V_53 ) ;
V_24 -> V_13 = V_30 ;
V_22 -> V_24 = V_24 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
struct V_21 * V_22 = & V_2 -> V_10 -> V_22 ;
int V_97 ;
V_22 -> V_31 = F_8 ( V_22 -> V_31 , V_5 -> V_32 . V_33 . V_34 &
~ V_2 -> V_10 -> V_36 ) ;
if ( ! V_22 -> V_31 )
goto V_37;
F_26 ( V_2 ) ;
F_9 ( V_2 ) ;
return;
V_37:
if ( V_2 -> V_10 -> V_60 )
V_97 = 0 ;
else if ( V_2 -> V_10 -> V_36 )
V_97 = - V_48 ;
else
V_97 = - V_38 ;
F_25 ( V_2 , V_97 ) ;
}
static void F_28 ( struct V_1 * V_2 , void * V_40 , int V_3 )
{
struct V_21 * V_22 = & V_2 -> V_10 -> V_22 ;
switch ( V_3 ) {
case 0 :
V_2 -> V_10 -> V_60 |= V_22 -> V_31 ;
break;
case - V_48 :
V_2 -> V_10 -> V_13 . V_59 = 1 ;
V_2 -> V_10 -> V_36 |= V_22 -> V_31 ;
break;
case - V_38 :
V_2 -> V_10 -> V_49 |= V_22 -> V_31 ;
break;
default:
goto V_50;
}
V_22 -> V_31 >>= 1 ;
F_27 ( V_2 ) ;
return;
V_50:
F_25 ( V_2 , V_3 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
struct V_21 * V_22 = & V_2 -> V_10 -> V_22 ;
struct V_8 * V_98 = & V_2 -> V_10 -> V_11 ;
V_5 -> V_20 = 0 ;
V_5 -> V_31 = V_5 -> V_32 . V_33 . V_34 ;
memset ( V_2 -> V_10 -> V_53 , 0 , sizeof( V_2 -> V_10 -> V_53 ) ) ;
V_2 -> V_10 -> V_60 = 0 ;
V_2 -> V_10 -> V_68 = V_5 -> V_32 . V_33 . V_34 ;
V_2 -> V_10 -> V_49 = 0 ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_22 -> V_61 = V_62 ;
V_22 -> V_63 = V_64 ;
V_22 -> V_31 = 0x80 ;
V_22 -> V_73 = 1 ;
if ( V_2 -> V_10 -> V_13 . V_14 ) {
F_29 ( 4 , L_6 ) ;
F_30 ( 4 , V_98 , sizeof( * V_98 ) ) ;
V_22 -> V_65 = F_28 ;
F_27 ( V_2 ) ;
} else {
F_29 ( 4 , L_7 ) ;
F_30 ( 4 , V_98 , sizeof( * V_98 ) ) ;
V_22 -> V_99 = F_10 ;
V_22 -> V_65 = F_11 ;
F_7 ( V_2 ) ;
}
}
void F_31 ( struct V_1 * V_2 )
{
F_29 ( 4 , L_8 ) ;
F_30 ( 4 , & V_2 -> V_10 -> V_11 , sizeof( V_2 -> V_10 -> V_11 ) ) ;
V_2 -> V_10 -> V_13 . V_14 = V_2 -> V_10 -> V_100 . V_14 ;
V_2 -> V_10 -> V_13 . V_12 = V_2 -> V_10 -> V_100 . V_12 ;
V_2 -> V_10 -> V_13 . V_101 = 0 ;
V_2 -> V_10 -> V_36 = 0 ;
F_15 ( V_2 ) ;
}
static void F_32 ( struct V_1 * V_2 , void * V_40 , int V_3 )
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
F_4 ( 0 , L_9 , V_9 -> V_18 , V_9 -> V_19 ,
V_3 ) ;
F_33 ( V_2 , V_3 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
struct V_21 * V_22 = & V_2 -> V_10 -> V_22 ;
T_1 V_51 ;
F_29 ( 4 , L_10 ) ;
F_30 ( 4 , & V_2 -> V_10 -> V_11 , sizeof( V_2 -> V_10 -> V_11 ) ) ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_22 -> V_61 = V_62 ;
V_22 -> V_63 = V_64 ;
V_22 -> V_31 = V_5 -> V_32 . V_33 . V_34 & V_5 -> V_35 ;
V_22 -> V_73 = 1 ;
V_22 -> V_65 = F_32 ;
V_51 = V_66 ;
if ( V_2 -> V_10 -> V_13 . V_12 )
V_51 |= V_67 ;
F_12 ( V_2 , V_51 ) ;
F_9 ( V_2 ) ;
}
static void F_35 ( struct V_1 * V_2 , void * V_102 , void * V_103 )
{
struct V_21 * V_22 = & V_2 -> V_10 -> V_22 ;
struct V_23 * V_24 = V_2 -> V_10 -> V_25 ;
V_24 [ 0 ] . V_26 = V_104 ;
V_24 [ 0 ] . V_28 = ( V_57 ) ( V_58 ) V_102 ;
V_24 [ 0 ] . V_29 = 32 ;
V_24 [ 0 ] . V_13 = V_105 ;
V_24 [ 1 ] . V_26 = V_106 ;
V_24 [ 1 ] . V_28 = ( V_57 ) ( V_58 ) V_103 ;
V_24 [ 1 ] . V_29 = 32 ;
V_24 [ 1 ] . V_13 = 0 ;
V_22 -> V_24 = V_24 ;
}
static void F_36 ( struct V_1 * V_2 , void * V_40 , int V_3 )
{
F_37 ( V_2 , V_40 , V_3 ) ;
}
void F_38 ( struct V_1 * V_2 , void * V_40 , void * V_102 ,
void * V_103 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
struct V_21 * V_22 = & V_2 -> V_10 -> V_22 ;
F_29 ( 4 , L_11 ) ;
F_30 ( 4 , & V_2 -> V_10 -> V_11 , sizeof( V_2 -> V_10 -> V_11 ) ) ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_22 -> V_61 = V_62 ;
V_22 -> V_63 = V_64 ;
V_22 -> V_31 = V_5 -> V_32 . V_33 . V_34 & V_5 -> V_35 ;
V_22 -> V_40 = V_40 ;
V_22 -> V_65 = F_36 ;
F_35 ( V_2 , V_102 , V_103 ) ;
F_9 ( V_2 ) ;
}
