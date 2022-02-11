static void F_1 ( struct V_1 * V_2 ,
const unsigned char * V_3 , T_1 V_4 )
{
F_2 ( & V_2 -> V_2 , V_3 , V_4 ) ;
F_3 ( & V_2 -> V_2 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
const unsigned char * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
unsigned long V_7 ;
F_6 ( & V_6 -> V_8 , V_7 ) ;
if ( V_3 [ 0 ] == 0x00 )
V_6 -> V_9 = false ;
else
V_6 -> V_9 = true ;
F_7 ( & V_6 -> V_8 , V_7 ) ;
}
static void F_8 ( struct V_10 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_11 ;
const unsigned char * V_12 = V_10 -> V_13 ;
const unsigned char * V_14 = V_12 + 2 ;
T_1 V_15 = V_10 -> V_16 - 2 ;
if ( V_10 -> V_16 <= 2 ) {
F_9 ( & V_2 -> V_17 , L_1 ,
V_10 -> V_16 ) ;
return;
}
if ( ( V_12 [ 0 ] == 0x00 ) && ( V_12 [ 1 ] == 0x00 ) ) {
F_1 ( V_2 , V_14 , V_15 ) ;
} else if ( ( V_12 [ 0 ] == 0x00 ) && ( V_12 [ 1 ] == 0x01 ) ) {
F_4 ( V_2 , V_14 , V_15 ) ;
} else {
F_9 ( & V_2 -> V_17 , L_2 ,
V_12 [ 0 ] , V_12 [ 1 ] ) ;
}
}
static int F_10 ( struct V_1 * V_2 , T_2 V_18 ,
T_2 V_19 )
{
struct V_20 * V_21 = V_2 -> V_21 ;
int V_22 ;
T_2 * V_23 ;
V_23 = F_11 ( 1 , V_24 ) ;
if ( ! V_23 )
return - V_25 ;
V_23 [ 0 ] = V_19 ;
V_22 = F_12 ( V_21 -> V_17 , F_13 ( V_21 -> V_17 , 0 ) ,
V_18 ,
V_26 | V_27 | V_28 ,
0 , 0 , V_23 , 1 , 0 ) ;
F_14 ( V_23 ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
}
static int F_15 ( struct V_29 * V_30 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
unsigned long V_7 ;
int V_31 ;
F_6 ( & V_6 -> V_8 , V_7 ) ;
V_6 -> V_32 = false ;
F_7 ( & V_6 -> V_8 , V_7 ) ;
F_10 ( V_2 , V_33 , 0 ) ;
F_16 ( V_2 -> V_21 -> V_17 , V_2 -> V_34 -> V_35 ) ;
V_31 = F_17 ( V_30 , V_2 ) ;
if ( ! V_31 )
return V_31 ;
F_10 ( V_2 , V_36 , 1 ) ;
return V_31 ;
}
static void F_18 ( struct V_10 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_11 ;
struct V_5 * V_6 = F_5 ( V_2 ) ;
int V_37 = V_10 -> V_37 ;
unsigned long V_7 ;
F_14 ( V_10 -> V_13 ) ;
F_14 ( V_10 -> V_38 ) ;
if ( V_37 )
F_9 ( & V_2 -> V_17 ,
L_3 ,
V_39 , V_37 ) ;
F_6 ( & V_6 -> V_8 , V_7 ) ;
-- V_6 -> V_40 ;
F_7 ( & V_6 -> V_8 , V_7 ) ;
F_19 ( V_2 ) ;
}
static int F_20 ( struct V_29 * V_30 , struct V_1 * V_2 ,
const unsigned char * V_3 , int V_41 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
struct V_20 * V_21 = V_2 -> V_21 ;
struct V_10 * V_10 ;
unsigned char * V_23 ;
unsigned long V_7 ;
int V_37 ;
struct V_42 * V_43 ;
F_6 ( & V_6 -> V_8 , V_7 ) ;
if ( V_6 -> V_40 > V_44 ) {
F_7 ( & V_6 -> V_8 , V_7 ) ;
F_9 ( & V_2 -> V_17 , L_4 , V_39 ) ;
return 0 ;
}
V_6 -> V_40 ++ ;
F_7 ( & V_6 -> V_8 , V_7 ) ;
V_23 = F_21 ( V_41 , V_45 ) ;
if ( ! V_23 ) {
V_41 = - V_25 ;
goto V_46;
}
V_10 = F_22 ( 0 , V_45 ) ;
if ( ! V_10 ) {
V_41 = - V_25 ;
goto V_47;
}
memcpy ( V_23 , V_3 , V_41 ) ;
F_23 ( & V_2 -> V_17 , V_39 , V_41 , V_23 ) ;
V_43 = F_21 ( sizeof( struct V_42 ) , V_48 ) ;
if ( ! V_43 ) {
V_41 = - V_25 ;
goto V_49;
}
V_43 -> V_50 = V_27 | V_28 | V_26 ;
V_43 -> V_51 = 0x01 ;
V_43 -> V_52 = 0 ;
V_43 -> V_53 = 0 ;
V_43 -> V_54 = F_24 ( V_41 ) ;
F_25 ( V_10 , V_21 -> V_17 ,
F_13 ( V_21 -> V_17 , 0 ) ,
( unsigned char * ) V_43 , V_23 , V_41 ,
F_18 , V_2 ) ;
V_37 = F_26 ( V_10 , V_45 ) ;
if ( V_37 ) {
F_27 ( & V_2 -> V_17 ,
L_5 ,
V_39 , V_37 ) ;
V_41 = V_37 ;
goto error;
}
F_28 ( V_10 ) ;
return V_41 ;
error:
F_14 ( V_43 ) ;
V_49:
F_28 ( V_10 ) ;
V_47:
F_14 ( V_23 ) ;
V_46:
F_6 ( & V_6 -> V_8 , V_7 ) ;
-- V_6 -> V_40 ;
F_7 ( & V_6 -> V_8 , V_7 ) ;
return V_41 ;
}
static int F_29 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_55 ;
struct V_5 * V_6 = F_5 ( V_2 ) ;
unsigned long V_7 ;
F_6 ( & V_6 -> V_8 , V_7 ) ;
if ( V_6 -> V_40 > V_44 * 2 / 3 ) {
F_7 ( & V_6 -> V_8 , V_7 ) ;
F_9 ( & V_2 -> V_17 , L_4 , V_39 ) ;
return 0 ;
}
F_7 ( & V_6 -> V_8 , V_7 ) ;
return 2048 ;
}
static int F_30 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_55 ;
struct V_5 * V_6 = F_5 ( V_2 ) ;
unsigned long V_7 ;
int V_56 = 0 ;
F_6 ( & V_6 -> V_8 , V_7 ) ;
if ( V_6 -> V_32 )
V_56 |= V_57 ;
if ( V_6 -> V_9 )
V_56 |= V_58 ;
F_7 ( & V_6 -> V_8 , V_7 ) ;
F_9 ( & V_2 -> V_17 , L_6 , V_39 , V_56 ) ;
return V_56 ;
}
static int F_31 ( struct V_29 * V_30 ,
unsigned int V_59 , unsigned int V_60 )
{
struct V_1 * V_2 = V_30 -> V_55 ;
struct V_5 * V_6 = F_5 ( V_2 ) ;
unsigned long V_7 ;
bool V_32 ;
bool V_61 = false ;
int V_62 ;
F_6 ( & V_6 -> V_8 , V_7 ) ;
V_32 = V_6 -> V_32 ;
if ( V_59 & V_57 )
V_6 -> V_32 = true ;
if ( V_60 & V_57 )
V_6 -> V_32 = false ;
V_61 = V_32 ^ V_6 -> V_32 ;
F_7 ( & V_6 -> V_8 , V_7 ) ;
if ( ! V_61 )
return 0 ;
V_62 = F_10 ( V_2 , V_33 , ! V_32 ) ;
if ( V_62 )
return F_32 ( V_62 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_63 T_3 * V_21 )
{
struct V_63 V_64 ;
if ( ! V_21 )
return - V_65 ;
memset ( & V_64 , 0x00 , sizeof( V_64 ) ) ;
V_64 . type = V_66 ;
V_64 . line = V_2 -> V_67 ;
V_64 . V_2 = 0 ;
V_64 . V_68 = 0 ;
V_64 . V_7 = V_69 | V_70 ;
V_64 . V_71 = 1024 ;
V_64 . V_72 = 9600 ;
V_64 . V_73 = 5 * V_74 ;
V_64 . V_75 = 30 * V_74 ;
if ( F_34 ( V_21 , & V_64 , sizeof( * V_21 ) ) )
return - V_65 ;
return 0 ;
}
static int F_35 ( struct V_29 * V_30 ,
unsigned int V_76 , unsigned long V_77 )
{
struct V_1 * V_2 = V_30 -> V_55 ;
switch ( V_76 ) {
case V_78 :
return F_33 ( V_2 ,
(struct V_63 T_3 * ) V_77 ) ;
}
return - V_79 ;
}
static int F_36 ( struct V_20 * V_21 )
{
if ( ! V_21 -> V_80 ) {
F_27 ( & V_21 -> V_17 -> V_17 , L_7 ) ;
return - V_81 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_11 ( sizeof( * V_6 ) , V_24 ) ;
if ( ! V_6 )
return - V_25 ;
F_38 ( & V_6 -> V_8 ) ;
F_39 ( V_2 , V_6 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
F_14 ( V_6 ) ;
return 0 ;
}
