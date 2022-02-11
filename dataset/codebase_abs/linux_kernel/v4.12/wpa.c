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
F_6 ( & V_2 -> V_27 -> V_28 , V_29 ) ) &&
! ( V_2 -> V_4 -> V_15 . V_22 & V_30 ) ) {
return V_20 ;
}
V_14 = V_31 ;
if ( ! V_13 -> V_24 . V_25 )
V_14 += V_32 ;
if ( F_7 ( F_8 ( V_11 ) < V_14 ||
F_9 ( V_11 ) < V_33 ,
L_1 ,
F_9 ( V_11 ) , V_33 ,
F_8 ( V_11 ) , V_14 ) )
return V_21 ;
V_4 = & V_2 -> V_4 -> V_15 . V_4 [ V_34 ] ;
V_5 = F_10 ( V_11 , V_31 ) ;
F_11 ( V_4 , V_9 , V_3 , V_6 , V_5 ) ;
if ( F_5 ( V_13 -> V_22 & V_23 ) )
V_5 [ 0 ] ++ ;
return V_20 ;
}
T_4
F_12 ( struct V_35 * V_36 )
{
T_2 * V_3 , * V_4 = NULL ;
T_3 V_6 ;
unsigned int V_7 ;
T_2 V_5 [ V_31 ] ;
struct V_10 * V_11 = V_36 -> V_11 ;
struct V_37 * V_38 = F_13 ( V_11 ) ;
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
if ( F_14 ( V_36 -> V_11 ) )
return V_51 ;
V_9 = ( void * ) V_11 -> V_3 ;
V_3 = V_11 -> V_3 + V_7 ;
V_6 = V_11 -> V_18 - V_7 - V_31 ;
V_4 = & V_36 -> V_4 -> V_15 . V_4 [ V_53 ] ;
F_11 ( V_4 , V_9 , V_3 , V_6 , V_5 ) ;
if ( F_15 ( V_5 , V_3 + V_6 , V_31 ) )
goto V_52;
F_16 ( V_11 , V_11 -> V_18 - V_31 ) ;
V_45:
V_36 -> V_4 -> V_54 . V_55 . V_36 [ V_36 -> V_56 ] . V_57 = V_36 -> V_58 ;
V_36 -> V_4 -> V_54 . V_55 . V_36 [ V_36 -> V_56 ] . V_59 = V_36 -> V_60 ;
return V_39 ;
V_52:
V_36 -> V_4 -> V_54 . V_55 . V_61 ++ ;
V_44:
F_17 ( V_36 -> V_47 -> V_62 , V_9 -> V_63 ,
F_18 ( V_9 -> V_64 ) ?
V_65 :
V_66 ,
V_36 -> V_4 ? V_36 -> V_4 -> V_15 . V_50 : - 1 ,
NULL , V_67 ) ;
return V_51 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
struct V_68 * V_4 = V_2 -> V_4 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
unsigned int V_7 ;
int V_18 , V_14 ;
T_5 V_69 ;
T_2 * V_70 ;
if ( V_13 -> V_24 . V_25 &&
! ( V_13 -> V_24 . V_25 -> V_22 & V_71 ) &&
! ( V_13 -> V_24 . V_25 -> V_22 & V_72 ) ) {
return 0 ;
}
V_7 = F_4 ( V_9 -> V_19 ) ;
V_18 = V_11 -> V_18 - V_7 ;
if ( V_13 -> V_24 . V_25 )
V_14 = 0 ;
else
V_14 = V_32 ;
if ( F_20 ( F_8 ( V_11 ) < V_14 ||
F_9 ( V_11 ) < V_33 ) )
return - 1 ;
V_70 = F_21 ( V_11 , V_33 ) ;
memmove ( V_70 , V_70 + V_33 , V_7 ) ;
V_70 += V_7 ;
if ( V_13 -> V_24 . V_25 &&
( V_13 -> V_24 . V_25 -> V_22 & V_72 ) )
return 0 ;
V_69 = F_22 ( & V_4 -> V_15 . V_73 ) ;
V_70 = F_23 ( V_70 , & V_4 -> V_15 , V_69 ) ;
if ( V_13 -> V_24 . V_25 )
return 0 ;
F_10 ( V_11 , V_32 ) ;
return F_24 ( V_2 -> V_27 -> V_74 ,
V_4 , V_11 , V_70 , V_18 ) ;
}
T_1
F_25 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
F_26 ( V_2 ) ;
F_27 (&tx->skbs, skb) {
if ( F_19 ( V_2 , V_11 ) < 0 )
return V_21 ;
}
return V_20 ;
}
T_4
F_28 ( struct V_35 * V_36 )
{
struct V_8 * V_9 = (struct V_8 * ) V_36 -> V_11 -> V_3 ;
int V_7 , V_75 , V_76 = 0 ;
struct V_68 * V_4 = V_36 -> V_4 ;
struct V_10 * V_11 = V_36 -> V_11 ;
struct V_37 * V_38 = F_13 ( V_11 ) ;
V_7 = F_4 ( V_9 -> V_19 ) ;
if ( ! F_29 ( V_9 -> V_19 ) )
return V_39 ;
if ( ! V_36 -> V_77 || V_11 -> V_18 - V_7 < 12 )
return V_51 ;
if ( F_14 ( V_36 -> V_11 ) )
return V_51 ;
V_9 = ( void * ) V_11 -> V_3 ;
if ( V_38 -> V_40 & V_46 )
V_76 = 1 ;
V_75 = F_30 ( V_36 -> V_27 -> V_78 ,
V_4 , V_11 -> V_3 + V_7 ,
V_11 -> V_18 - V_7 , V_36 -> V_77 -> V_77 . V_79 ,
V_9 -> V_64 , V_76 , V_36 -> V_56 ,
& V_36 -> V_58 ,
& V_36 -> V_60 ) ;
if ( V_75 != V_80 )
return V_51 ;
if ( ! ( V_38 -> V_40 & V_81 ) )
F_16 ( V_11 , V_11 -> V_18 - V_32 ) ;
memmove ( V_11 -> V_3 + V_33 , V_11 -> V_3 , V_7 ) ;
F_31 ( V_11 , V_33 ) ;
return V_39 ;
}
static void F_32 ( struct V_10 * V_11 , T_2 * V_69 , T_2 * V_82 , T_2 * V_83 )
{
T_6 V_84 ;
int V_85 , V_86 ;
T_2 V_87 ;
T_7 V_88 ;
unsigned int V_7 ;
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
V_86 = F_33 ( V_9 -> V_19 ) ;
V_84 = V_9 -> V_19 ;
V_84 &= ~ F_34 ( V_89 |
V_90 | V_91 ) ;
if ( ! V_86 )
V_84 &= ~ F_34 ( 0x0070 ) ;
V_84 |= F_34 ( V_92 ) ;
V_7 = F_4 ( V_9 -> V_19 ) ;
V_88 = V_7 - 2 ;
V_85 = F_35 ( V_9 -> V_19 ) ;
if ( F_36 ( V_9 -> V_19 ) )
V_87 = * F_37 ( V_9 ) & V_93 ;
else
V_87 = 0 ;
V_82 [ 0 ] = 0x1 ;
V_82 [ 1 ] = V_87 | ( V_86 << 4 ) ;
memcpy ( & V_82 [ 2 ] , V_9 -> V_63 , V_94 ) ;
memcpy ( & V_82 [ 8 ] , V_69 , V_95 ) ;
F_38 ( V_88 , & V_83 [ 0 ] ) ;
F_39 ( V_84 , ( T_6 * ) & V_83 [ 2 ] ) ;
memcpy ( & V_83 [ 4 ] , & V_9 -> V_64 , 3 * V_94 ) ;
V_83 [ 22 ] = * ( ( T_2 * ) & V_9 -> V_96 ) & 0x0f ;
V_83 [ 23 ] = 0 ;
if ( V_85 ) {
memcpy ( & V_83 [ 24 ] , V_9 -> V_97 , V_94 ) ;
V_83 [ 30 ] = V_87 ;
V_83 [ 31 ] = 0 ;
} else {
memset ( & V_83 [ 24 ] , 0 , V_94 + V_98 ) ;
V_83 [ 24 ] = V_87 ;
}
}
static inline void F_40 ( T_2 * V_9 , T_2 * V_69 , int V_99 )
{
V_9 [ 0 ] = V_69 [ 5 ] ;
V_9 [ 1 ] = V_69 [ 4 ] ;
V_9 [ 2 ] = 0 ;
V_9 [ 3 ] = 0x20 | ( V_99 << 6 ) ;
V_9 [ 4 ] = V_69 [ 3 ] ;
V_9 [ 5 ] = V_69 [ 2 ] ;
V_9 [ 6 ] = V_69 [ 1 ] ;
V_9 [ 7 ] = V_69 [ 0 ] ;
}
static inline void F_41 ( T_2 * V_69 , T_2 * V_9 )
{
V_69 [ 0 ] = V_9 [ 7 ] ;
V_69 [ 1 ] = V_9 [ 6 ] ;
V_69 [ 2 ] = V_9 [ 5 ] ;
V_69 [ 3 ] = V_9 [ 4 ] ;
V_69 [ 4 ] = V_9 [ 1 ] ;
V_69 [ 5 ] = V_9 [ 0 ] ;
}
static int F_42 ( struct V_1 * V_2 , struct V_10 * V_11 ,
unsigned int V_100 )
{
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
struct V_68 * V_4 = V_2 -> V_4 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
int V_7 , V_18 , V_14 ;
T_2 * V_70 ;
T_2 V_69 [ 6 ] ;
T_5 V_101 ;
T_2 V_83 [ V_102 ] ;
T_2 V_82 [ V_103 ] ;
if ( V_13 -> V_24 . V_25 &&
! ( V_13 -> V_24 . V_25 -> V_22 & V_71 ) &&
! ( V_13 -> V_24 . V_25 -> V_22 & V_72 ) &&
! ( ( V_13 -> V_24 . V_25 -> V_22 &
V_104 ) &&
F_33 ( V_9 -> V_19 ) ) ) {
return 0 ;
}
V_7 = F_4 ( V_9 -> V_19 ) ;
V_18 = V_11 -> V_18 - V_7 ;
if ( V_13 -> V_24 . V_25 )
V_14 = 0 ;
else
V_14 = V_100 ;
if ( F_20 ( F_8 ( V_11 ) < V_14 ||
F_9 ( V_11 ) < V_105 ) )
return - 1 ;
V_70 = F_21 ( V_11 , V_105 ) ;
memmove ( V_70 , V_70 + V_105 , V_7 ) ;
if ( V_13 -> V_24 . V_25 &&
( V_13 -> V_24 . V_25 -> V_22 & V_72 ) )
return 0 ;
V_9 = (struct V_8 * ) V_70 ;
V_70 += V_7 ;
V_101 = F_22 ( & V_4 -> V_15 . V_73 ) ;
V_69 [ 5 ] = V_101 ;
V_69 [ 4 ] = V_101 >> 8 ;
V_69 [ 3 ] = V_101 >> 16 ;
V_69 [ 2 ] = V_101 >> 24 ;
V_69 [ 1 ] = V_101 >> 32 ;
V_69 [ 0 ] = V_101 >> 40 ;
F_40 ( V_70 , V_69 , V_4 -> V_15 . V_50 ) ;
if ( V_13 -> V_24 . V_25 )
return 0 ;
V_70 += V_105 ;
F_32 ( V_11 , V_69 , V_82 , V_83 ) ;
return F_43 ( V_4 -> V_54 . V_106 . V_107 , V_82 , V_83 , V_70 , V_18 ,
F_10 ( V_11 , V_100 ) , V_100 ) ;
}
T_1
F_44 ( struct V_1 * V_2 ,
unsigned int V_100 )
{
struct V_10 * V_11 ;
F_26 ( V_2 ) ;
F_27 (&tx->skbs, skb) {
if ( F_42 ( V_2 , V_11 , V_100 ) < 0 )
return V_21 ;
}
return V_20 ;
}
T_4
F_45 ( struct V_35 * V_36 ,
unsigned int V_100 )
{
struct V_8 * V_9 = (struct V_8 * ) V_36 -> V_11 -> V_3 ;
int V_7 ;
struct V_68 * V_4 = V_36 -> V_4 ;
struct V_10 * V_11 = V_36 -> V_11 ;
struct V_37 * V_38 = F_13 ( V_11 ) ;
T_2 V_69 [ V_95 ] ;
int V_6 ;
int V_108 ;
V_7 = F_4 ( V_9 -> V_19 ) ;
if ( ! F_29 ( V_9 -> V_19 ) &&
! F_46 ( V_11 ) )
return V_39 ;
if ( V_38 -> V_40 & V_46 ) {
if ( ! F_47 ( V_36 -> V_11 , V_7 + V_105 ) )
return V_51 ;
if ( V_38 -> V_40 & V_109 )
V_100 = 0 ;
} else {
if ( F_14 ( V_36 -> V_11 ) )
return V_51 ;
}
V_6 = V_11 -> V_18 - V_7 - V_105 - V_100 ;
if ( ! V_36 -> V_77 || V_6 < 0 )
return V_51 ;
if ( ! ( V_38 -> V_40 & V_110 ) ) {
int V_75 ;
F_41 ( V_69 , V_11 -> V_3 + V_7 ) ;
V_108 = V_36 -> V_56 ;
V_75 = memcmp ( V_69 , V_4 -> V_54 . V_106 . V_111 [ V_108 ] ,
V_95 ) ;
if ( V_75 < 0 ||
( ! V_75 && ! ( V_38 -> V_40 & V_112 ) ) ) {
V_4 -> V_54 . V_106 . V_113 ++ ;
return V_51 ;
}
if ( ! ( V_38 -> V_40 & V_46 ) ) {
T_2 V_83 [ 2 * V_103 ] ;
T_2 V_82 [ V_103 ] ;
F_32 ( V_11 , V_69 , V_82 , V_83 ) ;
if ( F_48 (
V_4 -> V_54 . V_106 . V_107 , V_82 , V_83 ,
V_11 -> V_3 + V_7 + V_105 ,
V_6 ,
V_11 -> V_3 + V_11 -> V_18 - V_100 , V_100 ) )
return V_51 ;
}
memcpy ( V_4 -> V_54 . V_106 . V_111 [ V_108 ] , V_69 , V_95 ) ;
}
if ( F_49 ( V_11 , V_11 -> V_18 - V_100 ) )
return V_51 ;
memmove ( V_11 -> V_3 + V_105 , V_11 -> V_3 , V_7 ) ;
F_31 ( V_11 , V_105 ) ;
return V_39 ;
}
static void F_50 ( struct V_10 * V_11 , T_2 * V_69 , T_2 * V_114 , T_2 * V_83 )
{
T_6 V_84 ;
T_2 V_87 ;
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
memcpy ( V_114 , V_9 -> V_63 , V_94 ) ;
memcpy ( & V_114 [ V_94 ] , V_69 , V_115 ) ;
V_114 [ 13 ] = 0 ;
V_114 [ 14 ] = 0 ;
V_114 [ V_103 - 1 ] = 0x01 ;
F_38 ( F_4 ( V_9 -> V_19 ) - 2 , & V_83 [ 0 ] ) ;
V_84 = V_9 -> V_19 ;
V_84 &= ~ F_34 ( V_89 |
V_90 | V_91 ) ;
if ( ! F_33 ( V_9 -> V_19 ) )
V_84 &= ~ F_34 ( 0x0070 ) ;
V_84 |= F_34 ( V_92 ) ;
F_39 ( V_84 , ( T_6 * ) & V_83 [ 2 ] ) ;
memcpy ( & V_83 [ 4 ] , & V_9 -> V_64 , 3 * V_94 ) ;
V_83 [ 22 ] = * ( ( T_2 * ) & V_9 -> V_96 ) & 0x0f ;
V_83 [ 23 ] = 0 ;
if ( F_36 ( V_9 -> V_19 ) )
V_87 = * F_37 ( V_9 ) &
V_93 ;
else
V_87 = 0 ;
if ( F_35 ( V_9 -> V_19 ) ) {
memcpy ( & V_83 [ 24 ] , V_9 -> V_97 , V_94 ) ;
V_83 [ 30 ] = V_87 ;
V_83 [ 31 ] = 0 ;
} else {
memset ( & V_83 [ 24 ] , 0 , V_94 + V_98 ) ;
V_83 [ 24 ] = V_87 ;
}
}
static inline void F_51 ( T_2 * V_9 , const T_2 * V_69 , int V_99 )
{
V_9 [ 0 ] = V_69 [ 5 ] ;
V_9 [ 1 ] = V_69 [ 4 ] ;
V_9 [ 2 ] = 0 ;
V_9 [ 3 ] = 0x20 | ( V_99 << 6 ) ;
V_9 [ 4 ] = V_69 [ 3 ] ;
V_9 [ 5 ] = V_69 [ 2 ] ;
V_9 [ 6 ] = V_69 [ 1 ] ;
V_9 [ 7 ] = V_69 [ 0 ] ;
}
static inline void F_52 ( T_2 * V_69 , const T_2 * V_9 )
{
V_69 [ 0 ] = V_9 [ 7 ] ;
V_69 [ 1 ] = V_9 [ 6 ] ;
V_69 [ 2 ] = V_9 [ 5 ] ;
V_69 [ 3 ] = V_9 [ 4 ] ;
V_69 [ 4 ] = V_9 [ 1 ] ;
V_69 [ 5 ] = V_9 [ 0 ] ;
}
static int F_53 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
struct V_68 * V_4 = V_2 -> V_4 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
int V_7 , V_18 , V_14 ;
T_2 * V_70 ;
T_2 V_69 [ 6 ] ;
T_5 V_101 ;
T_2 V_83 [ V_116 ] ;
T_2 V_114 [ V_103 ] ;
if ( V_13 -> V_24 . V_25 &&
! ( V_13 -> V_24 . V_25 -> V_22 & V_71 ) &&
! ( V_13 -> V_24 . V_25 -> V_22 & V_72 ) &&
! ( ( V_13 -> V_24 . V_25 -> V_22 &
V_104 ) &&
F_33 ( V_9 -> V_19 ) ) ) {
return 0 ;
}
V_7 = F_4 ( V_9 -> V_19 ) ;
V_18 = V_11 -> V_18 - V_7 ;
if ( V_13 -> V_24 . V_25 )
V_14 = 0 ;
else
V_14 = V_117 ;
if ( F_20 ( F_8 ( V_11 ) < V_14 ||
F_9 ( V_11 ) < V_118 ) )
return - 1 ;
V_70 = F_21 ( V_11 , V_118 ) ;
memmove ( V_70 , V_70 + V_118 , V_7 ) ;
F_54 ( V_11 , F_55 ( V_11 ) +
V_118 ) ;
if ( V_13 -> V_24 . V_25 &&
( V_13 -> V_24 . V_25 -> V_22 & V_72 ) )
return 0 ;
V_9 = (struct V_8 * ) V_70 ;
V_70 += V_7 ;
V_101 = F_22 ( & V_4 -> V_15 . V_73 ) ;
V_69 [ 5 ] = V_101 ;
V_69 [ 4 ] = V_101 >> 8 ;
V_69 [ 3 ] = V_101 >> 16 ;
V_69 [ 2 ] = V_101 >> 24 ;
V_69 [ 1 ] = V_101 >> 32 ;
V_69 [ 0 ] = V_101 >> 40 ;
F_51 ( V_70 , V_69 , V_4 -> V_15 . V_50 ) ;
if ( V_13 -> V_24 . V_25 )
return 0 ;
V_70 += V_118 ;
F_50 ( V_11 , V_69 , V_114 , V_83 ) ;
return F_56 ( V_4 -> V_54 . V_119 . V_107 , V_114 , V_83 , V_70 , V_18 ,
F_10 ( V_11 , V_117 ) ) ;
}
T_1
F_57 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
F_26 ( V_2 ) ;
F_27 (&tx->skbs, skb) {
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
struct V_37 * V_38 = F_13 ( V_11 ) ;
T_2 V_69 [ V_115 ] ;
int V_6 , V_108 , V_100 = V_117 ;
V_7 = F_4 ( V_9 -> V_19 ) ;
if ( ! F_29 ( V_9 -> V_19 ) &&
! F_46 ( V_11 ) )
return V_39 ;
if ( V_38 -> V_40 & V_46 ) {
if ( ! F_47 ( V_36 -> V_11 , V_7 + V_118 ) )
return V_51 ;
if ( V_38 -> V_40 & V_109 )
V_100 = 0 ;
} else {
if ( F_14 ( V_36 -> V_11 ) )
return V_51 ;
}
V_6 = V_11 -> V_18 - V_7 - V_118 - V_100 ;
if ( ! V_36 -> V_77 || V_6 < 0 )
return V_51 ;
if ( ! ( V_38 -> V_40 & V_110 ) ) {
int V_75 ;
F_52 ( V_69 , V_11 -> V_3 + V_7 ) ;
V_108 = V_36 -> V_56 ;
V_75 = memcmp ( V_69 , V_4 -> V_54 . V_119 . V_111 [ V_108 ] ,
V_115 ) ;
if ( V_75 < 0 ||
( ! V_75 && ! ( V_38 -> V_40 & V_112 ) ) ) {
V_4 -> V_54 . V_119 . V_113 ++ ;
return V_51 ;
}
if ( ! ( V_38 -> V_40 & V_46 ) ) {
T_2 V_83 [ 2 * V_103 ] ;
T_2 V_114 [ V_103 ] ;
F_50 ( V_11 , V_69 , V_114 , V_83 ) ;
if ( F_59 (
V_4 -> V_54 . V_119 . V_107 , V_114 , V_83 ,
V_11 -> V_3 + V_7 + V_118 ,
V_6 ,
V_11 -> V_3 + V_11 -> V_18 -
V_117 ) )
return V_51 ;
}
memcpy ( V_4 -> V_54 . V_119 . V_111 [ V_108 ] , V_69 , V_115 ) ;
}
if ( F_49 ( V_11 , V_11 -> V_18 - V_100 ) )
return V_51 ;
memmove ( V_11 -> V_3 + V_118 , V_11 -> V_3 , V_7 ) ;
F_31 ( V_11 , V_118 ) ;
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
T_2 * V_70 , V_120 = V_4 -> V_15 . V_120 ;
if ( V_13 -> V_24 . V_25 &&
! ( V_13 -> V_24 . V_25 -> V_22 & V_72 ) ) {
return V_20 ;
}
if ( F_5 ( F_9 ( V_11 ) < V_120 &&
F_61 ( V_11 , V_120 , 0 , V_67 ) ) )
return V_21 ;
V_7 = F_4 ( V_9 -> V_19 ) ;
V_70 = F_21 ( V_11 , V_120 ) ;
memmove ( V_70 , V_70 + V_120 , V_7 ) ;
return V_20 ;
}
static inline int F_62 ( T_2 * V_121 , T_2 * V_122 , int V_18 )
{
int V_123 ;
for ( V_123 = V_18 - 1 ; V_123 >= 0 ; V_123 -- ) {
if ( V_121 [ V_123 ] < V_122 [ V_123 ] )
return - 1 ;
else if ( V_121 [ V_123 ] > V_122 [ V_123 ] )
return 1 ;
}
return 0 ;
}
static T_4
F_63 ( struct V_35 * V_36 )
{
struct V_68 * V_4 = V_36 -> V_4 ;
struct V_8 * V_9 = (struct V_8 * ) V_36 -> V_11 -> V_3 ;
const struct V_124 * V_125 = NULL ;
int V_7 = F_4 ( V_9 -> V_19 ) ;
struct V_37 * V_38 = F_13 ( V_36 -> V_11 ) ;
int V_6 ;
T_2 * V_111 ;
T_2 * V_126 ;
T_2 V_87 ;
if ( ! V_36 -> V_77 || ! V_36 -> V_77 -> V_127 ||
! ( V_38 -> V_40 & V_46 ) )
return V_51 ;
if ( ! F_29 ( V_9 -> V_19 ) )
return V_39 ;
V_125 = V_36 -> V_77 -> V_127 ;
V_6 = V_36 -> V_11 -> V_18 - V_7 - V_125 -> V_128 ;
if ( V_6 < 0 )
return V_51 ;
if ( F_36 ( V_9 -> V_19 ) )
V_87 = * F_37 ( V_9 ) &
V_93 ;
else
V_87 = 0 ;
if ( F_14 ( V_36 -> V_11 ) )
return V_51 ;
V_9 = (struct V_8 * ) V_36 -> V_11 -> V_3 ;
V_111 = V_4 -> V_54 . V_129 . V_111 [ V_87 ] ;
V_126 = V_36 -> V_11 -> V_3 + V_7 + V_125 -> V_130 ;
if ( F_62 ( V_126 , V_111 , V_125 -> V_131 ) <= 0 )
return V_51 ;
memcpy ( V_111 , V_126 , V_125 -> V_131 ) ;
if ( F_49 ( V_36 -> V_11 , V_36 -> V_11 -> V_18 - V_125 -> V_100 ) )
return V_51 ;
memmove ( V_36 -> V_11 -> V_3 + V_125 -> V_128 , V_36 -> V_11 -> V_3 , V_7 ) ;
F_31 ( V_36 -> V_11 , V_125 -> V_128 ) ;
return V_39 ;
}
static void F_64 ( struct V_10 * V_11 , T_2 * V_83 )
{
T_6 V_84 ;
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
V_84 = V_9 -> V_19 ;
V_84 &= ~ F_34 ( V_89 | V_90 |
V_91 ) ;
F_39 ( V_84 , ( T_6 * ) & V_83 [ 0 ] ) ;
memcpy ( V_83 + 2 , & V_9 -> V_64 , 3 * V_94 ) ;
}
static inline void F_65 ( T_2 * V_132 , T_5 V_69 )
{
* V_132 ++ = V_69 ;
* V_132 ++ = V_69 >> 8 ;
* V_132 ++ = V_69 >> 16 ;
* V_132 ++ = V_69 >> 24 ;
* V_132 ++ = V_69 >> 32 ;
* V_132 = V_69 >> 40 ;
}
static inline void F_66 ( T_2 * V_132 , const T_2 * V_133 )
{
* V_132 ++ = V_133 [ 5 ] ;
* V_132 ++ = V_133 [ 4 ] ;
* V_132 ++ = V_133 [ 3 ] ;
* V_132 ++ = V_133 [ 2 ] ;
* V_132 ++ = V_133 [ 1 ] ;
* V_132 = V_133 [ 0 ] ;
}
T_1
F_67 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_68 * V_4 = V_2 -> V_4 ;
struct V_134 * V_135 ;
T_2 V_83 [ 20 ] ;
T_5 V_101 ;
if ( F_20 ( F_68 ( & V_2 -> V_136 ) != 1 ) )
return V_21 ;
V_11 = F_69 ( & V_2 -> V_136 ) ;
V_13 = F_2 ( V_11 ) ;
if ( V_13 -> V_24 . V_25 )
return V_20 ;
if ( F_20 ( F_8 ( V_11 ) < sizeof( * V_135 ) ) )
return V_21 ;
V_135 = (struct V_134 * ) F_10 ( V_11 , sizeof( * V_135 ) ) ;
V_135 -> V_137 = V_138 ;
V_135 -> V_139 = sizeof( * V_135 ) - 2 ;
V_135 -> V_99 = F_34 ( V_4 -> V_15 . V_50 ) ;
V_101 = F_22 ( & V_4 -> V_15 . V_73 ) ;
F_65 ( V_135 -> V_140 , V_101 ) ;
F_64 ( V_11 , V_83 ) ;
F_70 ( V_4 -> V_54 . V_141 . V_107 , V_83 ,
V_11 -> V_3 + 24 , V_11 -> V_18 - 24 , V_135 -> V_5 ) ;
return V_20 ;
}
T_1
F_71 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_68 * V_4 = V_2 -> V_4 ;
struct V_142 * V_135 ;
T_2 V_83 [ 20 ] ;
T_5 V_101 ;
if ( F_20 ( F_68 ( & V_2 -> V_136 ) != 1 ) )
return V_21 ;
V_11 = F_69 ( & V_2 -> V_136 ) ;
V_13 = F_2 ( V_11 ) ;
if ( V_13 -> V_24 . V_25 )
return V_20 ;
if ( F_20 ( F_8 ( V_11 ) < sizeof( * V_135 ) ) )
return V_21 ;
V_135 = (struct V_142 * ) F_10 ( V_11 , sizeof( * V_135 ) ) ;
V_135 -> V_137 = V_138 ;
V_135 -> V_139 = sizeof( * V_135 ) - 2 ;
V_135 -> V_99 = F_34 ( V_4 -> V_15 . V_50 ) ;
V_101 = F_22 ( & V_4 -> V_15 . V_73 ) ;
F_65 ( V_135 -> V_140 , V_101 ) ;
F_64 ( V_11 , V_83 ) ;
F_72 ( V_4 -> V_54 . V_141 . V_107 , V_83 ,
V_11 -> V_3 + 24 , V_11 -> V_18 - 24 , V_135 -> V_5 ) ;
return V_20 ;
}
T_4
F_73 ( struct V_35 * V_36 )
{
struct V_10 * V_11 = V_36 -> V_11 ;
struct V_37 * V_38 = F_13 ( V_11 ) ;
struct V_68 * V_4 = V_36 -> V_4 ;
struct V_134 * V_135 ;
T_2 V_83 [ 20 ] , V_5 [ 8 ] , V_143 [ 6 ] ;
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
if ( ! F_33 ( V_9 -> V_19 ) )
return V_39 ;
if ( V_11 -> V_18 < 24 + sizeof( * V_135 ) )
return V_51 ;
V_135 = (struct V_134 * )
( V_11 -> V_3 + V_11 -> V_18 - sizeof( * V_135 ) ) ;
if ( V_135 -> V_137 != V_138 ||
V_135 -> V_139 != sizeof( * V_135 ) - 2 )
return V_51 ;
F_66 ( V_143 , V_135 -> V_140 ) ;
if ( memcmp ( V_143 , V_4 -> V_54 . V_141 . V_111 , 6 ) <= 0 ) {
V_4 -> V_54 . V_141 . V_113 ++ ;
return V_51 ;
}
if ( ! ( V_38 -> V_40 & V_46 ) ) {
F_64 ( V_11 , V_83 ) ;
F_70 ( V_4 -> V_54 . V_141 . V_107 , V_83 ,
V_11 -> V_3 + 24 , V_11 -> V_18 - 24 , V_5 ) ;
if ( F_15 ( V_5 , V_135 -> V_5 , sizeof( V_135 -> V_5 ) ) ) {
V_4 -> V_54 . V_141 . V_144 ++ ;
return V_51 ;
}
}
memcpy ( V_4 -> V_54 . V_141 . V_111 , V_143 , 6 ) ;
F_16 ( V_11 , V_11 -> V_18 - sizeof( * V_135 ) ) ;
return V_39 ;
}
T_4
F_74 ( struct V_35 * V_36 )
{
struct V_10 * V_11 = V_36 -> V_11 ;
struct V_37 * V_38 = F_13 ( V_11 ) ;
struct V_68 * V_4 = V_36 -> V_4 ;
struct V_142 * V_135 ;
T_2 V_83 [ 20 ] , V_5 [ 16 ] , V_143 [ 6 ] ;
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
if ( ! F_33 ( V_9 -> V_19 ) )
return V_39 ;
if ( V_11 -> V_18 < 24 + sizeof( * V_135 ) )
return V_51 ;
V_135 = (struct V_142 * )
( V_11 -> V_3 + V_11 -> V_18 - sizeof( * V_135 ) ) ;
if ( V_135 -> V_137 != V_138 ||
V_135 -> V_139 != sizeof( * V_135 ) - 2 )
return V_51 ;
F_66 ( V_143 , V_135 -> V_140 ) ;
if ( memcmp ( V_143 , V_4 -> V_54 . V_141 . V_111 , 6 ) <= 0 ) {
V_4 -> V_54 . V_141 . V_113 ++ ;
return V_51 ;
}
if ( ! ( V_38 -> V_40 & V_46 ) ) {
F_64 ( V_11 , V_83 ) ;
F_72 ( V_4 -> V_54 . V_141 . V_107 , V_83 ,
V_11 -> V_3 + 24 , V_11 -> V_18 - 24 , V_5 ) ;
if ( F_15 ( V_5 , V_135 -> V_5 , sizeof( V_135 -> V_5 ) ) ) {
V_4 -> V_54 . V_141 . V_144 ++ ;
return V_51 ;
}
}
memcpy ( V_4 -> V_54 . V_141 . V_111 , V_143 , 6 ) ;
F_16 ( V_11 , V_11 -> V_18 - sizeof( * V_135 ) ) ;
return V_39 ;
}
T_1
F_75 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_68 * V_4 = V_2 -> V_4 ;
struct V_142 * V_135 ;
struct V_8 * V_9 ;
T_2 V_83 [ V_145 ] ;
T_5 V_101 ;
T_2 V_146 [ V_147 ] ;
if ( F_20 ( F_68 ( & V_2 -> V_136 ) != 1 ) )
return V_21 ;
V_11 = F_69 ( & V_2 -> V_136 ) ;
V_13 = F_2 ( V_11 ) ;
if ( V_13 -> V_24 . V_25 )
return V_20 ;
if ( F_20 ( F_8 ( V_11 ) < sizeof( * V_135 ) ) )
return V_21 ;
V_135 = (struct V_142 * ) F_10 ( V_11 , sizeof( * V_135 ) ) ;
V_135 -> V_137 = V_138 ;
V_135 -> V_139 = sizeof( * V_135 ) - 2 ;
V_135 -> V_99 = F_34 ( V_4 -> V_15 . V_50 ) ;
V_101 = F_22 ( & V_4 -> V_15 . V_73 ) ;
F_65 ( V_135 -> V_140 , V_101 ) ;
F_64 ( V_11 , V_83 ) ;
V_9 = (struct V_8 * ) V_11 -> V_3 ;
memcpy ( V_146 , V_9 -> V_63 , V_94 ) ;
F_66 ( V_146 + V_94 , V_135 -> V_140 ) ;
if ( F_76 ( V_4 -> V_54 . V_148 . V_107 , V_83 , V_146 ,
V_11 -> V_3 + 24 , V_11 -> V_18 - 24 , V_135 -> V_5 ) < 0 )
return V_21 ;
return V_20 ;
}
T_4
F_77 ( struct V_35 * V_36 )
{
struct V_10 * V_11 = V_36 -> V_11 ;
struct V_37 * V_38 = F_13 ( V_11 ) ;
struct V_68 * V_4 = V_36 -> V_4 ;
struct V_142 * V_135 ;
T_2 V_83 [ V_145 ] , V_5 [ V_149 ] , V_143 [ 6 ] , V_146 [ V_147 ] ;
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
if ( ! F_33 ( V_9 -> V_19 ) )
return V_39 ;
if ( V_11 -> V_18 < 24 + sizeof( * V_135 ) )
return V_51 ;
V_135 = (struct V_142 * )
( V_11 -> V_3 + V_11 -> V_18 - sizeof( * V_135 ) ) ;
if ( V_135 -> V_137 != V_138 ||
V_135 -> V_139 != sizeof( * V_135 ) - 2 )
return V_51 ;
F_66 ( V_143 , V_135 -> V_140 ) ;
if ( memcmp ( V_143 , V_4 -> V_54 . V_148 . V_111 , 6 ) <= 0 ) {
V_4 -> V_54 . V_148 . V_113 ++ ;
return V_51 ;
}
if ( ! ( V_38 -> V_40 & V_46 ) ) {
F_64 ( V_11 , V_83 ) ;
memcpy ( V_146 , V_9 -> V_63 , V_94 ) ;
memcpy ( V_146 + V_94 , V_143 , 6 ) ;
if ( F_76 ( V_4 -> V_54 . V_148 . V_107 , V_83 , V_146 ,
V_11 -> V_3 + 24 , V_11 -> V_18 - 24 ,
V_5 ) < 0 ||
F_15 ( V_5 , V_135 -> V_5 , sizeof( V_135 -> V_5 ) ) ) {
V_4 -> V_54 . V_148 . V_144 ++ ;
return V_51 ;
}
}
memcpy ( V_4 -> V_54 . V_148 . V_111 , V_143 , 6 ) ;
F_16 ( V_11 , V_11 -> V_18 - sizeof( * V_135 ) ) ;
return V_39 ;
}
T_1
F_78 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 = NULL ;
T_1 V_75 ;
F_27 (&tx->skbs, skb) {
V_13 = F_2 ( V_11 ) ;
if ( ! V_13 -> V_24 . V_25 )
return V_21 ;
if ( V_2 -> V_4 -> V_22 & V_150 ) {
V_75 = F_60 ( V_2 , V_11 ) ;
if ( V_75 != V_20 )
return V_75 ;
}
}
F_26 ( V_2 ) ;
return V_20 ;
}
T_4
F_79 ( struct V_35 * V_36 )
{
if ( V_36 -> V_77 && V_36 -> V_77 -> V_127 )
return F_63 ( V_36 ) ;
return V_51 ;
}
