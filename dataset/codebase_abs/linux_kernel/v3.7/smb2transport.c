static int
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
static int
F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_6 = 0 ;
struct V_15 * V_16 = V_2 -> V_12 [ 0 ] . V_17 ;
if ( ! ( V_16 -> V_33 & V_34 ) ||
V_4 -> V_35 == V_36 )
return V_6 ;
if ( ! V_4 -> V_37 ) {
strncpy ( V_16 -> V_18 , L_6 , 8 ) ;
return V_6 ;
}
V_6 = F_1 ( V_2 , V_4 ) ;
return V_6 ;
}
int
F_10 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_6 ;
char V_38 [ 16 ] ;
struct V_15 * V_16 = (struct V_15 * ) V_2 -> V_12 [ 0 ] . V_17 ;
if ( ( V_16 -> V_39 == V_40 ) ||
( V_16 -> V_39 == V_41 ) ||
( ! V_4 -> V_37 ) )
return 0 ;
if ( memcmp ( V_16 -> V_18 , L_7 , 8 ) == 0 )
F_11 ( 1 , L_8 ,
V_16 -> V_39 ) ;
memcpy ( V_38 , V_16 -> V_18 , V_19 ) ;
memset ( V_16 -> V_18 , 0 , V_19 ) ;
F_12 ( & V_4 -> V_42 ) ;
V_6 = F_1 ( V_2 , V_4 ) ;
F_13 ( & V_4 -> V_42 ) ;
if ( V_6 )
return V_6 ;
if ( memcmp ( V_38 , V_16 -> V_18 ,
V_19 ) )
return - V_43 ;
else
return 0 ;
}
static inline void
F_14 ( struct V_3 * V_4 , struct V_15 * V_44 )
{
V_44 -> V_45 = F_15 ( V_4 ) ;
}
static struct V_46 *
F_16 ( const struct V_15 * V_47 ,
struct V_3 * V_4 )
{
struct V_46 * V_48 ;
if ( V_4 == NULL ) {
F_3 ( 1 , L_9 ) ;
return NULL ;
}
V_48 = F_17 ( V_49 , V_50 ) ;
if ( V_48 == NULL )
return V_48 ;
else {
memset ( V_48 , 0 , sizeof( struct V_46 ) ) ;
V_48 -> V_51 = V_47 -> V_45 ;
V_48 -> V_52 = V_53 -> V_52 ;
V_48 -> V_54 = V_47 -> V_39 ;
V_48 -> V_55 = V_56 ;
V_48 -> V_4 = V_4 ;
V_48 -> V_57 = V_58 ;
V_48 -> V_59 = V_53 ;
}
F_18 ( & V_60 ) ;
V_48 -> V_61 = V_62 ;
return V_48 ;
}
static int
F_19 ( struct V_63 * V_64 , struct V_15 * V_65 ,
struct V_46 * * V_51 )
{
if ( V_64 -> V_4 -> V_35 == V_66 )
return - V_67 ;
if ( V_64 -> V_4 -> V_35 == V_68 ) {
F_11 ( 1 , L_10 ) ;
return - V_69 ;
}
if ( V_64 -> V_70 != V_71 ) {
if ( ( V_65 -> V_39 != V_72 ) &&
( V_65 -> V_39 != V_40 ) )
return - V_69 ;
}
* V_51 = F_16 ( V_65 , V_64 -> V_4 ) ;
if ( * V_51 == NULL )
return - V_73 ;
F_20 ( & V_74 ) ;
F_21 ( & ( * V_51 ) -> V_75 , & V_64 -> V_4 -> V_76 ) ;
F_22 ( & V_74 ) ;
return 0 ;
}
int
F_23 ( struct V_46 * V_51 , struct V_3 * V_4 ,
bool V_77 )
{
unsigned int V_78 = F_24 ( V_51 -> V_79 ) ;
struct V_10 V_11 ;
struct V_1 V_2 = { . V_12 = & V_11 ,
. V_14 = 1 } ;
V_11 . V_17 = ( char * ) V_51 -> V_79 ;
V_11 . V_28 = F_24 ( V_51 -> V_79 ) + 4 ;
F_25 ( V_51 -> V_79 , F_26 ( V_80 , 80 , V_78 ) ) ;
if ( ( V_78 > 24 ) &&
( V_4 -> V_81 & ( V_82 | V_83 ) ) ) {
int V_6 ;
V_6 = F_10 ( & V_2 , V_4 ) ;
if ( V_6 )
F_3 ( 1 , L_11
L_12 , V_6 ) ;
}
return F_27 ( V_51 -> V_79 , V_77 ) ;
}
struct V_46 *
F_28 ( struct V_63 * V_64 , struct V_1 * V_2 )
{
int V_6 ;
struct V_15 * V_44 = (struct V_15 * ) V_2 -> V_12 [ 0 ] . V_17 ;
struct V_46 * V_51 ;
F_14 ( V_64 -> V_4 , V_44 ) ;
V_6 = F_19 ( V_64 , V_44 , & V_51 ) ;
if ( V_6 )
return F_29 ( V_6 ) ;
V_6 = F_9 ( V_2 , V_64 -> V_4 ) ;
if ( V_6 ) {
F_30 ( V_51 ) ;
return F_29 ( V_6 ) ;
}
return V_51 ;
}
struct V_46 *
F_31 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
int V_6 ;
struct V_15 * V_44 = (struct V_15 * ) V_2 -> V_12 [ 0 ] . V_17 ;
struct V_46 * V_51 ;
F_14 ( V_4 , V_44 ) ;
V_51 = F_16 ( V_44 , V_4 ) ;
if ( V_51 == NULL )
return F_29 ( - V_73 ) ;
V_6 = F_9 ( V_2 , V_4 ) ;
if ( V_6 ) {
F_32 ( V_51 ) ;
return F_29 ( V_6 ) ;
}
return V_51 ;
}
