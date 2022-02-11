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
static int F_15 ( struct V_5 * V_6 , struct V_12 * V_13 )
{
if ( ! F_12 ( V_6 , V_13 ) )
return - 1 ;
return F_16 ( V_13 ) ;
}
static int F_17 ( struct V_19 * V_20 , struct V_12 * V_13 ,
struct V_5 * V_6 , struct V_1 * V_2 )
{
struct V_21 * V_22 ;
F_18 ( V_23 ) ;
int V_24 ;
V_24 = F_15 ( V_6 , V_13 ) ;
if ( V_24 != - 1 )
return V_24 ;
if ( V_20 -> V_16 & V_25 )
return - 1 ;
V_22 = F_19 ( V_13 , V_6 ) ;
do {
F_20 ( & V_22 -> V_23 , & V_23 , V_26 ) ;
V_24 = F_15 ( V_6 , V_13 ) ;
if ( V_24 != - 1 )
break;
if ( V_6 )
F_21 ( V_6 , false ) ;
V_24 = F_15 ( V_6 , V_13 ) ;
if ( V_24 != - 1 )
break;
F_22 ( V_20 -> V_27 ) ;
F_23 () ;
V_20 -> V_27 = F_24 ( V_20 -> V_28 ) ;
V_20 -> V_6 = F_25 ( V_20 -> V_28 , V_20 -> V_27 -> V_29 ) ;
if ( V_20 -> V_16 & V_30 ) {
V_13 = & V_20 -> V_6 -> V_2 -> V_11 ;
} else {
V_6 = V_20 -> V_6 ;
V_13 = & V_6 -> V_2 -> V_3 ;
}
F_26 ( & V_22 -> V_23 , & V_23 ) ;
V_22 = F_19 ( V_13 , V_6 ) ;
} while ( 1 );
F_26 ( & V_22 -> V_23 , & V_23 ) ;
return V_24 ;
}
static unsigned int F_27 ( struct V_19 * V_20 )
{
int V_24 ;
V_24 = F_17 ( V_20 , & V_20 -> V_6 -> V_2 -> V_3 , V_20 -> V_6 ,
V_20 -> V_6 -> V_2 ) ;
if ( V_24 >= 0 )
return V_24 + V_20 -> V_6 -> V_2 -> V_31 ;
return V_32 ;
}
static unsigned int F_28 ( struct V_19 * V_20 )
{
int V_24 ;
if ( F_29 ( ! V_20 -> V_6 -> V_2 -> V_31 ) ) {
F_30 ( 1 ) ;
return V_32 ;
}
V_24 = F_17 ( V_20 , & V_20 -> V_6 -> V_2 -> V_11 , NULL ,
V_20 -> V_6 -> V_2 ) ;
if ( V_24 < 0 )
return V_32 ;
return V_24 ;
}
unsigned int F_31 ( struct V_19 * V_20 )
{
if ( V_20 -> V_16 & V_30 )
return F_28 ( V_20 ) ;
return F_27 ( V_20 ) ;
}
void F_32 ( struct V_5 * V_6 , struct V_33 * V_27 ,
unsigned int V_24 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
if ( V_24 >= V_2 -> V_31 ) {
const int V_34 = V_24 - V_2 -> V_31 ;
F_33 ( V_34 >= V_2 -> V_35 ) ;
F_34 ( & V_2 -> V_3 , V_34 , V_27 -> V_29 ) ;
} else {
F_33 ( V_24 >= V_2 -> V_31 ) ;
F_34 ( & V_2 -> V_11 , V_24 , V_27 -> V_29 ) ;
}
}
static bool F_35 ( struct V_36 * V_37 , unsigned int V_38 , void * V_20 )
{
struct V_39 * V_40 = V_20 ;
struct V_5 * V_6 = V_40 -> V_6 ;
struct V_1 * V_2 = V_6 -> V_2 ;
bool V_41 = V_40 -> V_41 ;
struct V_42 * V_43 ;
if ( ! V_41 )
V_38 += V_2 -> V_31 ;
V_43 = V_2 -> V_44 [ V_38 ] ;
if ( V_43 -> V_28 == V_6 -> V_45 )
V_40 -> V_46 ( V_6 , V_43 , V_40 -> V_20 , V_41 ) ;
return true ;
}
static void F_36 ( struct V_5 * V_6 , struct V_12 * V_13 ,
T_1 * V_46 , void * V_20 , bool V_41 )
{
struct V_39 V_40 = {
. V_6 = V_6 ,
. V_46 = V_46 ,
. V_20 = V_20 ,
. V_41 = V_41 ,
} ;
F_37 ( & V_13 -> V_4 , F_35 , & V_40 ) ;
}
static bool F_38 ( struct V_36 * V_37 , unsigned int V_38 , void * V_20 )
{
struct V_47 * V_40 = V_20 ;
struct V_1 * V_2 = V_40 -> V_2 ;
bool V_41 = V_40 -> V_41 ;
struct V_42 * V_43 ;
if ( ! V_41 )
V_38 += V_2 -> V_31 ;
V_43 = V_2 -> V_44 [ V_38 ] ;
V_40 -> V_46 ( V_43 , V_40 -> V_20 , V_41 ) ;
return true ;
}
static void F_39 ( struct V_1 * V_2 , struct V_12 * V_13 ,
T_2 * V_46 , void * V_20 , bool V_41 )
{
struct V_47 V_40 = {
. V_2 = V_2 ,
. V_46 = V_46 ,
. V_20 = V_20 ,
. V_41 = V_41 ,
} ;
if ( V_2 -> V_44 )
F_37 ( & V_13 -> V_4 , F_38 , & V_40 ) ;
}
static void F_40 ( struct V_1 * V_2 ,
T_2 * V_46 , void * V_48 )
{
if ( V_2 -> V_31 )
F_39 ( V_2 , & V_2 -> V_11 , V_46 , V_48 , true ) ;
F_39 ( V_2 , & V_2 -> V_3 , V_46 , V_48 , false ) ;
}
void F_41 ( struct V_49 * V_50 ,
T_2 * V_46 , void * V_48 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_52 ; V_51 ++ ) {
if ( V_50 -> V_2 && V_50 -> V_2 [ V_51 ] )
F_40 ( V_50 -> V_2 [ V_51 ] , V_46 , V_48 ) ;
}
}
int F_42 ( struct V_49 * V_53 )
{
int V_51 , V_54 , V_55 = 0 ;
if ( ! V_53 -> V_56 -> V_57 )
goto V_58;
for ( V_51 = 0 ; V_51 < V_53 -> V_52 ; V_51 ++ ) {
struct V_1 * V_2 = V_53 -> V_2 [ V_51 ] ;
for ( V_54 = 0 ; V_54 < V_2 -> V_35 ; V_54 ++ ) {
if ( ! V_2 -> V_44 [ V_54 ] )
continue;
V_55 = V_53 -> V_56 -> V_57 ( V_53 -> V_59 ,
V_2 -> V_44 [ V_54 ] ) ;
if ( V_55 )
goto V_58;
}
}
V_58:
return V_55 ;
}
void F_43 ( struct V_60 * V_28 , T_1 * V_46 ,
void * V_48 )
{
struct V_5 * V_6 ;
int V_51 ;
F_44 (q, hctx, i) {
struct V_1 * V_2 = V_6 -> V_2 ;
if ( ! F_45 ( V_6 ) )
continue;
if ( V_2 -> V_31 )
F_36 ( V_6 , & V_2 -> V_11 , V_46 , V_48 , true ) ;
F_36 ( V_6 , & V_2 -> V_3 , V_46 , V_48 , false ) ;
}
}
static unsigned int F_46 ( const struct V_12 * V_13 )
{
return V_13 -> V_4 . V_14 - F_47 ( & V_13 -> V_4 ) ;
}
static int F_48 ( struct V_12 * V_13 , unsigned int V_14 ,
bool V_61 , int V_62 )
{
return F_49 ( V_13 , V_14 , - 1 , V_61 , V_63 ,
V_62 ) ;
}
static struct V_1 * F_50 ( struct V_1 * V_2 ,
int V_62 , int V_64 )
{
unsigned int V_14 = V_2 -> V_35 - V_2 -> V_31 ;
bool V_61 = V_64 == V_65 ;
if ( F_48 ( & V_2 -> V_3 , V_14 , V_61 , V_62 ) )
goto V_66;
if ( F_48 ( & V_2 -> V_11 , V_2 -> V_31 , V_61 ,
V_62 ) )
goto V_67;
return V_2 ;
V_67:
F_51 ( & V_2 -> V_3 ) ;
V_66:
F_52 ( V_2 ) ;
return NULL ;
}
struct V_1 * F_53 ( unsigned int V_68 ,
unsigned int V_69 ,
int V_62 , int V_64 )
{
struct V_1 * V_2 ;
if ( V_68 > V_70 ) {
F_54 ( L_1 ) ;
return NULL ;
}
V_2 = F_55 ( sizeof( * V_2 ) , V_63 , V_62 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_35 = V_68 ;
V_2 -> V_31 = V_69 ;
return F_50 ( V_2 , V_62 , V_64 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
F_51 ( & V_2 -> V_3 ) ;
F_51 ( & V_2 -> V_11 ) ;
F_52 ( V_2 ) ;
}
int F_57 ( struct V_1 * V_2 , unsigned int V_71 )
{
V_71 -= V_2 -> V_31 ;
if ( V_71 > V_2 -> V_35 )
return - V_72 ;
F_58 ( & V_2 -> V_3 , V_71 ) ;
F_7 ( V_2 , false ) ;
return 0 ;
}
T_3 F_59 ( struct V_42 * V_43 )
{
struct V_60 * V_28 = V_43 -> V_28 ;
struct V_5 * V_6 ;
int V_73 = 0 ;
if ( V_28 -> V_74 ) {
V_6 = F_25 ( V_28 , V_43 -> V_75 -> V_29 ) ;
V_73 = V_6 -> V_76 ;
}
return ( V_73 << V_77 ) |
( V_43 -> V_24 & V_78 ) ;
}
T_4 F_60 ( struct V_1 * V_2 , char * V_79 )
{
char * V_80 = V_79 ;
unsigned int free , V_81 ;
if ( ! V_2 )
return 0 ;
V_79 += sprintf ( V_79 , L_2
L_3 ,
V_2 -> V_35 , V_2 -> V_31 ,
1U << V_2 -> V_3 . V_4 . V_82 ) ;
free = F_46 ( & V_2 -> V_3 ) ;
V_81 = F_46 ( & V_2 -> V_11 ) ;
V_79 += sprintf ( V_79 , L_4 , free , V_81 ) ;
V_79 += sprintf ( V_79 , L_5 , F_13 ( & V_2 -> V_9 ) ) ;
return V_79 - V_80 ;
}
