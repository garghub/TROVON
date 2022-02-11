void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 , int V_6 , int V_7 )
{
V_4 -> V_2 = V_2 ;
V_4 -> V_8 = V_2 -> V_9 + ( 0x20 * V_5 + 0x80 ) ;
V_4 -> V_10 = 1 << V_5 ;
V_4 -> V_11 = V_5 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_12 = V_7 ;
F_2 ( V_4 ) ;
F_3 ( & V_4 -> V_13 , & V_2 -> V_14 ) ;
}
void F_4 ( struct V_3 * V_4 , bool V_15 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_5 ( V_2 , V_4 ) ;
V_4 -> V_16 = F_6 ( V_2 , V_17 ) ;
if ( ! V_15 )
V_4 -> V_16 -= V_4 -> V_18 ;
F_7 ( V_2 , V_19 , 0 , 1 << V_4 -> V_11 ) ;
F_8 ( V_4 , V_20 ,
0 , V_21 | V_22 ) ;
V_4 -> V_23 = true ;
}
void F_9 ( struct V_3 * V_4 )
{
F_8 ( V_4 , V_20 ,
V_21 | V_22 , 0 ) ;
F_10 ( V_4 , V_24 , V_22 ) ;
V_4 -> V_23 = false ;
}
void F_11 ( struct V_3 * V_4 )
{
F_12 ( V_4 -> V_2 , V_4 ) ;
F_9 ( V_4 ) ;
F_7 ( V_4 -> V_2 , V_19 , 1 << V_4 -> V_11 , 0 ) ;
}
void F_13 ( struct V_3 * V_4 )
{
unsigned char V_25 ;
int V_26 ;
F_9 ( V_4 ) ;
F_8 ( V_4 , V_20 , 0 , V_27 ) ;
F_14 ( 3 ) ;
V_26 = 300 ;
do {
V_25 = F_15 ( V_4 , V_20 ) &
V_27 ;
if ( V_25 )
break;
} while ( -- V_26 );
V_25 &= ~ V_27 ;
F_10 ( V_4 , V_20 , V_25 ) ;
F_14 ( 3 ) ;
V_26 = 300 ;
do {
V_25 = F_15 ( V_4 , V_20 ) &
V_27 ;
if ( ! V_25 )
break;
} while ( -- V_26 );
if ( V_4 -> V_28 )
* V_4 -> V_28 = 0 ;
}
int F_16 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_29 * V_30 ;
unsigned int V_25 ;
if ( V_4 -> V_31 )
V_30 = V_4 -> V_31 -> V_30 ;
else
V_30 = NULL ;
F_9 ( V_4 ) ;
V_25 = F_17 ( V_4 , V_20 ) ;
V_25 = ( V_25 & ~ V_32 ) |
( V_4 -> V_12 << V_33 ) ;
if ( ! V_2 -> V_34 )
V_25 |= V_35 ;
F_18 ( V_4 , V_20 , V_25 ) ;
F_18 ( V_4 , V_36 , V_4 -> V_37 ) ;
F_19 ( V_4 , V_38 , V_4 -> V_39 ) ;
F_19 ( V_4 , V_40 , V_4 -> V_41 - 1 ) ;
F_18 ( V_4 , V_42 , ( V_43 ) V_4 -> V_44 . V_45 ) ;
F_18 ( V_4 , V_46 ,
F_20 ( V_4 -> V_44 . V_45 ) ) ;
if ( V_2 -> V_47 && V_2 -> V_28 . V_45 ) {
if ( ! ( F_6 ( V_2 , V_48 ) & V_49 ) )
F_21 ( V_2 , V_48 ,
( V_43 ) V_2 -> V_28 . V_45 | V_49 ) ;
}
F_22 ( V_4 , V_20 , 0 , V_22 ) ;
if ( V_4 -> V_6 == V_50 )
V_4 -> V_51 =
F_23 ( V_4 , V_52 ) + 1 ;
else
V_4 -> V_51 = 0 ;
if ( V_30 && V_30 -> V_53 > 64 )
V_4 -> V_54 =
- F_24 ( V_30 , 64 ) ;
else
V_4 -> V_54 = 0 ;
if ( V_30 )
V_4 -> V_18 = ( ( ( V_30 -> V_53 * 24000 ) /
V_30 -> V_55 ) * 1000 ) ;
return 0 ;
}
void F_25 ( struct V_3 * V_4 )
{
F_18 ( V_4 , V_42 , 0 ) ;
F_18 ( V_4 , V_46 , 0 ) ;
F_18 ( V_4 , V_20 , 0 ) ;
V_4 -> V_37 = 0 ;
V_4 -> V_56 = 0 ;
V_4 -> V_39 = 0 ;
}
struct V_3 * F_26 ( struct V_1 * V_2 ,
struct V_57 * V_31 )
{
struct V_3 * V_4 ;
struct V_3 * V_58 = NULL ;
int V_59 = ( V_31 -> V_60 -> V_61 << 16 ) | ( V_31 -> V_62 << 2 ) |
( V_31 -> V_63 + 1 ) ;
F_27 (azx_dev, &bus->stream_list, list) {
if ( V_4 -> V_6 != V_31 -> V_63 )
continue;
if ( V_4 -> V_64 )
continue;
if ( V_4 -> V_65 == V_59 ) {
V_58 = V_4 ;
break;
}
if ( ! V_58 || V_2 -> V_66 )
V_58 = V_4 ;
}
if ( V_58 ) {
F_28 ( & V_2 -> V_67 ) ;
V_58 -> V_64 = 1 ;
V_58 -> V_23 = 0 ;
V_58 -> V_65 = V_59 ;
V_58 -> V_31 = V_31 ;
F_29 ( & V_2 -> V_67 ) ;
}
return V_58 ;
}
void F_30 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_28 ( & V_2 -> V_67 ) ;
V_4 -> V_64 = 0 ;
V_4 -> V_23 = 0 ;
V_4 -> V_31 = NULL ;
F_29 ( & V_2 -> V_67 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_68 * V_69 ,
struct V_3 * V_4 , T_1 * * V_70 ,
int V_71 , int V_72 , int V_73 )
{
T_1 * V_44 = * V_70 ;
while ( V_72 > 0 ) {
T_2 V_45 ;
int V_74 ;
if ( V_4 -> V_41 >= V_75 )
return - V_76 ;
V_45 = F_32 ( V_69 , V_71 ) ;
V_44 [ 0 ] = F_33 ( ( V_43 ) V_45 ) ;
V_44 [ 1 ] = F_33 ( F_20 ( V_45 ) ) ;
V_74 = F_34 ( V_69 , V_71 , V_72 ) ;
if ( V_2 -> V_77 ) {
V_43 V_78 = 0x1000 - ( V_71 & 0xfff ) ;
if ( V_74 > V_78 )
V_74 = V_78 ;
}
V_44 [ 2 ] = F_33 ( V_74 ) ;
V_72 -= V_74 ;
V_44 [ 3 ] = ( V_72 || ! V_73 ) ? 0 : F_33 ( 0x01 ) ;
V_44 += 4 ;
V_4 -> V_41 ++ ;
V_71 += V_74 ;
}
* V_70 = V_44 ;
return V_71 ;
}
int F_35 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_57 * V_31 = V_4 -> V_31 ;
struct V_29 * V_30 = V_31 -> V_30 ;
T_1 * V_44 ;
int V_79 , V_71 , V_80 , V_56 ;
int V_81 , V_82 ;
F_18 ( V_4 , V_42 , 0 ) ;
F_18 ( V_4 , V_46 , 0 ) ;
V_56 = V_4 -> V_56 ;
V_80 = V_4 -> V_37 / V_56 ;
V_44 = ( T_1 * ) V_4 -> V_44 . V_83 ;
V_71 = 0 ;
V_4 -> V_41 = 0 ;
V_81 = V_2 -> V_84 ;
if ( ! V_4 -> V_85 && V_81 > 0 ) {
V_82 = V_81 ;
V_81 = ( V_81 * V_30 -> V_55 + 47999 ) / 48000 ;
if ( ! V_81 )
V_81 = V_82 ;
else
V_81 = ( ( V_81 + V_82 - 1 ) / V_82 ) *
V_82 ;
V_81 = F_24 ( V_30 , V_81 ) ;
if ( V_81 >= V_56 ) {
F_36 ( V_2 -> V_86 , L_1 ,
V_81 ) ;
V_81 = 0 ;
} else {
V_71 = F_31 ( V_2 , F_37 ( V_31 ) ,
V_4 ,
& V_44 , V_71 , V_81 , true ) ;
if ( V_71 < 0 )
goto error;
}
} else
V_81 = 0 ;
for ( V_79 = 0 ; V_79 < V_80 ; V_79 ++ ) {
if ( V_79 == V_80 - 1 && V_81 )
V_71 = F_31 ( V_2 , F_37 ( V_31 ) ,
V_4 , & V_44 , V_71 ,
V_56 - V_81 , 0 ) ;
else
V_71 = F_31 ( V_2 , F_37 ( V_31 ) ,
V_4 , & V_44 , V_71 ,
V_56 ,
! V_4 -> V_85 ) ;
if ( V_71 < 0 )
goto error;
}
return 0 ;
error:
F_38 ( V_2 -> V_86 , L_2 ,
V_4 -> V_37 , V_56 ) ;
return - V_76 ;
}
int F_39 ( struct V_3 * V_4 ,
unsigned int V_39 )
{
unsigned int V_37 , V_56 ;
struct V_57 * V_31 = V_4 -> V_31 ;
struct V_29 * V_30 ;
int V_87 ;
if ( ! V_31 )
return - V_76 ;
V_30 = V_31 -> V_30 ;
V_37 = F_40 ( V_31 ) ;
V_56 = F_41 ( V_31 ) ;
if ( V_37 != V_4 -> V_37 ||
V_56 != V_4 -> V_56 ||
V_39 != V_4 -> V_39 ||
V_30 -> V_85 != V_4 -> V_85 ) {
V_4 -> V_37 = V_37 ;
V_4 -> V_56 = V_56 ;
V_4 -> V_39 = V_39 ;
V_4 -> V_85 = V_30 -> V_85 ;
V_87 = F_35 ( V_4 ) ;
if ( V_87 < 0 )
return V_87 ;
}
return 0 ;
}
static T_3 F_42 ( const struct V_88 * V_89 )
{
struct V_3 * V_4 = F_43 ( V_89 , struct V_3 , V_89 ) ;
return F_6 ( V_4 -> V_2 , V_17 ) ;
}
static void F_44 ( struct V_3 * V_4 ,
bool V_90 , T_3 V_91 )
{
struct V_92 * V_93 = & V_4 -> V_93 ;
struct V_88 * V_89 = & V_4 -> V_89 ;
T_4 V_94 ;
V_89 -> V_95 = F_42 ;
V_89 -> V_96 = F_45 ( 32 ) ;
V_89 -> V_97 = 125 ;
V_89 -> V_98 = 0 ;
V_94 = 0 ;
F_46 ( V_93 , V_89 , V_94 ) ;
if ( V_90 ) {
V_93 -> V_99 = V_91 ;
}
}
void F_47 ( struct V_3 * V_4 ,
unsigned int V_100 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_29 * V_30 = V_4 -> V_31 -> V_30 ;
struct V_3 * V_101 ;
bool V_102 = false ;
T_3 V_99 = 0 ;
int V_79 = 0 ;
F_27 (s, &bus->stream_list, list) {
if ( V_100 & ( 1 << V_79 ) ) {
F_44 ( V_101 , V_102 , V_99 ) ;
if ( ! V_102 ) {
V_102 = true ;
V_99 = V_101 -> V_93 . V_99 ;
}
}
V_79 ++ ;
}
F_48 ( V_30 , & V_30 -> V_103 ) ;
V_30 -> V_104 = true ;
}
void F_49 ( struct V_3 * V_4 , bool V_105 ,
unsigned int V_100 , unsigned int V_106 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned int V_25 ;
if ( ! V_106 )
V_106 = V_107 ;
V_25 = F_50 ( V_108 , V_2 , V_106 ) ;
if ( V_105 )
V_25 |= V_100 ;
else
V_25 &= ~ V_100 ;
F_51 ( V_108 , V_2 , V_106 , V_25 ) ;
}
void F_52 ( struct V_3 * V_4 , bool V_109 ,
unsigned int V_100 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_79 , V_110 , V_26 ;
struct V_3 * V_101 ;
for ( V_26 = 5000 ; V_26 ; V_26 -- ) {
V_110 = 0 ;
V_79 = 0 ;
F_27 (s, &bus->stream_list, list) {
if ( V_100 & ( 1 << V_79 ) ) {
if ( V_109 ) {
if ( ! ( F_15 ( V_101 , V_24 ) &
V_111 ) )
V_110 ++ ;
} else {
if ( F_15 ( V_101 , V_20 ) &
V_21 )
V_110 ++ ;
}
}
V_79 ++ ;
}
if ( ! V_110 )
break;
F_53 () ;
}
}
int F_54 ( struct V_3 * V_4 , unsigned int V_112 ,
unsigned int V_113 , struct V_68 * V_114 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
V_43 * V_44 ;
int V_87 ;
F_55 ( V_4 ) ;
F_28 ( & V_2 -> V_67 ) ;
if ( V_4 -> V_23 || V_4 -> V_115 ) {
F_29 ( & V_2 -> V_67 ) ;
V_87 = - V_116 ;
goto V_117;
}
V_4 -> V_115 = true ;
F_29 ( & V_2 -> V_67 ) ;
V_87 = V_2 -> V_118 -> V_119 ( V_2 , V_120 ,
V_113 , V_114 ) ;
if ( V_87 < 0 )
goto V_121;
V_4 -> V_31 = NULL ;
V_4 -> V_37 = V_113 ;
V_4 -> V_56 = V_113 ;
V_4 -> V_39 = V_112 ;
F_13 ( V_4 ) ;
F_18 ( V_4 , V_42 , 0 ) ;
F_18 ( V_4 , V_46 , 0 ) ;
V_4 -> V_41 = 0 ;
V_44 = ( V_43 * ) V_4 -> V_44 . V_83 ;
V_87 = F_31 ( V_2 , V_114 , V_4 , & V_44 , 0 , V_113 , 0 ) ;
if ( V_87 < 0 )
goto error;
F_16 ( V_4 ) ;
F_56 ( V_4 ) ;
return V_4 -> V_12 ;
error:
V_2 -> V_118 -> V_122 ( V_2 , V_114 ) ;
V_121:
F_28 ( & V_2 -> V_67 ) ;
V_4 -> V_115 = false ;
F_29 ( & V_2 -> V_67 ) ;
V_117:
F_56 ( V_4 ) ;
return V_87 ;
}
void F_57 ( struct V_3 * V_4 , bool V_109 )
{
if ( V_109 )
F_4 ( V_4 , true ) ;
else
F_11 ( V_4 ) ;
}
void F_58 ( struct V_3 * V_4 ,
struct V_68 * V_69 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( ! V_69 -> V_83 || ! V_4 -> V_115 )
return;
F_55 ( V_4 ) ;
F_18 ( V_4 , V_42 , 0 ) ;
F_18 ( V_4 , V_46 , 0 ) ;
F_18 ( V_4 , V_20 , 0 ) ;
V_4 -> V_37 = 0 ;
V_4 -> V_56 = 0 ;
V_4 -> V_39 = 0 ;
V_2 -> V_118 -> V_122 ( V_2 , V_69 ) ;
V_69 -> V_83 = NULL ;
F_28 ( & V_2 -> V_67 ) ;
V_4 -> V_115 = false ;
F_29 ( & V_2 -> V_67 ) ;
F_56 ( V_4 ) ;
}
