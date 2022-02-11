int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
const struct V_2 * V_4 ,
T_1 V_5 , T_2 V_6 ,
int V_7 )
{
struct V_8 * V_9 ;
int error = 0 ;
V_3 -> V_10 = V_4 -> V_10 ;
F_2 (addr, &src->address_list, list) {
error = F_3 ( V_1 , V_3 , & V_9 -> V_11 , V_5 ,
V_6 , V_7 ) ;
if ( error < 0 )
goto V_12;
}
if ( F_4 ( & V_3 -> V_13 ) && ( V_14 == V_5 ) ) {
F_2 (addr, &src->address_list, list) {
error = F_3 ( V_1 , V_3 , & V_9 -> V_11 ,
V_15 , V_6 ,
V_7 ) ;
if ( error < 0 )
goto V_12;
}
}
V_12:
if ( error )
F_5 ( V_3 ) ;
return error ;
}
int F_6 ( struct V_2 * V_3 ,
const struct V_2 * V_4 ,
T_2 V_6 )
{
struct V_8 * V_9 ;
int error = 0 ;
V_3 -> V_10 = V_4 -> V_10 ;
F_2 (addr, &src->address_list, list) {
error = F_7 ( V_3 , & V_9 -> V_11 , 1 , V_6 ) ;
if ( error < 0 )
break;
}
return error ;
}
void F_8 ( struct V_2 * V_16 , T_3 V_10 )
{
F_9 ( & V_16 -> V_13 ) ;
V_16 -> V_10 = V_10 ;
}
static void F_5 ( struct V_2 * V_16 )
{
struct V_8 * V_9 , * V_17 ;
F_10 (addr, temp, &bp->address_list, list) {
F_11 ( & V_9 -> V_18 ) ;
F_12 ( V_9 , V_19 ) ;
F_13 ( V_9 ) ;
}
}
void F_14 ( struct V_2 * V_16 )
{
F_5 ( V_16 ) ;
}
int F_7 ( struct V_2 * V_16 , union V_20 * V_21 ,
T_4 V_22 , T_2 V_6 )
{
struct V_8 * V_9 ;
V_9 = F_15 ( struct V_8 , V_6 ) ;
if ( ! V_9 )
return - V_23 ;
memcpy ( & V_9 -> V_11 , V_21 , sizeof( * V_21 ) ) ;
if ( ! V_9 -> V_11 . V_24 . V_25 )
V_9 -> V_11 . V_24 . V_25 = F_16 ( V_16 -> V_10 ) ;
V_9 -> V_26 = V_22 ;
V_9 -> V_27 = 1 ;
F_9 ( & V_9 -> V_18 ) ;
F_17 ( & V_9 -> V_18 , & V_16 -> V_13 ) ;
F_18 ( V_9 ) ;
return 0 ;
}
int F_19 ( struct V_2 * V_16 , union V_20 * V_28 )
{
struct V_8 * V_9 , * V_17 ;
int V_29 = 0 ;
F_10 (addr, temp, &bp->address_list, list) {
if ( F_20 ( & V_9 -> V_11 , V_28 ) ) {
V_29 = 1 ;
V_9 -> V_27 = 0 ;
F_11 ( & V_9 -> V_18 ) ;
break;
}
}
if ( V_29 ) {
F_12 ( V_9 , V_19 ) ;
F_13 ( V_9 ) ;
return 0 ;
}
return - V_30 ;
}
union V_31 F_21 ( const struct V_2 * V_16 ,
int * V_32 ,
T_2 V_6 )
{
union V_31 V_33 ;
union V_31 V_34 ;
int V_35 ;
union V_36 V_37 ;
int V_38 ;
struct V_8 * V_9 ;
struct V_39 * V_40 ;
struct V_41 * V_42 ;
V_35 = 0 ;
V_38 = 0 ;
F_22 (pos, &bp->address_list) {
V_38 += sizeof( union V_36 ) ;
}
if ( V_38 == sizeof( union V_36 ) ) {
V_34 . V_43 = NULL ;
goto V_44;
}
V_34 . V_43 = F_23 ( V_38 , V_6 ) ;
if ( ! V_34 . V_43 )
goto V_44;
V_33 = V_34 ;
F_2 (addr, &bp->address_list, list) {
V_42 = F_24 ( V_9 -> V_11 . V_24 . V_45 ) ;
V_38 = V_42 -> V_46 ( & V_9 -> V_11 , & V_37 ) ;
memcpy ( V_33 . V_43 , & V_37 , V_38 ) ;
V_33 . V_43 += V_38 ;
V_35 += V_38 ;
}
V_44:
* V_32 = V_35 ;
return V_34 ;
}
int F_25 ( struct V_2 * V_16 , T_4 * V_47 ,
int V_32 , T_3 V_10 , T_2 V_6 )
{
union V_36 * V_37 ;
struct V_48 * V_49 ;
union V_20 V_9 ;
int V_34 = 0 ;
int V_38 ;
struct V_41 * V_42 ;
while ( V_32 ) {
V_49 = (struct V_48 * ) V_47 ;
V_37 = (union V_36 * ) V_47 ;
V_42 = F_24 ( F_26 ( V_49 -> type ) ) ;
if ( F_27 ( ! V_42 ) ) {
V_34 = - V_30 ;
F_5 ( V_16 ) ;
break;
}
V_42 -> V_50 ( & V_9 , V_37 , F_16 ( V_10 ) , 0 ) ;
V_34 = F_7 ( V_16 , & V_9 , V_51 , V_6 ) ;
if ( V_34 ) {
F_5 ( V_16 ) ;
break;
}
V_38 = F_28 ( V_49 -> V_52 ) ;
V_32 -= V_38 ;
V_47 += V_38 ;
}
return V_34 ;
}
int F_29 ( struct V_2 * V_16 ,
const union V_20 * V_9 ,
struct V_53 * V_54 )
{
struct V_8 * V_55 ;
int V_56 = 0 ;
F_30 () ;
F_31 (laddr, &bp->address_list, list) {
if ( ! V_55 -> V_27 )
continue;
if ( V_54 -> V_57 -> V_58 ( & V_55 -> V_11 , V_9 , V_54 ) ) {
V_56 = 1 ;
break;
}
}
F_32 () ;
return V_56 ;
}
int F_33 ( struct V_2 * V_16 ,
const union V_20 * V_9 ,
struct V_53 * V_59 ,
struct V_53 * V_60 )
{
struct V_8 * V_55 ;
int V_61 = 0 ;
struct V_53 * V_62 ;
if ( F_34 ( V_59 ) -> V_63 == V_64 )
V_62 = V_59 ;
else if ( F_34 ( V_60 ) -> V_63 == V_64 )
V_62 = V_60 ;
else
V_62 = V_59 ;
F_30 () ;
F_31 (laddr, &bp->address_list, list) {
if ( ! V_55 -> V_27 )
continue;
V_61 = V_62 -> V_57 -> V_58 ( & V_55 -> V_11 , V_9 , V_62 ) ;
if ( V_61 )
break;
}
F_32 () ;
return V_61 ;
}
int F_35 ( const struct V_2 * V_16 ,
const union V_20 * V_9 )
{
struct V_8 * V_55 ;
struct V_41 * V_42 ;
int V_26 = - 1 ;
V_42 = F_24 ( V_9 -> V_65 . V_66 ) ;
if ( F_27 ( ! V_42 ) )
return V_26 ;
F_30 () ;
F_31 (laddr, &bp->address_list, list) {
if ( ! V_55 -> V_27 )
continue;
if ( V_42 -> V_58 ( & V_55 -> V_11 , V_9 ) ) {
V_26 = V_55 -> V_26 ;
break;
}
}
F_32 () ;
return V_26 ;
}
union V_20 * F_36 ( struct V_2 * V_16 ,
const union V_20 * V_67 ,
int V_68 ,
struct V_53 * V_54 )
{
struct V_8 * V_55 ;
union V_20 * V_9 ;
void * V_69 ;
struct V_41 * V_42 ;
int V_70 ;
F_2 (laddr, &bp->address_list, list) {
V_69 = (union V_20 * ) V_67 ;
for ( V_70 = 0 ; V_70 < V_68 ; V_70 ++ ) {
V_9 = V_69 ;
V_42 = F_24 ( V_9 -> V_24 . V_45 ) ;
if ( ! V_42 )
break;
if ( V_54 -> V_57 -> V_58 ( & V_55 -> V_11 , V_9 , V_54 ) )
break;
V_69 += V_42 -> V_71 ;
}
if ( V_70 == V_68 )
return & V_55 -> V_11 ;
}
return NULL ;
}
static int F_3 ( struct V_1 * V_1 , struct V_2 * V_3 ,
union V_20 * V_9 ,
T_1 V_5 , T_2 V_6 ,
int V_7 )
{
int error = 0 ;
if ( F_37 ( NULL , V_9 ) ) {
error = F_38 ( V_1 , V_3 , V_5 , V_6 , V_7 ) ;
} else if ( F_39 ( V_1 , V_9 , V_5 ) ) {
if ( ( ( ( V_72 == V_9 -> V_65 . V_66 ) &&
( V_7 & V_73 ) ) ) ||
( ( ( V_64 == V_9 -> V_65 . V_66 ) &&
( V_7 & V_74 ) &&
( V_7 & V_75 ) ) ) )
error = F_7 ( V_3 , V_9 , V_51 ,
V_6 ) ;
}
return error ;
}
int F_37 ( struct V_76 * V_77 , const union V_20 * V_9 )
{
unsigned short V_78 = 0 ;
struct V_41 * V_42 ;
if ( V_9 -> V_65 . V_66 != V_79 )
V_78 = V_9 -> V_65 . V_66 ;
else if ( V_77 )
V_78 = V_77 -> V_63 ;
V_42 = F_24 ( V_78 ) ;
if ( ! V_42 )
return 0 ;
return V_42 -> V_80 ( V_9 ) ;
}
int F_39 ( struct V_1 * V_1 , const union V_20 * V_9 , T_1 V_5 )
{
T_1 V_81 = F_40 ( V_9 ) ;
if ( V_82 == V_81 )
return 0 ;
switch ( V_1 -> V_83 . V_84 ) {
case V_85 :
return 1 ;
case V_86 :
if ( V_81 <= V_5 )
return 1 ;
break;
case V_87 :
if ( V_81 <= V_5 || V_88 == V_81 )
return 1 ;
break;
case V_89 :
if ( V_81 <= V_5 || V_15 == V_81 )
return 1 ;
break;
default:
break;
}
return 0 ;
}
int F_41 ( struct V_76 * V_77 )
{
struct V_2 * V_16 ;
struct V_8 * V_9 ;
V_16 = & F_42 ( V_77 ) -> V_90 -> V_91 . V_92 ;
if ( F_43 ( & V_16 -> V_13 ) ) {
V_9 = F_44 ( V_16 -> V_13 . V_93 ,
struct V_8 , V_18 ) ;
if ( F_37 ( V_77 , & V_9 -> V_11 ) )
return 1 ;
}
return 0 ;
}
T_1 F_40 ( const union V_20 * V_9 )
{
struct V_41 * V_42 ;
V_42 = F_24 ( V_9 -> V_65 . V_66 ) ;
if ( ! V_42 )
return V_82 ;
return V_42 -> V_5 ( (union V_20 * ) V_9 ) ;
}
