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
F_36 ( V_2 ) ;
V_2 -> V_36 -> V_37 ( V_2 ) ;
}
F_33 ( & V_7 -> V_21 ) ;
F_42 ( V_2 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
F_3 ( L_7 , V_2 -> V_19 ) ;
F_39 ( & V_2 -> V_38 ,
F_40 ( V_33 + V_39 ) ) ;
}
static void F_44 ( unsigned long V_27 )
{
struct V_1 * V_2 = (struct V_1 * ) V_27 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_28 * V_29 = V_7 -> V_30 ;
T_1 V_40 = V_2 -> V_36 -> V_41 ( V_2 ) ;
if ( V_40 != V_2 -> V_42 ) {
V_2 -> V_42 = V_40 ;
} else if ( V_40 < V_2 -> V_43 ) {
V_2 -> V_42 = V_40 ;
F_10 ( V_7 -> V_7 , L_9 ,
V_2 -> V_19 ) ;
F_10 ( V_7 -> V_7 , L_10 ,
V_2 -> V_19 , V_40 ) ;
F_10 ( V_7 -> V_7 , L_11 ,
V_2 -> V_19 , V_2 -> V_43 ) ;
F_35 ( V_29 -> V_31 , & V_2 -> V_35 ) ;
}
if ( V_2 -> V_43 > V_2 -> V_42 )
F_43 ( V_2 ) ;
F_35 ( V_29 -> V_31 , & V_2 -> V_44 ) ;
}
static int F_45 ( struct V_1 * V_2 , T_1 V_45 , T_1 * V_46 )
{
T_1 V_47 [ F_14 ( V_2 -> V_48 ) ] ;
int V_13 , V_49 = F_46 ( V_45 , V_2 -> V_50 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_50 ; V_13 ++ )
V_47 [ V_13 ] = F_47 ( V_2 , V_2 -> V_51 [ V_13 ] . V_52 ) ;
for ( V_13 = 0 ; V_13 < V_49 ; V_13 ++ )
V_46 [ V_13 ] = V_47 [ V_13 ] - V_2 -> V_48 [ V_13 ] ;
for ( V_13 = 0 ; V_13 < V_2 -> V_50 ; V_13 ++ )
V_2 -> V_48 [ V_13 ] = V_47 [ V_13 ] ;
return V_49 ;
}
static void F_48 ( struct V_1 * V_2 )
{
T_2 time ;
T_1 V_53 ;
unsigned long V_54 ;
F_49 ( & V_2 -> V_55 , V_54 ) ;
if ( ! V_2 -> V_56 )
goto V_57;
time = F_50 () ;
V_53 = F_51 ( F_52 ( time , V_2 -> V_58 . time ) ) ;
V_2 -> V_59 += V_53 ;
if ( V_2 -> V_58 . V_60 )
V_2 -> V_61 += V_53 ;
V_2 -> V_58 . V_60 = F_32 ( V_2 ) ;
V_2 -> V_58 . time = time ;
V_57:
F_53 ( & V_2 -> V_55 , V_54 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
unsigned long V_54 ;
F_49 ( & V_2 -> V_55 , V_54 ) ;
V_2 -> V_58 . V_60 = F_32 ( V_2 ) ;
V_2 -> V_58 . time = F_50 () ;
V_2 -> V_61 = V_2 -> V_59 = 0 ;
V_2 -> V_56 = true ;
F_45 ( V_2 , 0 , NULL ) ;
F_53 ( & V_2 -> V_55 , V_54 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
V_2 -> V_56 = false ;
}
int F_56 ( struct V_1 * V_2 , T_1 * V_61 ,
T_1 * V_59 , T_1 V_45 , T_1 * V_46 )
{
unsigned long V_54 ;
int V_8 ;
F_49 ( & V_2 -> V_55 , V_54 ) ;
if ( ! V_2 -> V_56 ) {
V_8 = - V_22 ;
goto V_57;
}
* V_61 = V_2 -> V_61 ;
* V_59 = V_2 -> V_59 ;
V_2 -> V_61 = V_2 -> V_59 = 0 ;
V_8 = F_45 ( V_2 , V_45 , V_46 ) ;
V_57:
F_53 ( & V_2 -> V_55 , V_54 ) ;
return V_8 ;
}
static void F_57 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_30 ( V_24 , struct V_1 , V_44 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
T_1 V_40 = V_2 -> V_36 -> V_41 ( V_2 ) ;
F_58 ( V_2 -> V_7 , V_40 ) ;
F_31 ( & V_7 -> V_21 ) ;
while ( ! F_59 ( & V_2 -> V_62 ) ) {
struct V_63 * V_64 ;
V_64 = F_60 ( & V_2 -> V_62 ,
struct V_63 , V_65 ) ;
if ( ( V_64 -> V_66 <= V_40 ) &&
( V_64 -> V_67 <= V_40 ) ) {
F_61 ( & V_64 -> V_68 ) ;
F_62 ( & V_64 -> V_68 , V_2 -> V_69 ) ;
F_63 ( & V_64 -> V_68 ) ;
} else {
break;
}
}
F_33 ( & V_7 -> V_21 ) ;
if ( ! F_32 ( V_2 ) )
F_38 ( V_2 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_7 -> V_30 ;
F_35 ( V_29 -> V_31 , & V_2 -> V_44 ) ;
F_48 ( V_2 ) ;
}
int F_64 ( struct V_1 * V_2 , struct V_70 * V_71 ,
struct V_72 * V_73 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_28 * V_29 = V_7 -> V_30 ;
int V_13 , V_8 ;
V_71 -> V_40 = ++ V_29 -> V_74 ;
V_2 -> V_43 = V_71 -> V_40 ;
F_36 ( V_2 ) ;
F_65 ( V_71 ) ;
V_2 -> V_43 = V_71 -> V_40 ;
F_48 ( V_2 ) ;
V_8 = V_2 -> V_36 -> V_71 ( V_2 , V_71 , V_73 ) ;
V_29 -> V_75 = V_73 ;
for ( V_13 = 0 ; V_13 < V_71 -> V_76 ; V_13 ++ ) {
struct V_63 * V_77 = V_71 -> V_78 [ V_13 ] . V_64 ;
F_26 ( F_66 ( V_77 ) && ( V_77 -> V_2 != V_2 ) ) ;
if ( ! F_66 ( V_77 ) ) {
T_1 V_79 ;
F_67 ( & V_77 -> V_68 ) ;
F_68 ( & V_77 -> V_68 ,
V_71 -> V_2 -> V_69 , & V_79 ) ;
}
if ( V_71 -> V_78 [ V_13 ] . V_54 & V_80 )
F_69 ( & V_77 -> V_68 , V_2 , false , V_71 -> V_40 ) ;
if ( V_71 -> V_78 [ V_13 ] . V_54 & V_81 )
F_69 ( & V_77 -> V_68 , V_2 , true , V_71 -> V_40 ) ;
}
F_43 ( V_2 ) ;
return V_8 ;
}
static T_3 F_70 ( int V_82 , void * V_27 )
{
struct V_1 * V_2 = V_27 ;
return V_2 -> V_36 -> V_82 ( V_2 ) ;
}
int F_71 ( struct V_6 * V_83 , struct V_84 * V_85 ,
struct V_1 * V_2 , const struct V_86 * V_36 ,
const char * V_19 , const char * V_87 , const char * V_88 , int V_89 )
{
struct V_90 * V_91 ;
int V_13 , V_8 ;
if ( F_26 ( V_2 -> V_50 > F_14 ( V_2 -> V_48 ) ) )
V_2 -> V_50 = F_14 ( V_2 -> V_48 ) ;
V_2 -> V_7 = V_83 ;
V_2 -> V_36 = V_36 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_26 = true ;
F_72 ( & V_2 -> V_62 ) ;
F_73 ( & V_2 -> V_44 , F_57 ) ;
F_73 ( & V_2 -> V_25 , F_29 ) ;
F_73 ( & V_2 -> V_35 , F_41 ) ;
F_74 ( & V_2 -> V_32 , F_34 ,
( unsigned long ) V_2 ) ;
F_74 ( & V_2 -> V_38 , F_44 ,
( unsigned long ) V_2 ) ;
F_75 ( & V_2 -> V_55 ) ;
F_76 ( F_14 ( V_92 ) != F_14 ( V_2 -> V_14 ) ) ;
V_2 -> V_93 = F_77 ( V_85 , V_87 , V_19 ) ;
if ( F_78 ( V_2 -> V_93 ) ) {
V_8 = F_79 ( V_2 -> V_93 ) ;
goto V_94;
}
V_2 -> V_82 = F_80 ( V_85 , V_88 ) ;
if ( V_2 -> V_82 < 0 ) {
V_8 = V_2 -> V_82 ;
F_10 ( V_83 -> V_7 , L_12 , V_8 ) ;
goto V_94;
}
V_8 = F_81 ( & V_85 -> V_7 , V_2 -> V_82 , F_70 ,
V_95 , V_2 -> V_19 , V_2 ) ;
if ( V_8 ) {
F_10 ( V_83 -> V_7 , L_13 , V_2 -> V_82 , V_8 ) ;
goto V_94;
}
for ( V_13 = 0 ; V_13 < F_14 ( V_92 ) ; V_13 ++ ) {
V_2 -> V_14 [ V_13 ] = F_82 ( & V_85 -> V_7 , V_92 [ V_13 ] ) ;
F_3 ( L_14 , V_92 [ V_13 ] , V_2 -> V_14 [ V_13 ] ) ;
if ( F_78 ( V_2 -> V_14 [ V_13 ] ) )
V_2 -> V_14 [ V_13 ] = NULL ;
}
V_2 -> V_17 = F_82 ( & V_85 -> V_7 , L_15 ) ;
F_3 ( L_16 , V_2 -> V_17 ) ;
if ( F_78 ( V_2 -> V_17 ) )
V_2 -> V_17 = NULL ;
V_2 -> V_9 = F_83 ( & V_85 -> V_7 , L_17 ) ;
F_3 ( L_18 , V_2 -> V_9 ) ;
if ( F_78 ( V_2 -> V_9 ) )
V_2 -> V_9 = NULL ;
V_2 -> V_10 = F_83 ( & V_85 -> V_7 , L_19 ) ;
F_3 ( L_20 , V_2 -> V_10 ) ;
if ( F_78 ( V_2 -> V_10 ) )
V_2 -> V_10 = NULL ;
V_91 = F_84 ( & V_96 ) ;
if ( V_91 ) {
F_85 ( V_83 -> V_7 , L_21 , V_19 ) ;
V_2 -> V_97 = F_86 ( V_83 , V_91 ) ;
} else {
F_85 ( V_83 -> V_7 , L_22 , V_19 ) ;
}
V_2 -> V_69 = F_87 ( V_83 , V_2 -> V_97 ) ;
V_2 -> V_98 = F_88 ( V_2 , V_89 ) ;
if ( F_78 ( V_2 -> V_98 ) ) {
V_8 = F_79 ( V_2 -> V_98 ) ;
V_2 -> V_98 = NULL ;
F_10 ( V_83 -> V_7 , L_23 , V_8 ) ;
goto V_94;
}
V_8 = F_68 ( V_2 -> V_98 -> V_99 , V_2 -> V_69 , & V_2 -> V_100 ) ;
if ( V_8 ) {
V_2 -> V_100 = 0 ;
F_10 ( V_83 -> V_7 , L_24 , V_8 ) ;
goto V_94;
}
F_1 ( V_2 ) ;
return 0 ;
V_94:
return V_8 ;
}
void F_89 ( struct V_1 * V_2 )
{
F_3 ( L_7 , V_2 -> V_19 ) ;
F_26 ( ! F_59 ( & V_2 -> V_62 ) ) ;
F_4 ( V_2 ) ;
if ( V_2 -> V_98 ) {
if ( V_2 -> V_100 )
F_62 ( V_2 -> V_98 -> V_99 , V_2 -> V_69 ) ;
F_90 ( V_2 -> V_98 ) ;
}
if ( V_2 -> V_97 )
V_2 -> V_97 -> V_36 -> V_101 ( V_2 -> V_97 ) ;
}
