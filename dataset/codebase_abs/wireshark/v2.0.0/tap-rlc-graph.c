int F_1 ( T_1 V_1 , T_1 V_2 , T_1 V_3 , T_2 V_4 , T_2 V_5 ,
T_1 V_6 , T_1 V_7 , T_1 V_8 , T_2 V_9 , T_2 V_10 ,
T_3 V_11 )
{
if ( ! V_11 ) {
return ( V_5 == V_10 ) &&
( V_1 == V_6 ) &&
( V_2 == V_7 ) &&
( V_3 == V_8 ) &&
( V_4 == V_9 ) ;
}
else {
if ( V_11 && ( V_4 == V_12 ) && ( V_9 == V_12 ) ) {
return ( ( V_5 != V_10 ) &&
( V_1 == V_6 ) &&
( V_2 == V_7 ) &&
( V_3 == V_8 ) ) ;
}
else {
return FALSE ;
}
}
}
static int
F_2 ( void * V_13 , T_4 * T_5 V_14 , T_6 * T_7 V_14 , const void * V_15 )
{
int V_16 ;
T_3 V_17 = TRUE ;
T_8 * V_18 = ( T_8 * ) V_13 ;
const T_9 * V_19 = ( const T_9 * ) V_15 ;
for ( V_16 = 0 ; V_16 < V_18 -> V_20 ; V_16 ++ ) {
T_9 * V_21 = V_18 -> V_22 [ V_16 ] ;
if ( F_1 ( V_21 -> V_23 , V_21 -> V_24 , V_21 -> V_25 , V_21 -> V_26 , V_21 -> V_27 ,
V_19 -> V_23 , V_19 -> V_24 , V_19 -> V_25 , V_19 -> V_26 , V_19 -> V_27 ,
V_19 -> V_28 ) ) {
V_17 = FALSE ;
break;
}
}
if ( V_17 && ( V_18 -> V_20 < V_29 ) ) {
V_18 -> V_22 [ V_18 -> V_20 ] = F_3 ( T_9 , 1 ) ;
* ( V_18 -> V_22 [ V_18 -> V_20 ] ) = * V_19 ;
if ( V_18 -> V_22 [ V_18 -> V_20 ] -> V_28 ) {
V_18 -> V_22 [ V_18 -> V_20 ] -> V_27 = ! V_18 -> V_22 [ V_18 -> V_20 ] -> V_27 ;
}
V_18 -> V_20 ++ ;
}
return 0 ;
}
T_9 * F_4 ( T_10 * V_30 ,
struct V_31 * V_32 ,
T_11 * * V_33 , T_3 * V_34 )
{
T_12 * V_35 ;
T_6 T_7 ;
T_13 * V_36 ;
T_14 * V_37 ;
T_15 V_38 ;
T_8 V_18 = { 0 , { NULL , NULL , NULL , NULL , NULL , NULL , NULL , NULL } } ;
if ( V_30 -> V_39 == V_40 ) {
return NULL ;
}
V_35 = V_30 -> V_41 ;
if ( ! F_5 ( L_1 , & V_36 , V_33 ) ) {
* V_34 = TRUE ;
return NULL ;
}
if ( ! F_6 ( V_30 , V_35 ) ) {
return NULL ;
}
V_37 = F_7 ( L_1 , & V_18 , NULL , 0 , NULL , F_2 , NULL ) ;
if ( V_37 ) {
fprintf ( V_42 , L_2 ,
V_37 -> V_43 ) ;
F_8 ( V_37 , TRUE ) ;
exit ( 1 ) ;
}
F_9 ( & T_7 , V_30 -> V_44 , TRUE , FALSE ) ;
F_10 ( & T_7 , V_36 ) ;
F_11 ( & T_7 , V_30 -> V_45 , & V_30 -> V_46 , F_12 ( V_35 , & V_30 -> V_47 ) , V_35 , NULL ) ;
V_38 = T_7 . V_48 . V_38 ;
F_13 ( & T_7 ) ;
F_14 ( & V_18 ) ;
if ( V_18 . V_20 == 0 ) {
* V_33 = ( char * ) L_3 ;
* V_34 = FALSE ;
return NULL ;
}
if ( V_18 . V_20 > 1 ) {
* V_33 = ( char * ) L_4 ;
* V_34 = FALSE ;
return NULL ;
}
V_32 -> V_49 = V_35 -> V_49 ;
V_32 -> V_50 = ( V_51 ) V_38 . V_52 ;
V_32 -> V_53 = V_38 . V_54 / 1000 ;
V_32 -> V_55 = ( V_51 ) V_35 -> V_56 . V_52 ;
V_32 -> V_57 = V_35 -> V_56 . V_54 / 1000 ;
V_32 -> V_23 = V_18 . V_22 [ 0 ] -> V_23 ;
V_32 -> V_24 = V_18 . V_22 [ 0 ] -> V_24 ;
V_32 -> V_25 = V_18 . V_22 [ 0 ] -> V_25 ;
V_32 -> V_26 = V_18 . V_22 [ 0 ] -> V_26 ;
V_32 -> V_28 = V_18 . V_22 [ 0 ] -> V_28 ;
V_32 -> V_27 = ! V_32 -> V_28 ? V_18 . V_22 [ 0 ] -> V_27 : ! V_18 . V_22 [ 0 ] -> V_27 ;
return V_18 . V_22 [ 0 ] ;
}
int F_15 ( void * V_13 , T_4 * T_5 , T_6 * T_7 V_14 , const void * V_15 )
{
struct V_58 * V_59 = (struct V_58 * ) V_13 ;
const T_9 * V_60 = ( const T_9 * ) V_15 ;
if ( F_1 ( V_59 -> V_23 , V_59 -> V_24 , V_59 -> V_25 , V_59 -> V_26 , V_59 -> V_27 ,
V_60 -> V_23 , V_60 -> V_24 , V_60 -> V_25 , V_60 -> V_26 , V_60 -> V_27 ,
V_60 -> V_28 ) ) {
struct V_31 * V_61 = (struct V_31 * ) F_16 ( sizeof( struct V_31 ) ) ;
V_61 -> V_62 = NULL ;
V_61 -> V_49 = T_5 -> V_63 -> V_49 ;
V_61 -> V_50 = ( V_51 ) T_5 -> V_38 . V_52 ;
V_61 -> V_53 = T_5 -> V_38 . V_54 / 1000 ;
V_61 -> V_55 = ( V_51 ) T_5 -> V_63 -> V_56 . V_52 ;
V_61 -> V_57 = T_5 -> V_63 -> V_56 . V_54 / 1000 ;
V_61 -> V_23 = V_60 -> V_23 ;
V_61 -> V_24 = V_60 -> V_24 ;
V_61 -> V_25 = V_60 -> V_25 ;
V_61 -> V_27 = V_60 -> V_27 ;
V_61 -> V_26 = V_60 -> V_26 ;
V_61 -> V_28 = V_60 -> V_28 ;
if ( ! V_60 -> V_28 ) {
V_61 -> V_64 = V_60 -> V_65 ;
V_61 -> V_66 = V_60 -> V_66 ;
}
else {
T_16 V_16 ;
V_61 -> V_67 = V_60 -> V_67 ;
V_61 -> V_68 = V_60 -> V_68 ;
for ( V_16 = 0 ; V_16 < V_60 -> V_68 ; V_16 ++ ) {
V_61 -> V_69 [ V_16 ] = V_60 -> V_69 [ V_16 ] ;
}
}
if ( V_59 -> V_70 ) {
V_59 -> V_71 -> V_62 = V_61 ;
} else {
V_59 -> V_70 = V_61 ;
}
V_59 -> V_71 = V_61 ;
}
return 0 ;
}
T_3 F_17 ( T_10 * V_30 , struct V_58 * V_72 , T_3 V_73 ,
char * * V_74 , T_3 * V_75 )
{
struct V_31 V_76 ;
T_14 * V_37 ;
F_18 ( NULL , V_77 , L_5 ) ;
if ( ! V_30 || ! V_72 ) {
return FALSE ;
}
if ( ! V_73 ) {
struct T_9 * V_19 = F_4 ( V_30 , & V_76 , V_74 , V_75 ) ;
if ( ! V_19 ) {
return FALSE ;
}
V_72 -> V_78 = TRUE ;
V_72 -> V_23 = V_19 -> V_23 ;
V_72 -> V_24 = V_19 -> V_24 ;
V_72 -> V_25 = V_19 -> V_25 ;
V_72 -> V_26 = V_19 -> V_26 ;
V_72 -> V_27 = V_19 -> V_27 ;
}
V_72 -> V_71 = NULL ;
V_37 = F_7 ( L_1 , V_72 , L_1 , 0 , NULL , F_15 , NULL ) ;
if ( V_37 ) {
fprintf ( V_42 , L_6 ,
V_37 -> V_43 ) ;
F_8 ( V_37 , TRUE ) ;
exit ( 1 ) ;
}
F_19 ( V_30 ) ;
F_14 ( V_72 ) ;
return TRUE ;
}
void F_20 ( struct V_58 * V_72 )
{
struct V_31 * V_61 ;
while ( V_72 -> V_70 ) {
V_61 = V_72 -> V_70 -> V_62 ;
F_21 ( V_72 -> V_70 ) ;
V_72 -> V_70 = V_61 ;
}
V_72 -> V_70 = NULL ;
}
