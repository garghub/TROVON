static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
int V_5 ;
int V_6 ;
unsigned int V_7 ;
void * V_8 ;
if ( ! V_2 -> V_9 )
return - V_10 ;
if ( ! V_2 -> V_11 ) {
T_1 V_12 = V_2 -> V_12 ;
F_2 ( V_2 -> V_13 , L_1 ) ;
V_2 -> V_12 = 1 ;
V_8 = F_3 ( V_2 -> V_14 , V_15 ) ;
if ( ! V_8 )
return - V_10 ;
V_5 = F_4 ( V_2 , 0 , V_8 ,
V_2 -> V_9 ) ;
V_2 -> V_12 = V_12 ;
if ( V_5 < 0 ) {
F_5 ( V_8 ) ;
return V_5 ;
}
V_2 -> V_11 = V_8 ;
V_2 -> V_16 = 1 ;
}
for ( V_6 = 0 , V_3 = 0 ; V_3 < V_2 -> V_9 ; V_3 ++ ) {
V_7 = F_6 ( V_2 , V_2 -> V_11 , V_3 ) ;
if ( F_7 ( V_2 , V_3 * V_2 -> V_17 ) )
continue;
V_6 ++ ;
}
V_2 -> V_18 = F_3 ( V_6 * sizeof( struct V_19 ) ,
V_15 ) ;
if ( ! V_2 -> V_18 ) {
V_5 = - V_20 ;
goto V_21;
}
V_2 -> V_22 = V_6 ;
for ( V_3 = 0 , V_4 = 0 ; V_3 < V_2 -> V_9 ; V_3 ++ ) {
V_7 = F_6 ( V_2 , V_2 -> V_11 , V_3 ) ;
if ( F_7 ( V_2 , V_3 * V_2 -> V_17 ) )
continue;
V_2 -> V_18 [ V_4 ] . V_23 = V_3 * V_2 -> V_17 ;
V_2 -> V_18 [ V_4 ] . V_24 = V_7 ;
V_4 ++ ;
}
return 0 ;
V_21:
if ( V_2 -> V_16 )
F_5 ( V_2 -> V_11 ) ;
return V_5 ;
}
int F_8 ( struct V_1 * V_2 , const struct V_25 * V_26 )
{
int V_5 ;
int V_3 ;
void * V_8 ;
for ( V_3 = 0 ; V_3 < V_26 -> V_22 ; V_3 ++ )
if ( V_26 -> V_18 [ V_3 ] . V_23 % V_2 -> V_17 )
return - V_10 ;
if ( V_2 -> V_27 == V_28 ) {
V_2 -> V_12 = true ;
return 0 ;
}
for ( V_3 = 0 ; V_3 < F_9 ( V_29 ) ; V_3 ++ )
if ( V_29 [ V_3 ] -> type == V_2 -> V_27 )
break;
if ( V_3 == F_9 ( V_29 ) ) {
F_10 ( V_2 -> V_13 , L_2 ,
V_2 -> V_27 ) ;
return - V_10 ;
}
V_2 -> V_22 = V_26 -> V_22 ;
V_2 -> V_9 = V_26 -> V_9 ;
V_2 -> V_11 = V_26 -> V_11 ;
V_2 -> V_30 = F_11 ( V_26 -> V_31 , 8 ) ;
V_2 -> V_14 = V_2 -> V_30 * V_26 -> V_9 ;
V_2 -> V_32 = NULL ;
V_2 -> V_33 = V_29 [ V_3 ] ;
if ( ! V_2 -> V_33 -> V_34 ||
! V_2 -> V_33 -> V_35 ||
! V_2 -> V_33 -> V_36 )
return - V_10 ;
if ( V_26 -> V_18 ) {
if ( ! V_2 -> V_22 )
return - V_10 ;
V_8 = F_12 ( V_26 -> V_18 , V_2 -> V_22 *
sizeof( struct V_19 ) , V_15 ) ;
if ( ! V_8 )
return - V_20 ;
V_2 -> V_18 = V_8 ;
} else if ( V_2 -> V_9 ) {
V_5 = F_1 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( ! V_2 -> V_37 )
V_2 -> V_37 = V_2 -> V_9 ;
if ( V_2 -> V_33 -> V_38 ) {
F_13 ( V_2 -> V_13 , L_3 ,
V_2 -> V_33 -> V_36 ) ;
V_5 = V_2 -> V_33 -> V_38 ( V_2 ) ;
if ( V_5 )
goto V_21;
}
return 0 ;
V_21:
F_5 ( V_2 -> V_18 ) ;
if ( V_2 -> V_16 )
F_5 ( V_2 -> V_11 ) ;
return V_5 ;
}
void F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_27 == V_28 )
return;
F_15 ( ! V_2 -> V_33 ) ;
F_5 ( V_2 -> V_18 ) ;
if ( V_2 -> V_16 )
F_5 ( V_2 -> V_11 ) ;
if ( V_2 -> V_33 -> exit ) {
F_13 ( V_2 -> V_13 , L_4 ,
V_2 -> V_33 -> V_36 ) ;
V_2 -> V_33 -> exit ( V_2 ) ;
}
}
int F_16 ( struct V_1 * V_2 ,
unsigned int V_23 , unsigned int * V_39 )
{
int V_5 ;
if ( V_2 -> V_27 == V_28 )
return - V_40 ;
F_15 ( ! V_2 -> V_33 ) ;
if ( ! F_7 ( V_2 , V_23 ) ) {
V_5 = V_2 -> V_33 -> V_34 ( V_2 , V_23 , V_39 ) ;
if ( V_5 == 0 )
F_17 ( V_2 -> V_13 , V_23 , * V_39 ) ;
return V_5 ;
}
return - V_10 ;
}
int F_18 ( struct V_1 * V_2 ,
unsigned int V_23 , unsigned int V_39 )
{
if ( V_2 -> V_27 == V_28 )
return 0 ;
F_15 ( ! V_2 -> V_33 ) ;
if ( ! F_7 ( V_2 , V_23 ) )
return V_2 -> V_33 -> V_35 ( V_2 , V_23 , V_39 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , unsigned int V_41 ,
unsigned int V_42 )
{
unsigned int V_23 ;
for ( V_23 = V_41 ; V_23 <= V_42 ; V_23 += V_2 -> V_17 ) {
unsigned int V_7 ;
int V_5 ;
if ( F_7 ( V_2 , V_23 ) ||
! F_20 ( V_2 , V_23 ) )
continue;
V_5 = F_16 ( V_2 , V_23 , & V_7 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_21 ( V_2 , V_23 ) ;
if ( V_5 >= 0 && V_7 == V_2 -> V_18 [ V_5 ] . V_24 )
continue;
V_2 -> V_12 = 1 ;
V_5 = F_22 ( V_2 , V_23 , V_7 ) ;
V_2 -> V_12 = 0 ;
if ( V_5 ) {
F_10 ( V_2 -> V_13 , L_5 ,
V_23 , V_5 ) ;
return V_5 ;
}
F_13 ( V_2 -> V_13 , L_6 , V_23 , V_7 ) ;
}
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
int V_5 = 0 ;
unsigned int V_3 ;
const char * V_36 ;
unsigned int V_43 ;
F_15 ( ! V_2 -> V_33 ) ;
V_2 -> V_44 ( V_2 -> V_45 ) ;
V_43 = V_2 -> V_12 ;
F_13 ( V_2 -> V_13 , L_7 ,
V_2 -> V_33 -> V_36 ) ;
V_36 = V_2 -> V_33 -> V_36 ;
F_24 ( V_2 -> V_13 , V_36 , L_8 ) ;
if ( ! V_2 -> V_46 )
goto V_47;
V_2 -> V_48 = true ;
V_2 -> V_12 = 1 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_49 ; V_3 ++ ) {
V_5 = F_22 ( V_2 , V_2 -> V_50 [ V_3 ] . V_23 , V_2 -> V_50 [ V_3 ] . V_24 ) ;
if ( V_5 != 0 ) {
F_10 ( V_2 -> V_13 , L_9 ,
V_2 -> V_50 [ V_3 ] . V_23 , V_2 -> V_50 [ V_3 ] . V_24 , V_5 ) ;
goto V_47;
}
}
V_2 -> V_12 = 0 ;
if ( V_2 -> V_33 -> V_51 )
V_5 = V_2 -> V_33 -> V_51 ( V_2 , 0 , V_2 -> V_37 ) ;
else
V_5 = F_19 ( V_2 , 0 , V_2 -> V_37 ) ;
if ( V_5 == 0 )
V_2 -> V_46 = false ;
V_47:
V_2 -> V_48 = false ;
V_2 -> V_12 = V_43 ;
V_2 -> V_52 ( V_2 -> V_45 ) ;
F_25 ( V_2 ) ;
F_24 ( V_2 -> V_13 , V_36 , L_10 ) ;
return V_5 ;
}
int F_26 ( struct V_1 * V_2 , unsigned int V_41 ,
unsigned int V_42 )
{
int V_5 = 0 ;
const char * V_36 ;
unsigned int V_43 ;
F_15 ( ! V_2 -> V_33 ) ;
V_2 -> V_44 ( V_2 -> V_45 ) ;
V_43 = V_2 -> V_12 ;
V_36 = V_2 -> V_33 -> V_36 ;
F_13 ( V_2 -> V_13 , L_11 , V_36 , V_41 , V_42 ) ;
F_24 ( V_2 -> V_13 , V_36 , L_12 ) ;
if ( ! V_2 -> V_46 )
goto V_47;
V_2 -> V_48 = true ;
if ( V_2 -> V_33 -> V_51 )
V_5 = V_2 -> V_33 -> V_51 ( V_2 , V_41 , V_42 ) ;
else
V_5 = F_19 ( V_2 , V_41 , V_42 ) ;
V_47:
V_2 -> V_12 = V_43 ;
V_2 -> V_48 = false ;
V_2 -> V_52 ( V_2 -> V_45 ) ;
F_25 ( V_2 ) ;
F_24 ( V_2 -> V_13 , V_36 , L_13 ) ;
return V_5 ;
}
int F_27 ( struct V_1 * V_2 , unsigned int V_41 ,
unsigned int V_42 )
{
int V_5 = 0 ;
if ( ! V_2 -> V_33 || ! V_2 -> V_33 -> V_53 )
return - V_10 ;
V_2 -> V_44 ( V_2 -> V_45 ) ;
F_28 ( V_2 -> V_13 , V_41 , V_42 ) ;
V_5 = V_2 -> V_33 -> V_53 ( V_2 , V_41 , V_42 ) ;
V_2 -> V_52 ( V_2 -> V_45 ) ;
return V_5 ;
}
void F_29 ( struct V_1 * V_2 , bool V_54 )
{
V_2 -> V_44 ( V_2 -> V_45 ) ;
F_30 ( V_2 -> V_12 && V_54 ) ;
V_2 -> V_55 = V_54 ;
F_31 ( V_2 -> V_13 , V_54 ) ;
V_2 -> V_52 ( V_2 -> V_45 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
V_2 -> V_44 ( V_2 -> V_45 ) ;
V_2 -> V_46 = true ;
V_2 -> V_52 ( V_2 -> V_45 ) ;
}
void F_33 ( struct V_1 * V_2 , bool V_54 )
{
V_2 -> V_44 ( V_2 -> V_45 ) ;
F_30 ( V_2 -> V_55 && V_54 ) ;
V_2 -> V_12 = V_54 ;
F_34 ( V_2 -> V_13 , V_54 ) ;
V_2 -> V_52 ( V_2 -> V_45 ) ;
}
bool F_35 ( struct V_1 * V_2 , void * V_56 , unsigned int V_57 ,
unsigned int V_7 )
{
if ( F_6 ( V_2 , V_56 , V_57 ) == V_7 )
return true ;
if ( V_2 -> V_58 . V_59 ) {
V_2 -> V_58 . V_59 ( V_56 + ( V_2 -> V_30 * V_57 ) ,
V_7 , 0 ) ;
return false ;
}
switch ( V_2 -> V_30 ) {
case 1 : {
T_2 * V_32 = V_56 ;
V_32 [ V_57 ] = V_7 ;
break;
}
case 2 : {
T_3 * V_32 = V_56 ;
V_32 [ V_57 ] = V_7 ;
break;
}
case 4 : {
T_1 * V_32 = V_56 ;
V_32 [ V_57 ] = V_7 ;
break;
}
default:
F_36 () ;
}
return false ;
}
unsigned int F_6 ( struct V_1 * V_2 , const void * V_56 ,
unsigned int V_57 )
{
if ( ! V_56 )
return - V_10 ;
if ( V_2 -> V_58 . V_60 )
return V_2 -> V_58 . V_60 ( F_37 ( V_2 , V_56 ,
V_57 ) ) ;
switch ( V_2 -> V_30 ) {
case 1 : {
const T_2 * V_32 = V_56 ;
return V_32 [ V_57 ] ;
}
case 2 : {
const T_3 * V_32 = V_56 ;
return V_32 [ V_57 ] ;
}
case 4 : {
const T_1 * V_32 = V_56 ;
return V_32 [ V_57 ] ;
}
default:
F_36 () ;
}
return - 1 ;
}
static int F_38 ( const void * V_61 , const void * V_62 )
{
const struct V_19 * V_63 = V_61 ;
const struct V_19 * V_64 = V_62 ;
return V_63 -> V_23 - V_64 -> V_23 ;
}
int F_21 ( struct V_1 * V_2 , unsigned int V_23 )
{
struct V_19 V_65 ;
struct V_19 * V_66 ;
V_65 . V_23 = V_23 ;
V_65 . V_24 = 0 ;
V_66 = bsearch ( & V_65 , V_2 -> V_18 , V_2 -> V_22 ,
sizeof( struct V_19 ) , F_38 ) ;
if ( V_66 )
return V_66 - V_2 -> V_18 ;
else
return - V_67 ;
}
static bool F_39 ( unsigned long * V_68 , unsigned int V_57 )
{
if ( ! V_68 )
return true ;
return F_40 ( V_57 , V_68 ) ;
}
static int F_41 ( struct V_1 * V_2 , void * V_69 ,
unsigned long * V_68 ,
unsigned int V_70 ,
unsigned int V_71 , unsigned int V_72 )
{
unsigned int V_3 , V_73 , V_7 ;
int V_5 ;
for ( V_3 = V_71 ; V_3 < V_72 ; V_3 ++ ) {
V_73 = V_70 + ( V_3 * V_2 -> V_17 ) ;
if ( ! F_39 ( V_68 , V_3 ) )
continue;
V_7 = F_6 ( V_2 , V_69 , V_3 ) ;
V_5 = F_21 ( V_2 , V_73 ) ;
if ( V_5 >= 0 && V_7 == V_2 -> V_18 [ V_5 ] . V_24 )
continue;
V_2 -> V_12 = 1 ;
V_5 = F_22 ( V_2 , V_73 , V_7 ) ;
V_2 -> V_12 = 0 ;
if ( V_5 != 0 ) {
F_10 ( V_2 -> V_13 , L_5 ,
V_73 , V_5 ) ;
return V_5 ;
}
F_13 ( V_2 -> V_13 , L_6 ,
V_73 , V_7 ) ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , const void * * V_74 ,
unsigned int V_56 , unsigned int V_75 )
{
T_4 V_76 = V_2 -> V_58 . V_76 ;
int V_5 , V_6 ;
if ( * V_74 == NULL )
return 0 ;
V_6 = ( V_75 - V_56 ) / V_2 -> V_17 ;
F_13 ( V_2 -> V_13 , L_14 ,
V_6 * V_76 , V_6 , V_56 , V_75 - V_2 -> V_17 ) ;
V_2 -> V_12 = 1 ;
V_5 = F_43 ( V_2 , V_56 , * V_74 , V_6 * V_76 ) ;
if ( V_5 )
F_10 ( V_2 -> V_13 , L_15 ,
V_56 , V_75 - V_2 -> V_17 , V_5 ) ;
V_2 -> V_12 = 0 ;
* V_74 = NULL ;
return V_5 ;
}
static int F_44 ( struct V_1 * V_2 , void * V_69 ,
unsigned long * V_68 ,
unsigned int V_70 , unsigned int V_71 ,
unsigned int V_72 )
{
unsigned int V_3 , V_7 ;
unsigned int V_73 = 0 ;
unsigned int V_56 = 0 ;
const void * V_74 = NULL ;
int V_5 ;
for ( V_3 = V_71 ; V_3 < V_72 ; V_3 ++ ) {
V_73 = V_70 + ( V_3 * V_2 -> V_17 ) ;
if ( ! F_39 ( V_68 , V_3 ) ) {
V_5 = F_42 ( V_2 , & V_74 ,
V_56 , V_73 ) ;
if ( V_5 != 0 )
return V_5 ;
continue;
}
V_7 = F_6 ( V_2 , V_69 , V_3 ) ;
V_5 = F_21 ( V_2 , V_73 ) ;
if ( V_5 >= 0 && V_7 == V_2 -> V_18 [ V_5 ] . V_24 ) {
V_5 = F_42 ( V_2 , & V_74 ,
V_56 , V_73 ) ;
if ( V_5 != 0 )
return V_5 ;
continue;
}
if ( ! V_74 ) {
V_74 = F_37 ( V_2 , V_69 , V_3 ) ;
V_56 = V_73 ;
}
}
return F_42 ( V_2 , & V_74 , V_56 , V_73 +
V_2 -> V_17 ) ;
}
int F_45 ( struct V_1 * V_2 , void * V_69 ,
unsigned long * V_68 ,
unsigned int V_70 , unsigned int V_71 ,
unsigned int V_72 )
{
if ( F_46 ( V_2 ) && ! V_2 -> V_77 )
return F_44 ( V_2 , V_69 , V_68 ,
V_70 , V_71 , V_72 ) ;
else
return F_41 ( V_2 , V_69 , V_68 ,
V_70 , V_71 , V_72 ) ;
}
