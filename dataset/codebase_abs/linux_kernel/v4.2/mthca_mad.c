static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = NULL ;
int V_6 ;
V_5 = F_2 ( sizeof *V_5 , V_7 ) ;
if ( ! V_5 )
return - V_8 ;
V_6 = F_3 ( & V_2 -> V_9 , V_3 , V_5 ) ;
if ( V_6 ) {
F_4 ( V_10 L_1 ,
V_6 , V_2 -> V_9 . V_11 , V_3 ) ;
goto V_12;
}
V_2 -> V_13 [ V_3 - 1 ] = V_5 -> V_14 *
F_5 ( V_5 -> V_15 ) ;
V_12:
F_6 ( V_5 ) ;
return V_6 ;
}
static void F_7 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_16 , T_1 V_17 )
{
struct V_18 * V_19 ;
struct V_20 V_21 ;
unsigned long V_22 ;
if ( ! V_2 -> V_23 [ V_3 - 1 ] [ 0 ] )
return;
memset ( & V_21 , 0 , sizeof V_21 ) ;
V_21 . V_24 = V_16 ;
V_21 . V_17 = V_17 ;
V_21 . V_3 = V_3 ;
V_19 = F_8 ( V_2 -> V_23 [ V_3 - 1 ] [ 0 ] -> V_25 -> V_26 ,
& V_21 ) ;
if ( F_9 ( V_19 ) )
return;
F_10 ( & V_2 -> V_27 , V_22 ) ;
if ( V_2 -> V_28 [ V_3 - 1 ] )
F_11 ( V_2 -> V_28 [ V_3 - 1 ] ) ;
V_2 -> V_28 [ V_3 - 1 ] = V_19 ;
F_12 ( & V_2 -> V_27 , V_22 ) ;
}
static void F_13 ( struct V_29 * V_30 ,
T_1 V_3 ,
const struct V_31 * V_32 ,
T_2 V_33 )
{
struct V_34 V_35 ;
if ( ( V_32 -> V_36 . V_37 == V_38 ||
V_32 -> V_36 . V_37 == V_39 ) &&
V_32 -> V_36 . V_40 == V_41 ) {
if ( V_32 -> V_36 . V_42 == V_43 ) {
struct V_44 * V_45 =
(struct V_44 * ) ( (struct V_46 * ) V_32 ) -> V_47 ;
T_2 V_16 = F_14 ( V_45 -> V_16 ) ;
F_1 ( F_15 ( V_30 ) , V_3 ) ;
F_7 ( F_15 ( V_30 ) , V_3 ,
F_14 ( V_45 -> V_48 ) ,
V_45 -> V_49 & 0xf ) ;
V_35 . V_50 = V_30 ;
V_35 . V_51 . V_3 = V_3 ;
if ( V_45 -> V_52 & 0x80 ) {
V_35 . V_35 = V_53 ;
F_16 ( & V_35 ) ;
}
if ( V_33 != V_16 ) {
V_35 . V_35 = V_54 ;
F_16 ( & V_35 ) ;
}
}
if ( V_32 -> V_36 . V_42 == V_55 ) {
V_35 . V_50 = V_30 ;
V_35 . V_35 = V_56 ;
V_35 . V_51 . V_3 = V_3 ;
F_16 ( & V_35 ) ;
}
}
}
static void F_17 ( struct V_29 * V_2 ,
struct V_31 * V_32 )
{
if ( ( V_32 -> V_36 . V_37 == V_38 ||
V_32 -> V_36 . V_37 == V_39 ) &&
V_32 -> V_36 . V_40 == V_57 &&
V_32 -> V_36 . V_42 == V_58 ) {
F_18 ( & F_15 ( V_2 ) -> V_59 ) ;
memcpy ( ( (struct V_46 * ) V_32 ) -> V_47 , V_2 -> V_60 , 64 ) ;
F_19 ( & F_15 ( V_2 ) -> V_59 ) ;
}
}
static void F_20 ( struct V_1 * V_2 ,
T_1 V_3 ,
const struct V_31 * V_32 )
{
int V_61 = V_32 -> V_36 . V_37 != V_38 ;
struct V_62 * V_63 ;
struct V_64 * V_65 = V_2 -> V_23 [ V_3 - 1 ] [ V_61 ] ;
int V_6 ;
unsigned long V_22 ;
if ( V_65 ) {
V_63 = F_21 ( V_65 , V_61 , 0 , 0 , V_66 ,
V_67 , V_68 ,
V_69 ) ;
if ( F_9 ( V_63 ) )
return;
F_10 ( & V_2 -> V_27 , V_22 ) ;
memcpy ( V_63 -> V_32 , V_32 , sizeof *V_32 ) ;
if ( ( V_63 -> V_70 = V_2 -> V_28 [ V_3 - 1 ] ) )
V_6 = F_22 ( V_63 , NULL ) ;
else
V_6 = - V_71 ;
F_12 ( & V_2 -> V_27 , V_22 ) ;
if ( V_6 )
F_23 ( V_63 ) ;
}
}
int F_24 ( struct V_29 * V_30 ,
int V_72 ,
T_1 V_3 ,
const struct V_73 * V_74 ,
const struct V_75 * V_76 ,
const struct V_77 * V_78 , T_3 V_79 ,
struct V_77 * V_12 , T_3 * V_80 ,
T_2 * V_81 )
{
int V_82 ;
T_2 V_83 = V_74 ? V_74 -> V_83 : F_14 ( V_84 ) ;
T_2 V_33 = 0 ;
struct V_4 V_85 ;
const struct V_31 * V_86 = ( const struct V_31 * ) V_78 ;
struct V_31 * V_87 = (struct V_31 * ) V_12 ;
if ( F_25 ( V_79 != sizeof( * V_86 ) ||
* V_80 != sizeof( * V_87 ) ) )
return V_88 ;
if ( V_86 -> V_36 . V_40 == V_89 &&
V_83 == 0 ) {
F_20 ( F_15 ( V_30 ) , V_3 , V_86 ) ;
return V_90 | V_91 ;
}
if ( V_86 -> V_36 . V_37 == V_38 ||
V_86 -> V_36 . V_37 == V_39 ) {
if ( V_86 -> V_36 . V_40 != V_92 &&
V_86 -> V_36 . V_40 != V_41 &&
V_86 -> V_36 . V_40 != V_93 )
return V_90 ;
if ( V_86 -> V_36 . V_42 == V_94 ||
( ( V_86 -> V_36 . V_42 & V_95 ) ==
V_95 ) )
return V_90 ;
} else if ( V_86 -> V_36 . V_37 == V_96 ||
V_86 -> V_36 . V_37 == V_97 ||
V_86 -> V_36 . V_37 == V_98 ) {
if ( V_86 -> V_36 . V_40 != V_92 &&
V_86 -> V_36 . V_40 != V_41 )
return V_90 ;
} else
return V_90 ;
if ( ( V_86 -> V_36 . V_37 == V_38 ||
V_86 -> V_36 . V_37 == V_39 ) &&
V_86 -> V_36 . V_40 == V_41 &&
V_86 -> V_36 . V_42 == V_43 &&
! F_3 ( V_30 , V_3 , & V_85 ) )
V_33 = V_85 . V_16 ;
V_82 = F_26 ( F_15 ( V_30 ) ,
V_72 & V_99 ,
V_72 & V_100 ,
V_3 , V_74 , V_76 , V_86 , V_87 ) ;
if ( V_82 == - V_101 )
return V_90 ;
else if ( V_82 ) {
F_27 ( F_15 ( V_30 ) , L_2 , V_82 ) ;
return V_88 ;
}
if ( ! V_87 -> V_36 . V_102 ) {
F_13 ( V_30 , V_3 , V_86 , V_33 ) ;
F_17 ( V_30 , V_87 ) ;
}
if ( V_86 -> V_36 . V_37 == V_39 )
V_87 -> V_36 . V_102 |= F_28 ( 1 << 15 ) ;
if ( V_86 -> V_36 . V_40 == V_93 )
return V_90 | V_91 ;
return V_90 | V_103 ;
}
static void F_29 ( struct V_64 * V_65 ,
struct V_104 * V_105 )
{
F_23 ( V_105 -> V_63 ) ;
}
int F_30 ( struct V_1 * V_2 )
{
struct V_64 * V_65 ;
int V_106 , V_107 ;
int V_6 ;
F_31 ( & V_2 -> V_27 ) ;
for ( V_106 = 0 ; V_106 < V_2 -> V_108 . V_109 ; ++ V_106 )
for ( V_107 = 0 ; V_107 <= 1 ; ++ V_107 ) {
V_65 = F_32 ( & V_2 -> V_9 , V_106 + 1 ,
V_107 ? V_110 : V_111 ,
NULL , 0 , F_29 ,
NULL , NULL , 0 ) ;
if ( F_9 ( V_65 ) ) {
V_6 = F_33 ( V_65 ) ;
goto V_82;
}
V_2 -> V_23 [ V_106 ] [ V_107 ] = V_65 ;
}
for ( V_106 = 1 ; V_106 <= V_2 -> V_108 . V_109 ; ++ V_106 ) {
V_6 = F_1 ( V_2 , V_106 ) ;
if ( V_6 ) {
F_27 ( V_2 , L_3
L_4 , V_106 ) ;
goto V_82;
}
}
return 0 ;
V_82:
for ( V_106 = 0 ; V_106 < V_2 -> V_108 . V_109 ; ++ V_106 )
for ( V_107 = 0 ; V_107 <= 1 ; ++ V_107 )
if ( V_2 -> V_23 [ V_106 ] [ V_107 ] )
F_34 ( V_2 -> V_23 [ V_106 ] [ V_107 ] ) ;
return V_6 ;
}
void F_35 ( struct V_1 * V_2 )
{
struct V_64 * V_65 ;
int V_106 , V_107 ;
for ( V_106 = 0 ; V_106 < V_2 -> V_108 . V_109 ; ++ V_106 ) {
for ( V_107 = 0 ; V_107 <= 1 ; ++ V_107 ) {
V_65 = V_2 -> V_23 [ V_106 ] [ V_107 ] ;
V_2 -> V_23 [ V_106 ] [ V_107 ] = NULL ;
F_34 ( V_65 ) ;
}
if ( V_2 -> V_28 [ V_106 ] )
F_11 ( V_2 -> V_28 [ V_106 ] ) ;
}
}
