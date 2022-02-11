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
if ( memcmp ( V_5 , V_3 + V_6 , V_31 ) != 0 )
goto V_52;
F_15 ( V_11 , V_11 -> V_18 - V_31 ) ;
V_45:
V_36 -> V_4 -> V_54 . V_55 . V_36 [ V_36 -> V_56 ] . V_57 = V_36 -> V_58 ;
V_36 -> V_4 -> V_54 . V_55 . V_36 [ V_36 -> V_56 ] . V_59 = V_36 -> V_60 ;
return V_39 ;
V_52:
V_36 -> V_4 -> V_54 . V_55 . V_61 ++ ;
V_44:
F_16 ( V_36 -> V_47 -> V_62 , V_9 -> V_63 ,
F_17 ( V_9 -> V_64 ) ?
V_65 :
V_66 ,
V_36 -> V_4 ? V_36 -> V_4 -> V_15 . V_50 : - 1 ,
NULL , V_67 ) ;
return V_51 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_10 * V_11 )
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
if ( F_19 ( F_8 ( V_11 ) < V_14 ||
F_9 ( V_11 ) < V_33 ) )
return - 1 ;
V_70 = F_20 ( V_11 , V_33 ) ;
memmove ( V_70 , V_70 + V_33 , V_7 ) ;
V_70 += V_7 ;
if ( V_13 -> V_24 . V_25 &&
( V_13 -> V_24 . V_25 -> V_22 & V_72 ) )
return 0 ;
V_69 = F_21 ( & V_4 -> V_15 . V_73 ) ;
V_70 = F_22 ( V_70 , & V_4 -> V_15 , V_69 ) ;
if ( V_13 -> V_24 . V_25 )
return 0 ;
F_10 ( V_11 , V_32 ) ;
return F_23 ( V_2 -> V_27 -> V_74 ,
V_4 , V_11 , V_70 , V_18 ) ;
}
T_1
F_24 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
F_25 ( V_2 ) ;
F_26 (&tx->skbs, skb) {
if ( F_18 ( V_2 , V_11 ) < 0 )
return V_21 ;
}
return V_20 ;
}
T_4
F_27 ( struct V_35 * V_36 )
{
struct V_8 * V_9 = (struct V_8 * ) V_36 -> V_11 -> V_3 ;
int V_7 , V_75 , V_76 = 0 ;
struct V_68 * V_4 = V_36 -> V_4 ;
struct V_10 * V_11 = V_36 -> V_11 ;
struct V_37 * V_38 = F_13 ( V_11 ) ;
V_7 = F_4 ( V_9 -> V_19 ) ;
if ( ! F_28 ( V_9 -> V_19 ) )
return V_39 ;
if ( ! V_36 -> V_77 || V_11 -> V_18 - V_7 < 12 )
return V_51 ;
if ( F_14 ( V_36 -> V_11 ) )
return V_51 ;
V_9 = ( void * ) V_11 -> V_3 ;
if ( V_38 -> V_40 & V_46 )
V_76 = 1 ;
V_75 = F_29 ( V_36 -> V_27 -> V_78 ,
V_4 , V_11 -> V_3 + V_7 ,
V_11 -> V_18 - V_7 , V_36 -> V_77 -> V_77 . V_79 ,
V_9 -> V_64 , V_76 , V_36 -> V_56 ,
& V_36 -> V_58 ,
& V_36 -> V_60 ) ;
if ( V_75 != V_80 )
return V_51 ;
F_15 ( V_11 , V_11 -> V_18 - V_32 ) ;
memmove ( V_11 -> V_3 + V_33 , V_11 -> V_3 , V_7 ) ;
F_30 ( V_11 , V_33 ) ;
return V_39 ;
}
static void F_31 ( struct V_10 * V_11 , T_2 * V_69 , T_2 * V_81 , T_2 * V_82 )
{
T_6 V_83 ;
int V_84 , V_85 ;
T_2 V_86 ;
T_7 V_87 ;
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
memcpy ( & V_81 [ 8 ] , V_69 , V_94 ) ;
F_37 ( V_87 , & V_82 [ 0 ] ) ;
F_38 ( V_83 , ( T_6 * ) & V_82 [ 2 ] ) ;
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
static inline void F_39 ( T_2 * V_9 , T_2 * V_69 , int V_98 )
{
V_9 [ 0 ] = V_69 [ 5 ] ;
V_9 [ 1 ] = V_69 [ 4 ] ;
V_9 [ 2 ] = 0 ;
V_9 [ 3 ] = 0x20 | ( V_98 << 6 ) ;
V_9 [ 4 ] = V_69 [ 3 ] ;
V_9 [ 5 ] = V_69 [ 2 ] ;
V_9 [ 6 ] = V_69 [ 1 ] ;
V_9 [ 7 ] = V_69 [ 0 ] ;
}
static inline void F_40 ( T_2 * V_69 , T_2 * V_9 )
{
V_69 [ 0 ] = V_9 [ 7 ] ;
V_69 [ 1 ] = V_9 [ 6 ] ;
V_69 [ 2 ] = V_9 [ 5 ] ;
V_69 [ 3 ] = V_9 [ 4 ] ;
V_69 [ 4 ] = V_9 [ 1 ] ;
V_69 [ 5 ] = V_9 [ 0 ] ;
}
static int F_41 ( struct V_1 * V_2 , struct V_10 * V_11 ,
unsigned int V_99 )
{
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
struct V_68 * V_4 = V_2 -> V_4 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
int V_7 , V_18 , V_14 ;
T_2 * V_70 ;
T_2 V_69 [ 6 ] ;
T_5 V_100 ;
T_2 V_82 [ V_101 ] ;
T_2 V_81 [ V_102 ] ;
if ( V_13 -> V_24 . V_25 &&
! ( V_13 -> V_24 . V_25 -> V_22 & V_71 ) &&
! ( V_13 -> V_24 . V_25 -> V_22 & V_72 ) &&
! ( ( V_13 -> V_24 . V_25 -> V_22 &
V_103 ) &&
F_32 ( V_9 -> V_19 ) ) ) {
return 0 ;
}
V_7 = F_4 ( V_9 -> V_19 ) ;
V_18 = V_11 -> V_18 - V_7 ;
if ( V_13 -> V_24 . V_25 )
V_14 = 0 ;
else
V_14 = V_99 ;
if ( F_19 ( F_8 ( V_11 ) < V_14 ||
F_9 ( V_11 ) < V_104 ) )
return - 1 ;
V_70 = F_20 ( V_11 , V_104 ) ;
memmove ( V_70 , V_70 + V_104 , V_7 ) ;
if ( V_13 -> V_24 . V_25 &&
( V_13 -> V_24 . V_25 -> V_22 & V_72 ) )
return 0 ;
V_9 = (struct V_8 * ) V_70 ;
V_70 += V_7 ;
V_100 = F_21 ( & V_4 -> V_15 . V_73 ) ;
V_69 [ 5 ] = V_100 ;
V_69 [ 4 ] = V_100 >> 8 ;
V_69 [ 3 ] = V_100 >> 16 ;
V_69 [ 2 ] = V_100 >> 24 ;
V_69 [ 1 ] = V_100 >> 32 ;
V_69 [ 0 ] = V_100 >> 40 ;
F_39 ( V_70 , V_69 , V_4 -> V_15 . V_50 ) ;
if ( V_13 -> V_24 . V_25 )
return 0 ;
V_70 += V_104 ;
F_31 ( V_11 , V_69 , V_81 , V_82 ) ;
return F_42 ( V_4 -> V_54 . V_105 . V_106 , V_81 , V_82 , V_70 , V_18 ,
F_10 ( V_11 , V_99 ) , V_99 ) ;
}
T_1
F_43 ( struct V_1 * V_2 ,
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
F_44 ( struct V_35 * V_36 ,
unsigned int V_99 )
{
struct V_8 * V_9 = (struct V_8 * ) V_36 -> V_11 -> V_3 ;
int V_7 ;
struct V_68 * V_4 = V_36 -> V_4 ;
struct V_10 * V_11 = V_36 -> V_11 ;
struct V_37 * V_38 = F_13 ( V_11 ) ;
T_2 V_69 [ V_94 ] ;
int V_6 ;
int V_107 ;
V_7 = F_4 ( V_9 -> V_19 ) ;
if ( ! F_28 ( V_9 -> V_19 ) &&
! F_45 ( V_11 ) )
return V_39 ;
if ( V_38 -> V_40 & V_46 ) {
if ( ! F_46 ( V_36 -> V_11 , V_7 + V_104 ) )
return V_51 ;
if ( V_38 -> V_40 & V_108 )
V_99 = 0 ;
} else {
if ( F_14 ( V_36 -> V_11 ) )
return V_51 ;
}
V_6 = V_11 -> V_18 - V_7 - V_104 - V_99 ;
if ( ! V_36 -> V_77 || V_6 < 0 )
return V_51 ;
if ( ! ( V_38 -> V_40 & V_109 ) ) {
int V_75 ;
F_40 ( V_69 , V_11 -> V_3 + V_7 ) ;
V_107 = V_36 -> V_56 ;
V_75 = memcmp ( V_69 , V_4 -> V_54 . V_105 . V_110 [ V_107 ] ,
V_94 ) ;
if ( V_75 < 0 ||
( ! V_75 && ! ( V_38 -> V_40 & V_111 ) ) ) {
V_4 -> V_54 . V_105 . V_112 ++ ;
return V_51 ;
}
if ( ! ( V_38 -> V_40 & V_46 ) ) {
T_2 V_82 [ 2 * V_102 ] ;
T_2 V_81 [ V_102 ] ;
F_31 ( V_11 , V_69 , V_81 , V_82 ) ;
if ( F_47 (
V_4 -> V_54 . V_105 . V_106 , V_81 , V_82 ,
V_11 -> V_3 + V_7 + V_104 ,
V_6 ,
V_11 -> V_3 + V_11 -> V_18 - V_99 , V_99 ) )
return V_51 ;
}
memcpy ( V_4 -> V_54 . V_105 . V_110 [ V_107 ] , V_69 , V_94 ) ;
}
if ( F_48 ( V_11 , V_11 -> V_18 - V_99 ) )
return V_51 ;
memmove ( V_11 -> V_3 + V_104 , V_11 -> V_3 , V_7 ) ;
F_30 ( V_11 , V_104 ) ;
return V_39 ;
}
static void F_49 ( struct V_10 * V_11 , T_2 * V_69 , T_2 * V_113 , T_2 * V_82 )
{
T_6 V_83 ;
T_2 V_86 ;
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
memcpy ( V_113 , V_9 -> V_63 , V_93 ) ;
memcpy ( & V_113 [ V_93 ] , V_69 , V_114 ) ;
V_113 [ 13 ] = 0 ;
V_113 [ 14 ] = 0 ;
V_113 [ V_102 - 1 ] = 0x01 ;
F_37 ( F_4 ( V_9 -> V_19 ) - 2 , & V_82 [ 0 ] ) ;
V_83 = V_9 -> V_19 ;
V_83 &= ~ F_33 ( V_88 |
V_89 | V_90 ) ;
if ( ! F_32 ( V_9 -> V_19 ) )
V_83 &= ~ F_33 ( 0x0070 ) ;
V_83 |= F_33 ( V_91 ) ;
F_38 ( V_83 , ( T_6 * ) & V_82 [ 2 ] ) ;
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
static inline void F_50 ( T_2 * V_9 , const T_2 * V_69 , int V_98 )
{
V_9 [ 0 ] = V_69 [ 5 ] ;
V_9 [ 1 ] = V_69 [ 4 ] ;
V_9 [ 2 ] = 0 ;
V_9 [ 3 ] = 0x20 | ( V_98 << 6 ) ;
V_9 [ 4 ] = V_69 [ 3 ] ;
V_9 [ 5 ] = V_69 [ 2 ] ;
V_9 [ 6 ] = V_69 [ 1 ] ;
V_9 [ 7 ] = V_69 [ 0 ] ;
}
static inline void F_51 ( T_2 * V_69 , const T_2 * V_9 )
{
V_69 [ 0 ] = V_9 [ 7 ] ;
V_69 [ 1 ] = V_9 [ 6 ] ;
V_69 [ 2 ] = V_9 [ 5 ] ;
V_69 [ 3 ] = V_9 [ 4 ] ;
V_69 [ 4 ] = V_9 [ 1 ] ;
V_69 [ 5 ] = V_9 [ 0 ] ;
}
static int F_52 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
struct V_68 * V_4 = V_2 -> V_4 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
int V_7 , V_18 , V_14 ;
T_2 * V_70 ;
T_2 V_69 [ 6 ] ;
T_5 V_100 ;
T_2 V_82 [ V_115 ] ;
T_2 V_113 [ V_102 ] ;
if ( V_13 -> V_24 . V_25 &&
! ( V_13 -> V_24 . V_25 -> V_22 & V_71 ) &&
! ( V_13 -> V_24 . V_25 -> V_22 & V_72 ) &&
! ( ( V_13 -> V_24 . V_25 -> V_22 &
V_103 ) &&
F_32 ( V_9 -> V_19 ) ) ) {
return 0 ;
}
V_7 = F_4 ( V_9 -> V_19 ) ;
V_18 = V_11 -> V_18 - V_7 ;
if ( V_13 -> V_24 . V_25 )
V_14 = 0 ;
else
V_14 = V_116 ;
if ( F_19 ( F_8 ( V_11 ) < V_14 ||
F_9 ( V_11 ) < V_117 ) )
return - 1 ;
V_70 = F_20 ( V_11 , V_117 ) ;
memmove ( V_70 , V_70 + V_117 , V_7 ) ;
F_53 ( V_11 , F_54 ( V_11 ) +
V_117 ) ;
if ( V_13 -> V_24 . V_25 &&
( V_13 -> V_24 . V_25 -> V_22 & V_72 ) )
return 0 ;
V_9 = (struct V_8 * ) V_70 ;
V_70 += V_7 ;
V_100 = F_21 ( & V_4 -> V_15 . V_73 ) ;
V_69 [ 5 ] = V_100 ;
V_69 [ 4 ] = V_100 >> 8 ;
V_69 [ 3 ] = V_100 >> 16 ;
V_69 [ 2 ] = V_100 >> 24 ;
V_69 [ 1 ] = V_100 >> 32 ;
V_69 [ 0 ] = V_100 >> 40 ;
F_50 ( V_70 , V_69 , V_4 -> V_15 . V_50 ) ;
if ( V_13 -> V_24 . V_25 )
return 0 ;
V_70 += V_117 ;
F_49 ( V_11 , V_69 , V_113 , V_82 ) ;
return F_55 ( V_4 -> V_54 . V_118 . V_106 , V_113 , V_82 , V_70 , V_18 ,
F_10 ( V_11 , V_116 ) ) ;
}
T_1
F_56 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
F_25 ( V_2 ) ;
F_26 (&tx->skbs, skb) {
if ( F_52 ( V_2 , V_11 ) < 0 )
return V_21 ;
}
return V_20 ;
}
T_4
F_57 ( struct V_35 * V_36 )
{
struct V_8 * V_9 = (struct V_8 * ) V_36 -> V_11 -> V_3 ;
int V_7 ;
struct V_68 * V_4 = V_36 -> V_4 ;
struct V_10 * V_11 = V_36 -> V_11 ;
struct V_37 * V_38 = F_13 ( V_11 ) ;
T_2 V_69 [ V_114 ] ;
int V_6 , V_107 , V_99 = V_116 ;
V_7 = F_4 ( V_9 -> V_19 ) ;
if ( ! F_28 ( V_9 -> V_19 ) &&
! F_45 ( V_11 ) )
return V_39 ;
if ( V_38 -> V_40 & V_46 ) {
if ( ! F_46 ( V_36 -> V_11 , V_7 + V_117 ) )
return V_51 ;
if ( V_38 -> V_40 & V_108 )
V_99 = 0 ;
} else {
if ( F_14 ( V_36 -> V_11 ) )
return V_51 ;
}
V_6 = V_11 -> V_18 - V_7 - V_117 - V_99 ;
if ( ! V_36 -> V_77 || V_6 < 0 )
return V_51 ;
if ( ! ( V_38 -> V_40 & V_109 ) ) {
int V_75 ;
F_51 ( V_69 , V_11 -> V_3 + V_7 ) ;
V_107 = V_36 -> V_56 ;
V_75 = memcmp ( V_69 , V_4 -> V_54 . V_118 . V_110 [ V_107 ] ,
V_114 ) ;
if ( V_75 < 0 ||
( ! V_75 && ! ( V_38 -> V_40 & V_111 ) ) ) {
V_4 -> V_54 . V_118 . V_112 ++ ;
return V_51 ;
}
if ( ! ( V_38 -> V_40 & V_46 ) ) {
T_2 V_82 [ 2 * V_102 ] ;
T_2 V_113 [ V_102 ] ;
F_49 ( V_11 , V_69 , V_113 , V_82 ) ;
if ( F_58 (
V_4 -> V_54 . V_118 . V_106 , V_113 , V_82 ,
V_11 -> V_3 + V_7 + V_117 ,
V_6 ,
V_11 -> V_3 + V_11 -> V_18 -
V_116 ) )
return V_51 ;
}
memcpy ( V_4 -> V_54 . V_118 . V_110 [ V_107 ] , V_69 , V_114 ) ;
}
if ( F_48 ( V_11 , V_11 -> V_18 - V_99 ) )
return V_51 ;
memmove ( V_11 -> V_3 + V_117 , V_11 -> V_3 , V_7 ) ;
F_30 ( V_11 , V_117 ) ;
return V_39 ;
}
static T_1
F_59 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
struct V_68 * V_4 = V_2 -> V_4 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
int V_7 ;
T_2 * V_70 , V_119 = V_4 -> V_15 . V_119 ;
if ( V_13 -> V_24 . V_25 &&
! ( V_13 -> V_24 . V_25 -> V_22 & V_72 ) ) {
return V_20 ;
}
if ( F_5 ( F_9 ( V_11 ) < V_119 &&
F_60 ( V_11 , V_119 , 0 , V_67 ) ) )
return V_21 ;
V_7 = F_4 ( V_9 -> V_19 ) ;
V_70 = F_20 ( V_11 , V_119 ) ;
memmove ( V_70 , V_70 + V_119 , V_7 ) ;
return V_20 ;
}
static inline int F_61 ( T_2 * V_120 , T_2 * V_121 , int V_18 )
{
int V_122 ;
for ( V_122 = V_18 - 1 ; V_122 >= 0 ; V_122 -- ) {
if ( V_120 [ V_122 ] < V_121 [ V_122 ] )
return - 1 ;
else if ( V_120 [ V_122 ] > V_121 [ V_122 ] )
return 1 ;
}
return 0 ;
}
static T_4
F_62 ( struct V_35 * V_36 )
{
struct V_68 * V_4 = V_36 -> V_4 ;
struct V_8 * V_9 = (struct V_8 * ) V_36 -> V_11 -> V_3 ;
const struct V_123 * V_124 = NULL ;
int V_7 = F_4 ( V_9 -> V_19 ) ;
struct V_37 * V_38 = F_13 ( V_36 -> V_11 ) ;
int V_6 ;
T_2 * V_110 ;
T_2 * V_125 ;
T_2 V_86 ;
if ( ! V_36 -> V_77 || ! V_36 -> V_77 -> V_126 ||
! ( V_38 -> V_40 & V_46 ) )
return V_51 ;
if ( ! F_28 ( V_9 -> V_19 ) )
return V_39 ;
V_124 = V_36 -> V_77 -> V_126 ;
V_6 = V_36 -> V_11 -> V_18 - V_7 - V_124 -> V_127 ;
if ( V_6 < 0 )
return V_51 ;
if ( F_35 ( V_9 -> V_19 ) )
V_86 = * F_36 ( V_9 ) &
V_92 ;
else
V_86 = 0 ;
if ( F_14 ( V_36 -> V_11 ) )
return V_51 ;
V_9 = (struct V_8 * ) V_36 -> V_11 -> V_3 ;
V_110 = V_4 -> V_54 . V_128 . V_110 [ V_86 ] ;
V_125 = V_36 -> V_11 -> V_3 + V_7 + V_124 -> V_129 ;
if ( F_61 ( V_125 , V_110 , V_124 -> V_130 ) <= 0 )
return V_51 ;
memcpy ( V_110 , V_125 , V_124 -> V_130 ) ;
if ( F_48 ( V_36 -> V_11 , V_36 -> V_11 -> V_18 - V_124 -> V_99 ) )
return V_51 ;
memmove ( V_36 -> V_11 -> V_3 + V_124 -> V_127 , V_36 -> V_11 -> V_3 , V_7 ) ;
F_30 ( V_36 -> V_11 , V_124 -> V_127 ) ;
return V_39 ;
}
static void F_63 ( struct V_10 * V_11 , T_2 * V_82 )
{
T_6 V_83 ;
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
V_83 = V_9 -> V_19 ;
V_83 &= ~ F_33 ( V_88 | V_89 |
V_90 ) ;
F_38 ( V_83 , ( T_6 * ) & V_82 [ 0 ] ) ;
memcpy ( V_82 + 2 , & V_9 -> V_64 , 3 * V_93 ) ;
}
static inline void F_64 ( T_2 * V_131 , T_5 V_69 )
{
* V_131 ++ = V_69 ;
* V_131 ++ = V_69 >> 8 ;
* V_131 ++ = V_69 >> 16 ;
* V_131 ++ = V_69 >> 24 ;
* V_131 ++ = V_69 >> 32 ;
* V_131 = V_69 >> 40 ;
}
static inline void F_65 ( T_2 * V_131 , const T_2 * V_132 )
{
* V_131 ++ = V_132 [ 5 ] ;
* V_131 ++ = V_132 [ 4 ] ;
* V_131 ++ = V_132 [ 3 ] ;
* V_131 ++ = V_132 [ 2 ] ;
* V_131 ++ = V_132 [ 1 ] ;
* V_131 = V_132 [ 0 ] ;
}
T_1
F_66 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_68 * V_4 = V_2 -> V_4 ;
struct V_133 * V_134 ;
T_2 V_82 [ 20 ] ;
T_5 V_100 ;
if ( F_19 ( F_67 ( & V_2 -> V_135 ) != 1 ) )
return V_21 ;
V_11 = F_68 ( & V_2 -> V_135 ) ;
V_13 = F_2 ( V_11 ) ;
if ( V_13 -> V_24 . V_25 )
return V_20 ;
if ( F_19 ( F_8 ( V_11 ) < sizeof( * V_134 ) ) )
return V_21 ;
V_134 = (struct V_133 * ) F_10 ( V_11 , sizeof( * V_134 ) ) ;
V_134 -> V_136 = V_137 ;
V_134 -> V_138 = sizeof( * V_134 ) - 2 ;
V_134 -> V_98 = F_33 ( V_4 -> V_15 . V_50 ) ;
V_100 = F_21 ( & V_4 -> V_15 . V_73 ) ;
F_64 ( V_134 -> V_139 , V_100 ) ;
F_63 ( V_11 , V_82 ) ;
F_69 ( V_4 -> V_54 . V_140 . V_106 , V_82 ,
V_11 -> V_3 + 24 , V_11 -> V_18 - 24 , V_134 -> V_5 ) ;
return V_20 ;
}
T_1
F_70 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_68 * V_4 = V_2 -> V_4 ;
struct V_141 * V_134 ;
T_2 V_82 [ 20 ] ;
T_5 V_100 ;
if ( F_19 ( F_67 ( & V_2 -> V_135 ) != 1 ) )
return V_21 ;
V_11 = F_68 ( & V_2 -> V_135 ) ;
V_13 = F_2 ( V_11 ) ;
if ( V_13 -> V_24 . V_25 )
return V_20 ;
if ( F_19 ( F_8 ( V_11 ) < sizeof( * V_134 ) ) )
return V_21 ;
V_134 = (struct V_141 * ) F_10 ( V_11 , sizeof( * V_134 ) ) ;
V_134 -> V_136 = V_137 ;
V_134 -> V_138 = sizeof( * V_134 ) - 2 ;
V_134 -> V_98 = F_33 ( V_4 -> V_15 . V_50 ) ;
V_100 = F_21 ( & V_4 -> V_15 . V_73 ) ;
F_64 ( V_134 -> V_139 , V_100 ) ;
F_63 ( V_11 , V_82 ) ;
F_71 ( V_4 -> V_54 . V_140 . V_106 , V_82 ,
V_11 -> V_3 + 24 , V_11 -> V_18 - 24 , V_134 -> V_5 ) ;
return V_20 ;
}
T_4
F_72 ( struct V_35 * V_36 )
{
struct V_10 * V_11 = V_36 -> V_11 ;
struct V_37 * V_38 = F_13 ( V_11 ) ;
struct V_68 * V_4 = V_36 -> V_4 ;
struct V_133 * V_134 ;
T_2 V_82 [ 20 ] , V_5 [ 8 ] , V_142 [ 6 ] ;
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
if ( ! F_32 ( V_9 -> V_19 ) )
return V_39 ;
if ( V_11 -> V_18 < 24 + sizeof( * V_134 ) )
return V_51 ;
V_134 = (struct V_133 * )
( V_11 -> V_3 + V_11 -> V_18 - sizeof( * V_134 ) ) ;
if ( V_134 -> V_136 != V_137 ||
V_134 -> V_138 != sizeof( * V_134 ) - 2 )
return V_51 ;
F_65 ( V_142 , V_134 -> V_139 ) ;
if ( memcmp ( V_142 , V_4 -> V_54 . V_140 . V_110 , 6 ) <= 0 ) {
V_4 -> V_54 . V_140 . V_112 ++ ;
return V_51 ;
}
if ( ! ( V_38 -> V_40 & V_46 ) ) {
F_63 ( V_11 , V_82 ) ;
F_69 ( V_4 -> V_54 . V_140 . V_106 , V_82 ,
V_11 -> V_3 + 24 , V_11 -> V_18 - 24 , V_5 ) ;
if ( memcmp ( V_5 , V_134 -> V_5 , sizeof( V_134 -> V_5 ) ) != 0 ) {
V_4 -> V_54 . V_140 . V_143 ++ ;
return V_51 ;
}
}
memcpy ( V_4 -> V_54 . V_140 . V_110 , V_142 , 6 ) ;
F_15 ( V_11 , V_11 -> V_18 - sizeof( * V_134 ) ) ;
return V_39 ;
}
T_4
F_73 ( struct V_35 * V_36 )
{
struct V_10 * V_11 = V_36 -> V_11 ;
struct V_37 * V_38 = F_13 ( V_11 ) ;
struct V_68 * V_4 = V_36 -> V_4 ;
struct V_141 * V_134 ;
T_2 V_82 [ 20 ] , V_5 [ 16 ] , V_142 [ 6 ] ;
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
if ( ! F_32 ( V_9 -> V_19 ) )
return V_39 ;
if ( V_11 -> V_18 < 24 + sizeof( * V_134 ) )
return V_51 ;
V_134 = (struct V_141 * )
( V_11 -> V_3 + V_11 -> V_18 - sizeof( * V_134 ) ) ;
if ( V_134 -> V_136 != V_137 ||
V_134 -> V_138 != sizeof( * V_134 ) - 2 )
return V_51 ;
F_65 ( V_142 , V_134 -> V_139 ) ;
if ( memcmp ( V_142 , V_4 -> V_54 . V_140 . V_110 , 6 ) <= 0 ) {
V_4 -> V_54 . V_140 . V_112 ++ ;
return V_51 ;
}
if ( ! ( V_38 -> V_40 & V_46 ) ) {
F_63 ( V_11 , V_82 ) ;
F_71 ( V_4 -> V_54 . V_140 . V_106 , V_82 ,
V_11 -> V_3 + 24 , V_11 -> V_18 - 24 , V_5 ) ;
if ( memcmp ( V_5 , V_134 -> V_5 , sizeof( V_134 -> V_5 ) ) != 0 ) {
V_4 -> V_54 . V_140 . V_143 ++ ;
return V_51 ;
}
}
memcpy ( V_4 -> V_54 . V_140 . V_110 , V_142 , 6 ) ;
F_15 ( V_11 , V_11 -> V_18 - sizeof( * V_134 ) ) ;
return V_39 ;
}
T_1
F_74 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_68 * V_4 = V_2 -> V_4 ;
struct V_141 * V_134 ;
struct V_8 * V_9 ;
T_2 V_82 [ V_144 ] ;
T_5 V_100 ;
T_2 V_145 [ V_146 ] ;
if ( F_19 ( F_67 ( & V_2 -> V_135 ) != 1 ) )
return V_21 ;
V_11 = F_68 ( & V_2 -> V_135 ) ;
V_13 = F_2 ( V_11 ) ;
if ( V_13 -> V_24 . V_25 )
return V_20 ;
if ( F_19 ( F_8 ( V_11 ) < sizeof( * V_134 ) ) )
return V_21 ;
V_134 = (struct V_141 * ) F_10 ( V_11 , sizeof( * V_134 ) ) ;
V_134 -> V_136 = V_137 ;
V_134 -> V_138 = sizeof( * V_134 ) - 2 ;
V_134 -> V_98 = F_33 ( V_4 -> V_15 . V_50 ) ;
V_100 = F_21 ( & V_4 -> V_15 . V_73 ) ;
F_64 ( V_134 -> V_139 , V_100 ) ;
F_63 ( V_11 , V_82 ) ;
V_9 = (struct V_8 * ) V_11 -> V_3 ;
memcpy ( V_145 , V_9 -> V_63 , V_93 ) ;
F_65 ( V_145 + V_93 , V_134 -> V_139 ) ;
if ( F_75 ( V_4 -> V_54 . V_147 . V_106 , V_82 , V_145 ,
V_11 -> V_3 + 24 , V_11 -> V_18 - 24 , V_134 -> V_5 ) < 0 )
return V_21 ;
return V_20 ;
}
T_4
F_76 ( struct V_35 * V_36 )
{
struct V_10 * V_11 = V_36 -> V_11 ;
struct V_37 * V_38 = F_13 ( V_11 ) ;
struct V_68 * V_4 = V_36 -> V_4 ;
struct V_141 * V_134 ;
T_2 V_82 [ V_144 ] , V_5 [ V_148 ] , V_142 [ 6 ] , V_145 [ V_146 ] ;
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
if ( ! F_32 ( V_9 -> V_19 ) )
return V_39 ;
if ( V_11 -> V_18 < 24 + sizeof( * V_134 ) )
return V_51 ;
V_134 = (struct V_141 * )
( V_11 -> V_3 + V_11 -> V_18 - sizeof( * V_134 ) ) ;
if ( V_134 -> V_136 != V_137 ||
V_134 -> V_138 != sizeof( * V_134 ) - 2 )
return V_51 ;
F_65 ( V_142 , V_134 -> V_139 ) ;
if ( memcmp ( V_142 , V_4 -> V_54 . V_147 . V_110 , 6 ) <= 0 ) {
V_4 -> V_54 . V_147 . V_112 ++ ;
return V_51 ;
}
if ( ! ( V_38 -> V_40 & V_46 ) ) {
F_63 ( V_11 , V_82 ) ;
memcpy ( V_145 , V_9 -> V_63 , V_93 ) ;
memcpy ( V_145 + V_93 , V_142 , 6 ) ;
if ( F_75 ( V_4 -> V_54 . V_147 . V_106 , V_82 , V_145 ,
V_11 -> V_3 + 24 , V_11 -> V_18 - 24 ,
V_5 ) < 0 ||
memcmp ( V_5 , V_134 -> V_5 , sizeof( V_134 -> V_5 ) ) != 0 ) {
V_4 -> V_54 . V_147 . V_143 ++ ;
return V_51 ;
}
}
memcpy ( V_4 -> V_54 . V_147 . V_110 , V_142 , 6 ) ;
F_15 ( V_11 , V_11 -> V_18 - sizeof( * V_134 ) ) ;
return V_39 ;
}
T_1
F_77 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 = NULL ;
T_1 V_75 ;
F_26 (&tx->skbs, skb) {
V_13 = F_2 ( V_11 ) ;
if ( ! V_13 -> V_24 . V_25 )
return V_21 ;
if ( V_2 -> V_4 -> V_22 & V_149 ) {
V_75 = F_59 ( V_2 , V_11 ) ;
if ( V_75 != V_20 )
return V_75 ;
}
}
F_25 ( V_2 ) ;
return V_20 ;
}
T_4
F_78 ( struct V_35 * V_36 )
{
if ( V_36 -> V_77 && V_36 -> V_77 -> V_126 )
return F_62 ( V_36 ) ;
return V_51 ;
}
