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
F_19 ( V_2 -> V_18 , L_15 ,
V_2 -> V_7 -> V_19 -> V_20 , V_2 -> V_7 -> V_21 , V_43 ) ;
goto V_46;
}
V_6 = * V_41 ;
F_11 ( V_2 , V_6 ) ;
if ( ( V_43 = F_5 ( V_2 , V_47 , V_41 ) ) < 0 ) {
F_19 ( V_2 -> V_18 , L_16 , V_43 ) ;
goto V_46;
}
V_16 = * V_41 ;
F_9 ( V_2 , V_16 ) ;
F_8 ( V_2 , V_47 ,
V_27 | V_29 ) ;
if ( ( V_43 = F_5 ( V_2 , V_48 , V_41 ) ) < 0 ) {
F_19 ( V_2 -> V_18 , L_17 , V_43 ) ;
goto V_46;
}
V_40 = * V_41 ;
F_8 ( V_2 , V_48 ,
F_20 ( V_49 , F_16 ( V_40 ) ) ) ;
F_19 ( V_2 -> V_18 , L_18 , V_49 ) ;
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
F_19 ( V_2 -> V_18 , L_21 , V_43 ) ;
return V_43 ;
}
if ( ( V_6 & V_36 ) != V_36 )
return - V_50 ;
return 0 ;
}
static void F_24 ( struct V_51 * V_51 )
{
F_22 ( V_51 -> V_52 ) ;
F_25 ( V_51 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
V_2 -> V_53 ++ ;
if ( V_2 -> V_53 > 5 ) {
struct V_51 * V_51 ;
struct V_54 * V_3 ;
int V_6 ;
V_51 = F_27 ( 0 , V_55 ) ;
if ( ! V_51 )
return;
V_3 = F_18 ( sizeof *V_3 , V_55 ) ;
if ( ! V_3 ) {
F_25 ( V_51 ) ;
return;
}
V_3 -> V_56 = V_14
| V_9
| V_10 ;
V_3 -> V_57 = V_12 ;
V_3 -> V_58 = F_28 ( V_27
| V_29 ) ;
V_3 -> V_59 = F_28 ( V_47 ) ;
V_3 -> V_60 = F_28 ( 0 ) ;
F_29 ( V_51 , V_2 -> V_7 ,
F_7 ( V_2 -> V_7 , 0 ) ,
( unsigned char * ) V_3 ,
NULL , 0 ,
F_24 , V_3 ) ;
V_6 = F_30 ( V_51 , V_55 ) ;
if ( V_6 ) {
F_22 ( V_3 ) ;
F_25 ( V_51 ) ;
return;
}
F_10 ( V_2 , V_61 , V_2 -> V_18 ,
L_22 ) ;
V_2 -> V_53 = 0 ;
}
}
static int F_31 ( struct V_1 * V_2 , struct V_62 * V_63 )
{
struct V_64 * V_65 ;
struct V_66 * V_67 ;
T_2 V_68 , V_69 ;
if ( ! ( V_63 -> V_70 & 0x01 ) ) {
F_19 ( V_2 -> V_18 , L_23 ,
V_63 -> V_70 , V_2 -> V_18 -> V_71 , V_2 -> V_72 ,
V_2 -> V_18 -> V_73 ) ;
V_2 -> V_18 -> V_74 . V_75 ++ ;
F_26 ( V_2 ) ;
return 0 ;
}
V_65 = (struct V_64 * ) V_63 -> V_76 ;
V_68 = F_32 ( & V_65 -> V_68 ) ;
V_69 = F_32 ( & V_65 -> V_69 ) ;
if ( F_33 ( V_69 ) > V_77 ) {
V_2 -> V_18 -> V_74 . V_75 ++ ;
F_19 ( V_2 -> V_18 , L_24 , V_69 ) ;
F_26 ( V_2 ) ;
return 0 ;
} else if ( V_68 < V_78 ) {
V_2 -> V_18 -> V_74 . V_75 ++ ;
F_19 ( V_2 -> V_18 , L_25 , V_68 ) ;
F_26 ( V_2 ) ;
return 0 ;
} else if ( V_68 > V_78 ) {
F_19 ( V_2 -> V_18 , L_26 , V_68 - V_78 ) ;
F_26 ( V_2 ) ;
}
F_34 ( V_63 , V_68 ) ;
V_67 = (struct V_66 * )
( V_63 -> V_76 + V_63 -> V_70 - sizeof *V_67 ) ;
F_35 ( V_63 , V_63 -> V_70 - sizeof *V_67 ) ;
if ( ( V_69 & 0x01 ) == 0 ) {
if ( V_63 -> V_76 [ V_69 ] != V_79 ) {
V_2 -> V_18 -> V_74 . V_75 ++ ;
F_19 ( V_2 -> V_18 , L_27 ) ;
return 0 ;
}
F_35 ( V_63 , V_63 -> V_70 - 1 ) ;
}
if ( V_63 -> V_70 != V_69 ) {
V_2 -> V_18 -> V_74 . V_75 ++ ;
F_19 ( V_2 -> V_18 , L_28 ,
V_63 -> V_70 , V_69 ) ;
F_26 ( V_2 ) ;
return 0 ;
}
if ( V_65 -> V_80 != F_36 ( & V_67 -> V_80 ) ) {
V_2 -> V_18 -> V_74 . V_81 ++ ;
F_19 ( V_2 -> V_18 , L_29 ,
F_37 ( V_65 -> V_80 ) ,
F_37 ( V_67 -> V_80 ) ) ;
return 0 ;
}
#if 0
netdev_dbg(dev->net, "frame <rx h %d p %d id %d\n", header->hdr_len,
header->packet_len, header->packet_id);
#endif
V_2 -> V_53 = 0 ;
return 1 ;
}
static struct V_62 *
F_38 ( struct V_1 * V_2 , struct V_62 * V_63 , T_3 V_82 )
{
struct V_62 * V_83 ;
struct V_64 * V_65 = NULL ;
struct V_66 * V_67 = NULL ;
int V_84 = sizeof ( struct V_66 ) ;
int V_70 = V_63 -> V_70 ;
if ( ! ( ( V_70 + V_84 + sizeof ( struct V_64 ) ) & 0x01 ) )
V_84 ++ ;
if ( ! F_39 ( V_63 ) ) {
int V_85 = F_40 ( V_63 ) ;
int V_86 = F_41 ( V_63 ) ;
if ( V_84 <= V_86 &&
sizeof( struct V_64 ) <= V_85 )
goto V_87;
if ( ( sizeof ( struct V_64 ) + V_84 ) <
( V_85 + V_86 ) ) {
V_63 -> V_76 = memmove ( V_63 -> V_88
+ sizeof ( struct V_64 ) ,
V_63 -> V_76 , V_63 -> V_70 ) ;
F_42 ( V_63 , V_70 ) ;
goto V_87;
}
}
V_83 = F_43 ( V_63 ,
sizeof ( struct V_64 ) ,
V_84 ,
V_82 ) ;
F_44 ( V_63 ) ;
if ( ! V_83 )
return V_83 ;
V_63 = V_83 ;
V_87:
V_65 = (struct V_64 * ) F_45 ( V_63 , sizeof *V_65 ) ;
V_65 -> V_68 = F_28 ( sizeof ( * V_65 ) ) ;
V_65 -> V_69 = F_28 ( V_70 ) ;
V_65 -> V_80 = F_28 ( ( T_2 ) V_2 -> V_89 ++ ) ;
if ( ! ( ( V_63 -> V_70 + sizeof *V_67 ) & 0x01 ) )
* F_46 ( V_63 , 1 ) = V_79 ;
V_67 = (struct V_66 * ) F_46 ( V_63 , sizeof *V_67 ) ;
F_47 ( V_65 -> V_80 , & V_67 -> V_80 ) ;
#if 0
netdev_dbg(dev->net, "frame >tx h %d p %d id %d\n",
header->hdr_len, header->packet_len,
header->packet_id);
#endif
return V_63 ;
}
static int F_48 ( struct V_1 * V_2 , struct V_90 * V_91 )
{
unsigned V_92 = sizeof ( struct V_64 )
+ 1
+ sizeof ( struct V_66 ) ;
V_2 -> V_18 -> V_71 += V_92 ;
V_2 -> V_93 = V_2 -> V_18 -> V_71 + V_2 -> V_18 -> V_73 ;
V_2 -> V_72 = V_77 ;
return F_49 ( V_2 , V_91 ) ;
}
