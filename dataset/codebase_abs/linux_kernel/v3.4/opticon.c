static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
unsigned char * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_3 -> V_8 ;
int V_9 = V_1 -> V_9 ;
struct V_10 * V_11 ;
int V_12 ;
int V_13 ;
unsigned long V_14 ;
F_2 ( L_1 , V_15 , V_8 -> V_16 ) ;
switch ( V_9 ) {
case 0 :
break;
case - V_17 :
case - V_18 :
case - V_19 :
F_2 ( L_2 ,
V_15 , V_9 ) ;
return;
default:
F_2 ( L_3 ,
V_15 , V_9 ) ;
goto exit;
}
F_3 ( V_20 , & V_8 -> V_21 , V_15 , V_1 -> V_22 ,
V_5 ) ;
if ( V_1 -> V_22 > 2 ) {
V_13 = V_1 -> V_22 - 2 ;
if ( ( V_5 [ 0 ] == 0x00 ) && ( V_5 [ 1 ] == 0x00 ) ) {
V_11 = F_4 ( & V_8 -> V_8 ) ;
if ( V_11 ) {
F_5 ( V_11 , V_5 + 2 ,
V_13 ) ;
F_6 ( V_11 ) ;
F_7 ( V_11 ) ;
}
} else {
if ( ( V_5 [ 0 ] == 0x00 ) && ( V_5 [ 1 ] == 0x01 ) ) {
F_8 ( & V_3 -> V_23 , V_14 ) ;
if ( V_5 [ 2 ] == 0x00 )
V_3 -> V_24 = false ;
else
V_3 -> V_24 = true ;
F_9 ( & V_3 -> V_23 , V_14 ) ;
} else {
F_10 ( & V_3 -> V_25 -> V_21 ,
L_4
L_5 ,
V_5 [ 0 ] , V_5 [ 1 ] ) ;
}
}
} else {
F_10 ( & V_3 -> V_25 -> V_21 ,
L_6
L_7 , V_1 -> V_22 ) ;
}
exit:
F_11 ( & V_3 -> V_23 ) ;
if ( ! V_3 -> V_26 ) {
F_12 ( V_3 -> V_27 , V_3 -> V_25 ,
F_13 ( V_3 -> V_25 ,
V_3 -> V_28 ) ,
V_3 -> V_29 , V_3 -> V_30 ,
F_1 , V_3 ) ;
V_12 = F_14 ( V_3 -> V_27 , V_31 ) ;
if ( V_12 )
F_15 ( & V_8 -> V_21 ,
L_8 ,
V_15 , V_12 ) ;
} else
V_3 -> V_32 = true ;
F_16 ( & V_3 -> V_23 ) ;
}
static int F_17 ( struct V_7 * V_8 , T_1 V_33 ,
T_1 V_34 )
{
struct V_35 * V_36 = V_8 -> V_36 ;
int V_37 ;
T_1 V_38 [ 2 ] ;
V_38 [ 0 ] = V_34 ;
V_37 = F_18 ( V_36 -> V_21 , F_19 ( V_36 -> V_21 , 0 ) ,
V_33 ,
V_39 | V_40 | V_41 ,
0 , 0 , V_38 , 1 , 0 ) ;
return V_37 ;
}
static int F_20 ( struct V_10 * V_11 , struct V_7 * V_8 )
{
struct V_2 * V_3 = F_21 ( V_8 -> V_36 ) ;
unsigned long V_14 ;
int V_12 = 0 ;
F_2 ( L_1 , V_15 , V_8 -> V_16 ) ;
F_8 ( & V_3 -> V_23 , V_14 ) ;
V_3 -> V_26 = false ;
V_3 -> V_32 = false ;
V_3 -> V_8 = V_8 ;
V_3 -> V_42 = false ;
F_9 ( & V_3 -> V_23 , V_14 ) ;
F_17 ( V_8 , V_43 , 0 ) ;
F_12 ( V_3 -> V_27 , V_3 -> V_25 ,
F_13 ( V_3 -> V_25 ,
V_3 -> V_28 ) ,
V_3 -> V_29 , V_3 -> V_30 ,
F_1 , V_3 ) ;
F_22 ( V_3 -> V_25 , V_3 -> V_27 -> V_44 ) ;
V_12 = F_14 ( V_3 -> V_27 , V_45 ) ;
if ( V_12 )
F_15 ( & V_8 -> V_21 ,
L_8 ,
V_15 , V_12 ) ;
F_17 ( V_8 , V_46 , 1 ) ;
return V_12 ;
}
static void F_23 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_21 ( V_8 -> V_36 ) ;
F_2 ( L_1 , V_15 , V_8 -> V_16 ) ;
F_24 ( V_3 -> V_27 ) ;
}
static void F_25 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
int V_9 = V_1 -> V_9 ;
unsigned long V_14 ;
F_26 ( V_1 -> V_6 ) ;
F_26 ( V_1 -> V_47 ) ;
if ( V_9 )
F_2 ( L_9 ,
V_15 , V_9 ) ;
F_8 ( & V_3 -> V_23 , V_14 ) ;
-- V_3 -> V_48 ;
F_9 ( & V_3 -> V_23 , V_14 ) ;
F_27 ( V_3 -> V_8 ) ;
}
static int F_28 ( struct V_10 * V_11 , struct V_7 * V_8 ,
const unsigned char * V_49 , int V_50 )
{
struct V_2 * V_3 = F_21 ( V_8 -> V_36 ) ;
struct V_35 * V_36 = V_8 -> V_36 ;
struct V_1 * V_1 ;
unsigned char * V_38 ;
unsigned long V_14 ;
int V_9 ;
struct V_51 * V_52 ;
F_2 ( L_1 , V_15 , V_8 -> V_16 ) ;
F_8 ( & V_3 -> V_23 , V_14 ) ;
if ( V_3 -> V_48 > V_53 ) {
F_9 ( & V_3 -> V_23 , V_14 ) ;
F_2 ( L_10 , V_15 ) ;
return 0 ;
}
V_3 -> V_48 ++ ;
F_9 ( & V_3 -> V_23 , V_14 ) ;
V_38 = F_29 ( V_50 , V_31 ) ;
if ( ! V_38 ) {
F_15 ( & V_8 -> V_21 , L_11 ) ;
V_50 = - V_54 ;
goto V_55;
}
V_1 = F_30 ( 0 , V_31 ) ;
if ( ! V_1 ) {
F_15 ( & V_8 -> V_21 , L_12 ) ;
V_50 = - V_54 ;
goto V_56;
}
memcpy ( V_38 , V_49 , V_50 ) ;
F_3 ( V_20 , & V_8 -> V_21 , V_15 , V_50 , V_38 ) ;
V_52 = F_29 ( sizeof( struct V_51 ) , V_57 ) ;
if ( ! V_52 ) {
F_15 ( & V_8 -> V_21 , L_11 ) ;
V_50 = - V_54 ;
goto error;
}
V_52 -> V_58 = V_40 | V_41 | V_39 ;
V_52 -> V_59 = 0x01 ;
V_52 -> V_60 = 0 ;
V_52 -> V_61 = 0 ;
V_52 -> V_62 = F_31 ( V_50 ) ;
F_32 ( V_1 , V_36 -> V_21 ,
F_19 ( V_36 -> V_21 , 0 ) ,
( unsigned char * ) V_52 , V_38 , V_50 ,
F_25 , V_3 ) ;
V_9 = F_14 ( V_1 , V_31 ) ;
if ( V_9 ) {
F_15 ( & V_8 -> V_21 ,
L_13 ,
V_15 , V_9 ) ;
V_50 = V_9 ;
goto error;
}
F_33 ( V_1 ) ;
return V_50 ;
error:
F_33 ( V_1 ) ;
V_56:
F_26 ( V_38 ) ;
V_55:
F_8 ( & V_3 -> V_23 , V_14 ) ;
-- V_3 -> V_48 ;
F_9 ( & V_3 -> V_23 , V_14 ) ;
return V_50 ;
}
static int F_34 ( struct V_10 * V_11 )
{
struct V_7 * V_8 = V_11 -> V_63 ;
struct V_2 * V_3 = F_21 ( V_8 -> V_36 ) ;
unsigned long V_14 ;
F_2 ( L_1 , V_15 , V_8 -> V_16 ) ;
F_8 ( & V_3 -> V_23 , V_14 ) ;
if ( V_3 -> V_48 > V_53 * 2 / 3 ) {
F_9 ( & V_3 -> V_23 , V_14 ) ;
F_2 ( L_10 , V_15 ) ;
return 0 ;
}
F_9 ( & V_3 -> V_23 , V_14 ) ;
return 2048 ;
}
static void F_35 ( struct V_10 * V_11 )
{
struct V_7 * V_8 = V_11 -> V_63 ;
struct V_2 * V_3 = F_21 ( V_8 -> V_36 ) ;
unsigned long V_14 ;
F_2 ( L_1 , V_15 , V_8 -> V_16 ) ;
F_8 ( & V_3 -> V_23 , V_14 ) ;
V_3 -> V_26 = true ;
F_9 ( & V_3 -> V_23 , V_14 ) ;
}
static void F_36 ( struct V_10 * V_11 )
{
struct V_7 * V_8 = V_11 -> V_63 ;
struct V_2 * V_3 = F_21 ( V_8 -> V_36 ) ;
unsigned long V_14 ;
int V_12 , V_64 ;
F_2 ( L_1 , V_15 , V_8 -> V_16 ) ;
F_8 ( & V_3 -> V_23 , V_14 ) ;
V_3 -> V_26 = false ;
V_64 = V_3 -> V_32 ;
V_3 -> V_32 = false ;
F_9 ( & V_3 -> V_23 , V_14 ) ;
if ( V_64 ) {
V_12 = F_14 ( V_3 -> V_27 , V_31 ) ;
if ( V_12 )
F_15 ( & V_8 -> V_21 ,
L_14 ,
V_15 , V_12 ) ;
}
}
static int F_37 ( struct V_10 * V_11 )
{
struct V_7 * V_8 = V_11 -> V_63 ;
struct V_2 * V_3 = F_21 ( V_8 -> V_36 ) ;
unsigned long V_14 ;
int V_12 = 0 ;
F_2 ( L_1 , V_15 , V_8 -> V_16 ) ;
if ( ! F_38 ( V_8 -> V_36 -> V_65 ) )
return - V_66 ;
F_8 ( & V_3 -> V_23 , V_14 ) ;
if ( V_3 -> V_42 )
V_12 |= V_67 ;
if ( V_3 -> V_24 )
V_12 |= V_68 ;
F_9 ( & V_3 -> V_23 , V_14 ) ;
F_2 ( L_15 , V_15 , V_12 ) ;
return V_12 ;
}
static int F_39 ( struct V_10 * V_11 ,
unsigned int V_69 , unsigned int V_70 )
{
struct V_7 * V_8 = V_11 -> V_63 ;
struct V_2 * V_3 = F_21 ( V_8 -> V_36 ) ;
unsigned long V_14 ;
bool V_42 ;
bool V_71 = false ;
if ( ! F_38 ( V_8 -> V_36 -> V_65 ) )
return - V_66 ;
F_8 ( & V_3 -> V_23 , V_14 ) ;
V_42 = V_3 -> V_42 ;
if ( V_69 & V_67 )
V_3 -> V_42 = true ;
if ( V_70 & V_67 )
V_3 -> V_42 = false ;
V_71 = V_42 ^ V_3 -> V_42 ;
F_9 ( & V_3 -> V_23 , V_14 ) ;
if ( ! V_71 )
return 0 ;
return F_17 ( V_8 , V_43 , ! V_42 ) ;
}
static int F_40 ( struct V_2 * V_3 ,
struct V_72 T_2 * V_36 )
{
struct V_72 V_73 ;
if ( ! V_36 )
return - V_74 ;
memset ( & V_73 , 0x00 , sizeof( V_73 ) ) ;
V_73 . type = V_75 ;
V_73 . line = V_3 -> V_36 -> V_76 ;
V_73 . V_8 = 0 ;
V_73 . V_77 = 0 ;
V_73 . V_14 = V_78 | V_79 ;
V_73 . V_80 = 1024 ;
V_73 . V_81 = 9600 ;
V_73 . V_82 = 5 * V_83 ;
V_73 . V_84 = 30 * V_83 ;
if ( F_41 ( V_36 , & V_73 , sizeof( * V_36 ) ) )
return - V_74 ;
return 0 ;
}
static int F_42 ( struct V_10 * V_11 ,
unsigned int V_85 , unsigned long V_86 )
{
struct V_7 * V_8 = V_11 -> V_63 ;
struct V_2 * V_3 = F_21 ( V_8 -> V_36 ) ;
F_2 ( L_16 , V_15 , V_8 -> V_16 , V_85 ) ;
switch ( V_85 ) {
case V_87 :
return F_40 ( V_3 ,
(struct V_72 T_2 * ) V_86 ) ;
}
return - V_88 ;
}
static int F_43 ( struct V_35 * V_36 )
{
struct V_2 * V_3 ;
struct V_89 * V_90 ;
int V_91 ;
int V_37 = - V_54 ;
bool V_92 = false ;
V_3 = F_44 ( sizeof( * V_3 ) , V_45 ) ;
if ( V_3 == NULL ) {
F_15 ( & V_36 -> V_21 -> V_21 , L_17 , V_15 ) ;
return - V_54 ;
}
F_45 ( & V_3 -> V_23 ) ;
V_3 -> V_36 = V_36 ;
V_3 -> V_8 = V_36 -> V_8 [ 0 ] ;
V_3 -> V_25 = V_36 -> V_21 ;
V_3 -> V_48 = 0 ;
V_90 = V_36 -> V_65 -> V_93 ;
for ( V_91 = 0 ; V_91 < V_90 -> V_94 . V_95 ; ++ V_91 ) {
struct V_96 * V_97 ;
V_97 = & V_90 -> V_97 [ V_91 ] . V_94 ;
if ( ! F_46 ( V_97 ) )
continue;
V_3 -> V_27 = F_30 ( 0 , V_45 ) ;
if ( ! V_3 -> V_27 ) {
F_15 ( & V_3 -> V_25 -> V_21 , L_11 ) ;
goto error;
}
V_3 -> V_30 = F_47 ( V_97 ) * 2 ;
V_3 -> V_29 = F_29 ( V_3 -> V_30 , V_45 ) ;
if ( ! V_3 -> V_29 ) {
F_15 ( & V_3 -> V_25 -> V_21 , L_11 ) ;
goto error;
}
V_3 -> V_28 = V_97 -> V_98 ;
V_92 = true ;
break;
}
if ( ! V_92 ) {
F_15 ( & V_3 -> V_25 -> V_21 ,
L_18 ) ;
goto error;
}
F_48 ( V_36 , V_3 ) ;
return 0 ;
error:
F_33 ( V_3 -> V_27 ) ;
F_26 ( V_3 -> V_29 ) ;
F_26 ( V_3 ) ;
return V_37 ;
}
static void F_49 ( struct V_35 * V_36 )
{
struct V_2 * V_3 = F_21 ( V_36 ) ;
F_2 ( L_19 , V_15 ) ;
F_24 ( V_3 -> V_27 ) ;
F_33 ( V_3 -> V_27 ) ;
}
static void F_50 ( struct V_35 * V_36 )
{
struct V_2 * V_3 = F_21 ( V_36 ) ;
F_2 ( L_19 , V_15 ) ;
F_26 ( V_3 -> V_29 ) ;
F_26 ( V_3 ) ;
}
static int F_51 ( struct V_99 * V_90 , T_3 V_100 )
{
struct V_35 * V_36 = F_38 ( V_90 ) ;
struct V_2 * V_3 = F_21 ( V_36 ) ;
F_24 ( V_3 -> V_27 ) ;
return 0 ;
}
static int F_52 ( struct V_99 * V_90 )
{
struct V_35 * V_36 = F_38 ( V_90 ) ;
struct V_2 * V_3 = F_21 ( V_36 ) ;
struct V_7 * V_8 = V_36 -> V_8 [ 0 ] ;
int V_12 ;
F_53 ( & V_8 -> V_8 . V_101 ) ;
if ( F_54 ( V_102 , & V_8 -> V_8 . V_14 ) )
V_12 = F_14 ( V_3 -> V_27 , V_57 ) ;
else
V_12 = 0 ;
F_55 ( & V_8 -> V_8 . V_101 ) ;
return V_12 ;
}
