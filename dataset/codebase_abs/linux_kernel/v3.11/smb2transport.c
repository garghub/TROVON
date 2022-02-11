static int
F_1 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned int V_4 ;
if ( V_2 -> V_5 . V_6 != NULL )
return 0 ;
V_2 -> V_5 . V_7 = F_2 ( L_1 , 0 , 0 ) ;
if ( F_3 ( V_2 -> V_5 . V_7 ) ) {
F_4 ( V_8 , L_2 ) ;
V_3 = F_5 ( V_2 -> V_5 . V_7 ) ;
V_2 -> V_5 . V_7 = NULL ;
return V_3 ;
}
V_4 = sizeof( struct V_9 ) +
F_6 ( V_2 -> V_5 . V_7 ) ;
V_2 -> V_5 . V_6 = F_7 ( V_4 , V_10 ) ;
if ( ! V_2 -> V_5 . V_6 ) {
F_8 ( V_2 -> V_5 . V_7 ) ;
V_2 -> V_5 . V_7 = NULL ;
return - V_11 ;
}
V_2 -> V_5 . V_6 -> V_12 . V_13 = V_2 -> V_5 . V_7 ;
V_2 -> V_5 . V_6 -> V_12 . V_14 = 0x0 ;
return 0 ;
}
static int
F_9 ( struct V_1 * V_2 )
{
unsigned int V_4 ;
int V_3 ;
if ( V_2 -> V_5 . V_15 != NULL )
return 0 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_2 -> V_5 . V_16 = F_2 ( L_3 , 0 , 0 ) ;
if ( F_3 ( V_2 -> V_5 . V_16 ) ) {
F_4 ( V_8 , L_4 ) ;
F_10 ( V_2 -> V_5 . V_6 ) ;
V_2 -> V_5 . V_6 = NULL ;
F_8 ( V_2 -> V_5 . V_7 ) ;
V_2 -> V_5 . V_7 = NULL ;
V_3 = F_5 ( V_2 -> V_5 . V_16 ) ;
V_2 -> V_5 . V_16 = NULL ;
return V_3 ;
}
V_4 = sizeof( struct V_9 ) +
F_6 ( V_2 -> V_5 . V_16 ) ;
V_2 -> V_5 . V_15 = F_7 ( V_4 , V_10 ) ;
if ( ! V_2 -> V_5 . V_15 ) {
F_4 ( V_8 , L_5 , V_17 ) ;
F_10 ( V_2 -> V_5 . V_6 ) ;
V_2 -> V_5 . V_6 = NULL ;
F_8 ( V_2 -> V_5 . V_7 ) ;
F_8 ( V_2 -> V_5 . V_16 ) ;
V_2 -> V_5 . V_7 = NULL ;
V_2 -> V_5 . V_16 = NULL ;
return - V_11 ;
}
V_2 -> V_5 . V_15 -> V_12 . V_13 = V_2 -> V_5 . V_16 ;
V_2 -> V_5 . V_15 -> V_12 . V_14 = 0x0 ;
return 0 ;
}
int
F_11 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
int V_20 , V_3 ;
unsigned char V_21 [ V_22 ] ;
unsigned char * V_23 = V_21 ;
struct V_24 * V_25 = V_19 -> V_26 ;
int V_27 = V_19 -> V_28 ;
struct V_29 * V_30 = (struct V_29 * ) V_25 [ 0 ] . V_31 ;
memset ( V_21 , 0x0 , V_22 ) ;
memset ( V_30 -> V_32 , 0x0 , V_33 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_6 , V_17 ) ;
return V_3 ;
}
V_3 = F_12 ( V_2 -> V_5 . V_7 ,
V_2 -> V_34 . V_35 , V_36 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_7 , V_17 ) ;
return V_3 ;
}
V_3 = F_13 ( & V_2 -> V_5 . V_6 -> V_12 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_8 , V_17 ) ;
return V_3 ;
}
for ( V_20 = 0 ; V_20 < V_27 ; V_20 ++ ) {
if ( V_25 [ V_20 ] . V_37 == 0 )
continue;
if ( V_25 [ V_20 ] . V_31 == NULL ) {
F_4 ( V_8 , L_9 ) ;
return - V_38 ;
}
if ( V_20 == 0 ) {
if ( V_25 [ 0 ] . V_37 <= 8 )
break;
V_3 =
F_14 (
& V_2 -> V_5 . V_6 -> V_12 ,
V_25 [ V_20 ] . V_31 + 4 , V_25 [ V_20 ] . V_37 - 4 ) ;
} else {
V_3 =
F_14 (
& V_2 -> V_5 . V_6 -> V_12 ,
V_25 [ V_20 ] . V_31 , V_25 [ V_20 ] . V_37 ) ;
}
if ( V_3 ) {
F_4 ( V_8 , L_10 ,
V_17 ) ;
return V_3 ;
}
}
for ( V_20 = 0 ; V_20 < V_19 -> V_39 ; V_20 ++ ) {
struct V_24 V_40 ;
F_15 ( V_19 , V_20 , & V_40 ) ;
F_14 ( & V_2 -> V_5 . V_6 -> V_12 ,
V_40 . V_31 , V_40 . V_37 ) ;
F_16 ( V_19 -> V_41 [ V_20 ] ) ;
}
V_3 = F_17 ( & V_2 -> V_5 . V_6 -> V_12 ,
V_23 ) ;
if ( V_3 )
F_4 ( V_8 , L_11 , V_17 ) ;
memcpy ( V_30 -> V_32 , V_23 , V_33 ) ;
return V_3 ;
}
void
F_18 ( struct V_1 * V_2 )
{
unsigned char V_42 = 0x0 ;
T_1 V_20 [ 4 ] = { 0 , 0 , 0 , 1 } ;
T_1 V_43 [ 4 ] = { 0 , 0 , 0 , 128 } ;
int V_3 = 0 ;
unsigned char V_44 [ V_22 ] ;
unsigned char * V_45 = V_44 ;
memset ( V_44 , 0x0 , V_22 ) ;
memset ( V_2 -> V_46 , 0x0 , V_47 ) ;
V_3 = F_9 ( V_2 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_12 , V_17 ) ;
goto V_48;
}
V_3 = F_12 ( V_2 -> V_5 . V_7 ,
V_2 -> V_34 . V_35 , V_36 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_13 , V_17 ) ;
goto V_48;
}
V_3 = F_13 ( & V_2 -> V_5 . V_6 -> V_12 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_14 , V_17 ) ;
goto V_48;
}
V_3 = F_14 ( & V_2 -> V_5 . V_6 -> V_12 ,
V_20 , 4 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_15 , V_17 ) ;
goto V_48;
}
V_3 = F_14 ( & V_2 -> V_5 . V_6 -> V_12 ,
L_16 , 12 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_17 , V_17 ) ;
goto V_48;
}
V_3 = F_14 ( & V_2 -> V_5 . V_6 -> V_12 ,
& V_42 , 1 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_18 , V_17 ) ;
goto V_48;
}
V_3 = F_14 ( & V_2 -> V_5 . V_6 -> V_12 ,
L_19 , 8 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_20 , V_17 ) ;
goto V_48;
}
V_3 = F_14 ( & V_2 -> V_5 . V_6 -> V_12 ,
V_43 , 4 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_21 , V_17 ) ;
goto V_48;
}
V_3 = F_17 ( & V_2 -> V_5 . V_6 -> V_12 ,
V_45 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_11 , V_17 ) ;
goto V_48;
}
memcpy ( V_2 -> V_46 , V_45 , V_47 ) ;
V_48:
return;
}
int
F_19 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
int V_20 , V_3 ;
unsigned char V_49 [ V_50 ] ;
unsigned char * V_23 = V_49 ;
struct V_24 * V_25 = V_19 -> V_26 ;
int V_27 = V_19 -> V_28 ;
struct V_29 * V_30 = (struct V_29 * ) V_25 [ 0 ] . V_31 ;
memset ( V_49 , 0x0 , V_50 ) ;
memset ( V_30 -> V_32 , 0x0 , V_33 ) ;
V_3 = F_12 ( V_2 -> V_5 . V_16 ,
V_2 -> V_46 , V_50 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_22 , V_17 ) ;
return V_3 ;
}
V_3 = F_13 ( & V_2 -> V_5 . V_15 -> V_12 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_23 , V_17 ) ;
return V_3 ;
}
for ( V_20 = 0 ; V_20 < V_27 ; V_20 ++ ) {
if ( V_25 [ V_20 ] . V_37 == 0 )
continue;
if ( V_25 [ V_20 ] . V_31 == NULL ) {
F_4 ( V_8 , L_24 ) ;
return - V_38 ;
}
if ( V_20 == 0 ) {
if ( V_25 [ 0 ] . V_37 <= 8 )
break;
V_3 =
F_14 (
& V_2 -> V_5 . V_15 -> V_12 ,
V_25 [ V_20 ] . V_31 + 4 , V_25 [ V_20 ] . V_37 - 4 ) ;
} else {
V_3 =
F_14 (
& V_2 -> V_5 . V_15 -> V_12 ,
V_25 [ V_20 ] . V_31 , V_25 [ V_20 ] . V_37 ) ;
}
if ( V_3 ) {
F_4 ( V_8 , L_25 ,
V_17 ) ;
return V_3 ;
}
}
for ( V_20 = 0 ; V_20 < V_19 -> V_39 ; V_20 ++ ) {
struct V_24 V_40 ;
F_15 ( V_19 , V_20 , & V_40 ) ;
F_14 ( & V_2 -> V_5 . V_15 -> V_12 ,
V_40 . V_31 , V_40 . V_37 ) ;
F_16 ( V_19 -> V_41 [ V_20 ] ) ;
}
V_3 = F_17 ( & V_2 -> V_5 . V_15 -> V_12 ,
V_23 ) ;
if ( V_3 )
F_4 ( V_8 , L_26 , V_17 ) ;
memcpy ( V_30 -> V_32 , V_23 , V_33 ) ;
return V_3 ;
}
static int
F_20 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_29 * V_30 = V_19 -> V_26 [ 0 ] . V_31 ;
if ( ! ( V_30 -> V_51 & V_52 ) ||
V_2 -> V_53 == V_54 )
return V_3 ;
if ( ! V_2 -> V_55 ) {
strncpy ( V_30 -> V_32 , L_27 , 8 ) ;
return V_3 ;
}
V_3 = V_2 -> V_56 -> V_57 ( V_19 , V_2 ) ;
return V_3 ;
}
int
F_21 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
unsigned int V_3 ;
char V_58 [ 16 ] ;
struct V_29 * V_30 = (struct V_29 * ) V_19 -> V_26 [ 0 ] . V_31 ;
if ( ( V_30 -> V_59 == V_60 ) ||
( V_30 -> V_59 == V_61 ) ||
( ! V_2 -> V_55 ) )
return 0 ;
if ( memcmp ( V_30 -> V_32 , L_28 , 8 ) == 0 )
F_4 ( V_62 , L_29 ,
V_30 -> V_59 ) ;
memcpy ( V_58 , V_30 -> V_32 , V_33 ) ;
memset ( V_30 -> V_32 , 0 , V_33 ) ;
F_22 ( & V_2 -> V_63 ) ;
V_3 = V_2 -> V_56 -> V_57 ( V_19 , V_2 ) ;
F_23 ( & V_2 -> V_63 ) ;
if ( V_3 )
return V_3 ;
if ( memcmp ( V_58 , V_30 -> V_32 ,
V_33 ) )
return - V_64 ;
else
return 0 ;
}
static inline void
F_24 ( struct V_1 * V_2 , struct V_29 * V_65 )
{
V_65 -> V_66 = F_25 ( V_2 ) ;
}
static struct V_67 *
F_26 ( const struct V_29 * V_68 ,
struct V_1 * V_2 )
{
struct V_67 * V_69 ;
if ( V_2 == NULL ) {
F_4 ( V_8 , L_30 ) ;
return NULL ;
}
V_69 = F_27 ( V_70 , V_71 ) ;
if ( V_69 == NULL )
return V_69 ;
else {
memset ( V_69 , 0 , sizeof( struct V_67 ) ) ;
V_69 -> V_72 = V_68 -> V_66 ;
V_69 -> V_73 = V_74 -> V_73 ;
V_69 -> V_75 = V_68 -> V_59 ;
V_69 -> V_76 = V_77 ;
V_69 -> V_2 = V_2 ;
V_69 -> V_78 = V_79 ;
V_69 -> V_80 = V_74 ;
}
F_28 ( & V_81 ) ;
V_69 -> V_82 = V_83 ;
return V_69 ;
}
static int
F_29 ( struct V_84 * V_85 , struct V_29 * V_86 ,
struct V_67 * * V_72 )
{
if ( V_85 -> V_2 -> V_53 == V_87 )
return - V_88 ;
if ( V_85 -> V_2 -> V_53 == V_89 ) {
F_4 ( V_62 , L_31 ) ;
return - V_90 ;
}
if ( V_85 -> V_91 != V_92 ) {
if ( ( V_86 -> V_59 != V_93 ) &&
( V_86 -> V_59 != V_60 ) )
return - V_90 ;
}
* V_72 = F_26 ( V_86 , V_85 -> V_2 ) ;
if ( * V_72 == NULL )
return - V_11 ;
F_30 ( & V_94 ) ;
F_31 ( & ( * V_72 ) -> V_95 , & V_85 -> V_2 -> V_96 ) ;
F_32 ( & V_94 ) ;
return 0 ;
}
int
F_33 ( struct V_67 * V_72 , struct V_1 * V_2 ,
bool V_97 )
{
unsigned int V_98 = F_34 ( V_72 -> V_99 ) ;
struct V_24 V_25 ;
struct V_18 V_19 = { . V_26 = & V_25 ,
. V_28 = 1 } ;
V_25 . V_31 = ( char * ) V_72 -> V_99 ;
V_25 . V_37 = F_34 ( V_72 -> V_99 ) + 4 ;
F_35 ( V_72 -> V_99 , F_36 ( V_100 , 80 , V_98 ) ) ;
if ( V_98 > 24 && V_2 -> V_101 ) {
int V_3 ;
V_3 = F_21 ( & V_19 , V_2 ) ;
if ( V_3 )
F_4 ( V_8 , L_32 ,
V_3 ) ;
}
return F_37 ( V_72 -> V_99 , V_97 ) ;
}
struct V_67 *
F_38 ( struct V_84 * V_85 , struct V_18 * V_19 )
{
int V_3 ;
struct V_29 * V_65 = (struct V_29 * ) V_19 -> V_26 [ 0 ] . V_31 ;
struct V_67 * V_72 ;
F_24 ( V_85 -> V_2 , V_65 ) ;
V_3 = F_29 ( V_85 , V_65 , & V_72 ) ;
if ( V_3 )
return F_39 ( V_3 ) ;
V_3 = F_20 ( V_19 , V_85 -> V_2 ) ;
if ( V_3 ) {
F_40 ( V_72 ) ;
return F_39 ( V_3 ) ;
}
return V_72 ;
}
struct V_67 *
F_41 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
int V_3 ;
struct V_29 * V_65 = (struct V_29 * ) V_19 -> V_26 [ 0 ] . V_31 ;
struct V_67 * V_72 ;
F_24 ( V_2 , V_65 ) ;
V_72 = F_26 ( V_65 , V_2 ) ;
if ( V_72 == NULL )
return F_39 ( - V_11 ) ;
V_3 = F_20 ( V_19 , V_2 ) ;
if ( V_3 ) {
F_42 ( V_72 ) ;
return F_39 ( V_3 ) ;
}
return V_72 ;
}
