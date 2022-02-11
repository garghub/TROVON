static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
int V_4 ;
F_2 (bv, bio, i) {
struct V_5 * V_5 = V_3 -> V_6 ;
F_3 ( V_5 , F_4 ( V_1 ) , V_1 -> V_7 ) ;
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
F_11 ( struct V_5 * V_5 , struct V_21 * V_22 , int V_23 )
{
struct V_24 * V_24 = V_5 -> V_25 -> V_26 ;
struct V_21 * V_27 , * V_28 ;
int V_29 = 0 ;
if ( ! F_12 ( V_5 ) ) {
if ( V_24 -> V_30 == V_31 &&
F_13 ( V_22 ) ) {
F_14 ( V_5 ) ;
return;
}
F_15 ( V_5 , 1 << V_24 -> V_30 , 0 ) ;
}
V_28 = F_16 ( V_5 ) ;
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
F_17 ( struct V_1 * V_1 , struct V_5 * V_5 , unsigned V_36 ,
T_1 * V_37 , struct V_21 * V_38 ,
unsigned long * V_39 , T_3 V_40 ,
T_2 V_41 )
{
struct V_24 * V_24 = V_5 -> V_25 -> V_26 ;
const unsigned V_42 = V_24 -> V_30 ;
const unsigned V_43 = V_44 >> V_42 ;
const unsigned V_45 = 1 << V_42 ;
T_1 V_46 ;
T_1 V_47 ;
T_1 V_48 ;
T_1 V_49 [ V_50 ] ;
unsigned V_23 ;
unsigned V_51 = V_43 ;
struct V_10 * V_11 = NULL ;
int V_52 ;
int V_53 = 1 ;
unsigned V_54 ;
unsigned V_55 ;
if ( F_12 ( V_5 ) )
goto V_56;
V_46 = ( T_1 ) V_5 -> V_57 << ( V_31 - V_42 ) ;
V_47 = V_46 + V_36 * V_43 ;
V_48 = ( F_18 ( V_24 ) + V_45 - 1 ) >> V_42 ;
if ( V_47 > V_48 )
V_47 = V_48 ;
V_23 = 0 ;
V_54 = V_38 -> V_58 >> V_42 ;
if ( F_19 ( V_38 ) && V_46 > * V_39 &&
V_46 < ( * V_39 + V_54 ) ) {
unsigned V_59 = V_46 - * V_39 ;
unsigned V_60 = V_54 - V_59 ;
for ( V_55 = 0 ; ; V_55 ++ ) {
if ( V_55 == V_60 ) {
F_20 ( V_38 ) ;
break;
}
if ( V_23 == V_43 )
break;
V_49 [ V_23 ] = V_38 -> V_34 + V_59 +
V_55 ;
V_23 ++ ;
V_46 ++ ;
}
V_11 = V_38 -> V_33 ;
}
V_38 -> V_61 = V_5 ;
while ( V_23 < V_43 ) {
V_38 -> V_32 = 0 ;
V_38 -> V_58 = 0 ;
if ( V_46 < V_47 ) {
V_38 -> V_58 = ( V_47 - V_46 ) << V_42 ;
if ( V_40 ( V_24 , V_46 , V_38 , 0 ) )
goto V_56;
* V_39 = V_46 ;
}
if ( ! F_19 ( V_38 ) ) {
V_53 = 0 ;
if ( V_51 == V_43 )
V_51 = V_23 ;
V_23 ++ ;
V_46 ++ ;
continue;
}
if ( F_13 ( V_38 ) ) {
F_11 ( V_5 , V_38 , V_23 ) ;
goto V_56;
}
if ( V_51 != V_43 )
goto V_56;
if ( V_23 && V_49 [ V_23 - 1 ] != V_38 -> V_34 - 1 )
goto V_56;
V_54 = V_38 -> V_58 >> V_42 ;
for ( V_55 = 0 ; ; V_55 ++ ) {
if ( V_55 == V_54 ) {
F_20 ( V_38 ) ;
break;
} else if ( V_23 == V_43 )
break;
V_49 [ V_23 ] = V_38 -> V_34 + V_55 ;
V_23 ++ ;
V_46 ++ ;
}
V_11 = V_38 -> V_33 ;
}
if ( V_51 != V_43 ) {
F_21 ( V_5 , V_51 << V_42 , V_44 ) ;
if ( V_51 == 0 ) {
F_14 ( V_5 ) ;
F_22 ( V_5 ) ;
goto V_62;
}
} else if ( V_53 ) {
F_23 ( V_5 ) ;
}
if ( V_53 && V_43 == 1 && ! F_24 ( V_5 ) &&
F_25 ( V_5 ) == 0 ) {
F_14 ( V_5 ) ;
goto V_56;
}
if ( V_1 && ( * V_37 != V_49 [ 0 ] - 1 ) )
V_1 = F_6 ( V_63 , V_1 ) ;
V_64:
if ( V_1 == NULL ) {
if ( V_51 == V_43 ) {
if ( ! F_26 ( V_11 , V_49 [ 0 ] << ( V_42 - 9 ) ,
V_5 ) )
goto V_62;
}
V_1 = F_9 ( V_11 , V_49 [ 0 ] << ( V_42 - 9 ) ,
F_27 ( int , V_36 , V_65 ) , V_41 ) ;
if ( V_1 == NULL )
goto V_56;
}
V_52 = V_51 << V_42 ;
if ( F_28 ( V_1 , V_5 , V_52 , 0 ) < V_52 ) {
V_1 = F_6 ( V_63 , V_1 ) ;
goto V_64;
}
V_55 = V_46 - * V_39 ;
V_54 = V_38 -> V_58 >> V_42 ;
if ( ( F_29 ( V_38 ) && V_55 == V_54 ) ||
( V_51 != V_43 ) )
V_1 = F_6 ( V_63 , V_1 ) ;
else
* V_37 = V_49 [ V_43 - 1 ] ;
V_62:
return V_1 ;
V_56:
if ( V_1 )
V_1 = F_6 ( V_63 , V_1 ) ;
if ( ! F_24 ( V_5 ) )
F_30 ( V_5 , V_40 ) ;
else
F_22 ( V_5 ) ;
goto V_62;
}
int
F_31 ( struct V_66 * V_25 , struct V_67 * V_68 ,
unsigned V_36 , T_3 V_40 )
{
struct V_1 * V_1 = NULL ;
unsigned V_69 ;
T_1 V_37 = 0 ;
struct V_21 V_38 ;
unsigned long V_39 = 0 ;
T_2 V_41 = F_32 ( V_25 , V_70 ) ;
V_38 . V_32 = 0 ;
V_38 . V_58 = 0 ;
for ( V_69 = 0 ; V_69 < V_36 ; V_69 ++ ) {
struct V_5 * V_5 = F_33 ( V_68 -> V_71 , struct V_5 , V_72 ) ;
F_34 ( & V_5 -> V_16 ) ;
F_35 ( & V_5 -> V_72 ) ;
if ( ! F_36 ( V_5 , V_25 ,
V_5 -> V_57 ,
V_41 ) ) {
V_1 = F_17 ( V_1 , V_5 ,
V_36 - V_69 ,
& V_37 , & V_38 ,
& V_39 ,
V_40 , V_41 ) ;
}
F_37 ( V_5 ) ;
}
F_38 ( ! F_39 ( V_68 ) ) ;
if ( V_1 )
F_6 ( V_63 , V_1 ) ;
return 0 ;
}
int F_40 ( struct V_5 * V_5 , T_3 V_40 )
{
struct V_1 * V_1 = NULL ;
T_1 V_37 = 0 ;
struct V_21 V_38 ;
unsigned long V_39 = 0 ;
T_2 V_41 = F_32 ( V_5 -> V_25 , V_70 ) ;
V_38 . V_32 = 0 ;
V_38 . V_58 = 0 ;
V_1 = F_17 ( V_1 , V_5 , 1 , & V_37 ,
& V_38 , & V_39 , V_40 , V_41 ) ;
if ( V_1 )
F_6 ( V_63 , V_1 ) ;
return 0 ;
}
static void F_41 ( struct V_5 * V_5 , unsigned V_73 )
{
unsigned V_74 = 0 ;
struct V_21 * V_22 , * V_28 ;
if ( ! F_12 ( V_5 ) )
return;
V_28 = F_16 ( V_5 ) ;
V_22 = V_28 ;
do {
if ( V_74 ++ == V_73 )
break;
F_42 ( V_22 ) ;
V_22 = V_22 -> V_35 ;
} while ( V_22 != V_28 );
if ( V_75 && F_24 ( V_5 ) )
F_43 ( V_5 ) ;
}
static int F_44 ( struct V_5 * V_5 , struct V_76 * V_77 ,
void * V_78 )
{
struct V_79 * V_80 = V_78 ;
struct V_1 * V_1 = V_80 -> V_1 ;
struct V_66 * V_25 = V_5 -> V_25 ;
struct V_24 * V_24 = V_5 -> V_25 -> V_26 ;
const unsigned V_42 = V_24 -> V_30 ;
unsigned long V_81 ;
const unsigned V_43 = V_44 >> V_42 ;
T_1 V_47 ;
T_1 V_46 ;
T_1 V_49 [ V_50 ] ;
unsigned V_23 ;
unsigned V_73 = V_43 ;
struct V_10 * V_11 = NULL ;
int V_82 = 0 ;
T_1 V_83 = 0 ;
struct V_10 * V_84 = NULL ;
int V_52 ;
struct V_21 V_38 ;
T_4 V_85 = F_18 ( V_24 ) ;
int V_86 = 0 ;
int V_87 = ( V_77 -> V_88 == V_89 ? V_90 : V_91 ) ;
if ( F_12 ( V_5 ) ) {
struct V_21 * V_28 = F_16 ( V_5 ) ;
struct V_21 * V_22 = V_28 ;
V_23 = 0 ;
do {
F_38 ( F_45 ( V_22 ) ) ;
if ( ! F_19 ( V_22 ) ) {
if ( F_46 ( V_22 ) )
goto V_56;
if ( V_73 == V_43 )
V_73 = V_23 ;
continue;
}
if ( V_73 != V_43 )
goto V_56;
if ( ! F_46 ( V_22 ) || ! F_13 ( V_22 ) )
goto V_56;
if ( V_23 ) {
if ( V_22 -> V_34 != V_49 [ V_23 - 1 ] + 1 )
goto V_56;
}
V_49 [ V_23 ++ ] = V_22 -> V_34 ;
V_82 = F_29 ( V_22 ) ;
if ( V_82 ) {
V_83 = V_22 -> V_34 ;
V_84 = V_22 -> V_33 ;
}
V_11 = V_22 -> V_33 ;
} while ( ( V_22 = V_22 -> V_35 ) != V_28 );
if ( V_73 )
goto V_92;
goto V_56;
}
F_38 ( ! F_24 ( V_5 ) ) ;
V_46 = ( T_1 ) V_5 -> V_57 << ( V_31 - V_42 ) ;
V_47 = ( V_85 - 1 ) >> V_42 ;
V_38 . V_61 = V_5 ;
for ( V_23 = 0 ; V_23 < V_43 ; ) {
V_38 . V_32 = 0 ;
V_38 . V_58 = 1 << V_42 ;
if ( V_80 -> V_40 ( V_24 , V_46 , & V_38 , 1 ) )
goto V_56;
if ( F_47 ( & V_38 ) )
F_48 ( V_38 . V_33 ,
V_38 . V_34 ) ;
if ( F_29 ( & V_38 ) ) {
V_83 = V_38 . V_34 ;
V_84 = V_38 . V_33 ;
}
if ( V_23 ) {
if ( V_38 . V_34 != V_49 [ V_23 - 1 ] + 1 )
goto V_56;
}
V_49 [ V_23 ++ ] = V_38 . V_34 ;
V_82 = F_29 ( & V_38 ) ;
V_11 = V_38 . V_33 ;
if ( V_46 == V_47 )
break;
V_46 ++ ;
}
F_38 ( V_23 == 0 ) ;
V_73 = V_23 ;
V_92:
V_81 = V_85 >> V_31 ;
if ( V_5 -> V_57 >= V_81 ) {
unsigned V_93 = V_85 & ( V_44 - 1 ) ;
if ( V_5 -> V_57 > V_81 || ! V_93 )
goto V_56;
F_21 ( V_5 , V_93 , V_44 ) ;
}
if ( V_1 && V_80 -> V_37 != V_49 [ 0 ] - 1 )
V_1 = F_6 ( V_87 , V_1 ) ;
V_64:
if ( V_1 == NULL ) {
if ( V_73 == V_43 ) {
if ( ! F_49 ( V_11 , V_49 [ 0 ] << ( V_42 - 9 ) ,
V_5 , V_77 ) ) {
F_41 ( V_5 , V_73 ) ;
goto V_62;
}
}
V_1 = F_9 ( V_11 , V_49 [ 0 ] << ( V_42 - 9 ) ,
V_65 , V_94 | V_95 ) ;
if ( V_1 == NULL )
goto V_56;
F_50 ( V_77 , V_1 ) ;
}
F_51 ( V_77 , V_5 , V_96 ) ;
V_52 = V_73 << V_42 ;
if ( F_28 ( V_1 , V_5 , V_52 , 0 ) < V_52 ) {
V_1 = F_6 ( V_87 , V_1 ) ;
goto V_64;
}
F_41 ( V_5 , V_73 ) ;
F_38 ( F_52 ( V_5 ) ) ;
F_53 ( V_5 ) ;
F_22 ( V_5 ) ;
if ( V_82 || ( V_73 != V_43 ) ) {
V_1 = F_6 ( V_87 , V_1 ) ;
if ( V_83 ) {
F_54 ( V_84 ,
V_83 , 1 << V_42 ) ;
}
} else {
V_80 -> V_37 = V_49 [ V_43 - 1 ] ;
}
goto V_62;
V_56:
if ( V_1 )
V_1 = F_6 ( V_87 , V_1 ) ;
if ( V_80 -> V_97 ) {
V_86 = V_25 -> V_98 -> V_99 ( V_5 , V_77 ) ;
} else {
V_86 = - V_100 ;
goto V_62;
}
F_55 ( V_25 , V_86 ) ;
V_62:
V_80 -> V_1 = V_1 ;
return V_86 ;
}
int
F_56 ( struct V_66 * V_25 ,
struct V_76 * V_77 , T_3 V_40 )
{
struct V_101 V_102 ;
int V_86 ;
F_57 ( & V_102 ) ;
if ( ! V_40 )
V_86 = F_58 ( V_25 , V_77 ) ;
else {
struct V_79 V_80 = {
. V_1 = NULL ,
. V_37 = 0 ,
. V_40 = V_40 ,
. V_97 = 1 ,
} ;
V_86 = F_59 ( V_25 , V_77 , F_44 , & V_80 ) ;
if ( V_80 . V_1 ) {
int V_87 = ( V_77 -> V_88 == V_89 ?
V_90 : V_91 ) ;
F_6 ( V_87 , V_80 . V_1 ) ;
}
}
F_60 ( & V_102 ) ;
return V_86 ;
}
int F_61 ( struct V_5 * V_5 , T_3 V_40 ,
struct V_76 * V_77 )
{
struct V_79 V_80 = {
. V_1 = NULL ,
. V_37 = 0 ,
. V_40 = V_40 ,
. V_97 = 0 ,
} ;
int V_86 = F_44 ( V_5 , V_77 , & V_80 ) ;
if ( V_80 . V_1 ) {
int V_87 = ( V_77 -> V_88 == V_89 ?
V_90 : V_91 ) ;
F_6 ( V_87 , V_80 . V_1 ) ;
}
return V_86 ;
}
