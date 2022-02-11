static int F_1 ( int V_1 , char * V_2 , T_1 V_3 )
{
int V_4 ;
F_2 ( & V_5 ) ;
memcpy ( V_6 , V_2 , V_7 ) ;
V_4 = F_3 ( V_1 , 2 , 1 , NULL , V_6 , V_3 ) ;
memcpy ( V_2 , V_6 , V_7 ) ;
F_4 ( & V_5 ) ;
return V_4 ;
}
static int F_5 ( T_2 V_8 )
{
struct V_9 * V_10 ;
V_10 = F_6 ( V_8 ) ;
if ( ! V_10 )
return - V_11 ;
F_7 ( V_10 ) ;
F_8 ( V_10 ) ;
return 0 ;
}
static int F_9 ( struct V_9 * V_10 , struct V_12 * * V_13 ,
const char * V_14 , T_2 V_15 , char * V_16 )
{
struct V_12 * V_17 = * V_13 ;
int V_18 = 0 ;
if ( V_15 & 0x80000000 ) {
V_15 = ~ V_15 + 1 ;
V_18 = 1 ;
}
if ( V_17 ) {
char * V_19 = F_10 ( V_17 -> V_20 + V_15 , V_21 ) ;
if ( ! V_19 )
return - V_22 ;
memcpy ( V_19 , V_17 -> V_16 , V_17 -> V_20 ) ;
memcpy ( V_19 + V_17 -> V_20 , V_16 , V_15 ) ;
F_11 ( V_17 -> V_16 ) ;
V_17 -> V_16 = V_19 ;
V_17 -> V_20 += V_15 ;
} else {
V_17 = F_10 ( sizeof( * V_17 ) , V_21 ) ;
if ( ! V_17 )
return - V_22 ;
V_17 -> V_14 = F_12 ( V_14 , V_21 ) ;
if ( ! V_17 -> V_14 ) {
F_11 ( V_17 ) ;
return - V_22 ;
}
V_17 -> V_20 = V_15 ;
V_17 -> V_16 = F_10 ( V_17 -> V_20 , V_21 ) ;
if ( ! V_17 -> V_16 ) {
F_11 ( V_17 -> V_14 ) ;
F_11 ( V_17 ) ;
return - V_22 ;
}
memcpy ( V_17 -> V_16 , V_16 , V_15 ) ;
* V_13 = V_17 ;
}
if ( ! V_18 ) {
F_13 ( V_10 , V_17 ) ;
* V_13 = NULL ;
}
return 0 ;
}
static int F_14 ( T_2 V_8 , T_1 V_3 )
{
struct V_23 * V_24 ;
struct V_9 * V_10 ;
struct V_12 * V_13 = NULL ;
int V_25 , V_4 , V_26 ;
char * V_27 ;
char * V_28 ;
int V_29 ;
T_2 V_15 ;
V_29 = F_15 ( L_1 ) ;
if ( V_29 == V_30 )
return - V_31 ;
V_28 = F_10 ( V_7 , V_21 ) ;
if ( ! V_28 )
return - V_22 ;
V_10 = F_6 ( V_8 ) ;
if ( ! V_10 ) {
F_11 ( V_28 ) ;
return - V_11 ;
}
V_24 = (struct V_23 * ) & V_28 [ 0 ] ;
V_24 -> V_8 = V_8 ;
do {
V_26 = F_1 ( V_29 , V_28 ,
V_3 ) ;
if ( V_26 < 0 )
break;
V_27 = V_28 + sizeof( * V_24 ) ;
if ( * V_27 == 0 ) {
V_27 ++ ;
V_15 = * ( T_2 * ) V_27 ;
V_27 += V_15 + sizeof( V_15 ) ;
V_24 -> V_32 -- ;
}
for ( V_25 = 0 ; V_25 < V_24 -> V_32 ; V_25 ++ ) {
char * V_33 ;
V_33 = V_27 ;
V_27 += strlen ( V_33 ) + 1 ;
V_15 = * ( T_2 * ) V_27 ;
V_27 += sizeof( V_15 ) ;
switch ( V_15 ) {
case 0x00000000 :
break;
case 0x80000000 :
V_13 = F_16 ( V_10 , V_33 , NULL ) ;
F_17 ( V_10 , V_13 ) ;
V_13 = NULL ;
break;
default:
V_4 = F_9 ( V_10 , & V_13 , V_33 ,
V_15 , V_27 ) ;
if ( V_4 ) {
F_18 ( V_34 L_2
L_3 , V_33 ) ;
}
V_27 += V_15 ;
}
}
} while ( V_26 == 1 );
F_8 ( V_10 ) ;
F_11 ( V_28 ) ;
return 0 ;
}
static int F_19 ( T_2 V_35 , T_2 V_36 )
{
struct V_9 * V_10 ;
struct V_9 * V_37 ;
int V_4 ;
V_37 = F_6 ( V_35 ) ;
if ( ! V_37 )
return - V_11 ;
V_10 = F_20 ( V_36 , V_37 ) ;
if ( ! V_10 )
return - V_11 ;
V_4 = F_21 ( V_10 ) ;
if ( V_4 )
F_22 ( V_10 ) ;
F_8 ( V_37 ) ;
return V_4 ;
}
int F_23 ( T_1 V_3 )
{
char * V_28 ;
T_2 * V_38 ;
int V_39 ;
int V_4 ;
V_39 = F_15 ( L_4 ) ;
if ( V_39 == V_30 )
return - V_31 ;
V_28 = F_10 ( V_7 , V_21 ) ;
if ( ! V_28 )
return - V_22 ;
do {
V_4 = F_1 ( V_39 , V_28 , V_3 ) ;
if ( V_4 && V_4 != 1 )
break;
V_38 = ( T_2 * ) V_28 + 4 ;
while ( * V_38 & V_40 ) {
int V_25 ;
T_2 V_41 = * V_38 & V_40 ;
int V_42 = * V_38 & V_43 ;
V_38 ++ ;
for ( V_25 = 0 ; V_25 < V_42 ; V_25 ++ ) {
T_2 V_8 = * V_38 ++ ;
T_2 V_36 ;
switch ( V_41 ) {
case V_44 :
F_5 ( V_8 ) ;
break;
case V_45 :
F_14 ( V_8 , V_3 ) ;
break;
case V_46 :
V_36 = * V_38 ++ ;
F_19 ( V_8 , V_36 ) ;
break;
}
}
}
} while ( V_4 == 1 );
F_11 ( V_28 ) ;
return V_4 ;
}
void F_24 ( void )
{
int V_4 ;
int V_47 ;
V_4 = F_23 ( V_48 ) ;
if ( V_4 ) {
F_18 ( V_34 L_5
L_6 , V_4 ) ;
return;
}
V_47 = F_15 ( L_7 ) ;
if ( V_47 == V_30 ) {
F_18 ( V_34 L_8
L_9 ) ;
return;
}
V_4 = F_3 ( V_47 , 0 , 1 , NULL ) ;
if ( ! V_4 ) {
V_4 = F_23 ( V_48 ) ;
if ( V_4 )
F_18 ( V_34 L_10
L_11 , V_4 ) ;
} else {
F_18 ( V_34 L_12 , V_4 ) ;
return;
}
return;
}
static T_3 F_25 ( struct V_49 * V_49 , struct V_50 * V_51 ,
const char * V_2 , T_4 V_52 )
{
struct V_53 args ;
T_5 V_54 ;
int V_4 ;
V_4 = F_26 ( V_2 , 0 , & V_54 ) ;
if ( V_4 )
return V_4 ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_1 = F_15 ( L_13 ) ;
args . V_55 = 2 ;
args . V_56 = 1 ;
args . args [ 0 ] = V_54 >> 32 ;
args . args [ 1 ] = V_54 & 0xffffffff ;
args . V_57 = & args . args [ args . V_55 ] ;
do {
args . V_57 [ 0 ] = 0 ;
V_4 = F_27 ( & args ) ;
if ( ! V_4 && args . V_57 [ 0 ] == V_58 )
F_28 ( 1 ) ;
} while ( ! V_4 && args . V_57 [ 0 ] == V_58 );
if ( V_4 )
return V_4 ;
else if ( args . V_57 [ 0 ] )
return args . V_57 [ 0 ] ;
F_24 () ;
return V_52 ;
}
static int T_6 F_29 ( void )
{
int V_4 ;
V_59 = F_30 ( L_14 , V_60 ) ;
if ( ! V_59 )
return - V_22 ;
V_4 = F_31 ( V_59 , & V_61 . V_51 ) ;
return V_4 ;
}
