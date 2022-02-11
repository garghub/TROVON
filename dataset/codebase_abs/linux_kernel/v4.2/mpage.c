static void F_1 ( struct V_1 * V_1 , int V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
F_2 (bv, bio, i) {
struct V_6 * V_6 = V_4 -> V_7 ;
F_3 ( V_6 , F_4 ( V_1 ) , V_2 ) ;
}
F_5 ( V_1 ) ;
}
static struct V_1 * F_6 ( int V_8 , struct V_1 * V_1 )
{
V_1 -> V_9 = F_1 ;
F_7 ( V_8 , V_1 ) ;
F_8 ( V_8 , V_1 ) ;
return NULL ;
}
static struct V_1 *
F_9 ( struct V_10 * V_11 ,
T_1 V_12 , int V_13 ,
T_2 V_14 )
{
struct V_1 * V_1 ;
V_1 = F_10 ( V_14 , V_13 ) ;
if ( V_1 == NULL && ( V_15 -> V_16 & V_17 ) ) {
while ( ! V_1 && ( V_13 /= 2 ) )
V_1 = F_10 ( V_14 , V_13 ) ;
}
if ( V_1 ) {
V_1 -> V_18 = V_11 ;
V_1 -> V_19 . V_20 = V_12 ;
}
return V_1 ;
}
static void
F_11 ( struct V_6 * V_6 , struct V_21 * V_22 , int V_23 )
{
struct V_24 * V_24 = V_6 -> V_25 -> V_26 ;
struct V_21 * V_27 , * V_28 ;
int V_29 = 0 ;
if ( ! F_12 ( V_6 ) ) {
if ( V_24 -> V_30 == V_31 &&
F_13 ( V_22 ) ) {
F_14 ( V_6 ) ;
return;
}
F_15 ( V_6 , 1 << V_24 -> V_30 , 0 ) ;
}
V_28 = F_16 ( V_6 ) ;
V_27 = V_28 ;
do {
if ( V_29 == V_23 ) {
V_27 -> V_32 = V_22 -> V_32 ;
V_27 -> V_33 = V_22 -> V_33 ;
V_27 -> V_34 = V_22 -> V_34 ;
break;
}
V_27 = V_27 -> V_35 ;
V_29 ++ ;
} while ( V_27 != V_28 );
}
static struct V_1 *
F_17 ( struct V_1 * V_1 , struct V_6 * V_6 , unsigned V_36 ,
T_1 * V_37 , struct V_21 * V_38 ,
unsigned long * V_39 , T_3 V_40 )
{
struct V_24 * V_24 = V_6 -> V_25 -> V_26 ;
const unsigned V_41 = V_24 -> V_30 ;
const unsigned V_42 = V_43 >> V_41 ;
const unsigned V_44 = 1 << V_41 ;
T_1 V_45 ;
T_1 V_46 ;
T_1 V_47 ;
T_1 V_48 [ V_49 ] ;
unsigned V_23 ;
unsigned V_50 = V_42 ;
struct V_10 * V_11 = NULL ;
int V_51 ;
int V_52 = 1 ;
unsigned V_53 ;
unsigned V_54 ;
if ( F_12 ( V_6 ) )
goto V_55;
V_45 = ( T_1 ) V_6 -> V_56 << ( V_31 - V_41 ) ;
V_46 = V_45 + V_36 * V_42 ;
V_47 = ( F_18 ( V_24 ) + V_44 - 1 ) >> V_41 ;
if ( V_46 > V_47 )
V_46 = V_47 ;
V_23 = 0 ;
V_53 = V_38 -> V_57 >> V_41 ;
if ( F_19 ( V_38 ) && V_45 > * V_39 &&
V_45 < ( * V_39 + V_53 ) ) {
unsigned V_58 = V_45 - * V_39 ;
unsigned V_59 = V_53 - V_58 ;
for ( V_54 = 0 ; ; V_54 ++ ) {
if ( V_54 == V_59 ) {
F_20 ( V_38 ) ;
break;
}
if ( V_23 == V_42 )
break;
V_48 [ V_23 ] = V_38 -> V_34 + V_58 +
V_54 ;
V_23 ++ ;
V_45 ++ ;
}
V_11 = V_38 -> V_33 ;
}
V_38 -> V_60 = V_6 ;
while ( V_23 < V_42 ) {
V_38 -> V_32 = 0 ;
V_38 -> V_57 = 0 ;
if ( V_45 < V_46 ) {
V_38 -> V_57 = ( V_46 - V_45 ) << V_41 ;
if ( V_40 ( V_24 , V_45 , V_38 , 0 ) )
goto V_55;
* V_39 = V_45 ;
}
if ( ! F_19 ( V_38 ) ) {
V_52 = 0 ;
if ( V_50 == V_42 )
V_50 = V_23 ;
V_23 ++ ;
V_45 ++ ;
continue;
}
if ( F_13 ( V_38 ) ) {
F_11 ( V_6 , V_38 , V_23 ) ;
goto V_55;
}
if ( V_50 != V_42 )
goto V_55;
if ( V_23 && V_48 [ V_23 - 1 ] != V_38 -> V_34 - 1 )
goto V_55;
V_53 = V_38 -> V_57 >> V_41 ;
for ( V_54 = 0 ; ; V_54 ++ ) {
if ( V_54 == V_53 ) {
F_20 ( V_38 ) ;
break;
} else if ( V_23 == V_42 )
break;
V_48 [ V_23 ] = V_38 -> V_34 + V_54 ;
V_23 ++ ;
V_45 ++ ;
}
V_11 = V_38 -> V_33 ;
}
if ( V_50 != V_42 ) {
F_21 ( V_6 , V_50 << V_41 , V_43 ) ;
if ( V_50 == 0 ) {
F_14 ( V_6 ) ;
F_22 ( V_6 ) ;
goto V_61;
}
} else if ( V_52 ) {
F_23 ( V_6 ) ;
}
if ( V_52 && V_42 == 1 && ! F_24 ( V_6 ) &&
F_25 ( V_6 ) == 0 ) {
F_14 ( V_6 ) ;
goto V_55;
}
if ( V_1 && ( * V_37 != V_48 [ 0 ] - 1 ) )
V_1 = F_6 ( V_62 , V_1 ) ;
V_63:
if ( V_1 == NULL ) {
if ( V_50 == V_42 ) {
if ( ! F_26 ( V_11 , V_48 [ 0 ] << ( V_41 - 9 ) ,
V_6 ) )
goto V_61;
}
V_1 = F_9 ( V_11 , V_48 [ 0 ] << ( V_41 - 9 ) ,
F_27 ( int , V_36 , F_28 ( V_11 ) ) ,
V_64 ) ;
if ( V_1 == NULL )
goto V_55;
}
V_51 = V_50 << V_41 ;
if ( F_29 ( V_1 , V_6 , V_51 , 0 ) < V_51 ) {
V_1 = F_6 ( V_62 , V_1 ) ;
goto V_63;
}
V_54 = V_45 - * V_39 ;
V_53 = V_38 -> V_57 >> V_41 ;
if ( ( F_30 ( V_38 ) && V_54 == V_53 ) ||
( V_50 != V_42 ) )
V_1 = F_6 ( V_62 , V_1 ) ;
else
* V_37 = V_48 [ V_42 - 1 ] ;
V_61:
return V_1 ;
V_55:
if ( V_1 )
V_1 = F_6 ( V_62 , V_1 ) ;
if ( ! F_24 ( V_6 ) )
F_31 ( V_6 , V_40 ) ;
else
F_22 ( V_6 ) ;
goto V_61;
}
int
F_32 ( struct V_65 * V_25 , struct V_66 * V_67 ,
unsigned V_36 , T_3 V_40 )
{
struct V_1 * V_1 = NULL ;
unsigned V_68 ;
T_1 V_37 = 0 ;
struct V_21 V_38 ;
unsigned long V_39 = 0 ;
V_38 . V_32 = 0 ;
V_38 . V_57 = 0 ;
for ( V_68 = 0 ; V_68 < V_36 ; V_68 ++ ) {
struct V_6 * V_6 = F_33 ( V_67 -> V_69 , struct V_6 , V_70 ) ;
F_34 ( & V_6 -> V_16 ) ;
F_35 ( & V_6 -> V_70 ) ;
if ( ! F_36 ( V_6 , V_25 ,
V_6 -> V_56 , V_64 ) ) {
V_1 = F_17 ( V_1 , V_6 ,
V_36 - V_68 ,
& V_37 , & V_38 ,
& V_39 ,
V_40 ) ;
}
F_37 ( V_6 ) ;
}
F_38 ( ! F_39 ( V_67 ) ) ;
if ( V_1 )
F_6 ( V_62 , V_1 ) ;
return 0 ;
}
int F_40 ( struct V_6 * V_6 , T_3 V_40 )
{
struct V_1 * V_1 = NULL ;
T_1 V_37 = 0 ;
struct V_21 V_38 ;
unsigned long V_39 = 0 ;
V_38 . V_32 = 0 ;
V_38 . V_57 = 0 ;
V_1 = F_17 ( V_1 , V_6 , 1 , & V_37 ,
& V_38 , & V_39 , V_40 ) ;
if ( V_1 )
F_6 ( V_62 , V_1 ) ;
return 0 ;
}
static void F_41 ( struct V_6 * V_6 , unsigned V_71 )
{
unsigned V_72 = 0 ;
struct V_21 * V_22 , * V_28 ;
if ( ! F_12 ( V_6 ) )
return;
V_28 = F_16 ( V_6 ) ;
V_22 = V_28 ;
do {
if ( V_72 ++ == V_71 )
break;
F_42 ( V_22 ) ;
V_22 = V_22 -> V_35 ;
} while ( V_22 != V_28 );
if ( V_73 && F_24 ( V_6 ) )
F_43 ( V_6 ) ;
}
static int F_44 ( struct V_6 * V_6 , struct V_74 * V_75 ,
void * V_76 )
{
struct V_77 * V_78 = V_76 ;
struct V_1 * V_1 = V_78 -> V_1 ;
struct V_65 * V_25 = V_6 -> V_25 ;
struct V_24 * V_24 = V_6 -> V_25 -> V_26 ;
const unsigned V_41 = V_24 -> V_30 ;
unsigned long V_79 ;
const unsigned V_42 = V_43 >> V_41 ;
T_1 V_46 ;
T_1 V_45 ;
T_1 V_48 [ V_49 ] ;
unsigned V_23 ;
unsigned V_71 = V_42 ;
struct V_10 * V_11 = NULL ;
int V_80 = 0 ;
T_1 V_81 = 0 ;
struct V_10 * V_82 = NULL ;
int V_51 ;
struct V_21 V_38 ;
T_4 V_83 = F_18 ( V_24 ) ;
int V_84 = 0 ;
if ( F_12 ( V_6 ) ) {
struct V_21 * V_28 = F_16 ( V_6 ) ;
struct V_21 * V_22 = V_28 ;
V_23 = 0 ;
do {
F_38 ( F_45 ( V_22 ) ) ;
if ( ! F_19 ( V_22 ) ) {
if ( F_46 ( V_22 ) )
goto V_55;
if ( V_71 == V_42 )
V_71 = V_23 ;
continue;
}
if ( V_71 != V_42 )
goto V_55;
if ( ! F_46 ( V_22 ) || ! F_13 ( V_22 ) )
goto V_55;
if ( V_23 ) {
if ( V_22 -> V_34 != V_48 [ V_23 - 1 ] + 1 )
goto V_55;
}
V_48 [ V_23 ++ ] = V_22 -> V_34 ;
V_80 = F_30 ( V_22 ) ;
if ( V_80 ) {
V_81 = V_22 -> V_34 ;
V_82 = V_22 -> V_33 ;
}
V_11 = V_22 -> V_33 ;
} while ( ( V_22 = V_22 -> V_35 ) != V_28 );
if ( V_71 )
goto V_85;
goto V_55;
}
F_38 ( ! F_24 ( V_6 ) ) ;
V_45 = ( T_1 ) V_6 -> V_56 << ( V_31 - V_41 ) ;
V_46 = ( V_83 - 1 ) >> V_41 ;
V_38 . V_60 = V_6 ;
for ( V_23 = 0 ; V_23 < V_42 ; ) {
V_38 . V_32 = 0 ;
V_38 . V_57 = 1 << V_41 ;
if ( V_78 -> V_40 ( V_24 , V_45 , & V_38 , 1 ) )
goto V_55;
if ( F_47 ( & V_38 ) )
F_48 ( V_38 . V_33 ,
V_38 . V_34 ) ;
if ( F_30 ( & V_38 ) ) {
V_81 = V_38 . V_34 ;
V_82 = V_38 . V_33 ;
}
if ( V_23 ) {
if ( V_38 . V_34 != V_48 [ V_23 - 1 ] + 1 )
goto V_55;
}
V_48 [ V_23 ++ ] = V_38 . V_34 ;
V_80 = F_30 ( & V_38 ) ;
V_11 = V_38 . V_33 ;
if ( V_45 == V_46 )
break;
V_45 ++ ;
}
F_38 ( V_23 == 0 ) ;
V_71 = V_23 ;
V_85:
V_79 = V_83 >> V_31 ;
if ( V_6 -> V_56 >= V_79 ) {
unsigned V_86 = V_83 & ( V_43 - 1 ) ;
if ( V_6 -> V_56 > V_79 || ! V_86 )
goto V_55;
F_21 ( V_6 , V_86 , V_43 ) ;
}
if ( V_1 && V_78 -> V_37 != V_48 [ 0 ] - 1 )
V_1 = F_6 ( V_87 , V_1 ) ;
V_63:
if ( V_1 == NULL ) {
if ( V_71 == V_42 ) {
if ( ! F_49 ( V_11 , V_48 [ 0 ] << ( V_41 - 9 ) ,
V_6 , V_75 ) ) {
F_41 ( V_6 , V_71 ) ;
goto V_61;
}
}
V_1 = F_9 ( V_11 , V_48 [ 0 ] << ( V_41 - 9 ) ,
F_28 ( V_11 ) , V_88 | V_89 ) ;
if ( V_1 == NULL )
goto V_55;
F_50 ( V_75 , V_1 ) ;
}
F_51 ( V_75 , V_6 , V_90 ) ;
V_51 = V_71 << V_41 ;
if ( F_29 ( V_1 , V_6 , V_51 , 0 ) < V_51 ) {
V_1 = F_6 ( V_87 , V_1 ) ;
goto V_63;
}
F_41 ( V_6 , V_71 ) ;
F_38 ( F_52 ( V_6 ) ) ;
F_53 ( V_6 ) ;
F_22 ( V_6 ) ;
if ( V_80 || ( V_71 != V_42 ) ) {
V_1 = F_6 ( V_87 , V_1 ) ;
if ( V_81 ) {
F_54 ( V_82 ,
V_81 , 1 << V_41 ) ;
}
} else {
V_78 -> V_37 = V_48 [ V_42 - 1 ] ;
}
goto V_61;
V_55:
if ( V_1 )
V_1 = F_6 ( V_87 , V_1 ) ;
if ( V_78 -> V_91 ) {
V_84 = V_25 -> V_92 -> V_93 ( V_6 , V_75 ) ;
} else {
V_84 = - V_94 ;
goto V_61;
}
F_55 ( V_25 , V_84 ) ;
V_61:
V_78 -> V_1 = V_1 ;
return V_84 ;
}
int
F_56 ( struct V_65 * V_25 ,
struct V_74 * V_75 , T_3 V_40 )
{
struct V_95 V_96 ;
int V_84 ;
F_57 ( & V_96 ) ;
if ( ! V_40 )
V_84 = F_58 ( V_25 , V_75 ) ;
else {
struct V_77 V_78 = {
. V_1 = NULL ,
. V_37 = 0 ,
. V_40 = V_40 ,
. V_91 = 1 ,
} ;
V_84 = F_59 ( V_25 , V_75 , F_44 , & V_78 ) ;
if ( V_78 . V_1 )
F_6 ( V_87 , V_78 . V_1 ) ;
}
F_60 ( & V_96 ) ;
return V_84 ;
}
int F_61 ( struct V_6 * V_6 , T_3 V_40 ,
struct V_74 * V_75 )
{
struct V_77 V_78 = {
. V_1 = NULL ,
. V_37 = 0 ,
. V_40 = V_40 ,
. V_91 = 0 ,
} ;
int V_84 = F_44 ( V_6 , V_75 , & V_78 ) ;
if ( V_78 . V_1 )
F_6 ( V_87 , V_78 . V_1 ) ;
return V_84 ;
}
