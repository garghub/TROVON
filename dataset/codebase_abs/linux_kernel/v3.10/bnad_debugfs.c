static int
F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_3 = V_1 -> V_4 ;
struct V_5 * V_6 ;
unsigned long V_7 ;
int V_8 ;
V_6 = F_2 ( sizeof( struct V_5 ) , V_9 ) ;
if ( ! V_6 )
return - V_10 ;
V_6 -> V_11 = V_12 ;
V_6 -> V_13 = F_2 ( V_6 -> V_11 , V_9 ) ;
if ( ! V_6 -> V_13 ) {
F_3 ( V_6 ) ;
V_6 = NULL ;
return - V_10 ;
}
F_4 ( & V_3 -> V_14 , V_7 ) ;
V_8 = F_5 ( & V_3 -> V_15 . V_16 . V_17 ,
V_6 -> V_13 ,
& V_6 -> V_11 ) ;
F_6 ( & V_3 -> V_14 , V_7 ) ;
if ( V_8 != V_18 ) {
F_3 ( V_6 -> V_13 ) ;
V_6 -> V_13 = NULL ;
F_3 ( V_6 ) ;
V_6 = NULL ;
F_7 ( L_1 ,
F_8 ( V_3 -> V_19 ) ) ;
return - V_10 ;
}
V_2 -> V_20 = V_6 ;
return 0 ;
}
static int
F_9 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_3 = V_1 -> V_4 ;
struct V_5 * V_6 ;
unsigned long V_7 ;
int V_8 ;
V_6 = F_2 ( sizeof( struct V_5 ) , V_9 ) ;
if ( ! V_6 )
return - V_10 ;
V_6 -> V_11 = V_12 ;
V_6 -> V_13 = F_2 ( V_6 -> V_11 , V_9 ) ;
if ( ! V_6 -> V_13 ) {
F_3 ( V_6 ) ;
V_6 = NULL ;
return - V_10 ;
}
F_4 ( & V_3 -> V_14 , V_7 ) ;
V_8 = F_10 ( & V_3 -> V_15 . V_16 . V_17 ,
V_6 -> V_13 ,
& V_6 -> V_11 ) ;
F_6 ( & V_3 -> V_14 , V_7 ) ;
if ( V_8 != V_18 && V_8 != V_21 ) {
F_3 ( V_6 -> V_13 ) ;
V_6 -> V_13 = NULL ;
F_3 ( V_6 ) ;
V_6 = NULL ;
F_7 ( L_2 ,
F_8 ( V_3 -> V_19 ) ) ;
return - V_10 ;
}
V_2 -> V_20 = V_6 ;
return 0 ;
}
static int
F_11 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_5 * V_22 ;
V_22 = F_2 ( sizeof( struct V_5 ) , V_9 ) ;
if ( ! V_22 )
return - V_10 ;
V_22 -> V_4 = V_1 -> V_4 ;
V_2 -> V_20 = V_22 ;
return 0 ;
}
static int
F_12 ( struct V_3 * V_3 , void * V_23 , T_1 V_24 )
{
struct V_25 * V_26 = (struct V_25 * ) V_23 ;
struct V_27 V_28 ;
unsigned long V_7 = 0 ;
int V_29 = V_30 ;
F_4 ( & V_3 -> V_14 , V_7 ) ;
F_13 ( & V_3 -> V_15 . V_16 . V_17 , & V_26 -> V_31 ) ;
F_6 ( & V_3 -> V_14 , V_7 ) ;
V_28 . V_3 = V_3 ;
V_28 . V_32 = 0 ;
F_14 ( & V_28 . V_33 ) ;
F_4 ( & V_3 -> V_14 , V_7 ) ;
V_29 = F_15 ( & V_3 -> V_15 . V_34 , & V_26 -> V_35 ,
V_36 , & V_28 ) ;
if ( V_29 != V_18 ) {
F_6 ( & V_3 -> V_14 , V_7 ) ;
goto V_37;
}
F_6 ( & V_3 -> V_14 , V_7 ) ;
F_16 ( & V_28 . V_33 ) ;
V_26 -> V_38 = V_28 . V_32 ;
V_28 . V_32 = 0 ;
F_14 ( & V_28 . V_33 ) ;
F_4 ( & V_3 -> V_14 , V_7 ) ;
V_29 = F_17 ( & V_3 -> V_15 . V_39 , & V_26 -> V_40 ,
V_36 , & V_28 ) ;
if ( V_29 != V_18 ) {
F_6 ( & V_3 -> V_14 , V_7 ) ;
goto V_37;
}
F_6 ( & V_3 -> V_14 , V_7 ) ;
F_16 ( & V_28 . V_33 ) ;
V_26 -> V_41 = V_28 . V_32 ;
V_37:
return V_29 ;
}
static int
F_18 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_3 = V_1 -> V_4 ;
struct V_5 * V_42 ;
int V_8 ;
V_42 = F_2 ( sizeof( struct V_5 ) , V_9 ) ;
if ( ! V_42 )
return - V_10 ;
V_42 -> V_11 = sizeof( struct V_25 ) ;
V_42 -> V_13 = F_2 ( V_42 -> V_11 , V_9 ) ;
if ( ! V_42 -> V_13 ) {
F_3 ( V_42 ) ;
V_42 = NULL ;
return - V_10 ;
}
F_19 ( & V_3 -> V_43 ) ;
V_8 = F_12 ( V_3 , V_42 -> V_13 ,
V_42 -> V_11 ) ;
F_20 ( & V_3 -> V_43 ) ;
if ( V_8 != V_18 ) {
F_3 ( V_42 -> V_13 ) ;
V_42 -> V_13 = NULL ;
F_3 ( V_42 ) ;
V_42 = NULL ;
F_7 ( L_3 ,
F_8 ( V_3 -> V_19 ) ) ;
return - V_10 ;
}
V_2 -> V_20 = V_42 ;
return 0 ;
}
static T_2
F_21 ( struct V_2 * V_2 , T_2 V_44 , int V_45 )
{
T_2 V_46 = V_2 -> V_47 ;
struct V_5 * V_48 = V_2 -> V_20 ;
if ( ! V_48 )
return - V_49 ;
switch ( V_45 ) {
case 0 :
V_2 -> V_47 = V_44 ;
break;
case 1 :
V_2 -> V_47 += V_44 ;
break;
case 2 :
V_2 -> V_47 = V_48 -> V_11 + V_44 ;
break;
default:
return - V_49 ;
}
if ( V_2 -> V_47 < 0 || V_2 -> V_47 > V_48 -> V_11 ) {
V_2 -> V_47 = V_46 ;
return - V_49 ;
}
return V_2 -> V_47 ;
}
static T_3
F_22 ( struct V_2 * V_2 , char T_4 * V_50 ,
T_5 V_51 , T_2 * V_46 )
{
struct V_5 * V_48 = V_2 -> V_20 ;
if ( ! V_48 || ! V_48 -> V_13 )
return 0 ;
return F_23 ( V_50 , V_51 , V_46 ,
V_48 -> V_13 , V_48 -> V_11 ) ;
}
static int
F_24 ( struct V_52 * V_17 , T_1 V_44 , T_1 V_24 )
{
T_6 V_53 ;
V_53 = ( V_44 >> 15 ) & 0x7 ;
if ( V_53 == 0 ) {
if ( ( V_44 + ( V_24 << 2 ) ) > 0x8000 )
return V_54 ;
} else if ( V_53 == 0x1 ) {
if ( ( V_44 + ( V_24 << 2 ) ) > 0x10000 )
return V_54 ;
} else {
if ( ( V_44 + ( V_24 << 2 ) ) > F_25 ( V_17 ) )
return V_54 ;
}
return V_18 ;
}
static T_3
F_26 ( struct V_2 * V_2 , char T_4 * V_50 ,
T_5 V_51 , T_2 * V_46 )
{
struct V_5 * V_55 = V_2 -> V_20 ;
struct V_3 * V_3 = (struct V_3 * ) V_55 -> V_4 ;
T_3 V_8 ;
if ( ! V_3 -> V_56 )
return 0 ;
V_8 = F_23 ( V_50 , V_51 , V_46 ,
V_3 -> V_56 , V_3 -> V_57 ) ;
if ( ( * V_46 + V_51 ) >= V_3 -> V_57 ) {
F_3 ( V_3 -> V_56 ) ;
V_3 -> V_56 = NULL ;
V_3 -> V_57 = 0 ;
}
return V_8 ;
}
static T_3
F_27 ( struct V_2 * V_2 , const char T_4 * V_50 ,
T_5 V_51 , T_2 * V_58 )
{
struct V_5 * V_55 = V_2 -> V_20 ;
struct V_3 * V_3 = (struct V_3 * ) V_55 -> V_4 ;
struct V_52 * V_17 = & V_3 -> V_15 . V_16 . V_17 ;
int V_59 , V_24 , V_8 , V_60 ;
T_1 * V_61 ;
void T_7 * V_62 , * V_63 ;
unsigned long V_7 ;
void * V_64 ;
V_64 = F_2 ( V_51 , V_9 ) ;
if ( ! V_64 )
return - V_10 ;
if ( F_28 ( V_64 , ( void T_4 * ) V_50 , V_51 ) ) {
F_3 ( V_64 ) ;
return - V_10 ;
}
V_8 = sscanf ( V_64 , L_4 , & V_59 , & V_24 ) ;
if ( V_8 < 2 ) {
F_7 ( L_5 ,
F_8 ( V_3 -> V_19 ) ) ;
F_3 ( V_64 ) ;
return - V_49 ;
}
F_3 ( V_64 ) ;
F_3 ( V_3 -> V_56 ) ;
V_3 -> V_56 = NULL ;
V_3 -> V_57 = 0 ;
V_3 -> V_56 = F_2 ( V_24 << 2 , V_9 ) ;
if ( ! V_3 -> V_56 )
return - V_10 ;
V_3 -> V_57 = V_24 << 2 ;
V_62 = F_29 ( V_17 ) ;
V_59 &= F_25 ( V_17 ) ;
V_8 = F_24 ( V_17 , V_59 , V_24 ) ;
if ( V_8 ) {
F_7 ( L_6 ,
F_8 ( V_3 -> V_19 ) ) ;
F_3 ( V_3 -> V_56 ) ;
V_3 -> V_56 = NULL ;
V_3 -> V_57 = 0 ;
return - V_49 ;
}
V_63 = V_62 + V_59 ;
V_61 = ( T_1 * ) V_3 -> V_56 ;
F_4 ( & V_3 -> V_14 , V_7 ) ;
for ( V_60 = 0 ; V_60 < V_24 ; V_60 ++ ) {
* V_61 = F_30 ( V_63 ) ;
V_61 ++ ;
V_63 += sizeof( T_1 ) ;
}
F_6 ( & V_3 -> V_14 , V_7 ) ;
return V_51 ;
}
static T_3
F_31 ( struct V_2 * V_2 , const char T_4 * V_50 ,
T_5 V_51 , T_2 * V_58 )
{
struct V_5 * V_48 = V_2 -> V_20 ;
struct V_3 * V_3 = (struct V_3 * ) V_48 -> V_4 ;
struct V_52 * V_17 = & V_3 -> V_15 . V_16 . V_17 ;
int V_59 , V_65 , V_8 ;
void T_7 * V_63 ;
unsigned long V_7 ;
void * V_64 ;
V_64 = F_2 ( V_51 , V_9 ) ;
if ( ! V_64 )
return - V_10 ;
if ( F_28 ( V_64 , ( void T_4 * ) V_50 , V_51 ) ) {
F_3 ( V_64 ) ;
return - V_10 ;
}
V_8 = sscanf ( V_64 , L_4 , & V_59 , & V_65 ) ;
if ( V_8 < 2 ) {
F_7 ( L_5 ,
F_8 ( V_3 -> V_19 ) ) ;
F_3 ( V_64 ) ;
return - V_49 ;
}
F_3 ( V_64 ) ;
V_59 &= F_25 ( V_17 ) ;
V_8 = F_24 ( V_17 , V_59 , 1 ) ;
if ( V_8 ) {
F_7 ( L_6 ,
F_8 ( V_3 -> V_19 ) ) ;
return - V_49 ;
}
V_63 = ( F_29 ( V_17 ) ) + V_59 ;
F_4 ( & V_3 -> V_14 , V_7 ) ;
F_32 ( V_65 , V_63 ) ;
F_6 ( & V_3 -> V_14 , V_7 ) ;
return V_51 ;
}
static int
F_33 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_5 * V_48 = V_2 -> V_20 ;
if ( ! V_48 )
return 0 ;
V_2 -> V_20 = NULL ;
F_3 ( V_48 ) ;
return 0 ;
}
static int
F_34 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_5 * V_48 = V_2 -> V_20 ;
if ( ! V_48 )
return 0 ;
F_3 ( V_48 -> V_13 ) ;
V_2 -> V_20 = NULL ;
F_3 ( V_48 ) ;
V_48 = NULL ;
return 0 ;
}
void
F_35 ( struct V_3 * V_3 )
{
const struct V_66 * V_2 ;
char V_67 [ 64 ] ;
int V_60 ;
if ( ! V_68 ) {
V_68 = F_36 ( L_7 , NULL ) ;
F_37 ( & V_69 , 0 ) ;
if ( ! V_68 ) {
F_7 ( L_8 ) ;
return;
}
}
snprintf ( V_67 , sizeof( V_67 ) , L_9 , F_8 ( V_3 -> V_19 ) ) ;
if ( ! V_3 -> V_70 ) {
V_3 -> V_70 =
F_36 ( V_67 , V_68 ) ;
if ( ! V_3 -> V_70 ) {
F_7 ( L_10 ,
F_8 ( V_3 -> V_19 ) ) ;
return;
}
F_38 ( & V_69 ) ;
for ( V_60 = 0 ; V_60 < F_39 ( V_71 ) ; V_60 ++ ) {
V_2 = & V_71 [ V_60 ] ;
V_3 -> V_72 [ V_60 ] =
F_40 ( V_2 -> V_67 ,
V_2 -> V_73 ,
V_3 -> V_70 ,
V_3 ,
V_2 -> V_74 ) ;
if ( ! V_3 -> V_72 [ V_60 ] ) {
F_7 (
L_11 ,
F_8 ( V_3 -> V_19 ) , V_2 -> V_67 ) ;
return;
}
}
}
}
void
F_41 ( struct V_3 * V_3 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < F_39 ( V_71 ) ; V_60 ++ ) {
if ( V_3 -> V_72 [ V_60 ] ) {
F_42 ( V_3 -> V_72 [ V_60 ] ) ;
V_3 -> V_72 [ V_60 ] = NULL ;
}
}
if ( V_3 -> V_70 ) {
F_42 ( V_3 -> V_70 ) ;
V_3 -> V_70 = NULL ;
F_43 ( & V_69 ) ;
}
if ( F_44 ( & V_69 ) == 0 ) {
F_42 ( V_68 ) ;
V_68 = NULL ;
}
}
