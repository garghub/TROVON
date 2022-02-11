static struct V_1 * F_1 ( T_1 V_2 , T_2 type )
{
struct V_1 * V_3 ;
V_3 = F_2 ( sizeof( struct V_1 ) + V_2 , V_4 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> type = type ;
return V_3 ;
}
static int F_3 ( struct V_5 * V_6 ,
struct V_1 * V_3 , T_1 V_2 )
{
int V_7 ;
V_2 += sizeof( struct V_1 ) ;
V_7 = F_4 ( V_6 , ( T_2 * ) V_3 , V_2 ) ;
if ( V_7 != V_2 ) {
F_5 ( & V_6 -> V_8 , L_1 ) ;
return V_7 ;
}
return 0 ;
}
static inline int F_6 ( struct V_5 * V_6 , T_2 V_9 )
{
struct V_1 * V_3 ;
int V_7 ;
V_3 = F_1 ( 1 , V_10 ) ;
if ( ! V_3 )
return - V_11 ;
V_3 -> V_12 [ 0 ] = V_9 ;
V_7 = F_3 ( V_6 , V_3 , 1 ) ;
F_7 ( V_3 ) ;
return V_7 ;
}
static void F_8 ( struct V_13 * V_14 )
{
struct V_1 * V_3 ;
T_2 * V_15 = V_14 -> V_16 -> V_17 ;
int V_18 , V_19 , V_20 ;
V_3 = F_1 ( V_14 -> V_21 * V_14 -> V_22 / 8 ,
V_23 ) ;
if ( ! V_3 )
return;
for ( V_18 = 0 ; V_18 < ( V_14 -> V_22 / 8 ) ; V_18 ++ ) {
for ( V_19 = 0 ; V_19 < V_14 -> V_21 ; V_19 ++ ) {
T_1 V_24 = V_18 * V_14 -> V_21 + V_19 ;
V_3 -> V_12 [ V_24 ] = 0 ;
for ( V_20 = 0 ; V_20 < 8 ; V_20 ++ ) {
T_1 V_25 = V_14 -> V_21 * V_18 ;
T_1 V_26 = V_25 + ( V_14 -> V_21 * V_20 + V_19 ) / 8 ;
T_2 V_27 = * ( V_15 + V_26 ) ;
T_2 V_28 = V_27 & ( 1 << ( V_19 % 8 ) ) ;
V_28 = V_28 >> ( V_19 % 8 ) ;
V_3 -> V_12 [ V_24 ] |= V_28 << V_20 ;
}
}
}
F_3 ( V_14 -> V_6 , V_3 , V_14 -> V_21 * V_14 -> V_22 / 8 ) ;
F_7 ( V_3 ) ;
}
static T_3 F_9 ( struct V_29 * V_16 , const char T_4 * V_30 ,
T_5 V_31 , T_6 * V_32 )
{
struct V_13 * V_14 = V_16 -> V_14 ;
unsigned long V_33 ;
unsigned long V_34 = * V_32 ;
T_2 T_7 * V_35 ;
V_33 = V_16 -> V_36 . V_37 ;
if ( V_34 > V_33 )
return - V_38 ;
if ( V_31 + V_34 > V_33 )
V_31 = V_33 - V_34 ;
if ( ! V_31 )
return - V_38 ;
V_35 = ( void V_39 * ) ( V_16 -> V_17 + V_34 ) ;
if ( F_10 ( V_35 , V_30 , V_31 ) )
return - V_40 ;
F_8 ( V_14 ) ;
* V_32 += V_31 ;
return V_31 ;
}
static void F_11 ( struct V_29 * V_16 , const struct V_41 * V_42 )
{
struct V_13 * V_14 = V_16 -> V_14 ;
F_12 ( V_16 , V_42 ) ;
F_8 ( V_14 ) ;
}
static void F_13 ( struct V_29 * V_16 , const struct V_43 * V_44 )
{
struct V_13 * V_14 = V_16 -> V_14 ;
F_14 ( V_16 , V_44 ) ;
F_8 ( V_14 ) ;
}
static void F_15 ( struct V_29 * V_16 , const struct V_45 * V_46 )
{
struct V_13 * V_14 = V_16 -> V_14 ;
F_16 ( V_16 , V_46 ) ;
F_8 ( V_14 ) ;
}
static void F_17 ( struct V_29 * V_16 ,
struct V_47 * V_48 )
{
F_8 ( V_16 -> V_14 ) ;
}
static int F_18 ( struct V_13 * V_14 )
{
int V_7 ;
V_14 -> V_49 = F_19 ( & V_14 -> V_6 -> V_8 , NULL ) ;
if ( F_20 ( V_14 -> V_49 ) ) {
F_5 ( & V_14 -> V_6 -> V_8 , L_2 ) ;
return F_21 ( V_14 -> V_49 ) ;
}
V_14 -> V_50 = F_22 ( V_14 -> V_49 ) ;
F_23 ( V_14 -> V_49 , V_14 -> V_50 / 2 , V_14 -> V_50 ) ;
F_24 ( V_14 -> V_49 ) ;
F_25 ( & V_14 -> V_6 -> V_8 , L_3 ,
V_14 -> V_49 -> V_49 , V_14 -> V_50 ) ;
V_7 = F_6 ( V_14 -> V_6 , V_51 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_52 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_26 ( struct V_13 * V_14 )
{
F_27 ( V_14 -> V_49 ) ;
F_28 ( V_14 -> V_49 ) ;
return 0 ;
}
static int F_29 ( struct V_13 * V_14 )
{
int V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_53 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , 0x7f ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , 0xc8 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_51 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_54 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_14 -> V_22 - 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_55 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , 0x20 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_56 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , 0xf0 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_57 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , 0x22 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_58 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , 0x22 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_59 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , 0x49 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_60 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , 0x14 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_61 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 ,
V_62 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_63 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , 0x0 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_14 -> V_21 - 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_64 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , 0x0 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 ,
V_14 -> V_65 + ( V_14 -> V_22 / 8 ) - 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_52 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_30 ( struct V_5 * V_6 ,
const struct V_66 * V_67 )
{
struct V_29 * V_16 ;
struct V_68 * V_69 = V_6 -> V_8 . V_70 ;
T_1 V_71 ;
struct V_13 * V_14 ;
T_2 * V_15 ;
int V_7 ;
if ( ! V_69 ) {
F_5 ( & V_6 -> V_8 , L_4 ) ;
return - V_38 ;
}
V_16 = F_31 ( sizeof( struct V_13 ) , & V_6 -> V_8 ) ;
if ( ! V_16 ) {
F_5 ( & V_6 -> V_8 , L_5 ) ;
return - V_11 ;
}
V_14 = V_16 -> V_14 ;
V_14 -> V_16 = V_16 ;
V_14 -> V_6 = V_6 ;
V_14 -> V_72 = (struct V_73 * ) F_32 ( V_74 ,
& V_6 -> V_8 ) -> V_12 ;
V_14 -> V_75 = F_33 ( V_6 -> V_8 . V_70 ,
L_6 , 0 ) ;
if ( ! F_34 ( V_14 -> V_75 ) ) {
V_7 = - V_38 ;
goto V_76;
}
if ( F_35 ( V_69 , L_7 , & V_14 -> V_21 ) )
V_14 -> V_21 = 96 ;
if ( F_35 ( V_69 , L_8 , & V_14 -> V_22 ) )
V_14 -> V_22 = 16 ;
if ( F_35 ( V_69 , L_9 , & V_14 -> V_65 ) )
V_14 -> V_65 = 1 ;
V_71 = V_14 -> V_21 * V_14 -> V_22 / 8 ;
V_15 = F_36 ( & V_6 -> V_8 , V_71 , V_4 ) ;
if ( ! V_15 ) {
F_5 ( & V_6 -> V_8 , L_10 ) ;
V_7 = - V_11 ;
goto V_76;
}
V_16 -> V_77 = & V_73 ;
V_16 -> V_36 = V_78 ;
V_16 -> V_36 . V_79 = V_14 -> V_21 / 8 ;
V_16 -> V_80 = & V_81 ;
V_16 -> V_82 = V_83 ;
V_16 -> V_82 . V_84 = V_14 -> V_21 ;
V_16 -> V_82 . V_85 = V_14 -> V_21 ;
V_16 -> V_82 . V_86 = V_14 -> V_22 ;
V_16 -> V_82 . V_87 = V_14 -> V_22 ;
V_16 -> V_82 . V_88 . V_89 = 1 ;
V_16 -> V_82 . V_88 . V_90 = 0 ;
V_16 -> V_82 . V_91 . V_89 = 1 ;
V_16 -> V_82 . V_91 . V_90 = 0 ;
V_16 -> V_82 . V_92 . V_89 = 1 ;
V_16 -> V_82 . V_92 . V_90 = 0 ;
V_16 -> V_17 = ( T_2 V_39 T_7 * ) V_15 ;
V_16 -> V_36 . V_93 = ( unsigned long ) V_15 ;
V_16 -> V_36 . V_37 = V_71 ;
F_37 ( V_16 ) ;
V_7 = F_38 ( & V_6 -> V_8 , V_14 -> V_75 ,
V_94 ,
L_11 ) ;
if ( V_7 ) {
F_5 ( & V_6 -> V_8 ,
L_12 ,
V_14 -> V_75 , V_7 ) ;
goto V_95;
}
F_39 ( V_6 , V_16 ) ;
F_40 ( V_14 -> V_75 , 0 ) ;
F_41 ( 4 ) ;
F_40 ( V_14 -> V_75 , 1 ) ;
F_41 ( 4 ) ;
if ( V_14 -> V_72 -> V_96 ) {
V_7 = V_14 -> V_72 -> V_96 ( V_14 ) ;
if ( V_7 )
goto V_95;
}
V_7 = F_42 ( V_16 ) ;
if ( V_7 ) {
F_5 ( & V_6 -> V_8 , L_13 ) ;
goto V_97;
}
F_43 ( & V_6 -> V_8 , L_14 , V_16 -> V_69 , V_16 -> V_36 . V_67 , V_71 ) ;
return 0 ;
V_97:
if ( V_14 -> V_72 -> remove )
V_14 -> V_72 -> remove ( V_14 ) ;
V_95:
F_44 ( V_16 ) ;
V_76:
F_45 ( V_16 ) ;
return V_7 ;
}
static int F_46 ( struct V_5 * V_6 )
{
struct V_29 * V_16 = F_47 ( V_6 ) ;
struct V_13 * V_14 = V_16 -> V_14 ;
F_48 ( V_16 ) ;
if ( V_14 -> V_72 -> remove )
V_14 -> V_72 -> remove ( V_14 ) ;
F_44 ( V_16 ) ;
F_45 ( V_16 ) ;
return 0 ;
}
