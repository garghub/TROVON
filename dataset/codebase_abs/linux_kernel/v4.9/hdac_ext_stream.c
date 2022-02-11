void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 , int V_6 , int V_7 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
if ( V_9 -> V_10 ) {
V_4 -> V_11 = V_9 -> V_10 + V_12 +
V_13 * V_5 ;
V_4 -> V_14 = V_9 -> V_10 + V_15 +
V_16 * V_2 -> V_17 +
V_18 * V_5 ;
}
if ( V_9 -> V_19 ) {
V_4 -> V_20 = V_9 -> V_19 + V_21 +
V_22 * V_5 +
V_23 ;
V_4 -> V_24 = V_9 -> V_19 + V_21 +
V_22 * V_5 +
V_25 ;
}
if ( V_9 -> V_26 )
V_4 -> V_27 = V_9 -> V_26 + V_28 +
V_29 * V_5 ;
V_4 -> V_30 = false ;
F_2 ( V_9 , & V_4 -> V_31 , V_5 , V_6 , V_7 ) ;
}
int F_3 ( struct V_1 * V_2 , int V_32 ,
int V_33 , int V_34 )
{
int V_35 = 0 ;
int V_36 , V_7 , V_5 = V_32 ;
for ( V_36 = 0 ; V_36 < V_33 ; V_36 ++ ) {
struct V_3 * V_4 =
F_4 ( sizeof( * V_4 ) , V_37 ) ;
if ( ! V_4 )
return - V_38 ;
V_7 = ++ V_35 ;
F_1 ( V_2 , V_4 , V_5 , V_34 , V_7 ) ;
V_5 ++ ;
}
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_39 * V_40 , * V_41 ;
struct V_3 * V_4 ;
struct V_8 * V_9 = F_6 ( V_2 ) ;
F_7 (s, _s, &bus->stream_list, list) {
V_4 = F_8 ( V_40 ) ;
F_9 ( V_2 , V_4 , false ) ;
F_10 ( & V_40 -> V_42 ) ;
F_11 ( V_4 ) ;
}
}
void F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_43 )
{
struct V_39 * V_31 = & V_4 -> V_31 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
F_12 ( & V_9 -> V_44 ) ;
if ( V_43 )
F_13 ( V_9 -> V_10 , V_45 , 0 ,
F_14 ( V_31 -> V_46 ) ) ;
else
F_13 ( V_9 -> V_10 , V_45 ,
F_14 ( V_31 -> V_46 ) , 0 ) ;
V_4 -> V_30 = V_43 ;
F_15 ( & V_9 -> V_44 ) ;
}
void F_16 ( struct V_3 * V_4 )
{
F_13 ( V_4 -> V_14 , V_47 , 0 , V_48 ) ;
}
void F_17 ( struct V_3 * V_4 )
{
F_13 ( V_4 -> V_14 , V_47 , V_48 , 0 ) ;
}
void F_18 ( struct V_3 * V_4 )
{
unsigned char V_49 ;
int V_50 ;
F_17 ( V_4 ) ;
F_13 ( V_4 -> V_14 , V_47 , 0 , V_51 ) ;
F_19 ( 3 ) ;
V_50 = 50 ;
do {
V_49 = F_20 ( V_4 -> V_14 + V_47 ) &
V_51 ;
if ( V_49 )
break;
F_19 ( 3 ) ;
} while ( -- V_50 );
V_49 &= ~ V_51 ;
F_21 ( V_49 , V_4 -> V_14 + V_47 ) ;
F_19 ( 3 ) ;
V_50 = 50 ;
do {
V_49 = F_20 ( V_4 -> V_14 + V_47 ) & V_51 ;
if ( ! V_49 )
break;
F_19 ( 3 ) ;
} while ( -- V_50 );
}
int F_22 ( struct V_3 * V_4 , int V_52 )
{
struct V_39 * V_31 = & V_4 -> V_31 ;
unsigned int V_49 ;
F_17 ( V_4 ) ;
V_49 = F_20 ( V_4 -> V_14 + V_47 ) ;
V_49 = ( V_49 & ~ V_53 ) |
( V_31 -> V_35 << V_54 ) ;
F_21 ( V_49 , V_4 -> V_14 + V_47 ) ;
F_23 ( V_52 , V_4 -> V_14 + V_55 ) ;
return 0 ;
}
void F_24 ( struct V_56 * V_57 ,
int V_4 )
{
F_25 ( V_57 -> V_58 , V_59 , ( 1 << V_4 ) , 1 << V_4 ) ;
}
void F_26 ( struct V_56 * V_57 ,
int V_4 )
{
F_25 ( V_57 -> V_58 , V_59 , 0 , ( 1 << V_4 ) ) ;
}
static struct V_3 *
F_27 ( struct V_1 * V_2 ,
struct V_60 * V_61 )
{
struct V_3 * V_62 = NULL ;
struct V_39 * V_4 = NULL ;
struct V_8 * V_63 = & V_2 -> V_9 ;
if ( ! V_63 -> V_10 ) {
F_28 ( V_63 -> V_64 , L_1 ) ;
return NULL ;
}
F_29 (stream, &hbus->stream_list, list) {
struct V_3 * V_31 = F_30 ( V_4 ,
struct V_3 ,
V_31 ) ;
if ( V_4 -> V_6 != V_61 -> V_4 )
continue;
if ( V_31 -> V_30 && ! V_31 -> V_65 ) {
V_62 = V_31 ;
break;
}
if ( ! V_31 -> V_65 ) {
F_9 ( V_2 , V_31 , true ) ;
V_62 = V_31 ;
break;
}
}
if ( V_62 ) {
F_12 ( & V_63 -> V_44 ) ;
V_62 -> V_65 = 1 ;
V_62 -> V_66 = V_61 ;
F_15 ( & V_63 -> V_44 ) ;
}
return V_62 ;
}
static struct V_3 *
F_31 ( struct V_1 * V_2 ,
struct V_60 * V_61 )
{
struct V_3 * V_62 = NULL ;
struct V_39 * V_4 = NULL ;
struct V_8 * V_63 = & V_2 -> V_9 ;
if ( ! V_63 -> V_10 ) {
F_28 ( V_63 -> V_64 , L_1 ) ;
return NULL ;
}
F_29 (stream, &hbus->stream_list, list) {
struct V_3 * V_31 = F_30 ( V_4 ,
struct V_3 ,
V_31 ) ;
if ( V_4 -> V_6 != V_61 -> V_4 )
continue;
if ( ! V_4 -> V_67 ) {
if ( ! V_31 -> V_30 )
F_9 ( V_2 , V_31 , true ) ;
V_62 = V_31 ;
break;
}
}
if ( V_62 ) {
F_12 ( & V_63 -> V_44 ) ;
V_62 -> V_31 . V_67 = 1 ;
V_62 -> V_31 . V_68 = 0 ;
V_62 -> V_31 . V_61 = V_61 ;
F_15 ( & V_63 -> V_44 ) ;
}
return V_62 ;
}
struct V_3 * F_32 ( struct V_1 * V_2 ,
struct V_60 * V_61 ,
int type )
{
struct V_3 * V_31 = NULL ;
struct V_39 * V_4 = NULL ;
struct V_8 * V_63 = & V_2 -> V_9 ;
switch ( type ) {
case V_69 :
V_4 = F_33 ( V_63 , V_61 ) ;
if ( V_4 )
V_31 = F_30 ( V_4 ,
struct V_3 , V_31 ) ;
return V_31 ;
case V_70 :
return F_31 ( V_2 , V_61 ) ;
case V_71 :
return F_27 ( V_2 , V_61 ) ;
default:
return NULL ;
}
}
void F_34 ( struct V_3 * V_4 , int type )
{
struct V_8 * V_9 = V_4 -> V_31 . V_9 ;
struct V_1 * V_2 = F_35 ( V_9 ) ;
switch ( type ) {
case V_69 :
F_36 ( & V_4 -> V_31 ) ;
break;
case V_70 :
if ( V_4 -> V_30 && ! V_4 -> V_65 )
F_9 ( V_2 , V_4 , false ) ;
F_36 ( & V_4 -> V_31 ) ;
break;
case V_71 :
if ( V_4 -> V_30 && ! V_4 -> V_31 . V_67 )
F_9 ( V_2 , V_4 , false ) ;
F_12 ( & V_9 -> V_44 ) ;
V_4 -> V_65 = 0 ;
V_4 -> V_66 = NULL ;
F_15 ( & V_9 -> V_44 ) ;
break;
default:
F_37 ( V_9 -> V_64 , L_2 , type ) ;
}
}
void F_38 ( struct V_1 * V_2 ,
bool V_72 , int V_46 )
{
T_1 V_73 = 0 ;
T_1 V_74 = 0 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
if ( ! V_9 -> V_19 ) {
F_28 ( V_9 -> V_64 , L_3 ) ;
return;
}
V_73 |= ( 1 << V_46 ) ;
V_74 = F_20 ( V_9 -> V_19 + V_75 ) ;
V_73 |= V_74 ;
if ( V_72 )
F_13 ( V_9 -> V_19 , V_75 , 0 , V_73 ) ;
else
F_13 ( V_9 -> V_19 , V_75 , V_73 , 0 ) ;
}
int F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_76 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
if ( ! V_9 -> V_19 ) {
F_28 ( V_9 -> V_64 , L_3 ) ;
return - V_77 ;
}
F_21 ( V_76 , V_4 -> V_20 ) ;
return 0 ;
}
int F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
if ( ! V_9 -> V_19 ) {
F_28 ( V_9 -> V_64 , L_3 ) ;
return - V_77 ;
}
return F_20 ( V_4 -> V_24 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
struct V_39 * V_4 ;
if ( V_9 -> V_78 ) {
F_29 (stream, &bus->stream_list, list)
F_42 ( V_4 ) ;
F_43 ( V_9 ) ;
}
}
void F_44 ( struct V_1 * V_2 ,
bool V_72 , int V_46 )
{
T_1 V_73 = 0 ;
T_1 V_74 = 0 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
if ( ! V_9 -> V_26 ) {
F_28 ( V_9 -> V_64 , L_4 ) ;
return;
}
V_73 |= ( 1 << V_46 ) ;
V_74 = F_20 ( V_9 -> V_26 + V_75 ) ;
V_73 |= V_74 ;
if ( V_72 )
F_13 ( V_9 -> V_26 , V_79 , 0 , V_73 ) ;
else
F_13 ( V_9 -> V_26 , V_79 , V_73 , 0 ) ;
}
int F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_76 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
if ( ! V_9 -> V_26 ) {
F_28 ( V_9 -> V_64 , L_4 ) ;
return - V_77 ;
}
F_21 ( V_76 , V_4 -> V_27 ) ;
return 0 ;
}
int F_46 ( struct V_3 * V_4 , T_1 V_76 )
{
F_47 ( & V_4 -> V_31 , V_80 , V_76 ) ;
return 0 ;
}
