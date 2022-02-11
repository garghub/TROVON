static inline bool
F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
return F_2 ( V_2 -> V_5 + V_4 -> V_6 ) & F_3 ( V_4 -> V_7 ) ;
}
static inline void
F_4 ( struct V_1 * V_2 ,
const struct V_3 * V_4 , bool V_8 )
{
T_1 V_9 = F_2 ( V_2 -> V_5 + V_4 -> V_6 ) ;
if ( V_8 )
V_9 |= F_3 ( V_4 -> V_7 ) ;
else
V_9 &= ~ F_3 ( V_4 -> V_7 ) ;
F_5 ( V_9 , V_2 -> V_5 + V_4 -> V_6 ) ;
}
static unsigned long
F_6 ( struct V_10 * V_11 , unsigned long V_12 )
{
struct V_13 * V_13 = F_7 ( V_11 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
const struct V_14 * V_15 ;
const struct V_16 * V_17 ;
unsigned V_18 , V_19 , V_20 , V_21 ;
bool V_22 , V_23 ;
unsigned long V_24 ;
T_1 V_25 ;
V_15 = & V_2 -> V_26 [ V_13 -> V_27 ] ;
F_8 ( V_15 -> type != V_28 ) ;
V_17 = & V_15 -> V_29 ;
F_9 ( & V_2 -> V_30 , V_24 ) ;
V_25 = F_2 ( V_2 -> V_5 + V_17 -> V_6 ) ;
F_10 ( & V_2 -> V_30 , V_24 ) ;
V_18 = ( V_25 >> V_17 -> V_31 ) & F_11 ( V_17 -> V_32 - 1 , 0 ) ;
V_18 += V_17 -> V_33 ;
V_19 = ( V_25 >> V_17 -> V_34 ) & F_11 ( V_17 -> V_35 - 1 , 0 ) ;
V_19 += V_17 -> V_36 ;
V_20 = V_25 >> V_17 -> V_37 ;
V_20 &= F_11 ( V_17 -> V_38 - 1 , 0 ) ;
V_22 = ! ! ( V_25 & F_3 ( V_17 -> V_39 ) ) ;
V_23 = ! ! ( V_25 & F_3 ( V_17 -> V_40 ) ) ;
if ( V_22 )
return V_12 ;
if ( ! V_23 )
return 0 ;
for ( V_21 = 0 ; V_21 < V_17 -> V_41 ; V_21 ++ ) {
if ( V_17 -> V_42 [ V_21 ] == V_20 )
break;
}
F_8 ( V_21 == V_17 -> V_41 ) ;
V_21 ++ ;
return F_12 ( ( V_43 ) V_12 * V_18 , V_19 * V_21 ) ;
}
static unsigned long
F_13 ( const struct V_14 * V_15 ,
unsigned long V_44 , unsigned long V_12 ,
unsigned * V_45 , unsigned * V_46 , unsigned * V_47 )
{
const struct V_16 * V_17 ;
unsigned V_18 , V_19 , V_21 ;
V_17 = & V_15 -> V_29 ;
V_21 = 1 ;
V_19 = V_12 / ( 10 * V_48 ) ;
V_19 = F_14 ( unsigned , V_19 , 1 << V_15 -> V_29 . V_35 ) ;
V_19 = F_15 ( unsigned , V_19 , V_17 -> V_36 ) ;
V_18 = ( V_44 / V_48 ) * V_21 * V_19 / ( V_12 / V_48 ) ;
V_18 = F_14 ( unsigned , V_18 , 1 << V_15 -> V_29 . V_32 ) ;
V_18 = F_15 ( unsigned , V_18 , V_17 -> V_33 ) ;
if ( V_45 )
* V_45 = V_18 ;
if ( V_46 )
* V_46 = V_19 ;
if ( V_47 )
* V_47 = V_21 ;
return F_12 ( ( V_43 ) V_12 * V_18 , V_19 * V_21 ) ;
}
static long
F_16 ( struct V_10 * V_11 , unsigned long V_49 ,
unsigned long * V_50 )
{
struct V_13 * V_13 = F_7 ( V_11 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
const struct V_14 * V_15 ;
V_15 = & V_2 -> V_26 [ V_13 -> V_27 ] ;
F_8 ( V_15 -> type != V_28 ) ;
return F_13 ( V_15 , V_49 , * V_50 , NULL , NULL , NULL ) ;
}
static int
F_17 ( struct V_10 * V_11 , unsigned long V_49 ,
unsigned long V_12 )
{
const unsigned V_51 = 100 ;
struct V_13 * V_13 = F_7 ( V_11 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
const struct V_14 * V_15 ;
const struct V_16 * V_17 ;
unsigned long V_44 , V_24 ;
unsigned V_18 , V_19 , V_21 , V_52 ;
T_1 V_25 ;
V_15 = & V_2 -> V_26 [ V_13 -> V_27 ] ;
F_8 ( V_15 -> type != V_28 ) ;
V_17 = & V_15 -> V_29 ;
V_44 = F_13 ( V_15 , V_49 , V_12 ,
& V_18 , & V_19 , & V_21 ) ;
if ( V_44 != V_49 )
F_18 ( L_1 ,
V_15 -> V_53 , V_49 , V_44 ) ;
F_9 ( & V_2 -> V_30 , V_24 ) ;
V_25 = F_2 ( V_2 -> V_5 + V_17 -> V_6 ) ;
V_25 &= ~ ( F_11 ( V_17 -> V_32 - 1 , 0 ) << V_17 -> V_31 ) ;
V_25 |= ( V_18 - V_17 -> V_33 ) << V_17 -> V_31 ;
V_25 &= ~ ( F_11 ( V_17 -> V_35 - 1 , 0 ) << V_17 -> V_34 ) ;
V_25 |= ( V_19 - V_17 -> V_36 ) << V_17 -> V_34 ;
V_25 &= ~ ( F_11 ( V_17 -> V_38 - 1 , 0 ) << V_17 -> V_37 ) ;
V_25 |= V_17 -> V_42 [ V_21 - 1 ] << V_17 -> V_37 ;
V_25 &= ~ F_3 ( V_17 -> V_39 ) ;
V_25 |= F_3 ( V_17 -> V_40 ) ;
F_5 ( V_25 , V_2 -> V_5 + V_17 -> V_6 ) ;
for ( V_52 = 0 ; V_52 < V_51 ; V_52 ++ ) {
V_25 = F_2 ( V_2 -> V_5 + V_17 -> V_6 ) ;
if ( V_25 & F_3 ( V_17 -> V_54 ) )
break;
F_19 ( 1 ) ;
}
F_10 ( & V_2 -> V_30 , V_24 ) ;
if ( V_52 == V_51 )
return - V_55 ;
return 0 ;
}
static T_2 F_20 ( struct V_10 * V_11 )
{
struct V_13 * V_13 = F_7 ( V_11 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
const struct V_14 * V_15 ;
T_1 V_6 ;
T_2 V_52 , V_56 , V_27 = 0 ;
V_15 = & V_2 -> V_26 [ V_13 -> V_27 ] ;
if ( V_15 -> type & V_57 ) {
V_6 = F_2 ( V_2 -> V_5 + V_15 -> V_58 . V_6 ) ;
V_56 = ( V_6 >> V_15 -> V_58 . V_59 ) &
F_11 ( V_15 -> V_58 . V_60 - 1 , 0 ) ;
for ( V_52 = 0 ; V_52 < V_56 ; V_52 ++ ) {
if ( V_15 -> V_61 [ V_52 ] != - 1 )
V_27 ++ ;
}
}
return V_27 ;
}
static int F_21 ( struct V_10 * V_11 , T_2 V_27 )
{
struct V_13 * V_13 = F_7 ( V_11 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
const struct V_14 * V_15 ;
unsigned long V_24 ;
T_2 V_62 , V_56 , V_63 ;
T_1 V_6 , V_64 ;
V_15 = & V_2 -> V_26 [ V_13 -> V_27 ] ;
if ( V_15 -> type & V_57 ) {
V_56 = V_62 = 0 ;
V_63 = 1 << V_15 -> V_58 . V_60 ;
for (; V_56 < V_63 ; V_56 ++ ) {
if ( V_15 -> V_61 [ V_56 ] == - 1 )
continue;
if ( V_62 == V_27 )
break;
V_62 ++ ;
}
F_8 ( V_62 != V_27 ) ;
V_64 = F_11 ( V_15 -> V_58 . V_60 - 1 , 0 ) ;
V_64 <<= V_15 -> V_58 . V_59 ;
F_9 ( & V_2 -> V_30 , V_24 ) ;
V_6 = F_2 ( V_2 -> V_5 + V_15 -> V_58 . V_6 ) ;
V_6 &= ~ V_64 ;
V_6 |= V_56 << V_15 -> V_58 . V_59 ;
F_5 ( V_6 , V_2 -> V_5 + V_15 -> V_58 . V_6 ) ;
F_10 ( & V_2 -> V_30 , V_24 ) ;
return 0 ;
}
return V_27 ? - V_65 : 0 ;
}
static unsigned long
F_22 ( struct V_10 * V_11 , unsigned long V_12 )
{
struct V_13 * V_13 = F_7 ( V_11 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
const struct V_14 * V_15 ;
unsigned long V_44 = V_12 ;
T_1 V_66 , div ;
V_15 = & V_2 -> V_26 [ V_13 -> V_27 ] ;
if ( V_15 -> type & V_67 ) {
V_66 = F_2 ( V_2 -> V_5 + V_15 -> div . V_6 ) ;
div = ( V_66 >> V_15 -> div . V_59 ) &
F_11 ( V_15 -> div . V_60 - 1 , 0 ) ;
div += 1 ;
div *= V_15 -> div . div ;
V_44 /= div ;
}
return V_44 ;
}
static unsigned
F_23 ( const struct V_14 * V_15 ,
unsigned long V_12 , unsigned long V_49 )
{
unsigned div ;
div = F_24 ( V_12 , V_49 ) ;
div = F_14 ( unsigned , div , 1 << V_15 -> div . V_60 ) ;
div = F_15 ( unsigned , div , 1 ) ;
div /= V_15 -> div . div ;
div *= V_15 -> div . div ;
return div ;
}
static long
F_25 ( struct V_10 * V_11 , unsigned long V_49 ,
unsigned long * V_12 )
{
struct V_13 * V_13 = F_7 ( V_11 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
const struct V_14 * V_15 ;
long V_44 = * V_12 ;
V_15 = & V_2 -> V_26 [ V_13 -> V_27 ] ;
if ( V_15 -> type & V_67 )
V_44 /= F_23 ( V_15 , * V_12 , V_49 ) ;
else if ( V_15 -> type & V_68 )
V_44 /= V_15 -> V_69 . div ;
return V_44 ;
}
static int
F_26 ( struct V_10 * V_11 , unsigned long V_49 ,
unsigned long V_12 )
{
struct V_13 * V_13 = F_7 ( V_11 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
const struct V_14 * V_15 ;
const unsigned V_51 = 100 ;
unsigned long V_44 , V_24 ;
unsigned div , V_52 ;
T_1 V_6 , V_64 ;
int V_70 = 0 ;
V_15 = & V_2 -> V_26 [ V_13 -> V_27 ] ;
if ( V_15 -> type & V_67 ) {
div = F_23 ( V_15 , V_12 , V_49 ) ;
V_44 = V_12 / div ;
if ( V_44 != V_49 )
return - V_65 ;
F_9 ( & V_2 -> V_30 , V_24 ) ;
V_6 = F_2 ( V_2 -> V_5 + V_15 -> div . V_6 ) ;
V_64 = F_11 ( V_15 -> div . V_60 - 1 , 0 ) ;
V_6 &= ~ ( V_64 << V_15 -> div . V_59 ) ;
V_6 |= ( ( div / V_15 -> div . div ) - 1 ) << V_15 -> div . V_59 ;
if ( V_15 -> div . V_71 != - 1 )
V_6 &= ~ F_3 ( V_15 -> div . V_71 ) ;
if ( V_15 -> div . V_72 != - 1 )
V_6 |= F_3 ( V_15 -> div . V_72 ) ;
F_5 ( V_6 , V_2 -> V_5 + V_15 -> div . V_6 ) ;
if ( V_15 -> div . V_73 != - 1 ) {
for ( V_52 = 0 ; V_52 < V_51 ; V_52 ++ ) {
V_6 = F_2 ( V_2 -> V_5 + V_15 -> div . V_6 ) ;
if ( ! ( V_6 & F_3 ( V_15 -> div . V_73 ) ) )
break;
F_19 ( 1 ) ;
}
if ( V_52 == V_51 )
V_70 = - V_55 ;
}
F_10 ( & V_2 -> V_30 , V_24 ) ;
return V_70 ;
}
return - V_65 ;
}
static int F_27 ( struct V_10 * V_11 )
{
struct V_13 * V_13 = F_7 ( V_11 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
const struct V_14 * V_15 ;
unsigned long V_24 ;
V_15 = & V_2 -> V_26 [ V_13 -> V_27 ] ;
if ( V_15 -> type & V_74 ) {
F_9 ( & V_2 -> V_30 , V_24 ) ;
F_4 ( V_2 , & V_15 -> V_75 , false ) ;
F_10 ( & V_2 -> V_30 , V_24 ) ;
}
return 0 ;
}
static void F_28 ( struct V_10 * V_11 )
{
struct V_13 * V_13 = F_7 ( V_11 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
const struct V_14 * V_15 ;
unsigned long V_24 ;
V_15 = & V_2 -> V_26 [ V_13 -> V_27 ] ;
if ( V_15 -> type & V_74 ) {
F_9 ( & V_2 -> V_30 , V_24 ) ;
F_4 ( V_2 , & V_15 -> V_75 , true ) ;
F_10 ( & V_2 -> V_30 , V_24 ) ;
}
}
static int F_29 ( struct V_10 * V_11 )
{
struct V_13 * V_13 = F_7 ( V_11 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
const struct V_14 * V_15 ;
unsigned long V_24 ;
int V_76 = 1 ;
V_15 = & V_2 -> V_26 [ V_13 -> V_27 ] ;
if ( V_15 -> type & V_74 ) {
F_9 ( & V_2 -> V_30 , V_24 ) ;
V_76 = ! F_1 ( V_2 , & V_15 -> V_75 ) ;
F_10 ( & V_2 -> V_30 , V_24 ) ;
}
return V_76 ;
}
static int F_30 ( struct V_1 * V_2 , unsigned V_27 )
{
const struct V_14 * V_15 = & V_2 -> V_26 [ V_27 ] ;
struct V_77 V_78 ;
struct V_13 * V_13 = NULL ;
struct V_79 * V_79 , * V_80 ;
const char * V_81 [ 4 ] ;
unsigned V_82 , V_52 , V_83 ;
int V_84 = - V_65 ;
F_31 ( F_32 ( V_15 -> V_61 ) > F_32 ( V_81 ) ) ;
if ( V_15 -> type == V_85 ) {
V_79 = F_33 ( V_2 -> V_86 , V_15 -> V_53 ) ;
if ( F_34 ( V_79 ) ) {
F_35 ( L_2 ,
V_87 , V_15 -> V_53 ) ;
V_84 = - V_88 ;
goto V_89;
}
V_84 = F_36 ( V_79 , V_15 -> V_53 , NULL ) ;
if ( V_84 ) {
F_37 ( V_79 ) ;
goto V_89;
}
V_2 -> V_90 . V_91 [ V_27 ] = V_79 ;
return 0 ;
}
if ( ! V_15 -> type ) {
F_35 ( L_3 , V_87 ,
V_15 -> V_53 ) ;
goto V_89;
}
V_13 = F_38 ( sizeof( * V_13 ) , V_92 ) ;
if ( ! V_13 ) {
V_84 = - V_93 ;
goto V_89;
}
V_13 -> V_11 . V_94 = & V_78 ;
V_13 -> V_2 = V_2 ;
V_13 -> V_27 = V_27 ;
V_78 . V_53 = V_15 -> V_53 ;
V_78 . V_24 = 0 ;
V_78 . V_81 = V_81 ;
V_82 = V_15 -> type ;
if ( V_82 & ( V_57 | V_95 ) ) {
V_78 . V_96 = 0 ;
if ( V_82 & V_57 )
V_83 = 1 << V_15 -> V_58 . V_60 ;
else
V_83 = F_32 ( V_15 -> V_61 ) ;
for ( V_52 = 0 ; V_52 < V_83 ; V_52 ++ ) {
if ( V_15 -> V_61 [ V_52 ] == - 1 )
continue;
V_80 = V_2 -> V_90 . V_91 [ V_15 -> V_61 [ V_52 ] ] ;
V_81 [ V_78 . V_96 ] =
F_39 ( V_80 ) ;
V_78 . V_96 ++ ;
}
F_8 ( ! V_78 . V_96 ) ;
F_8 ( V_78 . V_96 > F_32 ( V_81 ) ) ;
} else {
F_8 ( V_15 -> V_61 [ 0 ] == - 1 ) ;
V_78 . V_96 = 1 ;
V_80 = V_2 -> V_90 . V_91 [ V_15 -> V_61 [ 0 ] ] ;
V_81 [ 0 ] = F_39 ( V_80 ) ;
}
if ( V_82 & V_95 ) {
V_78 . V_97 = V_15 -> V_98 . V_99 ;
V_82 &= ~ V_95 ;
if ( V_82 ) {
F_35 ( L_4 ,
V_87 , V_82 ) ;
goto V_89;
}
} else if ( V_82 & V_28 ) {
V_78 . V_97 = & V_100 ;
V_82 &= ~ V_28 ;
if ( V_82 ) {
F_35 ( L_5 ,
V_87 , V_82 ) ;
goto V_89;
}
} else {
V_78 . V_97 = & V_101 ;
}
V_82 &= ~ ( V_74 | V_68 ) ;
if ( V_82 & V_57 ) {
if ( ! ( V_82 & V_102 ) )
V_78 . V_24 |= V_103 ;
V_82 &= ~ ( V_57 | V_102 ) ;
}
if ( V_82 & V_67 ) {
V_82 &= ~ V_67 ;
} else {
V_78 . V_24 |= V_104 ;
}
if ( V_82 ) {
F_35 ( L_6 , V_87 , V_82 ) ;
goto V_89;
}
V_79 = F_40 ( NULL , & V_13 -> V_11 ) ;
if ( F_34 ( V_79 ) ) {
F_35 ( L_7 , V_87 ,
V_15 -> V_53 ) ;
V_84 = F_41 ( V_79 ) ;
goto V_89;
}
V_84 = F_36 ( V_79 , V_15 -> V_53 , NULL ) ;
if ( V_84 )
goto V_89;
V_2 -> V_90 . V_91 [ V_27 ] = V_79 ;
V_89:
if ( V_84 )
F_42 ( V_13 ) ;
return V_84 ;
}
struct V_1 *
F_43 ( const struct V_14 * V_26 ,
unsigned V_105 , struct V_106 * V_86 )
{
struct V_1 * V_2 ;
V_2 = F_38 ( sizeof( * V_2 ) , V_92 ) ;
if ( ! V_2 )
goto V_107;
V_2 -> V_5 = F_44 ( V_86 , 0 ) ;
if ( ! V_2 -> V_5 ) {
F_35 ( L_8 , V_87 ) ;
goto V_108;
}
V_2 -> V_86 = V_86 ;
V_2 -> V_26 = V_26 ;
V_2 -> V_90 . V_109 = V_105 ;
F_45 ( & V_2 -> V_30 ) ;
return V_2 ;
V_108:
F_42 ( V_2 ) ;
V_107:
return NULL ;
}
int F_46 ( struct V_1 * V_2 )
{
unsigned V_52 ;
int V_84 ;
V_2 -> V_90 . V_91 = F_47 ( V_2 -> V_90 . V_109 , sizeof( struct V_79 * ) ,
V_92 ) ;
if ( ! V_2 -> V_90 . V_91 ) {
V_84 = - V_93 ;
goto V_107;
}
for ( V_52 = 0 ; V_52 < V_2 -> V_90 . V_109 ; V_52 ++ ) {
V_84 = F_30 ( V_2 , V_52 ) ;
if ( V_84 )
goto V_110;
}
V_84 = F_48 ( V_2 -> V_86 , V_111 ,
& V_2 -> V_90 ) ;
if ( V_84 )
goto V_110;
return 0 ;
V_110:
for ( V_52 = 0 ; V_52 < V_2 -> V_90 . V_109 ; V_52 ++ ) {
if ( ! V_2 -> V_90 . V_91 [ V_52 ] )
continue;
if ( V_2 -> V_26 [ V_52 ] . type & V_85 )
F_37 ( V_2 -> V_90 . V_91 [ V_52 ] ) ;
else
F_49 ( V_2 -> V_90 . V_91 [ V_52 ] ) ;
}
F_42 ( V_2 -> V_90 . V_91 ) ;
V_107:
return V_84 ;
}
