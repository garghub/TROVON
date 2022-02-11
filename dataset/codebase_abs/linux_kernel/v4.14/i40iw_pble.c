void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_5 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 = & V_4 -> V_11 ;
if ( V_11 -> V_12 ) {
F_2 (clist, tlist, &pinfo->clist) {
V_9 = F_3 ( V_6 , struct V_8 , V_13 ) ;
if ( V_9 -> type == V_14 )
F_4 ( V_2 -> V_15 , V_9 ) ;
F_5 ( V_9 ) ;
}
F_6 ( V_11 -> V_12 ) ;
}
}
enum V_16 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_17 * V_18 ;
T_1 V_19 = 0 ;
V_18 = V_2 -> V_18 ;
V_4 -> V_20 = V_18 -> V_21 [ V_22 ] . V_23 ;
if ( V_4 -> V_20 & 0xfff )
V_19 = ( V_24 - ( V_4 -> V_20 & 0xfff ) ) >> 3 ;
V_4 -> V_25 =
V_18 -> V_21 [ V_22 ] . V_26 - V_19 ;
V_4 -> V_27 = V_4 -> V_20 + ( V_19 << 3 ) ;
V_4 -> V_11 . V_28 = V_29 ;
V_4 -> V_11 . V_12 = F_8 ( V_4 -> V_11 . V_28 , - 1 ) ;
F_9 ( & V_4 -> V_11 . V_6 ) ;
if ( ! V_4 -> V_11 . V_12 )
goto error;
if ( F_10 ( V_2 , V_4 ) )
goto error;
return 0 ;
error: F_1 ( V_2 , V_4 ) ;
return V_30 ;
}
static inline void F_11 ( struct V_3 * V_4 ,
struct V_31 * V_32 )
{
V_32 -> V_33 = ( T_1 ) ( V_4 -> V_27 ) / V_34 ;
V_32 -> V_35 = ( T_1 ) ( V_4 -> V_27 ) / V_36 ;
V_32 -> V_37 = ( V_32 -> V_35 % V_38 ) ;
}
static enum V_16 F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_39 * V_40 )
{
enum V_16 V_41 = 0 ;
struct V_31 * V_32 = & V_40 -> V_32 ;
struct V_8 * V_9 = V_40 -> V_9 ;
struct V_17 * V_18 = V_40 -> V_18 ;
struct V_42 * V_43 = V_40 -> V_43 ;
T_1 V_44 = 0 ;
if ( ! V_43 -> V_45 ) {
if ( V_2 -> V_46 ) {
V_41 = F_13 ( V_2 -> V_15 , V_18 ,
V_40 -> V_32 . V_33 ,
V_47 ,
V_34 ) ;
if ( V_41 )
return V_41 ;
V_9 -> type = V_48 ;
}
}
V_44 = V_32 -> V_37 << V_49 ;
V_9 -> V_50 = V_40 -> V_51 << V_49 ;
V_9 -> V_52 = ( ( V_53 * ) V_43 -> V_54 . V_55 . V_56 . V_57 + V_44 ) ;
V_9 -> V_58 = V_4 -> V_27 ;
F_14 ( V_2 , V_59 , L_1 ,
V_9 -> V_50 , V_9 -> V_50 , V_9 -> V_52 , V_9 -> V_58 ) ;
return 0 ;
}
static void F_4 ( struct V_60 * V_15 , struct V_8 * V_9 )
{
struct V_61 * V_62 = (struct V_61 * ) V_15 -> V_63 ;
int V_64 ;
if ( ! V_9 -> V_65 )
goto V_66;
for ( V_64 = 0 ; V_64 < V_9 -> V_65 ; V_64 ++ )
F_15 ( & V_62 -> V_2 , V_9 -> V_67 [ V_64 ] , V_24 , V_68 ) ;
V_66:
F_5 ( V_9 -> V_67 ) ;
V_9 -> V_67 = NULL ;
F_16 ( V_9 -> V_52 ) ;
V_9 -> V_52 = NULL ;
V_9 -> type = 0 ;
}
static enum V_16 F_17 ( struct V_60 * V_15 ,
struct V_8 * V_9 ,
int V_65 )
{
struct V_61 * V_62 = (struct V_61 * ) V_15 -> V_63 ;
struct V_69 * V_69 ;
V_53 * V_56 ;
T_1 V_50 ;
int V_64 ;
V_9 -> V_67 = F_18 ( V_65 << 3 , V_70 ) ;
if ( ! V_9 -> V_67 )
return V_30 ;
V_50 = V_24 * V_65 ;
V_9 -> V_52 = F_19 ( V_50 ) ;
if ( ! V_9 -> V_52 ) {
F_5 ( V_9 -> V_67 ) ;
V_9 -> V_67 = NULL ;
return V_30 ;
}
V_9 -> V_50 = V_50 ;
V_56 = ( V_53 * ) V_9 -> V_52 ;
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ ) {
V_69 = F_20 ( ( void * ) V_56 ) ;
if ( ! V_69 )
break;
V_9 -> V_67 [ V_64 ] = F_21 ( & V_62 -> V_2 , V_69 , 0 ,
V_24 , V_68 ) ;
if ( F_22 ( & V_62 -> V_2 , V_9 -> V_67 [ V_64 ] ) )
break;
V_56 += V_24 ;
}
V_9 -> V_65 = V_64 ;
V_9 -> type = V_14 ;
if ( V_64 == V_65 )
return 0 ;
F_4 ( V_15 , V_9 ) ;
return V_30 ;
}
static inline T_1 F_23 ( struct V_3 * V_4 , T_2 V_56 )
{
return ( V_56 - ( V_4 -> V_20 ) ) >> 3 ;
}
static enum V_16 F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_39 * V_40 )
{
V_53 * V_56 ;
struct V_71 V_72 ;
struct V_73 * V_74 ;
struct V_42 * V_43 = V_40 -> V_43 ;
struct V_17 * V_18 = V_40 -> V_18 ;
struct V_8 * V_9 = V_40 -> V_9 ;
struct V_75 V_76 ;
enum V_16 V_77 = 0 ;
T_1 V_37 = V_40 -> V_32 . V_37 ;
T_1 V_35 = V_40 -> V_32 . V_35 ;
T_1 V_64 ;
V_77 = F_17 ( V_2 -> V_15 , V_9 , V_40 -> V_51 ) ;
if ( V_77 )
return V_30 ;
V_77 = F_13 ( V_2 -> V_15 , V_18 ,
V_40 -> V_32 . V_33 , V_78 ,
V_34 ) ;
if ( V_77 )
goto error;
if ( ! V_2 -> V_46 ) {
V_77 = F_25 ( V_2 , V_22 ,
F_23 ( V_4 ,
V_4 -> V_27 ) ,
( V_40 -> V_51 << V_79 ) ) ;
if ( V_77 ) {
F_26 ( L_2 , V_77 ) ;
goto error;
}
}
V_56 = V_9 -> V_52 ;
for ( V_64 = 0 ; V_64 < V_40 -> V_51 ; V_64 ++ ) {
V_72 . V_80 = V_9 -> V_67 [ V_64 ] ;
V_72 . V_50 = V_24 ;
V_72 . V_57 = ( void * ) ( V_56 ) ;
V_74 = & V_43 -> V_54 . V_81 . V_74 [ V_37 ++ ] ;
if ( ! V_74 -> V_45 ) {
V_77 = F_27 ( V_2 -> V_15 , V_18 , V_35 ++ , & V_72 ) ;
if ( V_77 )
goto error;
V_56 += V_24 ;
} else {
F_26 ( L_3 ) ;
}
}
if ( ! V_2 -> V_46 ) {
V_76 . V_82 = V_40 -> V_32 . V_37 ;
V_76 . V_83 = false ;
V_76 . V_84 = V_85 ;
V_76 . V_86 = V_43 -> V_54 . V_81 . V_87 . V_80 ;
V_76 . V_88 = V_40 -> V_32 . V_33 ;
V_77 = F_28 ( V_2 -> V_89 ,
& V_76 , true ) ;
if ( V_77 ) {
F_26 ( L_4 , V_77 ) ;
goto error;
}
}
V_9 -> V_58 = V_4 -> V_27 ;
return 0 ;
error:
F_4 ( V_2 -> V_15 , V_9 ) ;
return V_77 ;
}
static enum V_16 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_42 * V_43 ;
struct V_17 * V_18 ;
struct V_8 * V_9 ;
struct V_39 V_40 ;
struct V_31 * V_32 = & V_40 . V_32 ;
enum V_16 V_41 = 0 ;
enum V_90 V_91 ;
T_2 V_92 = 0 ;
T_1 V_51 ;
if ( V_4 -> V_25 < V_85 )
return V_30 ;
if ( V_4 -> V_27 & 0xfff ) {
F_26 ( L_5 , V_4 -> V_27 ) ;
return V_93 ;
}
V_9 = F_18 ( sizeof( * V_9 ) , V_70 ) ;
if ( ! V_9 )
return V_30 ;
V_18 = V_2 -> V_18 ;
V_9 -> V_58 = V_4 -> V_27 ;
F_11 ( V_4 , V_32 ) ;
V_43 = & V_18 -> V_94 . V_43 [ V_32 -> V_33 ] ;
V_51 = ( V_32 -> V_37 ) ? ( V_38 -
V_32 -> V_37 ) : V_38 ;
V_51 = F_29 ( V_51 , V_4 -> V_25 >> V_79 ) ;
V_40 . V_9 = V_9 ;
V_40 . V_18 = V_18 ;
V_40 . V_51 = V_51 ;
V_40 . V_43 = V_43 ;
if ( ! V_43 -> V_45 ) {
V_91 = ( ! V_32 -> V_37 &&
( V_51 == V_38 ) &&
V_2 -> V_46 ) ? V_47 : V_78 ;
} else {
V_91 = V_43 -> V_95 ;
}
F_14 ( V_2 , V_59 ,
L_6 ,
V_51 , V_4 -> V_25 , V_4 -> V_27 ) ;
F_14 ( V_2 , V_59 , L_7 ,
V_91 , V_43 -> V_45 ) ;
if ( V_91 == V_47 )
V_41 = F_12 ( V_2 , V_4 , & V_40 ) ;
if ( V_41 )
V_91 = V_78 ;
else
V_4 -> V_96 ++ ;
if ( V_91 == V_78 ) {
V_41 = F_24 ( V_2 , V_4 , & V_40 ) ;
if ( V_41 )
goto error;
else
V_4 -> V_97 ++ ;
}
if ( F_30 ( V_4 -> V_11 . V_12 , ( unsigned long ) V_9 -> V_52 ,
( V_98 ) V_9 -> V_58 , V_9 -> V_50 , - 1 ) ) {
F_26 ( L_8 ) ;
V_41 = V_30 ;
goto error;
}
V_4 -> V_27 += V_9 -> V_50 ;
F_14 ( V_2 , V_59 , L_9 ,
V_4 -> V_27 , V_9 -> V_50 , V_9 -> V_50 ) ;
V_4 -> V_25 -= ( V_9 -> V_50 >> 3 ) ;
F_31 ( & V_9 -> V_13 , & V_4 -> V_11 . V_6 ) ;
V_92 = ( V_91 == V_78 ) ?
V_43 -> V_54 . V_81 . V_87 . V_80 : V_43 -> V_54 . V_55 . V_56 . V_80 ;
if ( V_43 -> V_45 )
return 0 ;
if ( V_2 -> V_46 ) {
V_41 = F_32 ( V_2 , V_18 -> V_99 ,
V_92 , V_32 -> V_33 ,
V_43 -> V_95 , true ) ;
if ( V_41 ) {
F_26 ( L_10 ) ;
goto error;
}
}
V_43 -> V_45 = true ;
return 0 ;
error:
F_5 ( V_9 ) ;
return V_41 ;
}
static void F_33 ( struct V_3 * V_4 ,
struct V_100 * V_101 )
{
T_1 V_64 ;
struct V_102 * V_12 ;
struct V_103 * V_104 = & V_101 -> V_105 ;
struct V_106 * V_107 = & V_104 -> V_107 ;
struct V_106 * V_108 = V_104 -> V_108 ;
V_12 = V_4 -> V_11 . V_12 ;
for ( V_64 = 0 ; V_64 < V_104 -> V_109 ; V_64 ++ , V_108 ++ ) {
if ( V_108 -> V_56 )
F_34 ( V_12 , V_108 -> V_56 , ( V_108 -> V_26 << 3 ) ) ;
else
break;
}
if ( V_107 -> V_56 )
F_34 ( V_12 , V_107 -> V_56 , ( V_107 -> V_26 << 3 ) ) ;
F_5 ( V_104 -> V_108 ) ;
V_104 -> V_108 = NULL ;
}
static enum V_16 F_35 ( struct V_3 * V_4 ,
struct V_100 * V_101 ,
struct V_102 * V_12 )
{
T_1 V_110 , V_111 , V_112 , V_64 ;
T_1 V_113 = V_85 ;
T_2 * V_56 ;
struct V_103 * V_104 = & V_101 -> V_105 ;
struct V_106 * V_107 = & V_104 -> V_107 ;
struct V_106 * V_108 ;
V_110 = V_101 -> V_114 >> 9 ;
V_111 = V_101 -> V_114 % V_85 ;
V_112 = ( V_111 == 0 ) ? V_110 : V_110 + 1 ;
V_104 -> V_109 = V_112 ;
V_108 = F_18 ( ( sizeof( * V_108 ) * V_112 ) , V_115 ) ;
if ( ! V_108 )
return V_30 ;
V_104 -> V_108 = V_108 ;
V_107 -> V_56 = F_36 ( V_12 , ( V_112 << 3 ) ) ;
if ( ! V_107 -> V_56 ) {
F_5 ( V_104 -> V_108 ) ;
V_104 -> V_108 = NULL ;
return V_30 ;
}
V_107 -> V_32 = F_23 ( V_4 ,
( T_2 ) F_37 ( V_12 , V_107 -> V_56 ) ) ;
V_107 -> V_26 = V_112 ;
V_56 = ( T_2 * ) V_107 -> V_56 ;
for ( V_64 = 0 ; V_64 < V_112 ; V_64 ++ , V_108 ++ ) {
V_113 = ( V_111 && ( ( V_64 + 1 ) == V_112 ) ) ? V_111 : V_85 ;
V_108 -> V_56 = F_36 ( V_12 , ( V_113 << 3 ) ) ;
if ( ! V_108 -> V_56 )
goto error;
V_108 -> V_32 = F_23 ( V_4 , ( T_2 ) F_37 ( V_12 , V_108 -> V_56 ) ) ;
V_108 -> V_26 = V_113 ;
* V_56 = ( T_2 ) V_108 -> V_32 ;
V_56 ++ ;
}
V_101 -> V_116 = V_117 ;
V_4 -> V_118 ++ ;
return 0 ;
error:
F_33 ( V_4 , V_101 ) ;
return V_30 ;
}
static enum V_16 F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_100 * V_101 )
{
T_2 * V_56 ;
struct V_102 * V_12 ;
struct V_106 * V_119 = & V_101 -> V_120 ;
V_12 = V_4 -> V_11 . V_12 ;
V_56 = ( T_2 * ) F_36 ( V_12 , ( V_101 -> V_114 << 3 ) ) ;
if ( ! V_56 )
return V_30 ;
V_101 -> V_116 = V_121 ;
V_119 -> V_56 = ( unsigned long ) V_56 ;
V_119 -> V_32 = F_23 ( V_4 , ( T_2 ) F_37 ( V_12 ,
( unsigned long ) V_56 ) ) ;
V_119 -> V_26 = V_101 -> V_114 ;
V_4 -> V_122 ++ ;
return 0 ;
}
static inline enum V_16 F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_100 * V_101 ,
struct V_102 * V_12 )
{
enum V_16 V_77 = 0 ;
V_77 = F_38 ( V_2 , V_4 , V_101 ) ;
if ( V_77 && ( V_101 -> V_114 > V_85 ) )
V_77 = F_35 ( V_4 , V_101 , V_12 ) ;
return V_77 ;
}
enum V_16 F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_100 * V_101 ,
T_1 V_123 )
{
struct V_102 * V_12 ;
enum V_16 V_77 = 0 ;
T_1 V_124 = 0 ;
int V_64 ;
V_12 = V_4 -> V_11 . V_12 ;
V_101 -> V_114 = V_123 ;
V_101 -> V_116 = V_125 ;
V_77 = F_39 ( V_2 , V_4 , V_101 , V_12 ) ;
if ( ! V_77 )
goto exit;
V_124 = ( V_101 -> V_114 >> 18 ) + 1 ;
for ( V_64 = 0 ; V_64 < V_124 ; V_64 ++ ) {
V_77 = F_10 ( V_2 , V_4 ) ;
if ( V_77 )
break;
V_77 = F_39 ( V_2 , V_4 , V_101 , V_12 ) ;
if ( ! V_77 )
break;
}
exit:
if ( ! V_77 )
V_4 -> V_126 ++ ;
else
V_4 -> V_127 ++ ;
return V_77 ;
}
void F_41 ( struct V_3 * V_4 ,
struct V_100 * V_101 )
{
struct V_102 * V_12 ;
V_12 = V_4 -> V_11 . V_12 ;
if ( V_101 -> V_116 == V_117 )
F_33 ( V_4 , V_101 ) ;
else
F_34 ( V_12 , V_101 -> V_120 . V_56 ,
( V_101 -> V_120 . V_26 << 3 ) ) ;
V_4 -> V_128 ++ ;
}
