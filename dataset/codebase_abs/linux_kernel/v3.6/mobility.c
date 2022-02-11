static int F_1 ( int V_1 , char * V_2 )
{
int V_3 ;
F_2 ( & V_4 ) ;
memcpy ( V_5 , V_2 , V_6 ) ;
V_3 = F_3 ( V_1 , 2 , 1 , NULL , V_5 , 1 ) ;
memcpy ( V_2 , V_5 , V_6 ) ;
F_4 ( & V_4 ) ;
return V_3 ;
}
static int F_5 ( T_1 V_7 )
{
struct V_8 * V_9 ;
V_9 = F_6 ( V_7 ) ;
if ( ! V_9 )
return - V_10 ;
F_7 ( V_9 ) ;
return 0 ;
}
static int F_8 ( struct V_8 * V_9 , struct V_11 * * V_12 ,
const char * V_13 , T_1 V_14 , char * V_15 )
{
struct V_11 * V_16 = * V_12 ;
int V_17 = 0 ;
if ( V_14 & 0x80000000 ) {
V_14 = ~ V_14 + 1 ;
V_17 = 1 ;
}
if ( V_16 ) {
char * V_18 = F_9 ( V_16 -> V_19 + V_14 , V_20 ) ;
if ( ! V_18 )
return - V_21 ;
memcpy ( V_18 , V_16 -> V_15 , V_16 -> V_19 ) ;
memcpy ( V_18 + V_16 -> V_19 , V_15 , V_14 ) ;
F_10 ( V_16 -> V_15 ) ;
V_16 -> V_15 = V_18 ;
V_16 -> V_19 += V_14 ;
} else {
V_16 = F_9 ( sizeof( * V_16 ) , V_20 ) ;
if ( ! V_16 )
return - V_21 ;
V_16 -> V_13 = F_11 ( V_13 , V_20 ) ;
if ( ! V_16 -> V_13 ) {
F_10 ( V_16 ) ;
return - V_21 ;
}
V_16 -> V_19 = V_14 ;
V_16 -> V_15 = F_9 ( V_16 -> V_19 , V_20 ) ;
if ( ! V_16 -> V_15 ) {
F_10 ( V_16 -> V_13 ) ;
F_10 ( V_16 ) ;
return - V_21 ;
}
memcpy ( V_16 -> V_15 , V_15 , V_14 ) ;
* V_12 = V_16 ;
}
if ( ! V_17 ) {
F_12 ( V_9 , V_16 ) ;
V_16 = NULL ;
}
return 0 ;
}
static int F_13 ( T_1 V_7 )
{
struct V_22 * V_23 ;
struct V_8 * V_9 ;
struct V_11 * V_12 = NULL ;
int V_24 , V_3 ;
char * V_25 ;
char * V_26 ;
int V_27 ;
V_27 = F_14 ( L_1 ) ;
if ( V_27 == V_28 )
return - V_29 ;
V_26 = F_9 ( V_6 , V_20 ) ;
if ( ! V_26 )
return - V_21 ;
V_9 = F_6 ( V_7 ) ;
if ( ! V_9 ) {
F_10 ( V_26 ) ;
return - V_10 ;
}
V_23 = (struct V_22 * ) & V_26 [ 0 ] ;
V_23 -> V_7 = V_7 ;
do {
V_3 = F_1 ( V_27 , V_26 ) ;
if ( V_3 < 0 )
break;
V_25 = V_26 + sizeof( * V_23 ) ;
for ( V_24 = 0 ; V_24 < V_23 -> V_30 ; V_24 ++ ) {
char * V_31 ;
T_1 V_14 ;
V_31 = V_25 + 1 ;
V_25 += strlen ( V_31 ) + 1 ;
V_14 = * V_25 ++ ;
switch ( V_14 ) {
case 0x00000000 :
break;
case 0x80000000 :
V_12 = F_15 ( V_9 , V_31 , NULL ) ;
F_16 ( V_9 , V_12 ) ;
V_12 = NULL ;
break;
default:
V_3 = F_8 ( V_9 , & V_12 , V_31 ,
V_14 , V_25 ) ;
if ( V_3 ) {
F_17 ( V_32 L_2
L_3 , V_31 ) ;
}
V_25 += V_14 ;
}
}
} while ( V_3 == 1 );
F_18 ( V_9 ) ;
F_10 ( V_26 ) ;
return 0 ;
}
static int F_19 ( T_1 V_33 , T_1 V_34 )
{
struct V_8 * V_9 ;
struct V_8 * V_35 ;
int V_3 ;
V_9 = F_20 ( V_34 ) ;
if ( ! V_9 )
return - V_10 ;
V_35 = F_6 ( V_33 ) ;
if ( ! V_35 ) {
F_21 ( V_9 ) ;
return - V_10 ;
}
V_9 -> V_36 = V_35 ;
V_3 = F_22 ( V_9 ) ;
if ( V_3 )
F_21 ( V_9 ) ;
F_18 ( V_35 ) ;
return V_3 ;
}
static int F_23 ( void )
{
char * V_26 ;
T_1 * V_37 ;
int V_38 ;
int V_3 ;
V_38 = F_14 ( L_4 ) ;
if ( V_38 == V_28 )
return - V_29 ;
V_26 = F_9 ( V_6 , V_20 ) ;
if ( ! V_26 )
return - V_21 ;
do {
V_3 = F_1 ( V_38 , V_26 ) ;
if ( V_3 && V_3 != 1 )
break;
V_37 = ( T_1 * ) V_26 + 4 ;
while ( * V_37 & V_39 ) {
int V_24 ;
T_1 V_40 = * V_37 & V_39 ;
int V_41 = * V_37 & V_42 ;
V_37 ++ ;
for ( V_24 = 0 ; V_24 < V_41 ; V_24 ++ ) {
T_1 V_7 = * V_37 ++ ;
T_1 V_34 ;
switch ( V_40 ) {
case V_43 :
F_5 ( V_7 ) ;
break;
case V_44 :
F_13 ( V_7 ) ;
break;
case V_45 :
V_34 = * V_37 ++ ;
F_19 ( V_7 , V_34 ) ;
break;
}
}
}
} while ( V_3 == 1 );
F_10 ( V_26 ) ;
return V_3 ;
}
void F_24 ( void )
{
int V_3 ;
int V_46 ;
V_3 = F_23 () ;
if ( V_3 ) {
F_17 ( V_32 L_5
L_6 , V_3 ) ;
return;
}
V_46 = F_14 ( L_7 ) ;
if ( V_46 == V_28 ) {
F_17 ( V_32 L_8
L_9 ) ;
return;
}
V_3 = F_3 ( V_46 , 0 , 1 , NULL ) ;
if ( ! V_3 ) {
V_3 = F_23 () ;
if ( V_3 )
F_17 ( V_32 L_10
L_11 , V_3 ) ;
} else {
F_17 ( V_32 L_12 , V_3 ) ;
return;
}
return;
}
static T_2 F_25 ( struct V_47 * V_47 , struct V_48 * V_49 ,
const char * V_2 , T_3 V_50 )
{
struct V_51 args ;
T_4 V_52 ;
int V_3 ;
V_3 = F_26 ( V_2 , 0 , & V_52 ) ;
if ( V_3 )
return V_3 ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_1 = F_14 ( L_13 ) ;
args . V_53 = 2 ;
args . V_54 = 1 ;
args . args [ 0 ] = V_52 >> 32 ;
args . args [ 1 ] = V_52 & 0xffffffff ;
args . V_55 = & args . args [ args . V_53 ] ;
do {
args . V_55 [ 0 ] = 0 ;
V_3 = F_27 ( & args ) ;
if ( ! V_3 && args . V_55 [ 0 ] == V_56 )
F_28 ( 1 ) ;
} while ( ! V_3 && args . V_55 [ 0 ] == V_56 );
if ( V_3 )
return V_3 ;
else if ( args . V_55 [ 0 ] )
return args . V_55 [ 0 ] ;
F_24 () ;
return V_50 ;
}
static int T_5 F_29 ( void )
{
int V_3 ;
V_57 = F_30 ( L_14 , V_58 ) ;
if ( ! V_57 )
return - V_21 ;
V_3 = F_31 ( V_57 , & V_59 . V_49 ) ;
return V_3 ;
}
