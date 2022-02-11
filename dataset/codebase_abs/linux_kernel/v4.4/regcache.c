static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
int V_5 ;
int V_6 ;
unsigned int V_7 ;
void * V_8 ;
if ( ! V_2 -> V_9 )
return - V_10 ;
for ( V_6 = 0 , V_3 = 0 ; V_3 < V_2 -> V_9 ; V_3 ++ )
if ( ! F_2 ( V_2 , V_3 * V_2 -> V_11 ) )
V_6 ++ ;
if ( ! V_6 ) {
V_2 -> V_12 = true ;
return 0 ;
}
V_2 -> V_13 = V_6 ;
V_2 -> V_14 = F_3 ( V_6 , sizeof( struct V_15 ) ,
V_16 ) ;
if ( ! V_2 -> V_14 )
return - V_17 ;
if ( ! V_2 -> V_18 ) {
bool V_12 = V_2 -> V_12 ;
F_4 ( V_2 -> V_19 , L_1 ) ;
V_2 -> V_12 = true ;
V_8 = F_5 ( V_2 -> V_20 , V_16 ) ;
if ( ! V_8 ) {
V_5 = - V_17 ;
goto V_21;
}
V_5 = F_6 ( V_2 , 0 , V_8 ,
V_2 -> V_9 ) ;
V_2 -> V_12 = V_12 ;
if ( V_5 < 0 )
goto V_22;
V_2 -> V_18 = V_8 ;
V_2 -> V_23 = 1 ;
}
for ( V_3 = 0 , V_4 = 0 ; V_3 < V_2 -> V_9 ; V_3 ++ ) {
if ( F_2 ( V_2 , V_3 * V_2 -> V_11 ) )
continue;
V_7 = F_7 ( V_2 , V_2 -> V_18 , V_3 ) ;
V_2 -> V_14 [ V_4 ] . V_24 = V_3 * V_2 -> V_11 ;
V_2 -> V_14 [ V_4 ] . V_25 = V_7 ;
V_4 ++ ;
}
return 0 ;
V_22:
F_8 ( V_8 ) ;
V_21:
F_8 ( V_2 -> V_14 ) ;
return V_5 ;
}
int F_9 ( struct V_1 * V_2 , const struct V_26 * V_27 )
{
int V_5 ;
int V_3 ;
void * V_8 ;
for ( V_3 = 0 ; V_3 < V_27 -> V_13 ; V_3 ++ )
if ( V_27 -> V_14 [ V_3 ] . V_24 % V_2 -> V_11 )
return - V_10 ;
if ( V_2 -> V_28 == V_29 ) {
V_2 -> V_12 = true ;
return 0 ;
}
for ( V_3 = 0 ; V_3 < F_10 ( V_30 ) ; V_3 ++ )
if ( V_30 [ V_3 ] -> type == V_2 -> V_28 )
break;
if ( V_3 == F_10 ( V_30 ) ) {
F_11 ( V_2 -> V_19 , L_2 ,
V_2 -> V_28 ) ;
return - V_10 ;
}
V_2 -> V_13 = V_27 -> V_13 ;
V_2 -> V_9 = V_27 -> V_9 ;
V_2 -> V_18 = V_27 -> V_18 ;
V_2 -> V_31 = F_12 ( V_27 -> V_32 , 8 ) ;
V_2 -> V_20 = V_2 -> V_31 * V_27 -> V_9 ;
V_2 -> V_33 = NULL ;
V_2 -> V_34 = V_30 [ V_3 ] ;
if ( ! V_2 -> V_34 -> V_35 ||
! V_2 -> V_34 -> V_36 ||
! V_2 -> V_34 -> V_37 )
return - V_10 ;
if ( V_27 -> V_14 ) {
if ( ! V_2 -> V_13 )
return - V_10 ;
V_8 = F_13 ( V_27 -> V_14 , V_2 -> V_13 *
sizeof( struct V_15 ) , V_16 ) ;
if ( ! V_8 )
return - V_17 ;
V_2 -> V_14 = V_8 ;
} else if ( V_2 -> V_9 ) {
V_5 = F_1 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_2 -> V_12 )
return 0 ;
}
if ( ! V_2 -> V_38 )
V_2 -> V_38 = V_2 -> V_9 ;
if ( V_2 -> V_34 -> V_39 ) {
F_14 ( V_2 -> V_19 , L_3 ,
V_2 -> V_34 -> V_37 ) ;
V_5 = V_2 -> V_34 -> V_39 ( V_2 ) ;
if ( V_5 )
goto V_21;
}
return 0 ;
V_21:
F_8 ( V_2 -> V_14 ) ;
if ( V_2 -> V_23 )
F_8 ( V_2 -> V_18 ) ;
return V_5 ;
}
void F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_28 == V_29 )
return;
F_16 ( ! V_2 -> V_34 ) ;
F_8 ( V_2 -> V_14 ) ;
if ( V_2 -> V_23 )
F_8 ( V_2 -> V_18 ) ;
if ( V_2 -> V_34 -> exit ) {
F_14 ( V_2 -> V_19 , L_4 ,
V_2 -> V_34 -> V_37 ) ;
V_2 -> V_34 -> exit ( V_2 ) ;
}
}
int F_17 ( struct V_1 * V_2 ,
unsigned int V_24 , unsigned int * V_40 )
{
int V_5 ;
if ( V_2 -> V_28 == V_29 )
return - V_41 ;
F_16 ( ! V_2 -> V_34 ) ;
if ( ! F_2 ( V_2 , V_24 ) ) {
V_5 = V_2 -> V_34 -> V_35 ( V_2 , V_24 , V_40 ) ;
if ( V_5 == 0 )
F_18 ( V_2 , V_24 , * V_40 ) ;
return V_5 ;
}
return - V_10 ;
}
int F_19 ( struct V_1 * V_2 ,
unsigned int V_24 , unsigned int V_40 )
{
if ( V_2 -> V_28 == V_29 )
return 0 ;
F_16 ( ! V_2 -> V_34 ) ;
if ( ! F_2 ( V_2 , V_24 ) )
return V_2 -> V_34 -> V_36 ( V_2 , V_24 , V_40 ) ;
return 0 ;
}
static bool F_20 ( struct V_1 * V_2 , unsigned int V_24 ,
unsigned int V_7 )
{
int V_5 ;
if ( ! V_2 -> V_42 )
return true ;
V_5 = F_21 ( V_2 , V_24 ) ;
if ( V_5 >= 0 && V_7 == V_2 -> V_14 [ V_5 ] . V_25 )
return false ;
return true ;
}
static int F_22 ( struct V_1 * V_2 , unsigned int V_43 ,
unsigned int V_44 )
{
unsigned int V_24 ;
for ( V_24 = V_43 ; V_24 <= V_44 ; V_24 += V_2 -> V_11 ) {
unsigned int V_7 ;
int V_5 ;
if ( F_2 ( V_2 , V_24 ) ||
! F_23 ( V_2 , V_24 ) )
continue;
V_5 = F_17 ( V_2 , V_24 , & V_7 ) ;
if ( V_5 )
return V_5 ;
if ( ! F_20 ( V_2 , V_24 , V_7 ) )
continue;
V_2 -> V_12 = true ;
V_5 = F_24 ( V_2 , V_24 , V_7 ) ;
V_2 -> V_12 = false ;
if ( V_5 ) {
F_11 ( V_2 -> V_19 , L_5 ,
V_24 , V_5 ) ;
return V_5 ;
}
F_14 ( V_2 -> V_19 , L_6 , V_24 , V_7 ) ;
}
return 0 ;
}
int F_25 ( struct V_1 * V_2 )
{
int V_5 = 0 ;
unsigned int V_3 ;
const char * V_37 ;
bool V_45 ;
F_16 ( ! V_2 -> V_34 ) ;
V_2 -> V_46 ( V_2 -> V_47 ) ;
V_45 = V_2 -> V_12 ;
F_14 ( V_2 -> V_19 , L_7 ,
V_2 -> V_34 -> V_37 ) ;
V_37 = V_2 -> V_34 -> V_37 ;
F_26 ( V_2 , V_37 , L_8 ) ;
if ( ! V_2 -> V_48 )
goto V_49;
V_2 -> V_50 = true ;
V_2 -> V_12 = true ;
for ( V_3 = 0 ; V_3 < V_2 -> V_51 ; V_3 ++ ) {
V_5 = F_24 ( V_2 , V_2 -> V_52 [ V_3 ] . V_24 , V_2 -> V_52 [ V_3 ] . V_25 ) ;
if ( V_5 != 0 ) {
F_11 ( V_2 -> V_19 , L_9 ,
V_2 -> V_52 [ V_3 ] . V_24 , V_2 -> V_52 [ V_3 ] . V_25 , V_5 ) ;
goto V_49;
}
}
V_2 -> V_12 = false ;
if ( V_2 -> V_34 -> V_53 )
V_5 = V_2 -> V_34 -> V_53 ( V_2 , 0 , V_2 -> V_38 ) ;
else
V_5 = F_22 ( V_2 , 0 , V_2 -> V_38 ) ;
if ( V_5 == 0 )
V_2 -> V_48 = false ;
V_49:
V_2 -> V_50 = false ;
V_2 -> V_12 = V_45 ;
V_2 -> V_42 = false ;
V_2 -> V_54 ( V_2 -> V_47 ) ;
F_27 ( V_2 ) ;
F_26 ( V_2 , V_37 , L_10 ) ;
return V_5 ;
}
int F_28 ( struct V_1 * V_2 , unsigned int V_43 ,
unsigned int V_44 )
{
int V_5 = 0 ;
const char * V_37 ;
bool V_45 ;
F_16 ( ! V_2 -> V_34 ) ;
V_2 -> V_46 ( V_2 -> V_47 ) ;
V_45 = V_2 -> V_12 ;
V_37 = V_2 -> V_34 -> V_37 ;
F_14 ( V_2 -> V_19 , L_11 , V_37 , V_43 , V_44 ) ;
F_26 ( V_2 , V_37 , L_12 ) ;
if ( ! V_2 -> V_48 )
goto V_49;
V_2 -> V_50 = true ;
if ( V_2 -> V_34 -> V_53 )
V_5 = V_2 -> V_34 -> V_53 ( V_2 , V_43 , V_44 ) ;
else
V_5 = F_22 ( V_2 , V_43 , V_44 ) ;
V_49:
V_2 -> V_12 = V_45 ;
V_2 -> V_50 = false ;
V_2 -> V_42 = false ;
V_2 -> V_54 ( V_2 -> V_47 ) ;
F_27 ( V_2 ) ;
F_26 ( V_2 , V_37 , L_13 ) ;
return V_5 ;
}
int F_29 ( struct V_1 * V_2 , unsigned int V_43 ,
unsigned int V_44 )
{
int V_5 = 0 ;
if ( ! V_2 -> V_34 || ! V_2 -> V_34 -> V_55 )
return - V_10 ;
V_2 -> V_46 ( V_2 -> V_47 ) ;
F_30 ( V_2 , V_43 , V_44 ) ;
V_5 = V_2 -> V_34 -> V_55 ( V_2 , V_43 , V_44 ) ;
V_2 -> V_54 ( V_2 -> V_47 ) ;
return V_5 ;
}
void F_31 ( struct V_1 * V_2 , bool V_56 )
{
V_2 -> V_46 ( V_2 -> V_47 ) ;
F_32 ( V_2 -> V_12 && V_56 ) ;
V_2 -> V_57 = V_56 ;
F_33 ( V_2 , V_56 ) ;
V_2 -> V_54 ( V_2 -> V_47 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
V_2 -> V_46 ( V_2 -> V_47 ) ;
V_2 -> V_48 = true ;
V_2 -> V_42 = true ;
V_2 -> V_54 ( V_2 -> V_47 ) ;
}
void F_35 ( struct V_1 * V_2 , bool V_56 )
{
V_2 -> V_46 ( V_2 -> V_47 ) ;
F_32 ( V_2 -> V_57 && V_56 ) ;
V_2 -> V_12 = V_56 ;
F_36 ( V_2 , V_56 ) ;
V_2 -> V_54 ( V_2 -> V_47 ) ;
}
bool F_37 ( struct V_1 * V_2 , void * V_58 , unsigned int V_59 ,
unsigned int V_7 )
{
if ( F_7 ( V_2 , V_58 , V_59 ) == V_7 )
return true ;
if ( V_2 -> V_60 . V_61 ) {
V_2 -> V_60 . V_61 ( V_58 + ( V_2 -> V_31 * V_59 ) ,
V_7 , 0 ) ;
return false ;
}
switch ( V_2 -> V_31 ) {
case 1 : {
T_1 * V_33 = V_58 ;
V_33 [ V_59 ] = V_7 ;
break;
}
case 2 : {
T_2 * V_33 = V_58 ;
V_33 [ V_59 ] = V_7 ;
break;
}
case 4 : {
T_3 * V_33 = V_58 ;
V_33 [ V_59 ] = V_7 ;
break;
}
default:
F_38 () ;
}
return false ;
}
unsigned int F_7 ( struct V_1 * V_2 , const void * V_58 ,
unsigned int V_59 )
{
if ( ! V_58 )
return - V_10 ;
if ( V_2 -> V_60 . V_62 )
return V_2 -> V_60 . V_62 ( F_39 ( V_2 , V_58 ,
V_59 ) ) ;
switch ( V_2 -> V_31 ) {
case 1 : {
const T_1 * V_33 = V_58 ;
return V_33 [ V_59 ] ;
}
case 2 : {
const T_2 * V_33 = V_58 ;
return V_33 [ V_59 ] ;
}
case 4 : {
const T_3 * V_33 = V_58 ;
return V_33 [ V_59 ] ;
}
default:
F_38 () ;
}
return - 1 ;
}
static int F_40 ( const void * V_63 , const void * V_64 )
{
const struct V_15 * V_65 = V_63 ;
const struct V_15 * V_66 = V_64 ;
return V_65 -> V_24 - V_66 -> V_24 ;
}
int F_21 ( struct V_1 * V_2 , unsigned int V_24 )
{
struct V_15 V_67 ;
struct V_15 * V_68 ;
V_67 . V_24 = V_24 ;
V_67 . V_25 = 0 ;
V_68 = bsearch ( & V_67 , V_2 -> V_14 , V_2 -> V_13 ,
sizeof( struct V_15 ) , F_40 ) ;
if ( V_68 )
return V_68 - V_2 -> V_14 ;
else
return - V_69 ;
}
static bool F_41 ( unsigned long * V_70 , unsigned int V_59 )
{
if ( ! V_70 )
return true ;
return F_42 ( V_59 , V_70 ) ;
}
static int F_43 ( struct V_1 * V_2 , void * V_71 ,
unsigned long * V_70 ,
unsigned int V_72 ,
unsigned int V_73 , unsigned int V_74 )
{
unsigned int V_3 , V_75 , V_7 ;
int V_5 ;
for ( V_3 = V_73 ; V_3 < V_74 ; V_3 ++ ) {
V_75 = V_72 + ( V_3 * V_2 -> V_11 ) ;
if ( ! F_41 ( V_70 , V_3 ) ||
! F_23 ( V_2 , V_75 ) )
continue;
V_7 = F_7 ( V_2 , V_71 , V_3 ) ;
if ( ! F_20 ( V_2 , V_75 , V_7 ) )
continue;
V_2 -> V_12 = true ;
V_5 = F_24 ( V_2 , V_75 , V_7 ) ;
V_2 -> V_12 = false ;
if ( V_5 != 0 ) {
F_11 ( V_2 -> V_19 , L_5 ,
V_75 , V_5 ) ;
return V_5 ;
}
F_14 ( V_2 -> V_19 , L_6 ,
V_75 , V_7 ) ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , const void * * V_76 ,
unsigned int V_58 , unsigned int V_77 )
{
T_4 V_78 = V_2 -> V_60 . V_78 ;
int V_5 , V_6 ;
if ( * V_76 == NULL )
return 0 ;
V_6 = ( V_77 - V_58 ) / V_2 -> V_11 ;
F_14 ( V_2 -> V_19 , L_14 ,
V_6 * V_78 , V_6 , V_58 , V_77 - V_2 -> V_11 ) ;
V_2 -> V_12 = true ;
V_5 = F_45 ( V_2 , V_58 , * V_76 , V_6 * V_78 ) ;
if ( V_5 )
F_11 ( V_2 -> V_19 , L_15 ,
V_58 , V_77 - V_2 -> V_11 , V_5 ) ;
V_2 -> V_12 = false ;
* V_76 = NULL ;
return V_5 ;
}
static int F_46 ( struct V_1 * V_2 , void * V_71 ,
unsigned long * V_70 ,
unsigned int V_72 , unsigned int V_73 ,
unsigned int V_74 )
{
unsigned int V_3 , V_7 ;
unsigned int V_75 = 0 ;
unsigned int V_58 = 0 ;
const void * V_76 = NULL ;
int V_5 ;
for ( V_3 = V_73 ; V_3 < V_74 ; V_3 ++ ) {
V_75 = V_72 + ( V_3 * V_2 -> V_11 ) ;
if ( ! F_41 ( V_70 , V_3 ) ||
! F_23 ( V_2 , V_75 ) ) {
V_5 = F_44 ( V_2 , & V_76 ,
V_58 , V_75 ) ;
if ( V_5 != 0 )
return V_5 ;
continue;
}
V_7 = F_7 ( V_2 , V_71 , V_3 ) ;
if ( ! F_20 ( V_2 , V_75 , V_7 ) ) {
V_5 = F_44 ( V_2 , & V_76 ,
V_58 , V_75 ) ;
if ( V_5 != 0 )
return V_5 ;
continue;
}
if ( ! V_76 ) {
V_76 = F_39 ( V_2 , V_71 , V_3 ) ;
V_58 = V_75 ;
}
}
return F_44 ( V_2 , & V_76 , V_58 , V_75 +
V_2 -> V_11 ) ;
}
int F_47 ( struct V_1 * V_2 , void * V_71 ,
unsigned long * V_70 ,
unsigned int V_72 , unsigned int V_73 ,
unsigned int V_74 )
{
if ( F_48 ( V_2 ) && ! V_2 -> V_79 )
return F_46 ( V_2 , V_71 , V_70 ,
V_72 , V_73 , V_74 ) ;
else
return F_43 ( V_2 , V_71 , V_70 ,
V_72 , V_73 , V_74 ) ;
}
