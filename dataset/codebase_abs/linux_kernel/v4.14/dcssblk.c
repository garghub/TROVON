static T_1 F_1 ( struct V_1 * V_2 ,
T_2 V_3 , void * V_4 , T_1 V_5 , struct V_6 * V_7 )
{
return F_2 ( V_4 , V_5 , V_7 ) ;
}
static void
F_3 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 , * V_14 ;
V_11 = F_4 ( V_9 , struct V_10 , V_9 ) ;
F_5 (entry, temp, &dev_info->seg_list, lh) {
F_6 ( & V_13 -> V_15 ) ;
F_7 ( V_13 ) ;
}
F_7 ( V_11 ) ;
F_8 ( V_16 ) ;
}
static int
F_9 ( struct V_10 * V_11 )
{
int V_17 , V_18 ;
struct V_10 * V_13 ;
if ( V_11 == NULL )
return - V_19 ;
for ( V_17 = 0 ; V_17 < ( 1 << V_20 ) ; V_17 ++ ) {
V_18 = 0 ;
F_10 (entry, &dcssblk_devices, lh)
if ( V_17 == V_13 -> V_21 -> V_22 )
V_18 ++ ;
if ( ! V_18 ) break;
}
if ( V_18 )
return - V_23 ;
V_11 -> V_21 -> V_22 = V_17 ;
return 0 ;
}
static struct V_10 *
F_11 ( char * V_24 )
{
struct V_10 * V_13 ;
F_10 (entry, &dcssblk_devices, lh) {
if ( ! strcmp ( V_24 , V_13 -> V_25 ) ) {
return V_13 ;
}
}
return NULL ;
}
static struct V_12 *
F_12 ( char * V_24 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
F_10 (dev_info, &dcssblk_devices, lh) {
F_10 (entry, &dev_info->seg_list, lh) {
if ( ! strcmp ( V_24 , V_13 -> V_25 ) )
return V_13 ;
}
}
return NULL ;
}
static unsigned long
F_13 ( struct V_10 * V_11 )
{
unsigned long V_26 ;
struct V_12 * V_13 ;
V_26 = 0 ;
F_10 (entry, &dev_info->seg_list, lh) {
if ( V_26 < V_13 -> V_27 )
V_26 = V_13 -> V_27 ;
}
return V_26 ;
}
static unsigned long
F_14 ( struct V_10 * V_11 )
{
int V_28 ;
unsigned long V_29 ;
struct V_12 * V_13 ;
V_28 = 0 ;
V_29 = 0 ;
F_10 (entry, &dev_info->seg_list, lh) {
if ( V_28 == 0 ) {
V_29 = V_13 -> V_30 ;
V_28 = 1 ;
} else {
if ( V_29 > V_13 -> V_30 )
V_29 = V_13 -> V_30 ;
}
}
return V_29 ;
}
static int
F_15 ( struct V_10 * V_11 )
{
int V_7 , V_31 , V_32 ;
struct V_12 * V_33 , * V_13 , V_14 ;
if ( V_11 -> V_34 <= 1 )
return 0 ;
V_33 = F_16 (
sizeof( struct V_12 ) * V_11 -> V_34 ,
V_35 ) ;
if ( V_33 == NULL )
return - V_36 ;
V_7 = 0 ;
F_10 (entry, &dev_info->seg_list, lh) {
memcpy ( & V_33 [ V_7 ] , V_13 , sizeof( struct V_12 ) ) ;
V_7 ++ ;
}
for ( V_7 = 0 ; V_7 < V_11 -> V_34 ; V_7 ++ )
for ( V_31 = 0 ; V_31 < V_11 -> V_34 ; V_31 ++ )
if ( V_33 [ V_31 ] . V_30 > V_33 [ V_7 ] . V_30 ) {
memcpy ( & V_14 , & V_33 [ V_7 ] ,
sizeof( struct V_12 ) ) ;
memcpy ( & V_33 [ V_7 ] , & V_33 [ V_31 ] ,
sizeof( struct V_12 ) ) ;
memcpy ( & V_33 [ V_31 ] , & V_14 ,
sizeof( struct V_12 ) ) ;
}
for ( V_7 = 0 ; V_7 < V_11 -> V_34 - 1 ; V_7 ++ ) {
if ( ( V_33 [ V_7 ] . V_27 + 1 ) != V_33 [ V_7 + 1 ] . V_30 ) {
F_17 ( L_1
L_2 , V_33 [ V_7 ] . V_25 ,
V_33 [ V_7 + 1 ] . V_25 ) ;
V_32 = - V_19 ;
goto V_37;
}
if ( V_33 [ V_7 ] . V_38 != V_33 [ V_7 + 1 ] . V_38 ) {
if ( ! ( V_33 [ V_7 ] . V_38 & V_39 ) ||
( V_33 [ V_7 ] . V_38 == V_40 ) ||
! ( V_33 [ V_7 + 1 ] . V_38 &
V_39 ) ||
( V_33 [ V_7 + 1 ] . V_38 == V_40 ) ) {
F_17 ( L_3
L_4 ,
V_33 [ V_7 ] . V_25 ,
V_33 [ V_7 + 1 ] . V_25 ) ;
V_32 = - V_19 ;
goto V_37;
}
}
}
V_32 = 0 ;
V_37:
F_7 ( V_33 ) ;
return V_32 ;
}
static int
F_18 ( char * V_24 , struct V_12 * * V_41 )
{
int V_32 ;
F_19 ( & V_42 ) ;
* V_41 = F_12 ( V_24 ) ;
F_20 ( & V_42 ) ;
if ( * V_41 != NULL )
return - V_43 ;
* V_41 = F_16 ( sizeof( struct V_12 ) , V_35 ) ;
if ( * V_41 == NULL )
return - V_36 ;
strcpy ( ( * V_41 ) -> V_25 , V_24 ) ;
V_32 = F_21 ( V_24 , V_44 ,
& ( * V_41 ) -> V_30 , & ( * V_41 ) -> V_27 ) ;
if ( V_32 < 0 ) {
F_22 ( V_32 , ( * V_41 ) -> V_25 ) ;
F_7 ( * V_41 ) ;
} else {
F_23 ( & ( * V_41 ) -> V_15 ) ;
( * V_41 ) -> V_38 = V_32 ;
}
return V_32 ;
}
static T_3
F_24 ( struct V_8 * V_9 , struct V_45 * V_46 , char * V_47 )
{
struct V_10 * V_11 ;
V_11 = F_4 ( V_9 , struct V_10 , V_9 ) ;
return sprintf ( V_47 , V_11 -> V_48 ? L_5 : L_6 ) ;
}
static T_3
F_25 ( struct V_8 * V_9 , struct V_45 * V_46 , const char * V_49 , T_1 V_50 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 , * V_14 ;
int V_32 ;
if ( ( V_50 > 1 ) && ( V_49 [ 1 ] != '\n' ) && ( V_49 [ 1 ] != '\0' ) )
return - V_19 ;
F_26 ( & V_42 ) ;
V_11 = F_4 ( V_9 , struct V_10 , V_9 ) ;
if ( F_27 ( & V_11 -> V_51 ) ) {
V_32 = - V_23 ;
goto V_37;
}
if ( V_49 [ 0 ] == '1' ) {
F_10 (entry, &dev_info->seg_list, lh) {
V_32 = F_28 ( V_13 -> V_25 ,
V_44 ) ;
if ( V_32 < 0 ) {
F_29 ( V_32 == - V_19 ) ;
if ( V_32 != - V_52 )
goto V_53;
}
}
V_11 -> V_48 = 1 ;
switch ( V_11 -> V_38 ) {
case V_54 :
case V_40 :
case V_55 :
F_30 ( V_11 -> V_21 , 1 ) ;
}
} else if ( V_49 [ 0 ] == '0' ) {
if ( V_11 -> V_38 == V_55 ) {
F_17 ( L_7
L_8 ,
V_11 -> V_25 ) ;
V_32 = - V_19 ;
goto V_37;
}
F_10 (entry, &dev_info->seg_list, lh) {
V_32 = F_28 ( V_13 -> V_25 ,
V_39 ) ;
if ( V_32 < 0 ) {
F_29 ( V_32 == - V_19 ) ;
if ( V_32 != - V_52 )
goto V_53;
}
}
V_11 -> V_48 = 0 ;
F_30 ( V_11 -> V_21 , 0 ) ;
} else {
V_32 = - V_19 ;
goto V_37;
}
V_32 = V_50 ;
goto V_37;
V_53:
F_17 ( L_9
L_10 , V_11 -> V_25 ) ;
V_14 = V_13 ;
F_10 (entry, &dev_info->seg_list, lh) {
if ( V_13 != V_14 )
F_31 ( V_13 -> V_25 ) ;
}
F_6 ( & V_11 -> V_15 ) ;
F_32 ( V_11 -> V_2 ) ;
F_33 ( V_11 -> V_2 ) ;
F_34 ( V_11 -> V_21 ) ;
F_35 ( V_11 -> V_56 ) ;
V_11 -> V_21 -> V_57 = NULL ;
F_36 ( V_11 -> V_21 ) ;
F_37 ( & V_42 ) ;
if ( F_38 ( V_9 , V_46 ) ) {
F_39 ( V_9 ) ;
F_40 ( V_9 ) ;
}
return V_32 ;
V_37:
F_37 ( & V_42 ) ;
return V_32 ;
}
static T_3
F_41 ( struct V_8 * V_9 , struct V_45 * V_46 , char * V_47 )
{
struct V_10 * V_11 ;
V_11 = F_4 ( V_9 , struct V_10 , V_9 ) ;
return sprintf ( V_47 , V_11 -> V_58 ? L_5 : L_6 ) ;
}
static T_3
F_42 ( struct V_8 * V_9 , struct V_45 * V_46 , const char * V_49 , T_1 V_50 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
if ( ( V_50 > 1 ) && ( V_49 [ 1 ] != '\n' ) && ( V_49 [ 1 ] != '\0' ) )
return - V_19 ;
V_11 = F_4 ( V_9 , struct V_10 , V_9 ) ;
F_26 ( & V_42 ) ;
if ( V_49 [ 0 ] == '1' ) {
if ( F_27 ( & V_11 -> V_51 ) == 0 ) {
F_43 ( L_11
L_12 , V_11 -> V_25 ) ;
F_10 (entry, &dev_info->seg_list, lh) {
if ( V_13 -> V_38 == V_59 ||
V_13 -> V_38 == V_60 )
F_44 ( L_13
L_14 ,
V_13 -> V_25 ) ;
else
F_45 ( V_13 -> V_25 ) ;
}
} else {
F_43 ( L_15
L_16 ,
V_11 -> V_25 ) ;
V_11 -> V_58 = 1 ;
}
} else if ( V_49 [ 0 ] == '0' ) {
if ( V_11 -> V_58 ) {
V_11 -> V_58 = 0 ;
F_43 ( L_17
L_18 ,
V_11 -> V_25 ) ;
}
} else {
F_37 ( & V_42 ) ;
return - V_19 ;
}
F_37 ( & V_42 ) ;
return V_50 ;
}
static T_3
F_46 ( struct V_8 * V_9 , struct V_45 * V_46 ,
char * V_47 )
{
int V_7 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
F_19 ( & V_42 ) ;
V_11 = F_4 ( V_9 , struct V_10 , V_9 ) ;
V_7 = 0 ;
V_47 [ 0 ] = '\0' ;
F_10 (entry, &dev_info->seg_list, lh) {
strcpy ( & V_47 [ V_7 ] , V_13 -> V_25 ) ;
V_7 += strlen ( V_13 -> V_25 ) ;
V_47 [ V_7 ] = '\n' ;
V_7 ++ ;
}
F_20 ( & V_42 ) ;
return V_7 ;
}
static T_3
F_47 ( struct V_8 * V_9 , struct V_45 * V_46 , const char * V_47 , T_1 V_50 )
{
int V_32 , V_7 , V_31 , V_34 ;
struct V_10 * V_11 ;
struct V_12 * V_41 , * V_14 ;
char * V_61 ;
unsigned long V_62 ;
V_11 = NULL ;
V_41 = NULL ;
if ( V_9 != V_63 ) {
V_32 = - V_19 ;
goto V_64;
}
if ( ( V_50 < 1 ) || ( V_47 [ 0 ] == '\0' ) || ( V_47 [ 0 ] == '\n' ) ) {
V_32 = - V_65 ;
goto V_64;
}
V_61 = F_48 ( V_50 + 1 , V_35 ) ;
if ( V_61 == NULL ) {
V_32 = - V_36 ;
goto V_64;
}
V_34 = 0 ;
for ( V_7 = 0 ; ( V_7 < V_50 && ( V_47 [ V_7 ] != '\0' ) && ( V_47 [ V_7 ] != '\n' ) ) ; V_7 ++ ) {
for ( V_31 = V_7 ; V_31 < V_50 &&
( V_47 [ V_31 ] != ':' ) &&
( V_47 [ V_31 ] != '\0' ) &&
( V_47 [ V_31 ] != '\n' ) ; V_31 ++ ) {
V_61 [ V_31 - V_7 ] = toupper ( V_47 [ V_31 ] ) ;
}
V_61 [ V_31 - V_7 ] = '\0' ;
if ( ( ( V_31 - V_7 ) == 0 ) || ( ( V_31 - V_7 ) > 8 ) ) {
V_32 = - V_65 ;
goto V_66;
}
V_32 = F_18 ( V_61 , & V_41 ) ;
if ( V_32 < 0 )
goto V_66;
if ( V_34 == 0 ) {
V_11 = F_16 ( sizeof( struct V_10 ) ,
V_35 ) ;
if ( V_11 == NULL ) {
V_32 = - V_36 ;
goto V_37;
}
strcpy ( V_11 -> V_25 , V_61 ) ;
V_11 -> V_38 = V_41 -> V_38 ;
F_23 ( & V_11 -> V_67 ) ;
}
F_49 ( & V_41 -> V_15 , & V_11 -> V_67 ) ;
V_34 ++ ;
V_7 = V_31 ;
if ( ( V_47 [ V_31 ] == '\0' ) || ( V_47 [ V_31 ] == '\n' ) )
break;
}
if ( ( V_7 > 0 ) && ( V_47 [ V_7 - 1 ] == ':' ) ) {
V_32 = - V_65 ;
goto V_66;
}
F_50 ( V_61 , V_47 , V_7 + 1 ) ;
V_11 -> V_34 = V_34 ;
V_32 = F_15 ( V_11 ) ;
if ( V_32 < 0 )
goto V_66;
V_11 -> V_30 = F_14 ( V_11 ) ;
V_11 -> V_27 = F_13 ( V_11 ) ;
F_51 ( & V_11 -> V_9 , L_19 , V_11 -> V_25 ) ;
V_11 -> V_9 . V_68 = F_3 ;
V_11 -> V_9 . V_69 = V_70 ;
F_23 ( & V_11 -> V_15 ) ;
V_11 -> V_21 = F_52 ( V_71 ) ;
if ( V_11 -> V_21 == NULL ) {
V_32 = - V_36 ;
goto V_66;
}
V_11 -> V_21 -> V_72 = V_73 ;
V_11 -> V_21 -> V_74 = & V_75 ;
V_11 -> V_56 = F_53 ( V_35 ) ;
V_11 -> V_21 -> V_57 = V_11 -> V_56 ;
V_11 -> V_21 -> V_76 = V_11 ;
F_54 ( V_11 -> V_56 , V_77 ) ;
F_55 ( V_11 -> V_56 , 4096 ) ;
F_56 ( V_78 , V_11 -> V_56 ) ;
V_62 = ( V_11 -> V_27 - V_11 -> V_30 + 1 ) ;
F_57 ( V_11 -> V_21 , V_62 >> 9 ) ;
F_43 ( L_20
L_21 , V_61 , V_62 , V_62 >> 9 ) ;
V_11 -> V_58 = 0 ;
V_11 -> V_48 = 1 ;
V_11 -> V_9 . V_79 = V_63 ;
F_26 ( & V_42 ) ;
if ( F_12 ( V_61 ) ) {
V_32 = - V_43 ;
goto V_80;
}
V_32 = F_9 ( V_11 ) ;
if ( V_32 )
goto V_80;
sprintf ( V_11 -> V_21 -> V_81 , L_22 ,
V_11 -> V_21 -> V_22 ) ;
F_49 ( & V_11 -> V_15 , & V_82 ) ;
if ( ! F_58 ( V_16 ) ) {
V_32 = - V_83 ;
goto V_84;
}
V_32 = F_59 ( & V_11 -> V_9 ) ;
if ( V_32 )
goto V_85;
V_11 -> V_2 = F_60 ( V_11 , V_11 -> V_21 -> V_81 ,
& V_86 ) ;
if ( ! V_11 -> V_2 ) {
V_32 = - V_36 ;
goto V_85;
}
F_61 ( & V_11 -> V_9 ) ;
F_62 ( & V_11 -> V_9 , V_11 -> V_21 ) ;
switch ( V_11 -> V_38 ) {
case V_54 :
case V_40 :
case V_55 :
F_30 ( V_11 -> V_21 , 1 ) ;
break;
default:
F_30 ( V_11 -> V_21 , 0 ) ;
break;
}
F_37 ( & V_42 ) ;
V_32 = V_50 ;
goto V_37;
V_85:
F_6 ( & V_11 -> V_15 ) ;
F_35 ( V_11 -> V_56 ) ;
V_11 -> V_21 -> V_57 = NULL ;
F_36 ( V_11 -> V_21 ) ;
F_10 (seg_info, &dev_info->seg_list, lh) {
F_31 ( V_41 -> V_25 ) ;
}
F_40 ( & V_11 -> V_9 ) ;
F_37 ( & V_42 ) ;
goto V_37;
V_84:
F_6 ( & V_11 -> V_15 ) ;
V_80:
F_35 ( V_11 -> V_56 ) ;
V_11 -> V_21 -> V_57 = NULL ;
F_36 ( V_11 -> V_21 ) ;
F_37 ( & V_42 ) ;
V_66:
if ( V_11 == NULL )
goto V_37;
F_5 (seg_info, temp, &dev_info->seg_list, lh) {
F_6 ( & V_41 -> V_15 ) ;
F_31 ( V_41 -> V_25 ) ;
F_7 ( V_41 ) ;
}
F_7 ( V_11 ) ;
V_37:
F_7 ( V_61 ) ;
V_64:
return V_32 ;
}
static T_3
F_63 ( struct V_8 * V_9 , struct V_45 * V_46 , const char * V_47 , T_1 V_50 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
int V_32 , V_7 ;
char * V_61 ;
if ( V_9 != V_63 ) {
return - V_19 ;
}
V_61 = F_48 ( V_50 + 1 , V_35 ) ;
if ( V_61 == NULL ) {
return - V_36 ;
}
for ( V_7 = 0 ; ( V_7 < V_50 && ( * ( V_47 + V_7 ) != '\0' ) && ( * ( V_47 + V_7 ) != '\n' ) ) ; V_7 ++ ) {
V_61 [ V_7 ] = toupper ( V_47 [ V_7 ] ) ;
}
V_61 [ V_7 ] = '\0' ;
if ( ( V_7 == 0 ) || ( V_7 > 8 ) ) {
V_32 = - V_65 ;
goto V_87;
}
F_26 ( & V_42 ) ;
V_11 = F_11 ( V_61 ) ;
if ( V_11 == NULL ) {
F_37 ( & V_42 ) ;
F_44 ( L_23 ,
V_61 ) ;
V_32 = - V_83 ;
goto V_87;
}
if ( F_27 ( & V_11 -> V_51 ) != 0 ) {
F_37 ( & V_42 ) ;
F_44 ( L_24 ,
V_61 ) ;
V_32 = - V_23 ;
goto V_87;
}
F_6 ( & V_11 -> V_15 ) ;
F_32 ( V_11 -> V_2 ) ;
F_33 ( V_11 -> V_2 ) ;
F_34 ( V_11 -> V_21 ) ;
F_35 ( V_11 -> V_56 ) ;
V_11 -> V_21 -> V_57 = NULL ;
F_36 ( V_11 -> V_21 ) ;
F_10 (entry, &dev_info->seg_list, lh)
F_31 ( V_13 -> V_25 ) ;
F_37 ( & V_42 ) ;
F_39 ( & V_11 -> V_9 ) ;
F_40 ( & V_11 -> V_9 ) ;
V_32 = V_50 ;
V_87:
F_7 ( V_61 ) ;
return V_32 ;
}
static int
F_64 ( struct V_88 * V_89 , T_4 V_90 )
{
struct V_10 * V_11 ;
int V_32 ;
V_11 = V_89 -> V_91 -> V_76 ;
if ( NULL == V_11 ) {
V_32 = - V_83 ;
goto V_37;
}
F_65 ( & V_11 -> V_51 ) ;
V_89 -> V_92 = 4096 ;
V_32 = 0 ;
V_37:
return V_32 ;
}
static void
F_66 ( struct V_93 * V_94 , T_4 V_90 )
{
struct V_10 * V_11 = V_94 -> V_76 ;
struct V_12 * V_13 ;
if ( ! V_11 ) {
F_67 ( 1 ) ;
return;
}
F_26 ( & V_42 ) ;
if ( F_68 ( & V_11 -> V_51 )
&& ( V_11 -> V_58 ) ) {
F_43 ( L_25
L_26 , V_11 -> V_25 ) ;
F_10 (entry, &dev_info->seg_list, lh) {
if ( V_13 -> V_38 == V_59 ||
V_13 -> V_38 == V_60 )
F_44 ( L_27
L_28 , V_13 -> V_25 ) ;
else
F_45 ( V_13 -> V_25 ) ;
}
V_11 -> V_58 = 0 ;
}
F_37 ( & V_42 ) ;
}
static T_5
V_77 ( struct V_95 * V_96 , struct V_97 * V_97 )
{
struct V_10 * V_11 ;
struct V_98 V_99 ;
struct V_100 V_101 ;
unsigned long V_102 ;
unsigned long V_103 ;
unsigned long V_104 ;
unsigned long V_105 ;
F_69 ( V_96 , & V_97 ) ;
V_105 = 0 ;
V_11 = V_97 -> V_106 -> V_76 ;
if ( V_11 == NULL )
goto V_107;
if ( ( V_97 -> V_108 . V_109 & 7 ) != 0 ||
( V_97 -> V_108 . V_110 & 4095 ) != 0 )
goto V_107;
if ( F_70 ( V_97 ) > F_71 ( V_97 -> V_106 ) ) {
goto V_107;
}
if ( V_11 -> V_48 ) {
switch ( V_11 -> V_38 ) {
case V_54 :
case V_40 :
case V_55 :
if ( F_72 ( V_97 ) == V_111 ) {
F_44 ( L_29 ,
F_73 ( & V_11 -> V_9 ) ) ;
goto V_107;
}
}
}
V_102 = ( V_97 -> V_108 . V_109 >> 3 ) ;
F_74 (bvec, bio, iter) {
V_103 = ( unsigned long )
F_75 ( V_99 . V_112 ) + V_99 . V_113 ;
V_104 = V_11 -> V_30 + ( V_102 << 12 ) + V_105 ;
if ( F_76 ( ( V_103 & 4095 ) != 0 ) || ( V_99 . V_114 & 4095 ) != 0 )
goto V_107;
if ( F_72 ( V_97 ) == V_115 ) {
memcpy ( ( void * ) V_103 , ( void * ) V_104 ,
V_99 . V_114 ) ;
} else {
memcpy ( ( void * ) V_104 , ( void * ) V_103 ,
V_99 . V_114 ) ;
}
V_105 += V_99 . V_114 ;
}
F_77 ( V_97 ) ;
return V_116 ;
V_107:
F_78 ( V_97 ) ;
return V_116 ;
}
static long
F_79 ( struct V_10 * V_11 , T_2 V_3 ,
long V_117 , void * * V_118 , T_6 * V_119 )
{
T_7 V_120 = V_3 * V_121 ;
unsigned long V_122 ;
V_122 = V_11 -> V_27 - V_11 -> V_30 + 1 ;
* V_118 = ( void * ) V_11 -> V_30 + V_120 ;
* V_119 = F_80 ( F_81 ( V_11 -> V_30 + V_120 ) , V_123 ) ;
return ( V_122 - V_120 ) / V_121 ;
}
static long
F_82 ( struct V_1 * V_2 , T_2 V_3 ,
long V_117 , void * * V_118 , T_6 * V_119 )
{
struct V_10 * V_11 = F_83 ( V_2 ) ;
return F_79 ( V_11 , V_3 , V_117 , V_118 , V_119 ) ;
}
static void
F_84 ( void )
{
int V_32 , V_7 , V_31 , V_124 ;
char V_47 [ V_125 + 1 ] ;
struct V_10 * V_11 ;
for ( V_7 = 0 ; ( V_7 < V_125 ) && ( V_126 [ V_7 ] != '\0' ) ;
V_7 ++ ) {
for ( V_31 = V_7 ; ( V_31 < V_125 ) &&
( V_126 [ V_31 ] != ',' ) &&
( V_126 [ V_31 ] != '\0' ) &&
( V_126 [ V_31 ] != '(' ) ; V_31 ++ )
{
V_47 [ V_31 - V_7 ] = V_126 [ V_31 ] ;
}
V_47 [ V_31 - V_7 ] = '\0' ;
V_32 = F_47 ( V_63 , NULL , V_47 , V_31 - V_7 ) ;
if ( ( V_32 >= 0 ) && ( V_126 [ V_31 ] == '(' ) ) {
for ( V_124 = 0 ; ( V_47 [ V_124 ] != ':' ) && ( V_47 [ V_124 ] != '\0' ) ; V_124 ++ )
V_47 [ V_124 ] = toupper ( V_47 [ V_124 ] ) ;
V_47 [ V_124 ] = '\0' ;
if ( ! strncmp ( & V_126 [ V_31 ] , L_30 , 7 ) ) {
F_19 ( & V_42 ) ;
V_11 = F_11 ( V_47 ) ;
F_20 ( & V_42 ) ;
if ( V_11 )
F_25 ( & V_11 -> V_9 ,
NULL , L_6 , 2 ) ;
}
}
while ( ( V_126 [ V_31 ] != ',' ) &&
( V_126 [ V_31 ] != '\0' ) )
{
V_31 ++ ;
}
if ( V_126 [ V_31 ] == '\0' )
break;
V_7 = V_31 ;
}
}
static int F_85 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
int V_32 = 0 ;
F_10 (dev_info, &dcssblk_devices, lh) {
switch ( V_11 -> V_38 ) {
case V_54 :
case V_40 :
case V_55 :
if ( ! V_11 -> V_48 )
V_32 = - V_19 ;
break;
default:
V_32 = - V_19 ;
break;
}
if ( V_32 )
break;
}
if ( V_32 )
F_17 ( L_31
L_32 ,
V_11 -> V_25 ) ;
return V_32 ;
}
static int F_86 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
unsigned long V_30 , V_27 ;
int V_32 = 0 ;
F_10 (dev_info, &dcssblk_devices, lh) {
F_10 (entry, &dev_info->seg_list, lh) {
F_31 ( V_13 -> V_25 ) ;
V_32 = F_21 ( V_13 -> V_25 , V_44 ,
& V_30 , & V_27 ) ;
if ( V_32 < 0 ) {
F_22 ( V_32 , V_13 -> V_25 ) ;
goto V_127;
}
if ( V_30 != V_13 -> V_30 || V_27 != V_13 -> V_27 ) {
F_17 ( L_33
L_34 ,
V_13 -> V_25 ) ;
goto V_127;
}
}
}
return 0 ;
V_127:
F_87 ( L_35 ) ;
}
static int F_88 ( struct V_8 * V_9 )
{
return 0 ;
}
static void T_8
F_89 ( void )
{
F_90 ( V_128 ) ;
F_91 ( & V_129 ) ;
F_92 ( V_63 ) ;
F_93 ( V_73 , V_130 ) ;
}
static int T_9
F_94 ( void )
{
int V_32 ;
V_32 = F_95 ( & V_129 ) ;
if ( V_32 )
return V_32 ;
V_128 = F_96 ( L_36 , - 1 , NULL ,
0 ) ;
if ( F_97 ( V_128 ) ) {
V_32 = F_98 ( V_128 ) ;
goto V_131;
}
V_63 = F_99 ( L_36 ) ;
if ( F_97 ( V_63 ) ) {
V_32 = F_98 ( V_63 ) ;
goto V_132;
}
V_32 = F_100 ( V_63 , & V_133 ) ;
if ( V_32 )
goto V_134;
V_32 = F_100 ( V_63 , & V_135 ) ;
if ( V_32 )
goto V_134;
V_32 = F_101 ( 0 , V_130 ) ;
if ( V_32 < 0 )
goto V_134;
V_73 = V_32 ;
F_102 ( & V_42 ) ;
F_84 () ;
return 0 ;
V_134:
F_92 ( V_63 ) ;
V_132:
F_90 ( V_128 ) ;
V_131:
F_91 ( & V_129 ) ;
return V_32 ;
}
