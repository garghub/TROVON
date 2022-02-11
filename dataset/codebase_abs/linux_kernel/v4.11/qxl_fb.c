static void F_1 ( struct V_1 * V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
V_1 -> V_3 = V_3 ;
if ( V_5 ) {
V_1 -> V_8 = V_5 -> V_9 . V_8 ;
if ( V_1 -> V_8 == V_10 ||
V_1 -> V_8 == V_11 )
memcpy ( & V_1 -> V_12 ,
V_5 -> V_12 ,
sizeof( V_1 -> V_12 ) ) ;
} else {
if ( V_7 -> V_13 == 1 )
V_1 -> V_8 = V_14 ;
else
V_1 -> V_8 = V_11 ;
}
if ( V_7 ) {
memcpy ( & V_1 -> V_6 , V_7 ,
sizeof( V_1 -> V_6 ) ) ;
}
}
static void F_2 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_3 ( V_16 ) ;
int V_19 ;
V_19 = F_4 ( V_18 , false ) ;
if ( F_5 ( V_19 == 0 ) ) {
F_6 ( V_18 ) ;
F_7 ( V_18 ) ;
F_8 ( V_18 ) ;
}
F_9 ( V_16 ) ;
}
int F_10 ( struct V_2 * V_3 ,
struct V_20 * V_21 ,
T_1 * V_22 )
{
int V_23 ;
struct V_15 * V_16 = V_3 -> V_24 -> V_25 ;
F_11 ( ! V_16 ) ;
V_23 = F_12 ( V_21 , V_16 , V_22 ) ;
if ( V_23 )
return V_23 ;
return 0 ;
}
static int F_13 ( struct V_26 * V_27 ,
const struct V_28 * V_29 ,
struct V_15 * * V_30 )
{
struct V_2 * V_3 = V_27 -> V_3 ;
struct V_15 * V_16 = NULL ;
struct V_17 * V_18 = NULL ;
int V_19 ;
int V_31 , V_32 ;
int V_33 = V_29 -> V_33 ;
V_32 = V_29 -> V_34 [ 0 ] * V_33 ;
V_31 = F_14 ( V_32 , V_35 ) ;
V_19 = F_15 ( V_3 , V_31 , 0 ,
V_36 ,
false ,
false ,
NULL ,
& V_16 ) ;
if ( V_19 ) {
F_16 ( L_1 ,
V_31 ) ;
return - V_37 ;
}
V_18 = F_3 ( V_16 ) ;
V_18 -> V_38 . V_39 = V_29 -> V_39 ;
V_18 -> V_38 . V_33 = V_29 -> V_33 ;
V_18 -> V_38 . V_40 = V_29 -> V_34 [ 0 ] ;
V_18 -> V_38 . V_41 = V_42 ;
V_19 = F_4 ( V_18 , false ) ;
if ( F_17 ( V_19 != 0 ) )
goto V_43;
V_19 = F_18 ( V_18 , V_36 , NULL ) ;
if ( V_19 ) {
F_8 ( V_18 ) ;
goto V_43;
}
V_19 = F_19 ( V_18 , NULL ) ;
F_8 ( V_18 ) ;
if ( V_19 )
goto V_43;
* V_30 = V_16 ;
return 0 ;
V_43:
F_2 ( V_16 ) ;
* V_30 = NULL ;
return V_19 ;
}
static int F_20 ( struct V_44 * V_45 ,
struct V_20 * V_21 ,
unsigned V_46 , unsigned V_47 ,
struct V_48 * V_49 ,
unsigned V_50 )
{
struct V_2 * V_3 = V_45 -> V_51 -> V_52 ;
struct V_4 * V_5 = V_3 -> V_53 ;
struct V_26 * V_27 = V_5 -> V_54 ;
struct V_1 V_1 ;
struct V_6 * V_7 = & V_1 . V_6 ;
int V_40 = V_27 -> V_55 . V_56 . V_34 [ 0 ] ;
F_21 ( V_3 , L_2 , V_49 -> V_57 , V_49 -> V_58 ,
V_49 -> y1 , V_49 -> V_59 ) ;
V_7 -> V_60 = V_49 -> V_57 ;
V_7 -> V_61 = V_49 -> y1 ;
V_7 -> V_39 = V_49 -> V_58 - V_49 -> V_57 ;
V_7 -> V_33 = V_49 -> V_59 - V_49 -> y1 ;
V_7 -> V_62 = 0xffffffff ;
V_7 -> V_63 = 0 ;
V_7 -> V_13 = 32 ;
V_7 -> V_64 . V_65 = 0 ;
V_7 -> V_64 . V_66 = 0 ;
V_7 -> V_64 . V_67 = NULL ;
V_7 -> V_64 . V_68 = NULL ;
V_7 -> V_64 . V_69 = NULL ;
V_7 -> V_64 . V_70 = NULL ;
V_7 -> V_71 = V_27 -> V_72 + ( V_49 -> V_57 * 4 ) + ( V_40 * V_49 -> y1 ) ;
F_1 ( & V_1 , V_3 , V_5 , NULL ) ;
F_22 ( & V_1 , V_40 ) ;
return 0 ;
}
static int F_23 ( struct V_26 * V_27 ,
struct V_73 * V_74 )
{
struct V_2 * V_3 = V_27 -> V_3 ;
struct V_4 * V_5 ;
struct V_44 * V_45 = NULL ;
struct V_28 V_29 ;
struct V_15 * V_16 = NULL ;
struct V_17 * V_18 = NULL ;
int V_19 ;
int V_32 ;
int V_75 = V_74 -> V_76 ;
int V_13 = V_74 -> V_77 ;
void * V_72 ;
V_29 . V_39 = V_74 -> V_78 ;
V_29 . V_33 = V_74 -> V_79 ;
V_29 . V_34 [ 0 ] = F_14 ( V_29 . V_39 * ( ( V_75 + 1 ) / 8 ) , 64 ) ;
V_29 . V_80 = F_24 ( V_75 , V_13 ) ;
V_19 = F_13 ( V_27 , & V_29 , & V_16 ) ;
if ( V_19 < 0 )
return V_19 ;
V_18 = F_3 ( V_16 ) ;
F_25 ( V_3 , L_3 , V_81 , V_29 . V_39 ,
V_29 . V_33 , V_29 . V_34 [ 0 ] ) ;
V_72 = F_26 ( V_29 . V_34 [ 0 ] * V_29 . V_33 ) ;
F_11 ( ! V_72 ) ;
F_25 ( V_3 ,
L_4 ,
F_27 ( V_18 ) ,
F_28 ( V_18 ) ,
V_18 -> V_82 ,
V_72 ) ;
V_32 = V_29 . V_34 [ 0 ] * V_29 . V_33 ;
V_5 = F_29 ( & V_27 -> V_83 ) ;
if ( F_30 ( V_5 ) ) {
V_19 = F_31 ( V_5 ) ;
goto V_43;
}
V_5 -> V_54 = V_27 ;
F_32 ( & V_3 -> V_84 , & V_27 -> V_55 , & V_29 , V_16 ,
& V_85 ) ;
V_45 = & V_27 -> V_55 . V_56 ;
V_27 -> V_83 . V_45 = V_45 ;
V_27 -> V_72 = V_72 ;
strcpy ( V_5 -> V_9 . V_86 , L_5 ) ;
F_33 ( V_5 , V_45 -> V_34 [ 0 ] , V_45 -> V_41 -> V_13 ) ;
V_5 -> V_46 = V_87 | V_88 | V_89 ;
V_5 -> V_90 = & V_91 ;
V_5 -> V_9 . V_92 = V_3 -> V_93 ;
V_5 -> V_9 . V_94 = V_16 -> V_32 ;
V_5 -> V_95 = V_27 -> V_72 ;
V_5 -> V_96 = V_16 -> V_32 ;
F_34 ( V_5 , & V_27 -> V_83 , V_74 -> V_97 ,
V_74 -> V_98 ) ;
V_5 -> V_99 -> V_100 [ 0 ] . V_56 = V_3 -> V_84 . V_101 . V_102 ;
V_5 -> V_99 -> V_100 [ 0 ] . V_32 = V_3 -> V_103 ;
V_5 -> V_9 . V_104 = 0 ;
V_5 -> V_9 . V_105 = 0 ;
if ( V_5 -> V_95 == NULL ) {
V_19 = - V_106 ;
goto V_107;
}
#ifdef F_35
V_5 -> V_108 = & V_109 ;
F_36 ( V_5 ) ;
#endif
V_3 -> V_53 = V_5 ;
V_3 -> V_24 = & V_27 -> V_55 ;
F_37 ( L_6 , V_5 -> V_9 . V_92 , ( unsigned long ) V_5 -> V_96 ) ;
F_37 ( L_7 ,
V_45 -> V_41 -> V_13 , V_45 -> V_34 [ 0 ] , V_45 -> V_39 , V_45 -> V_33 ) ;
return 0 ;
V_107:
F_38 ( & V_27 -> V_83 ) ;
V_43:
if ( V_18 ) {
V_19 = F_4 ( V_18 , false ) ;
if ( F_5 ( V_19 == 0 ) ) {
F_6 ( V_18 ) ;
F_7 ( V_18 ) ;
F_8 ( V_18 ) ;
}
}
if ( V_45 && V_19 ) {
F_9 ( V_16 ) ;
F_39 ( V_45 ) ;
F_40 ( V_45 ) ;
}
F_9 ( V_16 ) ;
return V_19 ;
}
static int F_41 (
struct V_110 * V_83 ,
struct V_73 * V_74 )
{
struct V_26 * V_27 =
F_42 ( V_83 , struct V_26 , V_83 ) ;
int V_111 = 0 ;
int V_19 ;
if ( ! V_83 -> V_45 ) {
V_19 = F_23 ( V_27 , V_74 ) ;
if ( V_19 )
return V_19 ;
V_111 = 1 ;
}
return V_111 ;
}
static int F_43 ( struct V_112 * V_51 , struct V_26 * V_27 )
{
struct V_113 * V_55 = & V_27 -> V_55 ;
F_44 ( & V_27 -> V_83 ) ;
F_38 ( & V_27 -> V_83 ) ;
if ( V_55 -> V_25 ) {
F_2 ( V_55 -> V_25 ) ;
V_55 -> V_25 = NULL ;
}
F_45 ( & V_27 -> V_83 ) ;
F_46 ( V_27 -> V_72 ) ;
F_39 ( & V_55 -> V_56 ) ;
return 0 ;
}
int F_47 ( struct V_2 * V_3 )
{
struct V_26 * V_27 ;
int V_114 = 32 ;
int V_19 ;
V_27 = F_48 ( sizeof( struct V_26 ) , V_115 ) ;
if ( ! V_27 )
return - V_37 ;
V_27 -> V_3 = V_3 ;
V_3 -> V_116 . V_27 = V_27 ;
F_49 ( & V_27 -> V_117 ) ;
F_50 ( & V_27 -> V_118 ) ;
F_51 ( & V_3 -> V_84 , & V_27 -> V_83 ,
& V_119 ) ;
V_19 = F_52 ( & V_3 -> V_84 , & V_27 -> V_83 ,
V_120 ) ;
if ( V_19 )
goto free;
V_19 = F_53 ( & V_27 -> V_83 ) ;
if ( V_19 )
goto V_121;
V_19 = F_54 ( & V_27 -> V_83 , V_114 ) ;
if ( V_19 )
goto V_121;
return 0 ;
V_121:
F_45 ( & V_27 -> V_83 ) ;
free:
F_40 ( V_27 ) ;
return V_19 ;
}
void F_55 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_116 . V_27 )
return;
F_43 ( & V_3 -> V_84 , V_3 -> V_116 . V_27 ) ;
F_40 ( V_3 -> V_116 . V_27 ) ;
V_3 -> V_116 . V_27 = NULL ;
}
void F_56 ( struct V_2 * V_3 , int V_122 )
{
F_57 ( & V_3 -> V_116 . V_27 -> V_83 , V_122 ) ;
}
bool F_58 ( struct V_2 * V_3 , struct V_17 * V_123 )
{
if ( V_123 == F_3 ( V_3 -> V_116 . V_27 -> V_55 . V_25 ) )
return true ;
return false ;
}
