struct V_1 * F_1 ( struct V_2 * V_3 )
{
T_1 V_4 ;
union V_5 * V_6 ;
struct V_7 * V_8 = NULL ;
struct V_1 * V_9 = NULL ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) {
F_3 ( V_3 , L_1 ) ;
return NULL ;
}
V_6 = F_4 ( V_4 , & V_10 , 1 , 1 , NULL ) ;
if ( V_6 && V_6 -> type == V_11 ) {
V_8 = (struct V_7 * ) V_6 -> V_12 . V_13 ;
V_9 = (struct V_1 * )
F_5 ( V_8 -> V_14 , V_8 -> V_15 ,
V_16 ) ;
F_6 ( V_6 ) ;
return V_9 ;
}
F_3 ( V_3 , L_2 ) ;
return NULL ;
}
void F_7 ( struct V_1 * V_17 )
{
F_8 ( ( void * ) V_17 ) ;
}
static struct V_18 * F_9 (
struct V_2 * V_3 , struct V_19 * V_20 ,
T_2 V_21 , T_3 V_22 , T_4 V_23 , T_2 V_24 )
{
struct V_18 * V_25 ;
struct V_26 * V_27 ;
struct V_28 * V_29 = V_20 -> V_29 ;
int V_30 ;
F_10 ( V_3 , L_3 , V_20 -> V_31 ) ;
for ( V_30 = 0 ; V_30 < V_20 -> V_31 ; V_30 ++ ) {
V_27 = & V_29 -> V_32 . V_20 ;
F_10 ( V_3 , L_4 , V_27 -> V_33 ,
V_27 -> V_34 , V_27 -> V_35 ) ;
if ( V_27 -> V_33 == V_21 && V_27 -> V_34 == V_23 ) {
V_25 = & V_29 -> V_36 ;
if ( V_24 == V_37 )
return V_25 ;
if ( V_27 -> V_35 == V_22 )
return V_25 ;
}
V_29 = (struct V_28 * ) ( V_29 -> V_36 . V_38 +
V_29 -> V_36 . V_39 ) ;
}
return NULL ;
}
static void F_11 ( struct V_2 * V_3 , T_3 V_40 , T_2 V_24 ,
T_2 V_41 , T_2 V_42 , T_3 V_43 , T_2 V_44 , T_4 V_23 )
{
F_10 ( V_3 , L_5 ) ;
F_10 ( V_3 , L_4 , V_42 , V_41 , V_43 ) ;
F_10 ( V_3 , L_6 , V_40 , V_24 ) ;
F_10 ( V_3 , L_7 , V_23 ) ;
}
static bool F_12 ( struct V_2 * V_3 , struct V_45 * V_46 ,
T_3 V_40 , T_2 V_47 , T_2 V_44 , T_2 V_48 )
{
F_10 ( V_3 , L_8 ,
V_46 -> V_49 , V_46 -> V_24 ,
V_46 -> V_50 , V_46 -> V_51 ) ;
if ( ( V_46 -> V_49 == V_40 ) &&
( V_46 -> V_24 == V_47 ) &&
( V_46 -> V_50 == V_44 ) &&
( V_46 -> V_51 == V_48 ) )
return true ;
else
return false ;
}
struct V_18
* F_13 ( struct V_52 * V_52 , T_3 V_53 , T_2 V_47 ,
T_2 V_41 , T_2 V_54 , T_3 V_43 ,
T_2 V_44 , T_2 V_48 )
{
struct V_19 * V_20 ;
struct V_45 * V_46 ;
struct V_55 * V_56 = F_14 ( & V_52 -> V_57 ) ;
struct V_2 * V_3 = V_56 -> V_3 ;
struct V_18 * V_25 ;
struct V_1 * V_17 = V_52 -> V_17 ;
T_4 V_23 = ( V_41 == 16 ) ? 16 : 32 ;
T_2 V_58 ;
F_11 ( V_3 , V_53 , V_47 , V_41 , V_54 , V_43 , V_44 , V_23 ) ;
V_46 = (struct V_45 * ) V_17 -> V_59 ;
F_10 ( V_3 , L_9 , V_17 -> V_60 ) ;
for ( V_58 = 0 ; V_58 < V_17 -> V_60 ; V_58 ++ ) {
if ( F_12 ( V_3 , V_46 , V_53 , V_47 ,
V_44 , V_48 ) ) {
V_20 = (struct V_19 * ) ( V_46 -> V_36 . V_38 +
V_46 -> V_36 . V_39 ) ;
V_25 = F_9 ( V_3 , V_20 , V_54 ,
V_43 , V_23 , V_47 ) ;
if ( V_25 )
return V_25 ;
}
V_46 = (struct V_45 * ) ( ( T_2 * ) V_46 + V_46 -> V_15 ) ;
}
return NULL ;
}
int F_15 ( struct V_52 * V_52 )
{
struct V_1 * V_17 = (struct V_1 * ) V_52 -> V_17 ;
struct V_45 * V_46 ;
struct V_61 * V_62 ;
struct V_2 * V_3 = & V_52 -> V_63 -> V_3 ;
unsigned int V_64 = 0 ;
T_2 V_58 ;
V_46 = (struct V_45 * ) V_17 -> V_59 ;
for ( V_58 = 0 ; V_58 < V_17 -> V_60 ; V_58 ++ ) {
if ( V_46 -> V_24 == V_37 ) {
V_62 = (struct V_61 * )
( V_46 -> V_36 . V_38 ) ;
switch ( V_62 -> V_65 ) {
case V_66 :
case V_67 :
V_64 |= V_68 ;
break;
case V_69 :
case V_70 :
case V_71 :
V_64 |= V_72 ;
break;
default:
F_16 ( V_3 , L_10 ,
V_62 -> V_65 ) ;
}
}
V_46 = (struct V_45 * ) ( ( T_2 * ) V_46 + V_46 -> V_15 ) ;
}
return V_64 ;
}
static void F_17 ( char * V_73 )
{
char * V_74 = V_73 ;
int V_75 ;
int V_30 ;
V_75 = 0 ;
for ( V_30 = 0 ; V_74 [ V_30 ] ; V_30 ++ ) {
if ( ! isspace ( V_74 [ V_30 ] ) )
V_74 [ V_75 ++ ] = V_74 [ V_30 ] ;
}
V_74 [ V_75 ] = '\0' ;
}
int F_18 ( struct V_52 * V_52 )
{
struct V_1 * V_17 = (struct V_1 * ) V_52 -> V_17 ;
struct V_55 * V_56 = F_14 ( & V_52 -> V_57 ) ;
struct V_2 * V_3 = V_56 -> V_3 ;
F_10 ( V_3 , L_11 ,
V_17 -> V_76 . V_77 , V_17 -> V_76 . V_78 ,
V_17 -> V_76 . V_79 ) ;
snprintf ( V_52 -> V_80 , sizeof( V_52 -> V_80 ) , L_12 ,
V_52 -> V_81 , V_17 -> V_76 . V_77 , V_17 -> V_76 . V_78 ,
V_17 -> V_76 . V_79 , L_13 ) ;
F_17 ( V_52 -> V_80 ) ;
return 0 ;
}
static T_5 F_19 ( struct V_2 * V_3 ,
struct V_82 * V_83 , char * V_84 )
{
struct V_85 * V_63 = F_20 ( V_3 ) ;
struct V_86 * V_57 = F_21 ( V_63 ) ;
struct V_52 * V_52 = F_22 ( V_57 ) ;
struct V_1 * V_17 = (struct V_1 * ) V_52 -> V_17 ;
char V_87 [ 32 ] ;
sprintf ( V_87 , L_14 , V_52 -> V_81 ,
V_17 -> V_76 . V_77 , V_17 -> V_76 . V_78 ,
V_17 -> V_76 . V_79 ) ;
F_17 ( V_87 ) ;
return sprintf ( V_84 , L_15 , V_87 ) ;
}
int F_23 ( struct V_52 * V_52 )
{
struct V_2 * V_3 = & V_52 -> V_63 -> V_3 ;
if ( F_24 ( & V_3 -> V_88 , & V_89 . V_83 ) )
F_16 ( V_3 , L_16 ) ;
return 0 ;
}
void F_25 ( struct V_52 * V_52 )
{
struct V_2 * V_3 = & V_52 -> V_63 -> V_3 ;
F_26 ( & V_3 -> V_88 , & V_89 . V_83 ) ;
}
