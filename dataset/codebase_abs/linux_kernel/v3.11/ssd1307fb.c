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
static inline int F_8 ( struct V_5 * V_6 , T_2 V_12 )
{
struct V_1 * V_3 ;
int V_7 ;
V_3 = F_1 ( 1 , V_13 ) ;
if ( ! V_3 )
return - V_11 ;
V_3 -> V_12 [ 0 ] = V_12 ;
V_7 = F_3 ( V_6 , V_3 , 1 ) ;
F_7 ( V_3 ) ;
return V_7 ;
}
static void F_9 ( struct V_14 * V_15 )
{
struct V_1 * V_3 ;
T_2 * V_16 = V_15 -> V_17 -> V_18 ;
int V_19 , V_20 , V_21 ;
V_3 = F_1 ( V_15 -> V_22 * V_15 -> V_23 / 8 ,
V_13 ) ;
if ( ! V_3 )
return;
for ( V_19 = 0 ; V_19 < ( V_15 -> V_23 / 8 ) ; V_19 ++ ) {
for ( V_20 = 0 ; V_20 < V_15 -> V_22 ; V_20 ++ ) {
T_1 V_24 = V_19 * V_15 -> V_22 + V_20 ;
V_3 -> V_12 [ V_24 ] = 0 ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ ) {
T_1 V_25 = V_15 -> V_22 * V_19 ;
T_1 V_26 = V_25 + ( V_15 -> V_22 * V_21 + V_20 ) / 8 ;
T_2 V_27 = * ( V_16 + V_26 ) ;
T_2 V_28 = V_27 & ( 1 << ( V_20 % 8 ) ) ;
V_28 = V_28 >> ( V_20 % 8 ) ;
V_3 -> V_12 [ V_24 ] |= V_28 << V_21 ;
}
}
}
F_3 ( V_15 -> V_6 , V_3 , V_15 -> V_22 * V_15 -> V_23 / 8 ) ;
F_7 ( V_3 ) ;
}
static T_3 F_10 ( struct V_29 * V_17 , const char T_4 * V_30 ,
T_5 V_31 , T_6 * V_32 )
{
struct V_14 * V_15 = V_17 -> V_15 ;
unsigned long V_33 ;
unsigned long V_34 = * V_32 ;
T_2 T_7 * V_35 ;
V_33 = V_17 -> V_36 . V_37 ;
if ( V_34 > V_33 )
return - V_38 ;
if ( V_31 + V_34 > V_33 )
V_31 = V_33 - V_34 ;
if ( ! V_31 )
return - V_38 ;
V_35 = ( void V_39 * ) ( V_17 -> V_18 + V_34 ) ;
if ( F_11 ( V_35 , V_30 , V_31 ) )
return - V_40 ;
F_9 ( V_15 ) ;
* V_32 += V_31 ;
return V_31 ;
}
static void F_12 ( struct V_29 * V_17 , const struct V_41 * V_42 )
{
struct V_14 * V_15 = V_17 -> V_15 ;
F_13 ( V_17 , V_42 ) ;
F_9 ( V_15 ) ;
}
static void F_14 ( struct V_29 * V_17 , const struct V_43 * V_44 )
{
struct V_14 * V_15 = V_17 -> V_15 ;
F_15 ( V_17 , V_44 ) ;
F_9 ( V_15 ) ;
}
static void F_16 ( struct V_29 * V_17 , const struct V_45 * V_46 )
{
struct V_14 * V_15 = V_17 -> V_15 ;
F_17 ( V_17 , V_46 ) ;
F_9 ( V_15 ) ;
}
static void F_18 ( struct V_29 * V_17 ,
struct V_47 * V_48 )
{
F_9 ( V_17 -> V_15 ) ;
}
static int F_19 ( struct V_14 * V_15 )
{
int V_7 ;
V_15 -> V_49 = F_20 ( & V_15 -> V_6 -> V_8 , NULL ) ;
if ( F_21 ( V_15 -> V_49 ) ) {
F_5 ( & V_15 -> V_6 -> V_8 , L_2 ) ;
return F_22 ( V_15 -> V_49 ) ;
}
V_15 -> V_50 = F_23 ( V_15 -> V_49 ) ;
F_24 ( V_15 -> V_49 , V_15 -> V_50 / 2 , V_15 -> V_50 ) ;
F_25 ( V_15 -> V_49 ) ;
F_26 ( & V_15 -> V_6 -> V_8 , L_3 ,
V_15 -> V_49 -> V_49 , V_15 -> V_50 ) ;
V_7 = F_6 ( V_15 -> V_6 , V_51 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_15 -> V_6 , V_52 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_27 ( struct V_14 * V_15 )
{
F_28 ( V_15 -> V_49 ) ;
F_29 ( V_15 -> V_49 ) ;
return 0 ;
}
static int F_30 ( struct V_14 * V_15 )
{
int V_7 ;
V_7 = F_6 ( V_15 -> V_6 , V_53 ) ;
V_7 = V_7 & F_6 ( V_15 -> V_6 , 0x7f ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_15 -> V_6 , 0xc8 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_15 -> V_6 , V_51 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_15 -> V_6 , V_54 ) ;
V_7 = V_7 & F_6 ( V_15 -> V_6 , V_15 -> V_23 - 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_15 -> V_6 , V_55 ) ;
V_7 = F_6 ( V_15 -> V_6 , 0x20 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_15 -> V_6 , V_56 ) ;
V_7 = V_7 & F_6 ( V_15 -> V_6 , 0xf0 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_15 -> V_6 , V_57 ) ;
V_7 = V_7 & F_6 ( V_15 -> V_6 , 0x22 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_15 -> V_6 , V_58 ) ;
V_7 = V_7 & F_6 ( V_15 -> V_6 , 0x22 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_15 -> V_6 , V_59 ) ;
V_7 = V_7 & F_6 ( V_15 -> V_6 , 0x49 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_15 -> V_6 , V_60 ) ;
V_7 = V_7 & F_6 ( V_15 -> V_6 , 0x14 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_15 -> V_6 , V_61 ) ;
V_7 = V_7 & F_6 ( V_15 -> V_6 ,
V_62 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_15 -> V_6 , V_63 ) ;
V_7 = V_7 & F_6 ( V_15 -> V_6 , 0x0 ) ;
V_7 = V_7 & F_6 ( V_15 -> V_6 , V_15 -> V_22 - 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_15 -> V_6 , V_64 ) ;
V_7 = V_7 & F_6 ( V_15 -> V_6 , 0x0 ) ;
V_7 = V_7 & F_6 ( V_15 -> V_6 ,
V_15 -> V_65 + ( V_15 -> V_23 / 8 ) - 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_15 -> V_6 , V_52 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_31 ( struct V_5 * V_6 ,
const struct V_66 * V_67 )
{
struct V_29 * V_17 ;
struct V_68 * V_69 = V_6 -> V_8 . V_70 ;
T_1 V_71 ;
struct V_14 * V_15 ;
T_2 * V_16 ;
int V_7 ;
if ( ! V_69 ) {
F_5 ( & V_6 -> V_8 , L_4 ) ;
return - V_38 ;
}
V_17 = F_32 ( sizeof( struct V_14 ) , & V_6 -> V_8 ) ;
if ( ! V_17 ) {
F_5 ( & V_6 -> V_8 , L_5 ) ;
return - V_11 ;
}
V_15 = V_17 -> V_15 ;
V_15 -> V_17 = V_17 ;
V_15 -> V_6 = V_6 ;
V_15 -> V_72 = (struct V_73 * ) F_33 ( V_74 ,
& V_6 -> V_8 ) -> V_12 ;
V_15 -> V_75 = F_34 ( V_6 -> V_8 . V_70 ,
L_6 , 0 ) ;
if ( ! F_35 ( V_15 -> V_75 ) ) {
V_7 = - V_38 ;
goto V_76;
}
if ( F_36 ( V_69 , L_7 , & V_15 -> V_22 ) )
V_15 -> V_22 = 96 ;
if ( F_36 ( V_69 , L_8 , & V_15 -> V_23 ) )
V_15 -> V_22 = 16 ;
if ( F_36 ( V_69 , L_9 , & V_15 -> V_65 ) )
V_15 -> V_65 = 1 ;
V_71 = V_15 -> V_22 * V_15 -> V_23 / 8 ;
V_16 = F_37 ( & V_6 -> V_8 , V_71 , V_4 ) ;
if ( ! V_16 ) {
F_5 ( & V_6 -> V_8 , L_10 ) ;
V_7 = - V_11 ;
goto V_76;
}
V_17 -> V_77 = & V_73 ;
V_17 -> V_36 = V_78 ;
V_17 -> V_36 . V_79 = V_15 -> V_22 / 8 ;
V_17 -> V_80 = & V_81 ;
V_17 -> V_82 = V_83 ;
V_17 -> V_82 . V_84 = V_15 -> V_22 ;
V_17 -> V_82 . V_85 = V_15 -> V_22 ;
V_17 -> V_82 . V_86 = V_15 -> V_23 ;
V_17 -> V_82 . V_87 = V_15 -> V_23 ;
V_17 -> V_82 . V_88 . V_89 = 1 ;
V_17 -> V_82 . V_88 . V_90 = 0 ;
V_17 -> V_82 . V_91 . V_89 = 1 ;
V_17 -> V_82 . V_91 . V_90 = 0 ;
V_17 -> V_82 . V_92 . V_89 = 1 ;
V_17 -> V_82 . V_92 . V_90 = 0 ;
V_17 -> V_18 = ( T_2 V_39 T_7 * ) V_16 ;
V_17 -> V_36 . V_93 = ( unsigned long ) V_16 ;
V_17 -> V_36 . V_37 = V_71 ;
F_38 ( V_17 ) ;
V_7 = F_39 ( & V_6 -> V_8 , V_15 -> V_75 ,
V_94 ,
L_11 ) ;
if ( V_7 ) {
F_5 ( & V_6 -> V_8 ,
L_12 ,
V_15 -> V_75 , V_7 ) ;
goto V_95;
}
F_40 ( V_6 , V_17 ) ;
F_41 ( V_15 -> V_75 , 0 ) ;
F_42 ( 4 ) ;
F_41 ( V_15 -> V_75 , 1 ) ;
F_42 ( 4 ) ;
if ( V_15 -> V_72 -> V_96 ) {
V_7 = V_15 -> V_72 -> V_96 ( V_15 ) ;
if ( V_7 )
goto V_95;
}
V_7 = F_43 ( V_17 ) ;
if ( V_7 ) {
F_5 ( & V_6 -> V_8 , L_13 ) ;
goto V_97;
}
F_44 ( & V_6 -> V_8 , L_14 , V_17 -> V_69 , V_17 -> V_36 . V_67 , V_71 ) ;
return 0 ;
V_97:
if ( V_15 -> V_72 -> remove )
V_15 -> V_72 -> remove ( V_15 ) ;
V_95:
F_45 ( V_17 ) ;
V_76:
F_46 ( V_17 ) ;
return V_7 ;
}
static int F_47 ( struct V_5 * V_6 )
{
struct V_29 * V_17 = F_48 ( V_6 ) ;
struct V_14 * V_15 = V_17 -> V_15 ;
F_49 ( V_17 ) ;
if ( V_15 -> V_72 -> remove )
V_15 -> V_72 -> remove ( V_15 ) ;
F_45 ( V_17 ) ;
F_46 ( V_17 ) ;
return 0 ;
}
