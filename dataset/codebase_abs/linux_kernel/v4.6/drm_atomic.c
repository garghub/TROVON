void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_2 ( V_2 -> V_4 ) ;
F_2 ( V_2 -> V_5 ) ;
F_2 ( V_2 -> V_6 ) ;
F_2 ( V_2 -> V_7 ) ;
F_2 ( V_2 -> V_8 ) ;
}
int
F_3 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
V_2 -> V_11 = true ;
V_2 -> V_5 = F_4 ( V_10 -> V_12 . V_13 ,
sizeof( * V_2 -> V_5 ) , V_14 ) ;
if ( ! V_2 -> V_5 )
goto V_15;
V_2 -> V_6 = F_4 ( V_10 -> V_12 . V_13 ,
sizeof( * V_2 -> V_6 ) , V_14 ) ;
if ( ! V_2 -> V_6 )
goto V_15;
V_2 -> V_7 = F_4 ( V_10 -> V_12 . V_16 ,
sizeof( * V_2 -> V_7 ) , V_14 ) ;
if ( ! V_2 -> V_7 )
goto V_15;
V_2 -> V_8 = F_4 ( V_10 -> V_12 . V_16 ,
sizeof( * V_2 -> V_8 ) , V_14 ) ;
if ( ! V_2 -> V_8 )
goto V_15;
V_2 -> V_10 = V_10 ;
F_5 ( L_1 , V_2 ) ;
return 0 ;
V_15:
F_1 ( V_2 ) ;
return - V_17 ;
}
struct V_1 *
F_6 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = & V_10 -> V_12 ;
struct V_1 * V_2 ;
if ( ! V_19 -> V_20 -> V_21 ) {
V_2 = F_7 ( sizeof( * V_2 ) , V_14 ) ;
if ( ! V_2 )
return NULL ;
if ( F_3 ( V_10 , V_2 ) < 0 ) {
F_2 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
return V_19 -> V_20 -> V_21 ( V_10 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_18 * V_19 = & V_10 -> V_12 ;
int V_22 ;
F_5 ( L_2 , V_2 ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_23 ; V_22 ++ ) {
struct V_24 * V_25 = V_2 -> V_3 [ V_22 ] ;
if ( ! V_25 )
continue;
V_2 -> V_4 [ V_22 ] -> V_25 = NULL ;
V_25 -> V_20 -> V_26 ( NULL ,
V_2 -> V_4 [ V_22 ] ) ;
V_2 -> V_3 [ V_22 ] = NULL ;
V_2 -> V_4 [ V_22 ] = NULL ;
}
for ( V_22 = 0 ; V_22 < V_19 -> V_13 ; V_22 ++ ) {
struct V_27 * V_28 = V_2 -> V_5 [ V_22 ] ;
if ( ! V_28 )
continue;
V_28 -> V_20 -> V_26 ( V_28 ,
V_2 -> V_6 [ V_22 ] ) ;
V_2 -> V_5 [ V_22 ] = NULL ;
V_2 -> V_6 [ V_22 ] = NULL ;
}
for ( V_22 = 0 ; V_22 < V_19 -> V_16 ; V_22 ++ ) {
struct V_29 * V_30 = V_2 -> V_7 [ V_22 ] ;
if ( ! V_30 )
continue;
V_30 -> V_20 -> V_26 ( V_30 ,
V_2 -> V_8 [ V_22 ] ) ;
V_2 -> V_7 [ V_22 ] = NULL ;
V_2 -> V_8 [ V_22 ] = NULL ;
}
}
void F_9 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_18 * V_19 = & V_10 -> V_12 ;
if ( V_19 -> V_20 -> V_31 )
V_19 -> V_20 -> V_31 ( V_2 ) ;
else
F_8 ( V_2 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_18 * V_19 ;
if ( ! V_2 )
return;
V_10 = V_2 -> V_10 ;
V_19 = & V_10 -> V_12 ;
F_9 ( V_2 ) ;
F_5 ( L_3 , V_2 ) ;
if ( V_19 -> V_20 -> V_32 ) {
V_19 -> V_20 -> V_32 ( V_2 ) ;
} else {
F_1 ( V_2 ) ;
F_2 ( V_2 ) ;
}
}
struct V_33 *
F_11 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
int V_34 , V_35 = F_12 ( V_28 ) ;
struct V_33 * V_36 ;
V_36 = F_13 ( V_2 , V_28 ) ;
if ( V_36 )
return V_36 ;
V_34 = F_14 ( & V_28 -> V_37 , V_2 -> V_38 ) ;
if ( V_34 )
return F_15 ( V_34 ) ;
V_36 = V_28 -> V_20 -> V_39 ( V_28 ) ;
if ( ! V_36 )
return F_15 ( - V_17 ) ;
V_2 -> V_6 [ V_35 ] = V_36 ;
V_2 -> V_5 [ V_35 ] = V_28 ;
V_36 -> V_2 = V_2 ;
F_5 ( L_4 ,
V_28 -> V_40 . V_41 , V_28 -> V_42 , V_36 , V_2 ) ;
return V_36 ;
}
int F_16 ( struct V_33 * V_2 ,
struct V_43 * V_44 )
{
struct V_45 V_46 ;
if ( V_44 && memcmp ( & V_2 -> V_44 , V_44 , sizeof( * V_44 ) ) == 0 )
return 0 ;
F_17 ( V_2 -> V_47 ) ;
V_2 -> V_47 = NULL ;
if ( V_44 ) {
F_18 ( & V_46 , V_44 ) ;
V_2 -> V_47 =
F_19 ( V_2 -> V_28 -> V_10 ,
sizeof( V_46 ) ,
& V_46 ) ;
if ( F_20 ( V_2 -> V_47 ) )
return F_21 ( V_2 -> V_47 ) ;
F_22 ( & V_2 -> V_44 , V_44 ) ;
V_2 -> V_48 = true ;
F_5 ( L_5 ,
V_44 -> V_42 , V_2 ) ;
} else {
memset ( & V_2 -> V_44 , 0 , sizeof( V_2 -> V_44 ) ) ;
V_2 -> V_48 = false ;
F_5 ( L_6 ,
V_2 ) ;
}
return 0 ;
}
int F_23 ( struct V_33 * V_2 ,
struct V_49 * V_50 )
{
if ( V_50 == V_2 -> V_47 )
return 0 ;
F_17 ( V_2 -> V_47 ) ;
V_2 -> V_47 = NULL ;
if ( V_50 ) {
if ( V_50 -> V_51 != sizeof( struct V_45 ) ||
F_24 ( & V_2 -> V_44 ,
( const struct V_45 * )
V_50 -> V_52 ) )
return - V_53 ;
V_2 -> V_47 = F_25 ( V_50 ) ;
V_2 -> V_48 = true ;
F_5 ( L_5 ,
V_2 -> V_44 . V_42 , V_2 ) ;
} else {
memset ( & V_2 -> V_44 , 0 , sizeof( V_2 -> V_44 ) ) ;
V_2 -> V_48 = false ;
F_5 ( L_6 ,
V_2 ) ;
}
return 0 ;
}
static void
F_26 ( struct V_49 * * V_50 ,
struct V_49 * V_54 ,
bool * V_55 )
{
struct V_49 * V_56 = * V_50 ;
if ( V_56 == V_54 )
return;
if ( V_56 )
F_17 ( V_56 ) ;
if ( V_54 )
F_25 ( V_54 ) ;
* V_50 = V_54 ;
* V_55 = true ;
return;
}
static int
F_27 ( struct V_27 * V_28 ,
struct V_49 * * V_50 ,
T_1 V_57 ,
T_2 V_58 ,
bool * V_55 )
{
struct V_9 * V_10 = V_28 -> V_10 ;
struct V_49 * V_54 = NULL ;
if ( V_57 != 0 ) {
V_54 = F_28 ( V_10 , V_57 ) ;
if ( V_54 == NULL )
return - V_53 ;
if ( V_58 > 0 && V_58 != V_54 -> V_51 )
return - V_53 ;
}
F_26 ( V_50 , V_54 , V_55 ) ;
return 0 ;
}
int F_29 ( struct V_27 * V_28 ,
struct V_33 * V_2 , struct V_59 * V_60 ,
T_1 V_61 )
{
struct V_9 * V_10 = V_28 -> V_10 ;
struct V_18 * V_19 = & V_10 -> V_12 ;
bool V_55 = false ;
int V_34 ;
if ( V_60 == V_19 -> V_62 )
V_2 -> V_63 = V_61 ;
else if ( V_60 == V_19 -> V_64 ) {
struct V_49 * V_44 =
F_28 ( V_10 , V_61 ) ;
V_34 = F_23 ( V_2 , V_44 ) ;
F_17 ( V_44 ) ;
return V_34 ;
} else if ( V_60 == V_19 -> V_65 ) {
V_34 = F_27 ( V_28 ,
& V_2 -> V_66 ,
V_61 ,
- 1 ,
& V_55 ) ;
V_2 -> V_67 = V_55 ;
return V_34 ;
} else if ( V_60 == V_19 -> V_68 ) {
V_34 = F_27 ( V_28 ,
& V_2 -> V_69 ,
V_61 ,
sizeof( struct V_70 ) ,
& V_55 ) ;
V_2 -> V_67 = V_55 ;
return V_34 ;
} else if ( V_60 == V_19 -> V_71 ) {
V_34 = F_27 ( V_28 ,
& V_2 -> V_72 ,
V_61 ,
- 1 ,
& V_55 ) ;
V_2 -> V_67 = V_55 ;
return V_34 ;
} else if ( V_28 -> V_20 -> V_73 )
return V_28 -> V_20 -> V_73 ( V_28 , V_2 , V_60 , V_61 ) ;
else
return - V_53 ;
return 0 ;
}
static int
F_30 ( struct V_27 * V_28 ,
const struct V_33 * V_2 ,
struct V_59 * V_60 , T_1 * V_61 )
{
struct V_9 * V_10 = V_28 -> V_10 ;
struct V_18 * V_19 = & V_10 -> V_12 ;
if ( V_60 == V_19 -> V_62 )
* V_61 = V_2 -> V_63 ;
else if ( V_60 == V_19 -> V_64 )
* V_61 = ( V_2 -> V_47 ) ? V_2 -> V_47 -> V_40 . V_41 : 0 ;
else if ( V_60 == V_19 -> V_65 )
* V_61 = ( V_2 -> V_66 ) ? V_2 -> V_66 -> V_40 . V_41 : 0 ;
else if ( V_60 == V_19 -> V_68 )
* V_61 = ( V_2 -> V_69 ) ? V_2 -> V_69 -> V_40 . V_41 : 0 ;
else if ( V_60 == V_19 -> V_71 )
* V_61 = ( V_2 -> V_72 ) ? V_2 -> V_72 -> V_40 . V_41 : 0 ;
else if ( V_28 -> V_20 -> V_74 )
return V_28 -> V_20 -> V_74 ( V_28 , V_2 , V_60 , V_61 ) ;
else
return - V_53 ;
return 0 ;
}
static int F_31 ( struct V_27 * V_28 ,
struct V_33 * V_2 )
{
if ( V_2 -> V_63 && ! V_2 -> V_48 ) {
F_5 ( L_7 ,
V_28 -> V_40 . V_41 , V_28 -> V_42 ) ;
return - V_53 ;
}
if ( F_32 ( V_28 -> V_10 , V_75 ) &&
F_33 ( V_2 -> V_48 && ! V_2 -> V_47 ) ) {
F_5 ( L_8 ,
V_28 -> V_40 . V_41 , V_28 -> V_42 ) ;
return - V_53 ;
}
if ( F_32 ( V_28 -> V_10 , V_75 ) &&
F_33 ( ! V_2 -> V_48 && V_2 -> V_47 ) ) {
F_5 ( L_9 ,
V_28 -> V_40 . V_41 , V_28 -> V_42 ) ;
return - V_53 ;
}
if ( V_2 -> V_76 && ! V_2 -> V_63 && ! V_28 -> V_2 -> V_63 ) {
F_5 ( L_10 ,
V_28 -> V_40 . V_41 ) ;
return - V_53 ;
}
return 0 ;
}
struct V_77 *
F_34 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
int V_34 , V_35 = F_35 ( V_30 ) ;
struct V_77 * V_78 ;
V_78 = F_36 ( V_2 , V_30 ) ;
if ( V_78 )
return V_78 ;
V_34 = F_14 ( & V_30 -> V_37 , V_2 -> V_38 ) ;
if ( V_34 )
return F_15 ( V_34 ) ;
V_78 = V_30 -> V_20 -> V_39 ( V_30 ) ;
if ( ! V_78 )
return F_15 ( - V_17 ) ;
V_2 -> V_8 [ V_35 ] = V_78 ;
V_2 -> V_7 [ V_35 ] = V_30 ;
V_78 -> V_2 = V_2 ;
F_5 ( L_11 ,
V_30 -> V_40 . V_41 , V_30 -> V_42 , V_78 , V_2 ) ;
if ( V_78 -> V_28 ) {
struct V_33 * V_36 ;
V_36 = F_11 ( V_2 ,
V_78 -> V_28 ) ;
if ( F_20 ( V_36 ) )
return F_37 ( V_36 ) ;
}
return V_78 ;
}
int F_38 ( struct V_29 * V_30 ,
struct V_77 * V_2 , struct V_59 * V_60 ,
T_1 V_61 )
{
struct V_9 * V_10 = V_30 -> V_10 ;
struct V_18 * V_19 = & V_10 -> V_12 ;
if ( V_60 == V_19 -> V_79 ) {
struct V_80 * V_81 = F_39 ( V_10 , V_61 ) ;
F_40 ( V_2 , V_81 ) ;
if ( V_81 )
F_41 ( V_81 ) ;
} else if ( V_60 == V_19 -> V_82 ) {
struct V_27 * V_28 = F_42 ( V_10 , V_61 ) ;
return F_43 ( V_2 , V_28 ) ;
} else if ( V_60 == V_19 -> V_83 ) {
V_2 -> V_84 = F_44 ( V_61 ) ;
} else if ( V_60 == V_19 -> V_85 ) {
V_2 -> V_86 = F_44 ( V_61 ) ;
} else if ( V_60 == V_19 -> V_87 ) {
V_2 -> V_88 = V_61 ;
} else if ( V_60 == V_19 -> V_89 ) {
V_2 -> V_90 = V_61 ;
} else if ( V_60 == V_19 -> V_91 ) {
V_2 -> V_92 = V_61 ;
} else if ( V_60 == V_19 -> V_93 ) {
V_2 -> V_94 = V_61 ;
} else if ( V_60 == V_19 -> V_95 ) {
V_2 -> V_96 = V_61 ;
} else if ( V_60 == V_19 -> V_97 ) {
V_2 -> V_98 = V_61 ;
} else if ( V_60 == V_19 -> V_99 ) {
V_2 -> V_100 = V_61 ;
} else if ( V_30 -> V_20 -> V_73 ) {
return V_30 -> V_20 -> V_73 ( V_30 , V_2 ,
V_60 , V_61 ) ;
} else {
return - V_53 ;
}
return 0 ;
}
static int
F_45 ( struct V_29 * V_30 ,
const struct V_77 * V_2 ,
struct V_59 * V_60 , T_1 * V_61 )
{
struct V_9 * V_10 = V_30 -> V_10 ;
struct V_18 * V_19 = & V_10 -> V_12 ;
if ( V_60 == V_19 -> V_79 ) {
* V_61 = ( V_2 -> V_81 ) ? V_2 -> V_81 -> V_40 . V_41 : 0 ;
} else if ( V_60 == V_19 -> V_82 ) {
* V_61 = ( V_2 -> V_28 ) ? V_2 -> V_28 -> V_40 . V_41 : 0 ;
} else if ( V_60 == V_19 -> V_83 ) {
* V_61 = F_46 ( V_2 -> V_84 ) ;
} else if ( V_60 == V_19 -> V_85 ) {
* V_61 = F_46 ( V_2 -> V_86 ) ;
} else if ( V_60 == V_19 -> V_87 ) {
* V_61 = V_2 -> V_88 ;
} else if ( V_60 == V_19 -> V_89 ) {
* V_61 = V_2 -> V_90 ;
} else if ( V_60 == V_19 -> V_91 ) {
* V_61 = V_2 -> V_92 ;
} else if ( V_60 == V_19 -> V_93 ) {
* V_61 = V_2 -> V_94 ;
} else if ( V_60 == V_19 -> V_95 ) {
* V_61 = V_2 -> V_96 ;
} else if ( V_60 == V_19 -> V_97 ) {
* V_61 = V_2 -> V_98 ;
} else if ( V_60 == V_19 -> V_99 ) {
* V_61 = V_2 -> V_100 ;
} else if ( V_30 -> V_20 -> V_74 ) {
return V_30 -> V_20 -> V_74 ( V_30 , V_2 , V_60 , V_61 ) ;
} else {
return - V_53 ;
}
return 0 ;
}
static bool
F_47 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
struct V_77 * V_78 )
{
if ( ! V_30 -> V_2 -> V_28 || ! V_78 -> V_28 )
return false ;
if ( V_30 -> V_2 -> V_28 == V_78 -> V_28 )
return false ;
return true ;
}
static int F_48 ( struct V_29 * V_30 ,
struct V_77 * V_2 )
{
unsigned int V_101 , V_102 ;
int V_34 ;
if ( F_33 ( V_2 -> V_28 && ! V_2 -> V_81 ) ) {
F_5 ( L_12 ) ;
return - V_53 ;
} else if ( F_33 ( V_2 -> V_81 && ! V_2 -> V_28 ) ) {
F_5 ( L_13 ) ;
return - V_53 ;
}
if ( ! V_2 -> V_28 )
return 0 ;
if ( ! ( V_30 -> V_103 & F_49 ( V_2 -> V_28 ) ) ) {
F_5 ( L_14 ) ;
return - V_53 ;
}
V_34 = F_50 ( V_30 , V_2 -> V_81 -> V_104 ) ;
if ( V_34 ) {
F_5 ( L_15 ,
F_51 ( V_2 -> V_81 -> V_104 ) ) ;
return V_34 ;
}
if ( V_2 -> V_88 > V_105 ||
V_2 -> V_84 > V_105 - ( V_106 ) V_2 -> V_88 ||
V_2 -> V_90 > V_105 ||
V_2 -> V_86 > V_105 - ( V_106 ) V_2 -> V_90 ) {
F_5 ( L_16 ,
V_2 -> V_88 , V_2 -> V_90 ,
V_2 -> V_84 , V_2 -> V_86 ) ;
return - V_107 ;
}
V_101 = V_2 -> V_81 -> V_108 << 16 ;
V_102 = V_2 -> V_81 -> V_109 << 16 ;
if ( V_2 -> V_96 > V_101 ||
V_2 -> V_92 > V_101 - V_2 -> V_96 ||
V_2 -> V_98 > V_102 ||
V_2 -> V_94 > V_102 - V_2 -> V_98 ) {
F_5 ( L_17
L_18 ,
V_2 -> V_96 >> 16 , ( ( V_2 -> V_96 & 0xffff ) * 15625 ) >> 10 ,
V_2 -> V_98 >> 16 , ( ( V_2 -> V_98 & 0xffff ) * 15625 ) >> 10 ,
V_2 -> V_92 >> 16 , ( ( V_2 -> V_92 & 0xffff ) * 15625 ) >> 10 ,
V_2 -> V_94 >> 16 , ( ( V_2 -> V_94 & 0xffff ) * 15625 ) >> 10 ) ;
return - V_110 ;
}
if ( F_47 ( V_2 -> V_2 , V_30 , V_2 ) ) {
F_5 ( L_19 ,
V_30 -> V_40 . V_41 , V_30 -> V_42 ) ;
return - V_53 ;
}
return 0 ;
}
struct V_111 *
F_52 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
int V_34 , V_35 ;
struct V_18 * V_19 = & V_25 -> V_10 -> V_12 ;
struct V_111 * V_112 ;
V_34 = F_14 ( & V_19 -> V_113 , V_2 -> V_38 ) ;
if ( V_34 )
return F_15 ( V_34 ) ;
V_35 = F_53 ( V_25 ) ;
if ( V_35 >= V_2 -> V_23 ) {
struct V_24 * * V_114 ;
struct V_111 * * V_115 ;
int V_116 = F_54 ( V_35 + 1 , V_19 -> V_23 ) ;
V_114 = F_55 ( V_2 -> V_3 , V_116 * sizeof( * V_2 -> V_3 ) , V_14 ) ;
if ( ! V_114 )
return F_15 ( - V_17 ) ;
V_2 -> V_3 = V_114 ;
memset ( & V_2 -> V_3 [ V_2 -> V_23 ] , 0 ,
sizeof( * V_2 -> V_3 ) * ( V_116 - V_2 -> V_23 ) ) ;
V_115 = F_55 ( V_2 -> V_4 , V_116 * sizeof( * V_2 -> V_4 ) , V_14 ) ;
if ( ! V_115 )
return F_15 ( - V_17 ) ;
V_2 -> V_4 = V_115 ;
memset ( & V_2 -> V_4 [ V_2 -> V_23 ] , 0 ,
sizeof( * V_2 -> V_4 ) * ( V_116 - V_2 -> V_23 ) ) ;
V_2 -> V_23 = V_116 ;
}
if ( V_2 -> V_4 [ V_35 ] )
return V_2 -> V_4 [ V_35 ] ;
V_112 = V_25 -> V_20 -> V_39 ( V_25 ) ;
if ( ! V_112 )
return F_15 ( - V_17 ) ;
V_2 -> V_4 [ V_35 ] = V_112 ;
V_2 -> V_3 [ V_35 ] = V_25 ;
V_112 -> V_2 = V_2 ;
F_5 ( L_20 ,
V_25 -> V_40 . V_41 , V_112 , V_2 ) ;
if ( V_112 -> V_28 ) {
struct V_33 * V_36 ;
V_36 = F_11 ( V_2 ,
V_112 -> V_28 ) ;
if ( F_20 ( V_36 ) )
return F_37 ( V_36 ) ;
}
return V_112 ;
}
int F_56 ( struct V_24 * V_25 ,
struct V_111 * V_2 , struct V_59 * V_60 ,
T_1 V_61 )
{
struct V_9 * V_10 = V_25 -> V_10 ;
struct V_18 * V_19 = & V_10 -> V_12 ;
if ( V_60 == V_19 -> V_82 ) {
struct V_27 * V_28 = F_42 ( V_10 , V_61 ) ;
return F_57 ( V_2 , V_28 ) ;
} else if ( V_60 == V_19 -> V_117 ) {
return - V_53 ;
} else if ( V_25 -> V_20 -> V_73 ) {
return V_25 -> V_20 -> V_73 ( V_25 ,
V_2 , V_60 , V_61 ) ;
} else {
return - V_53 ;
}
}
static int
F_58 ( struct V_24 * V_25 ,
const struct V_111 * V_2 ,
struct V_59 * V_60 , T_1 * V_61 )
{
struct V_9 * V_10 = V_25 -> V_10 ;
struct V_18 * V_19 = & V_10 -> V_12 ;
if ( V_60 == V_19 -> V_82 ) {
* V_61 = ( V_2 -> V_28 ) ? V_2 -> V_28 -> V_40 . V_41 : 0 ;
} else if ( V_60 == V_19 -> V_117 ) {
* V_61 = V_25 -> V_118 ;
} else if ( V_25 -> V_20 -> V_74 ) {
return V_25 -> V_20 -> V_74 ( V_25 ,
V_2 , V_60 , V_61 ) ;
} else {
return - V_53 ;
}
return 0 ;
}
int F_59 ( struct V_119 * V_120 ,
struct V_59 * V_60 , T_1 * V_61 )
{
struct V_9 * V_10 = V_60 -> V_10 ;
int V_34 ;
switch ( V_120 -> type ) {
case V_121 : {
struct V_24 * V_25 = F_60 ( V_120 ) ;
F_33 ( ! F_61 ( & V_10 -> V_12 . V_113 ) ) ;
V_34 = F_58 ( V_25 ,
V_25 -> V_2 , V_60 , V_61 ) ;
break;
}
case V_122 : {
struct V_27 * V_28 = F_62 ( V_120 ) ;
F_33 ( ! F_61 ( & V_28 -> V_37 ) ) ;
V_34 = F_30 ( V_28 ,
V_28 -> V_2 , V_60 , V_61 ) ;
break;
}
case V_123 : {
struct V_29 * V_30 = F_63 ( V_120 ) ;
F_33 ( ! F_61 ( & V_30 -> V_37 ) ) ;
V_34 = F_45 ( V_30 ,
V_30 -> V_2 , V_60 , V_61 ) ;
break;
}
default:
V_34 = - V_53 ;
break;
}
return V_34 ;
}
int
F_43 ( struct V_77 * V_78 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 = V_78 -> V_30 ;
struct V_33 * V_36 ;
if ( V_78 -> V_28 ) {
V_36 = F_11 ( V_78 -> V_2 ,
V_78 -> V_28 ) ;
if ( F_33 ( F_20 ( V_36 ) ) )
return F_21 ( V_36 ) ;
V_36 -> V_124 &= ~ ( 1 << F_35 ( V_30 ) ) ;
}
V_78 -> V_28 = V_28 ;
if ( V_28 ) {
V_36 = F_11 ( V_78 -> V_2 ,
V_28 ) ;
if ( F_20 ( V_36 ) )
return F_21 ( V_36 ) ;
V_36 -> V_124 |= ( 1 << F_35 ( V_30 ) ) ;
}
if ( V_28 )
F_5 ( L_21 ,
V_78 , V_28 -> V_40 . V_41 , V_28 -> V_42 ) ;
else
F_5 ( L_22 ,
V_78 ) ;
return 0 ;
}
void
F_40 ( struct V_77 * V_78 ,
struct V_80 * V_81 )
{
if ( V_78 -> V_81 )
F_41 ( V_78 -> V_81 ) ;
if ( V_81 )
F_64 ( V_81 ) ;
V_78 -> V_81 = V_81 ;
if ( V_81 )
F_5 ( L_23 ,
V_81 -> V_40 . V_41 , V_78 ) ;
else
F_5 ( L_24 ,
V_78 ) ;
}
int
F_57 ( struct V_111 * V_125 ,
struct V_27 * V_28 )
{
struct V_33 * V_36 ;
if ( V_125 -> V_28 && V_125 -> V_28 != V_28 ) {
V_36 = F_13 ( V_125 -> V_2 ,
V_125 -> V_28 ) ;
V_36 -> V_126 &=
~ ( 1 << F_53 ( V_125 -> V_25 ) ) ;
}
if ( V_28 ) {
V_36 = F_11 ( V_125 -> V_2 , V_28 ) ;
if ( F_20 ( V_36 ) )
return F_21 ( V_36 ) ;
V_36 -> V_126 |=
1 << F_53 ( V_125 -> V_25 ) ;
}
V_125 -> V_28 = V_28 ;
if ( V_28 )
F_5 ( L_25 ,
V_125 , V_28 -> V_40 . V_41 , V_28 -> V_42 ) ;
else
F_5 ( L_26 ,
V_125 ) ;
return 0 ;
}
int
F_65 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_18 * V_19 = & V_2 -> V_10 -> V_12 ;
struct V_24 * V_25 ;
struct V_111 * V_125 ;
int V_34 ;
V_34 = F_14 ( & V_19 -> V_113 , V_2 -> V_38 ) ;
if ( V_34 )
return V_34 ;
F_5 ( L_27 ,
V_28 -> V_40 . V_41 , V_28 -> V_42 , V_2 ) ;
F_66 (connector, state->dev) {
if ( V_25 -> V_2 -> V_28 != V_28 )
continue;
V_125 = F_52 ( V_2 , V_25 ) ;
if ( F_20 ( V_125 ) )
return F_21 ( V_125 ) ;
}
return 0 ;
}
int
F_67 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 ;
F_33 ( ! F_13 ( V_2 , V_28 ) ) ;
F_68 (plane, state->dev, crtc->state->plane_mask) {
struct V_77 * V_78 =
F_34 ( V_2 , V_30 ) ;
if ( F_20 ( V_78 ) )
return F_21 ( V_78 ) ;
}
return 0 ;
}
void F_69 ( struct V_1 * V_2 )
{
int V_34 ;
V_127:
F_70 ( V_2 -> V_38 ) ;
V_34 = F_71 ( V_2 -> V_10 , V_2 -> V_38 ) ;
if ( V_34 )
goto V_127;
}
int F_72 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_18 * V_19 = & V_10 -> V_12 ;
struct V_29 * V_30 ;
struct V_77 * V_78 ;
struct V_27 * V_28 ;
struct V_33 * V_36 ;
int V_22 , V_34 = 0 ;
F_5 ( L_28 , V_2 ) ;
F_73 (state, plane, plane_state, i) {
V_34 = F_48 ( V_30 , V_78 ) ;
if ( V_34 ) {
F_5 ( L_29 ,
V_30 -> V_40 . V_41 , V_30 -> V_42 ) ;
return V_34 ;
}
}
F_74 (state, crtc, crtc_state, i) {
V_34 = F_31 ( V_28 , V_36 ) ;
if ( V_34 ) {
F_5 ( L_30 ,
V_28 -> V_40 . V_41 , V_28 -> V_42 ) ;
return V_34 ;
}
}
if ( V_19 -> V_20 -> V_128 )
V_34 = V_19 -> V_20 -> V_128 ( V_2 -> V_10 , V_2 ) ;
if ( ! V_2 -> V_11 ) {
F_74 (state, crtc, crtc_state, i) {
if ( F_75 ( V_36 ) ) {
F_5 ( L_31 ,
V_28 -> V_40 . V_41 , V_28 -> V_42 ) ;
return - V_53 ;
}
}
}
return V_34 ;
}
int F_76 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = & V_2 -> V_10 -> V_12 ;
int V_34 ;
V_34 = F_72 ( V_2 ) ;
if ( V_34 )
return V_34 ;
F_5 ( L_32 , V_2 ) ;
return V_19 -> V_20 -> V_129 ( V_2 -> V_10 , V_2 , false ) ;
}
int F_77 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = & V_2 -> V_10 -> V_12 ;
int V_34 ;
V_34 = F_72 ( V_2 ) ;
if ( V_34 )
return V_34 ;
F_5 ( L_33 , V_2 ) ;
return V_19 -> V_20 -> V_129 ( V_2 -> V_10 , V_2 , true ) ;
}
static struct V_130 * F_78 (
struct V_9 * V_10 , struct V_131 * V_132 , T_1 V_133 )
{
struct V_130 * V_134 = NULL ;
int V_34 ;
V_134 = F_7 ( sizeof *V_134 , V_14 ) ;
if ( ! V_134 )
return NULL ;
V_134 -> V_76 . V_40 . type = V_135 ;
V_134 -> V_76 . V_40 . V_51 = sizeof( V_134 -> V_76 ) ;
V_134 -> V_76 . V_133 = V_133 ;
V_34 = F_79 ( V_10 , V_132 , & V_134 -> V_40 , & V_134 -> V_76 . V_40 ) ;
if ( V_34 ) {
F_2 ( V_134 ) ;
return NULL ;
}
return V_134 ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_119 * V_120 , struct V_59 * V_136 ,
T_1 V_137 )
{
struct V_119 * V_138 ;
int V_34 ;
if ( ! F_81 ( V_136 , V_137 , & V_138 ) )
return - V_53 ;
switch ( V_120 -> type ) {
case V_121 : {
struct V_24 * V_25 = F_60 ( V_120 ) ;
struct V_111 * V_112 ;
V_112 = F_52 ( V_2 , V_25 ) ;
if ( F_20 ( V_112 ) ) {
V_34 = F_21 ( V_112 ) ;
break;
}
V_34 = F_56 ( V_25 ,
V_112 , V_136 , V_137 ) ;
break;
}
case V_122 : {
struct V_27 * V_28 = F_62 ( V_120 ) ;
struct V_33 * V_36 ;
V_36 = F_11 ( V_2 , V_28 ) ;
if ( F_20 ( V_36 ) ) {
V_34 = F_21 ( V_36 ) ;
break;
}
V_34 = F_29 ( V_28 ,
V_36 , V_136 , V_137 ) ;
break;
}
case V_123 : {
struct V_29 * V_30 = F_63 ( V_120 ) ;
struct V_77 * V_78 ;
V_78 = F_34 ( V_2 , V_30 ) ;
if ( F_20 ( V_78 ) ) {
V_34 = F_21 ( V_78 ) ;
break;
}
V_34 = F_38 ( V_30 ,
V_78 , V_136 , V_137 ) ;
break;
}
default:
V_34 = - V_53 ;
break;
}
F_82 ( V_136 , V_138 ) ;
return V_34 ;
}
void F_83 ( struct V_9 * V_10 ,
unsigned V_124 ,
int V_34 )
{
struct V_29 * V_30 ;
F_68 (plane, dev, plane_mask) {
if ( V_34 == 0 ) {
struct V_80 * V_139 = V_30 -> V_2 -> V_81 ;
if ( V_139 )
F_64 ( V_139 ) ;
V_30 -> V_81 = V_139 ;
V_30 -> V_28 = V_30 -> V_2 -> V_28 ;
if ( V_30 -> V_140 )
F_41 ( V_30 -> V_140 ) ;
}
V_30 -> V_140 = NULL ;
}
}
int F_84 ( struct V_9 * V_10 ,
void * V_52 , struct V_131 * V_132 )
{
struct V_141 * V_142 = V_52 ;
T_3 T_4 * V_143 = ( T_3 T_4 * ) ( unsigned long ) ( V_142 -> V_143 ) ;
T_3 T_4 * V_144 = ( T_3 T_4 * ) ( unsigned long ) ( V_142 -> V_144 ) ;
T_3 T_4 * V_145 = ( T_3 T_4 * ) ( unsigned long ) ( V_142 -> V_145 ) ;
T_1 T_4 * V_146 = ( T_1 T_4 * ) ( unsigned long ) ( V_142 -> V_146 ) ;
unsigned int V_147 , V_148 ;
struct V_1 * V_2 ;
struct V_149 V_150 ;
struct V_29 * V_30 ;
struct V_27 * V_28 ;
struct V_33 * V_36 ;
unsigned V_124 ;
int V_34 = 0 ;
unsigned int V_22 , V_151 ;
if ( ! F_32 ( V_10 , V_75 ) )
return - V_53 ;
if ( ! V_132 -> V_152 )
return - V_53 ;
if ( V_142 -> V_153 & ~ V_154 )
return - V_53 ;
if ( V_142 -> V_155 )
return - V_53 ;
if ( ( V_142 -> V_153 & V_156 ) &&
! V_10 -> V_12 . V_157 )
return - V_53 ;
if ( ( V_142 -> V_153 & V_158 ) &&
( V_142 -> V_153 & V_159 ) )
return - V_53 ;
F_85 ( & V_150 , 0 ) ;
V_2 = F_6 ( V_10 ) ;
if ( ! V_2 )
return - V_17 ;
V_2 -> V_38 = & V_150 ;
V_2 -> V_11 = ! ! ( V_142 -> V_153 & V_160 ) ;
V_127:
V_124 = 0 ;
V_147 = 0 ;
V_148 = 0 ;
for ( V_22 = 0 ; V_22 < V_142 -> V_161 ; V_22 ++ ) {
T_3 V_162 , V_163 ;
struct V_119 * V_120 ;
if ( F_86 ( V_162 , V_143 + V_147 ) ) {
V_34 = - V_164 ;
goto V_165;
}
V_120 = F_87 ( V_10 , V_162 , V_166 ) ;
if ( ! V_120 || ! V_120 -> V_167 ) {
V_34 = - V_168 ;
goto V_165;
}
if ( F_86 ( V_163 , V_144 + V_147 ) ) {
V_34 = - V_164 ;
goto V_165;
}
V_147 ++ ;
for ( V_151 = 0 ; V_151 < V_163 ; V_151 ++ ) {
T_3 V_169 ;
T_1 V_137 ;
struct V_59 * V_136 ;
if ( F_86 ( V_169 , V_145 + V_148 ) ) {
V_34 = - V_164 ;
goto V_165;
}
V_136 = F_88 ( V_10 , V_169 ) ;
if ( ! V_136 ) {
V_34 = - V_168 ;
goto V_165;
}
if ( F_89 ( & V_137 ,
V_146 + V_148 ,
sizeof( V_137 ) ) ) {
V_34 = - V_164 ;
goto V_165;
}
V_34 = F_80 ( V_2 , V_120 , V_136 , V_137 ) ;
if ( V_34 )
goto V_165;
V_148 ++ ;
}
if ( V_120 -> type == V_123 && V_163 &&
! ( V_142 -> V_153 & V_158 ) ) {
V_30 = F_63 ( V_120 ) ;
V_124 |= ( 1 << F_35 ( V_30 ) ) ;
V_30 -> V_140 = V_30 -> V_81 ;
}
}
if ( V_142 -> V_153 & V_159 ) {
F_74 (state, crtc, crtc_state, i) {
struct V_130 * V_134 ;
V_134 = F_78 ( V_10 , V_132 , V_142 -> V_133 ) ;
if ( ! V_134 ) {
V_34 = - V_17 ;
goto V_165;
}
V_36 -> V_76 = V_134 ;
}
}
if ( V_142 -> V_153 & V_158 ) {
V_34 = F_72 ( V_2 ) ;
} else if ( V_142 -> V_153 & V_170 ) {
V_34 = F_77 ( V_2 ) ;
} else {
V_34 = F_76 ( V_2 ) ;
}
V_165:
F_83 ( V_10 , V_124 , V_34 ) ;
if ( V_34 && V_142 -> V_153 & V_159 ) {
F_74 (state, crtc, crtc_state, i) {
if ( ! V_36 -> V_76 )
continue;
F_90 ( V_10 , & V_36 -> V_76 -> V_40 ) ;
}
}
if ( V_34 == - V_171 ) {
F_9 ( V_2 ) ;
F_70 ( & V_150 ) ;
goto V_127;
}
if ( V_34 || V_142 -> V_153 & V_158 )
F_10 ( V_2 ) ;
F_91 ( & V_150 ) ;
F_92 ( & V_150 ) ;
return V_34 ;
}
