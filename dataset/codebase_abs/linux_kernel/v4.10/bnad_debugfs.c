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
F_7 ( V_3 -> V_19 , L_1 ) ;
return - V_10 ;
}
V_2 -> V_20 = V_6 ;
return 0 ;
}
static int
F_8 ( struct V_1 * V_1 , struct V_2 * V_2 )
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
V_8 = F_9 ( & V_3 -> V_15 . V_16 . V_17 ,
V_6 -> V_13 ,
& V_6 -> V_11 ) ;
F_6 ( & V_3 -> V_14 , V_7 ) ;
if ( V_8 != V_18 && V_8 != V_21 ) {
F_3 ( V_6 -> V_13 ) ;
V_6 -> V_13 = NULL ;
F_3 ( V_6 ) ;
V_6 = NULL ;
F_7 ( V_3 -> V_19 , L_2 ) ;
return - V_10 ;
}
V_2 -> V_20 = V_6 ;
return 0 ;
}
static int
F_10 ( struct V_1 * V_1 , struct V_2 * V_2 )
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
F_11 ( struct V_3 * V_3 , void * V_23 , T_1 V_24 )
{
struct V_25 * V_26 = (struct V_25 * ) V_23 ;
struct V_27 V_28 ;
unsigned long V_7 = 0 ;
int V_29 = V_30 ;
F_4 ( & V_3 -> V_14 , V_7 ) ;
F_12 ( & V_3 -> V_15 . V_16 . V_17 , & V_26 -> V_31 ) ;
F_6 ( & V_3 -> V_14 , V_7 ) ;
V_28 . V_3 = V_3 ;
V_28 . V_32 = 0 ;
F_13 ( & V_28 . V_33 ) ;
F_4 ( & V_3 -> V_14 , V_7 ) ;
V_29 = F_14 ( & V_3 -> V_15 . V_34 , & V_26 -> V_35 ,
V_36 , & V_28 ) ;
if ( V_29 != V_18 ) {
F_6 ( & V_3 -> V_14 , V_7 ) ;
goto V_37;
}
F_6 ( & V_3 -> V_14 , V_7 ) ;
F_15 ( & V_28 . V_33 ) ;
V_26 -> V_38 = V_28 . V_32 ;
V_28 . V_32 = 0 ;
F_16 ( & V_28 . V_33 ) ;
F_4 ( & V_3 -> V_14 , V_7 ) ;
V_29 = F_17 ( & V_3 -> V_15 . V_39 , & V_26 -> V_40 ,
V_36 , & V_28 ) ;
if ( V_29 != V_18 ) {
F_6 ( & V_3 -> V_14 , V_7 ) ;
goto V_37;
}
F_6 ( & V_3 -> V_14 , V_7 ) ;
F_15 ( & V_28 . V_33 ) ;
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
V_8 = F_11 ( V_3 , V_42 -> V_13 ,
V_42 -> V_11 ) ;
F_20 ( & V_3 -> V_43 ) ;
if ( V_8 != V_18 ) {
F_3 ( V_42 -> V_13 ) ;
V_42 -> V_13 = NULL ;
F_3 ( V_42 ) ;
V_42 = NULL ;
F_7 ( V_3 -> V_19 , L_3 ) ;
return - V_10 ;
}
V_2 -> V_20 = V_42 ;
return 0 ;
}
static T_2
F_21 ( struct V_2 * V_2 , T_2 V_44 , int V_45 )
{
struct V_5 * V_46 = V_2 -> V_20 ;
if ( ! V_46 )
return - V_47 ;
return F_22 ( V_2 , V_44 , V_45 , V_46 -> V_11 ) ;
}
static T_3
F_23 ( struct V_2 * V_2 , char T_4 * V_48 ,
T_5 V_49 , T_2 * V_50 )
{
struct V_5 * V_46 = V_2 -> V_20 ;
if ( ! V_46 || ! V_46 -> V_13 )
return 0 ;
return F_24 ( V_48 , V_49 , V_50 ,
V_46 -> V_13 , V_46 -> V_11 ) ;
}
static int
F_25 ( struct V_51 * V_17 , T_1 V_44 , T_1 V_24 )
{
T_6 V_52 ;
V_52 = ( V_44 >> 15 ) & 0x7 ;
if ( V_52 == 0 ) {
if ( V_44 + ( V_24 << 2 ) > 0x8000 )
return V_53 ;
} else if ( V_52 == 0x1 ) {
if ( V_44 + ( V_24 << 2 ) > 0x10000 )
return V_53 ;
} else {
if ( V_44 + ( V_24 << 2 ) > F_26 ( V_17 ) )
return V_53 ;
}
return V_18 ;
}
static T_3
F_27 ( struct V_2 * V_2 , char T_4 * V_48 ,
T_5 V_49 , T_2 * V_50 )
{
struct V_5 * V_54 = V_2 -> V_20 ;
struct V_3 * V_3 = (struct V_3 * ) V_54 -> V_4 ;
T_3 V_8 ;
if ( ! V_3 -> V_55 )
return 0 ;
V_8 = F_24 ( V_48 , V_49 , V_50 ,
V_3 -> V_55 , V_3 -> V_56 ) ;
if ( ( * V_50 + V_49 ) >= V_3 -> V_56 ) {
F_3 ( V_3 -> V_55 ) ;
V_3 -> V_55 = NULL ;
V_3 -> V_56 = 0 ;
}
return V_8 ;
}
static T_3
F_28 ( struct V_2 * V_2 , const char T_4 * V_48 ,
T_5 V_49 , T_2 * V_57 )
{
struct V_5 * V_54 = V_2 -> V_20 ;
struct V_3 * V_3 = (struct V_3 * ) V_54 -> V_4 ;
struct V_51 * V_17 = & V_3 -> V_15 . V_16 . V_17 ;
int V_8 , V_58 ;
T_1 V_59 , V_24 ;
T_1 * V_60 ;
void T_7 * V_61 , * V_62 ;
unsigned long V_7 ;
void * V_63 ;
V_63 = F_29 ( V_48 , V_49 ) ;
if ( F_30 ( V_63 ) )
return F_31 ( V_63 ) ;
V_8 = sscanf ( V_63 , L_4 , & V_59 , & V_24 ) ;
if ( V_8 < 2 ) {
F_7 ( V_3 -> V_19 , L_5 ) ;
F_3 ( V_63 ) ;
return - V_47 ;
}
F_3 ( V_63 ) ;
F_3 ( V_3 -> V_55 ) ;
V_3 -> V_56 = 0 ;
V_3 -> V_55 = F_2 ( V_24 << 2 , V_9 ) ;
if ( ! V_3 -> V_55 )
return - V_10 ;
V_3 -> V_56 = V_24 << 2 ;
V_61 = F_32 ( V_17 ) ;
V_59 &= F_26 ( V_17 ) ;
V_8 = F_25 ( V_17 , V_59 , V_24 ) ;
if ( V_8 ) {
F_7 ( V_3 -> V_19 , L_6 ) ;
F_3 ( V_3 -> V_55 ) ;
V_3 -> V_55 = NULL ;
V_3 -> V_56 = 0 ;
return - V_47 ;
}
V_62 = V_61 + V_59 ;
V_60 = ( T_1 * ) V_3 -> V_55 ;
F_4 ( & V_3 -> V_14 , V_7 ) ;
for ( V_58 = 0 ; V_58 < V_24 ; V_58 ++ ) {
* V_60 = F_33 ( V_62 ) ;
V_60 ++ ;
V_62 += sizeof( T_1 ) ;
}
F_6 ( & V_3 -> V_14 , V_7 ) ;
return V_49 ;
}
static T_3
F_34 ( struct V_2 * V_2 , const char T_4 * V_48 ,
T_5 V_49 , T_2 * V_57 )
{
struct V_5 * V_46 = V_2 -> V_20 ;
struct V_3 * V_3 = (struct V_3 * ) V_46 -> V_4 ;
struct V_51 * V_17 = & V_3 -> V_15 . V_16 . V_17 ;
int V_8 ;
T_1 V_59 , V_64 ;
void T_7 * V_62 ;
unsigned long V_7 ;
void * V_63 ;
V_63 = F_29 ( V_48 , V_49 ) ;
if ( F_30 ( V_63 ) )
return F_31 ( V_63 ) ;
V_8 = sscanf ( V_63 , L_4 , & V_59 , & V_64 ) ;
if ( V_8 < 2 ) {
F_7 ( V_3 -> V_19 , L_5 ) ;
F_3 ( V_63 ) ;
return - V_47 ;
}
F_3 ( V_63 ) ;
V_59 &= F_26 ( V_17 ) ;
V_8 = F_25 ( V_17 , V_59 , 1 ) ;
if ( V_8 ) {
F_7 ( V_3 -> V_19 , L_6 ) ;
return - V_47 ;
}
V_62 = ( F_32 ( V_17 ) ) + V_59 ;
F_4 ( & V_3 -> V_14 , V_7 ) ;
F_35 ( V_64 , V_62 ) ;
F_6 ( & V_3 -> V_14 , V_7 ) ;
return V_49 ;
}
static int
F_36 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_5 * V_46 = V_2 -> V_20 ;
if ( ! V_46 )
return 0 ;
V_2 -> V_20 = NULL ;
F_3 ( V_46 ) ;
return 0 ;
}
static int
F_37 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_5 * V_46 = V_2 -> V_20 ;
if ( ! V_46 )
return 0 ;
F_3 ( V_46 -> V_13 ) ;
V_2 -> V_20 = NULL ;
F_3 ( V_46 ) ;
V_46 = NULL ;
return 0 ;
}
void
F_38 ( struct V_3 * V_3 )
{
const struct V_65 * V_2 ;
char V_66 [ 64 ] ;
int V_58 ;
if ( ! V_67 ) {
V_67 = F_39 ( L_7 , NULL ) ;
F_40 ( & V_68 , 0 ) ;
if ( ! V_67 ) {
F_7 ( V_3 -> V_19 ,
L_8 ) ;
return;
}
}
snprintf ( V_66 , sizeof( V_66 ) , L_9 , F_41 ( V_3 -> V_69 ) ) ;
if ( ! V_3 -> V_70 ) {
V_3 -> V_70 =
F_39 ( V_66 , V_67 ) ;
if ( ! V_3 -> V_70 ) {
F_7 ( V_3 -> V_19 ,
L_8 ) ;
return;
}
F_42 ( & V_68 ) ;
for ( V_58 = 0 ; V_58 < F_43 ( V_71 ) ; V_58 ++ ) {
V_2 = & V_71 [ V_58 ] ;
V_3 -> V_72 [ V_58 ] =
F_44 ( V_2 -> V_66 ,
V_2 -> V_73 ,
V_3 -> V_70 ,
V_3 ,
V_2 -> V_74 ) ;
if ( ! V_3 -> V_72 [ V_58 ] ) {
F_7 ( V_3 -> V_19 ,
L_10 ,
V_2 -> V_66 ) ;
return;
}
}
}
}
void
F_45 ( struct V_3 * V_3 )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < F_43 ( V_71 ) ; V_58 ++ ) {
if ( V_3 -> V_72 [ V_58 ] ) {
F_46 ( V_3 -> V_72 [ V_58 ] ) ;
V_3 -> V_72 [ V_58 ] = NULL ;
}
}
if ( V_3 -> V_70 ) {
F_46 ( V_3 -> V_70 ) ;
V_3 -> V_70 = NULL ;
F_47 ( & V_68 ) ;
}
if ( F_48 ( & V_68 ) == 0 ) {
F_46 ( V_67 ) ;
V_67 = NULL ;
}
}
