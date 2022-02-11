static int F_1 ( struct V_1 * V_2 , T_1 V_3 , struct V_4 * V_4 , T_2 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_8 . V_9 ;
struct V_10 * * V_11 = & V_7 -> V_10 ;
struct V_10 * V_12 = NULL ;
struct V_13 * V_14 ;
struct V_13 * V_15 ;
int V_16 ;
while ( * V_11 ) {
V_12 = * V_11 ;
V_15 = F_2 ( V_12 , struct V_13 , V_10 ) ;
if ( V_15 -> V_3 < V_3 )
V_11 = & V_12 -> V_17 ;
else if ( V_15 -> V_3 > V_3 )
V_11 = & V_12 -> V_18 ;
else
return - V_19 ;
}
V_14 = F_3 ( sizeof( * V_14 ) , V_20 ) ;
if ( ! V_14 )
return - V_21 ;
V_14 -> V_3 = V_3 ;
V_14 -> V_4 = V_4 ;
V_14 -> V_5 = V_5 ;
V_14 -> V_22 = V_23 ;
for ( V_16 = 0 ; V_16 < V_23 ; V_16 ++ )
F_4 ( V_16 , & V_14 -> V_24 ) ;
F_5 ( & V_14 -> V_10 , V_12 , V_11 ) ;
F_6 ( & V_14 -> V_10 , V_7 ) ;
F_7 ( & V_14 -> V_25 , & V_2 -> V_8 . V_26 ) ;
return 0 ;
}
static struct V_13 * F_8 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_6 * V_7 = & V_2 -> V_8 . V_9 ;
struct V_10 * V_27 = V_7 -> V_10 ;
struct V_13 * V_28 = NULL ;
struct V_13 * V_15 ;
while ( V_27 ) {
V_15 = F_2 ( V_27 , struct V_13 , V_10 ) ;
if ( V_15 -> V_3 < V_3 ) {
V_27 = V_27 -> V_17 ;
} else if ( V_15 -> V_3 > V_3 ) {
V_27 = V_27 -> V_18 ;
} else {
V_28 = V_15 ;
break;
}
}
return V_28 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 * V_5 ,
T_3 * V_29 , int V_30 )
{
T_4 V_31 [ F_10 ( V_32 ) ] = { 0 } ;
T_4 V_33 [ F_10 ( V_34 ) ] = { 0 } ;
int V_35 ;
F_11 ( V_34 , V_33 , V_36 , V_37 ) ;
F_11 ( V_34 , V_33 , V_38 , V_30 ?
V_39 :
V_40 ) ;
V_35 = F_12 ( V_2 , V_33 , sizeof( V_33 ) , V_31 , sizeof( V_31 ) ) ;
if ( V_35 )
return V_35 ;
* V_29 = F_13 ( V_32 , V_31 , V_41 ) ;
* V_5 = F_13 ( V_32 , V_31 , V_42 ) ;
return V_35 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_13 * V_43 ;
unsigned V_44 ;
if ( F_15 ( & V_2 -> V_8 . V_26 ) )
return - V_21 ;
V_43 = F_16 ( V_2 -> V_8 . V_26 . V_45 , struct V_13 , V_25 ) ;
V_44 = F_17 ( & V_43 -> V_24 , 8 * sizeof( V_43 -> V_24 ) ) ;
if ( V_44 >= V_23 ) {
F_18 ( V_2 , L_1 ) ;
return - V_46 ;
}
F_19 ( V_44 , & V_43 -> V_24 ) ;
V_43 -> V_22 -- ;
if ( ! V_43 -> V_22 )
F_20 ( & V_43 -> V_25 ) ;
* V_3 = V_43 -> V_3 + V_44 * V_47 ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_13 * V_48 ;
int V_44 ;
V_48 = F_8 ( V_2 , V_3 & V_49 ) ;
if ( ! V_48 ) {
F_18 ( V_2 , L_2 ) ;
return;
}
V_44 = ( V_3 & ~ V_49 ) >> V_50 ;
V_48 -> V_22 ++ ;
F_4 ( V_44 , & V_48 -> V_24 ) ;
if ( V_48 -> V_22 == V_23 ) {
F_22 ( & V_48 -> V_10 , & V_2 -> V_8 . V_9 ) ;
if ( V_48 -> V_22 != 1 )
F_20 ( & V_48 -> V_25 ) ;
F_23 ( & V_2 -> V_51 -> V_2 , V_3 & V_49 ,
V_52 , V_53 ) ;
F_24 ( V_48 -> V_4 ) ;
F_25 ( V_48 ) ;
} else if ( V_48 -> V_22 == 1 ) {
F_7 ( & V_48 -> V_25 , & V_2 -> V_8 . V_26 ) ;
}
}
static int F_26 ( struct V_1 * V_2 , T_2 V_5 )
{
struct V_4 * V_4 ;
T_1 V_54 = 1 ;
T_1 V_3 ;
int V_35 ;
int V_55 = F_27 ( & V_2 -> V_51 -> V_2 ) ;
V_4 = F_28 ( V_55 , V_56 , 0 ) ;
if ( ! V_4 ) {
F_18 ( V_2 , L_3 ) ;
return - V_21 ;
}
V_57:
V_3 = F_29 ( & V_2 -> V_51 -> V_2 , V_4 , 0 ,
V_52 , V_53 ) ;
if ( F_30 ( & V_2 -> V_51 -> V_2 , V_3 ) ) {
F_18 ( V_2 , L_4 ) ;
V_35 = - V_21 ;
goto V_58;
}
if ( V_3 == 0 ) {
V_54 = V_3 ;
goto V_57;
}
V_35 = F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
if ( V_35 ) {
F_31 ( V_2 , L_5 ) ;
F_23 ( & V_2 -> V_51 -> V_2 , V_3 , V_52 ,
V_53 ) ;
}
V_58:
if ( V_35 )
F_24 ( V_4 ) ;
if ( V_54 == 0 )
F_23 ( & V_2 -> V_51 -> V_2 , V_54 , V_52 ,
V_53 ) ;
return V_35 ;
}
static void F_32 ( struct V_1 * V_2 , T_2 V_5 )
{
T_4 V_31 [ F_10 ( V_59 ) ] = { 0 } ;
T_4 V_33 [ F_10 ( V_60 ) ] = { 0 } ;
int V_35 ;
F_11 ( V_60 , V_33 , V_36 , V_61 ) ;
F_11 ( V_60 , V_33 , V_38 , V_62 ) ;
F_11 ( V_60 , V_33 , V_42 , V_5 ) ;
V_35 = F_12 ( V_2 , V_33 , sizeof( V_33 ) , V_31 , sizeof( V_31 ) ) ;
if ( V_35 )
F_18 ( V_2 , L_6 ,
V_5 , V_35 ) ;
}
static int F_33 ( struct V_1 * V_2 , T_2 V_5 , int V_29 ,
int V_63 )
{
T_4 V_31 [ F_10 ( V_59 ) ] = { 0 } ;
int V_64 = F_34 ( V_60 ) ;
T_1 V_3 ;
int V_35 ;
T_4 * V_33 ;
int V_16 ;
V_64 += V_29 * F_35 ( V_60 , V_65 [ 0 ] ) ;
V_33 = F_36 ( V_64 ) ;
if ( ! V_33 ) {
V_35 = - V_21 ;
F_18 ( V_2 , L_7 , V_64 ) ;
goto V_66;
}
for ( V_16 = 0 ; V_16 < V_29 ; V_16 ++ ) {
V_67:
V_35 = F_14 ( V_2 , & V_3 ) ;
if ( V_35 ) {
if ( V_35 == - V_21 )
V_35 = F_26 ( V_2 , V_5 ) ;
if ( V_35 )
goto V_68;
goto V_67;
}
F_37 ( V_60 , V_33 , V_65 , V_16 , V_3 ) ;
}
F_11 ( V_60 , V_33 , V_36 , V_61 ) ;
F_11 ( V_60 , V_33 , V_38 , V_69 ) ;
F_11 ( V_60 , V_33 , V_42 , V_5 ) ;
F_11 ( V_60 , V_33 , V_70 , V_29 ) ;
V_35 = F_12 ( V_2 , V_33 , V_64 , V_31 , sizeof( V_31 ) ) ;
if ( V_35 ) {
F_18 ( V_2 , L_8 ,
V_5 , V_29 , V_35 ) ;
goto V_68;
}
V_2 -> V_8 . V_71 += V_29 ;
if ( V_5 )
V_2 -> V_8 . V_72 += V_29 ;
F_38 ( V_2 , L_9 , V_35 ) ;
F_39 ( V_33 ) ;
return 0 ;
V_68:
for ( V_16 -- ; V_16 >= 0 ; V_16 -- )
F_21 ( V_2 , F_40 ( V_60 , V_33 , V_65 [ V_16 ] ) ) ;
V_66:
F_39 ( V_33 ) ;
if ( V_63 )
F_32 ( V_2 , V_5 ) ;
return V_35 ;
}
static int F_41 ( struct V_1 * V_2 ,
T_4 * V_33 , int V_73 , T_4 * V_31 , int V_74 )
{
struct V_13 * V_48 ;
struct V_10 * V_75 ;
T_4 V_5 ;
T_4 V_29 ;
T_4 V_16 = 0 ;
if ( V_2 -> V_76 != V_77 )
return F_12 ( V_2 , V_33 , V_73 , V_31 , V_74 ) ;
V_29 = F_13 ( V_60 , V_33 , V_70 ) ;
V_5 = F_13 ( V_60 , V_33 , V_42 ) ;
V_75 = F_42 ( & V_2 -> V_8 . V_9 ) ;
while ( V_75 && V_16 < V_29 ) {
V_48 = F_2 ( V_75 , struct V_13 , V_10 ) ;
V_75 = F_43 ( V_75 ) ;
if ( V_48 -> V_5 != V_5 )
continue;
F_37 ( V_59 , V_31 , V_65 , V_16 , V_48 -> V_3 ) ;
V_16 ++ ;
}
F_11 ( V_59 , V_31 , V_78 , V_16 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , T_4 V_5 , int V_29 ,
int * V_79 )
{
int V_80 = F_34 ( V_59 ) ;
T_4 V_33 [ F_10 ( V_60 ) ] = { 0 } ;
int V_81 ;
T_4 * V_31 ;
int V_35 ;
int V_16 ;
if ( V_79 )
* V_79 = 0 ;
V_80 += V_29 * F_35 ( V_59 , V_65 [ 0 ] ) ;
V_31 = F_36 ( V_80 ) ;
if ( ! V_31 )
return - V_21 ;
F_11 ( V_60 , V_33 , V_36 , V_61 ) ;
F_11 ( V_60 , V_33 , V_38 , V_82 ) ;
F_11 ( V_60 , V_33 , V_42 , V_5 ) ;
F_11 ( V_60 , V_33 , V_70 , V_29 ) ;
F_38 ( V_2 , L_10 , V_29 , V_80 ) ;
V_35 = F_41 ( V_2 , V_33 , sizeof( V_33 ) , V_31 , V_80 ) ;
if ( V_35 ) {
F_31 ( V_2 , L_11 , V_35 ) ;
goto V_66;
}
V_81 = F_13 ( V_59 , V_31 , V_78 ) ;
if ( V_81 > V_29 ) {
F_18 ( V_2 , L_12 ,
V_81 , V_29 ) ;
V_35 = - V_83 ;
goto V_66;
}
for ( V_16 = 0 ; V_16 < V_81 ; V_16 ++ )
F_21 ( V_2 , F_40 ( V_59 , V_31 , V_65 [ V_16 ] ) ) ;
if ( V_79 )
* V_79 = V_81 ;
V_2 -> V_8 . V_71 -= V_81 ;
if ( V_5 )
V_2 -> V_8 . V_72 -= V_81 ;
V_66:
F_39 ( V_31 ) ;
return V_35 ;
}
static void F_45 ( struct V_84 * V_85 )
{
struct V_86 * V_87 = F_46 ( V_85 , struct V_86 , V_85 ) ;
struct V_1 * V_2 = V_87 -> V_2 ;
int V_35 = 0 ;
if ( V_87 -> V_29 < 0 )
V_35 = F_44 ( V_2 , V_87 -> V_5 , - 1 * V_87 -> V_29 , NULL ) ;
else if ( V_87 -> V_29 > 0 )
V_35 = F_33 ( V_2 , V_87 -> V_5 , V_87 -> V_29 , 1 ) ;
if ( V_35 )
F_18 ( V_2 , L_13 ,
V_87 -> V_29 < 0 ? L_14 : L_15 , V_35 ) ;
F_25 ( V_87 ) ;
}
void F_47 ( struct V_1 * V_2 , T_2 V_5 ,
T_3 V_29 )
{
struct V_86 * V_87 ;
V_87 = F_3 ( sizeof( * V_87 ) , V_88 ) ;
if ( ! V_87 ) {
F_18 ( V_2 , L_16 ) ;
return;
}
V_87 -> V_2 = V_2 ;
V_87 -> V_5 = V_5 ;
V_87 -> V_29 = V_29 ;
F_48 ( & V_87 -> V_85 , F_45 ) ;
F_49 ( V_2 -> V_8 . V_89 , & V_87 -> V_85 ) ;
}
int F_50 ( struct V_1 * V_2 , int V_30 )
{
T_2 V_90 ( V_5 ) ;
T_3 V_90 ( V_29 ) ;
int V_35 ;
V_35 = F_9 ( V_2 , & V_5 , & V_29 , V_30 ) ;
if ( V_35 )
return V_35 ;
F_38 ( V_2 , L_17 ,
V_29 , V_30 ? L_18 : L_19 , V_5 ) ;
return F_33 ( V_2 , V_5 , V_29 , 0 ) ;
}
static int F_51 ( void )
{
struct V_91 * V_92 ;
struct V_93 * V_94 ;
int V_95 ;
V_95 = ( sizeof( V_94 -> V_31 ) + V_96 * sizeof( V_92 -> V_97 ) -
F_34 ( V_59 ) ) /
F_35 ( V_59 , V_65 [ 0 ] ) ;
return V_95 ;
}
int F_52 ( struct V_1 * V_2 )
{
unsigned long V_98 = V_99 + F_53 ( V_100 ) ;
struct V_13 * V_48 ;
struct V_10 * V_75 ;
int V_79 = 0 ;
int V_35 = 0 ;
do {
V_75 = F_42 ( & V_2 -> V_8 . V_9 ) ;
if ( V_75 ) {
V_48 = F_2 ( V_75 , struct V_13 , V_10 ) ;
V_35 = F_44 ( V_2 , V_48 -> V_5 ,
F_51 () ,
& V_79 ) ;
if ( V_35 ) {
F_18 ( V_2 , L_20 ,
V_35 ) ;
return V_35 ;
}
if ( V_79 )
V_98 = V_99 + F_53 ( V_100 ) ;
}
if ( F_54 ( V_99 , V_98 ) ) {
F_18 ( V_2 , L_21 ) ;
break;
}
} while ( V_75 );
F_55 ( V_2 -> V_8 . V_71 ,
L_22 ,
V_2 -> V_8 . V_71 ) ;
F_55 ( V_2 -> V_8 . V_72 ,
L_23 ,
V_2 -> V_8 . V_72 ) ;
return 0 ;
}
void F_56 ( struct V_1 * V_2 )
{
V_2 -> V_8 . V_9 = V_101 ;
F_57 ( & V_2 -> V_8 . V_26 ) ;
}
void F_58 ( struct V_1 * V_2 )
{
}
int F_59 ( struct V_1 * V_2 )
{
V_2 -> V_8 . V_89 = F_60 ( L_24 ) ;
if ( ! V_2 -> V_8 . V_89 )
return - V_21 ;
return 0 ;
}
void F_61 ( struct V_1 * V_2 )
{
F_62 ( V_2 -> V_8 . V_89 ) ;
}
int F_63 ( struct V_1 * V_2 )
{
unsigned long V_98 = V_99 + F_53 ( V_102 ) ;
int V_103 = V_2 -> V_8 . V_72 ;
if ( V_2 -> V_76 == V_77 ) {
F_18 ( V_2 , L_25 ) ;
return 0 ;
}
F_38 ( V_2 , L_26 , V_103 ,
V_2 -> V_8 . V_104 ) ;
while ( V_2 -> V_8 . V_72 ) {
if ( F_54 ( V_99 , V_98 ) ) {
F_18 ( V_2 , L_27 , V_2 -> V_8 . V_72 ) ;
return - V_105 ;
}
if ( V_2 -> V_8 . V_72 < V_103 ) {
V_98 = V_99 + F_53 ( V_102 ) ;
V_103 = V_2 -> V_8 . V_72 ;
}
F_64 ( 50 ) ;
}
F_38 ( V_2 , L_28 , V_2 -> V_8 . V_104 ) ;
return 0 ;
}
