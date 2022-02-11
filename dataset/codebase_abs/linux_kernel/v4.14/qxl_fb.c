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
F_4 ( V_18 ) ;
F_5 ( V_18 ) ;
F_6 ( V_16 ) ;
}
int F_7 ( struct V_2 * V_3 ,
struct V_19 * V_20 ,
T_1 * V_21 )
{
int V_22 ;
struct V_15 * V_16 = V_3 -> V_23 -> V_24 ;
F_8 ( ! V_16 ) ;
V_22 = F_9 ( V_20 , V_16 , V_21 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
static int F_10 ( struct V_25 * V_26 ,
const struct V_27 * V_28 ,
struct V_15 * * V_29 )
{
struct V_2 * V_3 = V_26 -> V_3 ;
struct V_15 * V_16 = NULL ;
struct V_17 * V_18 = NULL ;
int V_30 ;
int V_31 , V_32 ;
int V_33 = V_28 -> V_33 ;
V_32 = V_28 -> V_34 [ 0 ] * V_33 ;
V_31 = F_11 ( V_32 , V_35 ) ;
V_30 = F_12 ( V_3 , V_31 , 0 ,
V_36 ,
false ,
false ,
NULL ,
& V_16 ) ;
if ( V_30 ) {
F_13 ( L_1 ,
V_31 ) ;
return - V_37 ;
}
V_18 = F_3 ( V_16 ) ;
V_18 -> V_38 . V_39 = V_28 -> V_39 ;
V_18 -> V_38 . V_33 = V_28 -> V_33 ;
V_18 -> V_38 . V_40 = V_28 -> V_34 [ 0 ] ;
V_18 -> V_38 . V_41 = V_42 ;
V_30 = F_14 ( V_18 , V_36 , NULL ) ;
if ( V_30 ) {
goto V_43;
}
V_30 = F_15 ( V_18 , NULL ) ;
if ( V_30 )
goto V_43;
* V_29 = V_16 ;
return 0 ;
V_43:
F_2 ( V_16 ) ;
* V_29 = NULL ;
return V_30 ;
}
static int F_16 ( struct V_44 * V_45 ,
struct V_19 * V_20 ,
unsigned V_46 , unsigned V_47 ,
struct V_48 * V_49 ,
unsigned V_50 )
{
struct V_2 * V_3 = V_45 -> V_51 -> V_52 ;
struct V_4 * V_5 = V_3 -> V_53 ;
struct V_25 * V_26 = V_5 -> V_54 ;
struct V_1 V_1 ;
struct V_6 * V_7 = & V_1 . V_6 ;
int V_40 = V_26 -> V_55 . V_56 . V_34 [ 0 ] ;
F_17 ( V_3 , L_2 , V_49 -> V_57 , V_49 -> V_58 ,
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
V_7 -> V_71 = V_26 -> V_72 + ( V_49 -> V_57 * 4 ) + ( V_40 * V_49 -> y1 ) ;
F_1 ( & V_1 , V_3 , V_5 , NULL ) ;
F_18 ( & V_1 , V_40 ) ;
return 0 ;
}
static int F_19 ( struct V_25 * V_26 ,
struct V_73 * V_74 )
{
struct V_2 * V_3 = V_26 -> V_3 ;
struct V_4 * V_5 ;
struct V_44 * V_45 = NULL ;
struct V_27 V_28 ;
struct V_15 * V_16 = NULL ;
struct V_17 * V_18 = NULL ;
int V_30 ;
int V_32 ;
int V_75 = V_74 -> V_76 ;
int V_13 = V_74 -> V_77 ;
void * V_72 ;
V_28 . V_39 = V_74 -> V_78 ;
V_28 . V_33 = V_74 -> V_79 ;
V_28 . V_34 [ 0 ] = F_11 ( V_28 . V_39 * ( ( V_75 + 1 ) / 8 ) , 64 ) ;
V_28 . V_80 = F_20 ( V_75 , V_13 ) ;
V_30 = F_10 ( V_26 , & V_28 , & V_16 ) ;
if ( V_30 < 0 )
return V_30 ;
V_18 = F_3 ( V_16 ) ;
F_21 ( V_3 , L_3 , V_81 , V_28 . V_39 ,
V_28 . V_33 , V_28 . V_34 [ 0 ] ) ;
V_72 = F_22 ( V_28 . V_34 [ 0 ] * V_28 . V_33 ) ;
F_8 ( ! V_72 ) ;
F_21 ( V_3 ,
L_4 ,
F_23 ( V_18 ) ,
F_24 ( V_18 ) ,
V_18 -> V_82 ,
V_72 ) ;
V_32 = V_28 . V_34 [ 0 ] * V_28 . V_33 ;
V_5 = F_25 ( & V_26 -> V_83 ) ;
if ( F_26 ( V_5 ) ) {
V_30 = F_27 ( V_5 ) ;
goto V_43;
}
V_5 -> V_54 = V_26 ;
F_28 ( & V_3 -> V_84 , & V_26 -> V_55 , & V_28 , V_16 ,
& V_85 ) ;
V_45 = & V_26 -> V_55 . V_56 ;
V_26 -> V_83 . V_45 = V_45 ;
V_26 -> V_72 = V_72 ;
strcpy ( V_5 -> V_9 . V_86 , L_5 ) ;
F_29 ( V_5 , V_45 -> V_34 [ 0 ] , V_45 -> V_41 -> V_13 ) ;
V_5 -> V_87 = & V_88 ;
V_5 -> V_9 . V_89 = V_3 -> V_90 ;
V_5 -> V_9 . V_91 = V_16 -> V_32 ;
V_5 -> V_92 = V_26 -> V_72 ;
V_5 -> V_93 = V_16 -> V_32 ;
F_30 ( V_5 , & V_26 -> V_83 , V_74 -> V_94 ,
V_74 -> V_95 ) ;
V_5 -> V_96 -> V_97 [ 0 ] . V_56 = V_3 -> V_84 . V_98 . V_99 ;
V_5 -> V_96 -> V_97 [ 0 ] . V_32 = V_3 -> V_100 ;
V_5 -> V_9 . V_101 = 0 ;
V_5 -> V_9 . V_102 = 0 ;
if ( V_5 -> V_92 == NULL ) {
V_30 = - V_103 ;
goto V_43;
}
#ifdef F_31
V_5 -> V_104 = & V_105 ;
F_32 ( V_5 ) ;
#endif
V_3 -> V_53 = V_5 ;
V_3 -> V_23 = & V_26 -> V_55 ;
F_33 ( L_6 , V_5 -> V_9 . V_89 , ( unsigned long ) V_5 -> V_93 ) ;
F_33 ( L_7 ,
V_45 -> V_41 -> V_13 , V_45 -> V_34 [ 0 ] , V_45 -> V_39 , V_45 -> V_33 ) ;
return 0 ;
V_43:
if ( V_18 ) {
F_4 ( V_18 ) ;
F_5 ( V_18 ) ;
}
if ( V_45 && V_30 ) {
F_6 ( V_16 ) ;
F_34 ( V_45 ) ;
F_35 ( V_45 ) ;
}
F_6 ( V_16 ) ;
return V_30 ;
}
static int F_36 (
struct V_106 * V_83 ,
struct V_73 * V_74 )
{
struct V_25 * V_26 =
F_37 ( V_83 , struct V_25 , V_83 ) ;
int V_107 = 0 ;
int V_30 ;
if ( ! V_83 -> V_45 ) {
V_30 = F_19 ( V_26 , V_74 ) ;
if ( V_30 )
return V_30 ;
V_107 = 1 ;
}
return V_107 ;
}
static int F_38 ( struct V_108 * V_51 , struct V_25 * V_26 )
{
struct V_109 * V_55 = & V_26 -> V_55 ;
F_39 ( & V_26 -> V_83 ) ;
if ( V_55 -> V_24 ) {
F_2 ( V_55 -> V_24 ) ;
V_55 -> V_24 = NULL ;
}
F_40 ( & V_26 -> V_83 ) ;
F_41 ( V_26 -> V_72 ) ;
F_34 ( & V_55 -> V_56 ) ;
return 0 ;
}
int F_42 ( struct V_2 * V_3 )
{
int V_30 = 0 ;
#ifdef F_31
struct V_25 * V_26 ;
int V_110 = 32 ;
V_26 = F_43 ( sizeof( struct V_25 ) , V_111 ) ;
if ( ! V_26 )
return - V_37 ;
V_26 -> V_3 = V_3 ;
V_3 -> V_112 . V_26 = V_26 ;
F_44 ( & V_26 -> V_113 ) ;
F_45 ( & V_26 -> V_114 ) ;
F_46 ( & V_3 -> V_84 , & V_26 -> V_83 ,
& V_115 ) ;
V_30 = F_47 ( & V_3 -> V_84 , & V_26 -> V_83 ,
V_116 ) ;
if ( V_30 )
goto free;
V_30 = F_48 ( & V_26 -> V_83 ) ;
if ( V_30 )
goto V_117;
V_30 = F_49 ( & V_26 -> V_83 , V_110 ) ;
if ( V_30 )
goto V_117;
return 0 ;
V_117:
F_40 ( & V_26 -> V_83 ) ;
free:
F_35 ( V_26 ) ;
#endif
return V_30 ;
}
void F_50 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_112 . V_26 )
return;
F_38 ( & V_3 -> V_84 , V_3 -> V_112 . V_26 ) ;
F_35 ( V_3 -> V_112 . V_26 ) ;
V_3 -> V_112 . V_26 = NULL ;
}
void F_51 ( struct V_2 * V_3 , int V_118 )
{
if ( ! V_3 -> V_112 . V_26 )
return;
F_52 ( & V_3 -> V_112 . V_26 -> V_83 , V_118 ) ;
}
bool F_53 ( struct V_2 * V_3 , struct V_17 * V_119 )
{
if ( V_119 == F_3 ( V_3 -> V_112 . V_26 -> V_55 . V_24 ) )
return true ;
return false ;
}
