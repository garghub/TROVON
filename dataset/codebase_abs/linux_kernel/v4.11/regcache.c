static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
int V_5 ;
int V_6 ;
unsigned int V_7 , V_8 ;
void * V_9 ;
if ( ! V_2 -> V_10 )
return - V_11 ;
for ( V_6 = 0 , V_3 = 0 ; V_3 < V_2 -> V_10 ; V_3 ++ )
if ( F_2 ( V_2 , V_3 * V_2 -> V_12 ) &&
! F_3 ( V_2 , V_3 * V_2 -> V_12 ) )
V_6 ++ ;
if ( ! V_6 ) {
V_2 -> V_13 = true ;
return 0 ;
}
V_2 -> V_14 = V_6 ;
V_2 -> V_15 = F_4 ( V_6 , sizeof( struct V_16 ) ,
V_17 ) ;
if ( ! V_2 -> V_15 )
return - V_18 ;
if ( ! V_2 -> V_19 ) {
bool V_13 = V_2 -> V_13 ;
F_5 ( V_2 -> V_20 , L_1 ) ;
V_2 -> V_13 = true ;
V_9 = F_6 ( V_2 -> V_21 , V_17 ) ;
if ( ! V_9 ) {
V_5 = - V_18 ;
goto V_22;
}
V_5 = F_7 ( V_2 , 0 , V_9 ,
V_2 -> V_21 ) ;
V_2 -> V_13 = V_13 ;
if ( V_5 == 0 ) {
V_2 -> V_19 = V_9 ;
V_2 -> V_23 = 1 ;
} else {
F_8 ( V_9 ) ;
}
}
for ( V_3 = 0 , V_4 = 0 ; V_3 < V_2 -> V_10 ; V_3 ++ ) {
V_7 = V_3 * V_2 -> V_12 ;
if ( ! F_2 ( V_2 , V_7 ) )
continue;
if ( F_3 ( V_2 , V_7 ) )
continue;
if ( V_2 -> V_19 ) {
V_8 = F_9 ( V_2 , V_2 -> V_19 , V_3 ) ;
} else {
bool V_13 = V_2 -> V_13 ;
V_2 -> V_13 = true ;
V_5 = F_10 ( V_2 , V_7 , & V_8 ) ;
V_2 -> V_13 = V_13 ;
if ( V_5 != 0 ) {
F_11 ( V_2 -> V_20 , L_2 ,
V_7 , V_5 ) ;
goto V_22;
}
}
V_2 -> V_15 [ V_4 ] . V_7 = V_7 ;
V_2 -> V_15 [ V_4 ] . V_24 = V_8 ;
V_4 ++ ;
}
return 0 ;
V_22:
F_8 ( V_2 -> V_15 ) ;
return V_5 ;
}
int F_12 ( struct V_1 * V_2 , const struct V_25 * V_26 )
{
int V_5 ;
int V_3 ;
void * V_9 ;
if ( V_2 -> V_27 == V_28 ) {
if ( V_26 -> V_15 || V_26 -> V_10 )
F_5 ( V_2 -> V_20 ,
L_3 ) ;
V_2 -> V_13 = true ;
return 0 ;
}
if ( V_26 -> V_15 && ! V_26 -> V_14 ) {
F_11 ( V_2 -> V_20 ,
L_4 ) ;
return - V_11 ;
}
for ( V_3 = 0 ; V_3 < V_26 -> V_14 ; V_3 ++ )
if ( V_26 -> V_15 [ V_3 ] . V_7 % V_2 -> V_12 )
return - V_11 ;
for ( V_3 = 0 ; V_3 < F_13 ( V_29 ) ; V_3 ++ )
if ( V_29 [ V_3 ] -> type == V_2 -> V_27 )
break;
if ( V_3 == F_13 ( V_29 ) ) {
F_11 ( V_2 -> V_20 , L_5 ,
V_2 -> V_27 ) ;
return - V_11 ;
}
V_2 -> V_14 = V_26 -> V_14 ;
V_2 -> V_10 = V_26 -> V_10 ;
V_2 -> V_19 = V_26 -> V_19 ;
V_2 -> V_30 = F_14 ( V_26 -> V_31 , 8 ) ;
V_2 -> V_21 = V_2 -> V_30 * V_26 -> V_10 ;
V_2 -> V_32 = NULL ;
V_2 -> V_33 = V_29 [ V_3 ] ;
if ( ! V_2 -> V_33 -> V_34 ||
! V_2 -> V_33 -> V_35 ||
! V_2 -> V_33 -> V_36 )
return - V_11 ;
if ( V_26 -> V_15 ) {
V_9 = F_15 ( V_26 -> V_15 , V_2 -> V_14 *
sizeof( struct V_16 ) , V_17 ) ;
if ( ! V_9 )
return - V_18 ;
V_2 -> V_15 = V_9 ;
} else if ( V_2 -> V_10 ) {
V_5 = F_1 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_2 -> V_13 )
return 0 ;
}
if ( ! V_2 -> V_37 )
V_2 -> V_37 = V_2 -> V_10 ;
if ( V_2 -> V_33 -> V_38 ) {
F_16 ( V_2 -> V_20 , L_6 ,
V_2 -> V_33 -> V_36 ) ;
V_5 = V_2 -> V_33 -> V_38 ( V_2 ) ;
if ( V_5 )
goto V_22;
}
return 0 ;
V_22:
F_8 ( V_2 -> V_15 ) ;
if ( V_2 -> V_23 )
F_8 ( V_2 -> V_19 ) ;
return V_5 ;
}
void F_17 ( struct V_1 * V_2 )
{
if ( V_2 -> V_27 == V_28 )
return;
F_18 ( ! V_2 -> V_33 ) ;
F_8 ( V_2 -> V_15 ) ;
if ( V_2 -> V_23 )
F_8 ( V_2 -> V_19 ) ;
if ( V_2 -> V_33 -> exit ) {
F_16 ( V_2 -> V_20 , L_7 ,
V_2 -> V_33 -> V_36 ) ;
V_2 -> V_33 -> exit ( V_2 ) ;
}
}
int F_19 ( struct V_1 * V_2 ,
unsigned int V_7 , unsigned int * V_39 )
{
int V_5 ;
if ( V_2 -> V_27 == V_28 )
return - V_40 ;
F_18 ( ! V_2 -> V_33 ) ;
if ( ! F_3 ( V_2 , V_7 ) ) {
V_5 = V_2 -> V_33 -> V_34 ( V_2 , V_7 , V_39 ) ;
if ( V_5 == 0 )
F_20 ( V_2 , V_7 , * V_39 ) ;
return V_5 ;
}
return - V_11 ;
}
int F_21 ( struct V_1 * V_2 ,
unsigned int V_7 , unsigned int V_39 )
{
if ( V_2 -> V_27 == V_28 )
return 0 ;
F_18 ( ! V_2 -> V_33 ) ;
if ( ! F_3 ( V_2 , V_7 ) )
return V_2 -> V_33 -> V_35 ( V_2 , V_7 , V_39 ) ;
return 0 ;
}
static bool F_22 ( struct V_1 * V_2 , unsigned int V_7 ,
unsigned int V_8 )
{
int V_5 ;
if ( ! V_2 -> V_41 )
return true ;
V_5 = F_23 ( V_2 , V_7 ) ;
if ( V_5 >= 0 && V_8 == V_2 -> V_15 [ V_5 ] . V_24 )
return false ;
return true ;
}
static int F_24 ( struct V_1 * V_2 , unsigned int V_42 ,
unsigned int V_43 )
{
unsigned int V_7 ;
for ( V_7 = V_42 ; V_7 <= V_43 ; V_7 += V_2 -> V_12 ) {
unsigned int V_8 ;
int V_5 ;
if ( F_3 ( V_2 , V_7 ) ||
! F_25 ( V_2 , V_7 ) )
continue;
V_5 = F_19 ( V_2 , V_7 , & V_8 ) ;
if ( V_5 )
return V_5 ;
if ( ! F_22 ( V_2 , V_7 , V_8 ) )
continue;
V_2 -> V_13 = true ;
V_5 = F_26 ( V_2 , V_7 , V_8 ) ;
V_2 -> V_13 = false ;
if ( V_5 ) {
F_11 ( V_2 -> V_20 , L_8 ,
V_7 , V_5 ) ;
return V_5 ;
}
F_16 ( V_2 -> V_20 , L_9 , V_7 , V_8 ) ;
}
return 0 ;
}
int F_27 ( struct V_1 * V_2 )
{
int V_5 = 0 ;
unsigned int V_3 ;
const char * V_36 ;
bool V_44 ;
F_18 ( ! V_2 -> V_33 ) ;
V_2 -> V_45 ( V_2 -> V_46 ) ;
V_44 = V_2 -> V_13 ;
F_16 ( V_2 -> V_20 , L_10 ,
V_2 -> V_33 -> V_36 ) ;
V_36 = V_2 -> V_33 -> V_36 ;
F_28 ( V_2 , V_36 , L_11 ) ;
if ( ! V_2 -> V_47 )
goto V_48;
V_2 -> V_49 = true ;
V_2 -> V_13 = true ;
for ( V_3 = 0 ; V_3 < V_2 -> V_50 ; V_3 ++ ) {
V_5 = F_26 ( V_2 , V_2 -> V_51 [ V_3 ] . V_7 , V_2 -> V_51 [ V_3 ] . V_24 ) ;
if ( V_5 != 0 ) {
F_11 ( V_2 -> V_20 , L_12 ,
V_2 -> V_51 [ V_3 ] . V_7 , V_2 -> V_51 [ V_3 ] . V_24 , V_5 ) ;
goto V_48;
}
}
V_2 -> V_13 = false ;
if ( V_2 -> V_33 -> V_52 )
V_5 = V_2 -> V_33 -> V_52 ( V_2 , 0 , V_2 -> V_37 ) ;
else
V_5 = F_24 ( V_2 , 0 , V_2 -> V_37 ) ;
if ( V_5 == 0 )
V_2 -> V_47 = false ;
V_48:
V_2 -> V_49 = false ;
V_2 -> V_13 = V_44 ;
V_2 -> V_41 = false ;
V_2 -> V_53 ( V_2 -> V_46 ) ;
F_29 ( V_2 ) ;
F_28 ( V_2 , V_36 , L_13 ) ;
return V_5 ;
}
int F_30 ( struct V_1 * V_2 , unsigned int V_42 ,
unsigned int V_43 )
{
int V_5 = 0 ;
const char * V_36 ;
bool V_44 ;
F_18 ( ! V_2 -> V_33 ) ;
V_2 -> V_45 ( V_2 -> V_46 ) ;
V_44 = V_2 -> V_13 ;
V_36 = V_2 -> V_33 -> V_36 ;
F_16 ( V_2 -> V_20 , L_14 , V_36 , V_42 , V_43 ) ;
F_28 ( V_2 , V_36 , L_15 ) ;
if ( ! V_2 -> V_47 )
goto V_48;
V_2 -> V_49 = true ;
if ( V_2 -> V_33 -> V_52 )
V_5 = V_2 -> V_33 -> V_52 ( V_2 , V_42 , V_43 ) ;
else
V_5 = F_24 ( V_2 , V_42 , V_43 ) ;
V_48:
V_2 -> V_13 = V_44 ;
V_2 -> V_49 = false ;
V_2 -> V_41 = false ;
V_2 -> V_53 ( V_2 -> V_46 ) ;
F_29 ( V_2 ) ;
F_28 ( V_2 , V_36 , L_16 ) ;
return V_5 ;
}
int F_31 ( struct V_1 * V_2 , unsigned int V_42 ,
unsigned int V_43 )
{
int V_5 = 0 ;
if ( ! V_2 -> V_33 || ! V_2 -> V_33 -> V_54 )
return - V_11 ;
V_2 -> V_45 ( V_2 -> V_46 ) ;
F_32 ( V_2 , V_42 , V_43 ) ;
V_5 = V_2 -> V_33 -> V_54 ( V_2 , V_42 , V_43 ) ;
V_2 -> V_53 ( V_2 -> V_46 ) ;
return V_5 ;
}
void F_33 ( struct V_1 * V_2 , bool V_55 )
{
V_2 -> V_45 ( V_2 -> V_46 ) ;
F_34 ( V_2 -> V_13 && V_55 ) ;
V_2 -> V_56 = V_55 ;
F_35 ( V_2 , V_55 ) ;
V_2 -> V_53 ( V_2 -> V_46 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
V_2 -> V_45 ( V_2 -> V_46 ) ;
V_2 -> V_47 = true ;
V_2 -> V_41 = true ;
V_2 -> V_53 ( V_2 -> V_46 ) ;
}
void F_37 ( struct V_1 * V_2 , bool V_55 )
{
V_2 -> V_45 ( V_2 -> V_46 ) ;
F_34 ( V_2 -> V_56 && V_55 ) ;
V_2 -> V_13 = V_55 ;
F_38 ( V_2 , V_55 ) ;
V_2 -> V_53 ( V_2 -> V_46 ) ;
}
bool F_39 ( struct V_1 * V_2 , void * V_57 , unsigned int V_58 ,
unsigned int V_8 )
{
if ( F_9 ( V_2 , V_57 , V_58 ) == V_8 )
return true ;
if ( V_2 -> V_59 . V_60 ) {
V_2 -> V_59 . V_60 ( V_57 + ( V_2 -> V_30 * V_58 ) ,
V_8 , 0 ) ;
return false ;
}
switch ( V_2 -> V_30 ) {
case 1 : {
T_1 * V_32 = V_57 ;
V_32 [ V_58 ] = V_8 ;
break;
}
case 2 : {
T_2 * V_32 = V_57 ;
V_32 [ V_58 ] = V_8 ;
break;
}
case 4 : {
T_3 * V_32 = V_57 ;
V_32 [ V_58 ] = V_8 ;
break;
}
#ifdef F_40
case 8 : {
T_4 * V_32 = V_57 ;
V_32 [ V_58 ] = V_8 ;
break;
}
#endif
default:
F_41 () ;
}
return false ;
}
unsigned int F_9 ( struct V_1 * V_2 , const void * V_57 ,
unsigned int V_58 )
{
if ( ! V_57 )
return - V_11 ;
if ( V_2 -> V_59 . V_61 )
return V_2 -> V_59 . V_61 ( F_42 ( V_2 , V_57 ,
V_58 ) ) ;
switch ( V_2 -> V_30 ) {
case 1 : {
const T_1 * V_32 = V_57 ;
return V_32 [ V_58 ] ;
}
case 2 : {
const T_2 * V_32 = V_57 ;
return V_32 [ V_58 ] ;
}
case 4 : {
const T_3 * V_32 = V_57 ;
return V_32 [ V_58 ] ;
}
#ifdef F_40
case 8 : {
const T_4 * V_32 = V_57 ;
return V_32 [ V_58 ] ;
}
#endif
default:
F_41 () ;
}
return - 1 ;
}
static int F_43 ( const void * V_62 , const void * V_63 )
{
const struct V_16 * V_64 = V_62 ;
const struct V_16 * V_65 = V_63 ;
return V_64 -> V_7 - V_65 -> V_7 ;
}
int F_23 ( struct V_1 * V_2 , unsigned int V_7 )
{
struct V_16 V_66 ;
struct V_16 * V_67 ;
V_66 . V_7 = V_7 ;
V_66 . V_24 = 0 ;
V_67 = bsearch ( & V_66 , V_2 -> V_15 , V_2 -> V_14 ,
sizeof( struct V_16 ) , F_43 ) ;
if ( V_67 )
return V_67 - V_2 -> V_15 ;
else
return - V_68 ;
}
static bool F_44 ( unsigned long * V_69 , unsigned int V_58 )
{
if ( ! V_69 )
return true ;
return F_45 ( V_58 , V_69 ) ;
}
static int F_46 ( struct V_1 * V_2 , void * V_70 ,
unsigned long * V_69 ,
unsigned int V_71 ,
unsigned int V_72 , unsigned int V_73 )
{
unsigned int V_3 , V_74 , V_8 ;
int V_5 ;
for ( V_3 = V_72 ; V_3 < V_73 ; V_3 ++ ) {
V_74 = V_71 + ( V_3 * V_2 -> V_12 ) ;
if ( ! F_44 ( V_69 , V_3 ) ||
! F_25 ( V_2 , V_74 ) )
continue;
V_8 = F_9 ( V_2 , V_70 , V_3 ) ;
if ( ! F_22 ( V_2 , V_74 , V_8 ) )
continue;
V_2 -> V_13 = true ;
V_5 = F_26 ( V_2 , V_74 , V_8 ) ;
V_2 -> V_13 = false ;
if ( V_5 != 0 ) {
F_11 ( V_2 -> V_20 , L_8 ,
V_74 , V_5 ) ;
return V_5 ;
}
F_16 ( V_2 -> V_20 , L_9 ,
V_74 , V_8 ) ;
}
return 0 ;
}
static int F_47 ( struct V_1 * V_2 , const void * * V_75 ,
unsigned int V_57 , unsigned int V_76 )
{
T_5 V_77 = V_2 -> V_59 . V_77 ;
int V_5 , V_6 ;
if ( * V_75 == NULL )
return 0 ;
V_6 = ( V_76 - V_57 ) / V_2 -> V_12 ;
F_16 ( V_2 -> V_20 , L_17 ,
V_6 * V_77 , V_6 , V_57 , V_76 - V_2 -> V_12 ) ;
V_2 -> V_13 = true ;
V_5 = F_48 ( V_2 , V_57 , * V_75 , V_6 * V_77 ) ;
if ( V_5 )
F_11 ( V_2 -> V_20 , L_18 ,
V_57 , V_76 - V_2 -> V_12 , V_5 ) ;
V_2 -> V_13 = false ;
* V_75 = NULL ;
return V_5 ;
}
static int F_49 ( struct V_1 * V_2 , void * V_70 ,
unsigned long * V_69 ,
unsigned int V_71 , unsigned int V_72 ,
unsigned int V_73 )
{
unsigned int V_3 , V_8 ;
unsigned int V_74 = 0 ;
unsigned int V_57 = 0 ;
const void * V_75 = NULL ;
int V_5 ;
for ( V_3 = V_72 ; V_3 < V_73 ; V_3 ++ ) {
V_74 = V_71 + ( V_3 * V_2 -> V_12 ) ;
if ( ! F_44 ( V_69 , V_3 ) ||
! F_25 ( V_2 , V_74 ) ) {
V_5 = F_47 ( V_2 , & V_75 ,
V_57 , V_74 ) ;
if ( V_5 != 0 )
return V_5 ;
continue;
}
V_8 = F_9 ( V_2 , V_70 , V_3 ) ;
if ( ! F_22 ( V_2 , V_74 , V_8 ) ) {
V_5 = F_47 ( V_2 , & V_75 ,
V_57 , V_74 ) ;
if ( V_5 != 0 )
return V_5 ;
continue;
}
if ( ! V_75 ) {
V_75 = F_42 ( V_2 , V_70 , V_3 ) ;
V_57 = V_74 ;
}
}
return F_47 ( V_2 , & V_75 , V_57 , V_74 +
V_2 -> V_12 ) ;
}
int F_50 ( struct V_1 * V_2 , void * V_70 ,
unsigned long * V_69 ,
unsigned int V_71 , unsigned int V_72 ,
unsigned int V_73 )
{
if ( F_51 ( V_2 ) && ! V_2 -> V_78 )
return F_49 ( V_2 , V_70 , V_69 ,
V_71 , V_72 , V_73 ) ;
else
return F_46 ( V_2 , V_70 , V_69 ,
V_71 , V_72 , V_73 ) ;
}
