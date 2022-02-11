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
F_2 ( L_1 ,
V_18 , V_9 ) ;
return;
default:
F_2 ( L_2 ,
V_18 , V_9 ) ;
goto exit;
}
F_3 ( V_19 , & V_8 -> V_20 , V_18 , V_1 -> V_21 ,
V_5 ) ;
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
F_10 ( & V_3 -> V_24 -> V_20 ,
L_3
L_4 ,
V_5 [ 0 ] , V_5 [ 1 ] ) ;
}
}
} else {
F_10 ( & V_3 -> V_24 -> V_20 ,
L_5
L_6 , V_1 -> V_21 ) ;
}
exit:
F_11 ( & V_3 -> V_22 ) ;
if ( ! V_3 -> V_25 ) {
F_12 ( V_3 -> V_26 , V_3 -> V_24 ,
F_13 ( V_3 -> V_24 ,
V_3 -> V_27 ) ,
V_3 -> V_28 , V_3 -> V_29 ,
F_1 , V_3 ) ;
V_12 = F_14 ( V_3 -> V_26 , V_30 ) ;
if ( V_12 )
F_15 ( & V_8 -> V_20 ,
L_7 ,
V_18 , V_12 ) ;
} else
V_3 -> V_31 = true ;
F_16 ( & V_3 -> V_22 ) ;
}
static int F_17 ( struct V_7 * V_8 , T_1 V_32 ,
T_1 V_33 )
{
struct V_34 * V_35 = V_8 -> V_35 ;
int V_36 ;
T_1 V_37 [ 2 ] ;
V_37 [ 0 ] = V_33 ;
V_36 = F_18 ( V_35 -> V_20 , F_19 ( V_35 -> V_20 , 0 ) ,
V_32 ,
V_38 | V_39 | V_40 ,
0 , 0 , V_37 , 1 , 0 ) ;
return V_36 ;
}
static int F_20 ( struct V_10 * V_11 , struct V_7 * V_8 )
{
struct V_2 * V_3 = F_21 ( V_8 -> V_35 ) ;
unsigned long V_14 ;
int V_12 = 0 ;
F_8 ( & V_3 -> V_22 , V_14 ) ;
V_3 -> V_25 = false ;
V_3 -> V_31 = false ;
V_3 -> V_8 = V_8 ;
V_3 -> V_41 = false ;
F_9 ( & V_3 -> V_22 , V_14 ) ;
F_17 ( V_8 , V_42 , 0 ) ;
F_12 ( V_3 -> V_26 , V_3 -> V_24 ,
F_13 ( V_3 -> V_24 ,
V_3 -> V_27 ) ,
V_3 -> V_28 , V_3 -> V_29 ,
F_1 , V_3 ) ;
F_22 ( V_3 -> V_24 , V_3 -> V_26 -> V_43 ) ;
V_12 = F_14 ( V_3 -> V_26 , V_44 ) ;
if ( V_12 )
F_15 ( & V_8 -> V_20 ,
L_7 ,
V_18 , V_12 ) ;
F_17 ( V_8 , V_45 , 1 ) ;
return V_12 ;
}
static void F_23 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_21 ( V_8 -> V_35 ) ;
F_24 ( V_3 -> V_26 ) ;
}
static void F_25 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
int V_9 = V_1 -> V_9 ;
unsigned long V_14 ;
F_26 ( V_1 -> V_6 ) ;
F_26 ( V_1 -> V_46 ) ;
if ( V_9 )
F_2 ( L_8 ,
V_18 , V_9 ) ;
F_8 ( & V_3 -> V_22 , V_14 ) ;
-- V_3 -> V_47 ;
F_9 ( & V_3 -> V_22 , V_14 ) ;
F_27 ( V_3 -> V_8 ) ;
}
static int F_28 ( struct V_10 * V_11 , struct V_7 * V_8 ,
const unsigned char * V_48 , int V_49 )
{
struct V_2 * V_3 = F_21 ( V_8 -> V_35 ) ;
struct V_34 * V_35 = V_8 -> V_35 ;
struct V_1 * V_1 ;
unsigned char * V_37 ;
unsigned long V_14 ;
int V_9 ;
struct V_50 * V_51 ;
F_8 ( & V_3 -> V_22 , V_14 ) ;
if ( V_3 -> V_47 > V_52 ) {
F_9 ( & V_3 -> V_22 , V_14 ) ;
F_2 ( L_9 , V_18 ) ;
return 0 ;
}
V_3 -> V_47 ++ ;
F_9 ( & V_3 -> V_22 , V_14 ) ;
V_37 = F_29 ( V_49 , V_30 ) ;
if ( ! V_37 ) {
F_15 ( & V_8 -> V_20 , L_10 ) ;
V_49 = - V_53 ;
goto V_54;
}
V_1 = F_30 ( 0 , V_30 ) ;
if ( ! V_1 ) {
F_15 ( & V_8 -> V_20 , L_11 ) ;
V_49 = - V_53 ;
goto V_55;
}
memcpy ( V_37 , V_48 , V_49 ) ;
F_3 ( V_19 , & V_8 -> V_20 , V_18 , V_49 , V_37 ) ;
V_51 = F_29 ( sizeof( struct V_50 ) , V_56 ) ;
if ( ! V_51 ) {
F_15 ( & V_8 -> V_20 , L_10 ) ;
V_49 = - V_53 ;
goto error;
}
V_51 -> V_57 = V_39 | V_40 | V_38 ;
V_51 -> V_58 = 0x01 ;
V_51 -> V_59 = 0 ;
V_51 -> V_60 = 0 ;
V_51 -> V_61 = F_31 ( V_49 ) ;
F_32 ( V_1 , V_35 -> V_20 ,
F_19 ( V_35 -> V_20 , 0 ) ,
( unsigned char * ) V_51 , V_37 , V_49 ,
F_25 , V_3 ) ;
V_9 = F_14 ( V_1 , V_30 ) ;
if ( V_9 ) {
F_15 ( & V_8 -> V_20 ,
L_12 ,
V_18 , V_9 ) ;
V_49 = V_9 ;
goto error;
}
F_33 ( V_1 ) ;
return V_49 ;
error:
F_33 ( V_1 ) ;
V_55:
F_26 ( V_37 ) ;
V_54:
F_8 ( & V_3 -> V_22 , V_14 ) ;
-- V_3 -> V_47 ;
F_9 ( & V_3 -> V_22 , V_14 ) ;
return V_49 ;
}
static int F_34 ( struct V_10 * V_11 )
{
struct V_7 * V_8 = V_11 -> V_62 ;
struct V_2 * V_3 = F_21 ( V_8 -> V_35 ) ;
unsigned long V_14 ;
F_8 ( & V_3 -> V_22 , V_14 ) ;
if ( V_3 -> V_47 > V_52 * 2 / 3 ) {
F_9 ( & V_3 -> V_22 , V_14 ) ;
F_2 ( L_9 , V_18 ) ;
return 0 ;
}
F_9 ( & V_3 -> V_22 , V_14 ) ;
return 2048 ;
}
static void F_35 ( struct V_10 * V_11 )
{
struct V_7 * V_8 = V_11 -> V_62 ;
struct V_2 * V_3 = F_21 ( V_8 -> V_35 ) ;
unsigned long V_14 ;
F_8 ( & V_3 -> V_22 , V_14 ) ;
V_3 -> V_25 = true ;
F_9 ( & V_3 -> V_22 , V_14 ) ;
}
static void F_36 ( struct V_10 * V_11 )
{
struct V_7 * V_8 = V_11 -> V_62 ;
struct V_2 * V_3 = F_21 ( V_8 -> V_35 ) ;
unsigned long V_14 ;
int V_12 , V_63 ;
F_8 ( & V_3 -> V_22 , V_14 ) ;
V_3 -> V_25 = false ;
V_63 = V_3 -> V_31 ;
V_3 -> V_31 = false ;
F_9 ( & V_3 -> V_22 , V_14 ) ;
if ( V_63 ) {
V_12 = F_14 ( V_3 -> V_26 , V_30 ) ;
if ( V_12 )
F_15 ( & V_8 -> V_20 ,
L_13 ,
V_18 , V_12 ) ;
}
}
static int F_37 ( struct V_10 * V_11 )
{
struct V_7 * V_8 = V_11 -> V_62 ;
struct V_2 * V_3 = F_21 ( V_8 -> V_35 ) ;
unsigned long V_14 ;
int V_12 = 0 ;
F_8 ( & V_3 -> V_22 , V_14 ) ;
if ( V_3 -> V_41 )
V_12 |= V_64 ;
if ( V_3 -> V_23 )
V_12 |= V_65 ;
F_9 ( & V_3 -> V_22 , V_14 ) ;
F_2 ( L_14 , V_18 , V_12 ) ;
return V_12 ;
}
static int F_38 ( struct V_10 * V_11 ,
unsigned int V_66 , unsigned int V_67 )
{
struct V_7 * V_8 = V_11 -> V_62 ;
struct V_34 * V_35 = V_8 -> V_35 ;
struct V_2 * V_3 = F_21 ( V_8 -> V_35 ) ;
unsigned long V_14 ;
bool V_41 ;
bool V_68 = false ;
int V_69 ;
F_8 ( & V_3 -> V_22 , V_14 ) ;
V_41 = V_3 -> V_41 ;
if ( V_66 & V_64 )
V_3 -> V_41 = true ;
if ( V_67 & V_64 )
V_3 -> V_41 = false ;
V_68 = V_41 ^ V_3 -> V_41 ;
F_9 ( & V_3 -> V_22 , V_14 ) ;
if ( ! V_68 )
return 0 ;
F_39 ( & V_35 -> V_70 ) ;
if ( ! V_35 -> V_71 )
V_69 = F_17 ( V_8 , V_42 , ! V_41 ) ;
else
V_69 = - V_72 ;
F_40 ( & V_35 -> V_70 ) ;
return V_69 ;
}
static int F_41 ( struct V_2 * V_3 ,
struct V_73 T_2 * V_35 )
{
struct V_73 V_74 ;
if ( ! V_35 )
return - V_75 ;
memset ( & V_74 , 0x00 , sizeof( V_74 ) ) ;
V_74 . type = V_76 ;
V_74 . line = V_3 -> V_35 -> V_77 ;
V_74 . V_8 = 0 ;
V_74 . V_78 = 0 ;
V_74 . V_14 = V_79 | V_80 ;
V_74 . V_81 = 1024 ;
V_74 . V_82 = 9600 ;
V_74 . V_83 = 5 * V_84 ;
V_74 . V_85 = 30 * V_84 ;
if ( F_42 ( V_35 , & V_74 , sizeof( * V_35 ) ) )
return - V_75 ;
return 0 ;
}
static int F_43 ( struct V_10 * V_11 ,
unsigned int V_86 , unsigned long V_87 )
{
struct V_7 * V_8 = V_11 -> V_62 ;
struct V_2 * V_3 = F_21 ( V_8 -> V_35 ) ;
F_2 ( L_15 , V_18 , V_8 -> V_88 , V_86 ) ;
switch ( V_86 ) {
case V_89 :
return F_41 ( V_3 ,
(struct V_73 T_2 * ) V_87 ) ;
}
return - V_90 ;
}
static int F_44 ( struct V_34 * V_35 )
{
struct V_2 * V_3 ;
struct V_91 * V_92 ;
int V_93 ;
int V_36 = - V_53 ;
bool V_94 = false ;
V_3 = F_45 ( sizeof( * V_3 ) , V_44 ) ;
if ( V_3 == NULL ) {
F_15 ( & V_35 -> V_20 -> V_20 , L_16 , V_18 ) ;
return - V_53 ;
}
F_46 ( & V_3 -> V_22 ) ;
V_3 -> V_35 = V_35 ;
V_3 -> V_8 = V_35 -> V_8 [ 0 ] ;
V_3 -> V_24 = V_35 -> V_20 ;
V_3 -> V_47 = 0 ;
V_92 = V_35 -> V_95 -> V_96 ;
for ( V_93 = 0 ; V_93 < V_92 -> V_97 . V_98 ; ++ V_93 ) {
struct V_99 * V_100 ;
V_100 = & V_92 -> V_100 [ V_93 ] . V_97 ;
if ( ! F_47 ( V_100 ) )
continue;
V_3 -> V_26 = F_30 ( 0 , V_44 ) ;
if ( ! V_3 -> V_26 ) {
F_15 ( & V_3 -> V_24 -> V_20 , L_10 ) ;
goto error;
}
V_3 -> V_29 = F_48 ( V_100 ) * 2 ;
V_3 -> V_28 = F_29 ( V_3 -> V_29 , V_44 ) ;
if ( ! V_3 -> V_28 ) {
F_15 ( & V_3 -> V_24 -> V_20 , L_10 ) ;
goto error;
}
V_3 -> V_27 = V_100 -> V_101 ;
V_94 = true ;
break;
}
if ( ! V_94 ) {
F_15 ( & V_3 -> V_24 -> V_20 ,
L_17 ) ;
goto error;
}
F_49 ( V_35 , V_3 ) ;
return 0 ;
error:
F_33 ( V_3 -> V_26 ) ;
F_26 ( V_3 -> V_28 ) ;
F_26 ( V_3 ) ;
return V_36 ;
}
static void F_50 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = F_21 ( V_35 ) ;
F_24 ( V_3 -> V_26 ) ;
F_33 ( V_3 -> V_26 ) ;
}
static void F_51 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = F_21 ( V_35 ) ;
F_26 ( V_3 -> V_28 ) ;
F_26 ( V_3 ) ;
}
static int F_52 ( struct V_34 * V_35 , T_3 V_102 )
{
struct V_2 * V_3 = F_21 ( V_35 ) ;
F_24 ( V_3 -> V_26 ) ;
return 0 ;
}
static int F_53 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = F_21 ( V_35 ) ;
struct V_7 * V_8 = V_35 -> V_8 [ 0 ] ;
int V_12 ;
F_39 ( & V_8 -> V_8 . V_103 ) ;
if ( F_54 ( V_104 , & V_8 -> V_8 . V_14 ) )
V_12 = F_14 ( V_3 -> V_26 , V_56 ) ;
else
V_12 = 0 ;
F_40 ( & V_8 -> V_8 . V_103 ) ;
return V_12 ;
}
