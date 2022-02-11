static void F_1 ( struct V_1 * V_1 , int V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
F_2 (bv, bio, i) {
struct V_6 * V_6 = V_4 -> V_7 ;
if ( F_3 ( V_1 ) == V_8 ) {
if ( ! V_2 ) {
F_4 ( V_6 ) ;
} else {
F_5 ( V_6 ) ;
F_6 ( V_6 ) ;
}
F_7 ( V_6 ) ;
} else {
if ( V_2 ) {
F_6 ( V_6 ) ;
if ( V_6 -> V_9 )
F_8 ( V_10 , & V_6 -> V_9 -> V_11 ) ;
}
F_9 ( V_6 ) ;
}
}
F_10 ( V_1 ) ;
}
static struct V_1 * F_11 ( int V_12 , struct V_1 * V_1 )
{
V_1 -> V_13 = F_1 ;
F_12 ( V_12 , V_1 ) ;
return NULL ;
}
static struct V_1 *
F_13 ( struct V_14 * V_15 ,
T_1 V_16 , int V_17 ,
T_2 V_18 )
{
struct V_1 * V_1 ;
V_1 = F_14 ( V_18 , V_17 ) ;
if ( V_1 == NULL && ( V_19 -> V_11 & V_20 ) ) {
while ( ! V_1 && ( V_17 /= 2 ) )
V_1 = F_14 ( V_18 , V_17 ) ;
}
if ( V_1 ) {
V_1 -> V_21 = V_15 ;
V_1 -> V_22 . V_23 = V_16 ;
}
return V_1 ;
}
static void
F_15 ( struct V_6 * V_6 , struct V_24 * V_25 , int V_26 )
{
struct V_27 * V_27 = V_6 -> V_9 -> V_28 ;
struct V_24 * V_29 , * V_30 ;
int V_31 = 0 ;
if ( ! F_16 ( V_6 ) ) {
if ( V_27 -> V_32 == V_33 &&
F_17 ( V_25 ) ) {
F_4 ( V_6 ) ;
return;
}
F_18 ( V_6 , 1 << V_27 -> V_32 , 0 ) ;
}
V_30 = F_19 ( V_6 ) ;
V_29 = V_30 ;
do {
if ( V_31 == V_26 ) {
V_29 -> V_34 = V_25 -> V_34 ;
V_29 -> V_35 = V_25 -> V_35 ;
V_29 -> V_36 = V_25 -> V_36 ;
break;
}
V_29 = V_29 -> V_37 ;
V_31 ++ ;
} while ( V_29 != V_30 );
}
static struct V_1 *
F_20 ( struct V_1 * V_1 , struct V_6 * V_6 , unsigned V_38 ,
T_1 * V_39 , struct V_24 * V_40 ,
unsigned long * V_41 , T_3 V_42 )
{
struct V_27 * V_27 = V_6 -> V_9 -> V_28 ;
const unsigned V_43 = V_27 -> V_32 ;
const unsigned V_44 = V_45 >> V_43 ;
const unsigned V_46 = 1 << V_43 ;
T_1 V_47 ;
T_1 V_48 ;
T_1 V_49 ;
T_1 V_50 [ V_51 ] ;
unsigned V_26 ;
unsigned V_52 = V_44 ;
struct V_14 * V_15 = NULL ;
int V_53 ;
int V_54 = 1 ;
unsigned V_55 ;
unsigned V_56 ;
if ( F_16 ( V_6 ) )
goto V_57;
V_47 = ( T_1 ) V_6 -> V_58 << ( V_33 - V_43 ) ;
V_48 = V_47 + V_38 * V_44 ;
V_49 = ( F_21 ( V_27 ) + V_46 - 1 ) >> V_43 ;
if ( V_48 > V_49 )
V_48 = V_49 ;
V_26 = 0 ;
V_55 = V_40 -> V_59 >> V_43 ;
if ( F_22 ( V_40 ) && V_47 > * V_41 &&
V_47 < ( * V_41 + V_55 ) ) {
unsigned V_60 = V_47 - * V_41 ;
unsigned V_61 = V_55 - V_60 ;
for ( V_56 = 0 ; ; V_56 ++ ) {
if ( V_56 == V_61 ) {
F_23 ( V_40 ) ;
break;
}
if ( V_26 == V_44 )
break;
V_50 [ V_26 ] = V_40 -> V_36 + V_60 +
V_56 ;
V_26 ++ ;
V_47 ++ ;
}
V_15 = V_40 -> V_35 ;
}
V_40 -> V_62 = V_6 ;
while ( V_26 < V_44 ) {
V_40 -> V_34 = 0 ;
V_40 -> V_59 = 0 ;
if ( V_47 < V_48 ) {
V_40 -> V_59 = ( V_48 - V_47 ) << V_43 ;
if ( V_42 ( V_27 , V_47 , V_40 , 0 ) )
goto V_57;
* V_41 = V_47 ;
}
if ( ! F_22 ( V_40 ) ) {
V_54 = 0 ;
if ( V_52 == V_44 )
V_52 = V_26 ;
V_26 ++ ;
V_47 ++ ;
continue;
}
if ( F_17 ( V_40 ) ) {
F_15 ( V_6 , V_40 , V_26 ) ;
goto V_57;
}
if ( V_52 != V_44 )
goto V_57;
if ( V_26 && V_50 [ V_26 - 1 ] != V_40 -> V_36 - 1 )
goto V_57;
V_55 = V_40 -> V_59 >> V_43 ;
for ( V_56 = 0 ; ; V_56 ++ ) {
if ( V_56 == V_55 ) {
F_23 ( V_40 ) ;
break;
} else if ( V_26 == V_44 )
break;
V_50 [ V_26 ] = V_40 -> V_36 + V_56 ;
V_26 ++ ;
V_47 ++ ;
}
V_15 = V_40 -> V_35 ;
}
if ( V_52 != V_44 ) {
F_24 ( V_6 , V_52 << V_43 , V_45 ) ;
if ( V_52 == 0 ) {
F_4 ( V_6 ) ;
F_7 ( V_6 ) ;
goto V_63;
}
} else if ( V_54 ) {
F_25 ( V_6 ) ;
}
if ( V_54 && V_44 == 1 && ! F_26 ( V_6 ) &&
F_27 ( V_6 ) == 0 ) {
F_4 ( V_6 ) ;
goto V_57;
}
if ( V_1 && ( * V_39 != V_50 [ 0 ] - 1 ) )
V_1 = F_11 ( V_8 , V_1 ) ;
V_64:
if ( V_1 == NULL ) {
V_1 = F_13 ( V_15 , V_50 [ 0 ] << ( V_43 - 9 ) ,
F_28 ( int , V_38 , F_29 ( V_15 ) ) ,
V_65 ) ;
if ( V_1 == NULL )
goto V_57;
}
V_53 = V_52 << V_43 ;
if ( F_30 ( V_1 , V_6 , V_53 , 0 ) < V_53 ) {
V_1 = F_11 ( V_8 , V_1 ) ;
goto V_64;
}
V_56 = V_47 - * V_41 ;
V_55 = V_40 -> V_59 >> V_43 ;
if ( ( F_31 ( V_40 ) && V_56 == V_55 ) ||
( V_52 != V_44 ) )
V_1 = F_11 ( V_8 , V_1 ) ;
else
* V_39 = V_50 [ V_44 - 1 ] ;
V_63:
return V_1 ;
V_57:
if ( V_1 )
V_1 = F_11 ( V_8 , V_1 ) ;
if ( ! F_26 ( V_6 ) )
F_32 ( V_6 , V_42 ) ;
else
F_7 ( V_6 ) ;
goto V_63;
}
int
F_33 ( struct V_66 * V_9 , struct V_67 * V_68 ,
unsigned V_38 , T_3 V_42 )
{
struct V_1 * V_1 = NULL ;
unsigned V_69 ;
T_1 V_39 = 0 ;
struct V_24 V_40 ;
unsigned long V_41 = 0 ;
V_40 . V_34 = 0 ;
V_40 . V_59 = 0 ;
for ( V_69 = 0 ; V_69 < V_38 ; V_69 ++ ) {
struct V_6 * V_6 = F_34 ( V_68 -> V_70 , struct V_6 , V_71 ) ;
F_35 ( & V_6 -> V_11 ) ;
F_36 ( & V_6 -> V_71 ) ;
if ( ! F_37 ( V_6 , V_9 ,
V_6 -> V_58 , V_65 ) ) {
V_1 = F_20 ( V_1 , V_6 ,
V_38 - V_69 ,
& V_39 , & V_40 ,
& V_41 ,
V_42 ) ;
}
F_38 ( V_6 ) ;
}
F_39 ( ! F_40 ( V_68 ) ) ;
if ( V_1 )
F_11 ( V_8 , V_1 ) ;
return 0 ;
}
int F_41 ( struct V_6 * V_6 , T_3 V_42 )
{
struct V_1 * V_1 = NULL ;
T_1 V_39 = 0 ;
struct V_24 V_40 ;
unsigned long V_41 = 0 ;
V_40 . V_34 = 0 ;
V_40 . V_59 = 0 ;
V_1 = F_20 ( V_1 , V_6 , 1 , & V_39 ,
& V_40 , & V_41 , V_42 ) ;
if ( V_1 )
F_11 ( V_8 , V_1 ) ;
return 0 ;
}
static int F_42 ( struct V_6 * V_6 , struct V_72 * V_73 ,
void * V_74 )
{
struct V_75 * V_76 = V_74 ;
struct V_1 * V_1 = V_76 -> V_1 ;
struct V_66 * V_9 = V_6 -> V_9 ;
struct V_27 * V_27 = V_6 -> V_9 -> V_28 ;
const unsigned V_43 = V_27 -> V_32 ;
unsigned long V_77 ;
const unsigned V_44 = V_45 >> V_43 ;
T_1 V_48 ;
T_1 V_47 ;
T_1 V_50 [ V_51 ] ;
unsigned V_26 ;
unsigned V_78 = V_44 ;
struct V_14 * V_15 = NULL ;
int V_79 = 0 ;
T_1 V_80 = 0 ;
struct V_14 * V_81 = NULL ;
int V_53 ;
struct V_24 V_40 ;
T_4 V_82 = F_21 ( V_27 ) ;
int V_83 = 0 ;
if ( F_16 ( V_6 ) ) {
struct V_24 * V_30 = F_19 ( V_6 ) ;
struct V_24 * V_25 = V_30 ;
V_26 = 0 ;
do {
F_39 ( F_43 ( V_25 ) ) ;
if ( ! F_22 ( V_25 ) ) {
if ( F_44 ( V_25 ) )
goto V_57;
if ( V_78 == V_44 )
V_78 = V_26 ;
continue;
}
if ( V_78 != V_44 )
goto V_57;
if ( ! F_44 ( V_25 ) || ! F_17 ( V_25 ) )
goto V_57;
if ( V_26 ) {
if ( V_25 -> V_36 != V_50 [ V_26 - 1 ] + 1 )
goto V_57;
}
V_50 [ V_26 ++ ] = V_25 -> V_36 ;
V_79 = F_31 ( V_25 ) ;
if ( V_79 ) {
V_80 = V_25 -> V_36 ;
V_81 = V_25 -> V_35 ;
}
V_15 = V_25 -> V_35 ;
} while ( ( V_25 = V_25 -> V_37 ) != V_30 );
if ( V_78 )
goto V_84;
goto V_57;
}
F_39 ( ! F_26 ( V_6 ) ) ;
V_47 = ( T_1 ) V_6 -> V_58 << ( V_33 - V_43 ) ;
V_48 = ( V_82 - 1 ) >> V_43 ;
V_40 . V_62 = V_6 ;
for ( V_26 = 0 ; V_26 < V_44 ; ) {
V_40 . V_34 = 0 ;
V_40 . V_59 = 1 << V_43 ;
if ( V_76 -> V_42 ( V_27 , V_47 , & V_40 , 1 ) )
goto V_57;
if ( F_45 ( & V_40 ) )
F_46 ( V_40 . V_35 ,
V_40 . V_36 ) ;
if ( F_31 ( & V_40 ) ) {
V_80 = V_40 . V_36 ;
V_81 = V_40 . V_35 ;
}
if ( V_26 ) {
if ( V_40 . V_36 != V_50 [ V_26 - 1 ] + 1 )
goto V_57;
}
V_50 [ V_26 ++ ] = V_40 . V_36 ;
V_79 = F_31 ( & V_40 ) ;
V_15 = V_40 . V_35 ;
if ( V_47 == V_48 )
break;
V_47 ++ ;
}
F_39 ( V_26 == 0 ) ;
V_78 = V_26 ;
V_84:
V_77 = V_82 >> V_33 ;
if ( V_6 -> V_58 >= V_77 ) {
unsigned V_85 = V_82 & ( V_45 - 1 ) ;
if ( V_6 -> V_58 > V_77 || ! V_85 )
goto V_57;
F_24 ( V_6 , V_85 , V_45 ) ;
}
if ( V_1 && V_76 -> V_39 != V_50 [ 0 ] - 1 )
V_1 = F_11 ( V_86 , V_1 ) ;
V_64:
if ( V_1 == NULL ) {
V_1 = F_13 ( V_15 , V_50 [ 0 ] << ( V_43 - 9 ) ,
F_29 ( V_15 ) , V_87 | V_88 ) ;
if ( V_1 == NULL )
goto V_57;
}
V_53 = V_78 << V_43 ;
if ( F_30 ( V_1 , V_6 , V_53 , 0 ) < V_53 ) {
V_1 = F_11 ( V_86 , V_1 ) ;
goto V_64;
}
if ( F_16 ( V_6 ) ) {
struct V_24 * V_30 = F_19 ( V_6 ) ;
struct V_24 * V_25 = V_30 ;
unsigned V_89 = 0 ;
do {
if ( V_89 ++ == V_78 )
break;
F_47 ( V_25 ) ;
V_25 = V_25 -> V_37 ;
} while ( V_25 != V_30 );
if ( V_90 && F_26 ( V_6 ) )
F_48 ( V_6 ) ;
}
F_39 ( F_49 ( V_6 ) ) ;
F_50 ( V_6 ) ;
F_7 ( V_6 ) ;
if ( V_79 || ( V_78 != V_44 ) ) {
V_1 = F_11 ( V_86 , V_1 ) ;
if ( V_80 ) {
F_51 ( V_81 ,
V_80 , 1 << V_43 ) ;
}
} else {
V_76 -> V_39 = V_50 [ V_44 - 1 ] ;
}
goto V_63;
V_57:
if ( V_1 )
V_1 = F_11 ( V_86 , V_1 ) ;
if ( V_76 -> V_91 ) {
V_83 = V_9 -> V_92 -> V_93 ( V_6 , V_73 ) ;
} else {
V_83 = - V_94 ;
goto V_63;
}
F_52 ( V_9 , V_83 ) ;
V_63:
V_76 -> V_1 = V_1 ;
return V_83 ;
}
int
F_53 ( struct V_66 * V_9 ,
struct V_72 * V_73 , T_3 V_42 )
{
struct V_95 V_96 ;
int V_83 ;
F_54 ( & V_96 ) ;
if ( ! V_42 )
V_83 = F_55 ( V_9 , V_73 ) ;
else {
struct V_75 V_76 = {
. V_1 = NULL ,
. V_39 = 0 ,
. V_42 = V_42 ,
. V_91 = 1 ,
} ;
V_83 = F_56 ( V_9 , V_73 , F_42 , & V_76 ) ;
if ( V_76 . V_1 )
F_11 ( V_86 , V_76 . V_1 ) ;
}
F_57 ( & V_96 ) ;
return V_83 ;
}
int F_58 ( struct V_6 * V_6 , T_3 V_42 ,
struct V_72 * V_73 )
{
struct V_75 V_76 = {
. V_1 = NULL ,
. V_39 = 0 ,
. V_42 = V_42 ,
. V_91 = 0 ,
} ;
int V_83 = F_42 ( V_6 , V_73 , & V_76 ) ;
if ( V_76 . V_1 )
F_11 ( V_86 , V_76 . V_1 ) ;
return V_83 ;
}
