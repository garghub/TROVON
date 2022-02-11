bool F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return true ;
return F_2 ( & V_2 -> V_3 . V_4 ) ;
}
bool F_3 ( struct V_5 * V_6 )
{
if ( ! F_4 ( V_7 , & V_6 -> V_8 ) &&
! F_5 ( V_7 , & V_6 -> V_8 ) )
F_6 ( & V_6 -> V_2 -> V_9 ) ;
return true ;
}
void F_7 ( struct V_1 * V_2 , bool V_10 )
{
F_8 ( & V_2 -> V_3 ) ;
if ( V_10 )
F_8 ( & V_2 -> V_11 ) ;
}
void F_9 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
if ( ! F_10 ( V_7 , & V_6 -> V_8 ) )
return;
F_11 ( & V_2 -> V_9 ) ;
F_7 ( V_2 , false ) ;
}
static inline bool F_12 ( struct V_5 * V_6 ,
struct V_12 * V_13 )
{
unsigned int V_14 , V_15 ;
if ( ! V_6 || ! ( V_6 -> V_16 & V_17 ) )
return true ;
if ( ! F_4 ( V_7 , & V_6 -> V_8 ) )
return true ;
if ( V_13 -> V_4 . V_14 == 1 )
return true ;
V_15 = F_13 ( & V_6 -> V_2 -> V_9 ) ;
if ( ! V_15 )
return true ;
V_14 = F_14 ( ( V_13 -> V_4 . V_14 + V_15 - 1 ) / V_15 , 4U ) ;
return F_13 ( & V_6 -> V_18 ) < V_14 ;
}
static int F_15 ( struct V_19 * V_20 ,
struct V_12 * V_13 )
{
if ( ! ( V_20 -> V_16 & V_21 ) &&
! F_12 ( V_20 -> V_6 , V_13 ) )
return - 1 ;
if ( V_20 -> V_22 )
return F_16 ( V_13 , V_20 -> V_22 ) ;
else
return F_17 ( V_13 ) ;
}
unsigned int F_18 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_19 ( V_20 ) ;
struct V_12 * V_13 ;
struct V_23 * V_24 ;
F_20 ( V_25 ) ;
unsigned int V_26 ;
bool V_27 ;
int V_28 ;
if ( V_20 -> V_16 & V_29 ) {
if ( F_21 ( ! V_2 -> V_30 ) ) {
F_22 ( 1 ) ;
return V_31 ;
}
V_13 = & V_2 -> V_11 ;
V_26 = 0 ;
} else {
V_13 = & V_2 -> V_3 ;
V_26 = V_2 -> V_30 ;
}
V_28 = F_15 ( V_20 , V_13 ) ;
if ( V_28 != - 1 )
goto V_32;
if ( V_20 -> V_16 & V_33 )
return V_31 ;
V_24 = F_23 ( V_13 , V_20 -> V_6 ) ;
V_27 = V_20 -> V_34 == NULL ;
do {
F_24 ( & V_24 -> V_25 , & V_25 , V_35 ) ;
V_28 = F_15 ( V_20 , V_13 ) ;
if ( V_28 != - 1 )
break;
F_25 ( V_20 -> V_6 , false ) ;
V_28 = F_15 ( V_20 , V_13 ) ;
if ( V_28 != - 1 )
break;
if ( V_20 -> V_34 )
F_26 ( V_20 -> V_34 ) ;
F_27 () ;
V_20 -> V_34 = F_28 ( V_20 -> V_36 ) ;
V_20 -> V_6 = F_29 ( V_20 -> V_36 , V_20 -> V_34 -> V_37 ) ;
V_2 = F_19 ( V_20 ) ;
if ( V_20 -> V_16 & V_29 )
V_13 = & V_2 -> V_11 ;
else
V_13 = & V_2 -> V_3 ;
F_30 ( & V_24 -> V_25 , & V_25 ) ;
V_24 = F_23 ( V_13 , V_20 -> V_6 ) ;
} while ( 1 );
if ( V_27 && V_20 -> V_34 )
F_26 ( V_20 -> V_34 ) ;
F_30 ( & V_24 -> V_25 , & V_25 ) ;
V_32:
return V_28 + V_26 ;
}
void F_31 ( struct V_5 * V_6 , struct V_1 * V_2 ,
struct V_38 * V_34 , unsigned int V_28 )
{
if ( ! F_32 ( V_2 , V_28 ) ) {
const int V_39 = V_28 - V_2 -> V_30 ;
F_33 ( V_39 >= V_2 -> V_40 ) ;
F_34 ( & V_2 -> V_3 , V_39 , V_34 -> V_37 ) ;
} else {
F_33 ( V_28 >= V_2 -> V_30 ) ;
F_34 ( & V_2 -> V_11 , V_28 , V_34 -> V_37 ) ;
}
}
static bool F_35 ( struct V_41 * V_42 , unsigned int V_43 , void * V_20 )
{
struct V_44 * V_45 = V_20 ;
struct V_5 * V_6 = V_45 -> V_6 ;
struct V_1 * V_2 = V_6 -> V_2 ;
bool V_46 = V_45 -> V_46 ;
struct V_47 * V_48 ;
if ( ! V_46 )
V_43 += V_2 -> V_30 ;
V_48 = V_2 -> V_49 [ V_43 ] ;
if ( V_48 && V_48 -> V_36 == V_6 -> V_50 )
V_45 -> V_51 ( V_6 , V_48 , V_45 -> V_20 , V_46 ) ;
return true ;
}
static void F_36 ( struct V_5 * V_6 , struct V_12 * V_13 ,
T_1 * V_51 , void * V_20 , bool V_46 )
{
struct V_44 V_45 = {
. V_6 = V_6 ,
. V_51 = V_51 ,
. V_20 = V_20 ,
. V_46 = V_46 ,
} ;
F_37 ( & V_13 -> V_4 , F_35 , & V_45 ) ;
}
static bool F_38 ( struct V_41 * V_42 , unsigned int V_43 , void * V_20 )
{
struct V_52 * V_45 = V_20 ;
struct V_1 * V_2 = V_45 -> V_2 ;
bool V_46 = V_45 -> V_46 ;
struct V_47 * V_48 ;
if ( ! V_46 )
V_43 += V_2 -> V_30 ;
V_48 = V_2 -> V_49 [ V_43 ] ;
if ( V_48 )
V_45 -> V_51 ( V_48 , V_45 -> V_20 , V_46 ) ;
return true ;
}
static void F_39 ( struct V_1 * V_2 , struct V_12 * V_13 ,
T_2 * V_51 , void * V_20 , bool V_46 )
{
struct V_52 V_45 = {
. V_2 = V_2 ,
. V_51 = V_51 ,
. V_20 = V_20 ,
. V_46 = V_46 ,
} ;
if ( V_2 -> V_49 )
F_37 ( & V_13 -> V_4 , F_38 , & V_45 ) ;
}
static void F_40 ( struct V_1 * V_2 ,
T_2 * V_51 , void * V_53 )
{
if ( V_2 -> V_30 )
F_39 ( V_2 , & V_2 -> V_11 , V_51 , V_53 , true ) ;
F_39 ( V_2 , & V_2 -> V_3 , V_51 , V_53 , false ) ;
}
void F_41 ( struct V_54 * V_55 ,
T_2 * V_51 , void * V_53 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_55 -> V_57 ; V_56 ++ ) {
if ( V_55 -> V_2 && V_55 -> V_2 [ V_56 ] )
F_40 ( V_55 -> V_2 [ V_56 ] , V_51 , V_53 ) ;
}
}
int F_42 ( struct V_54 * V_58 ,
int (F_43)( void * , struct V_47 * ) )
{
int V_56 , V_59 , V_60 = 0 ;
if ( F_22 ( ! F_43 ) )
goto V_61;
for ( V_56 = 0 ; V_56 < V_58 -> V_57 ; V_56 ++ ) {
struct V_1 * V_2 = V_58 -> V_2 [ V_56 ] ;
if ( ! V_2 )
continue;
for ( V_59 = 0 ; V_59 < V_2 -> V_40 ; V_59 ++ ) {
if ( ! V_2 -> V_62 [ V_59 ] )
continue;
V_60 = F_43 ( V_58 -> V_63 ,
V_2 -> V_62 [ V_59 ] ) ;
if ( V_60 )
goto V_61;
}
}
V_61:
return V_60 ;
}
void F_44 ( struct V_64 * V_36 , T_1 * V_51 ,
void * V_53 )
{
struct V_5 * V_6 ;
int V_56 ;
F_45 (q, hctx, i) {
struct V_1 * V_2 = V_6 -> V_2 ;
if ( ! F_46 ( V_6 ) )
continue;
if ( V_2 -> V_30 )
F_36 ( V_6 , & V_2 -> V_11 , V_51 , V_53 , true ) ;
F_36 ( V_6 , & V_2 -> V_3 , V_51 , V_53 , false ) ;
}
}
static int F_47 ( struct V_12 * V_13 , unsigned int V_14 ,
bool V_65 , int V_66 )
{
return F_48 ( V_13 , V_14 , - 1 , V_65 , V_67 ,
V_66 ) ;
}
static struct V_1 * F_49 ( struct V_1 * V_2 ,
int V_66 , int V_68 )
{
unsigned int V_14 = V_2 -> V_40 - V_2 -> V_30 ;
bool V_65 = V_68 == V_69 ;
if ( F_47 ( & V_2 -> V_3 , V_14 , V_65 , V_66 ) )
goto V_70;
if ( F_47 ( & V_2 -> V_11 , V_2 -> V_30 , V_65 ,
V_66 ) )
goto V_71;
return V_2 ;
V_71:
F_50 ( & V_2 -> V_3 ) ;
V_70:
F_51 ( V_2 ) ;
return NULL ;
}
struct V_1 * F_52 ( unsigned int V_72 ,
unsigned int V_73 ,
int V_66 , int V_68 )
{
struct V_1 * V_2 ;
if ( V_72 > V_74 ) {
F_53 ( L_1 ) ;
return NULL ;
}
V_2 = F_54 ( sizeof( * V_2 ) , V_67 , V_66 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_40 = V_72 ;
V_2 -> V_30 = V_73 ;
return F_49 ( V_2 , V_66 , V_68 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
F_50 ( & V_2 -> V_3 ) ;
F_50 ( & V_2 -> V_11 ) ;
F_51 ( V_2 ) ;
}
int F_56 ( struct V_5 * V_6 ,
struct V_1 * * V_75 , unsigned int V_76 ,
bool V_77 )
{
struct V_1 * V_2 = * V_75 ;
if ( V_76 <= V_2 -> V_30 )
return - V_78 ;
V_76 -= V_2 -> V_30 ;
if ( V_76 > V_2 -> V_40 ) {
struct V_54 * V_58 = V_6 -> V_50 -> V_79 ;
struct V_1 * V_80 ;
bool V_60 ;
if ( ! V_77 )
return - V_78 ;
if ( V_76 > 16 * V_81 )
return - V_78 ;
V_80 = F_57 ( V_58 , V_6 -> V_82 , V_76 , 0 ) ;
if ( ! V_80 )
return - V_83 ;
V_60 = F_58 ( V_58 , V_80 , V_6 -> V_82 , V_76 ) ;
if ( V_60 ) {
F_59 ( V_80 ) ;
return - V_83 ;
}
F_60 ( V_58 , * V_75 , V_6 -> V_82 ) ;
F_59 ( * V_75 ) ;
* V_75 = V_80 ;
} else {
F_61 ( & V_2 -> V_3 , V_76 ) ;
}
return 0 ;
}
T_3 F_62 ( struct V_47 * V_48 )
{
struct V_64 * V_36 = V_48 -> V_36 ;
struct V_5 * V_6 ;
int V_84 = 0 ;
if ( V_36 -> V_85 ) {
V_6 = F_29 ( V_36 , V_48 -> V_86 -> V_37 ) ;
V_84 = V_6 -> V_82 ;
}
return ( V_84 << V_87 ) |
( V_48 -> V_28 & V_88 ) ;
}
