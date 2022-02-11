static void
F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 , int V_5 ,
const struct F_1 * V_6 , int V_7 )
{
struct V_8 * V_9 = & V_2 -> V_4 . V_10 . V_9 ;
struct V_11 * V_12 = V_9 -> V_12 ;
int V_13 ;
for ( V_13 = 0 ; V_6 -> V_14 [ V_13 ] . V_15 ; V_13 ++ ) {
if ( V_6 -> V_14 [ V_13 ] . V_16 ) {
T_1 V_17 = F_2 ( V_12 , V_6 -> V_14 [ V_13 ] . V_16 + V_4 + 0 ) ;
T_1 V_18 = F_2 ( V_12 , V_6 -> V_14 [ V_13 ] . V_16 + V_4 + V_5 ) ;
T_1 V_15 = V_6 -> V_14 [ V_13 ] . V_15 + ( V_6 -> V_15 * V_7 ) ;
const char * V_19 = V_6 -> V_14 [ V_13 ] . V_19 ;
char V_20 [ 16 ] ;
if ( V_18 != V_17 )
snprintf ( V_20 , sizeof( V_20 ) , L_1 , V_17 ) ;
else
snprintf ( V_20 , sizeof( V_20 ) , L_2 , ' ' ) ;
F_3 ( V_9 , V_3 , V_21 ,
L_3 ,
V_15 , V_18 , V_20 , V_19 ? L_4 : L_5 ,
V_19 ? V_19 : L_5 ) ;
}
}
}
void
F_4 ( struct V_22 * V_23 , int V_3 )
{
struct V_1 * V_2 = V_23 -> V_24 -> V_2 ;
struct V_8 * V_9 = & V_2 -> V_4 . V_10 . V_9 ;
const struct F_4 * V_15 = V_23 -> V_15 ;
const struct F_1 * V_6 ;
int V_13 , V_25 ;
if ( V_3 > V_9 -> V_3 )
return;
for ( V_13 = 0 ; ( V_6 = V_15 -> V_14 [ V_13 ] . V_15 ) != NULL ; V_13 ++ ) {
T_1 V_4 = V_23 -> V_26 * V_15 -> V_16 ;
for ( V_25 = 0 ; V_25 < V_15 -> V_14 [ V_13 ] . V_27 ; V_25 ++ , V_4 += V_6 -> V_16 ) {
const char * V_28 = V_15 -> V_19 ;
const char * V_29 = L_5 ;
char V_30 [ 16 ] , V_31 [ 16 ] ;
if ( V_15 -> V_16 ) {
snprintf ( V_30 , sizeof( V_30 ) , L_6 ,
V_15 -> V_19 , V_23 -> V_32 . V_33 ) ;
V_28 = V_30 ;
}
if ( V_15 -> V_14 [ V_13 ] . V_27 > 1 ) {
snprintf ( V_31 , sizeof( V_31 ) , L_7 ,
V_15 -> V_14 [ V_13 ] . V_19 , V_25 ) ;
V_29 = V_31 ;
}
F_3 ( V_9 , V_3 , V_21 , L_8 , V_28 , V_29 ) ;
F_1 ( V_2 , V_3 , V_4 , V_15 -> V_18 ,
V_6 , V_25 ) ;
}
}
}
static void
F_5 ( struct V_34 * V_35 , int type , int V_36 )
{
struct V_1 * V_2 = F_6 ( V_35 , F_7 ( * V_2 ) , V_37 ) ;
struct V_11 * V_12 = V_2 -> V_4 . V_10 . V_9 . V_12 ;
F_8 ( V_12 , 0x610028 , 0x00000001 << V_36 , 0x00000000 << V_36 ) ;
F_9 ( V_12 , 0x610020 , 0x00000001 << V_36 ) ;
}
static void
F_10 ( struct V_34 * V_35 , int V_38 , int V_36 )
{
struct V_1 * V_2 = F_6 ( V_35 , F_7 ( * V_2 ) , V_37 ) ;
struct V_11 * V_12 = V_2 -> V_4 . V_10 . V_9 . V_12 ;
F_9 ( V_12 , 0x610020 , 0x00000001 << V_36 ) ;
F_8 ( V_12 , 0x610028 , 0x00000001 << V_36 , 0x00000001 << V_36 ) ;
}
void
F_11 ( struct V_1 * V_2 , int V_32 )
{
struct V_39 {
} V_40 ;
F_12 ( & V_2 -> V_37 , 1 , V_32 , & V_40 , sizeof( V_40 ) ) ;
}
int
F_13 ( struct V_41 * V_42 , void * V_14 , T_1 V_43 ,
struct V_44 * V_45 )
{
struct V_22 * V_23 = V_22 ( V_42 ) ;
union {
struct V_46 V_47 ;
} * args = V_14 ;
int V_48 = - V_49 ;
if ( ! ( V_48 = F_14 ( V_48 , & V_14 , & V_43 , args -> V_47 ) ) ) {
V_45 -> V_43 = sizeof( struct V_39 ) ;
V_45 -> V_38 = 1 ;
V_45 -> V_36 = V_23 -> V_32 . V_33 ;
return 0 ;
}
return V_48 ;
}
static int
F_15 ( struct V_41 * V_42 , T_2 V_16 , T_1 * V_14 )
{
struct V_22 * V_23 = V_22 ( V_42 ) ;
struct V_1 * V_2 = V_23 -> V_24 -> V_2 ;
struct V_11 * V_12 = V_2 -> V_4 . V_10 . V_9 . V_12 ;
* V_14 = F_2 ( V_12 , 0x640000 + ( V_23 -> V_32 . V_33 * 0x1000 ) + V_16 ) ;
return 0 ;
}
static int
F_16 ( struct V_41 * V_42 , T_2 V_16 , T_1 V_14 )
{
struct V_22 * V_23 = V_22 ( V_42 ) ;
struct V_1 * V_2 = V_23 -> V_24 -> V_2 ;
struct V_11 * V_12 = V_2 -> V_4 . V_10 . V_9 . V_12 ;
F_9 ( V_12 , 0x640000 + ( V_23 -> V_32 . V_33 * 0x1000 ) + V_16 , V_14 ) ;
return 0 ;
}
static int
F_17 ( struct V_41 * V_42 , T_1 type ,
struct V_34 * * V_50 )
{
struct V_22 * V_23 = V_22 ( V_42 ) ;
struct V_1 * V_2 = V_23 -> V_24 -> V_2 ;
switch ( type ) {
case V_51 :
* V_50 = & V_2 -> V_37 ;
return 0 ;
default:
break;
}
return - V_52 ;
}
static int
F_18 ( struct V_41 * V_42 , T_2 * V_16 , T_1 * V_43 )
{
struct V_22 * V_23 = V_22 ( V_42 ) ;
struct V_1 * V_2 = V_23 -> V_24 -> V_2 ;
struct V_11 * V_12 = V_2 -> V_4 . V_10 . V_9 . V_12 ;
* V_16 = V_12 -> V_53 -> V_54 ( V_12 , 0 ) +
0x640000 + ( V_23 -> V_32 . V_33 * 0x1000 ) ;
* V_43 = 0x001000 ;
return 0 ;
}
static int
F_19 ( const struct V_55 * V_56 ,
void * V_14 , T_1 V_43 , struct V_41 * * V_57 )
{
struct V_22 * V_23 = V_22 ( V_56 -> V_58 ) ;
return V_23 -> V_53 -> V_59 ( V_23 , V_56 , V_14 , V_43 , V_57 ) ;
}
static int
F_20 ( struct V_41 * V_42 , int V_36 ,
struct V_55 * V_56 )
{
struct V_22 * V_23 = V_22 ( V_42 ) ;
if ( V_23 -> V_53 -> V_60 ) {
int V_48 = V_23 -> V_53 -> V_60 ( V_23 , V_36 , V_56 ) ;
if ( V_48 == 0 )
V_56 -> V_61 = F_19 ;
return V_48 ;
}
return - V_52 ;
}
static int
F_21 ( struct V_41 * V_42 , bool V_62 )
{
struct V_22 * V_23 = V_22 ( V_42 ) ;
V_23 -> V_53 -> V_63 ( V_23 ) ;
return 0 ;
}
static int
F_22 ( struct V_41 * V_42 )
{
struct V_22 * V_23 = V_22 ( V_42 ) ;
return V_23 -> V_53 -> V_64 ( V_23 ) ;
}
static void *
F_23 ( struct V_41 * V_42 )
{
struct V_22 * V_23 = V_22 ( V_42 ) ;
struct V_1 * V_2 = V_23 -> V_24 -> V_2 ;
if ( V_23 -> V_32 . V_33 >= 0 )
V_2 -> V_23 [ V_23 -> V_32 . V_33 ] = NULL ;
return V_23 -> V_53 -> V_65 ? V_23 -> V_53 -> V_65 ( V_23 ) : V_23 ;
}
int
F_24 ( const struct V_66 * V_53 ,
const struct F_4 * V_15 ,
struct V_67 * V_24 , int V_68 , int V_33 , int V_26 ,
const struct V_55 * V_56 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
F_25 ( & V_22 , V_56 , & V_23 -> V_42 ) ;
V_23 -> V_53 = V_53 ;
V_23 -> V_15 = V_15 ;
V_23 -> V_24 = V_24 ;
V_23 -> V_32 . V_68 = V_68 ;
V_23 -> V_32 . V_33 = V_33 ;
V_23 -> V_26 = V_26 ;
if ( V_2 -> V_23 [ V_23 -> V_32 . V_33 ] ) {
V_23 -> V_32 . V_33 = - 1 ;
return - V_69 ;
}
V_2 -> V_23 [ V_23 -> V_32 . V_33 ] = V_23 ;
return 0 ;
}
int
F_26 ( const struct V_66 * V_53 ,
const struct F_4 * V_15 ,
struct V_67 * V_24 , int V_68 , int V_33 , int V_26 ,
const struct V_55 * V_56 ,
struct V_41 * * V_57 )
{
struct V_22 * V_23 ;
if ( ! ( V_23 = F_27 ( sizeof( * V_23 ) , V_70 ) ) )
return - V_71 ;
* V_57 = & V_23 -> V_42 ;
return F_24 ( V_53 , V_15 , V_24 , V_68 , V_33 ,
V_26 , V_56 , V_23 ) ;
}
