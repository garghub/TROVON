static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_8 , V_9 , V_10 ;
V_8 = F_2 ( V_6 -> V_11 + V_12 ) ;
V_9 = F_2 ( V_6 -> V_11 + V_13 ) & V_8 ;
V_10 = F_2 ( V_6 -> V_11 + V_14 ) ;
if ( F_3 ( V_10 ) ) {
F_4 ( V_15 L_1 ,
V_16 , V_10 ) ;
F_5 ( V_10 , V_6 -> V_11 + V_14 ) ;
return V_17 ;
}
if ( V_9 & ~ ( V_18 | \
V_19 ) ) {
F_4 ( V_15 L_2 ,
V_16 , V_9 ) ;
return V_20 ;
}
F_5 ( V_9 , V_6 -> V_11 + V_13 ) ;
if ( V_9 & V_18 )
F_6 ( V_4 -> V_21 ) ;
if ( V_9 & V_19 )
F_6 ( V_4 -> V_22 ) ;
return V_17 ;
}
static void F_7 ( void T_2 * V_23 , int V_24 ,
unsigned long V_25 ,
struct V_26 * V_27 )
{
int V_28 ;
F_5 ( 0 , V_23 + F_8 ( V_24 ) ) ;
F_5 ( 0 , V_23 + F_9 ( V_24 ) ) ;
for ( V_28 = 0 ; V_28 < V_27 -> V_29 ; V_28 ++ ) {
struct V_30 * V_31 = V_27 -> V_31 + V_28 ;
if ( ( V_31 -> V_23 & 0xffff0000 ) < ( V_25 & 0xffff0000 ) ) {
F_5 ( V_31 -> V_23 & 0xffff0000 ,
V_23 + F_9 ( V_24 ) ) ;
F_5 ( ( ( V_31 -> V_32 - 1 ) & 0xffff0000 ) |
( V_31 -> V_33 << 8 ) |
( V_27 -> V_34 << 4 ) | 1 ,
V_23 + F_8 ( V_24 ) ) ;
}
}
}
static int F_10 ( struct V_35 * V_36 )
{
int V_37 ;
struct V_38 * V_39 = V_36 -> V_39 ;
struct V_40 * V_41 = V_36 -> V_42 ;
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_45 * V_46 = V_41 -> V_46 ;
struct V_5 * V_6 ;
struct V_3 * V_4 = F_11 ( V_44 ) ;
unsigned long V_47 ;
V_6 = F_12 ( V_46 , V_36 ) ;
F_13 ( V_36 , & V_48 ) ;
V_37 = F_14 ( V_39 ,
V_49 ,
V_6 -> V_50 * 2 ,
V_51 - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_15 ( V_39 , 0 ,
V_49 ,
V_6 -> V_50 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_15 ( V_36 -> V_39 , 0 ,
V_52 ,
V_6 -> V_50 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_4 == NULL ) {
V_4 = F_16 ( sizeof( struct V_3 ) , V_53 ) ;
if ( V_4 == NULL )
return - V_54 ;
V_4 -> V_7 = V_6 ;
V_37 = F_17 ( V_6 -> V_1 , F_1 , V_55 ,
L_3 , V_4 ) ;
if ( V_37 ) {
F_18 ( V_4 ) ;
return - V_56 ;
}
F_19 ( V_44 , V_4 ) ;
F_5 ( ( unsigned long ) - 1 , V_6 -> V_11 + V_57 ) ;
}
V_47 = F_20 ( V_36 -> V_58 . V_59 ) ;
if ( V_36 -> V_60 == V_61 ) {
V_4 -> V_21 = V_36 ;
F_7 ( V_6 -> V_11 ,
V_62 , V_47 , V_6 -> V_27 ) ;
} else {
V_4 -> V_22 = V_36 ;
F_7 ( V_6 -> V_11 ,
V_63 , V_47 , V_6 -> V_27 ) ;
}
return 0 ;
}
static int F_21 ( struct V_35 * V_36 )
{
struct V_40 * V_41 = V_36 -> V_42 ;
struct V_45 * V_46 = V_41 -> V_46 ;
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_3 * V_4 = F_11 ( V_44 ) ;
struct V_5 * V_6 ;
V_6 = F_12 ( V_46 , V_36 ) ;
if ( ! V_4 || ! V_6 )
return 0 ;
if ( V_36 -> V_60 == V_61 )
V_4 -> V_21 = NULL ;
else
V_4 -> V_22 = NULL ;
if ( ! V_4 -> V_21 && ! V_4 -> V_22 ) {
F_5 ( 0 , V_6 -> V_11 + V_57 ) ;
F_22 ( V_6 -> V_1 , V_4 ) ;
F_18 ( V_4 ) ;
F_19 ( V_44 , NULL ) ;
}
return 0 ;
}
static int F_23 ( struct V_35 * V_36 ,
struct V_64 * V_65 )
{
struct V_38 * V_39 = V_36 -> V_39 ;
F_24 ( V_36 , & V_36 -> V_58 ) ;
V_39 -> V_66 = F_25 ( V_65 ) ;
return 0 ;
}
static int F_26 ( struct V_35 * V_36 )
{
F_24 ( V_36 , NULL ) ;
return 0 ;
}
static int F_27 ( struct V_35 * V_36 )
{
struct V_38 * V_39 = V_36 -> V_39 ;
struct V_40 * V_41 = V_36 -> V_42 ;
struct V_45 * V_46 = V_41 -> V_46 ;
struct V_5 * V_6 ;
unsigned long V_32 , V_67 ;
V_6 = F_12 ( V_46 , V_36 ) ;
V_32 = F_28 ( V_39 , V_39 -> V_68 ) ;
V_32 = ( V_32 >> 2 ) - 1 ;
V_67 = F_29 ( V_36 ) ;
if ( V_36 -> V_60 == V_61 ) {
F_5 ( V_67 , V_6 -> V_11 + V_69 ) ;
F_5 ( V_39 -> V_70 , V_6 -> V_11 + V_71 ) ;
F_5 ( V_32 , V_6 -> V_11 + V_72 ) ;
} else {
F_5 ( V_67 , V_6 -> V_11 + V_73 ) ;
F_5 ( V_39 -> V_70 , V_6 -> V_11 + V_74 ) ;
F_5 ( V_32 , V_6 -> V_11 + V_75 ) ;
}
return 0 ;
}
static T_3 F_30 ( struct V_35
* V_36 )
{
struct V_40 * V_41 = V_36 -> V_42 ;
struct V_45 * V_46 = V_41 -> V_46 ;
struct V_5 * V_6 ;
T_3 V_67 ;
V_6 = F_12 ( V_46 , V_36 ) ;
if ( V_36 -> V_60 == V_61 )
V_67 = F_31 ( V_36 -> V_39 ,
F_2 ( V_6 -> V_11 + V_76 ) ) ;
else
V_67 = F_31 ( V_36 -> V_39 ,
F_2 ( V_6 -> V_11 + V_77 ) ) ;
return V_67 ;
}
static int F_32 ( struct V_78 * V_79 ,
int V_60 )
{
struct V_35 * V_36 = V_79 -> V_80 [ V_60 ] . V_36 ;
struct V_81 * V_82 = & V_36 -> V_58 ;
T_4 V_32 = V_48 . V_83 ;
V_82 -> V_84 . type = V_85 ;
V_82 -> V_84 . V_84 = V_79 -> V_86 -> V_84 ;
V_82 -> V_59 = F_33 ( V_79 -> V_86 -> V_84 , V_32 ,
& V_82 -> V_47 , V_53 ) ;
if ( ! V_82 -> V_59 )
return - V_54 ;
V_82 -> V_87 = V_32 ;
V_82 -> V_42 = NULL ;
return 0 ;
}
static int F_34 ( struct V_88 * V_86 ,
struct V_45 * V_89 , struct V_78 * V_79 )
{
int V_90 ;
if ( ! V_86 -> V_84 -> V_91 )
V_86 -> V_84 -> V_91 = & V_92 ;
if ( ! V_86 -> V_84 -> V_93 )
V_86 -> V_84 -> V_93 = 0xffffffff ;
if ( V_89 -> V_94 -> V_95 . V_96 ) {
V_90 = F_32 ( V_79 ,
V_61 ) ;
if ( V_90 )
return V_90 ;
}
if ( V_89 -> V_94 -> V_97 . V_96 ) {
V_90 = F_32 ( V_79 ,
V_98 ) ;
if ( V_90 )
return V_90 ;
}
return 0 ;
}
static void F_35 ( struct V_78 * V_79 )
{
struct V_35 * V_36 ;
struct V_81 * V_82 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < 2 ; V_60 ++ ) {
V_36 = V_79 -> V_80 [ V_60 ] . V_36 ;
if ( ! V_36 )
continue;
V_82 = & V_36 -> V_58 ;
if ( ! V_82 -> V_59 )
continue;
F_36 ( V_79 -> V_86 -> V_84 , V_82 -> V_87 ,
V_82 -> V_59 , V_82 -> V_47 ) ;
V_82 -> V_59 = NULL ;
}
}
static int T_5 F_37 ( struct V_99 * V_100 )
{
return F_38 ( & V_100 -> V_84 , & V_101 ) ;
}
static int T_6 F_39 ( struct V_99 * V_100 )
{
F_40 ( & V_100 -> V_84 ) ;
return 0 ;
}
static int T_7 F_41 ( void )
{
return F_42 ( & V_102 ) ;
}
static void T_8 F_43 ( void )
{
F_44 ( & V_102 ) ;
}
