static void F_1 ( struct V_1 * V_1 , int V_2 )
{
const int V_3 = F_2 ( V_4 , & V_1 -> V_5 ) ;
struct V_6 * V_7 = V_1 -> V_8 + V_1 -> V_9 - 1 ;
do {
struct V_10 * V_10 = V_7 -> V_11 ;
if ( -- V_7 >= V_1 -> V_8 )
F_3 ( & V_7 -> V_11 -> V_12 ) ;
if ( F_4 ( V_1 ) == V_13 ) {
if ( V_3 ) {
F_5 ( V_10 ) ;
} else {
F_6 ( V_10 ) ;
F_7 ( V_10 ) ;
}
F_8 ( V_10 ) ;
} else {
if ( ! V_3 ) {
F_7 ( V_10 ) ;
if ( V_10 -> V_14 )
F_9 ( V_15 , & V_10 -> V_14 -> V_12 ) ;
}
F_10 ( V_10 ) ;
}
} while ( V_7 >= V_1 -> V_8 );
F_11 ( V_1 ) ;
}
static struct V_1 * F_12 ( int V_16 , struct V_1 * V_1 )
{
V_1 -> V_17 = F_1 ;
F_13 ( V_16 , V_1 ) ;
return NULL ;
}
static struct V_1 *
F_14 ( struct V_18 * V_19 ,
T_1 V_20 , int V_21 ,
T_2 V_22 )
{
struct V_1 * V_1 ;
V_1 = F_15 ( V_22 , V_21 ) ;
if ( V_1 == NULL && ( V_23 -> V_12 & V_24 ) ) {
while ( ! V_1 && ( V_21 /= 2 ) )
V_1 = F_15 ( V_22 , V_21 ) ;
}
if ( V_1 ) {
V_1 -> V_25 = V_19 ;
V_1 -> V_26 = V_20 ;
}
return V_1 ;
}
static void
F_16 ( struct V_10 * V_10 , struct V_27 * V_28 , int V_29 )
{
struct V_30 * V_30 = V_10 -> V_14 -> V_31 ;
struct V_27 * V_32 , * V_33 ;
int V_34 = 0 ;
if ( ! F_17 ( V_10 ) ) {
if ( V_30 -> V_35 == V_36 &&
F_18 ( V_28 ) ) {
F_5 ( V_10 ) ;
return;
}
F_19 ( V_10 , 1 << V_30 -> V_35 , 0 ) ;
}
V_33 = F_20 ( V_10 ) ;
V_32 = V_33 ;
do {
if ( V_34 == V_29 ) {
V_32 -> V_37 = V_28 -> V_37 ;
V_32 -> V_38 = V_28 -> V_38 ;
V_32 -> V_39 = V_28 -> V_39 ;
break;
}
V_32 = V_32 -> V_40 ;
V_34 ++ ;
} while ( V_32 != V_33 );
}
static struct V_1 *
F_21 ( struct V_1 * V_1 , struct V_10 * V_10 , unsigned V_41 ,
T_1 * V_42 , struct V_27 * V_43 ,
unsigned long * V_44 , T_3 V_45 )
{
struct V_30 * V_30 = V_10 -> V_14 -> V_31 ;
const unsigned V_46 = V_30 -> V_35 ;
const unsigned V_47 = V_48 >> V_46 ;
const unsigned V_49 = 1 << V_46 ;
T_1 V_50 ;
T_1 V_51 ;
T_1 V_52 ;
T_1 V_53 [ V_54 ] ;
unsigned V_29 ;
unsigned V_55 = V_47 ;
struct V_18 * V_19 = NULL ;
int V_56 ;
int V_57 = 1 ;
unsigned V_58 ;
unsigned V_59 ;
if ( F_17 ( V_10 ) )
goto V_60;
V_50 = ( T_1 ) V_10 -> V_61 << ( V_36 - V_46 ) ;
V_51 = V_50 + V_41 * V_47 ;
V_52 = ( F_22 ( V_30 ) + V_49 - 1 ) >> V_46 ;
if ( V_51 > V_52 )
V_51 = V_52 ;
V_29 = 0 ;
V_58 = V_43 -> V_62 >> V_46 ;
if ( F_23 ( V_43 ) && V_50 > * V_44 &&
V_50 < ( * V_44 + V_58 ) ) {
unsigned V_63 = V_50 - * V_44 ;
unsigned V_64 = V_58 - V_63 ;
for ( V_59 = 0 ; ; V_59 ++ ) {
if ( V_59 == V_64 ) {
F_24 ( V_43 ) ;
break;
}
if ( V_29 == V_47 )
break;
V_53 [ V_29 ] = V_43 -> V_39 + V_63 +
V_59 ;
V_29 ++ ;
V_50 ++ ;
}
V_19 = V_43 -> V_38 ;
}
V_43 -> V_65 = V_10 ;
while ( V_29 < V_47 ) {
V_43 -> V_37 = 0 ;
V_43 -> V_62 = 0 ;
if ( V_50 < V_51 ) {
V_43 -> V_62 = ( V_51 - V_50 ) << V_46 ;
if ( V_45 ( V_30 , V_50 , V_43 , 0 ) )
goto V_60;
* V_44 = V_50 ;
}
if ( ! F_23 ( V_43 ) ) {
V_57 = 0 ;
if ( V_55 == V_47 )
V_55 = V_29 ;
V_29 ++ ;
V_50 ++ ;
continue;
}
if ( F_18 ( V_43 ) ) {
F_16 ( V_10 , V_43 , V_29 ) ;
goto V_60;
}
if ( V_55 != V_47 )
goto V_60;
if ( V_29 && V_53 [ V_29 - 1 ] != V_43 -> V_39 - 1 )
goto V_60;
V_58 = V_43 -> V_62 >> V_46 ;
for ( V_59 = 0 ; ; V_59 ++ ) {
if ( V_59 == V_58 ) {
F_24 ( V_43 ) ;
break;
} else if ( V_29 == V_47 )
break;
V_53 [ V_29 ] = V_43 -> V_39 + V_59 ;
V_29 ++ ;
V_50 ++ ;
}
V_19 = V_43 -> V_38 ;
}
if ( V_55 != V_47 ) {
F_25 ( V_10 , V_55 << V_46 , V_48 ) ;
if ( V_55 == 0 ) {
F_5 ( V_10 ) ;
F_8 ( V_10 ) ;
goto V_66;
}
} else if ( V_57 ) {
F_26 ( V_10 ) ;
}
if ( V_57 && V_47 == 1 && ! F_27 ( V_10 ) &&
F_28 ( V_10 ) == 0 ) {
F_5 ( V_10 ) ;
goto V_60;
}
if ( V_1 && ( * V_42 != V_53 [ 0 ] - 1 ) )
V_1 = F_12 ( V_13 , V_1 ) ;
V_67:
if ( V_1 == NULL ) {
V_1 = F_14 ( V_19 , V_53 [ 0 ] << ( V_46 - 9 ) ,
F_29 ( int , V_41 , F_30 ( V_19 ) ) ,
V_68 ) ;
if ( V_1 == NULL )
goto V_60;
}
V_56 = V_55 << V_46 ;
if ( F_31 ( V_1 , V_10 , V_56 , 0 ) < V_56 ) {
V_1 = F_12 ( V_13 , V_1 ) ;
goto V_67;
}
V_59 = V_50 - * V_44 ;
V_58 = V_43 -> V_62 >> V_46 ;
if ( ( F_32 ( V_43 ) && V_59 == V_58 ) ||
( V_55 != V_47 ) )
V_1 = F_12 ( V_13 , V_1 ) ;
else
* V_42 = V_53 [ V_47 - 1 ] ;
V_66:
return V_1 ;
V_60:
if ( V_1 )
V_1 = F_12 ( V_13 , V_1 ) ;
if ( ! F_27 ( V_10 ) )
F_33 ( V_10 , V_45 ) ;
else
F_8 ( V_10 ) ;
goto V_66;
}
int
F_34 ( struct V_69 * V_14 , struct V_70 * V_71 ,
unsigned V_41 , T_3 V_45 )
{
struct V_1 * V_1 = NULL ;
unsigned V_72 ;
T_1 V_42 = 0 ;
struct V_27 V_43 ;
unsigned long V_44 = 0 ;
V_43 . V_37 = 0 ;
V_43 . V_62 = 0 ;
for ( V_72 = 0 ; V_72 < V_41 ; V_72 ++ ) {
struct V_10 * V_10 = F_35 ( V_71 -> V_73 , struct V_10 , V_74 ) ;
F_3 ( & V_10 -> V_12 ) ;
F_36 ( & V_10 -> V_74 ) ;
if ( ! F_37 ( V_10 , V_14 ,
V_10 -> V_61 , V_68 ) ) {
V_1 = F_21 ( V_1 , V_10 ,
V_41 - V_72 ,
& V_42 , & V_43 ,
& V_44 ,
V_45 ) ;
}
F_38 ( V_10 ) ;
}
F_39 ( ! F_40 ( V_71 ) ) ;
if ( V_1 )
F_12 ( V_13 , V_1 ) ;
return 0 ;
}
int F_41 ( struct V_10 * V_10 , T_3 V_45 )
{
struct V_1 * V_1 = NULL ;
T_1 V_42 = 0 ;
struct V_27 V_43 ;
unsigned long V_44 = 0 ;
V_43 . V_37 = 0 ;
V_43 . V_62 = 0 ;
V_1 = F_21 ( V_1 , V_10 , 1 , & V_42 ,
& V_43 , & V_44 , V_45 ) ;
if ( V_1 )
F_12 ( V_13 , V_1 ) ;
return 0 ;
}
static int F_42 ( struct V_10 * V_10 , struct V_75 * V_76 ,
void * V_77 )
{
struct V_78 * V_79 = V_77 ;
struct V_1 * V_1 = V_79 -> V_1 ;
struct V_69 * V_14 = V_10 -> V_14 ;
struct V_30 * V_30 = V_10 -> V_14 -> V_31 ;
const unsigned V_46 = V_30 -> V_35 ;
unsigned long V_80 ;
const unsigned V_47 = V_48 >> V_46 ;
T_1 V_51 ;
T_1 V_50 ;
T_1 V_53 [ V_54 ] ;
unsigned V_29 ;
unsigned V_81 = V_47 ;
struct V_18 * V_19 = NULL ;
int V_82 = 0 ;
T_1 V_83 = 0 ;
struct V_18 * V_84 = NULL ;
int V_56 ;
struct V_27 V_43 ;
T_4 V_85 = F_22 ( V_30 ) ;
int V_86 = 0 ;
if ( F_17 ( V_10 ) ) {
struct V_27 * V_33 = F_20 ( V_10 ) ;
struct V_27 * V_28 = V_33 ;
V_29 = 0 ;
do {
F_39 ( F_43 ( V_28 ) ) ;
if ( ! F_23 ( V_28 ) ) {
if ( F_44 ( V_28 ) )
goto V_60;
if ( V_81 == V_47 )
V_81 = V_29 ;
continue;
}
if ( V_81 != V_47 )
goto V_60;
if ( ! F_44 ( V_28 ) || ! F_18 ( V_28 ) )
goto V_60;
if ( V_29 ) {
if ( V_28 -> V_39 != V_53 [ V_29 - 1 ] + 1 )
goto V_60;
}
V_53 [ V_29 ++ ] = V_28 -> V_39 ;
V_82 = F_32 ( V_28 ) ;
if ( V_82 ) {
V_83 = V_28 -> V_39 ;
V_84 = V_28 -> V_38 ;
}
V_19 = V_28 -> V_38 ;
} while ( ( V_28 = V_28 -> V_40 ) != V_33 );
if ( V_81 )
goto V_87;
goto V_60;
}
F_39 ( ! F_27 ( V_10 ) ) ;
V_50 = ( T_1 ) V_10 -> V_61 << ( V_36 - V_46 ) ;
V_51 = ( V_85 - 1 ) >> V_46 ;
V_43 . V_65 = V_10 ;
for ( V_29 = 0 ; V_29 < V_47 ; ) {
V_43 . V_37 = 0 ;
V_43 . V_62 = 1 << V_46 ;
if ( V_79 -> V_45 ( V_30 , V_50 , & V_43 , 1 ) )
goto V_60;
if ( F_45 ( & V_43 ) )
F_46 ( V_43 . V_38 ,
V_43 . V_39 ) ;
if ( F_32 ( & V_43 ) ) {
V_83 = V_43 . V_39 ;
V_84 = V_43 . V_38 ;
}
if ( V_29 ) {
if ( V_43 . V_39 != V_53 [ V_29 - 1 ] + 1 )
goto V_60;
}
V_53 [ V_29 ++ ] = V_43 . V_39 ;
V_82 = F_32 ( & V_43 ) ;
V_19 = V_43 . V_38 ;
if ( V_50 == V_51 )
break;
V_50 ++ ;
}
F_39 ( V_29 == 0 ) ;
V_81 = V_29 ;
V_87:
V_80 = V_85 >> V_36 ;
if ( V_10 -> V_61 >= V_80 ) {
unsigned V_88 = V_85 & ( V_48 - 1 ) ;
if ( V_10 -> V_61 > V_80 || ! V_88 )
goto V_60;
F_25 ( V_10 , V_88 , V_48 ) ;
}
if ( V_1 && V_79 -> V_42 != V_53 [ 0 ] - 1 )
V_1 = F_12 ( V_89 , V_1 ) ;
V_67:
if ( V_1 == NULL ) {
V_1 = F_14 ( V_19 , V_53 [ 0 ] << ( V_46 - 9 ) ,
F_30 ( V_19 ) , V_90 | V_91 ) ;
if ( V_1 == NULL )
goto V_60;
}
V_56 = V_81 << V_46 ;
if ( F_31 ( V_1 , V_10 , V_56 , 0 ) < V_56 ) {
V_1 = F_12 ( V_89 , V_1 ) ;
goto V_67;
}
if ( F_17 ( V_10 ) ) {
struct V_27 * V_33 = F_20 ( V_10 ) ;
struct V_27 * V_28 = V_33 ;
unsigned V_92 = 0 ;
do {
if ( V_92 ++ == V_81 )
break;
F_47 ( V_28 ) ;
V_28 = V_28 -> V_40 ;
} while ( V_28 != V_33 );
if ( V_93 && F_27 ( V_10 ) )
F_48 ( V_10 ) ;
}
F_39 ( F_49 ( V_10 ) ) ;
F_50 ( V_10 ) ;
F_8 ( V_10 ) ;
if ( V_82 || ( V_81 != V_47 ) ) {
V_1 = F_12 ( V_89 , V_1 ) ;
if ( V_83 ) {
F_51 ( V_84 ,
V_83 , 1 << V_46 ) ;
}
} else {
V_79 -> V_42 = V_53 [ V_47 - 1 ] ;
}
goto V_66;
V_60:
if ( V_1 )
V_1 = F_12 ( V_89 , V_1 ) ;
if ( V_79 -> V_94 ) {
V_86 = V_14 -> V_95 -> V_96 ( V_10 , V_76 ) ;
} else {
V_86 = - V_97 ;
goto V_66;
}
F_52 ( V_14 , V_86 ) ;
V_66:
V_79 -> V_1 = V_1 ;
return V_86 ;
}
int
F_53 ( struct V_69 * V_14 ,
struct V_75 * V_76 , T_3 V_45 )
{
struct V_98 V_99 ;
int V_86 ;
F_54 ( & V_99 ) ;
if ( ! V_45 )
V_86 = F_55 ( V_14 , V_76 ) ;
else {
struct V_78 V_79 = {
. V_1 = NULL ,
. V_42 = 0 ,
. V_45 = V_45 ,
. V_94 = 1 ,
} ;
V_86 = F_56 ( V_14 , V_76 , F_42 , & V_79 ) ;
if ( V_79 . V_1 )
F_12 ( V_89 , V_79 . V_1 ) ;
}
F_57 ( & V_99 ) ;
return V_86 ;
}
int F_58 ( struct V_10 * V_10 , T_3 V_45 ,
struct V_75 * V_76 )
{
struct V_78 V_79 = {
. V_1 = NULL ,
. V_42 = 0 ,
. V_45 = V_45 ,
. V_94 = 0 ,
} ;
int V_86 = F_42 ( V_10 , V_76 , & V_79 ) ;
if ( V_79 . V_1 )
F_12 ( V_89 , V_79 . V_1 ) ;
return V_86 ;
}
