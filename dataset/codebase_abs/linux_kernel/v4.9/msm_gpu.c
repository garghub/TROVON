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
struct V_36 * V_37 ;
T_1 V_38 = V_2 -> V_39 -> V_40 ( V_2 ) ;
F_42 ( V_2 -> V_41 , V_38 + 1 ) ;
F_31 ( & V_7 -> V_21 ) ;
F_10 ( V_7 -> V_7 , L_8 , V_2 -> V_19 ) ;
F_43 (submit, &gpu->submit_list, node) {
if ( V_37 -> V_38 -> V_42 == ( V_38 + 1 ) ) {
struct V_43 * V_44 ;
F_44 () ;
V_44 = F_45 ( V_37 -> V_45 , V_46 ) ;
if ( V_44 ) {
F_10 ( V_7 -> V_7 , L_9 ,
V_2 -> V_19 , V_44 -> V_47 ) ;
}
F_46 () ;
break;
}
}
if ( F_32 ( V_2 ) ) {
F_47 ( V_2 ) ;
F_36 ( V_2 ) ;
V_2 -> V_39 -> V_48 ( V_2 ) ;
F_43 (submit, &gpu->submit_list, node) {
V_2 -> V_39 -> V_37 ( V_2 , V_37 , NULL ) ;
}
}
F_33 ( & V_7 -> V_21 ) ;
F_48 ( V_2 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_3 ( L_7 , V_2 -> V_19 ) ;
F_39 ( & V_2 -> V_49 ,
F_40 ( V_33 + V_50 ) ) ;
}
static void F_50 ( unsigned long V_27 )
{
struct V_1 * V_2 = (struct V_1 * ) V_27 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_28 * V_29 = V_7 -> V_30 ;
T_1 V_38 = V_2 -> V_39 -> V_40 ( V_2 ) ;
if ( V_38 != V_2 -> V_51 ) {
V_2 -> V_51 = V_38 ;
} else if ( V_38 < V_2 -> V_41 -> V_40 ) {
V_2 -> V_51 = V_38 ;
F_10 ( V_7 -> V_7 , L_10 ,
V_2 -> V_19 ) ;
F_10 ( V_7 -> V_7 , L_11 ,
V_2 -> V_19 , V_38 ) ;
F_10 ( V_7 -> V_7 , L_12 ,
V_2 -> V_19 , V_2 -> V_41 -> V_40 ) ;
F_35 ( V_29 -> V_31 , & V_2 -> V_35 ) ;
}
if ( V_2 -> V_41 -> V_40 > V_2 -> V_51 )
F_49 ( V_2 ) ;
F_35 ( V_29 -> V_31 , & V_2 -> V_52 ) ;
}
static int F_51 ( struct V_1 * V_2 , T_1 V_53 , T_1 * V_54 )
{
T_1 V_55 [ F_14 ( V_2 -> V_56 ) ] ;
int V_13 , V_57 = F_52 ( V_53 , V_2 -> V_58 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_58 ; V_13 ++ )
V_55 [ V_13 ] = F_53 ( V_2 , V_2 -> V_59 [ V_13 ] . V_60 ) ;
for ( V_13 = 0 ; V_13 < V_57 ; V_13 ++ )
V_54 [ V_13 ] = V_55 [ V_13 ] - V_2 -> V_56 [ V_13 ] ;
for ( V_13 = 0 ; V_13 < V_2 -> V_58 ; V_13 ++ )
V_2 -> V_56 [ V_13 ] = V_55 [ V_13 ] ;
return V_57 ;
}
static void F_54 ( struct V_1 * V_2 )
{
T_2 time ;
T_1 V_61 ;
unsigned long V_62 ;
F_55 ( & V_2 -> V_63 , V_62 ) ;
if ( ! V_2 -> V_64 )
goto V_65;
time = F_56 () ;
V_61 = F_57 ( F_58 ( time , V_2 -> V_66 . time ) ) ;
V_2 -> V_67 += V_61 ;
if ( V_2 -> V_66 . V_68 )
V_2 -> V_69 += V_61 ;
V_2 -> V_66 . V_68 = F_32 ( V_2 ) ;
V_2 -> V_66 . time = time ;
V_65:
F_59 ( & V_2 -> V_63 , V_62 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
unsigned long V_62 ;
F_55 ( & V_2 -> V_63 , V_62 ) ;
V_2 -> V_66 . V_68 = F_32 ( V_2 ) ;
V_2 -> V_66 . time = F_56 () ;
V_2 -> V_69 = V_2 -> V_67 = 0 ;
V_2 -> V_64 = true ;
F_51 ( V_2 , 0 , NULL ) ;
F_59 ( & V_2 -> V_63 , V_62 ) ;
}
void F_61 ( struct V_1 * V_2 )
{
V_2 -> V_64 = false ;
}
int F_62 ( struct V_1 * V_2 , T_1 * V_69 ,
T_1 * V_67 , T_1 V_53 , T_1 * V_54 )
{
unsigned long V_62 ;
int V_8 ;
F_55 ( & V_2 -> V_63 , V_62 ) ;
if ( ! V_2 -> V_64 ) {
V_8 = - V_22 ;
goto V_65;
}
* V_69 = V_2 -> V_69 ;
* V_67 = V_2 -> V_67 ;
V_2 -> V_69 = V_2 -> V_67 = 0 ;
V_8 = F_51 ( V_2 , V_53 , V_54 ) ;
V_65:
F_59 ( & V_2 -> V_63 , V_62 ) ;
return V_8 ;
}
static void F_63 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_37 -> V_70 ; V_13 ++ ) {
struct V_71 * V_72 = V_37 -> V_73 [ V_13 ] . V_74 ;
F_64 ( & V_72 -> V_75 ) ;
F_65 ( & V_72 -> V_75 , V_2 -> V_76 ) ;
F_66 ( & V_72 -> V_75 ) ;
}
F_67 ( V_37 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
F_26 ( ! F_27 ( & V_7 -> V_21 ) ) ;
while ( ! F_68 ( & V_2 -> V_77 ) ) {
struct V_36 * V_37 ;
V_37 = F_69 ( & V_2 -> V_77 ,
struct V_36 , V_78 ) ;
if ( F_70 ( V_37 -> V_38 ) ) {
F_63 ( V_2 , V_37 ) ;
} else {
break;
}
}
}
static void F_71 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_30 ( V_24 , struct V_1 , V_52 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
T_1 V_38 = V_2 -> V_39 -> V_40 ( V_2 ) ;
F_42 ( V_2 -> V_41 , V_38 ) ;
F_31 ( & V_7 -> V_21 ) ;
F_47 ( V_2 ) ;
F_33 ( & V_7 -> V_21 ) ;
if ( ! F_32 ( V_2 ) )
F_38 ( V_2 ) ;
}
void F_48 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_7 -> V_30 ;
F_35 ( V_29 -> V_31 , & V_2 -> V_52 ) ;
F_54 ( V_2 ) ;
}
void F_72 ( struct V_1 * V_2 , struct V_36 * V_37 ,
struct V_79 * V_80 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_28 * V_29 = V_7 -> V_30 ;
int V_13 ;
F_26 ( ! F_27 ( & V_7 -> V_21 ) ) ;
F_36 ( V_2 ) ;
F_73 ( & V_37 -> V_78 , & V_2 -> V_77 ) ;
F_74 ( V_37 ) ;
F_54 ( V_2 ) ;
for ( V_13 = 0 ; V_13 < V_37 -> V_70 ; V_13 ++ ) {
struct V_71 * V_72 = V_37 -> V_73 [ V_13 ] . V_74 ;
T_1 V_81 ;
F_26 ( F_75 ( V_72 ) && ( V_72 -> V_2 != V_2 ) ) ;
F_76 ( & V_72 -> V_75 ) ;
F_77 ( & V_72 -> V_75 ,
V_37 -> V_2 -> V_76 , & V_81 ) ;
if ( V_37 -> V_73 [ V_13 ] . V_62 & V_82 )
F_78 ( & V_72 -> V_75 , V_2 , true , V_37 -> V_38 ) ;
else if ( V_37 -> V_73 [ V_13 ] . V_62 & V_83 )
F_78 ( & V_72 -> V_75 , V_2 , false , V_37 -> V_38 ) ;
}
V_2 -> V_39 -> V_37 ( V_2 , V_37 , V_80 ) ;
V_29 -> V_84 = V_80 ;
F_49 ( V_2 ) ;
}
static T_3 F_79 ( int V_85 , void * V_27 )
{
struct V_1 * V_2 = V_27 ;
return V_2 -> V_39 -> V_85 ( V_2 ) ;
}
int F_80 ( struct V_6 * V_86 , struct V_87 * V_88 ,
struct V_1 * V_2 , const struct V_89 * V_39 ,
const char * V_19 , const char * V_90 , const char * V_91 , int V_92 )
{
struct V_93 * V_94 ;
int V_13 , V_8 ;
if ( F_26 ( V_2 -> V_58 > F_14 ( V_2 -> V_56 ) ) )
V_2 -> V_58 = F_14 ( V_2 -> V_56 ) ;
V_2 -> V_7 = V_86 ;
V_2 -> V_39 = V_39 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_26 = true ;
V_2 -> V_41 = F_81 ( V_86 , V_19 ) ;
if ( F_82 ( V_2 -> V_41 ) ) {
V_8 = F_83 ( V_2 -> V_41 ) ;
V_2 -> V_41 = NULL ;
goto V_95;
}
F_84 ( & V_2 -> V_96 ) ;
F_85 ( & V_2 -> V_52 , F_71 ) ;
F_85 ( & V_2 -> V_25 , F_29 ) ;
F_85 ( & V_2 -> V_35 , F_41 ) ;
F_84 ( & V_2 -> V_77 ) ;
F_86 ( & V_2 -> V_32 , F_34 ,
( unsigned long ) V_2 ) ;
F_86 ( & V_2 -> V_49 , F_50 ,
( unsigned long ) V_2 ) ;
F_87 ( & V_2 -> V_63 ) ;
F_88 ( F_14 ( V_97 ) != F_14 ( V_2 -> V_14 ) ) ;
V_2 -> V_98 = F_89 ( V_88 , V_90 , V_19 ) ;
if ( F_82 ( V_2 -> V_98 ) ) {
V_8 = F_83 ( V_2 -> V_98 ) ;
goto V_95;
}
V_2 -> V_85 = F_90 ( V_88 , V_91 ) ;
if ( V_2 -> V_85 < 0 ) {
V_8 = V_2 -> V_85 ;
F_10 ( V_86 -> V_7 , L_13 , V_8 ) ;
goto V_95;
}
V_8 = F_91 ( & V_88 -> V_7 , V_2 -> V_85 , F_79 ,
V_99 , V_2 -> V_19 , V_2 ) ;
if ( V_8 ) {
F_10 ( V_86 -> V_7 , L_14 , V_2 -> V_85 , V_8 ) ;
goto V_95;
}
for ( V_13 = 0 ; V_13 < F_14 ( V_97 ) ; V_13 ++ ) {
V_2 -> V_14 [ V_13 ] = F_92 ( & V_88 -> V_7 , V_97 [ V_13 ] ) ;
F_3 ( L_15 , V_97 [ V_13 ] , V_2 -> V_14 [ V_13 ] ) ;
if ( F_82 ( V_2 -> V_14 [ V_13 ] ) )
V_2 -> V_14 [ V_13 ] = NULL ;
}
V_2 -> V_17 = F_92 ( & V_88 -> V_7 , L_16 ) ;
F_3 ( L_17 , V_2 -> V_17 ) ;
if ( F_82 ( V_2 -> V_17 ) )
V_2 -> V_17 = NULL ;
V_2 -> V_9 = F_93 ( & V_88 -> V_7 , L_18 ) ;
F_3 ( L_19 , V_2 -> V_9 ) ;
if ( F_82 ( V_2 -> V_9 ) )
V_2 -> V_9 = NULL ;
V_2 -> V_10 = F_93 ( & V_88 -> V_7 , L_20 ) ;
F_3 ( L_21 , V_2 -> V_10 ) ;
if ( F_82 ( V_2 -> V_10 ) )
V_2 -> V_10 = NULL ;
V_94 = F_94 ( & V_100 ) ;
if ( V_94 ) {
F_95 ( V_86 -> V_7 , L_22 , V_19 ) ;
V_2 -> V_101 = F_96 ( & V_88 -> V_7 , V_94 ) ;
if ( F_82 ( V_2 -> V_101 ) ) {
V_8 = F_83 ( V_2 -> V_101 ) ;
F_10 ( V_86 -> V_7 , L_23 , V_8 ) ;
V_2 -> V_101 = NULL ;
F_97 ( V_94 ) ;
goto V_95;
}
} else {
F_95 ( V_86 -> V_7 , L_24 , V_19 ) ;
}
V_2 -> V_76 = F_98 ( V_86 , V_2 -> V_101 ) ;
F_31 ( & V_86 -> V_21 ) ;
V_2 -> V_102 = F_99 ( V_2 , V_92 ) ;
F_33 ( & V_86 -> V_21 ) ;
if ( F_82 ( V_2 -> V_102 ) ) {
V_8 = F_83 ( V_2 -> V_102 ) ;
V_2 -> V_102 = NULL ;
F_10 ( V_86 -> V_7 , L_25 , V_8 ) ;
goto V_95;
}
F_1 ( V_2 ) ;
return 0 ;
V_95:
return V_8 ;
}
void F_100 ( struct V_1 * V_2 )
{
F_3 ( L_7 , V_2 -> V_19 ) ;
F_26 ( ! F_68 ( & V_2 -> V_96 ) ) ;
F_4 ( V_2 ) ;
if ( V_2 -> V_102 ) {
if ( V_2 -> V_103 )
F_65 ( V_2 -> V_102 -> V_104 , V_2 -> V_76 ) ;
F_101 ( V_2 -> V_102 ) ;
}
if ( V_2 -> V_101 )
V_2 -> V_101 -> V_39 -> V_105 ( V_2 -> V_101 ) ;
if ( V_2 -> V_41 )
F_102 ( V_2 -> V_41 ) ;
}
