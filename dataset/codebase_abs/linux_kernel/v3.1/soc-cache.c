static bool F_1 ( void * V_1 , unsigned int V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
switch ( V_4 ) {
case 1 : {
T_1 * V_5 = V_1 ;
if ( V_5 [ V_2 ] == V_3 )
return true ;
V_5 [ V_2 ] = V_3 ;
break;
}
case 2 : {
T_2 * V_5 = V_1 ;
if ( V_5 [ V_2 ] == V_3 )
return true ;
V_5 [ V_2 ] = V_3 ;
break;
}
default:
F_2 () ;
}
return false ;
}
static unsigned int F_3 ( const void * V_1 , unsigned int V_2 ,
unsigned int V_4 )
{
if ( ! V_1 )
return - 1 ;
switch ( V_4 ) {
case 1 : {
const T_1 * V_5 = V_1 ;
return V_5 [ V_2 ] ;
}
case 2 : {
const T_2 * V_5 = V_1 ;
return V_5 [ V_2 ] ;
}
default:
F_2 () ;
}
return - 1 ;
}
static inline void F_4 (
struct V_6 * V_7 ,
unsigned int * V_1 , unsigned int * V_8 )
{
* V_1 = V_7 -> V_9 ;
* V_8 = V_7 -> V_9 + V_7 -> V_10 - 1 ;
}
static unsigned int F_5 (
struct V_6 * V_7 , unsigned int V_2 )
{
unsigned int V_3 ;
switch ( V_7 -> V_4 ) {
case 1 : {
T_1 * V_11 = V_7 -> V_12 ;
V_3 = V_11 [ V_2 ] ;
return V_3 ;
}
case 2 : {
T_2 * V_11 = V_7 -> V_12 ;
V_3 = V_11 [ V_2 ] ;
return V_3 ;
}
default:
F_2 () ;
break;
}
return - 1 ;
}
static void F_6 ( struct V_6 * V_7 ,
unsigned int V_2 , unsigned int V_3 )
{
switch ( V_7 -> V_4 ) {
case 1 : {
T_1 * V_11 = V_7 -> V_12 ;
V_11 [ V_2 ] = V_3 ;
break;
}
case 2 : {
T_2 * V_11 = V_7 -> V_12 ;
V_11 [ V_2 ] = V_3 ;
break;
}
default:
F_2 () ;
break;
}
}
static struct V_6 * F_7 (
struct V_13 * V_14 , unsigned int V_15 )
{
struct V_16 * V_17 ;
struct V_6 * V_7 ;
unsigned int V_9 , V_18 ;
V_17 = V_14 -> V_16 ;
while ( V_17 ) {
V_7 = F_8 ( V_17 , struct V_6 , V_17 ) ;
F_4 ( V_7 , & V_9 , & V_18 ) ;
if ( V_15 >= V_9 && V_15 <= V_18 )
return V_7 ;
else if ( V_15 > V_18 )
V_17 = V_17 -> V_19 ;
else if ( V_15 < V_9 )
V_17 = V_17 -> V_20 ;
}
return NULL ;
}
static int F_9 ( struct V_13 * V_14 ,
struct V_6 * V_7 )
{
struct V_16 * * V_21 , * V_22 ;
struct V_6 * V_23 ;
unsigned int V_24 , V_25 ;
unsigned int V_9 ;
V_22 = NULL ;
V_21 = & V_14 -> V_16 ;
while ( * V_21 ) {
V_23 = F_8 ( * V_21 , struct V_6 ,
V_17 ) ;
F_4 ( V_23 , & V_24 ,
& V_25 ) ;
V_9 = V_7 -> V_9 ;
V_22 = * V_21 ;
if ( V_9 >= V_24 &&
V_9 <= V_25 )
return 0 ;
else if ( V_9 > V_25 )
V_21 = & ( ( * V_21 ) -> V_19 ) ;
else if ( V_9 < V_24 )
V_21 = & ( ( * V_21 ) -> V_20 ) ;
}
F_10 ( & V_7 -> V_17 , V_22 , V_21 ) ;
F_11 ( & V_7 -> V_17 , V_14 ) ;
return 1 ;
}
static int F_12 ( struct V_26 * V_27 )
{
struct V_28 * V_29 ;
struct V_16 * V_17 ;
struct V_6 * V_7 ;
unsigned int V_30 ;
unsigned int V_3 , V_31 ;
int V_32 ;
int V_33 ;
V_29 = V_27 -> V_34 ;
for ( V_17 = F_13 ( & V_29 -> V_14 ) ; V_17 ; V_17 = F_14 ( V_17 ) ) {
V_7 = F_15 ( V_17 , struct V_6 , V_17 ) ;
for ( V_33 = 0 ; V_33 < V_7 -> V_10 ; ++ V_33 ) {
V_30 = V_7 -> V_9 + V_33 ;
V_3 = F_5 ( V_7 , V_33 ) ;
V_31 = F_3 ( V_27 -> V_35 , V_33 ,
V_7 -> V_4 ) ;
if ( V_3 == V_31 )
continue;
F_16 ( ! F_17 ( V_27 , V_30 ) ) ;
V_27 -> V_36 = 1 ;
V_32 = F_18 ( V_27 , V_30 , V_3 ) ;
V_27 -> V_36 = 0 ;
if ( V_32 )
return V_32 ;
F_19 ( V_27 -> V_37 , L_1 ,
V_30 , V_3 ) ;
}
}
return 0 ;
}
static int F_20 ( struct V_6 * V_7 ,
unsigned int V_38 , unsigned int V_15 ,
unsigned int V_39 )
{
T_1 * V_40 ;
V_40 = F_21 ( V_7 -> V_12 ,
( V_7 -> V_10 + 1 ) * V_7 -> V_4 , V_41 ) ;
if ( ! V_40 )
return - V_42 ;
memmove ( V_40 + ( V_38 + 1 ) * V_7 -> V_4 ,
V_40 + V_38 * V_7 -> V_4 ,
( V_7 -> V_10 - V_38 ) * V_7 -> V_4 ) ;
V_7 -> V_12 = V_40 ;
V_7 -> V_10 ++ ;
if ( ! V_38 )
V_7 -> V_9 = V_15 ;
F_6 ( V_7 , V_38 , V_39 ) ;
return 0 ;
}
static int F_22 ( struct V_26 * V_27 ,
unsigned int V_15 , unsigned int V_39 )
{
struct V_28 * V_29 ;
struct V_6 * V_7 , * V_23 ;
struct V_16 * V_17 ;
unsigned int V_3 ;
unsigned int V_43 ;
unsigned int V_9 , V_18 ;
unsigned int V_38 ;
int V_33 ;
int V_32 ;
V_29 = V_27 -> V_34 ;
V_7 = V_29 -> V_44 ;
if ( V_7 ) {
F_4 ( V_7 , & V_9 , & V_18 ) ;
if ( V_15 >= V_9 && V_15 <= V_18 ) {
V_43 = V_15 - V_9 ;
V_3 = F_5 ( V_7 , V_43 ) ;
if ( V_3 == V_39 )
return 0 ;
F_6 ( V_7 , V_43 , V_39 ) ;
return 0 ;
}
}
V_7 = F_7 ( & V_29 -> V_14 , V_15 ) ;
if ( V_7 ) {
V_43 = V_15 - V_7 -> V_9 ;
V_3 = F_5 ( V_7 , V_43 ) ;
if ( V_3 == V_39 )
return 0 ;
F_6 ( V_7 , V_43 , V_39 ) ;
V_29 -> V_44 = V_7 ;
} else {
if ( ! V_39 )
return 0 ;
for ( V_17 = F_13 ( & V_29 -> V_14 ) ; V_17 ;
V_17 = F_14 ( V_17 ) ) {
V_23 = F_15 ( V_17 , struct V_6 , V_17 ) ;
for ( V_33 = 0 ; V_33 < V_23 -> V_10 ; ++ V_33 ) {
V_43 = V_23 -> V_9 + V_33 ;
if ( abs ( V_43 - V_15 ) != 1 )
continue;
if ( V_43 + 1 == V_15 )
V_38 = V_33 + 1 ;
else
V_38 = V_33 ;
V_32 = F_20 ( V_23 , V_38 ,
V_15 , V_39 ) ;
if ( V_32 )
return V_32 ;
V_29 -> V_44 = V_23 ;
return 0 ;
}
}
V_7 = F_23 ( sizeof *V_7 , V_41 ) ;
if ( ! V_7 )
return - V_42 ;
V_7 -> V_10 = 1 ;
V_7 -> V_9 = V_15 ;
V_7 -> V_4 = V_27 -> V_45 -> V_46 ;
V_7 -> V_12 = F_24 ( V_7 -> V_10 * V_7 -> V_4 ,
V_41 ) ;
if ( ! V_7 -> V_12 ) {
F_25 ( V_7 ) ;
return - V_42 ;
}
F_6 ( V_7 , 0 , V_39 ) ;
F_9 ( & V_29 -> V_14 , V_7 ) ;
V_29 -> V_44 = V_7 ;
}
return 0 ;
}
static int F_26 ( struct V_26 * V_27 ,
unsigned int V_15 , unsigned int * V_39 )
{
struct V_28 * V_29 ;
struct V_6 * V_7 ;
unsigned int V_9 , V_18 ;
unsigned int V_43 ;
V_29 = V_27 -> V_34 ;
V_7 = V_29 -> V_44 ;
if ( V_7 ) {
F_4 ( V_7 , & V_9 , & V_18 ) ;
if ( V_15 >= V_9 && V_15 <= V_18 ) {
V_43 = V_15 - V_9 ;
* V_39 = F_5 ( V_7 , V_43 ) ;
return 0 ;
}
}
V_7 = F_7 ( & V_29 -> V_14 , V_15 ) ;
if ( V_7 ) {
V_43 = V_15 - V_7 -> V_9 ;
* V_39 = F_5 ( V_7 , V_43 ) ;
V_29 -> V_44 = V_7 ;
} else {
* V_39 = 0 ;
}
return 0 ;
}
static int F_27 ( struct V_26 * V_27 )
{
struct V_16 * V_47 ;
struct V_28 * V_29 ;
struct V_6 * V_48 ;
V_29 = V_27 -> V_34 ;
if ( ! V_29 )
return 0 ;
V_47 = F_13 ( & V_29 -> V_14 ) ;
while ( V_47 ) {
V_48 = F_15 ( V_47 , struct V_6 , V_17 ) ;
V_47 = F_14 ( & V_48 -> V_17 ) ;
F_28 ( & V_48 -> V_17 , & V_29 -> V_14 ) ;
F_25 ( V_48 -> V_12 ) ;
F_25 ( V_48 ) ;
}
F_25 ( V_27 -> V_34 ) ;
V_27 -> V_34 = NULL ;
return 0 ;
}
static int F_29 ( struct V_26 * V_27 )
{
struct V_28 * V_29 ;
unsigned int V_4 ;
unsigned int V_3 ;
int V_33 ;
int V_32 ;
V_27 -> V_34 = F_24 ( sizeof *V_29 , V_41 ) ;
if ( ! V_27 -> V_34 )
return - V_42 ;
V_29 = V_27 -> V_34 ;
V_29 -> V_14 = V_49 ;
V_29 -> V_44 = NULL ;
if ( ! V_27 -> V_35 )
return 0 ;
V_4 = V_27 -> V_45 -> V_46 ;
for ( V_33 = 0 ; V_33 < V_27 -> V_45 -> V_50 ; ++ V_33 ) {
V_3 = F_3 ( V_27 -> V_35 , V_33 ,
V_4 ) ;
if ( ! V_3 )
continue;
V_32 = F_22 ( V_27 , V_33 , V_3 ) ;
if ( V_32 )
goto V_51;
}
return 0 ;
V_51:
F_30 ( V_27 ) ;
return V_32 ;
}
static int F_31 ( void )
{
return V_52 ;
}
static int F_32 ( struct V_53 * V_54 )
{
V_54 -> V_55 = F_24 ( V_56 , V_41 ) ;
if ( ! V_54 -> V_55 )
return - V_42 ;
return 0 ;
}
static int F_33 ( struct V_53 * V_54 )
{
T_3 V_57 ;
int V_32 ;
V_32 = F_34 ( V_54 -> V_58 , V_54 -> V_59 ,
V_54 -> V_60 , & V_57 , V_54 -> V_55 ) ;
if ( V_32 != V_61 || V_57 > V_54 -> V_62 )
return - V_63 ;
V_54 -> V_62 = V_57 ;
return 0 ;
}
static int F_35 ( struct V_53 * V_54 )
{
T_3 V_62 ;
int V_32 ;
V_62 = V_54 -> V_62 ;
V_32 = F_36 ( V_54 -> V_58 , V_54 -> V_59 ,
V_54 -> V_60 , & V_62 ) ;
if ( V_32 != V_61 || V_62 != V_54 -> V_62 )
return - V_63 ;
return 0 ;
}
static int F_37 ( struct V_26 * V_27 ,
struct V_53 * V_54 )
{
int V_32 ;
V_54 -> V_62 = F_38 ( V_64 ) ;
V_54 -> V_60 = F_24 ( V_54 -> V_62 , V_41 ) ;
if ( ! V_54 -> V_60 ) {
V_54 -> V_62 = 0 ;
return - V_42 ;
}
V_32 = F_33 ( V_54 ) ;
if ( V_32 < 0 )
return V_32 ;
return 0 ;
}
static int F_39 ( struct V_26 * V_27 ,
struct V_53 * V_54 )
{
int V_32 ;
V_54 -> V_62 = V_54 -> V_65 ;
V_54 -> V_60 = F_24 ( V_54 -> V_62 , V_41 ) ;
if ( ! V_54 -> V_60 ) {
V_54 -> V_62 = 0 ;
return - V_42 ;
}
V_32 = F_35 ( V_54 ) ;
if ( V_32 < 0 )
return V_32 ;
return 0 ;
}
static inline int F_40 ( struct V_26 * V_27 ,
unsigned int V_15 )
{
const struct V_66 * V_67 ;
V_67 = V_27 -> V_45 ;
return ( V_15 * V_67 -> V_46 ) /
F_41 ( V_27 -> V_68 , F_31 () ) ;
}
static inline int F_42 ( struct V_26 * V_27 ,
unsigned int V_15 )
{
const struct V_66 * V_67 ;
V_67 = V_27 -> V_45 ;
return V_15 % ( F_41 ( V_27 -> V_68 , F_31 () ) /
V_67 -> V_46 ) ;
}
static inline int F_43 ( struct V_26 * V_27 )
{
const struct V_66 * V_67 ;
V_67 = V_27 -> V_45 ;
return F_41 ( V_27 -> V_68 , F_31 () ) ;
}
static int F_44 ( struct V_26 * V_27 )
{
struct V_53 * * V_69 ;
unsigned int V_3 ;
int V_33 ;
int V_32 ;
V_69 = V_27 -> V_34 ;
F_45 (i, lzo_blocks[0]->sync_bmp, lzo_blocks[0]->sync_bmp_nbits) {
F_16 ( ! F_17 ( V_27 , V_33 ) ) ;
V_32 = F_46 ( V_27 , V_33 , & V_3 ) ;
if ( V_32 )
return V_32 ;
V_27 -> V_36 = 1 ;
V_32 = F_18 ( V_27 , V_33 , V_3 ) ;
V_27 -> V_36 = 0 ;
if ( V_32 )
return V_32 ;
F_19 ( V_27 -> V_37 , L_1 ,
V_33 , V_3 ) ;
}
return 0 ;
}
static int F_47 ( struct V_26 * V_27 ,
unsigned int V_15 , unsigned int V_39 )
{
struct V_53 * V_70 , * * V_69 ;
int V_32 , V_71 , V_72 ;
T_3 V_73 , V_74 ;
void * V_75 ;
V_71 = F_40 ( V_27 , V_15 ) ;
V_72 = F_42 ( V_27 , V_15 ) ;
V_73 = F_43 ( V_27 ) ;
V_69 = V_27 -> V_34 ;
V_70 = V_69 [ V_71 ] ;
V_75 = V_70 -> V_60 ;
V_74 = V_70 -> V_62 ;
V_70 -> V_58 = V_70 -> V_60 ;
V_70 -> V_59 = V_70 -> V_62 ;
V_32 = F_39 ( V_27 , V_70 ) ;
if ( V_32 < 0 ) {
F_25 ( V_70 -> V_60 ) ;
goto V_76;
}
if ( F_1 ( V_70 -> V_60 , V_72 , V_39 ,
V_27 -> V_45 -> V_46 ) ) {
F_25 ( V_70 -> V_60 ) ;
goto V_76;
}
V_70 -> V_58 = V_70 -> V_60 ;
V_70 -> V_59 = V_70 -> V_62 ;
V_32 = F_37 ( V_27 , V_70 ) ;
if ( V_32 < 0 ) {
F_25 ( V_70 -> V_60 ) ;
F_25 ( V_70 -> V_58 ) ;
goto V_76;
}
F_48 ( V_15 , V_70 -> V_77 ) ;
F_25 ( V_75 ) ;
F_25 ( V_70 -> V_58 ) ;
return 0 ;
V_76:
V_70 -> V_60 = V_75 ;
V_70 -> V_62 = V_74 ;
return V_32 ;
}
static int F_49 ( struct V_26 * V_27 ,
unsigned int V_15 , unsigned int * V_39 )
{
struct V_53 * V_70 , * * V_69 ;
int V_32 , V_71 , V_72 ;
T_3 V_73 , V_74 ;
void * V_75 ;
* V_39 = 0 ;
V_71 = F_40 ( V_27 , V_15 ) ;
V_72 = F_42 ( V_27 , V_15 ) ;
V_73 = F_43 ( V_27 ) ;
V_69 = V_27 -> V_34 ;
V_70 = V_69 [ V_71 ] ;
V_75 = V_70 -> V_60 ;
V_74 = V_70 -> V_62 ;
V_70 -> V_58 = V_70 -> V_60 ;
V_70 -> V_59 = V_70 -> V_62 ;
V_32 = F_39 ( V_27 , V_70 ) ;
if ( V_32 >= 0 )
* V_39 = F_3 ( V_70 -> V_60 , V_72 ,
V_27 -> V_45 -> V_46 ) ;
F_25 ( V_70 -> V_60 ) ;
V_70 -> V_60 = V_75 ;
V_70 -> V_62 = V_74 ;
return 0 ;
}
static int F_50 ( struct V_26 * V_27 )
{
struct V_53 * * V_69 ;
int V_33 , V_78 ;
V_69 = V_27 -> V_34 ;
if ( ! V_69 )
return 0 ;
V_78 = F_31 () ;
if ( V_69 [ 0 ] )
F_25 ( V_69 [ 0 ] -> V_77 ) ;
for ( V_33 = 0 ; V_33 < V_78 ; ++ V_33 ) {
if ( V_69 [ V_33 ] ) {
F_25 ( V_69 [ V_33 ] -> V_55 ) ;
F_25 ( V_69 [ V_33 ] -> V_60 ) ;
}
F_25 ( V_69 [ V_33 ] ) ;
}
F_25 ( V_69 ) ;
V_27 -> V_34 = NULL ;
return 0 ;
}
static int F_51 ( struct V_26 * V_27 )
{
struct V_53 * * V_69 ;
T_3 V_79 ;
const struct V_66 * V_67 ;
int V_32 , V_80 , V_33 , V_73 , V_78 ;
const char * V_11 , * V_81 ;
unsigned long * V_77 ;
V_32 = 0 ;
V_67 = V_27 -> V_45 ;
V_80 = 0 ;
if ( ! V_27 -> V_35 )
V_80 = 1 ;
if ( ! V_27 -> V_35 ) {
V_27 -> V_35 = F_23 ( V_27 -> V_68 , V_41 ) ;
if ( ! V_27 -> V_35 )
return - V_42 ;
}
V_78 = F_31 () ;
V_27 -> V_34 = F_23 ( V_78 * sizeof *V_69 ,
V_41 ) ;
if ( ! V_27 -> V_34 ) {
V_32 = - V_42 ;
goto V_82;
}
V_69 = V_27 -> V_34 ;
V_79 = V_67 -> V_50 ;
V_77 = F_24 ( F_52 ( V_79 ) * sizeof( long ) ,
V_41 ) ;
if ( ! V_77 ) {
V_32 = - V_42 ;
goto V_51;
}
F_53 ( V_77 , V_79 ) ;
for ( V_33 = 0 ; V_33 < V_78 ; ++ V_33 ) {
V_69 [ V_33 ] = F_23 ( sizeof ** V_69 ,
V_41 ) ;
if ( ! V_69 [ V_33 ] ) {
F_25 ( V_77 ) ;
V_32 = - V_42 ;
goto V_51;
}
V_69 [ V_33 ] -> V_77 = V_77 ;
V_69 [ V_33 ] -> V_83 = V_79 ;
V_32 = F_32 ( V_69 [ V_33 ] ) ;
if ( V_32 < 0 )
goto V_51;
}
V_73 = F_43 ( V_27 ) ;
V_11 = V_27 -> V_35 ;
V_81 = V_27 -> V_35 + V_27 -> V_68 ;
for ( V_33 = 0 ; V_33 < V_78 ; ++ V_33 , V_11 += V_73 ) {
V_69 [ V_33 ] -> V_58 = V_11 ;
if ( V_11 + V_73 > V_81 )
V_69 [ V_33 ] -> V_59 = V_81 - V_11 ;
else
V_69 [ V_33 ] -> V_59 = V_73 ;
V_32 = F_37 ( V_27 ,
V_69 [ V_33 ] ) ;
if ( V_32 < 0 )
goto V_51;
V_69 [ V_33 ] -> V_65 =
V_69 [ V_33 ] -> V_59 ;
}
if ( V_80 ) {
F_25 ( V_27 -> V_35 ) ;
V_27 -> V_35 = NULL ;
}
return 0 ;
V_51:
F_30 ( V_27 ) ;
V_82:
if ( V_80 ) {
F_25 ( V_27 -> V_35 ) ;
V_27 -> V_35 = NULL ;
}
return V_32 ;
}
static int F_54 ( struct V_26 * V_27 )
{
int V_33 ;
int V_32 ;
const struct V_66 * V_67 ;
unsigned int V_3 ;
V_67 = V_27 -> V_45 ;
for ( V_33 = 0 ; V_33 < V_67 -> V_50 ; ++ V_33 ) {
V_32 = F_46 ( V_27 , V_33 , & V_3 ) ;
if ( V_32 )
return V_32 ;
if ( V_27 -> V_35 )
if ( F_3 ( V_27 -> V_35 ,
V_33 , V_67 -> V_46 ) == V_3 )
continue;
F_16 ( ! F_17 ( V_27 , V_33 ) ) ;
V_32 = F_18 ( V_27 , V_33 , V_3 ) ;
if ( V_32 )
return V_32 ;
F_19 ( V_27 -> V_37 , L_1 ,
V_33 , V_3 ) ;
}
return 0 ;
}
static int F_55 ( struct V_26 * V_27 ,
unsigned int V_15 , unsigned int V_39 )
{
F_1 ( V_27 -> V_34 , V_15 , V_39 ,
V_27 -> V_45 -> V_46 ) ;
return 0 ;
}
static int F_56 ( struct V_26 * V_27 ,
unsigned int V_15 , unsigned int * V_39 )
{
* V_39 = F_3 ( V_27 -> V_34 , V_15 ,
V_27 -> V_45 -> V_46 ) ;
return 0 ;
}
static int F_57 ( struct V_26 * V_27 )
{
if ( ! V_27 -> V_34 )
return 0 ;
F_25 ( V_27 -> V_34 ) ;
V_27 -> V_34 = NULL ;
return 0 ;
}
static int F_58 ( struct V_26 * V_27 )
{
const struct V_66 * V_67 ;
V_67 = V_27 -> V_45 ;
if ( V_27 -> V_35 )
V_27 -> V_34 = F_59 ( V_27 -> V_35 ,
V_27 -> V_68 , V_41 ) ;
else
V_27 -> V_34 = F_23 ( V_27 -> V_68 , V_41 ) ;
if ( ! V_27 -> V_34 )
return - V_42 ;
return 0 ;
}
int F_60 ( struct V_26 * V_27 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < F_61 ( V_84 ) ; ++ V_33 )
if ( V_84 [ V_33 ] . V_85 == V_27 -> V_86 )
break;
if ( V_33 == F_61 ( V_84 ) ) {
F_62 ( V_27 -> V_37 , L_2 ,
V_27 -> V_86 ) ;
V_33 = 0 ;
}
F_63 ( & V_27 -> V_87 ) ;
V_27 -> V_88 = & V_84 [ V_33 ] ;
if ( V_27 -> V_88 -> V_89 ) {
if ( V_27 -> V_88 -> V_90 )
F_19 ( V_27 -> V_37 , L_3 ,
V_27 -> V_88 -> V_90 , V_27 -> V_90 ) ;
return V_27 -> V_88 -> V_89 ( V_27 ) ;
}
return - V_91 ;
}
int F_30 ( struct V_26 * V_27 )
{
if ( V_27 -> V_88 && V_27 -> V_88 -> exit ) {
if ( V_27 -> V_88 -> V_90 )
F_19 ( V_27 -> V_37 , L_4 ,
V_27 -> V_88 -> V_90 , V_27 -> V_90 ) ;
return V_27 -> V_88 -> exit ( V_27 ) ;
}
return - V_91 ;
}
int F_46 ( struct V_26 * V_27 ,
unsigned int V_15 , unsigned int * V_39 )
{
int V_32 ;
F_64 ( & V_27 -> V_87 ) ;
if ( V_39 && V_27 -> V_88 && V_27 -> V_88 -> V_92 ) {
V_32 = V_27 -> V_88 -> V_92 ( V_27 , V_15 , V_39 ) ;
F_65 ( & V_27 -> V_87 ) ;
return V_32 ;
}
F_65 ( & V_27 -> V_87 ) ;
return - V_91 ;
}
int F_66 ( struct V_26 * V_27 ,
unsigned int V_15 , unsigned int V_39 )
{
int V_32 ;
F_64 ( & V_27 -> V_87 ) ;
if ( V_27 -> V_88 && V_27 -> V_88 -> V_93 ) {
V_32 = V_27 -> V_88 -> V_93 ( V_27 , V_15 , V_39 ) ;
F_65 ( & V_27 -> V_87 ) ;
return V_32 ;
}
F_65 ( & V_27 -> V_87 ) ;
return - V_91 ;
}
int F_67 ( struct V_26 * V_27 )
{
int V_32 ;
const char * V_90 ;
if ( ! V_27 -> V_94 ) {
return 0 ;
}
if ( ! V_27 -> V_88 || ! V_27 -> V_88 -> V_95 )
return - V_91 ;
if ( V_27 -> V_88 -> V_90 )
V_90 = V_27 -> V_88 -> V_90 ;
else
V_90 = L_5 ;
if ( V_27 -> V_88 -> V_90 )
F_19 ( V_27 -> V_37 , L_6 ,
V_27 -> V_88 -> V_90 , V_27 -> V_90 ) ;
F_68 ( V_27 , V_90 , L_7 ) ;
V_32 = V_27 -> V_88 -> V_95 ( V_27 ) ;
if ( ! V_32 )
V_27 -> V_94 = 0 ;
F_68 ( V_27 , V_90 , L_8 ) ;
return V_32 ;
}
static int F_69 ( struct V_26 * V_27 ,
unsigned int V_15 )
{
const struct V_66 * V_67 ;
unsigned int V_96 , V_97 , V_98 ;
V_67 = V_27 -> V_45 ;
V_96 = 0 ;
V_97 = V_67 -> V_99 - 1 ;
do {
V_98 = ( V_96 + V_97 ) / 2 ;
if ( V_67 -> V_100 [ V_98 ] . V_15 == V_15 )
return V_98 ;
if ( V_67 -> V_100 [ V_98 ] . V_15 < V_15 )
V_96 = V_98 + 1 ;
else
V_97 = V_98 ;
} while ( V_96 <= V_97 );
return - 1 ;
}
int F_70 ( struct V_26 * V_27 ,
unsigned int V_15 )
{
int V_98 ;
if ( V_15 >= V_27 -> V_45 -> V_50 )
return 1 ;
V_98 = F_69 ( V_27 , V_15 ) ;
if ( V_98 < 0 )
return 0 ;
return V_27 -> V_45 -> V_100 [ V_98 ] . V_101 ;
}
int F_71 ( struct V_26 * V_27 ,
unsigned int V_15 )
{
int V_98 ;
if ( V_15 >= V_27 -> V_45 -> V_50 )
return 1 ;
V_98 = F_69 ( V_27 , V_15 ) ;
if ( V_98 < 0 )
return 0 ;
return V_27 -> V_45 -> V_100 [ V_98 ] . V_92 ;
}
int F_72 ( struct V_26 * V_27 ,
unsigned int V_15 )
{
int V_98 ;
if ( V_15 >= V_27 -> V_45 -> V_50 )
return 1 ;
V_98 = F_69 ( V_27 , V_15 ) ;
if ( V_98 < 0 )
return 0 ;
return V_27 -> V_45 -> V_100 [ V_98 ] . V_93 ;
}
