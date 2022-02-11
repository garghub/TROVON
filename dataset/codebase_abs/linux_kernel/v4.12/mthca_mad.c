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
V_21 . type = F_8 ( & V_2 -> V_9 , V_3 ) ;
F_9 ( & V_21 , V_16 ) ;
F_10 ( & V_21 , V_17 ) ;
F_11 ( & V_21 , V_3 ) ;
V_19 = F_12 ( V_2 -> V_23 [ V_3 - 1 ] [ 0 ] -> V_24 -> V_25 ,
& V_21 ) ;
if ( F_13 ( V_19 ) )
return;
F_14 ( & V_2 -> V_26 , V_22 ) ;
if ( V_2 -> V_27 [ V_3 - 1 ] )
F_15 ( V_2 -> V_27 [ V_3 - 1 ] ) ;
V_2 -> V_27 [ V_3 - 1 ] = V_19 ;
F_16 ( & V_2 -> V_26 , V_22 ) ;
}
static void F_17 ( struct V_28 * V_29 ,
T_1 V_3 ,
const struct V_30 * V_31 ,
T_2 V_32 )
{
struct V_33 V_34 ;
if ( ( V_31 -> V_35 . V_36 == V_37 ||
V_31 -> V_35 . V_36 == V_38 ) &&
V_31 -> V_35 . V_39 == V_40 ) {
if ( V_31 -> V_35 . V_41 == V_42 ) {
struct V_43 * V_44 =
(struct V_43 * ) ( (struct V_45 * ) V_31 ) -> V_46 ;
T_2 V_16 = F_18 ( V_44 -> V_16 ) ;
F_1 ( F_19 ( V_29 ) , V_3 ) ;
F_7 ( F_19 ( V_29 ) , V_3 ,
F_18 ( V_44 -> V_47 ) ,
V_44 -> V_48 & 0xf ) ;
V_34 . V_49 = V_29 ;
V_34 . V_50 . V_3 = V_3 ;
if ( V_44 -> V_51 & 0x80 ) {
V_34 . V_34 = V_52 ;
F_20 ( & V_34 ) ;
}
if ( V_32 != V_16 ) {
V_34 . V_34 = V_53 ;
F_20 ( & V_34 ) ;
}
}
if ( V_31 -> V_35 . V_41 == V_54 ) {
V_34 . V_49 = V_29 ;
V_34 . V_34 = V_55 ;
V_34 . V_50 . V_3 = V_3 ;
F_20 ( & V_34 ) ;
}
}
}
static void F_21 ( struct V_28 * V_2 ,
struct V_30 * V_31 )
{
if ( ( V_31 -> V_35 . V_36 == V_37 ||
V_31 -> V_35 . V_36 == V_38 ) &&
V_31 -> V_35 . V_39 == V_56 &&
V_31 -> V_35 . V_41 == V_57 ) {
F_22 ( & F_19 ( V_2 ) -> V_58 ) ;
memcpy ( ( (struct V_45 * ) V_31 ) -> V_46 , V_2 -> V_59 ,
V_60 ) ;
F_23 ( & F_19 ( V_2 ) -> V_58 ) ;
}
}
static void F_24 ( struct V_1 * V_2 ,
T_1 V_3 ,
const struct V_30 * V_31 )
{
int V_61 = V_31 -> V_35 . V_36 != V_37 ;
struct V_62 * V_63 ;
struct V_64 * V_65 = V_2 -> V_23 [ V_3 - 1 ] [ V_61 ] ;
int V_6 ;
unsigned long V_22 ;
if ( V_65 ) {
V_63 = F_25 ( V_65 , V_61 , 0 , 0 , V_66 ,
V_67 , V_68 ,
V_69 ) ;
if ( F_13 ( V_63 ) )
return;
F_14 ( & V_2 -> V_26 , V_22 ) ;
memcpy ( V_63 -> V_31 , V_31 , sizeof *V_31 ) ;
if ( ( V_63 -> V_70 = V_2 -> V_27 [ V_3 - 1 ] ) )
V_6 = F_26 ( V_63 , NULL ) ;
else
V_6 = - V_71 ;
F_16 ( & V_2 -> V_26 , V_22 ) ;
if ( V_6 )
F_27 ( V_63 ) ;
}
}
int F_28 ( struct V_28 * V_29 ,
int V_72 ,
T_1 V_3 ,
const struct V_73 * V_74 ,
const struct V_75 * V_76 ,
const struct V_77 * V_78 , T_3 V_79 ,
struct V_77 * V_12 , T_3 * V_80 ,
T_2 * V_81 )
{
int V_82 ;
T_2 V_83 = V_74 ? V_74 -> V_83 : F_18 ( V_84 ) ;
T_2 V_32 = 0 ;
struct V_4 V_85 ;
const struct V_30 * V_86 = ( const struct V_30 * ) V_78 ;
struct V_30 * V_87 = (struct V_30 * ) V_12 ;
if ( F_29 ( V_79 != sizeof( * V_86 ) ||
* V_80 != sizeof( * V_87 ) ) )
return V_88 ;
if ( V_86 -> V_35 . V_39 == V_89 &&
V_83 == 0 ) {
F_24 ( F_19 ( V_29 ) , V_3 , V_86 ) ;
return V_90 | V_91 ;
}
if ( V_86 -> V_35 . V_36 == V_37 ||
V_86 -> V_35 . V_36 == V_38 ) {
if ( V_86 -> V_35 . V_39 != V_92 &&
V_86 -> V_35 . V_39 != V_40 &&
V_86 -> V_35 . V_39 != V_93 )
return V_90 ;
if ( V_86 -> V_35 . V_41 == V_94 ||
( ( V_86 -> V_35 . V_41 & V_95 ) ==
V_95 ) )
return V_90 ;
} else if ( V_86 -> V_35 . V_36 == V_96 ||
V_86 -> V_35 . V_36 == V_97 ||
V_86 -> V_35 . V_36 == V_98 ) {
if ( V_86 -> V_35 . V_39 != V_92 &&
V_86 -> V_35 . V_39 != V_40 )
return V_90 ;
} else
return V_90 ;
if ( ( V_86 -> V_35 . V_36 == V_37 ||
V_86 -> V_35 . V_36 == V_38 ) &&
V_86 -> V_35 . V_39 == V_40 &&
V_86 -> V_35 . V_41 == V_42 &&
! F_3 ( V_29 , V_3 , & V_85 ) )
V_32 = V_85 . V_16 ;
V_82 = F_30 ( F_19 ( V_29 ) ,
V_72 & V_99 ,
V_72 & V_100 ,
V_3 , V_74 , V_76 , V_86 , V_87 ) ;
if ( V_82 == - V_101 )
return V_90 ;
else if ( V_82 ) {
F_31 ( F_19 ( V_29 ) , L_2 , V_82 ) ;
return V_88 ;
}
if ( ! V_87 -> V_35 . V_102 ) {
F_17 ( V_29 , V_3 , V_86 , V_32 ) ;
F_21 ( V_29 , V_87 ) ;
}
if ( V_86 -> V_35 . V_36 == V_38 )
V_87 -> V_35 . V_102 |= F_32 ( 1 << 15 ) ;
if ( V_86 -> V_35 . V_39 == V_93 )
return V_90 | V_91 ;
return V_90 | V_103 ;
}
static void F_33 ( struct V_64 * V_65 ,
struct V_104 * V_105 )
{
F_27 ( V_105 -> V_63 ) ;
}
int F_34 ( struct V_1 * V_2 )
{
struct V_64 * V_65 ;
int V_106 , V_107 ;
int V_6 ;
F_35 ( & V_2 -> V_26 ) ;
for ( V_106 = 0 ; V_106 < V_2 -> V_108 . V_109 ; ++ V_106 )
for ( V_107 = 0 ; V_107 <= 1 ; ++ V_107 ) {
V_65 = F_36 ( & V_2 -> V_9 , V_106 + 1 ,
V_107 ? V_110 : V_111 ,
NULL , 0 , F_33 ,
NULL , NULL , 0 ) ;
if ( F_13 ( V_65 ) ) {
V_6 = F_37 ( V_65 ) ;
goto V_82;
}
V_2 -> V_23 [ V_106 ] [ V_107 ] = V_65 ;
}
for ( V_106 = 1 ; V_106 <= V_2 -> V_108 . V_109 ; ++ V_106 ) {
V_6 = F_1 ( V_2 , V_106 ) ;
if ( V_6 ) {
F_31 ( V_2 , L_3
L_4 , V_106 ) ;
goto V_82;
}
}
return 0 ;
V_82:
for ( V_106 = 0 ; V_106 < V_2 -> V_108 . V_109 ; ++ V_106 )
for ( V_107 = 0 ; V_107 <= 1 ; ++ V_107 )
if ( V_2 -> V_23 [ V_106 ] [ V_107 ] )
F_38 ( V_2 -> V_23 [ V_106 ] [ V_107 ] ) ;
return V_6 ;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_64 * V_65 ;
int V_106 , V_107 ;
for ( V_106 = 0 ; V_106 < V_2 -> V_108 . V_109 ; ++ V_106 ) {
for ( V_107 = 0 ; V_107 <= 1 ; ++ V_107 ) {
V_65 = V_2 -> V_23 [ V_106 ] [ V_107 ] ;
V_2 -> V_23 [ V_106 ] [ V_107 ] = NULL ;
F_38 ( V_65 ) ;
}
if ( V_2 -> V_27 [ V_106 ] )
F_15 ( V_2 -> V_27 [ V_106 ] ) ;
}
}
