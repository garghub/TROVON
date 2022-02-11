static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , int V_6 )
{
int V_7 = 0 ;
int V_8 ;
int V_9 ;
T_1 V_10 ;
T_1 V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_16 V_17 ;
unsigned long V_18 = V_5 >> V_19 ;
struct V_20 * V_21 ;
if ( V_4 )
V_7 = F_2 ( V_4 ) ;
F_3 ( & V_15 -> V_22 ) ;
V_13 = F_4 ( & V_15 -> V_23 , V_18 ) ;
if ( V_13 )
F_5 ( & V_13 -> V_24 ) ;
F_6 ( & V_15 -> V_22 ) ;
if ( ! V_13 )
return - 1 ;
F_3 ( & V_13 -> V_25 ) ;
F_7 ( & V_13 -> V_26 , & V_17 ) ;
V_21 = V_13 -> V_27 ;
V_13 -> V_27 = NULL ;
F_6 ( & V_13 -> V_25 ) ;
if ( V_6 == 0 ) {
V_8 = V_7 ? F_8 ( V_4 ) : 0 ;
V_11 = F_9 ( V_4 ) ;
} else {
V_8 = 0 ;
V_11 = 0 ;
}
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ ) {
struct V_28 * V_29 ;
T_1 V_30 ;
struct V_31 V_32 ;
struct V_31 V_33 ;
F_10 ( V_4 , & V_32 , V_9 ) ;
if ( V_9 + 1 < V_8 )
F_10 ( V_4 , & V_33 , V_9 + 1 ) ;
else
V_33 = V_13 -> V_34 ;
V_10 = F_11 ( V_4 , V_9 ) ;
V_30 = F_12 ( V_4 , V_9 ) ;
F_13 (rec, &list, list) {
struct V_35 * V_36 = V_29 -> V_36 ;
#ifdef F_14
if ( V_29 -> V_11 != V_11 ) {
F_15 ( V_37 L_1
L_2 ,
V_32 . V_38 , V_32 . type , V_32 . V_39 ,
V_29 -> V_11 , V_11 ) ;
}
#endif
if ( V_29 -> V_11 == V_11 &&
F_16 ( & V_32 , & V_36 -> V_40 ) < 0 &&
F_16 ( & V_33 , & V_36 -> V_41 ) > 0 )
F_17 ( V_36 , V_10 , & V_33 ,
V_7 - 1 , V_30 ) ;
}
}
while ( ! F_18 ( & V_17 ) ) {
struct V_35 * V_36 ;
struct V_28 * V_29 ;
V_29 = F_19 ( & V_17 , struct V_28 , V_17 ) ;
F_20 ( & V_29 -> V_17 ) ;
V_36 = V_29 -> V_36 ;
F_21 ( V_29 ) ;
F_5 ( & V_36 -> V_24 ) ;
if ( F_22 ( & V_36 -> V_42 ) ) {
F_23 ( & V_36 -> V_24 , V_43 ) ;
F_24 ( & V_36 -> V_44 ) ;
}
F_23 ( & V_36 -> V_24 , V_43 ) ;
F_25 ( V_15 , V_13 ) ;
}
F_25 ( V_15 , V_13 ) ;
if ( V_21 )
F_26 ( & V_21 -> V_45 ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , int V_6 )
{
int V_46 ;
V_46 = F_1 ( V_2 , V_4 , V_5 , V_6 ) ;
F_28 ( V_2 -> V_15 ) ;
return V_46 ;
}
static struct V_47 * F_29 ( struct V_14 * V_15 ,
struct V_20 * V_48 , T_1 V_49 ,
struct V_50 * V_51 )
{
int V_46 ;
int V_52 = 0 ;
struct V_47 * V_53 ;
struct V_54 * V_55 = NULL ;
T_1 V_5 ;
T_1 V_56 ;
int V_9 ;
V_57:
V_53 = NULL ;
F_3 ( & V_15 -> V_22 ) ;
V_46 = F_30 ( & V_48 -> V_58 , ( void * * ) & V_53 ,
V_49 >> V_19 , 1 ) ;
if ( V_46 == 1 )
F_5 ( & V_53 -> V_24 ) ;
F_6 ( & V_15 -> V_22 ) ;
if ( V_46 == 1 ) {
if ( V_49 >= V_53 -> V_5 && V_49 < V_53 -> V_56 )
return V_53 ;
F_3 ( & V_15 -> V_22 ) ;
F_23 ( & V_53 -> V_24 , V_59 ) ;
F_6 ( & V_15 -> V_22 ) ;
}
if ( V_52 )
return NULL ;
V_55 = F_31 ( V_15 , V_49 ) ;
if ( ! V_55 )
return NULL ;
V_5 = V_55 -> V_32 . V_38 ;
V_56 = V_5 + V_55 -> V_32 . V_39 - 1 ;
F_32 ( V_55 ) ;
V_53 = F_33 ( sizeof( * V_53 ) , V_60 ) ;
if ( ! V_53 )
return NULL ;
V_53 -> V_5 = V_5 ;
V_53 -> V_56 = V_56 ;
F_34 ( & V_53 -> V_17 ) ;
F_35 ( & V_53 -> V_25 ) ;
V_53 -> V_61 = 0 ;
F_36 ( & V_53 -> V_24 ) ;
V_53 -> V_42 = 0 ;
V_53 -> V_62 = V_48 ;
for ( V_9 = 0 ; V_9 < V_51 -> V_63 ; ++ V_9 ) {
V_53 -> V_64 [ V_9 ] = V_51 -> V_65 [ V_9 ] . V_48 ;
}
V_53 -> V_66 = V_51 -> V_63 ;
F_3 ( & V_15 -> V_22 ) ;
V_46 = F_37 ( & V_48 -> V_58 ,
( unsigned long ) V_53 -> V_56 >> V_19 ,
V_53 ) ;
F_6 ( & V_15 -> V_22 ) ;
if ( V_46 ) {
F_21 ( V_53 ) ;
V_52 = 1 ;
goto V_57;
}
return V_53 ;
}
static struct V_12 * F_38 ( struct V_1 * V_2 ,
T_1 V_49 ,
struct V_31 * V_34 , int V_7 )
{
int V_46 ;
int V_52 = 0 ;
struct V_12 * V_13 = NULL ;
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_67 * V_68 = & V_15 -> V_69 ;
struct V_50 * V_51 = NULL ;
struct V_20 * V_48 ;
T_2 V_70 ;
T_1 V_71 ;
int V_72 = 0 ;
int V_9 ;
unsigned long V_18 = V_49 >> V_19 ;
V_57:
F_3 ( & V_15 -> V_22 ) ;
V_13 = F_4 ( & V_15 -> V_23 , V_18 ) ;
if ( V_13 )
F_5 ( & V_13 -> V_24 ) ;
F_6 ( & V_15 -> V_22 ) ;
if ( V_13 || V_52 )
return V_13 ;
V_13 = F_33 ( sizeof( * V_13 ) , V_60 ) ;
if ( ! V_13 )
return NULL ;
V_70 = F_39 ( V_2 , V_7 ) ;
V_13 -> V_49 = V_49 ;
V_13 -> V_70 = V_70 ;
V_13 -> V_34 = * V_34 ;
F_34 ( & V_13 -> V_26 ) ;
F_35 ( & V_13 -> V_25 ) ;
F_36 ( & V_13 -> V_24 ) ;
V_71 = V_70 ;
V_46 = F_40 ( V_68 , V_73 , V_49 , & V_71 , & V_51 , 0 ) ;
if ( V_46 || ! V_51 || V_71 < V_70 )
goto error;
if ( V_51 -> V_63 > V_74 ) {
F_15 ( V_75 L_3
L_4 , V_74 ) ;
goto error;
}
for ( V_72 = 0 ; V_72 < V_51 -> V_63 ; ++ V_72 ) {
struct V_47 * V_53 ;
V_48 = V_51 -> V_65 [ V_72 ] . V_48 ;
V_53 = F_29 ( V_15 , V_48 , V_49 , V_51 ) ;
if ( ! V_53 )
break;
V_13 -> V_76 [ V_72 ] = V_53 ;
F_3 ( & V_53 -> V_25 ) ;
if ( ! V_53 -> V_42 )
F_5 ( & V_53 -> V_24 ) ;
++ V_53 -> V_42 ;
F_6 ( & V_53 -> V_25 ) ;
F_3 ( & V_15 -> V_22 ) ;
F_23 ( & V_53 -> V_24 , V_59 ) ;
F_6 ( & V_15 -> V_22 ) ;
}
V_13 -> V_72 = V_72 ;
if ( V_72 == 0 ) {
goto error;
}
F_3 ( & V_15 -> V_22 ) ;
V_46 = F_37 ( & V_15 -> V_23 , V_18 , V_13 ) ;
if ( V_46 ) {
F_6 ( & V_15 -> V_22 ) ;
if ( V_46 != - V_77 ) {
V_52 = 1 ;
}
goto error;
}
for ( V_9 = 0 ; V_9 < V_72 ; ++ V_9 ) {
V_48 = V_51 -> V_65 [ V_9 ] . V_48 ;
V_46 = F_37 ( & V_48 -> V_78 , V_18 , V_13 ) ;
if ( V_46 ) {
while ( -- V_9 >= 0 ) {
V_48 = V_51 -> V_65 [ V_9 ] . V_48 ;
F_41 ( V_48 == NULL ) ;
F_42 ( & V_48 -> V_78 , V_18 ) ;
}
F_41 ( V_15 == NULL ) ;
F_42 ( & V_15 -> V_23 , V_18 ) ;
F_6 ( & V_15 -> V_22 ) ;
goto error;
}
}
F_6 ( & V_15 -> V_22 ) ;
F_21 ( V_51 ) ;
return V_13 ;
error:
while ( V_72 ) {
struct V_47 * V_53 ;
-- V_72 ;
V_53 = V_13 -> V_76 [ V_72 ] ;
F_5 ( & V_53 -> V_24 ) ;
F_3 ( & V_53 -> V_25 ) ;
-- V_53 -> V_42 ;
if ( V_53 -> V_42 == 0 ) {
F_23 ( & V_53 -> V_24 , V_59 ) ;
}
F_6 ( & V_53 -> V_25 ) ;
F_3 ( & V_15 -> V_22 ) ;
F_23 ( & V_53 -> V_24 , V_59 ) ;
F_6 ( & V_15 -> V_22 ) ;
}
F_21 ( V_51 ) ;
F_21 ( V_13 ) ;
if ( V_52 )
goto V_57;
return NULL ;
}
static void F_43 ( struct V_79 * V_80 )
{
}
static void F_25 ( struct V_14 * V_15 ,
struct V_12 * V_13 )
{
int V_9 ;
unsigned long V_18 = V_13 -> V_49 >> V_19 ;
F_3 ( & V_15 -> V_22 ) ;
if ( ! F_23 ( & V_13 -> V_24 , F_43 ) ) {
F_6 ( & V_15 -> V_22 ) ;
return;
}
F_42 ( & V_15 -> V_23 , V_18 ) ;
for ( V_9 = 0 ; V_9 < V_13 -> V_72 ; ++ V_9 ) {
struct V_47 * V_53 = V_13 -> V_76 [ V_9 ] ;
F_42 ( & V_53 -> V_62 -> V_78 , V_18 ) ;
}
F_6 ( & V_15 -> V_22 ) ;
for ( V_9 = 0 ; V_9 < V_13 -> V_72 ; ++ V_9 ) {
struct V_47 * V_53 = V_13 -> V_76 [ V_9 ] ;
F_5 ( & V_53 -> V_24 ) ;
F_3 ( & V_53 -> V_25 ) ;
-- V_53 -> V_42 ;
if ( V_53 -> V_42 == 0 ) {
F_23 ( & V_53 -> V_24 , V_59 ) ;
}
F_6 ( & V_53 -> V_25 ) ;
F_3 ( & V_15 -> V_22 ) ;
F_23 ( & V_53 -> V_24 , V_59 ) ;
F_6 ( & V_15 -> V_22 ) ;
}
if ( V_13 -> V_27 )
F_26 ( & V_13 -> V_27 -> V_45 ) ;
F_21 ( V_13 ) ;
}
static void V_59 ( struct V_79 * V_79 )
{
struct V_47 * V_53 = F_44 ( V_79 , struct V_47 , V_24 ) ;
F_42 ( & V_53 -> V_62 -> V_58 ,
V_53 -> V_56 >> V_19 ) ;
F_21 ( V_53 ) ;
}
static void V_43 ( struct V_79 * V_79 )
{
struct V_35 * V_36 = F_44 ( V_79 , struct V_35 ,
V_24 ) ;
F_21 ( V_36 ) ;
}
static int F_17 ( struct V_35 * V_36 , T_1 V_49 ,
struct V_31 * V_34 , int V_7 , T_1 V_11 )
{
struct V_1 * V_2 = V_36 -> V_2 ;
struct V_12 * V_13 ;
struct V_28 * V_29 ;
V_13 = F_38 ( V_2 , V_49 , V_34 , V_7 ) ;
if ( ! V_13 )
return - 1 ;
V_29 = F_33 ( sizeof( * V_29 ) , V_60 ) ;
if ( ! V_29 ) {
F_25 ( V_2 -> V_15 , V_13 ) ;
return - 1 ;
}
V_29 -> V_36 = V_36 ;
V_29 -> V_11 = V_11 ;
F_45 ( & V_36 -> V_42 ) ;
F_3 ( & V_13 -> V_25 ) ;
F_46 ( & V_29 -> V_17 , & V_13 -> V_26 ) ;
F_6 ( & V_13 -> V_25 ) ;
return 0 ;
}
static void F_47 ( struct V_47 * V_53 , int V_25 )
{
int V_9 ;
unsigned long V_18 = V_53 -> V_56 >> V_19 ;
for ( V_9 = 0 ; V_9 < V_53 -> V_66 ; ++ V_9 ) {
struct V_47 * V_81 ;
V_81 = F_4 ( & V_53 -> V_64 [ V_9 ] -> V_58 , V_18 ) ;
if ( V_81 && V_81 -> V_62 != V_53 -> V_62 )
V_81 -> V_61 = V_25 ;
}
}
static int F_48 ( struct V_20 * V_48 )
{
struct V_47 * V_82 = NULL ;
struct V_47 * V_83 = NULL ;
T_1 V_84 = 0 ;
T_1 V_85 = 0 ;
unsigned long V_18 = 0 ;
int V_46 ;
if ( V_48 -> V_86 ) {
F_47 ( V_48 -> V_86 , 0 ) ;
F_23 ( & V_48 -> V_86 -> V_24 , V_59 ) ;
V_48 -> V_86 = NULL ;
}
while ( 1 ) {
struct V_47 * V_53 ;
V_46 = F_30 ( & V_48 -> V_58 ,
( void * * ) & V_53 , V_18 , 1 ) ;
if ( V_46 == 0 )
break;
V_18 = ( V_53 -> V_56 >> V_19 ) + 1 ;
if ( V_53 -> V_61 ) {
if ( V_53 -> V_42 > V_85 ) {
V_85 = V_53 -> V_42 ;
V_83 = V_53 ;
}
} else {
if ( V_53 -> V_42 > V_84 ) {
V_84 = V_53 -> V_42 ;
V_82 = V_53 ;
}
}
}
if ( V_82 )
V_48 -> V_86 = V_82 ;
else if ( V_83 )
V_48 -> V_86 = V_83 ;
else
return 0 ;
V_48 -> V_87 = V_48 -> V_86 -> V_5 ;
F_5 ( & V_48 -> V_86 -> V_24 ) ;
F_47 ( V_48 -> V_86 , 1 ) ;
return 1 ;
}
static int F_49 ( struct V_14 * V_15 ,
struct V_20 * V_48 )
{
struct V_12 * V_13 = NULL ;
int V_88 = 0 ;
struct V_3 * V_4 = NULL ;
T_1 V_49 ;
T_2 V_70 ;
int V_46 ;
int V_9 ;
int V_89 = 0 ;
F_3 ( & V_15 -> V_22 ) ;
if ( V_48 -> V_86 == NULL ) {
V_46 = F_48 ( V_48 ) ;
if ( ! V_46 ) {
F_6 ( & V_15 -> V_22 ) ;
return 0 ;
}
}
V_46 = F_30 ( & V_48 -> V_78 , ( void * * ) & V_13 ,
V_48 -> V_87 >> V_19 , 1 ) ;
if ( V_46 == 0 || V_13 -> V_49 >= V_48 -> V_86 -> V_56 ) {
V_46 = F_48 ( V_48 ) ;
if ( ! V_46 ) {
F_6 ( & V_15 -> V_22 ) ;
return 0 ;
}
V_13 = NULL ;
V_46 = F_30 ( & V_48 -> V_78 , ( void * * ) & V_13 ,
V_48 -> V_87 >> V_19 , 1 ) ;
}
if ( V_46 == 0 ) {
F_6 ( & V_15 -> V_22 ) ;
return 0 ;
}
V_48 -> V_87 = V_13 -> V_49 + V_13 -> V_70 ;
F_5 ( & V_13 -> V_24 ) ;
F_6 ( & V_15 -> V_22 ) ;
for ( V_9 = 0 ; V_9 < V_13 -> V_72 ; ++ V_9 ) {
if ( V_13 -> V_76 [ V_9 ] -> V_62 == V_48 ) {
V_88 = V_9 + 1 ;
break;
}
}
V_49 = V_13 -> V_49 ;
V_70 = V_13 -> V_70 ;
F_3 ( & V_13 -> V_25 ) ;
if ( V_13 -> V_27 == NULL ) {
V_13 -> V_27 = V_48 ;
V_89 = 1 ;
}
F_6 ( & V_13 -> V_25 ) ;
F_25 ( V_15 , V_13 ) ;
if ( ! V_89 )
return 0 ;
F_45 ( & V_48 -> V_45 ) ;
V_46 = F_50 ( V_15 -> V_90 , V_49 , V_70 ,
V_88 , & V_4 ) ;
if ( V_46 )
F_1 ( V_15 -> V_90 , NULL , V_49 , V_46 ) ;
else if ( V_4 )
F_1 ( V_15 -> V_90 , V_4 , V_4 -> V_5 , V_46 ) ;
if ( V_4 )
F_51 ( V_4 ) ;
return 1 ;
}
static void F_52 ( struct V_91 * V_92 )
{
struct V_93 * V_94 ;
struct V_14 * V_15 ;
V_94 = F_44 ( V_92 , struct V_93 , V_92 ) ;
V_15 = V_94 -> V_15 ;
F_21 ( V_94 ) ;
F_53 ( V_15 ) ;
}
static void F_53 ( struct V_14 * V_15 )
{
struct V_20 * V_62 ;
struct V_95 * V_96 = V_15 -> V_96 ;
T_1 V_97 ;
T_1 V_98 = 0 ;
int V_9 ;
do {
V_97 = 0 ;
F_13 (device, &fs_devices->devices, dev_list) {
if ( F_54 ( & V_62 -> V_45 ) <
V_99 )
V_97 += F_49 ( V_15 ,
V_62 ) ;
}
V_98 += V_97 ;
} while ( V_97 && V_98 < 10000 );
if ( V_97 == 0 )
return;
for ( V_9 = 0 ; V_9 < 2 ; ++ V_9 )
F_28 ( V_15 ) ;
}
static void F_28 ( struct V_14 * V_15 )
{
struct V_93 * V_94 ;
V_94 = F_33 ( sizeof( * V_94 ) , V_60 ) ;
if ( ! V_94 ) {
F_55 () ;
}
V_94 -> V_92 . V_100 = F_52 ;
V_94 -> V_15 = V_15 ;
F_56 ( & V_15 -> V_101 , & V_94 -> V_92 ) ;
}
static void F_57 ( struct V_14 * V_15 , int V_102 )
{
struct V_20 * V_62 ;
struct V_95 * V_96 = V_15 -> V_96 ;
unsigned long V_18 ;
int V_46 ;
int V_9 ;
int V_103 ;
int V_104 ;
F_3 ( & V_15 -> V_22 ) ;
F_13 (device, &fs_devices->devices, dev_list) {
F_15 ( V_37 L_5 , V_62 -> V_105 ,
F_54 ( & V_62 -> V_45 ) ) ;
V_18 = 0 ;
while ( 1 ) {
struct V_47 * V_53 ;
V_46 = F_30 ( & V_62 -> V_58 ,
( void * * ) & V_53 , V_18 , 1 ) ;
if ( V_46 == 0 )
break;
F_15 ( V_37 L_6
L_7 , V_53 -> V_5 , V_53 -> V_56 , V_53 -> V_42 ,
V_53 -> V_61 ) ;
for ( V_103 = 0 ; V_103 < V_53 -> V_66 ; ++ V_103 ) {
F_15 ( V_106 L_8 ,
V_53 -> V_64 [ V_103 ] -> V_105 ) ;
}
if ( V_62 -> V_86 == V_53 )
F_15 ( V_106 L_9 ,
V_62 -> V_87 - V_53 -> V_5 ) ;
F_15 ( V_106 L_10 ) ;
V_18 = ( V_53 -> V_56 >> V_19 ) + 1 ;
}
V_104 = 0 ;
V_18 = 0 ;
while ( V_102 ) {
struct V_12 * V_13 = NULL ;
V_46 = F_30 ( & V_62 -> V_78 ,
( void * * ) & V_13 , V_18 , 1 ) ;
if ( V_46 == 0 )
break;
F_15 ( V_37
L_11 ,
V_13 -> V_49 , V_13 -> V_70 ,
F_18 ( & V_13 -> V_26 ) , V_13 -> V_27 ?
V_13 -> V_27 -> V_105 : - 1 ) ;
for ( V_9 = 0 ; V_9 < V_13 -> V_72 ; ++ V_9 ) {
F_15 ( V_106 L_12 ,
V_13 -> V_76 [ V_9 ] -> V_5 ,
V_13 -> V_76 [ V_9 ] -> V_56 ) ;
for ( V_103 = 0 ; V_103 < V_13 -> V_76 [ V_9 ] -> V_66 ; ++ V_103 ) {
F_15 ( V_106 L_8 ,
V_13 -> V_76 [ V_9 ] -> V_64 [ V_103 ] -> V_105 ) ;
}
}
F_15 ( V_106 L_10 ) ;
V_18 = ( V_13 -> V_49 >> V_19 ) + 1 ;
if ( ++ V_104 > 15 )
break;
}
}
V_18 = 0 ;
V_104 = 0 ;
while ( V_102 ) {
struct V_12 * V_13 = NULL ;
V_46 = F_30 ( & V_15 -> V_23 , ( void * * ) & V_13 ,
V_18 , 1 ) ;
if ( V_46 == 0 )
break;
if ( ! V_13 -> V_27 ) {
V_18 = ( V_13 -> V_49 >> V_19 ) + 1 ;
continue;
}
F_15 ( V_37
L_13 ,
V_13 -> V_49 , V_13 -> V_70 , F_18 ( & V_13 -> V_26 ) ,
V_13 -> V_27 ? V_13 -> V_27 -> V_105 : - 1 ) ;
for ( V_9 = 0 ; V_9 < V_13 -> V_72 ; ++ V_9 ) {
F_15 ( V_106 L_12 ,
V_13 -> V_76 [ V_9 ] -> V_5 ,
V_13 -> V_76 [ V_9 ] -> V_56 ) ;
for ( V_9 = 0 ; V_9 < V_13 -> V_72 ; ++ V_9 ) {
F_15 ( V_106 L_12 ,
V_13 -> V_76 [ V_9 ] -> V_5 ,
V_13 -> V_76 [ V_9 ] -> V_56 ) ;
for ( V_103 = 0 ; V_103 < V_13 -> V_76 [ V_9 ] -> V_66 ; ++ V_103 ) {
F_15 ( V_106 L_8 ,
V_13 -> V_76 [ V_9 ] -> V_64 [ V_103 ] -> V_105 ) ;
}
}
}
F_15 ( V_106 L_10 ) ;
V_18 = ( V_13 -> V_49 >> V_19 ) + 1 ;
}
F_6 ( & V_15 -> V_22 ) ;
}
struct V_35 * F_58 ( struct V_1 * V_2 ,
struct V_31 * V_41 , struct V_31 * V_40 )
{
struct V_35 * V_36 ;
T_1 V_5 ;
T_1 V_11 ;
int V_7 ;
struct V_3 * V_107 ;
static struct V_31 V_108 = {
. V_38 = ( T_1 ) - 1 ,
. type = ( V_109 ) - 1 ,
. V_39 = ( T_1 ) - 1
} ;
V_36 = F_33 ( sizeof( * V_36 ) , V_60 ) ;
if ( ! V_36 )
return F_59 ( - V_77 ) ;
V_36 -> V_2 = V_2 ;
V_36 -> V_41 = * V_41 ;
V_36 -> V_40 = * V_40 ;
F_60 ( & V_36 -> V_42 , 0 ) ;
F_61 ( & V_36 -> V_44 ) ;
F_36 ( & V_36 -> V_24 ) ;
F_5 ( & V_36 -> V_24 ) ;
V_107 = F_62 ( V_2 ) ;
V_5 = V_107 -> V_5 ;
V_7 = F_2 ( V_107 ) ;
V_11 = F_9 ( V_107 ) ;
F_51 ( V_107 ) ;
F_17 ( V_36 , V_5 , & V_108 , V_7 , V_11 ) ;
F_28 ( V_2 -> V_15 ) ;
return V_36 ;
}
int F_63 ( void * V_110 )
{
struct V_35 * V_36 = V_110 ;
while ( F_54 ( & V_36 -> V_42 ) ) {
F_64 ( V_36 -> V_44 , F_54 ( & V_36 -> V_42 ) == 0 ,
5 * V_111 ) ;
F_57 ( V_36 -> V_2 -> V_15 , V_36 -> V_42 < 10 ? 1 : 0 ) ;
}
F_57 ( V_36 -> V_2 -> V_15 , V_36 -> V_42 < 10 ? 1 : 0 ) ;
F_23 ( & V_36 -> V_24 , V_43 ) ;
return 0 ;
}
int F_63 ( void * V_110 )
{
struct V_35 * V_36 = V_110 ;
while ( F_54 ( & V_36 -> V_42 ) ) {
F_65 ( V_36 -> V_44 , F_54 ( & V_36 -> V_42 ) == 0 ) ;
}
F_23 ( & V_36 -> V_24 , V_43 ) ;
return 0 ;
}
void F_66 ( void * V_110 )
{
struct V_35 * V_36 = V_110 ;
F_23 ( & V_36 -> V_24 , V_43 ) ;
}
