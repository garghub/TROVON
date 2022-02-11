static bool
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 , * V_10 ;
bool V_11 = false ;
struct V_12 * V_13 ;
struct V_14 * V_15 = V_2 -> V_15 ;
F_2 (ra_list, ra_list_head, list) {
if ( F_3 ( & V_7 -> V_16 ) )
continue;
F_4 (&ra_list->skb_head, skb, tmp) {
V_13 = F_5 ( V_9 ) ;
if ( V_13 -> V_17 & V_18 ) {
F_6 ( V_9 , & V_7 -> V_16 ) ;
F_7 ( V_15 , V_9 , 0 ,
- 1 ) ;
if ( V_7 -> V_19 )
V_2 -> V_20 . V_21 [ V_5 ] -- ;
else
F_8 ( & V_2 -> V_20 . V_22 ) ;
V_11 = true ;
}
if ( ( F_9 ( & V_15 -> V_23 ) <=
V_24 ) )
break;
}
}
return V_11 ;
}
static void F_10 ( struct V_1 * V_2 )
{
unsigned long V_17 ;
struct V_3 * V_7 ;
int V_25 ;
F_11 ( & V_2 -> V_20 . V_26 , V_17 ) ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ , V_2 -> V_28 ++ ) {
if ( V_2 -> V_28 == V_27 )
V_2 -> V_28 = 0 ;
V_7 = & V_2 -> V_20 . V_29 [ V_2 -> V_28 ] . V_7 ;
if ( F_1 ( V_2 , V_7 , V_25 ) ) {
V_2 -> V_28 ++ ;
break;
}
}
F_12 ( & V_2 -> V_20 . V_26 , V_17 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
struct V_8 * V_34 ;
struct V_12 * V_13 ;
int V_35 ;
struct V_36 * V_37 ;
struct V_38 * V_39 ;
int V_40 ;
V_31 = (struct V_30 * ) ( V_9 -> V_41 ) ;
V_33 = ( void * ) V_31 + F_14 ( V_31 -> V_42 ) ;
if ( ( F_9 ( & V_15 -> V_23 ) >=
V_43 ) ) {
F_15 ( V_2 -> V_15 , ERROR ,
L_1 ) ;
F_16 ( V_9 ) ;
F_10 ( V_2 ) ;
return;
}
if ( ( ! memcmp ( & V_33 -> V_44 , V_45 ,
sizeof( V_45 ) ) ) ||
( ! memcmp ( & V_33 -> V_44 , V_46 ,
sizeof( V_46 ) ) &&
F_17 ( V_33 -> V_44 . V_47 ) != V_48 &&
F_17 ( V_33 -> V_44 . V_47 ) != V_49 ) ) {
V_37 = (struct V_36 * )
( ( V_50 * ) ( & V_33 -> V_51 )
+ sizeof( V_33 -> V_51 )
+ sizeof( V_33 -> V_44 )
- sizeof( V_33 -> V_51 . V_52 )
- sizeof( V_33 -> V_51 . V_53 )
- sizeof( V_33 -> V_44 . V_47 ) ) ;
memcpy ( V_37 -> V_53 , V_33 -> V_51 . V_53 ,
sizeof( V_37 -> V_53 ) ) ;
memcpy ( V_37 -> V_52 , V_33 -> V_51 . V_52 ,
sizeof( V_37 -> V_52 ) ) ;
V_35 = ( V_50 * ) V_37 - ( V_50 * ) V_31 ;
} else {
V_35 = ( V_50 * ) & V_33 -> V_51 - ( V_50 * ) V_31 ;
}
F_18 ( V_9 , V_35 ) ;
if ( F_19 ( V_9 ) < V_54 ) {
F_15 ( V_2 -> V_15 , ERROR ,
L_2 ,
F_19 ( V_9 ) ) ;
V_34 =
F_20 ( V_9 , V_54 ) ;
if ( F_21 ( ! V_34 ) ) {
F_15 ( V_2 -> V_15 , ERROR ,
L_3 ) ;
F_16 ( V_9 ) ;
V_2 -> V_55 . V_56 ++ ;
return;
}
F_16 ( V_9 ) ;
V_9 = V_34 ;
F_15 ( V_2 -> V_15 , V_57 ,
L_4 ,
F_19 ( V_9 ) ) ;
}
V_13 = F_5 ( V_9 ) ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_58 = V_2 -> V_58 ;
V_13 -> V_59 = V_2 -> V_59 ;
V_13 -> V_17 |= V_18 ;
V_39 = F_22 ( V_2 , V_33 -> V_51 . V_53 ) ;
if ( V_39 ) {
V_39 -> V_55 . V_60 = V_61 ;
V_39 -> V_55 . V_62 += V_9 -> V_63 ;
V_39 -> V_55 . V_64 ++ ;
V_39 -> V_55 . V_65 = V_31 -> V_66 ;
V_39 -> V_55 . V_67 = V_31 -> V_68 ;
}
if ( F_23 ( V_33 -> V_51 . V_52 ) ) {
V_2 -> V_55 . V_62 += V_9 -> V_63 ;
V_2 -> V_55 . V_64 ++ ;
V_13 -> V_69 = V_9 -> V_63 ;
}
F_24 ( V_9 ) ;
V_40 = V_70 [ V_9 -> V_71 ] ;
F_25 ( & V_2 -> V_72 [ V_40 ] ) ;
F_26 ( V_2 , V_9 ) ;
F_25 ( & V_15 -> V_73 ) ;
F_25 ( & V_15 -> V_23 ) ;
F_27 ( V_2 -> V_15 ) ;
return;
}
int F_28 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
V_50 V_74 [ V_75 ] ;
struct V_8 * V_76 ;
V_31 = (struct V_30 * ) ( V_9 -> V_41 ) ;
V_33 = ( void * ) V_31 + F_14 ( V_31 -> V_42 ) ;
if ( ! V_2 -> V_77 ) {
F_15 ( V_15 , ERROR ,
L_5 ) ;
F_29 ( V_9 ) ;
return 0 ;
}
memcpy ( V_74 , V_33 -> V_51 . V_52 , V_75 ) ;
if ( F_30 ( V_74 ) ) {
V_76 = F_31 ( V_9 , V_78 ) ;
F_13 ( V_2 , V_76 ) ;
} else {
if ( F_22 ( V_2 , V_74 ) ) {
F_13 ( V_2 , V_9 ) ;
return 0 ;
}
}
return F_32 ( V_2 , V_9 ) ;
}
int F_33 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_38 * V_39 ;
struct V_36 * V_37 ;
struct V_8 * V_76 ;
struct V_12 * V_13 ;
if ( ! V_9 )
return - 1 ;
V_37 = ( void * ) V_9 -> V_41 ;
V_39 = F_22 ( V_2 , V_37 -> V_53 ) ;
if ( V_39 ) {
V_39 -> V_55 . V_60 = V_61 ;
V_39 -> V_55 . V_62 += V_9 -> V_63 ;
V_39 -> V_55 . V_64 ++ ;
}
V_9 -> V_79 = V_2 -> V_80 ;
V_9 -> V_81 = F_34 ( V_9 , V_2 -> V_80 ) ;
V_9 -> V_82 = V_83 ;
if ( ( V_15 -> V_84 == V_85 ||
V_15 -> V_84 == V_86 ) &&
( V_9 -> V_87 > V_88 ) )
V_9 -> V_87 += ( V_9 -> V_63 - V_88 ) ;
if ( F_30 ( V_37 -> V_52 ) ||
F_22 ( V_2 , V_37 -> V_52 ) ) {
if ( F_19 ( V_9 ) < V_54 )
V_76 =
F_20 ( V_9 , V_54 ) ;
else
V_76 = F_31 ( V_9 , V_78 ) ;
if ( F_35 ( V_76 ) ) {
V_13 = F_5 ( V_76 ) ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_58 = V_2 -> V_58 ;
V_13 -> V_59 = V_2 -> V_59 ;
V_13 -> V_17 |= V_18 ;
F_24 ( V_76 ) ;
F_26 ( V_2 , V_76 ) ;
F_25 ( & V_15 -> V_73 ) ;
F_25 ( & V_15 -> V_23 ) ;
if ( ( F_9 ( & V_15 -> V_23 ) >=
V_43 ) ) {
F_15 ( V_15 , ERROR ,
L_1 ) ;
F_10 ( V_2 ) ;
}
} else {
F_15 ( V_15 , ERROR , L_6 ) ;
}
F_27 ( V_15 ) ;
if ( F_22 ( V_2 , V_37 -> V_52 ) )
return 0 ;
}
if ( F_36 () )
F_37 ( V_9 ) ;
else
F_38 ( V_9 ) ;
return 0 ;
}
int F_39 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
int V_89 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
T_1 V_90 ;
V_50 V_91 [ V_75 ] , V_92 ;
unsigned long V_17 ;
struct V_38 * V_93 ;
V_31 = (struct V_30 * ) ( V_9 -> V_41 ) ;
V_90 = F_14 ( V_31 -> V_90 ) ;
V_33 = ( void * ) V_31 + F_14 ( V_31 -> V_42 ) ;
F_40 ( V_91 , V_33 -> V_51 . V_53 ) ;
if ( ( F_14 ( V_31 -> V_42 ) +
F_14 ( V_31 -> V_94 ) ) > ( T_1 ) V_9 -> V_63 ) {
F_15 ( V_15 , ERROR ,
L_7 ,
V_9 -> V_63 , F_14 ( V_31 -> V_42 ) ,
F_14 ( V_31 -> V_94 ) ) ;
V_2 -> V_55 . V_95 ++ ;
V_93 = F_22 ( V_2 , V_91 ) ;
if ( V_93 )
V_93 -> V_55 . V_96 ++ ;
F_29 ( V_9 ) ;
return 0 ;
}
if ( V_90 == V_97 ) {
V_89 = F_41 ( V_2 , V_9 ) ;
if ( V_89 )
F_15 ( V_15 , V_98 , L_8 ) ;
F_29 ( V_9 ) ;
return V_89 ;
}
if ( V_90 != V_99 && V_31 -> V_71 < V_27 ) {
F_11 ( & V_2 -> V_100 , V_17 ) ;
V_93 = F_22 ( V_2 , V_91 ) ;
if ( V_93 )
V_93 -> V_101 [ V_31 -> V_71 ] =
F_14 ( V_31 -> V_102 ) ;
F_12 ( & V_2 -> V_100 , V_17 ) ;
}
if ( ! V_2 -> V_103 ||
( ! F_42 ( V_2 , V_31 -> V_71 , V_91 ) &&
( F_14 ( V_31 -> V_90 ) != V_104 ) ) ) {
V_89 = F_28 ( V_2 , V_9 ) ;
return V_89 ;
}
V_92 = ( V_50 ) F_14 ( V_31 -> V_90 ) ;
V_89 = F_43 ( V_2 , F_14 ( V_31 -> V_102 ) ,
V_31 -> V_71 , V_91 , V_92 ,
V_9 ) ;
if ( V_89 || ( V_90 == V_99 ) )
F_29 ( V_9 ) ;
if ( V_89 )
V_2 -> V_55 . V_95 ++ ;
return V_89 ;
}
void * F_44 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_105 * V_106 ;
struct V_12 * V_13 = F_5 ( V_9 ) ;
int V_107 ;
T_1 V_92 , V_108 ;
int V_109 = ( V_2 -> V_15 -> V_84 == V_85 ) ? 0 :
V_110 ;
if ( ! V_9 -> V_63 ) {
F_15 ( V_15 , ERROR ,
L_9 , V_9 -> V_63 ) ;
V_13 -> V_111 = - 1 ;
return V_9 -> V_41 ;
}
F_45 ( F_19 ( V_9 ) < V_54 ) ;
V_92 = F_46 ( V_9 ) ? V_97 : 0 ;
V_107 = ( ( void * ) V_9 -> V_41 - ( sizeof( * V_106 ) + V_109 ) - NULL ) &
( V_112 - 1 ) ;
F_47 ( V_9 , sizeof( * V_106 ) + V_107 ) ;
V_106 = (struct V_105 * ) V_9 -> V_41 ;
memset ( V_106 , 0 , sizeof( * V_106 ) ) ;
V_106 -> V_58 = V_2 -> V_58 ;
V_106 -> V_59 = V_2 -> V_59 ;
V_106 -> V_113 = F_48 ( ( T_1 ) ( V_9 -> V_63 - ( sizeof( * V_106 ) +
V_107 ) ) ) ;
V_106 -> V_71 = ( V_50 ) V_9 -> V_71 ;
V_106 -> V_114 = F_49 ( V_2 , V_9 ) ;
if ( V_13 -> V_17 & V_115 ||
V_13 -> V_17 & V_116 ) {
V_106 -> V_117 = V_13 -> V_118 ;
V_106 -> V_17 |= V_119 ;
}
if ( V_106 -> V_71 < F_50 ( V_2 -> V_20 . V_120 ) )
V_106 -> V_121 =
F_51 ( V_2 -> V_20 . V_120 [ V_106 -> V_71 ] ) ;
V_108 = sizeof( * V_106 ) + V_107 ;
if ( V_92 == V_97 ) {
V_106 -> V_122 = F_48 ( V_92 ) ;
V_108 += V_123 ;
}
V_106 -> V_124 = F_48 ( V_108 ) ;
F_47 ( V_9 , V_109 ) ;
if ( ! V_106 -> V_121 )
V_106 -> V_121 = F_51 ( V_2 -> V_125 ) ;
return V_9 -> V_41 ;
}
