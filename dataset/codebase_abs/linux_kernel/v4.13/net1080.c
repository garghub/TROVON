static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_2 * V_5 )
{
int V_6 = F_2 ( V_2 , V_3 ,
V_7 | V_8 |
V_9 ,
0 , V_4 , V_5 ,
sizeof *V_5 ) ;
if ( V_6 > 0 )
V_6 = 0 ;
if ( ! V_6 )
F_3 ( V_5 ) ;
return V_6 ;
}
static inline int
F_4 ( struct V_1 * V_2 , T_1 V_4 , T_2 * V_5 )
{
return F_1 ( V_2 , V_10 , V_4 , V_5 ) ;
}
static void
F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_2 V_11 )
{
F_6 ( V_2 , V_3 ,
V_12 | V_8 | V_9 ,
V_11 , V_4 , NULL , 0 ) ;
}
static inline void
F_7 ( struct V_1 * V_2 , T_1 V_4 , T_2 V_11 )
{
F_5 ( V_2 , V_10 , V_4 , V_11 ) ;
}
static inline void F_8 ( struct V_1 * V_2 , T_2 V_13 )
{
F_9 ( V_2 , V_14 , V_2 -> V_15 ,
L_1 ,
V_2 -> V_16 -> V_17 -> V_18 , V_2 -> V_16 -> V_19 ,
V_13 ,
( V_13 & V_20 ) ? L_2 : L_3 ,
( V_13 & V_21 ) ? L_4 : L_3 ,
( V_13 & V_22 ) ? L_5 : L_3 ,
( V_13 & V_23 ) ? L_6 : L_3 ,
( V_13 & V_24 ) ? L_7 : L_3 ,
( V_13 & V_25 ) ? L_8 : L_3 ,
( V_13 & V_26 ) ? L_9 : L_3 ,
( V_13 & V_27 ) ? L_8 : L_3 ,
( V_13 & V_28 ) ? L_9 : L_3 ,
V_13 & ~ V_29 ) ;
}
static inline void F_10 ( struct V_1 * V_2 , T_2 V_6 )
{
F_9 ( V_2 , V_14 , V_2 -> V_15 ,
L_10 ,
V_2 -> V_16 -> V_17 -> V_18 , V_2 -> V_16 -> V_19 ,
V_6 ,
( V_6 & V_30 ) ? 'A' : 'B' ,
F_11 ( V_6 ) ,
( V_6 & V_31 ) ? L_11 : L_3 ,
( V_6 & V_32 ) ? L_12 : L_3 ,
( V_6 & V_33 ) ? L_13 : L_3 ,
F_12 ( V_6 ) ,
( V_6 & V_34 ) ? L_11 : L_3 ,
( V_6 & V_35 ) ? L_12 : L_3 ,
( V_6 & V_36 ) ? L_13 : L_3 ,
V_6 & V_37 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
T_2 V_13 , V_6 , V_38 ;
T_2 V_39 ;
int V_40 ;
if ( ( V_40 = F_4 ( V_2 , V_41 , & V_39 ) ) < 0 ) {
F_14 ( V_2 -> V_15 , L_14 ,
V_2 -> V_16 -> V_17 -> V_18 , V_2 -> V_16 -> V_19 , V_40 ) ;
goto V_42;
}
V_6 = V_39 ;
F_10 ( V_2 , V_6 ) ;
if ( ( V_40 = F_4 ( V_2 , V_43 , & V_39 ) ) < 0 ) {
F_14 ( V_2 -> V_15 , L_15 , V_40 ) ;
goto V_42;
}
V_13 = V_39 ;
F_8 ( V_2 , V_13 ) ;
F_7 ( V_2 , V_43 ,
V_25 | V_27 ) ;
if ( ( V_40 = F_4 ( V_2 , V_44 , & V_39 ) ) < 0 ) {
F_14 ( V_2 -> V_15 , L_16 , V_40 ) ;
goto V_42;
}
V_38 = V_39 ;
F_7 ( V_2 , V_44 ,
F_15 ( V_45 , F_16 ( V_38 ) ) ) ;
F_14 ( V_2 -> V_15 , L_17 , V_45 ) ;
F_17 ( V_2 , V_14 , V_2 -> V_15 , L_18 ,
( V_6 & V_30 ) ? 'A' : 'B' ,
( V_6 & V_34 ) ? L_3 : L_19 ) ;
V_40 = 0 ;
V_42:
return V_40 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_40 ;
T_2 V_6 ;
T_2 V_39 ;
V_40 = F_4 ( V_2 , V_41 , & V_39 ) ;
V_6 = V_39 ;
if ( V_40 != 0 ) {
F_14 ( V_2 -> V_15 , L_20 , V_40 ) ;
return V_40 ;
}
if ( ( V_6 & V_34 ) != V_34 )
return - V_46 ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
if ( ++ V_2 -> V_47 <= 5 )
return;
if ( F_20 ( V_2 , V_10 ,
V_12 | V_8 |
V_9 ,
V_25 |
V_27 ,
V_43 , NULL , 0 ) )
return;
F_9 ( V_2 , V_48 , V_2 -> V_15 ,
L_21 ) ;
V_2 -> V_47 = 0 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
struct V_51 * V_52 ;
struct V_53 * V_54 ;
T_2 V_55 , V_56 ;
if ( V_50 -> V_57 < V_2 -> V_15 -> V_58 )
return 0 ;
if ( ! ( V_50 -> V_57 & 0x01 ) ) {
F_14 ( V_2 -> V_15 , L_22 ,
V_50 -> V_57 , V_2 -> V_15 -> V_58 , V_2 -> V_59 ,
V_2 -> V_15 -> V_60 ) ;
V_2 -> V_15 -> V_61 . V_62 ++ ;
F_19 ( V_2 ) ;
return 0 ;
}
V_52 = (struct V_51 * ) V_50 -> V_63 ;
V_55 = F_22 ( & V_52 -> V_55 ) ;
V_56 = F_22 ( & V_52 -> V_56 ) ;
if ( F_23 ( V_56 ) > V_64 ) {
V_2 -> V_15 -> V_61 . V_62 ++ ;
F_14 ( V_2 -> V_15 , L_23 , V_56 ) ;
F_19 ( V_2 ) ;
return 0 ;
} else if ( V_55 < V_65 ) {
V_2 -> V_15 -> V_61 . V_62 ++ ;
F_14 ( V_2 -> V_15 , L_24 , V_55 ) ;
F_19 ( V_2 ) ;
return 0 ;
} else if ( V_55 > V_65 ) {
F_14 ( V_2 -> V_15 , L_25 , V_55 - V_65 ) ;
F_19 ( V_2 ) ;
}
F_24 ( V_50 , V_55 ) ;
V_54 = (struct V_53 * )
( V_50 -> V_63 + V_50 -> V_57 - sizeof *V_54 ) ;
F_25 ( V_50 , V_50 -> V_57 - sizeof *V_54 ) ;
if ( ( V_56 & 0x01 ) == 0 ) {
if ( V_50 -> V_63 [ V_56 ] != V_66 ) {
V_2 -> V_15 -> V_61 . V_62 ++ ;
F_14 ( V_2 -> V_15 , L_26 ) ;
return 0 ;
}
F_25 ( V_50 , V_50 -> V_57 - 1 ) ;
}
if ( V_50 -> V_57 != V_56 ) {
V_2 -> V_15 -> V_61 . V_62 ++ ;
F_14 ( V_2 -> V_15 , L_27 ,
V_50 -> V_57 , V_56 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
if ( V_52 -> V_67 != F_26 ( & V_54 -> V_67 ) ) {
V_2 -> V_15 -> V_61 . V_68 ++ ;
F_14 ( V_2 -> V_15 , L_28 ,
F_27 ( V_52 -> V_67 ) ,
F_27 ( V_54 -> V_67 ) ) ;
return 0 ;
}
#if 0
netdev_dbg(dev->net, "frame <rx h %d p %d id %d\n", header->hdr_len,
header->packet_len, header->packet_id);
#endif
V_2 -> V_47 = 0 ;
return 1 ;
}
static struct V_49 *
F_28 ( struct V_1 * V_2 , struct V_49 * V_50 , T_3 V_69 )
{
struct V_49 * V_70 ;
struct V_51 * V_52 = NULL ;
struct V_53 * V_54 = NULL ;
int V_71 = sizeof ( struct V_53 ) ;
int V_57 = V_50 -> V_57 ;
if ( ! ( ( V_57 + V_71 + sizeof ( struct V_51 ) ) & 0x01 ) )
V_71 ++ ;
if ( ! F_29 ( V_50 ) ) {
int V_72 = F_30 ( V_50 ) ;
int V_73 = F_31 ( V_50 ) ;
if ( V_71 <= V_73 &&
sizeof( struct V_51 ) <= V_72 )
goto V_74;
if ( ( sizeof ( struct V_51 ) + V_71 ) <
( V_72 + V_73 ) ) {
V_50 -> V_63 = memmove ( V_50 -> V_75
+ sizeof ( struct V_51 ) ,
V_50 -> V_63 , V_50 -> V_57 ) ;
F_32 ( V_50 , V_57 ) ;
goto V_74;
}
}
V_70 = F_33 ( V_50 ,
sizeof ( struct V_51 ) ,
V_71 ,
V_69 ) ;
F_34 ( V_50 ) ;
if ( ! V_70 )
return V_70 ;
V_50 = V_70 ;
V_74:
V_52 = F_35 ( V_50 , sizeof *V_52 ) ;
V_52 -> V_55 = F_36 ( sizeof ( * V_52 ) ) ;
V_52 -> V_56 = F_36 ( V_57 ) ;
V_52 -> V_67 = F_36 ( ( T_2 ) V_2 -> V_76 ++ ) ;
if ( ! ( ( V_50 -> V_57 + sizeof *V_54 ) & 0x01 ) )
F_37 ( V_50 , V_66 ) ;
V_54 = F_38 ( V_50 , sizeof *V_54 ) ;
F_39 ( V_52 -> V_67 , & V_54 -> V_67 ) ;
#if 0
netdev_dbg(dev->net, "frame >tx h %d p %d id %d\n",
header->hdr_len, header->packet_len,
header->packet_id);
#endif
return V_50 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_77 * V_78 )
{
unsigned V_79 = sizeof ( struct V_51 )
+ 1
+ sizeof ( struct V_53 ) ;
V_2 -> V_15 -> V_58 += V_79 ;
V_2 -> V_80 = V_2 -> V_15 -> V_58 + V_2 -> V_15 -> V_60 ;
V_2 -> V_59 = V_64 ;
return F_41 ( V_2 , V_78 ) ;
}
