static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 * V_4 ;
V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
* V_4 = V_3 ;
}
static inline T_1 F_3 ( struct V_1 * V_2 )
{
T_1 * V_4 ;
V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
return * V_4 ;
}
static void F_4 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
T_2 * V_9 ;
struct V_10 * V_11 ;
int V_12 ;
F_5 ( V_2 -> V_5 . V_13 != ( unsigned int ) ( F_6 ( V_8 ) -> V_14 + 1 ) ) ;
V_11 = V_2 -> V_5 . V_6 ;
F_7 ( V_11 , V_8 -> V_4 , F_8 ( V_8 ) ) ;
for ( V_12 = 0 ; V_12 < F_6 ( V_8 ) -> V_14 ; V_12 ++ ) {
V_11 = F_9 ( V_11 ) ;
F_5 ( ! V_11 ) ;
V_9 = & F_6 ( V_8 ) -> V_15 [ V_12 ] ;
F_10 ( V_11 , V_9 -> V_16 . V_17 , V_9 -> V_18 , V_9 -> V_19 ) ;
}
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
V_8 = V_2 -> V_20 ;
F_12 ( L_1 , V_2 , V_2 -> V_20 ,
V_8 ) ;
V_2 -> V_21 = NULL ;
F_13 ( V_8 ) ;
F_14 ( V_2 ) ;
}
static struct V_1 * F_15 ( struct V_22 * V_23 ,
struct V_7 * V_8 , T_3 V_24 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( F_6 ( V_8 ) -> V_14 + 1 , V_24 ) ;
if ( ! V_2 )
return NULL ;
F_4 ( V_8 , V_2 ) ;
V_2 -> V_21 = F_11 ;
V_2 -> V_25 = V_23 -> V_26 ;
V_2 -> V_20 = V_8 ;
return V_2 ;
}
static inline void F_17 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_18 ( V_2 -> V_27 ) ;
F_19 ( & V_2 -> V_27 -> V_28 , L_2 , F_3 ( V_2 ) ) ;
F_20 ( & V_23 -> V_29 ) ;
F_21 ( & V_2 -> V_30 , & V_23 -> V_31 ) ;
F_22 ( & V_23 -> V_29 ) ;
}
static struct V_1 * F_23 ( struct V_22 * V_23 )
{
struct V_1 * V_2 ;
F_5 ( F_24 ( & V_23 -> V_31 ) ) ;
F_20 ( & V_23 -> V_29 ) ;
V_2 = F_25 ( & V_23 -> V_31 , struct V_1 , V_30 ) ;
F_26 ( & V_2 -> V_30 ) ;
F_22 ( & V_23 -> V_29 ) ;
V_2 -> V_21 = F_17 ;
return V_2 ;
}
static void F_27 ( struct V_22 * V_23 )
{
struct V_1 * V_2 , * V_32 ;
F_28 (msg, tmp, &ssi->cmdqueue, link) {
F_26 ( & V_2 -> V_30 ) ;
V_2 -> V_21 = NULL ;
F_29 ( F_2 ( V_2 -> V_5 . V_6 ) ) ;
F_14 ( V_2 ) ;
}
}
static int F_30 ( struct V_22 * V_23 )
{
struct V_1 * V_2 ;
T_1 * V_33 ;
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_34 ; V_12 ++ ) {
V_2 = F_16 ( 1 , V_35 ) ;
if ( ! V_2 )
goto V_36;
V_33 = F_31 ( sizeof( * V_33 ) , V_35 ) ;
if ( ! V_33 ) {
F_14 ( V_2 ) ;
goto V_36;
}
F_32 ( V_2 -> V_5 . V_6 , V_33 , sizeof( * V_33 ) ) ;
V_2 -> V_25 = V_23 -> V_37 ;
F_21 ( & V_2 -> V_30 , & V_23 -> V_31 ) ;
}
return 0 ;
V_36:
F_27 ( V_23 ) ;
return - V_38 ;
}
static void F_33 ( struct V_22 * V_23 , unsigned int V_39 )
{
V_23 -> V_40 = V_39 ;
switch ( V_39 ) {
case V_41 :
F_34 ( & V_23 -> V_42 ) ;
if ( V_23 -> V_43 == V_44 )
F_34 ( & V_23 -> V_45 ) ;
break;
case V_46 :
if ( F_35 ( & V_23 -> V_47 ) )
break;
case V_48 :
F_36 ( & V_23 -> V_45 , V_49 +
F_37 ( V_50 ) ) ;
F_36 ( & V_23 -> V_42 , V_49 + F_37 ( V_51 ) ) ;
break;
default:
break;
}
}
static void F_38 ( struct V_22 * V_23 , unsigned int V_39 )
{
V_23 -> V_43 = V_39 ;
switch ( V_39 ) {
case V_44 :
case V_52 :
F_34 ( & V_23 -> V_53 ) ;
if ( V_23 -> V_40 == V_41 )
F_34 ( & V_23 -> V_45 ) ;
break;
case V_54 :
case V_55 :
case V_56 :
F_36 ( & V_23 -> V_45 ,
V_49 + F_37 ( V_50 ) ) ;
F_36 ( & V_23 -> V_53 , V_49 + F_37 ( V_51 ) ) ;
break;
default:
break;
}
}
struct V_57 * F_39 ( struct V_57 * V_58 )
{
struct V_57 * V_59 = F_40 ( - V_60 ) ;
struct V_22 * V_23 ;
F_41 (ssi, &ssip_list, link)
if ( V_58 -> V_28 . V_61 == V_23 -> V_27 -> V_28 . V_61 ) {
V_59 = V_23 -> V_27 ;
break;
}
return V_59 ;
}
int F_42 ( struct V_57 * V_59 )
{
struct V_22 * V_23 = F_18 ( V_59 ) ;
F_19 ( & V_59 -> V_28 , L_3 , F_35 ( & V_23 -> V_47 ) ) ;
F_20 ( & V_23 -> V_29 ) ;
if ( V_23 -> V_43 == V_44 ) {
F_38 ( V_23 , V_54 ) ;
F_43 ( V_59 ) ;
}
F_22 ( & V_23 -> V_29 ) ;
F_44 ( & V_23 -> V_47 ) ;
return 0 ;
}
int F_45 ( struct V_57 * V_59 )
{
struct V_22 * V_23 = F_18 ( V_59 ) ;
F_46 ( F_35 ( & V_23 -> V_47 ) == 0 ) ;
if ( F_47 ( & V_23 -> V_47 ) ) {
F_20 ( & V_23 -> V_29 ) ;
if ( ( V_23 -> V_43 == V_52 ) ||
( V_23 -> V_43 == V_54 ) ) {
F_38 ( V_23 , V_44 ) ;
F_48 ( V_59 ) ;
}
F_22 ( & V_23 -> V_29 ) ;
}
F_19 ( & V_59 -> V_28 , L_4 , F_35 ( & V_23 -> V_47 ) ) ;
return 0 ;
}
int F_49 ( struct V_57 * V_59 )
{
struct V_22 * V_23 = F_18 ( V_59 ) ;
return F_50 ( V_23 -> V_62 ) ;
}
static void F_51 ( struct V_57 * V_27 )
{
struct V_22 * V_23 = F_18 ( V_27 ) ;
struct V_63 * V_64 , * V_32 ;
struct V_1 * V_2 ;
if ( F_50 ( V_23 -> V_62 ) )
F_52 ( V_23 -> V_62 ) ;
F_53 ( V_27 ) ;
F_20 ( & V_23 -> V_29 ) ;
if ( V_23 -> V_43 != V_44 )
F_48 ( V_27 ) ;
if ( V_23 -> V_65 )
F_54 ( V_27 , 0 ) ;
F_34 ( & V_23 -> V_42 ) ;
F_34 ( & V_23 -> V_53 ) ;
F_34 ( & V_23 -> V_45 ) ;
V_23 -> V_66 = 0 ;
V_23 -> V_43 = 0 ;
V_23 -> V_40 = 0 ;
V_23 -> V_65 = 0 ;
V_23 -> V_67 = 0 ;
V_23 -> V_68 = 0 ;
F_55 (head, tmp, &ssi->txqueue) {
V_2 = F_56 ( V_64 , struct V_1 , V_30 ) ;
F_19 ( & V_27 -> V_28 , L_5 ) ;
F_26 ( V_64 ) ;
F_11 ( V_2 ) ;
}
V_23 -> V_69 = 0 ;
F_22 ( & V_23 -> V_29 ) ;
}
static void F_57 ( struct V_57 * V_27 )
{
struct V_22 * V_23 = F_18 ( V_27 ) ;
struct V_1 * V_2 ;
F_20 ( & V_23 -> V_29 ) ;
F_58 ( & V_27 -> V_28 , L_6 , V_23 -> V_66 ) ;
F_58 ( & V_27 -> V_28 , L_7 , V_23 -> V_40 ) ;
F_58 ( & V_27 -> V_28 , L_8 , V_23 -> V_43 ) ;
F_58 ( & V_27 -> V_28 , L_9 , ( V_23 -> V_66 == V_70 ) ?
L_10 : L_11 ) ;
F_58 ( & V_27 -> V_28 , L_12 , V_23 -> V_65 ) ;
F_58 ( & V_27 -> V_28 , L_13 , V_23 -> V_67 ) ;
F_58 ( & V_27 -> V_28 , L_14 , V_23 -> V_68 ) ;
F_41 (msg, &ssi->txqueue, link)
F_58 ( & V_27 -> V_28 , L_15 , V_2 ) ;
F_22 ( & V_23 -> V_29 ) ;
}
static void F_59 ( struct V_57 * V_27 )
{
struct V_22 * V_23 = F_18 ( V_27 ) ;
struct V_1 * V_2 ;
F_57 ( V_27 ) ;
F_51 ( V_27 ) ;
V_2 = F_23 ( V_23 ) ;
V_2 -> V_71 = V_72 ;
F_60 ( V_27 , V_2 ) ;
}
static void F_61 ( unsigned long V_4 )
{
struct V_57 * V_27 = (struct V_57 * ) V_4 ;
struct V_22 * V_23 = F_18 ( V_27 ) ;
F_19 ( & V_27 -> V_28 , L_16 ,
V_23 -> V_66 , V_23 -> V_40 , V_23 -> V_43 ) ;
F_62 ( & V_23 -> V_29 ) ;
if ( V_23 -> V_40 == V_41 )
switch ( V_23 -> V_43 ) {
case V_52 :
if ( F_35 ( & V_23 -> V_47 ) == 0 )
break;
case V_44 :
F_63 ( & V_23 -> V_29 ) ;
return;
}
F_36 ( & V_23 -> V_45 , V_49 + F_37 ( V_50 ) ) ;
F_63 ( & V_23 -> V_29 ) ;
}
static void F_64 ( unsigned long V_4 )
{
struct V_57 * V_27 = (struct V_57 * ) V_4 ;
F_58 ( & V_27 -> V_28 , L_17 ) ;
F_59 ( V_27 ) ;
}
static void F_65 ( struct V_57 * V_27 )
{
struct V_22 * V_23 = F_18 ( V_27 ) ;
struct V_1 * V_2 ;
F_19 ( & V_27 -> V_28 , L_18 ) ;
V_2 = F_23 ( V_23 ) ;
F_1 ( V_2 , F_66 ( V_73 ) ) ;
V_2 -> V_71 = F_17 ;
F_67 ( V_27 , V_2 ) ;
F_19 ( & V_27 -> V_28 , L_19 ) ;
V_2 = F_23 ( V_23 ) ;
V_2 -> V_71 = V_72 ;
F_60 ( V_27 , V_2 ) ;
}
static void F_68 ( struct V_57 * V_27 )
{
struct V_22 * V_23 = F_18 ( V_27 ) ;
struct V_1 * V_2 ;
F_19 ( & V_27 -> V_28 , L_20 , V_23 -> V_66 ,
V_23 -> V_40 ) ;
F_62 ( & V_23 -> V_29 ) ;
if ( ( V_23 -> V_66 != V_70 ) || ( V_23 -> V_40 == V_46 ) ) {
if ( V_23 -> V_66 == V_74 ) {
V_23 -> V_66 = V_75 ;
F_63 ( & V_23 -> V_29 ) ;
F_65 ( V_27 ) ;
} else {
F_63 ( & V_23 -> V_29 ) ;
}
return;
}
F_33 ( V_23 , V_46 ) ;
F_63 ( & V_23 -> V_29 ) ;
V_2 = F_23 ( V_23 ) ;
F_1 ( V_2 , V_76 ) ;
V_2 -> V_71 = F_17 ;
F_19 ( & V_27 -> V_28 , L_21 ) ;
F_67 ( V_27 , V_2 ) ;
}
static void F_69 ( struct V_57 * V_27 )
{
struct V_22 * V_23 = F_18 ( V_27 ) ;
F_19 ( & V_27 -> V_28 , L_22 , V_23 -> V_66 ) ;
F_62 ( & V_23 -> V_29 ) ;
if ( F_70 ( V_23 -> V_66 == V_70 ) )
F_33 ( V_23 , V_41 ) ;
F_63 ( & V_23 -> V_29 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
F_11 ( V_2 -> V_20 ) ;
F_17 ( V_2 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_57 * V_27 = V_2 -> V_27 ;
struct V_22 * V_23 = F_18 ( V_27 ) ;
struct V_1 * V_4 ;
V_4 = V_2 -> V_20 ;
F_17 ( V_2 ) ;
F_62 ( & V_23 -> V_29 ) ;
F_38 ( V_23 , V_55 ) ;
F_63 ( & V_23 -> V_29 ) ;
F_67 ( V_27 , V_4 ) ;
}
static int F_73 ( struct V_57 * V_27 )
{
struct V_22 * V_23 = F_18 ( V_27 ) ;
struct V_1 * V_2 , * V_77 ;
struct V_7 * V_8 ;
F_20 ( & V_23 -> V_29 ) ;
if ( F_24 ( & V_23 -> V_78 ) ) {
F_22 ( & V_23 -> V_29 ) ;
return 0 ;
}
V_77 = F_25 ( & V_23 -> V_78 , struct V_1 , V_30 ) ;
F_26 ( & V_77 -> V_30 ) ;
V_23 -> V_69 -- ;
F_22 ( & V_23 -> V_29 ) ;
V_2 = F_23 ( V_23 ) ;
V_8 = V_77 -> V_20 ;
V_2 -> V_20 = V_77 ;
V_2 -> V_71 = F_72 ;
V_2 -> V_21 = F_71 ;
F_20 ( & V_23 -> V_29 ) ;
F_1 ( V_2 , F_74 ( F_75 ( V_8 -> V_79 ) ,
V_23 -> V_68 ) ) ;
V_23 -> V_68 ++ ;
F_38 ( V_23 , V_55 ) ;
F_22 ( & V_23 -> V_29 ) ;
F_19 ( & V_27 -> V_28 , L_23 ,
F_75 ( V_8 -> V_79 ) ) ;
return F_67 ( V_27 , V_2 ) ;
}
static void F_76 ( struct V_7 * V_8 )
{
struct V_80 * V_81 = V_8 -> V_81 ;
if ( F_77 ( ! F_50 ( V_81 ) ) ) {
F_19 ( & V_81 -> V_81 , L_24 ) ;
V_81 -> V_82 . V_83 ++ ;
F_13 ( V_8 ) ;
return;
}
if ( F_77 ( ! F_78 ( V_8 , V_84 ) ) ) {
F_19 ( & V_81 -> V_81 , L_25 ) ;
V_81 -> V_82 . V_85 ++ ;
V_81 -> V_82 . V_86 ++ ;
F_13 ( V_8 ) ;
return;
}
V_81 -> V_82 . V_87 ++ ;
V_81 -> V_82 . V_88 += V_8 -> V_79 ;
( ( V_89 * ) V_8 -> V_4 ) [ 2 ] = F_79 ( ( ( V_89 * ) V_8 -> V_4 ) [ 2 ] ) ;
F_19 ( & V_81 -> V_81 , L_26 ,
( ( V_89 * ) V_8 -> V_4 ) [ 2 ] , F_79 ( ( ( V_89 * ) V_8 -> V_4 ) [ 2 ] ) ) ;
V_8 -> V_90 = F_80 ( V_91 ) ;
F_81 ( V_8 ) ;
F_82 ( V_8 , 1 ) ;
F_83 ( V_8 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_57 * V_27 = V_2 -> V_27 ;
struct V_22 * V_23 = F_18 ( V_27 ) ;
struct V_7 * V_8 ;
if ( V_2 -> V_92 == V_93 ) {
F_58 ( & V_27 -> V_28 , L_27 ) ;
F_11 ( V_2 ) ;
F_59 ( V_27 ) ;
return;
}
F_34 ( & V_23 -> V_42 ) ;
V_8 = V_2 -> V_20 ;
F_76 ( V_8 ) ;
F_14 ( V_2 ) ;
}
static void F_85 ( struct V_57 * V_27 , T_1 V_3 )
{
struct V_22 * V_23 = F_18 ( V_27 ) ;
struct V_1 * V_2 ;
if ( V_3 == V_94 )
return;
switch ( V_23 -> V_66 ) {
case V_70 :
F_58 ( & V_27 -> V_28 , L_28 ) ;
F_59 ( V_27 ) ;
case V_74 :
F_62 ( & V_23 -> V_29 ) ;
V_23 -> V_66 = V_75 ;
if ( ! V_23 -> V_65 ) {
V_23 -> V_65 = 1 ;
F_54 ( V_27 , 1 ) ;
}
F_36 ( & V_23 -> V_53 , V_49 + F_37 ( V_51 ) ) ;
F_63 ( & V_23 -> V_29 ) ;
F_19 ( & V_27 -> V_28 , L_29 ) ;
if ( F_86 ( V_3 ) != V_73 )
F_87 ( & V_27 -> V_28 , L_30 ) ;
V_2 = F_23 ( V_23 ) ;
F_1 ( V_2 , F_88 ( V_73 ) ) ;
V_2 -> V_71 = F_17 ;
F_67 ( V_27 , V_2 ) ;
break;
case V_75 :
break;
default:
F_19 ( & V_27 -> V_28 , L_31 , V_23 -> V_66 ) ;
break;
}
}
static void F_89 ( struct V_57 * V_27 , T_1 V_3 )
{
struct V_22 * V_23 = F_18 ( V_27 ) ;
if ( F_86 ( V_3 ) != V_73 )
F_87 ( & V_27 -> V_28 , L_32 ) ;
F_62 ( & V_23 -> V_29 ) ;
if ( V_23 -> V_66 != V_70 )
F_36 ( & V_23 -> V_53 , V_49 + F_37 ( V_51 ) ) ;
else
F_19 ( & V_27 -> V_28 , L_33 ,
V_23 -> V_66 ) ;
F_63 ( & V_23 -> V_29 ) ;
}
static void F_90 ( struct V_57 * V_27 , T_1 V_3 )
{
struct V_22 * V_23 = F_18 ( V_27 ) ;
unsigned int V_95 = F_91 ( V_3 ) ;
F_62 ( & V_23 -> V_29 ) ;
if ( V_23 -> V_66 != V_75 ) {
F_19 ( & V_27 -> V_28 , L_34 ,
V_23 -> V_66 ) ;
F_63 ( & V_23 -> V_29 ) ;
return;
}
if ( V_23 -> V_65 ) {
V_23 -> V_65 = 0 ;
F_54 ( V_27 , 0 ) ;
}
V_23 -> V_66 = V_70 ;
F_34 ( & V_23 -> V_53 ) ;
F_63 ( & V_23 -> V_29 ) ;
F_92 ( & V_27 -> V_28 , L_35 ,
V_95 & V_96 ? L_36 : L_37 ) ;
if ( V_95 & V_96 ) {
F_59 ( V_27 ) ;
return;
}
F_19 ( & V_27 -> V_28 , L_38 ) ;
F_93 ( V_23 -> V_62 ) ;
F_94 ( V_23 -> V_62 ) ;
}
static void F_95 ( struct V_57 * V_27 )
{
struct V_22 * V_23 = F_18 ( V_27 ) ;
F_62 ( & V_23 -> V_29 ) ;
if ( F_77 ( V_23 -> V_66 != V_70 ) ) {
F_19 ( & V_27 -> V_28 , L_39 ,
V_23 -> V_43 , V_23 -> V_66 ) ;
F_63 ( & V_23 -> V_29 ) ;
return;
}
if ( V_23 -> V_43 != V_54 ) {
F_19 ( & V_27 -> V_28 , L_40 ) ;
F_63 ( & V_23 -> V_29 ) ;
return;
}
F_38 ( V_23 , V_52 ) ;
F_63 ( & V_23 -> V_29 ) ;
F_73 ( V_27 ) ;
}
static void F_96 ( struct V_57 * V_27 , T_1 V_3 )
{
struct V_22 * V_23 = F_18 ( V_27 ) ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
int V_79 = F_97 ( V_3 ) ;
F_19 ( & V_27 -> V_28 , L_41 , V_79 ) ;
F_62 ( & V_23 -> V_29 ) ;
if ( F_77 ( V_23 -> V_66 != V_70 ) ) {
F_58 ( & V_27 -> V_28 , L_42 ,
V_23 -> V_43 , V_23 -> V_66 ) ;
F_63 ( & V_23 -> V_29 ) ;
return;
}
F_33 ( V_23 , V_48 ) ;
if ( F_77 ( F_98 ( V_3 ) != V_23 -> V_67 ) ) {
F_58 ( & V_27 -> V_28 , L_43 ,
F_98 ( V_3 ) , V_23 -> V_67 ) ;
F_63 ( & V_23 -> V_29 ) ;
goto V_97;
}
V_23 -> V_67 ++ ;
F_63 ( & V_23 -> V_29 ) ;
V_8 = F_99 ( V_23 -> V_62 , V_79 * 4 ) ;
if ( F_77 ( ! V_8 ) ) {
F_58 ( & V_27 -> V_28 , L_44 ) ;
goto V_97;
}
V_8 -> V_81 = V_23 -> V_62 ;
F_100 ( V_8 , V_79 * 4 ) ;
V_2 = F_15 ( V_23 , V_8 , V_98 ) ;
if ( F_77 ( ! V_2 ) ) {
F_58 ( & V_27 -> V_28 , L_45 ) ;
goto V_99;
}
V_2 -> V_71 = F_84 ;
F_60 ( V_27 , V_2 ) ;
return;
V_99:
F_13 ( V_8 ) ;
V_97:
F_59 ( V_27 ) ;
}
static void V_72 ( struct V_1 * V_2 )
{
struct V_57 * V_27 = V_2 -> V_27 ;
T_1 V_3 = F_3 ( V_2 ) ;
unsigned int V_100 = F_101 ( V_3 ) ;
if ( V_2 -> V_92 == V_93 ) {
F_58 ( & V_27 -> V_28 , L_46 ) ;
F_17 ( V_2 ) ;
F_59 ( V_27 ) ;
return;
}
F_60 ( V_27 , V_2 ) ;
F_19 ( & V_27 -> V_28 , L_47 , V_3 ) ;
switch ( V_100 ) {
case V_101 :
break;
case V_102 :
F_85 ( V_27 , V_3 ) ;
break;
case V_103 :
F_89 ( V_27 , V_3 ) ;
break;
case V_104 :
F_90 ( V_27 , V_3 ) ;
break;
case V_105 :
F_96 ( V_27 , V_3 ) ;
break;
case V_106 :
F_95 ( V_27 ) ;
break;
default:
F_87 ( & V_27 -> V_28 , L_48 , V_3 ) ;
break;
}
}
static void F_102 ( struct V_1 * V_2 )
{
struct V_57 * V_27 = V_2 -> V_27 ;
struct V_22 * V_23 = F_18 ( V_27 ) ;
F_17 ( V_2 ) ;
F_62 ( & V_23 -> V_29 ) ;
if ( F_24 ( & V_23 -> V_78 ) ) {
if ( F_35 ( & V_23 -> V_47 ) ) {
F_38 ( V_23 , V_52 ) ;
} else {
F_38 ( V_23 , V_44 ) ;
F_48 ( V_27 ) ;
}
F_63 ( & V_23 -> V_29 ) ;
} else {
F_63 ( & V_23 -> V_29 ) ;
F_73 ( V_27 ) ;
}
F_93 ( V_23 -> V_62 ) ;
}
static void F_103 ( struct V_1 * V_2 )
{
struct V_57 * V_27 = V_2 -> V_27 ;
struct V_22 * V_23 = F_18 ( V_27 ) ;
struct V_1 * V_107 ;
if ( V_2 -> V_92 == V_93 ) {
F_58 ( & V_27 -> V_28 , L_49 ) ;
F_59 ( V_27 ) ;
goto V_36;
}
F_62 ( & V_23 -> V_29 ) ;
if ( F_24 ( & V_23 -> V_78 ) ) {
F_38 ( V_23 , V_56 ) ;
F_63 ( & V_23 -> V_29 ) ;
V_107 = F_23 ( V_23 ) ;
F_1 ( V_107 , V_108 ) ;
V_107 -> V_71 = F_102 ;
F_19 ( & V_27 -> V_28 , L_50 ) ;
F_67 ( V_27 , V_107 ) ;
} else {
F_63 ( & V_23 -> V_29 ) ;
F_73 ( V_27 ) ;
}
V_36:
F_11 ( V_2 ) ;
}
static void F_104 ( struct V_57 * V_27 , unsigned long V_109 )
{
switch ( V_109 ) {
case V_110 :
F_68 ( V_27 ) ;
break;
case V_111 :
F_69 ( V_27 ) ;
break;
default:
return;
}
}
static int F_105 ( struct V_80 * V_81 )
{
struct V_57 * V_27 = F_106 ( V_81 -> V_81 . V_61 ) ;
struct V_22 * V_23 = F_18 ( V_27 ) ;
int V_112 ;
V_112 = F_107 ( V_27 , 1 ) ;
if ( V_112 < 0 ) {
F_58 ( & V_27 -> V_28 , L_51 ) ;
return V_112 ;
}
V_112 = F_108 ( V_27 , F_104 ) ;
if ( V_112 < 0 ) {
F_58 ( & V_27 -> V_28 , L_52 ,
V_112 ) ;
return V_112 ;
}
F_19 ( & V_27 -> V_28 , L_53 ) ;
F_109 ( V_27 ) ;
F_20 ( & V_23 -> V_29 ) ;
if ( ! V_23 -> V_65 ) {
V_23 -> V_65 = 1 ;
F_54 ( V_27 , 1 ) ;
}
V_23 -> V_66 = V_74 ;
F_22 ( & V_23 -> V_29 ) ;
return 0 ;
}
static int F_110 ( struct V_80 * V_81 )
{
struct V_57 * V_27 = F_106 ( V_81 -> V_81 . V_61 ) ;
F_51 ( V_27 ) ;
F_111 ( V_27 ) ;
F_112 ( V_27 ) ;
return 0 ;
}
static int F_113 ( struct V_80 * V_81 , int V_113 )
{
if ( V_113 > V_114 || V_113 < V_115 )
return - V_116 ;
V_81 -> V_117 = V_113 ;
return 0 ;
}
static int F_114 ( struct V_7 * V_8 , struct V_80 * V_81 )
{
struct V_57 * V_27 = F_106 ( V_81 -> V_81 . V_61 ) ;
struct V_22 * V_23 = F_18 ( V_27 ) ;
struct V_1 * V_2 ;
if ( ( V_8 -> V_90 != F_80 ( V_91 ) ) ||
( V_8 -> V_79 < V_84 ) )
goto V_118;
if ( ( V_8 -> V_79 & 3 ) && F_115 ( V_8 , 4 - ( V_8 -> V_79 & 3 ) ) )
goto V_118;
if ( F_116 ( V_8 , 0 ) )
goto V_118;
( ( V_89 * ) V_8 -> V_4 ) [ 2 ] = F_80 ( ( ( V_89 * ) V_8 -> V_4 ) [ 2 ] ) ;
V_2 = F_15 ( V_23 , V_8 , V_98 ) ;
if ( ! V_2 ) {
F_19 ( & V_27 -> V_28 , L_54 ) ;
goto V_118;
}
V_2 -> V_71 = F_103 ;
F_20 ( & V_23 -> V_29 ) ;
if ( F_77 ( V_23 -> V_66 != V_70 ) ) {
F_22 ( & V_23 -> V_29 ) ;
F_19 ( & V_27 -> V_28 , L_55 ) ;
goto V_119;
}
F_21 ( & V_2 -> V_30 , & V_23 -> V_78 ) ;
V_23 -> V_69 ++ ;
if ( V_81 -> V_120 < V_23 -> V_69 ) {
F_117 ( & V_27 -> V_28 , L_56 , V_23 -> V_69 ) ;
F_118 ( V_81 ) ;
}
if ( V_23 -> V_43 == V_44 ) {
F_38 ( V_23 , V_54 ) ;
F_22 ( & V_23 -> V_29 ) ;
F_19 ( & V_27 -> V_28 , L_57 , V_23 -> V_69 ) ;
F_43 ( V_27 ) ;
} else if ( V_23 -> V_43 == V_52 ) {
F_19 ( & V_27 -> V_28 , L_58 ,
V_23 -> V_69 ) ;
F_22 ( & V_23 -> V_29 ) ;
F_73 ( V_27 ) ;
} else {
F_22 ( & V_23 -> V_29 ) ;
}
V_81 -> V_82 . V_121 ++ ;
V_81 -> V_82 . V_122 += V_8 -> V_79 ;
return 0 ;
V_119:
F_14 ( V_2 ) ;
V_118:
V_81 -> V_82 . V_123 ++ ;
F_13 ( V_8 ) ;
return 0 ;
}
void F_119 ( struct V_57 * V_59 )
{
struct V_22 * V_23 = F_18 ( V_59 ) ;
F_58 ( & V_23 -> V_27 -> V_28 , L_59 ) ;
F_59 ( V_23 -> V_27 ) ;
}
static void F_120 ( struct V_80 * V_81 )
{
V_81 -> V_124 = 0 ;
V_81 -> V_125 = & V_126 ;
V_81 -> type = V_127 ;
V_81 -> V_24 = V_128 | V_129 ;
V_81 -> V_117 = V_130 ;
V_81 -> V_131 = 1 ;
V_81 -> V_132 [ 0 ] = V_133 ;
V_81 -> V_134 = 1 ;
V_81 -> V_120 = V_135 ;
V_81 -> V_21 = V_136 ;
V_81 -> V_137 = & V_138 ;
}
static int F_121 ( struct V_28 * V_81 )
{
static const char V_139 [] = L_60 ;
struct V_57 * V_27 = F_106 ( V_81 ) ;
struct V_22 * V_23 ;
int V_112 ;
V_23 = F_122 ( sizeof( * V_23 ) , V_35 ) ;
if ( ! V_23 ) {
F_58 ( V_81 , L_61 ) ;
return - V_38 ;
}
F_123 ( & V_23 -> V_29 ) ;
F_124 ( & V_23 -> V_42 ) ;
F_124 ( & V_23 -> V_53 ) ;
F_125 ( & V_23 -> V_45 ) ;
V_23 -> V_42 . V_4 = ( unsigned long ) V_27 ;
V_23 -> V_42 . V_140 = F_64 ;
V_23 -> V_53 . V_4 = ( unsigned long ) V_27 ;
V_23 -> V_53 . V_140 = F_64 ;
V_23 -> V_45 . V_4 = ( unsigned long ) V_27 ;
V_23 -> V_45 . V_140 = F_61 ;
F_126 ( & V_23 -> V_78 ) ;
F_126 ( & V_23 -> V_31 ) ;
F_127 ( & V_23 -> V_47 , 0 ) ;
F_128 ( V_27 , V_23 ) ;
V_23 -> V_27 = V_27 ;
V_23 -> V_37 = F_129 ( V_27 , L_62 ) ;
if ( V_23 -> V_37 < 0 ) {
V_112 = V_23 -> V_37 ;
F_58 ( V_81 , L_63 , V_112 ) ;
goto V_36;
}
V_23 -> V_26 = F_129 ( V_27 , L_64 ) ;
if ( V_23 -> V_26 < 0 ) {
V_112 = V_23 -> V_26 ;
F_58 ( V_81 , L_65 , V_112 ) ;
goto V_36;
}
V_112 = F_30 ( V_23 ) ;
if ( V_112 < 0 ) {
F_58 ( V_81 , L_66 ) ;
goto V_36;
}
V_23 -> V_62 = F_130 ( 0 , V_139 , V_141 , F_120 ) ;
if ( ! V_23 -> V_62 ) {
F_58 ( V_81 , L_67 ) ;
V_112 = - V_38 ;
goto V_97;
}
F_131 ( V_23 -> V_62 , V_81 ) ;
F_52 ( V_23 -> V_62 ) ;
V_112 = F_132 ( V_23 -> V_62 ) ;
if ( V_112 < 0 ) {
F_58 ( V_81 , L_68 , V_112 ) ;
goto V_99;
}
F_133 ( & V_23 -> V_30 , & V_142 ) ;
F_19 ( V_81 , L_69 ,
V_23 -> V_37 , V_23 -> V_26 ) ;
return 0 ;
V_99:
V_136 ( V_23 -> V_62 ) ;
V_97:
F_27 ( V_23 ) ;
V_36:
F_29 ( V_23 ) ;
return V_112 ;
}
static int F_134 ( struct V_28 * V_81 )
{
struct V_57 * V_27 = F_106 ( V_81 ) ;
struct V_22 * V_23 = F_18 ( V_27 ) ;
F_26 ( & V_23 -> V_30 ) ;
F_135 ( V_23 -> V_62 ) ;
F_27 ( V_23 ) ;
F_128 ( V_27 , NULL ) ;
F_29 ( V_23 ) ;
return 0 ;
}
static int T_4 F_136 ( void )
{
F_137 ( L_70 ) ;
return F_138 ( & V_143 ) ;
}
static void T_5 F_139 ( void )
{
F_140 ( & V_143 ) ;
F_137 ( L_71 ) ;
}
