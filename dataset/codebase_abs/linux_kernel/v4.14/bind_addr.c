int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
const struct V_2 * V_4 ,
enum V_5 V_6 , T_1 V_7 ,
int V_8 )
{
struct V_9 * V_10 ;
int error = 0 ;
V_3 -> V_11 = V_4 -> V_11 ;
F_2 (addr, &src->address_list, list) {
error = F_3 ( V_1 , V_3 , & V_10 -> V_12 , V_6 ,
V_7 , V_8 ) ;
if ( error < 0 )
goto V_13;
}
if ( F_4 ( & V_3 -> V_14 ) && ( V_15 == V_6 ) ) {
F_2 (addr, &src->address_list, list) {
error = F_3 ( V_1 , V_3 , & V_10 -> V_12 ,
V_16 , V_7 ,
V_8 ) ;
if ( error < 0 )
goto V_13;
}
}
V_13:
if ( error )
F_5 ( V_3 ) ;
return error ;
}
int F_6 ( struct V_2 * V_3 ,
const struct V_2 * V_4 ,
T_1 V_7 )
{
struct V_9 * V_10 ;
int error = 0 ;
V_3 -> V_11 = V_4 -> V_11 ;
F_2 (addr, &src->address_list, list) {
error = F_7 ( V_3 , & V_10 -> V_12 , sizeof( V_10 -> V_12 ) ,
1 , V_7 ) ;
if ( error < 0 )
break;
}
return error ;
}
void F_8 ( struct V_2 * V_17 , T_2 V_11 )
{
F_9 ( & V_17 -> V_14 ) ;
V_17 -> V_11 = V_11 ;
}
static void F_5 ( struct V_2 * V_17 )
{
struct V_9 * V_10 , * V_18 ;
F_10 (addr, temp, &bp->address_list, list) {
F_11 ( & V_10 -> V_19 ) ;
F_12 ( V_10 , V_20 ) ;
F_13 ( V_10 ) ;
}
}
void F_14 ( struct V_2 * V_17 )
{
F_5 ( V_17 ) ;
}
int F_7 ( struct V_2 * V_17 , union V_21 * V_22 ,
int V_23 , T_3 V_24 , T_1 V_7 )
{
struct V_9 * V_10 ;
V_10 = F_15 ( sizeof( * V_10 ) , V_7 ) ;
if ( ! V_10 )
return - V_25 ;
memcpy ( & V_10 -> V_12 , V_22 , F_16 ( V_26 , sizeof( * V_22 ) , V_23 ) ) ;
if ( ! V_10 -> V_12 . V_27 . V_28 )
V_10 -> V_12 . V_27 . V_28 = F_17 ( V_17 -> V_11 ) ;
V_10 -> V_29 = V_24 ;
V_10 -> V_30 = 1 ;
F_9 ( & V_10 -> V_19 ) ;
F_18 ( & V_10 -> V_19 , & V_17 -> V_14 ) ;
F_19 ( V_10 ) ;
return 0 ;
}
int F_20 ( struct V_2 * V_17 , union V_21 * V_31 )
{
struct V_9 * V_10 , * V_18 ;
int V_32 = 0 ;
F_10 (addr, temp, &bp->address_list, list) {
if ( F_21 ( & V_10 -> V_12 , V_31 ) ) {
V_32 = 1 ;
V_10 -> V_30 = 0 ;
F_11 ( & V_10 -> V_19 ) ;
break;
}
}
if ( V_32 ) {
F_12 ( V_10 , V_20 ) ;
F_13 ( V_10 ) ;
return 0 ;
}
return - V_33 ;
}
union V_34 F_22 ( const struct V_2 * V_17 ,
int * V_35 ,
T_1 V_7 )
{
union V_34 V_36 ;
union V_34 V_37 ;
int V_38 ;
union V_39 V_40 ;
int V_41 ;
struct V_9 * V_10 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
V_38 = 0 ;
V_41 = 0 ;
F_23 (pos, &bp->address_list) {
V_41 += sizeof( union V_39 ) ;
}
if ( V_41 == sizeof( union V_39 ) ) {
V_37 . V_46 = NULL ;
goto V_47;
}
V_37 . V_46 = F_24 ( V_41 , V_7 ) ;
if ( ! V_37 . V_46 )
goto V_47;
V_36 = V_37 ;
F_2 (addr, &bp->address_list, list) {
V_45 = F_25 ( V_10 -> V_12 . V_27 . V_48 ) ;
V_41 = V_45 -> V_49 ( & V_10 -> V_12 , & V_40 ) ;
memcpy ( V_36 . V_46 , & V_40 , V_41 ) ;
V_36 . V_46 += V_41 ;
V_38 += V_41 ;
}
V_47:
* V_35 = V_38 ;
return V_37 ;
}
int F_26 ( struct V_2 * V_17 , T_3 * V_50 ,
int V_35 , T_2 V_11 , T_1 V_7 )
{
union V_39 * V_40 ;
struct V_51 * V_52 ;
union V_21 V_10 ;
int V_37 = 0 ;
int V_41 ;
struct V_44 * V_45 ;
while ( V_35 ) {
V_52 = (struct V_51 * ) V_50 ;
V_40 = (union V_39 * ) V_50 ;
V_45 = F_25 ( F_27 ( V_52 -> type ) ) ;
if ( F_28 ( ! V_45 ) ) {
V_37 = - V_33 ;
F_5 ( V_17 ) ;
break;
}
V_45 -> V_53 ( & V_10 , V_40 , F_17 ( V_11 ) , 0 ) ;
if ( F_29 ( V_17 , & V_10 ) != - 1 )
goto V_54;
V_37 = F_7 ( V_17 , & V_10 , sizeof( V_10 ) ,
V_55 , V_7 ) ;
if ( V_37 ) {
F_5 ( V_17 ) ;
break;
}
V_54:
V_41 = F_30 ( V_52 -> V_56 ) ;
V_35 -= V_41 ;
V_50 += V_41 ;
}
return V_37 ;
}
int F_31 ( struct V_2 * V_17 ,
const union V_21 * V_10 ,
struct V_57 * V_58 )
{
struct V_9 * V_59 ;
int V_60 = 0 ;
F_32 () ;
F_33 (laddr, &bp->address_list, list) {
if ( ! V_59 -> V_30 )
continue;
if ( V_58 -> V_61 -> V_62 ( & V_59 -> V_12 , V_10 , V_58 ) ) {
V_60 = 1 ;
break;
}
}
F_34 () ;
return V_60 ;
}
int F_35 ( struct V_2 * V_17 ,
const union V_21 * V_10 ,
struct V_57 * V_63 ,
struct V_57 * V_64 )
{
struct V_9 * V_59 ;
int V_65 = 0 ;
struct V_57 * V_66 ;
if ( F_36 ( V_63 ) -> V_67 == V_68 )
V_66 = V_63 ;
else if ( F_36 ( V_64 ) -> V_67 == V_68 )
V_66 = V_64 ;
else
V_66 = V_63 ;
F_32 () ;
F_33 (laddr, &bp->address_list, list) {
if ( ! V_59 -> V_30 )
continue;
V_65 = V_66 -> V_61 -> V_62 ( & V_59 -> V_12 , V_10 , V_66 ) ;
if ( V_65 )
break;
}
F_34 () ;
return V_65 ;
}
int F_29 ( const struct V_2 * V_17 ,
const union V_21 * V_10 )
{
struct V_9 * V_59 ;
struct V_44 * V_45 ;
int V_29 = - 1 ;
V_45 = F_25 ( V_10 -> V_69 . V_70 ) ;
if ( F_28 ( ! V_45 ) )
return V_29 ;
F_32 () ;
F_33 (laddr, &bp->address_list, list) {
if ( ! V_59 -> V_30 )
continue;
if ( V_45 -> V_62 ( & V_59 -> V_12 , V_10 ) ) {
V_29 = V_59 -> V_29 ;
break;
}
}
F_34 () ;
return V_29 ;
}
union V_21 * F_37 ( struct V_2 * V_17 ,
const union V_21 * V_71 ,
int V_72 ,
struct V_57 * V_58 )
{
struct V_9 * V_59 ;
union V_21 * V_10 ;
void * V_73 ;
struct V_44 * V_45 ;
int V_74 ;
F_2 (laddr, &bp->address_list, list) {
V_73 = (union V_21 * ) V_71 ;
for ( V_74 = 0 ; V_74 < V_72 ; V_74 ++ ) {
V_10 = V_73 ;
V_45 = F_25 ( V_10 -> V_27 . V_48 ) ;
if ( ! V_45 )
break;
if ( V_58 -> V_61 -> V_62 ( & V_59 -> V_12 , V_10 , V_58 ) )
break;
V_73 += V_45 -> V_75 ;
}
if ( V_74 == V_72 )
return & V_59 -> V_12 ;
}
return NULL ;
}
static int F_3 ( struct V_1 * V_1 , struct V_2 * V_3 ,
union V_21 * V_10 , enum V_5 V_6 ,
T_1 V_7 , int V_8 )
{
int error = 0 ;
if ( F_38 ( NULL , V_10 ) ) {
error = F_39 ( V_1 , V_3 , V_6 , V_7 , V_8 ) ;
} else if ( F_40 ( V_1 , V_10 , V_6 ) ) {
if ( ( ( ( V_76 == V_10 -> V_69 . V_70 ) &&
( V_8 & V_77 ) ) ) ||
( ( ( V_68 == V_10 -> V_69 . V_70 ) &&
( V_8 & V_78 ) &&
( V_8 & V_79 ) ) ) )
error = F_7 ( V_3 , V_10 , sizeof( * V_10 ) ,
V_55 , V_7 ) ;
}
return error ;
}
int F_38 ( struct V_80 * V_81 , const union V_21 * V_10 )
{
unsigned short V_82 = 0 ;
struct V_44 * V_45 ;
if ( V_10 -> V_69 . V_70 != V_83 )
V_82 = V_10 -> V_69 . V_70 ;
else if ( V_81 )
V_82 = V_81 -> V_67 ;
V_45 = F_25 ( V_82 ) ;
if ( ! V_45 )
return 0 ;
return V_45 -> V_84 ( V_10 ) ;
}
int F_40 ( struct V_1 * V_1 , const union V_21 * V_10 ,
enum V_5 V_6 )
{
enum V_5 V_85 = V_5 ( V_10 ) ;
if ( V_86 == V_85 )
return 0 ;
switch ( V_1 -> V_87 . V_88 ) {
case V_89 :
return 1 ;
case V_90 :
if ( V_85 <= V_6 )
return 1 ;
break;
case V_91 :
if ( V_85 <= V_6 || V_92 == V_85 )
return 1 ;
break;
case V_93 :
if ( V_85 <= V_6 || V_16 == V_85 )
return 1 ;
break;
default:
break;
}
return 0 ;
}
int F_41 ( struct V_80 * V_81 )
{
struct V_2 * V_17 ;
struct V_9 * V_10 ;
V_17 = & F_42 ( V_81 ) -> V_94 -> V_95 . V_96 ;
if ( F_43 ( & V_17 -> V_14 ) ) {
V_10 = F_44 ( V_17 -> V_14 . V_54 ,
struct V_9 , V_19 ) ;
if ( F_38 ( V_81 , & V_10 -> V_12 ) )
return 1 ;
}
return 0 ;
}
enum V_5 V_5 ( const union V_21 * V_10 )
{
struct V_44 * V_45 ;
V_45 = F_25 ( V_10 -> V_69 . V_70 ) ;
if ( ! V_45 )
return V_86 ;
return V_45 -> V_6 ( (union V_21 * ) V_10 ) ;
}
