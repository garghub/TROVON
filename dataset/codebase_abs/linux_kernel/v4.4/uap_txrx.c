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
V_31 = (struct V_30 * ) ( V_9 -> V_40 ) ;
V_33 = ( void * ) V_31 + F_14 ( V_31 -> V_41 ) ;
if ( ( F_9 ( & V_15 -> V_23 ) >=
V_42 ) ) {
F_15 ( V_2 -> V_15 , ERROR ,
L_1 ) ;
F_16 ( V_9 ) ;
F_10 ( V_2 ) ;
return;
}
if ( ( ! memcmp ( & V_33 -> V_43 , V_44 ,
sizeof( V_44 ) ) ) ||
( ! memcmp ( & V_33 -> V_43 , V_45 ,
sizeof( V_45 ) ) &&
F_17 ( V_33 -> V_43 . V_46 ) != V_47 &&
F_17 ( V_33 -> V_43 . V_46 ) != V_48 ) ) {
V_37 = (struct V_36 * )
( ( V_49 * ) ( & V_33 -> V_50 )
+ sizeof( V_33 -> V_50 )
+ sizeof( V_33 -> V_43 )
- sizeof( V_33 -> V_50 . V_51 )
- sizeof( V_33 -> V_50 . V_52 )
- sizeof( V_33 -> V_43 . V_46 ) ) ;
memcpy ( V_37 -> V_52 , V_33 -> V_50 . V_52 ,
sizeof( V_37 -> V_52 ) ) ;
memcpy ( V_37 -> V_51 , V_33 -> V_50 . V_51 ,
sizeof( V_37 -> V_51 ) ) ;
V_35 = ( V_49 * ) V_37 - ( V_49 * ) V_31 ;
} else {
V_35 = ( V_49 * ) & V_33 -> V_50 - ( V_49 * ) V_31 ;
}
F_18 ( V_9 , V_35 ) ;
if ( F_19 ( V_9 ) < V_53 ) {
F_15 ( V_2 -> V_15 , ERROR ,
L_2 ,
F_19 ( V_9 ) ) ;
V_34 =
F_20 ( V_9 , V_53 ) ;
if ( F_21 ( ! V_34 ) ) {
F_15 ( V_2 -> V_15 , ERROR ,
L_3 ) ;
F_16 ( V_9 ) ;
V_2 -> V_54 . V_55 ++ ;
return;
}
F_16 ( V_9 ) ;
V_9 = V_34 ;
F_15 ( V_2 -> V_15 , V_56 ,
L_4 ,
F_19 ( V_9 ) ) ;
}
V_13 = F_5 ( V_9 ) ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_57 = V_2 -> V_57 ;
V_13 -> V_58 = V_2 -> V_58 ;
V_13 -> V_17 |= V_18 ;
V_39 = F_22 ( V_2 , V_33 -> V_50 . V_52 ) ;
if ( V_39 ) {
V_39 -> V_54 . V_59 = V_60 ;
V_39 -> V_54 . V_61 += V_9 -> V_62 ;
V_39 -> V_54 . V_63 ++ ;
V_39 -> V_54 . V_64 = V_31 -> V_65 ;
V_39 -> V_54 . V_66 = V_31 -> V_67 ;
}
if ( F_23 ( V_33 -> V_50 . V_51 ) ) {
V_2 -> V_54 . V_61 += V_9 -> V_62 ;
V_2 -> V_54 . V_63 ++ ;
V_13 -> V_68 = V_9 -> V_62 ;
}
F_24 ( V_9 ) ;
F_25 ( V_2 , V_9 ) ;
F_26 ( & V_15 -> V_69 ) ;
F_26 ( & V_15 -> V_23 ) ;
return;
}
int F_27 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
V_49 V_70 [ V_71 ] ;
struct V_8 * V_72 ;
V_31 = (struct V_30 * ) ( V_9 -> V_40 ) ;
V_33 = ( void * ) V_31 + F_14 ( V_31 -> V_41 ) ;
if ( ! V_2 -> V_73 ) {
F_15 ( V_15 , ERROR ,
L_5 ) ;
F_28 ( V_9 ) ;
return 0 ;
}
memcpy ( V_70 , V_33 -> V_50 . V_51 , V_71 ) ;
if ( F_29 ( V_70 ) ) {
V_72 = F_30 ( V_9 , V_74 ) ;
F_13 ( V_2 , V_72 ) ;
} else {
if ( F_22 ( V_2 , V_70 ) ) {
F_13 ( V_2 , V_9 ) ;
return 0 ;
}
}
return F_31 ( V_2 , V_9 ) ;
}
int F_32 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
int V_75 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
T_1 V_76 ;
V_49 V_77 [ V_71 ] , V_78 ;
unsigned long V_17 ;
struct V_38 * V_79 ;
V_31 = (struct V_30 * ) ( V_9 -> V_40 ) ;
V_76 = F_14 ( V_31 -> V_76 ) ;
V_33 = ( void * ) V_31 + F_14 ( V_31 -> V_41 ) ;
F_33 ( V_77 , V_33 -> V_50 . V_52 ) ;
if ( ( F_14 ( V_31 -> V_41 ) +
F_14 ( V_31 -> V_80 ) ) > ( T_1 ) V_9 -> V_62 ) {
F_15 ( V_15 , ERROR ,
L_6 ,
V_9 -> V_62 , F_14 ( V_31 -> V_41 ) ,
F_14 ( V_31 -> V_80 ) ) ;
V_2 -> V_54 . V_81 ++ ;
V_79 = F_22 ( V_2 , V_77 ) ;
if ( V_79 )
V_79 -> V_54 . V_82 ++ ;
F_28 ( V_9 ) ;
return 0 ;
}
if ( V_76 == V_83 ) {
V_75 = F_34 ( V_2 , V_9 ) ;
if ( V_75 )
F_15 ( V_15 , ERROR ,
L_7 ) ;
F_28 ( V_9 ) ;
return V_75 ;
}
if ( V_76 != V_84 && V_31 -> V_85 < V_27 ) {
F_11 ( & V_2 -> V_86 , V_17 ) ;
V_79 = F_22 ( V_2 , V_77 ) ;
if ( V_79 )
V_79 -> V_87 [ V_31 -> V_85 ] =
F_14 ( V_31 -> V_88 ) ;
F_12 ( & V_2 -> V_86 , V_17 ) ;
}
if ( ! V_2 -> V_89 ||
( ! F_35 ( V_2 , V_31 -> V_85 , V_77 ) &&
( F_14 ( V_31 -> V_76 ) != V_90 ) ) ) {
V_75 = F_27 ( V_2 , V_9 ) ;
return V_75 ;
}
V_78 = ( V_49 ) F_14 ( V_31 -> V_76 ) ;
V_75 = F_36 ( V_2 , F_14 ( V_31 -> V_88 ) ,
V_31 -> V_85 , V_77 , V_78 ,
V_9 ) ;
if ( V_75 || ( V_76 == V_84 ) )
F_28 ( V_9 ) ;
if ( V_75 )
V_2 -> V_54 . V_81 ++ ;
return V_75 ;
}
void * F_37 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_91 * V_92 ;
struct V_12 * V_13 = F_5 ( V_9 ) ;
int V_93 ;
T_1 V_78 , V_94 ;
int V_95 = ( V_2 -> V_15 -> V_96 == V_97 ) ? 0 :
V_98 ;
if ( ! V_9 -> V_62 ) {
F_15 ( V_15 , ERROR ,
L_8 , V_9 -> V_62 ) ;
V_13 -> V_99 = - 1 ;
return V_9 -> V_40 ;
}
F_38 ( F_19 ( V_9 ) < V_53 ) ;
V_78 = F_39 ( V_9 ) ? V_83 : 0 ;
V_93 = ( ( void * ) V_9 -> V_40 - ( sizeof( * V_92 ) + V_95 ) - NULL ) &
( V_100 - 1 ) ;
F_40 ( V_9 , sizeof( * V_92 ) + V_93 ) ;
V_92 = (struct V_91 * ) V_9 -> V_40 ;
memset ( V_92 , 0 , sizeof( * V_92 ) ) ;
V_92 -> V_57 = V_2 -> V_57 ;
V_92 -> V_58 = V_2 -> V_58 ;
V_92 -> V_101 = F_41 ( ( T_1 ) ( V_9 -> V_62 - ( sizeof( * V_92 ) +
V_93 ) ) ) ;
V_92 -> V_85 = ( V_49 ) V_9 -> V_85 ;
V_92 -> V_102 = F_42 ( V_2 , V_9 ) ;
if ( V_13 -> V_17 & V_103 ||
V_13 -> V_17 & V_104 ) {
V_92 -> V_105 = V_13 -> V_106 ;
V_92 -> V_17 |= V_107 ;
}
if ( V_92 -> V_85 < F_43 ( V_2 -> V_20 . V_108 ) )
V_92 -> V_109 =
F_44 ( V_2 -> V_20 . V_108 [ V_92 -> V_85 ] ) ;
V_94 = sizeof( * V_92 ) + V_93 ;
if ( V_78 == V_83 ) {
V_92 -> V_110 = F_41 ( V_78 ) ;
V_94 += V_111 ;
}
V_92 -> V_112 = F_41 ( V_94 ) ;
F_40 ( V_9 , V_95 ) ;
if ( ! V_92 -> V_109 )
V_92 -> V_109 = F_44 ( V_2 -> V_113 ) ;
return V_9 -> V_40 ;
}
