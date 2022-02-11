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
V_4 -> V_19 = false ;
F_2 ( V_9 , & V_4 -> V_20 , V_5 , V_6 , V_7 ) ;
}
int F_3 ( struct V_1 * V_2 , int V_21 ,
int V_22 , int V_23 )
{
int V_24 = 0 ;
int V_25 , V_7 , V_5 = V_21 ;
for ( V_25 = 0 ; V_25 < V_22 ; V_25 ++ ) {
struct V_3 * V_4 =
F_4 ( sizeof( * V_4 ) , V_26 ) ;
if ( ! V_4 )
return - V_27 ;
V_7 = ++ V_24 ;
F_1 ( V_2 , V_4 , V_5 , V_23 , V_7 ) ;
V_5 ++ ;
}
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_28 * V_29 ;
struct V_3 * V_4 ;
struct V_8 * V_9 = F_6 ( V_2 ) ;
while ( ! F_7 ( & V_9 -> V_30 ) ) {
V_29 = F_8 ( & V_9 -> V_30 , struct V_28 , V_31 ) ;
V_4 = F_9 ( V_29 ) ;
F_10 ( & V_29 -> V_31 ) ;
F_11 ( V_4 ) ;
}
}
void F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_32 )
{
struct V_28 * V_20 = & V_4 -> V_20 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
F_13 ( & V_9 -> V_33 ) ;
if ( V_32 )
F_14 ( V_2 -> V_10 , V_34 , 0 ,
F_15 ( V_20 -> V_35 ) ) ;
else
F_14 ( V_2 -> V_10 , V_34 ,
F_15 ( V_20 -> V_35 ) , 0 ) ;
V_4 -> V_19 = V_32 ;
F_16 ( & V_9 -> V_33 ) ;
}
void F_17 ( struct V_3 * V_4 )
{
F_14 ( V_4 -> V_14 , V_36 , 0 , V_37 ) ;
}
void F_18 ( struct V_3 * V_4 )
{
F_14 ( V_4 -> V_14 , V_36 , V_37 , 0 ) ;
}
void F_19 ( struct V_3 * V_4 )
{
unsigned char V_38 ;
int V_39 ;
F_18 ( V_4 ) ;
F_14 ( V_4 -> V_14 , V_36 , 0 , V_40 ) ;
F_20 ( 3 ) ;
V_39 = 50 ;
do {
V_38 = F_21 ( V_4 -> V_14 + V_36 ) &
V_40 ;
if ( V_38 )
break;
F_20 ( 3 ) ;
} while ( -- V_39 );
V_38 &= ~ V_40 ;
F_22 ( V_38 , V_4 -> V_14 + V_36 ) ;
F_20 ( 3 ) ;
V_39 = 50 ;
do {
V_38 = F_21 ( V_4 -> V_14 + V_36 ) & V_40 ;
if ( ! V_38 )
break;
F_20 ( 3 ) ;
} while ( -- V_39 );
}
int F_23 ( struct V_3 * V_4 , int V_41 )
{
struct V_28 * V_20 = & V_4 -> V_20 ;
unsigned int V_38 ;
F_18 ( V_4 ) ;
V_38 = F_21 ( V_4 -> V_14 + V_36 ) ;
V_38 = ( V_38 & ~ V_42 ) |
( V_20 -> V_24 << V_43 ) ;
F_22 ( V_38 , V_4 -> V_14 + V_36 ) ;
F_24 ( V_41 , V_4 -> V_14 + V_44 ) ;
return 0 ;
}
void F_25 ( struct V_45 * V_46 ,
int V_4 )
{
F_26 ( V_46 -> V_47 , V_48 , ( 1 << V_4 ) , 0 ) ;
}
void F_27 ( struct V_45 * V_46 ,
int V_4 )
{
F_26 ( V_46 -> V_47 , V_48 , 0 , ( 1 << V_4 ) ) ;
}
static struct V_3 *
F_28 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_3 * V_51 = NULL ;
struct V_28 * V_4 = NULL ;
struct V_8 * V_52 = & V_2 -> V_9 ;
if ( ! V_2 -> V_10 ) {
F_29 ( V_52 -> V_53 , L_1 ) ;
return NULL ;
}
F_30 (stream, &hbus->stream_list, list) {
struct V_3 * V_20 = F_31 ( V_4 ,
struct V_3 ,
V_20 ) ;
if ( V_4 -> V_6 != V_50 -> V_4 )
continue;
if ( V_20 -> V_19 && ! V_20 -> V_54 ) {
V_51 = V_20 ;
break;
}
if ( ! V_20 -> V_54 ) {
F_12 ( V_2 , V_20 , true ) ;
V_51 = V_20 ;
break;
}
}
if ( V_51 ) {
F_13 ( & V_52 -> V_33 ) ;
V_51 -> V_54 = 1 ;
V_51 -> V_55 = V_50 ;
F_16 ( & V_52 -> V_33 ) ;
}
return V_51 ;
}
static struct V_3 *
F_32 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_3 * V_51 = NULL ;
struct V_28 * V_4 = NULL ;
struct V_8 * V_52 = & V_2 -> V_9 ;
int V_56 ;
if ( ! V_2 -> V_10 ) {
F_29 ( V_52 -> V_53 , L_1 ) ;
return NULL ;
}
V_56 = ( V_50 -> V_57 -> V_58 << 16 ) | ( V_50 -> V_59 << 2 ) |
( V_50 -> V_4 + 1 ) ;
F_30 (stream, &hbus->stream_list, list) {
struct V_3 * V_20 = F_31 ( V_4 ,
struct V_3 ,
V_20 ) ;
if ( V_4 -> V_6 != V_50 -> V_4 )
continue;
if ( ! V_4 -> V_60 ) {
if ( ! V_20 -> V_19 )
F_12 ( V_2 , V_20 , true ) ;
V_51 = V_20 ;
break;
}
}
if ( V_51 ) {
F_13 ( & V_52 -> V_33 ) ;
V_51 -> V_20 . V_60 = 1 ;
V_51 -> V_20 . V_61 = 0 ;
V_51 -> V_20 . V_62 = V_56 ;
V_51 -> V_20 . V_50 = V_50 ;
F_16 ( & V_52 -> V_33 ) ;
}
return V_51 ;
}
struct V_3 * F_33 ( struct V_1 * V_2 ,
struct V_49 * V_50 ,
int type )
{
struct V_3 * V_20 = NULL ;
struct V_28 * V_4 = NULL ;
struct V_8 * V_52 = & V_2 -> V_9 ;
switch ( type ) {
case V_63 :
V_4 = F_34 ( V_52 , V_50 ) ;
if ( V_4 )
V_20 = F_31 ( V_4 ,
struct V_3 , V_20 ) ;
return V_20 ;
case V_64 :
return F_32 ( V_2 , V_50 ) ;
case V_65 :
return F_28 ( V_2 , V_50 ) ;
default:
return NULL ;
}
}
void F_35 ( struct V_3 * V_4 , int type )
{
struct V_8 * V_9 = V_4 -> V_20 . V_9 ;
struct V_1 * V_2 = F_36 ( V_9 ) ;
switch ( type ) {
case V_63 :
F_37 ( & V_4 -> V_20 ) ;
break;
case V_64 :
if ( V_4 -> V_19 ) {
F_12 ( V_2 , V_4 , false ) ;
F_37 ( & V_4 -> V_20 ) ;
}
break;
case V_65 :
if ( V_4 -> V_19 )
F_12 ( V_2 , V_4 , false ) ;
F_13 ( & V_9 -> V_33 ) ;
V_4 -> V_54 = 0 ;
V_4 -> V_55 = NULL ;
F_16 ( & V_9 -> V_33 ) ;
break;
default:
F_38 ( V_9 -> V_53 , L_2 , type ) ;
}
}
void F_39 ( struct V_1 * V_2 ,
bool V_66 , int V_35 )
{
T_1 V_67 = 0 ;
T_1 V_68 = 0 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
if ( ! V_2 -> V_69 ) {
F_29 ( V_9 -> V_53 , L_3 ) ;
return;
}
V_67 |= ( 1 << V_35 ) ;
V_68 = F_40 ( V_9 , V_70 ) ;
V_67 |= V_68 ;
if ( V_66 )
F_14 ( V_2 -> V_69 , V_71 , 0 , V_67 ) ;
else
F_14 ( V_2 -> V_69 , V_71 , V_67 , 0 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
struct V_28 * V_4 ;
if ( V_9 -> V_72 ) {
F_30 (stream, &bus->stream_list, list)
F_42 ( V_4 ) ;
F_43 ( V_9 ) ;
}
}
