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
V_7 = F_6 ( V_2 -> V_11 ,
V_3 , V_2 -> V_17 ) ;
if ( F_7 ( V_2 , V_3 * V_2 -> V_18 ) )
continue;
V_6 ++ ;
}
V_2 -> V_19 = F_3 ( V_6 * sizeof( struct V_20 ) ,
V_15 ) ;
if ( ! V_2 -> V_19 ) {
V_5 = - V_21 ;
goto V_22;
}
V_2 -> V_23 = V_6 ;
for ( V_3 = 0 , V_4 = 0 ; V_3 < V_2 -> V_9 ; V_3 ++ ) {
V_7 = F_6 ( V_2 -> V_11 ,
V_3 , V_2 -> V_17 ) ;
if ( F_7 ( V_2 , V_3 * V_2 -> V_18 ) )
continue;
V_2 -> V_19 [ V_4 ] . V_24 = V_3 * V_2 -> V_18 ;
V_2 -> V_19 [ V_4 ] . V_25 = V_7 ;
V_4 ++ ;
}
return 0 ;
V_22:
if ( V_2 -> V_16 )
F_5 ( V_2 -> V_11 ) ;
return V_5 ;
}
int F_8 ( struct V_1 * V_2 , const struct V_26 * V_27 )
{
int V_5 ;
int V_3 ;
void * V_8 ;
for ( V_3 = 0 ; V_3 < V_27 -> V_23 ; V_3 ++ )
if ( V_27 -> V_19 [ V_3 ] . V_24 % V_2 -> V_18 )
return - V_10 ;
if ( V_2 -> V_28 == V_29 ) {
V_2 -> V_12 = true ;
return 0 ;
}
for ( V_3 = 0 ; V_3 < F_9 ( V_30 ) ; V_3 ++ )
if ( V_30 [ V_3 ] -> type == V_2 -> V_28 )
break;
if ( V_3 == F_9 ( V_30 ) ) {
F_10 ( V_2 -> V_13 , L_2 ,
V_2 -> V_28 ) ;
return - V_10 ;
}
V_2 -> V_23 = V_27 -> V_23 ;
V_2 -> V_9 = V_27 -> V_9 ;
V_2 -> V_11 = V_27 -> V_11 ;
V_2 -> V_17 = F_11 ( V_27 -> V_31 , 8 ) ;
V_2 -> V_14 = V_2 -> V_17 * V_27 -> V_9 ;
V_2 -> V_32 = NULL ;
V_2 -> V_33 = V_30 [ V_3 ] ;
if ( ! V_2 -> V_33 -> V_34 ||
! V_2 -> V_33 -> V_35 ||
! V_2 -> V_33 -> V_36 )
return - V_10 ;
if ( V_27 -> V_19 ) {
if ( ! V_2 -> V_23 )
return - V_10 ;
V_8 = F_12 ( V_27 -> V_19 , V_2 -> V_23 *
sizeof( struct V_20 ) , V_15 ) ;
if ( ! V_8 )
return - V_21 ;
V_2 -> V_19 = V_8 ;
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
goto V_22;
}
return 0 ;
V_22:
F_5 ( V_2 -> V_19 ) ;
if ( V_2 -> V_16 )
F_5 ( V_2 -> V_11 ) ;
return V_5 ;
}
void F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_28 == V_29 )
return;
F_15 ( ! V_2 -> V_33 ) ;
F_5 ( V_2 -> V_19 ) ;
if ( V_2 -> V_16 )
F_5 ( V_2 -> V_11 ) ;
if ( V_2 -> V_33 -> exit ) {
F_13 ( V_2 -> V_13 , L_4 ,
V_2 -> V_33 -> V_36 ) ;
V_2 -> V_33 -> exit ( V_2 ) ;
}
}
int F_16 ( struct V_1 * V_2 ,
unsigned int V_24 , unsigned int * V_39 )
{
int V_5 ;
if ( V_2 -> V_28 == V_29 )
return - V_40 ;
F_15 ( ! V_2 -> V_33 ) ;
if ( ! F_7 ( V_2 , V_24 ) ) {
V_5 = V_2 -> V_33 -> V_34 ( V_2 , V_24 , V_39 ) ;
if ( V_5 == 0 )
F_17 ( V_2 -> V_13 , V_24 , * V_39 ) ;
return V_5 ;
}
return - V_10 ;
}
int F_18 ( struct V_1 * V_2 ,
unsigned int V_24 , unsigned int V_39 )
{
if ( V_2 -> V_28 == V_29 )
return 0 ;
F_15 ( ! V_2 -> V_33 ) ;
if ( ! F_19 ( V_2 , V_24 ) )
return - V_41 ;
if ( ! F_7 ( V_2 , V_24 ) )
return V_2 -> V_33 -> V_35 ( V_2 , V_24 , V_39 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 )
{
int V_5 = 0 ;
unsigned int V_3 ;
const char * V_36 ;
unsigned int V_42 ;
F_15 ( ! V_2 -> V_33 || ! V_2 -> V_33 -> V_43 ) ;
V_2 -> V_44 ( V_2 ) ;
V_42 = V_2 -> V_12 ;
F_13 ( V_2 -> V_13 , L_5 ,
V_2 -> V_33 -> V_36 ) ;
V_36 = V_2 -> V_33 -> V_36 ;
F_21 ( V_2 -> V_13 , V_36 , L_6 ) ;
if ( ! V_2 -> V_45 )
goto V_46;
V_2 -> V_12 = 1 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_47 ; V_3 ++ ) {
if ( V_2 -> V_48 [ V_3 ] . V_24 % V_2 -> V_18 ) {
V_5 = - V_10 ;
goto V_46;
}
V_5 = F_22 ( V_2 , V_2 -> V_48 [ V_3 ] . V_24 , V_2 -> V_48 [ V_3 ] . V_25 ) ;
if ( V_5 != 0 ) {
F_10 ( V_2 -> V_13 , L_7 ,
V_2 -> V_48 [ V_3 ] . V_24 , V_2 -> V_48 [ V_3 ] . V_25 , V_5 ) ;
goto V_46;
}
}
V_2 -> V_12 = 0 ;
V_5 = V_2 -> V_33 -> V_43 ( V_2 , 0 , V_2 -> V_37 ) ;
if ( V_5 == 0 )
V_2 -> V_45 = false ;
V_46:
F_21 ( V_2 -> V_13 , V_36 , L_8 ) ;
V_2 -> V_12 = V_42 ;
V_2 -> V_49 ( V_2 ) ;
return V_5 ;
}
int F_23 ( struct V_1 * V_2 , unsigned int V_50 ,
unsigned int V_51 )
{
int V_5 = 0 ;
const char * V_36 ;
unsigned int V_42 ;
F_15 ( ! V_2 -> V_33 || ! V_2 -> V_33 -> V_43 ) ;
V_2 -> V_44 ( V_2 ) ;
V_42 = V_2 -> V_12 ;
V_36 = V_2 -> V_33 -> V_36 ;
F_13 ( V_2 -> V_13 , L_9 , V_36 , V_50 , V_51 ) ;
F_21 ( V_2 -> V_13 , V_36 , L_10 ) ;
if ( ! V_2 -> V_45 )
goto V_46;
V_5 = V_2 -> V_33 -> V_43 ( V_2 , V_50 , V_51 ) ;
V_46:
F_21 ( V_2 -> V_13 , V_36 , L_11 ) ;
V_2 -> V_12 = V_42 ;
V_2 -> V_49 ( V_2 ) ;
return V_5 ;
}
void F_24 ( struct V_1 * V_2 , bool V_52 )
{
V_2 -> V_44 ( V_2 ) ;
F_25 ( V_2 -> V_12 && V_52 ) ;
V_2 -> V_53 = V_52 ;
F_26 ( V_2 -> V_13 , V_52 ) ;
V_2 -> V_49 ( V_2 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
V_2 -> V_44 ( V_2 ) ;
V_2 -> V_45 = true ;
V_2 -> V_49 ( V_2 ) ;
}
void F_28 ( struct V_1 * V_2 , bool V_52 )
{
V_2 -> V_44 ( V_2 ) ;
F_25 ( V_2 -> V_53 && V_52 ) ;
V_2 -> V_12 = V_52 ;
F_29 ( V_2 -> V_13 , V_52 ) ;
V_2 -> V_49 ( V_2 ) ;
}
bool F_30 ( void * V_54 , unsigned int V_55 ,
unsigned int V_7 , unsigned int V_56 )
{
switch ( V_56 ) {
case 1 : {
T_2 * V_32 = V_54 ;
if ( V_32 [ V_55 ] == V_7 )
return true ;
V_32 [ V_55 ] = V_7 ;
break;
}
case 2 : {
T_3 * V_32 = V_54 ;
if ( V_32 [ V_55 ] == V_7 )
return true ;
V_32 [ V_55 ] = V_7 ;
break;
}
case 4 : {
T_1 * V_32 = V_54 ;
if ( V_32 [ V_55 ] == V_7 )
return true ;
V_32 [ V_55 ] = V_7 ;
break;
}
default:
F_31 () ;
}
return false ;
}
unsigned int F_6 ( const void * V_54 , unsigned int V_55 ,
unsigned int V_56 )
{
if ( ! V_54 )
return - V_10 ;
switch ( V_56 ) {
case 1 : {
const T_2 * V_32 = V_54 ;
return V_32 [ V_55 ] ;
}
case 2 : {
const T_3 * V_32 = V_54 ;
return V_32 [ V_55 ] ;
}
case 4 : {
const T_1 * V_32 = V_54 ;
return V_32 [ V_55 ] ;
}
default:
F_31 () ;
}
return - 1 ;
}
static int F_32 ( const void * V_57 , const void * V_58 )
{
const struct V_20 * V_59 = V_57 ;
const struct V_20 * V_60 = V_58 ;
return V_59 -> V_24 - V_60 -> V_24 ;
}
int F_33 ( struct V_1 * V_2 , unsigned int V_24 )
{
struct V_20 V_61 ;
struct V_20 * V_62 ;
V_61 . V_24 = V_24 ;
V_61 . V_25 = 0 ;
V_62 = bsearch ( & V_61 , V_2 -> V_19 , V_2 -> V_23 ,
sizeof( struct V_20 ) , F_32 ) ;
if ( V_62 )
return V_62 - V_2 -> V_19 ;
else
return - V_63 ;
}
