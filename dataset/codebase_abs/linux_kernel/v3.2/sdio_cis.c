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
F_5 ( L_1 ,
F_6 ( V_2 -> V_28 ) , V_17 , V_21 , V_6 ) ;
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
V_2 -> V_16 . V_29 = V_5 [ 1 ] | ( V_5 [ 2 ] << 8 ) ;
V_2 -> V_16 . V_30 = V_31 [ ( V_5 [ 3 ] >> 3 ) & 15 ] *
V_32 [ V_5 [ 3 ] & 7 ] ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const unsigned char * V_5 , unsigned V_6 )
{
unsigned V_33 ;
unsigned V_23 ;
if ( ! V_4 )
return - V_26 ;
V_33 = V_4 -> V_2 -> V_34 . V_35 ;
V_23 = ( V_33 == V_36 ) ? 28 : 42 ;
if ( V_6 < V_23 )
return - V_26 ;
V_4 -> V_37 = V_5 [ 12 ] | ( V_5 [ 13 ] << 8 ) ;
if ( V_33 > V_36 )
V_4 -> V_38 = ( V_5 [ 28 ] | ( V_5 [ 29 ] << 8 ) ) * 10 ;
else
V_4 -> V_38 = F_9 ( V_39 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const unsigned char * V_5 , unsigned V_6 )
{
if ( V_6 < 1 )
return - V_26 ;
return F_4 ( V_2 , V_4 , L_2 ,
V_40 ,
F_11 ( V_40 ) ,
V_5 [ 0 ] , V_5 , V_6 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_22 ;
struct V_41 * V_42 , * * V_43 ;
unsigned V_7 , V_44 = 0 ;
for ( V_7 = 0 ; V_7 < 3 ; V_7 ++ ) {
unsigned char V_45 , V_46 ;
if ( V_4 )
V_46 = V_4 -> V_47 ;
else
V_46 = 0 ;
V_22 = F_13 ( V_2 , 0 , 0 ,
F_14 ( V_46 ) + V_48 + V_7 , 0 , & V_45 ) ;
if ( V_22 )
return V_22 ;
V_44 |= V_45 << ( V_7 * 8 ) ;
}
if ( V_4 )
V_43 = & V_4 -> V_49 ;
else
V_43 = & V_2 -> V_49 ;
F_15 ( * V_43 ) ;
do {
unsigned char V_50 , V_51 ;
V_22 = F_13 ( V_2 , 0 , 0 , V_44 ++ , 0 , & V_50 ) ;
if ( V_22 )
break;
if ( V_50 == 0xff )
break;
if ( V_50 == 0x00 )
continue;
V_22 = F_13 ( V_2 , 0 , 0 , V_44 ++ , 0 , & V_51 ) ;
if ( V_22 )
break;
if ( V_51 == 0xff )
break;
V_42 = F_16 ( sizeof( * V_42 ) + V_51 , V_10 ) ;
if ( ! V_42 )
return - V_11 ;
for ( V_7 = 0 ; V_7 < V_51 ; V_7 ++ ) {
V_22 = F_13 ( V_2 , 0 , 0 ,
V_44 + V_7 , 0 , & V_42 -> V_52 [ V_7 ] ) ;
if ( V_22 )
break;
}
if ( V_22 ) {
F_17 ( V_42 ) ;
break;
}
V_22 = F_4 ( V_2 , V_4 , L_3 ,
V_53 , F_11 ( V_53 ) ,
V_50 , V_42 -> V_52 , V_51 ) ;
if ( V_22 == - V_25 || V_22 == - V_27 ) {
V_42 -> V_54 = NULL ;
V_42 -> V_21 = V_50 ;
V_42 -> V_6 = V_51 ;
* V_43 = V_42 ;
V_43 = & V_42 -> V_54 ;
if ( V_22 == - V_27 ) {
F_18 ( L_4
L_5 ,
F_6 ( V_2 -> V_28 ) ,
V_50 , V_51 ) ;
}
V_22 = 0 ;
} else {
F_17 ( V_42 ) ;
}
V_44 += V_51 ;
} while ( ! V_22 );
if ( V_4 )
* V_43 = V_2 -> V_49 ;
return V_22 ;
}
int F_19 ( struct V_1 * V_2 )
{
return F_12 ( V_2 , NULL ) ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_41 * V_55 , * V_56 ;
V_55 = V_2 -> V_49 ;
while ( V_55 ) {
V_56 = V_55 ;
V_55 = V_55 -> V_54 ;
F_17 ( V_56 ) ;
}
V_2 -> V_49 = NULL ;
}
int F_21 ( struct V_3 * V_4 )
{
int V_22 ;
V_22 = F_12 ( V_4 -> V_2 , V_4 ) ;
if ( V_22 )
return V_22 ;
F_22 ( & V_4 -> V_2 -> V_57 ) ;
if ( V_4 -> V_14 == 0 ) {
V_4 -> V_14 = V_4 -> V_2 -> V_16 . V_14 ;
V_4 -> V_15 = V_4 -> V_2 -> V_16 . V_15 ;
}
return 0 ;
}
void F_23 ( struct V_3 * V_4 )
{
struct V_41 * V_55 , * V_56 ;
V_55 = V_4 -> V_49 ;
while ( V_55 && V_55 != V_4 -> V_2 -> V_49 ) {
V_56 = V_55 ;
V_55 = V_55 -> V_54 ;
F_17 ( V_56 ) ;
}
V_4 -> V_49 = NULL ;
F_24 ( & V_4 -> V_2 -> V_57 ) ;
}
