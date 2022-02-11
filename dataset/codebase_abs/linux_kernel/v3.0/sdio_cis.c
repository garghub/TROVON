static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const unsigned char * V_5 , unsigned V_6 )
{
unsigned V_7 , V_8 ;
char * * V_9 , * string ;
V_5 += 2 ;
V_6 -= 2 ;
V_8 = 0 ;
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ ) {
if ( V_5 [ V_7 ] == 0xff )
break;
if ( V_5 [ V_7 ] == 0 )
V_8 ++ ;
}
if ( V_8 == 0 )
return 0 ;
V_6 = V_7 ;
V_9 = F_2 ( sizeof( char * ) * V_8 + V_6 , V_10 ) ;
if ( ! V_9 )
return - V_11 ;
string = ( char * ) ( V_9 + V_8 ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_9 [ V_7 ] = string ;
strcpy ( string , V_5 ) ;
string += strlen ( string ) + 1 ;
V_5 += strlen ( V_5 ) + 1 ;
}
if ( V_4 ) {
V_4 -> V_12 = V_8 ;
V_4 -> V_13 = ( const char * * ) V_9 ;
} else {
V_2 -> V_12 = V_8 ;
V_2 -> V_13 = ( const char * * ) V_9 ;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const unsigned char * V_5 , unsigned V_6 )
{
unsigned int V_14 , V_15 ;
V_14 = V_5 [ 0 ] | ( V_5 [ 1 ] << 8 ) ;
V_15 = V_5 [ 2 ] | ( V_5 [ 3 ] << 8 ) ;
if ( V_4 ) {
V_4 -> V_14 = V_14 ;
V_4 -> V_15 = V_15 ;
} else {
V_2 -> V_16 . V_14 = V_14 ;
V_2 -> V_16 . V_15 = V_15 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_17 ,
const struct V_18 * V_19 , int V_20 ,
unsigned char V_21 ,
const unsigned char * V_5 , unsigned V_6 )
{
int V_7 , V_22 ;
for ( V_7 = 0 ; V_7 < V_20 ; V_7 ++ , V_19 ++ ) {
if ( V_19 -> V_21 == V_21 )
break;
}
if ( V_7 < V_20 ) {
if ( V_6 >= V_19 -> V_23 ) {
if ( V_19 -> V_24 )
V_22 = V_19 -> V_24 ( V_2 , V_4 , V_5 , V_6 ) ;
else
V_22 = - V_25 ;
} else {
V_22 = - V_26 ;
}
if ( V_22 && V_22 != - V_25 && V_22 != - V_27 ) {
F_5 ( V_28 L_1 ,
F_6 ( V_2 -> V_29 ) , V_17 , V_21 , V_6 ) ;
}
} else {
V_22 = - V_27 ;
}
return V_22 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const unsigned char * V_5 , unsigned V_6 )
{
if ( V_4 )
return - V_26 ;
V_2 -> V_16 . V_30 = V_5 [ 1 ] | ( V_5 [ 2 ] << 8 ) ;
V_2 -> V_16 . V_31 = V_32 [ ( V_5 [ 3 ] >> 3 ) & 15 ] *
V_33 [ V_5 [ 3 ] & 7 ] ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const unsigned char * V_5 , unsigned V_6 )
{
unsigned V_34 ;
unsigned V_23 ;
if ( ! V_4 )
return - V_26 ;
V_34 = V_4 -> V_2 -> V_35 . V_36 ;
V_23 = ( V_34 == V_37 ) ? 28 : 42 ;
if ( V_6 < V_23 )
return - V_26 ;
V_4 -> V_38 = V_5 [ 12 ] | ( V_5 [ 13 ] << 8 ) ;
if ( V_34 > V_37 )
V_4 -> V_39 = ( V_5 [ 28 ] | ( V_5 [ 29 ] << 8 ) ) * 10 ;
else
V_4 -> V_39 = F_9 ( V_40 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const unsigned char * V_5 , unsigned V_6 )
{
if ( V_6 < 1 )
return - V_26 ;
return F_4 ( V_2 , V_4 , L_2 ,
V_41 ,
F_11 ( V_41 ) ,
V_5 [ 0 ] , V_5 , V_6 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_22 ;
struct V_42 * V_43 , * * V_44 ;
unsigned V_7 , V_45 = 0 ;
for ( V_7 = 0 ; V_7 < 3 ; V_7 ++ ) {
unsigned char V_46 , V_47 ;
if ( V_4 )
V_47 = V_4 -> V_48 ;
else
V_47 = 0 ;
V_22 = F_13 ( V_2 , 0 , 0 ,
F_14 ( V_47 ) + V_49 + V_7 , 0 , & V_46 ) ;
if ( V_22 )
return V_22 ;
V_45 |= V_46 << ( V_7 * 8 ) ;
}
if ( V_4 )
V_44 = & V_4 -> V_50 ;
else
V_44 = & V_2 -> V_50 ;
F_15 ( * V_44 ) ;
do {
unsigned char V_51 , V_52 ;
V_22 = F_13 ( V_2 , 0 , 0 , V_45 ++ , 0 , & V_51 ) ;
if ( V_22 )
break;
if ( V_51 == 0xff )
break;
if ( V_51 == 0x00 )
continue;
V_22 = F_13 ( V_2 , 0 , 0 , V_45 ++ , 0 , & V_52 ) ;
if ( V_22 )
break;
if ( V_52 == 0xff )
break;
V_43 = F_16 ( sizeof( * V_43 ) + V_52 , V_10 ) ;
if ( ! V_43 )
return - V_11 ;
for ( V_7 = 0 ; V_7 < V_52 ; V_7 ++ ) {
V_22 = F_13 ( V_2 , 0 , 0 ,
V_45 + V_7 , 0 , & V_43 -> V_53 [ V_7 ] ) ;
if ( V_22 )
break;
}
if ( V_22 ) {
F_17 ( V_43 ) ;
break;
}
V_22 = F_4 ( V_2 , V_4 , L_3 ,
V_54 , F_11 ( V_54 ) ,
V_51 , V_43 -> V_53 , V_52 ) ;
if ( V_22 == - V_25 || V_22 == - V_27 ) {
V_43 -> V_55 = NULL ;
V_43 -> V_21 = V_51 ;
V_43 -> V_6 = V_52 ;
* V_44 = V_43 ;
V_44 = & V_43 -> V_55 ;
if ( V_22 == - V_27 ) {
F_5 ( V_56 L_4
L_5 ,
F_6 ( V_2 -> V_29 ) ,
V_51 , V_52 ) ;
}
V_22 = 0 ;
} else {
F_17 ( V_43 ) ;
}
V_45 += V_52 ;
} while ( ! V_22 );
if ( V_4 )
* V_44 = V_2 -> V_50 ;
return V_22 ;
}
int F_18 ( struct V_1 * V_2 )
{
return F_12 ( V_2 , NULL ) ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_42 * V_57 , * V_58 ;
V_57 = V_2 -> V_50 ;
while ( V_57 ) {
V_58 = V_57 ;
V_57 = V_57 -> V_55 ;
F_17 ( V_58 ) ;
}
V_2 -> V_50 = NULL ;
}
int F_20 ( struct V_3 * V_4 )
{
int V_22 ;
V_22 = F_12 ( V_4 -> V_2 , V_4 ) ;
if ( V_22 )
return V_22 ;
F_21 ( & V_4 -> V_2 -> V_59 ) ;
if ( V_4 -> V_14 == 0 ) {
V_4 -> V_14 = V_4 -> V_2 -> V_16 . V_14 ;
V_4 -> V_15 = V_4 -> V_2 -> V_16 . V_15 ;
}
return 0 ;
}
void F_22 ( struct V_3 * V_4 )
{
struct V_42 * V_57 , * V_58 ;
V_57 = V_4 -> V_50 ;
while ( V_57 && V_57 != V_4 -> V_2 -> V_50 ) {
V_58 = V_57 ;
V_57 = V_57 -> V_55 ;
F_17 ( V_58 ) ;
}
V_4 -> V_50 = NULL ;
F_23 ( & V_4 -> V_2 -> V_59 ) ;
}
