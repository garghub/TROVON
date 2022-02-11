int F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
T_1 F_3 ( const char * V_2 )
{
unsigned long V_3 ;
unsigned int V_4 ;
int V_5 ;
V_3 = 0 ;
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ ) {
V_3 <<= 8 ;
if ( * V_2 != '\0' ) {
V_4 = 0 ;
while ( * V_2 != '\0' && * V_2 != '.' && * V_2 != '\n' ) {
V_4 *= 10 ;
V_4 += * V_2 - '0' ;
V_2 ++ ;
}
V_3 |= V_4 ;
if ( * V_2 != '\0' )
V_2 ++ ;
}
}
return F_4 ( V_3 ) ;
}
static inline int F_5 ( char V_6 , int V_7 )
{
int V_4 ;
if ( V_6 == V_7 || V_6 == '\0' )
return V_8 ;
if ( V_6 == ':' )
return V_9 ;
if ( V_6 == '.' )
return V_10 ;
V_4 = F_6 ( V_6 ) ;
if ( V_4 >= 0 )
return V_4 | V_11 | ( V_4 < 10 ? V_12 : 0 ) ;
if ( V_7 == - 1 )
return V_8 ;
return V_13 ;
}
int F_7 ( const char * V_14 , int V_15 ,
T_2 * V_16 ,
int V_7 , const char * * V_17 )
{
const char * V_18 ;
T_2 * V_19 ;
T_2 V_20 [ 4 ] ;
int V_21 = 0 ;
int V_5 ;
int V_22 = 0 ;
if ( V_15 < 0 )
V_15 = strlen ( V_14 ) ;
V_18 = V_14 ;
V_19 = V_20 ;
V_5 = 0 ;
while( 1 ) {
int V_6 ;
V_6 = F_5 ( V_15 > 0 ? * V_18 : '\0' , V_7 ) ;
if ( ! ( V_6 & ( V_12 | V_10 | V_8 | V_9 ) ) ) {
goto V_23;
}
if ( V_6 & ( V_10 | V_8 | V_9 ) ) {
if ( V_22 == 0 )
goto V_23;
* V_19 ++ = V_22 & 0xff ;
V_22 = 0 ;
V_5 ++ ;
if ( V_6 & ( V_8 | V_9 ) ) {
if ( V_5 != 4 )
goto V_23;
break;
}
goto V_24;
}
V_22 = ( V_22 * 10 ) + V_6 ;
if ( ( V_22 & 0xffff ) > 255 ) {
goto V_23;
}
V_24:
if ( V_5 >= 4 )
goto V_23;
V_18 ++ ;
V_15 -- ;
}
V_21 = 1 ;
memcpy ( V_16 , V_20 , sizeof( V_20 ) ) ;
V_23:
if ( V_17 )
* V_17 = V_18 ;
return V_21 ;
}
int F_8 ( const char * V_14 , int V_15 ,
T_2 * V_16 ,
int V_7 , const char * * V_17 )
{
const char * V_18 , * V_25 = NULL ;
T_2 * V_19 , * V_26 = NULL ;
T_2 V_20 [ 16 ] ;
int V_21 = 0 ;
int V_5 ;
int V_27 = V_28 | V_11 | V_29 ;
int V_22 = 0 ;
memset ( V_20 , 0 , sizeof( V_20 ) ) ;
V_18 = V_14 ;
V_19 = V_20 ;
if ( V_15 < 0 )
V_15 = strlen ( V_14 ) ;
while ( 1 ) {
int V_6 ;
V_6 = F_5 ( V_15 > 0 ? * V_18 : '\0' , V_7 ) ;
if ( ! ( V_6 & V_27 ) )
goto V_23;
if ( V_6 & ( V_8 | V_9 ) ) {
if ( ! ( V_27 & V_29 ) ) {
* V_19 ++ = ( V_22 >> 8 ) & 0xff ;
* V_19 ++ = V_22 & 0xff ;
}
V_22 = 0 ;
if ( V_6 & V_8 ) {
break;
}
switch ( V_27 & V_9 ) {
case V_30 :
V_26 = V_19 ;
V_27 = V_11 | V_8 ;
if ( V_26 - V_20 >= sizeof( V_20 ) )
V_27 |= V_29 ;
break;
case V_31 | V_28 :
V_27 = V_11 | V_30 ;
break;
case V_31 :
V_27 = V_11 ;
break;
case V_28 :
V_27 = V_30 ;
break;
default:
V_27 = 0 ;
}
V_25 = V_18 + 1 ;
goto V_24;
}
if ( V_6 & V_10 ) {
V_21 = F_7 ( V_25 ? V_25 : V_18 , V_15 + ( int ) ( V_18 - V_25 ) , V_19 , V_7 , & V_18 ) ;
if ( V_21 > 0 ) {
V_19 += 4 ;
break;
}
goto V_23;
}
V_22 = ( V_22 << 4 ) | ( 0xff & V_6 ) ;
V_27 = V_31 | V_8 ;
if ( ! ( V_22 & 0xf000 ) ) {
V_27 |= V_11 ;
}
if ( ! V_26 && V_19 + 2 < V_20 + sizeof( V_20 ) ) {
V_27 |= V_28 ;
V_27 &= ~ V_8 ;
}
if ( V_19 + 2 >= V_20 + sizeof( V_20 ) ) {
V_27 &= ~ ( V_31 | V_28 ) ;
}
V_24:
if ( ( V_26 && V_19 + 4 < V_20 + sizeof( V_20 ) ) ||
V_19 + 4 == V_20 + sizeof( V_20 ) ) {
V_27 |= V_10 ;
}
if ( V_19 >= V_20 + sizeof( V_20 ) ) {
V_27 &= ~ ( V_11 | V_9 ) ;
}
V_18 ++ ;
V_15 -- ;
}
V_5 = 15 ; V_19 -- ;
if ( V_26 ) {
while( V_19 >= V_26 )
V_16 [ V_5 -- ] = * V_19 -- ;
while( V_5 >= V_26 - V_20 )
V_16 [ V_5 -- ] = 0 ;
while( V_5 >= 0 )
V_16 [ V_5 -- ] = * V_19 -- ;
} else
memcpy ( V_16 , V_20 , sizeof( V_20 ) ) ;
V_21 = 1 ;
V_23:
if ( V_17 )
* V_17 = V_18 ;
return V_21 ;
}
void F_9 ( T_3 * V_32 , struct V_33 * V_34 ,
T_1 V_35 , T_1 V_36 , int V_37 )
{
T_1 V_38 [] = { ~ V_35 , V_36 } ;
if ( V_34 -> V_39 != V_40 ) {
* V_32 = F_10 ( F_11 ( V_38 , sizeof( V_38 ) ,
~ F_12 ( * V_32 ) ) ) ;
if ( V_34 -> V_39 == V_41 && V_37 )
V_34 -> V_42 = ~ F_11 ( V_38 , sizeof( V_38 ) ,
~ V_34 -> V_42 ) ;
} else if ( V_37 )
* V_32 = ~ F_10 ( F_11 ( V_38 , sizeof( V_38 ) ,
F_12 ( * V_32 ) ) ) ;
}
void F_13 ( T_3 * V_32 , struct V_33 * V_34 ,
const T_1 * V_35 , const T_1 * V_36 ,
int V_37 )
{
T_1 V_38 [] = {
~ V_35 [ 0 ] , ~ V_35 [ 1 ] , ~ V_35 [ 2 ] , ~ V_35 [ 3 ] ,
V_36 [ 0 ] , V_36 [ 1 ] , V_36 [ 2 ] , V_36 [ 3 ] ,
} ;
if ( V_34 -> V_39 != V_40 ) {
* V_32 = F_10 ( F_11 ( V_38 , sizeof( V_38 ) ,
~ F_12 ( * V_32 ) ) ) ;
if ( V_34 -> V_39 == V_41 && V_37 )
V_34 -> V_42 = ~ F_11 ( V_38 , sizeof( V_38 ) ,
~ V_34 -> V_42 ) ;
} else if ( V_37 )
* V_32 = ~ F_10 ( F_11 ( V_38 , sizeof( V_38 ) ,
F_12 ( * V_32 ) ) ) ;
}
static void F_14 ( struct V_43 * V_22 )
{
struct V_44 * V_45 =
F_15 ( V_22 , struct V_44 , V_45 ) ;
if ( ! F_16 ( V_45 -> V_46 ) )
F_17 ( V_45 -> V_46 ) ;
F_18 ( V_45 ) ;
}
static void F_19 ( struct V_47 * V_46 )
{
struct V_44 * V_22 ;
V_22 = F_20 ( sizeof( * V_22 ) , V_48 ) ;
if ( ! V_22 )
return;
F_21 ( & V_22 -> V_45 , F_14 ) ;
V_22 -> V_46 = V_46 ;
F_22 ( & V_22 -> V_45 ) ;
}
bool F_23 ( void * V_49 , int V_50 , bool * V_51 ,
struct V_47 * V_52 )
{
static F_24 ( V_53 ) ;
unsigned long V_54 ;
F_25 ( & V_53 , V_54 ) ;
if ( * V_51 ) {
F_26 ( & V_53 , V_54 ) ;
return false ;
}
F_27 ( V_49 , V_50 ) ;
* V_51 = true ;
F_26 ( & V_53 , V_54 ) ;
F_19 ( V_52 ) ;
return true ;
}
