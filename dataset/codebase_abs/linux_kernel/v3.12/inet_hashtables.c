struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_4 ,
struct V_5 * V_6 ,
const unsigned short V_7 )
{
struct V_1 * V_8 = F_2 ( V_3 , V_9 ) ;
if ( V_8 != NULL ) {
F_3 ( & V_8 -> V_10 , F_4 ( V_4 ) ) ;
V_8 -> V_11 = V_7 ;
V_8 -> V_12 = 0 ;
V_8 -> V_13 = 0 ;
V_8 -> V_14 = 0 ;
F_5 ( & V_8 -> V_15 ) ;
F_6 ( & V_8 -> V_16 , & V_6 -> V_17 ) ;
}
return V_8 ;
}
void F_7 ( struct V_2 * V_3 , struct V_1 * V_8 )
{
if ( F_8 ( & V_8 -> V_15 ) ) {
F_9 ( & V_8 -> V_16 ) ;
F_10 ( V_10 ( V_8 ) ) ;
F_11 ( V_3 , V_8 ) ;
}
}
void F_12 ( struct V_18 * V_19 , struct V_1 * V_8 ,
const unsigned short V_7 )
{
struct V_20 * V_21 = V_19 -> V_22 -> V_23 . V_21 ;
F_13 ( & V_21 -> V_24 ) ;
F_14 ( V_19 ) -> V_25 = V_7 ;
F_15 ( V_19 , & V_8 -> V_15 ) ;
V_8 -> V_14 ++ ;
F_16 ( V_19 ) -> V_26 = V_8 ;
}
static void F_17 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_22 -> V_23 . V_21 ;
const int V_27 = F_18 ( F_19 ( V_19 ) , F_14 ( V_19 ) -> V_25 ,
V_21 -> V_28 ) ;
struct V_5 * V_6 = & V_21 -> V_27 [ V_27 ] ;
struct V_1 * V_8 ;
F_20 ( & V_21 -> V_24 ) ;
F_21 ( & V_6 -> V_29 ) ;
V_8 = F_16 ( V_19 ) -> V_26 ;
F_22 ( V_19 ) ;
V_8 -> V_14 -- ;
F_16 ( V_19 ) -> V_26 = NULL ;
F_14 ( V_19 ) -> V_25 = 0 ;
F_7 ( V_21 -> V_30 , V_8 ) ;
F_23 ( & V_6 -> V_29 ) ;
}
void F_24 ( struct V_18 * V_19 )
{
F_25 () ;
F_17 ( V_19 ) ;
F_26 () ;
}
int F_27 ( struct V_18 * V_19 , struct V_18 * V_31 )
{
struct V_20 * V_32 = V_19 -> V_22 -> V_23 . V_21 ;
unsigned short V_11 = F_14 ( V_31 ) -> V_25 ;
const int V_27 = F_18 ( F_19 ( V_19 ) , V_11 ,
V_32 -> V_28 ) ;
struct V_5 * V_6 = & V_32 -> V_27 [ V_27 ] ;
struct V_1 * V_8 ;
F_21 ( & V_6 -> V_29 ) ;
V_8 = F_16 ( V_19 ) -> V_26 ;
if ( V_8 -> V_11 != V_11 ) {
F_28 (tb, &head->chain) {
if ( F_29 ( V_10 ( V_8 ) , F_19 ( V_19 ) ) &&
V_8 -> V_11 == V_11 )
break;
}
if ( ! V_8 ) {
V_8 = F_1 ( V_32 -> V_30 ,
F_19 ( V_19 ) , V_6 , V_11 ) ;
if ( ! V_8 ) {
F_23 ( & V_6 -> V_29 ) ;
return - V_33 ;
}
}
}
F_12 ( V_31 , V_8 , V_11 ) ;
F_23 ( & V_6 -> V_29 ) ;
return 0 ;
}
static inline int F_30 ( struct V_18 * V_19 , struct V_4 * V_4 ,
const unsigned short V_34 , const T_1 V_35 ,
const int V_36 )
{
int V_37 = - 1 ;
struct V_38 * V_39 = F_14 ( V_19 ) ;
if ( F_29 ( F_19 ( V_19 ) , V_4 ) && V_39 -> V_25 == V_34 &&
! F_31 ( V_19 ) ) {
T_1 V_40 = V_39 -> V_41 ;
V_37 = V_19 -> V_42 == V_43 ? 2 : 1 ;
if ( V_40 ) {
if ( V_40 != V_35 )
return - 1 ;
V_37 += 4 ;
}
if ( V_19 -> V_44 ) {
if ( V_19 -> V_44 != V_36 )
return - 1 ;
V_37 += 4 ;
}
}
return V_37 ;
}
struct V_18 * F_32 ( struct V_4 * V_4 ,
struct V_20 * V_21 ,
const T_1 V_45 , T_2 V_46 ,
const T_1 V_35 , const unsigned short V_34 ,
const int V_36 )
{
struct V_18 * V_19 , * V_47 ;
struct V_48 * V_16 ;
unsigned int V_49 = F_33 ( V_4 , V_34 ) ;
struct V_50 * V_51 = & V_21 -> V_52 [ V_49 ] ;
int V_37 , V_53 , V_54 = 0 , V_55 = 0 ;
T_3 V_56 = 0 ;
F_34 () ;
V_57:
V_47 = NULL ;
V_53 = 0 ;
F_35 (sk, node, &ilb->head) {
V_37 = F_30 ( V_19 , V_4 , V_34 , V_35 , V_36 ) ;
if ( V_37 > V_53 ) {
V_47 = V_19 ;
V_53 = V_37 ;
V_55 = V_19 -> V_58 ;
if ( V_55 ) {
V_56 = F_36 ( V_4 , V_35 , V_34 ,
V_45 , V_46 ) ;
V_54 = 1 ;
}
} else if ( V_37 == V_53 && V_55 ) {
V_54 ++ ;
if ( ( ( V_59 ) V_56 * V_54 ) >> 32 == 0 )
V_47 = V_19 ;
V_56 = F_37 ( V_56 ) ;
}
}
if ( F_38 ( V_16 ) != V_49 + V_60 )
goto V_57;
if ( V_47 ) {
if ( F_39 ( ! F_40 ( & V_47 -> V_61 ) ) )
V_47 = NULL ;
else if ( F_39 ( F_30 ( V_47 , V_4 , V_34 , V_35 ,
V_36 ) < V_53 ) ) {
F_41 ( V_47 ) ;
goto V_57;
}
}
F_42 () ;
return V_47 ;
}
struct V_18 * F_43 ( struct V_4 * V_4 ,
struct V_20 * V_21 ,
const T_1 V_45 , const T_2 V_46 ,
const T_1 V_35 , const T_4 V_34 ,
const int V_36 )
{
F_44 (acookie, saddr, daddr)
const T_5 V_62 = F_45 ( V_46 , V_34 ) ;
struct V_18 * V_19 ;
const struct V_48 * V_16 ;
unsigned int V_49 = F_36 ( V_4 , V_35 , V_34 , V_45 , V_46 ) ;
unsigned int V_63 = V_49 & V_21 -> V_64 ;
struct V_65 * V_6 = & V_21 -> V_66 [ V_63 ] ;
F_34 () ;
V_57:
F_35 (sk, node, &head->chain) {
if ( V_19 -> V_67 != V_49 )
continue;
if ( F_46 ( F_47 ( V_19 , V_4 , V_68 ,
V_45 , V_35 , V_62 , V_36 ) ) ) {
if ( F_39 ( ! F_40 ( & V_19 -> V_61 ) ) )
goto V_69;
if ( F_39 ( ! F_47 ( V_19 , V_4 , V_68 ,
V_45 , V_35 , V_62 , V_36 ) ) ) {
F_41 ( V_19 ) ;
goto V_57;
}
goto V_70;
}
}
if ( F_38 ( V_16 ) != V_63 )
goto V_57;
V_69:
F_35 (sk, node, &head->twchain) {
if ( V_19 -> V_67 != V_49 )
continue;
if ( F_46 ( F_48 ( V_19 , V_4 , V_68 ,
V_45 , V_35 , V_62 ,
V_36 ) ) ) {
if ( F_39 ( ! F_40 ( & V_19 -> V_61 ) ) ) {
V_19 = NULL ;
goto V_70;
}
if ( F_39 ( ! F_48 ( V_19 , V_4 , V_68 ,
V_45 , V_35 , V_62 ,
V_36 ) ) ) {
F_49 ( F_50 ( V_19 ) ) ;
goto V_69;
}
goto V_70;
}
}
if ( F_38 ( V_16 ) != V_63 )
goto V_69;
V_19 = NULL ;
V_70:
F_42 () ;
return V_19 ;
}
static int F_51 ( struct V_71 * V_72 ,
struct V_18 * V_19 , T_6 V_73 ,
struct V_74 * * V_75 )
{
struct V_20 * V_76 = V_72 -> V_21 ;
struct V_38 * V_39 = F_14 ( V_19 ) ;
T_1 V_35 = V_39 -> V_41 ;
T_1 V_45 = V_39 -> V_77 ;
int V_36 = V_19 -> V_44 ;
F_44 (acookie, saddr, daddr)
const T_5 V_62 = F_45 ( V_39 -> V_78 , V_73 ) ;
struct V_4 * V_4 = F_19 ( V_19 ) ;
unsigned int V_49 = F_36 ( V_4 , V_35 , V_73 ,
V_45 , V_39 -> V_78 ) ;
struct V_65 * V_6 = V_65 ( V_76 , V_49 ) ;
T_7 * V_29 = F_52 ( V_76 , V_49 ) ;
struct V_18 * V_79 ;
const struct V_48 * V_16 ;
struct V_74 * V_80 ;
int V_81 = 0 ;
F_21 ( V_29 ) ;
F_53 (sk2, node, &head->twchain) {
if ( V_79 -> V_67 != V_49 )
continue;
if ( F_46 ( F_48 ( V_79 , V_4 , V_68 ,
V_45 , V_35 , V_62 , V_36 ) ) ) {
V_80 = F_50 ( V_79 ) ;
if ( F_54 ( V_19 , V_79 , V_75 ) )
goto V_82;
else
goto V_83;
}
}
V_80 = NULL ;
F_53 (sk2, node, &head->chain) {
if ( V_79 -> V_67 != V_49 )
continue;
if ( F_46 ( F_47 ( V_79 , V_4 , V_68 ,
V_45 , V_35 , V_62 , V_36 ) ) )
goto V_83;
}
V_82:
V_39 -> V_25 = V_73 ;
V_39 -> V_84 = F_55 ( V_73 ) ;
V_19 -> V_67 = V_49 ;
F_56 ( ! F_57 ( V_19 ) ) ;
F_58 ( V_19 , & V_6 -> V_17 ) ;
if ( V_80 ) {
V_81 = F_59 ( V_80 ) ;
F_60 ( V_4 , V_85 ) ;
}
F_23 ( V_29 ) ;
if ( V_81 )
F_49 ( V_80 ) ;
F_61 ( F_19 ( V_19 ) , V_19 -> V_22 , 1 ) ;
if ( V_75 ) {
* V_75 = V_80 ;
} else if ( V_80 ) {
F_62 ( V_80 , V_72 ) ;
F_49 ( V_80 ) ;
}
return 0 ;
V_83:
F_23 ( V_29 ) ;
return - V_86 ;
}
static inline T_3 F_63 ( const struct V_18 * V_19 )
{
const struct V_38 * V_39 = F_14 ( V_19 ) ;
return F_64 ( V_39 -> V_41 ,
V_39 -> V_77 ,
V_39 -> V_78 ) ;
}
int F_65 ( struct V_18 * V_19 , struct V_74 * V_80 )
{
struct V_20 * V_21 = V_19 -> V_22 -> V_23 . V_21 ;
struct V_87 * V_88 ;
T_7 * V_29 ;
struct V_65 * V_6 ;
int V_81 = 0 ;
F_56 ( ! F_57 ( V_19 ) ) ;
V_19 -> V_67 = F_66 ( V_19 ) ;
V_6 = V_65 ( V_21 , V_19 -> V_67 ) ;
V_88 = & V_6 -> V_17 ;
V_29 = F_52 ( V_21 , V_19 -> V_67 ) ;
F_21 ( V_29 ) ;
F_58 ( V_19 , V_88 ) ;
if ( V_80 ) {
F_56 ( V_19 -> V_67 != V_80 -> V_89 ) ;
V_81 = F_59 ( V_80 ) ;
}
F_23 ( V_29 ) ;
F_61 ( F_19 ( V_19 ) , V_19 -> V_22 , 1 ) ;
return V_81 ;
}
static void F_67 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_22 -> V_23 . V_21 ;
struct V_50 * V_51 ;
if ( V_19 -> V_90 != V_91 ) {
F_65 ( V_19 , NULL ) ;
return;
}
F_56 ( ! F_57 ( V_19 ) ) ;
V_51 = & V_21 -> V_52 [ F_68 ( V_19 ) ] ;
F_21 ( & V_51 -> V_29 ) ;
F_58 ( V_19 , & V_51 -> V_6 ) ;
F_61 ( F_19 ( V_19 ) , V_19 -> V_22 , 1 ) ;
F_23 ( & V_51 -> V_29 ) ;
}
void F_69 ( struct V_18 * V_19 )
{
if ( V_19 -> V_90 != V_92 ) {
F_25 () ;
F_67 ( V_19 ) ;
F_26 () ;
}
}
void F_70 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_22 -> V_23 . V_21 ;
T_7 * V_29 ;
int V_93 ;
if ( F_57 ( V_19 ) )
return;
if ( V_19 -> V_90 == V_91 )
V_29 = & V_21 -> V_52 [ F_68 ( V_19 ) ] . V_29 ;
else
V_29 = F_52 ( V_21 , V_19 -> V_67 ) ;
F_71 ( V_29 ) ;
V_93 = F_72 ( V_19 ) ;
if ( V_93 )
F_61 ( F_19 ( V_19 ) , V_19 -> V_22 , - 1 ) ;
F_73 ( V_29 ) ;
}
int F_74 ( struct V_71 * V_72 ,
struct V_18 * V_19 , T_3 V_94 ,
int (* F_75)( struct V_71 * ,
struct V_18 * , T_6 , struct V_74 * * ) ,
int (* V_49)( struct V_18 * V_19 , struct V_74 * V_75 ) )
{
struct V_20 * V_76 = V_72 -> V_21 ;
const unsigned short V_7 = F_14 ( V_19 ) -> V_25 ;
struct V_5 * V_6 ;
struct V_1 * V_8 ;
int V_95 ;
struct V_4 * V_4 = F_19 ( V_19 ) ;
int V_81 = 1 ;
if ( ! V_7 ) {
int V_96 , V_97 , V_98 , V_99 , V_11 ;
static T_3 V_100 ;
T_3 V_101 = V_100 + V_94 ;
struct V_74 * V_80 = NULL ;
F_76 ( & V_98 , & V_99 ) ;
V_97 = ( V_99 - V_98 ) + 1 ;
F_25 () ;
for ( V_96 = 1 ; V_96 <= V_97 ; V_96 ++ ) {
V_11 = V_98 + ( V_96 + V_101 ) % V_97 ;
if ( F_77 ( V_11 ) )
continue;
V_6 = & V_76 -> V_27 [ F_18 ( V_4 , V_11 ,
V_76 -> V_28 ) ] ;
F_21 ( & V_6 -> V_29 ) ;
F_28 (tb, &head->chain) {
if ( F_29 ( V_10 ( V_8 ) , V_4 ) &&
V_8 -> V_11 == V_11 ) {
if ( V_8 -> V_12 >= 0 ||
V_8 -> V_13 >= 0 )
goto V_102;
F_56 ( F_8 ( & V_8 -> V_15 ) ) ;
if ( ! F_75 ( V_72 , V_19 ,
V_11 , & V_80 ) )
goto V_103;
goto V_102;
}
}
V_8 = F_1 ( V_76 -> V_30 ,
V_4 , V_6 , V_11 ) ;
if ( ! V_8 ) {
F_23 ( & V_6 -> V_29 ) ;
break;
}
V_8 -> V_12 = - 1 ;
V_8 -> V_13 = - 1 ;
goto V_103;
V_102:
F_23 ( & V_6 -> V_29 ) ;
}
F_26 () ;
return - V_86 ;
V_103:
V_100 += V_96 ;
F_12 ( V_19 , V_8 , V_11 ) ;
if ( F_57 ( V_19 ) ) {
F_14 ( V_19 ) -> V_84 = F_55 ( V_11 ) ;
V_81 += V_49 ( V_19 , V_80 ) ;
}
if ( V_80 )
V_81 += F_78 ( V_80 , V_76 ) ;
F_23 ( & V_6 -> V_29 ) ;
if ( V_80 ) {
F_62 ( V_80 , V_72 ) ;
while ( V_81 ) {
V_81 -- ;
F_49 ( V_80 ) ;
}
}
V_95 = 0 ;
goto V_70;
}
V_6 = & V_76 -> V_27 [ F_18 ( V_4 , V_7 , V_76 -> V_28 ) ] ;
V_8 = F_16 ( V_19 ) -> V_26 ;
F_71 ( & V_6 -> V_29 ) ;
if ( F_79 ( & V_8 -> V_15 ) == V_19 && ! V_19 -> V_104 . V_105 ) {
V_49 ( V_19 , NULL ) ;
F_73 ( & V_6 -> V_29 ) ;
return 0 ;
} else {
F_23 ( & V_6 -> V_29 ) ;
V_95 = F_75 ( V_72 , V_19 , V_7 , NULL ) ;
V_70:
F_26 () ;
return V_95 ;
}
}
int F_80 ( struct V_71 * V_72 ,
struct V_18 * V_19 )
{
return F_74 ( V_72 , V_19 , F_63 ( V_19 ) ,
F_51 , F_65 ) ;
}
void F_81 ( struct V_20 * V_23 )
{
int V_96 ;
F_82 ( & V_23 -> V_24 , 0 ) ;
for ( V_96 = 0 ; V_96 < V_106 ; V_96 ++ ) {
F_83 ( & V_23 -> V_52 [ V_96 ] . V_29 ) ;
F_84 ( & V_23 -> V_52 [ V_96 ] . V_6 ,
V_96 + V_60 ) ;
}
}
