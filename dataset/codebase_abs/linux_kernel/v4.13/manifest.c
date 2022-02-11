static const char * F_1 ( T_1 type )
{
switch ( type ) {
case V_1 :
return L_1 ;
case V_2 :
return L_2 ;
case V_3 :
return L_3 ;
case V_4 :
return L_4 ;
case V_5 :
return L_5 ;
default:
F_2 ( 1 ) ;
return L_6 ;
}
}
static void F_3 ( struct V_6 * V_7 )
{
F_4 ( & V_7 -> V_8 ) ;
F_5 ( V_7 ) ;
}
static void F_6 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
struct V_6 * V_11 ;
F_7 (descriptor, next, &intf->manifest_descs, links)
F_3 ( V_7 ) ;
}
static void F_8 ( struct V_12 * V_13 , T_1 V_14 )
{
struct V_6 * V_15 , * V_16 ;
struct V_17 * V_18 ;
F_7 (desc, tmp, head, links) {
V_18 = V_15 -> V_19 ;
if ( V_15 -> type != V_4 )
continue;
if ( V_18 -> V_20 == V_14 )
F_3 ( V_15 ) ;
}
}
static struct V_6 * F_9 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
struct V_6 * V_11 ;
F_7 (descriptor, next, &intf->manifest_descs, links)
if ( V_7 -> type == V_5 )
return V_7 ;
return NULL ;
}
static int F_10 ( struct V_9 * V_10 ,
struct V_21 * V_15 , T_2 V_22 )
{
struct V_23 * V_24 = & V_15 -> V_25 ;
struct V_6 * V_7 ;
T_2 V_26 ;
T_2 V_27 ;
if ( V_22 < sizeof( * V_24 ) ) {
F_11 ( & V_10 -> V_28 , L_7 ,
V_22 , sizeof( * V_24 ) ) ;
return - V_29 ;
}
V_26 = F_12 ( V_24 -> V_22 ) ;
if ( V_26 > V_22 ) {
F_11 ( & V_10 -> V_28 , L_8 ,
V_26 , V_22 ) ;
return - V_29 ;
}
V_27 = sizeof( * V_24 ) ;
switch ( V_24 -> type ) {
case V_2 :
V_27 += sizeof( struct V_30 ) ;
V_27 += V_15 -> string . V_31 ;
V_27 = F_13 ( V_27 , 4 ) ;
break;
case V_3 :
V_27 += sizeof( struct V_32 ) ;
break;
case V_5 :
V_27 += sizeof( struct V_33 ) ;
break;
case V_4 :
V_27 += sizeof( struct V_17 ) ;
break;
case V_1 :
default:
F_11 ( & V_10 -> V_28 , L_9 ,
V_24 -> type ) ;
return - V_29 ;
}
if ( V_26 < V_27 ) {
F_11 ( & V_10 -> V_28 , L_10 ,
F_1 ( V_24 -> type ) ,
V_26 , V_27 ) ;
return - V_29 ;
}
if ( V_26 > V_27 ) {
F_14 ( & V_10 -> V_28 , L_11 ,
F_1 ( V_24 -> type ) ,
V_27 , V_26 ) ;
}
V_7 = F_15 ( sizeof( * V_7 ) , V_34 ) ;
if ( ! V_7 )
return - V_35 ;
V_7 -> V_22 = V_26 ;
V_7 -> V_19 = ( char * ) V_15 + sizeof( * V_24 ) ;
V_7 -> type = V_24 -> type ;
F_16 ( & V_7 -> V_8 , & V_10 -> V_36 ) ;
return V_26 ;
}
static char * F_17 ( struct V_9 * V_10 , T_1 V_37 )
{
struct V_30 * V_38 ;
struct V_6 * V_7 ;
bool V_39 = false ;
char * string ;
if ( ! V_37 )
return NULL ;
F_18 (descriptor, &intf->manifest_descs, links) {
if ( V_7 -> type != V_2 )
continue;
V_38 = V_7 -> V_19 ;
if ( V_38 -> V_40 == V_37 ) {
V_39 = true ;
break;
}
}
if ( ! V_39 )
return F_19 ( - V_41 ) ;
string = F_20 ( & V_38 -> string , V_38 -> V_31 + 1 ,
V_34 ) ;
if ( ! string )
return F_19 ( - V_35 ) ;
string [ V_38 -> V_31 ] = '\0' ;
F_3 ( V_7 ) ;
return string ;
}
static T_3 F_21 ( struct V_42 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_17 * V_18 ;
struct V_6 * V_15 , * V_11 , * V_16 ;
F_22 ( V_43 ) ;
T_1 V_14 = V_20 -> V_40 ;
T_4 V_44 ;
T_3 V_45 = 0 ;
int V_46 ;
F_7 (desc, next, &intf->manifest_descs, links) {
if ( V_15 -> type != V_4 )
continue;
V_18 = V_15 -> V_19 ;
if ( V_18 -> V_20 != V_14 )
continue;
V_44 = F_12 ( V_18 -> V_40 ) ;
if ( V_44 > V_47 )
goto exit;
if ( V_44 == V_48 ) {
F_11 ( & V_20 -> V_28 , L_12 ,
V_44 ) ;
goto exit;
}
F_18 (tmp, &list, links) {
V_18 = V_16 -> V_19 ;
if ( V_44 == F_12 ( V_18 -> V_40 ) ) {
F_11 ( & V_20 -> V_28 ,
L_13 ,
V_44 ) ;
goto exit;
}
}
F_23 ( & V_15 -> V_8 , & V_43 ) ;
V_45 ++ ;
}
if ( ! V_45 )
return 0 ;
V_20 -> V_49 = F_24 ( V_45 , sizeof( * V_20 -> V_49 ) ,
V_34 ) ;
if ( ! V_20 -> V_49 )
goto exit;
V_20 -> V_50 = V_45 ;
V_46 = 0 ;
F_7 (desc, next, &list, links) {
V_18 = V_15 -> V_19 ;
memcpy ( & V_20 -> V_49 [ V_46 ++ ] , V_18 ,
sizeof( * V_18 ) ) ;
F_3 ( V_15 ) ;
}
return V_45 ;
exit:
F_8 ( & V_43 , V_14 ) ;
F_8 ( & V_10 -> V_36 , V_14 ) ;
return 0 ;
}
static T_3 F_25 ( struct V_9 * V_10 )
{
struct V_6 * V_15 ;
struct V_42 * V_20 ;
struct V_42 * V_51 ;
T_3 V_45 = 0 ;
T_1 V_14 ;
T_1 V_52 ;
while ( ( V_15 = F_9 ( V_10 ) ) ) {
struct V_33 * V_53 ;
V_53 = V_15 -> V_19 ;
V_14 = V_53 -> V_40 ;
V_52 = V_53 -> V_52 ;
F_3 ( V_15 ) ;
if ( V_14 == V_54 ) {
F_26 ( & V_10 -> V_28 , L_14 ,
V_55 ) ;
F_8 ( & V_10 -> V_36 ,
V_14 ) ;
continue;
}
if ( V_52 == V_56 ) {
F_11 ( & V_10 -> V_28 ,
L_15 ,
V_14 ) ;
goto V_57;
}
V_20 = F_27 ( V_10 , V_14 , V_52 ) ;
if ( ! V_20 )
goto V_57;
if ( ! F_21 ( V_20 ) ) {
F_28 ( V_20 ) ;
continue;
}
V_45 ++ ;
}
return V_45 ;
V_57:
F_7 (bundle, bundle_next, &intf->bundles, links) {
F_28 ( V_20 ) ;
V_45 -- ;
}
return 0 ;
}
static bool F_29 ( struct V_9 * V_10 ,
struct V_6 * V_58 )
{
struct V_32 * V_59 = V_58 -> V_19 ;
struct V_60 * V_61 = V_10 -> V_61 ;
char * V_62 ;
V_62 = F_17 ( V_10 , V_59 -> V_63 ) ;
if ( F_30 ( V_62 ) )
return false ;
V_61 -> V_64 = V_62 ;
V_62 = F_17 ( V_10 , V_59 -> V_65 ) ;
if ( F_30 ( V_62 ) )
goto V_66;
V_61 -> V_67 = V_62 ;
V_10 -> V_68 = V_59 -> V_68 ;
F_3 ( V_58 ) ;
if ( ! F_25 ( V_10 ) ) {
F_11 ( & V_10 -> V_28 , L_16 ) ;
goto V_69;
}
return true ;
V_69:
F_5 ( V_61 -> V_67 ) ;
V_61 -> V_67 = NULL ;
V_66:
F_5 ( V_61 -> V_64 ) ;
V_61 -> V_64 = NULL ;
return false ;
}
bool F_31 ( struct V_9 * V_10 , void * V_19 , T_2 V_22 )
{
struct V_70 * V_71 ;
struct V_72 * V_25 ;
struct V_21 * V_15 ;
struct V_6 * V_7 ;
struct V_6 * V_58 = NULL ;
T_4 V_73 ;
T_3 V_39 = 0 ;
bool V_74 ;
if ( F_2 ( ! F_32 ( & V_10 -> V_36 ) ) )
return false ;
if ( V_22 < sizeof( * V_25 ) ) {
F_11 ( & V_10 -> V_28 , L_17 ,
V_22 , sizeof( * V_25 ) ) ;
return false ;
}
V_71 = V_19 ;
V_25 = & V_71 -> V_25 ;
V_73 = F_12 ( V_25 -> V_22 ) ;
if ( V_73 != V_22 ) {
F_11 ( & V_10 -> V_28 , L_18 ,
V_22 , V_73 ) ;
return false ;
}
if ( V_25 -> V_75 > V_76 ) {
F_11 ( & V_10 -> V_28 , L_19 ,
V_25 -> V_75 , V_25 -> V_77 ,
V_76 , V_78 ) ;
return false ;
}
V_15 = V_71 -> V_79 ;
V_22 -= sizeof( * V_25 ) ;
while ( V_22 ) {
int V_26 ;
V_26 = F_10 ( V_10 , V_15 , V_22 ) ;
if ( V_26 < 0 ) {
V_74 = false ;
goto V_80;
}
V_15 = (struct V_21 * ) ( ( char * ) V_15 + V_26 ) ;
V_22 -= V_26 ;
}
F_18 (descriptor, &intf->manifest_descs, links) {
if ( V_7 -> type == V_3 )
if ( ! V_39 ++ )
V_58 = V_7 ;
}
if ( V_39 != 1 ) {
F_11 ( & V_10 -> V_28 , L_20 ,
V_39 ) ;
V_74 = false ;
goto V_80;
}
V_74 = F_29 ( V_10 , V_58 ) ;
if ( V_74 && ! F_32 ( & V_10 -> V_36 ) )
F_33 ( & V_10 -> V_28 , L_21 ) ;
V_80:
F_6 ( V_10 ) ;
return V_74 ;
}
