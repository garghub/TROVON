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
struct V_11 * V_17 ;
int V_18 = 0 ;
if ( V_14 & 0x80000000 ) {
V_14 = ~ V_14 + 1 ;
V_18 = 1 ;
}
if ( V_16 ) {
char * V_19 = F_9 ( V_16 -> V_20 + V_14 , V_21 ) ;
if ( ! V_19 )
return - V_22 ;
memcpy ( V_19 , V_16 -> V_15 , V_16 -> V_20 ) ;
memcpy ( V_19 + V_16 -> V_20 , V_15 , V_14 ) ;
F_10 ( V_16 -> V_15 ) ;
V_16 -> V_15 = V_19 ;
V_16 -> V_20 += V_14 ;
} else {
V_16 = F_9 ( sizeof( * V_16 ) , V_21 ) ;
if ( ! V_16 )
return - V_22 ;
V_16 -> V_13 = F_11 ( V_13 , V_21 ) ;
if ( ! V_16 -> V_13 ) {
F_10 ( V_16 ) ;
return - V_22 ;
}
V_16 -> V_20 = V_14 ;
V_16 -> V_15 = F_9 ( V_16 -> V_20 , V_21 ) ;
if ( ! V_16 -> V_15 ) {
F_10 ( V_16 -> V_13 ) ;
F_10 ( V_16 ) ;
return - V_22 ;
}
memcpy ( V_16 -> V_15 , V_15 , V_14 ) ;
* V_12 = V_16 ;
}
if ( ! V_18 ) {
V_17 = F_12 ( V_9 , V_16 -> V_13 , NULL ) ;
if ( V_17 )
F_13 ( V_9 , V_16 , V_17 ) ;
else
F_14 ( V_9 , V_16 ) ;
V_16 = NULL ;
}
return 0 ;
}
static int F_15 ( T_1 V_7 )
{
struct V_23 * V_24 ;
struct V_8 * V_9 ;
struct V_11 * V_12 = NULL ;
int V_25 , V_3 ;
char * V_26 ;
char * V_27 ;
int V_28 ;
V_28 = F_16 ( L_1 ) ;
if ( V_28 == V_29 )
return - V_30 ;
V_27 = F_9 ( V_6 , V_21 ) ;
if ( ! V_27 )
return - V_22 ;
V_9 = F_6 ( V_7 ) ;
if ( ! V_9 ) {
F_10 ( V_27 ) ;
return - V_10 ;
}
V_24 = (struct V_23 * ) & V_27 [ 0 ] ;
V_24 -> V_7 = V_7 ;
do {
V_3 = F_1 ( V_28 , V_27 ) ;
if ( V_3 < 0 )
break;
V_26 = V_27 + sizeof( * V_24 ) ;
for ( V_25 = 0 ; V_25 < V_24 -> V_31 ; V_25 ++ ) {
char * V_32 ;
T_1 V_14 ;
V_32 = V_26 + 1 ;
V_26 += strlen ( V_32 ) + 1 ;
V_14 = * V_26 ++ ;
switch ( V_14 ) {
case 0x00000000 :
break;
case 0x80000000 :
V_12 = F_12 ( V_9 , V_32 , NULL ) ;
F_17 ( V_9 , V_12 ) ;
V_12 = NULL ;
break;
default:
V_3 = F_8 ( V_9 , & V_12 , V_32 ,
V_14 , V_26 ) ;
if ( V_3 ) {
F_18 ( V_33 L_2
L_3 , V_32 ) ;
}
V_26 += V_14 ;
}
}
} while ( V_3 == 1 );
F_19 ( V_9 ) ;
F_10 ( V_27 ) ;
return 0 ;
}
static int F_20 ( T_1 V_34 , T_1 V_35 )
{
struct V_8 * V_9 ;
struct V_8 * V_36 ;
int V_3 ;
V_9 = F_21 ( V_35 ) ;
if ( ! V_9 )
return - V_10 ;
V_36 = F_6 ( V_34 ) ;
if ( ! V_36 ) {
F_22 ( V_9 ) ;
return - V_10 ;
}
V_9 -> V_37 = V_36 ;
V_3 = F_23 ( V_9 ) ;
if ( V_3 )
F_22 ( V_9 ) ;
F_19 ( V_36 ) ;
return V_3 ;
}
static int F_24 ( void )
{
char * V_27 ;
T_1 * V_38 ;
int V_39 ;
int V_3 ;
V_39 = F_16 ( L_4 ) ;
if ( V_39 == V_29 )
return - V_30 ;
V_27 = F_9 ( V_6 , V_21 ) ;
if ( ! V_27 )
return - V_22 ;
do {
V_3 = F_1 ( V_39 , V_27 ) ;
if ( V_3 && V_3 != 1 )
break;
V_38 = ( T_1 * ) V_27 + 4 ;
while ( * V_38 & V_40 ) {
int V_25 ;
T_1 V_41 = * V_38 & V_40 ;
int V_42 = * V_38 & V_43 ;
V_38 ++ ;
for ( V_25 = 0 ; V_25 < V_42 ; V_25 ++ ) {
T_1 V_7 = * V_38 ++ ;
T_1 V_35 ;
switch ( V_41 ) {
case V_44 :
F_5 ( V_7 ) ;
break;
case V_45 :
F_15 ( V_7 ) ;
break;
case V_46 :
V_35 = * V_38 ++ ;
F_20 ( V_7 , V_35 ) ;
break;
}
}
}
} while ( V_3 == 1 );
F_10 ( V_27 ) ;
return V_3 ;
}
void F_25 ( void )
{
int V_3 ;
int V_47 ;
V_3 = F_24 () ;
if ( V_3 ) {
F_18 ( V_33 L_5
L_6 , V_3 ) ;
return;
}
V_47 = F_16 ( L_7 ) ;
if ( V_47 == V_29 ) {
F_18 ( V_33 L_8
L_9 ) ;
return;
}
V_3 = F_3 ( V_47 , 0 , 1 , NULL ) ;
if ( ! V_3 ) {
V_3 = F_24 () ;
if ( V_3 )
F_18 ( V_33 L_10
L_11 , V_3 ) ;
} else {
F_18 ( V_33 L_12 , V_3 ) ;
return;
}
return;
}
static T_2 F_26 ( struct V_48 * V_48 , struct V_49 * V_50 ,
const char * V_2 , T_3 V_51 )
{
struct V_52 args ;
T_4 V_53 ;
int V_3 ;
V_3 = F_27 ( V_2 , 0 , & V_53 ) ;
if ( V_3 )
return V_3 ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_1 = F_16 ( L_13 ) ;
args . V_54 = 2 ;
args . V_55 = 1 ;
args . args [ 0 ] = V_53 >> 32 ;
args . args [ 1 ] = V_53 & 0xffffffff ;
args . V_56 = & args . args [ args . V_54 ] ;
do {
args . V_56 [ 0 ] = 0 ;
V_3 = F_28 ( & args ) ;
if ( ! V_3 && args . V_56 [ 0 ] == V_57 )
F_29 ( 1 ) ;
} while ( ! V_3 && args . V_56 [ 0 ] == V_57 );
if ( V_3 )
return V_3 ;
else if ( args . V_56 [ 0 ] )
return args . V_56 [ 0 ] ;
F_25 () ;
return V_51 ;
}
static int T_5 F_30 ( void )
{
int V_3 ;
V_58 = F_31 ( L_14 , V_59 ) ;
if ( ! V_58 )
return - V_22 ;
V_3 = F_32 ( V_58 , & V_60 . V_50 ) ;
return V_3 ;
}
