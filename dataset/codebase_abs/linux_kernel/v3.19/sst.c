static inline bool F_1 ( T_1 V_1 )
{
return ( ( V_1 & V_2 ) ? true : false ) ;
}
static inline bool F_2 ( unsigned int V_3 )
{
return ( ( V_3 <= V_4 ) ? true : false ) ;
}
static T_2 F_3 ( int V_5 , void * V_6 )
{
union V_7 V_8 ;
union V_9 V_10 ;
union V_11 V_12 ;
struct V_13 * V_14 = NULL ;
unsigned int V_3 = 0 ;
struct V_15 * V_16 = (struct V_15 * ) V_6 ;
T_2 V_17 = V_18 ;
V_8 . V_19 = F_4 ( V_16 -> V_20 , V_21 ) ;
if ( V_8 . V_22 . V_23 ) {
F_5 ( & V_16 -> V_24 ) ;
V_10 . V_19 = F_4 ( V_16 -> V_20 ,
V_16 -> V_25 . V_26 ) ;
V_10 . V_27 . V_28 . V_22 . V_29 = 0 ;
F_6 ( V_16 -> V_20 , V_16 -> V_25 . V_26 , V_10 . V_19 ) ;
;
V_8 . V_22 . V_23 = 1 ;
F_6 ( V_16 -> V_20 , V_21 , V_8 . V_19 ) ;
F_7 ( & V_16 -> V_24 ) ;
F_8 ( V_16 -> V_30 , & V_16 -> V_31 ) ;
V_17 = V_18 ;
}
if ( V_8 . V_22 . V_32 ) {
F_5 ( & V_16 -> V_24 ) ;
V_12 . V_19 = F_4 ( V_16 -> V_20 , V_33 ) ;
V_12 . V_22 . V_32 = 1 ;
F_6 ( V_16 -> V_20 , V_33 , V_12 . V_19 ) ;
F_7 ( & V_16 -> V_24 ) ;
V_10 . V_19 = F_4 ( V_16 -> V_20 , V_16 -> V_25 . V_34 ) ;
if ( F_9 ( & V_14 , V_10 . V_27 . V_28 . V_22 . V_35 ) ) {
V_16 -> V_36 -> V_37 ( V_16 ) ;
return V_18 ;
}
if ( V_10 . V_27 . V_28 . V_22 . V_35 ) {
V_3 = V_10 . V_27 . V_38 ;
if ( F_2 ( V_3 ) ) {
F_10 ( V_14 -> V_39 ,
V_16 -> V_40 + V_16 -> V_41 , V_3 ) ;
} else {
F_11 ( V_16 -> V_42 ,
L_1 , V_3 ) ;
V_10 . V_27 . V_38 = 0 ;
}
}
V_14 -> V_43 = V_10 ;
V_14 -> V_44 =
F_1 ( V_10 . V_27 . V_28 . V_22 . V_1 ) ;
F_5 ( & V_16 -> V_45 ) ;
F_12 ( & V_14 -> V_46 , & V_16 -> V_47 ) ;
F_7 ( & V_16 -> V_45 ) ;
V_16 -> V_36 -> V_37 ( V_16 ) ;
V_17 = V_48 ;
}
return V_17 ;
}
static T_2 F_13 ( int V_5 , void * V_6 )
{
struct V_15 * V_16 = (struct V_15 * ) V_6 ;
struct V_13 * V_49 , * V_14 = NULL ;
unsigned long V_50 ;
F_14 ( & V_16 -> V_45 , V_50 ) ;
if ( F_15 ( & V_16 -> V_47 ) ) {
F_16 ( & V_16 -> V_45 , V_50 ) ;
return V_18 ;
}
F_17 (msg, __msg, &drv->rx_list, node) {
F_18 ( & V_14 -> V_46 ) ;
F_16 ( & V_16 -> V_45 , V_50 ) ;
if ( V_14 -> V_44 )
V_16 -> V_36 -> V_51 ( V_14 ) ;
else
V_16 -> V_36 -> V_52 ( V_16 , V_14 ) ;
if ( V_14 -> V_53 )
F_19 ( V_14 -> V_39 ) ;
F_19 ( V_14 ) ;
F_14 ( & V_16 -> V_45 , V_50 ) ;
}
F_16 ( & V_16 -> V_45 , V_50 ) ;
return V_18 ;
}
static int F_20 ( struct V_15 * V_54 )
{
int V_55 = 0 ;
V_55 = F_21 ( V_54 , V_56 , V_57 ,
V_58 , V_59 , 0 , NULL , NULL ,
true , true , false , true ) ;
if ( V_55 < 0 ) {
F_11 ( V_54 -> V_42 , L_2 , V_55 ) ;
return - V_60 ;
}
return 0 ;
}
int F_22 ( struct V_15 * V_54 )
{
switch ( V_54 -> V_61 ) {
case V_62 :
case V_63 :
case V_64 :
V_54 -> V_65 = V_66 ;
V_54 -> V_36 = & V_67 ;
return 0 ;
default:
F_11 ( V_54 -> V_42 ,
L_3 , V_54 -> V_61 ) ;
return - V_68 ;
} ;
}
void F_23 ( struct V_69 * V_70 )
{
struct V_15 * V_71 = F_24 ( V_70 ,
struct V_15 , V_31 ) ;
V_71 -> V_36 -> V_72 ( V_71 , NULL , false ) ;
}
static int F_25 ( struct V_15 * V_71 )
{
F_26 ( & V_71 -> V_73 ) ;
F_26 ( & V_71 -> V_47 ) ;
F_26 ( & V_71 -> V_74 ) ;
F_26 ( & V_71 -> V_75 ) ;
F_27 ( & V_71 -> V_31 , F_23 ) ;
F_28 ( & V_71 -> V_76 ) ;
V_71 -> V_30 =
F_29 ( L_4 ) ;
if ( ! V_71 -> V_30 )
return - V_77 ;
return 0 ;
}
static void F_30 ( struct V_15 * V_71 )
{
F_31 ( & V_71 -> V_78 ) ;
F_32 ( & V_71 -> V_45 ) ;
F_32 ( & V_71 -> V_24 ) ;
F_32 ( & V_71 -> V_79 ) ;
}
int F_33 ( struct V_15 * * V_71 ,
struct V_80 * V_42 , unsigned int V_61 )
{
* V_71 = F_34 ( V_42 , sizeof( struct V_15 ) , V_81 ) ;
if ( ! ( * V_71 ) )
return - V_82 ;
( * V_71 ) -> V_42 = V_42 ;
( * V_71 ) -> V_61 = V_61 ;
return 0 ;
}
int F_35 ( struct V_15 * V_71 )
{
int V_55 = 0 , V_83 ;
if ( ! V_71 -> V_84 )
return - V_68 ;
if ( ! V_71 -> V_84 -> V_85 )
return - V_68 ;
memcpy ( & V_71 -> V_86 , V_71 -> V_84 -> V_85 , sizeof( V_71 -> V_86 ) ) ;
V_55 = F_22 ( V_71 ) ;
if ( V_55 != 0 )
return - V_68 ;
F_30 ( V_71 ) ;
F_36 ( V_71 , V_87 ) ;
V_71 -> V_88 = 1 ;
V_71 -> V_89 = 0 ;
V_71 -> V_90 = NULL ;
V_71 -> V_91 = 0 ;
V_71 -> V_92 = 0 ;
if ( F_25 ( V_71 ) )
return - V_68 ;
V_71 -> V_41 = V_71 -> V_84 -> V_93 -> V_94 ;
V_71 -> V_25 . V_26 = V_95 + V_71 -> V_84 -> V_93 -> V_96 ;
V_71 -> V_25 . V_34 = V_97 + V_71 -> V_84 -> V_93 -> V_96 ;
F_37 ( V_71 -> V_42 , L_5 ,
V_71 -> V_86 . V_98 ) ;
for ( V_83 = 1 ; V_83 <= V_71 -> V_86 . V_98 ; V_83 ++ ) {
struct V_99 * V_100 = & V_71 -> V_101 [ V_83 ] ;
memset ( V_100 , 0 , sizeof( * V_100 ) ) ;
V_100 -> V_102 = V_59 ;
F_31 ( & V_100 -> V_103 ) ;
}
V_55 = F_38 ( V_71 -> V_42 , V_71 -> V_104 , V_71 -> V_36 -> V_105 ,
V_71 -> V_36 -> V_106 , 0 , V_107 ,
V_71 ) ;
if ( V_55 )
goto V_108;
F_39 ( V_71 -> V_42 , L_6 , V_71 -> V_104 ) ;
F_6 ( V_71 -> V_20 , V_33 , 0xFFFF0038 ) ;
V_71 -> V_109 = F_34 ( V_71 -> V_42 ,
sizeof( struct V_110 ) , V_81 ) ;
if ( ! V_71 -> V_109 ) {
V_55 = - V_82 ;
goto V_108;
}
F_40 ( V_71 -> V_109 , V_111 ,
V_112 ) ;
F_39 ( V_71 -> V_42 , L_7 , V_71 -> V_113 ) ;
V_55 = F_41 ( V_114 , true , V_71 -> V_113 ,
V_71 -> V_42 , V_81 , V_71 , V_115 ) ;
if ( V_55 ) {
F_11 ( V_71 -> V_42 , L_8 , V_55 ) ;
goto V_108;
}
F_42 ( V_71 -> V_42 ) ;
return 0 ;
V_108:
F_43 ( V_71 -> V_30 ) ;
return V_55 ;
}
void F_44 ( struct V_15 * V_71 )
{
F_45 ( V_71 -> V_42 ) ;
F_46 ( V_71 -> V_42 ) ;
F_47 ( V_71 -> V_42 ) ;
F_36 ( V_71 , V_116 ) ;
F_48 () ;
F_43 ( V_71 -> V_30 ) ;
F_49 ( V_71 -> V_109 ) ;
F_19 ( V_71 -> V_117 . V_118 ) ;
F_19 ( V_71 -> V_117 . V_119 ) ;
V_71 -> V_117 . V_120 = 0 ;
F_19 ( V_71 -> V_90 ) ;
V_71 -> V_90 = NULL ;
F_50 ( V_71 ) ;
V_71 = NULL ;
}
static inline void F_51 ( struct V_15 * V_71 ,
void T_3 * V_20 ,
struct V_121 * V_122 )
{
unsigned long V_50 ;
F_14 ( & V_71 -> V_24 , V_50 ) ;
V_122 -> V_123 = F_4 ( V_20 , V_33 ) ,
F_16 ( & V_71 -> V_24 , V_50 ) ;
}
static inline void F_52 ( struct V_15 * V_71 ,
void T_3 * V_20 ,
struct V_121 * V_122 )
{
unsigned long V_50 ;
F_14 ( & V_71 -> V_24 , V_50 ) ;
F_6 ( V_20 , V_33 , V_122 -> V_123 ) ,
F_16 ( & V_71 -> V_24 , V_50 ) ;
}
void F_53 ( struct V_15 * V_71 )
{
F_54 ( V_71 -> V_42 , V_124 ) ;
F_55 ( V_71 -> V_42 ) ;
F_56 ( V_71 -> V_42 ) ;
if ( V_125 )
F_57 ( V_71 -> V_42 ) ;
else
F_58 ( V_71 -> V_42 ) ;
F_51 ( V_71 , V_71 -> V_20 , V_71 -> V_126 ) ;
}
static int F_59 ( struct V_80 * V_42 )
{
int V_55 = 0 ;
struct V_15 * V_71 = F_60 ( V_42 ) ;
if ( V_71 -> V_127 == V_87 ) {
F_39 ( V_42 , L_9 ) ;
return 0 ;
}
if ( V_71 -> V_36 -> V_128 ( V_71 ) )
return - V_77 ;
F_36 ( V_71 , V_87 ) ;
F_61 ( V_71 -> V_104 ) ;
F_62 ( V_71 -> V_30 ) ;
F_51 ( V_71 , V_71 -> V_20 , V_71 -> V_126 ) ;
return V_55 ;
}
static int F_63 ( struct V_80 * V_42 )
{
int V_55 = 0 ;
struct V_15 * V_71 = F_60 ( V_42 ) ;
if ( V_71 -> V_127 == V_87 ) {
V_55 = F_64 ( V_71 ) ;
if ( V_55 ) {
F_11 ( V_42 , L_10 , V_55 ) ;
F_36 ( V_71 , V_87 ) ;
}
}
return V_55 ;
}
