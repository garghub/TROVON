static inline int F_1 ( void ) { return 0 ; }
static inline void F_2 ( void ) { }
static char * F_3 ( struct V_1 * V_2 , T_1 * V_3 )
{
if ( F_4 ( V_2 -> V_4 ) == V_5 )
return NULL ;
return F_5 ( V_6 , L_1 , F_6 ( V_2 ) ) ;
}
static int T_2 F_7 ( void )
{
int V_7 ;
V_7 = F_1 () ;
if ( V_7 )
return V_7 ;
V_8 = F_8 ( V_9 , L_2 ) ;
if ( F_9 ( V_8 ) ) {
F_2 () ;
return F_10 ( V_8 ) ;
}
V_8 -> V_10 = F_3 ;
return 0 ;
}
static void T_3 F_11 ( void )
{
F_2 () ;
F_12 ( V_8 ) ;
}
static int F_13 ( struct V_11 * V_12 , struct V_11 * * V_13 , const struct V_14 * V_15 , int V_16 , int V_17 , int V_18 )
{
int V_19 = V_17 ;
if ( V_16 < 0 ) {
while ( * V_13 && ( * V_13 ) -> V_20 < V_19 )
V_13 = & ( ( * V_13 ) -> V_21 ) ;
while( V_19 < V_18 )
{
if( * V_13 == NULL || ( * V_13 ) -> V_20 > V_19 )
break;
V_13 = & ( ( * V_13 ) -> V_21 ) ;
V_19 += V_22 ;
}
if( V_19 >= V_18 )
return - V_23 ;
} else {
V_19 = V_17 + ( V_16 * 16 ) ;
while ( * V_13 ) {
if ( ( * V_13 ) -> V_20 == V_19 )
return - V_24 ;
if ( ( * V_13 ) -> V_20 > V_19 )
break;
V_13 = & ( ( * V_13 ) -> V_21 ) ;
}
}
V_12 -> V_20 = V_19 ;
V_12 -> V_25 = V_15 ;
V_12 -> V_21 = * V_13 ;
* V_13 = V_12 ;
return V_19 ;
}
static struct V_11 * F_14 ( struct V_11 * * V_13 , int V_26 )
{
while( * V_13 )
{
struct V_11 * V_27 = * V_13 ;
if( V_27 -> V_20 == V_26 )
{
* V_13 = V_27 -> V_21 ;
return V_27 ;
}
V_13 = & ( V_27 -> V_21 ) ;
}
F_15 ( V_28 L_3 , V_26 ) ;
return NULL ;
}
static int F_16 ( struct V_11 * * V_13 , const struct V_14 * V_15 , int V_16 , int V_17 , int V_18 , const char * V_29 , T_1 V_3 , struct V_1 * V_2 )
{
struct V_11 * V_12 = F_17 ( sizeof( * V_12 ) , V_6 ) ;
int V_30 ;
if ( ! V_12 )
return - V_31 ;
F_18 ( & V_32 ) ;
V_33:
V_30 = F_13 ( V_12 , V_13 , V_15 , V_16 , V_17 , V_18 ) ;
F_19 ( & V_32 ) ;
if ( V_30 < 0 )
goto V_34;
else if ( V_30 < V_22 )
sprintf ( V_12 -> V_29 , L_4 , V_29 ) ;
else
sprintf ( V_12 -> V_29 , L_5 , V_29 , V_30 / V_22 ) ;
if ( ! V_35 ) {
V_30 = F_20 ( V_5 , V_12 -> V_20 , 1 , V_12 -> V_29 ,
& V_36 ) ;
if ( V_30 < 0 ) {
F_18 ( & V_32 ) ;
F_14 ( V_13 , V_12 -> V_20 ) ;
if ( V_16 < 0 ) {
V_17 = V_12 -> V_20 + V_22 ;
goto V_33;
}
F_19 ( & V_32 ) ;
return - V_24 ;
}
}
F_21 ( V_8 , V_2 , F_22 ( V_5 , V_12 -> V_20 ) ,
NULL , L_6 , V_12 -> V_29 + 6 ) ;
return V_12 -> V_20 ;
V_34:
F_23 ( V_12 ) ;
return V_30 ;
}
static void F_24 ( struct V_11 * * V_13 , int V_26 )
{
struct V_11 * V_27 ;
F_18 ( & V_32 ) ;
V_27 = F_14 ( V_13 , V_26 ) ;
F_19 ( & V_32 ) ;
if ( V_27 ) {
if ( ! V_35 )
F_25 ( V_5 , V_27 -> V_20 , 1 ,
V_27 -> V_29 ) ;
F_26 ( V_8 , F_22 ( V_5 , V_27 -> V_20 ) ) ;
F_23 ( V_27 ) ;
}
}
int F_27 ( const struct V_14 * V_15 , int V_26 ,
struct V_1 * V_2 )
{
const int V_37 = V_26 % V_22 ;
int V_38 = 256 ;
const char * V_29 ;
char V_39 [ 16 ] ;
switch ( V_37 ) {
case 0 :
V_29 = L_7 ;
break;
case 1 :
V_29 = L_8 ;
if ( V_26 >= V_22 )
goto V_40;
V_38 = V_26 + 1 ;
break;
case 2 :
V_29 = L_9 ;
break;
case 3 :
V_29 = L_10 ;
break;
case 4 :
V_29 = L_11 ;
break;
case 5 :
V_29 = L_12 ;
break;
case 8 :
V_29 = L_13 ;
if ( V_26 >= V_22 )
goto V_40;
V_38 = V_26 + 1 ;
break;
case 9 :
V_29 = L_14 ;
break;
case 10 :
V_29 = L_15 ;
break;
case 12 :
V_29 = L_16 ;
break;
case 13 :
V_29 = L_17 ;
break;
case 14 :
V_29 = L_18 ;
break;
default:
{
V_40:
sprintf ( V_39 , L_19 , V_37 ) ;
if ( V_26 >= V_22 )
strcat ( V_39 , L_20 ) ;
V_29 = V_39 ;
}
break;
}
return F_16 ( & V_41 [ V_37 ] , V_15 , - 1 , V_26 , V_38 ,
V_29 , V_42 | V_43 , V_2 ) ;
}
int F_28 ( const struct V_14 * V_15 , int V_26 )
{
return F_27 ( V_15 , V_26 , NULL ) ;
}
int F_29 ( const struct V_14 * V_15 , int V_2 )
{
return F_16 ( & V_41 [ 0 ] , V_15 , V_2 , 0 , 128 ,
L_7 , V_42 | V_43 , NULL ) ;
}
int F_30 ( const struct V_14 * V_15 , int V_2 )
{
return F_16 ( & V_41 [ 2 ] , V_15 , V_2 , 2 , 130 ,
L_9 , V_42 | V_43 , NULL ) ;
}
int F_31 ( const struct V_14 * V_15 , int V_2 )
{
return F_16 ( & V_41 [ 3 ] , V_15 , V_2 , 3 , 131 ,
L_10 , V_43 | V_42 , NULL ) ;
}
void F_32 ( int V_26 )
{
F_24 ( & V_41 [ V_26 % V_22 ] , V_26 ) ;
}
void F_33 ( int V_26 )
{
F_24 ( & V_41 [ 0 ] , V_26 ) ;
}
void F_34 ( int V_26 )
{
F_24 ( & V_41 [ 2 ] , V_26 ) ;
}
void F_35 ( int V_26 )
{
F_24 ( & V_41 [ 3 ] , V_26 ) ;
}
static struct V_11 * F_36 ( int V_37 , int V_26 )
{
struct V_11 * V_12 ;
V_12 = V_41 [ V_37 ] ;
while( V_12 && V_12 -> V_20 <= V_26 )
{
if( V_12 -> V_20 == V_26 )
return V_12 ;
V_12 = V_12 -> V_21 ;
}
return NULL ;
}
static int F_37 ( struct V_44 * V_44 , struct V_45 * V_45 )
{
int V_37 ;
int V_26 = F_38 ( V_44 ) ;
struct V_11 * V_12 ;
const struct V_14 * V_46 = NULL ;
V_37 = V_26 & 0x0F ;
if( V_37 == 4 || V_37 == 5 )
{
V_26 &= 0xF0 ;
V_26 |= 3 ;
V_37 = 3 ;
}
F_18 ( & V_32 ) ;
V_12 = F_36 ( V_37 , V_26 ) ;
if ( V_12 )
V_46 = F_39 ( V_12 -> V_25 ) ;
if ( V_35 && ! V_46 ) {
F_19 ( & V_32 ) ;
F_40 ( L_21 , V_26 >> 4 ) ;
F_40 ( L_22 , V_26 >> 4 , V_37 ) ;
if ( F_40 ( L_23 , V_5 , V_26 ) > 0 )
F_40 ( L_24 , V_5 ) ;
F_18 ( & V_32 ) ;
V_12 = F_36 ( V_37 , V_26 ) ;
if ( V_12 )
V_46 = F_39 ( V_12 -> V_25 ) ;
}
F_19 ( & V_32 ) ;
if ( V_46 ) {
int V_47 = 0 ;
F_41 ( V_45 , V_46 ) ;
if ( V_45 -> V_48 -> V_49 )
V_47 = V_45 -> V_48 -> V_49 ( V_44 , V_45 ) ;
return V_47 ;
}
return - V_50 ;
}
static void F_2 ( void )
{
F_42 ( V_5 , L_2 ) ;
}
static int T_2 F_1 ( void )
{
if ( V_35 &&
F_43 ( V_5 , L_2 , & V_36 ) == - 1 ) {
F_15 ( V_28 L_25 ) ;
return - V_24 ;
}
return 0 ;
}
