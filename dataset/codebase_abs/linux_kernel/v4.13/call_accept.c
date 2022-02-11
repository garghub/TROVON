static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 ,
T_2 V_6 ,
unsigned long V_7 , T_3 V_8 )
{
const void * V_9 = F_2 ( 0 ) ;
struct V_10 * V_11 ;
struct V_12 * V_13 = V_12 ( F_3 ( & V_2 -> V_14 ) ) ;
int V_15 , V_16 ;
unsigned int V_17 = V_18 ;
unsigned int V_19 , V_20 , V_21 , V_22 ;
V_15 = V_2 -> V_14 . V_23 ;
V_16 = V_2 -> V_14 . V_24 ;
if ( V_16 >= V_15 ) {
F_4 ( L_1 , V_15 ) ;
return - V_25 ;
}
V_15 -= V_16 ;
V_21 = V_4 -> V_26 ;
V_22 = F_5 ( V_4 -> V_27 ) ;
V_16 = F_6 ( V_21 , V_22 , V_17 ) ;
if ( V_16 >= V_15 ) {
F_4 ( L_2 , V_16 ) ;
return - V_25 ;
}
V_15 = V_16 + 1 ;
V_19 = V_4 -> V_28 ;
V_20 = F_5 ( V_4 -> V_29 ) ;
if ( F_6 ( V_19 , V_20 , V_17 ) < V_15 ) {
struct V_30 * V_31 = F_7 ( V_2 -> V_32 , V_8 ) ;
if ( ! V_31 )
return - V_33 ;
V_4 -> V_34 [ V_19 ] = V_31 ;
F_8 ( & V_4 -> V_28 ,
( V_19 + 1 ) & ( V_17 - 1 ) ) ;
}
V_19 = V_4 -> V_35 ;
V_20 = F_5 ( V_4 -> V_36 ) ;
if ( F_6 ( V_19 , V_20 , V_17 ) < V_15 ) {
struct V_37 * V_38 ;
V_38 = F_9 ( V_13 , V_8 ) ;
if ( ! V_38 )
return - V_33 ;
V_4 -> V_39 [ V_19 ] = V_38 ;
F_8 ( & V_4 -> V_35 ,
( V_19 + 1 ) & ( V_17 - 1 ) ) ;
F_10 ( V_38 , V_40 ,
F_11 ( & V_38 -> V_41 ) , V_9 ) ;
}
V_11 = F_12 ( V_8 ) ;
if ( ! V_11 )
return - V_33 ;
V_11 -> V_42 |= ( 1 << V_43 ) ;
V_11 -> V_44 = V_45 ;
F_13 ( V_11 , V_46 ,
F_11 ( & V_11 -> V_41 ) ,
V_9 , ( const void * ) V_7 ) ;
F_14 ( & V_2 -> V_47 ) ;
if ( V_6 ) {
struct V_10 * V_48 ;
struct V_49 * V_50 , * * V_51 ;
V_51 = & V_2 -> V_52 . V_49 ;
V_50 = NULL ;
while ( * V_51 ) {
V_50 = * V_51 ;
V_48 = F_15 ( V_50 , struct V_10 , V_53 ) ;
if ( V_7 < V_11 -> V_7 )
V_51 = & ( * V_51 ) -> V_54 ;
else if ( V_7 > V_11 -> V_7 )
V_51 = & ( * V_51 ) -> V_55 ;
else
goto V_56;
}
V_11 -> V_7 = V_7 ;
V_11 -> V_5 = V_5 ;
F_16 ( V_11 , V_57 ) ;
V_6 ( V_11 , V_7 ) ;
F_16 ( V_11 , V_58 ) ;
F_17 ( & V_11 -> V_53 , V_50 , V_51 ) ;
F_18 ( & V_11 -> V_53 , & V_2 -> V_52 ) ;
F_19 ( V_59 , & V_11 -> V_42 ) ;
}
F_20 ( & V_11 -> V_60 , & V_2 -> V_61 ) ;
F_21 ( & V_2 -> V_47 ) ;
F_14 ( & V_13 -> V_47 ) ;
F_22 ( & V_11 -> V_62 , & V_13 -> V_52 ) ;
F_21 ( & V_13 -> V_47 ) ;
V_4 -> V_63 [ V_21 ] = V_11 ;
F_8 ( & V_4 -> V_26 , ( V_21 + 1 ) & ( V_17 - 1 ) ) ;
F_4 ( L_3 , V_11 -> V_64 , V_7 ) ;
return 0 ;
V_56:
F_21 ( & V_2 -> V_47 ) ;
F_23 ( V_11 ) ;
F_4 ( L_4 ) ;
return - V_65 ;
}
int F_24 ( struct V_1 * V_2 , T_3 V_8 )
{
struct V_3 * V_4 = V_2 -> V_66 ;
if ( ! V_4 ) {
V_4 = F_25 ( sizeof( struct V_3 ) , V_8 ) ;
if ( ! V_4 )
return - V_33 ;
V_2 -> V_66 = V_4 ;
}
if ( V_2 -> V_67 )
return 0 ;
while ( F_1 ( V_2 , V_4 , NULL , NULL , 0 , V_8 ) == 0 )
;
return 0 ;
}
void F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_66 ;
struct V_12 * V_13 = V_12 ( F_3 ( & V_2 -> V_14 ) ) ;
unsigned int V_17 = V_18 , V_19 , V_20 ;
if ( ! V_4 )
return;
V_2 -> V_66 = NULL ;
F_27 ( & V_2 -> V_68 ) ;
F_28 ( & V_2 -> V_68 ) ;
V_19 = V_4 -> V_28 ;
V_20 = V_4 -> V_29 ;
while ( F_6 ( V_19 , V_20 , V_17 ) > 0 ) {
struct V_30 * V_31 = V_4 -> V_34 [ V_20 ] ;
F_29 ( V_31 ) ;
V_20 = ( V_20 + 1 ) & ( V_17 - 1 ) ;
}
V_19 = V_4 -> V_35 ;
V_20 = V_4 -> V_36 ;
while ( F_6 ( V_19 , V_20 , V_17 ) > 0 ) {
struct V_37 * V_38 = V_4 -> V_39 [ V_20 ] ;
F_14 ( & V_13 -> V_69 ) ;
F_30 ( & V_38 -> V_62 ) ;
F_30 ( & V_38 -> V_70 ) ;
F_21 ( & V_13 -> V_69 ) ;
F_29 ( V_38 ) ;
V_20 = ( V_20 + 1 ) & ( V_17 - 1 ) ;
}
V_19 = V_4 -> V_26 ;
V_20 = V_4 -> V_27 ;
while ( F_6 ( V_19 , V_20 , V_17 ) > 0 ) {
struct V_10 * V_11 = V_4 -> V_63 [ V_20 ] ;
V_11 -> V_71 = V_2 ;
if ( V_2 -> V_67 ) {
F_31 ( L_5 , V_11 -> V_7 ) ;
V_2 -> V_67 ( V_11 , V_11 -> V_7 ) ;
F_32 ( V_11 , V_72 ) ;
}
F_33 ( V_11 ) ;
F_34 ( V_2 , V_11 ) ;
F_32 ( V_11 , V_73 ) ;
V_20 = ( V_20 + 1 ) & ( V_17 - 1 ) ;
}
F_29 ( V_4 ) ;
}
static struct V_10 * F_35 ( struct V_1 * V_2 ,
struct V_74 * V_32 ,
struct V_37 * V_38 ,
struct V_75 * V_76 )
{
struct V_3 * V_4 = V_2 -> V_66 ;
struct V_30 * V_31 , * V_77 ;
struct V_10 * V_11 ;
unsigned short V_21 , V_78 , V_79 ;
unsigned short V_22 , V_80 , V_81 ;
unsigned short V_82 , V_83 ;
V_21 = F_36 ( & V_4 -> V_26 ) ;
V_22 = V_4 -> V_27 ;
V_82 = F_6 ( V_21 , V_22 , V_18 ) ;
V_78 = F_36 ( & V_4 -> V_35 ) ;
V_80 = V_4 -> V_36 ;
V_83 = F_6 ( V_78 , V_80 , V_18 ) ;
F_37 ( V_83 , >= , V_82 ) ;
V_79 = F_36 ( & V_4 -> V_28 ) ;
V_81 = V_4 -> V_29 ;
F_37 ( F_6 ( V_79 , V_81 , V_18 ) , >= ,
V_83 ) ;
if ( V_82 == 0 )
return NULL ;
if ( ! V_38 ) {
V_77 = V_4 -> V_34 [ V_81 ] ;
if ( F_38 ( & V_77 -> V_84 , V_76 ) < 0 )
return NULL ;
V_31 = F_39 ( V_32 , V_77 ) ;
if ( V_31 == V_77 ) {
V_4 -> V_34 [ V_81 ] = NULL ;
F_8 ( & V_4 -> V_29 ,
( V_81 + 1 ) &
( V_18 - 1 ) ) ;
}
V_38 = V_4 -> V_39 [ V_80 ] ;
V_4 -> V_39 [ V_80 ] = NULL ;
F_8 ( & V_4 -> V_36 ,
( V_80 + 1 ) & ( V_18 - 1 ) ) ;
F_40 ( V_32 ) ;
V_38 -> V_85 . V_32 = V_32 ;
V_38 -> V_85 . V_31 = V_31 ;
F_41 ( V_38 ) ;
F_42 ( V_2 , V_38 , V_76 ) ;
} else {
F_43 ( V_38 ) ;
}
V_11 = V_4 -> V_63 [ V_22 ] ;
V_4 -> V_63 [ V_22 ] = NULL ;
F_8 ( & V_4 -> V_27 ,
( V_22 + 1 ) & ( V_18 - 1 ) ) ;
F_44 ( V_11 ) ;
V_11 -> V_38 = V_38 ;
V_11 -> V_31 = F_45 ( V_38 -> V_85 . V_31 ) ;
V_11 -> V_86 = V_11 -> V_31 -> V_86 ;
return V_11 ;
}
struct V_10 * F_46 ( struct V_74 * V_32 ,
struct V_37 * V_38 ,
struct V_75 * V_76 )
{
struct V_87 * V_88 = F_47 ( V_76 ) ;
struct V_1 * V_2 ;
struct V_10 * V_11 ;
T_4 V_89 = V_88 -> V_90 . V_91 ;
F_48 ( L_6 ) ;
V_2 = F_49 ( V_32 -> V_92 ) ;
if ( V_2 && ( V_89 == V_2 -> V_84 . V_93 ||
V_89 == V_2 -> V_94 ) )
goto V_95;
F_50 ( L_7 , V_88 -> V_90 . V_96 , V_88 -> V_90 . V_97 , V_88 -> V_90 . V_98 ,
V_99 , V_100 ) ;
V_76 -> V_101 = V_102 ;
V_76 -> V_103 = V_99 ;
F_4 ( L_8 ) ;
return NULL ;
V_95:
F_51 ( & V_2 -> V_68 ) ;
if ( V_2 -> V_14 . V_104 == V_105 ||
V_2 -> V_14 . V_104 == V_106 ) {
F_50 ( L_9 , V_88 -> V_90 . V_96 , V_88 -> V_90 . V_97 ,
V_88 -> V_90 . V_98 , V_99 , V_107 ) ;
V_76 -> V_101 = V_102 ;
V_76 -> V_103 = V_99 ;
F_4 ( L_10 ) ;
V_11 = NULL ;
goto V_108;
}
V_11 = F_35 ( V_2 , V_32 , V_38 , V_76 ) ;
if ( ! V_11 ) {
V_76 -> V_101 = V_109 ;
F_4 ( L_11 ) ;
V_11 = NULL ;
goto V_108;
}
F_52 ( V_11 , V_110 ,
V_88 -> V_90 . V_111 , V_88 -> V_90 . V_98 ) ;
if ( ! F_53 ( & V_11 -> V_112 ) )
F_54 () ;
F_55 ( V_2 , V_11 , V_76 ) ;
V_38 = V_11 -> V_38 ;
if ( V_2 -> V_113 )
V_2 -> V_113 ( & V_2 -> V_14 , V_11 , V_11 -> V_7 ) ;
else
F_56 ( & V_2 -> V_14 ) ;
F_51 ( & V_38 -> V_114 ) ;
switch ( V_38 -> V_44 ) {
case V_115 :
V_38 -> V_44 = V_116 ;
F_19 ( V_117 , & V_11 -> V_38 -> V_118 ) ;
F_57 ( V_11 -> V_38 ) ;
break;
case V_119 :
F_14 ( & V_11 -> V_114 ) ;
if ( V_2 -> V_67 )
V_11 -> V_44 = V_120 ;
else
V_11 -> V_44 = V_121 ;
F_21 ( & V_11 -> V_114 ) ;
break;
case V_122 :
F_58 ( V_11 , V_123 ,
V_38 -> V_124 , - V_125 ) ;
break;
case V_126 :
F_59 ( L_12 , V_11 , V_88 -> V_90 . V_98 ,
V_38 -> V_127 , - V_125 ) ;
break;
default:
F_54 () ;
}
F_60 ( & V_38 -> V_114 ) ;
if ( V_11 -> V_44 == V_121 )
F_61 ( V_11 ) ;
F_32 ( V_11 , V_73 ) ;
F_4 ( L_13 , V_11 , V_11 -> V_64 ) ;
V_108:
F_60 ( & V_2 -> V_68 ) ;
return V_11 ;
}
struct V_10 * F_62 ( struct V_1 * V_2 ,
unsigned long V_7 ,
T_1 V_5 )
__releases( &rx->sk.sk_lock.slock
int F_63 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
bool abort = false ;
int V_128 ;
F_48 ( L_6 ) ;
ASSERT ( ! F_64 () ) ;
F_14 ( & V_2 -> V_47 ) ;
if ( F_65 ( & V_2 -> V_129 ) ) {
F_21 ( & V_2 -> V_47 ) ;
return - V_130 ;
}
V_11 = F_66 ( V_2 -> V_129 . V_131 ,
struct V_10 , V_132 ) ;
F_67 ( & V_11 -> V_132 ) ;
F_68 ( & V_2 -> V_14 ) ;
F_44 ( V_11 ) ;
F_69 ( & V_11 -> V_114 ) ;
switch ( V_11 -> V_44 ) {
case V_121 :
F_70 ( L_14 , V_11 , 1 , V_133 , - V_125 ) ;
abort = true ;
case V_134 :
V_128 = V_11 -> error ;
goto V_135;
default:
F_54 () ;
}
V_135:
F_71 ( & V_11 -> V_114 ) ;
F_21 ( & V_2 -> V_47 ) ;
if ( abort ) {
F_72 ( V_11 ) ;
F_34 ( V_2 , V_11 ) ;
F_32 ( V_11 , V_73 ) ;
}
F_24 ( V_2 , V_136 ) ;
F_4 ( L_15 , V_128 ) ;
return V_128 ;
}
int F_73 ( struct V_71 * V_137 ,
T_1 V_5 ,
T_2 V_6 ,
unsigned long V_7 , T_3 V_8 )
{
struct V_1 * V_2 = F_74 ( V_137 -> V_14 ) ;
struct V_3 * V_4 = V_2 -> V_66 ;
if ( V_137 -> V_14 -> V_104 == V_106 )
return - V_107 ;
return F_1 ( V_2 , V_4 , V_5 ,
V_6 , V_7 ,
V_8 ) ;
}
