static T_1 F_1 ( T_1 * V_1 , T_1 type )
{
if ( V_1 [ 0 ] != type || V_1 [ 1 ] != V_2 [ V_1 [ 0 ] ] )
return 0 ;
return V_1 [ 2 ] ;
}
static T_2 F_2 ( T_1 * V_1 , T_1 type )
{
if ( V_1 [ 0 ] != type || V_1 [ 1 ] != V_2 [ V_1 [ 0 ] ] )
return 0 ;
return F_3 ( * ( ( V_3 * ) ( V_1 + 2 ) ) ) ;
}
static T_1 F_4 ( T_1 * V_1 )
{
return F_1 ( V_1 , V_4 ) ;
}
static T_2 F_5 ( T_1 * V_1 )
{
return F_2 ( V_1 , V_5 ) & 0x7ff ;
}
static T_2 F_6 ( T_1 * V_1 )
{
return F_2 ( V_1 , V_6 ) ;
}
static T_2 F_7 ( T_1 * V_1 )
{
return F_1 ( V_1 , V_7 ) ;
}
static T_1 F_8 ( T_1 * V_1 )
{
return F_1 ( V_1 , V_8 ) ;
}
static T_1 F_9 ( T_1 * V_1 )
{
return F_1 ( V_1 , V_9 ) & 0xf ;
}
T_1 * F_10 ( T_1 type , T_1 * V_10 , T_1 V_11 , T_1 * V_12 )
{
T_1 * V_1 , V_13 ;
F_11 ( L_1 , type ) ;
if ( type >= V_14 )
return NULL ;
V_13 = V_2 [ type ] ;
if ( V_13 == 0 && V_11 == 0 )
return NULL ;
else if ( V_13 == 0 )
V_13 = V_11 ;
* V_12 = 2 + V_13 ;
V_1 = F_12 ( 2 + V_13 , V_15 ) ;
if ( V_1 == NULL )
return V_1 ;
V_1 [ 0 ] = type ;
V_1 [ 1 ] = V_13 ;
memcpy ( V_1 + 2 , V_10 , V_13 ) ;
return V_1 ;
}
struct V_16 * F_13 ( T_1 V_17 , T_1 V_18 )
{
struct V_16 * V_19 ;
T_1 V_10 [ 2 ] ;
V_19 = F_12 ( sizeof( struct V_16 ) , V_15 ) ;
if ( V_19 == NULL )
return NULL ;
V_10 [ 0 ] = V_17 ;
V_10 [ 1 ] = V_18 ;
V_19 -> V_1 = F_10 ( V_20 , V_10 , 2 ,
& V_19 -> V_21 ) ;
if ( V_19 -> V_1 == NULL ) {
F_14 ( V_19 ) ;
return NULL ;
}
V_19 -> V_17 = V_17 ;
V_19 -> V_18 = V_18 ;
F_15 ( & V_19 -> V_22 ) ;
return V_19 ;
}
struct V_16 * F_16 ( T_1 V_17 , char * V_23 ,
T_3 V_24 )
{
struct V_16 * V_25 ;
F_11 ( L_2 , V_23 , V_24 ) ;
V_25 = F_12 ( sizeof( struct V_16 ) , V_15 ) ;
if ( V_25 == NULL )
return NULL ;
V_25 -> V_21 = V_24 + 3 ;
if ( V_23 [ V_24 - 1 ] == 0 )
V_25 -> V_21 -- ;
V_25 -> V_1 = F_12 ( V_25 -> V_21 + 1 , V_15 ) ;
if ( V_25 -> V_1 == NULL ) {
F_14 ( V_25 ) ;
return NULL ;
}
V_25 -> V_1 [ 0 ] = V_26 ;
V_25 -> V_1 [ 1 ] = V_25 -> V_21 - 2 ;
V_25 -> V_1 [ 2 ] = V_17 ;
V_25 -> V_17 = V_17 ;
V_25 -> V_23 = V_25 -> V_1 + 3 ;
memcpy ( V_25 -> V_23 , V_23 , V_24 ) ;
V_25 -> time = V_27 ;
F_15 ( & V_25 -> V_22 ) ;
return V_25 ;
}
void F_17 ( struct V_16 * V_28 )
{
F_14 ( V_28 -> V_1 ) ;
F_14 ( V_28 ) ;
}
void F_18 ( struct V_29 * V_30 )
{
struct V_16 * V_28 ;
struct V_31 * V_32 ;
F_19 (sdp, n, head, node) {
F_20 ( & V_28 -> V_22 ) ;
F_17 ( V_28 ) ;
}
}
int F_21 ( struct V_33 * V_34 ,
T_1 * V_35 , T_2 V_36 )
{
T_1 * V_1 = V_35 , type , V_13 , V_37 = 0 ;
F_11 ( L_3 , V_36 ) ;
if ( V_34 == NULL )
return - V_38 ;
while ( V_37 < V_36 ) {
type = V_1 [ 0 ] ;
V_13 = V_1 [ 1 ] ;
F_11 ( L_4 , type , V_13 ) ;
switch ( type ) {
case V_4 :
V_34 -> V_39 = F_4 ( V_1 ) ;
break;
case V_5 :
V_34 -> V_40 = F_5 ( V_1 ) + 128 ;
break;
case V_6 :
V_34 -> V_41 = F_6 ( V_1 ) ;
break;
case V_7 :
V_34 -> V_42 = F_7 ( V_1 ) * 10 ;
break;
case V_8 :
V_34 -> V_43 = F_8 ( V_1 ) ;
break;
default:
F_22 ( L_5 , type ) ;
break;
}
V_37 += V_13 + 2 ;
V_1 += V_13 + 2 ;
}
F_11 ( L_6 ,
V_34 -> V_39 , V_34 -> V_40 ,
V_34 -> V_42 , V_34 -> V_43 ,
V_34 -> V_41 ) ;
return 0 ;
}
int F_23 ( struct V_44 * V_45 ,
T_1 * V_35 , T_2 V_36 )
{
T_1 * V_1 = V_35 , type , V_13 , V_37 = 0 ;
F_11 ( L_3 , V_36 ) ;
if ( V_45 == NULL )
return - V_46 ;
while ( V_37 < V_36 ) {
type = V_1 [ 0 ] ;
V_13 = V_1 [ 1 ] ;
F_11 ( L_4 , type , V_13 ) ;
switch ( type ) {
case V_5 :
V_45 -> V_40 = F_5 ( V_1 ) + 128 ;
break;
case V_9 :
V_45 -> V_47 = F_9 ( V_1 ) ;
break;
case V_48 :
break;
default:
F_22 ( L_5 , type ) ;
break;
}
V_37 += V_13 + 2 ;
V_1 += V_13 + 2 ;
}
F_11 ( L_7 , V_45 ,
V_45 -> V_47 , V_45 -> V_40 ) ;
return 0 ;
}
static struct V_49 * F_24 ( struct V_49 * V_50 ,
T_1 V_51 , T_1 V_52 , T_1 V_53 )
{
T_1 V_54 [ 2 ] ;
F_11 ( L_8 , V_53 , V_51 , V_52 ) ;
V_54 [ 0 ] = ( T_1 ) ( ( V_51 << 2 ) | ( V_53 >> 2 ) ) ;
V_54 [ 1 ] = ( T_1 ) ( ( V_53 << 6 ) | V_52 ) ;
F_11 ( L_9 , V_54 [ 0 ] , V_54 [ 1 ] ) ;
memcpy ( F_25 ( V_50 , V_55 ) , V_54 , V_55 ) ;
return V_50 ;
}
static struct V_49 * F_26 ( struct V_49 * V_50 , T_1 * V_1 ,
T_1 V_12 )
{
if ( V_1 == NULL )
return NULL ;
memcpy ( F_25 ( V_50 , V_12 ) , V_1 , V_12 ) ;
return V_50 ;
}
static struct V_49 * F_27 ( struct V_44 * V_45 ,
T_1 V_56 , T_2 V_57 )
{
struct V_49 * V_58 ;
int V_59 ;
if ( V_45 -> V_52 == 0 )
return NULL ;
V_58 = F_28 ( V_45 -> V_60 , & V_45 -> V_61 , V_62 ,
V_57 + V_55 , & V_59 ) ;
if ( V_58 == NULL ) {
F_22 ( L_10 ) ;
return NULL ;
}
V_58 = F_24 ( V_58 , V_45 -> V_51 , V_45 -> V_52 , V_56 ) ;
return V_58 ;
}
int F_29 ( struct V_44 * V_45 )
{
struct V_49 * V_58 ;
struct V_63 * V_60 ;
struct V_33 * V_34 ;
F_11 ( L_11 ) ;
V_34 = V_45 -> V_34 ;
if ( V_34 == NULL )
return - V_38 ;
V_60 = V_45 -> V_60 ;
if ( V_60 == NULL )
return - V_38 ;
V_58 = F_27 ( V_45 , V_64 , 0 ) ;
if ( V_58 == NULL )
return - V_65 ;
F_30 ( & V_34 -> V_66 , V_58 ) ;
return 0 ;
}
int F_31 ( struct V_63 * V_60 )
{
struct V_49 * V_58 ;
struct V_33 * V_34 ;
T_2 V_57 = 0 ;
F_11 ( L_12 ) ;
V_34 = F_32 ( V_60 ) ;
if ( V_34 == NULL )
return - V_38 ;
V_57 += V_55 ;
V_57 += V_60 -> V_67 + V_60 -> V_68 + V_69 ;
V_58 = F_33 ( V_57 , V_15 ) ;
if ( V_58 == NULL )
return - V_65 ;
F_34 ( V_58 , V_60 -> V_67 + V_69 ) ;
V_58 = F_24 ( V_58 , 0 , 0 , V_70 ) ;
F_35 ( V_58 ) ;
F_36 ( V_34 , V_58 , V_71 ) ;
return F_37 ( V_60 , V_34 -> V_72 , V_58 ,
V_73 , V_34 ) ;
}
int F_38 ( struct V_44 * V_45 )
{
struct V_33 * V_34 ;
struct V_49 * V_58 ;
T_1 * V_74 = NULL , V_75 ;
T_1 * V_76 = NULL , V_77 ;
T_1 * V_78 = NULL , V_79 , V_80 ;
int V_59 ;
T_2 V_57 = 0 , V_81 ;
F_11 ( L_13 ) ;
V_34 = V_45 -> V_34 ;
if ( V_34 == NULL )
return - V_38 ;
if ( V_45 -> V_82 != NULL ) {
V_74 = F_10 ( V_48 ,
V_45 -> V_82 ,
V_45 -> V_83 ,
& V_75 ) ;
V_57 += V_75 ;
}
V_81 = F_3 ( V_45 -> V_81 ) > V_84 ?
V_34 -> V_81 : V_45 -> V_81 ;
V_80 = V_45 -> V_80 > V_85 ? V_34 -> V_80 : V_45 -> V_80 ;
V_76 = F_10 ( V_5 , ( T_1 * ) & V_81 , 0 ,
& V_77 ) ;
V_57 += V_77 ;
V_78 = F_10 ( V_9 , & V_80 , 0 , & V_79 ) ;
V_57 += V_79 ;
F_11 ( L_14 , V_57 , V_45 -> V_83 ) ;
V_58 = F_27 ( V_45 , V_86 , V_57 ) ;
if ( V_58 == NULL ) {
V_59 = - V_65 ;
goto V_87;
}
if ( V_74 != NULL )
V_58 = F_26 ( V_58 , V_74 ,
V_75 ) ;
V_58 = F_26 ( V_58 , V_76 , V_77 ) ;
V_58 = F_26 ( V_58 , V_78 , V_79 ) ;
F_30 ( & V_34 -> V_66 , V_58 ) ;
return 0 ;
V_87:
F_22 ( L_15 , V_59 ) ;
F_14 ( V_74 ) ;
F_14 ( V_76 ) ;
F_14 ( V_78 ) ;
return V_59 ;
}
int F_39 ( struct V_44 * V_45 )
{
struct V_33 * V_34 ;
struct V_49 * V_58 ;
T_1 * V_76 = NULL , V_77 ;
T_1 * V_78 = NULL , V_79 , V_80 ;
int V_59 ;
T_2 V_57 = 0 , V_81 ;
F_11 ( L_16 ) ;
V_34 = V_45 -> V_34 ;
if ( V_34 == NULL )
return - V_38 ;
V_81 = F_3 ( V_45 -> V_81 ) > V_84 ?
V_34 -> V_81 : V_45 -> V_81 ;
V_80 = V_45 -> V_80 > V_85 ? V_34 -> V_80 : V_45 -> V_80 ;
V_76 = F_10 ( V_5 , ( T_1 * ) & V_81 , 0 ,
& V_77 ) ;
V_57 += V_77 ;
V_78 = F_10 ( V_9 , & V_80 , 0 , & V_79 ) ;
V_57 += V_79 ;
V_58 = F_27 ( V_45 , V_88 , V_57 ) ;
if ( V_58 == NULL ) {
V_59 = - V_65 ;
goto V_87;
}
V_58 = F_26 ( V_58 , V_76 , V_77 ) ;
V_58 = F_26 ( V_58 , V_78 , V_79 ) ;
F_30 ( & V_34 -> V_66 , V_58 ) ;
return 0 ;
V_87:
F_22 ( L_15 , V_59 ) ;
F_14 ( V_76 ) ;
F_14 ( V_78 ) ;
return V_59 ;
}
static struct V_49 * F_40 ( struct V_33 * V_34 ,
T_3 V_12 )
{
struct V_49 * V_58 ;
struct V_63 * V_60 ;
T_2 V_57 = 0 ;
if ( V_34 == NULL )
return F_41 ( - V_38 ) ;
V_60 = V_34 -> V_60 ;
if ( V_60 == NULL )
return F_41 ( - V_38 ) ;
V_57 += V_55 ;
V_57 += V_60 -> V_67 + V_60 -> V_68 + V_69 ;
V_57 += V_12 ;
V_58 = F_33 ( V_57 , V_15 ) ;
if ( V_58 == NULL )
return F_41 ( - V_65 ) ;
F_34 ( V_58 , V_60 -> V_67 + V_69 ) ;
V_58 = F_24 ( V_58 , V_89 , V_89 , V_90 ) ;
return V_58 ;
}
int F_42 ( struct V_33 * V_34 ,
struct V_29 * V_91 , T_3 V_92 )
{
struct V_16 * V_28 ;
struct V_31 * V_32 ;
struct V_49 * V_58 ;
V_58 = F_40 ( V_34 , V_92 ) ;
if ( F_43 ( V_58 ) )
return F_44 ( V_58 ) ;
F_19 (sdp, n, tlv_list, node) {
memcpy ( F_25 ( V_58 , V_28 -> V_21 ) , V_28 -> V_1 , V_28 -> V_21 ) ;
F_20 ( & V_28 -> V_22 ) ;
F_17 ( V_28 ) ;
}
F_30 ( & V_34 -> V_66 , V_58 ) ;
return 0 ;
}
int F_45 ( struct V_33 * V_34 ,
struct V_29 * V_91 , T_3 V_92 )
{
struct V_16 * V_25 ;
struct V_31 * V_32 ;
struct V_49 * V_58 ;
V_58 = F_40 ( V_34 , V_92 ) ;
if ( F_43 ( V_58 ) )
return F_44 ( V_58 ) ;
F_46 ( & V_34 -> V_93 ) ;
if ( F_47 ( & V_34 -> V_94 ) )
F_48 ( & V_34 -> V_95 ,
V_27 + F_49 ( 3 * V_34 -> V_42 ) ) ;
F_19 (sdreq, n, tlv_list, node) {
F_11 ( L_17 , V_25 -> V_17 , V_25 -> V_23 ) ;
memcpy ( F_25 ( V_58 , V_25 -> V_21 ) , V_25 -> V_1 ,
V_25 -> V_21 ) ;
F_20 ( & V_25 -> V_22 ) ;
F_50 ( & V_25 -> V_22 , & V_34 -> V_94 ) ;
}
F_51 ( & V_34 -> V_93 ) ;
F_30 ( & V_34 -> V_66 , V_58 ) ;
return 0 ;
}
int F_52 ( struct V_33 * V_34 , T_1 V_52 , T_1 V_51 , T_1 V_96 )
{
struct V_49 * V_58 ;
struct V_63 * V_60 ;
T_2 V_57 = 1 ;
F_11 ( L_18 , V_96 ) ;
if ( V_34 == NULL )
return - V_38 ;
V_60 = V_34 -> V_60 ;
if ( V_60 == NULL )
return - V_38 ;
V_57 += V_55 ;
V_57 += V_60 -> V_67 + V_60 -> V_68 + V_69 ;
V_58 = F_33 ( V_57 , V_15 ) ;
if ( V_58 == NULL )
return - V_65 ;
F_34 ( V_58 , V_60 -> V_67 + V_69 ) ;
V_58 = F_24 ( V_58 , V_51 , V_52 , V_97 ) ;
memcpy ( F_25 ( V_58 , 1 ) , & V_96 , 1 ) ;
F_53 ( & V_34 -> V_66 , V_58 ) ;
return 0 ;
}
int F_54 ( struct V_44 * V_45 )
{
struct V_49 * V_58 ;
struct V_33 * V_34 ;
F_11 ( L_19 ) ;
V_34 = V_45 -> V_34 ;
if ( V_34 == NULL )
return - V_38 ;
V_58 = F_27 ( V_45 , V_64 , 0 ) ;
if ( V_58 == NULL )
return - V_65 ;
F_53 ( & V_34 -> V_66 , V_58 ) ;
return 0 ;
}
int F_55 ( struct V_44 * V_45 ,
struct V_98 * V_99 , T_3 V_100 )
{
struct V_49 * V_50 ;
struct V_45 * V_61 = & V_45 -> V_61 ;
struct V_33 * V_34 ;
T_3 V_101 = 0 , V_102 ;
T_1 * V_103 , * V_104 ;
T_2 V_40 ;
F_11 ( L_20 , V_100 ) ;
V_34 = V_45 -> V_34 ;
if ( V_34 == NULL )
return - V_38 ;
if( ( V_45 -> V_105 &&
F_56 ( & V_45 -> V_106 ) >= V_45 -> V_47 &&
F_56 ( & V_45 -> V_66 ) >= 2 * V_45 -> V_47 ) ) {
F_22 ( L_21 ,
F_56 ( & V_45 -> V_106 ) ) ;
return - V_107 ;
}
if ( ( ! V_45 -> V_105 &&
F_56 ( & V_45 -> V_66 ) >= 2 * V_45 -> V_47 ) ) {
F_22 ( L_22 ,
F_56 ( & V_45 -> V_66 ) ) ;
return - V_107 ;
}
V_103 = F_12 ( V_100 , V_15 ) ;
if ( V_103 == NULL )
return - V_65 ;
if ( F_57 ( V_103 , V_99 -> V_108 , V_100 ) ) {
F_14 ( V_103 ) ;
return - V_109 ;
}
V_102 = V_100 ;
V_104 = V_103 ;
do {
V_40 = V_45 -> V_40 > V_110 ?
V_34 -> V_40 : V_45 -> V_40 ;
V_101 = F_58 ( T_3 , V_40 , V_102 ) ;
F_11 ( L_23 ,
V_101 , V_102 ) ;
V_50 = F_27 ( V_45 , V_111 ,
V_101 + V_112 ) ;
if ( V_50 == NULL )
return - V_65 ;
F_25 ( V_50 , V_112 ) ;
if ( F_59 ( V_101 > 0 ) )
memcpy ( F_25 ( V_50 , V_101 ) , V_104 , V_101 ) ;
F_30 ( & V_45 -> V_66 , V_50 ) ;
F_60 ( V_61 ) ;
F_61 ( V_45 ) ;
F_62 ( V_61 ) ;
V_102 -= V_101 ;
V_104 += V_101 ;
} while ( V_102 > 0 );
F_14 ( V_103 ) ;
return V_100 ;
}
int F_63 ( struct V_44 * V_45 , T_1 V_52 , T_1 V_51 ,
struct V_98 * V_99 , T_3 V_100 )
{
struct V_49 * V_50 ;
struct V_33 * V_34 ;
T_3 V_101 = 0 , V_102 ;
T_1 * V_104 , * V_103 ;
T_2 V_40 ;
int V_59 ;
F_11 ( L_24 , V_100 ) ;
V_34 = V_45 -> V_34 ;
if ( V_34 == NULL )
return - V_38 ;
V_103 = F_12 ( V_100 , V_15 ) ;
if ( V_103 == NULL )
return - V_65 ;
if ( F_57 ( V_103 , V_99 -> V_108 , V_100 ) ) {
F_14 ( V_103 ) ;
return - V_109 ;
}
V_102 = V_100 ;
V_104 = V_103 ;
do {
V_40 = V_45 -> V_40 > V_110 ?
V_34 -> V_40 : V_45 -> V_40 ;
V_101 = F_58 ( T_3 , V_40 , V_102 ) ;
F_11 ( L_23 ,
V_101 , V_102 ) ;
V_50 = F_28 ( V_45 -> V_60 , & V_45 -> V_61 , V_62 ,
V_101 + V_55 , & V_59 ) ;
if ( V_50 == NULL ) {
F_22 ( L_10 ) ;
continue;
}
V_50 = F_24 ( V_50 , V_51 , V_52 , V_113 ) ;
if ( F_59 ( V_101 > 0 ) )
memcpy ( F_25 ( V_50 , V_101 ) , V_104 , V_101 ) ;
F_30 ( & V_34 -> V_66 , V_50 ) ;
V_102 -= V_101 ;
V_104 += V_101 ;
} while ( V_102 > 0 );
F_14 ( V_103 ) ;
return V_100 ;
}
int F_64 ( struct V_44 * V_45 )
{
struct V_49 * V_58 ;
struct V_33 * V_34 ;
F_11 ( L_25 , V_45 -> V_114 ) ;
V_34 = V_45 -> V_34 ;
if ( V_34 == NULL )
return - V_38 ;
V_58 = F_27 ( V_45 , V_115 , V_112 ) ;
if ( V_58 == NULL )
return - V_65 ;
F_25 ( V_58 , V_112 ) ;
V_58 -> V_116 [ 2 ] = V_45 -> V_114 ;
F_53 ( & V_34 -> V_66 , V_58 ) ;
return 0 ;
}
