int F_1 ( struct V_1 * V_2 ,
const struct V_1 * V_3 ,
T_1 V_4 , T_2 V_5 ,
int V_6 )
{
struct V_7 * V_8 ;
int error = 0 ;
V_2 -> V_9 = V_3 -> V_9 ;
F_2 (addr, &src->address_list, list) {
error = F_3 ( V_2 , & V_8 -> V_10 , V_4 ,
V_5 , V_6 ) ;
if ( error < 0 )
goto V_11;
}
if ( F_4 ( & V_2 -> V_12 ) && ( V_13 == V_4 ) ) {
F_2 (addr, &src->address_list, list) {
error = F_3 ( V_2 , & V_8 -> V_10 ,
V_14 , V_5 ,
V_6 ) ;
if ( error < 0 )
goto V_11;
}
}
V_11:
if ( error )
F_5 ( V_2 ) ;
return error ;
}
int F_6 ( struct V_1 * V_2 ,
const struct V_1 * V_3 ,
T_2 V_5 )
{
struct V_7 * V_8 ;
int error = 0 ;
V_2 -> V_9 = V_3 -> V_9 ;
F_2 (addr, &src->address_list, list) {
error = F_7 ( V_2 , & V_8 -> V_10 , 1 , V_5 ) ;
if ( error < 0 )
break;
}
return error ;
}
void F_8 ( struct V_1 * V_15 , T_3 V_9 )
{
V_15 -> V_16 = 0 ;
F_9 ( & V_15 -> V_12 ) ;
V_15 -> V_9 = V_9 ;
}
static void F_5 ( struct V_1 * V_15 )
{
struct V_7 * V_8 , * V_17 ;
F_10 (addr, temp, &bp->address_list, list) {
F_11 ( & V_8 -> V_18 ) ;
F_12 ( V_8 , V_19 ) ;
F_13 ( V_8 ) ;
}
}
void F_14 ( struct V_1 * V_15 )
{
F_5 ( V_15 ) ;
if ( V_15 -> V_16 ) {
F_15 ( V_15 ) ;
F_13 ( V_20 ) ;
}
}
int F_7 ( struct V_1 * V_15 , union V_21 * V_22 ,
T_4 V_23 , T_2 V_5 )
{
struct V_7 * V_8 ;
V_8 = F_16 ( struct V_7 , V_5 ) ;
if ( ! V_8 )
return - V_24 ;
memcpy ( & V_8 -> V_10 , V_22 , sizeof( * V_22 ) ) ;
if ( ! V_8 -> V_10 . V_25 . V_26 )
V_8 -> V_10 . V_25 . V_26 = F_17 ( V_15 -> V_9 ) ;
V_8 -> V_27 = V_23 ;
V_8 -> V_28 = 1 ;
F_9 ( & V_8 -> V_18 ) ;
F_18 ( & V_8 -> V_18 , & V_15 -> V_12 ) ;
F_19 ( V_8 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_15 , union V_21 * V_29 )
{
struct V_7 * V_8 , * V_17 ;
int V_30 = 0 ;
F_10 (addr, temp, &bp->address_list, list) {
if ( F_21 ( & V_8 -> V_10 , V_29 ) ) {
V_30 = 1 ;
V_8 -> V_28 = 0 ;
F_11 ( & V_8 -> V_18 ) ;
break;
}
}
if ( V_30 ) {
F_12 ( V_8 , V_19 ) ;
F_13 ( V_8 ) ;
return 0 ;
}
return - V_31 ;
}
union V_32 F_22 ( const struct V_1 * V_15 ,
int * V_33 ,
T_2 V_5 )
{
union V_32 V_34 ;
union V_32 V_35 ;
int V_36 ;
union V_37 V_38 ;
int V_39 ;
struct V_7 * V_8 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
V_36 = 0 ;
V_39 = 0 ;
F_23 (pos, &bp->address_list) {
V_39 += sizeof( union V_37 ) ;
}
if ( V_39 == sizeof( union V_37 ) ) {
V_35 . V_44 = NULL ;
goto V_45;
}
V_35 . V_44 = F_24 ( V_39 , V_5 ) ;
if ( ! V_35 . V_44 )
goto V_45;
V_34 = V_35 ;
F_2 (addr, &bp->address_list, list) {
V_43 = F_25 ( V_8 -> V_10 . V_25 . V_46 ) ;
V_39 = V_43 -> V_47 ( & V_8 -> V_10 , & V_38 ) ;
memcpy ( V_34 . V_44 , & V_38 , V_39 ) ;
V_34 . V_44 += V_39 ;
V_36 += V_39 ;
}
V_45:
* V_33 = V_36 ;
return V_35 ;
}
int F_26 ( struct V_1 * V_15 , T_4 * V_48 ,
int V_33 , T_3 V_9 , T_2 V_5 )
{
union V_37 * V_38 ;
struct V_49 * V_50 ;
union V_21 V_8 ;
int V_35 = 0 ;
int V_39 ;
struct V_42 * V_43 ;
while ( V_33 ) {
V_50 = (struct V_49 * ) V_48 ;
V_38 = (union V_37 * ) V_48 ;
V_43 = F_25 ( F_27 ( V_50 -> type ) ) ;
if ( F_28 ( ! V_43 ) ) {
V_35 = - V_31 ;
F_5 ( V_15 ) ;
break;
}
V_43 -> V_51 ( & V_8 , V_38 , F_17 ( V_9 ) , 0 ) ;
V_35 = F_7 ( V_15 , & V_8 , V_52 , V_5 ) ;
if ( V_35 ) {
F_5 ( V_15 ) ;
break;
}
V_39 = F_29 ( V_50 -> V_53 ) ;
V_33 -= V_39 ;
V_48 += V_39 ;
}
return V_35 ;
}
int F_30 ( struct V_1 * V_15 ,
const union V_21 * V_8 ,
struct V_54 * V_55 )
{
struct V_7 * V_56 ;
int V_57 = 0 ;
F_31 () ;
F_32 (laddr, &bp->address_list, list) {
if ( ! V_56 -> V_28 )
continue;
if ( V_55 -> V_58 -> V_59 ( & V_56 -> V_10 , V_8 , V_55 ) ) {
V_57 = 1 ;
break;
}
}
F_33 () ;
return V_57 ;
}
int F_34 ( struct V_1 * V_15 ,
const union V_21 * V_8 ,
struct V_54 * V_60 ,
struct V_54 * V_61 )
{
struct V_7 * V_56 ;
int V_62 = 0 ;
struct V_54 * V_63 ;
if ( F_35 ( V_60 ) -> V_64 == V_65 )
V_63 = V_60 ;
else if ( F_35 ( V_61 ) -> V_64 == V_65 )
V_63 = V_61 ;
else
V_63 = V_60 ;
F_31 () ;
F_32 (laddr, &bp->address_list, list) {
if ( ! V_56 -> V_28 )
continue;
V_62 = V_63 -> V_58 -> V_59 ( & V_56 -> V_10 , V_8 , V_63 ) ;
if ( V_62 )
break;
}
F_33 () ;
return V_62 ;
}
int F_36 ( const struct V_1 * V_15 ,
const union V_21 * V_8 )
{
struct V_7 * V_56 ;
struct V_42 * V_43 ;
int V_27 = - 1 ;
V_43 = F_25 ( V_8 -> V_66 . V_67 ) ;
if ( F_28 ( ! V_43 ) )
return V_27 ;
F_31 () ;
F_32 (laddr, &bp->address_list, list) {
if ( ! V_56 -> V_28 )
continue;
if ( V_43 -> V_59 ( & V_56 -> V_10 , V_8 ) ) {
V_27 = V_56 -> V_27 ;
break;
}
}
F_33 () ;
return V_27 ;
}
union V_21 * F_37 ( struct V_1 * V_15 ,
const union V_21 * V_68 ,
int V_69 ,
struct V_54 * V_55 )
{
struct V_7 * V_56 ;
union V_21 * V_8 ;
void * V_70 ;
struct V_42 * V_43 ;
int V_71 ;
F_2 (laddr, &bp->address_list, list) {
V_70 = (union V_21 * ) V_68 ;
for ( V_71 = 0 ; V_71 < V_69 ; V_71 ++ ) {
V_8 = (union V_21 * ) V_70 ;
V_43 = F_25 ( V_8 -> V_25 . V_46 ) ;
if ( ! V_43 )
break;
if ( V_55 -> V_58 -> V_59 ( & V_56 -> V_10 , V_8 , V_55 ) )
break;
V_70 += V_43 -> V_72 ;
}
if ( V_71 == V_69 )
return & V_56 -> V_10 ;
}
return NULL ;
}
static int F_3 ( struct V_1 * V_2 ,
union V_21 * V_8 ,
T_1 V_4 , T_2 V_5 ,
int V_6 )
{
int error = 0 ;
if ( F_38 ( NULL , V_8 ) ) {
error = F_39 ( V_2 , V_4 , V_5 , V_6 ) ;
} else if ( F_40 ( V_8 , V_4 ) ) {
if ( ( ( ( V_73 == V_8 -> V_66 . V_67 ) &&
( V_6 & V_74 ) ) ) ||
( ( ( V_65 == V_8 -> V_66 . V_67 ) &&
( V_6 & V_75 ) &&
( V_6 & V_76 ) ) ) )
error = F_7 ( V_2 , V_8 , V_52 ,
V_5 ) ;
}
return error ;
}
int F_38 ( struct V_77 * V_78 , const union V_21 * V_8 )
{
unsigned short V_79 = 0 ;
struct V_42 * V_43 ;
if ( V_8 -> V_66 . V_67 != V_80 )
V_79 = V_8 -> V_66 . V_67 ;
else if ( V_78 )
V_79 = V_78 -> V_64 ;
V_43 = F_25 ( V_79 ) ;
if ( ! V_43 )
return 0 ;
return V_43 -> V_81 ( V_8 ) ;
}
int F_40 ( const union V_21 * V_8 , T_1 V_4 )
{
T_1 V_82 = F_41 ( V_8 ) ;
if ( V_83 == V_82 )
return 0 ;
switch ( V_84 ) {
case V_85 :
return 1 ;
case V_86 :
if ( V_82 <= V_4 )
return 1 ;
break;
case V_87 :
if ( V_82 <= V_4 || V_88 == V_82 )
return 1 ;
break;
case V_89 :
if ( V_82 <= V_4 || V_14 == V_82 )
return 1 ;
break;
default:
break;
}
return 0 ;
}
T_1 F_41 ( const union V_21 * V_8 )
{
struct V_42 * V_43 ;
V_43 = F_25 ( V_8 -> V_66 . V_67 ) ;
if ( ! V_43 )
return V_83 ;
return V_43 -> V_4 ( (union V_21 * ) V_8 ) ;
}
