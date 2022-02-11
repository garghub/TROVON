static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
int V_7 )
{
int V_8 ;
int V_9 ;
T_1 V_10 ;
T_1 V_11 ;
struct V_12 V_13 ;
F_2 ( & V_4 -> V_14 ) ;
F_3 ( & V_4 -> V_15 , & V_13 ) ;
V_4 -> V_16 = 0 ;
F_4 ( & V_4 -> V_14 ) ;
if ( V_7 )
goto V_17;
if ( ! F_5 ( V_6 ) )
goto V_17;
V_8 = F_6 ( V_6 ) ;
V_11 = F_7 ( V_6 ) ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ ) {
struct V_18 * V_19 ;
T_1 V_20 ;
struct V_21 V_22 ;
struct V_21 V_23 ;
F_8 ( V_6 , & V_22 , V_9 ) ;
if ( V_9 + 1 < V_8 )
F_8 ( V_6 , & V_23 , V_9 + 1 ) ;
else
V_23 = V_4 -> V_24 ;
V_10 = F_9 ( V_6 , V_9 ) ;
V_20 = F_10 ( V_6 , V_9 ) ;
F_11 (rec, &list, list) {
struct V_25 * V_26 = V_19 -> V_26 ;
#ifdef F_12
if ( V_19 -> V_11 != V_11 ) {
F_13 ( V_2 ,
L_1 ,
V_22 . V_27 , V_22 . type , V_22 . V_28 ,
V_19 -> V_11 , V_11 ) ;
}
#endif
if ( V_19 -> V_11 == V_11 &&
F_14 ( & V_22 , & V_26 -> V_29 ) < 0 &&
F_14 ( & V_23 , & V_26 -> V_30 ) > 0 )
F_15 ( V_26 , V_10 , & V_23 , V_20 ) ;
}
}
V_17:
while ( ! F_16 ( & V_13 ) ) {
struct V_25 * V_26 ;
struct V_18 * V_19 ;
V_19 = F_17 ( & V_13 , struct V_18 , V_13 ) ;
F_18 ( & V_19 -> V_13 ) ;
V_26 = V_19 -> V_26 ;
F_19 ( V_19 ) ;
F_20 ( & V_26 -> V_31 ) ;
if ( F_21 ( & V_26 -> V_32 ) ) {
F_22 ( & V_26 -> V_31 , V_33 ) ;
F_23 ( & V_26 -> V_34 ) ;
}
F_22 ( & V_26 -> V_31 , V_33 ) ;
F_24 ( V_2 , V_4 ) ;
}
return;
}
int F_25 ( struct V_5 * V_6 , int V_7 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
int V_35 = 0 ;
struct V_3 * V_4 ;
F_2 ( & V_2 -> V_36 ) ;
V_4 = F_26 ( & V_2 -> V_37 ,
V_6 -> V_38 >> V_39 ) ;
if ( V_4 )
V_4 -> V_31 ++ ;
F_4 ( & V_2 -> V_36 ) ;
if ( ! V_4 ) {
V_35 = - 1 ;
goto V_40;
}
F_1 ( V_2 , V_4 , V_6 , V_7 ) ;
F_24 ( V_2 , V_4 ) ;
V_40:
F_27 ( V_2 ) ;
return V_35 ;
}
static struct V_41 * F_28 ( struct V_42 * V_43 , T_1 V_44 ,
struct V_45 * V_46 )
{
struct V_1 * V_2 = V_43 -> V_2 ;
int V_35 ;
struct V_41 * V_47 ;
struct V_48 * V_49 = NULL ;
T_1 V_38 ;
T_1 V_50 ;
int V_9 ;
V_47 = NULL ;
F_2 ( & V_2 -> V_36 ) ;
V_35 = F_29 ( & V_43 -> V_51 , ( void * * ) & V_47 ,
V_44 >> V_39 , 1 ) ;
if ( V_35 == 1 && V_44 >= V_47 -> V_38 && V_44 <= V_47 -> V_50 ) {
F_20 ( & V_47 -> V_31 ) ;
F_4 ( & V_2 -> V_36 ) ;
return V_47 ;
}
F_4 ( & V_2 -> V_36 ) ;
V_49 = F_30 ( V_2 , V_44 ) ;
if ( ! V_49 )
return NULL ;
V_38 = V_49 -> V_22 . V_27 ;
V_50 = V_38 + V_49 -> V_22 . V_28 - 1 ;
F_31 ( V_49 ) ;
V_47 = F_32 ( sizeof( * V_47 ) , V_52 ) ;
if ( ! V_47 )
return NULL ;
V_35 = F_33 ( V_52 ) ;
if ( V_35 ) {
F_19 ( V_47 ) ;
return NULL ;
}
V_47 -> V_38 = V_38 ;
V_47 -> V_50 = V_50 ;
F_34 ( & V_47 -> V_13 ) ;
F_35 ( & V_47 -> V_14 ) ;
V_47 -> V_53 = 0 ;
F_36 ( & V_47 -> V_31 ) ;
V_47 -> V_32 = 0 ;
V_47 -> V_54 = V_43 ;
for ( V_9 = 0 ; V_9 < V_46 -> V_55 ; ++ V_9 ) {
V_47 -> V_56 [ V_9 ] = V_46 -> V_57 [ V_9 ] . V_43 ;
}
V_47 -> V_58 = V_46 -> V_55 ;
F_2 ( & V_2 -> V_36 ) ;
V_35 = F_37 ( & V_43 -> V_51 ,
( unsigned long ) ( V_47 -> V_50 >> V_39 ) ,
V_47 ) ;
if ( V_35 == - V_59 ) {
F_19 ( V_47 ) ;
V_35 = F_29 ( & V_43 -> V_51 , ( void * * ) & V_47 ,
V_44 >> V_39 , 1 ) ;
if ( V_35 == 1 && V_44 >= V_47 -> V_38 && V_44 <= V_47 -> V_50 )
F_20 ( & V_47 -> V_31 ) ;
else
V_47 = NULL ;
}
F_4 ( & V_2 -> V_36 ) ;
F_38 () ;
return V_47 ;
}
static struct V_3 * F_39 ( struct V_1 * V_2 ,
T_1 V_44 ,
struct V_21 * V_24 )
{
int V_35 ;
struct V_3 * V_4 = NULL ;
struct V_3 * V_60 = NULL ;
struct V_45 * V_46 = NULL ;
struct V_42 * V_43 ;
struct V_42 * V_61 ;
T_1 V_62 ;
int V_63 ;
int V_64 = 0 ;
unsigned long V_65 = V_44 >> V_39 ;
int V_66 ;
int V_67 = 0 ;
F_2 ( & V_2 -> V_36 ) ;
V_4 = F_26 ( & V_2 -> V_37 , V_65 ) ;
if ( V_4 )
V_4 -> V_31 ++ ;
F_4 ( & V_2 -> V_36 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_32 ( sizeof( * V_4 ) , V_52 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_44 = V_44 ;
V_4 -> V_24 = * V_24 ;
F_34 ( & V_4 -> V_15 ) ;
F_35 ( & V_4 -> V_14 ) ;
V_4 -> V_31 = 1 ;
V_62 = V_2 -> V_68 ;
V_35 = F_40 ( V_2 , V_69 , V_44 ,
& V_62 , & V_46 , 0 ) ;
if ( V_35 || ! V_46 || V_62 < V_2 -> V_68 )
goto error;
if ( V_46 -> V_55 > V_70 ) {
F_41 ( V_2 ,
L_2 ,
V_70 ) ;
goto error;
}
V_63 = V_46 -> V_55 - V_46 -> V_71 ;
for ( V_64 = 0 ; V_64 < V_63 ; ++ V_64 ) {
struct V_41 * V_47 ;
V_43 = V_46 -> V_57 [ V_64 ] . V_43 ;
if ( ! V_43 -> V_72 )
continue;
V_47 = F_28 ( V_43 , V_44 , V_46 ) ;
if ( ! V_47 )
continue;
V_4 -> V_73 [ V_4 -> V_64 ++ ] = V_47 ;
F_2 ( & V_47 -> V_14 ) ;
if ( ! V_47 -> V_32 )
F_20 ( & V_47 -> V_31 ) ;
++ V_47 -> V_32 ;
F_4 ( & V_47 -> V_14 ) ;
F_2 ( & V_2 -> V_36 ) ;
F_22 ( & V_47 -> V_31 , V_74 ) ;
F_4 ( & V_2 -> V_36 ) ;
}
if ( V_4 -> V_64 == 0 ) {
goto error;
}
V_35 = F_33 ( V_52 ) ;
if ( V_35 )
goto error;
F_42 ( & V_2 -> V_75 , 0 ) ;
F_2 ( & V_2 -> V_36 ) ;
V_35 = F_37 ( & V_2 -> V_37 , V_65 , V_4 ) ;
if ( V_35 == - V_59 ) {
V_60 = F_26 ( & V_2 -> V_37 , V_65 ) ;
V_60 -> V_31 ++ ;
F_4 ( & V_2 -> V_36 ) ;
F_43 ( & V_2 -> V_75 , 0 ) ;
F_38 () ;
goto error;
}
if ( V_35 ) {
F_4 ( & V_2 -> V_36 ) ;
F_43 ( & V_2 -> V_75 , 0 ) ;
F_38 () ;
goto error;
}
F_38 () ;
V_61 = NULL ;
V_66 = F_44 (
& V_2 -> V_75 ) ;
for ( V_64 = 0 ; V_64 < V_4 -> V_64 ; ++ V_64 ) {
V_43 = V_4 -> V_73 [ V_64 ] -> V_54 ;
if ( V_43 == V_61 ) {
continue;
}
if ( ! V_43 -> V_72 )
continue;
if ( V_66 &&
V_43 == V_2 -> V_75 . V_76 ) {
continue;
}
V_61 = V_43 ;
V_35 = F_37 ( & V_43 -> V_77 , V_65 , V_4 ) ;
if ( V_35 ) {
while ( -- V_64 >= 0 ) {
V_43 = V_4 -> V_73 [ V_64 ] -> V_54 ;
F_45 ( V_43 == NULL ) ;
F_46 ( & V_43 -> V_77 , V_65 ) ;
}
F_46 ( & V_2 -> V_37 , V_65 ) ;
F_4 ( & V_2 -> V_36 ) ;
F_43 ( & V_2 -> V_75 , 0 ) ;
goto error;
}
V_67 = 1 ;
}
F_4 ( & V_2 -> V_36 ) ;
F_43 ( & V_2 -> V_75 , 0 ) ;
if ( ! V_67 )
goto error;
F_47 ( V_46 ) ;
return V_4 ;
error:
for ( V_64 = 0 ; V_64 < V_4 -> V_64 ; ++ V_64 ) {
struct V_41 * V_47 ;
V_47 = V_4 -> V_73 [ V_64 ] ;
F_20 ( & V_47 -> V_31 ) ;
F_2 ( & V_47 -> V_14 ) ;
-- V_47 -> V_32 ;
if ( V_47 -> V_32 == 0 ) {
F_22 ( & V_47 -> V_31 , V_74 ) ;
}
F_4 ( & V_47 -> V_14 ) ;
F_2 ( & V_2 -> V_36 ) ;
F_22 ( & V_47 -> V_31 , V_74 ) ;
F_4 ( & V_2 -> V_36 ) ;
}
F_47 ( V_46 ) ;
F_19 ( V_4 ) ;
return V_60 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_9 ;
unsigned long V_65 = V_4 -> V_44 >> V_39 ;
F_2 ( & V_2 -> V_36 ) ;
if ( -- V_4 -> V_31 ) {
F_4 ( & V_2 -> V_36 ) ;
return;
}
F_46 ( & V_2 -> V_37 , V_65 ) ;
for ( V_9 = 0 ; V_9 < V_4 -> V_64 ; ++ V_9 ) {
struct V_41 * V_47 = V_4 -> V_73 [ V_9 ] ;
F_46 ( & V_47 -> V_54 -> V_77 , V_65 ) ;
}
F_4 ( & V_2 -> V_36 ) ;
for ( V_9 = 0 ; V_9 < V_4 -> V_64 ; ++ V_9 ) {
struct V_41 * V_47 = V_4 -> V_73 [ V_9 ] ;
F_20 ( & V_47 -> V_31 ) ;
F_2 ( & V_47 -> V_14 ) ;
-- V_47 -> V_32 ;
if ( V_47 -> V_32 == 0 ) {
F_22 ( & V_47 -> V_31 , V_74 ) ;
}
F_4 ( & V_47 -> V_14 ) ;
F_2 ( & V_2 -> V_36 ) ;
F_22 ( & V_47 -> V_31 , V_74 ) ;
F_4 ( & V_2 -> V_36 ) ;
}
F_19 ( V_4 ) ;
}
static void V_74 ( struct V_78 * V_78 )
{
struct V_41 * V_47 = F_48 ( V_78 , struct V_41 , V_31 ) ;
F_46 ( & V_47 -> V_54 -> V_51 ,
V_47 -> V_50 >> V_39 ) ;
F_19 ( V_47 ) ;
}
static void V_33 ( struct V_78 * V_78 )
{
struct V_25 * V_26 = F_48 ( V_78 , struct V_25 ,
V_31 ) ;
F_19 ( V_26 ) ;
}
static int F_15 ( struct V_25 * V_26 , T_1 V_44 ,
struct V_21 * V_24 , T_1 V_11 )
{
struct V_1 * V_2 = V_26 -> V_2 ;
struct V_3 * V_4 ;
struct V_18 * V_19 ;
V_4 = F_39 ( V_2 , V_44 , V_24 ) ;
if ( ! V_4 )
return - 1 ;
V_19 = F_32 ( sizeof( * V_19 ) , V_52 ) ;
if ( ! V_19 ) {
F_24 ( V_2 , V_4 ) ;
return - V_79 ;
}
V_19 -> V_26 = V_26 ;
V_19 -> V_11 = V_11 ;
F_49 ( & V_26 -> V_32 ) ;
F_2 ( & V_4 -> V_14 ) ;
F_50 ( & V_19 -> V_13 , & V_4 -> V_15 ) ;
F_4 ( & V_4 -> V_14 ) ;
return 0 ;
}
static void F_51 ( struct V_41 * V_47 , int V_14 )
{
int V_9 ;
unsigned long V_65 = V_47 -> V_50 >> V_39 ;
for ( V_9 = 0 ; V_9 < V_47 -> V_58 ; ++ V_9 ) {
struct V_41 * V_80 ;
V_80 = F_26 ( & V_47 -> V_56 [ V_9 ] -> V_51 , V_65 ) ;
if ( V_80 && V_80 -> V_54 != V_47 -> V_54 )
V_80 -> V_53 = V_14 ;
}
}
static int F_52 ( struct V_42 * V_43 )
{
struct V_41 * V_81 = NULL ;
struct V_41 * V_82 = NULL ;
T_1 V_83 = 0 ;
T_1 V_84 = 0 ;
unsigned long V_65 = 0 ;
int V_35 ;
if ( V_43 -> V_85 ) {
F_51 ( V_43 -> V_85 , 0 ) ;
F_22 ( & V_43 -> V_85 -> V_31 , V_74 ) ;
V_43 -> V_85 = NULL ;
}
while ( 1 ) {
struct V_41 * V_47 ;
V_35 = F_29 ( & V_43 -> V_51 ,
( void * * ) & V_47 , V_65 , 1 ) ;
if ( V_35 == 0 )
break;
V_65 = ( V_47 -> V_50 >> V_39 ) + 1 ;
if ( V_47 -> V_53 ) {
if ( V_47 -> V_32 > V_84 ) {
V_84 = V_47 -> V_32 ;
V_82 = V_47 ;
}
} else {
if ( V_47 -> V_32 > V_83 ) {
V_83 = V_47 -> V_32 ;
V_81 = V_47 ;
}
}
}
if ( V_81 )
V_43 -> V_85 = V_81 ;
else if ( V_82 )
V_43 -> V_85 = V_82 ;
else
return 0 ;
V_43 -> V_86 = V_43 -> V_85 -> V_38 ;
F_20 ( & V_43 -> V_85 -> V_31 ) ;
F_51 ( V_43 -> V_85 , 1 ) ;
return 1 ;
}
static int F_53 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_2 ;
struct V_3 * V_4 = NULL ;
int V_87 = 0 ;
struct V_5 * V_6 = NULL ;
T_1 V_44 ;
int V_35 ;
int V_9 ;
F_2 ( & V_2 -> V_36 ) ;
if ( V_43 -> V_85 == NULL ) {
V_35 = F_52 ( V_43 ) ;
if ( ! V_35 ) {
F_4 ( & V_2 -> V_36 ) ;
return 0 ;
}
}
V_35 = F_29 ( & V_43 -> V_77 , ( void * * ) & V_4 ,
V_43 -> V_86 >> V_39 , 1 ) ;
if ( V_35 == 0 || V_4 -> V_44 > V_43 -> V_85 -> V_50 ) {
V_35 = F_52 ( V_43 ) ;
if ( ! V_35 ) {
F_4 ( & V_2 -> V_36 ) ;
return 0 ;
}
V_4 = NULL ;
V_35 = F_29 ( & V_43 -> V_77 , ( void * * ) & V_4 ,
V_43 -> V_86 >> V_39 , 1 ) ;
}
if ( V_35 == 0 ) {
F_4 ( & V_2 -> V_36 ) ;
return 0 ;
}
V_43 -> V_86 = V_4 -> V_44 + V_2 -> V_68 ;
V_4 -> V_31 ++ ;
F_4 ( & V_2 -> V_36 ) ;
F_2 ( & V_4 -> V_14 ) ;
if ( V_4 -> V_16 || F_16 ( & V_4 -> V_15 ) ) {
F_4 ( & V_4 -> V_14 ) ;
F_24 ( V_2 , V_4 ) ;
return 0 ;
}
V_4 -> V_16 = 1 ;
F_4 ( & V_4 -> V_14 ) ;
for ( V_9 = 0 ; V_9 < V_4 -> V_64 ; ++ V_9 ) {
if ( V_4 -> V_73 [ V_9 ] -> V_54 == V_43 ) {
V_87 = V_9 + 1 ;
break;
}
}
V_44 = V_4 -> V_44 ;
F_49 ( & V_43 -> V_88 ) ;
V_35 = F_54 ( V_2 , V_44 , V_87 , & V_6 ) ;
if ( V_35 )
F_1 ( V_2 , V_4 , NULL , V_35 ) ;
else if ( V_6 )
F_1 ( V_2 , V_4 , V_6 , V_35 ) ;
if ( V_6 )
F_55 ( V_6 ) ;
F_56 ( & V_43 -> V_88 ) ;
F_24 ( V_2 , V_4 ) ;
return 1 ;
}
static void F_57 ( struct V_89 * V_90 )
{
struct V_91 * V_92 ;
struct V_1 * V_2 ;
int V_93 ;
V_92 = F_48 ( V_90 , struct V_91 , V_90 ) ;
V_2 = V_92 -> V_2 ;
F_19 ( V_92 ) ;
V_93 = F_58 ( F_59 ( V_94 ) ,
F_60 ( V_94 ) ) ;
F_61 ( V_94 , V_95 ) ;
F_62 ( V_2 ) ;
F_61 ( V_94 , V_93 ) ;
F_56 ( & V_2 -> V_96 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_42 * V_54 ;
struct V_97 * V_98 = V_2 -> V_98 ;
T_1 V_99 ;
T_1 V_100 = 0 ;
int V_9 ;
do {
V_99 = 0 ;
F_63 ( & V_98 -> V_101 ) ;
F_11 (device, &fs_devices->devices, dev_list) {
if ( F_64 ( & V_54 -> V_88 ) <
V_102 )
V_99 += F_53 ( V_54 ) ;
}
F_65 ( & V_98 -> V_101 ) ;
V_100 += V_99 ;
} while ( V_99 && V_100 < 10000 );
if ( V_99 == 0 )
return;
for ( V_9 = 0 ; V_9 < 2 ; ++ V_9 ) {
F_27 ( V_2 ) ;
if ( F_64 ( & V_2 -> V_96 ) >
V_70 * 2 )
break;
}
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_91 * V_92 ;
V_92 = F_32 ( sizeof( * V_92 ) , V_52 ) ;
if ( ! V_92 ) {
F_66 () ;
}
F_67 ( & V_92 -> V_90 , V_103 ,
F_57 , NULL , NULL ) ;
V_92 -> V_2 = V_2 ;
F_68 ( V_2 -> V_104 , & V_92 -> V_90 ) ;
F_49 ( & V_2 -> V_96 ) ;
}
static void F_69 ( struct V_1 * V_2 , int V_105 )
{
struct V_42 * V_54 ;
struct V_97 * V_98 = V_2 -> V_98 ;
unsigned long V_65 ;
int V_35 ;
int V_9 ;
int V_106 ;
int V_107 ;
F_2 ( & V_2 -> V_36 ) ;
F_11 (device, &fs_devices->devices, dev_list) {
F_13 ( V_2 , L_3 , V_54 -> V_108 ,
F_64 ( & V_54 -> V_88 ) ) ;
V_65 = 0 ;
while ( 1 ) {
struct V_41 * V_47 ;
V_35 = F_29 ( & V_54 -> V_51 ,
( void * * ) & V_47 , V_65 , 1 ) ;
if ( V_35 == 0 )
break;
F_70 ( L_4 ,
V_47 -> V_38 , V_47 -> V_50 , V_47 -> V_32 ,
V_47 -> V_53 ) ;
for ( V_106 = 0 ; V_106 < V_47 -> V_58 ; ++ V_106 ) {
F_71 ( L_5 ,
V_47 -> V_56 [ V_106 ] -> V_108 ) ;
}
if ( V_54 -> V_85 == V_47 )
F_71 ( L_6 ,
V_54 -> V_86 - V_47 -> V_38 ) ;
F_71 ( L_7 ) ;
V_65 = ( V_47 -> V_50 >> V_39 ) + 1 ;
}
V_107 = 0 ;
V_65 = 0 ;
while ( V_105 ) {
struct V_3 * V_4 = NULL ;
V_35 = F_29 ( & V_54 -> V_77 ,
( void * * ) & V_4 , V_65 , 1 ) ;
if ( V_35 == 0 )
break;
F_70 ( L_8 ,
V_4 -> V_44 , V_2 -> V_68 ,
F_16 ( & V_4 -> V_15 ) , V_4 -> V_16 ) ;
for ( V_9 = 0 ; V_9 < V_4 -> V_64 ; ++ V_9 ) {
F_71 ( L_9 ,
V_4 -> V_73 [ V_9 ] -> V_38 ,
V_4 -> V_73 [ V_9 ] -> V_50 ) ;
for ( V_106 = 0 ; V_106 < V_4 -> V_73 [ V_9 ] -> V_58 ; ++ V_106 ) {
F_71 ( L_5 ,
V_4 -> V_73 [ V_9 ] -> V_56 [ V_106 ] -> V_108 ) ;
}
}
F_71 ( L_7 ) ;
V_65 = ( V_4 -> V_44 >> V_39 ) + 1 ;
if ( ++ V_107 > 15 )
break;
}
}
V_65 = 0 ;
V_107 = 0 ;
while ( V_105 ) {
struct V_3 * V_4 = NULL ;
V_35 = F_29 ( & V_2 -> V_37 , ( void * * ) & V_4 ,
V_65 , 1 ) ;
if ( V_35 == 0 )
break;
if ( ! V_4 -> V_16 ) {
V_65 = ( V_4 -> V_44 >> V_39 ) + 1 ;
continue;
}
F_70 ( L_10 ,
V_4 -> V_44 , V_2 -> V_68 ,
F_16 ( & V_4 -> V_15 ) , V_4 -> V_16 ) ;
for ( V_9 = 0 ; V_9 < V_4 -> V_64 ; ++ V_9 ) {
F_71 ( L_9 ,
V_4 -> V_73 [ V_9 ] -> V_38 ,
V_4 -> V_73 [ V_9 ] -> V_50 ) ;
for ( V_106 = 0 ; V_106 < V_4 -> V_73 [ V_9 ] -> V_58 ; ++ V_106 ) {
F_71 ( L_5 ,
V_4 -> V_73 [ V_9 ] -> V_56 [ V_106 ] -> V_108 ) ;
}
}
F_71 ( L_7 ) ;
V_65 = ( V_4 -> V_44 >> V_39 ) + 1 ;
}
F_4 ( & V_2 -> V_36 ) ;
}
struct V_25 * F_72 ( struct V_109 * V_110 ,
struct V_21 * V_30 , struct V_21 * V_29 )
{
struct V_25 * V_26 ;
T_1 V_38 ;
T_1 V_11 ;
int V_35 ;
struct V_5 * V_111 ;
static struct V_21 V_112 = {
. V_27 = ( T_1 ) - 1 ,
. type = ( V_113 ) - 1 ,
. V_28 = ( T_1 ) - 1
} ;
V_26 = F_32 ( sizeof( * V_26 ) , V_52 ) ;
if ( ! V_26 )
return F_73 ( - V_79 ) ;
V_26 -> V_2 = V_110 -> V_2 ;
V_26 -> V_30 = * V_30 ;
V_26 -> V_29 = * V_29 ;
F_74 ( & V_26 -> V_32 , 0 ) ;
F_75 ( & V_26 -> V_34 ) ;
F_36 ( & V_26 -> V_31 ) ;
F_20 ( & V_26 -> V_31 ) ;
V_111 = F_76 ( V_110 ) ;
V_38 = V_111 -> V_38 ;
V_11 = F_7 ( V_111 ) ;
F_55 ( V_111 ) ;
V_35 = F_15 ( V_26 , V_38 , & V_112 , V_11 ) ;
if ( V_35 ) {
F_19 ( V_26 ) ;
return F_73 ( V_35 ) ;
}
F_27 ( V_110 -> V_2 ) ;
return V_26 ;
}
int F_77 ( void * V_114 )
{
struct V_25 * V_26 = V_114 ;
struct V_1 * V_2 = V_26 -> V_2 ;
while ( F_64 ( & V_26 -> V_32 ) ) {
if ( ! F_64 ( & V_2 -> V_96 ) )
F_27 ( V_2 ) ;
F_78 ( V_26 -> V_34 , F_64 ( & V_26 -> V_32 ) == 0 ,
5 * V_115 ) ;
F_69 ( V_2 , F_64 ( & V_26 -> V_32 ) < 10 ? 1 : 0 ) ;
}
F_69 ( V_2 , F_64 ( & V_26 -> V_32 ) < 10 ? 1 : 0 ) ;
F_22 ( & V_26 -> V_31 , V_33 ) ;
return 0 ;
}
int F_77 ( void * V_114 )
{
struct V_25 * V_26 = V_114 ;
struct V_1 * V_2 = V_26 -> V_2 ;
while ( F_64 ( & V_26 -> V_32 ) ) {
if ( ! F_64 ( & V_2 -> V_96 ) )
F_27 ( V_2 ) ;
F_78 ( V_26 -> V_34 , F_64 ( & V_26 -> V_32 ) == 0 ,
( V_115 + 9 ) / 10 ) ;
}
F_22 ( & V_26 -> V_31 , V_33 ) ;
return 0 ;
}
void F_79 ( void * V_114 )
{
struct V_25 * V_26 = V_114 ;
F_22 ( & V_26 -> V_31 , V_33 ) ;
}
