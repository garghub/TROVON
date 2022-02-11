struct V_1 * F_1 ( struct V_2 * V_3 )
{
T_1 V_4 ;
union V_5 * V_6 ;
struct V_7 * V_8 = NULL ;
struct V_1 * V_9 = NULL ;
if ( F_2 ( F_3 ( NULL , V_10 , & V_4 ) ) ) {
F_4 ( V_3 , L_1 ) ;
return NULL ;
}
V_6 = F_5 ( V_4 , V_11 , 1 , 1 , NULL ) ;
if ( V_6 && V_6 -> type == V_12 ) {
V_8 = (struct V_7 * ) V_6 -> V_13 . V_14 ;
V_9 = (struct V_1 * )
F_6 ( V_8 -> V_15 , V_8 -> V_16 ,
V_17 ) ;
F_7 ( V_6 ) ;
return V_9 ;
}
F_4 ( V_3 , L_2 ) ;
return NULL ;
}
void F_8 ( struct V_1 * V_18 )
{
F_9 ( ( void * ) V_18 ) ;
}
static struct V_19 * F_10 (
struct V_2 * V_3 , struct V_20 * V_21 ,
T_2 V_22 , T_3 V_23 , T_4 V_24 , T_2 V_25 )
{
struct V_19 * V_26 ;
struct V_27 * V_28 ;
struct V_29 * V_30 = V_21 -> V_30 ;
int V_31 ;
F_11 ( V_3 , L_3 , V_21 -> V_32 ) ;
for ( V_31 = 0 ; V_31 < V_21 -> V_32 ; V_31 ++ ) {
V_28 = & V_30 -> V_33 . V_21 ;
F_11 ( V_3 , L_4 , V_28 -> V_34 ,
V_28 -> V_35 , V_28 -> V_36 ) ;
if ( V_28 -> V_34 == V_22 && V_28 -> V_35 == V_24 ) {
V_26 = & V_30 -> V_37 ;
if ( V_25 == V_38 )
return V_26 ;
if ( V_28 -> V_36 == V_23 )
return V_26 ;
}
V_30 = (struct V_29 * ) ( V_30 -> V_37 . V_39 +
V_30 -> V_37 . V_40 ) ;
}
return NULL ;
}
static void F_12 ( struct V_2 * V_3 , T_3 V_41 , T_2 V_25 ,
T_2 V_42 , T_2 V_43 , T_3 V_44 , T_2 V_45 , T_4 V_24 )
{
F_11 ( V_3 , L_5 ) ;
F_11 ( V_3 , L_4 , V_43 , V_42 , V_44 ) ;
F_11 ( V_3 , L_6 , V_41 , V_25 ) ;
F_11 ( V_3 , L_7 , V_24 ) ;
}
static bool F_13 ( struct V_2 * V_3 , struct V_46 * V_47 ,
T_3 V_41 , T_2 V_48 , T_2 V_45 )
{
F_11 ( V_3 , L_8 ,
V_47 -> V_49 , V_47 -> V_25 , V_47 -> V_50 ) ;
if ( ( V_47 -> V_49 == V_41 ) &&
( V_47 -> V_25 == V_48 ) &&
( V_47 -> V_50 == V_45 ) )
return true ;
else
return false ;
}
struct V_19
* F_14 ( struct V_51 * V_51 , T_3 V_52 , T_2 V_48 ,
T_2 V_42 , T_2 V_53 , T_3 V_44 , T_2 V_45 )
{
struct V_20 * V_21 ;
struct V_46 * V_47 ;
struct V_54 * V_55 = F_15 ( & V_51 -> V_56 ) ;
struct V_2 * V_3 = V_55 -> V_3 ;
struct V_19 * V_26 ;
struct V_1 * V_18 = V_51 -> V_18 ;
T_4 V_24 = ( V_42 == 16 ) ? 16 : 32 ;
T_2 V_57 ;
F_12 ( V_3 , V_52 , V_48 , V_42 , V_53 , V_44 , V_45 , V_24 ) ;
V_47 = (struct V_46 * ) V_18 -> V_58 ;
F_11 ( V_3 , L_9 , V_18 -> V_59 ) ;
for ( V_57 = 0 ; V_57 < V_18 -> V_59 ; V_57 ++ ) {
if ( F_13 ( V_3 , V_47 , V_52 , V_48 , V_45 ) ) {
V_21 = (struct V_20 * ) ( V_47 -> V_37 . V_39 +
V_47 -> V_37 . V_40 ) ;
V_26 = F_10 ( V_3 , V_21 , V_53 ,
V_44 , V_24 , V_48 ) ;
if ( V_26 )
return V_26 ;
}
V_47 = (struct V_46 * ) ( ( T_2 * ) V_47 + V_47 -> V_16 ) ;
}
return NULL ;
}
int F_16 ( struct V_51 * V_51 )
{
struct V_1 * V_18 = (struct V_1 * ) V_51 -> V_18 ;
struct V_46 * V_47 ;
struct V_60 * V_61 ;
struct V_2 * V_3 = & V_51 -> V_62 -> V_3 ;
unsigned int V_63 = 0 ;
T_2 V_57 ;
V_47 = (struct V_46 * ) V_18 -> V_58 ;
for ( V_57 = 0 ; V_57 < V_18 -> V_59 ; V_57 ++ ) {
if ( V_47 -> V_25 == V_38 ) {
V_61 = (struct V_60 * )
( V_47 -> V_37 . V_39 ) ;
switch ( V_61 -> V_64 ) {
case V_65 :
case V_66 :
V_63 |= V_67 ;
break;
case V_68 :
case V_69 :
case V_70 :
V_63 |= V_71 ;
break;
default:
F_17 ( V_3 , L_10 ,
V_61 -> V_64 ) ;
}
}
V_47 = (struct V_46 * ) ( ( T_2 * ) V_47 + V_47 -> V_16 ) ;
}
return V_63 ;
}
static void F_18 ( struct V_51 * V_51 )
{
char * V_72 = V_51 -> V_73 ;
int V_74 ;
int V_31 ;
V_74 = 0 ;
for ( V_31 = 0 ; V_72 [ V_31 ] ; V_31 ++ ) {
if ( ! isspace ( V_72 [ V_31 ] ) )
V_72 [ V_74 ++ ] = V_72 [ V_31 ] ;
}
V_72 [ V_74 ] = '\0' ;
}
int F_19 ( struct V_51 * V_51 )
{
struct V_1 * V_18 = (struct V_1 * ) V_51 -> V_18 ;
struct V_54 * V_55 = F_15 ( & V_51 -> V_56 ) ;
struct V_2 * V_3 = V_55 -> V_3 ;
F_11 ( V_3 , L_11 ,
V_18 -> V_75 . V_76 , V_18 -> V_75 . V_77 ,
V_18 -> V_75 . V_78 ) ;
snprintf ( V_51 -> V_73 , sizeof( V_51 -> V_73 ) , L_12 ,
V_51 -> V_79 , V_18 -> V_75 . V_76 , V_18 -> V_75 . V_77 ,
V_18 -> V_75 . V_78 , L_13 ) ;
F_18 ( V_51 ) ;
return 0 ;
}
