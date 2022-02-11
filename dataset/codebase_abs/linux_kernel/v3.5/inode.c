unsigned F_1 ( struct V_1 * V_2 ,
unsigned V_3 )
{
unsigned V_4 = F_2 ( unsigned , V_3 , V_5 ) ;
V_4 = F_2 ( unsigned , V_4 , V_2 -> V_6 / V_7 ) ;
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
V_9 -> V_21 = NULL ;
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
V_9 -> V_21 = NULL ;
if ( ! V_9 -> V_3 )
V_9 -> V_3 = V_5 ;
}
static int F_6 ( struct V_8 * V_9 )
{
unsigned V_4 ;
V_4 = F_1 ( & V_9 -> V_12 -> V_2 , V_9 -> V_3 ) ;
for (; V_4 ; V_4 >>= 1 ) {
V_9 -> V_4 = F_7 ( V_4 * sizeof( struct V_22 * ) ,
V_23 ) ;
if ( F_8 ( V_9 -> V_4 ) ) {
V_9 -> V_16 = V_4 ;
return 0 ;
}
}
F_9 ( L_1 ,
V_9 -> V_3 ) ;
return - V_24 ;
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
static int F_13 ( struct V_8 * V_9 , struct V_22 * V_22 ,
unsigned V_25 )
{
if ( F_14 ( V_9 -> V_17 >= V_9 -> V_16 ) )
return - V_24 ;
V_9 -> V_4 [ V_9 -> V_17 ++ ] = V_22 ;
V_9 -> V_18 += V_25 ;
return 0 ;
}
static int F_15 ( struct V_22 * V_22 , int V_26 )
{
switch ( V_26 ) {
case 0 :
F_16 ( V_22 ) ;
if ( F_17 ( V_22 ) )
F_18 ( V_22 ) ;
break;
case - V_27 :
F_19 ( V_22 ) ;
F_16 ( V_22 ) ;
if ( F_17 ( V_22 ) )
F_18 ( V_22 ) ;
F_20 ( L_2 ) ;
case V_28 :
V_26 = 0 ;
break;
default:
F_21 ( V_22 ) ;
}
return V_26 ;
}
static void F_22 ( struct V_22 * V_22 , int V_26 )
{
if ( F_14 ( V_26 == V_28 ) )
return;
if ( V_26 ) {
F_23 ( V_22 -> V_29 , V_26 ) ;
F_21 ( V_22 ) ;
}
F_24 ( V_22 ) ;
}
static int F_25 ( struct V_8 * V_9 )
{
int V_30 ;
T_1 V_31 ;
T_1 V_18 = 0 ;
int V_26 = F_26 ( V_9 -> V_15 , NULL ) ;
if ( F_8 ( ! V_26 ) ) {
V_31 = V_9 -> V_18 ;
V_26 = V_28 ;
} else {
V_31 = 0 ;
}
F_27 ( L_3
L_4 ,
V_9 -> V_10 -> V_32 , F_28 ( V_31 ) , V_9 -> V_18 ,
V_9 -> V_17 ) ;
for ( V_30 = 0 ; V_30 < V_9 -> V_17 ; V_30 ++ ) {
struct V_22 * V_22 = V_9 -> V_4 [ V_30 ] ;
struct V_10 * V_10 = V_22 -> V_29 -> V_33 ;
int V_34 ;
if ( V_10 != V_9 -> V_10 )
continue;
if ( F_8 ( V_18 < V_31 ) )
V_34 = 0 ;
else
V_34 = V_26 ;
F_27 ( L_5 ,
V_10 -> V_32 , V_22 -> V_35 ,
V_34 ? L_6 : L_7 ) ;
V_26 = F_15 ( V_22 , V_34 ) ;
if ( ! V_9 -> V_20 )
F_29 ( V_22 ) ;
V_18 += V_7 ;
}
F_10 ( V_9 ) ;
F_27 ( L_8 ) ;
return V_26 ;
}
static void F_30 ( struct V_36 * V_15 , void * V_37 )
{
struct V_8 * V_9 = V_37 ;
F_25 ( V_9 ) ;
F_31 ( & V_9 -> V_12 -> V_38 ) ;
F_11 ( V_9 ) ;
}
static void F_32 ( struct V_8 * V_9 , int V_26 , int V_39 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_9 -> V_17 ; V_30 ++ ) {
struct V_22 * V_22 = V_9 -> V_4 [ V_30 ] ;
if ( V_39 == V_40 )
F_15 ( V_22 , V_26 ) ;
else
F_22 ( V_22 , V_26 ) ;
F_29 ( V_22 ) ;
}
}
static int F_33 ( struct V_36 * V_15 ,
struct V_8 * V_41 , struct V_8 * V_9 )
{
F_34 ( V_41 -> V_17 < V_15 -> V_17 ) ;
if ( V_41 -> V_17 > V_15 -> V_17 ) {
struct V_22 * * V_42 ;
unsigned V_43 = V_41 -> V_17 - V_15 -> V_17 ;
unsigned long V_44 = V_41 -> V_18 - V_15 -> V_18 ;
unsigned V_30 ;
int V_26 ;
V_41 -> V_17 = V_15 -> V_17 ;
V_41 -> V_18 = V_15 -> V_18 ;
V_9 -> V_3 += V_43 ;
V_9 -> V_17 = V_43 ;
V_9 -> V_18 = V_44 ;
V_42 = V_41 -> V_4 + V_41 -> V_17 ;
V_9 -> V_19 = ( * V_42 ) -> V_35 ;
V_26 = F_6 ( V_9 ) ;
if ( F_14 ( V_26 ) )
return V_26 ;
for ( V_30 = 0 ; V_30 < V_43 ; ++ V_30 )
V_9 -> V_4 [ V_30 ] = * V_42 ++ ;
F_20 ( L_9
L_10
L_11 ,
V_41 -> V_17 , V_43 , V_9 -> V_3 ,
V_9 -> V_19 * V_7 , V_9 -> V_18 ) ;
}
return 0 ;
}
static int F_35 ( struct V_8 * V_9 )
{
struct V_45 * V_46 = F_36 ( V_9 -> V_10 ) ;
struct V_36 * V_15 ;
struct V_8 * V_47 = NULL ;
int V_26 ;
if ( ! V_9 -> V_4 )
return 0 ;
if ( ! V_9 -> V_15 ) {
int V_26 = F_37 ( & V_9 -> V_12 -> V_2 , & V_46 -> V_48 , true ,
V_9 -> V_19 << V_49 ,
V_9 -> V_18 , & V_9 -> V_15 ) ;
if ( V_26 )
return V_26 ;
}
V_15 = V_9 -> V_15 ;
V_15 -> V_4 = V_9 -> V_4 ;
if ( V_9 -> V_20 ) {
F_38 ( V_9 -> V_15 ) ;
return F_25 ( V_9 ) ;
}
V_47 = F_7 ( sizeof( * V_47 ) , V_23 ) ;
if ( ! V_47 ) {
V_26 = - V_24 ;
goto V_50;
}
* V_47 = * V_9 ;
V_15 -> V_51 = F_30 ;
V_15 -> V_52 = V_47 ;
F_4 ( V_9 ) ;
V_26 = F_33 ( V_15 , V_47 , V_9 ) ;
if ( F_14 ( V_26 ) )
goto V_50;
F_27 ( L_12 ,
V_9 -> V_10 -> V_32 , F_28 ( V_15 -> V_53 ) , F_28 ( V_15 -> V_18 ) ) ;
V_26 = F_38 ( V_15 ) ;
if ( F_14 ( V_26 ) )
goto V_50;
F_39 ( & V_9 -> V_12 -> V_38 ) ;
return 0 ;
V_50:
if ( ! V_9 -> V_20 )
F_32 ( V_9 , V_26 , V_40 ) ;
F_10 ( V_9 ) ;
F_11 ( V_47 ) ;
return V_26 ;
}
static int F_40 ( void * V_54 , struct V_22 * V_22 )
{
struct V_8 * V_9 = V_54 ;
struct V_10 * V_10 = V_9 -> V_10 ;
struct V_45 * V_46 = F_36 ( V_10 ) ;
T_2 V_55 = F_41 ( V_10 ) ;
T_3 V_56 = V_55 >> V_49 ;
T_4 V_25 ;
int V_26 ;
if ( F_42 ( V_22 ) )
F_9 ( L_13 , V_9 -> V_10 -> V_32 ,
V_22 -> V_35 ) ;
V_9 -> V_21 = V_22 ;
if ( V_22 -> V_35 < V_56 )
V_25 = V_57 ;
else if ( V_22 -> V_35 == V_56 )
V_25 = V_55 & ~ V_58 ;
else
V_25 = 0 ;
if ( ! V_25 || ! F_43 ( V_46 ) ) {
F_19 ( V_22 ) ;
F_16 ( V_22 ) ;
if ( F_17 ( V_22 ) )
F_18 ( V_22 ) ;
if ( ! V_9 -> V_20 )
F_29 ( V_22 ) ;
F_20 ( L_14
L_15
L_16 , V_10 -> V_32 , V_25 ,
V_9 -> V_20 , V_22 -> V_35 , V_56 ) ;
return F_35 ( V_9 ) ;
}
V_59:
if ( F_14 ( V_9 -> V_19 == - 1 ) ) {
V_9 -> V_19 = V_22 -> V_35 ;
} else if ( F_14 ( ( V_9 -> V_19 + V_9 -> V_17 ) !=
V_22 -> V_35 ) ) {
V_26 = F_35 ( V_9 ) ;
if ( F_14 ( V_26 ) )
goto V_60;
goto V_59;
}
if ( ! V_9 -> V_4 ) {
V_26 = F_6 ( V_9 ) ;
if ( F_14 ( V_26 ) )
goto V_60;
}
if ( V_25 != V_57 )
F_44 ( V_22 , V_25 , V_57 - V_25 ) ;
F_27 ( L_17 ,
V_10 -> V_32 , V_22 -> V_35 , V_25 ) ;
V_26 = F_13 ( V_9 , V_22 , V_25 ) ;
if ( V_26 ) {
F_27 ( L_18
L_19 ,
V_22 , V_25 , V_9 -> V_17 , V_9 -> V_18 ) ;
V_26 = F_35 ( V_9 ) ;
if ( F_14 ( V_26 ) )
goto V_60;
goto V_59;
}
return 0 ;
V_60:
F_29 ( V_22 ) ;
return V_26 ;
}
static int F_45 ( struct V_61 * V_61 , struct V_62 * V_29 ,
struct V_63 * V_4 , unsigned V_17 )
{
struct V_8 V_9 ;
int V_26 ;
F_3 ( & V_9 , V_17 , V_29 -> V_33 ) ;
V_26 = F_46 ( V_29 , V_4 , F_40 , & V_9 ) ;
if ( V_26 ) {
F_9 ( L_20 , V_26 ) ;
return V_26 ;
}
V_26 = F_35 ( & V_9 ) ;
if ( F_14 ( V_26 ) )
return V_26 ;
return F_35 ( & V_9 ) ;
}
static int F_47 ( struct V_22 * V_22 , bool V_20 )
{
struct V_8 V_9 ;
int V_26 ;
F_3 ( & V_9 , 1 , V_22 -> V_29 -> V_33 ) ;
V_9 . V_20 = V_20 ;
V_26 = F_40 ( & V_9 , V_22 ) ;
if ( V_26 ) {
F_9 ( L_21 , V_26 ) ;
return V_26 ;
}
return F_35 ( & V_9 ) ;
}
static int F_48 ( struct V_61 * V_61 , struct V_22 * V_22 )
{
return F_47 ( V_22 , false ) ;
}
static void F_49 ( struct V_36 * V_15 , void * V_37 )
{
struct V_8 * V_9 = V_37 ;
int V_30 ;
T_1 V_31 ;
T_1 V_18 = 0 ;
int V_26 = F_26 ( V_15 , NULL ) ;
F_31 ( & V_9 -> V_12 -> V_38 ) ;
if ( F_8 ( ! V_26 ) ) {
V_31 = V_9 -> V_18 ;
V_26 = V_28 ;
} else {
V_31 = 0 ;
}
F_27 ( L_22
L_4 ,
V_9 -> V_10 -> V_32 , F_28 ( V_31 ) , V_9 -> V_18 ,
V_9 -> V_17 ) ;
for ( V_30 = 0 ; V_30 < V_9 -> V_17 ; V_30 ++ ) {
struct V_22 * V_22 = V_9 -> V_4 [ V_30 ] ;
struct V_10 * V_10 = V_22 -> V_29 -> V_33 ;
int V_34 ;
if ( V_10 != V_9 -> V_10 )
continue;
if ( F_8 ( V_18 < V_31 ) )
V_34 = 0 ;
else
V_34 = V_26 ;
F_22 ( V_22 , V_34 ) ;
F_29 ( V_22 ) ;
F_27 ( L_23 ,
V_10 -> V_32 , V_22 -> V_35 , V_34 ) ;
V_18 += V_7 ;
}
F_10 ( V_9 ) ;
F_11 ( V_9 ) ;
F_27 ( L_24 ) ;
}
static struct V_22 * F_50 ( void * V_64 , T_1 V_53 , bool * V_65 )
{
struct V_8 * V_9 = V_64 ;
T_3 V_35 = V_53 / V_7 ;
if ( ! V_9 -> V_21 ||
( V_9 -> V_21 -> V_35 != V_35 ) ) {
struct V_22 * V_22 = F_51 ( V_9 -> V_10 -> V_66 , V_35 ) ;
if ( ! V_22 ) {
V_22 = F_52 ( V_9 -> V_10 -> V_66 ,
V_35 , V_67 ) ;
if ( F_14 ( ! V_22 ) ) {
F_20 ( L_25
L_26 , F_28 ( V_35 ) ) ;
return NULL ;
}
F_29 ( V_22 ) ;
}
if ( F_53 ( V_22 ) || F_54 ( V_22 ) )
* V_65 = true ;
else
* V_65 = F_42 ( V_22 ) ;
F_20 ( L_27 , V_35 , * V_65 ) ;
return V_22 ;
} else {
F_20 ( L_28 ,
V_9 -> V_21 -> V_35 ) ;
* V_65 = true ;
return V_9 -> V_21 ;
}
}
static void F_55 ( void * V_64 , struct V_22 * V_22 )
{
struct V_8 * V_9 = V_64 ;
if ( V_9 -> V_21 != V_22 ) {
F_20 ( L_29 , V_22 -> V_35 ) ;
F_56 ( V_22 ) ;
return;
}
F_20 ( L_30 , V_22 -> V_35 ) ;
}
static int F_57 ( struct V_8 * V_9 )
{
struct V_45 * V_46 = F_36 ( V_9 -> V_10 ) ;
struct V_36 * V_15 ;
struct V_8 * V_47 = NULL ;
int V_26 ;
if ( ! V_9 -> V_4 )
return 0 ;
F_34 ( V_9 -> V_15 ) ;
V_26 = F_37 ( & V_9 -> V_12 -> V_2 , & V_46 -> V_48 , false ,
V_9 -> V_19 << V_49 ,
V_9 -> V_18 , & V_9 -> V_15 ) ;
if ( F_14 ( V_26 ) )
goto V_50;
V_47 = F_7 ( sizeof( * V_47 ) , V_23 ) ;
if ( ! V_47 ) {
F_9 ( L_31 ) ;
V_26 = - V_24 ;
goto V_50;
}
* V_47 = * V_9 ;
V_15 = V_9 -> V_15 ;
V_15 -> V_4 = V_47 -> V_4 ;
V_15 -> V_51 = F_49 ;
V_15 -> V_68 = & V_69 ;
V_15 -> V_52 = V_47 ;
F_4 ( V_9 ) ;
V_26 = F_33 ( V_15 , V_47 , V_9 ) ;
if ( F_14 ( V_26 ) )
goto V_50;
F_27 ( L_32 ,
V_9 -> V_10 -> V_32 , F_28 ( V_15 -> V_53 ) , F_28 ( V_15 -> V_18 ) ) ;
V_26 = F_58 ( V_15 ) ;
if ( F_14 ( V_26 ) ) {
F_9 ( L_33 ) ;
goto V_50;
}
F_39 ( & V_9 -> V_12 -> V_38 ) ;
return 0 ;
V_50:
F_32 ( V_9 , V_26 , V_70 ) ;
F_10 ( V_9 ) ;
F_11 ( V_47 ) ;
return V_26 ;
}
static int F_59 ( struct V_22 * V_22 ,
struct V_71 * V_72 , void * V_54 )
{
struct V_8 * V_9 = V_54 ;
struct V_10 * V_10 = V_9 -> V_10 ;
struct V_45 * V_46 = F_36 ( V_10 ) ;
T_2 V_55 = F_41 ( V_10 ) ;
T_3 V_56 = V_55 >> V_49 ;
T_4 V_25 ;
int V_26 ;
F_34 ( ! F_60 ( V_22 ) ) ;
V_26 = F_61 ( V_46 ) ;
if ( F_14 ( V_26 ) )
goto V_60;
if ( V_22 -> V_35 < V_56 )
V_25 = V_57 ;
else {
V_25 = V_55 & ~ V_58 ;
if ( V_22 -> V_35 > V_56 || ! V_25 ) {
V_26 = F_57 ( V_9 ) ;
if ( F_14 ( V_26 ) )
goto V_60;
if ( F_17 ( V_22 ) )
F_18 ( V_22 ) ;
F_29 ( V_22 ) ;
F_20 ( L_34
L_35 ,
V_10 -> V_32 , V_22 -> V_35 ) ;
return 0 ;
}
}
V_59:
if ( F_14 ( V_9 -> V_19 == - 1 ) ) {
V_9 -> V_19 = V_22 -> V_35 ;
} else if ( F_14 ( ( V_9 -> V_19 + V_9 -> V_17 ) !=
V_22 -> V_35 ) ) {
V_26 = F_57 ( V_9 ) ;
if ( F_14 ( V_26 ) )
goto V_60;
F_20 ( L_36 ,
V_10 -> V_32 , V_22 -> V_35 ) ;
goto V_59;
}
if ( ! V_9 -> V_4 ) {
V_26 = F_6 ( V_9 ) ;
if ( F_14 ( V_26 ) )
goto V_60;
}
F_27 ( L_37 ,
V_10 -> V_32 , V_22 -> V_35 , V_25 ) ;
V_26 = F_13 ( V_9 , V_22 , V_25 ) ;
if ( F_14 ( V_26 ) ) {
F_27 ( L_38
L_39 ,
V_9 -> V_17 , V_9 -> V_18 ) ;
V_26 = F_57 ( V_9 ) ;
if ( F_14 ( V_26 ) ) {
F_20 ( L_40 , V_26 ) ;
goto V_60;
}
goto V_59;
}
F_34 ( F_54 ( V_22 ) ) ;
F_62 ( V_22 ) ;
return 0 ;
V_60:
F_20 ( L_41 ,
V_10 -> V_32 , V_22 -> V_35 , V_26 ) ;
F_63 ( V_73 , & V_22 -> V_29 -> V_74 ) ;
F_29 ( V_22 ) ;
return V_26 ;
}
static int F_64 ( struct V_62 * V_29 ,
struct V_71 * V_75 )
{
struct V_8 V_9 ;
long V_76 , V_77 , V_3 ;
int V_26 ;
V_76 = V_75 -> V_78 >> V_49 ;
V_77 = ( V_75 -> V_79 == V_80 ) ?
V_76 + V_29 -> V_81 :
V_75 -> V_79 >> V_49 ;
if ( V_76 || V_77 )
V_3 = V_77 - V_76 + 1 ;
else
V_3 = V_29 -> V_81 ;
if ( V_3 < 32L )
V_3 = 32L ;
F_27 ( L_42
L_43 ,
V_29 -> V_33 -> V_32 , V_75 -> V_78 , V_75 -> V_79 ,
V_29 -> V_81 , V_76 , V_77 , V_3 ) ;
F_3 ( & V_9 , V_3 , V_29 -> V_33 ) ;
V_26 = F_65 ( V_29 , V_75 , F_59 , & V_9 ) ;
if ( F_14 ( V_26 ) ) {
F_9 ( L_44 , V_26 ) ;
return V_26 ;
}
V_26 = F_57 ( & V_9 ) ;
if ( F_14 ( V_26 ) )
return V_26 ;
if ( V_75 -> V_82 == V_83 ) {
return F_57 ( & V_9 ) ;
} else if ( V_9 . V_17 ) {
unsigned V_30 ;
for ( V_30 = 0 ; V_30 < V_9 . V_17 ; V_30 ++ ) {
struct V_22 * V_22 = V_9 . V_4 [ V_30 ] ;
F_24 ( V_22 ) ;
F_66 ( V_22 ) ;
F_29 ( V_22 ) ;
}
}
return 0 ;
}
static void F_67 ( struct V_10 * V_10 , T_2 V_84 )
{
if ( V_84 > V_10 -> V_55 )
F_68 ( V_10 , V_84 , V_10 -> V_55 ) ;
}
int F_69 ( struct V_61 * V_61 , struct V_62 * V_29 ,
T_2 V_85 , unsigned V_25 , unsigned V_74 ,
struct V_22 * * V_86 , void * * V_87 )
{
int V_26 = 0 ;
struct V_22 * V_22 ;
V_22 = * V_86 ;
if ( V_22 == NULL ) {
V_26 = F_70 ( V_61 , V_29 , V_85 , V_25 , V_74 , V_86 ,
V_87 ) ;
if ( V_26 ) {
F_20 ( L_45 ) ;
goto V_88;
}
V_22 = * V_86 ;
}
if ( ! F_42 ( V_22 ) && ( V_25 != V_57 ) ) {
T_2 V_55 = F_41 ( V_29 -> V_33 ) ;
T_3 V_56 = V_55 >> V_49 ;
T_4 V_89 ;
if ( V_22 -> V_35 < V_56 )
V_89 = V_57 ;
else if ( V_22 -> V_35 == V_56 )
V_89 = V_55 & ~ V_58 ;
else
V_89 = 0 ;
if ( ! V_89 ) {
F_19 ( V_22 ) ;
F_16 ( V_22 ) ;
goto V_88;
}
V_26 = F_47 ( V_22 , true ) ;
if ( V_26 ) {
F_29 ( V_22 ) ;
F_20 ( L_46 ) ;
}
}
V_88:
if ( F_14 ( V_26 ) )
F_67 ( V_29 -> V_33 , V_85 + V_25 ) ;
return V_26 ;
}
static int F_71 ( struct V_61 * V_61 ,
struct V_62 * V_29 ,
T_2 V_85 , unsigned V_25 , unsigned V_74 ,
struct V_22 * * V_86 , void * * V_87 )
{
* V_86 = NULL ;
return F_69 ( V_61 , V_29 , V_85 , V_25 , V_74 , V_86 ,
V_87 ) ;
}
static int F_72 ( struct V_61 * V_61 , struct V_62 * V_29 ,
T_2 V_85 , unsigned V_25 , unsigned V_90 ,
struct V_22 * V_22 , void * V_87 )
{
struct V_10 * V_10 = V_29 -> V_33 ;
T_2 V_55 = V_10 -> V_55 ;
int V_26 ;
V_26 = F_73 ( V_61 , V_29 , V_85 , V_25 , V_90 , V_22 , V_87 ) ;
if ( F_14 ( V_26 ) )
F_67 ( V_10 , V_85 + V_25 ) ;
if ( V_55 != V_10 -> V_55 )
F_74 ( V_10 ) ;
return V_26 ;
}
static int F_75 ( struct V_22 * V_22 , T_5 V_91 )
{
F_20 ( L_47 , V_22 -> V_35 ) ;
F_76 ( 1 ) ;
return 0 ;
}
static void F_77 ( struct V_22 * V_22 , unsigned long V_53 )
{
F_20 ( L_48 , V_22 -> V_35 , V_53 ) ;
F_76 ( 1 ) ;
}
static inline int F_78 ( struct V_10 * V_10 )
{
struct V_45 * V_46 = F_36 ( V_10 ) ;
return F_79 ( V_10 -> V_92 ) && ( V_46 -> V_93 [ 0 ] != 0 ) ;
}
static int F_80 ( struct V_10 * V_10 , T_2 V_94 )
{
struct V_45 * V_46 = F_36 ( V_10 ) ;
struct V_11 * V_12 = V_10 -> V_13 -> V_14 ;
int V_26 ;
V_10 -> V_95 = V_10 -> V_96 = V_97 ;
V_26 = F_81 ( & V_12 -> V_2 , & V_46 -> V_48 , ( T_1 ) V_94 ) ;
if ( F_8 ( ! V_26 ) )
F_82 ( V_10 , V_94 ) ;
F_20 ( L_49 ,
V_10 -> V_32 , V_94 , V_26 ) ;
return V_26 ;
}
int F_83 ( struct V_98 * V_98 , struct V_99 * V_99 )
{
struct V_10 * V_10 = V_98 -> V_100 ;
int error ;
error = F_61 ( F_36 ( V_10 ) ) ;
if ( F_14 ( error ) )
return error ;
error = F_84 ( V_10 , V_99 ) ;
if ( F_14 ( error ) )
return error ;
if ( ( V_99 -> V_101 & V_102 ) &&
V_99 -> V_103 != F_41 ( V_10 ) ) {
error = F_80 ( V_10 , V_99 -> V_103 ) ;
if ( F_14 ( error ) )
return error ;
}
F_85 ( V_10 , V_99 ) ;
F_74 ( V_10 ) ;
return 0 ;
}
static int F_86 ( struct V_104 * V_105 , struct V_45 * V_46 ,
struct V_106 * V_10 )
{
struct V_11 * V_12 = V_105 -> V_14 ;
struct V_107 V_108 [] = {
[ 0 ] = V_109 ,
[ 1 ] = V_110 ,
[ 2 ] = V_111 ,
} ;
struct V_36 * V_15 ;
struct V_112 * V_2 ;
int V_26 ;
V_26 = F_87 ( & V_12 -> V_2 , & V_46 -> V_48 , & V_15 ) ;
if ( F_14 ( V_26 ) ) {
F_9 ( L_50 , V_113 ) ;
return V_26 ;
}
V_108 [ 1 ] . V_25 = F_88 ( V_12 -> V_48 . V_114 ) ;
V_108 [ 2 ] . V_25 = F_88 ( V_12 -> V_48 . V_114 ) ;
V_15 -> V_115 = V_108 ;
V_15 -> V_116 = F_89 ( V_108 ) ;
V_26 = F_38 ( V_15 ) ;
if ( F_14 ( V_26 ) ) {
F_9 ( L_51 ,
F_28 ( V_46 -> V_117 . V_118 . V_119 ) , V_26 ) ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_92 = 0040000 | ( 0777 & ~ 022 ) ;
if ( ( V_26 == - V_120 ) || ( V_26 == - V_121 ) )
V_26 = 0 ;
goto V_88;
}
V_26 = F_90 ( V_15 , & V_108 [ 0 ] ) ;
if ( V_26 ) {
F_9 ( L_52 , V_113 ) ;
goto V_88;
}
F_76 ( V_108 [ 0 ] . V_25 != V_122 ) ;
memcpy ( V_10 , V_108 [ 0 ] . V_123 , V_122 ) ;
V_26 = F_90 ( V_15 , & V_108 [ 1 ] ) ;
if ( V_26 ) {
F_9 ( L_52 , V_113 ) ;
goto V_88;
}
if ( V_108 [ 1 ] . V_25 ) {
V_2 = V_108 [ 1 ] . V_123 ;
if ( V_2 -> V_124 != F_91 ( V_125 ) ) {
F_9 ( L_53 ,
V_113 , V_2 -> V_124 ) ;
V_26 = - V_126 ;
goto V_88;
}
}
V_26 = F_90 ( V_15 , & V_108 [ 2 ] ) ;
if ( V_26 ) {
F_9 ( L_52 , V_113 ) ;
goto V_88;
}
if ( V_108 [ 2 ] . V_25 ) {
V_2 = V_108 [ 2 ] . V_123 ;
if ( V_2 -> V_124 != F_91 ( V_125 ) ) {
F_9 ( L_54 ,
V_113 , V_2 -> V_124 ) ;
V_26 = - V_126 ;
goto V_88;
}
}
V_88:
F_12 ( V_15 ) ;
return V_26 ;
}
static void F_92 ( struct V_45 * V_46 )
{
F_93 ( & V_46 -> V_127 ) ;
V_46 -> V_128 = 0 ;
}
struct V_10 * F_94 ( struct V_104 * V_105 , unsigned long V_129 )
{
struct V_45 * V_46 ;
struct V_106 V_130 ;
struct V_10 * V_10 ;
int V_26 ;
V_10 = F_95 ( V_105 , V_129 ) ;
if ( ! V_10 )
return F_96 ( - V_24 ) ;
if ( ! ( V_10 -> V_131 & V_132 ) )
return V_10 ;
V_46 = F_36 ( V_10 ) ;
F_92 ( V_46 ) ;
F_97 ( & V_46 -> V_48 , & V_46 -> V_117 , V_105 -> V_14 ,
F_98 ( V_46 ) ) ;
V_26 = F_86 ( V_105 , V_46 , & V_130 ) ;
if ( V_26 )
goto V_133;
F_99 ( V_46 ) ;
V_10 -> V_92 = F_100 ( V_130 . V_92 ) ;
V_10 -> V_134 = F_101 ( V_130 . V_134 ) ;
V_10 -> V_135 = F_101 ( V_130 . V_135 ) ;
F_102 ( V_10 , F_100 ( V_130 . V_136 ) ) ;
V_10 -> V_96 . V_137 = ( signed ) F_101 ( V_130 . V_96 ) ;
V_10 -> V_138 . V_137 = ( signed ) F_101 ( V_130 . V_138 ) ;
V_10 -> V_95 . V_137 = ( signed ) F_101 ( V_130 . V_95 ) ;
V_10 -> V_96 . V_139 =
V_10 -> V_138 . V_139 = V_10 -> V_95 . V_139 = 0 ;
V_46 -> V_140 = F_103 ( V_130 . V_55 ) ;
F_104 ( V_10 , V_46 -> V_140 ) ;
V_10 -> V_141 = V_142 ;
V_10 -> V_143 = F_101 ( V_130 . V_143 ) ;
V_46 -> V_144 = 0 ;
if ( ( V_10 -> V_145 == 0 ) && ( V_10 -> V_92 == 0 ) ) {
V_26 = - V_146 ;
goto V_133;
}
if ( F_105 ( V_10 -> V_92 ) || F_106 ( V_10 -> V_92 ) ) {
if ( V_130 . V_93 [ 0 ] )
V_10 -> V_147 =
F_107 ( F_101 ( V_130 . V_93 [ 0 ] ) ) ;
else
V_10 -> V_147 =
F_108 ( F_101 ( V_130 . V_93 [ 1 ] ) ) ;
} else {
memcpy ( V_46 -> V_93 , V_130 . V_93 , sizeof( V_130 . V_93 ) ) ;
}
V_10 -> V_66 -> V_148 = V_105 -> V_149 ;
if ( F_109 ( V_10 -> V_92 ) ) {
V_10 -> V_150 = & V_151 ;
V_10 -> V_152 = & V_153 ;
V_10 -> V_66 -> V_154 = & V_155 ;
} else if ( F_110 ( V_10 -> V_92 ) ) {
V_10 -> V_150 = & V_156 ;
V_10 -> V_152 = & V_157 ;
V_10 -> V_66 -> V_154 = & V_155 ;
} else if ( F_79 ( V_10 -> V_92 ) ) {
if ( F_78 ( V_10 ) )
V_10 -> V_150 = & V_158 ;
else {
V_10 -> V_150 = & V_159 ;
V_10 -> V_66 -> V_154 = & V_155 ;
}
} else {
V_10 -> V_150 = & V_160 ;
if ( V_130 . V_93 [ 0 ] )
F_111 ( V_10 , V_10 -> V_92 ,
F_107 ( F_101 ( V_130 . V_93 [ 0 ] ) ) ) ;
else
F_111 ( V_10 , V_10 -> V_92 ,
F_108 ( F_101 ( V_130 . V_93 [ 1 ] ) ) ) ;
}
F_112 ( V_10 ) ;
return V_10 ;
V_133:
F_113 ( V_10 ) ;
return F_96 ( V_26 ) ;
}
int F_114 ( struct V_45 * V_46 )
{
if ( ! F_43 ( V_46 ) ) {
F_20 ( L_55 ) ;
F_34 ( ! F_115 ( V_46 ) ) ;
F_116 ( V_46 -> V_127 , F_43 ( V_46 ) ) ;
F_20 ( L_56 ) ;
}
return F_14 ( F_117 ( & V_46 -> V_161 ) ) ? - V_162 : 0 ;
}
static void F_118 ( struct V_36 * V_15 , void * V_37 )
{
struct V_10 * V_10 = V_37 ;
struct V_45 * V_46 = F_36 ( V_10 ) ;
struct V_11 * V_12 = V_10 -> V_13 -> V_14 ;
int V_26 ;
V_26 = F_26 ( V_15 , NULL ) ;
F_12 ( V_15 ) ;
F_31 ( & V_12 -> V_38 ) ;
if ( F_14 ( V_26 ) ) {
F_9 ( L_57 ,
F_28 ( F_98 ( V_46 ) ) ,
F_28 ( V_46 -> V_117 . V_118 . V_163 ) ) ;
}
F_99 ( V_46 ) ;
F_119 ( & V_46 -> V_127 ) ;
}
struct V_10 * F_120 ( struct V_10 * V_164 , T_6 V_165 )
{
struct V_104 * V_105 = V_164 -> V_13 ;
struct V_11 * V_12 = V_105 -> V_14 ;
struct V_10 * V_10 ;
struct V_45 * V_46 ;
struct V_36 * V_15 ;
int V_26 ;
V_10 = F_121 ( V_105 ) ;
if ( ! V_10 )
return F_96 ( - V_24 ) ;
V_46 = F_36 ( V_10 ) ;
F_92 ( V_46 ) ;
F_122 ( V_46 ) ;
V_10 -> V_66 -> V_148 = V_105 -> V_149 ;
F_123 ( V_10 , V_164 , V_165 ) ;
V_10 -> V_32 = V_12 -> V_166 ++ ;
V_10 -> V_141 = V_142 ;
V_10 -> V_95 = V_10 -> V_138 = V_10 -> V_96 = V_97 ;
V_46 -> V_140 = V_10 -> V_55 = 0 ;
F_124 ( & V_12 -> V_167 ) ;
V_10 -> V_143 = V_12 -> V_168 ++ ;
F_125 ( & V_12 -> V_167 ) ;
F_126 ( V_10 ) ;
F_97 ( & V_46 -> V_48 , & V_46 -> V_117 , V_105 -> V_14 ,
F_98 ( V_46 ) ) ;
F_127 ( V_12 ) ;
F_74 ( V_10 ) ;
V_26 = F_87 ( & V_12 -> V_2 , & V_46 -> V_48 , & V_15 ) ;
if ( F_14 ( V_26 ) ) {
F_9 ( L_58 ) ;
return F_96 ( V_26 ) ;
}
V_15 -> V_51 = F_118 ;
V_15 -> V_52 = V_10 ;
V_26 = F_128 ( V_15 ) ;
if ( V_26 ) {
F_12 ( V_15 ) ;
return F_96 ( V_26 ) ;
}
F_39 ( & V_12 -> V_38 ) ;
return V_10 ;
}
static void F_129 ( struct V_36 * V_15 , void * V_37 )
{
struct V_169 * args = V_37 ;
F_12 ( V_15 ) ;
F_31 ( & args -> V_12 -> V_38 ) ;
F_11 ( args ) ;
}
static int F_130 ( struct V_10 * V_10 , int V_170 )
{
struct V_45 * V_46 = F_36 ( V_10 ) ;
struct V_104 * V_105 = V_10 -> V_13 ;
struct V_11 * V_12 = V_105 -> V_14 ;
struct V_36 * V_15 ;
struct V_107 V_171 ;
struct V_106 * V_130 ;
struct V_169 * args ;
int V_26 ;
args = F_131 ( sizeof( * args ) , V_23 ) ;
if ( ! args ) {
F_20 ( L_59 ) ;
return - V_24 ;
}
V_130 = & args -> V_130 ;
V_130 -> V_92 = F_91 ( V_10 -> V_92 ) ;
V_130 -> V_134 = F_132 ( V_10 -> V_134 ) ;
V_130 -> V_135 = F_132 ( V_10 -> V_135 ) ;
V_130 -> V_136 = F_91 ( V_10 -> V_145 ) ;
V_130 -> V_96 = F_132 ( V_10 -> V_96 . V_137 ) ;
V_130 -> V_138 = F_132 ( V_10 -> V_138 . V_137 ) ;
V_130 -> V_95 = F_132 ( V_10 -> V_95 . V_137 ) ;
V_46 -> V_140 = F_41 ( V_10 ) ;
V_130 -> V_55 = F_133 ( V_46 -> V_140 ) ;
V_130 -> V_143 = F_132 ( V_10 -> V_143 ) ;
if ( F_105 ( V_10 -> V_92 ) || F_106 ( V_10 -> V_92 ) ) {
if ( F_134 ( V_10 -> V_147 ) ) {
V_130 -> V_93 [ 0 ] =
F_132 ( F_135 ( V_10 -> V_147 ) ) ;
V_130 -> V_93 [ 1 ] = 0 ;
} else {
V_130 -> V_93 [ 0 ] = 0 ;
V_130 -> V_93 [ 1 ] =
F_132 ( F_136 ( V_10 -> V_147 ) ) ;
V_130 -> V_93 [ 2 ] = 0 ;
}
} else
memcpy ( V_130 -> V_93 , V_46 -> V_93 , sizeof( V_130 -> V_93 ) ) ;
V_26 = F_87 ( & V_12 -> V_2 , & V_46 -> V_48 , & V_15 ) ;
if ( F_14 ( V_26 ) ) {
F_9 ( L_50 , V_113 ) ;
goto V_172;
}
V_171 = V_109 ;
V_171 . V_123 = V_130 ;
V_15 -> V_173 = 1 ;
V_15 -> V_174 = & V_171 ;
F_61 ( V_46 ) ;
if ( ! V_170 ) {
args -> V_12 = V_12 ;
V_15 -> V_51 = F_129 ;
V_15 -> V_52 = args ;
}
V_26 = F_58 ( V_15 ) ;
if ( ! V_170 && ! V_26 ) {
F_39 ( & V_12 -> V_38 ) ;
goto V_88;
}
F_12 ( V_15 ) ;
V_172:
F_11 ( args ) ;
V_88:
F_20 ( L_60 ,
V_10 -> V_32 , V_170 , V_26 ) ;
return V_26 ;
}
int F_137 ( struct V_10 * V_10 , struct V_71 * V_75 )
{
return F_130 ( V_10 , 1 ) ;
}
static void F_138 ( struct V_36 * V_15 , void * V_37 )
{
struct V_11 * V_12 = V_37 ;
F_12 ( V_15 ) ;
F_31 ( & V_12 -> V_38 ) ;
}
void F_139 ( struct V_10 * V_10 )
{
struct V_45 * V_46 = F_36 ( V_10 ) ;
struct V_104 * V_105 = V_10 -> V_13 ;
struct V_11 * V_12 = V_105 -> V_14 ;
struct V_36 * V_15 ;
int V_26 ;
F_140 ( & V_10 -> V_93 , 0 ) ;
if ( V_10 -> V_145 || F_117 ( V_10 ) )
goto V_175;
V_10 -> V_55 = 0 ;
F_141 ( V_10 ) ;
F_61 ( V_46 ) ;
V_26 = F_87 ( & V_12 -> V_2 , & V_46 -> V_48 , & V_15 ) ;
if ( F_14 ( V_26 ) ) {
F_9 ( L_61 , V_113 ) ;
return;
}
V_15 -> V_51 = F_138 ;
V_15 -> V_52 = V_12 ;
V_26 = F_142 ( V_15 ) ;
if ( V_26 ) {
F_9 ( L_62 , V_113 ) ;
F_12 ( V_15 ) ;
return;
}
F_39 ( & V_12 -> V_38 ) ;
return;
V_175:
F_141 ( V_10 ) ;
}
