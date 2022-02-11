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
V_47 -> V_51 = F_28 ( 0 , 0 , 1 ) ;
V_47 -> V_52 = V_53 | V_54 ;
return 0 ;
}
static int F_29 ( struct V_23 * V_23 , void * V_45 ,
struct V_55 * V_56 )
{
struct V_57 V_58 = {} ;
int V_3 , V_4 , V_59 = 5 ;
struct V_1 * V_2 = V_23 -> V_38 ;
if ( V_56 -> V_60 != 0 )
return - V_61 ;
V_56 -> type = V_62 ;
V_56 -> V_63 = V_64 ;
V_56 -> V_65 = V_21 / 62500 ;
V_56 -> V_66 = V_67 / 62500 ;
V_56 -> V_68 = V_69 ;
V_56 -> V_70 = V_71 ;
V_56 -> signal = 0 ;
V_56 -> V_72 = 0 ;
F_17 ( & V_2 -> V_27 ) ;
V_3 = F_30 ( V_2 , V_73 , V_10 ,
& V_58 , & V_4 , sizeof( V_58 ) ) ;
while ( V_58 . V_74 && V_59 -- && ! V_3 ) {
F_2 ( V_5 ) ;
F_3 ( V_6 ) ;
V_3 = F_30 ( V_2 , V_73 , V_10 ,
& V_58 , & V_4 , sizeof( V_58 ) ) ;
}
F_22 ( & V_2 -> V_27 ) ;
if ( V_3 || V_4 ) {
V_56 -> signal = 0 ;
} else if ( ( V_58 . V_75 || V_58 . V_76 )
&& V_58 . V_77 == 0 ) {
V_56 -> signal = 0xffff ;
} else
V_56 -> signal = ( V_58 . V_77 * 255 / 10 ) << 8 ;
return 0 ;
}
static int F_31 ( struct V_23 * V_23 , void * V_45 ,
struct V_78 * V_79 )
{
struct V_1 * V_2 = V_23 -> V_38 ;
V_79 -> V_80 = V_2 -> V_14 . V_22 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_3 V_80 )
{
T_3 V_81 ;
int V_3 , V_4 ;
F_17 ( & V_2 -> V_27 ) ;
V_3 = F_6 ( V_2 , V_13 ,
V_2 -> V_14 . V_15 , & V_4 ) ;
V_81 = ( V_80 * 125 ) * 500 / 1000 ;
if ( V_81 < V_21 / 1000 || V_81 > V_67 / 1000 ) {
V_3 = - V_61 ;
goto error;
}
V_3 = F_6 ( V_2 , V_20 , V_81 , & V_4 ) ;
if ( V_3 < 0 )
goto error ;
V_3 = F_6 ( V_2 , V_82 , 0 , & V_4 ) ;
F_2 ( V_5 ) ;
F_3 ( V_6 / 4 ) ;
if ( ! V_2 -> V_14 . V_40 ) {
V_3 = F_6 ( V_2 , V_82 , 0 , & V_4 ) ;
V_3 = F_6 ( V_2 , V_42 ,
V_83 , & V_4 ) ;
V_2 -> V_14 . V_40 = 1 ;
}
V_2 -> V_14 . V_22 = V_80 ;
error:
F_22 ( & V_2 -> V_27 ) ;
return V_3 ;
}
static int F_32 ( struct V_23 * V_23 , void * V_45 ,
struct V_78 * V_79 )
{
struct V_1 * V_2 = V_23 -> V_38 ;
V_2 -> V_41 = V_23 ;
#ifdef F_33
V_2 -> V_84 = F_7 ;
V_2 -> V_85 = F_11 ;
#endif
return F_12 ( V_2 , V_79 -> V_80 ) ;
}
static int F_34 ( struct V_23 * V_23 , void * V_45 ,
struct V_86 * V_87 )
{
return 0 ;
}
static int F_35 ( struct V_23 * V_23 , void * V_88 ,
struct V_89 * V_90 )
{
struct V_1 * V_2 = V_23 -> V_38 ;
int V_91 ;
if ( V_90 -> V_92 != V_93 )
return - V_61 ;
for ( V_91 = 0 ; V_91 < V_90 -> V_59 ; V_91 ++ ) {
struct V_94 * V_95 = V_90 -> V_96 + V_91 ;
if ( V_95 -> V_97 != V_98 )
continue;
if ( V_91 < V_99 )
V_95 -> V_100 = V_2 -> V_14 . V_15 ;
}
return 0 ;
}
static int F_36 ( struct V_23 * V_23 , void * V_88 ,
struct V_89 * V_90 )
{
int V_91 ;
if ( V_90 -> V_92 != V_93 )
return - V_61 ;
for ( V_91 = 0 ; V_91 < V_90 -> V_59 ; V_91 ++ ) {
struct V_94 * V_95 = V_90 -> V_96 + V_91 ;
if ( V_95 -> V_97 != V_98 )
continue;
if ( V_95 -> V_100 >= 0 && V_95 -> V_100 < V_99 ) {
struct V_1 * V_2 = V_23 -> V_38 ;
int V_15 = V_101 [ V_95 -> V_100 ] ;
T_1 V_4 ;
F_6 ( V_2 , V_13 ,
V_15 , & V_4 ) ;
V_2 -> V_14 . V_15 = V_15 ;
}
}
return 0 ;
}
static int F_37 ( struct V_23 * V_23 , void * V_45 ,
struct V_86 * V_95 )
{
return 0 ;
}
static int F_38 ( struct V_23 * V_23 , void * V_45 ,
struct V_102 * V_95 )
{
if ( ! ( V_95 -> V_97 & V_103 ) )
return - V_61 ;
V_95 -> V_97 &= ~ V_103 ;
if ( V_95 -> V_97 != V_98 ) {
V_95 -> V_97 = V_98 ;
F_39 ( V_95 , V_104 ,
V_105 , 1 ,
V_106 ) ;
V_95 -> V_107 = V_108 ;
return 0 ;
}
return - V_61 ;
}
static int F_40 ( struct V_23 * V_23 , void * V_88 ,
struct V_109 * V_110 )
{
return F_41 ( V_110 , NULL , NULL ) ;
}
static int F_42 ( struct V_23 * V_23 , void * V_45 , struct V_55 * V_56 )
{
return V_56 -> V_60 > 0 ? - V_61 : 0 ;
}
static int F_43 ( struct V_23 * V_23 , void * V_45 , struct V_111 * V_112 )
{
return ( V_112 -> V_60 != 0 ) ? - V_61 : 0 ;
}
static int F_44 ( struct V_23 * V_23 , void * V_45 , struct V_111 * V_113 )
{
V_113 -> V_60 = 0 ;
V_113 -> V_114 = 0 ;
V_113 -> V_63 = V_115 ;
strcpy ( V_113 -> V_116 , L_3 ) ;
return 0 ;
}
static int F_45 ( struct V_23 * V_24 , void * V_45 , T_1 V_91 )
{
return ( V_91 != 0 ) ? - V_61 : 0 ;
}
static int F_46 ( struct V_23 * V_24 , void * V_45 , T_1 * V_91 )
{
return ( * V_91 != 0 ) ? - V_61 : 0 ;
}
int F_47 ( struct V_1 * V_2 )
{
struct V_25 * V_117 ;
V_117 = F_48 ( V_2 , & V_118 ) ;
if ( V_117 == NULL )
return - 1 ;
if ( F_49 ( V_117 , V_119 , - 1 ) < 0 ) {
F_50 ( V_117 ) ;
return - 1 ;
}
V_2 -> V_14 . V_117 = V_117 ;
return 0 ;
}
int F_51 ( struct V_1 * V_2 )
{
F_52 ( & V_2 -> V_14 . V_117 ) ;
return 0 ;
}
