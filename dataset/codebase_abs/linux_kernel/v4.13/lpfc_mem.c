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
int
F_11 ( struct V_1 * V_2 )
{
V_2 -> V_57 =
F_4 ( L_6 ,
V_2 -> V_22 , V_58 ,
V_59 , 0 ) ;
if ( ! V_2 -> V_57 ) {
F_12 ( V_2 , V_60 , V_61 ,
L_7 ) ;
return - V_7 ;
}
return 0 ;
}
void
F_13 ( struct V_1 * V_2 )
{
int V_16 ;
struct V_13 * V_14 = & V_2 -> V_15 ;
struct V_55 * V_62 ;
F_14 ( V_2 ) ;
if ( V_2 -> V_57 )
F_7 ( V_2 -> V_57 ) ;
V_2 -> V_57 = NULL ;
if ( V_2 -> V_48 )
F_7 ( V_2 -> V_48 ) ;
V_2 -> V_48 = NULL ;
if ( V_2 -> V_45 )
F_7 ( V_2 -> V_45 ) ;
V_2 -> V_45 = NULL ;
if ( V_2 -> V_63 )
F_7 ( V_2 -> V_63 ) ;
V_2 -> V_63 = NULL ;
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
while ( ! F_15 ( & V_2 -> V_64 ) ) {
V_62 = F_16 ( & V_2 -> V_64 ,
struct V_55 ,
V_65 ) ;
F_17 ( & V_62 -> V_65 ) ;
F_18 ( V_62 , V_2 -> V_53 ) ;
}
F_8 ( V_2 -> V_53 ) ;
}
V_2 -> V_53 = NULL ;
return;
}
void
F_19 ( struct V_1 * V_2 )
{
struct V_66 * V_67 = & V_2 -> V_68 ;
V_38 * V_69 , * V_70 ;
struct V_28 * V_71 ;
F_20 (mbox, next_mbox, &psli->mboxq, list) {
V_71 = (struct V_28 * ) ( V_69 -> V_72 ) ;
if ( V_71 ) {
F_21 ( V_2 , V_71 -> V_34 , V_71 -> V_35 ) ;
F_10 ( V_71 ) ;
}
F_17 ( & V_69 -> V_73 ) ;
F_18 ( V_69 , V_2 -> V_37 ) ;
}
F_20 (mbox, next_mbox, &psli->mboxq_cmpl, list) {
V_71 = (struct V_28 * ) ( V_69 -> V_72 ) ;
if ( V_71 ) {
F_21 ( V_2 , V_71 -> V_34 , V_71 -> V_35 ) ;
F_10 ( V_71 ) ;
}
F_17 ( & V_69 -> V_73 ) ;
F_18 ( V_69 , V_2 -> V_37 ) ;
}
F_22 ( & V_2 -> V_74 ) ;
V_67 -> V_75 &= ~ V_76 ;
F_23 ( & V_2 -> V_74 ) ;
if ( V_67 -> V_77 ) {
V_69 = V_67 -> V_77 ;
V_71 = (struct V_28 * ) ( V_69 -> V_72 ) ;
if ( V_71 ) {
F_21 ( V_2 , V_71 -> V_34 , V_71 -> V_35 ) ;
F_10 ( V_71 ) ;
}
F_18 ( V_69 , V_2 -> V_37 ) ;
V_67 -> V_77 = NULL ;
}
F_13 ( V_2 ) ;
F_10 ( V_67 -> V_78 ) ;
V_67 -> V_78 = NULL ;
return;
}
void *
F_24 ( struct V_1 * V_2 , int V_79 , T_2 * V_80 )
{
struct V_13 * V_14 = & V_2 -> V_15 ;
unsigned long V_81 ;
void * V_82 ;
V_82 = F_6 ( V_2 -> V_24 , V_30 , V_80 ) ;
F_25 ( & V_2 -> V_74 , V_81 ) ;
if ( ! V_82 && ( V_79 & V_83 ) && V_14 -> V_33 ) {
V_14 -> V_33 -- ;
V_82 = V_14 -> V_27 [ V_14 -> V_33 ] . V_34 ;
* V_80 = V_14 -> V_27 [ V_14 -> V_33 ] . V_35 ;
}
F_26 ( & V_2 -> V_74 , V_81 ) ;
return V_82 ;
}
void
F_27 ( struct V_1 * V_2 , void * V_34 , T_2 V_84 )
{
struct V_13 * V_14 = & V_2 -> V_15 ;
if ( V_14 -> V_33 < V_14 -> V_32 ) {
V_14 -> V_27 [ V_14 -> V_33 ] . V_34 = V_34 ;
V_14 -> V_27 [ V_14 -> V_33 ] . V_35 = V_84 ;
V_14 -> V_33 ++ ;
} else {
F_9 ( V_2 -> V_24 , V_34 , V_84 ) ;
}
return;
}
void
F_21 ( struct V_1 * V_2 , void * V_34 , T_2 V_84 )
{
unsigned long V_81 ;
F_25 ( & V_2 -> V_74 , V_81 ) ;
F_27 ( V_2 , V_34 , V_84 ) ;
F_26 ( & V_2 -> V_74 , V_81 ) ;
return;
}
void *
F_28 ( struct V_1 * V_2 , int V_79 , T_2 * V_80 )
{
void * V_82 ;
V_82 = F_6 ( V_2 -> V_21 , V_30 , V_80 ) ;
return V_82 ;
}
void
F_29 ( struct V_1 * V_2 , void * V_34 , T_2 V_84 )
{
F_9 ( V_2 -> V_21 , V_34 , V_84 ) ;
}
struct V_85 *
F_30 ( struct V_1 * V_2 )
{
struct V_85 * V_86 ;
V_86 = F_31 ( sizeof( struct V_85 ) , V_30 ) ;
if ( ! V_86 )
return NULL ;
V_86 -> V_87 . V_34 = F_6 ( V_2 -> V_51 , V_30 ,
& V_86 -> V_87 . V_35 ) ;
if ( ! V_86 -> V_87 . V_34 ) {
F_10 ( V_86 ) ;
return NULL ;
}
V_86 -> V_88 = V_25 ;
return V_86 ;
}
void
F_32 ( struct V_1 * V_2 , struct V_85 * V_86 )
{
F_9 ( V_2 -> V_51 , V_86 -> V_87 . V_34 , V_86 -> V_87 . V_35 ) ;
F_10 ( V_86 ) ;
return;
}
struct V_85 *
F_33 ( struct V_1 * V_2 )
{
struct V_85 * V_89 ;
V_89 = F_31 ( sizeof( struct V_85 ) , V_30 ) ;
if ( ! V_89 )
return NULL ;
V_89 -> V_90 . V_34 = F_6 ( V_2 -> V_45 , V_30 ,
& V_89 -> V_90 . V_35 ) ;
if ( ! V_89 -> V_90 . V_34 ) {
F_10 ( V_89 ) ;
return NULL ;
}
V_89 -> V_87 . V_34 = F_6 ( V_2 -> V_48 , V_30 ,
& V_89 -> V_87 . V_35 ) ;
if ( ! V_89 -> V_87 . V_34 ) {
F_9 ( V_2 -> V_45 , V_89 -> V_90 . V_34 ,
V_89 -> V_90 . V_35 ) ;
F_10 ( V_89 ) ;
return NULL ;
}
V_89 -> V_88 = V_49 ;
return V_89 ;
}
void
F_34 ( struct V_1 * V_2 , struct V_85 * V_91 )
{
F_9 ( V_2 -> V_45 , V_91 -> V_90 . V_34 , V_91 -> V_90 . V_35 ) ;
F_9 ( V_2 -> V_48 , V_91 -> V_87 . V_34 , V_91 -> V_87 . V_35 ) ;
F_10 ( V_91 ) ;
}
struct V_92 *
F_35 ( struct V_1 * V_2 )
{
struct V_92 * V_89 ;
V_89 = F_31 ( sizeof( struct V_92 ) , V_30 ) ;
if ( ! V_89 )
return NULL ;
V_89 -> V_90 . V_34 = F_6 ( V_2 -> V_45 , V_30 ,
& V_89 -> V_90 . V_35 ) ;
if ( ! V_89 -> V_90 . V_34 ) {
F_10 ( V_89 ) ;
return NULL ;
}
V_89 -> V_87 . V_34 = F_6 ( V_2 -> V_57 ,
V_30 , & V_89 -> V_87 . V_35 ) ;
if ( ! V_89 -> V_87 . V_34 ) {
F_9 ( V_2 -> V_45 , V_89 -> V_90 . V_34 ,
V_89 -> V_90 . V_35 ) ;
F_10 ( V_89 ) ;
return NULL ;
}
V_89 -> V_88 = V_58 ;
return V_89 ;
}
void
F_36 ( struct V_1 * V_2 , struct V_92 * V_91 )
{
F_9 ( V_2 -> V_45 , V_91 -> V_90 . V_34 , V_91 -> V_90 . V_35 ) ;
F_9 ( V_2 -> V_57 ,
V_91 -> V_87 . V_34 , V_91 -> V_87 . V_35 ) ;
F_10 ( V_91 ) ;
}
void
F_37 ( struct V_1 * V_2 , struct V_28 * V_71 )
{
struct V_85 * V_93 ;
unsigned long V_94 ;
if ( ! V_71 )
return;
if ( V_2 -> V_95 & V_96 ) {
V_93 = F_38 ( V_71 , struct V_85 , V_87 ) ;
F_25 ( & V_2 -> V_74 , V_94 ) ;
if ( ! V_2 -> V_97 ) {
F_26 ( & V_2 -> V_74 , V_94 ) ;
return;
}
F_17 ( & V_93 -> V_87 . V_73 ) ;
if ( V_93 -> V_98 == - 1 ) {
( V_2 -> V_99 [ V_100 ] . V_101 )
( V_2 , V_93 ) ;
} else {
F_39 ( V_2 , V_93 ) ;
}
F_26 ( & V_2 -> V_74 , V_94 ) ;
} else {
F_21 ( V_2 , V_71 -> V_34 , V_71 -> V_35 ) ;
F_10 ( V_71 ) ;
}
return;
}
void
F_40 ( struct V_1 * V_2 , struct V_28 * V_71 )
{
struct V_102 * V_103 ;
struct V_104 V_105 ;
struct V_104 V_106 ;
struct V_92 * V_107 ;
unsigned long V_94 ;
int V_108 ;
if ( ! V_71 )
return;
V_107 = F_38 ( V_71 , struct V_92 , V_90 ) ;
V_103 = V_107 -> V_109 -> V_103 ;
F_25 ( & V_2 -> V_74 , V_94 ) ;
F_17 ( & V_107 -> V_90 . V_73 ) ;
V_105 . V_110 = F_41 ( V_107 -> V_90 . V_35 ) ;
V_105 . V_111 = F_42 ( V_107 -> V_90 . V_35 ) ;
V_106 . V_110 = F_41 ( V_107 -> V_87 . V_35 ) ;
V_106 . V_111 = F_42 ( V_107 -> V_87 . V_35 ) ;
V_108 = F_43 ( V_107 -> V_109 , V_107 -> V_112 , & V_105 , & V_106 ) ;
if ( V_108 < 0 ) {
( V_103 -> V_113 ) ( V_2 , V_107 ) ;
F_12 ( V_2 , V_60 , V_61 ,
L_8 ,
V_107 -> V_109 -> V_114 ,
V_107 -> V_109 -> V_115 ,
V_107 -> V_109 -> V_116 ) ;
} else {
F_44 ( & V_107 -> V_90 . V_73 , & V_103 -> V_117 ) ;
V_103 -> V_118 ++ ;
}
F_26 ( & V_2 -> V_74 , V_94 ) ;
}
