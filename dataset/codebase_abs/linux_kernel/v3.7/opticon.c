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
switch ( V_9 ) {
case 0 :
break;
case - V_15 :
case - V_16 :
case - V_17 :
F_2 ( & V_3 -> V_18 -> V_19 , L_1 ,
V_20 , V_9 ) ;
return;
default:
F_2 ( & V_3 -> V_18 -> V_19 , L_2 ,
V_20 , V_9 ) ;
goto exit;
}
F_3 ( & V_8 -> V_19 , V_20 , V_1 -> V_21 , V_5 ) ;
if ( V_1 -> V_21 > 2 ) {
V_13 = V_1 -> V_21 - 2 ;
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
F_8 ( & V_3 -> V_22 , V_14 ) ;
if ( V_5 [ 2 ] == 0x00 )
V_3 -> V_23 = false ;
else
V_3 -> V_23 = true ;
F_9 ( & V_3 -> V_22 , V_14 ) ;
} else {
F_2 ( & V_3 -> V_18 -> V_19 ,
L_3
L_4 ,
V_5 [ 0 ] , V_5 [ 1 ] ) ;
}
}
} else {
F_2 ( & V_3 -> V_18 -> V_19 ,
L_5
L_6 , V_1 -> V_21 ) ;
}
exit:
F_10 ( & V_3 -> V_22 ) ;
if ( ! V_3 -> V_24 ) {
F_11 ( V_3 -> V_25 , V_3 -> V_18 ,
F_12 ( V_3 -> V_18 ,
V_3 -> V_26 ) ,
V_3 -> V_27 , V_3 -> V_28 ,
F_1 , V_3 ) ;
V_12 = F_13 ( V_3 -> V_25 , V_29 ) ;
if ( V_12 )
F_14 ( & V_8 -> V_19 ,
L_7 ,
V_20 , V_12 ) ;
} else
V_3 -> V_30 = true ;
F_15 ( & V_3 -> V_22 ) ;
}
static int F_16 ( struct V_7 * V_8 , T_1 V_31 ,
T_1 V_32 )
{
struct V_33 * V_34 = V_8 -> V_34 ;
int V_35 ;
T_1 * V_36 ;
V_36 = F_17 ( 1 , V_37 ) ;
if ( ! V_36 )
return - V_38 ;
V_36 [ 0 ] = V_32 ;
V_35 = F_18 ( V_34 -> V_19 , F_19 ( V_34 -> V_19 , 0 ) ,
V_31 ,
V_39 | V_40 | V_41 ,
0 , 0 , V_36 , 1 , 0 ) ;
F_20 ( V_36 ) ;
return V_35 ;
}
static int F_21 ( struct V_10 * V_11 , struct V_7 * V_8 )
{
struct V_2 * V_3 = F_22 ( V_8 -> V_34 ) ;
unsigned long V_14 ;
int V_12 = 0 ;
F_8 ( & V_3 -> V_22 , V_14 ) ;
V_3 -> V_24 = false ;
V_3 -> V_30 = false ;
V_3 -> V_8 = V_8 ;
V_3 -> V_42 = false ;
F_9 ( & V_3 -> V_22 , V_14 ) ;
F_16 ( V_8 , V_43 , 0 ) ;
F_11 ( V_3 -> V_25 , V_3 -> V_18 ,
F_12 ( V_3 -> V_18 ,
V_3 -> V_26 ) ,
V_3 -> V_27 , V_3 -> V_28 ,
F_1 , V_3 ) ;
F_23 ( V_3 -> V_18 , V_3 -> V_25 -> V_44 ) ;
V_12 = F_13 ( V_3 -> V_25 , V_37 ) ;
if ( V_12 )
F_14 ( & V_8 -> V_19 ,
L_7 ,
V_20 , V_12 ) ;
F_16 ( V_8 , V_45 , 1 ) ;
return V_12 ;
}
static void F_24 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_22 ( V_8 -> V_34 ) ;
F_25 ( V_3 -> V_25 ) ;
}
static void F_26 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
int V_9 = V_1 -> V_9 ;
unsigned long V_14 ;
F_20 ( V_1 -> V_6 ) ;
F_20 ( V_1 -> V_46 ) ;
if ( V_9 )
F_2 ( & V_3 -> V_18 -> V_19 , L_8 ,
V_20 , V_9 ) ;
F_8 ( & V_3 -> V_22 , V_14 ) ;
-- V_3 -> V_47 ;
F_9 ( & V_3 -> V_22 , V_14 ) ;
F_27 ( V_3 -> V_8 ) ;
}
static int F_28 ( struct V_10 * V_11 , struct V_7 * V_8 ,
const unsigned char * V_48 , int V_49 )
{
struct V_2 * V_3 = F_22 ( V_8 -> V_34 ) ;
struct V_33 * V_34 = V_8 -> V_34 ;
struct V_1 * V_1 ;
unsigned char * V_36 ;
unsigned long V_14 ;
int V_9 ;
struct V_50 * V_51 ;
F_8 ( & V_3 -> V_22 , V_14 ) ;
if ( V_3 -> V_47 > V_52 ) {
F_9 ( & V_3 -> V_22 , V_14 ) ;
F_2 ( & V_8 -> V_19 , L_9 , V_20 ) ;
return 0 ;
}
V_3 -> V_47 ++ ;
F_9 ( & V_3 -> V_22 , V_14 ) ;
V_36 = F_29 ( V_49 , V_29 ) ;
if ( ! V_36 ) {
F_14 ( & V_8 -> V_19 , L_10 ) ;
V_49 = - V_38 ;
goto V_53;
}
V_1 = F_30 ( 0 , V_29 ) ;
if ( ! V_1 ) {
F_14 ( & V_8 -> V_19 , L_11 ) ;
V_49 = - V_38 ;
goto V_54;
}
memcpy ( V_36 , V_48 , V_49 ) ;
F_3 ( & V_8 -> V_19 , V_20 , V_49 , V_36 ) ;
V_51 = F_29 ( sizeof( struct V_50 ) , V_55 ) ;
if ( ! V_51 ) {
F_14 ( & V_8 -> V_19 , L_10 ) ;
V_49 = - V_38 ;
goto V_56;
}
V_51 -> V_57 = V_40 | V_41 | V_39 ;
V_51 -> V_58 = 0x01 ;
V_51 -> V_59 = 0 ;
V_51 -> V_60 = 0 ;
V_51 -> V_61 = F_31 ( V_49 ) ;
F_32 ( V_1 , V_34 -> V_19 ,
F_19 ( V_34 -> V_19 , 0 ) ,
( unsigned char * ) V_51 , V_36 , V_49 ,
F_26 , V_3 ) ;
V_9 = F_13 ( V_1 , V_29 ) ;
if ( V_9 ) {
F_14 ( & V_8 -> V_19 ,
L_12 ,
V_20 , V_9 ) ;
V_49 = V_9 ;
goto error;
}
F_33 ( V_1 ) ;
return V_49 ;
error:
F_20 ( V_51 ) ;
V_56:
F_33 ( V_1 ) ;
V_54:
F_20 ( V_36 ) ;
V_53:
F_8 ( & V_3 -> V_22 , V_14 ) ;
-- V_3 -> V_47 ;
F_9 ( & V_3 -> V_22 , V_14 ) ;
return V_49 ;
}
static int F_34 ( struct V_10 * V_11 )
{
struct V_7 * V_8 = V_11 -> V_62 ;
struct V_2 * V_3 = F_22 ( V_8 -> V_34 ) ;
unsigned long V_14 ;
F_8 ( & V_3 -> V_22 , V_14 ) ;
if ( V_3 -> V_47 > V_52 * 2 / 3 ) {
F_9 ( & V_3 -> V_22 , V_14 ) ;
F_2 ( & V_8 -> V_19 , L_9 , V_20 ) ;
return 0 ;
}
F_9 ( & V_3 -> V_22 , V_14 ) ;
return 2048 ;
}
static void F_35 ( struct V_10 * V_11 )
{
struct V_7 * V_8 = V_11 -> V_62 ;
struct V_2 * V_3 = F_22 ( V_8 -> V_34 ) ;
unsigned long V_14 ;
F_8 ( & V_3 -> V_22 , V_14 ) ;
V_3 -> V_24 = true ;
F_9 ( & V_3 -> V_22 , V_14 ) ;
}
static void F_36 ( struct V_10 * V_11 )
{
struct V_7 * V_8 = V_11 -> V_62 ;
struct V_2 * V_3 = F_22 ( V_8 -> V_34 ) ;
unsigned long V_14 ;
int V_12 , V_63 ;
F_8 ( & V_3 -> V_22 , V_14 ) ;
V_3 -> V_24 = false ;
V_63 = V_3 -> V_30 ;
V_3 -> V_30 = false ;
F_9 ( & V_3 -> V_22 , V_14 ) ;
if ( V_63 ) {
V_12 = F_13 ( V_3 -> V_25 , V_29 ) ;
if ( V_12 )
F_14 ( & V_8 -> V_19 ,
L_13 ,
V_20 , V_12 ) ;
}
}
static int F_37 ( struct V_10 * V_11 )
{
struct V_7 * V_8 = V_11 -> V_62 ;
struct V_2 * V_3 = F_22 ( V_8 -> V_34 ) ;
unsigned long V_14 ;
int V_12 = 0 ;
F_8 ( & V_3 -> V_22 , V_14 ) ;
if ( V_3 -> V_42 )
V_12 |= V_64 ;
if ( V_3 -> V_23 )
V_12 |= V_65 ;
F_9 ( & V_3 -> V_22 , V_14 ) ;
F_2 ( & V_8 -> V_19 , L_14 , V_20 , V_12 ) ;
return V_12 ;
}
static int F_38 ( struct V_10 * V_11 ,
unsigned int V_66 , unsigned int V_67 )
{
struct V_7 * V_8 = V_11 -> V_62 ;
struct V_33 * V_34 = V_8 -> V_34 ;
struct V_2 * V_3 = F_22 ( V_8 -> V_34 ) ;
unsigned long V_14 ;
bool V_42 ;
bool V_68 = false ;
int V_69 ;
F_8 ( & V_3 -> V_22 , V_14 ) ;
V_42 = V_3 -> V_42 ;
if ( V_66 & V_64 )
V_3 -> V_42 = true ;
if ( V_67 & V_64 )
V_3 -> V_42 = false ;
V_68 = V_42 ^ V_3 -> V_42 ;
F_9 ( & V_3 -> V_22 , V_14 ) ;
if ( ! V_68 )
return 0 ;
F_39 ( & V_34 -> V_70 ) ;
if ( ! V_34 -> V_71 )
V_69 = F_16 ( V_8 , V_43 , ! V_42 ) ;
else
V_69 = - V_72 ;
F_40 ( & V_34 -> V_70 ) ;
return V_69 ;
}
static int F_41 ( struct V_2 * V_3 ,
struct V_73 T_2 * V_34 )
{
struct V_73 V_74 ;
if ( ! V_34 )
return - V_75 ;
memset ( & V_74 , 0x00 , sizeof( V_74 ) ) ;
V_74 . type = V_76 ;
V_74 . line = V_3 -> V_34 -> V_77 ;
V_74 . V_8 = 0 ;
V_74 . V_78 = 0 ;
V_74 . V_14 = V_79 | V_80 ;
V_74 . V_81 = 1024 ;
V_74 . V_82 = 9600 ;
V_74 . V_83 = 5 * V_84 ;
V_74 . V_85 = 30 * V_84 ;
if ( F_42 ( V_34 , & V_74 , sizeof( * V_34 ) ) )
return - V_75 ;
return 0 ;
}
static int F_43 ( struct V_10 * V_11 ,
unsigned int V_86 , unsigned long V_87 )
{
struct V_7 * V_8 = V_11 -> V_62 ;
struct V_2 * V_3 = F_22 ( V_8 -> V_34 ) ;
F_2 ( & V_8 -> V_19 , L_15 , V_20 , V_8 -> V_88 , V_86 ) ;
switch ( V_86 ) {
case V_89 :
return F_41 ( V_3 ,
(struct V_73 T_2 * ) V_87 ) ;
}
return - V_90 ;
}
static int F_44 ( struct V_33 * V_34 )
{
struct V_2 * V_3 ;
struct V_91 * V_92 ;
int V_93 ;
int V_35 = - V_38 ;
bool V_94 = false ;
V_3 = F_17 ( sizeof( * V_3 ) , V_37 ) ;
if ( V_3 == NULL ) {
F_14 ( & V_34 -> V_19 -> V_19 , L_16 , V_20 ) ;
return - V_38 ;
}
F_45 ( & V_3 -> V_22 ) ;
V_3 -> V_34 = V_34 ;
V_3 -> V_8 = V_34 -> V_8 [ 0 ] ;
V_3 -> V_18 = V_34 -> V_19 ;
V_3 -> V_47 = 0 ;
V_92 = V_34 -> V_95 -> V_96 ;
for ( V_93 = 0 ; V_93 < V_92 -> V_97 . V_98 ; ++ V_93 ) {
struct V_99 * V_100 ;
V_100 = & V_92 -> V_100 [ V_93 ] . V_97 ;
if ( ! F_46 ( V_100 ) )
continue;
V_3 -> V_25 = F_30 ( 0 , V_37 ) ;
if ( ! V_3 -> V_25 ) {
F_14 ( & V_3 -> V_18 -> V_19 , L_10 ) ;
goto error;
}
V_3 -> V_28 = F_47 ( V_100 ) * 2 ;
V_3 -> V_27 = F_29 ( V_3 -> V_28 , V_37 ) ;
if ( ! V_3 -> V_27 ) {
F_14 ( & V_3 -> V_18 -> V_19 , L_10 ) ;
goto error;
}
V_3 -> V_26 = V_100 -> V_101 ;
V_94 = true ;
break;
}
if ( ! V_94 ) {
F_14 ( & V_3 -> V_18 -> V_19 ,
L_17 ) ;
goto error;
}
F_48 ( V_34 , V_3 ) ;
return 0 ;
error:
F_33 ( V_3 -> V_25 ) ;
F_20 ( V_3 -> V_27 ) ;
F_20 ( V_3 ) ;
return V_35 ;
}
static void F_49 ( struct V_33 * V_34 )
{
struct V_2 * V_3 = F_22 ( V_34 ) ;
F_25 ( V_3 -> V_25 ) ;
F_33 ( V_3 -> V_25 ) ;
}
static void F_50 ( struct V_33 * V_34 )
{
struct V_2 * V_3 = F_22 ( V_34 ) ;
F_20 ( V_3 -> V_27 ) ;
F_20 ( V_3 ) ;
}
static int F_51 ( struct V_33 * V_34 , T_3 V_102 )
{
struct V_2 * V_3 = F_22 ( V_34 ) ;
F_25 ( V_3 -> V_25 ) ;
return 0 ;
}
static int F_52 ( struct V_33 * V_34 )
{
struct V_2 * V_3 = F_22 ( V_34 ) ;
struct V_7 * V_8 = V_34 -> V_8 [ 0 ] ;
int V_12 ;
F_39 ( & V_8 -> V_8 . V_103 ) ;
if ( F_53 ( V_104 , & V_8 -> V_8 . V_14 ) )
V_12 = F_13 ( V_3 -> V_25 , V_55 ) ;
else
V_12 = 0 ;
F_40 ( & V_8 -> V_8 . V_103 ) ;
return V_12 ;
}
