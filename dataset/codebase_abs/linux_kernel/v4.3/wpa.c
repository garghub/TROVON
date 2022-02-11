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
F_15 ( V_36 -> V_47 ,
V_36 -> V_4 ? V_36 -> V_4 -> V_15 . V_50 : - 1 ,
( void * ) V_11 -> V_3 , NULL , V_62 ) ;
return V_51 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
struct V_63 * V_4 = V_2 -> V_4 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
unsigned int V_7 ;
int V_18 , V_14 ;
T_2 * V_64 ;
if ( V_13 -> V_24 . V_25 &&
! ( V_13 -> V_24 . V_25 -> V_22 & V_65 ) &&
! ( V_13 -> V_24 . V_25 -> V_22 & V_66 ) ) {
return 0 ;
}
V_7 = F_4 ( V_9 -> V_19 ) ;
V_18 = V_11 -> V_18 - V_7 ;
if ( V_13 -> V_24 . V_25 )
V_14 = 0 ;
else
V_14 = V_32 ;
if ( F_17 ( F_7 ( V_11 ) < V_14 ||
F_8 ( V_11 ) < V_33 ) )
return - 1 ;
V_64 = F_18 ( V_11 , V_33 ) ;
memmove ( V_64 , V_64 + V_33 , V_7 ) ;
V_64 += V_7 ;
if ( V_13 -> V_24 . V_25 &&
( V_13 -> V_24 . V_25 -> V_22 & V_66 ) )
return 0 ;
F_19 ( & V_4 -> V_54 . V_55 . V_67 ) ;
V_4 -> V_54 . V_55 . V_2 . V_59 ++ ;
if ( V_4 -> V_54 . V_55 . V_2 . V_59 == 0 )
V_4 -> V_54 . V_55 . V_2 . V_57 ++ ;
V_64 = F_20 ( V_64 , V_4 ) ;
F_21 ( & V_4 -> V_54 . V_55 . V_67 ) ;
if ( V_13 -> V_24 . V_25 )
return 0 ;
F_9 ( V_11 , V_32 ) ;
return F_22 ( V_2 -> V_27 -> V_68 ,
V_4 , V_11 , V_64 , V_18 ) ;
}
T_1
F_23 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
F_24 ( V_2 ) ;
F_25 (&tx->skbs, skb) {
if ( F_16 ( V_2 , V_11 ) < 0 )
return V_21 ;
}
return V_20 ;
}
T_4
F_26 ( struct V_35 * V_36 )
{
struct V_8 * V_9 = (struct V_8 * ) V_36 -> V_11 -> V_3 ;
int V_7 , V_69 , V_70 = 0 ;
struct V_63 * V_4 = V_36 -> V_4 ;
struct V_10 * V_11 = V_36 -> V_11 ;
struct V_37 * V_38 = F_12 ( V_11 ) ;
V_7 = F_4 ( V_9 -> V_19 ) ;
if ( ! F_27 ( V_9 -> V_19 ) )
return V_39 ;
if ( ! V_36 -> V_71 || V_11 -> V_18 - V_7 < 12 )
return V_51 ;
if ( F_13 ( V_36 -> V_11 ) )
return V_51 ;
V_9 = ( void * ) V_11 -> V_3 ;
if ( V_38 -> V_40 & V_46 )
V_70 = 1 ;
V_69 = F_28 ( V_36 -> V_27 -> V_72 ,
V_4 , V_11 -> V_3 + V_7 ,
V_11 -> V_18 - V_7 , V_36 -> V_71 -> V_71 . V_73 ,
V_9 -> V_74 , V_70 , V_36 -> V_56 ,
& V_36 -> V_58 ,
& V_36 -> V_60 ) ;
if ( V_69 != V_75 )
return V_51 ;
F_14 ( V_11 , V_11 -> V_18 - V_32 ) ;
memmove ( V_11 -> V_3 + V_33 , V_11 -> V_3 , V_7 ) ;
F_29 ( V_11 , V_33 ) ;
return V_39 ;
}
static void F_30 ( struct V_10 * V_11 , T_2 * V_76 , T_2 * V_77 , T_2 * V_78 )
{
T_5 V_79 ;
int V_80 , V_81 ;
T_2 V_82 ;
T_6 V_83 ;
unsigned int V_7 ;
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
V_81 = F_31 ( V_9 -> V_19 ) ;
V_79 = V_9 -> V_19 ;
V_79 &= ~ F_32 ( V_84 |
V_85 | V_86 ) ;
if ( ! V_81 )
V_79 &= ~ F_32 ( 0x0070 ) ;
V_79 |= F_32 ( V_87 ) ;
V_7 = F_4 ( V_9 -> V_19 ) ;
V_83 = V_7 - 2 ;
V_80 = F_33 ( V_9 -> V_19 ) ;
if ( F_34 ( V_9 -> V_19 ) )
V_82 = * F_35 ( V_9 ) & V_88 ;
else
V_82 = 0 ;
V_77 [ 0 ] = 0x1 ;
V_77 [ 1 ] = V_82 | ( V_81 << 4 ) ;
memcpy ( & V_77 [ 2 ] , V_9 -> V_89 , V_90 ) ;
memcpy ( & V_77 [ 8 ] , V_76 , V_91 ) ;
F_36 ( V_83 , & V_78 [ 0 ] ) ;
F_37 ( V_79 , ( T_5 * ) & V_78 [ 2 ] ) ;
memcpy ( & V_78 [ 4 ] , & V_9 -> V_74 , 3 * V_90 ) ;
V_78 [ 22 ] = * ( ( T_2 * ) & V_9 -> V_92 ) & 0x0f ;
V_78 [ 23 ] = 0 ;
if ( V_80 ) {
memcpy ( & V_78 [ 24 ] , V_9 -> V_93 , V_90 ) ;
V_78 [ 30 ] = V_82 ;
V_78 [ 31 ] = 0 ;
} else {
memset ( & V_78 [ 24 ] , 0 , V_90 + V_94 ) ;
V_78 [ 24 ] = V_82 ;
}
}
static inline void F_38 ( T_2 * V_9 , T_2 * V_76 , int V_95 )
{
V_9 [ 0 ] = V_76 [ 5 ] ;
V_9 [ 1 ] = V_76 [ 4 ] ;
V_9 [ 2 ] = 0 ;
V_9 [ 3 ] = 0x20 | ( V_95 << 6 ) ;
V_9 [ 4 ] = V_76 [ 3 ] ;
V_9 [ 5 ] = V_76 [ 2 ] ;
V_9 [ 6 ] = V_76 [ 1 ] ;
V_9 [ 7 ] = V_76 [ 0 ] ;
}
static inline void F_39 ( T_2 * V_76 , T_2 * V_9 )
{
V_76 [ 0 ] = V_9 [ 7 ] ;
V_76 [ 1 ] = V_9 [ 6 ] ;
V_76 [ 2 ] = V_9 [ 5 ] ;
V_76 [ 3 ] = V_9 [ 4 ] ;
V_76 [ 4 ] = V_9 [ 1 ] ;
V_76 [ 5 ] = V_9 [ 0 ] ;
}
static int F_40 ( struct V_1 * V_2 , struct V_10 * V_11 ,
unsigned int V_96 )
{
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
struct V_63 * V_4 = V_2 -> V_4 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
int V_7 , V_18 , V_14 ;
T_2 * V_64 ;
T_2 V_76 [ 6 ] ;
T_7 V_97 ;
T_2 V_78 [ 2 * V_98 ] ;
T_2 V_77 [ V_98 ] ;
if ( V_13 -> V_24 . V_25 &&
! ( V_13 -> V_24 . V_25 -> V_22 & V_65 ) &&
! ( V_13 -> V_24 . V_25 -> V_22 & V_66 ) &&
! ( ( V_13 -> V_24 . V_25 -> V_22 &
V_99 ) &&
F_31 ( V_9 -> V_19 ) ) ) {
return 0 ;
}
V_7 = F_4 ( V_9 -> V_19 ) ;
V_18 = V_11 -> V_18 - V_7 ;
if ( V_13 -> V_24 . V_25 )
V_14 = 0 ;
else
V_14 = V_96 ;
if ( F_17 ( F_7 ( V_11 ) < V_14 ||
F_8 ( V_11 ) < V_100 ) )
return - 1 ;
V_64 = F_18 ( V_11 , V_100 ) ;
memmove ( V_64 , V_64 + V_100 , V_7 ) ;
if ( V_13 -> V_24 . V_25 &&
( V_13 -> V_24 . V_25 -> V_22 & V_66 ) )
return 0 ;
V_9 = (struct V_8 * ) V_64 ;
V_64 += V_7 ;
V_97 = F_41 ( & V_4 -> V_15 . V_101 ) ;
V_76 [ 5 ] = V_97 ;
V_76 [ 4 ] = V_97 >> 8 ;
V_76 [ 3 ] = V_97 >> 16 ;
V_76 [ 2 ] = V_97 >> 24 ;
V_76 [ 1 ] = V_97 >> 32 ;
V_76 [ 0 ] = V_97 >> 40 ;
F_38 ( V_64 , V_76 , V_4 -> V_15 . V_50 ) ;
if ( V_13 -> V_24 . V_25 )
return 0 ;
V_64 += V_100 ;
F_30 ( V_11 , V_76 , V_77 , V_78 ) ;
F_42 ( V_4 -> V_54 . V_102 . V_103 , V_77 , V_78 , V_64 , V_18 ,
F_9 ( V_11 , V_96 ) , V_96 ) ;
return 0 ;
}
T_1
F_43 ( struct V_1 * V_2 ,
unsigned int V_96 )
{
struct V_10 * V_11 ;
F_24 ( V_2 ) ;
F_25 (&tx->skbs, skb) {
if ( F_40 ( V_2 , V_11 , V_96 ) < 0 )
return V_21 ;
}
return V_20 ;
}
T_4
F_44 ( struct V_35 * V_36 ,
unsigned int V_96 )
{
struct V_8 * V_9 = (struct V_8 * ) V_36 -> V_11 -> V_3 ;
int V_7 ;
struct V_63 * V_4 = V_36 -> V_4 ;
struct V_10 * V_11 = V_36 -> V_11 ;
struct V_37 * V_38 = F_12 ( V_11 ) ;
T_2 V_76 [ V_91 ] ;
int V_6 ;
int V_104 ;
V_7 = F_4 ( V_9 -> V_19 ) ;
if ( ! F_27 ( V_9 -> V_19 ) &&
! F_45 ( V_11 ) )
return V_39 ;
V_6 = V_11 -> V_18 - V_7 - V_100 - V_96 ;
if ( ! V_36 -> V_71 || V_6 < 0 )
return V_51 ;
if ( V_38 -> V_40 & V_46 ) {
if ( ! F_46 ( V_36 -> V_11 , V_7 + V_100 ) )
return V_51 ;
} else {
if ( F_13 ( V_36 -> V_11 ) )
return V_51 ;
}
if ( ! ( V_38 -> V_40 & V_105 ) ) {
F_39 ( V_76 , V_11 -> V_3 + V_7 ) ;
V_104 = V_36 -> V_56 ;
if ( memcmp ( V_76 , V_4 -> V_54 . V_102 . V_106 [ V_104 ] ,
V_91 ) <= 0 ) {
V_4 -> V_54 . V_102 . V_107 ++ ;
return V_51 ;
}
if ( ! ( V_38 -> V_40 & V_46 ) ) {
T_2 V_78 [ 2 * V_98 ] ;
T_2 V_77 [ V_98 ] ;
F_30 ( V_11 , V_76 , V_77 , V_78 ) ;
if ( F_47 (
V_4 -> V_54 . V_102 . V_103 , V_77 , V_78 ,
V_11 -> V_3 + V_7 + V_100 ,
V_6 ,
V_11 -> V_3 + V_11 -> V_18 - V_96 , V_96 ) )
return V_51 ;
}
memcpy ( V_4 -> V_54 . V_102 . V_106 [ V_104 ] , V_76 , V_91 ) ;
}
if ( F_48 ( V_11 , V_11 -> V_18 - V_96 ) )
return V_51 ;
memmove ( V_11 -> V_3 + V_100 , V_11 -> V_3 , V_7 ) ;
F_29 ( V_11 , V_100 ) ;
return V_39 ;
}
static void F_49 ( struct V_10 * V_11 , T_2 * V_76 , T_2 * V_108 , T_2 * V_78 )
{
T_5 V_79 ;
T_2 V_82 ;
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
memcpy ( V_108 , V_9 -> V_89 , V_90 ) ;
memcpy ( & V_108 [ V_90 ] , V_76 , V_109 ) ;
V_108 [ 13 ] = 0 ;
V_108 [ 14 ] = 0 ;
V_108 [ V_98 - 1 ] = 0x01 ;
F_36 ( F_4 ( V_9 -> V_19 ) - 2 , & V_78 [ 0 ] ) ;
V_79 = V_9 -> V_19 ;
V_79 &= ~ F_32 ( V_84 |
V_85 | V_86 ) ;
if ( ! F_31 ( V_9 -> V_19 ) )
V_79 &= ~ F_32 ( 0x0070 ) ;
V_79 |= F_32 ( V_87 ) ;
F_37 ( V_79 , ( T_5 * ) & V_78 [ 2 ] ) ;
memcpy ( & V_78 [ 4 ] , & V_9 -> V_74 , 3 * V_90 ) ;
V_78 [ 22 ] = * ( ( T_2 * ) & V_9 -> V_92 ) & 0x0f ;
V_78 [ 23 ] = 0 ;
if ( F_34 ( V_9 -> V_19 ) )
V_82 = * F_35 ( V_9 ) &
V_88 ;
else
V_82 = 0 ;
if ( F_33 ( V_9 -> V_19 ) ) {
memcpy ( & V_78 [ 24 ] , V_9 -> V_93 , V_90 ) ;
V_78 [ 30 ] = V_82 ;
V_78 [ 31 ] = 0 ;
} else {
memset ( & V_78 [ 24 ] , 0 , V_90 + V_94 ) ;
V_78 [ 24 ] = V_82 ;
}
}
static inline void F_50 ( T_2 * V_9 , const T_2 * V_76 , int V_95 )
{
V_9 [ 0 ] = V_76 [ 5 ] ;
V_9 [ 1 ] = V_76 [ 4 ] ;
V_9 [ 2 ] = 0 ;
V_9 [ 3 ] = 0x20 | ( V_95 << 6 ) ;
V_9 [ 4 ] = V_76 [ 3 ] ;
V_9 [ 5 ] = V_76 [ 2 ] ;
V_9 [ 6 ] = V_76 [ 1 ] ;
V_9 [ 7 ] = V_76 [ 0 ] ;
}
static inline void F_51 ( T_2 * V_76 , const T_2 * V_9 )
{
V_76 [ 0 ] = V_9 [ 7 ] ;
V_76 [ 1 ] = V_9 [ 6 ] ;
V_76 [ 2 ] = V_9 [ 5 ] ;
V_76 [ 3 ] = V_9 [ 4 ] ;
V_76 [ 4 ] = V_9 [ 1 ] ;
V_76 [ 5 ] = V_9 [ 0 ] ;
}
static int F_52 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
struct V_63 * V_4 = V_2 -> V_4 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
int V_7 , V_18 , V_14 ;
T_2 * V_64 ;
T_2 V_76 [ 6 ] ;
T_7 V_97 ;
T_2 V_78 [ 2 * V_98 ] ;
T_2 V_108 [ V_98 ] ;
if ( V_13 -> V_24 . V_25 &&
! ( V_13 -> V_24 . V_25 -> V_22 & V_65 ) &&
! ( V_13 -> V_24 . V_25 -> V_22 & V_66 ) &&
! ( ( V_13 -> V_24 . V_25 -> V_22 &
V_99 ) &&
F_31 ( V_9 -> V_19 ) ) ) {
return 0 ;
}
V_7 = F_4 ( V_9 -> V_19 ) ;
V_18 = V_11 -> V_18 - V_7 ;
if ( V_13 -> V_24 . V_25 )
V_14 = 0 ;
else
V_14 = V_110 ;
if ( F_17 ( F_7 ( V_11 ) < V_14 ||
F_8 ( V_11 ) < V_111 ) )
return - 1 ;
V_64 = F_18 ( V_11 , V_111 ) ;
memmove ( V_64 , V_64 + V_111 , V_7 ) ;
F_53 ( V_11 , F_54 ( V_11 ) +
V_111 ) ;
if ( V_13 -> V_24 . V_25 &&
( V_13 -> V_24 . V_25 -> V_22 & V_66 ) )
return 0 ;
V_9 = (struct V_8 * ) V_64 ;
V_64 += V_7 ;
V_97 = F_41 ( & V_4 -> V_15 . V_101 ) ;
V_76 [ 5 ] = V_97 ;
V_76 [ 4 ] = V_97 >> 8 ;
V_76 [ 3 ] = V_97 >> 16 ;
V_76 [ 2 ] = V_97 >> 24 ;
V_76 [ 1 ] = V_97 >> 32 ;
V_76 [ 0 ] = V_97 >> 40 ;
F_50 ( V_64 , V_76 , V_4 -> V_15 . V_50 ) ;
if ( V_13 -> V_24 . V_25 )
return 0 ;
V_64 += V_111 ;
F_49 ( V_11 , V_76 , V_108 , V_78 ) ;
F_55 ( V_4 -> V_54 . V_112 . V_103 , V_108 , V_78 , V_64 , V_18 ,
F_9 ( V_11 , V_110 ) ) ;
return 0 ;
}
T_1
F_56 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
F_24 ( V_2 ) ;
F_25 (&tx->skbs, skb) {
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
struct V_63 * V_4 = V_36 -> V_4 ;
struct V_10 * V_11 = V_36 -> V_11 ;
struct V_37 * V_38 = F_12 ( V_11 ) ;
T_2 V_76 [ V_109 ] ;
int V_6 ;
int V_104 ;
V_7 = F_4 ( V_9 -> V_19 ) ;
if ( ! F_27 ( V_9 -> V_19 ) &&
! F_45 ( V_11 ) )
return V_39 ;
V_6 = V_11 -> V_18 - V_7 - V_111 -
V_110 ;
if ( ! V_36 -> V_71 || V_6 < 0 )
return V_51 ;
if ( V_38 -> V_40 & V_46 ) {
if ( ! F_46 ( V_36 -> V_11 , V_7 + V_111 ) )
return V_51 ;
} else {
if ( F_13 ( V_36 -> V_11 ) )
return V_51 ;
}
if ( ! ( V_38 -> V_40 & V_105 ) ) {
F_51 ( V_76 , V_11 -> V_3 + V_7 ) ;
V_104 = V_36 -> V_56 ;
if ( memcmp ( V_76 , V_4 -> V_54 . V_112 . V_106 [ V_104 ] ,
V_109 ) <= 0 ) {
V_4 -> V_54 . V_112 . V_107 ++ ;
return V_51 ;
}
if ( ! ( V_38 -> V_40 & V_46 ) ) {
T_2 V_78 [ 2 * V_98 ] ;
T_2 V_108 [ V_98 ] ;
F_49 ( V_11 , V_76 , V_108 , V_78 ) ;
if ( F_58 (
V_4 -> V_54 . V_112 . V_103 , V_108 , V_78 ,
V_11 -> V_3 + V_7 + V_111 ,
V_6 ,
V_11 -> V_3 + V_11 -> V_18 -
V_110 ) )
return V_51 ;
}
memcpy ( V_4 -> V_54 . V_112 . V_106 [ V_104 ] , V_76 , V_109 ) ;
}
if ( F_48 ( V_11 , V_11 -> V_18 - V_110 ) )
return V_51 ;
memmove ( V_11 -> V_3 + V_111 , V_11 -> V_3 , V_7 ) ;
F_29 ( V_11 , V_111 ) ;
return V_39 ;
}
static T_1
F_59 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
struct V_63 * V_4 = V_2 -> V_4 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
int V_7 ;
T_2 * V_64 , V_113 = V_4 -> V_15 . V_113 ;
if ( V_13 -> V_24 . V_25 &&
! ( V_13 -> V_24 . V_25 -> V_22 & V_66 ) ) {
return V_20 ;
}
if ( F_5 ( F_8 ( V_11 ) < V_113 &&
F_60 ( V_11 , V_113 , 0 , V_62 ) ) )
return V_21 ;
V_7 = F_4 ( V_9 -> V_19 ) ;
V_64 = F_18 ( V_11 , V_113 ) ;
memmove ( V_64 , V_64 + V_113 , V_7 ) ;
return V_20 ;
}
static inline int F_61 ( T_2 * V_114 , T_2 * V_115 , int V_18 )
{
int V_116 ;
for ( V_116 = V_18 - 1 ; V_116 >= 0 ; V_116 -- ) {
if ( V_114 [ V_116 ] < V_115 [ V_116 ] )
return - 1 ;
else if ( V_114 [ V_116 ] > V_115 [ V_116 ] )
return 1 ;
}
return 0 ;
}
static T_4
F_62 ( struct V_35 * V_36 )
{
struct V_63 * V_4 = V_36 -> V_4 ;
struct V_8 * V_9 = (struct V_8 * ) V_36 -> V_11 -> V_3 ;
const struct V_117 * V_118 = NULL ;
int V_7 = F_4 ( V_9 -> V_19 ) ;
struct V_37 * V_38 = F_12 ( V_36 -> V_11 ) ;
int V_6 ;
T_2 * V_106 ;
T_2 * V_119 ;
T_2 V_82 ;
if ( ! V_36 -> V_71 || ! V_36 -> V_71 -> V_120 ||
! ( V_38 -> V_40 & V_46 ) )
return V_51 ;
if ( ! F_27 ( V_9 -> V_19 ) )
return V_39 ;
V_118 = V_36 -> V_71 -> V_120 ;
V_6 = V_36 -> V_11 -> V_18 - V_7 - V_118 -> V_121 ;
if ( V_6 < 0 )
return V_51 ;
if ( F_34 ( V_9 -> V_19 ) )
V_82 = * F_35 ( V_9 ) &
V_88 ;
else
V_82 = 0 ;
if ( F_13 ( V_36 -> V_11 ) )
return V_51 ;
V_9 = (struct V_8 * ) V_36 -> V_11 -> V_3 ;
V_106 = V_4 -> V_54 . V_122 . V_106 [ V_82 ] ;
V_119 = V_36 -> V_11 -> V_3 + V_7 + V_118 -> V_123 ;
if ( F_61 ( V_119 , V_106 , V_118 -> V_124 ) <= 0 )
return V_51 ;
memcpy ( V_106 , V_119 , V_118 -> V_124 ) ;
if ( F_48 ( V_36 -> V_11 , V_36 -> V_11 -> V_18 - V_118 -> V_96 ) )
return V_51 ;
memmove ( V_36 -> V_11 -> V_3 + V_118 -> V_121 , V_36 -> V_11 -> V_3 , V_7 ) ;
F_29 ( V_36 -> V_11 , V_118 -> V_121 ) ;
return V_39 ;
}
static void F_63 ( struct V_10 * V_11 , T_2 * V_78 )
{
T_5 V_79 ;
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
V_79 = V_9 -> V_19 ;
V_79 &= ~ F_32 ( V_84 | V_85 |
V_86 ) ;
F_37 ( V_79 , ( T_5 * ) & V_78 [ 0 ] ) ;
memcpy ( V_78 + 2 , & V_9 -> V_74 , 3 * V_90 ) ;
}
static inline void F_64 ( T_2 * V_125 , T_7 V_76 )
{
* V_125 ++ = V_76 ;
* V_125 ++ = V_76 >> 8 ;
* V_125 ++ = V_76 >> 16 ;
* V_125 ++ = V_76 >> 24 ;
* V_125 ++ = V_76 >> 32 ;
* V_125 = V_76 >> 40 ;
}
static inline void F_65 ( T_2 * V_125 , const T_2 * V_126 )
{
* V_125 ++ = V_126 [ 5 ] ;
* V_125 ++ = V_126 [ 4 ] ;
* V_125 ++ = V_126 [ 3 ] ;
* V_125 ++ = V_126 [ 2 ] ;
* V_125 ++ = V_126 [ 1 ] ;
* V_125 = V_126 [ 0 ] ;
}
T_1
F_66 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_63 * V_4 = V_2 -> V_4 ;
struct V_127 * V_128 ;
T_2 V_78 [ 20 ] ;
T_7 V_97 ;
if ( F_17 ( F_67 ( & V_2 -> V_129 ) != 1 ) )
return V_21 ;
V_11 = F_68 ( & V_2 -> V_129 ) ;
V_13 = F_2 ( V_11 ) ;
if ( V_13 -> V_24 . V_25 )
return V_20 ;
if ( F_17 ( F_7 ( V_11 ) < sizeof( * V_128 ) ) )
return V_21 ;
V_128 = (struct V_127 * ) F_9 ( V_11 , sizeof( * V_128 ) ) ;
V_128 -> V_130 = V_131 ;
V_128 -> V_132 = sizeof( * V_128 ) - 2 ;
V_128 -> V_95 = F_32 ( V_4 -> V_15 . V_50 ) ;
V_97 = F_41 ( & V_4 -> V_15 . V_101 ) ;
F_64 ( V_128 -> V_133 , V_97 ) ;
F_63 ( V_11 , V_78 ) ;
F_69 ( V_4 -> V_54 . V_134 . V_103 , V_78 ,
V_11 -> V_3 + 24 , V_11 -> V_18 - 24 , V_128 -> V_5 ) ;
return V_20 ;
}
T_1
F_70 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_63 * V_4 = V_2 -> V_4 ;
struct V_135 * V_128 ;
T_2 V_78 [ 20 ] ;
T_7 V_97 ;
if ( F_17 ( F_67 ( & V_2 -> V_129 ) != 1 ) )
return V_21 ;
V_11 = F_68 ( & V_2 -> V_129 ) ;
V_13 = F_2 ( V_11 ) ;
if ( V_13 -> V_24 . V_25 )
return V_20 ;
if ( F_17 ( F_7 ( V_11 ) < sizeof( * V_128 ) ) )
return V_21 ;
V_128 = (struct V_135 * ) F_9 ( V_11 , sizeof( * V_128 ) ) ;
V_128 -> V_130 = V_131 ;
V_128 -> V_132 = sizeof( * V_128 ) - 2 ;
V_128 -> V_95 = F_32 ( V_4 -> V_15 . V_50 ) ;
V_97 = F_41 ( & V_4 -> V_15 . V_101 ) ;
F_64 ( V_128 -> V_133 , V_97 ) ;
F_63 ( V_11 , V_78 ) ;
F_71 ( V_4 -> V_54 . V_134 . V_103 , V_78 ,
V_11 -> V_3 + 24 , V_11 -> V_18 - 24 , V_128 -> V_5 ) ;
return V_20 ;
}
T_4
F_72 ( struct V_35 * V_36 )
{
struct V_10 * V_11 = V_36 -> V_11 ;
struct V_37 * V_38 = F_12 ( V_11 ) ;
struct V_63 * V_4 = V_36 -> V_4 ;
struct V_127 * V_128 ;
T_2 V_78 [ 20 ] , V_5 [ 8 ] , V_136 [ 6 ] ;
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
if ( ! F_31 ( V_9 -> V_19 ) )
return V_39 ;
if ( V_11 -> V_18 < 24 + sizeof( * V_128 ) )
return V_51 ;
V_128 = (struct V_127 * )
( V_11 -> V_3 + V_11 -> V_18 - sizeof( * V_128 ) ) ;
if ( V_128 -> V_130 != V_131 ||
V_128 -> V_132 != sizeof( * V_128 ) - 2 )
return V_51 ;
F_65 ( V_136 , V_128 -> V_133 ) ;
if ( memcmp ( V_136 , V_4 -> V_54 . V_134 . V_106 , 6 ) <= 0 ) {
V_4 -> V_54 . V_134 . V_107 ++ ;
return V_51 ;
}
if ( ! ( V_38 -> V_40 & V_46 ) ) {
F_63 ( V_11 , V_78 ) ;
F_69 ( V_4 -> V_54 . V_134 . V_103 , V_78 ,
V_11 -> V_3 + 24 , V_11 -> V_18 - 24 , V_5 ) ;
if ( memcmp ( V_5 , V_128 -> V_5 , sizeof( V_128 -> V_5 ) ) != 0 ) {
V_4 -> V_54 . V_134 . V_137 ++ ;
return V_51 ;
}
}
memcpy ( V_4 -> V_54 . V_134 . V_106 , V_136 , 6 ) ;
F_14 ( V_11 , V_11 -> V_18 - sizeof( * V_128 ) ) ;
return V_39 ;
}
T_4
F_73 ( struct V_35 * V_36 )
{
struct V_10 * V_11 = V_36 -> V_11 ;
struct V_37 * V_38 = F_12 ( V_11 ) ;
struct V_63 * V_4 = V_36 -> V_4 ;
struct V_135 * V_128 ;
T_2 V_78 [ 20 ] , V_5 [ 16 ] , V_136 [ 6 ] ;
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
if ( ! F_31 ( V_9 -> V_19 ) )
return V_39 ;
if ( V_11 -> V_18 < 24 + sizeof( * V_128 ) )
return V_51 ;
V_128 = (struct V_135 * )
( V_11 -> V_3 + V_11 -> V_18 - sizeof( * V_128 ) ) ;
if ( V_128 -> V_130 != V_131 ||
V_128 -> V_132 != sizeof( * V_128 ) - 2 )
return V_51 ;
F_65 ( V_136 , V_128 -> V_133 ) ;
if ( memcmp ( V_136 , V_4 -> V_54 . V_134 . V_106 , 6 ) <= 0 ) {
V_4 -> V_54 . V_134 . V_107 ++ ;
return V_51 ;
}
if ( ! ( V_38 -> V_40 & V_46 ) ) {
F_63 ( V_11 , V_78 ) ;
F_71 ( V_4 -> V_54 . V_134 . V_103 , V_78 ,
V_11 -> V_3 + 24 , V_11 -> V_18 - 24 , V_5 ) ;
if ( memcmp ( V_5 , V_128 -> V_5 , sizeof( V_128 -> V_5 ) ) != 0 ) {
V_4 -> V_54 . V_134 . V_137 ++ ;
return V_51 ;
}
}
memcpy ( V_4 -> V_54 . V_134 . V_106 , V_136 , 6 ) ;
F_14 ( V_11 , V_11 -> V_18 - sizeof( * V_128 ) ) ;
return V_39 ;
}
T_1
F_74 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_63 * V_4 = V_2 -> V_4 ;
struct V_135 * V_128 ;
struct V_8 * V_9 ;
T_2 V_78 [ 20 ] ;
T_7 V_97 ;
T_2 V_138 [ 12 ] ;
if ( F_17 ( F_67 ( & V_2 -> V_129 ) != 1 ) )
return V_21 ;
V_11 = F_68 ( & V_2 -> V_129 ) ;
V_13 = F_2 ( V_11 ) ;
if ( V_13 -> V_24 . V_25 )
return V_20 ;
if ( F_17 ( F_7 ( V_11 ) < sizeof( * V_128 ) ) )
return V_21 ;
V_128 = (struct V_135 * ) F_9 ( V_11 , sizeof( * V_128 ) ) ;
V_128 -> V_130 = V_131 ;
V_128 -> V_132 = sizeof( * V_128 ) - 2 ;
V_128 -> V_95 = F_32 ( V_4 -> V_15 . V_50 ) ;
V_97 = F_41 ( & V_4 -> V_15 . V_101 ) ;
F_64 ( V_128 -> V_133 , V_97 ) ;
F_63 ( V_11 , V_78 ) ;
V_9 = (struct V_8 * ) V_11 -> V_3 ;
memcpy ( V_138 , V_9 -> V_89 , V_90 ) ;
F_65 ( V_138 + V_90 , V_128 -> V_133 ) ;
if ( F_75 ( V_4 -> V_54 . V_139 . V_103 , V_78 , V_138 ,
V_11 -> V_3 + 24 , V_11 -> V_18 - 24 , V_128 -> V_5 ) < 0 )
return V_21 ;
return V_20 ;
}
T_4
F_76 ( struct V_35 * V_36 )
{
struct V_10 * V_11 = V_36 -> V_11 ;
struct V_37 * V_38 = F_12 ( V_11 ) ;
struct V_63 * V_4 = V_36 -> V_4 ;
struct V_135 * V_128 ;
T_2 V_78 [ 20 ] , V_5 [ 16 ] , V_136 [ 6 ] , V_138 [ 12 ] ;
struct V_8 * V_9 = (struct V_8 * ) V_11 -> V_3 ;
if ( ! F_31 ( V_9 -> V_19 ) )
return V_39 ;
if ( V_11 -> V_18 < 24 + sizeof( * V_128 ) )
return V_51 ;
V_128 = (struct V_135 * )
( V_11 -> V_3 + V_11 -> V_18 - sizeof( * V_128 ) ) ;
if ( V_128 -> V_130 != V_131 ||
V_128 -> V_132 != sizeof( * V_128 ) - 2 )
return V_51 ;
F_65 ( V_136 , V_128 -> V_133 ) ;
if ( memcmp ( V_136 , V_4 -> V_54 . V_139 . V_106 , 6 ) <= 0 ) {
V_4 -> V_54 . V_139 . V_107 ++ ;
return V_51 ;
}
if ( ! ( V_38 -> V_40 & V_46 ) ) {
F_63 ( V_11 , V_78 ) ;
memcpy ( V_138 , V_9 -> V_89 , V_90 ) ;
memcpy ( V_138 + V_90 , V_136 , 6 ) ;
if ( F_75 ( V_4 -> V_54 . V_139 . V_103 , V_78 , V_138 ,
V_11 -> V_3 + 24 , V_11 -> V_18 - 24 ,
V_5 ) < 0 ||
memcmp ( V_5 , V_128 -> V_5 , sizeof( V_128 -> V_5 ) ) != 0 ) {
V_4 -> V_54 . V_139 . V_137 ++ ;
return V_51 ;
}
}
memcpy ( V_4 -> V_54 . V_139 . V_106 , V_136 , 6 ) ;
F_14 ( V_11 , V_11 -> V_18 - sizeof( * V_128 ) ) ;
return V_39 ;
}
T_1
F_77 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 = NULL ;
T_1 V_69 ;
F_25 (&tx->skbs, skb) {
V_13 = F_2 ( V_11 ) ;
if ( ! V_13 -> V_24 . V_25 )
return V_21 ;
if ( V_2 -> V_4 -> V_22 & V_140 ) {
V_69 = F_59 ( V_2 , V_11 ) ;
if ( V_69 != V_20 )
return V_69 ;
}
}
F_24 ( V_2 ) ;
return V_20 ;
}
T_4
F_78 ( struct V_35 * V_36 )
{
if ( V_36 -> V_71 && V_36 -> V_71 -> V_120 )
return F_62 ( V_36 ) ;
return V_51 ;
}
