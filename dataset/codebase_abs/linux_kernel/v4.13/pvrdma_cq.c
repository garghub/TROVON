int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
T_1 V_10 = V_9 -> V_11 ;
unsigned long V_12 ;
int V_13 = 0 ;
V_10 |= ( V_4 & V_14 ) == V_15 ?
V_16 : V_17 ;
F_4 ( & V_9 -> V_18 , V_12 ) ;
F_5 ( V_6 , V_10 ) ;
if ( V_4 & V_19 ) {
unsigned int V_20 ;
V_13 = F_6 ( & V_9 -> V_21 -> V_22 ,
V_9 -> V_2 . V_23 , & V_20 ) ;
if ( F_7 ( V_13 == V_24 ) )
F_8 ( & V_6 -> V_25 -> V_6 , L_1 ) ;
}
F_9 ( & V_9 -> V_18 , V_12 ) ;
return V_13 ;
}
struct V_1 * F_10 ( struct V_26 * V_27 ,
const struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_32 * V_33 )
{
int V_34 = V_29 -> V_23 ;
struct V_5 * V_6 = F_2 ( V_27 ) ;
struct V_8 * V_9 ;
int V_35 ;
int V_36 ;
unsigned long V_12 ;
union V_37 V_38 ;
union V_39 V_40 ;
struct V_41 * V_42 = & V_38 . V_43 ;
struct V_44 * V_45 = & V_40 . V_46 ;
struct F_10 V_47 ;
F_11 ( sizeof( struct V_48 ) != 64 ) ;
V_34 = F_12 ( V_34 ) ;
if ( V_34 < 1 || V_34 > V_6 -> V_49 -> V_50 . V_51 )
return F_13 ( - V_52 ) ;
if ( ! F_14 ( & V_6 -> V_53 , 1 , V_6 -> V_49 -> V_50 . V_54 ) )
return F_13 ( - V_55 ) ;
V_9 = F_15 ( sizeof( * V_9 ) , V_56 ) ;
if ( ! V_9 ) {
F_16 ( & V_6 -> V_53 ) ;
return F_13 ( - V_55 ) ;
}
V_9 -> V_2 . V_23 = V_34 ;
if ( V_31 ) {
if ( F_17 ( & V_47 , V_33 , sizeof( V_47 ) ) ) {
V_35 = - V_57 ;
goto V_58;
}
V_9 -> V_59 = F_18 ( V_31 , V_47 . V_60 , V_47 . V_61 ,
V_62 , 1 ) ;
if ( F_19 ( V_9 -> V_59 ) ) {
V_35 = F_20 ( V_9 -> V_59 ) ;
goto V_58;
}
V_36 = F_21 ( V_9 -> V_59 ) ;
} else {
V_9 -> V_63 = true ;
V_36 = 1 + ( V_34 * sizeof( struct V_48 ) +
V_64 - 1 ) / V_64 ;
V_9 -> V_65 = V_64 ;
}
if ( V_36 < 0 || V_36 > V_66 ) {
F_22 ( & V_6 -> V_25 -> V_6 ,
L_2 ) ;
V_35 = - V_52 ;
goto V_67;
}
V_35 = F_23 ( V_6 , & V_9 -> V_68 , V_36 , V_9 -> V_63 ) ;
if ( V_35 ) {
F_22 ( & V_6 -> V_25 -> V_6 ,
L_3 ) ;
goto V_67;
}
if ( V_9 -> V_63 )
V_9 -> V_21 = V_9 -> V_68 . V_69 [ 0 ] ;
else
F_24 ( & V_9 -> V_68 , V_9 -> V_59 , 0 ) ;
F_25 ( & V_9 -> V_70 , 1 ) ;
F_26 ( & V_9 -> V_71 ) ;
F_27 ( & V_9 -> V_18 ) ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
V_42 -> V_72 . V_42 = V_73 ;
V_42 -> V_74 = V_36 ;
V_42 -> V_75 = ( V_31 ) ?
( V_76 ) F_28 ( V_31 ) -> V_75 : 0 ;
V_42 -> V_23 = V_34 ;
V_42 -> V_77 = V_9 -> V_68 . V_78 ;
V_35 = F_29 ( V_6 , & V_38 , & V_40 , V_79 ) ;
if ( V_35 < 0 ) {
F_22 ( & V_6 -> V_25 -> V_6 ,
L_4 , V_35 ) ;
goto V_80;
}
V_9 -> V_2 . V_23 = V_45 -> V_23 ;
V_9 -> V_11 = V_45 -> V_11 ;
F_4 ( & V_6 -> V_81 , V_12 ) ;
V_6 -> V_82 [ V_9 -> V_11 % V_6 -> V_49 -> V_50 . V_54 ] = V_9 ;
F_9 ( & V_6 -> V_81 , V_12 ) ;
if ( V_31 ) {
V_9 -> V_83 = & ( F_28 ( V_31 ) -> V_83 ) ;
if ( F_30 ( V_33 , & V_9 -> V_11 , sizeof( V_84 ) ) ) {
F_22 ( & V_6 -> V_25 -> V_6 ,
L_5 ) ;
F_31 ( & V_9 -> V_2 ) ;
return F_13 ( - V_52 ) ;
}
}
return & V_9 -> V_2 ;
V_80:
F_32 ( V_6 , & V_9 -> V_68 ) ;
V_67:
if ( V_31 )
F_33 ( V_9 -> V_59 ) ;
V_58:
F_16 ( & V_6 -> V_53 ) ;
F_34 ( V_9 ) ;
return F_13 ( V_35 ) ;
}
static void F_35 ( struct V_5 * V_6 , struct V_8 * V_9 )
{
F_16 ( & V_9 -> V_70 ) ;
F_36 ( V_9 -> V_71 , ! F_37 ( & V_9 -> V_70 ) ) ;
if ( ! V_9 -> V_63 )
F_33 ( V_9 -> V_59 ) ;
F_32 ( V_6 , & V_9 -> V_68 ) ;
F_34 ( V_9 ) ;
}
int F_31 ( struct V_1 * V_9 )
{
struct V_8 * V_85 = F_3 ( V_9 ) ;
union V_37 V_38 ;
struct V_86 * V_42 = & V_38 . V_87 ;
struct V_5 * V_6 = F_2 ( V_9 -> V_7 ) ;
unsigned long V_12 ;
int V_35 ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
V_42 -> V_72 . V_42 = V_88 ;
V_42 -> V_11 = V_85 -> V_11 ;
V_35 = F_29 ( V_6 , & V_38 , NULL , 0 ) ;
if ( V_35 < 0 )
F_22 ( & V_6 -> V_25 -> V_6 ,
L_6 ,
V_35 ) ;
F_4 ( & V_6 -> V_81 , V_12 ) ;
V_6 -> V_82 [ V_85 -> V_11 ] = NULL ;
F_9 ( & V_6 -> V_81 , V_12 ) ;
F_35 ( V_6 , V_85 ) ;
F_16 ( & V_6 -> V_53 ) ;
return V_35 ;
}
int F_38 ( struct V_1 * V_9 , T_2 V_89 , T_2 V_90 )
{
return - V_91 ;
}
static inline struct V_48 * F_39 ( struct V_8 * V_9 , int V_92 )
{
return (struct V_48 * ) F_40 (
& V_9 -> V_68 ,
V_9 -> V_65 +
sizeof( struct V_48 ) * V_92 ) ;
}
void F_41 ( struct V_93 * V_94 , struct V_8 * V_9 )
{
int V_20 ;
int V_13 ;
if ( ! V_9 -> V_63 )
return;
V_13 = F_6 ( & V_9 -> V_21 -> V_22 ,
V_9 -> V_2 . V_23 , & V_20 ) ;
if ( F_7 ( V_13 > 0 ) ) {
int V_95 ;
int V_96 ;
int V_97 = F_42 ( & V_9 -> V_21 -> V_22 . V_98 ,
V_9 -> V_2 . V_23 ) ;
struct V_48 * V_23 ;
struct V_48 * V_99 ;
V_95 = ( V_97 > V_20 ) ? ( V_97 - V_20 ) :
( V_9 -> V_2 . V_23 - V_20 + V_97 ) ;
V_96 = -- V_97 ;
while ( V_95 -- > 0 ) {
if ( V_96 < 0 )
V_96 = V_9 -> V_2 . V_23 - 1 ;
if ( V_97 < 0 )
V_97 = V_9 -> V_2 . V_23 - 1 ;
V_99 = F_39 ( V_9 , V_96 ) ;
if ( ( V_99 -> V_94 & 0xFFFF ) != V_94 -> V_100 ) {
if ( V_96 != V_97 ) {
V_23 = F_39 ( V_9 , V_97 ) ;
* V_23 = * V_99 ;
}
V_97 -- ;
} else {
F_43 (
& V_9 -> V_21 -> V_22 . V_101 ,
V_9 -> V_2 . V_23 ) ;
}
V_96 -- ;
}
}
}
static int F_44 ( struct V_8 * V_9 , struct V_93 * * V_102 ,
struct V_103 * V_104 )
{
struct V_5 * V_6 = F_2 ( V_9 -> V_2 . V_7 ) ;
int V_13 ;
unsigned int V_20 ;
bool V_105 = false ;
struct V_48 * V_23 ;
V_106:
V_13 = F_6 ( & V_9 -> V_21 -> V_22 ,
V_9 -> V_2 . V_23 , & V_20 ) ;
if ( V_13 == 0 ) {
if ( V_105 )
return - V_107 ;
F_5 ( V_6 , V_9 -> V_11 | V_108 ) ;
V_105 = true ;
goto V_106;
} else if ( V_13 == V_24 ) {
F_8 ( & V_6 -> V_25 -> V_6 , L_1 ) ;
return - V_107 ;
}
V_23 = F_39 ( V_9 , V_20 ) ;
F_45 () ;
if ( V_6 -> V_109 [ V_23 -> V_94 & 0xffff ] )
* V_102 = (struct V_93 * ) V_6 -> V_109 [ V_23 -> V_94 & 0xffff ] ;
else
return - V_107 ;
V_104 -> V_110 = F_46 ( V_23 -> V_110 ) ;
V_104 -> V_111 = F_47 ( V_23 -> V_111 ) ;
V_104 -> V_112 = V_23 -> V_112 ;
V_104 -> V_94 = & ( * V_102 ) -> V_113 ;
V_104 -> V_114 = V_23 -> V_114 ;
V_104 -> V_115 . V_116 = V_23 -> V_116 ;
V_104 -> V_117 = V_23 -> V_117 ;
V_104 -> V_118 = F_48 ( V_23 -> V_118 ) ;
V_104 -> V_119 = V_23 -> V_119 ;
V_104 -> V_120 = V_23 -> V_120 ;
V_104 -> V_121 = V_23 -> V_121 ;
V_104 -> V_122 = V_23 -> V_122 ;
V_104 -> V_123 = V_23 -> V_123 ;
V_104 -> V_124 = V_23 -> V_124 ;
F_43 ( & V_9 -> V_21 -> V_22 . V_101 , V_9 -> V_2 . V_23 ) ;
return 0 ;
}
int F_49 ( struct V_1 * V_2 , int V_125 , struct V_103 * V_104 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_93 * V_102 = NULL ;
unsigned long V_12 ;
int V_126 ;
if ( V_125 < 1 || V_104 == NULL )
return 0 ;
F_4 ( & V_9 -> V_18 , V_12 ) ;
for ( V_126 = 0 ; V_126 < V_125 ; ++ V_126 ) {
if ( F_44 ( V_9 , & V_102 , V_104 + V_126 ) )
break;
}
F_9 ( & V_9 -> V_18 , V_12 ) ;
return V_126 ;
}
int F_50 ( struct V_1 * V_2 , int V_34 , struct V_32 * V_33 )
{
return - V_91 ;
}
