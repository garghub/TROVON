int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_5 , T_1 * V_6 , int V_7 )
{
int V_8 = - 1 ;
if ( F_2 ( & V_2 -> V_9 ) )
return - V_10 ;
V_8 = F_3 ( V_2 -> V_11 ,
F_4 ( V_2 -> V_11 , 0 ) ,
V_3 ,
V_12 | V_13 ,
V_4 ,
V_5 ,
V_6 ,
V_7 ,
2000 ) ;
if ( V_8 < 0 ) {
F_5 ( L_1 , V_8 ) ;
V_8 = - V_14 ;
} else
V_8 = 0 ;
F_6 ( L_2 , V_3 , V_4 , V_5 ) ;
F_7 ( V_6 , V_7 , F_6 ) ;
F_8 ( & V_2 -> V_9 ) ;
return V_8 ;
}
static int F_9 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 ,
T_2 V_5 ,
T_1 * V_6 ,
int V_7 )
{
int V_8 ;
F_6 ( L_3 , V_3 , V_4 , V_5 ) ;
F_7 ( V_6 , V_7 , F_6 ) ;
if ( F_2 ( & V_2 -> V_9 ) )
return - V_10 ;
V_8 = F_3 ( V_2 -> V_11 ,
F_10 ( V_2 -> V_11 , 0 ) ,
V_3 ,
V_12 | V_15 ,
V_4 ,
V_5 ,
V_6 ,
V_7 ,
2000 ) ;
if ( V_8 != V_7 ) {
F_5 ( L_4 , V_8 ) ;
F_8 ( & V_2 -> V_9 ) ;
return - V_14 ;
} else{
F_8 ( & V_2 -> V_9 ) ;
return 0 ;
}
}
static int F_11 ( struct V_16 * V_17 , int V_18 )
{
int V_8 ;
T_1 V_3 ;
T_2 V_4 ;
T_2 V_5 ;
int V_7 ;
F_12 ( L_5 , V_19 , V_18 ) ;
V_3 = 0xBC ;
V_4 = V_18 ;
V_5 = 0 ;
V_7 = 0 ;
V_8 = F_9 ( V_17 -> V_20 , V_3 , V_4 , V_5 , NULL , V_7 ) ;
if ( V_8 != 0 )
F_5 ( L_4 , V_8 ) ;
return V_8 ;
}
static int F_13 ( struct V_1 * V_2 , T_3 * V_21 , int * V_22 )
{
return 0 ;
}
static int F_14 ( struct V_23 * V_24 ,
int V_25 ,
int V_26 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 -> V_27 ;
struct V_28 * V_22 = (struct V_28 * ) V_2 -> V_29 ;
int V_8 ;
T_1 V_3 ;
T_2 V_4 ;
T_2 V_5 ;
int V_7 ;
T_1 * V_6 ;
if ( V_25 != 0 )
return - V_30 ;
V_6 = F_15 ( 12 , V_31 ) ;
if ( ! V_6 )
return - V_32 ;
F_16 ( & V_22 -> V_33 ) ;
V_3 = 0xC1 ;
V_4 = V_26 ;
V_5 = 0 ;
V_7 = 1 ;
V_8 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ) ;
if ( V_8 < 0 ) {
F_5 ( L_1 , V_8 ) ;
V_8 = - V_30 ;
} else {
V_8 = V_6 [ 0 ] ;
}
F_8 ( & V_22 -> V_33 ) ;
F_17 ( V_6 ) ;
return V_8 ;
}
static int F_18 ( struct V_23 * V_24 ,
int V_25 ,
int V_26 ,
T_1 V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 -> V_27 ;
struct V_28 * V_22 = (struct V_28 * ) V_2 -> V_29 ;
int V_8 ;
T_1 V_3 ;
T_2 V_34 ;
T_2 V_5 ;
int V_7 ;
F_12 ( L_5 , V_19 , V_25 ) ;
if ( V_25 != 0 )
return - V_30 ;
F_16 ( & V_22 -> V_33 ) ;
V_3 = 0xC2 ;
V_34 = V_26 ;
V_5 = V_4 ;
V_7 = 0 ;
V_8 = F_9 ( V_2 , V_3 , V_34 , V_5 , NULL , V_7 ) ;
if ( V_8 != 0 )
F_5 ( L_4 , V_8 ) ;
F_8 ( & V_22 -> V_33 ) ;
return V_8 ;
}
static int F_19 ( struct V_23 * V_24 ,
int V_25 ,
T_1 V_26 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 -> V_27 ;
struct V_28 * V_22 = (struct V_28 * ) V_2 -> V_29 ;
int V_8 ;
T_1 V_3 ;
T_2 V_4 ;
T_2 V_5 ;
int V_7 ;
T_1 * V_6 ;
if ( V_25 != 0 )
return - V_30 ;
V_6 = F_15 ( 12 , V_31 ) ;
if ( ! V_6 )
return - V_32 ;
F_16 ( & V_22 -> V_33 ) ;
V_3 = 0xC3 ;
V_4 = V_26 ;
V_5 = 0 ;
V_7 = 2 ;
V_8 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ) ;
if ( V_8 < 0 ) {
F_5 ( L_1 , V_8 ) ;
V_8 = - V_30 ;
} else {
if ( V_6 [ 0 ] == 0 )
F_5 ( L_6 ) ;
V_8 = V_6 [ 1 ] ;
F_12 ( L_7 , V_6 [ 1 ] , V_4 ) ;
}
F_8 ( & V_22 -> V_33 ) ;
F_17 ( V_6 ) ;
return V_8 ;
}
static int F_20 ( struct V_23 * V_24 ,
int V_25 ,
T_1 V_26 ,
T_1 V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 -> V_27 ;
struct V_28 * V_22 = (struct V_28 * ) V_2 -> V_29 ;
int V_8 ;
T_1 V_3 ;
T_2 V_34 ;
T_2 V_5 ;
int V_7 ;
if ( V_25 != 0 )
return - V_30 ;
F_16 ( & V_22 -> V_33 ) ;
V_3 = 0xC4 ;
V_34 = V_26 ;
V_5 = V_4 ;
V_7 = 0 ;
V_8 = F_9 ( V_2 , V_3 , V_34 , V_5 , NULL , V_7 ) ;
if ( V_8 != 0 ) {
F_5 ( L_4 , V_8 ) ;
goto V_35;
}
V_35:
F_8 ( & V_22 -> V_33 ) ;
return V_8 ;
}
static int F_21 ( struct V_23 * V_24 , int V_25 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 -> V_27 ;
int V_8 ;
T_1 V_3 ;
T_2 V_4 ;
T_2 V_5 ;
int V_7 ;
T_1 * V_6 ;
V_6 = F_15 ( 12 , V_31 ) ;
if ( ! V_6 )
return - V_32 ;
V_3 = 0xC8 ;
V_4 = 0 ;
V_5 = 0 ;
V_7 = 1 ;
V_8 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ) ;
if ( V_8 < 0 ) {
F_5 ( L_1 , V_8 ) ;
V_8 = - V_14 ;
} else{
V_8 = V_6 [ 0 ] ;
}
F_17 ( V_6 ) ;
return V_8 ;
}
static int F_22 ( struct V_23 * V_24 , int V_25 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 -> V_27 ;
struct V_28 * V_22 = (struct V_28 * ) V_2 -> V_29 ;
int V_8 , V_36 ;
T_1 V_3 ;
T_2 V_4 ;
T_2 V_5 ;
int V_7 ;
F_16 ( & V_22 -> V_33 ) ;
V_3 = 0xC6 ;
V_4 = 1 ;
V_5 = 0 ;
V_7 = 0 ;
V_8 = F_9 ( V_2 , V_3 , V_4 , V_5 , NULL , V_7 ) ;
if ( V_8 != 0 ) {
F_5 ( L_4 , V_8 ) ;
goto V_35;
}
F_23 ( 500 ) ;
V_3 = 0xC6 ;
V_4 = 0 ;
V_5 = 0 ;
V_7 = 0 ;
V_8 = F_9 ( V_2 , V_3 , V_4 , V_5 , NULL , V_7 ) ;
if ( V_8 != 0 ) {
F_5 ( L_4 , V_8 ) ;
goto V_35;
}
for ( V_36 = 0 ; V_36 < 15 ; V_36 ++ ) {
F_23 ( 100 ) ;
if ( F_21 ( V_24 , V_25 ) ) {
F_12 ( L_8 ) ;
break;
}
}
F_23 ( 5000 ) ;
V_35:
F_8 ( & V_22 -> V_33 ) ;
return V_8 ;
}
static int F_24 ( struct V_23 * V_24 , int V_25 )
{
return 0 ;
}
static int F_25 ( struct V_23 * V_24 , int V_25 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 -> V_27 ;
struct V_28 * V_22 = (struct V_28 * ) V_2 -> V_29 ;
int V_8 ;
T_1 V_3 ;
T_2 V_4 ;
T_2 V_5 ;
int V_7 ;
F_12 ( L_9 , V_19 ) ;
F_16 ( & V_22 -> V_33 ) ;
V_3 = 0xC7 ;
V_4 = 1 ;
V_5 = 0 ;
V_7 = 0 ;
V_8 = F_9 ( V_2 , V_3 , V_4 , V_5 , NULL , V_7 ) ;
if ( V_8 != 0 ) {
F_5 ( L_4 , V_8 ) ;
goto V_35;
}
V_35:
F_8 ( & V_22 -> V_33 ) ;
return V_8 ;
}
static int F_26 ( struct V_23 * V_24 , int V_25 , int V_37 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 -> V_27 ;
struct V_28 * V_22 = (struct V_28 * ) V_2 -> V_29 ;
int V_8 ;
T_1 V_3 ;
T_2 V_4 ;
T_2 V_5 ;
int V_7 ;
T_1 * V_6 ;
V_6 = F_15 ( 12 , V_31 ) ;
if ( ! V_6 )
return - V_32 ;
F_16 ( & V_22 -> V_33 ) ;
V_3 = 0xC5 ;
V_4 = 0 ;
V_5 = 0 ;
V_7 = 1 ;
V_8 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ) ;
if ( V_8 < 0 ) {
F_5 ( L_1 , V_8 ) ;
V_8 = - V_14 ;
} else
V_8 = 0 ;
if ( ! V_8 && V_6 [ 0 ] == 1 ) {
V_8 = V_38 |
V_39 ;
}
F_8 ( & V_22 -> V_33 ) ;
F_17 ( V_6 ) ;
return V_8 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_28 * V_22 ;
F_12 ( L_9 , V_19 ) ;
if ( NULL == V_2 )
return;
V_22 = (struct V_28 * ) V_2 -> V_29 ;
if ( NULL == V_22 )
return;
if ( NULL == V_22 -> V_24 . V_27 )
return;
F_28 ( & V_22 -> V_24 ) ;
memset ( & V_22 -> V_24 , 0 , sizeof( V_22 -> V_24 ) ) ;
}
static int F_29 ( struct V_16 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_20 ;
struct V_28 * V_22 = (struct V_28 * ) V_2 -> V_29 ;
int V_8 ;
F_12 ( L_9 , V_19 ) ;
F_30 ( & V_22 -> V_33 ) ;
V_22 -> V_24 . V_41 = V_42 ;
V_22 -> V_24 . V_43 = F_14 ;
V_22 -> V_24 . V_44 = F_18 ;
V_22 -> V_24 . V_45 = F_19 ;
V_22 -> V_24 . V_46 = F_20 ;
V_22 -> V_24 . V_47 = F_22 ;
V_22 -> V_24 . V_48 = F_24 ;
V_22 -> V_24 . V_49 = F_25 ;
V_22 -> V_24 . V_50 = F_26 ;
V_22 -> V_24 . V_27 = V_2 ;
V_8 = F_31 ( & V_40 -> V_51 ,
& V_22 -> V_24 ,
0 ,
1 ) ;
if ( V_8 != 0 ) {
F_32 ( L_10 , V_8 ) ;
memset ( & V_22 -> V_24 , 0 , sizeof( V_22 -> V_24 ) ) ;
return V_8 ;
}
F_12 ( L_11 ) ;
return 0 ;
}
static int F_33 ( struct V_52 * V_53 , T_4 V_54 )
{
T_1 V_55 ;
struct V_16 * V_17 = V_53 -> V_56 -> V_29 ;
struct V_57 V_57 = {
. V_58 = 0x99 ,
. V_59 = 0 ,
. V_55 = & V_55 ,
. V_60 = 1
} ;
switch ( V_54 ) {
case V_61 :
V_55 = 1 ;
F_34 ( & V_17 -> V_20 -> V_62 , & V_57 , 1 ) ;
break;
case V_63 :
V_55 = 2 ;
F_34 ( & V_17 -> V_20 -> V_62 , & V_57 , 1 ) ;
break;
case V_64 :
V_55 = 0 ;
F_34 ( & V_17 -> V_20 -> V_62 , & V_57 , 1 ) ;
break;
default:
return - V_30 ;
}
return 0 ;
}
static int F_35 ( struct V_16 * V_17 )
{
int V_8 ;
T_1 V_3 ;
T_2 V_4 ;
T_2 V_5 ;
int V_7 ;
V_3 = 0xBC ;
V_4 = 1 ;
V_5 = 3 ;
V_7 = 0 ;
V_8 = F_9 ( V_17 -> V_20 , V_3 , V_4 , V_5 , NULL , V_7 ) ;
if ( V_8 != 0 )
return - V_14 ;
return 0 ;
}
static int F_36 ( struct V_16 * V_17 )
{
int V_8 ;
T_1 V_3 ;
T_2 V_4 ;
T_2 V_5 ;
int V_7 ;
V_3 = 0xC0 ;
V_4 = 1 ;
V_5 = 3 ;
V_7 = 0 ;
V_8 = F_9 ( V_17 -> V_20 , V_3 , V_4 , V_5 , NULL , V_7 ) ;
if ( V_8 != 0 )
return - V_14 ;
V_3 = 0xC0 ;
V_4 = 0 ;
V_5 = 3 ;
V_7 = 0 ;
F_37 ( 200 ) ;
V_8 = F_9 ( V_17 -> V_20 , V_3 , V_4 , V_5 , NULL , V_7 ) ;
if ( V_8 != 0 )
return - V_14 ;
F_37 ( 200 ) ;
V_3 = 0xC0 ;
V_4 = 1 ;
V_5 = 3 ;
V_7 = 0 ;
V_8 = F_9 ( V_17 -> V_20 , V_3 , V_4 , V_5 , NULL , V_7 ) ;
if ( V_8 != 0 )
return - V_14 ;
F_37 ( 200 ) ;
return 0 ;
}
static int F_38 ( struct V_16 * V_17 , int V_18 )
{
int V_8 ;
T_1 V_3 ;
T_2 V_4 ;
T_2 V_5 ;
int V_7 ;
V_3 = 0xC7 ;
V_4 = V_18 ;
V_5 = 0 ;
V_7 = 0 ;
V_8 = F_9 ( V_17 -> V_20 , V_3 , V_4 , V_5 , NULL , V_7 ) ;
if ( V_8 != 0 )
return - V_14 ;
return 0 ;
}
static int F_39 ( struct V_16 * V_17 )
{
F_35 ( V_17 ) ;
F_36 ( V_17 ) ;
F_12 ( L_12 , V_17 , V_17 -> V_20 ) ;
V_17 -> V_65 [ 0 ] . V_53 = F_40 ( & V_66 , & V_17 -> V_20 -> V_62 ) ;
if ( V_17 -> V_65 [ 0 ] . V_53 ) {
F_12 ( L_13 , V_66 . V_67 ) ;
if ( F_41 ( V_17 -> V_65 [ 0 ] . V_53 , & V_68 , & V_17 -> V_20 -> V_62 ) ) {
F_12 ( L_14 , V_68 . V_69 ) ;
V_17 -> V_65 [ 0 ] . V_53 -> V_70 . V_71 = F_33 ;
F_29 ( V_17 ) ;
} else {
V_17 -> V_65 [ 0 ] . V_53 = NULL ;
}
} else
F_5 ( L_15 ) ;
F_38 ( V_17 , 0 ) ;
return 0 ;
}
static void F_42 ( struct V_72 * V_73 )
{
struct V_1 * V_2 = F_43 ( V_73 ) ;
F_27 ( V_2 ) ;
F_44 ( V_73 ) ;
}
static int F_45 ( struct V_72 * V_73 ,
const struct V_74 * V_75 )
{
return F_46 ( V_73 ,
& V_76 ,
V_42 ,
NULL ,
V_77 ) ;
}
static int F_47 ( struct V_78 * V_17 , struct V_57 V_79 [] , int V_80 )
{
struct V_1 * V_2 = F_48 ( V_17 ) ;
int V_36 = 0 , V_81 = 0 , V_60 = 0 ;
T_2 V_5 ;
T_2 V_4 ;
int V_82 ;
T_1 V_3 ;
T_1 * V_27 ;
V_27 = F_15 ( 256 , V_31 ) ;
if ( ! V_27 )
return - V_32 ;
if ( F_2 ( & V_2 -> V_83 ) < 0 ) {
F_17 ( V_27 ) ;
return - V_10 ;
}
if ( V_80 > 2 )
F_5 ( L_16 ) ;
for ( V_36 = 0 ; V_36 < V_80 ; V_36 ++ ) {
if ( V_79 [ V_36 ] . V_58 == 0x99 ) {
V_3 = 0xBE ;
V_5 = 0 ;
V_4 = V_79 [ V_36 ] . V_55 [ 0 ] & 0x00ff ;
V_82 = 1 ;
F_9 ( V_2 , V_3 , V_4 , V_5 , V_27 , V_82 ) ;
}
if ( V_79 [ V_36 ] . V_58 == 0xd0 ) {
if ( V_36 + 1 < V_80 && ( V_79 [ V_36 + 1 ] . V_59 & V_84 ) ) {
V_3 = 0xB9 ;
V_5 = ( ( ( V_79 [ V_36 ] . V_55 [ 0 ] << 8 ) & 0xff00 ) | ( V_79 [ V_36 ] . V_55 [ 1 ] & 0x00ff ) ) ;
V_4 = V_79 [ V_36 ] . V_58 + ( V_79 [ V_36 ] . V_60 << 8 ) ;
V_82 = V_79 [ V_36 + 1 ] . V_60 + 6 ;
F_1 ( V_2 , V_3 , V_4 , V_5 , V_27 , V_82 ) ;
V_60 = V_79 [ V_36 + 1 ] . V_60 ;
for ( V_81 = 0 ; V_81 < V_60 ; V_81 ++ )
V_79 [ V_36 + 1 ] . V_55 [ V_81 ] = V_27 [ V_81 + 5 ] ;
V_36 ++ ;
} else {
V_3 = 0xBD ;
V_5 = ( ( ( V_79 [ V_36 ] . V_55 [ 0 ] << 8 ) & 0xff00 ) | ( V_79 [ V_36 ] . V_55 [ 1 ] & 0x00ff ) ) ;
V_4 = V_79 [ V_36 ] . V_58 + ( 2 << 8 ) ;
V_82 = V_79 [ V_36 ] . V_60 - 2 ;
V_60 = V_79 [ V_36 ] . V_60 - 2 ;
for ( V_81 = 0 ; V_81 < V_60 ; V_81 ++ )
V_27 [ V_81 ] = V_79 [ V_36 ] . V_55 [ V_81 + 2 ] ;
F_9 ( V_2 , V_3 , V_4 , V_5 , V_27 , V_82 ) ;
}
}
if ( V_79 [ V_36 ] . V_58 == 0xc0 ) {
if ( V_79 [ V_36 ] . V_59 & V_84 ) {
V_3 = 0xB9 ;
V_5 = 0x0 ;
V_4 = V_79 [ V_36 ] . V_58 ;
V_82 = V_79 [ V_36 ] . V_60 + 6 ;
F_1 ( V_2 , V_3 , V_4 , V_5 , V_27 , V_82 ) ;
V_60 = V_79 [ V_36 ] . V_60 ;
for ( V_81 = 0 ; V_81 < V_60 ; V_81 ++ )
V_79 [ V_36 ] . V_55 [ V_81 ] = V_27 [ V_81 + 5 ] ;
} else {
V_3 = 0xBD ;
V_5 = V_79 [ V_36 ] . V_55 [ 0 ] & 0x00FF ;
V_4 = V_79 [ V_36 ] . V_58 + ( 1 << 8 ) ;
V_82 = V_79 [ V_36 ] . V_60 - 1 ;
V_60 = V_79 [ V_36 ] . V_60 - 1 ;
for ( V_81 = 0 ; V_81 < V_60 ; V_81 ++ )
V_27 [ V_81 ] = V_79 [ V_36 ] . V_55 [ V_81 + 1 ] ;
F_9 ( V_2 , V_3 , V_4 , V_5 , V_27 , V_82 ) ;
}
}
}
F_8 ( & V_2 -> V_83 ) ;
F_17 ( V_27 ) ;
return V_36 ;
}
static T_3 F_49 ( struct V_78 * V_85 )
{
return V_86 ;
}
int F_50 ( struct V_87 * V_11 ,
struct V_88 * V_89 ,
struct V_90 * * V_91 ,
int * V_92 )
{
T_1 * V_6 ;
T_5 V_8 ;
V_6 = F_15 ( 16 , V_31 ) ;
if ( ! V_6 )
return - V_32 ;
V_8 = F_3 ( V_11 ,
F_4 ( V_11 , 0 ) ,
0xb7 ,
V_12 | V_13 ,
6 ,
0 ,
V_6 ,
6 ,
V_93 ) ;
* V_92 = V_8 <= 0 ;
F_17 ( V_6 ) ;
F_12 ( L_17 , * V_92 ) ;
return 0 ;
}
