int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
T_1 V_10 = V_9 -> V_11 ;
V_10 |= ( V_4 & V_12 ) == V_13 ?
V_14 : V_15 ;
F_4 ( V_6 , V_10 ) ;
return 0 ;
}
struct V_1 * F_5 ( struct V_16 * V_17 ,
const struct V_18 * V_19 ,
struct V_20 * V_21 ,
struct V_22 * V_23 )
{
int V_24 = V_19 -> V_25 ;
struct V_5 * V_6 = F_2 ( V_17 ) ;
struct V_8 * V_9 ;
int V_26 ;
int V_27 ;
unsigned long V_28 ;
union V_29 V_30 ;
union V_31 V_32 ;
struct V_33 * V_34 = & V_30 . V_35 ;
struct V_36 * V_37 = & V_32 . V_38 ;
struct F_5 V_39 ;
F_6 ( sizeof( struct V_40 ) != 64 ) ;
V_24 = F_7 ( V_24 ) ;
if ( V_24 < 1 || V_24 > V_6 -> V_41 -> V_42 . V_43 )
return F_8 ( - V_44 ) ;
if ( ! F_9 ( & V_6 -> V_45 , 1 , V_6 -> V_41 -> V_42 . V_46 ) )
return F_8 ( - V_47 ) ;
V_9 = F_10 ( sizeof( * V_9 ) , V_48 ) ;
if ( ! V_9 ) {
F_11 ( & V_6 -> V_45 ) ;
return F_8 ( - V_47 ) ;
}
V_9 -> V_2 . V_25 = V_24 ;
if ( V_21 ) {
if ( F_12 ( & V_39 , V_23 , sizeof( V_39 ) ) ) {
V_26 = - V_49 ;
goto V_50;
}
V_9 -> V_51 = F_13 ( V_21 , V_39 . V_52 , V_39 . V_53 ,
V_54 , 1 ) ;
if ( F_14 ( V_9 -> V_51 ) ) {
V_26 = F_15 ( V_9 -> V_51 ) ;
goto V_50;
}
V_27 = F_16 ( V_9 -> V_51 ) ;
} else {
V_9 -> V_55 = true ;
V_27 = 1 + ( V_24 * sizeof( struct V_40 ) +
V_56 - 1 ) / V_56 ;
V_9 -> V_57 = V_56 ;
}
if ( V_27 < 0 || V_27 > V_58 ) {
F_17 ( & V_6 -> V_59 -> V_6 ,
L_1 ) ;
V_26 = - V_44 ;
goto V_60;
}
V_26 = F_18 ( V_6 , & V_9 -> V_61 , V_27 , V_9 -> V_55 ) ;
if ( V_26 ) {
F_17 ( & V_6 -> V_59 -> V_6 ,
L_2 ) ;
goto V_60;
}
if ( V_9 -> V_55 )
V_9 -> V_62 = V_9 -> V_61 . V_63 [ 0 ] ;
else
F_19 ( & V_9 -> V_61 , V_9 -> V_51 , 0 ) ;
F_20 ( & V_9 -> V_64 , 1 ) ;
F_21 ( & V_9 -> V_65 ) ;
F_22 ( & V_9 -> V_66 ) ;
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
V_34 -> V_67 . V_34 = V_68 ;
V_34 -> V_69 = V_27 ;
V_34 -> V_70 = ( V_21 ) ?
( V_71 ) F_23 ( V_21 ) -> V_70 : 0 ;
V_34 -> V_25 = V_24 ;
V_34 -> V_72 = V_9 -> V_61 . V_73 ;
V_26 = F_24 ( V_6 , & V_30 , & V_32 , V_74 ) ;
if ( V_26 < 0 ) {
F_17 ( & V_6 -> V_59 -> V_6 ,
L_3 , V_26 ) ;
goto V_75;
}
V_9 -> V_2 . V_25 = V_37 -> V_25 ;
V_9 -> V_11 = V_37 -> V_11 ;
F_25 ( & V_6 -> V_76 , V_28 ) ;
V_6 -> V_77 [ V_9 -> V_11 % V_6 -> V_41 -> V_42 . V_46 ] = V_9 ;
F_26 ( & V_6 -> V_76 , V_28 ) ;
if ( V_21 ) {
V_9 -> V_78 = & ( F_23 ( V_21 ) -> V_78 ) ;
if ( F_27 ( V_23 , & V_9 -> V_11 , sizeof( V_79 ) ) ) {
F_17 ( & V_6 -> V_59 -> V_6 ,
L_4 ) ;
F_28 ( & V_9 -> V_2 ) ;
return F_8 ( - V_44 ) ;
}
}
return & V_9 -> V_2 ;
V_75:
F_29 ( V_6 , & V_9 -> V_61 ) ;
V_60:
if ( V_21 )
F_30 ( V_9 -> V_51 ) ;
V_50:
F_11 ( & V_6 -> V_45 ) ;
F_31 ( V_9 ) ;
return F_8 ( V_26 ) ;
}
static void F_32 ( struct V_5 * V_6 , struct V_8 * V_9 )
{
F_11 ( & V_9 -> V_64 ) ;
F_33 ( V_9 -> V_65 , ! F_34 ( & V_9 -> V_64 ) ) ;
if ( ! V_9 -> V_55 )
F_30 ( V_9 -> V_51 ) ;
F_29 ( V_6 , & V_9 -> V_61 ) ;
F_31 ( V_9 ) ;
}
int F_28 ( struct V_1 * V_9 )
{
struct V_8 * V_80 = F_3 ( V_9 ) ;
union V_29 V_30 ;
struct V_81 * V_34 = & V_30 . V_82 ;
struct V_5 * V_6 = F_2 ( V_9 -> V_7 ) ;
unsigned long V_28 ;
int V_26 ;
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
V_34 -> V_67 . V_34 = V_83 ;
V_34 -> V_11 = V_80 -> V_11 ;
V_26 = F_24 ( V_6 , & V_30 , NULL , 0 ) ;
if ( V_26 < 0 )
F_17 ( & V_6 -> V_59 -> V_6 ,
L_5 ,
V_26 ) ;
F_25 ( & V_6 -> V_76 , V_28 ) ;
V_6 -> V_77 [ V_80 -> V_11 ] = NULL ;
F_26 ( & V_6 -> V_76 , V_28 ) ;
F_32 ( V_6 , V_80 ) ;
F_11 ( & V_6 -> V_45 ) ;
return V_26 ;
}
int F_35 ( struct V_1 * V_9 , T_2 V_84 , T_2 V_85 )
{
return - V_86 ;
}
static inline struct V_40 * F_36 ( struct V_8 * V_9 , int V_87 )
{
return (struct V_40 * ) F_37 (
& V_9 -> V_61 ,
V_9 -> V_57 +
sizeof( struct V_40 ) * V_87 ) ;
}
void F_38 ( struct V_88 * V_89 , struct V_8 * V_9 )
{
int V_90 ;
int V_91 ;
if ( ! V_9 -> V_55 )
return;
V_91 = F_39 ( & V_9 -> V_62 -> V_92 ,
V_9 -> V_2 . V_25 , & V_90 ) ;
if ( F_40 ( V_91 > 0 ) ) {
int V_93 ;
int V_94 ;
int V_95 = F_41 ( & V_9 -> V_62 -> V_92 . V_96 ,
V_9 -> V_2 . V_25 ) ;
struct V_40 * V_25 ;
struct V_40 * V_97 ;
V_93 = ( V_95 > V_90 ) ? ( V_95 - V_90 ) :
( V_9 -> V_2 . V_25 - V_90 + V_95 ) ;
V_94 = -- V_95 ;
while ( V_93 -- > 0 ) {
if ( V_94 < 0 )
V_94 = V_9 -> V_2 . V_25 - 1 ;
if ( V_95 < 0 )
V_95 = V_9 -> V_2 . V_25 - 1 ;
V_97 = F_36 ( V_9 , V_94 ) ;
if ( ( V_97 -> V_89 & 0xFFFF ) != V_89 -> V_98 ) {
if ( V_94 != V_95 ) {
V_25 = F_36 ( V_9 , V_95 ) ;
* V_25 = * V_97 ;
}
V_95 -- ;
} else {
F_42 (
& V_9 -> V_62 -> V_92 . V_99 ,
V_9 -> V_2 . V_25 ) ;
}
V_94 -- ;
}
}
}
static int F_43 ( struct V_8 * V_9 , struct V_88 * * V_100 ,
struct V_101 * V_102 )
{
struct V_5 * V_6 = F_2 ( V_9 -> V_2 . V_7 ) ;
int V_91 ;
unsigned int V_90 ;
bool V_103 = false ;
struct V_40 * V_25 ;
V_104:
V_91 = F_39 ( & V_9 -> V_62 -> V_92 ,
V_9 -> V_2 . V_25 , & V_90 ) ;
if ( V_91 == 0 ) {
if ( V_103 )
return - V_105 ;
F_4 ( V_6 , V_9 -> V_11 | V_106 ) ;
V_103 = true ;
goto V_104;
} else if ( V_91 == V_107 ) {
F_44 ( & V_6 -> V_59 -> V_6 , L_6 ) ;
return - V_105 ;
}
V_25 = F_36 ( V_9 , V_90 ) ;
F_45 () ;
if ( V_6 -> V_108 [ V_25 -> V_89 & 0xffff ] )
* V_100 = (struct V_88 * ) V_6 -> V_108 [ V_25 -> V_89 & 0xffff ] ;
else
return - V_105 ;
V_102 -> V_109 = F_46 ( V_25 -> V_109 ) ;
V_102 -> V_110 = F_47 ( V_25 -> V_110 ) ;
V_102 -> V_111 = V_25 -> V_111 ;
V_102 -> V_89 = & ( * V_100 ) -> V_112 ;
V_102 -> V_113 = V_25 -> V_113 ;
V_102 -> V_114 . V_115 = V_25 -> V_115 ;
V_102 -> V_116 = V_25 -> V_116 ;
V_102 -> V_117 = F_48 ( V_25 -> V_117 ) ;
V_102 -> V_118 = V_25 -> V_118 ;
V_102 -> V_119 = V_25 -> V_119 ;
V_102 -> V_120 = V_25 -> V_120 ;
V_102 -> V_121 = V_25 -> V_121 ;
V_102 -> V_122 = V_25 -> V_122 ;
V_102 -> V_123 = 0 ;
F_42 ( & V_9 -> V_62 -> V_92 . V_99 , V_9 -> V_2 . V_25 ) ;
return 0 ;
}
int F_49 ( struct V_1 * V_2 , int V_124 , struct V_101 * V_102 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_88 * V_100 = NULL ;
unsigned long V_28 ;
int V_125 ;
if ( V_124 < 1 || V_102 == NULL )
return 0 ;
F_25 ( & V_9 -> V_66 , V_28 ) ;
for ( V_125 = 0 ; V_125 < V_124 ; ++ V_125 ) {
if ( F_43 ( V_9 , & V_100 , V_102 + V_125 ) )
break;
}
F_26 ( & V_9 -> V_66 , V_28 ) ;
return V_125 ;
}
int F_50 ( struct V_1 * V_2 , int V_24 , struct V_22 * V_23 )
{
return - V_86 ;
}
