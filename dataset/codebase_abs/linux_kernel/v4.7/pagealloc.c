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
struct V_31 V_32 ;
struct V_33 V_34 ;
int V_35 ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_32 . V_36 . V_37 = F_10 ( V_38 ) ;
V_32 . V_36 . V_39 = V_30 ? F_10 ( V_40 ) : F_10 ( V_41 ) ;
V_35 = F_11 ( V_2 , & V_32 , sizeof( V_32 ) , & V_34 , sizeof( V_34 ) ) ;
if ( V_35 )
return V_35 ;
if ( V_34 . V_36 . V_42 )
return F_12 ( & V_34 . V_36 ) ;
* V_29 = F_13 ( V_34 . V_43 ) ;
* V_5 = F_14 ( V_34 . V_5 ) ;
return V_35 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_13 * V_44 ;
unsigned V_45 ;
if ( F_16 ( & V_2 -> V_8 . V_26 ) )
return - V_21 ;
V_44 = F_17 ( V_2 -> V_8 . V_26 . V_46 , struct V_13 , V_25 ) ;
V_45 = F_18 ( & V_44 -> V_24 , 8 * sizeof( V_44 -> V_24 ) ) ;
if ( V_45 >= V_23 ) {
F_19 ( V_2 , L_1 ) ;
return - V_47 ;
}
F_20 ( V_45 , & V_44 -> V_24 ) ;
V_44 -> V_22 -- ;
if ( ! V_44 -> V_22 )
F_21 ( & V_44 -> V_25 ) ;
* V_3 = V_44 -> V_3 + V_45 * V_48 ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_13 * V_49 ;
int V_45 ;
V_49 = F_8 ( V_2 , V_3 & V_50 ) ;
if ( ! V_49 ) {
F_19 ( V_2 , L_2 ) ;
return;
}
V_45 = ( V_3 & ~ V_50 ) >> V_51 ;
V_49 -> V_22 ++ ;
F_4 ( V_45 , & V_49 -> V_24 ) ;
if ( V_49 -> V_22 == V_23 ) {
F_23 ( & V_49 -> V_10 , & V_2 -> V_8 . V_9 ) ;
if ( V_49 -> V_22 != 1 )
F_21 ( & V_49 -> V_25 ) ;
F_24 ( & V_2 -> V_52 -> V_2 , V_3 & V_50 ,
V_53 , V_54 ) ;
F_25 ( V_49 -> V_4 ) ;
F_26 ( V_49 ) ;
} else if ( V_49 -> V_22 == 1 ) {
F_7 ( & V_49 -> V_25 , & V_2 -> V_8 . V_26 ) ;
}
}
static int F_27 ( struct V_1 * V_2 , T_2 V_5 )
{
struct V_4 * V_4 ;
T_1 V_3 ;
int V_35 ;
int V_55 = F_28 ( & V_2 -> V_52 -> V_2 ) ;
V_4 = F_29 ( V_55 , V_56 , 0 ) ;
if ( ! V_4 ) {
F_19 ( V_2 , L_3 ) ;
return - V_21 ;
}
V_3 = F_30 ( & V_2 -> V_52 -> V_2 , V_4 , 0 ,
V_53 , V_54 ) ;
if ( F_31 ( & V_2 -> V_52 -> V_2 , V_3 ) ) {
F_19 ( V_2 , L_4 ) ;
V_35 = - V_21 ;
goto V_57;
}
V_35 = F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
if ( V_35 ) {
F_32 ( V_2 , L_5 ) ;
goto V_58;
}
return 0 ;
V_58:
F_24 ( & V_2 -> V_52 -> V_2 , V_3 , V_53 , V_54 ) ;
V_57:
F_25 ( V_4 ) ;
return V_35 ;
}
static void F_33 ( struct V_1 * V_2 , T_2 V_5 )
{
struct V_59 * V_32 ;
struct V_60 V_34 ;
int V_35 ;
V_32 = F_3 ( sizeof( * V_32 ) , V_20 ) ;
if ( ! V_32 )
return;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_32 -> V_36 . V_37 = F_10 ( V_61 ) ;
V_32 -> V_36 . V_39 = F_10 ( V_62 ) ;
V_32 -> V_5 = F_10 ( V_5 ) ;
V_35 = F_11 ( V_2 , V_32 , sizeof( * V_32 ) , & V_34 , sizeof( V_34 ) ) ;
if ( ! V_35 )
V_35 = F_12 ( & V_34 . V_36 ) ;
if ( V_35 )
F_19 ( V_2 , L_6 ) ;
F_26 ( V_32 ) ;
}
static int F_34 ( struct V_1 * V_2 , T_2 V_5 , int V_29 ,
int V_63 )
{
struct V_59 * V_32 ;
struct V_60 V_34 ;
int V_64 ;
T_1 V_3 ;
int V_35 ;
int V_16 ;
V_64 = sizeof( * V_32 ) + V_29 * sizeof( V_32 -> V_65 [ 0 ] ) ;
V_32 = F_35 ( V_64 ) ;
if ( ! V_32 ) {
V_35 = - V_21 ;
F_19 ( V_2 , L_7 , V_64 ) ;
goto V_66;
}
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
for ( V_16 = 0 ; V_16 < V_29 ; V_16 ++ ) {
V_67:
V_35 = F_15 ( V_2 , & V_3 ) ;
if ( V_35 ) {
if ( V_35 == - V_21 )
V_35 = F_27 ( V_2 , V_5 ) ;
if ( V_35 )
goto V_68;
goto V_67;
}
V_32 -> V_65 [ V_16 ] = F_36 ( V_3 ) ;
}
V_32 -> V_36 . V_37 = F_10 ( V_61 ) ;
V_32 -> V_36 . V_39 = F_10 ( V_69 ) ;
V_32 -> V_5 = F_10 ( V_5 ) ;
V_32 -> V_70 = F_37 ( V_29 ) ;
V_35 = F_11 ( V_2 , V_32 , V_64 , & V_34 , sizeof( V_34 ) ) ;
if ( V_35 ) {
F_19 ( V_2 , L_8 ,
V_5 , V_29 , V_35 ) ;
goto V_68;
}
V_35 = F_12 ( & V_34 . V_36 ) ;
if ( V_35 ) {
F_19 ( V_2 , L_9 ,
V_5 , V_29 , V_34 . V_36 . V_42 ) ;
goto V_68;
}
V_2 -> V_8 . V_71 += V_29 ;
if ( V_5 )
V_2 -> V_8 . V_72 += V_29 ;
F_38 ( V_2 , L_10 , V_35 ) ;
F_39 ( V_32 ) ;
return 0 ;
V_68:
for ( V_16 -- ; V_16 >= 0 ; V_16 -- )
F_22 ( V_2 , F_40 ( V_32 -> V_65 [ V_16 ] ) ) ;
V_66:
F_39 ( V_32 ) ;
if ( V_63 )
F_33 ( V_2 , V_5 ) ;
return V_35 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_59 * V_32 , int V_73 ,
struct V_60 * V_34 , int V_74 )
{
struct V_13 * V_49 ;
struct V_10 * V_75 ;
T_4 V_29 ;
T_4 V_16 = 0 ;
if ( V_2 -> V_76 != V_77 )
return F_42 ( V_2 , ( T_4 * ) V_32 , V_73 ,
( T_4 * ) V_34 , V_74 ) ;
V_29 = F_13 ( V_32 -> V_70 ) ;
V_75 = F_43 ( & V_2 -> V_8 . V_9 ) ;
while ( V_75 && V_16 < V_29 ) {
V_49 = F_2 ( V_75 , struct V_13 , V_10 ) ;
V_34 -> V_65 [ V_16 ] = F_36 ( V_49 -> V_3 ) ;
V_75 = F_44 ( V_75 ) ;
V_16 ++ ;
}
V_34 -> V_70 = F_37 ( V_16 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , T_4 V_5 , int V_29 ,
int * V_78 )
{
struct V_59 V_32 ;
struct V_60 * V_34 ;
int V_79 ;
int V_80 ;
T_1 V_3 ;
int V_35 ;
int V_16 ;
if ( V_78 )
* V_78 = 0 ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_80 = sizeof( * V_34 ) + V_29 * sizeof( V_34 -> V_65 [ 0 ] ) ;
V_34 = F_35 ( V_80 ) ;
if ( ! V_34 )
return - V_21 ;
V_32 . V_36 . V_37 = F_10 ( V_61 ) ;
V_32 . V_36 . V_39 = F_10 ( V_81 ) ;
V_32 . V_5 = F_10 ( V_5 ) ;
V_32 . V_70 = F_37 ( V_29 ) ;
F_38 ( V_2 , L_11 , V_29 , V_80 ) ;
V_35 = F_41 ( V_2 , & V_32 , sizeof( V_32 ) , V_34 , V_80 ) ;
if ( V_35 ) {
F_32 ( V_2 , L_12 , V_35 ) ;
goto V_66;
}
V_79 = F_13 ( V_34 -> V_70 ) ;
if ( V_79 > V_29 ) {
F_19 ( V_2 , L_13 ,
V_79 , V_29 ) ;
V_35 = - V_82 ;
goto V_66;
}
for ( V_16 = 0 ; V_16 < V_79 ; V_16 ++ ) {
V_3 = F_40 ( V_34 -> V_65 [ V_16 ] ) ;
F_22 ( V_2 , V_3 ) ;
}
if ( V_78 )
* V_78 = V_79 ;
V_2 -> V_8 . V_71 -= V_79 ;
if ( V_5 )
V_2 -> V_8 . V_72 -= V_79 ;
V_66:
F_39 ( V_34 ) ;
return V_35 ;
}
static void F_46 ( struct V_83 * V_84 )
{
struct V_85 * V_86 = F_47 ( V_84 , struct V_85 , V_84 ) ;
struct V_1 * V_2 = V_86 -> V_2 ;
int V_35 = 0 ;
if ( V_86 -> V_29 < 0 )
V_35 = F_45 ( V_2 , V_86 -> V_5 , - 1 * V_86 -> V_29 , NULL ) ;
else if ( V_86 -> V_29 > 0 )
V_35 = F_34 ( V_2 , V_86 -> V_5 , V_86 -> V_29 , 1 ) ;
if ( V_35 )
F_19 ( V_2 , L_14 ,
V_86 -> V_29 < 0 ? L_15 : L_16 , V_35 ) ;
F_26 ( V_86 ) ;
}
void F_48 ( struct V_1 * V_2 , T_2 V_5 ,
T_3 V_29 )
{
struct V_85 * V_86 ;
V_86 = F_3 ( sizeof( * V_86 ) , V_87 ) ;
if ( ! V_86 ) {
F_19 ( V_2 , L_17 ) ;
return;
}
V_86 -> V_2 = V_2 ;
V_86 -> V_5 = V_5 ;
V_86 -> V_29 = V_29 ;
F_49 ( & V_86 -> V_84 , F_46 ) ;
F_50 ( V_2 -> V_8 . V_88 , & V_86 -> V_84 ) ;
}
int F_51 ( struct V_1 * V_2 , int V_30 )
{
T_2 V_89 ( V_5 ) ;
T_3 V_89 ( V_29 ) ;
int V_35 ;
V_35 = F_9 ( V_2 , & V_5 , & V_29 , V_30 ) ;
if ( V_35 )
return V_35 ;
F_38 ( V_2 , L_18 ,
V_29 , V_30 ? L_19 : L_20 , V_5 ) ;
return F_34 ( V_2 , V_5 , V_29 , 0 ) ;
}
static int F_52 ( void )
{
struct V_90 * V_91 ;
struct V_92 * V_93 ;
int V_94 ;
V_94 = ( sizeof( V_93 -> V_34 ) + V_95 * sizeof( V_91 -> V_96 ) -
sizeof( struct V_60 ) ) /
F_53 ( struct V_60 , V_65 [ 0 ] ) ;
return V_94 ;
}
int F_54 ( struct V_1 * V_2 )
{
unsigned long V_97 = V_98 + F_55 ( V_99 ) ;
struct V_13 * V_49 ;
struct V_10 * V_75 ;
int V_78 = 0 ;
int V_35 = 0 ;
do {
V_75 = F_43 ( & V_2 -> V_8 . V_9 ) ;
if ( V_75 ) {
V_49 = F_2 ( V_75 , struct V_13 , V_10 ) ;
V_35 = F_45 ( V_2 , V_49 -> V_5 ,
F_52 () ,
& V_78 ) ;
if ( V_35 ) {
F_19 ( V_2 , L_21 ,
V_35 ) ;
return V_35 ;
}
if ( V_78 )
V_97 = V_98 + F_55 ( V_99 ) ;
}
if ( F_56 ( V_98 , V_97 ) ) {
F_19 ( V_2 , L_22 ) ;
break;
}
} while ( V_75 );
F_57 ( V_2 -> V_8 . V_71 ,
L_23 ,
V_2 -> V_8 . V_71 ) ;
F_57 ( V_2 -> V_8 . V_72 ,
L_24 ,
V_2 -> V_8 . V_72 ) ;
return 0 ;
}
void F_58 ( struct V_1 * V_2 )
{
V_2 -> V_8 . V_9 = V_100 ;
F_59 ( & V_2 -> V_8 . V_26 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
}
int F_61 ( struct V_1 * V_2 )
{
V_2 -> V_8 . V_88 = F_62 ( L_25 ) ;
if ( ! V_2 -> V_8 . V_88 )
return - V_21 ;
return 0 ;
}
void F_63 ( struct V_1 * V_2 )
{
F_64 ( V_2 -> V_8 . V_88 ) ;
}
int F_65 ( struct V_1 * V_2 )
{
unsigned long V_97 = V_98 + F_55 ( V_101 ) ;
int V_102 = V_2 -> V_8 . V_72 ;
F_38 ( V_2 , L_26 , V_102 ,
V_2 -> V_8 . V_103 ) ;
while ( V_2 -> V_8 . V_72 ) {
if ( F_56 ( V_98 , V_97 ) ) {
F_19 ( V_2 , L_27 , V_2 -> V_8 . V_72 ) ;
return - V_104 ;
}
if ( V_2 -> V_8 . V_72 < V_102 ) {
V_97 = V_98 + F_55 ( V_101 ) ;
V_102 = V_2 -> V_8 . V_72 ;
}
F_66 ( 50 ) ;
}
F_38 ( V_2 , L_28 , V_2 -> V_8 . V_103 ) ;
return 0 ;
}
