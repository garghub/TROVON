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
if ( ! V_7 )
continue;
V_6 ++ ;
}
V_2 -> V_17 = F_3 ( V_6 * sizeof( struct V_18 ) ,
V_14 ) ;
if ( ! V_2 -> V_17 )
return - V_19 ;
V_2 -> V_20 = V_6 ;
for ( V_3 = 0 , V_4 = 0 ; V_3 < V_2 -> V_9 ; V_3 ++ ) {
V_7 = F_6 ( V_2 -> V_11 ,
V_3 , V_2 -> V_16 ) ;
if ( ! V_7 )
continue;
V_2 -> V_17 [ V_4 ] . V_21 = V_3 ;
V_2 -> V_17 [ V_4 ] . V_22 = V_7 ;
V_4 ++ ;
}
return 0 ;
}
int F_7 ( struct V_1 * V_2 )
{
int V_5 ;
int V_3 ;
void * V_8 ;
if ( V_2 -> V_23 == V_24 ) {
V_2 -> V_25 = true ;
return 0 ;
}
for ( V_3 = 0 ; V_3 < F_8 ( V_26 ) ; V_3 ++ )
if ( V_26 [ V_3 ] -> type == V_2 -> V_23 )
break;
if ( V_3 == F_8 ( V_26 ) ) {
F_9 ( V_2 -> V_12 , L_2 ,
V_2 -> V_23 ) ;
return - V_10 ;
}
V_2 -> V_27 = NULL ;
V_2 -> V_28 = V_26 [ V_3 ] ;
if ( ! V_2 -> V_28 -> V_29 ||
! V_2 -> V_28 -> V_30 ||
! V_2 -> V_28 -> V_31 )
return - V_10 ;
if ( V_2 -> V_17 ) {
if ( ! V_2 -> V_20 )
return - V_10 ;
V_8 = F_10 ( V_2 -> V_17 , V_2 -> V_20 *
sizeof( struct V_18 ) , V_14 ) ;
if ( ! V_8 )
return - V_19 ;
V_2 -> V_17 = V_8 ;
} else if ( V_2 -> V_9 ) {
V_5 = F_1 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( ! V_2 -> V_32 )
V_2 -> V_32 = V_2 -> V_9 ;
if ( V_2 -> V_28 -> V_33 ) {
F_11 ( V_2 -> V_12 , L_3 ,
V_2 -> V_28 -> V_31 ) ;
return V_2 -> V_28 -> V_33 ( V_2 ) ;
}
return 0 ;
}
void F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_23 == V_24 )
return;
F_13 ( ! V_2 -> V_28 ) ;
F_5 ( V_2 -> V_17 ) ;
if ( V_2 -> V_15 )
F_5 ( V_2 -> V_11 ) ;
if ( V_2 -> V_28 -> exit ) {
F_11 ( V_2 -> V_12 , L_4 ,
V_2 -> V_28 -> V_31 ) ;
V_2 -> V_28 -> exit ( V_2 ) ;
}
}
int F_14 ( struct V_1 * V_2 ,
unsigned int V_21 , unsigned int * V_34 )
{
if ( V_2 -> V_23 == V_24 )
return - V_35 ;
F_13 ( ! V_2 -> V_28 ) ;
if ( ! F_15 ( V_2 , V_21 ) )
return - V_36 ;
if ( ! F_16 ( V_2 , V_21 ) )
return V_2 -> V_28 -> V_29 ( V_2 , V_21 , V_34 ) ;
return - V_10 ;
}
int F_17 ( struct V_1 * V_2 ,
unsigned int V_21 , unsigned int V_34 )
{
if ( V_2 -> V_23 == V_24 )
return 0 ;
F_13 ( ! V_2 -> V_28 ) ;
if ( ! F_18 ( V_2 , V_21 ) )
return - V_36 ;
if ( ! F_16 ( V_2 , V_21 ) )
return V_2 -> V_28 -> V_30 ( V_2 , V_21 , V_34 ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 )
{
int V_5 = 0 ;
unsigned int V_7 ;
unsigned int V_3 ;
const char * V_31 ;
unsigned int V_37 ;
F_13 ( ! V_2 -> V_28 ) ;
F_20 ( & V_2 -> V_38 ) ;
V_37 = V_2 -> V_25 ;
F_11 ( V_2 -> V_12 , L_5 ,
V_2 -> V_28 -> V_31 ) ;
V_31 = V_2 -> V_28 -> V_31 ;
F_21 ( V_2 -> V_12 , V_31 , L_6 ) ;
if ( V_2 -> V_28 -> V_39 ) {
V_5 = V_2 -> V_28 -> V_39 ( V_2 ) ;
} else {
for ( V_3 = 0 ; V_3 < V_2 -> V_20 ; V_3 ++ ) {
V_5 = F_14 ( V_2 , V_3 , & V_7 ) ;
if ( V_5 < 0 )
goto V_40;
V_2 -> V_25 = 1 ;
V_5 = F_22 ( V_2 , V_3 , V_7 ) ;
V_2 -> V_25 = 0 ;
if ( V_5 < 0 )
goto V_40;
F_11 ( V_2 -> V_12 , L_7 ,
V_2 -> V_17 [ V_3 ] . V_21 ,
V_2 -> V_17 [ V_3 ] . V_22 ) ;
}
}
V_40:
F_21 ( V_2 -> V_12 , V_31 , L_8 ) ;
V_2 -> V_25 = V_37 ;
F_23 ( & V_2 -> V_38 ) ;
return V_5 ;
}
void F_24 ( struct V_1 * V_2 , bool V_41 )
{
F_20 ( & V_2 -> V_38 ) ;
F_25 ( V_2 -> V_25 && V_41 ) ;
V_2 -> V_42 = V_41 ;
F_23 ( & V_2 -> V_38 ) ;
}
void F_26 ( struct V_1 * V_2 , bool V_41 )
{
F_20 ( & V_2 -> V_38 ) ;
F_25 ( V_2 -> V_42 && V_41 ) ;
V_2 -> V_25 = V_41 ;
F_23 ( & V_2 -> V_38 ) ;
}
bool F_27 ( void * V_43 , unsigned int V_44 ,
unsigned int V_7 , unsigned int V_45 )
{
switch ( V_45 ) {
case 1 : {
T_1 * V_27 = V_43 ;
if ( V_27 [ V_44 ] == V_7 )
return true ;
V_27 [ V_44 ] = V_7 ;
break;
}
case 2 : {
T_2 * V_27 = V_43 ;
if ( V_27 [ V_44 ] == V_7 )
return true ;
V_27 [ V_44 ] = V_7 ;
break;
}
default:
F_28 () ;
}
return false ;
}
unsigned int F_6 ( const void * V_43 , unsigned int V_44 ,
unsigned int V_45 )
{
if ( ! V_43 )
return - V_10 ;
switch ( V_45 ) {
case 1 : {
const T_1 * V_27 = V_43 ;
return V_27 [ V_44 ] ;
}
case 2 : {
const T_2 * V_27 = V_43 ;
return V_27 [ V_44 ] ;
}
default:
F_28 () ;
}
return - 1 ;
}
static int F_29 ( const void * V_46 , const void * V_47 )
{
const struct V_18 * V_48 = V_46 ;
const struct V_18 * V_49 = V_47 ;
return V_48 -> V_21 - V_49 -> V_21 ;
}
int F_30 ( struct V_1 * V_2 , unsigned int V_21 )
{
struct V_18 V_50 ;
struct V_18 * V_51 ;
V_50 . V_21 = V_21 ;
V_50 . V_22 = 0 ;
V_51 = bsearch ( & V_50 , V_2 -> V_17 , V_2 -> V_20 ,
sizeof( struct V_18 ) , F_29 ) ;
if ( V_51 )
return V_51 - V_2 -> V_17 ;
else
return - V_52 ;
}
int F_31 ( struct V_1 * V_2 , unsigned int V_21 ,
unsigned int V_7 )
{
void * V_53 ;
V_53 = F_32 ( V_2 -> V_17 ,
( V_2 -> V_20 + 1 ) * sizeof( struct V_18 ) ,
V_14 ) ;
if ( ! V_53 )
return - V_19 ;
V_2 -> V_17 = V_53 ;
V_2 -> V_20 ++ ;
V_2 -> V_17 [ V_2 -> V_20 - 1 ] . V_21 = V_21 ;
V_2 -> V_17 [ V_2 -> V_20 - 1 ] . V_22 = V_7 ;
F_33 ( V_2 -> V_17 , V_2 -> V_20 ,
sizeof( struct V_18 ) , F_29 , NULL ) ;
return 0 ;
}
