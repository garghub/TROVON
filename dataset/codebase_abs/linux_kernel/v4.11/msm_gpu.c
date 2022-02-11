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
int V_11 ;
if ( V_2 -> V_12 [ 0 ] && V_2 -> V_13 )
F_14 ( V_2 -> V_12 [ 0 ] , V_2 -> V_13 ) ;
if ( V_2 -> V_12 [ 2 ] )
F_14 ( V_2 -> V_12 [ 2 ] , 19200000 ) ;
for ( V_11 = F_15 ( V_2 -> V_12 ) - 1 ; V_11 >= 0 ; V_11 -- )
if ( V_2 -> V_12 [ V_11 ] )
F_16 ( V_2 -> V_12 [ V_11 ] ) ;
for ( V_11 = F_15 ( V_2 -> V_12 ) - 1 ; V_11 >= 0 ; V_11 -- )
if ( V_2 -> V_12 [ V_11 ] )
F_17 ( V_2 -> V_12 [ V_11 ] ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_11 ;
for ( V_11 = F_15 ( V_2 -> V_12 ) - 1 ; V_11 >= 0 ; V_11 -- )
if ( V_2 -> V_12 [ V_11 ] )
F_19 ( V_2 -> V_12 [ V_11 ] ) ;
for ( V_11 = F_15 ( V_2 -> V_12 ) - 1 ; V_11 >= 0 ; V_11 -- )
if ( V_2 -> V_12 [ V_11 ] )
F_20 ( V_2 -> V_12 [ V_11 ] ) ;
if ( V_2 -> V_12 [ 0 ] && V_2 -> V_14 )
F_14 ( V_2 -> V_12 [ 0 ] , V_2 -> V_14 ) ;
if ( V_2 -> V_12 [ 2 ] )
F_14 ( V_2 -> V_12 [ 2 ] , 0 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
if ( V_2 -> V_15 )
F_22 ( V_2 -> V_15 ) ;
if ( V_2 -> V_16 )
F_6 ( V_2 , V_2 -> V_16 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
if ( V_2 -> V_15 )
F_24 ( V_2 -> V_15 ) ;
if ( V_2 -> V_16 )
F_6 ( V_2 , 0 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
F_3 ( L_5 , V_2 -> V_17 , V_2 -> V_18 ) ;
F_26 ( ! F_27 ( & V_7 -> V_19 ) ) ;
if ( V_2 -> V_18 ++ > 0 )
return 0 ;
if ( F_26 ( V_2 -> V_18 <= 0 ) )
return - V_20 ;
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
F_3 ( L_5 , V_2 -> V_17 , V_2 -> V_18 ) ;
F_26 ( ! F_27 ( & V_7 -> V_19 ) ) ;
if ( -- V_2 -> V_18 > 0 )
return 0 ;
if ( F_26 ( V_2 -> V_18 < 0 ) )
return - V_20 ;
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
static void F_29 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_30 ( V_22 , struct V_1 , V_23 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
if ( V_2 -> V_24 )
return;
F_3 ( L_6 , V_2 -> V_17 ) ;
F_31 ( & V_7 -> V_19 ) ;
if ( ! ( F_32 ( V_2 ) || V_2 -> V_24 ) ) {
F_23 ( V_2 ) ;
F_18 ( V_2 ) ;
V_2 -> V_24 = true ;
}
F_33 ( & V_7 -> V_19 ) ;
}
static void F_34 ( unsigned long V_25 )
{
struct V_1 * V_2 = (struct V_1 * ) V_25 ;
struct V_26 * V_27 = V_2 -> V_7 -> V_28 ;
F_35 ( V_27 -> V_29 , & V_2 -> V_23 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_3 ( L_7 , V_2 -> V_17 ) ;
F_37 ( & V_2 -> V_30 ) ;
if ( V_2 -> V_24 ) {
F_13 ( V_2 ) ;
F_21 ( V_2 ) ;
V_2 -> V_24 = false ;
}
}
static void F_38 ( struct V_1 * V_2 )
{
F_3 ( L_7 , V_2 -> V_17 ) ;
F_39 ( & V_2 -> V_30 ,
F_40 ( V_31 + V_32 ) ) ;
}
static void F_41 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_30 ( V_22 , struct V_1 , V_33 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_34 * V_35 ;
T_1 V_36 = V_2 -> V_37 -> V_38 ( V_2 ) ;
F_42 ( V_2 -> V_39 , V_36 + 1 ) ;
F_31 ( & V_7 -> V_19 ) ;
F_10 ( V_7 -> V_7 , L_8 , V_2 -> V_17 ) ;
F_43 (submit, &gpu->submit_list, node) {
if ( V_35 -> V_36 -> V_40 == ( V_36 + 1 ) ) {
struct V_41 * V_42 ;
F_44 () ;
V_42 = F_45 ( V_35 -> V_43 , V_44 ) ;
if ( V_42 ) {
F_10 ( V_7 -> V_7 , L_9 ,
V_2 -> V_17 , V_42 -> V_45 ) ;
}
F_46 () ;
break;
}
}
if ( F_32 ( V_2 ) ) {
F_47 ( V_2 ) ;
F_36 ( V_2 ) ;
V_2 -> V_37 -> V_46 ( V_2 ) ;
F_43 (submit, &gpu->submit_list, node) {
V_2 -> V_37 -> V_35 ( V_2 , V_35 , NULL ) ;
}
}
F_33 ( & V_7 -> V_19 ) ;
F_48 ( V_2 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_3 ( L_7 , V_2 -> V_17 ) ;
F_39 ( & V_2 -> V_47 ,
F_40 ( V_31 + V_48 ) ) ;
}
static void F_50 ( unsigned long V_25 )
{
struct V_1 * V_2 = (struct V_1 * ) V_25 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_26 * V_27 = V_7 -> V_28 ;
T_1 V_36 = V_2 -> V_37 -> V_38 ( V_2 ) ;
if ( V_36 != V_2 -> V_49 ) {
V_2 -> V_49 = V_36 ;
} else if ( V_36 < V_2 -> V_39 -> V_38 ) {
V_2 -> V_49 = V_36 ;
F_10 ( V_7 -> V_7 , L_10 ,
V_2 -> V_17 ) ;
F_10 ( V_7 -> V_7 , L_11 ,
V_2 -> V_17 , V_36 ) ;
F_10 ( V_7 -> V_7 , L_12 ,
V_2 -> V_17 , V_2 -> V_39 -> V_38 ) ;
F_35 ( V_27 -> V_29 , & V_2 -> V_33 ) ;
}
if ( V_2 -> V_39 -> V_38 > V_2 -> V_49 )
F_49 ( V_2 ) ;
F_35 ( V_27 -> V_29 , & V_2 -> V_50 ) ;
}
static int F_51 ( struct V_1 * V_2 , T_1 V_51 , T_1 * V_52 )
{
T_1 V_53 [ F_15 ( V_2 -> V_54 ) ] ;
int V_11 , V_55 = F_52 ( V_51 , V_2 -> V_56 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_56 ; V_11 ++ )
V_53 [ V_11 ] = F_53 ( V_2 , V_2 -> V_57 [ V_11 ] . V_58 ) ;
for ( V_11 = 0 ; V_11 < V_55 ; V_11 ++ )
V_52 [ V_11 ] = V_53 [ V_11 ] - V_2 -> V_54 [ V_11 ] ;
for ( V_11 = 0 ; V_11 < V_2 -> V_56 ; V_11 ++ )
V_2 -> V_54 [ V_11 ] = V_53 [ V_11 ] ;
return V_55 ;
}
static void F_54 ( struct V_1 * V_2 )
{
T_2 time ;
T_1 V_59 ;
unsigned long V_60 ;
F_55 ( & V_2 -> V_61 , V_60 ) ;
if ( ! V_2 -> V_62 )
goto V_63;
time = F_56 () ;
V_59 = F_57 ( F_58 ( time , V_2 -> V_64 . time ) ) ;
V_2 -> V_65 += V_59 ;
if ( V_2 -> V_64 . V_66 )
V_2 -> V_67 += V_59 ;
V_2 -> V_64 . V_66 = F_32 ( V_2 ) ;
V_2 -> V_64 . time = time ;
V_63:
F_59 ( & V_2 -> V_61 , V_60 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
unsigned long V_60 ;
F_55 ( & V_2 -> V_61 , V_60 ) ;
V_2 -> V_64 . V_66 = F_32 ( V_2 ) ;
V_2 -> V_64 . time = F_56 () ;
V_2 -> V_67 = V_2 -> V_65 = 0 ;
V_2 -> V_62 = true ;
F_51 ( V_2 , 0 , NULL ) ;
F_59 ( & V_2 -> V_61 , V_60 ) ;
}
void F_61 ( struct V_1 * V_2 )
{
V_2 -> V_62 = false ;
}
int F_62 ( struct V_1 * V_2 , T_1 * V_67 ,
T_1 * V_65 , T_1 V_51 , T_1 * V_52 )
{
unsigned long V_60 ;
int V_8 ;
F_55 ( & V_2 -> V_61 , V_60 ) ;
if ( ! V_2 -> V_62 ) {
V_8 = - V_20 ;
goto V_63;
}
* V_67 = V_2 -> V_67 ;
* V_65 = V_2 -> V_65 ;
V_2 -> V_67 = V_2 -> V_65 = 0 ;
V_8 = F_51 ( V_2 , V_51 , V_52 ) ;
V_63:
F_59 ( & V_2 -> V_61 , V_60 ) ;
return V_8 ;
}
static void F_63 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_35 -> V_68 ; V_11 ++ ) {
struct V_69 * V_70 = V_35 -> V_71 [ V_11 ] . V_72 ;
F_64 ( & V_70 -> V_73 ) ;
F_65 ( & V_70 -> V_73 , V_2 -> V_74 ) ;
F_66 ( & V_70 -> V_73 ) ;
}
F_67 ( V_35 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
F_26 ( ! F_27 ( & V_7 -> V_19 ) ) ;
while ( ! F_68 ( & V_2 -> V_75 ) ) {
struct V_34 * V_35 ;
V_35 = F_69 ( & V_2 -> V_75 ,
struct V_34 , V_76 ) ;
if ( F_70 ( V_35 -> V_36 ) ) {
F_63 ( V_2 , V_35 ) ;
} else {
break;
}
}
}
static void F_71 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_30 ( V_22 , struct V_1 , V_50 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
T_1 V_36 = V_2 -> V_37 -> V_38 ( V_2 ) ;
F_42 ( V_2 -> V_39 , V_36 ) ;
F_31 ( & V_7 -> V_19 ) ;
F_47 ( V_2 ) ;
F_33 ( & V_7 -> V_19 ) ;
if ( ! F_32 ( V_2 ) )
F_38 ( V_2 ) ;
}
void F_48 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_7 -> V_28 ;
F_35 ( V_27 -> V_29 , & V_2 -> V_50 ) ;
F_54 ( V_2 ) ;
}
void F_72 ( struct V_1 * V_2 , struct V_34 * V_35 ,
struct V_77 * V_78 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_26 * V_27 = V_7 -> V_28 ;
int V_11 ;
F_26 ( ! F_27 ( & V_7 -> V_19 ) ) ;
F_36 ( V_2 ) ;
F_73 ( & V_35 -> V_76 , & V_2 -> V_75 ) ;
F_74 ( V_35 ) ;
F_54 ( V_2 ) ;
for ( V_11 = 0 ; V_11 < V_35 -> V_68 ; V_11 ++ ) {
struct V_69 * V_70 = V_35 -> V_71 [ V_11 ] . V_72 ;
T_3 V_79 ;
F_26 ( F_75 ( V_70 ) && ( V_70 -> V_2 != V_2 ) ) ;
F_76 ( & V_70 -> V_73 ) ;
F_77 ( & V_70 -> V_73 ,
V_35 -> V_2 -> V_74 , & V_79 ) ;
if ( V_35 -> V_71 [ V_11 ] . V_60 & V_80 )
F_78 ( & V_70 -> V_73 , V_2 , true , V_35 -> V_36 ) ;
else if ( V_35 -> V_71 [ V_11 ] . V_60 & V_81 )
F_78 ( & V_70 -> V_73 , V_2 , false , V_35 -> V_36 ) ;
}
V_2 -> V_37 -> V_35 ( V_2 , V_35 , V_78 ) ;
V_27 -> V_82 = V_78 ;
F_49 ( V_2 ) ;
}
static T_4 F_79 ( int V_83 , void * V_25 )
{
struct V_1 * V_2 = V_25 ;
return V_2 -> V_37 -> V_83 ( V_2 ) ;
}
int F_80 ( struct V_6 * V_84 , struct V_85 * V_86 ,
struct V_1 * V_2 , const struct V_87 * V_37 ,
const char * V_17 , const char * V_88 , const char * V_89 , int V_90 )
{
struct V_91 * V_92 ;
int V_11 , V_8 ;
if ( F_26 ( V_2 -> V_56 > F_15 ( V_2 -> V_54 ) ) )
V_2 -> V_56 = F_15 ( V_2 -> V_54 ) ;
V_2 -> V_7 = V_84 ;
V_2 -> V_37 = V_37 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_24 = true ;
V_2 -> V_39 = F_81 ( V_84 , V_17 ) ;
if ( F_82 ( V_2 -> V_39 ) ) {
V_8 = F_83 ( V_2 -> V_39 ) ;
V_2 -> V_39 = NULL ;
goto V_93;
}
F_84 ( & V_2 -> V_94 ) ;
F_85 ( & V_2 -> V_50 , F_71 ) ;
F_85 ( & V_2 -> V_23 , F_29 ) ;
F_85 ( & V_2 -> V_33 , F_41 ) ;
F_84 ( & V_2 -> V_75 ) ;
F_86 ( & V_2 -> V_30 , F_34 ,
( unsigned long ) V_2 ) ;
F_86 ( & V_2 -> V_47 , F_50 ,
( unsigned long ) V_2 ) ;
F_87 ( & V_2 -> V_61 ) ;
F_88 ( F_15 ( V_95 ) != F_15 ( V_2 -> V_12 ) ) ;
V_2 -> V_96 = F_89 ( V_86 , V_88 , V_17 ) ;
if ( F_82 ( V_2 -> V_96 ) ) {
V_8 = F_83 ( V_2 -> V_96 ) ;
goto V_93;
}
V_2 -> V_83 = F_90 ( V_86 , V_89 ) ;
if ( V_2 -> V_83 < 0 ) {
V_8 = V_2 -> V_83 ;
F_10 ( V_84 -> V_7 , L_13 , V_8 ) ;
goto V_93;
}
V_8 = F_91 ( & V_86 -> V_7 , V_2 -> V_83 , F_79 ,
V_97 , V_2 -> V_17 , V_2 ) ;
if ( V_8 ) {
F_10 ( V_84 -> V_7 , L_14 , V_2 -> V_83 , V_8 ) ;
goto V_93;
}
for ( V_11 = 0 ; V_11 < F_15 ( V_95 ) ; V_11 ++ ) {
V_2 -> V_12 [ V_11 ] = F_92 ( V_86 , V_95 [ V_11 ] ) ;
F_3 ( L_15 , V_95 [ V_11 ] , V_2 -> V_12 [ V_11 ] ) ;
if ( F_82 ( V_2 -> V_12 [ V_11 ] ) )
V_2 -> V_12 [ V_11 ] = NULL ;
}
V_2 -> V_15 = F_92 ( V_86 , L_16 ) ;
F_3 ( L_17 , V_2 -> V_15 ) ;
if ( F_82 ( V_2 -> V_15 ) )
V_2 -> V_15 = NULL ;
V_2 -> V_9 = F_93 ( & V_86 -> V_7 , L_18 ) ;
F_3 ( L_19 , V_2 -> V_9 ) ;
if ( F_82 ( V_2 -> V_9 ) )
V_2 -> V_9 = NULL ;
V_2 -> V_10 = F_93 ( & V_86 -> V_7 , L_20 ) ;
F_3 ( L_21 , V_2 -> V_10 ) ;
if ( F_82 ( V_2 -> V_10 ) )
V_2 -> V_10 = NULL ;
V_92 = F_94 ( & V_98 ) ;
if ( V_92 ) {
V_92 -> V_99 . V_100 = V_101 ;
V_92 -> V_99 . V_102 = 0xffffffff ;
F_95 ( V_84 -> V_7 , L_22 , V_17 ) ;
V_2 -> V_103 = F_96 ( & V_86 -> V_7 ,
V_92 , L_23 ) ;
if ( F_82 ( V_2 -> V_103 ) ) {
V_8 = F_83 ( V_2 -> V_103 ) ;
F_10 ( V_84 -> V_7 , L_24 , V_8 ) ;
V_2 -> V_103 = NULL ;
F_97 ( V_92 ) ;
goto V_93;
}
} else {
F_95 ( V_84 -> V_7 , L_25 , V_17 ) ;
}
V_2 -> V_74 = F_98 ( V_84 , V_2 -> V_103 ) ;
F_31 ( & V_84 -> V_19 ) ;
V_2 -> V_104 = F_99 ( V_2 , V_90 ) ;
F_33 ( & V_84 -> V_19 ) ;
if ( F_82 ( V_2 -> V_104 ) ) {
V_8 = F_83 ( V_2 -> V_104 ) ;
V_2 -> V_104 = NULL ;
F_10 ( V_84 -> V_7 , L_26 , V_8 ) ;
goto V_93;
}
F_1 ( V_2 ) ;
return 0 ;
V_93:
return V_8 ;
}
void F_100 ( struct V_1 * V_2 )
{
F_3 ( L_7 , V_2 -> V_17 ) ;
F_26 ( ! F_68 ( & V_2 -> V_94 ) ) ;
F_4 ( V_2 ) ;
if ( V_2 -> V_104 ) {
if ( V_2 -> V_105 )
F_65 ( V_2 -> V_104 -> V_106 , V_2 -> V_74 ) ;
F_101 ( V_2 -> V_104 ) ;
}
if ( V_2 -> V_39 )
F_102 ( V_2 -> V_39 ) ;
}
