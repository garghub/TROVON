static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = (struct V_2 * ) V_1 -> V_4 ;
return ( V_3 -> V_5 == V_6 ) &&
( V_3 -> V_7 == V_8 ) &&
( V_3 -> V_9 == V_10 ) ;
}
static int F_2 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = (struct V_2 * ) V_1 -> V_4 ;
return ( V_3 -> V_5 == V_11 ) &&
( V_3 -> V_7 == V_12 ) ;
}
static int F_3 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = (struct V_2 * ) V_1 -> V_4 ;
return ( V_3 -> V_5 == V_13 ) &&
( V_3 -> V_7 == V_14 ) ;
}
static int F_4 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
T_1 V_15 ;
T_1 V_16 ;
V_3 = (struct V_2 * ) V_1 -> V_4 ;
V_15 = F_5 ( V_3 -> V_9 ) ;
V_16 = F_5 ( V_3 -> V_17 ) ;
if ( ( V_3 -> V_5 == V_18 ) &&
( V_3 -> V_7 == V_19 ) &&
( V_15 == V_20 ) ) {
F_6 ( L_1 , V_16 ) ;
return 1 ;
} else
return 0 ;
}
static int F_7 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
int V_21 ;
int V_22 ;
int V_23 ;
int V_24 ;
V_3 = (struct V_2 * ) V_1 -> V_4 ;
V_21 = F_5 ( V_3 -> V_17 ) & 0x000f ;
V_22 = F_5 ( V_3 -> V_17 ) & 0x0080 ;
if ( V_22 )
V_23 = F_8 ( V_1 -> V_25 , V_21 ) ;
else
V_23 = F_9 ( V_1 -> V_25 , V_21 ) ;
V_24 = F_10 ( V_1 -> V_25 , V_23 ) ;
if ( V_24 < 0 )
F_11 ( & V_1 -> V_25 -> V_25 ,
L_2 ,
V_1 -> V_25 -> V_26 , V_21 , V_24 ) ;
else
F_12 ( & V_1 -> V_25 -> V_25 ,
L_3 ,
V_1 -> V_25 -> V_26 , V_21 ) ;
return V_24 ;
}
static int F_13 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
T_1 V_27 ;
T_1 V_28 ;
int V_24 ;
V_3 = (struct V_2 * ) V_1 -> V_4 ;
V_27 = F_5 ( V_3 -> V_9 ) ;
V_28 = F_5 ( V_3 -> V_17 ) ;
F_6 ( L_4 ,
V_28 , V_27 ) ;
V_24 = F_14 ( V_1 -> V_25 , V_28 , V_27 ) ;
if ( V_24 < 0 )
F_11 ( & V_1 -> V_25 -> V_25 ,
L_5 ,
V_28 , V_27 , V_24 ) ;
else
F_12 ( & V_1 -> V_25 -> V_25 ,
L_6 ,
V_28 , V_27 ) ;
return V_24 ;
}
static int F_15 ( struct V_1 * V_1 )
{
struct V_29 * V_30 = (struct V_29 * ) V_1 -> V_31 ;
struct V_32 * V_33 = V_30 -> V_33 ;
struct V_2 * V_3 ;
T_1 V_34 ;
int V_35 ;
V_3 = (struct V_2 * ) V_1 -> V_4 ;
V_34 = F_5 ( V_3 -> V_9 ) ;
V_35 = F_16 ( V_33 -> V_36 , V_34 ) ;
if ( V_35 && V_35 != - V_37 )
F_11 ( & V_33 -> V_36 -> V_25 , L_7 ,
V_34 , V_35 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_1 )
{
struct V_29 * V_30 = (struct V_29 * ) V_1 -> V_31 ;
struct V_32 * V_33 = V_30 -> V_33 ;
F_12 ( & V_1 -> V_25 -> V_25 , L_8 ) ;
if ( F_18 ( V_33 -> V_36 , NULL ) < 0 ) {
F_11 ( & V_1 -> V_25 -> V_25 , L_9 ) ;
return 0 ;
}
F_19 ( V_33 -> V_36 ) ;
F_20 ( V_33 -> V_36 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_1 )
{
if ( ! V_1 || ! V_1 -> V_4 )
return;
if ( F_22 ( V_1 -> V_38 ) != V_39 )
return;
if ( F_1 ( V_1 ) )
F_7 ( V_1 ) ;
else if ( F_2 ( V_1 ) )
F_13 ( V_1 ) ;
else if ( F_3 ( V_1 ) )
F_15 ( V_1 ) ;
else if ( F_4 ( V_1 ) )
F_17 ( V_1 ) ;
else
F_6 ( L_10 ) ;
}
static int F_23 ( struct V_32 * V_33 ,
struct V_40 * V_41 )
{
int V_24 ;
unsigned long V_42 ;
struct V_29 * V_30 ;
F_24 ( & V_33 -> V_43 , V_42 ) ;
F_25 (priv, &sdev->priv_init, list) {
if ( V_30 -> V_44 != V_41 -> V_45 . V_46 . V_44 )
continue;
F_12 ( & V_30 -> V_1 -> V_25 -> V_25 , L_11 ,
V_30 -> V_1 ) ;
V_30 -> V_47 = 1 ;
V_30 -> V_44 = V_41 -> V_48 . V_44 ;
F_26 ( & V_33 -> V_43 , V_42 ) ;
V_24 = F_27 ( V_30 -> V_1 ) ;
if ( V_24 != - V_49 )
F_11 ( & V_30 -> V_1 -> V_25 -> V_25 ,
L_12 ,
V_30 -> V_1 , V_24 ) ;
return 0 ;
}
F_6 ( L_13 ,
V_41 -> V_45 . V_46 . V_44 ) ;
F_28 ( V_33 , V_41 -> V_48 . V_44 , 0 ) ;
F_26 ( & V_33 -> V_43 , V_42 ) ;
return 0 ;
}
static int F_29 ( struct V_32 * V_33 , struct V_40 * V_41 )
{
struct V_50 * V_51 = & V_33 -> V_51 ;
int V_52 = 0 ;
if ( V_41 -> V_48 . V_53 == V_33 -> V_53 ) {
F_30 ( & V_51 -> V_54 ) ;
if ( V_51 -> V_55 == V_56 ) {
V_52 = 1 ;
}
F_31 ( & V_51 -> V_54 ) ;
}
return V_52 ;
}
static struct V_29 * F_32 ( struct V_32 * V_33 ,
struct V_40 * V_41 )
{
struct V_29 * V_30 ;
struct V_50 * V_51 = & V_33 -> V_51 ;
unsigned long V_42 ;
F_24 ( & V_33 -> V_43 , V_42 ) ;
V_30 = F_33 ( V_57 , V_58 ) ;
if ( ! V_30 ) {
F_11 ( & V_33 -> V_36 -> V_25 , L_14 ) ;
F_26 ( & V_33 -> V_43 , V_42 ) ;
F_34 ( V_51 , V_59 ) ;
return NULL ;
}
V_30 -> V_44 = V_41 -> V_48 . V_44 ;
V_30 -> V_33 = V_33 ;
F_35 ( & V_30 -> V_60 , & V_33 -> V_61 ) ;
F_26 ( & V_33 -> V_43 , V_42 ) ;
return V_30 ;
}
static int F_36 ( struct V_32 * V_33 , int V_62 , int V_63 )
{
struct V_64 * V_36 = V_33 -> V_36 ;
struct V_65 * V_66 ;
struct V_67 * V_68 = NULL ;
if ( V_63 == V_69 )
V_66 = V_36 -> V_70 [ V_62 & 0x7f ] ;
else
V_66 = V_36 -> V_71 [ V_62 & 0x7f ] ;
if ( ! V_66 ) {
F_11 ( & V_33 -> V_36 -> V_25 , L_15 ,
V_62 ) ;
F_37 () ;
}
V_68 = & V_66 -> V_72 ;
if ( F_38 ( V_68 ) ) {
if ( V_63 == V_73 )
return F_9 ( V_36 , V_62 ) ;
else
return F_8 ( V_36 , V_62 ) ;
}
if ( F_39 ( V_68 ) ) {
if ( V_63 == V_73 )
return F_40 ( V_36 , V_62 ) ;
else
return F_41 ( V_36 , V_62 ) ;
}
if ( F_42 ( V_68 ) ) {
if ( V_63 == V_73 )
return F_43 ( V_36 , V_62 ) ;
else
return F_44 ( V_36 , V_62 ) ;
}
if ( F_45 ( V_68 ) ) {
if ( V_63 == V_73 )
return F_46 ( V_36 , V_62 ) ;
else
return F_47 ( V_36 , V_62 ) ;
}
F_11 ( & V_33 -> V_36 -> V_25 , L_16 , V_62 ) ;
return 0 ;
}
static void F_48 ( struct V_1 * V_1 )
{
int V_74 ;
struct V_64 * V_25 ;
struct V_65 * V_66 ;
int V_75 ;
unsigned int V_76 ;
if ( ! V_1 || V_1 -> V_77 || ! V_1 -> V_78 )
return;
V_25 = V_1 -> V_25 ;
if ( ( ! V_25 ) || ( V_25 -> V_79 < V_80 ) )
return;
V_66 = ( F_49 ( V_1 -> V_38 ) ? V_25 -> V_70 : V_25 -> V_71 )
[ F_50 ( V_1 -> V_38 ) ] ;
if ( ! V_66 )
return;
V_74 = F_51 ( & V_66 -> V_72 ) ;
if ( V_74 == V_81 ) {
struct V_2 * V_82 =
(struct V_2 * ) V_1 -> V_4 ;
if ( ! V_82 )
return;
V_75 = ! ( V_82 -> V_7 & V_83 ) ||
! V_82 -> V_84 ;
} else {
V_75 = F_52 ( & V_66 -> V_72 ) ;
}
V_76 = ( V_85 | V_86 |
V_87 | V_88 ) ;
switch ( V_74 ) {
case V_89 :
if ( V_75 )
V_76 |= V_90 ;
case V_81 :
V_76 |= V_91 ;
default:
if ( ! V_75 )
V_76 |= V_92 ;
break;
case V_93 :
V_76 |= V_94 ;
break;
}
V_1 -> V_95 &= V_76 ;
}
static void F_53 ( struct V_32 * V_33 ,
struct V_40 * V_41 )
{
int V_24 ;
struct V_29 * V_30 ;
struct V_50 * V_51 = & V_33 -> V_51 ;
struct V_64 * V_36 = V_33 -> V_36 ;
int V_38 = F_36 ( V_33 , V_41 -> V_48 . V_66 , V_41 -> V_48 . V_96 ) ;
V_30 = F_32 ( V_33 , V_41 ) ;
if ( ! V_30 )
return;
if ( F_54 ( V_38 ) )
V_30 -> V_1 = F_55 ( V_41 -> V_45 . V_97 . V_98 ,
V_99 ) ;
else
V_30 -> V_1 = F_55 ( 0 , V_99 ) ;
if ( ! V_30 -> V_1 ) {
F_11 ( & V_36 -> V_25 , L_17 ) ;
F_34 ( V_51 , V_59 ) ;
return;
}
if ( V_41 -> V_45 . V_97 . V_100 > 0 ) {
V_30 -> V_1 -> V_101 =
F_56 ( V_41 -> V_45 . V_97 . V_100 ,
V_99 ) ;
if ( ! V_30 -> V_1 -> V_101 ) {
F_34 ( V_51 , V_59 ) ;
return;
}
}
V_30 -> V_1 -> V_4 = F_57 ( & V_41 -> V_45 . V_97 . V_82 , 8 ,
V_99 ) ;
if ( ! V_30 -> V_1 -> V_4 ) {
F_11 ( & V_36 -> V_25 , L_18 ) ;
F_34 ( V_51 , V_59 ) ;
return;
}
V_30 -> V_1 -> V_31 = ( void * ) V_30 ;
V_30 -> V_1 -> V_25 = V_36 ;
V_30 -> V_1 -> V_38 = V_38 ;
V_30 -> V_1 -> V_78 = V_102 ;
F_58 ( V_41 , V_30 -> V_1 , V_103 , 0 ) ;
if ( F_59 ( V_51 , V_30 -> V_1 ) < 0 )
return;
if ( F_60 ( V_51 , V_30 -> V_1 ) < 0 )
return;
F_21 ( V_30 -> V_1 ) ;
F_48 ( V_30 -> V_1 ) ;
V_24 = F_61 ( V_30 -> V_1 , V_99 ) ;
if ( V_24 == 0 )
F_6 ( L_19 ,
V_41 -> V_48 . V_44 ) ;
else {
F_11 ( & V_36 -> V_25 , L_20 , V_24 ) ;
F_62 ( V_41 ) ;
F_63 ( V_30 -> V_1 ) ;
F_34 ( V_51 , V_104 ) ;
}
F_6 ( L_21 ) ;
}
static void F_64 ( struct V_50 * V_51 )
{
int V_24 ;
struct V_40 V_41 ;
struct V_32 * V_33 = F_65 ( V_51 , struct V_32 , V_51 ) ;
struct V_105 * V_25 = & V_33 -> V_36 -> V_25 ;
F_6 ( L_22 ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_24 = F_66 ( V_51 -> V_106 , & V_41 , sizeof( V_41 ) ) ;
if ( V_24 != sizeof( V_41 ) ) {
F_11 ( V_25 , L_23 , V_24 ) ;
F_34 ( V_51 , V_107 ) ;
return;
}
F_67 ( & V_41 , 0 ) ;
if ( V_108 )
F_62 ( & V_41 ) ;
if ( ! F_29 ( V_33 , & V_41 ) ) {
F_11 ( V_25 , L_24 ) ;
F_34 ( V_51 , V_107 ) ;
return;
}
switch ( V_41 . V_48 . V_109 ) {
case V_110 :
F_23 ( V_33 , & V_41 ) ;
break;
case V_103 :
F_53 ( V_33 , & V_41 ) ;
break;
default:
F_11 ( V_25 , L_25 ) ;
F_34 ( V_51 , V_107 ) ;
break;
}
}
int F_68 ( void * V_111 )
{
struct V_50 * V_51 = V_111 ;
while ( ! F_69 () ) {
if ( F_70 ( V_51 ) )
break;
F_64 ( V_51 ) ;
}
return 0 ;
}
