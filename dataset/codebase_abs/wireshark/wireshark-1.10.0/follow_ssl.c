static int
F_1 ( void * V_1 , T_1 * V_2 , T_2 * T_3 V_3 , const void * V_4 )
{
T_4 * V_5 = ( T_4 * ) V_1 ;
T_5 * V_6 ;
T_6 * V_7 ;
T_7 V_8 ;
T_8 * V_9 ;
int V_10 = F_2 ( V_4 ) ;
T_9 * V_11 = ( T_9 * ) F_3 ( V_2 -> V_12 , V_10 , 0 ) ;
if ( ! V_11 || ! V_11 -> V_7 )
return 0 ;
V_8 = 0 ;
V_7 = V_11 -> V_7 ;
do {
V_8 += V_7 -> V_13 . V_14 ;
V_7 = V_7 -> V_15 ;
} while ( V_7 );
V_6 = ( T_5 * ) F_4 ( sizeof( T_5 ) + V_8 ) ;
if ( V_5 -> V_16 == 0 ) {
V_5 -> V_16 = V_2 -> V_17 ;
F_5 ( & V_5 -> V_18 , & V_2 -> V_19 ) ;
}
if ( F_6 ( & V_5 -> V_18 , & V_2 -> V_19 ) &&
V_5 -> V_16 == V_2 -> V_17 )
V_6 -> V_20 = 0 ;
else
V_6 -> V_20 = 1 ;
V_5 -> V_21 [ V_6 -> V_20 ] += V_8 ;
V_6 -> V_22 . V_22 = ( T_8 * ) ( V_6 + 1 ) ;
V_6 -> V_22 . V_14 = V_8 ;
V_7 = V_11 -> V_7 ;
V_9 = V_6 -> V_22 . V_22 ;
do {
memcpy ( V_9 , V_7 -> V_13 . V_22 , V_7 -> V_13 . V_14 ) ;
V_9 += V_7 -> V_13 . V_14 ;
V_7 = V_7 -> V_15 ;
} while ( V_7 );
V_5 -> V_23 = F_7 (
V_5 -> V_23 , V_6 ) ;
return 0 ;
}
void
F_8 ( T_10 * T_11 V_3 , T_12 V_22 V_3 )
{
T_10 * V_24 , * V_25 ;
T_13 * V_26 ;
const T_13 * V_27 ;
int V_28 , V_29 ;
const char * V_30 , * V_31 ;
char * V_32 , * V_33 ;
T_13 * V_34 = NULL ;
T_13 * V_35 = NULL ;
T_13 * V_36 = NULL ;
T_14 V_37 ;
T_4 * V_5 ;
T_15 * V_38 ;
if ( ! F_9 ( V_39 . T_3 ) ) {
F_10 ( V_40 , V_41 ,
L_1
L_2 ) ;
return;
}
V_5 = F_11 ( T_4 , 1 ) ;
V_5 -> V_42 = V_43 ;
F_12 () ;
V_26 = F_13 ( & V_39 . T_3 -> V_11 ) ;
if ( ! V_26 )
{
F_10 ( V_40 , V_41 ,
L_3
L_4 ) ;
F_14 ( V_5 ) ;
return;
}
V_25 = ( T_10 * ) F_15 ( F_16 ( V_44 ) , V_45 ) ;
V_24 = F_17 ( F_18 ( V_25 ) ) ;
V_5 -> V_24 = V_24 ;
V_27 =
( const T_13 * ) F_19 ( F_20 ( V_24 ) ) ;
V_29 = V_27 ? ( int ) strlen ( V_27 ) : 0 ;
V_28 = ( int ) strlen ( V_26 ) + V_29 + 16 ;
V_5 -> V_46 = ( T_13 * ) F_4 ( V_28 ) ;
if( V_29 ) {
F_21 ( V_5 -> V_46 , V_28 ,
L_5 , V_27 , V_26 ) ;
} else {
F_21 ( V_5 -> V_46 , V_28 ,
L_6 , V_26 ) ;
}
V_38 = F_22 ( L_7 , V_5 , V_26 , 0 ,
NULL , F_1 , NULL ) ;
if ( V_38 )
{
F_10 ( V_40 , V_41 ,
L_8 , V_38 -> V_47 ) ;
F_14 ( V_5 -> V_46 ) ;
F_14 ( V_5 ) ;
F_14 ( V_26 ) ;
return;
}
F_23 ( F_20 ( V_24 ) , V_26 ) ;
F_24 ( & V_39 , V_26 , TRUE ) ;
F_14 ( V_26 ) ;
F_25 ( V_5 ) ;
F_26 ( & V_37 ) ;
if ( V_37 . V_48 ) {
struct V_49 V_50 ;
memcpy ( & V_50 , V_37 . V_51 [ 0 ] , 16 ) ;
V_30 = F_27 ( & V_50 ) ;
memcpy ( & V_50 , V_37 . V_51 [ 0 ] , 16 ) ;
V_31 = F_27 ( & V_50 ) ;
} else {
T_16 V_50 ;
memcpy ( & V_50 , V_37 . V_51 [ 0 ] , 4 ) ;
V_30 = F_28 ( V_50 ) ;
memcpy ( & V_50 , V_37 . V_51 [ 1 ] , 4 ) ;
V_31 = F_28 ( V_50 ) ;
}
V_32 = F_29 ( V_37 . V_52 [ 0 ] ) ;
V_33 = F_29 ( V_37 . V_52 [ 1 ] ) ;
V_5 -> V_48 = V_37 . V_48 ;
V_36 = F_30 ( L_9 , V_5 -> V_21 [ 0 ] + V_5 -> V_21 [ 1 ] ) ;
if( V_5 -> V_16 == V_37 . V_52 [ 0 ] ) {
V_34 =
F_30 ( L_10 V_53 L_11 ,
V_30 , V_32 ,
V_31 , V_33 ,
V_5 -> V_21 [ 0 ] ) ;
V_35 =
F_30 ( L_10 V_53 L_11 ,
V_31 , V_33 ,
V_30 , V_32 ,
V_5 -> V_21 [ 1 ] ) ;
} else {
V_34 =
F_30 ( L_10 V_53 L_11 ,
V_31 , V_33 ,
V_30 , V_32 ,
V_5 -> V_21 [ 0 ] ) ;
V_35 =
F_30 ( L_10 V_53 L_11 ,
V_30 , V_32 ,
V_31 , V_33 ,
V_5 -> V_21 [ 1 ] ) ;
}
F_31 ( L_12 , V_5 , V_36 ,
V_34 , V_35 ) ;
F_14 ( V_36 ) ;
F_14 ( V_34 ) ;
F_14 ( V_35 ) ;
}
T_17
F_32 ( T_4 * V_5 ,
T_18 (* F_33)( char * , T_19 , T_18 , void * ) ,
void * V_54 )
{
T_16 V_55 = 0 , V_56 = 0 ;
T_16 V_57 = 0 ;
T_16 V_58 = 0 ;
T_16 * V_59 ;
T_18 V_60 ;
T_20 * V_61 ;
T_17 V_62 ;
for ( V_61 = V_5 -> V_23 ; V_61 ; V_61 = F_34 ( V_61 ) ) {
T_5 * V_6 = ( T_5 * ) V_61 -> V_22 ;
V_60 = FALSE ;
if ( ! V_6 -> V_20 ) {
V_59 = & V_55 ;
if ( V_5 -> V_63 == V_64 ) {
V_60 = TRUE ;
}
} else {
V_59 = & V_56 ;
if ( V_5 -> V_63 == V_65 ) {
V_60 = TRUE ;
}
}
if ( ! V_60 ) {
T_19 V_66 = V_6 -> V_22 . V_14 ;
T_13 * V_67 = ( T_13 * ) F_35 ( V_6 -> V_22 . V_22 , ( V_68 ) V_66 ) ;
V_62 = F_36 ( V_5 , F_33 , V_67 , V_66 ,
V_6 -> V_20 , V_54 , V_59 ,
& V_57 , & V_58 ) ;
F_14 ( V_67 ) ;
if( V_62 == V_69 )
return V_62 ;
}
}
return V_70 ;
}
