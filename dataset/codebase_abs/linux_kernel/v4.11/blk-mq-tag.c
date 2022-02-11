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
return F_16 ( V_13 ) ;
}
unsigned int F_17 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_18 ( V_20 ) ;
struct V_12 * V_13 ;
struct V_22 * V_23 ;
F_19 ( V_24 ) ;
unsigned int V_25 ;
bool V_26 ;
int V_27 ;
if ( V_20 -> V_16 & V_28 ) {
if ( F_20 ( ! V_2 -> V_29 ) ) {
F_21 ( 1 ) ;
return V_30 ;
}
V_13 = & V_2 -> V_11 ;
V_25 = 0 ;
} else {
V_13 = & V_2 -> V_3 ;
V_25 = V_2 -> V_29 ;
}
V_27 = F_15 ( V_20 , V_13 ) ;
if ( V_27 != - 1 )
goto V_31;
if ( V_20 -> V_16 & V_32 )
return V_30 ;
V_23 = F_22 ( V_13 , V_20 -> V_6 ) ;
V_26 = V_20 -> V_33 == NULL ;
do {
F_23 ( & V_23 -> V_24 , & V_24 , V_34 ) ;
V_27 = F_15 ( V_20 , V_13 ) ;
if ( V_27 != - 1 )
break;
F_24 ( V_20 -> V_6 , false ) ;
V_27 = F_15 ( V_20 , V_13 ) ;
if ( V_27 != - 1 )
break;
if ( V_20 -> V_33 )
F_25 ( V_20 -> V_33 ) ;
F_26 () ;
V_20 -> V_33 = F_27 ( V_20 -> V_35 ) ;
V_20 -> V_6 = F_28 ( V_20 -> V_35 , V_20 -> V_33 -> V_36 ) ;
V_2 = F_18 ( V_20 ) ;
if ( V_20 -> V_16 & V_28 )
V_13 = & V_2 -> V_11 ;
else
V_13 = & V_2 -> V_3 ;
F_29 ( & V_23 -> V_24 , & V_24 ) ;
V_23 = F_22 ( V_13 , V_20 -> V_6 ) ;
} while ( 1 );
if ( V_26 && V_20 -> V_33 )
F_25 ( V_20 -> V_33 ) ;
F_29 ( & V_23 -> V_24 , & V_24 ) ;
V_31:
return V_27 + V_25 ;
}
void F_30 ( struct V_5 * V_6 , struct V_1 * V_2 ,
struct V_37 * V_33 , unsigned int V_27 )
{
if ( ! F_31 ( V_2 , V_27 ) ) {
const int V_38 = V_27 - V_2 -> V_29 ;
F_32 ( V_38 >= V_2 -> V_39 ) ;
F_33 ( & V_2 -> V_3 , V_38 , V_33 -> V_36 ) ;
} else {
F_32 ( V_27 >= V_2 -> V_29 ) ;
F_33 ( & V_2 -> V_11 , V_27 , V_33 -> V_36 ) ;
}
}
static bool F_34 ( struct V_40 * V_41 , unsigned int V_42 , void * V_20 )
{
struct V_43 * V_44 = V_20 ;
struct V_5 * V_6 = V_44 -> V_6 ;
struct V_1 * V_2 = V_6 -> V_2 ;
bool V_45 = V_44 -> V_45 ;
struct V_46 * V_47 ;
if ( ! V_45 )
V_42 += V_2 -> V_29 ;
V_47 = V_2 -> V_48 [ V_42 ] ;
if ( V_47 -> V_35 == V_6 -> V_49 )
V_44 -> V_50 ( V_6 , V_47 , V_44 -> V_20 , V_45 ) ;
return true ;
}
static void F_35 ( struct V_5 * V_6 , struct V_12 * V_13 ,
T_1 * V_50 , void * V_20 , bool V_45 )
{
struct V_43 V_44 = {
. V_6 = V_6 ,
. V_50 = V_50 ,
. V_20 = V_20 ,
. V_45 = V_45 ,
} ;
F_36 ( & V_13 -> V_4 , F_34 , & V_44 ) ;
}
static bool F_37 ( struct V_40 * V_41 , unsigned int V_42 , void * V_20 )
{
struct V_51 * V_44 = V_20 ;
struct V_1 * V_2 = V_44 -> V_2 ;
bool V_45 = V_44 -> V_45 ;
struct V_46 * V_47 ;
if ( ! V_45 )
V_42 += V_2 -> V_29 ;
V_47 = V_2 -> V_48 [ V_42 ] ;
V_44 -> V_50 ( V_47 , V_44 -> V_20 , V_45 ) ;
return true ;
}
static void F_38 ( struct V_1 * V_2 , struct V_12 * V_13 ,
T_2 * V_50 , void * V_20 , bool V_45 )
{
struct V_51 V_44 = {
. V_2 = V_2 ,
. V_50 = V_50 ,
. V_20 = V_20 ,
. V_45 = V_45 ,
} ;
if ( V_2 -> V_48 )
F_36 ( & V_13 -> V_4 , F_37 , & V_44 ) ;
}
static void F_39 ( struct V_1 * V_2 ,
T_2 * V_50 , void * V_52 )
{
if ( V_2 -> V_29 )
F_38 ( V_2 , & V_2 -> V_11 , V_50 , V_52 , true ) ;
F_38 ( V_2 , & V_2 -> V_3 , V_50 , V_52 , false ) ;
}
void F_40 ( struct V_53 * V_54 ,
T_2 * V_50 , void * V_52 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_54 -> V_56 ; V_55 ++ ) {
if ( V_54 -> V_2 && V_54 -> V_2 [ V_55 ] )
F_39 ( V_54 -> V_2 [ V_55 ] , V_50 , V_52 ) ;
}
}
int F_41 ( struct V_53 * V_57 )
{
int V_55 , V_58 , V_59 = 0 ;
if ( ! V_57 -> V_60 -> V_61 )
goto V_62;
for ( V_55 = 0 ; V_55 < V_57 -> V_56 ; V_55 ++ ) {
struct V_1 * V_2 = V_57 -> V_2 [ V_55 ] ;
if ( ! V_2 )
continue;
for ( V_58 = 0 ; V_58 < V_2 -> V_39 ; V_58 ++ ) {
if ( ! V_2 -> V_63 [ V_58 ] )
continue;
V_59 = V_57 -> V_60 -> V_61 ( V_57 -> V_64 ,
V_2 -> V_63 [ V_58 ] ) ;
if ( V_59 )
goto V_62;
}
}
V_62:
return V_59 ;
}
void F_42 ( struct V_65 * V_35 , T_1 * V_50 ,
void * V_52 )
{
struct V_5 * V_6 ;
int V_55 ;
F_43 (q, hctx, i) {
struct V_1 * V_2 = V_6 -> V_2 ;
if ( ! F_44 ( V_6 ) )
continue;
if ( V_2 -> V_29 )
F_35 ( V_6 , & V_2 -> V_11 , V_50 , V_52 , true ) ;
F_35 ( V_6 , & V_2 -> V_3 , V_50 , V_52 , false ) ;
}
}
static int F_45 ( struct V_12 * V_13 , unsigned int V_14 ,
bool V_66 , int V_67 )
{
return F_46 ( V_13 , V_14 , - 1 , V_66 , V_68 ,
V_67 ) ;
}
static struct V_1 * F_47 ( struct V_1 * V_2 ,
int V_67 , int V_69 )
{
unsigned int V_14 = V_2 -> V_39 - V_2 -> V_29 ;
bool V_66 = V_69 == V_70 ;
if ( F_45 ( & V_2 -> V_3 , V_14 , V_66 , V_67 ) )
goto V_71;
if ( F_45 ( & V_2 -> V_11 , V_2 -> V_29 , V_66 ,
V_67 ) )
goto V_72;
return V_2 ;
V_72:
F_48 ( & V_2 -> V_3 ) ;
V_71:
F_49 ( V_2 ) ;
return NULL ;
}
struct V_1 * F_50 ( unsigned int V_73 ,
unsigned int V_74 ,
int V_67 , int V_69 )
{
struct V_1 * V_2 ;
if ( V_73 > V_75 ) {
F_51 ( L_1 ) ;
return NULL ;
}
V_2 = F_52 ( sizeof( * V_2 ) , V_68 , V_67 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_39 = V_73 ;
V_2 -> V_29 = V_74 ;
return F_47 ( V_2 , V_67 , V_69 ) ;
}
void F_53 ( struct V_1 * V_2 )
{
F_48 ( & V_2 -> V_3 ) ;
F_48 ( & V_2 -> V_11 ) ;
F_49 ( V_2 ) ;
}
int F_54 ( struct V_5 * V_6 ,
struct V_1 * * V_76 , unsigned int V_77 ,
bool V_78 )
{
struct V_1 * V_2 = * V_76 ;
if ( V_77 <= V_2 -> V_29 )
return - V_79 ;
V_77 -= V_2 -> V_29 ;
if ( V_77 > V_2 -> V_39 ) {
struct V_53 * V_57 = V_6 -> V_49 -> V_80 ;
struct V_1 * V_81 ;
bool V_59 ;
if ( ! V_78 )
return - V_79 ;
if ( V_77 > 16 * V_82 )
return - V_79 ;
V_81 = F_55 ( V_57 , V_6 -> V_83 , V_77 , 0 ) ;
if ( ! V_81 )
return - V_84 ;
V_59 = F_56 ( V_57 , V_81 , V_6 -> V_83 , V_77 ) ;
if ( V_59 ) {
F_57 ( V_81 ) ;
return - V_84 ;
}
F_58 ( V_57 , * V_76 , V_6 -> V_83 ) ;
F_57 ( * V_76 ) ;
* V_76 = V_81 ;
} else {
F_59 ( & V_2 -> V_3 , V_77 ) ;
}
return 0 ;
}
T_3 F_60 ( struct V_46 * V_47 )
{
struct V_65 * V_35 = V_47 -> V_35 ;
struct V_5 * V_6 ;
int V_85 = 0 ;
if ( V_35 -> V_86 ) {
V_6 = F_28 ( V_35 , V_47 -> V_87 -> V_36 ) ;
V_85 = V_6 -> V_83 ;
}
return ( V_85 << V_88 ) |
( V_47 -> V_27 & V_89 ) ;
}
