void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 , int V_6 , int V_7 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
if ( V_2 -> V_10 ) {
V_4 -> V_11 = V_2 -> V_10 + V_12 +
V_13 * V_5 ;
V_4 -> V_14 = V_2 -> V_10 + V_15 +
V_16 * V_2 -> V_17 +
V_18 * V_5 ;
}
if ( V_2 -> V_19 ) {
V_4 -> V_20 = V_2 -> V_19 + V_21 +
V_22 * V_5 +
V_23 ;
V_4 -> V_24 = V_2 -> V_19 + V_21 +
V_22 * V_5 +
V_25 ;
}
V_4 -> V_26 = false ;
F_2 ( V_9 , & V_4 -> V_27 , V_5 , V_6 , V_7 ) ;
}
int F_3 ( struct V_1 * V_2 , int V_28 ,
int V_29 , int V_30 )
{
int V_31 = 0 ;
int V_32 , V_7 , V_5 = V_28 ;
for ( V_32 = 0 ; V_32 < V_29 ; V_32 ++ ) {
struct V_3 * V_4 =
F_4 ( sizeof( * V_4 ) , V_33 ) ;
if ( ! V_4 )
return - V_34 ;
V_7 = ++ V_31 ;
F_1 ( V_2 , V_4 , V_5 , V_30 , V_7 ) ;
V_5 ++ ;
}
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_35 * V_36 ;
struct V_3 * V_4 ;
struct V_8 * V_9 = F_6 ( V_2 ) ;
while ( ! F_7 ( & V_9 -> V_37 ) ) {
V_36 = F_8 ( & V_9 -> V_37 , struct V_35 , V_38 ) ;
V_4 = F_9 ( V_36 ) ;
F_10 ( & V_36 -> V_38 ) ;
F_11 ( V_4 ) ;
}
}
void F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_39 )
{
struct V_35 * V_27 = & V_4 -> V_27 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
F_13 ( & V_9 -> V_40 ) ;
if ( V_39 )
F_14 ( V_2 -> V_10 , V_41 , 0 ,
F_15 ( V_27 -> V_42 ) ) ;
else
F_14 ( V_2 -> V_10 , V_41 ,
F_15 ( V_27 -> V_42 ) , 0 ) ;
V_4 -> V_26 = V_39 ;
F_16 ( & V_9 -> V_40 ) ;
}
void F_17 ( struct V_3 * V_4 )
{
F_14 ( V_4 -> V_14 , V_43 , 0 , V_44 ) ;
}
void F_18 ( struct V_3 * V_4 )
{
F_14 ( V_4 -> V_14 , V_43 , V_44 , 0 ) ;
}
void F_19 ( struct V_3 * V_4 )
{
unsigned char V_45 ;
int V_46 ;
F_18 ( V_4 ) ;
F_14 ( V_4 -> V_14 , V_43 , 0 , V_47 ) ;
F_20 ( 3 ) ;
V_46 = 50 ;
do {
V_45 = F_21 ( V_4 -> V_14 + V_43 ) &
V_47 ;
if ( V_45 )
break;
F_20 ( 3 ) ;
} while ( -- V_46 );
V_45 &= ~ V_47 ;
F_22 ( V_45 , V_4 -> V_14 + V_43 ) ;
F_20 ( 3 ) ;
V_46 = 50 ;
do {
V_45 = F_21 ( V_4 -> V_14 + V_43 ) & V_47 ;
if ( ! V_45 )
break;
F_20 ( 3 ) ;
} while ( -- V_46 );
}
int F_23 ( struct V_3 * V_4 , int V_48 )
{
struct V_35 * V_27 = & V_4 -> V_27 ;
unsigned int V_45 ;
F_18 ( V_4 ) ;
V_45 = F_21 ( V_4 -> V_14 + V_43 ) ;
V_45 = ( V_45 & ~ V_49 ) |
( V_27 -> V_31 << V_50 ) ;
F_22 ( V_45 , V_4 -> V_14 + V_43 ) ;
F_24 ( V_48 , V_4 -> V_14 + V_51 ) ;
return 0 ;
}
void F_25 ( struct V_52 * V_53 ,
int V_4 )
{
F_26 ( V_53 -> V_54 , V_55 , ( 1 << V_4 ) , 0 ) ;
}
void F_27 ( struct V_52 * V_53 ,
int V_4 )
{
F_26 ( V_53 -> V_54 , V_55 , 0 , ( 1 << V_4 ) ) ;
}
static struct V_3 *
F_28 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
struct V_3 * V_58 = NULL ;
struct V_35 * V_4 = NULL ;
struct V_8 * V_59 = & V_2 -> V_9 ;
if ( ! V_2 -> V_10 ) {
F_29 ( V_59 -> V_60 , L_1 ) ;
return NULL ;
}
F_30 (stream, &hbus->stream_list, list) {
struct V_3 * V_27 = F_31 ( V_4 ,
struct V_3 ,
V_27 ) ;
if ( V_4 -> V_6 != V_57 -> V_4 )
continue;
if ( V_27 -> V_26 && ! V_27 -> V_61 ) {
V_58 = V_27 ;
break;
}
if ( ! V_27 -> V_61 ) {
F_12 ( V_2 , V_27 , true ) ;
V_58 = V_27 ;
break;
}
}
if ( V_58 ) {
F_13 ( & V_59 -> V_40 ) ;
V_58 -> V_61 = 1 ;
V_58 -> V_62 = V_57 ;
F_16 ( & V_59 -> V_40 ) ;
}
return V_58 ;
}
static struct V_3 *
F_32 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
struct V_3 * V_58 = NULL ;
struct V_35 * V_4 = NULL ;
struct V_8 * V_59 = & V_2 -> V_9 ;
if ( ! V_2 -> V_10 ) {
F_29 ( V_59 -> V_60 , L_1 ) ;
return NULL ;
}
F_30 (stream, &hbus->stream_list, list) {
struct V_3 * V_27 = F_31 ( V_4 ,
struct V_3 ,
V_27 ) ;
if ( V_4 -> V_6 != V_57 -> V_4 )
continue;
if ( ! V_4 -> V_63 ) {
if ( ! V_27 -> V_26 )
F_12 ( V_2 , V_27 , true ) ;
V_58 = V_27 ;
break;
}
}
if ( V_58 ) {
F_13 ( & V_59 -> V_40 ) ;
V_58 -> V_27 . V_63 = 1 ;
V_58 -> V_27 . V_64 = 0 ;
V_58 -> V_27 . V_57 = V_57 ;
F_16 ( & V_59 -> V_40 ) ;
}
return V_58 ;
}
struct V_3 * F_33 ( struct V_1 * V_2 ,
struct V_56 * V_57 ,
int type )
{
struct V_3 * V_27 = NULL ;
struct V_35 * V_4 = NULL ;
struct V_8 * V_59 = & V_2 -> V_9 ;
switch ( type ) {
case V_65 :
V_4 = F_34 ( V_59 , V_57 ) ;
if ( V_4 )
V_27 = F_31 ( V_4 ,
struct V_3 , V_27 ) ;
return V_27 ;
case V_66 :
return F_32 ( V_2 , V_57 ) ;
case V_67 :
return F_28 ( V_2 , V_57 ) ;
default:
return NULL ;
}
}
void F_35 ( struct V_3 * V_4 , int type )
{
struct V_8 * V_9 = V_4 -> V_27 . V_9 ;
struct V_1 * V_2 = F_36 ( V_9 ) ;
switch ( type ) {
case V_65 :
F_37 ( & V_4 -> V_27 ) ;
break;
case V_66 :
if ( V_4 -> V_26 ) {
F_12 ( V_2 , V_4 , false ) ;
F_37 ( & V_4 -> V_27 ) ;
}
break;
case V_67 :
if ( V_4 -> V_26 )
F_12 ( V_2 , V_4 , false ) ;
F_13 ( & V_9 -> V_40 ) ;
V_4 -> V_61 = 0 ;
V_4 -> V_62 = NULL ;
F_16 ( & V_9 -> V_40 ) ;
break;
default:
F_38 ( V_9 -> V_60 , L_2 , type ) ;
}
}
void F_39 ( struct V_1 * V_2 ,
bool V_68 , int V_42 )
{
T_1 V_69 = 0 ;
T_1 V_70 = 0 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
if ( ! V_2 -> V_19 ) {
F_29 ( V_9 -> V_60 , L_3 ) ;
return;
}
V_69 |= ( 1 << V_42 ) ;
V_70 = F_21 ( V_2 -> V_19 + V_71 ) ;
V_69 |= V_70 ;
if ( V_68 )
F_14 ( V_2 -> V_19 , V_71 , 0 , V_69 ) ;
else
F_14 ( V_2 -> V_19 , V_71 , V_69 , 0 ) ;
}
int F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_72 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
if ( ! V_2 -> V_19 ) {
F_29 ( V_9 -> V_60 , L_3 ) ;
return - V_73 ;
}
F_22 ( V_72 , V_4 -> V_20 ) ;
return 0 ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
if ( ! V_2 -> V_19 ) {
F_29 ( V_9 -> V_60 , L_3 ) ;
return - V_73 ;
}
return F_21 ( V_4 -> V_24 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
struct V_35 * V_4 ;
if ( V_9 -> V_74 ) {
F_30 (stream, &bus->stream_list, list)
F_43 ( V_4 ) ;
F_44 ( V_9 ) ;
}
}
