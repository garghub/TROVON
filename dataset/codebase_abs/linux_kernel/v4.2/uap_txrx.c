static bool
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 , * V_9 ;
bool V_10 = false ;
struct V_11 * V_12 ;
struct V_13 * V_14 = V_2 -> V_14 ;
F_2 (ra_list, ra_list_head, list) {
if ( F_3 ( & V_6 -> V_15 ) )
continue;
F_4 (&ra_list->skb_head, skb, tmp) {
V_12 = F_5 ( V_8 ) ;
if ( V_12 -> V_16 & V_17 ) {
F_6 ( V_8 , & V_6 -> V_15 ) ;
F_7 ( V_14 , V_8 , 0 ,
- 1 ) ;
F_8 ( & V_2 -> V_18 . V_19 ) ;
V_10 = true ;
}
if ( ( F_9 ( & V_14 -> V_20 ) <=
V_21 ) )
break;
}
}
return V_10 ;
}
static void F_10 ( struct V_1 * V_2 )
{
unsigned long V_16 ;
struct V_3 * V_6 ;
int V_22 ;
F_11 ( & V_2 -> V_18 . V_23 , V_16 ) ;
for ( V_22 = 0 ; V_22 < V_24 ; V_22 ++ , V_2 -> V_25 ++ ) {
if ( V_2 -> V_25 == V_24 )
V_2 -> V_25 = 0 ;
V_6 = & V_2 -> V_18 . V_26 [ V_2 -> V_25 ] . V_6 ;
if ( F_1 ( V_2 , V_6 ) ) {
V_2 -> V_25 ++ ;
break;
}
}
F_12 ( & V_2 -> V_18 . V_23 , V_16 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
struct V_7 * V_31 ;
struct V_11 * V_12 ;
int V_32 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
V_28 = (struct V_27 * ) ( V_8 -> V_37 ) ;
V_30 = ( void * ) V_28 + F_14 ( V_28 -> V_38 ) ;
if ( ( F_9 ( & V_14 -> V_20 ) >=
V_39 ) ) {
F_15 ( V_2 -> V_14 , ERROR ,
L_1 ) ;
F_16 ( V_8 ) ;
F_10 ( V_2 ) ;
return;
}
if ( ( ! memcmp ( & V_30 -> V_40 , V_41 ,
sizeof( V_41 ) ) ) ||
( ! memcmp ( & V_30 -> V_40 , V_42 ,
sizeof( V_42 ) ) &&
F_17 ( V_30 -> V_40 . V_43 ) != V_44 &&
F_17 ( V_30 -> V_40 . V_43 ) != V_45 ) ) {
V_34 = (struct V_33 * )
( ( V_46 * ) ( & V_30 -> V_47 )
+ sizeof( V_30 -> V_47 )
+ sizeof( V_30 -> V_40 )
- sizeof( V_30 -> V_47 . V_48 )
- sizeof( V_30 -> V_47 . V_49 )
- sizeof( V_30 -> V_40 . V_43 ) ) ;
memcpy ( V_34 -> V_49 , V_30 -> V_47 . V_49 ,
sizeof( V_34 -> V_49 ) ) ;
memcpy ( V_34 -> V_48 , V_30 -> V_47 . V_48 ,
sizeof( V_34 -> V_48 ) ) ;
V_32 = ( V_46 * ) V_34 - ( V_46 * ) V_28 ;
} else {
V_32 = ( V_46 * ) & V_30 -> V_47 - ( V_46 * ) V_28 ;
}
F_18 ( V_8 , V_32 ) ;
if ( F_19 ( V_8 ) < V_50 ) {
F_15 ( V_2 -> V_14 , ERROR ,
L_2 ,
F_19 ( V_8 ) ) ;
V_31 =
F_20 ( V_8 , V_50 ) ;
if ( F_21 ( ! V_31 ) ) {
F_15 ( V_2 -> V_14 , ERROR ,
L_3 ) ;
F_16 ( V_8 ) ;
V_2 -> V_51 . V_52 ++ ;
return;
}
F_16 ( V_8 ) ;
V_8 = V_31 ;
F_15 ( V_2 -> V_14 , V_53 ,
L_4 ,
F_19 ( V_8 ) ) ;
}
V_12 = F_5 ( V_8 ) ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
V_12 -> V_54 = V_2 -> V_54 ;
V_12 -> V_55 = V_2 -> V_55 ;
V_12 -> V_16 |= V_17 ;
V_36 = F_22 ( V_2 , V_30 -> V_47 . V_49 ) ;
if ( V_36 ) {
V_36 -> V_51 . V_56 = V_57 ;
V_36 -> V_51 . V_58 += V_8 -> V_59 ;
V_36 -> V_51 . V_60 ++ ;
V_36 -> V_51 . V_61 = V_28 -> V_62 ;
V_36 -> V_51 . V_63 = V_28 -> V_64 ;
}
if ( F_23 ( V_30 -> V_47 . V_48 ) ) {
V_2 -> V_51 . V_58 += V_8 -> V_59 ;
V_2 -> V_51 . V_60 ++ ;
V_12 -> V_65 = V_8 -> V_59 ;
}
F_24 ( V_8 ) ;
F_25 ( V_2 , V_8 ) ;
F_26 ( & V_14 -> V_66 ) ;
F_26 ( & V_14 -> V_20 ) ;
return;
}
int F_27 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
V_46 V_67 [ V_68 ] ;
struct V_7 * V_69 ;
V_28 = (struct V_27 * ) ( V_8 -> V_37 ) ;
V_30 = ( void * ) V_28 + F_14 ( V_28 -> V_38 ) ;
if ( ! V_2 -> V_70 ) {
F_15 ( V_14 , ERROR ,
L_5 ) ;
F_28 ( V_8 ) ;
return 0 ;
}
memcpy ( V_67 , V_30 -> V_47 . V_48 , V_68 ) ;
if ( F_29 ( V_67 ) ) {
V_69 = F_30 ( V_8 , V_71 ) ;
F_13 ( V_2 , V_69 ) ;
} else {
if ( F_22 ( V_2 , V_67 ) ) {
F_13 ( V_2 , V_8 ) ;
return 0 ;
}
}
return F_31 ( V_2 , V_8 ) ;
}
int F_32 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_72 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
T_1 V_73 ;
V_46 V_74 [ V_68 ] , V_75 ;
unsigned long V_16 ;
struct V_35 * V_76 ;
V_28 = (struct V_27 * ) ( V_8 -> V_37 ) ;
V_73 = F_14 ( V_28 -> V_73 ) ;
V_30 = ( void * ) V_28 + F_14 ( V_28 -> V_38 ) ;
F_33 ( V_74 , V_30 -> V_47 . V_49 ) ;
if ( ( F_14 ( V_28 -> V_38 ) +
F_14 ( V_28 -> V_77 ) ) > ( T_1 ) V_8 -> V_59 ) {
F_15 ( V_14 , ERROR ,
L_6 ,
V_8 -> V_59 , F_14 ( V_28 -> V_38 ) ,
F_14 ( V_28 -> V_77 ) ) ;
V_2 -> V_51 . V_78 ++ ;
V_76 = F_22 ( V_2 , V_74 ) ;
if ( V_76 )
V_76 -> V_51 . V_79 ++ ;
F_28 ( V_8 ) ;
return 0 ;
}
if ( V_73 == V_80 ) {
V_72 = F_34 ( V_2 , V_8 ) ;
if ( V_72 )
F_15 ( V_14 , ERROR ,
L_7 ) ;
F_28 ( V_8 ) ;
return V_72 ;
}
if ( V_73 != V_81 && V_28 -> V_82 < V_24 ) {
F_11 ( & V_2 -> V_83 , V_16 ) ;
V_76 = F_22 ( V_2 , V_74 ) ;
if ( V_76 )
V_76 -> V_84 [ V_28 -> V_82 ] =
F_14 ( V_28 -> V_85 ) ;
F_12 ( & V_2 -> V_83 , V_16 ) ;
}
if ( ! V_2 -> V_86 ||
( ! F_35 ( V_2 , V_28 -> V_82 , V_74 ) &&
( F_14 ( V_28 -> V_73 ) != V_87 ) ) ) {
V_72 = F_27 ( V_2 , V_8 ) ;
return V_72 ;
}
V_75 = ( V_46 ) F_14 ( V_28 -> V_73 ) ;
V_72 = F_36 ( V_2 , F_14 ( V_28 -> V_85 ) ,
V_28 -> V_82 , V_74 , V_75 ,
V_8 ) ;
if ( V_72 || ( V_73 == V_81 ) )
F_28 ( V_8 ) ;
if ( V_72 )
V_2 -> V_51 . V_78 ++ ;
return V_72 ;
}
void * F_37 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_88 * V_89 ;
struct V_11 * V_12 = F_5 ( V_8 ) ;
int V_90 ;
T_1 V_75 , V_91 ;
int V_92 = ( V_2 -> V_14 -> V_93 == V_94 ) ? 0 :
V_95 ;
if ( ! V_8 -> V_59 ) {
F_15 ( V_14 , ERROR ,
L_8 , V_8 -> V_59 ) ;
V_12 -> V_96 = - 1 ;
return V_8 -> V_37 ;
}
F_38 ( F_19 ( V_8 ) < V_50 ) ;
V_75 = F_39 ( V_8 ) ? V_80 : 0 ;
V_90 = ( ( void * ) V_8 -> V_37 - ( sizeof( * V_89 ) + V_92 ) - NULL ) &
( V_97 - 1 ) ;
F_40 ( V_8 , sizeof( * V_89 ) + V_90 ) ;
V_89 = (struct V_88 * ) V_8 -> V_37 ;
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_54 = V_2 -> V_54 ;
V_89 -> V_55 = V_2 -> V_55 ;
V_89 -> V_98 = F_41 ( ( T_1 ) ( V_8 -> V_59 - ( sizeof( * V_89 ) +
V_90 ) ) ) ;
V_89 -> V_82 = ( V_46 ) V_8 -> V_82 ;
V_89 -> V_99 = F_42 ( V_2 , V_8 ) ;
if ( V_12 -> V_16 & V_100 ||
V_12 -> V_16 & V_101 ) {
V_89 -> V_102 = V_12 -> V_103 ;
V_89 -> V_16 |= V_104 ;
}
if ( V_89 -> V_82 < F_43 ( V_2 -> V_18 . V_105 ) )
V_89 -> V_106 =
F_44 ( V_2 -> V_18 . V_105 [ V_89 -> V_82 ] ) ;
V_91 = sizeof( * V_89 ) + V_90 ;
if ( V_75 == V_80 ) {
V_89 -> V_107 = F_41 ( V_75 ) ;
V_91 += V_108 ;
}
V_89 -> V_109 = F_41 ( V_91 ) ;
F_40 ( V_8 , V_92 ) ;
if ( ! V_89 -> V_106 )
V_89 -> V_106 = F_44 ( V_2 -> V_110 ) ;
return V_8 -> V_37 ;
}
