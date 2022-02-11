static void F_1 ( struct V_1 * V_2 ,
const unsigned char * V_3 , T_1 V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( & V_2 -> V_2 ) ;
if ( ! V_6 )
return;
F_3 ( V_6 , V_3 , V_4 ) ;
F_4 ( V_6 ) ;
F_5 ( V_6 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
const unsigned char * V_3 , T_1 V_4 )
{
struct V_7 * V_8 = F_7 ( V_2 ) ;
unsigned long V_9 ;
F_8 ( & V_8 -> V_10 , V_9 ) ;
if ( V_3 [ 0 ] == 0x00 )
V_8 -> V_11 = false ;
else
V_8 -> V_11 = true ;
F_9 ( & V_8 -> V_10 , V_9 ) ;
}
static void F_10 ( struct V_12 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_13 ;
const unsigned char * V_14 = V_12 -> V_15 ;
const unsigned char * V_16 = V_14 + 2 ;
T_1 V_17 = V_12 -> V_18 - 2 ;
if ( V_12 -> V_18 <= 2 ) {
F_11 ( & V_2 -> V_19 , L_1 ,
V_12 -> V_18 ) ;
return;
}
if ( ( V_14 [ 0 ] == 0x00 ) && ( V_14 [ 1 ] == 0x00 ) ) {
F_1 ( V_2 , V_16 , V_17 ) ;
} else if ( ( V_14 [ 0 ] == 0x00 ) && ( V_14 [ 1 ] == 0x01 ) ) {
F_6 ( V_2 , V_16 , V_17 ) ;
} else {
F_11 ( & V_2 -> V_19 , L_2 ,
V_14 [ 0 ] , V_14 [ 1 ] ) ;
}
}
static int F_12 ( struct V_1 * V_2 , T_2 V_20 ,
T_2 V_21 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_24 ;
T_2 * V_25 ;
V_25 = F_13 ( 1 , V_26 ) ;
if ( ! V_25 )
return - V_27 ;
V_25 [ 0 ] = V_21 ;
V_24 = F_14 ( V_23 -> V_19 , F_15 ( V_23 -> V_19 , 0 ) ,
V_20 ,
V_28 | V_29 | V_30 ,
0 , 0 , V_25 , 1 , 0 ) ;
F_16 ( V_25 ) ;
return V_24 ;
}
static int F_17 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
struct V_7 * V_8 = F_7 ( V_2 ) ;
unsigned long V_9 ;
int V_31 ;
F_8 ( & V_8 -> V_10 , V_9 ) ;
V_8 -> V_32 = false ;
F_9 ( & V_8 -> V_10 , V_9 ) ;
F_12 ( V_2 , V_33 , 0 ) ;
F_18 ( V_2 -> V_23 -> V_19 , V_2 -> V_34 -> V_35 ) ;
V_31 = F_19 ( V_6 , V_2 ) ;
if ( ! V_31 )
return V_31 ;
F_12 ( V_2 , V_36 , 1 ) ;
return V_31 ;
}
static void F_20 ( struct V_12 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_13 ;
struct V_7 * V_8 = F_7 ( V_2 ) ;
int V_37 = V_12 -> V_37 ;
unsigned long V_9 ;
F_16 ( V_12 -> V_15 ) ;
F_16 ( V_12 -> V_38 ) ;
if ( V_37 )
F_11 ( & V_2 -> V_19 ,
L_3 ,
V_39 , V_37 ) ;
F_8 ( & V_8 -> V_10 , V_9 ) ;
-- V_8 -> V_40 ;
F_9 ( & V_8 -> V_10 , V_9 ) ;
F_21 ( V_2 ) ;
}
static int F_22 ( struct V_5 * V_6 , struct V_1 * V_2 ,
const unsigned char * V_3 , int V_41 )
{
struct V_7 * V_8 = F_7 ( V_2 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
struct V_12 * V_12 ;
unsigned char * V_25 ;
unsigned long V_9 ;
int V_37 ;
struct V_42 * V_43 ;
F_8 ( & V_8 -> V_10 , V_9 ) ;
if ( V_8 -> V_40 > V_44 ) {
F_9 ( & V_8 -> V_10 , V_9 ) ;
F_11 ( & V_2 -> V_19 , L_4 , V_39 ) ;
return 0 ;
}
V_8 -> V_40 ++ ;
F_9 ( & V_8 -> V_10 , V_9 ) ;
V_25 = F_23 ( V_41 , V_45 ) ;
if ( ! V_25 ) {
F_24 ( & V_2 -> V_19 , L_5 ) ;
V_41 = - V_27 ;
goto V_46;
}
V_12 = F_25 ( 0 , V_45 ) ;
if ( ! V_12 ) {
F_24 ( & V_2 -> V_19 , L_6 ) ;
V_41 = - V_27 ;
goto V_47;
}
memcpy ( V_25 , V_3 , V_41 ) ;
F_26 ( & V_2 -> V_19 , V_39 , V_41 , V_25 ) ;
V_43 = F_23 ( sizeof( struct V_42 ) , V_48 ) ;
if ( ! V_43 ) {
F_24 ( & V_2 -> V_19 , L_5 ) ;
V_41 = - V_27 ;
goto V_49;
}
V_43 -> V_50 = V_29 | V_30 | V_28 ;
V_43 -> V_51 = 0x01 ;
V_43 -> V_52 = 0 ;
V_43 -> V_53 = 0 ;
V_43 -> V_54 = F_27 ( V_41 ) ;
F_28 ( V_12 , V_23 -> V_19 ,
F_15 ( V_23 -> V_19 , 0 ) ,
( unsigned char * ) V_43 , V_25 , V_41 ,
F_20 , V_2 ) ;
V_37 = F_29 ( V_12 , V_45 ) ;
if ( V_37 ) {
F_24 ( & V_2 -> V_19 ,
L_7 ,
V_39 , V_37 ) ;
V_41 = V_37 ;
goto error;
}
F_30 ( V_12 ) ;
return V_41 ;
error:
F_16 ( V_43 ) ;
V_49:
F_30 ( V_12 ) ;
V_47:
F_16 ( V_25 ) ;
V_46:
F_8 ( & V_8 -> V_10 , V_9 ) ;
-- V_8 -> V_40 ;
F_9 ( & V_8 -> V_10 , V_9 ) ;
return V_41 ;
}
static int F_31 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_55 ;
struct V_7 * V_8 = F_7 ( V_2 ) ;
unsigned long V_9 ;
F_8 ( & V_8 -> V_10 , V_9 ) ;
if ( V_8 -> V_40 > V_44 * 2 / 3 ) {
F_9 ( & V_8 -> V_10 , V_9 ) ;
F_11 ( & V_2 -> V_19 , L_4 , V_39 ) ;
return 0 ;
}
F_9 ( & V_8 -> V_10 , V_9 ) ;
return 2048 ;
}
static int F_32 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_55 ;
struct V_7 * V_8 = F_7 ( V_2 ) ;
unsigned long V_9 ;
int V_56 = 0 ;
F_8 ( & V_8 -> V_10 , V_9 ) ;
if ( V_8 -> V_32 )
V_56 |= V_57 ;
if ( V_8 -> V_11 )
V_56 |= V_58 ;
F_9 ( & V_8 -> V_10 , V_9 ) ;
F_11 ( & V_2 -> V_19 , L_8 , V_39 , V_56 ) ;
return V_56 ;
}
static int F_33 ( struct V_5 * V_6 ,
unsigned int V_59 , unsigned int V_60 )
{
struct V_1 * V_2 = V_6 -> V_55 ;
struct V_22 * V_23 = V_2 -> V_23 ;
struct V_7 * V_8 = F_7 ( V_2 ) ;
unsigned long V_9 ;
bool V_32 ;
bool V_61 = false ;
int V_62 ;
F_8 ( & V_8 -> V_10 , V_9 ) ;
V_32 = V_8 -> V_32 ;
if ( V_59 & V_57 )
V_8 -> V_32 = true ;
if ( V_60 & V_57 )
V_8 -> V_32 = false ;
V_61 = V_32 ^ V_8 -> V_32 ;
F_9 ( & V_8 -> V_10 , V_9 ) ;
if ( ! V_61 )
return 0 ;
F_34 ( & V_23 -> V_63 ) ;
if ( ! V_23 -> V_64 )
V_62 = F_12 ( V_2 , V_33 , ! V_32 ) ;
else
V_62 = - V_65 ;
F_35 ( & V_23 -> V_63 ) ;
return V_62 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_66 T_3 * V_23 )
{
struct V_66 V_67 ;
if ( ! V_23 )
return - V_68 ;
memset ( & V_67 , 0x00 , sizeof( V_67 ) ) ;
V_67 . type = V_69 ;
V_67 . line = V_2 -> V_23 -> V_70 ;
V_67 . V_2 = 0 ;
V_67 . V_71 = 0 ;
V_67 . V_9 = V_72 | V_73 ;
V_67 . V_74 = 1024 ;
V_67 . V_75 = 9600 ;
V_67 . V_76 = 5 * V_77 ;
V_67 . V_78 = 30 * V_77 ;
if ( F_37 ( V_23 , & V_67 , sizeof( * V_23 ) ) )
return - V_68 ;
return 0 ;
}
static int F_38 ( struct V_5 * V_6 ,
unsigned int V_79 , unsigned long V_80 )
{
struct V_1 * V_2 = V_6 -> V_55 ;
F_11 ( & V_2 -> V_19 , L_9 , V_39 , V_2 -> V_81 , V_79 ) ;
switch ( V_79 ) {
case V_82 :
return F_36 ( V_2 ,
(struct V_66 T_3 * ) V_80 ) ;
}
return - V_83 ;
}
static int F_39 ( struct V_22 * V_23 )
{
if ( ! V_23 -> V_84 ) {
F_24 ( & V_23 -> V_19 -> V_19 , L_10 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
V_8 = F_13 ( sizeof( * V_8 ) , V_26 ) ;
if ( ! V_8 )
return - V_27 ;
F_41 ( & V_8 -> V_10 ) ;
F_42 ( V_2 , V_8 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_7 ( V_2 ) ;
F_16 ( V_8 ) ;
return 0 ;
}
