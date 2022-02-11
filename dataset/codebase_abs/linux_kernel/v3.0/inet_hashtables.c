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
F_5 ( & V_8 -> V_14 ) ;
F_6 ( & V_8 -> V_15 , & V_6 -> V_16 ) ;
}
return V_8 ;
}
void F_7 ( struct V_2 * V_3 , struct V_1 * V_8 )
{
if ( F_8 ( & V_8 -> V_14 ) ) {
F_9 ( & V_8 -> V_15 ) ;
F_10 ( V_10 ( V_8 ) ) ;
F_11 ( V_3 , V_8 ) ;
}
}
void F_12 ( struct V_17 * V_18 , struct V_1 * V_8 ,
const unsigned short V_7 )
{
struct V_19 * V_20 = V_18 -> V_21 -> V_22 . V_20 ;
F_13 ( & V_20 -> V_23 ) ;
F_14 ( V_18 ) -> V_24 = V_7 ;
F_15 ( V_18 , & V_8 -> V_14 ) ;
V_8 -> V_13 ++ ;
F_16 ( V_18 ) -> V_25 = V_8 ;
}
static void F_17 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 -> V_22 . V_20 ;
const int V_26 = F_18 ( F_19 ( V_18 ) , F_14 ( V_18 ) -> V_24 ,
V_20 -> V_27 ) ;
struct V_5 * V_6 = & V_20 -> V_26 [ V_26 ] ;
struct V_1 * V_8 ;
F_20 ( & V_20 -> V_23 ) ;
F_21 ( & V_6 -> V_28 ) ;
V_8 = F_16 ( V_18 ) -> V_25 ;
F_22 ( V_18 ) ;
V_8 -> V_13 -- ;
F_16 ( V_18 ) -> V_25 = NULL ;
F_14 ( V_18 ) -> V_24 = 0 ;
F_7 ( V_20 -> V_29 , V_8 ) ;
F_23 ( & V_6 -> V_28 ) ;
}
void F_24 ( struct V_17 * V_18 )
{
F_25 () ;
F_17 ( V_18 ) ;
F_26 () ;
}
int F_27 ( struct V_17 * V_18 , struct V_17 * V_30 )
{
struct V_19 * V_31 = V_18 -> V_21 -> V_22 . V_20 ;
unsigned short V_11 = F_14 ( V_30 ) -> V_24 ;
const int V_26 = F_18 ( F_19 ( V_18 ) , V_11 ,
V_31 -> V_27 ) ;
struct V_5 * V_6 = & V_31 -> V_26 [ V_26 ] ;
struct V_1 * V_8 ;
F_21 ( & V_6 -> V_28 ) ;
V_8 = F_16 ( V_18 ) -> V_25 ;
if ( V_8 -> V_11 != V_11 ) {
struct V_32 * V_15 ;
F_28 (tb, node, &head->chain) {
if ( F_29 ( V_10 ( V_8 ) , F_19 ( V_18 ) ) &&
V_8 -> V_11 == V_11 )
break;
}
if ( ! V_15 ) {
V_8 = F_1 ( V_31 -> V_29 ,
F_19 ( V_18 ) , V_6 , V_11 ) ;
if ( ! V_8 ) {
F_23 ( & V_6 -> V_28 ) ;
return - V_33 ;
}
}
}
F_12 ( V_30 , V_8 , V_11 ) ;
F_23 ( & V_6 -> V_28 ) ;
return 0 ;
}
static inline int F_30 ( struct V_17 * V_18 , struct V_4 * V_4 ,
const unsigned short V_34 , const T_1 V_35 ,
const int V_36 )
{
int V_37 = - 1 ;
struct V_38 * V_39 = F_14 ( V_18 ) ;
if ( F_29 ( F_19 ( V_18 ) , V_4 ) && V_39 -> V_24 == V_34 &&
! F_31 ( V_18 ) ) {
T_1 V_40 = V_39 -> V_41 ;
V_37 = V_18 -> V_42 == V_43 ? 1 : 0 ;
if ( V_40 ) {
if ( V_40 != V_35 )
return - 1 ;
V_37 += 2 ;
}
if ( V_18 -> V_44 ) {
if ( V_18 -> V_44 != V_36 )
return - 1 ;
V_37 += 2 ;
}
}
return V_37 ;
}
struct V_17 * F_32 ( struct V_4 * V_4 ,
struct V_19 * V_20 ,
const T_1 V_35 , const unsigned short V_34 ,
const int V_36 )
{
struct V_17 * V_18 , * V_45 ;
struct V_46 * V_15 ;
unsigned int V_47 = F_33 ( V_4 , V_34 ) ;
struct V_48 * V_49 = & V_20 -> V_50 [ V_47 ] ;
int V_37 , V_51 ;
F_34 () ;
V_52:
V_45 = NULL ;
V_51 = - 1 ;
F_35 (sk, node, &ilb->head) {
V_37 = F_30 ( V_18 , V_4 , V_34 , V_35 , V_36 ) ;
if ( V_37 > V_51 ) {
V_45 = V_18 ;
V_51 = V_37 ;
}
}
if ( F_36 ( V_15 ) != V_47 + V_53 )
goto V_52;
if ( V_45 ) {
if ( F_37 ( ! F_38 ( & V_45 -> V_54 ) ) )
V_45 = NULL ;
else if ( F_37 ( F_30 ( V_45 , V_4 , V_34 , V_35 ,
V_36 ) < V_51 ) ) {
F_39 ( V_45 ) ;
goto V_52;
}
}
F_40 () ;
return V_45 ;
}
struct V_17 * F_41 ( struct V_4 * V_4 ,
struct V_19 * V_20 ,
const T_1 V_55 , const T_2 V_56 ,
const T_1 V_35 , const T_3 V_34 ,
const int V_36 )
{
F_42 (acookie, saddr, daddr)
const T_4 V_57 = F_43 ( V_56 , V_34 ) ;
struct V_17 * V_18 ;
const struct V_46 * V_15 ;
unsigned int V_47 = F_44 ( V_4 , V_35 , V_34 , V_55 , V_56 ) ;
unsigned int V_58 = V_47 & V_20 -> V_59 ;
struct V_60 * V_6 = & V_20 -> V_61 [ V_58 ] ;
F_34 () ;
V_52:
F_35 (sk, node, &head->chain) {
if ( F_45 ( V_18 , V_4 , V_47 , V_62 ,
V_55 , V_35 , V_57 , V_36 ) ) {
if ( F_37 ( ! F_38 ( & V_18 -> V_54 ) ) )
goto V_63;
if ( F_37 ( ! F_45 ( V_18 , V_4 , V_47 , V_62 ,
V_55 , V_35 , V_57 , V_36 ) ) ) {
F_39 ( V_18 ) ;
goto V_52;
}
goto V_64;
}
}
if ( F_36 ( V_15 ) != V_58 )
goto V_52;
V_63:
F_35 (sk, node, &head->twchain) {
if ( F_46 ( V_18 , V_4 , V_47 , V_62 ,
V_55 , V_35 , V_57 , V_36 ) ) {
if ( F_37 ( ! F_38 ( & V_18 -> V_54 ) ) ) {
V_18 = NULL ;
goto V_64;
}
if ( F_37 ( ! F_46 ( V_18 , V_4 , V_47 , V_62 ,
V_55 , V_35 , V_57 , V_36 ) ) ) {
F_39 ( V_18 ) ;
goto V_63;
}
goto V_64;
}
}
if ( F_36 ( V_15 ) != V_58 )
goto V_63;
V_18 = NULL ;
V_64:
F_40 () ;
return V_18 ;
}
static int F_47 ( struct V_65 * V_66 ,
struct V_17 * V_18 , T_5 V_67 ,
struct V_68 * * V_69 )
{
struct V_19 * V_70 = V_66 -> V_20 ;
struct V_38 * V_39 = F_14 ( V_18 ) ;
T_1 V_35 = V_39 -> V_41 ;
T_1 V_55 = V_39 -> V_71 ;
int V_36 = V_18 -> V_44 ;
F_42 (acookie, saddr, daddr)
const T_4 V_57 = F_43 ( V_39 -> V_72 , V_67 ) ;
struct V_4 * V_4 = F_19 ( V_18 ) ;
unsigned int V_47 = F_44 ( V_4 , V_35 , V_67 ,
V_55 , V_39 -> V_72 ) ;
struct V_60 * V_6 = V_60 ( V_70 , V_47 ) ;
T_6 * V_28 = F_48 ( V_70 , V_47 ) ;
struct V_17 * V_73 ;
const struct V_46 * V_15 ;
struct V_68 * V_74 ;
int V_75 = 0 ;
F_21 ( V_28 ) ;
F_49 (sk2, node, &head->twchain) {
V_74 = F_50 ( V_73 ) ;
if ( F_46 ( V_73 , V_4 , V_47 , V_62 ,
V_55 , V_35 , V_57 , V_36 ) ) {
if ( F_51 ( V_18 , V_73 , V_69 ) )
goto V_76;
else
goto V_77;
}
}
V_74 = NULL ;
F_49 (sk2, node, &head->chain) {
if ( F_45 ( V_73 , V_4 , V_47 , V_62 ,
V_55 , V_35 , V_57 , V_36 ) )
goto V_77;
}
V_76:
V_39 -> V_24 = V_67 ;
V_39 -> V_78 = F_52 ( V_67 ) ;
V_18 -> V_79 = V_47 ;
F_53 ( ! F_54 ( V_18 ) ) ;
F_55 ( V_18 , & V_6 -> V_16 ) ;
if ( V_74 ) {
V_75 = F_56 ( V_74 ) ;
F_57 ( V_4 , V_80 ) ;
}
F_23 ( V_28 ) ;
if ( V_75 )
F_58 ( V_74 ) ;
F_59 ( F_19 ( V_18 ) , V_18 -> V_21 , 1 ) ;
if ( V_69 ) {
* V_69 = V_74 ;
} else if ( V_74 ) {
F_60 ( V_74 , V_66 ) ;
F_58 ( V_74 ) ;
}
return 0 ;
V_77:
F_23 ( V_28 ) ;
return - V_81 ;
}
static inline T_7 F_61 ( const struct V_17 * V_18 )
{
const struct V_38 * V_39 = F_14 ( V_18 ) ;
return F_62 ( V_39 -> V_41 ,
V_39 -> V_71 ,
V_39 -> V_72 ) ;
}
int F_63 ( struct V_17 * V_18 , struct V_68 * V_74 )
{
struct V_19 * V_20 = V_18 -> V_21 -> V_22 . V_20 ;
struct V_82 * V_83 ;
T_6 * V_28 ;
struct V_60 * V_6 ;
int V_75 = 0 ;
F_53 ( ! F_54 ( V_18 ) ) ;
V_18 -> V_79 = F_64 ( V_18 ) ;
V_6 = V_60 ( V_20 , V_18 -> V_79 ) ;
V_83 = & V_6 -> V_16 ;
V_28 = F_48 ( V_20 , V_18 -> V_79 ) ;
F_21 ( V_28 ) ;
F_55 ( V_18 , V_83 ) ;
if ( V_74 ) {
F_53 ( V_18 -> V_79 != V_74 -> V_84 ) ;
V_75 = F_56 ( V_74 ) ;
}
F_23 ( V_28 ) ;
F_59 ( F_19 ( V_18 ) , V_18 -> V_21 , 1 ) ;
return V_75 ;
}
static void F_65 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 -> V_22 . V_20 ;
struct V_48 * V_49 ;
if ( V_18 -> V_85 != V_86 ) {
F_63 ( V_18 , NULL ) ;
return;
}
F_53 ( ! F_54 ( V_18 ) ) ;
V_49 = & V_20 -> V_50 [ F_66 ( V_18 ) ] ;
F_21 ( & V_49 -> V_28 ) ;
F_55 ( V_18 , & V_49 -> V_6 ) ;
F_59 ( F_19 ( V_18 ) , V_18 -> V_21 , 1 ) ;
F_23 ( & V_49 -> V_28 ) ;
}
void F_67 ( struct V_17 * V_18 )
{
if ( V_18 -> V_85 != V_87 ) {
F_25 () ;
F_65 ( V_18 ) ;
F_26 () ;
}
}
void F_68 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 -> V_22 . V_20 ;
T_6 * V_28 ;
int V_88 ;
if ( F_54 ( V_18 ) )
return;
if ( V_18 -> V_85 == V_86 )
V_28 = & V_20 -> V_50 [ F_66 ( V_18 ) ] . V_28 ;
else
V_28 = F_48 ( V_20 , V_18 -> V_79 ) ;
F_69 ( V_28 ) ;
V_88 = F_70 ( V_18 ) ;
if ( V_88 )
F_59 ( F_19 ( V_18 ) , V_18 -> V_21 , - 1 ) ;
F_71 ( V_28 ) ;
}
int F_72 ( struct V_65 * V_66 ,
struct V_17 * V_18 , T_7 V_89 ,
int (* F_73)( struct V_65 * ,
struct V_17 * , T_5 , struct V_68 * * ) ,
int (* V_47)( struct V_17 * V_18 , struct V_68 * V_69 ) )
{
struct V_19 * V_70 = V_66 -> V_20 ;
const unsigned short V_7 = F_14 ( V_18 ) -> V_24 ;
struct V_5 * V_6 ;
struct V_1 * V_8 ;
int V_90 ;
struct V_4 * V_4 = F_19 ( V_18 ) ;
int V_75 = 1 ;
if ( ! V_7 ) {
int V_91 , V_92 , V_93 , V_94 , V_11 ;
static T_7 V_95 ;
T_7 V_96 = V_95 + V_89 ;
struct V_32 * V_15 ;
struct V_68 * V_74 = NULL ;
F_74 ( & V_93 , & V_94 ) ;
V_92 = ( V_94 - V_93 ) + 1 ;
F_25 () ;
for ( V_91 = 1 ; V_91 <= V_92 ; V_91 ++ ) {
V_11 = V_93 + ( V_91 + V_96 ) % V_92 ;
if ( F_75 ( V_11 ) )
continue;
V_6 = & V_70 -> V_26 [ F_18 ( V_4 , V_11 ,
V_70 -> V_27 ) ] ;
F_21 ( & V_6 -> V_28 ) ;
F_28 (tb, node, &head->chain) {
if ( F_29 ( V_10 ( V_8 ) , V_4 ) &&
V_8 -> V_11 == V_11 ) {
if ( V_8 -> V_12 >= 0 )
goto V_97;
F_53 ( F_8 ( & V_8 -> V_14 ) ) ;
if ( ! F_73 ( V_66 , V_18 ,
V_11 , & V_74 ) )
goto V_98;
goto V_97;
}
}
V_8 = F_1 ( V_70 -> V_29 ,
V_4 , V_6 , V_11 ) ;
if ( ! V_8 ) {
F_23 ( & V_6 -> V_28 ) ;
break;
}
V_8 -> V_12 = - 1 ;
goto V_98;
V_97:
F_23 ( & V_6 -> V_28 ) ;
}
F_26 () ;
return - V_81 ;
V_98:
V_95 += V_91 ;
F_12 ( V_18 , V_8 , V_11 ) ;
if ( F_54 ( V_18 ) ) {
F_14 ( V_18 ) -> V_78 = F_52 ( V_11 ) ;
V_75 += V_47 ( V_18 , V_74 ) ;
}
if ( V_74 )
V_75 += F_76 ( V_74 , V_70 ) ;
F_23 ( & V_6 -> V_28 ) ;
if ( V_74 ) {
F_60 ( V_74 , V_66 ) ;
while ( V_75 ) {
V_75 -- ;
F_58 ( V_74 ) ;
}
}
V_90 = 0 ;
goto V_64;
}
V_6 = & V_70 -> V_26 [ F_18 ( V_4 , V_7 , V_70 -> V_27 ) ] ;
V_8 = F_16 ( V_18 ) -> V_25 ;
F_69 ( & V_6 -> V_28 ) ;
if ( F_77 ( & V_8 -> V_14 ) == V_18 && ! V_18 -> V_99 . V_100 ) {
V_47 ( V_18 , NULL ) ;
F_71 ( & V_6 -> V_28 ) ;
return 0 ;
} else {
F_23 ( & V_6 -> V_28 ) ;
V_90 = F_73 ( V_66 , V_18 , V_7 , NULL ) ;
V_64:
F_26 () ;
return V_90 ;
}
}
int F_78 ( struct V_65 * V_66 ,
struct V_17 * V_18 )
{
return F_72 ( V_66 , V_18 , F_61 ( V_18 ) ,
F_47 , F_63 ) ;
}
void F_79 ( struct V_19 * V_22 )
{
int V_91 ;
F_80 ( & V_22 -> V_23 , 0 ) ;
for ( V_91 = 0 ; V_91 < V_101 ; V_91 ++ ) {
F_81 ( & V_22 -> V_50 [ V_91 ] . V_28 ) ;
F_82 ( & V_22 -> V_50 [ V_91 ] . V_6 ,
V_91 + V_53 ) ;
}
}
