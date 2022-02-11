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
for ( V_23 = V_41 ; V_23 <= V_42 ; V_23 ++ ) {
unsigned int V_7 ;
int V_5 ;
if ( F_7 ( V_2 , V_23 ) )
continue;
V_5 = F_16 ( V_2 , V_23 , & V_7 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_20 ( V_2 , V_23 ) ;
if ( V_5 >= 0 && V_7 == V_2 -> V_18 [ V_5 ] . V_24 )
continue;
V_2 -> V_12 = 1 ;
V_5 = F_21 ( V_2 , V_23 , V_7 ) ;
V_2 -> V_12 = 0 ;
if ( V_5 )
return V_5 ;
F_13 ( V_2 -> V_13 , L_5 , V_23 , V_7 ) ;
}
return 0 ;
}
int F_22 ( struct V_1 * V_2 )
{
int V_5 = 0 ;
unsigned int V_3 ;
const char * V_36 ;
unsigned int V_43 ;
F_15 ( ! V_2 -> V_33 ) ;
V_2 -> V_44 ( V_2 -> V_45 ) ;
V_43 = V_2 -> V_12 ;
F_13 ( V_2 -> V_13 , L_6 ,
V_2 -> V_33 -> V_36 ) ;
V_36 = V_2 -> V_33 -> V_36 ;
F_23 ( V_2 -> V_13 , V_36 , L_7 ) ;
if ( ! V_2 -> V_46 )
goto V_47;
V_2 -> V_12 = 1 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_48 ; V_3 ++ ) {
if ( V_2 -> V_49 [ V_3 ] . V_23 % V_2 -> V_17 ) {
V_5 = - V_10 ;
goto V_47;
}
V_5 = F_21 ( V_2 , V_2 -> V_49 [ V_3 ] . V_23 , V_2 -> V_49 [ V_3 ] . V_24 ) ;
if ( V_5 != 0 ) {
F_10 ( V_2 -> V_13 , L_8 ,
V_2 -> V_49 [ V_3 ] . V_23 , V_2 -> V_49 [ V_3 ] . V_24 , V_5 ) ;
goto V_47;
}
}
V_2 -> V_12 = 0 ;
if ( V_2 -> V_33 -> V_50 )
V_5 = V_2 -> V_33 -> V_50 ( V_2 , 0 , V_2 -> V_37 ) ;
else
V_5 = F_19 ( V_2 , 0 , V_2 -> V_37 ) ;
if ( V_5 == 0 )
V_2 -> V_46 = false ;
V_47:
F_23 ( V_2 -> V_13 , V_36 , L_9 ) ;
V_2 -> V_12 = V_43 ;
V_2 -> V_51 ( V_2 -> V_45 ) ;
return V_5 ;
}
int F_24 ( struct V_1 * V_2 , unsigned int V_41 ,
unsigned int V_42 )
{
int V_5 = 0 ;
const char * V_36 ;
unsigned int V_43 ;
F_15 ( ! V_2 -> V_33 ) ;
V_2 -> V_44 ( V_2 -> V_45 ) ;
V_43 = V_2 -> V_12 ;
V_36 = V_2 -> V_33 -> V_36 ;
F_13 ( V_2 -> V_13 , L_10 , V_36 , V_41 , V_42 ) ;
F_23 ( V_2 -> V_13 , V_36 , L_11 ) ;
if ( ! V_2 -> V_46 )
goto V_47;
if ( V_2 -> V_33 -> V_50 )
V_5 = V_2 -> V_33 -> V_50 ( V_2 , V_41 , V_42 ) ;
else
V_5 = F_19 ( V_2 , V_41 , V_42 ) ;
V_47:
F_23 ( V_2 -> V_13 , V_36 , L_12 ) ;
V_2 -> V_12 = V_43 ;
V_2 -> V_51 ( V_2 -> V_45 ) ;
return V_5 ;
}
int F_25 ( struct V_1 * V_2 , unsigned int V_41 ,
unsigned int V_42 )
{
int V_5 = 0 ;
if ( ! V_2 -> V_33 || ! V_2 -> V_33 -> V_52 )
return - V_10 ;
V_2 -> V_44 ( V_2 -> V_45 ) ;
F_26 ( V_2 -> V_13 , V_41 , V_42 ) ;
V_5 = V_2 -> V_33 -> V_52 ( V_2 , V_41 , V_42 ) ;
V_2 -> V_51 ( V_2 -> V_45 ) ;
return V_5 ;
}
void F_27 ( struct V_1 * V_2 , bool V_53 )
{
V_2 -> V_44 ( V_2 -> V_45 ) ;
F_28 ( V_2 -> V_12 && V_53 ) ;
V_2 -> V_54 = V_53 ;
F_29 ( V_2 -> V_13 , V_53 ) ;
V_2 -> V_51 ( V_2 -> V_45 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
V_2 -> V_44 ( V_2 -> V_45 ) ;
V_2 -> V_46 = true ;
V_2 -> V_51 ( V_2 -> V_45 ) ;
}
void F_31 ( struct V_1 * V_2 , bool V_53 )
{
V_2 -> V_44 ( V_2 -> V_45 ) ;
F_28 ( V_2 -> V_54 && V_53 ) ;
V_2 -> V_12 = V_53 ;
F_32 ( V_2 -> V_13 , V_53 ) ;
V_2 -> V_51 ( V_2 -> V_45 ) ;
}
bool F_33 ( struct V_1 * V_2 , void * V_55 , unsigned int V_56 ,
unsigned int V_7 )
{
if ( F_6 ( V_2 , V_55 , V_56 ) == V_7 )
return true ;
if ( V_2 -> V_57 . V_58 ) {
V_2 -> V_57 . V_58 ( V_55 + ( V_2 -> V_30 * V_56 ) ,
V_7 , 0 ) ;
return false ;
}
switch ( V_2 -> V_30 ) {
case 1 : {
T_2 * V_32 = V_55 ;
V_32 [ V_56 ] = V_7 ;
break;
}
case 2 : {
T_3 * V_32 = V_55 ;
V_32 [ V_56 ] = V_7 ;
break;
}
case 4 : {
T_1 * V_32 = V_55 ;
V_32 [ V_56 ] = V_7 ;
break;
}
default:
F_34 () ;
}
return false ;
}
unsigned int F_6 ( struct V_1 * V_2 , const void * V_55 ,
unsigned int V_56 )
{
if ( ! V_55 )
return - V_10 ;
if ( V_2 -> V_57 . V_59 )
return V_2 -> V_57 . V_59 ( F_35 ( V_2 , V_55 ,
V_56 ) ) ;
switch ( V_2 -> V_30 ) {
case 1 : {
const T_2 * V_32 = V_55 ;
return V_32 [ V_56 ] ;
}
case 2 : {
const T_3 * V_32 = V_55 ;
return V_32 [ V_56 ] ;
}
case 4 : {
const T_1 * V_32 = V_55 ;
return V_32 [ V_56 ] ;
}
default:
F_34 () ;
}
return - 1 ;
}
static int F_36 ( const void * V_60 , const void * V_61 )
{
const struct V_19 * V_62 = V_60 ;
const struct V_19 * V_63 = V_61 ;
return V_62 -> V_23 - V_63 -> V_23 ;
}
int F_20 ( struct V_1 * V_2 , unsigned int V_23 )
{
struct V_19 V_64 ;
struct V_19 * V_65 ;
V_64 . V_23 = V_23 ;
V_64 . V_24 = 0 ;
V_65 = bsearch ( & V_64 , V_2 -> V_18 , V_2 -> V_22 ,
sizeof( struct V_19 ) , F_36 ) ;
if ( V_65 )
return V_65 - V_2 -> V_18 ;
else
return - V_66 ;
}
static bool F_37 ( unsigned long * V_67 , unsigned int V_56 )
{
if ( ! V_67 )
return true ;
return F_38 ( V_56 , V_67 ) ;
}
static int F_39 ( struct V_1 * V_2 , void * V_68 ,
unsigned long * V_67 ,
unsigned int V_69 ,
unsigned int V_70 , unsigned int V_71 )
{
unsigned int V_3 , V_72 , V_7 ;
int V_5 ;
for ( V_3 = V_70 ; V_3 < V_71 ; V_3 ++ ) {
V_72 = V_69 + ( V_3 * V_2 -> V_17 ) ;
if ( ! F_37 ( V_67 , V_3 ) )
continue;
V_7 = F_6 ( V_2 , V_68 , V_3 ) ;
V_5 = F_20 ( V_2 , V_72 ) ;
if ( V_5 >= 0 && V_7 == V_2 -> V_18 [ V_5 ] . V_24 )
continue;
V_2 -> V_12 = 1 ;
V_5 = F_21 ( V_2 , V_72 , V_7 ) ;
V_2 -> V_12 = 0 ;
if ( V_5 != 0 )
return V_5 ;
F_13 ( V_2 -> V_13 , L_5 ,
V_72 , V_7 ) ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , const void * * V_73 ,
unsigned int V_55 , unsigned int V_74 )
{
T_4 V_75 = V_2 -> V_57 . V_75 ;
int V_5 , V_6 ;
if ( * V_73 == NULL )
return 0 ;
V_6 = V_74 - V_55 ;
F_13 ( V_2 -> V_13 , L_13 ,
V_6 * V_75 , V_6 , V_55 , V_74 - 1 ) ;
V_2 -> V_12 = 1 ;
V_5 = F_41 ( V_2 , V_55 , * V_73 , V_6 * V_75 ,
false ) ;
V_2 -> V_12 = 0 ;
* V_73 = NULL ;
return V_5 ;
}
static int F_42 ( struct V_1 * V_2 , void * V_68 ,
unsigned long * V_67 ,
unsigned int V_69 , unsigned int V_70 ,
unsigned int V_71 )
{
unsigned int V_3 , V_7 ;
unsigned int V_72 = 0 ;
unsigned int V_55 = 0 ;
const void * V_73 = NULL ;
int V_5 ;
for ( V_3 = V_70 ; V_3 < V_71 ; V_3 ++ ) {
V_72 = V_69 + ( V_3 * V_2 -> V_17 ) ;
if ( ! F_37 ( V_67 , V_3 ) ) {
V_5 = F_40 ( V_2 , & V_73 ,
V_55 , V_72 ) ;
if ( V_5 != 0 )
return V_5 ;
continue;
}
V_7 = F_6 ( V_2 , V_68 , V_3 ) ;
V_5 = F_20 ( V_2 , V_72 ) ;
if ( V_5 >= 0 && V_7 == V_2 -> V_18 [ V_5 ] . V_24 ) {
V_5 = F_40 ( V_2 , & V_73 ,
V_55 , V_72 ) ;
if ( V_5 != 0 )
return V_5 ;
continue;
}
if ( ! V_73 ) {
V_73 = F_35 ( V_2 , V_68 , V_3 ) ;
V_55 = V_72 ;
}
}
return F_40 ( V_2 , & V_73 , V_55 , V_72 +
V_2 -> V_17 ) ;
}
int F_43 ( struct V_1 * V_2 , void * V_68 ,
unsigned long * V_67 ,
unsigned int V_69 , unsigned int V_70 ,
unsigned int V_71 )
{
if ( F_44 ( V_2 ) )
return F_42 ( V_2 , V_68 , V_67 ,
V_69 , V_70 , V_71 ) ;
else
return F_39 ( V_2 , V_68 , V_67 ,
V_69 , V_70 , V_71 ) ;
}
