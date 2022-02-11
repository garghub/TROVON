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
struct V_3 * F_31 ( struct V_1 * V_2 ,
int V_68 , int V_12 )
{
struct V_3 * V_69 ;
F_27 (s, &bus->stream_list, list) {
if ( V_69 -> V_6 == V_68 && V_69 -> V_12 == V_12 )
return V_69 ;
}
return NULL ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_70 * V_71 ,
struct V_3 * V_4 , T_1 * * V_72 ,
int V_73 , int V_74 , int V_75 )
{
T_1 * V_44 = * V_72 ;
while ( V_74 > 0 ) {
T_2 V_45 ;
int V_76 ;
if ( V_4 -> V_41 >= V_77 )
return - V_78 ;
V_45 = F_33 ( V_71 , V_73 ) ;
V_44 [ 0 ] = F_34 ( ( V_43 ) V_45 ) ;
V_44 [ 1 ] = F_34 ( F_20 ( V_45 ) ) ;
V_76 = F_35 ( V_71 , V_73 , V_74 ) ;
if ( V_2 -> V_79 ) {
V_43 V_80 = 0x1000 - ( V_73 & 0xfff ) ;
if ( V_76 > V_80 )
V_76 = V_80 ;
}
V_44 [ 2 ] = F_34 ( V_76 ) ;
V_74 -= V_76 ;
V_44 [ 3 ] = ( V_74 || ! V_75 ) ? 0 : F_34 ( 0x01 ) ;
V_44 += 4 ;
V_4 -> V_41 ++ ;
V_73 += V_76 ;
}
* V_72 = V_44 ;
return V_73 ;
}
int F_36 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_57 * V_31 = V_4 -> V_31 ;
struct V_29 * V_30 = V_31 -> V_30 ;
T_1 * V_44 ;
int V_81 , V_73 , V_82 , V_56 ;
int V_83 , V_84 ;
F_18 ( V_4 , V_42 , 0 ) ;
F_18 ( V_4 , V_46 , 0 ) ;
V_56 = V_4 -> V_56 ;
V_82 = V_4 -> V_37 / V_56 ;
V_44 = ( T_1 * ) V_4 -> V_44 . V_85 ;
V_73 = 0 ;
V_4 -> V_41 = 0 ;
V_83 = V_2 -> V_86 ;
if ( ! V_4 -> V_87 && V_83 > 0 ) {
V_84 = V_83 ;
V_83 = ( V_83 * V_30 -> V_55 + 47999 ) / 48000 ;
if ( ! V_83 )
V_83 = V_84 ;
else
V_83 = ( ( V_83 + V_84 - 1 ) / V_84 ) *
V_84 ;
V_83 = F_24 ( V_30 , V_83 ) ;
if ( V_83 >= V_56 ) {
F_37 ( V_2 -> V_88 , L_1 ,
V_83 ) ;
V_83 = 0 ;
} else {
V_73 = F_32 ( V_2 , F_38 ( V_31 ) ,
V_4 ,
& V_44 , V_73 , V_83 , true ) ;
if ( V_73 < 0 )
goto error;
}
} else
V_83 = 0 ;
for ( V_81 = 0 ; V_81 < V_82 ; V_81 ++ ) {
if ( V_81 == V_82 - 1 && V_83 )
V_73 = F_32 ( V_2 , F_38 ( V_31 ) ,
V_4 , & V_44 , V_73 ,
V_56 - V_83 , 0 ) ;
else
V_73 = F_32 ( V_2 , F_38 ( V_31 ) ,
V_4 , & V_44 , V_73 ,
V_56 ,
! V_4 -> V_87 ) ;
if ( V_73 < 0 )
goto error;
}
return 0 ;
error:
F_39 ( V_2 -> V_88 , L_2 ,
V_4 -> V_37 , V_56 ) ;
return - V_78 ;
}
int F_40 ( struct V_3 * V_4 ,
unsigned int V_39 )
{
unsigned int V_37 , V_56 ;
struct V_57 * V_31 = V_4 -> V_31 ;
struct V_29 * V_30 ;
int V_89 ;
if ( ! V_31 )
return - V_78 ;
V_30 = V_31 -> V_30 ;
V_37 = F_41 ( V_31 ) ;
V_56 = F_42 ( V_31 ) ;
if ( V_37 != V_4 -> V_37 ||
V_56 != V_4 -> V_56 ||
V_39 != V_4 -> V_39 ||
V_30 -> V_87 != V_4 -> V_87 ) {
V_4 -> V_37 = V_37 ;
V_4 -> V_56 = V_56 ;
V_4 -> V_39 = V_39 ;
V_4 -> V_87 = V_30 -> V_87 ;
V_89 = F_36 ( V_4 ) ;
if ( V_89 < 0 )
return V_89 ;
}
return 0 ;
}
static T_3 F_43 ( const struct V_90 * V_91 )
{
struct V_3 * V_4 = F_44 ( V_91 , struct V_3 , V_91 ) ;
return F_6 ( V_4 -> V_2 , V_17 ) ;
}
static void F_45 ( struct V_3 * V_4 ,
bool V_92 , T_3 V_93 )
{
struct V_94 * V_95 = & V_4 -> V_95 ;
struct V_90 * V_91 = & V_4 -> V_91 ;
T_4 V_96 ;
V_91 -> V_97 = F_43 ;
V_91 -> V_98 = F_46 ( 32 ) ;
V_91 -> V_99 = 125 ;
V_91 -> V_100 = 0 ;
V_96 = 0 ;
F_47 ( V_95 , V_91 , V_96 ) ;
if ( V_92 ) {
V_95 -> V_101 = V_93 ;
}
}
void F_48 ( struct V_3 * V_4 ,
unsigned int V_102 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_29 * V_30 = V_4 -> V_31 -> V_30 ;
struct V_3 * V_69 ;
bool V_103 = false ;
T_3 V_101 = 0 ;
int V_81 = 0 ;
F_27 (s, &bus->stream_list, list) {
if ( V_102 & ( 1 << V_81 ) ) {
F_45 ( V_69 , V_103 , V_101 ) ;
if ( ! V_103 ) {
V_103 = true ;
V_101 = V_69 -> V_95 . V_101 ;
}
}
V_81 ++ ;
}
F_49 ( V_30 , & V_30 -> V_104 ) ;
V_30 -> V_105 = true ;
}
void F_50 ( struct V_3 * V_4 , bool V_106 ,
unsigned int V_102 , unsigned int V_107 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned int V_25 ;
if ( ! V_107 )
V_107 = V_108 ;
V_25 = F_51 ( V_109 , V_2 , V_107 ) ;
if ( V_106 )
V_25 |= V_102 ;
else
V_25 &= ~ V_102 ;
F_52 ( V_109 , V_2 , V_107 , V_25 ) ;
}
void F_53 ( struct V_3 * V_4 , bool V_110 ,
unsigned int V_102 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_81 , V_111 , V_26 ;
struct V_3 * V_69 ;
for ( V_26 = 5000 ; V_26 ; V_26 -- ) {
V_111 = 0 ;
V_81 = 0 ;
F_27 (s, &bus->stream_list, list) {
if ( V_102 & ( 1 << V_81 ) ) {
if ( V_110 ) {
if ( ! ( F_15 ( V_69 , V_24 ) &
V_112 ) )
V_111 ++ ;
} else {
if ( F_15 ( V_69 , V_20 ) &
V_21 )
V_111 ++ ;
}
}
V_81 ++ ;
}
if ( ! V_111 )
break;
F_54 () ;
}
}
int F_55 ( struct V_3 * V_4 , unsigned int V_113 ,
unsigned int V_114 , struct V_70 * V_115 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
V_43 * V_44 ;
int V_89 ;
F_56 ( V_4 ) ;
F_28 ( & V_2 -> V_67 ) ;
if ( V_4 -> V_23 || V_4 -> V_116 ) {
F_29 ( & V_2 -> V_67 ) ;
V_89 = - V_117 ;
goto V_118;
}
V_4 -> V_116 = true ;
F_29 ( & V_2 -> V_67 ) ;
V_89 = V_2 -> V_119 -> V_120 ( V_2 , V_121 ,
V_114 , V_115 ) ;
if ( V_89 < 0 )
goto V_122;
V_4 -> V_31 = NULL ;
V_4 -> V_37 = V_114 ;
V_4 -> V_56 = V_114 ;
V_4 -> V_39 = V_113 ;
F_13 ( V_4 ) ;
F_18 ( V_4 , V_42 , 0 ) ;
F_18 ( V_4 , V_46 , 0 ) ;
V_4 -> V_41 = 0 ;
V_44 = ( V_43 * ) V_4 -> V_44 . V_85 ;
V_89 = F_32 ( V_2 , V_115 , V_4 , & V_44 , 0 , V_114 , 0 ) ;
if ( V_89 < 0 )
goto error;
F_16 ( V_4 ) ;
F_57 ( V_4 ) ;
return V_4 -> V_12 ;
error:
V_2 -> V_119 -> V_123 ( V_2 , V_115 ) ;
V_122:
F_28 ( & V_2 -> V_67 ) ;
V_4 -> V_116 = false ;
F_29 ( & V_2 -> V_67 ) ;
V_118:
F_57 ( V_4 ) ;
return V_89 ;
}
void F_58 ( struct V_3 * V_4 , bool V_110 )
{
if ( V_110 )
F_4 ( V_4 , true ) ;
else
F_11 ( V_4 ) ;
}
void F_59 ( struct V_3 * V_4 ,
struct V_70 * V_71 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
if ( ! V_71 -> V_85 || ! V_4 -> V_116 )
return;
F_56 ( V_4 ) ;
F_18 ( V_4 , V_42 , 0 ) ;
F_18 ( V_4 , V_46 , 0 ) ;
F_18 ( V_4 , V_20 , 0 ) ;
V_4 -> V_37 = 0 ;
V_4 -> V_56 = 0 ;
V_4 -> V_39 = 0 ;
V_2 -> V_119 -> V_123 ( V_2 , V_71 ) ;
V_71 -> V_85 = NULL ;
F_28 ( & V_2 -> V_67 ) ;
V_4 -> V_116 = false ;
F_29 ( & V_2 -> V_67 ) ;
F_57 ( V_4 ) ;
}
