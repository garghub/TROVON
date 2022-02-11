static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
int V_4 ;
F_2 (bv, bio, i) {
struct V_5 * V_5 = V_3 -> V_6 ;
F_3 ( V_5 , F_4 ( F_5 ( V_1 ) ) ,
F_6 ( V_1 -> V_7 ) ) ;
}
F_7 ( V_1 ) ;
}
static struct V_1 * F_8 ( int V_8 , int V_9 , struct V_1 * V_1 )
{
V_1 -> V_10 = F_1 ;
F_9 ( V_1 , V_8 , V_9 ) ;
F_10 ( V_8 , V_1 ) ;
F_11 ( V_1 ) ;
return NULL ;
}
static struct V_1 *
F_12 ( struct V_11 * V_12 ,
T_1 V_13 , int V_14 ,
T_2 V_15 )
{
struct V_1 * V_1 ;
V_15 &= V_16 ;
V_1 = F_13 ( V_15 , V_14 ) ;
if ( V_1 == NULL && ( V_17 -> V_18 & V_19 ) ) {
while ( ! V_1 && ( V_14 /= 2 ) )
V_1 = F_13 ( V_15 , V_14 ) ;
}
if ( V_1 ) {
F_14 ( V_1 , V_12 ) ;
V_1 -> V_20 . V_21 = V_13 ;
}
return V_1 ;
}
static void
F_15 ( struct V_5 * V_5 , struct V_22 * V_23 , int V_24 )
{
struct V_25 * V_25 = V_5 -> V_26 -> V_27 ;
struct V_22 * V_28 , * V_29 ;
int V_30 = 0 ;
if ( ! F_16 ( V_5 ) ) {
if ( V_25 -> V_31 == V_32 &&
F_17 ( V_23 ) ) {
F_18 ( V_5 ) ;
return;
}
F_19 ( V_5 , F_20 ( V_25 ) , 0 ) ;
}
V_29 = F_21 ( V_5 ) ;
V_28 = V_29 ;
do {
if ( V_30 == V_24 ) {
V_28 -> V_33 = V_23 -> V_33 ;
V_28 -> V_34 = V_23 -> V_34 ;
V_28 -> V_35 = V_23 -> V_35 ;
break;
}
V_28 = V_28 -> V_36 ;
V_30 ++ ;
} while ( V_28 != V_29 );
}
static struct V_1 *
F_22 ( struct V_1 * V_1 , struct V_5 * V_5 , unsigned V_37 ,
T_1 * V_38 , struct V_22 * V_39 ,
unsigned long * V_40 , T_3 V_41 ,
T_2 V_42 )
{
struct V_25 * V_25 = V_5 -> V_26 -> V_27 ;
const unsigned V_43 = V_25 -> V_31 ;
const unsigned V_44 = V_45 >> V_43 ;
const unsigned V_46 = 1 << V_43 ;
T_1 V_47 ;
T_1 V_48 ;
T_1 V_49 ;
T_1 V_50 [ V_51 ] ;
unsigned V_24 ;
unsigned V_52 = V_44 ;
struct V_11 * V_12 = NULL ;
int V_53 ;
int V_54 = 1 ;
unsigned V_55 ;
unsigned V_56 ;
if ( F_16 ( V_5 ) )
goto V_57;
V_47 = ( T_1 ) V_5 -> V_58 << ( V_32 - V_43 ) ;
V_48 = V_47 + V_37 * V_44 ;
V_49 = ( F_23 ( V_25 ) + V_46 - 1 ) >> V_43 ;
if ( V_48 > V_49 )
V_48 = V_49 ;
V_24 = 0 ;
V_55 = V_39 -> V_59 >> V_43 ;
if ( F_24 ( V_39 ) && V_47 > * V_40 &&
V_47 < ( * V_40 + V_55 ) ) {
unsigned V_60 = V_47 - * V_40 ;
unsigned V_61 = V_55 - V_60 ;
for ( V_56 = 0 ; ; V_56 ++ ) {
if ( V_56 == V_61 ) {
F_25 ( V_39 ) ;
break;
}
if ( V_24 == V_44 )
break;
V_50 [ V_24 ] = V_39 -> V_35 + V_60 +
V_56 ;
V_24 ++ ;
V_47 ++ ;
}
V_12 = V_39 -> V_34 ;
}
V_39 -> V_62 = V_5 ;
while ( V_24 < V_44 ) {
V_39 -> V_33 = 0 ;
V_39 -> V_59 = 0 ;
if ( V_47 < V_48 ) {
V_39 -> V_59 = ( V_48 - V_47 ) << V_43 ;
if ( V_41 ( V_25 , V_47 , V_39 , 0 ) )
goto V_57;
* V_40 = V_47 ;
}
if ( ! F_24 ( V_39 ) ) {
V_54 = 0 ;
if ( V_52 == V_44 )
V_52 = V_24 ;
V_24 ++ ;
V_47 ++ ;
continue;
}
if ( F_17 ( V_39 ) ) {
F_15 ( V_5 , V_39 , V_24 ) ;
goto V_57;
}
if ( V_52 != V_44 )
goto V_57;
if ( V_24 && V_50 [ V_24 - 1 ] != V_39 -> V_35 - 1 )
goto V_57;
V_55 = V_39 -> V_59 >> V_43 ;
for ( V_56 = 0 ; ; V_56 ++ ) {
if ( V_56 == V_55 ) {
F_25 ( V_39 ) ;
break;
} else if ( V_24 == V_44 )
break;
V_50 [ V_24 ] = V_39 -> V_35 + V_56 ;
V_24 ++ ;
V_47 ++ ;
}
V_12 = V_39 -> V_34 ;
}
if ( V_52 != V_44 ) {
F_26 ( V_5 , V_52 << V_43 , V_45 ) ;
if ( V_52 == 0 ) {
F_18 ( V_5 ) ;
F_27 ( V_5 ) ;
goto V_63;
}
} else if ( V_54 ) {
F_28 ( V_5 ) ;
}
if ( V_54 && V_44 == 1 && ! F_29 ( V_5 ) &&
F_30 ( V_5 ) == 0 ) {
F_18 ( V_5 ) ;
goto V_57;
}
if ( V_1 && ( * V_38 != V_50 [ 0 ] - 1 ) )
V_1 = F_8 ( V_64 , 0 , V_1 ) ;
V_65:
if ( V_1 == NULL ) {
if ( V_52 == V_44 ) {
if ( ! F_31 ( V_12 , V_50 [ 0 ] << ( V_43 - 9 ) ,
V_5 ) )
goto V_63;
}
V_1 = F_12 ( V_12 , V_50 [ 0 ] << ( V_43 - 9 ) ,
F_32 ( int , V_37 , V_66 ) , V_42 ) ;
if ( V_1 == NULL )
goto V_57;
}
V_53 = V_52 << V_43 ;
if ( F_33 ( V_1 , V_5 , V_53 , 0 ) < V_53 ) {
V_1 = F_8 ( V_64 , 0 , V_1 ) ;
goto V_65;
}
V_56 = V_47 - * V_40 ;
V_55 = V_39 -> V_59 >> V_43 ;
if ( ( F_34 ( V_39 ) && V_56 == V_55 ) ||
( V_52 != V_44 ) )
V_1 = F_8 ( V_64 , 0 , V_1 ) ;
else
* V_38 = V_50 [ V_44 - 1 ] ;
V_63:
return V_1 ;
V_57:
if ( V_1 )
V_1 = F_8 ( V_64 , 0 , V_1 ) ;
if ( ! F_29 ( V_5 ) )
F_35 ( V_5 , V_41 ) ;
else
F_27 ( V_5 ) ;
goto V_63;
}
int
F_36 ( struct V_67 * V_26 , struct V_68 * V_69 ,
unsigned V_37 , T_3 V_41 )
{
struct V_1 * V_1 = NULL ;
unsigned V_70 ;
T_1 V_38 = 0 ;
struct V_22 V_39 ;
unsigned long V_40 = 0 ;
T_2 V_42 = F_37 ( V_26 ) ;
V_39 . V_33 = 0 ;
V_39 . V_59 = 0 ;
for ( V_70 = 0 ; V_70 < V_37 ; V_70 ++ ) {
struct V_5 * V_5 = F_38 ( V_69 ) ;
F_39 ( & V_5 -> V_18 ) ;
F_40 ( & V_5 -> V_71 ) ;
if ( ! F_41 ( V_5 , V_26 ,
V_5 -> V_58 ,
V_42 ) ) {
V_1 = F_22 ( V_1 , V_5 ,
V_37 - V_70 ,
& V_38 , & V_39 ,
& V_40 ,
V_41 , V_42 ) ;
}
F_42 ( V_5 ) ;
}
F_43 ( ! F_44 ( V_69 ) ) ;
if ( V_1 )
F_8 ( V_64 , 0 , V_1 ) ;
return 0 ;
}
int F_45 ( struct V_5 * V_5 , T_3 V_41 )
{
struct V_1 * V_1 = NULL ;
T_1 V_38 = 0 ;
struct V_22 V_39 ;
unsigned long V_40 = 0 ;
T_2 V_42 = F_46 ( V_5 -> V_26 , V_16 ) ;
V_39 . V_33 = 0 ;
V_39 . V_59 = 0 ;
V_1 = F_22 ( V_1 , V_5 , 1 , & V_38 ,
& V_39 , & V_40 , V_41 , V_42 ) ;
if ( V_1 )
F_8 ( V_64 , 0 , V_1 ) ;
return 0 ;
}
static void F_47 ( struct V_5 * V_5 , unsigned V_72 )
{
unsigned V_73 = 0 ;
struct V_22 * V_23 , * V_29 ;
if ( ! F_16 ( V_5 ) )
return;
V_29 = F_21 ( V_5 ) ;
V_23 = V_29 ;
do {
if ( V_73 ++ == V_72 )
break;
F_48 ( V_23 ) ;
V_23 = V_23 -> V_36 ;
} while ( V_23 != V_29 );
if ( V_74 && F_29 ( V_5 ) )
F_49 ( V_5 ) ;
}
void F_50 ( struct V_5 * V_5 )
{
F_47 ( V_5 , ~ 0U ) ;
}
static int F_51 ( struct V_5 * V_5 , struct V_75 * V_76 ,
void * V_77 )
{
struct V_78 * V_79 = V_77 ;
struct V_1 * V_1 = V_79 -> V_1 ;
struct V_67 * V_26 = V_5 -> V_26 ;
struct V_25 * V_25 = V_5 -> V_26 -> V_27 ;
const unsigned V_43 = V_25 -> V_31 ;
unsigned long V_80 ;
const unsigned V_44 = V_45 >> V_43 ;
T_1 V_48 ;
T_1 V_47 ;
T_1 V_50 [ V_51 ] ;
unsigned V_24 ;
unsigned V_72 = V_44 ;
struct V_11 * V_12 = NULL ;
int V_81 = 0 ;
T_1 V_82 = 0 ;
struct V_11 * V_83 = NULL ;
int V_53 ;
struct V_22 V_39 ;
T_4 V_84 = F_23 ( V_25 ) ;
int V_85 = 0 ;
int V_9 = F_52 ( V_76 ) ;
if ( F_16 ( V_5 ) ) {
struct V_22 * V_29 = F_21 ( V_5 ) ;
struct V_22 * V_23 = V_29 ;
V_24 = 0 ;
do {
F_43 ( F_53 ( V_23 ) ) ;
if ( ! F_24 ( V_23 ) ) {
if ( F_54 ( V_23 ) )
goto V_57;
if ( V_72 == V_44 )
V_72 = V_24 ;
continue;
}
if ( V_72 != V_44 )
goto V_57;
if ( ! F_54 ( V_23 ) || ! F_17 ( V_23 ) )
goto V_57;
if ( V_24 ) {
if ( V_23 -> V_35 != V_50 [ V_24 - 1 ] + 1 )
goto V_57;
}
V_50 [ V_24 ++ ] = V_23 -> V_35 ;
V_81 = F_34 ( V_23 ) ;
if ( V_81 ) {
V_82 = V_23 -> V_35 ;
V_83 = V_23 -> V_34 ;
}
V_12 = V_23 -> V_34 ;
} while ( ( V_23 = V_23 -> V_36 ) != V_29 );
if ( V_72 )
goto V_86;
goto V_57;
}
F_43 ( ! F_29 ( V_5 ) ) ;
V_47 = ( T_1 ) V_5 -> V_58 << ( V_32 - V_43 ) ;
V_48 = ( V_84 - 1 ) >> V_43 ;
V_39 . V_62 = V_5 ;
for ( V_24 = 0 ; V_24 < V_44 ; ) {
V_39 . V_33 = 0 ;
V_39 . V_59 = 1 << V_43 ;
if ( V_79 -> V_41 ( V_25 , V_47 , & V_39 , 1 ) )
goto V_57;
if ( F_55 ( & V_39 ) )
F_56 ( & V_39 ) ;
if ( F_34 ( & V_39 ) ) {
V_82 = V_39 . V_35 ;
V_83 = V_39 . V_34 ;
}
if ( V_24 ) {
if ( V_39 . V_35 != V_50 [ V_24 - 1 ] + 1 )
goto V_57;
}
V_50 [ V_24 ++ ] = V_39 . V_35 ;
V_81 = F_34 ( & V_39 ) ;
V_12 = V_39 . V_34 ;
if ( V_47 == V_48 )
break;
V_47 ++ ;
}
F_43 ( V_24 == 0 ) ;
V_72 = V_24 ;
V_86:
V_80 = V_84 >> V_32 ;
if ( V_5 -> V_58 >= V_80 ) {
unsigned V_87 = V_84 & ( V_45 - 1 ) ;
if ( V_5 -> V_58 > V_80 || ! V_87 )
goto V_57;
F_26 ( V_5 , V_87 , V_45 ) ;
}
if ( V_1 && V_79 -> V_38 != V_50 [ 0 ] - 1 )
V_1 = F_8 ( V_88 , V_9 , V_1 ) ;
V_65:
if ( V_1 == NULL ) {
if ( V_72 == V_44 ) {
if ( ! F_57 ( V_12 , V_50 [ 0 ] << ( V_43 - 9 ) ,
V_5 , V_76 ) )
goto V_63;
}
V_1 = F_12 ( V_12 , V_50 [ 0 ] << ( V_43 - 9 ) ,
V_66 , V_89 | V_90 ) ;
if ( V_1 == NULL )
goto V_57;
F_58 ( V_76 , V_1 ) ;
V_1 -> V_91 = V_25 -> V_92 ;
}
F_59 ( V_76 , V_5 , V_45 ) ;
V_53 = V_72 << V_43 ;
if ( F_33 ( V_1 , V_5 , V_53 , 0 ) < V_53 ) {
V_1 = F_8 ( V_88 , V_9 , V_1 ) ;
goto V_65;
}
F_47 ( V_5 , V_72 ) ;
F_43 ( F_60 ( V_5 ) ) ;
F_61 ( V_5 ) ;
F_27 ( V_5 ) ;
if ( V_81 || ( V_72 != V_44 ) ) {
V_1 = F_8 ( V_88 , V_9 , V_1 ) ;
if ( V_82 ) {
F_62 ( V_83 ,
V_82 , 1 << V_43 ) ;
}
} else {
V_79 -> V_38 = V_50 [ V_44 - 1 ] ;
}
goto V_63;
V_57:
if ( V_1 )
V_1 = F_8 ( V_88 , V_9 , V_1 ) ;
if ( V_79 -> V_93 ) {
V_85 = V_26 -> V_94 -> V_95 ( V_5 , V_76 ) ;
} else {
V_85 = - V_96 ;
goto V_63;
}
F_63 ( V_26 , V_85 ) ;
V_63:
V_79 -> V_1 = V_1 ;
return V_85 ;
}
int
F_64 ( struct V_67 * V_26 ,
struct V_75 * V_76 , T_3 V_41 )
{
struct V_97 V_98 ;
int V_85 ;
F_65 ( & V_98 ) ;
if ( ! V_41 )
V_85 = F_66 ( V_26 , V_76 ) ;
else {
struct V_78 V_79 = {
. V_1 = NULL ,
. V_38 = 0 ,
. V_41 = V_41 ,
. V_93 = 1 ,
} ;
V_85 = F_67 ( V_26 , V_76 , F_51 , & V_79 ) ;
if ( V_79 . V_1 ) {
int V_9 = ( V_76 -> V_99 == V_100 ?
V_101 : 0 ) ;
F_8 ( V_88 , V_9 , V_79 . V_1 ) ;
}
}
F_68 ( & V_98 ) ;
return V_85 ;
}
int F_69 ( struct V_5 * V_5 , T_3 V_41 ,
struct V_75 * V_76 )
{
struct V_78 V_79 = {
. V_1 = NULL ,
. V_38 = 0 ,
. V_41 = V_41 ,
. V_93 = 0 ,
} ;
int V_85 = F_51 ( V_5 , V_76 , & V_79 ) ;
if ( V_79 . V_1 ) {
int V_9 = ( V_76 -> V_99 == V_100 ?
V_101 : 0 ) ;
F_8 ( V_88 , V_9 , V_79 . V_1 ) ;
}
return V_85 ;
}
