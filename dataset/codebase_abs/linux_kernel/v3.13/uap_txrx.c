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
T_1 V_37 [ V_38 ] = { 0xaa , 0xaa , 0x03 , 0x00 , 0x00 , 0x00 } ;
V_28 = (struct V_27 * ) ( V_8 -> V_39 ) ;
V_30 = ( void * ) V_28 + F_14 ( V_28 -> V_40 ) ;
if ( ( F_9 ( & V_14 -> V_20 ) >=
V_41 ) ) {
F_15 ( V_2 -> V_14 -> V_42 ,
L_1 ) ;
F_16 ( V_8 ) ;
F_10 ( V_2 ) ;
return;
}
if ( ! memcmp ( & V_30 -> V_43 ,
V_37 , sizeof( V_37 ) ) ) {
V_36 = (struct V_35 * )
( ( T_1 * ) ( & V_30 -> V_44 )
+ sizeof( V_30 -> V_44 )
+ sizeof( V_30 -> V_43 )
- sizeof( V_30 -> V_44 . V_45 )
- sizeof( V_30 -> V_44 . V_46 )
- sizeof( V_30 -> V_43 . V_47 ) ) ;
memcpy ( V_36 -> V_46 , V_30 -> V_44 . V_46 ,
sizeof( V_36 -> V_46 ) ) ;
memcpy ( V_36 -> V_45 , V_30 -> V_44 . V_45 ,
sizeof( V_36 -> V_45 ) ) ;
V_32 = ( T_1 * ) V_36 - ( T_1 * ) V_28 ;
} else {
V_32 = ( T_1 * ) & V_30 -> V_44 - ( T_1 * ) V_28 ;
}
F_17 ( V_8 , V_32 ) ;
if ( F_18 ( V_8 ) < V_48 ) {
F_19 ( V_2 -> V_14 -> V_42 ,
L_2 ,
F_18 ( V_8 ) ) ;
V_31 =
F_20 ( V_8 , V_48 ) ;
if ( F_21 ( ! V_31 ) ) {
F_15 ( V_2 -> V_14 -> V_42 ,
L_3 ) ;
F_16 ( V_8 ) ;
V_2 -> V_49 . V_50 ++ ;
return;
}
F_16 ( V_8 ) ;
V_8 = V_31 ;
F_19 ( V_2 -> V_14 -> V_42 , L_4 ,
F_18 ( V_8 ) ) ;
}
V_12 = F_5 ( V_8 ) ;
V_12 -> V_51 = V_2 -> V_51 ;
V_12 -> V_52 = V_2 -> V_52 ;
V_12 -> V_16 |= V_17 ;
F_22 ( & V_34 ) ;
V_8 -> V_53 = F_23 ( V_34 ) ;
F_24 ( V_2 , V_8 ) ;
F_25 ( & V_14 -> V_54 ) ;
F_25 ( & V_14 -> V_20 ) ;
return;
}
int F_26 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
T_1 V_55 [ V_38 ] ;
struct V_7 * V_56 ;
V_28 = (struct V_27 * ) ( V_8 -> V_39 ) ;
V_30 = ( void * ) V_28 + F_14 ( V_28 -> V_40 ) ;
if ( ! V_2 -> V_57 ) {
F_15 ( V_14 -> V_42 , L_5 ) ;
F_27 ( V_8 ) ;
return 0 ;
}
memcpy ( V_55 , V_30 -> V_44 . V_45 , V_38 ) ;
if ( F_28 ( V_55 ) ) {
V_56 = F_29 ( V_8 , V_58 ) ;
F_13 ( V_2 , V_56 ) ;
} else {
if ( F_30 ( V_2 , V_55 ) ) {
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
int V_59 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
T_2 V_60 ;
T_1 V_61 [ V_38 ] , V_62 ;
struct V_63 * V_64 ;
V_28 = (struct V_27 * ) ( V_8 -> V_39 ) ;
V_60 = F_14 ( V_28 -> V_60 ) ;
V_30 = ( void * ) V_28 + F_14 ( V_28 -> V_40 ) ;
if ( ( F_14 ( V_28 -> V_40 ) +
F_14 ( V_28 -> V_65 ) ) > ( T_2 ) V_8 -> V_66 ) {
F_15 ( V_14 -> V_42 ,
L_6 ,
V_8 -> V_66 , F_14 ( V_28 -> V_40 ) ,
F_14 ( V_28 -> V_65 ) ) ;
V_2 -> V_49 . V_67 ++ ;
if ( V_14 -> V_68 . V_69 )
V_14 -> V_68 . V_69 ( V_14 , V_8 ) ;
else
F_27 ( V_8 ) ;
return 0 ;
}
if ( F_14 ( V_28 -> V_60 ) == V_70 ) {
struct V_71 V_72 ;
struct V_7 * V_73 ;
F_33 ( & V_72 ) ;
F_17 ( V_8 , F_14 ( V_28 -> V_40 ) ) ;
F_34 ( V_8 , F_14 ( V_28 -> V_65 ) ) ;
F_35 ( V_8 , & V_72 , V_2 -> V_74 ,
V_2 -> V_75 -> V_76 , 0 , false ) ;
while ( ! F_3 ( & V_72 ) ) {
V_73 = F_36 ( & V_72 ) ;
V_59 = F_37 ( V_2 , V_73 ) ;
if ( V_59 )
F_15 ( V_14 -> V_42 ,
L_7 ) ;
}
return 0 ;
} else if ( V_60 == V_77 ) {
V_59 = F_38 ( V_2 , V_8 ) ;
if ( V_59 )
F_15 ( V_14 -> V_42 , L_8 ) ;
F_27 ( V_8 ) ;
return V_59 ;
}
memcpy ( V_61 , V_30 -> V_44 . V_46 , V_38 ) ;
if ( V_60 != V_78 && V_28 -> V_79 < V_24 ) {
V_64 = F_30 ( V_2 , V_61 ) ;
if ( V_64 )
V_64 -> V_80 [ V_28 -> V_79 ] =
F_14 ( V_28 -> V_81 ) ;
}
if ( ! V_2 -> V_82 ||
( ! F_39 ( V_2 , V_28 -> V_79 , V_61 ) &&
( F_14 ( V_28 -> V_60 ) != V_70 ) ) ) {
V_59 = F_26 ( V_2 , V_8 ) ;
return V_59 ;
}
V_62 = ( T_1 ) F_14 ( V_28 -> V_60 ) ;
V_59 = F_40 ( V_2 , F_14 ( V_28 -> V_81 ) ,
V_28 -> V_79 , V_61 , V_62 ,
V_8 ) ;
if ( V_59 || ( V_60 == V_78 ) ) {
if ( V_14 -> V_68 . V_69 )
V_14 -> V_68 . V_69 ( V_14 , V_8 ) ;
else
F_27 ( V_8 ) ;
}
if ( V_59 )
V_2 -> V_49 . V_67 ++ ;
return V_59 ;
}
void * F_41 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_83 * V_84 ;
struct V_11 * V_12 = F_5 ( V_8 ) ;
int V_85 , V_66 ;
T_2 V_62 ;
if ( ! V_8 -> V_66 ) {
F_15 ( V_14 -> V_42 , L_9 , V_8 -> V_66 ) ;
V_12 -> V_86 = - 1 ;
return V_8 -> V_39 ;
}
V_62 = F_42 ( V_8 ) ? V_77 : 0 ;
V_85 = ( 4 - ( ( ( void * ) V_8 -> V_39 - NULL ) & 0x3 ) ) % 4 ;
V_66 = sizeof( * V_84 ) + V_85 ;
F_43 ( F_18 ( V_8 ) < V_66 + V_87 ) ;
F_44 ( V_8 , V_66 ) ;
V_84 = (struct V_83 * ) V_8 -> V_39 ;
memset ( V_84 , 0 , sizeof( * V_84 ) ) ;
V_84 -> V_51 = V_2 -> V_51 ;
V_84 -> V_52 = V_2 -> V_52 ;
V_84 -> V_88 = F_45 ( ( T_2 ) ( V_8 -> V_66 - V_66 ) ) ;
V_84 -> V_79 = ( T_1 ) V_8 -> V_79 ;
V_84 -> V_89 = F_46 ( V_2 , V_8 ) ;
if ( V_84 -> V_79 < F_47 ( V_2 -> V_18 . V_90 ) )
V_84 -> V_91 =
F_48 ( V_2 -> V_18 . V_90 [ V_84 -> V_79 ] ) ;
if ( V_62 == V_77 ) {
V_84 -> V_92 = F_45 ( V_62 ) ;
V_66 += V_93 ;
}
V_84 -> V_94 = F_45 ( V_66 ) ;
F_44 ( V_8 , V_87 ) ;
if ( ! V_84 -> V_91 )
V_84 -> V_91 = F_48 ( V_2 -> V_95 ) ;
return V_8 -> V_39 ;
}
