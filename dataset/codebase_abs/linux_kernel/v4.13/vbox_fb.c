static void F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 , int V_5 , int V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_11 = - V_12 ;
bool V_13 = false ;
int V_14 , V_15 ;
unsigned long V_16 ;
struct V_17 V_18 ;
V_8 = V_2 -> V_19 . V_8 ;
V_10 = F_2 ( V_8 ) ;
if ( F_3 () )
V_11 = F_4 ( V_10 , true ) ;
if ( V_11 ) {
if ( V_11 != - V_12 )
return;
V_13 = true ;
}
V_14 = V_3 + V_5 - 1 ;
V_15 = V_4 + V_6 - 1 ;
F_5 ( & V_2 -> V_20 , V_16 ) ;
if ( V_2 -> y1 < V_4 )
V_4 = V_2 -> y1 ;
if ( V_2 -> V_15 > V_15 )
V_15 = V_2 -> V_15 ;
if ( V_2 -> V_21 < V_3 )
V_3 = V_2 -> V_21 ;
if ( V_2 -> V_14 > V_14 )
V_14 = V_2 -> V_14 ;
if ( V_13 ) {
V_2 -> V_21 = V_3 ;
V_2 -> V_14 = V_14 ;
V_2 -> y1 = V_4 ;
V_2 -> V_15 = V_15 ;
F_6 ( & V_2 -> V_20 , V_16 ) ;
return;
}
V_2 -> V_21 = V_22 ;
V_2 -> y1 = V_22 ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = 0 ;
F_6 ( & V_2 -> V_20 , V_16 ) ;
V_18 . V_21 = V_3 ;
V_18 . V_14 = V_14 + 1 ;
V_18 . y1 = V_4 ;
V_18 . V_15 = V_15 + 1 ;
F_7 ( & V_2 -> V_19 . V_23 , & V_18 , 1 ) ;
F_8 ( V_10 ) ;
}
static void F_9 ( struct V_24 * V_25 , struct V_26 * V_27 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
unsigned long V_29 , V_30 , V_31 , V_32 ;
struct V_33 * V_33 ;
int y1 , V_15 ;
V_31 = V_34 ;
V_32 = 0 ;
F_10 (page, pagelist, lru) {
V_29 = V_33 -> V_35 << V_36 ;
V_30 = V_29 + V_37 - 1 ;
V_31 = V_31 ( V_31 , V_29 ) ;
V_32 = V_32 ( V_32 , V_30 ) ;
}
if ( V_31 < V_32 ) {
y1 = V_31 / V_25 -> V_38 . V_39 ;
V_15 = ( V_32 / V_25 -> V_38 . V_39 ) + 1 ;
F_11 ( L_1 ,
V_40 , y1 , V_25 -> V_41 . V_42 , V_15 - y1 - 1 ) ;
F_1 ( V_2 , 0 , y1 , V_25 -> V_41 . V_42 , V_15 - y1 - 1 ) ;
}
}
static void F_12 ( struct V_24 * V_25 , const struct V_43 * V_18 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
F_13 ( V_25 , V_18 ) ;
F_1 ( V_2 , V_18 -> V_44 , V_18 -> V_45 , V_18 -> V_5 , V_18 -> V_6 ) ;
}
static void F_14 ( struct V_24 * V_25 , const struct V_46 * V_47 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
F_15 ( V_25 , V_47 ) ;
F_1 ( V_2 , V_47 -> V_44 , V_47 -> V_45 , V_47 -> V_5 , V_47 -> V_6 ) ;
}
static void F_16 ( struct V_24 * V_25 , const struct V_48 * V_49 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
F_17 ( V_25 , V_49 ) ;
F_1 ( V_2 , V_49 -> V_44 , V_49 -> V_45 , V_49 -> V_5 ,
V_49 -> V_6 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_50 * V_51 ,
struct V_7 * * V_52 )
{
struct V_53 * V_54 = V_2 -> V_55 . V_54 ;
T_1 V_56 ;
struct V_7 * V_57 ;
T_1 V_58 = V_51 -> V_59 [ 0 ] ;
int V_11 ;
V_56 = V_58 * V_51 -> V_6 ;
V_11 = F_19 ( V_54 , V_56 , true , & V_57 ) ;
if ( V_11 )
return V_11 ;
* V_52 = V_57 ;
return 0 ;
}
static int F_20 ( struct V_60 * V_55 ,
struct V_61 * V_62 )
{
struct V_1 * V_2 =
F_21 ( V_55 , struct V_1 , V_55 ) ;
struct V_53 * V_54 = V_2 -> V_55 . V_54 ;
struct V_50 V_51 ;
struct V_63 * V_64 ;
struct V_24 * V_25 ;
struct V_65 * V_65 = & V_54 -> V_66 -> V_54 ;
struct V_7 * V_57 ;
struct V_9 * V_10 ;
int V_56 , V_11 ;
T_1 V_58 ;
V_51 . V_5 = V_62 -> V_67 ;
V_51 . V_6 = V_62 -> V_68 ;
V_58 = V_51 . V_5 * ( ( V_62 -> V_69 + 7 ) / 8 ) ;
V_51 . V_70 = F_22 ( V_62 -> V_69 ,
V_62 -> V_71 ) ;
V_51 . V_59 [ 0 ] = V_58 ;
V_56 = V_58 * V_51 . V_6 ;
V_11 = F_18 ( V_2 , & V_51 , & V_57 ) ;
if ( V_11 ) {
F_23 ( L_2 , V_11 ) ;
return V_11 ;
}
V_11 = F_24 ( V_54 , & V_2 -> V_19 , & V_51 , V_57 ) ;
if ( V_11 )
return V_11 ;
V_10 = F_2 ( V_57 ) ;
V_11 = F_4 ( V_10 , false ) ;
if ( V_11 )
return V_11 ;
V_11 = F_25 ( V_10 , V_72 , NULL ) ;
if ( V_11 ) {
F_8 ( V_10 ) ;
return V_11 ;
}
V_11 = F_26 ( & V_10 -> V_10 , 0 , V_10 -> V_10 . V_73 , & V_10 -> V_74 ) ;
F_8 ( V_10 ) ;
if ( V_11 ) {
F_23 ( L_3 ) ;
return V_11 ;
}
V_25 = F_27 ( 0 , V_65 ) ;
if ( ! V_25 )
return - V_75 ;
V_25 -> V_28 = V_2 ;
V_2 -> V_56 = V_56 ;
V_64 = & V_2 -> V_19 . V_23 ;
V_2 -> V_55 . V_64 = V_64 ;
V_2 -> V_55 . V_2 = V_25 ;
strcpy ( V_25 -> V_38 . V_76 , L_4 ) ;
V_25 -> V_16 = V_77 | V_78 |
V_79 ;
V_25 -> V_80 = & V_81 ;
V_11 = F_28 ( & V_25 -> V_82 , 256 , 0 ) ;
if ( V_11 )
return - V_75 ;
V_25 -> V_83 = F_29 ( 1 ) ;
if ( ! V_25 -> V_83 )
return - V_75 ;
V_25 -> V_83 -> V_84 [ 0 ] . V_23 = F_30 ( V_54 -> V_66 , 0 ) ;
V_25 -> V_83 -> V_84 [ 0 ] . V_56 = F_31 ( V_54 -> V_66 , 0 ) ;
F_32 ( V_25 , V_64 -> V_59 [ 0 ] , V_64 -> V_85 -> V_86 ) ;
F_33 ( V_25 , & V_2 -> V_55 , V_62 -> V_87 ,
V_62 -> V_88 ) ;
V_25 -> V_89 = V_10 -> V_74 . V_90 ;
V_25 -> V_91 = V_56 ;
#ifdef F_34
V_25 -> V_92 = & V_93 ;
F_35 ( V_25 ) ;
#endif
V_25 -> V_94 . V_16 = V_95 ;
F_36 ( L_5 , V_64 -> V_5 , V_64 -> V_6 ) ;
return 0 ;
}
static void F_37 ( struct V_96 * V_97 , T_2 V_98 , T_2 V_99 ,
T_2 V_100 , int V_101 )
{
}
static void F_38 ( struct V_96 * V_97 , T_2 * V_98 , T_2 * V_99 ,
T_2 * V_100 , int V_101 )
{
* V_98 = V_101 ;
* V_99 = V_101 ;
* V_100 = V_101 ;
}
void F_39 ( struct V_53 * V_54 )
{
struct V_102 * V_103 = V_54 -> V_104 ;
struct V_1 * V_2 = V_103 -> V_2 ;
struct V_105 * V_19 = & V_2 -> V_19 ;
F_40 ( & V_2 -> V_55 ) ;
if ( V_19 -> V_8 ) {
struct V_9 * V_10 = F_2 ( V_19 -> V_8 ) ;
if ( ! F_4 ( V_10 , false ) ) {
if ( V_10 -> V_74 . V_90 )
F_41 ( & V_10 -> V_74 ) ;
if ( V_10 -> V_106 )
F_42 ( V_10 ) ;
F_8 ( V_10 ) ;
}
F_43 ( V_19 -> V_8 ) ;
V_19 -> V_8 = NULL ;
}
F_44 ( & V_2 -> V_55 ) ;
F_45 ( & V_19 -> V_23 ) ;
F_46 ( & V_19 -> V_23 ) ;
}
int F_47 ( struct V_53 * V_54 )
{
struct V_102 * V_103 = V_54 -> V_104 ;
struct V_1 * V_2 ;
int V_11 ;
V_2 = F_48 ( V_54 -> V_54 , sizeof( * V_2 ) , V_107 ) ;
if ( ! V_2 )
return - V_75 ;
V_103 -> V_2 = V_2 ;
F_49 ( & V_2 -> V_20 ) ;
F_50 ( V_54 , & V_2 -> V_55 , & V_108 ) ;
V_11 = F_51 ( V_54 , & V_2 -> V_55 , V_103 -> V_109 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_52 ( & V_2 -> V_55 ) ;
if ( V_11 )
goto V_110;
F_53 ( V_54 ) ;
V_11 = F_54 ( & V_2 -> V_55 , 32 ) ;
if ( V_11 )
goto V_110;
return 0 ;
V_110:
F_44 ( & V_2 -> V_55 ) ;
return V_11 ;
}
void F_55 ( struct V_102 * V_103 , unsigned long V_111 )
{
struct V_24 * V_2 = V_103 -> V_2 -> V_55 . V_2 ;
V_2 -> V_38 . V_112 = V_2 -> V_83 -> V_84 [ 0 ] . V_23 + V_111 ;
V_2 -> V_38 . V_113 = V_103 -> V_114 - V_111 ;
}
