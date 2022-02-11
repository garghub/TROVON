static inline struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_2 * V_3 )
{
F_4 ( & V_4 ) ;
F_5 ( V_3 , & V_5 ) ;
F_6 ( F_7 ( V_3 ) , V_3 -> V_6 , 1 ) ;
F_8 ( & V_4 ) ;
}
static void F_9 ( struct V_2 * V_3 )
{
F_4 ( & V_4 ) ;
if ( F_10 ( V_3 ) )
F_6 ( F_7 ( V_3 ) , V_3 -> V_6 , - 1 ) ;
F_8 ( & V_4 ) ;
}
static int F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_8 . V_9 = V_10 ;
V_7 -> V_8 . V_11 = 0xffff ;
V_7 -> V_12 = 1 ;
memset ( & V_7 -> V_8 . V_13 , 0xff , sizeof( V_7 -> V_8 . V_13 ) ) ;
return 0 ;
}
static void F_12 ( struct V_2 * V_3 , long V_14 )
{
F_13 ( V_3 ) ;
}
static int F_14 ( struct V_2 * V_3 , struct V_15 * V_16 , int V_17 )
{
struct V_18 * V_19 = (struct V_18 * ) V_16 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_20 = - V_21 ;
struct V_22 * V_23 ;
F_15 ( V_3 ) ;
V_7 -> V_24 = 0 ;
if ( V_17 < sizeof( * V_19 ) )
goto V_25;
if ( V_19 -> V_26 != V_27 )
goto V_25;
V_23 = F_16 ( F_7 ( V_3 ) , & V_19 -> V_19 ) ;
if ( ! V_23 ) {
V_20 = - V_28 ;
goto V_25;
}
if ( V_23 -> type != V_29 ) {
V_20 = - V_28 ;
goto V_30;
}
memcpy ( & V_7 -> V_31 , & V_19 -> V_19 , sizeof( struct V_32 ) ) ;
V_7 -> V_24 = 1 ;
V_20 = 0 ;
V_30:
F_17 ( V_23 ) ;
V_25:
F_18 ( V_3 ) ;
return V_20 ;
}
static int F_19 ( struct V_2 * V_3 , int V_33 , unsigned long V_34 )
{
switch ( V_33 ) {
case V_35 :
{
int V_36 = F_20 ( V_3 ) ;
return F_21 ( V_36 , ( int V_37 * ) V_34 ) ;
}
case V_38 :
{
struct V_39 * V_40 ;
unsigned long V_36 ;
V_36 = 0 ;
F_22 ( & V_3 -> V_41 . V_42 ) ;
V_40 = F_23 ( & V_3 -> V_41 ) ;
if ( V_40 != NULL ) {
V_36 = V_40 -> V_17 - ( 3 + 8 + 8 ) ;
}
F_24 ( & V_3 -> V_41 . V_42 ) ;
return F_21 ( V_36 , ( int V_37 * ) V_34 ) ;
}
}
return - V_43 ;
}
static int F_25 ( struct V_2 * V_3 , struct V_15 * V_16 ,
int V_17 )
{
struct V_18 * V_19 = (struct V_18 * ) V_16 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_20 = 0 ;
if ( V_17 < sizeof( * V_19 ) )
return - V_21 ;
if ( V_19 -> V_26 != V_27 )
return - V_21 ;
F_15 ( V_3 ) ;
if ( ! V_7 -> V_24 ) {
V_20 = - V_44 ;
goto V_25;
}
memcpy ( & V_7 -> V_8 , & V_19 -> V_19 , sizeof( struct V_32 ) ) ;
V_25:
F_18 ( V_3 ) ;
return V_20 ;
}
static int F_26 ( struct V_2 * V_3 , int V_45 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_15 ( V_3 ) ;
V_7 -> V_8 . V_9 = V_10 ;
memset ( & V_7 -> V_8 . V_13 , 0xff , sizeof( V_7 -> V_8 . V_13 ) ) ;
F_18 ( V_3 ) ;
return 0 ;
}
static int F_27 ( struct V_46 * V_47 , struct V_2 * V_3 ,
struct V_48 * V_49 , T_1 V_50 )
{
struct V_22 * V_23 ;
unsigned int V_51 ;
struct V_39 * V_40 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_52 , V_53 ;
int V_20 ;
if ( V_49 -> V_54 & V_55 ) {
F_28 ( L_1 , V_49 -> V_54 ) ;
return - V_56 ;
}
if ( ! V_7 -> V_24 )
V_23 = F_29 ( F_7 ( V_3 ) , V_29 ) ;
else
V_23 = F_16 ( F_7 ( V_3 ) , & V_7 -> V_31 ) ;
if ( ! V_23 ) {
F_28 ( L_2 ) ;
V_20 = - V_57 ;
goto V_25;
}
V_51 = V_23 -> V_51 ;
F_28 ( L_3 , V_23 -> V_58 , V_51 ) ;
if ( V_50 > V_51 ) {
F_28 ( L_4 , V_50 , V_51 ) ;
V_20 = - V_21 ;
goto V_59;
}
V_52 = F_30 ( V_23 ) ;
V_53 = V_23 -> V_60 ;
V_40 = F_31 ( V_3 , V_52 + V_53 + V_50 ,
V_49 -> V_54 & V_61 ,
& V_20 ) ;
if ( ! V_40 )
goto V_59;
F_32 ( V_40 , V_52 ) ;
F_33 ( V_40 ) ;
F_34 ( V_40 ) -> V_45 = V_62 ;
if ( V_7 -> V_12 )
F_34 ( V_40 ) -> V_45 |= V_63 ;
F_34 ( V_40 ) -> V_64 = F_35 ( V_23 ) -> F_36 ( V_23 ) ;
V_20 = F_37 ( V_40 , V_23 , V_65 , & V_7 -> V_8 ,
V_7 -> V_24 ? & V_7 -> V_31 : NULL , V_50 ) ;
if ( V_20 < 0 )
goto V_66;
F_38 ( V_40 ) ;
V_20 = F_39 ( F_40 ( V_40 , V_50 ) , V_49 -> V_67 , V_50 ) ;
if ( V_20 < 0 )
goto V_66;
V_40 -> V_23 = V_23 ;
V_40 -> V_3 = V_3 ;
V_40 -> V_68 = F_41 ( V_65 ) ;
F_17 ( V_23 ) ;
V_20 = F_42 ( V_40 ) ;
if ( V_20 > 0 )
V_20 = F_43 ( V_20 ) ;
return V_20 ? : V_50 ;
V_66:
F_44 ( V_40 ) ;
V_59:
F_17 ( V_23 ) ;
V_25:
return V_20 ;
}
static int F_45 ( struct V_46 * V_47 , struct V_2 * V_3 ,
struct V_48 * V_49 , T_1 V_17 , int V_69 , int V_45 ,
int * V_70 )
{
T_1 V_71 = 0 ;
int V_20 = - V_56 ;
struct V_39 * V_40 ;
F_46 ( struct V_18 * , V_72 , V_49 -> V_73 ) ;
V_40 = F_47 ( V_3 , V_45 , V_69 , & V_20 ) ;
if ( ! V_40 )
goto V_25;
V_71 = V_40 -> V_17 ;
if ( V_17 < V_71 ) {
V_49 -> V_54 |= V_74 ;
V_71 = V_17 ;
}
V_20 = F_48 ( V_40 , 0 , V_49 -> V_67 , V_71 ) ;
if ( V_20 )
goto V_75;
F_49 ( V_49 , V_3 , V_40 ) ;
if ( V_72 ) {
V_72 -> V_26 = V_27 ;
V_72 -> V_19 = F_34 ( V_40 ) -> V_76 ;
* V_70 = sizeof( * V_72 ) ;
}
if ( V_45 & V_74 )
V_71 = V_40 -> V_17 ;
V_75:
F_50 ( V_3 , V_40 ) ;
V_25:
if ( V_20 )
return V_20 ;
return V_71 ;
}
static int F_51 ( struct V_2 * V_3 , struct V_39 * V_40 )
{
if ( F_52 ( V_3 , V_40 ) < 0 ) {
F_44 ( V_40 ) ;
return V_77 ;
}
return V_78 ;
}
static inline int F_53 ( T_2 * V_79 , T_3 V_11 ,
T_3 V_80 , struct V_1 * V_7 )
{
if ( ! V_7 -> V_24 )
return 1 ;
if ( V_7 -> V_31 . V_9 == V_10 &&
! memcmp ( V_7 -> V_31 . V_13 , V_79 , V_81 ) )
return 1 ;
if ( V_7 -> V_31 . V_9 == V_82 &&
V_11 == V_7 -> V_31 . V_11 &&
V_80 == V_7 -> V_31 . V_80 )
return 1 ;
return 0 ;
}
int F_54 ( struct V_22 * V_23 , struct V_39 * V_40 )
{
struct V_2 * V_3 , * V_83 = NULL ;
int V_84 = V_78 ;
T_3 V_11 , V_80 ;
F_55 ( V_23 -> type != V_29 ) ;
V_11 = F_35 ( V_23 ) -> F_56 ( V_23 ) ;
V_80 = F_35 ( V_23 ) -> F_57 ( V_23 ) ;
F_58 ( & V_4 ) ;
F_59 (sk, &dgram_head) {
if ( F_53 ( V_23 -> V_85 , V_11 , V_80 ,
F_1 ( V_3 ) ) ) {
if ( V_83 ) {
struct V_39 * V_86 ;
V_86 = F_60 ( V_40 , V_87 ) ;
if ( V_86 )
F_51 ( V_83 , V_86 ) ;
}
V_83 = V_3 ;
}
}
if ( V_83 )
F_51 ( V_83 , V_40 ) ;
else {
F_44 ( V_40 ) ;
V_84 = V_77 ;
}
F_61 ( & V_4 ) ;
return V_84 ;
}
static int F_62 ( struct V_2 * V_3 , int V_88 , int V_89 ,
char V_37 * V_90 , int V_37 * V_91 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_92 , V_17 ;
if ( V_88 != V_93 )
return - V_56 ;
if ( F_63 ( V_17 , V_91 ) )
return - V_94 ;
V_17 = F_64 (unsigned int, len, sizeof(int)) ;
switch ( V_89 ) {
case V_95 :
V_92 = V_7 -> V_12 ;
break;
default:
return - V_96 ;
}
if ( F_21 ( V_17 , V_91 ) )
return - V_94 ;
if ( F_65 ( V_90 , & V_92 , V_17 ) )
return - V_94 ;
return 0 ;
}
static int F_66 ( struct V_2 * V_3 , int V_88 , int V_89 ,
char V_37 * V_90 , unsigned int V_91 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_92 ;
int V_20 = 0 ;
if ( V_91 < sizeof( int ) )
return - V_21 ;
if ( F_63 ( V_92 , ( int V_37 * ) V_90 ) )
return - V_94 ;
F_15 ( V_3 ) ;
switch ( V_89 ) {
case V_95 :
V_7 -> V_12 = ! ! V_92 ;
break;
default:
V_20 = - V_96 ;
break;
}
F_18 ( V_3 ) ;
return V_20 ;
}
