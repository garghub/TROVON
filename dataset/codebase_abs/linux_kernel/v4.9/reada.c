static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
T_1 V_7 , int V_8 )
{
int V_9 = 0 ;
int V_10 ;
int V_11 ;
T_1 V_12 ;
T_1 V_13 ;
struct V_14 V_15 ;
if ( V_6 )
V_9 = F_2 ( V_6 ) ;
F_3 ( & V_4 -> V_16 ) ;
F_4 ( & V_4 -> V_17 , & V_15 ) ;
V_4 -> V_18 = 0 ;
F_5 ( & V_4 -> V_16 ) ;
if ( V_8 )
goto V_19;
if ( ! V_9 )
goto V_19;
V_10 = F_6 ( V_6 ) ;
V_13 = F_7 ( V_6 ) ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ ) {
struct V_20 * V_21 ;
T_1 V_22 ;
struct V_23 V_24 ;
struct V_23 V_25 ;
F_8 ( V_6 , & V_24 , V_11 ) ;
if ( V_11 + 1 < V_10 )
F_8 ( V_6 , & V_25 , V_11 + 1 ) ;
else
V_25 = V_4 -> V_26 ;
V_12 = F_9 ( V_6 , V_11 ) ;
V_22 = F_10 ( V_6 , V_11 ) ;
F_11 (rec, &list, list) {
struct V_27 * V_28 = V_21 -> V_28 ;
#ifdef F_12
if ( V_21 -> V_13 != V_13 ) {
F_13 ( V_2 ,
L_1 ,
V_24 . V_29 , V_24 . type , V_24 . V_30 ,
V_21 -> V_13 , V_13 ) ;
}
#endif
if ( V_21 -> V_13 == V_13 &&
F_14 ( & V_24 , & V_28 -> V_31 ) < 0 &&
F_14 ( & V_25 , & V_28 -> V_32 ) > 0 )
F_15 ( V_28 , V_12 , & V_25 , V_22 ) ;
}
}
V_19:
while ( ! F_16 ( & V_15 ) ) {
struct V_27 * V_28 ;
struct V_20 * V_21 ;
V_21 = F_17 ( & V_15 , struct V_20 , V_15 ) ;
F_18 ( & V_21 -> V_15 ) ;
V_28 = V_21 -> V_28 ;
F_19 ( V_21 ) ;
F_20 ( & V_28 -> V_33 ) ;
if ( F_21 ( & V_28 -> V_34 ) ) {
F_22 ( & V_28 -> V_33 , V_35 ) ;
F_23 ( & V_28 -> V_36 ) ;
}
F_22 ( & V_28 -> V_33 , V_35 ) ;
F_24 ( V_2 , V_4 ) ;
}
return;
}
int F_25 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_1 V_7 , int V_8 )
{
int V_37 = 0 ;
struct V_3 * V_4 ;
F_3 ( & V_2 -> V_38 ) ;
V_4 = F_26 ( & V_2 -> V_39 ,
V_7 >> V_40 ) ;
if ( V_4 )
V_4 -> V_33 ++ ;
F_5 ( & V_2 -> V_38 ) ;
if ( ! V_4 ) {
V_37 = - 1 ;
goto V_41;
}
F_1 ( V_2 , V_4 , V_6 , V_7 , V_8 ) ;
F_24 ( V_2 , V_4 ) ;
V_41:
F_27 ( V_2 ) ;
return V_37 ;
}
static struct V_42 * F_28 ( struct V_1 * V_2 ,
struct V_43 * V_44 , T_1 V_45 ,
struct V_46 * V_47 )
{
int V_37 ;
struct V_42 * V_48 ;
struct V_49 * V_50 = NULL ;
T_1 V_7 ;
T_1 V_51 ;
int V_11 ;
V_48 = NULL ;
F_3 ( & V_2 -> V_38 ) ;
V_37 = F_29 ( & V_44 -> V_52 , ( void * * ) & V_48 ,
V_45 >> V_40 , 1 ) ;
if ( V_37 == 1 && V_45 >= V_48 -> V_7 && V_45 <= V_48 -> V_51 ) {
F_20 ( & V_48 -> V_33 ) ;
F_5 ( & V_2 -> V_38 ) ;
return V_48 ;
}
F_5 ( & V_2 -> V_38 ) ;
V_50 = F_30 ( V_2 , V_45 ) ;
if ( ! V_50 )
return NULL ;
V_7 = V_50 -> V_24 . V_29 ;
V_51 = V_7 + V_50 -> V_24 . V_30 - 1 ;
F_31 ( V_50 ) ;
V_48 = F_32 ( sizeof( * V_48 ) , V_53 ) ;
if ( ! V_48 )
return NULL ;
V_48 -> V_7 = V_7 ;
V_48 -> V_51 = V_51 ;
F_33 ( & V_48 -> V_15 ) ;
F_34 ( & V_48 -> V_16 ) ;
V_48 -> V_54 = 0 ;
F_35 ( & V_48 -> V_33 ) ;
V_48 -> V_34 = 0 ;
V_48 -> V_55 = V_44 ;
for ( V_11 = 0 ; V_11 < V_47 -> V_56 ; ++ V_11 ) {
V_48 -> V_57 [ V_11 ] = V_47 -> V_58 [ V_11 ] . V_44 ;
}
V_48 -> V_59 = V_47 -> V_56 ;
F_3 ( & V_2 -> V_38 ) ;
V_37 = F_36 ( & V_44 -> V_52 ,
( unsigned long ) ( V_48 -> V_51 >> V_40 ) ,
V_48 ) ;
if ( V_37 == - V_60 ) {
F_19 ( V_48 ) ;
V_37 = F_29 ( & V_44 -> V_52 , ( void * * ) & V_48 ,
V_45 >> V_40 , 1 ) ;
if ( V_37 == 1 && V_45 >= V_48 -> V_7 && V_45 <= V_48 -> V_51 )
F_20 ( & V_48 -> V_33 ) ;
else
V_48 = NULL ;
}
F_5 ( & V_2 -> V_38 ) ;
return V_48 ;
}
static struct V_3 * F_37 ( struct V_61 * V_62 ,
T_1 V_45 ,
struct V_23 * V_26 )
{
int V_37 ;
struct V_3 * V_4 = NULL ;
struct V_3 * V_63 = NULL ;
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_46 * V_47 = NULL ;
struct V_43 * V_44 ;
struct V_43 * V_64 ;
T_2 V_65 ;
T_1 V_66 ;
int V_67 ;
int V_68 = 0 ;
unsigned long V_69 = V_45 >> V_40 ;
int V_70 ;
int V_71 = 0 ;
F_3 ( & V_2 -> V_38 ) ;
V_4 = F_26 ( & V_2 -> V_39 , V_69 ) ;
if ( V_4 )
V_4 -> V_33 ++ ;
F_5 ( & V_2 -> V_38 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_32 ( sizeof( * V_4 ) , V_53 ) ;
if ( ! V_4 )
return NULL ;
V_65 = V_62 -> V_72 ;
V_4 -> V_45 = V_45 ;
V_4 -> V_26 = * V_26 ;
F_33 ( & V_4 -> V_17 ) ;
F_34 ( & V_4 -> V_16 ) ;
V_4 -> V_33 = 1 ;
V_66 = V_65 ;
V_37 = F_38 ( V_2 , V_73 , V_45 , & V_66 ,
& V_47 , 0 ) ;
if ( V_37 || ! V_47 || V_66 < V_65 )
goto error;
if ( V_47 -> V_56 > V_74 ) {
F_39 ( V_62 -> V_2 ,
L_2 ,
V_74 ) ;
goto error;
}
V_67 = V_47 -> V_56 - V_47 -> V_75 ;
for ( V_68 = 0 ; V_68 < V_67 ; ++ V_68 ) {
struct V_42 * V_48 ;
V_44 = V_47 -> V_58 [ V_68 ] . V_44 ;
if ( ! V_44 -> V_76 )
continue;
V_48 = F_28 ( V_2 , V_44 , V_45 , V_47 ) ;
if ( ! V_48 )
continue;
V_4 -> V_77 [ V_4 -> V_68 ++ ] = V_48 ;
F_3 ( & V_48 -> V_16 ) ;
if ( ! V_48 -> V_34 )
F_20 ( & V_48 -> V_33 ) ;
++ V_48 -> V_34 ;
F_5 ( & V_48 -> V_16 ) ;
F_3 ( & V_2 -> V_38 ) ;
F_22 ( & V_48 -> V_33 , V_78 ) ;
F_5 ( & V_2 -> V_38 ) ;
}
if ( V_4 -> V_68 == 0 ) {
goto error;
}
F_40 ( & V_2 -> V_79 , 0 ) ;
F_3 ( & V_2 -> V_38 ) ;
V_37 = F_36 ( & V_2 -> V_39 , V_69 , V_4 ) ;
if ( V_37 == - V_60 ) {
V_63 = F_26 ( & V_2 -> V_39 , V_69 ) ;
F_41 ( ! V_63 ) ;
V_63 -> V_33 ++ ;
F_5 ( & V_2 -> V_38 ) ;
F_42 ( & V_2 -> V_79 , 0 ) ;
goto error;
}
if ( V_37 ) {
F_5 ( & V_2 -> V_38 ) ;
F_42 ( & V_2 -> V_79 , 0 ) ;
goto error;
}
V_64 = NULL ;
V_70 = F_43 (
& V_2 -> V_79 ) ;
for ( V_68 = 0 ; V_68 < V_4 -> V_68 ; ++ V_68 ) {
V_44 = V_4 -> V_77 [ V_68 ] -> V_55 ;
if ( V_44 == V_64 ) {
continue;
}
if ( ! V_44 -> V_76 )
continue;
if ( V_70 &&
V_44 == V_2 -> V_79 . V_80 ) {
continue;
}
V_64 = V_44 ;
V_37 = F_36 ( & V_44 -> V_81 , V_69 , V_4 ) ;
if ( V_37 ) {
while ( -- V_68 >= 0 ) {
V_44 = V_4 -> V_77 [ V_68 ] -> V_55 ;
F_41 ( V_44 == NULL ) ;
F_44 ( & V_44 -> V_81 , V_69 ) ;
}
F_41 ( V_2 == NULL ) ;
F_44 ( & V_2 -> V_39 , V_69 ) ;
F_5 ( & V_2 -> V_38 ) ;
F_42 ( & V_2 -> V_79 , 0 ) ;
goto error;
}
V_71 = 1 ;
}
F_5 ( & V_2 -> V_38 ) ;
F_42 ( & V_2 -> V_79 , 0 ) ;
if ( ! V_71 )
goto error;
F_45 ( V_47 ) ;
return V_4 ;
error:
for ( V_68 = 0 ; V_68 < V_4 -> V_68 ; ++ V_68 ) {
struct V_42 * V_48 ;
V_48 = V_4 -> V_77 [ V_68 ] ;
F_20 ( & V_48 -> V_33 ) ;
F_3 ( & V_48 -> V_16 ) ;
-- V_48 -> V_34 ;
if ( V_48 -> V_34 == 0 ) {
F_22 ( & V_48 -> V_33 , V_78 ) ;
}
F_5 ( & V_48 -> V_16 ) ;
F_3 ( & V_2 -> V_38 ) ;
F_22 ( & V_48 -> V_33 , V_78 ) ;
F_5 ( & V_2 -> V_38 ) ;
}
F_45 ( V_47 ) ;
F_19 ( V_4 ) ;
return V_63 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_11 ;
unsigned long V_69 = V_4 -> V_45 >> V_40 ;
F_3 ( & V_2 -> V_38 ) ;
if ( -- V_4 -> V_33 ) {
F_5 ( & V_2 -> V_38 ) ;
return;
}
F_44 ( & V_2 -> V_39 , V_69 ) ;
for ( V_11 = 0 ; V_11 < V_4 -> V_68 ; ++ V_11 ) {
struct V_42 * V_48 = V_4 -> V_77 [ V_11 ] ;
F_44 ( & V_48 -> V_55 -> V_81 , V_69 ) ;
}
F_5 ( & V_2 -> V_38 ) ;
for ( V_11 = 0 ; V_11 < V_4 -> V_68 ; ++ V_11 ) {
struct V_42 * V_48 = V_4 -> V_77 [ V_11 ] ;
F_20 ( & V_48 -> V_33 ) ;
F_3 ( & V_48 -> V_16 ) ;
-- V_48 -> V_34 ;
if ( V_48 -> V_34 == 0 ) {
F_22 ( & V_48 -> V_33 , V_78 ) ;
}
F_5 ( & V_48 -> V_16 ) ;
F_3 ( & V_2 -> V_38 ) ;
F_22 ( & V_48 -> V_33 , V_78 ) ;
F_5 ( & V_2 -> V_38 ) ;
}
F_19 ( V_4 ) ;
}
static void V_78 ( struct V_82 * V_82 )
{
struct V_42 * V_48 = F_46 ( V_82 , struct V_42 , V_33 ) ;
F_44 ( & V_48 -> V_55 -> V_52 ,
V_48 -> V_51 >> V_40 ) ;
F_19 ( V_48 ) ;
}
static void V_35 ( struct V_82 * V_82 )
{
struct V_27 * V_28 = F_46 ( V_82 , struct V_27 ,
V_33 ) ;
F_19 ( V_28 ) ;
}
static int F_15 ( struct V_27 * V_28 , T_1 V_45 ,
struct V_23 * V_26 , T_1 V_13 )
{
struct V_61 * V_62 = V_28 -> V_62 ;
struct V_3 * V_4 ;
struct V_20 * V_21 ;
V_4 = F_37 ( V_62 , V_45 , V_26 ) ;
if ( ! V_4 )
return - 1 ;
V_21 = F_32 ( sizeof( * V_21 ) , V_53 ) ;
if ( ! V_21 ) {
F_24 ( V_62 -> V_2 , V_4 ) ;
return - V_83 ;
}
V_21 -> V_28 = V_28 ;
V_21 -> V_13 = V_13 ;
F_47 ( & V_28 -> V_34 ) ;
F_3 ( & V_4 -> V_16 ) ;
F_48 ( & V_21 -> V_15 , & V_4 -> V_17 ) ;
F_5 ( & V_4 -> V_16 ) ;
return 0 ;
}
static void F_49 ( struct V_42 * V_48 , int V_16 )
{
int V_11 ;
unsigned long V_69 = V_48 -> V_51 >> V_40 ;
for ( V_11 = 0 ; V_11 < V_48 -> V_59 ; ++ V_11 ) {
struct V_42 * V_84 ;
V_84 = F_26 ( & V_48 -> V_57 [ V_11 ] -> V_52 , V_69 ) ;
if ( V_84 && V_84 -> V_55 != V_48 -> V_55 )
V_84 -> V_54 = V_16 ;
}
}
static int F_50 ( struct V_43 * V_44 )
{
struct V_42 * V_85 = NULL ;
struct V_42 * V_86 = NULL ;
T_1 V_87 = 0 ;
T_1 V_88 = 0 ;
unsigned long V_69 = 0 ;
int V_37 ;
if ( V_44 -> V_89 ) {
F_49 ( V_44 -> V_89 , 0 ) ;
F_22 ( & V_44 -> V_89 -> V_33 , V_78 ) ;
V_44 -> V_89 = NULL ;
}
while ( 1 ) {
struct V_42 * V_48 ;
V_37 = F_29 ( & V_44 -> V_52 ,
( void * * ) & V_48 , V_69 , 1 ) ;
if ( V_37 == 0 )
break;
V_69 = ( V_48 -> V_51 >> V_40 ) + 1 ;
if ( V_48 -> V_54 ) {
if ( V_48 -> V_34 > V_88 ) {
V_88 = V_48 -> V_34 ;
V_86 = V_48 ;
}
} else {
if ( V_48 -> V_34 > V_87 ) {
V_87 = V_48 -> V_34 ;
V_85 = V_48 ;
}
}
}
if ( V_85 )
V_44 -> V_89 = V_85 ;
else if ( V_86 )
V_44 -> V_89 = V_86 ;
else
return 0 ;
V_44 -> V_90 = V_44 -> V_89 -> V_7 ;
F_20 ( & V_44 -> V_89 -> V_33 ) ;
F_49 ( V_44 -> V_89 , 1 ) ;
return 1 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
struct V_3 * V_4 = NULL ;
int V_91 = 0 ;
struct V_5 * V_6 = NULL ;
T_1 V_45 ;
int V_37 ;
int V_11 ;
F_3 ( & V_2 -> V_38 ) ;
if ( V_44 -> V_89 == NULL ) {
V_37 = F_50 ( V_44 ) ;
if ( ! V_37 ) {
F_5 ( & V_2 -> V_38 ) ;
return 0 ;
}
}
V_37 = F_29 ( & V_44 -> V_81 , ( void * * ) & V_4 ,
V_44 -> V_90 >> V_40 , 1 ) ;
if ( V_37 == 0 || V_4 -> V_45 > V_44 -> V_89 -> V_51 ) {
V_37 = F_50 ( V_44 ) ;
if ( ! V_37 ) {
F_5 ( & V_2 -> V_38 ) ;
return 0 ;
}
V_4 = NULL ;
V_37 = F_29 ( & V_44 -> V_81 , ( void * * ) & V_4 ,
V_44 -> V_90 >> V_40 , 1 ) ;
}
if ( V_37 == 0 ) {
F_5 ( & V_2 -> V_38 ) ;
return 0 ;
}
V_44 -> V_90 = V_4 -> V_45 + V_2 -> V_92 -> V_72 ;
V_4 -> V_33 ++ ;
F_5 ( & V_2 -> V_38 ) ;
F_3 ( & V_4 -> V_16 ) ;
if ( V_4 -> V_18 || F_16 ( & V_4 -> V_17 ) ) {
F_5 ( & V_4 -> V_16 ) ;
F_24 ( V_2 , V_4 ) ;
return 0 ;
}
V_4 -> V_18 = 1 ;
F_5 ( & V_4 -> V_16 ) ;
for ( V_11 = 0 ; V_11 < V_4 -> V_68 ; ++ V_11 ) {
if ( V_4 -> V_77 [ V_11 ] -> V_55 == V_44 ) {
V_91 = V_11 + 1 ;
break;
}
}
V_45 = V_4 -> V_45 ;
F_47 ( & V_44 -> V_93 ) ;
V_37 = F_52 ( V_2 -> V_94 , V_45 ,
V_91 , & V_6 ) ;
if ( V_37 )
F_1 ( V_2 , V_4 , NULL , V_45 , V_37 ) ;
else if ( V_6 )
F_1 ( V_2 , V_4 , V_6 , V_6 -> V_7 , V_37 ) ;
if ( V_6 )
F_53 ( V_6 ) ;
F_54 ( & V_44 -> V_93 ) ;
F_24 ( V_2 , V_4 ) ;
return 1 ;
}
static void F_55 ( struct V_95 * V_96 )
{
struct V_97 * V_98 ;
struct V_1 * V_2 ;
int V_99 ;
V_98 = F_46 ( V_96 , struct V_97 , V_96 ) ;
V_2 = V_98 -> V_2 ;
F_19 ( V_98 ) ;
V_99 = F_56 ( F_57 ( V_100 ) ,
F_58 ( V_100 ) ) ;
F_59 ( V_100 , V_101 ) ;
F_60 ( V_2 ) ;
F_59 ( V_100 , V_99 ) ;
F_54 ( & V_2 -> V_102 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_43 * V_55 ;
struct V_103 * V_104 = V_2 -> V_104 ;
T_1 V_105 ;
T_1 V_106 = 0 ;
int V_11 ;
do {
V_105 = 0 ;
F_61 ( & V_104 -> V_107 ) ;
F_11 (device, &fs_devices->devices, dev_list) {
if ( F_62 ( & V_55 -> V_93 ) <
V_108 )
V_105 += F_51 ( V_2 ,
V_55 ) ;
}
F_63 ( & V_104 -> V_107 ) ;
V_106 += V_105 ;
} while ( V_105 && V_106 < 10000 );
if ( V_105 == 0 )
return;
for ( V_11 = 0 ; V_11 < 2 ; ++ V_11 ) {
F_27 ( V_2 ) ;
if ( F_62 ( & V_2 -> V_102 ) >
V_74 * 2 )
break;
}
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_97 * V_98 ;
V_98 = F_32 ( sizeof( * V_98 ) , V_53 ) ;
if ( ! V_98 ) {
F_64 () ;
}
F_65 ( & V_98 -> V_96 , V_109 ,
F_55 , NULL , NULL ) ;
V_98 -> V_2 = V_2 ;
F_66 ( V_2 -> V_110 , & V_98 -> V_96 ) ;
F_47 ( & V_2 -> V_102 ) ;
}
static void F_67 ( struct V_1 * V_2 , int V_111 )
{
struct V_43 * V_55 ;
struct V_103 * V_104 = V_2 -> V_104 ;
unsigned long V_69 ;
int V_37 ;
int V_11 ;
int V_112 ;
int V_113 ;
F_3 ( & V_2 -> V_38 ) ;
F_11 (device, &fs_devices->devices, dev_list) {
F_13 ( V_2 , L_3 , V_55 -> V_114 ,
F_62 ( & V_55 -> V_93 ) ) ;
V_69 = 0 ;
while ( 1 ) {
struct V_42 * V_48 ;
V_37 = F_29 ( & V_55 -> V_52 ,
( void * * ) & V_48 , V_69 , 1 ) ;
if ( V_37 == 0 )
break;
F_68 ( L_4 ,
V_48 -> V_7 , V_48 -> V_51 , V_48 -> V_34 ,
V_48 -> V_54 ) ;
for ( V_112 = 0 ; V_112 < V_48 -> V_59 ; ++ V_112 ) {
F_69 ( L_5 ,
V_48 -> V_57 [ V_112 ] -> V_114 ) ;
}
if ( V_55 -> V_89 == V_48 )
F_69 ( L_6 ,
V_55 -> V_90 - V_48 -> V_7 ) ;
F_69 ( L_7 ) ;
V_69 = ( V_48 -> V_51 >> V_40 ) + 1 ;
}
V_113 = 0 ;
V_69 = 0 ;
while ( V_111 ) {
struct V_3 * V_4 = NULL ;
V_37 = F_29 ( & V_55 -> V_81 ,
( void * * ) & V_4 , V_69 , 1 ) ;
if ( V_37 == 0 )
break;
F_68 ( L_8 ,
V_4 -> V_45 , V_2 -> V_92 -> V_72 ,
F_16 ( & V_4 -> V_17 ) , V_4 -> V_18 ) ;
for ( V_11 = 0 ; V_11 < V_4 -> V_68 ; ++ V_11 ) {
F_69 ( L_9 ,
V_4 -> V_77 [ V_11 ] -> V_7 ,
V_4 -> V_77 [ V_11 ] -> V_51 ) ;
for ( V_112 = 0 ; V_112 < V_4 -> V_77 [ V_11 ] -> V_59 ; ++ V_112 ) {
F_69 ( L_5 ,
V_4 -> V_77 [ V_11 ] -> V_57 [ V_112 ] -> V_114 ) ;
}
}
F_69 ( L_7 ) ;
V_69 = ( V_4 -> V_45 >> V_40 ) + 1 ;
if ( ++ V_113 > 15 )
break;
}
}
V_69 = 0 ;
V_113 = 0 ;
while ( V_111 ) {
struct V_3 * V_4 = NULL ;
V_37 = F_29 ( & V_2 -> V_39 , ( void * * ) & V_4 ,
V_69 , 1 ) ;
if ( V_37 == 0 )
break;
if ( ! V_4 -> V_18 ) {
V_69 = ( V_4 -> V_45 >> V_40 ) + 1 ;
continue;
}
F_68 ( L_10 ,
V_4 -> V_45 , V_2 -> V_92 -> V_72 ,
F_16 ( & V_4 -> V_17 ) , V_4 -> V_18 ) ;
for ( V_11 = 0 ; V_11 < V_4 -> V_68 ; ++ V_11 ) {
F_69 ( L_9 ,
V_4 -> V_77 [ V_11 ] -> V_7 ,
V_4 -> V_77 [ V_11 ] -> V_51 ) ;
for ( V_112 = 0 ; V_112 < V_4 -> V_77 [ V_11 ] -> V_59 ; ++ V_112 ) {
F_69 ( L_5 ,
V_4 -> V_77 [ V_11 ] -> V_57 [ V_112 ] -> V_114 ) ;
}
}
F_69 ( L_7 ) ;
V_69 = ( V_4 -> V_45 >> V_40 ) + 1 ;
}
F_5 ( & V_2 -> V_38 ) ;
}
struct V_27 * F_70 ( struct V_61 * V_62 ,
struct V_23 * V_32 , struct V_23 * V_31 )
{
struct V_27 * V_28 ;
T_1 V_7 ;
T_1 V_13 ;
int V_37 ;
struct V_5 * V_115 ;
static struct V_23 V_116 = {
. V_29 = ( T_1 ) - 1 ,
. type = ( V_117 ) - 1 ,
. V_30 = ( T_1 ) - 1
} ;
V_28 = F_32 ( sizeof( * V_28 ) , V_53 ) ;
if ( ! V_28 )
return F_71 ( - V_83 ) ;
V_28 -> V_62 = V_62 ;
V_28 -> V_32 = * V_32 ;
V_28 -> V_31 = * V_31 ;
F_72 ( & V_28 -> V_34 , 0 ) ;
F_73 ( & V_28 -> V_36 ) ;
F_35 ( & V_28 -> V_33 ) ;
F_20 ( & V_28 -> V_33 ) ;
V_115 = F_74 ( V_62 ) ;
V_7 = V_115 -> V_7 ;
V_13 = F_7 ( V_115 ) ;
F_53 ( V_115 ) ;
V_37 = F_15 ( V_28 , V_7 , & V_116 , V_13 ) ;
if ( V_37 ) {
F_19 ( V_28 ) ;
return F_71 ( V_37 ) ;
}
F_27 ( V_62 -> V_2 ) ;
return V_28 ;
}
int F_75 ( void * V_118 )
{
struct V_27 * V_28 = V_118 ;
struct V_1 * V_2 = V_28 -> V_62 -> V_2 ;
while ( F_62 ( & V_28 -> V_34 ) ) {
if ( ! F_62 ( & V_2 -> V_102 ) )
F_27 ( V_2 ) ;
F_76 ( V_28 -> V_36 , F_62 ( & V_28 -> V_34 ) == 0 ,
5 * V_119 ) ;
F_67 ( V_28 -> V_62 -> V_2 ,
F_62 ( & V_28 -> V_34 ) < 10 ? 1 : 0 ) ;
}
F_67 ( V_28 -> V_62 -> V_2 , F_62 ( & V_28 -> V_34 ) < 10 ? 1 : 0 ) ;
F_22 ( & V_28 -> V_33 , V_35 ) ;
return 0 ;
}
int F_75 ( void * V_118 )
{
struct V_27 * V_28 = V_118 ;
struct V_1 * V_2 = V_28 -> V_62 -> V_2 ;
while ( F_62 ( & V_28 -> V_34 ) ) {
if ( ! F_62 ( & V_2 -> V_102 ) )
F_27 ( V_2 ) ;
F_76 ( V_28 -> V_36 , F_62 ( & V_28 -> V_34 ) == 0 ,
( V_119 + 9 ) / 10 ) ;
}
F_22 ( & V_28 -> V_33 , V_35 ) ;
return 0 ;
}
void F_77 ( void * V_118 )
{
struct V_27 * V_28 = V_118 ;
F_22 ( & V_28 -> V_33 , V_35 ) ;
}
