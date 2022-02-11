static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 V_6 ;
int V_7 ;
V_6 . type = V_8 ;
V_6 . V_9 = 0x00 ;
V_7 = F_3 ( V_4 -> V_2 , V_10 , 1 ,
sizeof( V_6 ) , & V_6 ) ;
if ( V_7 )
return V_7 ;
return F_4 ( V_2 ,
V_10 , NULL ) ;
}
static inline int F_5 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_11 ,
sizeof( V_12 ) ,
( V_13 * ) & V_12 ) ;
}
static inline int F_7 ( struct V_1 * V_2 , T_1 type )
{
return F_8 ( V_2 , V_14 , sizeof( type ) , & type ) ;
}
static inline int F_9 ( struct V_1 * V_2 , T_1 V_15 ,
char * V_16 )
{
return F_8 ( V_2 , V_17 , V_15 , V_16 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_18 ,
T_2 V_19 )
{
T_2 V_20 = 13560 ;
T_2 V_21 , V_22 , V_23 ;
char V_16 [ 9 ] ;
V_21 = ( 24 * V_20 ) / V_19 ;
V_23 = 24 * V_20 - V_21 * V_19 ;
V_22 = ( 32768 * V_23 ) / V_19 ;
V_16 [ 0 ] = 0x00 ;
V_16 [ 1 ] = 0x00 ;
V_16 [ 2 ] = 0x00 ;
V_16 [ 3 ] = 0x10 ;
V_16 [ 4 ] = 0x04 ;
V_16 [ 5 ] = V_22 & 0xFF ;
V_16 [ 6 ] = ( V_22 >> 8 ) & 0xff ;
V_16 [ 7 ] = V_21 ;
V_16 [ 8 ] = V_18 ;
return F_9 ( V_2 , 9 , V_16 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_24 = 1 ;
F_12 ( & V_4 -> V_25 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
void (* F_14)( struct V_1 * V_2 ) , int V_26 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = & V_4 -> V_29 -> V_30 -> V_28 ;
F_15 ( V_28 , L_1 , V_26 ) ;
F_16 ( & V_4 -> V_31 , V_26 ) ;
V_4 -> V_32 = F_14 ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_33 , T_1 type )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_34 * V_35 ;
struct V_36 * V_37 ;
unsigned long V_15 ;
T_1 V_38 , V_39 ;
int V_40 = 0 ;
if ( ( type == V_41 && ! V_4 -> V_42 ) ||
( type == V_43 && ! V_4 -> V_44 ) )
return - V_45 ;
if ( type == V_41 )
V_35 = V_4 -> V_42 ;
else
V_35 = V_4 -> V_44 ;
V_38 = F_18 ( V_2 , V_33 ) ;
if ( V_38 <= 0 )
return - V_45 ;
V_15 = V_35 -> V_46 ;
F_13 ( V_2 , F_11 ,
F_19 ( V_35 -> V_46 , V_38 ) ) ;
while ( V_15 ) {
V_39 = F_20 (unsigned long, (unsigned long) max_size,
len) ;
V_37 = F_21 ( V_2 , ( V_47 + V_39 ) ,
V_48 ) ;
if ( ! V_37 ) {
F_13 ( V_2 , NULL , 0 ) ;
return - V_49 ;
}
F_22 ( V_37 , V_47 ) ;
memcpy ( F_23 ( V_37 , V_39 ) , V_35 -> V_16 + ( V_35 -> V_46 - V_15 ) ,
V_39 ) ;
V_40 = F_24 ( V_2 , V_33 , V_37 ) ;
if ( V_40 ) {
F_13 ( V_2 , NULL , 0 ) ;
return V_40 ;
}
V_15 -= V_39 ;
}
return V_40 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_7 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = & V_4 -> V_29 -> V_30 -> V_28 ;
F_15 ( V_28 , L_2 , V_50 ) ;
V_7 = V_4 -> V_51 -> V_52 ( V_4 -> V_29 ) ;
return V_7 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = & V_4 -> V_29 -> V_30 -> V_28 ;
F_15 ( V_28 , L_2 , V_50 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = & V_4 -> V_29 -> V_30 -> V_28 ;
F_15 ( V_28 , L_2 , V_50 ) ;
if ( F_28 ( & V_4 -> V_31 ) )
V_4 -> V_32 ( V_2 ) ;
return V_4 -> V_51 -> V_53 ( V_4 -> V_29 , V_37 ) ;
}
int F_29 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = & V_4 -> V_29 -> V_30 -> V_28 ;
F_15 ( V_28 , L_2 , V_50 ) ;
return F_30 ( V_2 , V_37 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = & V_4 -> V_29 -> V_30 -> V_28 ;
T_1 * V_16 ;
int V_7 ;
V_7 = F_32 ( & V_4 -> V_44 , V_54 , V_28 ) ;
if ( V_7 < 0 ) {
F_33 ( V_28 , L_3 ) ;
goto error;
}
V_16 = ( T_1 * ) V_4 -> V_44 -> V_16 ;
V_4 -> V_55 =
V_16 [ V_56 ] |
( V_16 [ V_56 + 1 ] << 8 ) |
( V_16 [ V_56 + 2 ] << 16 ) |
( V_16 [ V_56 + 3 ] << 24 ) ;
F_15 ( V_28 , L_4 ,
V_4 -> V_55 , ( int ) V_4 -> V_44 -> V_46 ) ;
V_7 = F_32 ( & V_4 -> V_42 , V_57 , V_28 ) ;
if ( V_7 < 0 ) {
F_33 ( V_28 , L_5 ) ;
goto V_58;
}
V_16 = ( T_1 * ) V_4 -> V_42 -> V_16 ;
V_4 -> V_59 =
V_16 [ V_56 ] |
( V_16 [ V_56 + 1 ] << 8 ) |
( V_16 [ V_56 + 2 ] << 16 ) |
( V_16 [ V_56 + 3 ] << 24 ) ;
F_15 ( V_28 , L_6 ,
V_4 -> V_59 , ( int ) V_4 -> V_42 -> V_46 ) ;
V_58:
return 0 ;
error:
return V_7 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_42 ) {
F_35 ( V_4 -> V_42 ) ;
V_4 -> V_42 = NULL ;
}
if ( V_4 -> V_44 ) {
F_35 ( V_4 -> V_44 ) ;
V_4 -> V_42 = NULL ;
}
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = & V_4 -> V_29 -> V_30 -> V_28 ;
T_1 V_33 ;
int V_7 = 0 ;
if ( V_4 -> V_60 >= V_4 -> V_59 )
goto V_58;
V_4 -> V_24 = 0 ;
V_4 -> V_61 = 0 ;
V_4 -> V_62 = 0 ;
V_7 = F_7 ( V_2 , V_41 ) ;
if ( V_7 )
goto V_58;
V_33 = F_1 ( V_2 ) ;
if ( V_33 < 0 ) {
V_7 = V_33 ;
goto V_58;
}
V_7 = F_17 ( V_2 , V_33 , V_41 ) ;
if ( V_7 )
goto V_58;
F_37 ( V_4 -> V_25 ,
V_4 -> V_24 == 1 ) ;
F_38 ( V_63 ) ;
V_7 = F_39 ( V_4 -> V_2 , V_33 ) ;
if ( V_7 )
goto V_58;
if ( F_7 ( V_2 , V_64 ) ) {
F_33 ( V_28 , L_7 , V_7 ) ;
V_7 = - V_45 ;
goto V_58;
}
F_37 ( V_4 -> V_25 , V_4 -> V_62 ) ;
V_7 = V_4 -> V_65 ;
if ( V_7 ) {
F_33 ( V_28 , L_7 , V_7 ) ;
V_7 = - V_45 ;
goto V_58;
}
F_37 ( V_4 -> V_25 , V_4 -> V_61 ) ;
V_58:
return V_7 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = & V_4 -> V_29 -> V_30 -> V_28 ;
T_1 V_33 ;
int V_7 = 0 ;
if ( V_4 -> V_66 >= V_4 -> V_55 )
goto V_58;
V_4 -> V_24 = 0 ;
V_4 -> V_61 = 0 ;
V_4 -> V_62 = 0 ;
V_7 = F_7 ( V_2 , V_43 ) ;
if ( V_7 )
goto V_58;
V_33 = F_1 ( V_2 ) ;
if ( V_33 < 0 ) {
V_7 = V_33 ;
goto V_58;
}
V_7 = F_17 ( V_2 , V_33 , V_43 ) ;
if ( V_7 )
goto V_58;
F_37 ( V_4 -> V_25 ,
V_4 -> V_24 == 1 ) ;
F_38 ( V_63 ) ;
V_7 = F_39 ( V_4 -> V_2 , V_33 ) ;
if ( V_7 )
goto V_58;
if ( F_7 ( V_2 , V_64 ) ) {
F_33 ( V_28 , L_8 , V_7 ) ;
V_7 = - V_45 ;
goto V_58;
}
F_37 ( V_4 -> V_25 , V_4 -> V_62 ) ;
V_7 = V_4 -> V_65 ;
if ( V_7 ) {
F_33 ( V_28 , L_8 , V_7 ) ;
V_7 = - V_45 ;
goto V_58;
}
F_37 ( V_4 -> V_25 , V_4 -> V_61 ) ;
V_58:
return V_7 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = & V_4 -> V_29 -> V_30 -> V_28 ;
int V_7 ;
T_1 V_67 = 0 ;
F_15 ( V_28 , L_2 , V_50 ) ;
V_7 = F_42 ( V_2 ) ;
if ( V_7 )
goto error;
V_7 = F_5 ( V_2 ) ;
if ( V_7 )
goto error;
V_7 = F_31 ( V_2 ) ;
if ( V_7 )
goto error;
if ( V_4 -> V_60 < V_4 -> V_59 ) {
V_7 = F_36 ( V_2 ) ;
if ( V_7 )
goto error;
V_67 = 1 ;
}
if ( V_4 -> V_66 < V_4 -> V_55 ) {
V_7 = F_40 ( V_2 ) ;
if ( V_7 )
goto error;
V_67 = 1 ;
}
F_34 ( V_2 ) ;
if ( V_67 ) {
V_7 = F_42 ( V_2 ) ;
if ( V_7 )
goto error;
V_7 = F_5 ( V_2 ) ;
if ( V_7 )
goto error;
if ( V_4 -> V_60 != V_4 -> V_59 ||
V_4 -> V_66 != V_4 -> V_55 ) {
F_33 ( V_28 , L_9 ) ;
V_7 = - V_45 ;
goto error;
}
}
return F_43 ( V_2 ) ;
error:
F_34 ( V_2 ) ;
F_33 ( V_28 , L_10 , V_7 ) ;
return V_7 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = & V_4 -> V_29 -> V_30 -> V_28 ;
int V_7 ;
if ( V_4 -> V_68 && V_4 -> V_68 [ 0 ] ) {
V_7 = F_9 ( V_2 , V_4 -> V_68 [ 3 ] ,
& V_4 -> V_68 [ 4 ] ) ;
if ( V_7 ) {
F_33 ( V_28 , L_11 ,
V_7 ) ;
return V_7 ;
}
}
V_7 = F_10 ( V_2 , V_4 -> V_18 , V_4 -> V_19 ) ;
if ( V_7 ) {
F_33 ( V_28 , L_12 , V_7 ) ;
return V_7 ;
}
V_7 = F_43 ( V_2 ) ;
if ( V_7 )
return V_7 ;
return F_42 ( V_2 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = & V_4 -> V_29 -> V_30 -> V_28 ;
F_15 ( V_28 , L_2 , V_50 ) ;
V_4 -> V_61 = 1 ;
F_12 ( & V_4 -> V_25 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = & V_4 -> V_29 -> V_30 -> V_28 ;
F_15 ( V_28 , L_2 , V_50 ) ;
V_4 -> V_62 = 1 ;
V_4 -> V_65 = V_37 -> V_16 [ 0 ] ;
F_12 ( & V_4 -> V_25 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = & V_4 -> V_29 -> V_30 -> V_28 ;
T_1 V_69 = V_37 -> V_16 [ 0 ] ;
F_15 ( V_28 , L_13 , V_50 , V_69 ) ;
F_48 ( V_2 , V_69 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = & V_4 -> V_29 -> V_30 -> V_28 ;
T_1 V_69 = V_37 -> V_16 [ 0 ] ;
F_15 ( V_28 , L_13 , V_50 , V_69 ) ;
F_48 ( V_2 , V_69 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = & V_4 -> V_29 -> V_30 -> V_28 ;
struct V_70 * V_71 = ( void * ) V_37 -> V_16 ;
T_1 V_72 , * V_73 ;
if ( V_71 -> V_69 == V_74 ) {
V_73 = V_71 -> V_16 ;
for ( V_72 = 0 ; V_72 < 4 ; V_72 ++ ) {
switch ( * V_73 ++ ) {
case V_75 :
V_73 ++ ;
V_4 -> V_66 = F_51 ( ( V_76 * ) V_73 ) ;
V_73 += 4 ;
break;
case V_77 :
V_73 ++ ;
V_4 -> V_60 = F_51 ( ( V_76 * ) V_73 ) ;
V_73 += 4 ;
break;
case V_78 :
V_73 ++ ;
V_4 -> V_60 = F_51 ( ( V_76 * ) V_73 ) ;
V_73 += 4 ;
break;
case V_79 :
V_73 ++ ;
V_4 -> V_80 = * V_73 ++ ;
}
}
}
F_15 ( V_28 , L_14 , V_4 -> V_60 ) ;
F_15 ( V_28 , L_15 , V_4 -> V_66 ) ;
F_15 ( V_28 , L_16 , V_4 -> V_80 ) ;
F_15 ( V_28 , L_13 , V_50 , V_71 -> V_69 ) ;
F_48 ( V_2 , V_71 -> V_69 ) ;
return 0 ;
}
int F_52 ( struct V_81 * V_29 , struct V_82 * V_51 ,
struct V_1 * * V_83 , int V_84 ,
int V_85 , T_1 V_18 , T_2 V_19 ,
T_1 * V_68 )
{
struct V_27 * V_28 = & V_29 -> V_30 -> V_28 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
T_2 V_86 ;
int V_7 ;
V_4 = F_53 ( sizeof( struct V_3 ) , V_48 ) ;
if ( ! V_4 ) {
V_7 = - V_49 ;
goto V_87;
}
V_4 -> V_29 = V_29 ;
V_4 -> V_51 = V_51 ;
V_4 -> V_18 = V_18 ;
V_4 -> V_19 = V_19 ;
V_4 -> V_68 = V_68 ;
F_54 ( & V_4 -> V_25 ) ;
V_86 = V_88 |
V_89 |
V_90 |
V_91 |
V_92 |
V_93 |
V_94 ;
V_2 = F_55 ( & V_95 , V_86 , V_84 ,
V_85 ) ;
if ( ! V_2 ) {
F_33 ( V_28 , L_17 ) ;
V_7 = - V_49 ;
goto V_96;
}
V_7 = F_56 ( V_2 ) ;
if ( V_7 )
goto V_97;
* V_83 = V_2 ;
V_4 -> V_2 = V_2 ;
F_57 ( V_2 , V_4 ) ;
return 0 ;
V_97:
F_58 ( V_2 ) ;
V_96:
F_59 ( V_4 ) ;
V_87:
return V_7 ;
}
void F_60 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = & V_4 -> V_29 -> V_30 -> V_28 ;
F_15 ( V_28 , L_2 , V_50 ) ;
F_61 ( V_2 ) ;
F_58 ( V_2 ) ;
F_59 ( V_4 ) ;
}
