static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 = NULL ;
unsigned long V_9 ;
int V_10 ;
if ( V_2 -> V_11 != F_3 ( V_12 ) )
goto V_13;
V_8 = F_4 ( 0 , V_14 ) ;
if ( ! V_8 )
goto V_13;
F_5 ( V_8 , V_6 -> V_15 , V_6 -> V_16 , V_2 -> V_17 , V_2 -> V_18 ,
V_19 , V_2 ) ;
V_8 -> V_20 = V_21 ;
V_10 = F_6 ( V_8 , V_14 ) ;
if ( V_10 ) {
F_7 ( V_8 ) ;
goto V_13;
}
F_8 ( & V_6 -> V_22 , V_9 ) ;
V_6 -> V_23 ++ ;
if ( V_6 -> V_23 >= V_4 -> V_24 )
F_9 ( V_4 ) ;
F_10 ( & V_6 -> V_22 , V_9 ) ;
return V_25 ;
V_13:
F_11 ( V_2 ) ;
V_4 -> V_26 . V_27 ++ ;
return V_25 ;
}
static void V_19 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_28 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_29 = V_8 -> V_29 ;
switch ( V_29 ) {
case 0 :
V_4 -> V_26 . V_30 += V_2 -> V_18 ;
break;
case - V_31 :
case - V_32 :
case - V_33 :
V_4 -> V_26 . V_34 ++ ;
default:
V_4 -> V_26 . V_35 ++ ;
F_12 ( & V_4 -> V_4 , L_1 , V_29 ) ;
}
V_4 -> V_26 . V_36 ++ ;
F_13 ( & V_6 -> V_22 ) ;
V_6 -> V_23 -- ;
F_14 ( V_4 ) ;
F_15 ( & V_6 -> V_22 ) ;
F_16 ( V_2 ) ;
F_7 ( V_8 ) ;
}
static int F_17 ( struct V_5 * V_6 , struct V_7 * V_8 , T_2 V_37 )
{
struct V_3 * V_4 = V_6 -> V_4 ;
struct V_38 * V_38 ;
int V_10 ;
V_38 = F_18 ( V_4 , V_37 ) ;
if ( ! V_38 )
return - V_39 ;
F_5 ( V_8 , V_6 -> V_15 , V_6 -> V_40 , F_19 ( V_38 ) ,
V_41 , V_42 , V_4 ) ;
V_8 -> V_20 = 0 ;
V_10 = F_6 ( V_8 , V_37 ) ;
if ( F_20 ( V_10 ) ) {
F_12 ( & V_4 -> V_4 , L_2 , V_10 ) ;
F_21 ( V_4 , V_38 ) ;
}
return V_10 ;
}
static void V_42 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = V_8 -> V_28 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_38 * V_38 = F_22 ( V_8 -> V_43 ) ;
struct V_1 * V_2 ;
unsigned long V_9 ;
int V_29 = V_8 -> V_29 ;
switch ( V_29 ) {
case 0 :
F_8 ( & V_6 -> V_44 , V_9 ) ;
V_2 = V_6 -> V_45 ;
if ( ! V_2 ) {
V_2 = V_6 -> V_45 = F_23 ( V_4 , 12 ) ;
if ( F_24 ( V_2 ) ) {
memcpy ( F_25 ( V_2 , 1 ) , F_19 ( V_38 ) , 1 ) ;
F_26 ( V_2 , F_27 ( V_2 ) -> V_46 ,
V_38 , 1 , V_8 -> V_47 ) ;
V_38 = NULL ;
}
} else {
F_26 ( V_2 , F_27 ( V_2 ) -> V_46 ,
V_38 , 0 , V_8 -> V_47 ) ;
V_38 = NULL ;
}
if ( V_8 -> V_47 < V_41 )
V_6 -> V_45 = NULL ;
else
V_2 = NULL ;
F_10 ( & V_6 -> V_44 , V_9 ) ;
if ( V_2 ) {
V_2 -> V_11 = F_3 ( V_12 ) ;
F_28 ( V_2 ) ;
F_29 ( V_2 , 1 ) ;
V_2 -> V_4 = V_4 ;
V_4 -> V_26 . V_48 ++ ;
V_4 -> V_26 . V_49 += V_2 -> V_18 ;
F_30 ( V_2 ) ;
}
goto V_50;
case - V_31 :
case - V_32 :
case - V_33 :
V_8 = NULL ;
break;
case - V_51 :
V_4 -> V_26 . V_52 ++ ;
F_12 ( & V_4 -> V_4 , L_3 ) ;
break;
case - V_53 :
V_4 -> V_26 . V_54 ++ ;
break;
}
V_4 -> V_26 . V_55 ++ ;
V_50:
if ( V_38 )
F_21 ( V_4 , V_38 ) ;
if ( V_8 )
F_17 ( V_6 , V_8 , V_14 ) ;
}
static int F_31 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_10 ;
unsigned V_56 ;
unsigned V_57 = V_6 -> V_58 -> V_59 -> V_60 . V_61 ;
V_10 = F_32 ( V_6 -> V_15 , V_57 , V_6 -> V_62 ) ;
if ( V_10 )
return V_10 ;
for ( V_56 = 0 ; V_56 < V_63 ; V_56 ++ ) {
struct V_7 * V_8 = F_4 ( 0 , V_64 ) ;
if ( ! V_8 || F_17 ( V_6 , V_8 , V_64 ) ) {
F_33 ( V_4 ) ;
return - V_39 ;
}
V_6 -> V_65 [ V_56 ] = V_8 ;
}
F_14 ( V_4 ) ;
return 0 ;
}
static int F_33 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
unsigned V_56 ;
unsigned V_57 = V_6 -> V_58 -> V_59 -> V_60 . V_61 ;
F_9 ( V_4 ) ;
for ( V_56 = 0 ; V_56 < V_63 ; V_56 ++ ) {
struct V_7 * V_8 = V_6 -> V_65 [ V_56 ] ;
if ( ! V_8 )
continue;
F_34 ( V_8 ) ;
F_7 ( V_8 ) ;
V_6 -> V_65 [ V_56 ] = NULL ;
}
return F_32 ( V_6 -> V_15 , V_57 , ! V_6 -> V_62 ) ;
}
static int F_35 ( struct V_3 * V_4 , struct V_66 * V_67 , int V_68 )
{
struct V_69 * V_8 = (struct V_69 * ) V_67 ;
switch ( V_68 ) {
case V_70 :
V_8 -> V_71 . V_72 = V_73 ;
return 0 ;
}
return - V_74 ;
}
static int F_36 ( struct V_3 * V_4 , int V_75 )
{
if ( ( V_75 < V_76 ) || ( V_75 > V_77 ) )
return - V_78 ;
V_4 -> V_79 = V_75 ;
return 0 ;
}
static void F_37 ( struct V_3 * V_4 )
{
V_4 -> V_80 = 0 ;
V_4 -> V_81 = & V_82 ,
V_4 -> V_83 = & V_84 ;
V_4 -> type = V_85 ;
V_4 -> V_9 = V_86 | V_87 ;
V_4 -> V_79 = V_77 ;
V_4 -> V_88 = 1 ;
V_4 -> V_89 [ 0 ] = V_90 ;
V_4 -> V_91 = 1 ;
V_4 -> V_24 = 3 ;
V_4 -> V_92 = V_93 ;
}
int F_38 ( struct V_94 * V_95 , const struct V_96 * V_97 )
{
static const char V_98 [] = L_4 ;
const struct V_99 * V_100 = NULL ;
const struct V_101 * V_102 ;
struct V_94 * V_58 ;
struct V_103 * V_104 = F_39 ( V_95 ) ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
T_3 * V_17 ;
int V_105 = 0 ;
int V_18 , V_10 ;
V_17 = V_95 -> V_106 -> V_107 ;
V_18 = V_95 -> V_106 -> V_108 ;
while ( V_18 >= 3 ) {
T_3 V_109 = V_17 [ 0 ] ;
if ( V_109 < 3 )
return - V_78 ;
if ( V_17 [ 1 ] == V_110 ) {
switch ( V_17 [ 2 ] ) {
case V_111 :
if ( V_100 || V_109 < 5 )
break;
V_100 =
(struct V_99 * ) V_17 ;
break;
case 0xAB :
V_105 = 1 ;
break;
}
}
V_17 += V_109 ;
V_18 -= V_109 ;
}
if ( ! V_100 || ! V_105 )
return - V_78 ;
V_58 = F_40 ( V_104 , V_100 -> V_112 ) ;
if ( V_58 == NULL )
return - V_113 ;
if ( V_58 -> V_114 != 2 )
return - V_78 ;
if ( V_58 -> V_106 [ 0 ] . V_60 . V_115 == 0 &&
V_58 -> V_106 [ 1 ] . V_60 . V_115 == 2 )
V_102 = V_58 -> V_106 + 1 ;
else
if ( V_58 -> V_106 [ 0 ] . V_60 . V_115 == 2 &&
V_58 -> V_106 [ 1 ] . V_60 . V_115 == 0 )
V_102 = V_58 -> V_106 ;
else
return - V_78 ;
V_4 = F_41 ( sizeof( * V_6 ) + sizeof( V_6 -> V_65 [ 0 ] ) * V_63 ,
V_98 , F_37 ) ;
if ( ! V_4 )
return - V_39 ;
V_6 = F_2 ( V_4 ) ;
F_42 ( V_4 , & V_95 -> V_4 ) ;
V_6 -> V_4 = V_4 ;
V_6 -> V_15 = F_43 ( V_104 ) ;
V_6 -> V_95 = V_95 ;
V_6 -> V_58 = V_58 ;
F_44 ( & V_6 -> V_22 ) ;
F_44 ( & V_6 -> V_44 ) ;
if ( F_45 ( V_102 -> V_116 [ 0 ] . V_60 . V_117 ) ) {
V_6 -> V_40 = F_46 ( V_104 ,
V_102 -> V_116 [ 0 ] . V_60 . V_117 ) ;
V_6 -> V_16 = F_47 ( V_104 ,
V_102 -> V_116 [ 1 ] . V_60 . V_117 ) ;
} else {
V_6 -> V_40 = F_46 ( V_104 ,
V_102 -> V_116 [ 1 ] . V_60 . V_117 ) ;
V_6 -> V_16 = F_47 ( V_104 ,
V_102 -> V_116 [ 0 ] . V_60 . V_117 ) ;
}
V_6 -> V_62 = V_102 - V_58 -> V_106 ;
V_10 = F_48 ( & V_118 , V_58 , V_6 ) ;
if ( V_10 )
goto V_119;
F_32 ( V_104 , V_100 -> V_112 ,
! V_6 -> V_62 ) ;
F_49 ( V_95 , V_6 ) ;
V_10 = F_50 ( V_4 ) ;
if ( V_10 ) {
F_51 ( & V_118 , V_58 ) ;
goto V_119;
}
F_12 ( & V_4 -> V_4 , L_5 ) ;
return 0 ;
V_119:
F_49 ( V_95 , NULL ) ;
V_93 ( V_4 ) ;
return V_10 ;
}
static void F_52 ( struct V_94 * V_95 )
{
struct V_5 * V_6 = F_53 ( V_95 ) ;
struct V_103 * V_15 = V_6 -> V_15 ;
if ( V_6 -> V_120 )
return;
V_6 -> V_120 = 1 ;
F_51 ( & V_118 ,
( V_6 -> V_95 == V_95 ) ? V_6 -> V_58 : V_6 -> V_95 ) ;
F_54 ( V_6 -> V_4 ) ;
F_55 ( V_15 ) ;
}
static int T_4 F_56 ( void )
{
return F_57 ( & V_118 ) ;
}
static void T_5 F_58 ( void )
{
F_59 ( & V_118 ) ;
}
