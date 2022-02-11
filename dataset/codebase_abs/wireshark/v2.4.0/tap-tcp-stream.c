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
V_22 -> V_24 = V_2 -> V_24 ;
V_22 -> V_25 = ( V_26 ) V_2 -> V_27 . V_28 ;
V_22 -> V_29 = V_2 -> V_27 . V_30 / 1000 ;
V_22 -> V_31 = V_9 -> V_31 ;
V_22 -> V_32 = V_9 -> V_32 ;
V_22 -> V_33 = V_9 -> V_33 ;
V_22 -> V_34 = V_9 -> V_34 ;
V_22 -> V_20 = V_9 -> V_20 ;
V_22 -> V_17 = V_9 -> V_17 ;
V_22 -> V_35 = V_9 -> V_35 ;
F_2 ( & V_22 -> V_18 , & V_9 -> V_18 ) ;
F_2 ( & V_22 -> V_15 , & V_9 -> V_15 ) ;
V_22 -> V_36 = F_5 ( V_37 , V_9 -> V_36 ) ;
if ( V_22 -> V_36 > 0 ) {
memcpy ( & V_22 -> V_38 , & V_9 -> V_38 , sizeof( V_22 -> V_38 ) ) ;
memcpy ( & V_22 -> V_39 , & V_9 -> V_39 , sizeof( V_22 -> V_39 ) ) ;
}
if ( V_5 -> V_7 -> V_40 ) {
V_5 -> V_41 -> V_23 = V_22 ;
} else {
V_5 -> V_7 -> V_40 = V_22 ;
}
V_5 -> V_41 = V_22 ;
}
return FALSE ;
}
void
F_6 ( T_6 * V_42 , struct V_6 * V_7 , T_1 V_43 )
{
struct V_22 V_44 ;
T_7 * V_45 ;
T_5 V_5 ;
F_7 ( NULL , V_46 , L_1 ) ;
if ( ! V_42 || ! V_7 ) return;
if ( ! V_43 ) {
struct V_8 * V_47 = F_8 ( V_42 , & V_44 ) ;
if ( ! V_47 ) return;
if ( V_7 -> type == V_48 )
V_5 . V_21 = V_49 ;
else
V_5 . V_21 = V_50 ;
F_2 ( & V_7 -> V_12 , & V_44 . V_18 ) ;
V_7 -> V_16 = V_44 . V_20 ;
F_2 ( & V_7 -> V_14 , & V_44 . V_15 ) ;
V_7 -> V_19 = V_44 . V_17 ;
V_7 -> V_10 = V_47 -> V_11 ;
}
else {
V_5 . V_21 = V_50 ;
}
V_5 . V_44 = & V_44 ;
V_5 . V_7 = V_7 ;
V_5 . V_41 = NULL ;
V_45 = F_9 ( L_2 , & V_5 , L_2 , 0 , NULL , F_1 , NULL ) ;
if ( V_45 ) {
fprintf ( V_51 , L_3 ,
V_45 -> V_52 ) ;
F_10 ( V_45 , TRUE ) ;
exit ( 1 ) ;
}
F_11 ( V_42 ) ;
F_12 ( & V_5 ) ;
}
void
F_13 ( struct V_6 * V_7 )
{
struct V_22 * V_22 ;
while ( V_7 -> V_40 ) {
V_22 = V_7 -> V_40 -> V_23 ;
F_14 ( V_7 -> V_40 ) ;
V_7 -> V_40 = V_22 ;
}
V_7 -> V_40 = NULL ;
}
int
F_3 ( T_8 * V_53 , T_8 * V_54 , T_9 V_55 , T_9 V_56 , const T_8 * V_57 , const T_8 * V_58 , T_9 V_59 , T_9 V_60 , int V_61 )
{
int V_62 , V_63 ;
V_62 = ( ( ! ( F_15 ( V_53 , V_57 ) ) ) &&
( ! ( F_15 ( V_54 , V_58 ) ) ) &&
( V_55 == V_59 ) &&
( V_56 == V_60 ) ) ;
if ( V_61 == V_49 ) {
return V_62 ;
} else {
V_63 = ( ( ! ( F_15 ( V_53 , V_58 ) ) ) &&
( ! ( F_15 ( V_54 , V_57 ) ) ) &&
( V_55 == V_60 ) &&
( V_56 == V_59 ) ) ;
return V_62 || V_63 ;
}
}
int
F_16 ( struct V_6 * V_7 )
{
int V_64 ;
struct V_22 * V_65 ;
for ( V_65 = V_7 -> V_40 , V_64 = 0 ; V_65 ; V_65 = V_65 -> V_23 ) {
if ( F_3 ( & V_7 -> V_12 , & V_7 -> V_14 ,
V_7 -> V_16 , V_7 -> V_19 ,
& V_65 -> V_18 , & V_65 -> V_15 ,
V_65 -> V_20 , V_65 -> V_17 ,
V_49 ) ) {
V_64 ++ ;
}
}
return V_64 ;
}
int
F_17 ( struct V_6 * V_7 , int * V_36 )
{
int V_64 ;
struct V_22 * V_65 ;
for ( V_65 = V_7 -> V_40 , V_64 = 0 ; V_65 ; V_65 = V_65 -> V_23 ) {
if ( ! F_3 ( & V_7 -> V_12 , & V_7 -> V_14 ,
V_7 -> V_16 , V_7 -> V_19 ,
& V_65 -> V_18 , & V_65 -> V_15 ,
V_65 -> V_20 , V_65 -> V_17 ,
V_49 ) ) {
V_64 ++ ;
* V_36 += V_65 -> V_36 ;
}
}
return V_64 ;
}
static T_1
F_18 ( void * V_1 , T_2 * V_2 V_3 , T_3 * T_4 V_3 , const void * V_4 )
{
int V_66 ;
T_1 V_67 = TRUE ;
T_10 * V_68 = ( T_10 * ) V_1 ;
const struct V_8 * V_47 = ( const struct V_8 * ) V_4 ;
for ( V_66 = 0 ; V_66 < V_68 -> V_69 ; V_66 ++ ) {
struct V_8 * V_70 = V_68 -> V_71 [ V_66 ] ;
if ( F_3 ( & V_70 -> V_18 , & V_70 -> V_15 ,
V_70 -> V_20 , V_70 -> V_17 ,
& V_47 -> V_18 , & V_47 -> V_15 ,
V_47 -> V_20 , V_70 -> V_17 ,
V_49 ) )
{
V_67 = FALSE ;
break;
}
}
if ( V_67 && ( V_68 -> V_69 < V_72 ) ) {
V_68 -> V_71 [ V_68 -> V_69 ] = (struct V_8 * ) F_4 ( sizeof( struct V_8 ) ) ;
* ( V_68 -> V_71 [ V_68 -> V_69 ] ) = * V_47 ;
F_2 ( & V_68 -> V_71 [ V_68 -> V_69 ] -> V_18 , & V_47 -> V_18 ) ;
F_2 ( & V_68 -> V_71 [ V_68 -> V_69 ] -> V_15 , & V_47 -> V_15 ) ;
V_68 -> V_69 ++ ;
}
return FALSE ;
}
struct V_8 *
F_8 ( T_6 * V_42 , struct V_22 * V_73 )
{
T_11 * V_74 ;
T_3 T_4 ;
T_12 * V_75 ;
T_13 * V_76 ;
T_7 * V_45 ;
T_14 V_27 ;
T_10 V_68 = { 0 , { NULL , NULL , NULL , NULL , NULL , NULL , NULL , NULL } } ;
if ( ! V_42 || ! V_73 )
return NULL ;
V_74 = V_42 -> V_77 ;
if ( ! F_19 ( L_2 , & V_75 , & V_76 ) ) {
F_20 ( V_78 , V_79 , L_4 , V_76 ) ;
F_14 ( V_76 ) ;
return NULL ;
}
if ( ! F_21 ( V_42 , V_74 ) )
return NULL ;
V_45 = F_9 ( L_2 , & V_68 , NULL , 0 , NULL , F_18 , NULL ) ;
if ( V_45 ) {
fprintf ( V_51 , L_3 ,
V_45 -> V_52 ) ;
F_10 ( V_45 , TRUE ) ;
exit ( 1 ) ;
}
F_22 ( & T_4 , V_42 -> V_80 , TRUE , FALSE ) ;
F_23 ( & T_4 , V_75 ) ;
F_24 ( & T_4 , V_42 -> V_81 , & V_42 -> V_82 , F_25 ( V_74 , & V_42 -> V_83 ) , V_74 , NULL ) ;
V_27 = T_4 . V_84 . V_27 ;
F_26 ( & T_4 ) ;
F_12 ( & V_68 ) ;
if ( V_68 . V_69 == 0 ) {
F_20 ( V_78 , V_79 ,
L_5 ) ;
return NULL ;
}
if ( V_68 . V_69 > 1 ) {
F_20 ( V_78 , V_79 ,
L_6
L_7 ) ;
return NULL ;
}
V_73 -> V_24 = V_74 -> V_24 ;
V_73 -> V_25 = ( V_26 ) V_27 . V_28 ;
V_73 -> V_29 = V_27 . V_30 / 1000 ;
V_73 -> V_31 = V_68 . V_71 [ 0 ] -> V_31 ;
V_73 -> V_32 = V_68 . V_71 [ 0 ] -> V_32 ;
V_73 -> V_33 = V_68 . V_71 [ 0 ] -> V_33 ;
V_73 -> V_34 = V_68 . V_71 [ 0 ] -> V_34 ;
V_73 -> V_20 = V_68 . V_71 [ 0 ] -> V_20 ;
V_73 -> V_17 = V_68 . V_71 [ 0 ] -> V_17 ;
V_73 -> V_35 = V_68 . V_71 [ 0 ] -> V_35 ;
F_2 ( & V_73 -> V_18 , & V_68 . V_71 [ 0 ] -> V_18 ) ;
F_2 ( & V_73 -> V_15 , & V_68 . V_71 [ 0 ] -> V_15 ) ;
return V_68 . V_71 [ 0 ] ;
}
int F_27 ( struct V_85 * V_86 , unsigned int V_87 )
{
struct V_85 * V_88 ;
for ( V_88 = V_86 ; V_88 ; V_88 = V_88 -> V_23 ) {
if ( F_28 ( V_87 , V_88 -> V_87 ) &&
F_29 ( V_87 , V_88 -> V_89 ) )
return TRUE ;
}
return FALSE ;
}
struct V_85 *
F_30 ( double V_90 , unsigned int V_87 , unsigned int V_91 )
{
struct V_85 * V_88 ;
V_88 = (struct V_85 * ) F_4 ( sizeof( struct V_85 ) ) ;
V_88 -> V_23 = NULL ;
V_88 -> time = V_90 ;
V_88 -> V_87 = V_87 ;
V_88 -> V_89 = V_87 + V_91 ;
return V_88 ;
}
void F_31 ( struct V_85 * * V_92 , struct V_85 * V_93 )
{
struct V_85 * V_88 , * V_86 = * V_92 ;
for ( V_88 = V_86 ; V_88 ; V_88 = V_88 -> V_23 ) {
if ( ! V_88 -> V_23 )
break;
}
if ( V_88 )
V_88 -> V_23 = V_93 ;
else
* V_92 = V_93 ;
}
void F_32 ( struct V_85 * * V_92 , struct V_85 * V_94 )
{
struct V_85 * V_88 , * V_86 = * V_92 ;
if ( ! V_94 || ! V_86 )
return;
if ( V_94 == V_86 ) {
* V_92 = V_86 -> V_23 ;
F_14 ( V_86 ) ;
} else {
for ( V_88 = V_86 ; V_88 ; V_88 = V_88 -> V_23 ) {
if ( V_88 -> V_23 == V_94 ) {
V_88 -> V_23 = V_88 -> V_23 -> V_23 ;
F_14 ( V_94 ) ;
break;
}
}
}
}
void F_33 ( struct V_85 * * V_92 ) {
while ( * V_92 ) {
struct V_85 * V_95 = * V_92 ;
* V_92 = V_95 -> V_23 ;
F_14 ( V_95 ) ;
}
}
