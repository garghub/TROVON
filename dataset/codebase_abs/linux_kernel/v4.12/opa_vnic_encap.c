static inline void F_1 ( T_1 * V_1 , T_2 V_2 , T_2 V_3 , T_3 V_4 ,
T_3 V_5 , T_3 V_6 , T_1 V_7 , T_1 V_8 ,
T_1 V_9 , T_3 V_10 )
{
T_2 V_11 [ V_12 ] = { 0 , 0xc0000000 , 0 , 0 , 0 } ;
V_11 [ 2 ] = V_9 ;
V_11 [ 3 ] = V_6 ;
V_11 [ 4 ] = V_10 << V_13 ;
V_11 [ 0 ] |= ( V_2 & V_14 ) ;
V_11 [ 2 ] |= ( ( V_2 >> ( 20 - V_15 ) ) & V_16 ) ;
V_11 [ 1 ] |= ( V_3 & V_14 ) ;
V_11 [ 2 ] |= ( ( V_3 >> ( 20 - V_17 ) ) & V_18 ) ;
V_11 [ 0 ] |= ( V_4 << V_19 ) ;
V_11 [ 1 ] |= ( V_8 << V_20 ) ;
V_11 [ 1 ] |= ( V_7 << V_21 ) ;
V_11 [ 2 ] |= ( ( T_2 ) V_5 << V_22 ) ;
memcpy ( V_1 , V_11 , V_23 ) ;
}
static void F_2 ( struct V_24 * V_25 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
int V_30 ;
if ( ! V_25 )
return;
F_3 (mactbl, bkt, tmp, node, hlist) {
F_4 ( & V_27 -> V_31 ) ;
F_5 ( V_27 ) ;
}
F_5 ( V_25 ) ;
}
static struct V_24 * F_6 ( void )
{
T_2 V_32 = sizeof( struct V_24 ) * V_33 ;
struct V_24 * V_25 ;
V_25 = F_7 ( V_32 , V_34 ) ;
if ( ! V_25 )
return F_8 ( - V_35 ) ;
F_9 ( V_25 ) ;
return V_25 ;
}
void F_10 ( struct V_36 * V_37 )
{
struct V_24 * V_25 ;
F_11 ( & V_37 -> V_38 ) ;
V_25 = F_12 ( V_37 -> V_25 ) ;
F_13 ( V_37 -> V_25 , NULL ) ;
F_14 () ;
F_2 ( V_25 ) ;
F_15 ( & V_37 -> V_38 ) ;
}
void F_16 ( struct V_36 * V_37 ,
struct V_39 * V_40 )
{
struct V_26 * V_27 ;
struct V_24 * V_25 ;
int V_30 ;
T_3 V_41 , V_42 ;
F_17 () ;
V_25 = F_18 ( V_37 -> V_25 ) ;
if ( ! V_25 )
goto V_43;
V_41 = F_19 ( V_40 -> V_44 ) ;
V_42 = F_19 ( V_40 -> V_45 ) ;
F_20 (mactbl, bkt, node, hlist) {
struct V_46 * V_47 = & V_27 -> V_48 ;
struct V_49 * V_48 ;
if ( ( V_27 -> V_50 < V_41 ) ||
( V_27 -> V_50 >= ( V_41 + V_42 ) ) )
continue;
V_48 = & V_40 -> V_51 [ V_27 -> V_50 - V_41 ] ;
memcpy ( V_48 -> V_52 , V_47 -> V_52 ,
F_21 ( V_48 -> V_52 ) ) ;
memcpy ( V_48 -> V_53 , V_47 -> V_53 ,
F_21 ( V_48 -> V_53 ) ) ;
V_48 -> V_54 = F_22 ( V_47 -> V_54 ) ;
}
V_40 -> V_55 = F_22 ( V_37 -> V_56 . V_57 . V_55 ) ;
V_43:
F_23 () ;
}
int F_24 ( struct V_36 * V_37 ,
struct V_39 * V_40 )
{
struct V_26 * V_27 , * V_58 ;
struct V_24 * V_59 , * V_60 ;
int V_61 , V_30 , V_8 = 0 ;
T_1 V_62 ;
T_3 V_41 , V_42 ;
F_11 ( & V_37 -> V_38 ) ;
V_59 = F_6 () ;
if ( F_25 ( V_59 ) ) {
F_15 ( & V_37 -> V_38 ) ;
return F_26 ( V_59 ) ;
}
V_41 = F_19 ( V_40 -> V_44 ) ;
V_42 = F_19 ( V_40 -> V_45 ) ;
for ( V_61 = 0 ; V_61 < V_42 ; V_61 ++ ) {
struct V_46 * V_47 ;
struct V_49 * V_48 =
& V_40 -> V_51 [ V_61 ] ;
T_1 * V_52 = V_48 -> V_52 ;
T_1 V_63 [ V_64 ] = { 0 } ;
F_27 ( L_1 ,
V_41 + V_61 , V_52 [ 0 ] , V_52 [ 1 ] , V_52 [ 2 ] ,
V_52 [ 3 ] , V_52 [ 4 ] , V_52 [ 5 ] ,
V_48 -> V_54 ) ;
if ( ! memcmp ( V_52 , V_63 , F_21 ( V_63 ) ) )
continue;
V_27 = F_7 ( sizeof( * V_27 ) , V_34 ) ;
if ( ! V_27 ) {
V_8 = - V_35 ;
goto V_65;
}
V_27 -> V_50 = V_41 + V_61 ;
V_47 = & V_27 -> V_48 ;
memcpy ( V_47 -> V_52 , V_48 -> V_52 ,
F_21 ( V_47 -> V_52 ) ) ;
memcpy ( V_47 -> V_53 , V_48 -> V_53 ,
F_21 ( V_47 -> V_53 ) ) ;
V_47 -> V_54 = F_28 ( V_48 -> V_54 ) ;
V_62 = V_27 -> V_48 . V_52 [ V_66 ] ;
F_29 ( V_59 , & V_27 -> V_31 , V_62 ) ;
}
V_60 = F_12 ( V_37 -> V_25 ) ;
if ( ! V_60 )
goto V_67;
F_20 (old_mactbl, bkt, node, hlist) {
if ( ( V_27 -> V_50 >= V_41 ) &&
( V_27 -> V_50 < ( V_41 + V_42 ) ) )
continue;
V_58 = F_7 ( sizeof( * V_58 ) , V_34 ) ;
if ( ! V_58 ) {
V_8 = - V_35 ;
goto V_65;
}
V_58 -> V_50 = V_27 -> V_50 ;
memcpy ( & V_58 -> V_48 , & V_27 -> V_48 , sizeof( V_27 -> V_48 ) ) ;
V_62 = V_58 -> V_48 . V_52 [ V_66 ] ;
F_29 ( V_59 , & V_58 -> V_31 , V_62 ) ;
}
V_67:
F_13 ( V_37 -> V_25 , V_59 ) ;
F_14 () ;
V_37 -> V_56 . V_57 . V_55 = F_28 ( V_40 -> V_55 ) ;
V_65:
if ( V_8 )
F_2 ( V_59 ) ;
else
F_2 ( V_60 ) ;
F_15 ( & V_37 -> V_38 ) ;
return V_8 ;
}
static T_4 F_30 ( struct V_36 * V_37 ,
struct V_68 * V_69 )
{
struct V_26 * V_27 ;
struct V_24 * V_25 ;
T_2 V_3 = 0 ;
T_1 V_62 ;
F_17 () ;
V_25 = F_18 ( V_37 -> V_25 ) ;
if ( F_31 ( ! V_25 ) )
goto V_70;
V_62 = V_69 -> V_71 [ V_66 ] ;
F_32 (mactbl, node, hlist, key) {
struct V_46 * V_48 = & V_27 -> V_48 ;
if ( F_31 ( F_33 ( V_48 -> V_54 ) ) )
continue;
if ( ! memcmp ( V_27 -> V_48 . V_52 , V_69 -> V_71 ,
F_21 ( V_27 -> V_48 . V_52 ) ) ) {
V_3 = F_34 ( V_27 -> V_48 . V_54 ) ;
break;
}
}
V_70:
F_23 () ;
return V_3 ;
}
static T_4 F_35 ( struct V_36 * V_37 ,
struct V_72 * V_73 , T_1 V_74 )
{
struct V_75 * V_56 = & V_37 -> V_56 ;
struct V_68 * V_69 = (struct V_68 * ) F_36 ( V_73 ) ;
T_2 V_3 ;
V_3 = F_30 ( V_37 , V_69 ) ;
if ( V_3 )
return V_3 ;
if ( F_37 ( V_69 -> V_71 ) ) {
V_3 = V_56 -> V_76 . V_77 ;
} else {
if ( F_38 ( V_69 -> V_71 ) ) {
V_3 = ( ( T_4 ) V_69 -> V_71 [ 5 ] << 16 ) |
( ( T_4 ) V_69 -> V_71 [ 4 ] << 8 ) |
V_69 -> V_71 [ 3 ] ;
if ( F_31 ( ! V_3 ) )
F_39 ( L_2 ) ;
} else if ( V_74 != V_78 ) {
V_3 = V_56 -> V_76 . V_79 [ V_74 ] ;
}
}
return V_3 ;
}
static T_1 F_40 ( struct V_75 * V_56 ,
struct V_72 * V_73 )
{
struct V_68 * V_69 = (struct V_68 * ) F_36 ( V_73 ) ;
T_3 V_80 ;
T_1 V_7 ;
if ( ! F_41 ( V_73 , & V_80 ) ) {
T_1 V_81 = F_42 ( V_80 ) ;
if ( F_37 ( V_69 -> V_71 ) )
V_7 = V_56 -> V_57 . V_82 [ V_81 ] ;
else
V_7 = V_56 -> V_57 . V_83 [ V_81 ] ;
} else {
if ( F_37 ( V_69 -> V_71 ) )
V_7 = V_56 -> V_57 . V_84 ;
else
V_7 = V_56 -> V_57 . V_85 ;
}
return V_7 ;
}
T_1 F_43 ( struct V_36 * V_37 , struct V_72 * V_73 )
{
struct V_68 * V_69 = (struct V_68 * ) F_36 ( V_73 ) ;
struct V_75 * V_56 = & V_37 -> V_56 ;
T_1 V_86 ;
if ( F_44 ( V_73 ) ) {
T_1 V_81 = F_45 ( V_73 ) >> V_87 ;
if ( F_37 ( V_69 -> V_71 ) )
V_86 = V_56 -> V_57 . V_88 [ V_81 ] ;
else
V_86 = V_56 -> V_57 . V_89 [ V_81 ] ;
} else {
if ( F_37 ( V_69 -> V_71 ) )
V_86 = V_56 -> V_57 . V_90 ;
else
V_86 = V_56 -> V_57 . V_91 ;
}
return V_86 ;
}
T_1 F_46 ( struct V_36 * V_37 , struct V_72 * V_73 )
{
T_3 V_92 ;
V_92 = F_47 ( V_37 -> V_93 , V_73 , F_48 ( 15 ) ) ;
return ( T_1 ) ( ( V_92 >> 8 ) ^ ( V_92 & 0xff ) ) ;
}
static inline T_1 F_49 ( struct V_36 * V_37 ,
T_1 V_6 )
{
T_1 V_94 ;
V_94 = ( ( V_6 & 0xf ) + ( V_6 >> 4 ) ) ;
return V_37 -> V_95 [ V_94 & ( V_96 - 1 ) ] ;
}
static inline int F_50 ( struct V_72 * V_73 )
{
T_2 V_97 ;
V_97 = - ( V_73 -> V_4 + V_98 ) & 0x7 ;
V_97 += V_98 ;
return ( V_73 -> V_4 + V_97 ) >> 3 ;
}
void F_51 ( struct V_36 * V_37 , struct V_72 * V_73 )
{
struct V_75 * V_56 = & V_37 -> V_56 ;
struct V_99 * V_100 ;
T_1 V_74 , V_7 , V_6 , * V_1 ;
T_3 V_4 , V_10 ;
T_2 V_3 ;
V_1 = F_52 ( V_73 , V_23 ) ;
V_6 = F_46 ( V_37 , V_73 ) ;
V_74 = F_49 ( V_37 , V_6 ) ;
V_4 = F_50 ( V_73 ) ;
V_3 = F_35 ( V_37 , V_73 , V_74 ) ;
V_7 = F_40 ( V_56 , V_73 ) ;
V_10 = V_56 -> V_76 . V_101 ;
V_100 = (struct V_99 * ) F_52 ( V_73 , sizeof( * V_100 ) ) ;
V_100 -> V_86 = F_43 ( V_37 , V_73 ) ;
V_100 -> V_6 = V_6 ;
V_100 -> V_102 = 0 ;
if ( F_31 ( ! V_3 ) ) {
V_100 -> V_102 = V_103 ;
return;
}
F_1 ( V_1 , V_56 -> V_57 . V_104 , V_3 , V_4 ,
V_56 -> V_76 . V_5 , V_6 , V_7 , 0 ,
V_105 , V_10 ) ;
}
