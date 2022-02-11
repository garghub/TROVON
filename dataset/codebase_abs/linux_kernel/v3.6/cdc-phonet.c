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
V_38 = F_18 ( V_37 | V_39 , NULL ) ;
if ( ! V_38 )
return - V_40 ;
F_5 ( V_8 , V_6 -> V_15 , V_6 -> V_41 , F_19 ( V_38 ) ,
V_42 , V_43 , V_4 ) ;
V_8 -> V_20 = 0 ;
V_10 = F_6 ( V_8 , V_37 ) ;
if ( F_20 ( V_10 ) ) {
F_12 ( & V_4 -> V_4 , L_2 , V_10 ) ;
F_21 ( V_38 ) ;
}
return V_10 ;
}
static void V_43 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = V_8 -> V_28 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_38 * V_38 = F_22 ( V_8 -> V_44 ) ;
struct V_1 * V_2 ;
unsigned long V_9 ;
int V_29 = V_8 -> V_29 ;
switch ( V_29 ) {
case 0 :
F_8 ( & V_6 -> V_45 , V_9 ) ;
V_2 = V_6 -> V_46 ;
if ( ! V_2 ) {
V_2 = V_6 -> V_46 = F_23 ( V_4 , 12 ) ;
if ( F_24 ( V_2 ) ) {
memcpy ( F_25 ( V_2 , 1 ) , F_19 ( V_38 ) , 1 ) ;
F_26 ( V_2 , F_27 ( V_2 ) -> V_47 ,
V_38 , 1 , V_8 -> V_48 ,
V_42 ) ;
V_38 = NULL ;
}
} else {
F_26 ( V_2 , F_27 ( V_2 ) -> V_47 ,
V_38 , 0 , V_8 -> V_48 ,
V_42 ) ;
V_38 = NULL ;
}
if ( V_8 -> V_48 < V_42 )
V_6 -> V_46 = NULL ;
else
V_2 = NULL ;
F_10 ( & V_6 -> V_45 , V_9 ) ;
if ( V_2 ) {
V_2 -> V_11 = F_3 ( V_12 ) ;
F_28 ( V_2 ) ;
F_29 ( V_2 , 1 ) ;
V_2 -> V_4 = V_4 ;
V_4 -> V_26 . V_49 ++ ;
V_4 -> V_26 . V_50 += V_2 -> V_18 ;
F_30 ( V_2 ) ;
}
goto V_51;
case - V_31 :
case - V_32 :
case - V_33 :
V_8 = NULL ;
break;
case - V_52 :
V_4 -> V_26 . V_53 ++ ;
F_12 ( & V_4 -> V_4 , L_3 ) ;
break;
case - V_54 :
V_4 -> V_26 . V_55 ++ ;
break;
}
V_4 -> V_26 . V_56 ++ ;
V_51:
if ( V_38 )
F_21 ( V_38 ) ;
if ( V_8 )
F_17 ( V_6 , V_8 , V_14 | V_57 ) ;
}
static int F_31 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_10 ;
unsigned V_58 ;
unsigned V_59 = V_6 -> V_60 -> V_61 -> V_62 . V_63 ;
V_10 = F_32 ( V_6 -> V_15 , V_59 , V_6 -> V_64 ) ;
if ( V_10 )
return V_10 ;
for ( V_58 = 0 ; V_58 < V_65 ; V_58 ++ ) {
struct V_7 * V_8 = F_4 ( 0 , V_66 ) ;
if ( ! V_8 || F_17 ( V_6 , V_8 , V_66 | V_57 ) ) {
F_7 ( V_8 ) ;
F_33 ( V_4 ) ;
return - V_40 ;
}
V_6 -> V_67 [ V_58 ] = V_8 ;
}
F_14 ( V_4 ) ;
return 0 ;
}
static int F_33 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
unsigned V_58 ;
unsigned V_59 = V_6 -> V_60 -> V_61 -> V_62 . V_63 ;
F_9 ( V_4 ) ;
for ( V_58 = 0 ; V_58 < V_65 ; V_58 ++ ) {
struct V_7 * V_8 = V_6 -> V_67 [ V_58 ] ;
if ( ! V_8 )
continue;
F_34 ( V_8 ) ;
F_7 ( V_8 ) ;
V_6 -> V_67 [ V_58 ] = NULL ;
}
return F_32 ( V_6 -> V_15 , V_59 , ! V_6 -> V_64 ) ;
}
static int F_35 ( struct V_3 * V_4 , struct V_68 * V_69 , int V_70 )
{
struct V_71 * V_8 = (struct V_71 * ) V_69 ;
switch ( V_70 ) {
case V_72 :
V_8 -> V_73 . V_74 = V_75 ;
return 0 ;
}
return - V_76 ;
}
static int F_36 ( struct V_3 * V_4 , int V_77 )
{
if ( ( V_77 < V_78 ) || ( V_77 > V_79 ) )
return - V_80 ;
V_4 -> V_81 = V_77 ;
return 0 ;
}
static void F_37 ( struct V_3 * V_4 )
{
V_4 -> V_82 = 0 ;
V_4 -> V_83 = & V_84 ,
V_4 -> V_85 = & V_86 ;
V_4 -> type = V_87 ;
V_4 -> V_9 = V_88 | V_89 ;
V_4 -> V_81 = V_79 ;
V_4 -> V_90 = 1 ;
V_4 -> V_91 [ 0 ] = V_92 ;
V_4 -> V_93 = 1 ;
V_4 -> V_24 = 3 ;
V_4 -> V_94 = V_95 ;
}
int F_38 ( struct V_96 * V_97 , const struct V_98 * V_99 )
{
static const char V_100 [] = L_4 ;
const struct V_101 * V_102 = NULL ;
const struct V_103 * V_104 ;
struct V_96 * V_60 ;
struct V_105 * V_106 = F_39 ( V_97 ) ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
T_3 * V_17 ;
int V_107 = 0 ;
int V_18 , V_10 ;
V_17 = V_97 -> V_108 -> V_109 ;
V_18 = V_97 -> V_108 -> V_110 ;
while ( V_18 >= 3 ) {
T_3 V_111 = V_17 [ 0 ] ;
if ( V_111 < 3 )
return - V_80 ;
if ( V_17 [ 1 ] == V_112 ) {
switch ( V_17 [ 2 ] ) {
case V_113 :
if ( V_102 || V_111 < 5 )
break;
V_102 =
(struct V_101 * ) V_17 ;
break;
case 0xAB :
V_107 = 1 ;
break;
}
}
V_17 += V_111 ;
V_18 -= V_111 ;
}
if ( ! V_102 || ! V_107 )
return - V_80 ;
V_60 = F_40 ( V_106 , V_102 -> V_114 ) ;
if ( V_60 == NULL )
return - V_115 ;
if ( V_60 -> V_116 != 2 )
return - V_80 ;
if ( V_60 -> V_108 [ 0 ] . V_62 . V_117 == 0 &&
V_60 -> V_108 [ 1 ] . V_62 . V_117 == 2 )
V_104 = V_60 -> V_108 + 1 ;
else
if ( V_60 -> V_108 [ 0 ] . V_62 . V_117 == 2 &&
V_60 -> V_108 [ 1 ] . V_62 . V_117 == 0 )
V_104 = V_60 -> V_108 ;
else
return - V_80 ;
V_4 = F_41 ( sizeof( * V_6 ) + sizeof( V_6 -> V_67 [ 0 ] ) * V_65 ,
V_100 , F_37 ) ;
if ( ! V_4 )
return - V_40 ;
V_6 = F_2 ( V_4 ) ;
F_42 ( V_4 , & V_97 -> V_4 ) ;
V_6 -> V_4 = V_4 ;
V_6 -> V_15 = V_106 ;
V_6 -> V_97 = V_97 ;
V_6 -> V_60 = V_60 ;
F_43 ( & V_6 -> V_22 ) ;
F_43 ( & V_6 -> V_45 ) ;
if ( F_44 ( V_104 -> V_118 [ 0 ] . V_62 . V_119 ) ) {
V_6 -> V_41 = F_45 ( V_106 ,
V_104 -> V_118 [ 0 ] . V_62 . V_119 ) ;
V_6 -> V_16 = F_46 ( V_106 ,
V_104 -> V_118 [ 1 ] . V_62 . V_119 ) ;
} else {
V_6 -> V_41 = F_45 ( V_106 ,
V_104 -> V_118 [ 1 ] . V_62 . V_119 ) ;
V_6 -> V_16 = F_46 ( V_106 ,
V_104 -> V_118 [ 0 ] . V_62 . V_119 ) ;
}
V_6 -> V_64 = V_104 - V_60 -> V_108 ;
V_10 = F_47 ( & V_120 , V_60 , V_6 ) ;
if ( V_10 )
goto V_121;
F_32 ( V_106 , V_102 -> V_114 ,
! V_6 -> V_64 ) ;
F_48 ( V_97 , V_6 ) ;
V_10 = F_49 ( V_4 ) ;
if ( V_10 ) {
F_50 ( & V_120 , V_60 ) ;
goto V_121;
}
F_12 ( & V_4 -> V_4 , L_5 ) ;
return 0 ;
V_121:
F_48 ( V_97 , NULL ) ;
V_95 ( V_4 ) ;
return V_10 ;
}
static void F_51 ( struct V_96 * V_97 )
{
struct V_5 * V_6 = F_52 ( V_97 ) ;
if ( V_6 -> V_122 )
return;
V_6 -> V_122 = 1 ;
F_50 ( & V_120 ,
( V_6 -> V_97 == V_97 ) ? V_6 -> V_60 : V_6 -> V_97 ) ;
F_53 ( V_6 -> V_4 ) ;
}
