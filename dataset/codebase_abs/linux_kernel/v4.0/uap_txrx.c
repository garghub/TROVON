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
V_28 = (struct V_27 * ) ( V_8 -> V_35 ) ;
V_30 = ( void * ) V_28 + F_14 ( V_28 -> V_36 ) ;
if ( ( F_9 ( & V_14 -> V_20 ) >=
V_37 ) ) {
F_15 ( V_2 -> V_14 -> V_38 ,
L_1 ) ;
F_16 ( V_8 ) ;
F_10 ( V_2 ) ;
return;
}
if ( ( ! memcmp ( & V_30 -> V_39 , V_40 ,
sizeof( V_40 ) ) ) ||
( ! memcmp ( & V_30 -> V_39 , V_41 ,
sizeof( V_41 ) ) &&
F_17 ( V_30 -> V_39 . V_42 ) != V_43 &&
F_17 ( V_30 -> V_39 . V_42 ) != V_44 ) ) {
V_34 = (struct V_33 * )
( ( V_45 * ) ( & V_30 -> V_46 )
+ sizeof( V_30 -> V_46 )
+ sizeof( V_30 -> V_39 )
- sizeof( V_30 -> V_46 . V_47 )
- sizeof( V_30 -> V_46 . V_48 )
- sizeof( V_30 -> V_39 . V_42 ) ) ;
memcpy ( V_34 -> V_48 , V_30 -> V_46 . V_48 ,
sizeof( V_34 -> V_48 ) ) ;
memcpy ( V_34 -> V_47 , V_30 -> V_46 . V_47 ,
sizeof( V_34 -> V_47 ) ) ;
V_32 = ( V_45 * ) V_34 - ( V_45 * ) V_28 ;
} else {
V_32 = ( V_45 * ) & V_30 -> V_46 - ( V_45 * ) V_28 ;
}
F_18 ( V_8 , V_32 ) ;
if ( F_19 ( V_8 ) < V_49 ) {
F_20 ( V_2 -> V_14 -> V_38 ,
L_2 ,
F_19 ( V_8 ) ) ;
V_31 =
F_21 ( V_8 , V_49 ) ;
if ( F_22 ( ! V_31 ) ) {
F_15 ( V_2 -> V_14 -> V_38 ,
L_3 ) ;
F_16 ( V_8 ) ;
V_2 -> V_50 . V_51 ++ ;
return;
}
F_16 ( V_8 ) ;
V_8 = V_31 ;
F_20 ( V_2 -> V_14 -> V_38 , L_4 ,
F_19 ( V_8 ) ) ;
}
V_12 = F_5 ( V_8 ) ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
V_12 -> V_52 = V_2 -> V_52 ;
V_12 -> V_53 = V_2 -> V_53 ;
V_12 -> V_16 |= V_17 ;
if ( F_23 ( V_30 -> V_46 . V_47 ) ) {
V_2 -> V_50 . V_54 += V_8 -> V_55 ;
V_2 -> V_50 . V_56 ++ ;
V_12 -> V_57 = V_8 -> V_55 ;
}
F_24 ( V_8 ) ;
F_25 ( V_2 , V_8 ) ;
F_26 ( & V_14 -> V_58 ) ;
F_26 ( & V_14 -> V_20 ) ;
return;
}
int F_27 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
V_45 V_59 [ V_60 ] ;
struct V_7 * V_61 ;
V_28 = (struct V_27 * ) ( V_8 -> V_35 ) ;
V_30 = ( void * ) V_28 + F_14 ( V_28 -> V_36 ) ;
if ( ! V_2 -> V_62 ) {
F_15 ( V_14 -> V_38 , L_5 ) ;
F_28 ( V_8 ) ;
return 0 ;
}
memcpy ( V_59 , V_30 -> V_46 . V_47 , V_60 ) ;
if ( F_29 ( V_59 ) ) {
V_61 = F_30 ( V_8 , V_63 ) ;
F_13 ( V_2 , V_61 ) ;
} else {
if ( F_31 ( V_2 , V_59 ) ) {
F_13 ( V_2 , V_8 ) ;
return 0 ;
}
}
return F_32 ( V_2 , V_8 ) ;
}
int F_33 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_64 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
T_1 V_65 ;
V_45 V_66 [ V_60 ] , V_67 ;
unsigned long V_16 ;
struct V_68 * V_69 ;
V_28 = (struct V_27 * ) ( V_8 -> V_35 ) ;
V_65 = F_14 ( V_28 -> V_65 ) ;
V_30 = ( void * ) V_28 + F_14 ( V_28 -> V_36 ) ;
if ( ( F_14 ( V_28 -> V_36 ) +
F_14 ( V_28 -> V_70 ) ) > ( T_1 ) V_8 -> V_55 ) {
F_15 ( V_14 -> V_38 ,
L_6 ,
V_8 -> V_55 , F_14 ( V_28 -> V_36 ) ,
F_14 ( V_28 -> V_70 ) ) ;
V_2 -> V_50 . V_71 ++ ;
F_28 ( V_8 ) ;
return 0 ;
}
if ( V_65 == V_72 ) {
V_64 = F_34 ( V_2 , V_8 ) ;
if ( V_64 )
F_15 ( V_14 -> V_38 , L_7 ) ;
F_28 ( V_8 ) ;
return V_64 ;
}
memcpy ( V_66 , V_30 -> V_46 . V_48 , V_60 ) ;
if ( V_65 != V_73 && V_28 -> V_74 < V_24 ) {
F_11 ( & V_2 -> V_75 , V_16 ) ;
V_69 = F_31 ( V_2 , V_66 ) ;
if ( V_69 )
V_69 -> V_76 [ V_28 -> V_74 ] =
F_14 ( V_28 -> V_77 ) ;
F_12 ( & V_2 -> V_75 , V_16 ) ;
}
if ( ! V_2 -> V_78 ||
( ! F_35 ( V_2 , V_28 -> V_74 , V_66 ) &&
( F_14 ( V_28 -> V_65 ) != V_79 ) ) ) {
V_64 = F_27 ( V_2 , V_8 ) ;
return V_64 ;
}
V_67 = ( V_45 ) F_14 ( V_28 -> V_65 ) ;
V_64 = F_36 ( V_2 , F_14 ( V_28 -> V_77 ) ,
V_28 -> V_74 , V_66 , V_67 ,
V_8 ) ;
if ( V_64 || ( V_65 == V_73 ) )
F_28 ( V_8 ) ;
if ( V_64 )
V_2 -> V_50 . V_71 ++ ;
return V_64 ;
}
void * F_37 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_80 * V_81 ;
struct V_11 * V_12 = F_5 ( V_8 ) ;
int V_82 ;
T_1 V_67 , V_83 ;
int V_84 = ( V_2 -> V_14 -> V_85 == V_86 ) ? 0 :
V_87 ;
if ( ! V_8 -> V_55 ) {
F_15 ( V_14 -> V_38 , L_8 , V_8 -> V_55 ) ;
V_12 -> V_88 = - 1 ;
return V_8 -> V_35 ;
}
F_38 ( F_19 ( V_8 ) < V_49 ) ;
V_67 = F_39 ( V_8 ) ? V_72 : 0 ;
V_82 = ( ( void * ) V_8 -> V_35 - ( sizeof( * V_81 ) + V_84 ) - NULL ) &
( V_89 - 1 ) ;
F_40 ( V_8 , sizeof( * V_81 ) + V_82 ) ;
V_81 = (struct V_80 * ) V_8 -> V_35 ;
memset ( V_81 , 0 , sizeof( * V_81 ) ) ;
V_81 -> V_52 = V_2 -> V_52 ;
V_81 -> V_53 = V_2 -> V_53 ;
V_81 -> V_90 = F_41 ( ( T_1 ) ( V_8 -> V_55 - ( sizeof( * V_81 ) +
V_82 ) ) ) ;
V_81 -> V_74 = ( V_45 ) V_8 -> V_74 ;
V_81 -> V_91 = F_42 ( V_2 , V_8 ) ;
if ( V_12 -> V_16 & V_92 ||
V_12 -> V_16 & V_93 ) {
V_81 -> V_94 = V_12 -> V_95 ;
V_81 -> V_16 |= V_96 ;
}
if ( V_81 -> V_74 < F_43 ( V_2 -> V_18 . V_97 ) )
V_81 -> V_98 =
F_44 ( V_2 -> V_18 . V_97 [ V_81 -> V_74 ] ) ;
V_83 = sizeof( * V_81 ) + V_82 ;
if ( V_67 == V_72 ) {
V_81 -> V_99 = F_41 ( V_67 ) ;
V_83 += V_100 ;
}
V_81 -> V_101 = F_41 ( V_83 ) ;
F_40 ( V_8 , V_84 ) ;
if ( ! V_81 -> V_98 )
V_81 -> V_98 = F_44 ( V_2 -> V_102 ) ;
return V_8 -> V_35 ;
}
