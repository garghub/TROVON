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
V_2 -> V_33 = 0 ;
V_2 -> V_34 = NULL ;
V_2 -> V_35 = V_29 [ V_3 ] ;
if ( ! V_2 -> V_35 -> V_36 ||
! V_2 -> V_35 -> V_37 ||
! V_2 -> V_35 -> V_38 )
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
if ( ! V_2 -> V_39 )
V_2 -> V_39 = V_2 -> V_9 ;
if ( V_2 -> V_35 -> V_40 ) {
F_13 ( V_2 -> V_13 , L_3 ,
V_2 -> V_35 -> V_38 ) ;
V_5 = V_2 -> V_35 -> V_40 ( V_2 ) ;
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
F_15 ( ! V_2 -> V_35 ) ;
F_5 ( V_2 -> V_32 ) ;
F_5 ( V_2 -> V_18 ) ;
if ( V_2 -> V_16 )
F_5 ( V_2 -> V_11 ) ;
if ( V_2 -> V_35 -> exit ) {
F_13 ( V_2 -> V_13 , L_4 ,
V_2 -> V_35 -> V_38 ) ;
V_2 -> V_35 -> exit ( V_2 ) ;
}
}
int F_16 ( struct V_1 * V_2 ,
unsigned int V_23 , unsigned int * V_41 )
{
int V_5 ;
if ( V_2 -> V_27 == V_28 )
return - V_42 ;
F_15 ( ! V_2 -> V_35 ) ;
if ( ! F_7 ( V_2 , V_23 ) ) {
V_5 = V_2 -> V_35 -> V_36 ( V_2 , V_23 , V_41 ) ;
if ( V_5 == 0 )
F_17 ( V_2 -> V_13 , V_23 , * V_41 ) ;
return V_5 ;
}
return - V_10 ;
}
int F_18 ( struct V_1 * V_2 ,
unsigned int V_23 , unsigned int V_41 )
{
if ( V_2 -> V_27 == V_28 )
return 0 ;
F_15 ( ! V_2 -> V_35 ) ;
if ( ! F_19 ( V_2 , V_23 ) )
return - V_43 ;
if ( ! F_7 ( V_2 , V_23 ) )
return V_2 -> V_35 -> V_37 ( V_2 , V_23 , V_41 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 )
{
int V_5 = 0 ;
unsigned int V_3 ;
const char * V_38 ;
unsigned int V_44 ;
F_15 ( ! V_2 -> V_35 || ! V_2 -> V_35 -> V_45 ) ;
V_2 -> V_46 ( V_2 -> V_47 ) ;
V_44 = V_2 -> V_12 ;
F_13 ( V_2 -> V_13 , L_5 ,
V_2 -> V_35 -> V_38 ) ;
V_38 = V_2 -> V_35 -> V_38 ;
F_21 ( V_2 -> V_13 , V_38 , L_6 ) ;
if ( ! V_2 -> V_48 )
goto V_49;
V_2 -> V_12 = 1 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_50 ; V_3 ++ ) {
if ( V_2 -> V_51 [ V_3 ] . V_23 % V_2 -> V_17 ) {
V_5 = - V_10 ;
goto V_49;
}
V_5 = F_22 ( V_2 , V_2 -> V_51 [ V_3 ] . V_23 , V_2 -> V_51 [ V_3 ] . V_24 ) ;
if ( V_5 != 0 ) {
F_10 ( V_2 -> V_13 , L_7 ,
V_2 -> V_51 [ V_3 ] . V_23 , V_2 -> V_51 [ V_3 ] . V_24 , V_5 ) ;
goto V_49;
}
}
V_2 -> V_12 = 0 ;
V_5 = V_2 -> V_35 -> V_45 ( V_2 , 0 , V_2 -> V_39 ) ;
if ( V_5 == 0 )
V_2 -> V_48 = false ;
V_49:
F_21 ( V_2 -> V_13 , V_38 , L_8 ) ;
V_2 -> V_12 = V_44 ;
V_2 -> V_52 ( V_2 -> V_47 ) ;
return V_5 ;
}
int F_23 ( struct V_1 * V_2 , unsigned int V_53 ,
unsigned int V_54 )
{
int V_5 = 0 ;
const char * V_38 ;
unsigned int V_44 ;
F_15 ( ! V_2 -> V_35 || ! V_2 -> V_35 -> V_45 ) ;
V_2 -> V_46 ( V_2 -> V_47 ) ;
V_44 = V_2 -> V_12 ;
V_38 = V_2 -> V_35 -> V_38 ;
F_13 ( V_2 -> V_13 , L_9 , V_38 , V_53 , V_54 ) ;
F_21 ( V_2 -> V_13 , V_38 , L_10 ) ;
if ( ! V_2 -> V_48 )
goto V_49;
V_5 = V_2 -> V_35 -> V_45 ( V_2 , V_53 , V_54 ) ;
V_49:
F_21 ( V_2 -> V_13 , V_38 , L_11 ) ;
V_2 -> V_12 = V_44 ;
V_2 -> V_52 ( V_2 -> V_47 ) ;
return V_5 ;
}
void F_24 ( struct V_1 * V_2 , bool V_55 )
{
V_2 -> V_46 ( V_2 -> V_47 ) ;
F_25 ( V_2 -> V_12 && V_55 ) ;
V_2 -> V_56 = V_55 ;
F_26 ( V_2 -> V_13 , V_55 ) ;
V_2 -> V_52 ( V_2 -> V_47 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
V_2 -> V_46 ( V_2 -> V_47 ) ;
V_2 -> V_48 = true ;
V_2 -> V_52 ( V_2 -> V_47 ) ;
}
void F_28 ( struct V_1 * V_2 , bool V_55 )
{
V_2 -> V_46 ( V_2 -> V_47 ) ;
F_25 ( V_2 -> V_56 && V_55 ) ;
V_2 -> V_12 = V_55 ;
F_29 ( V_2 -> V_13 , V_55 ) ;
V_2 -> V_52 ( V_2 -> V_47 ) ;
}
int F_30 ( struct V_1 * V_2 , unsigned int V_23 )
{
unsigned long * V_32 ;
unsigned int V_57 ;
unsigned int V_58 ;
int V_3 ;
V_58 = V_23 + 1 ;
V_57 = F_31 ( V_58 ) ;
V_57 *= sizeof( long ) ;
if ( ! V_2 -> V_32 ) {
V_32 = F_3 ( V_57 , V_15 ) ;
if ( ! V_32 )
return - V_20 ;
F_32 ( V_32 , V_58 ) ;
V_2 -> V_32 = V_32 ;
V_2 -> V_33 = V_58 ;
}
if ( V_58 > V_2 -> V_33 ) {
V_32 = F_33 ( V_2 -> V_32 ,
V_57 , V_15 ) ;
if ( ! V_32 )
return - V_20 ;
for ( V_3 = 0 ; V_3 < V_58 ; V_3 ++ )
if ( V_3 >= V_2 -> V_33 )
F_34 ( V_3 , V_32 ) ;
V_2 -> V_32 = V_32 ;
V_2 -> V_33 = V_58 ;
}
F_35 ( V_23 , V_2 -> V_32 ) ;
return 0 ;
}
bool F_36 ( struct V_1 * V_2 , void * V_59 , unsigned int V_60 ,
unsigned int V_7 )
{
if ( F_6 ( V_2 , V_59 , V_60 ) == V_7 )
return true ;
if ( V_2 -> V_61 . V_62 ) {
V_2 -> V_61 . V_62 ( V_59 + ( V_2 -> V_30 * V_60 ) ,
V_7 , 0 ) ;
return false ;
}
switch ( V_2 -> V_30 ) {
case 1 : {
T_2 * V_34 = V_59 ;
V_34 [ V_60 ] = V_7 ;
break;
}
case 2 : {
T_3 * V_34 = V_59 ;
V_34 [ V_60 ] = V_7 ;
break;
}
case 4 : {
T_1 * V_34 = V_59 ;
V_34 [ V_60 ] = V_7 ;
break;
}
default:
F_37 () ;
}
return false ;
}
unsigned int F_6 ( struct V_1 * V_2 , const void * V_59 ,
unsigned int V_60 )
{
if ( ! V_59 )
return - V_10 ;
if ( V_2 -> V_61 . V_63 )
return V_2 -> V_61 . V_63 ( F_38 ( V_2 , V_59 ,
V_60 ) ) ;
switch ( V_2 -> V_30 ) {
case 1 : {
const T_2 * V_34 = V_59 ;
return V_34 [ V_60 ] ;
}
case 2 : {
const T_3 * V_34 = V_59 ;
return V_34 [ V_60 ] ;
}
case 4 : {
const T_1 * V_34 = V_59 ;
return V_34 [ V_60 ] ;
}
default:
F_37 () ;
}
return - 1 ;
}
static int F_39 ( const void * V_64 , const void * V_65 )
{
const struct V_19 * V_66 = V_64 ;
const struct V_19 * V_67 = V_65 ;
return V_66 -> V_23 - V_67 -> V_23 ;
}
int F_40 ( struct V_1 * V_2 , unsigned int V_23 )
{
struct V_19 V_68 ;
struct V_19 * V_69 ;
V_68 . V_23 = V_23 ;
V_68 . V_24 = 0 ;
V_69 = bsearch ( & V_68 , V_2 -> V_18 , V_2 -> V_22 ,
sizeof( struct V_19 ) , F_39 ) ;
if ( V_69 )
return V_69 - V_2 -> V_18 ;
else
return - V_70 ;
}
static int F_41 ( struct V_1 * V_2 , void * V_71 ,
unsigned int V_72 ,
unsigned int V_73 , unsigned int V_74 )
{
unsigned int V_3 , V_75 , V_7 ;
int V_5 ;
for ( V_3 = V_73 ; V_3 < V_74 ; V_3 ++ ) {
V_75 = V_72 + ( V_3 * V_2 -> V_17 ) ;
if ( ! F_42 ( V_2 , V_75 ) )
continue;
V_7 = F_6 ( V_2 , V_71 , V_3 ) ;
V_5 = F_40 ( V_2 , V_75 ) ;
if ( V_5 >= 0 && V_7 == V_2 -> V_18 [ V_5 ] . V_24 )
continue;
V_2 -> V_12 = 1 ;
V_5 = F_22 ( V_2 , V_75 , V_7 ) ;
V_2 -> V_12 = 0 ;
if ( V_5 != 0 )
return V_5 ;
F_13 ( V_2 -> V_13 , L_12 ,
V_75 , V_7 ) ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 , const void * * V_76 ,
unsigned int V_59 , unsigned int V_77 )
{
T_4 V_78 = V_2 -> V_61 . V_78 ;
int V_5 , V_6 ;
if ( * V_76 == NULL )
return 0 ;
V_6 = V_77 - V_59 ;
F_13 ( V_2 -> V_13 , L_13 ,
V_6 * V_78 , V_6 , V_59 , V_77 - 1 ) ;
V_2 -> V_12 = 1 ;
V_5 = F_44 ( V_2 , V_59 , * V_76 , V_6 * V_78 ,
false ) ;
V_2 -> V_12 = 0 ;
* V_76 = NULL ;
return V_5 ;
}
static int F_45 ( struct V_1 * V_2 , void * V_71 ,
unsigned int V_72 , unsigned int V_73 ,
unsigned int V_74 )
{
unsigned int V_3 , V_7 ;
unsigned int V_75 = 0 ;
unsigned int V_59 = 0 ;
const void * V_76 = NULL ;
int V_5 ;
for ( V_3 = V_73 ; V_3 < V_74 ; V_3 ++ ) {
V_75 = V_72 + ( V_3 * V_2 -> V_17 ) ;
if ( ! F_42 ( V_2 , V_75 ) ) {
V_5 = F_43 ( V_2 , & V_76 ,
V_59 , V_75 ) ;
if ( V_5 != 0 )
return V_5 ;
continue;
}
V_7 = F_6 ( V_2 , V_71 , V_3 ) ;
V_5 = F_40 ( V_2 , V_75 ) ;
if ( V_5 >= 0 && V_7 == V_2 -> V_18 [ V_5 ] . V_24 ) {
V_5 = F_43 ( V_2 , & V_76 ,
V_59 , V_75 ) ;
if ( V_5 != 0 )
return V_5 ;
continue;
}
if ( ! V_76 ) {
V_76 = F_38 ( V_2 , V_71 , V_3 ) ;
V_59 = V_75 ;
}
}
return F_43 ( V_2 , & V_76 , V_59 , V_75 ) ;
}
int F_46 ( struct V_1 * V_2 , void * V_71 ,
unsigned int V_72 , unsigned int V_73 ,
unsigned int V_74 )
{
if ( F_47 ( V_2 ) )
return F_45 ( V_2 , V_71 , V_72 ,
V_73 , V_74 ) ;
else
return F_41 ( V_2 , V_71 , V_72 ,
V_73 , V_74 ) ;
}
