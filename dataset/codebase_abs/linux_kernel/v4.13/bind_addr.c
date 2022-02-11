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
error = F_7 ( V_3 , & V_9 -> V_11 , sizeof( V_9 -> V_11 ) ,
1 , V_6 ) ;
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
int V_22 , T_4 V_23 , T_2 V_6 )
{
struct V_8 * V_9 ;
V_9 = F_15 ( sizeof( * V_9 ) , V_6 ) ;
if ( ! V_9 )
return - V_24 ;
memcpy ( & V_9 -> V_11 , V_21 , F_16 ( V_25 , sizeof( * V_21 ) , V_22 ) ) ;
if ( ! V_9 -> V_11 . V_26 . V_27 )
V_9 -> V_11 . V_26 . V_27 = F_17 ( V_16 -> V_10 ) ;
V_9 -> V_28 = V_23 ;
V_9 -> V_29 = 1 ;
F_9 ( & V_9 -> V_18 ) ;
F_18 ( & V_9 -> V_18 , & V_16 -> V_13 ) ;
F_19 ( V_9 ) ;
return 0 ;
}
int F_20 ( struct V_2 * V_16 , union V_20 * V_30 )
{
struct V_8 * V_9 , * V_17 ;
int V_31 = 0 ;
F_10 (addr, temp, &bp->address_list, list) {
if ( F_21 ( & V_9 -> V_11 , V_30 ) ) {
V_31 = 1 ;
V_9 -> V_29 = 0 ;
F_11 ( & V_9 -> V_18 ) ;
break;
}
}
if ( V_31 ) {
F_12 ( V_9 , V_19 ) ;
F_13 ( V_9 ) ;
return 0 ;
}
return - V_32 ;
}
union V_33 F_22 ( const struct V_2 * V_16 ,
int * V_34 ,
T_2 V_6 )
{
union V_33 V_35 ;
union V_33 V_36 ;
int V_37 ;
union V_38 V_39 ;
int V_40 ;
struct V_8 * V_9 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
V_37 = 0 ;
V_40 = 0 ;
F_23 (pos, &bp->address_list) {
V_40 += sizeof( union V_38 ) ;
}
if ( V_40 == sizeof( union V_38 ) ) {
V_36 . V_45 = NULL ;
goto V_46;
}
V_36 . V_45 = F_24 ( V_40 , V_6 ) ;
if ( ! V_36 . V_45 )
goto V_46;
V_35 = V_36 ;
F_2 (addr, &bp->address_list, list) {
V_44 = F_25 ( V_9 -> V_11 . V_26 . V_47 ) ;
V_40 = V_44 -> V_48 ( & V_9 -> V_11 , & V_39 ) ;
memcpy ( V_35 . V_45 , & V_39 , V_40 ) ;
V_35 . V_45 += V_40 ;
V_37 += V_40 ;
}
V_46:
* V_34 = V_37 ;
return V_36 ;
}
int F_26 ( struct V_2 * V_16 , T_4 * V_49 ,
int V_34 , T_3 V_10 , T_2 V_6 )
{
union V_38 * V_39 ;
struct V_50 * V_51 ;
union V_20 V_9 ;
int V_36 = 0 ;
int V_40 ;
struct V_43 * V_44 ;
while ( V_34 ) {
V_51 = (struct V_50 * ) V_49 ;
V_39 = (union V_38 * ) V_49 ;
V_44 = F_25 ( F_27 ( V_51 -> type ) ) ;
if ( F_28 ( ! V_44 ) ) {
V_36 = - V_32 ;
F_5 ( V_16 ) ;
break;
}
V_44 -> V_52 ( & V_9 , V_39 , F_17 ( V_10 ) , 0 ) ;
if ( F_29 ( V_16 , & V_9 ) != - 1 )
goto V_53;
V_36 = F_7 ( V_16 , & V_9 , sizeof( V_9 ) ,
V_54 , V_6 ) ;
if ( V_36 ) {
F_5 ( V_16 ) ;
break;
}
V_53:
V_40 = F_30 ( V_51 -> V_55 ) ;
V_34 -= V_40 ;
V_49 += V_40 ;
}
return V_36 ;
}
int F_31 ( struct V_2 * V_16 ,
const union V_20 * V_9 ,
struct V_56 * V_57 )
{
struct V_8 * V_58 ;
int V_59 = 0 ;
F_32 () ;
F_33 (laddr, &bp->address_list, list) {
if ( ! V_58 -> V_29 )
continue;
if ( V_57 -> V_60 -> V_61 ( & V_58 -> V_11 , V_9 , V_57 ) ) {
V_59 = 1 ;
break;
}
}
F_34 () ;
return V_59 ;
}
int F_35 ( struct V_2 * V_16 ,
const union V_20 * V_9 ,
struct V_56 * V_62 ,
struct V_56 * V_63 )
{
struct V_8 * V_58 ;
int V_64 = 0 ;
struct V_56 * V_65 ;
if ( F_36 ( V_62 ) -> V_66 == V_67 )
V_65 = V_62 ;
else if ( F_36 ( V_63 ) -> V_66 == V_67 )
V_65 = V_63 ;
else
V_65 = V_62 ;
F_32 () ;
F_33 (laddr, &bp->address_list, list) {
if ( ! V_58 -> V_29 )
continue;
V_64 = V_65 -> V_60 -> V_61 ( & V_58 -> V_11 , V_9 , V_65 ) ;
if ( V_64 )
break;
}
F_34 () ;
return V_64 ;
}
int F_29 ( const struct V_2 * V_16 ,
const union V_20 * V_9 )
{
struct V_8 * V_58 ;
struct V_43 * V_44 ;
int V_28 = - 1 ;
V_44 = F_25 ( V_9 -> V_68 . V_69 ) ;
if ( F_28 ( ! V_44 ) )
return V_28 ;
F_32 () ;
F_33 (laddr, &bp->address_list, list) {
if ( ! V_58 -> V_29 )
continue;
if ( V_44 -> V_61 ( & V_58 -> V_11 , V_9 ) ) {
V_28 = V_58 -> V_28 ;
break;
}
}
F_34 () ;
return V_28 ;
}
union V_20 * F_37 ( struct V_2 * V_16 ,
const union V_20 * V_70 ,
int V_71 ,
struct V_56 * V_57 )
{
struct V_8 * V_58 ;
union V_20 * V_9 ;
void * V_72 ;
struct V_43 * V_44 ;
int V_73 ;
F_2 (laddr, &bp->address_list, list) {
V_72 = (union V_20 * ) V_70 ;
for ( V_73 = 0 ; V_73 < V_71 ; V_73 ++ ) {
V_9 = V_72 ;
V_44 = F_25 ( V_9 -> V_26 . V_47 ) ;
if ( ! V_44 )
break;
if ( V_57 -> V_60 -> V_61 ( & V_58 -> V_11 , V_9 , V_57 ) )
break;
V_72 += V_44 -> V_74 ;
}
if ( V_73 == V_71 )
return & V_58 -> V_11 ;
}
return NULL ;
}
static int F_3 ( struct V_1 * V_1 , struct V_2 * V_3 ,
union V_20 * V_9 ,
T_1 V_5 , T_2 V_6 ,
int V_7 )
{
int error = 0 ;
if ( F_38 ( NULL , V_9 ) ) {
error = F_39 ( V_1 , V_3 , V_5 , V_6 , V_7 ) ;
} else if ( F_40 ( V_1 , V_9 , V_5 ) ) {
if ( ( ( ( V_75 == V_9 -> V_68 . V_69 ) &&
( V_7 & V_76 ) ) ) ||
( ( ( V_67 == V_9 -> V_68 . V_69 ) &&
( V_7 & V_77 ) &&
( V_7 & V_78 ) ) ) )
error = F_7 ( V_3 , V_9 , sizeof( * V_9 ) ,
V_54 , V_6 ) ;
}
return error ;
}
int F_38 ( struct V_79 * V_80 , const union V_20 * V_9 )
{
unsigned short V_81 = 0 ;
struct V_43 * V_44 ;
if ( V_9 -> V_68 . V_69 != V_82 )
V_81 = V_9 -> V_68 . V_69 ;
else if ( V_80 )
V_81 = V_80 -> V_66 ;
V_44 = F_25 ( V_81 ) ;
if ( ! V_44 )
return 0 ;
return V_44 -> V_83 ( V_9 ) ;
}
int F_40 ( struct V_1 * V_1 , const union V_20 * V_9 , T_1 V_5 )
{
T_1 V_84 = F_41 ( V_9 ) ;
if ( V_85 == V_84 )
return 0 ;
switch ( V_1 -> V_86 . V_87 ) {
case V_88 :
return 1 ;
case V_89 :
if ( V_84 <= V_5 )
return 1 ;
break;
case V_90 :
if ( V_84 <= V_5 || V_91 == V_84 )
return 1 ;
break;
case V_92 :
if ( V_84 <= V_5 || V_15 == V_84 )
return 1 ;
break;
default:
break;
}
return 0 ;
}
int F_42 ( struct V_79 * V_80 )
{
struct V_2 * V_16 ;
struct V_8 * V_9 ;
V_16 = & F_43 ( V_80 ) -> V_93 -> V_94 . V_95 ;
if ( F_44 ( & V_16 -> V_13 ) ) {
V_9 = F_45 ( V_16 -> V_13 . V_53 ,
struct V_8 , V_18 ) ;
if ( F_38 ( V_80 , & V_9 -> V_11 ) )
return 1 ;
}
return 0 ;
}
T_1 F_41 ( const union V_20 * V_9 )
{
struct V_43 * V_44 ;
V_44 = F_25 ( V_9 -> V_68 . V_69 ) ;
if ( ! V_44 )
return V_85 ;
return V_44 -> V_5 ( (union V_20 * ) V_9 ) ;
}
