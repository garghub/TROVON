unsigned F_1 ( struct V_1 * V_2 ,
unsigned V_3 )
{
unsigned V_4 = F_2 ( unsigned , V_3 ,
V_2 -> V_5 / V_6 ) ;
return V_4 ;
}
static void F_3 ( struct V_7 * V_8 , unsigned V_3 ,
struct V_9 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 -> V_13 ;
V_8 -> V_11 = V_11 ;
V_8 -> V_9 = V_9 ;
V_8 -> V_3 = V_3 ;
V_8 -> V_14 = NULL ;
V_8 -> V_4 = NULL ;
V_8 -> V_15 = 0 ;
V_8 -> V_16 = 0 ;
V_8 -> V_17 = 0 ;
V_8 -> V_18 = - 1 ;
V_8 -> V_19 = false ;
V_8 -> V_20 = NULL ;
}
static void F_4 ( struct V_7 * V_8 )
{
V_8 -> V_3 -= F_5 ( V_8 -> V_16 , V_8 -> V_3 ) ;
V_8 -> V_4 = NULL ;
V_8 -> V_15 = 0 ;
V_8 -> V_16 = 0 ;
V_8 -> V_17 = 0 ;
V_8 -> V_18 = - 1 ;
V_8 -> V_14 = NULL ;
V_8 -> V_20 = NULL ;
if ( ! V_8 -> V_3 )
V_8 -> V_3 =
F_1 ( & V_8 -> V_11 -> V_2 , ~ 0 ) ;
}
static int F_6 ( struct V_7 * V_8 )
{
unsigned V_4 ;
V_4 = F_1 ( & V_8 -> V_11 -> V_2 , V_8 -> V_3 ) ;
for (; V_4 ; V_4 >>= 1 ) {
V_8 -> V_4 = F_7 ( V_4 * sizeof( struct V_21 * ) ,
V_22 ) ;
if ( F_8 ( V_8 -> V_4 ) ) {
V_8 -> V_15 = V_4 ;
return 0 ;
}
}
F_9 ( L_1 ,
V_8 -> V_3 ) ;
return - V_23 ;
}
static void F_10 ( struct V_7 * V_8 )
{
F_11 ( V_8 -> V_4 ) ;
V_8 -> V_4 = NULL ;
if ( V_8 -> V_14 ) {
F_12 ( V_8 -> V_14 ) ;
V_8 -> V_14 = NULL ;
}
}
static int F_13 ( struct V_7 * V_8 , struct V_21 * V_21 ,
unsigned V_24 )
{
if ( F_14 ( V_8 -> V_16 >= V_8 -> V_15 ) )
return - V_23 ;
V_8 -> V_4 [ V_8 -> V_16 ++ ] = V_21 ;
V_8 -> V_17 += V_24 ;
return 0 ;
}
static int F_15 ( struct V_21 * V_21 , int V_25 )
{
switch ( V_25 ) {
case 0 :
F_16 ( V_21 ) ;
if ( F_17 ( V_21 ) )
F_18 ( V_21 ) ;
break;
case - V_26 :
F_19 ( V_21 ) ;
F_16 ( V_21 ) ;
if ( F_17 ( V_21 ) )
F_18 ( V_21 ) ;
F_20 ( L_2 ) ;
case V_27 :
V_25 = 0 ;
break;
default:
F_21 ( V_21 ) ;
}
return V_25 ;
}
static void F_22 ( struct V_21 * V_21 , int V_25 )
{
if ( F_14 ( V_25 == V_27 ) )
return;
if ( V_25 ) {
F_23 ( V_21 -> V_28 , V_25 ) ;
F_21 ( V_21 ) ;
}
F_24 ( V_21 ) ;
}
static int F_25 ( struct V_7 * V_8 )
{
int V_29 ;
T_1 V_30 ;
T_1 V_17 = 0 ;
int V_25 = F_26 ( V_8 -> V_14 , NULL ) ;
if ( F_8 ( ! V_25 ) ) {
V_30 = V_8 -> V_17 ;
V_25 = V_27 ;
} else {
V_30 = 0 ;
}
F_27 ( L_3
L_4 ,
V_8 -> V_9 -> V_31 , F_28 ( V_30 ) , V_8 -> V_17 ,
V_8 -> V_16 ) ;
for ( V_29 = 0 ; V_29 < V_8 -> V_16 ; V_29 ++ ) {
struct V_21 * V_21 = V_8 -> V_4 [ V_29 ] ;
struct V_9 * V_9 = V_21 -> V_28 -> V_32 ;
int V_33 ;
if ( V_9 != V_8 -> V_9 )
continue;
if ( F_8 ( V_17 < V_30 ) )
V_33 = 0 ;
else
V_33 = V_25 ;
F_27 ( L_5 ,
V_9 -> V_31 , V_21 -> V_34 ,
V_33 ? L_6 : L_7 ) ;
V_25 = F_15 ( V_21 , V_33 ) ;
if ( ! V_8 -> V_19 )
F_29 ( V_21 ) ;
V_17 += V_6 ;
}
F_10 ( V_8 ) ;
F_27 ( L_8 ) ;
return V_25 ;
}
static void F_30 ( struct V_35 * V_14 , void * V_36 )
{
struct V_7 * V_8 = V_36 ;
F_25 ( V_8 ) ;
F_31 ( & V_8 -> V_11 -> V_37 ) ;
F_11 ( V_8 ) ;
}
static void F_32 ( struct V_7 * V_8 , int V_25 , int V_38 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_8 -> V_16 ; V_29 ++ ) {
struct V_21 * V_21 = V_8 -> V_4 [ V_29 ] ;
if ( V_38 == V_39 )
F_15 ( V_21 , V_25 ) ;
else
F_22 ( V_21 , V_25 ) ;
F_29 ( V_21 ) ;
}
}
static int F_33 ( struct V_35 * V_14 ,
struct V_7 * V_40 , struct V_7 * V_8 )
{
F_34 ( V_40 -> V_16 < V_14 -> V_16 ) ;
if ( V_40 -> V_16 > V_14 -> V_16 ) {
struct V_21 * * V_41 ;
unsigned V_42 = V_40 -> V_16 - V_14 -> V_16 ;
unsigned long V_43 = V_40 -> V_17 - V_14 -> V_17 ;
unsigned V_29 ;
int V_25 ;
V_40 -> V_16 = V_14 -> V_16 ;
V_40 -> V_17 = V_14 -> V_17 ;
V_8 -> V_3 += V_42 ;
V_8 -> V_16 = V_42 ;
V_8 -> V_17 = V_43 ;
V_41 = V_40 -> V_4 + V_40 -> V_16 ;
V_8 -> V_18 = ( * V_41 ) -> V_34 ;
V_25 = F_6 ( V_8 ) ;
if ( F_14 ( V_25 ) )
return V_25 ;
for ( V_29 = 0 ; V_29 < V_42 ; ++ V_29 )
V_8 -> V_4 [ V_29 ] = * V_41 ++ ;
F_20 ( L_9
L_10
L_11 ,
V_40 -> V_16 , V_42 , V_8 -> V_3 ,
V_8 -> V_18 * V_6 , V_8 -> V_17 ) ;
}
return 0 ;
}
static int F_35 ( struct V_7 * V_8 )
{
struct V_44 * V_45 = F_36 ( V_8 -> V_9 ) ;
struct V_35 * V_14 ;
struct V_7 * V_46 = NULL ;
int V_25 ;
if ( ! V_8 -> V_4 )
return 0 ;
if ( ! V_8 -> V_14 ) {
int V_25 = F_37 ( & V_8 -> V_11 -> V_2 , & V_45 -> V_47 , true ,
V_8 -> V_18 << V_48 ,
V_8 -> V_17 , & V_8 -> V_14 ) ;
if ( V_25 )
return V_25 ;
}
V_14 = V_8 -> V_14 ;
V_14 -> V_4 = V_8 -> V_4 ;
if ( V_8 -> V_19 ) {
F_38 ( V_8 -> V_14 ) ;
return F_25 ( V_8 ) ;
}
V_46 = F_7 ( sizeof( * V_46 ) , V_22 ) ;
if ( ! V_46 ) {
V_25 = - V_23 ;
goto V_49;
}
* V_46 = * V_8 ;
V_14 -> V_50 = F_30 ;
V_14 -> V_51 = V_46 ;
F_4 ( V_8 ) ;
V_25 = F_33 ( V_14 , V_46 , V_8 ) ;
if ( F_14 ( V_25 ) )
goto V_49;
F_27 ( L_12 ,
V_8 -> V_9 -> V_31 , F_28 ( V_14 -> V_52 ) , F_28 ( V_14 -> V_17 ) ) ;
V_25 = F_38 ( V_14 ) ;
if ( F_14 ( V_25 ) )
goto V_49;
F_39 ( & V_8 -> V_11 -> V_37 ) ;
return 0 ;
V_49:
if ( ! V_46 )
V_46 = V_8 ;
F_32 ( V_46 , V_25 , V_39 ) ;
F_10 ( V_46 ) ;
F_11 ( V_46 ) ;
return V_25 ;
}
static int F_40 ( void * V_53 , struct V_21 * V_21 )
{
struct V_7 * V_8 = V_53 ;
struct V_9 * V_9 = V_8 -> V_9 ;
struct V_44 * V_45 = F_36 ( V_9 ) ;
T_2 V_54 = F_41 ( V_9 ) ;
T_3 V_55 = V_54 >> V_48 ;
T_4 V_24 ;
int V_25 ;
F_34 ( ! F_42 ( V_21 ) ) ;
if ( F_43 ( V_21 ) )
F_9 ( L_13 , V_8 -> V_9 -> V_31 ,
V_21 -> V_34 ) ;
V_8 -> V_20 = V_21 ;
if ( V_21 -> V_34 < V_55 )
V_24 = V_56 ;
else if ( V_21 -> V_34 == V_55 )
V_24 = V_54 & ~ V_57 ;
else
V_24 = 0 ;
if ( ! V_24 || ! F_44 ( V_45 ) ) {
F_19 ( V_21 ) ;
F_16 ( V_21 ) ;
if ( F_17 ( V_21 ) )
F_18 ( V_21 ) ;
if ( ! V_8 -> V_19 )
F_29 ( V_21 ) ;
F_20 ( L_14
L_15
L_16 , V_9 -> V_31 , V_24 ,
V_8 -> V_19 , V_21 -> V_34 , V_55 ) ;
return F_35 ( V_8 ) ;
}
V_58:
if ( F_14 ( V_8 -> V_18 == - 1 ) ) {
V_8 -> V_18 = V_21 -> V_34 ;
} else if ( F_14 ( ( V_8 -> V_18 + V_8 -> V_16 ) !=
V_21 -> V_34 ) ) {
V_25 = F_35 ( V_8 ) ;
if ( F_14 ( V_25 ) )
goto V_59;
goto V_58;
}
if ( ! V_8 -> V_4 ) {
V_25 = F_6 ( V_8 ) ;
if ( F_14 ( V_25 ) )
goto V_59;
}
if ( V_24 != V_56 )
F_45 ( V_21 , V_24 , V_56 - V_24 ) ;
F_27 ( L_17 ,
V_9 -> V_31 , V_21 -> V_34 , V_24 ) ;
V_25 = F_13 ( V_8 , V_21 , V_24 ) ;
if ( V_25 ) {
F_27 ( L_18
L_19 ,
V_21 , V_24 , V_8 -> V_16 , V_8 -> V_17 ) ;
V_25 = F_35 ( V_8 ) ;
if ( F_14 ( V_25 ) )
goto V_59;
goto V_58;
}
return 0 ;
V_59:
F_29 ( V_21 ) ;
return V_25 ;
}
static int F_46 ( struct V_60 * V_60 , struct V_61 * V_28 ,
struct V_62 * V_4 , unsigned V_16 )
{
struct V_7 V_8 ;
int V_25 ;
F_3 ( & V_8 , V_16 , V_28 -> V_32 ) ;
V_25 = F_47 ( V_28 , V_4 , F_40 , & V_8 ) ;
if ( V_25 ) {
F_9 ( L_20 , V_25 ) ;
return V_25 ;
}
V_25 = F_35 ( & V_8 ) ;
if ( F_14 ( V_25 ) )
return V_25 ;
return F_35 ( & V_8 ) ;
}
static int F_48 ( struct V_21 * V_21 , bool V_19 )
{
struct V_7 V_8 ;
int V_25 ;
F_3 ( & V_8 , 1 , V_21 -> V_28 -> V_32 ) ;
V_8 . V_19 = V_19 ;
V_25 = F_40 ( & V_8 , V_21 ) ;
if ( V_25 ) {
F_9 ( L_21 , V_25 ) ;
return V_25 ;
}
return F_35 ( & V_8 ) ;
}
static int F_49 ( struct V_60 * V_60 , struct V_21 * V_21 )
{
return F_48 ( V_21 , false ) ;
}
static void F_50 ( struct V_35 * V_14 , void * V_36 )
{
struct V_7 * V_8 = V_36 ;
int V_29 ;
T_1 V_30 ;
T_1 V_17 = 0 ;
int V_25 = F_26 ( V_14 , NULL ) ;
F_31 ( & V_8 -> V_11 -> V_37 ) ;
if ( F_8 ( ! V_25 ) ) {
V_30 = V_8 -> V_17 ;
V_25 = V_27 ;
} else {
V_30 = 0 ;
}
F_27 ( L_22
L_4 ,
V_8 -> V_9 -> V_31 , F_28 ( V_30 ) , V_8 -> V_17 ,
V_8 -> V_16 ) ;
for ( V_29 = 0 ; V_29 < V_8 -> V_16 ; V_29 ++ ) {
struct V_21 * V_21 = V_8 -> V_4 [ V_29 ] ;
struct V_9 * V_9 = V_21 -> V_28 -> V_32 ;
int V_33 ;
if ( V_9 != V_8 -> V_9 )
continue;
if ( F_8 ( V_17 < V_30 ) )
V_33 = 0 ;
else
V_33 = V_25 ;
F_22 ( V_21 , V_33 ) ;
F_29 ( V_21 ) ;
F_27 ( L_23 ,
V_9 -> V_31 , V_21 -> V_34 , V_33 ) ;
V_17 += V_6 ;
}
F_10 ( V_8 ) ;
F_11 ( V_8 ) ;
F_27 ( L_24 ) ;
}
static struct V_21 * F_51 ( void * V_63 , T_1 V_52 , bool * V_64 )
{
struct V_7 * V_8 = V_63 ;
T_3 V_34 = V_52 / V_6 ;
if ( ! V_8 -> V_20 ||
( V_8 -> V_20 -> V_34 != V_34 ) ) {
struct V_21 * V_21 ;
T_2 V_54 = F_41 ( V_8 -> V_9 ) ;
if ( V_52 >= V_54 ) {
* V_64 = true ;
F_27 ( L_25 , V_34 ) ;
return F_52 ( 0 ) ;
}
V_21 = F_53 ( V_8 -> V_9 -> V_65 , V_34 ) ;
if ( ! V_21 ) {
V_21 = F_54 ( V_8 -> V_9 -> V_65 ,
V_34 , V_66 ) ;
if ( F_14 ( ! V_21 ) ) {
F_20 ( L_26
L_27 , F_28 ( V_34 ) ) ;
return NULL ;
}
F_29 ( V_21 ) ;
}
if ( F_55 ( V_21 ) || F_56 ( V_21 ) )
* V_64 = true ;
else
* V_64 = F_43 ( V_21 ) ;
F_27 ( L_28 , V_34 , * V_64 ) ;
return V_21 ;
} else {
F_27 ( L_29 ,
V_8 -> V_20 -> V_34 ) ;
* V_64 = true ;
return V_8 -> V_20 ;
}
}
static void F_57 ( void * V_63 , struct V_21 * V_21 )
{
struct V_7 * V_8 = V_63 ;
if ( ( V_8 -> V_20 != V_21 ) && ( F_52 ( 0 ) != V_21 ) ) {
F_27 ( L_30 , V_21 -> V_34 ) ;
F_58 ( V_21 ) ;
return;
}
F_27 ( L_31 ,
F_52 ( 0 ) == V_21 ? - 1 : V_21 -> V_34 ) ;
}
static int F_59 ( struct V_7 * V_8 )
{
struct V_44 * V_45 = F_36 ( V_8 -> V_9 ) ;
struct V_35 * V_14 ;
struct V_7 * V_46 = NULL ;
int V_25 ;
if ( ! V_8 -> V_4 )
return 0 ;
F_34 ( V_8 -> V_14 ) ;
V_25 = F_37 ( & V_8 -> V_11 -> V_2 , & V_45 -> V_47 , false ,
V_8 -> V_18 << V_48 ,
V_8 -> V_17 , & V_8 -> V_14 ) ;
if ( F_14 ( V_25 ) )
goto V_49;
V_46 = F_7 ( sizeof( * V_46 ) , V_22 ) ;
if ( ! V_46 ) {
F_9 ( L_32 ) ;
V_25 = - V_23 ;
goto V_49;
}
* V_46 = * V_8 ;
V_14 = V_8 -> V_14 ;
V_14 -> V_4 = V_46 -> V_4 ;
V_14 -> V_50 = F_50 ;
V_14 -> V_67 = & V_68 ;
V_14 -> V_51 = V_46 ;
F_4 ( V_8 ) ;
V_25 = F_33 ( V_14 , V_46 , V_8 ) ;
if ( F_14 ( V_25 ) )
goto V_49;
F_27 ( L_33 ,
V_8 -> V_9 -> V_31 , F_28 ( V_14 -> V_52 ) , F_28 ( V_14 -> V_17 ) ) ;
V_25 = F_60 ( V_14 ) ;
if ( F_14 ( V_25 ) ) {
F_9 ( L_34 ) ;
goto V_49;
}
F_39 ( & V_8 -> V_11 -> V_37 ) ;
return 0 ;
V_49:
if ( ! V_46 )
V_46 = V_8 ;
F_32 ( V_46 , V_25 , V_69 ) ;
F_10 ( V_46 ) ;
F_11 ( V_46 ) ;
return V_25 ;
}
static int F_61 ( struct V_21 * V_21 ,
struct V_70 * V_71 , void * V_53 )
{
struct V_7 * V_8 = V_53 ;
struct V_9 * V_9 = V_8 -> V_9 ;
struct V_44 * V_45 = F_36 ( V_9 ) ;
T_2 V_54 = F_41 ( V_9 ) ;
T_3 V_55 = V_54 >> V_48 ;
T_4 V_24 ;
int V_25 ;
F_34 ( ! F_42 ( V_21 ) ) ;
V_25 = F_62 ( V_45 ) ;
if ( F_14 ( V_25 ) )
goto V_59;
if ( V_21 -> V_34 < V_55 )
V_24 = V_56 ;
else {
V_24 = V_54 & ~ V_57 ;
if ( V_21 -> V_34 > V_55 || ! V_24 ) {
V_25 = F_59 ( V_8 ) ;
if ( F_14 ( V_25 ) )
goto V_59;
if ( F_17 ( V_21 ) )
F_18 ( V_21 ) ;
F_29 ( V_21 ) ;
F_20 ( L_35
L_36 ,
V_9 -> V_31 , V_21 -> V_34 ) ;
return 0 ;
}
}
V_58:
if ( F_14 ( V_8 -> V_18 == - 1 ) ) {
V_8 -> V_18 = V_21 -> V_34 ;
} else if ( F_14 ( ( V_8 -> V_18 + V_8 -> V_16 ) !=
V_21 -> V_34 ) ) {
V_25 = F_59 ( V_8 ) ;
if ( F_14 ( V_25 ) )
goto V_59;
F_20 ( L_37 ,
V_9 -> V_31 , V_21 -> V_34 ) ;
goto V_58;
}
if ( ! V_8 -> V_4 ) {
V_25 = F_6 ( V_8 ) ;
if ( F_14 ( V_25 ) )
goto V_59;
}
F_27 ( L_38 ,
V_9 -> V_31 , V_21 -> V_34 , V_24 ) ;
V_25 = F_13 ( V_8 , V_21 , V_24 ) ;
if ( F_14 ( V_25 ) ) {
F_27 ( L_39
L_40 ,
V_8 -> V_16 , V_8 -> V_17 ) ;
V_25 = F_59 ( V_8 ) ;
if ( F_14 ( V_25 ) ) {
F_20 ( L_41 , V_25 ) ;
goto V_59;
}
goto V_58;
}
F_34 ( F_56 ( V_21 ) ) ;
F_63 ( V_21 ) ;
return 0 ;
V_59:
F_20 ( L_42 ,
V_9 -> V_31 , V_21 -> V_34 , V_25 ) ;
F_64 ( V_72 , & V_21 -> V_28 -> V_73 ) ;
F_29 ( V_21 ) ;
return V_25 ;
}
static int F_65 ( struct V_61 * V_28 ,
struct V_70 * V_74 )
{
struct V_7 V_8 ;
long V_75 , V_76 , V_3 ;
int V_25 ;
V_75 = V_74 -> V_77 >> V_48 ;
V_76 = ( V_74 -> V_78 == V_79 ) ?
V_75 + V_28 -> V_80 :
V_74 -> V_78 >> V_48 ;
if ( V_75 || V_76 )
V_3 = V_76 - V_75 + 1 ;
else
V_3 = V_28 -> V_80 ;
if ( V_3 < 32L )
V_3 = 32L ;
F_27 ( L_43
L_44 ,
V_28 -> V_32 -> V_31 , V_74 -> V_77 , V_74 -> V_78 ,
V_28 -> V_80 , V_75 , V_76 , V_3 ) ;
F_3 ( & V_8 , V_3 , V_28 -> V_32 ) ;
V_25 = F_66 ( V_28 , V_74 , F_61 , & V_8 ) ;
if ( F_14 ( V_25 ) ) {
F_9 ( L_45 , V_25 ) ;
return V_25 ;
}
V_25 = F_59 ( & V_8 ) ;
if ( F_14 ( V_25 ) )
return V_25 ;
if ( V_74 -> V_81 == V_82 ) {
return F_59 ( & V_8 ) ;
} else if ( V_8 . V_16 ) {
unsigned V_29 ;
for ( V_29 = 0 ; V_29 < V_8 . V_16 ; V_29 ++ ) {
struct V_21 * V_21 = V_8 . V_4 [ V_29 ] ;
F_24 ( V_21 ) ;
F_67 ( V_21 ) ;
F_29 ( V_21 ) ;
}
}
return 0 ;
}
static void F_68 ( struct V_9 * V_9 , T_2 V_83 )
{
if ( V_83 > V_9 -> V_54 )
F_69 ( V_9 , V_9 -> V_54 ) ;
}
int F_70 ( struct V_60 * V_60 , struct V_61 * V_28 ,
T_2 V_84 , unsigned V_24 , unsigned V_73 ,
struct V_21 * * V_85 , void * * V_86 )
{
int V_25 = 0 ;
struct V_21 * V_21 ;
V_21 = * V_85 ;
if ( V_21 == NULL ) {
V_25 = F_71 ( V_60 , V_28 , V_84 , V_24 , V_73 , V_85 ,
V_86 ) ;
if ( V_25 ) {
F_20 ( L_46 ) ;
goto V_87;
}
V_21 = * V_85 ;
}
if ( ! F_43 ( V_21 ) && ( V_24 != V_56 ) ) {
T_2 V_54 = F_41 ( V_28 -> V_32 ) ;
T_3 V_55 = V_54 >> V_48 ;
T_4 V_88 ;
if ( V_21 -> V_34 < V_55 )
V_88 = V_56 ;
else if ( V_21 -> V_34 == V_55 )
V_88 = V_54 & ~ V_57 ;
else
V_88 = 0 ;
if ( ! V_88 ) {
F_19 ( V_21 ) ;
F_16 ( V_21 ) ;
goto V_87;
}
V_25 = F_48 ( V_21 , true ) ;
if ( V_25 ) {
F_29 ( V_21 ) ;
F_20 ( L_47 ) ;
}
}
V_87:
if ( F_14 ( V_25 ) )
F_68 ( V_28 -> V_32 , V_84 + V_24 ) ;
return V_25 ;
}
static int F_72 ( struct V_60 * V_60 ,
struct V_61 * V_28 ,
T_2 V_84 , unsigned V_24 , unsigned V_73 ,
struct V_21 * * V_85 , void * * V_86 )
{
* V_85 = NULL ;
return F_70 ( V_60 , V_28 , V_84 , V_24 , V_73 , V_85 ,
V_86 ) ;
}
static int F_73 ( struct V_60 * V_60 , struct V_61 * V_28 ,
T_2 V_84 , unsigned V_24 , unsigned V_89 ,
struct V_21 * V_21 , void * V_86 )
{
struct V_9 * V_9 = V_28 -> V_32 ;
T_2 V_54 = V_9 -> V_54 ;
int V_25 ;
V_25 = F_74 ( V_60 , V_28 , V_84 , V_24 , V_89 , V_21 , V_86 ) ;
if ( F_14 ( V_25 ) )
F_68 ( V_9 , V_84 + V_24 ) ;
if ( V_54 != V_9 -> V_54 )
F_75 ( V_9 ) ;
return V_25 ;
}
static int F_76 ( struct V_21 * V_21 , T_5 V_90 )
{
F_20 ( L_48 , V_21 -> V_34 ) ;
F_77 ( 1 ) ;
return 0 ;
}
static void F_78 ( struct V_21 * V_21 , unsigned int V_52 ,
unsigned int V_17 )
{
F_20 ( L_49 ,
V_21 -> V_34 , V_52 , V_17 ) ;
F_77 ( 1 ) ;
}
static T_6 F_79 ( struct V_91 * V_92 , struct V_93 * V_94 ,
T_2 V_52 )
{
return 0 ;
}
static inline int F_80 ( struct V_9 * V_9 )
{
struct V_44 * V_45 = F_36 ( V_9 ) ;
return F_81 ( V_9 -> V_95 ) && ( V_45 -> V_96 [ 0 ] != 0 ) ;
}
static int F_82 ( struct V_9 * V_9 , T_2 V_97 )
{
struct V_44 * V_45 = F_36 ( V_9 ) ;
struct V_10 * V_11 = V_9 -> V_12 -> V_13 ;
int V_25 ;
V_9 -> V_98 = V_9 -> V_99 = V_100 ;
V_25 = F_83 ( & V_11 -> V_2 , & V_45 -> V_47 , ( T_1 ) V_97 ) ;
if ( F_8 ( ! V_25 ) )
F_84 ( V_9 , V_97 ) ;
F_27 ( L_50 ,
V_9 -> V_31 , V_97 , V_25 ) ;
return V_25 ;
}
int F_85 ( struct V_101 * V_101 , struct V_102 * V_102 )
{
struct V_9 * V_9 = F_86 ( V_101 ) ;
int error ;
error = F_62 ( F_36 ( V_9 ) ) ;
if ( F_14 ( error ) )
return error ;
error = F_87 ( V_9 , V_102 ) ;
if ( F_14 ( error ) )
return error ;
if ( ( V_102 -> V_103 & V_104 ) &&
V_102 -> V_105 != F_41 ( V_9 ) ) {
error = F_82 ( V_9 , V_102 -> V_105 ) ;
if ( F_14 ( error ) )
return error ;
}
F_88 ( V_9 , V_102 ) ;
F_75 ( V_9 ) ;
return 0 ;
}
static int F_89 ( struct V_106 * V_107 , struct V_44 * V_45 ,
struct V_108 * V_9 )
{
struct V_10 * V_11 = V_107 -> V_13 ;
struct V_109 V_110 [] = {
[ 0 ] = V_111 ,
[ 1 ] = V_112 ,
[ 2 ] = V_113 ,
} ;
struct V_35 * V_14 ;
struct V_114 * V_2 ;
int V_25 ;
V_25 = F_90 ( & V_11 -> V_2 , & V_45 -> V_47 , & V_14 ) ;
if ( F_14 ( V_25 ) ) {
F_9 ( L_51 , V_115 ) ;
return V_25 ;
}
V_110 [ 1 ] . V_24 = F_91 ( V_11 -> V_47 . V_116 ) ;
V_110 [ 2 ] . V_24 = F_91 ( V_11 -> V_47 . V_116 ) ;
V_14 -> V_117 = V_110 ;
V_14 -> V_118 = F_92 ( V_110 ) ;
V_25 = F_38 ( V_14 ) ;
if ( F_14 ( V_25 ) ) {
F_9 ( L_52 ,
F_28 ( V_45 -> V_119 . V_120 . V_121 ) , V_25 ) ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_95 = 0040000 | ( 0777 & ~ 022 ) ;
V_25 = 0 ;
goto V_87;
}
V_25 = F_93 ( V_14 , & V_110 [ 0 ] ) ;
if ( V_25 ) {
F_9 ( L_53 , V_115 ) ;
goto V_87;
}
F_77 ( V_110 [ 0 ] . V_24 != V_122 ) ;
memcpy ( V_9 , V_110 [ 0 ] . V_123 , V_122 ) ;
V_25 = F_93 ( V_14 , & V_110 [ 1 ] ) ;
if ( V_25 ) {
F_9 ( L_54 , V_115 ) ;
goto V_87;
}
if ( V_110 [ 1 ] . V_24 ) {
V_2 = V_110 [ 1 ] . V_123 ;
if ( V_2 -> V_124 != F_94 ( V_125 ) ) {
F_9 ( L_55 ,
V_115 , V_2 -> V_124 ) ;
V_25 = - V_126 ;
goto V_87;
}
}
V_25 = F_93 ( V_14 , & V_110 [ 2 ] ) ;
if ( V_25 ) {
F_9 ( L_56 , V_115 ) ;
goto V_87;
}
if ( V_110 [ 2 ] . V_24 ) {
V_2 = V_110 [ 2 ] . V_123 ;
if ( V_2 -> V_124 != F_94 ( V_125 ) ) {
F_9 ( L_57 ,
V_115 , V_2 -> V_124 ) ;
V_25 = - V_126 ;
goto V_87;
}
}
V_87:
F_12 ( V_14 ) ;
return V_25 ;
}
static void F_95 ( struct V_44 * V_45 )
{
F_96 ( & V_45 -> V_127 ) ;
V_45 -> V_128 = 0 ;
}
struct V_9 * F_97 ( struct V_106 * V_107 , unsigned long V_129 )
{
struct V_44 * V_45 ;
struct V_108 V_130 ;
struct V_9 * V_9 ;
int V_25 ;
V_9 = F_98 ( V_107 , V_129 ) ;
if ( ! V_9 )
return F_99 ( - V_23 ) ;
if ( ! ( V_9 -> V_131 & V_132 ) )
return V_9 ;
V_45 = F_36 ( V_9 ) ;
F_95 ( V_45 ) ;
F_100 ( & V_45 -> V_47 , & V_45 -> V_119 , V_107 -> V_13 ,
F_101 ( V_45 ) ) ;
V_25 = F_89 ( V_107 , V_45 , & V_130 ) ;
if ( V_25 )
goto V_133;
F_102 ( V_45 ) ;
V_9 -> V_95 = F_103 ( V_130 . V_95 ) ;
F_104 ( V_9 , F_105 ( V_130 . V_134 ) ) ;
F_106 ( V_9 , F_105 ( V_130 . V_135 ) ) ;
F_107 ( V_9 , F_103 ( V_130 . V_136 ) ) ;
V_9 -> V_99 . V_137 = ( signed ) F_105 ( V_130 . V_99 ) ;
V_9 -> V_138 . V_137 = ( signed ) F_105 ( V_130 . V_138 ) ;
V_9 -> V_98 . V_137 = ( signed ) F_105 ( V_130 . V_98 ) ;
V_9 -> V_99 . V_139 =
V_9 -> V_138 . V_139 = V_9 -> V_98 . V_139 = 0 ;
V_45 -> V_140 = F_108 ( V_130 . V_54 ) ;
F_109 ( V_9 , V_45 -> V_140 ) ;
V_9 -> V_141 = V_142 ;
V_9 -> V_143 = F_105 ( V_130 . V_143 ) ;
V_45 -> V_144 = 0 ;
if ( ( V_9 -> V_145 == 0 ) && ( V_9 -> V_95 == 0 ) ) {
V_25 = - V_146 ;
goto V_133;
}
if ( F_110 ( V_9 -> V_95 ) || F_111 ( V_9 -> V_95 ) ) {
if ( V_130 . V_96 [ 0 ] )
V_9 -> V_147 =
F_112 ( F_105 ( V_130 . V_96 [ 0 ] ) ) ;
else
V_9 -> V_147 =
F_113 ( F_105 ( V_130 . V_96 [ 1 ] ) ) ;
} else {
memcpy ( V_45 -> V_96 , V_130 . V_96 , sizeof( V_130 . V_96 ) ) ;
}
if ( F_114 ( V_9 -> V_95 ) ) {
V_9 -> V_148 = & V_149 ;
V_9 -> V_150 = & V_151 ;
V_9 -> V_65 -> V_152 = & V_153 ;
} else if ( F_115 ( V_9 -> V_95 ) ) {
V_9 -> V_148 = & V_154 ;
V_9 -> V_150 = & V_155 ;
V_9 -> V_65 -> V_152 = & V_153 ;
} else if ( F_81 ( V_9 -> V_95 ) ) {
if ( F_80 ( V_9 ) ) {
V_9 -> V_148 = & V_156 ;
V_9 -> V_157 = ( char * ) V_45 -> V_96 ;
} else {
V_9 -> V_148 = & V_158 ;
V_9 -> V_65 -> V_152 = & V_153 ;
}
} else {
V_9 -> V_148 = & V_159 ;
if ( V_130 . V_96 [ 0 ] )
F_116 ( V_9 , V_9 -> V_95 ,
F_112 ( F_105 ( V_130 . V_96 [ 0 ] ) ) ) ;
else
F_116 ( V_9 , V_9 -> V_95 ,
F_113 ( F_105 ( V_130 . V_96 [ 1 ] ) ) ) ;
}
F_117 ( V_9 ) ;
return V_9 ;
V_133:
F_118 ( V_9 ) ;
return F_99 ( V_25 ) ;
}
int F_119 ( struct V_44 * V_45 )
{
if ( ! F_44 ( V_45 ) ) {
F_20 ( L_58 ) ;
F_34 ( ! F_120 ( V_45 ) ) ;
F_121 ( V_45 -> V_127 , F_44 ( V_45 ) ) ;
F_20 ( L_59 ) ;
}
return F_14 ( F_122 ( & V_45 -> V_160 ) ) ? - V_161 : 0 ;
}
static void F_123 ( struct V_35 * V_14 , void * V_36 )
{
struct V_9 * V_9 = V_36 ;
struct V_44 * V_45 = F_36 ( V_9 ) ;
struct V_10 * V_11 = V_9 -> V_12 -> V_13 ;
int V_25 ;
V_25 = F_26 ( V_14 , NULL ) ;
F_12 ( V_14 ) ;
F_31 ( & V_11 -> V_37 ) ;
if ( F_14 ( V_25 ) ) {
F_9 ( L_60 ,
F_28 ( F_101 ( V_45 ) ) ,
F_28 ( V_45 -> V_119 . V_120 . V_162 ) ) ;
}
F_102 ( V_45 ) ;
F_124 ( & V_45 -> V_127 ) ;
}
struct V_9 * F_125 ( struct V_9 * V_163 , T_7 V_164 )
{
struct V_106 * V_107 = V_163 -> V_12 ;
struct V_10 * V_11 = V_107 -> V_13 ;
struct V_9 * V_9 ;
struct V_44 * V_45 ;
struct V_35 * V_14 ;
int V_25 ;
V_9 = F_126 ( V_107 ) ;
if ( ! V_9 )
return F_99 ( - V_23 ) ;
V_45 = F_36 ( V_9 ) ;
F_95 ( V_45 ) ;
F_127 ( V_45 ) ;
F_128 ( V_9 , V_163 , V_164 ) ;
V_9 -> V_31 = V_11 -> V_165 ++ ;
V_9 -> V_141 = V_142 ;
V_9 -> V_98 = V_9 -> V_138 = V_9 -> V_99 = V_100 ;
V_45 -> V_140 = V_9 -> V_54 = 0 ;
F_129 ( & V_11 -> V_166 ) ;
V_9 -> V_143 = V_11 -> V_167 ++ ;
F_130 ( & V_11 -> V_166 ) ;
F_131 ( V_9 ) ;
F_100 ( & V_45 -> V_47 , & V_45 -> V_119 , V_107 -> V_13 ,
F_101 ( V_45 ) ) ;
F_132 ( V_11 ) ;
F_75 ( V_9 ) ;
V_25 = F_90 ( & V_11 -> V_2 , & V_45 -> V_47 , & V_14 ) ;
if ( F_14 ( V_25 ) ) {
F_9 ( L_61 ) ;
return F_99 ( V_25 ) ;
}
V_14 -> V_50 = F_123 ;
V_14 -> V_51 = V_9 ;
V_25 = F_133 ( V_14 ) ;
if ( V_25 ) {
F_12 ( V_14 ) ;
return F_99 ( V_25 ) ;
}
F_39 ( & V_11 -> V_37 ) ;
return V_9 ;
}
static void F_134 ( struct V_35 * V_14 , void * V_36 )
{
struct V_168 * args = V_36 ;
F_12 ( V_14 ) ;
F_31 ( & args -> V_11 -> V_37 ) ;
F_11 ( args ) ;
}
static int F_135 ( struct V_9 * V_9 , int V_169 )
{
struct V_44 * V_45 = F_36 ( V_9 ) ;
struct V_106 * V_107 = V_9 -> V_12 ;
struct V_10 * V_11 = V_107 -> V_13 ;
struct V_35 * V_14 ;
struct V_109 V_170 ;
struct V_108 * V_130 ;
struct V_168 * args ;
int V_25 ;
args = F_136 ( sizeof( * args ) , V_22 ) ;
if ( ! args ) {
F_20 ( L_62 ) ;
return - V_23 ;
}
V_130 = & args -> V_130 ;
V_130 -> V_95 = F_94 ( V_9 -> V_95 ) ;
V_130 -> V_134 = F_137 ( F_138 ( V_9 ) ) ;
V_130 -> V_135 = F_137 ( F_139 ( V_9 ) ) ;
V_130 -> V_136 = F_94 ( V_9 -> V_145 ) ;
V_130 -> V_99 = F_137 ( V_9 -> V_99 . V_137 ) ;
V_130 -> V_138 = F_137 ( V_9 -> V_138 . V_137 ) ;
V_130 -> V_98 = F_137 ( V_9 -> V_98 . V_137 ) ;
V_45 -> V_140 = F_41 ( V_9 ) ;
V_130 -> V_54 = F_140 ( V_45 -> V_140 ) ;
V_130 -> V_143 = F_137 ( V_9 -> V_143 ) ;
if ( F_110 ( V_9 -> V_95 ) || F_111 ( V_9 -> V_95 ) ) {
if ( F_141 ( V_9 -> V_147 ) ) {
V_130 -> V_96 [ 0 ] =
F_137 ( F_142 ( V_9 -> V_147 ) ) ;
V_130 -> V_96 [ 1 ] = 0 ;
} else {
V_130 -> V_96 [ 0 ] = 0 ;
V_130 -> V_96 [ 1 ] =
F_137 ( F_143 ( V_9 -> V_147 ) ) ;
V_130 -> V_96 [ 2 ] = 0 ;
}
} else
memcpy ( V_130 -> V_96 , V_45 -> V_96 , sizeof( V_130 -> V_96 ) ) ;
V_25 = F_90 ( & V_11 -> V_2 , & V_45 -> V_47 , & V_14 ) ;
if ( F_14 ( V_25 ) ) {
F_9 ( L_51 , V_115 ) ;
goto V_171;
}
V_170 = V_111 ;
V_170 . V_123 = V_130 ;
V_14 -> V_172 = 1 ;
V_14 -> V_173 = & V_170 ;
F_62 ( V_45 ) ;
if ( ! V_169 ) {
args -> V_11 = V_11 ;
V_14 -> V_50 = F_134 ;
V_14 -> V_51 = args ;
}
V_25 = F_60 ( V_14 ) ;
if ( ! V_169 && ! V_25 ) {
F_39 ( & V_11 -> V_37 ) ;
goto V_87;
}
F_12 ( V_14 ) ;
V_171:
F_11 ( args ) ;
V_87:
F_20 ( L_63 ,
V_9 -> V_31 , V_169 , V_25 ) ;
return V_25 ;
}
int F_144 ( struct V_9 * V_9 , struct V_70 * V_74 )
{
return F_135 ( V_9 , 1 ) ;
}
static void F_145 ( struct V_35 * V_14 , void * V_36 )
{
struct V_10 * V_11 = V_36 ;
F_12 ( V_14 ) ;
F_31 ( & V_11 -> V_37 ) ;
}
void F_146 ( struct V_9 * V_9 )
{
struct V_44 * V_45 = F_36 ( V_9 ) ;
struct V_106 * V_107 = V_9 -> V_12 ;
struct V_10 * V_11 = V_107 -> V_13 ;
struct V_35 * V_14 ;
int V_25 ;
F_147 ( & V_9 -> V_96 ) ;
if ( V_9 -> V_145 || F_122 ( V_9 ) )
goto V_174;
V_9 -> V_54 = 0 ;
F_148 ( V_9 ) ;
F_62 ( V_45 ) ;
V_25 = F_90 ( & V_11 -> V_2 , & V_45 -> V_47 , & V_14 ) ;
if ( F_14 ( V_25 ) ) {
F_9 ( L_64 , V_115 ) ;
return;
}
V_14 -> V_50 = F_145 ;
V_14 -> V_51 = V_11 ;
V_25 = F_149 ( V_14 ) ;
if ( V_25 ) {
F_9 ( L_65 , V_115 ) ;
F_12 ( V_14 ) ;
return;
}
F_39 ( & V_11 -> V_37 ) ;
return;
V_174:
F_148 ( V_9 ) ;
}
