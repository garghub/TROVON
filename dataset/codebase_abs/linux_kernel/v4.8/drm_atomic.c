static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 =
F_2 ( V_1 , struct V_2 , V_4 ) ;
F_3 ( V_3 ) ;
}
void F_4 ( struct V_2 * V_3 )
{
F_5 ( & V_3 -> V_4 , F_1 ) ;
}
void F_6 ( struct V_5 * V_6 )
{
F_3 ( V_6 -> V_7 ) ;
F_3 ( V_6 -> V_8 ) ;
F_3 ( V_6 -> V_9 ) ;
}
int
F_7 ( struct V_10 * V_11 , struct V_5 * V_6 )
{
V_6 -> V_12 = true ;
V_6 -> V_8 = F_8 ( V_11 -> V_13 . V_14 ,
sizeof( * V_6 -> V_8 ) , V_15 ) ;
if ( ! V_6 -> V_8 )
goto V_16;
V_6 -> V_9 = F_8 ( V_11 -> V_13 . V_17 ,
sizeof( * V_6 -> V_9 ) , V_15 ) ;
if ( ! V_6 -> V_9 )
goto V_16;
V_6 -> V_11 = V_11 ;
F_9 ( L_1 , V_6 ) ;
return 0 ;
V_16:
F_6 ( V_6 ) ;
return - V_18 ;
}
struct V_5 *
F_10 ( struct V_10 * V_11 )
{
struct V_19 * V_20 = & V_11 -> V_13 ;
struct V_5 * V_6 ;
if ( ! V_20 -> V_21 -> V_22 ) {
V_6 = F_11 ( sizeof( * V_6 ) , V_15 ) ;
if ( ! V_6 )
return NULL ;
if ( F_7 ( V_11 , V_6 ) < 0 ) {
F_3 ( V_6 ) ;
return NULL ;
}
return V_6 ;
}
return V_20 -> V_21 -> V_22 ( V_11 ) ;
}
void F_12 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
int V_23 ;
F_9 ( L_2 , V_6 ) ;
for ( V_23 = 0 ; V_23 < V_6 -> V_24 ; V_23 ++ ) {
struct V_25 * V_26 = V_6 -> V_7 [ V_23 ] . V_27 ;
if ( ! V_26 )
continue;
V_26 -> V_21 -> V_28 ( V_26 ,
V_6 -> V_7 [ V_23 ] . V_6 ) ;
V_6 -> V_7 [ V_23 ] . V_27 = NULL ;
V_6 -> V_7 [ V_23 ] . V_6 = NULL ;
F_13 ( V_26 ) ;
}
for ( V_23 = 0 ; V_23 < V_20 -> V_14 ; V_23 ++ ) {
struct V_29 * V_30 = V_6 -> V_8 [ V_23 ] . V_27 ;
if ( ! V_30 )
continue;
V_30 -> V_21 -> V_28 ( V_30 ,
V_6 -> V_8 [ V_23 ] . V_6 ) ;
if ( V_6 -> V_8 [ V_23 ] . V_3 ) {
F_3 ( V_6 -> V_8 [ V_23 ] . V_3 -> V_31 ) ;
V_6 -> V_8 [ V_23 ] . V_3 -> V_31 = NULL ;
F_4 ( V_6 -> V_8 [ V_23 ] . V_3 ) ;
}
V_6 -> V_8 [ V_23 ] . V_3 = NULL ;
V_6 -> V_8 [ V_23 ] . V_27 = NULL ;
V_6 -> V_8 [ V_23 ] . V_6 = NULL ;
}
for ( V_23 = 0 ; V_23 < V_20 -> V_17 ; V_23 ++ ) {
struct V_32 * V_33 = V_6 -> V_9 [ V_23 ] . V_27 ;
if ( ! V_33 )
continue;
V_33 -> V_21 -> V_28 ( V_33 ,
V_6 -> V_9 [ V_23 ] . V_6 ) ;
V_6 -> V_9 [ V_23 ] . V_27 = NULL ;
V_6 -> V_9 [ V_23 ] . V_6 = NULL ;
}
}
void F_14 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
if ( V_20 -> V_21 -> V_34 )
V_20 -> V_21 -> V_34 ( V_6 ) ;
else
F_12 ( V_6 ) ;
}
void F_15 ( struct V_5 * V_6 )
{
struct V_10 * V_11 ;
struct V_19 * V_20 ;
if ( ! V_6 )
return;
V_11 = V_6 -> V_11 ;
V_20 = & V_11 -> V_13 ;
F_14 ( V_6 ) ;
F_9 ( L_3 , V_6 ) ;
if ( V_20 -> V_21 -> V_35 ) {
V_20 -> V_21 -> V_35 ( V_6 ) ;
} else {
F_6 ( V_6 ) ;
F_3 ( V_6 ) ;
}
}
struct V_36 *
F_16 ( struct V_5 * V_6 ,
struct V_29 * V_30 )
{
int V_37 , V_38 = F_17 ( V_30 ) ;
struct V_36 * V_39 ;
F_18 ( ! V_6 -> V_40 ) ;
V_39 = F_19 ( V_6 , V_30 ) ;
if ( V_39 )
return V_39 ;
V_37 = F_20 ( & V_30 -> V_41 , V_6 -> V_40 ) ;
if ( V_37 )
return F_21 ( V_37 ) ;
V_39 = V_30 -> V_21 -> V_42 ( V_30 ) ;
if ( ! V_39 )
return F_21 ( - V_18 ) ;
V_6 -> V_8 [ V_38 ] . V_6 = V_39 ;
V_6 -> V_8 [ V_38 ] . V_27 = V_30 ;
V_39 -> V_6 = V_6 ;
F_9 ( L_4 ,
V_30 -> V_43 . V_44 , V_30 -> V_45 , V_39 , V_6 ) ;
return V_39 ;
}
int F_22 ( struct V_36 * V_6 ,
struct V_46 * V_47 )
{
struct V_48 V_49 ;
if ( V_47 && memcmp ( & V_6 -> V_47 , V_47 , sizeof( * V_47 ) ) == 0 )
return 0 ;
F_23 ( V_6 -> V_50 ) ;
V_6 -> V_50 = NULL ;
if ( V_47 ) {
F_24 ( & V_49 , V_47 ) ;
V_6 -> V_50 =
F_25 ( V_6 -> V_30 -> V_11 ,
sizeof( V_49 ) ,
& V_49 ) ;
if ( F_26 ( V_6 -> V_50 ) )
return F_27 ( V_6 -> V_50 ) ;
F_28 ( & V_6 -> V_47 , V_47 ) ;
V_6 -> V_51 = true ;
F_9 ( L_5 ,
V_47 -> V_45 , V_6 ) ;
} else {
memset ( & V_6 -> V_47 , 0 , sizeof( V_6 -> V_47 ) ) ;
V_6 -> V_51 = false ;
F_9 ( L_6 ,
V_6 ) ;
}
return 0 ;
}
int F_29 ( struct V_36 * V_6 ,
struct V_52 * V_53 )
{
if ( V_53 == V_6 -> V_50 )
return 0 ;
F_23 ( V_6 -> V_50 ) ;
V_6 -> V_50 = NULL ;
memset ( & V_6 -> V_47 , 0 , sizeof( V_6 -> V_47 ) ) ;
if ( V_53 ) {
if ( V_53 -> V_54 != sizeof( struct V_48 ) ||
F_30 ( & V_6 -> V_47 ,
( const struct V_48 * )
V_53 -> V_55 ) )
return - V_56 ;
V_6 -> V_50 = F_31 ( V_53 ) ;
V_6 -> V_51 = true ;
F_9 ( L_5 ,
V_6 -> V_47 . V_45 , V_6 ) ;
} else {
V_6 -> V_51 = false ;
F_9 ( L_6 ,
V_6 ) ;
}
return 0 ;
}
static void
F_32 ( struct V_52 * * V_53 ,
struct V_52 * V_57 ,
bool * V_58 )
{
struct V_52 * V_59 = * V_53 ;
if ( V_59 == V_57 )
return;
F_23 ( V_59 ) ;
if ( V_57 )
F_31 ( V_57 ) ;
* V_53 = V_57 ;
* V_58 = true ;
return;
}
static int
F_33 ( struct V_29 * V_30 ,
struct V_52 * * V_53 ,
T_1 V_60 ,
T_2 V_61 ,
bool * V_58 )
{
struct V_10 * V_11 = V_30 -> V_11 ;
struct V_52 * V_57 = NULL ;
if ( V_60 != 0 ) {
V_57 = F_34 ( V_11 , V_60 ) ;
if ( V_57 == NULL )
return - V_56 ;
if ( V_61 > 0 && V_61 != V_57 -> V_54 )
return - V_56 ;
}
F_32 ( V_53 , V_57 , V_58 ) ;
return 0 ;
}
int F_35 ( struct V_29 * V_30 ,
struct V_36 * V_6 , struct V_62 * V_63 ,
T_1 V_64 )
{
struct V_10 * V_11 = V_30 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
bool V_58 = false ;
int V_37 ;
if ( V_63 == V_20 -> V_65 )
V_6 -> V_66 = V_64 ;
else if ( V_63 == V_20 -> V_67 ) {
struct V_52 * V_47 =
F_34 ( V_11 , V_64 ) ;
V_37 = F_29 ( V_6 , V_47 ) ;
F_23 ( V_47 ) ;
return V_37 ;
} else if ( V_63 == V_20 -> V_68 ) {
V_37 = F_33 ( V_30 ,
& V_6 -> V_69 ,
V_64 ,
- 1 ,
& V_58 ) ;
V_6 -> V_70 |= V_58 ;
return V_37 ;
} else if ( V_63 == V_20 -> V_71 ) {
V_37 = F_33 ( V_30 ,
& V_6 -> V_72 ,
V_64 ,
sizeof( struct V_73 ) ,
& V_58 ) ;
V_6 -> V_70 |= V_58 ;
return V_37 ;
} else if ( V_63 == V_20 -> V_74 ) {
V_37 = F_33 ( V_30 ,
& V_6 -> V_75 ,
V_64 ,
- 1 ,
& V_58 ) ;
V_6 -> V_70 |= V_58 ;
return V_37 ;
} else if ( V_30 -> V_21 -> V_76 )
return V_30 -> V_21 -> V_76 ( V_30 , V_6 , V_63 , V_64 ) ;
else
return - V_56 ;
return 0 ;
}
static int
F_36 ( struct V_29 * V_30 ,
const struct V_36 * V_6 ,
struct V_62 * V_63 , T_1 * V_64 )
{
struct V_10 * V_11 = V_30 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
if ( V_63 == V_20 -> V_65 )
* V_64 = V_6 -> V_66 ;
else if ( V_63 == V_20 -> V_67 )
* V_64 = ( V_6 -> V_50 ) ? V_6 -> V_50 -> V_43 . V_44 : 0 ;
else if ( V_63 == V_20 -> V_68 )
* V_64 = ( V_6 -> V_69 ) ? V_6 -> V_69 -> V_43 . V_44 : 0 ;
else if ( V_63 == V_20 -> V_71 )
* V_64 = ( V_6 -> V_72 ) ? V_6 -> V_72 -> V_43 . V_44 : 0 ;
else if ( V_63 == V_20 -> V_74 )
* V_64 = ( V_6 -> V_75 ) ? V_6 -> V_75 -> V_43 . V_44 : 0 ;
else if ( V_30 -> V_21 -> V_77 )
return V_30 -> V_21 -> V_77 ( V_30 , V_6 , V_63 , V_64 ) ;
else
return - V_56 ;
return 0 ;
}
static int F_37 ( struct V_29 * V_30 ,
struct V_36 * V_6 )
{
if ( V_6 -> V_66 && ! V_6 -> V_51 ) {
F_9 ( L_7 ,
V_30 -> V_43 . V_44 , V_30 -> V_45 ) ;
return - V_56 ;
}
if ( F_38 ( V_30 -> V_11 , V_78 ) &&
F_18 ( V_6 -> V_51 && ! V_6 -> V_50 ) ) {
F_9 ( L_8 ,
V_30 -> V_43 . V_44 , V_30 -> V_45 ) ;
return - V_56 ;
}
if ( F_38 ( V_30 -> V_11 , V_78 ) &&
F_18 ( ! V_6 -> V_51 && V_6 -> V_50 ) ) {
F_9 ( L_9 ,
V_30 -> V_43 . V_44 , V_30 -> V_45 ) ;
return - V_56 ;
}
if ( V_6 -> V_31 && ! V_6 -> V_66 && ! V_30 -> V_6 -> V_66 ) {
F_9 ( L_10 ,
V_30 -> V_43 . V_44 ) ;
return - V_56 ;
}
return 0 ;
}
struct V_79 *
F_39 ( struct V_5 * V_6 ,
struct V_32 * V_33 )
{
int V_37 , V_38 = F_40 ( V_33 ) ;
struct V_79 * V_80 ;
F_18 ( ! V_6 -> V_40 ) ;
V_80 = F_41 ( V_6 , V_33 ) ;
if ( V_80 )
return V_80 ;
V_37 = F_20 ( & V_33 -> V_41 , V_6 -> V_40 ) ;
if ( V_37 )
return F_21 ( V_37 ) ;
V_80 = V_33 -> V_21 -> V_42 ( V_33 ) ;
if ( ! V_80 )
return F_21 ( - V_18 ) ;
V_6 -> V_9 [ V_38 ] . V_6 = V_80 ;
V_6 -> V_9 [ V_38 ] . V_27 = V_33 ;
V_80 -> V_6 = V_6 ;
F_9 ( L_11 ,
V_33 -> V_43 . V_44 , V_33 -> V_45 , V_80 , V_6 ) ;
if ( V_80 -> V_30 ) {
struct V_36 * V_39 ;
V_39 = F_16 ( V_6 ,
V_80 -> V_30 ) ;
if ( F_26 ( V_39 ) )
return F_42 ( V_39 ) ;
}
return V_80 ;
}
int F_43 ( struct V_32 * V_33 ,
struct V_79 * V_6 , struct V_62 * V_63 ,
T_1 V_64 )
{
struct V_10 * V_11 = V_33 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
if ( V_63 == V_20 -> V_81 ) {
struct V_82 * V_83 = F_44 ( V_11 , V_64 ) ;
F_45 ( V_6 , V_83 ) ;
if ( V_83 )
F_46 ( V_83 ) ;
} else if ( V_63 == V_20 -> V_84 ) {
struct V_29 * V_30 = F_47 ( V_11 , V_64 ) ;
return F_48 ( V_6 , V_30 ) ;
} else if ( V_63 == V_20 -> V_85 ) {
V_6 -> V_86 = F_49 ( V_64 ) ;
} else if ( V_63 == V_20 -> V_87 ) {
V_6 -> V_88 = F_49 ( V_64 ) ;
} else if ( V_63 == V_20 -> V_89 ) {
V_6 -> V_90 = V_64 ;
} else if ( V_63 == V_20 -> V_91 ) {
V_6 -> V_92 = V_64 ;
} else if ( V_63 == V_20 -> V_93 ) {
V_6 -> V_94 = V_64 ;
} else if ( V_63 == V_20 -> V_95 ) {
V_6 -> V_96 = V_64 ;
} else if ( V_63 == V_20 -> V_97 ) {
V_6 -> V_98 = V_64 ;
} else if ( V_63 == V_20 -> V_99 ) {
V_6 -> V_100 = V_64 ;
} else if ( V_63 == V_20 -> V_101 ) {
V_6 -> V_102 = V_64 ;
} else if ( V_63 == V_33 -> V_103 ) {
V_6 -> V_104 = V_64 ;
} else if ( V_33 -> V_21 -> V_76 ) {
return V_33 -> V_21 -> V_76 ( V_33 , V_6 ,
V_63 , V_64 ) ;
} else {
return - V_56 ;
}
return 0 ;
}
static int
F_50 ( struct V_32 * V_33 ,
const struct V_79 * V_6 ,
struct V_62 * V_63 , T_1 * V_64 )
{
struct V_10 * V_11 = V_33 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
if ( V_63 == V_20 -> V_81 ) {
* V_64 = ( V_6 -> V_83 ) ? V_6 -> V_83 -> V_43 . V_44 : 0 ;
} else if ( V_63 == V_20 -> V_84 ) {
* V_64 = ( V_6 -> V_30 ) ? V_6 -> V_30 -> V_43 . V_44 : 0 ;
} else if ( V_63 == V_20 -> V_85 ) {
* V_64 = F_51 ( V_6 -> V_86 ) ;
} else if ( V_63 == V_20 -> V_87 ) {
* V_64 = F_51 ( V_6 -> V_88 ) ;
} else if ( V_63 == V_20 -> V_89 ) {
* V_64 = V_6 -> V_90 ;
} else if ( V_63 == V_20 -> V_91 ) {
* V_64 = V_6 -> V_92 ;
} else if ( V_63 == V_20 -> V_93 ) {
* V_64 = V_6 -> V_94 ;
} else if ( V_63 == V_20 -> V_95 ) {
* V_64 = V_6 -> V_96 ;
} else if ( V_63 == V_20 -> V_97 ) {
* V_64 = V_6 -> V_98 ;
} else if ( V_63 == V_20 -> V_99 ) {
* V_64 = V_6 -> V_100 ;
} else if ( V_63 == V_20 -> V_101 ) {
* V_64 = V_6 -> V_102 ;
} else if ( V_63 == V_33 -> V_103 ) {
* V_64 = V_6 -> V_104 ;
} else if ( V_33 -> V_21 -> V_77 ) {
return V_33 -> V_21 -> V_77 ( V_33 , V_6 , V_63 , V_64 ) ;
} else {
return - V_56 ;
}
return 0 ;
}
static bool
F_52 ( struct V_5 * V_6 ,
struct V_32 * V_33 ,
struct V_79 * V_80 )
{
if ( ! V_33 -> V_6 -> V_30 || ! V_80 -> V_30 )
return false ;
if ( V_33 -> V_6 -> V_30 == V_80 -> V_30 )
return false ;
return true ;
}
static int F_53 ( struct V_32 * V_33 ,
struct V_79 * V_6 )
{
unsigned int V_105 , V_106 ;
int V_37 ;
if ( F_18 ( V_6 -> V_30 && ! V_6 -> V_83 ) ) {
F_9 ( L_12 ) ;
return - V_56 ;
} else if ( F_18 ( V_6 -> V_83 && ! V_6 -> V_30 ) ) {
F_9 ( L_13 ) ;
return - V_56 ;
}
if ( ! V_6 -> V_30 )
return 0 ;
if ( ! ( V_33 -> V_107 & F_54 ( V_6 -> V_30 ) ) ) {
F_9 ( L_14 ) ;
return - V_56 ;
}
V_37 = F_55 ( V_33 , V_6 -> V_83 -> V_108 ) ;
if ( V_37 ) {
F_9 ( L_15 ,
F_56 ( V_6 -> V_83 -> V_108 ) ) ;
return V_37 ;
}
if ( V_6 -> V_90 > V_109 ||
V_6 -> V_86 > V_109 - ( V_110 ) V_6 -> V_90 ||
V_6 -> V_92 > V_109 ||
V_6 -> V_88 > V_109 - ( V_110 ) V_6 -> V_92 ) {
F_9 ( L_16 ,
V_6 -> V_90 , V_6 -> V_92 ,
V_6 -> V_86 , V_6 -> V_88 ) ;
return - V_111 ;
}
V_105 = V_6 -> V_83 -> V_112 << 16 ;
V_106 = V_6 -> V_83 -> V_113 << 16 ;
if ( V_6 -> V_98 > V_105 ||
V_6 -> V_94 > V_105 - V_6 -> V_98 ||
V_6 -> V_100 > V_106 ||
V_6 -> V_96 > V_106 - V_6 -> V_100 ) {
F_9 ( L_17
L_18 ,
V_6 -> V_98 >> 16 , ( ( V_6 -> V_98 & 0xffff ) * 15625 ) >> 10 ,
V_6 -> V_100 >> 16 , ( ( V_6 -> V_100 & 0xffff ) * 15625 ) >> 10 ,
V_6 -> V_94 >> 16 , ( ( V_6 -> V_94 & 0xffff ) * 15625 ) >> 10 ,
V_6 -> V_96 >> 16 , ( ( V_6 -> V_96 & 0xffff ) * 15625 ) >> 10 ) ;
return - V_114 ;
}
if ( F_52 ( V_6 -> V_6 , V_33 , V_6 ) ) {
F_9 ( L_19 ,
V_33 -> V_43 . V_44 , V_33 -> V_45 ) ;
return - V_56 ;
}
return 0 ;
}
struct V_115 *
F_57 ( struct V_5 * V_6 ,
struct V_25 * V_26 )
{
int V_37 , V_38 ;
struct V_19 * V_20 = & V_26 -> V_11 -> V_13 ;
struct V_115 * V_116 ;
F_18 ( ! V_6 -> V_40 ) ;
V_37 = F_20 ( & V_20 -> V_117 , V_6 -> V_40 ) ;
if ( V_37 )
return F_21 ( V_37 ) ;
V_38 = F_58 ( V_26 ) ;
if ( V_38 >= V_6 -> V_24 ) {
struct V_118 * V_119 ;
int V_120 = F_59 ( V_38 + 1 , V_20 -> V_24 ) ;
V_119 = F_60 ( V_6 -> V_7 , V_120 * sizeof( * V_6 -> V_7 ) , V_15 ) ;
if ( ! V_119 )
return F_21 ( - V_18 ) ;
V_6 -> V_7 = V_119 ;
memset ( & V_6 -> V_7 [ V_6 -> V_24 ] , 0 ,
sizeof( * V_6 -> V_7 ) * ( V_120 - V_6 -> V_24 ) ) ;
V_6 -> V_24 = V_120 ;
}
if ( V_6 -> V_7 [ V_38 ] . V_6 )
return V_6 -> V_7 [ V_38 ] . V_6 ;
V_116 = V_26 -> V_21 -> V_42 ( V_26 ) ;
if ( ! V_116 )
return F_21 ( - V_18 ) ;
F_61 ( V_26 ) ;
V_6 -> V_7 [ V_38 ] . V_6 = V_116 ;
V_6 -> V_7 [ V_38 ] . V_27 = V_26 ;
V_116 -> V_6 = V_6 ;
F_9 ( L_20 ,
V_26 -> V_43 . V_44 , V_116 , V_6 ) ;
if ( V_116 -> V_30 ) {
struct V_36 * V_39 ;
V_39 = F_16 ( V_6 ,
V_116 -> V_30 ) ;
if ( F_26 ( V_39 ) )
return F_42 ( V_39 ) ;
}
return V_116 ;
}
int F_62 ( struct V_25 * V_26 ,
struct V_115 * V_6 , struct V_62 * V_63 ,
T_1 V_64 )
{
struct V_10 * V_11 = V_26 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
if ( V_63 == V_20 -> V_84 ) {
struct V_29 * V_30 = F_47 ( V_11 , V_64 ) ;
return F_63 ( V_6 , V_30 ) ;
} else if ( V_63 == V_20 -> V_121 ) {
return - V_56 ;
} else if ( V_26 -> V_21 -> V_76 ) {
return V_26 -> V_21 -> V_76 ( V_26 ,
V_6 , V_63 , V_64 ) ;
} else {
return - V_56 ;
}
}
static int
F_64 ( struct V_25 * V_26 ,
const struct V_115 * V_6 ,
struct V_62 * V_63 , T_1 * V_64 )
{
struct V_10 * V_11 = V_26 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
if ( V_63 == V_20 -> V_84 ) {
* V_64 = ( V_6 -> V_30 ) ? V_6 -> V_30 -> V_43 . V_44 : 0 ;
} else if ( V_63 == V_20 -> V_121 ) {
* V_64 = V_26 -> V_122 ;
} else if ( V_26 -> V_21 -> V_77 ) {
return V_26 -> V_21 -> V_77 ( V_26 ,
V_6 , V_63 , V_64 ) ;
} else {
return - V_56 ;
}
return 0 ;
}
int F_65 ( struct V_123 * V_124 ,
struct V_62 * V_63 , T_1 * V_64 )
{
struct V_10 * V_11 = V_63 -> V_11 ;
int V_37 ;
switch ( V_124 -> type ) {
case V_125 : {
struct V_25 * V_26 = F_66 ( V_124 ) ;
F_18 ( ! F_67 ( & V_11 -> V_13 . V_117 ) ) ;
V_37 = F_64 ( V_26 ,
V_26 -> V_6 , V_63 , V_64 ) ;
break;
}
case V_126 : {
struct V_29 * V_30 = F_68 ( V_124 ) ;
F_18 ( ! F_67 ( & V_30 -> V_41 ) ) ;
V_37 = F_36 ( V_30 ,
V_30 -> V_6 , V_63 , V_64 ) ;
break;
}
case V_127 : {
struct V_32 * V_33 = F_69 ( V_124 ) ;
F_18 ( ! F_67 ( & V_33 -> V_41 ) ) ;
V_37 = F_50 ( V_33 ,
V_33 -> V_6 , V_63 , V_64 ) ;
break;
}
default:
V_37 = - V_56 ;
break;
}
return V_37 ;
}
int
F_48 ( struct V_79 * V_80 ,
struct V_29 * V_30 )
{
struct V_32 * V_33 = V_80 -> V_33 ;
struct V_36 * V_39 ;
if ( V_80 -> V_30 ) {
V_39 = F_16 ( V_80 -> V_6 ,
V_80 -> V_30 ) ;
if ( F_18 ( F_26 ( V_39 ) ) )
return F_27 ( V_39 ) ;
V_39 -> V_128 &= ~ ( 1 << F_40 ( V_33 ) ) ;
}
V_80 -> V_30 = V_30 ;
if ( V_30 ) {
V_39 = F_16 ( V_80 -> V_6 ,
V_30 ) ;
if ( F_26 ( V_39 ) )
return F_27 ( V_39 ) ;
V_39 -> V_128 |= ( 1 << F_40 ( V_33 ) ) ;
}
if ( V_30 )
F_9 ( L_21 ,
V_80 , V_30 -> V_43 . V_44 , V_30 -> V_45 ) ;
else
F_9 ( L_22 ,
V_80 ) ;
return 0 ;
}
void
F_45 ( struct V_79 * V_80 ,
struct V_82 * V_83 )
{
if ( V_80 -> V_83 )
F_46 ( V_80 -> V_83 ) ;
if ( V_83 )
F_70 ( V_83 ) ;
V_80 -> V_83 = V_83 ;
if ( V_83 )
F_9 ( L_23 ,
V_83 -> V_43 . V_44 , V_80 ) ;
else
F_9 ( L_24 ,
V_80 ) ;
}
int
F_63 ( struct V_115 * V_129 ,
struct V_29 * V_30 )
{
struct V_36 * V_39 ;
if ( V_129 -> V_30 == V_30 )
return 0 ;
if ( V_129 -> V_30 ) {
V_39 = F_19 ( V_129 -> V_6 ,
V_129 -> V_30 ) ;
V_39 -> V_130 &=
~ ( 1 << F_58 ( V_129 -> V_26 ) ) ;
F_13 ( V_129 -> V_26 ) ;
V_129 -> V_30 = NULL ;
}
if ( V_30 ) {
V_39 = F_16 ( V_129 -> V_6 , V_30 ) ;
if ( F_26 ( V_39 ) )
return F_27 ( V_39 ) ;
V_39 -> V_130 |=
1 << F_58 ( V_129 -> V_26 ) ;
F_61 ( V_129 -> V_26 ) ;
V_129 -> V_30 = V_30 ;
F_9 ( L_25 ,
V_129 , V_30 -> V_43 . V_44 , V_30 -> V_45 ) ;
} else {
F_9 ( L_26 ,
V_129 ) ;
}
return 0 ;
}
int
F_71 ( struct V_5 * V_6 ,
struct V_29 * V_30 )
{
struct V_19 * V_20 = & V_6 -> V_11 -> V_13 ;
struct V_25 * V_26 ;
struct V_115 * V_129 ;
int V_37 ;
V_37 = F_20 ( & V_20 -> V_117 , V_6 -> V_40 ) ;
if ( V_37 )
return V_37 ;
F_9 ( L_27 ,
V_30 -> V_43 . V_44 , V_30 -> V_45 , V_6 ) ;
F_72 (connector, state->dev) {
if ( V_26 -> V_6 -> V_30 != V_30 )
continue;
V_129 = F_57 ( V_6 , V_26 ) ;
if ( F_26 ( V_129 ) )
return F_27 ( V_129 ) ;
}
return 0 ;
}
int
F_73 ( struct V_5 * V_6 ,
struct V_29 * V_30 )
{
struct V_32 * V_33 ;
F_18 ( ! F_19 ( V_6 , V_30 ) ) ;
F_74 (plane, state->dev, crtc->state->plane_mask) {
struct V_79 * V_80 =
F_39 ( V_6 , V_33 ) ;
if ( F_26 ( V_80 ) )
return F_27 ( V_80 ) ;
}
return 0 ;
}
void F_75 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
unsigned V_131 = 0 ;
struct V_29 * V_30 ;
int V_37 ;
bool V_132 = false ;
F_76 (crtc, dev) {
if ( V_30 -> V_40 != V_6 -> V_40 )
continue;
V_131 |= F_54 ( V_30 ) ;
V_30 -> V_40 = NULL ;
}
if ( F_18 ( V_11 -> V_13 . V_40 == V_6 -> V_40 ) ) {
V_132 = true ;
V_11 -> V_13 . V_40 = NULL ;
}
V_133:
F_77 ( V_6 -> V_40 ) ;
V_37 = F_78 ( V_11 , V_6 -> V_40 ) ;
if ( V_37 )
goto V_133;
F_76 (crtc, dev)
if ( F_54 ( V_30 ) & V_131 )
V_30 -> V_40 = V_6 -> V_40 ;
if ( V_132 )
V_11 -> V_13 . V_40 = V_6 -> V_40 ;
}
int F_79 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_19 * V_20 = & V_11 -> V_13 ;
struct V_32 * V_33 ;
struct V_79 * V_80 ;
struct V_29 * V_30 ;
struct V_36 * V_39 ;
int V_23 , V_37 = 0 ;
F_9 ( L_28 , V_6 ) ;
F_80 (state, plane, plane_state, i) {
V_37 = F_53 ( V_33 , V_80 ) ;
if ( V_37 ) {
F_9 ( L_29 ,
V_33 -> V_43 . V_44 , V_33 -> V_45 ) ;
return V_37 ;
}
}
F_81 (state, crtc, crtc_state, i) {
V_37 = F_37 ( V_30 , V_39 ) ;
if ( V_37 ) {
F_9 ( L_30 ,
V_30 -> V_43 . V_44 , V_30 -> V_45 ) ;
return V_37 ;
}
}
if ( V_20 -> V_21 -> V_134 )
V_37 = V_20 -> V_21 -> V_134 ( V_6 -> V_11 , V_6 ) ;
if ( ! V_6 -> V_12 ) {
F_81 (state, crtc, crtc_state, i) {
if ( F_82 ( V_39 ) ) {
F_9 ( L_31 ,
V_30 -> V_43 . V_44 , V_30 -> V_45 ) ;
return - V_56 ;
}
}
}
return V_37 ;
}
int F_83 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = & V_6 -> V_11 -> V_13 ;
int V_37 ;
V_37 = F_79 ( V_6 ) ;
if ( V_37 )
return V_37 ;
F_9 ( L_32 , V_6 ) ;
return V_20 -> V_21 -> V_135 ( V_6 -> V_11 , V_6 , false ) ;
}
int F_84 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = & V_6 -> V_11 -> V_13 ;
int V_37 ;
V_37 = F_79 ( V_6 ) ;
if ( V_37 )
return V_37 ;
F_9 ( L_33 , V_6 ) ;
return V_20 -> V_21 -> V_135 ( V_6 -> V_11 , V_6 , true ) ;
}
static struct V_136 * F_85 (
struct V_10 * V_11 , struct V_137 * V_138 ,
struct V_139 * V_139 , T_1 V_140 )
{
struct V_136 * V_141 = NULL ;
int V_37 ;
V_141 = F_11 ( sizeof *V_141 , V_15 ) ;
if ( ! V_141 )
return NULL ;
V_141 -> V_31 . V_43 . type = V_142 ;
V_141 -> V_31 . V_43 . V_54 = sizeof( V_141 -> V_31 ) ;
V_141 -> V_31 . V_140 = V_140 ;
if ( V_138 ) {
V_37 = F_86 ( V_11 , V_138 , & V_141 -> V_43 ,
& V_141 -> V_31 . V_43 ) ;
if ( V_37 ) {
F_3 ( V_141 ) ;
return NULL ;
}
}
V_141 -> V_43 . V_139 = V_139 ;
return V_141 ;
}
static int F_87 ( struct V_5 * V_6 ,
struct V_123 * V_124 , struct V_62 * V_143 ,
T_1 V_144 )
{
struct V_123 * V_4 ;
int V_37 ;
if ( ! F_88 ( V_143 , V_144 , & V_4 ) )
return - V_56 ;
switch ( V_124 -> type ) {
case V_125 : {
struct V_25 * V_26 = F_66 ( V_124 ) ;
struct V_115 * V_116 ;
V_116 = F_57 ( V_6 , V_26 ) ;
if ( F_26 ( V_116 ) ) {
V_37 = F_27 ( V_116 ) ;
break;
}
V_37 = F_62 ( V_26 ,
V_116 , V_143 , V_144 ) ;
break;
}
case V_126 : {
struct V_29 * V_30 = F_68 ( V_124 ) ;
struct V_36 * V_39 ;
V_39 = F_16 ( V_6 , V_30 ) ;
if ( F_26 ( V_39 ) ) {
V_37 = F_27 ( V_39 ) ;
break;
}
V_37 = F_35 ( V_30 ,
V_39 , V_143 , V_144 ) ;
break;
}
case V_127 : {
struct V_32 * V_33 = F_69 ( V_124 ) ;
struct V_79 * V_80 ;
V_80 = F_39 ( V_6 , V_33 ) ;
if ( F_26 ( V_80 ) ) {
V_37 = F_27 ( V_80 ) ;
break;
}
V_37 = F_43 ( V_33 ,
V_80 , V_143 , V_144 ) ;
break;
}
default:
V_37 = - V_56 ;
break;
}
F_89 ( V_143 , V_4 ) ;
return V_37 ;
}
void F_90 ( struct V_10 * V_11 ,
unsigned V_128 ,
int V_37 )
{
struct V_32 * V_33 ;
F_74 (plane, dev, plane_mask) {
if ( V_37 == 0 ) {
struct V_82 * V_145 = V_33 -> V_6 -> V_83 ;
if ( V_145 )
F_70 ( V_145 ) ;
V_33 -> V_83 = V_145 ;
V_33 -> V_30 = V_33 -> V_6 -> V_30 ;
if ( V_33 -> V_146 )
F_46 ( V_33 -> V_146 ) ;
}
V_33 -> V_146 = NULL ;
}
}
int F_91 ( struct V_10 * V_11 ,
void * V_55 , struct V_137 * V_138 )
{
struct V_147 * V_148 = V_55 ;
T_3 T_4 * V_149 = ( T_3 T_4 * ) ( unsigned long ) ( V_148 -> V_149 ) ;
T_3 T_4 * V_150 = ( T_3 T_4 * ) ( unsigned long ) ( V_148 -> V_150 ) ;
T_3 T_4 * V_151 = ( T_3 T_4 * ) ( unsigned long ) ( V_148 -> V_151 ) ;
T_1 T_4 * V_152 = ( T_1 T_4 * ) ( unsigned long ) ( V_148 -> V_152 ) ;
unsigned int V_153 , V_154 ;
struct V_5 * V_6 ;
struct V_155 V_156 ;
struct V_32 * V_33 ;
struct V_29 * V_30 ;
struct V_36 * V_39 ;
unsigned V_128 ;
int V_37 = 0 ;
unsigned int V_23 , V_157 ;
if ( ! F_38 ( V_11 , V_78 ) )
return - V_56 ;
if ( ! V_138 -> V_158 )
return - V_56 ;
if ( V_148 -> V_159 & ~ V_160 )
return - V_56 ;
if ( V_148 -> V_161 )
return - V_56 ;
if ( ( V_148 -> V_159 & V_162 ) &&
! V_11 -> V_13 . V_163 )
return - V_56 ;
if ( ( V_148 -> V_159 & V_164 ) &&
( V_148 -> V_159 & V_165 ) )
return - V_56 ;
F_92 ( & V_156 , 0 ) ;
V_6 = F_10 ( V_11 ) ;
if ( ! V_6 )
return - V_18 ;
V_6 -> V_40 = & V_156 ;
V_6 -> V_12 = ! ! ( V_148 -> V_159 & V_166 ) ;
V_133:
V_128 = 0 ;
V_153 = 0 ;
V_154 = 0 ;
for ( V_23 = 0 ; V_23 < V_148 -> V_167 ; V_23 ++ ) {
T_3 V_168 , V_169 ;
struct V_123 * V_124 ;
if ( F_93 ( V_168 , V_149 + V_153 ) ) {
V_37 = - V_170 ;
goto V_171;
}
V_124 = F_94 ( V_11 , V_168 , V_172 ) ;
if ( ! V_124 ) {
V_37 = - V_173 ;
goto V_171;
}
if ( ! V_124 -> V_174 ) {
F_95 ( V_124 ) ;
V_37 = - V_173 ;
goto V_171;
}
if ( F_93 ( V_169 , V_150 + V_153 ) ) {
F_95 ( V_124 ) ;
V_37 = - V_170 ;
goto V_171;
}
V_153 ++ ;
for ( V_157 = 0 ; V_157 < V_169 ; V_157 ++ ) {
T_3 V_175 ;
T_1 V_144 ;
struct V_62 * V_143 ;
if ( F_93 ( V_175 , V_151 + V_154 ) ) {
F_95 ( V_124 ) ;
V_37 = - V_170 ;
goto V_171;
}
V_143 = F_96 ( V_11 , V_175 ) ;
if ( ! V_143 ) {
F_95 ( V_124 ) ;
V_37 = - V_173 ;
goto V_171;
}
if ( F_97 ( & V_144 ,
V_152 + V_154 ,
sizeof( V_144 ) ) ) {
F_95 ( V_124 ) ;
V_37 = - V_170 ;
goto V_171;
}
V_37 = F_87 ( V_6 , V_124 , V_143 , V_144 ) ;
if ( V_37 ) {
F_95 ( V_124 ) ;
goto V_171;
}
V_154 ++ ;
}
if ( V_124 -> type == V_127 && V_169 &&
! ( V_148 -> V_159 & V_164 ) ) {
V_33 = F_69 ( V_124 ) ;
V_128 |= ( 1 << F_40 ( V_33 ) ) ;
V_33 -> V_146 = V_33 -> V_83 ;
}
F_95 ( V_124 ) ;
}
if ( V_148 -> V_159 & V_165 ) {
F_81 (state, crtc, crtc_state, i) {
struct V_136 * V_141 ;
V_141 = F_85 ( V_11 , V_138 , NULL ,
V_148 -> V_140 ) ;
if ( ! V_141 ) {
V_37 = - V_18 ;
goto V_171;
}
V_39 -> V_31 = V_141 ;
}
}
if ( V_148 -> V_159 & V_164 ) {
V_37 = F_79 ( V_6 ) ;
} else if ( V_148 -> V_159 & V_176 ) {
V_37 = F_84 ( V_6 ) ;
} else {
V_37 = F_83 ( V_6 ) ;
}
V_171:
F_90 ( V_11 , V_128 , V_37 ) ;
if ( V_37 && V_148 -> V_159 & V_165 ) {
F_81 (state, crtc, crtc_state, i) {
if ( ! V_39 -> V_31 )
continue;
F_98 ( V_11 , & V_39 -> V_31 -> V_43 ) ;
}
}
if ( V_37 == - V_177 ) {
F_14 ( V_6 ) ;
F_77 ( & V_156 ) ;
goto V_133;
}
if ( V_37 || V_148 -> V_159 & V_164 )
F_15 ( V_6 ) ;
F_99 ( & V_156 ) ;
F_100 ( & V_156 ) ;
return V_37 ;
}
