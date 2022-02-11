static inline int F_1 ( int V_1 , int V_2 )
{
F_2 ( V_2 , V_1 ) ;
return F_3 ( V_1 + 1 ) ;
}
static inline int F_4 ( int V_1 )
{
if ( ! F_5 ( V_1 , 2 , L_1 ) ) {
F_6 ( L_2 , V_1 ) ;
return - V_3 ;
}
F_2 ( V_4 , V_1 ) ;
return 0 ;
}
static inline void F_7 ( int V_1 , int V_5 )
{
F_2 ( V_6 , V_1 ) ;
F_2 ( V_5 , V_1 + 1 ) ;
}
static inline void F_8 ( int V_1 )
{
F_2 ( V_7 , V_1 ) ;
F_9 ( V_1 , 2 ) ;
}
static int F_10 ( T_1 V_8 , T_2 V_9 , T_1 V_2 , T_2 V_10 )
{
T_2 V_11 ;
int V_12 ;
const int V_13 = 64 ;
const int V_14 = 32 ;
V_11 = F_3 ( V_8 + 1 ) ;
F_2 ( V_11 , V_8 + 1 ) ;
F_2 ( 0x00 , V_8 + 2 ) ;
F_2 ( 0x80 , V_8 + 3 ) ;
F_2 ( V_9 , V_8 + 4 ) ;
F_2 ( 0x01 , V_8 + 5 ) ;
F_2 ( 0x04 , V_8 + 2 ) ;
if ( V_9 == V_15 )
F_2 ( V_10 , V_8 + 4 ) ;
F_2 ( V_2 & 0xff , V_8 + 6 ) ;
F_2 ( V_2 >> 8 , V_8 + 7 ) ;
F_2 ( 0x01 , V_8 ) ;
for ( V_12 = 0 ; V_12 < V_13 + V_14 ; V_12 ++ ) {
if ( V_12 >= V_13 )
F_11 ( 1 ) ;
V_11 = F_3 ( V_8 + 8 ) ;
if ( V_11 )
F_2 ( V_11 , V_8 + 8 ) ;
if ( V_11 & 0x01 )
break;
}
if ( V_12 == V_13 + V_14 ) {
F_6 ( L_3
L_4 , V_2 , 1 ) ;
return - V_16 ;
}
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ ) {
V_11 = F_3 ( V_8 + 1 ) ;
if ( V_11 == 0x01 )
break;
if ( V_12 == 0 )
F_12 ( L_5
L_6 , ( unsigned int ) V_11 , V_2 ) ;
}
if ( V_12 == V_13 ) {
F_6 ( L_3
L_4 , V_2 , 2 ) ;
return - V_16 ;
}
if ( V_9 == V_17 )
return F_3 ( V_8 + 4 ) ;
return 0 ;
}
int F_13 ( T_1 V_8 , T_1 V_2 )
{
return F_10 ( V_8 , V_17 , V_2 , 0 ) ;
}
int F_14 ( T_1 V_8 , T_1 V_2 , T_2 V_11 )
{
return F_10 ( V_8 , V_15 , V_2 , V_11 ) ;
}
int F_15 ( T_1 V_8 , T_1 V_2 )
{
int V_18 , V_19 ;
V_18 = F_13 ( V_8 , V_2 ) ;
if ( V_18 < 0 )
return V_18 ;
V_19 = F_13 ( V_8 , V_2 + 1 ) ;
if ( V_19 < 0 )
return V_19 ;
return V_18 | ( V_19 << 8 ) ;
}
int F_16 ( T_1 V_8 , T_1 V_20 , T_1 V_21 ,
int V_22 )
{
int V_19 , V_23 ;
V_19 = F_13 ( V_8 , V_20 ) ;
if ( V_19 < 0 )
return V_19 ;
V_23 = F_13 ( V_8 , V_21 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_22 )
return ( V_19 << 4 ) | ( V_23 >> 4 ) ;
else
return ( V_19 << 4 ) | ( V_23 & 0x0f ) ;
}
static void F_17 ( struct V_24 * V_25 )
{
struct V_26 * V_27 =
F_18 ( V_25 , struct V_26 , V_24 ) ;
F_19 ( V_27 ) ;
}
static int F_20 ( struct V_28 * V_29 ,
unsigned int V_30 )
{
struct V_26 * V_27 = F_21 ( V_29 ) ;
unsigned int V_31 ;
T_2 V_32 ;
int V_33 ;
if ( V_30 <= 255 )
V_31 = 1 ;
else
V_31 = 60 ;
if ( V_30 < V_31 || V_30 > ( V_31 * 255 ) )
return - V_34 ;
if ( V_31 == 1 )
V_32 = V_27 -> V_35 | V_36 ;
else
V_32 = V_27 -> V_35 & ~ V_36 ;
if ( V_27 -> V_35 != V_32 ) {
F_22 ( V_27 -> V_37 ) ;
V_33 = F_14 ( V_27 -> V_8 ,
V_38 ,
V_32 ) ;
F_23 ( V_27 -> V_37 ) ;
if ( V_33 )
return V_33 ;
V_27 -> V_35 = V_32 ;
}
V_27 -> V_39 = F_24 ( V_30 , V_31 ) ;
V_29 -> V_30 = V_27 -> V_39 * V_31 ;
return 0 ;
}
static int F_25 ( struct V_28 * V_29 )
{
struct V_26 * V_27 = F_21 ( V_29 ) ;
int V_33 ;
T_2 V_11 ;
F_22 ( V_27 -> V_37 ) ;
V_33 = F_14 ( V_27 -> V_8 , V_40 ,
V_27 -> V_39 ) ;
if ( V_33 )
goto V_41;
V_11 = V_27 -> V_42 | V_43 ;
V_33 = F_14 ( V_27 -> V_8 ,
V_44 , V_11 ) ;
if ( V_33 )
goto V_41;
V_27 -> V_42 = V_11 ;
V_11 = F_3 ( V_27 -> V_8 + 9 ) ;
if ( V_11 & 0x01 )
F_2 ( 0x01 , V_27 -> V_8 + 9 ) ;
V_41:
F_23 ( V_27 -> V_37 ) ;
return V_33 ;
}
static int F_26 ( struct V_28 * V_29 )
{
struct V_26 * V_27 = F_21 ( V_29 ) ;
int V_33 ;
F_22 ( V_27 -> V_37 ) ;
V_33 = F_14 ( V_27 -> V_8 , V_40 ,
V_27 -> V_39 ) ;
F_23 ( V_27 -> V_37 ) ;
return V_33 ;
}
static int F_27 ( struct V_28 * V_29 )
{
struct V_26 * V_27 = F_21 ( V_29 ) ;
int V_33 = 0 ;
T_2 V_11 ;
V_11 = V_27 -> V_42 & ~ V_43 ;
F_22 ( V_27 -> V_37 ) ;
V_33 = F_14 ( V_27 -> V_8 ,
V_44 , V_11 ) ;
F_23 ( V_27 -> V_37 ) ;
if ( V_33 )
return V_33 ;
V_27 -> V_42 = V_11 ;
return 0 ;
}
static void F_28 ( struct V_28 * V_29 )
{
struct V_26 * V_27 = F_21 ( V_29 ) ;
F_29 ( & V_27 -> V_24 ) ;
}
static void F_30 ( struct V_28 * V_29 )
{
struct V_26 * V_27 = F_21 ( V_29 ) ;
F_31 ( & V_27 -> V_24 , F_17 ) ;
}
struct V_26 * F_32 ( struct V_45 * V_46 ,
T_1 V_8 , T_3 V_47 , struct V_48 * V_37 , int V_49 )
{
struct V_26 * V_27 ;
int V_50 , V_32 , V_51 ;
F_22 ( V_37 ) ;
V_32 =
F_13 ( V_8 , V_38 ) ;
V_51 =
F_13 ( V_8 , V_44 ) ;
F_23 ( V_37 ) ;
if ( V_32 < 0 )
return NULL ;
if ( V_51 < 0 )
return NULL ;
if ( V_49 && ! ( V_51 & V_43 ) ) {
F_12 ( L_7 ) ;
return NULL ;
}
V_27 = F_33 ( sizeof( struct V_26 ) , V_52 ) ;
if ( ! V_27 )
return NULL ;
V_27 -> V_8 = V_8 ;
V_27 -> V_37 = V_37 ;
F_34 ( & V_27 -> V_24 ) ;
F_35 ( V_27 -> V_53 . V_54 , L_8 ,
sizeof( V_27 -> V_53 . V_54 ) ) ;
V_27 -> V_53 . V_55 = V_47 ;
V_27 -> V_53 . V_56 = V_57 | V_58 ;
if ( ! V_59 )
V_27 -> V_53 . V_56 |= V_60 ;
V_27 -> V_29 . V_61 = & V_27 -> V_53 ;
V_27 -> V_29 . V_62 = & V_63 ;
V_27 -> V_29 . V_46 = V_46 ;
V_27 -> V_29 . V_30 = 60 ;
V_27 -> V_29 . V_64 = 1 ;
V_27 -> V_29 . V_65 = 255 * 60 ;
if ( V_59 )
F_36 ( V_66 , & V_27 -> V_29 . V_67 ) ;
if ( V_51 & V_43 )
F_36 ( V_68 , & V_27 -> V_29 . V_67 ) ;
if ( V_32 & V_36 )
V_27 -> V_39 = 60 ;
else
V_27 -> V_39 = 1 ;
V_27 -> V_35 = V_32 ;
V_27 -> V_42 = V_51 ;
F_37 ( & V_27 -> V_29 , V_27 ) ;
V_50 = F_38 ( & V_27 -> V_29 ) ;
if ( V_50 ) {
F_6 ( L_9 , V_50 ) ;
F_19 ( V_27 ) ;
return NULL ;
}
return V_27 ;
}
void F_39 ( struct V_26 * V_27 )
{
F_40 ( & V_27 -> V_29 ) ;
F_31 ( & V_27 -> V_24 , F_17 ) ;
}
static int T_4 F_41 ( int V_69 , unsigned short * V_70 ,
const char * * V_71 )
{
T_2 V_72 ;
int V_50 ;
V_50 = F_4 ( V_69 ) ;
if ( V_50 )
return V_50 ;
V_72 = F_1 ( V_69 , V_73 ) ;
switch ( V_72 ) {
case V_74 :
* V_71 = L_10 ;
break;
case V_75 :
* V_71 = L_11 ;
break;
default:
F_42 ( L_12 ,
( unsigned int ) V_72 ) ;
V_50 = - V_76 ;
goto exit;
}
F_7 ( V_69 , V_77 ) ;
if ( ! ( F_1 ( V_69 , V_78 ) & 0x01 ) ) {
F_12 ( L_13 ) ;
V_50 = - V_76 ;
goto exit;
}
* V_70 = F_1 ( V_69 , V_79 ) |
F_1 ( V_69 , V_79 + 1 ) << 8 ;
if ( * V_70 == 0 ) {
F_12 ( L_14 ) ;
V_50 = - V_76 ;
goto exit;
}
exit:
F_8 ( V_69 ) ;
return V_50 ;
}
static int T_4 F_43 ( unsigned short V_70 , const char * V_71 )
{
struct V_80 V_81 = {
. V_82 = V_70 ,
. V_83 = V_70 + V_84 - 1 ,
. V_85 = V_86 ,
} ;
int V_50 ;
V_87 = F_44 ( V_71 , V_70 ) ;
if ( ! V_87 )
return - V_88 ;
V_81 . V_71 = V_87 -> V_71 ;
V_50 = F_45 ( & V_81 ) ;
if ( V_50 )
goto V_89;
V_50 = F_46 ( V_87 , & V_81 , 1 ) ;
if ( V_50 ) {
F_6 ( L_15 ) ;
goto V_89;
}
V_50 = F_47 ( V_87 ) ;
if ( V_50 ) {
F_6 ( L_16 ) ;
goto V_89;
}
return 0 ;
V_89:
F_48 ( V_87 ) ;
return V_50 ;
}
static int T_4 F_49 ( void )
{
int V_50 ;
unsigned short V_70 ;
const char * V_71 ;
V_50 = F_41 ( 0x4e , & V_70 , & V_71 ) ;
if ( V_50 )
V_50 = F_41 ( 0x2e , & V_70 , & V_71 ) ;
if ( V_50 )
return V_50 ;
return F_43 ( V_70 , V_71 ) ;
}
static void T_5 F_50 ( void )
{
F_51 ( V_87 ) ;
}
