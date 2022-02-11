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
F_2 ( V_2 -> V_12 , L_1 ) ;
V_8 = F_3 ( V_2 -> V_13 , V_14 ) ;
if ( ! V_8 )
return - V_10 ;
V_5 = F_4 ( V_2 , 0 , V_8 ,
V_2 -> V_9 ) ;
if ( V_5 < 0 ) {
F_5 ( V_8 ) ;
return V_5 ;
}
V_2 -> V_11 = V_8 ;
V_2 -> V_15 = 1 ;
}
for ( V_6 = 0 , V_3 = 0 ; V_3 < V_2 -> V_9 ; V_3 ++ ) {
V_7 = F_6 ( V_2 -> V_11 ,
V_3 , V_2 -> V_16 ) ;
if ( F_7 ( V_2 , V_3 ) )
continue;
V_6 ++ ;
}
V_2 -> V_17 = F_3 ( V_6 * sizeof( struct V_18 ) ,
V_14 ) ;
if ( ! V_2 -> V_17 ) {
V_5 = - V_19 ;
goto V_20;
}
V_2 -> V_21 = V_6 ;
for ( V_3 = 0 , V_4 = 0 ; V_3 < V_2 -> V_9 ; V_3 ++ ) {
V_7 = F_6 ( V_2 -> V_11 ,
V_3 , V_2 -> V_16 ) ;
if ( F_7 ( V_2 , V_3 ) )
continue;
V_2 -> V_17 [ V_4 ] . V_22 = V_3 ;
V_2 -> V_17 [ V_4 ] . V_23 = V_7 ;
V_4 ++ ;
}
return 0 ;
V_20:
if ( V_2 -> V_15 )
F_5 ( V_2 -> V_11 ) ;
return V_5 ;
}
int F_8 ( struct V_1 * V_2 , const struct V_24 * V_25 )
{
int V_5 ;
int V_3 ;
void * V_8 ;
if ( V_2 -> V_26 == V_27 ) {
V_2 -> V_28 = true ;
return 0 ;
}
for ( V_3 = 0 ; V_3 < F_9 ( V_29 ) ; V_3 ++ )
if ( V_29 [ V_3 ] -> type == V_2 -> V_26 )
break;
if ( V_3 == F_9 ( V_29 ) ) {
F_10 ( V_2 -> V_12 , L_2 ,
V_2 -> V_26 ) ;
return - V_10 ;
}
V_2 -> V_21 = V_25 -> V_21 ;
V_2 -> V_9 = V_25 -> V_9 ;
V_2 -> V_11 = V_25 -> V_11 ;
V_2 -> V_16 = F_11 ( V_25 -> V_30 , 8 ) ;
V_2 -> V_13 = V_2 -> V_16 * V_25 -> V_9 ;
V_2 -> V_31 = NULL ;
V_2 -> V_32 = V_29 [ V_3 ] ;
if ( ! V_2 -> V_32 -> V_33 ||
! V_2 -> V_32 -> V_34 ||
! V_2 -> V_32 -> V_35 )
return - V_10 ;
if ( V_25 -> V_17 ) {
if ( ! V_2 -> V_21 )
return - V_10 ;
V_8 = F_12 ( V_25 -> V_17 , V_2 -> V_21 *
sizeof( struct V_18 ) , V_14 ) ;
if ( ! V_8 )
return - V_19 ;
V_2 -> V_17 = V_8 ;
} else if ( V_2 -> V_9 ) {
V_5 = F_1 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( ! V_2 -> V_36 )
V_2 -> V_36 = V_2 -> V_9 ;
if ( V_2 -> V_32 -> V_37 ) {
F_13 ( V_2 -> V_12 , L_3 ,
V_2 -> V_32 -> V_35 ) ;
V_5 = V_2 -> V_32 -> V_37 ( V_2 ) ;
if ( V_5 )
goto V_20;
}
return 0 ;
V_20:
F_5 ( V_2 -> V_17 ) ;
if ( V_2 -> V_15 )
F_5 ( V_2 -> V_11 ) ;
return V_5 ;
}
void F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_26 == V_27 )
return;
F_15 ( ! V_2 -> V_32 ) ;
F_5 ( V_2 -> V_17 ) ;
if ( V_2 -> V_15 )
F_5 ( V_2 -> V_11 ) ;
if ( V_2 -> V_32 -> exit ) {
F_13 ( V_2 -> V_12 , L_4 ,
V_2 -> V_32 -> V_35 ) ;
V_2 -> V_32 -> exit ( V_2 ) ;
}
}
int F_16 ( struct V_1 * V_2 ,
unsigned int V_22 , unsigned int * V_38 )
{
int V_5 ;
if ( V_2 -> V_26 == V_27 )
return - V_39 ;
F_15 ( ! V_2 -> V_32 ) ;
if ( ! F_7 ( V_2 , V_22 ) ) {
V_5 = V_2 -> V_32 -> V_33 ( V_2 , V_22 , V_38 ) ;
if ( V_5 == 0 )
F_17 ( V_2 -> V_12 , V_22 , * V_38 ) ;
return V_5 ;
}
return - V_10 ;
}
int F_18 ( struct V_1 * V_2 ,
unsigned int V_22 , unsigned int V_38 )
{
if ( V_2 -> V_26 == V_27 )
return 0 ;
F_15 ( ! V_2 -> V_32 ) ;
if ( ! F_19 ( V_2 , V_22 ) )
return - V_40 ;
if ( ! F_7 ( V_2 , V_22 ) )
return V_2 -> V_32 -> V_34 ( V_2 , V_22 , V_38 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 )
{
int V_5 = 0 ;
unsigned int V_7 ;
unsigned int V_3 ;
const char * V_35 ;
unsigned int V_41 ;
F_15 ( ! V_2 -> V_32 ) ;
F_21 ( & V_2 -> V_42 ) ;
V_41 = V_2 -> V_28 ;
F_13 ( V_2 -> V_12 , L_5 ,
V_2 -> V_32 -> V_35 ) ;
V_35 = V_2 -> V_32 -> V_35 ;
F_22 ( V_2 -> V_12 , V_35 , L_6 ) ;
if ( ! V_2 -> V_43 )
goto V_44;
if ( V_2 -> V_32 -> V_45 ) {
V_5 = V_2 -> V_32 -> V_45 ( V_2 ) ;
} else {
for ( V_3 = 0 ; V_3 < V_2 -> V_21 ; V_3 ++ ) {
V_5 = F_16 ( V_2 , V_3 , & V_7 ) ;
if ( V_5 < 0 )
goto V_44;
V_2 -> V_28 = 1 ;
V_5 = F_23 ( V_2 , V_3 , V_7 ) ;
V_2 -> V_28 = 0 ;
if ( V_5 < 0 )
goto V_44;
F_13 ( V_2 -> V_12 , L_7 ,
V_2 -> V_17 [ V_3 ] . V_22 ,
V_2 -> V_17 [ V_3 ] . V_23 ) ;
}
}
V_44:
F_22 ( V_2 -> V_12 , V_35 , L_8 ) ;
V_2 -> V_28 = V_41 ;
F_24 ( & V_2 -> V_42 ) ;
return V_5 ;
}
void F_25 ( struct V_1 * V_2 , bool V_46 )
{
F_21 ( & V_2 -> V_42 ) ;
F_26 ( V_2 -> V_28 && V_46 ) ;
V_2 -> V_47 = V_46 ;
F_24 ( & V_2 -> V_42 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
F_21 ( & V_2 -> V_42 ) ;
V_2 -> V_43 = true ;
F_24 ( & V_2 -> V_42 ) ;
}
void F_28 ( struct V_1 * V_2 , bool V_46 )
{
F_21 ( & V_2 -> V_42 ) ;
F_26 ( V_2 -> V_47 && V_46 ) ;
V_2 -> V_28 = V_46 ;
F_24 ( & V_2 -> V_42 ) ;
}
bool F_29 ( void * V_48 , unsigned int V_49 ,
unsigned int V_7 , unsigned int V_50 )
{
switch ( V_50 ) {
case 1 : {
T_1 * V_31 = V_48 ;
if ( V_31 [ V_49 ] == V_7 )
return true ;
V_31 [ V_49 ] = V_7 ;
break;
}
case 2 : {
T_2 * V_31 = V_48 ;
if ( V_31 [ V_49 ] == V_7 )
return true ;
V_31 [ V_49 ] = V_7 ;
break;
}
default:
F_30 () ;
}
return false ;
}
unsigned int F_6 ( const void * V_48 , unsigned int V_49 ,
unsigned int V_50 )
{
if ( ! V_48 )
return - V_10 ;
switch ( V_50 ) {
case 1 : {
const T_1 * V_31 = V_48 ;
return V_31 [ V_49 ] ;
}
case 2 : {
const T_2 * V_31 = V_48 ;
return V_31 [ V_49 ] ;
}
default:
F_30 () ;
}
return - 1 ;
}
static int F_31 ( const void * V_51 , const void * V_52 )
{
const struct V_18 * V_53 = V_51 ;
const struct V_18 * V_54 = V_52 ;
return V_53 -> V_22 - V_54 -> V_22 ;
}
int F_32 ( struct V_1 * V_2 , unsigned int V_22 )
{
struct V_18 V_55 ;
struct V_18 * V_56 ;
V_55 . V_22 = V_22 ;
V_55 . V_23 = 0 ;
V_56 = bsearch ( & V_55 , V_2 -> V_17 , V_2 -> V_21 ,
sizeof( struct V_18 ) , F_31 ) ;
if ( V_56 )
return V_56 - V_2 -> V_17 ;
else
return - V_57 ;
}
