unsigned F_1 ( struct V_1 * V_2 ,
unsigned V_3 )
{
unsigned V_4 = F_2 ( unsigned , V_3 , V_5 ) ;
V_4 = F_2 ( unsigned , V_4 ,
V_2 -> V_6 * V_7 ) ;
return V_4 ;
}
static void F_3 ( struct V_8 * V_9 , unsigned V_3 ,
struct V_10 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 -> V_14 ;
V_9 -> V_12 = V_12 ;
V_9 -> V_10 = V_10 ;
V_9 -> V_3 = V_3 ;
V_9 -> V_15 = NULL ;
V_9 -> V_4 = NULL ;
V_9 -> V_16 = 0 ;
V_9 -> V_17 = 0 ;
V_9 -> V_18 = 0 ;
V_9 -> V_19 = - 1 ;
V_9 -> V_20 = false ;
}
static void F_4 ( struct V_8 * V_9 )
{
V_9 -> V_3 -= F_5 ( V_9 -> V_17 , V_9 -> V_3 ) ;
V_9 -> V_4 = NULL ;
V_9 -> V_16 = 0 ;
V_9 -> V_17 = 0 ;
V_9 -> V_18 = 0 ;
V_9 -> V_19 = - 1 ;
V_9 -> V_15 = NULL ;
if ( ! V_9 -> V_3 )
V_9 -> V_3 = V_5 ;
}
static int F_6 ( struct V_8 * V_9 )
{
unsigned V_4 ;
if ( ! V_9 -> V_15 ) {
int V_21 = F_7 ( & V_9 -> V_12 -> V_2 , & V_9 -> V_15 ) ;
if ( V_21 )
return V_21 ;
}
V_4 = F_1 ( & V_9 -> V_12 -> V_2 , V_9 -> V_3 ) ;
for (; V_4 ; V_4 >>= 1 ) {
V_9 -> V_4 = F_8 ( V_4 * sizeof( struct V_22 * ) ,
V_23 ) ;
if ( F_9 ( V_9 -> V_4 ) ) {
V_9 -> V_16 = V_4 ;
return 0 ;
}
}
F_10 ( L_1 ,
V_9 -> V_3 ) ;
return - V_24 ;
}
static void F_11 ( struct V_8 * V_9 )
{
F_12 ( V_9 -> V_4 ) ;
V_9 -> V_4 = NULL ;
if ( V_9 -> V_15 ) {
F_13 ( V_9 -> V_15 ) ;
V_9 -> V_15 = NULL ;
}
}
static int F_14 ( struct V_8 * V_9 , struct V_22 * V_22 ,
unsigned V_25 )
{
if ( F_15 ( V_9 -> V_17 >= V_9 -> V_16 ) )
return - V_24 ;
V_9 -> V_4 [ V_9 -> V_17 ++ ] = V_22 ;
V_9 -> V_18 += V_25 ;
return 0 ;
}
static int F_16 ( struct V_22 * V_22 , int V_21 )
{
if ( V_21 == 0 ) {
F_17 ( V_22 ) ;
if ( F_18 ( V_22 ) )
F_19 ( V_22 ) ;
} else if ( V_21 == - V_26 ) {
F_20 ( V_22 ) ;
F_17 ( V_22 ) ;
if ( F_18 ( V_22 ) )
F_19 ( V_22 ) ;
V_21 = 0 ;
F_21 ( L_2 ) ;
} else
F_22 ( V_22 ) ;
return V_21 ;
}
static void F_23 ( struct V_22 * V_22 , int V_21 )
{
if ( V_21 ) {
F_24 ( V_22 -> V_27 , V_21 ) ;
F_22 ( V_22 ) ;
}
F_25 ( V_22 ) ;
}
static int F_26 ( struct V_8 * V_9 )
{
int V_28 ;
T_1 V_29 ;
T_1 V_30 ;
T_1 V_18 = 0 ;
int V_21 = F_27 ( V_9 -> V_15 , & V_29 ) ;
if ( F_9 ( ! V_21 ) )
V_30 = V_9 -> V_18 ;
else
V_30 = V_9 -> V_18 - V_29 ;
F_28 ( L_3
L_4 ,
V_9 -> V_10 -> V_31 , F_29 ( V_30 ) , V_9 -> V_18 ,
V_9 -> V_17 ) ;
for ( V_28 = 0 ; V_28 < V_9 -> V_17 ; V_28 ++ ) {
struct V_22 * V_22 = V_9 -> V_4 [ V_28 ] ;
struct V_10 * V_10 = V_22 -> V_27 -> V_32 ;
int V_33 ;
if ( V_10 != V_9 -> V_10 )
continue;
if ( F_9 ( V_18 < V_30 ) )
V_33 = 0 ;
else
V_33 = V_21 ;
F_28 ( L_5 ,
V_10 -> V_31 , V_22 -> V_34 ,
V_33 ? L_6 : L_7 ) ;
V_21 = F_16 ( V_22 , V_33 ) ;
if ( ! V_9 -> V_20 )
F_30 ( V_22 ) ;
V_18 += V_35 ;
}
F_11 ( V_9 ) ;
F_28 ( L_8 ) ;
return V_21 ;
}
static void F_31 ( struct V_36 * V_15 , void * V_37 )
{
struct V_8 * V_9 = V_37 ;
F_26 ( V_9 ) ;
F_32 ( & V_9 -> V_12 -> V_38 ) ;
F_12 ( V_9 ) ;
}
static void F_33 ( struct V_8 * V_9 , int V_21 , int V_39 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_9 -> V_17 ; V_28 ++ ) {
struct V_22 * V_22 = V_9 -> V_4 [ V_28 ] ;
if ( V_39 == V_40 )
F_16 ( V_22 , V_21 ) ;
else
F_23 ( V_22 , V_21 ) ;
F_30 ( V_22 ) ;
}
}
static int F_34 ( struct V_8 * V_9 )
{
struct V_41 * V_42 = F_35 ( V_9 -> V_10 ) ;
struct V_36 * V_15 = V_9 -> V_15 ;
struct V_8 * V_43 = NULL ;
int V_21 ;
if ( ! V_9 -> V_4 )
return 0 ;
V_15 -> V_4 = V_9 -> V_4 ;
V_15 -> V_17 = V_9 -> V_17 ;
V_15 -> V_18 = V_9 -> V_18 ;
V_15 -> V_44 = V_9 -> V_19 << V_45 ;
if ( V_9 -> V_20 ) {
F_36 ( V_42 , V_9 -> V_15 ) ;
return F_26 ( V_9 ) ;
}
V_43 = F_8 ( sizeof( * V_43 ) , V_23 ) ;
if ( ! V_43 ) {
V_21 = - V_24 ;
goto V_46;
}
* V_43 = * V_9 ;
V_15 -> V_47 = F_31 ;
V_15 -> V_48 = V_43 ;
V_21 = F_36 ( V_42 , V_15 ) ;
if ( F_15 ( V_21 ) )
goto V_46;
F_37 ( & V_9 -> V_12 -> V_38 ) ;
F_28 ( L_9 ,
V_15 -> V_49 . V_50 , F_29 ( V_15 -> V_44 ) , V_9 -> V_18 ) ;
F_4 ( V_9 ) ;
return 0 ;
V_46:
if ( ! V_9 -> V_20 )
F_33 ( V_9 , V_21 , V_40 ) ;
F_11 ( V_9 ) ;
F_12 ( V_43 ) ;
return V_21 ;
}
static int F_38 ( void * V_51 , struct V_22 * V_22 )
{
struct V_8 * V_9 = V_51 ;
struct V_10 * V_10 = V_9 -> V_10 ;
struct V_41 * V_42 = F_35 ( V_10 ) ;
T_2 V_52 = F_39 ( V_10 ) ;
T_3 V_53 = V_52 >> V_45 ;
T_4 V_25 ;
int V_21 ;
if ( F_40 ( V_22 ) )
F_10 ( L_10 , V_9 -> V_10 -> V_31 ,
V_22 -> V_34 ) ;
if ( V_22 -> V_34 < V_53 )
V_25 = V_54 ;
else if ( V_22 -> V_34 == V_53 )
V_25 = V_52 & ~ V_55 ;
else
V_25 = 0 ;
if ( ! V_25 || ! F_41 ( V_42 ) ) {
F_20 ( V_22 ) ;
F_17 ( V_22 ) ;
if ( F_18 ( V_22 ) )
F_19 ( V_22 ) ;
if ( ! V_9 -> V_20 )
F_30 ( V_22 ) ;
F_21 ( L_11
L_12
L_13 , V_10 -> V_31 , V_25 ,
V_9 -> V_20 , V_22 -> V_34 , V_53 ) ;
return F_34 ( V_9 ) ;
}
V_56:
if ( F_15 ( V_9 -> V_19 == - 1 ) ) {
V_9 -> V_19 = V_22 -> V_34 ;
} else if ( F_15 ( ( V_9 -> V_19 + V_9 -> V_17 ) !=
V_22 -> V_34 ) ) {
V_21 = F_34 ( V_9 ) ;
if ( F_15 ( V_21 ) )
goto V_57;
goto V_56;
}
if ( ! V_9 -> V_4 ) {
V_21 = F_6 ( V_9 ) ;
if ( F_15 ( V_21 ) )
goto V_57;
}
if ( V_25 != V_54 )
F_42 ( V_22 , V_25 , V_54 - V_25 ) ;
F_28 ( L_14 ,
V_10 -> V_31 , V_22 -> V_34 , V_25 ) ;
V_21 = F_14 ( V_9 , V_22 , V_25 ) ;
if ( V_21 ) {
F_28 ( L_15
L_16 ,
V_22 , V_25 , V_9 -> V_17 , V_9 -> V_18 ) ;
V_21 = F_34 ( V_9 ) ;
if ( F_15 ( V_21 ) )
goto V_57;
goto V_56;
}
return 0 ;
V_57:
F_30 ( V_22 ) ;
return V_21 ;
}
static int F_43 ( struct V_58 * V_58 , struct V_59 * V_27 ,
struct V_60 * V_4 , unsigned V_17 )
{
struct V_8 V_9 ;
int V_21 ;
F_3 ( & V_9 , V_17 , V_27 -> V_32 ) ;
V_21 = F_44 ( V_27 , V_4 , F_38 , & V_9 ) ;
if ( V_21 ) {
F_10 ( L_17 , V_21 ) ;
return V_21 ;
}
return F_34 ( & V_9 ) ;
}
static int F_45 ( struct V_22 * V_22 , bool V_20 )
{
struct V_8 V_9 ;
int V_21 ;
F_3 ( & V_9 , 1 , V_22 -> V_27 -> V_32 ) ;
V_9 . V_20 = V_20 ;
V_21 = F_38 ( & V_9 , V_22 ) ;
if ( V_21 ) {
F_10 ( L_18 , V_21 ) ;
return V_21 ;
}
return F_34 ( & V_9 ) ;
}
static int F_46 ( struct V_58 * V_58 , struct V_22 * V_22 )
{
return F_45 ( V_22 , false ) ;
}
static void F_47 ( struct V_36 * V_15 , void * V_37 )
{
struct V_8 * V_9 = V_37 ;
int V_28 ;
T_1 V_29 ;
T_1 V_30 ;
T_1 V_18 = 0 ;
int V_21 = F_27 ( V_15 , & V_29 ) ;
F_32 ( & V_9 -> V_12 -> V_38 ) ;
if ( F_9 ( ! V_21 ) )
V_30 = V_9 -> V_18 ;
else
V_30 = V_9 -> V_18 - V_29 ;
F_28 ( L_19
L_4 ,
V_9 -> V_10 -> V_31 , F_29 ( V_30 ) , V_9 -> V_18 ,
V_9 -> V_17 ) ;
for ( V_28 = 0 ; V_28 < V_9 -> V_17 ; V_28 ++ ) {
struct V_22 * V_22 = V_9 -> V_4 [ V_28 ] ;
struct V_10 * V_10 = V_22 -> V_27 -> V_32 ;
int V_33 ;
if ( V_10 != V_9 -> V_10 )
continue;
if ( F_9 ( V_18 < V_30 ) )
V_33 = 0 ;
else
V_33 = V_21 ;
F_23 ( V_22 , V_33 ) ;
F_30 ( V_22 ) ;
F_28 ( L_20 ,
V_10 -> V_31 , V_22 -> V_34 , V_33 ) ;
V_18 += V_35 ;
}
F_11 ( V_9 ) ;
F_12 ( V_9 ) ;
F_28 ( L_21 ) ;
}
static int F_48 ( struct V_8 * V_9 )
{
struct V_41 * V_42 = F_35 ( V_9 -> V_10 ) ;
struct V_36 * V_15 = V_9 -> V_15 ;
struct V_8 * V_43 = NULL ;
int V_21 ;
if ( ! V_9 -> V_4 )
return 0 ;
V_43 = F_8 ( sizeof( * V_43 ) , V_23 ) ;
if ( ! V_43 ) {
F_10 ( L_22 ) ;
V_21 = - V_24 ;
goto V_46;
}
* V_43 = * V_9 ;
V_15 -> V_4 = V_43 -> V_4 ;
V_15 -> V_17 = V_43 -> V_17 ;
V_15 -> V_44 = V_43 -> V_19 << V_45 ;
V_15 -> V_18 = V_43 -> V_18 ;
V_15 -> V_47 = F_47 ;
V_15 -> V_48 = V_43 ;
V_21 = F_49 ( V_42 , V_15 ) ;
if ( F_15 ( V_21 ) ) {
F_10 ( L_23 ) ;
goto V_46;
}
F_37 ( & V_9 -> V_12 -> V_38 ) ;
F_28 ( L_24 ,
V_9 -> V_10 -> V_31 , V_9 -> V_19 , F_29 ( V_15 -> V_44 ) ,
V_9 -> V_18 ) ;
F_4 ( V_9 ) ;
return 0 ;
V_46:
F_33 ( V_9 , V_21 , V_61 ) ;
F_11 ( V_9 ) ;
F_12 ( V_43 ) ;
return V_21 ;
}
static int F_50 ( struct V_22 * V_22 ,
struct V_62 * V_63 , void * V_51 )
{
struct V_8 * V_9 = V_51 ;
struct V_10 * V_10 = V_9 -> V_10 ;
struct V_41 * V_42 = F_35 ( V_10 ) ;
T_2 V_52 = F_39 ( V_10 ) ;
T_3 V_53 = V_52 >> V_45 ;
T_4 V_25 ;
int V_21 ;
F_51 ( ! F_52 ( V_22 ) ) ;
V_21 = F_53 ( V_42 ) ;
if ( F_15 ( V_21 ) )
goto V_57;
if ( V_22 -> V_34 < V_53 )
V_25 = V_54 ;
else {
V_25 = V_52 & ~ V_55 ;
if ( V_22 -> V_34 > V_53 || ! V_25 ) {
V_21 = F_48 ( V_9 ) ;
if ( F_15 ( V_21 ) )
goto V_57;
if ( F_18 ( V_22 ) )
F_19 ( V_22 ) ;
F_30 ( V_22 ) ;
F_21 ( L_25
L_26 ,
V_10 -> V_31 , V_22 -> V_34 ) ;
return 0 ;
}
}
V_56:
if ( F_15 ( V_9 -> V_19 == - 1 ) ) {
V_9 -> V_19 = V_22 -> V_34 ;
} else if ( F_15 ( ( V_9 -> V_19 + V_9 -> V_17 ) !=
V_22 -> V_34 ) ) {
V_21 = F_48 ( V_9 ) ;
if ( F_15 ( V_21 ) )
goto V_57;
F_21 ( L_27 ,
V_10 -> V_31 , V_22 -> V_34 ) ;
goto V_56;
}
if ( ! V_9 -> V_4 ) {
V_21 = F_6 ( V_9 ) ;
if ( F_15 ( V_21 ) )
goto V_57;
}
F_28 ( L_28 ,
V_10 -> V_31 , V_22 -> V_34 , V_25 ) ;
V_21 = F_14 ( V_9 , V_22 , V_25 ) ;
if ( F_15 ( V_21 ) ) {
F_28 ( L_29
L_30 ,
V_9 -> V_17 , V_9 -> V_18 ) ;
V_21 = F_48 ( V_9 ) ;
if ( F_15 ( V_21 ) ) {
F_21 ( L_31 , V_21 ) ;
goto V_57;
}
goto V_56;
}
F_51 ( F_54 ( V_22 ) ) ;
F_55 ( V_22 ) ;
return 0 ;
V_57:
F_21 ( L_32 ,
V_10 -> V_31 , V_22 -> V_34 , V_21 ) ;
F_56 ( V_64 , & V_22 -> V_27 -> V_65 ) ;
F_30 ( V_22 ) ;
return V_21 ;
}
static int F_57 ( struct V_59 * V_27 ,
struct V_62 * V_66 )
{
struct V_8 V_9 ;
long V_67 , V_68 , V_3 ;
int V_21 ;
V_67 = V_66 -> V_69 >> V_45 ;
V_68 = ( V_66 -> V_70 == V_71 ) ?
V_67 + V_27 -> V_72 :
V_66 -> V_70 >> V_45 ;
if ( V_67 || V_68 )
V_3 = V_68 - V_67 + 1 ;
else
V_3 = V_27 -> V_72 ;
if ( V_3 < 32L )
V_3 = 32L ;
F_28 ( L_33
L_34 ,
V_27 -> V_32 -> V_31 , V_66 -> V_69 , V_66 -> V_70 ,
V_27 -> V_72 , V_67 , V_68 , V_3 ) ;
F_3 ( & V_9 , V_3 , V_27 -> V_32 ) ;
V_21 = F_58 ( V_27 , V_66 , F_50 , & V_9 ) ;
if ( V_21 ) {
F_10 ( L_35 , V_21 ) ;
return V_21 ;
}
return F_48 ( & V_9 ) ;
}
static int F_59 ( struct V_22 * V_22 , struct V_62 * V_66 )
{
struct V_8 V_9 ;
int V_21 ;
F_3 ( & V_9 , 1 , V_22 -> V_27 -> V_32 ) ;
V_21 = F_50 ( V_22 , NULL , & V_9 ) ;
if ( V_21 ) {
F_10 ( L_36 , V_21 ) ;
return V_21 ;
}
return F_48 ( & V_9 ) ;
}
static void F_60 ( struct V_10 * V_10 , T_2 V_73 )
{
if ( V_73 > V_10 -> V_52 )
F_61 ( V_10 , V_73 , V_10 -> V_52 ) ;
}
int F_62 ( struct V_58 * V_58 , struct V_59 * V_27 ,
T_2 V_74 , unsigned V_25 , unsigned V_65 ,
struct V_22 * * V_75 , void * * V_76 )
{
int V_21 = 0 ;
struct V_22 * V_22 ;
V_22 = * V_75 ;
if ( V_22 == NULL ) {
V_21 = F_63 ( V_58 , V_27 , V_74 , V_25 , V_65 , V_75 ,
V_76 ) ;
if ( V_21 ) {
F_21 ( L_37 ) ;
goto V_77;
}
V_22 = * V_75 ;
}
if ( ! F_40 ( V_22 ) && ( V_25 != V_54 ) ) {
T_2 V_52 = F_39 ( V_27 -> V_32 ) ;
T_3 V_53 = V_52 >> V_45 ;
T_4 V_78 ;
if ( V_22 -> V_34 < V_53 )
V_78 = V_54 ;
else if ( V_22 -> V_34 == V_53 )
V_78 = V_52 & ~ V_55 ;
else
V_78 = 0 ;
if ( ! V_78 ) {
F_20 ( V_22 ) ;
F_17 ( V_22 ) ;
goto V_77;
}
V_21 = F_45 ( V_22 , true ) ;
if ( V_21 ) {
F_30 ( V_22 ) ;
F_21 ( L_38 ) ;
}
}
V_77:
if ( F_15 ( V_21 ) )
F_60 ( V_27 -> V_32 , V_74 + V_25 ) ;
return V_21 ;
}
static int F_64 ( struct V_58 * V_58 ,
struct V_59 * V_27 ,
T_2 V_74 , unsigned V_25 , unsigned V_65 ,
struct V_22 * * V_75 , void * * V_76 )
{
* V_75 = NULL ;
return F_62 ( V_58 , V_27 , V_74 , V_25 , V_65 , V_75 ,
V_76 ) ;
}
static int F_65 ( struct V_58 * V_58 , struct V_59 * V_27 ,
T_2 V_74 , unsigned V_25 , unsigned V_79 ,
struct V_22 * V_22 , void * V_76 )
{
struct V_10 * V_10 = V_27 -> V_32 ;
T_2 V_52 = V_10 -> V_52 ;
int V_21 ;
V_21 = F_66 ( V_58 , V_27 , V_74 , V_25 , V_79 , V_22 , V_76 ) ;
if ( F_15 ( V_21 ) )
F_60 ( V_10 , V_74 + V_25 ) ;
if ( V_52 != V_10 -> V_52 )
F_67 ( V_10 ) ;
return V_21 ;
}
static int F_68 ( struct V_22 * V_22 , T_5 V_80 )
{
F_21 ( L_39 , V_22 -> V_34 ) ;
F_69 ( 1 ) ;
return 0 ;
}
static void F_70 ( struct V_22 * V_22 , unsigned long V_44 )
{
F_21 ( L_40 , V_22 -> V_34 , V_44 ) ;
F_69 ( 1 ) ;
}
static inline int F_71 ( struct V_10 * V_10 )
{
struct V_41 * V_42 = F_35 ( V_10 ) ;
return F_72 ( V_10 -> V_81 ) && ( V_42 -> V_82 [ 0 ] != 0 ) ;
}
static int F_73 ( struct V_10 * V_10 , T_2 V_83 )
{
struct V_41 * V_42 = F_35 ( V_10 ) ;
int V_21 ;
V_10 -> V_84 = V_10 -> V_85 = V_86 ;
V_21 = F_74 ( V_42 , ( T_1 ) V_83 ) ;
if ( F_9 ( ! V_21 ) )
F_75 ( V_10 , V_83 ) ;
F_21 ( L_41 ,
V_10 -> V_31 , V_83 , V_21 ) ;
return V_21 ;
}
int F_76 ( struct V_87 * V_87 , struct V_88 * V_88 )
{
struct V_10 * V_10 = V_87 -> V_89 ;
int error ;
error = F_53 ( F_35 ( V_10 ) ) ;
if ( F_15 ( error ) )
return error ;
error = F_77 ( V_10 , V_88 ) ;
if ( F_15 ( error ) )
return error ;
if ( ( V_88 -> V_90 & V_91 ) &&
V_88 -> V_92 != F_39 ( V_10 ) ) {
error = F_73 ( V_10 , V_88 -> V_92 ) ;
if ( F_15 ( error ) )
return error ;
}
F_78 ( V_10 , V_88 ) ;
F_67 ( V_10 ) ;
return 0 ;
}
static int F_79 ( struct V_93 * V_94 , struct V_41 * V_42 ,
struct V_95 * V_10 )
{
struct V_11 * V_12 = V_94 -> V_14 ;
struct V_96 V_97 [] = {
[ 0 ] = V_98 ,
[ 1 ] = V_99 ,
[ 2 ] = V_100 ,
} ;
struct V_36 * V_15 ;
struct V_101 * V_2 ;
int V_21 ;
V_21 = F_7 ( & V_12 -> V_2 , & V_15 ) ;
if ( F_15 ( V_21 ) ) {
F_10 ( L_42 , V_102 ) ;
return V_21 ;
}
V_15 -> V_49 . V_50 = F_80 ( V_42 ) ;
F_81 ( V_42 -> V_103 , & V_15 -> V_49 ) ;
V_15 -> V_104 = V_42 -> V_103 ;
V_97 [ 1 ] . V_25 = F_82 ( V_12 -> V_2 . V_105 ) ;
V_97 [ 2 ] . V_25 = F_82 ( V_12 -> V_2 . V_105 ) ;
V_15 -> V_106 = V_97 ;
V_15 -> V_107 = F_83 ( V_97 ) ;
V_21 = F_84 ( V_15 ) ;
if ( F_15 ( V_21 ) ) {
F_10 ( L_43 ,
F_29 ( V_15 -> V_49 . V_50 ) , V_21 ) ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_81 = 0040000 | ( 0777 & ~ 022 ) ;
if ( ( V_21 == - V_108 ) || ( V_21 == - V_109 ) )
V_21 = 0 ;
goto V_77;
}
V_21 = F_85 ( V_15 , & V_97 [ 0 ] ) ;
if ( V_21 ) {
F_10 ( L_44 , V_102 ) ;
goto V_77;
}
F_69 ( V_97 [ 0 ] . V_25 != V_110 ) ;
memcpy ( V_10 , V_97 [ 0 ] . V_111 , V_110 ) ;
V_21 = F_85 ( V_15 , & V_97 [ 1 ] ) ;
if ( V_21 ) {
F_10 ( L_44 , V_102 ) ;
goto V_77;
}
if ( V_97 [ 1 ] . V_25 ) {
V_2 = V_97 [ 1 ] . V_111 ;
if ( V_2 -> V_112 != F_86 ( V_113 ) ) {
F_10 ( L_45 ,
V_102 , V_2 -> V_112 ) ;
V_21 = - V_114 ;
goto V_77;
}
}
V_21 = F_85 ( V_15 , & V_97 [ 2 ] ) ;
if ( V_21 ) {
F_10 ( L_44 , V_102 ) ;
goto V_77;
}
if ( V_97 [ 2 ] . V_25 ) {
V_2 = V_97 [ 2 ] . V_111 ;
if ( V_2 -> V_112 != F_86 ( V_113 ) ) {
F_10 ( L_46 ,
V_102 , V_2 -> V_112 ) ;
V_21 = - V_114 ;
goto V_77;
}
}
V_77:
F_13 ( V_15 ) ;
return V_21 ;
}
static void F_87 ( struct V_41 * V_42 )
{
F_88 ( & V_42 -> V_115 ) ;
V_42 -> V_116 = 0 ;
}
struct V_10 * F_89 ( struct V_93 * V_94 , unsigned long V_117 )
{
struct V_41 * V_42 ;
struct V_95 V_118 ;
struct V_10 * V_10 ;
int V_21 ;
V_10 = F_90 ( V_94 , V_117 ) ;
if ( ! V_10 )
return F_91 ( - V_24 ) ;
if ( ! ( V_10 -> V_119 & V_120 ) )
return V_10 ;
V_42 = F_35 ( V_10 ) ;
F_87 ( V_42 ) ;
V_21 = F_79 ( V_94 , V_42 , & V_118 ) ;
if ( V_21 )
goto V_121;
F_92 ( V_42 ) ;
V_10 -> V_81 = F_93 ( V_118 . V_81 ) ;
V_10 -> V_122 = F_94 ( V_118 . V_122 ) ;
V_10 -> V_123 = F_94 ( V_118 . V_123 ) ;
V_10 -> V_124 = F_93 ( V_118 . V_125 ) ;
V_10 -> V_85 . V_126 = ( signed ) F_94 ( V_118 . V_85 ) ;
V_10 -> V_127 . V_126 = ( signed ) F_94 ( V_118 . V_127 ) ;
V_10 -> V_84 . V_126 = ( signed ) F_94 ( V_118 . V_84 ) ;
V_10 -> V_85 . V_128 =
V_10 -> V_127 . V_128 = V_10 -> V_84 . V_128 = 0 ;
V_42 -> V_129 = F_95 ( V_118 . V_52 ) ;
F_96 ( V_10 , V_42 -> V_129 ) ;
V_10 -> V_130 = V_131 ;
V_10 -> V_132 = F_94 ( V_118 . V_132 ) ;
V_42 -> V_133 = 0 ;
if ( ( V_10 -> V_124 == 0 ) && ( V_10 -> V_81 == 0 ) ) {
V_21 = - V_134 ;
goto V_121;
}
if ( F_97 ( V_10 -> V_81 ) || F_98 ( V_10 -> V_81 ) ) {
if ( V_118 . V_82 [ 0 ] )
V_10 -> V_135 =
F_99 ( F_94 ( V_118 . V_82 [ 0 ] ) ) ;
else
V_10 -> V_135 =
F_100 ( F_94 ( V_118 . V_82 [ 1 ] ) ) ;
} else {
memcpy ( V_42 -> V_82 , V_118 . V_82 , sizeof( V_118 . V_82 ) ) ;
}
V_10 -> V_136 -> V_137 = V_94 -> V_138 ;
if ( F_101 ( V_10 -> V_81 ) ) {
V_10 -> V_139 = & V_140 ;
V_10 -> V_141 = & V_142 ;
V_10 -> V_136 -> V_143 = & V_144 ;
} else if ( F_102 ( V_10 -> V_81 ) ) {
V_10 -> V_139 = & V_145 ;
V_10 -> V_141 = & V_146 ;
V_10 -> V_136 -> V_143 = & V_144 ;
} else if ( F_72 ( V_10 -> V_81 ) ) {
if ( F_71 ( V_10 ) )
V_10 -> V_139 = & V_147 ;
else {
V_10 -> V_139 = & V_148 ;
V_10 -> V_136 -> V_143 = & V_144 ;
}
} else {
V_10 -> V_139 = & V_149 ;
if ( V_118 . V_82 [ 0 ] )
F_103 ( V_10 , V_10 -> V_81 ,
F_99 ( F_94 ( V_118 . V_82 [ 0 ] ) ) ) ;
else
F_103 ( V_10 , V_10 -> V_81 ,
F_100 ( F_94 ( V_118 . V_82 [ 1 ] ) ) ) ;
}
F_104 ( V_10 ) ;
return V_10 ;
V_121:
F_105 ( V_10 ) ;
return F_91 ( V_21 ) ;
}
int F_106 ( struct V_41 * V_42 )
{
if ( ! F_41 ( V_42 ) ) {
F_21 ( L_47 ) ;
F_51 ( ! F_107 ( V_42 ) ) ;
F_108 ( V_42 -> V_115 , F_41 ( V_42 ) ) ;
F_21 ( L_48 ) ;
}
return F_15 ( F_109 ( & V_42 -> V_150 ) ) ? - V_151 : 0 ;
}
static void F_110 ( struct V_36 * V_15 , void * V_37 )
{
struct V_10 * V_10 = V_37 ;
struct V_41 * V_42 = F_35 ( V_10 ) ;
struct V_11 * V_12 = V_10 -> V_13 -> V_14 ;
int V_21 ;
V_21 = F_27 ( V_15 , NULL ) ;
F_13 ( V_15 ) ;
F_32 ( & V_12 -> V_38 ) ;
if ( F_15 ( V_21 ) ) {
F_10 ( L_49 ,
F_29 ( F_80 ( V_42 ) ) , F_29 ( V_12 -> V_2 . V_152 ) ) ;
}
F_92 ( V_42 ) ;
F_111 ( & V_42 -> V_115 ) ;
}
struct V_10 * F_112 ( struct V_10 * V_153 , int V_154 )
{
struct V_93 * V_94 ;
struct V_10 * V_10 ;
struct V_41 * V_42 ;
struct V_11 * V_12 ;
struct V_36 * V_15 ;
int V_21 ;
V_94 = V_153 -> V_13 ;
V_10 = F_113 ( V_94 ) ;
if ( ! V_10 )
return F_91 ( - V_24 ) ;
V_42 = F_35 ( V_10 ) ;
F_87 ( V_42 ) ;
F_114 ( V_42 ) ;
V_12 = V_94 -> V_14 ;
V_10 -> V_136 -> V_137 = V_94 -> V_138 ;
F_115 ( V_10 , V_153 , V_154 ) ;
V_10 -> V_31 = V_12 -> V_155 ++ ;
V_10 -> V_130 = V_131 ;
V_10 -> V_84 = V_10 -> V_127 = V_10 -> V_85 = V_86 ;
V_42 -> V_129 = V_10 -> V_52 = 0 ;
F_116 ( & V_12 -> V_156 ) ;
V_10 -> V_132 = V_12 -> V_157 ++ ;
F_117 ( & V_12 -> V_156 ) ;
F_118 ( V_10 ) ;
F_119 ( V_12 ) ;
F_67 ( V_10 ) ;
V_21 = F_7 ( & V_12 -> V_2 , & V_15 ) ;
if ( F_15 ( V_21 ) ) {
F_10 ( L_50 ) ;
return F_91 ( V_21 ) ;
}
V_15 -> V_49 . V_50 = F_80 ( V_42 ) ;
F_81 ( V_42 -> V_103 , & V_15 -> V_49 ) ;
V_15 -> V_47 = F_110 ;
V_15 -> V_48 = V_10 ;
V_15 -> V_104 = V_42 -> V_103 ;
V_21 = F_120 ( V_15 ) ;
if ( V_21 ) {
F_13 ( V_15 ) ;
return F_91 ( V_21 ) ;
}
F_37 ( & V_12 -> V_38 ) ;
return V_10 ;
}
static void F_121 ( struct V_36 * V_15 , void * V_37 )
{
struct V_158 * args = V_37 ;
F_13 ( V_15 ) ;
F_32 ( & args -> V_12 -> V_38 ) ;
F_12 ( args ) ;
}
static int F_122 ( struct V_10 * V_10 , int V_159 )
{
struct V_41 * V_42 = F_35 ( V_10 ) ;
struct V_93 * V_94 = V_10 -> V_13 ;
struct V_11 * V_12 = V_94 -> V_14 ;
struct V_36 * V_15 ;
struct V_96 V_160 ;
struct V_95 * V_118 ;
struct V_158 * args ;
int V_21 ;
args = F_123 ( sizeof( * args ) , V_23 ) ;
if ( ! args ) {
F_21 ( L_51 ) ;
return - V_24 ;
}
V_118 = & args -> V_118 ;
V_118 -> V_81 = F_86 ( V_10 -> V_81 ) ;
V_118 -> V_122 = F_124 ( V_10 -> V_122 ) ;
V_118 -> V_123 = F_124 ( V_10 -> V_123 ) ;
V_118 -> V_125 = F_86 ( V_10 -> V_124 ) ;
V_118 -> V_85 = F_124 ( V_10 -> V_85 . V_126 ) ;
V_118 -> V_127 = F_124 ( V_10 -> V_127 . V_126 ) ;
V_118 -> V_84 = F_124 ( V_10 -> V_84 . V_126 ) ;
V_42 -> V_129 = F_39 ( V_10 ) ;
V_118 -> V_52 = F_125 ( V_42 -> V_129 ) ;
V_118 -> V_132 = F_124 ( V_10 -> V_132 ) ;
if ( F_97 ( V_10 -> V_81 ) || F_98 ( V_10 -> V_81 ) ) {
if ( F_126 ( V_10 -> V_135 ) ) {
V_118 -> V_82 [ 0 ] =
F_124 ( F_127 ( V_10 -> V_135 ) ) ;
V_118 -> V_82 [ 1 ] = 0 ;
} else {
V_118 -> V_82 [ 0 ] = 0 ;
V_118 -> V_82 [ 1 ] =
F_124 ( F_128 ( V_10 -> V_135 ) ) ;
V_118 -> V_82 [ 2 ] = 0 ;
}
} else
memcpy ( V_118 -> V_82 , V_42 -> V_82 , sizeof( V_118 -> V_82 ) ) ;
V_21 = F_7 ( & V_12 -> V_2 , & V_15 ) ;
if ( F_15 ( V_21 ) ) {
F_10 ( L_42 , V_102 ) ;
goto V_161;
}
V_160 = V_98 ;
V_160 . V_111 = V_118 ;
V_15 -> V_162 = 1 ;
V_15 -> V_163 = & V_160 ;
F_53 ( V_42 ) ;
if ( ! V_159 ) {
args -> V_12 = V_12 ;
V_15 -> V_47 = F_121 ;
V_15 -> V_48 = args ;
}
V_21 = F_49 ( V_42 , V_15 ) ;
if ( ! V_159 && ! V_21 ) {
F_37 ( & V_12 -> V_38 ) ;
goto V_77;
}
F_13 ( V_15 ) ;
V_161:
F_12 ( args ) ;
V_77:
F_21 ( L_52 ,
V_10 -> V_31 , V_159 , V_21 ) ;
return V_21 ;
}
int F_129 ( struct V_10 * V_10 , struct V_62 * V_66 )
{
return F_122 ( V_10 , 1 ) ;
}
static void F_130 ( struct V_36 * V_15 , void * V_37 )
{
struct V_11 * V_12 = V_37 ;
F_13 ( V_15 ) ;
F_32 ( & V_12 -> V_38 ) ;
}
void F_131 ( struct V_10 * V_10 )
{
struct V_41 * V_42 = F_35 ( V_10 ) ;
struct V_93 * V_94 = V_10 -> V_13 ;
struct V_11 * V_12 = V_94 -> V_14 ;
struct V_36 * V_15 ;
int V_21 ;
F_132 ( & V_10 -> V_82 , 0 ) ;
if ( V_10 -> V_124 || F_109 ( V_10 ) )
goto V_164;
V_10 -> V_52 = 0 ;
F_133 ( V_10 ) ;
F_53 ( V_42 ) ;
V_21 = F_7 ( & V_12 -> V_2 , & V_15 ) ;
if ( F_15 ( V_21 ) ) {
F_10 ( L_53 , V_102 ) ;
return;
}
V_15 -> V_49 . V_50 = F_80 ( V_42 ) ;
V_15 -> V_47 = F_130 ;
V_15 -> V_48 = V_12 ;
V_15 -> V_104 = V_42 -> V_103 ;
V_21 = F_134 ( V_15 ) ;
if ( V_21 ) {
F_10 ( L_54 , V_102 ) ;
F_13 ( V_15 ) ;
return;
}
F_37 ( & V_12 -> V_38 ) ;
return;
V_164:
F_133 ( V_10 ) ;
}
