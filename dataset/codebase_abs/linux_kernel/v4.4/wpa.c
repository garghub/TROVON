T_1
F_1 ( struct V_1 * V_2 )
{
T_2 * V_3 , * V_4 , * V_5 ;
T_3 V_6 ;
unsigned int V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
int V_14 ;
V_9 = (struct V_8 * ) V_11 -> V_3 ;
if ( ! V_2 -> V_4 || V_2 -> V_4 -> V_15 . V_16 != V_17 ||
V_11 -> V_18 < 24 || ! F_3 ( V_9 -> V_19 ) )
return V_20 ;
V_7 = F_4 ( V_9 -> V_19 ) ;
if ( V_11 -> V_18 < V_7 )
return V_21 ;
V_3 = V_11 -> V_3 + V_7 ;
V_6 = V_11 -> V_18 - V_7 ;
if ( F_5 ( V_13 -> V_22 & V_23 ) ) {
V_13 -> V_24 . V_25 = NULL ;
}
if ( V_13 -> V_24 . V_25 &&
( V_13 -> V_22 & V_26 ||
V_2 -> V_27 -> V_28 -> V_29 ) &&
! ( V_2 -> V_4 -> V_15 . V_22 & V_30 ) ) {
return V_20 ;
}
V_14 = V_31 ;
if ( ! V_13 -> V_24 . V_25 )
V_14 += V_32 ;
if ( F_6 ( F_7 ( V_11 ) < V_14 ||
F_8 ( V_11 ) < V_33 ,
L_1 ,
F_8 ( V_11 ) , V_33 ,
F_7 ( V_11 ) , V_14 ) )
return V_21 ;
V_4 = & V_2 -> V_4 -> V_15 . V_4 [ V_34 ] ;
V_5 = F_9 ( V_11 , V_31 ) ;
F_10 ( V_4 , V_9 , V_3 , V_6 , V_5 ) ;
if ( F_5 ( V_13 -> V_22 & V_23 ) )
V_5 [ 0 ] ++ ;
return V_20 ;
}
T_4
F_11 ( struct V_35 * V_36 )
{
T_2 * V_3 , * V_4 = NULL ;
T_3 V_6 ;
unsigned int V_7 ;
T_2 V_5 [ V_31 ] ;
struct V_10 * V_11 = V_36 -> V_11 ;
struct V_37 * V_38 = F_12 ( V_11 ) ;
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
if ( ! F_3 ( V_9 -> V_19 ) )
return V_39 ;
if ( V_38 -> V_40 & ( V_41 | V_42 ) ) {
if ( V_38 -> V_40 & V_43 )
goto V_44;
if ( ! ( V_38 -> V_40 & V_42 ) && V_36 -> V_4 &&
V_36 -> V_4 -> V_15 . V_16 == V_17 )
goto V_45;
return V_39 ;
}
if ( ! V_36 -> V_4 || V_36 -> V_4 -> V_15 . V_16 != V_17 ||
! ( V_38 -> V_40 & V_46 ) )
return V_39 ;
if ( V_36 -> V_47 -> V_48 . type == V_49 && V_36 -> V_4 -> V_15 . V_50 ) {
return V_51 ;
}
if ( V_38 -> V_40 & V_43 )
goto V_52;
V_7 = F_4 ( V_9 -> V_19 ) ;
if ( V_11 -> V_18 < V_7 + V_31 )
return V_51 ;
if ( F_13 ( V_36 -> V_11 ) )
return V_51 ;
V_9 = ( void * ) V_11 -> V_3 ;
V_3 = V_11 -> V_3 + V_7 ;
V_6 = V_11 -> V_18 - V_7 - V_31 ;
V_4 = & V_36 -> V_4 -> V_15 . V_4 [ V_53 ] ;
F_10 ( V_4 , V_9 , V_3 , V_6 , V_5 ) ;
if ( memcmp ( V_5 , V_3 + V_6 , V_31 ) != 0 )
goto V_52;
F_14 ( V_11 , V_11 -> V_18 - V_31 ) ;
V_45:
V_36 -> V_4 -> V_54 . V_55 . V_36 [ V_36 -> V_56 ] . V_57 = V_36 -> V_58 ;
V_36 -> V_4 -> V_54 . V_55 . V_36 [ V_36 -> V_56 ] . V_59 = V_36 -> V_60 ;
return V_39 ;
V_52:
V_36 -> V_4 -> V_54 . V_55 . V_61 ++ ;
V_44:
F_15 ( V_36 -> V_47 -> V_62 , V_9 -> V_63 ,
F_16 ( V_9 -> V_64 ) ?
V_65 :
V_66 ,
V_36 -> V_4 ? V_36 -> V_4 -> V_15 . V_50 : - 1 ,
NULL , V_67 ) ;
return V_51 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
struct V_68 * V_4 = V_2 -> V_4 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
unsigned int V_7 ;
int V_18 , V_14 ;
T_2 * V_69 ;
if ( V_13 -> V_24 . V_25 &&
! ( V_13 -> V_24 . V_25 -> V_22 & V_70 ) &&
! ( V_13 -> V_24 . V_25 -> V_22 & V_71 ) ) {
return 0 ;
}
V_7 = F_4 ( V_9 -> V_19 ) ;
V_18 = V_11 -> V_18 - V_7 ;
if ( V_13 -> V_24 . V_25 )
V_14 = 0 ;
else
V_14 = V_32 ;
if ( F_18 ( F_7 ( V_11 ) < V_14 ||
F_8 ( V_11 ) < V_33 ) )
return - 1 ;
V_69 = F_19 ( V_11 , V_33 ) ;
memmove ( V_69 , V_69 + V_33 , V_7 ) ;
V_69 += V_7 ;
if ( V_13 -> V_24 . V_25 &&
( V_13 -> V_24 . V_25 -> V_22 & V_71 ) )
return 0 ;
F_20 ( & V_4 -> V_54 . V_55 . V_72 ) ;
V_4 -> V_54 . V_55 . V_2 . V_59 ++ ;
if ( V_4 -> V_54 . V_55 . V_2 . V_59 == 0 )
V_4 -> V_54 . V_55 . V_2 . V_57 ++ ;
V_69 = F_21 ( V_69 , V_4 ) ;
F_22 ( & V_4 -> V_54 . V_55 . V_72 ) ;
if ( V_13 -> V_24 . V_25 )
return 0 ;
F_9 ( V_11 , V_32 ) ;
return F_23 ( V_2 -> V_27 -> V_73 ,
V_4 , V_11 , V_69 , V_18 ) ;
}
T_1
F_24 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
F_25 ( V_2 ) ;
F_26 (&tx->skbs, skb) {
if ( F_17 ( V_2 , V_11 ) < 0 )
return V_21 ;
}
return V_20 ;
}
T_4
F_27 ( struct V_35 * V_36 )
{
struct V_8 * V_9 = (struct V_8 * ) V_36 -> V_11 -> V_3 ;
int V_7 , V_74 , V_75 = 0 ;
struct V_68 * V_4 = V_36 -> V_4 ;
struct V_10 * V_11 = V_36 -> V_11 ;
struct V_37 * V_38 = F_12 ( V_11 ) ;
V_7 = F_4 ( V_9 -> V_19 ) ;
if ( ! F_28 ( V_9 -> V_19 ) )
return V_39 ;
if ( ! V_36 -> V_76 || V_11 -> V_18 - V_7 < 12 )
return V_51 ;
if ( F_13 ( V_36 -> V_11 ) )
return V_51 ;
V_9 = ( void * ) V_11 -> V_3 ;
if ( V_38 -> V_40 & V_46 )
V_75 = 1 ;
V_74 = F_29 ( V_36 -> V_27 -> V_77 ,
V_4 , V_11 -> V_3 + V_7 ,
V_11 -> V_18 - V_7 , V_36 -> V_76 -> V_76 . V_78 ,
V_9 -> V_64 , V_75 , V_36 -> V_56 ,
& V_36 -> V_58 ,
& V_36 -> V_60 ) ;
if ( V_74 != V_79 )
return V_51 ;
F_14 ( V_11 , V_11 -> V_18 - V_32 ) ;
memmove ( V_11 -> V_3 + V_33 , V_11 -> V_3 , V_7 ) ;
F_30 ( V_11 , V_33 ) ;
return V_39 ;
}
static void F_31 ( struct V_10 * V_11 , T_2 * V_80 , T_2 * V_81 , T_2 * V_82 )
{
T_5 V_83 ;
int V_84 , V_85 ;
T_2 V_86 ;
T_6 V_87 ;
unsigned int V_7 ;
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
V_85 = F_32 ( V_9 -> V_19 ) ;
V_83 = V_9 -> V_19 ;
V_83 &= ~ F_33 ( V_88 |
V_89 | V_90 ) ;
if ( ! V_85 )
V_83 &= ~ F_33 ( 0x0070 ) ;
V_83 |= F_33 ( V_91 ) ;
V_7 = F_4 ( V_9 -> V_19 ) ;
V_87 = V_7 - 2 ;
V_84 = F_34 ( V_9 -> V_19 ) ;
if ( F_35 ( V_9 -> V_19 ) )
V_86 = * F_36 ( V_9 ) & V_92 ;
else
V_86 = 0 ;
V_81 [ 0 ] = 0x1 ;
V_81 [ 1 ] = V_86 | ( V_85 << 4 ) ;
memcpy ( & V_81 [ 2 ] , V_9 -> V_63 , V_93 ) ;
memcpy ( & V_81 [ 8 ] , V_80 , V_94 ) ;
F_37 ( V_87 , & V_82 [ 0 ] ) ;
F_38 ( V_83 , ( T_5 * ) & V_82 [ 2 ] ) ;
memcpy ( & V_82 [ 4 ] , & V_9 -> V_64 , 3 * V_93 ) ;
V_82 [ 22 ] = * ( ( T_2 * ) & V_9 -> V_95 ) & 0x0f ;
V_82 [ 23 ] = 0 ;
if ( V_84 ) {
memcpy ( & V_82 [ 24 ] , V_9 -> V_96 , V_93 ) ;
V_82 [ 30 ] = V_86 ;
V_82 [ 31 ] = 0 ;
} else {
memset ( & V_82 [ 24 ] , 0 , V_93 + V_97 ) ;
V_82 [ 24 ] = V_86 ;
}
}
static inline void F_39 ( T_2 * V_9 , T_2 * V_80 , int V_98 )
{
V_9 [ 0 ] = V_80 [ 5 ] ;
V_9 [ 1 ] = V_80 [ 4 ] ;
V_9 [ 2 ] = 0 ;
V_9 [ 3 ] = 0x20 | ( V_98 << 6 ) ;
V_9 [ 4 ] = V_80 [ 3 ] ;
V_9 [ 5 ] = V_80 [ 2 ] ;
V_9 [ 6 ] = V_80 [ 1 ] ;
V_9 [ 7 ] = V_80 [ 0 ] ;
}
static inline void F_40 ( T_2 * V_80 , T_2 * V_9 )
{
V_80 [ 0 ] = V_9 [ 7 ] ;
V_80 [ 1 ] = V_9 [ 6 ] ;
V_80 [ 2 ] = V_9 [ 5 ] ;
V_80 [ 3 ] = V_9 [ 4 ] ;
V_80 [ 4 ] = V_9 [ 1 ] ;
V_80 [ 5 ] = V_9 [ 0 ] ;
}
static int F_41 ( struct V_1 * V_2 , struct V_10 * V_11 ,
unsigned int V_99 )
{
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
struct V_68 * V_4 = V_2 -> V_4 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
int V_7 , V_18 , V_14 ;
T_2 * V_69 ;
T_2 V_80 [ 6 ] ;
T_7 V_100 ;
T_2 V_82 [ 2 * V_101 ] ;
T_2 V_81 [ V_101 ] ;
if ( V_13 -> V_24 . V_25 &&
! ( V_13 -> V_24 . V_25 -> V_22 & V_70 ) &&
! ( V_13 -> V_24 . V_25 -> V_22 & V_71 ) &&
! ( ( V_13 -> V_24 . V_25 -> V_22 &
V_102 ) &&
F_32 ( V_9 -> V_19 ) ) ) {
return 0 ;
}
V_7 = F_4 ( V_9 -> V_19 ) ;
V_18 = V_11 -> V_18 - V_7 ;
if ( V_13 -> V_24 . V_25 )
V_14 = 0 ;
else
V_14 = V_99 ;
if ( F_18 ( F_7 ( V_11 ) < V_14 ||
F_8 ( V_11 ) < V_103 ) )
return - 1 ;
V_69 = F_19 ( V_11 , V_103 ) ;
memmove ( V_69 , V_69 + V_103 , V_7 ) ;
if ( V_13 -> V_24 . V_25 &&
( V_13 -> V_24 . V_25 -> V_22 & V_71 ) )
return 0 ;
V_9 = (struct V_8 * ) V_69 ;
V_69 += V_7 ;
V_100 = F_42 ( & V_4 -> V_15 . V_104 ) ;
V_80 [ 5 ] = V_100 ;
V_80 [ 4 ] = V_100 >> 8 ;
V_80 [ 3 ] = V_100 >> 16 ;
V_80 [ 2 ] = V_100 >> 24 ;
V_80 [ 1 ] = V_100 >> 32 ;
V_80 [ 0 ] = V_100 >> 40 ;
F_39 ( V_69 , V_80 , V_4 -> V_15 . V_50 ) ;
if ( V_13 -> V_24 . V_25 )
return 0 ;
V_69 += V_103 ;
F_31 ( V_11 , V_80 , V_81 , V_82 ) ;
F_43 ( V_4 -> V_54 . V_105 . V_106 , V_81 , V_82 , V_69 , V_18 ,
F_9 ( V_11 , V_99 ) , V_99 ) ;
return 0 ;
}
T_1
F_44 ( struct V_1 * V_2 ,
unsigned int V_99 )
{
struct V_10 * V_11 ;
F_25 ( V_2 ) ;
F_26 (&tx->skbs, skb) {
if ( F_41 ( V_2 , V_11 , V_99 ) < 0 )
return V_21 ;
}
return V_20 ;
}
T_4
F_45 ( struct V_35 * V_36 ,
unsigned int V_99 )
{
struct V_8 * V_9 = (struct V_8 * ) V_36 -> V_11 -> V_3 ;
int V_7 ;
struct V_68 * V_4 = V_36 -> V_4 ;
struct V_10 * V_11 = V_36 -> V_11 ;
struct V_37 * V_38 = F_12 ( V_11 ) ;
T_2 V_80 [ V_94 ] ;
int V_6 ;
int V_107 ;
V_7 = F_4 ( V_9 -> V_19 ) ;
if ( ! F_28 ( V_9 -> V_19 ) &&
! F_46 ( V_11 ) )
return V_39 ;
V_6 = V_11 -> V_18 - V_7 - V_103 - V_99 ;
if ( ! V_36 -> V_76 || V_6 < 0 )
return V_51 ;
if ( V_38 -> V_40 & V_46 ) {
if ( ! F_47 ( V_36 -> V_11 , V_7 + V_103 ) )
return V_51 ;
} else {
if ( F_13 ( V_36 -> V_11 ) )
return V_51 ;
}
if ( ! ( V_38 -> V_40 & V_108 ) ) {
F_40 ( V_80 , V_11 -> V_3 + V_7 ) ;
V_107 = V_36 -> V_56 ;
if ( memcmp ( V_80 , V_4 -> V_54 . V_105 . V_109 [ V_107 ] ,
V_94 ) <= 0 ) {
V_4 -> V_54 . V_105 . V_110 ++ ;
return V_51 ;
}
if ( ! ( V_38 -> V_40 & V_46 ) ) {
T_2 V_82 [ 2 * V_101 ] ;
T_2 V_81 [ V_101 ] ;
F_31 ( V_11 , V_80 , V_81 , V_82 ) ;
if ( F_48 (
V_4 -> V_54 . V_105 . V_106 , V_81 , V_82 ,
V_11 -> V_3 + V_7 + V_103 ,
V_6 ,
V_11 -> V_3 + V_11 -> V_18 - V_99 , V_99 ) )
return V_51 ;
}
memcpy ( V_4 -> V_54 . V_105 . V_109 [ V_107 ] , V_80 , V_94 ) ;
}
if ( F_49 ( V_11 , V_11 -> V_18 - V_99 ) )
return V_51 ;
memmove ( V_11 -> V_3 + V_103 , V_11 -> V_3 , V_7 ) ;
F_30 ( V_11 , V_103 ) ;
return V_39 ;
}
static void F_50 ( struct V_10 * V_11 , T_2 * V_80 , T_2 * V_111 , T_2 * V_82 )
{
T_5 V_83 ;
T_2 V_86 ;
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
memcpy ( V_111 , V_9 -> V_63 , V_93 ) ;
memcpy ( & V_111 [ V_93 ] , V_80 , V_112 ) ;
V_111 [ 13 ] = 0 ;
V_111 [ 14 ] = 0 ;
V_111 [ V_101 - 1 ] = 0x01 ;
F_37 ( F_4 ( V_9 -> V_19 ) - 2 , & V_82 [ 0 ] ) ;
V_83 = V_9 -> V_19 ;
V_83 &= ~ F_33 ( V_88 |
V_89 | V_90 ) ;
if ( ! F_32 ( V_9 -> V_19 ) )
V_83 &= ~ F_33 ( 0x0070 ) ;
V_83 |= F_33 ( V_91 ) ;
F_38 ( V_83 , ( T_5 * ) & V_82 [ 2 ] ) ;
memcpy ( & V_82 [ 4 ] , & V_9 -> V_64 , 3 * V_93 ) ;
V_82 [ 22 ] = * ( ( T_2 * ) & V_9 -> V_95 ) & 0x0f ;
V_82 [ 23 ] = 0 ;
if ( F_35 ( V_9 -> V_19 ) )
V_86 = * F_36 ( V_9 ) &
V_92 ;
else
V_86 = 0 ;
if ( F_34 ( V_9 -> V_19 ) ) {
memcpy ( & V_82 [ 24 ] , V_9 -> V_96 , V_93 ) ;
V_82 [ 30 ] = V_86 ;
V_82 [ 31 ] = 0 ;
} else {
memset ( & V_82 [ 24 ] , 0 , V_93 + V_97 ) ;
V_82 [ 24 ] = V_86 ;
}
}
static inline void F_51 ( T_2 * V_9 , const T_2 * V_80 , int V_98 )
{
V_9 [ 0 ] = V_80 [ 5 ] ;
V_9 [ 1 ] = V_80 [ 4 ] ;
V_9 [ 2 ] = 0 ;
V_9 [ 3 ] = 0x20 | ( V_98 << 6 ) ;
V_9 [ 4 ] = V_80 [ 3 ] ;
V_9 [ 5 ] = V_80 [ 2 ] ;
V_9 [ 6 ] = V_80 [ 1 ] ;
V_9 [ 7 ] = V_80 [ 0 ] ;
}
static inline void F_52 ( T_2 * V_80 , const T_2 * V_9 )
{
V_80 [ 0 ] = V_9 [ 7 ] ;
V_80 [ 1 ] = V_9 [ 6 ] ;
V_80 [ 2 ] = V_9 [ 5 ] ;
V_80 [ 3 ] = V_9 [ 4 ] ;
V_80 [ 4 ] = V_9 [ 1 ] ;
V_80 [ 5 ] = V_9 [ 0 ] ;
}
static int F_53 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
struct V_68 * V_4 = V_2 -> V_4 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
int V_7 , V_18 , V_14 ;
T_2 * V_69 ;
T_2 V_80 [ 6 ] ;
T_7 V_100 ;
T_2 V_82 [ 2 * V_101 ] ;
T_2 V_111 [ V_101 ] ;
if ( V_13 -> V_24 . V_25 &&
! ( V_13 -> V_24 . V_25 -> V_22 & V_70 ) &&
! ( V_13 -> V_24 . V_25 -> V_22 & V_71 ) &&
! ( ( V_13 -> V_24 . V_25 -> V_22 &
V_102 ) &&
F_32 ( V_9 -> V_19 ) ) ) {
return 0 ;
}
V_7 = F_4 ( V_9 -> V_19 ) ;
V_18 = V_11 -> V_18 - V_7 ;
if ( V_13 -> V_24 . V_25 )
V_14 = 0 ;
else
V_14 = V_113 ;
if ( F_18 ( F_7 ( V_11 ) < V_14 ||
F_8 ( V_11 ) < V_114 ) )
return - 1 ;
V_69 = F_19 ( V_11 , V_114 ) ;
memmove ( V_69 , V_69 + V_114 , V_7 ) ;
F_54 ( V_11 , F_55 ( V_11 ) +
V_114 ) ;
if ( V_13 -> V_24 . V_25 &&
( V_13 -> V_24 . V_25 -> V_22 & V_71 ) )
return 0 ;
V_9 = (struct V_8 * ) V_69 ;
V_69 += V_7 ;
V_100 = F_42 ( & V_4 -> V_15 . V_104 ) ;
V_80 [ 5 ] = V_100 ;
V_80 [ 4 ] = V_100 >> 8 ;
V_80 [ 3 ] = V_100 >> 16 ;
V_80 [ 2 ] = V_100 >> 24 ;
V_80 [ 1 ] = V_100 >> 32 ;
V_80 [ 0 ] = V_100 >> 40 ;
F_51 ( V_69 , V_80 , V_4 -> V_15 . V_50 ) ;
if ( V_13 -> V_24 . V_25 )
return 0 ;
V_69 += V_114 ;
F_50 ( V_11 , V_80 , V_111 , V_82 ) ;
F_56 ( V_4 -> V_54 . V_115 . V_106 , V_111 , V_82 , V_69 , V_18 ,
F_9 ( V_11 , V_113 ) ) ;
return 0 ;
}
T_1
F_57 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
F_25 ( V_2 ) ;
F_26 (&tx->skbs, skb) {
if ( F_53 ( V_2 , V_11 ) < 0 )
return V_21 ;
}
return V_20 ;
}
T_4
F_58 ( struct V_35 * V_36 )
{
struct V_8 * V_9 = (struct V_8 * ) V_36 -> V_11 -> V_3 ;
int V_7 ;
struct V_68 * V_4 = V_36 -> V_4 ;
struct V_10 * V_11 = V_36 -> V_11 ;
struct V_37 * V_38 = F_12 ( V_11 ) ;
T_2 V_80 [ V_112 ] ;
int V_6 ;
int V_107 ;
V_7 = F_4 ( V_9 -> V_19 ) ;
if ( ! F_28 ( V_9 -> V_19 ) &&
! F_46 ( V_11 ) )
return V_39 ;
V_6 = V_11 -> V_18 - V_7 - V_114 -
V_113 ;
if ( ! V_36 -> V_76 || V_6 < 0 )
return V_51 ;
if ( V_38 -> V_40 & V_46 ) {
if ( ! F_47 ( V_36 -> V_11 , V_7 + V_114 ) )
return V_51 ;
} else {
if ( F_13 ( V_36 -> V_11 ) )
return V_51 ;
}
if ( ! ( V_38 -> V_40 & V_108 ) ) {
F_52 ( V_80 , V_11 -> V_3 + V_7 ) ;
V_107 = V_36 -> V_56 ;
if ( memcmp ( V_80 , V_4 -> V_54 . V_115 . V_109 [ V_107 ] ,
V_112 ) <= 0 ) {
V_4 -> V_54 . V_115 . V_110 ++ ;
return V_51 ;
}
if ( ! ( V_38 -> V_40 & V_46 ) ) {
T_2 V_82 [ 2 * V_101 ] ;
T_2 V_111 [ V_101 ] ;
F_50 ( V_11 , V_80 , V_111 , V_82 ) ;
if ( F_59 (
V_4 -> V_54 . V_115 . V_106 , V_111 , V_82 ,
V_11 -> V_3 + V_7 + V_114 ,
V_6 ,
V_11 -> V_3 + V_11 -> V_18 -
V_113 ) )
return V_51 ;
}
memcpy ( V_4 -> V_54 . V_115 . V_109 [ V_107 ] , V_80 , V_112 ) ;
}
if ( F_49 ( V_11 , V_11 -> V_18 - V_113 ) )
return V_51 ;
memmove ( V_11 -> V_3 + V_114 , V_11 -> V_3 , V_7 ) ;
F_30 ( V_11 , V_114 ) ;
return V_39 ;
}
static T_1
F_60 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
struct V_68 * V_4 = V_2 -> V_4 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
int V_7 ;
T_2 * V_69 , V_116 = V_4 -> V_15 . V_116 ;
if ( V_13 -> V_24 . V_25 &&
! ( V_13 -> V_24 . V_25 -> V_22 & V_71 ) ) {
return V_20 ;
}
if ( F_5 ( F_8 ( V_11 ) < V_116 &&
F_61 ( V_11 , V_116 , 0 , V_67 ) ) )
return V_21 ;
V_7 = F_4 ( V_9 -> V_19 ) ;
V_69 = F_19 ( V_11 , V_116 ) ;
memmove ( V_69 , V_69 + V_116 , V_7 ) ;
return V_20 ;
}
static inline int F_62 ( T_2 * V_117 , T_2 * V_118 , int V_18 )
{
int V_119 ;
for ( V_119 = V_18 - 1 ; V_119 >= 0 ; V_119 -- ) {
if ( V_117 [ V_119 ] < V_118 [ V_119 ] )
return - 1 ;
else if ( V_117 [ V_119 ] > V_118 [ V_119 ] )
return 1 ;
}
return 0 ;
}
static T_4
F_63 ( struct V_35 * V_36 )
{
struct V_68 * V_4 = V_36 -> V_4 ;
struct V_8 * V_9 = (struct V_8 * ) V_36 -> V_11 -> V_3 ;
const struct V_120 * V_121 = NULL ;
int V_7 = F_4 ( V_9 -> V_19 ) ;
struct V_37 * V_38 = F_12 ( V_36 -> V_11 ) ;
int V_6 ;
T_2 * V_109 ;
T_2 * V_122 ;
T_2 V_86 ;
if ( ! V_36 -> V_76 || ! V_36 -> V_76 -> V_123 ||
! ( V_38 -> V_40 & V_46 ) )
return V_51 ;
if ( ! F_28 ( V_9 -> V_19 ) )
return V_39 ;
V_121 = V_36 -> V_76 -> V_123 ;
V_6 = V_36 -> V_11 -> V_18 - V_7 - V_121 -> V_124 ;
if ( V_6 < 0 )
return V_51 ;
if ( F_35 ( V_9 -> V_19 ) )
V_86 = * F_36 ( V_9 ) &
V_92 ;
else
V_86 = 0 ;
if ( F_13 ( V_36 -> V_11 ) )
return V_51 ;
V_9 = (struct V_8 * ) V_36 -> V_11 -> V_3 ;
V_109 = V_4 -> V_54 . V_125 . V_109 [ V_86 ] ;
V_122 = V_36 -> V_11 -> V_3 + V_7 + V_121 -> V_126 ;
if ( F_62 ( V_122 , V_109 , V_121 -> V_127 ) <= 0 )
return V_51 ;
memcpy ( V_109 , V_122 , V_121 -> V_127 ) ;
if ( F_49 ( V_36 -> V_11 , V_36 -> V_11 -> V_18 - V_121 -> V_99 ) )
return V_51 ;
memmove ( V_36 -> V_11 -> V_3 + V_121 -> V_124 , V_36 -> V_11 -> V_3 , V_7 ) ;
F_30 ( V_36 -> V_11 , V_121 -> V_124 ) ;
return V_39 ;
}
static void F_64 ( struct V_10 * V_11 , T_2 * V_82 )
{
T_5 V_83 ;
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
V_83 = V_9 -> V_19 ;
V_83 &= ~ F_33 ( V_88 | V_89 |
V_90 ) ;
F_38 ( V_83 , ( T_5 * ) & V_82 [ 0 ] ) ;
memcpy ( V_82 + 2 , & V_9 -> V_64 , 3 * V_93 ) ;
}
static inline void F_65 ( T_2 * V_128 , T_7 V_80 )
{
* V_128 ++ = V_80 ;
* V_128 ++ = V_80 >> 8 ;
* V_128 ++ = V_80 >> 16 ;
* V_128 ++ = V_80 >> 24 ;
* V_128 ++ = V_80 >> 32 ;
* V_128 = V_80 >> 40 ;
}
static inline void F_66 ( T_2 * V_128 , const T_2 * V_129 )
{
* V_128 ++ = V_129 [ 5 ] ;
* V_128 ++ = V_129 [ 4 ] ;
* V_128 ++ = V_129 [ 3 ] ;
* V_128 ++ = V_129 [ 2 ] ;
* V_128 ++ = V_129 [ 1 ] ;
* V_128 = V_129 [ 0 ] ;
}
T_1
F_67 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_68 * V_4 = V_2 -> V_4 ;
struct V_130 * V_131 ;
T_2 V_82 [ 20 ] ;
T_7 V_100 ;
if ( F_18 ( F_68 ( & V_2 -> V_132 ) != 1 ) )
return V_21 ;
V_11 = F_69 ( & V_2 -> V_132 ) ;
V_13 = F_2 ( V_11 ) ;
if ( V_13 -> V_24 . V_25 )
return V_20 ;
if ( F_18 ( F_7 ( V_11 ) < sizeof( * V_131 ) ) )
return V_21 ;
V_131 = (struct V_130 * ) F_9 ( V_11 , sizeof( * V_131 ) ) ;
V_131 -> V_133 = V_134 ;
V_131 -> V_135 = sizeof( * V_131 ) - 2 ;
V_131 -> V_98 = F_33 ( V_4 -> V_15 . V_50 ) ;
V_100 = F_42 ( & V_4 -> V_15 . V_104 ) ;
F_65 ( V_131 -> V_136 , V_100 ) ;
F_64 ( V_11 , V_82 ) ;
F_70 ( V_4 -> V_54 . V_137 . V_106 , V_82 ,
V_11 -> V_3 + 24 , V_11 -> V_18 - 24 , V_131 -> V_5 ) ;
return V_20 ;
}
T_1
F_71 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_68 * V_4 = V_2 -> V_4 ;
struct V_138 * V_131 ;
T_2 V_82 [ 20 ] ;
T_7 V_100 ;
if ( F_18 ( F_68 ( & V_2 -> V_132 ) != 1 ) )
return V_21 ;
V_11 = F_69 ( & V_2 -> V_132 ) ;
V_13 = F_2 ( V_11 ) ;
if ( V_13 -> V_24 . V_25 )
return V_20 ;
if ( F_18 ( F_7 ( V_11 ) < sizeof( * V_131 ) ) )
return V_21 ;
V_131 = (struct V_138 * ) F_9 ( V_11 , sizeof( * V_131 ) ) ;
V_131 -> V_133 = V_134 ;
V_131 -> V_135 = sizeof( * V_131 ) - 2 ;
V_131 -> V_98 = F_33 ( V_4 -> V_15 . V_50 ) ;
V_100 = F_42 ( & V_4 -> V_15 . V_104 ) ;
F_65 ( V_131 -> V_136 , V_100 ) ;
F_64 ( V_11 , V_82 ) ;
F_72 ( V_4 -> V_54 . V_137 . V_106 , V_82 ,
V_11 -> V_3 + 24 , V_11 -> V_18 - 24 , V_131 -> V_5 ) ;
return V_20 ;
}
T_4
F_73 ( struct V_35 * V_36 )
{
struct V_10 * V_11 = V_36 -> V_11 ;
struct V_37 * V_38 = F_12 ( V_11 ) ;
struct V_68 * V_4 = V_36 -> V_4 ;
struct V_130 * V_131 ;
T_2 V_82 [ 20 ] , V_5 [ 8 ] , V_139 [ 6 ] ;
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
if ( ! F_32 ( V_9 -> V_19 ) )
return V_39 ;
if ( V_11 -> V_18 < 24 + sizeof( * V_131 ) )
return V_51 ;
V_131 = (struct V_130 * )
( V_11 -> V_3 + V_11 -> V_18 - sizeof( * V_131 ) ) ;
if ( V_131 -> V_133 != V_134 ||
V_131 -> V_135 != sizeof( * V_131 ) - 2 )
return V_51 ;
F_66 ( V_139 , V_131 -> V_136 ) ;
if ( memcmp ( V_139 , V_4 -> V_54 . V_137 . V_109 , 6 ) <= 0 ) {
V_4 -> V_54 . V_137 . V_110 ++ ;
return V_51 ;
}
if ( ! ( V_38 -> V_40 & V_46 ) ) {
F_64 ( V_11 , V_82 ) ;
F_70 ( V_4 -> V_54 . V_137 . V_106 , V_82 ,
V_11 -> V_3 + 24 , V_11 -> V_18 - 24 , V_5 ) ;
if ( memcmp ( V_5 , V_131 -> V_5 , sizeof( V_131 -> V_5 ) ) != 0 ) {
V_4 -> V_54 . V_137 . V_140 ++ ;
return V_51 ;
}
}
memcpy ( V_4 -> V_54 . V_137 . V_109 , V_139 , 6 ) ;
F_14 ( V_11 , V_11 -> V_18 - sizeof( * V_131 ) ) ;
return V_39 ;
}
T_4
F_74 ( struct V_35 * V_36 )
{
struct V_10 * V_11 = V_36 -> V_11 ;
struct V_37 * V_38 = F_12 ( V_11 ) ;
struct V_68 * V_4 = V_36 -> V_4 ;
struct V_138 * V_131 ;
T_2 V_82 [ 20 ] , V_5 [ 16 ] , V_139 [ 6 ] ;
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
if ( ! F_32 ( V_9 -> V_19 ) )
return V_39 ;
if ( V_11 -> V_18 < 24 + sizeof( * V_131 ) )
return V_51 ;
V_131 = (struct V_138 * )
( V_11 -> V_3 + V_11 -> V_18 - sizeof( * V_131 ) ) ;
if ( V_131 -> V_133 != V_134 ||
V_131 -> V_135 != sizeof( * V_131 ) - 2 )
return V_51 ;
F_66 ( V_139 , V_131 -> V_136 ) ;
if ( memcmp ( V_139 , V_4 -> V_54 . V_137 . V_109 , 6 ) <= 0 ) {
V_4 -> V_54 . V_137 . V_110 ++ ;
return V_51 ;
}
if ( ! ( V_38 -> V_40 & V_46 ) ) {
F_64 ( V_11 , V_82 ) ;
F_72 ( V_4 -> V_54 . V_137 . V_106 , V_82 ,
V_11 -> V_3 + 24 , V_11 -> V_18 - 24 , V_5 ) ;
if ( memcmp ( V_5 , V_131 -> V_5 , sizeof( V_131 -> V_5 ) ) != 0 ) {
V_4 -> V_54 . V_137 . V_140 ++ ;
return V_51 ;
}
}
memcpy ( V_4 -> V_54 . V_137 . V_109 , V_139 , 6 ) ;
F_14 ( V_11 , V_11 -> V_18 - sizeof( * V_131 ) ) ;
return V_39 ;
}
T_1
F_75 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_68 * V_4 = V_2 -> V_4 ;
struct V_138 * V_131 ;
struct V_8 * V_9 ;
T_2 V_82 [ 20 ] ;
T_7 V_100 ;
T_2 V_141 [ 12 ] ;
if ( F_18 ( F_68 ( & V_2 -> V_132 ) != 1 ) )
return V_21 ;
V_11 = F_69 ( & V_2 -> V_132 ) ;
V_13 = F_2 ( V_11 ) ;
if ( V_13 -> V_24 . V_25 )
return V_20 ;
if ( F_18 ( F_7 ( V_11 ) < sizeof( * V_131 ) ) )
return V_21 ;
V_131 = (struct V_138 * ) F_9 ( V_11 , sizeof( * V_131 ) ) ;
V_131 -> V_133 = V_134 ;
V_131 -> V_135 = sizeof( * V_131 ) - 2 ;
V_131 -> V_98 = F_33 ( V_4 -> V_15 . V_50 ) ;
V_100 = F_42 ( & V_4 -> V_15 . V_104 ) ;
F_65 ( V_131 -> V_136 , V_100 ) ;
F_64 ( V_11 , V_82 ) ;
V_9 = (struct V_8 * ) V_11 -> V_3 ;
memcpy ( V_141 , V_9 -> V_63 , V_93 ) ;
F_66 ( V_141 + V_93 , V_131 -> V_136 ) ;
if ( F_76 ( V_4 -> V_54 . V_142 . V_106 , V_82 , V_141 ,
V_11 -> V_3 + 24 , V_11 -> V_18 - 24 , V_131 -> V_5 ) < 0 )
return V_21 ;
return V_20 ;
}
T_4
F_77 ( struct V_35 * V_36 )
{
struct V_10 * V_11 = V_36 -> V_11 ;
struct V_37 * V_38 = F_12 ( V_11 ) ;
struct V_68 * V_4 = V_36 -> V_4 ;
struct V_138 * V_131 ;
T_2 V_82 [ 20 ] , V_5 [ 16 ] , V_139 [ 6 ] , V_141 [ 12 ] ;
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
if ( ! F_32 ( V_9 -> V_19 ) )
return V_39 ;
if ( V_11 -> V_18 < 24 + sizeof( * V_131 ) )
return V_51 ;
V_131 = (struct V_138 * )
( V_11 -> V_3 + V_11 -> V_18 - sizeof( * V_131 ) ) ;
if ( V_131 -> V_133 != V_134 ||
V_131 -> V_135 != sizeof( * V_131 ) - 2 )
return V_51 ;
F_66 ( V_139 , V_131 -> V_136 ) ;
if ( memcmp ( V_139 , V_4 -> V_54 . V_142 . V_109 , 6 ) <= 0 ) {
V_4 -> V_54 . V_142 . V_110 ++ ;
return V_51 ;
}
if ( ! ( V_38 -> V_40 & V_46 ) ) {
F_64 ( V_11 , V_82 ) ;
memcpy ( V_141 , V_9 -> V_63 , V_93 ) ;
memcpy ( V_141 + V_93 , V_139 , 6 ) ;
if ( F_76 ( V_4 -> V_54 . V_142 . V_106 , V_82 , V_141 ,
V_11 -> V_3 + 24 , V_11 -> V_18 - 24 ,
V_5 ) < 0 ||
memcmp ( V_5 , V_131 -> V_5 , sizeof( V_131 -> V_5 ) ) != 0 ) {
V_4 -> V_54 . V_142 . V_140 ++ ;
return V_51 ;
}
}
memcpy ( V_4 -> V_54 . V_142 . V_109 , V_139 , 6 ) ;
F_14 ( V_11 , V_11 -> V_18 - sizeof( * V_131 ) ) ;
return V_39 ;
}
T_1
F_78 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 = NULL ;
T_1 V_74 ;
F_26 (&tx->skbs, skb) {
V_13 = F_2 ( V_11 ) ;
if ( ! V_13 -> V_24 . V_25 )
return V_21 ;
if ( V_2 -> V_4 -> V_22 & V_143 ) {
V_74 = F_60 ( V_2 , V_11 ) ;
if ( V_74 != V_20 )
return V_74 ;
}
}
F_25 ( V_2 ) ;
return V_20 ;
}
T_4
F_79 ( struct V_35 * V_36 )
{
if ( V_36 -> V_76 && V_36 -> V_76 -> V_123 )
return F_63 ( V_36 ) ;
return V_51 ;
}
