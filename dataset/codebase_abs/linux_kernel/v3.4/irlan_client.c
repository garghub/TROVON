static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 ( 2 , L_1 , V_4 ) ;
F_3 (self != NULL, return;) ;
F_3 (self->magic == IRLAN_MAGIC, return;) ;
if ( ( V_3 -> V_5 . V_6 == V_7 ) &&
( V_3 -> V_8 . V_9 == V_10 ) &&
( V_3 -> V_5 . V_9 != V_10 ) ) {
F_4 ( V_3 , V_3 -> V_11 , V_3 -> V_12 ) ;
}
}
static void F_5 ( struct V_2 * V_3 , int V_13 )
{
F_2 ( 4 , L_1 , V_4 ) ;
F_6 ( & V_3 -> V_8 . V_14 , V_13 , ( void * ) V_3 ,
F_1 ) ;
}
void F_4 ( struct V_2 * V_3 , T_1 V_11 , T_1 V_12 )
{
F_2 ( 1 , L_1 , V_4 ) ;
F_3 (self != NULL, return;) ;
F_3 (self->magic == IRLAN_MAGIC, return;) ;
if ( ( V_3 -> V_8 . V_9 != V_10 ) ||
( V_3 -> V_5 . V_6 == V_15 ) )
{
F_2 ( 0 , L_2 , V_4 ) ;
return;
}
V_3 -> V_11 = V_11 ;
V_3 -> V_12 = V_12 ;
if ( V_3 -> V_16 == V_17 ) {
F_2 ( 0 , L_3 , V_4 ) ;
return;
}
F_7 ( V_3 ) ;
F_8 ( V_3 ) ;
F_9 ( V_3 , V_18 , NULL ) ;
F_5 ( V_3 , 2 * V_19 ) ;
}
void F_10 ( T_2 * V_20 ,
T_3 V_21 ,
void * V_22 )
{
struct V_2 * V_3 ;
T_1 V_11 , V_12 ;
F_2 ( 1 , L_1 , V_4 ) ;
F_3 (discovery != NULL, return;) ;
if( V_21 == V_23 )
return;
V_11 = V_20 -> V_11 ;
V_12 = V_20 -> V_12 ;
F_11 () ;
V_3 = F_12 () ;
if ( V_3 ) {
F_3 (self->magic == IRLAN_MAGIC, goto out;) ;
F_2 ( 1 , L_4 , V_4 ,
V_12 ) ;
F_4 ( V_3 , V_11 , V_12 ) ;
}
F_13 (out:)
F_14 () ;
}
static int F_15 ( void * V_24 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_2 * V_3 ;
F_2 ( 2 , L_1 , V_4 ) ;
V_3 = V_24 ;
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRLAN_MAGIC, return -1;) ;
F_3 (skb != NULL, return -1;) ;
F_9 ( V_3 , V_28 , V_27 ) ;
F_2 ( 2 , L_5 , V_4 ) ;
V_3 -> V_8 . V_29 = FALSE ;
F_16 ( V_3 ) ;
return 0 ;
}
static void F_17 ( void * V_24 , void * V_25 ,
T_4 V_30 ,
struct V_26 * V_31 )
{
struct V_2 * V_3 ;
struct V_32 * V_33 ;
struct V_26 * V_27 ;
F_2 ( 4 , L_6 , V_4 , V_30 ) ;
V_3 = V_24 ;
V_33 = V_25 ;
F_3 (self != NULL, return;) ;
F_3 (self->magic == IRLAN_MAGIC, return;) ;
F_3 (tsap != NULL, return;) ;
F_3 (tsap->magic == TTP_TSAP_MAGIC, return;) ;
F_3 (tsap == self->client.tsap_ctrl, return;) ;
while ( ( V_27 = F_18 ( & V_3 -> V_8 . V_34 ) ) != NULL ) {
F_19 ( V_27 ) ;
}
V_3 -> V_8 . V_29 = FALSE ;
F_9 ( V_3 , V_35 , NULL ) ;
}
static void F_7 ( struct V_2 * V_3 )
{
struct V_32 * V_33 ;
T_5 V_36 ;
F_2 ( 4 , L_1 , V_4 ) ;
F_3 (self != NULL, return;) ;
F_3 (self->magic == IRLAN_MAGIC, return;) ;
if ( V_3 -> V_8 . V_37 )
return;
F_20 ( & V_36 ) ;
V_36 . V_38 = F_15 ;
V_36 . V_39 = V_40 ;
V_36 . V_41 = F_17 ;
V_36 . V_24 = V_3 ;
F_21 ( V_36 . V_42 , L_7 , sizeof( V_36 . V_42 ) ) ;
V_33 = F_22 ( V_43 , V_44 , & V_36 ) ;
if ( ! V_33 ) {
F_2 ( 2 , L_8 , V_4 ) ;
return;
}
V_3 -> V_8 . V_37 = V_33 ;
}
static void V_40 ( void * V_24 , void * V_25 ,
struct V_45 * V_46 ,
T_1 V_47 ,
T_6 V_48 ,
struct V_26 * V_27 )
{
struct V_2 * V_3 ;
F_2 ( 4 , L_1 , V_4 ) ;
V_3 = V_24 ;
F_3 (self != NULL, return;) ;
F_3 (self->magic == IRLAN_MAGIC, return;) ;
V_3 -> V_8 . V_47 = V_47 ;
V_3 -> V_8 . V_48 = V_48 ;
F_9 ( V_3 , V_49 , NULL ) ;
}
static void F_23 ( T_6 V_50 )
{
switch( V_50 ) {
case 0 :
F_24 ( V_51 L_9 ) ;
break;
case 1 :
F_25 ( L_10 ) ;
break;
case 2 :
F_25 ( L_11 ) ;
break;
case 3 :
F_25 ( L_12 ) ;
break;
case 4 :
F_25 ( L_13 ) ;
break;
case 5 :
F_25 ( L_14 ) ;
break;
case 6 :
F_25 ( L_15 ) ;
break;
case 7 :
F_25 ( L_16 ) ;
break;
case 8 :
F_25 ( L_17 ) ;
break;
case 9 :
F_25 ( L_18 ) ;
break;
case 255 :
F_25 ( L_19 ) ;
break;
}
}
void F_26 ( struct V_2 * V_3 , struct V_26 * V_27 )
{
T_6 * V_52 ;
T_6 * V_53 ;
int V_54 ;
int V_55 ;
T_7 V_56 ;
int V_57 ;
char * V_42 ;
char * V_58 ;
F_3 (skb != NULL, return;) ;
F_2 ( 4 , L_20 , V_4 , ( int ) V_27 -> V_59 ) ;
F_3 (self != NULL, return;) ;
F_3 (self->magic == IRLAN_MAGIC, return;) ;
if ( ! V_27 ) {
F_27 ( L_21 , V_4 ) ;
return;
}
V_52 = V_27 -> V_1 ;
if ( V_52 [ 0 ] ) {
F_23 ( V_52 [ 0 ] ) ;
return;
}
V_42 = F_28 ( 255 , V_60 ) ;
if ( ! V_42 )
return;
V_58 = F_28 ( 1016 , V_60 ) ;
if ( ! V_58 ) {
F_29 ( V_42 ) ;
return;
}
V_54 = V_52 [ 1 ] ;
F_2 ( 4 , L_22 , V_4 , V_54 ) ;
V_53 = V_52 + 2 ;
for ( V_57 = 0 ; V_57 < V_54 ; V_57 ++ ) {
V_55 = F_30 ( V_53 , V_42 , V_58 , & V_56 ) ;
if ( V_55 < 0 ) {
F_2 ( 2 , L_23 , V_4 ) ;
break;
}
V_53 += V_55 ;
F_31 ( V_3 , V_42 , V_58 , V_56 ) ;
}
F_29 ( V_42 ) ;
F_29 ( V_58 ) ;
}
static void F_31 ( struct V_2 * V_3 , char * V_61 ,
char * V_58 , int V_56 )
{
T_7 V_62 ;
T_6 * V_63 ;
int V_57 ;
F_2 ( 4 , L_24 , V_4 , V_61 ) ;
F_3 (self != NULL, return;) ;
F_3 (self->magic == IRLAN_MAGIC, return;) ;
if ( strcmp ( V_61 , L_25 ) == 0 ) {
if ( strcmp ( V_58 , L_26 ) == 0 )
V_3 -> V_64 = V_65 ;
else
V_3 -> V_64 = V_66 ;
return;
}
if ( strcmp ( V_61 , L_27 ) == 0 ) {
if ( strcmp ( V_58 , L_28 ) == 0 )
V_3 -> V_8 . V_67 |= V_68 ;
else if ( strcmp ( V_58 , L_29 ) == 0 )
V_3 -> V_8 . V_67 |= V_69 ;
else if ( strcmp ( V_58 , L_30 ) == 0 )
V_3 -> V_8 . V_67 |= V_70 ;
else if ( strcmp ( V_58 , L_31 ) == 0 )
V_3 -> V_8 . V_67 |= V_71 ;
else if ( strcmp ( V_58 , L_32 ) == 0 )
V_3 -> V_8 . V_67 |= V_72 ;
else if ( strcmp ( V_58 , L_33 ) == 0 )
V_3 -> V_8 . V_67 |= V_73 ;
else if ( strcmp ( V_58 , L_34 ) == 0 )
V_3 -> V_8 . V_67 |= V_74 ;
}
if ( strcmp ( V_61 , L_35 ) == 0 ) {
if ( strcmp ( V_58 , L_36 ) == 0 )
V_3 -> V_8 . V_6 = V_15 ;
else if ( strcmp ( V_58 , L_37 ) == 0 )
V_3 -> V_8 . V_6 = V_7 ;
else if ( strcmp ( V_58 , L_38 ) == 0 )
V_3 -> V_8 . V_6 = V_75 ;
else {
F_2 ( 2 , L_39 , V_4 ) ;
}
}
if ( strcmp ( V_61 , L_40 ) == 0 ) {
F_2 ( 4 , L_41 , ( T_6 ) V_58 [ 0 ] ,
( T_6 ) V_58 [ 1 ] ) ;
V_3 -> V_76 [ 0 ] = V_58 [ 0 ] ;
V_3 -> V_76 [ 1 ] = V_58 [ 1 ] ;
return;
}
if ( strcmp ( V_61 , L_42 ) == 0 ) {
V_3 -> V_77 = V_58 [ 0 ] ;
F_2 ( 4 , L_43 , V_3 -> V_77 ) ;
return;
}
if ( strcmp ( V_61 , L_44 ) == 0 ) {
memcpy ( & V_62 , V_58 , 2 ) ;
F_32 ( & V_62 ) ;
V_3 -> V_8 . V_78 = V_62 ;
F_2 ( 2 , L_45 , V_4 ,
V_3 -> V_8 . V_78 ) ;
}
if ( strcmp ( V_61 , L_46 ) == 0 ) {
memcpy ( & V_62 , V_58 , 2 ) ;
F_32 ( & V_62 ) ;
V_3 -> V_8 . V_79 = V_62 ;
F_2 ( 4 , L_47 , V_4 ,
V_3 -> V_8 . V_79 ) ;
}
if ( strcmp ( V_61 , L_48 ) == 0 ) {
F_2 ( 4 , L_49 ) ;
memcpy ( V_3 -> V_8 . V_80 , V_58 , V_56 ) ;
V_3 -> V_8 . V_81 = V_56 ;
F_2 ( 4 , L_50 ) ;
}
if ( strcmp ( V_61 , L_51 ) == 0 ) {
V_63 = V_58 ;
F_2 ( 4 , L_52 , V_63 ) ;
for ( V_57 = 0 ; V_57 < 6 ; V_57 ++ )
V_3 -> V_82 -> V_83 [ V_57 ] = V_63 [ V_57 ] ;
}
}
void F_33 ( int V_84 , T_7 V_85 ,
struct V_86 * V_58 , void * V_22 )
{
struct V_2 * V_3 ;
F_2 ( 4 , L_1 , V_4 ) ;
F_3 (priv != NULL, return;) ;
V_3 = V_22 ;
F_3 (self->magic == IRLAN_MAGIC, return;) ;
F_34 ( V_3 -> V_8 . V_87 ) ;
V_3 -> V_8 . V_87 = NULL ;
if ( V_84 != V_88 ) {
F_2 ( 2 , L_53 , V_4 ) ;
F_9 ( V_3 , V_89 ,
NULL ) ;
return;
}
switch ( V_58 -> type ) {
case V_90 :
V_3 -> V_91 = V_58 -> V_92 . integer ;
if ( V_58 -> V_92 . integer != - 1 ) {
F_9 ( V_3 , V_93 ,
NULL ) ;
return;
}
F_35 ( V_58 ) ;
break;
default:
F_2 ( 2 , L_54 , V_4 ) ;
break;
}
F_9 ( V_3 , V_89 , NULL ) ;
}
