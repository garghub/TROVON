static T_1
F_1 ( void * V_1 , T_2 * V_2 , T_3 * T_4 V_3 , const void * V_4 )
{
T_5 * V_5 = ( T_5 * ) V_1 ;
struct V_6 * V_7 = V_5 -> V_7 ;
const struct V_8 * V_9 = ( const struct V_8 * ) V_4 ;
if ( V_7 -> V_10 == V_9 -> V_11
&& ( V_7 -> V_12 . type == V_13 || V_7 -> V_14 . type == V_13 ) ) {
F_2 ( & V_7 -> V_12 , & V_9 -> V_15 ) ;
V_7 -> V_16 = V_9 -> V_17 ;
F_2 ( & V_7 -> V_14 , & V_9 -> V_18 ) ;
V_7 -> V_19 = V_9 -> V_20 ;
}
if ( F_3 ( & V_7 -> V_12 , & V_7 -> V_14 ,
V_7 -> V_16 , V_7 -> V_19 ,
& V_9 -> V_18 , & V_9 -> V_15 ,
V_9 -> V_20 , V_9 -> V_17 ,
V_5 -> V_21 )
&& V_7 -> V_10 == V_9 -> V_11 )
{
struct V_22 * V_22 = (struct V_22 * ) F_4 ( sizeof( struct V_22 ) ) ;
V_22 -> V_23 = NULL ;
V_22 -> V_24 = V_2 -> V_25 -> V_24 ;
V_22 -> V_26 = ( V_27 ) V_2 -> V_28 . V_29 ;
V_22 -> V_30 = V_2 -> V_28 . V_31 / 1000 ;
V_22 -> V_32 = V_9 -> V_32 ;
V_22 -> V_33 = V_9 -> V_33 ;
V_22 -> V_34 = V_9 -> V_34 ;
V_22 -> V_35 = V_9 -> V_35 ;
V_22 -> V_20 = V_9 -> V_20 ;
V_22 -> V_17 = V_9 -> V_17 ;
V_22 -> V_36 = V_9 -> V_36 ;
F_2 ( & V_22 -> V_18 , & V_9 -> V_18 ) ;
F_2 ( & V_22 -> V_15 , & V_9 -> V_15 ) ;
V_22 -> V_37 = F_5 ( V_38 , V_9 -> V_37 ) ;
if ( V_22 -> V_37 > 0 ) {
memcpy ( & V_22 -> V_39 , & V_9 -> V_39 , sizeof( V_22 -> V_39 ) ) ;
memcpy ( & V_22 -> V_40 , & V_9 -> V_40 , sizeof( V_22 -> V_40 ) ) ;
}
if ( V_5 -> V_7 -> V_41 ) {
V_5 -> V_42 -> V_23 = V_22 ;
} else {
V_5 -> V_7 -> V_41 = V_22 ;
}
V_5 -> V_42 = V_22 ;
}
return FALSE ;
}
void
F_6 ( T_6 * V_43 , struct V_6 * V_7 , T_1 V_44 )
{
struct V_22 V_45 ;
T_7 * V_46 ;
T_5 V_5 ;
F_7 ( NULL , V_47 , L_1 ) ;
if ( ! V_43 || ! V_7 ) return;
if ( ! V_44 ) {
struct V_8 * V_48 = F_8 ( V_43 , & V_45 ) ;
if ( ! V_48 ) return;
if ( V_7 -> type == V_49 )
V_5 . V_21 = V_50 ;
else
V_5 . V_21 = V_51 ;
F_2 ( & V_7 -> V_12 , & V_45 . V_18 ) ;
V_7 -> V_16 = V_45 . V_20 ;
F_2 ( & V_7 -> V_14 , & V_45 . V_15 ) ;
V_7 -> V_19 = V_45 . V_17 ;
V_7 -> V_10 = V_48 -> V_11 ;
}
else {
V_5 . V_21 = V_51 ;
}
V_5 . V_45 = & V_45 ;
V_5 . V_7 = V_7 ;
V_5 . V_42 = NULL ;
V_46 = F_9 ( L_2 , & V_5 , L_2 , 0 , NULL , F_1 , NULL ) ;
if ( V_46 ) {
fprintf ( V_52 , L_3 ,
V_46 -> V_53 ) ;
F_10 ( V_46 , TRUE ) ;
exit ( 1 ) ;
}
F_11 ( V_43 ) ;
F_12 ( & V_5 ) ;
}
void
F_13 ( struct V_6 * V_7 )
{
struct V_22 * V_22 ;
while ( V_7 -> V_41 ) {
V_22 = V_7 -> V_41 -> V_23 ;
F_14 ( V_7 -> V_41 ) ;
V_7 -> V_41 = V_22 ;
}
V_7 -> V_41 = NULL ;
}
int
F_3 ( T_8 * V_54 , T_8 * V_55 , T_9 V_56 , T_9 V_57 , const T_8 * V_58 , const T_8 * V_59 , T_9 V_60 , T_9 V_61 , int V_62 )
{
int V_63 , V_64 ;
V_63 = ( ( ! ( F_15 ( V_54 , V_58 ) ) ) &&
( ! ( F_15 ( V_55 , V_59 ) ) ) &&
( V_56 == V_60 ) &&
( V_57 == V_61 ) ) ;
if ( V_62 == V_50 ) {
return V_63 ;
} else {
V_64 = ( ( ! ( F_15 ( V_54 , V_59 ) ) ) &&
( ! ( F_15 ( V_55 , V_58 ) ) ) &&
( V_56 == V_61 ) &&
( V_57 == V_60 ) ) ;
return V_63 || V_64 ;
}
}
int
F_16 ( struct V_6 * V_7 )
{
int V_65 ;
struct V_22 * V_66 ;
for ( V_66 = V_7 -> V_41 , V_65 = 0 ; V_66 ; V_66 = V_66 -> V_23 ) {
if ( F_3 ( & V_7 -> V_12 , & V_7 -> V_14 ,
V_7 -> V_16 , V_7 -> V_19 ,
& V_66 -> V_18 , & V_66 -> V_15 ,
V_66 -> V_20 , V_66 -> V_17 ,
V_50 ) ) {
V_65 ++ ;
}
}
return V_65 ;
}
int
F_17 ( struct V_6 * V_7 , int * V_37 )
{
int V_65 ;
struct V_22 * V_66 ;
for ( V_66 = V_7 -> V_41 , V_65 = 0 ; V_66 ; V_66 = V_66 -> V_23 ) {
if ( ! F_3 ( & V_7 -> V_12 , & V_7 -> V_14 ,
V_7 -> V_16 , V_7 -> V_19 ,
& V_66 -> V_18 , & V_66 -> V_15 ,
V_66 -> V_20 , V_66 -> V_17 ,
V_50 ) ) {
V_65 ++ ;
* V_37 += V_66 -> V_37 ;
}
}
return V_65 ;
}
static T_1
F_18 ( void * V_1 , T_2 * V_2 V_3 , T_3 * T_4 V_3 , const void * V_4 )
{
int V_67 ;
T_1 V_68 = TRUE ;
T_10 * V_69 = ( T_10 * ) V_1 ;
const struct V_8 * V_48 = ( const struct V_8 * ) V_4 ;
for ( V_67 = 0 ; V_67 < V_69 -> V_70 ; V_67 ++ ) {
struct V_8 * V_71 = V_69 -> V_72 [ V_67 ] ;
if ( F_3 ( & V_71 -> V_18 , & V_71 -> V_15 ,
V_71 -> V_20 , V_71 -> V_17 ,
& V_48 -> V_18 , & V_48 -> V_15 ,
V_48 -> V_20 , V_71 -> V_17 ,
V_50 ) )
{
V_68 = FALSE ;
break;
}
}
if ( V_68 && ( V_69 -> V_70 < V_73 ) ) {
V_69 -> V_72 [ V_69 -> V_70 ] = (struct V_8 * ) F_4 ( sizeof( struct V_8 ) ) ;
* ( V_69 -> V_72 [ V_69 -> V_70 ] ) = * V_48 ;
F_2 ( & V_69 -> V_72 [ V_69 -> V_70 ] -> V_18 , & V_48 -> V_18 ) ;
F_2 ( & V_69 -> V_72 [ V_69 -> V_70 ] -> V_15 , & V_48 -> V_15 ) ;
V_69 -> V_70 ++ ;
}
return FALSE ;
}
struct V_8 *
F_8 ( T_6 * V_43 , struct V_22 * V_74 )
{
T_11 * V_75 ;
T_3 T_4 ;
T_12 * V_76 ;
T_13 * V_77 ;
T_7 * V_46 ;
T_14 V_28 ;
T_10 V_69 = { 0 , { NULL , NULL , NULL , NULL , NULL , NULL , NULL , NULL } } ;
if ( ! V_43 || ! V_74 )
return NULL ;
V_75 = V_43 -> V_78 ;
if ( ! F_19 ( L_2 , & V_76 , & V_77 ) ) {
F_20 ( V_79 , V_80 , L_4 , V_77 ) ;
F_14 ( V_77 ) ;
return NULL ;
}
if ( ! F_21 ( V_43 , V_75 ) )
return NULL ;
V_46 = F_9 ( L_2 , & V_69 , NULL , 0 , NULL , F_18 , NULL ) ;
if ( V_46 ) {
fprintf ( V_52 , L_3 ,
V_46 -> V_53 ) ;
F_10 ( V_46 , TRUE ) ;
exit ( 1 ) ;
}
F_22 ( & T_4 , V_43 -> V_81 , TRUE , FALSE ) ;
F_23 ( & T_4 , V_76 ) ;
F_24 ( & T_4 , V_43 -> V_82 , & V_43 -> V_83 , F_25 ( V_75 , & V_43 -> V_84 ) , V_75 , NULL ) ;
V_28 = T_4 . V_85 . V_28 ;
F_26 ( & T_4 ) ;
F_12 ( & V_69 ) ;
if ( V_69 . V_70 == 0 ) {
F_20 ( V_79 , V_80 ,
L_5 ) ;
return NULL ;
}
if ( V_69 . V_70 > 1 ) {
F_20 ( V_79 , V_80 ,
L_6
L_7 ) ;
return NULL ;
}
V_74 -> V_24 = V_75 -> V_24 ;
V_74 -> V_26 = ( V_27 ) V_28 . V_29 ;
V_74 -> V_30 = V_28 . V_31 / 1000 ;
V_74 -> V_32 = V_69 . V_72 [ 0 ] -> V_32 ;
V_74 -> V_33 = V_69 . V_72 [ 0 ] -> V_33 ;
V_74 -> V_34 = V_69 . V_72 [ 0 ] -> V_34 ;
V_74 -> V_35 = V_69 . V_72 [ 0 ] -> V_35 ;
V_74 -> V_20 = V_69 . V_72 [ 0 ] -> V_20 ;
V_74 -> V_17 = V_69 . V_72 [ 0 ] -> V_17 ;
V_74 -> V_36 = V_69 . V_72 [ 0 ] -> V_36 ;
F_2 ( & V_74 -> V_18 , & V_69 . V_72 [ 0 ] -> V_18 ) ;
F_2 ( & V_74 -> V_15 , & V_69 . V_72 [ 0 ] -> V_15 ) ;
return V_69 . V_72 [ 0 ] ;
}
int F_27 ( struct V_86 * V_87 , unsigned int V_88 )
{
struct V_86 * V_89 ;
for ( V_89 = V_87 ; V_89 ; V_89 = V_89 -> V_23 ) {
if ( V_89 -> V_88 == V_88 )
return TRUE ;
}
return FALSE ;
}
struct V_86 * F_28 ( double V_90 , unsigned int V_88 )
{
struct V_86 * V_89 ;
V_89 = (struct V_86 * ) F_4 ( sizeof( struct V_86 ) ) ;
V_89 -> V_23 = NULL ;
V_89 -> time = V_90 ;
V_89 -> V_88 = V_88 ;
return V_89 ;
}
void F_29 ( struct V_86 * * V_91 , struct V_86 * V_92 )
{
struct V_86 * V_89 , * V_87 = * V_91 ;
for ( V_89 = V_87 ; V_89 ; V_89 = V_89 -> V_23 ) {
if ( ! V_89 -> V_23 )
break;
}
if ( V_89 )
V_89 -> V_23 = V_92 ;
else
* V_91 = V_92 ;
}
void F_30 ( struct V_86 * * V_91 , struct V_86 * V_93 )
{
struct V_86 * V_89 , * V_87 = * V_91 ;
if ( ! V_93 || ! V_87 )
return;
if ( V_93 == V_87 ) {
* V_91 = V_87 -> V_23 ;
F_14 ( V_87 ) ;
} else {
for ( V_89 = V_87 ; V_89 ; V_89 = V_89 -> V_23 ) {
if ( V_89 -> V_23 == V_93 ) {
V_89 -> V_23 = V_89 -> V_23 -> V_23 ;
F_14 ( V_93 ) ;
break;
}
}
}
}
