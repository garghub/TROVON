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
& V_2 -> V_22 -> V_23 ,
V_2 -> V_19 ,
V_16 , 0 ) ;
if ( ! V_2 -> V_21 )
goto V_24;
} else {
V_2 -> V_21 =
F_4 ( L_1 ,
& V_2 -> V_22 -> V_23 , V_2 -> V_19 ,
V_12 , 0 ) ;
if ( ! V_2 -> V_21 )
goto V_24;
}
V_2 -> V_25 = F_4 ( L_2 , & V_2 -> V_22 -> V_23 ,
V_26 ,
V_12 , 0 ) ;
if ( ! V_2 -> V_25 )
goto V_27;
V_14 -> V_28 = F_5 ( sizeof( struct V_29 ) *
V_30 , V_31 ) ;
if ( ! V_14 -> V_28 )
goto V_32;
V_14 -> V_33 = 0 ;
V_14 -> V_34 = 0 ;
for ( V_16 = 0 ; V_16 < V_30 ; V_16 ++ ) {
V_14 -> V_28 [ V_16 ] . V_35 = F_6 ( V_2 -> V_25 ,
V_31 , & V_14 -> V_28 [ V_16 ] . V_36 ) ;
if ( ! V_14 -> V_28 [ V_16 ] . V_35 )
goto V_37;
V_14 -> V_33 ++ ;
V_14 -> V_34 ++ ;
}
V_2 -> V_38 = F_2 ( V_11 ,
sizeof( V_39 ) ) ;
if ( ! V_2 -> V_38 )
goto V_37;
V_2 -> V_40 = F_2 ( V_11 ,
sizeof( struct V_41 ) ) ;
if ( ! V_2 -> V_40 )
goto V_42;
if ( V_2 -> V_17 == V_18 ) {
V_2 -> V_43 =
F_2 ( V_11 ,
sizeof( struct V_44 ) ) ;
if ( ! V_2 -> V_43 )
goto V_45;
V_2 -> V_46 = F_4 ( L_3 ,
& V_2 -> V_22 -> V_23 ,
V_47 , V_12 , 0 ) ;
if ( ! V_2 -> V_46 )
goto V_48;
V_2 -> V_49 = F_4 ( L_4 ,
& V_2 -> V_22 -> V_23 ,
V_50 , V_12 , 0 ) ;
if ( ! V_2 -> V_49 )
goto V_51;
V_2 -> V_52 = NULL ;
} else {
V_2 -> V_52 = F_4 ( L_5 ,
& V_2 -> V_22 -> V_23 , V_26 , V_12 , 0 ) ;
if ( ! V_2 -> V_52 )
goto V_45;
V_2 -> V_46 = NULL ;
V_2 -> V_49 = NULL ;
}
if ( V_2 -> V_53 ) {
V_2 -> V_54 = F_2 (
V_55 ,
sizeof( struct V_56 ) ) ;
if ( ! V_2 -> V_54 )
goto V_57;
} else {
V_2 -> V_54 = NULL ;
}
return 0 ;
V_57:
F_7 ( V_2 -> V_49 ) ;
V_2 -> V_49 = NULL ;
V_51:
F_7 ( V_2 -> V_46 ) ;
V_2 -> V_46 = NULL ;
V_48:
F_8 ( V_2 -> V_43 ) ;
V_2 -> V_43 = NULL ;
V_45:
F_8 ( V_2 -> V_40 ) ;
V_2 -> V_40 = NULL ;
V_42:
F_8 ( V_2 -> V_38 ) ;
V_2 -> V_38 = NULL ;
V_37:
while ( V_16 -- )
F_9 ( V_2 -> V_25 , V_14 -> V_28 [ V_16 ] . V_35 ,
V_14 -> V_28 [ V_16 ] . V_36 ) ;
F_10 ( V_14 -> V_28 ) ;
V_32:
F_7 ( V_2 -> V_25 ) ;
V_2 -> V_25 = NULL ;
V_27:
F_7 ( V_2 -> V_21 ) ;
V_2 -> V_21 = NULL ;
V_24:
return - V_7 ;
}
int
F_11 ( struct V_1 * V_2 )
{
V_2 -> V_58 =
F_4 ( L_6 ,
& V_2 -> V_22 -> V_23 , V_59 ,
V_60 , 0 ) ;
if ( ! V_2 -> V_58 ) {
F_12 ( V_2 , V_61 , V_62 ,
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
struct V_56 * V_63 ;
F_14 ( V_2 ) ;
if ( V_2 -> V_58 )
F_7 ( V_2 -> V_58 ) ;
V_2 -> V_58 = NULL ;
if ( V_2 -> V_49 )
F_7 ( V_2 -> V_49 ) ;
V_2 -> V_49 = NULL ;
if ( V_2 -> V_46 )
F_7 ( V_2 -> V_46 ) ;
V_2 -> V_46 = NULL ;
if ( V_2 -> V_64 )
F_7 ( V_2 -> V_64 ) ;
V_2 -> V_64 = NULL ;
if ( V_2 -> V_52 )
F_7 ( V_2 -> V_52 ) ;
V_2 -> V_52 = NULL ;
if ( V_2 -> V_43 )
F_8 ( V_2 -> V_43 ) ;
V_2 -> V_43 = NULL ;
F_8 ( V_2 -> V_40 ) ;
V_2 -> V_40 = NULL ;
if ( V_2 -> V_17 == V_18 && V_2 -> V_10 ) {
F_8 ( V_2 -> V_10 ) ;
V_2 -> V_10 = NULL ;
}
F_8 ( V_2 -> V_38 ) ;
V_2 -> V_38 = NULL ;
for ( V_16 = 0 ; V_16 < V_14 -> V_34 ; V_16 ++ )
F_9 ( V_2 -> V_25 , V_14 -> V_28 [ V_16 ] . V_35 ,
V_14 -> V_28 [ V_16 ] . V_36 ) ;
F_10 ( V_14 -> V_28 ) ;
F_7 ( V_2 -> V_25 ) ;
V_2 -> V_25 = NULL ;
F_7 ( V_2 -> V_21 ) ;
V_2 -> V_21 = NULL ;
if ( V_2 -> V_54 ) {
while ( ! F_15 ( & V_2 -> V_65 ) ) {
V_63 = F_16 ( & V_2 -> V_65 ,
struct V_56 ,
V_66 ) ;
F_17 ( & V_63 -> V_66 ) ;
F_18 ( V_63 , V_2 -> V_54 ) ;
}
F_8 ( V_2 -> V_54 ) ;
}
V_2 -> V_54 = NULL ;
return;
}
void
F_19 ( struct V_1 * V_2 )
{
struct V_67 * V_68 = & V_2 -> V_69 ;
V_39 * V_70 , * V_71 ;
struct V_29 * V_72 ;
F_20 (mbox, next_mbox, &psli->mboxq, list) {
V_72 = (struct V_29 * ) ( V_70 -> V_73 ) ;
if ( V_72 ) {
F_21 ( V_2 , V_72 -> V_35 , V_72 -> V_36 ) ;
F_10 ( V_72 ) ;
}
F_17 ( & V_70 -> V_74 ) ;
F_18 ( V_70 , V_2 -> V_38 ) ;
}
F_20 (mbox, next_mbox, &psli->mboxq_cmpl, list) {
V_72 = (struct V_29 * ) ( V_70 -> V_73 ) ;
if ( V_72 ) {
F_21 ( V_2 , V_72 -> V_35 , V_72 -> V_36 ) ;
F_10 ( V_72 ) ;
}
F_17 ( & V_70 -> V_74 ) ;
F_18 ( V_70 , V_2 -> V_38 ) ;
}
F_22 ( & V_2 -> V_75 ) ;
V_68 -> V_76 &= ~ V_77 ;
F_23 ( & V_2 -> V_75 ) ;
if ( V_68 -> V_78 ) {
V_70 = V_68 -> V_78 ;
V_72 = (struct V_29 * ) ( V_70 -> V_73 ) ;
if ( V_72 ) {
F_21 ( V_2 , V_72 -> V_35 , V_72 -> V_36 ) ;
F_10 ( V_72 ) ;
}
F_18 ( V_70 , V_2 -> V_38 ) ;
V_68 -> V_78 = NULL ;
}
F_13 ( V_2 ) ;
F_10 ( V_68 -> V_79 ) ;
V_68 -> V_79 = NULL ;
return;
}
void *
F_24 ( struct V_1 * V_2 , int V_80 , T_2 * V_81 )
{
struct V_13 * V_14 = & V_2 -> V_15 ;
unsigned long V_82 ;
void * V_83 ;
V_83 = F_6 ( V_2 -> V_25 , V_31 , V_81 ) ;
F_25 ( & V_2 -> V_75 , V_82 ) ;
if ( ! V_83 && ( V_80 & V_84 ) && V_14 -> V_34 ) {
V_14 -> V_34 -- ;
V_83 = V_14 -> V_28 [ V_14 -> V_34 ] . V_35 ;
* V_81 = V_14 -> V_28 [ V_14 -> V_34 ] . V_36 ;
}
F_26 ( & V_2 -> V_75 , V_82 ) ;
return V_83 ;
}
void
F_27 ( struct V_1 * V_2 , void * V_35 , T_2 V_85 )
{
struct V_13 * V_14 = & V_2 -> V_15 ;
if ( V_14 -> V_34 < V_14 -> V_33 ) {
V_14 -> V_28 [ V_14 -> V_34 ] . V_35 = V_35 ;
V_14 -> V_28 [ V_14 -> V_34 ] . V_36 = V_85 ;
V_14 -> V_34 ++ ;
} else {
F_9 ( V_2 -> V_25 , V_35 , V_85 ) ;
}
return;
}
void
F_21 ( struct V_1 * V_2 , void * V_35 , T_2 V_85 )
{
unsigned long V_82 ;
F_25 ( & V_2 -> V_75 , V_82 ) ;
F_27 ( V_2 , V_35 , V_85 ) ;
F_26 ( & V_2 -> V_75 , V_82 ) ;
return;
}
void *
F_28 ( struct V_1 * V_2 , int V_80 , T_2 * V_81 )
{
void * V_83 ;
V_83 = F_6 ( V_2 -> V_21 , V_31 , V_81 ) ;
return V_83 ;
}
void
F_29 ( struct V_1 * V_2 , void * V_35 , T_2 V_85 )
{
F_9 ( V_2 -> V_21 , V_35 , V_85 ) ;
}
struct V_86 *
F_30 ( struct V_1 * V_2 )
{
struct V_86 * V_87 ;
V_87 = F_31 ( sizeof( struct V_86 ) , V_31 ) ;
if ( ! V_87 )
return NULL ;
V_87 -> V_88 . V_35 = F_6 ( V_2 -> V_52 , V_31 ,
& V_87 -> V_88 . V_36 ) ;
if ( ! V_87 -> V_88 . V_35 ) {
F_10 ( V_87 ) ;
return NULL ;
}
V_87 -> V_89 = V_26 ;
return V_87 ;
}
void
F_32 ( struct V_1 * V_2 , struct V_86 * V_87 )
{
F_9 ( V_2 -> V_52 , V_87 -> V_88 . V_35 , V_87 -> V_88 . V_36 ) ;
F_10 ( V_87 ) ;
return;
}
struct V_86 *
F_33 ( struct V_1 * V_2 )
{
struct V_86 * V_90 ;
V_90 = F_31 ( sizeof( struct V_86 ) , V_31 ) ;
if ( ! V_90 )
return NULL ;
V_90 -> V_91 . V_35 = F_6 ( V_2 -> V_46 , V_31 ,
& V_90 -> V_91 . V_36 ) ;
if ( ! V_90 -> V_91 . V_35 ) {
F_10 ( V_90 ) ;
return NULL ;
}
V_90 -> V_88 . V_35 = F_6 ( V_2 -> V_49 , V_31 ,
& V_90 -> V_88 . V_36 ) ;
if ( ! V_90 -> V_88 . V_35 ) {
F_9 ( V_2 -> V_46 , V_90 -> V_91 . V_35 ,
V_90 -> V_91 . V_36 ) ;
F_10 ( V_90 ) ;
return NULL ;
}
V_90 -> V_89 = V_50 ;
return V_90 ;
}
void
F_34 ( struct V_1 * V_2 , struct V_86 * V_92 )
{
F_9 ( V_2 -> V_46 , V_92 -> V_91 . V_35 , V_92 -> V_91 . V_36 ) ;
F_9 ( V_2 -> V_49 , V_92 -> V_88 . V_35 , V_92 -> V_88 . V_36 ) ;
F_10 ( V_92 ) ;
}
struct V_93 *
F_35 ( struct V_1 * V_2 )
{
struct V_93 * V_90 ;
V_90 = F_31 ( sizeof( struct V_93 ) , V_31 ) ;
if ( ! V_90 )
return NULL ;
V_90 -> V_91 . V_35 = F_6 ( V_2 -> V_46 , V_31 ,
& V_90 -> V_91 . V_36 ) ;
if ( ! V_90 -> V_91 . V_35 ) {
F_10 ( V_90 ) ;
return NULL ;
}
V_90 -> V_88 . V_35 = F_6 ( V_2 -> V_58 ,
V_31 , & V_90 -> V_88 . V_36 ) ;
if ( ! V_90 -> V_88 . V_35 ) {
F_9 ( V_2 -> V_46 , V_90 -> V_91 . V_35 ,
V_90 -> V_91 . V_36 ) ;
F_10 ( V_90 ) ;
return NULL ;
}
V_90 -> V_89 = V_59 ;
return V_90 ;
}
void
F_36 ( struct V_1 * V_2 , struct V_93 * V_92 )
{
F_9 ( V_2 -> V_46 , V_92 -> V_91 . V_35 , V_92 -> V_91 . V_36 ) ;
F_9 ( V_2 -> V_58 ,
V_92 -> V_88 . V_35 , V_92 -> V_88 . V_36 ) ;
F_10 ( V_92 ) ;
}
void
F_37 ( struct V_1 * V_2 , struct V_29 * V_72 )
{
struct V_86 * V_94 ;
unsigned long V_95 ;
if ( ! V_72 )
return;
if ( V_2 -> V_96 & V_97 ) {
V_94 = F_38 ( V_72 , struct V_86 , V_88 ) ;
F_25 ( & V_2 -> V_75 , V_95 ) ;
if ( ! V_2 -> V_98 ) {
F_26 ( & V_2 -> V_75 , V_95 ) ;
return;
}
F_17 ( & V_94 -> V_88 . V_74 ) ;
if ( V_94 -> V_99 == - 1 ) {
( V_2 -> V_100 [ V_101 ] . V_102 )
( V_2 , V_94 ) ;
} else {
F_39 ( V_2 , V_94 ) ;
}
F_26 ( & V_2 -> V_75 , V_95 ) ;
} else {
F_21 ( V_2 , V_72 -> V_35 , V_72 -> V_36 ) ;
F_10 ( V_72 ) ;
}
return;
}
void
F_40 ( struct V_1 * V_2 , struct V_29 * V_72 )
{
struct V_103 * V_104 ;
struct V_105 V_106 ;
struct V_105 V_107 ;
struct V_93 * V_108 ;
unsigned long V_95 ;
int V_109 ;
if ( ! V_72 )
return;
V_108 = F_38 ( V_72 , struct V_93 , V_91 ) ;
V_104 = V_108 -> V_110 -> V_104 ;
F_25 ( & V_2 -> V_75 , V_95 ) ;
F_17 ( & V_108 -> V_91 . V_74 ) ;
V_106 . V_111 = F_41 ( V_108 -> V_91 . V_36 ) ;
V_106 . V_112 = F_42 ( V_108 -> V_91 . V_36 ) ;
V_107 . V_111 = F_41 ( V_108 -> V_88 . V_36 ) ;
V_107 . V_112 = F_42 ( V_108 -> V_88 . V_36 ) ;
V_109 = F_43 ( V_108 -> V_110 , V_108 -> V_113 , & V_106 , & V_107 ) ;
if ( V_109 < 0 ) {
( V_104 -> V_114 ) ( V_2 , V_108 ) ;
F_12 ( V_2 , V_61 , V_62 ,
L_8 ,
V_108 -> V_110 -> V_115 ,
V_108 -> V_110 -> V_116 ,
V_108 -> V_110 -> V_117 ) ;
} else {
F_44 ( & V_108 -> V_91 . V_74 , & V_104 -> V_118 ) ;
V_104 -> V_119 ++ ;
}
F_26 ( & V_2 -> V_75 , V_95 ) ;
}
