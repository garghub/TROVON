static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_2 * V_5 )
{
int V_6 = F_2 ( V_2 -> V_7 ,
F_3 ( V_2 -> V_7 , 0 ) ,
V_3 ,
V_8 | V_9 | V_10 ,
0 , V_4 ,
V_5 , sizeof *V_5 ,
V_11 ) ;
if ( V_6 > 0 )
V_6 = 0 ;
if ( ! V_6 )
F_4 ( V_5 ) ;
return V_6 ;
}
static inline int
F_5 ( struct V_1 * V_2 , T_1 V_4 , T_2 * V_5 )
{
return F_1 ( V_2 , V_12 , V_4 , V_5 ) ;
}
static void
F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_2 V_13 )
{
F_2 ( V_2 -> V_7 ,
F_7 ( V_2 -> V_7 , 0 ) ,
V_3 ,
V_14 | V_9 | V_10 ,
V_13 , V_4 ,
NULL , 0 ,
V_15 ) ;
}
static inline void
F_8 ( struct V_1 * V_2 , T_1 V_4 , T_2 V_13 )
{
F_6 ( V_2 , V_12 , V_4 , V_13 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , T_2 V_16 )
{
F_10 ( V_2 , V_17 , V_2 -> V_18 ,
L_1 ,
V_2 -> V_7 -> V_19 -> V_20 , V_2 -> V_7 -> V_21 ,
V_16 ,
( V_16 & V_22 ) ? L_2 : L_3 ,
( V_16 & V_23 ) ? L_4 : L_3 ,
( V_16 & V_24 ) ? L_5 : L_3 ,
( V_16 & V_25 ) ? L_6 : L_3 ,
( V_16 & V_26 ) ? L_7 : L_3 ,
( V_16 & V_27 ) ? L_8 : L_3 ,
( V_16 & V_28 ) ? L_9 : L_3 ,
( V_16 & V_29 ) ? L_8 : L_3 ,
( V_16 & V_30 ) ? L_9 : L_3 ,
V_16 & ~ V_31 ) ;
}
static inline void F_11 ( struct V_1 * V_2 , T_2 V_6 )
{
F_10 ( V_2 , V_17 , V_2 -> V_18 ,
L_10 ,
V_2 -> V_7 -> V_19 -> V_20 , V_2 -> V_7 -> V_21 ,
V_6 ,
( V_6 & V_32 ) ? 'A' : 'B' ,
F_12 ( V_6 ) ,
( V_6 & V_33 ) ? L_11 : L_3 ,
( V_6 & V_34 ) ? L_12 : L_3 ,
( V_6 & V_35 ) ? L_13 : L_3 ,
F_13 ( V_6 ) ,
( V_6 & V_36 ) ? L_11 : L_3 ,
( V_6 & V_37 ) ? L_12 : L_3 ,
( V_6 & V_38 ) ? L_13 : L_3 ,
V_6 & V_39 ) ;
}
static inline void F_14 ( struct V_1 * V_2 , T_2 V_40 )
{
F_10 ( V_2 , V_17 , V_2 -> V_18 , L_14 ,
V_2 -> V_7 -> V_19 -> V_20 , V_2 -> V_7 -> V_21 ,
V_40 , F_15 ( V_40 ) , F_16 ( V_40 ) ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_2 V_16 , V_6 , V_40 ;
T_2 * V_41 = F_18 ( sizeof ( T_2 ) , V_42 ) ;
int V_43 ;
if ( ! V_41 )
return - V_44 ;
if ( ( V_43 = F_5 ( V_2 , V_45 , V_41 ) ) < 0 ) {
F_19 ( L_15 ,
V_2 -> V_7 -> V_19 -> V_20 , V_2 -> V_7 -> V_21 , V_43 ) ;
goto V_46;
}
V_6 = * V_41 ;
F_11 ( V_2 , V_6 ) ;
if ( ( V_43 = F_5 ( V_2 , V_47 , V_41 ) ) < 0 ) {
F_19 ( L_16 , V_43 ) ;
goto V_46;
}
V_16 = * V_41 ;
F_9 ( V_2 , V_16 ) ;
F_8 ( V_2 , V_47 ,
V_27 | V_29 ) ;
if ( ( V_43 = F_5 ( V_2 , V_48 , V_41 ) ) < 0 ) {
F_19 ( L_17 , V_43 ) ;
goto V_46;
}
V_40 = * V_41 ;
F_8 ( V_2 , V_48 ,
F_20 ( V_49 , F_16 ( V_40 ) ) ) ;
F_19 ( L_18 , V_2 -> V_18 -> V_50 , V_49 ) ;
F_21 ( V_2 , V_17 , V_2 -> V_18 , L_19 ,
( V_6 & V_32 ) ? 'A' : 'B' ,
( V_6 & V_36 ) ? L_3 : L_20 ) ;
V_43 = 0 ;
V_46:
F_22 ( V_41 ) ;
return V_43 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_43 ;
T_2 V_6 ;
T_2 * V_41 = F_18 ( sizeof ( T_2 ) , V_42 ) ;
if ( ! V_41 )
return - V_44 ;
V_43 = F_5 ( V_2 , V_45 , V_41 ) ;
V_6 = * V_41 ;
F_22 ( V_41 ) ;
if ( V_43 != 0 ) {
F_19 ( L_21 , V_2 -> V_18 -> V_50 , V_43 ) ;
return V_43 ;
}
if ( ( V_6 & V_36 ) != V_36 )
return - V_51 ;
return 0 ;
}
static void F_24 ( struct V_52 * V_52 )
{
F_22 ( V_52 -> V_53 ) ;
F_25 ( V_52 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
V_2 -> V_54 ++ ;
if ( V_2 -> V_54 > 5 ) {
struct V_52 * V_52 ;
struct V_55 * V_3 ;
int V_6 ;
V_52 = F_27 ( 0 , V_56 ) ;
if ( ! V_52 )
return;
V_3 = F_18 ( sizeof *V_3 , V_56 ) ;
if ( ! V_3 ) {
F_25 ( V_52 ) ;
return;
}
V_3 -> V_57 = V_14
| V_9
| V_10 ;
V_3 -> V_58 = V_12 ;
V_3 -> V_59 = F_28 ( V_27
| V_29 ) ;
V_3 -> V_60 = F_28 ( V_47 ) ;
V_3 -> V_61 = F_28 ( 0 ) ;
F_29 ( V_52 , V_2 -> V_7 ,
F_7 ( V_2 -> V_7 , 0 ) ,
( unsigned char * ) V_3 ,
NULL , 0 ,
F_24 , V_3 ) ;
V_6 = F_30 ( V_52 , V_56 ) ;
if ( V_6 ) {
F_22 ( V_3 ) ;
F_25 ( V_52 ) ;
return;
}
F_10 ( V_2 , V_62 , V_2 -> V_18 ,
L_22 ) ;
V_2 -> V_54 = 0 ;
}
}
static int F_31 ( struct V_1 * V_2 , struct V_63 * V_64 )
{
struct V_65 * V_66 ;
struct V_67 * V_68 ;
T_2 V_69 , V_70 ;
if ( ! ( V_64 -> V_71 & 0x01 ) ) {
#ifdef F_32
struct V_72 * V_18 = V_2 -> V_18 ;
F_19 ( L_23 , V_64 -> V_71 ,
V_18 -> V_73 , V_2 -> V_74 , V_18 -> V_75 ) ;
#endif
V_2 -> V_18 -> V_76 . V_77 ++ ;
F_26 ( V_2 ) ;
return 0 ;
}
V_66 = (struct V_65 * ) V_64 -> V_78 ;
V_69 = F_33 ( & V_66 -> V_69 ) ;
V_70 = F_33 ( & V_66 -> V_70 ) ;
if ( F_34 ( V_70 ) > V_79 ) {
V_2 -> V_18 -> V_76 . V_77 ++ ;
F_19 ( L_24 , V_70 ) ;
F_26 ( V_2 ) ;
return 0 ;
} else if ( V_69 < V_80 ) {
V_2 -> V_18 -> V_76 . V_77 ++ ;
F_19 ( L_25 , V_69 ) ;
F_26 ( V_2 ) ;
return 0 ;
} else if ( V_69 > V_80 ) {
F_19 ( L_26 , V_69 - V_80 ) ;
F_26 ( V_2 ) ;
}
F_35 ( V_64 , V_69 ) ;
V_68 = (struct V_67 * )
( V_64 -> V_78 + V_64 -> V_71 - sizeof *V_68 ) ;
F_36 ( V_64 , V_64 -> V_71 - sizeof *V_68 ) ;
if ( ( V_70 & 0x01 ) == 0 ) {
if ( V_64 -> V_78 [ V_70 ] != V_81 ) {
V_2 -> V_18 -> V_76 . V_77 ++ ;
F_19 ( L_27 ) ;
return 0 ;
}
F_36 ( V_64 , V_64 -> V_71 - 1 ) ;
}
if ( V_64 -> V_71 != V_70 ) {
V_2 -> V_18 -> V_76 . V_77 ++ ;
F_19 ( L_28 ,
V_64 -> V_71 , V_70 ) ;
F_26 ( V_2 ) ;
return 0 ;
}
if ( V_66 -> V_82 != F_37 ( & V_68 -> V_82 ) ) {
V_2 -> V_18 -> V_76 . V_83 ++ ;
F_19 ( L_29 ,
F_38 ( V_66 -> V_82 ) ,
F_38 ( V_68 -> V_82 ) ) ;
return 0 ;
}
#if 0
netdev_dbg(dev->net, "frame <rx h %d p %d id %d\n", header->hdr_len,
header->packet_len, header->packet_id);
#endif
V_2 -> V_54 = 0 ;
return 1 ;
}
static struct V_63 *
F_39 ( struct V_1 * V_2 , struct V_63 * V_64 , T_3 V_84 )
{
struct V_63 * V_85 ;
struct V_65 * V_66 = NULL ;
struct V_67 * V_68 = NULL ;
int V_86 = sizeof ( struct V_67 ) ;
int V_71 = V_64 -> V_71 ;
if ( ! ( ( V_71 + V_86 + sizeof ( struct V_65 ) ) & 0x01 ) )
V_86 ++ ;
if ( ! F_40 ( V_64 ) ) {
int V_87 = F_41 ( V_64 ) ;
int V_88 = F_42 ( V_64 ) ;
if ( V_86 <= V_88 &&
sizeof( struct V_65 ) <= V_87 )
goto V_89;
if ( ( sizeof ( struct V_65 ) + V_86 ) <
( V_87 + V_88 ) ) {
V_64 -> V_78 = memmove ( V_64 -> V_90
+ sizeof ( struct V_65 ) ,
V_64 -> V_78 , V_64 -> V_71 ) ;
F_43 ( V_64 , V_71 ) ;
goto V_89;
}
}
V_85 = F_44 ( V_64 ,
sizeof ( struct V_65 ) ,
V_86 ,
V_84 ) ;
F_45 ( V_64 ) ;
if ( ! V_85 )
return V_85 ;
V_64 = V_85 ;
V_89:
V_66 = (struct V_65 * ) F_46 ( V_64 , sizeof *V_66 ) ;
V_66 -> V_69 = F_28 ( sizeof ( * V_66 ) ) ;
V_66 -> V_70 = F_28 ( V_71 ) ;
V_66 -> V_82 = F_28 ( ( T_2 ) V_2 -> V_91 ++ ) ;
if ( ! ( ( V_64 -> V_71 + sizeof *V_68 ) & 0x01 ) )
* F_47 ( V_64 , 1 ) = V_81 ;
V_68 = (struct V_67 * ) F_47 ( V_64 , sizeof *V_68 ) ;
F_48 ( V_66 -> V_82 , & V_68 -> V_82 ) ;
#if 0
netdev_dbg(dev->net, "frame >tx h %d p %d id %d\n",
header->hdr_len, header->packet_len,
header->packet_id);
#endif
return V_64 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_92 * V_93 )
{
unsigned V_94 = sizeof ( struct V_65 )
+ 1
+ sizeof ( struct V_67 ) ;
V_2 -> V_18 -> V_73 += V_94 ;
V_2 -> V_95 = V_2 -> V_18 -> V_73 + V_2 -> V_18 -> V_75 ;
V_2 -> V_74 = V_79 ;
return F_50 ( V_2 , V_93 ) ;
}
