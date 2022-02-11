static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 ) {
V_2 -> V_4 = F_2 ( V_2 -> V_3 ) ;
F_3 ( L_1 , V_2 -> V_4 ) ;
}
}
static void F_4 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 ) {
F_5 ( V_2 -> V_4 ) ;
V_2 -> V_4 = 0 ;
}
}
static void F_6 ( struct V_1 * V_2 , int V_5 )
{
if ( V_2 -> V_4 ) {
F_3 ( L_2 , V_5 ) ;
F_7 ( V_2 -> V_4 , V_5 ) ;
}
}
static void F_1 ( struct V_1 * V_2 ) {}
static void F_4 ( struct V_1 * V_2 ) {}
static void F_6 ( struct V_1 * V_2 , int V_5 ) {}
static int F_8 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 = 0 ;
if ( V_2 -> V_9 ) {
V_8 = F_9 ( V_2 -> V_9 ) ;
if ( V_8 ) {
F_10 ( V_7 -> V_7 , L_3 , V_8 ) ;
return V_8 ;
}
}
if ( V_2 -> V_10 ) {
V_8 = F_9 ( V_2 -> V_10 ) ;
if ( V_8 ) {
F_10 ( V_7 -> V_7 , L_4 , V_8 ) ;
return V_8 ;
}
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 )
F_12 ( V_2 -> V_10 ) ;
if ( V_2 -> V_9 )
F_12 ( V_2 -> V_9 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = NULL ;
int V_13 ;
for ( V_13 = F_14 ( V_2 -> V_14 ) - 1 ; V_13 > 0 ; V_13 -- ) {
if ( V_2 -> V_14 [ V_13 ] ) {
F_15 ( V_2 -> V_14 [ V_13 ] ) ;
V_12 = V_2 -> V_14 [ V_13 ] ;
}
}
if ( V_12 && V_2 -> V_15 )
F_16 ( V_12 , V_2 -> V_15 ) ;
for ( V_13 = F_14 ( V_2 -> V_14 ) - 1 ; V_13 > 0 ; V_13 -- )
if ( V_2 -> V_14 [ V_13 ] )
F_17 ( V_2 -> V_14 [ V_13 ] ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = NULL ;
int V_13 ;
for ( V_13 = F_14 ( V_2 -> V_14 ) - 1 ; V_13 > 0 ; V_13 -- ) {
if ( V_2 -> V_14 [ V_13 ] ) {
F_19 ( V_2 -> V_14 [ V_13 ] ) ;
V_12 = V_2 -> V_14 [ V_13 ] ;
}
}
if ( V_12 && V_2 -> V_16 )
F_16 ( V_12 , V_2 -> V_16 ) ;
for ( V_13 = F_14 ( V_2 -> V_14 ) - 1 ; V_13 > 0 ; V_13 -- )
if ( V_2 -> V_14 [ V_13 ] )
F_20 ( V_2 -> V_14 [ V_13 ] ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
if ( V_2 -> V_17 )
F_22 ( V_2 -> V_17 ) ;
if ( V_2 -> V_18 )
F_6 ( V_2 , V_2 -> V_18 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
if ( V_2 -> V_17 )
F_24 ( V_2 -> V_17 ) ;
if ( V_2 -> V_18 )
F_6 ( V_2 , 0 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
F_3 ( L_5 , V_2 -> V_19 , V_2 -> V_20 ) ;
F_26 ( ! F_27 ( & V_7 -> V_21 ) ) ;
if ( V_2 -> V_20 ++ > 0 )
return 0 ;
if ( F_26 ( V_2 -> V_20 <= 0 ) )
return - V_22 ;
V_8 = F_8 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_13 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_21 ( V_2 ) ;
if ( V_8 )
return V_8 ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
F_3 ( L_5 , V_2 -> V_19 , V_2 -> V_20 ) ;
F_26 ( ! F_27 ( & V_7 -> V_21 ) ) ;
if ( -- V_2 -> V_20 > 0 )
return 0 ;
if ( F_26 ( V_2 -> V_20 < 0 ) )
return - V_22 ;
V_8 = F_23 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_18 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_11 ( V_2 ) ;
if ( V_8 )
return V_8 ;
return 0 ;
}
static void F_29 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_30 ( V_24 , struct V_1 , V_25 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
if ( V_2 -> V_26 )
return;
F_3 ( L_6 , V_2 -> V_19 ) ;
F_31 ( & V_7 -> V_21 ) ;
if ( ! ( F_32 ( V_2 ) || V_2 -> V_26 ) ) {
F_23 ( V_2 ) ;
F_18 ( V_2 ) ;
V_2 -> V_26 = true ;
}
F_33 ( & V_7 -> V_21 ) ;
}
static void F_34 ( unsigned long V_27 )
{
struct V_1 * V_2 = (struct V_1 * ) V_27 ;
struct V_28 * V_29 = V_2 -> V_7 -> V_30 ;
F_35 ( V_29 -> V_31 , & V_2 -> V_25 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_3 ( L_7 , V_2 -> V_19 ) ;
F_37 ( & V_2 -> V_32 ) ;
if ( V_2 -> V_26 ) {
F_13 ( V_2 ) ;
F_21 ( V_2 ) ;
V_2 -> V_26 = false ;
}
}
static void F_38 ( struct V_1 * V_2 )
{
F_3 ( L_7 , V_2 -> V_19 ) ;
F_39 ( & V_2 -> V_32 ,
F_40 ( V_33 + V_34 ) ) ;
}
static void F_41 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_30 ( V_24 , struct V_1 , V_35 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_10 ( V_7 -> V_7 , L_8 , V_2 -> V_19 ) ;
F_31 ( & V_7 -> V_21 ) ;
if ( F_32 ( V_2 ) ) {
struct V_36 * V_37 ;
T_1 V_38 = V_2 -> V_39 -> V_40 ( V_2 ) ;
F_42 ( V_2 , V_38 + 1 ) ;
F_36 ( V_2 ) ;
V_2 -> V_39 -> V_41 ( V_2 ) ;
F_43 (submit, &gpu->submit_list, node) {
V_2 -> V_39 -> V_37 ( V_2 , V_37 , NULL ) ;
}
}
F_33 ( & V_7 -> V_21 ) ;
F_44 ( V_2 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_3 ( L_7 , V_2 -> V_19 ) ;
F_39 ( & V_2 -> V_42 ,
F_40 ( V_33 + V_43 ) ) ;
}
static void F_46 ( unsigned long V_27 )
{
struct V_1 * V_2 = (struct V_1 * ) V_27 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_28 * V_29 = V_7 -> V_30 ;
T_1 V_38 = V_2 -> V_39 -> V_40 ( V_2 ) ;
if ( V_38 != V_2 -> V_44 ) {
V_2 -> V_44 = V_38 ;
} else if ( V_38 < V_2 -> V_45 ) {
V_2 -> V_44 = V_38 ;
F_10 ( V_7 -> V_7 , L_9 ,
V_2 -> V_19 ) ;
F_10 ( V_7 -> V_7 , L_10 ,
V_2 -> V_19 , V_38 ) ;
F_10 ( V_7 -> V_7 , L_11 ,
V_2 -> V_19 , V_2 -> V_45 ) ;
F_35 ( V_29 -> V_31 , & V_2 -> V_35 ) ;
}
if ( V_2 -> V_45 > V_2 -> V_44 )
F_45 ( V_2 ) ;
F_35 ( V_29 -> V_31 , & V_2 -> V_46 ) ;
}
static int F_47 ( struct V_1 * V_2 , T_1 V_47 , T_1 * V_48 )
{
T_1 V_49 [ F_14 ( V_2 -> V_50 ) ] ;
int V_13 , V_51 = F_48 ( V_47 , V_2 -> V_52 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_52 ; V_13 ++ )
V_49 [ V_13 ] = F_49 ( V_2 , V_2 -> V_53 [ V_13 ] . V_54 ) ;
for ( V_13 = 0 ; V_13 < V_51 ; V_13 ++ )
V_48 [ V_13 ] = V_49 [ V_13 ] - V_2 -> V_50 [ V_13 ] ;
for ( V_13 = 0 ; V_13 < V_2 -> V_52 ; V_13 ++ )
V_2 -> V_50 [ V_13 ] = V_49 [ V_13 ] ;
return V_51 ;
}
static void F_50 ( struct V_1 * V_2 )
{
T_2 time ;
T_1 V_55 ;
unsigned long V_56 ;
F_51 ( & V_2 -> V_57 , V_56 ) ;
if ( ! V_2 -> V_58 )
goto V_59;
time = F_52 () ;
V_55 = F_53 ( F_54 ( time , V_2 -> V_60 . time ) ) ;
V_2 -> V_61 += V_55 ;
if ( V_2 -> V_60 . V_62 )
V_2 -> V_63 += V_55 ;
V_2 -> V_60 . V_62 = F_32 ( V_2 ) ;
V_2 -> V_60 . time = time ;
V_59:
F_55 ( & V_2 -> V_57 , V_56 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
unsigned long V_56 ;
F_51 ( & V_2 -> V_57 , V_56 ) ;
V_2 -> V_60 . V_62 = F_32 ( V_2 ) ;
V_2 -> V_60 . time = F_52 () ;
V_2 -> V_63 = V_2 -> V_61 = 0 ;
V_2 -> V_58 = true ;
F_47 ( V_2 , 0 , NULL ) ;
F_55 ( & V_2 -> V_57 , V_56 ) ;
}
void F_57 ( struct V_1 * V_2 )
{
V_2 -> V_58 = false ;
}
int F_58 ( struct V_1 * V_2 , T_1 * V_63 ,
T_1 * V_61 , T_1 V_47 , T_1 * V_48 )
{
unsigned long V_56 ;
int V_8 ;
F_51 ( & V_2 -> V_57 , V_56 ) ;
if ( ! V_2 -> V_58 ) {
V_8 = - V_22 ;
goto V_59;
}
* V_63 = V_2 -> V_63 ;
* V_61 = V_2 -> V_61 ;
V_2 -> V_63 = V_2 -> V_61 = 0 ;
V_8 = F_47 ( V_2 , V_47 , V_48 ) ;
V_59:
F_55 ( & V_2 -> V_57 , V_56 ) ;
return V_8 ;
}
static void F_42 ( struct V_1 * V_2 , T_1 V_38 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
F_26 ( ! F_27 ( & V_7 -> V_21 ) ) ;
while ( ! F_59 ( & V_2 -> V_64 ) ) {
struct V_36 * V_37 ;
V_37 = F_60 ( & V_2 -> V_64 ,
struct V_36 , V_65 ) ;
if ( V_37 -> V_38 <= V_38 ) {
F_61 ( & V_37 -> V_65 ) ;
F_62 ( V_37 ) ;
} else {
break;
}
}
}
static void F_63 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_30 ( V_24 , struct V_1 , V_46 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
T_1 V_38 = V_2 -> V_39 -> V_40 ( V_2 ) ;
F_64 ( V_2 -> V_7 , V_38 ) ;
F_31 ( & V_7 -> V_21 ) ;
F_42 ( V_2 , V_38 ) ;
while ( ! F_59 ( & V_2 -> V_66 ) ) {
struct V_67 * V_68 ;
V_68 = F_60 ( & V_2 -> V_66 ,
struct V_67 , V_69 ) ;
if ( ( V_68 -> V_70 <= V_38 ) &&
( V_68 -> V_71 <= V_38 ) ) {
F_65 ( & V_68 -> V_72 ) ;
F_66 ( & V_68 -> V_72 , V_2 -> V_73 ) ;
F_67 ( & V_68 -> V_72 ) ;
} else {
break;
}
}
F_33 ( & V_7 -> V_21 ) ;
if ( ! F_32 ( V_2 ) )
F_38 ( V_2 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_7 -> V_30 ;
F_35 ( V_29 -> V_31 , & V_2 -> V_46 ) ;
F_50 ( V_2 ) ;
}
int F_68 ( struct V_1 * V_2 , struct V_36 * V_37 ,
struct V_74 * V_75 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_28 * V_29 = V_7 -> V_30 ;
int V_13 , V_8 ;
F_26 ( ! F_27 ( & V_7 -> V_21 ) ) ;
V_37 -> V_38 = ++ V_29 -> V_76 ;
V_2 -> V_45 = V_37 -> V_38 ;
F_36 ( V_2 ) ;
F_69 ( & V_37 -> V_65 , & V_2 -> V_64 ) ;
F_70 ( V_37 ) ;
V_2 -> V_45 = V_37 -> V_38 ;
F_50 ( V_2 ) ;
for ( V_13 = 0 ; V_13 < V_37 -> V_77 ; V_13 ++ ) {
struct V_67 * V_78 = V_37 -> V_79 [ V_13 ] . V_68 ;
F_26 ( F_71 ( V_78 ) && ( V_78 -> V_2 != V_2 ) ) ;
if ( ! F_71 ( V_78 ) ) {
T_1 V_80 ;
F_72 ( & V_78 -> V_72 ) ;
F_73 ( & V_78 -> V_72 ,
V_37 -> V_2 -> V_73 , & V_80 ) ;
}
if ( V_37 -> V_79 [ V_13 ] . V_56 & V_81 )
F_74 ( & V_78 -> V_72 , V_2 , false , V_37 -> V_38 ) ;
if ( V_37 -> V_79 [ V_13 ] . V_56 & V_82 )
F_74 ( & V_78 -> V_72 , V_2 , true , V_37 -> V_38 ) ;
}
V_8 = V_2 -> V_39 -> V_37 ( V_2 , V_37 , V_75 ) ;
V_29 -> V_83 = V_75 ;
F_45 ( V_2 ) ;
return V_8 ;
}
static T_3 F_75 ( int V_84 , void * V_27 )
{
struct V_1 * V_2 = V_27 ;
return V_2 -> V_39 -> V_84 ( V_2 ) ;
}
int F_76 ( struct V_6 * V_85 , struct V_86 * V_87 ,
struct V_1 * V_2 , const struct V_88 * V_39 ,
const char * V_19 , const char * V_89 , const char * V_90 , int V_91 )
{
struct V_92 * V_93 ;
int V_13 , V_8 ;
if ( F_26 ( V_2 -> V_52 > F_14 ( V_2 -> V_50 ) ) )
V_2 -> V_52 = F_14 ( V_2 -> V_50 ) ;
V_2 -> V_7 = V_85 ;
V_2 -> V_39 = V_39 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_26 = true ;
F_77 ( & V_2 -> V_66 ) ;
F_78 ( & V_2 -> V_46 , F_63 ) ;
F_78 ( & V_2 -> V_25 , F_29 ) ;
F_78 ( & V_2 -> V_35 , F_41 ) ;
F_77 ( & V_2 -> V_64 ) ;
F_79 ( & V_2 -> V_32 , F_34 ,
( unsigned long ) V_2 ) ;
F_79 ( & V_2 -> V_42 , F_46 ,
( unsigned long ) V_2 ) ;
F_80 ( & V_2 -> V_57 ) ;
F_81 ( F_14 ( V_94 ) != F_14 ( V_2 -> V_14 ) ) ;
V_2 -> V_95 = F_82 ( V_87 , V_89 , V_19 ) ;
if ( F_83 ( V_2 -> V_95 ) ) {
V_8 = F_84 ( V_2 -> V_95 ) ;
goto V_96;
}
V_2 -> V_84 = F_85 ( V_87 , V_90 ) ;
if ( V_2 -> V_84 < 0 ) {
V_8 = V_2 -> V_84 ;
F_10 ( V_85 -> V_7 , L_12 , V_8 ) ;
goto V_96;
}
V_8 = F_86 ( & V_87 -> V_7 , V_2 -> V_84 , F_75 ,
V_97 , V_2 -> V_19 , V_2 ) ;
if ( V_8 ) {
F_10 ( V_85 -> V_7 , L_13 , V_2 -> V_84 , V_8 ) ;
goto V_96;
}
for ( V_13 = 0 ; V_13 < F_14 ( V_94 ) ; V_13 ++ ) {
V_2 -> V_14 [ V_13 ] = F_87 ( & V_87 -> V_7 , V_94 [ V_13 ] ) ;
F_3 ( L_14 , V_94 [ V_13 ] , V_2 -> V_14 [ V_13 ] ) ;
if ( F_83 ( V_2 -> V_14 [ V_13 ] ) )
V_2 -> V_14 [ V_13 ] = NULL ;
}
V_2 -> V_17 = F_87 ( & V_87 -> V_7 , L_15 ) ;
F_3 ( L_16 , V_2 -> V_17 ) ;
if ( F_83 ( V_2 -> V_17 ) )
V_2 -> V_17 = NULL ;
V_2 -> V_9 = F_88 ( & V_87 -> V_7 , L_17 ) ;
F_3 ( L_18 , V_2 -> V_9 ) ;
if ( F_83 ( V_2 -> V_9 ) )
V_2 -> V_9 = NULL ;
V_2 -> V_10 = F_88 ( & V_87 -> V_7 , L_19 ) ;
F_3 ( L_20 , V_2 -> V_10 ) ;
if ( F_83 ( V_2 -> V_10 ) )
V_2 -> V_10 = NULL ;
V_93 = F_89 ( & V_98 ) ;
if ( V_93 ) {
F_90 ( V_85 -> V_7 , L_21 , V_19 ) ;
V_2 -> V_99 = F_91 ( & V_87 -> V_7 , V_93 ) ;
if ( F_83 ( V_2 -> V_99 ) ) {
V_8 = F_84 ( V_2 -> V_99 ) ;
F_10 ( V_85 -> V_7 , L_22 , V_8 ) ;
V_2 -> V_99 = NULL ;
F_92 ( V_93 ) ;
goto V_96;
}
} else {
F_90 ( V_85 -> V_7 , L_23 , V_19 ) ;
}
V_2 -> V_73 = F_93 ( V_85 , V_2 -> V_99 ) ;
F_31 ( & V_85 -> V_21 ) ;
V_2 -> V_100 = F_94 ( V_2 , V_91 ) ;
F_33 ( & V_85 -> V_21 ) ;
if ( F_83 ( V_2 -> V_100 ) ) {
V_8 = F_84 ( V_2 -> V_100 ) ;
V_2 -> V_100 = NULL ;
F_10 ( V_85 -> V_7 , L_24 , V_8 ) ;
goto V_96;
}
F_1 ( V_2 ) ;
return 0 ;
V_96:
return V_8 ;
}
void F_95 ( struct V_1 * V_2 )
{
F_3 ( L_7 , V_2 -> V_19 ) ;
F_26 ( ! F_59 ( & V_2 -> V_66 ) ) ;
F_4 ( V_2 ) ;
if ( V_2 -> V_100 ) {
if ( V_2 -> V_101 )
F_66 ( V_2 -> V_100 -> V_102 , V_2 -> V_73 ) ;
F_96 ( V_2 -> V_100 ) ;
}
if ( V_2 -> V_99 )
V_2 -> V_99 -> V_39 -> V_103 ( V_2 -> V_99 ) ;
}
