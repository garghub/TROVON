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
struct V_31 * V_32 ,
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
struct V_31 * V_32 )
{
int V_61 = V_32 -> V_36 . V_37 != V_38 ;
struct V_62 * V_63 ;
struct V_64 * V_65 = V_2 -> V_23 [ V_3 - 1 ] [ V_61 ] ;
int V_6 ;
unsigned long V_22 ;
if ( V_65 ) {
V_63 = F_21 ( V_65 , V_61 , 0 , 0 , V_66 ,
V_67 , V_68 ) ;
if ( F_9 ( V_63 ) )
return;
F_10 ( & V_2 -> V_27 , V_22 ) ;
memcpy ( V_63 -> V_32 , V_32 , sizeof *V_32 ) ;
if ( ( V_63 -> V_69 = V_2 -> V_28 [ V_3 - 1 ] ) )
V_6 = F_22 ( V_63 , NULL ) ;
else
V_6 = - V_70 ;
F_12 ( & V_2 -> V_27 , V_22 ) ;
if ( V_6 )
F_23 ( V_63 ) ;
}
}
int F_24 ( struct V_29 * V_30 ,
int V_71 ,
T_1 V_3 ,
struct V_72 * V_73 ,
struct V_74 * V_75 ,
struct V_31 * V_76 ,
struct V_31 * V_77 )
{
int V_78 ;
T_2 V_79 = V_73 ? V_73 -> V_79 : F_14 ( V_80 ) ;
T_2 V_33 = 0 ;
struct V_4 V_81 ;
if ( V_76 -> V_36 . V_40 == V_82 &&
V_79 == 0 ) {
F_20 ( F_15 ( V_30 ) , V_3 , V_76 ) ;
return V_83 | V_84 ;
}
if ( V_76 -> V_36 . V_37 == V_38 ||
V_76 -> V_36 . V_37 == V_39 ) {
if ( V_76 -> V_36 . V_40 != V_85 &&
V_76 -> V_36 . V_40 != V_41 &&
V_76 -> V_36 . V_40 != V_86 )
return V_83 ;
if ( V_76 -> V_36 . V_42 == V_87 ||
( ( V_76 -> V_36 . V_42 & V_88 ) ==
V_88 ) )
return V_83 ;
} else if ( V_76 -> V_36 . V_37 == V_89 ||
V_76 -> V_36 . V_37 == V_90 ||
V_76 -> V_36 . V_37 == V_91 ) {
if ( V_76 -> V_36 . V_40 != V_85 &&
V_76 -> V_36 . V_40 != V_41 )
return V_83 ;
} else
return V_83 ;
if ( ( V_76 -> V_36 . V_37 == V_38 ||
V_76 -> V_36 . V_37 == V_39 ) &&
V_76 -> V_36 . V_40 == V_41 &&
V_76 -> V_36 . V_42 == V_43 &&
! F_3 ( V_30 , V_3 , & V_81 ) )
V_33 = V_81 . V_16 ;
V_78 = F_25 ( F_15 ( V_30 ) ,
V_71 & V_92 ,
V_71 & V_93 ,
V_3 , V_73 , V_75 , V_76 , V_77 ) ;
if ( V_78 == - V_94 )
return V_83 ;
else if ( V_78 ) {
F_26 ( F_15 ( V_30 ) , L_2 , V_78 ) ;
return V_95 ;
}
if ( ! V_77 -> V_36 . V_96 ) {
F_13 ( V_30 , V_3 , V_76 , V_33 ) ;
F_17 ( V_30 , V_77 ) ;
}
if ( V_76 -> V_36 . V_37 == V_39 )
V_77 -> V_36 . V_96 |= F_27 ( 1 << 15 ) ;
if ( V_76 -> V_36 . V_40 == V_86 )
return V_83 | V_84 ;
return V_83 | V_97 ;
}
static void F_28 ( struct V_64 * V_65 ,
struct V_98 * V_99 )
{
F_23 ( V_99 -> V_63 ) ;
}
int F_29 ( struct V_1 * V_2 )
{
struct V_64 * V_65 ;
int V_100 , V_101 ;
int V_6 ;
F_30 ( & V_2 -> V_27 ) ;
for ( V_100 = 0 ; V_100 < V_2 -> V_102 . V_103 ; ++ V_100 )
for ( V_101 = 0 ; V_101 <= 1 ; ++ V_101 ) {
V_65 = F_31 ( & V_2 -> V_9 , V_100 + 1 ,
V_101 ? V_104 : V_105 ,
NULL , 0 , F_28 ,
NULL , NULL , 0 ) ;
if ( F_9 ( V_65 ) ) {
V_6 = F_32 ( V_65 ) ;
goto V_78;
}
V_2 -> V_23 [ V_100 ] [ V_101 ] = V_65 ;
}
for ( V_100 = 1 ; V_100 <= V_2 -> V_102 . V_103 ; ++ V_100 ) {
V_6 = F_1 ( V_2 , V_100 ) ;
if ( V_6 ) {
F_26 ( V_2 , L_3
L_4 , V_100 ) ;
goto V_78;
}
}
return 0 ;
V_78:
for ( V_100 = 0 ; V_100 < V_2 -> V_102 . V_103 ; ++ V_100 )
for ( V_101 = 0 ; V_101 <= 1 ; ++ V_101 )
if ( V_2 -> V_23 [ V_100 ] [ V_101 ] )
F_33 ( V_2 -> V_23 [ V_100 ] [ V_101 ] ) ;
return V_6 ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_64 * V_65 ;
int V_100 , V_101 ;
for ( V_100 = 0 ; V_100 < V_2 -> V_102 . V_103 ; ++ V_100 ) {
for ( V_101 = 0 ; V_101 <= 1 ; ++ V_101 ) {
V_65 = V_2 -> V_23 [ V_100 ] [ V_101 ] ;
V_2 -> V_23 [ V_100 ] [ V_101 ] = NULL ;
F_33 ( V_65 ) ;
}
if ( V_2 -> V_28 [ V_100 ] )
F_11 ( V_2 -> V_28 [ V_100 ] ) ;
}
}
