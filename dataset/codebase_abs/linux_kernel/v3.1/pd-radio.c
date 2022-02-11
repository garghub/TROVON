static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
F_2 ( V_5 ) ;
F_3 ( V_6 / 2 ) ;
V_3 = F_4 ( V_2 -> V_7 , 0 , V_8 ) ;
if ( V_3 < 0 )
goto V_9;
V_3 = F_5 ( V_2 , V_10 ) ;
if ( V_3 != 0 )
goto V_9;
V_3 = F_6 ( V_2 , V_11 , V_12 , & V_4 ) ;
V_3 = F_6 ( V_2 , V_13 ,
V_2 -> V_14 . V_15 , & V_4 ) ;
V_3 |= F_6 ( V_2 , V_16 ,
V_17 , & V_4 ) ;
V_3 |= F_6 ( V_2 , V_18 ,
V_19 , & V_4 ) ;
V_3 |= F_6 ( V_2 , V_20 , V_21 , & V_4 ) ;
V_9:
return V_3 ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
F_4 ( V_2 -> V_7 , 0 , 0 ) ;
F_10 ( 300 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
F_1 ( V_2 ) ;
F_12 ( V_2 , V_2 -> V_14 . V_22 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
static int F_14 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = F_15 ( V_24 ) ;
struct V_1 * V_2 = F_16 ( V_26 ) ;
int V_3 = 0 ;
if ( ! V_2 )
return - 1 ;
F_17 ( & V_2 -> V_27 ) ;
if ( V_2 -> V_28 & V_29 ) {
V_3 = - V_30 ;
goto V_9;
}
if ( V_2 -> V_28 && ! ( V_2 -> V_28 & V_31 ) ) {
V_3 = - V_32 ;
goto V_9;
}
F_18 ( V_2 -> V_33 ) ;
if ( 0 == V_2 -> V_28 ) {
if ( V_2 -> V_14 . V_15 == 0 )
V_2 -> V_14 . V_15 = V_34 ;
F_19 ( V_26 , V_35 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 ) {
F_20 ( V_2 -> V_33 ) ;
goto V_9;
}
V_2 -> V_28 |= V_31 ;
}
V_2 -> V_14 . V_36 ++ ;
F_21 ( & V_2 -> V_37 ) ;
V_24 -> V_38 = V_2 ;
V_9:
F_22 ( & V_2 -> V_27 ) ;
return V_3 ;
}
static int F_23 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_38 ;
struct V_14 * V_39 = & V_2 -> V_14 ;
T_2 V_4 ;
F_17 ( & V_2 -> V_27 ) ;
V_39 -> V_36 -- ;
if ( 0 == V_39 -> V_36 )
V_2 -> V_28 &= ~ V_31 ;
if ( V_39 -> V_40 && V_24 == V_2 -> V_41 ) {
V_39 -> V_40 = 0 ;
F_6 ( V_2 , V_42 , V_43 , & V_4 ) ;
}
F_20 ( V_2 -> V_33 ) ;
F_22 ( & V_2 -> V_27 ) ;
F_24 ( & V_2 -> V_37 , V_44 ) ;
V_24 -> V_38 = NULL ;
return 0 ;
}
static int F_25 ( struct V_23 * V_23 , void * V_45 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = V_23 -> V_38 ;
F_26 ( V_47 -> V_48 , L_1 , sizeof( V_47 -> V_48 ) ) ;
F_26 ( V_47 -> V_49 , L_2 , sizeof( V_47 -> V_49 ) ) ;
F_27 ( V_2 -> V_7 , V_47 -> V_50 , sizeof( V_47 -> V_50 ) ) ;
V_47 -> V_51 = V_52 | V_53 ;
return 0 ;
}
static int F_28 ( struct V_23 * V_23 , void * V_45 ,
struct V_54 * V_55 )
{
struct V_56 V_57 = {} ;
int V_3 , V_4 , V_58 = 5 ;
struct V_1 * V_2 = V_23 -> V_38 ;
if ( V_55 -> V_59 != 0 )
return - V_60 ;
V_55 -> type = V_61 ;
V_55 -> V_62 = V_63 ;
V_55 -> V_64 = V_21 / 62500 ;
V_55 -> V_65 = V_66 / 62500 ;
V_55 -> V_67 = V_68 ;
V_55 -> V_69 = V_70 ;
V_55 -> signal = 0 ;
V_55 -> V_71 = 0 ;
F_17 ( & V_2 -> V_27 ) ;
V_3 = F_29 ( V_2 , V_72 , V_10 ,
& V_57 , & V_4 , sizeof( V_57 ) ) ;
while ( V_57 . V_73 && V_58 -- && ! V_3 ) {
F_2 ( V_5 ) ;
F_3 ( V_6 ) ;
V_3 = F_29 ( V_2 , V_72 , V_10 ,
& V_57 , & V_4 , sizeof( V_57 ) ) ;
}
F_22 ( & V_2 -> V_27 ) ;
if ( V_3 || V_4 ) {
V_55 -> signal = 0 ;
} else if ( ( V_57 . V_74 || V_57 . V_75 )
&& V_57 . V_76 == 0 ) {
V_55 -> signal = 0xffff ;
} else
V_55 -> signal = ( V_57 . V_76 * 255 / 10 ) << 8 ;
return 0 ;
}
static int F_30 ( struct V_23 * V_23 , void * V_45 ,
struct V_77 * V_78 )
{
struct V_1 * V_2 = V_23 -> V_38 ;
V_78 -> V_79 = V_2 -> V_14 . V_22 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_3 V_79 )
{
T_3 V_80 ;
int V_3 , V_4 ;
F_17 ( & V_2 -> V_27 ) ;
V_3 = F_6 ( V_2 , V_13 ,
V_2 -> V_14 . V_15 , & V_4 ) ;
V_80 = ( V_79 * 125 ) * 500 / 1000 ;
if ( V_80 < V_21 / 1000 || V_80 > V_66 / 1000 ) {
V_3 = - V_60 ;
goto error;
}
V_3 = F_6 ( V_2 , V_20 , V_80 , & V_4 ) ;
if ( V_3 < 0 )
goto error ;
V_3 = F_6 ( V_2 , V_81 , 0 , & V_4 ) ;
F_2 ( V_5 ) ;
F_3 ( V_6 / 4 ) ;
if ( ! V_2 -> V_14 . V_40 ) {
V_3 = F_6 ( V_2 , V_81 , 0 , & V_4 ) ;
V_3 = F_6 ( V_2 , V_42 ,
V_82 , & V_4 ) ;
V_2 -> V_14 . V_40 = 1 ;
}
V_2 -> V_14 . V_22 = V_79 ;
error:
F_22 ( & V_2 -> V_27 ) ;
return V_3 ;
}
static int F_31 ( struct V_23 * V_23 , void * V_45 ,
struct V_77 * V_78 )
{
struct V_1 * V_2 = V_23 -> V_38 ;
V_2 -> V_41 = V_23 ;
#ifdef F_32
V_2 -> V_83 = F_7 ;
V_2 -> V_84 = F_11 ;
#endif
return F_12 ( V_2 , V_78 -> V_79 ) ;
}
static int F_33 ( struct V_23 * V_23 , void * V_45 ,
struct V_85 * V_86 )
{
return 0 ;
}
static int F_34 ( struct V_23 * V_23 , void * V_87 ,
struct V_88 * V_89 )
{
struct V_1 * V_2 = V_23 -> V_38 ;
int V_90 ;
if ( V_89 -> V_91 != V_92 )
return - V_60 ;
for ( V_90 = 0 ; V_90 < V_89 -> V_58 ; V_90 ++ ) {
struct V_93 * V_94 = V_89 -> V_95 + V_90 ;
if ( V_94 -> V_96 != V_97 )
continue;
if ( V_90 < V_98 )
V_94 -> V_99 = V_2 -> V_14 . V_15 ;
}
return 0 ;
}
static int F_35 ( struct V_23 * V_23 , void * V_87 ,
struct V_88 * V_89 )
{
int V_90 ;
if ( V_89 -> V_91 != V_92 )
return - V_60 ;
for ( V_90 = 0 ; V_90 < V_89 -> V_58 ; V_90 ++ ) {
struct V_93 * V_94 = V_89 -> V_95 + V_90 ;
if ( V_94 -> V_96 != V_97 )
continue;
if ( V_94 -> V_99 >= 0 && V_94 -> V_99 < V_98 ) {
struct V_1 * V_2 = V_23 -> V_38 ;
int V_15 = V_100 [ V_94 -> V_99 ] ;
T_1 V_4 ;
F_6 ( V_2 , V_13 ,
V_15 , & V_4 ) ;
V_2 -> V_14 . V_15 = V_15 ;
}
}
return 0 ;
}
static int F_36 ( struct V_23 * V_23 , void * V_45 ,
struct V_85 * V_94 )
{
return 0 ;
}
static int F_37 ( struct V_23 * V_23 , void * V_45 ,
struct V_101 * V_94 )
{
if ( ! ( V_94 -> V_96 & V_102 ) )
return - V_60 ;
V_94 -> V_96 &= ~ V_102 ;
if ( V_94 -> V_96 != V_97 ) {
V_94 -> V_96 = V_97 ;
F_38 ( V_94 , V_103 ,
V_104 , 1 ,
V_105 ) ;
V_94 -> V_106 = V_107 ;
return 0 ;
}
return - V_60 ;
}
static int F_39 ( struct V_23 * V_23 , void * V_87 ,
struct V_108 * V_109 )
{
return F_40 ( V_109 , NULL , NULL ) ;
}
static int F_41 ( struct V_23 * V_23 , void * V_45 , struct V_54 * V_55 )
{
return V_55 -> V_59 > 0 ? - V_60 : 0 ;
}
static int F_42 ( struct V_23 * V_23 , void * V_45 , struct V_110 * V_111 )
{
return ( V_111 -> V_59 != 0 ) ? - V_60 : 0 ;
}
static int F_43 ( struct V_23 * V_23 , void * V_45 , struct V_110 * V_112 )
{
V_112 -> V_59 = 0 ;
V_112 -> V_113 = 0 ;
V_112 -> V_62 = V_114 ;
strcpy ( V_112 -> V_115 , L_3 ) ;
return 0 ;
}
static int F_44 ( struct V_23 * V_24 , void * V_45 , T_1 V_90 )
{
return ( V_90 != 0 ) ? - V_60 : 0 ;
}
static int F_45 ( struct V_23 * V_24 , void * V_45 , T_1 * V_90 )
{
return ( * V_90 != 0 ) ? - V_60 : 0 ;
}
int F_46 ( struct V_1 * V_2 )
{
struct V_25 * V_116 ;
V_116 = F_47 ( V_2 , & V_117 ) ;
if ( V_116 == NULL )
return - 1 ;
if ( F_48 ( V_116 , V_118 , - 1 ) < 0 ) {
F_49 ( V_116 ) ;
return - 1 ;
}
V_2 -> V_14 . V_116 = V_116 ;
return 0 ;
}
int F_50 ( struct V_1 * V_2 )
{
F_51 ( & V_2 -> V_14 . V_116 ) ;
return 0 ;
}
