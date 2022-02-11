int F_1 ( T_1 V_1 , T_1 V_2 ,
T_1 V_3 , T_1 V_4 ,
const struct V_5 * V_6 )
{
unsigned int V_7 , V_8 ;
V_7 = V_6 -> V_9 << 16 ;
V_8 = V_6 -> V_10 << 16 ;
if ( V_3 > V_7 ||
V_1 > V_7 - V_3 ||
V_4 > V_8 ||
V_2 > V_8 - V_4 ) {
F_2 ( L_1
L_2 ,
V_3 >> 16 , ( ( V_3 & 0xffff ) * 15625 ) >> 10 ,
V_4 >> 16 , ( ( V_4 & 0xffff ) * 15625 ) >> 10 ,
V_1 >> 16 , ( ( V_1 & 0xffff ) * 15625 ) >> 10 ,
V_2 >> 16 , ( ( V_2 & 0xffff ) * 15625 ) >> 10 ) ;
return - V_11 ;
}
return 0 ;
}
int F_3 ( struct V_12 * V_13 ,
void * V_14 , struct V_15 * V_16 )
{
struct V_17 * V_18 = V_14 ;
struct V_19 V_20 = {} ;
int V_21 ;
V_20 . V_22 = V_18 -> V_22 ;
V_20 . V_9 = V_18 -> V_9 ;
V_20 . V_10 = V_18 -> V_10 ;
V_20 . V_23 [ 0 ] = V_18 -> V_24 ;
V_20 . V_25 = F_4 ( V_18 -> V_26 , V_18 -> V_27 ) ;
V_20 . V_28 [ 0 ] = V_18 -> V_29 ;
V_21 = F_5 ( V_13 , & V_20 , V_16 ) ;
if ( V_21 )
return V_21 ;
V_18 -> V_22 = V_20 . V_22 ;
return 0 ;
}
static int F_6 ( const struct V_19 * V_20 )
{
const struct V_30 * V_31 ;
int V_32 ;
V_31 = F_7 ( V_20 -> V_25 & ~ V_33 ) ;
if ( ! V_31 ) {
struct V_34 V_35 ;
F_2 ( L_3 ,
F_8 ( V_20 -> V_25 ,
& V_35 ) ) ;
return - V_36 ;
}
if ( V_20 -> V_9 == 0 || V_20 -> V_9 % V_31 -> V_37 ) {
F_2 ( L_4 , V_20 -> V_9 ) ;
return - V_36 ;
}
if ( V_20 -> V_10 == 0 || V_20 -> V_10 % V_31 -> V_38 ) {
F_2 ( L_5 , V_20 -> V_10 ) ;
return - V_36 ;
}
for ( V_32 = 0 ; V_32 < V_31 -> V_39 ; V_32 ++ ) {
unsigned int V_9 = V_20 -> V_9 / ( V_32 != 0 ? V_31 -> V_37 : 1 ) ;
unsigned int V_10 = V_20 -> V_10 / ( V_32 != 0 ? V_31 -> V_38 : 1 ) ;
unsigned int V_40 = V_31 -> V_40 [ V_32 ] ;
if ( ! V_20 -> V_28 [ V_32 ] ) {
F_2 ( L_6 , V_32 ) ;
return - V_36 ;
}
if ( ( V_41 ) V_9 * V_40 > V_42 )
return - V_43 ;
if ( ( V_41 ) V_10 * V_20 -> V_23 [ V_32 ] + V_20 -> V_44 [ V_32 ] > V_42 )
return - V_43 ;
if ( V_20 -> V_23 [ V_32 ] < V_9 * V_40 ) {
F_2 ( L_7 , V_20 -> V_23 [ V_32 ] , V_32 ) ;
return - V_36 ;
}
if ( V_20 -> V_45 [ V_32 ] && ! ( V_20 -> V_46 & V_47 ) ) {
F_2 ( L_8 ,
V_20 -> V_45 [ V_32 ] , V_32 ) ;
return - V_36 ;
}
if ( V_20 -> V_46 & V_47 &&
V_20 -> V_45 [ V_32 ] != V_20 -> V_45 [ 0 ] ) {
F_2 ( L_8 ,
V_20 -> V_45 [ V_32 ] , V_32 ) ;
return - V_36 ;
}
switch ( V_20 -> V_45 [ V_32 ] ) {
case V_48 :
if ( V_20 -> V_25 != V_49 ||
V_9 % 128 || V_10 % 32 ||
V_20 -> V_23 [ V_32 ] % 128 ) {
F_2 ( L_9 , V_32 ) ;
return - V_36 ;
}
break;
default:
break;
}
}
for ( V_32 = V_31 -> V_39 ; V_32 < 4 ; V_32 ++ ) {
if ( V_20 -> V_45 [ V_32 ] ) {
F_2 ( L_10 , V_32 ) ;
return - V_36 ;
}
if ( ! ( V_20 -> V_46 & V_47 ) )
continue;
if ( V_20 -> V_28 [ V_32 ] ) {
F_2 ( L_11 , V_32 ) ;
return - V_36 ;
}
if ( V_20 -> V_23 [ V_32 ] ) {
F_2 ( L_12 , V_32 ) ;
return - V_36 ;
}
if ( V_20 -> V_44 [ V_32 ] ) {
F_2 ( L_13 , V_32 ) ;
return - V_36 ;
}
}
return 0 ;
}
struct V_5 *
F_9 ( struct V_12 * V_13 ,
const struct V_19 * V_20 ,
struct V_15 * V_16 )
{
struct V_50 * V_51 = & V_13 -> V_52 ;
struct V_5 * V_6 ;
int V_21 ;
if ( V_20 -> V_46 & ~ ( V_53 | V_47 ) ) {
F_2 ( L_14 , V_20 -> V_46 ) ;
return F_10 ( - V_36 ) ;
}
if ( ( V_51 -> V_54 > V_20 -> V_9 ) || ( V_20 -> V_9 > V_51 -> V_55 ) ) {
F_2 ( L_15 ,
V_20 -> V_9 , V_51 -> V_54 , V_51 -> V_55 ) ;
return F_10 ( - V_36 ) ;
}
if ( ( V_51 -> V_56 > V_20 -> V_10 ) || ( V_20 -> V_10 > V_51 -> V_57 ) ) {
F_2 ( L_16 ,
V_20 -> V_10 , V_51 -> V_56 , V_51 -> V_57 ) ;
return F_10 ( - V_36 ) ;
}
if ( V_20 -> V_46 & V_47 &&
! V_13 -> V_52 . V_58 ) {
F_2 ( L_17 ) ;
return F_10 ( - V_36 ) ;
}
V_21 = F_6 ( V_20 ) ;
if ( V_21 )
return F_10 ( V_21 ) ;
V_6 = V_13 -> V_52 . V_59 -> V_60 ( V_13 , V_16 , V_20 ) ;
if ( F_11 ( V_6 ) ) {
F_2 ( L_18 ) ;
return V_6 ;
}
return V_6 ;
}
int F_5 ( struct V_12 * V_13 ,
void * V_14 , struct V_15 * V_16 )
{
struct V_19 * V_20 = V_14 ;
struct V_5 * V_6 ;
if ( ! F_12 ( V_13 , V_61 ) )
return - V_36 ;
V_6 = F_9 ( V_13 , V_20 , V_16 ) ;
if ( F_11 ( V_6 ) )
return F_13 ( V_6 ) ;
F_2 ( L_19 , V_6 -> V_62 . V_63 ) ;
V_20 -> V_22 = V_6 -> V_62 . V_63 ;
F_14 ( & V_16 -> V_64 ) ;
F_15 ( & V_6 -> V_65 , & V_16 -> V_66 ) ;
F_16 ( & V_16 -> V_64 ) ;
return 0 ;
}
static void F_17 ( struct V_67 * V_68 )
{
struct V_69 * V_70 = F_18 ( V_68 , F_19 ( * V_70 ) , V_71 ) ;
while ( ! F_20 ( & V_70 -> V_66 ) ) {
struct V_5 * V_6 =
F_21 ( & V_70 -> V_66 , F_19 ( * V_6 ) , V_65 ) ;
F_22 ( & V_6 -> V_65 ) ;
F_23 ( V_6 ) ;
}
}
int F_24 ( struct V_12 * V_13 ,
void * V_14 , struct V_15 * V_16 )
{
struct V_5 * V_6 = NULL ;
struct V_5 * V_72 = NULL ;
T_1 * V_63 = V_14 ;
int V_73 = 0 ;
if ( ! F_12 ( V_13 , V_61 ) )
return - V_36 ;
V_6 = F_25 ( V_13 , * V_63 ) ;
if ( ! V_6 )
return - V_74 ;
F_14 ( & V_16 -> V_64 ) ;
F_26 (fbl, &file_priv->fbs, filp_head)
if ( V_6 == V_72 )
V_73 = 1 ;
if ( ! V_73 ) {
F_16 ( & V_16 -> V_64 ) ;
goto V_75;
}
F_22 ( & V_6 -> V_65 ) ;
F_16 ( & V_16 -> V_64 ) ;
F_27 ( V_6 ) ;
if ( F_28 ( V_6 ) > 1 ) {
struct V_69 V_70 ;
F_29 ( & V_70 . V_71 , F_17 ) ;
F_30 ( & V_70 . V_66 ) ;
F_31 ( & V_6 -> V_65 , & V_70 . V_66 ) ;
F_32 ( & V_70 . V_71 ) ;
F_33 ( & V_70 . V_71 ) ;
F_34 ( & V_70 . V_71 ) ;
} else
F_27 ( V_6 ) ;
return 0 ;
V_75:
F_27 ( V_6 ) ;
return - V_74 ;
}
int F_35 ( struct V_12 * V_13 ,
void * V_14 , struct V_15 * V_16 )
{
struct V_17 * V_20 = V_14 ;
struct V_5 * V_6 ;
int V_21 ;
if ( ! F_12 ( V_13 , V_61 ) )
return - V_36 ;
V_6 = F_25 ( V_13 , V_20 -> V_22 ) ;
if ( ! V_6 )
return - V_74 ;
V_20 -> V_10 = V_6 -> V_10 ;
V_20 -> V_9 = V_6 -> V_9 ;
V_20 -> V_27 = V_6 -> V_27 ;
V_20 -> V_26 = V_6 -> V_76 ;
V_20 -> V_24 = V_6 -> V_23 [ 0 ] ;
if ( V_6 -> V_59 -> V_77 ) {
if ( F_36 ( V_16 ) || F_37 ( V_78 ) ||
F_38 ( V_16 ) ) {
V_21 = V_6 -> V_59 -> V_77 ( V_6 , V_16 ,
& V_20 -> V_29 ) ;
} else {
V_20 -> V_29 = 0 ;
V_21 = 0 ;
}
} else {
V_21 = - V_79 ;
}
F_27 ( V_6 ) ;
return V_21 ;
}
int F_39 ( struct V_12 * V_13 ,
void * V_14 , struct V_15 * V_16 )
{
struct V_80 T_2 * V_81 ;
struct V_80 * V_82 = NULL ;
struct V_83 * V_20 = V_14 ;
struct V_5 * V_6 ;
unsigned V_46 ;
int V_84 ;
int V_21 ;
if ( ! F_12 ( V_13 , V_61 ) )
return - V_36 ;
V_6 = F_25 ( V_13 , V_20 -> V_22 ) ;
if ( ! V_6 )
return - V_74 ;
V_84 = V_20 -> V_84 ;
V_81 = (struct V_80 T_2 * ) ( unsigned long ) V_20 -> V_81 ;
if ( ! V_84 != ! V_81 ) {
V_21 = - V_36 ;
goto V_85;
}
V_46 = V_86 & V_20 -> V_46 ;
if ( V_46 & V_87 && ( V_84 % 2 ) ) {
V_21 = - V_36 ;
goto V_85;
}
if ( V_84 && V_81 ) {
if ( V_84 < 0 || V_84 > V_88 ) {
V_21 = - V_36 ;
goto V_85;
}
V_82 = F_40 ( V_84 , sizeof( * V_82 ) , V_89 ) ;
if ( ! V_82 ) {
V_21 = - V_90 ;
goto V_85;
}
V_21 = F_41 ( V_82 , V_81 ,
V_84 * sizeof( * V_82 ) ) ;
if ( V_21 ) {
V_21 = - V_91 ;
goto V_92;
}
}
if ( V_6 -> V_59 -> V_93 ) {
V_21 = V_6 -> V_59 -> V_93 ( V_6 , V_16 , V_46 , V_20 -> V_94 ,
V_82 , V_84 ) ;
} else {
V_21 = - V_95 ;
}
V_92:
F_42 ( V_82 ) ;
V_85:
F_27 ( V_6 ) ;
return V_21 ;
}
void F_43 ( struct V_15 * V_96 )
{
struct V_5 * V_6 , * V_97 ;
struct V_69 V_70 ;
F_30 ( & V_70 . V_66 ) ;
F_44 (fb, tfb, &priv->fbs, filp_head) {
if ( F_28 ( V_6 ) > 1 ) {
F_45 ( & V_6 -> V_65 , & V_70 . V_66 ) ;
} else {
F_22 ( & V_6 -> V_65 ) ;
F_27 ( V_6 ) ;
}
}
if ( ! F_20 ( & V_70 . V_66 ) ) {
F_29 ( & V_70 . V_71 , F_17 ) ;
F_32 ( & V_70 . V_71 ) ;
F_33 ( & V_70 . V_71 ) ;
F_34 ( & V_70 . V_71 ) ;
}
}
void F_46 ( struct V_98 * V_98 )
{
struct V_5 * V_6 =
F_18 ( V_98 , struct V_5 , V_62 . V_99 ) ;
struct V_12 * V_13 = V_6 -> V_13 ;
F_47 ( V_13 , & V_6 -> V_62 ) ;
V_6 -> V_59 -> V_100 ( V_6 ) ;
}
int F_48 ( struct V_12 * V_13 , struct V_5 * V_6 ,
const struct V_101 * V_59 )
{
int V_21 ;
F_30 ( & V_6 -> V_65 ) ;
V_6 -> V_13 = V_13 ;
V_6 -> V_59 = V_59 ;
V_21 = F_49 ( V_13 , & V_6 -> V_62 , V_102 ,
false , F_46 ) ;
if ( V_21 )
goto V_103;
F_14 ( & V_13 -> V_52 . V_104 ) ;
V_13 -> V_52 . V_105 ++ ;
F_15 ( & V_6 -> V_106 , & V_13 -> V_52 . V_107 ) ;
F_16 ( & V_13 -> V_52 . V_104 ) ;
F_50 ( V_13 , & V_6 -> V_62 ) ;
V_103:
return V_21 ;
}
struct V_5 * F_25 ( struct V_12 * V_13 ,
T_1 V_63 )
{
struct V_108 * V_109 ;
struct V_5 * V_6 = NULL ;
V_109 = F_51 ( V_13 , V_63 , V_102 ) ;
if ( V_109 )
V_6 = F_52 ( V_109 ) ;
return V_6 ;
}
void F_53 ( struct V_5 * V_6 )
{
struct V_12 * V_13 ;
if ( ! V_6 )
return;
V_13 = V_6 -> V_13 ;
F_47 ( V_13 , & V_6 -> V_62 ) ;
}
void F_54 ( struct V_5 * V_6 )
{
struct V_12 * V_13 = V_6 -> V_13 ;
F_14 ( & V_13 -> V_52 . V_104 ) ;
F_55 ( & V_6 -> V_106 ) ;
V_13 -> V_52 . V_105 -- ;
F_16 ( & V_13 -> V_52 . V_104 ) ;
}
void F_23 ( struct V_5 * V_6 )
{
struct V_12 * V_13 ;
struct V_110 * V_111 ;
struct V_112 * V_113 ;
if ( ! V_6 )
return;
V_13 = V_6 -> V_13 ;
F_56 ( ! F_20 ( & V_6 -> V_65 ) ) ;
if ( F_28 ( V_6 ) > 1 ) {
F_57 ( V_13 ) ;
F_58 (crtc, dev) {
if ( V_111 -> V_114 -> V_6 == V_6 ) {
if ( F_59 ( V_111 ) )
F_60 ( L_20 , V_111 ) ;
}
}
F_61 (plane, dev) {
if ( V_113 -> V_6 == V_6 )
F_62 ( V_113 ) ;
}
F_63 ( V_13 ) ;
}
F_27 ( V_6 ) ;
}
