static void
F_1 ( T_1 V_1 , T_1 T_2 V_2 )
{
F_2 ( ( V_3 * ) V_1 ) ;
}
void
F_3 ( void )
{
F_4 ( V_4 , F_1 , NULL ) ;
}
void
F_5 ( T_3 * T_4 V_2 , T_1 V_1 V_2 )
{
T_3 * V_5 ;
T_3 * V_6 ;
int V_7 ;
T_5 * V_8 ;
const T_5 * V_9 ;
int V_10 ;
const char * V_11 , * V_12 ;
char * V_13 , * V_14 ;
T_5 * V_15 = NULL ;
T_5 * V_16 = NULL ;
T_5 * V_17 = NULL ;
T_6 V_18 ;
V_3 * V_19 ;
T_7 V_20 ;
T_8 V_21 ;
T_5 * V_22 ;
if ( V_23 . V_24 -> V_25 . V_26 != V_27 ) {
F_6 ( V_28 , V_29 ,
L_1
L_2 ) ;
return;
}
V_19 = F_7 ( V_3 , 1 ) ;
V_19 -> V_30 = V_31 ;
F_8 () ;
V_8 = F_9 ( & V_23 . V_24 -> V_25 ) ;
if ( ! V_8 ) {
F_6 ( V_28 , V_29 ,
L_3
L_4 ) ;
F_10 ( V_19 ) ;
return;
}
V_7 = F_11 ( & V_22 , L_5 ) ;
V_19 -> V_22 = F_12 ( V_22 ) ;
if ( V_7 == - 1 ) {
F_6 ( V_28 , V_29 ,
L_6 ,
V_19 -> V_22 , F_13 ( V_32 ) ) ;
F_10 ( V_19 -> V_22 ) ;
F_10 ( V_19 ) ;
F_10 ( V_8 ) ;
return;
}
V_33 = fdopen ( V_7 , L_7 ) ;
if ( V_33 == NULL ) {
F_6 ( V_28 , V_29 ,
L_6 ,
V_19 -> V_22 , F_13 ( V_32 ) ) ;
F_14 ( V_7 ) ;
F_15 ( V_19 -> V_22 ) ;
F_10 ( V_19 -> V_22 ) ;
F_10 ( V_19 ) ;
F_10 ( V_8 ) ;
return;
}
V_5 = F_16 ( F_17 ( V_34 ) , V_35 ) ;
V_6 = F_18 ( F_19 ( V_5 ) ) ;
V_19 -> V_6 = V_6 ;
V_9 =
( const T_5 * ) F_20 ( F_21 ( V_6 ) ) ;
V_10 = ( int ) ( strlen ( V_8 ) + strlen ( V_9 ) + 16 ) ;
V_19 -> V_36 = ( T_5 * ) F_22 ( V_10 ) ;
if( strlen ( V_9 ) ) {
F_23 ( V_19 -> V_36 , V_10 ,
L_8 , V_9 , V_8 ) ;
} else {
F_23 ( V_19 -> V_36 , V_10 ,
L_9 , V_8 ) ;
}
F_24 ( F_21 ( V_6 ) , V_8 ) ;
F_25 ( & V_23 , V_8 , TRUE ) ;
F_10 ( V_8 ) ;
if ( V_37 ) {
F_6 ( V_28 , V_29 ,
L_10 ) ;
F_14 ( V_7 ) ;
F_15 ( V_19 -> V_22 ) ;
F_10 ( V_19 -> V_22 ) ;
F_10 ( V_19 -> V_36 ) ;
F_10 ( V_19 ) ;
return;
}
rewind ( V_33 ) ;
V_21 = fread ( & V_20 , 1 , sizeof( V_20 ) , V_33 ) ;
if ( V_21 != sizeof( V_20 ) ) {
if ( ferror ( V_33 ) ) {
F_6 ( V_28 , V_29 ,
L_11 ,
V_19 -> V_22 , F_13 ( V_32 ) ) ;
} else {
F_6 ( V_28 , V_29 ,
L_12 ,
V_19 -> V_22 ,
( unsigned long ) sizeof( V_20 ) ,
( unsigned long ) V_21 ) ;
}
F_14 ( V_7 ) ;
F_15 ( V_19 -> V_22 ) ;
F_10 ( V_19 -> V_22 ) ;
F_10 ( V_19 -> V_36 ) ;
F_10 ( V_19 ) ;
return;
}
fclose ( V_33 ) ;
F_26 ( & V_18 ) ;
if ( V_18 . V_38 ) {
struct V_39 V_40 ;
memcpy ( & V_40 , V_18 . V_41 [ 0 ] , 16 ) ;
V_11 = F_27 ( & V_40 ) ;
memcpy ( & V_40 , V_18 . V_41 [ 1 ] , 16 ) ;
V_12 = F_27 ( & V_40 ) ;
} else {
T_9 V_40 ;
memcpy ( & V_40 , V_18 . V_41 [ 0 ] , 4 ) ;
V_11 = F_28 ( V_40 ) ;
memcpy ( & V_40 , V_18 . V_41 [ 1 ] , 4 ) ;
V_12 = F_28 ( V_40 ) ;
}
V_19 -> V_38 = V_18 . V_38 ;
V_13 = F_29 ( V_18 . V_42 [ 0 ] ) ;
V_14 = F_29 ( V_18 . V_42 [ 1 ] ) ;
if( V_20 . V_43 == V_18 . V_42 [ 0 ] ) {
V_15 =
F_30 ( L_13 V_44 L_14 ,
V_11 , V_13 ,
V_12 , V_14 ,
V_18 . V_45 [ 0 ] ) ;
} else {
V_15 =
F_30 ( L_13 V_44 L_14 ,
V_12 , V_14 ,
V_11 , V_13 ,
V_18 . V_45 [ 0 ] ) ;
}
if( V_20 . V_43 == V_18 . V_42 [ 1 ] ) {
V_16 =
F_30 ( L_13 V_44 L_14 ,
V_11 , V_13 ,
V_12 , V_14 ,
V_18 . V_45 [ 1 ] ) ;
} else {
V_16 =
F_30 ( L_13 V_44 L_14 ,
V_12 , V_14 ,
V_11 , V_13 ,
V_18 . V_45 [ 1 ] ) ;
}
V_17 = F_30 ( L_15 , V_18 . V_45 [ 0 ] + V_18 . V_45 [ 1 ] ) ;
F_31 ( L_16 , V_19 , V_17 ,
V_15 , V_16 ) ;
F_10 ( V_17 ) ;
F_10 ( V_15 ) ;
F_10 ( V_16 ) ;
V_33 = NULL ;
}
T_10
F_32 ( V_3 * V_19 ,
T_11 (* F_33)( char * , T_8 , T_11 , void * ) ,
void * V_46 )
{
T_7 V_20 ;
T_8 V_47 ;
T_8 V_48 ;
int V_49 ;
T_12 V_50 [ V_51 ] ;
T_13 V_52 = 0 ;
T_11 V_53 ;
T_9 V_54 = 0 , V_55 = 0 ;
T_9 V_56 = 0 ;
T_9 V_57 = 0 ;
T_9 * V_58 ;
T_11 V_59 ;
char V_60 [ V_61 + 1 ] ;
T_8 V_21 ;
T_10 V_62 ;
V_49 = ( V_19 -> V_38 ) ? 16 : 4 ;
V_33 = F_34 ( V_19 -> V_22 , L_17 ) ;
if ( V_33 == NULL ) {
F_6 ( V_28 , V_29 ,
L_18 , V_19 -> V_22 ,
F_13 ( V_32 ) ) ;
return V_63 ;
}
while ( ( V_21 = fread ( & V_20 , 1 , sizeof( V_20 ) , V_33 ) ) ) {
if ( V_21 != sizeof( V_20 ) ) {
F_6 ( V_28 , V_29 ,
L_12 ,
V_19 -> V_22 ,
( unsigned long ) sizeof( V_20 ) ,
( unsigned long ) V_21 ) ;
fclose ( V_33 ) ;
V_33 = NULL ;
return V_64 ;
}
if ( V_52 == 0 ) {
memcpy ( V_50 , V_20 . V_65 , V_49 ) ;
V_52 = V_20 . V_43 ;
}
V_59 = FALSE ;
if ( memcmp ( V_50 , V_20 . V_65 , V_49 ) == 0 &&
V_52 == V_20 . V_43 ) {
V_53 = FALSE ;
V_58 = & V_54 ;
if ( V_19 -> V_66 == V_67 ) {
V_59 = TRUE ;
}
}
else {
V_53 = TRUE ;
V_58 = & V_55 ;
if ( V_19 -> V_66 == V_68 ) {
V_59 = TRUE ;
}
}
V_48 = 0 ;
while ( V_48 < V_20 . V_69 ) {
V_47 = ( ( V_20 . V_69 - V_48 ) < V_61 ) ? ( V_20 . V_69 - V_48 ) : V_61 ;
V_21 = fread ( V_60 , 1 , V_47 , V_33 ) ;
if ( V_21 == 0 )
break;
V_48 += V_21 ;
if ( ! V_59 ) {
V_62 = F_35 ( V_19 , F_33 , V_60 ,
V_21 , V_53 , V_46 , V_58 ,
& V_56 ,
& V_57 ) ;
if( V_62 == V_70 ) {
fclose ( V_33 ) ;
V_33 = NULL ;
return V_62 ;
}
}
}
}
if ( ferror ( V_33 ) ) {
F_6 ( V_28 , V_29 ,
L_19 , V_19 -> V_22 ,
F_13 ( V_32 ) ) ;
fclose ( V_33 ) ;
V_33 = NULL ;
return V_64 ;
}
fclose ( V_33 ) ;
V_33 = NULL ;
return V_71 ;
}
