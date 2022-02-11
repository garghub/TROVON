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
V_4 = F_1 ( & V_9 -> V_12 -> V_2 , V_9 -> V_3 ) ;
for (; V_4 ; V_4 >>= 1 ) {
V_9 -> V_4 = F_7 ( V_4 * sizeof( struct V_21 * ) ,
V_22 ) ;
if ( F_8 ( V_9 -> V_4 ) ) {
V_9 -> V_16 = V_4 ;
return 0 ;
}
}
F_9 ( L_1 ,
V_9 -> V_3 ) ;
return - V_23 ;
}
static void F_10 ( struct V_8 * V_9 )
{
F_11 ( V_9 -> V_4 ) ;
V_9 -> V_4 = NULL ;
if ( V_9 -> V_15 ) {
F_12 ( V_9 -> V_15 ) ;
V_9 -> V_15 = NULL ;
}
}
static int F_13 ( struct V_8 * V_9 , struct V_21 * V_21 ,
unsigned V_24 )
{
if ( F_14 ( V_9 -> V_17 >= V_9 -> V_16 ) )
return - V_23 ;
V_9 -> V_4 [ V_9 -> V_17 ++ ] = V_21 ;
V_9 -> V_18 += V_24 ;
return 0 ;
}
static int F_15 ( struct V_21 * V_21 , int V_25 )
{
if ( V_25 == 0 ) {
F_16 ( V_21 ) ;
if ( F_17 ( V_21 ) )
F_18 ( V_21 ) ;
} else if ( V_25 == - V_26 ) {
F_19 ( V_21 ) ;
F_16 ( V_21 ) ;
if ( F_17 ( V_21 ) )
F_18 ( V_21 ) ;
V_25 = 0 ;
F_20 ( L_2 ) ;
} else
F_21 ( V_21 ) ;
return V_25 ;
}
static void F_22 ( struct V_21 * V_21 , int V_25 )
{
if ( V_25 ) {
F_23 ( V_21 -> V_27 , V_25 ) ;
F_21 ( V_21 ) ;
}
F_24 ( V_21 ) ;
}
static int F_25 ( struct V_8 * V_9 )
{
int V_28 ;
T_1 V_29 ;
T_1 V_30 ;
T_1 V_18 = 0 ;
int V_25 = F_26 ( V_9 -> V_15 , & V_29 ) ;
if ( F_8 ( ! V_25 ) )
V_30 = V_9 -> V_18 ;
else
V_30 = V_9 -> V_18 - V_29 ;
F_27 ( L_3
L_4 ,
V_9 -> V_10 -> V_31 , F_28 ( V_30 ) , V_9 -> V_18 ,
V_9 -> V_17 ) ;
for ( V_28 = 0 ; V_28 < V_9 -> V_17 ; V_28 ++ ) {
struct V_21 * V_21 = V_9 -> V_4 [ V_28 ] ;
struct V_10 * V_10 = V_21 -> V_27 -> V_32 ;
int V_33 ;
if ( V_10 != V_9 -> V_10 )
continue;
if ( F_8 ( V_18 < V_30 ) )
V_33 = 0 ;
else
V_33 = V_25 ;
F_27 ( L_5 ,
V_10 -> V_31 , V_21 -> V_34 ,
V_33 ? L_6 : L_7 ) ;
V_25 = F_15 ( V_21 , V_33 ) ;
if ( ! V_9 -> V_20 )
F_29 ( V_21 ) ;
V_18 += V_35 ;
}
F_10 ( V_9 ) ;
F_27 ( L_8 ) ;
return V_25 ;
}
static void F_30 ( struct V_36 * V_15 , void * V_37 )
{
struct V_8 * V_9 = V_37 ;
F_25 ( V_9 ) ;
F_31 ( & V_9 -> V_12 -> V_38 ) ;
F_11 ( V_9 ) ;
}
static void F_32 ( struct V_8 * V_9 , int V_25 , int V_39 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_9 -> V_17 ; V_28 ++ ) {
struct V_21 * V_21 = V_9 -> V_4 [ V_28 ] ;
if ( V_39 == V_40 )
F_15 ( V_21 , V_25 ) ;
else
F_22 ( V_21 , V_25 ) ;
F_29 ( V_21 ) ;
}
}
static int F_33 ( struct V_8 * V_9 )
{
struct V_41 * V_42 = F_34 ( V_9 -> V_10 ) ;
struct V_36 * V_15 ;
struct V_8 * V_43 = NULL ;
int V_25 ;
if ( ! V_9 -> V_4 )
return 0 ;
if ( ! V_9 -> V_15 ) {
int V_25 = F_35 ( & V_9 -> V_12 -> V_2 , & V_42 -> V_44 , true ,
V_9 -> V_19 << V_45 ,
V_9 -> V_18 , & V_9 -> V_15 ) ;
if ( V_25 )
return V_25 ;
}
V_15 = V_9 -> V_15 ;
V_15 -> V_4 = V_9 -> V_4 ;
V_15 -> V_17 = V_9 -> V_17 ;
if ( V_9 -> V_20 ) {
F_36 ( V_9 -> V_15 ) ;
return F_25 ( V_9 ) ;
}
V_43 = F_7 ( sizeof( * V_43 ) , V_22 ) ;
if ( ! V_43 ) {
V_25 = - V_23 ;
goto V_46;
}
* V_43 = * V_9 ;
V_15 -> V_47 = F_30 ;
V_15 -> V_48 = V_43 ;
V_25 = F_36 ( V_15 ) ;
if ( F_14 ( V_25 ) )
goto V_46;
F_37 ( & V_9 -> V_12 -> V_38 ) ;
F_27 ( L_9 ,
V_42 -> V_49 . V_50 . V_51 , F_28 ( V_15 -> V_52 ) , V_9 -> V_18 ) ;
F_4 ( V_9 ) ;
return 0 ;
V_46:
if ( ! V_9 -> V_20 )
F_32 ( V_9 , V_25 , V_40 ) ;
F_10 ( V_9 ) ;
F_11 ( V_43 ) ;
return V_25 ;
}
static int F_38 ( void * V_53 , struct V_21 * V_21 )
{
struct V_8 * V_9 = V_53 ;
struct V_10 * V_10 = V_9 -> V_10 ;
struct V_41 * V_42 = F_34 ( V_10 ) ;
T_2 V_54 = F_39 ( V_10 ) ;
T_3 V_55 = V_54 >> V_45 ;
T_4 V_24 ;
int V_25 ;
if ( F_40 ( V_21 ) )
F_9 ( L_10 , V_9 -> V_10 -> V_31 ,
V_21 -> V_34 ) ;
if ( V_21 -> V_34 < V_55 )
V_24 = V_56 ;
else if ( V_21 -> V_34 == V_55 )
V_24 = V_54 & ~ V_57 ;
else
V_24 = 0 ;
if ( ! V_24 || ! F_41 ( V_42 ) ) {
F_19 ( V_21 ) ;
F_16 ( V_21 ) ;
if ( F_17 ( V_21 ) )
F_18 ( V_21 ) ;
if ( ! V_9 -> V_20 )
F_29 ( V_21 ) ;
F_20 ( L_11
L_12
L_13 , V_10 -> V_31 , V_24 ,
V_9 -> V_20 , V_21 -> V_34 , V_55 ) ;
return F_33 ( V_9 ) ;
}
V_58:
if ( F_14 ( V_9 -> V_19 == - 1 ) ) {
V_9 -> V_19 = V_21 -> V_34 ;
} else if ( F_14 ( ( V_9 -> V_19 + V_9 -> V_17 ) !=
V_21 -> V_34 ) ) {
V_25 = F_33 ( V_9 ) ;
if ( F_14 ( V_25 ) )
goto V_59;
goto V_58;
}
if ( ! V_9 -> V_4 ) {
V_25 = F_6 ( V_9 ) ;
if ( F_14 ( V_25 ) )
goto V_59;
}
if ( V_24 != V_56 )
F_42 ( V_21 , V_24 , V_56 - V_24 ) ;
F_27 ( L_14 ,
V_10 -> V_31 , V_21 -> V_34 , V_24 ) ;
V_25 = F_13 ( V_9 , V_21 , V_24 ) ;
if ( V_25 ) {
F_27 ( L_15
L_16 ,
V_21 , V_24 , V_9 -> V_17 , V_9 -> V_18 ) ;
V_25 = F_33 ( V_9 ) ;
if ( F_14 ( V_25 ) )
goto V_59;
goto V_58;
}
return 0 ;
V_59:
F_29 ( V_21 ) ;
return V_25 ;
}
static int F_43 ( struct V_60 * V_60 , struct V_61 * V_27 ,
struct V_62 * V_4 , unsigned V_17 )
{
struct V_8 V_9 ;
int V_25 ;
F_3 ( & V_9 , V_17 , V_27 -> V_32 ) ;
V_25 = F_44 ( V_27 , V_4 , F_38 , & V_9 ) ;
if ( V_25 ) {
F_9 ( L_17 , V_25 ) ;
return V_25 ;
}
return F_33 ( & V_9 ) ;
}
static int F_45 ( struct V_21 * V_21 , bool V_20 )
{
struct V_8 V_9 ;
int V_25 ;
F_3 ( & V_9 , 1 , V_21 -> V_27 -> V_32 ) ;
V_9 . V_20 = V_20 ;
V_25 = F_38 ( & V_9 , V_21 ) ;
if ( V_25 ) {
F_9 ( L_18 , V_25 ) ;
return V_25 ;
}
return F_33 ( & V_9 ) ;
}
static int F_46 ( struct V_60 * V_60 , struct V_21 * V_21 )
{
return F_45 ( V_21 , false ) ;
}
static void F_47 ( struct V_36 * V_15 , void * V_37 )
{
struct V_8 * V_9 = V_37 ;
int V_28 ;
T_1 V_29 ;
T_1 V_30 ;
T_1 V_18 = 0 ;
int V_25 = F_26 ( V_15 , & V_29 ) ;
F_31 ( & V_9 -> V_12 -> V_38 ) ;
if ( F_8 ( ! V_25 ) )
V_30 = V_9 -> V_18 ;
else
V_30 = V_9 -> V_18 - V_29 ;
F_27 ( L_19
L_4 ,
V_9 -> V_10 -> V_31 , F_28 ( V_30 ) , V_9 -> V_18 ,
V_9 -> V_17 ) ;
for ( V_28 = 0 ; V_28 < V_9 -> V_17 ; V_28 ++ ) {
struct V_21 * V_21 = V_9 -> V_4 [ V_28 ] ;
struct V_10 * V_10 = V_21 -> V_27 -> V_32 ;
int V_33 ;
if ( V_10 != V_9 -> V_10 )
continue;
if ( F_8 ( V_18 < V_30 ) )
V_33 = 0 ;
else
V_33 = V_25 ;
F_22 ( V_21 , V_33 ) ;
F_29 ( V_21 ) ;
F_27 ( L_20 ,
V_10 -> V_31 , V_21 -> V_34 , V_33 ) ;
V_18 += V_35 ;
}
F_10 ( V_9 ) ;
F_11 ( V_9 ) ;
F_27 ( L_21 ) ;
}
static int F_48 ( struct V_8 * V_9 )
{
struct V_41 * V_42 = F_34 ( V_9 -> V_10 ) ;
struct V_36 * V_15 ;
struct V_8 * V_43 = NULL ;
int V_25 ;
if ( ! V_9 -> V_4 )
return 0 ;
F_49 ( V_9 -> V_15 ) ;
V_25 = F_35 ( & V_9 -> V_12 -> V_2 , & V_42 -> V_44 , false ,
V_9 -> V_19 << V_45 ,
V_9 -> V_18 , & V_9 -> V_15 ) ;
if ( F_14 ( V_25 ) )
goto V_46;
V_43 = F_7 ( sizeof( * V_43 ) , V_22 ) ;
if ( ! V_43 ) {
F_9 ( L_22 ) ;
V_25 = - V_23 ;
goto V_46;
}
* V_43 = * V_9 ;
V_15 = V_9 -> V_15 ;
V_15 -> V_4 = V_43 -> V_4 ;
V_15 -> V_17 = V_43 -> V_17 ;
V_15 -> V_47 = F_47 ;
V_15 -> V_48 = V_43 ;
V_25 = F_50 ( V_15 ) ;
if ( F_14 ( V_25 ) ) {
F_9 ( L_23 ) ;
goto V_46;
}
F_37 ( & V_9 -> V_12 -> V_38 ) ;
F_27 ( L_24 ,
V_9 -> V_10 -> V_31 , V_9 -> V_19 , F_28 ( V_15 -> V_52 ) ,
V_9 -> V_18 ) ;
F_4 ( V_9 ) ;
return 0 ;
V_46:
F_32 ( V_9 , V_25 , V_63 ) ;
F_10 ( V_9 ) ;
F_11 ( V_43 ) ;
return V_25 ;
}
static int F_51 ( struct V_21 * V_21 ,
struct V_64 * V_65 , void * V_53 )
{
struct V_8 * V_9 = V_53 ;
struct V_10 * V_10 = V_9 -> V_10 ;
struct V_41 * V_42 = F_34 ( V_10 ) ;
T_2 V_54 = F_39 ( V_10 ) ;
T_3 V_55 = V_54 >> V_45 ;
T_4 V_24 ;
int V_25 ;
F_49 ( ! F_52 ( V_21 ) ) ;
V_25 = F_53 ( V_42 ) ;
if ( F_14 ( V_25 ) )
goto V_59;
if ( V_21 -> V_34 < V_55 )
V_24 = V_56 ;
else {
V_24 = V_54 & ~ V_57 ;
if ( V_21 -> V_34 > V_55 || ! V_24 ) {
V_25 = F_48 ( V_9 ) ;
if ( F_14 ( V_25 ) )
goto V_59;
if ( F_17 ( V_21 ) )
F_18 ( V_21 ) ;
F_29 ( V_21 ) ;
F_20 ( L_25
L_26 ,
V_10 -> V_31 , V_21 -> V_34 ) ;
return 0 ;
}
}
V_58:
if ( F_14 ( V_9 -> V_19 == - 1 ) ) {
V_9 -> V_19 = V_21 -> V_34 ;
} else if ( F_14 ( ( V_9 -> V_19 + V_9 -> V_17 ) !=
V_21 -> V_34 ) ) {
V_25 = F_48 ( V_9 ) ;
if ( F_14 ( V_25 ) )
goto V_59;
F_20 ( L_27 ,
V_10 -> V_31 , V_21 -> V_34 ) ;
goto V_58;
}
if ( ! V_9 -> V_4 ) {
V_25 = F_6 ( V_9 ) ;
if ( F_14 ( V_25 ) )
goto V_59;
}
F_27 ( L_28 ,
V_10 -> V_31 , V_21 -> V_34 , V_24 ) ;
V_25 = F_13 ( V_9 , V_21 , V_24 ) ;
if ( F_14 ( V_25 ) ) {
F_27 ( L_29
L_30 ,
V_9 -> V_17 , V_9 -> V_18 ) ;
V_25 = F_48 ( V_9 ) ;
if ( F_14 ( V_25 ) ) {
F_20 ( L_31 , V_25 ) ;
goto V_59;
}
goto V_58;
}
F_49 ( F_54 ( V_21 ) ) ;
F_55 ( V_21 ) ;
return 0 ;
V_59:
F_20 ( L_32 ,
V_10 -> V_31 , V_21 -> V_34 , V_25 ) ;
F_56 ( V_66 , & V_21 -> V_27 -> V_67 ) ;
F_29 ( V_21 ) ;
return V_25 ;
}
static int F_57 ( struct V_61 * V_27 ,
struct V_64 * V_68 )
{
struct V_8 V_9 ;
long V_69 , V_70 , V_3 ;
int V_25 ;
V_69 = V_68 -> V_71 >> V_45 ;
V_70 = ( V_68 -> V_72 == V_73 ) ?
V_69 + V_27 -> V_74 :
V_68 -> V_72 >> V_45 ;
if ( V_69 || V_70 )
V_3 = V_70 - V_69 + 1 ;
else
V_3 = V_27 -> V_74 ;
if ( V_3 < 32L )
V_3 = 32L ;
F_27 ( L_33
L_34 ,
V_27 -> V_32 -> V_31 , V_68 -> V_71 , V_68 -> V_72 ,
V_27 -> V_74 , V_69 , V_70 , V_3 ) ;
F_3 ( & V_9 , V_3 , V_27 -> V_32 ) ;
V_25 = F_58 ( V_27 , V_68 , F_51 , & V_9 ) ;
if ( V_25 ) {
F_9 ( L_35 , V_25 ) ;
return V_25 ;
}
return F_48 ( & V_9 ) ;
}
static int F_59 ( struct V_21 * V_21 , struct V_64 * V_68 )
{
struct V_8 V_9 ;
int V_25 ;
F_3 ( & V_9 , 1 , V_21 -> V_27 -> V_32 ) ;
V_25 = F_51 ( V_21 , NULL , & V_9 ) ;
if ( V_25 ) {
F_9 ( L_36 , V_25 ) ;
return V_25 ;
}
return F_48 ( & V_9 ) ;
}
static void F_60 ( struct V_10 * V_10 , T_2 V_75 )
{
if ( V_75 > V_10 -> V_54 )
F_61 ( V_10 , V_75 , V_10 -> V_54 ) ;
}
int F_62 ( struct V_60 * V_60 , struct V_61 * V_27 ,
T_2 V_76 , unsigned V_24 , unsigned V_67 ,
struct V_21 * * V_77 , void * * V_78 )
{
int V_25 = 0 ;
struct V_21 * V_21 ;
V_21 = * V_77 ;
if ( V_21 == NULL ) {
V_25 = F_63 ( V_60 , V_27 , V_76 , V_24 , V_67 , V_77 ,
V_78 ) ;
if ( V_25 ) {
F_20 ( L_37 ) ;
goto V_79;
}
V_21 = * V_77 ;
}
if ( ! F_40 ( V_21 ) && ( V_24 != V_56 ) ) {
T_2 V_54 = F_39 ( V_27 -> V_32 ) ;
T_3 V_55 = V_54 >> V_45 ;
T_4 V_80 ;
if ( V_21 -> V_34 < V_55 )
V_80 = V_56 ;
else if ( V_21 -> V_34 == V_55 )
V_80 = V_54 & ~ V_57 ;
else
V_80 = 0 ;
if ( ! V_80 ) {
F_19 ( V_21 ) ;
F_16 ( V_21 ) ;
goto V_79;
}
V_25 = F_45 ( V_21 , true ) ;
if ( V_25 ) {
F_29 ( V_21 ) ;
F_20 ( L_38 ) ;
}
}
V_79:
if ( F_14 ( V_25 ) )
F_60 ( V_27 -> V_32 , V_76 + V_24 ) ;
return V_25 ;
}
static int F_64 ( struct V_60 * V_60 ,
struct V_61 * V_27 ,
T_2 V_76 , unsigned V_24 , unsigned V_67 ,
struct V_21 * * V_77 , void * * V_78 )
{
* V_77 = NULL ;
return F_62 ( V_60 , V_27 , V_76 , V_24 , V_67 , V_77 ,
V_78 ) ;
}
static int F_65 ( struct V_60 * V_60 , struct V_61 * V_27 ,
T_2 V_76 , unsigned V_24 , unsigned V_81 ,
struct V_21 * V_21 , void * V_78 )
{
struct V_10 * V_10 = V_27 -> V_32 ;
T_2 V_54 = V_10 -> V_54 ;
int V_25 ;
V_25 = F_66 ( V_60 , V_27 , V_76 , V_24 , V_81 , V_21 , V_78 ) ;
if ( F_14 ( V_25 ) )
F_60 ( V_10 , V_76 + V_24 ) ;
if ( V_54 != V_10 -> V_54 )
F_67 ( V_10 ) ;
return V_25 ;
}
static int F_68 ( struct V_21 * V_21 , T_5 V_82 )
{
F_20 ( L_39 , V_21 -> V_34 ) ;
F_69 ( 1 ) ;
return 0 ;
}
static void F_70 ( struct V_21 * V_21 , unsigned long V_52 )
{
F_20 ( L_40 , V_21 -> V_34 , V_52 ) ;
F_69 ( 1 ) ;
}
static inline int F_71 ( struct V_10 * V_10 )
{
struct V_41 * V_42 = F_34 ( V_10 ) ;
return F_72 ( V_10 -> V_83 ) && ( V_42 -> V_84 [ 0 ] != 0 ) ;
}
static int F_73 ( struct V_10 * V_10 , T_2 V_85 )
{
struct V_41 * V_42 = F_34 ( V_10 ) ;
struct V_11 * V_12 = V_10 -> V_13 -> V_14 ;
int V_25 ;
V_10 -> V_86 = V_10 -> V_87 = V_88 ;
V_25 = F_74 ( & V_12 -> V_2 , & V_42 -> V_44 , ( T_1 ) V_85 ) ;
if ( F_8 ( ! V_25 ) )
F_75 ( V_10 , V_85 ) ;
F_20 ( L_41 ,
V_10 -> V_31 , V_85 , V_25 ) ;
return V_25 ;
}
int F_76 ( struct V_89 * V_89 , struct V_90 * V_90 )
{
struct V_10 * V_10 = V_89 -> V_91 ;
int error ;
error = F_53 ( F_34 ( V_10 ) ) ;
if ( F_14 ( error ) )
return error ;
error = F_77 ( V_10 , V_90 ) ;
if ( F_14 ( error ) )
return error ;
if ( ( V_90 -> V_92 & V_93 ) &&
V_90 -> V_94 != F_39 ( V_10 ) ) {
error = F_73 ( V_10 , V_90 -> V_94 ) ;
if ( F_14 ( error ) )
return error ;
}
F_78 ( V_10 , V_90 ) ;
F_67 ( V_10 ) ;
return 0 ;
}
static int F_79 ( struct V_95 * V_96 , struct V_41 * V_42 ,
struct V_97 * V_10 )
{
struct V_11 * V_12 = V_96 -> V_14 ;
struct V_98 V_99 [] = {
[ 0 ] = V_100 ,
[ 1 ] = V_101 ,
[ 2 ] = V_102 ,
} ;
struct V_36 * V_15 ;
struct V_103 * V_2 ;
int V_25 ;
V_25 = F_80 ( & V_12 -> V_2 , & V_42 -> V_44 , & V_15 ) ;
if ( F_14 ( V_25 ) ) {
F_9 ( L_42 , V_104 ) ;
return V_25 ;
}
V_99 [ 1 ] . V_24 = F_81 ( V_12 -> V_44 . V_105 ) ;
V_99 [ 2 ] . V_24 = F_81 ( V_12 -> V_44 . V_105 ) ;
V_15 -> V_106 = V_99 ;
V_15 -> V_107 = F_82 ( V_99 ) ;
V_25 = F_36 ( V_15 ) ;
if ( F_14 ( V_25 ) ) {
F_9 ( L_43 ,
F_28 ( V_42 -> V_49 . V_50 . V_51 ) , V_25 ) ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_83 = 0040000 | ( 0777 & ~ 022 ) ;
if ( ( V_25 == - V_108 ) || ( V_25 == - V_109 ) )
V_25 = 0 ;
goto V_79;
}
V_25 = F_83 ( V_15 , & V_99 [ 0 ] ) ;
if ( V_25 ) {
F_9 ( L_44 , V_104 ) ;
goto V_79;
}
F_69 ( V_99 [ 0 ] . V_24 != V_110 ) ;
memcpy ( V_10 , V_99 [ 0 ] . V_111 , V_110 ) ;
V_25 = F_83 ( V_15 , & V_99 [ 1 ] ) ;
if ( V_25 ) {
F_9 ( L_44 , V_104 ) ;
goto V_79;
}
if ( V_99 [ 1 ] . V_24 ) {
V_2 = V_99 [ 1 ] . V_111 ;
if ( V_2 -> V_112 != F_84 ( V_113 ) ) {
F_9 ( L_45 ,
V_104 , V_2 -> V_112 ) ;
V_25 = - V_114 ;
goto V_79;
}
}
V_25 = F_83 ( V_15 , & V_99 [ 2 ] ) ;
if ( V_25 ) {
F_9 ( L_44 , V_104 ) ;
goto V_79;
}
if ( V_99 [ 2 ] . V_24 ) {
V_2 = V_99 [ 2 ] . V_111 ;
if ( V_2 -> V_112 != F_84 ( V_113 ) ) {
F_9 ( L_46 ,
V_104 , V_2 -> V_112 ) ;
V_25 = - V_114 ;
goto V_79;
}
}
V_79:
F_12 ( V_15 ) ;
return V_25 ;
}
static void F_85 ( struct V_41 * V_42 )
{
F_86 ( & V_42 -> V_115 ) ;
V_42 -> V_116 = 0 ;
}
struct V_10 * F_87 ( struct V_95 * V_96 , unsigned long V_117 )
{
struct V_41 * V_42 ;
struct V_97 V_118 ;
struct V_10 * V_10 ;
int V_25 ;
V_10 = F_88 ( V_96 , V_117 ) ;
if ( ! V_10 )
return F_89 ( - V_23 ) ;
if ( ! ( V_10 -> V_119 & V_120 ) )
return V_10 ;
V_42 = F_34 ( V_10 ) ;
F_85 ( V_42 ) ;
F_90 ( & V_42 -> V_44 , & V_42 -> V_49 , V_96 -> V_14 ,
F_91 ( V_42 ) ) ;
V_25 = F_79 ( V_96 , V_42 , & V_118 ) ;
if ( V_25 )
goto V_121;
F_92 ( V_42 ) ;
V_10 -> V_83 = F_93 ( V_118 . V_83 ) ;
V_10 -> V_122 = F_94 ( V_118 . V_122 ) ;
V_10 -> V_123 = F_94 ( V_118 . V_123 ) ;
V_10 -> V_124 = F_93 ( V_118 . V_125 ) ;
V_10 -> V_87 . V_126 = ( signed ) F_94 ( V_118 . V_87 ) ;
V_10 -> V_127 . V_126 = ( signed ) F_94 ( V_118 . V_127 ) ;
V_10 -> V_86 . V_126 = ( signed ) F_94 ( V_118 . V_86 ) ;
V_10 -> V_87 . V_128 =
V_10 -> V_127 . V_128 = V_10 -> V_86 . V_128 = 0 ;
V_42 -> V_129 = F_95 ( V_118 . V_54 ) ;
F_96 ( V_10 , V_42 -> V_129 ) ;
V_10 -> V_130 = V_131 ;
V_10 -> V_132 = F_94 ( V_118 . V_132 ) ;
V_42 -> V_133 = 0 ;
if ( ( V_10 -> V_124 == 0 ) && ( V_10 -> V_83 == 0 ) ) {
V_25 = - V_134 ;
goto V_121;
}
if ( F_97 ( V_10 -> V_83 ) || F_98 ( V_10 -> V_83 ) ) {
if ( V_118 . V_84 [ 0 ] )
V_10 -> V_135 =
F_99 ( F_94 ( V_118 . V_84 [ 0 ] ) ) ;
else
V_10 -> V_135 =
F_100 ( F_94 ( V_118 . V_84 [ 1 ] ) ) ;
} else {
memcpy ( V_42 -> V_84 , V_118 . V_84 , sizeof( V_118 . V_84 ) ) ;
}
V_10 -> V_136 -> V_137 = V_96 -> V_138 ;
if ( F_101 ( V_10 -> V_83 ) ) {
V_10 -> V_139 = & V_140 ;
V_10 -> V_141 = & V_142 ;
V_10 -> V_136 -> V_143 = & V_144 ;
} else if ( F_102 ( V_10 -> V_83 ) ) {
V_10 -> V_139 = & V_145 ;
V_10 -> V_141 = & V_146 ;
V_10 -> V_136 -> V_143 = & V_144 ;
} else if ( F_72 ( V_10 -> V_83 ) ) {
if ( F_71 ( V_10 ) )
V_10 -> V_139 = & V_147 ;
else {
V_10 -> V_139 = & V_148 ;
V_10 -> V_136 -> V_143 = & V_144 ;
}
} else {
V_10 -> V_139 = & V_149 ;
if ( V_118 . V_84 [ 0 ] )
F_103 ( V_10 , V_10 -> V_83 ,
F_99 ( F_94 ( V_118 . V_84 [ 0 ] ) ) ) ;
else
F_103 ( V_10 , V_10 -> V_83 ,
F_100 ( F_94 ( V_118 . V_84 [ 1 ] ) ) ) ;
}
F_104 ( V_10 ) ;
return V_10 ;
V_121:
F_105 ( V_10 ) ;
return F_89 ( V_25 ) ;
}
int F_106 ( struct V_41 * V_42 )
{
if ( ! F_41 ( V_42 ) ) {
F_20 ( L_47 ) ;
F_49 ( ! F_107 ( V_42 ) ) ;
F_108 ( V_42 -> V_115 , F_41 ( V_42 ) ) ;
F_20 ( L_48 ) ;
}
return F_14 ( F_109 ( & V_42 -> V_150 ) ) ? - V_151 : 0 ;
}
static void F_110 ( struct V_36 * V_15 , void * V_37 )
{
struct V_10 * V_10 = V_37 ;
struct V_41 * V_42 = F_34 ( V_10 ) ;
struct V_11 * V_12 = V_10 -> V_13 -> V_14 ;
int V_25 ;
V_25 = F_26 ( V_15 , NULL ) ;
F_12 ( V_15 ) ;
F_31 ( & V_12 -> V_38 ) ;
if ( F_14 ( V_25 ) ) {
F_9 ( L_49 ,
F_28 ( F_91 ( V_42 ) ) ,
F_28 ( V_42 -> V_49 . V_50 . V_152 ) ) ;
}
F_92 ( V_42 ) ;
F_111 ( & V_42 -> V_115 ) ;
}
struct V_10 * F_112 ( struct V_10 * V_153 , int V_154 )
{
struct V_95 * V_96 = V_153 -> V_13 ;
struct V_11 * V_12 = V_96 -> V_14 ;
struct V_10 * V_10 ;
struct V_41 * V_42 ;
struct V_36 * V_15 ;
int V_25 ;
V_10 = F_113 ( V_96 ) ;
if ( ! V_10 )
return F_89 ( - V_23 ) ;
V_42 = F_34 ( V_10 ) ;
F_85 ( V_42 ) ;
F_114 ( V_42 ) ;
V_10 -> V_136 -> V_137 = V_96 -> V_138 ;
F_115 ( V_10 , V_153 , V_154 ) ;
V_10 -> V_31 = V_12 -> V_155 ++ ;
V_10 -> V_130 = V_131 ;
V_10 -> V_86 = V_10 -> V_127 = V_10 -> V_87 = V_88 ;
V_42 -> V_129 = V_10 -> V_54 = 0 ;
F_116 ( & V_12 -> V_156 ) ;
V_10 -> V_132 = V_12 -> V_157 ++ ;
F_117 ( & V_12 -> V_156 ) ;
F_118 ( V_10 ) ;
F_90 ( & V_42 -> V_44 , & V_42 -> V_49 , V_96 -> V_14 ,
F_91 ( V_42 ) ) ;
F_119 ( V_12 ) ;
F_67 ( V_10 ) ;
V_25 = F_80 ( & V_12 -> V_2 , & V_42 -> V_44 , & V_15 ) ;
if ( F_14 ( V_25 ) ) {
F_9 ( L_50 ) ;
return F_89 ( V_25 ) ;
}
V_15 -> V_47 = F_110 ;
V_15 -> V_48 = V_10 ;
V_25 = F_120 ( V_15 ) ;
if ( V_25 ) {
F_12 ( V_15 ) ;
return F_89 ( V_25 ) ;
}
F_37 ( & V_12 -> V_38 ) ;
return V_10 ;
}
static void F_121 ( struct V_36 * V_15 , void * V_37 )
{
struct V_158 * args = V_37 ;
F_12 ( V_15 ) ;
F_31 ( & args -> V_12 -> V_38 ) ;
F_11 ( args ) ;
}
static int F_122 ( struct V_10 * V_10 , int V_159 )
{
struct V_41 * V_42 = F_34 ( V_10 ) ;
struct V_95 * V_96 = V_10 -> V_13 ;
struct V_11 * V_12 = V_96 -> V_14 ;
struct V_36 * V_15 ;
struct V_98 V_160 ;
struct V_97 * V_118 ;
struct V_158 * args ;
int V_25 ;
args = F_123 ( sizeof( * args ) , V_22 ) ;
if ( ! args ) {
F_20 ( L_51 ) ;
return - V_23 ;
}
V_118 = & args -> V_118 ;
V_118 -> V_83 = F_84 ( V_10 -> V_83 ) ;
V_118 -> V_122 = F_124 ( V_10 -> V_122 ) ;
V_118 -> V_123 = F_124 ( V_10 -> V_123 ) ;
V_118 -> V_125 = F_84 ( V_10 -> V_124 ) ;
V_118 -> V_87 = F_124 ( V_10 -> V_87 . V_126 ) ;
V_118 -> V_127 = F_124 ( V_10 -> V_127 . V_126 ) ;
V_118 -> V_86 = F_124 ( V_10 -> V_86 . V_126 ) ;
V_42 -> V_129 = F_39 ( V_10 ) ;
V_118 -> V_54 = F_125 ( V_42 -> V_129 ) ;
V_118 -> V_132 = F_124 ( V_10 -> V_132 ) ;
if ( F_97 ( V_10 -> V_83 ) || F_98 ( V_10 -> V_83 ) ) {
if ( F_126 ( V_10 -> V_135 ) ) {
V_118 -> V_84 [ 0 ] =
F_124 ( F_127 ( V_10 -> V_135 ) ) ;
V_118 -> V_84 [ 1 ] = 0 ;
} else {
V_118 -> V_84 [ 0 ] = 0 ;
V_118 -> V_84 [ 1 ] =
F_124 ( F_128 ( V_10 -> V_135 ) ) ;
V_118 -> V_84 [ 2 ] = 0 ;
}
} else
memcpy ( V_118 -> V_84 , V_42 -> V_84 , sizeof( V_118 -> V_84 ) ) ;
V_25 = F_80 ( & V_12 -> V_2 , & V_42 -> V_44 , & V_15 ) ;
if ( F_14 ( V_25 ) ) {
F_9 ( L_42 , V_104 ) ;
goto V_161;
}
V_160 = V_100 ;
V_160 . V_111 = V_118 ;
V_15 -> V_162 = 1 ;
V_15 -> V_163 = & V_160 ;
F_53 ( V_42 ) ;
if ( ! V_159 ) {
args -> V_12 = V_12 ;
V_15 -> V_47 = F_121 ;
V_15 -> V_48 = args ;
}
V_25 = F_50 ( V_15 ) ;
if ( ! V_159 && ! V_25 ) {
F_37 ( & V_12 -> V_38 ) ;
goto V_79;
}
F_12 ( V_15 ) ;
V_161:
F_11 ( args ) ;
V_79:
F_20 ( L_52 ,
V_10 -> V_31 , V_159 , V_25 ) ;
return V_25 ;
}
int F_129 ( struct V_10 * V_10 , struct V_64 * V_68 )
{
return F_122 ( V_10 , 1 ) ;
}
static void F_130 ( struct V_36 * V_15 , void * V_37 )
{
struct V_11 * V_12 = V_37 ;
F_12 ( V_15 ) ;
F_31 ( & V_12 -> V_38 ) ;
}
void F_131 ( struct V_10 * V_10 )
{
struct V_41 * V_42 = F_34 ( V_10 ) ;
struct V_95 * V_96 = V_10 -> V_13 ;
struct V_11 * V_12 = V_96 -> V_14 ;
struct V_36 * V_15 ;
int V_25 ;
F_132 ( & V_10 -> V_84 , 0 ) ;
if ( V_10 -> V_124 || F_109 ( V_10 ) )
goto V_164;
V_10 -> V_54 = 0 ;
F_133 ( V_10 ) ;
F_53 ( V_42 ) ;
V_25 = F_80 ( & V_12 -> V_2 , & V_42 -> V_44 , & V_15 ) ;
if ( F_14 ( V_25 ) ) {
F_9 ( L_53 , V_104 ) ;
return;
}
V_15 -> V_47 = F_130 ;
V_15 -> V_48 = V_12 ;
V_25 = F_134 ( V_15 ) ;
if ( V_25 ) {
F_9 ( L_54 , V_104 ) ;
F_12 ( V_15 ) ;
return;
}
F_37 ( & V_12 -> V_38 ) ;
return;
V_164:
F_133 ( V_10 ) ;
}
