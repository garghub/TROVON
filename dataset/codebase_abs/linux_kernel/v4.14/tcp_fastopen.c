void F_1 ( bool V_1 )
{
static T_1 V_2 [ V_3 ] ;
if ( F_2 ( V_2 , sizeof( V_2 ) ) && V_1 )
F_3 ( V_2 , sizeof( V_2 ) ) ;
}
static void F_4 ( struct V_4 * V_5 )
{
struct V_6 * V_7 =
F_5 ( V_5 , struct V_6 , V_8 ) ;
F_6 ( V_7 -> V_9 ) ;
F_7 ( V_7 ) ;
}
int F_3 ( void * V_2 , unsigned int V_10 )
{
int V_11 ;
struct V_6 * V_7 , * V_12 ;
V_7 = F_8 ( sizeof( * V_7 ) , V_13 ) ;
if ( ! V_7 )
return - V_14 ;
V_7 -> V_9 = F_9 ( L_1 , 0 , 0 ) ;
if ( F_10 ( V_7 -> V_9 ) ) {
V_11 = F_11 ( V_7 -> V_9 ) ;
error: F_7 ( V_7 ) ;
F_12 ( L_2 , V_11 ) ;
return V_11 ;
}
V_11 = F_13 ( V_7 -> V_9 , V_2 , V_10 ) ;
if ( V_11 ) {
F_12 ( L_3 , V_11 ) ;
F_6 ( V_7 -> V_9 ) ;
goto error;
}
memcpy ( V_7 -> V_2 , V_2 , V_10 ) ;
F_14 ( & V_15 ) ;
V_12 = F_15 ( V_16 ,
F_16 ( & V_15 ) ) ;
F_17 ( V_16 , V_7 ) ;
F_18 ( & V_15 ) ;
if ( V_12 )
F_19 ( & V_12 -> V_8 , F_4 ) ;
return V_11 ;
}
static bool F_20 ( const void * V_17 ,
struct V_18 * V_19 )
{
struct V_6 * V_7 ;
bool V_20 = false ;
F_21 () ;
V_7 = F_22 ( V_16 ) ;
if ( V_7 ) {
F_23 ( V_7 -> V_9 , V_19 -> V_21 , V_17 ) ;
V_19 -> V_10 = V_22 ;
V_20 = true ;
}
F_24 () ;
return V_20 ;
}
static bool F_25 ( struct V_23 * V_24 ,
struct V_25 * V_26 ,
struct V_18 * V_19 )
{
if ( V_24 -> V_27 -> V_28 == V_29 ) {
const struct V_30 * V_31 = F_26 ( V_26 ) ;
T_2 V_17 [ 4 ] = { V_31 -> V_32 , V_31 -> V_33 , 0 , 0 } ;
return F_20 ( V_17 , V_19 ) ;
}
#if F_27 ( V_34 )
if ( V_24 -> V_27 -> V_28 == V_35 ) {
const struct V_36 * V_37 = F_28 ( V_26 ) ;
struct V_18 V_38 ;
if ( F_20 ( & V_37 -> V_32 , & V_38 ) ) {
struct V_39 * V_40 = & V_38 . V_41 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < 4 ; V_42 ++ )
V_40 -> V_43 [ V_42 ] ^= V_37 -> V_33 . V_43 [ V_42 ] ;
return F_20 ( V_40 , V_19 ) ;
}
}
#endif
return false ;
}
void F_29 ( struct V_44 * V_45 , struct V_25 * V_46 )
{
struct V_47 * V_48 = F_30 ( V_45 ) ;
if ( F_31 ( V_46 ) -> V_49 == V_48 -> V_50 )
return;
V_46 = F_32 ( V_46 , V_51 ) ;
if ( ! V_46 )
return;
F_33 ( V_46 ) ;
V_48 -> V_52 = 0 ;
F_34 ( V_48 , V_46 ) ;
F_35 ( V_46 , F_36 ( V_46 ) ) ;
F_37 ( V_45 , V_46 -> V_53 ) ;
F_38 ( V_46 , V_45 ) ;
F_31 ( V_46 ) -> V_54 ++ ;
F_31 ( V_46 ) -> V_55 &= ~ V_56 ;
V_48 -> V_50 = F_31 ( V_46 ) -> V_49 ;
F_39 ( & V_45 -> V_57 , V_46 ) ;
V_48 -> V_58 = 1 ;
V_48 -> V_59 = V_46 -> V_10 ;
if ( F_31 ( V_46 ) -> V_55 & V_60 )
F_40 ( V_45 ) ;
}
static struct V_44 * F_41 ( struct V_44 * V_45 ,
struct V_25 * V_46 ,
struct V_23 * V_24 )
{
struct V_47 * V_48 ;
struct V_61 * V_62 = & F_42 ( V_45 ) -> V_63 ;
struct V_44 * V_64 ;
bool V_65 ;
V_24 -> V_66 = 0 ;
V_24 -> V_67 = 0 ;
V_24 -> V_45 = NULL ;
V_64 = F_42 ( V_45 ) -> V_68 -> V_69 ( V_45 , V_46 , V_24 , NULL ,
NULL , & V_65 ) ;
if ( ! V_64 )
return NULL ;
F_14 ( & V_62 -> V_70 . V_71 ) ;
V_62 -> V_70 . V_72 ++ ;
F_18 ( & V_62 -> V_70 . V_71 ) ;
V_48 = F_30 ( V_64 ) ;
V_48 -> V_73 = V_24 ;
F_43 ( V_24 ) -> V_74 = true ;
V_48 -> V_75 = F_44 ( F_45 ( V_46 ) -> V_76 ) ;
V_48 -> V_77 = V_48 -> V_75 ;
F_46 ( V_64 , V_78 ,
V_79 , V_80 ) ;
F_47 ( & V_24 -> V_81 , 2 ) ;
F_42 ( V_64 ) -> V_68 -> V_82 ( V_64 ) ;
F_48 ( V_64 ) ;
F_49 ( V_64 ) ;
F_50 ( V_64 ) ;
F_51 ( V_64 , V_83 ) ;
F_52 ( V_64 ) ;
V_48 -> V_50 = F_31 ( V_46 ) -> V_54 + 1 ;
F_29 ( V_64 , V_46 ) ;
F_43 ( V_24 ) -> V_50 = V_48 -> V_50 ;
V_48 -> V_84 = V_48 -> V_50 ;
return V_64 ;
}
static bool F_53 ( struct V_44 * V_45 )
{
struct V_85 * V_70 ;
V_70 = & F_42 ( V_45 ) -> V_63 . V_70 ;
if ( V_70 -> V_86 == 0 )
return false ;
if ( V_70 -> V_72 >= V_70 -> V_86 ) {
struct V_23 * V_87 ;
F_14 ( & V_70 -> V_71 ) ;
V_87 = V_70 -> V_88 ;
if ( ! V_87 || F_54 ( V_87 -> V_89 . V_90 , V_91 ) ) {
F_55 ( F_56 ( V_45 ) ,
V_92 ) ;
F_18 ( & V_70 -> V_71 ) ;
return false ;
}
V_70 -> V_88 = V_87 -> V_93 ;
V_70 -> V_72 -- ;
F_18 ( & V_70 -> V_71 ) ;
F_57 ( V_87 ) ;
}
return true ;
}
struct V_44 * F_58 ( struct V_44 * V_45 , struct V_25 * V_46 ,
struct V_23 * V_24 ,
struct V_18 * V_19 )
{
struct V_18 V_94 = { . V_10 = - 1 } ;
bool V_95 = F_31 ( V_46 ) -> V_49 != F_31 ( V_46 ) -> V_54 + 1 ;
struct V_44 * V_64 ;
if ( V_19 -> V_10 == 0 )
F_59 ( F_56 ( V_45 ) , V_96 ) ;
if ( ! ( ( V_97 & V_98 ) &&
( V_95 || V_19 -> V_10 >= 0 ) &&
F_53 ( V_45 ) ) ) {
V_19 -> V_10 = - 1 ;
return NULL ;
}
if ( V_95 && ( V_97 & V_99 ) )
goto V_100;
if ( V_19 -> V_10 >= 0 &&
F_25 ( V_24 , V_46 , & V_94 ) &&
V_19 -> V_10 == V_22 &&
V_19 -> V_10 == V_94 . V_10 &&
! memcmp ( V_19 -> V_21 , V_94 . V_21 , V_19 -> V_10 ) ) {
V_100:
V_64 = F_41 ( V_45 , V_46 , V_24 ) ;
if ( V_64 ) {
V_19 -> V_10 = - 1 ;
F_59 ( F_56 ( V_45 ) ,
V_101 ) ;
return V_64 ;
}
F_59 ( F_56 ( V_45 ) , V_102 ) ;
} else if ( V_19 -> V_10 > 0 )
F_59 ( F_56 ( V_45 ) , V_102 ) ;
V_94 . exp = V_19 -> exp ;
* V_19 = V_94 ;
return NULL ;
}
bool F_60 ( struct V_44 * V_45 , T_3 * V_103 ,
struct V_18 * V_104 )
{
unsigned long V_105 = 0 ;
int V_106 = 0 ;
F_61 ( V_45 , V_103 , V_104 , & V_106 , & V_105 ) ;
if ( V_106 > 1 &&
F_62 ( V_91 , V_105 + ( 60 * V_107 << V_106 ) ) ) {
V_104 -> V_10 = - 1 ;
return false ;
}
if ( F_63 ( V_45 ) ) {
V_104 -> V_10 = - 1 ;
return false ;
}
if ( V_97 & V_108 ) {
V_104 -> V_10 = - 1 ;
return true ;
}
return V_104 -> V_10 > 0 ;
}
bool F_64 ( struct V_44 * V_45 , int * V_11 )
{
struct V_18 V_104 = { . V_10 = 0 } ;
struct V_47 * V_48 = F_30 ( V_45 ) ;
T_3 V_103 ;
if ( V_48 -> V_109 && ! V_48 -> V_110 ) {
if ( F_60 ( V_45 , & V_103 , & V_104 ) ) {
F_65 ( V_45 ) -> V_111 = 1 ;
return true ;
}
V_48 -> V_110 = F_66 ( sizeof( * V_48 -> V_110 ) ,
V_45 -> V_112 ) ;
if ( V_48 -> V_110 )
V_48 -> V_110 -> V_104 = V_104 ;
else
* V_11 = - V_113 ;
}
return false ;
}
void F_67 ( struct V_44 * V_45 )
{
F_68 ( & V_114 ) ;
V_115 = V_91 ;
F_59 ( F_56 ( V_45 ) , V_116 ) ;
}
void F_69 ( void )
{
F_70 ( & V_114 , 0 ) ;
}
bool F_63 ( struct V_44 * V_45 )
{
int V_117 = F_71 ( & V_114 ) ;
int V_118 ;
unsigned long V_119 ;
if ( ! V_117 )
return false ;
V_118 = 1 << F_72 ( V_117 - 1 , 6 ) ;
V_119 = V_118 * V_120 * V_107 ;
if ( F_62 ( V_91 , V_115 + V_119 ) )
return true ;
F_30 ( V_45 ) -> V_121 = 1 ;
return false ;
}
void F_73 ( struct V_44 * V_45 )
{
struct V_47 * V_48 = F_30 ( V_45 ) ;
struct V_122 * V_123 ;
struct V_25 * V_46 ;
struct V_124 * V_125 ;
if ( ! V_48 -> V_126 )
return;
if ( ! V_48 -> V_127 ) {
V_123 = F_74 ( & V_48 -> V_128 ) ;
if ( V_123 && ! F_75 ( V_123 ) ) {
V_46 = F_76 ( V_123 , struct V_25 , V_129 ) ;
if ( F_31 ( V_46 ) -> V_55 & V_60 ) {
F_67 ( V_45 ) ;
return;
}
}
} else if ( V_48 -> V_121 &&
F_71 ( & V_114 ) ) {
V_125 = F_77 ( V_45 ) ;
if ( ! ( V_125 && V_125 -> V_130 && ( V_125 -> V_130 -> V_131 & V_132 ) ) )
F_69 () ;
F_78 ( V_125 ) ;
}
}
