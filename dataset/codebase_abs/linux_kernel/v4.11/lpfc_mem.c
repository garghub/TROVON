int
F_1 ( struct V_1 * V_2 ) {
T_1 V_3 ;
int V_4 = V_2 -> V_5 . V_6 . V_4 ;
if ( V_4 <= 0 )
return - V_7 ;
V_3 = ( ( V_8 - 1 + V_4 ) / V_8 ) *
sizeof( unsigned long ) ;
V_2 -> V_9 = V_3 ;
V_2 -> V_10 = F_2 ( V_11 ,
V_3 ) ;
if ( ! V_2 -> V_10 )
return - V_7 ;
else
return 0 ;
}
int
F_3 ( struct V_1 * V_2 , int V_12 )
{
struct V_13 * V_14 = & V_2 -> V_15 ;
int V_16 ;
if ( V_2 -> V_17 == V_18 ) {
if ( V_2 -> V_19 < V_20 )
V_16 = V_2 -> V_19 ;
else
V_16 = V_20 ;
V_2 -> V_21 =
F_4 ( L_1 ,
V_2 -> V_22 ,
V_2 -> V_19 ,
V_16 , 0 ) ;
if ( ! V_2 -> V_21 )
goto V_23;
} else {
V_2 -> V_21 =
F_4 ( L_1 ,
V_2 -> V_22 , V_2 -> V_19 ,
V_12 , 0 ) ;
if ( ! V_2 -> V_21 )
goto V_23;
}
V_2 -> V_24 = F_4 ( L_2 , V_2 -> V_22 ,
V_25 ,
V_12 , 0 ) ;
if ( ! V_2 -> V_24 )
goto V_26;
V_14 -> V_27 = F_5 ( sizeof( struct V_28 ) *
V_29 , V_30 ) ;
if ( ! V_14 -> V_27 )
goto V_31;
V_14 -> V_32 = 0 ;
V_14 -> V_33 = 0 ;
for ( V_16 = 0 ; V_16 < V_29 ; V_16 ++ ) {
V_14 -> V_27 [ V_16 ] . V_34 = F_6 ( V_2 -> V_24 ,
V_30 , & V_14 -> V_27 [ V_16 ] . V_35 ) ;
if ( ! V_14 -> V_27 [ V_16 ] . V_34 )
goto V_36;
V_14 -> V_32 ++ ;
V_14 -> V_33 ++ ;
}
V_2 -> V_37 = F_2 ( V_11 ,
sizeof( V_38 ) ) ;
if ( ! V_2 -> V_37 )
goto V_36;
V_2 -> V_39 = F_2 ( V_11 ,
sizeof( struct V_40 ) ) ;
if ( ! V_2 -> V_39 )
goto V_41;
if ( V_2 -> V_17 == V_18 ) {
V_2 -> V_42 =
F_2 ( V_11 ,
sizeof( struct V_43 ) ) ;
if ( ! V_2 -> V_42 )
goto V_44;
V_2 -> V_45 = F_4 ( L_3 ,
V_2 -> V_22 ,
V_46 , V_12 , 0 ) ;
if ( ! V_2 -> V_45 )
goto V_47;
V_2 -> V_48 = F_4 ( L_4 ,
V_2 -> V_22 ,
V_49 , V_12 , 0 ) ;
if ( ! V_2 -> V_48 )
goto V_50;
V_2 -> V_51 = NULL ;
} else {
V_2 -> V_51 = F_4 ( L_5 ,
V_2 -> V_22 , V_25 , V_12 , 0 ) ;
if ( ! V_2 -> V_51 )
goto V_44;
V_2 -> V_45 = NULL ;
V_2 -> V_48 = NULL ;
}
if ( V_2 -> V_52 ) {
V_2 -> V_53 = F_2 (
V_54 ,
sizeof( struct V_55 ) ) ;
if ( ! V_2 -> V_53 )
goto V_56;
} else {
V_2 -> V_53 = NULL ;
}
return 0 ;
V_56:
F_7 ( V_2 -> V_48 ) ;
V_2 -> V_48 = NULL ;
V_50:
F_7 ( V_2 -> V_45 ) ;
V_2 -> V_45 = NULL ;
V_47:
F_8 ( V_2 -> V_42 ) ;
V_2 -> V_42 = NULL ;
V_44:
F_8 ( V_2 -> V_39 ) ;
V_2 -> V_39 = NULL ;
V_41:
F_8 ( V_2 -> V_37 ) ;
V_2 -> V_37 = NULL ;
V_36:
while ( V_16 -- )
F_9 ( V_2 -> V_24 , V_14 -> V_27 [ V_16 ] . V_34 ,
V_14 -> V_27 [ V_16 ] . V_35 ) ;
F_10 ( V_14 -> V_27 ) ;
V_31:
F_7 ( V_2 -> V_24 ) ;
V_2 -> V_24 = NULL ;
V_26:
F_7 ( V_2 -> V_21 ) ;
V_2 -> V_21 = NULL ;
V_23:
return - V_7 ;
}
void
F_11 ( struct V_1 * V_2 )
{
int V_16 ;
struct V_13 * V_14 = & V_2 -> V_15 ;
struct V_55 * V_57 ;
F_12 ( V_2 ) ;
if ( V_2 -> V_48 )
F_7 ( V_2 -> V_48 ) ;
V_2 -> V_48 = NULL ;
if ( V_2 -> V_45 )
F_7 ( V_2 -> V_45 ) ;
V_2 -> V_45 = NULL ;
if ( V_2 -> V_58 )
F_7 ( V_2 -> V_58 ) ;
V_2 -> V_58 = NULL ;
if ( V_2 -> V_51 )
F_7 ( V_2 -> V_51 ) ;
V_2 -> V_51 = NULL ;
if ( V_2 -> V_42 )
F_8 ( V_2 -> V_42 ) ;
V_2 -> V_42 = NULL ;
F_8 ( V_2 -> V_39 ) ;
V_2 -> V_39 = NULL ;
if ( V_2 -> V_17 == V_18 && V_2 -> V_10 ) {
F_8 ( V_2 -> V_10 ) ;
V_2 -> V_10 = NULL ;
}
F_8 ( V_2 -> V_37 ) ;
V_2 -> V_37 = NULL ;
for ( V_16 = 0 ; V_16 < V_14 -> V_33 ; V_16 ++ )
F_9 ( V_2 -> V_24 , V_14 -> V_27 [ V_16 ] . V_34 ,
V_14 -> V_27 [ V_16 ] . V_35 ) ;
F_10 ( V_14 -> V_27 ) ;
F_7 ( V_2 -> V_24 ) ;
V_2 -> V_24 = NULL ;
F_7 ( V_2 -> V_21 ) ;
V_2 -> V_21 = NULL ;
if ( V_2 -> V_53 ) {
while ( ! F_13 ( & V_2 -> V_59 ) ) {
V_57 = F_14 ( & V_2 -> V_59 ,
struct V_55 ,
V_60 ) ;
F_15 ( & V_57 -> V_60 ) ;
F_16 ( V_57 , V_2 -> V_53 ) ;
}
F_8 ( V_2 -> V_53 ) ;
}
V_2 -> V_53 = NULL ;
return;
}
void
F_17 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = & V_2 -> V_63 ;
V_38 * V_64 , * V_65 ;
struct V_28 * V_66 ;
F_18 (mbox, next_mbox, &psli->mboxq, list) {
V_66 = (struct V_28 * ) ( V_64 -> V_67 ) ;
if ( V_66 ) {
F_19 ( V_2 , V_66 -> V_34 , V_66 -> V_35 ) ;
F_10 ( V_66 ) ;
}
F_15 ( & V_64 -> V_68 ) ;
F_16 ( V_64 , V_2 -> V_37 ) ;
}
F_18 (mbox, next_mbox, &psli->mboxq_cmpl, list) {
V_66 = (struct V_28 * ) ( V_64 -> V_67 ) ;
if ( V_66 ) {
F_19 ( V_2 , V_66 -> V_34 , V_66 -> V_35 ) ;
F_10 ( V_66 ) ;
}
F_15 ( & V_64 -> V_68 ) ;
F_16 ( V_64 , V_2 -> V_37 ) ;
}
F_20 ( & V_2 -> V_69 ) ;
V_62 -> V_70 &= ~ V_71 ;
F_21 ( & V_2 -> V_69 ) ;
if ( V_62 -> V_72 ) {
V_64 = V_62 -> V_72 ;
V_66 = (struct V_28 * ) ( V_64 -> V_67 ) ;
if ( V_66 ) {
F_19 ( V_2 , V_66 -> V_34 , V_66 -> V_35 ) ;
F_10 ( V_66 ) ;
}
F_16 ( V_64 , V_2 -> V_37 ) ;
V_62 -> V_72 = NULL ;
}
F_11 ( V_2 ) ;
F_10 ( V_62 -> V_73 ) ;
V_62 -> V_73 = NULL ;
return;
}
void *
F_22 ( struct V_1 * V_2 , int V_74 , T_2 * V_75 )
{
struct V_13 * V_14 = & V_2 -> V_15 ;
unsigned long V_76 ;
void * V_77 ;
V_77 = F_6 ( V_2 -> V_24 , V_30 , V_75 ) ;
F_23 ( & V_2 -> V_69 , V_76 ) ;
if ( ! V_77 && ( V_74 & V_78 ) && V_14 -> V_33 ) {
V_14 -> V_33 -- ;
V_77 = V_14 -> V_27 [ V_14 -> V_33 ] . V_34 ;
* V_75 = V_14 -> V_27 [ V_14 -> V_33 ] . V_35 ;
}
F_24 ( & V_2 -> V_69 , V_76 ) ;
return V_77 ;
}
void
F_25 ( struct V_1 * V_2 , void * V_34 , T_2 V_79 )
{
struct V_13 * V_14 = & V_2 -> V_15 ;
if ( V_14 -> V_33 < V_14 -> V_32 ) {
V_14 -> V_27 [ V_14 -> V_33 ] . V_34 = V_34 ;
V_14 -> V_27 [ V_14 -> V_33 ] . V_35 = V_79 ;
V_14 -> V_33 ++ ;
} else {
F_9 ( V_2 -> V_24 , V_34 , V_79 ) ;
}
return;
}
void
F_19 ( struct V_1 * V_2 , void * V_34 , T_2 V_79 )
{
unsigned long V_76 ;
F_23 ( & V_2 -> V_69 , V_76 ) ;
F_25 ( V_2 , V_34 , V_79 ) ;
F_24 ( & V_2 -> V_69 , V_76 ) ;
return;
}
void *
F_26 ( struct V_1 * V_2 , int V_74 , T_2 * V_75 )
{
void * V_77 ;
V_77 = F_6 ( V_2 -> V_21 , V_30 , V_75 ) ;
return V_77 ;
}
void
F_27 ( struct V_1 * V_2 , void * V_34 , T_2 V_79 )
{
F_9 ( V_2 -> V_21 , V_34 , V_79 ) ;
}
struct V_80 *
F_28 ( struct V_1 * V_2 )
{
struct V_80 * V_81 ;
V_81 = F_29 ( sizeof( struct V_80 ) , V_30 ) ;
if ( ! V_81 )
return NULL ;
V_81 -> V_82 . V_34 = F_6 ( V_2 -> V_51 , V_30 ,
& V_81 -> V_82 . V_35 ) ;
if ( ! V_81 -> V_82 . V_34 ) {
F_10 ( V_81 ) ;
return NULL ;
}
V_81 -> V_83 = V_25 ;
return V_81 ;
}
void
F_30 ( struct V_1 * V_2 , struct V_80 * V_81 )
{
F_9 ( V_2 -> V_51 , V_81 -> V_82 . V_34 , V_81 -> V_82 . V_35 ) ;
F_10 ( V_81 ) ;
return;
}
struct V_80 *
F_31 ( struct V_1 * V_2 )
{
struct V_80 * V_84 ;
V_84 = F_29 ( sizeof( struct V_80 ) , V_30 ) ;
if ( ! V_84 )
return NULL ;
V_84 -> V_85 . V_34 = F_6 ( V_2 -> V_45 , V_30 ,
& V_84 -> V_85 . V_35 ) ;
if ( ! V_84 -> V_85 . V_34 ) {
F_10 ( V_84 ) ;
return NULL ;
}
V_84 -> V_82 . V_34 = F_6 ( V_2 -> V_48 , V_30 ,
& V_84 -> V_82 . V_35 ) ;
if ( ! V_84 -> V_82 . V_34 ) {
F_9 ( V_2 -> V_45 , V_84 -> V_85 . V_34 ,
V_84 -> V_85 . V_35 ) ;
F_10 ( V_84 ) ;
return NULL ;
}
V_84 -> V_83 = V_49 ;
return V_84 ;
}
void
F_32 ( struct V_1 * V_2 , struct V_80 * V_86 )
{
F_9 ( V_2 -> V_45 , V_86 -> V_85 . V_34 , V_86 -> V_85 . V_35 ) ;
F_9 ( V_2 -> V_48 , V_86 -> V_82 . V_34 , V_86 -> V_82 . V_35 ) ;
F_10 ( V_86 ) ;
}
struct V_87 *
F_33 ( struct V_1 * V_2 )
{
struct V_87 * V_84 ;
struct V_88 * V_89 ;
union V_90 * V_91 ;
V_84 = F_29 ( sizeof( struct V_87 ) , V_30 ) ;
if ( ! V_84 )
return NULL ;
V_84 -> V_85 . V_34 = F_6 ( V_2 -> V_45 , V_30 ,
& V_84 -> V_85 . V_35 ) ;
if ( ! V_84 -> V_85 . V_34 ) {
F_10 ( V_84 ) ;
return NULL ;
}
V_84 -> V_82 . V_34 = F_6 ( V_2 -> V_48 , V_30 ,
& V_84 -> V_82 . V_35 ) ;
if ( ! V_84 -> V_82 . V_34 ) {
F_9 ( V_2 -> V_45 , V_84 -> V_85 . V_34 ,
V_84 -> V_85 . V_35 ) ;
F_10 ( V_84 ) ;
return NULL ;
}
V_84 -> V_83 = V_49 ;
V_84 -> V_92 = F_29 ( sizeof( struct V_93 ) ,
V_30 ) ;
if ( ! V_84 -> V_92 ) {
F_9 ( V_2 -> V_48 , V_84 -> V_82 . V_34 ,
V_84 -> V_82 . V_35 ) ;
F_9 ( V_2 -> V_45 , V_84 -> V_85 . V_34 ,
V_84 -> V_85 . V_35 ) ;
F_10 ( V_84 ) ;
return NULL ;
}
V_84 -> V_94 = F_34 ( V_2 ) ;
if ( ! V_84 -> V_94 ) {
F_10 ( V_84 -> V_92 ) ;
F_9 ( V_2 -> V_48 , V_84 -> V_82 . V_34 ,
V_84 -> V_82 . V_35 ) ;
F_9 ( V_2 -> V_45 , V_84 -> V_85 . V_34 ,
V_84 -> V_85 . V_35 ) ;
F_10 ( V_84 ) ;
F_35 ( V_2 , V_95 , V_96 ,
L_6 ) ;
return NULL ;
}
V_84 -> V_94 -> V_97 = V_98 ;
V_89 = V_84 -> V_94 ;
V_91 = (union V_90 * ) & V_89 -> V_91 ;
memset ( V_91 , 0 , sizeof( union V_99 ) ) ;
F_36 ( V_100 , & V_91 -> V_101 . V_102 , V_103 ) ;
F_36 ( V_104 , & V_91 -> V_101 . V_102 , V_105 ) ;
F_36 ( V_106 , & V_91 -> V_101 . V_102 , 1 ) ;
F_36 ( V_107 , & V_91 -> V_108 . V_102 , 1 ) ;
F_36 ( V_109 , & V_91 -> V_101 . V_102 , 0 ) ;
F_36 ( V_110 , & V_91 -> V_101 . V_102 , 0 ) ;
V_84 -> V_94 -> V_67 = NULL ;
F_37 ( & V_2 -> V_5 . V_111 ) ;
V_84 -> V_112 = F_38 ( V_2 , V_84 -> V_94 ) ;
F_39 ( & V_2 -> V_5 . V_111 ) ;
if ( ! V_84 -> V_112 ) {
F_40 ( V_2 , V_84 -> V_94 ) ;
F_10 ( V_84 -> V_92 ) ;
F_9 ( V_2 -> V_48 , V_84 -> V_82 . V_34 ,
V_84 -> V_82 . V_35 ) ;
F_9 ( V_2 -> V_45 , V_84 -> V_85 . V_34 ,
V_84 -> V_85 . V_35 ) ;
F_10 ( V_84 ) ;
F_35 ( V_2 , V_95 , V_96 ,
L_7 ) ;
return NULL ;
}
return V_84 ;
}
void
F_41 ( struct V_1 * V_2 , struct V_87 * V_86 )
{
unsigned long V_113 ;
F_42 ( V_2 , V_86 -> V_112 -> V_114 ) ;
V_86 -> V_112 -> V_115 = V_116 ;
V_86 -> V_112 -> V_117 = NULL ;
F_23 ( & V_2 -> V_5 . V_111 , V_113 ) ;
F_43 ( & V_86 -> V_112 -> V_68 , & V_2 -> V_5 . V_118 ) ;
F_24 ( & V_2 -> V_5 . V_111 , V_113 ) ;
F_40 ( V_2 , V_86 -> V_94 ) ;
F_10 ( V_86 -> V_92 ) ;
F_9 ( V_2 -> V_45 , V_86 -> V_85 . V_34 , V_86 -> V_85 . V_35 ) ;
F_9 ( V_2 -> V_48 , V_86 -> V_82 . V_34 , V_86 -> V_82 . V_35 ) ;
F_10 ( V_86 ) ;
}
void
F_44 ( struct V_1 * V_2 , struct V_28 * V_66 )
{
struct V_80 * V_119 ;
unsigned long V_113 ;
if ( ! V_66 )
return;
if ( V_2 -> V_120 & V_121 ) {
V_119 = F_45 ( V_66 , struct V_80 , V_82 ) ;
F_23 ( & V_2 -> V_69 , V_113 ) ;
if ( ! V_2 -> V_122 ) {
F_24 ( & V_2 -> V_69 , V_113 ) ;
return;
}
F_15 ( & V_119 -> V_82 . V_68 ) ;
if ( V_119 -> V_123 == - 1 ) {
( V_2 -> V_124 [ V_125 ] . V_126 )
( V_2 , V_119 ) ;
} else {
F_46 ( V_2 , V_119 ) ;
}
F_24 ( & V_2 -> V_69 , V_113 ) ;
} else {
F_19 ( V_2 , V_66 -> V_34 , V_66 -> V_35 ) ;
F_10 ( V_66 ) ;
}
return;
}
void
F_47 ( struct V_1 * V_2 , struct V_28 * V_66 )
{
struct V_127 * V_128 ;
struct V_129 V_130 ;
struct V_129 V_131 ;
struct V_87 * V_132 ;
unsigned long V_113 ;
int V_133 ;
if ( ! V_66 )
return;
V_132 = F_45 ( V_66 , struct V_87 , V_85 ) ;
V_128 = V_132 -> V_134 -> V_128 ;
F_23 ( & V_2 -> V_69 , V_113 ) ;
F_15 ( & V_132 -> V_85 . V_68 ) ;
V_130 . V_135 = F_48 ( V_132 -> V_85 . V_35 ) ;
V_130 . V_136 = F_49 ( V_132 -> V_85 . V_35 ) ;
V_131 . V_135 = F_48 ( V_132 -> V_82 . V_35 ) ;
V_131 . V_136 = F_49 ( V_132 -> V_82 . V_35 ) ;
V_133 = F_50 ( V_132 -> V_134 , V_132 -> V_137 , & V_130 , & V_131 ) ;
if ( V_133 < 0 ) {
( V_128 -> V_138 ) ( V_2 , V_132 ) ;
} else {
F_43 ( & V_132 -> V_85 . V_68 , & V_128 -> V_139 ) ;
V_128 -> V_140 ++ ;
}
F_24 ( & V_2 -> V_69 , V_113 ) ;
}
