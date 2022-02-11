int
F_1 ( int V_1 )
{
int V_2 = 0 ;
if ( ( V_1 >= 2412 ) && ( V_1 <= 2484 ) ) {
while ( ( V_2 < 14 ) && ( V_1 != V_3 [ V_2 ] ) )
V_2 ++ ;
return ( V_2 >= 14 ) ? 0 : ++ V_2 ;
} else if ( ( V_1 >= ( int ) 5000 ) && ( V_1 <= ( int ) 6000 ) ) {
return ( ( V_1 - 5000 ) / 5 ) ;
} else
return 0 ;
}
int
F_2 ( T_1 * V_4 )
{
int V_5 ;
V_4 -> V_6 = F_3 ( V_7 , sizeof ( void * ) , V_8 ) ;
if ( ! V_4 -> V_6 )
return - V_9 ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
if ( V_10 [ V_5 ] . V_11 & V_12 ) {
V_4 -> V_6 [ V_5 ] = F_4 ( V_10 [ V_5 ] . V_13 *
( V_10 [ V_5 ] . V_14 + 1 ) ,
V_8 ) ;
if ( ! V_4 -> V_6 [ V_5 ] )
return - V_9 ;
} else
V_4 -> V_6 [ V_5 ] = NULL ;
}
F_5 ( & V_4 -> V_15 ) ;
F_6 ( V_4 ) ;
return 0 ;
}
void
F_7 ( T_1 * V_4 )
{
int V_5 ;
if ( ! V_4 -> V_6 )
return;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
F_8 ( V_4 -> V_6 [ V_5 ] ) ;
V_4 -> V_6 [ V_5 ] = NULL ;
}
F_8 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
}
void
F_9 ( int type , void * V_16 )
{
switch ( type ) {
case V_17 :
* ( V_18 * ) V_16 = F_10 ( * ( V_18 * ) V_16 ) ;
break;
case V_19 : {
struct V_20 * V_21 = V_16 ;
V_21 -> V_13 = F_10 ( V_21 -> V_13 ) ;
V_21 -> V_22 = F_10 ( V_21 -> V_22 ) ;
break;
}
case V_23 : {
struct V_24 * V_25 = V_16 ;
V_25 -> V_26 = F_11 ( V_25 -> V_26 ) ;
V_25 -> V_27 = F_11 ( V_25 -> V_27 ) ;
V_25 -> V_28 = F_11 ( V_25 -> V_28 ) ;
V_25 -> V_29 = F_11 ( V_25 -> V_29 ) ;
V_25 -> V_30 = F_11 ( V_25 -> V_30 ) ;
break;
}
case V_31 : {
struct V_32 * V_33 = V_16 ;
int V_5 ;
V_33 -> V_34 = F_10 ( V_33 -> V_34 ) ;
for ( V_5 = 0 ; V_5 < V_33 -> V_34 ; V_5 ++ )
F_9 ( V_23 , & V_33 -> V_35 [ V_5 ] ) ;
break;
}
case V_36 : {
struct V_37 * V_38 = V_16 ;
int V_5 ;
V_38 -> V_34 = F_11 ( V_38 -> V_34 ) ;
for ( V_5 = 0 ; V_5 < V_38 -> V_34 ; V_5 ++ )
V_38 -> V_39 [ V_5 ] = F_11 ( V_38 -> V_39 [ V_5 ] ) ;
break;
}
case V_40 : {
struct V_41 * V_42 = V_16 ;
V_42 -> V_43 = F_11 ( V_42 -> V_43 ) ;
V_42 -> V_44 = F_11 ( V_42 -> V_44 ) ;
V_42 -> V_45 = F_11 ( V_42 -> V_45 ) ;
break;
}
case V_46 : {
struct V_47 * V_42 = V_16 ;
V_42 -> V_43 = F_11 ( V_42 -> V_43 ) ;
V_42 -> V_44 = F_11 ( V_42 -> V_44 ) ;
V_42 -> V_45 = F_11 ( V_42 -> V_45 ) ;
V_42 -> V_13 = F_11 ( V_42 -> V_13 ) ;
break;
}
case V_48 : {
struct V_49 * V_50 = V_16 ;
V_50 -> V_43 = F_11 ( V_50 -> V_43 ) ;
V_50 -> V_13 = F_11 ( V_50 -> V_13 ) ;
break;
}
case V_51 :
case V_52 :
case V_53 :
case V_54 :
break;
default:
F_12 () ;
}
}
static void
F_13 ( int type , void * V_16 )
{
switch ( type ) {
case V_17 :
* ( V_18 * ) V_16 = F_14 ( * ( V_18 * ) V_16 ) ;
break;
case V_19 : {
struct V_20 * V_21 = V_16 ;
V_21 -> V_13 = F_14 ( V_21 -> V_13 ) ;
V_21 -> V_22 = F_14 ( V_21 -> V_22 ) ;
break;
}
case V_23 : {
struct V_24 * V_25 = V_16 ;
V_25 -> V_26 = F_15 ( V_25 -> V_26 ) ;
V_25 -> V_27 = F_15 ( V_25 -> V_27 ) ;
V_25 -> V_28 = F_15 ( V_25 -> V_28 ) ;
V_25 -> V_29 = F_15 ( V_25 -> V_29 ) ;
V_25 -> V_30 = F_15 ( V_25 -> V_30 ) ;
break;
}
case V_31 : {
struct V_32 * V_33 = V_16 ;
int V_5 ;
V_33 -> V_34 = F_14 ( V_33 -> V_34 ) ;
for ( V_5 = 0 ; V_5 < V_33 -> V_34 ; V_5 ++ )
F_13 ( V_23 , & V_33 -> V_35 [ V_5 ] ) ;
break;
}
case V_36 : {
struct V_37 * V_38 = V_16 ;
int V_5 ;
V_38 -> V_34 = F_15 ( V_38 -> V_34 ) ;
for ( V_5 = 0 ; V_5 < V_38 -> V_34 ; V_5 ++ )
V_38 -> V_39 [ V_5 ] = F_15 ( V_38 -> V_39 [ V_5 ] ) ;
break;
}
case V_40 : {
struct V_41 * V_42 = V_16 ;
V_42 -> V_43 = F_15 ( V_42 -> V_43 ) ;
V_42 -> V_44 = F_15 ( V_42 -> V_44 ) ;
V_42 -> V_45 = F_15 ( V_42 -> V_45 ) ;
break;
}
case V_46 : {
struct V_47 * V_42 = V_16 ;
V_42 -> V_43 = F_15 ( V_42 -> V_43 ) ;
V_42 -> V_44 = F_15 ( V_42 -> V_44 ) ;
V_42 -> V_45 = F_15 ( V_42 -> V_45 ) ;
V_42 -> V_13 = F_15 ( V_42 -> V_13 ) ;
break;
}
case V_48 : {
struct V_49 * V_50 = V_16 ;
V_50 -> V_43 = F_15 ( V_50 -> V_43 ) ;
V_50 -> V_13 = F_15 ( V_50 -> V_13 ) ;
break;
}
case V_51 :
case V_52 :
case V_53 :
case V_54 :
break;
default:
F_12 () ;
}
}
int
F_16 ( T_1 * V_4 , enum V_55 V_56 , int V_57 , void * V_16 )
{
int V_58 = 0 ;
struct V_59 * V_60 = NULL ;
int V_61 = V_62 ;
int V_63 ;
void * V_64 , * V_65 = V_16 ;
V_18 V_66 ;
F_17 ( V_7 <= V_56 ) ;
F_17 ( V_57 > V_10 [ V_56 ] . V_14 ) ;
if ( ! V_4 -> V_6 )
return - 1 ;
V_63 = V_10 [ V_56 ] . V_13 ;
V_64 = V_4 -> V_6 [ V_56 ] ;
V_64 += ( V_64 ? V_57 * V_63 : 0 ) ;
V_66 = V_10 [ V_56 ] . V_66 + V_57 ;
if ( V_65 == NULL )
V_65 = V_64 ;
else
F_13 ( V_10 [ V_56 ] . V_11 & V_67 , V_65 ) ;
if ( V_64 )
F_18 ( & V_4 -> V_15 ) ;
if ( F_19 ( V_4 ) >= V_68 ) {
V_58 = F_20 ( V_4 -> V_69 , V_70 , V_66 ,
V_65 , V_63 , & V_60 ) ;
if ( ! V_58 ) {
V_61 = V_60 -> V_71 -> V_72 ;
F_21 ( V_60 ) ;
}
if ( V_58 || V_61 == V_62 )
V_58 = - V_73 ;
} else if ( ! V_64 )
V_58 = - V_73 ;
if ( V_64 ) {
if ( ! V_58 && V_16 )
memcpy ( V_64 , V_65 , V_63 ) ;
F_22 ( & V_4 -> V_15 ) ;
}
if ( V_16 )
F_9 ( V_10 [ V_56 ] . V_11 & V_67 , V_16 ) ;
return V_58 ;
}
int
F_23 ( T_1 * V_4 , enum V_55 V_56 , void * V_16 , int V_74 )
{
int V_58 = 0 ;
struct V_59 * V_60 ;
int V_61 = V_62 ;
int V_63 ;
V_18 V_66 ;
F_17 ( V_7 <= V_56 ) ;
V_63 = V_10 [ V_56 ] . V_13 ;
V_66 = V_10 [ V_56 ] . V_66 ;
F_13 ( V_10 [ V_56 ] . V_11 & V_67 , V_16 ) ;
if ( F_19 ( V_4 ) >= V_68 ) {
V_58 = F_20 ( V_4 -> V_69 , V_70 , V_66 ,
V_16 , V_63 + V_74 , & V_60 ) ;
if ( ! V_58 ) {
V_61 = V_60 -> V_71 -> V_72 ;
F_21 ( V_60 ) ;
}
if ( V_58 || V_61 == V_62 )
V_58 = - V_73 ;
} else
V_58 = - V_73 ;
if ( V_16 )
F_9 ( V_10 [ V_56 ] . V_11 & V_67 , V_16 ) ;
return V_58 ;
}
int
F_24 ( T_1 * V_4 , enum V_55 V_56 , int V_57 , void * V_16 ,
union V_75 * V_76 )
{
int V_58 = - V_73 ;
int V_77 = 0 ;
struct V_59 * V_60 = NULL ;
int V_63 ;
void * V_64 , * V_78 = NULL ;
V_18 V_66 ;
F_17 ( V_7 <= V_56 ) ;
F_17 ( V_57 > V_10 [ V_56 ] . V_14 ) ;
V_76 -> V_79 = NULL ;
if ( ! V_4 -> V_6 )
return - 1 ;
V_63 = V_10 [ V_56 ] . V_13 ;
V_64 = V_4 -> V_6 [ V_56 ] ;
V_64 += V_64 ? V_57 * V_63 : 0 ;
V_66 = V_10 [ V_56 ] . V_66 + V_57 ;
V_77 = V_63 ;
if ( V_64 )
F_25 ( & V_4 -> V_15 ) ;
if ( F_19 ( V_4 ) >= V_68 ) {
V_58 = F_20 ( V_4 -> V_69 , V_80 ,
V_66 , V_16 , V_63 , & V_60 ) ;
if ( V_58 || ! V_60 ||
V_60 -> V_71 -> V_72 == V_62 ) {
if ( V_60 )
F_21 ( V_60 ) ;
V_58 = - V_73 ;
}
if ( ! V_58 ) {
V_78 = V_60 -> V_16 ;
V_77 = V_60 -> V_71 -> V_81 ;
}
} else if ( V_64 ) {
V_78 = V_64 ;
V_58 = 0 ;
}
if ( ( V_10 [ V_56 ] . V_11 & V_67 ) == V_17 )
V_76 -> V_82 = V_58 ? 0 : F_10 ( * ( V_18 * ) V_78 ) ;
else {
V_76 -> V_79 = F_26 ( V_77 , V_8 ) ;
F_17 ( V_76 -> V_79 == NULL ) ;
if ( V_58 )
memset ( V_76 -> V_79 , 0 , V_77 ) ;
else {
memcpy ( V_76 -> V_79 , V_78 , V_77 ) ;
F_9 ( V_10 [ V_56 ] . V_11 & V_67 ,
V_76 -> V_79 ) ;
}
}
if ( V_64 )
F_27 ( & V_4 -> V_15 ) ;
if ( V_60 && ! V_58 )
F_21 ( V_60 ) ;
if ( V_77 > V_10 [ V_56 ] . V_13 )
F_28 ( V_83
L_1
L_2 ,
V_66 , V_77 , V_10 [ V_56 ] . V_13 ) ;
return V_58 ;
}
int
F_29 ( T_1 * V_4 , enum V_55 * V_84 , int V_56 )
{
int V_5 , V_58 = 0 ;
struct V_59 * V_60 ;
for ( V_5 = 0 ; V_5 < V_56 ; V_5 ++ ) {
struct V_85 * V_86 = & ( V_10 [ V_84 [ V_5 ] ] ) ;
void * V_16 = V_4 -> V_6 [ V_84 [ V_5 ] ] ;
int V_87 = 0 ;
V_18 V_66 = V_86 -> V_66 ;
F_17 ( V_16 == NULL ) ;
while ( V_87 <= V_86 -> V_14 ) {
int V_88 = F_20 ( V_4 -> V_69 , V_70 ,
V_66 , V_16 , V_86 -> V_13 ,
& V_60 ) ;
if ( V_60 ) {
V_88 |= ( V_60 -> V_71 -> V_72 == V_62 ) ;
F_21 ( V_60 ) ;
}
if ( V_88 )
F_28 ( V_89 L_3
L_4 ,
V_4 -> V_69 -> V_90 , V_66 , V_88 ) ;
V_58 |= V_88 ;
V_87 ++ ;
V_66 ++ ;
V_16 += V_86 -> V_13 ;
}
}
return V_58 ;
}
void
F_30 ( T_1 * V_4 , enum V_55 V_56 , void * V_16 )
{
F_17 ( V_7 <= V_56 ) ;
F_17 ( V_4 -> V_6 [ V_56 ] == NULL ) ;
memcpy ( V_4 -> V_6 [ V_56 ] , V_16 , V_10 [ V_56 ] . V_13 ) ;
F_13 ( V_10 [ V_56 ] . V_11 & V_67 , V_4 -> V_6 [ V_56 ] ) ;
}
void
F_31 ( T_1 * V_4 , enum V_55 V_56 , void * V_76 )
{
F_17 ( V_7 <= V_56 ) ;
F_17 ( V_4 -> V_6 [ V_56 ] == NULL ) ;
F_17 ( V_76 == NULL ) ;
memcpy ( V_76 , V_4 -> V_6 [ V_56 ] , V_10 [ V_56 ] . V_13 ) ;
F_9 ( V_10 [ V_56 ] . V_11 & V_67 , V_76 ) ;
}
static int
F_32 ( T_1 * V_4 )
{
struct V_59 * V_76 ;
int V_58 ;
V_58 = F_20 ( V_4 -> V_69 , V_80 ,
V_10 [ V_91 ] . V_66 , NULL ,
V_10 [ V_91 ] . V_13 , & V_76 ) ;
if ( ( V_58 == 0 ) && V_76 && ( V_76 -> V_71 -> V_72 != V_62 ) )
memcpy ( V_4 -> V_69 -> V_92 , V_76 -> V_16 , 6 ) ;
else
V_58 = - V_73 ;
if ( V_76 )
F_21 ( V_76 ) ;
if ( V_58 )
F_28 ( V_89 L_5 , V_4 -> V_69 -> V_90 ) ;
return V_58 ;
}
int
F_33 ( T_1 * V_4 )
{
int V_93 ;
enum V_55 V_82 ;
if ( F_19 ( V_4 ) < V_94 )
return 0 ;
V_93 = F_29 ( V_4 , V_95 , F_34 ( V_95 ) ) ;
if ( V_4 -> V_96 != V_97 )
V_93 |= F_29 ( V_4 , V_98 , F_34 ( V_98 ) ) ;
V_82 = V_99 ;
V_93 |= F_29 ( V_4 , & V_82 , 1 ) ;
V_93 |= F_32 ( V_4 ) ;
if ( V_93 ) {
F_28 ( V_83 L_6 , V_4 -> V_69 -> V_90 ) ;
}
return V_93 ;
}
int
F_35 ( T_1 * V_4 )
{
V_18 V_100 ;
F_25 ( & V_4 -> V_15 ) ;
V_100 =
F_10 ( * ( V_18 * ) V_4 -> V_6 [ V_101 ] ) ;
F_27 ( & V_4 -> V_15 ) ;
return ( ( V_4 -> V_96 == V_102 ) &&
( V_100 >= V_103 ) ) ;
}
enum V_55
F_36 ( V_18 V_66 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ )
if ( V_10 [ V_5 ] . V_66 == V_66 )
return V_5 ;
F_28 ( V_83 L_7 , V_66 ) ;
return V_7 ;
}
int
F_37 ( enum V_55 V_56 , union V_75 * V_88 , char * V_104 )
{
switch ( V_10 [ V_56 ] . V_11 & V_67 ) {
case V_17 :
return snprintf ( V_104 , V_105 , L_8 , V_88 -> V_82 ) ;
break;
case V_19 : {
struct V_20 * V_21 = V_88 -> V_79 ;
return snprintf ( V_104 , V_105 ,
L_9 , V_21 -> V_13 ,
V_21 -> V_22 ) ;
}
break;
case V_23 : {
struct V_24 * V_25 = V_88 -> V_79 ;
return snprintf ( V_104 , V_105 ,
L_10
L_11
L_12 , V_25 -> V_26 ,
V_25 -> V_27 , V_25 -> V_28 ,
V_25 -> V_29 , V_25 -> V_30 ) ;
}
break;
case V_31 : {
struct V_32 * V_33 = V_88 -> V_79 ;
int V_5 , V_106 ;
V_106 = snprintf ( V_104 , V_105 , L_13 , V_33 -> V_34 ) ;
for ( V_5 = 0 ; V_5 < V_33 -> V_34 ; V_5 ++ )
V_106 += snprintf ( V_104 + V_106 , V_105 - V_106 ,
L_14
L_11
L_12 ,
V_5 , V_33 -> V_35 [ V_5 ] . V_26 ,
V_33 -> V_35 [ V_5 ] . V_27 ,
V_33 -> V_35 [ V_5 ] . V_28 ,
V_33 -> V_35 [ V_5 ] . V_29 ,
V_33 -> V_35 [ V_5 ] . V_30 ) ;
return V_106 ;
}
break;
case V_36 : {
struct V_37 * V_38 = V_88 -> V_79 ;
int V_5 , V_86 ;
F_28 ( L_15 , V_38 -> V_34 ) ;
V_86 = snprintf ( V_104 , V_105 , L_13 , V_38 -> V_34 ) ;
for ( V_5 = 0 ; V_5 < V_38 -> V_34 ; V_5 ++ )
V_86 += snprintf ( V_104 + V_86 , V_105 - V_86 ,
L_16 , V_5 , V_38 -> V_39 [ V_5 ] ) ;
return V_86 ;
}
break;
case V_40 : {
struct V_41 * V_42 = V_88 -> V_79 ;
return snprintf ( V_104 , V_105 ,
L_17 ,
V_42 -> V_43 , V_42 -> V_44 , V_42 -> V_45 ) ;
}
break;
case V_46 : {
struct V_47 * V_42 = V_88 -> V_79 ;
return snprintf ( V_104 , V_105 ,
L_18
L_19 , V_42 -> V_43 ,
V_42 -> V_44 , V_42 -> V_45 , V_42 -> V_13 ) ;
}
break;
case V_48 : {
struct V_49 * V_50 = V_88 -> V_79 ;
return snprintf ( V_104 , V_105 ,
L_20 ,
V_50 -> V_43 ,
V_50 -> V_13 ) ;
}
break;
case V_51 : {
struct V_107 * V_108 = V_88 -> V_79 ;
return snprintf ( V_104 , V_105 ,
L_21 ,
V_108 -> V_81 , V_108 -> V_81 ,
V_108 -> V_109 ) ;
}
break;
case V_52 : {
struct V_110 * V_111 = V_88 -> V_79 ;
int V_86 , V_5 ;
V_86 = snprintf ( V_104 , V_105 ,
L_22 ,
V_111 -> type , V_111 -> V_81 ) ;
for ( V_5 = 0 ; V_5 < V_111 -> V_81 ; V_5 ++ )
V_86 += snprintf ( V_104 + V_86 , V_105 - V_86 ,
L_23 , V_111 -> V_111 [ V_5 ] ) ;
V_86 += snprintf ( V_104 + V_86 , V_105 - V_86 , L_24 ) ;
return V_86 ;
}
break;
case V_54 :
case V_53 : {
unsigned char * V_21 = V_88 -> V_79 ;
int V_86 , V_5 ;
V_86 = snprintf ( V_104 , V_105 , L_25 ) ;
for ( V_5 = 0 ; V_5 < V_10 [ V_56 ] . V_13 ; V_5 ++ )
V_86 += snprintf ( V_104 + V_86 , V_105 - V_86 ,
L_23 , V_21 [ V_5 ] ) ;
V_86 += snprintf ( V_104 + V_86 , V_105 - V_86 , L_24 ) ;
return V_86 ;
}
break;
default:
F_12 () ;
}
return 0 ;
}
