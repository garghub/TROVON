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
F_11 ( & V_1 -> V_25 -> V_25 , L_2
L_3 , V_1 -> V_25 -> V_26 , V_21 , V_24 ) ;
else
F_12 ( & V_1 -> V_25 -> V_25 , L_4
L_5 , V_1 -> V_25 -> V_26 , V_21 ) ;
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
F_6 ( L_6 ,
V_28 , V_27 ) ;
V_24 = F_14 ( V_1 -> V_25 , V_28 , V_27 ) ;
if ( V_24 < 0 )
F_11 ( & V_1 -> V_25 -> V_25 , L_7
L_8 , V_28 , V_27 , V_24 ) ;
else
F_12 ( & V_1 -> V_25 -> V_25 , L_9
L_10 , V_28 , V_27 ) ;
return V_24 ;
}
static int F_15 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
T_1 V_29 ;
V_3 = (struct V_2 * ) V_1 -> V_4 ;
V_29 = F_5 ( V_3 -> V_9 ) ;
F_12 ( & V_1 -> V_25 -> V_25 , L_11 ,
V_29 , F_16 ( & V_1 -> V_25 -> V_25 ) ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_1 )
{
struct V_30 * V_31 = (struct V_30 * ) V_1 -> V_32 ;
struct V_33 * V_34 = V_31 -> V_34 ;
F_12 ( & V_1 -> V_25 -> V_25 , L_12 ) ;
if ( F_18 ( V_34 -> V_35 , V_34 -> V_28 ) < 0 ) {
F_11 ( & V_1 -> V_25 -> V_25 , L_13 ) ;
return 0 ;
}
F_19 ( V_34 -> V_35 ) ;
F_20 ( V_34 -> V_35 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_1 )
{
if ( ! V_1 || ! V_1 -> V_4 )
return;
if ( F_22 ( V_1 -> V_36 ) != V_37 )
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
F_6 ( L_14 ) ;
}
static int F_23 ( struct V_33 * V_34 ,
struct V_38 * V_39 )
{
unsigned long V_40 ;
struct V_30 * V_31 ;
F_24 ( & V_34 -> V_41 , V_40 ) ;
F_25 (priv, &sdev->priv_init, list) {
if ( V_31 -> V_42 == V_39 -> V_43 . V_44 . V_42 ) {
int V_24 ;
F_12 ( & V_31 -> V_1 -> V_25 -> V_25 , L_15 ,
V_31 -> V_1 ) ;
V_31 -> V_45 = 1 ;
V_31 -> V_42 = V_39 -> V_46 . V_42 ;
F_26 ( & V_34 -> V_41 , V_40 ) ;
V_24 = F_27 ( V_31 -> V_1 ) ;
if ( V_24 != - V_47 )
F_11 ( & V_31 -> V_1 -> V_25 -> V_25 ,
L_16 ,
V_31 -> V_1 , V_24 ) ;
return 0 ;
}
}
F_6 ( L_17 ,
V_39 -> V_43 . V_44 . V_42 ) ;
F_28 ( V_34 , V_39 -> V_46 . V_42 , 0 ) ;
F_26 ( & V_34 -> V_41 , V_40 ) ;
return 0 ;
}
static int F_29 ( struct V_33 * V_34 , struct V_38 * V_39 )
{
struct V_48 * V_49 = & V_34 -> V_49 ;
int V_50 = 0 ;
if ( V_39 -> V_46 . V_51 == V_34 -> V_51 ) {
F_30 ( & V_49 -> V_52 ) ;
if ( V_49 -> V_53 == V_54 ) {
V_50 = 1 ;
}
F_31 ( & V_49 -> V_52 ) ;
}
return V_50 ;
}
static struct V_30 * F_32 ( struct V_33 * V_34 ,
struct V_38 * V_39 )
{
struct V_30 * V_31 ;
struct V_48 * V_49 = & V_34 -> V_49 ;
unsigned long V_40 ;
F_24 ( & V_34 -> V_41 , V_40 ) ;
V_31 = F_33 ( V_55 , V_56 ) ;
if ( ! V_31 ) {
F_11 ( & V_34 -> V_28 -> V_25 , L_18 ) ;
F_26 ( & V_34 -> V_41 , V_40 ) ;
F_34 ( V_49 , V_57 ) ;
return NULL ;
}
V_31 -> V_42 = V_39 -> V_46 . V_42 ;
V_31 -> V_34 = V_34 ;
F_35 ( & V_31 -> V_58 , & V_34 -> V_59 ) ;
F_26 ( & V_34 -> V_41 , V_40 ) ;
return V_31 ;
}
static int F_36 ( struct V_33 * V_34 , int V_60 , int V_61 )
{
struct V_62 * V_35 = V_34 -> V_35 ;
struct V_63 * V_64 ;
struct V_65 * V_66 = NULL ;
if ( V_61 == V_67 )
V_64 = V_35 -> V_68 [ V_60 & 0x7f ] ;
else
V_64 = V_35 -> V_69 [ V_60 & 0x7f ] ;
if ( ! V_64 ) {
F_11 ( & V_34 -> V_28 -> V_25 , L_19 ,
V_60 ) ;
F_37 () ;
}
V_66 = & V_64 -> V_70 ;
if ( F_38 ( V_66 ) ) {
if ( V_61 == V_71 )
return F_9 ( V_35 , V_60 ) ;
else
return F_8 ( V_35 , V_60 ) ;
}
if ( F_39 ( V_66 ) ) {
if ( V_61 == V_71 )
return F_40 ( V_35 , V_60 ) ;
else
return F_41 ( V_35 , V_60 ) ;
}
if ( F_42 ( V_66 ) ) {
if ( V_61 == V_71 )
return F_43 ( V_35 , V_60 ) ;
else
return F_44 ( V_35 , V_60 ) ;
}
if ( F_45 ( V_66 ) ) {
if ( V_61 == V_71 )
return F_46 ( V_35 , V_60 ) ;
else
return F_47 ( V_35 , V_60 ) ;
}
F_11 ( & V_34 -> V_28 -> V_25 , L_20 , V_60 ) ;
return 0 ;
}
static void F_48 ( struct V_1 * V_1 )
{
int V_72 ;
struct V_62 * V_25 ;
struct V_63 * V_64 ;
int V_73 ;
unsigned int V_74 ;
if ( ! V_1 || V_1 -> V_75 || ! V_1 -> V_76 )
return;
V_25 = V_1 -> V_25 ;
if ( ( ! V_25 ) || ( V_25 -> V_77 < V_78 ) )
return;
V_64 = ( F_49 ( V_1 -> V_36 ) ? V_25 -> V_68 : V_25 -> V_69 )
[ F_50 ( V_1 -> V_36 ) ] ;
if ( ! V_64 )
return;
V_72 = F_51 ( & V_64 -> V_70 ) ;
if ( V_72 == V_79 ) {
struct V_2 * V_80 =
(struct V_2 * ) V_1 -> V_4 ;
if ( ! V_80 )
return;
V_73 = ! ( V_80 -> V_7 & V_81 ) ||
! V_80 -> V_82 ;
} else {
V_73 = F_52 ( & V_64 -> V_70 ) ;
}
V_74 = ( V_83 | V_84 |
V_85 | V_86 ) ;
switch ( V_72 ) {
case V_87 :
if ( V_73 )
V_74 |= V_88 ;
case V_79 :
V_74 |= V_89 ;
default:
if ( ! V_73 )
V_74 |= V_90 ;
break;
case V_91 :
V_74 |= V_92 ;
break;
}
V_1 -> V_93 &= V_74 ;
}
static void F_53 ( struct V_33 * V_34 ,
struct V_38 * V_39 )
{
int V_24 ;
struct V_30 * V_31 ;
struct V_48 * V_49 = & V_34 -> V_49 ;
struct V_62 * V_35 = V_34 -> V_35 ;
int V_36 = F_36 ( V_34 , V_39 -> V_46 . V_64 , V_39 -> V_46 . V_94 ) ;
V_31 = F_32 ( V_34 , V_39 ) ;
if ( ! V_31 )
return;
if ( F_54 ( V_36 ) )
V_31 -> V_1 = F_55 ( V_39 -> V_43 . V_95 . V_96 ,
V_97 ) ;
else
V_31 -> V_1 = F_55 ( 0 , V_97 ) ;
if ( ! V_31 -> V_1 ) {
F_11 ( & V_34 -> V_28 -> V_25 , L_21 ) ;
F_34 ( V_49 , V_57 ) ;
return;
}
if ( V_39 -> V_43 . V_95 . V_98 > 0 ) {
V_31 -> V_1 -> V_99 =
F_56 ( V_39 -> V_43 . V_95 . V_98 ,
V_97 ) ;
if ( ! V_31 -> V_1 -> V_99 ) {
F_11 ( & V_34 -> V_28 -> V_25 , L_22 ) ;
F_34 ( V_49 , V_57 ) ;
return;
}
}
V_31 -> V_1 -> V_4 = F_57 ( & V_39 -> V_43 . V_95 . V_80 , 8 ,
V_97 ) ;
if ( ! V_31 -> V_1 -> V_4 ) {
F_11 ( & V_34 -> V_28 -> V_25 , L_23 ) ;
F_34 ( V_49 , V_57 ) ;
return;
}
V_31 -> V_1 -> V_32 = ( void * ) V_31 ;
V_31 -> V_1 -> V_25 = V_35 ;
V_31 -> V_1 -> V_36 = V_36 ;
V_31 -> V_1 -> V_76 = V_100 ;
F_58 ( V_39 , V_31 -> V_1 , V_101 , 0 ) ;
if ( F_59 ( V_49 , V_31 -> V_1 ) < 0 )
return;
if ( F_60 ( V_49 , V_31 -> V_1 ) < 0 )
return;
F_21 ( V_31 -> V_1 ) ;
F_48 ( V_31 -> V_1 ) ;
V_24 = F_61 ( V_31 -> V_1 , V_97 ) ;
if ( V_24 == 0 )
F_6 ( L_24 ,
V_39 -> V_46 . V_42 ) ;
else {
F_11 ( & V_34 -> V_28 -> V_25 , L_25 , V_24 ) ;
F_62 ( V_39 ) ;
F_63 ( V_31 -> V_1 ) ;
F_34 ( V_49 , V_102 ) ;
}
F_6 ( L_26 ) ;
return;
}
static void F_64 ( struct V_48 * V_49 )
{
int V_24 ;
struct V_38 V_39 ;
struct V_33 * V_34 = F_65 ( V_49 , struct V_33 , V_49 ) ;
struct V_103 * V_25 = & V_34 -> V_28 -> V_25 ;
F_6 ( L_27 ) ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
V_24 = F_66 ( V_49 -> V_104 , & V_39 , sizeof( V_39 ) ) ;
if ( V_24 != sizeof( V_39 ) ) {
F_11 ( V_25 , L_28 , V_24 ) ;
F_34 ( V_49 , V_105 ) ;
return;
}
F_67 ( & V_39 , 0 ) ;
if ( V_106 )
F_62 ( & V_39 ) ;
if ( ! F_29 ( V_34 , & V_39 ) ) {
F_11 ( V_25 , L_29 ) ;
F_34 ( V_49 , V_105 ) ;
return;
}
switch ( V_39 . V_46 . V_107 ) {
case V_108 :
F_23 ( V_34 , & V_39 ) ;
break;
case V_101 :
F_53 ( V_34 , & V_39 ) ;
break;
default:
F_11 ( V_25 , L_30 ) ;
F_34 ( V_49 , V_105 ) ;
break;
}
}
int F_68 ( void * V_109 )
{
struct V_48 * V_49 = V_109 ;
while ( ! F_69 () ) {
if ( F_70 ( V_49 ) )
break;
F_64 ( V_49 ) ;
}
return 0 ;
}
