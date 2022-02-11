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
T_1 V_44 ;
int V_45 = F_12 ( V_31 -> V_46 ) ;
F_13 ( & V_9 -> V_47 ) ;
V_44 = F_14 ( V_9 -> V_10 + V_48 ) & V_45 ;
if ( V_43 && ! V_44 )
F_15 ( V_9 -> V_10 , V_48 , V_45 , V_45 ) ;
else if ( ! V_43 && V_44 )
F_15 ( V_9 -> V_10 , V_48 , V_45 , 0 ) ;
V_4 -> V_30 = V_43 ;
F_16 ( & V_9 -> V_47 ) ;
}
void F_17 ( struct V_3 * V_4 )
{
F_15 ( V_4 -> V_14 , V_49 , 0 , V_50 ) ;
}
void F_18 ( struct V_3 * V_4 )
{
F_15 ( V_4 -> V_14 , V_49 , V_50 , 0 ) ;
}
void F_19 ( struct V_3 * V_4 )
{
unsigned char V_44 ;
int V_51 ;
F_18 ( V_4 ) ;
F_15 ( V_4 -> V_14 , V_49 , 0 , V_52 ) ;
F_20 ( 3 ) ;
V_51 = 50 ;
do {
V_44 = F_21 ( V_4 -> V_14 + V_49 ) &
V_52 ;
if ( V_44 )
break;
F_20 ( 3 ) ;
} while ( -- V_51 );
V_44 &= ~ V_52 ;
F_22 ( V_44 , V_4 -> V_14 + V_49 ) ;
F_20 ( 3 ) ;
V_51 = 50 ;
do {
V_44 = F_21 ( V_4 -> V_14 + V_49 ) & V_52 ;
if ( ! V_44 )
break;
F_20 ( 3 ) ;
} while ( -- V_51 );
}
int F_23 ( struct V_3 * V_4 , int V_53 )
{
struct V_39 * V_31 = & V_4 -> V_31 ;
unsigned int V_44 ;
F_18 ( V_4 ) ;
V_44 = F_21 ( V_4 -> V_14 + V_49 ) ;
V_44 = ( V_44 & ~ V_54 ) |
( V_31 -> V_35 << V_55 ) ;
F_22 ( V_44 , V_4 -> V_14 + V_49 ) ;
F_24 ( V_53 , V_4 -> V_14 + V_56 ) ;
return 0 ;
}
void F_25 ( struct V_57 * V_58 ,
int V_4 )
{
F_26 ( V_58 -> V_59 , V_60 , ( 1 << V_4 ) , 1 << V_4 ) ;
}
void F_27 ( struct V_57 * V_58 ,
int V_4 )
{
F_26 ( V_58 -> V_59 , V_60 , 0 , ( 1 << V_4 ) ) ;
}
static struct V_3 *
F_28 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_3 * V_63 = NULL ;
struct V_39 * V_4 = NULL ;
struct V_8 * V_64 = & V_2 -> V_9 ;
if ( ! V_64 -> V_10 ) {
F_29 ( V_64 -> V_65 , L_1 ) ;
return NULL ;
}
F_30 (stream, &hbus->stream_list, list) {
struct V_3 * V_31 = F_31 ( V_4 ,
struct V_3 ,
V_31 ) ;
if ( V_4 -> V_6 != V_62 -> V_4 )
continue;
if ( V_31 -> V_30 && ! V_31 -> V_66 ) {
V_63 = V_31 ;
break;
}
if ( ! V_31 -> V_66 ) {
F_9 ( V_2 , V_31 , true ) ;
V_63 = V_31 ;
break;
}
}
if ( V_63 ) {
F_13 ( & V_64 -> V_47 ) ;
V_63 -> V_66 = 1 ;
V_63 -> V_67 = V_62 ;
F_16 ( & V_64 -> V_47 ) ;
}
return V_63 ;
}
static struct V_3 *
F_32 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_3 * V_63 = NULL ;
struct V_39 * V_4 = NULL ;
struct V_8 * V_64 = & V_2 -> V_9 ;
if ( ! V_64 -> V_10 ) {
F_29 ( V_64 -> V_65 , L_1 ) ;
return NULL ;
}
F_30 (stream, &hbus->stream_list, list) {
struct V_3 * V_31 = F_31 ( V_4 ,
struct V_3 ,
V_31 ) ;
if ( V_4 -> V_6 != V_62 -> V_4 )
continue;
if ( ! V_4 -> V_68 ) {
if ( ! V_31 -> V_30 )
F_9 ( V_2 , V_31 , true ) ;
V_63 = V_31 ;
break;
}
}
if ( V_63 ) {
F_13 ( & V_64 -> V_47 ) ;
V_63 -> V_31 . V_68 = 1 ;
V_63 -> V_31 . V_69 = 0 ;
V_63 -> V_31 . V_62 = V_62 ;
F_16 ( & V_64 -> V_47 ) ;
}
return V_63 ;
}
struct V_3 * F_33 ( struct V_1 * V_2 ,
struct V_61 * V_62 ,
int type )
{
struct V_3 * V_31 = NULL ;
struct V_39 * V_4 = NULL ;
struct V_8 * V_64 = & V_2 -> V_9 ;
switch ( type ) {
case V_70 :
V_4 = F_34 ( V_64 , V_62 ) ;
if ( V_4 )
V_31 = F_31 ( V_4 ,
struct V_3 , V_31 ) ;
return V_31 ;
case V_71 :
return F_32 ( V_2 , V_62 ) ;
case V_72 :
return F_28 ( V_2 , V_62 ) ;
default:
return NULL ;
}
}
void F_35 ( struct V_3 * V_4 , int type )
{
struct V_8 * V_9 = V_4 -> V_31 . V_9 ;
struct V_1 * V_2 = F_36 ( V_9 ) ;
switch ( type ) {
case V_70 :
F_37 ( & V_4 -> V_31 ) ;
break;
case V_71 :
if ( V_4 -> V_30 && ! V_4 -> V_66 )
F_9 ( V_2 , V_4 , false ) ;
F_37 ( & V_4 -> V_31 ) ;
break;
case V_72 :
if ( V_4 -> V_30 && ! V_4 -> V_31 . V_68 )
F_9 ( V_2 , V_4 , false ) ;
F_13 ( & V_9 -> V_47 ) ;
V_4 -> V_66 = 0 ;
V_4 -> V_67 = NULL ;
F_16 ( & V_9 -> V_47 ) ;
break;
default:
F_38 ( V_9 -> V_65 , L_2 , type ) ;
}
}
void F_39 ( struct V_1 * V_2 ,
bool V_73 , int V_46 )
{
T_1 V_45 = 0 ;
T_1 V_74 = 0 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
if ( ! V_9 -> V_19 ) {
F_29 ( V_9 -> V_65 , L_3 ) ;
return;
}
V_45 |= ( 1 << V_46 ) ;
V_74 = F_21 ( V_9 -> V_19 + V_75 ) ;
V_45 |= V_74 ;
if ( V_73 )
F_15 ( V_9 -> V_19 , V_75 , 0 , V_45 ) ;
else
F_15 ( V_9 -> V_19 , V_75 , V_45 , 0 ) ;
}
int F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_76 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
if ( ! V_9 -> V_19 ) {
F_29 ( V_9 -> V_65 , L_3 ) ;
return - V_77 ;
}
F_22 ( V_76 , V_4 -> V_20 ) ;
return 0 ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
if ( ! V_9 -> V_19 ) {
F_29 ( V_9 -> V_65 , L_3 ) ;
return - V_77 ;
}
return F_21 ( V_4 -> V_24 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
struct V_39 * V_4 ;
if ( V_9 -> V_78 ) {
F_30 (stream, &bus->stream_list, list)
F_43 ( V_4 ) ;
F_44 ( V_9 ) ;
}
}
void F_45 ( struct V_1 * V_2 ,
bool V_73 , int V_46 )
{
T_1 V_45 = 0 ;
T_1 V_74 = 0 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
if ( ! V_9 -> V_26 ) {
F_29 ( V_9 -> V_65 , L_4 ) ;
return;
}
V_45 |= ( 1 << V_46 ) ;
V_74 = F_21 ( V_9 -> V_26 + V_75 ) ;
V_45 |= V_74 ;
if ( V_73 )
F_15 ( V_9 -> V_26 , V_79 , 0 , V_45 ) ;
else
F_15 ( V_9 -> V_26 , V_79 , V_45 , 0 ) ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_76 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
if ( ! V_9 -> V_26 ) {
F_29 ( V_9 -> V_65 , L_4 ) ;
return - V_77 ;
}
F_22 ( V_76 , V_4 -> V_27 ) ;
return 0 ;
}
int F_47 ( struct V_3 * V_4 , T_1 V_76 )
{
F_48 ( & V_4 -> V_31 , V_80 , V_76 ) ;
return 0 ;
}
