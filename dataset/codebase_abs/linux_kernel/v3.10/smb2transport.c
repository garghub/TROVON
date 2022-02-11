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
F_3 ( V_25 , L_1 , V_26 ) ;
return V_6 ;
}
V_6 = F_4 ( & V_4 -> V_20 . V_27 -> V_28 ) ;
if ( V_6 ) {
F_3 ( V_25 , L_2 , V_26 ) ;
return V_6 ;
}
for ( V_5 = 0 ; V_5 < V_13 ; V_5 ++ ) {
if ( V_11 [ V_5 ] . V_29 == 0 )
continue;
if ( V_11 [ V_5 ] . V_17 == NULL ) {
F_3 ( V_25 , L_3 ) ;
return - V_30 ;
}
if ( V_5 == 0 ) {
if ( V_11 [ 0 ] . V_29 <= 8 )
break;
V_6 =
F_5 (
& V_4 -> V_20 . V_27 -> V_28 ,
V_11 [ V_5 ] . V_17 + 4 , V_11 [ V_5 ] . V_29 - 4 ) ;
} else {
V_6 =
F_5 (
& V_4 -> V_20 . V_27 -> V_28 ,
V_11 [ V_5 ] . V_17 , V_11 [ V_5 ] . V_29 ) ;
}
if ( V_6 ) {
F_3 ( V_25 , L_4 ,
V_26 ) ;
return V_6 ;
}
}
for ( V_5 = 0 ; V_5 < V_2 -> V_31 ; V_5 ++ ) {
struct V_10 V_32 ;
F_6 ( V_2 , V_5 , & V_32 ) ;
F_5 ( & V_4 -> V_20 . V_27 -> V_28 ,
V_32 . V_17 , V_32 . V_29 ) ;
F_7 ( V_2 -> V_33 [ V_5 ] ) ;
}
V_6 = F_8 ( & V_4 -> V_20 . V_27 -> V_28 ,
V_9 ) ;
if ( V_6 )
F_3 ( V_25 , L_5 , V_26 ) ;
memcpy ( V_16 -> V_18 , V_9 , V_19 ) ;
return V_6 ;
}
int
F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_3 ( V_34 , L_6 ) ;
return - V_35 ;
}
static int
F_10 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_6 = 0 ;
struct V_15 * V_16 = V_2 -> V_12 [ 0 ] . V_17 ;
if ( ! ( V_16 -> V_36 & V_37 ) ||
V_4 -> V_38 == V_39 )
return V_6 ;
if ( ! V_4 -> V_40 ) {
strncpy ( V_16 -> V_18 , L_7 , 8 ) ;
return V_6 ;
}
V_6 = V_4 -> V_41 -> V_42 ( V_2 , V_4 ) ;
return V_6 ;
}
int
F_11 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_6 ;
char V_43 [ 16 ] ;
struct V_15 * V_16 = (struct V_15 * ) V_2 -> V_12 [ 0 ] . V_17 ;
if ( ( V_16 -> V_44 == V_45 ) ||
( V_16 -> V_44 == V_46 ) ||
( ! V_4 -> V_40 ) )
return 0 ;
if ( memcmp ( V_16 -> V_18 , L_8 , 8 ) == 0 )
F_3 ( V_34 , L_9 ,
V_16 -> V_44 ) ;
memcpy ( V_43 , V_16 -> V_18 , V_19 ) ;
memset ( V_16 -> V_18 , 0 , V_19 ) ;
F_12 ( & V_4 -> V_47 ) ;
V_6 = V_4 -> V_41 -> V_42 ( V_2 , V_4 ) ;
F_13 ( & V_4 -> V_47 ) ;
if ( V_6 )
return V_6 ;
if ( memcmp ( V_43 , V_16 -> V_18 ,
V_19 ) )
return - V_48 ;
else
return 0 ;
}
static inline void
F_14 ( struct V_3 * V_4 , struct V_15 * V_49 )
{
V_49 -> V_50 = F_15 ( V_4 ) ;
}
static struct V_51 *
F_16 ( const struct V_15 * V_52 ,
struct V_3 * V_4 )
{
struct V_51 * V_53 ;
if ( V_4 == NULL ) {
F_3 ( V_25 , L_10 ) ;
return NULL ;
}
V_53 = F_17 ( V_54 , V_55 ) ;
if ( V_53 == NULL )
return V_53 ;
else {
memset ( V_53 , 0 , sizeof( struct V_51 ) ) ;
V_53 -> V_56 = V_52 -> V_50 ;
V_53 -> V_57 = V_58 -> V_57 ;
V_53 -> V_59 = V_52 -> V_44 ;
V_53 -> V_60 = V_61 ;
V_53 -> V_4 = V_4 ;
V_53 -> V_62 = V_63 ;
V_53 -> V_64 = V_58 ;
}
F_18 ( & V_65 ) ;
V_53 -> V_66 = V_67 ;
return V_53 ;
}
static int
F_19 ( struct V_68 * V_69 , struct V_15 * V_70 ,
struct V_51 * * V_56 )
{
if ( V_69 -> V_4 -> V_38 == V_71 )
return - V_72 ;
if ( V_69 -> V_4 -> V_38 == V_73 ) {
F_3 ( V_34 , L_11 ) ;
return - V_74 ;
}
if ( V_69 -> V_75 != V_76 ) {
if ( ( V_70 -> V_44 != V_77 ) &&
( V_70 -> V_44 != V_45 ) )
return - V_74 ;
}
* V_56 = F_16 ( V_70 , V_69 -> V_4 ) ;
if ( * V_56 == NULL )
return - V_78 ;
F_20 ( & V_79 ) ;
F_21 ( & ( * V_56 ) -> V_80 , & V_69 -> V_4 -> V_81 ) ;
F_22 ( & V_79 ) ;
return 0 ;
}
int
F_23 ( struct V_51 * V_56 , struct V_3 * V_4 ,
bool V_82 )
{
unsigned int V_83 = F_24 ( V_56 -> V_84 ) ;
struct V_10 V_11 ;
struct V_1 V_2 = { . V_12 = & V_11 ,
. V_14 = 1 } ;
V_11 . V_17 = ( char * ) V_56 -> V_84 ;
V_11 . V_29 = F_24 ( V_56 -> V_84 ) + 4 ;
F_25 ( V_56 -> V_84 , F_26 ( V_85 , 80 , V_83 ) ) ;
if ( ( V_83 > 24 ) &&
( V_4 -> V_86 & ( V_87 | V_88 ) ) ) {
int V_6 ;
V_6 = F_11 ( & V_2 , V_4 ) ;
if ( V_6 )
F_3 ( V_25 , L_12 ,
V_6 ) ;
}
return F_27 ( V_56 -> V_84 , V_82 ) ;
}
struct V_51 *
F_28 ( struct V_68 * V_69 , struct V_1 * V_2 )
{
int V_6 ;
struct V_15 * V_49 = (struct V_15 * ) V_2 -> V_12 [ 0 ] . V_17 ;
struct V_51 * V_56 ;
F_14 ( V_69 -> V_4 , V_49 ) ;
V_6 = F_19 ( V_69 , V_49 , & V_56 ) ;
if ( V_6 )
return F_29 ( V_6 ) ;
V_6 = F_10 ( V_2 , V_69 -> V_4 ) ;
if ( V_6 ) {
F_30 ( V_56 ) ;
return F_29 ( V_6 ) ;
}
return V_56 ;
}
struct V_51 *
F_31 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
int V_6 ;
struct V_15 * V_49 = (struct V_15 * ) V_2 -> V_12 [ 0 ] . V_17 ;
struct V_51 * V_56 ;
F_14 ( V_4 , V_49 ) ;
V_56 = F_16 ( V_49 , V_4 ) ;
if ( V_56 == NULL )
return F_29 ( - V_78 ) ;
V_6 = F_10 ( V_2 , V_4 ) ;
if ( V_6 ) {
F_32 ( V_56 ) ;
return F_29 ( V_6 ) ;
}
return V_56 ;
}
