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
V_10 = F_6 ( F_7 ( V_8 ) ) ;
if ( ! V_10 )
return - V_11 ;
F_8 ( V_10 ) ;
F_9 ( V_10 ) ;
return 0 ;
}
static int F_10 ( struct V_9 * V_10 , struct V_12 * * V_13 ,
const char * V_14 , T_3 V_15 , char * V_16 )
{
struct V_12 * V_17 = * V_13 ;
int V_18 = 0 ;
if ( V_15 & 0x80000000 ) {
V_15 = ~ V_15 + 1 ;
V_18 = 1 ;
}
if ( V_17 ) {
char * V_19 = F_11 ( V_17 -> V_20 + V_15 , V_21 ) ;
if ( ! V_19 )
return - V_22 ;
memcpy ( V_19 , V_17 -> V_16 , V_17 -> V_20 ) ;
memcpy ( V_19 + V_17 -> V_20 , V_16 , V_15 ) ;
F_12 ( V_17 -> V_16 ) ;
V_17 -> V_16 = V_19 ;
V_17 -> V_20 += V_15 ;
} else {
V_17 = F_11 ( sizeof( * V_17 ) , V_21 ) ;
if ( ! V_17 )
return - V_22 ;
V_17 -> V_14 = F_13 ( V_14 , V_21 ) ;
if ( ! V_17 -> V_14 ) {
F_12 ( V_17 ) ;
return - V_22 ;
}
V_17 -> V_20 = V_15 ;
V_17 -> V_16 = F_11 ( V_17 -> V_20 , V_21 ) ;
if ( ! V_17 -> V_16 ) {
F_12 ( V_17 -> V_14 ) ;
F_12 ( V_17 ) ;
return - V_22 ;
}
memcpy ( V_17 -> V_16 , V_16 , V_15 ) ;
* V_13 = V_17 ;
}
if ( ! V_18 ) {
F_14 ( V_10 , V_17 ) ;
* V_13 = NULL ;
}
return 0 ;
}
static int F_15 ( T_2 V_8 , T_1 V_3 )
{
struct V_23 * V_24 ;
struct V_9 * V_10 ;
struct V_12 * V_13 = NULL ;
int V_25 , V_4 , V_26 ;
char * V_27 ;
char * V_28 ;
int V_29 ;
T_3 V_30 ;
T_3 V_15 ;
V_29 = F_16 ( L_1 ) ;
if ( V_29 == V_31 )
return - V_32 ;
V_28 = F_11 ( V_7 , V_21 ) ;
if ( ! V_28 )
return - V_22 ;
V_10 = F_6 ( F_7 ( V_8 ) ) ;
if ( ! V_10 ) {
F_12 ( V_28 ) ;
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
V_30 = F_7 ( V_24 -> V_30 ) ;
if ( * V_27 == 0 ) {
V_27 ++ ;
V_15 = F_7 ( * ( T_2 * ) V_27 ) ;
V_27 += V_15 + sizeof( V_15 ) ;
V_30 -- ;
}
for ( V_25 = 0 ; V_25 < V_30 ; V_25 ++ ) {
char * V_33 ;
V_33 = V_27 ;
V_27 += strlen ( V_33 ) + 1 ;
V_15 = F_7 ( * ( T_2 * ) V_27 ) ;
V_27 += sizeof( V_15 ) ;
switch ( V_15 ) {
case 0x00000000 :
break;
case 0x80000000 :
F_17 ( V_10 , F_18 ( V_10 ,
V_33 , NULL ) ) ;
V_13 = NULL ;
break;
default:
V_4 = F_10 ( V_10 , & V_13 , V_33 ,
V_15 , V_27 ) ;
if ( V_4 ) {
F_19 ( V_34 L_2
L_3 , V_33 ) ;
}
V_27 += V_15 ;
}
}
} while ( V_26 == 1 );
F_9 ( V_10 ) ;
F_12 ( V_28 ) ;
return 0 ;
}
static int F_20 ( T_2 V_35 , T_2 V_36 )
{
struct V_9 * V_10 ;
struct V_9 * V_37 ;
int V_4 ;
V_37 = F_6 ( F_7 ( V_35 ) ) ;
if ( ! V_37 )
return - V_11 ;
V_10 = F_21 ( V_36 , V_37 ) ;
if ( ! V_10 )
return - V_11 ;
V_4 = F_22 ( V_10 ) ;
if ( V_4 )
F_23 ( V_10 ) ;
F_9 ( V_37 ) ;
return V_4 ;
}
static void F_24 ( T_2 V_8 )
{
struct V_38 * V_39 ;
struct V_9 * V_10 ;
V_10 = F_6 ( F_7 ( V_8 ) ) ;
if ( V_10 ) {
F_9 ( V_10 ) ;
return;
}
V_39 = F_11 ( sizeof( * V_39 ) , V_21 ) ;
if( ! V_39 )
return;
V_39 -> V_40 = V_41 ;
V_39 -> V_42 = V_43 ;
V_39 -> V_44 = V_45 ;
V_39 -> V_46 . V_36 = V_8 ;
F_25 ( V_39 , NULL , NULL ) ;
F_12 ( V_39 ) ;
}
int F_26 ( T_1 V_3 )
{
char * V_28 ;
T_2 * V_47 ;
int V_48 ;
int V_4 ;
V_48 = F_16 ( L_4 ) ;
if ( V_48 == V_31 )
return - V_32 ;
V_28 = F_11 ( V_7 , V_21 ) ;
if ( ! V_28 )
return - V_22 ;
do {
V_4 = F_1 ( V_48 , V_28 , V_3 ) ;
if ( V_4 && V_4 != 1 )
break;
V_47 = ( T_2 * ) V_28 + 4 ;
while ( F_7 ( * V_47 ) & V_49 ) {
int V_25 ;
T_3 V_42 = F_7 ( * V_47 ) & V_49 ;
T_3 V_50 = F_7 ( * V_47 ) & V_51 ;
V_47 ++ ;
for ( V_25 = 0 ; V_25 < V_50 ; V_25 ++ ) {
T_2 V_8 = * V_47 ++ ;
T_2 V_36 ;
switch ( V_42 ) {
case V_52 :
F_5 ( V_8 ) ;
break;
case V_53 :
F_15 ( V_8 , V_3 ) ;
if ( V_3 == V_54 )
F_24 ( V_8 ) ;
break;
case V_55 :
V_36 = * V_47 ++ ;
F_20 ( V_8 , V_36 ) ;
break;
}
}
}
} while ( V_4 == 1 );
F_12 ( V_28 ) ;
return V_4 ;
}
void F_27 ( void )
{
int V_4 ;
int V_56 ;
V_56 = F_16 ( L_5 ) ;
if ( V_56 == V_31 ) {
F_19 ( V_34 L_6
L_7 ) ;
return;
}
do {
V_4 = F_3 ( V_56 , 0 , 1 , NULL ) ;
} while ( F_28 ( V_4 ) );
if ( V_4 )
F_19 ( V_34 L_8 , V_4 ) ;
V_4 = F_26 ( V_57 ) ;
if ( V_4 )
F_19 ( V_34 L_9
L_10 , V_4 ) ;
return;
}
static T_4 F_29 ( struct V_58 * V_58 , struct V_59 * V_60 ,
const char * V_2 , T_5 V_61 )
{
T_6 V_62 ;
int V_4 ;
V_4 = F_30 ( V_2 , 0 , & V_62 ) ;
if ( V_4 )
return V_4 ;
do {
V_4 = F_31 ( V_62 ) ;
if ( V_4 == - V_63 )
F_32 ( 1 ) ;
} while ( V_4 == - V_63 );
if ( V_4 )
return V_4 ;
F_27 () ;
return V_61 ;
}
static int T_7 F_33 ( void )
{
int V_4 ;
V_64 = F_34 ( L_11 , V_65 ) ;
if ( ! V_64 )
return - V_22 ;
V_4 = F_35 ( V_64 , & V_66 . V_60 ) ;
if ( V_4 )
F_36 ( L_12 , V_4 ) ;
V_4 = F_35 ( V_64 , & V_67 . V_60 . V_60 ) ;
if ( V_4 )
F_36 ( L_13 , V_4 ) ;
return 0 ;
}
