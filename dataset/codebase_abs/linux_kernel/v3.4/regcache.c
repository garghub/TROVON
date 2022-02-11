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
if ( F_7 ( V_2 , V_3 ) )
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
V_7 = F_6 ( V_2 -> V_11 ,
V_3 , V_2 -> V_17 ) ;
if ( F_7 ( V_2 , V_3 ) )
continue;
V_2 -> V_18 [ V_4 ] . V_23 = V_3 ;
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
V_2 -> V_17 = F_11 ( V_26 -> V_30 , 8 ) ;
V_2 -> V_14 = V_2 -> V_17 * V_26 -> V_9 ;
V_2 -> V_31 = NULL ;
V_2 -> V_32 = V_29 [ V_3 ] ;
if ( ! V_2 -> V_32 -> V_33 ||
! V_2 -> V_32 -> V_34 ||
! V_2 -> V_32 -> V_35 )
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
if ( ! V_2 -> V_36 )
V_2 -> V_36 = V_2 -> V_9 ;
if ( V_2 -> V_32 -> V_37 ) {
F_13 ( V_2 -> V_13 , L_3 ,
V_2 -> V_32 -> V_35 ) ;
V_5 = V_2 -> V_32 -> V_37 ( V_2 ) ;
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
F_15 ( ! V_2 -> V_32 ) ;
F_5 ( V_2 -> V_18 ) ;
if ( V_2 -> V_16 )
F_5 ( V_2 -> V_11 ) ;
if ( V_2 -> V_32 -> exit ) {
F_13 ( V_2 -> V_13 , L_4 ,
V_2 -> V_32 -> V_35 ) ;
V_2 -> V_32 -> exit ( V_2 ) ;
}
}
int F_16 ( struct V_1 * V_2 ,
unsigned int V_23 , unsigned int * V_38 )
{
int V_5 ;
if ( V_2 -> V_27 == V_28 )
return - V_39 ;
F_15 ( ! V_2 -> V_32 ) ;
if ( ! F_7 ( V_2 , V_23 ) ) {
V_5 = V_2 -> V_32 -> V_33 ( V_2 , V_23 , V_38 ) ;
if ( V_5 == 0 )
F_17 ( V_2 -> V_13 , V_23 , * V_38 ) ;
return V_5 ;
}
return - V_10 ;
}
int F_18 ( struct V_1 * V_2 ,
unsigned int V_23 , unsigned int V_38 )
{
if ( V_2 -> V_27 == V_28 )
return 0 ;
F_15 ( ! V_2 -> V_32 ) ;
if ( ! F_19 ( V_2 , V_23 ) )
return - V_40 ;
if ( ! F_7 ( V_2 , V_23 ) )
return V_2 -> V_32 -> V_34 ( V_2 , V_23 , V_38 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 )
{
int V_5 = 0 ;
unsigned int V_3 ;
const char * V_35 ;
unsigned int V_41 ;
F_15 ( ! V_2 -> V_32 || ! V_2 -> V_32 -> V_42 ) ;
F_21 ( & V_2 -> V_43 ) ;
V_41 = V_2 -> V_12 ;
F_13 ( V_2 -> V_13 , L_5 ,
V_2 -> V_32 -> V_35 ) ;
V_35 = V_2 -> V_32 -> V_35 ;
F_22 ( V_2 -> V_13 , V_35 , L_6 ) ;
if ( ! V_2 -> V_44 )
goto V_45;
V_2 -> V_12 = 1 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_46 ; V_3 ++ ) {
V_5 = F_23 ( V_2 , V_2 -> V_47 [ V_3 ] . V_23 , V_2 -> V_47 [ V_3 ] . V_24 ) ;
if ( V_5 != 0 ) {
F_10 ( V_2 -> V_13 , L_7 ,
V_2 -> V_47 [ V_3 ] . V_23 , V_2 -> V_47 [ V_3 ] . V_24 , V_5 ) ;
goto V_45;
}
}
V_2 -> V_12 = 0 ;
V_5 = V_2 -> V_32 -> V_42 ( V_2 , 0 , V_2 -> V_36 ) ;
if ( V_5 == 0 )
V_2 -> V_44 = false ;
V_45:
F_22 ( V_2 -> V_13 , V_35 , L_8 ) ;
V_2 -> V_12 = V_41 ;
F_24 ( & V_2 -> V_43 ) ;
return V_5 ;
}
int F_25 ( struct V_1 * V_2 , unsigned int V_48 ,
unsigned int V_49 )
{
int V_5 = 0 ;
const char * V_35 ;
unsigned int V_41 ;
F_15 ( ! V_2 -> V_32 || ! V_2 -> V_32 -> V_42 ) ;
F_21 ( & V_2 -> V_43 ) ;
V_41 = V_2 -> V_12 ;
V_35 = V_2 -> V_32 -> V_35 ;
F_13 ( V_2 -> V_13 , L_9 , V_35 , V_48 , V_49 ) ;
F_22 ( V_2 -> V_13 , V_35 , L_10 ) ;
if ( ! V_2 -> V_44 )
goto V_45;
V_5 = V_2 -> V_32 -> V_42 ( V_2 , V_48 , V_49 ) ;
V_45:
F_22 ( V_2 -> V_13 , V_35 , L_11 ) ;
V_2 -> V_12 = V_41 ;
F_24 ( & V_2 -> V_43 ) ;
return V_5 ;
}
void F_26 ( struct V_1 * V_2 , bool V_50 )
{
F_21 ( & V_2 -> V_43 ) ;
F_27 ( V_2 -> V_12 && V_50 ) ;
V_2 -> V_51 = V_50 ;
F_28 ( V_2 -> V_13 , V_50 ) ;
F_24 ( & V_2 -> V_43 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
F_21 ( & V_2 -> V_43 ) ;
V_2 -> V_44 = true ;
F_24 ( & V_2 -> V_43 ) ;
}
void F_30 ( struct V_1 * V_2 , bool V_50 )
{
F_21 ( & V_2 -> V_43 ) ;
F_27 ( V_2 -> V_51 && V_50 ) ;
V_2 -> V_12 = V_50 ;
F_31 ( V_2 -> V_13 , V_50 ) ;
F_24 ( & V_2 -> V_43 ) ;
}
bool F_32 ( void * V_52 , unsigned int V_53 ,
unsigned int V_7 , unsigned int V_54 )
{
switch ( V_54 ) {
case 1 : {
T_2 * V_31 = V_52 ;
if ( V_31 [ V_53 ] == V_7 )
return true ;
V_31 [ V_53 ] = V_7 ;
break;
}
case 2 : {
T_3 * V_31 = V_52 ;
if ( V_31 [ V_53 ] == V_7 )
return true ;
V_31 [ V_53 ] = V_7 ;
break;
}
case 4 : {
T_1 * V_31 = V_52 ;
if ( V_31 [ V_53 ] == V_7 )
return true ;
V_31 [ V_53 ] = V_7 ;
break;
}
default:
F_33 () ;
}
return false ;
}
unsigned int F_6 ( const void * V_52 , unsigned int V_53 ,
unsigned int V_54 )
{
if ( ! V_52 )
return - V_10 ;
switch ( V_54 ) {
case 1 : {
const T_2 * V_31 = V_52 ;
return V_31 [ V_53 ] ;
}
case 2 : {
const T_3 * V_31 = V_52 ;
return V_31 [ V_53 ] ;
}
case 4 : {
const T_1 * V_31 = V_52 ;
return V_31 [ V_53 ] ;
}
default:
F_33 () ;
}
return - 1 ;
}
static int F_34 ( const void * V_55 , const void * V_56 )
{
const struct V_19 * V_57 = V_55 ;
const struct V_19 * V_58 = V_56 ;
return V_57 -> V_23 - V_58 -> V_23 ;
}
int F_35 ( struct V_1 * V_2 , unsigned int V_23 )
{
struct V_19 V_59 ;
struct V_19 * V_60 ;
V_59 . V_23 = V_23 ;
V_59 . V_24 = 0 ;
V_60 = bsearch ( & V_59 , V_2 -> V_18 , V_2 -> V_22 ,
sizeof( struct V_19 ) , F_34 ) ;
if ( V_60 )
return V_60 - V_2 -> V_18 ;
else
return - V_61 ;
}
