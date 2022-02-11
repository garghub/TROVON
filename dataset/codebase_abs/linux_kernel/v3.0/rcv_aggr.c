void *
F_1 ( T_1 V_1 )
{
struct V_2 * V_3 = NULL ;
struct V_4 * V_4 ;
T_2 V_5 ;
int V_6 = 0 ;
F_2 ( L_1 ) ;
do {
V_3 = F_3 ( sizeof( struct V_2 ) ) ;
if( ! V_3 ) {
F_2 ( L_2 ) ;
V_6 = V_7 ;
break;
}
F_4 ( V_3 , sizeof( struct V_2 ) ) ;
V_3 -> V_8 = V_9 ;
F_5 ( & V_3 -> V_10 , V_11 , V_3 ) ;
V_3 -> V_12 = false ;
F_6 ( & V_3 -> V_13 ) ;
V_3 -> V_1 = V_1 ;
V_3 -> V_1 ( & V_3 -> V_13 , V_14 ) ;
for( V_5 = 0 ; V_5 < V_15 ; V_5 ++ ) {
V_4 = F_7 ( V_3 , V_5 ) ;
V_4 -> V_16 = false ;
V_4 -> V_17 = false ;
V_4 -> V_18 = false ;
F_6 ( & V_4 -> V_19 ) ;
F_8 ( & V_4 -> V_20 ) ;
}
}while( false );
F_2 ( L_3 ,
( V_6 == 0 ) ? L_4 : L_5 ) ;
if ( V_6 ) {
F_9 ( V_3 ) ;
}
return ( ( V_6 == 0 ) ? V_3 : NULL ) ;
}
static void
F_10 ( struct V_2 * V_3 , T_2 V_21 )
{
struct V_4 * V_4 ;
struct V_22 * V_23 ;
F_11 ( V_21 < V_15 && V_3 ) ;
V_4 = F_7 ( V_3 , V_21 ) ;
V_23 = F_12 ( V_3 , V_21 ) ;
if( V_4 -> V_16 ) {
F_13 ( V_3 , V_21 , 0 , V_24 ) ;
}
V_4 -> V_16 = false ;
V_4 -> V_17 = false ;
V_4 -> V_18 = false ;
V_4 -> V_25 = 0 ;
V_4 -> V_26 = 0 ;
V_4 -> V_27 = 0 ;
if( V_4 -> V_28 ) {
F_14 ( V_4 -> V_28 ) ;
V_4 -> V_28 = NULL ;
}
F_4 ( V_23 , sizeof( struct V_22 ) ) ;
}
void
F_9 ( void * V_29 )
{
struct V_2 * V_3 = (struct V_2 * ) V_29 ;
struct V_4 * V_4 ;
T_2 V_5 , V_30 ;
F_2 ( L_6 , V_31 , V_3 ) ;
F_11 ( V_3 ) ;
if( V_3 ) {
if( V_3 -> V_12 ) {
F_15 ( & V_3 -> V_10 ) ;
V_3 -> V_12 = false ;
}
for( V_5 = 0 ; V_5 < V_15 ; V_5 ++ ) {
V_4 = F_7 ( V_3 , V_5 ) ;
if( V_4 -> V_28 ) {
for( V_30 = 0 ; V_30 < V_4 -> V_27 ; V_30 ++ ) {
if( V_4 -> V_28 [ V_30 ] . V_32 ) {
F_16 ( V_4 -> V_28 [ V_30 ] . V_32 ) ;
}
}
F_14 ( V_4 -> V_28 ) ;
}
while( F_17 ( & V_4 -> V_19 ) ) {
F_16 ( F_18 ( & V_4 -> V_19 ) ) ;
}
if ( F_19 ( & V_4 -> V_20 ) ) {
F_20 ( & V_4 -> V_20 ) ;
}
}
while( F_17 ( & V_3 -> V_13 ) ) {
F_16 ( F_18 ( & V_3 -> V_13 ) ) ;
}
F_14 ( V_3 ) ;
}
F_2 ( L_7 ) ;
}
void
F_21 ( void * V_29 , void * V_33 , T_3 V_34 )
{
struct V_2 * V_3 = (struct V_2 * ) V_29 ;
F_11 ( V_3 && V_34 && V_33 ) ;
V_3 -> V_35 = V_34 ;
V_3 -> V_33 = V_33 ;
}
void
F_22 ( void * V_29 , T_2 V_21 , T_4 V_36 )
{
struct V_2 * V_3 = (struct V_2 * ) V_29 ;
struct V_22 * V_23 ;
F_11 ( V_3 ) ;
V_23 = F_12 ( V_3 , V_21 ) ;
V_23 -> V_37 ++ ;
F_13 ( V_3 , V_21 , V_36 , V_24 ) ;
}
void
F_23 ( void * V_29 , T_2 V_21 , T_4 V_36 , T_2 V_25 )
{
struct V_2 * V_3 = (struct V_2 * ) V_29 ;
struct V_4 * V_4 ;
struct V_22 * V_23 ;
F_11 ( V_3 ) ;
V_4 = F_7 ( V_3 , V_21 ) ;
V_23 = F_12 ( V_3 , V_21 ) ;
F_2 ( L_8 , V_31 , V_25 , V_4 -> V_16 ) ;
if( V_25 < V_38 || V_25 > V_39 ) {
F_2 ( L_9 , V_25 , V_21 ) ;
}
if( V_4 -> V_16 ) {
F_10 ( V_3 , V_21 ) ;
}
V_4 -> V_26 = V_36 ;
V_4 -> V_28 = F_3 ( F_24 ( V_25 ) ) ;
if( ( V_4 -> V_28 == NULL ) ) {
F_2 ( L_10 , V_21 ) ;
F_11 ( 0 ) ;
}
F_4 ( V_4 -> V_28 , F_24 ( V_25 ) ) ;
V_4 -> V_25 = V_25 ;
V_4 -> V_27 = F_25 ( V_25 ) ;
if( F_17 ( & V_4 -> V_19 ) != 0 ) {
F_2 ( L_11 ) ;
F_11 ( 0 ) ;
}
V_4 -> V_16 = true ;
}
void
F_26 ( void * V_29 , T_2 V_21 )
{
struct V_2 * V_3 = (struct V_2 * ) V_29 ;
struct V_4 * V_4 ;
F_11 ( V_3 ) ;
F_2 ( L_12 , V_31 , V_21 ) ;
V_4 = F_7 ( V_3 , V_21 ) ;
if( V_4 -> V_16 ) {
F_10 ( V_3 , V_21 ) ;
}
}
static void
F_13 ( struct V_2 * V_3 , T_2 V_21 , T_4 V_36 , T_2 V_40 )
{
struct V_4 * V_4 ;
struct V_41 * V_42 ;
T_4 V_43 , V_44 , V_45 ;
struct V_22 * V_23 ;
F_11 ( V_3 ) ;
V_4 = F_7 ( V_3 , V_21 ) ;
V_23 = F_12 ( V_3 , V_21 ) ;
V_43 = F_27 ( V_4 -> V_26 , V_4 -> V_27 ) ;
V_45 = ( V_36 ) ? V_36 : V_4 -> V_26 ;
V_44 = F_27 ( V_45 , V_4 -> V_27 ) ;
F_28 ( & V_4 -> V_20 ) ;
do {
V_42 = & V_4 -> V_28 [ V_43 ] ;
if( ( V_40 == V_46 ) && ( ! V_42 -> V_32 ) )
break;
if( V_42 -> V_32 ) {
if( V_42 -> V_47 ) {
F_29 ( V_3 , V_4 , & V_42 -> V_32 ) ;
} else {
F_30 ( & V_4 -> V_19 , V_42 -> V_32 ) ;
}
V_42 -> V_32 = NULL ;
} else {
V_23 -> V_48 ++ ;
}
V_4 -> V_26 = F_31 ( V_4 -> V_26 ) ;
V_43 = F_27 ( V_4 -> V_26 , V_4 -> V_27 ) ;
} while( V_43 != V_44 );
F_32 ( & V_4 -> V_20 ) ;
V_23 -> V_49 += F_17 ( & V_4 -> V_19 ) ;
F_33 ( V_3 , & V_4 -> V_19 ) ;
}
static void *
F_34 ( struct V_2 * V_3 )
{
void * V_50 = NULL ;
if ( F_17 ( & V_3 -> V_13 ) < ( V_14 >> 2 ) ) {
V_3 -> V_1 ( & V_3 -> V_13 , V_14 ) ;
}
if ( F_17 ( & V_3 -> V_13 ) ) {
V_50 = F_18 ( & V_3 -> V_13 ) ;
}
return V_50 ;
}
static void
F_29 ( struct V_2 * V_3 , struct V_4 * V_4 , void * * V_32 )
{
void * V_51 ;
T_4 V_52 , V_53 , V_54 , V_55 ;
T_2 * V_56 ;
V_54 = sizeof( V_57 ) ;
V_56 = F_35 ( * V_32 ) + V_54 ;
V_55 = F_36 ( * V_32 ) - V_54 ;
while( V_55 > V_54 ) {
V_53 = F_37 ( ( ( V_57 * ) V_56 ) -> V_58 ) ;
#define F_38 1508
#define F_39 46
if( V_53 < F_39 || V_53 > F_38 ) {
F_2 ( L_13 , V_53 ) ;
break;
}
V_52 = V_53 + V_54 ;
V_51 = F_34 ( V_3 ) ;
if( V_51 == NULL ) {
F_2 ( L_14 ) ;
break;
}
memcpy ( F_35 ( V_51 ) , V_56 , V_52 ) ;
F_40 ( V_51 , V_52 ) ;
if ( F_41 ( V_51 ) != 0 ) {
F_2 ( L_15 ) ;
F_16 ( V_51 ) ;
break;
}
F_30 ( & V_4 -> V_19 , V_51 ) ;
if ( ( V_55 - V_52 ) == 0 ) {
break;
}
V_52 = ( ( V_52 + 3 ) & ~ 3 ) ;
V_56 += V_52 ;
V_55 -= V_52 ;
}
F_16 ( * V_32 ) ;
* V_32 = NULL ;
}
void
F_42 ( void * V_29 , T_2 V_21 , T_4 V_36 , bool V_47 , void * * V_32 )
{
struct V_2 * V_3 = (struct V_2 * ) V_29 ;
struct V_4 * V_4 ;
struct V_22 * V_23 ;
T_4 V_43 , V_59 , V_60 , V_61 ;
T_4 * V_62 ;
struct V_41 * V_42 ;
T_5 * log ;
F_11 ( V_3 ) ;
F_11 ( V_21 < V_15 ) ;
V_4 = F_7 ( V_3 , V_21 ) ;
V_23 = F_12 ( V_3 , V_21 ) ;
V_23 -> V_63 ++ ;
if( ! V_4 -> V_16 ) {
if( V_47 ) {
F_29 ( V_3 , V_4 , V_32 ) ;
V_23 -> V_64 ++ ;
F_33 ( V_3 , & V_4 -> V_19 ) ;
}
return;
}
V_59 = V_4 -> V_26 ;
V_60 = V_36 ;
V_61 = ( V_59 + V_4 -> V_27 - 1 ) & V_65 ;
log = & V_3 -> V_66 ;
V_62 = & log -> V_67 ;
log -> V_68 [ * V_62 ] . V_60 = V_60 ;
log -> V_68 [ * V_62 ] . V_59 = V_59 ;
log -> V_68 [ * V_62 ] . V_61 = V_61 ;
* V_62 = F_31 ( * V_62 ) ;
if( ( ( V_59 < V_61 ) && ( V_60 < V_59 || V_60 > V_61 ) ) ||
( ( V_59 > V_61 ) && ( V_60 > V_61 ) && ( V_60 < V_59 ) ) ) {
T_4 V_69 ;
V_69 = ( V_61 + V_4 -> V_27 - 1 ) & V_65 ;
if( ( ( V_61 < V_69 ) && ( V_60 < V_61 || V_60 > V_69 ) ) ||
( ( V_61 > V_69 ) && ( V_60 > V_69 ) && ( V_60 < V_61 ) ) ) {
F_13 ( V_3 , V_21 , 0 , V_24 ) ;
if( V_60 >= V_4 -> V_27 - 1 ) {
V_4 -> V_26 = V_60 - ( V_4 -> V_27 - 1 ) ;
} else{
V_4 -> V_26 = V_65 - ( V_4 -> V_27 - 2 - V_60 ) ;
}
} else {
if( V_60 >= V_4 -> V_27 - 1 ) {
V_59 = V_60 - ( V_4 -> V_27 - 1 ) ;
} else{
V_59 = V_65 - ( V_4 -> V_27 - 2 - V_60 ) ;
}
F_13 ( V_3 , V_21 , V_59 , V_24 ) ;
}
V_23 -> V_70 ++ ;
}
V_43 = F_27 ( V_36 , V_4 -> V_27 ) ;
V_42 = & V_4 -> V_28 [ V_43 ] ;
F_28 ( & V_4 -> V_20 ) ;
if( V_42 -> V_32 ) {
F_16 ( V_42 -> V_32 ) ;
V_23 -> V_71 ++ ;
}
V_42 -> V_32 = * V_32 ;
V_42 -> V_47 = V_47 ;
V_42 -> V_36 = V_36 ;
if( V_42 -> V_47 ) {
V_23 -> V_64 ++ ;
} else {
V_23 -> V_72 ++ ;
}
F_32 ( & V_4 -> V_20 ) ;
* V_32 = NULL ;
F_13 ( V_3 , V_21 , 0 , V_46 ) ;
if( V_3 -> V_12 ) {
V_4 -> V_17 = true ;
} else{
for( V_43 = 0 ; V_43 < V_4 -> V_27 ; V_43 ++ ) {
if( V_4 -> V_28 [ V_43 ] . V_32 ) {
V_3 -> V_12 = true ;
F_43 ( & V_3 -> V_10 , V_73 , 0 ) ;
V_4 -> V_17 = false ;
V_4 -> V_18 = true ;
break;
}
}
}
}
void
F_44 ( void * V_29 )
{
T_2 V_21 ;
struct V_2 * V_3 = (struct V_2 * ) V_29 ;
F_11 ( V_3 ) ;
for( V_21 = 0 ; V_21 < V_15 ; V_21 ++ ) {
F_10 ( V_3 , V_21 ) ;
}
}
static void
V_11 ( unsigned long V_74 )
{
T_2 V_5 , V_75 ;
struct V_2 * V_3 = (struct V_2 * ) V_74 ;
struct V_4 * V_4 ;
struct V_22 * V_23 ;
for( V_5 = 0 ; V_5 < V_15 ; V_5 ++ ) {
V_4 = F_7 ( V_3 , V_5 ) ;
V_23 = F_12 ( V_3 , V_5 ) ;
if( V_4 -> V_16 == false ||
V_4 -> V_18 == false ||
V_4 -> V_17 == true ) {
continue;
}
V_23 -> V_76 ++ ;
F_2 ( L_16 , V_4 -> V_26 , ( ( V_4 -> V_26 + V_4 -> V_27 - 1 ) & V_65 ) ) ;
F_13 ( V_3 , V_5 , 0 , V_24 ) ;
}
V_3 -> V_12 = false ;
for( V_5 = 0 ; V_5 < V_15 ; V_5 ++ ) {
V_4 = F_7 ( V_3 , V_5 ) ;
if( V_4 -> V_16 == true && V_4 -> V_28 ) {
for( V_75 = 0 ; V_75 < V_4 -> V_27 ; V_75 ++ )
{
if( V_4 -> V_28 [ V_75 ] . V_32 )
{
V_3 -> V_12 = true ;
V_4 -> V_18 = true ;
V_4 -> V_17 = false ;
break;
}
}
if( V_75 >= V_4 -> V_27 ) {
V_4 -> V_18 = false ;
}
}
}
if( V_3 -> V_12 ) {
F_43 ( & V_3 -> V_10 , V_73 , 0 ) ;
}
}
static void
F_33 ( struct V_2 * V_3 , T_6 * V_19 )
{
void * V_32 ;
while( ( V_32 = F_18 ( V_19 ) ) ) {
V_3 -> V_35 ( V_3 -> V_33 , V_32 ) ;
}
}
void
F_45 ( void * V_29 , T_5 * * V_77 )
{
struct V_2 * V_3 = (struct V_2 * ) V_29 ;
struct V_4 * V_4 ;
struct V_22 * V_23 ;
T_2 V_5 ;
* V_77 = & V_3 -> V_66 ;
F_2 ( L_17 ) ;
F_2 ( L_18 ) ;
for( V_5 = 0 ; V_5 < V_15 ; V_5 ++ ) {
V_23 = F_12 ( V_3 , V_5 ) ;
V_4 = F_7 ( V_3 , V_5 ) ;
F_2 ( L_19 , V_5 , V_23 -> V_63 , V_23 -> V_71 ,
V_23 -> V_70 , V_23 -> V_72 ,
V_23 -> V_64 , V_23 -> V_49 , V_23 -> V_76 ,
V_23 -> V_48 , V_23 -> V_37 ,
V_4 -> V_26 ) ;
}
F_2 ( L_20 ) ;
}
