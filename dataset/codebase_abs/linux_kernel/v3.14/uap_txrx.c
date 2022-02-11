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
struct V_33 V_34 ;
struct V_35 * V_36 ;
V_28 = (struct V_27 * ) ( V_8 -> V_37 ) ;
V_30 = ( void * ) V_28 + F_14 ( V_28 -> V_38 ) ;
if ( ( F_9 ( & V_14 -> V_20 ) >=
V_39 ) ) {
F_15 ( V_2 -> V_14 -> V_40 ,
L_1 ) ;
F_16 ( V_8 ) ;
F_10 ( V_2 ) ;
return;
}
if ( ( ! memcmp ( & V_30 -> V_41 , V_42 ,
sizeof( V_42 ) ) ) ||
( ! memcmp ( & V_30 -> V_41 , V_43 ,
sizeof( V_43 ) ) &&
F_17 ( V_30 -> V_41 . V_44 ) != V_45 &&
F_17 ( V_30 -> V_41 . V_44 ) != V_46 ) ) {
V_36 = (struct V_35 * )
( ( V_47 * ) ( & V_30 -> V_48 )
+ sizeof( V_30 -> V_48 )
+ sizeof( V_30 -> V_41 )
- sizeof( V_30 -> V_48 . V_49 )
- sizeof( V_30 -> V_48 . V_50 )
- sizeof( V_30 -> V_41 . V_44 ) ) ;
memcpy ( V_36 -> V_50 , V_30 -> V_48 . V_50 ,
sizeof( V_36 -> V_50 ) ) ;
memcpy ( V_36 -> V_49 , V_30 -> V_48 . V_49 ,
sizeof( V_36 -> V_49 ) ) ;
V_32 = ( V_47 * ) V_36 - ( V_47 * ) V_28 ;
} else {
V_32 = ( V_47 * ) & V_30 -> V_48 - ( V_47 * ) V_28 ;
}
F_18 ( V_8 , V_32 ) ;
if ( F_19 ( V_8 ) < V_51 ) {
F_20 ( V_2 -> V_14 -> V_40 ,
L_2 ,
F_19 ( V_8 ) ) ;
V_31 =
F_21 ( V_8 , V_51 ) ;
if ( F_22 ( ! V_31 ) ) {
F_15 ( V_2 -> V_14 -> V_40 ,
L_3 ) ;
F_16 ( V_8 ) ;
V_2 -> V_52 . V_53 ++ ;
return;
}
F_16 ( V_8 ) ;
V_8 = V_31 ;
F_20 ( V_2 -> V_14 -> V_40 , L_4 ,
F_19 ( V_8 ) ) ;
}
V_12 = F_5 ( V_8 ) ;
V_12 -> V_54 = V_2 -> V_54 ;
V_12 -> V_55 = V_2 -> V_55 ;
V_12 -> V_16 |= V_17 ;
if ( F_23 ( V_30 -> V_48 . V_49 ) ) {
V_2 -> V_52 . V_56 += V_8 -> V_57 ;
V_2 -> V_52 . V_58 ++ ;
V_12 -> V_59 = V_8 -> V_57 ;
}
F_24 ( & V_34 ) ;
V_8 -> V_60 = F_25 ( V_34 ) ;
F_26 ( V_2 , V_8 ) ;
F_27 ( & V_14 -> V_61 ) ;
F_27 ( & V_14 -> V_20 ) ;
return;
}
int F_28 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
V_47 V_62 [ V_63 ] ;
struct V_7 * V_64 ;
V_28 = (struct V_27 * ) ( V_8 -> V_37 ) ;
V_30 = ( void * ) V_28 + F_14 ( V_28 -> V_38 ) ;
if ( ! V_2 -> V_65 ) {
F_15 ( V_14 -> V_40 , L_5 ) ;
F_29 ( V_8 ) ;
return 0 ;
}
memcpy ( V_62 , V_30 -> V_48 . V_49 , V_63 ) ;
if ( F_30 ( V_62 ) ) {
V_64 = F_31 ( V_8 , V_66 ) ;
F_13 ( V_2 , V_64 ) ;
} else {
if ( F_32 ( V_2 , V_62 ) ) {
F_13 ( V_2 , V_8 ) ;
return 0 ;
}
}
return F_33 ( V_2 , V_8 ) ;
}
int F_34 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_67 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
T_1 V_68 ;
V_47 V_69 [ V_63 ] , V_70 ;
struct V_71 * V_72 ;
V_28 = (struct V_27 * ) ( V_8 -> V_37 ) ;
V_68 = F_14 ( V_28 -> V_68 ) ;
V_30 = ( void * ) V_28 + F_14 ( V_28 -> V_38 ) ;
if ( ( F_14 ( V_28 -> V_38 ) +
F_14 ( V_28 -> V_73 ) ) > ( T_1 ) V_8 -> V_57 ) {
F_15 ( V_14 -> V_40 ,
L_6 ,
V_8 -> V_57 , F_14 ( V_28 -> V_38 ) ,
F_14 ( V_28 -> V_73 ) ) ;
V_2 -> V_52 . V_74 ++ ;
F_29 ( V_8 ) ;
return 0 ;
}
if ( F_14 ( V_28 -> V_68 ) == V_75 ) {
struct V_76 V_77 ;
struct V_7 * V_78 ;
F_35 ( & V_77 ) ;
F_18 ( V_8 , F_14 ( V_28 -> V_38 ) ) ;
F_36 ( V_8 , F_14 ( V_28 -> V_73 ) ) ;
F_37 ( V_8 , & V_77 , V_2 -> V_79 ,
V_2 -> V_80 -> V_81 , 0 , false ) ;
while ( ! F_3 ( & V_77 ) ) {
V_78 = F_38 ( & V_77 ) ;
V_67 = F_39 ( V_2 , V_78 ) ;
if ( V_67 )
F_15 ( V_14 -> V_40 ,
L_7 ) ;
}
return 0 ;
} else if ( V_68 == V_82 ) {
V_67 = F_40 ( V_2 , V_8 ) ;
if ( V_67 )
F_15 ( V_14 -> V_40 , L_8 ) ;
F_29 ( V_8 ) ;
return V_67 ;
}
memcpy ( V_69 , V_30 -> V_48 . V_50 , V_63 ) ;
if ( V_68 != V_83 && V_28 -> V_84 < V_24 ) {
V_72 = F_32 ( V_2 , V_69 ) ;
if ( V_72 )
V_72 -> V_85 [ V_28 -> V_84 ] =
F_14 ( V_28 -> V_86 ) ;
}
if ( ! V_2 -> V_87 ||
( ! F_41 ( V_2 , V_28 -> V_84 , V_69 ) &&
( F_14 ( V_28 -> V_68 ) != V_75 ) ) ) {
V_67 = F_28 ( V_2 , V_8 ) ;
return V_67 ;
}
V_70 = ( V_47 ) F_14 ( V_28 -> V_68 ) ;
V_67 = F_42 ( V_2 , F_14 ( V_28 -> V_86 ) ,
V_28 -> V_84 , V_69 , V_70 ,
V_8 ) ;
if ( V_67 || ( V_68 == V_83 ) )
F_29 ( V_8 ) ;
if ( V_67 )
V_2 -> V_52 . V_74 ++ ;
return V_67 ;
}
void * F_43 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_88 * V_89 ;
struct V_11 * V_12 = F_5 ( V_8 ) ;
int V_90 , V_57 ;
T_1 V_70 ;
if ( ! V_8 -> V_57 ) {
F_15 ( V_14 -> V_40 , L_9 , V_8 -> V_57 ) ;
V_12 -> V_91 = - 1 ;
return V_8 -> V_37 ;
}
V_70 = F_44 ( V_8 ) ? V_82 : 0 ;
V_90 = ( 4 - ( ( ( void * ) V_8 -> V_37 - NULL ) & 0x3 ) ) % 4 ;
V_57 = sizeof( * V_89 ) + V_90 ;
F_45 ( F_19 ( V_8 ) < V_57 + V_92 ) ;
F_46 ( V_8 , V_57 ) ;
V_89 = (struct V_88 * ) V_8 -> V_37 ;
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_54 = V_2 -> V_54 ;
V_89 -> V_55 = V_2 -> V_55 ;
V_89 -> V_93 = F_47 ( ( T_1 ) ( V_8 -> V_57 - V_57 ) ) ;
V_89 -> V_84 = ( V_47 ) V_8 -> V_84 ;
V_89 -> V_94 = F_48 ( V_2 , V_8 ) ;
if ( V_89 -> V_84 < F_49 ( V_2 -> V_18 . V_95 ) )
V_89 -> V_96 =
F_50 ( V_2 -> V_18 . V_95 [ V_89 -> V_84 ] ) ;
if ( V_70 == V_82 ) {
V_89 -> V_97 = F_47 ( V_70 ) ;
V_57 += V_98 ;
}
V_89 -> V_99 = F_47 ( V_57 ) ;
F_46 ( V_8 , V_92 ) ;
if ( ! V_89 -> V_96 )
V_89 -> V_96 = F_50 ( V_2 -> V_100 ) ;
return V_8 -> V_37 ;
}
