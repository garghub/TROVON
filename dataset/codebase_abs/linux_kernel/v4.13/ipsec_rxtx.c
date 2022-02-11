static inline T_1 F_1 ( struct V_1 * V_2 )
{
return V_3 [ F_2 ( V_2 ) -> V_4 ] ;
}
static struct V_5 * F_3 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
if ( F_4 ( F_5 ( V_2 , sizeof( * V_6 ) ) ) )
return F_6 ( - V_9 ) ;
V_8 = (struct V_7 * ) F_7 ( V_2 , sizeof( * V_6 ) ) ;
V_2 -> V_10 -= sizeof( * V_6 ) ;
V_6 = (struct V_5 * ) ( V_8 + 1 ) ;
memmove ( V_2 -> V_11 , V_2 -> V_11 + sizeof( * V_6 ) ,
2 * V_12 ) ;
V_8 -> V_13 = F_8 ( V_14 ) ;
memset ( V_6 -> V_15 . V_16 , 0 , sizeof( V_6 -> V_15 . V_16 ) ) ;
return V_6 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
unsigned int V_19 = F_10 ( V_18 -> V_11 ) ;
struct V_20 * V_20 = F_11 ( V_2 ) ;
struct V_21 * V_22 = F_12 ( V_2 ) ;
unsigned int V_23 ;
T_2 V_24 ;
int V_25 ;
V_25 = F_13 ( V_2 , V_2 -> V_26 - V_19 - 2 , & V_24 , 1 ) ;
if ( F_4 ( V_25 ) )
return V_25 ;
V_23 = V_19 + V_24 + 2 ;
F_14 ( V_2 , V_2 -> V_26 - V_23 ) ;
if ( V_2 -> V_27 == F_15 ( V_28 ) ) {
V_22 -> V_29 = F_15 ( F_16 ( V_22 -> V_29 ) - V_23 ) ;
F_17 ( V_22 ) ;
} else {
V_20 -> V_30 = F_15 ( F_16 ( V_20 -> V_30 ) -
V_23 ) ;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_31 * V_32 , T_2 V_33 ,
struct V_34 * V_35 )
{
T_2 V_36 ;
V_32 -> V_37 = F_19 ( V_2 ) / 2 ;
if ( V_2 -> V_27 == F_15 ( V_38 ) )
V_32 -> V_39 |= V_40 ;
if ( V_33 == V_41 ) {
V_32 -> V_42 = F_20 ( V_2 ) / 2 ;
if ( V_35 -> V_36 == V_43 ) {
V_32 -> V_39 |= V_44 ;
V_36 = F_21 ( V_2 ) -> V_45 ;
} else {
V_36 = F_22 ( V_2 ) -> V_27 ;
}
} else {
V_32 -> V_42 = F_19 ( V_2 ) / 2 ;
if ( V_2 -> V_27 == F_15 ( V_38 ) )
V_32 -> V_39 |= V_44 ;
V_36 = V_35 -> V_36 ;
}
switch ( V_36 ) {
case V_46 :
V_32 -> V_39 |= V_47 ;
case V_48 :
V_32 -> V_49 = F_23 ( V_2 ) / 2 ;
break;
}
}
static void F_24 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
int V_50 ;
T_3 V_51 ;
V_51 = F_25 ( V_35 -> V_52 . V_53 + ( ( V_54 ) V_35 -> V_52 . V_55 << 32 ) ) ;
V_50 = F_26 ( V_2 ) + sizeof( struct V_56 ) ;
F_27 ( V_2 , V_50 , & V_51 , 8 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_34 * V_35 )
{
struct V_56 * V_57 ;
struct V_58 * V_59 ;
if ( F_29 ( V_2 ) ) {
V_57 = V_56 ( V_2 ) ;
V_59 = F_30 ( V_2 ) ;
F_31 ( V_2 -> V_60 , L_1 ,
V_2 -> V_61 ,
V_2 -> V_62 ,
V_2 -> V_63 ,
V_2 -> V_64 ) ;
F_31 ( V_2 -> V_60 , L_2 ,
V_2 -> V_26 , F_2 ( V_2 ) -> V_4 ,
F_16 ( V_59 -> V_65 ) , F_16 ( V_59 -> V_66 ) ,
F_32 ( V_59 -> V_52 ) , F_32 ( V_57 -> V_67 ) ) ;
V_6 -> V_68 = V_69 ;
V_6 -> V_15 . V_70 . V_71 = F_1 ( V_2 ) ;
V_6 -> V_15 . V_70 . V_52 = F_15 ( F_32 ( V_59 -> V_52 ) & 0xFFFF ) ;
} else {
V_6 -> V_68 = V_72 ;
}
V_6 -> V_15 . V_70 . V_73 = V_35 -> V_36 ;
F_31 ( V_2 -> V_60 , L_3 ,
V_6 -> V_68 , V_6 -> V_15 . V_70 . V_73 ,
F_16 ( V_6 -> V_15 . V_70 . V_71 ) ,
F_16 ( V_6 -> V_15 . V_70 . V_52 ) ) ;
}
struct V_1 * F_33 ( struct V_74 * V_75 ,
struct V_76 * V_77 ,
struct V_1 * V_2 )
{
struct V_78 * V_79 = F_34 ( V_75 ) ;
struct V_34 * V_35 = V_34 ( V_2 ) ;
struct V_5 * V_6 ;
struct V_17 * V_18 ;
if ( ! V_35 )
return V_2 ;
if ( F_4 ( V_2 -> V_80 -> V_26 != 1 ) ) {
F_35 ( & V_79 -> V_81 -> V_82 . V_83 ) ;
goto V_84;
}
V_18 = F_36 ( V_2 ) ;
if ( F_4 ( ! V_18 ) ) {
F_35 ( & V_79 -> V_81 -> V_82 . V_85 ) ;
goto V_84;
}
if ( F_4 ( ! V_18 -> V_86 . V_87 ||
( V_2 -> V_27 != F_15 ( V_28 ) &&
V_2 -> V_27 != F_15 ( V_38 ) ) ) ) {
F_35 ( & V_79 -> V_81 -> V_82 . V_88 ) ;
goto V_84;
}
if ( ! F_29 ( V_2 ) )
if ( F_4 ( F_9 ( V_2 , V_18 ) ) ) {
F_35 ( & V_79 -> V_81 -> V_82 . V_89 ) ;
goto V_84;
}
V_6 = F_3 ( V_2 ) ;
if ( F_4 ( F_37 ( V_6 ) ) ) {
F_35 ( & V_79 -> V_81 -> V_82 . V_90 ) ;
goto V_84;
}
F_18 ( V_2 , & V_77 -> V_8 , V_18 -> V_91 . V_33 , V_35 ) ;
F_24 ( V_2 , V_35 ) ;
F_28 ( V_2 , V_6 , V_35 ) ;
return V_2 ;
V_84:
F_38 ( V_2 ) ;
return NULL ;
}
static inline struct V_17 *
F_39 ( struct V_74 * V_75 , struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_78 * V_79 = F_34 ( V_75 ) ;
struct V_34 * V_35 ;
struct V_17 * V_92 ;
T_4 V_93 ;
V_2 -> V_80 = F_40 ( V_2 -> V_80 ) ;
if ( F_4 ( ! V_2 -> V_80 ) ) {
F_35 ( & V_79 -> V_81 -> V_82 . V_94 ) ;
return NULL ;
}
V_93 = F_41 ( V_6 -> V_15 . V_95 . V_93 ) ;
V_92 = F_42 ( V_79 -> V_81 , V_93 ) ;
if ( F_4 ( ! V_92 ) ) {
F_35 ( & V_79 -> V_81 -> V_82 . V_96 ) ;
return NULL ;
}
V_2 -> V_80 -> V_97 [ V_2 -> V_80 -> V_26 ++ ] = V_92 ;
V_2 -> V_80 -> V_98 ++ ;
V_35 = V_34 ( V_2 ) ;
V_35 -> V_99 = V_100 ;
switch ( V_6 -> V_68 ) {
case V_101 :
V_35 -> V_102 = V_103 ;
break;
case V_104 :
V_35 -> V_102 = V_105 ;
break;
default:
F_35 ( & V_79 -> V_81 -> V_82 . V_106 ) ;
return NULL ;
}
return V_92 ;
}
struct V_1 * F_43 ( struct V_74 * V_75 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_7 * V_107 ;
struct V_7 * V_108 ;
struct V_17 * V_92 ;
T_1 * V_109 ;
if ( V_2 -> V_26 < V_110 + V_111 )
return V_2 ;
V_109 = ( T_1 * ) ( V_2 -> V_11 + V_12 * 2 ) ;
if ( * V_109 != F_8 ( V_14 ) )
return V_2 ;
V_6 = (struct V_5 * ) ( V_2 -> V_11 + V_110 ) ;
V_92 = F_39 ( V_75 , V_2 , V_6 ) ;
if ( F_4 ( ! V_92 ) ) {
F_38 ( V_2 ) ;
return NULL ;
}
V_107 = (struct V_7 * ) V_2 -> V_11 ;
V_108 = (struct V_7 * ) ( V_2 -> V_11 + V_111 ) ;
memmove ( V_108 , V_107 , 2 * V_12 ) ;
F_44 ( V_2 , V_111 ) ;
return V_2 ;
}
bool F_45 ( struct V_1 * V_2 , struct V_74 * V_75 ,
T_5 V_112 )
{
struct V_17 * V_18 ;
if ( V_2 -> V_80 && V_2 -> V_80 -> V_26 ) {
V_18 = V_2 -> V_80 -> V_97 [ 0 ] ;
if ( V_18 && V_18 -> V_86 . V_87 )
return true ;
}
return false ;
}
void F_46 ( void )
{
T_6 V_71 ;
T_4 V_113 ;
V_3 [ 1 ] = F_15 ( 0xFFFF ) ;
for ( V_113 = 2 ; V_113 < V_114 ; V_113 ++ ) {
V_71 = F_47 ( 1ULL << 32 , V_113 ) >> 16 ;
V_3 [ V_113 ] = F_15 ( V_71 ) ;
}
}
