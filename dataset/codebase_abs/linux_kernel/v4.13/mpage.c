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
V_1 -> V_20 = V_12 ;
V_1 -> V_21 . V_22 = V_13 ;
}
return V_1 ;
}
static void
F_14 ( struct V_5 * V_5 , struct V_23 * V_24 , int V_25 )
{
struct V_26 * V_26 = V_5 -> V_27 -> V_28 ;
struct V_23 * V_29 , * V_30 ;
int V_31 = 0 ;
if ( ! F_15 ( V_5 ) ) {
if ( V_26 -> V_32 == V_33 &&
F_16 ( V_24 ) ) {
F_17 ( V_5 ) ;
return;
}
F_18 ( V_5 , F_19 ( V_26 ) , 0 ) ;
}
V_30 = F_20 ( V_5 ) ;
V_29 = V_30 ;
do {
if ( V_31 == V_25 ) {
V_29 -> V_34 = V_24 -> V_34 ;
V_29 -> V_35 = V_24 -> V_35 ;
V_29 -> V_36 = V_24 -> V_36 ;
break;
}
V_29 = V_29 -> V_37 ;
V_31 ++ ;
} while ( V_29 != V_30 );
}
static struct V_1 *
F_21 ( struct V_1 * V_1 , struct V_5 * V_5 , unsigned V_38 ,
T_1 * V_39 , struct V_23 * V_40 ,
unsigned long * V_41 , T_3 V_42 ,
T_2 V_43 )
{
struct V_26 * V_26 = V_5 -> V_27 -> V_28 ;
const unsigned V_44 = V_26 -> V_32 ;
const unsigned V_45 = V_46 >> V_44 ;
const unsigned V_47 = 1 << V_44 ;
T_1 V_48 ;
T_1 V_49 ;
T_1 V_50 ;
T_1 V_51 [ V_52 ] ;
unsigned V_25 ;
unsigned V_53 = V_45 ;
struct V_11 * V_12 = NULL ;
int V_54 ;
int V_55 = 1 ;
unsigned V_56 ;
unsigned V_57 ;
if ( F_15 ( V_5 ) )
goto V_58;
V_48 = ( T_1 ) V_5 -> V_59 << ( V_33 - V_44 ) ;
V_49 = V_48 + V_38 * V_45 ;
V_50 = ( F_22 ( V_26 ) + V_47 - 1 ) >> V_44 ;
if ( V_49 > V_50 )
V_49 = V_50 ;
V_25 = 0 ;
V_56 = V_40 -> V_60 >> V_44 ;
if ( F_23 ( V_40 ) && V_48 > * V_41 &&
V_48 < ( * V_41 + V_56 ) ) {
unsigned V_61 = V_48 - * V_41 ;
unsigned V_62 = V_56 - V_61 ;
for ( V_57 = 0 ; ; V_57 ++ ) {
if ( V_57 == V_62 ) {
F_24 ( V_40 ) ;
break;
}
if ( V_25 == V_45 )
break;
V_51 [ V_25 ] = V_40 -> V_36 + V_61 +
V_57 ;
V_25 ++ ;
V_48 ++ ;
}
V_12 = V_40 -> V_35 ;
}
V_40 -> V_63 = V_5 ;
while ( V_25 < V_45 ) {
V_40 -> V_34 = 0 ;
V_40 -> V_60 = 0 ;
if ( V_48 < V_49 ) {
V_40 -> V_60 = ( V_49 - V_48 ) << V_44 ;
if ( V_42 ( V_26 , V_48 , V_40 , 0 ) )
goto V_58;
* V_41 = V_48 ;
}
if ( ! F_23 ( V_40 ) ) {
V_55 = 0 ;
if ( V_53 == V_45 )
V_53 = V_25 ;
V_25 ++ ;
V_48 ++ ;
continue;
}
if ( F_16 ( V_40 ) ) {
F_14 ( V_5 , V_40 , V_25 ) ;
goto V_58;
}
if ( V_53 != V_45 )
goto V_58;
if ( V_25 && V_51 [ V_25 - 1 ] != V_40 -> V_36 - 1 )
goto V_58;
V_56 = V_40 -> V_60 >> V_44 ;
for ( V_57 = 0 ; ; V_57 ++ ) {
if ( V_57 == V_56 ) {
F_24 ( V_40 ) ;
break;
} else if ( V_25 == V_45 )
break;
V_51 [ V_25 ] = V_40 -> V_36 + V_57 ;
V_25 ++ ;
V_48 ++ ;
}
V_12 = V_40 -> V_35 ;
}
if ( V_53 != V_45 ) {
F_25 ( V_5 , V_53 << V_44 , V_46 ) ;
if ( V_53 == 0 ) {
F_17 ( V_5 ) ;
F_26 ( V_5 ) ;
goto V_64;
}
} else if ( V_55 ) {
F_27 ( V_5 ) ;
}
if ( V_55 && V_45 == 1 && ! F_28 ( V_5 ) &&
F_29 ( V_5 ) == 0 ) {
F_17 ( V_5 ) ;
goto V_58;
}
if ( V_1 && ( * V_39 != V_51 [ 0 ] - 1 ) )
V_1 = F_8 ( V_65 , 0 , V_1 ) ;
V_66:
if ( V_1 == NULL ) {
if ( V_53 == V_45 ) {
if ( ! F_30 ( V_12 , V_51 [ 0 ] << ( V_44 - 9 ) ,
V_5 ) )
goto V_64;
}
V_1 = F_12 ( V_12 , V_51 [ 0 ] << ( V_44 - 9 ) ,
F_31 ( int , V_38 , V_67 ) , V_43 ) ;
if ( V_1 == NULL )
goto V_58;
}
V_54 = V_53 << V_44 ;
if ( F_32 ( V_1 , V_5 , V_54 , 0 ) < V_54 ) {
V_1 = F_8 ( V_65 , 0 , V_1 ) ;
goto V_66;
}
V_57 = V_48 - * V_41 ;
V_56 = V_40 -> V_60 >> V_44 ;
if ( ( F_33 ( V_40 ) && V_57 == V_56 ) ||
( V_53 != V_45 ) )
V_1 = F_8 ( V_65 , 0 , V_1 ) ;
else
* V_39 = V_51 [ V_45 - 1 ] ;
V_64:
return V_1 ;
V_58:
if ( V_1 )
V_1 = F_8 ( V_65 , 0 , V_1 ) ;
if ( ! F_28 ( V_5 ) )
F_34 ( V_5 , V_42 ) ;
else
F_26 ( V_5 ) ;
goto V_64;
}
int
F_35 ( struct V_68 * V_27 , struct V_69 * V_70 ,
unsigned V_38 , T_3 V_42 )
{
struct V_1 * V_1 = NULL ;
unsigned V_71 ;
T_1 V_39 = 0 ;
struct V_23 V_40 ;
unsigned long V_41 = 0 ;
T_2 V_43 = F_36 ( V_27 ) ;
V_40 . V_34 = 0 ;
V_40 . V_60 = 0 ;
for ( V_71 = 0 ; V_71 < V_38 ; V_71 ++ ) {
struct V_5 * V_5 = F_37 ( V_70 ) ;
F_38 ( & V_5 -> V_18 ) ;
F_39 ( & V_5 -> V_72 ) ;
if ( ! F_40 ( V_5 , V_27 ,
V_5 -> V_59 ,
V_43 ) ) {
V_1 = F_21 ( V_1 , V_5 ,
V_38 - V_71 ,
& V_39 , & V_40 ,
& V_41 ,
V_42 , V_43 ) ;
}
F_41 ( V_5 ) ;
}
F_42 ( ! F_43 ( V_70 ) ) ;
if ( V_1 )
F_8 ( V_65 , 0 , V_1 ) ;
return 0 ;
}
int F_44 ( struct V_5 * V_5 , T_3 V_42 )
{
struct V_1 * V_1 = NULL ;
T_1 V_39 = 0 ;
struct V_23 V_40 ;
unsigned long V_41 = 0 ;
T_2 V_43 = F_45 ( V_5 -> V_27 , V_16 ) ;
V_40 . V_34 = 0 ;
V_40 . V_60 = 0 ;
V_1 = F_21 ( V_1 , V_5 , 1 , & V_39 ,
& V_40 , & V_41 , V_42 , V_43 ) ;
if ( V_1 )
F_8 ( V_65 , 0 , V_1 ) ;
return 0 ;
}
static void F_46 ( struct V_5 * V_5 , unsigned V_73 )
{
unsigned V_74 = 0 ;
struct V_23 * V_24 , * V_30 ;
if ( ! F_15 ( V_5 ) )
return;
V_30 = F_20 ( V_5 ) ;
V_24 = V_30 ;
do {
if ( V_74 ++ == V_73 )
break;
F_47 ( V_24 ) ;
V_24 = V_24 -> V_37 ;
} while ( V_24 != V_30 );
if ( V_75 && F_28 ( V_5 ) )
F_48 ( V_5 ) ;
}
static int F_49 ( struct V_5 * V_5 , struct V_76 * V_77 ,
void * V_78 )
{
struct V_79 * V_80 = V_78 ;
struct V_1 * V_1 = V_80 -> V_1 ;
struct V_68 * V_27 = V_5 -> V_27 ;
struct V_26 * V_26 = V_5 -> V_27 -> V_28 ;
const unsigned V_44 = V_26 -> V_32 ;
unsigned long V_81 ;
const unsigned V_45 = V_46 >> V_44 ;
T_1 V_49 ;
T_1 V_48 ;
T_1 V_51 [ V_52 ] ;
unsigned V_25 ;
unsigned V_73 = V_45 ;
struct V_11 * V_12 = NULL ;
int V_82 = 0 ;
T_1 V_83 = 0 ;
struct V_11 * V_84 = NULL ;
int V_54 ;
struct V_23 V_40 ;
T_4 V_85 = F_22 ( V_26 ) ;
int V_86 = 0 ;
int V_9 = F_50 ( V_77 ) ;
if ( F_15 ( V_5 ) ) {
struct V_23 * V_30 = F_20 ( V_5 ) ;
struct V_23 * V_24 = V_30 ;
V_25 = 0 ;
do {
F_42 ( F_51 ( V_24 ) ) ;
if ( ! F_23 ( V_24 ) ) {
if ( F_52 ( V_24 ) )
goto V_58;
if ( V_73 == V_45 )
V_73 = V_25 ;
continue;
}
if ( V_73 != V_45 )
goto V_58;
if ( ! F_52 ( V_24 ) || ! F_16 ( V_24 ) )
goto V_58;
if ( V_25 ) {
if ( V_24 -> V_36 != V_51 [ V_25 - 1 ] + 1 )
goto V_58;
}
V_51 [ V_25 ++ ] = V_24 -> V_36 ;
V_82 = F_33 ( V_24 ) ;
if ( V_82 ) {
V_83 = V_24 -> V_36 ;
V_84 = V_24 -> V_35 ;
}
V_12 = V_24 -> V_35 ;
} while ( ( V_24 = V_24 -> V_37 ) != V_30 );
if ( V_73 )
goto V_87;
goto V_58;
}
F_42 ( ! F_28 ( V_5 ) ) ;
V_48 = ( T_1 ) V_5 -> V_59 << ( V_33 - V_44 ) ;
V_49 = ( V_85 - 1 ) >> V_44 ;
V_40 . V_63 = V_5 ;
for ( V_25 = 0 ; V_25 < V_45 ; ) {
V_40 . V_34 = 0 ;
V_40 . V_60 = 1 << V_44 ;
if ( V_80 -> V_42 ( V_26 , V_48 , & V_40 , 1 ) )
goto V_58;
if ( F_53 ( & V_40 ) )
F_54 ( & V_40 ) ;
if ( F_33 ( & V_40 ) ) {
V_83 = V_40 . V_36 ;
V_84 = V_40 . V_35 ;
}
if ( V_25 ) {
if ( V_40 . V_36 != V_51 [ V_25 - 1 ] + 1 )
goto V_58;
}
V_51 [ V_25 ++ ] = V_40 . V_36 ;
V_82 = F_33 ( & V_40 ) ;
V_12 = V_40 . V_35 ;
if ( V_48 == V_49 )
break;
V_48 ++ ;
}
F_42 ( V_25 == 0 ) ;
V_73 = V_25 ;
V_87:
V_81 = V_85 >> V_33 ;
if ( V_5 -> V_59 >= V_81 ) {
unsigned V_88 = V_85 & ( V_46 - 1 ) ;
if ( V_5 -> V_59 > V_81 || ! V_88 )
goto V_58;
F_25 ( V_5 , V_88 , V_46 ) ;
}
if ( V_1 && V_80 -> V_39 != V_51 [ 0 ] - 1 )
V_1 = F_8 ( V_89 , V_9 , V_1 ) ;
V_66:
if ( V_1 == NULL ) {
if ( V_73 == V_45 ) {
if ( ! F_55 ( V_12 , V_51 [ 0 ] << ( V_44 - 9 ) ,
V_5 , V_77 ) ) {
F_46 ( V_5 , V_73 ) ;
goto V_64;
}
}
V_1 = F_12 ( V_12 , V_51 [ 0 ] << ( V_44 - 9 ) ,
V_67 , V_90 | V_91 ) ;
if ( V_1 == NULL )
goto V_58;
F_56 ( V_77 , V_1 ) ;
V_1 -> V_92 = V_26 -> V_93 ;
}
F_57 ( V_77 , V_5 , V_46 ) ;
V_54 = V_73 << V_44 ;
if ( F_32 ( V_1 , V_5 , V_54 , 0 ) < V_54 ) {
V_1 = F_8 ( V_89 , V_9 , V_1 ) ;
goto V_66;
}
F_46 ( V_5 , V_73 ) ;
F_42 ( F_58 ( V_5 ) ) ;
F_59 ( V_5 ) ;
F_26 ( V_5 ) ;
if ( V_82 || ( V_73 != V_45 ) ) {
V_1 = F_8 ( V_89 , V_9 , V_1 ) ;
if ( V_83 ) {
F_60 ( V_84 ,
V_83 , 1 << V_44 ) ;
}
} else {
V_80 -> V_39 = V_51 [ V_45 - 1 ] ;
}
goto V_64;
V_58:
if ( V_1 )
V_1 = F_8 ( V_89 , V_9 , V_1 ) ;
if ( V_80 -> V_94 ) {
V_86 = V_27 -> V_95 -> V_96 ( V_5 , V_77 ) ;
} else {
V_86 = - V_97 ;
goto V_64;
}
F_61 ( V_27 , V_86 ) ;
V_64:
V_80 -> V_1 = V_1 ;
return V_86 ;
}
int
F_62 ( struct V_68 * V_27 ,
struct V_76 * V_77 , T_3 V_42 )
{
struct V_98 V_99 ;
int V_86 ;
F_63 ( & V_99 ) ;
if ( ! V_42 )
V_86 = F_64 ( V_27 , V_77 ) ;
else {
struct V_79 V_80 = {
. V_1 = NULL ,
. V_39 = 0 ,
. V_42 = V_42 ,
. V_94 = 1 ,
} ;
V_86 = F_65 ( V_27 , V_77 , F_49 , & V_80 ) ;
if ( V_80 . V_1 ) {
int V_9 = ( V_77 -> V_100 == V_101 ?
V_102 : 0 ) ;
F_8 ( V_89 , V_9 , V_80 . V_1 ) ;
}
}
F_66 ( & V_99 ) ;
return V_86 ;
}
int F_67 ( struct V_5 * V_5 , T_3 V_42 ,
struct V_76 * V_77 )
{
struct V_79 V_80 = {
. V_1 = NULL ,
. V_39 = 0 ,
. V_42 = V_42 ,
. V_94 = 0 ,
} ;
int V_86 = F_49 ( V_5 , V_77 , & V_80 ) ;
if ( V_80 . V_1 ) {
int V_9 = ( V_77 -> V_100 == V_101 ?
V_102 : 0 ) ;
F_8 ( V_89 , V_9 , V_80 . V_1 ) ;
}
return V_86 ;
}
