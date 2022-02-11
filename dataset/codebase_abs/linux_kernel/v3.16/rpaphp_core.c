static int F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
int V_3 ;
struct V_4 * V_4 = (struct V_4 * ) V_1 -> V_5 ;
switch ( V_2 ) {
case 0 :
case 1 :
case 2 :
break;
default:
V_2 = 1 ;
break;
}
V_3 = F_2 ( V_6 , V_4 -> V_7 , V_2 ) ;
if ( ! V_3 )
V_1 -> V_8 -> V_9 = V_2 ;
return V_3 ;
}
static int F_3 ( struct V_1 * V_1 , T_1 * V_2 )
{
int V_10 , V_11 ;
struct V_4 * V_4 = (struct V_4 * ) V_1 -> V_5 ;
V_10 = F_4 ( V_4 -> V_12 , & V_11 ) ;
if ( ! V_10 )
* V_2 = V_11 ;
return V_10 ;
}
static int F_5 ( struct V_1 * V_1 , T_1 * V_2 )
{
struct V_4 * V_4 = (struct V_4 * ) V_1 -> V_5 ;
* V_2 = V_4 -> V_1 -> V_8 -> V_9 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_1 , T_1 * V_2 )
{
struct V_4 * V_4 = (struct V_4 * ) V_1 -> V_5 ;
int V_3 , V_13 ;
V_3 = F_7 ( V_4 , & V_13 ) ;
* V_2 = V_14 ;
if ( V_3 )
return V_3 ;
if ( V_13 == V_15 )
* V_2 = V_15 ;
else if ( V_13 == V_16 )
* V_2 = V_4 -> V_13 ;
return 0 ;
}
static enum V_17 F_8 ( struct V_4 * V_4 )
{
enum V_17 V_18 ;
switch ( V_4 -> type ) {
case 1 :
case 2 :
case 3 :
case 4 :
case 5 :
case 6 :
V_18 = V_19 ;
break;
case 7 :
case 8 :
V_18 = V_20 ;
break;
case 11 :
case 14 :
V_18 = V_21 ;
break;
case 12 :
case 15 :
V_18 = V_22 ;
break;
case 13 :
case 16 :
V_18 = V_23 ;
break;
default:
V_18 = V_24 ;
break;
}
return V_18 ;
}
static int F_9 ( struct V_25 * V_26 , const int * * V_27 ,
const int * * V_28 , const int * * V_29 ,
const int * * V_30 )
{
const int * V_31 , * V_32 , * V_33 , * V_34 ;
V_31 = F_10 ( V_26 , L_1 , NULL ) ;
V_32 = F_10 ( V_26 , L_2 , NULL ) ;
V_33 = F_10 ( V_26 , L_3 , NULL ) ;
V_34 = F_10 ( V_26 , L_4 , NULL ) ;
if ( ! V_31 || ! V_32 || ! V_33 || ! V_34 ) {
return - V_35 ;
}
if ( V_27 )
* V_27 = V_31 ;
if ( V_28 )
* V_28 = V_32 ;
if ( V_29 )
* V_29 = V_33 ;
if ( V_30 )
* V_30 = V_34 ;
return 0 ;
}
int F_11 ( struct V_25 * V_26 , int * V_36 ,
char * * V_37 , char * * V_38 , int * V_39 )
{
const int * V_31 , * V_32 ;
const int * V_33 , * V_34 ;
const unsigned int * V_40 ;
char * V_41 , * V_42 ;
int V_43 , V_3 ;
V_40 = F_10 ( V_26 , L_5 , NULL ) ;
if ( ! V_40 ) {
return - V_35 ;
}
V_3 = F_9 ( V_26 -> V_44 , & V_31 , & V_32 , & V_33 , & V_34 ) ;
if ( V_3 < 0 ) {
return - V_35 ;
}
V_41 = ( char * ) & V_32 [ 1 ] ;
V_42 = ( char * ) & V_33 [ 1 ] ;
for ( V_43 = 0 ; V_43 < F_12 ( V_31 [ 0 ] ) ; V_43 ++ ) {
if ( ( unsigned int ) V_31 [ V_43 + 1 ] == * V_40 ) {
if ( V_37 )
* V_37 = V_41 ;
if ( V_38 )
* V_38 = V_42 ;
if ( V_36 )
* V_36 = F_12 ( * V_40 ) ;
if ( V_39 )
* V_39 = F_12 ( V_34 [ V_43 + 1 ] ) ;
return 0 ;
}
V_41 += ( strlen ( V_41 ) + 1 ) ;
V_42 += ( strlen ( V_42 ) + 1 ) ;
}
return - V_35 ;
}
static int F_13 ( char * V_38 )
{
unsigned long V_2 ;
char * V_45 ;
V_2 = F_14 ( V_38 , & V_45 , 10 ) ;
if ( V_45 == V_38 )
return 0 ;
return 1 ;
}
static int F_15 ( struct V_25 * V_26 , const int * * V_31 ,
const int * * V_32 , const int * * V_33 , const int * * V_46 )
{
const int * V_29 ;
int V_3 ;
V_3 = F_9 ( V_26 , V_31 , V_32 , & V_29 , V_46 ) ;
if ( V_3 < 0 )
return 0 ;
if ( ! F_13 ( ( char * ) & V_29 [ 1 ] ) )
return 0 ;
* V_33 = V_29 ;
return 1 ;
}
int F_16 ( struct V_25 * V_26 )
{
struct V_4 * V_4 ;
int V_10 = 0 ;
int V_43 ;
const int * V_31 , * V_32 , * V_33 , * V_46 ;
char * V_47 , * type ;
if ( ! V_26 -> V_47 || strcmp ( V_26 -> V_47 , L_6 ) )
return 0 ;
if ( ! F_15 ( V_26 , & V_31 , & V_32 , & V_33 , & V_46 ) )
return 0 ;
F_17 ( L_7 , V_48 , V_26 -> V_49 ) ;
V_47 = ( char * ) & V_32 [ 1 ] ;
type = ( char * ) & V_33 [ 1 ] ;
for ( V_43 = 0 ; V_43 < F_12 ( V_31 [ 0 ] ) ; V_43 ++ ) {
int V_7 ;
V_7 = F_12 ( V_31 [ V_43 + 1 ] ) ;
V_4 = F_18 ( V_26 , V_7 , V_47 ,
F_12 ( V_46 [ V_43 + 1 ] ) ) ;
if ( ! V_4 )
return - V_50 ;
V_4 -> type = F_14 ( type , NULL , 10 ) ;
F_17 ( L_8 ,
V_7 , V_47 , type ) ;
V_10 = F_19 ( V_4 ) ;
if ( ! V_10 )
V_10 = F_20 ( V_4 ) ;
if ( V_10 )
F_21 ( V_4 ) ;
V_47 += strlen ( V_47 ) + 1 ;
type += strlen ( type ) + 1 ;
}
F_17 ( L_9 , V_48 , V_10 ) ;
return V_10 ;
}
static void T_2 F_22 ( void )
{
struct V_51 * V_52 , * V_53 ;
struct V_4 * V_4 ;
F_23 (tmp, n, &rpaphp_slot_head) {
V_4 = F_24 ( V_52 , struct V_4 , V_54 ) ;
F_25 ( & V_4 -> V_54 ) ;
F_26 ( V_4 -> V_1 ) ;
}
return;
}
static int T_3 F_27 ( void )
{
struct V_25 * V_26 = NULL ;
V_8 ( V_55 L_10 V_56 L_11 ) ;
while ( ( V_26 = F_28 ( V_26 , L_6 ) ) )
F_16 ( V_26 ) ;
return 0 ;
}
static void T_2 F_29 ( void )
{
F_22 () ;
}
static int F_30 ( struct V_1 * V_1 )
{
struct V_4 * V_4 = (struct V_4 * ) V_1 -> V_5 ;
int V_13 ;
int V_10 ;
if ( V_4 -> V_13 == V_57 )
return 0 ;
V_10 = F_7 ( V_4 , & V_13 ) ;
if ( V_10 )
return V_10 ;
if ( V_13 == V_16 ) {
F_31 () ;
F_32 ( V_4 -> V_58 ) ;
F_33 () ;
V_4 -> V_13 = V_57 ;
} else if ( V_13 == V_15 ) {
V_4 -> V_13 = V_15 ;
} else {
F_34 ( L_12 , V_48 , V_4 -> V_47 ) ;
V_4 -> V_13 = V_14 ;
return - V_35 ;
}
V_4 -> V_58 -> V_59 = F_8 ( V_4 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_1 )
{
struct V_4 * V_4 = (struct V_4 * ) V_1 -> V_5 ;
if ( V_4 -> V_13 == V_60 )
return - V_35 ;
F_31 () ;
F_36 ( V_4 -> V_58 ) ;
F_33 () ;
F_37 () ;
V_4 -> V_13 = V_60 ;
return 0 ;
}
