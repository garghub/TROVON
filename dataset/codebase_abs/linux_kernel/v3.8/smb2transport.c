int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 , V_6 ;
unsigned char V_7 [ V_8 ] ;
unsigned char * V_9 = V_7 ;
struct V_10 * V_11 = V_2 -> V_12 ;
int V_13 = V_2 -> V_14 ;
struct V_15 * V_16 = (struct V_15 * ) V_11 [ 0 ] . V_17 ;
memset ( V_7 , 0x0 , V_8 ) ;
memset ( V_16 -> V_18 , 0x0 , V_19 ) ;
V_6 = F_2 ( V_4 -> V_20 . V_21 ,
V_4 -> V_22 . V_23 , V_24 ) ;
if ( V_6 ) {
F_3 ( 1 , L_1 , V_25 ) ;
return V_6 ;
}
V_6 = F_4 ( & V_4 -> V_20 . V_26 -> V_27 ) ;
if ( V_6 ) {
F_3 ( 1 , L_2 , V_25 ) ;
return V_6 ;
}
for ( V_5 = 0 ; V_5 < V_13 ; V_5 ++ ) {
if ( V_11 [ V_5 ] . V_28 == 0 )
continue;
if ( V_11 [ V_5 ] . V_17 == NULL ) {
F_3 ( 1 , L_3 ) ;
return - V_29 ;
}
if ( V_5 == 0 ) {
if ( V_11 [ 0 ] . V_28 <= 8 )
break;
V_6 =
F_5 (
& V_4 -> V_20 . V_26 -> V_27 ,
V_11 [ V_5 ] . V_17 + 4 , V_11 [ V_5 ] . V_28 - 4 ) ;
} else {
V_6 =
F_5 (
& V_4 -> V_20 . V_26 -> V_27 ,
V_11 [ V_5 ] . V_17 , V_11 [ V_5 ] . V_28 ) ;
}
if ( V_6 ) {
F_3 ( 1 , L_4 ,
V_25 ) ;
return V_6 ;
}
}
for ( V_5 = 0 ; V_5 < V_2 -> V_30 ; V_5 ++ ) {
struct V_10 V_31 ;
F_6 ( V_2 , V_5 , & V_31 ) ;
F_5 ( & V_4 -> V_20 . V_26 -> V_27 ,
V_31 . V_17 , V_31 . V_28 ) ;
F_7 ( V_2 -> V_32 [ V_5 ] ) ;
}
V_6 = F_8 ( & V_4 -> V_20 . V_26 -> V_27 ,
V_9 ) ;
if ( V_6 )
F_3 ( 1 , L_5 , V_25 ) ;
memcpy ( V_16 -> V_18 , V_9 , V_19 ) ;
return V_6 ;
}
int
F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_10 ( 1 , L_6 ) ;
return - V_33 ;
}
static int
F_11 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_6 = 0 ;
struct V_15 * V_16 = V_2 -> V_12 [ 0 ] . V_17 ;
if ( ! ( V_16 -> V_34 & V_35 ) ||
V_4 -> V_36 == V_37 )
return V_6 ;
if ( ! V_4 -> V_38 ) {
strncpy ( V_16 -> V_18 , L_7 , 8 ) ;
return V_6 ;
}
V_6 = V_4 -> V_39 -> V_40 ( V_2 , V_4 ) ;
return V_6 ;
}
int
F_12 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_6 ;
char V_41 [ 16 ] ;
struct V_15 * V_16 = (struct V_15 * ) V_2 -> V_12 [ 0 ] . V_17 ;
if ( ( V_16 -> V_42 == V_43 ) ||
( V_16 -> V_42 == V_44 ) ||
( ! V_4 -> V_38 ) )
return 0 ;
if ( memcmp ( V_16 -> V_18 , L_8 , 8 ) == 0 )
F_10 ( 1 , L_9 ,
V_16 -> V_42 ) ;
memcpy ( V_41 , V_16 -> V_18 , V_19 ) ;
memset ( V_16 -> V_18 , 0 , V_19 ) ;
F_13 ( & V_4 -> V_45 ) ;
V_6 = V_4 -> V_39 -> V_40 ( V_2 , V_4 ) ;
F_14 ( & V_4 -> V_45 ) ;
if ( V_6 )
return V_6 ;
if ( memcmp ( V_41 , V_16 -> V_18 ,
V_19 ) )
return - V_46 ;
else
return 0 ;
}
static inline void
F_15 ( struct V_3 * V_4 , struct V_15 * V_47 )
{
V_47 -> V_48 = F_16 ( V_4 ) ;
}
static struct V_49 *
F_17 ( const struct V_15 * V_50 ,
struct V_3 * V_4 )
{
struct V_49 * V_51 ;
if ( V_4 == NULL ) {
F_3 ( 1 , L_10 ) ;
return NULL ;
}
V_51 = F_18 ( V_52 , V_53 ) ;
if ( V_51 == NULL )
return V_51 ;
else {
memset ( V_51 , 0 , sizeof( struct V_49 ) ) ;
V_51 -> V_54 = V_50 -> V_48 ;
V_51 -> V_55 = V_56 -> V_55 ;
V_51 -> V_57 = V_50 -> V_42 ;
V_51 -> V_58 = V_59 ;
V_51 -> V_4 = V_4 ;
V_51 -> V_60 = V_61 ;
V_51 -> V_62 = V_56 ;
}
F_19 ( & V_63 ) ;
V_51 -> V_64 = V_65 ;
return V_51 ;
}
static int
F_20 ( struct V_66 * V_67 , struct V_15 * V_68 ,
struct V_49 * * V_54 )
{
if ( V_67 -> V_4 -> V_36 == V_69 )
return - V_70 ;
if ( V_67 -> V_4 -> V_36 == V_71 ) {
F_10 ( 1 , L_11 ) ;
return - V_72 ;
}
if ( V_67 -> V_73 != V_74 ) {
if ( ( V_68 -> V_42 != V_75 ) &&
( V_68 -> V_42 != V_43 ) )
return - V_72 ;
}
* V_54 = F_17 ( V_68 , V_67 -> V_4 ) ;
if ( * V_54 == NULL )
return - V_76 ;
F_21 ( & V_77 ) ;
F_22 ( & ( * V_54 ) -> V_78 , & V_67 -> V_4 -> V_79 ) ;
F_23 ( & V_77 ) ;
return 0 ;
}
int
F_24 ( struct V_49 * V_54 , struct V_3 * V_4 ,
bool V_80 )
{
unsigned int V_81 = F_25 ( V_54 -> V_82 ) ;
struct V_10 V_11 ;
struct V_1 V_2 = { . V_12 = & V_11 ,
. V_14 = 1 } ;
V_11 . V_17 = ( char * ) V_54 -> V_82 ;
V_11 . V_28 = F_25 ( V_54 -> V_82 ) + 4 ;
F_26 ( V_54 -> V_82 , F_27 ( V_83 , 80 , V_81 ) ) ;
if ( ( V_81 > 24 ) &&
( V_4 -> V_84 & ( V_85 | V_86 ) ) ) {
int V_6 ;
V_6 = F_12 ( & V_2 , V_4 ) ;
if ( V_6 )
F_3 ( 1 , L_12
L_13 , V_6 ) ;
}
return F_28 ( V_54 -> V_82 , V_80 ) ;
}
struct V_49 *
F_29 ( struct V_66 * V_67 , struct V_1 * V_2 )
{
int V_6 ;
struct V_15 * V_47 = (struct V_15 * ) V_2 -> V_12 [ 0 ] . V_17 ;
struct V_49 * V_54 ;
F_15 ( V_67 -> V_4 , V_47 ) ;
V_6 = F_20 ( V_67 , V_47 , & V_54 ) ;
if ( V_6 )
return F_30 ( V_6 ) ;
V_6 = F_11 ( V_2 , V_67 -> V_4 ) ;
if ( V_6 ) {
F_31 ( V_54 ) ;
return F_30 ( V_6 ) ;
}
return V_54 ;
}
struct V_49 *
F_32 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
int V_6 ;
struct V_15 * V_47 = (struct V_15 * ) V_2 -> V_12 [ 0 ] . V_17 ;
struct V_49 * V_54 ;
F_15 ( V_4 , V_47 ) ;
V_54 = F_17 ( V_47 , V_4 ) ;
if ( V_54 == NULL )
return F_30 ( - V_76 ) ;
V_6 = F_11 ( V_2 , V_4 ) ;
if ( V_6 ) {
F_33 ( V_54 ) ;
return F_30 ( V_6 ) ;
}
return V_54 ;
}
