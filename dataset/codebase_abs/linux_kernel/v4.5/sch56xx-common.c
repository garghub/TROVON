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
F_6 ( L_3 ,
V_2 , 1 ) ;
return - V_16 ;
}
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ ) {
V_11 = F_3 ( V_8 + 1 ) ;
if ( V_11 == 0x01 )
break;
if ( V_12 == 0 )
F_12 ( L_4 ,
( unsigned int ) V_11 , V_2 ) ;
}
if ( V_12 == V_13 ) {
F_6 ( L_3 ,
V_2 , 2 ) ;
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
static int F_17 ( struct V_24 * V_25 ,
unsigned int V_26 )
{
struct V_27 * V_28 = F_18 ( V_25 ) ;
unsigned int V_29 ;
T_2 V_30 ;
int V_31 ;
if ( V_26 <= 255 )
V_29 = 1 ;
else
V_29 = 60 ;
if ( V_26 < V_29 || V_26 > ( V_29 * 255 ) )
return - V_32 ;
if ( V_29 == 1 )
V_30 = V_28 -> V_33 | V_34 ;
else
V_30 = V_28 -> V_33 & ~ V_34 ;
if ( V_28 -> V_33 != V_30 ) {
F_19 ( V_28 -> V_35 ) ;
V_31 = F_14 ( V_28 -> V_8 ,
V_36 ,
V_30 ) ;
F_20 ( V_28 -> V_35 ) ;
if ( V_31 )
return V_31 ;
V_28 -> V_33 = V_30 ;
}
V_28 -> V_37 = F_21 ( V_26 , V_29 ) ;
V_25 -> V_26 = V_28 -> V_37 * V_29 ;
return 0 ;
}
static int F_22 ( struct V_24 * V_25 )
{
struct V_27 * V_28 = F_18 ( V_25 ) ;
int V_31 ;
T_2 V_11 ;
F_19 ( V_28 -> V_35 ) ;
V_31 = F_14 ( V_28 -> V_8 , V_38 ,
V_28 -> V_37 ) ;
if ( V_31 )
goto V_39;
V_11 = V_28 -> V_40 | V_41 ;
V_31 = F_14 ( V_28 -> V_8 ,
V_42 , V_11 ) ;
if ( V_31 )
goto V_39;
V_28 -> V_40 = V_11 ;
V_11 = F_3 ( V_28 -> V_8 + 9 ) ;
if ( V_11 & 0x01 )
F_2 ( 0x01 , V_28 -> V_8 + 9 ) ;
V_39:
F_20 ( V_28 -> V_35 ) ;
return V_31 ;
}
static int F_23 ( struct V_24 * V_25 )
{
struct V_27 * V_28 = F_18 ( V_25 ) ;
int V_31 ;
F_19 ( V_28 -> V_35 ) ;
V_31 = F_14 ( V_28 -> V_8 , V_38 ,
V_28 -> V_37 ) ;
F_20 ( V_28 -> V_35 ) ;
return V_31 ;
}
static int F_24 ( struct V_24 * V_25 )
{
struct V_27 * V_28 = F_18 ( V_25 ) ;
int V_31 = 0 ;
T_2 V_11 ;
V_11 = V_28 -> V_40 & ~ V_41 ;
F_19 ( V_28 -> V_35 ) ;
V_31 = F_14 ( V_28 -> V_8 ,
V_42 , V_11 ) ;
F_20 ( V_28 -> V_35 ) ;
if ( V_31 )
return V_31 ;
V_28 -> V_40 = V_11 ;
return 0 ;
}
struct V_27 * F_25 ( struct V_43 * V_44 ,
T_1 V_8 , T_3 V_45 , struct V_46 * V_35 , int V_47 )
{
struct V_27 * V_28 ;
int V_48 , V_30 , V_49 ;
F_19 ( V_35 ) ;
V_30 =
F_13 ( V_8 , V_36 ) ;
V_49 =
F_13 ( V_8 , V_42 ) ;
F_20 ( V_35 ) ;
if ( V_30 < 0 )
return NULL ;
if ( V_49 < 0 )
return NULL ;
if ( V_47 && ! ( V_49 & V_41 ) ) {
F_12 ( L_5 ) ;
return NULL ;
}
V_28 = F_26 ( sizeof( struct V_27 ) , V_50 ) ;
if ( ! V_28 )
return NULL ;
V_28 -> V_8 = V_8 ;
V_28 -> V_35 = V_35 ;
F_27 ( V_28 -> V_51 . V_52 , L_6 ,
sizeof( V_28 -> V_51 . V_52 ) ) ;
V_28 -> V_51 . V_53 = V_45 ;
V_28 -> V_51 . V_54 = V_55 | V_56 ;
if ( ! V_57 )
V_28 -> V_51 . V_54 |= V_58 ;
V_28 -> V_25 . V_59 = & V_28 -> V_51 ;
V_28 -> V_25 . V_60 = & V_61 ;
V_28 -> V_25 . V_44 = V_44 ;
V_28 -> V_25 . V_26 = 60 ;
V_28 -> V_25 . V_62 = 1 ;
V_28 -> V_25 . V_63 = 255 * 60 ;
if ( V_57 )
F_28 ( V_64 , & V_28 -> V_25 . V_65 ) ;
if ( V_49 & V_41 )
F_28 ( V_66 , & V_28 -> V_25 . V_65 ) ;
if ( V_30 & V_34 )
V_28 -> V_37 = 60 ;
else
V_28 -> V_37 = 1 ;
V_28 -> V_33 = V_30 ;
V_28 -> V_40 = V_49 ;
F_29 ( & V_28 -> V_25 , V_28 ) ;
V_48 = F_30 ( & V_28 -> V_25 ) ;
if ( V_48 ) {
F_6 ( L_7 , V_48 ) ;
F_31 ( V_28 ) ;
return NULL ;
}
return V_28 ;
}
void F_32 ( struct V_27 * V_28 )
{
F_33 ( & V_28 -> V_25 ) ;
F_31 ( V_28 ) ;
}
static int T_4 F_34 ( int V_67 , const char * * V_68 )
{
T_2 V_69 ;
unsigned short V_70 ;
int V_48 ;
V_48 = F_4 ( V_67 ) ;
if ( V_48 )
return V_48 ;
V_69 = F_1 ( V_67 , V_71 ) ;
switch ( V_69 ) {
case V_72 :
* V_68 = L_8 ;
break;
case V_73 :
* V_68 = L_9 ;
break;
default:
F_35 ( L_10 ,
( unsigned int ) V_69 ) ;
V_48 = - V_74 ;
goto exit;
}
F_7 ( V_67 , V_75 ) ;
if ( ! ( F_1 ( V_67 , V_76 ) & 0x01 ) ) {
F_12 ( L_11 ) ;
V_48 = - V_74 ;
goto exit;
}
V_70 = F_1 ( V_67 , V_77 ) |
F_1 ( V_67 , V_77 + 1 ) << 8 ;
if ( V_70 == 0 ) {
F_12 ( L_12 ) ;
V_48 = - V_74 ;
goto exit;
}
V_48 = V_70 ;
exit:
F_8 ( V_67 ) ;
return V_48 ;
}
static int T_4 F_36 ( int V_70 , const char * V_68 )
{
struct V_78 V_79 = {
. V_80 = V_70 ,
. V_81 = V_70 + V_82 - 1 ,
. V_83 = V_84 ,
} ;
int V_48 ;
V_85 = F_37 ( V_68 , V_70 ) ;
if ( ! V_85 )
return - V_86 ;
V_79 . V_68 = V_85 -> V_68 ;
V_48 = F_38 ( & V_79 ) ;
if ( V_48 )
goto V_87;
V_48 = F_39 ( V_85 , & V_79 , 1 ) ;
if ( V_48 ) {
F_6 ( L_13 ) ;
goto V_87;
}
V_48 = F_40 ( V_85 ) ;
if ( V_48 ) {
F_6 ( L_14 ) ;
goto V_87;
}
return 0 ;
V_87:
F_41 ( V_85 ) ;
return V_48 ;
}
static int T_4 F_42 ( void )
{
int V_70 ;
const char * V_68 = NULL ;
V_70 = F_34 ( 0x4e , & V_68 ) ;
if ( V_70 < 0 )
V_70 = F_34 ( 0x2e , & V_68 ) ;
if ( V_70 < 0 )
return V_70 ;
return F_36 ( V_70 , V_68 ) ;
}
static void T_5 F_43 ( void )
{
F_44 ( V_85 ) ;
}
